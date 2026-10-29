/* cally 逆向卡：All_38 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 46 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/46 JS_RegExp_prototype_test(RValue&, CInstance*, CInstance*, int, RValue*)  0x2576bc  size 684  171 条（0x2576bc..0x257968）
 * @func 0x2576bc 0x257968  size 684  171 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2578b0→0x3eb70c, 0x2578d0→0x3eb70c, 0x2578dc→0x3eb70c, 0x2578e8→0x3eb70c, 0x2578f4→0x3eb70c, 0x257918→0x3eb70c
 * 调用序列: JSThrowTypeError(char const*)×2 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×2 / 0xb6574 / F_JS_ToString(RValue&, RValue*) / YYGetString(RValue const*, int) / 0xb6538 / YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xc×4 / 0x40×3 / 0x1c×3 / 0x20×3 / 0x4×3 / 0x38×2 / 0x10×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2576bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2576c0 mov r5, r1
 *   @0x2576c4 ldr r1, [pc, #0x268]
 *   @0x2576c8 sub sp, sp, #212
 *   @0x2576cc mov r6, r0
 *   @0x2576d0 ldr r0, [r5, #0x40]
 *   @0x2576d4 add r1, pc, r1
 *   @0x2576d8 ldr r11, [pc, #0x258]
 *   @0x2576dc bl 0xb6574 <strcmp@plt>
 *   @0x2576e0 add r11, pc, r11
 *   @0x2576e4 subs r4, r0, #0
 *   @0x2576e8 beq 0x257700 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x2576ec ldr r0, [pc, #0x248]
 *   @0x2576f0 add r0, pc, r0
 *   @0x2576f4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2576f8 add sp, sp, #212
 *   @0x2576fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x257700 add r7, sp, #40
 *   @0x257704 ldr r1, [sp, #0xf8]
 *   @0x257708 mov r2, #0
 *   @0x25770c mov r3, #0
 *   @0x257710 mov r0, r7
 *   @0x257714 strd r2, r3, [sp, #40]
 *   @0x257718 str r4, [sp, #0x30]
 *   @0x25771c mvn r3, #-16777216
 *   @0x257720 str r3, [sp, #0x34]
 *   @0x257724 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x257728 cmp r0, #2
 *   @0x25772c beq 0x2576f8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x257730 cmp r0, #1
 *   @0x257734 beq 0x257924 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x257738 mov r1, r4
 *   @0x25773c mov r0, r7
 *   @0x257740 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x257744 add r7, sp, #56
 *   @0x257748 add r9, sp, #72
 *   @0x25774c mov r10, r0
 *   @0x257750 bl 0xb6538 <strlen@plt>
 *   @0x257754 ldr r2, [pc, #0x1e4]
 *   @0x257758 mov r1, r7
 *   @0x25775c str r4, [sp, #0x38]
 *   @0x257760 add r2, pc, r2
 *   @0x257764 str r4, [sp, #0x3c]
 *   @0x257768 str r4, [sp, #0x40]
 *   @0x25776c str r4, [sp, #0x44]
 *   @0x257770 str r4, [sp, #0x48]
 *   @0x257774 str r4, [sp, #0x4c]
 *   @0x257778 str r4, [sp, #0x50]
 *   @0x25777c str r4, [sp, #0x54]
 *   @0x257780 mov r8, r0
 *   @0x257784 mov r0, r5
 *   @0x257788 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x25778c ldr r2, [pc, #0x1b0]
 *   @0x257790 mov r1, r9
 *   @0x257794 mov r0, r5
 *   @0x257798 add r2, pc, r2
 *   @0x25779c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2577a0 mov r0, r7
 *   @0x2577a4 mov r1, r4
 *   @0x2577a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2577ac mov r1, r4
 *   @0x2577b0 mov r7, r0
 *   @0x2577b4 mov r0, r9
 *   @0x2577b8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x2577bc ldr r3, [pc, #0x184]
 *   @0x2577c0 add r3, pc, r3
 *   @0x2577c4 str r3, [sp, #0x10]
 *   @0x2577c8 ldr r3, [pc, #0x17c]
 *   @0x2577cc add r3, pc, r3
 *   @0x2577d0 str r3, [sp, #0x14]
 *   @0x2577d4 ldr r3, [pc, #0x174]
 *   @0x2577d8 add r3, pc, r3
 *   @0x2577dc str r3, [sp, #0x18]
 *   @0x2577e0 ldr r3, [pc, #0x16c]
 *   @0x2577e4 add r3, pc, r3
 *   @0x2577e8 str r3, [sp, #0x1c]
 *   @0x2577ec ldr r3, [pc, #0x164]
 *   @0x2577f0 add r3, pc, r3
 *   @0x2577f4 str r3, [sp, #0x20]
 *   @0x2577f8 ldr r3, [pc, #0x15c]
 *   @0x2577fc add r3, pc, r3
 *   @0x257800 str r3, [sp, #0x24]
 *   @0x257804 cmp r0, #0
 *   @0x257808 moveq r7, #0
 *   @0x25780c lsr r9, r7, #31
 *   @0x257810 cmp r7, r8
 *   @0x257814 movle r4, r9
 *   @0x257818 orrgt r4, r9, #1
 *   @0x25781c mov r2, r10
 *   @0x257820 cmp r4, #0
 *   @0x257824 mov r3, r8
 *   @0x257828 add r1, sp, #88
 *   @0x25782c mov r12, #30
 *   @0x257830 bne 0x257900 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x244>
 *   @0x257834 ldr lr, [r5, #0x20]
 *   @0x257838 ldr r0, [r5, #0x1c]
 *   @0x25783c str r1, [sp, #0x8]
 *   @0x257840 str r7, [sp]
 *   @0x257844 mov r1, lr
 *   @0x257848 str r4, [sp, #0x4]
 *   @0x25784c str r12, [sp, #0xc]
 *   @0x257850 bl 0x279390 <pcre_exec>
 *   @0x257854 cmp r0, #0
 *   @0x257858 blt 0x25787c <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x25785c mov r2, #13
 *   @0x257860 str r4, [r6]
 *   @0x257864 mov r3, #0
 *   @0x257868 str r2, [r6, #0xc]
 *   @0x25786c movt r3, #0x3ff0
 *   @0x257870 str r3, [r6, #0x4]
 *   @0x257874 add sp, sp, #212
 *   @0x257878 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25787c add r0, r0, #6
 *   @0x257880 cmp r0, #5
 *   @0x257884 addls pc, pc, r0, lsl #2
 *   @0x257888 b 0x257918 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x25788c b 0x2578f4 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x257890 b 0x2578e8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x257894 b 0x2578dc <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x257898 b 0x2578d0 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x25789c b 0x2578b0 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x2578a0 b 0x2578a4 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x2578a4 add r7, r7, #1
 *   @0x2578a8 lsr r9, r7, #31
 *   @0x2578ac b 0x257810 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x2578b0 ldr r3, [pc, #0xa8]
 *   @0x2578b4 ldr r1, [sp, #0x24]
 *   @0x2578b8 ldr r3, [r11, r3]
 *   @0x2578bc ldr r0, [r3]
 *   @0x2578c0 ldr r3, [r0]
 *   @0x2578c4 ldr r3, [r3, #0xc]
 *   @0x2578c8 blx r3
 *   @0x2578cc b 0x257810 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x2578d0 ldr r3, [pc, #0x88]
 *   @0x2578d4 ldr r1, [sp, #0x20]
 *   @0x2578d8 b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x2578dc ldr r3, [pc, #0x7c]
 *   @0x2578e0 ldr r1, [sp, #0x1c]
 *   @0x2578e4 b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x2578e8 ldr r3, [pc, #0x70]
 *   @0x2578ec ldr r1, [sp, #0x18]
 *   @0x2578f0 b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x2578f4 ldr r3, [pc, #0x64]
 *   @0x2578f8 ldr r1, [sp, #0x14]
 *   @0x2578fc b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x257900 mov r3, #0
 *   @0x257904 mov r2, #13
 *   @0x257908 str r3, [r6]
 *   @0x25790c str r2, [r6, #0xc]
 *   @0x257910 str r3, [r6, #0x4]
 *   @0x257914 b 0x2576f8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x257918 ldr r3, [pc, #0x40]
 *   @0x25791c ldr r1, [sp, #0x10]
 *   @0x257920 b 0x2578b8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x257924 ldr r0, [pc, #0x38]
 *   @0x257928 add r0, pc, r0
 *   @0x25792c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x257930 b 0x2576f8 <_Z24JS_RegExp_prototype_testR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x257934 andeq lr, pc, r8, asr r5
 *   @0x257938 andseq r10, r9, r0, ror r5
 *   @0x25793c andeq lr, pc, r8, asr r8
 *   @0x257940 andeq lr, pc, r0, asr #18
 *   @0x257944 andeq sp, sp, r0, asr #14
 *   @0x257948 andeq lr, pc, r8, ror r9
 *   @0x25794c andeq lr, pc, r0, asr r9
 *   @0x257950 andeq lr, pc, r4, lsr #18
 *   @0x257954 strdeq lr, pc, [pc], -r12
 *   @0x257958 ldrdeq lr, pc, [pc], -r4
 *   @0x25795c strheq lr, [pc], -r0
 *   @0x257960 .word 0xffffbac4
 *   @0x257964 .word 0x000ff1dc
 *
 * ══ §2/46 b2MotorJoint::InitVelocityConstraints(b2SolverData const&)  0x2ce3c4  size 684  171 条（0x2ce3c4..0x2ce670）
 * @func 0x2ce3c4 0x2ce670  size 684  171 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2
 * 字段偏移 top8: 0x8×2 / 0x30×1 / 0x34×1 / 0x18×1 / 0x1c×1 / 0x68×1 / 0x6c×1 / 0x14×1
 * VFP 指令 131 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce3c4 ldr r2, [r0, #0x30]
 *   @0x2ce3c8 ldr r3, [r0, #0x34]
 *   @0x2ce3cc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2ce3d0 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2ce3d4 mov r7, r1
 *   @0x2ce3d8 vldr s16, [r2, #144]
 *   @0x2ce3dc add r1, r2, #44
 *   @0x2ce3e0 mov r4, r0
 *   @0x2ce3e4 ldr r6, [r2, #0x8]
 *   @0x2ce3e8 add lr, r0, #136
 *   @0x2ce3ec ldr r12, [r3, #0x8]
 *   @0x2ce3f0 add r10, r0, #128
 *   @0x2ce3f4 ldm r1, {r0, r1}
 *   @0x2ce3f8 add r9, r3, #44
 *   @0x2ce3fc ldr r8, [r7, #0x18]
 *   @0x2ce400 vldr s23, [r2, #136]
 *   @0x2ce404 vldr s22, [r3, #136]
 *   @0x2ce408 ldr r5, [r7, #0x1c]
 *   @0x2ce40c str r6, [r4, #0x68]
 *   @0x2ce410 add r6, r6, r6, lsl #1
 *   @0x2ce414 str r12, [r4, #0x6c]
 *   @0x2ce418 add r12, r12, r12, lsl #1
 *   @0x2ce41c stm r10, {r0, r1}
 *   @0x2ce420 lsl r6, r6, #2
 *   @0x2ce424 ldm r9, {r0, r1}
 *   @0x2ce428 vldr s17, [r3, #144]
 *   @0x2ce42c add r2, r8, r6
 *   @0x2ce430 lsl r12, r12, #2
 *   @0x2ce434 vldr s20, [r2, #8]
 *   @0x2ce438 add r3, r8, r12
 *   @0x2ce43c stm lr, {r0, r1}
 *   @0x2ce440 vstr s23, [r4, #156]
 *   @0x2ce444 vmov r0, s20
 *   @0x2ce448 vstr s22, [r4, #160]
 *   @0x2ce44c vstr s16, [r4, #164]
 *   @0x2ce450 vstr s17, [r4, #168]
 *   @0x2ce454 vldr s21, [r3, #8]
 *   @0x2ce458 vldr s27, [r3]
 *   @0x2ce45c vldr s26, [r3, #4]
 *   @0x2ce460 vldr s25, [r2]
 *   @0x2ce464 vldr s24, [r2, #4]
 *   @0x2ce468 add r6, r5, r6
 *   @0x2ce46c add r5, r5, r12
 *   @0x2ce470 bl 0xb6580 <sinf@plt>
 *   @0x2ce474 vmov s18, r0
 *   @0x2ce478 vmov r0, s20
 *   @0x2ce47c bl 0xb658c <cosf@plt>
 *   @0x2ce480 vsub.f32 s20, s21, s20
 *   @0x2ce484 vmov s19, r0
 *   @0x2ce488 vmov r0, s21
 *   @0x2ce48c bl 0xb6580 <sinf@plt>
 *   @0x2ce490 vmov s28, r0
 *   @0x2ce494 vmov r0, s21
 *   @0x2ce498 bl 0xb658c <cosf@plt>
 *   @0x2ce49c vldr s13, [r4, #132]
 *   @0x2ce4a0 vneg.f32 s13, s13
 *   @0x2ce4a4 vldr s14, [r4, #128]
 *   @0x2ce4a8 vldr s1, [r6]
 *   @0x2ce4ac vldr s2, [r6, #4]
 *   @0x2ce4b0 vldr s3, [r6, #8]
 *   @0x2ce4b4 vldr s4, [r5]
 *   @0x2ce4b8 vldr s5, [r5, #4]
 *   @0x2ce4bc vldr s6, [r5, #8]
 *   @0x2ce4c0 vmul.f32 s15, s13, s18
 *   @0x2ce4c4 vmul.f32 s13, s13, s19
 *   @0x2ce4c8 vneg.f32 s14, s14
 *   @0x2ce4cc vmov s10, r0
 *   @0x2ce4d0 vnmls.f32 s15, s14, s19
 *   @0x2ce4d4 vmla.f32 s13, s14, s18
 *   @0x2ce4d8 vstr s15, [r4, #112]
 *   @0x2ce4dc vstr s13, [r4, #116]
 *   @0x2ce4e0 vldr s14, [r4, #140]
 *   @0x2ce4e4 vneg.f32 s14, s14
 *   @0x2ce4e8 vldr s12, [r4, #136]
 *   @0x2ce4ec ldrb r3, [r7, #0x14]
 *   @0x2ce4f0 vmul.f32 s11, s14, s28
 *   @0x2ce4f4 vneg.f32 s12, s12
 *   @0x2ce4f8 vmul.f32 s14, s14, s10
 *   @0x2ce4fc vnmls.f32 s11, s12, s10
 *   @0x2ce500 vmla.f32 s14, s12, s28
 *   @0x2ce504 vstr s11, [r4, #120]
 *   @0x2ce508 vadd.f32 s9, s23, s22
 *   @0x2ce50c vstr s14, [r4, #124]
 *   @0x2ce510 vmul.f32 s8, s16, s15
 *   @0x2ce514 vmul.f32 s7, s17, s11
 *   @0x2ce518 vmul.f32 s0, s16, s13
 *   @0x2ce51c vmov.f32 s28, s9
 *   @0x2ce520 vmla.f32 s28, s8, s15
 *   @0x2ce524 vmul.f32 s10, s7, s14
 *   @0x2ce528 vnmul.f32 s12, s16, s15
 *   @0x2ce52c vmla.f32 s9, s0, s13
 *   @0x2ce530 vnmls.f32 s10, s12, s13
 *   @0x2ce534 vmul.f32 s12, s17, s14
 *   @0x2ce538 vmov.f32 s8, s28
 *   @0x2ce53c vmla.f32 s9, s12, s14
 *   @0x2ce540 vmla.f32 s8, s7, s11
 *   @0x2ce544 vmul.f32 s12, s10, s10
 *   @0x2ce548 vnmls.f32 s12, s9, s8
 *   @0x2ce54c vcmp.f32 s12, #0
 *   @0x2ce550 vmrs APSR_nzcv, fpscr
 *   @0x2ce554 vmovne.f32 s7, #1.000000e+00
 *   @0x2ce558 vdivne.f32 s12, s7, s12
 *   @0x2ce55c vadd.f32 s7, s16, s17
 *   @0x2ce560 vnmul.f32 s10, s12, s10
 *   @0x2ce564 vmul.f32 s8, s8, s12
 *   @0x2ce568 vstr s10, [r4, #176]
 *   @0x2ce56c vstr s10, [r4, #180]
 *   @0x2ce570 vmul.f32 s12, s9, s12
 *   @0x2ce574 vldr s9, [r4, #68]
 *   @0x2ce578 vstr s8, [r4, #172]
 *   @0x2ce57c vldr s8, [r4, #76]
 *   @0x2ce580 vcmpe.f32 s7, #0
 *   @0x2ce584 vstr s12, [r4, #184]
 *   @0x2ce588 vmrs APSR_nzcv, fpscr
 *   @0x2ce58c vmovgt.f32 s12, #1.000000e+00
 *   @0x2ce590 vdivgt.f32 s7, s12, s7
 *   @0x2ce594 vldr s12, [r4, #72]
 *   @0x2ce598 cmp r3, #0
 *   @0x2ce59c vmul.f32 s10, s12, s18
 *   @0x2ce5a0 vstr s7, [r4, #188]
 *   @0x2ce5a4 vmul.f32 s12, s12, s19
 *   @0x2ce5a8 vadd.f32 s27, s11, s27
 *   @0x2ce5ac vadd.f32 s26, s14, s26
 *   @0x2ce5b0 vnmls.f32 s10, s9, s19
 *   @0x2ce5b4 vmla.f32 s12, s9, s18
 *   @0x2ce5b8 vsub.f32 s25, s27, s25
 *   @0x2ce5bc vsub.f32 s24, s26, s24
 *   @0x2ce5c0 vsub.f32 s25, s25, s15
 *   @0x2ce5c4 vsub.f32 s24, s24, s13
 *   @0x2ce5c8 vsub.f32 s10, s25, s10
 *   @0x2ce5cc vsub.f32 s12, s24, s12
 *   @0x2ce5d0 vstr s10, [r4, #144]
 *   @0x2ce5d4 vsub.f32 s20, s20, s8
 *   @0x2ce5d8 vstr s12, [r4, #148]
 *   @0x2ce5dc vstr s20, [r4, #152]
 *   @0x2ce5e0 bne 0x2ce614 <_ZN12b2MotorJoint23InitVelocityConstraintsERK12b2SolverData+0x250>
 *   @0x2ce5e4 mov r3, #0
 *   @0x2ce5e8 str r3, [r4, #0x50]
 *   @0x2ce5ec str r3, [r4, #0x54]
 *   @0x2ce5f0 str r3, [r4, #0x58]
 *   @0x2ce5f4 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2ce5f8 vstr s1, [r6]
 *   @0x2ce5fc vstr s2, [r6, #4]
 *   @0x2ce600 vstr s3, [r6, #8]
 *   @0x2ce604 vstr s4, [r5]
 *   @0x2ce608 vstr s5, [r5, #4]
 *   @0x2ce60c vstr s6, [r5, #8]
 *   @0x2ce610 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2ce614 vldr s9, [r7, #8]
 *   @0x2ce618 vldr s10, [r4, #80]
 *   @0x2ce61c vmul.f32 s10, s9, s10
 *   @0x2ce620 vldr s12, [r4, #84]
 *   @0x2ce624 vldr s8, [r4, #88]
 *   @0x2ce628 vmul.f32 s12, s9, s12
 *   @0x2ce62c vstr s10, [r4, #80]
 *   @0x2ce630 vmul.f32 s13, s13, s10
 *   @0x2ce634 vstr s12, [r4, #84]
 *   @0x2ce638 vmul.f32 s14, s14, s10
 *   @0x2ce63c vnmls.f32 s13, s15, s12
 *   @0x2ce640 vnmls.f32 s14, s11, s12
 *   @0x2ce644 vmul.f32 s15, s9, s8
 *   @0x2ce648 vadd.f32 s13, s15, s13
 *   @0x2ce64c vstr s15, [r4, #88]
 *   @0x2ce650 vadd.f32 s14, s15, s14
 *   @0x2ce654 vmls.f32 s1, s23, s10
 *   @0x2ce658 vmla.f32 s4, s22, s10
 *   @0x2ce65c vmls.f32 s2, s23, s12
 *   @0x2ce660 vmla.f32 s5, s22, s12
 *   @0x2ce664 vmls.f32 s3, s16, s13
 *   @0x2ce668 vmla.f32 s6, s17, s14
 *   @0x2ce66c b 0x2ce5f4 <_ZN12b2MotorJoint23InitVelocityConstraintsERK12b2SolverData+0x230>
 *
 * ══ §3/46 F_StringHashToNewline(RValue&, CInstance*, CInstance*, int, RValue*)  0x1100e8  size 680  170 条（0x1100e8..0x110390）
 * @func 0x1100e8 0x110390  size 680  170 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×3 / utf8_add_char×2 / 0xb6538×2 / YYAlloc(int)×2 / 0xb65bc×2 / 0xb65a4×2 / GetTextFromArg(RValue const*, int, char**) / F_StringHashToNewline(RValue&, CInstance*, CInstance*, int, RValue*)+0x134
 * 字段偏移 top8: 0x24×10 / 0x1c×9 / 0x20×7 / 0x8×4 / 0x10×4 / 0xc×3 / 0x4×3 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1100e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1100ec sub sp, sp, #44
 *   @0x1100f0 mov r4, #0
 *   @0x1100f4 ldr r3, [sp, #0x50]
 *   @0x1100f8 str r0, [sp]
 *   @0x1100fc str r4, [sp, #0x8]
 *   @0x110100 ldr r2, [r3, #0xc]
 *   @0x110104 mov r0, r3
 *   @0x110108 bic r2, r2, #-16777216
 *   @0x11010c cmp r2, #1
 *   @0x110110 beq 0x110378 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x290>
 *   @0x110114 mov r1, #1024
 *   @0x110118 add r2, sp, #8
 *   @0x11011c mov r3, #1
 *   @0x110120 str r3, [sp, #0x4]
 *   @0x110124 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc>
 *   @0x110128 ldr r3, [sp, #0x8]
 *   @0x11012c mov r7, #0
 *   @0x110130 str r3, [sp, #0xc]
 *   @0x110134 str r7, [sp, #0x1c]
 *   @0x110138 str r7, [sp, #0x20]
 *   @0x11013c str r7, [sp, #0x24]
 *   @0x110140 strb r7, [sp, #0x14]
 *   @0x110144 strb r7, [sp, #0x15]
 *   @0x110148 strb r7, [sp, #0x16]
 *   @0x11014c strb r7, [sp, #0x17]
 *   @0x110150 strb r7, [sp, #0x18]
 *   @0x110154 ldrb r3, [r3]
 *   @0x110158 cmp r3, r7
 *   @0x11015c beq 0x110364 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x27c>
 *   @0x110160 add r9, sp, #12
 *   @0x110164 add r4, sp, #20
 *   @0x110168 add r8, sp, #16
 *   @0x11016c mov r10, r7
 *   @0x110170 b 0x110248 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x110174 subs r3, r0, #92
 *   @0x110178 rsbs r7, r3, #0
 *   @0x11017c adcs r7, r7, r3
 *   @0x110180 mov r1, r0
 *   @0x110184 mov r0, r8
 *   @0x110188 str r4, [sp, #0x10]
 *   @0x11018c bl 0x10fe28 <utf8_add_char>
 *   @0x110190 ldr r3, [sp, #0x10]
 *   @0x110194 mov r0, r4
 *   @0x110198 strb r10, [r3]
 *   @0x11019c bl 0xb6538 <strlen@plt>
 *   @0x1101a0 ldr r2, [sp, #0x24]
 *   @0x1101a4 ldr r3, [sp, #0x20]
 *   @0x1101a8 add r1, r0, #1
 *   @0x1101ac mov r5, r0
 *   @0x1101b0 mvn r0, r2
 *   @0x1101b4 add r0, r3, r0
 *   @0x1101b8 cmp r1, r0
 *   @0x1101bc ble 0x11021c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1101c0 cmp r3, #0
 *   @0x1101c4 add r2, r1, r2
 *   @0x1101c8 ldr r6, [sp, #0x1c]
 *   @0x1101cc moveq r3, r1
 *   @0x1101d0 add r3, r3, r3, lsl #1
 *   @0x1101d4 add r3, r3, r3, lsr #31
 *   @0x1101d8 asr r11, r3, #1
 *   @0x1101dc cmp r11, r2
 *   @0x1101e0 addlt r2, r2, r2, lsl #1
 *   @0x1101e4 addlt r2, r2, r2, lsr #31
 *   @0x1101e8 asrlt r11, r2, #1
 *   @0x1101ec mov r0, r11
 *   @0x1101f0 bl 0xcef4c <_Z7YYAlloci>
 *   @0x1101f4 ldr r2, [sp, #0x20]
 *   @0x1101f8 mov r1, r6
 *   @0x1101fc str r0, [sp, #0x1c]
 *   @0x110200 bl 0xb65bc <memcpy@plt>
 *   @0x110204 cmp r6, #0
 *   @0x110208 str r11, [sp, #0x20]
 *   @0x11020c beq 0x110218 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x110210 mov r0, r6
 *   @0x110214 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x110218 ldr r2, [sp, #0x24]
 *   @0x11021c ldr r0, [sp, #0x1c]
 *   @0x110220 mov r1, r4
 *   @0x110224 add r0, r0, r2
 *   @0x110228 bl 0xb65a4 <strcpy@plt>
 *   @0x11022c ldr r3, [sp, #0xc]
 *   @0x110230 ldr r2, [sp, #0x24]
 *   @0x110234 add r5, r5, r2
 *   @0x110238 str r5, [sp, #0x24]
 *   @0x11023c ldrb r3, [r3]
 *   @0x110240 cmp r3, #0
 *   @0x110244 beq 0x110324 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x110248 mov r0, r9
 *   @0x11024c bl 0x10fb38 <utf8_extract_char>
 *   @0x110250 cmp r0, #35
 *   @0x110254 bne 0x110174 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x110258 cmp r7, #0
 *   @0x11025c movne r7, #0
 *   @0x110260 bne 0x110180 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x110264 mov r1, #13
 *   @0x110268 mov r0, r8
 *   @0x11026c str r4, [sp, #0x10]
 *   @0x110270 bl 0x10fe28 <utf8_add_char>
 *   @0x110274 ldr r3, [sp, #0x10]
 *   @0x110278 mov r0, r4
 *   @0x11027c strb r7, [r3]
 *   @0x110280 bl 0xb6538 <strlen@plt>
 *   @0x110284 ldr r2, [sp, #0x24]
 *   @0x110288 ldr r3, [sp, #0x20]
 *   @0x11028c add r1, r0, #1
 *   @0x110290 mov r5, r0
 *   @0x110294 mvn r0, r2
 *   @0x110298 add r0, r3, r0
 *   @0x11029c cmp r1, r0
 *   @0x1102a0 ble 0x110300 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x218>
 *   @0x1102a4 cmp r3, #0
 *   @0x1102a8 add r2, r1, r2
 *   @0x1102ac ldr r6, [sp, #0x1c]
 *   @0x1102b0 moveq r3, r1
 *   @0x1102b4 add r3, r3, r3, lsl #1
 *   @0x1102b8 add r3, r3, r3, lsr #31
 *   @0x1102bc asr r11, r3, #1
 *   @0x1102c0 cmp r11, r2
 *   @0x1102c4 addlt r2, r2, r2, lsl #1
 *   @0x1102c8 addlt r2, r2, r2, lsr #31
 *   @0x1102cc asrlt r11, r2, #1
 *   @0x1102d0 mov r0, r11
 *   @0x1102d4 bl 0xcef4c <_Z7YYAlloci>
 *   @0x1102d8 ldr r2, [sp, #0x20]
 *   @0x1102dc mov r1, r6
 *   @0x1102e0 str r0, [sp, #0x1c]
 *   @0x1102e4 bl 0xb65bc <memcpy@plt>
 *   @0x1102e8 cmp r6, #0
 *   @0x1102ec str r11, [sp, #0x20]
 *   @0x1102f0 beq 0x1102fc <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x1102f4 mov r0, r6
 *   @0x1102f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1102fc ldr r2, [sp, #0x24]
 *   @0x110300 ldr r0, [sp, #0x1c]
 *   @0x110304 mov r1, r4
 *   @0x110308 add r0, r0, r2
 *   @0x11030c bl 0xb65a4 <strcpy@plt>
 *   @0x110310 ldr r3, [sp, #0x24]
 *   @0x110314 mov r0, #10
 *   @0x110318 add r5, r3, r5
 *   @0x11031c str r5, [sp, #0x24]
 *   @0x110320 b 0x110180 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x110324 cmp r5, #0
 *   @0x110328 beq 0x110364 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x27c>
 *   @0x11032c ldr r1, [sp, #0x1c]
 *   @0x110330 ldr r0, [sp]
 *   @0x110334 mov r3, #0
 *   @0x110338 str r3, [sp, #0x24]
 *   @0x11033c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x110340 ldr r3, [sp, #0x4]
 *   @0x110344 cmp r3, #0
 *   @0x110348 bne 0x11036c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x11034c ldr r0, [sp, #0x1c]
 *   @0x110350 cmp r0, #0
 *   @0x110354 beq 0x11035c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x110358 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x11035c add sp, sp, #44
 *   @0x110360 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x110364 add r1, sp, #36
 *   @0x110368 b 0x110330 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x11036c ldr r0, [sp, #0x8]
 *   @0x110370 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x110374 b 0x11034c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x110378 mov r1, r4
 *   @0x11037c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x110380 str r4, [sp, #0x4]
 *   @0x110384 mov r3, r0
 *   @0x110388 str r0, [sp, #0x8]
 *   @0x11038c b 0x11012c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x44>
 *
 * ══ §4/46 CSprite::ComputeBoundingBox()  0x1e3320  size 680  170 条（0x1e3320..0x1e35c8）
 * @func 0x1e3320 0x1e35c8  size 680  170 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6994×4 / 0xb6700×4 / CSprite::ComputeBoundingBox()+0x20c / CBitmap32::BoundingBox() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×5 / 0xc×4 / 0x20×3 / 0x1c×3 / 0x10×3 / 0x14×3 / 0x4×2 / 0x18×2
 * VFP 指令 63 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e3320 ldr r2, [r0, #0x28]
 *   @0x1e3324 ldr r3, [r0, #0x24]
 *   @0x1e3328 push {r4, r5, r6, r7, r8, lr}
 *   @0x1e332c vpush {d8, d9, d10}
 *   @0x1e3330 mov r4, r0
 *   @0x1e3334 mul r1, r2, r2
 *   @0x1e3338 ldr r0, [r0, #0x20]
 *   @0x1e333c mul r12, r3, r3
 *   @0x1e3340 rsb r2, r2, r0
 *   @0x1e3344 mul r2, r2, r2
 *   @0x1e3348 vmov s19, r1
 *   @0x1e334c ldr r1, [r4, #0x1c]
 *   @0x1e3350 vmov s18, r12
 *   @0x1e3354 vcvt.f32.s32 s19, s19
 *   @0x1e3358 rsb r3, r3, r1
 *   @0x1e335c mul r3, r3, r3
 *   @0x1e3360 vcvt.f32.s32 s18, s18
 *   @0x1e3364 vmov s13, r3
 *   @0x1e3368 vadd.f32 s14, s18, s19
 *   @0x1e336c vsqrt.f32 s15, s14
 *   @0x1e3370 vcmp.f32 s15, s15
 *   @0x1e3374 vcvt.f32.s32 s17, s13
 *   @0x1e3378 vmrs APSR_nzcv, fpscr
 *   @0x1e337c vmov s13, r2
 *   @0x1e3380 vcvt.f32.s32 s16, s13
 *   @0x1e3384 bne 0x1e35a8 <_ZN7CSprite18ComputeBoundingBoxEv+0x288>
 *   @0x1e3388 vmov r0, s15
 *   @0x1e338c bl 0xb6994 <ceilf@plt>
 *   @0x1e3390 vadd.f32 s19, s17, s19
 *   @0x1e3394 vsqrt.f32 s15, s19
 *   @0x1e3398 vmov s20, r0
 *   @0x1e339c vcmp.f32 s15, s15
 *   @0x1e33a0 vmrs APSR_nzcv, fpscr
 *   @0x1e33a4 bne 0x1e3588 <_ZN7CSprite18ComputeBoundingBoxEv+0x268>
 *   @0x1e33a8 vadd.f32 s18, s18, s16
 *   @0x1e33ac vmov r0, s15
 *   @0x1e33b0 bl 0xb6994 <ceilf@plt>
 *   @0x1e33b4 vsqrt.f32 s15, s18
 *   @0x1e33b8 vmov s19, r0
 *   @0x1e33bc vcmp.f32 s15, s15
 *   @0x1e33c0 vmrs APSR_nzcv, fpscr
 *   @0x1e33c4 bne 0x1e35b8 <_ZN7CSprite18ComputeBoundingBoxEv+0x298>
 *   @0x1e33c8 vadd.f32 s16, s17, s16
 *   @0x1e33cc vmov r0, s15
 *   @0x1e33d0 bl 0xb6994 <ceilf@plt>
 *   @0x1e33d4 vsqrt.f32 s15, s16
 *   @0x1e33d8 vmov s18, r0
 *   @0x1e33dc vcmp.f32 s15, s15
 *   @0x1e33e0 vmrs APSR_nzcv, fpscr
 *   @0x1e33e4 bne 0x1e3598 <_ZN7CSprite18ComputeBoundingBoxEv+0x278>
 *   @0x1e33e8 vmov r0, s15
 *   @0x1e33ec bl 0xb6994 <ceilf@plt>
 *   @0x1e33f0 vcvt.s32.f32 s18, s18
 *   @0x1e33f4 ldr r3, [r4, #0x4]
 *   @0x1e33f8 vcvt.s32.f32 s19, s19
 *   @0x1e33fc vmov r2, s18
 *   @0x1e3400 vmov r1, s19
 *   @0x1e3404 vcvt.s32.f32 s20, s20
 *   @0x1e3408 vmov s13, r0
 *   @0x1e340c vcvt.s32.f32 s13, s13
 *   @0x1e3410 cmp r2, r1
 *   @0x1e3414 movlt r2, r1
 *   @0x1e3418 vmov r1, s20
 *   @0x1e341c vmov r0, s13
 *   @0x1e3420 cmp r2, r0
 *   @0x1e3424 movlt r2, r0
 *   @0x1e3428 cmp r1, r2
 *   @0x1e342c strge r1, [r4, #0x2c]
 *   @0x1e3430 strlt r2, [r4, #0x2c]
 *   @0x1e3434 cmp r3, #2
 *   @0x1e3438 beq 0x1e352c <_ZN7CSprite18ComputeBoundingBoxEv+0x20c>
 *   @0x1e343c ldrb r2, [r4, #0x32]
 *   @0x1e3440 cmp r2, #0
 *   @0x1e3444 bne 0x1e3534 <_ZN7CSprite18ComputeBoundingBoxEv+0x214>
 *   @0x1e3448 ldr r1, [r4, #0x1c]
 *   @0x1e344c mov r3, #0
 *   @0x1e3450 ldr r2, [r4, #0x20]
 *   @0x1e3454 sub r1, r1, #1
 *   @0x1e3458 str r3, [r4, #0x8]
 *   @0x1e345c sub r2, r2, #1
 *   @0x1e3460 str r1, [r4, #0x10]
 *   @0x1e3464 str r3, [r4, #0xc]
 *   @0x1e3468 str r2, [r4, #0x14]
 *   @0x1e346c ldr r3, [r4, #0x18]
 *   @0x1e3470 ldr r2, [r4, #0x74]
 *   @0x1e3474 cmp r3, #0
 *   @0x1e3478 streq r3, [r4, #0xc]
 *   @0x1e347c streq r3, [r4, #0x10]
 *   @0x1e3480 streq r3, [r4, #0x8]
 *   @0x1e3484 streq r3, [r4, #0x14]
 *   @0x1e3488 cmp r2, #1
 *   @0x1e348c beq 0x1e3540 <_ZN7CSprite18ComputeBoundingBoxEv+0x220>
 *   @0x1e3490 cmp r3, #0
 *   @0x1e3494 ldr r2, [r4, #0x1c]
 *   @0x1e3498 ldr r3, [r4, #0x20]
 *   @0x1e349c mov r5, #0
 *   @0x1e34a0 sub r2, r2, #1
 *   @0x1e34a4 str r5, [r4, #0x10]
 *   @0x1e34a8 sub r3, r3, #1
 *   @0x1e34ac str r2, [r4, #0x8]
 *   @0x1e34b0 str r5, [r4, #0x14]
 *   @0x1e34b4 str r3, [r4, #0xc]
 *   @0x1e34b8 ble 0x1e352c <_ZN7CSprite18ComputeBoundingBoxEv+0x20c>
 *   @0x1e34bc ldr r3, [r4, #0x48]
 *   @0x1e34c0 ldr r0, [r3, r5, lsl #2]
 *   @0x1e34c4 add r5, r5, #1
 *   @0x1e34c8 bl 0x167508 <_ZN9CBitmap3211BoundingBoxEv>
 *   @0x1e34cc ldr r8, [r4, #0x8]
 *   @0x1e34d0 ldr r6, [r4, #0x10]
 *   @0x1e34d4 ldr r12, [r4, #0xc]
 *   @0x1e34d8 ldr r2, [r4, #0x14]
 *   @0x1e34dc ldr r3, [r0, #0xc]
 *   @0x1e34e0 ldr r7, [r0]
 *   @0x1e34e4 ldr lr, [r0, #0x8]
 *   @0x1e34e8 ldr r1, [r0, #0x4]
 *   @0x1e34ec cmp r2, r3
 *   @0x1e34f0 strge r2, [r4, #0x14]
 *   @0x1e34f4 strlt r3, [r4, #0x14]
 *   @0x1e34f8 cmp r8, r7
 *   @0x1e34fc strle r8, [r4, #0x8]
 *   @0x1e3500 strgt r7, [r4, #0x8]
 *   @0x1e3504 cmp r6, lr
 *   @0x1e3508 strge r6, [r4, #0x10]
 *   @0x1e350c strlt lr, [r4, #0x10]
 *   @0x1e3510 cmp r12, r1
 *   @0x1e3514 strle r12, [r4, #0xc]
 *   @0x1e3518 strgt r1, [r4, #0xc]
 *   @0x1e351c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e3520 ldr r3, [r4, #0x18]
 *   @0x1e3524 cmp r3, r5
 *   @0x1e3528 bgt 0x1e34bc <_ZN7CSprite18ComputeBoundingBoxEv+0x19c>
 *   @0x1e352c vpop {d8, d9, d10}
 *   @0x1e3530 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1e3534 cmp r3, #1
 *   @0x1e3538 bne 0x1e346c <_ZN7CSprite18ComputeBoundingBoxEv+0x14c>
 *   @0x1e353c b 0x1e3448 <_ZN7CSprite18ComputeBoundingBoxEv+0x128>
 *   @0x1e3540 ldr r3, [r4, #0x84]
 *   @0x1e3544 cmp r3, #0
 *   @0x1e3548 beq 0x1e352c <_ZN7CSprite18ComputeBoundingBoxEv+0x20c>
 *   @0x1e354c vldr s15, [r3, #8]
 *   @0x1e3550 vcvt.s32.f32 s15, s15
 *   @0x1e3554 vldr s13, [r3, #12]
 *   @0x1e3558 vldr s14, [r3, #16]
 *   @0x1e355c vpop {d8, d9, d10}
 *   @0x1e3560 vmov r2, s15
 *   @0x1e3564 vldr s15, [r3, #20]
 *   @0x1e3568 vcvt.s32.f32 s13, s13
 *   @0x1e356c vcvt.s32.f32 s14, s14
 *   @0x1e3570 vstr s13, [r4, #16]
 *   @0x1e3574 vcvt.s32.f32 s15, s15
 *   @0x1e3578 vstr s14, [r4, #12]
 *   @0x1e357c str r2, [r4, #0x8]
 *   @0x1e3580 vstr s15, [r4, #20]
 *   @0x1e3584 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1e3588 vmov r0, s19
 *   @0x1e358c bl 0xb6700 <sqrtf@plt>
 *   @0x1e3590 vmov s15, r0
 *   @0x1e3594 b 0x1e33a8 <_ZN7CSprite18ComputeBoundingBoxEv+0x88>
 *   @0x1e3598 vmov r0, s16
 *   @0x1e359c bl 0xb6700 <sqrtf@plt>
 *   @0x1e35a0 vmov s15, r0
 *   @0x1e35a4 b 0x1e33e8 <_ZN7CSprite18ComputeBoundingBoxEv+0xc8>
 *   @0x1e35a8 vmov r0, s14
 *   @0x1e35ac bl 0xb6700 <sqrtf@plt>
 *   @0x1e35b0 vmov s15, r0
 *   @0x1e35b4 b 0x1e3388 <_ZN7CSprite18ComputeBoundingBoxEv+0x68>
 *   @0x1e35b8 vmov r0, s18
 *   @0x1e35bc bl 0xb6700 <sqrtf@plt>
 *   @0x1e35c0 vmov s15, r0
 *   @0x1e35c4 b 0x1e33c8 <_ZN7CSprite18ComputeBoundingBoxEv+0xa8>
 *
 * ══ §5/46 FT_Outline_Decompose  0x2e6078  size 678  170 条（0x2e6078..0x2e631e）
 * @func 0x2e6078 0x2e6320  size 680  170 条
 * 部分覆盖: 本节 170/303 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x4e73c0 / 0x328fc0 / 0x49e1e8 / 0xff4a2e44 / FT_Outline_Decompose+0x122 / 0x366ea8 / 0xff4a2ec4 / 0xff4a2ed0
 * 字段偏移 top8: 0xc×6 / 0x8×5 / 0x2c×4 / 0x40×3 / 0x14×2 / 0x4×2 / 0x18×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6078 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e607c sub sp, #0x4c
 *   @0x2e6080 mov r9, r2
 *   @0x2e6084 cmp r0, #0x0
 *   @0x2e6088 stmdbhs r0, {r3, r7, pc}
 *   @0x2e608c beq.w 0x2e6316 <FT_Outline_Decompose+0x29e>
 *   @0x2e6090 movs r3, #0x0
 *   @0x2e6094 stmdbvs sp, {r6, r11}
 *   @0x2e6098 ldr r6, [r1, #0x14]
 *   @0x2e609c str.w r8, [sp, #0x1c]
 *   @0x2e60a0 b 0x2e6178 <FT_Outline_Decompose+0x100>
 *   @0x2e60a4 stmdage r10, {r2, pc}
 *   @0x2e60a8 str r0, [sp, #0x4]
 *   @0x2e60ac bl 0x4e73c0 <SrcVerts+0x44404>
 *   @0x2e60b0 bls 0x328fc0
 *   @0x2e60b4 ldm.w r4, {r0, r1}
 *   @0x2e60b8 stm.w r2, {r0, r1}
 *   @0x2e60bc lsl.w r12, r0, r5
 *   @0x2e60c0 ldr r2, [sp, #0x2c]
 *   @0x2e60c4 stmdbls r4, {r2, r3, r10, r11}
 *   @0x2e60c8 str.w r12, [sp, #0x28]
 *   @0x2e60cc lsls r2, r5
 *   @0x2e60d0 str r2, [sp, #0x2c]
 *   @0x2e60d4 .word 0xf10d0031
 *   @0x2e60d8 .word 0xf8db0820
 *   @0x2e60dc .word 0xf8cd1004
 *   @0x2e60e0 .word 0xf8dd8008
 *   @0x2e60e4 adcmi r8, r8, r4
 *   @0x2e60e8 lsl.w r10, r1, r5
 *   @0x2e60ec str r0, [sp, #0x18]
 *   @0x2e60f0 .word 0xf8dd0003
 *   @0x2e60f4 stm r8, {r3, pc}
 *   @0x2e60f8 stmdals r3, {r0, r1}
 *   @0x2e60fc ldr r1, [r0, #0x8]
 *   @0x2e6100 stclpl p8, c0, [r11], {3}
 *   @0x2e6104 and r3, r3, #0x3
 *   @0x2e6108 cmp r3, #0x2
 *   @0x2e610c cmp r3, #0x0
 *   @0x2e6110 ldr r3, [r7]
 *   @0x2e6114 mov r1, r9
 *   @0x2e6118 cmp r0, #0x0
 *   @0x2e611c stmdage r12, {r0, r2, r3, r4, r5, r6, r7, pc}
 *   @0x2e6120 str r0, [sp, #0x18]
 *   @0x2e6124 bhs.w 0x2e6308 <FT_Outline_Decompose+0x290>
 *   @0x2e6128 ldrb.w r3, [r8, #0x1]
 *   @0x2e612c add.w r10, r4, #0x8
 *   @0x2e6130 add.w r2, r8, #0x1
 *   @0x2e6134 ands r3, r3, #0x3
 *   @0x2e6138 bne 0x2e61de <FT_Outline_Decompose+0x166>
 *   @0x2e613c lsls r3, r5
 *   @0x2e6140 str r3, [sp, #0x20]
 *   @0x2e6144 add.w r4, r8, #0x2
 *   @0x2e6148 lsls r3, r5
 *   @0x2e614c str r3, [sp, #0x24]
 *   @0x2e6150 cmp r3, r11
 *   @0x2e6154 ldr r3, [r7, #0x8]
 *   @0x2e6158 add r1, sp, #0x28
 *   @0x2e615c blx r3
 *   @0x2e6160 bne.w 0x2e6318 <FT_Outline_Decompose+0x2a0>
 *   @0x2e6164 ldr.w r8, [sp, #0x10]
 *   @0x2e6168 add.w r3, r8, #0x1
 *   @0x2e616c ldr.w r8, [sp, #0x14]
 *   @0x2e6170 add.w r8, r8, #0x1
 *   @0x2e6174 str.w r8, [sp, #0x14]
 *   @0x2e6178 ldr r0, [sp, #0xc]
 *   @0x2e617c rfeib r0!
 *   @0x2e6180 ldrmi r2, [r0]
 *   @0x2e6184 bge.w 0x2e6312 <FT_Outline_Decompose+0x29a>
 *   @0x2e6188 ldr r0, [sp, #0xc]
 *   @0x2e618c stmvs r2, {r2, r4, pc} ^
 *   @0x2e6190 ldrsh.w r2, [r2, r8, lsl #1]
 *   @0x2e6194 cmp r2, #0x0
 *   @0x2e6198 bge 0x2e60a2 <FT_Outline_Decompose+0x2a>
 *   @0x2e619c b 0x2e6318 <FT_Outline_Decompose+0x2a0>
 *   @0x2e61a0 blls 0x49e1e8 <TimingData+0x41d0>
 *   @0x2e61a4 ldrb.w r1, [r1, lr]
 *   @0x2e61a8 subs r0, r3, r6
 *   @0x2e61ac .word 0xf001030a
 *   @0x2e61b0 stmdbhs r1, {r0, r1, r8}
 *   @0x2e61b4 bne 0x2e61c0 <FT_Outline_Decompose+0x148>
 *   @0x2e61b8 sub.w r11, r11, #0x8
 *   @0x2e61bc str r3, [sp, #0x2c]
 *   @0x2e61c0 add r12, r0
 *   @0x2e61c4 add.w r12, r12, r12, lsr #31
 *   @0x2e61c8 add.w r2, r2, r2, lsr #31
 *   @0x2e61cc asr.w r1, r12, #0x1
 *   @0x2e61d0 asrs r2, r2, #0x1
 *   @0x2e61d4 str r2, [sp, #0x2c]
 *   @0x2e61d8 add.w r8, r8, #0xffffffff
 *   @0x2e61dc b 0x2e6110 <FT_Outline_Decompose+0x98>
 *   @0x2e61e0 bne 0x2e6286 <FT_Outline_Decompose+0x20e>
 *   @0x2e61e4 add r0, sp, #0x40
 *   @0x2e61e8 lsls r3, r5
 *   @0x2e61ec str r3, [sp, #0x40]
 *   @0x2e61f0 lsls r3, r5
 *   @0x2e61f4 str r3, [sp, #0x44]
 *   @0x2e61f8 str r2, [sp]
 *   @0x2e61fc ldr r2, [sp]
 *   @0x2e6200 bne.w 0x2e6318 <FT_Outline_Decompose+0x2a0>
 *   @0x2e6204 mov r8, r2
 *   @0x2e6208 ldr r2, [r3, #0x8]
 *   @0x2e620c ldrb.w r1, [r8]
 *   @0x2e6210 add.w r12, r3, #0x8
 *   @0x2e6214 adds r4, #0x1
 *   @0x2e6218 and r1, r1, #0x3
 *   @0x2e621c subs r2, r2, r6
 *   @0x2e6220 ldr r3, [r3, #0xc]
 *   @0x2e6224 mov r10, r12
 *   @0x2e6228 bl 0xff4a2e44 <b2_toiTime+0xfffffffffed499a0>
 *   @0x2e622c movwls r0, #0xf303
 *   @0x2e6230 bne 0x2e6242 <FT_Outline_Decompose+0x1ca>
 *   @0x2e6234 add r0, sp, #0x20
 *   @0x2e6238 mov r2, r9
 *   @0x2e623c cmp r0, #0x0
 *   @0x2e6240 b 0x2e6304 <FT_Outline_Decompose+0x28c>
 *   @0x2e6244 bne 0x2e619a <FT_Outline_Decompose+0x122>
 *   @0x2e6248 add r0, sp, #0x20
 *   @0x2e624c add r1, sp, #0x40
 *   @0x2e6250 ldrsbne r7, [r2], #-34
 *   @0x2e6254 str r2, [sp, #0x40]
 *   @0x2e6258 add r3, r2
 *   @0x2e625c add.w r3, r3, r3, lsr #31
 *   @0x2e6260 asrs r3, r3, #0x1
 *   @0x2e6264 ldr r3, [r7, #0x8]
 *   @0x2e6268 ldrmi r12, [r8, r0]
 *   @0x2e626c ldr.w r12, [sp]
 *   @0x2e6270 cmp r0, #0x0
 *   @0x2e6274 add r3, sp, #0x38
 *   @0x2e6278 ldm r3, {r3, pc}
 *   @0x2e627c strbtmi r0, [r3], -r3
 *   @0x2e6280 stm.w r8, {r0, r1}
 *   @0x2e6284 b 0x2e6150 <FT_Outline_Decompose+0xd8>
 *   @0x2e6288 ldrmi r0, [r11, #0x310]
 *   @0x2e628c blo 0x2e619a <FT_Outline_Decompose+0x122>
 *   @0x2e6290 .word 0xf0033002
 *   @0x2e6294 blhs 0x366ea8 <_ZTS12CDS_Priority+0x8f00>
 *   @0x2e6298 bne.w 0x2e619a <FT_Outline_Decompose+0x122>
 *   @0x2e629c ldr r3, [r4, #0x8]
 *   @0x2e62a0 ldrbmi r0, [r10, #0xa18]
 *   @0x2e62a4 add r1, sp, #0x38
 *   @0x2e62a8 bl 0xff4a2ec4 <b2_toiTime+0xfffffffffed49a20>
 *   @0x2e62ac movwls r0, #0xc303
 *   @0x2e62b0 ldr r3, [r4, #0xc]
 *   @0x2e62b4 bl 0xff4a2ed0 <b2_toiTime+0xfffffffffed49a2c>
 *   @0x2e62b8 movwls r0, #0xd303
 *   @0x2e62bc ldr r3, [r4, #0x10]
 *   @0x2e62c0 bl 0xff4a2edc <b2_toiTime+0xfffffffffed49a38>
 *   @0x2e62c4 movwls r0, #0xe303
 *   @0x2e62c8 ldr r3, [r4, #0x14]
 *   @0x2e62cc bl 0xff4a2ee8 <b2_toiTime+0xfffffffffed49a44>
 *   @0x2e62d0 movwls r0, #0xf303
 *   @0x2e62d4 bhi 0x2e62f8 <FT_Outline_Decompose+0x280>
 *   @0x2e62d8 add r0, sp, #0x30
 *   @0x2e62dc lsls r3, r5
 *   @0x2e62e0 str r3, [sp, #0x40]
 *   @0x2e62e4 ldr r4, [r7, #0xc]
 *   @0x2e62e8 subs r3, r3, r6
 *   @0x2e62ec mov r3, r9
 *   @0x2e62f0 cbnz r0, 0x2e6318 <FT_Outline_Decompose+0x2a0>
 *   @0x2e62f4 and r0, r5, r3, lsl #16
 *   @0x2e62f8 ldr r4, [r7, #0xc]
 *   @0x2e62fc add r2, sp, #0x28
 *   @0x2e6300 blx r4
 *   @0x2e6304 mov r4, r10
 *   @0x2e6308 ldr r3, [r7, #0x4]
 *   @0x2e630c mov r1, r9
 *   @0x2e6310 b 0x2e615e <FT_Outline_Decompose+0xe6>
 *   @0x2e6314 b 0x2e6318 <FT_Outline_Decompose+0x2a0>
 *   @0x2e6318 add sp, #0x4c
 *   @0x2e631c ldrlt r8, [r0, #-0xff0]!
 *
 * ══ §6/46 F_CameraCreateView(RValue&, CInstance*, CInstance*, int, RValue*)  0x16ee64  size 676  169 条（0x16ee64..0x16f108）
 * @func 0x16ee64 0x16f108  size 676  169 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / CCamera::GetViewX()×2 / CCamera::GetViewWidth()×2 / CCamera::GetViewY()×2 / CCamera::GetViewHeight()×2 / F_CameraCreateView(RValue&, CInstance*, CInstance*, int, RValue*)+0x19c / CCameraManager::CreateCamera() / CCamera::GetID()
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x4×1 / 0x260×1 / 0xf4×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ee64 cmp r3, #3
 *   @0x16ee68 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16ee6c vpush {d8, d9}
 *   @0x16ee70 mov r8, r3
 *   @0x16ee74 mov r3, #0
 *   @0x16ee78 mov r5, r0
 *   @0x16ee7c mov r6, r3
 *   @0x16ee80 ldr r7, [sp, #0x38]
 *   @0x16ee84 movt r3, #0xbff0
 *   @0x16ee88 str r6, [r0, #0xc]
 *   @0x16ee8c str r3, [r0, #0x4]
 *   @0x16ee90 str r6, [r0]
 *   @0x16ee94 ble 0x16f000 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x16ee98 ldr r0, [pc, #0x260]
 *   @0x16ee9c ldr r0, [pc, r0]
 *   @0x16eea0 bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv>
 *   @0x16eea4 mov r4, r0
 *   @0x16eea8 bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16eeac cmp r4, #0
 *   @0x16eeb0 vmov s15, r0
 *   @0x16eeb4 vcvt.f64.s32 d7, s15
 *   @0x16eeb8 vmov r0, r1, d7
 *   @0x16eebc vmov r2, s14
 *   @0x16eec0 mov r3, r1
 *   @0x16eec4 stm r5, {r2, r3}
 *   @0x16eec8 beq 0x16f018 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x16eecc mov r1, r6
 *   @0x16eed0 mov r0, r7
 *   @0x16eed4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16eed8 mov r1, r0
 *   @0x16eedc mov r0, r4
 *   @0x16eee0 bl 0x16d29c <_ZN7CCamera8SetViewXEf>
 *   @0x16eee4 mov r1, #1
 *   @0x16eee8 mov r0, r7
 *   @0x16eeec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16eef0 mov r1, r0
 *   @0x16eef4 mov r0, r4
 *   @0x16eef8 bl 0x16d2ac <_ZN7CCamera8SetViewYEf>
 *   @0x16eefc mov r1, #2
 *   @0x16ef00 mov r0, r7
 *   @0x16ef04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16ef08 mov r1, r0
 *   @0x16ef0c mov r0, r4
 *   @0x16ef10 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf>
 *   @0x16ef14 mov r1, #3
 *   @0x16ef18 mov r0, r7
 *   @0x16ef1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16ef20 mov r1, r0
 *   @0x16ef24 mov r0, r4
 *   @0x16ef28 bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf>
 *   @0x16ef2c cmp r8, #4
 *   @0x16ef30 moveq r6, #0
 *   @0x16ef34 bne 0x16f06c <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x16ef38 mvn r9, #0
 *   @0x16ef3c mov r10, #0
 *   @0x16ef40 movt r10, #0xbf80
 *   @0x16ef44 mov r11, #0
 *   @0x16ef48 movt r11, #0xbf80
 *   @0x16ef4c mov r5, #0
 *   @0x16ef50 mov r7, r5
 *   @0x16ef54 mov r1, r6
 *   @0x16ef58 mov r0, r4
 *   @0x16ef5c bl 0x16d31c <_ZN7CCamera12SetViewAngleEf>
 *   @0x16ef60 mov r0, r4
 *   @0x16ef64 mov r1, r9
 *   @0x16ef68 vmov.f32 s17, #5.000000e-01
 *   @0x16ef6c bl 0x16d32c <_ZN7CCamera17SetTargetInstanceEi>
 *   @0x16ef70 mov r0, r4
 *   @0x16ef74 mov r1, r10
 *   @0x16ef78 bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf>
 *   @0x16ef7c mov r0, r4
 *   @0x16ef80 mov r1, r11
 *   @0x16ef84 bl 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf>
 *   @0x16ef88 mov r0, r4
 *   @0x16ef8c mov r1, r5
 *   @0x16ef90 bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf>
 *   @0x16ef94 mov r0, r4
 *   @0x16ef98 mov r1, r7
 *   @0x16ef9c bl 0x16d30c <_ZN7CCamera14SetViewBorderYEf>
 *   @0x16efa0 mov r0, r4
 *   @0x16efa4 bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv>
 *   @0x16efa8 cmp r0, #0
 *   @0x16efac mov r0, r4
 *   @0x16efb0 bne 0x16f020 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x16efb4 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv>
 *   @0x16efb8 vmov s16, r0
 *   @0x16efbc mov r0, r4
 *   @0x16efc0 bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv>
 *   @0x16efc4 vmov s14, r0
 *   @0x16efc8 mov r0, r4
 *   @0x16efcc vmla.f32 s16, s14, s17
 *   @0x16efd0 bl 0x16d2b4 <_ZN7CCamera8GetViewYEv>
 *   @0x16efd4 vmov s18, r0
 *   @0x16efd8 mov r0, r4
 *   @0x16efdc bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv>
 *   @0x16efe0 vmov r1, s16
 *   @0x16efe4 vmov s15, r0
 *   @0x16efe8 mov r0, r4
 *   @0x16efec vmla.f32 s18, s15, s17
 *   @0x16eff0 vmov r2, s18
 *   @0x16eff4 vpop {d8, d9}
 *   @0x16eff8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16effc b 0x16dc0c <_ZN7CCamera11Build3DViewEff>
 *   @0x16f000 vpop {d8, d9}
 *   @0x16f004 mov r1, r6
 *   @0x16f008 ldr r0, [pc, #0xf4]
 *   @0x16f00c add r0, pc, r0
 *   @0x16f010 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16f014 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f018 vpop {d8, d9}
 *   @0x16f01c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x16f020 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv>
 *   @0x16f024 vmov s16, r0
 *   @0x16f028 mov r0, r4
 *   @0x16f02c bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv>
 *   @0x16f030 vmov s14, r0
 *   @0x16f034 mov r0, r4
 *   @0x16f038 vmla.f32 s16, s14, s17
 *   @0x16f03c bl 0x16d2b4 <_ZN7CCamera8GetViewYEv>
 *   @0x16f040 vmov s18, r0
 *   @0x16f044 mov r0, r4
 *   @0x16f048 bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv>
 *   @0x16f04c vmov r1, s16
 *   @0x16f050 vmov s15, r0
 *   @0x16f054 mov r0, r4
 *   @0x16f058 vmla.f32 s18, s15, s17
 *   @0x16f05c vmov r2, s18
 *   @0x16f060 vpop {d8, d9}
 *   @0x16f064 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16f068 b 0x16db44 <_ZN7CCamera11Build2DViewEff>
 *   @0x16f06c mov r0, r7
 *   @0x16f070 mov r1, #4
 *   @0x16f074 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f078 cmp r8, #5
 *   @0x16f07c mov r6, r0
 *   @0x16f080 beq 0x16ef38 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x16f084 mov r0, r7
 *   @0x16f088 mov r1, #5
 *   @0x16f08c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f090 cmp r8, #6
 *   @0x16f094 mov r9, r0
 *   @0x16f098 beq 0x16ef3c <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x16f09c mov r0, r7
 *   @0x16f0a0 mov r1, #6
 *   @0x16f0a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f0a8 cmp r8, #7
 *   @0x16f0ac mov r10, r0
 *   @0x16f0b0 beq 0x16ef44 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x16f0b4 mov r0, r7
 *   @0x16f0b8 mov r1, #7
 *   @0x16f0bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f0c0 cmp r8, #8
 *   @0x16f0c4 mov r11, r0
 *   @0x16f0c8 beq 0x16ef4c <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x16f0cc mov r0, r7
 *   @0x16f0d0 mov r1, #8
 *   @0x16f0d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f0d8 cmp r8, #9
 *   @0x16f0dc mov r5, r0
 *   @0x16f0e0 beq 0x16f0f8 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x16f0e4 mov r0, r7
 *   @0x16f0e8 mov r1, #9
 *   @0x16f0ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f0f0 mov r7, r0
 *   @0x16f0f4 b 0x16ef54 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x16f0f8 mov r7, #0
 *   @0x16f0fc b 0x16ef54 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x16f100 .word 0x0027edd8
 *   @0x16f104 andseq r11, sp, r8, ror #25
 *
 * ══ §7/46 GR_Window_View_Convert_World(int, float, float, int&, int&)  0x17a110  size 676  169 条（0x17a110..0x17a3b4）
 * @func 0x17a110 0x17a3b4  size 676  169 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×6 / 0xb67e4×2 / 0xb67d8×2 / CCameraManager::GetCamera(int) / CCamera::GetViewProjMat()
 * 字段偏移 top8: 0x88×1 / 0x244×1 / 0x20c×1 / 0xf4×1 / 0x2c×1
 * VFP 指令 110 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17a110 push {r4, r5, r6, lr}
 *   @0x17a114 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x17a118 vmov s19, r1
 *   @0x17a11c sub sp, sp, #64
 *   @0x17a120 mov r4, r0
 *   @0x17a124 vcvt.f64.f32 d5, s19
 *   @0x17a128 mov r6, r3
 *   @0x17a12c vmov s17, r2
 *   @0x17a130 ldr r5, [sp, #0x88]
 *   @0x17a134 vmov r0, r1, d5
 *   @0x17a138 bl 0xb66e8 <lrint@plt>
 *   @0x17a13c vcvt.f64.f32 d6, s17
 *   @0x17a140 str r0, [r6]
 *   @0x17a144 vmov r0, r1, d6
 *   @0x17a148 bl 0xb66e8 <lrint@plt>
 *   @0x17a14c cmp r4, #31
 *   @0x17a150 str r0, [r5]
 *   @0x17a154 bhi 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198>
 *   @0x17a158 add r4, r4, r4, lsl #1
 *   @0x17a15c ldr r2, [pc, #0x244]
 *   @0x17a160 lsl r4, r4, #4
 *   @0x17a164 ldr r2, [pc, r2]
 *   @0x17a168 ldrb r3, [r2, r4]
 *   @0x17a16c cmp r3, #0
 *   @0x17a170 bne 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198>
 *   @0x17a174 add r4, r4, r2
 *   @0x17a178 vldr s11, [r4, #12]
 *   @0x17a17c vcmp.f32 s11, #0
 *   @0x17a180 vmrs APSR_nzcv, fpscr
 *   @0x17a184 beq 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198>
 *   @0x17a188 vldr s10, [r4, #16]
 *   @0x17a18c vcmp.f32 s10, #0
 *   @0x17a190 vmrs APSR_nzcv, fpscr
 *   @0x17a194 beq 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198>
 *   @0x17a198 ldr r3, [pc, #0x20c]
 *   @0x17a19c ldr r3, [pc, r3]
 *   @0x17a1a0 ldrb r3, [r3]
 *   @0x17a1a4 cmp r3, #0
 *   @0x17a1a8 bne 0x17a2b4 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x1a4>
 *   @0x17a1ac vldr s15, [r4, #4]
 *   @0x17a1b0 vldr s16, [r4, #8]
 *   @0x17a1b4 vsub.f32 s19, s19, s15
 *   @0x17a1b8 vldr s8, [r4, #36]
 *   @0x17a1bc vldr s9, [r4, #28]
 *   @0x17a1c0 vldr s21, [r4, #32]
 *   @0x17a1c4 vldr d7, [pc, #460]
 *   @0x17a1c8 vsub.f32 s16, s17, s16
 *   @0x17a1cc vabs.f32 s12, s8
 *   @0x17a1d0 vmul.f32 s19, s9, s19
 *   @0x17a1d4 vmul.f32 s16, s21, s16
 *   @0x17a1d8 vcvt.f64.f32 d6, s12
 *   @0x17a1dc vcmpe.f64 d6, d7
 *   @0x17a1e0 vdiv.f32 s11, s19, s11
 *   @0x17a1e4 vmrs APSR_nzcv, fpscr
 *   @0x17a1e8 vdiv.f32 s16, s16, s10
 *   @0x17a1ec bmi 0x17a360 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x250>
 *   @0x17a1f0 vldr s27, [pc, #424]
 *   @0x17a1f4 vldr s20, [pc, #424]
 *   @0x17a1f8 vmul.f32 s22, s8, s27
 *   @0x17a1fc vdiv.f32 s22, s22, s20
 *   @0x17a200 vmov.f32 s26, #5.000000e-01
 *   @0x17a204 vmul.f32 s28, s9, s26
 *   @0x17a208 vsub.f32 s11, s11, s28
 *   @0x17a20c vcvt.f64.f32 d11, s22
 *   @0x17a210 vmov r0, r1, d11
 *   @0x17a214 vcvt.f64.f32 d9, s11
 *   @0x17a218 bl 0xb67e4 <cos@plt>
 *   @0x17a21c vmls.f32 s16, s21, s26
 *   @0x17a220 vcvt.f64.f32 d8, s16
 *   @0x17a224 vmov d12, r0, r1
 *   @0x17a228 vmov r0, r1, d11
 *   @0x17a22c bl 0xb67d8 <sin@plt>
 *   @0x17a230 vldr s14, [r4, #20]
 *   @0x17a234 vadd.f32 s14, s28, s14
 *   @0x17a238 vcvt.f64.f32 d7, s14
 *   @0x17a23c vmla.f64 d7, d9, d12
 *   @0x17a240 vmov d6, r0, r1
 *   @0x17a244 vmov.f64 d5, d7
 *   @0x17a248 vmla.f64 d5, d8, d6
 *   @0x17a24c vmov r0, r1, d5
 *   @0x17a250 bl 0xb66e8 <lrint@plt>
 *   @0x17a254 vldr s15, [r4, #36]
 *   @0x17a258 vmul.f32 s27, s15, s27
 *   @0x17a25c vdiv.f32 s20, s27, s20
 *   @0x17a260 str r0, [r6]
 *   @0x17a264 vcvt.f64.f32 d10, s20
 *   @0x17a268 vmov r0, r1, d10
 *   @0x17a26c bl 0xb67d8 <sin@plt>
 *   @0x17a270 vmov d11, r0, r1
 *   @0x17a274 vmov r0, r1, d10
 *   @0x17a278 bl 0xb67e4 <cos@plt>
 *   @0x17a27c vldr s15, [r4, #32]
 *   @0x17a280 vldr s14, [r4, #24]
 *   @0x17a284 vmla.f32 s14, s15, s26
 *   @0x17a288 vcvt.f64.f32 d7, s14
 *   @0x17a28c vmls.f64 d7, d9, d11
 *   @0x17a290 vmov d6, r0, r1
 *   @0x17a294 vmov.f64 d5, d7
 *   @0x17a298 vmla.f64 d5, d8, d6
 *   @0x17a29c vmov r0, r1, d5
 *   @0x17a2a0 bl 0xb66e8 <lrint@plt>
 *   @0x17a2a4 str r0, [r5]
 *   @0x17a2a8 add sp, sp, #64
 *   @0x17a2ac vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x17a2b0 pop {r4, r5, r6, pc}
 *   @0x17a2b4 ldr r0, [pc, #0xf4]
 *   @0x17a2b8 ldr r1, [r4, #0x2c]
 *   @0x17a2bc ldr r0, [pc, r0]
 *   @0x17a2c0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x17a2c4 subs r1, r0, #0
 *   @0x17a2c8 beq 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198>
 *   @0x17a2cc mov r0, sp
 *   @0x17a2d0 bl 0x16d1ac <_ZN7CCamera14GetViewProjMatEv>
 *   @0x17a2d4 vldr s11, [sp, #16]
 *   @0x17a2d8 vldr s12, [sp, #28]
 *   @0x17a2dc vmul.f32 s11, s17, s11
 *   @0x17a2e0 vldr s2, [sp, #20]
 *   @0x17a2e4 vldr s3, [sp]
 *   @0x17a2e8 vldr s4, [sp, #12]
 *   @0x17a2ec vldr s5, [sp, #4]
 *   @0x17a2f0 vldr s8, [sp, #52]
 *   @0x17a2f4 vldr s6, [sp, #48]
 *   @0x17a2f8 vldr s7, [sp, #60]
 *   @0x17a2fc vldr s9, [r4, #28]
 *   @0x17a300 vldr s13, [r4, #20]
 *   @0x17a304 vldr s10, [r4, #32]
 *   @0x17a308 vldr s14, [r4, #24]
 *   @0x17a30c vmul.f32 s12, s17, s12
 *   @0x17a310 vmul.f32 s17, s17, s2
 *   @0x17a314 vmla.f32 s11, s19, s3
 *   @0x17a318 vmla.f32 s12, s19, s4
 *   @0x17a31c vmla.f32 s17, s19, s5
 *   @0x17a320 vadd.f32 s12, s12, s7
 *   @0x17a324 vadd.f32 s17, s17, s8
 *   @0x17a328 vadd.f32 s11, s11, s6
 *   @0x17a32c vdiv.f32 s11, s11, s12
 *   @0x17a330 vdiv.f32 s12, s17, s12
 *   @0x17a334 vmov.f32 s15, #5.000000e-01
 *   @0x17a338 vmov.f32 s8, s15
 *   @0x17a33c vmla.f32 s8, s11, s15
 *   @0x17a340 vmla.f32 s15, s12, s15
 *   @0x17a344 vmla.f32 s13, s8, s9
 *   @0x17a348 vmla.f32 s14, s15, s10
 *   @0x17a34c vcvt.s32.f32 s13, s13
 *   @0x17a350 vcvt.s32.f32 s14, s14
 *   @0x17a354 vstr s13, [r6]
 *   @0x17a358 vstr s14, [r5]
 *   @0x17a35c b 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198>
 *   @0x17a360 vldr s15, [r4, #20]
 *   @0x17a364 vadd.f32 s11, s11, s15
 *   @0x17a368 vcvt.f64.f32 d6, s11
 *   @0x17a36c vmov r0, r1, d6
 *   @0x17a370 bl 0xb66e8 <lrint@plt>
 *   @0x17a374 vldr s15, [r4, #24]
 *   @0x17a378 vadd.f32 s16, s16, s15
 *   @0x17a37c vcvt.f64.f32 d7, s16
 *   @0x17a380 str r0, [r6]
 *   @0x17a384 vmov r0, r1, d7
 *   @0x17a388 bl 0xb66e8 <lrint@plt>
 *   @0x17a38c str r0, [r5]
 *   @0x17a390 b 0x17a2a8 <_Z28GR_Window_View_Convert_WorldiffRiS_+0x198>
 *   @0x17a394 nop
 *   @0x17a398 .word 0x47ae147b
 *   @0x17a39c svclo #0x847ae1
 *   @0x17a3a0 ldrdmi r0, r1, [r9], #-251
 *   @0x17a3a4 teqmi r4, #0
 *   @0x17a3a8 mlaeq r7, r12, r1, r6
 *   @0x17a3ac eoreq r3, r7, r8, lsl #15
 *   @0x17a3b0 .word 0x002739b8
 *
 * ══ §8/46 Shader_Setup(char*, char*, char**, bool*, int, char**)  0x1878d8  size 676  169 条（0x1878d8..0x187b7c）
 * @func 0x1878d8 0x187b7c  size 676  169 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x187a20→0x479b38, 0x187a3c→0x479b34, 0x187a58→0x479b34
 * 调用序列: operator delete[](void*)×5 / 0xb6538×4 / MemoryManager::Free(void const*)×4 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65bc×2 / operator new(unsigned int) / Shader_Build(GLSLShader*, char**, bool*, int, char**) / operator delete(void*)
 * 字段偏移 top8: 0x14×4 / 0x34×4 / 0x78×4 / 0xc×3 / 0x10×3 / 0x2c×3 / 0x38×3 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1878d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1878dc cmp r1, #0
 *   @0x1878e0 cmpne r0, #0
 *   @0x1878e4 ldr r8, [pc, #0x280]
 *   @0x1878e8 mov r7, r0
 *   @0x1878ec sub sp, sp, #12
 *   @0x1878f0 mov r6, r1
 *   @0x1878f4 add r8, pc, r8
 *   @0x1878f8 movne r5, #0
 *   @0x1878fc moveq r5, #1
 *   @0x187900 mov r10, r2
 *   @0x187904 mov r9, r3
 *   @0x187908 moveq r0, #0
 *   @0x18790c beq 0x187b64 <_Z12Shader_SetupPcS_PS_PbiS0_+0x28c>
 *   @0x187910 mov r0, #128
 *   @0x187914 ldr r11, [pc, #0x254]
 *   @0x187918 bl 0x27c524 <_Znwj>
 *   @0x18791c mvn r12, #0
 *   @0x187920 add r11, pc, r11
 *   @0x187924 mov r4, r0
 *   @0x187928 str r5, [r0]
 *   @0x18792c str r5, [r0, #0x4]
 *   @0x187930 mov r0, r7
 *   @0x187934 str r12, [r4, #0x1c]
 *   @0x187938 str r12, [r4, #0x20]
 *   @0x18793c str r12, [r4, #0x24]
 *   @0x187940 str r12, [r4, #0x28]
 *   @0x187944 str r12, [r4, #0x40]
 *   @0x187948 str r5, [r4, #0x8]
 *   @0x18794c str r5, [r4, #0xc]
 *   @0x187950 str r5, [r4, #0x10]
 *   @0x187954 str r5, [r4, #0x14]
 *   @0x187958 str r5, [r4, #0x18]
 *   @0x18795c str r5, [r4, #0x2c]
 *   @0x187960 str r5, [r4, #0x30]
 *   @0x187964 str r5, [r4, #0x34]
 *   @0x187968 str r5, [r4, #0x38]
 *   @0x18796c str r5, [r4, #0x78]
 *   @0x187970 str r5, [r4, #0x7c]
 *   @0x187974 mov r5, r11
 *   @0x187978 bl 0xb6538 <strlen@plt>
 *   @0x18797c mov r3, #1
 *   @0x187980 mov r1, r11
 *   @0x187984 mov r2, #70
 *   @0x187988 add r0, r0, r3
 *   @0x18798c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x187990 mov r11, r0
 *   @0x187994 mov r0, r7
 *   @0x187998 str r11, [r4, #0xc]
 *   @0x18799c bl 0xb6538 <strlen@plt>
 *   @0x1879a0 mov r1, r7
 *   @0x1879a4 add r2, r0, #1
 *   @0x1879a8 mov r0, r11
 *   @0x1879ac bl 0xb65bc <memcpy@plt>
 *   @0x1879b0 mov r0, r6
 *   @0x1879b4 bl 0xb6538 <strlen@plt>
 *   @0x1879b8 mov r3, #1
 *   @0x1879bc mov r1, r5
 *   @0x1879c0 mov r2, #70
 *   @0x1879c4 add r0, r0, r3
 *   @0x1879c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1879cc mov r5, r0
 *   @0x1879d0 mov r0, r6
 *   @0x1879d4 str r5, [r4, #0x10]
 *   @0x1879d8 bl 0xb6538 <strlen@plt>
 *   @0x1879dc mov r1, r6
 *   @0x1879e0 add r2, r0, #1
 *   @0x1879e4 mov r0, r5
 *   @0x1879e8 bl 0xb65bc <memcpy@plt>
 *   @0x1879ec ldr r3, [sp, #0x34]
 *   @0x1879f0 mov r1, r10
 *   @0x1879f4 mov r2, r9
 *   @0x1879f8 mov r0, r4
 *   @0x1879fc str r3, [sp]
 *   @0x187a00 ldr r3, [sp, #0x30]
 *   @0x187a04 bl 0x187468 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_>
 *   @0x187a08 cmp r0, #0
 *   @0x187a0c movne r0, r4
 *   @0x187a10 bne 0x187b64 <_Z12Shader_SetupPcS_PS_PbiS0_+0x28c>
 *   @0x187a14 ldr r0, [r4, #0x8]
 *   @0x187a18 cmn r0, #1
 *   @0x187a1c beq 0x187a30 <_Z12Shader_SetupPcS_PS_PbiS0_+0x158>
 *   @0x187a20 ldr r3, [pc, #0x14c]
 *   @0x187a24 ldr r3, [r8, r3]
 *   @0x187a28 ldr r3, [r3]
 *   @0x187a2c blx r3
 *   @0x187a30 ldr r0, [r4]
 *   @0x187a34 cmn r0, #1
 *   @0x187a38 beq 0x187a4c <_Z12Shader_SetupPcS_PS_PbiS0_+0x174>
 *   @0x187a3c ldr r3, [pc, #0x134]
 *   @0x187a40 ldr r3, [r8, r3]
 *   @0x187a44 ldr r3, [r3]
 *   @0x187a48 blx r3
 *   @0x187a4c ldr r0, [r4, #0x4]
 *   @0x187a50 cmn r0, #1
 *   @0x187a54 beq 0x187a68 <_Z12Shader_SetupPcS_PS_PbiS0_+0x190>
 *   @0x187a58 ldr r3, [pc, #0x118]
 *   @0x187a5c ldr r3, [r8, r3]
 *   @0x187a60 ldr r3, [r3]
 *   @0x187a64 blx r3
 *   @0x187a68 ldr r0, [r4, #0xc]
 *   @0x187a6c cmp r0, #0
 *   @0x187a70 beq 0x187a78 <_Z12Shader_SetupPcS_PS_PbiS0_+0x1a0>
 *   @0x187a74 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187a78 ldr r0, [r4, #0x10]
 *   @0x187a7c cmp r0, #0
 *   @0x187a80 beq 0x187a88 <_Z12Shader_SetupPcS_PS_PbiS0_+0x1b0>
 *   @0x187a84 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187a88 ldr r0, [r4, #0x14]
 *   @0x187a8c cmp r0, #0
 *   @0x187a90 beq 0x187acc <_Z12Shader_SetupPcS_PS_PbiS0_+0x1f4>
 *   @0x187a94 ldr r5, [r0, #-0x4]
 *   @0x187a98 add r5, r5, r5, lsl #1
 *   @0x187a9c add r5, r0, r5, lsl #2
 *   @0x187aa0 cmp r0, r5
 *   @0x187aa4 beq 0x187abc <_Z12Shader_SetupPcS_PS_PbiS0_+0x1e4>
 *   @0x187aa8 ldr r0, [r5, #-0xc]!
 *   @0x187aac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187ab0 ldr r0, [r4, #0x14]
 *   @0x187ab4 cmp r0, r5
 *   @0x187ab8 bne 0x187aa8 <_Z12Shader_SetupPcS_PS_PbiS0_+0x1d0>
 *   @0x187abc sub r0, r0, #8
 *   @0x187ac0 bl 0x27d1d4 <_ZdaPv>
 *   @0x187ac4 mov r3, #0
 *   @0x187ac8 str r3, [r4, #0x14]
 *   @0x187acc ldr r0, [r4, #0x2c]
 *   @0x187ad0 cmp r0, #0
 *   @0x187ad4 beq 0x187ae4 <_Z12Shader_SetupPcS_PS_PbiS0_+0x20c>
 *   @0x187ad8 bl 0x27d1d4 <_ZdaPv>
 *   @0x187adc mov r3, #0
 *   @0x187ae0 str r3, [r4, #0x2c]
 *   @0x187ae4 ldr r0, [r4, #0x34]
 *   @0x187ae8 cmp r0, #0
 *   @0x187aec beq 0x187afc <_Z12Shader_SetupPcS_PS_PbiS0_+0x224>
 *   @0x187af0 bl 0x27d1d4 <_ZdaPv>
 *   @0x187af4 mov r3, #0
 *   @0x187af8 str r3, [r4, #0x34]
 *   @0x187afc ldr r0, [r4, #0x38]
 *   @0x187b00 cmp r0, #0
 *   @0x187b04 beq 0x187b14 <_Z12Shader_SetupPcS_PS_PbiS0_+0x23c>
 *   @0x187b08 bl 0x27d1d4 <_ZdaPv>
 *   @0x187b0c mov r3, #0
 *   @0x187b10 str r3, [r4, #0x38]
 *   @0x187b14 ldr r0, [r4, #0x78]
 *   @0x187b18 cmp r0, #0
 *   @0x187b1c beq 0x187b58 <_Z12Shader_SetupPcS_PS_PbiS0_+0x280>
 *   @0x187b20 ldr r5, [r0, #-0x4]
 *   @0x187b24 rsb r5, r5, r5, lsl #3
 *   @0x187b28 add r5, r0, r5, lsl #2
 *   @0x187b2c cmp r0, r5
 *   @0x187b30 beq 0x187b48 <_Z12Shader_SetupPcS_PS_PbiS0_+0x270>
 *   @0x187b34 ldr r0, [r5, #-0x1c]!
 *   @0x187b38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187b3c ldr r0, [r4, #0x78]
 *   @0x187b40 cmp r0, r5
 *   @0x187b44 bne 0x187b34 <_Z12Shader_SetupPcS_PS_PbiS0_+0x25c>
 *   @0x187b48 sub r0, r0, #8
 *   @0x187b4c bl 0x27d1d4 <_ZdaPv>
 *   @0x187b50 mov r3, #0
 *   @0x187b54 str r3, [r4, #0x78]
 *   @0x187b58 mov r0, r4
 *   @0x187b5c bl 0x27d1d0 <_ZdlPv>
 *   @0x187b60 mov r0, #0
 *   @0x187b64 add sp, sp, #12
 *   @0x187b68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x187b6c eoreq r10, r6, r12, asr r3
 *   @0x187b70 andseq r9, r10, r0, lsl r7
 *   @0x187b74 .word 0xffffbb78
 *   @0x187b78 .word 0xffffbb7c
 *
 * ══ §9/46 GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)  0x1d68a0  size 676  169 条（0x1d68a0..0x1d6b44）
 * @func 0x1d68a0 0x1d6b44  size 676  169 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d691c→0x536f20, 0x1d6920→0x536f70, 0x1d6950→0x542374, 0x1d6958→0x53ab70
 * 调用序列: GR_Window_Views_Convert(int, int, int&, int&) / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)+0x284 / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)+0x138 / CInstance::Collision_Point(float, float, bool) / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)+0x1f0 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)+0xe0 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x60×4 / 0x64×4 / 0x14×4 / 0x4×4 / 0x2×3 / 0x8×3 / 0x68×2 / 0x20c×2
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d68a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d68a4 vpush {d8}
 *   @0x1d68a8 sub sp, sp, #52
 *   @0x1d68ac mov r6, r0
 *   @0x1d68b0 ldr r4, [pc, #0x274]
 *   @0x1d68b4 ldr r12, [sp, #0x60]
 *   @0x1d68b8 mov r5, r1
 *   @0x1d68bc ldr r0, [sp, #0x64]
 *   @0x1d68c0 add r4, pc, r4
 *   @0x1d68c4 vmov s17, r2
 *   @0x1d68c8 cmp r0, #0
 *   @0x1d68cc cmpne r12, #0
 *   @0x1d68d0 ldrb r12, [sp, #0x68]
 *   @0x1d68d4 vmov s16, r3
 *   @0x1d68d8 str r12, [sp, #0x14]
 *   @0x1d68dc beq 0x1d6af0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x250>
 *   @0x1d68e0 cmp r12, #0
 *   @0x1d68e4 ldr r12, [sp, #0x60]
 *   @0x1d68e8 ldr r0, [r12]
 *   @0x1d68ec beq 0x1d6afc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x25c>
 *   @0x1d68f0 ldr r12, [sp, #0x64]
 *   @0x1d68f4 mov r10, r0
 *   @0x1d68f8 ldr r7, [r12]
 *   @0x1d68fc vcvt.s32.f32 s17, s17
 *   @0x1d6900 add r2, sp, #40
 *   @0x1d6904 add r3, sp, #44
 *   @0x1d6908 add r11, r5, r6, lsl #8
 *   @0x1d690c vcvt.s32.f32 s16, s16
 *   @0x1d6910 vmov r0, s17
 *   @0x1d6914 vmov r1, s16
 *   @0x1d6918 bl 0x17a6a0 <_Z23GR_Window_Views_ConvertiiRiS_>
 *   @0x1d691c ldr r3, [pc, #0x20c]
 *   @0x1d6920 ldr r1, [pc, #0x20c]
 *   @0x1d6924 ldr r0, [r4, r3]
 *   @0x1d6928 ldrd r2, r3, [r0]
 *   @0x1d692c strd r2, r3, [sp, #8]
 *   @0x1d6930 adds r2, r2, #1
 *   @0x1d6934 adc r3, r3, #0
 *   @0x1d6938 strd r2, r3, [r0]
 *   @0x1d693c ldr r1, [r4, r1]
 *   @0x1d6940 ldr r3, [r1, r11, lsl #2]
 *   @0x1d6944 str r1, [sp, #0x18]
 *   @0x1d6948 cmp r3, #0
 *   @0x1d694c ble 0x1d6b24 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x284>
 *   @0x1d6950 ldr r2, [pc, #0x1e0]
 *   @0x1d6954 mov r8, #0
 *   @0x1d6958 ldr r3, [pc, #0x1dc]
 *   @0x1d695c mov r9, r7
 *   @0x1d6960 ldr r12, [pc, #0x1d8]
 *   @0x1d6964 add r12, pc, r12
 *   @0x1d6968 str r12, [sp, #0x24]
 *   @0x1d696c ldr r2, [r4, r2]
 *   @0x1d6970 ldr r3, [r4, r3]
 *   @0x1d6974 str r2, [sp, #0x1c]
 *   @0x1d6978 add r3, r3, r11, lsl #3
 *   @0x1d697c str r3, [sp, #0x20]
 *   @0x1d6980 ldr r12, [sp, #0x1c]
 *   @0x1d6984 ldr r3, [r12]
 *   @0x1d6988 ldr r12, [sp, #0x20]
 *   @0x1d698c ldr r2, [r3, #0x4]
 *   @0x1d6990 ldr r1, [r12, #0x4]
 *   @0x1d6994 ldr r3, [r3]
 *   @0x1d6998 ldr r1, [r1, r8, lsl #2]
 *   @0x1d699c and r2, r1, r2
 *   @0x1d69a0 ldr r3, [r3, r2, lsl #3]
 *   @0x1d69a4 cmp r3, #0
 *   @0x1d69a8 bne 0x1d69bc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x11c>
 *   @0x1d69ac b 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c>
 *   @0x1d69b0 ldr r3, [r3, #0x4]
 *   @0x1d69b4 cmp r3, #0
 *   @0x1d69b8 beq 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c>
 *   @0x1d69bc ldr r2, [r3, #0x8]
 *   @0x1d69c0 cmp r1, r2
 *   @0x1d69c4 bne 0x1d69b0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x110>
 *   @0x1d69c8 ldr r3, [r3, #0xc]
 *   @0x1d69cc cmp r3, #0
 *   @0x1d69d0 ldrne r4, [r3, #0xc4]
 *   @0x1d69d4 beq 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c>
 *   @0x1d69d8 cmp r4, #0
 *   @0x1d69dc beq 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c>
 *   @0x1d69e0 ldr r3, [r4, #0x8]
 *   @0x1d69e4 cmp r3, #0
 *   @0x1d69e8 beq 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c>
 *   @0x1d69ec ldr r5, [r4, #0x8]
 *   @0x1d69f0 ldr r4, [r4]
 *   @0x1d69f4 ldrb r3, [r5, #0x68]
 *   @0x1d69f8 cmp r3, #0
 *   @0x1d69fc bne 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138>
 *   @0x1d6a00 ldrb r6, [r5, #0x69]
 *   @0x1d6a04 cmp r6, #0
 *   @0x1d6a08 bne 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138>
 *   @0x1d6a0c ldrd r2, r3, [r5, #112]
 *   @0x1d6a10 ldrd r0, r1, [sp, #8]
 *   @0x1d6a14 cmp r0, r2
 *   @0x1d6a18 sbcs r1, r1, r3
 *   @0x1d6a1c blt 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138>
 *   @0x1d6a20 vldr s15, [sp, #40]
 *   @0x1d6a24 vcvt.f32.s32 s15, s15
 *   @0x1d6a28 mov r0, r5
 *   @0x1d6a2c mov r3, #1
 *   @0x1d6a30 vmov r1, s15
 *   @0x1d6a34 vldr s15, [sp, #44]
 *   @0x1d6a38 vcvt.f32.s32 s15, s15
 *   @0x1d6a3c vmov r2, s15
 *   @0x1d6a40 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb>
 *   @0x1d6a44 cmp r0, #0
 *   @0x1d6a48 beq 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138>
 *   @0x1d6a4c ldr r12, [sp, #0x14]
 *   @0x1d6a50 cmp r12, #0
 *   @0x1d6a54 beq 0x1d6a90 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x1f0>
 *   @0x1d6a58 cmp r7, #0
 *   @0x1d6a5c ldr r1, [r5, #0x78]
 *   @0x1d6a60 ble 0x1d6a90 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x1f0>
 *   @0x1d6a64 ldr r3, [r10]
 *   @0x1d6a68 cmp r1, r3
 *   @0x1d6a6c beq 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138>
 *   @0x1d6a70 mov r3, r10
 *   @0x1d6a74 b 0x1d6a84 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x1e4>
 *   @0x1d6a78 ldr r2, [r3, #0x4]!
 *   @0x1d6a7c cmp r1, r2
 *   @0x1d6a80 beq 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138>
 *   @0x1d6a84 add r6, r6, #1
 *   @0x1d6a88 cmp r6, r7
 *   @0x1d6a8c bne 0x1d6a78 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x1d8>
 *   @0x1d6a90 add r9, r9, #1
 *   @0x1d6a94 mov r0, #0
 *   @0x1d6a98 mov r3, #74
 *   @0x1d6a9c str r0, [sp]
 *   @0x1d6aa0 lsl r6, r9, #2
 *   @0x1d6aa4 mov r0, r10
 *   @0x1d6aa8 ldr r2, [sp, #0x24]
 *   @0x1d6aac mov r1, r6
 *   @0x1d6ab0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1d6ab4 ldr r3, [r5, #0x78]
 *   @0x1d6ab8 cmp r4, #0
 *   @0x1d6abc add r6, r0, r6
 *   @0x1d6ac0 mov r10, r0
 *   @0x1d6ac4 str r3, [r6, #-0x4]
 *   @0x1d6ac8 bne 0x1d69e0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x140>
 *   @0x1d6acc ldr r12, [sp, #0x18]
 *   @0x1d6ad0 add r8, r8, #1
 *   @0x1d6ad4 ldr r3, [r12, r11, lsl #2]
 *   @0x1d6ad8 cmp r8, r3
 *   @0x1d6adc blt 0x1d6980 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0xe0>
 *   @0x1d6ae0 ldr r12, [sp, #0x64]
 *   @0x1d6ae4 str r9, [r12]
 *   @0x1d6ae8 ldr r12, [sp, #0x60]
 *   @0x1d6aec str r10, [r12]
 *   @0x1d6af0 add sp, sp, #52
 *   @0x1d6af4 vpop {d8}
 *   @0x1d6af8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d6afc cmp r0, #0
 *   @0x1d6b00 beq 0x1d68f0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x50>
 *   @0x1d6b04 ldr r10, [sp, #0x14]
 *   @0x1d6b08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d6b0c ldr r7, [sp, #0x14]
 *   @0x1d6b10 ldr r12, [sp, #0x60]
 *   @0x1d6b14 ldr r0, [sp, #0x64]
 *   @0x1d6b18 str r7, [r12]
 *   @0x1d6b1c str r7, [r0]
 *   @0x1d6b20 b 0x1d68fc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x5c>
 *   @0x1d6b24 mov r9, r7
 *   @0x1d6b28 b 0x1d6ae0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x240>
 *   @0x1d6b2c mlaeq r1, r0, r3, r11
 *   @0x1d6b30 .word 0xffffdeb4
 *   @0x1d6b34 .word 0xffffdeb8
 *   @0x1d6b38 .word 0xffffbfec
 *   @0x1d6b3c .word 0xffffdebc
 *   @0x1d6b40 andseq r10, r5, r12, asr #13
 *
 * ══ §10/46 b2PulleyJoint::SolvePositionConstraints(b2SolverData const&)  0x2d08d4  size 676  169 条（0x2d08d4..0x2d0b78）
 * @func 0x2d08d4 0x2d0b78  size 676  169 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / 0xb6700×2 / 0xfebc67a4
 * 字段偏移 top8: 0x78×2 / 0x7c×2 / 0x18×2
 * VFP 指令 136 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d08d4 ldr r2, [r0, #0x78]
 *   @0x2d08d8 push {r3, r4, r5, lr}
 *   @0x2d08dc vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d08e0 mov r5, r1
 *   @0x2d08e4 ldr r3, [r0, #0x7c]
 *   @0x2d08e8 add r2, r2, r2, lsl #1
 *   @0x2d08ec ldr r1, [r1, #0x18]
 *   @0x2d08f0 mov r4, r0
 *   @0x2d08f4 add r3, r3, r3, lsl #1
 *   @0x2d08f8 add r2, r1, r2, lsl #2
 *   @0x2d08fc vldr s22, [r2, #8]
 *   @0x2d0900 vmov r0, s22
 *   @0x2d0904 add r3, r1, r3, lsl #2
 *   @0x2d0908 vldr s26, [r2]
 *   @0x2d090c vldr s21, [r3, #8]
 *   @0x2d0910 vldr s25, [r2, #4]
 *   @0x2d0914 vldr s24, [r3]
 *   @0x2d0918 vldr s23, [r3, #4]
 *   @0x2d091c bl 0xb6580 <sinf@plt>
 *   @0x2d0920 vmov s20, r0
 *   @0x2d0924 vmov r0, s22
 *   @0x2d0928 bl 0xb658c <cosf@plt>
 *   @0x2d092c vmov s16, r0
 *   @0x2d0930 vmov r0, s21
 *   @0x2d0934 bl 0xb6580 <sinf@plt>
 *   @0x2d0938 vmov s31, r0
 *   @0x2d093c vmov r0, s21
 *   @0x2d0940 bl 0xb658c <cosf@plt>
 *   @0x2d0944 vldr s15, [r4, #164]
 *   @0x2d0948 vldr s17, [r4, #96]
 *   @0x2d094c vsub.f32 s17, s17, s15
 *   @0x2d0950 vldr s6, [r4, #92]
 *   @0x2d0954 vldr s15, [r4, #160]
 *   @0x2d0958 vldr s7, [r4, #72]
 *   @0x2d095c vldr s8, [r4, #68]
 *   @0x2d0960 vldr s19, [r4, #104]
 *   @0x2d0964 vldr s9, [r4, #172]
 *   @0x2d0968 vldr s10, [r4, #100]
 *   @0x2d096c vldr s14, [r4, #168]
 *   @0x2d0970 vldr s11, [r4, #76]
 *   @0x2d0974 vldr s12, [r4, #80]
 *   @0x2d0978 vmul.f32 s18, s17, s16
 *   @0x2d097c vsub.f32 s15, s6, s15
 *   @0x2d0980 vmov s13, r0
 *   @0x2d0984 vmla.f32 s18, s15, s20
 *   @0x2d0988 vmul.f32 s17, s17, s20
 *   @0x2d098c vnmls.f32 s17, s15, s16
 *   @0x2d0990 vadd.f32 s29, s18, s25
 *   @0x2d0994 vsub.f32 s29, s29, s7
 *   @0x2d0998 vadd.f32 s30, s17, s26
 *   @0x2d099c vmul.f32 s15, s29, s29
 *   @0x2d09a0 vsub.f32 s30, s30, s8
 *   @0x2d09a4 vmla.f32 s15, s30, s30
 *   @0x2d09a8 vsub.f32 s19, s19, s9
 *   @0x2d09ac vmul.f32 s16, s19, s31
 *   @0x2d09b0 vmul.f32 s19, s19, s13
 *   @0x2d09b4 vsub.f32 s14, s10, s14
 *   @0x2d09b8 vsqrt.f32 s20, s15
 *   @0x2d09bc vnmls.f32 s16, s14, s13
 *   @0x2d09c0 vmla.f32 s19, s14, s31
 *   @0x2d09c4 vadd.f32 s28, s16, s24
 *   @0x2d09c8 vadd.f32 s27, s19, s23
 *   @0x2d09cc vcmp.f32 s20, s20
 *   @0x2d09d0 vsub.f32 s28, s28, s11
 *   @0x2d09d4 vmrs APSR_nzcv, fpscr
 *   @0x2d09d8 vsub.f32 s27, s27, s12
 *   @0x2d09dc bne 0x2d0b4c <_ZN13b2PulleyJoint24SolvePositionConstraintsERK12b2SolverData+0x278>
 *   @0x2d09e0 vmul.f32 s15, s27, s27
 *   @0x2d09e4 vmla.f32 s15, s28, s28
 *   @0x2d09e8 vsqrt.f32 s13, s15
 *   @0x2d09ec vcmp.f32 s13, s13
 *   @0x2d09f0 vmrs APSR_nzcv, fpscr
 *   @0x2d09f4 bne 0x2d0b5c <_ZN13b2PulleyJoint24SolvePositionConstraintsERK12b2SolverData+0x288>
 *   @0x2d09f8 vldr s15, [pc, #364]
 *   @0x2d09fc vcmpe.f32 s20, s15
 *   @0x2d0a00 vldr s6, [r4, #184]
 *   @0x2d0a04 vldr s7, [r4, #188]
 *   @0x2d0a08 vldr s8, [r4, #176]
 *   @0x2d0a0c vldr s9, [r4, #180]
 *   @0x2d0a10 ldr r2, [r4, #0x78]
 *   @0x2d0a14 vmrs APSR_nzcv, fpscr
 *   @0x2d0a18 vmovgt.f32 s15, #1.000000e+00
 *   @0x2d0a1c vldrle s29, [pc, #332]
 *   @0x2d0a20 ldr r3, [r4, #0x7c]
 *   @0x2d0a24 ldr r1, [r5, #0x18]
 *   @0x2d0a28 add r2, r2, r2, lsl #1
 *   @0x2d0a2c add r3, r3, r3, lsl #1
 *   @0x2d0a30 add r2, r1, r2, lsl #2
 *   @0x2d0a34 add r3, r1, r3, lsl #2
 *   @0x2d0a38 vdivgt.f32 s15, s15, s20
 *   @0x2d0a3c vmulgt.f32 s30, s15, s30
 *   @0x2d0a40 vmulgt.f32 s29, s15, s29
 *   @0x2d0a44 vldr s15, [pc, #288]
 *   @0x2d0a48 vcmpe.f32 s13, s15
 *   @0x2d0a4c vmovle.f32 s30, s29
 *   @0x2d0a50 vmrs APSR_nzcv, fpscr
 *   @0x2d0a54 vldrle s27, [pc, #276]
 *   @0x2d0a58 vmovgt.f32 s12, #1.000000e+00
 *   @0x2d0a5c vdivgt.f32 s12, s12, s13
 *   @0x2d0a60 vmulgt.f32 s28, s12, s28
 *   @0x2d0a64 vmovle.f32 s28, s27
 *   @0x2d0a68 vmul.f32 s10, s30, s18
 *   @0x2d0a6c vmulgt.f32 s27, s12, s27
 *   @0x2d0a70 vldr s12, [r4, #112]
 *   @0x2d0a74 vmul.f32 s11, s28, s19
 *   @0x2d0a78 vnmls.f32 s10, s29, s17
 *   @0x2d0a7c vnmls.f32 s11, s27, s16
 *   @0x2d0a80 vmul.f32 s15, s6, s10
 *   @0x2d0a84 vmul.f32 s14, s7, s11
 *   @0x2d0a88 vmov.f32 s5, s8
 *   @0x2d0a8c vmla.f32 s5, s15, s10
 *   @0x2d0a90 vmov.f32 s10, s9
 *   @0x2d0a94 vmla.f32 s10, s14, s11
 *   @0x2d0a98 vmul.f32 s11, s12, s12
 *   @0x2d0a9c vmov.f32 s15, s5
 *   @0x2d0aa0 vmla.f32 s15, s11, s10
 *   @0x2d0aa4 vcmpe.f32 s15, #0
 *   @0x2d0aa8 vmov.f32 s14, s10
 *   @0x2d0aac vmrs APSR_nzcv, fpscr
 *   @0x2d0ab0 vmovgt.f32 s14, #1.000000e+00
 *   @0x2d0ab4 vdivgt.f32 s15, s14, s15
 *   @0x2d0ab8 vldr s14, [r4, #108]
 *   @0x2d0abc vsub.f32 s14, s14, s20
 *   @0x2d0ac0 vmls.f32 s14, s12, s13
 *   @0x2d0ac4 vnmul.f32 s15, s15, s14
 *   @0x2d0ac8 vnmul.f32 s12, s12, s15
 *   @0x2d0acc vneg.f32 s15, s15
 *   @0x2d0ad0 vmul.f32 s28, s12, s28
 *   @0x2d0ad4 vmul.f32 s30, s15, s30
 *   @0x2d0ad8 vmul.f32 s29, s15, s29
 *   @0x2d0adc vmul.f32 s27, s12, s27
 *   @0x2d0ae0 vmul.f32 s19, s19, s28
 *   @0x2d0ae4 vmul.f32 s18, s18, s30
 *   @0x2d0ae8 vnmls.f32 s19, s16, s27
 *   @0x2d0aec vnmls.f32 s18, s17, s29
 *   @0x2d0af0 vmla.f32 s26, s8, s30
 *   @0x2d0af4 vmla.f32 s22, s6, s18
 *   @0x2d0af8 vstr s26, [r2]
 *   @0x2d0afc vmla.f32 s25, s8, s29
 *   @0x2d0b00 vstr s22, [r2, #8]
 *   @0x2d0b04 vmla.f32 s21, s7, s19
 *   @0x2d0b08 vstr s25, [r2, #4]
 *   @0x2d0b0c vmla.f32 s24, s9, s28
 *   @0x2d0b10 vstr s21, [r3, #8]
 *   @0x2d0b14 vmla.f32 s23, s9, s27
 *   @0x2d0b18 vstr s24, [r3]
 *   @0x2d0b1c vcmpe.f32 s14, #0
 *   @0x2d0b20 vstr s23, [r3, #4]
 *   @0x2d0b24 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d0b28 vmrs APSR_nzcv, fpscr
 *   @0x2d0b2c vnegle.f32 s13, s14
 *   @0x2d0b30 vmovgt.f32 s13, s14
 *   @0x2d0b34 vldr s14, [pc, #56]
 *   @0x2d0b38 vcmpe.f32 s13, s14
 *   @0x2d0b3c vmrs APSR_nzcv, fpscr
 *   @0x2d0b40 movpl r0, #0
 *   @0x2d0b44 movmi r0, #1
 *   @0x2d0b48 pop {r3, r4, r5, pc}
 *   @0x2d0b4c vmov r0, s15
 *   @0x2d0b50 bl 0xb6700 <sqrtf@plt>
 *   @0x2d0b54 vmov s20, r0
 *   @0x2d0b58 b 0x2d09e0 <_ZN13b2PulleyJoint24SolvePositionConstraintsERK12b2SolverData+0x10c>
 *   @0x2d0b5c vmov r0, s15
 *   @0x2d0b60 bl 0xb6700 <sqrtf@plt>
 *   @0x2d0b64 vmov s13, r0
 *   @0x2d0b68 b 0x2d09f8 <_ZN13b2PulleyJoint24SolvePositionConstraintsERK12b2SolverData+0x124>
 *   @0x2d0b6c stcllo p12, c12, [r12, #-816]
 *   @0x2d0b70 andeq r0, r0, r0
 *   @0x2d0b74 bllo 0xfebc67a4 <b2_toiTime+0xfffffffffe46d300>
 *
 * ══ §11/46 Code_Constant_Find(char const*, RValue*)  0xf1770  size 672  168 条（0xf1770..0xf1a10）
 * @func 0xf1770 0xf1a10  size 672  168 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Find(char const*) / Code_Constant_Find(char const*, RValue*)+0x48 / Sound_Find(char const*) / Object_Find(char const*) / Audio_Find(char const*) / Background_Find(char const*) / Path_Find(char const*) / Font_Find(char const*)
 * 字段偏移 top8: 0xc×6 / 0x8×4 / 0x4×2 / 0x1a4×2 / 0x-4×1 / 0x15c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1770 mov r2, #0
 *   @0xf1774 push {r3, r4, r5, r6, r7, lr}
 *   @0xf1778 mov r3, r2
 *   @0xf177c movt r2, #0xbff0
 *   @0xf1780 str r3, [r1, #0xc]
 *   @0xf1784 str r2, [r1, #0x4]
 *   @0xf1788 mov r4, r1
 *   @0xf178c str r3, [r1]
 *   @0xf1790 mov r5, r0
 *   @0xf1794 bl 0x1eef64 <_Z11Sprite_FindPKc>
 *   @0xf1798 cmp r0, #0
 *   @0xf179c blt 0xf17b8 <_Z18Code_Constant_FindPKcP6RValue+0x48>
 *   @0xf17a0 vmov s15, r0
 *   @0xf17a4 mov r0, #1
 *   @0xf17a8 vcvt.f64.s32 d7, s15
 *   @0xf17ac vmov r2, r3, d7
 *   @0xf17b0 stm r4, {r2, r3}
 *   @0xf17b4 pop {r3, r4, r5, r6, r7, pc}
 *   @0xf17b8 mov r0, r5
 *   @0xf17bc bl 0x21fc54 <_Z10Sound_FindPKc>
 *   @0xf17c0 cmp r0, #0
 *   @0xf17c4 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf17c8 mov r0, r5
 *   @0xf17cc bl 0x19edf4 <_Z11Object_FindPKc>
 *   @0xf17d0 cmp r0, #0
 *   @0xf17d4 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf17d8 mov r0, r5
 *   @0xf17dc bl 0x219794 <_Z10Audio_FindPKc>
 *   @0xf17e0 cmp r0, #0
 *   @0xf17e4 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf17e8 mov r0, r5
 *   @0xf17ec bl 0xc370c <_Z15Background_FindPKc>
 *   @0xf17f0 cmp r0, #0
 *   @0xf17f4 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf17f8 mov r0, r5
 *   @0xf17fc bl 0x1a80d4 <_Z9Path_FindPKc>
 *   @0xf1800 cmp r0, #0
 *   @0xf1804 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf1808 mov r0, r5
 *   @0xf180c bl 0xfa374 <_Z9Font_FindPKc>
 *   @0xf1810 cmp r0, #0
 *   @0xf1814 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf1818 mov r0, r5
 *   @0xf181c bl 0x1f2bcc <_Z13TimeLine_FindPKc>
 *   @0xf1820 cmp r0, #0
 *   @0xf1824 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf1828 mov r0, r5
 *   @0xf182c bl 0x1e0610 <_Z11Script_FindPKc>
 *   @0xf1830 cmp r0, #0
 *   @0xf1834 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf1838 mov r0, r5
 *   @0xf183c bl 0x1b524c <_Z9Room_FindPKc>
 *   @0xf1840 cmp r0, #0
 *   @0xf1844 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf1848 mov r0, r5
 *   @0xf184c bl 0x1e12dc <_Z11Shader_FindPKc>
 *   @0xf1850 cmp r0, #0
 *   @0xf1854 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30>
 *   @0xf1858 ldr r2, [pc, #0x1a4]
 *   @0xf185c ldr r3, [pc, #0x1a4]
 *   @0xf1860 ldr r2, [pc, r2]
 *   @0xf1864 ldr r3, [pc, r3]
 *   @0xf1868 ldr r2, [r2]
 *   @0xf186c ldr r7, [r3]
 *   @0xf1870 sub r6, r2, #1
 *   @0xf1874 add r7, r7, r2, lsl #2
 *   @0xf1878 cmp r6, #0
 *   @0xf187c mov r1, r5
 *   @0xf1880 blt 0xf189c <_Z18Code_Constant_FindPKcP6RValue+0x12c>
 *   @0xf1884 ldr r0, [r7, #-0x4]!
 *   @0xf1888 bl 0xb6574 <strcmp@plt>
 *   @0xf188c cmp r0, #0
 *   @0xf1890 beq 0xf18a4 <_Z18Code_Constant_FindPKcP6RValue+0x134>
 *   @0xf1894 sub r6, r6, #1
 *   @0xf1898 b 0xf1878 <_Z18Code_Constant_FindPKcP6RValue+0x108>
 *   @0xf189c mov r0, #0
 *   @0xf18a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xf18a4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0xf18a8 ldr r3, [pc, #0x15c]
 *   @0xf18ac ldr r2, [r4, #0xc]
 *   @0xf18b0 lsl r5, r6, #4
 *   @0xf18b4 ldr r3, [pc, r3]
 *   @0xf18b8 bic r1, r2, #-16777216
 *   @0xf18bc ldr r6, [r3]
 *   @0xf18c0 cmp r1, #1
 *   @0xf18c4 add r7, r6, r5
 *   @0xf18c8 beq 0xf1968 <_Z18Code_Constant_FindPKcP6RValue+0x1f8>
 *   @0xf18cc cmp r1, #2
 *   @0xf18d0 bne 0xf1900 <_Z18Code_Constant_FindPKcP6RValue+0x190>
 *   @0xf18d4 sub r3, r2, #1
 *   @0xf18d8 bic r3, r3, #-16777216
 *   @0xf18dc bic r3, r3, #3
 *   @0xf18e0 cmp r3, #0
 *   @0xf18e4 bne 0xf18f0 <_Z18Code_Constant_FindPKcP6RValue+0x180>
 *   @0xf18e8 mov r0, r4
 *   @0xf18ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xf18f0 mov r2, #0
 *   @0xf18f4 mov r3, #5
 *   @0xf18f8 str r2, [r4, #0x8]
 *   @0xf18fc str r3, [r4, #0xc]
 *   @0xf1900 ldr r3, [r7, #0xc]
 *   @0xf1904 mov r1, #0
 *   @0xf1908 ldr r2, [r7, #0x8]
 *   @0xf190c str r1, [r4]
 *   @0xf1910 str r3, [r4, #0xc]
 *   @0xf1914 ldr r3, [r7, #0xc]
 *   @0xf1918 str r2, [r4, #0x8]
 *   @0xf191c bic r3, r3, #-16777216
 *   @0xf1920 cmp r3, #14
 *   @0xf1924 addls pc, pc, r3, lsl #2
 *   @0xf1928 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf192c b 0xf19a4 <_Z18Code_Constant_FindPKcP6RValue+0x234>
 *   @0xf1930 b 0xf19ec <_Z18Code_Constant_FindPKcP6RValue+0x27c>
 *   @0xf1934 b 0xf19b4 <_Z18Code_Constant_FindPKcP6RValue+0x244>
 *   @0xf1938 b 0xf19e0 <_Z18Code_Constant_FindPKcP6RValue+0x270>
 *   @0xf193c b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf1940 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf1944 b 0xf1978 <_Z18Code_Constant_FindPKcP6RValue+0x208>
 *   @0xf1948 b 0xf19e0 <_Z18Code_Constant_FindPKcP6RValue+0x270>
 *   @0xf194c b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf1950 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf1954 b 0xf19a4 <_Z18Code_Constant_FindPKcP6RValue+0x234>
 *   @0xf1958 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf195c b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf1960 b 0xf19a4 <_Z18Code_Constant_FindPKcP6RValue+0x234>
 *   @0xf1964 b 0xf19e0 <_Z18Code_Constant_FindPKcP6RValue+0x270>
 *   @0xf1968 ldr r0, [r4]
 *   @0xf196c bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_>
 *   @0xf1970 str r0, [r4]
 *   @0xf1974 b 0xf1900 <_Z18Code_Constant_FindPKcP6RValue+0x190>
 *   @0xf1978 ldr r3, [r6, r5]
 *   @0xf197c str r3, [r4]
 *   @0xf1980 ldr r3, [r6, r5]
 *   @0xf1984 cmp r3, #0
 *   @0xf1988 beq 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf198c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xf1990 ldr r1, [r6, r5]
 *   @0xf1994 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xf1998 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0xf199c mov r0, #1
 *   @0xf19a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xf19a4 ldr r2, [r6, r5]
 *   @0xf19a8 ldr r3, [r7, #0x4]
 *   @0xf19ac stm r4, {r2, r3}
 *   @0xf19b0 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf19b4 ldr r3, [r6, r5]
 *   @0xf19b8 cmp r3, #0
 *   @0xf19bc str r3, [r4]
 *   @0xf19c0 beq 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf19c4 ldr r1, [r3, #0x8]
 *   @0xf19c8 ldr r2, [r3]
 *   @0xf19cc cmp r1, #0
 *   @0xf19d0 streq r4, [r3, #0x8]
 *   @0xf19d4 add r2, r2, #1
 *   @0xf19d8 str r2, [r3]
 *   @0xf19dc b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf19e0 ldr r3, [r6, r5]
 *   @0xf19e4 str r3, [r4]
 *   @0xf19e8 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228>
 *   @0xf19ec ldr r3, [r6, r5]
 *   @0xf19f0 cmp r3, #0
 *   @0xf19f4 ldrne r2, [r3, #0x4]
 *   @0xf19f8 addne r2, r2, #1
 *   @0xf19fc strne r2, [r3, #0x4]
 *   @0xf1a00 b 0xf19e4 <_Z18Code_Constant_FindPKcP6RValue+0x274>
 *   @0xf1a04 eoreq r12, pc, r4, ror #10
 *   @0xf1a08 eoreq r12, pc, r4, ror #10
 *   @0xf1a0c eoreq r12, pc, r8, lsl r5
 *
 * ══ §12/46 CSprite::ClearSWFData()  0x1e68b0  size 668  167 条（0x1e68b0..0x1e6b4c）
 * @func 0x1e68b0 0x1e6b4c  size 668  167 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×18 / CSprite::ClearSWFData()+0x1f0×2 / GR_Texture_Free(int)×2 / CSprite::ClearSWFData()+0x1bc / CSprite::ClearSWFData()+0x268
 * 字段偏移 top8: 0x4×12 / 0x8×5 / 0x84×4 / 0x7c×3 / 0x80×3 / 0xc×3 / 0x10×3 / 0x18×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e68b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e68b4 sub sp, sp, #12
 *   @0x1e68b8 str r0, [sp, #0x4]
 *   @0x1e68bc ldr r0, [r0, #0x7c]
 *   @0x1e68c0 cmp r0, #0
 *   @0x1e68c4 beq 0x1e6ab4 <_ZN7CSprite12ClearSWFDataEv+0x204>
 *   @0x1e68c8 ldr r2, [sp, #0x4]
 *   @0x1e68cc ldr r3, [r2, #0x80]
 *   @0x1e68d0 cmp r3, #0
 *   @0x1e68d4 ble 0x1e6aa0 <_ZN7CSprite12ClearSWFDataEv+0x1f0>
 *   @0x1e68d8 mov r11, #0
 *   @0x1e68dc b 0x1e6908 <_ZN7CSprite12ClearSWFDataEv+0x58>
 *   @0x1e68e0 cmp r3, #2
 *   @0x1e68e4 beq 0x1e6b40 <_ZN7CSprite12ClearSWFDataEv+0x290>
 *   @0x1e68e8 mov r0, r9
 *   @0x1e68ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e68f0 ldr r3, [sp, #0x4]
 *   @0x1e68f4 ldr r0, [r3, #0x7c]
 *   @0x1e68f8 ldr r3, [r3, #0x80]
 *   @0x1e68fc add r11, r11, #1
 *   @0x1e6900 cmp r3, r11
 *   @0x1e6904 ble 0x1e6aa0 <_ZN7CSprite12ClearSWFDataEv+0x1f0>
 *   @0x1e6908 ldr r9, [r0, r11, lsl #2]
 *   @0x1e690c cmp r9, #0
 *   @0x1e6910 beq 0x1e68fc <_ZN7CSprite12ClearSWFDataEv+0x4c>
 *   @0x1e6914 ldr r3, [r9]
 *   @0x1e6918 cmp r3, #1
 *   @0x1e691c bne 0x1e68e0 <_ZN7CSprite12ClearSWFDataEv+0x30>
 *   @0x1e6920 ldr r0, [r9, #0x8]
 *   @0x1e6924 cmp r0, #0
 *   @0x1e6928 beq 0x1e68e8 <_ZN7CSprite12ClearSWFDataEv+0x38>
 *   @0x1e692c ldr r3, [r9, #0x1c]
 *   @0x1e6930 cmp r3, #0
 *   @0x1e6934 movne r8, #0
 *   @0x1e6938 movne r10, r8
 *   @0x1e693c beq 0x1e6a98 <_ZN7CSprite12ClearSWFDataEv+0x1e8>
 *   @0x1e6940 ldr r4, [r0, r8]
 *   @0x1e6944 add r5, r0, r8
 *   @0x1e6948 cmp r4, #0
 *   @0x1e694c beq 0x1e69f8 <_ZN7CSprite12ClearSWFDataEv+0x148>
 *   @0x1e6950 ldr r3, [r5, #0xc]
 *   @0x1e6954 cmp r3, #0
 *   @0x1e6958 beq 0x1e69f0 <_ZN7CSprite12ClearSWFDataEv+0x140>
 *   @0x1e695c mov r6, #0
 *   @0x1e6960 mov r7, r6
 *   @0x1e6964 ldr r0, [r4, r6]
 *   @0x1e6968 add r4, r4, r6
 *   @0x1e696c cmp r0, #0
 *   @0x1e6970 beq 0x1e6978 <_ZN7CSprite12ClearSWFDataEv+0xc8>
 *   @0x1e6974 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6978 ldr r0, [r4, #0x4]
 *   @0x1e697c cmp r0, #0
 *   @0x1e6980 beq 0x1e6988 <_ZN7CSprite12ClearSWFDataEv+0xd8>
 *   @0x1e6984 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6988 ldr r0, [r4, #0x8]
 *   @0x1e698c cmp r0, #0
 *   @0x1e6990 beq 0x1e6998 <_ZN7CSprite12ClearSWFDataEv+0xe8>
 *   @0x1e6994 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6998 ldr r0, [r4, #0xc]
 *   @0x1e699c cmp r0, #0
 *   @0x1e69a0 beq 0x1e69a8 <_ZN7CSprite12ClearSWFDataEv+0xf8>
 *   @0x1e69a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e69a8 ldr r0, [r4, #0x10]
 *   @0x1e69ac cmp r0, #0
 *   @0x1e69b0 beq 0x1e69b8 <_ZN7CSprite12ClearSWFDataEv+0x108>
 *   @0x1e69b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e69b8 ldr r0, [r4, #0x14]
 *   @0x1e69bc cmp r0, #0
 *   @0x1e69c0 beq 0x1e69c8 <_ZN7CSprite12ClearSWFDataEv+0x118>
 *   @0x1e69c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e69c8 ldr r0, [r4, #0x18]
 *   @0x1e69cc cmp r0, #0
 *   @0x1e69d0 beq 0x1e69d8 <_ZN7CSprite12ClearSWFDataEv+0x128>
 *   @0x1e69d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e69d8 ldr r3, [r5, #0xc]
 *   @0x1e69dc add r7, r7, #1
 *   @0x1e69e0 add r6, r6, #84
 *   @0x1e69e4 ldr r4, [r5]
 *   @0x1e69e8 cmp r3, r7
 *   @0x1e69ec bhi 0x1e6964 <_ZN7CSprite12ClearSWFDataEv+0xb4>
 *   @0x1e69f0 mov r0, r4
 *   @0x1e69f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e69f8 ldr r0, [r5, #0x4]
 *   @0x1e69fc cmp r0, #0
 *   @0x1e6a00 beq 0x1e6a70 <_ZN7CSprite12ClearSWFDataEv+0x1c0>
 *   @0x1e6a04 ldr r3, [r5, #0x10]
 *   @0x1e6a08 cmp r3, #0
 *   @0x1e6a0c beq 0x1e6a6c <_ZN7CSprite12ClearSWFDataEv+0x1bc>
 *   @0x1e6a10 mov r4, #0
 *   @0x1e6a14 b 0x1e6a30 <_ZN7CSprite12ClearSWFDataEv+0x180>
 *   @0x1e6a18 mov r0, r6
 *   @0x1e6a1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6a20 ldr r3, [r5, #0x10]
 *   @0x1e6a24 ldr r0, [r5, #0x4]
 *   @0x1e6a28 cmp r3, r4
 *   @0x1e6a2c bls 0x1e6a6c <_ZN7CSprite12ClearSWFDataEv+0x1bc>
 *   @0x1e6a30 ldr r6, [r0, r4, lsl #2]
 *   @0x1e6a34 lsl r7, r4, #2
 *   @0x1e6a38 add r4, r4, #1
 *   @0x1e6a3c ldr r3, [r6]
 *   @0x1e6a40 cmp r3, #2
 *   @0x1e6a44 bne 0x1e6a18 <_ZN7CSprite12ClearSWFDataEv+0x168>
 *   @0x1e6a48 ldr r0, [r6, #0x50]
 *   @0x1e6a4c cmp r0, #0
 *   @0x1e6a50 beq 0x1e6a58 <_ZN7CSprite12ClearSWFDataEv+0x1a8>
 *   @0x1e6a54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6a58 ldr r0, [r6, #0x54]
 *   @0x1e6a5c bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0x1e6a60 ldr r3, [r5, #0x4]
 *   @0x1e6a64 ldr r6, [r3, r7]
 *   @0x1e6a68 b 0x1e6a18 <_ZN7CSprite12ClearSWFDataEv+0x168>
 *   @0x1e6a6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6a70 ldr r0, [r5, #0x8]
 *   @0x1e6a74 cmp r0, #0
 *   @0x1e6a78 beq 0x1e6a80 <_ZN7CSprite12ClearSWFDataEv+0x1d0>
 *   @0x1e6a7c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6a80 ldr r3, [r9, #0x1c]
 *   @0x1e6a84 add r10, r10, #1
 *   @0x1e6a88 add r8, r8, #24
 *   @0x1e6a8c ldr r0, [r9, #0x8]
 *   @0x1e6a90 cmp r3, r10
 *   @0x1e6a94 bhi 0x1e6940 <_ZN7CSprite12ClearSWFDataEv+0x90>
 *   @0x1e6a98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6a9c b 0x1e68e8 <_ZN7CSprite12ClearSWFDataEv+0x38>
 *   @0x1e6aa0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6aa4 ldr r2, [sp, #0x4]
 *   @0x1e6aa8 mov r3, #0
 *   @0x1e6aac str r3, [r2, #0x7c]
 *   @0x1e6ab0 str r3, [r2, #0x80]
 *   @0x1e6ab4 ldr r2, [sp, #0x4]
 *   @0x1e6ab8 ldr r3, [r2, #0x84]
 *   @0x1e6abc cmp r3, #0
 *   @0x1e6ac0 mov r0, r3
 *   @0x1e6ac4 beq 0x1e6b38 <_ZN7CSprite12ClearSWFDataEv+0x288>
 *   @0x1e6ac8 ldr r2, [r3]
 *   @0x1e6acc cmp r2, #0
 *   @0x1e6ad0 beq 0x1e6b28 <_ZN7CSprite12ClearSWFDataEv+0x278>
 *   @0x1e6ad4 ldr r1, [r3, #0x18]
 *   @0x1e6ad8 cmp r1, #0
 *   @0x1e6adc ble 0x1e6b18 <_ZN7CSprite12ClearSWFDataEv+0x268>
 *   @0x1e6ae0 mov r4, #0
 *   @0x1e6ae4 mov r5, r4
 *   @0x1e6ae8 ldr r0, [r2, r4]
 *   @0x1e6aec add r5, r5, #1
 *   @0x1e6af0 add r4, r4, #24
 *   @0x1e6af4 cmp r0, #0
 *   @0x1e6af8 beq 0x1e6b08 <_ZN7CSprite12ClearSWFDataEv+0x258>
 *   @0x1e6afc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6b00 ldr r2, [sp, #0x4]
 *   @0x1e6b04 ldr r3, [r2, #0x84]
 *   @0x1e6b08 ldr r2, [r3, #0x18]
 *   @0x1e6b0c cmp r2, r5
 *   @0x1e6b10 ldr r2, [r3]
 *   @0x1e6b14 bgt 0x1e6ae8 <_ZN7CSprite12ClearSWFDataEv+0x238>
 *   @0x1e6b18 mov r0, r2
 *   @0x1e6b1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6b20 ldr r3, [sp, #0x4]
 *   @0x1e6b24 ldr r0, [r3, #0x84]
 *   @0x1e6b28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6b2c ldr r2, [sp, #0x4]
 *   @0x1e6b30 mov r3, #0
 *   @0x1e6b34 str r3, [r2, #0x84]
 *   @0x1e6b38 add sp, sp, #12
 *   @0x1e6b3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e6b40 ldr r0, [r9, #0x8]
 *   @0x1e6b44 bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0x1e6b48 b 0x1e68e8 <_ZN7CSprite12ClearSWFDataEv+0x38>
 *
 * ══ §13/46 CDS_Grid::Clear(RValue*)  0x20c120  size 668  167 条（0x20c120..0x20c3bc）
 * @func 0x20c120 0x20c3bc  size 668  167 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / FREE_RValue__Pre(RValue*)×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CDS_Grid::Clear(RValue*)+0x138 / CDS_Grid::Clear(RValue*)+0x12c / CDS_Grid::Clear(RValue*)+0x28
 * 字段偏移 top8: 0x4×19 / 0x8×9 / 0xc×7
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20c120 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20c124 mov r5, r0
 *   @0x20c128 ldr r8, [r0, #0x4]
 *   @0x20c12c sub sp, sp, #12
 *   @0x20c130 mov r9, r1
 *   @0x20c134 cmp r8, #0
 *   @0x20c138 ble 0x20c258 <_ZN8CDS_Grid5ClearEP6RValue+0x138>
 *   @0x20c13c ldr r2, [r0, #0x8]
 *   @0x20c140 mov r10, #0
 *   @0x20c144 mov r11, r10
 *   @0x20c148 cmp r2, #0
 *   @0x20c14c ble 0x20c24c <_ZN8CDS_Grid5ClearEP6RValue+0x12c>
 *   @0x20c150 mov r4, #0
 *   @0x20c154 mla r8, r8, r4, r10
 *   @0x20c158 ldr r7, [r5]
 *   @0x20c15c add r6, r7, r8, lsl #4
 *   @0x20c160 ldr r2, [r6, #0xc]
 *   @0x20c164 sub r2, r2, #1
 *   @0x20c168 bic r2, r2, #-16777216
 *   @0x20c16c bic r2, r2, #3
 *   @0x20c170 cmp r2, #0
 *   @0x20c174 beq 0x20c310 <_ZN8CDS_Grid5ClearEP6RValue+0x1f0>
 *   @0x20c178 str r11, [r6, #0x8]
 *   @0x20c17c mov r3, #5
 *   @0x20c180 str r3, [r6, #0xc]
 *   @0x20c184 str r11, [r7, r8, lsl #4]
 *   @0x20c188 ldm r5, {r7, r8}
 *   @0x20c18c mla r8, r8, r4, r10
 *   @0x20c190 add r6, r7, r8, lsl #4
 *   @0x20c194 ldr r1, [r6, #0xc]
 *   @0x20c198 bic r2, r1, #-16777216
 *   @0x20c19c cmp r2, #1
 *   @0x20c1a0 beq 0x20c2d8 <_ZN8CDS_Grid5ClearEP6RValue+0x1b8>
 *   @0x20c1a4 cmp r2, #2
 *   @0x20c1a8 bne 0x20c1cc <_ZN8CDS_Grid5ClearEP6RValue+0xac>
 *   @0x20c1ac sub r1, r1, #1
 *   @0x20c1b0 bic r1, r1, #-16777216
 *   @0x20c1b4 bic r1, r1, #3
 *   @0x20c1b8 cmp r1, #0
 *   @0x20c1bc beq 0x20c3b0 <_ZN8CDS_Grid5ClearEP6RValue+0x290>
 *   @0x20c1c0 mov r3, #5
 *   @0x20c1c4 str r11, [r6, #0x8]
 *   @0x20c1c8 str r3, [r6, #0xc]
 *   @0x20c1cc ldr r2, [r9, #0xc]
 *   @0x20c1d0 ldr r1, [r9, #0x8]
 *   @0x20c1d4 str r11, [r7, r8, lsl #4]
 *   @0x20c1d8 str r2, [r6, #0xc]
 *   @0x20c1dc ldr r2, [r9, #0xc]
 *   @0x20c1e0 str r1, [r6, #0x8]
 *   @0x20c1e4 bic r2, r2, #-16777216
 *   @0x20c1e8 cmp r2, #14
 *   @0x20c1ec addls pc, pc, r2, lsl #2
 *   @0x20c1f0 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c1f4 b 0x20c260 <_ZN8CDS_Grid5ClearEP6RValue+0x140>
 *   @0x20c1f8 b 0x20c29c <_ZN8CDS_Grid5ClearEP6RValue+0x17c>
 *   @0x20c1fc b 0x20c270 <_ZN8CDS_Grid5ClearEP6RValue+0x150>
 *   @0x20c200 b 0x20c230 <_ZN8CDS_Grid5ClearEP6RValue+0x110>
 *   @0x20c204 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c208 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c20c b 0x20c2b4 <_ZN8CDS_Grid5ClearEP6RValue+0x194>
 *   @0x20c210 b 0x20c230 <_ZN8CDS_Grid5ClearEP6RValue+0x110>
 *   @0x20c214 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c218 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c21c b 0x20c260 <_ZN8CDS_Grid5ClearEP6RValue+0x140>
 *   @0x20c220 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c224 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c228 b 0x20c260 <_ZN8CDS_Grid5ClearEP6RValue+0x140>
 *   @0x20c22c b 0x20c230 <_ZN8CDS_Grid5ClearEP6RValue+0x110>
 *   @0x20c230 ldr r2, [r9]
 *   @0x20c234 str r2, [r7, r8, lsl #4]
 *   @0x20c238 ldr r2, [r5, #0x8]
 *   @0x20c23c add r4, r4, #1
 *   @0x20c240 ldr r8, [r5, #0x4]
 *   @0x20c244 cmp r2, r4
 *   @0x20c248 bgt 0x20c154 <_ZN8CDS_Grid5ClearEP6RValue+0x34>
 *   @0x20c24c add r10, r10, #1
 *   @0x20c250 cmp r10, r8
 *   @0x20c254 blt 0x20c148 <_ZN8CDS_Grid5ClearEP6RValue+0x28>
 *   @0x20c258 add sp, sp, #12
 *   @0x20c25c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20c260 ldm r9, {r1, r2}
 *   @0x20c264 str r1, [r7, r8, lsl #4]
 *   @0x20c268 str r2, [r6, #0x4]
 *   @0x20c26c b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c270 ldr r2, [r9]
 *   @0x20c274 cmp r2, #0
 *   @0x20c278 str r2, [r7, r8, lsl #4]
 *   @0x20c27c beq 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c280 ldr r0, [r2, #0x8]
 *   @0x20c284 ldr r1, [r2]
 *   @0x20c288 cmp r0, #0
 *   @0x20c28c streq r6, [r2, #0x8]
 *   @0x20c290 add r1, r1, #1
 *   @0x20c294 str r1, [r2]
 *   @0x20c298 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c29c ldr r2, [r9]
 *   @0x20c2a0 cmp r2, #0
 *   @0x20c2a4 ldrne r1, [r2, #0x4]
 *   @0x20c2a8 addne r1, r1, #1
 *   @0x20c2ac strne r1, [r2, #0x4]
 *   @0x20c2b0 b 0x20c234 <_ZN8CDS_Grid5ClearEP6RValue+0x114>
 *   @0x20c2b4 ldr r2, [r9]
 *   @0x20c2b8 str r2, [r7, r8, lsl #4]
 *   @0x20c2bc ldr r2, [r9]
 *   @0x20c2c0 cmp r2, #0
 *   @0x20c2c4 beq 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c2c8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20c2cc ldr r1, [r9]
 *   @0x20c2d0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20c2d4 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118>
 *   @0x20c2d8 ldr r2, [r7, r8, lsl #4]
 *   @0x20c2dc cmp r2, #0
 *   @0x20c2e0 beq 0x20c308 <_ZN8CDS_Grid5ClearEP6RValue+0x1e8>
 *   @0x20c2e4 str r2, [sp]
 *   @0x20c2e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20c2ec ldr r2, [sp]
 *   @0x20c2f0 ldr r1, [r2, #0x4]
 *   @0x20c2f4 sub r1, r1, #1
 *   @0x20c2f8 str r1, [r2, #0x4]
 *   @0x20c2fc cmp r1, #0
 *   @0x20c300 beq 0x20c31c <_ZN8CDS_Grid5ClearEP6RValue+0x1fc>
 *   @0x20c304 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20c308 str r11, [r7, r8, lsl #4]
 *   @0x20c30c b 0x20c1cc <_ZN8CDS_Grid5ClearEP6RValue+0xac>
 *   @0x20c310 mov r0, r6
 *   @0x20c314 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c318 b 0x20c178 <_ZN8CDS_Grid5ClearEP6RValue+0x58>
 *   @0x20c31c ldr r0, [r2]
 *   @0x20c320 str r1, [sp, #0x4]
 *   @0x20c324 str r2, [sp]
 *   @0x20c328 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20c32c ldr r2, [sp]
 *   @0x20c330 ldr r1, [sp, #0x4]
 *   @0x20c334 str r1, [r2]
 *   @0x20c338 str r1, [r2, #0x8]
 *   @0x20c33c str r2, [sp]
 *   @0x20c340 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20c344 ldr r2, [sp]
 *   @0x20c348 ldr r1, [r2, #0x4]
 *   @0x20c34c sub r1, r1, #1
 *   @0x20c350 str r1, [r2, #0x4]
 *   @0x20c354 cmp r1, #0
 *   @0x20c358 bne 0x20c398 <_ZN8CDS_Grid5ClearEP6RValue+0x278>
 *   @0x20c35c ldr r0, [r2]
 *   @0x20c360 str r1, [sp, #0x4]
 *   @0x20c364 str r2, [sp]
 *   @0x20c368 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20c36c ldr r2, [sp]
 *   @0x20c370 ldr r1, [sp, #0x4]
 *   @0x20c374 mov r0, r2
 *   @0x20c378 str r1, [r2]
 *   @0x20c37c str r1, [r2, #0x8]
 *   @0x20c380 str r2, [sp]
 *   @0x20c384 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20c388 ldr r2, [sp]
 *   @0x20c38c mov r0, r2
 *   @0x20c390 bl 0x27d1d0 <_ZdlPv>
 *   @0x20c394 ldr r2, [sp]
 *   @0x20c398 str r2, [sp]
 *   @0x20c39c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20c3a0 ldr r2, [sp]
 *   @0x20c3a4 mov r0, r2
 *   @0x20c3a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x20c3ac b 0x20c304 <_ZN8CDS_Grid5ClearEP6RValue+0x1e4>
 *   @0x20c3b0 mov r0, r6
 *   @0x20c3b4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c3b8 b 0x20c1c0 <_ZN8CDS_Grid5ClearEP6RValue+0xa0>
 *
 * ══ §14/46 CCamera::ExecuteScript(int)  0x170888  size 664  166 条（0x170888..0x170b20）
 * @func 0x170888 0x170b20  size 664  166 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1708a4→0x54290c, 0x1708b4→0x47f295, 0x1708d4→0x48f78c, 0x170920→0x544be0
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*)×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CCamera::ExecuteScript(int)+0x200 / CCamera::ExecuteScript(int)+0x190
 * 字段偏移 top8: 0x4×13 / 0x10×8 / 0x8×5 / 0xc×5 / 0x278×1 / 0x264×1 / 0x258×1 / 0x23c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170888 cmn r1, #1
 *   @0x17088c ldr r2, [pc, #0x278]
 *   @0x170890 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x170894 mov r12, r1
 *   @0x170898 sub sp, sp, #36
 *   @0x17089c add r2, pc, r2
 *   @0x1708a0 beq 0x170918 <_ZN7CCamera13ExecuteScriptEi+0x90>
 *   @0x1708a4 ldr r4, [pc, #0x264]
 *   @0x1708a8 mov r1, #0
 *   @0x1708ac ldr r0, [r0]
 *   @0x1708b0 str r1, [sp, #0x10]
 *   @0x1708b4 ldr r3, [pc, #0x258]
 *   @0x1708b8 ldr r5, [r2, r4]
 *   @0x1708bc ldr r7, [r5]
 *   @0x1708c0 str r0, [r5]
 *   @0x1708c4 ldr r3, [r2, r3]
 *   @0x1708c8 ldrb r3, [r3]
 *   @0x1708cc cmp r3, r1
 *   @0x1708d0 bne 0x170920 <_ZN7CCamera13ExecuteScriptEi+0x98>
 *   @0x1708d4 ldr r1, [pc, #0x23c]
 *   @0x1708d8 ldr r2, [r2, r1]
 *   @0x1708dc ldr r1, [r2, #0x8]
 *   @0x1708e0 cmp r1, #0
 *   @0x1708e4 beq 0x170900 <_ZN7CCamera13ExecuteScriptEi+0x78>
 *   @0x1708e8 mov r0, r12
 *   @0x1708ec str r3, [sp, #0x4]
 *   @0x1708f0 add r12, sp, #16
 *   @0x1708f4 mov r2, r1
 *   @0x1708f8 str r12, [sp]
 *   @0x1708fc bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x170900 ldr r2, [sp, #0x1c]
 *   @0x170904 sub r3, r2, #1
 *   @0x170908 bic r3, r3, #-16777216
 *   @0x17090c bics r4, r3, #3
 *   @0x170910 beq 0x17094c <_ZN7CCamera13ExecuteScriptEi+0xc4>
 *   @0x170914 str r7, [r5]
 *   @0x170918 add sp, sp, #36
 *   @0x17091c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x170920 ldr lr, [pc, #0x1f4]
 *   @0x170924 mov r3, r1
 *   @0x170928 mov r0, r12
 *   @0x17092c ldr r2, [r2, lr]
 *   @0x170930 str r1, [sp, #0x4]
 *   @0x170934 add r1, sp, #16
 *   @0x170938 str r1, [sp]
 *   @0x17093c ldr r1, [r2]
 *   @0x170940 mov r2, r1
 *   @0x170944 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x170948 b 0x170900 <_ZN7CCamera13ExecuteScriptEi+0x78>
 *   @0x17094c bic r2, r2, #-16777216
 *   @0x170950 cmp r2, #2
 *   @0x170954 beq 0x170994 <_ZN7CCamera13ExecuteScriptEi+0x10c>
 *   @0x170958 cmp r2, #3
 *   @0x17095c beq 0x170a3c <_ZN7CCamera13ExecuteScriptEi+0x1b4>
 *   @0x170960 cmp r2, #1
 *   @0x170964 bne 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c>
 *   @0x170968 ldr r4, [sp, #0x10]
 *   @0x17096c cmp r4, #0
 *   @0x170970 beq 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c>
 *   @0x170974 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x170978 ldr r6, [r4, #0x4]
 *   @0x17097c sub r6, r6, #1
 *   @0x170980 str r6, [r4, #0x4]
 *   @0x170984 cmp r6, #0
 *   @0x170988 beq 0x170aa8 <_ZN7CCamera13ExecuteScriptEi+0x220>
 *   @0x17098c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x170990 b 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c>
 *   @0x170994 ldr r9, [sp, #0x10]
 *   @0x170998 cmp r9, #0
 *   @0x17099c beq 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c>
 *   @0x1709a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1709a4 ldr r3, [r9]
 *   @0x1709a8 ldr r1, [r9, #0x8]
 *   @0x1709ac add r2, sp, #16
 *   @0x1709b0 sub r3, r3, #1
 *   @0x1709b4 str r3, [r9]
 *   @0x1709b8 cmp r1, r2
 *   @0x1709bc streq r4, [r9, #0x8]
 *   @0x1709c0 cmp r3, #0
 *   @0x1709c4 bgt 0x17098c <_ZN7CCamera13ExecuteScriptEi+0x104>
 *   @0x1709c8 ldr r3, [r9, #0x10]
 *   @0x1709cc cmp r3, #0
 *   @0x1709d0 movgt r8, #0
 *   @0x1709d4 movgt r10, #5
 *   @0x1709d8 movgt r6, r8
 *   @0x1709dc ble 0x170a88 <_ZN7CCamera13ExecuteScriptEi+0x200>
 *   @0x1709e0 ldr r3, [r9, #0x4]
 *   @0x1709e4 add r2, r3, r8, lsl #3
 *   @0x1709e8 str r2, [sp, #0xc]
 *   @0x1709ec ldr r11, [r3, r8, lsl #3]
 *   @0x1709f0 ldr r4, [r2, #0x4]
 *   @0x1709f4 add r11, r4, r11, lsl #4
 *   @0x1709f8 cmp r4, r11
 *   @0x1709fc blo 0x170a18 <_ZN7CCamera13ExecuteScriptEi+0x190>
 *   @0x170a00 b 0x170ae0 <_ZN7CCamera13ExecuteScriptEi+0x258>
 *   @0x170a04 str r6, [r4, #0x8]
 *   @0x170a08 str r10, [r4, #0xc]
 *   @0x170a0c str r6, [r4], #16
 *   @0x170a10 cmp r11, r4
 *   @0x170a14 bls 0x170a64 <_ZN7CCamera13ExecuteScriptEi+0x1dc>
 *   @0x170a18 ldr r3, [r4, #0xc]
 *   @0x170a1c sub r3, r3, #1
 *   @0x170a20 bic r3, r3, #-16777216
 *   @0x170a24 bic r3, r3, #3
 *   @0x170a28 cmp r3, #0
 *   @0x170a2c bne 0x170a04 <_ZN7CCamera13ExecuteScriptEi+0x17c>
 *   @0x170a30 mov r0, r4
 *   @0x170a34 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x170a38 b 0x170a04 <_ZN7CCamera13ExecuteScriptEi+0x17c>
 *   @0x170a3c ldr r3, [sp, #0x18]
 *   @0x170a40 tst r3, #8
 *   @0x170a44 beq 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c>
 *   @0x170a48 ldr r0, [sp, #0x10]
 *   @0x170a4c cmp r0, #0
 *   @0x170a50 beq 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c>
 *   @0x170a54 ldr r3, [r0]
 *   @0x170a58 ldr r3, [r3, #0x4]
 *   @0x170a5c blx r3
 *   @0x170a60 b 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c>
 *   @0x170a64 ldr r3, [sp, #0xc]
 *   @0x170a68 ldr r0, [r3, #0x4]
 *   @0x170a6c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x170a70 ldr r3, [r9, #0x10]
 *   @0x170a74 add r8, r8, #1
 *   @0x170a78 ldr r2, [sp, #0xc]
 *   @0x170a7c cmp r8, r3
 *   @0x170a80 str r6, [r2, #0x4]
 *   @0x170a84 blt 0x1709e0 <_ZN7CCamera13ExecuteScriptEi+0x158>
 *   @0x170a88 ldr r0, [r9, #0x4]
 *   @0x170a8c mov r4, #0
 *   @0x170a90 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x170a94 str r4, [r9, #0x4]
 *   @0x170a98 mov r0, r9
 *   @0x170a9c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x170aa0 str r4, [sp, #0x10]
 *   @0x170aa4 b 0x17098c <_ZN7CCamera13ExecuteScriptEi+0x104>
 *   @0x170aa8 ldr r0, [r4]
 *   @0x170aac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x170ab0 str r6, [r4]
 *   @0x170ab4 str r6, [r4, #0x8]
 *   @0x170ab8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x170abc ldr r6, [r4, #0x4]
 *   @0x170ac0 sub r6, r6, #1
 *   @0x170ac4 str r6, [r4, #0x4]
 *   @0x170ac8 cmp r6, #0
 *   @0x170acc beq 0x170ae8 <_ZN7CCamera13ExecuteScriptEi+0x260>
 *   @0x170ad0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x170ad4 mov r0, r4
 *   @0x170ad8 bl 0x27d1d0 <_ZdlPv>
 *   @0x170adc b 0x17098c <_ZN7CCamera13ExecuteScriptEi+0x104>
 *   @0x170ae0 mov r0, r4
 *   @0x170ae4 b 0x170a6c <_ZN7CCamera13ExecuteScriptEi+0x1e4>
 *   @0x170ae8 ldr r0, [r4]
 *   @0x170aec bl 0xcef90 <_Z6YYFreePKv>
 *   @0x170af0 mov r0, r4
 *   @0x170af4 str r6, [r4]
 *   @0x170af8 str r6, [r4, #0x8]
 *   @0x170afc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x170b00 mov r0, r4
 *   @0x170b04 bl 0x27d1d0 <_ZdlPv>
 *   @0x170b08 b 0x170ad0 <_ZN7CCamera13ExecuteScriptEi+0x248>
 *   @0x170b0c .word 0x002813b4
 *   @0x170b10 .word 0xffffc168
 *   @0x170b14 .word 0xffffbf68
 *   @0x170b18 .word 0xffffc024
 *   @0x170b1c .word 0xffffbf64
 *
 * ══ §15/46 GR_Surface_Create_Special(int, int, int, int)  0x171228  size 664  166 条（0x171228..0x1714c0）
 * @func 0x171228 0x1714c0  size 664  166 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Create_Special(int, int, int, int)+0xe0 / GR_Texture_Create_Empty(int, int, bool, bool, int) / GR_Surface_Create_Special(int, int, int, int)+0x1c8 / GR_Surface_Get(int) / operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×10 / 0xc×7 / 0x4×6 / 0x3×3 / 0x1b8×2 / 0x1a0×2 / 0x150×2 / 0x264×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17122c cmp r2, #0
 *   @0x171230 ldr r5, [pc, #0x264]
 *   @0x171234 sub sp, sp, #20
 *   @0x171238 mov r9, r0
 *   @0x17123c mov r8, r1
 *   @0x171240 mov r10, r3
 *   @0x171244 add r5, pc, r5
 *   @0x171248 blt 0x171308 <_Z25GR_Surface_Create_Specialiiii+0xe0>
 *   @0x17124c ldr r3, [pc, #0x24c]
 *   @0x171250 ldr r7, [r5, r3]
 *   @0x171254 ldr r1, [r7, #0x4]
 *   @0x171258 ldr r3, [r7]
 *   @0x17125c and r1, r2, r1
 *   @0x171260 ldr r3, [r3, r1, lsl #3]
 *   @0x171264 cmp r3, #0
 *   @0x171268 bne 0x17127c <_Z25GR_Surface_Create_Specialiiii+0x54>
 *   @0x17126c b 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4>
 *   @0x171270 ldr r3, [r3, #0x4]
 *   @0x171274 cmp r3, #0
 *   @0x171278 beq 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4>
 *   @0x17127c ldr r1, [r3, #0x8]
 *   @0x171280 cmp r2, r1
 *   @0x171284 bne 0x171270 <_Z25GR_Surface_Create_Specialiiii+0x48>
 *   @0x171288 ldr r4, [r3, #0xc]
 *   @0x17128c cmp r4, #0
 *   @0x171290 beq 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4>
 *   @0x171294 mov r2, #1
 *   @0x171298 str r10, [sp]
 *   @0x17129c mov r3, r2
 *   @0x1712a0 mov r0, r9
 *   @0x1712a4 mov r1, r8
 *   @0x1712a8 bl 0x173a24 <_Z23GR_Texture_Create_Emptyiibbi>
 *   @0x1712ac ldr r3, [pc, #0x1f0]
 *   @0x1712b0 cmp r0, #0
 *   @0x1712b4 blt 0x1713f0 <_Z25GR_Surface_Create_Specialiiii+0x1c8>
 *   @0x1712b8 stmib r4, {r0, r9}
 *   @0x1712bc str r8, [r4, #0xc]
 *   @0x1712c0 ldr r3, [r5, r3]
 *   @0x1712c4 ldr r0, [r4]
 *   @0x1712c8 ldr r3, [r3]
 *   @0x1712cc cmp r0, r3
 *   @0x1712d0 beq 0x1712e8 <_Z25GR_Surface_Create_Specialiiii+0xc0>
 *   @0x1712d4 add sp, sp, #20
 *   @0x1712d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1712dc mvn r0, #0
 *   @0x1712e0 add sp, sp, #20
 *   @0x1712e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1712e8 ldr r2, [pc, #0x1b8]
 *   @0x1712ec ldr r3, [pc, #0x1b8]
 *   @0x1712f0 ldr r2, [r5, r2]
 *   @0x1712f4 str r9, [r2]
 *   @0x1712f8 ldr r3, [r5, r3]
 *   @0x1712fc str r8, [r3]
 *   @0x171300 add sp, sp, #20
 *   @0x171304 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x171308 ldr r3, [pc, #0x1a0]
 *   @0x17130c ldr r4, [pc, #0x1a0]
 *   @0x171310 add r3, pc, r3
 *   @0x171314 add r4, pc, r4
 *   @0x171318 ldr r0, [r3]
 *   @0x17131c b 0x17132c <_Z25GR_Surface_Create_Specialiiii+0x104>
 *   @0x171320 ldr r0, [r4]
 *   @0x171324 add r0, r0, #1
 *   @0x171328 str r0, [r4]
 *   @0x17132c bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x171330 cmp r0, #0
 *   @0x171334 bne 0x171320 <_Z25GR_Surface_Create_Specialiiii+0xf8>
 *   @0x171338 mov r6, r0
 *   @0x17133c mov r0, #16
 *   @0x171340 bl 0x27c524 <_Znwj>
 *   @0x171344 ldr r1, [pc, #0x16c]
 *   @0x171348 ldr r12, [pc, #0x150]
 *   @0x17134c mov r3, #1
 *   @0x171350 add r1, pc, r1
 *   @0x171354 movw r2, #0x132
 *   @0x171358 ldr r11, [r1]
 *   @0x17135c add lr, r11, r3
 *   @0x171360 str lr, [r1]
 *   @0x171364 ldr r1, [pc, #0x150]
 *   @0x171368 add r1, pc, r1
 *   @0x17136c mov r4, r0
 *   @0x171370 mov r0, #16
 *   @0x171374 str r6, [r4, #0x4]
 *   @0x171378 str r6, [r4, #0x8]
 *   @0x17137c str r6, [r4, #0xc]
 *   @0x171380 str r11, [r4]
 *   @0x171384 ldr r7, [r5, r12]
 *   @0x171388 ldr lr, [r7]
 *   @0x17138c ldr r12, [r7, #0x4]
 *   @0x171390 str lr, [sp, #0xc]
 *   @0x171394 and r12, r11, r12
 *   @0x171398 str r12, [sp, #0x8]
 *   @0x17139c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1713a0 ldr r12, [sp, #0x8]
 *   @0x1713a4 ldr r1, [sp, #0xc]
 *   @0x1713a8 add r3, r1, r12, lsl #3
 *   @0x1713ac ldr r2, [r1, r12, lsl #3]
 *   @0x1713b0 cmp r2, #0
 *   @0x1713b4 ldrne r2, [r3, #0x4]
 *   @0x1713b8 str r11, [r0, #0x8]
 *   @0x1713bc str r4, [r0, #0xc]
 *   @0x1713c0 strne r2, [r0]
 *   @0x1713c4 streq r0, [r3, #0x4]
 *   @0x1713c8 strne r0, [r2, #0x4]
 *   @0x1713cc strne r0, [r3, #0x4]
 *   @0x1713d0 ldr r3, [r7, #0x8]
 *   @0x1713d4 streq r0, [r1, r12, lsl #3]
 *   @0x1713d8 strne r6, [r0, #0x4]
 *   @0x1713dc add r3, r3, #1
 *   @0x1713e0 streq r2, [r0, #0x4]
 *   @0x1713e4 streq r2, [r0]
 *   @0x1713e8 str r3, [r7, #0x8]
 *   @0x1713ec b 0x171294 <_Z25GR_Surface_Create_Specialiiii+0x6c>
 *   @0x1713f0 ldr r3, [r5, r3]
 *   @0x1713f4 ldr r2, [r4]
 *   @0x1713f8 ldr r3, [r3]
 *   @0x1713fc cmp r2, r3
 *   @0x171400 bne 0x171420 <_Z25GR_Surface_Create_Specialiiii+0x1f8>
 *   @0x171404 ldr r0, [pc, #0x9c]
 *   @0x171408 mov r3, #1
 *   @0x17140c ldr r1, [pc, #0x98]
 *   @0x171410 ldr r0, [r5, r0]
 *   @0x171414 str r3, [r0]
 *   @0x171418 ldr r1, [r5, r1]
 *   @0x17141c str r3, [r1]
 *   @0x171420 ldr r0, [r7, #0x4]
 *   @0x171424 ldr r1, [r7]
 *   @0x171428 and r0, r2, r0
 *   @0x17142c ldr r4, [r1, r0, lsl #3]
 *   @0x171430 add r12, r1, r0, lsl #3
 *   @0x171434 cmp r4, #0
 *   @0x171438 bne 0x17144c <_Z25GR_Surface_Create_Specialiiii+0x224>
 *   @0x17143c b 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4>
 *   @0x171440 ldr r4, [r4, #0x4]
 *   @0x171444 cmp r4, #0
 *   @0x171448 beq 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4>
 *   @0x17144c ldr r3, [r4, #0x8]
 *   @0x171450 cmp r2, r3
 *   @0x171454 bne 0x171440 <_Z25GR_Surface_Create_Specialiiii+0x218>
 *   @0x171458 ldm r4, {r2, r3}
 *   @0x17145c cmp r2, #0
 *   @0x171460 strne r3, [r2, #0x4]
 *   @0x171464 ldrne r3, [r4, #0x4]
 *   @0x171468 streq r3, [r1, r0, lsl #3]
 *   @0x17146c cmp r3, #0
 *   @0x171470 ldr r0, [r4, #0xc]
 *   @0x171474 strne r2, [r3]
 *   @0x171478 streq r2, [r12, #0x4]
 *   @0x17147c bl 0x27d1d0 <_ZdlPv>
 *   @0x171480 mov r0, r4
 *   @0x171484 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x171488 ldr r3, [r7, #0x8]
 *   @0x17148c mvn r0, #0
 *   @0x171490 add r3, r3, r0
 *   @0x171494 str r3, [r7, #0x8]
 *   @0x171498 b 0x1712d4 <_Z25GR_Surface_Create_Specialiiii+0xac>
 *   @0x17149c eoreq r0, r8, r12, lsl #20
 *   @0x1714a0 .word 0xffffbec0
 *   @0x1714a4 .word 0xffffc988
 *   @0x1714a8 .word 0xffffdf38
 *   @0x1714ac .word 0xffffdf40
 *   @0x1714b0 mlaseq r1, r0, r4, lr
 *   @0x1714b4 eorseq lr, r1, r12, lsl #9
 *   @0x1714b8 eorseq lr, r1, r0, asr r4
 *   @0x1714bc andseq r10, sp, r12, lsr r0
 *
 * ══ §16/46 YYObject_PropertyNameIterator::NextInternal(RValue*, RValue*)  0x240134  size 664  166 条（0x240134..0x2403cc）
 * @func 0x240134 0x2403cc  size 664  166 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×4 / YYCreateString(RValue*, char const*)×3 / YYObject_PropertyNameIterator::NextInternal(RValue*, RValue*)+0x68×2 / YYObject_PropertyNameIterator::NextInternal(RValue*, RValue*)+0x184 / YYObject_PropertyNameIterator::NextInternal(RValue*, RValue*)+0x174 / YYObject_PropertyNameIterator::NextInternal(RValue*, RValue*)+0xd0 / Code_Variable_Find_Name(char const*, int, int) / YYObject_PropertyNameIterator::NextInternal(RValue*, RValue*)+0x164
 * 字段偏移 top8: 0x8×12 / 0x4×11 / 0xc×5 / 0x24×3 / 0x44×2 / 0x278×1 / 0x21c×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240134 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x240138 sub sp, sp, #76
 *   @0x24013c ldr r4, [pc, #0x278]
 *   @0x240140 mov r5, r0
 *   @0x240144 ldr r12, [r0, #0x4]
 *   @0x240148 mov r7, r1
 *   @0x24014c ldr r4, [pc, r4]
 *   @0x240150 mov r6, r2
 *   @0x240154 cmp r12, #0
 *   @0x240158 ldr r3, [r4]
 *   @0x24015c str r3, [sp, #0x44]
 *   @0x240160 beq 0x2401d8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xa4>
 *   @0x240164 cmp r12, #1
 *   @0x240168 bne 0x2401bc <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x88>
 *   @0x24016c ldr r0, [r0]
 *   @0x240170 ldr r3, [r0, #0x24]
 *   @0x240174 cmp r3, #1
 *   @0x240178 bls 0x24019c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x68>
 *   @0x24017c ldr r3, [r0, #0x4]
 *   @0x240180 cmp r3, #0
 *   @0x240184 beq 0x240388 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x254>
 *   @0x240188 add r0, r3, #16
 *   @0x24018c ldr r3, [r0, #0xc]
 *   @0x240190 bic r3, r3, #-16777216
 *   @0x240194 cmp r3, #6
 *   @0x240198 beq 0x2402c8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x194>
 *   @0x24019c ldr r1, [pc, #0x21c]
 *   @0x2401a0 mov r0, r7
 *   @0x2401a4 add r1, pc, r1
 *   @0x2401a8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2401ac mov r3, #2
 *   @0x2401b0 mov r0, #1
 *   @0x2401b4 str r3, [r5, #0x4]
 *   @0x2401b8 b 0x2401c0 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x8c>
 *   @0x2401bc mov r0, #0
 *   @0x2401c0 ldr r2, [sp, #0x44]
 *   @0x2401c4 ldr r3, [r4]
 *   @0x2401c8 cmp r2, r3
 *   @0x2401cc bne 0x2403b8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x284>
 *   @0x2401d0 add sp, sp, #76
 *   @0x2401d4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2401d8 ldr r3, [r0]
 *   @0x2401dc ldr r2, [r0, #0x8]
 *   @0x2401e0 ldr r3, [r3, #0x60]
 *   @0x2401e4 cmp r2, #0
 *   @0x2401e8 ldr r8, [r3, #0x4]
 *   @0x2401ec blt 0x2402b8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x184>
 *   @0x2401f0 cmp r8, r2
 *   @0x2401f4 blt 0x2402a8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x174>
 *   @0x2401f8 ldr r3, [r3, #0x10]
 *   @0x2401fc b 0x240208 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xd4>
 *   @0x240200 add r12, r12, #1
 *   @0x240204 add r3, r3, #12
 *   @0x240208 ldr lr, [r3, #0x8]
 *   @0x24020c cmp lr, #0
 *   @0x240210 ble 0x240204 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xd0>
 *   @0x240214 cmp r2, r12
 *   @0x240218 bne 0x240200 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xcc>
 *   @0x24021c ldr r2, [r3]
 *   @0x240220 add r9, r3, #4
 *   @0x240224 add r2, r2, #99328
 *   @0x240228 add r2, r2, #672
 *   @0x24022c ldr r0, [pc, #0x190]
 *   @0x240230 mvn r1, #8
 *   @0x240234 add r0, pc, r0
 *   @0x240238 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii>
 *   @0x24023c ldr r3, [r9]
 *   @0x240240 ldr r12, [r3]
 *   @0x240244 ldr r2, [r3, #0x8]
 *   @0x240248 mov r1, r0
 *   @0x24024c ldr r0, [r3, #0x4]
 *   @0x240250 ldr r3, [r3, #0xc]
 *   @0x240254 str r12, [r6]
 *   @0x240258 str r0, [r6, #0x4]
 *   @0x24025c str r2, [r6, #0x8]
 *   @0x240260 str r3, [r6, #0xc]
 *   @0x240264 ldr r3, [r5, #0x8]
 *   @0x240268 add r3, r3, #1
 *   @0x24026c str r3, [r5, #0x8]
 *   @0x240270 cmp r3, r8
 *   @0x240274 blo 0x240298 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x164>
 *   @0x240278 ldr r3, [r5]
 *   @0x24027c ldr r3, [r3, #0x24]
 *   @0x240280 cmp r3, #1
 *   @0x240284 movhi r2, #1
 *   @0x240288 movhi r3, #0
 *   @0x24028c movls r3, #2
 *   @0x240290 stmibhi r5, {r2, r3}
 *   @0x240294 strls r3, [r5, #0x4]
 *   @0x240298 mov r0, r7
 *   @0x24029c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2402a0 mov r0, #1
 *   @0x2402a4 b 0x2401c0 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x8c>
 *   @0x2402a8 movw r2, #0x869f
 *   @0x2402ac mov r9, r12
 *   @0x2402b0 movt r2, #0x1
 *   @0x2402b4 b 0x24022c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xf8>
 *   @0x2402b8 movw r2, #0x869f
 *   @0x2402bc mov r9, r12
 *   @0x2402c0 movt r2, #0x1
 *   @0x2402c4 b 0x24022c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xf8>
 *   @0x2402c8 ldr r0, [r5]
 *   @0x2402cc ldr r3, [r0, #0x4]
 *   @0x2402d0 cmp r3, #0
 *   @0x2402d4 beq 0x240394 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x260>
 *   @0x2402d8 add r0, r3, #16
 *   @0x2402dc ldr r3, [r0]
 *   @0x2402e0 ldr r8, [r3, #0x24]
 *   @0x2402e4 cmp r8, #0
 *   @0x2402e8 ble 0x24019c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x68>
 *   @0x2402ec add r9, sp, #4
 *   @0x2402f0 ldr r2, [pc, #0xd0]
 *   @0x2402f4 ldr r3, [r5, #0x8]
 *   @0x2402f8 mov r1, #64
 *   @0x2402fc add r2, pc, r2
 *   @0x240300 mov r0, r9
 *   @0x240304 bl 0xb65c8 <snprintf@plt>
 *   @0x240308 ldr r0, [r5]
 *   @0x24030c mov r3, #0
 *   @0x240310 strb r3, [sp, #0x43]
 *   @0x240314 ldr r3, [r0, #0x4]
 *   @0x240318 cmp r3, #0
 *   @0x24031c beq 0x2403ac <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x278>
 *   @0x240320 add r0, r3, #16
 *   @0x240324 ldr r0, [r0]
 *   @0x240328 ldr r1, [r5, #0x8]
 *   @0x24032c ldr r3, [r0, #0x4]
 *   @0x240330 cmp r3, #0
 *   @0x240334 beq 0x2403a0 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x26c>
 *   @0x240338 add r3, r3, r1, lsl #4
 *   @0x24033c ldr r0, [r3]
 *   @0x240340 ldr r1, [r3, #0x4]
 *   @0x240344 ldr r2, [r3, #0x8]
 *   @0x240348 ldr r3, [r3, #0xc]
 *   @0x24034c str r0, [r6]
 *   @0x240350 mov r0, r7
 *   @0x240354 str r1, [r6, #0x4]
 *   @0x240358 mov r1, r9
 *   @0x24035c str r2, [r6, #0x8]
 *   @0x240360 str r3, [r6, #0xc]
 *   @0x240364 ldr r3, [r5, #0x8]
 *   @0x240368 add r3, r3, #1
 *   @0x24036c str r3, [r5, #0x8]
 *   @0x240370 cmp r8, r3
 *   @0x240374 movle r3, #2
 *   @0x240378 strle r3, [r5, #0x4]
 *   @0x24037c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x240380 mov r0, #1
 *   @0x240384 b 0x2401c0 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x8c>
 *   @0x240388 mov r1, r12
 *   @0x24038c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240390 b 0x24018c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x58>
 *   @0x240394 mov r1, #1
 *   @0x240398 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24039c b 0x2402dc <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x1a8>
 *   @0x2403a0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2403a4 mov r3, r0
 *   @0x2403a8 b 0x24033c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x208>
 *   @0x2403ac mov r1, #1
 *   @0x2403b0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2403b4 b 0x240324 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x1f0>
 *   @0x2403b8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2403bc andseq sp, r10, r4, lsl #16
 *   @0x2403c0 muleq lr, r2, r9
 *   @0x2403c4 andeq lr, lr, r2, lsl #18
 *   @0x2403c8 andeq r2, pc, r0, lsl r2
 *
 * ══ §17/46 F_DsMapAdd_Internal(int, double, double)  0x105638  size 660  165 条（0x105638..0x1058cc）
 * @func 0x105638 0x1058e0  size 680  170 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / UNLOCK_RVALUE_MUTEX()×2 / FREE_RValue__Pre(RValue*)×2 / YYFree(void const*)×2 / operator delete(void*)×2 / DS_AutoMutex::DS_AutoMutex() / CDS_Map::Add(RValue*, RValue*)
 * 字段偏移 top8: 0x4×15 / 0x10×8 / 0x8×4 / 0x1c×3 / 0x2c×3 / 0x18×2 / 0xc×2 / 0x264×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x105638 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10563c sub sp, sp, #52
 *   @0x105640 add r8, sp, #12
 *   @0x105644 mov r11, r0
 *   @0x105648 mov r4, r2
 *   @0x10564c mov r5, r3
 *   @0x105650 mov r0, r8
 *   @0x105654 ldrd r6, r7, [sp, #88]
 *   @0x105658 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x10565c ldr r3, [pc, #0x264]
 *   @0x105660 add r10, sp, #16
 *   @0x105664 add r9, sp, #32
 *   @0x105668 ldr r3, [pc, r3]
 *   @0x10566c strd r6, r7, [sp, #32]
 *   @0x105670 strd r4, r5, [sp, #16]
 *   @0x105674 mov r1, r10
 *   @0x105678 ldr r0, [r3, #0x4]
 *   @0x10567c mov r2, r9
 *   @0x105680 mov r3, #0
 *   @0x105684 str r3, [sp, #0x1c]
 *   @0x105688 str r3, [sp, #0x2c]
 *   @0x10568c ldr r0, [r0, r11, lsl #2]
 *   @0x105690 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x105694 ldr r3, [sp, #0x2c]
 *   @0x105698 sub r3, r3, #1
 *   @0x10569c bic r3, r3, #-16777216
 *   @0x1056a0 bic r3, r3, #3
 *   @0x1056a4 cmp r3, #0
 *   @0x1056a8 mov r6, r0
 *   @0x1056ac beq 0x105748 <_Z19F_DsMapAdd_Internalidd+0x110>
 *   @0x1056b0 ldr r1, [sp, #0x1c]
 *   @0x1056b4 mov r2, #0
 *   @0x1056b8 mov r0, #5
 *   @0x1056bc str r2, [sp, #0x28]
 *   @0x1056c0 sub r3, r1, #1
 *   @0x1056c4 str r2, [sp, #0x20]
 *   @0x1056c8 bic r3, r3, #-16777216
 *   @0x1056cc str r0, [sp, #0x2c]
 *   @0x1056d0 bics r4, r3, #3
 *   @0x1056d4 beq 0x105700 <_Z19F_DsMapAdd_Internalidd+0xc8>
 *   @0x1056d8 mov r0, r8
 *   @0x1056dc mov r3, #0
 *   @0x1056e0 mov r2, #5
 *   @0x1056e4 str r3, [sp, #0x18]
 *   @0x1056e8 str r3, [sp, #0x10]
 *   @0x1056ec str r2, [sp, #0x1c]
 *   @0x1056f0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1056f4 mov r0, r6
 *   @0x1056f8 add sp, sp, #52
 *   @0x1056fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x105700 bic r1, r1, #-16777216
 *   @0x105704 cmp r1, #2
 *   @0x105708 beq 0x10577c <_Z19F_DsMapAdd_Internalidd+0x144>
 *   @0x10570c cmp r1, #3
 *   @0x105710 beq 0x105754 <_Z19F_DsMapAdd_Internalidd+0x11c>
 *   @0x105714 cmp r1, #1
 *   @0x105718 bne 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0>
 *   @0x10571c ldr r4, [sp, #0x10]
 *   @0x105720 cmp r4, #0
 *   @0x105724 beq 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0>
 *   @0x105728 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10572c ldr r5, [r4, #0x4]
 *   @0x105730 sub r5, r5, #1
 *   @0x105734 str r5, [r4, #0x4]
 *   @0x105738 cmp r5, #0
 *   @0x10573c beq 0x105820 <_Z19F_DsMapAdd_Internalidd+0x1e8>
 *   @0x105740 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105744 b 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0>
 *   @0x105748 mov r0, r9
 *   @0x10574c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105750 b 0x1056b0 <_Z19F_DsMapAdd_Internalidd+0x78>
 *   @0x105754 ldr r3, [sp, #0x18]
 *   @0x105758 tst r3, #8
 *   @0x10575c beq 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0>
 *   @0x105760 ldr r0, [sp, #0x10]
 *   @0x105764 cmp r0, #0
 *   @0x105768 beq 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0>
 *   @0x10576c ldr r3, [r0]
 *   @0x105770 ldr r3, [r3, #0x4]
 *   @0x105774 blx r3
 *   @0x105778 b 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0>
 *   @0x10577c ldr r9, [sp, #0x10]
 *   @0x105780 cmp r9, #0
 *   @0x105784 beq 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0>
 *   @0x105788 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10578c ldr r3, [r9]
 *   @0x105790 ldr r2, [r9, #0x8]
 *   @0x105794 sub r3, r3, #1
 *   @0x105798 str r3, [r9]
 *   @0x10579c cmp r2, r10
 *   @0x1057a0 streq r4, [r9, #0x8]
 *   @0x1057a4 cmp r3, #0
 *   @0x1057a8 bgt 0x105740 <_Z19F_DsMapAdd_Internalidd+0x108>
 *   @0x1057ac ldr r3, [r9, #0x10]
 *   @0x1057b0 cmp r3, #0
 *   @0x1057b4 movgt r7, #0
 *   @0x1057b8 movgt r10, #5
 *   @0x1057bc movgt r5, r7
 *   @0x1057c0 ble 0x10587c <_Z19F_DsMapAdd_Internalidd+0x244>
 *   @0x1057c4 ldr r3, [r9, #0x4]
 *   @0x1057c8 add r2, r3, r7, lsl #3
 *   @0x1057cc str r2, [sp, #0x4]
 *   @0x1057d0 ldr r11, [r3, r7, lsl #3]
 *   @0x1057d4 ldr r4, [r2, #0x4]
 *   @0x1057d8 add r11, r4, r11, lsl #4
 *   @0x1057dc cmp r4, r11
 *   @0x1057e0 blo 0x1057fc <_Z19F_DsMapAdd_Internalidd+0x1c4>
 *   @0x1057e4 b 0x10589c <_Z19F_DsMapAdd_Internalidd+0x264>
 *   @0x1057e8 str r5, [r4, #0x8]
 *   @0x1057ec str r10, [r4, #0xc]
 *   @0x1057f0 str r5, [r4], #16
 *   @0x1057f4 cmp r11, r4
 *   @0x1057f8 bls 0x105858 <_Z19F_DsMapAdd_Internalidd+0x220>
 *   @0x1057fc ldr r3, [r4, #0xc]
 *   @0x105800 sub r3, r3, #1
 *   @0x105804 bic r3, r3, #-16777216
 *   @0x105808 bic r3, r3, #3
 *   @0x10580c cmp r3, #0
 *   @0x105810 bne 0x1057e8 <_Z19F_DsMapAdd_Internalidd+0x1b0>
 *   @0x105814 mov r0, r4
 *   @0x105818 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x10581c b 0x1057e8 <_Z19F_DsMapAdd_Internalidd+0x1b0>
 *   @0x105820 ldr r0, [r4]
 *   @0x105824 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105828 str r5, [r4]
 *   @0x10582c str r5, [r4, #0x8]
 *   @0x105830 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105834 ldr r5, [r4, #0x4]
 *   @0x105838 sub r5, r5, #1
 *   @0x10583c str r5, [r4, #0x4]
 *   @0x105840 cmp r5, #0
 *   @0x105844 beq 0x1058a4 <_Z19F_DsMapAdd_Internalidd+0x26c>
 *   @0x105848 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10584c mov r0, r4
 *   @0x105850 bl 0x27d1d0 <_ZdlPv>
 *   @0x105854 b 0x105740 <_Z19F_DsMapAdd_Internalidd+0x108>
 *   @0x105858 ldr r3, [sp, #0x4]
 *   @0x10585c ldr r0, [r3, #0x4]
 *   @0x105860 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x105864 ldr r3, [r9, #0x10]
 *   @0x105868 add r7, r7, #1
 *   @0x10586c ldr r2, [sp, #0x4]
 *   @0x105870 cmp r7, r3
 *   @0x105874 str r5, [r2, #0x4]
 *   @0x105878 blt 0x1057c4 <_Z19F_DsMapAdd_Internalidd+0x18c>
 *   @0x10587c ldr r0, [r9, #0x4]
 *   @0x105880 mov r4, #0
 *   @0x105884 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x105888 str r4, [r9, #0x4]
 *   @0x10588c mov r0, r9
 *   @0x105890 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x105894 str r4, [sp, #0x10]
 *   @0x105898 b 0x105740 <_Z19F_DsMapAdd_Internalidd+0x108>
 *   @0x10589c mov r0, r4
 *   @0x1058a0 b 0x105860 <_Z19F_DsMapAdd_Internalidd+0x228>
 *   @0x1058a4 ldr r0, [r4]
 *   @0x1058a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1058ac mov r0, r4
 *   @0x1058b0 str r5, [r4]
 *   @0x1058b4 str r5, [r4, #0x8]
 *   @0x1058b8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1058bc mov r0, r4
 *   @0x1058c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1058c4 b 0x105848 <_Z19F_DsMapAdd_Internalidd+0x210>
 *   @0x1058c8 .word 0x002e82d4
 *
 * ══ §18/46 F_HighscoreSetStrings(RValue&, CInstance*, CInstance*, int, RValue*)  0x128884  size 660  165 条（0x128884..0x128b18）
 * @func 0x128884 0x128b18  size 660  165 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×9 / LOCK_RVALUE_MUTEX()×6 / UNLOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / YYGetString(RValue const*, int)×3 / operator new(unsigned int)×3 / 0xb6538×3 / YYStrDup(char const*)×3
 * 字段偏移 top8: 0x4×12 / 0x8×9 / 0x27c×1 / 0x20×1 / 0x244×1 / 0x210×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x128884 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x128888 ldr r7, [pc, #0x27c]
 *   @0x12888c ldr r8, [sp, #0x20]
 *   @0x128890 ldr r7, [pc, r7]
 *   @0x128894 ldr r4, [r7]
 *   @0x128898 cmp r4, #0
 *   @0x12889c beq 0x1288c4 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1288a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1288a4 ldr r5, [r4, #0x4]
 *   @0x1288a8 sub r5, r5, #1
 *   @0x1288ac str r5, [r4, #0x4]
 *   @0x1288b0 cmp r5, #0
 *   @0x1288b4 beq 0x128a68 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x1288b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1288bc mov r0, r4
 *   @0x1288c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1288c4 ldr r6, [pc, #0x244]
 *   @0x1288c8 ldr r6, [pc, r6]
 *   @0x1288cc ldr r4, [r6]
 *   @0x1288d0 cmp r4, #0
 *   @0x1288d4 beq 0x1288fc <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1288d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1288dc ldr r5, [r4, #0x4]
 *   @0x1288e0 sub r5, r5, #1
 *   @0x1288e4 str r5, [r4, #0x4]
 *   @0x1288e8 cmp r5, #0
 *   @0x1288ec beq 0x128a30 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x1288f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1288f4 mov r0, r4
 *   @0x1288f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1288fc ldr r5, [pc, #0x210]
 *   @0x128900 ldr r5, [pc, r5]
 *   @0x128904 ldr r4, [r5]
 *   @0x128908 cmp r4, #0
 *   @0x12890c beq 0x128934 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x128910 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x128914 ldr r9, [r4, #0x4]
 *   @0x128918 sub r9, r9, #1
 *   @0x12891c str r9, [r4, #0x4]
 *   @0x128920 cmp r9, #0
 *   @0x128924 beq 0x1289f8 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x128928 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x12892c mov r0, r4
 *   @0x128930 bl 0x27d1d0 <_ZdlPv>
 *   @0x128934 mov r1, #0
 *   @0x128938 mov r0, r8
 *   @0x12893c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x128940 mov r9, r0
 *   @0x128944 mov r0, #12
 *   @0x128948 bl 0x27c524 <_Znwj>
 *   @0x12894c mov r4, r0
 *   @0x128950 subs r0, r9, #0
 *   @0x128954 beq 0x12895c <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x128958 bl 0xb6538 <strlen@plt>
 *   @0x12895c str r0, [r4, #0x8]
 *   @0x128960 mov r0, r9
 *   @0x128964 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x128968 mov r3, #1
 *   @0x12896c mov r1, r3
 *   @0x128970 stm r4, {r0, r3}
 *   @0x128974 mov r0, r8
 *   @0x128978 str r4, [r7]
 *   @0x12897c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x128980 mov r7, r0
 *   @0x128984 mov r0, #12
 *   @0x128988 bl 0x27c524 <_Znwj>
 *   @0x12898c mov r4, r0
 *   @0x128990 subs r0, r7, #0
 *   @0x128994 beq 0x12899c <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x128998 bl 0xb6538 <strlen@plt>
 *   @0x12899c str r0, [r4, #0x8]
 *   @0x1289a0 mov r0, r7
 *   @0x1289a4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1289a8 mov r3, #1
 *   @0x1289ac mov r1, #2
 *   @0x1289b0 stm r4, {r0, r3}
 *   @0x1289b4 mov r0, r8
 *   @0x1289b8 str r4, [r6]
 *   @0x1289bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1289c0 mov r6, r0
 *   @0x1289c4 mov r0, #12
 *   @0x1289c8 bl 0x27c524 <_Znwj>
 *   @0x1289cc mov r4, r0
 *   @0x1289d0 subs r0, r6, #0
 *   @0x1289d4 beq 0x1289dc <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x1289d8 bl 0xb6538 <strlen@plt>
 *   @0x1289dc str r0, [r4, #0x8]
 *   @0x1289e0 mov r0, r6
 *   @0x1289e4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1289e8 mov r3, #1
 *   @0x1289ec stm r4, {r0, r3}
 *   @0x1289f0 str r4, [r5]
 *   @0x1289f4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1289f8 ldr r0, [r4]
 *   @0x1289fc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x128a00 str r9, [r4]
 *   @0x128a04 str r9, [r4, #0x8]
 *   @0x128a08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x128a0c ldr r9, [r4, #0x4]
 *   @0x128a10 sub r9, r9, #1
 *   @0x128a14 str r9, [r4, #0x4]
 *   @0x128a18 cmp r9, #0
 *   @0x128a1c beq 0x128aa0 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x128a20 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x128a24 mov r0, r4
 *   @0x128a28 bl 0x27d1d0 <_ZdlPv>
 *   @0x128a2c b 0x128928 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x128a30 ldr r0, [r4]
 *   @0x128a34 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x128a38 str r5, [r4]
 *   @0x128a3c str r5, [r4, #0x8]
 *   @0x128a40 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x128a44 ldr r5, [r4, #0x4]
 *   @0x128a48 sub r5, r5, #1
 *   @0x128a4c str r5, [r4, #0x4]
 *   @0x128a50 cmp r5, #0
 *   @0x128a54 beq 0x128ae8 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x128a58 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x128a5c mov r0, r4
 *   @0x128a60 bl 0x27d1d0 <_ZdlPv>
 *   @0x128a64 b 0x1288f0 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x128a68 ldr r0, [r4]
 *   @0x128a6c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x128a70 str r5, [r4]
 *   @0x128a74 str r5, [r4, #0x8]
 *   @0x128a78 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x128a7c ldr r5, [r4, #0x4]
 *   @0x128a80 sub r5, r5, #1
 *   @0x128a84 str r5, [r4, #0x4]
 *   @0x128a88 cmp r5, #0
 *   @0x128a8c beq 0x128ac4 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x240>
 *   @0x128a90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x128a94 mov r0, r4
 *   @0x128a98 bl 0x27d1d0 <_ZdlPv>
 *   @0x128a9c b 0x1288b8 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x128aa0 ldr r0, [r4]
 *   @0x128aa4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x128aa8 mov r0, r4
 *   @0x128aac str r9, [r4]
 *   @0x128ab0 str r9, [r4, #0x8]
 *   @0x128ab4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x128ab8 mov r0, r4
 *   @0x128abc bl 0x27d1d0 <_ZdlPv>
 *   @0x128ac0 b 0x128a20 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x128ac4 ldr r0, [r4]
 *   @0x128ac8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x128acc mov r0, r4
 *   @0x128ad0 str r5, [r4]
 *   @0x128ad4 str r5, [r4, #0x8]
 *   @0x128ad8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x128adc mov r0, r4
 *   @0x128ae0 bl 0x27d1d0 <_ZdlPv>
 *   @0x128ae4 b 0x128a90 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x128ae8 ldr r0, [r4]
 *   @0x128aec bl 0xcef90 <_Z6YYFreePKv>
 *   @0x128af0 mov r0, r4
 *   @0x128af4 str r5, [r4]
 *   @0x128af8 str r5, [r4, #0x8]
 *   @0x128afc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x128b00 mov r0, r4
 *   @0x128b04 bl 0x27d1d0 <_ZdlPv>
 *   @0x128b08 b 0x128a58 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x128b0c .word 0x002c63b8
 *   @0x128b10 eoreq r6, r12, r4, lsl #7
 *   @0x128b14 eoreq r6, r12, r0, asr r3
 *
 * ══ §19/46 GifUnionColorMap(ColorMapObject const*, ColorMapObject const*, unsigned char*)  0x2c2c68  size 660  165 条（0x2c2c68..0x2c2efc）
 * @func 0x2c2c68 0x2c2efc  size 660  165 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GifUnionColorMap(ColorMapObject const*, ColorMapObject const*, unsigned char*)+0x1d8×2 / GifMakeMapObject(int, GifColorType const*) / GifUnionColorMap(ColorMapObject const*, ColorMapObject const*, unsigned char*)+0x8c / GifUnionColorMap(ColorMapObject const*, ColorMapObject const*, unsigned char*)+0x19c / 0xb6c40 / GifBitSize(int) / GifUnionColorMap(ColorMapObject const*, ColorMapObject const*, unsigned char*)+0x24c / GifUnionColorMap(ColorMapObject const*, ColorMapObject const*, unsigned char*)+0x280
 * 字段偏移 top8: 0xc×12 / 0x8×7 / 0x2×6 / 0x4×3 / 0x1×2 / 0x-5×1 / 0x-1×1 / 0x-6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2c68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c2c6c sub sp, sp, #20
 *   @0x2c2c70 ldr r3, [r0]
 *   @0x2c2c74 mov r7, r0
 *   @0x2c2c78 str r2, [sp, #0xc]
 *   @0x2c2c7c mov r10, r1
 *   @0x2c2c80 ldr r2, [r1]
 *   @0x2c2c84 mov r1, #0
 *   @0x2c2c88 cmp r3, r2
 *   @0x2c2c8c lslgt r0, r3, #1
 *   @0x2c2c90 lslle r0, r2, #1
 *   @0x2c2c94 bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType>
 *   @0x2c2c98 cmp r0, #0
 *   @0x2c2c9c str r0, [sp, #0x8]
 *   @0x2c2ca0 beq 0x2c2edc <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x274>
 *   @0x2c2ca4 ldr r4, [r7]
 *   @0x2c2ca8 cmp r4, #0
 *   @0x2c2cac mov r6, r4
 *   @0x2c2cb0 ble 0x2c2cf4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x8c>
 *   @0x2c2cb4 mov r3, #0
 *   @0x2c2cb8 mov r5, r0
 *   @0x2c2cbc ldr r0, [r7, #0xc]
 *   @0x2c2cc0 add r2, r3, r3, lsl #1
 *   @0x2c2cc4 ldr r1, [r5, #0xc]
 *   @0x2c2cc8 add r3, r3, #1
 *   @0x2c2ccc add r0, r0, r2
 *   @0x2c2cd0 add r12, r1, r2
 *   @0x2c2cd4 ldrh lr, [r0]
 *   @0x2c2cd8 ldrb r0, [r0, #0x2]
 *   @0x2c2cdc strh lr, [r1, r2]
 *   @0x2c2ce0 strb r0, [r12, #0x2]
 *   @0x2c2ce4 ldr r4, [r7]
 *   @0x2c2ce8 cmp r4, r3
 *   @0x2c2cec mov r6, r4
 *   @0x2c2cf0 bgt 0x2c2cbc <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x54>
 *   @0x2c2cf4 ldr r3, [r7, #0xc]
 *   @0x2c2cf8 add r0, r4, r4, lsl #1
 *   @0x2c2cfc sub r1, r0, #3
 *   @0x2c2d00 add r2, r3, r1
 *   @0x2c2d04 ldrb r1, [r3, r1]
 *   @0x2c2d08 cmp r1, #0
 *   @0x2c2d0c bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4>
 *   @0x2c2d10 ldrb r1, [r2, #0x1]
 *   @0x2c2d14 cmp r1, #0
 *   @0x2c2d18 bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4>
 *   @0x2c2d1c ldrb r2, [r2, #0x2]
 *   @0x2c2d20 cmp r2, #0
 *   @0x2c2d24 bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4>
 *   @0x2c2d28 add r3, r3, r0
 *   @0x2c2d2c b 0x2c2d4c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xe4>
 *   @0x2c2d30 ldrb r2, [r3, #-0x5]
 *   @0x2c2d34 sub r3, r3, #3
 *   @0x2c2d38 cmp r2, #0
 *   @0x2c2d3c bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4>
 *   @0x2c2d40 ldrb r2, [r3, #-0x1]
 *   @0x2c2d44 cmp r2, #0
 *   @0x2c2d48 bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4>
 *   @0x2c2d4c ldrb r2, [r3, #-0x6]
 *   @0x2c2d50 sub r6, r6, #1
 *   @0x2c2d54 cmp r2, #0
 *   @0x2c2d58 beq 0x2c2d30 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xc8>
 *   @0x2c2d5c ldr r3, [r10]
 *   @0x2c2d60 cmp r3, #0
 *   @0x2c2d64 ble 0x2c2e40 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x1d8>
 *   @0x2c2d68 cmp r6, #256
 *   @0x2c2d6c strle r7, [sp, #0x4]
 *   @0x2c2d70 movle r9, #0
 *   @0x2c2d74 movle r8, r9
 *   @0x2c2d78 bgt 0x2c2ed4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x26c>
 *   @0x2c2d7c ldr r5, [r10, #0xc]
 *   @0x2c2d80 cmp r4, #0
 *   @0x2c2d84 addle r5, r5, r9
 *   @0x2c2d88 ble 0x2c2e04 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x19c>
 *   @0x2c2d8c ldr r3, [sp, #0x4]
 *   @0x2c2d90 mov r11, #0
 *   @0x2c2d94 add r5, r5, r9
 *   @0x2c2d98 ldr r7, [r3, #0xc]
 *   @0x2c2d9c b 0x2c2dac <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x144>
 *   @0x2c2da0 add r11, r11, #1
 *   @0x2c2da4 cmp r11, r4
 *   @0x2c2da8 beq 0x2c2e04 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x19c>
 *   @0x2c2dac mov r0, r7
 *   @0x2c2db0 mov r2, #3
 *   @0x2c2db4 mov r1, r5
 *   @0x2c2db8 add r7, r7, r2
 *   @0x2c2dbc bl 0xb6c40 <memcmp@plt>
 *   @0x2c2dc0 cmp r0, #0
 *   @0x2c2dc4 bne 0x2c2da0 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x138>
 *   @0x2c2dc8 ldr r3, [sp, #0xc]
 *   @0x2c2dcc strb r11, [r3, r8]
 *   @0x2c2dd0 add r8, r8, #1
 *   @0x2c2dd4 ldr r3, [r10]
 *   @0x2c2dd8 cmp r3, r8
 *   @0x2c2ddc ble 0x2c2e40 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x1d8>
 *   @0x2c2de0 cmp r6, #256
 *   @0x2c2de4 add r9, r9, #3
 *   @0x2c2de8 bgt 0x2c2ed4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x26c>
 *   @0x2c2dec ldr r3, [sp, #0x4]
 *   @0x2c2df0 ldr r5, [r10, #0xc]
 *   @0x2c2df4 ldr r4, [r3]
 *   @0x2c2df8 cmp r4, #0
 *   @0x2c2dfc addle r5, r5, r9
 *   @0x2c2e00 bgt 0x2c2d8c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x124>
 *   @0x2c2e04 ldr r3, [sp, #0x8]
 *   @0x2c2e08 ldrh r12, [r5]
 *   @0x2c2e0c ldrb r0, [r5, #0x2]
 *   @0x2c2e10 ldr r2, [r3, #0xc]
 *   @0x2c2e14 add r3, r6, r6, lsl #1
 *   @0x2c2e18 add r1, r2, r3
 *   @0x2c2e1c strh r12, [r2, r3]
 *   @0x2c2e20 ldr r3, [sp, #0xc]
 *   @0x2c2e24 strb r0, [r1, #0x2]
 *   @0x2c2e28 strb r6, [r3, r8]
 *   @0x2c2e2c add r8, r8, #1
 *   @0x2c2e30 ldr r3, [r10]
 *   @0x2c2e34 add r6, r6, #1
 *   @0x2c2e38 cmp r3, r8
 *   @0x2c2e3c bgt 0x2c2de0 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x178>
 *   @0x2c2e40 cmp r6, #256
 *   @0x2c2e44 bgt 0x2c2ed4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x26c>
 *   @0x2c2e48 mov r0, r6
 *   @0x2c2e4c mov r5, #1
 *   @0x2c2e50 bl 0x2c2b8c <_Z10GifBitSizei>
 *   @0x2c2e54 ldr r2, [sp, #0x8]
 *   @0x2c2e58 ldr r3, [r2]
 *   @0x2c2e5c lsl r5, r5, r0
 *   @0x2c2e60 mov r7, r0
 *   @0x2c2e64 cmp r3, r5
 *   @0x2c2e68 beq 0x2c2ebc <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x254>
 *   @0x2c2e6c cmp r5, r6
 *   @0x2c2e70 ldr r0, [r2, #0xc]
 *   @0x2c2e74 ble 0x2c2eb4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x24c>
 *   @0x2c2e78 rsb r4, r6, r5
 *   @0x2c2e7c add r6, r6, r6, lsl #1
 *   @0x2c2e80 mov r3, #0
 *   @0x2c2e84 add r12, r0, r6
 *   @0x2c2e88 add r4, r4, r4, lsl #1
 *   @0x2c2e8c mov r2, r3
 *   @0x2c2e90 add r1, r12, r3
 *   @0x2c2e94 strb r2, [r1, #0x2]
 *   @0x2c2e98 strb r2, [r1, #0x1]
 *   @0x2c2e9c strb r2, [r12, r3]
 *   @0x2c2ea0 add r3, r3, #3
 *   @0x2c2ea4 cmp r3, r4
 *   @0x2c2ea8 bne 0x2c2e90 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x228>
 *   @0x2c2eac ldr r2, [sp, #0x8]
 *   @0x2c2eb0 ldr r3, [r2]
 *   @0x2c2eb4 cmp r5, r3
 *   @0x2c2eb8 blt 0x2c2ee8 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x280>
 *   @0x2c2ebc ldr r3, [sp, #0x8]
 *   @0x2c2ec0 mov r0, r3
 *   @0x2c2ec4 str r5, [r3]
 *   @0x2c2ec8 str r7, [r3, #0x4]
 *   @0x2c2ecc add sp, sp, #20
 *   @0x2c2ed0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c2ed4 ldr r0, [sp, #0x8]
 *   @0x2c2ed8 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c2edc mov r0, #0
 *   @0x2c2ee0 add sp, sp, #20
 *   @0x2c2ee4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c2ee8 add r1, r5, r5, lsl #1
 *   @0x2c2eec bl 0xb6c28 <realloc@plt>
 *   @0x2c2ef0 ldr r3, [sp, #0x8]
 *   @0x2c2ef4 str r0, [r3, #0xc]
 *   @0x2c2ef8 b 0x2c2ebc <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x254>
 *
 * ══ §20/46 b2MouseJoint::b2MouseJoint(b2MouseJointDef const*)  0x2cedbc  size 660  165 条（0x2cedbc..0x2cf050）
 * @func 0x2cedbc 0x2cf050  size 660  165 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*) / b2MouseJoint::b2MouseJoint(b2MouseJointDef const*)+0x64
 * 字段偏移 top8: 0x2×5 / 0x264×1 / 0x258×1 / 0x214×1 / 0x1d0×1 / 0x18c×1 / 0x148×1 / 0x34×1
 * VFP 指令 65 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cedbc push {r4, r5, r6, lr}
 *   @0x2cedc0 sub sp, sp, #16
 *   @0x2cedc4 mov r4, r0
 *   @0x2cedc8 mov r5, r1
 *   @0x2cedcc ldr r6, [pc, #0x264]
 *   @0x2cedd0 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2cedd4 vldr s15, [r5, #20]
 *   @0x2cedd8 vcmp.f32 s15, s15
 *   @0x2ceddc ldr r3, [pc, #0x258]
 *   @0x2cede0 ldr r6, [pc, r6]
 *   @0x2cede4 ldr r3, [pc, r3]
 *   @0x2cede8 ldr r2, [r6]
 *   @0x2cedec add r3, r3, #8
 *   @0x2cedf0 vmrs APSR_nzcv, fpscr
 *   @0x2cedf4 str r3, [r4]
 *   @0x2cedf8 bne 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64>
 *   @0x2cedfc mov r3, #0
 *   @0x2cee00 movw r1, #0x7f80
 *   @0x2cee04 strh r3, [sp]
 *   @0x2cee08 strh r1, [sp, #2]
 *   @0x2cee0c vldr s14, [sp]
 *   @0x2cee10 vneg.f32 s13, s14
 *   @0x2cee14 vcmpe.f32 s15, s13
 *   @0x2cee18 vmrs APSR_nzcv, fpscr
 *   @0x2cee1c bgt 0x2cefec <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x230>
 *   @0x2cee20 mov r0, #0
 *   @0x2cee24 ldr r1, [pc, #0x214]
 *   @0x2cee28 add r1, pc, r1
 *   @0x2cee2c blx r2
 *   @0x2cee30 vldr s15, [r5, #28]
 *   @0x2cee34 vcmp.f32 s15, s15
 *   @0x2cee38 ldr r3, [r6]
 *   @0x2cee3c vmrs APSR_nzcv, fpscr
 *   @0x2cee40 bne 0x2cee68 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xac>
 *   @0x2cee44 mov r1, #0
 *   @0x2cee48 movw r2, #0x7f80
 *   @0x2cee4c strh r1, [sp]
 *   @0x2cee50 strh r2, [sp, #2]
 *   @0x2cee54 vldr s14, [sp]
 *   @0x2cee58 vneg.f32 s13, s14
 *   @0x2cee5c vcmpe.f32 s15, s13
 *   @0x2cee60 vmrs APSR_nzcv, fpscr
 *   @0x2cee64 bgt 0x2cefcc <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x210>
 *   @0x2cee68 mov r0, #0
 *   @0x2cee6c ldr r1, [pc, #0x1d0]
 *   @0x2cee70 add r1, pc, r1
 *   @0x2cee74 blx r3
 *   @0x2cee78 vldr s15, [r5, #32]
 *   @0x2cee7c vcmp.f32 s15, s15
 *   @0x2cee80 ldr r3, [r6]
 *   @0x2cee84 vmrs APSR_nzcv, fpscr
 *   @0x2cee88 bne 0x2ceeb0 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xf4>
 *   @0x2cee8c mov r1, #0
 *   @0x2cee90 movw r2, #0x7f80
 *   @0x2cee94 strh r1, [sp]
 *   @0x2cee98 strh r2, [sp, #2]
 *   @0x2cee9c vldr s14, [sp]
 *   @0x2ceea0 vneg.f32 s13, s14
 *   @0x2ceea4 vcmpe.f32 s15, s13
 *   @0x2ceea8 vmrs APSR_nzcv, fpscr
 *   @0x2ceeac bgt 0x2cefac <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x1f0>
 *   @0x2ceeb0 mov r0, #0
 *   @0x2ceeb4 ldr r1, [pc, #0x18c]
 *   @0x2ceeb8 add r1, pc, r1
 *   @0x2ceebc blx r3
 *   @0x2ceec0 vldr s15, [r5, #36]
 *   @0x2ceec4 vcmp.f32 s15, s15
 *   @0x2ceec8 ldr r3, [r6]
 *   @0x2ceecc vmrs APSR_nzcv, fpscr
 *   @0x2ceed0 bne 0x2ceef8 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x13c>
 *   @0x2ceed4 mov r1, #0
 *   @0x2ceed8 movw r2, #0x7f80
 *   @0x2ceedc strh r1, [sp]
 *   @0x2ceee0 strh r2, [sp, #2]
 *   @0x2ceee4 vldr s14, [sp]
 *   @0x2ceee8 vneg.f32 s13, s14
 *   @0x2ceeec vcmpe.f32 s15, s13
 *   @0x2ceef0 vmrs APSR_nzcv, fpscr
 *   @0x2ceef4 bgt 0x2cef8c <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x1d0>
 *   @0x2ceef8 mov r0, #0
 *   @0x2ceefc ldr r1, [pc, #0x148]
 *   @0x2cef00 add r1, pc, r1
 *   @0x2cef04 blx r3
 *   @0x2cef08 add r2, r5, #20
 *   @0x2cef0c add r12, r4, #76
 *   @0x2cef10 ldr r3, [r4, #0x34]
 *   @0x2cef14 ldm r2, {r0, r1}
 *   @0x2cef18 vldr s15, [r3, #16]
 *   @0x2cef1c vldr s11, [r3, #20]
 *   @0x2cef20 vldr s13, [r3, #24]
 *   @0x2cef24 vldr s12, [r3, #12]
 *   @0x2cef28 ldr r2, [r5, #0x1c]
 *   @0x2cef2c stm r12, {r0, r1}
 *   @0x2cef30 vldr s14, [r4, #80]
 *   @0x2cef34 vsub.f32 s14, s14, s15
 *   @0x2cef38 vldr s10, [r4, #76]
 *   @0x2cef3c ldr r1, [r5, #0x20]
 *   @0x2cef40 mov r3, #0
 *   @0x2cef44 str r2, [r4, #0x68]
 *   @0x2cef48 mov r0, r4
 *   @0x2cef4c ldr r2, [r5, #0x24]
 *   @0x2cef50 str r3, [r4, #0x60]
 *   @0x2cef54 str r3, [r4, #0x64]
 *   @0x2cef58 str r1, [r4, #0x54]
 *   @0x2cef5c str r3, [r4, #0x5c]
 *   @0x2cef60 str r2, [r4, #0x58]
 *   @0x2cef64 str r3, [r4, #0x6c]
 *   @0x2cef68 vmul.f32 s15, s14, s11
 *   @0x2cef6c vmul.f32 s14, s14, s13
 *   @0x2cef70 vsub.f32 s12, s10, s12
 *   @0x2cef74 vmls.f32 s14, s11, s12
 *   @0x2cef78 vmla.f32 s15, s12, s13
 *   @0x2cef7c vstr s14, [r4, #72]
 *   @0x2cef80 vstr s15, [r4, #68]
 *   @0x2cef84 add sp, sp, #16
 *   @0x2cef88 pop {r4, r5, r6, pc}
 *   @0x2cef8c vcmpe.f32 s15, s14
 *   @0x2cef90 vmrs APSR_nzcv, fpscr
 *   @0x2cef94 bpl 0x2ceef8 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x13c>
 *   @0x2cef98 vcmpe.f32 s15, #0
 *   @0x2cef9c vmrs APSR_nzcv, fpscr
 *   @0x2cefa0 movge r0, #1
 *   @0x2cefa4 bge 0x2ceefc <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x140>
 *   @0x2cefa8 b 0x2ceef8 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x13c>
 *   @0x2cefac vcmpe.f32 s15, s14
 *   @0x2cefb0 vmrs APSR_nzcv, fpscr
 *   @0x2cefb4 bpl 0x2ceeb0 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xf4>
 *   @0x2cefb8 vcmpe.f32 s15, #0
 *   @0x2cefbc vmrs APSR_nzcv, fpscr
 *   @0x2cefc0 movge r0, #1
 *   @0x2cefc4 bge 0x2ceeb4 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xf8>
 *   @0x2cefc8 b 0x2ceeb0 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xf4>
 *   @0x2cefcc vcmpe.f32 s15, s14
 *   @0x2cefd0 vmrs APSR_nzcv, fpscr
 *   @0x2cefd4 bpl 0x2cee68 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xac>
 *   @0x2cefd8 vcmpe.f32 s15, #0
 *   @0x2cefdc vmrs APSR_nzcv, fpscr
 *   @0x2cefe0 movge r0, #1
 *   @0x2cefe4 bge 0x2cee6c <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xb0>
 *   @0x2cefe8 b 0x2cee68 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0xac>
 *   @0x2cefec vcmpe.f32 s15, s14
 *   @0x2ceff0 vmrs APSR_nzcv, fpscr
 *   @0x2ceff4 bpl 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64>
 *   @0x2ceff8 vldr s15, [r5, #24]
 *   @0x2ceffc vcmp.f32 s15, s15
 *   @0x2cf000 vmrs APSR_nzcv, fpscr
 *   @0x2cf004 bne 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64>
 *   @0x2cf008 strh r3, [sp]
 *   @0x2cf00c strh r1, [sp, #2]
 *   @0x2cf010 vldr s14, [sp]
 *   @0x2cf014 vneg.f32 s13, s14
 *   @0x2cf018 vcmpe.f32 s15, s13
 *   @0x2cf01c vmrs APSR_nzcv, fpscr
 *   @0x2cf020 ble 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64>
 *   @0x2cf024 vcmpe.f32 s15, s14
 *   @0x2cf028 vmrs APSR_nzcv, fpscr
 *   @0x2cf02c bpl 0x2cee20 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x64>
 *   @0x2cf030 mov r0, #1
 *   @0x2cf034 b 0x2cee24 <_ZN12b2MouseJointC2EPK15b2MouseJointDef+0x68>
 *   @0x2cf038 andseq r2, r2, r8, ror #13
 *   @0x2cf03c andseq r2, r2, r0, lsl #27
 *   @0x2cf040 andeq lr, r8, r4, lsl r7
 *   @0x2cf044 andeq lr, r8, r4, lsr #14
 *   @0x2cf048 andeq lr, r8, r4, lsr #15
 *   @0x2cf04c andeq lr, r8, r12, lsr r8
 *
 * ══ §21/46 png_create_read_struct_2  0x2a6d4c  size 656  164 条（0x2a6d4c..0x2a6fdc）
 * @func 0x2a6d4c 0x2a6fdc  size 656  164 条
 * 部分覆盖: 本节 164/297 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_get_header_ver×2 / png_warning×2 / png_create_struct_2 / 0x507190 / 0x4f39b8 / 0x4ef9e8 / png_set_mem_fn / FT_Get_CMap_Format+0x8
 * 字段偏移 top8: 0x24×17 / 0x4×4 / 0xa0×2 / 0x28×2 / 0x98×1 / 0x14×1 / 0x18×1 / 0x240×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6d4c push {r4, r5, r6, r7, lr}
 *   @0x2a6d50 str r0, [sp]
 *   @0x2a6d54 ldr r0, [sp, #0x98]
 *   @0x2a6d58 str r1, [sp, #0x14]
 *   @0x2a6d5c str r3, [sp, #0x4]
 *   @0x2a6d60 str r2, [sp, #0x18]
 *   @0x2a6d64 ldr r2, [sp, #0xa0]
 *   @0x2a6d68 ldr r3, [pc, #0x240]
 *   @0x2a6d6c str r1, [sp, #0xc]
 *   @0x2a6d70 movs r0, #0x1
 *   @0x2a6d74 ldr r3, [r3]
 *   @0x2a6d78 movs r3, #0x0
 *   @0x2a6d7c bl 0x2a6c02 <png_create_struct_2>
 *   @0x2a6d80 str r0, [sp, #0x24]
 *   @0x2a6d84 cmp r0, #0x0
 *   @0x2a6d88 bls 0x507190 <SrcVerts+0x641d4>
 *   @0x2a6d8c ldr r3, [pc, #0x210]
 *   @0x2a6d90 bls 0x4f39b8 <SrcVerts+0x509fc>
 *   @0x2a6d94 str.w r3, [r2, #0x30c]
 *   @0x2a6d98 movw r2, #0x7fff
 *   @0x2a6d9c ldr r3, [sp, #0x24]
 *   @0x2a6da0 blls 0x4ef9e8 <SrcVerts+0x4ca2c>
 *   @0x2a6da4 ldr r2, [pc, #0x1fc]
 *   @0x2a6da8 str.w r2, [r3, #0x1a0]
 *   @0x2a6dac ldr r2, [sp, #0x4]
 *   @0x2a6db0 ldr r1, [r2, r3]
 *   @0x2a6db4 .word 0xf7ff7280
 *   @0x2a6db8 .word 0xf60ffbc1
 *   @0x2a6dbc strmi lr, [r4], -r4, lsr #27
 *   @0x2a6dc0 cbz r0, 0x2a6dc6 <png_create_read_struct_2+0x7a>
 *   @0x2a6dc4 stmdbge r2, {r1, r5, r6, r8, r9, r10, r11, sp, lr, pc}
 *   @0x2a6dc8 ldr r0, [sp, #0x24]
 *   @0x2a6dcc bl 0x2a6d34 <png_set_mem_fn>
 *   @0x2a6dd0 add r1, sp, #0x14
 *   @0x2a6dd4 ldm r1, {r1, r2, r3}
 *   @0x2a6dd8 blls 0x2e5cc8 <FT_Get_CMap_Format+0x8>
 *   @0x2a6ddc cbz r3, 0x2a6e1a <png_create_read_struct_2+0xce>
 *   @0x2a6de0 mov.w r3, #0xffffffff
 *   @0x2a6de4 movs r6, #0x1
 *   @0x2a6de8 ldr r0, [sp]
 *   @0x2a6dec ldrb r2, [r3, r5]
 *   @0x2a6df0 ldrb r1, [r0, r3]
 *   @0x2a6df4 beq 0x2a6e04 <png_create_read_struct_2+0xb8>
 *   @0x2a6df8 ldr.w r0, [r1, #0x130]
 *   @0x2a6dfc orr r0, r0, #0x20000
 *   @0x2a6e00 str.w r0, [r1, #0x130]
 *   @0x2a6e04 ldr r0, [sp]
 *   @0x2a6e08 cmp r1, #0x2e
 *   @0x2a6e0c cbnz r4, 0x2a6e28 <png_create_read_struct_2+0xdc>
 *   @0x2a6e10 b 0x2a6e14 <png_create_read_struct_2+0xc8>
 *   @0x2a6e14 cmp r2, #0x0
 *   @0x2a6e18 b 0x2a6e28 <png_create_read_struct_2+0xdc>
 *   @0x2a6e1c ldr.w r2, [r3, #0x130]
 *   @0x2a6e20 orr r2, r2, #0x20000
 *   @0x2a6e24 str.w r2, [r3, #0x130]
 *   @0x2a6e28 ldr r3, [sp, #0x24]
 *   @0x2a6e2c orrseq r3, r11, #48, #2
 *   @0x2a6e30 bpl 0x2a6eb4 <png_create_read_struct_2+0x168>
 *   @0x2a6e34 cbz r1, 0x2a6e88 <png_create_read_struct_2+0x13c>
 *   @0x2a6e38 ldrb r4, [r1]
 *   @0x2a6e3c stmdavc r3, {r0, r1, r2, r6, r7, r11, r12, sp, lr, pc}
 *   @0x2a6e40 cmp r3, r4
 *   @0x2a6e44 ldr r2, [sp]
 *   @0x2a6e48 cmp r3, #0x31
 *   @0x2a6e4c ldr r0, [sp]
 *   @0x2a6e50 cmp r3, #0x30
 *   @0x2a6e54 b 0x2a6e68 <png_create_read_struct_2+0x11c>
 *   @0x2a6e58 movs r0, #0x0
 *   @0x2a6e5c bl 0x2a5fcc <png_get_header_ver>
 *   @0x2a6e60 ldrb r3, [r0, #0x2]
 *   @0x2a6e64 bne 0x2a6e70 <png_create_read_struct_2+0x124>
 *   @0x2a6e68 ldr r2, [sp]
 *   @0x2a6e6c cmp r3, #0x38
 *   @0x2a6e70 add r4, sp, #0x2c
 *   @0x2a6e74 movs r1, #0x50
 *   @0x2a6e78 mov r0, r4
 *   @0x2a6e7c blx 0xb65c8 <snprintf@plt>
 *   @0x2a6e80 ldr r0, [sp, #0x24]
 *   @0x2a6e84 bl 0x2a6474 <png_warning>
 *   @0x2a6e88 movs r0, #0x0
 *   @0x2a6e8c bl 0x2a5fcc <png_get_header_ver>
 *   @0x2a6e90 ldr r2, [pc, #0x128]
 *   @0x2a6e94 add r2, pc
 *   @0x2a6e98 mov r0, r4
 *   @0x2a6e9c stmdals r9, {r1, r2, r4, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2a6ea0 mov r1, r4
 *   @0x2a6ea4 stmdbmi r6, {r0, r1, r2, r5, r6, r7, r9, r11, r12, sp, lr, pc} ^
 *   @0x2a6ea8 ldr r0, [sp, #0x24]
 *   @0x2a6eac bl 0x2a6474 <png_warning>
 *   @0x2a6eb0 movs r3, #0x1
 *   @0x2a6eb4 ldr r3, [sp, #0x28]
 *   @0x2a6eb8 ldr r3, [sp, #0x24]
 *   @0x2a6ebc .word 0x9c095200
 *   @0x2a6ec0 ldr r0, [sp, #0x24]
 *   @0x2a6ec4 blls 0x4ef49c <SrcVerts+0x4c4e0>
 *   @0x2a6ec8 ldr.w r1, [r3, #0x174]
 *   @0x2a6ecc bl 0x2a6d16 <png_malloc_warn>
 *   @0x2a6ed0 ldr r3, [sp, #0x24]
 *   @0x2a6ed4 .word 0xf8d30170
 *   @0x2a6ed8 stmdblt r11, {r4, r5, r6, r8, r12, sp}
 *   @0x2a6edc movs r3, #0x1
 *   @0x2a6ee0 ldr r0, [sp, #0x4]
 *   @0x2a6ee4 ldr r2, [sp, #0x24]
 *   @0x2a6ee8 str.w r3, [r2, #0x158]
 *   @0x2a6eec ldr r3, [pc, #0xd8]
 *   @0x2a6ef0 ldr r3, [r0, r3]
 *   @0x2a6ef4 bls 0x4f346c <SrcVerts+0x504b0>
 *   @0x2a6ef8 ldr r3, [sp, #0x24]
 *   @0x2a6efc blls 0x533484 <g_pPNGFile+0x4b8>
 *   @0x2a6f00 cbnz r3, 0x2a6f42 <png_create_read_struct_2+0x1f6>
 *   @0x2a6f04 movs r2, #0x38
 *   @0x2a6f08 add.w r0, r0, #0x138
 *   @0x2a6f0c add r1, pc
 *   @0x2a6f10 andlo lr, r6, r0, ror #26
 *   @0x2a6f14 cmp r0, #0x6
 *   @0x2a6f18 tbb [pc, r0]
 *   @0x2a6f1c lsrs r0, r1, #0x10
 *   @0x2a6f20 lsrs r4, r0, #0x10
 *   @0x2a6f24 ldr r1, [pc, #0xa8]
 *   @0x2a6f28 add r1, pc
 *   @0x2a6f2c ldr r1, [pc, #0xa4]
 *   @0x2a6f30 add r1, pc
 *   @0x2a6f34 ldr r1, [pc, #0xa0]
 *   @0x2a6f38 add r1, pc
 *   @0x2a6f3c movwhs pc, #0x1a9b
 *   @0x2a6f40 str r3, [sp, #0x28]
 *   @0x2a6f44 cbz r1, 0x2a6f68 <png_create_read_struct_2+0x21c>
 *   @0x2a6f48 movs r4, #0x0
 *   @0x2a6f4c ldr.w r1, [r3, #0x170]
 *   @0x2a6f50 bl 0x2a6cfc <png_free>
 *   @0x2a6f54 ldr r3, [sp, #0x24]
 *   @0x2a6f58 ldr r0, [sp, #0x24]
 *   @0x2a6f5c bls 0x337524
 *   @0x2a6f60 bl 0x2a6c5e <png_destroy_struct_2>
 *   @0x2a6f64 mov r0, r4
 *   @0x2a6f68 ldr r2, [sp, #0x24]
 *   @0x2a6f6c ldr.w r3, [r3, #0x170]
 *   @0x2a6f70 str.w r3, [r2, #0x144]
 *   @0x2a6f74 ldr r2, [sp, #0x24]
 *   @0x2a6f78 ldr r0, [sp, #0x24]
 *   @0x2a6f7c .word 0xf8c23174
 *   @0x2a6f80 strmi r3, [r10], -r8, asr #2
 *   @0x2a6f84 bl 0x2a804c <png_set_read_fn>
 *   @0x2a6f88 ldr r0, [sp, #0x24]
 *   @0x2a6f8c ldr r1, [sp, #0x4]
 *   @0x2a6f90 ldr r3, [r1, r3]
 *   @0x2a6f94 cmp r2, r3
 *   @0x2a6f98 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a6f9c add sp, #0x84
 *   @0x2a6fa0 rsbs r0, r0, #0
 *   @0x2a6fa4 asrs r0, r0, #0x8
 *   @0x2a6fa8 add r6, sp, #0x3e8
 *   @0x2a6fac pop {pc}
 *   @0x2a6fb0 .word 0xffffe4ac
 *   @0x2a6fb4 andeq r5, lr, r10, lsl #11
 *   @0x2a6fb8 ldr r6, [r4, r4]
 *   @0x2a6fbc ldr r7, [r4, r1]
 *   @0x2a6fc0 ldr r7, [r0, r2]
 *   @0x2a6fc4 mcr2 p15, #0x2, pc, c4, c15, #0x7
 *   @0x2a6fc8 mcr2 p15, #0x2, pc, c8, c15, #0x7
 *   @0x2a6fcc str r4, [r7, r2]
 *   @0x2a6fd0 ldr r0, [r0, r1]
 *   @0x2a6fd4 ldr r2, [r1, r1]
 *   @0x2a6fd8 ldr r5, [r2, r1]
 *
 * ══ §22/46 CBackground::GenerateBitmapData()  0xc2da0  size 652  163 条（0xc2da0..0xc302c）
 * @func 0xc2da0 0xc302c  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / CBackground::InitTexture()×2 / CBackground::InitLocalTPE()×2 / Graphics::Texture_GrabRect(void*, int, int, int, int) / IBitmap::Create() / 0xb65b0 / CBackground::GenerateBitmapData()+0x1bc / 0xb65bc
 * 字段偏移 top8: 0x14×9 / 0xc×8 / 0x8×4 / 0x10×3 / 0x4×3 / 0x18×2 / 0xe×2 / 0x25c×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2da0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc2da4 mov r4, r0
 *   @0xc2da8 ldr r6, [r0, #0x10]
 *   @0xc2dac sub sp, sp, #20
 *   @0xc2db0 cmp r6, #0
 *   @0xc2db4 beq 0xc2dc4 <_ZN11CBackground18GenerateBitmapDataEv+0x24>
 *   @0xc2db8 mov r0, #0
 *   @0xc2dbc add sp, sp, #20
 *   @0xc2dc0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc2dc4 ldr r3, [pc, #0x25c]
 *   @0xc2dc8 ldr r0, [r0, #0x14]
 *   @0xc2dcc ldr r3, [pc, r3]
 *   @0xc2dd0 ldrsh r12, [r0, #20]
 *   @0xc2dd4 ldr r3, [r3, #0x4]
 *   @0xc2dd8 ldrsh r1, [r0]
 *   @0xc2ddc ldrsh r2, [r0, #2]
 *   @0xc2de0 ldr lr, [r3, r12, lsl #2]
 *   @0xc2de4 ldrsh r12, [r0, #6]
 *   @0xc2de8 ldrsh r3, [r0, #4]
 *   @0xc2dec ldr r0, [lr]
 *   @0xc2df0 str r12, [sp]
 *   @0xc2df4 bl 0x17e2a8 <_ZN8Graphics16Texture_GrabRectEPviiii>
 *   @0xc2df8 subs r9, r0, #0
 *   @0xc2dfc beq 0xc2db8 <_ZN11CBackground18GenerateBitmapDataEv+0x18>
 *   @0xc2e00 ldr r3, [r4, #0x14]
 *   @0xc2e04 ldrsh r2, [r3, #12]
 *   @0xc2e08 ldrsh r3, [r3, #4]
 *   @0xc2e0c vmov s14, r2
 *   @0xc2e10 vmov s15, r3
 *   @0xc2e14 vcvt.f32.s32 s14, s14
 *   @0xc2e18 vcvt.f32.s32 s15, s15
 *   @0xc2e1c vdiv.f32 s15, s14, s15
 *   @0xc2e20 vcvt.s32.f32 s15, s15
 *   @0xc2e24 vmov r8, s15
 *   @0xc2e28 bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0xc2e2c mov r1, #7
 *   @0xc2e30 ldr r3, [r0]
 *   @0xc2e34 mov r7, r0
 *   @0xc2e38 ldr r3, [r3, #0x1c]
 *   @0xc2e3c blx r3
 *   @0xc2e40 ldr r3, [r4, #0x14]
 *   @0xc2e44 mov r1, r8
 *   @0xc2e48 ldr r5, [r7]
 *   @0xc2e4c ldrsh r0, [r3, #16]
 *   @0xc2e50 bl 0x318d10 <__divsi3>
 *   @0xc2e54 ldr r3, [r5, #0xc]
 *   @0xc2e58 mov r1, r0
 *   @0xc2e5c mov r0, r7
 *   @0xc2e60 blx r3
 *   @0xc2e64 ldr r3, [r4, #0x14]
 *   @0xc2e68 mov r1, r8
 *   @0xc2e6c ldr r5, [r7]
 *   @0xc2e70 ldrsh r0, [r3, #18]
 *   @0xc2e74 bl 0x318d10 <__divsi3>
 *   @0xc2e78 ldr r3, [r5, #0x14]
 *   @0xc2e7c mov r1, r0
 *   @0xc2e80 mov r0, r7
 *   @0xc2e84 blx r3
 *   @0xc2e88 add r2, sp, #16
 *   @0xc2e8c mov r1, r6
 *   @0xc2e90 add r3, sp, #8
 *   @0xc2e94 str r6, [r2, #-0x4]!
 *   @0xc2e98 mov r0, r7
 *   @0xc2e9c ldr r12, [r7]
 *   @0xc2ea0 str r6, [sp, #0x8]
 *   @0xc2ea4 ldr r12, [r12, #0x24]
 *   @0xc2ea8 blx r12
 *   @0xc2eac ldr r3, [r7]
 *   @0xc2eb0 ldr r5, [sp, #0xc]
 *   @0xc2eb4 ldr r3, [r3, #0x18]
 *   @0xc2eb8 mov r10, r0
 *   @0xc2ebc mov r0, r7
 *   @0xc2ec0 blx r3
 *   @0xc2ec4 ldr r2, [sp, #0x8]
 *   @0xc2ec8 mov r1, r6
 *   @0xc2ecc mul r2, r2, r0
 *   @0xc2ed0 mov r0, r5
 *   @0xc2ed4 bl 0xb65b0 <memset@plt>
 *   @0xc2ed8 ldr r5, [r4, #0x14]
 *   @0xc2edc mov r1, r8
 *   @0xc2ee0 ldrsh r0, [r5, #10]
 *   @0xc2ee4 bl 0x318d10 <__divsi3>
 *   @0xc2ee8 ldr r3, [sp, #0xc]
 *   @0xc2eec ldr r11, [sp, #0x8]
 *   @0xc2ef0 mov r1, r8
 *   @0xc2ef4 mla r11, r11, r0, r3
 *   @0xc2ef8 ldrsh r0, [r5, #8]
 *   @0xc2efc bl 0x318d10 <__divsi3>
 *   @0xc2f00 ldrsh r3, [r5, #6]
 *   @0xc2f04 cmp r3, #0
 *   @0xc2f08 ldrhgt r3, [r5, #4]
 *   @0xc2f0c movgt r5, r9
 *   @0xc2f10 add r0, r11, r0, lsl #2
 *   @0xc2f14 str r0, [sp, #0xc]
 *   @0xc2f18 ble 0xc2f5c <_ZN11CBackground18GenerateBitmapDataEv+0x1bc>
 *   @0xc2f1c sxth r2, r3
 *   @0xc2f20 mov r1, r5
 *   @0xc2f24 add r6, r6, #1
 *   @0xc2f28 lsl r2, r2, #2
 *   @0xc2f2c bl 0xb65bc <memcpy@plt>
 *   @0xc2f30 ldr r2, [r4, #0x14]
 *   @0xc2f34 ldr r0, [sp, #0xc]
 *   @0xc2f38 ldr r1, [sp, #0x8]
 *   @0xc2f3c ldrh r3, [r2, #4]
 *   @0xc2f40 ldrsh r2, [r2, #6]
 *   @0xc2f44 add r0, r0, r1
 *   @0xc2f48 str r0, [sp, #0xc]
 *   @0xc2f4c cmp r2, r6
 *   @0xc2f50 sxth r2, r3
 *   @0xc2f54 add r5, r5, r2, lsl #2
 *   @0xc2f58 bgt 0xc2f1c <_ZN11CBackground18GenerateBitmapDataEv+0x17c>
 *   @0xc2f5c ldr r3, [r7]
 *   @0xc2f60 mov r1, r10
 *   @0xc2f64 mov r0, r7
 *   @0xc2f68 ldr r3, [r3, #0x28]
 *   @0xc2f6c blx r3
 *   @0xc2f70 mov r0, r9
 *   @0xc2f74 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc2f78 mov r0, #24
 *   @0xc2f7c bl 0x27c524 <_Znwj>
 *   @0xc2f80 mov r3, #0
 *   @0xc2f84 mov r2, r3
 *   @0xc2f88 mov r1, r7
 *   @0xc2f8c str r3, [sp]
 *   @0xc2f90 mov r5, r0
 *   @0xc2f94 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi>
 *   @0xc2f98 ldr r3, [r7]
 *   @0xc2f9c mov r0, r7
 *   @0xc2fa0 str r5, [r4, #0x10]
 *   @0xc2fa4 ldr r3, [r3, #0x4]
 *   @0xc2fa8 blx r3
 *   @0xc2fac ldr r3, [r4, #0x14]
 *   @0xc2fb0 cmp r3, #0
 *   @0xc2fb4 beq 0xc3014 <_ZN11CBackground18GenerateBitmapDataEv+0x274>
 *   @0xc2fb8 ldrb r3, [r4, #0x18]
 *   @0xc2fbc mov r0, r4
 *   @0xc2fc0 cmp r3, #0
 *   @0xc2fc4 streq r3, [r4, #0x14]
 *   @0xc2fc8 bl 0xc1e60 <_ZN11CBackground11InitTextureEv>
 *   @0xc2fcc mov r0, r4
 *   @0xc2fd0 bl 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv>
 *   @0xc2fd4 ldr r3, [r4, #0x14]
 *   @0xc2fd8 cmp r3, #0
 *   @0xc2fdc beq 0xc300c <_ZN11CBackground18GenerateBitmapDataEv+0x26c>
 *   @0xc2fe0 ldrh r2, [r3, #14]
 *   @0xc2fe4 uxth r8, r8
 *   @0xc2fe8 ldrh r1, [r3, #12]
 *   @0xc2fec mul r1, r1, r8
 *   @0xc2ff0 mul r8, r2, r8
 *   @0xc2ff4 uxth r1, r1
 *   @0xc2ff8 strh r1, [r3, #12]
 *   @0xc2ffc strh r1, [r3, #16]
 *   @0xc3000 uxth r2, r8
 *   @0xc3004 strh r2, [r3, #14]
 *   @0xc3008 strh r2, [r3, #18]
 *   @0xc300c mov r0, #1
 *   @0xc3010 b 0xc2dbc <_ZN11CBackground18GenerateBitmapDataEv+0x1c>
 *   @0xc3014 mov r0, r4
 *   @0xc3018 bl 0xc1e60 <_ZN11CBackground11InitTextureEv>
 *   @0xc301c mov r0, r4
 *   @0xc3020 bl 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv>
 *   @0xc3024 b 0xc300c <_ZN11CBackground18GenerateBitmapDataEv+0x26c>
 *   @0xc3028 eorseq r10, r2, r0, asr r11
 *
 * ══ §23/46 IBuffer::Poke(int, eBuffer_Type, RValue*)  0xcbff4  size 652  163 条（0xcbff4..0xcc280）
 * @func 0xcbff4 0xcc280  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Poke(int, eBuffer_Type, RValue*)+0xac×3 / YYGetInt32(RValue const*, int)×3 / YYGetString(RValue const*, int)×2 / 0xb6538×2 / YYGetUint32(RValue const*, int)×2 / YYGetFloat(RValue const*, int) / YYGetInt64(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x-8×5 / 0x10×4 / 0x1×3 / 0x18×2 / 0xc×2 / 0x20×2 / 0x-1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcbff4 push {r4, r5, r6, r7, lr}
 *   @0xcbff8 subs r4, r1, #0
 *   @0xcbffc sub sp, sp, #12
 *   @0xcc000 mov r6, r0
 *   @0xcc004 blt 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcc008 sub r2, r2, #1
 *   @0xcc00c cmp r2, #12
 *   @0xcc010 addls pc, pc, r2, lsl #2
 *   @0xcc014 b 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcc018 b 0xcc04c <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x58>
 *   @0xcc01c b 0xcc04c <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x58>
 *   @0xcc020 b 0xcc154 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x160>
 *   @0xcc024 b 0xcc170 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x17c>
 *   @0xcc028 b 0xcc18c <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x198>
 *   @0xcc02c b 0xcc1a8 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x1b4>
 *   @0xcc030 b 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcc034 b 0xcc1c4 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x1d0>
 *   @0xcc038 b 0xcc1e0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x1ec>
 *   @0xcc03c b 0xcc1fc <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x208>
 *   @0xcc040 b 0xcc228 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x234>
 *   @0xcc044 b 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcc048 b 0xcc0a8 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xb4>
 *   @0xcc04c ldr r2, [r0, #0x18]
 *   @0xcc050 cmp r2, #2
 *   @0xcc054 ldr r2, [r0, #0x10]
 *   @0xcc058 beq 0xcc148 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x154>
 *   @0xcc05c cmp r4, r2
 *   @0xcc060 bge 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcc064 mov r0, r3
 *   @0xcc068 mov r1, #0
 *   @0xcc06c ldr r5, [r6, #0xc]
 *   @0xcc070 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcc074 add r3, r4, #1
 *   @0xcc078 cmn r3, #1
 *   @0xcc07c strb r0, [r5, r4]
 *   @0xcc080 ldr r2, [r6, #0x10]
 *   @0xcc084 ldreq r3, [r6, #0x1c]
 *   @0xcc088 ldr r1, [r6, #0x20]
 *   @0xcc08c cmp r3, r1
 *   @0xcc090 movlt r3, r1
 *   @0xcc094 cmp r3, r2
 *   @0xcc098 strle r3, [r6, #0x20]
 *   @0xcc09c strgt r2, [r6, #0x20]
 *   @0xcc0a0 add sp, sp, #12
 *   @0xcc0a4 pop {r4, r5, r6, r7, pc}
 *   @0xcc0a8 mov r0, r3
 *   @0xcc0ac mov r1, #0
 *   @0xcc0b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xcc0b4 mov r5, r0
 *   @0xcc0b8 bl 0xb6538 <strlen@plt>
 *   @0xcc0bc mov r12, r0
 *   @0xcc0c0 ldr r1, [r6, #0x18]
 *   @0xcc0c4 ldr r2, [r6, #0x10]
 *   @0xcc0c8 cmp r1, #2
 *   @0xcc0cc beq 0xcc138 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x144>
 *   @0xcc0d0 rsb r3, r12, r2
 *   @0xcc0d4 cmp r4, r3
 *   @0xcc0d8 bgt 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcc0dc add r0, r4, r12
 *   @0xcc0e0 ldr r7, [r6, #0x20]
 *   @0xcc0e4 cmn r0, #1
 *   @0xcc0e8 ldr r3, [r6, #0xc]
 *   @0xcc0ec ldreq r0, [r6, #0x1c]
 *   @0xcc0f0 add r3, r3, r4
 *   @0xcc0f4 cmp r0, r7
 *   @0xcc0f8 movlt r0, r7
 *   @0xcc0fc cmp r0, r2
 *   @0xcc100 strle r0, [r6, #0x20]
 *   @0xcc104 strgt r2, [r6, #0x20]
 *   @0xcc108 cmp r1, #2
 *   @0xcc10c beq 0xcc244 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x250>
 *   @0xcc110 cmp r12, #0
 *   @0xcc114 addgt r1, r3, r12
 *   @0xcc118 ble 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcc11c ldrb r2, [r5], #1
 *   @0xcc120 strb r2, [r3], #1
 *   @0xcc124 cmp r3, r1
 *   @0xcc128 bne 0xcc11c <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x128>
 *   @0xcc12c add sp, sp, #12
 *   @0xcc130 pop {r4, r5, r6, r7, pc}
 *   @0xcc134 rsb r4, r2, r4
 *   @0xcc138 cmp r4, r2
 *   @0xcc13c bge 0xcc134 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x140>
 *   @0xcc140 b 0xcc0dc <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xe8>
 *   @0xcc144 rsb r4, r2, r4
 *   @0xcc148 cmp r4, r2
 *   @0xcc14c bge 0xcc144 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x150>
 *   @0xcc150 b 0xcc064 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x70>
 *   @0xcc154 mov r0, r3
 *   @0xcc158 mov r1, #0
 *   @0xcc15c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xcc160 add r5, sp, #8
 *   @0xcc164 mov r12, #2
 *   @0xcc168 strh r0, [r5, #-8]!
 *   @0xcc16c b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc>
 *   @0xcc170 mov r0, r3
 *   @0xcc174 mov r1, #0
 *   @0xcc178 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcc17c add r5, sp, #8
 *   @0xcc180 mov r12, #2
 *   @0xcc184 strh r0, [r5, #-8]!
 *   @0xcc188 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc>
 *   @0xcc18c mov r0, r3
 *   @0xcc190 mov r1, #0
 *   @0xcc194 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xcc198 add r5, sp, #8
 *   @0xcc19c mov r12, #4
 *   @0xcc1a0 str r0, [r5, #-0x8]!
 *   @0xcc1a4 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc>
 *   @0xcc1a8 mov r0, r3
 *   @0xcc1ac mov r1, #0
 *   @0xcc1b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcc1b4 add r5, sp, #8
 *   @0xcc1b8 mov r12, #4
 *   @0xcc1bc str r0, [r5, #-0x8]!
 *   @0xcc1c0 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc>
 *   @0xcc1c4 mov r0, r3
 *   @0xcc1c8 mov r1, #0
 *   @0xcc1cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xcc1d0 add r5, sp, #8
 *   @0xcc1d4 mov r12, #4
 *   @0xcc1d8 str r0, [r5, #-0x8]!
 *   @0xcc1dc b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc>
 *   @0xcc1e0 mov r0, r3
 *   @0xcc1e4 mov r1, #0
 *   @0xcc1e8 bl 0xcea30 <_Z10YYGetInt64PK6RValuei>
 *   @0xcc1ec add r5, sp, #8
 *   @0xcc1f0 mov r12, #8
 *   @0xcc1f4 strd r0, r1, [r5, #-8]!
 *   @0xcc1f8 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc>
 *   @0xcc1fc mov r0, r3
 *   @0xcc200 mov r1, #0
 *   @0xcc204 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0xcc208 cmp r0, #0
 *   @0xcc20c addne r5, sp, #8
 *   @0xcc210 addeq r5, sp, #8
 *   @0xcc214 movne r12, #1
 *   @0xcc218 moveq r12, #1
 *   @0xcc21c strbne r12, [r5, #-0x8]!
 *   @0xcc220 strbeq r0, [r5, #-0x8]!
 *   @0xcc224 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc>
 *   @0xcc228 mov r0, r3
 *   @0xcc22c mov r1, #0
 *   @0xcc230 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xcc234 mov r5, r0
 *   @0xcc238 bl 0xb6538 <strlen@plt>
 *   @0xcc23c add r12, r0, #1
 *   @0xcc240 b 0xcc0c0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xcc>
 *   @0xcc244 cmp r12, #0
 *   @0xcc248 ble 0xcc0a0 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcc24c add r12, r5, r12
 *   @0xcc250 ldrb r2, [r5], #1
 *   @0xcc254 add r4, r4, #1
 *   @0xcc258 add r3, r3, #1
 *   @0xcc25c strb r2, [r3, #-0x1]
 *   @0xcc260 ldr r2, [r6, #0x10]
 *   @0xcc264 cmp r4, r2
 *   @0xcc268 ldrge r3, [r6, #0xc]
 *   @0xcc26c movge r4, #0
 *   @0xcc270 cmp r5, r12
 *   @0xcc274 bne 0xcc250 <_ZN7IBuffer4PokeEi12eBuffer_TypeP6RValue+0x25c>
 *   @0xcc278 add sp, sp, #12
 *   @0xcc27c pop {r4, r5, r6, r7, pc}
 *
 * ══ §24/46 F_ArraySet2DPre(RValue&, CInstance*, CInstance*, int, RValue*)  0x112f4c  size 652  163 条（0x112f4c..0x1131d8）
 * @func 0x112f4c 0x1131d8  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYFree(void const*)×3 / operator delete(void*)×3 / YYGetInt32(RValue const*, int)×2 / SET_RValue_Array(RValue*, RValue*, int) / GetContextStackTop() / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0x30×7 / 0x8×6 / 0x4×6 / 0xc×5 / 0x3c×2 / 0x18×1 / 0x25c×1 / 0x250×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x112f4c cmp r3, #4
 *   @0x112f50 push {r3, r4, r5, r6, r7, lr}
 *   @0x112f54 mov r5, r0
 *   @0x112f58 ldr r4, [sp, #0x18]
 *   @0x112f5c beq 0x112f8c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x112f60 ldr r3, [r4, #0xc]
 *   @0x112f64 cmp r3, #2
 *   @0x112f68 beq 0x112f7c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x112f6c ldr r0, [pc, #0x25c]
 *   @0x112f70 pop {r3, r4, r5, r6, r7, lr}
 *   @0x112f74 add r0, pc, r0
 *   @0x112f78 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x112f7c ldr r0, [pc, #0x250]
 *   @0x112f80 pop {r3, r4, r5, r6, r7, lr}
 *   @0x112f84 add r0, pc, r0
 *   @0x112f88 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x112f8c ldr r6, [r4, #0xc]
 *   @0x112f90 cmp r6, #2
 *   @0x112f94 bne 0x112f6c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x112f98 ldr r3, [r4]
 *   @0x112f9c cmp r3, #0
 *   @0x112fa0 beq 0x112f7c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x112fa4 mov r1, #1
 *   @0x112fa8 mov r0, r4
 *   @0x112fac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x112fb0 mov r1, r6
 *   @0x112fb4 mov r7, r0
 *   @0x112fb8 mov r0, r4
 *   @0x112fbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x112fc0 mov r2, #32000
 *   @0x112fc4 add r1, r4, #48
 *   @0x112fc8 mla r2, r2, r7, r0
 *   @0x112fcc mov r0, r4
 *   @0x112fd0 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x112fd4 ldr r2, [r5, #0xc]
 *   @0x112fd8 bic r3, r2, #-16777216
 *   @0x112fdc cmp r3, #1
 *   @0x112fe0 beq 0x113084 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x112fe4 cmp r3, #2
 *   @0x112fe8 bne 0x113010 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x112fec sub r3, r2, #1
 *   @0x112ff0 bic r3, r3, #-16777216
 *   @0x112ff4 bic r3, r3, #3
 *   @0x112ff8 cmp r3, #0
 *   @0x112ffc beq 0x11316c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x113000 mov r2, #0
 *   @0x113004 mov r3, #5
 *   @0x113008 str r2, [r5, #0x8]
 *   @0x11300c str r3, [r5, #0xc]
 *   @0x113010 ldr r3, [r4, #0x3c]
 *   @0x113014 mov r1, #0
 *   @0x113018 ldr r2, [r4, #0x38]
 *   @0x11301c str r1, [r5]
 *   @0x113020 str r3, [r5, #0xc]
 *   @0x113024 ldr r3, [r4, #0x3c]
 *   @0x113028 str r2, [r5, #0x8]
 *   @0x11302c bic r3, r3, #-16777216
 *   @0x113030 cmp r3, #14
 *   @0x113034 addls pc, pc, r3, lsl #2
 *   @0x113038 b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x11303c b 0x1130b8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x113040 b 0x113118 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x113044 b 0x1130ec <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x113048 b 0x113078 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x11304c b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x113050 b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x113054 b 0x1130c8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x113058 b 0x113078 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x11305c b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x113060 b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x113064 b 0x1130b8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x113068 b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x11306c b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x113070 b 0x1130b8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x113074 b 0x113078 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x113078 ldr r3, [r4, #0x30]
 *   @0x11307c str r3, [r5]
 *   @0x113080 pop {r3, r4, r5, r6, r7, pc}
 *   @0x113084 ldr r6, [r5]
 *   @0x113088 cmp r6, #0
 *   @0x11308c beq 0x1130ac <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x113090 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x113094 ldr r7, [r6, #0x4]
 *   @0x113098 sub r7, r7, #1
 *   @0x11309c str r7, [r6, #0x4]
 *   @0x1130a0 cmp r7, #0
 *   @0x1130a4 beq 0x113134 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x1130a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1130ac mov r3, #0
 *   @0x1130b0 str r3, [r5]
 *   @0x1130b4 b 0x113010 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x1130b8 ldr r2, [r4, #0x30]
 *   @0x1130bc ldr r3, [r4, #0x34]
 *   @0x1130c0 stm r5, {r2, r3}
 *   @0x1130c4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1130c8 ldr r3, [r4, #0x30]
 *   @0x1130cc str r3, [r5]
 *   @0x1130d0 ldr r3, [r4, #0x30]
 *   @0x1130d4 cmp r3, #0
 *   @0x1130d8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1130dc bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1130e0 ldr r1, [r4, #0x30]
 *   @0x1130e4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1130e8 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1130ec ldr r3, [r4, #0x30]
 *   @0x1130f0 cmp r3, #0
 *   @0x1130f4 str r3, [r5]
 *   @0x1130f8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1130fc ldr r1, [r3, #0x8]
 *   @0x113100 ldr r2, [r3]
 *   @0x113104 cmp r1, #0
 *   @0x113108 streq r5, [r3, #0x8]
 *   @0x11310c add r2, r2, #1
 *   @0x113110 str r2, [r3]
 *   @0x113114 pop {r3, r4, r5, r6, r7, pc}
 *   @0x113118 ldr r3, [r4, #0x30]
 *   @0x11311c cmp r3, #0
 *   @0x113120 ldrne r2, [r3, #0x4]
 *   @0x113124 addne r2, r2, #1
 *   @0x113128 strne r2, [r3, #0x4]
 *   @0x11312c b 0x11307c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x113130 pop {r3, r4, r5, r6, r7, pc}
 *   @0x113134 ldr r0, [r6]
 *   @0x113138 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x11313c str r7, [r6]
 *   @0x113140 str r7, [r6, #0x8]
 *   @0x113144 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x113148 ldr r7, [r6, #0x4]
 *   @0x11314c sub r7, r7, #1
 *   @0x113150 str r7, [r6, #0x4]
 *   @0x113154 cmp r7, #0
 *   @0x113158 beq 0x113178 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x11315c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x113160 mov r0, r6
 *   @0x113164 bl 0x27d1d0 <_ZdlPv>
 *   @0x113168 b 0x1130a8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x11316c mov r0, r5
 *   @0x113170 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x113174 b 0x113000 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x113178 ldr r0, [r6]
 *   @0x11317c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x113180 str r7, [r6]
 *   @0x113184 str r7, [r6, #0x8]
 *   @0x113188 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x11318c ldr r7, [r6, #0x4]
 *   @0x113190 sub r7, r7, #1
 *   @0x113194 str r7, [r6, #0x4]
 *   @0x113198 cmp r7, #0
 *   @0x11319c bne 0x1131c0 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x1131a0 ldr r0, [r6]
 *   @0x1131a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1131a8 mov r0, r6
 *   @0x1131ac str r7, [r6]
 *   @0x1131b0 str r7, [r6, #0x8]
 *   @0x1131b4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1131b8 mov r0, r6
 *   @0x1131bc bl 0x27d1d0 <_ZdlPv>
 *   @0x1131c0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1131c4 mov r0, r6
 *   @0x1131c8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1131cc b 0x11315c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x1131d0 .word 0x00225fb4
 *   @0x1131d4 .word 0x00225fd0
 *
 * ══ §25/46 IO_Render()  0x18d488  size 652  163 条（0x18d488..0x18d714）
 * @func 0x18d488 0x18d714  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18d498→0x534660, 0x18d4a0→0x534658, 0x18d4ec→0x3f50d0, 0x18d4f0→0x3f50cc, 0x18d560→0x3f26c0, 0x18d568→0x3f26bc, 0x18d6cc→0x3f26bc, 0x18d6dc→0x3f26c0
 * 调用序列: IO_Render()+0x238 / GraphicsPerf::BeginDebugDraw() / Graphics::AllocVerts(ePrimType, void*, int, int) / Get_FullScreenOffset(int&, int&, int&, int&) / IO_Render()+0x234 / GraphicsPerf::EndDebugDraw()
 * 字段偏移 top8: 0x25c×2 / 0x-2c×2 / 0x210×2 / 0x258×1 / 0x1a4×1 / 0x1a0×1 / 0x-80×1 / 0x-84×1
 * VFP 指令 51 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d488 push {r4, r5, r6, r7, lr}
 *   @0x18d48c vpush {d8}
 *   @0x18d490 sub sp, sp, #20
 *   @0x18d494 ldr r5, [pc, #0x25c]
 *   @0x18d498 ldr r2, [pc, #0x25c]
 *   @0x18d49c add r5, pc, r5
 *   @0x18d4a0 ldr r3, [pc, #0x258]
 *   @0x18d4a4 ldr r7, [r5, r2]
 *   @0x18d4a8 ldr r6, [r5, r3]
 *   @0x18d4ac ldr r0, [r7]
 *   @0x18d4b0 ldr r2, [r6]
 *   @0x18d4b4 cmp r0, #0
 *   @0x18d4b8 ble 0x18d6c0 <_Z9IO_Renderv+0x238>
 *   @0x18d4bc mov r3, #0
 *   @0x18d4c0 add r2, r2, #44
 *   @0x18d4c4 mov r4, r3
 *   @0x18d4c8 ldrh r1, [r2, #-44]
 *   @0x18d4cc add r3, r3, #1
 *   @0x18d4d0 cmp r3, r0
 *   @0x18d4d4 add r2, r2, #44
 *   @0x18d4d8 ubfx r1, r1, #0x1, #0x1
 *   @0x18d4dc add r4, r4, r1
 *   @0x18d4e0 bne 0x18d4c8 <_Z9IO_Renderv+0x40>
 *   @0x18d4e4 cmp r4, #0
 *   @0x18d4e8 beq 0x18d6c0 <_Z9IO_Renderv+0x238>
 *   @0x18d4ec ldr r2, [pc, #0x210]
 *   @0x18d4f0 ldr r3, [pc, #0x210]
 *   @0x18d4f4 ldr r2, [r5, r2]
 *   @0x18d4f8 vldr s16, [r2]
 *   @0x18d4fc ldr r3, [r5, r3]
 *   @0x18d500 vldr s17, [r3]
 *   @0x18d504 vmov r3, s16
 *   @0x18d508 cmn r3, #1
 *   @0x18d50c beq 0x18d6dc <_Z9IO_Renderv+0x254>
 *   @0x18d510 vmov r3, s17
 *   @0x18d514 cmn r3, #1
 *   @0x18d518 beq 0x18d6cc <_Z9IO_Renderv+0x244>
 *   @0x18d51c bl 0x17b114 <_ZN12GraphicsPerf14BeginDebugDrawEv>
 *   @0x18d520 add r3, r4, r4, lsl #1
 *   @0x18d524 mov r1, #0
 *   @0x18d528 mov r2, #24
 *   @0x18d52c lsl r3, r3, #1
 *   @0x18d530 mov r0, #4
 *   @0x18d534 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x18d538 add r2, sp, #8
 *   @0x18d53c add r1, sp, #4
 *   @0x18d540 add r3, sp, #12
 *   @0x18d544 mov r4, r0
 *   @0x18d548 mov r0, sp
 *   @0x18d54c bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x18d550 ldr r7, [r7]
 *   @0x18d554 ldr r2, [r6]
 *   @0x18d558 cmp r7, #0
 *   @0x18d55c ble 0x18d6bc <_Z9IO_Renderv+0x234>
 *   @0x18d560 ldr r0, [pc, #0x1a4]
 *   @0x18d564 vldr s5, [sp]
 *   @0x18d568 ldr r3, [pc, #0x1a0]
 *   @0x18d56c vldr s6, [sp, #4]
 *   @0x18d570 add r2, r2, #44
 *   @0x18d574 mov r12, #1056964608
 *   @0x18d578 ldr r6, [r5, r0]
 *   @0x18d57c mov r1, #0
 *   @0x18d580 ldr lr, [r5, r3]
 *   @0x18d584 mvn r0, #0
 *   @0x18d588 mov r3, #0
 *   @0x18d58c ldr r5, [r6]
 *   @0x18d590 vmov r6, s5
 *   @0x18d594 ldr lr, [lr]
 *   @0x18d598 sub r6, r5, r6, lsl #1
 *   @0x18d59c vmov r5, s6
 *   @0x18d5a0 vmov s3, r6
 *   @0x18d5a4 sub r5, lr, r5, lsl #1
 *   @0x18d5a8 vmov s4, r5
 *   @0x18d5ac ldrh lr, [r2, #-44]
 *   @0x18d5b0 add r1, r1, #1
 *   @0x18d5b4 tst lr, #2
 *   @0x18d5b8 beq 0x18d6b0 <_Z9IO_Renderv+0x228>
 *   @0x18d5bc vldr s7, [r2, #-40]
 *   @0x18d5c0 vldr s8, [r2, #-32]
 *   @0x18d5c4 vcvt.f32.s32 s14, s16
 *   @0x18d5c8 vldr s9, [r2, #-36]
 *   @0x18d5cc vldr s10, [r2, #-28]
 *   @0x18d5d0 add r4, r4, #144
 *   @0x18d5d4 str r3, [r4, #-0x80]
 *   @0x18d5d8 str r0, [r4, #-0x84]
 *   @0x18d5dc str r3, [r4, #-0x7c]
 *   @0x18d5e0 str r12, [r4, #-0x88]
 *   @0x18d5e4 str r0, [r4, #-0x6c]
 *   @0x18d5e8 vcvt.f32.s32 s7, s7
 *   @0x18d5ec str r3, [r4, #-0x68]
 *   @0x18d5f0 str r3, [r4, #-0x64]
 *   @0x18d5f4 str r12, [r4, #-0x70]
 *   @0x18d5f8 str r0, [r4, #-0x54]
 *   @0x18d5fc str r3, [r4, #-0x50]
 *   @0x18d600 str r3, [r4, #-0x4c]
 *   @0x18d604 str r12, [r4, #-0x58]
 *   @0x18d608 vcvt.f32.s32 s8, s8
 *   @0x18d60c str r0, [r4, #-0x3c]
 *   @0x18d610 str r3, [r4, #-0x38]
 *   @0x18d614 str r3, [r4, #-0x34]
 *   @0x18d618 str r12, [r4, #-0x40]
 *   @0x18d61c str r0, [r4, #-0x24]
 *   @0x18d620 str r3, [r4, #-0x20]
 *   @0x18d624 str r3, [r4, #-0x1c]
 *   @0x18d628 vcvt.f32.s32 s15, s17
 *   @0x18d62c vcvt.f32.s32 s9, s9
 *   @0x18d630 vcvt.f32.s32 s10, s10
 *   @0x18d634 vdiv.f32 s7, s7, s14
 *   @0x18d638 vdiv.f32 s8, s8, s14
 *   @0x18d63c vdiv.f32 s9, s9, s15
 *   @0x18d640 vdiv.f32 s10, s10, s15
 *   @0x18d644 vcvt.f32.s32 s12, s5
 *   @0x18d648 vcvt.f32.s32 s15, s3
 *   @0x18d64c vcvt.f32.s32 s13, s6
 *   @0x18d650 vmov.f32 s14, s12
 *   @0x18d654 vcvt.f32.s32 s11, s4
 *   @0x18d658 vmla.f32 s14, s15, s7
 *   @0x18d65c vmla.f32 s12, s8, s15
 *   @0x18d660 vstr s14, [r4, #-144]
 *   @0x18d664 vstr s14, [r4, #-48]
 *   @0x18d668 vmov.f32 s15, s13
 *   @0x18d66c vstr s12, [r4, #-120]
 *   @0x18d670 vstr s12, [r4, #-96]
 *   @0x18d674 vstr s12, [r4, #-72]
 *   @0x18d678 vmla.f32 s15, s11, s9
 *   @0x18d67c vmla.f32 s13, s10, s11
 *   @0x18d680 vstr s15, [r4, #-140]
 *   @0x18d684 vstr s15, [r4, #-116]
 *   @0x18d688 vstr s13, [r4, #-92]
 *   @0x18d68c vstr s13, [r4, #-68]
 *   @0x18d690 vstr s13, [r4, #-44]
 *   @0x18d694 vstr s14, [r4, #-24]
 *   @0x18d698 vstr s15, [r4, #-20]
 *   @0x18d69c str r12, [r4, #-0x28]
 *   @0x18d6a0 str r0, [r4, #-0xc]
 *   @0x18d6a4 str r3, [r4, #-0x8]
 *   @0x18d6a8 str r3, [r4, #-0x4]
 *   @0x18d6ac str r12, [r4, #-0x10]
 *   @0x18d6b0 cmp r1, r7
 *   @0x18d6b4 add r2, r2, #44
 *   @0x18d6b8 bne 0x18d5ac <_Z9IO_Renderv+0x124>
 *   @0x18d6bc bl 0x17b3e4 <_ZN12GraphicsPerf12EndDebugDrawEv>
 *   @0x18d6c0 add sp, sp, #20
 *   @0x18d6c4 vpop {d8}
 *   @0x18d6c8 pop {r4, r5, r6, r7, pc}
 *   @0x18d6cc ldr r3, [pc, #0x3c]
 *   @0x18d6d0 ldr r3, [r5, r3]
 *   @0x18d6d4 vldr s17, [r3]
 *   @0x18d6d8 b 0x18d51c <_Z9IO_Renderv+0x94>
 *   @0x18d6dc ldr r3, [pc, #0x28]
 *   @0x18d6e0 ldr r3, [r5, r3]
 *   @0x18d6e4 vldr s16, [r3]
 *   @0x18d6e8 vmov r3, s17
 *   @0x18d6ec cmn r3, #1
 *   @0x18d6f0 bne 0x18d51c <_Z9IO_Renderv+0x94>
 *   @0x18d6f4 b 0x18d6cc <_Z9IO_Renderv+0x244>
 *   @0x18d6f8 .word 0x002647b4
 *   @0x18d6fc .word 0xffffdf00
 *   @0x18d700 .word 0xffffdf04
 *   @0x18d704 .word 0xffffdf18
 *   @0x18d708 .word 0xffffdf24
 *   @0x18d70c .word 0xffffe24c
 *   @0x18d710 .word 0xffffe250
 *
 * ══ §26/46 CVariableList::Alloc(RValue const*)  0x1f6cf4  size 652  163 条（0x1f6cf4..0x1f6f80）
 * @func 0x1f6cf4 0x1f6f80  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / HASH_RValue(RValue const*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / operator new(unsigned int)
 * 字段偏移 top8: 0x8×13 / 0x4×9 / 0x14×3 / 0xc×3 / 0x10×2 / 0x280×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f6cf4 ldr r3, [pc, #0x280]
 *   @0x1f6cf8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f6cfc ldr r3, [pc, r3]
 *   @0x1f6d00 mov r5, r0
 *   @0x1f6d04 ldr r4, [r3]
 *   @0x1f6d08 cmp r4, #0
 *   @0x1f6d0c beq 0x1f6ec4 <_ZN13CVariableList5AllocEPK6RValue+0x1d0>
 *   @0x1f6d10 ldr r2, [r4, #0x4]
 *   @0x1f6d14 add r7, r4, #8
 *   @0x1f6d18 str r2, [r3]
 *   @0x1f6d1c bl 0xcee94 <_Z11HASH_RValuePK6RValue>
 *   @0x1f6d20 ldr r2, [r4, #0x14]
 *   @0x1f6d24 bic r3, r2, #-16777216
 *   @0x1f6d28 cmp r3, #1
 *   @0x1f6d2c str r0, [r4, #0x28]
 *   @0x1f6d30 beq 0x1f6e08 <_ZN13CVariableList5AllocEPK6RValue+0x114>
 *   @0x1f6d34 cmp r3, #2
 *   @0x1f6d38 bne 0x1f6d60 <_ZN13CVariableList5AllocEPK6RValue+0x6c>
 *   @0x1f6d3c sub r2, r2, #1
 *   @0x1f6d40 bic r2, r2, #-16777216
 *   @0x1f6d44 bic r2, r2, #3
 *   @0x1f6d48 cmp r2, #0
 *   @0x1f6d4c beq 0x1f6ee0 <_ZN13CVariableList5AllocEPK6RValue+0x1ec>
 *   @0x1f6d50 mov r2, #0
 *   @0x1f6d54 mov r3, #5
 *   @0x1f6d58 str r2, [r4, #0x10]
 *   @0x1f6d5c str r3, [r4, #0x14]
 *   @0x1f6d60 ldr r3, [r5, #0xc]
 *   @0x1f6d64 mov r1, #0
 *   @0x1f6d68 ldr r2, [r5, #0x8]
 *   @0x1f6d6c str r1, [r4, #0x8]
 *   @0x1f6d70 str r3, [r4, #0x14]
 *   @0x1f6d74 ldr r3, [r5, #0xc]
 *   @0x1f6d78 str r2, [r4, #0x10]
 *   @0x1f6d7c bic r3, r3, #-16777216
 *   @0x1f6d80 cmp r3, #14
 *   @0x1f6d84 addls pc, pc, r3, lsl #2
 *   @0x1f6d88 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6d8c b 0x1f6e3c <_ZN13CVariableList5AllocEPK6RValue+0x148>
 *   @0x1f6d90 b 0x1f6e50 <_ZN13CVariableList5AllocEPK6RValue+0x15c>
 *   @0x1f6d94 b 0x1f6dc8 <_ZN13CVariableList5AllocEPK6RValue+0xd4>
 *   @0x1f6d98 b 0x1f6df8 <_ZN13CVariableList5AllocEPK6RValue+0x104>
 *   @0x1f6d9c b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6da0 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6da4 b 0x1f6e68 <_ZN13CVariableList5AllocEPK6RValue+0x174>
 *   @0x1f6da8 b 0x1f6df8 <_ZN13CVariableList5AllocEPK6RValue+0x104>
 *   @0x1f6dac b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6db0 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6db4 b 0x1f6e3c <_ZN13CVariableList5AllocEPK6RValue+0x148>
 *   @0x1f6db8 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6dbc b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6dc0 b 0x1f6e3c <_ZN13CVariableList5AllocEPK6RValue+0x148>
 *   @0x1f6dc4 b 0x1f6df8 <_ZN13CVariableList5AllocEPK6RValue+0x104>
 *   @0x1f6dc8 ldr r3, [r5]
 *   @0x1f6dcc cmp r3, #0
 *   @0x1f6dd0 str r3, [r4, #0x8]
 *   @0x1f6dd4 beq 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6dd8 ldr r1, [r3, #0x8]
 *   @0x1f6ddc ldr r2, [r3]
 *   @0x1f6de0 cmp r1, #0
 *   @0x1f6de4 streq r7, [r3, #0x8]
 *   @0x1f6de8 add r2, r2, #1
 *   @0x1f6dec str r2, [r3]
 *   @0x1f6df0 mov r0, r4
 *   @0x1f6df4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f6df8 ldr r3, [r5]
 *   @0x1f6dfc str r3, [r4, #0x8]
 *   @0x1f6e00 mov r0, r4
 *   @0x1f6e04 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f6e08 ldr r6, [r4, #0x8]
 *   @0x1f6e0c cmp r6, #0
 *   @0x1f6e10 beq 0x1f6e30 <_ZN13CVariableList5AllocEPK6RValue+0x13c>
 *   @0x1f6e14 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6e18 ldr r8, [r6, #0x4]
 *   @0x1f6e1c sub r8, r8, #1
 *   @0x1f6e20 str r8, [r6, #0x4]
 *   @0x1f6e24 cmp r8, #0
 *   @0x1f6e28 beq 0x1f6e8c <_ZN13CVariableList5AllocEPK6RValue+0x198>
 *   @0x1f6e2c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6e30 mov r3, #0
 *   @0x1f6e34 str r3, [r4, #0x8]
 *   @0x1f6e38 b 0x1f6d60 <_ZN13CVariableList5AllocEPK6RValue+0x6c>
 *   @0x1f6e3c ldm r5, {r2, r3}
 *   @0x1f6e40 mov r0, r4
 *   @0x1f6e44 str r2, [r4, #0x8]
 *   @0x1f6e48 str r3, [r4, #0xc]
 *   @0x1f6e4c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f6e50 ldr r3, [r5]
 *   @0x1f6e54 cmp r3, #0
 *   @0x1f6e58 ldrne r2, [r3, #0x4]
 *   @0x1f6e5c addne r2, r2, #1
 *   @0x1f6e60 strne r2, [r3, #0x4]
 *   @0x1f6e64 b 0x1f6dfc <_ZN13CVariableList5AllocEPK6RValue+0x108>
 *   @0x1f6e68 ldr r3, [r5]
 *   @0x1f6e6c str r3, [r4, #0x8]
 *   @0x1f6e70 ldr r3, [r5]
 *   @0x1f6e74 cmp r3, #0
 *   @0x1f6e78 beq 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6e7c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f6e80 ldr r1, [r5]
 *   @0x1f6e84 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f6e88 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc>
 *   @0x1f6e8c ldr r0, [r6]
 *   @0x1f6e90 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6e94 str r8, [r6]
 *   @0x1f6e98 str r8, [r6, #0x8]
 *   @0x1f6e9c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6ea0 ldr r8, [r6, #0x4]
 *   @0x1f6ea4 sub r8, r8, #1
 *   @0x1f6ea8 str r8, [r6, #0x4]
 *   @0x1f6eac cmp r8, #0
 *   @0x1f6eb0 beq 0x1f6eec <_ZN13CVariableList5AllocEPK6RValue+0x1f8>
 *   @0x1f6eb4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6eb8 mov r0, r6
 *   @0x1f6ebc bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6ec0 b 0x1f6e2c <_ZN13CVariableList5AllocEPK6RValue+0x138>
 *   @0x1f6ec4 mov r0, #44
 *   @0x1f6ec8 bl 0x27c524 <_Znwj>
 *   @0x1f6ecc mov r1, r5
 *   @0x1f6ed0 mov r4, r0
 *   @0x1f6ed4 bl 0x1f5b60 <_ZN9RVariableC2EPK6RValue>
 *   @0x1f6ed8 mov r0, r4
 *   @0x1f6edc pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f6ee0 mov r0, r7
 *   @0x1f6ee4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f6ee8 b 0x1f6d50 <_ZN13CVariableList5AllocEPK6RValue+0x5c>
 *   @0x1f6eec ldr r0, [r6]
 *   @0x1f6ef0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6ef4 str r8, [r6]
 *   @0x1f6ef8 str r8, [r6, #0x8]
 *   @0x1f6efc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6f00 ldr r8, [r6, #0x4]
 *   @0x1f6f04 sub r8, r8, #1
 *   @0x1f6f08 str r8, [r6, #0x4]
 *   @0x1f6f0c cmp r8, #0
 *   @0x1f6f10 beq 0x1f6f24 <_ZN13CVariableList5AllocEPK6RValue+0x230>
 *   @0x1f6f14 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6f18 mov r0, r6
 *   @0x1f6f1c bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6f20 b 0x1f6eb4 <_ZN13CVariableList5AllocEPK6RValue+0x1c0>
 *   @0x1f6f24 ldr r0, [r6]
 *   @0x1f6f28 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6f2c str r8, [r6]
 *   @0x1f6f30 str r8, [r6, #0x8]
 *   @0x1f6f34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6f38 ldr r8, [r6, #0x4]
 *   @0x1f6f3c sub r8, r8, #1
 *   @0x1f6f40 str r8, [r6, #0x4]
 *   @0x1f6f44 cmp r8, #0
 *   @0x1f6f48 bne 0x1f6f6c <_ZN13CVariableList5AllocEPK6RValue+0x278>
 *   @0x1f6f4c ldr r0, [r6]
 *   @0x1f6f50 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6f54 mov r0, r6
 *   @0x1f6f58 str r8, [r6]
 *   @0x1f6f5c str r8, [r6, #0x8]
 *   @0x1f6f60 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f6f64 mov r0, r6
 *   @0x1f6f68 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6f6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6f70 mov r0, r6
 *   @0x1f6f74 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6f78 b 0x1f6f14 <_ZN13CVariableList5AllocEPK6RValue+0x220>
 *   @0x1f6f7c andseq r10, pc, r8, lsr r1
 *
 * ══ §27/46 JS_Array_prototype_reverse(RValue&, CInstance*, CInstance*, int, RValue*)  0x24f97c  size 652  163 条（0x24f97c..0x24fc08）
 * @func 0x24f97c 0x24fc08  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Object_Put(YYObjectBase*, RValue*, char const*, bool)×4 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×3 / 0xb65c8×2 / JS_HasProperty(YYObjectBase*, char const*)×2 / FREE_RValue__Pre(RValue*)×2 / JS_DeleteProperty(YYObjectBase*, RValue*, char const*, bool)×2 / YYGetUint32(RValue const*, int) / 0xb65d4
 * 字段偏移 top8: 0x10×5 / 0x8×4 / 0xc×3 / 0x38×3 / 0x14×2 / 0x8c×2 / 0x48×2 / 0x34×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24f97c ldr r12, [pc, #0x278]
 *   @0x24f980 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24f984 ldr r12, [pc, r12]
 *   @0x24f988 sub sp, sp, #148
 *   @0x24f98c ldr r2, [pc, #0x26c]
 *   @0x24f990 ldr r3, [r12]
 *   @0x24f994 add r6, sp, #28
 *   @0x24f998 mov r5, #0
 *   @0x24f99c str r0, [sp, #0x10]
 *   @0x24f9a0 add r2, pc, r2
 *   @0x24f9a4 mov r0, r1
 *   @0x24f9a8 mov r4, r1
 *   @0x24f9ac mov r1, r6
 *   @0x24f9b0 str r12, [sp, #0x14]
 *   @0x24f9b4 mvn r8, #-16777216
 *   @0x24f9b8 str r3, [sp, #0x8c]
 *   @0x24f9bc str r5, [sp, #0x1c]
 *   @0x24f9c0 str r5, [sp, #0x20]
 *   @0x24f9c4 str r5, [sp, #0x24]
 *   @0x24f9c8 str r8, [sp, #0x28]
 *   @0x24f9cc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24f9d0 mov r0, r6
 *   @0x24f9d4 mov r1, r5
 *   @0x24f9d8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x24f9dc lsrs r12, r0, #1
 *   @0x24f9e0 str r12, [sp, #0x8]
 *   @0x24f9e4 beq 0x24fb60 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x24f9e8 ldr r9, [pc, #0x214]
 *   @0x24f9ec add r12, sp, #44
 *   @0x24f9f0 sub r0, r0, #1
 *   @0x24f9f4 str r12, [sp]
 *   @0x24f9f8 add r9, pc, r9
 *   @0x24f9fc add r12, sp, #60
 *   @0x24fa00 str r0, [sp, #0xc]
 *   @0x24fa04 add r7, sp, #76
 *   @0x24fa08 add r6, sp, #108
 *   @0x24fa0c str r12, [sp, #0x4]
 *   @0x24fa10 mov r11, r5
 *   @0x24fa14 b 0x24fa88 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x24fa18 eor r1, r10, #1
 *   @0x24fa1c and r1, r0, r1
 *   @0x24fa20 ands r1, r1, #255
 *   @0x24fa24 bne 0x24fba4 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x24fa28 eor r0, r0, #1
 *   @0x24fa2c and r2, r10, r0
 *   @0x24fa30 tst r2, #255
 *   @0x24fa34 bne 0x24fbcc <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x24fa38 ldr r3, [sp, #0x38]
 *   @0x24fa3c sub r3, r3, #1
 *   @0x24fa40 bic r3, r3, #-16777216
 *   @0x24fa44 bic r3, r3, #3
 *   @0x24fa48 cmp r3, #0
 *   @0x24fa4c beq 0x24fb98 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x24fa50 ldr r3, [sp, #0x48]
 *   @0x24fa54 mov r2, #5
 *   @0x24fa58 str r11, [sp, #0x34]
 *   @0x24fa5c sub r3, r3, #1
 *   @0x24fa60 str r2, [sp, #0x38]
 *   @0x24fa64 bic r3, r3, #-16777216
 *   @0x24fa68 str r11, [sp, #0x2c]
 *   @0x24fa6c bic r3, r3, #3
 *   @0x24fa70 cmp r3, #0
 *   @0x24fa74 beq 0x24fb48 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x24fa78 ldr r12, [sp, #0x8]
 *   @0x24fa7c add r5, r5, #1
 *   @0x24fa80 cmp r5, r12
 *   @0x24fa84 beq 0x24fb60 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x24fa88 ldr r12, [sp, #0xc]
 *   @0x24fa8c mov r1, #32
 *   @0x24fa90 mov r2, r9
 *   @0x24fa94 mov r0, r7
 *   @0x24fa98 rsb r3, r5, r12
 *   @0x24fa9c bl 0xb65c8 <snprintf@plt>
 *   @0x24faa0 mov r3, r5
 *   @0x24faa4 mov r1, #32
 *   @0x24faa8 mov r2, r9
 *   @0x24faac mov r0, r6
 *   @0x24fab0 bl 0xb65c8 <snprintf@plt>
 *   @0x24fab4 mov r0, r4
 *   @0x24fab8 add r1, sp, #44
 *   @0x24fabc mov r2, r7
 *   @0x24fac0 str r11, [sp, #0x2c]
 *   @0x24fac4 str r11, [sp, #0x30]
 *   @0x24fac8 str r11, [sp, #0x34]
 *   @0x24facc str r8, [sp, #0x38]
 *   @0x24fad0 str r11, [sp, #0x3c]
 *   @0x24fad4 str r11, [sp, #0x40]
 *   @0x24fad8 str r11, [sp, #0x44]
 *   @0x24fadc str r8, [sp, #0x48]
 *   @0x24fae0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24fae4 mov r2, r6
 *   @0x24fae8 mov r0, r4
 *   @0x24faec add r1, sp, #60
 *   @0x24faf0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24faf4 mov r1, r6
 *   @0x24faf8 mov r0, r4
 *   @0x24fafc bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x24fb00 mov r1, r7
 *   @0x24fb04 mov r10, r0
 *   @0x24fb08 mov r0, r4
 *   @0x24fb0c bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x24fb10 and r3, r0, r10
 *   @0x24fb14 ands r3, r3, #255
 *   @0x24fb18 beq 0x24fa18 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x24fb1c mov r0, r4
 *   @0x24fb20 add r1, sp, #60
 *   @0x24fb24 mov r2, r7
 *   @0x24fb28 mov r3, #0
 *   @0x24fb2c bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24fb30 mov r0, r4
 *   @0x24fb34 add r1, sp, #44
 *   @0x24fb38 mov r2, r6
 *   @0x24fb3c mov r3, #0
 *   @0x24fb40 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24fb44 b 0x24fa38 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24fb48 add r0, sp, #60
 *   @0x24fb4c add r5, r5, #1
 *   @0x24fb50 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24fb54 ldr r12, [sp, #0x8]
 *   @0x24fb58 cmp r5, r12
 *   @0x24fb5c bne 0x24fa88 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x24fb60 ldr r12, [sp, #0x10]
 *   @0x24fb64 mov r0, #6
 *   @0x24fb68 ldr r1, [sp, #0x8c]
 *   @0x24fb6c mov r3, #0
 *   @0x24fb70 str r4, [r12]
 *   @0x24fb74 ldr r12, [sp, #0x14]
 *   @0x24fb78 ldr r2, [r12]
 *   @0x24fb7c ldr r12, [sp, #0x10]
 *   @0x24fb80 cmp r1, r2
 *   @0x24fb84 str r0, [r12, #0xc]
 *   @0x24fb88 str r3, [r12, #0x8]
 *   @0x24fb8c bne 0x24fbf8 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x27c>
 *   @0x24fb90 add sp, sp, #148
 *   @0x24fb94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24fb98 add r0, sp, #44
 *   @0x24fb9c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24fba0 b 0x24fa50 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x24fba4 mov r0, r4
 *   @0x24fba8 add r1, sp, #44
 *   @0x24fbac mov r2, r6
 *   @0x24fbb0 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24fbb4 mov r0, r4
 *   @0x24fbb8 ldr r1, [sp, #0x10]
 *   @0x24fbbc mov r2, r7
 *   @0x24fbc0 mov r3, #1
 *   @0x24fbc4 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb>
 *   @0x24fbc8 b 0x24fa38 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24fbcc mov r3, r1
 *   @0x24fbd0 mov r0, r4
 *   @0x24fbd4 add r1, sp, #60
 *   @0x24fbd8 mov r2, r7
 *   @0x24fbdc bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24fbe0 mov r0, r4
 *   @0x24fbe4 ldr r1, [sp, #0x10]
 *   @0x24fbe8 mov r2, r6
 *   @0x24fbec mov r3, #1
 *   @0x24fbf0 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb>
 *   @0x24fbf4 b 0x24fa38 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24fbf8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x24fbfc andseq sp, r9, r12, asr #31
 *   @0x24fc00 andeq r0, lr, r12, asr #29
 *   @0x24fc04 andseq r6, r0, r8, ror #8
 *
 * ══ §28/46 logName(char const*)  0x27d9d8  size 652  163 条（0x27d9d8..0x27dc64）
 * @func 0x27d9d8 0x27dc64  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844×6 / 0xb68bc×6 / 0xb6850×6 / iffLogAddName(char const*, int*) / logName(char const*)+0x230 / logName(char const*)+0xfc / 0xb6538 / logName(char const*)+0x1c8
 * 字段偏移 top8: 0x4×15 / 0x8×6 / 0xc×3 / 0x23c×1 / 0x218×1 / 0x16c×1 / 0x12c×1 / 0xec×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d9d8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x27d9dc sub sp, sp, #12
 *   @0x27d9e0 mov r6, r0
 *   @0x27d9e4 mov r1, sp
 *   @0x27d9e8 bl 0x27d8c8 <_Z13iffLogAddNamePKcPi>
 *   @0x27d9ec cmp r0, #0
 *   @0x27d9f0 bne 0x27d9fc <_Z7logNamePKc+0x24>
 *   @0x27d9f4 add sp, sp, #12
 *   @0x27d9f8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x27d9fc ldr r5, [pc, #0x23c]
 *   @0x27da00 ldr r5, [pc, r5]
 *   @0x27da04 ldr r4, [r5]
 *   @0x27da08 ldr r3, [r4, #0xc]
 *   @0x27da0c cmp r3, #0
 *   @0x27da10 ble 0x27dc08 <_Z7logNamePKc+0x230>
 *   @0x27da14 ldr r7, [r4, #0x4]
 *   @0x27da18 add r2, r7, #4
 *   @0x27da1c cmp r3, r2
 *   @0x27da20 ble 0x27dad4 <_Z7logNamePKc+0xfc>
 *   @0x27da24 ldr r2, [pc, #0x218]
 *   @0x27da28 ldr r3, [r4]
 *   @0x27da2c add r2, pc, r2
 *   @0x27da30 ldr r0, [r2]
 *   @0x27da34 str r0, [r3, r7]
 *   @0x27da38 ldr r3, [r4, #0x4]
 *   @0x27da3c add r3, r3, #4
 *   @0x27da40 str r3, [r4, #0x4]
 *   @0x27da44 mov r0, r6
 *   @0x27da48 bl 0xb6538 <strlen@plt>
 *   @0x27da4c ldr r4, [r5]
 *   @0x27da50 ldr r3, [r4, #0xc]
 *   @0x27da54 cmp r3, #0
 *   @0x27da58 str r0, [sp, #0x4]
 *   @0x27da5c ble 0x27dba0 <_Z7logNamePKc+0x1c8>
 *   @0x27da60 ldr r7, [r4, #0x4]
 *   @0x27da64 add r2, r7, #4
 *   @0x27da68 cmp r3, r2
 *   @0x27da6c ble 0x27db5c <_Z7logNamePKc+0x184>
 *   @0x27da70 ldr r3, [r4]
 *   @0x27da74 ldr r0, [sp, #0x4]
 *   @0x27da78 str r0, [r3, r7]
 *   @0x27da7c ldr r3, [r4, #0x4]
 *   @0x27da80 add r3, r3, #4
 *   @0x27da84 str r3, [r4, #0x4]
 *   @0x27da88 ldr r4, [r5]
 *   @0x27da8c ldr r5, [sp, #0x4]
 *   @0x27da90 ldr r3, [r4, #0xc]
 *   @0x27da94 cmp r3, #0
 *   @0x27da98 ble 0x27dbd4 <_Z7logNamePKc+0x1fc>
 *   @0x27da9c ldr r7, [r4, #0x4]
 *   @0x27daa0 add r2, r5, r7
 *   @0x27daa4 cmp r3, r2
 *   @0x27daa8 ble 0x27db18 <_Z7logNamePKc+0x140>
 *   @0x27daac ldr r0, [r4]
 *   @0x27dab0 mov r2, r5
 *   @0x27dab4 mov r1, r6
 *   @0x27dab8 add r0, r0, r7
 *   @0x27dabc bl 0xb65bc <memcpy@plt>
 *   @0x27dac0 ldr r3, [r4, #0x4]
 *   @0x27dac4 add r5, r3, r5
 *   @0x27dac8 str r5, [r4, #0x4]
 *   @0x27dacc add sp, sp, #12
 *   @0x27dad0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x27dad4 ldr r1, [pc, #0x16c]
 *   @0x27dad8 ldr r0, [r4, #0x8]
 *   @0x27dadc add r1, pc, r1
 *   @0x27dae0 ldr r9, [r4]
 *   @0x27dae4 bl 0xb6844 <fopen@plt>
 *   @0x27dae8 mov r1, r7
 *   @0x27daec mov r2, #1
 *   @0x27daf0 mov r8, r0
 *   @0x27daf4 mov r0, r9
 *   @0x27daf8 mov r3, r8
 *   @0x27dafc bl 0xb68bc <fwrite@plt>
 *   @0x27db00 mov r0, r8
 *   @0x27db04 bl 0xb6850 <fclose@plt>
 *   @0x27db08 mov r3, #0
 *   @0x27db0c mov r7, r3
 *   @0x27db10 str r3, [r4, #0x4]
 *   @0x27db14 b 0x27da24 <_Z7logNamePKc+0x4c>
 *   @0x27db18 ldr r1, [pc, #0x12c]
 *   @0x27db1c ldr r0, [r4, #0x8]
 *   @0x27db20 add r1, pc, r1
 *   @0x27db24 ldr r9, [r4]
 *   @0x27db28 bl 0xb6844 <fopen@plt>
 *   @0x27db2c mov r1, r7
 *   @0x27db30 mov r2, #1
 *   @0x27db34 mov r8, r0
 *   @0x27db38 mov r0, r9
 *   @0x27db3c mov r3, r8
 *   @0x27db40 bl 0xb68bc <fwrite@plt>
 *   @0x27db44 mov r0, r8
 *   @0x27db48 bl 0xb6850 <fclose@plt>
 *   @0x27db4c mov r3, #0
 *   @0x27db50 mov r7, r3
 *   @0x27db54 str r3, [r4, #0x4]
 *   @0x27db58 b 0x27daac <_Z7logNamePKc+0xd4>
 *   @0x27db5c ldr r1, [pc, #0xec]
 *   @0x27db60 ldr r0, [r4, #0x8]
 *   @0x27db64 add r1, pc, r1
 *   @0x27db68 ldr r9, [r4]
 *   @0x27db6c bl 0xb6844 <fopen@plt>
 *   @0x27db70 mov r1, r7
 *   @0x27db74 mov r2, #1
 *   @0x27db78 mov r8, r0
 *   @0x27db7c mov r0, r9
 *   @0x27db80 mov r3, r8
 *   @0x27db84 bl 0xb68bc <fwrite@plt>
 *   @0x27db88 mov r0, r8
 *   @0x27db8c bl 0xb6850 <fclose@plt>
 *   @0x27db90 mov r3, #0
 *   @0x27db94 mov r7, r3
 *   @0x27db98 str r3, [r4, #0x4]
 *   @0x27db9c b 0x27da70 <_Z7logNamePKc+0x98>
 *   @0x27dba0 ldr r1, [pc, #0xac]
 *   @0x27dba4 ldr r0, [r4, #0x8]
 *   @0x27dba8 add r1, pc, r1
 *   @0x27dbac bl 0xb6844 <fopen@plt>
 *   @0x27dbb0 mov r1, #4
 *   @0x27dbb4 mov r2, #1
 *   @0x27dbb8 mov r4, r0
 *   @0x27dbbc mov r3, r0
 *   @0x27dbc0 add r0, sp, #4
 *   @0x27dbc4 bl 0xb68bc <fwrite@plt>
 *   @0x27dbc8 mov r0, r4
 *   @0x27dbcc bl 0xb6850 <fclose@plt>
 *   @0x27dbd0 b 0x27da88 <_Z7logNamePKc+0xb0>
 *   @0x27dbd4 ldr r1, [pc, #0x7c]
 *   @0x27dbd8 ldr r0, [r4, #0x8]
 *   @0x27dbdc add r1, pc, r1
 *   @0x27dbe0 bl 0xb6844 <fopen@plt>
 *   @0x27dbe4 mov r1, r5
 *   @0x27dbe8 mov r2, #1
 *   @0x27dbec mov r4, r0
 *   @0x27dbf0 mov r0, r6
 *   @0x27dbf4 mov r3, r4
 *   @0x27dbf8 bl 0xb68bc <fwrite@plt>
 *   @0x27dbfc mov r0, r4
 *   @0x27dc00 bl 0xb6850 <fclose@plt>
 *   @0x27dc04 b 0x27d9f4 <_Z7logNamePKc+0x1c>
 *   @0x27dc08 ldr r1, [pc, #0x4c]
 *   @0x27dc0c ldr r0, [r4, #0x8]
 *   @0x27dc10 add r1, pc, r1
 *   @0x27dc14 bl 0xb6844 <fopen@plt>
 *   @0x27dc18 mov r1, #4
 *   @0x27dc1c mov r2, #1
 *   @0x27dc20 mov r4, r0
 *   @0x27dc24 mov r3, r0
 *   @0x27dc28 ldr r0, [pc, #0x30]
 *   @0x27dc2c add r0, pc, r0
 *   @0x27dc30 bl 0xb68bc <fwrite@plt>
 *   @0x27dc34 mov r0, r4
 *   @0x27dc38 bl 0xb6850 <fclose@plt>
 *   @0x27dc3c b 0x27da44 <_Z7logNamePKc+0x6c>
 *   @0x27dc40 andseq r3, r7, r4, lsr #28
 *   @0x27dc44 andeq r9, sp, r8, asr #16
 *   @0x27dc48 ldrdeq r9, r10, [sp], -r0
 *   @0x27dc4c andeq r9, sp, r12, lsl #13
 *   @0x27dc50 andeq r9, sp, r8, asr #12
 *   @0x27dc54 andeq r9, sp, r4, lsl #12
 *   @0x27dc58 ldrdeq r9, r10, [sp], -r0
 *   @0x27dc5c muleq sp, r12, r5
 *   @0x27dc60 andeq r9, sp, r8, asr #12
 *
 * ══ §29/46 jpeg_idct_2x2  0x2c0fb4  size 652  163 条（0x2c0fb4..0x2c1240）
 * @func 0x2c0fb4 0x2c1240  size 652  163 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×5 / 0x50×4 / 0x8×4 / 0x14×4 / 0xc×4 / 0x10×3 / 0x4×3 / 0x70×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c0fb4 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2c0fb8 sub sp, sp, #88
 *   @0x2c0fbc add r6, sp, #24
 *   @0x2c0fc0 ldr r1, [r1, #0x50]
 *   @0x2c0fc4 ldr r0, [r0, #0x120]
 *   @0x2c0fc8 movw r11, #0xe8ee
 *   @0x2c0fcc str r3, [sp, #0x10]
 *   @0x2c0fd0 movw r7, #0xd746
 *   @0x2c0fd4 add r0, r0, #128
 *   @0x2c0fd8 movt r11, #0xffff
 *   @0x2c0fdc str r0, [sp, #0x8]
 *   @0x2c0fe0 movt r7, #0xffff
 *   @0x2c0fe4 str r6, [sp, #0x14]
 *   @0x2c0fe8 add r5, r2, #2
 *   @0x2c0fec add r4, r1, #4
 *   @0x2c0ff0 mov r12, r6
 *   @0x2c0ff4 str r7, [sp, #0xc]
 *   @0x2c0ff8 mov r0, #7
 *   @0x2c0ffc mov r3, #8
 *   @0x2c1000 str r11, [sp, #0x4]
 *   @0x2c1004 b 0x2c10c0 <jpeg_idct_2x2+0x10c>
 *   @0x2c1008 ldrh r6, [r2, #48]
 *   @0x2c100c cmp r6, #0
 *   @0x2c1010 beq 0x2c11b8 <jpeg_idct_2x2+0x204>
 *   @0x2c1014 ldrh r10, [r2, #112]
 *   @0x2c1018 ldrh r9, [r2, #80]
 *   @0x2c101c ldr r7, [r1, #0xa0]
 *   @0x2c1020 sxth r9, r9
 *   @0x2c1024 ldr r11, [r1, #0xe0]
 *   @0x2c1028 sxth r10, r10
 *   @0x2c102c sxth r6, r6
 *   @0x2c1030 sxth r8, r8
 *   @0x2c1034 mul r9, r7, r9
 *   @0x2c1038 ldrsh r7, [r5, #-2]
 *   @0x2c103c mul r10, r11, r10
 *   @0x2c1040 ldr r11, [r1, #0x60]
 *   @0x2c1044 mul r6, r11, r6
 *   @0x2c1048 movw r11, #0x1b37
 *   @0x2c104c mul r9, r11, r9
 *   @0x2c1050 ldr r11, [sp, #0x4]
 *   @0x2c1054 mla r9, r11, r10, r9
 *   @0x2c1058 ldr r10, [r4, #-0x4]
 *   @0x2c105c ldr r11, [r1, #0x20]
 *   @0x2c1060 mul r7, r10, r7
 *   @0x2c1064 ldr r10, [sp, #0xc]
 *   @0x2c1068 mul r8, r11, r8
 *   @0x2c106c movw r11, #0x73fc
 *   @0x2c1070 mla r9, r10, r6, r9
 *   @0x2c1074 lsl r7, r7, #15
 *   @0x2c1078 mla r8, r11, r8, r9
 *   @0x2c107c add r6, r7, r8
 *   @0x2c1080 rsb r8, r8, r7
 *   @0x2c1084 add r6, r6, #4096
 *   @0x2c1088 add r8, r8, #4096
 *   @0x2c108c asr r6, r6, #13
 *   @0x2c1090 asr r8, r8, #13
 *   @0x2c1094 str r6, [r12]
 *   @0x2c1098 str r8, [r12, #0x20]
 *   @0x2c109c cmp r0, #0
 *   @0x2c10a0 add r12, r12, #4
 *   @0x2c10a4 beq 0x2c10f8 <jpeg_idct_2x2+0x144>
 *   @0x2c10a8 sub r3, r3, #1
 *   @0x2c10ac add r5, r5, #2
 *   @0x2c10b0 add r2, r2, #2
 *   @0x2c10b4 add r4, r4, #4
 *   @0x2c10b8 add r1, r1, #4
 *   @0x2c10bc sub r0, r0, #1
 *   @0x2c10c0 bic r6, r3, #2
 *   @0x2c10c4 cmp r6, #4
 *   @0x2c10c8 beq 0x2c109c <jpeg_idct_2x2+0xe8>
 *   @0x2c10cc cmp r3, #2
 *   @0x2c10d0 beq 0x2c10f0 <jpeg_idct_2x2+0x13c>
 *   @0x2c10d4 ldrh r8, [r2, #16]
 *   @0x2c10d8 cmp r8, #0
 *   @0x2c10dc beq 0x2c1008 <jpeg_idct_2x2+0x54>
 *   @0x2c10e0 ldrh r10, [r2, #112]
 *   @0x2c10e4 ldrh r9, [r2, #80]
 *   @0x2c10e8 ldrh r6, [r2, #48]
 *   @0x2c10ec b 0x2c101c <jpeg_idct_2x2+0x68>
 *   @0x2c10f0 add r12, r12, #4
 *   @0x2c10f4 b 0x2c10a8 <jpeg_idct_2x2+0xf4>
 *   @0x2c10f8 movw r7, #0xe8ee
 *   @0x2c10fc movw r6, #0xd746
 *   @0x2c1100 movt r7, #0xffff
 *   @0x2c1104 movt r6, #0xffff
 *   @0x2c1108 add r3, sp, #24
 *   @0x2c110c movw r11, #0x1b37
 *   @0x2c1110 movw r10, #0x73fc
 *   @0x2c1114 ldr r12, [sp, #0x10]
 *   @0x2c1118 ldr r1, [r3, #0x4]
 *   @0x2c111c ldr r2, [r12, r0]
 *   @0x2c1120 cmp r1, #0
 *   @0x2c1124 ldr r12, [sp, #0x78]
 *   @0x2c1128 add r5, r2, r12
 *   @0x2c112c bne 0x2c11a8 <jpeg_idct_2x2+0x1f4>
 *   @0x2c1130 ldr r12, [r3, #0xc]
 *   @0x2c1134 cmp r12, #0
 *   @0x2c1138 beq 0x2c11f0 <jpeg_idct_2x2+0x23c>
 *   @0x2c113c ldr r4, [r3, #0x1c]
 *   @0x2c1140 ldr r9, [r3, #0x14]
 *   @0x2c1144 mul r9, r11, r9
 *   @0x2c1148 ldr r8, [r3], #32
 *   @0x2c114c mla r4, r7, r4, r9
 *   @0x2c1150 lsl r8, r8, #15
 *   @0x2c1154 mla r4, r6, r12, r4
 *   @0x2c1158 ldr r12, [sp, #0x8]
 *   @0x2c115c mla r1, r10, r1, r4
 *   @0x2c1160 add r9, r8, r1
 *   @0x2c1164 rsb r8, r1, r8
 *   @0x2c1168 add r9, r9, #524288
 *   @0x2c116c add r8, r8, #524288
 *   @0x2c1170 ubfx r9, r9, #0x14, #0xa
 *   @0x2c1174 ubfx r8, r8, #0x14, #0xa
 *   @0x2c1178 ldrb r1, [r12, r9]
 *   @0x2c117c ldr r12, [sp, #0x78]
 *   @0x2c1180 strb r1, [r2, r12]
 *   @0x2c1184 ldr r1, [sp, #0x8]
 *   @0x2c1188 ldrb r2, [r1, r8]
 *   @0x2c118c strb r2, [r5, #0x1]
 *   @0x2c1190 add r0, r0, #4
 *   @0x2c1194 cmp r0, #8
 *   @0x2c1198 bne 0x2c1114 <jpeg_idct_2x2+0x160>
 *   @0x2c119c add sp, sp, #88
 *   @0x2c11a0 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2c11a4 bx lr
 *   @0x2c11a8 ldr r4, [r3, #0x1c]
 *   @0x2c11ac ldr r9, [r3, #0x14]
 *   @0x2c11b0 ldr r12, [r3, #0xc]
 *   @0x2c11b4 b 0x2c1144 <jpeg_idct_2x2+0x190>
 *   @0x2c11b8 ldrh r9, [r2, #80]
 *   @0x2c11bc ldrh r10, [r2, #112]
 *   @0x2c11c0 cmp r9, #0
 *   @0x2c11c4 movne r6, r8
 *   @0x2c11c8 bne 0x2c101c <jpeg_idct_2x2+0x68>
 *   @0x2c11cc cmp r10, #0
 *   @0x2c11d0 bne 0x2c122c <jpeg_idct_2x2+0x278>
 *   @0x2c11d4 ldrsh r6, [r5, #-2]
 *   @0x2c11d8 ldr r7, [r4, #-0x4]
 *   @0x2c11dc mul r6, r7, r6
 *   @0x2c11e0 lsl r6, r6, #2
 *   @0x2c11e4 str r6, [r12]
 *   @0x2c11e8 str r6, [r12, #0x20]
 *   @0x2c11ec b 0x2c109c <jpeg_idct_2x2+0xe8>
 *   @0x2c11f0 ldr r9, [r3, #0x14]
 *   @0x2c11f4 ldr r4, [r3, #0x1c]
 *   @0x2c11f8 cmp r9, #0
 *   @0x2c11fc bne 0x2c1144 <jpeg_idct_2x2+0x190>
 *   @0x2c1200 cmp r4, #0
 *   @0x2c1204 bne 0x2c1238 <jpeg_idct_2x2+0x284>
 *   @0x2c1208 ldr r1, [r3], #32
 *   @0x2c120c ldr r12, [sp, #0x8]
 *   @0x2c1210 add r1, r1, #16
 *   @0x2c1214 ubfx r1, r1, #0x5, #0xa
 *   @0x2c1218 ldrb r1, [r12, r1]
 *   @0x2c121c ldr r12, [sp, #0x78]
 *   @0x2c1220 strb r1, [r2, r12]
 *   @0x2c1224 strb r1, [r5, #0x1]
 *   @0x2c1228 b 0x2c1190 <jpeg_idct_2x2+0x1dc>
 *   @0x2c122c mov r6, r8
 *   @0x2c1230 mov r9, r8
 *   @0x2c1234 b 0x2c101c <jpeg_idct_2x2+0x68>
 *   @0x2c1238 mov r12, r9
 *   @0x2c123c b 0x2c1144 <jpeg_idct_2x2+0x190>
 *
 * ══ §30/46 Extension_Finalize()  0xf6610  size 648  162 条（0xf6610..0xf6898）
 * @func 0xf6610 0xf6898  size 648  162 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×3 / CInstance::~CInstance()×2 / Error_Show(char const*, bool)×2 / Extension_Finalize()+0x1a4 / Script_Find(char const*) / Extension_Finalize()+0x150 / Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*) / CExtensionPackage::GetIncludesCount()
 * 字段偏移 top8: 0x24×6 / 0x18×3 / 0x20×3 / 0x4×3 / 0xc×2 / 0x6dc×2 / 0x8×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6610 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf6614 sub sp, sp, #1760
 *   @0xf6618 ldr r11, [pc, #0x264]
 *   @0xf661c sub sp, sp, #4
 *   @0xf6620 ldr r1, [pc, #0x260]
 *   @0xf6624 mov r10, #0
 *   @0xf6628 ldr r11, [pc, r11]
 *   @0xf662c str r10, [sp, #0x18]
 *   @0xf6630 ldr r1, [pc, r1]
 *   @0xf6634 str r10, [sp, #0x1c]
 *   @0xf6638 ldr r2, [r11]
 *   @0xf663c ldr r3, [r1]
 *   @0xf6640 cmp r2, r10
 *   @0xf6644 str r1, [sp, #0xc]
 *   @0xf6648 str r10, [sp, #0x20]
 *   @0xf664c str r10, [sp, #0x24]
 *   @0xf6650 str r3, [sp, #0x6dc]
 *   @0xf6654 ble 0xf67b4 <_Z18Extension_Finalizev+0x1a4>
 *   @0xf6658 ldr r2, [pc, #0x22c]
 *   @0xf665c add r8, sp, #296
 *   @0xf6660 add r9, sp, #40
 *   @0xf6664 add r2, pc, r2
 *   @0xf6668 str r2, [sp, #0x8]
 *   @0xf666c ldr r1, [sp, #0x8]
 *   @0xf6670 ldr r3, [r1, #0x4]
 *   @0xf6674 ldr r6, [r3, r10, lsl #2]
 *   @0xf6678 cmp r6, #0
 *   @0xf667c movne r4, #0
 *   @0xf6680 movne r5, r4
 *   @0xf6684 bne 0xf66ec <_Z18Extension_Finalizev+0xdc>
 *   @0xf6688 b 0xf678c <_Z18Extension_Finalizev+0x17c>
 *   @0xf668c mov r3, #5
 *   @0xf6690 str r5, [sp, #0x20]
 *   @0xf6694 str r5, [sp, #0x18]
 *   @0xf6698 str r3, [sp, #0x24]
 *   @0xf669c ldrb r3, [r7]
 *   @0xf66a0 cmp r3, #0
 *   @0xf66a4 beq 0xf66e0 <_Z18Extension_Finalizev+0xd0>
 *   @0xf66a8 mov r0, r7
 *   @0xf66ac bl 0x1e0610 <_Z11Script_FindPKc>
 *   @0xf66b0 cmp r0, #0
 *   @0xf66b4 blt 0xf6760 <_Z18Extension_Finalizev+0x150>
 *   @0xf66b8 add r3, sp, #16
 *   @0xf66bc add r7, sp, #24
 *   @0xf66c0 str r3, [sp, #0x4]
 *   @0xf66c4 mov r1, r8
 *   @0xf66c8 str r7, [sp]
 *   @0xf66cc mov r2, r8
 *   @0xf66d0 mov r3, #0
 *   @0xf66d4 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0xf66d8 cmp r0, #0
 *   @0xf66dc beq 0xf67bc <_Z18Extension_Finalizev+0x1ac>
 *   @0xf66e0 mov r0, r8
 *   @0xf66e4 bl 0x199320 <_ZN9CInstanceD2Ev>
 *   @0xf66e8 add r4, r4, #1
 *   @0xf66ec mov r0, r6
 *   @0xf66f0 bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv>
 *   @0xf66f4 cmp r4, r0
 *   @0xf66f8 bge 0xf678c <_Z18Extension_Finalizev+0x17c>
 *   @0xf66fc mov r1, r4
 *   @0xf6700 mov r0, r6
 *   @0xf6704 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi>
 *   @0xf6708 bl 0xf5010 <_ZN14CExtensionFile17GetFunction_FinalEv>
 *   @0xf670c subs r7, r0, #0
 *   @0xf6710 beq 0xf66e8 <_Z18Extension_Finalizev+0xd8>
 *   @0xf6714 mov r1, #0
 *   @0xf6718 mov r3, #0
 *   @0xf671c mov r2, r1
 *   @0xf6720 mov r0, r8
 *   @0xf6724 str r5, [sp]
 *   @0xf6728 str r5, [sp, #0x4]
 *   @0xf672c bl 0x1994dc <_ZN9CInstanceC2Effiib>
 *   @0xf6730 ldr r3, [sp, #0x24]
 *   @0xf6734 mov r2, #16
 *   @0xf6738 str r9, [sp, #0x14]
 *   @0xf673c sub r3, r3, #1
 *   @0xf6740 str r2, [sp, #0x10]
 *   @0xf6744 bic r3, r3, #-16777216
 *   @0xf6748 bic r3, r3, #3
 *   @0xf674c cmp r3, #0
 *   @0xf6750 bne 0xf668c <_Z18Extension_Finalizev+0x7c>
 *   @0xf6754 add r0, sp, #24
 *   @0xf6758 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xf675c b 0xf668c <_Z18Extension_Finalizev+0x7c>
 *   @0xf6760 mov r1, r7
 *   @0xf6764 mov r0, r6
 *   @0xf6768 bl 0xf5494 <_ZN17CExtensionPackage16FunctionFindNameEPKc>
 *   @0xf676c subs r1, r0, #0
 *   @0xf6770 beq 0xf682c <_Z18Extension_Finalizev+0x21c>
 *   @0xf6774 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf6778 add r3, sp, #24
 *   @0xf677c mov r1, #0
 *   @0xf6780 ldr r2, [sp, #0x14]
 *   @0xf6784 bl 0xf6344 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_>
 *   @0xf6788 b 0xf66e0 <_Z18Extension_Finalizev+0xd0>
 *   @0xf678c ldr r3, [r11]
 *   @0xf6790 add r10, r10, #1
 *   @0xf6794 cmp r3, r10
 *   @0xf6798 bgt 0xf666c <_Z18Extension_Finalizev+0x5c>
 *   @0xf679c ldr r3, [sp, #0x24]
 *   @0xf67a0 sub r3, r3, #1
 *   @0xf67a4 bic r3, r3, #-16777216
 *   @0xf67a8 bic r3, r3, #3
 *   @0xf67ac cmp r3, #0
 *   @0xf67b0 beq 0xf6870 <_Z18Extension_Finalizev+0x260>
 *   @0xf67b4 mov r0, #1
 *   @0xf67b8 b 0xf680c <_Z18Extension_Finalizev+0x1fc>
 *   @0xf67bc ldr r3, [pc, #0xcc]
 *   @0xf67c0 mov r1, #1
 *   @0xf67c4 ldr r3, [pc, r3]
 *   @0xf67c8 ldr r3, [r3]
 *   @0xf67cc ldr r0, [r3]
 *   @0xf67d0 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0xf67d4 ldr r3, [sp, #0x24]
 *   @0xf67d8 sub r3, r3, #1
 *   @0xf67dc bic r3, r3, #-16777216
 *   @0xf67e0 bic r3, r3, #3
 *   @0xf67e4 cmp r3, #0
 *   @0xf67e8 beq 0xf6864 <_Z18Extension_Finalizev+0x254>
 *   @0xf67ec mov r3, #0
 *   @0xf67f0 mov r2, #5
 *   @0xf67f4 str r3, [sp, #0x20]
 *   @0xf67f8 str r3, [sp, #0x18]
 *   @0xf67fc str r2, [sp, #0x24]
 *   @0xf6800 mov r0, r8
 *   @0xf6804 bl 0x199320 <_ZN9CInstanceD2Ev>
 *   @0xf6808 mov r0, #0
 *   @0xf680c ldr r1, [sp, #0xc]
 *   @0xf6810 ldr r2, [sp, #0x6dc]
 *   @0xf6814 ldr r3, [r1]
 *   @0xf6818 cmp r2, r3
 *   @0xf681c bne 0xf6880 <_Z18Extension_Finalizev+0x270>
 *   @0xf6820 add sp, sp, #1760
 *   @0xf6824 add sp, sp, #4
 *   @0xf6828 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf682c add r4, sp, #732
 *   @0xf6830 mov r2, #1024
 *   @0xf6834 mov r0, r4
 *   @0xf6838 bl 0xb65b0 <memset@plt>
 *   @0xf683c ldr r2, [pc, #0x50]
 *   @0xf6840 mov r0, r4
 *   @0xf6844 mov r3, r7
 *   @0xf6848 mov r1, #1024
 *   @0xf684c add r2, pc, r2
 *   @0xf6850 bl 0xb65c8 <snprintf@plt>
 *   @0xf6854 mov r0, r4
 *   @0xf6858 mov r1, #1
 *   @0xf685c bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0xf6860 b 0xf6800 <_Z18Extension_Finalizev+0x1f0>
 *   @0xf6864 mov r0, r7
 *   @0xf6868 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xf686c b 0xf67ec <_Z18Extension_Finalizev+0x1dc>
 *   @0xf6870 add r0, sp, #24
 *   @0xf6874 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xf6878 mov r0, #1
 *   @0xf687c b 0xf680c <_Z18Extension_Finalizev+0x1fc>
 *   @0xf6880 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xf6884 eoreq r7, pc, r12, lsl #16
 *   @0xf6888 eoreq r7, pc, r0, lsr #6
 *   @0xf688c eorseq r12, r8, r4, ror #31
 *   @0xf6890 eoreq r7, pc, r12, lsr #7
 *   @0xf6894 eoreq r1, r4, r4, lsl #3
 *
 * ══ §31/46 F_DsGridSet_release(RValue&, CInstance*, CInstance*, int, RValue*)  0x102ee4  size 648  162 条（0x102ee4..0x10316c）
 * @func 0x102ee4 0x10316c  size 648  162 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int)×3 / GetContextStackTop() / FREE_RValue__Pre(RValue*) / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0x4×17 / 0x8×7 / 0x30×7 / 0xc×3 / 0x3c×2 / 0x20×1 / 0x248×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x102ee4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x102ee8 mov r1, #0
 *   @0x102eec ldr r4, [sp, #0x20]
 *   @0x102ef0 mov r0, r4
 *   @0x102ef4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x102ef8 mov r1, #1
 *   @0x102efc mov r6, r0
 *   @0x102f00 mov r0, r4
 *   @0x102f04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x102f08 mov r1, #2
 *   @0x102f0c mov r5, r0
 *   @0x102f10 mov r0, r4
 *   @0x102f14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x102f18 ldr r3, [pc, #0x248]
 *   @0x102f1c ldr r3, [pc, r3]
 *   @0x102f20 ldr r3, [r3, #0x4]
 *   @0x102f24 ldr r3, [r3, r6, lsl #2]
 *   @0x102f28 ldm r3, {r6, r7}
 *   @0x102f2c mla r7, r7, r0, r5
 *   @0x102f30 add r5, r6, r7, lsl #4
 *   @0x102f34 ldr r2, [r5, #0xc]
 *   @0x102f38 bic r3, r2, #-16777216
 *   @0x102f3c cmp r3, #1
 *   @0x102f40 beq 0x102ff8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x102f44 cmp r3, #2
 *   @0x102f48 bne 0x102f70 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x102f4c sub r2, r2, #1
 *   @0x102f50 bic r2, r2, #-16777216
 *   @0x102f54 bic r2, r2, #3
 *   @0x102f58 cmp r2, #0
 *   @0x102f5c beq 0x1030cc <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x102f60 mov r2, #0
 *   @0x102f64 mov r3, #5
 *   @0x102f68 str r2, [r5, #0x8]
 *   @0x102f6c str r3, [r5, #0xc]
 *   @0x102f70 ldr r3, [r4, #0x3c]
 *   @0x102f74 mov r1, #0
 *   @0x102f78 ldr r2, [r4, #0x38]
 *   @0x102f7c str r1, [r6, r7, lsl #4]
 *   @0x102f80 str r3, [r5, #0xc]
 *   @0x102f84 ldr r3, [r4, #0x3c]
 *   @0x102f88 str r2, [r5, #0x8]
 *   @0x102f8c bic r3, r3, #-16777216
 *   @0x102f90 cmp r3, #14
 *   @0x102f94 addls pc, pc, r3, lsl #2
 *   @0x102f98 b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x102f9c b 0x102fe4 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x102fa0 b 0x103050 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x102fa4 b 0x103068 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x102fa8 b 0x102fd8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x102fac b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x102fb0 b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x102fb4 b 0x10302c <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x102fb8 b 0x102fd8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x102fbc b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x102fc0 b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x102fc4 b 0x102fe4 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x102fc8 b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x102fcc b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x102fd0 b 0x102fe4 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x102fd4 b 0x102fd8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x102fd8 ldr r3, [r4, #0x30]
 *   @0x102fdc str r3, [r6, r7, lsl #4]
 *   @0x102fe0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x102fe4 ldr r2, [r4, #0x30]
 *   @0x102fe8 ldr r3, [r4, #0x34]
 *   @0x102fec str r2, [r6, r7, lsl #4]
 *   @0x102ff0 str r3, [r5, #0x4]
 *   @0x102ff4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x102ff8 ldr r8, [r6, r7, lsl #4]
 *   @0x102ffc cmp r8, #0
 *   @0x103000 beq 0x103020 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x103004 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x103008 ldr r9, [r8, #0x4]
 *   @0x10300c sub r9, r9, #1
 *   @0x103010 str r9, [r8, #0x4]
 *   @0x103014 cmp r9, #0
 *   @0x103018 beq 0x103094 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x10301c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103020 mov r3, #0
 *   @0x103024 str r3, [r6, r7, lsl #4]
 *   @0x103028 b 0x102f70 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x10302c ldr r3, [r4, #0x30]
 *   @0x103030 str r3, [r6, r7, lsl #4]
 *   @0x103034 ldr r3, [r4, #0x30]
 *   @0x103038 cmp r3, #0
 *   @0x10303c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x103040 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x103044 ldr r1, [r4, #0x30]
 *   @0x103048 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x10304c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x103050 ldr r3, [r4, #0x30]
 *   @0x103054 cmp r3, #0
 *   @0x103058 ldrne r2, [r3, #0x4]
 *   @0x10305c addne r2, r2, #1
 *   @0x103060 strne r2, [r3, #0x4]
 *   @0x103064 b 0x102fdc <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x103068 ldr r3, [r4, #0x30]
 *   @0x10306c cmp r3, #0
 *   @0x103070 str r3, [r6, r7, lsl #4]
 *   @0x103074 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x103078 ldr r1, [r3, #0x8]
 *   @0x10307c ldr r2, [r3]
 *   @0x103080 cmp r1, #0
 *   @0x103084 streq r5, [r3, #0x8]
 *   @0x103088 add r2, r2, #1
 *   @0x10308c str r2, [r3]
 *   @0x103090 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x103094 ldr r0, [r8]
 *   @0x103098 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10309c str r9, [r8]
 *   @0x1030a0 str r9, [r8, #0x8]
 *   @0x1030a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1030a8 ldr r9, [r8, #0x4]
 *   @0x1030ac sub r9, r9, #1
 *   @0x1030b0 str r9, [r8, #0x4]
 *   @0x1030b4 cmp r9, #0
 *   @0x1030b8 beq 0x1030d8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x1030bc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1030c0 mov r0, r8
 *   @0x1030c4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1030c8 b 0x10301c <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x1030cc mov r0, r5
 *   @0x1030d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1030d4 b 0x102f60 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1030d8 ldr r0, [r8]
 *   @0x1030dc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1030e0 str r9, [r8]
 *   @0x1030e4 str r9, [r8, #0x8]
 *   @0x1030e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1030ec ldr r9, [r8, #0x4]
 *   @0x1030f0 sub r9, r9, #1
 *   @0x1030f4 str r9, [r8, #0x4]
 *   @0x1030f8 cmp r9, #0
 *   @0x1030fc beq 0x103110 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x103100 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103104 mov r0, r8
 *   @0x103108 bl 0x27d1d0 <_ZdlPv>
 *   @0x10310c b 0x1030bc <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x103110 ldr r0, [r8]
 *   @0x103114 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x103118 str r9, [r8]
 *   @0x10311c str r9, [r8, #0x8]
 *   @0x103120 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x103124 ldr r9, [r8, #0x4]
 *   @0x103128 sub r9, r9, #1
 *   @0x10312c str r9, [r8, #0x4]
 *   @0x103130 cmp r9, #0
 *   @0x103134 bne 0x103158 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x103138 ldr r0, [r8]
 *   @0x10313c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x103140 mov r0, r8
 *   @0x103144 str r9, [r8]
 *   @0x103148 str r9, [r8, #0x8]
 *   @0x10314c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x103150 mov r0, r8
 *   @0x103154 bl 0x27d1d0 <_ZdlPv>
 *   @0x103158 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10315c mov r0, r8
 *   @0x103160 bl 0x27d1d0 <_ZdlPv>
 *   @0x103164 b 0x103100 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x103168 eoreq r10, lr, r12, ror #30
 *
 * ══ §32/46 F_DsGridGet_release(RValue&, CInstance*, CInstance*, int, RValue*)  0x1058cc  size 648  162 条（0x1058cc..0x105b54）
 * @func 0x1058cc 0x105b54  size 648  162 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int)×3 / GetContextStackTop() / FREE_RValue__Pre(RValue*) / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0x4×17 / 0x8×8 / 0xc×5 / 0x20×1 / 0x244×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1058cc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1058d0 mov r1, #0
 *   @0x1058d4 ldr r5, [sp, #0x20]
 *   @0x1058d8 mov r4, r0
 *   @0x1058dc mov r0, r5
 *   @0x1058e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1058e4 mov r1, #1
 *   @0x1058e8 mov r6, r0
 *   @0x1058ec mov r0, r5
 *   @0x1058f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1058f4 mov r1, #2
 *   @0x1058f8 mov r7, r0
 *   @0x1058fc mov r0, r5
 *   @0x105900 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x105904 ldr r3, [pc, #0x244]
 *   @0x105908 ldr r1, [r4, #0xc]
 *   @0x10590c ldr r3, [pc, r3]
 *   @0x105910 bic r2, r1, #-16777216
 *   @0x105914 ldr r3, [r3, #0x4]
 *   @0x105918 cmp r2, #1
 *   @0x10591c ldr r3, [r3, r6, lsl #2]
 *   @0x105920 ldm r3, {r6, r12}
 *   @0x105924 mla r7, r12, r0, r7
 *   @0x105928 add r5, r6, r7, lsl #4
 *   @0x10592c beq 0x1059e0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x105930 cmp r2, #2
 *   @0x105934 bne 0x10595c <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x105938 sub r1, r1, #1
 *   @0x10593c bic r1, r1, #-16777216
 *   @0x105940 bic r1, r1, #3
 *   @0x105944 cmp r1, #0
 *   @0x105948 beq 0x105ab4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x10594c mov r2, #0
 *   @0x105950 mov r3, #5
 *   @0x105954 str r2, [r4, #0x8]
 *   @0x105958 str r3, [r4, #0xc]
 *   @0x10595c ldr r3, [r5, #0xc]
 *   @0x105960 mov r1, #0
 *   @0x105964 ldr r2, [r5, #0x8]
 *   @0x105968 str r1, [r4]
 *   @0x10596c str r3, [r4, #0xc]
 *   @0x105970 ldr r3, [r5, #0xc]
 *   @0x105974 str r2, [r4, #0x8]
 *   @0x105978 bic r3, r3, #-16777216
 *   @0x10597c cmp r3, #14
 *   @0x105980 addls pc, pc, r3, lsl #2
 *   @0x105984 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x105988 b 0x1059d0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x10598c b 0x105a38 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x105990 b 0x105a50 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x105994 b 0x1059c4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x105998 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x10599c b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x1059a0 b 0x105a14 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x1059a4 b 0x1059c4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x1059a8 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x1059ac b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x1059b0 b 0x1059d0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x1059b4 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x1059b8 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x1059bc b 0x1059d0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x1059c0 b 0x1059c4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x1059c4 ldr r3, [r6, r7, lsl #4]
 *   @0x1059c8 str r3, [r4]
 *   @0x1059cc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1059d0 ldr r2, [r6, r7, lsl #4]
 *   @0x1059d4 ldr r3, [r5, #0x4]
 *   @0x1059d8 stm r4, {r2, r3}
 *   @0x1059dc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1059e0 ldr r8, [r4]
 *   @0x1059e4 cmp r8, #0
 *   @0x1059e8 beq 0x105a08 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1059ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1059f0 ldr r9, [r8, #0x4]
 *   @0x1059f4 sub r9, r9, #1
 *   @0x1059f8 str r9, [r8, #0x4]
 *   @0x1059fc cmp r9, #0
 *   @0x105a00 beq 0x105a7c <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x105a04 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105a08 mov r3, #0
 *   @0x105a0c str r3, [r4]
 *   @0x105a10 b 0x10595c <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x105a14 ldr r3, [r6, r7, lsl #4]
 *   @0x105a18 str r3, [r4]
 *   @0x105a1c ldr r3, [r6, r7, lsl #4]
 *   @0x105a20 cmp r3, #0
 *   @0x105a24 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x105a28 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x105a2c ldr r1, [r6, r7, lsl #4]
 *   @0x105a30 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x105a34 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x105a38 ldr r3, [r6, r7, lsl #4]
 *   @0x105a3c cmp r3, #0
 *   @0x105a40 ldrne r2, [r3, #0x4]
 *   @0x105a44 addne r2, r2, #1
 *   @0x105a48 strne r2, [r3, #0x4]
 *   @0x105a4c b 0x1059c8 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x105a50 ldr r3, [r6, r7, lsl #4]
 *   @0x105a54 cmp r3, #0
 *   @0x105a58 str r3, [r4]
 *   @0x105a5c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x105a60 ldr r1, [r3, #0x8]
 *   @0x105a64 ldr r2, [r3]
 *   @0x105a68 cmp r1, #0
 *   @0x105a6c streq r4, [r3, #0x8]
 *   @0x105a70 add r2, r2, #1
 *   @0x105a74 str r2, [r3]
 *   @0x105a78 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x105a7c ldr r0, [r8]
 *   @0x105a80 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105a84 str r9, [r8]
 *   @0x105a88 str r9, [r8, #0x8]
 *   @0x105a8c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105a90 ldr r9, [r8, #0x4]
 *   @0x105a94 sub r9, r9, #1
 *   @0x105a98 str r9, [r8, #0x4]
 *   @0x105a9c cmp r9, #0
 *   @0x105aa0 beq 0x105ac0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x105aa4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105aa8 mov r0, r8
 *   @0x105aac bl 0x27d1d0 <_ZdlPv>
 *   @0x105ab0 b 0x105a04 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x105ab4 mov r0, r4
 *   @0x105ab8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105abc b 0x10594c <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x105ac0 ldr r0, [r8]
 *   @0x105ac4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105ac8 str r9, [r8]
 *   @0x105acc str r9, [r8, #0x8]
 *   @0x105ad0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105ad4 ldr r9, [r8, #0x4]
 *   @0x105ad8 sub r9, r9, #1
 *   @0x105adc str r9, [r8, #0x4]
 *   @0x105ae0 cmp r9, #0
 *   @0x105ae4 beq 0x105af8 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x105ae8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105aec mov r0, r8
 *   @0x105af0 bl 0x27d1d0 <_ZdlPv>
 *   @0x105af4 b 0x105aa4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x105af8 ldr r0, [r8]
 *   @0x105afc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105b00 str r9, [r8]
 *   @0x105b04 str r9, [r8, #0x8]
 *   @0x105b08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105b0c ldr r9, [r8, #0x4]
 *   @0x105b10 sub r9, r9, #1
 *   @0x105b14 str r9, [r8, #0x4]
 *   @0x105b18 cmp r9, #0
 *   @0x105b1c bne 0x105b40 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x105b20 ldr r0, [r8]
 *   @0x105b24 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105b28 mov r0, r8
 *   @0x105b2c str r9, [r8]
 *   @0x105b30 str r9, [r8, #0x8]
 *   @0x105b34 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x105b38 mov r0, r8
 *   @0x105b3c bl 0x27d1d0 <_ZdlPv>
 *   @0x105b40 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105b44 mov r0, r8
 *   @0x105b48 bl 0x27d1d0 <_ZdlPv>
 *   @0x105b4c b 0x105ae8 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x105b50 eoreq r8, lr, r12, ror r5
 *
 * ══ §33/46 CGestureUnknown::Update(long long)  0x1d87dc  size 648  162 条（0x1d87dc..0x1d8a64）
 * @func 0x1d87dc 0x1d8a64  size 648  162 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d8824→0x3f5168, 0x1d8860→0x3ebdd8, 0x1d88ac→0x544aa8, 0x1d8938→0x3ebd88, 0x1d89c8→0x544aa8, 0x1d8a28→0x3f5164
 * 调用序列: operator new(unsigned int)×2 / CGesture::CGesture()×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / IO_Button_Down(int, int) / CalcDistInches(int, int)
 * 字段偏移 top8: 0x4×10 / 0x8×8 / 0x28×7 / 0x40×6 / 0x44×6 / 0x30×5 / 0x34×4 / 0x4c×3
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d87dc ldr r1, [r0]
 *   @0x1d87e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d87e4 mov r4, r0
 *   @0x1d87e8 sub sp, sp, #12
 *   @0x1d87ec ldr r1, [r1, #0x18]
 *   @0x1d87f0 mov r10, r2
 *   @0x1d87f4 mov r11, r3
 *   @0x1d87f8 blx r1
 *   @0x1d87fc ldr r1, [r4, #0x28]
 *   @0x1d8800 mov r0, #1
 *   @0x1d8804 ldr r6, [pc, #0x238]
 *   @0x1d8808 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d880c add r6, pc, r6
 *   @0x1d8810 subs r7, r0, #0
 *   @0x1d8814 beq 0x1d8934 <_ZN15CGestureUnknown6UpdateEx+0x158>
 *   @0x1d8818 ldr r1, [r4, #0x4c]
 *   @0x1d881c ldr r0, [r4, #0x48]
 *   @0x1d8820 bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1d8824 ldr r1, [pc, #0x21c]
 *   @0x1d8828 ldrd r2, r3, [r4, #24]
 *   @0x1d882c ldr r1, [r6, r1]
 *   @0x1d8830 subs r2, r10, r2
 *   @0x1d8834 sbc r3, r11, r3
 *   @0x1d8838 vmov s15, r0
 *   @0x1d883c ldrd r0, r1, [r1]
 *   @0x1d8840 cmp r0, r2
 *   @0x1d8844 sbcs r9, r1, r3
 *   @0x1d8848 bge 0x1d8a28 <_ZN15CGestureUnknown6UpdateEx+0x24c>
 *   @0x1d884c mov r0, #96
 *   @0x1d8850 mov r7, #0
 *   @0x1d8854 bl 0x27c524 <_Znwj>
 *   @0x1d8858 mov r5, r0
 *   @0x1d885c bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d8860 ldr lr, [pc, #0x1e4]
 *   @0x1d8864 mvn r3, #0
 *   @0x1d8868 str r7, [r5, #0x40]
 *   @0x1d886c mov r2, #0
 *   @0x1d8870 ldr r12, [r4, #0x40]
 *   @0x1d8874 mov r0, #12
 *   @0x1d8878 str r3, [r5, #0x28]
 *   @0x1d887c str r7, [r5, #0x44]
 *   @0x1d8880 ldr r8, [r4, #0x28]
 *   @0x1d8884 ldr r1, [r4, #0x44]
 *   @0x1d8888 str r2, [r5, #0x58]
 *   @0x1d888c mov r2, #143
 *   @0x1d8890 str r3, [r5, #0x2c]
 *   @0x1d8894 mov r3, #1
 *   @0x1d8898 str r7, [r5, #0x38]
 *   @0x1d889c str r7, [r5, #0x3c]
 *   @0x1d88a0 str r7, [r5, #0x48]
 *   @0x1d88a4 str r7, [r5, #0x4c]
 *   @0x1d88a8 ldr r9, [r6, lr]
 *   @0x1d88ac ldr lr, [pc, #0x19c]
 *   @0x1d88b0 str r12, [r5, #0x30]
 *   @0x1d88b4 add r9, r9, #8
 *   @0x1d88b8 str r12, [r5, #0x40]
 *   @0x1d88bc str lr, [sp, #0x4]
 *   @0x1d88c0 mov lr, #3
 *   @0x1d88c4 str lr, [r5, #0x8]
 *   @0x1d88c8 ldr lr, [sp, #0x4]
 *   @0x1d88cc str r9, [r5]
 *   @0x1d88d0 str r1, [r5, #0x34]
 *   @0x1d88d4 str r1, [r5, #0x44]
 *   @0x1d88d8 str r8, [r5, #0x28]
 *   @0x1d88dc str r7, [r5, #0x14]
 *   @0x1d88e0 strd r10, r11, [r5, #24]
 *   @0x1d88e4 strd r10, r11, [r5, #32]
 *   @0x1d88e8 ldr r6, [r6, lr]
 *   @0x1d88ec ldr r1, [pc, #0x160]
 *   @0x1d88f0 ldr r12, [r6, #0x8]
 *   @0x1d88f4 add r1, pc, r1
 *   @0x1d88f8 add r12, r12, r3
 *   @0x1d88fc str r12, [r6, #0x8]
 *   @0x1d8900 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d8904 ldr r3, [r6, #0x4]
 *   @0x1d8908 cmp r3, r7
 *   @0x1d890c str r5, [r0, #0x8]
 *   @0x1d8910 beq 0x1d8a14 <_ZN15CGestureUnknown6UpdateEx+0x238>
 *   @0x1d8914 str r0, [r3]
 *   @0x1d8918 str r3, [r0, #0x4]
 *   @0x1d891c str r0, [r6, #0x4]
 *   @0x1d8920 str r7, [r0]
 *   @0x1d8924 mvn r3, #0
 *   @0x1d8928 str r3, [r4, #0x14]
 *   @0x1d892c add sp, sp, #12
 *   @0x1d8930 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d8934 mov r0, #96
 *   @0x1d8938 ldr r9, [pc, #0x118]
 *   @0x1d893c bl 0x27c524 <_Znwj>
 *   @0x1d8940 mov r5, r0
 *   @0x1d8944 bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d8948 str r7, [r5, #0x30]
 *   @0x1d894c mvn r12, #0
 *   @0x1d8950 ldr lr, [r4, #0x30]
 *   @0x1d8954 mov r3, #0
 *   @0x1d8958 str r12, [r5, #0x28]
 *   @0x1d895c mov r1, #1
 *   @0x1d8960 ldr r8, [r4, #0x28]
 *   @0x1d8964 mov r0, #12
 *   @0x1d8968 str r7, [r5, #0x34]
 *   @0x1d896c mov r2, #143
 *   @0x1d8970 str r12, [r5, #0x2c]
 *   @0x1d8974 ldr r12, [r4, #0x34]
 *   @0x1d8978 str r7, [r5, #0x40]
 *   @0x1d897c str r7, [r5, #0x44]
 *   @0x1d8980 str r12, [sp]
 *   @0x1d8984 str r3, [r5, #0x58]
 *   @0x1d8988 mov r3, r1
 *   @0x1d898c str r7, [r5, #0x38]
 *   @0x1d8990 str r7, [r5, #0x3c]
 *   @0x1d8994 str r7, [r5, #0x48]
 *   @0x1d8998 str r7, [r5, #0x4c]
 *   @0x1d899c ldr r9, [r6, r9]
 *   @0x1d89a0 str r9, [sp, #0x4]
 *   @0x1d89a4 ldr r9, [r4, #0x40]
 *   @0x1d89a8 ldr r12, [sp, #0x4]
 *   @0x1d89ac str r7, [r5, #0x5c]
 *   @0x1d89b0 str r9, [r5, #0x40]
 *   @0x1d89b4 add r9, r12, #8
 *   @0x1d89b8 str r9, [r5]
 *   @0x1d89bc ldr r9, [r4, #0x44]
 *   @0x1d89c0 str r8, [r5, #0x28]
 *   @0x1d89c4 str lr, [r5, #0x30]
 *   @0x1d89c8 ldr r8, [pc, #0x80]
 *   @0x1d89cc ldr lr, [sp]
 *   @0x1d89d0 str r1, [r5, #0x8]
 *   @0x1d89d4 str r7, [r5, #0x14]
 *   @0x1d89d8 str lr, [r5, #0x34]
 *   @0x1d89dc strd r10, r11, [r5, #24]
 *   @0x1d89e0 strd r10, r11, [r5, #32]
 *   @0x1d89e4 str r9, [r5, #0x44]
 *   @0x1d89e8 ldr r6, [r6, r8]
 *   @0x1d89ec ldr r1, [pc, #0x68]
 *   @0x1d89f0 ldr r12, [r6, #0x8]
 *   @0x1d89f4 add r1, pc, r1
 *   @0x1d89f8 add r12, r12, r3
 *   @0x1d89fc str r12, [r6, #0x8]
 *   @0x1d8a00 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d8a04 ldr r3, [r6, #0x4]
 *   @0x1d8a08 cmp r3, #0
 *   @0x1d8a0c str r5, [r0, #0x8]
 *   @0x1d8a10 bne 0x1d8914 <_ZN15CGestureUnknown6UpdateEx+0x138>
 *   @0x1d8a14 str r0, [r6, #0x4]
 *   @0x1d8a18 str r0, [r6]
 *   @0x1d8a1c str r3, [r0, #0x4]
 *   @0x1d8a20 str r3, [r0]
 *   @0x1d8a24 b 0x1d8924 <_ZN15CGestureUnknown6UpdateEx+0x148>
 *   @0x1d8a28 ldr r3, [pc, #0x30]
 *   @0x1d8a2c ldr r3, [r6, r3]
 *   @0x1d8a30 vldr s14, [r3]
 *   @0x1d8a34 vcmpe.f32 s15, s14
 *   @0x1d8a38 vmrs APSR_nzcv, fpscr
 *   @0x1d8a3c bgt 0x1d884c <_ZN15CGestureUnknown6UpdateEx+0x70>
 *   @0x1d8a40 b 0x1d892c <_ZN15CGestureUnknown6UpdateEx+0x150>
 *   @0x1d8a44 eoreq r9, r1, r4, asr #8
 *   @0x1d8a48 .word 0xffffef74
 *   @0x1d8a4c .word 0xffffefc8
 *   @0x1d8a50 .word 0xffffefc4
 *   @0x1d8a54 andseq r4, r7, r12, lsr r5
 *   @0x1d8a58 .word 0xffffefcc
 *   @0x1d8a5c andseq r4, r7, r12, lsr r4
 *   @0x1d8a60 .word 0xffffef78
 *
 * ══ §34/46 IO_Setup(IniFile*)  0x18cd20  size 644  161 条（0x18cd20..0x18cfa4）
 * @func 0x18cd20 0x18cfa4  size 644  161 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::ReadInt(char const*, char const*, int)×7 / IniFile::ReadString(char const*, char const*, char const*)×3 / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / IO_Setup(IniFile*)+0x220 / 0xb6550 / AllocateVirtualKey()
 * 字段偏移 top8: 0x4×4 / 0x8×4 / 0xc×3 / 0x94×2 / 0x14×2 / 0x18×2 / 0x24×2 / 0x28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18cd20 ldr r1, [pc, #0x240]
 *   @0x18cd24 mov r3, #0
 *   @0x18cd28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18cd2c ldr r1, [pc, r1]
 *   @0x18cd30 ldr r6, [pc, #0x234]
 *   @0x18cd34 sub sp, sp, #156
 *   @0x18cd38 ldr r12, [r1]
 *   @0x18cd3c mov r5, r0
 *   @0x18cd40 add r6, pc, r6
 *   @0x18cd44 ldr r2, [pc, #0x224]
 *   @0x18cd48 str r1, [sp, #0xc]
 *   @0x18cd4c add r2, pc, r2
 *   @0x18cd50 mov r1, r6
 *   @0x18cd54 str r12, [sp, #0x94]
 *   @0x18cd58 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i>
 *   @0x18cd5c ldr r2, [pc, #0x210]
 *   @0x18cd60 mov r1, r6
 *   @0x18cd64 mov r3, #0
 *   @0x18cd68 ldr r4, [pc, #0x208]
 *   @0x18cd6c add r2, pc, r2
 *   @0x18cd70 mov r7, r0
 *   @0x18cd74 mov r0, r5
 *   @0x18cd78 bl 0x235b78 <_ZN7IniFile10ReadStringEPKcS1_S1_>
 *   @0x18cd7c ldr r4, [pc, r4]
 *   @0x18cd80 mov r3, #0
 *   @0x18cd84 str r3, [r4]
 *   @0x18cd88 subs r6, r0, #0
 *   @0x18cd8c beq 0x18cdb4 <_Z8IO_SetupP7IniFile+0x94>
 *   @0x18cd90 bl 0xb6538 <strlen@plt>
 *   @0x18cd94 ldr r1, [pc, #0x1e0]
 *   @0x18cd98 movw r2, #0x44c
 *   @0x18cd9c mov r3, #1
 *   @0x18cda0 add r1, pc, r1
 *   @0x18cda4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18cda8 mov r1, r6
 *   @0x18cdac str r0, [r4]
 *   @0x18cdb0 bl 0xb65a4 <strcpy@plt>
 *   @0x18cdb4 cmp r7, #0
 *   @0x18cdb8 ble 0x18cf40 <_Z8IO_SetupP7IniFile+0x220>
 *   @0x18cdbc ldr r8, [pc, #0x1bc]
 *   @0x18cdc0 add r4, sp, #20
 *   @0x18cdc4 ldr r11, [pc, #0x1b8]
 *   @0x18cdc8 mov r6, #0
 *   @0x18cdcc ldr r10, [pc, #0x1b4]
 *   @0x18cdd0 add r8, pc, r8
 *   @0x18cdd4 ldr r2, [pc, #0x1b0]
 *   @0x18cdd8 add r11, pc, r11
 *   @0x18cddc ldr r3, [pc, #0x1ac]
 *   @0x18cde0 add r10, pc, r10
 *   @0x18cde4 ldr r1, [pc, #0x1a8]
 *   @0x18cde8 add r2, pc, r2
 *   @0x18cdec add r3, pc, r3
 *   @0x18cdf0 str r2, [sp]
 *   @0x18cdf4 add r1, pc, r1
 *   @0x18cdf8 str r3, [sp, #0x4]
 *   @0x18cdfc str r1, [sp, #0x8]
 *   @0x18ce00 mov r1, r8
 *   @0x18ce04 mov r2, r6
 *   @0x18ce08 mov r0, r4
 *   @0x18ce0c bl 0xb6550 <sprintf@plt>
 *   @0x18ce10 bl 0x18c590 <_Z18AllocateVirtualKeyv>
 *   @0x18ce14 subs r9, r0, #0
 *   @0x18ce18 beq 0x18cf34 <_Z8IO_SetupP7IniFile+0x214>
 *   @0x18ce1c mov r1, r4
 *   @0x18ce20 mov r2, r11
 *   @0x18ce24 mov r3, #0
 *   @0x18ce28 mov r0, r5
 *   @0x18ce2c bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i>
 *   @0x18ce30 mov r1, r4
 *   @0x18ce34 mov r2, r10
 *   @0x18ce38 mov r3, #0
 *   @0x18ce3c str r0, [r9, #0x4]
 *   @0x18ce40 mov r0, r5
 *   @0x18ce44 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i>
 *   @0x18ce48 mov r1, r4
 *   @0x18ce4c ldr r2, [sp]
 *   @0x18ce50 mov r3, #0
 *   @0x18ce54 str r0, [r9, #0x8]
 *   @0x18ce58 mov r0, r5
 *   @0x18ce5c bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i>
 *   @0x18ce60 mov r1, r4
 *   @0x18ce64 ldr r2, [sp, #0x4]
 *   @0x18ce68 mov r3, #0
 *   @0x18ce6c str r0, [r9, #0x14]
 *   @0x18ce70 mov r0, r5
 *   @0x18ce74 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i>
 *   @0x18ce78 mov r1, r4
 *   @0x18ce7c ldr r2, [sp, #0x8]
 *   @0x18ce80 mov r3, #0
 *   @0x18ce84 str r0, [r9, #0x18]
 *   @0x18ce88 mov r0, r5
 *   @0x18ce8c bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i>
 *   @0x18ce90 ldr r2, [pc, #0x100]
 *   @0x18ce94 mov r1, r4
 *   @0x18ce98 mov r3, #0
 *   @0x18ce9c add r2, pc, r2
 *   @0x18cea0 str r0, [r9, #0x1c]
 *   @0x18cea4 mov r0, r5
 *   @0x18cea8 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i>
 *   @0x18ceac ldr r1, [r9, #0x4]
 *   @0x18ceb0 ldr r3, [r9, #0x14]
 *   @0x18ceb4 mov r2, #0
 *   @0x18ceb8 ldr lr, [r9, #0x8]
 *   @0x18cebc add r3, r1, r3
 *   @0x18cec0 str r2, [r9, #0x24]
 *   @0x18cec4 ldr r1, [r9, #0x18]
 *   @0x18cec8 str r3, [r9, #0xc]
 *   @0x18cecc mov r3, r2
 *   @0x18ced0 ldr r2, [pc, #0xc4]
 *   @0x18ced4 add r1, lr, r1
 *   @0x18ced8 str r1, [r9, #0x10]
 *   @0x18cedc mov r1, r4
 *   @0x18cee0 add r2, pc, r2
 *   @0x18cee4 str r0, [r9, #0x20]
 *   @0x18cee8 mov r0, r5
 *   @0x18ceec bl 0x235b78 <_ZN7IniFile10ReadStringEPKcS1_S1_>
 *   @0x18cef0 cmp r0, #0
 *   @0x18cef4 beq 0x18cf00 <_Z8IO_SetupP7IniFile+0x1e0>
 *   @0x18cef8 bl 0x18c4a0 <_Z10ValueToKeyPKc>
 *   @0x18cefc str r0, [r9, #0x24]
 *   @0x18cf00 ldr r2, [pc, #0x98]
 *   @0x18cf04 mov r3, #0
 *   @0x18cf08 mov r0, r5
 *   @0x18cf0c str r3, [r9, #0x28]
 *   @0x18cf10 mov r1, r4
 *   @0x18cf14 add r2, pc, r2
 *   @0x18cf18 bl 0x235b78 <_ZN7IniFile10ReadStringEPKcS1_S1_>
 *   @0x18cf1c cmp r0, #0
 *   @0x18cf20 beq 0x18cf2c <_Z8IO_SetupP7IniFile+0x20c>
 *   @0x18cf24 bl 0x18c53c <_Z13ValueToButtonPKc>
 *   @0x18cf28 str r0, [r9, #0x28]
 *   @0x18cf2c mov r3, #1
 *   @0x18cf30 strh r3, [r9]
 *   @0x18cf34 add r6, r6, #1
 *   @0x18cf38 cmp r6, r7
 *   @0x18cf3c bne 0x18ce00 <_Z8IO_SetupP7IniFile+0xe0>
 *   @0x18cf40 mov r0, r5
 *   @0x18cf44 bl 0x18f05c <_Z9IO_SetupMP7IniFile>
 *   @0x18cf48 ldr r1, [sp, #0xc]
 *   @0x18cf4c ldr r2, [sp, #0x94]
 *   @0x18cf50 ldr r3, [r1]
 *   @0x18cf54 cmp r2, r3
 *   @0x18cf58 bne 0x18cf64 <_Z8IO_SetupP7IniFile+0x244>
 *   @0x18cf5c add sp, sp, #156
 *   @0x18cf60 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18cf64 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18cf68 eoreq r0, r6, r4, lsr #24
 *   @0x18cf6c andseq pc, r11, r12, lsr r5
 *   @0x18cf70 andseq pc, r11, r4, asr #10
 *   @0x18cf74 andseq pc, r11, r0, lsr r5
 *   @0x18cf78 eoreq r3, r6, r8, lsr #17
 *   @0x18cf7c andseq pc, r11, r12, lsr #9
 *   @0x18cf80 ldrsbeq pc, [r11], -r4
 *   @0x18cf84 ldrsbeq pc, [r11], -r12
 *   @0x18cf88 ldrsbeq pc, [r11], -r8
 *   @0x18cf8c ldrsbeq pc, [r11], -r4
 *   @0x18cf90 ldrsbeq pc, [r11], -r4
 *   @0x18cf94 ldrsbeq pc, [r11], -r0
 *   @0x18cf98 andseq pc, r11, r12, lsr #8
 *   @0x18cf9c andseq pc, r11, r12, ror #7
 *   @0x18cfa0 ldrheq pc, [r11], -r12
 *
 * ══ §35/46 JS_Array_prototype_filter(RValue&, CInstance*, CInstance*, int, RValue*)  0x251b00  size 644  161 条（0x251b00..0x251d84）
 * @func 0x251b00 0x251d84  size 644  161 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×5 / JSThrowTypeError(char const*)×2 / JS_Array_prototype_filter(RValue&, CInstance*, CInstance*, int, RValue*)+0x78 / JS_IsCallable(RValue&) / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*) / JS_ToBoolean(RValue&) / _itoa(int, char*, int)
 * 字段偏移 top8: 0xc×6 / 0x1c×5 / 0x4×5 / 0x20×4 / 0x14×4 / 0x24×4 / 0xec×2 / 0x10×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x251b00 ldr r12, [pc, #0x270]
 *   @0x251b04 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x251b08 sub sp, sp, #244
 *   @0x251b0c mov r4, r1
 *   @0x251b10 mov r5, r3
 *   @0x251b14 str r12, [sp, #0x20]
 *   @0x251b18 mov r6, r2
 *   @0x251b1c str r0, [sp, #0x1c]
 *   @0x251b20 mov r2, #5
 *   @0x251b24 ldr r0, [sp, #0x20]
 *   @0x251b28 ldr r12, [r1, #0x4]
 *   @0x251b2c ldr r0, [pc, r0]
 *   @0x251b30 ldr r1, [sp, #0x118]
 *   @0x251b34 str r0, [sp, #0x20]
 *   @0x251b38 cmp r12, #0
 *   @0x251b3c ldr r3, [r0]
 *   @0x251b40 ldr r0, [sp, #0x1c]
 *   @0x251b44 str r1, [sp, #0x14]
 *   @0x251b48 str r3, [sp, #0xec]
 *   @0x251b4c str r2, [r0, #0xc]
 *   @0x251b50 beq 0x251d58 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x258>
 *   @0x251b54 add r0, r12, #16
 *   @0x251b58 ldr r8, [r0]
 *   @0x251b5c cmp r5, #0
 *   @0x251b60 ldr r10, [r8, #0x24]
 *   @0x251b64 ble 0x251b78 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x251b68 ldr r0, [sp, #0x14]
 *   @0x251b6c bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x251b70 cmp r0, #0
 *   @0x251b74 bne 0x251ba0 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x251b78 ldr r0, [pc, #0x1fc]
 *   @0x251b7c add r0, pc, r0
 *   @0x251b80 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x251b84 ldr r12, [sp, #0x20]
 *   @0x251b88 ldr r2, [sp, #0xec]
 *   @0x251b8c ldr r3, [r12]
 *   @0x251b90 cmp r2, r3
 *   @0x251b94 bne 0x251d74 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x251b98 add sp, sp, #244
 *   @0x251b9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251ba0 cmp r5, #1
 *   @0x251ba4 moveq r12, #0
 *   @0x251ba8 streq r12, [sp, #0x18]
 *   @0x251bac ldrne r12, [sp, #0x14]
 *   @0x251bb0 ldrne r12, [r12, #0x10]
 *   @0x251bb4 strne r12, [sp, #0x18]
 *   @0x251bb8 ldr r12, [sp, #0x14]
 *   @0x251bbc mov r3, #0
 *   @0x251bc0 ldr r0, [sp, #0x1c]
 *   @0x251bc4 mov r1, r4
 *   @0x251bc8 mov r2, r6
 *   @0x251bcc str r12, [sp]
 *   @0x251bd0 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x251bd4 ldr r12, [sp, #0x1c]
 *   @0x251bd8 ldr r0, [r12]
 *   @0x251bdc ldr r3, [r0, #0x4]
 *   @0x251be0 cmp r3, #0
 *   @0x251be4 beq 0x251d68 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x251be8 add r0, r3, #16
 *   @0x251bec ldr r0, [r0]
 *   @0x251bf0 cmp r10, #0
 *   @0x251bf4 str r0, [sp, #0x24]
 *   @0x251bf8 beq 0x251b84 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x251bfc mov r11, #0
 *   @0x251c00 add r7, sp, #60
 *   @0x251c04 add r9, sp, #44
 *   @0x251c08 mov r6, r11
 *   @0x251c0c b 0x251c20 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x251c10 add r6, r6, #1
 *   @0x251c14 add r11, r11, #16
 *   @0x251c18 cmp r6, r10
 *   @0x251c1c beq 0x251b84 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x251c20 ldr r0, [r8, #0x4]
 *   @0x251c24 cmp r0, #0
 *   @0x251c28 beq 0x251d04 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x251c2c add r0, r0, r11
 *   @0x251c30 ldr r3, [r0, #0xc]
 *   @0x251c34 mvn r0, #-16777216
 *   @0x251c38 bic r3, r3, #-16777216
 *   @0x251c3c cmp r3, r0
 *   @0x251c40 beq 0x251c10 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x251c44 ldr r0, [r8, #0x4]
 *   @0x251c48 cmp r0, #0
 *   @0x251c4c beq 0x251d14 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x251c50 add r0, r0, r11
 *   @0x251c54 vmov s15, r6
 *   @0x251c58 mov r12, #0
 *   @0x251c5c ldm r0, {r0, r1, r2, r3}
 *   @0x251c60 vcvt.f64.u32 d7, s15
 *   @0x251c64 str r12, [sp, #0x58]
 *   @0x251c68 mov r12, #6
 *   @0x251c6c str r7, [sp]
 *   @0x251c70 str r12, [sp, #0x68]
 *   @0x251c74 stm r7, {r0, r1, r2, r3}
 *   @0x251c78 mov r1, r9
 *   @0x251c7c ldr r0, [sp, #0x18]
 *   @0x251c80 mov r3, #3
 *   @0x251c84 vmov r4, r5, d7
 *   @0x251c88 vstr s14, [sp, #76]
 *   @0x251c8c ldr r2, [sp, #0x14]
 *   @0x251c90 str r8, [sp, #0x5c]
 *   @0x251c94 str r5, [sp, #0x50]
 *   @0x251c98 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x251c9c cmp r0, #2
 *   @0x251ca0 beq 0x251b84 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x251ca4 cmp r0, #1
 *   @0x251ca8 beq 0x251d24 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x251cac mov r0, r9
 *   @0x251cb0 bl 0x2404bc <_Z12JS_ToBooleanR6RValue>
 *   @0x251cb4 cmp r0, #0
 *   @0x251cb8 beq 0x251c10 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x251cbc ldr r12, [sp, #0x24]
 *   @0x251cc0 add r3, sp, #108
 *   @0x251cc4 mov r2, #10
 *   @0x251cc8 mov r1, r3
 *   @0x251ccc ldr r0, [r12, #0x24]
 *   @0x251cd0 str r3, [sp, #0xc]
 *   @0x251cd4 bl 0xc4964 <_Z5_itoaiPci>
 *   @0x251cd8 ldr r1, [r8, #0x4]
 *   @0x251cdc ldr r12, [sp, #0x1c]
 *   @0x251ce0 cmp r1, #0
 *   @0x251ce4 ldr r3, [sp, #0xc]
 *   @0x251ce8 ldr r2, [r12]
 *   @0x251cec beq 0x251d34 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x251cf0 add r1, r1, r11
 *   @0x251cf4 mov r0, r2
 *   @0x251cf8 mov r2, r3
 *   @0x251cfc bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x251d00 b 0x251c10 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x251d04 mov r0, r8
 *   @0x251d08 mov r1, r6
 *   @0x251d0c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251d10 b 0x251c30 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x251d14 mov r0, r8
 *   @0x251d18 mov r1, r6
 *   @0x251d1c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251d20 b 0x251c54 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x251d24 ldr r0, [pc, #0x54]
 *   @0x251d28 add r0, pc, r0
 *   @0x251d2c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x251d30 b 0x251b84 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x251d34 mov r1, r6
 *   @0x251d38 mov r0, r8
 *   @0x251d3c str r2, [sp, #0x10]
 *   @0x251d40 str r3, [sp, #0xc]
 *   @0x251d44 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251d48 ldr r3, [sp, #0xc]
 *   @0x251d4c ldr r2, [sp, #0x10]
 *   @0x251d50 mov r1, r0
 *   @0x251d54 b 0x251cf4 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x251d58 mov r0, r4
 *   @0x251d5c mov r1, #1
 *   @0x251d60 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251d64 b 0x251b58 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x251d68 mov r1, #1
 *   @0x251d6c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251d70 b 0x251bec <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x251d74 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x251d78 andseq r11, r9, r4, lsr #28
 *   @0x251d7c mulseq r0, r12, r8
 *   @0x251d80 andseq r4, r0, r12, lsr #13
 *
 * ══ §36/46 b2DynamicTree::RebuildBottomUp()  0x2dfa00  size 644  161 条（0x2dfa00..0x2dfc84）
 * @func 0x2dfa00 0x2dfc84  size 644  161 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int) / b2DynamicTree::RebuildBottomUp()+0x98 / b2DynamicTree::RebuildBottomUp()+0x48 / b2DynamicTree::FreeNode(int) / b2DynamicTree::RebuildBottomUp()+0x260 / b2DynamicTree::AllocateNode() / b2Free(void*)
 * 字段偏移 top8: 0x4×6 / 0xc×5 / 0x2×5 / 0x14×4 / 0x20×4 / 0x8×2 / 0x18×2 / 0x1c×1
 * VFP 指令 52 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dfa00 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2dfa04 mov r9, r0
 *   @0x2dfa08 ldr r0, [r0, #0x8]
 *   @0x2dfa0c sub sp, sp, #20
 *   @0x2dfa10 lsl r0, r0, #2
 *   @0x2dfa14 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2dfa18 ldr r2, [r9, #0xc]
 *   @0x2dfa1c cmp r2, #0
 *   @0x2dfa20 movgt r6, #0
 *   @0x2dfa24 movgt r5, r6
 *   @0x2dfa28 movgt r4, r6
 *   @0x2dfa2c mov r10, r0
 *   @0x2dfa30 bgt 0x2dfa58 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x58>
 *   @0x2dfa34 b 0x2dfc60 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x260>
 *   @0x2dfa38 str r2, [r3, #0x14]
 *   @0x2dfa3c str r5, [r10, r4, lsl #2]
 *   @0x2dfa40 add r4, r4, #1
 *   @0x2dfa44 ldr r2, [r9, #0xc]
 *   @0x2dfa48 add r5, r5, #1
 *   @0x2dfa4c add r6, r6, #36
 *   @0x2dfa50 cmp r2, r5
 *   @0x2dfa54 ble 0x2dfa98 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x98>
 *   @0x2dfa58 ldr r3, [r9, #0x4]
 *   @0x2dfa5c add r3, r3, r6
 *   @0x2dfa60 ldr r1, [r3, #0x20]
 *   @0x2dfa64 cmp r1, #0
 *   @0x2dfa68 blt 0x2dfa48 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x48>
 *   @0x2dfa6c ldr r2, [r3, #0x18]
 *   @0x2dfa70 mov r1, r5
 *   @0x2dfa74 mov r0, r9
 *   @0x2dfa78 cmn r2, #1
 *   @0x2dfa7c beq 0x2dfa38 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x38>
 *   @0x2dfa80 bl 0x2deaac <_ZN13b2DynamicTree8FreeNodeEi>
 *   @0x2dfa84 ldr r2, [r9, #0xc]
 *   @0x2dfa88 add r5, r5, #1
 *   @0x2dfa8c add r6, r6, #36
 *   @0x2dfa90 cmp r2, r5
 *   @0x2dfa94 bgt 0x2dfa58 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x58>
 *   @0x2dfa98 cmp r4, #1
 *   @0x2dfa9c ble 0x2dfc60 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x260>
 *   @0x2dfaa0 ldr r3, [r9, #0x4]
 *   @0x2dfaa4 add r12, r10, r4, lsl #2
 *   @0x2dfaa8 mov r1, r9
 *   @0x2dfaac sub r2, r10, #4
 *   @0x2dfab0 str r2, [sp, #0xc]
 *   @0x2dfab4 ldr r9, [sp, #0xc]
 *   @0x2dfab8 mvn r5, #0
 *   @0x2dfabc mov r6, r5
 *   @0x2dfac0 mov r7, #0
 *   @0x2dfac4 vldr s7, [pc, #436]
 *   @0x2dfac8 ldr r2, [r9, #0x4]!
 *   @0x2dfacc add r8, r7, #1
 *   @0x2dfad0 cmp r8, r4
 *   @0x2dfad4 add r2, r2, r2, lsl #3
 *   @0x2dfad8 add r2, r3, r2, lsl #2
 *   @0x2dfadc vldr s10, [r2]
 *   @0x2dfae0 vldr s11, [r2, #4]
 *   @0x2dfae4 vldr s8, [r2, #8]
 *   @0x2dfae8 vldr s9, [r2, #12]
 *   @0x2dfaec bge 0x2dfb7c <_ZN13b2DynamicTree15RebuildBottomUpEv+0x17c>
 *   @0x2dfaf0 mov lr, r9
 *   @0x2dfaf4 mov r0, r8
 *   @0x2dfaf8 ldr r2, [lr, #0x4]!
 *   @0x2dfafc add r2, r2, r2, lsl #3
 *   @0x2dfb00 add r2, r3, r2, lsl #2
 *   @0x2dfb04 vldr s15, [r2]
 *   @0x2dfb08 vcmpe.f32 s10, s15
 *   @0x2dfb0c vldr s12, [r2, #4]
 *   @0x2dfb10 vldr s13, [r2, #8]
 *   @0x2dfb14 vldr s14, [r2, #12]
 *   @0x2dfb18 vmrs APSR_nzcv, fpscr
 *   @0x2dfb1c vcmpe.f32 s11, s12
 *   @0x2dfb20 vmovmi.f32 s15, s10
 *   @0x2dfb24 vmrs APSR_nzcv, fpscr
 *   @0x2dfb28 vcmpe.f32 s13, s8
 *   @0x2dfb2c vmovmi.f32 s12, s11
 *   @0x2dfb30 vmrs APSR_nzcv, fpscr
 *   @0x2dfb34 vcmpe.f32 s14, s9
 *   @0x2dfb38 vmovmi.f32 s13, s8
 *   @0x2dfb3c vmrs APSR_nzcv, fpscr
 *   @0x2dfb40 vmovmi.f32 s14, s9
 *   @0x2dfb44 vsub.f32 s15, s13, s15
 *   @0x2dfb48 vsub.f32 s14, s14, s12
 *   @0x2dfb4c vadd.f32 s15, s15, s14
 *   @0x2dfb50 vadd.f32 s15, s15, s15
 *   @0x2dfb54 vcmpe.f32 s7, s15
 *   @0x2dfb58 vmrs APSR_nzcv, fpscr
 *   @0x2dfb5c movgt r5, r0
 *   @0x2dfb60 add r0, r0, #1
 *   @0x2dfb64 vmovgt.f32 s7, s15
 *   @0x2dfb68 movgt r6, r7
 *   @0x2dfb6c cmp r0, r4
 *   @0x2dfb70 bne 0x2dfaf8 <_ZN13b2DynamicTree15RebuildBottomUpEv+0xf8>
 *   @0x2dfb74 mov r7, r8
 *   @0x2dfb78 b 0x2dfac8 <_ZN13b2DynamicTree15RebuildBottomUpEv+0xc8>
 *   @0x2dfb7c ldr r9, [r10, r6, lsl #2]
 *   @0x2dfb80 mov r0, r1
 *   @0x2dfb84 ldr r11, [r10, r5, lsl #2]
 *   @0x2dfb88 sub r4, r4, #1
 *   @0x2dfb8c stmib sp, {r1, r12}
 *   @0x2dfb90 add r8, r9, r9, lsl #3
 *   @0x2dfb94 add r7, r11, r11, lsl #3
 *   @0x2dfb98 add r8, r3, r8, lsl #2
 *   @0x2dfb9c add r7, r3, r7, lsl #2
 *   @0x2dfba0 bl 0x2de9bc <_ZN13b2DynamicTree12AllocateNodeEv>
 *   @0x2dfba4 vldr s12, [r8]
 *   @0x2dfba8 vldr s13, [r7]
 *   @0x2dfbac vcmpe.f32 s12, s13
 *   @0x2dfbb0 ldr r3, [r8, #0x20]
 *   @0x2dfbb4 ldr lr, [r7, #0x20]
 *   @0x2dfbb8 vldr s14, [r8, #4]
 *   @0x2dfbbc ldr r1, [sp, #0x4]
 *   @0x2dfbc0 vldr s15, [r7, #4]
 *   @0x2dfbc4 cmp lr, r3
 *   @0x2dfbc8 movlt lr, r3
 *   @0x2dfbcc vmrs APSR_nzcv, fpscr
 *   @0x2dfbd0 vcmpe.f32 s14, s15
 *   @0x2dfbd4 ldr r3, [r1, #0x4]
 *   @0x2dfbd8 add lr, lr, #1
 *   @0x2dfbdc vmovmi.f32 s13, s12
 *   @0x2dfbe0 vmrs APSR_nzcv, fpscr
 *   @0x2dfbe4 vmovmi.f32 s15, s14
 *   @0x2dfbe8 add r2, r0, r0, lsl #3
 *   @0x2dfbec add r2, r3, r2, lsl #2
 *   @0x2dfbf0 vstr s13, [r2]
 *   @0x2dfbf4 vstr s15, [r2, #4]
 *   @0x2dfbf8 vldr s12, [r8, #8]
 *   @0x2dfbfc vldr s13, [r7, #8]
 *   @0x2dfc00 vcmpe.f32 s12, s13
 *   @0x2dfc04 vldr s14, [r8, #12]
 *   @0x2dfc08 vldr s15, [r7, #12]
 *   @0x2dfc0c str lr, [r2, #0x20]
 *   @0x2dfc10 mvn lr, #0
 *   @0x2dfc14 str r9, [r2, #0x18]
 *   @0x2dfc18 vmrs APSR_nzcv, fpscr
 *   @0x2dfc1c vcmpe.f32 s14, s15
 *   @0x2dfc20 str lr, [r2, #0x14]
 *   @0x2dfc24 str r11, [r2, #0x1c]
 *   @0x2dfc28 vmovgt.f32 s13, s12
 *   @0x2dfc2c vmrs APSR_nzcv, fpscr
 *   @0x2dfc30 vstr s13, [r2, #8]
 *   @0x2dfc34 vmovgt.f32 s15, s14
 *   @0x2dfc38 vstr s15, [r2, #12]
 *   @0x2dfc3c str r0, [r8, #0x14]
 *   @0x2dfc40 cmp r4, #1
 *   @0x2dfc44 str r0, [r7, #0x14]
 *   @0x2dfc48 ldr r12, [sp, #0x8]
 *   @0x2dfc4c ldr r2, [r12, #-0x4]!
 *   @0x2dfc50 str r2, [r10, r5, lsl #2]
 *   @0x2dfc54 str r0, [r10, r6, lsl #2]
 *   @0x2dfc58 bne 0x2dfab4 <_ZN13b2DynamicTree15RebuildBottomUpEv+0xb4>
 *   @0x2dfc5c mov r9, r1
 *   @0x2dfc60 ldr r3, [r10]
 *   @0x2dfc64 mov r0, r10
 *   @0x2dfc68 str r3, [r9]
 *   @0x2dfc6c bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2dfc70 mov r0, r9
 *   @0x2dfc74 add sp, sp, #20
 *   @0x2dfc78 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2dfc7c b 0x2df960 <_ZNK13b2DynamicTree8ValidateEv>
 *   @0x2dfc80 svcvc #0x7fffff
 *
 * ══ §37/46 VM::PokeDSMap(int, int, RValue&)  0xe6364  size 640  160 条（0xe6364..0xe65e4）
 * @func 0xe6364 0xe65e4  size 640  160 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / VM::PokeDSMap(int, int, RValue&)+0x2c / VM::PokeDSMap(int, int, RValue&)+0x3c / DS_AutoMutex::DS_AutoMutex() / CDS_Map::Size() / FREE_RValue__Pre(RValue*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x10×5 / 0x4×4 / 0x8×3 / 0xc×3 / 0x1c×3 / 0x18×2 / 0x258×1 / 0x22c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe6364 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xe6368 subs r4, r0, #0
 *   @0xe636c sub sp, sp, #8
 *   @0xe6370 mov r7, r1
 *   @0xe6374 mov r9, r2
 *   @0xe6378 blt 0xe6390 <_ZN2VM9PokeDSMapEiiR6RValue+0x2c>
 *   @0xe637c ldr r3, [pc, #0x258]
 *   @0xe6380 ldr r3, [pc, r3]
 *   @0xe6384 ldr r3, [r3]
 *   @0xe6388 cmp r4, r3
 *   @0xe638c blt 0xe63a0 <_ZN2VM9PokeDSMapEiiR6RValue+0x3c>
 *   @0xe6390 mov r5, #0
 *   @0xe6394 mov r0, r5
 *   @0xe6398 add sp, sp, #8
 *   @0xe639c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xe63a0 add r8, sp, #4
 *   @0xe63a4 mov r0, r8
 *   @0xe63a8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xe63ac ldr r3, [pc, #0x22c]
 *   @0xe63b0 ldr r3, [pc, r3]
 *   @0xe63b4 ldr r3, [r3, #0x4]
 *   @0xe63b8 ldr r4, [r3, r4, lsl #2]
 *   @0xe63bc cmp r4, #0
 *   @0xe63c0 beq 0xe63e8 <_ZN2VM9PokeDSMapEiiR6RValue+0x84>
 *   @0xe63c4 mov r0, r4
 *   @0xe63c8 bl 0x2052c0 <_ZN7CDS_Map4SizeEv>
 *   @0xe63cc cmp r7, r0
 *   @0xe63d0 movge r5, #0
 *   @0xe63d4 movlt r5, #1
 *   @0xe63d8 cmp r7, #0
 *   @0xe63dc movlt r5, #0
 *   @0xe63e0 cmp r5, #0
 *   @0xe63e4 bne 0xe6400 <_ZN2VM9PokeDSMapEiiR6RValue+0x9c>
 *   @0xe63e8 mov r0, r8
 *   @0xe63ec mov r5, #0
 *   @0xe63f0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xe63f4 mov r0, r5
 *   @0xe63f8 add sp, sp, #8
 *   @0xe63fc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xe6400 ldr r0, [r4]
 *   @0xe6404 mov r12, #0
 *   @0xe6408 ldr r10, [r0]
 *   @0xe640c b 0xe6420 <_ZN2VM9PokeDSMapEiiR6RValue+0xbc>
 *   @0xe6410 ldr r2, [r0, #0x4]
 *   @0xe6414 add r12, r12, #1
 *   @0xe6418 cmp r12, r2
 *   @0xe641c bgt 0xe65d4 <_ZN2VM9PokeDSMapEiiR6RValue+0x270>
 *   @0xe6420 ldr r3, [r10, r12, lsl #3]
 *   @0xe6424 cmp r3, #0
 *   @0xe6428 beq 0xe6410 <_ZN2VM9PokeDSMapEiiR6RValue+0xac>
 *   @0xe642c cmp r7, #0
 *   @0xe6430 movne r6, #0
 *   @0xe6434 bne 0xe6448 <_ZN2VM9PokeDSMapEiiR6RValue+0xe4>
 *   @0xe6438 b 0xe6498 <_ZN2VM9PokeDSMapEiiR6RValue+0x134>
 *   @0xe643c add r6, r6, #1
 *   @0xe6440 cmp r6, r7
 *   @0xe6444 beq 0xe6498 <_ZN2VM9PokeDSMapEiiR6RValue+0x134>
 *   @0xe6448 cmp r3, #0
 *   @0xe644c beq 0xe643c <_ZN2VM9PokeDSMapEiiR6RValue+0xd8>
 *   @0xe6450 ldr r3, [r3, #0x4]
 *   @0xe6454 cmp r3, #0
 *   @0xe6458 bne 0xe643c <_ZN2VM9PokeDSMapEiiR6RValue+0xd8>
 *   @0xe645c ldr r1, [r0, #0x4]
 *   @0xe6460 add r4, r12, #1
 *   @0xe6464 cmp r4, r1
 *   @0xe6468 bgt 0xe6490 <_ZN2VM9PokeDSMapEiiR6RValue+0x12c>
 *   @0xe646c add lr, r10, r12, lsl #3
 *   @0xe6470 ldr r3, [lr, #0x8]
 *   @0xe6474 mov r12, r4
 *   @0xe6478 add lr, lr, #8
 *   @0xe647c add r4, r4, #1
 *   @0xe6480 cmp r3, #0
 *   @0xe6484 bne 0xe643c <_ZN2VM9PokeDSMapEiiR6RValue+0xd8>
 *   @0xe6488 cmp r1, r4
 *   @0xe648c bge 0xe6470 <_ZN2VM9PokeDSMapEiiR6RValue+0x10c>
 *   @0xe6490 mvn r12, #0
 *   @0xe6494 b 0xe643c <_ZN2VM9PokeDSMapEiiR6RValue+0xd8>
 *   @0xe6498 cmp r3, #0
 *   @0xe649c beq 0xe63e8 <_ZN2VM9PokeDSMapEiiR6RValue+0x84>
 *   @0xe64a0 ldr r4, [r3, #0xc]
 *   @0xe64a4 cmp r4, #0
 *   @0xe64a8 beq 0xe63e8 <_ZN2VM9PokeDSMapEiiR6RValue+0x84>
 *   @0xe64ac ldr r3, [r4, #0x1c]
 *   @0xe64b0 add r6, r4, #16
 *   @0xe64b4 sub r3, r3, #1
 *   @0xe64b8 bic r3, r3, #-16777216
 *   @0xe64bc bic r3, r3, #3
 *   @0xe64c0 cmp r3, #0
 *   @0xe64c4 beq 0xe6550 <_ZN2VM9PokeDSMapEiiR6RValue+0x1ec>
 *   @0xe64c8 mov r3, #5
 *   @0xe64cc str r3, [r4, #0x1c]
 *   @0xe64d0 ldr r3, [r9, #0xc]
 *   @0xe64d4 mov r2, #0
 *   @0xe64d8 str r2, [r4, #0x18]
 *   @0xe64dc ldr r1, [r9, #0x8]
 *   @0xe64e0 str r3, [r4, #0x1c]
 *   @0xe64e4 ldr r3, [r9, #0xc]
 *   @0xe64e8 str r2, [r4, #0x10]
 *   @0xe64ec bic r3, r3, #-16777216
 *   @0xe64f0 str r1, [r4, #0x18]
 *   @0xe64f4 cmp r3, #14
 *   @0xe64f8 addls pc, pc, r3, lsl #2
 *   @0xe64fc b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6500 b 0xe655c <_ZN2VM9PokeDSMapEiiR6RValue+0x1f8>
 *   @0xe6504 b 0xe65bc <_ZN2VM9PokeDSMapEiiR6RValue+0x258>
 *   @0xe6508 b 0xe6590 <_ZN2VM9PokeDSMapEiiR6RValue+0x22c>
 *   @0xe650c b 0xe653c <_ZN2VM9PokeDSMapEiiR6RValue+0x1d8>
 *   @0xe6510 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6514 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6518 b 0xe656c <_ZN2VM9PokeDSMapEiiR6RValue+0x208>
 *   @0xe651c b 0xe653c <_ZN2VM9PokeDSMapEiiR6RValue+0x1d8>
 *   @0xe6520 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6524 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6528 b 0xe655c <_ZN2VM9PokeDSMapEiiR6RValue+0x1f8>
 *   @0xe652c b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6530 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6534 b 0xe655c <_ZN2VM9PokeDSMapEiiR6RValue+0x1f8>
 *   @0xe6538 b 0xe653c <_ZN2VM9PokeDSMapEiiR6RValue+0x1d8>
 *   @0xe653c ldr r3, [r9]
 *   @0xe6540 str r3, [r4, #0x10]
 *   @0xe6544 mov r0, r8
 *   @0xe6548 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xe654c b 0xe6394 <_ZN2VM9PokeDSMapEiiR6RValue+0x30>
 *   @0xe6550 mov r0, r6
 *   @0xe6554 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe6558 b 0xe64c8 <_ZN2VM9PokeDSMapEiiR6RValue+0x164>
 *   @0xe655c ldm r9, {r2, r3}
 *   @0xe6560 str r2, [r4, #0x10]
 *   @0xe6564 str r3, [r4, #0x14]
 *   @0xe6568 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe656c ldr r3, [r9]
 *   @0xe6570 str r3, [r4, #0x10]
 *   @0xe6574 ldr r3, [r9]
 *   @0xe6578 cmp r3, #0
 *   @0xe657c beq 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6580 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xe6584 ldr r1, [r9]
 *   @0xe6588 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xe658c b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe6590 ldr r3, [r9]
 *   @0xe6594 cmp r3, #0
 *   @0xe6598 str r3, [r4, #0x10]
 *   @0xe659c beq 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe65a0 ldr r1, [r3, #0x8]
 *   @0xe65a4 ldr r2, [r3]
 *   @0xe65a8 cmp r1, #0
 *   @0xe65ac streq r6, [r3, #0x8]
 *   @0xe65b0 add r2, r2, #1
 *   @0xe65b4 str r2, [r3]
 *   @0xe65b8 b 0xe6544 <_ZN2VM9PokeDSMapEiiR6RValue+0x1e0>
 *   @0xe65bc ldr r3, [r9]
 *   @0xe65c0 cmp r3, #0
 *   @0xe65c4 ldrne r2, [r3, #0x4]
 *   @0xe65c8 addne r2, r2, #1
 *   @0xe65cc strne r2, [r3, #0x4]
 *   @0xe65d0 b 0xe6540 <_ZN2VM9PokeDSMapEiiR6RValue+0x1dc>
 *   @0xe65d4 mvn r12, #0
 *   @0xe65d8 b 0xe642c <_ZN2VM9PokeDSMapEiiR6RValue+0xc8>
 *   @0xe65dc ldrshteq r7, [r0], -r8
 *   @0xe65e0 eorseq r7, r0, r12, lsl #11
 *
 * ══ §38/46 Graphics::SurfaceCopy(void*, int, int, void*, int, int, int, int)  0x17e850  size 640  160 条（0x17e850..0x17ead0）
 * @func 0x17e850 0x17ead0  size 640  160 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush()×2 / 0xb65bc×2 / DBG_BIND_FRAMEBUFFER(int)×2 / GR_3D_Projection_Ortho(float, float, float, float, float) / DrawIt_Color(void*, float, float, float, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int) / Graphics::SetMatrices(float*, float*, float*) / Graphics::SetViewPort(int, int, int, int)
 * 字段偏移 top8: 0x70×4 / 0x40×2 / 0x4×2 / 0x3c×2 / 0x44×2 / 0x23c×1 / 0x228×1 / 0x218×1
 * VFP 指令 49 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17e850 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17e854 vpush {d8}
 *   @0x17e858 sub sp, sp, #268
 *   @0x17e85c ldr r4, [pc, #0x23c]
 *   @0x17e860 mov r5, r0
 *   @0x17e864 mov r9, r3
 *   @0x17e868 vmov s17, r1
 *   @0x17e86c vmov s16, r2
 *   @0x17e870 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17e874 ldr r3, [pc, #0x228]
 *   @0x17e878 add r4, pc, r4
 *   @0x17e87c add r8, sp, #72
 *   @0x17e880 mov r10, #192
 *   @0x17e884 mov r2, r10
 *   @0x17e888 ldr r11, [pc, #0x218]
 *   @0x17e88c ldr r3, [r4, r3]
 *   @0x17e890 mov r0, r8
 *   @0x17e894 add r11, pc, r11
 *   @0x17e898 mvn r6, #0
 *   @0x17e89c mov r1, r3
 *   @0x17e8a0 str r3, [sp, #0x40]
 *   @0x17e8a4 bl 0xb65bc <memcpy@plt>
 *   @0x17e8a8 ldr r2, [pc, #0x1fc]
 *   @0x17e8ac ldr r0, [r5, #0x18]
 *   @0x17e8b0 movw r3, #0x1b9
 *   @0x17e8b4 ldr r7, [r4, r2]
 *   @0x17e8b8 str r3, [r7, #0x4]
 *   @0x17e8bc str r11, [r7]
 *   @0x17e8c0 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x17e8c4 ldmib r5, {r2, r3}
 *   @0x17e8c8 mov r12, #0
 *   @0x17e8cc ldr lr, [pc, #0x1dc]
 *   @0x17e8d0 mov r0, r12
 *   @0x17e8d4 vmov s6, r2
 *   @0x17e8d8 ldr lr, [r4, lr]
 *   @0x17e8dc vcvt.f32.s32 s6, s6
 *   @0x17e8e0 str r12, [sp]
 *   @0x17e8e4 ldr r1, [lr]
 *   @0x17e8e8 str r6, [lr]
 *   @0x17e8ec str lr, [sp, #0x3c]
 *   @0x17e8f0 str r1, [sp, #0x44]
 *   @0x17e8f4 mov r1, r12
 *   @0x17e8f8 vmov r2, s6
 *   @0x17e8fc vmov s6, r3
 *   @0x17e900 vcvt.f32.s32 s6, s6
 *   @0x17e904 vmov r3, s6
 *   @0x17e908 bl 0x1633e8 <_Z22GR_3D_Projection_Orthofffff>
 *   @0x17e90c ldr r12, [pc, #0x1a0]
 *   @0x17e910 mov r0, #0
 *   @0x17e914 ldmib r5, {r2, r3}
 *   @0x17e918 mov r1, r0
 *   @0x17e91c ldr r12, [r4, r12]
 *   @0x17e920 ldr r12, [r12]
 *   @0x17e924 blx r12
 *   @0x17e928 ldr r12, [pc, #0x188]
 *   @0x17e92c mov r0, #0
 *   @0x17e930 ldmib r5, {r2, r3}
 *   @0x17e934 mov r1, r0
 *   @0x17e938 ldr r12, [r4, r12]
 *   @0x17e93c ldr r12, [r12]
 *   @0x17e940 blx r12
 *   @0x17e944 vmov.f32 s11, #1.000000e+00
 *   @0x17e948 vldr s10, [r9, #4]
 *   @0x17e94c vldr s15, [r9, #8]
 *   @0x17e950 ldr r2, [sp, #0x140]
 *   @0x17e954 vldr s6, [sp, #312]
 *   @0x17e958 ldr r1, [sp, #0x138]
 *   @0x17e95c mov r0, r9
 *   @0x17e960 ldr r3, [sp, #0x13c]
 *   @0x17e964 add r1, r1, r2
 *   @0x17e968 vmov r2, s16
 *   @0x17e96c str r6, [sp, #0x24]
 *   @0x17e970 vmov s7, r1
 *   @0x17e974 ldr r1, [sp, #0x144]
 *   @0x17e978 str r6, [sp, #0x28]
 *   @0x17e97c add r3, r3, r1
 *   @0x17e980 str r6, [sp, #0x2c]
 *   @0x17e984 vcvt.f32.s32 s10, s10
 *   @0x17e988 str r6, [sp, #0x30]
 *   @0x17e98c vmov s9, r3
 *   @0x17e990 ldr r3, [sp, #0x44]
 *   @0x17e994 vcvt.f32.s32 s15, s15
 *   @0x17e998 vdiv.f32 s12, s11, s10
 *   @0x17e99c add r2, r2, r1
 *   @0x17e9a0 ldr r1, [sp, #0x3c]
 *   @0x17e9a4 vmov s14, r2
 *   @0x17e9a8 str r3, [r1]
 *   @0x17e9ac vdiv.f32 s13, s11, s15
 *   @0x17e9b0 vldr s15, [sp, #316]
 *   @0x17e9b4 vcvt.f32.s32 s7, s7
 *   @0x17e9b8 vcvt.f32.s32 s9, s9
 *   @0x17e9bc vcvt.f32.s32 s8, s6
 *   @0x17e9c0 vldr s6, [sp, #320]
 *   @0x17e9c4 vcvt.f32.s32 s10, s15
 *   @0x17e9c8 vcvt.f32.s32 s11, s6
 *   @0x17e9cc vcvt.f32.s32 s15, s17
 *   @0x17e9d0 vmul.f32 s8, s8, s12
 *   @0x17e9d4 vstr s15, [sp, #12]
 *   @0x17e9d8 vmov r1, s15
 *   @0x17e9dc vmul.f32 s10, s13, s10
 *   @0x17e9e0 vstr s8, [sp, #20]
 *   @0x17e9e4 vmul.f32 s12, s7, s12
 *   @0x17e9e8 vstr s10, [sp, #24]
 *   @0x17e9ec vmul.f32 s13, s13, s9
 *   @0x17e9f0 vstr s12, [sp, #28]
 *   @0x17e9f4 vadd.f32 s15, s15, s11
 *   @0x17e9f8 vstr s13, [sp, #32]
 *   @0x17e9fc vcvt.f32.s32 s14, s14
 *   @0x17ea00 vstr s15, [sp, #4]
 *   @0x17ea04 vmov r3, s15
 *   @0x17ea08 vcvt.f32.s32 s16, s16
 *   @0x17ea0c vstr s14, [sp, #8]
 *   @0x17ea10 vstr s14, [sp, #16]
 *   @0x17ea14 vmov r2, s16
 *   @0x17ea18 vstr s16, [sp]
 *   @0x17ea1c bl 0x17438c <_Z12DrawIt_ColorPvffffffffffffjjjj>
 *   @0x17ea20 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17ea24 mov r1, r8
 *   @0x17ea28 mov r2, r10
 *   @0x17ea2c ldr r0, [sp, #0x40]
 *   @0x17ea30 bl 0xb65bc <memcpy@plt>
 *   @0x17ea34 mov r1, r8
 *   @0x17ea38 add r0, sp, #200
 *   @0x17ea3c add r2, sp, #136
 *   @0x17ea40 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_>
 *   @0x17ea44 ldr r0, [pc, #0x70]
 *   @0x17ea48 ldr r1, [pc, #0x70]
 *   @0x17ea4c ldr r2, [pc, #0x70]
 *   @0x17ea50 ldr r3, [pc, #0x70]
 *   @0x17ea54 ldr r0, [r4, r0]
 *   @0x17ea58 ldr r1, [r4, r1]
 *   @0x17ea5c ldr r2, [r4, r2]
 *   @0x17ea60 ldr r3, [r4, r3]
 *   @0x17ea64 ldr r1, [r1]
 *   @0x17ea68 ldr r0, [r0]
 *   @0x17ea6c ldr r2, [r2]
 *   @0x17ea70 ldr r3, [r3]
 *   @0x17ea74 bl 0x17dfb0 <_ZN8Graphics11SetViewPortEiiii>
 *   @0x17ea78 ldr r3, [pc, #0x4c]
 *   @0x17ea7c str r11, [r7]
 *   @0x17ea80 movw r2, #0x1e3
 *   @0x17ea84 str r2, [r7, #0x4]
 *   @0x17ea88 ldr r3, [r4, r3]
 *   @0x17ea8c ldr r0, [r3]
 *   @0x17ea90 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x17ea94 add sp, sp, #268
 *   @0x17ea98 vpop {d8}
 *   @0x17ea9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17eaa0 .word 0x002733d8
 *   @0x17eaa4 .word 0xffffe824
 *   @0x17eaa8 ldrheq sp, [r12], -r4
 *   @0x17eaac .word 0xffffe81c
 *   @0x17eab0 .word 0xffffe48c
 *   @0x17eab4 .word 0xffffbae4
 *   @0x17eab8 .word 0xffffbaf0
 *   @0x17eabc .word 0xffffe80c
 *   @0x17eac0 .word 0xffffe810
 *   @0x17eac4 .word 0xffffe814
 *   @0x17eac8 .word 0xffffe818
 *   @0x17eacc .word 0xffffe820
 *
 * ══ §39/46 Script_Load(unsigned char*, unsigned int, unsigned char*)  0x1e01e4  size 640  160 条（0x1e01e4..0x1e0464）
 * @func 0x1e01e4 0x1e0464  size 640  160 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1e01f4→0x544b58, 0x1e0204→0x544c68, 0x1e020c→0x544c70, 0x1e0254→0x544c6c, 0x1e02ac→0x544c44, 0x1e03a4→0x544b54
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / operator new(unsigned int)×2 / CScript::CScript(char const*)×2 / CScript::LoadFromChunk(YYScript*, unsigned char*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×9 / 0xc×4 / 0x10×3 / 0x1c×3 / 0x18×3 / 0x234×2 / 0x14×2 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e01e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e01e8 sub sp, sp, #36
 *   @0x1e01ec ldr r11, [pc, #0x248]
 *   @0x1e01f0 mov r8, r0
 *   @0x1e01f4 ldr r1, [pc, #0x244]
 *   @0x1e01f8 mov r3, #152
 *   @0x1e01fc add r11, pc, r11
 *   @0x1e0200 str r2, [sp, #0x10]
 *   @0x1e0204 ldr r0, [pc, #0x238]
 *   @0x1e0208 ldr r1, [r11, r1]
 *   @0x1e020c ldr r2, [pc, #0x234]
 *   @0x1e0210 ldr r5, [pc, #0x234]
 *   @0x1e0214 str r1, [sp, #0xc]
 *   @0x1e0218 ldr r4, [r11, r0]
 *   @0x1e021c add r5, pc, r5
 *   @0x1e0220 ldr r0, [r8]
 *   @0x1e0224 str r0, [sp, #0x4]
 *   @0x1e0228 ldr r0, [sp, #0xc]
 *   @0x1e022c ldr r1, [r0]
 *   @0x1e0230 ldr r0, [sp, #0x4]
 *   @0x1e0234 add r1, r0, r1
 *   @0x1e0238 str r1, [r4]
 *   @0x1e023c ldr r7, [r11, r2]
 *   @0x1e0240 mov r2, r5
 *   @0x1e0244 lsl r1, r1, #2
 *   @0x1e0248 add r0, r7, #4
 *   @0x1e024c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e0250 ldr r1, [r4]
 *   @0x1e0254 ldr r0, [pc, #0x1f4]
 *   @0x1e0258 mov r2, r5
 *   @0x1e025c mov r3, #154
 *   @0x1e0260 str r1, [r7]
 *   @0x1e0264 lsl r1, r1, #2
 *   @0x1e0268 ldr r10, [r11, r0]
 *   @0x1e026c mov r0, r10
 *   @0x1e0270 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e0274 ldr r1, [sp, #0x4]
 *   @0x1e0278 cmp r1, #0
 *   @0x1e027c beq 0x1e038c <_Z11Script_LoadPhjS_+0x1a8>
 *   @0x1e0280 ldr r3, [pc, #0x1cc]
 *   @0x1e0284 mov r9, r10
 *   @0x1e0288 ldr r0, [pc, #0x1c8]
 *   @0x1e028c mov r4, #0
 *   @0x1e0290 add r3, pc, r3
 *   @0x1e0294 str r11, [sp, #0x1c]
 *   @0x1e0298 add r0, pc, r0
 *   @0x1e029c str r3, [sp, #0x14]
 *   @0x1e02a0 str r0, [sp, #0x18]
 *   @0x1e02a4 mov r10, r7
 *   @0x1e02a8 b 0x1e036c <_Z11Script_LoadPhjS_+0x188>
 *   @0x1e02ac ldr r3, [pc, #0x1a8]
 *   @0x1e02b0 ldr r1, [sp, #0x1c]
 *   @0x1e02b4 ldr r3, [r1, r3]
 *   @0x1e02b8 ldr r11, [r3]
 *   @0x1e02bc str r3, [sp, #0x8]
 *   @0x1e02c0 adds r7, r11, r5
 *   @0x1e02c4 beq 0x1e0434 <_Z11Script_LoadPhjS_+0x250>
 *   @0x1e02c8 mov r0, #28
 *   @0x1e02cc bl 0x27c524 <_Znwj>
 *   @0x1e02d0 ldr r1, [sp, #0x14]
 *   @0x1e02d4 mov r6, r0
 *   @0x1e02d8 bl 0x1dfc04 <_ZN7CScriptC2EPKc>
 *   @0x1e02dc ldr r2, [sp, #0x10]
 *   @0x1e02e0 mov r1, r7
 *   @0x1e02e4 mov r0, r6
 *   @0x1e02e8 bl 0x1dfd3c <_ZN7CScript13LoadFromChunkEP8YYScriptPh>
 *   @0x1e02ec ldr r7, [r11, r5]
 *   @0x1e02f0 cmp r7, #0
 *   @0x1e02f4 ldrne r2, [sp, #0x8]
 *   @0x1e02f8 ldrne r3, [r2]
 *   @0x1e02fc addne r7, r3, r7
 *   @0x1e0300 mov r0, r7
 *   @0x1e0304 bl 0xb6538 <strlen@plt>
 *   @0x1e0308 ldr r1, [sp, #0x18]
 *   @0x1e030c mov r3, #1
 *   @0x1e0310 mov r2, #166
 *   @0x1e0314 add r0, r0, r3
 *   @0x1e0318 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e031c mov r1, r7
 *   @0x1e0320 mov r5, r0
 *   @0x1e0324 bl 0xb65a4 <strcpy@plt>
 *   @0x1e0328 ldr r3, [r9]
 *   @0x1e032c lsl r7, r4, #2
 *   @0x1e0330 ldr r0, [r3, r4, lsl #2]
 *   @0x1e0334 cmp r0, #0
 *   @0x1e0338 beq 0x1e034c <_Z11Script_LoadPhjS_+0x168>
 *   @0x1e033c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e0340 ldr r3, [r9]
 *   @0x1e0344 mov r0, #0
 *   @0x1e0348 str r0, [r3, r4, lsl #2]
 *   @0x1e034c ldr r3, [r10, #0x4]
 *   @0x1e0350 add r4, r4, #1
 *   @0x1e0354 ldr r1, [sp, #0x4]
 *   @0x1e0358 str r6, [r3, r7]
 *   @0x1e035c cmp r4, r1
 *   @0x1e0360 ldr r3, [r9]
 *   @0x1e0364 str r5, [r3, r7]
 *   @0x1e0368 beq 0x1e0380 <_Z11Script_LoadPhjS_+0x19c>
 *   @0x1e036c ldr r5, [r8, #0x4]!
 *   @0x1e0370 cmp r5, #0
 *   @0x1e0374 bne 0x1e02ac <_Z11Script_LoadPhjS_+0xc8>
 *   @0x1e0378 mov r6, r5
 *   @0x1e037c b 0x1e0328 <_Z11Script_LoadPhjS_+0x144>
 *   @0x1e0380 ldr r11, [sp, #0x1c]
 *   @0x1e0384 mov r7, r10
 *   @0x1e0388 mov r10, r9
 *   @0x1e038c ldr r2, [sp, #0xc]
 *   @0x1e0390 ldr r3, [r2]
 *   @0x1e0394 cmp r3, #0
 *   @0x1e0398 ble 0x1e0428 <_Z11Script_LoadPhjS_+0x244>
 *   @0x1e039c ldr r2, [sp, #0x4]
 *   @0x1e03a0 mov r4, #0
 *   @0x1e03a4 ldr r3, [pc, #0xb4]
 *   @0x1e03a8 mov r12, r7
 *   @0x1e03ac mov r8, r4
 *   @0x1e03b0 lsl r5, r2, #2
 *   @0x1e03b4 ldr r2, [r11, r3]
 *   @0x1e03b8 mov r7, r2
 *   @0x1e03bc ldr r3, [r7]
 *   @0x1e03c0 add r8, r8, #1
 *   @0x1e03c4 add r11, r3, r4
 *   @0x1e03c8 ldr r0, [r3, r4]
 *   @0x1e03cc add r4, r4, #12
 *   @0x1e03d0 str r12, [sp]
 *   @0x1e03d4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1e03d8 mov r9, r0
 *   @0x1e03dc mov r0, #28
 *   @0x1e03e0 bl 0x27c524 <_Znwj>
 *   @0x1e03e4 mov r1, r9
 *   @0x1e03e8 mov r6, r0
 *   @0x1e03ec bl 0x1dfc04 <_ZN7CScriptC2EPKc>
 *   @0x1e03f0 ldr r1, [r11, #0x4]
 *   @0x1e03f4 ldr r12, [sp]
 *   @0x1e03f8 ldr r2, [sp, #0xc]
 *   @0x1e03fc str r1, [r6, #0x10]
 *   @0x1e0400 ldr r3, [r12, #0x4]
 *   @0x1e0404 ldr r1, [r11, #0x8]
 *   @0x1e0408 ldr r0, [r2]
 *   @0x1e040c str r1, [r6, #0x18]
 *   @0x1e0410 cmp r0, r8
 *   @0x1e0414 str r6, [r3, r5]
 *   @0x1e0418 ldr r3, [r10]
 *   @0x1e041c str r9, [r3, r5]
 *   @0x1e0420 add r5, r5, #4
 *   @0x1e0424 bgt 0x1e03bc <_Z11Script_LoadPhjS_+0x1d8>
 *   @0x1e0428 mov r0, #1
 *   @0x1e042c add sp, sp, #36
 *   @0x1e0430 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e0434 mov r5, r7
 *   @0x1e0438 b 0x1e0378 <_Z11Script_LoadPhjS_+0x194>
 *   @0x1e043c eoreq r1, r1, r4, asr r10
 *   @0x1e0440 .word 0xfffff0e4
 *   @0x1e0444 .word 0xfffff0dc
 *   @0x1e0448 .word 0xfffff0d8
 *   @0x1e044c andseq r1, r7, r8, ror #21
 *   @0x1e0450 .word 0xfffff0e0
 *   @0x1e0454 andseq lr, r4, r6, lsr #17
 *   @0x1e0458 andseq r1, r7, r12, ror #20
 *   @0x1e045c .word 0xffffbcf4
 *   @0x1e0460 .word 0xfffff0e8
 *
 * ══ §40/46 HandleOverflow()  0x176bb0  size 636  159 条（0x176bb0..0x176e2c）
 * @func 0x176bb0 0x176e2c  size 636  159 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x176bbc→0x490004, 0x176be4→0x490008, 0x176c24→0x490008, 0x176c2c→0x49000c, 0x176c6c→0x49000c, 0x176cc4→0x49000c, 0x176cfc→0x49000c, 0x176d04→0x490008
 * 调用序列: GR_3D_Primitive_End()
 * 字段偏移 top8: 0x25c×2 / 0x238×1 / 0x1f8×1 / 0x1f4×1 / 0x1b4×1 / 0x15c×1 / 0x124×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x176bb0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x176bb4 sub sp, sp, #72
 *   @0x176bb8 ldr r4, [pc, #0x25c]
 *   @0x176bbc ldr r3, [pc, #0x25c]
 *   @0x176bc0 add r4, pc, r4
 *   @0x176bc4 ldr r7, [r4, r3]
 *   @0x176bc8 ldr r3, [r7]
 *   @0x176bcc cmp r3, #5
 *   @0x176bd0 beq 0x176d5c <_Z14HandleOverflowv+0x1ac>
 *   @0x176bd4 cmp r3, #6
 *   @0x176bd8 beq 0x176cfc <_Z14HandleOverflowv+0x14c>
 *   @0x176bdc cmp r3, #3
 *   @0x176be0 beq 0x176c24 <_Z14HandleOverflowv+0x74>
 *   @0x176be4 ldr r3, [pc, #0x238]
 *   @0x176be8 ldr r5, [r4, r3]
 *   @0x176bec ldr r6, [r5]
 *   @0x176bf0 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x176bf4 ldr r3, [r7]
 *   @0x176bf8 mov r2, #0
 *   @0x176bfc str r2, [r5]
 *   @0x176c00 cmp r3, #5
 *   @0x176c04 beq 0x176c64 <_Z14HandleOverflowv+0xb4>
 *   @0x176c08 cmp r3, #6
 *   @0x176c0c beq 0x176c6c <_Z14HandleOverflowv+0xbc>
 *   @0x176c10 cmp r3, #3
 *   @0x176c14 beq 0x176cc4 <_Z14HandleOverflowv+0x114>
 *   @0x176c18 mov r0, #1
 *   @0x176c1c add sp, sp, #72
 *   @0x176c20 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x176c24 ldr r2, [pc, #0x1f8]
 *   @0x176c28 mov r12, sp
 *   @0x176c2c ldr r3, [pc, #0x1f4]
 *   @0x176c30 ldr r5, [r4, r2]
 *   @0x176c34 ldr r2, [r4, r3]
 *   @0x176c38 ldr r6, [r5]
 *   @0x176c3c sub r3, r6, #1
 *   @0x176c40 add r3, r3, r3, lsl #3
 *   @0x176c44 add lr, r2, r3, lsl #2
 *   @0x176c48 ldm lr!, {r0, r1, r2, r3}
 *   @0x176c4c stm r12!, {r0, r1, r2, r3}
 *   @0x176c50 ldm lr!, {r0, r1, r2, r3}
 *   @0x176c54 ldr lr, [lr]
 *   @0x176c58 stm r12!, {r0, r1, r2, r3}
 *   @0x176c5c str lr, [r12]
 *   @0x176c60 b 0x176bf0 <_Z14HandleOverflowv+0x40>
 *   @0x176c64 tst r6, #1
 *   @0x176c68 bne 0x176dc4 <_Z14HandleOverflowv+0x214>
 *   @0x176c6c ldr r8, [pc, #0x1b4]
 *   @0x176c70 mov r7, sp
 *   @0x176c74 ldm r7!, {r0, r1, r2, r3}
 *   @0x176c78 mov r12, #2
 *   @0x176c7c ldr r4, [r4, r8]
 *   @0x176c80 add r6, sp, #36
 *   @0x176c84 str r12, [r5]
 *   @0x176c88 add r12, r4, #36
 *   @0x176c8c stm r4!, {r0, r1, r2, r3}
 *   @0x176c90 ldm r7!, {r0, r1, r2, r3}
 *   @0x176c94 stm r4!, {r0, r1, r2, r3}
 *   @0x176c98 ldm r6!, {r0, r1, r2, r3}
 *   @0x176c9c ldr r5, [r7]
 *   @0x176ca0 stm r12!, {r0, r1, r2, r3}
 *   @0x176ca4 ldm r6!, {r0, r1, r2, r3}
 *   @0x176ca8 str r5, [r4]
 *   @0x176cac stm r12!, {r0, r1, r2, r3}
 *   @0x176cb0 mov r0, #1
 *   @0x176cb4 ldr r3, [r6]
 *   @0x176cb8 str r3, [r12]
 *   @0x176cbc add sp, sp, #72
 *   @0x176cc0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x176cc4 ldr r12, [pc, #0x15c]
 *   @0x176cc8 mov r6, sp
 *   @0x176ccc mov r3, #1
 *   @0x176cd0 str r3, [r5]
 *   @0x176cd4 ldm r6!, {r0, r1, r2, r3}
 *   @0x176cd8 ldr r12, [r4, r12]
 *   @0x176cdc stm r12!, {r0, r1, r2, r3}
 *   @0x176ce0 ldm r6!, {r0, r1, r2, r3}
 *   @0x176ce4 ldr r4, [r6]
 *   @0x176ce8 stm r12!, {r0, r1, r2, r3}
 *   @0x176cec mov r0, #1
 *   @0x176cf0 str r4, [r12]
 *   @0x176cf4 add sp, sp, #72
 *   @0x176cf8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x176cfc ldr r3, [pc, #0x124]
 *   @0x176d00 mov r5, sp
 *   @0x176d04 ldr lr, [pc, #0x118]
 *   @0x176d08 add r12, sp, #36
 *   @0x176d0c ldr r8, [r4, r3]
 *   @0x176d10 mov r6, r8
 *   @0x176d14 ldm r6!, {r0, r1, r2, r3}
 *   @0x176d18 stm r5!, {r0, r1, r2, r3}
 *   @0x176d1c ldm r6!, {r0, r1, r2, r3}
 *   @0x176d20 ldr r6, [r6]
 *   @0x176d24 stm r5!, {r0, r1, r2, r3}
 *   @0x176d28 str r6, [r5]
 *   @0x176d2c ldr r5, [r4, lr]
 *   @0x176d30 ldr r6, [r5]
 *   @0x176d34 sub lr, r6, #1
 *   @0x176d38 add lr, lr, lr, lsl #3
 *   @0x176d3c add lr, r8, lr, lsl #2
 *   @0x176d40 ldm lr!, {r0, r1, r2, r3}
 *   @0x176d44 stm r12!, {r0, r1, r2, r3}
 *   @0x176d48 ldm lr!, {r0, r1, r2, r3}
 *   @0x176d4c stm r12!, {r0, r1, r2, r3}
 *   @0x176d50 ldr r3, [lr]
 *   @0x176d54 str r3, [r12]
 *   @0x176d58 b 0x176bf0 <_Z14HandleOverflowv+0x40>
 *   @0x176d5c ldr r2, [pc, #0xc0]
 *   @0x176d60 mov r8, sp
 *   @0x176d64 ldr r3, [pc, #0xbc]
 *   @0x176d68 add r12, sp, #36
 *   @0x176d6c ldr r5, [r4, r2]
 *   @0x176d70 ldr r3, [r4, r3]
 *   @0x176d74 ldr r6, [r5]
 *   @0x176d78 sub r9, r6, #2
 *   @0x176d7c sub lr, r6, #1
 *   @0x176d80 add r9, r9, r9, lsl #3
 *   @0x176d84 add lr, lr, lr, lsl #3
 *   @0x176d88 add r9, r3, r9, lsl #2
 *   @0x176d8c add lr, r3, lr, lsl #2
 *   @0x176d90 ldm r9!, {r0, r1, r2, r3}
 *   @0x176d94 stm r8!, {r0, r1, r2, r3}
 *   @0x176d98 ldm r9!, {r0, r1, r2, r3}
 *   @0x176d9c stm r8!, {r0, r1, r2, r3}
 *   @0x176da0 ldm lr!, {r0, r1, r2, r3}
 *   @0x176da4 ldr r9, [r9]
 *   @0x176da8 stm r12!, {r0, r1, r2, r3}
 *   @0x176dac ldm lr!, {r0, r1, r2, r3}
 *   @0x176db0 str r9, [r8]
 *   @0x176db4 stm r12!, {r0, r1, r2, r3}
 *   @0x176db8 ldr r3, [lr]
 *   @0x176dbc str r3, [r12]
 *   @0x176dc0 b 0x176bf0 <_Z14HandleOverflowv+0x40>
 *   @0x176dc4 ldr r12, [pc, #0x5c]
 *   @0x176dc8 mov r8, sp
 *   @0x176dcc ldm r8!, {r0, r1, r2, r3}
 *   @0x176dd0 mov r9, sp
 *   @0x176dd4 ldr r7, [r4, r12]
 *   @0x176dd8 add r6, sp, #36
 *   @0x176ddc mov r10, #3
 *   @0x176de0 add r4, r7, #36
 *   @0x176de4 add r12, r7, #72
 *   @0x176de8 stm r7!, {r0, r1, r2, r3}
 *   @0x176dec ldm r8!, {r0, r1, r2, r3}
 *   @0x176df0 stm r7!, {r0, r1, r2, r3}
 *   @0x176df4 ldm r9!, {r0, r1, r2, r3}
 *   @0x176df8 ldr r8, [r8]
 *   @0x176dfc stm r4!, {r0, r1, r2, r3}
 *   @0x176e00 ldm r9!, {r0, r1, r2, r3}
 *   @0x176e04 str r8, [r7]
 *   @0x176e08 stm r4!, {r0, r1, r2, r3}
 *   @0x176e0c ldm r6!, {r0, r1, r2, r3}
 *   @0x176e10 str r8, [r4]
 *   @0x176e14 str r10, [r5]
 *   @0x176e18 b 0x176cdc <_Z14HandleOverflowv+0x12c>
 *   @0x176e1c mlaeq r7, r0, r0, r11
 *   @0x176e20 .word 0xffffe674
 *   @0x176e24 .word 0xffffe670
 *   @0x176e28 .word 0xffffe680
 *
 * ══ §41/46 YYGML_Variable_GetValue(int, int, int, RValue*)  0x1f40cc  size 636  159 条（0x1f40cc..0x1f4348）
 * @func 0x1f40cc 0x1f4348  size 636  159 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1f40fc→0x536f28, 0x1f4188→0x542374, 0x1f4230→0x54298c, 0x1f4278→0x542a64, 0x1f42d0→0x542a4c
 * 调用序列: YYGML_Variable_GetValue(int, int, int, RValue*)+0xb0×2 / YYGML_Variable_GetValue(int, int, int, RValue*)+0xbc / YYObjectBase::InternalGetYYVar(int) / GET_RValue(RValue*, RValue*, int) / YYGML_Variable_GetValue(int, int, int, RValue*)+0x204
 * 字段偏移 top8: 0x4×8 / 0x8×6 / 0x68×5 / 0x69×4 / 0x3×2 / 0xc×2 / 0x2×2 / 0x7c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f40cc push {r4, r5, r6, r7, r8, lr}
 *   @0x1f40d0 cmn r0, #3
 *   @0x1f40d4 ldr r6, [pc, #0x254]
 *   @0x1f40d8 sub sp, sp, #8
 *   @0x1f40dc add r6, pc, r6
 *   @0x1f40e0 beq 0x1f4230 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x164>
 *   @0x1f40e4 cmp r0, #0
 *   @0x1f40e8 blt 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0>
 *   @0x1f40ec movw r12, #0x869f
 *   @0x1f40f0 movt r12, #0x1
 *   @0x1f40f4 cmp r0, r12
 *   @0x1f40f8 ble 0x1f4188 <_Z23YYGML_Variable_GetValueiiiP6RValue+0xbc>
 *   @0x1f40fc ldr r12, [pc, #0x230]
 *   @0x1f4100 ldr r12, [r6, r12]
 *   @0x1f4104 ldr r4, [r12, #0x4]
 *   @0x1f4108 ldr r12, [r12]
 *   @0x1f410c and r4, r0, r4
 *   @0x1f4110 ldr r12, [r12, r4, lsl #3]
 *   @0x1f4114 cmp r12, #0
 *   @0x1f4118 bne 0x1f412c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x60>
 *   @0x1f411c b 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0>
 *   @0x1f4120 ldr r12, [r12, #0x4]
 *   @0x1f4124 cmp r12, #0
 *   @0x1f4128 beq 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0>
 *   @0x1f412c ldr r4, [r12, #0x8]
 *   @0x1f4130 cmp r0, r4
 *   @0x1f4134 bne 0x1f4120 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x54>
 *   @0x1f4138 ldr r0, [r12, #0xc]
 *   @0x1f413c cmp r0, #0
 *   @0x1f4140 beq 0x1f4180 <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb4>
 *   @0x1f4144 ldrb r12, [r0, #0x68]
 *   @0x1f4148 cmp r12, #0
 *   @0x1f414c bne 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0>
 *   @0x1f4150 ldr r12, [r0, #0x4]
 *   @0x1f4154 cmp r12, #0
 *   @0x1f4158 addne r1, r12, r1, lsl #4
 *   @0x1f415c bne 0x1f421c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x150>
 *   @0x1f4160 str r2, [sp, #0x4]
 *   @0x1f4164 str r3, [sp]
 *   @0x1f4168 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f416c ldr r3, [sp]
 *   @0x1f4170 ldr r2, [sp, #0x4]
 *   @0x1f4174 mov r1, r0
 *   @0x1f4178 b 0x1f421c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x150>
 *   @0x1f417c mov r0, #0
 *   @0x1f4180 add sp, sp, #8
 *   @0x1f4184 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f4188 ldr r12, [pc, #0x1a8]
 *   @0x1f418c ldr r12, [r6, r12]
 *   @0x1f4190 ldr r12, [r12]
 *   @0x1f4194 ldr r4, [r12, #0x4]
 *   @0x1f4198 ldr r12, [r12]
 *   @0x1f419c and r4, r0, r4
 *   @0x1f41a0 ldr r12, [r12, r4, lsl #3]
 *   @0x1f41a4 cmp r12, #0
 *   @0x1f41a8 bne 0x1f41bc <_Z23YYGML_Variable_GetValueiiiP6RValue+0xf0>
 *   @0x1f41ac b 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac>
 *   @0x1f41b0 ldr r12, [r12, #0x4]
 *   @0x1f41b4 cmp r12, #0
 *   @0x1f41b8 beq 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac>
 *   @0x1f41bc ldr r4, [r12, #0x8]
 *   @0x1f41c0 cmp r0, r4
 *   @0x1f41c4 bne 0x1f41b0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0xe4>
 *   @0x1f41c8 ldr r12, [r12, #0xc]
 *   @0x1f41cc cmp r12, #0
 *   @0x1f41d0 ldrne r12, [r12, #0xd0]
 *   @0x1f41d4 beq 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac>
 *   @0x1f41d8 cmp r12, #0
 *   @0x1f41dc beq 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac>
 *   @0x1f41e0 ldr r4, [r12, #0x8]
 *   @0x1f41e4 cmp r4, #0
 *   @0x1f41e8 beq 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac>
 *   @0x1f41ec ldr r4, [r12, #0x8]
 *   @0x1f41f0 ldr r12, [r12]
 *   @0x1f41f4 ldrb r5, [r4, #0x68]
 *   @0x1f41f8 cmp r5, #0
 *   @0x1f41fc bne 0x1f41d8 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x10c>
 *   @0x1f4200 ldrb r5, [r4, #0x69]
 *   @0x1f4204 cmp r5, #0
 *   @0x1f4208 bne 0x1f41d8 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x10c>
 *   @0x1f420c ldr r0, [r4, #0x4]
 *   @0x1f4210 cmp r0, #0
 *   @0x1f4214 addne r1, r0, r1, lsl #4
 *   @0x1f4218 beq 0x1f4328 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x25c>
 *   @0x1f421c mov r0, r3
 *   @0x1f4220 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1f4224 mov r0, #1
 *   @0x1f4228 add sp, sp, #8
 *   @0x1f422c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f4230 ldr r0, [pc, #0x104]
 *   @0x1f4234 ldr r0, [r6, r0]
 *   @0x1f4238 ldr r0, [r0]
 *   @0x1f423c ldr r4, [r0, #0x80]
 *   @0x1f4240 cmp r4, #0
 *   @0x1f4244 bne 0x1f4258 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x18c>
 *   @0x1f4248 b 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0>
 *   @0x1f424c cmp r12, #0
 *   @0x1f4250 mov r4, r12
 *   @0x1f4254 beq 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0>
 *   @0x1f4258 ldrb r0, [r4, #0x68]
 *   @0x1f425c ldr r12, [r4, #0x178]
 *   @0x1f4260 cmp r0, #0
 *   @0x1f4264 bne 0x1f424c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x180>
 *   @0x1f4268 ldrb r0, [r4, #0x69]
 *   @0x1f426c cmp r0, #0
 *   @0x1f4270 bne 0x1f424c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x180>
 *   @0x1f4274 b 0x1f420c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x140>
 *   @0x1f4278 ldr r12, [pc, #0xc0]
 *   @0x1f427c ldr r12, [r6, r12]
 *   @0x1f4280 ldr r7, [r12, #0x8]
 *   @0x1f4284 cmp r7, #0
 *   @0x1f4288 ble 0x1f42d0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x204>
 *   @0x1f428c ldr r8, [r12]
 *   @0x1f4290 mov r12, #0
 *   @0x1f4294 b 0x1f42a0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1d4>
 *   @0x1f4298 cmp r12, r7
 *   @0x1f429c beq 0x1f42d0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x204>
 *   @0x1f42a0 ldr r4, [r8, r12, lsl #2]
 *   @0x1f42a4 add r12, r12, #1
 *   @0x1f42a8 ldr r5, [r4, #0x7c]
 *   @0x1f42ac cmp r0, r5
 *   @0x1f42b0 bne 0x1f4298 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1cc>
 *   @0x1f42b4 ldrb r5, [r4, #0x68]
 *   @0x1f42b8 cmp r5, #0
 *   @0x1f42bc bne 0x1f4298 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1cc>
 *   @0x1f42c0 ldrb r5, [r4, #0x69]
 *   @0x1f42c4 cmp r5, #0
 *   @0x1f42c8 bne 0x1f4298 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1cc>
 *   @0x1f42cc b 0x1f420c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x140>
 *   @0x1f42d0 ldr r12, [pc, #0x6c]
 *   @0x1f42d4 ldr r12, [r6, r12]
 *   @0x1f42d8 ldr r6, [r12, #0x8]
 *   @0x1f42dc cmp r6, #0
 *   @0x1f42e0 ble 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0>
 *   @0x1f42e4 ldr r7, [r12]
 *   @0x1f42e8 mov r12, #0
 *   @0x1f42ec b 0x1f42f8 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x22c>
 *   @0x1f42f0 cmp r12, r6
 *   @0x1f42f4 beq 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0>
 *   @0x1f42f8 ldr r4, [r7, r12, lsl #2]
 *   @0x1f42fc add r12, r12, #1
 *   @0x1f4300 ldr r5, [r4, #0x7c]
 *   @0x1f4304 cmp r0, r5
 *   @0x1f4308 bne 0x1f42f0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x224>
 *   @0x1f430c ldrb r5, [r4, #0x68]
 *   @0x1f4310 cmp r5, #0
 *   @0x1f4314 bne 0x1f42f0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x224>
 *   @0x1f4318 ldrb r5, [r4, #0x69]
 *   @0x1f431c cmp r5, #0
 *   @0x1f4320 bne 0x1f42f0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x224>
 *   @0x1f4324 b 0x1f420c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x140>
 *   @0x1f4328 mov r0, r4
 *   @0x1f432c b 0x1f4160 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x94>
 *   @0x1f4330 andseq sp, pc, r4, ror r11
 *   @0x1f4334 .word 0xffffbff4
 *   @0x1f4338 .word 0xffffbfec
 *   @0x1f433c .word 0xffffbcd8
 *   @0x1f4340 .word 0xffffbff0
 *   @0x1f4344 .word 0xffffbff8
 *
 * ══ §42/46 b2ParticleSystem::ComputeDepthForGroup(b2ParticleGroup*)  0x2d5920  size 636  159 条（0x2d5920..0x2d5b9c）
 * @func 0x2d5920 0x2d5b9c  size 636  159 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::ComputeDepthForGroup(b2ParticleGroup*)+0x24c×2 / b2ParticleSystem::ComputeDepthForGroup(b2ParticleGroup*)+0xb0 / b2ParticleSystem::ComputeDepthForGroup(b2ParticleGroup*)+0x184 / b2ParticleSystem::ComputeDepthForGroup(b2ParticleGroup*)+0x138 / b2ParticleSystem::ComputeDepthForGroup(b2ParticleGroup*)+0x17c / b2BlockAllocator::Allocate(int) / 0xb65b0
 * 字段偏移 top8: 0x4×9 / 0x48×3 / 0x74×2 / 0x7c×2 / 0x-c×2 / 0x-8×2 / 0x50×2 / 0x8×2
 * VFP 指令 38 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5920 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d5924 mov r4, r1
 *   @0x2d5928 ldmib r1, {r1, r5}
 *   @0x2d592c sub sp, sp, #12
 *   @0x2d5930 mov r9, r0
 *   @0x2d5934 cmp r1, r5
 *   @0x2d5938 bge 0x2d5958 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x38>
 *   @0x2d593c ldr r2, [r0, #0x48]
 *   @0x2d5940 mov r0, #0
 *   @0x2d5944 add r3, r2, r1, lsl #2
 *   @0x2d5948 add r2, r2, r5, lsl #2
 *   @0x2d594c str r0, [r3], #4
 *   @0x2d5950 cmp r3, r2
 *   @0x2d5954 bne 0x2d594c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x2c>
 *   @0x2d5958 ldr r12, [r9, #0x74]
 *   @0x2d595c cmp r12, #0
 *   @0x2d5960 ble 0x2d59d0 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xb0>
 *   @0x2d5964 ldr r3, [r9, #0x7c]
 *   @0x2d5968 add r12, r12, r12, lsl #1
 *   @0x2d596c add r3, r3, #12
 *   @0x2d5970 add r12, r3, r12, lsl #3
 *   @0x2d5974 ldr r2, [r3, #-0xc]
 *   @0x2d5978 ldr r0, [r3, #-0x8]
 *   @0x2d597c cmp r1, r2
 *   @0x2d5980 bgt 0x2d59c4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xa4>
 *   @0x2d5984 cmp r2, r5
 *   @0x2d5988 bge 0x2d59c4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xa4>
 *   @0x2d598c cmp r1, r0
 *   @0x2d5990 bgt 0x2d59c4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xa4>
 *   @0x2d5994 cmp r0, r5
 *   @0x2d5998 bge 0x2d59c4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xa4>
 *   @0x2d599c ldr r6, [r9, #0x48]
 *   @0x2d59a0 vldr s15, [r3]
 *   @0x2d59a4 add r2, r6, r2, lsl #2
 *   @0x2d59a8 vldr s14, [r2]
 *   @0x2d59ac vadd.f32 s14, s14, s15
 *   @0x2d59b0 add r0, r6, r0, lsl #2
 *   @0x2d59b4 vstr s14, [r2]
 *   @0x2d59b8 vldr s14, [r0]
 *   @0x2d59bc vadd.f32 s15, s14, s15
 *   @0x2d59c0 vstr s15, [r0]
 *   @0x2d59c4 add r3, r3, #24
 *   @0x2d59c8 cmp r3, r12
 *   @0x2d59cc bne 0x2d5974 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x54>
 *   @0x2d59d0 ldr r6, [r9, #0x50]
 *   @0x2d59d4 cmp r6, #0
 *   @0x2d59d8 beq 0x2d5aac <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x18c>
 *   @0x2d59dc str r1, [sp, #0x4]
 *   @0x2d59e0 ldr r3, [sp, #0x4]
 *   @0x2d59e4 str r6, [r9, #0x50]
 *   @0x2d59e8 cmp r5, r3
 *   @0x2d59ec ble 0x2d5aa4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x184>
 *   @0x2d59f0 ldr r0, [r9, #0x48]
 *   @0x2d59f4 lsl r3, r3, #2
 *   @0x2d59f8 add r2, r6, r3
 *   @0x2d59fc vldr s12, [pc, #396]
 *   @0x2d5a00 add r1, r0, r5, lsl #2
 *   @0x2d5a04 add r3, r0, r3
 *   @0x2d5a08 vldr s13, [pc, #388]
 *   @0x2d5a0c vldr s14, [pc, #388]
 *   @0x2d5a10 vldmia r3!, {s15}
 *   @0x2d5a14 vcmpe.f32 s15, s12
 *   @0x2d5a18 vmrs APSR_nzcv, fpscr
 *   @0x2d5a1c vmovpl.f32 s15, s14
 *   @0x2d5a20 vmovmi.f32 s15, s13
 *   @0x2d5a24 cmp r3, r1
 *   @0x2d5a28 vstmia r2!, {s15}
 *   @0x2d5a2c bne 0x2d5a10 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xf0>
 *   @0x2d5a30 ldr r12, [r4, #0x4]
 *   @0x2d5a34 ldr r5, [r4, #0x8]
 *   @0x2d5a38 rsb r10, r12, r5
 *   @0x2d5a3c cmp r10, #0
 *   @0x2d5a40 ble 0x2d5a58 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x138>
 *   @0x2d5a44 ldr r3, [r9, #0x74]
 *   @0x2d5a48 cmp r3, #0
 *   @0x2d5a4c add r3, r3, r3, lsl #1
 *   @0x2d5a50 lsl r4, r3, #3
 *   @0x2d5a54 bgt 0x2d5ae0 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x1c0>
 *   @0x2d5a58 ldr r3, [sp, #0x4]
 *   @0x2d5a5c cmp r5, r3
 *   @0x2d5a60 ble 0x2d5a9c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x17c>
 *   @0x2d5a64 ldr r2, [sp, #0x4]
 *   @0x2d5a68 add r5, r6, r5, lsl #2
 *   @0x2d5a6c vldr s14, [pc, #292]
 *   @0x2d5a70 add r3, r6, r2, lsl #2
 *   @0x2d5a74 mov r2, #0
 *   @0x2d5a78 vldmia r3!, {s15}
 *   @0x2d5a7c vcmpe.f32 s15, s14
 *   @0x2d5a80 vmrs APSR_nzcv, fpscr
 *   @0x2d5a84 vldrmi s13, [r9, #24]
 *   @0x2d5a88 vmulmi.f32 s15, s15, s13
 *   @0x2d5a8c strpl r2, [r3, #-0x4]
 *   @0x2d5a90 vstrmi s15, [r3, #-4]
 *   @0x2d5a94 cmp r3, r5
 *   @0x2d5a98 bne 0x2d5a78 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x158>
 *   @0x2d5a9c add sp, sp, #12
 *   @0x2d5aa0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d5aa4 ldr r12, [sp, #0x4]
 *   @0x2d5aa8 b 0x2d5a38 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x118>
 *   @0x2d5aac ldr r1, [r9, #0x28]
 *   @0x2d5ab0 ldr r0, [r9, #0xd4]
 *   @0x2d5ab4 lsl r1, r1, #2
 *   @0x2d5ab8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2d5abc ldr r2, [r9, #0x28]
 *   @0x2d5ac0 mov r1, #0
 *   @0x2d5ac4 lsl r2, r2, #2
 *   @0x2d5ac8 mov r6, r0
 *   @0x2d5acc bl 0xb65b0 <memset@plt>
 *   @0x2d5ad0 ldr r2, [r4, #0x4]
 *   @0x2d5ad4 ldr r5, [r4, #0x8]
 *   @0x2d5ad8 str r2, [sp, #0x4]
 *   @0x2d5adc b 0x2d59e0 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0xc0>
 *   @0x2d5ae0 vmov.f32 s11, #1.000000e+00
 *   @0x2d5ae4 ldr r3, [r9, #0x7c]
 *   @0x2d5ae8 mov r7, #0
 *   @0x2d5aec add r11, r3, #12
 *   @0x2d5af0 add r4, r11, r4
 *   @0x2d5af4 mov r3, r11
 *   @0x2d5af8 mov r8, #0
 *   @0x2d5afc ldr r2, [r3, #-0xc]
 *   @0x2d5b00 ldr r1, [r3, #-0x8]
 *   @0x2d5b04 cmp r2, r12
 *   @0x2d5b08 blt 0x2d5b6c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x24c>
 *   @0x2d5b0c cmp r2, r5
 *   @0x2d5b10 bge 0x2d5b6c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x24c>
 *   @0x2d5b14 cmp r1, r12
 *   @0x2d5b18 blt 0x2d5b6c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x24c>
 *   @0x2d5b1c cmp r1, r5
 *   @0x2d5b20 add r0, r6, r1, lsl #2
 *   @0x2d5b24 add r2, r6, r2, lsl #2
 *   @0x2d5b28 bge 0x2d5b6c <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x24c>
 *   @0x2d5b2c vldr s15, [r3]
 *   @0x2d5b30 vsub.f32 s15, s11, s15
 *   @0x2d5b34 vldr s13, [r0]
 *   @0x2d5b38 vldr s14, [r2]
 *   @0x2d5b3c vmov.f32 s12, s13
 *   @0x2d5b40 vadd.f32 s13, s13, s15
 *   @0x2d5b44 vadd.f32 s15, s14, s15
 *   @0x2d5b48 vcmpe.f32 s13, s14
 *   @0x2d5b4c vmrs APSR_nzcv, fpscr
 *   @0x2d5b50 vstrmi s13, [r2]
 *   @0x2d5b54 vldrmi s12, [r0]
 *   @0x2d5b58 vcmpe.f32 s15, s12
 *   @0x2d5b5c movmi r8, #1
 *   @0x2d5b60 vmrs APSR_nzcv, fpscr
 *   @0x2d5b64 movmi r8, #1
 *   @0x2d5b68 vstrmi s15, [r0]
 *   @0x2d5b6c add r3, r3, #24
 *   @0x2d5b70 cmp r3, r4
 *   @0x2d5b74 bne 0x2d5afc <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x1dc>
 *   @0x2d5b78 cmp r8, #0
 *   @0x2d5b7c beq 0x2d5a58 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x138>
 *   @0x2d5b80 add r7, r7, #1
 *   @0x2d5b84 cmp r7, r10
 *   @0x2d5b88 bne 0x2d5af4 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x1d4>
 *   @0x2d5b8c b 0x2d5a58 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup+0x138>
 *   @0x2d5b90 svclo #0x4ccccd
 *   @0x2d5b94 andeq r0, r0, r0
 *   @0x2d5b98 svcvc #0x7fffff
 *
 * ══ §43/46 YYGML_choose(YYRValue&, int, YYRValue**)  0x1143ac  size 632  158 条（0x1143ac..0x114624）
 * @func 0x1143ac 0x114624  size 632  158 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYRandom(int) / 0xb6598 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x8×8 / 0x4×8 / 0xc×5 / 0x2×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1143ac push {r3, r4, r5, r6, r7, lr}
 *   @0x1143b0 mov r4, r0
 *   @0x1143b4 mov r0, r1
 *   @0x1143b8 mov r5, r2
 *   @0x1143bc bl 0xc4600 <_Z8YYRandomi>
 *   @0x1143c0 vldr s15, [pc, #600]
 *   @0x1143c4 vmov s12, r0
 *   @0x1143c8 vcvt.f32.u32 s14, s12
 *   @0x1143cc vadd.f32 s15, s14, s15
 *   @0x1143d0 vcvt.f64.f32 d6, s15
 *   @0x1143d4 vmov r0, r1, d6
 *   @0x1143d8 bl 0xb6598 <floor@plt>
 *   @0x1143dc ldr r12, [r4, #0xc]
 *   @0x1143e0 bic r3, r12, #-16777216
 *   @0x1143e4 cmp r3, #1
 *   @0x1143e8 vmov d7, r0, r1
 *   @0x1143ec vcvt.s32.f64 s15, d7
 *   @0x1143f0 vmov r0, s15
 *   @0x1143f4 ldr r5, [r5, r0, lsl #2]
 *   @0x1143f8 beq 0x1144b0 <_Z12YYGML_chooseR8YYRValueiPPS_+0x104>
 *   @0x1143fc cmp r3, #2
 *   @0x114400 bne 0x114428 <_Z12YYGML_chooseR8YYRValueiPPS_+0x7c>
 *   @0x114404 sub r12, r12, #1
 *   @0x114408 bic r12, r12, #-16777216
 *   @0x11440c bic r12, r12, #3
 *   @0x114410 cmp r12, #0
 *   @0x114414 beq 0x114584 <_Z12YYGML_chooseR8YYRValueiPPS_+0x1d8>
 *   @0x114418 mov r2, #0
 *   @0x11441c mov r3, #5
 *   @0x114420 str r2, [r4, #0x8]
 *   @0x114424 str r3, [r4, #0xc]
 *   @0x114428 ldr r3, [r5, #0xc]
 *   @0x11442c mov r1, #0
 *   @0x114430 ldr r2, [r5, #0x8]
 *   @0x114434 str r1, [r4]
 *   @0x114438 str r3, [r4, #0xc]
 *   @0x11443c ldr r3, [r5, #0xc]
 *   @0x114440 str r2, [r4, #0x8]
 *   @0x114444 bic r3, r3, #-16777216
 *   @0x114448 cmp r3, #14
 *   @0x11444c addls pc, pc, r3, lsl #2
 *   @0x114450 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x114454 b 0x1144a0 <_Z12YYGML_chooseR8YYRValueiPPS_+0xf4>
 *   @0x114458 b 0x114508 <_Z12YYGML_chooseR8YYRValueiPPS_+0x15c>
 *   @0x11445c b 0x114520 <_Z12YYGML_chooseR8YYRValueiPPS_+0x174>
 *   @0x114460 b 0x114490 <_Z12YYGML_chooseR8YYRValueiPPS_+0xe4>
 *   @0x114464 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x114468 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x11446c b 0x1144e4 <_Z12YYGML_chooseR8YYRValueiPPS_+0x138>
 *   @0x114470 b 0x114490 <_Z12YYGML_chooseR8YYRValueiPPS_+0xe4>
 *   @0x114474 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x114478 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x11447c b 0x1144a0 <_Z12YYGML_chooseR8YYRValueiPPS_+0xf4>
 *   @0x114480 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x114484 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x114488 b 0x1144a0 <_Z12YYGML_chooseR8YYRValueiPPS_+0xf4>
 *   @0x11448c b 0x114490 <_Z12YYGML_chooseR8YYRValueiPPS_+0xe4>
 *   @0x114490 ldr r3, [r5]
 *   @0x114494 str r3, [r4]
 *   @0x114498 mov r0, r4
 *   @0x11449c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1144a0 ldm r5, {r2, r3}
 *   @0x1144a4 mov r0, r4
 *   @0x1144a8 stm r4, {r2, r3}
 *   @0x1144ac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1144b0 ldr r6, [r4]
 *   @0x1144b4 cmp r6, #0
 *   @0x1144b8 beq 0x1144d8 <_Z12YYGML_chooseR8YYRValueiPPS_+0x12c>
 *   @0x1144bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1144c0 ldr r7, [r6, #0x4]
 *   @0x1144c4 sub r7, r7, #1
 *   @0x1144c8 str r7, [r6, #0x4]
 *   @0x1144cc cmp r7, #0
 *   @0x1144d0 beq 0x11454c <_Z12YYGML_chooseR8YYRValueiPPS_+0x1a0>
 *   @0x1144d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1144d8 mov r3, #0
 *   @0x1144dc str r3, [r4]
 *   @0x1144e0 b 0x114428 <_Z12YYGML_chooseR8YYRValueiPPS_+0x7c>
 *   @0x1144e4 ldr r3, [r5]
 *   @0x1144e8 str r3, [r4]
 *   @0x1144ec ldr r3, [r5]
 *   @0x1144f0 cmp r3, #0
 *   @0x1144f4 beq 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x1144f8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1144fc ldr r1, [r5]
 *   @0x114500 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x114504 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x114508 ldr r3, [r5]
 *   @0x11450c cmp r3, #0
 *   @0x114510 ldrne r2, [r3, #0x4]
 *   @0x114514 addne r2, r2, #1
 *   @0x114518 strne r2, [r3, #0x4]
 *   @0x11451c b 0x114494 <_Z12YYGML_chooseR8YYRValueiPPS_+0xe8>
 *   @0x114520 ldr r3, [r5]
 *   @0x114524 cmp r3, #0
 *   @0x114528 str r3, [r4]
 *   @0x11452c beq 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x114530 ldr r1, [r3, #0x8]
 *   @0x114534 ldr r2, [r3]
 *   @0x114538 cmp r1, #0
 *   @0x11453c streq r4, [r3, #0x8]
 *   @0x114540 add r2, r2, #1
 *   @0x114544 str r2, [r3]
 *   @0x114548 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec>
 *   @0x11454c ldr r0, [r6]
 *   @0x114550 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x114554 str r7, [r6]
 *   @0x114558 str r7, [r6, #0x8]
 *   @0x11455c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x114560 ldr r7, [r6, #0x4]
 *   @0x114564 sub r7, r7, #1
 *   @0x114568 str r7, [r6, #0x4]
 *   @0x11456c cmp r7, #0
 *   @0x114570 beq 0x114590 <_Z12YYGML_chooseR8YYRValueiPPS_+0x1e4>
 *   @0x114574 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x114578 mov r0, r6
 *   @0x11457c bl 0x27d1d0 <_ZdlPv>
 *   @0x114580 b 0x1144d4 <_Z12YYGML_chooseR8YYRValueiPPS_+0x128>
 *   @0x114584 mov r0, r4
 *   @0x114588 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x11458c b 0x114418 <_Z12YYGML_chooseR8YYRValueiPPS_+0x6c>
 *   @0x114590 ldr r0, [r6]
 *   @0x114594 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x114598 str r7, [r6]
 *   @0x11459c str r7, [r6, #0x8]
 *   @0x1145a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1145a4 ldr r7, [r6, #0x4]
 *   @0x1145a8 sub r7, r7, #1
 *   @0x1145ac str r7, [r6, #0x4]
 *   @0x1145b0 cmp r7, #0
 *   @0x1145b4 beq 0x1145c8 <_Z12YYGML_chooseR8YYRValueiPPS_+0x21c>
 *   @0x1145b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1145bc mov r0, r6
 *   @0x1145c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1145c4 b 0x114574 <_Z12YYGML_chooseR8YYRValueiPPS_+0x1c8>
 *   @0x1145c8 ldr r0, [r6]
 *   @0x1145cc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1145d0 str r7, [r6]
 *   @0x1145d4 str r7, [r6, #0x8]
 *   @0x1145d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1145dc ldr r7, [r6, #0x4]
 *   @0x1145e0 sub r7, r7, #1
 *   @0x1145e4 str r7, [r6, #0x4]
 *   @0x1145e8 cmp r7, #0
 *   @0x1145ec bne 0x114610 <_Z12YYGML_chooseR8YYRValueiPPS_+0x264>
 *   @0x1145f0 ldr r0, [r6]
 *   @0x1145f4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1145f8 mov r0, r6
 *   @0x1145fc str r7, [r6]
 *   @0x114600 str r7, [r6, #0x8]
 *   @0x114604 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x114608 mov r0, r6
 *   @0x11460c bl 0x27d1d0 <_ZdlPv>
 *   @0x114610 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x114614 mov r0, r6
 *   @0x114618 bl 0x27d1d0 <_ZdlPv>
 *   @0x11461c b 0x1145b8 <_Z12YYGML_chooseR8YYRValueiPPS_+0x20c>
 *   @0x114620 andeq r0, r0, r0
 *
 * ══ §44/46 CPath::ComputeCurved()  0x1a6bb8  size 632  158 条（0x1a6bb8..0x1a6e30）
 * @func 0x1a6bb8 0x1a6e30  size 632  158 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod×3 / CPath::AddInternalPoint(float, float, float)×2 / CPath::ComputeCurved()+0x26c / CPath::ComputeCurved()+0x1f4 / CPath::ComputeCurved()+0x1e4 / CPath::ComputeCurved()+0xfc / CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x4×5 / 0x10×3 / 0x18×3 / 0x8×2 / 0x20×1 / 0x1c×1 / 0xc×1
 * VFP 指令 75 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6bb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a6bbc vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1a6bc0 mov r3, #0
 *   @0x1a6bc4 ldr r7, [r0, #0x10]
 *   @0x1a6bc8 sub sp, sp, #36
 *   @0x1a6bcc mov r5, r0
 *   @0x1a6bd0 str r3, [r0, #0x20]
 *   @0x1a6bd4 cmp r7, r3
 *   @0x1a6bd8 ble 0x1a6e24 <_ZN5CPath13ComputeCurvedEv+0x26c>
 *   @0x1a6bdc ldrb r3, [r0, #0x18]
 *   @0x1a6be0 cmp r3, #0
 *   @0x1a6be4 beq 0x1a6df8 <_ZN5CPath13ComputeCurvedEv+0x240>
 *   @0x1a6be8 sub r11, r7, #1
 *   @0x1a6bec cmp r11, #0
 *   @0x1a6bf0 blt 0x1a6dac <_ZN5CPath13ComputeCurvedEv+0x1f4>
 *   @0x1a6bf4 vmov.f32 s18, #5.000000e-01
 *   @0x1a6bf8 mov r10, #0
 *   @0x1a6bfc mov r6, #1
 *   @0x1a6c00 vmov.f32 s26, #2.500000e-01
 *   @0x1a6c04 vmov.f32 s29, #1.600000e+01
 *   @0x1a6c08 mov r0, r10
 *   @0x1a6c0c mov r1, r7
 *   @0x1a6c10 bl 0x318dec <__aeabi_idivmod>
 *   @0x1a6c14 mov r0, r6
 *   @0x1a6c18 mov r10, r6
 *   @0x1a6c1c add r6, r6, #1
 *   @0x1a6c20 ldr r8, [r5, #0x4]
 *   @0x1a6c24 ldr r4, [r5, #0x1c]
 *   @0x1a6c28 add r9, r1, r1, lsl #1
 *   @0x1a6c2c mov r1, r7
 *   @0x1a6c30 bl 0x318dec <__aeabi_idivmod>
 *   @0x1a6c34 mov r0, r6
 *   @0x1a6c38 add r9, r8, r9, lsl #2
 *   @0x1a6c3c vldr s21, [r9]
 *   @0x1a6c40 vldr s20, [r9, #4]
 *   @0x1a6c44 vldr s27, [r9, #8]
 *   @0x1a6c48 add r3, r1, r1, lsl #1
 *   @0x1a6c4c mov r1, r7
 *   @0x1a6c50 add r3, r8, r3, lsl #2
 *   @0x1a6c54 vldr s17, [r3]
 *   @0x1a6c58 vldr s16, [r3, #4]
 *   @0x1a6c5c vldr s19, [r3, #8]
 *   @0x1a6c60 bl 0x318dec <__aeabi_idivmod>
 *   @0x1a6c64 vadd.f32 s21, s17, s21
 *   @0x1a6c68 cmp r4, #0
 *   @0x1a6c6c vadd.f32 s20, s16, s20
 *   @0x1a6c70 vadd.f32 s27, s19, s27
 *   @0x1a6c74 vmul.f32 s21, s21, s18
 *   @0x1a6c78 add r1, r1, r1, lsl #1
 *   @0x1a6c7c add r8, r8, r1, lsl #2
 *   @0x1a6c80 vldr s25, [r8]
 *   @0x1a6c84 vldr s24, [r8, #4]
 *   @0x1a6c88 vldr s28, [r8, #8]
 *   @0x1a6c8c vadd.f32 s25, s17, s25
 *   @0x1a6c90 vadd.f32 s24, s16, s24
 *   @0x1a6c94 vadd.f32 s28, s19, s28
 *   @0x1a6c98 vmul.f32 s20, s20, s18
 *   @0x1a6c9c vmul.f32 s27, s27, s18
 *   @0x1a6ca0 vmul.f32 s25, s25, s18
 *   @0x1a6ca4 vmul.f32 s24, s24, s18
 *   @0x1a6ca8 vmul.f32 s28, s28, s18
 *   @0x1a6cac bne 0x1a6d10 <_ZN5CPath13ComputeCurvedEv+0x158>
 *   @0x1a6cb0 b 0x1a6d9c <_ZN5CPath13ComputeCurvedEv+0x1e4>
 *   @0x1a6cb4 mov r0, r5
 *   @0x1a6cb8 vmov r1, s23
 *   @0x1a6cbc vmov r2, s30
 *   @0x1a6cc0 vmov r3, s22
 *   @0x1a6cc4 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a6cc8 vsub.f32 s15, s16, s24
 *   @0x1a6ccc vmul.f32 s15, s15, s15
 *   @0x1a6cd0 vsub.f32 s14, s17, s25
 *   @0x1a6cd4 vmla.f32 s15, s14, s14
 *   @0x1a6cd8 vcmpe.f32 s15, s29
 *   @0x1a6cdc vmov.f32 s20, s30
 *   @0x1a6ce0 vmrs APSR_nzcv, fpscr
 *   @0x1a6ce4 vmov.f32 s21, s23
 *   @0x1a6ce8 vmov.f32 s27, s22
 *   @0x1a6cec ble 0x1a6d9c <_ZN5CPath13ComputeCurvedEv+0x1e4>
 *   @0x1a6cf0 subs r4, r4, #1
 *   @0x1a6cf4 vadd.f32 s17, s25, s17
 *   @0x1a6cf8 vadd.f32 s16, s24, s16
 *   @0x1a6cfc vadd.f32 s19, s28, s19
 *   @0x1a6d00 vmul.f32 s17, s17, s18
 *   @0x1a6d04 vmul.f32 s16, s16, s18
 *   @0x1a6d08 vmul.f32 s19, s19, s18
 *   @0x1a6d0c beq 0x1a6d9c <_ZN5CPath13ComputeCurvedEv+0x1e4>
 *   @0x1a6d10 vsub.f32 s15, s16, s20
 *   @0x1a6d14 vmul.f32 s15, s15, s15
 *   @0x1a6d18 vsub.f32 s14, s17, s21
 *   @0x1a6d1c vadd.f32 s11, s21, s17
 *   @0x1a6d20 vadd.f32 s12, s20, s16
 *   @0x1a6d24 vadd.f32 s13, s27, s19
 *   @0x1a6d28 vmla.f32 s15, s14, s14
 *   @0x1a6d2c vadd.f32 s23, s17, s11
 *   @0x1a6d30 vadd.f32 s30, s16, s12
 *   @0x1a6d34 vadd.f32 s22, s19, s13
 *   @0x1a6d38 vadd.f32 s23, s25, s23
 *   @0x1a6d3c vadd.f32 s30, s24, s30
 *   @0x1a6d40 vadd.f32 s22, s28, s22
 *   @0x1a6d44 vcmpe.f32 s15, s29
 *   @0x1a6d48 vmul.f32 s23, s23, s26
 *   @0x1a6d4c vmrs APSR_nzcv, fpscr
 *   @0x1a6d50 vmul.f32 s30, s30, s26
 *   @0x1a6d54 vmul.f32 s22, s22, s26
 *   @0x1a6d58 ble 0x1a6cb4 <_ZN5CPath13ComputeCurvedEv+0xfc>
 *   @0x1a6d5c vstr s27, [sp]
 *   @0x1a6d60 vstr s23, [sp, #16]
 *   @0x1a6d64 vstr s30, [sp, #20]
 *   @0x1a6d68 mov r0, r5
 *   @0x1a6d6c sub r1, r4, #1
 *   @0x1a6d70 vmov r2, s21
 *   @0x1a6d74 vmov r3, s20
 *   @0x1a6d78 vstr s22, [sp, #24]
 *   @0x1a6d7c vmul.f32 s11, s11, s18
 *   @0x1a6d80 vmul.f32 s12, s12, s18
 *   @0x1a6d84 vstr s11, [sp, #4]
 *   @0x1a6d88 vmul.f32 s13, s13, s18
 *   @0x1a6d8c vstr s12, [sp, #8]
 *   @0x1a6d90 vstr s13, [sp, #12]
 *   @0x1a6d94 bl 0x1a6154 <_ZN5CPath11HandlePieceEifffffffff>
 *   @0x1a6d98 b 0x1a6cb4 <_ZN5CPath13ComputeCurvedEv+0xfc>
 *   @0x1a6d9c cmp r11, r10
 *   @0x1a6da0 ldrge r7, [r5, #0x10]
 *   @0x1a6da4 bge 0x1a6c08 <_ZN5CPath13ComputeCurvedEv+0x50>
 *   @0x1a6da8 ldrb r3, [r5, #0x18]
 *   @0x1a6dac cmp r3, #0
 *   @0x1a6db0 beq 0x1a6dd8 <_ZN5CPath13ComputeCurvedEv+0x220>
 *   @0x1a6db4 ldr r3, [r5, #0xc]
 *   @0x1a6db8 mov r0, r5
 *   @0x1a6dbc ldr r1, [r3]
 *   @0x1a6dc0 ldr r2, [r3, #0x4]
 *   @0x1a6dc4 ldr r3, [r3, #0x8]
 *   @0x1a6dc8 add sp, sp, #36
 *   @0x1a6dcc vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1a6dd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a6dd4 b 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a6dd8 ldr r2, [r5, #0x10]
 *   @0x1a6ddc mov r0, r5
 *   @0x1a6de0 ldr r1, [r5, #0x4]
 *   @0x1a6de4 add r2, r2, r2, lsl #1
 *   @0x1a6de8 lsl r3, r2, #2
 *   @0x1a6dec sub r3, r3, #12
 *   @0x1a6df0 add r3, r1, r3
 *   @0x1a6df4 b 0x1a6dbc <_ZN5CPath13ComputeCurvedEv+0x204>
 *   @0x1a6df8 ldr r3, [r0, #0x4]
 *   @0x1a6dfc ldr r1, [r3]
 *   @0x1a6e00 ldr r2, [r3, #0x4]
 *   @0x1a6e04 ldr r3, [r3, #0x8]
 *   @0x1a6e08 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a6e0c ldrb r3, [r5, #0x18]
 *   @0x1a6e10 ldr r7, [r5, #0x10]
 *   @0x1a6e14 cmp r3, #0
 *   @0x1a6e18 subeq r11, r7, #3
 *   @0x1a6e1c beq 0x1a6bec <_ZN5CPath13ComputeCurvedEv+0x34>
 *   @0x1a6e20 b 0x1a6be8 <_ZN5CPath13ComputeCurvedEv+0x30>
 *   @0x1a6e24 add sp, sp, #36
 *   @0x1a6e28 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1a6e2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §45/46 b2ParticleSystem::CreateParticleGroupCallback::operator()(int, int, int) const  0x2d5308  size 632  158 条（0x2d5308..0x2d5580）
 * @func 0x2d5308 0x2d5580  size 632  158 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::CreateParticleGroupCallback::operator()(int, int, int) const+0x268×3 / b2ParticleSystem::CreateParticleGroupCallback::operator()(int, int, int) const+0x158 / b2BlockAllocator::Allocate(int) / 0xb65bc / b2BlockAllocator::Free(void*, int)
 * 字段偏移 top8: 0x4×5 / 0x98×3 / 0xa0×3 / 0xc×3 / 0x2×3 / 0x9c×2 / 0xd4×2 / 0x38×1
 * VFP 指令 87 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5308 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d530c vpush {d8, d9, d10}
 *   @0x2d5310 vmov.f32 s14, #4.000000e+00
 *   @0x2d5314 ldr r7, [r0]
 *   @0x2d5318 vldr s9, [r7, #32]
 *   @0x2d531c sub sp, sp, #20
 *   @0x2d5320 mov r12, r0
 *   @0x2d5324 mov r8, r1
 *   @0x2d5328 mov r9, r2
 *   @0x2d532c ldr r5, [r7, #0x38]
 *   @0x2d5330 mov r10, r3
 *   @0x2d5334 add r6, r5, r1, lsl #3
 *   @0x2d5338 add r4, r5, r2, lsl #3
 *   @0x2d533c vldr s10, [r6, #4]
 *   @0x2d5340 vldr s12, [r4, #4]
 *   @0x2d5344 vldr s11, [r6]
 *   @0x2d5348 vldr s13, [r4]
 *   @0x2d534c add r5, r5, r3, lsl #3
 *   @0x2d5350 vldr s8, [r5]
 *   @0x2d5354 vsub.f32 s17, s10, s12
 *   @0x2d5358 vldr s7, [r5, #4]
 *   @0x2d535c vmul.f32 s15, s17, s17
 *   @0x2d5360 vsub.f32 s16, s11, s13
 *   @0x2d5364 vmla.f32 s15, s16, s16
 *   @0x2d5368 vmul.f32 s14, s9, s14
 *   @0x2d536c vcmpe.f32 s14, s15
 *   @0x2d5370 vmrs APSR_nzcv, fpscr
 *   @0x2d5374 ble 0x2d5570 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii+0x268>
 *   @0x2d5378 vsub.f32 s19, s12, s7
 *   @0x2d537c vmul.f32 s15, s19, s19
 *   @0x2d5380 vsub.f32 s18, s13, s8
 *   @0x2d5384 vmla.f32 s15, s18, s18
 *   @0x2d5388 vcmpe.f32 s14, s15
 *   @0x2d538c vmrs APSR_nzcv, fpscr
 *   @0x2d5390 ble 0x2d5570 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii+0x268>
 *   @0x2d5394 vsub.f32 s21, s7, s10
 *   @0x2d5398 vmul.f32 s15, s21, s21
 *   @0x2d539c vsub.f32 s20, s8, s11
 *   @0x2d53a0 vmla.f32 s15, s20, s20
 *   @0x2d53a4 vcmpe.f32 s14, s15
 *   @0x2d53a8 vmrs APSR_nzcv, fpscr
 *   @0x2d53ac ble 0x2d5570 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii+0x268>
 *   @0x2d53b0 ldr r3, [r7, #0x98]
 *   @0x2d53b4 ldr r2, [r7, #0x9c]
 *   @0x2d53b8 cmp r3, r2
 *   @0x2d53bc blt 0x2d5460 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii+0x158>
 *   @0x2d53c0 cmp r3, #0
 *   @0x2d53c4 ldr r0, [r7, #0xd4]
 *   @0x2d53c8 lslne r1, r3, #1
 *   @0x2d53cc strne r1, [sp, #0x8]
 *   @0x2d53d0 rsbne r3, r1, r3, lsl #5
 *   @0x2d53d4 moveq r1, #15360
 *   @0x2d53d8 ldr r11, [r7, #0xa0]
 *   @0x2d53dc moveq r3, #256
 *   @0x2d53e0 lslne r1, r3, #2
 *   @0x2d53e4 streq r3, [sp, #0x8]
 *   @0x2d53e8 str r12, [sp]
 *   @0x2d53ec str r2, [sp, #0x4]
 *   @0x2d53f0 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2d53f4 ldr r2, [sp, #0x4]
 *   @0x2d53f8 mov r1, r11
 *   @0x2d53fc rsb r2, r2, r2, lsl #4
 *   @0x2d5400 lsl r3, r2, #2
 *   @0x2d5404 str r3, [sp, #0x4]
 *   @0x2d5408 mov r2, r3
 *   @0x2d540c str r0, [sp, #0xc]
 *   @0x2d5410 bl 0xb65bc <memcpy@plt>
 *   @0x2d5414 ldr r3, [sp, #0x4]
 *   @0x2d5418 mov r1, r11
 *   @0x2d541c ldr r0, [r7, #0xd4]
 *   @0x2d5420 mov r2, r3
 *   @0x2d5424 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d5428 ldr r12, [sp]
 *   @0x2d542c ldr r3, [sp, #0xc]
 *   @0x2d5430 vldr s11, [r6]
 *   @0x2d5434 ldr r1, [sp, #0x8]
 *   @0x2d5438 vldr s13, [r4]
 *   @0x2d543c ldr r2, [r12]
 *   @0x2d5440 vldr s10, [r6, #4]
 *   @0x2d5444 str r3, [r7, #0xa0]
 *   @0x2d5448 vldr s12, [r4, #4]
 *   @0x2d544c vldr s8, [r5]
 *   @0x2d5450 vldr s7, [r5, #4]
 *   @0x2d5454 ldr r3, [r2, #0x98]
 *   @0x2d5458 mov r7, r2
 *   @0x2d545c str r1, [r2, #0x9c]
 *   @0x2d5460 vadd.f32 s13, s11, s13
 *   @0x2d5464 vldr s15, [pc, #272]
 *   @0x2d5468 rsb r1, r3, r3, lsl #4
 *   @0x2d546c ldr r0, [r7, #0xa0]
 *   @0x2d5470 ldr r2, [r7, #0x30]
 *   @0x2d5474 add r11, r3, #1
 *   @0x2d5478 lsl r1, r1, #2
 *   @0x2d547c ldr r3, [r12, #0x4]
 *   @0x2d5480 vldr s14, [r3, #36]
 *   @0x2d5484 add r3, r0, r1
 *   @0x2d5488 str r8, [r0, r1]
 *   @0x2d548c stmib r3, {r9, r10}
 *   @0x2d5490 ldr r1, [r2, r8, lsl #2]
 *   @0x2d5494 ldr r12, [r2, r9, lsl #2]
 *   @0x2d5498 ldr r0, [r2, r10, lsl #2]
 *   @0x2d549c vstr s14, [r3, #16]
 *   @0x2d54a0 vadd.f32 s12, s10, s12
 *   @0x2d54a4 orr r2, r12, r0
 *   @0x2d54a8 orr r2, r2, r1
 *   @0x2d54ac str r2, [r3, #0xc]
 *   @0x2d54b0 vadd.f32 s13, s13, s8
 *   @0x2d54b4 vadd.f32 s12, s12, s7
 *   @0x2d54b8 vmul.f32 s13, s13, s15
 *   @0x2d54bc vmul.f32 s12, s12, s15
 *   @0x2d54c0 vsub.f32 s11, s11, s13
 *   @0x2d54c4 vsub.f32 s10, s10, s12
 *   @0x2d54c8 vstr s11, [r3, #20]
 *   @0x2d54cc vstr s10, [r3, #24]
 *   @0x2d54d0 vldr s14, [r4, #4]
 *   @0x2d54d4 vldr s15, [r4]
 *   @0x2d54d8 vsub.f32 s14, s14, s12
 *   @0x2d54dc vsub.f32 s15, s15, s13
 *   @0x2d54e0 vstr s14, [r3, #32]
 *   @0x2d54e4 vstr s15, [r3, #28]
 *   @0x2d54e8 vldr s14, [r5, #4]
 *   @0x2d54ec vldr s15, [r5]
 *   @0x2d54f0 vsub.f32 s12, s14, s12
 *   @0x2d54f4 vsub.f32 s13, s15, s13
 *   @0x2d54f8 vstr s12, [r3, #40]
 *   @0x2d54fc vstr s13, [r3, #36]
 *   @0x2d5500 vldr s8, [r4, #4]
 *   @0x2d5504 vldr s11, [r5]
 *   @0x2d5508 vldr s10, [r6, #4]
 *   @0x2d550c vldr s9, [r4]
 *   @0x2d5510 vmul.f32 s13, s8, s11
 *   @0x2d5514 vldr s15, [r5, #4]
 *   @0x2d5518 vldr s7, [r6]
 *   @0x2d551c vmul.f32 s12, s10, s9
 *   @0x2d5520 vmul.f32 s14, s7, s15
 *   @0x2d5524 vnmls.f32 s13, s9, s15
 *   @0x2d5528 vnmls.f32 s12, s7, s8
 *   @0x2d552c vmul.f32 s15, s17, s21
 *   @0x2d5530 vmul.f32 s17, s17, s19
 *   @0x2d5534 vmul.f32 s19, s19, s21
 *   @0x2d5538 vnmls.f32 s14, s10, s11
 *   @0x2d553c vmla.f32 s15, s16, s20
 *   @0x2d5540 vmla.f32 s17, s16, s18
 *   @0x2d5544 vmla.f32 s19, s18, s20
 *   @0x2d5548 vadd.f32 s13, s12, s13
 *   @0x2d554c vadd.f32 s14, s13, s14
 *   @0x2d5550 vneg.f32 s15, s15
 *   @0x2d5554 vstr s14, [r3, #56]
 *   @0x2d5558 vneg.f32 s17, s17
 *   @0x2d555c vstr s15, [r3, #44]
 *   @0x2d5560 vneg.f32 s19, s19
 *   @0x2d5564 vstr s17, [r3, #48]
 *   @0x2d5568 vstr s19, [r3, #52]
 *   @0x2d556c str r11, [r7, #0x98]
 *   @0x2d5570 add sp, sp, #20
 *   @0x2d5574 vpop {d8, d9, d10}
 *   @0x2d5578 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d557c .word 0x3eaaaaab
 *
 * ══ §46/46 VM::PokeDSList(int, int, RValue&)  0xe4ba8  size 452  113 条（0xe4ba8..0xe4d6c）
 * @func 0xe4ba8 0xe4d6c  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::PokeDSList(int, int, RValue&)+0xe4×2 / FREE_RValue__Pre(RValue*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×12 / 0xc×6 / 0x8×4 / 0x1a4×1 / 0x194×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe4ba8 cmp r0, #0
 *   @0xe4bac push {r4, r5, lr}
 *   @0xe4bb0 sub sp, sp, #12
 *   @0xe4bb4 blt 0xe4c8c <_ZN2VM10PokeDSListEiiR6RValue+0xe4>
 *   @0xe4bb8 ldr r3, [pc, #0x1a4]
 *   @0xe4bbc ldr r3, [pc, r3]
 *   @0xe4bc0 ldr r3, [r3]
 *   @0xe4bc4 cmp r0, r3
 *   @0xe4bc8 bge 0xe4c8c <_ZN2VM10PokeDSListEiiR6RValue+0xe4>
 *   @0xe4bcc ldr r3, [pc, #0x194]
 *   @0xe4bd0 ldr r3, [pc, r3]
 *   @0xe4bd4 ldr r3, [r3, #0x4]
 *   @0xe4bd8 ldr r0, [r3, r0, lsl #2]
 *   @0xe4bdc cmp r0, #0
 *   @0xe4be0 beq 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8>
 *   @0xe4be4 cmp r1, #0
 *   @0xe4be8 blt 0xe4c8c <_ZN2VM10PokeDSListEiiR6RValue+0xe4>
 *   @0xe4bec ldr r3, [r0, #0x4]
 *   @0xe4bf0 cmp r1, r3
 *   @0xe4bf4 bge 0xe4c8c <_ZN2VM10PokeDSListEiiR6RValue+0xe4>
 *   @0xe4bf8 ldr r5, [r0, #0xc]
 *   @0xe4bfc add r4, r5, r1, lsl #4
 *   @0xe4c00 ldr r3, [r4, #0xc]
 *   @0xe4c04 sub r3, r3, #1
 *   @0xe4c08 bic r3, r3, #-16777216
 *   @0xe4c0c bic r3, r3, #3
 *   @0xe4c10 cmp r3, #0
 *   @0xe4c14 beq 0xe4ca8 <_ZN2VM10PokeDSListEiiR6RValue+0x100>
 *   @0xe4c18 mov r3, #5
 *   @0xe4c1c str r3, [r4, #0xc]
 *   @0xe4c20 ldr r12, [r2, #0xc]
 *   @0xe4c24 mov r3, #0
 *   @0xe4c28 str r3, [r4, #0x8]
 *   @0xe4c2c str r3, [r5, r1, lsl #4]
 *   @0xe4c30 ldr r0, [r2, #0x8]
 *   @0xe4c34 str r12, [r4, #0xc]
 *   @0xe4c38 ldr r3, [r2, #0xc]
 *   @0xe4c3c str r0, [r4, #0x8]
 *   @0xe4c40 bic r3, r3, #-16777216
 *   @0xe4c44 cmp r3, #14
 *   @0xe4c48 addls pc, pc, r3, lsl #2
 *   @0xe4c4c b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4c50 b 0xe4cc4 <_ZN2VM10PokeDSListEiiR6RValue+0x11c>
 *   @0xe4c54 b 0xe4cdc <_ZN2VM10PokeDSListEiiR6RValue+0x134>
 *   @0xe4c58 b 0xe4cfc <_ZN2VM10PokeDSListEiiR6RValue+0x154>
 *   @0xe4c5c b 0xe4c98 <_ZN2VM10PokeDSListEiiR6RValue+0xf0>
 *   @0xe4c60 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4c64 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4c68 b 0xe4d34 <_ZN2VM10PokeDSListEiiR6RValue+0x18c>
 *   @0xe4c6c b 0xe4c98 <_ZN2VM10PokeDSListEiiR6RValue+0xf0>
 *   @0xe4c70 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4c74 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4c78 b 0xe4cc4 <_ZN2VM10PokeDSListEiiR6RValue+0x11c>
 *   @0xe4c7c b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4c80 b 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4c84 b 0xe4cc4 <_ZN2VM10PokeDSListEiiR6RValue+0x11c>
 *   @0xe4c88 b 0xe4c98 <_ZN2VM10PokeDSListEiiR6RValue+0xf0>
 *   @0xe4c8c mov r0, #0
 *   @0xe4c90 add sp, sp, #12
 *   @0xe4c94 pop {r4, r5, pc}
 *   @0xe4c98 ldr r3, [r2]
 *   @0xe4c9c mov r0, #1
 *   @0xe4ca0 str r3, [r5, r1, lsl #4]
 *   @0xe4ca4 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8>
 *   @0xe4ca8 mov r0, r4
 *   @0xe4cac str r1, [sp, #0x4]
 *   @0xe4cb0 str r2, [sp]
 *   @0xe4cb4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe4cb8 ldr r2, [sp]
 *   @0xe4cbc ldr r1, [sp, #0x4]
 *   @0xe4cc0 b 0xe4c18 <_ZN2VM10PokeDSListEiiR6RValue+0x70>
 *   @0xe4cc4 ldr r12, [r2]
 *   @0xe4cc8 mov r0, #1
 *   @0xe4ccc ldr r3, [r2, #0x4]
 *   @0xe4cd0 str r12, [r5, r1, lsl #4]
 *   @0xe4cd4 str r3, [r4, #0x4]
 *   @0xe4cd8 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8>
 *   @0xe4cdc ldr r3, [r2]
 *   @0xe4ce0 mov r0, #1
 *   @0xe4ce4 cmp r3, #0
 *   @0xe4ce8 ldrne r2, [r3, #0x4]
 *   @0xe4cec addne r2, r2, #1
 *   @0xe4cf0 strne r2, [r3, #0x4]
 *   @0xe4cf4 str r3, [r5, r1, lsl #4]
 *   @0xe4cf8 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8>
 *   @0xe4cfc ldr r3, [r2]
 *   @0xe4d00 cmp r3, #0
 *   @0xe4d04 str r3, [r5, r1, lsl #4]
 *   @0xe4d08 beq 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4d0c ldr r1, [r3, #0x8]
 *   @0xe4d10 ldr r2, [r3]
 *   @0xe4d14 cmp r1, #0
 *   @0xe4d18 streq r4, [r3, #0x8]
 *   @0xe4d1c add r2, r2, #1
 *   @0xe4d20 str r2, [r3]
 *   @0xe4d24 moveq r0, #1
 *   @0xe4d28 beq 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8>
 *   @0xe4d2c mov r0, #1
 *   @0xe4d30 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8>
 *   @0xe4d34 ldr r3, [r2]
 *   @0xe4d38 str r3, [r5, r1, lsl #4]
 *   @0xe4d3c ldr r3, [r2]
 *   @0xe4d40 cmp r3, #0
 *   @0xe4d44 beq 0xe4d2c <_ZN2VM10PokeDSListEiiR6RValue+0x184>
 *   @0xe4d48 str r2, [sp]
 *   @0xe4d4c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xe4d50 ldr r2, [sp]
 *   @0xe4d54 ldr r1, [r2]
 *   @0xe4d58 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xe4d5c mov r0, #1
 *   @0xe4d60 b 0xe4c90 <_ZN2VM10PokeDSListEiiR6RValue+0xe8>
 *   @0xe4d64 eorseq r9, r0, r0, asr #1
 *   @0xe4d68 ldrhteq r9, [r0], -r0
 */
