/* cally 逆向卡：Reach_06 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 42 个函数｜锚点 7499 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/42 spAnimationState_apply  0x283220  size 824  206 条（0x283220..0x283558）
 * @func 0x283220 0x283558  size 824  206 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAnimation_apply×2 / spAnimation_mix×2 / 0xb66ac×2 / spAnimationState_apply+0x230 / spAnimationState_apply+0xec / spAnimationState_apply+0x1a8
 * 字段偏移 top8: 0x10×9 / 0x8×8 / 0xc×6 / 0x1c×6 / 0x18×4 / 0x4×3 / 0x2×2 / 0x28×2
 * VFP 指令 59 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283220 ldr r3, [r0, #0xc]
 *   @0x283224 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x283228 vpush {d8, d9}
 *   @0x28322c cmp r3, #0
 *   @0x283230 sub sp, sp, #36
 *   @0x283234 mov r4, r0
 *   @0x283238 mov r10, r1
 *   @0x28323c ble 0x283450 <spAnimationState_apply+0x230>
 *   @0x283240 vmov.f32 s19, #1.000000e+00
 *   @0x283244 mov r7, #0
 *   @0x283248 mov r8, r7
 *   @0x28324c add r12, sp, #28
 *   @0x283250 str r12, [sp, #0x14]
 *   @0x283254 ldr r2, [r4, #0x10]
 *   @0x283258 lsl r9, r7, #2
 *   @0x28325c ldr r6, [r2, r7, lsl #2]
 *   @0x283260 cmp r6, #0
 *   @0x283264 beq 0x283444 <spAnimationState_apply+0x224>
 *   @0x283268 ldr r12, [r6, #0x10]
 *   @0x28326c vldr s18, [r6, #24]
 *   @0x283270 str r8, [sp, #0x1c]
 *   @0x283274 cmp r12, #0
 *   @0x283278 bne 0x28328c <spAnimationState_apply+0x6c>
 *   @0x28327c vldr s15, [r6, #32]
 *   @0x283280 vcmp.f32 s18, s15
 *   @0x283284 vmrs APSR_nzcv, fpscr
 *   @0x283288 vmovgt.f32 s18, s15
 *   @0x28328c ldr r3, [r6, #0x8]
 *   @0x283290 cmp r3, #0
 *   @0x283294 beq 0x2834a0 <spAnimationState_apply+0x280>
 *   @0x283298 vldr s15, [r6, #48]
 *   @0x28329c vldr s16, [r6, #44]
 *   @0x2832a0 vdiv.f32 s16, s16, s15
 *   @0x2832a4 ldr r12, [r3, #0x10]
 *   @0x2832a8 vldr s14, [r6, #52]
 *   @0x2832ac vldr s15, [r3, #24]
 *   @0x2832b0 cmp r12, #0
 *   @0x2832b4 vmul.f32 s16, s16, s14
 *   @0x2832b8 bne 0x2832cc <spAnimationState_apply+0xac>
 *   @0x2832bc vldr s14, [r3, #32]
 *   @0x2832c0 vcmp.f32 s15, s14
 *   @0x2832c4 vmrs APSR_nzcv, fpscr
 *   @0x2832c8 vmovgt.f32 s15, s14
 *   @0x2832cc ldr r0, [r3, #0xc]
 *   @0x2832d0 mov r1, r10
 *   @0x2832d4 vmov r2, s15
 *   @0x2832d8 str r12, [sp]
 *   @0x2832dc str r8, [sp, #0x4]
 *   @0x2832e0 str r8, [sp, #0x8]
 *   @0x2832e4 vmov r3, s15
 *   @0x2832e8 bl 0x281500 <spAnimation_apply>
 *   @0x2832ec vcmpe.f32 s16, s19
 *   @0x2832f0 vmrs APSR_nzcv, fpscr
 *   @0x2832f4 blt 0x28330c <spAnimationState_apply+0xec>
 *   @0x2832f8 vmov.f32 s16, #1.000000e+00
 *   @0x2832fc ldr r3, [r4, #0x20]
 *   @0x283300 ldr r0, [r6, #0x8]
 *   @0x283304 blx r3
 *   @0x283308 str r8, [r6, #0x8]
 *   @0x28330c ldr r12, [r6, #0x10]
 *   @0x283310 mov r1, r10
 *   @0x283314 ldr r3, [r4, #0x18]
 *   @0x283318 ldr r0, [r6, #0xc]
 *   @0x28331c ldr r2, [r6, #0x1c]
 *   @0x283320 vstr s16, [sp, #12]
 *   @0x283324 str r12, [sp]
 *   @0x283328 add r12, sp, #28
 *   @0x28332c stmib sp, {r3, r12}
 *   @0x283330 vmov r3, s18
 *   @0x283334 bl 0x2815ec <spAnimation_mix>
 *   @0x283338 ldr r3, [sp, #0x1c]
 *   @0x28333c cmp r3, #0
 *   @0x283340 movgt r5, #0
 *   @0x283344 ble 0x2833c8 <spAnimationState_apply+0x1a8>
 *   @0x283348 ldr r12, [r6, #0x28]
 *   @0x28334c mov r0, r4
 *   @0x283350 ldr r3, [r4, #0x18]
 *   @0x283354 mov r1, r7
 *   @0x283358 cmp r12, #0
 *   @0x28335c mov r2, #3
 *   @0x283360 ldr r11, [r3, r5, lsl #2]
 *   @0x283364 beq 0x283384 <spAnimationState_apply+0x164>
 *   @0x283368 mov r3, r11
 *   @0x28336c str r8, [sp]
 *   @0x283370 blx r12
 *   @0x283374 ldr r3, [r4, #0x10]
 *   @0x283378 ldr r3, [r3, r9]
 *   @0x28337c cmp r3, r6
 *   @0x283380 bne 0x283440 <spAnimationState_apply+0x220>
 *   @0x283384 ldr r12, [r4, #0x8]
 *   @0x283388 mov r0, r4
 *   @0x28338c mov r1, r7
 *   @0x283390 mov r2, #3
 *   @0x283394 cmp r12, #0
 *   @0x283398 mov r3, r11
 *   @0x28339c beq 0x2833b8 <spAnimationState_apply+0x198>
 *   @0x2833a0 str r8, [sp]
 *   @0x2833a4 blx r12
 *   @0x2833a8 ldr r3, [r4, #0x10]
 *   @0x2833ac ldr r3, [r3, r9]
 *   @0x2833b0 cmp r3, r6
 *   @0x2833b4 bne 0x283440 <spAnimationState_apply+0x220>
 *   @0x2833b8 ldr r3, [sp, #0x1c]
 *   @0x2833bc add r5, r5, #1
 *   @0x2833c0 cmp r3, r5
 *   @0x2833c4 bgt 0x283348 <spAnimationState_apply+0x128>
 *   @0x2833c8 ldr r3, [r6, #0x10]
 *   @0x2833cc cmp r3, #0
 *   @0x2833d0 bne 0x2834dc <spAnimationState_apply+0x2bc>
 *   @0x2833d4 vldr s15, [r6, #32]
 *   @0x2833d8 vldr s14, [r6, #28]
 *   @0x2833dc vcmpe.f32 s14, s15
 *   @0x2833e0 vmrs APSR_nzcv, fpscr
 *   @0x2833e4 bpl 0x2833f8 <spAnimationState_apply+0x1d8>
 *   @0x2833e8 vcmpe.f32 s18, s15
 *   @0x2833ec vmrs APSR_nzcv, fpscr
 *   @0x2833f0 movlt r3, #0
 *   @0x2833f4 movge r3, #1
 *   @0x2833f8 cmp r3, #0
 *   @0x2833fc beq 0x283490 <spAnimationState_apply+0x270>
 *   @0x283400 vldr s15, [r6, #32]
 *   @0x283404 vdiv.f32 s18, s18, s15
 *   @0x283408 ldr r12, [r6, #0x28]
 *   @0x28340c cmp r12, #0
 *   @0x283410 vcvt.s32.f32 s18, s18
 *   @0x283414 beq 0x28345c <spAnimationState_apply+0x23c>
 *   @0x283418 mov r3, #0
 *   @0x28341c vstr s18, [sp]
 *   @0x283420 mov r0, r4
 *   @0x283424 mov r1, r7
 *   @0x283428 mov r2, #2
 *   @0x28342c blx r12
 *   @0x283430 ldr r3, [r4, #0x10]
 *   @0x283434 ldr r3, [r3, r9]
 *   @0x283438 cmp r3, r6
 *   @0x28343c beq 0x28345c <spAnimationState_apply+0x23c>
 *   @0x283440 ldr r3, [r4, #0xc]
 *   @0x283444 add r7, r7, #1
 *   @0x283448 cmp r3, r7
 *   @0x28344c bgt 0x283254 <spAnimationState_apply+0x34>
 *   @0x283450 add sp, sp, #36
 *   @0x283454 vpop {d8, d9}
 *   @0x283458 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x28345c ldr r12, [r4, #0x8]
 *   @0x283460 cmp r12, #0
 *   @0x283464 beq 0x283490 <spAnimationState_apply+0x270>
 *   @0x283468 mov r3, #0
 *   @0x28346c vstr s18, [sp]
 *   @0x283470 mov r0, r4
 *   @0x283474 mov r1, r7
 *   @0x283478 mov r2, #2
 *   @0x28347c blx r12
 *   @0x283480 ldr r3, [r4, #0x10]
 *   @0x283484 ldr r3, [r3, r9]
 *   @0x283488 cmp r3, r6
 *   @0x28348c bne 0x283440 <spAnimationState_apply+0x220>
 *   @0x283490 ldr r2, [r6, #0x18]
 *   @0x283494 ldr r3, [r4, #0xc]
 *   @0x283498 str r2, [r6, #0x1c]
 *   @0x28349c b 0x283444 <spAnimationState_apply+0x224>
 *   @0x2834a0 vldr s15, [r6, #52]
 *   @0x2834a4 vcmp.f32 s15, s19
 *   @0x2834a8 ldr r0, [r6, #0xc]
 *   @0x2834ac ldr r2, [r6, #0x1c]
 *   @0x2834b0 ldr r3, [r4, #0x18]
 *   @0x2834b4 vmrs APSR_nzcv, fpscr
 *   @0x2834b8 bne 0x283534 <spAnimationState_apply+0x314>
 *   @0x2834bc str r3, [sp, #0x4]
 *   @0x2834c0 mov r1, r10
 *   @0x2834c4 add r3, sp, #28
 *   @0x2834c8 str r12, [sp]
 *   @0x2834cc str r3, [sp, #0x8]
 *   @0x2834d0 vmov r3, s18
 *   @0x2834d4 bl 0x281500 <spAnimation_apply>
 *   @0x2834d8 b 0x283338 <spAnimationState_apply+0x118>
 *   @0x2834dc vldr s14, [r6, #28]
 *   @0x2834e0 vcvt.f64.f32 d6, s14
 *   @0x2834e4 vldr s15, [r6, #32]
 *   @0x2834e8 vmov r0, r1, d6
 *   @0x2834ec vcvt.f64.f32 d6, s15
 *   @0x2834f0 vmov r2, r3, d6
 *   @0x2834f4 bl 0xb66ac <fmod@plt>
 *   @0x2834f8 vldr s15, [r6, #32]
 *   @0x2834fc vcvt.f64.f32 d6, s18
 *   @0x283500 vmov d8, r0, r1
 *   @0x283504 vmov r0, r1, d6
 *   @0x283508 vcvt.f64.f32 d6, s15
 *   @0x28350c vmov r2, r3, d6
 *   @0x283510 bl 0xb66ac <fmod@plt>
 *   @0x283514 vcvt.f32.f64 s16, d8
 *   @0x283518 vmov d6, r0, r1
 *   @0x28351c vcvt.f32.f64 s15, d6
 *   @0x283520 vcmpe.f32 s16, s15
 *   @0x283524 vmrs APSR_nzcv, fpscr
 *   @0x283528 movle r3, #0
 *   @0x28352c movgt r3, #1
 *   @0x283530 b 0x2833f8 <spAnimationState_apply+0x1d8>
 *   @0x283534 str r12, [sp]
 *   @0x283538 vstr s15, [sp, #12]
 *   @0x28353c str r3, [sp, #0x4]
 *   @0x283540 add r12, sp, #28
 *   @0x283544 mov r1, r10
 *   @0x283548 str r12, [sp, #0x8]
 *   @0x28354c vmov r3, s18
 *   @0x283550 bl 0x2815ec <spAnimation_mix>
 *   @0x283554 b 0x283338 <spAnimationState_apply+0x118>
 *
 * ══ §2/42 GR_D3D_Set_View_Area  0x169408  size 820  205 条（0x169408..0x16973c）
 * @func 0x169408 0x16973c  size 820  205 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x169420→0x3f23a0, 0x16942c→0x3f239c, 0x1694c8→0x3f2398, 0x1694cc→0x3f2394, 0x1694d8→0x3f2390, 0x169500→0x4859b0, 0x169518→0x3f23bd, 0x16959c→0x3f237c
 * 调用序列: 0xb6580×2 / 0xb658c×2 / yyMatrix::LookAtLH(yyMatrix*, yyVector3*, yyVector3*, yyVector3*)×2 / Graphics::SetMatrices(float*, float*, float*)×2 / SetViewExtents(float, float, float, float, float) / yyMatrix::OrthoLH(yyMatrix*, float, float, float, float) / yyMatrix::PerspectiveLH(yyMatrix*, float, float, float, float)
 * 字段偏移 top8: 0x94×2 / 0x90×2 / 0x8c×2 / 0x80×2 / 0x248×2 / 0x20×2 / 0x2c×2 / 0x24×2
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169408 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x16940c vpush {d8, d9, d10}
 *   @0x169410 sub sp, sp, #180
 *   @0x169414 vldr s21, [pc, #748]
 *   @0x169418 ldr r5, [pc, #0x2ec]
 *   @0x16941c mov r4, #0
 *   @0x169420 ldr r9, [pc, #0x2e8]
 *   @0x169424 mov r6, #1065353216
 *   @0x169428 add r5, pc, r5
 *   @0x16942c ldr r8, [pc, #0x2e0]
 *   @0x169430 str r4, [sp, #0x68]
 *   @0x169434 vmov s18, r3
 *   @0x169438 str r4, [sp, #0x64]
 *   @0x16943c vmov s20, r0
 *   @0x169440 str r4, [sp, #0x60]
 *   @0x169444 vmov s19, r1
 *   @0x169448 str r4, [sp, #0x5c]
 *   @0x16944c vmov s17, r2
 *   @0x169450 str r6, [sp, #0x6c]
 *   @0x169454 str r6, [sp, #0x58]
 *   @0x169458 str r6, [sp, #0x44]
 *   @0x16945c str r6, [sp, #0x30]
 *   @0x169460 str r6, [sp, #0xac]
 *   @0x169464 str r6, [sp, #0x98]
 *   @0x169468 str r6, [sp, #0x84]
 *   @0x16946c str r6, [sp, #0x70]
 *   @0x169470 str r4, [sp, #0x54]
 *   @0x169474 str r4, [sp, #0x50]
 *   @0x169478 str r4, [sp, #0x4c]
 *   @0x16947c str r4, [sp, #0x48]
 *   @0x169480 str r4, [sp, #0x40]
 *   @0x169484 str r4, [sp, #0x3c]
 *   @0x169488 str r4, [sp, #0x38]
 *   @0x16948c str r4, [sp, #0x34]
 *   @0x169490 str r4, [sp, #0xa8]
 *   @0x169494 str r4, [sp, #0xa4]
 *   @0x169498 str r4, [sp, #0xa0]
 *   @0x16949c str r4, [sp, #0x9c]
 *   @0x1694a0 str r4, [sp, #0x94]
 *   @0x1694a4 str r4, [sp, #0x90]
 *   @0x1694a8 str r4, [sp, #0x8c]
 *   @0x1694ac str r4, [sp, #0x88]
 *   @0x1694b0 str r4, [sp, #0x80]
 *   @0x1694b4 str r4, [sp, #0x7c]
 *   @0x1694b8 str r4, [sp, #0x78]
 *   @0x1694bc str r4, [sp, #0x74]
 *   @0x1694c0 vldr s16, [sp, #232]
 *   @0x1694c4 ldr r9, [r5, r9]
 *   @0x1694c8 ldr r7, [pc, #0x248]
 *   @0x1694cc ldr lr, [pc, #0x248]
 *   @0x1694d0 str r0, [r9]
 *   @0x1694d4 ldr r8, [r5, r8]
 *   @0x1694d8 ldr r12, [pc, #0x240]
 *   @0x1694dc str r1, [r8]
 *   @0x1694e0 ldr r7, [r5, r7]
 *   @0x1694e4 str r2, [r7]
 *   @0x1694e8 ldr lr, [r5, lr]
 *   @0x1694ec str r3, [lr]
 *   @0x1694f0 ldr r12, [r5, r12]
 *   @0x1694f4 vstr s16, [sp]
 *   @0x1694f8 vstr s16, [r12]
 *   @0x1694fc bl 0x1692e4 <_Z14SetViewExtentsfffff>
 *   @0x169500 ldr r3, [pc, #0x21c]
 *   @0x169504 vmov.f32 s15, #5.000000e-01
 *   @0x169508 ldr r7, [r5, r3]
 *   @0x16950c ldrb r3, [r7]
 *   @0x169510 cmp r3, #0
 *   @0x169514 beq 0x16952c <_Z20GR_D3D_Set_View_Areafffff+0x124>
 *   @0x169518 ldr r3, [pc, #0x208]
 *   @0x16951c ldr r3, [r5, r3]
 *   @0x169520 ldrb r3, [r3]
 *   @0x169524 cmp r3, #0
 *   @0x169528 bne 0x169620 <_Z20GR_D3D_Set_View_Areafffff+0x218>
 *   @0x16952c vmla.f32 s20, s17, s15
 *   @0x169530 mov r6, #0
 *   @0x169534 mov r3, #0
 *   @0x169538 str r6, [sp, #0x20]
 *   @0x16953c movt r3, #0xc67a
 *   @0x169540 str r3, [sp, #0x14]
 *   @0x169544 add r4, sp, #48
 *   @0x169548 vmla.f32 s19, s18, s15
 *   @0x16954c vstr s20, [sp, #12]
 *   @0x169550 vstr s20, [sp, #24]
 *   @0x169554 vnmul.f32 s15, s16, s21
 *   @0x169558 vstr s19, [sp, #16]
 *   @0x16955c vstr s19, [sp, #28]
 *   @0x169560 vmov r0, s15
 *   @0x169564 bl 0xb6580 <sinf@plt>
 *   @0x169568 vmul.f32 s21, s16, s21
 *   @0x16956c mov r8, r0
 *   @0x169570 vmov r0, s21
 *   @0x169574 bl 0xb658c <cosf@plt>
 *   @0x169578 add r1, sp, #12
 *   @0x16957c add r2, sp, #24
 *   @0x169580 add r3, sp, #36
 *   @0x169584 str r6, [sp, #0x2c]
 *   @0x169588 add r6, sp, #112
 *   @0x16958c str r8, [sp, #0x24]
 *   @0x169590 str r0, [sp, #0x28]
 *   @0x169594 mov r0, r4
 *   @0x169598 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x16959c ldr r0, [pc, #0x188]
 *   @0x1695a0 ldr r1, [pc, #0x188]
 *   @0x1695a4 mov lr, #1
 *   @0x1695a8 ldrb r2, [r7]
 *   @0x1695ac mov r3, #1065353216
 *   @0x1695b0 ldr r0, [r5, r0]
 *   @0x1695b4 mov r12, #0
 *   @0x1695b8 cmp r2, #0
 *   @0x1695bc ldr r2, [pc, #0x170]
 *   @0x1695c0 movt r12, #0x46fa
 *   @0x1695c4 strb lr, [r0]
 *   @0x1695c8 mov r0, r6
 *   @0x1695cc ldr r1, [r5, r1]
 *   @0x1695d0 str r3, [r1]
 *   @0x1695d4 ldr r2, [r5, r2]
 *   @0x1695d8 vmov r1, s17
 *   @0x1695dc str r12, [r2]
 *   @0x1695e0 ldr r2, [pc, #0x150]
 *   @0x1695e4 ldr r2, [r5, r2]
 *   @0x1695e8 str r12, [sp]
 *   @0x1695ec vldr s15, [r2]
 *   @0x1695f0 vcvt.f32.s32 s15, s15
 *   @0x1695f4 vmulne.f32 s15, s15, s18
 *   @0x1695f8 vnmuleq.f32 s15, s18, s15
 *   @0x1695fc vmov r2, s15
 *   @0x169600 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff>
 *   @0x169604 mov r1, r4
 *   @0x169608 mov r2, r6
 *   @0x16960c mov r0, #0
 *   @0x169610 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_>
 *   @0x169614 add sp, sp, #180
 *   @0x169618 vpop {d8, d9, d10}
 *   @0x16961c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x169620 vmla.f32 s20, s17, s15
 *   @0x169624 str r4, [sp, #0x20]
 *   @0x169628 mov r7, #0
 *   @0x16962c vmla.f32 s19, s18, s15
 *   @0x169630 vstr s20, [sp, #12]
 *   @0x169634 vstr s20, [sp, #24]
 *   @0x169638 vnmul.f32 s14, s16, s21
 *   @0x16963c vstr s19, [sp, #16]
 *   @0x169640 vstr s19, [sp, #28]
 *   @0x169644 vneg.f32 s15, s17
 *   @0x169648 vmov r0, s14
 *   @0x16964c vstr s15, [sp, #20]
 *   @0x169650 bl 0xb6580 <sinf@plt>
 *   @0x169654 vmul.f32 s21, s16, s21
 *   @0x169658 mov r8, r0
 *   @0x16965c vmov r0, s21
 *   @0x169660 bl 0xb658c <cosf@plt>
 *   @0x169664 str r8, [sp, #0x24]
 *   @0x169668 add r8, sp, #48
 *   @0x16966c add r1, sp, #12
 *   @0x169670 add r2, sp, #24
 *   @0x169674 add r3, sp, #36
 *   @0x169678 str r4, [sp, #0x2c]
 *   @0x16967c add r4, sp, #112
 *   @0x169680 str r0, [sp, #0x28]
 *   @0x169684 mov r0, r8
 *   @0x169688 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x16968c vdiv.f32 s18, s18, s17
 *   @0x169690 ldr r3, [pc, #0x94]
 *   @0x169694 mov r2, #0
 *   @0x169698 ldr lr, [pc, #0x90]
 *   @0x16969c movt r2, #0x46fa
 *   @0x1696a0 ldr r12, [pc, #0x8c]
 *   @0x1696a4 mov r0, r4
 *   @0x1696a8 ldr r9, [r5, r3]
 *   @0x1696ac mov r3, r6
 *   @0x1696b0 ldr r1, [pc, #0x80]
 *   @0x1696b4 strb r7, [r9]
 *   @0x1696b8 ldr lr, [r5, lr]
 *   @0x1696bc str r6, [lr]
 *   @0x1696c0 ldr r12, [r5, r12]
 *   @0x1696c4 str r2, [r12]
 *   @0x1696c8 ldr r1, [r5, r1]
 *   @0x1696cc str r2, [sp]
 *   @0x1696d0 vldr s15, [r1]
 *   @0x1696d4 vdiv.f32 s17, s17, s17
 *   @0x1696d8 vcvt.f32.s32 s15, s15
 *   @0x1696dc vmov r1, s17
 *   @0x1696e0 vmul.f32 s15, s18, s15
 *   @0x1696e4 vmov r2, s15
 *   @0x1696e8 bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff>
 *   @0x1696ec mov r0, r7
 *   @0x1696f0 mov r1, r8
 *   @0x1696f4 mov r2, r4
 *   @0x1696f8 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_>
 *   @0x1696fc add sp, sp, #180
 *   @0x169700 vpop {d8, d9, d10}
 *   @0x169704 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x169708 vstmialo lr, {s30, s31}
 *   @0x16970c eoreq r8, r8, r8, lsr #16
 *   @0x169710 .word 0xffffe504
 *   @0x169714 .word 0xffffe508
 *   @0x169718 .word 0xffffe50c
 *   @0x16971c .word 0xffffe510
 *   @0x169720 .word 0xffffe514
 *   @0x169724 .word 0xffffc0b4
 *   @0x169728 .word 0xffffe4b0
 *   @0x16972c .word 0xffffe480
 *   @0x169730 .word 0xffffe484
 *   @0x169734 .word 0xffffe488
 *   @0x169738 .word 0xffffe48c
 *
 * ══ §3/42 b2ParticleSystem::Solve  0x2db370  size 816  204 条（0x2db370..0x2db6a0）
 * @func 0x2db370 0x2db6a0  size 816  204 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::Solve(b2TimeStep const&)+0x5c / b2ParticleSystem::GetCriticalVelocitySquared(b2TimeStep const&) const / b2ParticleSystem::SolveCollision(b2TimeStep const&) / b2ParticleSystem::Solve(b2TimeStep const&)+0x148 / b2ParticleSystem::UpdateBodyContacts() / b2ParticleSystem::UpdateContacts(bool) / b2ParticleSystem::SolvePressure(b2TimeStep const&) / b2ParticleSystem::Solve(b2TimeStep const&)+0xd4
 * 字段偏移 top8: 0x4×12 / 0x24×5 / 0x8×5 / 0x40×2 / 0x30×1 / 0xa8×1 / 0xc×1 / 0x18×1
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2db370 push {r3, r4, r5, r6, r7, lr}
 *   @0x2db374 vpush {d8, d9}
 *   @0x2db378 mov r5, r0
 *   @0x2db37c ldr r0, [r0, #0x24]
 *   @0x2db380 mov r7, r1
 *   @0x2db384 ldr r3, [r5]
 *   @0x2db388 cmp r0, #0
 *   @0x2db38c add r3, r3, #1
 *   @0x2db390 str r3, [r5]
 *   @0x2db394 beq 0x2db598 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x228>
 *   @0x2db398 mov r1, #0
 *   @0x2db39c str r1, [r5, #0x4]
 *   @0x2db3a0 ble 0x2db3cc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x5c>
 *   @0x2db3a4 ldr r3, [r5, #0x30]
 *   @0x2db3a8 add r0, r3, r0, lsl #2
 *   @0x2db3ac ldr r2, [r3], #4
 *   @0x2db3b0 orr r2, r2, r1
 *   @0x2db3b4 cmp r3, r0
 *   @0x2db3b8 str r2, [r5, #0x4]
 *   @0x2db3bc mov r1, r2
 *   @0x2db3c0 bne 0x2db3ac <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x3c>
 *   @0x2db3c4 tst r2, #2
 *   @0x2db3c8 bne 0x2db5b0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x240>
 *   @0x2db3cc ldr r3, [r5, #0xa8]
 *   @0x2db3d0 mov r1, #0
 *   @0x2db3d4 str r1, [r5, #0x8]
 *   @0x2db3d8 cmp r3, r1
 *   @0x2db3dc beq 0x2db3fc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x8c>
 *   @0x2db3e0 ldr r2, [r3, #0xc]
 *   @0x2db3e4 ldr r3, [r3, #0x18]
 *   @0x2db3e8 orr r2, r1, r2
 *   @0x2db3ec cmp r3, #0
 *   @0x2db3f0 mov r1, r2
 *   @0x2db3f4 bne 0x2db3e0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x70>
 *   @0x2db3f8 str r2, [r5, #0x8]
 *   @0x2db3fc vldr s15, [r5, #20]
 *   @0x2db400 vldr s18, [r7]
 *   @0x2db404 vmul.f32 s18, s18, s15
 *   @0x2db408 ldr r3, [r5, #0xd4]
 *   @0x2db40c mov r0, r5
 *   @0x2db410 mov r1, r7
 *   @0x2db414 add r2, r3, #102400
 *   @0x2db418 vldr s17, [r2, #568]
 *   @0x2db41c mov r3, r2
 *   @0x2db420 vldr s15, [r3, #572]
 *   @0x2db424 vmul.f32 s17, s18, s17
 *   @0x2db428 vmul.f32 s18, s18, s15
 *   @0x2db42c bl 0x2d856c <_ZNK16b2ParticleSystem26GetCriticalVelocitySquaredERK10b2TimeStep>
 *   @0x2db430 ldr r3, [r5, #0x24]
 *   @0x2db434 cmp r3, #0
 *   @0x2db438 movgt r6, #0
 *   @0x2db43c vmov s16, r0
 *   @0x2db440 bgt 0x2db55c <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1ec>
 *   @0x2db444 mov r0, r5
 *   @0x2db448 mov r1, r7
 *   @0x2db44c bl 0x2d5cc0 <_ZN16b2ParticleSystem14SolveCollisionERK10b2TimeStep>
 *   @0x2db450 ldr r3, [r5, #0x8]
 *   @0x2db454 tst r3, #2
 *   @0x2db458 bne 0x2db650 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2e0>
 *   @0x2db45c ldr r3, [r5, #0x4]
 *   @0x2db460 tst r3, #4
 *   @0x2db464 bne 0x2db668 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2f8>
 *   @0x2db468 ldr r1, [r5, #0x24]
 *   @0x2db46c cmp r1, #0
 *   @0x2db470 ble 0x2db4b8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x148>
 *   @0x2db474 ldr r2, [r5, #0x40]
 *   @0x2db478 vldr s13, [r7]
 *   @0x2db47c ldr r3, [r5, #0x38]
 *   @0x2db480 add r1, r2, r1, lsl #3
 *   @0x2db484 vldr s11, [r2, #4]
 *   @0x2db488 vldr s14, [r3, #4]
 *   @0x2db48c vldr s15, [r3]
 *   @0x2db490 mov r0, r2
 *   @0x2db494 vmla.f32 s14, s13, s11
 *   @0x2db498 vldr s12, [r0]
 *   @0x2db49c add r2, r2, #8
 *   @0x2db4a0 add r3, r3, #8
 *   @0x2db4a4 cmp r2, r1
 *   @0x2db4a8 vmla.f32 s15, s13, s12
 *   @0x2db4ac vstr s14, [r3, #-4]
 *   @0x2db4b0 vstr s15, [r3, #-8]
 *   @0x2db4b4 bne 0x2db484 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x114>
 *   @0x2db4b8 mov r0, r5
 *   @0x2db4bc bl 0x2d5b9c <_ZN16b2ParticleSystem18UpdateBodyContactsEv>
 *   @0x2db4c0 mov r0, r5
 *   @0x2db4c4 mov r1, #0
 *   @0x2db4c8 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb>
 *   @0x2db4cc ldr r3, [r5, #0x4]
 *   @0x2db4d0 tst r3, #32
 *   @0x2db4d4 bne 0x2db5bc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x24c>
 *   @0x2db4d8 tst r3, #64
 *   @0x2db4dc bne 0x2db5d4 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x264>
 *   @0x2db4e0 tst r3, #128
 *   @0x2db4e4 bne 0x2db5ec <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x27c>
 *   @0x2db4e8 tst r3, #16
 *   @0x2db4ec bne 0x2db604 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x294>
 *   @0x2db4f0 tst r3, #8
 *   @0x2db4f4 bne 0x2db61c <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2ac>
 *   @0x2db4f8 ldr r3, [r5, #0x8]
 *   @0x2db4fc tst r3, #1
 *   @0x2db500 bne 0x2db634 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2c4>
 *   @0x2db504 ldr r3, [r5, #0x4]
 *   @0x2db508 tst r3, #256
 *   @0x2db50c bne 0x2db5a0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x230>
 *   @0x2db510 mov r0, r5
 *   @0x2db514 mov r1, r7
 *   @0x2db518 bl 0x2d90a4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep>
 *   @0x2db51c vpop {d8, d9}
 *   @0x2db520 mov r0, r5
 *   @0x2db524 mov r1, r7
 *   @0x2db528 pop {r3, r4, r5, r6, r7, lr}
 *   @0x2db52c b 0x2d8a44 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep>
 *   @0x2db530 vdiv.f32 s13, s16, s13
 *   @0x2db534 vsqrt.f32 s12, s13
 *   @0x2db538 vcmp.f32 s12, s12
 *   @0x2db53c vmrs APSR_nzcv, fpscr
 *   @0x2db540 bne 0x2db684 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x314>
 *   @0x2db544 vmul.f32 s14, s14, s12
 *   @0x2db548 vmul.f32 s15, s15, s12
 *   @0x2db54c vstr s14, [r4]
 *   @0x2db550 vstr s15, [r4, #4]
 *   @0x2db554 cmp r3, r6
 *   @0x2db558 ble 0x2db444 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0xd4>
 *   @0x2db55c ldr r4, [r5, #0x40]
 *   @0x2db560 add r4, r4, r6, lsl #3
 *   @0x2db564 vldr s15, [r4, #4]
 *   @0x2db568 vadd.f32 s15, s18, s15
 *   @0x2db56c vldr s14, [r4]
 *   @0x2db570 add r6, r6, #1
 *   @0x2db574 vmul.f32 s13, s15, s15
 *   @0x2db578 vstr s15, [r4, #4]
 *   @0x2db57c vadd.f32 s14, s17, s14
 *   @0x2db580 vmla.f32 s13, s14, s14
 *   @0x2db584 vstr s14, [r4]
 *   @0x2db588 vcmpe.f32 s16, s13
 *   @0x2db58c vmrs APSR_nzcv, fpscr
 *   @0x2db590 bpl 0x2db554 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1e4>
 *   @0x2db594 b 0x2db530 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1c0>
 *   @0x2db598 vpop {d8, d9}
 *   @0x2db59c pop {r3, r4, r5, r6, r7, pc}
 *   @0x2db5a0 mov r0, r5
 *   @0x2db5a4 mov r1, r7
 *   @0x2db5a8 bl 0x2d6440 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep>
 *   @0x2db5ac b 0x2db510 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1a0>
 *   @0x2db5b0 mov r0, r5
 *   @0x2db5b4 bl 0x2d660c <_ZN16b2ParticleSystem11SolveZombieEv>
 *   @0x2db5b8 b 0x2db3cc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x5c>
 *   @0x2db5bc mov r0, r5
 *   @0x2db5c0 mov r1, r7
 *   @0x2db5c4 bl 0x2d8c88 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep>
 *   @0x2db5c8 ldr r3, [r5, #0x4]
 *   @0x2db5cc tst r3, #64
 *   @0x2db5d0 beq 0x2db4e0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x170>
 *   @0x2db5d4 mov r0, r5
 *   @0x2db5d8 mov r1, r7
 *   @0x2db5dc bl 0x2d8e98 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep>
 *   @0x2db5e0 ldr r3, [r5, #0x4]
 *   @0x2db5e4 tst r3, #128
 *   @0x2db5e8 beq 0x2db4e8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x178>
 *   @0x2db5ec mov r0, r5
 *   @0x2db5f0 mov r1, r7
 *   @0x2db5f4 bl 0x2d82fc <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep>
 *   @0x2db5f8 ldr r3, [r5, #0x4]
 *   @0x2db5fc tst r3, #16
 *   @0x2db600 beq 0x2db4f0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x180>
 *   @0x2db604 mov r0, r5
 *   @0x2db608 mov r1, r7
 *   @0x2db60c bl 0x2d5fc0 <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep>
 *   @0x2db610 ldr r3, [r5, #0x4]
 *   @0x2db614 tst r3, #8
 *   @0x2db618 beq 0x2db4f8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x188>
 *   @0x2db61c mov r0, r5
 *   @0x2db620 mov r1, r7
 *   @0x2db624 bl 0x2d620c <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep>
 *   @0x2db628 ldr r3, [r5, #0x8]
 *   @0x2db62c tst r3, #1
 *   @0x2db630 beq 0x2db504 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x194>
 *   @0x2db634 mov r0, r5
 *   @0x2db638 mov r1, r7
 *   @0x2db63c bl 0x2d6330 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep>
 *   @0x2db640 ldr r3, [r5, #0x4]
 *   @0x2db644 tst r3, #256
 *   @0x2db648 beq 0x2db510 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1a0>
 *   @0x2db64c b 0x2db5a0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x230>
 *   @0x2db650 mov r0, r5
 *   @0x2db654 mov r1, r7
 *   @0x2db658 bl 0x2d5e54 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep>
 *   @0x2db65c ldr r3, [r5, #0x4]
 *   @0x2db660 tst r3, #4
 *   @0x2db664 beq 0x2db468 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0xf8>
 *   @0x2db668 mov r1, r7
 *   @0x2db66c mov r0, r5
 *   @0x2db670 bl 0x2d5e08 <_ZN16b2ParticleSystem9SolveWallERK10b2TimeStep>
 *   @0x2db674 ldr r1, [r5, #0x24]
 *   @0x2db678 cmp r1, #0
 *   @0x2db67c bgt 0x2db474 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x104>
 *   @0x2db680 b 0x2db4b8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x148>
 *   @0x2db684 vmov r0, s13
 *   @0x2db688 bl 0xb6700 <sqrtf@plt>
 *   @0x2db68c ldr r3, [r5, #0x24]
 *   @0x2db690 vldr s14, [r4]
 *   @0x2db694 vldr s15, [r4, #4]
 *   @0x2db698 vmov s12, r0
 *   @0x2db69c b 0x2db544 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1d4>
 *
 * ══ §4/42 b2Island::SolveTOI  0x2e12c4  size 804  201 条（0x2e12c4..0x2e15e8）
 * @func 0x2e12c4 0x2e15e8  size 804  201 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Island::SolveTOI(b2TimeStep const&, int, int)+0x2e0×2 / b2Island::SolveTOI(b2TimeStep const&, int, int)+0x78 / b2ContactSolver::b2ContactSolver(b2ContactSolverDef*) / b2Island::SolveTOI(b2TimeStep const&, int, int)+0xfc / b2ContactSolver::SolveTOIPositionConstraints(int, int) / b2ContactSolver::InitializeVelocityConstraints() / b2Island::SolveTOI(b2TimeStep const&, int, int)+0x174 / b2ContactSolver::SolveVelocityConstraints()
 * 字段偏移 top8: 0x8×6 / 0x18×5 / 0xc×5 / 0x1c×4 / 0x14×4 / 0x24×2 / 0x10×2 / 0x2×2
 * VFP 指令 71 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e12c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e12c8 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2e12cc mov r6, r0
 *   @0x2e12d0 ldr r5, [r0, #0x1c]
 *   @0x2e12d4 sub sp, sp, #100
 *   @0x2e12d8 mov r4, r1
 *   @0x2e12dc mov r7, r2
 *   @0x2e12e0 cmp r5, #0
 *   @0x2e12e4 mov r8, r3
 *   @0x2e12e8 ldr r10, [r0, #0x14]
 *   @0x2e12ec ldr r9, [r0, #0x18]
 *   @0x2e12f0 ble 0x2e133c <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x78>
 *   @0x2e12f4 ldr r3, [r0, #0x8]
 *   @0x2e12f8 add lr, r10, #8
 *   @0x2e12fc add r12, r9, #8
 *   @0x2e1300 add r5, r3, r5, lsl #2
 *   @0x2e1304 ldr r2, [r3], #4
 *   @0x2e1308 vldr s15, [r2, #72]
 *   @0x2e130c add r1, r2, #60
 *   @0x2e1310 add r2, r2, #80
 *   @0x2e1314 ldr r11, [r2, #0x8]
 *   @0x2e1318 cmp r3, r5
 *   @0x2e131c ldm r1, {r0, r1}
 *   @0x2e1320 stmdb lr, {r0, r1}
 *   @0x2e1324 ldm r2, {r0, r1}
 *   @0x2e1328 vmov r2, s15
 *   @0x2e132c str r2, [lr], #12
 *   @0x2e1330 stmdb r12, {r0, r1}
 *   @0x2e1334 str r11, [r12], #12
 *   @0x2e1338 bne 0x2e1304 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x40>
 *   @0x2e133c mov lr, r4
 *   @0x2e1340 mov r12, sp
 *   @0x2e1344 ldm lr!, {r0, r1, r2, r3}
 *   @0x2e1348 add r5, sp, #44
 *   @0x2e134c ldr r11, [r6, #0xc]
 *   @0x2e1350 str r9, [sp, #0x24]
 *   @0x2e1354 str r10, [sp, #0x20]
 *   @0x2e1358 stm r12!, {r0, r1, r2, r3}
 *   @0x2e135c ldm lr, {r0, r1}
 *   @0x2e1360 ldr r3, [r6]
 *   @0x2e1364 ldr r2, [r6, #0x24]
 *   @0x2e1368 stm r12, {r0, r1}
 *   @0x2e136c mov r0, r5
 *   @0x2e1370 mov r1, sp
 *   @0x2e1374 str r3, [sp, #0x28]
 *   @0x2e1378 str r11, [sp, #0x18]
 *   @0x2e137c str r2, [sp, #0x1c]
 *   @0x2e1380 bl 0x2e2090 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef>
 *   @0x2e1384 ldr r3, [r4, #0x10]
 *   @0x2e1388 cmp r3, #0
 *   @0x2e138c movgt r9, #0
 *   @0x2e1390 bgt 0x2e13a4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0xe0>
 *   @0x2e1394 b 0x2e13c0 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0xfc>
 *   @0x2e1398 ldr r3, [r4, #0x10]
 *   @0x2e139c cmp r3, r9
 *   @0x2e13a0 ble 0x2e13c0 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0xfc>
 *   @0x2e13a4 mov r0, r5
 *   @0x2e13a8 mov r1, r7
 *   @0x2e13ac mov r2, r8
 *   @0x2e13b0 add r9, r9, #1
 *   @0x2e13b4 bl 0x2e33d8 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii>
 *   @0x2e13b8 cmp r0, #0
 *   @0x2e13bc beq 0x2e1398 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0xd4>
 *   @0x2e13c0 ldr r1, [r6, #0x8]
 *   @0x2e13c4 add r2, r7, r7, lsl #1
 *   @0x2e13c8 ldr r3, [r6, #0x14]
 *   @0x2e13cc add r0, r8, r8, lsl #1
 *   @0x2e13d0 add r2, r3, r2, lsl #2
 *   @0x2e13d4 ldr r7, [r1, r7, lsl #2]
 *   @0x2e13d8 ldr r12, [r1, r8, lsl #2]
 *   @0x2e13dc add r3, r3, r0, lsl #2
 *   @0x2e13e0 ldm r2, {r0, r1}
 *   @0x2e13e4 add r8, r7, #52
 *   @0x2e13e8 ldr r9, [r2, #0x8]
 *   @0x2e13ec add lr, r12, #52
 *   @0x2e13f0 ldr r2, [r3, #0x8]
 *   @0x2e13f4 stm r8, {r0, r1}
 *   @0x2e13f8 ldm r3, {r0, r1}
 *   @0x2e13fc str r9, [r7, #0x44]
 *   @0x2e1400 stm lr, {r0, r1}
 *   @0x2e1404 mov r0, r5
 *   @0x2e1408 str r2, [r12, #0x44]
 *   @0x2e140c bl 0x2e2398 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv>
 *   @0x2e1410 ldr r3, [r4, #0xc]
 *   @0x2e1414 cmp r3, #0
 *   @0x2e1418 movgt r7, #0
 *   @0x2e141c ble 0x2e1438 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x174>
 *   @0x2e1420 mov r0, r5
 *   @0x2e1424 add r7, r7, #1
 *   @0x2e1428 bl 0x2e28f4 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv>
 *   @0x2e142c ldr r3, [r4, #0xc]
 *   @0x2e1430 cmp r3, r7
 *   @0x2e1434 bgt 0x2e1420 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x15c>
 *   @0x2e1438 ldr r9, [r6, #0x1c]
 *   @0x2e143c vldr s20, [r4]
 *   @0x2e1440 cmp r9, #0
 *   @0x2e1444 ble 0x2e15a4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x2e0>
 *   @0x2e1448 mov r10, #0
 *   @0x2e144c vmov.f32 s24, #4.000000e+00
 *   @0x2e1450 ldr r8, [r6, #0x14]
 *   @0x2e1454 mov r11, r10
 *   @0x2e1458 ldr r7, [r6, #0x18]
 *   @0x2e145c vldr s23, [pc, #380]
 *   @0x2e1460 vldr s25, [pc, #380]
 *   @0x2e1464 vmov.f32 s26, #2.000000e+00
 *   @0x2e1468 b 0x2e1534 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x270>
 *   @0x2e146c vmul.f32 s17, s20, s16
 *   @0x2e1470 vmul.f32 s15, s17, s17
 *   @0x2e1474 vcmpe.f32 s15, s23
 *   @0x2e1478 vmrs APSR_nzcv, fpscr
 *   @0x2e147c ble 0x2e1498 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x1d4>
 *   @0x2e1480 vcmpe.f32 s17, #0
 *   @0x2e1484 vmrs APSR_nzcv, fpscr
 *   @0x2e1488 vnegle.f32 s17, s17
 *   @0x2e148c vdiv.f32 s17, s25, s17
 *   @0x2e1490 vmul.f32 s16, s16, s17
 *   @0x2e1494 vmul.f32 s17, s20, s16
 *   @0x2e1498 ldr r1, [r6, #0x8]
 *   @0x2e149c add r11, r11, #1
 *   @0x2e14a0 ldr r4, [r1, r10]
 *   @0x2e14a4 add r10, r10, #4
 *   @0x2e14a8 vadd.f32 s22, s22, s13
 *   @0x2e14ac vadd.f32 s21, s21, s14
 *   @0x2e14b0 vstr s22, [r2]
 *   @0x2e14b4 vadd.f32 s17, s27, s17
 *   @0x2e14b8 vstr s21, [r2, #4]
 *   @0x2e14bc vstr s17, [r2, #8]
 *   @0x2e14c0 vmov r0, s17
 *   @0x2e14c4 vstr s16, [r3, #8]
 *   @0x2e14c8 vstr s19, [r3]
 *   @0x2e14cc vstr s18, [r3, #4]
 *   @0x2e14d0 vstr s16, [r4, #88]
 *   @0x2e14d4 vstr s22, [r4, #60]
 *   @0x2e14d8 vstr s21, [r4, #64]
 *   @0x2e14dc vstr s17, [r4, #72]
 *   @0x2e14e0 vstr s19, [r4, #80]
 *   @0x2e14e4 vstr s18, [r4, #84]
 *   @0x2e14e8 bl 0xb6580 <sinf@plt>
 *   @0x2e14ec vmov s16, r0
 *   @0x2e14f0 vstr s16, [r4, #20]
 *   @0x2e14f4 vmov r0, s17
 *   @0x2e14f8 bl 0xb658c <cosf@plt>
 *   @0x2e14fc vldr s14, [r4, #48]
 *   @0x2e1500 vmul.f32 s13, s14, s16
 *   @0x2e1504 vldr s12, [r4, #44]
 *   @0x2e1508 cmp r9, r11
 *   @0x2e150c vmov s15, r0
 *   @0x2e1510 str r0, [r4, #0x18]
 *   @0x2e1514 vmul.f32 s14, s14, s15
 *   @0x2e1518 vnmls.f32 s13, s12, s15
 *   @0x2e151c vmla.f32 s14, s12, s16
 *   @0x2e1520 vsub.f32 s13, s22, s13
 *   @0x2e1524 vsub.f32 s14, s21, s14
 *   @0x2e1528 vstr s13, [r4, #12]
 *   @0x2e152c vstr s14, [r4, #16]
 *   @0x2e1530 ble 0x2e15a4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x2e0>
 *   @0x2e1534 add r4, r10, r10, lsl #1
 *   @0x2e1538 add r3, r7, r4
 *   @0x2e153c vldr s18, [r3, #4]
 *   @0x2e1540 vmul.f32 s14, s20, s18
 *   @0x2e1544 vldr s19, [r3]
 *   @0x2e1548 add r2, r8, r4
 *   @0x2e154c vldr s16, [r3, #8]
 *   @0x2e1550 vldr s22, [r2]
 *   @0x2e1554 vldr s21, [r2, #4]
 *   @0x2e1558 vldr s27, [r2, #8]
 *   @0x2e155c vmul.f32 s13, s20, s19
 *   @0x2e1560 vmul.f32 s15, s14, s14
 *   @0x2e1564 vmla.f32 s15, s13, s13
 *   @0x2e1568 vcmpe.f32 s15, s24
 *   @0x2e156c vmrs APSR_nzcv, fpscr
 *   @0x2e1570 ble 0x2e146c <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x1a8>
 *   @0x2e1574 vsqrt.f32 s14, s15
 *   @0x2e1578 vcmp.f32 s14, s14
 *   @0x2e157c vmrs APSR_nzcv, fpscr
 *   @0x2e1580 bne 0x2e15c4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x300>
 *   @0x2e1584 vdiv.f32 s14, s26, s14
 *   @0x2e1588 add r2, r8, r4
 *   @0x2e158c add r3, r7, r4
 *   @0x2e1590 vmul.f32 s19, s19, s14
 *   @0x2e1594 vmul.f32 s18, s18, s14
 *   @0x2e1598 vmul.f32 s13, s20, s19
 *   @0x2e159c vmul.f32 s14, s20, s18
 *   @0x2e15a0 b 0x2e146c <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x1a8>
 *   @0x2e15a4 mov r0, r6
 *   @0x2e15a8 ldr r1, [sp, #0x54]
 *   @0x2e15ac bl 0x2e1224 <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint>
 *   @0x2e15b0 mov r0, r5
 *   @0x2e15b4 bl 0x2e2370 <_ZN15b2ContactSolverD2Ev>
 *   @0x2e15b8 add sp, sp, #100
 *   @0x2e15bc vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2e15c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e15c4 vmov r0, s15
 *   @0x2e15c8 bl 0xb6700 <sqrtf@plt>
 *   @0x2e15cc ldr r9, [r6, #0x1c]
 *   @0x2e15d0 ldr r8, [r6, #0x14]
 *   @0x2e15d4 ldr r7, [r6, #0x18]
 *   @0x2e15d8 vmov s14, r0
 *   @0x2e15dc b 0x2e1584 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x2c0>
 *   @0x2e15e0 andsmi lr, sp, r7, ror #19
 *   @0x2e15e4 svclo #0xc90fdb
 *
 * ══ §5/42 yySocket::Resolve  0x2954a8  size 792  198 条（0x2954a8..0x2957c0）
 * @func 0x2954a8 0x2957c0  size 792  198 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29556c→0x7578c0, 0x295668→0x7578c0
 * 调用序列: 0xb6e2c×3 / 0xb65bc×3 / MemoryManager::Free(void const*)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb6574×2 / 0xb6e38×2 / yySocket::DetectIPv6() / 0xb6604
 * 字段偏移 top8: 0x4×7 / 0x18×6 / 0x10×5 / 0x8×3 / 0x1c×3 / 0x64×2 / 0xc×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2954a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2954ac sub sp, sp, #108
 *   @0x2954b0 ldr r9, [pc, #0x2dc]
 *   @0x2954b4 mov r4, r0
 *   @0x2954b8 ldr r3, [pc, #0x2d8]
 *   @0x2954bc add r9, pc, r9
 *   @0x2954c0 ldr r5, [r9, r3]
 *   @0x2954c4 ldr r3, [r5]
 *   @0x2954c8 str r3, [sp, #0x64]
 *   @0x2954cc bl 0x297000 <_ZN8yySocket10DetectIPv6Ev>
 *   @0x2954d0 subs r7, r0, #0
 *   @0x2954d4 beq 0x2955f8 <_ZN8yySocket7ResolveEPc+0x150>
 *   @0x2954d8 ldr r1, [pc, #0x2bc]
 *   @0x2954dc mov r2, #70
 *   @0x2954e0 mov r3, #1
 *   @0x2954e4 mov r0, #28
 *   @0x2954e8 add r1, pc, r1
 *   @0x2954ec mov r7, #0
 *   @0x2954f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2954f4 ldr r1, [pc, #0x2a4]
 *   @0x2954f8 mov r3, #2
 *   @0x2954fc str r7, [sp]
 *   @0x295500 add r1, pc, r1
 *   @0x295504 mov r6, r0
 *   @0x295508 mov r0, r4
 *   @0x29550c strh r3, [r6]
 *   @0x295510 bl 0xb6574 <strcmp@plt>
 *   @0x295514 cmp r0, #0
 *   @0x295518 beq 0x295688 <_ZN8yySocket7ResolveEPc+0x1e0>
 *   @0x29551c ldr r1, [pc, #0x280]
 *   @0x295520 mov r0, r4
 *   @0x295524 str r7, [sp, #0x4]
 *   @0x295528 add r1, pc, r1
 *   @0x29552c str r7, [sp, #0x8]
 *   @0x295530 str r7, [sp, #0xc]
 *   @0x295534 str r7, [sp, #0x10]
 *   @0x295538 str r7, [sp, #0x14]
 *   @0x29553c str r7, [sp, #0x18]
 *   @0x295540 str r7, [sp, #0x1c]
 *   @0x295544 str r7, [sp, #0x20]
 *   @0x295548 bl 0xb6604 <strstr@plt>
 *   @0x29554c cmp r0, r7
 *   @0x295550 beq 0x2956ac <_ZN8yySocket7ResolveEPc+0x204>
 *   @0x295554 add r8, sp, #4
 *   @0x295558 mov r3, sp
 *   @0x29555c mov r0, r4
 *   @0x295560 mov r1, #0
 *   @0x295564 mov r2, r8
 *   @0x295568 bl 0xb6e2c <getaddrinfo@plt>
 *   @0x29556c ldr r3, [pc, #0x234]
 *   @0x295570 ldr r9, [r9, r3]
 *   @0x295574 cmp r0, #0
 *   @0x295578 str r0, [r9]
 *   @0x29557c bne 0x2956b8 <_ZN8yySocket7ResolveEPc+0x210>
 *   @0x295580 ldr r3, [sp]
 *   @0x295584 cmp r3, #0
 *   @0x295588 beq 0x295750 <_ZN8yySocket7ResolveEPc+0x2a8>
 *   @0x29558c mov r4, r0
 *   @0x295590 mov r12, r3
 *   @0x295594 mov r10, r0
 *   @0x295598 ldr lr, [r12, #0x4]
 *   @0x29559c cmp lr, #10
 *   @0x2955a0 moveq r10, r12
 *   @0x2955a4 beq 0x2955b0 <_ZN8yySocket7ResolveEPc+0x108>
 *   @0x2955a8 cmp lr, #2
 *   @0x2955ac moveq r4, r12
 *   @0x2955b0 ldr r12, [r12, #0x1c]
 *   @0x2955b4 cmp r12, #0
 *   @0x2955b8 bne 0x295598 <_ZN8yySocket7ResolveEPc+0xf0>
 *   @0x2955bc cmp r10, #0
 *   @0x2955c0 beq 0x2956d8 <_ZN8yySocket7ResolveEPc+0x230>
 *   @0x2955c4 mov r0, r6
 *   @0x2955c8 ldr r1, [r10, #0x18]
 *   @0x2955cc ldr r2, [r10, #0x10]
 *   @0x2955d0 bl 0xb65bc <memcpy@plt>
 *   @0x2955d4 ldr r0, [sp]
 *   @0x2955d8 bl 0xb6e38 <freeaddrinfo@plt>
 *   @0x2955dc mov r0, r6
 *   @0x2955e0 ldr r2, [sp, #0x64]
 *   @0x2955e4 ldr r3, [r5]
 *   @0x2955e8 cmp r2, r3
 *   @0x2955ec bne 0x295790 <_ZN8yySocket7ResolveEPc+0x2e8>
 *   @0x2955f0 add sp, sp, #108
 *   @0x2955f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2955f8 ldr r1, [pc, #0x1ac]
 *   @0x2955fc mov r2, #70
 *   @0x295600 mov r3, #1
 *   @0x295604 mov r0, #16
 *   @0x295608 add r1, pc, r1
 *   @0x29560c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x295610 ldr r1, [pc, #0x198]
 *   @0x295614 str r7, [sp, #0x4]
 *   @0x295618 mov r3, #2
 *   @0x29561c add r1, pc, r1
 *   @0x295620 mov r6, r0
 *   @0x295624 mov r0, r4
 *   @0x295628 strh r3, [r6]
 *   @0x29562c bl 0xb6574 <strcmp@plt>
 *   @0x295630 cmp r0, #0
 *   @0x295634 ldreq r4, [pc, #0x178]
 *   @0x295638 addeq r4, pc, r4
 *   @0x29563c mov r0, r4
 *   @0x295640 bl 0xb6e44 <inet_addr@plt>
 *   @0x295644 cmn r0, #1
 *   @0x295648 str r0, [r6, #0x4]
 *   @0x29564c movne r0, r6
 *   @0x295650 bne 0x2955e0 <_ZN8yySocket7ResolveEPc+0x138>
 *   @0x295654 mov r1, #0
 *   @0x295658 add r3, sp, #4
 *   @0x29565c mov r0, r4
 *   @0x295660 mov r2, r1
 *   @0x295664 bl 0xb6e2c <getaddrinfo@plt>
 *   @0x295668 ldr r3, [pc, #0x138]
 *   @0x29566c ldr r3, [r9, r3]
 *   @0x295670 cmp r0, #0
 *   @0x295674 str r0, [r3]
 *   @0x295678 beq 0x295774 <_ZN8yySocket7ResolveEPc+0x2cc>
 *   @0x29567c mov r0, r6
 *   @0x295680 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x295684 b 0x2956d0 <_ZN8yySocket7ResolveEPc+0x228>
 *   @0x295688 ldr r4, [pc, #0x128]
 *   @0x29568c str r0, [sp, #0x8]
 *   @0x295690 add r4, pc, r4
 *   @0x295694 str r0, [sp, #0xc]
 *   @0x295698 str r0, [sp, #0x10]
 *   @0x29569c str r0, [sp, #0x14]
 *   @0x2956a0 str r0, [sp, #0x18]
 *   @0x2956a4 str r0, [sp, #0x1c]
 *   @0x2956a8 str r0, [sp, #0x20]
 *   @0x2956ac mov r3, #4
 *   @0x2956b0 str r3, [sp, #0x4]
 *   @0x2956b4 b 0x295554 <_ZN8yySocket7ResolveEPc+0xac>
 *   @0x2956b8 mov r0, r6
 *   @0x2956bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2956c0 ldr r0, [sp]
 *   @0x2956c4 cmp r0, #0
 *   @0x2956c8 beq 0x2955e0 <_ZN8yySocket7ResolveEPc+0x138>
 *   @0x2956cc bl 0xb6e38 <freeaddrinfo@plt>
 *   @0x2956d0 mov r0, #0
 *   @0x2956d4 b 0x2955e0 <_ZN8yySocket7ResolveEPc+0x138>
 *   @0x2956d8 cmp r4, #0
 *   @0x2956dc beq 0x295750 <_ZN8yySocket7ResolveEPc+0x2a8>
 *   @0x2956e0 ldr r12, [r4, #0x18]
 *   @0x2956e4 add r4, sp, #36
 *   @0x2956e8 ldr r1, [pc, #0xcc]
 *   @0x2956ec mov r0, r4
 *   @0x2956f0 ldrb lr, [r12, #0x6]
 *   @0x2956f4 add r1, pc, r1
 *   @0x2956f8 ldrb r11, [r12, #0x4]
 *   @0x2956fc ldrb r2, [r12, #0x5]
 *   @0x295700 ldrb r3, [r12, #0x7]
 *   @0x295704 orr r2, r2, r11, lsl #8
 *   @0x295708 orr r3, r3, lr, lsl #8
 *   @0x29570c bl 0xb6550 <sprintf@plt>
 *   @0x295710 mov r0, r4
 *   @0x295714 mov r1, r10
 *   @0x295718 mov r2, r8
 *   @0x29571c mov r3, sp
 *   @0x295720 mov r12, #10
 *   @0x295724 str r12, [sp, #0x8]
 *   @0x295728 bl 0xb6e2c <getaddrinfo@plt>
 *   @0x29572c cmp r0, #0
 *   @0x295730 str r0, [r9]
 *   @0x295734 beq 0x295758 <_ZN8yySocket7ResolveEPc+0x2b0>
 *   @0x295738 mov r0, r6
 *   @0x29573c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x295740 ldr r0, [sp]
 *   @0x295744 cmp r0, #0
 *   @0x295748 bne 0x2956cc <_ZN8yySocket7ResolveEPc+0x224>
 *   @0x29574c b 0x2956d0 <_ZN8yySocket7ResolveEPc+0x228>
 *   @0x295750 mov r0, r3
 *   @0x295754 b 0x2955d8 <_ZN8yySocket7ResolveEPc+0x130>
 *   @0x295758 ldr r3, [sp]
 *   @0x29575c mov r0, r6
 *   @0x295760 ldr r1, [r3, #0x18]
 *   @0x295764 ldr r2, [r3, #0x10]
 *   @0x295768 bl 0xb65bc <memcpy@plt>
 *   @0x29576c ldr r0, [sp]
 *   @0x295770 b 0x2955d8 <_ZN8yySocket7ResolveEPc+0x130>
 *   @0x295774 ldr r3, [sp, #0x4]
 *   @0x295778 mov r0, r6
 *   @0x29577c ldr r1, [r3, #0x18]
 *   @0x295780 ldr r2, [r3, #0x10]
 *   @0x295784 bl 0xb65bc <memcpy@plt>
 *   @0x295788 mov r0, r6
 *   @0x29578c b 0x2955e0 <_ZN8yySocket7ResolveEPc+0x138>
 *   @0x295790 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x295794 mulseq r5, r4, r7
 *   @0x295798 .word 0xffffbd00
 *   @0x29579c andeq r11, r9, r8, asr #22
 *   @0x2957a0 andeq r1, r11, r4, lsl #2
 *   @0x2957a4 andeq r3, r12, r4, asr sp
 *   @0x2957a8 .word 0xfffffd40
 *   @0x2957ac andeq r11, r9, r8, lsr #20
 *   @0x2957b0 andeq r0, r11, r8, ror #31
 *   @0x2957b4 andeq r3, r12, r8, lsr r12
 *   @0x2957b8 andeq r3, r12, r0, ror #23
 *   @0x2957bc andeq r3, r12, r12, lsl #23
 *
 * ══ §6/42 CDS_Map::Clear  0x20daf8  size 784  196 条（0x20daf8..0x20de08）
 * @func 0x20daf8 0x20de08  size 784  196 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x20dba0→0x4836b8, 0x20dd4c→0x4836ac, 0x20dd60→0x4836b0, 0x20ddac→0x4836bc
 * 调用序列: FREE_RValue__Pre(RValue*)×4 / CDS_Map::Clear()+0xbc×2 / operator delete(void*)×2 / DS_AutoMutex::DS_AutoMutex() / CDS_Map::Clear()+0x24c / CDS_Map::Clear()+0x2b4 / CDS_Map::Clear()+0x128 / CDS_Map::Clear()+0x218
 * 字段偏移 top8: 0x4×11 / 0xc×8 / 0x10×7 / 0x1c×5 / 0x8×5 / 0x2×4 / 0x14×2 / 0x18×2
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20daf8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20dafc sub sp, sp, #36
 *   @0x20db00 add r3, sp, #28
 *   @0x20db04 mov r11, r0
 *   @0x20db08 str r3, [sp, #0x14]
 *   @0x20db0c mov r6, #0
 *   @0x20db10 mov r0, r3
 *   @0x20db14 ldr r9, [pc, #0x2d8]
 *   @0x20db18 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x20db1c ldr r10, [r11]
 *   @0x20db20 add r9, pc, r9
 *   @0x20db24 ldr r1, [r10]
 *   @0x20db28 b 0x20db3c <_ZN7CDS_Map5ClearEv+0x44>
 *   @0x20db2c ldr r3, [r10, #0x4]
 *   @0x20db30 add r6, r6, #1
 *   @0x20db34 cmp r6, r3
 *   @0x20db38 bgt 0x20ddec <_ZN7CDS_Map5ClearEv+0x2f4>
 *   @0x20db3c ldr r5, [r1, r6, lsl #3]
 *   @0x20db40 cmp r5, #0
 *   @0x20db44 beq 0x20db2c <_ZN7CDS_Map5ClearEv+0x34>
 *   @0x20db48 mov r7, #0
 *   @0x20db4c mov r8, #5
 *   @0x20db50 cmp r5, #0
 *   @0x20db54 beq 0x20dc40 <_ZN7CDS_Map5ClearEv+0x148>
 *   @0x20db58 ldr r4, [r5, #0xc]
 *   @0x20db5c cmp r4, #0
 *   @0x20db60 beq 0x20dc40 <_ZN7CDS_Map5ClearEv+0x148>
 *   @0x20db64 ldr r3, [r4, #0x1c]
 *   @0x20db68 uxth r1, r3
 *   @0x20db6c cmp r1, #0
 *   @0x20db70 bne 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20db74 tst r3, #-1073741824
 *   @0x20db78 beq 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20db7c ldr r2, [r4, #0x10]
 *   @0x20db80 cmp r3, #0
 *   @0x20db84 ldr r3, [r4, #0x14]
 *   @0x20db88 vmov d7, r2, r3
 *   @0x20db8c vcvt.s32.f64 s15, d7
 *   @0x20db90 vmov r2, s15
 *   @0x20db94 blt 0x20dd44 <_ZN7CDS_Map5ClearEv+0x24c>
 *   @0x20db98 cmp r2, #0
 *   @0x20db9c blt 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20dba0 ldr r3, [pc, #0x250]
 *   @0x20dba4 ldr r3, [r9, r3]
 *   @0x20dba8 ldr r3, [r3]
 *   @0x20dbac cmp r2, r3
 *   @0x20dbb0 blt 0x20ddac <_ZN7CDS_Map5ClearEv+0x2b4>
 *   @0x20dbb4 ldr r3, [r4, #0xc]
 *   @0x20dbb8 sub r3, r3, #1
 *   @0x20dbbc bic r3, r3, #-16777216
 *   @0x20dbc0 bic r3, r3, #3
 *   @0x20dbc4 cmp r3, #0
 *   @0x20dbc8 beq 0x20dd38 <_ZN7CDS_Map5ClearEv+0x240>
 *   @0x20dbcc ldr r3, [r4, #0x1c]
 *   @0x20dbd0 str r7, [r4, #0x8]
 *   @0x20dbd4 sub r3, r3, #1
 *   @0x20dbd8 str r8, [r4, #0xc]
 *   @0x20dbdc bic r3, r3, #-16777216
 *   @0x20dbe0 str r7, [r4]
 *   @0x20dbe4 bic r3, r3, #3
 *   @0x20dbe8 cmp r3, #0
 *   @0x20dbec beq 0x20dd2c <_ZN7CDS_Map5ClearEv+0x234>
 *   @0x20dbf0 str r7, [r4, #0x10]
 *   @0x20dbf4 ldr r5, [r5, #0x4]
 *   @0x20dbf8 str r7, [r4, #0x18]
 *   @0x20dbfc cmp r5, #0
 *   @0x20dc00 str r8, [r4, #0x1c]
 *   @0x20dc04 bne 0x20db50 <_ZN7CDS_Map5ClearEv+0x58>
 *   @0x20dc08 ldr r1, [r10, #0x4]
 *   @0x20dc0c add r3, r6, #1
 *   @0x20dc10 cmp r3, r1
 *   @0x20dc14 bgt 0x20dc40 <_ZN7CDS_Map5ClearEv+0x148>
 *   @0x20dc18 ldr r2, [r10]
 *   @0x20dc1c add r2, r2, r6, lsl #3
 *   @0x20dc20 ldr r5, [r2, #0x8]
 *   @0x20dc24 mov r6, r3
 *   @0x20dc28 add r2, r2, #8
 *   @0x20dc2c add r3, r3, #1
 *   @0x20dc30 cmp r5, #0
 *   @0x20dc34 bne 0x20db50 <_ZN7CDS_Map5ClearEv+0x58>
 *   @0x20dc38 cmp r3, r1
 *   @0x20dc3c ble 0x20dc20 <_ZN7CDS_Map5ClearEv+0x128>
 *   @0x20dc40 ldr r10, [r11]
 *   @0x20dc44 ldr r11, [r10, #0x4]
 *   @0x20dc48 cmp r11, #0
 *   @0x20dc4c lslge r8, r11, #3
 *   @0x20dc50 movge r7, #0
 *   @0x20dc54 movge r9, #5
 *   @0x20dc58 blt 0x20dd10 <_ZN7CDS_Map5ClearEv+0x218>
 *   @0x20dc5c ldr r3, [r10]
 *   @0x20dc60 add r2, r3, r8
 *   @0x20dc64 ldr r4, [r3, r8]
 *   @0x20dc68 str r7, [r3, r8]
 *   @0x20dc6c cmp r4, #0
 *   @0x20dc70 str r7, [r2, #0x4]
 *   @0x20dc74 beq 0x20dd00 <_ZN7CDS_Map5ClearEv+0x208>
 *   @0x20dc78 ldr r5, [r4, #0xc]
 *   @0x20dc7c ldr r6, [r4, #0x4]
 *   @0x20dc80 cmp r5, #0
 *   @0x20dc84 beq 0x20dce0 <_ZN7CDS_Map5ClearEv+0x1e8>
 *   @0x20dc88 ldr r3, [r5, #0xc]
 *   @0x20dc8c sub r3, r3, #1
 *   @0x20dc90 bic r3, r3, #-16777216
 *   @0x20dc94 bic r3, r3, #3
 *   @0x20dc98 cmp r3, #0
 *   @0x20dc9c beq 0x20dd20 <_ZN7CDS_Map5ClearEv+0x228>
 *   @0x20dca0 ldr r3, [r5, #0x1c]
 *   @0x20dca4 str r7, [r5, #0x8]
 *   @0x20dca8 sub r3, r3, #1
 *   @0x20dcac str r9, [r5, #0xc]
 *   @0x20dcb0 bic r3, r3, #-16777216
 *   @0x20dcb4 str r7, [r5]
 *   @0x20dcb8 bic r3, r3, #3
 *   @0x20dcbc cmp r3, #0
 *   @0x20dcc0 bne 0x20dccc <_ZN7CDS_Map5ClearEv+0x1d4>
 *   @0x20dcc4 add r0, r5, #16
 *   @0x20dcc8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20dccc str r7, [r5, #0x18]
 *   @0x20dcd0 mov r0, r5
 *   @0x20dcd4 str r9, [r5, #0x1c]
 *   @0x20dcd8 str r7, [r5, #0x10]
 *   @0x20dcdc bl 0x27d1d0 <_ZdlPv>
 *   @0x20dce0 mov r0, r4
 *   @0x20dce4 mov r4, r6
 *   @0x20dce8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20dcec ldr r3, [r10, #0x8]
 *   @0x20dcf0 cmp r6, #0
 *   @0x20dcf4 sub r3, r3, #1
 *   @0x20dcf8 str r3, [r10, #0x8]
 *   @0x20dcfc bne 0x20dc78 <_ZN7CDS_Map5ClearEv+0x180>
 *   @0x20dd00 sub r11, r11, #1
 *   @0x20dd04 sub r8, r8, #8
 *   @0x20dd08 cmn r11, #1
 *   @0x20dd0c bne 0x20dc5c <_ZN7CDS_Map5ClearEv+0x164>
 *   @0x20dd10 add r0, sp, #28
 *   @0x20dd14 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x20dd18 add sp, sp, #36
 *   @0x20dd1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20dd20 mov r0, r5
 *   @0x20dd24 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20dd28 b 0x20dca0 <_ZN7CDS_Map5ClearEv+0x1a8>
 *   @0x20dd2c add r0, r4, #16
 *   @0x20dd30 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20dd34 b 0x20dbf0 <_ZN7CDS_Map5ClearEv+0xf8>
 *   @0x20dd38 mov r0, r4
 *   @0x20dd3c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20dd40 b 0x20dbcc <_ZN7CDS_Map5ClearEv+0xd4>
 *   @0x20dd44 cmp r2, #0
 *   @0x20dd48 blt 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20dd4c ldr r3, [pc, #0xa8]
 *   @0x20dd50 ldr r3, [r9, r3]
 *   @0x20dd54 ldr r3, [r3]
 *   @0x20dd58 cmp r2, r3
 *   @0x20dd5c bge 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20dd60 ldr r3, [pc, #0x98]
 *   @0x20dd64 ldr r12, [r9, r3]
 *   @0x20dd68 ldr r3, [r12, #0x4]
 *   @0x20dd6c ldr r3, [r3, r2, lsl #2]
 *   @0x20dd70 cmp r3, #0
 *   @0x20dd74 beq 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20dd78 mov r0, r3
 *   @0x20dd7c stmib sp, {r1, r2}
 *   @0x20dd80 str r12, [sp, #0xc]
 *   @0x20dd84 str r3, [sp, #0x10]
 *   @0x20dd88 bl 0x20d9e8 <_ZN7CDS_MapD2Ev>
 *   @0x20dd8c ldr r3, [sp, #0x10]
 *   @0x20dd90 mov r0, r3
 *   @0x20dd94 bl 0x27d1d0 <_ZdlPv>
 *   @0x20dd98 ldr r12, [sp, #0xc]
 *   @0x20dd9c ldmib sp, {r1, r2}
 *   @0x20dda0 ldr r3, [r12, #0x4]
 *   @0x20dda4 str r1, [r3, r2, lsl #2]
 *   @0x20dda8 b 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20ddac ldr r3, [pc, #0x50]
 *   @0x20ddb0 ldr r3, [r9, r3]
 *   @0x20ddb4 ldr r0, [r3, #0x4]
 *   @0x20ddb8 ldr r0, [r0, r2, lsl #2]
 *   @0x20ddbc cmp r0, #0
 *   @0x20ddc0 beq 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20ddc4 ldr r12, [r0]
 *   @0x20ddc8 ldr r12, [r12, #0x4]
 *   @0x20ddcc stmib sp, {r1, r2}
 *   @0x20ddd0 str r3, [sp, #0x10]
 *   @0x20ddd4 blx r12
 *   @0x20ddd8 ldr r3, [sp, #0x10]
 *   @0x20dddc ldmib sp, {r1, r2}
 *   @0x20dde0 ldr r3, [r3, #0x4]
 *   @0x20dde4 str r1, [r3, r2, lsl #2]
 *   @0x20dde8 b 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc>
 *   @0x20ddec mvn r6, #0
 *   @0x20ddf0 b 0x20db48 <_ZN7CDS_Map5ClearEv+0x50>
 *   @0x20ddf4 andseq r4, lr, r0, lsr r1
 *   @0x20ddf8 .word 0xffffc02c
 *   @0x20ddfc .word 0xffffc028
 *   @0x20de00 .word 0xffffbcec
 *   @0x20de04 .word 0xffffc030
 *
 * ══ §7/42 JS_Argument_Put  0x2499cc  size 784  196 条（0x2499cc..0x249cdc）
 * @func 0x2499cc 0x249cdc  size 784  196 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYObjectBase::InternalGetYYVar(int)×3 / PushContextStack(YYObjectBase*)×2 / PopContextStack()×2 / 0xb66c4
 * 字段偏移 top8: 0x4×11 / 0x8×8 / 0xc×5 / 0x1×2 / 0x2f0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2499cc push {r3, r4, r5, r6, r7, lr}
 *   @0x2499d0 mov r7, r2
 *   @0x2499d4 mov r5, r1
 *   @0x2499d8 mov r6, r0
 *   @0x2499dc bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x2499e0 ldr r3, [pc, #0x2f0]
 *   @0x2499e4 mov r12, r7
 *   @0x2499e8 ldr r3, [pc, r3]
 *   @0x2499ec ldr r4, [r3]
 *   @0x2499f0 ldrb r3, [r12], #1
 *   @0x2499f4 cmp r3, #0
 *   @0x2499f8 add lr, r4, r3
 *   @0x2499fc bne 0x249aec <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x120>
 *   @0x249a00 mov r0, r7
 *   @0x249a04 bl 0xb66c4 <atol@plt>
 *   @0x249a08 ldr r3, [r6, #0x4]
 *   @0x249a0c cmp r3, #0
 *   @0x249a10 mov r4, r0
 *   @0x249a14 beq 0x249c0c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x240>
 *   @0x249a18 add r0, r3, #16
 *   @0x249a1c ldr r0, [r0]
 *   @0x249a20 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x249a24 ldr r3, [r6, #0x4]
 *   @0x249a28 cmp r3, #0
 *   @0x249a2c beq 0x249c60 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x294>
 *   @0x249a30 add r0, r3, #16
 *   @0x249a34 ldr r0, [r0]
 *   @0x249a38 ldr r3, [r0, #0x4]
 *   @0x249a3c cmp r3, #0
 *   @0x249a40 beq 0x249c70 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x2a4>
 *   @0x249a44 add r4, r3, r4, lsl #4
 *   @0x249a48 ldr r2, [r4, #0xc]
 *   @0x249a4c bic r3, r2, #-16777216
 *   @0x249a50 cmp r3, #1
 *   @0x249a54 beq 0x249ba0 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x1d4>
 *   @0x249a58 cmp r3, #2
 *   @0x249a5c bne 0x249a84 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0xb8>
 *   @0x249a60 sub r3, r2, #1
 *   @0x249a64 bic r3, r3, #-16777216
 *   @0x249a68 bic r3, r3, #3
 *   @0x249a6c cmp r3, #0
 *   @0x249a70 beq 0x249c54 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x288>
 *   @0x249a74 mov r2, #0
 *   @0x249a78 mov r3, #5
 *   @0x249a7c str r2, [r4, #0x8]
 *   @0x249a80 str r3, [r4, #0xc]
 *   @0x249a84 ldr r3, [r5, #0xc]
 *   @0x249a88 mov r1, #0
 *   @0x249a8c ldr r2, [r5, #0x8]
 *   @0x249a90 str r1, [r4]
 *   @0x249a94 str r3, [r4, #0xc]
 *   @0x249a98 ldr r3, [r5, #0xc]
 *   @0x249a9c str r2, [r4, #0x8]
 *   @0x249aa0 bic r3, r3, #-16777216
 *   @0x249aa4 cmp r3, #14
 *   @0x249aa8 addls pc, pc, r3, lsl #2
 *   @0x249aac b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249ab0 b 0x249b28 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x15c>
 *   @0x249ab4 b 0x249b88 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x1bc>
 *   @0x249ab8 b 0x249b5c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x190>
 *   @0x249abc b 0x249b14 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x148>
 *   @0x249ac0 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249ac4 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249ac8 b 0x249b38 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x16c>
 *   @0x249acc b 0x249b14 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x148>
 *   @0x249ad0 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249ad4 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249ad8 b 0x249b28 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x15c>
 *   @0x249adc b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249ae0 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249ae4 b 0x249b28 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x15c>
 *   @0x249ae8 b 0x249b14 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x148>
 *   @0x249aec ldrb r3, [lr, #0x1]
 *   @0x249af0 and r3, r3, #4
 *   @0x249af4 ands r3, r3, #255
 *   @0x249af8 bne 0x2499f0 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x24>
 *   @0x249afc mov r0, r6
 *   @0x249b00 mov r1, r7
 *   @0x249b04 mov r2, r5
 *   @0x249b08 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x249b0c pop {r3, r4, r5, r6, r7, lr}
 *   @0x249b10 b 0xd3a34 <_Z15PopContextStackv>
 *   @0x249b14 ldr r3, [r5]
 *   @0x249b18 str r3, [r4]
 *   @0x249b1c bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x249b20 pop {r3, r4, r5, r6, r7, lr}
 *   @0x249b24 b 0xd3a34 <_Z15PopContextStackv>
 *   @0x249b28 ldm r5, {r2, r3}
 *   @0x249b2c stm r4, {r2, r3}
 *   @0x249b30 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x249b34 b 0x249b20 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x154>
 *   @0x249b38 ldr r3, [r5]
 *   @0x249b3c str r3, [r4]
 *   @0x249b40 ldr r3, [r5]
 *   @0x249b44 cmp r3, #0
 *   @0x249b48 beq 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249b4c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x249b50 ldr r1, [r5]
 *   @0x249b54 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x249b58 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249b5c ldr r3, [r5]
 *   @0x249b60 cmp r3, #0
 *   @0x249b64 str r3, [r4]
 *   @0x249b68 beq 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249b6c ldr r1, [r3, #0x8]
 *   @0x249b70 ldr r2, [r3]
 *   @0x249b74 cmp r1, #0
 *   @0x249b78 streq r4, [r3, #0x8]
 *   @0x249b7c add r2, r2, #1
 *   @0x249b80 str r2, [r3]
 *   @0x249b84 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150>
 *   @0x249b88 ldr r3, [r5]
 *   @0x249b8c cmp r3, #0
 *   @0x249b90 ldrne r2, [r3, #0x4]
 *   @0x249b94 addne r2, r2, #1
 *   @0x249b98 strne r2, [r3, #0x4]
 *   @0x249b9c b 0x249b18 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x14c>
 *   @0x249ba0 ldr r6, [r4]
 *   @0x249ba4 cmp r6, #0
 *   @0x249ba8 beq 0x249bc8 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x1fc>
 *   @0x249bac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x249bb0 ldr r7, [r6, #0x4]
 *   @0x249bb4 sub r7, r7, #1
 *   @0x249bb8 str r7, [r6, #0x4]
 *   @0x249bbc cmp r7, #0
 *   @0x249bc0 beq 0x249bd4 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x208>
 *   @0x249bc4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x249bc8 mov r3, #0
 *   @0x249bcc str r3, [r4]
 *   @0x249bd0 b 0x249a84 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0xb8>
 *   @0x249bd4 ldr r0, [r6]
 *   @0x249bd8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x249bdc str r7, [r6]
 *   @0x249be0 str r7, [r6, #0x8]
 *   @0x249be4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x249be8 ldr r7, [r6, #0x4]
 *   @0x249bec sub r7, r7, #1
 *   @0x249bf0 str r7, [r6, #0x4]
 *   @0x249bf4 cmp r7, #0
 *   @0x249bf8 beq 0x249c1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x250>
 *   @0x249bfc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x249c00 mov r0, r6
 *   @0x249c04 bl 0x27d1d0 <_ZdlPv>
 *   @0x249c08 b 0x249bc4 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x1f8>
 *   @0x249c0c mov r0, r6
 *   @0x249c10 mov r1, #1
 *   @0x249c14 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x249c18 b 0x249a1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x50>
 *   @0x249c1c ldr r0, [r6]
 *   @0x249c20 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x249c24 str r7, [r6]
 *   @0x249c28 str r7, [r6, #0x8]
 *   @0x249c2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x249c30 ldr r7, [r6, #0x4]
 *   @0x249c34 sub r7, r7, #1
 *   @0x249c38 str r7, [r6, #0x4]
 *   @0x249c3c cmp r7, #0
 *   @0x249c40 beq 0x249c80 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x2b4>
 *   @0x249c44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x249c48 mov r0, r6
 *   @0x249c4c bl 0x27d1d0 <_ZdlPv>
 *   @0x249c50 b 0x249bfc <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x230>
 *   @0x249c54 mov r0, r4
 *   @0x249c58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x249c5c b 0x249a74 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0xa8>
 *   @0x249c60 mov r0, r6
 *   @0x249c64 mov r1, #1
 *   @0x249c68 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x249c6c b 0x249a34 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x68>
 *   @0x249c70 mov r1, r4
 *   @0x249c74 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x249c78 mov r4, r0
 *   @0x249c7c b 0x249a48 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x7c>
 *   @0x249c80 ldr r0, [r6]
 *   @0x249c84 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x249c88 str r7, [r6]
 *   @0x249c8c str r7, [r6, #0x8]
 *   @0x249c90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x249c94 ldr r7, [r6, #0x4]
 *   @0x249c98 sub r7, r7, #1
 *   @0x249c9c str r7, [r6, #0x4]
 *   @0x249ca0 cmp r7, #0
 *   @0x249ca4 bne 0x249cc8 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x2fc>
 *   @0x249ca8 ldr r0, [r6]
 *   @0x249cac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x249cb0 mov r0, r6
 *   @0x249cb4 str r7, [r6]
 *   @0x249cb8 str r7, [r6, #0x8]
 *   @0x249cbc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x249cc0 mov r0, r6
 *   @0x249cc4 bl 0x27d1d0 <_ZdlPv>
 *   @0x249cc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x249ccc mov r0, r6
 *   @0x249cd0 bl 0x27d1d0 <_ZdlPv>
 *   @0x249cd4 b 0x249c44 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x278>
 *   @0x249cd8 mulseq r10, r8, pc
 *
 * ══ §8/42 UpdateTouchActions  0x1d7908  size 772  193 条（0x1d7908..0x1d7c0c）
 * @func 0x1d7908 0x1d7c0c  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / IO_Button_Down(int, int)×2 / GetRawMouseX(int)×2 / GetRawMouseY(int)×2 / CTouchAction::AddRecord(long long, int, int)×2 / MemoryManager::Free(void const*)×2 / operator delete(void*) / operator new(unsigned int)
 * 字段偏移 top8: 0x8×15 / 0x4×3 / 0xc×2 / 0x830×2 / 0x2e8×1 / 0x2c4×1 / 0x188×1 / 0x828×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d7908 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d790c mov r10, r0
 *   @0x1d7910 ldr r6, [pc, #0x2e8]
 *   @0x1d7914 sub sp, sp, #20
 *   @0x1d7918 mov r11, r1
 *   @0x1d791c ldr r6, [pc, r6]
 *   @0x1d7920 ldr r4, [r6]
 *   @0x1d7924 cmp r4, #0
 *   @0x1d7928 beq 0x1d7a78 <_Z18UpdateTouchActionsx+0x170>
 *   @0x1d792c ldr r3, [r4, #0x8]
 *   @0x1d7930 cmp r3, #0
 *   @0x1d7934 beq 0x1d7a78 <_Z18UpdateTouchActionsx+0x170>
 *   @0x1d7938 ldr r8, [pc, #0x2c4]
 *   @0x1d793c mov r7, #0
 *   @0x1d7940 mov r9, r7
 *   @0x1d7944 str r6, [sp, #0xc]
 *   @0x1d7948 add r8, pc, r8
 *   @0x1d794c b 0x1d799c <_Z18UpdateTouchActionsx+0x94>
 *   @0x1d7950 mov r0, #12
 *   @0x1d7954 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d7958 cmp r7, #0
 *   @0x1d795c movne r3, #0
 *   @0x1d7960 streq r7, [r0, #0x4]
 *   @0x1d7964 streq r7, [r0]
 *   @0x1d7968 moveq r7, r0
 *   @0x1d796c str r5, [r0, #0x8]
 *   @0x1d7970 moveq r9, r7
 *   @0x1d7974 strne r0, [r7]
 *   @0x1d7978 strne r7, [r0, #0x4]
 *   @0x1d797c movne r7, r0
 *   @0x1d7980 strne r3, [r0]
 *   @0x1d7984 ldr r4, [r4]
 *   @0x1d7988 cmp r4, #0
 *   @0x1d798c beq 0x1d7ba8 <_Z18UpdateTouchActionsx+0x2a0>
 *   @0x1d7990 ldr r3, [r4, #0x8]
 *   @0x1d7994 cmp r3, #0
 *   @0x1d7998 beq 0x1d7ba8 <_Z18UpdateTouchActionsx+0x2a0>
 *   @0x1d799c ldr r5, [r4, #0x8]
 *   @0x1d79a0 mov r0, #1
 *   @0x1d79a4 mov r1, r8
 *   @0x1d79a8 mov r2, #143
 *   @0x1d79ac mov r3, r0
 *   @0x1d79b0 ldrb r12, [r5, #0x830]
 *   @0x1d79b4 cmp r12, #0
 *   @0x1d79b8 bne 0x1d7950 <_Z18UpdateTouchActionsx+0x48>
 *   @0x1d79bc ldr r1, [r5]
 *   @0x1d79c0 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d79c4 cmp r0, #0
 *   @0x1d79c8 bne 0x1d79e0 <_Z18UpdateTouchActionsx+0xd8>
 *   @0x1d79cc mov r3, #1
 *   @0x1d79d0 strb r3, [r5, #0x830]
 *   @0x1d79d4 movw r3, #0x838
 *   @0x1d79d8 strd r10, r11, [r5, r3]
 *   @0x1d79dc b 0x1d7984 <_Z18UpdateTouchActionsx+0x7c>
 *   @0x1d79e0 ldr r0, [r5]
 *   @0x1d79e4 bl 0x159e8c <_Z12GetRawMouseXi>
 *   @0x1d79e8 mov r6, r0
 *   @0x1d79ec ldr r0, [r5]
 *   @0x1d79f0 bl 0x159eec <_Z12GetRawMouseYi>
 *   @0x1d79f4 str r6, [sp]
 *   @0x1d79f8 mov r2, r10
 *   @0x1d79fc mov r3, r11
 *   @0x1d7a00 str r0, [sp, #0x4]
 *   @0x1d7a04 mov r0, r5
 *   @0x1d7a08 bl 0x1d7764 <_ZN12CTouchAction9AddRecordExii>
 *   @0x1d7a0c b 0x1d7984 <_Z18UpdateTouchActionsx+0x7c>
 *   @0x1d7a10 ldm r4, {r2, r3}
 *   @0x1d7a14 cmp r3, #0
 *   @0x1d7a18 strne r2, [r3]
 *   @0x1d7a1c ldrne r2, [r4]
 *   @0x1d7a20 streq r2, [r6]
 *   @0x1d7a24 cmp r2, #0
 *   @0x1d7a28 streq r3, [r6, #0x4]
 *   @0x1d7a2c strne r3, [r2, #0x4]
 *   @0x1d7a30 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d7a34 mov r0, r4
 *   @0x1d7a38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d7a3c ldr r3, [r6, #0x8]
 *   @0x1d7a40 sub r3, r3, #1
 *   @0x1d7a44 str r3, [r6, #0x8]
 *   @0x1d7a48 ldr r5, [r5]
 *   @0x1d7a4c cmp r5, #0
 *   @0x1d7a50 beq 0x1d7a60 <_Z18UpdateTouchActionsx+0x158>
 *   @0x1d7a54 ldr r3, [r5, #0x8]
 *   @0x1d7a58 cmp r3, #0
 *   @0x1d7a5c bne 0x1d7bc4 <_Z18UpdateTouchActionsx+0x2bc>
 *   @0x1d7a60 mov r0, r9
 *   @0x1d7a64 ldr r4, [r0]
 *   @0x1d7a68 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d7a6c cmp r4, #0
 *   @0x1d7a70 mov r0, r4
 *   @0x1d7a74 bne 0x1d7a64 <_Z18UpdateTouchActionsx+0x15c>
 *   @0x1d7a78 ldr r7, [pc, #0x188]
 *   @0x1d7a7c mov r4, #0
 *   @0x1d7a80 mov r8, r4
 *   @0x1d7a84 add r7, pc, r7
 *   @0x1d7a88 mov r0, #1
 *   @0x1d7a8c mov r1, r4
 *   @0x1d7a90 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d7a94 cmp r0, #0
 *   @0x1d7a98 beq 0x1d7b8c <_Z18UpdateTouchActionsx+0x284>
 *   @0x1d7a9c ldr r3, [r6]
 *   @0x1d7aa0 cmp r3, #0
 *   @0x1d7aa4 beq 0x1d7acc <_Z18UpdateTouchActionsx+0x1c4>
 *   @0x1d7aa8 ldr r2, [r3, #0x8]
 *   @0x1d7aac cmp r2, #0
 *   @0x1d7ab0 beq 0x1d7acc <_Z18UpdateTouchActionsx+0x1c4>
 *   @0x1d7ab4 ldr r2, [r2]
 *   @0x1d7ab8 cmp r2, r4
 *   @0x1d7abc beq 0x1d7b8c <_Z18UpdateTouchActionsx+0x284>
 *   @0x1d7ac0 ldr r3, [r3]
 *   @0x1d7ac4 cmp r3, #0
 *   @0x1d7ac8 bne 0x1d7aa8 <_Z18UpdateTouchActionsx+0x1a0>
 *   @0x1d7acc mov r0, #2112
 *   @0x1d7ad0 bl 0x27c524 <_Znwj>
 *   @0x1d7ad4 mov r5, r0
 *   @0x1d7ad8 bl 0x1d76f4 <_ZN12CTouchActionC2Ev>
 *   @0x1d7adc str r4, [r5]
 *   @0x1d7ae0 mov r0, r4
 *   @0x1d7ae4 bl 0x159e8c <_Z12GetRawMouseXi>
 *   @0x1d7ae8 mov r9, r0
 *   @0x1d7aec mov r0, r4
 *   @0x1d7af0 bl 0x159eec <_Z12GetRawMouseYi>
 *   @0x1d7af4 mov r2, r10
 *   @0x1d7af8 mov r3, r11
 *   @0x1d7afc str r9, [sp]
 *   @0x1d7b00 str r0, [sp, #0x4]
 *   @0x1d7b04 mov r0, r5
 *   @0x1d7b08 bl 0x1d7764 <_ZN12CTouchAction9AddRecordExii>
 *   @0x1d7b0c ldr r3, [r5, #0x828]
 *   @0x1d7b10 ldr r2, [r5, #0x82c]
 *   @0x1d7b14 cmp r3, r2
 *   @0x1d7b18 beq 0x1d7ba0 <_Z18UpdateTouchActionsx+0x298>
 *   @0x1d7b1c add r3, r3, #63
 *   @0x1d7b20 and lr, r3, #63
 *   @0x1d7b24 add lr, r5, lr, lsl #5
 *   @0x1d7b28 add lr, lr, #40
 *   @0x1d7b2c ldm lr!, {r0, r1, r2, r3}
 *   @0x1d7b30 add r12, r5, #8
 *   @0x1d7b34 ldr r9, [r6, #0x8]
 *   @0x1d7b38 add r9, r9, #1
 *   @0x1d7b3c stm r12!, {r0, r1, r2, r3}
 *   @0x1d7b40 ldm lr, {r0, r1, r2, r3}
 *   @0x1d7b44 str r9, [r6, #0x8]
 *   @0x1d7b48 stm r12, {r0, r1, r2, r3}
 *   @0x1d7b4c mov r3, #1
 *   @0x1d7b50 mov r0, #12
 *   @0x1d7b54 mov r1, r7
 *   @0x1d7b58 mov r2, #143
 *   @0x1d7b5c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d7b60 ldr r3, [r6, #0x4]
 *   @0x1d7b64 cmp r3, #0
 *   @0x1d7b68 str r5, [r0, #0x8]
 *   @0x1d7b6c streq r0, [r6, #0x4]
 *   @0x1d7b70 strne r0, [r3]
 *   @0x1d7b74 streq r0, [r6]
 *   @0x1d7b78 strne r3, [r0, #0x4]
 *   @0x1d7b7c streq r3, [r0, #0x4]
 *   @0x1d7b80 strne r0, [r6, #0x4]
 *   @0x1d7b84 streq r3, [r0]
 *   @0x1d7b88 strne r8, [r0]
 *   @0x1d7b8c add r4, r4, #1
 *   @0x1d7b90 cmp r4, #10
 *   @0x1d7b94 bne 0x1d7a88 <_Z18UpdateTouchActionsx+0x180>
 *   @0x1d7b98 add sp, sp, #20
 *   @0x1d7b9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d7ba0 mov lr, #0
 *   @0x1d7ba4 b 0x1d7b2c <_Z18UpdateTouchActionsx+0x224>
 *   @0x1d7ba8 cmp r9, #0
 *   @0x1d7bac ldr r6, [sp, #0xc]
 *   @0x1d7bb0 beq 0x1d7a78 <_Z18UpdateTouchActionsx+0x170>
 *   @0x1d7bb4 ldr r3, [r9, #0x8]
 *   @0x1d7bb8 cmp r3, #0
 *   @0x1d7bbc beq 0x1d7a60 <_Z18UpdateTouchActionsx+0x158>
 *   @0x1d7bc0 mov r5, r9
 *   @0x1d7bc4 ldr r4, [r6]
 *   @0x1d7bc8 ldr r3, [r5, #0x8]
 *   @0x1d7bcc cmp r4, #0
 *   @0x1d7bd0 beq 0x1d7a48 <_Z18UpdateTouchActionsx+0x140>
 *   @0x1d7bd4 ldr r0, [r4, #0x8]
 *   @0x1d7bd8 cmp r0, r3
 *   @0x1d7bdc bne 0x1d7bf0 <_Z18UpdateTouchActionsx+0x2e8>
 *   @0x1d7be0 b 0x1d7a10 <_Z18UpdateTouchActionsx+0x108>
 *   @0x1d7be4 ldr r0, [r4, #0x8]
 *   @0x1d7be8 cmp r3, r0
 *   @0x1d7bec beq 0x1d7a10 <_Z18UpdateTouchActionsx+0x108>
 *   @0x1d7bf0 ldr r4, [r4]
 *   @0x1d7bf4 cmp r4, #0
 *   @0x1d7bf8 bne 0x1d7be4 <_Z18UpdateTouchActionsx+0x2dc>
 *   @0x1d7bfc b 0x1d7a48 <_Z18UpdateTouchActionsx+0x140>
 *   @0x1d7c00 eoreq r9, r1, r8, ror #5
 *   @0x1d7c04 andseq r5, r7, r8, ror #9
 *   @0x1d7c08 andseq r5, r7, r12, lsr #7
 *
 * ══ §9/42 ProcessGestureEvents  0x1d719c  size 768  192 条（0x1d719c..0x1d749c）
 * @func 0x1d719c 0x1d749c  size 768  192 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d71a8→0x544a9c, 0x1d71d4→0x536f20, 0x1d71d8→0x3f5250, 0x1d71dc→0x536f70, 0x1d7260→0x536f28, 0x1d7338→0x53ab70, 0x1d733c→0x542374
 * 调用序列: ConvertGestureEventToGMEvent(int, bool)×2 / ProcessGestureEvents()+0x164×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / ProcessGestureEvents()+0x174 / CObjectGM::HasEventRecursive(int, int) / ProcessGestureEvents()+0x2a8 / ProcessGestureEvents()+0x284
 * 字段偏移 top8: 0x8×9 / 0x4×8 / 0x18×5 / 0xc×4 / 0x2×4 / 0x1c×3 / 0x2a8×3 / 0x20×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d719c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d71a0 sub sp, sp, #44
 *   @0x1d71a4 ldr r10, [pc, #0x2d0]
 *   @0x1d71a8 ldr r3, [pc, #0x2d0]
 *   @0x1d71ac add r10, pc, r10
 *   @0x1d71b0 str r10, [sp, #0x1c]
 *   @0x1d71b4 ldr r3, [r10, r3]
 *   @0x1d71b8 ldr r3, [r3]
 *   @0x1d71bc cmp r3, #0
 *   @0x1d71c0 str r3, [sp, #0x18]
 *   @0x1d71c4 beq 0x1d7474 <_Z20ProcessGestureEventsv+0x2d8>
 *   @0x1d71c8 ldr r3, [r3, #0x8]
 *   @0x1d71cc cmp r3, #0
 *   @0x1d71d0 beq 0x1d7474 <_Z20ProcessGestureEventsv+0x2d8>
 *   @0x1d71d4 ldr r1, [pc, #0x2a8]
 *   @0x1d71d8 ldr r2, [pc, #0x2a8]
 *   @0x1d71dc ldr r3, [pc, #0x2a8]
 *   @0x1d71e0 ldr r1, [r10, r1]
 *   @0x1d71e4 str r1, [sp, #0x20]
 *   @0x1d71e8 ldr r2, [r10, r2]
 *   @0x1d71ec str r2, [sp, #0x24]
 *   @0x1d71f0 ldr r11, [r10, r3]
 *   @0x1d71f4 ldr r12, [sp, #0x18]
 *   @0x1d71f8 mov r1, #0
 *   @0x1d71fc ldr r6, [r12, #0x8]
 *   @0x1d7200 ldr r0, [r6]
 *   @0x1d7204 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d7208 ldr r3, [sp, #0x20]
 *   @0x1d720c ldr r1, [r6, #0xc]
 *   @0x1d7210 ldr r10, [sp, #0x20]
 *   @0x1d7214 ldrd r2, r3, [r3]
 *   @0x1d7218 ldr r12, [sp, #0x24]
 *   @0x1d721c strd r2, r3, [sp, #8]
 *   @0x1d7220 adds r2, r2, #1
 *   @0x1d7224 adc r3, r3, #0
 *   @0x1d7228 cmp r1, #0
 *   @0x1d722c mov r5, r0
 *   @0x1d7230 ldr r0, [r6, #0x4]
 *   @0x1d7234 strd r2, r3, [r10]
 *   @0x1d7238 str r0, [r12]
 *   @0x1d723c ble 0x1d7310 <_Z20ProcessGestureEventsv+0x174>
 *   @0x1d7240 mov r7, r11
 *   @0x1d7244 ldr r8, [sp, #0x1c]
 *   @0x1d7248 ldrd r10, r11, [sp, #8]
 *   @0x1d724c mov r4, #0
 *   @0x1d7250 ldr r3, [r6, #0x8]
 *   @0x1d7254 ldr r0, [r3, r4, lsl #2]
 *   @0x1d7258 cmp r0, #0
 *   @0x1d725c blt 0x1d7300 <_Z20ProcessGestureEventsv+0x164>
 *   @0x1d7260 ldr r3, [pc, #0x228]
 *   @0x1d7264 ldr r3, [r8, r3]
 *   @0x1d7268 ldr r2, [r3, #0x4]
 *   @0x1d726c ldr r3, [r3]
 *   @0x1d7270 and r2, r0, r2
 *   @0x1d7274 ldr r3, [r3, r2, lsl #3]
 *   @0x1d7278 cmp r3, #0
 *   @0x1d727c bne 0x1d7290 <_Z20ProcessGestureEventsv+0xf4>
 *   @0x1d7280 b 0x1d7300 <_Z20ProcessGestureEventsv+0x164>
 *   @0x1d7284 ldr r3, [r3, #0x4]
 *   @0x1d7288 cmp r3, #0
 *   @0x1d728c beq 0x1d7300 <_Z20ProcessGestureEventsv+0x164>
 *   @0x1d7290 ldr r2, [r3, #0x8]
 *   @0x1d7294 cmp r0, r2
 *   @0x1d7298 bne 0x1d7284 <_Z20ProcessGestureEventsv+0xe8>
 *   @0x1d729c ldr r9, [r3, #0xc]
 *   @0x1d72a0 cmp r9, #0
 *   @0x1d72a4 beq 0x1d7300 <_Z20ProcessGestureEventsv+0x164>
 *   @0x1d72a8 ldrb r2, [r9, #0x68]
 *   @0x1d72ac cmp r2, #0
 *   @0x1d72b0 bne 0x1d7300 <_Z20ProcessGestureEventsv+0x164>
 *   @0x1d72b4 ldrb r2, [r9, #0x69]
 *   @0x1d72b8 cmp r2, #0
 *   @0x1d72bc bne 0x1d7300 <_Z20ProcessGestureEventsv+0x164>
 *   @0x1d72c0 ldrd r2, r3, [r9, #112]
 *   @0x1d72c4 cmp r10, r2
 *   @0x1d72c8 sbcs r0, r11, r3
 *   @0x1d72cc blt 0x1d7300 <_Z20ProcessGestureEventsv+0x164>
 *   @0x1d72d0 ldr r0, [r9, #0x80]
 *   @0x1d72d4 mov r1, #13
 *   @0x1d72d8 mov r2, r5
 *   @0x1d72dc bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii>
 *   @0x1d72e0 cmp r0, #0
 *   @0x1d72e4 beq 0x1d72fc <_Z20ProcessGestureEventsv+0x160>
 *   @0x1d72e8 mov r0, r9
 *   @0x1d72ec mov r2, #13
 *   @0x1d72f0 mov r1, r9
 *   @0x1d72f4 mov r3, r5
 *   @0x1d72f8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d72fc ldr r1, [r6, #0xc]
 *   @0x1d7300 add r4, r4, #1
 *   @0x1d7304 cmp r1, r4
 *   @0x1d7308 bgt 0x1d7250 <_Z20ProcessGestureEventsv+0xb4>
 *   @0x1d730c mov r11, r7
 *   @0x1d7310 ldr r0, [r6]
 *   @0x1d7314 mov r1, #1
 *   @0x1d7318 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d731c add r9, r0, #3328
 *   @0x1d7320 mov r8, r0
 *   @0x1d7324 ldr r3, [r11, r9, lsl #2]
 *   @0x1d7328 cmp r3, #0
 *   @0x1d732c ble 0x1d7444 <_Z20ProcessGestureEventsv+0x2a8>
 *   @0x1d7330 ldr r12, [sp, #0x1c]
 *   @0x1d7334 mov r7, #0
 *   @0x1d7338 ldr r2, [pc, #0x154]
 *   @0x1d733c ldr r3, [pc, #0x154]
 *   @0x1d7340 ldr r10, [r12, r2]
 *   @0x1d7344 ldr r3, [r12, r3]
 *   @0x1d7348 add r10, r10, r9, lsl #3
 *   @0x1d734c str r3, [sp, #0x14]
 *   @0x1d7350 mov r3, r10
 *   @0x1d7354 mov r10, r11
 *   @0x1d7358 mov r11, r3
 *   @0x1d735c ldr r12, [sp, #0x14]
 *   @0x1d7360 ldr r1, [r11, #0x4]
 *   @0x1d7364 ldr r3, [r12]
 *   @0x1d7368 ldr r1, [r1, r7, lsl #2]
 *   @0x1d736c ldr r2, [r3, #0x4]
 *   @0x1d7370 ldr r3, [r3]
 *   @0x1d7374 and r2, r1, r2
 *   @0x1d7378 ldr r3, [r3, r2, lsl #3]
 *   @0x1d737c cmp r3, #0
 *   @0x1d7380 bne 0x1d7394 <_Z20ProcessGestureEventsv+0x1f8>
 *   @0x1d7384 b 0x1d7430 <_Z20ProcessGestureEventsv+0x294>
 *   @0x1d7388 ldr r3, [r3, #0x4]
 *   @0x1d738c cmp r3, #0
 *   @0x1d7390 beq 0x1d7430 <_Z20ProcessGestureEventsv+0x294>
 *   @0x1d7394 ldr r2, [r3, #0x8]
 *   @0x1d7398 cmp r1, r2
 *   @0x1d739c bne 0x1d7388 <_Z20ProcessGestureEventsv+0x1ec>
 *   @0x1d73a0 ldr r3, [r3, #0xc]
 *   @0x1d73a4 cmp r3, #0
 *   @0x1d73a8 beq 0x1d7430 <_Z20ProcessGestureEventsv+0x294>
 *   @0x1d73ac ldr r6, [r3, #0xc4]
 *   @0x1d73b0 cmp r6, #0
 *   @0x1d73b4 beq 0x1d7430 <_Z20ProcessGestureEventsv+0x294>
 *   @0x1d73b8 ldr r3, [r6, #0x8]
 *   @0x1d73bc cmp r3, #0
 *   @0x1d73c0 beq 0x1d7430 <_Z20ProcessGestureEventsv+0x294>
 *   @0x1d73c4 str r10, [sp, #0x10]
 *   @0x1d73c8 str r11, [sp, #0x4]
 *   @0x1d73cc b 0x1d73dc <_Z20ProcessGestureEventsv+0x240>
 *   @0x1d73d0 ldr r3, [r6, #0x8]
 *   @0x1d73d4 cmp r3, #0
 *   @0x1d73d8 beq 0x1d7428 <_Z20ProcessGestureEventsv+0x28c>
 *   @0x1d73dc ldr r0, [r6, #0x8]
 *   @0x1d73e0 ldr r6, [r6]
 *   @0x1d73e4 ldrb r3, [r0, #0x68]
 *   @0x1d73e8 cmp r3, #0
 *   @0x1d73ec bne 0x1d7420 <_Z20ProcessGestureEventsv+0x284>
 *   @0x1d73f0 ldrb r3, [r0, #0x69]
 *   @0x1d73f4 cmp r3, #0
 *   @0x1d73f8 bne 0x1d7420 <_Z20ProcessGestureEventsv+0x284>
 *   @0x1d73fc ldrd r4, r5, [r0, #112]
 *   @0x1d7400 mov r1, r0
 *   @0x1d7404 ldrd r10, r11, [sp, #8]
 *   @0x1d7408 mov r2, #13
 *   @0x1d740c mov r3, r8
 *   @0x1d7410 cmp r10, r4
 *   @0x1d7414 sbcs r11, r11, r5
 *   @0x1d7418 blt 0x1d7420 <_Z20ProcessGestureEventsv+0x284>
 *   @0x1d741c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d7420 cmp r6, #0
 *   @0x1d7424 bne 0x1d73d0 <_Z20ProcessGestureEventsv+0x234>
 *   @0x1d7428 ldr r10, [sp, #0x10]
 *   @0x1d742c ldr r11, [sp, #0x4]
 *   @0x1d7430 ldr r3, [r10, r9, lsl #2]
 *   @0x1d7434 add r7, r7, #1
 *   @0x1d7438 cmp r3, r7
 *   @0x1d743c bgt 0x1d735c <_Z20ProcessGestureEventsv+0x1c0>
 *   @0x1d7440 mov r11, r10
 *   @0x1d7444 ldr r10, [sp, #0x18]
 *   @0x1d7448 mvn r0, #0
 *   @0x1d744c ldr r12, [sp, #0x24]
 *   @0x1d7450 ldr r10, [r10]
 *   @0x1d7454 str r0, [r12]
 *   @0x1d7458 cmp r10, #0
 *   @0x1d745c str r10, [sp, #0x18]
 *   @0x1d7460 beq 0x1d7474 <_Z20ProcessGestureEventsv+0x2d8>
 *   @0x1d7464 ldr r12, [sp, #0x18]
 *   @0x1d7468 ldr r3, [r12, #0x8]
 *   @0x1d746c cmp r3, #0
 *   @0x1d7470 bne 0x1d71f4 <_Z20ProcessGestureEventsv+0x58>
 *   @0x1d7474 add sp, sp, #44
 *   @0x1d7478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d747c eoreq r10, r1, r4, lsr #21
 *   @0x1d7480 .word 0xffffefb0
 *   @0x1d7484 .word 0xffffdeb4
 *   @0x1d7488 .word 0xffffbce8
 *   @0x1d748c .word 0xffffdeb8
 *   @0x1d7490 .word 0xffffbff4
 *   @0x1d7494 .word 0xffffdebc
 *   @0x1d7498 .word 0xffffbfec
 *
 * ══ §10/42 JS_Global_abstractRelationalComparison  0x25a518  size 764  191 条（0x25a518..0x25a814）
 * @func 0x25a518 0x25a814  size 764  191 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToPrimitive(RValue&, RValue&, int)×4 / yyisinf(RValue&)×4 / 0xb6604×2 / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*)×2 / CCodepointIterator_UTF8::GetNext()×2 / F_JS_ToNumber(RValue&, RValue&)×2 / YYError(char const*, ...) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×4 / 0x1c×2 / 0x4×2 / 0x8×1 / 0x18×1 / 0x10×1 / 0x1c8×1 / 0x160×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25a518 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x25a51c cmp r3, #0
 *   @0x25a520 sub sp, sp, #68
 *   @0x25a524 mov r4, #0
 *   @0x25a528 mov r5, #0
 *   @0x25a52c mov r6, r0
 *   @0x25a530 mov r7, r2
 *   @0x25a534 mov r9, r1
 *   @0x25a538 mov r2, #0
 *   @0x25a53c strd r4, r5, [sp]
 *   @0x25a540 str r2, [r0, #0xc]
 *   @0x25a544 mvn r0, #-16777216
 *   @0x25a548 str r2, [sp, #0x8]
 *   @0x25a54c str r2, [sp, #0x18]
 *   @0x25a550 strd r4, r5, [sp, #16]
 *   @0x25a554 str r0, [sp, #0xc]
 *   @0x25a558 str r0, [sp, #0x1c]
 *   @0x25a55c beq 0x25a664 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x14c>
 *   @0x25a560 mov r0, sp
 *   @0x25a564 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i>
 *   @0x25a568 cmp r0, #1
 *   @0x25a56c beq 0x25a6a8 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x190>
 *   @0x25a570 cmp r0, #0
 *   @0x25a574 bne 0x25a688 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x170>
 *   @0x25a578 add r4, sp, #16
 *   @0x25a57c mov r2, r0
 *   @0x25a580 mov r1, r7
 *   @0x25a584 mov r0, r4
 *   @0x25a588 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i>
 *   @0x25a58c cmp r0, #1
 *   @0x25a590 beq 0x25a6a8 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x190>
 *   @0x25a594 cmp r0, #0
 *   @0x25a598 bne 0x25a688 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x170>
 *   @0x25a59c ldr r2, [sp, #0x1c]
 *   @0x25a5a0 ldr r3, [sp, #0xc]
 *   @0x25a5a4 bic r2, r2, #-16777216
 *   @0x25a5a8 bic r3, r3, #-16777216
 *   @0x25a5ac cmp r3, #1
 *   @0x25a5b0 cmpeq r2, #1
 *   @0x25a5b4 bne 0x25a6c0 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x1a8>
 *   @0x25a5b8 ldr r2, [sp]
 *   @0x25a5bc ldr r3, [sp, #0x10]
 *   @0x25a5c0 ldr r4, [r2]
 *   @0x25a5c4 ldr r8, [r3]
 *   @0x25a5c8 mov r0, r4
 *   @0x25a5cc mov r1, r8
 *   @0x25a5d0 bl 0xb6604 <strstr@plt>
 *   @0x25a5d4 cmp r4, r0
 *   @0x25a5d8 beq 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4>
 *   @0x25a5dc mov r0, r8
 *   @0x25a5e0 mov r1, r4
 *   @0x25a5e4 bl 0xb6604 <strstr@plt>
 *   @0x25a5e8 cmp r8, r0
 *   @0x25a5ec beq 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130>
 *   @0x25a5f0 add r5, sp, #32
 *   @0x25a5f4 add r7, sp, #48
 *   @0x25a5f8 mov r1, r4
 *   @0x25a5fc mov r0, r5
 *   @0x25a600 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x25a604 mov r1, r8
 *   @0x25a608 mov r0, r7
 *   @0x25a60c bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x25a610 b 0x25a61c <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x104>
 *   @0x25a614 cmp r4, r0
 *   @0x25a618 bne 0x25a7f0 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2d8>
 *   @0x25a61c mov r0, r5
 *   @0x25a620 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x25a624 mov r4, r0
 *   @0x25a628 mov r0, r7
 *   @0x25a62c bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x25a630 cmp r4, #0
 *   @0x25a634 cmpne r0, #0
 *   @0x25a638 bne 0x25a614 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0xfc>
 *   @0x25a63c ldr r0, [pc, #0x1c8]
 *   @0x25a640 add r0, pc, r0
 *   @0x25a644 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x25a648 mov r0, #0
 *   @0x25a64c str r0, [r6]
 *   @0x25a650 mov r3, r0
 *   @0x25a654 movt r3, #0x3ff0
 *   @0x25a658 str r3, [r6, #0x4]
 *   @0x25a65c add sp, sp, #68
 *   @0x25a660 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x25a664 add r4, sp, #16
 *   @0x25a668 mov r1, r7
 *   @0x25a66c mov r2, r3
 *   @0x25a670 mov r0, r4
 *   @0x25a674 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i>
 *   @0x25a678 cmp r0, #1
 *   @0x25a67c beq 0x25a6a8 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x190>
 *   @0x25a680 cmp r0, #0
 *   @0x25a684 beq 0x25a690 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x178>
 *   @0x25a688 add sp, sp, #68
 *   @0x25a68c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x25a690 mov r2, r0
 *   @0x25a694 mov r1, r9
 *   @0x25a698 mov r0, sp
 *   @0x25a69c bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i>
 *   @0x25a6a0 cmp r0, #1
 *   @0x25a6a4 bne 0x25a594 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x7c>
 *   @0x25a6a8 ldr r0, [pc, #0x160]
 *   @0x25a6ac add r0, pc, r0
 *   @0x25a6b0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25a6b4 mov r0, #1
 *   @0x25a6b8 add sp, sp, #68
 *   @0x25a6bc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x25a6c0 add r5, sp, #32
 *   @0x25a6c4 add r7, sp, #48
 *   @0x25a6c8 mov r1, sp
 *   @0x25a6cc mov r2, #0
 *   @0x25a6d0 mov r0, r5
 *   @0x25a6d4 mov r3, #0
 *   @0x25a6d8 strd r2, r3, [sp, #32]
 *   @0x25a6dc strd r2, r3, [sp, #48]
 *   @0x25a6e0 mov r2, #0
 *   @0x25a6e4 mvn r3, #-16777216
 *   @0x25a6e8 str r2, [sp, #0x28]
 *   @0x25a6ec str r2, [sp, #0x38]
 *   @0x25a6f0 str r3, [sp, #0x2c]
 *   @0x25a6f4 str r3, [sp, #0x3c]
 *   @0x25a6f8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25a6fc mov r1, r4
 *   @0x25a700 mov r0, r7
 *   @0x25a704 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25a708 vldr d7, [sp, #32]
 *   @0x25a70c vcmp.f64 d7, d7
 *   @0x25a710 vmrs APSR_nzcv, fpscr
 *   @0x25a714 bvs 0x25a7fc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2e4>
 *   @0x25a718 vldr d6, [sp, #48]
 *   @0x25a71c vcmp.f64 d6, d6
 *   @0x25a720 vmrs APSR_nzcv, fpscr
 *   @0x25a724 bvs 0x25a7fc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2e4>
 *   @0x25a728 vcmp.f64 d7, d6
 *   @0x25a72c vmrs APSR_nzcv, fpscr
 *   @0x25a730 beq 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4>
 *   @0x25a734 vcmp.f64 d7, #0
 *   @0x25a738 vmrs APSR_nzcv, fpscr
 *   @0x25a73c bne 0x25a74c <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x234>
 *   @0x25a740 vcmp.f64 d6, #0
 *   @0x25a744 vmrs APSR_nzcv, fpscr
 *   @0x25a748 beq 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4>
 *   @0x25a74c mov r0, r5
 *   @0x25a750 bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x25a754 cmp r0, #0
 *   @0x25a758 beq 0x25a76c <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x254>
 *   @0x25a75c vldr d7, [sp, #32]
 *   @0x25a760 vcmpe.f64 d7, #0
 *   @0x25a764 vmrs APSR_nzcv, fpscr
 *   @0x25a768 bgt 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4>
 *   @0x25a76c mov r0, r7
 *   @0x25a770 bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x25a774 cmp r0, #0
 *   @0x25a778 beq 0x25a78c <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x274>
 *   @0x25a77c vldr d7, [sp, #48]
 *   @0x25a780 vcmpe.f64 d7, #0
 *   @0x25a784 vmrs APSR_nzcv, fpscr
 *   @0x25a788 bgt 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130>
 *   @0x25a78c mov r0, r7
 *   @0x25a790 bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x25a794 cmp r0, #0
 *   @0x25a798 beq 0x25a7ac <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x294>
 *   @0x25a79c vldr d7, [sp, #48]
 *   @0x25a7a0 vcmpe.f64 d7, #0
 *   @0x25a7a4 vmrs APSR_nzcv, fpscr
 *   @0x25a7a8 bmi 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4>
 *   @0x25a7ac mov r0, r5
 *   @0x25a7b0 bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x25a7b4 vldr d7, [sp, #32]
 *   @0x25a7b8 cmp r0, #0
 *   @0x25a7bc beq 0x25a7cc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2b4>
 *   @0x25a7c0 vcmpe.f64 d7, #0
 *   @0x25a7c4 vmrs APSR_nzcv, fpscr
 *   @0x25a7c8 bmi 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130>
 *   @0x25a7cc vldr d6, [sp, #48]
 *   @0x25a7d0 vcmpe.f64 d7, d6
 *   @0x25a7d4 vmrs APSR_nzcv, fpscr
 *   @0x25a7d8 bmi 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130>
 *   @0x25a7dc mov r0, #0
 *   @0x25a7e0 str r0, [r6]
 *   @0x25a7e4 str r0, [r6, #0x4]
 *   @0x25a7e8 add sp, sp, #68
 *   @0x25a7ec pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x25a7f0 cmp r4, r0
 *   @0x25a7f4 blt 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130>
 *   @0x25a7f8 b 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4>
 *   @0x25a7fc mov r3, #5
 *   @0x25a800 mov r0, #0
 *   @0x25a804 str r3, [r6, #0xc]
 *   @0x25a808 b 0x25a688 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x170>
 *   @0x25a80c andeq r12, pc, r0, asr #15
 *   @0x25a810 andeq r12, pc, r4, lsl r7
 *
 * ══ §11/42 Get_Event_Name  0xf41fc  size 760  190 条（0xf41fc..0xf44f4）
 * @func 0xf41fc 0xf44f4  size 760  190 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65c8×7 / KeyToStr(int)×3 / Object_Name(int) / MouseToStr(int) / OtherToStr(int) / WebToStr(int)
 * 字段偏移 top8: 0x18c×2 / 0x11c×2 / 0xe4×2 / 0xc0×2 / 0x98×2 / 0x224×1 / 0x218×1 / 0x210×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf41fc push {r4, lr}
 *   @0xf4200 sub sp, sp, #8
 *   @0xf4204 cmp r0, #14
 *   @0xf4208 addls pc, pc, r0, lsl #2
 *   @0xf420c b 0xf443c <_Z14Get_Event_Nameii+0x240>
 *   @0xf4210 b 0xf425c <_Z14Get_Event_Nameii+0x60>
 *   @0xf4214 b 0xf4268 <_Z14Get_Event_Nameii+0x6c>
 *   @0xf4218 b 0xf4274 <_Z14Get_Event_Nameii+0x78>
 *   @0xf421c b 0xf42a0 <_Z14Get_Event_Nameii+0xa4>
 *   @0xf4220 b 0xf42cc <_Z14Get_Event_Nameii+0xd0>
 *   @0xf4224 b 0xf4300 <_Z14Get_Event_Nameii+0x104>
 *   @0xf4228 b 0xf4348 <_Z14Get_Event_Nameii+0x14c>
 *   @0xf422c b 0xf4384 <_Z14Get_Event_Nameii+0x188>
 *   @0xf4230 b 0xf43c8 <_Z14Get_Event_Nameii+0x1cc>
 *   @0xf4234 b 0xf43d4 <_Z14Get_Event_Nameii+0x1d8>
 *   @0xf4238 b 0xf4408 <_Z14Get_Event_Nameii+0x20c>
 *   @0xf423c b 0xf443c <_Z14Get_Event_Nameii+0x240>
 *   @0xf4240 b 0xf443c <_Z14Get_Event_Nameii+0x240>
 *   @0xf4244 b 0xf443c <_Z14Get_Event_Nameii+0x240>
 *   @0xf4248 b 0xf424c <_Z14Get_Event_Nameii+0x50>
 *   @0xf424c ldr r0, [pc, #0x224]
 *   @0xf4250 add r0, pc, r0
 *   @0xf4254 add sp, sp, #8
 *   @0xf4258 pop {r4, pc}
 *   @0xf425c ldr r0, [pc, #0x218]
 *   @0xf4260 add r0, pc, r0
 *   @0xf4264 b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf4268 ldr r0, [pc, #0x210]
 *   @0xf426c add r0, pc, r0
 *   @0xf4270 b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf4274 ldr r4, [pc, #0x208]
 *   @0xf4278 mov r3, r1
 *   @0xf427c ldr r2, [pc, #0x204]
 *   @0xf4280 mov r1, #512
 *   @0xf4284 add r4, pc, r4
 *   @0xf4288 add r4, r4, #64
 *   @0xf428c add r2, pc, r2
 *   @0xf4290 mov r0, r4
 *   @0xf4294 bl 0xb65c8 <snprintf@plt>
 *   @0xf4298 mov r0, r4
 *   @0xf429c b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf42a0 ldr r4, [pc, #0x1e4]
 *   @0xf42a4 mov r3, r1
 *   @0xf42a8 ldr r2, [pc, #0x1e0]
 *   @0xf42ac mov r1, #512
 *   @0xf42b0 add r4, pc, r4
 *   @0xf42b4 add r4, r4, #64
 *   @0xf42b8 add r2, pc, r2
 *   @0xf42bc mov r0, r4
 *   @0xf42c0 bl 0xb65c8 <snprintf@plt>
 *   @0xf42c4 mov r0, r4
 *   @0xf42c8 b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf42cc mov r0, r1
 *   @0xf42d0 ldr r4, [pc, #0x1bc]
 *   @0xf42d4 bl 0x19ed54 <_Z11Object_Namei>
 *   @0xf42d8 ldr r2, [pc, #0x1b8]
 *   @0xf42dc add r4, pc, r4
 *   @0xf42e0 mov r1, #512
 *   @0xf42e4 add r4, r4, #64
 *   @0xf42e8 add r2, pc, r2
 *   @0xf42ec mov r3, r0
 *   @0xf42f0 mov r0, r4
 *   @0xf42f4 bl 0xb65c8 <snprintf@plt>
 *   @0xf42f8 mov r0, r4
 *   @0xf42fc b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf4300 mov r0, r1
 *   @0xf4304 ldr r4, [pc, #0x190]
 *   @0xf4308 bl 0xf348c <_Z8KeyToStri>
 *   @0xf430c ldr r12, [pc, #0x18c]
 *   @0xf4310 ldr r2, [pc, #0x18c]
 *   @0xf4314 add r4, pc, r4
 *   @0xf4318 ldr r3, [pc, #0x188]
 *   @0xf431c add r12, pc, r12
 *   @0xf4320 add r4, r4, #64
 *   @0xf4324 add r2, pc, r2
 *   @0xf4328 add r3, pc, r3
 *   @0xf432c mov r1, #512
 *   @0xf4330 stm sp, {r0, r12}
 *   @0xf4334 mov r0, r4
 *   @0xf4338 bl 0xb65c8 <snprintf@plt>
 *   @0xf433c mov r0, r4
 *   @0xf4340 add sp, sp, #8
 *   @0xf4344 pop {r4, pc}
 *   @0xf4348 mov r0, r1
 *   @0xf434c ldr r4, [pc, #0x158]
 *   @0xf4350 bl 0xf38f0 <_Z10MouseToStri>
 *   @0xf4354 ldr r2, [pc, #0x154]
 *   @0xf4358 add r4, pc, r4
 *   @0xf435c ldr r3, [pc, #0x150]
 *   @0xf4360 add r4, r4, #64
 *   @0xf4364 mov r1, #512
 *   @0xf4368 add r2, pc, r2
 *   @0xf436c add r3, pc, r3
 *   @0xf4370 str r0, [sp]
 *   @0xf4374 mov r0, r4
 *   @0xf4378 bl 0xb65c8 <snprintf@plt>
 *   @0xf437c mov r0, r4
 *   @0xf4380 b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf4384 cmp r1, #59
 *   @0xf4388 mov r0, r1
 *   @0xf438c bgt 0xf4448 <_Z14Get_Event_Nameii+0x24c>
 *   @0xf4390 bl 0xf3cf4 <_Z10OtherToStri>
 *   @0xf4394 ldr r4, [pc, #0x11c]
 *   @0xf4398 ldr r2, [pc, #0x11c]
 *   @0xf439c mov r1, #512
 *   @0xf43a0 add r4, pc, r4
 *   @0xf43a4 ldr r3, [pc, #0x114]
 *   @0xf43a8 add r4, r4, #64
 *   @0xf43ac add r2, pc, r2
 *   @0xf43b0 add r3, pc, r3
 *   @0xf43b4 str r0, [sp]
 *   @0xf43b8 mov r0, r4
 *   @0xf43bc bl 0xb65c8 <snprintf@plt>
 *   @0xf43c0 mov r0, r4
 *   @0xf43c4 b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf43c8 ldr r0, [pc, #0xf4]
 *   @0xf43cc add r0, pc, r0
 *   @0xf43d0 b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf43d4 mov r0, r1
 *   @0xf43d8 ldr r4, [pc, #0xe8]
 *   @0xf43dc bl 0xf348c <_Z8KeyToStri>
 *   @0xf43e0 ldr r12, [pc, #0xe4]
 *   @0xf43e4 ldr r2, [pc, #0xe4]
 *   @0xf43e8 add r4, pc, r4
 *   @0xf43ec ldr r3, [pc, #0xe0]
 *   @0xf43f0 add r12, pc, r12
 *   @0xf43f4 mov r1, #512
 *   @0xf43f8 add r4, r4, #64
 *   @0xf43fc add r2, pc, r2
 *   @0xf4400 add r3, pc, r3
 *   @0xf4404 b 0xf4330 <_Z14Get_Event_Nameii+0x134>
 *   @0xf4408 mov r0, r1
 *   @0xf440c ldr r4, [pc, #0xc4]
 *   @0xf4410 bl 0xf348c <_Z8KeyToStri>
 *   @0xf4414 ldr r12, [pc, #0xc0]
 *   @0xf4418 ldr r2, [pc, #0xc0]
 *   @0xf441c add r4, pc, r4
 *   @0xf4420 ldr r3, [pc, #0xbc]
 *   @0xf4424 add r12, pc, r12
 *   @0xf4428 mov r1, #512
 *   @0xf442c add r4, r4, #64
 *   @0xf4430 add r2, pc, r2
 *   @0xf4434 add r3, pc, r3
 *   @0xf4438 b 0xf4330 <_Z14Get_Event_Nameii+0x134>
 *   @0xf443c ldr r0, [pc, #0xa4]
 *   @0xf4440 add r0, pc, r0
 *   @0xf4444 b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf4448 bl 0xf40bc <_Z8WebToStri>
 *   @0xf444c ldr r4, [pc, #0x98]
 *   @0xf4450 ldr r2, [pc, #0x98]
 *   @0xf4454 mov r1, #512
 *   @0xf4458 add r4, pc, r4
 *   @0xf445c add r4, r4, #64
 *   @0xf4460 add r2, pc, r2
 *   @0xf4464 mov r3, r0
 *   @0xf4468 mov r0, r4
 *   @0xf446c bl 0xb65c8 <snprintf@plt>
 *   @0xf4470 mov r0, r4
 *   @0xf4474 b 0xf4254 <_Z14Get_Event_Nameii+0x58>
 *   @0xf4478 eoreq r3, r4, r8, ror r5
 *   @0xf447c eoreq r3, r4, r8, ror r5
 *   @0xf4480 eoreq r3, r4, r12, ror r5
 *   @0xf4484 eorseq pc, r8, r4, lsl #3
 *   @0xf4488 eoreq r3, r4, r8, ror r5
 *   @0xf448c eorseq pc, r8, r8, asr r1
 *   @0xf4490 eoreq r3, r4, r8, ror #10
 *   @0xf4494 eorseq pc, r8, r12, lsr #2
 *   @0xf4498 eoreq r3, r4, r8, asr #10
 *   @0xf449c ldrshteq pc, [r8], -r4
 *   @0xf44a0 eoreq r3, r4, r0, asr #10
 *   @0xf44a4 eoreq r3, r4, r12, lsl r5
 *   @0xf44a8 eoreq r3, r4, r0, lsr #10
 *   @0xf44ac ldrhteq pc, [r8], -r0
 *   @0xf44b0 eoreq r0, r4, r12, ror #16
 *   @0xf44b4 .word 0x002434f8
 *   @0xf44b8 eorseq pc, r8, r8, rrx
 *   @0xf44bc eoreq r0, r4, r8, lsr #16
 *   @0xf44c0 eoreq r3, r4, r8, asr #9
 *   @0xf44c4 eoreq r3, r4, r12, lsr #8
 *   @0xf44c8 eorseq pc, r8, r0, lsr #32
 *   @0xf44cc eoreq r3, r4, r12, ror #8
 *   @0xf44d0 eoreq r3, r4, r4, asr #8
 *   @0xf44d4 mlaeq r4, r8, r4, r3
 *   @0xf44d8 eorseq lr, r8, r12, ror #31
 *   @0xf44dc eoreq r3, r4, r8, lsr r4
 *   @0xf44e0 eoreq r3, r4, r0, lsl r4
 *   @0xf44e4 eoreq r3, r4, r12, ror r4
 *   @0xf44e8 eoreq r3, r4, r8, ror r3
 *   @0xf44ec ldrhteq lr, [r8], -r0
 *   @0xf44f0 eoreq r3, r4, r8, lsr #8
 *
 * ══ §12/42 CIAPPurchase::SetFromJSON  0x18ab40  size 760  190 条（0x18ab40..0x18ae38）
 * @func 0x18ab40 0x18ae38  size 760  190 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66d0×9 / json_object_get_string×5 / YYFree(void const*)×5 / YYStrDup(char const*)×5 / json_object_get_int×3 / json_object_get_object / json_object_get_double
 * 字段偏移 top8: 0x8×15 / 0x4×4 / 0xc×4 / 0x2a4×3 / 0x10×2 / 0x20×1 / 0x2a0×1 / 0x29c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ab40 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18ab44 mov r7, r0
 *   @0x18ab48 sub sp, sp, #20
 *   @0x18ab4c mov r0, r1
 *   @0x18ab50 bl 0x27e8f4 <json_object_get_object>
 *   @0x18ab54 mvn r3, #0
 *   @0x18ab58 str r3, [sp, #0x8]
 *   @0x18ab5c ldr r4, [r0, #0x20]
 *   @0x18ab60 cmp r4, #0
 *   @0x18ab64 beq 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18ab68 ldr r8, [pc, #0x2a4]
 *   @0x18ab6c ldr r9, [pc, #0x2a4]
 *   @0x18ab70 ldr r10, [pc, #0x2a4]
 *   @0x18ab74 add r8, pc, r8
 *   @0x18ab78 ldr r11, [pc, #0x2a0]
 *   @0x18ab7c add r9, pc, r9
 *   @0x18ab80 ldr r3, [pc, #0x29c]
 *   @0x18ab84 add r10, pc, r10
 *   @0x18ab88 add r11, pc, r11
 *   @0x18ab8c add r3, pc, r3
 *   @0x18ab90 str r3, [sp, #0x4]
 *   @0x18ab94 ldr r3, [pc, #0x28c]
 *   @0x18ab98 add r3, pc, r3
 *   @0x18ab9c str r3, [sp, #0xc]
 *   @0x18aba0 ldm r4, {r5, r6}
 *   @0x18aba4 cmp r6, #0
 *   @0x18aba8 beq 0x18ac6c <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x12c>
 *   @0x18abac mov r0, r5
 *   @0x18abb0 mov r1, r8
 *   @0x18abb4 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18abb8 cmp r0, #0
 *   @0x18abbc beq 0x18ac84 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x144>
 *   @0x18abc0 mov r0, r5
 *   @0x18abc4 mov r1, r9
 *   @0x18abc8 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18abcc cmp r0, #0
 *   @0x18abd0 beq 0x18acbc <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x17c>
 *   @0x18abd4 mov r0, r5
 *   @0x18abd8 mov r1, r10
 *   @0x18abdc bl 0xb66d0 <strcasecmp@plt>
 *   @0x18abe0 cmp r0, #0
 *   @0x18abe4 beq 0x18acf4 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x1b4>
 *   @0x18abe8 mov r0, r5
 *   @0x18abec mov r1, r11
 *   @0x18abf0 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18abf4 cmp r0, #0
 *   @0x18abf8 beq 0x18ad10 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x1d0>
 *   @0x18abfc mov r0, r5
 *   @0x18ac00 ldr r1, [sp, #0x4]
 *   @0x18ac04 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18ac08 cmp r0, #0
 *   @0x18ac0c beq 0x18ad34 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x1f4>
 *   @0x18ac10 mov r0, r5
 *   @0x18ac14 ldr r1, [sp, #0xc]
 *   @0x18ac18 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18ac1c cmp r0, #0
 *   @0x18ac20 beq 0x18ad6c <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x22c>
 *   @0x18ac24 ldr r1, [pc, #0x200]
 *   @0x18ac28 mov r0, r5
 *   @0x18ac2c add r1, pc, r1
 *   @0x18ac30 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18ac34 cmp r0, #0
 *   @0x18ac38 beq 0x18ad88 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x248>
 *   @0x18ac3c ldr r1, [pc, #0x1ec]
 *   @0x18ac40 mov r0, r5
 *   @0x18ac44 add r1, pc, r1
 *   @0x18ac48 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18ac4c cmp r0, #0
 *   @0x18ac50 beq 0x18adc0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x280>
 *   @0x18ac54 ldr r1, [pc, #0x1d8]
 *   @0x18ac58 mov r0, r5
 *   @0x18ac5c add r1, pc, r1
 *   @0x18ac60 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18ac64 cmp r0, #0
 *   @0x18ac68 beq 0x18adf8 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x2b8>
 *   @0x18ac6c ldr r4, [r4, #0x8]
 *   @0x18ac70 cmp r4, #0
 *   @0x18ac74 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18ac78 ldr r0, [sp, #0x8]
 *   @0x18ac7c add sp, sp, #20
 *   @0x18ac80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18ac84 mov r0, r6
 *   @0x18ac88 bl 0x27ed58 <json_object_get_string>
 *   @0x18ac8c mov r5, r0
 *   @0x18ac90 ldr r0, [r7]
 *   @0x18ac94 cmp r0, #0
 *   @0x18ac98 beq 0x18aca0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x160>
 *   @0x18ac9c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18aca0 mov r0, r5
 *   @0x18aca4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18aca8 str r0, [r7]
 *   @0x18acac ldr r4, [r4, #0x8]
 *   @0x18acb0 cmp r4, #0
 *   @0x18acb4 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18acb8 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18acbc mov r0, r6
 *   @0x18acc0 bl 0x27ed58 <json_object_get_string>
 *   @0x18acc4 mov r5, r0
 *   @0x18acc8 ldr r0, [r7, #0x4]
 *   @0x18accc cmp r0, #0
 *   @0x18acd0 beq 0x18acd8 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x198>
 *   @0x18acd4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18acd8 mov r0, r5
 *   @0x18acdc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18ace0 str r0, [r7, #0x4]
 *   @0x18ace4 ldr r4, [r4, #0x8]
 *   @0x18ace8 cmp r4, #0
 *   @0x18acec bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18acf0 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18acf4 mov r0, r6
 *   @0x18acf8 bl 0x27eb28 <json_object_get_int>
 *   @0x18acfc ldr r4, [r4, #0x8]
 *   @0x18ad00 cmp r4, #0
 *   @0x18ad04 str r0, [r7, #0x1c]
 *   @0x18ad08 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18ad0c b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18ad10 mov r0, r6
 *   @0x18ad14 bl 0x27ebf0 <json_object_get_double>
 *   @0x18ad18 ldr r4, [r4, #0x8]
 *   @0x18ad1c cmp r4, #0
 *   @0x18ad20 vmov d7, r0, r1
 *   @0x18ad24 vcvt.s32.f64 s15, d7
 *   @0x18ad28 vstr s15, [r7, #24]
 *   @0x18ad2c bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18ad30 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18ad34 mov r0, r6
 *   @0x18ad38 bl 0x27ed58 <json_object_get_string>
 *   @0x18ad3c mov r5, r0
 *   @0x18ad40 ldr r0, [r7, #0xc]
 *   @0x18ad44 cmp r0, #0
 *   @0x18ad48 beq 0x18ad50 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x210>
 *   @0x18ad4c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18ad50 mov r0, r5
 *   @0x18ad54 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18ad58 str r0, [r7, #0xc]
 *   @0x18ad5c ldr r4, [r4, #0x8]
 *   @0x18ad60 cmp r4, #0
 *   @0x18ad64 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18ad68 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18ad6c mov r0, r6
 *   @0x18ad70 bl 0x27eb28 <json_object_get_int>
 *   @0x18ad74 ldr r4, [r4, #0x8]
 *   @0x18ad78 cmp r4, #0
 *   @0x18ad7c str r0, [r7, #0x14]
 *   @0x18ad80 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18ad84 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18ad88 mov r0, r6
 *   @0x18ad8c bl 0x27ed58 <json_object_get_string>
 *   @0x18ad90 mov r5, r0
 *   @0x18ad94 ldr r0, [r7, #0x10]
 *   @0x18ad98 cmp r0, #0
 *   @0x18ad9c beq 0x18ada4 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x264>
 *   @0x18ada0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18ada4 mov r0, r5
 *   @0x18ada8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18adac str r0, [r7, #0x10]
 *   @0x18adb0 ldr r4, [r4, #0x8]
 *   @0x18adb4 cmp r4, #0
 *   @0x18adb8 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18adbc b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18adc0 mov r0, r6
 *   @0x18adc4 bl 0x27ed58 <json_object_get_string>
 *   @0x18adc8 mov r5, r0
 *   @0x18adcc ldr r0, [r7, #0x8]
 *   @0x18add0 cmp r0, #0
 *   @0x18add4 beq 0x18addc <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x29c>
 *   @0x18add8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18addc mov r0, r5
 *   @0x18ade0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18ade4 str r0, [r7, #0x8]
 *   @0x18ade8 ldr r4, [r4, #0x8]
 *   @0x18adec cmp r4, #0
 *   @0x18adf0 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18adf4 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18adf8 mov r0, r6
 *   @0x18adfc bl 0x27eb28 <json_object_get_int>
 *   @0x18ae00 ldr r4, [r4, #0x8]
 *   @0x18ae04 cmp r4, #0
 *   @0x18ae08 str r0, [sp, #0x8]
 *   @0x18ae0c bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60>
 *   @0x18ae10 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138>
 *   @0x18ae14 ldrsheq r1, [r12], -r12
 *   @0x18ae18 ldrheq r11, [r11], -r4
 *   @0x18ae1c ldrsheq r1, [r12], -r4
 *   @0x18ae20 andseq r1, r12, r0, lsl #12
 *   @0x18ae24 andseq r1, r12, r12, lsl #12
 *   @0x18ae28 andseq r11, r11, r8, ror r6
 *   @0x18ae2c andseq r1, r12, r12, ror r5
 *   @0x18ae30 andseq r1, r12, r8, ror r5
 *   @0x18ae34 ldrsbeq r11, [r11], -r12
 *
 * ══ §13/42 Compute_Color  0x1a2a98  size 760  190 条（0x1a2a98..0x1a2d90）
 * @func 0x1a2a98 0x1a2d90  size 760  190 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MyRandom(float, float, int)×6 / Color_Merge(unsigned int, unsigned int, float)×4 / Compute_Color(RParticle&)+0xac×2 / Color_RGB(int, int, int) / Color_RGBToColor(TRGB&) / Color_HSV(int, int, int) / Color_HSVToColor(THSV&) / fYYRandom(double)
 * 字段偏移 top8: 0x2c×7 / 0x4×4 / 0x80×4 / 0x7c×4 / 0x78×2 / 0x90×2 / 0x8c×2 / 0x5×2
 * VFP 指令 87 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a2a98 ldr r3, [pc, #0x2ec]
 *   @0x1a2a9c ldr r2, [r0, #0x8]
 *   @0x1a2aa0 ldr r3, [pc, r3]
 *   @0x1a2aa4 ldr r1, [r0, #0x4]
 *   @0x1a2aa8 cmp r2, #0
 *   @0x1a2aac ldr r3, [r3, #0x4]
 *   @0x1a2ab0 push {r4, r5, r6, lr}
 *   @0x1a2ab4 vpush {d8}
 *   @0x1a2ab8 mov r4, r0
 *   @0x1a2abc sub sp, sp, #8
 *   @0x1a2ac0 ldr r5, [r3, r1, lsl #2]
 *   @0x1a2ac4 ble 0x1a2b44 <_Z13Compute_ColorR9RParticle+0xac>
 *   @0x1a2ac8 ldr r3, [r0, #0xc]
 *   @0x1a2acc cmp r3, #0
 *   @0x1a2ad0 ble 0x1a2b44 <_Z13Compute_ColorR9RParticle+0xac>
 *   @0x1a2ad4 ldr r1, [r5, #0x78]
 *   @0x1a2ad8 cmp r1, #1
 *   @0x1a2adc beq 0x1a2b80 <_Z13Compute_ColorR9RParticle+0xe8>
 *   @0x1a2ae0 cmp r1, #2
 *   @0x1a2ae4 bne 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0>
 *   @0x1a2ae8 vmov s13, r2
 *   @0x1a2aec vmov s12, r3
 *   @0x1a2af0 vcvt.f32.s32 s15, s13
 *   @0x1a2af4 vadd.f32 s15, s15, s15
 *   @0x1a2af8 vcvt.f32.s32 s14, s12
 *   @0x1a2afc vdiv.f32 s15, s15, s14
 *   @0x1a2b00 vmov.f32 s14, #2.000000e+00
 *   @0x1a2b04 vcmpe.f32 s15, s14
 *   @0x1a2b08 vmrs APSR_nzcv, fpscr
 *   @0x1a2b0c bgt 0x1a2d6c <_Z13Compute_ColorR9RParticle+0x2d4>
 *   @0x1a2b10 vmov.f32 s14, #1.000000e+00
 *   @0x1a2b14 vcmpe.f32 s15, s14
 *   @0x1a2b18 vmrs APSR_nzcv, fpscr
 *   @0x1a2b1c vsubpl.f32 s15, s15, s14
 *   @0x1a2b20 bmi 0x1a2d74 <_Z13Compute_ColorR9RParticle+0x2dc>
 *   @0x1a2b24 ldr r0, [r5, #0x80]
 *   @0x1a2b28 ldr r1, [r5, #0x84]
 *   @0x1a2b2c vmov r2, s15
 *   @0x1a2b30 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0x1a2b34 str r0, [r4, #0x2c]
 *   @0x1a2b38 add sp, sp, #8
 *   @0x1a2b3c vpop {d8}
 *   @0x1a2b40 pop {r4, r5, r6, pc}
 *   @0x1a2b44 ldr r3, [r5, #0x78]
 *   @0x1a2b48 cmp r3, #5
 *   @0x1a2b4c addls pc, pc, r3, lsl #2
 *   @0x1a2b50 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0>
 *   @0x1a2b54 b 0x1a2b6c <_Z13Compute_ColorR9RParticle+0xd4>
 *   @0x1a2b58 b 0x1a2b6c <_Z13Compute_ColorR9RParticle+0xd4>
 *   @0x1a2b5c b 0x1a2b6c <_Z13Compute_ColorR9RParticle+0xd4>
 *   @0x1a2b60 b 0x1a2bc4 <_Z13Compute_ColorR9RParticle+0x12c>
 *   @0x1a2b64 b 0x1a2c7c <_Z13Compute_ColorR9RParticle+0x1e4>
 *   @0x1a2b68 b 0x1a2d34 <_Z13Compute_ColorR9RParticle+0x29c>
 *   @0x1a2b6c ldr r3, [r5, #0x7c]
 *   @0x1a2b70 str r3, [r4, #0x2c]
 *   @0x1a2b74 add sp, sp, #8
 *   @0x1a2b78 vpop {d8}
 *   @0x1a2b7c pop {r4, r5, r6, pc}
 *   @0x1a2b80 vmov s13, r2
 *   @0x1a2b84 ldr r0, [r5, #0x7c]
 *   @0x1a2b88 vmov s12, r3
 *   @0x1a2b8c ldr r1, [r5, #0x80]
 *   @0x1a2b90 vcvt.f32.s32 s14, s13
 *   @0x1a2b94 vcvt.f32.s32 s15, s12
 *   @0x1a2b98 vdiv.f32 s14, s14, s15
 *   @0x1a2b9c vmov.f32 s15, #1.000000e+00
 *   @0x1a2ba0 vcmp.f32 s14, s15
 *   @0x1a2ba4 vmrs APSR_nzcv, fpscr
 *   @0x1a2ba8 vmovgt r2, s15
 *   @0x1a2bac vmovle r2, s14
 *   @0x1a2bb0 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0x1a2bb4 str r0, [r4, #0x2c]
 *   @0x1a2bb8 add sp, sp, #8
 *   @0x1a2bbc vpop {d8}
 *   @0x1a2bc0 pop {r4, r5, r6, pc}
 *   @0x1a2bc4 vldr s12, [r5, #124]
 *   @0x1a2bc8 vldr s13, [r5, #128]
 *   @0x1a2bcc vcvt.f32.u32 s12, s12
 *   @0x1a2bd0 mov r2, #0
 *   @0x1a2bd4 vcvt.f32.u32 s13, s13
 *   @0x1a2bd8 vmov r0, s12
 *   @0x1a2bdc vmov r1, s13
 *   @0x1a2be0 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2be4 vldr s14, [r5, #132]
 *   @0x1a2be8 vldr s15, [r5, #136]
 *   @0x1a2bec vcvt.f32.u32 s14, s14
 *   @0x1a2bf0 mov r2, #0
 *   @0x1a2bf4 vcvt.f32.u32 s15, s15
 *   @0x1a2bf8 vmov r1, s15
 *   @0x1a2bfc vmov s16, r0
 *   @0x1a2c00 vmov r0, s14
 *   @0x1a2c04 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2c08 ldr r1, [r5, #0x90]
 *   @0x1a2c0c mov r2, #0
 *   @0x1a2c10 vmov s13, r1
 *   @0x1a2c14 vcvt.f32.u32 s13, s13
 *   @0x1a2c18 vmov r1, s13
 *   @0x1a2c1c vmov s17, r0
 *   @0x1a2c20 ldr r0, [r5, #0x8c]
 *   @0x1a2c24 vmov s12, r0
 *   @0x1a2c28 vcvt.f32.u32 s12, s12
 *   @0x1a2c2c vmov r0, s12
 *   @0x1a2c30 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2c34 vcvt.s32.f32 s17, s17
 *   @0x1a2c38 vcvt.s32.f32 s16, s16
 *   @0x1a2c3c vmov r1, s17
 *   @0x1a2c40 vmov s14, r0
 *   @0x1a2c44 vmov r0, s16
 *   @0x1a2c48 vcvt.s32.f32 s14, s14
 *   @0x1a2c4c vmov r2, s14
 *   @0x1a2c50 bl 0x20f9ac <_Z9Color_RGBiii>
 *   @0x1a2c54 mov r3, r0
 *   @0x1a2c58 add r0, sp, #4
 *   @0x1a2c5c ubfx r2, r3, #0x8, #0x8
 *   @0x1a2c60 strb r3, [sp, #0x4]
 *   @0x1a2c64 strb r2, [sp, #0x5]
 *   @0x1a2c68 ubfx r3, r3, #0x10, #0x8
 *   @0x1a2c6c strb r3, [sp, #0x6]
 *   @0x1a2c70 bl 0x20fa2c <_Z16Color_RGBToColorR4TRGB>
 *   @0x1a2c74 str r0, [r4, #0x2c]
 *   @0x1a2c78 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0>
 *   @0x1a2c7c vldr s15, [r5, #124]
 *   @0x1a2c80 vldr s12, [r5, #128]
 *   @0x1a2c84 vcvt.f32.u32 s15, s15
 *   @0x1a2c88 mov r2, #0
 *   @0x1a2c8c vcvt.f32.u32 s12, s12
 *   @0x1a2c90 vmov r0, s15
 *   @0x1a2c94 vmov r1, s12
 *   @0x1a2c98 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2c9c vldr s13, [r5, #132]
 *   @0x1a2ca0 vldr s14, [r5, #136]
 *   @0x1a2ca4 vcvt.f32.u32 s13, s13
 *   @0x1a2ca8 mov r2, #0
 *   @0x1a2cac vcvt.f32.u32 s14, s14
 *   @0x1a2cb0 vmov r1, s14
 *   @0x1a2cb4 vmov s16, r0
 *   @0x1a2cb8 vmov r0, s13
 *   @0x1a2cbc bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2cc0 ldr r1, [r5, #0x90]
 *   @0x1a2cc4 mov r2, #0
 *   @0x1a2cc8 vmov s12, r1
 *   @0x1a2ccc vcvt.f32.u32 s12, s12
 *   @0x1a2cd0 vmov r1, s12
 *   @0x1a2cd4 vmov s17, r0
 *   @0x1a2cd8 ldr r0, [r5, #0x8c]
 *   @0x1a2cdc vmov s15, r0
 *   @0x1a2ce0 vcvt.f32.u32 s15, s15
 *   @0x1a2ce4 vmov r0, s15
 *   @0x1a2ce8 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2cec vcvt.s32.f32 s17, s17
 *   @0x1a2cf0 vcvt.s32.f32 s16, s16
 *   @0x1a2cf4 vmov r1, s17
 *   @0x1a2cf8 vmov s13, r0
 *   @0x1a2cfc vmov r0, s16
 *   @0x1a2d00 vcvt.s32.f32 s13, s13
 *   @0x1a2d04 vmov r2, s13
 *   @0x1a2d08 bl 0x20f9d8 <_Z9Color_HSViii>
 *   @0x1a2d0c mov r3, r0
 *   @0x1a2d10 add r0, sp, #4
 *   @0x1a2d14 ubfx r2, r3, #0x8, #0x8
 *   @0x1a2d18 strb r3, [sp, #0x4]
 *   @0x1a2d1c strb r2, [sp, #0x5]
 *   @0x1a2d20 ubfx r3, r3, #0x10, #0x8
 *   @0x1a2d24 strb r3, [sp, #0x6]
 *   @0x1a2d28 bl 0x20feac <_Z16Color_HSVToColorR4THSV>
 *   @0x1a2d2c str r0, [r4, #0x2c]
 *   @0x1a2d30 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0>
 *   @0x1a2d34 mov r0, #0
 *   @0x1a2d38 mov r1, #0
 *   @0x1a2d3c movt r1, #0x3ff0
 *   @0x1a2d40 ldr r6, [r5, #0x7c]
 *   @0x1a2d44 ldr r5, [r5, #0x80]
 *   @0x1a2d48 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2d4c vmov d6, r0, r1
 *   @0x1a2d50 mov r0, r6
 *   @0x1a2d54 mov r1, r5
 *   @0x1a2d58 vcvt.f32.f64 s15, d6
 *   @0x1a2d5c vmov r2, s15
 *   @0x1a2d60 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0x1a2d64 str r0, [r4, #0x2c]
 *   @0x1a2d68 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0>
 *   @0x1a2d6c vmov.f32 s15, #1.000000e+00
 *   @0x1a2d70 b 0x1a2b24 <_Z13Compute_ColorR9RParticle+0x8c>
 *   @0x1a2d74 ldr r0, [r5, #0x7c]
 *   @0x1a2d78 ldr r1, [r5, #0x80]
 *   @0x1a2d7c vmov r2, s15
 *   @0x1a2d80 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0x1a2d84 str r0, [r4, #0x2c]
 *   @0x1a2d88 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0>
 *   @0x1a2d8c eoreq sp, r4, r12, lsl #26
 *
 * ══ §14/42 AddConstant  0xedd00  size 756  189 条（0xedd00..0xedff4）
 * @func 0xedd00 0xedff4  size 756  189 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×5 / LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / operator delete(void*)×4 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / YYStrDup(char const*) / PushContextStack(YYObjectBase*) / GetContextStackTop()
 * 字段偏移 top8: 0x4×16 / 0x8×8 / 0xc×5 / 0x2×2 / 0x2d4×1 / 0x2d0×1 / 0x2c8×1 / 0x2c4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xedd00 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xedd04 mov r5, r1
 *   @0xedd08 ldr r4, [pc, #0x2d4]
 *   @0xedd0c mov r3, #74
 *   @0xedd10 ldr r7, [pc, #0x2d0]
 *   @0xedd14 mov r9, r0
 *   @0xedd18 ldr r4, [pc, r4]
 *   @0xedd1c ldr r8, [pc, #0x2c8]
 *   @0xedd20 ldr r7, [pc, r7]
 *   @0xedd24 ldr r6, [pc, #0x2c4]
 *   @0xedd28 ldr r1, [r4]
 *   @0xedd2c add r8, pc, r8
 *   @0xedd30 mov r0, r7
 *   @0xedd34 add r1, r1, #1
 *   @0xedd38 mov r2, r8
 *   @0xedd3c lsl r1, r1, #2
 *   @0xedd40 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xedd44 ldr r1, [r4]
 *   @0xedd48 ldr r6, [pc, r6]
 *   @0xedd4c mov r2, r8
 *   @0xedd50 add r1, r1, #1
 *   @0xedd54 mov r3, #75
 *   @0xedd58 mov r0, r6
 *   @0xedd5c lsl r1, r1, #4
 *   @0xedd60 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xedd64 ldr r3, [r4]
 *   @0xedd68 ldr r7, [r7]
 *   @0xedd6c add r8, r3, #1073741824
 *   @0xedd70 add r3, r3, #1
 *   @0xedd74 str r3, [r4]
 *   @0xedd78 ldr r0, [r7, r8, lsl #2]
 *   @0xedd7c cmp r0, #0
 *   @0xedd80 beq 0xedd88 <_Z11AddConstantPKcP6RValue+0x88>
 *   @0xedd84 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xedd88 mov r0, r9
 *   @0xedd8c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xedd90 str r0, [r7, r8, lsl #2]
 *   @0xedd94 mov r0, #0
 *   @0xedd98 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0xedd9c ldr r7, [r4]
 *   @0xedda0 ldr r6, [r6]
 *   @0xedda4 sub r7, r7, #-268435455
 *   @0xedda8 add r4, r6, r7, lsl #4
 *   @0xeddac ldr r2, [r4, #0xc]
 *   @0xeddb0 bic r3, r2, #-16777216
 *   @0xeddb4 cmp r3, #1
 *   @0xeddb8 beq 0xede74 <_Z11AddConstantPKcP6RValue+0x174>
 *   @0xeddbc cmp r3, #2
 *   @0xeddc0 bne 0xedde8 <_Z11AddConstantPKcP6RValue+0xe8>
 *   @0xeddc4 sub r2, r2, #1
 *   @0xeddc8 bic r2, r2, #-16777216
 *   @0xeddcc bic r2, r2, #3
 *   @0xeddd0 cmp r2, #0
 *   @0xeddd4 beq 0xedf48 <_Z11AddConstantPKcP6RValue+0x248>
 *   @0xeddd8 mov r2, #0
 *   @0xedddc mov r3, #5
 *   @0xedde0 str r2, [r4, #0x8]
 *   @0xedde4 str r3, [r4, #0xc]
 *   @0xedde8 ldr r3, [r5, #0xc]
 *   @0xeddec mov r1, #0
 *   @0xeddf0 ldr r2, [r5, #0x8]
 *   @0xeddf4 str r1, [r6, r7, lsl #4]
 *   @0xeddf8 str r3, [r4, #0xc]
 *   @0xeddfc ldr r3, [r5, #0xc]
 *   @0xede00 str r2, [r4, #0x8]
 *   @0xede04 bic r3, r3, #-16777216
 *   @0xede08 cmp r3, #14
 *   @0xede0c addls pc, pc, r3, lsl #2
 *   @0xede10 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xede14 b 0xede60 <_Z11AddConstantPKcP6RValue+0x160>
 *   @0xede18 b 0xedecc <_Z11AddConstantPKcP6RValue+0x1cc>
 *   @0xede1c b 0xedee4 <_Z11AddConstantPKcP6RValue+0x1e4>
 *   @0xede20 b 0xede50 <_Z11AddConstantPKcP6RValue+0x150>
 *   @0xede24 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xede28 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xede2c b 0xedea8 <_Z11AddConstantPKcP6RValue+0x1a8>
 *   @0xede30 b 0xede50 <_Z11AddConstantPKcP6RValue+0x150>
 *   @0xede34 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xede38 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xede3c b 0xede60 <_Z11AddConstantPKcP6RValue+0x160>
 *   @0xede40 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xede44 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xede48 b 0xede60 <_Z11AddConstantPKcP6RValue+0x160>
 *   @0xede4c b 0xede50 <_Z11AddConstantPKcP6RValue+0x150>
 *   @0xede50 ldr r3, [r5]
 *   @0xede54 str r3, [r6, r7, lsl #4]
 *   @0xede58 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xede5c b 0xd3a34 <_Z15PopContextStackv>
 *   @0xede60 ldm r5, {r2, r3}
 *   @0xede64 str r2, [r6, r7, lsl #4]
 *   @0xede68 str r3, [r4, #0x4]
 *   @0xede6c pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xede70 b 0xd3a34 <_Z15PopContextStackv>
 *   @0xede74 ldr r8, [r6, r7, lsl #4]
 *   @0xede78 cmp r8, #0
 *   @0xede7c beq 0xede9c <_Z11AddConstantPKcP6RValue+0x19c>
 *   @0xede80 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xede84 ldr r9, [r8, #0x4]
 *   @0xede88 sub r9, r9, #1
 *   @0xede8c str r9, [r8, #0x4]
 *   @0xede90 cmp r9, #0
 *   @0xede94 beq 0xedf10 <_Z11AddConstantPKcP6RValue+0x210>
 *   @0xede98 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xede9c mov r3, #0
 *   @0xedea0 str r3, [r6, r7, lsl #4]
 *   @0xedea4 b 0xedde8 <_Z11AddConstantPKcP6RValue+0xe8>
 *   @0xedea8 ldr r3, [r5]
 *   @0xedeac str r3, [r6, r7, lsl #4]
 *   @0xedeb0 ldr r3, [r5]
 *   @0xedeb4 cmp r3, #0
 *   @0xedeb8 beq 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xedebc bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xedec0 ldr r1, [r5]
 *   @0xedec4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xedec8 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xedecc ldr r3, [r5]
 *   @0xeded0 cmp r3, #0
 *   @0xeded4 ldrne r2, [r3, #0x4]
 *   @0xeded8 addne r2, r2, #1
 *   @0xededc strne r2, [r3, #0x4]
 *   @0xedee0 b 0xede54 <_Z11AddConstantPKcP6RValue+0x154>
 *   @0xedee4 ldr r3, [r5]
 *   @0xedee8 cmp r3, #0
 *   @0xedeec str r3, [r6, r7, lsl #4]
 *   @0xedef0 beq 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xedef4 ldr r1, [r3, #0x8]
 *   @0xedef8 ldr r2, [r3]
 *   @0xedefc cmp r1, #0
 *   @0xedf00 streq r4, [r3, #0x8]
 *   @0xedf04 add r2, r2, #1
 *   @0xedf08 str r2, [r3]
 *   @0xedf0c b 0xede58 <_Z11AddConstantPKcP6RValue+0x158>
 *   @0xedf10 ldr r0, [r8]
 *   @0xedf14 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xedf18 str r9, [r8]
 *   @0xedf1c str r9, [r8, #0x8]
 *   @0xedf20 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xedf24 ldr r9, [r8, #0x4]
 *   @0xedf28 sub r9, r9, #1
 *   @0xedf2c str r9, [r8, #0x4]
 *   @0xedf30 cmp r9, #0
 *   @0xedf34 beq 0xedf54 <_Z11AddConstantPKcP6RValue+0x254>
 *   @0xedf38 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xedf3c mov r0, r8
 *   @0xedf40 bl 0x27d1d0 <_ZdlPv>
 *   @0xedf44 b 0xede98 <_Z11AddConstantPKcP6RValue+0x198>
 *   @0xedf48 mov r0, r4
 *   @0xedf4c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xedf50 b 0xeddd8 <_Z11AddConstantPKcP6RValue+0xd8>
 *   @0xedf54 ldr r0, [r8]
 *   @0xedf58 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xedf5c str r9, [r8]
 *   @0xedf60 str r9, [r8, #0x8]
 *   @0xedf64 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xedf68 ldr r9, [r8, #0x4]
 *   @0xedf6c sub r9, r9, #1
 *   @0xedf70 str r9, [r8, #0x4]
 *   @0xedf74 cmp r9, #0
 *   @0xedf78 beq 0xedf8c <_Z11AddConstantPKcP6RValue+0x28c>
 *   @0xedf7c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xedf80 mov r0, r8
 *   @0xedf84 bl 0x27d1d0 <_ZdlPv>
 *   @0xedf88 b 0xedf38 <_Z11AddConstantPKcP6RValue+0x238>
 *   @0xedf8c ldr r0, [r8]
 *   @0xedf90 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xedf94 str r9, [r8]
 *   @0xedf98 str r9, [r8, #0x8]
 *   @0xedf9c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xedfa0 ldr r9, [r8, #0x4]
 *   @0xedfa4 sub r9, r9, #1
 *   @0xedfa8 str r9, [r8, #0x4]
 *   @0xedfac cmp r9, #0
 *   @0xedfb0 bne 0xedfd4 <_Z11AddConstantPKcP6RValue+0x2d4>
 *   @0xedfb4 ldr r0, [r8]
 *   @0xedfb8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xedfbc mov r0, r8
 *   @0xedfc0 str r9, [r8]
 *   @0xedfc4 str r9, [r8, #0x8]
 *   @0xedfc8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xedfcc mov r0, r8
 *   @0xedfd0 bl 0x27d1d0 <_ZdlPv>
 *   @0xedfd4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xedfd8 mov r0, r8
 *   @0xedfdc bl 0x27d1d0 <_ZdlPv>
 *   @0xedfe0 b 0xedf7c <_Z11AddConstantPKcP6RValue+0x27c>
 *   @0xedfe4 eorseq r0, r0, r12, lsr #1
 *   @0xedfe8 eorseq r0, r0, r8, lsr #1
 *   @0xedfec eoreq r7, r4, r8, asr r1
 *   @0xedff0 eorseq r0, r0, r4, lsl #1
 *
 * ══ §15/42 VirtualKeys_DeSerialise  0x18ca38  size 744  186 条（0x18ca38..0x18cd20）
 * @func 0x18ca38 0x18cd20  size 744  186 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×14 / VirtualKeys_DeSerialise(IBuffer*)+0x2d8
 * 字段偏移 top8: 0xc×15 / 0x288×1 / 0x264×1 / 0x2×1 / 0x4×1 / 0x8×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ca38 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18ca3c add r4, r0, #44
 *   @0x18ca40 ldr r3, [r0]
 *   @0x18ca44 mov r1, #6
 *   @0x18ca48 mov r2, r4
 *   @0x18ca4c mov r5, r0
 *   @0x18ca50 ldr r3, [r3, #0xc]
 *   @0x18ca54 blx r3
 *   @0x18ca58 mov r0, r4
 *   @0x18ca5c mov r1, #0
 *   @0x18ca60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18ca64 movw r3, #0x353
 *   @0x18ca68 cmp r0, r3
 *   @0x18ca6c beq 0x18ca78 <_Z23VirtualKeys_DeSerialiseP7IBuffer+0x40>
 *   @0x18ca70 mov r0, #0
 *   @0x18ca74 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18ca78 ldr r3, [r5]
 *   @0x18ca7c mov r1, #6
 *   @0x18ca80 mov r2, r4
 *   @0x18ca84 mov r0, r5
 *   @0x18ca88 ldr r11, [pc, #0x288]
 *   @0x18ca8c ldr r3, [r3, #0xc]
 *   @0x18ca90 blx r3
 *   @0x18ca94 mov r0, r4
 *   @0x18ca98 mov r1, #0
 *   @0x18ca9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18caa0 ldr r11, [pc, r11]
 *   @0x18caa4 cmp r0, #0
 *   @0x18caa8 str r0, [r11]
 *   @0x18caac ble 0x18cd10 <_Z23VirtualKeys_DeSerialiseP7IBuffer+0x2d8>
 *   @0x18cab0 ldr r7, [pc, #0x264]
 *   @0x18cab4 mov r6, #0
 *   @0x18cab8 mov r8, r6
 *   @0x18cabc ldr r7, [pc, r7]
 *   @0x18cac0 ldr r3, [r5]
 *   @0x18cac4 mov r2, r4
 *   @0x18cac8 mov r1, #4
 *   @0x18cacc mov r0, r5
 *   @0x18cad0 ldr r10, [r7]
 *   @0x18cad4 add r8, r8, #1
 *   @0x18cad8 ldr r3, [r3, #0xc]
 *   @0x18cadc blx r3
 *   @0x18cae0 mov r1, #0
 *   @0x18cae4 mov r0, r4
 *   @0x18cae8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18caec ldr r3, [r5]
 *   @0x18caf0 ldr r9, [r7]
 *   @0x18caf4 mov r2, r4
 *   @0x18caf8 mov r1, #4
 *   @0x18cafc ldr r3, [r3, #0xc]
 *   @0x18cb00 add r9, r9, r6
 *   @0x18cb04 strh r0, [r10, r6]
 *   @0x18cb08 mov r0, r5
 *   @0x18cb0c blx r3
 *   @0x18cb10 mov r1, #0
 *   @0x18cb14 mov r0, r4
 *   @0x18cb18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cb1c ldr r3, [r5]
 *   @0x18cb20 ldr r10, [r7]
 *   @0x18cb24 mov r2, r4
 *   @0x18cb28 mov r1, #6
 *   @0x18cb2c ldr r3, [r3, #0xc]
 *   @0x18cb30 add r10, r10, r6
 *   @0x18cb34 strh r0, [r9, #2]
 *   @0x18cb38 mov r0, r5
 *   @0x18cb3c blx r3
 *   @0x18cb40 mov r1, #0
 *   @0x18cb44 mov r0, r4
 *   @0x18cb48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cb4c ldr r3, [r5]
 *   @0x18cb50 mov r2, r4
 *   @0x18cb54 mov r1, #6
 *   @0x18cb58 ldr r9, [r7]
 *   @0x18cb5c ldr r3, [r3, #0xc]
 *   @0x18cb60 add r9, r9, r6
 *   @0x18cb64 str r0, [r10, #0x4]
 *   @0x18cb68 mov r0, r5
 *   @0x18cb6c blx r3
 *   @0x18cb70 mov r1, #0
 *   @0x18cb74 mov r0, r4
 *   @0x18cb78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cb7c ldr r3, [r5]
 *   @0x18cb80 mov r2, r4
 *   @0x18cb84 mov r1, #6
 *   @0x18cb88 ldr r10, [r7]
 *   @0x18cb8c ldr r3, [r3, #0xc]
 *   @0x18cb90 add r10, r10, r6
 *   @0x18cb94 str r0, [r9, #0x8]
 *   @0x18cb98 mov r0, r5
 *   @0x18cb9c blx r3
 *   @0x18cba0 mov r1, #0
 *   @0x18cba4 mov r0, r4
 *   @0x18cba8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cbac ldr r3, [r5]
 *   @0x18cbb0 mov r2, r4
 *   @0x18cbb4 mov r1, #6
 *   @0x18cbb8 ldr r9, [r7]
 *   @0x18cbbc ldr r3, [r3, #0xc]
 *   @0x18cbc0 add r9, r9, r6
 *   @0x18cbc4 str r0, [r10, #0xc]
 *   @0x18cbc8 mov r0, r5
 *   @0x18cbcc blx r3
 *   @0x18cbd0 mov r1, #0
 *   @0x18cbd4 mov r0, r4
 *   @0x18cbd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cbdc ldr r3, [r5]
 *   @0x18cbe0 mov r2, r4
 *   @0x18cbe4 mov r1, #6
 *   @0x18cbe8 ldr r10, [r7]
 *   @0x18cbec ldr r3, [r3, #0xc]
 *   @0x18cbf0 add r10, r10, r6
 *   @0x18cbf4 str r0, [r9, #0x10]
 *   @0x18cbf8 mov r0, r5
 *   @0x18cbfc blx r3
 *   @0x18cc00 mov r1, #0
 *   @0x18cc04 mov r0, r4
 *   @0x18cc08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cc0c ldr r3, [r5]
 *   @0x18cc10 mov r2, r4
 *   @0x18cc14 mov r1, #6
 *   @0x18cc18 ldr r9, [r7]
 *   @0x18cc1c ldr r3, [r3, #0xc]
 *   @0x18cc20 add r9, r9, r6
 *   @0x18cc24 str r0, [r10, #0x14]
 *   @0x18cc28 mov r0, r5
 *   @0x18cc2c blx r3
 *   @0x18cc30 mov r1, #0
 *   @0x18cc34 mov r0, r4
 *   @0x18cc38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cc3c ldr r3, [r5]
 *   @0x18cc40 mov r2, r4
 *   @0x18cc44 mov r1, #6
 *   @0x18cc48 ldr r10, [r7]
 *   @0x18cc4c ldr r3, [r3, #0xc]
 *   @0x18cc50 add r10, r10, r6
 *   @0x18cc54 str r0, [r9, #0x18]
 *   @0x18cc58 mov r0, r5
 *   @0x18cc5c blx r3
 *   @0x18cc60 mov r1, #0
 *   @0x18cc64 mov r0, r4
 *   @0x18cc68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cc6c ldr r3, [r5]
 *   @0x18cc70 mov r2, r4
 *   @0x18cc74 mov r1, #6
 *   @0x18cc78 ldr r9, [r7]
 *   @0x18cc7c ldr r3, [r3, #0xc]
 *   @0x18cc80 add r9, r9, r6
 *   @0x18cc84 str r0, [r10, #0x1c]
 *   @0x18cc88 mov r0, r5
 *   @0x18cc8c blx r3
 *   @0x18cc90 mov r1, #0
 *   @0x18cc94 mov r0, r4
 *   @0x18cc98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cc9c ldr r3, [r5]
 *   @0x18cca0 mov r2, r4
 *   @0x18cca4 mov r1, #6
 *   @0x18cca8 ldr r10, [r7]
 *   @0x18ccac ldr r3, [r3, #0xc]
 *   @0x18ccb0 add r10, r10, r6
 *   @0x18ccb4 str r0, [r9, #0x20]
 *   @0x18ccb8 mov r0, r5
 *   @0x18ccbc blx r3
 *   @0x18ccc0 mov r1, #0
 *   @0x18ccc4 mov r0, r4
 *   @0x18ccc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cccc ldr r3, [r5]
 *   @0x18ccd0 mov r1, #6
 *   @0x18ccd4 mov r2, r4
 *   @0x18ccd8 ldr r9, [r7]
 *   @0x18ccdc ldr r3, [r3, #0xc]
 *   @0x18cce0 add r9, r9, r6
 *   @0x18cce4 add r6, r6, #44
 *   @0x18cce8 str r0, [r10, #0x24]
 *   @0x18ccec mov r0, r5
 *   @0x18ccf0 blx r3
 *   @0x18ccf4 mov r0, r4
 *   @0x18ccf8 mov r1, #0
 *   @0x18ccfc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18cd00 ldr r3, [r11]
 *   @0x18cd04 cmp r3, r8
 *   @0x18cd08 str r0, [r9, #0x28]
 *   @0x18cd0c bgt 0x18cac0 <_Z23VirtualKeys_DeSerialiseP7IBuffer+0x88>
 *   @0x18cd10 mov r0, #1
 *   @0x18cd14 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18cd18 strhteq r3, [r6], -r0
 *   @0x18cd1c mlaeq r6, r8, r0, r3
 *
 * ══ §16/42 CCamera::DeSerialize  0x16e95c  size 736  184 条（0x16e95c..0x16ec3c）
 * @func 0x16e95c 0x16ec3c  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / DeSerializeMatrix(yyMatrix*, IBuffer*)×6 / YYGetInt32(RValue const*, int)×5 / YYGetBool(RValue const*, int)×2
 * 字段偏移 top8: 0xc×16 / 0x4×1 / 0x184×1 / 0x188×1 / 0x18c×1 / 0x190×1 / 0x194×1 / 0x198×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16e95c ldr r3, [r1]
 *   @0x16e960 push {r4, r5, r6, lr}
 *   @0x16e964 add r5, r1, #44
 *   @0x16e968 mov r4, r1
 *   @0x16e96c mov r6, r0
 *   @0x16e970 mov r2, r5
 *   @0x16e974 ldr r3, [r3, #0xc]
 *   @0x16e978 mov r0, r1
 *   @0x16e97c mov r1, #6
 *   @0x16e980 blx r3
 *   @0x16e984 mov r1, #0
 *   @0x16e988 mov r0, r5
 *   @0x16e98c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16e990 mov r3, r6
 *   @0x16e994 mov r1, r4
 *   @0x16e998 str r0, [r3], #4
 *   @0x16e99c mov r0, r3
 *   @0x16e9a0 bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e9a4 add r0, r6, #68
 *   @0x16e9a8 mov r1, r4
 *   @0x16e9ac bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e9b0 add r0, r6, #132
 *   @0x16e9b4 mov r1, r4
 *   @0x16e9b8 bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e9bc add r0, r6, #196
 *   @0x16e9c0 mov r1, r4
 *   @0x16e9c4 bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e9c8 add r0, r6, #260
 *   @0x16e9cc mov r1, r4
 *   @0x16e9d0 bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e9d4 add r0, r6, #324
 *   @0x16e9d8 mov r1, r4
 *   @0x16e9dc bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e9e0 ldr r3, [r4]
 *   @0x16e9e4 mov r2, r5
 *   @0x16e9e8 mov r1, #8
 *   @0x16e9ec mov r0, r4
 *   @0x16e9f0 ldr r3, [r3, #0xc]
 *   @0x16e9f4 blx r3
 *   @0x16e9f8 mov r1, #0
 *   @0x16e9fc mov r0, r5
 *   @0x16ea00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16ea04 ldr r3, [r4]
 *   @0x16ea08 mov r2, r5
 *   @0x16ea0c mov r1, #8
 *   @0x16ea10 ldr r3, [r3, #0xc]
 *   @0x16ea14 str r0, [r6, #0x184]
 *   @0x16ea18 mov r0, r4
 *   @0x16ea1c blx r3
 *   @0x16ea20 mov r1, #0
 *   @0x16ea24 mov r0, r5
 *   @0x16ea28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16ea2c ldr r3, [r4]
 *   @0x16ea30 mov r2, r5
 *   @0x16ea34 mov r1, #8
 *   @0x16ea38 ldr r3, [r3, #0xc]
 *   @0x16ea3c str r0, [r6, #0x188]
 *   @0x16ea40 mov r0, r4
 *   @0x16ea44 blx r3
 *   @0x16ea48 mov r1, #0
 *   @0x16ea4c mov r0, r5
 *   @0x16ea50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16ea54 ldr r3, [r4]
 *   @0x16ea58 mov r2, r5
 *   @0x16ea5c mov r1, #8
 *   @0x16ea60 ldr r3, [r3, #0xc]
 *   @0x16ea64 str r0, [r6, #0x18c]
 *   @0x16ea68 mov r0, r4
 *   @0x16ea6c blx r3
 *   @0x16ea70 mov r1, #0
 *   @0x16ea74 mov r0, r5
 *   @0x16ea78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16ea7c ldr r3, [r4]
 *   @0x16ea80 mov r2, r5
 *   @0x16ea84 mov r1, #8
 *   @0x16ea88 ldr r3, [r3, #0xc]
 *   @0x16ea8c str r0, [r6, #0x190]
 *   @0x16ea90 mov r0, r4
 *   @0x16ea94 blx r3
 *   @0x16ea98 mov r1, #0
 *   @0x16ea9c mov r0, r5
 *   @0x16eaa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16eaa4 ldr r3, [r4]
 *   @0x16eaa8 mov r2, r5
 *   @0x16eaac mov r1, #8
 *   @0x16eab0 ldr r3, [r3, #0xc]
 *   @0x16eab4 str r0, [r6, #0x194]
 *   @0x16eab8 mov r0, r4
 *   @0x16eabc blx r3
 *   @0x16eac0 mov r1, #0
 *   @0x16eac4 mov r0, r5
 *   @0x16eac8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16eacc ldr r3, [r4]
 *   @0x16ead0 mov r2, r5
 *   @0x16ead4 mov r1, #8
 *   @0x16ead8 ldr r3, [r3, #0xc]
 *   @0x16eadc str r0, [r6, #0x198]
 *   @0x16eae0 mov r0, r4
 *   @0x16eae4 blx r3
 *   @0x16eae8 mov r1, #0
 *   @0x16eaec mov r0, r5
 *   @0x16eaf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16eaf4 ldr r3, [r4]
 *   @0x16eaf8 mov r2, r5
 *   @0x16eafc mov r1, #8
 *   @0x16eb00 ldr r3, [r3, #0xc]
 *   @0x16eb04 str r0, [r6, #0x19c]
 *   @0x16eb08 mov r0, r4
 *   @0x16eb0c blx r3
 *   @0x16eb10 mov r1, #0
 *   @0x16eb14 mov r0, r5
 *   @0x16eb18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16eb1c ldr r3, [r4]
 *   @0x16eb20 mov r2, r5
 *   @0x16eb24 mov r1, #8
 *   @0x16eb28 ldr r3, [r3, #0xc]
 *   @0x16eb2c str r0, [r6, #0x1a0]
 *   @0x16eb30 mov r0, r4
 *   @0x16eb34 blx r3
 *   @0x16eb38 mov r1, #0
 *   @0x16eb3c mov r0, r5
 *   @0x16eb40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16eb44 ldr r3, [r4]
 *   @0x16eb48 mov r2, r5
 *   @0x16eb4c mov r1, #6
 *   @0x16eb50 ldr r3, [r3, #0xc]
 *   @0x16eb54 str r0, [r6, #0x1a4]
 *   @0x16eb58 mov r0, r4
 *   @0x16eb5c blx r3
 *   @0x16eb60 mov r1, #0
 *   @0x16eb64 mov r0, r5
 *   @0x16eb68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16eb6c ldr r3, [r4]
 *   @0x16eb70 mov r2, r5
 *   @0x16eb74 mov r1, #6
 *   @0x16eb78 ldr r3, [r3, #0xc]
 *   @0x16eb7c str r0, [r6, #0x1a8]
 *   @0x16eb80 mov r0, r4
 *   @0x16eb84 blx r3
 *   @0x16eb88 mov r1, #0
 *   @0x16eb8c mov r0, r5
 *   @0x16eb90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16eb94 ldr r3, [r4]
 *   @0x16eb98 mov r2, r5
 *   @0x16eb9c mov r1, #6
 *   @0x16eba0 ldr r3, [r3, #0xc]
 *   @0x16eba4 str r0, [r6, #0x1ac]
 *   @0x16eba8 mov r0, r4
 *   @0x16ebac blx r3
 *   @0x16ebb0 mov r1, #0
 *   @0x16ebb4 mov r0, r5
 *   @0x16ebb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16ebbc ldr r3, [r4]
 *   @0x16ebc0 mov r2, r5
 *   @0x16ebc4 mov r1, #6
 *   @0x16ebc8 ldr r3, [r3, #0xc]
 *   @0x16ebcc str r0, [r6, #0x1b0]
 *   @0x16ebd0 mov r0, r4
 *   @0x16ebd4 blx r3
 *   @0x16ebd8 mov r1, #0
 *   @0x16ebdc mov r0, r5
 *   @0x16ebe0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16ebe4 ldr r3, [r4]
 *   @0x16ebe8 mov r2, r5
 *   @0x16ebec mov r1, #6
 *   @0x16ebf0 ldr r3, [r3, #0xc]
 *   @0x16ebf4 str r0, [r6, #0x1b4]
 *   @0x16ebf8 mov r0, r4
 *   @0x16ebfc blx r3
 *   @0x16ec00 mov r1, #0
 *   @0x16ec04 mov r0, r5
 *   @0x16ec08 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x16ec0c ldr r3, [r4]
 *   @0x16ec10 mov r2, r5
 *   @0x16ec14 mov r1, #6
 *   @0x16ec18 ldr r3, [r3, #0xc]
 *   @0x16ec1c strb r0, [r6, #0x1b8]
 *   @0x16ec20 mov r0, r4
 *   @0x16ec24 blx r3
 *   @0x16ec28 mov r0, r5
 *   @0x16ec2c mov r1, #0
 *   @0x16ec30 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x16ec34 strb r0, [r6, #0x1b9]
 *   @0x16ec38 pop {r4, r5, r6, pc}
 *
 * ══ §17/42 b2ContactSolver::b2ContactSolver  0x2e2090  size 736  184 条（0x2e2090..0x2e2370）
 * @func 0x2e2090 0x2e2370  size 736  184 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2StackAllocator::Allocate(int)×2 / b2ContactSolver::b2ContactSolver(b2ContactSolverDef*)+0x2d0×2 / b2ContactSolver::b2ContactSolver(b2ContactSolverDef*)+0x238
 * 字段偏移 top8: 0x24×6 / 0x8×6 / 0x20×4 / 0x30×4 / 0xc×4 / 0x4×4 / 0x28×3 / 0x2c×3
 * VFP 指令 49 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e2090 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e2094 mov lr, r1
 *   @0x2e2098 mov r4, r0
 *   @0x2e209c mov r5, r1
 *   @0x2e20a0 mov r12, r0
 *   @0x2e20a4 ldr r7, [r5, #0x28]
 *   @0x2e20a8 ldm lr!, {r0, r1, r2, r3}
 *   @0x2e20ac mov r8, #88
 *   @0x2e20b0 ldr r6, [r5, #0x1c]
 *   @0x2e20b4 sub sp, sp, #20
 *   @0x2e20b8 stm r12!, {r0, r1, r2, r3}
 *   @0x2e20bc ldm lr, {r0, r1}
 *   @0x2e20c0 stm r12, {r0, r1}
 *   @0x2e20c4 mov r0, r7
 *   @0x2e20c8 mul r1, r8, r6
 *   @0x2e20cc str r7, [r4, #0x20]
 *   @0x2e20d0 str r6, [r4, #0x30]
 *   @0x2e20d4 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2e20d8 ldr r3, [r4, #0x30]
 *   @0x2e20dc mov r1, #156
 *   @0x2e20e0 mul r1, r1, r3
 *   @0x2e20e4 str r0, [r4, #0x24]
 *   @0x2e20e8 ldr r0, [r4, #0x20]
 *   @0x2e20ec bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2e20f0 ldr r2, [r4, #0x30]
 *   @0x2e20f4 ldr r1, [r5, #0x20]
 *   @0x2e20f8 ldr r3, [r5, #0x24]
 *   @0x2e20fc cmp r2, #0
 *   @0x2e2100 str r2, [sp, #0x8]
 *   @0x2e2104 ldr r2, [r5, #0x18]
 *   @0x2e2108 str r1, [r4, #0x18]
 *   @0x2e210c str r3, [r4, #0x1c]
 *   @0x2e2110 str r2, [r4, #0x2c]
 *   @0x2e2114 str r0, [r4, #0x28]
 *   @0x2e2118 ble 0x2e2360 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x2d0>
 *   @0x2e211c ldr r3, [r4, #0x24]
 *   @0x2e2120 vldr s15, [pc, #580]
 *   @0x2e2124 str r3, [sp, #0xc]
 *   @0x2e2128 mov r3, #0
 *   @0x2e212c str r3, [sp]
 *   @0x2e2130 mov r3, r0
 *   @0x2e2134 mov r0, #0
 *   @0x2e2138 str r0, [sp, #0x4]
 *   @0x2e213c mov r5, r0
 *   @0x2e2140 ldr r12, [r2, r5, lsl #2]
 *   @0x2e2144 vldr s14, [r12, #140]
 *   @0x2e2148 ldr r2, [sp, #0x4]
 *   @0x2e214c vldr s9, [r12, #136]
 *   @0x2e2150 ldr r0, [sp, #0xc]
 *   @0x2e2154 ldr r8, [r12, #0x30]
 *   @0x2e2158 add r3, r3, r2
 *   @0x2e215c ldr r10, [r12, #0x34]
 *   @0x2e2160 ldr r1, [sp]
 *   @0x2e2164 ldr r9, [r8, #0x8]
 *   @0x2e2168 vldr s12, [r9, #136]
 *   @0x2e216c add r2, r0, r1
 *   @0x2e2170 ldr r11, [r12, #0x90]
 *   @0x2e2174 ldr r1, [r10, #0x8]
 *   @0x2e2178 vldr s13, [r9, #144]
 *   @0x2e217c ldr r6, [r12, #0x7c]
 *   @0x2e2180 add r0, r9, #44
 *   @0x2e2184 ldr r8, [r8, #0xc]
 *   @0x2e2188 vldr s10, [r8, #8]
 *   @0x2e218c ldr r9, [r9, #0x8]
 *   @0x2e2190 add r7, r2, #48
 *   @0x2e2194 ldr r8, [r1, #0x8]
 *   @0x2e2198 cmp r6, #0
 *   @0x2e219c ldr r10, [r10, #0xc]
 *   @0x2e21a0 vldr s11, [r10, #8]
 *   @0x2e21a4 str r11, [r3, #0x90]
 *   @0x2e21a8 add r10, r1, #44
 *   @0x2e21ac ldr r11, [r1, #0x88]
 *   @0x2e21b0 vstr s14, [r3, #140]
 *   @0x2e21b4 str r9, [r3, #0x70]
 *   @0x2e21b8 vldr s14, [r1, #144]
 *   @0x2e21bc str r8, [r3, #0x74]
 *   @0x2e21c0 vstr s9, [r3, #136]
 *   @0x2e21c4 str r11, [r3, #0x7c]
 *   @0x2e21c8 vstr s12, [r3, #120]
 *   @0x2e21cc vstr s13, [r3, #128]
 *   @0x2e21d0 vstr s14, [r3, #132]
 *   @0x2e21d4 str r6, [r3, #0x94]
 *   @0x2e21d8 str r5, [r3, #0x98]
 *   @0x2e21dc vstr s15, [r3, #96]
 *   @0x2e21e0 ldm r0, {r0, r1}
 *   @0x2e21e4 vstr s15, [r3, #104]
 *   @0x2e21e8 vstr s15, [r3, #100]
 *   @0x2e21ec vstr s15, [r3, #108]
 *   @0x2e21f0 vstr s15, [r3, #80]
 *   @0x2e21f4 vstr s15, [r3, #88]
 *   @0x2e21f8 vstr s15, [r3, #84]
 *   @0x2e21fc vstr s15, [r3, #92]
 *   @0x2e2200 str r9, [r2, #0x20]
 *   @0x2e2204 vstr s12, [r2, #40]
 *   @0x2e2208 str r8, [r2, #0x24]
 *   @0x2e220c add r9, r12, #104
 *   @0x2e2210 str r11, [r2, #0x2c]
 *   @0x2e2214 add r8, r2, #16
 *   @0x2e2218 stm r7, {r0, r1}
 *   @0x2e221c add r7, r12, #112
 *   @0x2e2220 ldm r10, {r0, r1}
 *   @0x2e2224 add r10, r2, #56
 *   @0x2e2228 ldr r11, [r12, #0x78]
 *   @0x2e222c stm r10, {r0, r1}
 *   @0x2e2230 vstr s13, [r2, #64]
 *   @0x2e2234 ldm r9, {r0, r1}
 *   @0x2e2238 vstr s14, [r2, #68]
 *   @0x2e223c add r9, r2, #24
 *   @0x2e2240 stm r8, {r0, r1}
 *   @0x2e2244 ldm r7, {r0, r1}
 *   @0x2e2248 stm r9, {r0, r1}
 *   @0x2e224c vstr s10, [r2, #76]
 *   @0x2e2250 vstr s11, [r2, #80]
 *   @0x2e2254 str r6, [r2, #0x54]
 *   @0x2e2258 str r11, [r2, #0x48]
 *   @0x2e225c ble 0x2e22c8 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x238>
 *   @0x2e2260 ldrb r1, [r4, #0x14]
 *   @0x2e2264 add r8, r3, #8
 *   @0x2e2268 lsl r6, r6, #3
 *   @0x2e226c add r3, r3, #32
 *   @0x2e2270 cmp r1, #0
 *   @0x2e2274 mov r7, #0
 *   @0x2e2278 bne 0x2e22fc <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x26c>
 *   @0x2e227c vmov r0, s15
 *   @0x2e2280 add r1, r12, #64
 *   @0x2e2284 vstr s15, [r3, #-16]
 *   @0x2e2288 vstr s15, [r3, #-12]
 *   @0x2e228c vstr s15, [r3, #-32]
 *   @0x2e2290 vstr s15, [r3, #-28]
 *   @0x2e2294 add r9, r2, r7
 *   @0x2e2298 vstr s15, [r8]
 *   @0x2e229c vstr s15, [r8, #4]
 *   @0x2e22a0 add r7, r7, #8
 *   @0x2e22a4 vstr s15, [r3, #-8]
 *   @0x2e22a8 vstr s15, [r3, #-4]
 *   @0x2e22ac cmp r7, r6
 *   @0x2e22b0 add r8, r8, #36
 *   @0x2e22b4 add r12, r12, #20
 *   @0x2e22b8 str r0, [r3], #36
 *   @0x2e22bc ldm r1, {r0, r1}
 *   @0x2e22c0 stm r9, {r0, r1}
 *   @0x2e22c4 bne 0x2e227c <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x1ec>
 *   @0x2e22c8 ldr r2, [sp, #0x4]
 *   @0x2e22cc add r5, r5, #1
 *   @0x2e22d0 ldr r3, [sp, #0x8]
 *   @0x2e22d4 add r2, r2, #156
 *   @0x2e22d8 str r2, [sp, #0x4]
 *   @0x2e22dc cmp r3, r5
 *   @0x2e22e0 ldr r2, [sp]
 *   @0x2e22e4 add r2, r2, #88
 *   @0x2e22e8 str r2, [sp]
 *   @0x2e22ec ble 0x2e2360 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x2d0>
 *   @0x2e22f0 ldr r2, [r4, #0x2c]
 *   @0x2e22f4 ldr r3, [r4, #0x28]
 *   @0x2e22f8 b 0x2e2140 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0xb0>
 *   @0x2e22fc vldr s13, [r4, #8]
 *   @0x2e2300 vldr s14, [r12, #72]
 *   @0x2e2304 vmul.f32 s14, s13, s14
 *   @0x2e2308 add r1, r12, #64
 *   @0x2e230c vmov r0, s15
 *   @0x2e2310 add r9, r2, r7
 *   @0x2e2314 add r7, r7, #8
 *   @0x2e2318 add r12, r12, #20
 *   @0x2e231c cmp r7, r6
 *   @0x2e2320 add r8, r8, #36
 *   @0x2e2324 vstr s14, [r3, #-16]
 *   @0x2e2328 vldr s14, [r12, #56]
 *   @0x2e232c vmul.f32 s14, s13, s14
 *   @0x2e2330 vstr s15, [r3, #-32]
 *   @0x2e2334 vstr s15, [r3, #-28]
 *   @0x2e2338 vstr s14, [r3, #-12]
 *   @0x2e233c vstr s15, [r8, #-36]
 *   @0x2e2340 vstr s15, [r8, #-32]
 *   @0x2e2344 vstr s15, [r3, #-8]
 *   @0x2e2348 vstr s15, [r3, #-4]
 *   @0x2e234c str r0, [r3], #36
 *   @0x2e2350 ldm r1, {r0, r1}
 *   @0x2e2354 stm r9, {r0, r1}
 *   @0x2e2358 bne 0x2e22fc <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x26c>
 *   @0x2e235c b 0x2e22c8 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x238>
 *   @0x2e2360 mov r0, r4
 *   @0x2e2364 add sp, sp, #20
 *   @0x2e2368 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e236c andeq r0, r0, r0
 *
 * ══ §18/42 SetLightingUniforms  0x183d88  size 732  183 条（0x183d88..0x184064）
 * @func 0x183d88 0x184064  size 732  183 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x183d98→0x4a22d0, 0x183da4→0x4a2314, 0x183da8→0x3f26e0, 0x183dc4→0x4a22f4, 0x183e18→0x4a22d4, 0x183f5c→0x479ae0, 0x183f64→0x3f2760, 0x183f88→0x479ae0
 * 调用序列: SetLightingUniforms(GLSLShader*, int)+0x168 / SetLightingUniforms(GLSLShader*, int)+0x1c4
 * 字段偏移 top8: 0x4×8 / 0x10×6 / 0x8×6 / 0xc×5 / 0x-8×4 / 0x-4×4 / 0x-c×3 / 0x2a0×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183d88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x183d8c sub sp, sp, #540
 *   @0x183d90 ldr r8, [pc, #0x2ac]
 *   @0x183d94 mov r5, r1
 *   @0x183d98 ldr r4, [pc, #0x2a8]
 *   @0x183d9c add r9, sp, #280
 *   @0x183da0 add r8, pc, r8
 *   @0x183da4 ldr r2, [pc, #0x2a0]
 *   @0x183da8 ldr r12, [pc, #0x2a0]
 *   @0x183dac add r7, sp, #24
 *   @0x183db0 str r9, [sp, #0xc]
 *   @0x183db4 mov r3, #0
 *   @0x183db8 str r0, [sp, #0x10]
 *   @0x183dbc mov r11, #1
 *   @0x183dc0 ldr r4, [r8, r4]
 *   @0x183dc4 ldr r1, [pc, #0x288]
 *   @0x183dc8 ldr r6, [r8, r2]
 *   @0x183dcc mov r2, r3
 *   @0x183dd0 ldr r12, [r8, r12]
 *   @0x183dd4 ldr r1, [r8, r1]
 *   @0x183dd8 ldr r10, [r4]
 *   @0x183ddc add r12, r12, #12
 *   @0x183de0 str r5, [sp, #0x14]
 *   @0x183de4 add r4, r6, #8
 *   @0x183de8 str r3, [sp, #0x4]
 *   @0x183dec mov r5, r7
 *   @0x183df0 b 0x183e14 <_Z19SetLightingUniformsP10GLSLShaderi+0x8c>
 *   @0x183df4 cmp r9, #1
 *   @0x183df8 beq 0x184020 <_Z19SetLightingUniformsP10GLSLShaderi+0x298>
 *   @0x183dfc add r3, r3, #1
 *   @0x183e00 add r4, r4, #16
 *   @0x183e04 cmp r3, #8
 *   @0x183e08 add r1, r1, #4
 *   @0x183e0c add r12, r12, #16
 *   @0x183e10 beq 0x183e90 <_Z19SetLightingUniformsP10GLSLShaderi+0x108>
 *   @0x183e14 ands r0, r10, r11, lsl r3
 *   @0x183e18 ldr r6, [pc, #0x238]
 *   @0x183e1c beq 0x183dfc <_Z19SetLightingUniformsP10GLSLShaderi+0x74>
 *   @0x183e20 ldr r6, [r8, r6]
 *   @0x183e24 add r9, sp, #280
 *   @0x183e28 str r6, [sp, #0x8]
 *   @0x183e2c lsl r6, r2, #4
 *   @0x183e30 ldr r0, [sp, #0x8]
 *   @0x183e34 add r7, r5, r6
 *   @0x183e38 add r6, r9, r6
 *   @0x183e3c ldr r9, [r0, r3, lsl #2]
 *   @0x183e40 cmp r9, #0
 *   @0x183e44 addeq r2, r2, #1
 *   @0x183e48 bne 0x183df4 <_Z19SetLightingUniformsP10GLSLShaderi+0x6c>
 *   @0x183e4c ldr r9, [r4, #-0x8]
 *   @0x183e50 str r9, [r7]
 *   @0x183e54 ldr r9, [r4, #-0x4]
 *   @0x183e58 str r9, [r7, #0x4]
 *   @0x183e5c ldr r9, [r4]
 *   @0x183e60 str r9, [r7, #0x8]
 *   @0x183e64 ldr r9, [r1]
 *   @0x183e68 str r9, [r7, #0xc]
 *   @0x183e6c ldr r9, [r12, #-0xc]
 *   @0x183e70 ldr r7, [r12, #-0x8]
 *   @0x183e74 str r9, [r6]
 *   @0x183e78 str r7, [r6, #0x4]
 *   @0x183e7c ldr r9, [r12, #-0x4]
 *   @0x183e80 ldr r7, [r12]
 *   @0x183e84 str r9, [r6, #0x8]
 *   @0x183e88 str r7, [r6, #0xc]
 *   @0x183e8c b 0x183dfc <_Z19SetLightingUniformsP10GLSLShaderi+0x74>
 *   @0x183e90 ldr r5, [sp, #0x14]
 *   @0x183e94 ldr r0, [sp, #0x4]
 *   @0x183e98 cmp r5, r2
 *   @0x183e9c ble 0x183ef0 <_Z19SetLightingUniformsP10GLSLShaderi+0x168>
 *   @0x183ea0 lsl r3, r2, #4
 *   @0x183ea4 add r12, sp, #280
 *   @0x183ea8 add r1, sp, #24
 *   @0x183eac mov r4, #1065353216
 *   @0x183eb0 add r1, r1, r3
 *   @0x183eb4 add r3, r12, r3
 *   @0x183eb8 mov r12, #0
 *   @0x183ebc add r2, r2, #1
 *   @0x183ec0 str r12, [r1]
 *   @0x183ec4 cmp r2, r5
 *   @0x183ec8 str r4, [r1, #0x4]
 *   @0x183ecc str r12, [r1, #0x8]
 *   @0x183ed0 add r3, r3, #16
 *   @0x183ed4 str r4, [r1, #0xc]
 *   @0x183ed8 add r1, r1, #16
 *   @0x183edc str r12, [r3, #-0x10]
 *   @0x183ee0 str r12, [r3, #-0xc]
 *   @0x183ee4 str r12, [r3, #-0x8]
 *   @0x183ee8 str r12, [r3, #-0x4]
 *   @0x183eec bne 0x183ebc <_Z19SetLightingUniformsP10GLSLShaderi+0x134>
 *   @0x183ef0 cmp r5, r0
 *   @0x183ef4 ble 0x183f4c <_Z19SetLightingUniformsP10GLSLShaderi+0x1c4>
 *   @0x183ef8 lsl r3, r0, #4
 *   @0x183efc add r1, sp, #280
 *   @0x183f00 add r3, r3, #128
 *   @0x183f04 add r2, sp, #24
 *   @0x183f08 add r2, r2, r3
 *   @0x183f0c mov r12, #1065353216
 *   @0x183f10 add r3, r1, r3
 *   @0x183f14 mov r1, #0
 *   @0x183f18 add r0, r0, #1
 *   @0x183f1c str r1, [r2]
 *   @0x183f20 cmp r0, r5
 *   @0x183f24 str r12, [r2, #0x4]
 *   @0x183f28 str r1, [r2, #0x8]
 *   @0x183f2c add r3, r3, #16
 *   @0x183f30 str r12, [r2, #0xc]
 *   @0x183f34 add r2, r2, #16
 *   @0x183f38 str r1, [r3, #-0x10]
 *   @0x183f3c str r1, [r3, #-0xc]
 *   @0x183f40 str r1, [r3, #-0x8]
 *   @0x183f44 str r1, [r3, #-0x4]
 *   @0x183f48 bne 0x183f18 <_Z19SetLightingUniformsP10GLSLShaderi+0x190>
 *   @0x183f4c ldr r12, [sp, #0x10]
 *   @0x183f50 ldr r0, [r12, #0x64]
 *   @0x183f54 cmn r0, #1
 *   @0x183f58 beq 0x183f78 <_Z19SetLightingUniformsP10GLSLShaderi+0x1f0>
 *   @0x183f5c ldr r3, [pc, #0xf8]
 *   @0x183f60 mov r1, #1
 *   @0x183f64 ldr r2, [pc, #0xf4]
 *   @0x183f68 ldr r3, [r8, r3]
 *   @0x183f6c ldr r2, [r8, r2]
 *   @0x183f70 ldr r3, [r3]
 *   @0x183f74 blx r3
 *   @0x183f78 ldr r3, [sp, #0x10]
 *   @0x183f7c ldr r0, [r3, #0x68]
 *   @0x183f80 cmn r0, #1
 *   @0x183f84 beq 0x183fa0 <_Z19SetLightingUniformsP10GLSLShaderi+0x218>
 *   @0x183f88 ldr r3, [pc, #0xcc]
 *   @0x183f8c mov r1, r5
 *   @0x183f90 add r2, sp, #24
 *   @0x183f94 ldr r3, [r8, r3]
 *   @0x183f98 ldr r3, [r3]
 *   @0x183f9c blx r3
 *   @0x183fa0 ldr r7, [sp, #0x10]
 *   @0x183fa4 ldr r0, [r7, #0x6c]
 *   @0x183fa8 cmn r0, #1
 *   @0x183fac beq 0x183fc8 <_Z19SetLightingUniformsP10GLSLShaderi+0x240>
 *   @0x183fb0 ldr r3, [pc, #0xa4]
 *   @0x183fb4 mov r1, r5
 *   @0x183fb8 add r2, sp, #280
 *   @0x183fbc ldr r3, [r8, r3]
 *   @0x183fc0 ldr r3, [r3]
 *   @0x183fc4 blx r3
 *   @0x183fc8 ldr r9, [sp, #0x10]
 *   @0x183fcc ldr r0, [r9, #0x70]
 *   @0x183fd0 cmn r0, #1
 *   @0x183fd4 beq 0x183ff0 <_Z19SetLightingUniformsP10GLSLShaderi+0x268>
 *   @0x183fd8 ldr r3, [pc, #0x7c]
 *   @0x183fdc mov r1, r5
 *   @0x183fe0 add r2, sp, #152
 *   @0x183fe4 ldr r3, [r8, r3]
 *   @0x183fe8 ldr r3, [r3]
 *   @0x183fec blx r3
 *   @0x183ff0 ldr r12, [sp, #0x10]
 *   @0x183ff4 ldr r0, [r12, #0x74]
 *   @0x183ff8 cmn r0, #1
 *   @0x183ffc beq 0x184018 <_Z19SetLightingUniformsP10GLSLShaderi+0x290>
 *   @0x184000 ldr r3, [pc, #0x54]
 *   @0x184004 mov r1, r5
 *   @0x184008 add r2, sp, #408
 *   @0x18400c ldr r3, [r8, r3]
 *   @0x184010 ldr r3, [r3]
 *   @0x184014 blx r3
 *   @0x184018 add sp, sp, #540
 *   @0x18401c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x184020 ldr r7, [sp, #0x4]
 *   @0x184024 add r9, sp, #280
 *   @0x184028 lsl r6, r7, #4
 *   @0x18402c add r7, r7, #1
 *   @0x184030 add r6, r6, #128
 *   @0x184034 str r7, [sp, #0x4]
 *   @0x184038 add r7, r5, r6
 *   @0x18403c add r6, r9, r6
 *   @0x184040 b 0x183e4c <_Z19SetLightingUniformsP10GLSLShaderi+0xc4>
 *   @0x184044 .word 0x0026deb0
 *   @0x184048 .word 0xffffe85c
 *   @0x18404c .word 0xffffe854
 *   @0x184050 .word 0xffffe850
 *   @0x184054 .word 0xffffe84c
 *   @0x184058 .word 0xffffe858
 *   @0x18405c .word 0xffffbbd0
 *   @0x184060 .word 0xffffe844
 *
 * ══ §19/42 HandleTimeLine  0x1d00b4  size 728  182 条（0x1d00b4..0x1d038c）
 * @func 0x1d00b4 0x1d038c  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimeLine::FindLarger(double)×5 / HandleTimeLine()+0x134×4 / CTimeLine::GetCount()×4 / Perform_Event_TimeLine(CInstance*, CInstance*, int, int)×3 / CTimeLine::GetStep(int)×3 / TimeLine_Data(int) / HandleTimeLine()+0x22c / CTimeLine::FindSmaller(double)
 * 字段偏移 top8: 0x15d×3 / 0x2c0×2 / 0x80×1 / 0x68×1 / 0x178×1 / 0x69×1 / 0x15c×1 / 0x14c×1
 * VFP 指令 59 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d00b4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d00b8 vpush {d8, d9}
 *   @0x1d00bc ldr r3, [pc, #0x2c0]
 *   @0x1d00c0 ldr r1, [pc, #0x2c0]
 *   @0x1d00c4 ldr r3, [pc, r3]
 *   @0x1d00c8 ldr r1, [pc, r1]
 *   @0x1d00cc ldr r3, [r3]
 *   @0x1d00d0 ldrd r4, r5, [r1]
 *   @0x1d00d4 ldr r6, [r3, #0x80]
 *   @0x1d00d8 adds r2, r4, #1
 *   @0x1d00dc adc r3, r5, #0
 *   @0x1d00e0 strd r2, r3, [r1]
 *   @0x1d00e4 cmp r6, #0
 *   @0x1d00e8 beq 0x1d01f4 <_Z14HandleTimeLinev+0x140>
 *   @0x1d00ec vldr s17, [pc, #652]
 *   @0x1d00f0 ldrb r3, [r6, #0x68]
 *   @0x1d00f4 ldr r7, [r6, #0x178]
 *   @0x1d00f8 cmp r3, #0
 *   @0x1d00fc bne 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d0100 ldrb r3, [r6, #0x69]
 *   @0x1d0104 cmp r3, #0
 *   @0x1d0108 bne 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d010c ldrd r2, r3, [r6, #112]
 *   @0x1d0110 cmp r4, r2
 *   @0x1d0114 sbcs r1, r5, r3
 *   @0x1d0118 blt 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d011c ldrb r3, [r6, #0x15c]
 *   @0x1d0120 cmp r3, #0
 *   @0x1d0124 beq 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d0128 ldr r9, [r6, #0x14c]
 *   @0x1d012c cmp r9, #0
 *   @0x1d0130 blt 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d0134 mov r0, r9
 *   @0x1d0138 bl 0x1f2c48 <_Z13TimeLine_Datai>
 *   @0x1d013c subs r10, r0, #0
 *   @0x1d0140 beq 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d0144 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv>
 *   @0x1d0148 cmp r0, #0
 *   @0x1d014c ble 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d0150 vldr s15, [r6, #344]
 *   @0x1d0154 vcmp.f32 s15, #0
 *   @0x1d0158 vmrs APSR_nzcv, fpscr
 *   @0x1d015c beq 0x1d01fc <_Z14HandleTimeLinev+0x148>
 *   @0x1d0160 vcmpe.f32 s15, #0
 *   @0x1d0164 vldr s16, [r6, #340]
 *   @0x1d0168 mov r0, r10
 *   @0x1d016c vcvt.f64.f32 d7, s16
 *   @0x1d0170 vmrs APSR_nzcv, fpscr
 *   @0x1d0174 vmov r2, r3, d7
 *   @0x1d0178 ble 0x1d02e0 <_Z14HandleTimeLinev+0x22c>
 *   @0x1d017c bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd>
 *   @0x1d0180 vldr s18, [r6, #344]
 *   @0x1d0184 vadd.f32 s18, s16, s18
 *   @0x1d0188 vcvt.f64.f32 d6, s18
 *   @0x1d018c vmov r2, r3, d6
 *   @0x1d0190 mov r8, r0
 *   @0x1d0194 mov r0, r10
 *   @0x1d0198 bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd>
 *   @0x1d019c cmp r8, r0
 *   @0x1d01a0 mov r11, r0
 *   @0x1d01a4 bge 0x1d01c8 <_Z14HandleTimeLinev+0x114>
 *   @0x1d01a8 mov r3, r8
 *   @0x1d01ac mov r0, r6
 *   @0x1d01b0 mov r1, r6
 *   @0x1d01b4 mov r2, r9
 *   @0x1d01b8 add r8, r8, #1
 *   @0x1d01bc bl 0xf30ec <_Z22Perform_Event_TimeLineP9CInstanceS0_ii>
 *   @0x1d01c0 cmp r8, r11
 *   @0x1d01c4 bne 0x1d01a8 <_Z14HandleTimeLinev+0xf4>
 *   @0x1d01c8 vldr s15, [r6, #340]
 *   @0x1d01cc vcmp.f32 s16, s15
 *   @0x1d01d0 ldrb r3, [r6, #0x15d]
 *   @0x1d01d4 vstr s16, [r6, #336]
 *   @0x1d01d8 vmrs APSR_nzcv, fpscr
 *   @0x1d01dc vstreq s18, [r6, #340]
 *   @0x1d01e0 cmp r3, #0
 *   @0x1d01e4 bne 0x1d02ac <_Z14HandleTimeLinev+0x1f8>
 *   @0x1d01e8 cmp r7, #0
 *   @0x1d01ec movne r6, r7
 *   @0x1d01f0 bne 0x1d00f0 <_Z14HandleTimeLinev+0x3c>
 *   @0x1d01f4 vpop {d8, d9}
 *   @0x1d01f8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d01fc vldr s15, [r6, #336]
 *   @0x1d0200 vcvt.f64.f32 d6, s15
 *   @0x1d0204 mov r0, r10
 *   @0x1d0208 vmov r2, r3, d6
 *   @0x1d020c bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd>
 *   @0x1d0210 vldr s16, [r6, #340]
 *   @0x1d0214 vldr s18, [r6, #344]
 *   @0x1d0218 vadd.f32 s18, s16, s18
 *   @0x1d021c vcvt.f64.f32 d7, s18
 *   @0x1d0220 vmov r2, r3, d7
 *   @0x1d0224 mov r8, r0
 *   @0x1d0228 mov r0, r10
 *   @0x1d022c bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd>
 *   @0x1d0230 cmp r8, r0
 *   @0x1d0234 mov r11, r0
 *   @0x1d0238 bge 0x1d025c <_Z14HandleTimeLinev+0x1a8>
 *   @0x1d023c mov r3, r8
 *   @0x1d0240 mov r0, r6
 *   @0x1d0244 mov r1, r6
 *   @0x1d0248 mov r2, r9
 *   @0x1d024c add r8, r8, #1
 *   @0x1d0250 bl 0xf30ec <_Z22Perform_Event_TimeLineP9CInstanceS0_ii>
 *   @0x1d0254 cmp r8, r11
 *   @0x1d0258 bne 0x1d023c <_Z14HandleTimeLinev+0x188>
 *   @0x1d025c vldr s15, [r6, #340]
 *   @0x1d0260 vcmp.f32 s16, s15
 *   @0x1d0264 ldrb r3, [r6, #0x15d]
 *   @0x1d0268 vstr s16, [r6, #336]
 *   @0x1d026c vmrs APSR_nzcv, fpscr
 *   @0x1d0270 vstreq s18, [r6, #340]
 *   @0x1d0274 cmp r3, #0
 *   @0x1d0278 beq 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d027c mov r0, r10
 *   @0x1d0280 vldr s16, [r6, #340]
 *   @0x1d0284 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv>
 *   @0x1d0288 sub r1, r0, #1
 *   @0x1d028c mov r0, r10
 *   @0x1d0290 bl 0x1f1738 <_ZN9CTimeLine7GetStepEi>
 *   @0x1d0294 vmov s12, r0
 *   @0x1d0298 vcvt.f32.s32 s15, s12
 *   @0x1d029c vcmpe.f32 s16, s15
 *   @0x1d02a0 vmrs APSR_nzcv, fpscr
 *   @0x1d02a4 bgt 0x1d02d8 <_Z14HandleTimeLinev+0x224>
 *   @0x1d02a8 b 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d02ac mov r0, r10
 *   @0x1d02b0 vldr s16, [r6, #340]
 *   @0x1d02b4 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv>
 *   @0x1d02b8 sub r1, r0, #1
 *   @0x1d02bc mov r0, r10
 *   @0x1d02c0 bl 0x1f1738 <_ZN9CTimeLine7GetStepEi>
 *   @0x1d02c4 vmov s13, r0
 *   @0x1d02c8 vcvt.f32.s32 s15, s13
 *   @0x1d02cc vcmpe.f32 s16, s15
 *   @0x1d02d0 vmrs APSR_nzcv, fpscr
 *   @0x1d02d4 ble 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d02d8 vstr s17, [r6, #340]
 *   @0x1d02dc b 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d02e0 bl 0x1f1d04 <_ZN9CTimeLine11FindSmallerEd>
 *   @0x1d02e4 vldr s18, [r6, #344]
 *   @0x1d02e8 vadd.f32 s18, s16, s18
 *   @0x1d02ec vcvt.f64.f32 d6, s18
 *   @0x1d02f0 vmov r2, r3, d6
 *   @0x1d02f4 mov r8, r0
 *   @0x1d02f8 mov r0, r10
 *   @0x1d02fc bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd>
 *   @0x1d0300 cmp r8, r0
 *   @0x1d0304 mov r11, r0
 *   @0x1d0308 ble 0x1d032c <_Z14HandleTimeLinev+0x278>
 *   @0x1d030c mov r3, r8
 *   @0x1d0310 mov r0, r6
 *   @0x1d0314 mov r1, r6
 *   @0x1d0318 mov r2, r9
 *   @0x1d031c sub r8, r8, #1
 *   @0x1d0320 bl 0xf30ec <_Z22Perform_Event_TimeLineP9CInstanceS0_ii>
 *   @0x1d0324 cmp r8, r11
 *   @0x1d0328 bne 0x1d030c <_Z14HandleTimeLinev+0x258>
 *   @0x1d032c vldr s15, [r6, #340]
 *   @0x1d0330 vcmp.f32 s16, s15
 *   @0x1d0334 ldrb r3, [r6, #0x15d]
 *   @0x1d0338 vstr s16, [r6, #336]
 *   @0x1d033c vmrs APSR_nzcv, fpscr
 *   @0x1d0340 vstreq s18, [r6, #340]
 *   @0x1d0344 cmp r3, #0
 *   @0x1d0348 beq 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d034c vldr s15, [r6, #340]
 *   @0x1d0350 vcmpe.f32 s15, #0
 *   @0x1d0354 vmrs APSR_nzcv, fpscr
 *   @0x1d0358 bpl 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d035c mov r0, r10
 *   @0x1d0360 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv>
 *   @0x1d0364 sub r1, r0, #1
 *   @0x1d0368 mov r0, r10
 *   @0x1d036c bl 0x1f1738 <_ZN9CTimeLine7GetStepEi>
 *   @0x1d0370 vmov s13, r0
 *   @0x1d0374 vcvt.f32.s32 s15, s13
 *   @0x1d0378 vstr s15, [r6, #340]
 *   @0x1d037c b 0x1d01e8 <_Z14HandleTimeLinev+0x134>
 *   @0x1d0380 andeq r0, r0, r0
 *   @0x1d0384 eoreq sp, r1, r4, ror #16
 *   @0x1d0388 eoreq pc, r1, r12, lsr r10
 *
 * ══ §20/42 CInstance::CreatePhysicsBody  0x192cd4  size 720  180 条（0x192cd4..0x192fa4）
 * @func 0x192cd4 0x192fa4  size 720  180 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::AddShapePoint(float, float)×2 / 0xb6550×2 / Error_Show(char const*, bool)×2 / Sprite_Exists(int) / CPhysicsFixtureFactory::CreateFixture() / CInstance::CreatePhysicsBody(CRoom*)+0x120 / CPhysicsFixture::SetPolygonShape() / CPhysicsWorld::CreateBody(CPhysicsFixture*, CInstance*, float, float)
 * 字段偏移 top8: 0x80×4 / 0x40×4 / 0x20×3 / 0x44×3 / 0x14×3 / 0x20c×2 / 0x1c×2 / 0xb4×2
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x192cd4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x192cd8 vpush {d8}
 *   @0x192cdc sub sp, sp, #528
 *   @0x192ce0 ldr r4, [pc, #0x2b0]
 *   @0x192ce4 mov r5, r0
 *   @0x192ce8 ldr r3, [r0, #0x80]
 *   @0x192cec mov r8, r1
 *   @0x192cf0 ldr r4, [pc, r4]
 *   @0x192cf4 cmp r3, #0
 *   @0x192cf8 ldr r2, [r4]
 *   @0x192cfc str r2, [sp, #0x20c]
 *   @0x192d00 beq 0x192d10 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x3c>
 *   @0x192d04 ldrb r3, [r3, #0x1c]
 *   @0x192d08 cmp r3, #0
 *   @0x192d0c bne 0x192d2c <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x58>
 *   @0x192d10 ldr r2, [sp, #0x20c]
 *   @0x192d14 ldr r3, [r4]
 *   @0x192d18 cmp r2, r3
 *   @0x192d1c bne 0x192f8c <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x2b8>
 *   @0x192d20 add sp, sp, #528
 *   @0x192d24 vpop {d8}
 *   @0x192d28 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x192d2c ldr r0, [r0, #0x8c]
 *   @0x192d30 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x192d34 cmp r0, #0
 *   @0x192d38 beq 0x192d10 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x3c>
 *   @0x192d3c ldr r3, [r8, #0xb4]
 *   @0x192d40 cmp r3, #0
 *   @0x192d44 beq 0x192d10 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x3c>
 *   @0x192d48 ldr r6, [r5, #0x80]
 *   @0x192d4c vldr s16, [r3, #96]
 *   @0x192d50 bl 0x2364d4 <_ZN22CPhysicsFixtureFactory13CreateFixtureEv>
 *   @0x192d54 ldr r9, [r6, #0x20]
 *   @0x192d58 cmp r9, #0
 *   @0x192d5c mov r7, r0
 *   @0x192d60 beq 0x192e74 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x1a0>
 *   @0x192d64 blt 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120>
 *   @0x192d68 cmp r9, #2
 *   @0x192d6c bgt 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120>
 *   @0x192d70 bl 0x2368f8 <_ZN15CPhysicsFixture15SetPolygonShapeEv>
 *   @0x192d74 vldr s15, [r5, #152]
 *   @0x192d78 vldr s14, [r5, #156]
 *   @0x192d7c vmul.f32 s13, s15, s14
 *   @0x192d80 vcmpe.f32 s13, #0
 *   @0x192d84 vmrs APSR_nzcv, fpscr
 *   @0x192d88 bmi 0x192f00 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x22c>
 *   @0x192d8c ldr r3, [r6, #0x40]
 *   @0x192d90 cmp r3, #0
 *   @0x192d94 movgt r10, #4
 *   @0x192d98 movgt r9, #0
 *   @0x192d9c bgt 0x192dac <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0xd8>
 *   @0x192da0 b 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120>
 *   @0x192da4 vldr s15, [r5, #152]
 *   @0x192da8 vldr s14, [r5, #156]
 *   @0x192dac ldr r3, [r6, #0x44]
 *   @0x192db0 mov r0, r7
 *   @0x192db4 add r2, r3, r9, lsl #3
 *   @0x192db8 add r3, r3, r10
 *   @0x192dbc vldr s12, [r2]
 *   @0x192dc0 vldr s13, [r3]
 *   @0x192dc4 vmul.f32 s12, s16, s12
 *   @0x192dc8 add r9, r9, #1
 *   @0x192dcc add r10, r10, #8
 *   @0x192dd0 vmul.f32 s13, s16, s13
 *   @0x192dd4 vmul.f32 s12, s12, s15
 *   @0x192dd8 vmul.f32 s13, s13, s14
 *   @0x192ddc vmov r1, s12
 *   @0x192de0 vmov r2, s13
 *   @0x192de4 bl 0x236ac8 <_ZN15CPhysicsFixture13AddShapePointEff>
 *   @0x192de8 ldr r3, [r6, #0x40]
 *   @0x192dec cmp r3, r9
 *   @0x192df0 bgt 0x192da4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0xd0>
 *   @0x192df4 vldr s16, [pc, #404]
 *   @0x192df8 vmov.f32 s17, s16
 *   @0x192dfc ldr r2, [r6, #0x34]
 *   @0x192e00 ldrb r0, [r6, #0x1d]
 *   @0x192e04 ldr r3, [r7, #0x20]
 *   @0x192e08 str r2, [r7, #0x4]
 *   @0x192e0c ldr r12, [r6, #0x30]
 *   @0x192e10 ldr r1, [r6, #0x24]
 *   @0x192e14 ldrb r2, [r6, #0x3c]
 *   @0x192e18 str r12, [r7]
 *   @0x192e1c strb r0, [r3, #0x14]
 *   @0x192e20 ldr r0, [r6, #0x28]
 *   @0x192e24 strh r1, [r3, #32]
 *   @0x192e28 ldr r1, [r6, #0x38]
 *   @0x192e2c str r0, [r3, #0x10]
 *   @0x192e30 ldr r0, [r6, #0x2c]
 *   @0x192e34 str r1, [r3, #0x8]
 *   @0x192e38 mov r1, r7
 *   @0x192e3c str r0, [r3, #0xc]
 *   @0x192e40 strb r2, [r7, #0x8]
 *   @0x192e44 mov r2, r5
 *   @0x192e48 ldrb r3, [r6, #0x3d]
 *   @0x192e4c cmp r3, #0
 *   @0x192e50 movne r3, #1
 *   @0x192e54 strbne r3, [r7, #0x18]
 *   @0x192e58 vmov r3, s17
 *   @0x192e5c ldr r0, [r8, #0xb4]
 *   @0x192e60 vstr s16, [sp]
 *   @0x192e64 bl 0x23894c <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff>
 *   @0x192e68 ldr r0, [r7, #0x1c]
 *   @0x192e6c bl 0x236648 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj>
 *   @0x192e70 b 0x192d10 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x3c>
 *   @0x192e74 ldr r3, [r6, #0x40]
 *   @0x192e78 cmp r3, #1
 *   @0x192e7c ble 0x192f60 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x28c>
 *   @0x192e80 vldr s15, [r5, #152]
 *   @0x192e84 vldr s13, [r5, #156]
 *   @0x192e88 vsub.f32 s13, s15, s13
 *   @0x192e8c vldr s14, [pc, #256]
 *   @0x192e90 vabs.f32 s13, s13
 *   @0x192e94 vcmpe.f32 s13, s14
 *   @0x192e98 vmrs APSR_nzcv, fpscr
 *   @0x192e9c bpl 0x192ed0 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x1fc>
 *   @0x192ea0 ldr r3, [r6, #0x44]
 *   @0x192ea4 vldr s13, [r3, #8]
 *   @0x192ea8 vmul.f32 s16, s16, s13
 *   @0x192eac mov r0, r7
 *   @0x192eb0 vldr s17, [r3]
 *   @0x192eb4 vldr s14, [r3, #4]
 *   @0x192eb8 vmul.f32 s16, s16, s15
 *   @0x192ebc vmov r1, s16
 *   @0x192ec0 vnmul.f32 s17, s17, s15
 *   @0x192ec4 vnmul.f32 s16, s14, s15
 *   @0x192ec8 bl 0x236788 <_ZN15CPhysicsFixture14SetCircleShapeEf>
 *   @0x192ecc b 0x192dfc <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x128>
 *   @0x192ed0 ldr r3, [r5, #0x80]
 *   @0x192ed4 add r9, sp, #12
 *   @0x192ed8 ldr r1, [pc, #0xbc]
 *   @0x192edc mov r0, r9
 *   @0x192ee0 add r1, pc, r1
 *   @0x192ee4 ldr r2, [r3, #0x14]
 *   @0x192ee8 bl 0xb6550 <sprintf@plt>
 *   @0x192eec mov r0, r9
 *   @0x192ef0 mov r1, #0
 *   @0x192ef4 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x192ef8 vmov.f32 s15, #1.000000e+00
 *   @0x192efc b 0x192ea0 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x1cc>
 *   @0x192f00 ldr r9, [r6, #0x40]
 *   @0x192f04 subs r9, r9, #1
 *   @0x192f08 bmi 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120>
 *   @0x192f0c lsl r10, r9, #3
 *   @0x192f10 b 0x192f1c <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x248>
 *   @0x192f14 vldr s15, [r5, #152]
 *   @0x192f18 vldr s14, [r5, #156]
 *   @0x192f1c ldr r3, [r6, #0x44]
 *   @0x192f20 sub r9, r9, #1
 *   @0x192f24 mov r0, r7
 *   @0x192f28 add r3, r3, r10
 *   @0x192f2c vldr s12, [r3]
 *   @0x192f30 vldr s13, [r3, #4]
 *   @0x192f34 vmul.f32 s12, s16, s12
 *   @0x192f38 sub r10, r10, #8
 *   @0x192f3c vmul.f32 s13, s16, s13
 *   @0x192f40 vmul.f32 s12, s12, s15
 *   @0x192f44 vmul.f32 s13, s13, s14
 *   @0x192f48 vmov r1, s12
 *   @0x192f4c vmov r2, s13
 *   @0x192f50 bl 0x236ac8 <_ZN15CPhysicsFixture13AddShapePointEff>
 *   @0x192f54 cmn r9, #1
 *   @0x192f58 bne 0x192f14 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x240>
 *   @0x192f5c b 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120>
 *   @0x192f60 ldr r3, [r5, #0x80]
 *   @0x192f64 add r10, sp, #12
 *   @0x192f68 ldr r1, [pc, #0x30]
 *   @0x192f6c mov r0, r10
 *   @0x192f70 add r1, pc, r1
 *   @0x192f74 ldr r2, [r3, #0x14]
 *   @0x192f78 bl 0xb6550 <sprintf@plt>
 *   @0x192f7c mov r0, r10
 *   @0x192f80 mov r1, r9
 *   @0x192f84 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x192f88 b 0x192e80 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x1ac>
 *   @0x192f8c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x192f90 andeq r0, r0, r0
 *   @0x192f94 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x192f98 eoreq r10, r5, r0, ror #24
 *   @0x192f9c andseq r9, r11, r12, lsr #14
 *   @0x192fa0 andseq r9, r11, r0, lsl #13
 *
 * ══ §21/42 COggAudio::DecompressOgg  0x226dec  size 720  180 条（0x226dec..0x2270bc）
 * @func 0x226dec 0x2270bc  size 720  180 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SOggChannel::SOggChannel() / ov_open_callbacks / ov_info / ov_pcm_total / MemoryManager::Alloc(unsigned int, char const*, int, bool) / COggAudio::DecompressOgg(cAudio_Sound*)+0x29c / ov_read / 0xb6af0
 * 字段偏移 top8: 0x1c×6 / 0xc×5 / 0x2c×3 / 0x28×2 / 0x334×2 / 0x20×2 / 0x24×2 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226dec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x226df0 sub sp, sp, #828
 *   @0x226df4 ldr r6, [pc, #0x298]
 *   @0x226df8 mov r4, r1
 *   @0x226dfc ldr r8, [r1, #0x28]
 *   @0x226e00 ldr r6, [pc, r6]
 *   @0x226e04 cmp r8, #0
 *   @0x226e08 ldr r3, [r6]
 *   @0x226e0c str r3, [sp, #0x334]
 *   @0x226e10 beq 0x226e20 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x34>
 *   @0x226e14 ldr r8, [r1, #0x2c]
 *   @0x226e18 cmp r8, #0
 *   @0x226e1c bne 0x226e3c <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x50>
 *   @0x226e20 ldr r1, [sp, #0x334]
 *   @0x226e24 mov r0, r8
 *   @0x226e28 ldr r3, [r6]
 *   @0x226e2c cmp r1, r3
 *   @0x226e30 bne 0x227090 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x2a4>
 *   @0x226e34 add sp, sp, #828
 *   @0x226e38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x226e3c ldr r3, [pc, #0x254]
 *   @0x226e40 add r7, sp, #48
 *   @0x226e44 ldr r1, [pc, #0x250]
 *   @0x226e48 mov r8, #0
 *   @0x226e4c ldr r3, [pc, r3]
 *   @0x226e50 ldr r2, [r4]
 *   @0x226e54 add r1, pc, r1
 *   @0x226e58 ldr r3, [r3]
 *   @0x226e5c str r3, [sp, #0x1c]
 *   @0x226e60 ldr r3, [r3]
 *   @0x226e64 ldr r0, [sp, #0x1c]
 *   @0x226e68 ldr r3, [r3, #0xc]
 *   @0x226e6c blx r3
 *   @0x226e70 mov r0, r7
 *   @0x226e74 bl 0x2233f4 <_ZN11SOggChannelC2Ev>
 *   @0x226e78 ldr r1, [pc, #0x220]
 *   @0x226e7c str r4, [sp, #0x2ec]
 *   @0x226e80 ldr r1, [pc, r1]
 *   @0x226e84 str r8, [sp, #0x2f0]
 *   @0x226e88 ldm r1, {r0, r1, r2, r3}
 *   @0x226e8c stm sp, {r0, r1, r2, r3}
 *   @0x226e90 mov r0, r7
 *   @0x226e94 mov r1, r7
 *   @0x226e98 mov r2, r8
 *   @0x226e9c mov r3, r8
 *   @0x226ea0 bl 0x231c48 <ov_open_callbacks>
 *   @0x226ea4 subs r9, r0, #0
 *   @0x226ea8 bne 0x227008 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x21c>
 *   @0x226eac mvn r1, #0
 *   @0x226eb0 mov r0, r7
 *   @0x226eb4 bl 0x232e28 <ov_info>
 *   @0x226eb8 movw r2, #0x1103
 *   @0x226ebc movw r3, #0x1101
 *   @0x226ec0 ldr r1, [r0, #0x4]
 *   @0x226ec4 str r0, [sp, #0x20]
 *   @0x226ec8 mov r0, r7
 *   @0x226ecc cmp r1, #1
 *   @0x226ed0 mvn r1, #0
 *   @0x226ed4 movne r3, r2
 *   @0x226ed8 movne r5, #4
 *   @0x226edc moveq r5, #2
 *   @0x226ee0 str r3, [sp, #0x24]
 *   @0x226ee4 bl 0x23138c <ov_pcm_total>
 *   @0x226ee8 movw r2, #0x29b
 *   @0x226eec mov r3, #1
 *   @0x226ef0 umull r10, r11, r0, r5
 *   @0x226ef4 mla r5, r5, r1, r11
 *   @0x226ef8 ldr r1, [pc, #0x1a4]
 *   @0x226efc strd r10, r11, [sp, #16]
 *   @0x226f00 add r1, pc, r1
 *   @0x226f04 ldr r0, [sp, #0x10]
 *   @0x226f08 str r5, [sp, #0x14]
 *   @0x226f0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x226f10 subs r8, r0, #0
 *   @0x226f14 beq 0x227038 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x24c>
 *   @0x226f18 ldrd r4, r5, [sp, #16]
 *   @0x226f1c str r9, [sp, #0x28]
 *   @0x226f20 cmp r4, #1
 *   @0x226f24 sbcs r5, r5, #0
 *   @0x226f28 mov r4, #0
 *   @0x226f2c mov r5, #0
 *   @0x226f30 blt 0x227088 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x29c>
 *   @0x226f34 mov r11, r9
 *   @0x226f38 add r10, sp, #40
 *   @0x226f3c ldr r9, [sp, #0x10]
 *   @0x226f40 b 0x226f60 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x174>
 *   @0x226f44 add r11, r11, r0
 *   @0x226f48 ldrd r0, r1, [sp, #16]
 *   @0x226f4c asr r5, r11, #31
 *   @0x226f50 mov r4, r11
 *   @0x226f54 cmp r4, r0
 *   @0x226f58 sbcs r1, r5, r1
 *   @0x226f5c bge 0x226f80 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x194>
 *   @0x226f60 mov r0, r7
 *   @0x226f64 add r1, r8, r11
 *   @0x226f68 rsb r2, r11, r9
 *   @0x226f6c mov r3, r10
 *   @0x226f70 bl 0x232ec8 <ov_read>
 *   @0x226f74 cmp r0, #0
 *   @0x226f78 bgt 0x226f44 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x158>
 *   @0x226f7c bne 0x227064 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x278>
 *   @0x226f80 ldrd r0, r1, [sp, #16]
 *   @0x226f84 cmp r1, r5
 *   @0x226f88 cmpeq r0, r4
 *   @0x226f8c beq 0x226fb8 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x1cc>
 *   @0x226f90 ldr r4, [sp, #0x1c]
 *   @0x226f94 mov r2, r11
 *   @0x226f98 ldr r1, [pc, #0x108]
 *   @0x226f9c ldr r3, [r4]
 *   @0x226fa0 mov r0, r4
 *   @0x226fa4 ldrd r4, r5, [sp, #16]
 *   @0x226fa8 add r1, pc, r1
 *   @0x226fac strd r4, r5, [sp]
 *   @0x226fb0 ldr r3, [r3, #0xc]
 *   @0x226fb4 blx r3
 *   @0x226fb8 add r1, sp, #824
 *   @0x226fbc mov r3, #0
 *   @0x226fc0 mov r0, #1
 *   @0x226fc4 str r3, [r1, #-0x30c]!
 *   @0x226fc8 bl 0xb6af0 <alGenBuffers@plt>
 *   @0x226fcc ldr r5, [sp, #0x20]
 *   @0x226fd0 mov r2, r8
 *   @0x226fd4 ldr r1, [sp, #0x24]
 *   @0x226fd8 mov r3, r11
 *   @0x226fdc ldr r0, [sp, #0x2c]
 *   @0x226fe0 ldr lr, [r5, #0x8]
 *   @0x226fe4 str lr, [sp]
 *   @0x226fe8 bl 0xb6afc <alBufferData@plt>
 *   @0x226fec ldr r0, [pc, #0xb8]
 *   @0x226ff0 add r0, pc, r0
 *   @0x226ff4 bl 0x215fd0 <_Z7checkALPKc>
 *   @0x226ff8 mov r0, r8
 *   @0x226ffc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x227000 ldr r8, [sp, #0x2c]
 *   @0x227004 b 0x22702c <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x240>
 *   @0x227008 ldr r5, [sp, #0x1c]
 *   @0x22700c mov r2, r9
 *   @0x227010 ldr r1, [pc, #0x98]
 *   @0x227014 ldr r3, [r4]
 *   @0x227018 ldr r12, [r5]
 *   @0x22701c mov r0, r5
 *   @0x227020 add r1, pc, r1
 *   @0x227024 ldr r12, [r12, #0xc]
 *   @0x227028 blx r12
 *   @0x22702c mov r0, r7
 *   @0x227030 bl 0x2234d0 <_ZN11SOggChannelD2Ev>
 *   @0x227034 b 0x226e20 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x34>
 *   @0x227038 ldr r11, [sp, #0x1c]
 *   @0x22703c ldr lr, [r4]
 *   @0x227040 ldr r1, [pc, #0x6c]
 *   @0x227044 ldr r12, [r11]
 *   @0x227048 mov r0, r11
 *   @0x22704c str lr, [sp]
 *   @0x227050 add r1, pc, r1
 *   @0x227054 ldrd r2, r3, [sp, #16]
 *   @0x227058 ldr r12, [r12, #0xc]
 *   @0x22705c blx r12
 *   @0x227060 b 0x22702c <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x240>
 *   @0x227064 ldr r10, [sp, #0x1c]
 *   @0x227068 mov r2, r0
 *   @0x22706c ldr r1, [pc, #0x44]
 *   @0x227070 ldr r3, [r10]
 *   @0x227074 mov r0, r10
 *   @0x227078 add r1, pc, r1
 *   @0x22707c ldr r3, [r3, #0xc]
 *   @0x227080 blx r3
 *   @0x227084 b 0x226f80 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x194>
 *   @0x227088 mov r11, r9
 *   @0x22708c b 0x226f80 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x194>
 *   @0x227090 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x227094 andseq r6, r12, r0, asr r11
 *   @0x227098 andseq r6, r12, r8, asr #17
 *   @0x22709c andseq lr, r2, r12, ror r1
 *   @0x2270a0 ldrsheq r10, [r12], -r4
 *   @0x2270a4 andseq lr, r2, r12, lsl #2
 *   @0x2270a8 ldrsbeq lr, [r2], -r4
 *   @0x2270ac andseq lr, r2, r4, asr #1
 *   @0x2270b0 andseq sp, r2, r8, asr #31
 *   @0x2270b4 ldrsheq sp, [r2], -r0
 *   @0x2270b8 andseq sp, r2, r4, ror #26
 *
 * ══ §22/42 memLogEvent  0x27ba28  size 716  179 条（0x27ba28..0x27bcf4）
 * @func 0x27ba28 0x27bcf4  size 716  179 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844×6 / 0xb68bc×6 / 0xb6850×6 / 0xb6610 / memLogEvent(char const*, ...)+0x260 / memLogEvent(char const*, ...)+0x12c / 0xb6538 / memLogEvent(char const*, ...)+0x1f4
 * 字段偏移 top8: 0x4×15 / 0x8×6 / 0xc×3 / 0x284×1 / 0x274×1 / 0x28×1 / 0x1ff×1 / 0x22c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ba28 push {r0, r1, r2, r3}
 *   @0x27ba2c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x27ba30 sub sp, sp, #12
 *   @0x27ba34 ldr r4, [pc, #0x284]
 *   @0x27ba38 ldr r4, [pc, r4]
 *   @0x27ba3c ldr r3, [r4]
 *   @0x27ba40 cmp r3, #0
 *   @0x27ba44 beq 0x27bb44 <_Z11memLogEventPKcz+0x11c>
 *   @0x27ba48 ldr r6, [pc, #0x274]
 *   @0x27ba4c add r0, sp, #44
 *   @0x27ba50 mov r1, #512
 *   @0x27ba54 str r0, [sp]
 *   @0x27ba58 add r6, pc, r6
 *   @0x27ba5c mov r3, r0
 *   @0x27ba60 ldr r2, [sp, #0x28]
 *   @0x27ba64 mov r7, #0
 *   @0x27ba68 mov r0, r6
 *   @0x27ba6c bl 0xb6610 <vsnprintf@plt>
 *   @0x27ba70 ldr r5, [r4]
 *   @0x27ba74 strb r7, [r6, #0x1ff]
 *   @0x27ba78 ldr r3, [r5, #0xc]
 *   @0x27ba7c cmp r3, r7
 *   @0x27ba80 ble 0x27bc88 <_Z11memLogEventPKcz+0x260>
 *   @0x27ba84 ldr r6, [r5, #0x4]
 *   @0x27ba88 add r2, r6, #4
 *   @0x27ba8c cmp r3, r2
 *   @0x27ba90 ble 0x27bb54 <_Z11memLogEventPKcz+0x12c>
 *   @0x27ba94 ldr r2, [pc, #0x22c]
 *   @0x27ba98 ldr r3, [r5]
 *   @0x27ba9c add r2, pc, r2
 *   @0x27baa0 ldr r0, [r2]
 *   @0x27baa4 str r0, [r3, r6]
 *   @0x27baa8 ldr r3, [r5, #0x4]
 *   @0x27baac add r3, r3, #4
 *   @0x27bab0 str r3, [r5, #0x4]
 *   @0x27bab4 ldr r0, [pc, #0x210]
 *   @0x27bab8 add r0, pc, r0
 *   @0x27babc bl 0xb6538 <strlen@plt>
 *   @0x27bac0 ldr r5, [r4]
 *   @0x27bac4 ldr r3, [r5, #0xc]
 *   @0x27bac8 cmp r3, #0
 *   @0x27bacc str r0, [sp, #0x4]
 *   @0x27bad0 ble 0x27bc1c <_Z11memLogEventPKcz+0x1f4>
 *   @0x27bad4 ldr r6, [r5, #0x4]
 *   @0x27bad8 add r2, r6, #4
 *   @0x27badc cmp r3, r2
 *   @0x27bae0 ble 0x27bbd8 <_Z11memLogEventPKcz+0x1b0>
 *   @0x27bae4 ldr r3, [r5]
 *   @0x27bae8 ldr r0, [sp, #0x4]
 *   @0x27baec str r0, [r3, r6]
 *   @0x27baf0 ldr r3, [r5, #0x4]
 *   @0x27baf4 add r3, r3, #4
 *   @0x27baf8 str r3, [r5, #0x4]
 *   @0x27bafc ldr r4, [r4]
 *   @0x27bb00 ldr r5, [sp, #0x4]
 *   @0x27bb04 ldr r3, [r4, #0xc]
 *   @0x27bb08 cmp r3, #0
 *   @0x27bb0c ble 0x27bc50 <_Z11memLogEventPKcz+0x228>
 *   @0x27bb10 ldr r6, [r4, #0x4]
 *   @0x27bb14 add r2, r5, r6
 *   @0x27bb18 cmp r3, r2
 *   @0x27bb1c ble 0x27bb94 <_Z11memLogEventPKcz+0x16c>
 *   @0x27bb20 ldr r0, [r4]
 *   @0x27bb24 mov r2, r5
 *   @0x27bb28 ldr r1, [pc, #0x1a0]
 *   @0x27bb2c add r0, r0, r6
 *   @0x27bb30 add r1, pc, r1
 *   @0x27bb34 bl 0xb65bc <memcpy@plt>
 *   @0x27bb38 ldr r3, [r4, #0x4]
 *   @0x27bb3c add r5, r3, r5
 *   @0x27bb40 str r5, [r4, #0x4]
 *   @0x27bb44 add sp, sp, #12
 *   @0x27bb48 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x27bb4c add sp, sp, #16
 *   @0x27bb50 bx lr
 *   @0x27bb54 ldr r1, [pc, #0x178]
 *   @0x27bb58 ldr r0, [r5, #0x8]
 *   @0x27bb5c add r1, pc, r1
 *   @0x27bb60 ldr r9, [r5]
 *   @0x27bb64 bl 0xb6844 <fopen@plt>
 *   @0x27bb68 mov r1, r6
 *   @0x27bb6c mov r2, #1
 *   @0x27bb70 mov r6, r7
 *   @0x27bb74 mov r8, r0
 *   @0x27bb78 mov r0, r9
 *   @0x27bb7c mov r3, r8
 *   @0x27bb80 bl 0xb68bc <fwrite@plt>
 *   @0x27bb84 mov r0, r8
 *   @0x27bb88 bl 0xb6850 <fclose@plt>
 *   @0x27bb8c str r7, [r5, #0x4]
 *   @0x27bb90 b 0x27ba94 <_Z11memLogEventPKcz+0x6c>
 *   @0x27bb94 ldr r1, [pc, #0x13c]
 *   @0x27bb98 ldr r0, [r4, #0x8]
 *   @0x27bb9c add r1, pc, r1
 *   @0x27bba0 ldr r8, [r4]
 *   @0x27bba4 bl 0xb6844 <fopen@plt>
 *   @0x27bba8 mov r1, r6
 *   @0x27bbac mov r2, #1
 *   @0x27bbb0 mov r7, r0
 *   @0x27bbb4 mov r0, r8
 *   @0x27bbb8 mov r3, r7
 *   @0x27bbbc bl 0xb68bc <fwrite@plt>
 *   @0x27bbc0 mov r0, r7
 *   @0x27bbc4 bl 0xb6850 <fclose@plt>
 *   @0x27bbc8 mov r3, #0
 *   @0x27bbcc mov r6, r3
 *   @0x27bbd0 str r3, [r4, #0x4]
 *   @0x27bbd4 b 0x27bb20 <_Z11memLogEventPKcz+0xf8>
 *   @0x27bbd8 ldr r1, [pc, #0xfc]
 *   @0x27bbdc ldr r0, [r5, #0x8]
 *   @0x27bbe0 add r1, pc, r1
 *   @0x27bbe4 ldr r8, [r5]
 *   @0x27bbe8 bl 0xb6844 <fopen@plt>
 *   @0x27bbec mov r1, r6
 *   @0x27bbf0 mov r2, #1
 *   @0x27bbf4 mov r7, r0
 *   @0x27bbf8 mov r0, r8
 *   @0x27bbfc mov r3, r7
 *   @0x27bc00 bl 0xb68bc <fwrite@plt>
 *   @0x27bc04 mov r0, r7
 *   @0x27bc08 bl 0xb6850 <fclose@plt>
 *   @0x27bc0c mov r3, #0
 *   @0x27bc10 mov r6, r3
 *   @0x27bc14 str r3, [r5, #0x4]
 *   @0x27bc18 b 0x27bae4 <_Z11memLogEventPKcz+0xbc>
 *   @0x27bc1c ldr r1, [pc, #0xbc]
 *   @0x27bc20 ldr r0, [r5, #0x8]
 *   @0x27bc24 add r1, pc, r1
 *   @0x27bc28 bl 0xb6844 <fopen@plt>
 *   @0x27bc2c mov r1, #4
 *   @0x27bc30 mov r2, #1
 *   @0x27bc34 mov r5, r0
 *   @0x27bc38 mov r3, r0
 *   @0x27bc3c add r0, sp, #4
 *   @0x27bc40 bl 0xb68bc <fwrite@plt>
 *   @0x27bc44 mov r0, r5
 *   @0x27bc48 bl 0xb6850 <fclose@plt>
 *   @0x27bc4c b 0x27bafc <_Z11memLogEventPKcz+0xd4>
 *   @0x27bc50 ldr r1, [pc, #0x8c]
 *   @0x27bc54 ldr r0, [r4, #0x8]
 *   @0x27bc58 add r1, pc, r1
 *   @0x27bc5c bl 0xb6844 <fopen@plt>
 *   @0x27bc60 mov r1, r5
 *   @0x27bc64 mov r2, #1
 *   @0x27bc68 mov r4, r0
 *   @0x27bc6c mov r3, r0
 *   @0x27bc70 ldr r0, [pc, #0x70]
 *   @0x27bc74 add r0, pc, r0
 *   @0x27bc78 bl 0xb68bc <fwrite@plt>
 *   @0x27bc7c mov r0, r4
 *   @0x27bc80 bl 0xb6850 <fclose@plt>
 *   @0x27bc84 b 0x27bb44 <_Z11memLogEventPKcz+0x11c>
 *   @0x27bc88 ldr r1, [pc, #0x5c]
 *   @0x27bc8c ldr r0, [r5, #0x8]
 *   @0x27bc90 add r1, pc, r1
 *   @0x27bc94 bl 0xb6844 <fopen@plt>
 *   @0x27bc98 mov r1, #4
 *   @0x27bc9c mov r2, #1
 *   @0x27bca0 mov r5, r0
 *   @0x27bca4 mov r3, r0
 *   @0x27bca8 ldr r0, [pc, #0x40]
 *   @0x27bcac add r0, pc, r0
 *   @0x27bcb0 bl 0xb68bc <fwrite@plt>
 *   @0x27bcb4 mov r0, r5
 *   @0x27bcb8 bl 0xb6850 <fclose@plt>
 *   @0x27bcbc b 0x27bab4 <_Z11memLogEventPKcz+0x8c>
 *   @0x27bcc0 andseq r5, r7, r12, ror #27
 *   @0x27bcc4 subeq r10, sp, r8, lsr r10
 *   @0x27bcc8 andeq r11, sp, r4, lsl r7
 *   @0x27bccc ldrdeq r10, r11, [sp], #-152
 *   @0x27bcd0 subeq r10, sp, r0, ror #18
 *   @0x27bcd4 andeq r11, sp, r0, asr r6
 *   @0x27bcd8 andeq r11, sp, r0, lsl r6
 *   @0x27bcdc andeq r11, sp, r12, asr #11
 *   @0x27bce0 andeq r11, sp, r8, lsl #11
 *   @0x27bce4 andeq r11, sp, r4, asr r5
 *   @0x27bce8 subeq r10, sp, r12, lsl r8
 *   @0x27bcec andeq r11, sp, r12, lsl r5
 *   @0x27bcf0 andeq r11, sp, r4, lsl #10
 *
 * ══ §23/42 CInstance::Collision_Skeleton  0x195294  size 708  177 条（0x195294..0x195558）
 * @func 0x195294 0x195558  size 708  177 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Collision_Skeleton(CInstance*, bool)+0x178×4 / CInstance::SkeletonAnimation()×3 / CSkeletonInstance::ComputeBoundingBox(tagYYRECT*, int, float, float, float, float, float)×2 / Sprite_Data(int)×2 / CInstance::Compute_BoundingBox(bool)×2 / CSkeletonInstance::SkeletonCollision(int, float, float, float, float, float, CSkeletonInstance*, int, float, float, float, float, float) / CSkeletonInstance::SpriteCollision(int, float, float, float, float, float, CSprite*, tagYYRECT*, int, float, float, float, float, float)
 * 字段偏移 top8: 0x98×6 / 0xb4×6 / 0xb8×6 / 0x9c×6 / 0xa0×6 / 0x4×4 / 0x8×4 / 0xc×4
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x195294 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x195298 sub sp, sp, #48
 *   @0x19529c mov r4, r0
 *   @0x1952a0 mov r5, r1
 *   @0x1952a4 mov r10, r2
 *   @0x1952a8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x1952ac ldr r6, [pc, #0x2a0]
 *   @0x1952b0 mov r8, r0
 *   @0x1952b4 mov r0, r5
 *   @0x1952b8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x1952bc vldr s15, [r4, #144]
 *   @0x1952c0 vcvt.s32.f32 s15, s15
 *   @0x1952c4 ldr r1, [r4, #0x98]
 *   @0x1952c8 ldr r6, [pc, r6]
 *   @0x1952cc ldr r3, [r4, #0xb4]
 *   @0x1952d0 ldr r9, [r6]
 *   @0x1952d4 str r4, [r6]
 *   @0x1952d8 vmov r2, s15
 *   @0x1952dc mov r7, r0
 *   @0x1952e0 ldr r0, [r4, #0xb8]
 *   @0x1952e4 str r1, [sp, #0x4]
 *   @0x1952e8 str r0, [sp]
 *   @0x1952ec ldr r0, [r4, #0x9c]
 *   @0x1952f0 ldr r1, [r4, #0xa0]
 *   @0x1952f4 str r0, [sp, #0x8]
 *   @0x1952f8 mov r0, r8
 *   @0x1952fc str r1, [sp, #0xc]
 *   @0x195300 add r1, r4, #232
 *   @0x195304 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff>
 *   @0x195308 str r5, [r6]
 *   @0x19530c cmp r0, #0
 *   @0x195310 movne r2, #0
 *   @0x195314 movne r3, #1
 *   @0x195318 strbne r2, [r4, #0x64]
 *   @0x19531c strbne r3, [r4, #0xb0]
 *   @0x195320 cmp r7, #0
 *   @0x195324 beq 0x195378 <_ZN9CInstance18Collision_SkeletonEPS_b+0xe4>
 *   @0x195328 ldr r1, [r5, #0xb8]
 *   @0x19532c vldr s15, [r5, #144]
 *   @0x195330 vcvt.s32.f32 s15, s15
 *   @0x195334 ldr r3, [r5, #0xb4]
 *   @0x195338 str r1, [sp]
 *   @0x19533c ldr r0, [r5, #0x98]
 *   @0x195340 ldr r1, [r5, #0x9c]
 *   @0x195344 str r0, [sp, #0x4]
 *   @0x195348 mov r0, r7
 *   @0x19534c str r1, [sp, #0x8]
 *   @0x195350 ldr r1, [r5, #0xa0]
 *   @0x195354 vmov r2, s15
 *   @0x195358 str r1, [sp, #0xc]
 *   @0x19535c add r1, r5, #232
 *   @0x195360 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff>
 *   @0x195364 cmp r0, #0
 *   @0x195368 movne r2, #0
 *   @0x19536c movne r3, #1
 *   @0x195370 strbne r2, [r5, #0x64]
 *   @0x195374 strbne r3, [r5, #0xb0]
 *   @0x195378 ldrb r3, [r4, #0x64]
 *   @0x19537c str r9, [r6]
 *   @0x195380 cmp r3, #0
 *   @0x195384 bne 0x195428 <_ZN9CInstance18Collision_SkeletonEPS_b+0x194>
 *   @0x195388 ldrb r3, [r5, #0x64]
 *   @0x19538c cmp r3, #0
 *   @0x195390 bne 0x195418 <_ZN9CInstance18Collision_SkeletonEPS_b+0x184>
 *   @0x195394 ldr r2, [r4, #0xf0]
 *   @0x195398 ldr r3, [r5, #0xe8]
 *   @0x19539c cmp r2, r3
 *   @0x1953a0 blt 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178>
 *   @0x1953a4 ldr r2, [r5, #0xf0]
 *   @0x1953a8 ldr r3, [r4, #0xe8]
 *   @0x1953ac cmp r2, r3
 *   @0x1953b0 blt 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178>
 *   @0x1953b4 ldr r2, [r4, #0xf4]
 *   @0x1953b8 ldr r3, [r5, #0xec]
 *   @0x1953bc cmp r2, r3
 *   @0x1953c0 blt 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178>
 *   @0x1953c4 ldr r2, [r5, #0xf4]
 *   @0x1953c8 ldr r3, [r4, #0xec]
 *   @0x1953cc cmp r2, r3
 *   @0x1953d0 blt 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178>
 *   @0x1953d4 ldr r0, [r5, #0xac]
 *   @0x1953d8 cmp r0, #0
 *   @0x1953dc ldrlt r0, [r5, #0x8c]
 *   @0x1953e0 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1953e4 cmp r0, #0
 *   @0x1953e8 mov r6, r0
 *   @0x1953ec beq 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178>
 *   @0x1953f0 ldr r3, [r0, #0x18]
 *   @0x1953f4 cmp r3, #0
 *   @0x1953f8 beq 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178>
 *   @0x1953fc cmp r10, #0
 *   @0x195400 bne 0x195438 <_ZN9CInstance18Collision_SkeletonEPS_b+0x1a4>
 *   @0x195404 mov r0, #1
 *   @0x195408 b 0x195410 <_ZN9CInstance18Collision_SkeletonEPS_b+0x17c>
 *   @0x19540c mov r0, #0
 *   @0x195410 add sp, sp, #48
 *   @0x195414 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x195418 mov r0, r5
 *   @0x19541c mov r1, #1
 *   @0x195420 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x195424 b 0x195394 <_ZN9CInstance18Collision_SkeletonEPS_b+0x100>
 *   @0x195428 mov r0, r4
 *   @0x19542c mov r1, #1
 *   @0x195430 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x195434 b 0x195388 <_ZN9CInstance18Collision_SkeletonEPS_b+0xf4>
 *   @0x195438 ldr r0, [r4, #0x8c]
 *   @0x19543c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x195440 ldrb r3, [r0, #0x30]
 *   @0x195444 cmp r3, #0
 *   @0x195448 bne 0x195458 <_ZN9CInstance18Collision_SkeletonEPS_b+0x1c4>
 *   @0x19544c ldrb r3, [r6, #0x30]
 *   @0x195450 cmp r3, #0
 *   @0x195454 beq 0x195404 <_ZN9CInstance18Collision_SkeletonEPS_b+0x170>
 *   @0x195458 cmp r7, #0
 *   @0x19545c beq 0x1954d4 <_ZN9CInstance18Collision_SkeletonEPS_b+0x240>
 *   @0x195460 vldr s15, [r5, #144]
 *   @0x195464 vcvt.s32.f32 s15, s15
 *   @0x195468 str r7, [sp, #0xc]
 *   @0x19546c mov r0, r8
 *   @0x195470 ldr lr, [r4, #0x98]
 *   @0x195474 ldr r12, [r4, #0x9c]
 *   @0x195478 ldr r2, [r4, #0xb4]
 *   @0x19547c ldr r3, [r4, #0xb8]
 *   @0x195480 vmov r1, s15
 *   @0x195484 vldr s15, [r4, #144]
 *   @0x195488 str lr, [sp]
 *   @0x19548c vcvt.s32.f32 s15, s15
 *   @0x195490 str r12, [sp, #0x4]
 *   @0x195494 ldr r12, [r4, #0xa0]
 *   @0x195498 str r12, [sp, #0x8]
 *   @0x19549c str r1, [sp, #0x10]
 *   @0x1954a0 ldr lr, [r5, #0xb4]
 *   @0x1954a4 ldr r12, [r5, #0xb8]
 *   @0x1954a8 vmov r1, s15
 *   @0x1954ac str lr, [sp, #0x14]
 *   @0x1954b0 str r12, [sp, #0x18]
 *   @0x1954b4 ldr r12, [r5, #0x9c]
 *   @0x1954b8 ldr lr, [r5, #0x98]
 *   @0x1954bc str r12, [sp, #0x20]
 *   @0x1954c0 str lr, [sp, #0x1c]
 *   @0x1954c4 ldr r12, [r5, #0xa0]
 *   @0x1954c8 str r12, [sp, #0x24]
 *   @0x1954cc bl 0xbefd8 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff>
 *   @0x1954d0 b 0x195410 <_ZN9CInstance18Collision_SkeletonEPS_b+0x17c>
 *   @0x1954d4 mov r0, r4
 *   @0x1954d8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x1954dc vldr s15, [r5, #144]
 *   @0x1954e0 vcvt.s32.f32 s15, s15
 *   @0x1954e4 str r6, [sp, #0xc]
 *   @0x1954e8 ldr lr, [r4, #0x98]
 *   @0x1954ec ldr r12, [r4, #0x9c]
 *   @0x1954f0 ldr r2, [r4, #0xb4]
 *   @0x1954f4 ldr r3, [r4, #0xb8]
 *   @0x1954f8 vmov r1, s15
 *   @0x1954fc vldr s15, [r4, #144]
 *   @0x195500 str r12, [sp, #0x4]
 *   @0x195504 add r12, r5, #232
 *   @0x195508 str lr, [sp]
 *   @0x19550c vcvt.s32.f32 s15, s15
 *   @0x195510 ldr lr, [r4, #0xa0]
 *   @0x195514 str r12, [sp, #0x10]
 *   @0x195518 str lr, [sp, #0x8]
 *   @0x19551c str r1, [sp, #0x14]
 *   @0x195520 ldr lr, [r5, #0xb4]
 *   @0x195524 ldr r12, [r5, #0xb8]
 *   @0x195528 vmov r1, s15
 *   @0x19552c str lr, [sp, #0x18]
 *   @0x195530 str r12, [sp, #0x1c]
 *   @0x195534 ldr r12, [r5, #0x9c]
 *   @0x195538 ldr lr, [r5, #0x98]
 *   @0x19553c str r12, [sp, #0x24]
 *   @0x195540 str lr, [sp, #0x20]
 *   @0x195544 ldr r12, [r5, #0xa0]
 *   @0x195548 str r12, [sp, #0x28]
 *   @0x19554c bl 0xbf0fc <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff>
 *   @0x195550 b 0x195410 <_ZN9CInstance18Collision_SkeletonEPS_b+0x17c>
 *   @0x195554 eoreq r8, r5, r12, ror #12
 *
 * ══ §24/42 F_JS_ToObject  0x247388  size 704  176 条（0x247388..0x247648）
 * @func 0x247388 0x247648  size 704  176 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / F_JSBooleanConstruct(RValue&, CInstance*, CInstance*, int, RValue*) / JS_Number_Constructor(RValue&, CInstance*, CInstance*, int, RValue*) / JS_String(RValue&, CInstance*, CInstance*, int, RValue*) / YYError(char const*, ...)
 * 字段偏移 top8: 0xc×7 / 0x8×6 / 0x4×5 / 0x148×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x247388 push {r4, r5, r6, r7, lr}
 *   @0x24738c mov r4, r1
 *   @0x247390 ldr r1, [r1, #0xc]
 *   @0x247394 sub sp, sp, #12
 *   @0x247398 mov r5, r0
 *   @0x24739c bic r3, r1, #-16777216
 *   @0x2473a0 cmp r3, #13
 *   @0x2473a4 addls pc, pc, r3, lsl #2
 *   @0x2473a8 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c>
 *   @0x2473ac b 0x2474b4 <_Z13F_JS_ToObjectR6RValuePS_+0x12c>
 *   @0x2473b0 b 0x2474d4 <_Z13F_JS_ToObjectR6RValuePS_+0x14c>
 *   @0x2473b4 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c>
 *   @0x2473b8 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c>
 *   @0x2473bc b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c>
 *   @0x2473c0 b 0x2473e4 <_Z13F_JS_ToObjectR6RValuePS_+0x5c>
 *   @0x2473c4 b 0x2473f0 <_Z13F_JS_ToObjectR6RValuePS_+0x68>
 *   @0x2473c8 b 0x247494 <_Z13F_JS_ToObjectR6RValuePS_+0x10c>
 *   @0x2473cc b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c>
 *   @0x2473d0 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c>
 *   @0x2473d4 b 0x247494 <_Z13F_JS_ToObjectR6RValuePS_+0x10c>
 *   @0x2473d8 b 0x2474f4 <_Z13F_JS_ToObjectR6RValuePS_+0x16c>
 *   @0x2473dc b 0x2473e4 <_Z13F_JS_ToObjectR6RValuePS_+0x5c>
 *   @0x2473e0 b 0x247494 <_Z13F_JS_ToObjectR6RValuePS_+0x10c>
 *   @0x2473e4 mov r0, #1
 *   @0x2473e8 add sp, sp, #12
 *   @0x2473ec pop {r4, r5, r6, r7, pc}
 *   @0x2473f0 ldr r2, [r0, #0xc]
 *   @0x2473f4 bic r3, r2, #-16777216
 *   @0x2473f8 cmp r3, #1
 *   @0x2473fc beq 0x24751c <_Z13F_JS_ToObjectR6RValuePS_+0x194>
 *   @0x247400 cmp r3, #2
 *   @0x247404 bne 0x247430 <_Z13F_JS_ToObjectR6RValuePS_+0xa8>
 *   @0x247408 sub r3, r2, #1
 *   @0x24740c bic r3, r3, #-16777216
 *   @0x247410 bic r3, r3, #3
 *   @0x247414 cmp r3, #0
 *   @0x247418 beq 0x2475e4 <_Z13F_JS_ToObjectR6RValuePS_+0x25c>
 *   @0x24741c mov r2, #5
 *   @0x247420 str r2, [r5, #0xc]
 *   @0x247424 ldr r1, [r4, #0xc]
 *   @0x247428 mov r3, #0
 *   @0x24742c str r3, [r5, #0x8]
 *   @0x247430 str r1, [r5, #0xc]
 *   @0x247434 mov r1, #0
 *   @0x247438 ldr r3, [r4, #0xc]
 *   @0x24743c ldr r2, [r4, #0x8]
 *   @0x247440 bic r3, r3, #-16777216
 *   @0x247444 str r1, [r5]
 *   @0x247448 str r2, [r5, #0x8]
 *   @0x24744c cmp r3, #14
 *   @0x247450 addls pc, pc, r3, lsl #2
 *   @0x247454 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x247458 b 0x247554 <_Z13F_JS_ToObjectR6RValuePS_+0x1cc>
 *   @0x24745c b 0x2475c4 <_Z13F_JS_ToObjectR6RValuePS_+0x23c>
 *   @0x247460 b 0x247590 <_Z13F_JS_ToObjectR6RValuePS_+0x208>
 *   @0x247464 b 0x24750c <_Z13F_JS_ToObjectR6RValuePS_+0x184>
 *   @0x247468 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x24746c b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x247470 b 0x247568 <_Z13F_JS_ToObjectR6RValuePS_+0x1e0>
 *   @0x247474 b 0x24750c <_Z13F_JS_ToObjectR6RValuePS_+0x184>
 *   @0x247478 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x24747c b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x247480 b 0x247554 <_Z13F_JS_ToObjectR6RValuePS_+0x1cc>
 *   @0x247484 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x247488 b 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x24748c b 0x247554 <_Z13F_JS_ToObjectR6RValuePS_+0x1cc>
 *   @0x247490 b 0x24750c <_Z13F_JS_ToObjectR6RValuePS_+0x184>
 *   @0x247494 mov r1, #0
 *   @0x247498 str r4, [sp]
 *   @0x24749c mov r2, r1
 *   @0x2474a0 mov r3, #1
 *   @0x2474a4 bl 0x2405dc <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_>
 *   @0x2474a8 mov r0, #0
 *   @0x2474ac add sp, sp, #12
 *   @0x2474b0 pop {r4, r5, r6, r7, pc}
 *   @0x2474b4 mov r1, #0
 *   @0x2474b8 str r4, [sp]
 *   @0x2474bc mov r2, r1
 *   @0x2474c0 mov r3, #1
 *   @0x2474c4 bl 0x24dc90 <_Z21JS_Number_ConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x2474c8 mov r0, #0
 *   @0x2474cc add sp, sp, #12
 *   @0x2474d0 pop {r4, r5, r6, r7, pc}
 *   @0x2474d4 mov r1, #0
 *   @0x2474d8 str r4, [sp]
 *   @0x2474dc mov r2, r1
 *   @0x2474e0 mov r3, #1
 *   @0x2474e4 bl 0x2583e4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_>
 *   @0x2474e8 mov r0, #0
 *   @0x2474ec add sp, sp, #12
 *   @0x2474f0 pop {r4, r5, r6, r7, pc}
 *   @0x2474f4 ldr r0, [pc, #0x148]
 *   @0x2474f8 add r0, pc, r0
 *   @0x2474fc bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x247500 mov r0, #1
 *   @0x247504 add sp, sp, #12
 *   @0x247508 pop {r4, r5, r6, r7, pc}
 *   @0x24750c ldr r3, [r4]
 *   @0x247510 mov r0, #0
 *   @0x247514 str r3, [r5]
 *   @0x247518 b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60>
 *   @0x24751c ldr r6, [r0]
 *   @0x247520 cmp r6, #0
 *   @0x247524 beq 0x247548 <_Z13F_JS_ToObjectR6RValuePS_+0x1c0>
 *   @0x247528 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24752c ldr r7, [r6, #0x4]
 *   @0x247530 sub r7, r7, #1
 *   @0x247534 str r7, [r6, #0x4]
 *   @0x247538 cmp r7, #0
 *   @0x24753c beq 0x2475ec <_Z13F_JS_ToObjectR6RValuePS_+0x264>
 *   @0x247540 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x247544 ldr r1, [r4, #0xc]
 *   @0x247548 mov r3, #0
 *   @0x24754c str r3, [r5]
 *   @0x247550 b 0x247430 <_Z13F_JS_ToObjectR6RValuePS_+0xa8>
 *   @0x247554 ldr r2, [r4]
 *   @0x247558 mov r0, #0
 *   @0x24755c ldr r3, [r4, #0x4]
 *   @0x247560 stm r5, {r2, r3}
 *   @0x247564 b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60>
 *   @0x247568 ldr r3, [r4]
 *   @0x24756c str r3, [r5]
 *   @0x247570 ldr r3, [r4]
 *   @0x247574 cmp r3, #0
 *   @0x247578 beq 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x24757c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x247580 ldr r1, [r4]
 *   @0x247584 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x247588 mov r0, #0
 *   @0x24758c b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60>
 *   @0x247590 ldr r3, [r4]
 *   @0x247594 cmp r3, #0
 *   @0x247598 str r3, [r5]
 *   @0x24759c beq 0x2475bc <_Z13F_JS_ToObjectR6RValuePS_+0x234>
 *   @0x2475a0 ldr r0, [r3, #0x8]
 *   @0x2475a4 ldr r2, [r3]
 *   @0x2475a8 cmp r0, #0
 *   @0x2475ac streq r5, [r3, #0x8]
 *   @0x2475b0 add r2, r2, #1
 *   @0x2475b4 str r2, [r3]
 *   @0x2475b8 beq 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60>
 *   @0x2475bc mov r0, #0
 *   @0x2475c0 b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60>
 *   @0x2475c4 ldr r3, [r4]
 *   @0x2475c8 mov r0, #0
 *   @0x2475cc cmp r3, #0
 *   @0x2475d0 ldrne r2, [r3, #0x4]
 *   @0x2475d4 addne r2, r2, #1
 *   @0x2475d8 strne r2, [r3, #0x4]
 *   @0x2475dc str r3, [r5]
 *   @0x2475e0 b 0x2473e8 <_Z13F_JS_ToObjectR6RValuePS_+0x60>
 *   @0x2475e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2475e8 b 0x24741c <_Z13F_JS_ToObjectR6RValuePS_+0x94>
 *   @0x2475ec ldr r0, [r6]
 *   @0x2475f0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2475f4 str r7, [r6]
 *   @0x2475f8 str r7, [r6, #0x8]
 *   @0x2475fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x247600 ldr r7, [r6, #0x4]
 *   @0x247604 sub r7, r7, #1
 *   @0x247608 str r7, [r6, #0x4]
 *   @0x24760c cmp r7, #0
 *   @0x247610 bne 0x247634 <_Z13F_JS_ToObjectR6RValuePS_+0x2ac>
 *   @0x247614 ldr r0, [r6]
 *   @0x247618 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24761c mov r0, r6
 *   @0x247620 str r7, [r6]
 *   @0x247624 str r7, [r6, #0x8]
 *   @0x247628 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24762c mov r0, r6
 *   @0x247630 bl 0x27d1d0 <_ZdlPv>
 *   @0x247634 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x247638 mov r0, r6
 *   @0x24763c bl 0x27d1d0 <_ZdlPv>
 *   @0x247640 b 0x247540 <_Z13F_JS_ToObjectR6RValuePS_+0x1b8>
 *   @0x247644 ldrsbeq lr, [r0], -r4
 *
 * ══ §25/42 CPhysicsWorld::CreateBody  0x23894c  size 700  175 条（0x23894c..0x238c08）
 * @func 0x23894c 0x238c08  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::CreateFixture(b2FixtureDef const*)×2 / CPhysicsObject::GetFixtureIndex(b2Fixture*)×2 / operator new(unsigned int)×2 / CPhysicsFixture::Finalise(CInstance*) / CPhysicsWorld::BuildCollisionBits(int) / CPhysicsWorld::ApplyVisualOffset(float, b2Vec2 const&, b2Vec2&) / b2World::CreateBody(b2BodyDef const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×4 / 0x1c×3 / 0x84×3 / 0x8×3 / 0x14×3 / 0x10×3 / 0x44c×2 / 0x20×2
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23894c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x238950 mov r10, r3
 *   @0x238954 ldr r5, [pc, #0x2a0]
 *   @0x238958 sub sp, sp, #1104
 *   @0x23895c sub sp, sp, #4
 *   @0x238960 mov r11, r1
 *   @0x238964 ldr r5, [pc, r5]
 *   @0x238968 mov r7, r0
 *   @0x23896c mov r0, r1
 *   @0x238970 mov r1, r2
 *   @0x238974 ldr r3, [r5]
 *   @0x238978 mov r4, r2
 *   @0x23897c str r3, [sp, #0x44c]
 *   @0x238980 bl 0x236b84 <_ZN15CPhysicsFixture8FinaliseEP9CInstance>
 *   @0x238984 ldr r6, [r11, #0x20]
 *   @0x238988 ldr r3, [r6]
 *   @0x23898c cmp r3, #0
 *   @0x238990 beq 0x238bc0 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0x274>
 *   @0x238994 mov r0, r7
 *   @0x238998 ldr r1, [r4, #0x7c]
 *   @0x23899c bl 0x238718 <_ZN13CPhysicsWorld18BuildCollisionBitsEi>
 *   @0x2389a0 cmn r0, #1
 *   @0x2389a4 mov r8, r0
 *   @0x2389a8 addne r3, r0, r0, lsl #1
 *   @0x2389ac moveq r3, #0
 *   @0x2389b0 streq r3, [r6, #0x18]
 *   @0x2389b4 addne r3, r7, r3, lsl #2
 *   @0x2389b8 ldrne r2, [r3, #0x6c]
 *   @0x2389bc ldrne r3, [r3, #0x70]
 *   @0x2389c0 strne r2, [r6, #0x18]
 *   @0x2389c4 str r3, [r6, #0x1c]
 *   @0x2389c8 ldr r3, [r4, #0x84]
 *   @0x2389cc cmp r3, #0
 *   @0x2389d0 beq 0x238a10 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0xc4>
 *   @0x2389d4 ldr r0, [r3]
 *   @0x2389d8 mov r1, r6
 *   @0x2389dc bl 0x2c6dfc <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef>
 *   @0x2389e0 mov r1, r0
 *   @0x2389e4 ldr r0, [r4, #0x84]
 *   @0x2389e8 bl 0x237708 <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture>
 *   @0x2389ec mov r4, r0
 *   @0x2389f0 ldr r2, [sp, #0x44c]
 *   @0x2389f4 mov r0, r4
 *   @0x2389f8 ldr r3, [r5]
 *   @0x2389fc cmp r2, r3
 *   @0x238a00 bne 0x238bf0 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0x2a4>
 *   @0x238a04 add sp, sp, #1104
 *   @0x238a08 add sp, sp, #4
 *   @0x238a0c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x238a10 ldr r2, [r11, #0x20]
 *   @0x238a14 vldr s14, [r4, #160]
 *   @0x238a18 vldr s15, [r2, #16]
 *   @0x238a1c vcmpe.f32 s15, #0
 *   @0x238a20 vldr s15, [pc, #460]
 *   @0x238a24 add r12, sp, #28
 *   @0x238a28 str r12, [sp, #0x4]
 *   @0x238a2c add r12, sp, #32
 *   @0x238a30 ldr lr, [r11, #0x4]
 *   @0x238a34 mov r1, #1065353216
 *   @0x238a38 vnmul.f32 s15, s14, s15
 *   @0x238a3c vldr s14, [pc, #436]
 *   @0x238a40 vmrs APSR_nzcv, fpscr
 *   @0x238a44 ldr r0, [r11]
 *   @0x238a48 strb r3, [sp, #0x3e]
 *   @0x238a4c mov r2, #1
 *   @0x238a50 strb r3, [sp, #0x3f]
 *   @0x238a54 mov r3, #0
 *   @0x238a58 str r1, [sp, #0x48]
 *   @0x238a5c str r3, [r12]
 *   @0x238a60 str r3, [sp, #0x1c]
 *   @0x238a64 str r3, [sp, #0x28]
 *   @0x238a68 str r3, [sp, #0x2c]
 *   @0x238a6c str r3, [sp, #0x30]
 *   @0x238a70 movgt r3, #2
 *   @0x238a74 ldrble r3, [r11, #0x18]
 *   @0x238a78 ldrb r1, [r11, #0x8]
 *   @0x238a7c add r11, sp, #2048
 *   @0x238a80 vdiv.f32 s15, s15, s14
 *   @0x238a84 strb r2, [sp, #0x3c]
 *   @0x238a88 strb r2, [sp, #0x40]
 *   @0x238a8c add r2, sp, #16
 *   @0x238a90 str lr, [sp, #0x38]
 *   @0x238a94 ldr lr, [r11, #-0x388]
 *   @0x238a98 mov r9, r2
 *   @0x238a9c str r10, [r9], #-8
 *   @0x238aa0 mov r11, #0
 *   @0x238aa4 str r3, [sp, #0x18]
 *   @0x238aa8 mov r3, r9
 *   @0x238aac strb r1, [sp, #0x3d]
 *   @0x238ab0 str r0, [sp, #0x34]
 *   @0x238ab4 mov r0, r7
 *   @0x238ab8 str lr, [sp, #0x14]
 *   @0x238abc str r4, [sp, #0x44]
 *   @0x238ac0 str r12, [sp]
 *   @0x238ac4 vmov r1, s15
 *   @0x238ac8 vstr s15, [sp, #36]
 *   @0x238acc bl 0x2380b4 <_ZN13CPhysicsWorld17ApplyVisualOffsetEfRK6b2Vec2RS0_>
 *   @0x238ad0 vldr s15, [sp, #12]
 *   @0x238ad4 vldr s14, [r4, #184]
 *   @0x238ad8 vsub.f32 s14, s14, s15
 *   @0x238adc vldr s15, [r7, #96]
 *   @0x238ae0 vldr s12, [r4, #180]
 *   @0x238ae4 vldr s13, [r9]
 *   @0x238ae8 ldr r12, [sp]
 *   @0x238aec ldr r0, [r7, #0x10]
 *   @0x238af0 mov r1, r12
 *   @0x238af4 vmul.f32 s14, s15, s14
 *   @0x238af8 vsub.f32 s13, s12, s13
 *   @0x238afc vmov r2, s14
 *   @0x238b00 vmul.f32 s15, s13, s15
 *   @0x238b04 str r2, [r1], #-8
 *   @0x238b08 vstr s15, [sp, #28]
 *   @0x238b0c bl 0x2c903c <_ZN7b2World10CreateBodyEPK9b2BodyDef>
 *   @0x238b10 mov r1, r6
 *   @0x238b14 str r0, [sp]
 *   @0x238b18 bl 0x2c6dfc <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef>
 *   @0x238b1c mov r9, r0
 *   @0x238b20 mov r0, #32
 *   @0x238b24 bl 0x27c524 <_Znwj>
 *   @0x238b28 ldr r3, [sp]
 *   @0x238b2c add r12, sp, #2048
 *   @0x238b30 ldr r2, [r3, #0xc]
 *   @0x238b34 str r3, [r0]
 *   @0x238b38 mov r6, r0
 *   @0x238b3c ldr r3, [r3, #0x10]
 *   @0x238b40 str r8, [r0, #0x14]
 *   @0x238b44 str r11, [r0, #0x18]
 *   @0x238b48 str r3, [r0, #0x10]
 *   @0x238b4c ldr r3, [r12, #-0x388]
 *   @0x238b50 str r2, [r0, #0xc]
 *   @0x238b54 str r10, [r0, #0x4]
 *   @0x238b58 mov r0, #12
 *   @0x238b5c str r3, [r6, #0x8]
 *   @0x238b60 bl 0x27c524 <_Znwj>
 *   @0x238b64 ldr r1, [pc, #0x94]
 *   @0x238b68 mov r3, #15
 *   @0x238b6c mov r2, #187
 *   @0x238b70 add r1, pc, r1
 *   @0x238b74 mov r8, r0
 *   @0x238b78 str r11, [r0, #0x8]
 *   @0x238b7c str r3, [r8, #0x4]
 *   @0x238b80 mov r0, #128
 *   @0x238b84 mov r3, #1
 *   @0x238b88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x238b8c mov r1, r11
 *   @0x238b90 mov r2, #128
 *   @0x238b94 str r0, [r8]
 *   @0x238b98 bl 0xb65b0 <memset@plt>
 *   @0x238b9c str r8, [r6, #0x1c]
 *   @0x238ba0 mov r0, r6
 *   @0x238ba4 str r6, [r4, #0x84]
 *   @0x238ba8 mov r1, r9
 *   @0x238bac bl 0x237708 <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture>
 *   @0x238bb0 mov r4, r0
 *   @0x238bb4 mov r0, r7
 *   @0x238bb8 bl 0x2388a4 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv>
 *   @0x238bbc b 0x2389f0 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0xa4>
 *   @0x238bc0 ldr r3, [r4, #0x80]
 *   @0x238bc4 add r6, sp, #76
 *   @0x238bc8 ldr r1, [pc, #0x34]
 *   @0x238bcc mvn r4, #0
 *   @0x238bd0 mov r0, r6
 *   @0x238bd4 add r1, pc, r1
 *   @0x238bd8 ldr r2, [r3, #0x14]
 *   @0x238bdc bl 0xb6550 <sprintf@plt>
 *   @0x238be0 mov r0, r6
 *   @0x238be4 mov r1, #1
 *   @0x238be8 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x238bec b 0x2389f0 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0xa4>
 *   @0x238bf0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x238bf4 ldrdmi r0, r1, [r9], #-251
 *   @0x238bf8 teqmi r4, #0
 *   @0x238bfc andseq r4, r11, r12, ror #31
 *   @0x238c00 andseq r4, r1, r12, lsr r1
 *   @0x238c04 andseq r12, r1, r12, ror #13
 *
 * ══ §26/42 F_DsQueueDequeue  0x101d8c  size 696  174 条（0x101d8c..0x102044）
 * @func 0x101d8c 0x102044  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_DsQueueDequeue(RValue&, CInstance*, CInstance*, int, RValue*)+0x108 / CDS_Queue::Dequeue() / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×5 / 0x18×1 / 0x288×1 / 0x278×1 / 0x2×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101d8c push {r3, r4, r5, r6, r7, lr}
 *   @0x101d90 mov r1, #0
 *   @0x101d94 mov r4, r0
 *   @0x101d98 ldr r0, [sp, #0x18]
 *   @0x101d9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x101da0 cmp r0, #0
 *   @0x101da4 blt 0x101e94 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x101da8 ldr r3, [pc, #0x288]
 *   @0x101dac ldr r3, [pc, r3]
 *   @0x101db0 ldr r3, [r3]
 *   @0x101db4 cmp r0, r3
 *   @0x101db8 bge 0x101e94 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x101dbc ldr r3, [pc, #0x278]
 *   @0x101dc0 ldr r3, [pc, r3]
 *   @0x101dc4 ldr r3, [r3, #0x4]
 *   @0x101dc8 ldr r0, [r3, r0, lsl #2]
 *   @0x101dcc cmp r0, #0
 *   @0x101dd0 beq 0x101e94 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x101dd4 bl 0x205ab0 <_ZN9CDS_Queue7DequeueEv>
 *   @0x101dd8 subs r5, r0, #0
 *   @0x101ddc streq r5, [r4]
 *   @0x101de0 streq r5, [r4, #0x4]
 *   @0x101de4 moveq r3, #5
 *   @0x101de8 streq r3, [r4, #0xc]
 *   @0x101dec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x101df0 ldr r2, [r4, #0xc]
 *   @0x101df4 bic r3, r2, #-16777216
 *   @0x101df8 cmp r3, #1
 *   @0x101dfc beq 0x101ec0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x101e00 cmp r3, #2
 *   @0x101e04 bne 0x101e2c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x101e08 sub r2, r2, #1
 *   @0x101e0c bic r2, r2, #-16777216
 *   @0x101e10 bic r2, r2, #3
 *   @0x101e14 cmp r2, #0
 *   @0x101e18 beq 0x101f94 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x101e1c mov r2, #0
 *   @0x101e20 mov r3, #5
 *   @0x101e24 str r2, [r4, #0x8]
 *   @0x101e28 str r3, [r4, #0xc]
 *   @0x101e2c ldr r3, [r5, #0xc]
 *   @0x101e30 mov r1, #0
 *   @0x101e34 ldr r2, [r5, #0x8]
 *   @0x101e38 str r1, [r4]
 *   @0x101e3c str r3, [r4, #0xc]
 *   @0x101e40 ldr r3, [r5, #0xc]
 *   @0x101e44 str r2, [r4, #0x8]
 *   @0x101e48 bic r3, r3, #-16777216
 *   @0x101e4c cmp r3, #14
 *   @0x101e50 addls pc, pc, r3, lsl #2
 *   @0x101e54 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x101e58 b 0x101eb4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x101e5c b 0x101f18 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x101e60 b 0x101f30 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x101e64 b 0x101ea8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x101e68 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x101e6c b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x101e70 b 0x101ef4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x101e74 b 0x101ea8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x101e78 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x101e7c b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x101e80 b 0x101eb4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x101e84 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x101e88 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x101e8c b 0x101eb4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x101e90 b 0x101ea8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x101e94 ldr r0, [pc, #0x1a4]
 *   @0x101e98 mov r1, #0
 *   @0x101e9c pop {r3, r4, r5, r6, r7, lr}
 *   @0x101ea0 add r0, pc, r0
 *   @0x101ea4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x101ea8 ldr r3, [r5]
 *   @0x101eac str r3, [r4]
 *   @0x101eb0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x101eb4 ldm r5, {r2, r3}
 *   @0x101eb8 stm r4, {r2, r3}
 *   @0x101ebc pop {r3, r4, r5, r6, r7, pc}
 *   @0x101ec0 ldr r6, [r4]
 *   @0x101ec4 cmp r6, #0
 *   @0x101ec8 beq 0x101ee8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x101ecc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x101ed0 ldr r7, [r6, #0x4]
 *   @0x101ed4 sub r7, r7, #1
 *   @0x101ed8 str r7, [r6, #0x4]
 *   @0x101edc cmp r7, #0
 *   @0x101ee0 beq 0x101f5c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x101ee4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x101ee8 mov r3, #0
 *   @0x101eec str r3, [r4]
 *   @0x101ef0 b 0x101e2c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x101ef4 ldr r3, [r5]
 *   @0x101ef8 str r3, [r4]
 *   @0x101efc ldr r3, [r5]
 *   @0x101f00 cmp r3, #0
 *   @0x101f04 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x101f08 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x101f0c ldr r1, [r5]
 *   @0x101f10 pop {r3, r4, r5, r6, r7, lr}
 *   @0x101f14 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x101f18 ldr r3, [r5]
 *   @0x101f1c cmp r3, #0
 *   @0x101f20 ldrne r2, [r3, #0x4]
 *   @0x101f24 addne r2, r2, #1
 *   @0x101f28 strne r2, [r3, #0x4]
 *   @0x101f2c b 0x101eac <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x101f30 ldr r3, [r5]
 *   @0x101f34 cmp r3, #0
 *   @0x101f38 str r3, [r4]
 *   @0x101f3c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x101f40 ldr r1, [r3, #0x8]
 *   @0x101f44 ldr r2, [r3]
 *   @0x101f48 cmp r1, #0
 *   @0x101f4c streq r4, [r3, #0x8]
 *   @0x101f50 add r2, r2, #1
 *   @0x101f54 str r2, [r3]
 *   @0x101f58 pop {r3, r4, r5, r6, r7, pc}
 *   @0x101f5c ldr r0, [r6]
 *   @0x101f60 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x101f64 str r7, [r6]
 *   @0x101f68 str r7, [r6, #0x8]
 *   @0x101f6c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x101f70 ldr r7, [r6, #0x4]
 *   @0x101f74 sub r7, r7, #1
 *   @0x101f78 str r7, [r6, #0x4]
 *   @0x101f7c cmp r7, #0
 *   @0x101f80 beq 0x101fa0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x101f84 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x101f88 mov r0, r6
 *   @0x101f8c bl 0x27d1d0 <_ZdlPv>
 *   @0x101f90 b 0x101ee4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x101f94 mov r0, r4
 *   @0x101f98 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x101f9c b 0x101e1c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x101fa0 ldr r0, [r6]
 *   @0x101fa4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x101fa8 str r7, [r6]
 *   @0x101fac str r7, [r6, #0x8]
 *   @0x101fb0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x101fb4 ldr r7, [r6, #0x4]
 *   @0x101fb8 sub r7, r7, #1
 *   @0x101fbc str r7, [r6, #0x4]
 *   @0x101fc0 cmp r7, #0
 *   @0x101fc4 beq 0x101fd8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x101fc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x101fcc mov r0, r6
 *   @0x101fd0 bl 0x27d1d0 <_ZdlPv>
 *   @0x101fd4 b 0x101f84 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x101fd8 ldr r0, [r6]
 *   @0x101fdc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x101fe0 str r7, [r6]
 *   @0x101fe4 str r7, [r6, #0x8]
 *   @0x101fe8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x101fec ldr r3, [r6, #0x4]
 *   @0x101ff0 sub r3, r3, #1
 *   @0x101ff4 str r3, [r6, #0x4]
 *   @0x101ff8 cmp r3, #0
 *   @0x101ffc beq 0x102010 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x102000 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102004 mov r0, r6
 *   @0x102008 bl 0x27d1d0 <_ZdlPv>
 *   @0x10200c b 0x101fc8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x102010 ldr r0, [r6]
 *   @0x102014 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102018 mov r3, #0
 *   @0x10201c mov r0, r6
 *   @0x102020 str r3, [r6]
 *   @0x102024 str r3, [r6, #0x8]
 *   @0x102028 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x10202c mov r0, r6
 *   @0x102030 bl 0x27d1d0 <_ZdlPv>
 *   @0x102034 b 0x102000 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x102038 eoreq r12, lr, r0, asr #1
 *   @0x10203c strhteq r12, [lr], -r0
 *   @0x102040 eoreq r5, r3, r12, asr sp
 *
 * ══ §27/42 Script_Prepare  0x1e0af0  size 696  174 条（0x1e0af0..0x1e0da8）
 * @func 0x1e0af0 0x1e0da8  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1e0b08→0x544c68, 0x1e0b2c→0x544c70, 0x1e0b68→0x544b44, 0x1e0b84→0x544be0, 0x1e0b8c→0x544b40, 0x1e0c08→0x47f295, 0x1e0c1c→0x757e72, 0x1e0c30→0x757e48
 * 调用序列: 0xb6538×2 / Script_Prepare()+0x78 / CScript::Compile() / Script_Prepare()+0x118 / operator new(unsigned int) / CCode::CCode(int, bool) / Code_Execute(CInstance*, CInstance*, CCode*, RValue*, int) / TickDebugger()
 * 字段偏移 top8: 0x4×3 / 0x-54×2 / 0x-28×2 / 0x2×2 / 0x-50×2 / 0x6c×2 / 0x274×1 / 0x270×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0af0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e0af4 add r11, sp, #32
 *   @0x1e0af8 ldr r5, [pc, #0x274]
 *   @0x1e0afc sub sp, sp, #60
 *   @0x1e0b00 ldr r2, [pc, #0x270]
 *   @0x1e0b04 add r5, pc, r5
 *   @0x1e0b08 ldr r3, [pc, #0x26c]
 *   @0x1e0b0c ldr r2, [r5, r2]
 *   @0x1e0b10 str r2, [r11, #-0x54]
 *   @0x1e0b14 ldr r2, [r2]
 *   @0x1e0b18 str r2, [r11, #-0x28]
 *   @0x1e0b1c ldr r6, [r5, r3]
 *   @0x1e0b20 ldr r3, [r6]
 *   @0x1e0b24 cmp r3, #0
 *   @0x1e0b28 ble 0x1e0b68 <_Z14Script_Preparev+0x78>
 *   @0x1e0b2c ldr r3, [pc, #0x24c]
 *   @0x1e0b30 mov r4, #0
 *   @0x1e0b34 ldr r8, [r5, r3]
 *   @0x1e0b38 ldr r3, [r8, #0x4]
 *   @0x1e0b3c lsl r7, r4, #2
 *   @0x1e0b40 ldr r0, [r3, r4, lsl #2]
 *   @0x1e0b44 cmp r0, #0
 *   @0x1e0b48 beq 0x1e0b58 <_Z14Script_Preparev+0x68>
 *   @0x1e0b4c bl 0x1dfe10 <_ZN7CScript7CompileEv>
 *   @0x1e0b50 subs r9, r0, #0
 *   @0x1e0b54 beq 0x1e0cf8 <_Z14Script_Preparev+0x208>
 *   @0x1e0b58 ldr r3, [r6]
 *   @0x1e0b5c add r4, r4, #1
 *   @0x1e0b60 cmp r3, r4
 *   @0x1e0b64 bgt 0x1e0b38 <_Z14Script_Preparev+0x48>
 *   @0x1e0b68 ldr r3, [pc, #0x214]
 *   @0x1e0b6c mov r2, #5
 *   @0x1e0b70 str r2, [r11, #-0x3c]
 *   @0x1e0b74 ldr r6, [r5, r3]
 *   @0x1e0b78 ldr r3, [r6]
 *   @0x1e0b7c cmp r3, #0
 *   @0x1e0b80 ble 0x1e0c08 <_Z14Script_Preparev+0x118>
 *   @0x1e0b84 ldr r3, [pc, #0x1fc]
 *   @0x1e0b88 sub r10, r11, #72
 *   @0x1e0b8c ldr r2, [pc, #0x1f8]
 *   @0x1e0b90 mov r7, #0
 *   @0x1e0b94 ldr r3, [r5, r3]
 *   @0x1e0b98 ldr r8, [r5, r2]
 *   @0x1e0b9c str r3, [r11, #-0x50]
 *   @0x1e0ba0 ldr r3, [r8]
 *   @0x1e0ba4 mov r0, #124
 *   @0x1e0ba8 ldr r9, [r3, r7, lsl #2]
 *   @0x1e0bac bl 0x27c524 <_Znwj>
 *   @0x1e0bb0 mov r2, #0
 *   @0x1e0bb4 mov r1, r9
 *   @0x1e0bb8 mov r4, r0
 *   @0x1e0bbc bl 0xcefc8 <_ZN5CCodeC2Eib>
 *   @0x1e0bc0 ldr r1, [r11, #-0x50]
 *   @0x1e0bc4 mov r3, #0
 *   @0x1e0bc8 mov r2, r4
 *   @0x1e0bcc ldr r0, [r1]
 *   @0x1e0bd0 str r3, [sp]
 *   @0x1e0bd4 mov r3, r10
 *   @0x1e0bd8 mov r1, r0
 *   @0x1e0bdc bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei>
 *   @0x1e0be0 cmp r4, #0
 *   @0x1e0be4 beq 0x1e0bf8 <_Z14Script_Preparev+0x108>
 *   @0x1e0be8 ldr r3, [r4]
 *   @0x1e0bec mov r0, r4
 *   @0x1e0bf0 ldr r3, [r3, #0x4]
 *   @0x1e0bf4 blx r3
 *   @0x1e0bf8 ldr r3, [r6]
 *   @0x1e0bfc add r7, r7, #1
 *   @0x1e0c00 cmp r3, r7
 *   @0x1e0c04 bgt 0x1e0ba0 <_Z14Script_Preparev+0xb0>
 *   @0x1e0c08 ldr r3, [pc, #0x180]
 *   @0x1e0c0c ldr r3, [r5, r3]
 *   @0x1e0c10 ldrb r3, [r3]
 *   @0x1e0c14 cmp r3, #0
 *   @0x1e0c18 beq 0x1e0cd4 <_Z14Script_Preparev+0x1e4>
 *   @0x1e0c1c ldr r3, [pc, #0x170]
 *   @0x1e0c20 ldr r4, [r5, r3]
 *   @0x1e0c24 ldrb r3, [r4]
 *   @0x1e0c28 cmp r3, #0
 *   @0x1e0c2c beq 0x1e0c54 <_Z14Script_Preparev+0x164>
 *   @0x1e0c30 ldr r3, [pc, #0x160]
 *   @0x1e0c34 ldr r6, [r5, r3]
 *   @0x1e0c38 bl 0x29d770 <_Z12TickDebuggerv>
 *   @0x1e0c3c ldrb r3, [r4]
 *   @0x1e0c40 cmp r3, #0
 *   @0x1e0c44 bne 0x1e0c38 <_Z14Script_Preparev+0x148>
 *   @0x1e0c48 ldrb r3, [r6]
 *   @0x1e0c4c cmp r3, #0
 *   @0x1e0c50 beq 0x1e0c38 <_Z14Script_Preparev+0x148>
 *   @0x1e0c54 bl 0x1e0530 <_Z13Script_Numberv>
 *   @0x1e0c58 mov r4, #0
 *   @0x1e0c5c mvn r3, #-16777216
 *   @0x1e0c60 str r4, [r11, #-0x38]
 *   @0x1e0c64 str r4, [r11, #-0x34]
 *   @0x1e0c68 str r4, [r11, #-0x30]
 *   @0x1e0c6c str r3, [r11, #-0x2c]
 *   @0x1e0c70 subs r6, r0, #0
 *   @0x1e0c74 subgt r7, r11, #56
 *   @0x1e0c78 bgt 0x1e0c8c <_Z14Script_Preparev+0x19c>
 *   @0x1e0c7c b 0x1e0cd4 <_Z14Script_Preparev+0x1e4>
 *   @0x1e0c80 add r4, r4, #1
 *   @0x1e0c84 cmp r4, r6
 *   @0x1e0c88 beq 0x1e0cd4 <_Z14Script_Preparev+0x1e4>
 *   @0x1e0c8c mov r0, r4
 *   @0x1e0c90 bl 0x1e069c <_Z11Script_Datai>
 *   @0x1e0c94 bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x1e0c98 ldr r2, [r0, #0x6c]
 *   @0x1e0c9c cmp r2, #0
 *   @0x1e0ca0 bne 0x1e0c80 <_Z14Script_Preparev+0x190>
 *   @0x1e0ca4 ldr r1, [pc, #0xdc]
 *   @0x1e0ca8 mov r3, r2
 *   @0x1e0cac mov r0, r4
 *   @0x1e0cb0 add r4, r4, #1
 *   @0x1e0cb4 ldr r1, [r5, r1]
 *   @0x1e0cb8 str r2, [sp, #0x4]
 *   @0x1e0cbc str r7, [sp]
 *   @0x1e0cc0 ldr r1, [r1]
 *   @0x1e0cc4 mov r2, r1
 *   @0x1e0cc8 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x1e0ccc cmp r4, r6
 *   @0x1e0cd0 bne 0x1e0c8c <_Z14Script_Preparev+0x19c>
 *   @0x1e0cd4 mov r9, #1
 *   @0x1e0cd8 ldr r1, [r11, #-0x54]
 *   @0x1e0cdc mov r0, r9
 *   @0x1e0ce0 ldr r2, [r11, #-0x28]
 *   @0x1e0ce4 ldr r3, [r1]
 *   @0x1e0ce8 cmp r2, r3
 *   @0x1e0cec bne 0x1e0d70 <_Z14Script_Preparev+0x280>
 *   @0x1e0cf0 sub sp, r11, #32
 *   @0x1e0cf4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e0cf8 ldr r3, [pc, #0x9c]
 *   @0x1e0cfc ldr r3, [r5, r3]
 *   @0x1e0d00 ldr r3, [r3]
 *   @0x1e0d04 ldr r6, [r3]
 *   @0x1e0d08 mov r0, r6
 *   @0x1e0d0c bl 0xb6538 <strlen@plt>
 *   @0x1e0d10 ldr r3, [pc, #0x88]
 *   @0x1e0d14 ldr r3, [r5, r3]
 *   @0x1e0d18 ldr r3, [r3]
 *   @0x1e0d1c ldr r4, [r3, r7]
 *   @0x1e0d20 mov r8, r0
 *   @0x1e0d24 mov r0, r4
 *   @0x1e0d28 bl 0xb6538 <strlen@plt>
 *   @0x1e0d2c mov r3, r4
 *   @0x1e0d30 ldr r2, [pc, #0x6c]
 *   @0x1e0d34 add r2, pc, r2
 *   @0x1e0d38 add r0, r8, r0
 *   @0x1e0d3c add r1, r0, #34
 *   @0x1e0d40 lsl r1, r1, #1
 *   @0x1e0d44 add r0, r1, #14
 *   @0x1e0d48 bic r0, r0, #7
 *   @0x1e0d4c sub sp, sp, r0
 *   @0x1e0d50 add r4, sp, #8
 *   @0x1e0d54 str r6, [sp]
 *   @0x1e0d58 mov r0, r4
 *   @0x1e0d5c bl 0xb65c8 <snprintf@plt>
 *   @0x1e0d60 mov r0, r4
 *   @0x1e0d64 mov r1, #1
 *   @0x1e0d68 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1e0d6c b 0x1e0cd8 <_Z14Script_Preparev+0x1e8>
 *   @0x1e0d70 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1e0d74 eoreq r1, r1, r12, asr #2
 *   @0x1e0d78 .word 0xffffbd00
 *   @0x1e0d7c .word 0xfffff0dc
 *   @0x1e0d80 .word 0xfffff0d8
 *   @0x1e0d84 .word 0xfffff058
 *   @0x1e0d88 .word 0xffffbf64
 *   @0x1e0d8c .word 0xfffff054
 *   @0x1e0d90 .word 0xffffbf68
 *   @0x1e0d94 .word 0xffffdf9c
 *   @0x1e0d98 .word 0xfffff0ec
 *   @0x1e0d9c .word 0xffffbf20
 *   @0x1e0da0 .word 0xfffff0e0
 *   @0x1e0da4 andseq r1, r7, r12, lsl r0
 *
 * ══ §28/42 __subdf3  0x318e14  size 688  172 条（0x318e14..0x3190c4）
 * @func 0x318e14 0x3190c4  size 688  172 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_dadd+0x54 / __aeabi_dadd+0xbc / __aeabi_dadd+0x130 / __aeabi_dadd+0x118 / __aeabi_dadd+0x184
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x318e14 eor r3, r3, #-2147483648
 *   @0x318e18 push {r4, r5, lr}
 *   @0x318e1c lsl r4, r1, #1
 *   @0x318e20 lsl r5, r3, #1
 *   @0x318e24 teq r4, r5
 *   @0x318e28 teqeq r0, r2
 *   @0x318e2c orrsne r12, r4, r0
 *   @0x318e30 orrsne r12, r5, r2
 *   @0x318e34 mvnsne r12, r4, asr #21
 *   @0x318e38 mvnsne r12, r5, asr #21
 *   @0x318e3c beq 0x319028 <__aeabi_dadd+0x210>
 *   @0x318e40 lsr r4, r4, #21
 *   @0x318e44 rsbs r5, r4, r5, lsr #21
 *   @0x318e48 rsblt r5, r5, #0
 *   @0x318e4c ble 0x318e6c <__aeabi_dadd+0x54>
 *   @0x318e50 add r4, r4, r5
 *   @0x318e54 eor r2, r0, r2
 *   @0x318e58 eor r3, r1, r3
 *   @0x318e5c eor r0, r2, r0
 *   @0x318e60 eor r1, r3, r1
 *   @0x318e64 eor r2, r0, r2
 *   @0x318e68 eor r3, r1, r3
 *   @0x318e6c cmp r5, #54
 *   @0x318e70 pophi {r4, r5, pc}
 *   @0x318e74 tst r1, #-2147483648
 *   @0x318e78 lsl r1, r1, #12
 *   @0x318e7c mov r12, #1048576
 *   @0x318e80 orr r1, r12, r1, lsr #12
 *   @0x318e84 beq 0x318e90 <__aeabi_dadd+0x78>
 *   @0x318e88 rsbs r0, r0, #0
 *   @0x318e8c rsc r1, r1, #0
 *   @0x318e90 tst r3, #-2147483648
 *   @0x318e94 lsl r3, r3, #12
 *   @0x318e98 orr r3, r12, r3, lsr #12
 *   @0x318e9c beq 0x318ea8 <__aeabi_dadd+0x90>
 *   @0x318ea0 rsbs r2, r2, #0
 *   @0x318ea4 rsc r3, r3, #0
 *   @0x318ea8 teq r4, r5
 *   @0x318eac beq 0x319010 <__aeabi_dadd+0x1f8>
 *   @0x318eb0 sub r4, r4, #1
 *   @0x318eb4 rsbs lr, r5, #32
 *   @0x318eb8 blt 0x318ed4 <__aeabi_dadd+0xbc>
 *   @0x318ebc lsl r12, r2, lr
 *   @0x318ec0 adds r0, r0, r2, lsr r5
 *   @0x318ec4 adc r1, r1, #0
 *   @0x318ec8 adds r0, r0, r3, lsl lr
 *   @0x318ecc adcs r1, r1, r3, asr r5
 *   @0x318ed0 b 0x318ef0 <__aeabi_dadd+0xd8>
 *   @0x318ed4 sub r5, r5, #32
 *   @0x318ed8 add lr, lr, #32
 *   @0x318edc cmp r2, #1
 *   @0x318ee0 lsl r12, r3, lr
 *   @0x318ee4 orrhs r12, r12, #2
 *   @0x318ee8 adds r0, r0, r3, asr r5
 *   @0x318eec adcs r1, r1, r3, asr #31
 *   @0x318ef0 and r5, r1, #-2147483648
 *   @0x318ef4 bpl 0x318f04 <__aeabi_dadd+0xec>
 *   @0x318ef8 rsbs r12, r12, #0
 *   @0x318efc rscs r0, r0, #0
 *   @0x318f00 rsc r1, r1, #0
 *   @0x318f04 cmp r1, #1048576
 *   @0x318f08 blo 0x318f48 <__aeabi_dadd+0x130>
 *   @0x318f0c cmp r1, #2097152
 *   @0x318f10 blo 0x318f30 <__aeabi_dadd+0x118>
 *   @0x318f14 lsrs r1, r1, #1
 *   @0x318f18 rrxs r0, r0
 *   @0x318f1c rrx r12, r12
 *   @0x318f20 add r4, r4, #1
 *   @0x318f24 lsl r2, r4, #21
 *   @0x318f28 cmn r2, #4194304
 *   @0x318f2c bhs 0x319088 <__aeabi_dadd+0x270>
 *   @0x318f30 cmp r12, #-2147483648
 *   @0x318f34 lsrseq r12, r0, #1
 *   @0x318f38 adcs r0, r0, #0
 *   @0x318f3c adc r1, r1, r4, lsl #20
 *   @0x318f40 orr r1, r1, r5
 *   @0x318f44 pop {r4, r5, pc}
 *   @0x318f48 lsls r12, r12, #1
 *   @0x318f4c adcs r0, r0, r0
 *   @0x318f50 adc r1, r1, r1
 *   @0x318f54 tst r1, #1048576
 *   @0x318f58 sub r4, r4, #1
 *   @0x318f5c bne 0x318f30 <__aeabi_dadd+0x118>
 *   @0x318f60 teq r1, #0
 *   @0x318f64 moveq r1, r0
 *   @0x318f68 moveq r0, #0
 *   @0x318f6c clz r3, r1
 *   @0x318f70 addeq r3, r3, #32
 *   @0x318f74 sub r3, r3, #11
 *   @0x318f78 subs r2, r3, #32
 *   @0x318f7c bge 0x318fa0 <__aeabi_dadd+0x188>
 *   @0x318f80 adds r2, r2, #12
 *   @0x318f84 ble 0x318f9c <__aeabi_dadd+0x184>
 *   @0x318f88 add r12, r2, #20
 *   @0x318f8c rsb r2, r2, #12
 *   @0x318f90 lsl r0, r1, r12
 *   @0x318f94 lsr r1, r1, r2
 *   @0x318f98 b 0x318fb0 <__aeabi_dadd+0x198>
 *   @0x318f9c add r2, r2, #20
 *   @0x318fa0 rsble r12, r2, #32
 *   @0x318fa4 lsl r1, r1, r2
 *   @0x318fa8 orrle r1, r1, r0, lsr r12
 *   @0x318fac lslle r0, r0, r2
 *   @0x318fb0 subs r4, r4, r3
 *   @0x318fb4 addge r1, r1, r4, lsl #20
 *   @0x318fb8 orrge r1, r1, r5
 *   @0x318fbc popge {r4, r5, pc}
 *   @0x318fc0 mvn r4, r4
 *   @0x318fc4 subs r4, r4, #31
 *   @0x318fc8 bge 0x319004 <__aeabi_dadd+0x1ec>
 *   @0x318fcc adds r4, r4, #12
 *   @0x318fd0 bgt 0x318fec <__aeabi_dadd+0x1d4>
 *   @0x318fd4 add r4, r4, #20
 *   @0x318fd8 rsb r2, r4, #32
 *   @0x318fdc lsr r0, r0, r4
 *   @0x318fe0 orr r0, r0, r1, lsl r2
 *   @0x318fe4 orr r1, r5, r1, lsr r4
 *   @0x318fe8 pop {r4, r5, pc}
 *   @0x318fec rsb r4, r4, #12
 *   @0x318ff0 rsb r2, r4, #32
 *   @0x318ff4 lsr r0, r0, r2
 *   @0x318ff8 orr r0, r0, r1, lsl r4
 *   @0x318ffc mov r1, r5
 *   @0x319000 pop {r4, r5, pc}
 *   @0x319004 lsr r0, r1, r4
 *   @0x319008 mov r1, r5
 *   @0x31900c pop {r4, r5, pc}
 *   @0x319010 teq r4, #0
 *   @0x319014 eor r3, r3, #1048576
 *   @0x319018 eoreq r1, r1, #1048576
 *   @0x31901c addeq r4, r4, #1
 *   @0x319020 subne r5, r5, #1
 *   @0x319024 b 0x318eb0 <__aeabi_dadd+0x98>
 *   @0x319028 mvns r12, r4, asr #21
 *   @0x31902c mvnsne r12, r5, asr #21
 *   @0x319030 beq 0x319098 <__aeabi_dadd+0x280>
 *   @0x319034 teq r4, r5
 *   @0x319038 teqeq r0, r2
 *   @0x31903c beq 0x319050 <__aeabi_dadd+0x238>
 *   @0x319040 orrs r12, r4, r0
 *   @0x319044 moveq r1, r3
 *   @0x319048 moveq r0, r2
 *   @0x31904c pop {r4, r5, pc}
 *   @0x319050 teq r1, r3
 *   @0x319054 movne r1, #0
 *   @0x319058 movne r0, #0
 *   @0x31905c popne {r4, r5, pc}
 *   @0x319060 lsrs r12, r4, #21
 *   @0x319064 bne 0x319078 <__aeabi_dadd+0x260>
 *   @0x319068 lsls r0, r0, #1
 *   @0x31906c adcs r1, r1, r1
 *   @0x319070 orrhs r1, r1, #-2147483648
 *   @0x319074 pop {r4, r5, pc}
 *   @0x319078 adds r4, r4, #4194304
 *   @0x31907c addlo r1, r1, #1048576
 *   @0x319080 poplo {r4, r5, pc}
 *   @0x319084 and r5, r1, #-2147483648
 *   @0x319088 orr r1, r5, #2130706432
 *   @0x31908c orr r1, r1, #15728640
 *   @0x319090 mov r0, #0
 *   @0x319094 pop {r4, r5, pc}
 *   @0x319098 mvns r12, r4, asr #21
 *   @0x31909c movne r1, r3
 *   @0x3190a0 movne r0, r2
 *   @0x3190a4 mvnseq r12, r5, asr #21
 *   @0x3190a8 movne r3, r1
 *   @0x3190ac movne r2, r0
 *   @0x3190b0 orrs r4, r0, r1, lsl #12
 *   @0x3190b4 orrseq r5, r2, r3, lsl #12
 *   @0x3190b8 teqeq r1, r3
 *   @0x3190bc orrne r1, r1, #524288
 *   @0x3190c0 pop {r4, r5, pc}
 *
 * ══ §29/42 Push_DispatchEvents  0x155bf8  size 676  167 条（0x155bf8..0x155e9c）
 * @func 0x155bf8 0x155e9c  size 676  167 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x155c08→0x484a6c, 0x155c20→0x3eb70c, 0x155c7c→0x3f5254, 0x155d08→0x4836b0
 * 调用序列: CreateDsMap(int, ...)×3 / operator delete(void*)×2 / Mutex::Lock() / Mutex::Unlock() / DS_AutoMutex::DS_AutoMutex() / HandleWebEvent(int) / Push_DispatchEvents()+0x150 / CDS_Map::~CDS_Map()
 * 字段偏移 top8: 0x4×7 / 0x10×3 / 0x14×3 / 0x20×3 / 0x24c×2 / 0xc×2 / 0x1e4×2 / 0x1d8×2
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155bf8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x155bfc vpush {d8}
 *   @0x155c00 sub sp, sp, #68
 *   @0x155c04 ldr r6, [pc, #0x24c]
 *   @0x155c08 ldr r3, [pc, #0x24c]
 *   @0x155c0c add r6, pc, r6
 *   @0x155c10 ldr r5, [r6, r3]
 *   @0x155c14 ldr r3, [r5]
 *   @0x155c18 cmp r3, #0
 *   @0x155c1c beq 0x155e40 <_Z19Push_DispatchEventsv+0x248>
 *   @0x155c20 ldr r3, [pc, #0x238]
 *   @0x155c24 add r2, sp, #60
 *   @0x155c28 str r2, [sp, #0x34]
 *   @0x155c2c ldr r4, [pc, #0x230]
 *   @0x155c30 ldr r3, [r6, r3]
 *   @0x155c34 ldr r1, [pc, #0x22c]
 *   @0x155c38 add r4, pc, r4
 *   @0x155c3c ldr r0, [r3]
 *   @0x155c40 add r1, pc, r1
 *   @0x155c44 ldr r3, [r0]
 *   @0x155c48 ldr r3, [r3, #0xc]
 *   @0x155c4c blx r3
 *   @0x155c50 ldr r0, [r4, #0x4]
 *   @0x155c54 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x155c58 ldr r0, [r4, #0x4]
 *   @0x155c5c ldr r4, [r5]
 *   @0x155c60 mov r3, #0
 *   @0x155c64 str r3, [r5]
 *   @0x155c68 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x155c6c add r0, sp, #60
 *   @0x155c70 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x155c74 cmp r4, #0
 *   @0x155c78 beq 0x155e34 <_Z19Push_DispatchEventsv+0x23c>
 *   @0x155c7c ldr r3, [pc, #0x1e8]
 *   @0x155c80 vldr d8, [pc, #456]
 *   @0x155c84 ldr r7, [pc, #0x1e4]
 *   @0x155c88 ldr r10, [pc, #0x1e4]
 *   @0x155c8c ldr r5, [r6, r3]
 *   @0x155c90 add r7, pc, r7
 *   @0x155c94 ldr r9, [pc, #0x1dc]
 *   @0x155c98 add r10, pc, r10
 *   @0x155c9c ldr r3, [pc, #0x1d8]
 *   @0x155ca0 ldr r2, [pc, #0x1d8]
 *   @0x155ca4 add r9, pc, r9
 *   @0x155ca8 add r3, pc, r3
 *   @0x155cac str r3, [sp, #0x2c]
 *   @0x155cb0 add r2, pc, r2
 *   @0x155cb4 str r2, [sp, #0x30]
 *   @0x155cb8 b 0x155d70 <_Z19Push_DispatchEventsv+0x178>
 *   @0x155cbc ldr r2, [sp, #0x2c]
 *   @0x155cc0 mov r3, #0
 *   @0x155cc4 stm sp, {r1, r9}
 *   @0x155cc8 vstr d8, [sp, #24]
 *   @0x155ccc str r3, [sp, #0x10]
 *   @0x155cd0 mov r0, #3
 *   @0x155cd4 str r2, [sp, #0x14]
 *   @0x155cd8 mov r1, r10
 *   @0x155cdc str r12, [sp, #0x20]
 *   @0x155ce0 mov r2, #0
 *   @0x155ce4 mov r3, #0
 *   @0x155ce8 vstr d7, [sp, #8]
 *   @0x155cec bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x155cf0 str r0, [r5]
 *   @0x155cf4 mov r0, #71
 *   @0x155cf8 bl 0x1ce134 <_Z14HandleWebEventi>
 *   @0x155cfc ldr r3, [r5]
 *   @0x155d00 cmp r3, #0
 *   @0x155d04 blt 0x155d48 <_Z19Push_DispatchEventsv+0x150>
 *   @0x155d08 ldr r2, [pc, #0x174]
 *   @0x155d0c ldr r11, [r6, r2]
 *   @0x155d10 ldr r2, [r11, #0x4]
 *   @0x155d14 add r0, r2, r3, lsl #2
 *   @0x155d18 ldr r8, [r2, r3, lsl #2]
 *   @0x155d1c cmp r8, #0
 *   @0x155d20 beq 0x155d40 <_Z19Push_DispatchEventsv+0x148>
 *   @0x155d24 mov r0, r8
 *   @0x155d28 bl 0x20d9e8 <_ZN7CDS_MapD2Ev>
 *   @0x155d2c mov r0, r8
 *   @0x155d30 bl 0x27d1d0 <_ZdlPv>
 *   @0x155d34 ldr r0, [r5]
 *   @0x155d38 ldr r3, [r11, #0x4]
 *   @0x155d3c add r0, r3, r0, lsl #2
 *   @0x155d40 mov r3, #0
 *   @0x155d44 str r3, [r0]
 *   @0x155d48 ldr r11, [r4]
 *   @0x155d4c mov r0, r4
 *   @0x155d50 mvn r2, #0
 *   @0x155d54 str r2, [r5]
 *   @0x155d58 bl 0x155b80 <_ZN22SPushNotificationEventD2Ev>
 *   @0x155d5c mov r0, r4
 *   @0x155d60 bl 0x27d1d0 <_ZdlPv>
 *   @0x155d64 cmp r11, #0
 *   @0x155d68 beq 0x155e34 <_Z19Push_DispatchEventsv+0x23c>
 *   @0x155d6c mov r4, r11
 *   @0x155d70 ldr r2, [r4, #0x4]
 *   @0x155d74 mvn r1, #0
 *   @0x155d78 ldr r3, [r4, #0x8]
 *   @0x155d7c cmp r2, #0
 *   @0x155d80 str r1, [r5]
 *   @0x155d84 ldr r12, [r4, #0xc]
 *   @0x155d88 ldr r1, [r7, r3, lsl #2]
 *   @0x155d8c beq 0x155de8 <_Z19Push_DispatchEventsv+0x1f0>
 *   @0x155d90 vmov s13, r2
 *   @0x155d94 cmp r3, #0
 *   @0x155d98 vcvt.f64.s32 d7, s13
 *   @0x155d9c bne 0x155cbc <_Z19Push_DispatchEventsv+0xc4>
 *   @0x155da0 ldr lr, [pc, #0xe0]
 *   @0x155da4 vstr d8, [sp, #24]
 *   @0x155da8 ldr r2, [pc, #0xdc]
 *   @0x155dac mov r0, #3
 *   @0x155db0 add lr, pc, lr
 *   @0x155db4 str r1, [sp]
 *   @0x155db8 add r2, pc, r2
 *   @0x155dbc str r3, [sp, #0x10]
 *   @0x155dc0 str r2, [sp, #0x14]
 *   @0x155dc4 vstr d7, [sp, #8]
 *   @0x155dc8 ldr r1, [sp, #0x30]
 *   @0x155dcc mov r2, #0
 *   @0x155dd0 str r12, [sp, #0x20]
 *   @0x155dd4 mov r3, #0
 *   @0x155dd8 str lr, [sp, #0x4]
 *   @0x155ddc bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x155de0 str r0, [r5]
 *   @0x155de4 b 0x155cf4 <_Z19Push_DispatchEventsv+0xfc>
 *   @0x155de8 str r1, [sp]
 *   @0x155dec vstr d8, [sp, #8]
 *   @0x155df0 ldr lr, [pc, #0x98]
 *   @0x155df4 vstr d8, [sp, #24]
 *   @0x155df8 ldr r3, [pc, #0x94]
 *   @0x155dfc mov r0, #3
 *   @0x155e00 ldr r1, [pc, #0x90]
 *   @0x155e04 add lr, pc, lr
 *   @0x155e08 add r3, pc, r3
 *   @0x155e0c str r2, [sp, #0x10]
 *   @0x155e10 str r3, [sp, #0x14]
 *   @0x155e14 add r1, pc, r1
 *   @0x155e18 str r12, [sp, #0x20]
 *   @0x155e1c mov r2, #0
 *   @0x155e20 str lr, [sp, #0x4]
 *   @0x155e24 mov r3, #0
 *   @0x155e28 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x155e2c str r0, [r5]
 *   @0x155e30 b 0x155cf4 <_Z19Push_DispatchEventsv+0xfc>
 *   @0x155e34 bl 0x161bfc <_Z23Push_ClearNotificationsv>
 *   @0x155e38 add r0, sp, #60
 *   @0x155e3c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x155e40 add sp, sp, #68
 *   @0x155e44 vpop {d8}
 *   @0x155e48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x155e4c nop
 *   @0x155e58 eoreq r12, r9, r4, asr #32
 *   @0x155e5c .word 0xffffdec4
 *   @0x155e60 .word 0xffffbac4
 *   @0x155e64 eorseq lr, r2, r4, lsr #28
 *   @0x155e68 ldrsbeq r0, [pc], -r8
 *   @0x155e6c .word 0xffffdec8
 *   @0x155e70 .word 0x002516b8
 *   @0x155e74 mulseq pc, r0, r4
 *   @0x155e78 andseq r10, sp, r12, lsr #27
 *   @0x155e7c mulseq pc, r4, r7
 *   @0x155e80 andseq r0, pc, r8, ror r4
 *   @0x155e84 .word 0xffffbcec
 *   @0x155e88 andseq r10, sp, r0, lsr #25
 *   @0x155e8c andseq r0, pc, r12, ror r6
 *   @0x155e90 andseq r10, sp, r12, asr #24
 *   @0x155e94 andseq r10, sp, r12, ror sp
 *   @0x155e98 andseq r0, pc, r4, lsl r3
 *
 * ══ §30/42 GR_Texture_Draw  0x174c40  size 672  168 条（0x174c40..0x174ee0）
 * @func 0x174c40 0x174ee0  size 672  168 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / GR_Texture_Draw(int, float, float, float, float, float, float, float, unsigned int, float)+0x1c4 / Graphics::AllocVerts(ePrimType, void*, int, int) / 0xb6580 / 0xb658c / 0xfe239898
 * 字段偏移 top8: 0x4×3 / 0x6×2 / 0xc×2 / 0x8×2 / 0x23c×1 / 0x48×1 / 0x2×1 / 0x70×1
 * VFP 指令 94 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x174c40 push {r3, r4, r5, r6, r7, lr}
 *   @0x174c44 vpush {d8, d9, d10, d11}
 *   @0x174c48 mov r4, r0
 *   @0x174c4c vldr s17, [sp, #56]
 *   @0x174c50 vmov s22, r1
 *   @0x174c54 vldr s20, [sp, #60]
 *   @0x174c58 vmov s21, r2
 *   @0x174c5c vldr s19, [sp, #64]
 *   @0x174c60 vmov s16, r3
 *   @0x174c64 vldr s18, [sp, #68]
 *   @0x174c68 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x174c6c subs r7, r0, #0
 *   @0x174c70 beq 0x174df8 <_Z15GR_Texture_Drawifffffffjf+0x1b8>
 *   @0x174c74 vldr s15, [pc, #596]
 *   @0x174c78 vldr s13, [sp, #76]
 *   @0x174c7c vmul.f32 s15, s13, s15
 *   @0x174c80 vcvt.s32.f32 s15, s15
 *   @0x174c84 vmov r6, s15
 *   @0x174c88 cmp r6, #255
 *   @0x174c8c movgt r6, #-16777216
 *   @0x174c90 ble 0x174e04 <_Z15GR_Texture_Drawifffffffjf+0x1c4>
 *   @0x174c94 ldr r3, [pc, #0x23c]
 *   @0x174c98 ldr r1, [sp, #0x48]
 *   @0x174c9c ldr r3, [pc, r3]
 *   @0x174ca0 bic r2, r1, #-16777216
 *   @0x174ca4 ldr r3, [r3, #0x4]
 *   @0x174ca8 orr r6, r6, r2
 *   @0x174cac ldr r5, [r3, r4, lsl #2]
 *   @0x174cb0 ldrh r3, [r5, #6]
 *   @0x174cb4 cmp r3, #0
 *   @0x174cb8 bne 0x174e14 <_Z15GR_Texture_Drawifffffffjf+0x1d4>
 *   @0x174cbc vmov.f32 s15, #8.000000e+00
 *   @0x174cc0 mov r3, #8
 *   @0x174cc4 strh r3, [r5, #4]
 *   @0x174cc8 strh r3, [r5, #6]
 *   @0x174ccc mov r3, #1040187392
 *   @0x174cd0 str r3, [r5, #0xc]
 *   @0x174cd4 str r3, [r5, #0x8]
 *   @0x174cd8 vmov.f32 s14, s15
 *   @0x174cdc mov r0, #4
 *   @0x174ce0 ldr r1, [r5]
 *   @0x174ce4 mov r2, #24
 *   @0x174ce8 mov r3, #6
 *   @0x174cec vnmul.f32 s22, s20, s22
 *   @0x174cf0 vnmul.f32 s21, s19, s21
 *   @0x174cf4 vmov.f32 s23, s22
 *   @0x174cf8 vmla.f32 s23, s20, s14
 *   @0x174cfc vmov.f32 s20, s21
 *   @0x174d00 vmla.f32 s20, s19, s15
 *   @0x174d04 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x174d08 vldr s15, [pc, #452]
 *   @0x174d0c vabs.f32 s14, s18
 *   @0x174d10 vcmpe.f32 s14, s15
 *   @0x174d14 vmrs APSR_nzcv, fpscr
 *   @0x174d18 mov r4, r0
 *   @0x174d1c bpl 0x174e3c <_Z15GR_Texture_Drawifffffffjf+0x1fc>
 *   @0x174d20 vadd.f32 s22, s16, s22
 *   @0x174d24 vadd.f32 s21, s17, s21
 *   @0x174d28 vstr s22, [r0]
 *   @0x174d2c vstr s22, [r0, #120]
 *   @0x174d30 vstr s22, [r0, #96]
 *   @0x174d34 vadd.f32 s16, s16, s23
 *   @0x174d38 vstr s21, [r0, #28]
 *   @0x174d3c vstr s21, [r0, #4]
 *   @0x174d40 vstr s21, [r0, #124]
 *   @0x174d44 vadd.f32 s17, s17, s20
 *   @0x174d48 vstr s16, [r0, #48]
 *   @0x174d4c vstr s16, [r0, #72]
 *   @0x174d50 vstr s16, [r0, #24]
 *   @0x174d54 vstr s17, [r0, #100]
 *   @0x174d58 vstr s17, [r0, #52]
 *   @0x174d5c vstr s17, [r0, #76]
 *   @0x174d60 mov r3, #0
 *   @0x174d64 str r3, [r4, #0x70]
 *   @0x174d68 str r3, [r4, #0x10]
 *   @0x174d6c str r3, [r4, #0x88]
 *   @0x174d70 str r3, [r4, #0x2c]
 *   @0x174d74 str r3, [r4, #0x14]
 *   @0x174d78 str r3, [r4, #0x8c]
 *   @0x174d7c vldr s14, [r5, #8]
 *   @0x174d80 ldrsh r1, [r5, #4]
 *   @0x174d84 ldr r3, [pc, #0x150]
 *   @0x174d88 str r6, [r4, #0x84]
 *   @0x174d8c vmov s15, r1
 *   @0x174d90 ldr r3, [pc, r3]
 *   @0x174d94 str r6, [r4, #0x6c]
 *   @0x174d98 vcvt.f32.s32 s15, s15
 *   @0x174d9c ldr r3, [r3]
 *   @0x174da0 str r6, [r4, #0x54]
 *   @0x174da4 str r6, [r4, #0x3c]
 *   @0x174da8 str r3, [r4, #0x80]
 *   @0x174dac str r3, [r4, #0x68]
 *   @0x174db0 str r3, [r4, #0x50]
 *   @0x174db4 str r3, [r4, #0x38]
 *   @0x174db8 vmul.f32 s15, s15, s14
 *   @0x174dbc str r3, [r4, #0x20]
 *   @0x174dc0 str r3, [r4, #0x8]
 *   @0x174dc4 str r6, [r4, #0x24]
 *   @0x174dc8 str r6, [r4, #0xc]
 *   @0x174dcc vstr s15, [r4, #64]
 *   @0x174dd0 vstr s15, [r4, #88]
 *   @0x174dd4 vstr s15, [r4, #40]
 *   @0x174dd8 ldrsh r3, [r5, #6]
 *   @0x174ddc vldr s14, [r5, #12]
 *   @0x174de0 vmov s15, r3
 *   @0x174de4 vcvt.f32.s32 s15, s15
 *   @0x174de8 vmul.f32 s15, s15, s14
 *   @0x174dec vstr s15, [r4, #116]
 *   @0x174df0 vstr s15, [r4, #68]
 *   @0x174df4 vstr s15, [r4, #92]
 *   @0x174df8 vpop {d8, d9, d10, d11}
 *   @0x174dfc mov r0, r7
 *   @0x174e00 pop {r3, r4, r5, r6, r7, pc}
 *   @0x174e04 cmp r6, #0
 *   @0x174e08 lslge r6, r6, #24
 *   @0x174e0c movlt r6, #0
 *   @0x174e10 b 0x174c94 <_Z15GR_Texture_Drawifffffffjf+0x54>
 *   @0x174e14 ldrh r2, [r5, #4]
 *   @0x174e18 cmp r2, #0
 *   @0x174e1c beq 0x174cbc <_Z15GR_Texture_Drawifffffffjf+0x7c>
 *   @0x174e20 sxth r2, r2
 *   @0x174e24 sxth r3, r3
 *   @0x174e28 vmov s13, r2
 *   @0x174e2c vcvt.f32.s32 s14, s13
 *   @0x174e30 vmov s13, r3
 *   @0x174e34 vcvt.f32.s32 s15, s13
 *   @0x174e38 b 0x174cdc <_Z15GR_Texture_Drawifffffffjf+0x9c>
 *   @0x174e3c vmov r0, s18
 *   @0x174e40 bl 0xb6580 <sinf@plt>
 *   @0x174e44 vmov s19, r0
 *   @0x174e48 vmov r0, s18
 *   @0x174e4c bl 0xb658c <cosf@plt>
 *   @0x174e50 vmov.f32 s13, s17
 *   @0x174e54 vmov.f32 s14, s16
 *   @0x174e58 vmls.f32 s13, s22, s19
 *   @0x174e5c vmls.f32 s17, s23, s19
 *   @0x174e60 vmov s15, r0
 *   @0x174e64 vmla.f32 s14, s22, s15
 *   @0x174e68 vmla.f32 s16, s23, s15
 *   @0x174e6c vmul.f32 s11, s21, s15
 *   @0x174e70 vmul.f32 s21, s21, s19
 *   @0x174e74 vmul.f32 s15, s20, s15
 *   @0x174e78 vmul.f32 s19, s20, s19
 *   @0x174e7c vadd.f32 s12, s13, s11
 *   @0x174e80 vadd.f32 s11, s17, s11
 *   @0x174e84 vstr s12, [r4, #4]
 *   @0x174e88 vstr s12, [r4, #124]
 *   @0x174e8c vadd.f32 s17, s15, s17
 *   @0x174e90 vstr s11, [r4, #28]
 *   @0x174e94 vadd.f32 s15, s15, s13
 *   @0x174e98 vstr s17, [r4, #52]
 *   @0x174e9c vstr s17, [r4, #76]
 *   @0x174ea0 vadd.f32 s13, s14, s21
 *   @0x174ea4 vstr s15, [r4, #100]
 *   @0x174ea8 vadd.f32 s21, s16, s21
 *   @0x174eac vstr s13, [r4]
 *   @0x174eb0 vstr s13, [r4, #120]
 *   @0x174eb4 vadd.f32 s16, s19, s16
 *   @0x174eb8 vstr s21, [r4, #24]
 *   @0x174ebc vadd.f32 s19, s19, s14
 *   @0x174ec0 vstr s16, [r4, #48]
 *   @0x174ec4 vstr s16, [r4, #72]
 *   @0x174ec8 vstr s19, [r4, #96]
 *   @0x174ecc b 0x174d60 <_Z15GR_Texture_Drawifffffffjf+0x120>
 *   @0x174ed0 cmnmi pc, #0
 *   @0x174ed4 blo 0xfe239898 <b2_toiTime+0xfffffffffdae03f4>
 *   @0x174ed8 eoreq r8, r7, r0, lsl #25
 *   @0x174edc mlaeq r7, r0, r11, r8
 *
 * ══ §31/42 Code_Variable_FindAlloc_Slot_From_Name  0xd2c84  size 668  167 条（0xd2c84..0xd2f20）
 * @func 0xd2c84 0xd2f20  size 668  167 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd2c94→0x544be0, 0xd2cc8→0x47f295, 0xd2cf0→0x47a19c, 0xd2d68→0x47a18c, 0xd2dd8→0x47a178
 * 调用序列: YYStrDup(char const*)×2 / MemoryManager::Free(void const*)×2 / Code_Variable_Find_Slot_From_Local_Name(char const*) / Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*)+0xdc / Code_Variable_Find_Slot_From_Global_Name(char const*) / Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*)+0x1e4 / Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*)+0x258 / Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*)+0x178
 * 字段偏移 top8: 0x4×8 / 0xc×7 / 0x8×2 / 0x270×1 / 0x26c×1 / 0x23c×1 / 0x218×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd2c84 push {r4, r5, r6, r7, r8, lr}
 *   @0xd2c88 mov r6, r1
 *   @0xd2c8c ldr r5, [pc, #0x270]
 *   @0xd2c90 sub sp, sp, #8
 *   @0xd2c94 ldr r3, [pc, #0x26c]
 *   @0xd2c98 add r5, pc, r5
 *   @0xd2c9c ldr r3, [r5, r3]
 *   @0xd2ca0 ldr r3, [r3]
 *   @0xd2ca4 cmp r3, r0
 *   @0xd2ca8 mov r0, r1
 *   @0xd2cac beq 0xd2cc8 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x44>
 *   @0xd2cb0 bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc>
 *   @0xd2cb4 subs r4, r0, #0
 *   @0xd2cb8 blt 0xd2d60 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xdc>
 *   @0xd2cbc mov r0, r4
 *   @0xd2cc0 add sp, sp, #8
 *   @0xd2cc4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xd2cc8 ldr r3, [pc, #0x23c]
 *   @0xd2ccc ldr r3, [r5, r3]
 *   @0xd2cd0 ldrb r7, [r3]
 *   @0xd2cd4 cmp r7, #0
 *   @0xd2cd8 bne 0xd2cb0 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x2c>
 *   @0xd2cdc bl 0xd2054 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc>
 *   @0xd2ce0 subs r4, r0, #0
 *   @0xd2ce4 bge 0xd2cbc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x38>
 *   @0xd2ce8 mov r0, r6
 *   @0xd2cec bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xd2cf0 ldr r3, [pc, #0x218]
 *   @0xd2cf4 ldr r5, [r5, r3]
 *   @0xd2cf8 ldr r1, [r5, #0x4]
 *   @0xd2cfc ldr r12, [r5]
 *   @0xd2d00 cmp r1, #0
 *   @0xd2d04 mov r8, r0
 *   @0xd2d08 ble 0xd2e68 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1e4>
 *   @0xd2d0c cmp r12, #0
 *   @0xd2d10 ldr r6, [r5, #0xc]
 *   @0xd2d14 ble 0xd2edc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x258>
 *   @0xd2d18 ldr r3, [r6]
 *   @0xd2d1c cmp r3, #0
 *   @0xd2d20 movne r4, r7
 *   @0xd2d24 movne r3, r6
 *   @0xd2d28 bne 0xd2d3c <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xb8>
 *   @0xd2d2c b 0xd2ed8 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x254>
 *   @0xd2d30 ldr r2, [r3, #0x4]!
 *   @0xd2d34 cmp r2, #0
 *   @0xd2d38 beq 0xd2d58 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xd4>
 *   @0xd2d3c add r4, r4, #1
 *   @0xd2d40 cmp r4, r1
 *   @0xd2d44 lsl r7, r4, #2
 *   @0xd2d48 beq 0xd2e68 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1e4>
 *   @0xd2d4c cmp r4, r12
 *   @0xd2d50 bne 0xd2d30 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xac>
 *   @0xd2d54 lsl r7, r4, #2
 *   @0xd2d58 str r8, [r6, r7]
 *   @0xd2d5c b 0xd2cbc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x38>
 *   @0xd2d60 mov r0, r6
 *   @0xd2d64 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xd2d68 ldr r3, [pc, #0x1a4]
 *   @0xd2d6c ldr r7, [r5, r3]
 *   @0xd2d70 ldr r12, [r7, #0x4]
 *   @0xd2d74 ldr lr, [r7]
 *   @0xd2d78 cmp r12, #0
 *   @0xd2d7c mov r8, r0
 *   @0xd2d80 ldrle r0, [r7, #0xc]
 *   @0xd2d84 ble 0xd2dfc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x178>
 *   @0xd2d88 cmp lr, #0
 *   @0xd2d8c ble 0xd2e1c <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x198>
 *   @0xd2d90 ldr r0, [r7, #0xc]
 *   @0xd2d94 ldr r6, [r0]
 *   @0xd2d98 cmp r6, #0
 *   @0xd2d9c movne r3, r0
 *   @0xd2da0 movne r4, #0
 *   @0xd2da4 bne 0xd2db8 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x134>
 *   @0xd2da8 b 0xd2efc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x278>
 *   @0xd2dac ldr r2, [r3, #0x4]!
 *   @0xd2db0 cmp r2, #0
 *   @0xd2db4 beq 0xd2dd4 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x150>
 *   @0xd2db8 add r4, r4, #1
 *   @0xd2dbc cmp r4, r12
 *   @0xd2dc0 lsl r6, r4, #2
 *   @0xd2dc4 beq 0xd2dfc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x178>
 *   @0xd2dc8 cmp r4, lr
 *   @0xd2dcc bne 0xd2dac <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x128>
 *   @0xd2dd0 lsl r6, r4, #2
 *   @0xd2dd4 str r8, [r0, r6]
 *   @0xd2dd8 ldr r3, [pc, #0x138]
 *   @0xd2ddc mov r1, r8
 *   @0xd2de0 mov r2, r4
 *   @0xd2de4 ldr r3, [r5, r3]
 *   @0xd2de8 ldr r0, [r3]
 *   @0xd2dec bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0xd2df0 mov r0, r4
 *   @0xd2df4 add sp, sp, #8
 *   @0xd2df8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xd2dfc cmp r12, lr
 *   @0xd2e00 beq 0xd2e2c <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1a8>
 *   @0xd2e04 add r0, r0, r12, lsl #2
 *   @0xd2e08 add r3, r12, #1
 *   @0xd2e0c mov r4, r12
 *   @0xd2e10 str r8, [r0]
 *   @0xd2e14 str r3, [r7, #0x4]
 *   @0xd2e18 b 0xd2dd8 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x154>
 *   @0xd2e1c mov r6, #0
 *   @0xd2e20 ldr r0, [r7, #0xc]
 *   @0xd2e24 mov r4, r6
 *   @0xd2e28 b 0xd2dd4 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x150>
 *   @0xd2e2c ldr r6, [r7, #0x8]
 *   @0xd2e30 add r6, r12, r6
 *   @0xd2e34 cmp r12, r6
 *   @0xd2e38 beq 0xd2e04 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x180>
 *   @0xd2e3c cmp r6, #0
 *   @0xd2e40 bne 0xd2e88 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x204>
 *   @0xd2e44 cmp r0, #0
 *   @0xd2e48 beq 0xd2ebc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x238>
 *   @0xd2e4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd2e50 mov r4, r6
 *   @0xd2e54 mov r3, #1
 *   @0xd2e58 mov r0, r6
 *   @0xd2e5c str r6, [r7, #0xc]
 *   @0xd2e60 str r6, [r7]
 *   @0xd2e64 b 0xd2e10 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x18c>
 *   @0xd2e68 cmp r1, r12
 *   @0xd2e6c movne r4, r1
 *   @0xd2e70 beq 0xd2ee4 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x260>
 *   @0xd2e74 ldr r2, [r5, #0xc]
 *   @0xd2e78 add r3, r4, #1
 *   @0xd2e7c str r8, [r2, r4, lsl #2]
 *   @0xd2e80 str r3, [r5, #0x4]
 *   @0xd2e84 b 0xd2cbc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x38>
 *   @0xd2e88 lsls r1, r6, #2
 *   @0xd2e8c beq 0xd2ebc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x238>
 *   @0xd2e90 ldr r2, [pc, #0x84]
 *   @0xd2e94 mov r3, #0
 *   @0xd2e98 str r3, [sp]
 *   @0xd2e9c movw r3, #0x11b
 *   @0xd2ea0 add r2, pc, r2
 *   @0xd2ea4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd2ea8 ldr r4, [r7, #0x4]
 *   @0xd2eac add r3, r4, #1
 *   @0xd2eb0 str r0, [r7, #0xc]
 *   @0xd2eb4 add r0, r0, r4, lsl #2
 *   @0xd2eb8 b 0xd2e60 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1dc>
 *   @0xd2ebc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd2ec0 mov r3, #0
 *   @0xd2ec4 mov r0, r3
 *   @0xd2ec8 str r3, [r7, #0xc]
 *   @0xd2ecc mov r4, r3
 *   @0xd2ed0 mov r3, #1
 *   @0xd2ed4 b 0xd2e60 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1dc>
 *   @0xd2ed8 mov r7, r3
 *   @0xd2edc mov r4, r7
 *   @0xd2ee0 b 0xd2d58 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xd4>
 *   @0xd2ee4 ldr r3, [r5, #0x8]
 *   @0xd2ee8 mov r0, r5
 *   @0xd2eec add r1, r1, r3
 *   @0xd2ef0 bl 0xd1b3c <_ZN18cARRAY_OF_POINTERS9setLengthEi>
 *   @0xd2ef4 ldr r4, [r5, #0x4]
 *   @0xd2ef8 b 0xd2e74 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1f0>
 *   @0xd2efc mov r4, r6
 *   @0xd2f00 b 0xd2dd4 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x150>
 *   @0xd2f04 ldrhteq lr, [r1], -r8
 *   @0xd2f08 .word 0xffffbf64
 *   @0xd2f0c .word 0xffffbf68
 *   @0xd2f10 .word 0xffffbf4c
 *   @0xd2f14 .word 0xffffbf50
 *   @0xd2f18 .word 0xffffbf54
 *   @0xd2f1c eoreq pc, r5, r0, asr #16
 *
 * ══ §32/42 b2SeparationFunction::Evaluate  0x2e0694  size 668  167 条（0x2e0694..0x2e0930）
 * @func 0x2e0694 0x2e0930  size 668  167 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2
 * 字段偏移 top8: 0x10×4 / 0x4×2 / 0x50×1
 * VFP 指令 135 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e0694 push {r4, r5, r6, lr}
 *   @0x2e0698 vpush {d8, d9, d10, d11}
 *   @0x2e069c vmov.f32 s17, #1.000000e+00
 *   @0x2e06a0 vldr s18, [r0, #36]
 *   @0x2e06a4 vmov s16, r3
 *   @0x2e06a8 vldr s15, [r0, #32]
 *   @0x2e06ac mov r4, r0
 *   @0x2e06b0 mov r5, r1
 *   @0x2e06b4 mov r6, r2
 *   @0x2e06b8 vmul.f32 s18, s16, s18
 *   @0x2e06bc vsub.f32 s17, s17, s16
 *   @0x2e06c0 vmla.f32 s18, s17, s15
 *   @0x2e06c4 vmov r0, s18
 *   @0x2e06c8 bl 0xb6580 <sinf@plt>
 *   @0x2e06cc vmov s20, r0
 *   @0x2e06d0 vmov r0, s18
 *   @0x2e06d4 bl 0xb658c <cosf@plt>
 *   @0x2e06d8 vldr s21, [r4, #72]
 *   @0x2e06dc vmul.f32 s21, s16, s21
 *   @0x2e06e0 vldr s15, [r4, #12]
 *   @0x2e06e4 vldr s12, [r4, #24]
 *   @0x2e06e8 vldr s14, [r4, #28]
 *   @0x2e06ec vldr s8, [r4, #68]
 *   @0x2e06f0 vldr s11, [r4, #8]
 *   @0x2e06f4 vldr s9, [r4, #16]
 *   @0x2e06f8 vldr s10, [r4, #20]
 *   @0x2e06fc vmul.f32 s12, s16, s12
 *   @0x2e0700 vmul.f32 s13, s15, s20
 *   @0x2e0704 vmov s19, r0
 *   @0x2e0708 vmul.f32 s14, s16, s14
 *   @0x2e070c vmul.f32 s15, s15, s19
 *   @0x2e0710 vmla.f32 s21, s17, s8
 *   @0x2e0714 vmla.f32 s12, s17, s9
 *   @0x2e0718 vmov r0, s21
 *   @0x2e071c vnmls.f32 s13, s11, s19
 *   @0x2e0720 vmla.f32 s15, s11, s20
 *   @0x2e0724 vmla.f32 s14, s17, s10
 *   @0x2e0728 vsub.f32 s22, s12, s13
 *   @0x2e072c vsub.f32 s23, s14, s15
 *   @0x2e0730 bl 0xb6580 <sinf@plt>
 *   @0x2e0734 vmov s18, r0
 *   @0x2e0738 vmov r0, s21
 *   @0x2e073c bl 0xb658c <cosf@plt>
 *   @0x2e0740 vldr s10, [r4, #48]
 *   @0x2e0744 vldr s12, [r4, #60]
 *   @0x2e0748 vldr s7, [r4, #64]
 *   @0x2e074c vmul.f32 s12, s16, s12
 *   @0x2e0750 vldr s11, [r4, #44]
 *   @0x2e0754 vldr s8, [r4, #52]
 *   @0x2e0758 vldr s9, [r4, #56]
 *   @0x2e075c ldr r3, [r4, #0x50]
 *   @0x2e0760 cmp r3, #1
 *   @0x2e0764 vmul.f32 s13, s10, s18
 *   @0x2e0768 vmul.f32 s16, s16, s7
 *   @0x2e076c vmov s15, r0
 *   @0x2e0770 vmul.f32 s14, s10, s15
 *   @0x2e0774 vmla.f32 s12, s17, s8
 *   @0x2e0778 vnmls.f32 s13, s11, s15
 *   @0x2e077c vmla.f32 s14, s11, s18
 *   @0x2e0780 vmla.f32 s16, s17, s9
 *   @0x2e0784 vsub.f32 s13, s12, s13
 *   @0x2e0788 vsub.f32 s16, s16, s14
 *   @0x2e078c beq 0x2e08ac <_ZNK20b2SeparationFunction8EvaluateEiif+0x218>
 *   @0x2e0790 cmp r3, #2
 *   @0x2e0794 beq 0x2e082c <_ZNK20b2SeparationFunction8EvaluateEiif+0x198>
 *   @0x2e0798 cmp r3, #0
 *   @0x2e079c beq 0x2e07b0 <_ZNK20b2SeparationFunction8EvaluateEiif+0x11c>
 *   @0x2e07a0 vpop {d8, d9, d10, d11}
 *   @0x2e07a4 vldr s15, [pc, #384]
 *   @0x2e07a8 vmov r0, s15
 *   @0x2e07ac pop {r4, r5, r6, pc}
 *   @0x2e07b0 ldr r2, [r4]
 *   @0x2e07b4 vldr s6, [r4, #96]
 *   @0x2e07b8 ldr r3, [r4, #0x4]
 *   @0x2e07bc vldr s7, [r4, #92]
 *   @0x2e07c0 ldr r2, [r2, #0x10]
 *   @0x2e07c4 ldr r3, [r3, #0x10]
 *   @0x2e07c8 add r5, r2, r5, lsl #3
 *   @0x2e07cc vldr s12, [r5, #4]
 *   @0x2e07d0 add r6, r3, r6, lsl #3
 *   @0x2e07d4 vmul.f32 s14, s12, s19
 *   @0x2e07d8 vldr s11, [r6, #4]
 *   @0x2e07dc vldr s8, [r5]
 *   @0x2e07e0 vldr s9, [r6]
 *   @0x2e07e4 vmul.f32 s10, s11, s15
 *   @0x2e07e8 vmul.f32 s12, s12, s20
 *   @0x2e07ec vmla.f32 s14, s8, s20
 *   @0x2e07f0 vmul.f32 s11, s11, s18
 *   @0x2e07f4 vmla.f32 s10, s9, s18
 *   @0x2e07f8 vnmls.f32 s12, s8, s19
 *   @0x2e07fc vnmls.f32 s11, s9, s15
 *   @0x2e0800 vadd.f32 s23, s14, s23
 *   @0x2e0804 vadd.f32 s16, s10, s16
 *   @0x2e0808 vsub.f32 s15, s16, s23
 *   @0x2e080c vadd.f32 s22, s12, s22
 *   @0x2e0810 vadd.f32 s13, s11, s13
 *   @0x2e0814 vmul.f32 s15, s15, s6
 *   @0x2e0818 vsub.f32 s13, s13, s22
 *   @0x2e081c vpop {d8, d9, d10, d11}
 *   @0x2e0820 vmla.f32 s15, s13, s7
 *   @0x2e0824 vmov r0, s15
 *   @0x2e0828 pop {r4, r5, r6, pc}
 *   @0x2e082c ldr r3, [r4]
 *   @0x2e0830 vldr s9, [r4, #88]
 *   @0x2e0834 vmul.f32 s8, s9, s15
 *   @0x2e0838 vldr s6, [r4, #84]
 *   @0x2e083c vldr s11, [r4, #96]
 *   @0x2e0840 vldr s7, [r4, #92]
 *   @0x2e0844 ldr r3, [r3, #0x10]
 *   @0x2e0848 add r5, r3, r5, lsl #3
 *   @0x2e084c vldr s12, [r5, #4]
 *   @0x2e0850 vldr s5, [r5]
 *   @0x2e0854 vmul.f32 s14, s12, s19
 *   @0x2e0858 vmul.f32 s9, s9, s18
 *   @0x2e085c vmul.f32 s12, s12, s20
 *   @0x2e0860 vmla.f32 s14, s5, s20
 *   @0x2e0864 vmla.f32 s8, s6, s18
 *   @0x2e0868 vmul.f32 s10, s11, s15
 *   @0x2e086c vnmls.f32 s12, s5, s19
 *   @0x2e0870 vnmls.f32 s9, s6, s15
 *   @0x2e0874 vmul.f32 s11, s11, s18
 *   @0x2e0878 vmla.f32 s10, s7, s18
 *   @0x2e087c vadd.f32 s14, s14, s23
 *   @0x2e0880 vadd.f32 s16, s8, s16
 *   @0x2e0884 vsub.f32 s14, s14, s16
 *   @0x2e0888 vnmls.f32 s11, s7, s15
 *   @0x2e088c vadd.f32 s12, s12, s22
 *   @0x2e0890 vpop {d8, d9, d10, d11}
 *   @0x2e0894 vadd.f32 s13, s9, s13
 *   @0x2e0898 vmul.f32 s15, s10, s14
 *   @0x2e089c vsub.f32 s13, s12, s13
 *   @0x2e08a0 vmla.f32 s15, s11, s13
 *   @0x2e08a4 vmov r0, s15
 *   @0x2e08a8 pop {r4, r5, r6, pc}
 *   @0x2e08ac ldr r3, [r4, #0x4]
 *   @0x2e08b0 vldr s9, [r4, #88]
 *   @0x2e08b4 vmul.f32 s8, s9, s19
 *   @0x2e08b8 vldr s6, [r4, #84]
 *   @0x2e08bc vldr s11, [r4, #96]
 *   @0x2e08c0 vldr s7, [r4, #92]
 *   @0x2e08c4 ldr r3, [r3, #0x10]
 *   @0x2e08c8 add r6, r3, r6, lsl #3
 *   @0x2e08cc vldr s12, [r6, #4]
 *   @0x2e08d0 vldr s5, [r6]
 *   @0x2e08d4 vmul.f32 s14, s12, s15
 *   @0x2e08d8 vmul.f32 s9, s9, s20
 *   @0x2e08dc vmul.f32 s12, s12, s18
 *   @0x2e08e0 vmla.f32 s14, s5, s18
 *   @0x2e08e4 vmla.f32 s8, s6, s20
 *   @0x2e08e8 vmul.f32 s10, s11, s19
 *   @0x2e08ec vnmls.f32 s12, s5, s15
 *   @0x2e08f0 vnmls.f32 s9, s6, s19
 *   @0x2e08f4 vmul.f32 s11, s11, s20
 *   @0x2e08f8 vmla.f32 s10, s7, s20
 *   @0x2e08fc vadd.f32 s16, s14, s16
 *   @0x2e0900 vadd.f32 s23, s8, s23
 *   @0x2e0904 vsub.f32 s15, s16, s23
 *   @0x2e0908 vnmls.f32 s11, s7, s19
 *   @0x2e090c vadd.f32 s22, s9, s22
 *   @0x2e0910 vadd.f32 s13, s12, s13
 *   @0x2e0914 vmul.f32 s15, s10, s15
 *   @0x2e0918 vsub.f32 s13, s13, s22
 *   @0x2e091c vpop {d8, d9, d10, d11}
 *   @0x2e0920 vmla.f32 s15, s11, s13
 *   @0x2e0924 vmov r0, s15
 *   @0x2e0928 pop {r4, r5, r6, pc}
 *   @0x2e092c andeq r0, r0, r0
 *
 * ══ §33/42 b2Contact::Update  0x2cc1ec  size 660  165 条（0x2cc1ec..0x2cc480）
 * @func 0x2cc1ec 0x2cc480  size 660  165 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2TestOverlap(b2Shape const*, int, b2Shape const*, int, b2Transform const&, b2Transform const&) / b2Contact::Update(b2ContactListener*)+0x214
 * 字段偏移 top8: 0x4×9 / 0xc×6 / 0x8×5 / 0x18×4 / 0x10×4 / 0x24×3 / 0x1c×3 / 0x20×3
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc1ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2cc1f0 add r7, r0, #64
 *   @0x2cc1f4 mov r8, r0
 *   @0x2cc1f8 ldr r4, [r0, #0x4]
 *   @0x2cc1fc mov lr, r7
 *   @0x2cc200 mov r9, r1
 *   @0x2cc204 ldm lr!, {r0, r1, r2, r3}
 *   @0x2cc208 sub sp, sp, #108
 *   @0x2cc20c add r12, sp, #40
 *   @0x2cc210 orr r5, r4, #4
 *   @0x2cc214 str r12, [sp, #0x14]
 *   @0x2cc218 ubfx r4, r4, #0x1, #0x1
 *   @0x2cc21c str r4, [sp, #0x24]
 *   @0x2cc220 stm r12!, {r0, r1, r2, r3}
 *   @0x2cc224 ldm lr!, {r0, r1, r2, r3}
 *   @0x2cc228 stm r12!, {r0, r1, r2, r3}
 *   @0x2cc22c ldm lr!, {r0, r1, r2, r3}
 *   @0x2cc230 stm r12!, {r0, r1, r2, r3}
 *   @0x2cc234 ldm lr, {r0, r1, r2, r3}
 *   @0x2cc238 stm r12, {r0, r1, r2, r3}
 *   @0x2cc23c ldr r2, [r8, #0x30]
 *   @0x2cc240 str r5, [r8, #0x4]
 *   @0x2cc244 ldr r1, [r8, #0x34]
 *   @0x2cc248 ldr r12, [r2, #0x8]
 *   @0x2cc24c ldrb r3, [r2, #0x2c]
 *   @0x2cc250 ldrb r0, [r1, #0x2c]
 *   @0x2cc254 str r12, [sp, #0x1c]
 *   @0x2cc258 ldr r12, [r1, #0x8]
 *   @0x2cc25c orrs r3, r0, r3
 *   @0x2cc260 str r3, [sp, #0x18]
 *   @0x2cc264 str r12, [sp, #0x20]
 *   @0x2cc268 ldr r12, [sp, #0x1c]
 *   @0x2cc26c add lr, r12, #12
 *   @0x2cc270 ldr r12, [sp, #0x20]
 *   @0x2cc274 add r3, r12, #12
 *   @0x2cc278 beq 0x2cc370 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x184>
 *   @0x2cc27c ldr r12, [r8, #0x3c]
 *   @0x2cc280 ldr r0, [r2, #0xc]
 *   @0x2cc284 ldr r2, [r1, #0xc]
 *   @0x2cc288 ldr r1, [r8, #0x38]
 *   @0x2cc28c str r3, [sp, #0x4]
 *   @0x2cc290 mov r3, r12
 *   @0x2cc294 str lr, [sp]
 *   @0x2cc298 bl 0x2c3abc <_Z13b2TestOverlapPK7b2ShapeiS1_iRK11b2TransformS4_>
 *   @0x2cc29c mov r3, #0
 *   @0x2cc2a0 str r3, [r8, #0x7c]
 *   @0x2cc2a4 mov r12, r0
 *   @0x2cc2a8 cmp r12, #0
 *   @0x2cc2ac ldr r7, [sp, #0x24]
 *   @0x2cc2b0 beq 0x2cc31c <_ZN9b2Contact6UpdateEP17b2ContactListener+0x130>
 *   @0x2cc2b4 ldr r3, [r8, #0x4]
 *   @0x2cc2b8 cmp r7, #0
 *   @0x2cc2bc orr r3, r3, #2
 *   @0x2cc2c0 str r3, [r8, #0x4]
 *   @0x2cc2c4 bne 0x2cc330 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x144>
 *   @0x2cc2c8 cmp r9, #0
 *   @0x2cc2cc beq 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128>
 *   @0x2cc2d0 ldr r3, [r9]
 *   @0x2cc2d4 mov r0, r9
 *   @0x2cc2d8 mov r1, r8
 *   @0x2cc2dc ldr r3, [r3, #0x8]
 *   @0x2cc2e0 str r12, [sp, #0x10]
 *   @0x2cc2e4 blx r3
 *   @0x2cc2e8 ldr r7, [sp, #0x18]
 *   @0x2cc2ec ldr r12, [sp, #0x10]
 *   @0x2cc2f0 eor r3, r7, #1
 *   @0x2cc2f4 tst r12, r3
 *   @0x2cc2f8 beq 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128>
 *   @0x2cc2fc ldr r3, [r9]
 *   @0x2cc300 mov r1, r8
 *   @0x2cc304 add r2, sp, #40
 *   @0x2cc308 mov r0, r9
 *   @0x2cc30c ldr r3, [r3, #0x10]
 *   @0x2cc310 blx r3
 *   @0x2cc314 add sp, sp, #108
 *   @0x2cc318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2cc31c ldr r3, [r8, #0x4]
 *   @0x2cc320 cmp r7, #0
 *   @0x2cc324 bic r3, r3, #2
 *   @0x2cc328 str r3, [r8, #0x4]
 *   @0x2cc32c bne 0x2cc34c <_ZN9b2Contact6UpdateEP17b2ContactListener+0x160>
 *   @0x2cc330 ldr r7, [sp, #0x18]
 *   @0x2cc334 eor r3, r7, #1
 *   @0x2cc338 tst r12, r3
 *   @0x2cc33c beq 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128>
 *   @0x2cc340 cmp r9, #0
 *   @0x2cc344 bne 0x2cc2fc <_ZN9b2Contact6UpdateEP17b2ContactListener+0x110>
 *   @0x2cc348 b 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128>
 *   @0x2cc34c cmp r9, #0
 *   @0x2cc350 beq 0x2cc314 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x128>
 *   @0x2cc354 ldr r3, [r9]
 *   @0x2cc358 mov r1, r8
 *   @0x2cc35c mov r0, r9
 *   @0x2cc360 ldr r3, [r3, #0xc]
 *   @0x2cc364 blx r3
 *   @0x2cc368 add sp, sp, #108
 *   @0x2cc36c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2cc370 ldr r12, [r8]
 *   @0x2cc374 mov r2, lr
 *   @0x2cc378 mov r0, r8
 *   @0x2cc37c mov r1, r7
 *   @0x2cc380 ldr r12, [r12]
 *   @0x2cc384 blx r12
 *   @0x2cc388 ldr r10, [r8, #0x7c]
 *   @0x2cc38c cmp r10, #0
 *   @0x2cc390 movle r12, #0
 *   @0x2cc394 movgt r12, #1
 *   @0x2cc398 cmp r12, #0
 *   @0x2cc39c beq 0x2cc414 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x228>
 *   @0x2cc3a0 ldr r5, [sp, #0x64]
 *   @0x2cc3a4 add r0, r8, #84
 *   @0x2cc3a8 ldr r11, [sp, #0x38]
 *   @0x2cc3ac vldr s15, [pc, #200]
 *   @0x2cc3b0 ldr r1, [sp, #0x18]
 *   @0x2cc3b4 cmp r5, #0
 *   @0x2cc3b8 vstr s15, [r7, #8]
 *   @0x2cc3bc vstr s15, [r7, #12]
 *   @0x2cc3c0 ldr r4, [r7, #0x10]
 *   @0x2cc3c4 ble 0x2cc400 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x214>
 *   @0x2cc3c8 cmp r11, r4
 *   @0x2cc3cc strne r7, [sp, #0xc]
 *   @0x2cc3d0 addne r3, sp, #60
 *   @0x2cc3d4 movne r2, #0
 *   @0x2cc3d8 bne 0x2cc3ec <_ZN9b2Contact6UpdateEP17b2ContactListener+0x200>
 *   @0x2cc3dc b 0x2cc474 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x288>
 *   @0x2cc3e0 ldr r7, [r3, #-0x4]
 *   @0x2cc3e4 cmp r7, r4
 *   @0x2cc3e8 beq 0x2cc45c <_ZN9b2Contact6UpdateEP17b2ContactListener+0x270>
 *   @0x2cc3ec add r2, r2, #1
 *   @0x2cc3f0 mov r6, r3
 *   @0x2cc3f4 cmp r2, r5
 *   @0x2cc3f8 add r3, r3, #20
 *   @0x2cc3fc bne 0x2cc3e0 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x1f4>
 *   @0x2cc400 add r1, r1, #1
 *   @0x2cc404 cmp r10, r1
 *   @0x2cc408 movgt r7, r0
 *   @0x2cc40c addgt r0, r0, #20
 *   @0x2cc410 bgt 0x2cc3b4 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x1c8>
 *   @0x2cc414 ldr r7, [sp, #0x24]
 *   @0x2cc418 cmp r12, r7
 *   @0x2cc41c beq 0x2cc2a8 <_ZN9b2Contact6UpdateEP17b2ContactListener+0xbc>
 *   @0x2cc420 ldr r7, [sp, #0x1c]
 *   @0x2cc424 ldrh r3, [r7, #4]
 *   @0x2cc428 tst r3, #2
 *   @0x2cc42c orreq r3, r3, #2
 *   @0x2cc430 strheq r3, [r7, #4]
 *   @0x2cc434 moveq r2, #0
 *   @0x2cc438 streq r2, [r7, #0xa0]
 *   @0x2cc43c ldr r7, [sp, #0x20]
 *   @0x2cc440 ldrh r3, [r7, #4]
 *   @0x2cc444 tst r3, #2
 *   @0x2cc448 orreq r3, r3, #2
 *   @0x2cc44c strheq r3, [r7, #4]
 *   @0x2cc450 moveq r2, #0
 *   @0x2cc454 streq r2, [r7, #0xa0]
 *   @0x2cc458 b 0x2cc2a8 <_ZN9b2Contact6UpdateEP17b2ContactListener+0xbc>
 *   @0x2cc45c ldr r7, [sp, #0xc]
 *   @0x2cc460 ldr r2, [r6, #0x8]
 *   @0x2cc464 ldr r3, [r6, #0xc]
 *   @0x2cc468 str r2, [r7, #0x8]
 *   @0x2cc46c str r3, [r7, #0xc]
 *   @0x2cc470 b 0x2cc400 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x214>
 *   @0x2cc474 add r6, sp, #40
 *   @0x2cc478 b 0x2cc460 <_ZN9b2Contact6UpdateEP17b2ContactListener+0x274>
 *   @0x2cc47c andeq r0, r0, r0
 *
 * ══ §34/42 GR_Surface_Create  0x170f98  size 656  164 条（0x170f98..0x171228）
 * @func 0x170f98 0x171228  size 656  164 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x170fb8→0x48ffb0, 0x171034→0x3f5110, 0x17105c→0x3f510c, 0x171060→0x3f5108, 0x1710bc→0x48ffb0, 0x17116c→0x3f510c, 0x171174→0x3f5108
 * 调用序列: GR_Surface_Create(int, int, int)+0xe4 / GR_Texture_Create_Empty(int, int, bool, bool, int) / GR_Surface_Create(int, int, int)+0x1c0 / GR_Surface_Get(int) / operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×9 / 0xc×7 / 0x4×5 / 0x3×3 / 0x1ac×2 / 0x194×2 / 0x144×2 / 0x25c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170f98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x170f9c cmp r2, #0
 *   @0x170fa0 ldr r5, [pc, #0x25c]
 *   @0x170fa4 sub sp, sp, #20
 *   @0x170fa8 mov r7, r0
 *   @0x170fac mov r6, r1
 *   @0x170fb0 add r5, pc, r5
 *   @0x170fb4 blt 0x17107c <_Z17GR_Surface_Createiii+0xe4>
 *   @0x170fb8 ldr r3, [pc, #0x248]
 *   @0x170fbc ldr r9, [r5, r3]
 *   @0x170fc0 ldr r1, [r9, #0x4]
 *   @0x170fc4 ldr r3, [r9]
 *   @0x170fc8 and r1, r2, r1
 *   @0x170fcc ldr r3, [r3, r1, lsl #3]
 *   @0x170fd0 cmp r3, #0
 *   @0x170fd4 beq 0x171000 <_Z17GR_Surface_Createiii+0x68>
 *   @0x170fd8 ldr r1, [r3, #0x8]
 *   @0x170fdc cmp r2, r1
 *   @0x170fe0 bne 0x170ff4 <_Z17GR_Surface_Createiii+0x5c>
 *   @0x170fe4 b 0x17100c <_Z17GR_Surface_Createiii+0x74>
 *   @0x170fe8 ldr r12, [r3, #0x8]
 *   @0x170fec cmp r2, r12
 *   @0x170ff0 beq 0x17100c <_Z17GR_Surface_Createiii+0x74>
 *   @0x170ff4 ldr r3, [r3, #0x4]
 *   @0x170ff8 cmp r3, #0
 *   @0x170ffc bne 0x170fe8 <_Z17GR_Surface_Createiii+0x50>
 *   @0x171000 mvn r0, #0
 *   @0x171004 add sp, sp, #20
 *   @0x171008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17100c ldr r4, [r3, #0xc]
 *   @0x171010 cmp r4, #0
 *   @0x171014 beq 0x171000 <_Z17GR_Surface_Createiii+0x68>
 *   @0x171018 mov r3, #4
 *   @0x17101c mov r0, r7
 *   @0x171020 str r3, [sp]
 *   @0x171024 mov r1, r6
 *   @0x171028 mov r3, #0
 *   @0x17102c mov r2, #1
 *   @0x171030 bl 0x173a24 <_Z23GR_Texture_Create_Emptyiibbi>
 *   @0x171034 ldr r3, [pc, #0x1d0]
 *   @0x171038 cmp r0, #0
 *   @0x17103c blt 0x171158 <_Z17GR_Surface_Createiii+0x1c0>
 *   @0x171040 stmib r4, {r0, r7}
 *   @0x171044 str r6, [r4, #0xc]
 *   @0x171048 ldr r3, [r5, r3]
 *   @0x17104c ldr r0, [r4]
 *   @0x171050 ldr r3, [r3]
 *   @0x171054 cmp r0, r3
 *   @0x171058 bne 0x171004 <_Z17GR_Surface_Createiii+0x6c>
 *   @0x17105c ldr r2, [pc, #0x1ac]
 *   @0x171060 ldr r3, [pc, #0x1ac]
 *   @0x171064 ldr r2, [r5, r2]
 *   @0x171068 str r7, [r2]
 *   @0x17106c ldr r3, [r5, r3]
 *   @0x171070 str r6, [r3]
 *   @0x171074 add sp, sp, #20
 *   @0x171078 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17107c ldr r3, [pc, #0x194]
 *   @0x171080 ldr r4, [pc, #0x194]
 *   @0x171084 add r3, pc, r3
 *   @0x171088 add r4, pc, r4
 *   @0x17108c ldr r0, [r3]
 *   @0x171090 b 0x1710a4 <_Z17GR_Surface_Createiii+0x10c>
 *   @0x171094 ldr r3, [r4]
 *   @0x171098 add r3, r3, #1
 *   @0x17109c str r3, [r4]
 *   @0x1710a0 mov r0, r3
 *   @0x1710a4 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x1710a8 subs r8, r0, #0
 *   @0x1710ac bne 0x171094 <_Z17GR_Surface_Createiii+0xfc>
 *   @0x1710b0 mov r0, #16
 *   @0x1710b4 bl 0x27c524 <_Znwj>
 *   @0x1710b8 ldr r1, [pc, #0x160]
 *   @0x1710bc ldr r12, [pc, #0x144]
 *   @0x1710c0 mov r3, #1
 *   @0x1710c4 add r1, pc, r1
 *   @0x1710c8 movw r2, #0x132
 *   @0x1710cc ldr r10, [r1]
 *   @0x1710d0 add lr, r10, r3
 *   @0x1710d4 str lr, [r1]
 *   @0x1710d8 ldr r1, [pc, #0x144]
 *   @0x1710dc add r1, pc, r1
 *   @0x1710e0 mov r4, r0
 *   @0x1710e4 mov r0, #16
 *   @0x1710e8 str r8, [r4, #0x4]
 *   @0x1710ec str r8, [r4, #0x8]
 *   @0x1710f0 str r8, [r4, #0xc]
 *   @0x1710f4 str r10, [r4]
 *   @0x1710f8 ldr r9, [r5, r12]
 *   @0x1710fc ldm r9, {r11, r12}
 *   @0x171100 and r12, r10, r12
 *   @0x171104 str r12, [sp, #0xc]
 *   @0x171108 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17110c ldr r12, [sp, #0xc]
 *   @0x171110 ldr r2, [r11, r12, lsl #3]
 *   @0x171114 add r3, r11, r12, lsl #3
 *   @0x171118 cmp r2, #0
 *   @0x17111c ldrne r2, [r3, #0x4]
 *   @0x171120 str r10, [r0, #0x8]
 *   @0x171124 str r4, [r0, #0xc]
 *   @0x171128 strne r2, [r0]
 *   @0x17112c streq r0, [r3, #0x4]
 *   @0x171130 strne r0, [r2, #0x4]
 *   @0x171134 strne r0, [r3, #0x4]
 *   @0x171138 ldr r3, [r9, #0x8]
 *   @0x17113c streq r0, [r11, r12, lsl #3]
 *   @0x171140 strne r8, [r0, #0x4]
 *   @0x171144 add r3, r3, #1
 *   @0x171148 streq r2, [r0, #0x4]
 *   @0x17114c streq r2, [r0]
 *   @0x171150 str r3, [r9, #0x8]
 *   @0x171154 b 0x171018 <_Z17GR_Surface_Createiii+0x80>
 *   @0x171158 ldr r3, [r5, r3]
 *   @0x17115c ldr r2, [r4]
 *   @0x171160 ldr r3, [r3]
 *   @0x171164 cmp r2, r3
 *   @0x171168 bne 0x171188 <_Z17GR_Surface_Createiii+0x1f0>
 *   @0x17116c ldr r0, [pc, #0x9c]
 *   @0x171170 mov r3, #1
 *   @0x171174 ldr r1, [pc, #0x98]
 *   @0x171178 ldr r0, [r5, r0]
 *   @0x17117c str r3, [r0]
 *   @0x171180 ldr r1, [r5, r1]
 *   @0x171184 str r3, [r1]
 *   @0x171188 ldr r0, [r9, #0x4]
 *   @0x17118c ldr r1, [r9]
 *   @0x171190 and r0, r2, r0
 *   @0x171194 ldr r4, [r1, r0, lsl #3]
 *   @0x171198 add r12, r1, r0, lsl #3
 *   @0x17119c cmp r4, #0
 *   @0x1711a0 bne 0x1711b4 <_Z17GR_Surface_Createiii+0x21c>
 *   @0x1711a4 b 0x171000 <_Z17GR_Surface_Createiii+0x68>
 *   @0x1711a8 ldr r4, [r4, #0x4]
 *   @0x1711ac cmp r4, #0
 *   @0x1711b0 beq 0x171000 <_Z17GR_Surface_Createiii+0x68>
 *   @0x1711b4 ldr r3, [r4, #0x8]
 *   @0x1711b8 cmp r2, r3
 *   @0x1711bc bne 0x1711a8 <_Z17GR_Surface_Createiii+0x210>
 *   @0x1711c0 ldm r4, {r2, r3}
 *   @0x1711c4 cmp r2, #0
 *   @0x1711c8 strne r3, [r2, #0x4]
 *   @0x1711cc ldrne r3, [r4, #0x4]
 *   @0x1711d0 streq r3, [r1, r0, lsl #3]
 *   @0x1711d4 cmp r3, #0
 *   @0x1711d8 ldr r0, [r4, #0xc]
 *   @0x1711dc strne r2, [r3]
 *   @0x1711e0 streq r2, [r12, #0x4]
 *   @0x1711e4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1711e8 mov r0, r4
 *   @0x1711ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1711f0 ldr r3, [r9, #0x8]
 *   @0x1711f4 mvn r0, #0
 *   @0x1711f8 add r3, r3, r0
 *   @0x1711fc str r3, [r9, #0x8]
 *   @0x171200 b 0x171004 <_Z17GR_Surface_Createiii+0x6c>
 *   @0x171204 eoreq r0, r8, r0, lsr #25
 *   @0x171208 .word 0xffffbec0
 *   @0x17120c .word 0xffffc988
 *   @0x171210 .word 0xffffdf38
 *   @0x171214 .word 0xffffdf40
 *   @0x171218 eorseq lr, r1, r12, lsl r7
 *   @0x17121c eorseq lr, r1, r8, lsl r7
 *   @0x171220 ldrsbteq lr, [r1], -r12
 *   @0x171224 andseq r10, sp, r8, asr #5
 *
 * ══ §35/42 CDS_Queue::Clear  0x20eacc  size 652  163 条（0x20eacc..0x20ed58）
 * @func 0x20eacc 0x20ed58  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UNLOCK_RVALUE_MUTEX()×4 / LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / CDS_Queue::Clear()+0xb8 / CDS_Queue::Clear()+0x170 / CDS_Queue::Clear()+0x25c
 * 字段偏移 top8: 0x4×17 / 0x8×14 / 0xc×11 / 0x10×4 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20eacc ldr r3, [r0, #0xc]
 *   @0x20ead0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20ead4 mov r6, #0
 *   @0x20ead8 cmp r3, r6
 *   @0x20eadc sub sp, sp, #20
 *   @0x20eae0 mov r11, r0
 *   @0x20eae4 str r6, [r0, #0x4]
 *   @0x20eae8 str r6, [r0, #0x8]
 *   @0x20eaec movgt r10, #5
 *   @0x20eaf0 movgt r5, r6
 *   @0x20eaf4 bgt 0x20eb18 <_ZN9CDS_Queue5ClearEv+0x4c>
 *   @0x20eaf8 b 0x20eb84 <_ZN9CDS_Queue5ClearEv+0xb8>
 *   @0x20eafc str r5, [r7, #0x8]
 *   @0x20eb00 add r6, r6, #1
 *   @0x20eb04 str r10, [r7, #0xc]
 *   @0x20eb08 str r5, [r9, r8]
 *   @0x20eb0c ldr r3, [r11, #0xc]
 *   @0x20eb10 cmp r3, r6
 *   @0x20eb14 ble 0x20eb84 <_ZN9CDS_Queue5ClearEv+0xb8>
 *   @0x20eb18 ldr r9, [r11, #0x10]
 *   @0x20eb1c lsl r8, r6, #4
 *   @0x20eb20 add r7, r9, r8
 *   @0x20eb24 ldr r12, [r7, #0xc]
 *   @0x20eb28 sub r0, r12, #1
 *   @0x20eb2c bic r0, r0, #-16777216
 *   @0x20eb30 bics r4, r0, #3
 *   @0x20eb34 bne 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20eb38 bic r12, r12, #-16777216
 *   @0x20eb3c cmp r12, #2
 *   @0x20eb40 beq 0x20ebbc <_ZN9CDS_Queue5ClearEv+0xf0>
 *   @0x20eb44 cmp r12, #3
 *   @0x20eb48 beq 0x20eb94 <_ZN9CDS_Queue5ClearEv+0xc8>
 *   @0x20eb4c cmp r12, #1
 *   @0x20eb50 bne 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20eb54 ldr r4, [r9, r8]
 *   @0x20eb58 cmp r4, #0
 *   @0x20eb5c beq 0x20eb7c <_ZN9CDS_Queue5ClearEv+0xb0>
 *   @0x20eb60 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20eb64 ldr r3, [r4, #0x4]
 *   @0x20eb68 sub r3, r3, #1
 *   @0x20eb6c str r3, [r4, #0x4]
 *   @0x20eb70 cmp r3, #0
 *   @0x20eb74 beq 0x20ebfc <_ZN9CDS_Queue5ClearEv+0x130>
 *   @0x20eb78 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20eb7c str r5, [r9, r8]
 *   @0x20eb80 b 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20eb84 mov r3, #0
 *   @0x20eb88 str r3, [r11, #0xc]
 *   @0x20eb8c add sp, sp, #20
 *   @0x20eb90 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20eb94 ldr r0, [r7, #0x8]
 *   @0x20eb98 tst r0, #8
 *   @0x20eb9c beq 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20eba0 ldr r0, [r9, r8]
 *   @0x20eba4 cmp r0, #0
 *   @0x20eba8 beq 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20ebac ldr r12, [r0]
 *   @0x20ebb0 ldr r12, [r12, #0x4]
 *   @0x20ebb4 blx r12
 *   @0x20ebb8 b 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20ebbc ldr r3, [r9, r8]
 *   @0x20ebc0 cmp r3, #0
 *   @0x20ebc4 str r3, [sp, #0x8]
 *   @0x20ebc8 beq 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20ebcc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20ebd0 ldr r3, [sp, #0x8]
 *   @0x20ebd4 ldr r0, [r3]
 *   @0x20ebd8 ldr r12, [r3, #0x8]
 *   @0x20ebdc sub r0, r0, #1
 *   @0x20ebe0 str r0, [r3]
 *   @0x20ebe4 cmp r7, r12
 *   @0x20ebe8 streq r4, [r3, #0x8]
 *   @0x20ebec cmp r0, #0
 *   @0x20ebf0 ble 0x20ec3c <_ZN9CDS_Queue5ClearEv+0x170>
 *   @0x20ebf4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20ebf8 b 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20ebfc ldr r0, [r4]
 *   @0x20ec00 str r3, [sp]
 *   @0x20ec04 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20ec08 ldr r3, [sp]
 *   @0x20ec0c str r3, [r4]
 *   @0x20ec10 str r3, [r4, #0x8]
 *   @0x20ec14 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20ec18 ldr r3, [r4, #0x4]
 *   @0x20ec1c sub r3, r3, #1
 *   @0x20ec20 str r3, [r4, #0x4]
 *   @0x20ec24 cmp r3, #0
 *   @0x20ec28 beq 0x20ecc8 <_ZN9CDS_Queue5ClearEv+0x1fc>
 *   @0x20ec2c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20ec30 mov r0, r4
 *   @0x20ec34 bl 0x27d1d0 <_ZdlPv>
 *   @0x20ec38 b 0x20eb78 <_ZN9CDS_Queue5ClearEv+0xac>
 *   @0x20ec3c ldr r3, [sp, #0x8]
 *   @0x20ec40 ldr r0, [r3, #0x10]
 *   @0x20ec44 cmp r0, #0
 *   @0x20ec48 movgt r3, #0
 *   @0x20ec4c strgt r3, [sp, #0x4]
 *   @0x20ec50 ble 0x20ed28 <_ZN9CDS_Queue5ClearEv+0x25c>
 *   @0x20ec54 ldr r3, [sp, #0x8]
 *   @0x20ec58 ldr r0, [r3, #0x4]
 *   @0x20ec5c ldr r3, [sp, #0x4]
 *   @0x20ec60 add r3, r0, r3, lsl #3
 *   @0x20ec64 str r3, [sp, #0xc]
 *   @0x20ec68 ldr r3, [sp, #0x4]
 *   @0x20ec6c ldr r12, [r0, r3, lsl #3]
 *   @0x20ec70 ldr r3, [sp, #0xc]
 *   @0x20ec74 ldr r4, [r3, #0x4]
 *   @0x20ec78 add r12, r4, r12, lsl #4
 *   @0x20ec7c cmp r4, r12
 *   @0x20ec80 blo 0x20ec9c <_ZN9CDS_Queue5ClearEv+0x1d0>
 *   @0x20ec84 b 0x20ed50 <_ZN9CDS_Queue5ClearEv+0x284>
 *   @0x20ec88 str r5, [r4, #0x8]
 *   @0x20ec8c str r10, [r4, #0xc]
 *   @0x20ec90 str r5, [r4], #16
 *   @0x20ec94 cmp r12, r4
 *   @0x20ec98 bls 0x20ecf4 <_ZN9CDS_Queue5ClearEv+0x228>
 *   @0x20ec9c ldr r0, [r4, #0xc]
 *   @0x20eca0 sub r0, r0, #1
 *   @0x20eca4 bic r0, r0, #-16777216
 *   @0x20eca8 bic r0, r0, #3
 *   @0x20ecac cmp r0, #0
 *   @0x20ecb0 bne 0x20ec88 <_ZN9CDS_Queue5ClearEv+0x1bc>
 *   @0x20ecb4 mov r0, r4
 *   @0x20ecb8 str r12, [sp]
 *   @0x20ecbc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20ecc0 ldr r12, [sp]
 *   @0x20ecc4 b 0x20ec88 <_ZN9CDS_Queue5ClearEv+0x1bc>
 *   @0x20ecc8 ldr r0, [r4]
 *   @0x20eccc str r3, [sp]
 *   @0x20ecd0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20ecd4 ldr r3, [sp]
 *   @0x20ecd8 mov r0, r4
 *   @0x20ecdc str r3, [r4]
 *   @0x20ece0 str r3, [r4, #0x8]
 *   @0x20ece4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20ece8 mov r0, r4
 *   @0x20ecec bl 0x27d1d0 <_ZdlPv>
 *   @0x20ecf0 b 0x20ec2c <_ZN9CDS_Queue5ClearEv+0x160>
 *   @0x20ecf4 ldr r3, [sp, #0xc]
 *   @0x20ecf8 ldr r0, [r3, #0x4]
 *   @0x20ecfc ldr r3, [sp, #0x4]
 *   @0x20ed00 add r3, r3, #1
 *   @0x20ed04 str r3, [sp, #0x4]
 *   @0x20ed08 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20ed0c ldr r3, [sp, #0x8]
 *   @0x20ed10 ldr r0, [r3, #0x10]
 *   @0x20ed14 ldr r3, [sp, #0xc]
 *   @0x20ed18 str r5, [r3, #0x4]
 *   @0x20ed1c ldr r3, [sp, #0x4]
 *   @0x20ed20 cmp r3, r0
 *   @0x20ed24 blt 0x20ec54 <_ZN9CDS_Queue5ClearEv+0x188>
 *   @0x20ed28 ldr r3, [sp, #0x8]
 *   @0x20ed2c ldr r0, [r3, #0x4]
 *   @0x20ed30 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20ed34 ldr r3, [sp, #0x8]
 *   @0x20ed38 str r5, [r3, #0x4]
 *   @0x20ed3c mov r0, r3
 *   @0x20ed40 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20ed44 str r5, [r9, r8]
 *   @0x20ed48 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20ed4c b 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30>
 *   @0x20ed50 mov r0, r4
 *   @0x20ed54 b 0x20ecfc <_ZN9CDS_Queue5ClearEv+0x230>
 *
 * ══ §36/42 b2Simplex::Solve3  0x2c3d14  size 652  163 条（0x2c3d14..0x2c3fa0）
 * @func 0x2c3d14 0x2c3fa0  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Simplex::Solve3()+0xa8×2 / b2Simplex::Solve3()+0xcc×2 / b2Simplex::Solve3()+0x130×2 / b2Simplex::Solve3()+0x168 / b2Simplex::Solve3()+0x1e0 / b2Simplex::Solve3()+0x20c / b2Simplex::Solve3()+0x188 / b2Simplex::Solve3()+0x1b4
 * 字段偏移 top8: 0x6c×7 / 0x18×1 / 0x3c×1 / 0x60×1
 * VFP 指令 99 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c3d14 vldr s14, [r0, #20]
 *   @0x2c3d18 vldr s12, [r0, #56]
 *   @0x2c3d1c vsub.f32 s1, s12, s14
 *   @0x2c3d20 vldr s15, [r0, #16]
 *   @0x2c3d24 vldr s10, [r0, #88]
 *   @0x2c3d28 vldr s11, [r0, #92]
 *   @0x2c3d2c vldr s13, [r0, #52]
 *   @0x2c3d30 push {r4, r5}
 *   @0x2c3d34 mov r12, r0
 *   @0x2c3d38 vsub.f32 s6, s10, s15
 *   @0x2c3d3c vsub.f32 s2, s11, s14
 *   @0x2c3d40 vmul.f32 s8, s14, s1
 *   @0x2c3d44 vsub.f32 s3, s13, s15
 *   @0x2c3d48 vmul.f32 s7, s14, s2
 *   @0x2c3d4c vmul.f32 s9, s1, s6
 *   @0x2c3d50 vmul.f32 s4, s11, s15
 *   @0x2c3d54 vmul.f32 s5, s13, s14
 *   @0x2c3d58 vmla.f32 s8, s15, s3
 *   @0x2c3d5c vnmls.f32 s9, s3, s2
 *   @0x2c3d60 vnmls.f32 s4, s10, s14
 *   @0x2c3d64 vnmls.f32 s5, s12, s15
 *   @0x2c3d68 vmla.f32 s7, s15, s6
 *   @0x2c3d6c vmul.f32 s14, s11, s2
 *   @0x2c3d70 vmul.f32 s15, s12, s1
 *   @0x2c3d74 vneg.f32 s2, s8
 *   @0x2c3d78 vcmpe.f32 s2, #0
 *   @0x2c3d7c vmla.f32 s14, s10, s6
 *   @0x2c3d80 vmrs APSR_nzcv, fpscr
 *   @0x2c3d84 vmla.f32 s15, s13, s3
 *   @0x2c3d88 vmul.f32 s4, s9, s4
 *   @0x2c3d8c vmul.f32 s5, s9, s5
 *   @0x2c3d90 vneg.f32 s6, s7
 *   @0x2c3d94 bls 0x2c3e7c <_ZN9b2Simplex6Solve3Ev+0x168>
 *   @0x2c3d98 vcmpe.f32 s15, #0
 *   @0x2c3d9c vmrs APSR_nzcv, fpscr
 *   @0x2c3da0 ble 0x2c3dbc <_ZN9b2Simplex6Solve3Ev+0xa8>
 *   @0x2c3da4 vcmpe.f32 s2, #0
 *   @0x2c3da8 vmrs APSR_nzcv, fpscr
 *   @0x2c3dac ble 0x2c3dbc <_ZN9b2Simplex6Solve3Ev+0xa8>
 *   @0x2c3db0 vcmpe.f32 s5, #0
 *   @0x2c3db4 vmrs APSR_nzcv, fpscr
 *   @0x2c3db8 bls 0x2c3ef4 <_ZN9b2Simplex6Solve3Ev+0x1e0>
 *   @0x2c3dbc vcmpe.f32 s14, #0
 *   @0x2c3dc0 vmrs APSR_nzcv, fpscr
 *   @0x2c3dc4 ble 0x2c3de0 <_ZN9b2Simplex6Solve3Ev+0xcc>
 *   @0x2c3dc8 vcmpe.f32 s6, #0
 *   @0x2c3dcc vmrs APSR_nzcv, fpscr
 *   @0x2c3dd0 ble 0x2c3de0 <_ZN9b2Simplex6Solve3Ev+0xcc>
 *   @0x2c3dd4 vcmpe.f32 s4, #0
 *   @0x2c3dd8 vmrs APSR_nzcv, fpscr
 *   @0x2c3ddc bls 0x2c3f20 <_ZN9b2Simplex6Solve3Ev+0x20c>
 *   @0x2c3de0 vsub.f32 s6, s11, s12
 *   @0x2c3de4 vmul.f32 s8, s12, s6
 *   @0x2c3de8 vsub.f32 s7, s10, s13
 *   @0x2c3dec vmla.f32 s8, s13, s7
 *   @0x2c3df0 vcmpe.f32 s15, #0
 *   @0x2c3df4 vneg.f32 s3, s8
 *   @0x2c3df8 vmrs APSR_nzcv, fpscr
 *   @0x2c3dfc bls 0x2c3e9c <_ZN9b2Simplex6Solve3Ev+0x188>
 *   @0x2c3e00 vmul.f32 s15, s11, s6
 *   @0x2c3e04 vcmpe.f32 s14, #0
 *   @0x2c3e08 vmla.f32 s15, s10, s7
 *   @0x2c3e0c vmrs APSR_nzcv, fpscr
 *   @0x2c3e10 bls 0x2c3ec8 <_ZN9b2Simplex6Solve3Ev+0x1b4>
 *   @0x2c3e14 vmul.f32 s12, s10, s12
 *   @0x2c3e18 vnmls.f32 s12, s11, s13
 *   @0x2c3e1c vcmpe.f32 s15, #0
 *   @0x2c3e20 vmul.f32 s12, s9, s12
 *   @0x2c3e24 vmrs APSR_nzcv, fpscr
 *   @0x2c3e28 ble 0x2c3e44 <_ZN9b2Simplex6Solve3Ev+0x130>
 *   @0x2c3e2c vcmpe.f32 s3, #0
 *   @0x2c3e30 vmrs APSR_nzcv, fpscr
 *   @0x2c3e34 ble 0x2c3e44 <_ZN9b2Simplex6Solve3Ev+0x130>
 *   @0x2c3e38 vcmpe.f32 s12, #0
 *   @0x2c3e3c vmrs APSR_nzcv, fpscr
 *   @0x2c3e40 bls 0x2c3f6c <_ZN9b2Simplex6Solve3Ev+0x258>
 *   @0x2c3e44 vadd.f32 s15, s12, s4
 *   @0x2c3e48 mov r3, #3
 *   @0x2c3e4c str r3, [r12, #0x6c]
 *   @0x2c3e50 vadd.f32 s15, s15, s5
 *   @0x2c3e54 vmov.f32 s14, #1.000000e+00
 *   @0x2c3e58 vdiv.f32 s15, s14, s15
 *   @0x2c3e5c vmul.f32 s12, s12, s15
 *   @0x2c3e60 vmul.f32 s4, s4, s15
 *   @0x2c3e64 vstr s12, [r12, #24]
 *   @0x2c3e68 vmul.f32 s5, s5, s15
 *   @0x2c3e6c vstr s4, [r12, #60]
 *   @0x2c3e70 vstr s5, [r12, #96]
 *   @0x2c3e74 pop {r4, r5}
 *   @0x2c3e78 bx lr
 *   @0x2c3e7c vcmpe.f32 s6, #0
 *   @0x2c3e80 vmrs APSR_nzcv, fpscr
 *   @0x2c3e84 bhi 0x2c3d98 <_ZN9b2Simplex6Solve3Ev+0x84>
 *   @0x2c3e88 mov r2, #1065353216
 *   @0x2c3e8c mov r3, #1
 *   @0x2c3e90 str r2, [r0, #0x18]
 *   @0x2c3e94 str r3, [r0, #0x6c]
 *   @0x2c3e98 b 0x2c3e74 <_ZN9b2Simplex6Solve3Ev+0x160>
 *   @0x2c3e9c vcmpe.f32 s3, #0
 *   @0x2c3ea0 vmrs APSR_nzcv, fpscr
 *   @0x2c3ea4 bhi 0x2c3e00 <_ZN9b2Simplex6Solve3Ev+0xec>
 *   @0x2c3ea8 add r5, r12, #36
 *   @0x2c3eac mov r2, #1065353216
 *   @0x2c3eb0 mov r3, #1
 *   @0x2c3eb4 str r2, [r12, #0x3c]
 *   @0x2c3eb8 str r3, [r12, #0x6c]
 *   @0x2c3ebc mov r4, r12
 *   @0x2c3ec0 ldm r5!, {r0, r1, r2, r3}
 *   @0x2c3ec4 b 0x2c3f50 <_ZN9b2Simplex6Solve3Ev+0x23c>
 *   @0x2c3ec8 vcmpe.f32 s15, #0
 *   @0x2c3ecc vmrs APSR_nzcv, fpscr
 *   @0x2c3ed0 bhi 0x2c3e14 <_ZN9b2Simplex6Solve3Ev+0x100>
 *   @0x2c3ed4 add r5, r12, #72
 *   @0x2c3ed8 mov r2, #1065353216
 *   @0x2c3edc mov r3, #1
 *   @0x2c3ee0 str r2, [r12, #0x60]
 *   @0x2c3ee4 str r3, [r12, #0x6c]
 *   @0x2c3ee8 mov r4, r12
 *   @0x2c3eec ldm r5!, {r0, r1, r2, r3}
 *   @0x2c3ef0 b 0x2c3f50 <_ZN9b2Simplex6Solve3Ev+0x23c>
 *   @0x2c3ef4 vsub.f32 s8, s15, s8
 *   @0x2c3ef8 mov r3, #2
 *   @0x2c3efc pop {r4, r5}
 *   @0x2c3f00 str r3, [r12, #0x6c]
 *   @0x2c3f04 vmov.f32 s14, #1.000000e+00
 *   @0x2c3f08 vdiv.f32 s8, s14, s8
 *   @0x2c3f0c vmul.f32 s15, s8, s15
 *   @0x2c3f10 vmul.f32 s8, s2, s8
 *   @0x2c3f14 vstr s15, [r12, #24]
 *   @0x2c3f18 vstr s8, [r12, #60]
 *   @0x2c3f1c bx lr
 *   @0x2c3f20 vsub.f32 s7, s14, s7
 *   @0x2c3f24 add r5, r12, #72
 *   @0x2c3f28 add r4, r12, #36
 *   @0x2c3f2c mov r3, #2
 *   @0x2c3f30 str r3, [r12, #0x6c]
 *   @0x2c3f34 vmov.f32 s15, #1.000000e+00
 *   @0x2c3f38 vdiv.f32 s7, s15, s7
 *   @0x2c3f3c vmul.f32 s6, s6, s7
 *   @0x2c3f40 vmul.f32 s14, s7, s14
 *   @0x2c3f44 vstr s6, [r12, #96]
 *   @0x2c3f48 ldm r5!, {r0, r1, r2, r3}
 *   @0x2c3f4c vstr s14, [r12, #24]
 *   @0x2c3f50 stm r4!, {r0, r1, r2, r3}
 *   @0x2c3f54 ldm r5!, {r0, r1, r2, r3}
 *   @0x2c3f58 ldr r12, [r5]
 *   @0x2c3f5c stm r4!, {r0, r1, r2, r3}
 *   @0x2c3f60 str r12, [r4]
 *   @0x2c3f64 pop {r4, r5}
 *   @0x2c3f68 bx lr
 *   @0x2c3f6c vsub.f32 s8, s15, s8
 *   @0x2c3f70 add r5, r12, #72
 *   @0x2c3f74 mov r3, #2
 *   @0x2c3f78 mov r4, r12
 *   @0x2c3f7c str r3, [r12, #0x6c]
 *   @0x2c3f80 vmov.f32 s14, #1.000000e+00
 *   @0x2c3f84 vdiv.f32 s8, s14, s8
 *   @0x2c3f88 vmul.f32 s3, s3, s8
 *   @0x2c3f8c vmul.f32 s15, s8, s15
 *   @0x2c3f90 vstr s3, [r12, #96]
 *   @0x2c3f94 ldm r5!, {r0, r1, r2, r3}
 *   @0x2c3f98 vstr s15, [r12, #60]
 *   @0x2c3f9c b 0x2c3f50 <_ZN9b2Simplex6Solve3Ev+0x23c>
 *
 * ══ §37/42 CDS_Map::Add  0x20d760  size 648  162 条（0x20d760..0x20d9e8）
 * @func 0x20d760 0x20d9e8  size 648  162 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYSetString(RValue*, char const*)×2 / UNLOCK_RVALUE_MUTEX()×2 / FREE_RValue__Pre(RValue*)×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CDS_Map::Add(RValue*, RValue*)
 * 字段偏移 top8: 0x4×12 / 0x10×8 / 0x8×6 / 0xc×5 / 0x18×2 / 0x1c×2 / 0x48×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20d760 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20d764 sub sp, sp, #36
 *   @0x20d768 mov r8, r0
 *   @0x20d76c mov r4, r2
 *   @0x20d770 ldr r6, [sp, #0x48]
 *   @0x20d774 mov r0, sp
 *   @0x20d778 mov r5, r3
 *   @0x20d77c mov r2, #1
 *   @0x20d780 mov r3, #0
 *   @0x20d784 str r2, [sp, #0xc]
 *   @0x20d788 str r3, [sp]
 *   @0x20d78c str r3, [sp, #0x4]
 *   @0x20d790 str r3, [sp, #0x8]
 *   @0x20d794 str r3, [sp, #0x10]
 *   @0x20d798 str r3, [sp, #0x14]
 *   @0x20d79c str r3, [sp, #0x18]
 *   @0x20d7a0 str r3, [sp, #0x1c]
 *   @0x20d7a4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20d7a8 cmp r6, #0
 *   @0x20d7ac strd r4, r5, [sp, #16]
 *   @0x20d7b0 add r4, sp, #16
 *   @0x20d7b4 beq 0x20d7c4 <_ZN7CDS_Map3AddEPKcdS1_+0x64>
 *   @0x20d7b8 mov r1, r6
 *   @0x20d7bc mov r0, r4
 *   @0x20d7c0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20d7c4 mov r0, r8
 *   @0x20d7c8 mov r1, sp
 *   @0x20d7cc mov r2, r4
 *   @0x20d7d0 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x20d7d4 ldr r3, [sp, #0xc]
 *   @0x20d7d8 sub r3, r3, #1
 *   @0x20d7dc bic r3, r3, #-16777216
 *   @0x20d7e0 bic r3, r3, #3
 *   @0x20d7e4 cmp r3, #0
 *   @0x20d7e8 mov r6, r0
 *   @0x20d7ec beq 0x20d874 <_ZN7CDS_Map3AddEPKcdS1_+0x114>
 *   @0x20d7f0 ldr r2, [sp, #0x1c]
 *   @0x20d7f4 mov r1, #0
 *   @0x20d7f8 mov r0, #5
 *   @0x20d7fc str r1, [sp, #0x8]
 *   @0x20d800 sub r3, r2, #1
 *   @0x20d804 str r1, [sp]
 *   @0x20d808 bic r3, r3, #-16777216
 *   @0x20d80c str r0, [sp, #0xc]
 *   @0x20d810 bics r5, r3, #3
 *   @0x20d814 beq 0x20d824 <_ZN7CDS_Map3AddEPKcdS1_+0xc4>
 *   @0x20d818 mov r0, r6
 *   @0x20d81c add sp, sp, #36
 *   @0x20d820 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20d824 bic r2, r2, #-16777216
 *   @0x20d828 cmp r2, #2
 *   @0x20d82c beq 0x20d8a8 <_ZN7CDS_Map3AddEPKcdS1_+0x148>
 *   @0x20d830 cmp r2, #3
 *   @0x20d834 beq 0x20d880 <_ZN7CDS_Map3AddEPKcdS1_+0x120>
 *   @0x20d838 cmp r2, #1
 *   @0x20d83c bne 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8>
 *   @0x20d840 ldr r4, [sp, #0x10]
 *   @0x20d844 cmp r4, #0
 *   @0x20d848 beq 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8>
 *   @0x20d84c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d850 ldr r5, [r4, #0x4]
 *   @0x20d854 sub r5, r5, #1
 *   @0x20d858 str r5, [r4, #0x4]
 *   @0x20d85c cmp r5, #0
 *   @0x20d860 beq 0x20d948 <_ZN7CDS_Map3AddEPKcdS1_+0x1e8>
 *   @0x20d864 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d868 mov r0, r6
 *   @0x20d86c add sp, sp, #36
 *   @0x20d870 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20d874 mov r0, sp
 *   @0x20d878 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20d87c b 0x20d7f0 <_ZN7CDS_Map3AddEPKcdS1_+0x90>
 *   @0x20d880 ldr r3, [sp, #0x18]
 *   @0x20d884 tst r3, #8
 *   @0x20d888 beq 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8>
 *   @0x20d88c ldr r0, [sp, #0x10]
 *   @0x20d890 cmp r0, #0
 *   @0x20d894 beq 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8>
 *   @0x20d898 ldr r3, [r0]
 *   @0x20d89c ldr r3, [r3, #0x4]
 *   @0x20d8a0 blx r3
 *   @0x20d8a4 b 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8>
 *   @0x20d8a8 ldr r8, [sp, #0x10]
 *   @0x20d8ac cmp r8, #0
 *   @0x20d8b0 beq 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8>
 *   @0x20d8b4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d8b8 ldr r3, [r8]
 *   @0x20d8bc ldr r2, [r8, #0x8]
 *   @0x20d8c0 sub r3, r3, #1
 *   @0x20d8c4 str r3, [r8]
 *   @0x20d8c8 cmp r2, r4
 *   @0x20d8cc streq r5, [r8, #0x8]
 *   @0x20d8d0 cmp r3, #0
 *   @0x20d8d4 bgt 0x20d864 <_ZN7CDS_Map3AddEPKcdS1_+0x104>
 *   @0x20d8d8 ldr r3, [r8, #0x10]
 *   @0x20d8dc cmp r3, #0
 *   @0x20d8e0 movgt r7, #0
 *   @0x20d8e4 movgt r11, #5
 *   @0x20d8e8 movgt r5, r7
 *   @0x20d8ec ble 0x20d99c <_ZN7CDS_Map3AddEPKcdS1_+0x23c>
 *   @0x20d8f0 ldr r3, [r8, #0x4]
 *   @0x20d8f4 add r9, r3, r7, lsl #3
 *   @0x20d8f8 ldr r10, [r3, r7, lsl #3]
 *   @0x20d8fc ldr r4, [r9, #0x4]
 *   @0x20d900 add r10, r4, r10, lsl #4
 *   @0x20d904 cmp r4, r10
 *   @0x20d908 blo 0x20d924 <_ZN7CDS_Map3AddEPKcdS1_+0x1c4>
 *   @0x20d90c b 0x20d9bc <_ZN7CDS_Map3AddEPKcdS1_+0x25c>
 *   @0x20d910 str r5, [r4, #0x8]
 *   @0x20d914 str r11, [r4, #0xc]
 *   @0x20d918 str r5, [r4], #16
 *   @0x20d91c cmp r10, r4
 *   @0x20d920 bls 0x20d980 <_ZN7CDS_Map3AddEPKcdS1_+0x220>
 *   @0x20d924 ldr r3, [r4, #0xc]
 *   @0x20d928 sub r3, r3, #1
 *   @0x20d92c bic r3, r3, #-16777216
 *   @0x20d930 bic r3, r3, #3
 *   @0x20d934 cmp r3, #0
 *   @0x20d938 bne 0x20d910 <_ZN7CDS_Map3AddEPKcdS1_+0x1b0>
 *   @0x20d93c mov r0, r4
 *   @0x20d940 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20d944 b 0x20d910 <_ZN7CDS_Map3AddEPKcdS1_+0x1b0>
 *   @0x20d948 ldr r0, [r4]
 *   @0x20d94c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d950 str r5, [r4]
 *   @0x20d954 str r5, [r4, #0x8]
 *   @0x20d958 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d95c ldr r5, [r4, #0x4]
 *   @0x20d960 sub r5, r5, #1
 *   @0x20d964 str r5, [r4, #0x4]
 *   @0x20d968 cmp r5, #0
 *   @0x20d96c beq 0x20d9c4 <_ZN7CDS_Map3AddEPKcdS1_+0x264>
 *   @0x20d970 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d974 mov r0, r4
 *   @0x20d978 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d97c b 0x20d864 <_ZN7CDS_Map3AddEPKcdS1_+0x104>
 *   @0x20d980 ldr r0, [r9, #0x4]
 *   @0x20d984 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20d988 ldr r3, [r8, #0x10]
 *   @0x20d98c add r7, r7, #1
 *   @0x20d990 str r5, [r9, #0x4]
 *   @0x20d994 cmp r7, r3
 *   @0x20d998 blt 0x20d8f0 <_ZN7CDS_Map3AddEPKcdS1_+0x190>
 *   @0x20d99c ldr r0, [r8, #0x4]
 *   @0x20d9a0 mov r4, #0
 *   @0x20d9a4 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20d9a8 str r4, [r8, #0x4]
 *   @0x20d9ac mov r0, r8
 *   @0x20d9b0 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20d9b4 str r4, [sp, #0x10]
 *   @0x20d9b8 b 0x20d864 <_ZN7CDS_Map3AddEPKcdS1_+0x104>
 *   @0x20d9bc mov r0, r4
 *   @0x20d9c0 b 0x20d984 <_ZN7CDS_Map3AddEPKcdS1_+0x224>
 *   @0x20d9c4 ldr r0, [r4]
 *   @0x20d9c8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d9cc mov r0, r4
 *   @0x20d9d0 str r5, [r4]
 *   @0x20d9d4 str r5, [r4, #0x8]
 *   @0x20d9d8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20d9dc mov r0, r4
 *   @0x20d9e0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d9e4 b 0x20d970 <_ZN7CDS_Map3AddEPKcdS1_+0x210>
 *
 * ══ §38/42 CSkeletonInstance::SpriteCollision  0xbf0fc  size 632  158 条（0xbf0fc..0xbf374）
 * @func 0xbf0fc 0xbf374  size 632  158 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::SpriteCollision(int, float, float, float, float, float, CSprite*, tagYYRECT*, int, float, float, float, float, float)+0x23c×2 / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) / CSkeletonInstance::SpriteCollision(int, float, float, float, float, float, CSprite*, tagYYRECT*, int, float, float, float, float, float)+0x254 / CSprite::UnpackWADMask(int) / CSkeletonInstance::SpriteCollision(int, float, float, float, float, float, CSprite*, tagYYRECT*, int, float, float, float, float, float)+0x84 / __aeabi_idivmod / 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x20×3 / 0x4×2 / 0x14×2 / 0x68×1 / 0x74×1 / 0xc×1 / 0x6c×1 / 0x78×1
 * VFP 指令 79 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbf0fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbf100 vpush {d8, d9, d10, d11, d12}
 *   @0xbf104 sub sp, sp, #28
 *   @0xbf108 vldr s24, [sp, #128]
 *   @0xbf10c mov r12, #0
 *   @0xbf110 mov r8, r0
 *   @0xbf114 ldr lr, [sp, #0x68]
 *   @0xbf118 vldr s18, [sp, #132]
 *   @0xbf11c ldr r5, [sp, #0x74]
 *   @0xbf120 vldr s17, [sp, #144]
 *   @0xbf124 str r12, [sp, #0xc]
 *   @0xbf128 str lr, [sp]
 *   @0xbf12c ldr lr, [sp, #0x6c]
 *   @0xbf130 ldr r4, [sp, #0x78]
 *   @0xbf134 ldr r9, [sp, #0x7c]
 *   @0xbf138 str lr, [sp, #0x4]
 *   @0xbf13c ldr lr, [sp, #0x70]
 *   @0xbf140 str lr, [sp, #0x8]
 *   @0xbf144 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbf148 cmp r5, #0
 *   @0xbf14c beq 0xbf350 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x254>
 *   @0xbf150 ldr r1, [r5, #0x18]
 *   @0xbf154 cmp r1, #0
 *   @0xbf158 ble 0xbf350 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x254>
 *   @0xbf15c mov r0, r5
 *   @0xbf160 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi>
 *   @0xbf164 ldr r6, [r5, #0x3c]
 *   @0xbf168 cmp r6, #0
 *   @0xbf16c ble 0xbf180 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x84>
 *   @0xbf170 mov r0, r9
 *   @0xbf174 mov r1, r6
 *   @0xbf178 bl 0x318dec <__aeabi_idivmod>
 *   @0xbf17c mov r9, r1
 *   @0xbf180 vldr s11, [r4]
 *   @0xbf184 vcvt.f32.s32 s15, s11
 *   @0xbf188 ldr r3, [r8, #0x20]
 *   @0xbf18c vldr s14, [r3, #12]
 *   @0xbf190 cmp r9, #0
 *   @0xbf194 vldr s11, [r4, #8]
 *   @0xbf198 addlt r9, r9, r6
 *   @0xbf19c vldr s12, [sp, #136]
 *   @0xbf1a0 vldr s13, [sp, #140]
 *   @0xbf1a4 vldr s20, [pc, #452]
 *   @0xbf1a8 vcmpe.f32 s14, s15
 *   @0xbf1ac vmrs APSR_nzcv, fpscr
 *   @0xbf1b0 vcvtle.s32.f32 s15, s15
 *   @0xbf1b4 vcvtgt.s32.f32 s14, s14
 *   @0xbf1b8 vmovle r6, s15
 *   @0xbf1bc vcvt.f32.s32 s15, s11
 *   @0xbf1c0 vmovgt r6, s14
 *   @0xbf1c4 vldr s14, [r3, #20]
 *   @0xbf1c8 vcmpe.f32 s14, s15
 *   @0xbf1cc vmov.f32 s22, #1.000000e+00
 *   @0xbf1d0 vmrs APSR_nzcv, fpscr
 *   @0xbf1d4 vcvtpl.s32.f32 s15, s15
 *   @0xbf1d8 vcvtmi.s32.f32 s14, s14
 *   @0xbf1dc vstrpl s15, [sp, #20]
 *   @0xbf1e0 vdiv.f32 s19, s22, s12
 *   @0xbf1e4 vldr s12, [r4, #4]
 *   @0xbf1e8 vstrmi s14, [sp, #20]
 *   @0xbf1ec vldr s14, [r3, #16]
 *   @0xbf1f0 vcvt.f32.s32 s15, s12
 *   @0xbf1f4 vcmpe.f32 s14, s15
 *   @0xbf1f8 vmrs APSR_nzcv, fpscr
 *   @0xbf1fc vcvtle.s32.f32 s15, s15
 *   @0xbf200 vcvtgt.s32.f32 s14, s14
 *   @0xbf204 vmovle r7, s15
 *   @0xbf208 vldr s15, [r4, #12]
 *   @0xbf20c vcvt.f32.s32 s15, s15
 *   @0xbf210 vmovgt r7, s14
 *   @0xbf214 vldr s14, [r3, #24]
 *   @0xbf218 vdiv.f32 s22, s22, s13
 *   @0xbf21c vnmul.f32 s13, s17, s20
 *   @0xbf220 vcmpe.f32 s14, s15
 *   @0xbf224 vmov r0, s13
 *   @0xbf228 vmrs APSR_nzcv, fpscr
 *   @0xbf22c vcvtmi.s32.f32 s14, s14
 *   @0xbf230 vcvtpl.s32.f32 s15, s15
 *   @0xbf234 vmovmi r11, s14
 *   @0xbf238 vmovpl r11, s15
 *   @0xbf23c bl 0xb6580 <sinf@plt>
 *   @0xbf240 vmul.f32 s20, s17, s20
 *   @0xbf244 vmov s16, r0
 *   @0xbf248 vmov r0, s20
 *   @0xbf24c bl 0xb658c <cosf@plt>
 *   @0xbf250 ldr r3, [sp, #0x14]
 *   @0xbf254 cmp r6, r3
 *   @0xbf258 vmov s20, r0
 *   @0xbf25c bgt 0xbf350 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x254>
 *   @0xbf260 lsl r9, r9, #3
 *   @0xbf264 cmp r7, r11
 *   @0xbf268 bgt 0xbf340 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x244>
 *   @0xbf26c vmov s11, r6
 *   @0xbf270 mov r4, r7
 *   @0xbf274 vcvt.f32.s32 s23, s11
 *   @0xbf278 vsub.f32 s21, s23, s24
 *   @0xbf27c vmul.f32 s17, s20, s21
 *   @0xbf280 vmul.f32 s21, s16, s21
 *   @0xbf284 vmov s11, r4
 *   @0xbf288 ldr r2, [r5, #0x28]
 *   @0xbf28c add r4, r4, #1
 *   @0xbf290 vcvt.f32.s32 s13, s11
 *   @0xbf294 vldr s11, [r5, #36]
 *   @0xbf298 vsub.f32 s14, s13, s18
 *   @0xbf29c vmov.f32 s12, s17
 *   @0xbf2a0 vmla.f32 s12, s14, s16
 *   @0xbf2a4 vcvt.f32.s32 s15, s11
 *   @0xbf2a8 vmla.f32 s15, s12, s19
 *   @0xbf2ac vcvt.s32.f32 s15, s15
 *   @0xbf2b0 vmov r3, s15
 *   @0xbf2b4 cmp r3, #0
 *   @0xbf2b8 blt 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c>
 *   @0xbf2bc ldr r0, [r5, #0x1c]
 *   @0xbf2c0 cmp r3, r0
 *   @0xbf2c4 bge 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c>
 *   @0xbf2c8 vmov.f32 s12, s21
 *   @0xbf2cc vmov s11, r2
 *   @0xbf2d0 vnmls.f32 s12, s20, s14
 *   @0xbf2d4 vcvt.f32.s32 s15, s11
 *   @0xbf2d8 vmla.f32 s15, s12, s22
 *   @0xbf2dc vcvt.s32.f32 s15, s15
 *   @0xbf2e0 vmov r12, s15
 *   @0xbf2e4 cmp r12, #0
 *   @0xbf2e8 blt 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c>
 *   @0xbf2ec ldr r2, [r5, #0x20]
 *   @0xbf2f0 cmp r12, r2
 *   @0xbf2f4 bge 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c>
 *   @0xbf2f8 ldrb r10, [r5, #0x31]
 *   @0xbf2fc vmov r1, s23
 *   @0xbf300 cmp r10, #0
 *   @0xbf304 vmov r2, s13
 *   @0xbf308 beq 0xbf328 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x22c>
 *   @0xbf30c ldr r10, [r5, #0x40]
 *   @0xbf310 add r10, r10, r9
 *   @0xbf314 ldr r10, [r10, #0x4]
 *   @0xbf318 mla r0, r0, r12, r10
 *   @0xbf31c ldrb r3, [r0, r3]
 *   @0xbf320 cmp r3, #0
 *   @0xbf324 beq 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c>
 *   @0xbf328 ldr r0, [r8, #0x20]
 *   @0xbf32c bl 0x28ac8c <spSkeletonBounds_containsPoint>
 *   @0xbf330 cmp r0, #0
 *   @0xbf334 bne 0xbf360 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x264>
 *   @0xbf338 cmp r11, r4
 *   @0xbf33c bge 0xbf284 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x188>
 *   @0xbf340 ldr r3, [sp, #0x14]
 *   @0xbf344 add r6, r6, #1
 *   @0xbf348 cmp r3, r6
 *   @0xbf34c bge 0xbf264 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x168>
 *   @0xbf350 mov r0, #0
 *   @0xbf354 add sp, sp, #28
 *   @0xbf358 vpop {d8, d9, d10, d11, d12}
 *   @0xbf35c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xbf360 mov r0, #1
 *   @0xbf364 add sp, sp, #28
 *   @0xbf368 vpop {d8, d9, d10, d11, d12}
 *   @0xbf36c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xbf370 vstmialo lr, {s30, s31}
 *
 * ══ §39/42 _make_words  0x22eb14  size 628  157 条（0x22eb14..0x22ed88）
 * @func 0x22eb14 0x22ed88  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2 / 0xb6544 / 0xb65b0 / _make_words+0x158 / _make_words+0x138 / _make_words+0x228 / _make_words+0x234
 * 字段偏移 top8: 0x4×8 / 0x8×5 / 0x10×4 / 0xc×4 / 0x14×3 / 0x-84×2 / 0x2×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22eb14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22eb18 cmp r2, #0
 *   @0x22eb1c sub sp, sp, #164
 *   @0x22eb20 add r9, sp, #28
 *   @0x22eb24 str r1, [sp, #0x10]
 *   @0x22eb28 ldreq r3, [sp, #0x10]
 *   @0x22eb2c str r0, [sp, #0x14]
 *   @0x22eb30 lslne r0, r2, #2
 *   @0x22eb34 str r2, [sp, #0xc]
 *   @0x22eb38 lsleq r0, r3, #2
 *   @0x22eb3c bl 0xb6544 <malloc@plt>
 *   @0x22eb40 mov r1, #0
 *   @0x22eb44 mov r2, #132
 *   @0x22eb48 mov r8, r0
 *   @0x22eb4c mov r0, r9
 *   @0x22eb50 bl 0xb65b0 <memset@plt>
 *   @0x22eb54 ldr r3, [sp, #0x10]
 *   @0x22eb58 cmp r3, #0
 *   @0x22eb5c ble 0x22ec6c <_make_words+0x158>
 *   @0x22eb60 ldr r3, [sp, #0x14]
 *   @0x22eb64 mov r7, #0
 *   @0x22eb68 str r8, [sp, #0x8]
 *   @0x22eb6c add r12, sp, #152
 *   @0x22eb70 sub r10, r3, #4
 *   @0x22eb74 mov r6, r7
 *   @0x22eb78 ldr r8, [sp, #0x10]
 *   @0x22eb7c ldr r0, [r10, #0x4]!
 *   @0x22eb80 cmp r0, #0
 *   @0x22eb84 ble 0x22ec4c <_make_words+0x138>
 *   @0x22eb88 add r1, sp, #160
 *   @0x22eb8c cmp r0, #31
 *   @0x22eb90 add r3, r1, r0, lsl #2
 *   @0x22eb94 ldr r4, [r3, #-0x84]
 *   @0x22eb98 bgt 0x22eba4 <_make_words+0x90>
 *   @0x22eb9c lsrs r2, r4, r0
 *   @0x22eba0 bne 0x22ed70 <_make_words+0x25c>
 *   @0x22eba4 ldr r2, [sp, #0x8]
 *   @0x22eba8 sub r5, r0, #1
 *   @0x22ebac add r11, r7, #1
 *   @0x22ebb0 str r4, [sp, #0x4]
 *   @0x22ebb4 mov r3, r0
 *   @0x22ebb8 add r1, r9, r5, lsl #2
 *   @0x22ebbc str r4, [r2, r7, lsl #2]
 *   @0x22ebc0 mov r2, r4
 *   @0x22ebc4 b 0x22ebcc <_make_words+0xb8>
 *   @0x22ebc8 ldr r2, [r1], #-4
 *   @0x22ebcc tst r2, #1
 *   @0x22ebd0 add r2, r2, #1
 *   @0x22ebd4 bne 0x22ecb0 <_make_words+0x19c>
 *   @0x22ebd8 subs r3, r3, #1
 *   @0x22ebdc str r2, [r1, #0x4]
 *   @0x22ebe0 bne 0x22ebc8 <_make_words+0xb4>
 *   @0x22ebe4 add r0, r0, #1
 *   @0x22ebe8 cmp r0, #32
 *   @0x22ebec bgt 0x22ec30 <_make_words+0x11c>
 *   @0x22ebf0 add r2, sp, #160
 *   @0x22ebf4 add r0, r2, r0, lsl #2
 *   @0x22ebf8 ldr r2, [r0, #-0x84]
 *   @0x22ebfc cmp r4, r2, lsr #1
 *   @0x22ec00 bne 0x22ec30 <_make_words+0x11c>
 *   @0x22ec04 add r5, r9, r5, lsl #2
 *   @0x22ec08 b 0x22ec1c <_make_words+0x108>
 *   @0x22ec0c ldr r3, [r5, #0x8]
 *   @0x22ec10 cmp r2, r3, lsr #1
 *   @0x22ec14 mov r2, r3
 *   @0x22ec18 bne 0x22ec30 <_make_words+0x11c>
 *   @0x22ec1c ldr r3, [r5, #0x4]!
 *   @0x22ec20 cmp r5, r12
 *   @0x22ec24 lsl r3, r3, #1
 *   @0x22ec28 str r3, [r5, #0x4]
 *   @0x22ec2c bne 0x22ec0c <_make_words+0xf8>
 *   @0x22ec30 add r6, r6, #1
 *   @0x22ec34 cmp r6, r8
 *   @0x22ec38 beq 0x22ec68 <_make_words+0x154>
 *   @0x22ec3c ldr r0, [r10, #0x4]!
 *   @0x22ec40 mov r7, r11
 *   @0x22ec44 cmp r0, #0
 *   @0x22ec48 bgt 0x22eb88 <_make_words+0x74>
 *   @0x22ec4c ldr r3, [sp, #0xc]
 *   @0x22ec50 add r6, r6, #1
 *   @0x22ec54 cmp r3, #0
 *   @0x22ec58 addeq r11, r7, #1
 *   @0x22ec5c movne r11, r7
 *   @0x22ec60 cmp r6, r8
 *   @0x22ec64 bne 0x22ec3c <_make_words+0x128>
 *   @0x22ec68 ldr r8, [sp, #0x8]
 *   @0x22ec6c ldr r3, [sp, #0xc]
 *   @0x22ec70 cmp r3, #1
 *   @0x22ec74 movne r3, #31
 *   @0x22ec78 mvnne r1, #0
 *   @0x22ec7c bne 0x22ec8c <_make_words+0x178>
 *   @0x22ec80 b 0x22ecdc <_make_words+0x1c8>
 *   @0x22ec84 cmn r3, #1
 *   @0x22ec88 beq 0x22ecdc <_make_words+0x1c8>
 *   @0x22ec8c ldr r2, [r9, #0x4]!
 *   @0x22ec90 ands r2, r2, r1, lsr r3
 *   @0x22ec94 sub r3, r3, #1
 *   @0x22ec98 beq 0x22ec84 <_make_words+0x170>
 *   @0x22ec9c mov r0, r8
 *   @0x22eca0 bl 0xb655c <free@plt>
 *   @0x22eca4 mov r0, #0
 *   @0x22eca8 add sp, sp, #164
 *   @0x22ecac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22ecb0 cmp r3, #1
 *   @0x22ecb4 addne r1, sp, #160
 *   @0x22ecb8 addne r2, r1, r3, lsl #2
 *   @0x22ecbc ldreq r3, [sp, #0x20]
 *   @0x22ecc0 movne r3, r2
 *   @0x22ecc4 ldrne r2, [r2, #-0x88]
 *   @0x22ecc8 addeq r3, r3, #1
 *   @0x22eccc streq r3, [sp, #0x20]
 *   @0x22ecd0 lslne r2, r2, #1
 *   @0x22ecd4 strne r2, [r3, #-0x84]
 *   @0x22ecd8 b 0x22ebe4 <_make_words+0xd0>
 *   @0x22ecdc ldr r3, [sp, #0x10]
 *   @0x22ece0 cmp r3, #0
 *   @0x22ece4 ble 0x22ed3c <_make_words+0x228>
 *   @0x22ece8 ldr r5, [sp, #0x14]
 *   @0x22ecec mov r4, #0
 *   @0x22ecf0 ldr r9, [sp, #0xc]
 *   @0x22ecf4 add r7, r5, r3, lsl #2
 *   @0x22ecf8 ldr r0, [r5], #4
 *   @0x22ecfc cmp r0, #0
 *   @0x22ed00 ble 0x22ed48 <_make_words+0x234>
 *   @0x22ed04 ldr r12, [r8, r4, lsl #2]
 *   @0x22ed08 mov r2, #0
 *   @0x22ed0c add r6, r8, r4, lsl #2
 *   @0x22ed10 mov r3, r2
 *   @0x22ed14 lsr r1, r12, r3
 *   @0x22ed18 add r3, r3, #1
 *   @0x22ed1c cmp r3, r0
 *   @0x22ed20 and r1, r1, #1
 *   @0x22ed24 orr r2, r1, r2, lsl #1
 *   @0x22ed28 bne 0x22ed14 <_make_words+0x200>
 *   @0x22ed2c add r4, r4, #1
 *   @0x22ed30 str r2, [r6]
 *   @0x22ed34 cmp r5, r7
 *   @0x22ed38 bne 0x22ecf8 <_make_words+0x1e4>
 *   @0x22ed3c mov r0, r8
 *   @0x22ed40 add sp, sp, #164
 *   @0x22ed44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22ed48 cmp r9, #0
 *   @0x22ed4c beq 0x22ed64 <_make_words+0x250>
 *   @0x22ed50 cmp r0, #0
 *   @0x22ed54 addne r6, r8, r4, lsl #2
 *   @0x22ed58 movne r2, #0
 *   @0x22ed5c bne 0x22ed2c <_make_words+0x218>
 *   @0x22ed60 b 0x22ed34 <_make_words+0x220>
 *   @0x22ed64 add r6, r8, r4, lsl #2
 *   @0x22ed68 mov r2, r9
 *   @0x22ed6c b 0x22ed2c <_make_words+0x218>
 *   @0x22ed70 ldr r8, [sp, #0x8]
 *   @0x22ed74 mov r0, r8
 *   @0x22ed78 bl 0xb655c <free@plt>
 *   @0x22ed7c mov r0, #0
 *   @0x22ed80 add sp, sp, #164
 *   @0x22ed84 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §40/42 g__fmt_D2A  0x23f368  size 628  157 条（0x23f368..0x23f5dc）
 * @func 0x23f368 0x23f5dc  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: g__fmt_D2A+0x190×2 / __divsi3×2 / g__fmt_D2A+0xc0 / g__fmt_D2A+0x1f4 / g__fmt_D2A+0x26c / g__fmt_D2A+0x260 / freedtoa(char*)
 * 字段偏移 top8: 0x1×15 / 0x2×2 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23f368 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x23f36c rsb r2, r1, r2
 *   @0x23f370 ldr r8, [sp, #0x24]
 *   @0x23f374 mov r10, r1
 *   @0x23f378 add r1, r2, #6
 *   @0x23f37c cmp r1, r8
 *   @0x23f380 bhi 0x23f4f8 <g__fmt_D2A+0x190>
 *   @0x23f384 ldr r1, [sp, #0x20]
 *   @0x23f388 sub r8, r8, #1
 *   @0x23f38c add r8, r0, r8
 *   @0x23f390 cmp r1, #0
 *   @0x23f394 movne r1, #45
 *   @0x23f398 strbne r1, [r0]
 *   @0x23f39c addne r0, r0, #1
 *   @0x23f3a0 cmn r3, #5
 *   @0x23f3a4 blt 0x23f428 <g__fmt_D2A+0xc0>
 *   @0x23f3a8 add r1, r2, #20
 *   @0x23f3ac cmp r3, r1
 *   @0x23f3b0 bgt 0x23f428 <g__fmt_D2A+0xc0>
 *   @0x23f3b4 cmp r3, #0
 *   @0x23f3b8 ble 0x23f55c <g__fmt_D2A+0x1f4>
 *   @0x23f3bc sub r1, r10, #1
 *   @0x23f3c0 mov lr, #46
 *   @0x23f3c4 b 0x23f3e4 <g__fmt_D2A+0x7c>
 *   @0x23f3c8 subs r3, r3, #1
 *   @0x23f3cc bne 0x23f3e0 <g__fmt_D2A+0x78>
 *   @0x23f3d0 ldrb r2, [r1, #0x1]
 *   @0x23f3d4 cmp r2, #0
 *   @0x23f3d8 strbne lr, [r0, #0x1]
 *   @0x23f3dc addne r12, r0, #2
 *   @0x23f3e0 mov r0, r12
 *   @0x23f3e4 ldrb r2, [r1, #0x1]!
 *   @0x23f3e8 add r12, r0, #1
 *   @0x23f3ec cmp r2, #0
 *   @0x23f3f0 strb r2, [r0]
 *   @0x23f3f4 bne 0x23f3c8 <g__fmt_D2A+0x60>
 *   @0x23f3f8 add r4, r0, r3
 *   @0x23f3fc cmp r8, r4
 *   @0x23f400 blo 0x23f4f8 <g__fmt_D2A+0x190>
 *   @0x23f404 cmp r3, #0
 *   @0x23f408 ble 0x23f5d4 <g__fmt_D2A+0x26c>
 *   @0x23f40c mov r3, #48
 *   @0x23f410 strb r3, [r0], #1
 *   @0x23f414 cmp r4, r0
 *   @0x23f418 bne 0x23f410 <g__fmt_D2A+0xa8>
 *   @0x23f41c mov r3, #0
 *   @0x23f420 strb r3, [r4]
 *   @0x23f424 b 0x23f4fc <g__fmt_D2A+0x194>
 *   @0x23f428 ldrb r2, [r10]
 *   @0x23f42c strb r2, [r0]
 *   @0x23f430 ldrb r2, [r10, #0x1]
 *   @0x23f434 cmp r2, #0
 *   @0x23f438 addeq r12, r0, #1
 *   @0x23f43c bne 0x23f50c <g__fmt_D2A+0x1a4>
 *   @0x23f440 subs r6, r3, #1
 *   @0x23f444 mov r3, #101
 *   @0x23f448 rsbmi r6, r6, #0
 *   @0x23f44c strb r3, [r12]
 *   @0x23f450 addmi r9, r12, #2
 *   @0x23f454 movmi r3, #45
 *   @0x23f458 movpl r3, #43
 *   @0x23f45c addpl r9, r12, #2
 *   @0x23f460 cmp r6, #9
 *   @0x23f464 strb r3, [r12, #0x1]
 *   @0x23f468 ble 0x23f5c8 <g__fmt_D2A+0x260>
 *   @0x23f46c mov r5, #10
 *   @0x23f470 mov r4, #1
 *   @0x23f474 b 0x23f47c <g__fmt_D2A+0x114>
 *   @0x23f478 mov r5, r3
 *   @0x23f47c add r3, r5, r5, lsl #2
 *   @0x23f480 add r4, r4, #1
 *   @0x23f484 lsl r3, r3, #1
 *   @0x23f488 cmp r6, r3
 *   @0x23f48c bge 0x23f478 <g__fmt_D2A+0x110>
 *   @0x23f490 mov r0, r6
 *   @0x23f494 mov r1, r5
 *   @0x23f498 bl 0x318d10 <__divsi3>
 *   @0x23f49c cmp r9, r8
 *   @0x23f4a0 bhs 0x23f4f8 <g__fmt_D2A+0x190>
 *   @0x23f4a4 cmp r4, #1
 *   @0x23f4a8 add r3, r0, #48
 *   @0x23f4ac add r7, r9, #1
 *   @0x23f4b0 strb r3, [r9]
 *   @0x23f4b4 beq 0x23f548 <g__fmt_D2A+0x1e0>
 *   @0x23f4b8 add r9, r9, r4
 *   @0x23f4bc b 0x23f4d0 <g__fmt_D2A+0x168>
 *   @0x23f4c0 strb r3, [r4], #1
 *   @0x23f4c4 cmp r4, r9
 *   @0x23f4c8 beq 0x23f550 <g__fmt_D2A+0x1e8>
 *   @0x23f4cc mov r7, r4
 *   @0x23f4d0 mls r6, r5, r0, r6
 *   @0x23f4d4 mov r1, r5
 *   @0x23f4d8 mov r4, r7
 *   @0x23f4dc add r6, r6, r6, lsl #2
 *   @0x23f4e0 lsl r6, r6, #1
 *   @0x23f4e4 mov r0, r6
 *   @0x23f4e8 bl 0x318d10 <__divsi3>
 *   @0x23f4ec cmp r7, r8
 *   @0x23f4f0 add r3, r0, #48
 *   @0x23f4f4 bne 0x23f4c0 <g__fmt_D2A+0x158>
 *   @0x23f4f8 mov r4, #0
 *   @0x23f4fc mov r0, r10
 *   @0x23f500 bl 0x23dd68 <_Z8freedtoaPc>
 *   @0x23f504 mov r0, r4
 *   @0x23f508 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x23f50c mov r2, #46
 *   @0x23f510 strb r2, [r0, #0x1]
 *   @0x23f514 ldrb r2, [r10, #0x1]
 *   @0x23f518 add r12, r0, #2
 *   @0x23f51c add r1, r10, #2
 *   @0x23f520 cmp r2, #0
 *   @0x23f524 strb r2, [r0, #0x2]
 *   @0x23f528 beq 0x23f440 <g__fmt_D2A+0xd8>
 *   @0x23f52c add r0, r0, #3
 *   @0x23f530 ldrb r2, [r1], #1
 *   @0x23f534 mov r12, r0
 *   @0x23f538 cmp r2, #0
 *   @0x23f53c strb r2, [r0], #1
 *   @0x23f540 bne 0x23f530 <g__fmt_D2A+0x1c8>
 *   @0x23f544 b 0x23f440 <g__fmt_D2A+0xd8>
 *   @0x23f548 mov r4, r7
 *   @0x23f54c mov r7, r9
 *   @0x23f550 mov r3, #0
 *   @0x23f554 strb r3, [r7, #0x1]
 *   @0x23f558 b 0x23f4fc <g__fmt_D2A+0x194>
 *   @0x23f55c rsb r12, r3, r2
 *   @0x23f560 mov r4, r0
 *   @0x23f564 mov r2, #48
 *   @0x23f568 strb r2, [r4], #2
 *   @0x23f56c add r12, r4, r12
 *   @0x23f570 mov r1, #46
 *   @0x23f574 cmp r8, r12
 *   @0x23f578 strb r1, [r0, #0x1]
 *   @0x23f57c blo 0x23f4f8 <g__fmt_D2A+0x190>
 *   @0x23f580 cmp r3, #0
 *   @0x23f584 beq 0x23f598 <g__fmt_D2A+0x230>
 *   @0x23f588 rsb r3, r3, r4
 *   @0x23f58c strb r2, [r4], #1
 *   @0x23f590 cmp r4, r3
 *   @0x23f594 bne 0x23f58c <g__fmt_D2A+0x224>
 *   @0x23f598 ldrb r3, [r10]
 *   @0x23f59c cmp r3, #0
 *   @0x23f5a0 strb r3, [r4]
 *   @0x23f5a4 beq 0x23f4fc <g__fmt_D2A+0x194>
 *   @0x23f5a8 add r3, r4, #1
 *   @0x23f5ac mov r1, r10
 *   @0x23f5b0 ldrb r2, [r1, #0x1]!
 *   @0x23f5b4 mov r4, r3
 *   @0x23f5b8 cmp r2, #0
 *   @0x23f5bc strb r2, [r3], #1
 *   @0x23f5c0 bne 0x23f5b0 <g__fmt_D2A+0x248>
 *   @0x23f5c4 b 0x23f4fc <g__fmt_D2A+0x194>
 *   @0x23f5c8 mov r5, #1
 *   @0x23f5cc mov r4, r5
 *   @0x23f5d0 b 0x23f490 <g__fmt_D2A+0x128>
 *   @0x23f5d4 mov r4, r0
 *   @0x23f5d8 b 0x23f41c <g__fmt_D2A+0xb4>
 *
 * ══ §41/42 Call_Accessor_Set  0x24931c  size 628  157 条（0x24931c..0x249590）
 * @func 0x24931c 0x249590  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2493b4→0x544b50, 0x249410→0x757e7c, 0x2494e0→0x757e80, 0x2494f0→0x757e80
 * 调用序列: PushContextStack(YYObjectBase*)×3 / PopContextStack()×3 / CScript::GetCode()×2 / YYObjectBase::InternalGetYYVar(int)×2 / YYAllocLocalStackNew(int) / VM::Exec(CCode*, YYObjectBase*, YYObjectBase*, RValue*, YYObjectBase*, int, RValue*, int, YYObjectBase*) / YYObjectBase::Free(YYObjectBase*) / CreateArgumentsObject(RValue&, YYObjectBase*, int, RValue*, bool)
 * 字段偏移 top8: 0xc×4 / 0x1c×4 / 0x4×3 / 0x78×3 / 0x8×3 / 0x248×1 / 0x2c×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24931c ldr r12, [r2, #0xc]
 *   @0x249320 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x249324 bic r12, r12, #-16777216
 *   @0x249328 sub sp, sp, #68
 *   @0x24932c ldr r6, [pc, #0x248]
 *   @0x249330 cmp r12, #6
 *   @0x249334 mov r4, #5
 *   @0x249338 add r6, pc, r6
 *   @0x24933c mov r7, r0
 *   @0x249340 mov r8, r1
 *   @0x249344 str r4, [sp, #0x2c]
 *   @0x249348 beq 0x249354 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x38>
 *   @0x24934c add sp, sp, #68
 *   @0x249350 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x249354 ldr r4, [r2]
 *   @0x249358 ldr r3, [r4, #0x48]
 *   @0x24935c cmp r3, #2
 *   @0x249360 bne 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x249364 ldr r3, [r4, #0x4]
 *   @0x249368 cmp r3, #0
 *   @0x24936c beq 0x24950c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x1f0>
 *   @0x249370 add r0, r3, #16
 *   @0x249374 ldr r1, [r0, #0xc]
 *   @0x249378 mvn r3, #-16777216
 *   @0x24937c cmp r1, r3
 *   @0x249380 moveq r3, #5
 *   @0x249384 streq r3, [r2, #0xc]
 *   @0x249388 beq 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x24938c ldr r3, [r4, #0x4]
 *   @0x249390 cmp r3, #0
 *   @0x249394 beq 0x249524 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x208>
 *   @0x249398 add r0, r3, #16
 *   @0x24939c ldr r9, [r0]
 *   @0x2493a0 cmp r9, #0
 *   @0x2493a4 beq 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x2493a8 ldr r10, [r9, #0x64]
 *   @0x2493ac cmp r10, #0
 *   @0x2493b0 beq 0x249490 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x174>
 *   @0x2493b4 ldr r3, [pc, #0x1c4]
 *   @0x2493b8 mov r4, #0
 *   @0x2493bc mov r5, #0
 *   @0x2493c0 ldr r3, [r6, r3]
 *   @0x2493c4 ldr r0, [r3]
 *   @0x2493c8 bl 0xd41e4 <_Z20YYAllocLocalStackNewi>
 *   @0x2493cc ldr r3, [r9, #0x78]
 *   @0x2493d0 mvn r2, #-16777216
 *   @0x2493d4 strd r4, r5, [sp, #48]
 *   @0x2493d8 cmp r3, #6
 *   @0x2493dc ldreq r3, [r9, #0x6c]
 *   @0x2493e0 mov r11, r0
 *   @0x2493e4 streq r3, [r0, #0xc]
 *   @0x2493e8 mov r0, r10
 *   @0x2493ec mov r3, #0
 *   @0x2493f0 str r2, [sp, #0x3c]
 *   @0x2493f4 str r3, [sp, #0x38]
 *   @0x2493f8 str r3, [sp, #0x1c]
 *   @0x2493fc bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x249400 ldr r3, [sp, #0x1c]
 *   @0x249404 ldr r2, [r0, #0x78]
 *   @0x249408 tst r2, #1
 *   @0x24940c bne 0x2494c4 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x1a8>
 *   @0x249410 ldr r3, [pc, #0x16c]
 *   @0x249414 ldr r4, [r6, r3]
 *   @0x249418 ldrb r3, [r4]
 *   @0x24941c cmp r3, #0
 *   @0x249420 bne 0x2494f0 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x1d4>
 *   @0x249424 mov r0, r7
 *   @0x249428 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x24942c ldr r3, [sp, #0x30]
 *   @0x249430 ldr r0, [r10, #0x8]
 *   @0x249434 mov r12, #1
 *   @0x249438 mov r1, r7
 *   @0x24943c mov r2, r7
 *   @0x249440 str r3, [sp, #0x10]
 *   @0x249444 mov r3, #0
 *   @0x249448 str r12, [sp, #0x4]
 *   @0x24944c str r3, [sp, #0xc]
 *   @0x249450 add r3, sp, #32
 *   @0x249454 str r11, [sp]
 *   @0x249458 str r8, [sp, #0x8]
 *   @0x24945c bl 0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_>
 *   @0x249460 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x249464 ldrb r3, [r4]
 *   @0x249468 cmp r3, #0
 *   @0x24946c bne 0x2494e0 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x1c4>
 *   @0x249470 mov r0, r10
 *   @0x249474 bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x249478 ldr r3, [r0, #0x78]
 *   @0x24947c tst r3, #2
 *   @0x249480 bne 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x249484 mov r0, r11
 *   @0x249488 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_>
 *   @0x24948c b 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x249490 ldr r4, [r9, #0x68]
 *   @0x249494 cmp r4, #0
 *   @0x249498 beq 0x249534 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x218>
 *   @0x24949c mov r0, r7
 *   @0x2494a0 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x2494a4 mov r1, r7
 *   @0x2494a8 mov r2, r7
 *   @0x2494ac add r0, sp, #32
 *   @0x2494b0 mov r3, #1
 *   @0x2494b4 str r8, [sp]
 *   @0x2494b8 blx r4
 *   @0x2494bc bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x2494c0 b 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x2494c4 str r3, [sp]
 *   @0x2494c8 mov r1, r9
 *   @0x2494cc add r0, sp, #48
 *   @0x2494d0 mov r2, #1
 *   @0x2494d4 mov r3, r8
 *   @0x2494d8 bl 0x248b58 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b>
 *   @0x2494dc b 0x249410 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0xf4>
 *   @0x2494e0 ldr r3, [pc, #0xa0]
 *   @0x2494e4 ldr r0, [r6, r3]
 *   @0x2494e8 bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x2494ec b 0x249470 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x154>
 *   @0x2494f0 ldr r2, [pc, #0x90]
 *   @0x2494f4 mov r1, #1
 *   @0x2494f8 ldr r3, [r10, #0x8]
 *   @0x2494fc ldr r0, [r6, r2]
 *   @0x249500 ldr r2, [r3, #0x60]
 *   @0x249504 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x249508 b 0x249424 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x108>
 *   @0x24950c mov r0, r4
 *   @0x249510 mov r1, #1
 *   @0x249514 str r2, [sp, #0x1c]
 *   @0x249518 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24951c ldr r2, [sp, #0x1c]
 *   @0x249520 b 0x249374 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x58>
 *   @0x249524 mov r0, r4
 *   @0x249528 mov r1, #1
 *   @0x24952c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x249530 b 0x24939c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x80>
 *   @0x249534 ldr r1, [pc, #0x50]
 *   @0x249538 mov r0, r9
 *   @0x24953c add r1, pc, r1
 *   @0x249540 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x249544 subs r3, r0, #0
 *   @0x249548 beq 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x24954c ldr r2, [r3, #0xc]
 *   @0x249550 cmp r2, #3
 *   @0x249554 bne 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x249558 mov r0, r7
 *   @0x24955c ldr r5, [r3]
 *   @0x249560 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x249564 mov r1, r4
 *   @0x249568 mov r2, r8
 *   @0x24956c mov r0, r7
 *   @0x249570 blx r5
 *   @0x249574 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x249578 b 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x24957c andseq r8, r10, r8, lsl r9
 *   @0x249580 .word 0xffffc104
 *   @0x249584 .word 0xffffbf18
 *   @0x249588 .word 0xffffbf1c
 *   @0x24958c ldrsbeq r11, [r0], -r12
 *
 * ══ §42/42 CDS_Queue::Enqueue  0x20588c  size 548  137 条（0x20588c..0x205ab0）
 * @func 0x20588c 0x205ab0  size 548  137 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0x4×10 / 0xc×7 / 0x8×6 / 0x10×1 / 0xec×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20588c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x205890 mov r5, r1
 *   @0x205894 ldr r3, [r0, #0xc]
 *   @0x205898 mov r4, r0
 *   @0x20589c ldr r1, [r0, #0x4]
 *   @0x2058a0 cmp r1, r3
 *   @0x2058a4 bge 0x2059b4 <_ZN9CDS_Queue7EnqueueEP6RValue+0x128>
 *   @0x2058a8 ldr r7, [r4, #0x10]
 *   @0x2058ac lsl r8, r1, #4
 *   @0x2058b0 add r6, r7, r8
 *   @0x2058b4 ldr r2, [r6, #0xc]
 *   @0x2058b8 bic r3, r2, #-16777216
 *   @0x2058bc cmp r3, #1
 *   @0x2058c0 beq 0x205980 <_ZN9CDS_Queue7EnqueueEP6RValue+0xf4>
 *   @0x2058c4 cmp r3, #2
 *   @0x2058c8 bne 0x2058f0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x64>
 *   @0x2058cc sub r2, r2, #1
 *   @0x2058d0 bic r2, r2, #-16777216
 *   @0x2058d4 bic r2, r2, #3
 *   @0x2058d8 cmp r2, #0
 *   @0x2058dc beq 0x205aa0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x214>
 *   @0x2058e0 mov r2, #0
 *   @0x2058e4 mov r3, #5
 *   @0x2058e8 str r2, [r6, #0x8]
 *   @0x2058ec str r3, [r6, #0xc]
 *   @0x2058f0 ldr r3, [r5, #0xc]
 *   @0x2058f4 mov r1, #0
 *   @0x2058f8 ldr r2, [r5, #0x8]
 *   @0x2058fc str r1, [r7, r8]
 *   @0x205900 str r3, [r6, #0xc]
 *   @0x205904 ldr r3, [r5, #0xc]
 *   @0x205908 str r2, [r6, #0x8]
 *   @0x20590c bic r3, r3, #-16777216
 *   @0x205910 cmp r3, #14
 *   @0x205914 addls pc, pc, r3, lsl #2
 *   @0x205918 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x20591c b 0x205970 <_ZN9CDS_Queue7EnqueueEP6RValue+0xe4>
 *   @0x205920 b 0x205a04 <_ZN9CDS_Queue7EnqueueEP6RValue+0x178>
 *   @0x205924 b 0x205a1c <_ZN9CDS_Queue7EnqueueEP6RValue+0x190>
 *   @0x205928 b 0x205958 <_ZN9CDS_Queue7EnqueueEP6RValue+0xcc>
 *   @0x20592c b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205930 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205934 b 0x2059e0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x154>
 *   @0x205938 b 0x205958 <_ZN9CDS_Queue7EnqueueEP6RValue+0xcc>
 *   @0x20593c b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205940 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205944 b 0x205970 <_ZN9CDS_Queue7EnqueueEP6RValue+0xe4>
 *   @0x205948 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x20594c b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205950 b 0x205970 <_ZN9CDS_Queue7EnqueueEP6RValue+0xe4>
 *   @0x205954 b 0x205958 <_ZN9CDS_Queue7EnqueueEP6RValue+0xcc>
 *   @0x205958 ldr r3, [r5]
 *   @0x20595c str r3, [r7, r8]
 *   @0x205960 ldr r3, [r4, #0x4]
 *   @0x205964 add r3, r3, #1
 *   @0x205968 str r3, [r4, #0x4]
 *   @0x20596c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x205970 ldm r5, {r2, r3}
 *   @0x205974 str r2, [r7, r8]
 *   @0x205978 str r3, [r6, #0x4]
 *   @0x20597c b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205980 ldr r9, [r7, r1, lsl #4]
 *   @0x205984 cmp r9, #0
 *   @0x205988 beq 0x2059a8 <_ZN9CDS_Queue7EnqueueEP6RValue+0x11c>
 *   @0x20598c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x205990 ldr r10, [r9, #0x4]
 *   @0x205994 sub r10, r10, #1
 *   @0x205998 str r10, [r9, #0x4]
 *   @0x20599c cmp r10, #0
 *   @0x2059a0 beq 0x205a48 <_ZN9CDS_Queue7EnqueueEP6RValue+0x1bc>
 *   @0x2059a4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2059a8 mov r3, #0
 *   @0x2059ac str r3, [r7, r8]
 *   @0x2059b0 b 0x2058f0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x64>
 *   @0x2059b4 add r1, r1, #16
 *   @0x2059b8 ldr r2, [pc, #0xec]
 *   @0x2059bc mov r3, #936
 *   @0x2059c0 add r0, r0, #16
 *   @0x2059c4 lsl r1, r1, #4
 *   @0x2059c8 add r2, pc, r2
 *   @0x2059cc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x2059d0 ldr r1, [r4, #0x4]
 *   @0x2059d4 add r3, r1, #16
 *   @0x2059d8 str r3, [r4, #0xc]
 *   @0x2059dc b 0x2058a8 <_ZN9CDS_Queue7EnqueueEP6RValue+0x1c>
 *   @0x2059e0 ldr r3, [r5]
 *   @0x2059e4 str r3, [r7, r8]
 *   @0x2059e8 ldr r3, [r5]
 *   @0x2059ec cmp r3, #0
 *   @0x2059f0 beq 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x2059f4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x2059f8 ldr r1, [r5]
 *   @0x2059fc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x205a00 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205a04 ldr r3, [r5]
 *   @0x205a08 cmp r3, #0
 *   @0x205a0c ldrne r2, [r3, #0x4]
 *   @0x205a10 addne r2, r2, #1
 *   @0x205a14 strne r2, [r3, #0x4]
 *   @0x205a18 b 0x20595c <_ZN9CDS_Queue7EnqueueEP6RValue+0xd0>
 *   @0x205a1c ldr r3, [r5]
 *   @0x205a20 cmp r3, #0
 *   @0x205a24 str r3, [r7, r8]
 *   @0x205a28 beq 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205a2c ldr r1, [r3, #0x8]
 *   @0x205a30 ldr r2, [r3]
 *   @0x205a34 cmp r1, #0
 *   @0x205a38 streq r6, [r3, #0x8]
 *   @0x205a3c add r2, r2, #1
 *   @0x205a40 str r2, [r3]
 *   @0x205a44 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4>
 *   @0x205a48 ldr r0, [r9]
 *   @0x205a4c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x205a50 str r10, [r9]
 *   @0x205a54 str r10, [r9, #0x8]
 *   @0x205a58 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x205a5c ldr r10, [r9, #0x4]
 *   @0x205a60 sub r10, r10, #1
 *   @0x205a64 str r10, [r9, #0x4]
 *   @0x205a68 cmp r10, #0
 *   @0x205a6c bne 0x205a90 <_ZN9CDS_Queue7EnqueueEP6RValue+0x204>
 *   @0x205a70 ldr r0, [r9]
 *   @0x205a74 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x205a78 mov r0, r9
 *   @0x205a7c str r10, [r9]
 *   @0x205a80 str r10, [r9, #0x8]
 *   @0x205a84 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x205a88 mov r0, r9
 *   @0x205a8c bl 0x27d1d0 <_ZdlPv>
 *   @0x205a90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x205a94 mov r0, r9
 *   @0x205a98 bl 0x27d1d0 <_ZdlPv>
 *   @0x205a9c b 0x2059a4 <_ZN9CDS_Queue7EnqueueEP6RValue+0x118>
 *   @0x205aa0 mov r0, r6
 *   @0x205aa4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x205aa8 b 0x2058e0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x54>
 *   @0x205aac andseq sp, r4, r4, lsr #28
 */
