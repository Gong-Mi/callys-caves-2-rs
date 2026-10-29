/* cally 逆向卡：All_42 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 60 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/60 b2MouseJoint::InitVelocityConstraints(b2SolverData const&)  0x2cebb4  size 520  130 条（0x2cebb4..0x2cedbc）
 * @func 0x2cebb4 0x2cedbc  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x8×2 / 0x34×1 / 0x18×1 / 0x1c×1 / 0x74×1 / 0x14×1 / 0x60×1 / 0x64×1
 * VFP 指令 99 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cebb4 push {r4, r5, r6, r7, r8, lr}
 *   @0x2cebb8 vpush {d8, d9, d10}
 *   @0x2cebbc mov r7, r1
 *   @0x2cebc0 ldr r6, [r0, #0x34]
 *   @0x2cebc4 mov r4, r0
 *   @0x2cebc8 ldr lr, [r1, #0x18]
 *   @0x2cebcc vldr s16, [r6, #144]
 *   @0x2cebd0 add r1, r6, #44
 *   @0x2cebd4 ldr r12, [r7, #0x1c]
 *   @0x2cebd8 ldr r3, [r6, #0x8]
 *   @0x2cebdc vldr s17, [r6, #136]
 *   @0x2cebe0 add r2, r0, #128
 *   @0x2cebe4 ldm r1, {r0, r1}
 *   @0x2cebe8 add r5, r3, r3, lsl #1
 *   @0x2cebec str r3, [r4, #0x74]
 *   @0x2cebf0 stm r2, {r0, r1}
 *   @0x2cebf4 vstr s17, [r4, #136]
 *   @0x2cebf8 lsl r5, r5, #2
 *   @0x2cebfc vstr s16, [r4, #140]
 *   @0x2cec00 add r3, lr, r5
 *   @0x2cec04 add r5, r12, r5
 *   @0x2cec08 vldr s20, [r3]
 *   @0x2cec0c vldr s19, [r3, #4]
 *   @0x2cec10 ldr r8, [r3, #0x8]
 *   @0x2cec14 mov r0, r8
 *   @0x2cec18 bl 0xb6580 <sinf@plt>
 *   @0x2cec1c vmov s18, r0
 *   @0x2cec20 mov r0, r8
 *   @0x2cec24 bl 0xb658c <cosf@plt>
 *   @0x2cec28 vldr s14, [r4, #84]
 *   @0x2cec2c vldr s15, [pc, #384]
 *   @0x2cec30 vmul.f32 s15, s14, s15
 *   @0x2cec34 vldr s14, [r6, #132]
 *   @0x2cec38 vldr s13, [r7]
 *   @0x2cec3c vldr s10, [r4, #88]
 *   @0x2cec40 vldr s5, [r5, #8]
 *   @0x2cec44 vldr s6, [r5]
 *   @0x2cec48 vldr s7, [r5, #4]
 *   @0x2cec4c vldr s3, [r4, #76]
 *   @0x2cec50 vldr s4, [r4, #80]
 *   @0x2cec54 ldrb r3, [r7, #0x14]
 *   @0x2cec58 vmul.f32 s8, s15, s15
 *   @0x2cec5c vmul.f32 s8, s14, s8
 *   @0x2cec60 vmov s11, r0
 *   @0x2cec64 vadd.f32 s14, s14, s14
 *   @0x2cec68 vmul.f32 s8, s13, s8
 *   @0x2cec6c vmul.f32 s14, s14, s10
 *   @0x2cec70 vldr s10, [r4, #68]
 *   @0x2cec74 vmov.f32 s12, s8
 *   @0x2cec78 vmla.f32 s12, s14, s15
 *   @0x2cec7c vldr s14, [r4, #72]
 *   @0x2cec80 vmul.f32 s12, s12, s13
 *   @0x2cec84 vldr s13, [r4, #128]
 *   @0x2cec88 vcmp.f32 s12, #0
 *   @0x2cec8c vmrs APSR_nzcv, fpscr
 *   @0x2cec90 vmovne.f32 s15, #1.000000e+00
 *   @0x2cec94 vstreq s12, [r4, #108]
 *   @0x2cec98 vdivne.f32 s15, s15, s12
 *   @0x2cec9c vmovne.f32 s12, s15
 *   @0x2ceca0 vstrne s15, [r4, #108]
 *   @0x2ceca4 vldr s15, [r4, #132]
 *   @0x2ceca8 vsub.f32 s14, s14, s15
 *   @0x2cecac vmul.f32 s15, s14, s18
 *   @0x2cecb0 vmul.f32 s14, s14, s11
 *   @0x2cecb4 vsub.f32 s13, s10, s13
 *   @0x2cecb8 vmla.f32 s14, s13, s18
 *   @0x2cecbc vmul.f32 s10, s16, s14
 *   @0x2cecc0 vstr s14, [r4, #124]
 *   @0x2cecc4 vnmls.f32 s15, s13, s11
 *   @0x2cecc8 vmov.f32 s9, s17
 *   @0x2ceccc vstr s15, [r4, #120]
 *   @0x2cecd0 vmla.f32 s9, s10, s14
 *   @0x2cecd4 vmul.f32 s13, s16, s15
 *   @0x2cecd8 vnmul.f32 s11, s16, s15
 *   @0x2cecdc vmov.f32 s10, s9
 *   @0x2cece0 vmov.f32 s9, s17
 *   @0x2cece4 vmla.f32 s9, s13, s15
 *   @0x2cece8 vmul.f32 s11, s11, s14
 *   @0x2cecec vmul.f32 s13, s11, s11
 *   @0x2cecf0 vadd.f32 s10, s10, s12
 *   @0x2cecf4 vadd.f32 s9, s9, s12
 *   @0x2cecf8 vnmls.f32 s13, s10, s9
 *   @0x2cecfc vcmp.f32 s13, #0
 *   @0x2ced00 vmul.f32 s12, s8, s12
 *   @0x2ced04 vmrs APSR_nzcv, fpscr
 *   @0x2ced08 vmovne.f32 s8, #1.000000e+00
 *   @0x2ced0c vstr s12, [r4, #92]
 *   @0x2ced10 vdivne.f32 s13, s8, s13
 *   @0x2ced14 cmp r3, #0
 *   @0x2ced18 vldr s8, [pc, #152]
 *   @0x2ced1c vadd.f32 s20, s20, s15
 *   @0x2ced20 vadd.f32 s19, s14, s19
 *   @0x2ced24 vsub.f32 s20, s20, s3
 *   @0x2ced28 vsub.f32 s19, s19, s4
 *   @0x2ced2c vnmul.f32 s11, s13, s11
 *   @0x2ced30 vmul.f32 s9, s9, s13
 *   @0x2ced34 vstr s11, [r4, #148]
 *   @0x2ced38 vstr s11, [r4, #152]
 *   @0x2ced3c vmul.f32 s13, s10, s13
 *   @0x2ced40 vstr s9, [r4, #144]
 *   @0x2ced44 vmul.f32 s20, s12, s20
 *   @0x2ced48 vstr s13, [r4, #156]
 *   @0x2ced4c vmul.f32 s12, s12, s19
 *   @0x2ced50 vstr s20, [r4, #160]
 *   @0x2ced54 vstr s12, [r4, #164]
 *   @0x2ced58 vmul.f32 s13, s5, s8
 *   @0x2ced5c bne 0x2ced80 <_ZN12b2MouseJoint23InitVelocityConstraintsERK12b2SolverData+0x1cc>
 *   @0x2ced60 mov r3, #0
 *   @0x2ced64 str r3, [r4, #0x60]
 *   @0x2ced68 str r3, [r4, #0x64]
 *   @0x2ced6c vpop {d8, d9, d10}
 *   @0x2ced70 vstr s6, [r5]
 *   @0x2ced74 vstr s7, [r5, #4]
 *   @0x2ced78 vstr s13, [r5, #8]
 *   @0x2ced7c pop {r4, r5, r6, r7, r8, pc}
 *   @0x2ced80 vldr s12, [r7, #8]
 *   @0x2ced84 vldr s11, [r4, #96]
 *   @0x2ced88 vmul.f32 s11, s12, s11
 *   @0x2ced8c vldr s10, [r4, #100]
 *   @0x2ced90 vmul.f32 s14, s14, s11
 *   @0x2ced94 vstr s11, [r4, #96]
 *   @0x2ced98 vmul.f32 s12, s12, s10
 *   @0x2ced9c vnmls.f32 s14, s15, s12
 *   @0x2ceda0 vstr s12, [r4, #100]
 *   @0x2ceda4 vmla.f32 s6, s17, s11
 *   @0x2ceda8 vmla.f32 s13, s16, s14
 *   @0x2cedac vmla.f32 s7, s17, s12
 *   @0x2cedb0 b 0x2ced6c <_ZN12b2MouseJoint23InitVelocityConstraintsERK12b2SolverData+0x1b8>
 *   @0x2cedb4 ldrdmi r0, r1, [r9], #251
 *   @0x2cedb8 svclo #0x7ae148
 *
 * ══ §2/60 StringReplace(char const*&, char const*, char const*, char const*, bool)  0x1116a4  size 516  129 条（0x1116a4..0x1118a8）
 * @func 0x1116a4 0x1118a8  size 516  129 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×13 / YYStrDup(char const*)×5 / String_Add(char const*&, char const*)×4 / String_Copy(char const*&, char const*, int, int)×3 / utf8_strlen×2 / StringPos(char const*, char const*)
 * 字段偏移 top8: 0x14×18 / 0xc×3 / 0x4×2 / 0x8×2 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1116a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1116a8 sub sp, sp, #28
 *   @0x1116ac cmp r1, #0
 *   @0x1116b0 mov r9, r0
 *   @0x1116b4 str r3, [sp, #0x4]
 *   @0x1116b8 mov r11, r2
 *   @0x1116bc ldrb r3, [sp, #0x40]
 *   @0x1116c0 str r1, [sp, #0xc]
 *   @0x1116c4 str r3, [sp, #0x8]
 *   @0x1116c8 beq 0x111874 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1d0>
 *   @0x1116cc mov r0, r1
 *   @0x1116d0 mov r7, #0
 *   @0x1116d4 str r7, [sp, #0x14]
 *   @0x1116d8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1116dc mov r4, r0
 *   @0x1116e0 mov r0, r11
 *   @0x1116e4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1116e8 mov r10, r0
 *   @0x1116ec ldr r0, [sp, #0xc]
 *   @0x1116f0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1116f4 cmp r4, r7
 *   @0x1116f8 mov r6, r0
 *   @0x1116fc beq 0x111888 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1e4>
 *   @0x111700 ldrb r3, [r4]
 *   @0x111704 cmp r3, #0
 *   @0x111708 beq 0x111888 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1e4>
 *   @0x11170c add r8, sp, #20
 *   @0x111710 b 0x111798 <_Z13StringReplaceRPKcS0_S0_S0_b+0xf4>
 *   @0x111714 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111718 ldr r0, [sp, #0x14]
 *   @0x11171c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x111720 mov r6, r0
 *   @0x111724 ldr r0, [sp, #0x14]
 *   @0x111728 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x11172c ldr r3, [sp, #0x8]
 *   @0x111730 mov r0, r10
 *   @0x111734 str r7, [sp, #0x14]
 *   @0x111738 cmp r3, #0
 *   @0x11173c beq 0x11187c <_Z13StringReplaceRPKcS0_S0_S0_b+0x1d8>
 *   @0x111740 bl 0x110648 <utf8_strlen>
 *   @0x111744 mvn r3, #-2147483648
 *   @0x111748 mov r1, r4
 *   @0x11174c add r2, r5, r0
 *   @0x111750 mov r0, r8
 *   @0x111754 bl 0x1114c4 <_Z11String_CopyRPKcS0_ii>
 *   @0x111758 ldr r5, [sp, #0x14]
 *   @0x11175c mov r0, r4
 *   @0x111760 cmp r5, #0
 *   @0x111764 beq 0x11182c <_Z13StringReplaceRPKcS0_S0_S0_b+0x188>
 *   @0x111768 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x11176c ldr r0, [sp, #0x14]
 *   @0x111770 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x111774 mov r4, r0
 *   @0x111778 ldr r0, [sp, #0x14]
 *   @0x11177c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111780 cmp r4, #0
 *   @0x111784 str r7, [sp, #0x14]
 *   @0x111788 beq 0x1118a0 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1fc>
 *   @0x11178c ldrb r0, [r4]
 *   @0x111790 cmp r0, #0
 *   @0x111794 beq 0x111844 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1a0>
 *   @0x111798 mov r0, r10
 *   @0x11179c mov r1, r4
 *   @0x1117a0 bl 0x1111e0 <_Z9StringPosPKcS0_>
 *   @0x1117a4 cmn r0, #1
 *   @0x1117a8 mov r5, r0
 *   @0x1117ac beq 0x11187c <_Z13StringReplaceRPKcS0_S0_S0_b+0x1d8>
 *   @0x1117b0 ldr r0, [sp, #0x14]
 *   @0x1117b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1117b8 mov r2, #0
 *   @0x1117bc mov r3, r5
 *   @0x1117c0 mov r0, r8
 *   @0x1117c4 mov r1, r6
 *   @0x1117c8 str r7, [sp, #0x14]
 *   @0x1117cc bl 0x1114c4 <_Z11String_CopyRPKcS0_ii>
 *   @0x1117d0 mov r0, r9
 *   @0x1117d4 ldr r1, [sp, #0x14]
 *   @0x1117d8 bl 0x1115e4 <_Z10String_AddRPKcS0_>
 *   @0x1117dc ldr r1, [sp, #0x4]
 *   @0x1117e0 mov r0, r9
 *   @0x1117e4 bl 0x1115e4 <_Z10String_AddRPKcS0_>
 *   @0x1117e8 ldr r0, [sp, #0x14]
 *   @0x1117ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1117f0 mov r0, r11
 *   @0x1117f4 str r7, [sp, #0x14]
 *   @0x1117f8 bl 0x110648 <utf8_strlen>
 *   @0x1117fc mvn r3, #-2147483648
 *   @0x111800 mov r1, r6
 *   @0x111804 add r2, r5, r0
 *   @0x111808 mov r0, r8
 *   @0x11180c bl 0x1114c4 <_Z11String_CopyRPKcS0_ii>
 *   @0x111810 ldr r3, [sp, #0x14]
 *   @0x111814 mov r0, r6
 *   @0x111818 cmp r3, #0
 *   @0x11181c bne 0x111714 <_Z13StringReplaceRPKcS0_S0_S0_b+0x70>
 *   @0x111820 mov r6, r3
 *   @0x111824 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111828 b 0x111724 <_Z13StringReplaceRPKcS0_S0_S0_b+0x80>
 *   @0x11182c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111830 ldr r0, [sp, #0x14]
 *   @0x111834 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111838 mov r4, r5
 *   @0x11183c mov r0, r5
 *   @0x111840 str r5, [sp, #0x14]
 *   @0x111844 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111848 mov r0, r4
 *   @0x11184c mov r3, #0
 *   @0x111850 str r3, [sp, #0x14]
 *   @0x111854 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111858 mov r0, r10
 *   @0x11185c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111860 mov r0, r6
 *   @0x111864 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x111868 ldr r3, [r9]
 *   @0x11186c cmp r3, #0
 *   @0x111870 beq 0x111890 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1ec>
 *   @0x111874 add sp, sp, #28
 *   @0x111878 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11187c mov r0, r9
 *   @0x111880 mov r1, r6
 *   @0x111884 bl 0x1115e4 <_Z10String_AddRPKcS0_>
 *   @0x111888 ldr r0, [sp, #0x14]
 *   @0x11188c b 0x111844 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1a0>
 *   @0x111890 mov r0, r9
 *   @0x111894 ldr r1, [sp, #0xc]
 *   @0x111898 bl 0x1115e4 <_Z10String_AddRPKcS0_>
 *   @0x11189c b 0x111874 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1d0>
 *   @0x1118a0 mov r0, r4
 *   @0x1118a4 b 0x111844 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1a0>
 *
 * ══ §3/60 GR_Draw_Rectangle_Ext(float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, bool)  0x16ac60  size 516  129 条（0x16ac60..0x16ae64）
 * @func 0x16ac60 0x16ae64  size 516  129 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16ac9c→0x3f23d8, 0x16aca4→0x3f23d4, 0x16acac→0x4859c0, 0x16ad5c→0x4859ac, 0x16ad74→0x3f23cc, 0x16ae00→0x4859c0, 0x16ae08→0x3f23d8, 0x16ae10→0x3f23d4
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)×2 / 0xb6598×2
 * 字段偏移 top8: 0x3c×3 / 0x40×2 / 0x38×2 / 0x50×2 / 0x1d0×1 / 0x30×1 / 0x34×1 / 0x1ac×1
 * VFP 指令 57 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ac60 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x16ac64 vpush {d8, d9}
 *   @0x16ac68 vmov s14, r2
 *   @0x16ac6c ldrb r12, [sp, #0x40]
 *   @0x16ac70 vmov s18, r0
 *   @0x16ac74 ldr r5, [pc, #0x1d0]
 *   @0x16ac78 vmov s19, r1
 *   @0x16ac7c cmp r12, #0
 *   @0x16ac80 vmov s15, r3
 *   @0x16ac84 add r5, pc, r5
 *   @0x16ac88 ldr r9, [sp, #0x30]
 *   @0x16ac8c ldr r8, [sp, #0x34]
 *   @0x16ac90 ldr r7, [sp, #0x38]
 *   @0x16ac94 ldr r6, [sp, #0x3c]
 *   @0x16ac98 beq 0x16ae00 <_Z21GR_Draw_Rectangle_Extffffjjjjb+0x1a0>
 *   @0x16ac9c ldr r12, [pc, #0x1ac]
 *   @0x16aca0 vldr s13, [pc, #416]
 *   @0x16aca4 ldr r1, [pc, #0x1a8]
 *   @0x16aca8 mov r0, #3
 *   @0x16acac ldr r3, [pc, #0x1a4]
 *   @0x16acb0 mov r2, #24
 *   @0x16acb4 ldr r12, [r5, r12]
 *   @0x16acb8 vldr s17, [r12]
 *   @0x16acbc ldr r1, [r5, r1]
 *   @0x16acc0 vmul.f32 s17, s17, s13
 *   @0x16acc4 vldr s16, [r1]
 *   @0x16acc8 ldr r1, [r5, r3]
 *   @0x16accc mov r3, #5
 *   @0x16acd0 ldr r1, [r1]
 *   @0x16acd4 ldr r1, [r1]
 *   @0x16acd8 vmul.f32 s16, s16, s13
 *   @0x16acdc vadd.f32 s18, s18, s17
 *   @0x16ace0 vadd.f32 s19, s19, s16
 *   @0x16ace4 vadd.f32 s17, s17, s14
 *   @0x16ace8 vadd.f32 s16, s16, s15
 *   @0x16acec bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16acf0 mov r4, r0
 *   @0x16acf4 vcmpe.f32 s18, s17
 *   @0x16acf8 bic r8, r8, #-16777216
 *   @0x16acfc bic r7, r7, #-16777216
 *   @0x16ad00 bic r6, r6, #-16777216
 *   @0x16ad04 vmrs APSR_nzcv, fpscr
 *   @0x16ad08 vmovgt.f32 s15, s18
 *   @0x16ad0c vmovgt.f32 s18, s17
 *   @0x16ad10 vmovgt.f32 s17, s15
 *   @0x16ad14 vcmpe.f32 s19, s16
 *   @0x16ad18 vcvt.f64.f32 d6, s17
 *   @0x16ad1c vmrs APSR_nzcv, fpscr
 *   @0x16ad20 vmovgt.f32 s15, s19
 *   @0x16ad24 vmov r0, r1, d6
 *   @0x16ad28 vmovgt.f32 s19, s16
 *   @0x16ad2c vmovgt.f32 s16, s15
 *   @0x16ad30 bl 0xb6598 <floor@plt>
 *   @0x16ad34 vmov d6, r0, r1
 *   @0x16ad38 vcvt.s32.f64 s15, d6
 *   @0x16ad3c vcvt.f32.s32 s15, s15
 *   @0x16ad40 vcmp.f32 s15, s17
 *   @0x16ad44 vmrs APSR_nzcv, fpscr
 *   @0x16ad48 vldreq s15, [pc, #248]
 *   @0x16ad4c vaddeq.f32 s17, s17, s15
 *   @0x16ad50 vcvt.f64.f32 d7, s16
 *   @0x16ad54 vmov r0, r1, d7
 *   @0x16ad58 bl 0xb6598 <floor@plt>
 *   @0x16ad5c ldr r3, [pc, #0xf8]
 *   @0x16ad60 vstr s18, [r4]
 *   @0x16ad64 vstr s18, [r4, #96]
 *   @0x16ad68 vstr s19, [r4, #4]
 *   @0x16ad6c vstr s19, [r4, #100]
 *   @0x16ad70 ldr r3, [r5, r3]
 *   @0x16ad74 ldr r2, [pc, #0xe4]
 *   @0x16ad78 ldr r3, [r3]
 *   @0x16ad7c str r3, [r4, #0x8]
 *   @0x16ad80 str r3, [r4, #0x68]
 *   @0x16ad84 vmov d6, r0, r1
 *   @0x16ad88 ldr r1, [r5, r2]
 *   @0x16ad8c vstr s17, [r4, #24]
 *   @0x16ad90 vstr s19, [r4, #28]
 *   @0x16ad94 vcvt.s32.f64 s15, d6
 *   @0x16ad98 vstr s17, [r4, #48]
 *   @0x16ad9c vstr s18, [r4, #72]
 *   @0x16ada0 ldr r1, [r1]
 *   @0x16ada4 bic r2, r9, #-16777216
 *   @0x16ada8 str r3, [r4, #0x20]
 *   @0x16adac str r3, [r4, #0x38]
 *   @0x16adb0 str r3, [r4, #0x50]
 *   @0x16adb4 lsl r3, r1, #24
 *   @0x16adb8 orr r2, r2, r3
 *   @0x16adbc orr r8, r8, r3
 *   @0x16adc0 orr r7, r7, r3
 *   @0x16adc4 str r2, [r4, #0xc]
 *   @0x16adc8 vcvt.f32.s32 s15, s15
 *   @0x16adcc orr r3, r6, r3
 *   @0x16add0 str r2, [r4, #0x6c]
 *   @0x16add4 str r8, [r4, #0x24]
 *   @0x16add8 str r7, [r4, #0x3c]
 *   @0x16addc str r3, [r4, #0x54]
 *   @0x16ade0 vcmp.f32 s15, s16
 *   @0x16ade4 vmrs APSR_nzcv, fpscr
 *   @0x16ade8 vldreq s15, [pc, #88]
 *   @0x16adec vaddeq.f32 s16, s16, s15
 *   @0x16adf0 vstr s16, [r4, #52]
 *   @0x16adf4 vstr s16, [r4, #76]
 *   @0x16adf8 vpop {d8, d9}
 *   @0x16adfc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x16ae00 ldr r1, [pc, #0x50]
 *   @0x16ae04 mov r0, #6
 *   @0x16ae08 ldr lr, [pc, #0x40]
 *   @0x16ae0c mov r2, #24
 *   @0x16ae10 ldr r12, [pc, #0x3c]
 *   @0x16ae14 mov r3, #5
 *   @0x16ae18 ldr r1, [r5, r1]
 *   @0x16ae1c ldr lr, [r5, lr]
 *   @0x16ae20 vldr s17, [lr]
 *   @0x16ae24 ldr r12, [r5, r12]
 *   @0x16ae28 vadd.f32 s17, s14, s17
 *   @0x16ae2c ldr r1, [r1]
 *   @0x16ae30 vldr s16, [r12]
 *   @0x16ae34 ldr r1, [r1]
 *   @0x16ae38 vadd.f32 s16, s15, s16
 *   @0x16ae3c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16ae40 mov r4, r0
 *   @0x16ae44 b 0x16acf4 <_Z21GR_Draw_Rectangle_Extffffjjjjb+0x94>
 *   @0x16ae48 stclo p7, c13, [r3], #-40
 *   @0x16ae4c eoreq r6, r8, r12, asr #31
 *   @0x16ae50 .word 0xffffe524
 *   @0x16ae54 .word 0xffffe520
 *   @0x16ae58 .word 0xffffe4e0
 *   @0x16ae5c .word 0xffffbcd0
 *   @0x16ae60 .word 0xffffc0b0
 *
 * ══ §4/60 CDS_Grid::Sort(int, int)  0x204f6c  size 516  129 条（0x204f6c..0x205170）
 * @func 0x204f6c 0x205170  size 516  129 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::Sort(int, int)+0x1dc×2 / CDS_Grid::Sort(int, int)+0xb0 / 0xb66dc / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CDS_Grid::Sort(int, int)+0x150 / CDS_Grid::Sort(int, int)+0x1d0 / MemoryManager::Free(void const*) / 0xb65d4
 * 字段偏移 top8: 0x4×11 / 0x8×9 / 0xc×4 / 0x-28×2 / 0x19c×2 / 0x1e0×1 / 0x1d8×1 / 0x194×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x204f6c ldr r12, [pc, #0x1e0]
 *   @0x204f70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x204f74 add r11, sp, #32
 *   @0x204f78 ldr r3, [pc, #0x1d8]
 *   @0x204f7c sub sp, sp, #12
 *   @0x204f80 add r12, pc, r12
 *   @0x204f84 mov r4, r0
 *   @0x204f88 ldr r5, [r12, r3]
 *   @0x204f8c ldr r0, [r0, #0x4]
 *   @0x204f90 ldr r3, [r5]
 *   @0x204f94 cmp r0, r1
 *   @0x204f98 str r3, [r11, #-0x28]
 *   @0x204f9c bgt 0x204fb8 <_ZN8CDS_Grid4SortEii+0x4c>
 *   @0x204fa0 ldr r2, [r11, #-0x28]
 *   @0x204fa4 ldr r3, [r5]
 *   @0x204fa8 cmp r2, r3
 *   @0x204fac bne 0x205150 <_ZN8CDS_Grid4SortEii+0x1e4>
 *   @0x204fb0 sub sp, r11, #32
 *   @0x204fb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204fb8 ldr r0, [pc, #0x19c]
 *   @0x204fbc ldr r6, [pc, #0x19c]
 *   @0x204fc0 ldr r3, [r4, #0x8]
 *   @0x204fc4 ldr r7, [r12, r0]
 *   @0x204fc8 ldr r0, [pc, #0x194]
 *   @0x204fcc cmp r3, #0
 *   @0x204fd0 lsl lr, r3, #2
 *   @0x204fd4 str r1, [r7]
 *   @0x204fd8 add lr, lr, #14
 *   @0x204fdc ldr r1, [r12, r6]
 *   @0x204fe0 bic lr, lr, #7
 *   @0x204fe4 sub sp, sp, lr
 *   @0x204fe8 str r2, [r1]
 *   @0x204fec mov r6, sp
 *   @0x204ff0 ldr r2, [r12, r0]
 *   @0x204ff4 str r4, [r2]
 *   @0x204ff8 ble 0x20501c <_ZN8CDS_Grid4SortEii+0xb0>
 *   @0x204ffc sub r2, sp, #4
 *   @0x205000 mov r3, #0
 *   @0x205004 ldr r1, [r4, #0x8]
 *   @0x205008 str r3, [r2, #0x4]!
 *   @0x20500c add r3, r3, #1
 *   @0x205010 cmp r1, r3
 *   @0x205014 bgt 0x205004 <_ZN8CDS_Grid4SortEii+0x98>
 *   @0x205018 mov r3, r1
 *   @0x20501c ldr lr, [pc, #0x144]
 *   @0x205020 mov r1, r3
 *   @0x205024 mov r0, r6
 *   @0x205028 mov r2, #4
 *   @0x20502c ldr r3, [r12, lr]
 *   @0x205030 bl 0xb66dc <qsort@plt>
 *   @0x205034 ldmib r4, {r0, r12}
 *   @0x205038 ldr r1, [pc, #0x12c]
 *   @0x20503c movw r2, #0x102c
 *   @0x205040 mov r3, #1
 *   @0x205044 mul r0, r12, r0
 *   @0x205048 add r1, pc, r1
 *   @0x20504c lsl r0, r0, #4
 *   @0x205050 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x205054 ldr r2, [r4, #0x8]
 *   @0x205058 cmp r2, #0
 *   @0x20505c movgt r7, #0
 *   @0x205060 ldrgt r3, [r4, #0x4]
 *   @0x205064 ble 0x205148 <_ZN8CDS_Grid4SortEii+0x1dc>
 *   @0x205068 cmp r3, #0
 *   @0x20506c ble 0x2050bc <_ZN8CDS_Grid4SortEii+0x150>
 *   @0x205070 mov r1, #0
 *   @0x205074 mla r3, r3, r7, r1
 *   @0x205078 ldr r2, [r4]
 *   @0x20507c add r1, r1, #1
 *   @0x205080 lsl r12, r3, #4
 *   @0x205084 add r2, r2, r12
 *   @0x205088 add r12, r0, r12
 *   @0x20508c ldr r9, [r2]
 *   @0x205090 ldr r8, [r2, #0x4]
 *   @0x205094 ldr lr, [r2, #0x8]
 *   @0x205098 ldr r2, [r2, #0xc]
 *   @0x20509c str r9, [r0, r3, lsl #4]
 *   @0x2050a0 str r8, [r12, #0x4]
 *   @0x2050a4 str lr, [r12, #0x8]
 *   @0x2050a8 str r2, [r12, #0xc]
 *   @0x2050ac ldr r3, [r4, #0x4]
 *   @0x2050b0 cmp r3, r1
 *   @0x2050b4 bgt 0x205074 <_ZN8CDS_Grid4SortEii+0x108>
 *   @0x2050b8 ldr r2, [r4, #0x8]
 *   @0x2050bc add r7, r7, #1
 *   @0x2050c0 cmp r2, r7
 *   @0x2050c4 bgt 0x205068 <_ZN8CDS_Grid4SortEii+0xfc>
 *   @0x2050c8 cmp r2, #0
 *   @0x2050cc ble 0x205148 <_ZN8CDS_Grid4SortEii+0x1dc>
 *   @0x2050d0 mov r8, #0
 *   @0x2050d4 ldr r1, [r6], #4
 *   @0x2050d8 cmp r1, r8
 *   @0x2050dc beq 0x20513c <_ZN8CDS_Grid4SortEii+0x1d0>
 *   @0x2050e0 cmp r3, #0
 *   @0x2050e4 ble 0x20513c <_ZN8CDS_Grid4SortEii+0x1d0>
 *   @0x2050e8 mov r2, #0
 *   @0x2050ec b 0x2050f4 <_ZN8CDS_Grid4SortEii+0x188>
 *   @0x2050f0 ldr r1, [r6, #-0x4]
 *   @0x2050f4 mla r1, r1, r3, r2
 *   @0x2050f8 ldr lr, [r4]
 *   @0x2050fc mla r3, r3, r8, r2
 *   @0x205100 add r2, r2, #1
 *   @0x205104 add r1, r0, r1, lsl #4
 *   @0x205108 ldr r10, [r1]
 *   @0x20510c add r12, lr, r3, lsl #4
 *   @0x205110 ldr r9, [r1, #0x4]
 *   @0x205114 ldr r7, [r1, #0x8]
 *   @0x205118 ldr r1, [r1, #0xc]
 *   @0x20511c str r10, [lr, r3, lsl #4]
 *   @0x205120 str r9, [r12, #0x4]
 *   @0x205124 str r7, [r12, #0x8]
 *   @0x205128 str r1, [r12, #0xc]
 *   @0x20512c ldr r3, [r4, #0x4]
 *   @0x205130 cmp r3, r2
 *   @0x205134 bgt 0x2050f0 <_ZN8CDS_Grid4SortEii+0x184>
 *   @0x205138 ldr r2, [r4, #0x8]
 *   @0x20513c add r8, r8, #1
 *   @0x205140 cmp r2, r8
 *   @0x205144 bgt 0x2050d4 <_ZN8CDS_Grid4SortEii+0x168>
 *   @0x205148 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20514c b 0x204fa0 <_ZN8CDS_Grid4SortEii+0x34>
 *   @0x205150 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x205154 ldrsbeq r12, [lr], -r0
 *   @0x205158 .word 0xffffbd00
 *   @0x20515c .word 0xfffff73c
 *   @0x205160 .word 0xfffff740
 *   @0x205164 .word 0xfffff738
 *   @0x205168 .word 0xfffff748
 *   @0x20516c andseq lr, r4, r4, lsr #15
 *
 * ══ §5/60 JS_Array_prototype_reduceRight(RValue&, CInstance*, CInstance*, int, RValue*)  0x251f64  size 516  129 条（0x251f64..0x252168）
 * @func 0x251f64 0x252168  size 516  129 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×5 / JSThrowTypeError(char const*)×2 / JS_Array_prototype_reduceRight(RValue&, CInstance*, CInstance*, int, RValue*)+0x184 / JS_IsCallable(RValue&) / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*)
 * 字段偏移 top8: 0xc×6 / 0x4×5 / 0x98×1 / 0x24×1 / 0x5c×1 / 0x6c×1 / 0x60×1 / 0x70×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x251f64 ldr r12, [r1, #0x4]
 *   @0x251f68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x251f6c cmp r12, #0
 *   @0x251f70 sub sp, sp, #116
 *   @0x251f74 mov r4, r3
 *   @0x251f78 mov r6, r1
 *   @0x251f7c mov r3, #5
 *   @0x251f80 str r0, [sp, #0xc]
 *   @0x251f84 mov r7, r2
 *   @0x251f88 str r3, [r0, #0xc]
 *   @0x251f8c ldr r10, [sp, #0x98]
 *   @0x251f90 beq 0x252134 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x251f94 add r0, r12, #16
 *   @0x251f98 ldr r11, [r0]
 *   @0x251f9c cmp r4, #0
 *   @0x251fa0 ldr r8, [r11, #0x24]
 *   @0x251fa4 ble 0x2520e8 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x251fa8 mov r0, r10
 *   @0x251fac bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x251fb0 cmp r0, #0
 *   @0x251fb4 beq 0x2520e8 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x251fb8 ldr r0, [r11, #0x4]
 *   @0x251fbc sub r5, r8, #1
 *   @0x251fc0 cmp r0, #0
 *   @0x251fc4 addne r0, r0, r5, lsl #4
 *   @0x251fc8 beq 0x252150 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x251fcc cmp r4, #1
 *   @0x251fd0 addne r3, r10, #16
 *   @0x251fd4 addeq r4, sp, #16
 *   @0x251fd8 ldmeq r0, {r0, r1, r2, r3}
 *   @0x251fdc addne r4, sp, #16
 *   @0x251fe0 ldmne r3, {r0, r1, r2, r3}
 *   @0x251fe4 subeq r5, r8, #2
 *   @0x251fe8 stm r4, {r0, r1, r2, r3}
 *   @0x251fec mov r3, #0
 *   @0x251ff0 ldr r0, [sp, #0xc]
 *   @0x251ff4 mov r1, r6
 *   @0x251ff8 str r10, [sp]
 *   @0x251ffc mov r2, r7
 *   @0x252000 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x252004 ldr r12, [sp, #0xc]
 *   @0x252008 ldr r0, [r12]
 *   @0x25200c ldr r3, [r0, #0x4]
 *   @0x252010 cmp r3, #0
 *   @0x252014 beq 0x252144 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x252018 cmp r5, #0
 *   @0x25201c lslge r7, r5, #4
 *   @0x252020 addge r6, sp, #48
 *   @0x252024 addge r8, sp, #32
 *   @0x252028 mvnge r9, #-16777216
 *   @0x25202c bge 0x2520cc <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x252030 b 0x25210c <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x252034 add r0, r0, r7
 *   @0x252038 ldr r3, [r0, #0xc]
 *   @0x25203c bic r3, r3, #-16777216
 *   @0x252040 cmp r3, r9
 *   @0x252044 beq 0x2520bc <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x252048 ldm r4, {r0, r1, r2, r3}
 *   @0x25204c ldr r12, [r11, #0x4]
 *   @0x252050 cmp r12, #0
 *   @0x252054 stm r6, {r0, r1, r2, r3}
 *   @0x252058 beq 0x2520fc <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x25205c add r0, r12, r7
 *   @0x252060 vmov s13, r5
 *   @0x252064 mov r12, #0
 *   @0x252068 ldm r0, {r0, r1, r2, r3}
 *   @0x25206c vcvt.f64.s32 d7, s13
 *   @0x252070 str r12, [sp, #0x5c]
 *   @0x252074 mov r12, #6
 *   @0x252078 str r12, [sp, #0x6c]
 *   @0x25207c add r12, sp, #64
 *   @0x252080 str r6, [sp]
 *   @0x252084 stm r12, {r0, r1, r2, r3}
 *   @0x252088 mov r0, #0
 *   @0x25208c mov r1, r8
 *   @0x252090 mov r2, r10
 *   @0x252094 mov r3, #3
 *   @0x252098 str r11, [sp, #0x60]
 *   @0x25209c vstr d7, [sp, #80]
 *   @0x2520a0 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x2520a4 cmp r0, #2
 *   @0x2520a8 beq 0x2520f4 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x2520ac cmp r0, #1
 *   @0x2520b0 beq 0x252120 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x2520b4 ldm r8, {r0, r1, r2, r3}
 *   @0x2520b8 stm r4, {r0, r1, r2, r3}
 *   @0x2520bc sub r5, r5, #1
 *   @0x2520c0 sub r7, r7, #16
 *   @0x2520c4 cmn r5, #1
 *   @0x2520c8 beq 0x25210c <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x2520cc ldr r0, [r11, #0x4]
 *   @0x2520d0 cmp r0, #0
 *   @0x2520d4 bne 0x252034 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x2520d8 mov r0, r11
 *   @0x2520dc mov r1, r5
 *   @0x2520e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2520e4 b 0x252038 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x2520e8 ldr r0, [pc, #0x70]
 *   @0x2520ec add r0, pc, r0
 *   @0x2520f0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2520f4 add sp, sp, #116
 *   @0x2520f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2520fc mov r0, r11
 *   @0x252100 mov r1, r5
 *   @0x252104 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x252108 b 0x252060 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x25210c ldm r4, {r0, r1, r2, r3}
 *   @0x252110 ldr r12, [sp, #0xc]
 *   @0x252114 stm r12, {r0, r1, r2, r3}
 *   @0x252118 add sp, sp, #116
 *   @0x25211c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x252120 ldr r0, [pc, #0x3c]
 *   @0x252124 add r0, pc, r0
 *   @0x252128 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25212c add sp, sp, #116
 *   @0x252130 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x252134 mov r0, r1
 *   @0x252138 mov r1, #1
 *   @0x25213c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x252140 b 0x251f98 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x252144 mov r1, #1
 *   @0x252148 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25214c b 0x252018 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x252150 mov r0, r11
 *   @0x252154 mov r1, r5
 *   @0x252158 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25215c b 0x251fcc <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x252160 andseq r4, r0, r8, lsr r4
 *   @0x252164 ldrheq r4, [r0], -r8
 *
 * ══ §6/60 _zip_dirent_read_buff(zip_dirent*, IBuffer*, unsigned char**, unsigned int*, int, zip_error*)  0x2a4108  size 516  129 条（0x2a4108..0x2a430c）
 * @func 0x2a4108 0x2a430c  size 516  129 条
 * 部分覆盖: 本节 129/237 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_read2(unsigned char**)×7 / _zip_read4(unsigned char**)×3 / _zip_error_set(zip_error*, int, int) / 0xb6c40 / 0x933670 / b2GearJoint::Dump()+0xb8 / anon_2a399c+0xba / anon_2a399c+0xfc
 * 字段偏移 top8: 0x68×3 / 0x2c×3 / 0x4×2 / 0x8×2 / 0x18×2 / 0x1a×2 / 0x6c×1 / 0x194×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4108 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a410c mov r9, r2
 *   @0x2a4110 mov r10, r1
 *   @0x2a4114 mov r4, r0
 *   @0x2a4118 ldr r2, [r2]
 *   @0x2a411c ldr r7, [sp, #0x6c]
 *   @0x2a4120 str r2, [sp, #0x4]
 *   @0x2a4124 ldr r1, [sp, #0x68]
 *   @0x2a4128 ite eq
 *   @0x2a412c .word 0xf04f0b2e
 *   @0x2a4130 .word 0xb1430b1e
 *   @0x2a4134 ldr r3, [r3]
 *   @0x2a4138 bhs 0x2a4146 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x3e>
 *   @0x2a413c movs r1, #0x13
 *   @0x2a4140 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a4144 b 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164>
 *   @0x2a4148 andle r0, r3, r0, lsl #30
 *   @0x2a414c ldr.w r3, [r9]
 *   @0x2a4150 str r3, [sp, #0x8]
 *   @0x2a4154 add r5, sp, #0xc
 *   @0x2a4158 movs r2, #0x1
 *   @0x2a415c mov r1, r5
 *   @0x2a4160 strls lr, [r2, #-0xd9e]
 *   @0x2a4164 ldr r2, [sp, #0x68]
 *   @0x2a4168 cbz r2, 0x2a4170 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x68>
 *   @0x2a416c add r1, pc
 *   @0x2a4170 ldr r1, [pc, #0x194]
 *   @0x2a4174 mov r0, r5
 *   @0x2a4178 blx 0xb6c40 <memcmp@plt>
 *   @0x2a417c mov r8, r0
 *   @0x2a4180 bne 0x2a413a <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x32>
 *   @0x2a4184 add r5, sp, #0x40
 *   @0x2a4188 blls 0x933670 <b2_toiTime+0x1da1cc>
 *   @0x2a418c cbnz r3, 0x2a4198 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x90>
 *   @0x2a4190 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a4194 strh r0, [r4]
 *   @0x2a4198 strh r0, [r4]
 *   @0x2a419c bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a41a0 strh r0, [r4, #0x2]
 *   @0x2a41a4 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a41a8 strh r0, [r4, #0x4]
 *   @0x2a41ac bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a41b0 strh r0, [r4, #0x6]
 *   @0x2a41b4 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a41b8 mov r3, r0
 *   @0x2a41bc str r3, [sp]
 *   @0x2a41c0 blls 0x2e3bc4 <_ZN11b2GearJoint4DumpEv+0xb8>
 *   @0x2a41c4 mov r1, r0
 *   @0x2a41c8 bl 0x2a3a56 <zip_close+0x86a>
 *   @0x2a41cc str r0, [r4, #0x8]
 *   @0x2a41d0 bl 0x2a3ed2 <_Z10_zip_read4PPh>
 *   @0x2a41d4 str r0, [r4, #0xc]
 *   @0x2a41d8 bl 0x2a3ed2 <_Z10_zip_read4PPh>
 *   @0x2a41dc str r0, [r4, #0x10]
 *   @0x2a41e0 bl 0x2a3ed2 <_Z10_zip_read4PPh>
 *   @0x2a41e4 str r0, [r4, #0x14]
 *   @0x2a41e8 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a41ec strh r0, [r4, #0x1c]
 *   @0x2a41f0 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a41f4 ldr r1, [sp, #0x68]
 *   @0x2a41f8 cbz r1, 0x2a4208 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x100>
 *   @0x2a41fc strh r3, [r4, #0x2c]
 *   @0x2a4200 strh r3, [r4, #0x30]
 *   @0x2a4204 str r3, [r4, #0x38]
 *   @0x2a4208 mov r0, r5
 *   @0x2a420c strhi pc, [r0, #0xe59]!
 *   @0x2a4210 mov r0, r5
 *   @0x2a4214 strbhi pc, [r0, #0xe55]!
 *   @0x2a4218 mov r0, r5
 *   @0x2a421c qsaxhi pc, r0, r1
 *   @0x2a4220 mov r0, r5
 *   @0x2a4224 msrvs SPSR, #1376
 *   @0x2a4228 mov r0, r5
 *   @0x2a422c movvs pc, #1312
 *   @0x2a4230 movs r3, #0x0
 *   @0x2a4234 str r3, [r4, #0x18]
 *   @0x2a4238 str r3, [r4, #0x28]
 *   @0x2a423c ldrh r2, [r4, #0x2c]
 *   @0x2a4240 add r3, r2
 *   @0x2a4244 cbz r6, 0x2a424e <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x146>
 *   @0x2a4248 cmp r3, r11
 *   @0x2a424c .word 0xf1b9af76
 *   @0x2a4250 eorle r0, r2, r0, lsl #30
 *   @0x2a4254 cbnz r1, 0x2a425c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x154>
 *   @0x2a4258 cbz r1, 0x2a4282 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x17a>
 *   @0x2a425c mov r0, r5
 *   @0x2a4260 mov r3, r7
 *   @0x2a4264 lslvs pc, r9, r12
 *   @0x2a4268 cmp r0, #0x0
 *   @0x2a426c mov.w r8, #0xffffffff
 *   @0x2a4270 b 0x2a42e2 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1da>
 *   @0x2a4274 movs r2, #0x0
 *   @0x2a4278 bl 0x2a3a98 <zip_close+0x8ac>
 *   @0x2a427c str r0, [r4, #0x20]
 *   @0x2a4280 beq 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164>
 *   @0x2a4284 cmp r1, #0x0
 *   @0x2a4288 mov r0, r5
 *   @0x2a428c mov r3, r7
 *   @0x2a4290 adcvs pc, r0, #768
 *   @0x2a4294 cmp r0, #0x0
 *   @0x2a4298 b 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164>
 *   @0x2a429c ldrh r1, [r4, #0x24]
 *   @0x2a42a0 b 0x2a42b4 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1ac>
 *   @0x2a42a4 movs r2, #0x1
 *   @0x2a42a8 bl 0x2a3af4 <zip_close+0x908>
 *   @0x2a42ac str r0, [r4, #0x18]
 *   @0x2a42b0 bne 0x2a429c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x194>
 *   @0x2a42b4 mov r0, r10
 *   @0x2a42b8 mov r3, r7
 *   @0x2a42bc eorvs pc, r0, #6912
 *   @0x2a42c0 cmp r0, #0x0
 *   @0x2a42c4 ldrh r1, [r4, #0x2c]
 *   @0x2a42c8 mov r0, r10
 *   @0x2a42cc mov r3, r7
 *   @0x2a42d0 adcvs pc, r0, #4352
 *   @0x2a42d4 cmp r0, #0x0
 *   @0x2a42d8 cbz r6, 0x2a42e2 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1da>
 *   @0x2a42dc rsb r3, r11, r3
 *   @0x2a42e0 str r3, [r6]
 *   @0x2a42e4 mov r0, r8
 *   @0x2a42e8 ldr r3, [r1]
 *   @0x2a42ec beq 0x2a42fa <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1f2>
 *   @0x2a42f0 blls 0x35e8c0 <_ZTS12CDS_Priority+0x918>
 *   @0x2a42f4 str.w r3, [r9]
 *   @0x2a42f8 b 0x2a42d8 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1d0>
 *   @0x2a42fc pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2a4300 ldr r0, [sp, #0xf8]
 *   @0x2a4304 ldrb r2, [r2, #0x1a]
 *   @0x2a4308 ldrb r1, [r2, #0x1a]
 *
 * ══ §7/60 __divdf3  0x31ada0  size 516  129 条（0x31ada0..0x31afa4）
 * @func 0x31ada0 0x31afa4  size 516  129 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divdf3+0x194
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31ada0 push {r4, r5, r6, lr}
 *   @0x31ada4 mov r12, #255
 *   @0x31ada8 orr r12, r12, #1792
 *   @0x31adac ands r4, r12, r1, lsr #20
 *   @0x31adb0 andsne r5, r12, r3, lsr #20
 *   @0x31adb4 teqne r4, r12
 *   @0x31adb8 teqne r5, r12
 *   @0x31adbc bleq 0x31af34 <__divdf3+0x194>
 *   @0x31adc0 sub r4, r4, r5
 *   @0x31adc4 eor lr, r1, r3
 *   @0x31adc8 orrs r5, r2, r3, lsl #12
 *   @0x31adcc lsl r1, r1, #12
 *   @0x31add0 beq 0x31af04 <__divdf3+0x164>
 *   @0x31add4 lsl r3, r3, #12
 *   @0x31add8 mov r5, #268435456
 *   @0x31addc orr r3, r5, r3, lsr #4
 *   @0x31ade0 orr r3, r3, r2, lsr #24
 *   @0x31ade4 lsl r2, r2, #8
 *   @0x31ade8 orr r5, r5, r1, lsr #4
 *   @0x31adec orr r5, r5, r0, lsr #24
 *   @0x31adf0 lsl r6, r0, #8
 *   @0x31adf4 and r1, lr, #-2147483648
 *   @0x31adf8 cmp r5, r3
 *   @0x31adfc cmpeq r6, r2
 *   @0x31ae00 adc r4, r4, #253
 *   @0x31ae04 add r4, r4, #768
 *   @0x31ae08 bhs 0x31ae14 <__divdf3+0x74>
 *   @0x31ae0c lsrs r3, r3, #1
 *   @0x31ae10 rrx r2, r2
 *   @0x31ae14 subs r6, r6, r2
 *   @0x31ae18 sbc r5, r5, r3
 *   @0x31ae1c lsrs r3, r3, #1
 *   @0x31ae20 rrx r2, r2
 *   @0x31ae24 mov r0, #1048576
 *   @0x31ae28 mov r12, #524288
 *   @0x31ae2c subs lr, r6, r2
 *   @0x31ae30 sbcs lr, r5, r3
 *   @0x31ae34 subhs r6, r6, r2
 *   @0x31ae38 movhs r5, lr
 *   @0x31ae3c orrhs r0, r0, r12
 *   @0x31ae40 lsrs r3, r3, #1
 *   @0x31ae44 rrx r2, r2
 *   @0x31ae48 subs lr, r6, r2
 *   @0x31ae4c sbcs lr, r5, r3
 *   @0x31ae50 subhs r6, r6, r2
 *   @0x31ae54 movhs r5, lr
 *   @0x31ae58 orrhs r0, r0, r12, lsr #1
 *   @0x31ae5c lsrs r3, r3, #1
 *   @0x31ae60 rrx r2, r2
 *   @0x31ae64 subs lr, r6, r2
 *   @0x31ae68 sbcs lr, r5, r3
 *   @0x31ae6c subhs r6, r6, r2
 *   @0x31ae70 movhs r5, lr
 *   @0x31ae74 orrhs r0, r0, r12, lsr #2
 *   @0x31ae78 lsrs r3, r3, #1
 *   @0x31ae7c rrx r2, r2
 *   @0x31ae80 subs lr, r6, r2
 *   @0x31ae84 sbcs lr, r5, r3
 *   @0x31ae88 subhs r6, r6, r2
 *   @0x31ae8c movhs r5, lr
 *   @0x31ae90 orrhs r0, r0, r12, lsr #3
 *   @0x31ae94 orrs lr, r5, r6
 *   @0x31ae98 beq 0x31aed4 <__divdf3+0x134>
 *   @0x31ae9c lsl r5, r5, #4
 *   @0x31aea0 orr r5, r5, r6, lsr #28
 *   @0x31aea4 lsl r6, r6, #4
 *   @0x31aea8 lsl r3, r3, #3
 *   @0x31aeac orr r3, r3, r2, lsr #29
 *   @0x31aeb0 lsl r2, r2, #3
 *   @0x31aeb4 lsrs r12, r12, #4
 *   @0x31aeb8 bne 0x31ae2c <__divdf3+0x8c>
 *   @0x31aebc tst r1, #1048576
 *   @0x31aec0 bne 0x31aee0 <__divdf3+0x140>
 *   @0x31aec4 orr r1, r1, r0
 *   @0x31aec8 mov r0, #0
 *   @0x31aecc mov r12, #-2147483648
 *   @0x31aed0 b 0x31ae2c <__divdf3+0x8c>
 *   @0x31aed4 tst r1, #1048576
 *   @0x31aed8 orreq r1, r1, r0
 *   @0x31aedc moveq r0, #0
 *   @0x31aee0 subs r12, r4, #253
 *   @0x31aee4 cmphi r12, #1792
 *   @0x31aee8 bhi 0x31ac18 <__muldf3+0xe4>
 *   @0x31aeec subs r12, r5, r3
 *   @0x31aef0 subseq r12, r6, r2
 *   @0x31aef4 lsrseq r12, r0, #1
 *   @0x31aef8 adcs r0, r0, #0
 *   @0x31aefc adc r1, r1, r4, lsl #20
 *   @0x31af00 pop {r4, r5, r6, pc}
 *   @0x31af04 and lr, lr, #-2147483648
 *   @0x31af08 orr r1, lr, r1, lsr #12
 *   @0x31af0c adds r4, r4, r12, lsr #1
 *   @0x31af10 rsbsgt r5, r4, r12
 *   @0x31af14 orrgt r1, r1, r4, lsl #20
 *   @0x31af18 popgt {r4, r5, r6, pc}
 *   @0x31af1c orr r1, r1, #1048576
 *   @0x31af20 mov lr, #0
 *   @0x31af24 subs r4, r4, #1
 *   @0x31af28 b 0x31ac18 <__muldf3+0xe4>
 *   @0x31af2c orr lr, r5, r6
 *   @0x31af30 b 0x31ac18 <__muldf3+0xe4>
 *   @0x31af34 and r5, r12, r3, lsr #20
 *   @0x31af38 teq r4, r12
 *   @0x31af3c teqeq r5, r12
 *   @0x31af40 beq 0x31ad94 <__muldf3+0x260>
 *   @0x31af44 teq r4, r12
 *   @0x31af48 bne 0x31af68 <__divdf3+0x1c8>
 *   @0x31af4c orrs r4, r0, r1, lsl #12
 *   @0x31af50 bne 0x31ad94 <__muldf3+0x260>
 *   @0x31af54 teq r5, r12
 *   @0x31af58 bne 0x31ad7c <__muldf3+0x248>
 *   @0x31af5c mov r0, r2
 *   @0x31af60 mov r1, r3
 *   @0x31af64 b 0x31ad94 <__muldf3+0x260>
 *   @0x31af68 teq r5, r12
 *   @0x31af6c bne 0x31af84 <__divdf3+0x1e4>
 *   @0x31af70 orrs r5, r2, r3, lsl #12
 *   @0x31af74 beq 0x31ad30 <__muldf3+0x1fc>
 *   @0x31af78 mov r0, r2
 *   @0x31af7c mov r1, r3
 *   @0x31af80 b 0x31ad94 <__muldf3+0x260>
 *   @0x31af84 orrs r6, r0, r1, lsl #1
 *   @0x31af88 orrsne r6, r2, r3, lsl #1
 *   @0x31af8c bne 0x31acc8 <__muldf3+0x194>
 *   @0x31af90 orrs r4, r0, r1, lsl #1
 *   @0x31af94 bne 0x31ad7c <__muldf3+0x248>
 *   @0x31af98 orrs r5, r2, r3, lsl #1
 *   @0x31af9c bne 0x31ad30 <__muldf3+0x1fc>
 *   @0x31afa0 b 0x31ad94 <__muldf3+0x260>
 *
 * ══ §8/60 SGamepadMapping::CreateFromString(char const*)  0x152790  size 512  128 条（0x152790..0x152990）
 * @func 0x152790 0x152990  size 512  128 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66d0×5 / 0xb6634×4 / YYStrDup(char const*) / operator new(unsigned int) / SGamepadMapping::SGamepadMapping(char const*, char const*) / SGamepadEntry::FromString(char const*) / 0xb6538 / YYFree(void const*)
 * 字段偏移 top8: 0x4×8 / 0x10×3 / 0x1×3 / 0xc×3 / 0x17c×2 / 0x8×2 / 0x14×2 / 0x188×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x152790 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x152794 sub sp, sp, #28
 *   @0x152798 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x15279c mov r1, #44
 *   @0x1527a0 str r0, [sp, #0x10]
 *   @0x1527a4 bl 0xb6634 <strchr@plt>
 *   @0x1527a8 subs r5, r0, #0
 *   @0x1527ac beq 0x152970 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1e0>
 *   @0x1527b0 add r6, r5, #1
 *   @0x1527b4 mov r1, #44
 *   @0x1527b8 mov r0, r6
 *   @0x1527bc bl 0xb6634 <strchr@plt>
 *   @0x1527c0 cmp r0, #0
 *   @0x1527c4 beq 0x152958 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1c8>
 *   @0x1527c8 mov r4, r0
 *   @0x1527cc mov r7, #0
 *   @0x1527d0 mov r0, #268
 *   @0x1527d4 strb r7, [r5]
 *   @0x1527d8 strb r7, [r4], #1
 *   @0x1527dc bl 0x27c524 <_Znwj>
 *   @0x1527e0 ldr r1, [sp, #0x10]
 *   @0x1527e4 mov r2, r6
 *   @0x1527e8 ldr r9, [pc, #0x188]
 *   @0x1527ec add r9, pc, r9
 *   @0x1527f0 str r0, [sp, #0x4]
 *   @0x1527f4 bl 0x15272c <_ZN15SGamepadMappingC2EPKcS1_>
 *   @0x1527f8 ldr r3, [pc, #0x17c]
 *   @0x1527fc ldr r2, [pc, #0x17c]
 *   @0x152800 ldr r3, [pc, r3]
 *   @0x152804 ldr r1, [pc, #0x178]
 *   @0x152808 add r2, pc, r2
 *   @0x15280c str r2, [sp, #0x8]
 *   @0x152810 ldr r2, [pc, #0x170]
 *   @0x152814 add r1, pc, r1
 *   @0x152818 str r1, [sp, #0x14]
 *   @0x15281c add r2, pc, r2
 *   @0x152820 ldr r1, [sp, #0x4]
 *   @0x152824 str r2, [sp, #0xc]
 *   @0x152828 ldr r2, [r3]
 *   @0x15282c str r2, [r1]
 *   @0x152830 str r1, [r3]
 *   @0x152834 b 0x152890 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x100>
 *   @0x152838 mov r0, r5
 *   @0x15283c ldr r1, [sp, #0x8]
 *   @0x152840 bl 0xb66d0 <strcasecmp@plt>
 *   @0x152844 cmp r0, #0
 *   @0x152848 beq 0x15287c <_ZN15SGamepadMapping16CreateFromStringEPKc+0xec>
 *   @0x15284c mov r0, r5
 *   @0x152850 ldr r1, [sp, #0xc]
 *   @0x152854 bl 0xb66d0 <strcasecmp@plt>
 *   @0x152858 cmp r0, #0
 *   @0x15285c moveq r0, #1
 *   @0x152860 beq 0x15287c <_ZN15SGamepadMapping16CreateFromStringEPKc+0xec>
 *   @0x152864 mov r0, r5
 *   @0x152868 ldr r1, [sp, #0x14]
 *   @0x15286c bl 0xb66d0 <strcasecmp@plt>
 *   @0x152870 cmp r0, #0
 *   @0x152874 moveq r0, #6
 *   @0x152878 movne r0, #0
 *   @0x15287c ldr r3, [sp, #0x4]
 *   @0x152880 str r0, [r3, #0xc]
 *   @0x152884 cmp r8, #0
 *   @0x152888 add r4, r6, #1
 *   @0x15288c bne 0x15295c <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1cc>
 *   @0x152890 mov r0, r4
 *   @0x152894 mov r1, #44
 *   @0x152898 bl 0xb6634 <strchr@plt>
 *   @0x15289c subs r6, r0, #0
 *   @0x1528a0 movne r8, #0
 *   @0x1528a4 beq 0x152944 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1b4>
 *   @0x1528a8 strb r7, [r6]
 *   @0x1528ac mov r0, r4
 *   @0x1528b0 mov r1, #58
 *   @0x1528b4 bl 0xb6634 <strchr@plt>
 *   @0x1528b8 subs r10, r0, #0
 *   @0x1528bc beq 0x15295c <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1cc>
 *   @0x1528c0 mov r5, r10
 *   @0x1528c4 mov r0, r4
 *   @0x1528c8 strb r7, [r5], #1
 *   @0x1528cc mov r1, r9
 *   @0x1528d0 bl 0xb66d0 <strcasecmp@plt>
 *   @0x1528d4 cmp r0, #0
 *   @0x1528d8 beq 0x152838 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xa8>
 *   @0x1528dc ldrb r3, [r10, #0x1]
 *   @0x1528e0 cmp r3, #0
 *   @0x1528e4 beq 0x152884 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xf4>
 *   @0x1528e8 ldr r3, [pc, #0x9c]
 *   @0x1528ec ldr r3, [pc, r3]
 *   @0x1528f0 ldr r10, [r3, #0x4]
 *   @0x1528f4 cmp r10, #21
 *   @0x1528f8 beq 0x152884 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xf4>
 *   @0x1528fc add r11, r3, #8
 *   @0x152900 b 0x152910 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x180>
 *   @0x152904 ldr r10, [r11, #-0x4]
 *   @0x152908 cmp r10, #21
 *   @0x15290c beq 0x152884 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xf4>
 *   @0x152910 ldr r1, [r11, #-0x8]
 *   @0x152914 mov r0, r4
 *   @0x152918 bl 0xb66d0 <strcasecmp@plt>
 *   @0x15291c add r11, r11, #8
 *   @0x152920 cmp r0, #0
 *   @0x152924 bne 0x152904 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x174>
 *   @0x152928 add r2, r10, r10, lsl #1
 *   @0x15292c ldr r3, [sp, #0x4]
 *   @0x152930 mov r1, r5
 *   @0x152934 add r0, r3, r2, lsl #2
 *   @0x152938 add r0, r0, #16
 *   @0x15293c bl 0x152694 <_ZN13SGamepadEntry10FromStringEPKc>
 *   @0x152940 b 0x152884 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xf4>
 *   @0x152944 mov r0, r4
 *   @0x152948 mov r8, #1
 *   @0x15294c bl 0xb6538 <strlen@plt>
 *   @0x152950 add r6, r4, r0
 *   @0x152954 b 0x1528a8 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x118>
 *   @0x152958 str r0, [sp, #0x4]
 *   @0x15295c ldr r0, [sp, #0x10]
 *   @0x152960 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x152964 ldr r0, [sp, #0x4]
 *   @0x152968 add sp, sp, #28
 *   @0x15296c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x152970 str r5, [sp, #0x4]
 *   @0x152974 b 0x15295c <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1cc>
 *   @0x152978 andseq r3, pc, r4, asr #8
 *   @0x15297c eoreq sp, r9, r8, ror #4
 *   @0x152980 andseq r3, pc, r4, lsr r4
 *   @0x152984 ldrsbeq r3, [pc], -r12
 *   @0x152988 andseq r3, pc, r8, lsr #8
 *   @0x15298c eoreq sp, r9, r0, lsl #3
 *
 * ══ §9/60 CLayerManager::AddLayer(CRoom*, int, char const*)  0x1c3598  size 512  128 条（0x1c3598..0x1c3798）
 * @func 0x1c3598 0x1c3798  size 512  128 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CLayerManager::AddLayer(CRoom*, int, char const*)+0x114 / CTimingSource::Reset() / CLayerManager::AddLayer(CRoom*, int, char const*)+0x50 / 0xb6538 / 0xb65bc / CLayerManager::InsertLayerIntoActiveList(CRoom*, CLayer*)
 * 字段偏移 top8: 0x8×7 / 0x4×5 / 0x10×3 / 0xc×2 / 0x19×2 / 0x1c×2 / 0x68×2 / 0x6c×2
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c3598 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1c359c vpush {d8}
 *   @0x1c35a0 sub sp, sp, #20
 *   @0x1c35a4 ldr r10, [pc, #0x1d8]
 *   @0x1c35a8 str r0, [sp, #0x8]
 *   @0x1c35ac ldr r10, [pc, r10]
 *   @0x1c35b0 str r1, [sp, #0xc]
 *   @0x1c35b4 str r2, [sp, #0x4]
 *   @0x1c35b8 ldr r6, [r10, #0x8]
 *   @0x1c35bc cmp r6, #0
 *   @0x1c35c0 bne 0x1c36b4 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0x11c>
 *   @0x1c35c4 ldr r3, [r10, #0x10]
 *   @0x1c35c8 cmp r3, #0
 *   @0x1c35cc ble 0x1c36ac <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0x114>
 *   @0x1c35d0 ldr r8, [pc, #0x1b0]
 *   @0x1c35d4 mov r7, #1
 *   @0x1c35d8 mov r4, #0
 *   @0x1c35dc mov r5, #0
 *   @0x1c35e0 add r8, pc, r8
 *   @0x1c35e4 vldr s16, [pc, #404]
 *   @0x1c35e8 mov r3, #1
 *   @0x1c35ec mov r0, #112
 *   @0x1c35f0 mov r1, r8
 *   @0x1c35f4 mov r2, #63
 *   @0x1c35f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c35fc mov r11, #0
 *   @0x1c3600 mvn r3, #0
 *   @0x1c3604 subs r9, r0, #0
 *   @0x1c3608 add r0, r9, #48
 *   @0x1c360c beq 0x1c3660 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0xc8>
 *   @0x1c3610 str r3, [r9]
 *   @0x1c3614 vstr s16, [r9, #8]
 *   @0x1c3618 str r11, [r9, #0x4]
 *   @0x1c361c vstr s16, [r9, #12]
 *   @0x1c3620 vstr s16, [r9, #16]
 *   @0x1c3624 vstr s16, [r9, #20]
 *   @0x1c3628 strb r7, [r9, #0x18]
 *   @0x1c362c strd r4, r5, [r9, #72]
 *   @0x1c3630 strb r11, [r9, #0x19]
 *   @0x1c3634 str r11, [r9, #0x1c]
 *   @0x1c3638 str r3, [r9, #0x20]
 *   @0x1c363c str r3, [r9, #0x24]
 *   @0x1c3640 str r3, [r9, #0x28]
 *   @0x1c3644 bl 0x214728 <_ZN13CTimingSource5ResetEv>
 *   @0x1c3648 str r11, [r9, #0x5c]
 *   @0x1c364c str r11, [r9, #0x58]
 *   @0x1c3650 str r11, [r9, #0x60]
 *   @0x1c3654 str r7, [r9, #0x64]
 *   @0x1c3658 str r11, [r9, #0x68]
 *   @0x1c365c str r11, [r9, #0x6c]
 *   @0x1c3660 ldr r3, [r10]
 *   @0x1c3664 mov r1, #0
 *   @0x1c3668 add r6, r6, #1
 *   @0x1c366c ldr r2, [r10, #0x8]
 *   @0x1c3670 cmp r3, r1
 *   @0x1c3674 streq r9, [r10, #0x4]
 *   @0x1c3678 strne r9, [r3, #0x6c]
 *   @0x1c367c add r2, r2, #1
 *   @0x1c3680 streq r3, [r9, #0x6c]
 *   @0x1c3684 streq r3, [r9, #0x68]
 *   @0x1c3688 strne r3, [r9, #0x68]
 *   @0x1c368c ldr r3, [r10, #0x10]
 *   @0x1c3690 streq r9, [r10]
 *   @0x1c3694 strne r9, [r10]
 *   @0x1c3698 strne r1, [r9, #0x6c]
 *   @0x1c369c cmp r6, r3
 *   @0x1c36a0 str r2, [r10, #0x8]
 *   @0x1c36a4 blt 0x1c35e8 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0x50>
 *   @0x1c36a8 ldr r6, [r10, #0x8]
 *   @0x1c36ac lsl r3, r3, #1
 *   @0x1c36b0 str r3, [r10, #0x10]
 *   @0x1c36b4 ldr r4, [r10]
 *   @0x1c36b8 sub r6, r6, #1
 *   @0x1c36bc ldr r1, [sp, #0xc]
 *   @0x1c36c0 mov r0, #0
 *   @0x1c36c4 str r6, [r10, #0x8]
 *   @0x1c36c8 ldr r3, [r4, #0x6c]
 *   @0x1c36cc ldr r2, [r4, #0x68]
 *   @0x1c36d0 cmp r3, #0
 *   @0x1c36d4 strne r2, [r3, #0x68]
 *   @0x1c36d8 ldrne r2, [r4, #0x68]
 *   @0x1c36dc ldrne r3, [r4, #0x6c]
 *   @0x1c36e0 streq r2, [r10]
 *   @0x1c36e4 cmp r2, #0
 *   @0x1c36e8 streq r3, [r10, #0x4]
 *   @0x1c36ec strne r3, [r2, #0x6c]
 *   @0x1c36f0 ldr r2, [pc, #0x94]
 *   @0x1c36f4 ldr r3, [pc, #0x94]
 *   @0x1c36f8 ldr r2, [pc, r2]
 *   @0x1c36fc str r1, [r4, #0x4]
 *   @0x1c3700 ldr r3, [pc, r3]
 *   @0x1c3704 strb r0, [r4, #0x19]
 *   @0x1c3708 ldr r1, [r2]
 *   @0x1c370c ldr r2, [r3]
 *   @0x1c3710 cmp r2, r1
 *   @0x1c3714 movlt r2, r1
 *   @0x1c3718 ldr r1, [sp, #0x4]
 *   @0x1c371c add r2, r2, #1
 *   @0x1c3720 str r2, [r3]
 *   @0x1c3724 cmp r1, r0
 *   @0x1c3728 str r2, [r4]
 *   @0x1c372c beq 0x1c3764 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0x1cc>
 *   @0x1c3730 mov r0, r1
 *   @0x1c3734 bl 0xb6538 <strlen@plt>
 *   @0x1c3738 mov r3, #1
 *   @0x1c373c ldr r1, [pc, #0x50]
 *   @0x1c3740 movw r2, #0x4ea
 *   @0x1c3744 add r1, pc, r1
 *   @0x1c3748 add r5, r0, r3
 *   @0x1c374c mov r0, r5
 *   @0x1c3750 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c3754 mov r2, r5
 *   @0x1c3758 ldr r1, [sp, #0x4]
 *   @0x1c375c str r0, [r4, #0x1c]
 *   @0x1c3760 bl 0xb65bc <memcpy@plt>
 *   @0x1c3764 ldr r0, [sp, #0x8]
 *   @0x1c3768 mov r1, r4
 *   @0x1c376c bl 0x1c30f8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer>
 *   @0x1c3770 mov r0, r4
 *   @0x1c3774 add sp, sp, #20
 *   @0x1c3778 vpop {d8}
 *   @0x1c377c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1c3780 andeq r0, r0, r0
 *   @0x1c3784 .word 0x0022d2b0
 *   @0x1c3788 ldrheq r10, [r8], -r4
 *   @0x1c378c eoreq sp, r2, r8, lsl #3
 *   @0x1c3790 .word 0x0022d3dc
 *   @0x1c3794 andseq r10, r8, r8, lsr #32
 *
 * ══ §10/60 CTimeLine::LoadFromChunk(YYTimeline*, unsigned char*)  0x1f19b4  size 512  128 条（0x1f19b4..0x1f1bb4）
 * @func 0x1f19b4 0x1f1bb4  size 512  128 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / CTimeLine::Clear() / CTimeLine::LoadFromChunk(YYTimeline*, unsigned char*)+0xb4 / CTimeLine::LoadFromChunk(YYTimeline*, unsigned char*)+0x4c / CTimeLine::LoadFromChunk(YYTimeline*, unsigned char*)+0x18c / operator new(unsigned int) / CEvent::CEvent()
 * 字段偏移 top8: 0xc×9 / 0x4×6 / 0x14×5 / 0x8×4 / 0x2×2 / 0xf8×1 / 0x10×1 / 0x-8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f19b4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1f19b8 mov r9, r1
 *   @0x1f19bc mov r6, r0
 *   @0x1f19c0 sub sp, sp, #8
 *   @0x1f19c4 mov r10, r2
 *   @0x1f19c8 bl 0x1f1768 <_ZN9CTimeLine5ClearEv>
 *   @0x1f19cc ldr r5, [r9, #0x4]
 *   @0x1f19d0 ldr r12, [r6, #0x8]
 *   @0x1f19d4 cmp r5, r12
 *   @0x1f19d8 beq 0x1f1a80 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xcc>
 *   @0x1f19dc cmp r5, #0
 *   @0x1f19e0 bne 0x1f1b4c <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x198>
 *   @0x1f19e4 ldr r3, [r6, #0xc]
 *   @0x1f19e8 cmp r3, #0
 *   @0x1f19ec beq 0x1f1a68 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xb4>
 *   @0x1f19f0 cmp r12, #0
 *   @0x1f19f4 ble 0x1f1a68 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xb4>
 *   @0x1f19f8 mov r4, r5
 *   @0x1f19fc mov r8, r5
 *   @0x1f1a00 ldr r0, [r3]
 *   @0x1f1a04 movw r2, #0xfeee
 *   @0x1f1a08 movt r2, #0xfeee
 *   @0x1f1a0c movw r1, #0xfeee
 *   @0x1f1a10 cmp r0, r2
 *   @0x1f1a14 movt r1, #0xfeee
 *   @0x1f1a18 lsl r7, r4, #2
 *   @0x1f1a1c beq 0x1f1a5c <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xa8>
 *   @0x1f1a20 ldr r2, [r3, r4, lsl #2]
 *   @0x1f1a24 add lr, r3, r7
 *   @0x1f1a28 cmp r2, #0
 *   @0x1f1a2c mov r0, r2
 *   @0x1f1a30 beq 0x1f1a5c <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xa8>
 *   @0x1f1a34 ldr r3, [r2]
 *   @0x1f1a38 cmp r3, r1
 *   @0x1f1a3c beq 0x1f1a54 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xa0>
 *   @0x1f1a40 ldr r3, [r3, #0x4]
 *   @0x1f1a44 blx r3
 *   @0x1f1a48 ldr lr, [r6, #0xc]
 *   @0x1f1a4c ldr r12, [r6, #0x8]
 *   @0x1f1a50 add lr, lr, r7
 *   @0x1f1a54 str r8, [lr]
 *   @0x1f1a58 ldr r3, [r6, #0xc]
 *   @0x1f1a5c add r4, r4, #1
 *   @0x1f1a60 cmp r4, r12
 *   @0x1f1a64 blt 0x1f1a00 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x4c>
 *   @0x1f1a68 mov r0, r3
 *   @0x1f1a6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1a70 mov r3, #0
 *   @0x1f1a74 str r3, [r6, #0xc]
 *   @0x1f1a78 str r5, [r6, #0x8]
 *   @0x1f1a7c ldr r5, [r9, #0x4]
 *   @0x1f1a80 cmp r5, #0
 *   @0x1f1a84 ldr r0, [r6, #0x14]
 *   @0x1f1a88 bne 0x1f1aa0 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xec>
 *   @0x1f1a8c cmp r0, #0
 *   @0x1f1a90 beq 0x1f1b80 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x1cc>
 *   @0x1f1a94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1a98 str r5, [r6, #0x14]
 *   @0x1f1a9c b 0x1f1ac4 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x110>
 *   @0x1f1aa0 lsls r1, r5, #2
 *   @0x1f1aa4 beq 0x1f1b80 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x1cc>
 *   @0x1f1aa8 ldr r2, [pc, #0xf8]
 *   @0x1f1aac mov r3, #0
 *   @0x1f1ab0 str r3, [sp]
 *   @0x1f1ab4 mov r3, #106
 *   @0x1f1ab8 add r2, pc, r2
 *   @0x1f1abc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f1ac0 str r0, [r6, #0x14]
 *   @0x1f1ac4 ldr r3, [r9, #0x4]
 *   @0x1f1ac8 str r5, [r6, #0x10]
 *   @0x1f1acc cmp r3, #0
 *   @0x1f1ad0 ble 0x1f1b40 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x18c>
 *   @0x1f1ad4 add r5, r9, #16
 *   @0x1f1ad8 mov r4, #0
 *   @0x1f1adc ldr r2, [r5, #-0x8]
 *   @0x1f1ae0 mov r0, #12
 *   @0x1f1ae4 ldr r3, [r6, #0x14]
 *   @0x1f1ae8 lsl r8, r4, #2
 *   @0x1f1aec add r5, r5, #8
 *   @0x1f1af0 str r2, [r3, r4, lsl #2]
 *   @0x1f1af4 add r4, r4, #1
 *   @0x1f1af8 bl 0x27c524 <_Znwj>
 *   @0x1f1afc mov r7, r0
 *   @0x1f1b00 bl 0xf2d0c <_ZN6CEventC2Ev>
 *   @0x1f1b04 ldr r3, [r5, #-0xc]
 *   @0x1f1b08 mov r0, r7
 *   @0x1f1b0c ldr r2, [pc, #0x98]
 *   @0x1f1b10 cmp r3, #0
 *   @0x1f1b14 ldrne r2, [pc, r2]
 *   @0x1f1b18 mov r1, r3
 *   @0x1f1b1c ldrne r1, [r2]
 *   @0x1f1b20 mov r2, r10
 *   @0x1f1b24 addne r1, r1, r3
 *   @0x1f1b28 bl 0xf2d84 <_ZN6CEvent13LoadFromChunkEP7YYEventPh>
 *   @0x1f1b2c ldr r2, [r9, #0x4]
 *   @0x1f1b30 ldr r3, [r6, #0xc]
 *   @0x1f1b34 cmp r2, r4
 *   @0x1f1b38 str r7, [r3, r8]
 *   @0x1f1b3c bgt 0x1f1adc <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x128>
 *   @0x1f1b40 mov r0, #1
 *   @0x1f1b44 add sp, sp, #8
 *   @0x1f1b48 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f1b4c lsls r1, r5, #2
 *   @0x1f1b50 beq 0x1f1b90 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x1dc>
 *   @0x1f1b54 ldr r2, [pc, #0x54]
 *   @0x1f1b58 mov r3, #0
 *   @0x1f1b5c ldr r0, [r6, #0xc]
 *   @0x1f1b60 add r2, pc, r2
 *   @0x1f1b64 str r3, [sp]
 *   @0x1f1b68 mov r3, #135
 *   @0x1f1b6c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f1b70 str r5, [r6, #0x8]
 *   @0x1f1b74 ldr r5, [r9, #0x4]
 *   @0x1f1b78 str r0, [r6, #0xc]
 *   @0x1f1b7c b 0x1f1a80 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xcc>
 *   @0x1f1b80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1b84 mov r3, #0
 *   @0x1f1b88 str r3, [r6, #0x14]
 *   @0x1f1b8c b 0x1f1ac4 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x110>
 *   @0x1f1b90 ldr r3, [r6, #0xc]
 *   @0x1f1b94 mov r0, r3
 *   @0x1f1b98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1b9c mov r3, #0
 *   @0x1f1ba0 str r3, [r6, #0xc]
 *   @0x1f1ba4 b 0x1f1a78 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xc4>
 *   @0x1f1ba8 andseq r0, r6, r12, lsl r12
 *   @0x1f1bac andseq r11, pc, r0, lsr lr
 *   @0x1f1bb0 andseq r0, r6, r0, lsr r11
 *
 * ══ §11/60 JS_Number_Prototype_toPrecision(RValue&, CInstance*, CInstance*, int, RValue*)  0x257048  size 512  128 条（0x257048..0x257248）
 * @func 0x257048 0x257248  size 512  128 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::FindValue(char const*)×2 / 0xb6550×2 / YYCreateString(RValue*, char const*)×2 / JS_Number_Prototype_toPrecision(RValue&, CInstance*, CInstance*, int, RValue*)+0x158 / F_JS_ToInteger(RValue&) / 0xb65b0 / 0xb6538 / JS_Number_Prototype_toPrecision(RValue&, CInstance*, CInstance*, int, RValue*)+0x108
 * 字段偏移 top8: 0x-40×3 / 0x-3c×3 / 0x-30×2 / 0x-34×2 / 0x1d0×1 / 0x4×1 / 0xc×1 / 0x174×1
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x257048 push {r4, r5, r6, r7, r8, r11, lr}
 *   @0x25704c vpush {d8, d9}
 *   @0x257050 add r11, sp, #40
 *   @0x257054 ldr r6, [pc, #0x1d0]
 *   @0x257058 sub sp, sp, #36
 *   @0x25705c cmp r3, #0
 *   @0x257060 ldr r6, [pc, r6]
 *   @0x257064 mov r8, r0
 *   @0x257068 mov r4, r1
 *   @0x25706c ldr r0, [r11, #0x4]
 *   @0x257070 ldr r3, [r6]
 *   @0x257074 str r3, [r11, #-0x30]
 *   @0x257078 ble 0x2571a0 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x25707c ldr r3, [r0, #0xc]
 *   @0x257080 bic r3, r3, #-16777216
 *   @0x257084 cmp r3, #5
 *   @0x257088 beq 0x2571a0 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x25708c bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x257090 vmov.f64 d7, #1.000000e+00
 *   @0x257094 vmov d8, r0, r1
 *   @0x257098 vcmpe.f64 d8, d7
 *   @0x25709c vmrs APSR_nzcv, fpscr
 *   @0x2570a0 bmi 0x257178 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2570a4 vmov.f64 d7, #2.000000e+01
 *   @0x2570a8 vcmpe.f64 d8, d7
 *   @0x2570ac vmrs APSR_nzcv, fpscr
 *   @0x2570b0 bgt 0x257178 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2570b4 ldr r1, [pc, #0x174]
 *   @0x2570b8 mov r0, r4
 *   @0x2570bc mov r7, #0
 *   @0x2570c0 str r7, [r11, #-0x34]
 *   @0x2570c4 add r1, pc, r1
 *   @0x2570c8 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x2570cc ldm r0, {r4, r5}
 *   @0x2570d0 vmov d6, r4, r5
 *   @0x2570d4 str r4, [r11, #-0x40]
 *   @0x2570d8 str r5, [r11, #-0x3c]
 *   @0x2570dc vmov d7, r4, r5
 *   @0x2570e0 vcmp.f64 d6, d7
 *   @0x2570e4 vmrs APSR_nzcv, fpscr
 *   @0x2570e8 bvs 0x2571e8 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x2570ec sub sp, sp, #264
 *   @0x2570f0 mov r1, r7
 *   @0x2570f4 add r7, sp, #8
 *   @0x2570f8 mov r2, #256
 *   @0x2570fc mov r0, r7
 *   @0x257100 bl 0xb65b0 <memset@plt>
 *   @0x257104 vcvt.s32.f64 s12, d8
 *   @0x257108 ldr r1, [pc, #0x124]
 *   @0x25710c mov r0, r7
 *   @0x257110 strd r4, r5, [sp]
 *   @0x257114 add r1, pc, r1
 *   @0x257118 vmov r2, s12
 *   @0x25711c bl 0xb6550 <sprintf@plt>
 *   @0x257120 mov r0, r7
 *   @0x257124 bl 0xb6538 <strlen@plt>
 *   @0x257128 vmov s13, r0
 *   @0x25712c vcvt.f64.u32 d9, s13
 *   @0x257130 vcmpe.f64 d8, d9
 *   @0x257134 vmrs APSR_nzcv, fpscr
 *   @0x257138 ble 0x257150 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x25713c mov r0, r7
 *   @0x257140 mov r1, #46
 *   @0x257144 bl 0xb6634 <strchr@plt>
 *   @0x257148 cmp r0, #0
 *   @0x25714c beq 0x2571fc <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x257150 mov r0, r8
 *   @0x257154 mov r1, r7
 *   @0x257158 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x25715c ldr r2, [r11, #-0x30]
 *   @0x257160 ldr r3, [r6]
 *   @0x257164 cmp r2, r3
 *   @0x257168 bne 0x257228 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x25716c sub sp, r11, #40
 *   @0x257170 vpop {d8, d9}
 *   @0x257174 pop {r4, r5, r6, r7, r8, r11, pc}
 *   @0x257178 vcmp.f64 d8, d8
 *   @0x25717c vmrs APSR_nzcv, fpscr
 *   @0x257180 movvs r3, #0
 *   @0x257184 movvc r3, #1
 *   @0x257188 cmp r3, #0
 *   @0x25718c beq 0x2570b4 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x257190 ldr r0, [pc, #0xa0]
 *   @0x257194 add r0, pc, r0
 *   @0x257198 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc>
 *   @0x25719c b 0x25715c <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x2571a0 ldr r1, [pc, #0x94]
 *   @0x2571a4 mov r0, r4
 *   @0x2571a8 mov r3, #0
 *   @0x2571ac str r3, [r11, #-0x34]
 *   @0x2571b0 add r1, pc, r1
 *   @0x2571b4 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x2571b8 ldm r0, {r2, r3}
 *   @0x2571bc vmov d6, r2, r3
 *   @0x2571c0 str r2, [r11, #-0x40]
 *   @0x2571c4 str r3, [r11, #-0x3c]
 *   @0x2571c8 vmov d7, r2, r3
 *   @0x2571cc vcmp.f64 d6, d7
 *   @0x2571d0 vmrs APSR_nzcv, fpscr
 *   @0x2571d4 bvs 0x2571e8 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x2571d8 mov r0, r8
 *   @0x2571dc sub r1, r11, #64
 *   @0x2571e0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2571e4 b 0x25715c <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x2571e8 ldr r1, [pc, #0x50]
 *   @0x2571ec mov r0, r8
 *   @0x2571f0 add r1, pc, r1
 *   @0x2571f4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2571f8 b 0x25715c <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x2571fc vsub.f64 d8, d8, d9
 *   @0x257200 ldr r2, [r11, #-0x40]
 *   @0x257204 ldr r3, [r11, #-0x3c]
 *   @0x257208 mov r0, r7
 *   @0x25720c ldr r1, [pc, #0x30]
 *   @0x257210 strd r2, r3, [sp]
 *   @0x257214 add r1, pc, r1
 *   @0x257218 vcvt.s32.f64 s14, d8
 *   @0x25721c vmov r2, s14
 *   @0x257220 bl 0xb6550 <sprintf@plt>
 *   @0x257224 b 0x257150 <_Z31JS_Number_Prototype_toPrecisionR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x257228 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x25722c ldrsheq r6, [r9], -r0
 *   @0x257230 andeq lr, pc, r12, asr #8
 *   @0x257234 andeq pc, pc, r8, ror #19
 *   @0x257238 andeq pc, pc, r0, lsr #18
 *   @0x25723c andeq lr, pc, r0, ror #6
 *   @0x257240 andeq r11, sp, r4, lsl #6
 *   @0x257244 muleq pc, r8, r8
 *
 * ══ §12/60 png_handle_sPLT  0x2ac9ec  size 512  128 条（0x2ac9ec..0x2acbec）
 * @func 0x2ac9ec 0x2acbec  size 512  128 条
 * 部分覆盖: 本节 128/231 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×2 / png_free×2 / png_crc_finish / png_error / png_malloc / png_handle_sPLT+0xb6 / png_handle_sPLT+0xcc / 0x484b4a
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x1c0×1 / 0xd8×1 / 0x2×1 / 0x6×1 / 0x3×1 / 0x7×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ac9ec push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ac9f0 mov r4, r0
 *   @0x2ac9f4 addlt r3, r5, r0, lsl r3
 *   @0x2ac9f8 mov r8, r1
 *   @0x2ac9fc cbz r3, 0x2aca1e <png_handle_sPLT+0x32>
 *   @0x2aca00 beq 0x2aca16 <png_handle_sPLT+0x2a>
 *   @0x2aca04 str.w r3, [r0, #0x310]
 *   @0x2aca08 cmp r3, #0x1
 *   @0x2aca0c ldr r1, [pc, #0x1c0]
 *   @0x2aca10 bl 0x2a6474 <png_warning>
 *   @0x2aca14 mov r0, r4
 *   @0x2aca18 bl 0x2abc94 <png_crc_finish>
 *   @0x2aca1c b 0x2acbc4 <png_handle_sPLT+0x1d8>
 *   @0x2aca20 ldrbeq r3, [r10, r12, lsr #2]
 *   @0x2aca24 bmi 0x2aca32 <png_handle_sPLT+0x46>
 *   @0x2aca28 mov r0, r4
 *   @0x2aca2c bl 0x2a642c <png_error>
 *   @0x2aca30 b 0x2aca3e <png_handle_sPLT+0x52>
 *   @0x2aca34 bpl 0x2aca3e <png_handle_sPLT+0x52>
 *   @0x2aca38 mov r0, r4
 *   @0x2aca3c b 0x2aca10 <png_handle_sPLT+0x24>
 *   @0x2aca40 ldr.w r1, [r4, #0x330]
 *   @0x2aca44 bl 0x2a6cfc <png_free>
 *   @0x2aca48 adds r1, r6, #0x1
 *   @0x2aca4c bl 0x2a6ca0 <png_malloc>
 *   @0x2aca50 mov r2, r6
 *   @0x2aca54 str.w r0, [r4, #0x330]
 *   @0x2aca58 mov r0, r4
 *   @0x2aca5c .word 0x4620f8d7
 *   @0x2aca60 movs r1, #0x0
 *   @0x2aca64 .word 0xb140f917
 *   @0x2aca68 mov r0, r4
 *   @0x2aca6c .word 0xf7fa1330
 *   @0x2aca70 movwhs pc, #0x945
 *   @0x2aca74 str.w r3, [r4, #0x330]
 *   @0x2aca78 b 0x2acbc4 <png_handle_sPLT+0x1d8>
 *   @0x2aca7c ldrpl r3, [r8, #0x330]
 *   @0x2aca80 ldr.w r7, [r4, #0x330]
 *   @0x2aca84 mov r2, r7
 *   @0x2aca88 adds r2, #0x1
 *   @0x2aca8c .word 0xf1b99000
 *   @0x2aca90 mvnsle r0, r0, lsl #30
 *   @0x2aca94 cmp r6, #0x1
 *   @0x2aca98 bls 0x2acaa2 <png_handle_sPLT+0xb6>
 *   @0x2aca9c add r2, r7
 *   @0x2acaa0 bls 0x2acab8 <png_handle_sPLT+0xcc>
 *   @0x2acaa4 mov r1, r7
 *   @0x2acaa8 stmdbmi r12, {r0, r3, r5, r8, r11, r12, sp, lr, pc} ^
 *   @0x2acaac movs r3, #0x0
 *   @0x2acab0 str.w r3, [r4, #0x330]
 *   @0x2acab4 add r1, pc
 *   @0x2acab8 ldrb.w r10, [r3, #0x1]
 *   @0x2acabc adds r5, r3, #0x2
 *   @0x2acac0 ldrtmi r0, [r3], #2823
 *   @0x2acac4 strb.w r10, [sp, #0x4]
 *   @0x2acac8 cmp.w r10, #0x8
 *   @0x2acacc ite ne
 *   @0x2acad0 .word 0xf04f0a0a
 *   @0x2acad4 ldrbmi r0, [r8], -r6, lsl #20
 *   @0x2acad8 mov r1, r10
 *   @0x2acadc strmi lr, [lr], -r8, lsl #19
 *   @0x2acae0 cbz r1, 0x2acaf6 <png_handle_sPLT+0x10a>
 *   @0x2acae4 mov r1, r7
 *   @0x2acae8 ldmdbmi sp!, {r0, r3, r8, r11, r12, sp, lr, pc}
 *   @0x2acaec str.w r9, [r4, #0x330]
 *   @0x2acaf0 mov r0, r4
 *   @0x2acaf4 b 0x2acb28 <png_handle_sPLT+0x13c>
 *   @0x2acaf8 mov r0, r11
 *   @0x2acafc bmi 0xfa6f2c <b2_toiTime+0x84da88>
 *   @0x2acb00 cmp r0, r2
 *   @0x2acb04 str r0, [sp, #0xc]
 *   @0x2acb08 ldr r1, [pc, #0xd8]
 *   @0x2acb0c add r1, pc
 *   @0x2acb10 movs r7, #0xa
 *   @0x2acb14 muls r1, r7, r1
 *   @0x2acb18 .word 0x9002f8fe
 *   @0x2acb1c cbz r0, 0x2acb22 <png_handle_sPLT+0x136>
 *   @0x2acb20 b 0x2acb60 <png_handle_sPLT+0x174>
 *   @0x2acb24 mov r0, r4
 *   @0x2acb28 bl 0x2a6474 <png_warning>
 *   @0x2acb2c b 0x2acbc4 <png_handle_sPLT+0x1d8>
 *   @0x2acb30 blx 0x484b4a <g_AccelX+0x8e>
 *   @0x2acb34 stmdals r2, {r1, r8, r12, sp, lr, pc}
 *   @0x2acb38 cmp r6, #0x8
 *   @0x2acb3c add.w r3, r0, r1
 *   @0x2acb40 bne 0x2acb68 <png_handle_sPLT+0x17c>
 *   @0x2acb44 adds r0, r5, #0x4
 *   @0x2acb48 strh r1, [r3, #0x2]
 *   @0x2acb4c strh r1, [r3, #0x4]
 *   @0x2acb50 strh r1, [r3, #0x6]
 *   @0x2acb54 adds r2, #0x1
 *   @0x2acb58 add.w r1, r1, r5, lsl #8
 *   @0x2acb5c adds r5, r0, #0x2
 *   @0x2acb60 ldr r3, [sp, #0xc]
 *   @0x2acb64 blt 0x2acb2e <png_handle_sPLT+0x142>
 *   @0x2acb68 ldrb.w lr, [r5, #0x1]
 *   @0x2acb6c add.w r6, lr, r6, lsl #8
 *   @0x2acb70 strh r6, [r0, r1]
 *   @0x2acb74 ldrb r1, [r5, #0x3]
 *   @0x2acb78 subshi r2, r9, r0, lsl #2
 *   @0x2acb7c ldrb r0, [r5, #0x4]
 *   @0x2acb80 add.w r1, r1, r0, lsl #8
 *   @0x2acb84 strh r1, [r3, #0x4]
 *   @0x2acb88 ldrb r1, [r5, #0x7]
 *   @0x2acb8c .word 0xf1052100
 *   @0x2acb90 sbcshi r0, r9, r8
 *   @0x2acb94 b 0x2acb52 <png_handle_sPLT+0x166>
 *   @0x2acb98 bge 0x3b9860 <error_g0017+0x12504>
 *   @0x2acb9c mov r0, r4
 *   @0x2acba0 str r3, [r2, #-16]!
 *   @0x2acba4 movs r3, #0x1
 *   @0x2acba8 bl 0x2af20c <png_set_sPLT>
 *   @0x2acbac mov r0, r4
 *   @0x2acbb0 .word 0xf7fa1330
 *   @0x2acbb4 movwhs pc, #0x8a3
 *   @0x2acbb8 mov r0, r4
 *   @0x2acbbc stmdbls r2, {r4, r5, r8, r9, r12, sp}
 *   @0x2acbc0 bl 0x2a6cfc <png_free>
 *   @0x2acbc4 add sp, #0x14
 *   @0x2acbc8 svclt #0x8ff0
 *   @0x2acbcc ldr r1, [sp, #0x264]
 *   @0x2acbd0 lsls r3, r5, #0x1e
 *   @0x2acbd4 lsls r0, r6, #0x1e
 *   @0x2acbd8 lsls r1, r7, #0x1e
 *   @0x2acbdc lsls r7, r2, #0x1d
 *   @0x2acbe0 lsls r6, r5, #0x1c
 *   @0x2acbe4 lsls r6, r5, #0x1c
 *   @0x2acbe8 lsls r0, r5, #0x1c
 *
 * ══ §13/60 b2PolygonShape::ComputeMass(b2MassData*, float) const  0x2c5990  size 512  128 条（0x2c5990..0x2c5b90）
 * @func 0x2c5990 0x2c5b90  size 512  128 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PolygonShape::ComputeMass(b2MassData*, float) const+0x1b0
 * 字段偏移 top8: 0x94×2 / 0x1e0×1 / 0x1d0×1 / 0xa4×1
 * VFP 指令 83 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5990 push {r4, r5, r6, lr}
 *   @0x2c5994 vpush {d8, d9, d10, d11}
 *   @0x2c5998 mov r6, r0
 *   @0x2c599c ldr r5, [pc, #0x1e0]
 *   @0x2c59a0 mov r4, r1
 *   @0x2c59a4 ldr r0, [r0, #0x94]
 *   @0x2c59a8 vmov s21, r2
 *   @0x2c59ac ldr r5, [pc, r5]
 *   @0x2c59b0 ldr r1, [pc, #0x1d0]
 *   @0x2c59b4 cmp r0, #2
 *   @0x2c59b8 add r1, pc, r1
 *   @0x2c59bc ldr r3, [r5]
 *   @0x2c59c0 movle r0, #0
 *   @0x2c59c4 movgt r0, #1
 *   @0x2c59c8 blx r3
 *   @0x2c59cc ldr r12, [r6, #0x94]
 *   @0x2c59d0 cmp r12, #0
 *   @0x2c59d4 ble 0x2c5b40 <_ZNK14b2PolygonShape11ComputeMassEP10b2MassDataf+0x1b0>
 *   @0x2c59d8 vldr s15, [pc, #404]
 *   @0x2c59dc vmov.f32 s14, s15
 *   @0x2c59e0 add r3, r6, #20
 *   @0x2c59e4 mov r2, #0
 *   @0x2c59e8 add r2, r2, #1
 *   @0x2c59ec vldr s13, [r3]
 *   @0x2c59f0 cmp r2, r12
 *   @0x2c59f4 vadd.f32 s15, s15, s13
 *   @0x2c59f8 add r3, r3, #8
 *   @0x2c59fc vldr s13, [r3, #-4]
 *   @0x2c5a00 vadd.f32 s14, s14, s13
 *   @0x2c5a04 bne 0x2c59e8 <_ZNK14b2PolygonShape11ComputeMassEP10b2MassDataf+0x58>
 *   @0x2c5a08 vmov.f32 s22, #1.000000e+00
 *   @0x2c5a0c vldr s16, [pc, #352]
 *   @0x2c5a10 vmov s12, r12
 *   @0x2c5a14 add r3, r6, #28
 *   @0x2c5a18 mov r2, #0
 *   @0x2c5a1c vldr s4, [pc, #340]
 *   @0x2c5a20 vldr s5, [pc, #340]
 *   @0x2c5a24 vcvt.f32.s32 s13, s12
 *   @0x2c5a28 vdiv.f32 s22, s22, s13
 *   @0x2c5a2c vmul.f32 s18, s22, s15
 *   @0x2c5a30 vmul.f32 s22, s22, s14
 *   @0x2c5a34 vmov.f32 s6, #5.000000e-01
 *   @0x2c5a38 vmov.f32 s20, s16
 *   @0x2c5a3c vmov.f32 s19, s16
 *   @0x2c5a40 vmov.f32 s17, s16
 *   @0x2c5a44 add r2, r2, #1
 *   @0x2c5a48 vldr s12, [r3, #-8]
 *   @0x2c5a4c cmp r2, r12
 *   @0x2c5a50 vldr s14, [r3, #-4]
 *   @0x2c5a54 vsub.f32 s12, s12, s18
 *   @0x2c5a58 vldrlt s13, [r3]
 *   @0x2c5a5c vldrlt s15, [r3, #4]
 *   @0x2c5a60 vldrge s13, [r6, #20]
 *   @0x2c5a64 vldrge s15, [r6, #24]
 *   @0x2c5a68 cmp r2, r12
 *   @0x2c5a6c add r3, r3, #8
 *   @0x2c5a70 vsub.f32 s14, s14, s22
 *   @0x2c5a74 vsub.f32 s13, s13, s18
 *   @0x2c5a78 vsub.f32 s15, s15, s22
 *   @0x2c5a7c vmul.f32 s10, s12, s13
 *   @0x2c5a80 vmul.f32 s11, s14, s15
 *   @0x2c5a84 vmul.f32 s9, s14, s13
 *   @0x2c5a88 vmla.f32 s10, s12, s12
 *   @0x2c5a8c vmla.f32 s11, s14, s14
 *   @0x2c5a90 vnmls.f32 s9, s12, s15
 *   @0x2c5a94 vmla.f32 s10, s13, s13
 *   @0x2c5a98 vmla.f32 s11, s15, s15
 *   @0x2c5a9c vmul.f32 s7, s9, s6
 *   @0x2c5aa0 vmul.f32 s9, s9, s5
 *   @0x2c5aa4 vmul.f32 s8, s7, s4
 *   @0x2c5aa8 vadd.f32 s11, s10, s11
 *   @0x2c5aac vadd.f32 s13, s12, s13
 *   @0x2c5ab0 vadd.f32 s15, s14, s15
 *   @0x2c5ab4 vmla.f32 s19, s9, s11
 *   @0x2c5ab8 vadd.f32 s17, s17, s7
 *   @0x2c5abc vmla.f32 s16, s8, s13
 *   @0x2c5ac0 vmla.f32 s20, s8, s15
 *   @0x2c5ac4 bne 0x2c5a44 <_ZNK14b2PolygonShape11ComputeMassEP10b2MassDataf+0xb4>
 *   @0x2c5ac8 vldr s15, [pc, #176]
 *   @0x2c5acc vcmpe.f32 s17, s15
 *   @0x2c5ad0 vmrs APSR_nzcv, fpscr
 *   @0x2c5ad4 movle r0, #0
 *   @0x2c5ad8 movgt r0, #1
 *   @0x2c5adc vmul.f32 s15, s21, s17
 *   @0x2c5ae0 ldr r1, [pc, #0xa4]
 *   @0x2c5ae4 ldr r3, [r5]
 *   @0x2c5ae8 add r1, pc, r1
 *   @0x2c5aec vstr s15, [r4]
 *   @0x2c5af0 blx r3
 *   @0x2c5af4 vmov.f32 s15, #1.000000e+00
 *   @0x2c5af8 vldr s14, [r4]
 *   @0x2c5afc vdiv.f32 s17, s15, s17
 *   @0x2c5b00 vmul.f32 s20, s17, s20
 *   @0x2c5b04 vmul.f32 s16, s17, s16
 *   @0x2c5b08 vadd.f32 s22, s22, s20
 *   @0x2c5b0c vmul.f32 s20, s20, s20
 *   @0x2c5b10 vstr s22, [r4, #8]
 *   @0x2c5b14 vmul.f32 s22, s22, s22
 *   @0x2c5b18 vadd.f32 s18, s18, s16
 *   @0x2c5b1c vmla.f32 s20, s16, s16
 *   @0x2c5b20 vstr s18, [r4, #4]
 *   @0x2c5b24 vmla.f32 s22, s18, s18
 *   @0x2c5b28 vsub.f32 s15, s22, s20
 *   @0x2c5b2c vmul.f32 s15, s15, s14
 *   @0x2c5b30 vmla.f32 s15, s21, s19
 *   @0x2c5b34 vpop {d8, d9, d10, d11}
 *   @0x2c5b38 vstr s15, [r4, #12]
 *   @0x2c5b3c pop {r4, r5, r6, pc}
 *   @0x2c5b40 vmov.f32 s18, #1.000000e+00
 *   @0x2c5b44 vldr s15, [pc, #40]
 *   @0x2c5b48 vmov s13, r12
 *   @0x2c5b4c mov r0, #0
 *   @0x2c5b50 vcvt.f32.s32 s14, s13
 *   @0x2c5b54 vdiv.f32 s18, s18, s14
 *   @0x2c5b58 vmul.f32 s18, s18, s15
 *   @0x2c5b5c vmov.f32 s16, s15
 *   @0x2c5b60 vmov.f32 s20, s15
 *   @0x2c5b64 vmov.f32 s19, s15
 *   @0x2c5b68 vmov.f32 s17, s15
 *   @0x2c5b6c vmov.f32 s22, s18
 *   @0x2c5b70 b 0x2c5adc <_ZNK14b2PolygonShape11ComputeMassEP10b2MassDataf+0x14c>
 *   @0x2c5b74 andeq r0, r0, r0
 *   @0x2c5b78 .word 0x3eaaaaab
 *   @0x2c5b7c .word 0x3daaaaab
 *   @0x2c5b80 strlo r0, [r0], #-0
 *   @0x2c5b84 andseq r11, r2, r12, lsl r11
 *   @0x2c5b88 andeq r7, r9, r4, lsl #14
 *   @0x2c5b8c andeq r7, r9, r8, lsl #12
 *
 * ══ §14/60 FT_Outline_EmboldenXY  0x2e6670  size 512  128 条（0x2e6670..0x2e6870）
 * @func 0x2e6670 0x2e6870  size 512  128 条
 * 部分覆盖: 本节 128/241 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_MulFix×3 / 0x346a4c / 0x382dcc / 0x3664b0 / 0x3b26cc / 0x4469b4 / 0x4469ac / FT_Outline_EmboldenXY+0x190
 * 字段偏移 top8: 0x4×5 / 0x3c×4 / 0x24×3 / 0x1c×3 / 0x8×2 / 0x38×2 / 0x18×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6670 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e6674 sub sp, #0x44
 *   @0x2e6678 cmp r0, #0x0
 *   @0x2e667c bl 0x346a4c
 *   @0x2e6680 bl 0x382dcc <_ZTS13C_UTF16String+0x19e78>
 *   @0x2e6684 ldrdne r7, r8, [r9], #-34
 *   @0x2e6688 asr.w r2, r2, #0x1
 *   @0x2e668c str r1, [sp, #0x24]
 *   @0x2e6690 bne 0x2e6698 <FT_Outline_EmboldenXY+0x28>
 *   @0x2e6694 movs r0, #0x0
 *   @0x2e6698 ldr r0, [sp, #0x4]
 *   @0x2e669c blls 0x3664b0 <_ZTS12CDS_Priority+0x8508>
 *   @0x2e66a0 cmp r0, #0x2
 *   @0x2e66a4 bne 0x2e66b4 <FT_Outline_EmboldenXY+0x44>
 *   @0x2e66a8 .word 0x28000000
 *   @0x2e66ac ite ne
 *   @0x2e66b0 moveq r0, #0x0
 *   @0x2e66b4 ldr r6, [r3, #0x4]
 *   @0x2e66b8 str r3, [sp, #0x8]
 *   @0x2e66bc add r3, sp, #0x38
 *   @0x2e66c0 ldr r2, [sp, #0x4]
 *   @0x2e66c4 bls 0x3b26cc <error_g0017+0xb370>
 *   @0x2e66c8 cmp r2, r3
 *   @0x2e66cc ldr r2, [sp, #0x4]
 *   @0x2e66d0 stcls p9, c0, [r2, #-0]
 *   @0x2e66d4 mov r7, r9
 *   @0x2e66d8 mov r8, r9
 *   @0x2e66dc ldr r2, [sp, #0xc]
 *   @0x2e66e0 .word 0xf8cd9030
 *   @0x2e66e4 rfedb r3!
 *   @0x2e66e8 movwls r3, #0x7012
 *   @0x2e66ec mov r4, r3
 *   @0x2e66f0 movwls r3, #0x53ff
 *   @0x2e66f4 cmp r5, r4
 *   @0x2e66f8 blls 0x4469b4 <g_RomDisk+0x4f194>
 *   @0x2e66fc cmp r4, r3
 *   @0x2e6700 blls 0x4469ac <g_RomDisk+0x4f18c>
 *   @0x2e6704 cmp r5, r3
 *   @0x2e6708 ldr.w r2, [r6, r5, lsl #3]
 *   @0x2e670c add.w r0, r6, r5, lsl #3
 *   @0x2e6710 ldr.w r3, [r6, r4, lsl #3]
 *   @0x2e6714 add.w r1, r6, r4, lsl #3
 *   @0x2e6718 subs r3, r2, r3
 *   @0x2e671c str r3, [sp, #0x38]
 *   @0x2e6720 ldr r3, [r1, #0x4]
 *   @0x2e6724 str r3, [sp, #0x3c]
 *   @0x2e6728 strhls pc, [r4], -r6
 *   @0x2e672c cmp r0, #0x0
 *   @0x2e6730 and r8, r5, r11, lsl #1
 *   @0x2e6734 ldr r3, [sp, #0x30]
 *   @0x2e6738 movwls r9, #0xe03c
 *   @0x2e673c ldr r3, [sp, #0x2c]
 *   @0x2e6740 cmp.w r8, #0x0
 *   @0x2e6744 beq 0x2e683c <FT_Outline_EmboldenXY+0x1cc>
 *   @0x2e6748 cmp r3, #0x0
 *   @0x2e674c mov r9, r7
 *   @0x2e6750 strls r11, [r5], #-48
 *   @0x2e6754 str.w r8, [sp, #0x2c]
 *   @0x2e6758 ldr r1, [sp, #0x38]
 *   @0x2e675c bl 0x2e4e4c <FT_MulFix>
 *   @0x2e6760 ldr r1, [sp, #0x3c]
 *   @0x2e6764 mov r0, r7
 *   @0x2e6768 bmi 0x1325534 <b2_toiTime+0xbcc090>
 *   @0x2e676c add r0, r10
 *   @0x2e6770 blt 0x2e6800 <FT_Outline_EmboldenXY+0x190>
 *   @0x2e6774 stmdals lr, {r7, r9, r11, r12, sp}
 *   @0x2e6778 ldr r3, [sp, #0x3c]
 *   @0x2e677c andls r0, r8, #0, #4
 *   @0x2e6780 ldr r2, [sp, #0x28]
 *   @0x2e6784 cbnz r2, 0x2e678a <FT_Outline_EmboldenXY+0x11a>
 *   @0x2e6788 b 0x2e6790 <FT_Outline_EmboldenXY+0x120>
 *   @0x2e678c rsbs r2, r2, #0
 *   @0x2e6790 mov r1, r7
 *   @0x2e6794 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e6798 mov r1, r11
 *   @0x2e679c ldr r0, [sp, #0x3c]
 *   @0x2e67a0 bls 0x5a54fc <g_SWFlineaavertbuff+0x52434>
 *   @0x2e67a4 ldr r3, [sp]
 *   @0x2e67a8 cbnz r2, 0x2e67ac <FT_Outline_EmboldenXY+0x13c>
 *   @0x2e67ac ldr r2, [sp, #0x10]
 *   @0x2e67b0 ldr r0, [sp, #0x24]
 *   @0x2e67b4 it lt
 *   @0x2e67b8 str r3, [sp]
 *   @0x2e67bc ldrbmi pc, [r1], -r7, asr #22
 *   @0x2e67c0 mov r11, r0
 *   @0x2e67c4 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e67c8 ldr r3, [sp]
 *   @0x2e67cc mov r0, r3
 *   @0x2e67d0 ldrle r1, [sp, #0x24]
 *   @0x2e67d4 movle r2, r10
 *   @0x2e67d8 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e67dc mov r1, r7
 *   @0x2e67e0 ldr r0, [sp, #0x18]
 *   @0x2e67e4 uasxmi pc, r1, r3
 *   @0x2e67e8 mov r3, r0
 *   @0x2e67ec str r3, [sp]
 *   @0x2e67f0 blls 0x3254ac
 *   @0x2e67f4 cmp r3, r0
 *   @0x2e67f8 bgt 0x2e680e <FT_Outline_EmboldenXY+0x19e>
 *   @0x2e67fc mov r2, r10
 *   @0x2e6800 movs r0, #0x0
 *   @0x2e6804 ldr r3, [sp, #0x24]
 *   @0x2e6808 ldr r3, [sp, #0x18]
 *   @0x2e680c b 0x2e6818 <FT_Outline_EmboldenXY+0x1a8>
 *   @0x2e6810 mov r2, r7
 *   @0x2e6814 .word 0xe7f5fa93
 *   @0x2e6818 add.w r3, r6, r4, lsl #3
 *   @0x2e681c ldr.w r2, [r6, r4, lsl #3]
 *   @0x2e6820 add r2, r11
 *   @0x2e6824 ldmdavs r10, {r2, r4, r5, sp} ^
 *   @0x2e6828 add r2, r0
 *   @0x2e682c ldr r3, [sp, #0x1c]
 *   @0x2e6830 ite lt
 *   @0x2e6834 ldrge r4, [sp, #0x8]
 *   @0x2e6838 bne 0x2e6818 <FT_Outline_EmboldenXY+0x1a8>
 *   @0x2e683c mov r4, r5
 *   @0x2e6840 svcls #0xfb038
 *   @0x2e6844 ldr.w r8, [sp, #0x10]
 *   @0x2e6848 ldr r3, [sp, #0x1c]
 *   @0x2e684c ite lt
 *   @0x2e6850 ldrge r5, [sp, #0x8]
 *   @0x2e6854 ldr r3, [sp, #0x1c]
 *   @0x2e6858 str r3, [sp, #0x8]
 *   @0x2e685c adds r3, #0x1
 *   @0x2e6860 b 0x2e66c0 <FT_Outline_EmboldenXY+0x50>
 *   @0x2e6864 add sp, #0x44
 *   @0x2e6868 svclt #0x8ff0
 *   @0x2e686c asrs r1, r0, #0x20
 *
 * ══ §15/60 Font_AddSprite(int, int, bool, int)  0xfa5ac  size 508  127 条（0xfa5ac..0xfa7a8）
 * @func 0xfa5ac 0xfa7a8  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xfa5d8→0x483688, 0xfa5dc→0x483680, 0xfa608→0x483684, 0xfa64c→0x48367c, 0xfa74c→0x483684
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / Sprite_Data(int) / Font_AddSprite(int, int, bool, int)+0x1d0 / utf8_add_char / operator new(unsigned int) / CFontGM::CFontGM(int, char const*, bool, int) / 0xb65c8 / YYStrDup(char const*)
 * 字段偏移 top8: 0x-130×4 / 0x-134×3 / 0x-13c×3 / 0x-140×2 / 0x-144×2 / 0x1b0×2 / 0x-138×2 / 0x-28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa5ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfa5b0 add r11, sp, #32
 *   @0xfa5b4 ldr r10, [pc, #0x1cc]
 *   @0xfa5b8 sub sp, sp, #300
 *   @0xfa5bc str r0, [r11, #-0x134]
 *   @0xfa5c0 ldr r0, [pc, #0x1c4]
 *   @0xfa5c4 add r10, pc, r10
 *   @0xfa5c8 str r2, [r11, #-0x140]
 *   @0xfa5cc mov r4, r1
 *   @0xfa5d0 str r3, [r11, #-0x144]
 *   @0xfa5d4 ldr r0, [r10, r0]
 *   @0xfa5d8 ldr r1, [pc, #0x1b0]
 *   @0xfa5dc ldr r2, [pc, #0x1b0]
 *   @0xfa5e0 ldr r3, [r0]
 *   @0xfa5e4 str r0, [r11, #-0x138]
 *   @0xfa5e8 str r3, [r11, #-0x28]
 *   @0xfa5ec ldr r1, [r10, r1]
 *   @0xfa5f0 str r1, [r11, #-0x130]
 *   @0xfa5f4 ldr r6, [r10, r2]
 *   @0xfa5f8 ldr r2, [r1]
 *   @0xfa5fc ldr r3, [r6]
 *   @0xfa600 cmp r2, r3
 *   @0xfa604 beq 0xfa724 <_Z14Font_AddSpriteiibi+0x178>
 *   @0xfa608 ldr r2, [pc, #0x188]
 *   @0xfa60c ldr r2, [r10, r2]
 *   @0xfa610 str r2, [r11, #-0x13c]
 *   @0xfa614 ldr r0, [r11, #-0x134]
 *   @0xfa618 add r3, r3, #1
 *   @0xfa61c str r3, [r6]
 *   @0xfa620 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0xfa624 ldr r2, [r0, #0x18]
 *   @0xfa628 mov r8, r0
 *   @0xfa62c cmp r2, #0
 *   @0xfa630 lsl r2, r2, #2
 *   @0xfa634 add r2, r2, #18
 *   @0xfa638 bic r2, r2, #7
 *   @0xfa63c sub sp, sp, r2
 *   @0xfa640 add r7, sp, #8
 *   @0xfa644 str r7, [r11, #-0x12c]
 *   @0xfa648 ble 0xfa77c <_Z14Font_AddSpriteiibi+0x1d0>
 *   @0xfa64c ldr r1, [pc, #0x148]
 *   @0xfa650 sub r5, r11, #300
 *   @0xfa654 lsl r9, r4, #1
 *   @0xfa658 mov r4, #0
 *   @0xfa65c ldr r10, [r10, r1]
 *   @0xfa660 ldr r3, [r10]
 *   @0xfa664 mov r0, r5
 *   @0xfa668 add r4, r4, #1
 *   @0xfa66c ldrh r1, [r3, r9]
 *   @0xfa670 add r9, r9, #2
 *   @0xfa674 bl 0x10fe28 <utf8_add_char>
 *   @0xfa678 ldr r3, [r8, #0x18]
 *   @0xfa67c cmp r3, r4
 *   @0xfa680 bgt 0xfa660 <_Z14Font_AddSpriteiibi+0xb4>
 *   @0xfa684 ldr r2, [r11, #-0x12c]
 *   @0xfa688 mov r3, #0
 *   @0xfa68c mov r0, #144
 *   @0xfa690 strb r3, [r2]
 *   @0xfa694 sub r5, r11, #296
 *   @0xfa698 bl 0x27c524 <_Znwj>
 *   @0xfa69c ldr r12, [r11, #-0x144]
 *   @0xfa6a0 ldr r1, [r11, #-0x134]
 *   @0xfa6a4 mov r2, r7
 *   @0xfa6a8 ldr r3, [r11, #-0x140]
 *   @0xfa6ac str r12, [sp]
 *   @0xfa6b0 mov r4, r0
 *   @0xfa6b4 bl 0xf7270 <_ZN7CFontGMC2EiPKcbi>
 *   @0xfa6b8 ldr r0, [r11, #-0x130]
 *   @0xfa6bc mov r1, #256
 *   @0xfa6c0 ldr r3, [r6]
 *   @0xfa6c4 ldr r2, [pc, #0xd4]
 *   @0xfa6c8 ldr r12, [r0, #0x4]
 *   @0xfa6cc sub lr, r3, #-1073741823
 *   @0xfa6d0 add r2, pc, r2
 *   @0xfa6d4 mov r0, r5
 *   @0xfa6d8 sub r3, r3, #1
 *   @0xfa6dc str r4, [r12, lr, lsl #2]
 *   @0xfa6e0 bl 0xb65c8 <snprintf@plt>
 *   @0xfa6e4 ldr r12, [r11, #-0x13c]
 *   @0xfa6e8 ldr r3, [r6]
 *   @0xfa6ec mov r0, r5
 *   @0xfa6f0 ldr r4, [r12]
 *   @0xfa6f4 sub r5, r3, #-1073741823
 *   @0xfa6f8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xfa6fc ldr r12, [r11, #-0x138]
 *   @0xfa700 ldr r3, [r6]
 *   @0xfa704 ldr r2, [r11, #-0x28]
 *   @0xfa708 str r0, [r4, r5, lsl #2]
 *   @0xfa70c sub r0, r3, #1
 *   @0xfa710 ldr r3, [r12]
 *   @0xfa714 cmp r2, r3
 *   @0xfa718 bne 0xfa784 <_Z14Font_AddSpriteiibi+0x1d8>
 *   @0xfa71c sub sp, r11, #32
 *   @0xfa720 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfa724 ldr r5, [pc, #0x78]
 *   @0xfa728 add r1, r2, #5
 *   @0xfa72c ldr r12, [r11, #-0x130]
 *   @0xfa730 movw r3, #0x121
 *   @0xfa734 add r5, pc, r5
 *   @0xfa738 lsl r1, r1, #2
 *   @0xfa73c add r0, r12, #4
 *   @0xfa740 mov r2, r5
 *   @0xfa744 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfa748 ldr r12, [r11, #-0x130]
 *   @0xfa74c ldr r0, [pc, #0x44]
 *   @0xfa750 movw r3, #0x123
 *   @0xfa754 ldr r1, [r6]
 *   @0xfa758 mov r2, r5
 *   @0xfa75c add r1, r1, #5
 *   @0xfa760 str r1, [r12]
 *   @0xfa764 ldr r0, [r10, r0]
 *   @0xfa768 lsl r1, r1, #2
 *   @0xfa76c str r0, [r11, #-0x13c]
 *   @0xfa770 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfa774 ldr r3, [r6]
 *   @0xfa778 b 0xfa614 <_Z14Font_AddSpriteiibi+0x68>
 *   @0xfa77c mov r2, r7
 *   @0xfa780 b 0xfa688 <_Z14Font_AddSpriteiibi+0xdc>
 *   @0xfa784 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xfa788 eoreq r7, pc, r12, lsl #13
 *   @0xfa78c .word 0xffffbd00
 *   @0xfa790 .word 0xffffc20c
 *   @0xfa794 .word 0xffffc210
 *   @0xfa798 .word 0xffffc214
 *   @0xfa79c .word 0xffffc218
 *   @0xfa7a0 eoreq sp, r3, r0, asr #9
 *   @0xfa7a4 eoreq sp, r3, r8, lsr #8
 *
 * ══ §16/60 F_D3DLightDefineDirection(RValue&, CInstance*, CInstance*, int, RValue*)  0x146fa8  size 508  127 条（0x146fa8..0x1471a4）
 * @func 0x146fa8 0x1471a4  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x147030→0x4849c4, 0x147034→0x484884, 0x147050→0x484944, 0x147108→0x4848c4
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int)×2 / 0xb6700 / 0xfe167390
 * 字段偏移 top8: 0x38×2 / 0x158×2 / 0x1cc×1 / 0x140×1 / 0x8c×1 / 0x2×1 / 0x40×1
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146fa8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x146fac vpush {d8, d9}
 *   @0x146fb0 sub sp, sp, #4
 *   @0x146fb4 mov r1, #0
 *   @0x146fb8 ldr r5, [pc, #0x1cc]
 *   @0x146fbc ldr r6, [sp, #0x38]
 *   @0x146fc0 add r5, pc, r5
 *   @0x146fc4 mov r0, r6
 *   @0x146fc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x146fcc cmp r0, #7
 *   @0x146fd0 mov r4, r0
 *   @0x146fd4 bhi 0x147158 <_Z25F_D3DLightDefineDirectionR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x146fd8 mov r1, #1
 *   @0x146fdc mov r0, r6
 *   @0x146fe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146fe4 mov r1, #2
 *   @0x146fe8 vmov s19, r0
 *   @0x146fec mov r0, r6
 *   @0x146ff0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146ff4 mov r1, #3
 *   @0x146ff8 vmov s18, r0
 *   @0x146ffc mov r0, r6
 *   @0x147000 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x147004 vmul.f32 s15, s18, s18
 *   @0x147008 vmla.f32 s15, s19, s19
 *   @0x14700c vmov s17, r0
 *   @0x147010 vmla.f32 s15, s17, s17
 *   @0x147014 vsqrt.f32 s14, s15
 *   @0x147018 vcmp.f32 s14, s14
 *   @0x14701c vmrs APSR_nzcv, fpscr
 *   @0x147020 bne 0x147174 <_Z25F_D3DLightDefineDirectionR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x147024 vmov.f32 s16, #1.000000e+00
 *   @0x147028 mov r0, r6
 *   @0x14702c mov r1, #4
 *   @0x147030 ldr r7, [pc, #0x158]
 *   @0x147034 ldr r9, [pc, #0x158]
 *   @0x147038 vdiv.f32 s14, s16, s14
 *   @0x14703c vmul.f32 s19, s19, s14
 *   @0x147040 vmul.f32 s18, s18, s14
 *   @0x147044 vmul.f32 s17, s17, s14
 *   @0x147048 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14704c vldr s15, [pc, #304]
 *   @0x147050 ldr r1, [pc, #0x140]
 *   @0x147054 ldr r10, [r5, r7]
 *   @0x147058 lsl r7, r4, #4
 *   @0x14705c add r8, r10, r7
 *   @0x147060 vneg.f32 s10, s18
 *   @0x147064 vneg.f32 s11, s17
 *   @0x147068 orr r3, r0, #-16777216
 *   @0x14706c uxtb r0, r0
 *   @0x147070 ubfx r2, r3, #0x8, #0x8
 *   @0x147074 vmov s12, r0
 *   @0x147078 vmov s13, r2
 *   @0x14707c ubfx r2, r3, #0x10, #0x8
 *   @0x147080 vcvt.f32.s32 s12, s12
 *   @0x147084 vmov s14, r2
 *   @0x147088 lsl r2, r4, #2
 *   @0x14708c add r6, r2, #1
 *   @0x147090 add r12, r2, #2
 *   @0x147094 add r2, r2, #3
 *   @0x147098 lsl r6, r6, #2
 *   @0x14709c lsl r12, r12, #2
 *   @0x1470a0 lsl r2, r2, #2
 *   @0x1470a4 add r0, r10, r6
 *   @0x1470a8 add r11, r10, r12
 *   @0x1470ac add r10, r10, r2
 *   @0x1470b0 vcvt.f32.s32 s13, s13
 *   @0x1470b4 vcvt.f32.s32 s14, s14
 *   @0x1470b8 vmul.f32 s12, s12, s15
 *   @0x1470bc vmul.f32 s13, s13, s15
 *   @0x1470c0 vmul.f32 s14, s14, s15
 *   @0x1470c4 vneg.f32 s15, s19
 *   @0x1470c8 vstr s15, [r8]
 *   @0x1470cc vstr s10, [r0]
 *   @0x1470d0 vstr s11, [r11]
 *   @0x1470d4 vstr s16, [r10]
 *   @0x1470d8 ldr r1, [r5, r1]
 *   @0x1470dc vldr s15, [pc, #164]
 *   @0x1470e0 mov r8, #0
 *   @0x1470e4 mov r0, r4
 *   @0x1470e8 add r10, r1, r2
 *   @0x1470ec vstr s15, [r10]
 *   @0x1470f0 add r10, r1, r12
 *   @0x1470f4 vstr s15, [r10]
 *   @0x1470f8 add r10, r1, r6
 *   @0x1470fc add r1, r1, r7
 *   @0x147100 vstr s15, [r10]
 *   @0x147104 vstr s15, [r1]
 *   @0x147108 ldr r1, [pc, #0x8c]
 *   @0x14710c ldr r10, [r5, r1]
 *   @0x147110 vmov r1, s19
 *   @0x147114 add r12, r10, r12
 *   @0x147118 add r2, r10, r2
 *   @0x14711c add r7, r10, r7
 *   @0x147120 add r6, r10, r6
 *   @0x147124 vstr s12, [r7]
 *   @0x147128 vstr s13, [r6]
 *   @0x14712c vstr s14, [r12]
 *   @0x147130 vstr s16, [r2]
 *   @0x147134 vmov r2, s18
 *   @0x147138 ldr r12, [r5, r9]
 *   @0x14713c str r3, [sp, #0x38]
 *   @0x147140 vmov r3, s17
 *   @0x147144 str r8, [r12, r4, lsl #2]
 *   @0x147148 add sp, sp, #4
 *   @0x14714c vpop {d8, d9}
 *   @0x147150 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x147154 b 0x17f658 <_Z28GR_3D_Light_Define_Directionifffj>
 *   @0x147158 ldr r0, [pc, #0x40]
 *   @0x14715c mov r1, #0
 *   @0x147160 add r0, pc, r0
 *   @0x147164 add sp, sp, #4
 *   @0x147168 vpop {d8, d9}
 *   @0x14716c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x147170 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147174 vmov r0, s15
 *   @0x147178 bl 0xb6700 <sqrtf@plt>
 *   @0x14717c vmov s14, r0
 *   @0x147180 b 0x147024 <_Z25F_D3DLightDefineDirectionR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x147184 bllo 0xfe167390 <b2_toiTime+0xfffffffffda0deec>
 *   @0x147188 andeq r0, r0, r0
 *   @0x14718c mlaeq r10, r0, r12, r10
 *   @0x147190 .word 0xffffd9dc
 *   @0x147194 .word 0xffffd9cc
 *   @0x147198 .word 0xffffd9d0
 *   @0x14719c .word 0xffffd9d8
 *   @0x1471a0 andseq r10, pc, r0, lsr #17
 *
 * ══ §17/60 C3D_Model::SaveToFile(char const*)  0x1644f8  size 508  127 条（0x1644f8..0x1646f4）
 * @func 0x1644f8 0x1646f4  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68a4×13 / 0xb6844 / C3D_Model::SaveToFile(char const*)+0x1c0 / 0xb68b0 / 0xb6850
 * 字段偏移 top8: 0x1d4×1 / 0x1c0×1 / 0x194×1 / 0x190×1 / 0x8×1 / 0x2×1
 * VFP 指令 36 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1644f8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1644fc vpush {d8, d9, d10, d11, d12}
 *   @0x164500 mov r7, r0
 *   @0x164504 mov r0, r1
 *   @0x164508 ldr r1, [pc, #0x1d4]
 *   @0x16450c add r1, pc, r1
 *   @0x164510 bl 0xb6844 <fopen@plt>
 *   @0x164514 subs r4, r0, #0
 *   @0x164518 moveq r0, r4
 *   @0x16451c beq 0x1646c4 <_ZN9C3D_Model10SaveToFileEPKc+0x1cc>
 *   @0x164520 ldr r5, [pc, #0x1c0]
 *   @0x164524 mov r2, #100
 *   @0x164528 add r5, pc, r5
 *   @0x16452c mov r1, r5
 *   @0x164530 bl 0xb68a4 <fprintf@plt>
 *   @0x164534 mov r0, r4
 *   @0x164538 mov r1, r5
 *   @0x16453c ldr r2, [r7]
 *   @0x164540 bl 0xb68a4 <fprintf@plt>
 *   @0x164544 ldr r3, [r7]
 *   @0x164548 cmp r3, #0
 *   @0x16454c ble 0x1646b8 <_ZN9C3D_Model10SaveToFileEPKc+0x1c0>
 *   @0x164550 ldr r8, [pc, #0x194]
 *   @0x164554 mov r6, #0
 *   @0x164558 ldr r5, [pc, #0x190]
 *   @0x16455c add r8, pc, r8
 *   @0x164560 add r5, pc, r5
 *   @0x164564 ldr r3, [r7, #0x8]
 *   @0x164568 ldr r3, [r3, r6, lsl #2]
 *   @0x16456c vldr s25, [r3, #4]
 *   @0x164570 vldr s24, [r3, #8]
 *   @0x164574 vldr s23, [r3, #12]
 *   @0x164578 vldr s19, [r3, #16]
 *   @0x16457c vldr s22, [r3, #20]
 *   @0x164580 ldr r2, [r3]
 *   @0x164584 vldr s18, [r3, #24]
 *   @0x164588 vldr s17, [r3, #28]
 *   @0x16458c vldr s21, [r3, #32]
 *   @0x164590 sub r12, r2, #3
 *   @0x164594 vldr s16, [r3, #36]
 *   @0x164598 vldr s20, [r3, #40]
 *   @0x16459c cmp r12, #6
 *   @0x1645a0 addls pc, pc, r12, lsl #2
 *   @0x1645a4 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0>
 *   @0x1645a8 b 0x1646cc <_ZN9C3D_Model10SaveToFileEPKc+0x1d4>
 *   @0x1645ac b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0>
 *   @0x1645b0 b 0x1646dc <_ZN9C3D_Model10SaveToFileEPKc+0x1e4>
 *   @0x1645b4 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0>
 *   @0x1645b8 b 0x1646d4 <_ZN9C3D_Model10SaveToFileEPKc+0x1dc>
 *   @0x1645bc b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0>
 *   @0x1645c0 b 0x1645c4 <_ZN9C3D_Model10SaveToFileEPKc+0xcc>
 *   @0x1645c4 vcvt.f32.s32 s16, s16
 *   @0x1645c8 mov r1, r8
 *   @0x1645cc mov r0, r4
 *   @0x1645d0 bl 0xb68a4 <fprintf@plt>
 *   @0x1645d4 mov r1, r5
 *   @0x1645d8 mov r0, r4
 *   @0x1645dc add r6, r6, #1
 *   @0x1645e0 vcvt.f64.f32 d7, s25
 *   @0x1645e4 vmov r2, r3, d7
 *   @0x1645e8 bl 0xb68a4 <fprintf@plt>
 *   @0x1645ec mov r1, r5
 *   @0x1645f0 vcvt.f64.f32 d7, s24
 *   @0x1645f4 mov r0, r4
 *   @0x1645f8 vmov r2, r3, d7
 *   @0x1645fc bl 0xb68a4 <fprintf@plt>
 *   @0x164600 mov r1, r5
 *   @0x164604 vcvt.f64.f32 d7, s23
 *   @0x164608 mov r0, r4
 *   @0x16460c vmov r2, r3, d7
 *   @0x164610 bl 0xb68a4 <fprintf@plt>
 *   @0x164614 mov r1, r5
 *   @0x164618 vcvt.f64.f32 d7, s19
 *   @0x16461c mov r0, r4
 *   @0x164620 vmov r2, r3, d7
 *   @0x164624 bl 0xb68a4 <fprintf@plt>
 *   @0x164628 mov r1, r5
 *   @0x16462c vcvt.f64.f32 d7, s22
 *   @0x164630 mov r0, r4
 *   @0x164634 vmov r2, r3, d7
 *   @0x164638 bl 0xb68a4 <fprintf@plt>
 *   @0x16463c mov r1, r5
 *   @0x164640 vcvt.f64.f32 d7, s18
 *   @0x164644 mov r0, r4
 *   @0x164648 vmov r2, r3, d7
 *   @0x16464c bl 0xb68a4 <fprintf@plt>
 *   @0x164650 mov r1, r5
 *   @0x164654 vcvt.f64.f32 d7, s17
 *   @0x164658 mov r0, r4
 *   @0x16465c vmov r2, r3, d7
 *   @0x164660 bl 0xb68a4 <fprintf@plt>
 *   @0x164664 mov r1, r5
 *   @0x164668 vcvt.f64.f32 d7, s21
 *   @0x16466c mov r0, r4
 *   @0x164670 vmov r2, r3, d7
 *   @0x164674 bl 0xb68a4 <fprintf@plt>
 *   @0x164678 mov r1, r5
 *   @0x16467c vcvt.f64.f32 d7, s16
 *   @0x164680 mov r0, r4
 *   @0x164684 vmov r2, r3, d7
 *   @0x164688 bl 0xb68a4 <fprintf@plt>
 *   @0x16468c mov r1, r5
 *   @0x164690 vcvt.f64.f32 d7, s20
 *   @0x164694 mov r0, r4
 *   @0x164698 vmov r2, r3, d7
 *   @0x16469c bl 0xb68a4 <fprintf@plt>
 *   @0x1646a0 mov r0, #10
 *   @0x1646a4 mov r1, r4
 *   @0x1646a8 bl 0xb68b0 <fputc@plt>
 *   @0x1646ac ldr r3, [r7]
 *   @0x1646b0 cmp r3, r6
 *   @0x1646b4 bgt 0x164564 <_ZN9C3D_Model10SaveToFileEPKc+0x6c>
 *   @0x1646b8 mov r0, r4
 *   @0x1646bc bl 0xb6850 <fclose@plt>
 *   @0x1646c0 mov r0, #1
 *   @0x1646c4 vpop {d8, d9, d10, d11, d12}
 *   @0x1646c8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1646cc vcvt.f32.s32 s19, s19
 *   @0x1646d0 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0>
 *   @0x1646d4 vcvt.f32.s32 s17, s17
 *   @0x1646d8 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0>
 *   @0x1646dc vcvt.f32.s32 s18, s18
 *   @0x1646e0 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0>
 *   @0x1646e4 andseq r11, sp, r0, ror #28
 *   @0x1646e8 andseq r6, lr, r4, asr r0
 *   @0x1646ec ldrheq sp, [r12], -r0
 *   @0x1646f0 andseq r6, lr, r0, lsr #32
 *
 * ══ §18/60 GV_Undefined(CInstance*, int, RValue*)  0x200890  size 508  127 条（0x200890..0x200a8c）
 * @func 0x200890 0x200a9c  size 524  131 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / GV_Undefined(CInstance*, int, RValue*)+0x124 / GV_Undefined(CInstance*, int, RValue*)+0x1b0 / GV_Undefined(CInstance*, int, RValue*)+0x170
 * 字段偏移 top8: 0x4×12 / 0x8×6 / 0xc×4 / 0x10×3 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200890 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x200894 mov r5, r2
 *   @0x200898 ldr r2, [r2, #0xc]
 *   @0x20089c sub r3, r2, #1
 *   @0x2008a0 bic r3, r3, #-16777216
 *   @0x2008a4 bics r4, r3, #3
 *   @0x2008a8 beq 0x2008cc <_Z12GV_UndefinedP9CInstanceiP6RValue+0x3c>
 *   @0x2008ac mov r3, #0
 *   @0x2008b0 mov r2, #5
 *   @0x2008b4 str r3, [r5, #0x8]
 *   @0x2008b8 mov r0, #1
 *   @0x2008bc str r3, [r5]
 *   @0x2008c0 str r3, [r5, #0x4]
 *   @0x2008c4 str r2, [r5, #0xc]
 *   @0x2008c8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2008cc bic r2, r2, #-16777216
 *   @0x2008d0 cmp r2, #2
 *   @0x2008d4 beq 0x200944 <_Z12GV_UndefinedP9CInstanceiP6RValue+0xb4>
 *   @0x2008d8 cmp r2, #3
 *   @0x2008dc beq 0x20091c <_Z12GV_UndefinedP9CInstanceiP6RValue+0x8c>
 *   @0x2008e0 cmp r2, #1
 *   @0x2008e4 bne 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c>
 *   @0x2008e8 ldr r4, [r5]
 *   @0x2008ec cmp r4, #0
 *   @0x2008f0 beq 0x200910 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x80>
 *   @0x2008f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2008f8 ldr r6, [r4, #0x4]
 *   @0x2008fc sub r6, r6, #1
 *   @0x200900 str r6, [r4, #0x4]
 *   @0x200904 cmp r6, #0
 *   @0x200908 beq 0x20097c <_Z12GV_UndefinedP9CInstanceiP6RValue+0xec>
 *   @0x20090c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200910 mov r3, #0
 *   @0x200914 str r3, [r5]
 *   @0x200918 b 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c>
 *   @0x20091c ldr r3, [r5, #0x8]
 *   @0x200920 tst r3, #8
 *   @0x200924 beq 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c>
 *   @0x200928 ldr r0, [r5]
 *   @0x20092c cmp r0, #0
 *   @0x200930 beq 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c>
 *   @0x200934 ldr r3, [r0]
 *   @0x200938 ldr r3, [r3, #0x4]
 *   @0x20093c blx r3
 *   @0x200940 b 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c>
 *   @0x200944 ldr r8, [r5]
 *   @0x200948 cmp r8, #0
 *   @0x20094c beq 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c>
 *   @0x200950 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200954 ldr r3, [r8]
 *   @0x200958 ldr r2, [r8, #0x8]
 *   @0x20095c sub r3, r3, #1
 *   @0x200960 str r3, [r8]
 *   @0x200964 cmp r5, r2
 *   @0x200968 streq r4, [r8, #0x8]
 *   @0x20096c cmp r3, #0
 *   @0x200970 ble 0x2009b4 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x124>
 *   @0x200974 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200978 b 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c>
 *   @0x20097c ldr r0, [r4]
 *   @0x200980 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200984 str r6, [r4]
 *   @0x200988 str r6, [r4, #0x8]
 *   @0x20098c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200990 ldr r6, [r4, #0x4]
 *   @0x200994 sub r6, r6, #1
 *   @0x200998 str r6, [r4, #0x4]
 *   @0x20099c cmp r6, #0
 *   @0x2009a0 beq 0x200a68 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1d8>
 *   @0x2009a4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2009a8 mov r0, r4
 *   @0x2009ac bl 0x27d1d0 <_ZdlPv>
 *   @0x2009b0 b 0x20090c <_Z12GV_UndefinedP9CInstanceiP6RValue+0x7c>
 *   @0x2009b4 ldr r3, [r8, #0x10]
 *   @0x2009b8 cmp r3, #0
 *   @0x2009bc movgt r7, #0
 *   @0x2009c0 movgt r11, #5
 *   @0x2009c4 movgt r6, r7
 *   @0x2009c8 ble 0x200a40 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1b0>
 *   @0x2009cc ldr r3, [r8, #0x4]
 *   @0x2009d0 add r9, r3, r7, lsl #3
 *   @0x2009d4 ldr r10, [r3, r7, lsl #3]
 *   @0x2009d8 ldr r4, [r9, #0x4]
 *   @0x2009dc add r10, r4, r10, lsl #4
 *   @0x2009e0 cmp r4, r10
 *   @0x2009e4 blo 0x200a00 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x170>
 *   @0x2009e8 b 0x200a60 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1d0>
 *   @0x2009ec str r6, [r4, #0x8]
 *   @0x2009f0 str r11, [r4, #0xc]
 *   @0x2009f4 str r6, [r4], #16
 *   @0x2009f8 cmp r10, r4
 *   @0x2009fc bls 0x200a24 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x194>
 *   @0x200a00 ldr r3, [r4, #0xc]
 *   @0x200a04 sub r3, r3, #1
 *   @0x200a08 bic r3, r3, #-16777216
 *   @0x200a0c bic r3, r3, #3
 *   @0x200a10 cmp r3, #0
 *   @0x200a14 bne 0x2009ec <_Z12GV_UndefinedP9CInstanceiP6RValue+0x15c>
 *   @0x200a18 mov r0, r4
 *   @0x200a1c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x200a20 b 0x2009ec <_Z12GV_UndefinedP9CInstanceiP6RValue+0x15c>
 *   @0x200a24 ldr r0, [r9, #0x4]
 *   @0x200a28 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200a2c ldr r3, [r8, #0x10]
 *   @0x200a30 add r7, r7, #1
 *   @0x200a34 str r6, [r9, #0x4]
 *   @0x200a38 cmp r7, r3
 *   @0x200a3c blt 0x2009cc <_Z12GV_UndefinedP9CInstanceiP6RValue+0x13c>
 *   @0x200a40 ldr r0, [r8, #0x4]
 *   @0x200a44 mov r4, #0
 *   @0x200a48 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200a4c str r4, [r8, #0x4]
 *   @0x200a50 mov r0, r8
 *   @0x200a54 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200a58 str r4, [r5]
 *   @0x200a5c b 0x200974 <_Z12GV_UndefinedP9CInstanceiP6RValue+0xe4>
 *   @0x200a60 mov r0, r4
 *   @0x200a64 b 0x200a28 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x198>
 *   @0x200a68 ldr r0, [r4]
 *   @0x200a6c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200a70 mov r0, r4
 *   @0x200a74 str r6, [r4]
 *   @0x200a78 str r6, [r4, #0x8]
 *   @0x200a7c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x200a80 mov r0, r4
 *   @0x200a84 bl 0x27d1d0 <_ZdlPv>
 *   @0x200a88 b 0x2009a4 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x114>
 *
 * ══ §19/60 GV_PointerInvalid(CInstance*, int, RValue*)  0x200a8c  size 508  127 条（0x200a8c..0x200c88）
 * @func 0x200a8c 0x200c88  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / GV_PointerInvalid(CInstance*, int, RValue*)+0x124 / GV_PointerInvalid(CInstance*, int, RValue*)+0x1b0 / GV_PointerInvalid(CInstance*, int, RValue*)+0x170
 * 字段偏移 top8: 0x4×11 / 0x8×6 / 0xc×4 / 0x10×3 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200a8c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x200a90 mov r5, r2
 *   @0x200a94 ldr r2, [r2, #0xc]
 *   @0x200a98 sub r3, r2, #1
 *   @0x200a9c bic r3, r3, #-16777216
 *   @0x200aa0 bics r4, r3, #3
 *   @0x200aa4 beq 0x200ac8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x3c>
 *   @0x200aa8 mov r3, #0
 *   @0x200aac mov r2, #3
 *   @0x200ab0 str r3, [r5, #0x8]
 *   @0x200ab4 mov r0, #1
 *   @0x200ab8 mvn r3, #0
 *   @0x200abc str r2, [r5, #0xc]
 *   @0x200ac0 str r3, [r5]
 *   @0x200ac4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x200ac8 bic r2, r2, #-16777216
 *   @0x200acc cmp r2, #2
 *   @0x200ad0 beq 0x200b40 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0xb4>
 *   @0x200ad4 cmp r2, #3
 *   @0x200ad8 beq 0x200b18 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x8c>
 *   @0x200adc cmp r2, #1
 *   @0x200ae0 bne 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c>
 *   @0x200ae4 ldr r4, [r5]
 *   @0x200ae8 cmp r4, #0
 *   @0x200aec beq 0x200b0c <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x80>
 *   @0x200af0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200af4 ldr r6, [r4, #0x4]
 *   @0x200af8 sub r6, r6, #1
 *   @0x200afc str r6, [r4, #0x4]
 *   @0x200b00 cmp r6, #0
 *   @0x200b04 beq 0x200b78 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0xec>
 *   @0x200b08 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200b0c mov r3, #0
 *   @0x200b10 str r3, [r5]
 *   @0x200b14 b 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c>
 *   @0x200b18 ldr r3, [r5, #0x8]
 *   @0x200b1c tst r3, #8
 *   @0x200b20 beq 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c>
 *   @0x200b24 ldr r0, [r5]
 *   @0x200b28 cmp r0, #0
 *   @0x200b2c beq 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c>
 *   @0x200b30 ldr r3, [r0]
 *   @0x200b34 ldr r3, [r3, #0x4]
 *   @0x200b38 blx r3
 *   @0x200b3c b 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c>
 *   @0x200b40 ldr r8, [r5]
 *   @0x200b44 cmp r8, #0
 *   @0x200b48 beq 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c>
 *   @0x200b4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200b50 ldr r3, [r8]
 *   @0x200b54 ldr r2, [r8, #0x8]
 *   @0x200b58 sub r3, r3, #1
 *   @0x200b5c str r3, [r8]
 *   @0x200b60 cmp r5, r2
 *   @0x200b64 streq r4, [r8, #0x8]
 *   @0x200b68 cmp r3, #0
 *   @0x200b6c ble 0x200bb0 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x124>
 *   @0x200b70 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200b74 b 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c>
 *   @0x200b78 ldr r0, [r4]
 *   @0x200b7c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200b80 str r6, [r4]
 *   @0x200b84 str r6, [r4, #0x8]
 *   @0x200b88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200b8c ldr r6, [r4, #0x4]
 *   @0x200b90 sub r6, r6, #1
 *   @0x200b94 str r6, [r4, #0x4]
 *   @0x200b98 cmp r6, #0
 *   @0x200b9c beq 0x200c64 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1d8>
 *   @0x200ba0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200ba4 mov r0, r4
 *   @0x200ba8 bl 0x27d1d0 <_ZdlPv>
 *   @0x200bac b 0x200b08 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x7c>
 *   @0x200bb0 ldr r3, [r8, #0x10]
 *   @0x200bb4 cmp r3, #0
 *   @0x200bb8 movgt r7, #0
 *   @0x200bbc movgt r11, #5
 *   @0x200bc0 movgt r6, r7
 *   @0x200bc4 ble 0x200c3c <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1b0>
 *   @0x200bc8 ldr r3, [r8, #0x4]
 *   @0x200bcc add r9, r3, r7, lsl #3
 *   @0x200bd0 ldr r10, [r3, r7, lsl #3]
 *   @0x200bd4 ldr r4, [r9, #0x4]
 *   @0x200bd8 add r10, r4, r10, lsl #4
 *   @0x200bdc cmp r4, r10
 *   @0x200be0 blo 0x200bfc <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x170>
 *   @0x200be4 b 0x200c5c <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1d0>
 *   @0x200be8 str r6, [r4, #0x8]
 *   @0x200bec str r11, [r4, #0xc]
 *   @0x200bf0 str r6, [r4], #16
 *   @0x200bf4 cmp r10, r4
 *   @0x200bf8 bls 0x200c20 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x194>
 *   @0x200bfc ldr r3, [r4, #0xc]
 *   @0x200c00 sub r3, r3, #1
 *   @0x200c04 bic r3, r3, #-16777216
 *   @0x200c08 bic r3, r3, #3
 *   @0x200c0c cmp r3, #0
 *   @0x200c10 bne 0x200be8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x15c>
 *   @0x200c14 mov r0, r4
 *   @0x200c18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x200c1c b 0x200be8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x15c>
 *   @0x200c20 ldr r0, [r9, #0x4]
 *   @0x200c24 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200c28 ldr r3, [r8, #0x10]
 *   @0x200c2c add r7, r7, #1
 *   @0x200c30 str r6, [r9, #0x4]
 *   @0x200c34 cmp r7, r3
 *   @0x200c38 blt 0x200bc8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x13c>
 *   @0x200c3c ldr r0, [r8, #0x4]
 *   @0x200c40 mov r4, #0
 *   @0x200c44 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200c48 str r4, [r8, #0x4]
 *   @0x200c4c mov r0, r8
 *   @0x200c50 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200c54 str r4, [r5]
 *   @0x200c58 b 0x200b70 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0xe4>
 *   @0x200c5c mov r0, r4
 *   @0x200c60 b 0x200c24 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x198>
 *   @0x200c64 ldr r0, [r4]
 *   @0x200c68 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200c6c mov r0, r4
 *   @0x200c70 str r6, [r4]
 *   @0x200c74 str r6, [r4, #0x8]
 *   @0x200c78 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x200c7c mov r0, r4
 *   @0x200c80 bl 0x27d1d0 <_ZdlPv>
 *   @0x200c84 b 0x200ba0 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x114>
 *
 * ══ §20/60 FreeAllDataStructures()  0x20b27c  size 508  127 条（0x20b27c..0x20b478）
 * @func 0x20b27c 0x20b478  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x20b298→0x4836ac, 0x20b2c8→0x4836b8, 0x20b438→0x3f7814, 0x20b440→0x3f5254
 * 调用序列: DS_AutoMutex::DS_AutoMutex() / FreeAllDataStructures()+0x4c / DestroyDsMap(int) / FreeAllDataStructures()+0x7c / DestroyDsList(int) / GetTheStacks(int&) / FreeAllDataStructures()+0xcc / GetTheQueues(int&)
 * 字段偏移 top8: 0x4×7 / 0x-4×4 / 0x8×2 / 0xc×2 / 0x10×2 / 0x14×2 / 0x1d4×1 / 0x1c8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20b27c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x20b280 sub sp, sp, #28
 *   @0x20b284 add r6, sp, #4
 *   @0x20b288 ldr r5, [pc, #0x1d4]
 *   @0x20b28c mov r0, r6
 *   @0x20b290 add r5, pc, r5
 *   @0x20b294 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x20b298 ldr r3, [pc, #0x1c8]
 *   @0x20b29c ldr r7, [r5, r3]
 *   @0x20b2a0 ldr r3, [r7]
 *   @0x20b2a4 cmp r3, #0
 *   @0x20b2a8 movgt r4, #0
 *   @0x20b2ac ble 0x20b2c8 <_Z21FreeAllDataStructuresv+0x4c>
 *   @0x20b2b0 mov r0, r4
 *   @0x20b2b4 add r4, r4, #1
 *   @0x20b2b8 bl 0x205334 <_Z12DestroyDsMapi>
 *   @0x20b2bc ldr r3, [r7]
 *   @0x20b2c0 cmp r3, r4
 *   @0x20b2c4 bgt 0x20b2b0 <_Z21FreeAllDataStructuresv+0x34>
 *   @0x20b2c8 ldr r3, [pc, #0x19c]
 *   @0x20b2cc ldr r7, [r5, r3]
 *   @0x20b2d0 ldr r3, [r7]
 *   @0x20b2d4 cmp r3, #0
 *   @0x20b2d8 movgt r4, #0
 *   @0x20b2dc ble 0x20b2f8 <_Z21FreeAllDataStructuresv+0x7c>
 *   @0x20b2e0 mov r0, r4
 *   @0x20b2e4 add r4, r4, #1
 *   @0x20b2e8 bl 0x205378 <_Z13DestroyDsListi>
 *   @0x20b2ec ldr r3, [r7]
 *   @0x20b2f0 cmp r3, r4
 *   @0x20b2f4 bgt 0x20b2e0 <_Z21FreeAllDataStructuresv+0x64>
 *   @0x20b2f8 add r0, sp, #8
 *   @0x20b2fc bl 0xffc9c <_Z12GetTheStacksRi>
 *   @0x20b300 ldr r2, [sp, #0x8]
 *   @0x20b304 cmp r2, #0
 *   @0x20b308 movgt r4, #0
 *   @0x20b30c movgt r8, r4
 *   @0x20b310 movgt r7, r0
 *   @0x20b314 ble 0x20b348 <_Z21FreeAllDataStructuresv+0xcc>
 *   @0x20b318 ldr r3, [r7], #4
 *   @0x20b31c add r4, r4, #1
 *   @0x20b320 cmp r3, #0
 *   @0x20b324 mov r0, r3
 *   @0x20b328 beq 0x20b340 <_Z21FreeAllDataStructuresv+0xc4>
 *   @0x20b32c ldr r3, [r3]
 *   @0x20b330 ldr r3, [r3, #0x4]
 *   @0x20b334 blx r3
 *   @0x20b338 ldr r2, [sp, #0x8]
 *   @0x20b33c str r8, [r7, #-0x4]
 *   @0x20b340 cmp r2, r4
 *   @0x20b344 bgt 0x20b318 <_Z21FreeAllDataStructuresv+0x9c>
 *   @0x20b348 add r0, sp, #12
 *   @0x20b34c bl 0xffee8 <_Z12GetTheQueuesRi>
 *   @0x20b350 ldr r2, [sp, #0xc]
 *   @0x20b354 cmp r2, #0
 *   @0x20b358 movgt r4, #0
 *   @0x20b35c movgt r8, r4
 *   @0x20b360 movgt r7, r0
 *   @0x20b364 ble 0x20b398 <_Z21FreeAllDataStructuresv+0x11c>
 *   @0x20b368 ldr r3, [r7], #4
 *   @0x20b36c add r4, r4, #1
 *   @0x20b370 cmp r3, #0
 *   @0x20b374 mov r0, r3
 *   @0x20b378 beq 0x20b390 <_Z21FreeAllDataStructuresv+0x114>
 *   @0x20b37c ldr r3, [r3]
 *   @0x20b380 ldr r3, [r3, #0x4]
 *   @0x20b384 blx r3
 *   @0x20b388 ldr r2, [sp, #0xc]
 *   @0x20b38c str r8, [r7, #-0x4]
 *   @0x20b390 cmp r2, r4
 *   @0x20b394 bgt 0x20b368 <_Z21FreeAllDataStructuresv+0xec>
 *   @0x20b398 add r0, sp, #16
 *   @0x20b39c bl 0x10026c <_Z11GetTheGridsRi>
 *   @0x20b3a0 ldr r3, [sp, #0x10]
 *   @0x20b3a4 cmp r3, #0
 *   @0x20b3a8 movgt r7, #0
 *   @0x20b3ac movgt r9, r7
 *   @0x20b3b0 movgt r8, r0
 *   @0x20b3b4 ble 0x20b3e8 <_Z21FreeAllDataStructuresv+0x16c>
 *   @0x20b3b8 ldr r4, [r8], #4
 *   @0x20b3bc add r7, r7, #1
 *   @0x20b3c0 cmp r4, #0
 *   @0x20b3c4 mov r0, r4
 *   @0x20b3c8 beq 0x20b3e0 <_Z21FreeAllDataStructuresv+0x164>
 *   @0x20b3cc bl 0x20b260 <_ZN8CDS_GridD2Ev>
 *   @0x20b3d0 mov r0, r4
 *   @0x20b3d4 bl 0x27d1d0 <_ZdlPv>
 *   @0x20b3d8 ldr r3, [sp, #0x10]
 *   @0x20b3dc str r9, [r8, #-0x4]
 *   @0x20b3e0 cmp r3, r7
 *   @0x20b3e4 bgt 0x20b3b8 <_Z21FreeAllDataStructuresv+0x13c>
 *   @0x20b3e8 add r0, sp, #20
 *   @0x20b3ec bl 0x100244 <_Z20GetThePriorityQueuesRi>
 *   @0x20b3f0 ldr r2, [sp, #0x14]
 *   @0x20b3f4 cmp r2, #0
 *   @0x20b3f8 movgt r4, #0
 *   @0x20b3fc movgt r8, r4
 *   @0x20b400 movgt r7, r0
 *   @0x20b404 ble 0x20b438 <_Z21FreeAllDataStructuresv+0x1bc>
 *   @0x20b408 ldr r3, [r7], #4
 *   @0x20b40c add r4, r4, #1
 *   @0x20b410 cmp r3, #0
 *   @0x20b414 mov r0, r3
 *   @0x20b418 beq 0x20b430 <_Z21FreeAllDataStructuresv+0x1b4>
 *   @0x20b41c ldr r3, [r3]
 *   @0x20b420 ldr r3, [r3, #0x4]
 *   @0x20b424 blx r3
 *   @0x20b428 ldr r2, [sp, #0x14]
 *   @0x20b42c str r8, [r7, #-0x4]
 *   @0x20b430 cmp r2, r4
 *   @0x20b434 bgt 0x20b408 <_Z21FreeAllDataStructuresv+0x18c>
 *   @0x20b438 ldr r1, [pc, #0x30]
 *   @0x20b43c mvn r3, #0
 *   @0x20b440 ldr r2, [pc, #0x2c]
 *   @0x20b444 mov r0, r6
 *   @0x20b448 ldr r1, [r5, r1]
 *   @0x20b44c str r3, [r1]
 *   @0x20b450 ldr r2, [r5, r2]
 *   @0x20b454 str r3, [r2]
 *   @0x20b458 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x20b45c add sp, sp, #28
 *   @0x20b460 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x20b464 andseq r6, lr, r0, asr #19
 *   @0x20b468 .word 0xffffc028
 *   @0x20b46c .word 0xffffc02c
 *   @0x20b470 .word 0xfffff750
 *   @0x20b474 .word 0xffffdec8
 *
 * ══ §21/60 IniFile::SetKey(char const*, char const*, char const*)  0x235edc  size 508  127 条（0x235edc..0x2360d8）
 * @func 0x235edc 0x2360d8  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×4 / 0xb6574×3 / 0xb6538×3 / 0xb65a4×3 / MemoryManager::Free(void const*)×2 / operator new(unsigned int)×2 / IniFile::GetKey(char const*, char const*) / IniFile::WriteIniFile()
 * 字段偏移 top8: 0x8×8 / 0x4×5 / 0x1c8×1 / 0x18×1 / 0x1a8×1 / 0x194×1 / 0x12c×1 / 0xf0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235edc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x235ee0 mov r6, r0
 *   @0x235ee4 mov r4, r1
 *   @0x235ee8 mov r0, r1
 *   @0x235eec ldr r1, [pc, #0x1c8]
 *   @0x235ef0 mov r5, #1
 *   @0x235ef4 strb r5, [r6, #0x18]
 *   @0x235ef8 mov r7, r2
 *   @0x235efc add r1, pc, r1
 *   @0x235f00 mov r8, r3
 *   @0x235f04 bl 0xb6574 <strcmp@plt>
 *   @0x235f08 cmp r0, #0
 *   @0x235f0c bne 0x235f48 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x6c>
 *   @0x235f10 ldr r1, [pc, #0x1a8]
 *   @0x235f14 mov r0, r7
 *   @0x235f18 add r1, pc, r1
 *   @0x235f1c bl 0xb6574 <strcmp@plt>
 *   @0x235f20 cmp r0, #0
 *   @0x235f24 bne 0x235f40 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x64>
 *   @0x235f28 ldr r1, [pc, #0x194]
 *   @0x235f2c mov r0, r8
 *   @0x235f30 add r1, pc, r1
 *   @0x235f34 bl 0xb6574 <strcmp@plt>
 *   @0x235f38 cmp r0, #0
 *   @0x235f3c beq 0x235fc0 <_ZN7IniFile6SetKeyEPKcS1_S1_+0xe4>
 *   @0x235f40 mov r0, #1
 *   @0x235f44 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x235f48 cmp r7, #0
 *   @0x235f4c cmpne r4, #0
 *   @0x235f50 bne 0x235f5c <_ZN7IniFile6SetKeyEPKcS1_S1_+0x80>
 *   @0x235f54 mov r0, #0
 *   @0x235f58 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x235f5c mov r0, r6
 *   @0x235f60 mov r1, r4
 *   @0x235f64 mov r2, r7
 *   @0x235f68 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x235f6c subs r9, r0, #0
 *   @0x235f70 beq 0x236000 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x124>
 *   @0x235f74 ldr r0, [r9, #0x8]
 *   @0x235f78 cmp r0, #0
 *   @0x235f7c beq 0x235f84 <_ZN7IniFile6SetKeyEPKcS1_S1_+0xa8>
 *   @0x235f80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x235f84 cmp r8, #0
 *   @0x235f88 beq 0x235fd4 <_ZN7IniFile6SetKeyEPKcS1_S1_+0xf8>
 *   @0x235f8c mov r0, r8
 *   @0x235f90 bl 0xb6538 <strlen@plt>
 *   @0x235f94 ldr r1, [pc, #0x12c]
 *   @0x235f98 movw r2, #0x26a
 *   @0x235f9c mov r3, #1
 *   @0x235fa0 add r1, pc, r1
 *   @0x235fa4 add r0, r0, #3
 *   @0x235fa8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x235fac mov r1, r8
 *   @0x235fb0 str r0, [r9, #0x8]
 *   @0x235fb4 bl 0xb65a4 <strcpy@plt>
 *   @0x235fb8 mov r0, #1
 *   @0x235fbc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x235fc0 mov r0, r6
 *   @0x235fc4 bl 0x235d3c <_ZN7IniFile12WriteIniFileEv>
 *   @0x235fc8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x235fcc mov r0, r5
 *   @0x235fd0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x235fd4 ldr r1, [pc, #0xf0]
 *   @0x235fd8 mov r0, #1
 *   @0x235fdc mov r3, r0
 *   @0x235fe0 movw r2, #0x26a
 *   @0x235fe4 add r1, pc, r1
 *   @0x235fe8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x235fec mov r3, r0
 *   @0x235ff0 mov r0, #1
 *   @0x235ff4 str r3, [r9, #0x8]
 *   @0x235ff8 strb r8, [r3]
 *   @0x235ffc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x236000 mov r0, r6
 *   @0x236004 mov r1, r4
 *   @0x236008 bl 0x235a90 <_ZN7IniFile10GetSectionEPKc>
 *   @0x23600c subs r10, r0, #0
 *   @0x236010 beq 0x236068 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x18c>
 *   @0x236014 mov r0, #12
 *   @0x236018 bl 0x27c524 <_Znwj>
 *   @0x23601c ldr r2, [r10, #0x4]
 *   @0x236020 mov r3, #0
 *   @0x236024 mov r9, r0
 *   @0x236028 mov r0, r7
 *   @0x23602c str r3, [r9, #0x4]
 *   @0x236030 str r3, [r9, #0x8]
 *   @0x236034 str r2, [r9]
 *   @0x236038 str r9, [r10, #0x4]
 *   @0x23603c bl 0xb6538 <strlen@plt>
 *   @0x236040 ldr r1, [pc, #0x88]
 *   @0x236044 mov r3, #1
 *   @0x236048 movw r2, #0x263
 *   @0x23604c add r1, pc, r1
 *   @0x236050 add r0, r0, r3
 *   @0x236054 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x236058 mov r1, r7
 *   @0x23605c str r0, [r9, #0x4]
 *   @0x236060 bl 0xb65a4 <strcpy@plt>
 *   @0x236064 b 0x235f74 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x98>
 *   @0x236068 mov r0, #12
 *   @0x23606c bl 0x27c524 <_Znwj>
 *   @0x236070 mov r10, r0
 *   @0x236074 str r9, [r0]
 *   @0x236078 mov r0, r4
 *   @0x23607c str r9, [r10, #0x4]
 *   @0x236080 str r9, [r10, #0x8]
 *   @0x236084 bl 0xb6538 <strlen@plt>
 *   @0x236088 ldr r1, [pc, #0x44]
 *   @0x23608c mov r3, r5
 *   @0x236090 movw r2, #0x256
 *   @0x236094 add r1, pc, r1
 *   @0x236098 add r0, r0, #1
 *   @0x23609c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2360a0 mov r1, r4
 *   @0x2360a4 str r0, [r10, #0x8]
 *   @0x2360a8 bl 0xb65a4 <strcpy@plt>
 *   @0x2360ac ldr r3, [r6, #0x8]
 *   @0x2360b0 str r3, [r10]
 *   @0x2360b4 str r10, [r6, #0x8]
 *   @0x2360b8 b 0x236014 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x138>
 *   @0x2360bc andseq pc, r1, r8, lsl r2
 *   @0x2360c0 andseq pc, r1, r12, lsl #4
 *   @0x2360c4 andseq pc, r1, r4, lsl #4
 *   @0x2360c8 andseq pc, r1, r4, asr #2
 *   @0x2360cc andseq pc, r1, r0, lsl #2
 *   @0x2360d0 mulseq r1, r8, r0
 *   @0x2360d4 andseq pc, r1, r0, asr r0
 *
 * ══ §22/60 JS_DateCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x259cac  size 508  127 条（0x259cac..0x259ea8）
 * @func 0x259cac 0x259ea8  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / JS_Date_constructor(RValue&, CInstance*, CInstance*, int, RValue*) / F_JS_ToString(RValue&, RValue*) / JS_DateCall(RValue&, CInstance*, CInstance*, int, RValue*)+0x1b0
 * 字段偏移 top8: 0x4×11 / 0x8×8 / 0x10×4 / 0xc×2 / 0x38×1 / 0x14×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x259cac push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x259cb0 sub sp, sp, #24
 *   @0x259cb4 add r4, sp, #8
 *   @0x259cb8 mov r5, r0
 *   @0x259cbc ldr r12, [sp, #0x38]
 *   @0x259cc0 mov r0, r4
 *   @0x259cc4 str r12, [sp]
 *   @0x259cc8 bl 0x246108 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_>
 *   @0x259ccc mov r0, r5
 *   @0x259cd0 mov r1, r4
 *   @0x259cd4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x259cd8 ldr r2, [sp, #0x14]
 *   @0x259cdc sub r3, r2, #1
 *   @0x259ce0 bic r3, r3, #-16777216
 *   @0x259ce4 bics r5, r3, #3
 *   @0x259ce8 beq 0x259cf4 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x259cec add sp, sp, #24
 *   @0x259cf0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x259cf4 bic r2, r2, #-16777216
 *   @0x259cf8 cmp r2, #2
 *   @0x259cfc beq 0x259d68 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x259d00 cmp r2, #3
 *   @0x259d04 beq 0x259d40 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x259d08 cmp r2, #1
 *   @0x259d0c bne 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x259d10 ldr r4, [sp, #0x8]
 *   @0x259d14 cmp r4, #0
 *   @0x259d18 beq 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x259d1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x259d20 ldr r5, [r4, #0x4]
 *   @0x259d24 sub r5, r5, #1
 *   @0x259d28 str r5, [r4, #0x4]
 *   @0x259d2c cmp r5, #0
 *   @0x259d30 beq 0x259e08 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x259d34 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x259d38 add sp, sp, #24
 *   @0x259d3c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x259d40 ldr r3, [sp, #0x10]
 *   @0x259d44 tst r3, #8
 *   @0x259d48 beq 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x259d4c ldr r0, [sp, #0x8]
 *   @0x259d50 cmp r0, #0
 *   @0x259d54 beq 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x259d58 ldr r3, [r0]
 *   @0x259d5c ldr r3, [r3, #0x4]
 *   @0x259d60 blx r3
 *   @0x259d64 b 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x259d68 ldr r7, [sp, #0x8]
 *   @0x259d6c cmp r7, #0
 *   @0x259d70 beq 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x259d74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x259d78 ldr r3, [r7]
 *   @0x259d7c ldr r2, [r7, #0x8]
 *   @0x259d80 sub r3, r3, #1
 *   @0x259d84 str r3, [r7]
 *   @0x259d88 cmp r2, r4
 *   @0x259d8c streq r5, [r7, #0x8]
 *   @0x259d90 cmp r3, #0
 *   @0x259d94 bgt 0x259d34 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x259d98 ldr r3, [r7, #0x10]
 *   @0x259d9c cmp r3, #0
 *   @0x259da0 movgt r6, #0
 *   @0x259da4 movgt r10, #5
 *   @0x259da8 movgt r5, r6
 *   @0x259dac ble 0x259e5c <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x259db0 ldr r3, [r7, #0x4]
 *   @0x259db4 add r8, r3, r6, lsl #3
 *   @0x259db8 ldr r9, [r3, r6, lsl #3]
 *   @0x259dbc ldr r4, [r8, #0x4]
 *   @0x259dc0 add r9, r4, r9, lsl #4
 *   @0x259dc4 cmp r4, r9
 *   @0x259dc8 blo 0x259de4 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x259dcc b 0x259e7c <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x259dd0 str r5, [r4, #0x8]
 *   @0x259dd4 str r10, [r4, #0xc]
 *   @0x259dd8 str r5, [r4], #16
 *   @0x259ddc cmp r9, r4
 *   @0x259de0 bls 0x259e40 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x259de4 ldr r3, [r4, #0xc]
 *   @0x259de8 sub r3, r3, #1
 *   @0x259dec bic r3, r3, #-16777216
 *   @0x259df0 bic r3, r3, #3
 *   @0x259df4 cmp r3, #0
 *   @0x259df8 bne 0x259dd0 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x259dfc mov r0, r4
 *   @0x259e00 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x259e04 b 0x259dd0 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x259e08 ldr r0, [r4]
 *   @0x259e0c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x259e10 str r5, [r4]
 *   @0x259e14 str r5, [r4, #0x8]
 *   @0x259e18 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x259e1c ldr r5, [r4, #0x4]
 *   @0x259e20 sub r5, r5, #1
 *   @0x259e24 str r5, [r4, #0x4]
 *   @0x259e28 cmp r5, #0
 *   @0x259e2c beq 0x259e84 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x259e30 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x259e34 mov r0, r4
 *   @0x259e38 bl 0x27d1d0 <_ZdlPv>
 *   @0x259e3c b 0x259d34 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x259e40 ldr r0, [r8, #0x4]
 *   @0x259e44 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x259e48 ldr r3, [r7, #0x10]
 *   @0x259e4c add r6, r6, #1
 *   @0x259e50 str r5, [r8, #0x4]
 *   @0x259e54 cmp r6, r3
 *   @0x259e58 blt 0x259db0 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x259e5c ldr r0, [r7, #0x4]
 *   @0x259e60 mov r4, #0
 *   @0x259e64 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x259e68 str r4, [r7, #0x4]
 *   @0x259e6c mov r0, r7
 *   @0x259e70 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x259e74 str r4, [sp, #0x8]
 *   @0x259e78 b 0x259d34 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x259e7c mov r0, r4
 *   @0x259e80 b 0x259e44 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x259e84 ldr r0, [r4]
 *   @0x259e88 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x259e8c mov r0, r4
 *   @0x259e90 str r5, [r4]
 *   @0x259e94 str r5, [r4, #0x8]
 *   @0x259e98 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x259e9c mov r0, r4
 *   @0x259ea0 bl 0x27d1d0 <_ZdlPv>
 *   @0x259ea4 b 0x259e30 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x184>
 *
 * ══ §23/60 anon_2b8dc0  0x2b8dc0  size 508  127 条（0x2b8dc0..0x2b8fbc）
 * @func 0x2b8dc0 0x2b8fbc  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2b8dc0+0x2c / anon_2b8dc0+0x54 / anon_2b8dc0+0x110 / 0xb6550 / anon_2b8dc0+0x15c / 0xb68a4 / 0xb65d4 / jpeg_destroy
 * 字段偏移 top8: 0x8×4 / 0x6c×4 / 0x14×3 / 0x68×2 / 0x70×2 / 0x2×2 / 0x1×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b8dc0 cmp r1, #0
 *   @0x2b8dc4 mov r3, r0
 *   @0x2b8dc8 push {r4, lr}
 *   @0x2b8dcc ldr r4, [r0]
 *   @0x2b8dd0 blt 0x2b8dec <jinit_upsampler+0x31c>
 *   @0x2b8dd4 ldr r3, [r4, #0x68]
 *   @0x2b8dd8 cmp r1, r3
 *   @0x2b8ddc popgt {r4, pc}
 *   @0x2b8de0 ldr r3, [r4, #0x8]
 *   @0x2b8de4 blx r3
 *   @0x2b8de8 pop {r4, pc}
 *   @0x2b8dec ldr r2, [r4, #0x6c]
 *   @0x2b8df0 cmp r2, #0
 *   @0x2b8df4 beq 0x2b8e04 <jinit_upsampler+0x334>
 *   @0x2b8df8 ldr r1, [r4, #0x68]
 *   @0x2b8dfc cmp r1, #2
 *   @0x2b8e00 ble 0x2b8e14 <jinit_upsampler+0x344>
 *   @0x2b8e04 mov r0, r3
 *   @0x2b8e08 ldr r3, [r4, #0x8]
 *   @0x2b8e0c blx r3
 *   @0x2b8e10 ldr r2, [r4, #0x6c]
 *   @0x2b8e14 add r2, r2, #1
 *   @0x2b8e18 str r2, [r4, #0x6c]
 *   @0x2b8e1c pop {r4, pc}
 *   @0x2b8e20 ldr r3, [r0]
 *   @0x2b8e24 mov r2, #0
 *   @0x2b8e28 str r2, [r3, #0x6c]
 *   @0x2b8e2c str r2, [r3, #0x14]
 *   @0x2b8e30 bx lr
 *   @0x2b8e34 push {r4, r5, lr}
 *   @0x2b8e38 sub sp, sp, #28
 *   @0x2b8e3c ldr r5, [r0]
 *   @0x2b8e40 mov r0, r1
 *   @0x2b8e44 ldr r3, [r5, #0x14]
 *   @0x2b8e48 cmp r3, #0
 *   @0x2b8e4c ble 0x2b8ed0 <jinit_upsampler+0x400>
 *   @0x2b8e50 ldr r2, [r5, #0x74]
 *   @0x2b8e54 cmp r3, r2
 *   @0x2b8e58 bgt 0x2b8ed0 <jinit_upsampler+0x400>
 *   @0x2b8e5c ldr r2, [r5, #0x70]
 *   @0x2b8e60 ldr r1, [r2, r3, lsl #2]
 *   @0x2b8e64 cmp r1, #0
 *   @0x2b8e68 beq 0x2b8f1c <jinit_upsampler+0x44c>
 *   @0x2b8e6c mov r4, r1
 *   @0x2b8e70 b 0x2b8e80 <jinit_upsampler+0x3b0>
 *   @0x2b8e74 cmp r12, #37
 *   @0x2b8e78 beq 0x2b8f00 <jinit_upsampler+0x430>
 *   @0x2b8e7c mov r4, r3
 *   @0x2b8e80 mov r3, r4
 *   @0x2b8e84 ldrb r12, [r3], #1
 *   @0x2b8e88 cmp r12, #0
 *   @0x2b8e8c bne 0x2b8e74 <jinit_upsampler+0x3a4>
 *   @0x2b8e90 add r2, r5, #24
 *   @0x2b8e94 ldm r2, {r2, r3, r12}
 *   @0x2b8e98 str r12, [sp]
 *   @0x2b8e9c ldr r12, [r5, #0x24]
 *   @0x2b8ea0 str r12, [sp, #0x4]
 *   @0x2b8ea4 ldr r12, [r5, #0x28]
 *   @0x2b8ea8 str r12, [sp, #0x8]
 *   @0x2b8eac ldr r12, [r5, #0x2c]
 *   @0x2b8eb0 str r12, [sp, #0xc]
 *   @0x2b8eb4 ldr r12, [r5, #0x30]
 *   @0x2b8eb8 str r12, [sp, #0x10]
 *   @0x2b8ebc ldr r12, [r5, #0x34]
 *   @0x2b8ec0 str r12, [sp, #0x14]
 *   @0x2b8ec4 bl 0xb6550 <sprintf@plt>
 *   @0x2b8ec8 add sp, sp, #28
 *   @0x2b8ecc pop {r4, r5, pc}
 *   @0x2b8ed0 ldr r2, [r5, #0x78]
 *   @0x2b8ed4 cmp r2, #0
 *   @0x2b8ed8 beq 0x2b8f1c <jinit_upsampler+0x44c>
 *   @0x2b8edc ldr r1, [r5, #0x7c]
 *   @0x2b8ee0 cmp r3, r1
 *   @0x2b8ee4 blt 0x2b8f1c <jinit_upsampler+0x44c>
 *   @0x2b8ee8 ldr r12, [r5, #0x80]
 *   @0x2b8eec cmp r3, r12
 *   @0x2b8ef0 bgt 0x2b8f1c <jinit_upsampler+0x44c>
 *   @0x2b8ef4 rsb r1, r1, r3
 *   @0x2b8ef8 ldr r1, [r2, r1, lsl #2]
 *   @0x2b8efc b 0x2b8e64 <jinit_upsampler+0x394>
 *   @0x2b8f00 ldrb r3, [r4, #0x1]
 *   @0x2b8f04 cmp r3, #115
 *   @0x2b8f08 bne 0x2b8e90 <jinit_upsampler+0x3c0>
 *   @0x2b8f0c add r2, r5, #24
 *   @0x2b8f10 add sp, sp, #28
 *   @0x2b8f14 pop {r4, r5, lr}
 *   @0x2b8f18 b 0xb6550 <sprintf@plt>
 *   @0x2b8f1c ldr r2, [r5, #0x70]
 *   @0x2b8f20 str r3, [r5, #0x18]
 *   @0x2b8f24 ldr r1, [r2]
 *   @0x2b8f28 b 0x2b8e6c <jinit_upsampler+0x39c>
 *   @0x2b8f2c push {r4, r5, lr}
 *   @0x2b8f30 sub sp, sp, #212
 *   @0x2b8f34 ldr r4, [pc, #0x54]
 *   @0x2b8f38 add r5, sp, #4
 *   @0x2b8f3c ldr r3, [r0]
 *   @0x2b8f40 ldr r4, [pc, r4]
 *   @0x2b8f44 mov r1, r5
 *   @0x2b8f48 ldr r2, [r4]
 *   @0x2b8f4c ldr r3, [r3, #0xc]
 *   @0x2b8f50 str r2, [sp, #0xcc]
 *   @0x2b8f54 blx r3
 *   @0x2b8f58 ldr r0, [pc, #0x34]
 *   @0x2b8f5c mov r2, r5
 *   @0x2b8f60 ldr r1, [pc, #0x30]
 *   @0x2b8f64 ldr r0, [pc, r0]
 *   @0x2b8f68 add r1, pc, r1
 *   @0x2b8f6c add r0, r0, #168
 *   @0x2b8f70 bl 0xb68a4 <fprintf@plt>
 *   @0x2b8f74 ldr r2, [sp, #0xcc]
 *   @0x2b8f78 ldr r3, [r4]
 *   @0x2b8f7c cmp r2, r3
 *   @0x2b8f80 bne 0x2b8f8c <jinit_upsampler+0x4bc>
 *   @0x2b8f84 add sp, sp, #212
 *   @0x2b8f88 pop {r4, r5, pc}
 *   @0x2b8f8c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b8f90 andseq r4, r3, r0, lsl r10
 *   @0x2b8f94 andseq r8, r3, r0, ror #9
 *   @0x2b8f98 andeq r11, r7, r12, lsr sp
 *   @0x2b8f9c push {r3, lr}
 *   @0x2b8fa0 mov r4, r0
 *   @0x2b8fa4 ldr r3, [r0]
 *   @0x2b8fa8 ldr r3, [r3, #0x8]
 *   @0x2b8fac blx r3
 *   @0x2b8fb0 mov r0, r4
 *   @0x2b8fb4 bl 0x2bc8b8 <jpeg_destroy>
 *   @0x2b8fb8 mov r0, #1
 *
 * ══ §24/60 void b2DynamicTree::Query<b2BroadPhase>(b2BroadPhase*, b2AABB const&) const  0x2c7cd4  size 508  127 条（0x2c7cd4..0x2c7ed0）
 * @func 0x2c7cd4 0x2c7ed0  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Free(void*)×4 / b2Alloc(int)×2 / 0xb65bc×2 / void b2DynamicTree::Query<b2BroadPhase>(b2BroadPhase*, b2AABB const&) const+0x120 / b2BroadPhase::QueryCallback(int)
 * 字段偏移 top8: 0x408×10 / 0x4×9 / 0x40c×5 / 0x2×2 / 0x18×2 / 0x1c×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7cd4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2c7cd8 mov r10, r0
 *   @0x2c7cdc sub sp, sp, #1040
 *   @0x2c7ce0 ldr r12, [r10]
 *   @0x2c7ce4 add r6, sp, #16
 *   @0x2c7ce8 mov r9, r2
 *   @0x2c7cec sub r0, r6, #8
 *   @0x2c7cf0 mov r2, #256
 *   @0x2c7cf4 mov r8, r1
 *   @0x2c7cf8 mov r3, #1
 *   @0x2c7cfc mov r5, r0
 *   @0x2c7d00 mov r7, r0
 *   @0x2c7d04 stmib sp, {r0, r12}
 *   @0x2c7d08 str r2, [sp, #0x40c]
 *   @0x2c7d0c b 0x2c7d18 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x44>
 *   @0x2c7d10 cmp r3, #0
 *   @0x2c7d14 ble 0x2c7df4 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x120>
 *   @0x2c7d18 sub r3, r3, #1
 *   @0x2c7d1c str r3, [sp, #0x408]
 *   @0x2c7d20 ldr r1, [r5, r3, lsl #2]
 *   @0x2c7d24 add r0, r5, r3, lsl #2
 *   @0x2c7d28 cmn r1, #1
 *   @0x2c7d2c beq 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c>
 *   @0x2c7d30 add r4, r1, r1, lsl #3
 *   @0x2c7d34 ldr r2, [r10, #0x4]
 *   @0x2c7d38 vldr s14, [r9]
 *   @0x2c7d3c vldr s13, [r9, #4]
 *   @0x2c7d40 add r4, r2, r4, lsl #2
 *   @0x2c7d44 vldr s15, [r4, #8]
 *   @0x2c7d48 vsub.f32 s15, s14, s15
 *   @0x2c7d4c vldr s11, [r4]
 *   @0x2c7d50 vldr s14, [r4, #12]
 *   @0x2c7d54 vldr s9, [r4, #4]
 *   @0x2c7d58 vldr s12, [r9, #8]
 *   @0x2c7d5c vldr s10, [r9, #12]
 *   @0x2c7d60 vcmpe.f32 s15, #0
 *   @0x2c7d64 vmrs APSR_nzcv, fpscr
 *   @0x2c7d68 bgt 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c>
 *   @0x2c7d6c vsub.f32 s14, s13, s14
 *   @0x2c7d70 vcmpe.f32 s14, #0
 *   @0x2c7d74 vmrs APSR_nzcv, fpscr
 *   @0x2c7d78 bgt 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c>
 *   @0x2c7d7c vsub.f32 s12, s11, s12
 *   @0x2c7d80 vcmpe.f32 s12, #0
 *   @0x2c7d84 vmrs APSR_nzcv, fpscr
 *   @0x2c7d88 bgt 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c>
 *   @0x2c7d8c vsub.f32 s10, s9, s10
 *   @0x2c7d90 vcmpe.f32 s10, #0
 *   @0x2c7d94 vmrs APSR_nzcv, fpscr
 *   @0x2c7d98 bgt 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c>
 *   @0x2c7d9c ldr r12, [r4, #0x18]
 *   @0x2c7da0 cmn r12, #1
 *   @0x2c7da4 beq 0x2c7e10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x13c>
 *   @0x2c7da8 ldr r2, [sp, #0x40c]
 *   @0x2c7dac cmp r3, r2
 *   @0x2c7db0 movne r3, r12
 *   @0x2c7db4 beq 0x2c7e6c <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x198>
 *   @0x2c7db8 str r3, [r0]
 *   @0x2c7dbc ldr r3, [sp, #0x408]
 *   @0x2c7dc0 ldr r2, [sp, #0x40c]
 *   @0x2c7dc4 add r3, r3, #1
 *   @0x2c7dc8 str r3, [sp, #0x408]
 *   @0x2c7dcc cmp r3, r2
 *   @0x2c7dd0 beq 0x2c7e2c <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x158>
 *   @0x2c7dd4 ldr r2, [r4, #0x1c]
 *   @0x2c7dd8 str r2, [r5, r3, lsl #2]
 *   @0x2c7ddc ldr r3, [sp, #0x408]
 *   @0x2c7de0 ldr r5, [sp, #0x4]
 *   @0x2c7de4 add r3, r3, #1
 *   @0x2c7de8 str r3, [sp, #0x408]
 *   @0x2c7dec cmp r3, #0
 *   @0x2c7df0 bgt 0x2c7d18 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x44>
 *   @0x2c7df4 sub r6, r6, #8
 *   @0x2c7df8 cmp r5, r6
 *   @0x2c7dfc beq 0x2c7e08 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x134>
 *   @0x2c7e00 mov r0, r5
 *   @0x2c7e04 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c7e08 add sp, sp, #1040
 *   @0x2c7e0c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c7e10 mov r0, r8
 *   @0x2c7e14 bl 0x2dc950 <_ZN12b2BroadPhase13QueryCallbackEi>
 *   @0x2c7e18 cmp r0, #0
 *   @0x2c7e1c beq 0x2c7eb8 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x1e4>
 *   @0x2c7e20 ldr r3, [sp, #0x408]
 *   @0x2c7e24 ldr r5, [sp, #0x4]
 *   @0x2c7e28 b 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c>
 *   @0x2c7e2c lsl r0, r3, #3
 *   @0x2c7e30 lsl r3, r3, #1
 *   @0x2c7e34 str r3, [sp, #0x40c]
 *   @0x2c7e38 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2c7e3c ldr r2, [sp, #0x408]
 *   @0x2c7e40 mov r1, r5
 *   @0x2c7e44 lsl r2, r2, #2
 *   @0x2c7e48 str r0, [sp, #0x4]
 *   @0x2c7e4c bl 0xb65bc <memcpy@plt>
 *   @0x2c7e50 cmp r5, r7
 *   @0x2c7e54 beq 0x2c7e60 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x18c>
 *   @0x2c7e58 mov r0, r5
 *   @0x2c7e5c bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c7e60 ldr r5, [sp, #0x4]
 *   @0x2c7e64 ldr r3, [sp, #0x408]
 *   @0x2c7e68 b 0x2c7dd4 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x100>
 *   @0x2c7e6c lsl r0, r3, #3
 *   @0x2c7e70 ldr r5, [sp, #0x4]
 *   @0x2c7e74 lsl r3, r3, #1
 *   @0x2c7e78 str r3, [sp, #0x40c]
 *   @0x2c7e7c bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2c7e80 ldr r2, [sp, #0x408]
 *   @0x2c7e84 mov r1, r5
 *   @0x2c7e88 lsl r2, r2, #2
 *   @0x2c7e8c str r0, [sp, #0x4]
 *   @0x2c7e90 bl 0xb65bc <memcpy@plt>
 *   @0x2c7e94 cmp r5, r7
 *   @0x2c7e98 beq 0x2c7ea4 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x1d0>
 *   @0x2c7e9c mov r0, r5
 *   @0x2c7ea0 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c7ea4 ldr r0, [sp, #0x408]
 *   @0x2c7ea8 ldr r5, [sp, #0x4]
 *   @0x2c7eac ldr r3, [r4, #0x18]
 *   @0x2c7eb0 add r0, r5, r0, lsl #2
 *   @0x2c7eb4 b 0x2c7db8 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0xe4>
 *   @0x2c7eb8 ldr r0, [sp, #0x4]
 *   @0x2c7ebc sub r6, r6, #8
 *   @0x2c7ec0 cmp r0, r6
 *   @0x2c7ec4 beq 0x2c7e08 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x134>
 *   @0x2c7ec8 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c7ecc b 0x2c7e08 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x134>
 *
 * ══ §25/60 b2World::DestroyBody(b2Body*)  0x2c93e4  size 508  127 条（0x2c93e4..0x2c95e0）
 * @func 0x2c93e4 0x2c95e0  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::DestroyJoint(b2Joint*) / b2ContactManager::Destroy(b2Contact*) / b2Fixture::DestroyProxies(b2BroadPhase*) / b2Fixture::Destroy(b2BlockAllocator*) / b2BlockAllocator::Free(void*, int) / b2Body::~b2Body()
 * 字段偏移 top8: 0x4×4 / 0x7c×3 / 0xc×3 / 0x74×3 / 0x78×3 / 0x80×2 / 0x1d8×1 / 0x1c8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c93e4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c93e8 movw r3, #0x9230
 *   @0x2c93ec movt r3, #0x1
 *   @0x2c93f0 mov r4, r0
 *   @0x2c93f4 ldr r5, [pc, #0x1d8]
 *   @0x2c93f8 mov r6, r1
 *   @0x2c93fc ldr r0, [r0, r3]
 *   @0x2c9400 movw r7, #0x91d4
 *   @0x2c9404 ldr r5, [pc, r5]
 *   @0x2c9408 ldr r1, [pc, #0x1c8]
 *   @0x2c940c cmp r0, #0
 *   @0x2c9410 movt r7, #0x1
 *   @0x2c9414 ldr r3, [r5]
 *   @0x2c9418 add r1, pc, r1
 *   @0x2c941c movle r0, #0
 *   @0x2c9420 movgt r0, #1
 *   @0x2c9424 blx r3
 *   @0x2c9428 ldr r0, [r4, r7]
 *   @0x2c942c ldr r1, [pc, #0x1a8]
 *   @0x2c9430 eor r0, r0, #2
 *   @0x2c9434 ldr r3, [r5]
 *   @0x2c9438 add r1, pc, r1
 *   @0x2c943c ubfx r0, r0, #0x1, #0x1
 *   @0x2c9440 blx r3
 *   @0x2c9444 ldr r3, [r4, r7]
 *   @0x2c9448 tst r3, #2
 *   @0x2c944c popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c9450 ldr r7, [r6, #0x7c]
 *   @0x2c9454 cmp r7, #0
 *   @0x2c9458 movwne r8, #0x9244
 *   @0x2c945c movtne r8, #0x1
 *   @0x2c9460 beq 0x2c94a4 <_ZN7b2World11DestroyBodyEP6b2Body+0xc0>
 *   @0x2c9464 ldr r3, [r4, r8]
 *   @0x2c9468 ldr r5, [r7, #0xc]
 *   @0x2c946c cmp r3, #0
 *   @0x2c9470 mov r0, r3
 *   @0x2c9474 beq 0x2c9488 <_ZN7b2World11DestroyBodyEP6b2Body+0xa4>
 *   @0x2c9478 ldr r3, [r3]
 *   @0x2c947c ldr r1, [r7, #0x4]
 *   @0x2c9480 ldr r3, [r3, #0x8]
 *   @0x2c9484 blx r3
 *   @0x2c9488 ldr r1, [r7, #0x4]
 *   @0x2c948c mov r0, r4
 *   @0x2c9490 bl 0x2c923c <_ZN7b2World12DestroyJointEP7b2Joint>
 *   @0x2c9494 cmp r5, #0
 *   @0x2c9498 mov r7, r5
 *   @0x2c949c str r5, [r6, #0x7c]
 *   @0x2c94a0 bne 0x2c9464 <_ZN7b2World11DestroyBodyEP6b2Body+0x80>
 *   @0x2c94a4 ldr r3, [r6, #0x80]
 *   @0x2c94a8 mov r2, #0
 *   @0x2c94ac str r2, [r6, #0x7c]
 *   @0x2c94b0 cmp r3, r2
 *   @0x2c94b4 addne r7, r4, #102400
 *   @0x2c94b8 addne r7, r7, #472
 *   @0x2c94bc beq 0x2c94dc <_ZN7b2World11DestroyBodyEP6b2Body+0xf8>
 *   @0x2c94c0 ldr r5, [r3, #0xc]
 *   @0x2c94c4 mov r0, r7
 *   @0x2c94c8 ldr r1, [r3, #0x4]
 *   @0x2c94cc bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact>
 *   @0x2c94d0 cmp r5, #0
 *   @0x2c94d4 mov r3, r5
 *   @0x2c94d8 bne 0x2c94c0 <_ZN7b2World11DestroyBodyEP6b2Body+0xdc>
 *   @0x2c94dc ldr r5, [r6, #0x74]
 *   @0x2c94e0 mov r3, #0
 *   @0x2c94e4 str r3, [r6, #0x80]
 *   @0x2c94e8 cmp r5, r3
 *   @0x2c94ec addne r9, r4, #102400
 *   @0x2c94f0 movwne r8, #0x9244
 *   @0x2c94f4 addne r9, r9, #472
 *   @0x2c94f8 movtne r8, #0x1
 *   @0x2c94fc beq 0x2c9568 <_ZN7b2World11DestroyBodyEP6b2Body+0x184>
 *   @0x2c9500 ldr r3, [r4, r8]
 *   @0x2c9504 mov r1, r5
 *   @0x2c9508 ldr r7, [r5, #0x4]
 *   @0x2c950c cmp r3, #0
 *   @0x2c9510 mov r0, r3
 *   @0x2c9514 beq 0x2c9524 <_ZN7b2World11DestroyBodyEP6b2Body+0x140>
 *   @0x2c9518 ldr r3, [r3]
 *   @0x2c951c ldr r3, [r3, #0xc]
 *   @0x2c9520 blx r3
 *   @0x2c9524 mov r0, r5
 *   @0x2c9528 mov r1, r9
 *   @0x2c952c bl 0x2c8770 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase>
 *   @0x2c9530 mov r0, r5
 *   @0x2c9534 mov r1, r4
 *   @0x2c9538 bl 0x2c85f0 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator>
 *   @0x2c953c mov r1, r5
 *   @0x2c9540 mov r0, r4
 *   @0x2c9544 mov r2, #52
 *   @0x2c9548 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2c954c ldr r3, [r6, #0x78]
 *   @0x2c9550 cmp r7, #0
 *   @0x2c9554 mov r5, r7
 *   @0x2c9558 sub r3, r3, #1
 *   @0x2c955c str r7, [r6, #0x74]
 *   @0x2c9560 str r3, [r6, #0x78]
 *   @0x2c9564 bne 0x2c9500 <_ZN7b2World11DestroyBodyEP6b2Body+0x11c>
 *   @0x2c9568 ldr r3, [r6, #0x6c]
 *   @0x2c956c mov r2, #0
 *   @0x2c9570 str r2, [r6, #0x74]
 *   @0x2c9574 cmp r3, r2
 *   @0x2c9578 str r2, [r6, #0x78]
 *   @0x2c957c ldrne r2, [r6, #0x70]
 *   @0x2c9580 strne r2, [r3, #0x70]
 *   @0x2c9584 ldr r2, [r6, #0x70]
 *   @0x2c9588 mov r0, r6
 *   @0x2c958c cmp r2, #0
 *   @0x2c9590 strne r3, [r2, #0x6c]
 *   @0x2c9594 movw r3, #0x9228
 *   @0x2c9598 movt r3, #0x1
 *   @0x2c959c ldr r1, [r4, r3]
 *   @0x2c95a0 cmp r1, r6
 *   @0x2c95a4 streq r2, [r4, r3]
 *   @0x2c95a8 movw r3, #0x9230
 *   @0x2c95ac movt r3, #0x1
 *   @0x2c95b0 ldr r2, [r4, r3]
 *   @0x2c95b4 sub r2, r2, #1
 *   @0x2c95b8 str r2, [r4, r3]
 *   @0x2c95bc bl 0x2c6bfc <_ZN6b2BodyD2Ev>
 *   @0x2c95c0 mov r0, r4
 *   @0x2c95c4 mov r1, r6
 *   @0x2c95c8 mov r2, #168
 *   @0x2c95cc pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c95d0 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2c95d4 andseq r8, r2, r4, asr #1
 *   @0x2c95d8 andeq r3, r9, r0, asr pc
 *   @0x2c95dc muleq r9, r12, lr
 *
 * ══ §26/60 GraphicsPerf::BuildPerfDisplay()  0x17bbfc  size 504  126 条（0x17bbfc..0x17bdf4）
 * @func 0x17bbfc 0x17bdf4  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17bc08→0x542979, 0x17bc28→0x499334, 0x17bc54→0x4a2108, 0x17bc70→0x4a2020, 0x17bca8→0x49a018, 0x17bcac→0x4a2030
 * 调用序列: __floatdisf×3 / Graphics::AllocVerts(ePrimType, void*, int, int)×2 / AddPerfBar(SVertex_Float*, float, float, unsigned int)×2 / GR_Window_Get_Region_Width()
 * 字段偏移 top8: 0x1cc×2 / 0x13c×2 / 0x-30×2 / 0x1b0×1 / 0x188×1 / 0x170×1 / 0x-5c×1 / 0x-40×1
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17bbfc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x17bc00 vpush {d8, d9}
 *   @0x17bc04 ldr r4, [pc, #0x1cc]
 *   @0x17bc08 ldr r3, [pc, #0x1cc]
 *   @0x17bc0c add r4, pc, r4
 *   @0x17bc10 ldr r3, [r4, r3]
 *   @0x17bc14 ldrb r1, [r3]
 *   @0x17bc18 cmp r1, #0
 *   @0x17bc1c beq 0x17bc28 <_ZN12GraphicsPerf16BuildPerfDisplayEv+0x2c>
 *   @0x17bc20 vpop {d8, d9}
 *   @0x17bc24 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x17bc28 ldr r3, [pc, #0x1b0]
 *   @0x17bc2c mov r2, #24
 *   @0x17bc30 mov r0, #4
 *   @0x17bc34 ldr r6, [r4, r3]
 *   @0x17bc38 ldr r3, [r6]
 *   @0x17bc3c add r3, r3, #1
 *   @0x17bc40 add r3, r3, r3, lsl #1
 *   @0x17bc44 lsl r3, r3, #1
 *   @0x17bc48 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17bc4c mov r5, r0
 *   @0x17bc50 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x17bc54 ldr r3, [pc, #0x188]
 *   @0x17bc58 add r7, r5, #144
 *   @0x17bc5c ldr r3, [r4, r3]
 *   @0x17bc60 vmov s14, r0
 *   @0x17bc64 ldrd r0, r1, [r3]
 *   @0x17bc68 vcvt.f32.s32 s17, s14
 *   @0x17bc6c bl 0x319398 <__floatdisf>
 *   @0x17bc70 ldr r2, [pc, #0x170]
 *   @0x17bc74 mov r1, #0
 *   @0x17bc78 mvn r3, #0
 *   @0x17bc7c ldr r8, [r4, r2]
 *   @0x17bc80 vldr s15, [r8]
 *   @0x17bc84 vmov s14, r0
 *   @0x17bc88 mov r0, r5
 *   @0x17bc8c vdiv.f32 s15, s14, s15
 *   @0x17bc90 vmul.f32 s15, s15, s17
 *   @0x17bc94 vmov r2, s15
 *   @0x17bc98 bl 0x17bb50 <_Z10AddPerfBarP13SVertex_Floatffj>
 *   @0x17bc9c ldr r10, [r6]
 *   @0x17bca0 subs r10, r10, #1
 *   @0x17bca4 bmi 0x17bd2c <_ZN12GraphicsPerf16BuildPerfDisplayEv+0x130>
 *   @0x17bca8 ldr r2, [pc, #0x13c]
 *   @0x17bcac ldr r3, [pc, #0x13c]
 *   @0x17bcb0 ldr r6, [r4, r2]
 *   @0x17bcb4 ldr r9, [r4, r3]
 *   @0x17bcb8 add r6, r6, #32
 *   @0x17bcbc ldrd r4, r5, [r9]
 *   @0x17bcc0 vldr s16, [r8]
 *   @0x17bcc4 ldrd r0, r1, [r6, #-32]
 *   @0x17bcc8 sub r10, r10, #1
 *   @0x17bccc add r6, r6, #32
 *   @0x17bcd0 subs r0, r0, r4
 *   @0x17bcd4 sbc r1, r1, r5
 *   @0x17bcd8 bl 0x319398 <__floatdisf>
 *   @0x17bcdc ldrd r2, r3, [r6, #-56]
 *   @0x17bce0 mov r1, r3
 *   @0x17bce4 vmov s15, r0
 *   @0x17bce8 mov r0, r2
 *   @0x17bcec subs r0, r0, r4
 *   @0x17bcf0 sbc r1, r1, r5
 *   @0x17bcf4 vdiv.f32 s18, s15, s16
 *   @0x17bcf8 bl 0x319398 <__floatdisf>
 *   @0x17bcfc ldr r3, [r6, #-0x30]
 *   @0x17bd00 vmov s14, r0
 *   @0x17bd04 mov r0, r7
 *   @0x17bd08 add r7, r7, #144
 *   @0x17bd0c vdiv.f32 s16, s14, s16
 *   @0x17bd10 vmul.f32 s18, s18, s17
 *   @0x17bd14 vmul.f32 s16, s16, s17
 *   @0x17bd18 vmov r1, s18
 *   @0x17bd1c vmov r2, s16
 *   @0x17bd20 bl 0x17bb50 <_Z10AddPerfBarP13SVertex_Floatffj>
 *   @0x17bd24 cmn r10, #1
 *   @0x17bd28 bne 0x17bcbc <_ZN12GraphicsPerf16BuildPerfDisplayEv+0xc0>
 *   @0x17bd2c mov r1, #0
 *   @0x17bd30 mov r2, #24
 *   @0x17bd34 mov r3, #10
 *   @0x17bd38 mov r0, #2
 *   @0x17bd3c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17bd40 vcvt.s32.f32 s17, s17
 *   @0x17bd44 mov r12, #0
 *   @0x17bd48 movw r5, #0xcccd
 *   @0x17bd4c movt r5, #0x3ecc
 *   @0x17bd50 mvn r4, #0
 *   @0x17bd54 mov r1, #0
 *   @0x17bd58 mov r8, #1090519040
 *   @0x17bd5c vmov r6, s17
 *   @0x17bd60 add r7, r6, #3
 *   @0x17bd64 cmp r6, r12
 *   @0x17bd68 movlt r6, r7
 *   @0x17bd6c mov r7, #0
 *   @0x17bd70 asr r6, r6, #2
 *   @0x17bd74 movt r7, #0x41a0
 *   @0x17bd78 add r3, r0, #48
 *   @0x17bd7c add r2, r0, #44
 *   @0x17bd80 add r0, r0, #288
 *   @0x17bd84 vmov s14, r12
 *   @0x17bd88 add r3, r3, #48
 *   @0x17bd8c add r12, r12, r6
 *   @0x17bd90 add r2, r2, #48
 *   @0x17bd94 vcvt.f32.s32 s15, s14
 *   @0x17bd98 vstr s15, [r3, #-96]
 *   @0x17bd9c vstr s15, [r2, #-68]
 *   @0x17bda0 str r8, [r3, #-0x5c]
 *   @0x17bda4 str r7, [r2, #-0x40]
 *   @0x17bda8 str r5, [r2, #-0x3c]
 *   @0x17bdac str r5, [r3, #-0x58]
 *   @0x17bdb0 str r4, [r2, #-0x38]
 *   @0x17bdb4 str r4, [r3, #-0x54]
 *   @0x17bdb8 str r1, [r2, #-0x30]
 *   @0x17bdbc str r1, [r3, #-0x4c]
 *   @0x17bdc0 str r1, [r2, #-0x34]
 *   @0x17bdc4 str r1, [r3, #-0x50]
 *   @0x17bdc8 cmp r3, r0
 *   @0x17bdcc bne 0x17bd84 <_ZN12GraphicsPerf16BuildPerfDisplayEv+0x188>
 *   @0x17bdd0 vpop {d8, d9}
 *   @0x17bdd4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x17bdd8 eoreq r6, r7, r4, asr #32
 *   @0x17bddc .word 0xffffdfa0
 *   @0x17bde0 .word 0xffffe730
 *   @0x17bde4 .word 0xffffe778
 *   @0x17bde8 .word 0xffffe6d8
 *   @0x17bdec .word 0xffffe738
 *   @0x17bdf0 .word 0xffffe74c
 *
 * ══ §27/60 LoadSave::HTTP_Request(char const*, char const*, char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, int)  0x18fdb8  size 504  126 条（0x18fdb8..0x18ffb0）
 * @func 0x18fdb8 0x18ffb0  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×8 / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / 0xb6538 / LoadSave::HTTP_Request(char const*, char const*, char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, int)+0x1a8 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x-28×5 / 0x8×4 / 0x4×4 / 0x-30×4 / 0xc×3 / 0x29c×3 / 0x10×2 / 0x-2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18fdb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18fdbc add r11, sp, #32
 *   @0x18fdc0 sub sp, sp, #36
 *   @0x18fdc4 mov r6, r0
 *   @0x18fdc8 mov r0, #68
 *   @0x18fdcc ldr lr, [r11, #0xc]
 *   @0x18fdd0 mov r9, r1
 *   @0x18fdd4 ldr r12, [r11, #0x8]
 *   @0x18fdd8 mov r8, r2
 *   @0x18fddc ldr r10, [r11, #0x4]
 *   @0x18fde0 mov r5, r3
 *   @0x18fde4 str lr, [r11, #-0x28]
 *   @0x18fde8 ldr r4, [r11, #0x10]
 *   @0x18fdec str r12, [r11, #-0x30]
 *   @0x18fdf0 bl 0x27c524 <_Znwj>
 *   @0x18fdf4 ldr r12, [r11, #-0x30]
 *   @0x18fdf8 mov r3, r10
 *   @0x18fdfc mov r1, r6
 *   @0x18fe00 ldr r10, [pc, #0x19c]
 *   @0x18fe04 str r12, [sp]
 *   @0x18fe08 mov r12, #0
 *   @0x18fe0c ldr r2, [r11, #-0x28]
 *   @0x18fe10 add r10, pc, r10
 *   @0x18fe14 str r12, [sp, #0x8]
 *   @0x18fe18 str r2, [sp, #0x4]
 *   @0x18fe1c mov r2, #131072
 *   @0x18fe20 mov r7, r0
 *   @0x18fe24 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x18fe28 bl 0x290274 <getJNIEnv>
 *   @0x18fe2c mov r1, r6
 *   @0x18fe30 ldr r3, [r0]
 *   @0x18fe34 ldr r3, [r3, #0x29c]
 *   @0x18fe38 blx r3
 *   @0x18fe3c str r0, [r11, #-0x28]
 *   @0x18fe40 bl 0x290274 <getJNIEnv>
 *   @0x18fe44 mov r1, r9
 *   @0x18fe48 ldr r3, [r0]
 *   @0x18fe4c ldr r3, [r3, #0x29c]
 *   @0x18fe50 blx r3
 *   @0x18fe54 mov r9, r0
 *   @0x18fe58 bl 0x290274 <getJNIEnv>
 *   @0x18fe5c mov r1, r8
 *   @0x18fe60 ldr r3, [r0]
 *   @0x18fe64 ldr r3, [r3, #0x29c]
 *   @0x18fe68 blx r3
 *   @0x18fe6c adds r3, r5, #0
 *   @0x18fe70 movne r3, #1
 *   @0x18fe74 cmn r4, #1
 *   @0x18fe78 movne r3, #0
 *   @0x18fe7c cmp r3, #0
 *   @0x18fe80 mov r8, r0
 *   @0x18fe84 beq 0x18fe94 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i+0xdc>
 *   @0x18fe88 mov r0, r5
 *   @0x18fe8c bl 0xb6538 <strlen@plt>
 *   @0x18fe90 mov r4, r0
 *   @0x18fe94 cmp r4, #0
 *   @0x18fe98 ble 0x18ff60 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i+0x1a8>
 *   @0x18fe9c add r2, r4, #7
 *   @0x18fea0 str sp, [r11, #-0x2c]
 *   @0x18fea4 bic r2, r2, #7
 *   @0x18fea8 mov r6, #0
 *   @0x18feac sub sp, sp, r2
 *   @0x18feb0 add r12, sp, #16
 *   @0x18feb4 ldrb r2, [r5, r6]
 *   @0x18feb8 strb r2, [r12, r6]
 *   @0x18febc add r6, r6, #1
 *   @0x18fec0 cmp r6, r4
 *   @0x18fec4 bne 0x18feb4 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i+0xfc>
 *   @0x18fec8 str r12, [r11, #-0x30]
 *   @0x18fecc bl 0x290274 <getJNIEnv>
 *   @0x18fed0 mov r1, r6
 *   @0x18fed4 ldr r2, [r0]
 *   @0x18fed8 ldr r2, [r2, #0x2c0]
 *   @0x18fedc blx r2
 *   @0x18fee0 mov r4, r0
 *   @0x18fee4 bl 0x290274 <getJNIEnv>
 *   @0x18fee8 ldr r12, [r11, #-0x30]
 *   @0x18feec mov r3, r6
 *   @0x18fef0 mov r1, r4
 *   @0x18fef4 mov r2, #0
 *   @0x18fef8 ldr lr, [r0]
 *   @0x18fefc str r12, [sp]
 *   @0x18ff00 ldr r12, [lr, #0x340]
 *   @0x18ff04 blx r12
 *   @0x18ff08 bl 0x290274 <getJNIEnv>
 *   @0x18ff0c ldr r1, [pc, #0x94]
 *   @0x18ff10 ldr r2, [pc, #0x94]
 *   @0x18ff14 ldr r3, [r11, #-0x28]
 *   @0x18ff18 ldr r1, [r10, r1]
 *   @0x18ff1c ldr r2, [r10, r2]
 *   @0x18ff20 ldr r1, [r1]
 *   @0x18ff24 ldr r2, [r2]
 *   @0x18ff28 str r4, [sp, #0x8]
 *   @0x18ff2c str r9, [sp]
 *   @0x18ff30 str r8, [sp, #0x4]
 *   @0x18ff34 ldr r12, [r7, #0x24]
 *   @0x18ff38 str r12, [sp, #0xc]
 *   @0x18ff3c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x18ff40 bl 0x290274 <getJNIEnv>
 *   @0x18ff44 mov r1, r4
 *   @0x18ff48 ldr r3, [r0]
 *   @0x18ff4c ldr r3, [r3, #0x5c]
 *   @0x18ff50 blx r3
 *   @0x18ff54 ldr sp, [r11, #-0x2c]
 *   @0x18ff58 sub sp, r11, #32
 *   @0x18ff5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18ff60 bl 0x290274 <getJNIEnv>
 *   @0x18ff64 ldr r1, [pc, #0x3c]
 *   @0x18ff68 ldr r2, [pc, #0x3c]
 *   @0x18ff6c mov r12, #0
 *   @0x18ff70 ldr r3, [r11, #-0x28]
 *   @0x18ff74 ldr r1, [r10, r1]
 *   @0x18ff78 ldr r2, [r10, r2]
 *   @0x18ff7c str r9, [r11, #0x4]
 *   @0x18ff80 ldr r1, [r1]
 *   @0x18ff84 ldr r2, [r2]
 *   @0x18ff88 str r8, [r11, #0x8]
 *   @0x18ff8c str r12, [r11, #0xc]
 *   @0x18ff90 ldr r12, [r7, #0x24]
 *   @0x18ff94 str r12, [r11, #0x10]
 *   @0x18ff98 sub sp, r11, #32
 *   @0x18ff9c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18ffa0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x18ffa4 eoreq r1, r6, r0, asr #28
 *   @0x18ffa8 .word 0xffffbd54
 *   @0x18ffac .word 0xffffea14
 *
 * ══ §28/60 GV_PointerNull(CInstance*, int, RValue*)  0x200698  size 504  126 条（0x200698..0x200890）
 * @func 0x200698 0x2008a0  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / GV_PointerNull(CInstance*, int, RValue*)+0x120 / GV_PointerNull(CInstance*, int, RValue*)+0x1ac / GV_PointerNull(CInstance*, int, RValue*)+0x16c
 * 字段偏移 top8: 0x4×11 / 0x8×6 / 0xc×4 / 0x10×3 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200698 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20069c mov r5, r2
 *   @0x2006a0 ldr r2, [r2, #0xc]
 *   @0x2006a4 sub r3, r2, #1
 *   @0x2006a8 bic r3, r3, #-16777216
 *   @0x2006ac bics r4, r3, #3
 *   @0x2006b0 beq 0x2006d0 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x38>
 *   @0x2006b4 mov r3, #0
 *   @0x2006b8 mov r2, #3
 *   @0x2006bc str r3, [r5, #0x8]
 *   @0x2006c0 mov r0, #1
 *   @0x2006c4 str r3, [r5]
 *   @0x2006c8 str r2, [r5, #0xc]
 *   @0x2006cc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2006d0 bic r2, r2, #-16777216
 *   @0x2006d4 cmp r2, #2
 *   @0x2006d8 beq 0x200748 <_Z14GV_PointerNullP9CInstanceiP6RValue+0xb0>
 *   @0x2006dc cmp r2, #3
 *   @0x2006e0 beq 0x200720 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x88>
 *   @0x2006e4 cmp r2, #1
 *   @0x2006e8 bne 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c>
 *   @0x2006ec ldr r4, [r5]
 *   @0x2006f0 cmp r4, #0
 *   @0x2006f4 beq 0x200714 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x7c>
 *   @0x2006f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2006fc ldr r6, [r4, #0x4]
 *   @0x200700 sub r6, r6, #1
 *   @0x200704 str r6, [r4, #0x4]
 *   @0x200708 cmp r6, #0
 *   @0x20070c beq 0x200780 <_Z14GV_PointerNullP9CInstanceiP6RValue+0xe8>
 *   @0x200710 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200714 mov r3, #0
 *   @0x200718 str r3, [r5]
 *   @0x20071c b 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c>
 *   @0x200720 ldr r3, [r5, #0x8]
 *   @0x200724 tst r3, #8
 *   @0x200728 beq 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c>
 *   @0x20072c ldr r0, [r5]
 *   @0x200730 cmp r0, #0
 *   @0x200734 beq 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c>
 *   @0x200738 ldr r3, [r0]
 *   @0x20073c ldr r3, [r3, #0x4]
 *   @0x200740 blx r3
 *   @0x200744 b 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c>
 *   @0x200748 ldr r8, [r5]
 *   @0x20074c cmp r8, #0
 *   @0x200750 beq 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c>
 *   @0x200754 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200758 ldr r3, [r8]
 *   @0x20075c ldr r2, [r8, #0x8]
 *   @0x200760 sub r3, r3, #1
 *   @0x200764 str r3, [r8]
 *   @0x200768 cmp r5, r2
 *   @0x20076c streq r4, [r8, #0x8]
 *   @0x200770 cmp r3, #0
 *   @0x200774 ble 0x2007b8 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x120>
 *   @0x200778 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20077c b 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c>
 *   @0x200780 ldr r0, [r4]
 *   @0x200784 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200788 str r6, [r4]
 *   @0x20078c str r6, [r4, #0x8]
 *   @0x200790 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200794 ldr r6, [r4, #0x4]
 *   @0x200798 sub r6, r6, #1
 *   @0x20079c str r6, [r4, #0x4]
 *   @0x2007a0 cmp r6, #0
 *   @0x2007a4 beq 0x20086c <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1d4>
 *   @0x2007a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2007ac mov r0, r4
 *   @0x2007b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2007b4 b 0x200710 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x78>
 *   @0x2007b8 ldr r3, [r8, #0x10]
 *   @0x2007bc cmp r3, #0
 *   @0x2007c0 movgt r7, #0
 *   @0x2007c4 movgt r11, #5
 *   @0x2007c8 movgt r6, r7
 *   @0x2007cc ble 0x200844 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1ac>
 *   @0x2007d0 ldr r3, [r8, #0x4]
 *   @0x2007d4 add r9, r3, r7, lsl #3
 *   @0x2007d8 ldr r10, [r3, r7, lsl #3]
 *   @0x2007dc ldr r4, [r9, #0x4]
 *   @0x2007e0 add r10, r4, r10, lsl #4
 *   @0x2007e4 cmp r4, r10
 *   @0x2007e8 blo 0x200804 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x16c>
 *   @0x2007ec b 0x200864 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1cc>
 *   @0x2007f0 str r6, [r4, #0x8]
 *   @0x2007f4 str r11, [r4, #0xc]
 *   @0x2007f8 str r6, [r4], #16
 *   @0x2007fc cmp r10, r4
 *   @0x200800 bls 0x200828 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x190>
 *   @0x200804 ldr r3, [r4, #0xc]
 *   @0x200808 sub r3, r3, #1
 *   @0x20080c bic r3, r3, #-16777216
 *   @0x200810 bic r3, r3, #3
 *   @0x200814 cmp r3, #0
 *   @0x200818 bne 0x2007f0 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x158>
 *   @0x20081c mov r0, r4
 *   @0x200820 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x200824 b 0x2007f0 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x158>
 *   @0x200828 ldr r0, [r9, #0x4]
 *   @0x20082c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200830 ldr r3, [r8, #0x10]
 *   @0x200834 add r7, r7, #1
 *   @0x200838 str r6, [r9, #0x4]
 *   @0x20083c cmp r7, r3
 *   @0x200840 blt 0x2007d0 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x138>
 *   @0x200844 ldr r0, [r8, #0x4]
 *   @0x200848 mov r4, #0
 *   @0x20084c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200850 str r4, [r8, #0x4]
 *   @0x200854 mov r0, r8
 *   @0x200858 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20085c str r4, [r5]
 *   @0x200860 b 0x200778 <_Z14GV_PointerNullP9CInstanceiP6RValue+0xe0>
 *   @0x200864 mov r0, r4
 *   @0x200868 b 0x20082c <_Z14GV_PointerNullP9CInstanceiP6RValue+0x194>
 *   @0x20086c ldr r0, [r4]
 *   @0x200870 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200874 mov r0, r4
 *   @0x200878 str r6, [r4]
 *   @0x20087c str r6, [r4, #0x8]
 *   @0x200880 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x200884 mov r0, r4
 *   @0x200888 bl 0x27d1d0 <_ZdlPv>
 *   @0x20088c b 0x2007a8 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x110>
 *
 * ══ §29/60 anon_223cb4  0x223cb4  size 504  126 条（0x223cb4..0x223eac）
 * @func 0x223cb4 0x223eac  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::LogError(char const*, ...)×5 / ov_open_callbacks×2 / zip_fopen / zip_fclose / 0xb6844 / ov_open / 0xb6850
 * 字段偏移 top8: 0x1c×2 / 0x64×1 / 0x2c0×1 / 0x14×1 / 0xd0×1 / 0xa0×1 / 0x18×1 / 0x2c8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223cb4 ldr r12, [pc, #0x64]
 *   @0x223cb8 push {r4, r5, lr}
 *   @0x223cbc ldr r12, [pc, r12]
 *   @0x223cc0 mov lr, r0
 *   @0x223cc4 mov r4, #0
 *   @0x223cc8 mov r5, r1
 *   @0x223ccc str r4, [r0, #0x2c0]
 *   @0x223cd0 ldm r12, {r0, r1, r2, r3}
 *   @0x223cd4 sub sp, sp, #20
 *   @0x223cd8 stm sp, {r0, r1, r2, r3}
 *   @0x223cdc mov r2, r4
 *   @0x223ce0 mov r0, lr
 *   @0x223ce4 mov r1, lr
 *   @0x223ce8 mov r3, r4
 *   @0x223cec bl 0x231c48 <ov_open_callbacks>
 *   @0x223cf0 subs r2, r0, #0
 *   @0x223cf4 moveq r0, #1
 *   @0x223cf8 beq 0x223d18 <_ZN10COggThread8LogErrorEPKcz+0x100>
 *   @0x223cfc cmp r5, r4
 *   @0x223d00 mov r0, r5
 *   @0x223d04 beq 0x223d18 <_ZN10COggThread8LogErrorEPKcz+0x100>
 *   @0x223d08 ldr r1, [pc, #0x14]
 *   @0x223d0c add r1, pc, r1
 *   @0x223d10 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x223d14 mov r0, r4
 *   @0x223d18 add sp, sp, #20
 *   @0x223d1c pop {r4, r5, pc}
 *   @0x223d20 ldrheq sp, [r12], -r8
 *   @0x223d24 andseq r1, r3, r4, asr #32
 *   @0x223d28 ldr r3, [pc, #0xd0]
 *   @0x223d2c push {r4, r5, r6, r7, lr}
 *   @0x223d30 ldr r3, [pc, r3]
 *   @0x223d34 sub sp, sp, #20
 *   @0x223d38 mov r6, r0
 *   @0x223d3c mov r4, r1
 *   @0x223d40 mov r7, r2
 *   @0x223d44 mov r1, r0
 *   @0x223d48 mov r2, #1
 *   @0x223d4c ldr r0, [r3]
 *   @0x223d50 blx 0x2a44b8 <zip_fopen>
 *   @0x223d54 subs r5, r0, #0
 *   @0x223d58 beq 0x223dd8 <_ZN10COggThread8LogErrorEPKcz+0x1c0>
 *   @0x223d5c ldr r3, [pc, #0xa0]
 *   @0x223d60 ldr lr, [r5, #0x18]
 *   @0x223d64 add r3, pc, r3
 *   @0x223d68 ldr r12, [r5, #0x1c]
 *   @0x223d6c str r5, [r4, #0x2c8]
 *   @0x223d70 ldm r3, {r0, r1, r2, r3}
 *   @0x223d74 str lr, [r4, #0x2cc]
 *   @0x223d78 str r12, [r4, #0x2d0]
 *   @0x223d7c stm sp, {r0, r1, r2, r3}
 *   @0x223d80 mov r2, #0
 *   @0x223d84 mov r0, r4
 *   @0x223d88 mov r1, r4
 *   @0x223d8c mov r3, r2
 *   @0x223d90 bl 0x231c48 <ov_open_callbacks>
 *   @0x223d94 subs r4, r0, #0
 *   @0x223d98 moveq r0, #1
 *   @0x223d9c bne 0x223da8 <_ZN10COggThread8LogErrorEPKcz+0x190>
 *   @0x223da0 add sp, sp, #20
 *   @0x223da4 pop {r4, r5, r6, r7, pc}
 *   @0x223da8 mov r0, r5
 *   @0x223dac blx 0x2a4388 <zip_fclose>
 *   @0x223db0 cmp r7, #0
 *   @0x223db4 beq 0x223dcc <_ZN10COggThread8LogErrorEPKcz+0x1b4>
 *   @0x223db8 ldr r1, [pc, #0x48]
 *   @0x223dbc mov r0, r7
 *   @0x223dc0 mov r2, r4
 *   @0x223dc4 add r1, pc, r1
 *   @0x223dc8 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x223dcc mov r0, #0
 *   @0x223dd0 add sp, sp, #20
 *   @0x223dd4 pop {r4, r5, r6, r7, pc}
 *   @0x223dd8 cmp r7, #0
 *   @0x223ddc beq 0x223dcc <_ZN10COggThread8LogErrorEPKcz+0x1b4>
 *   @0x223de0 ldr r1, [pc, #0x24]
 *   @0x223de4 mov r0, r7
 *   @0x223de8 mov r2, r6
 *   @0x223dec add r1, pc, r1
 *   @0x223df0 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x223df4 mov r0, r5
 *   @0x223df8 add sp, sp, #20
 *   @0x223dfc pop {r4, r5, r6, r7, pc}
 *   @0x223e00 andseq r12, r12, r4, ror #3
 *   @0x223e04 mulseq r12, r4, r1
 *   @0x223e08 andseq r0, r3, r12, lsl #31
 *   @0x223e0c andseq r0, r3, r0, lsl #31
 *   @0x223e10 push {r3, r4, r5, r6, r7, lr}
 *   @0x223e14 mov r5, r1
 *   @0x223e18 ldr r1, [pc, #0x84]
 *   @0x223e1c mov r4, r2
 *   @0x223e20 mov r7, r0
 *   @0x223e24 add r1, pc, r1
 *   @0x223e28 bl 0xb6844 <fopen@plt>
 *   @0x223e2c subs r6, r0, #0
 *   @0x223e30 beq 0x223e80 <_ZN10COggThread8LogErrorEPKcz+0x268>
 *   @0x223e34 mov r2, #0
 *   @0x223e38 mov r1, r5
 *   @0x223e3c mov r3, r2
 *   @0x223e40 bl 0x231cec <ov_open>
 *   @0x223e44 subs r5, r0, #0
 *   @0x223e48 bne 0x223e54 <_ZN10COggThread8LogErrorEPKcz+0x23c>
 *   @0x223e4c mov r0, #1
 *   @0x223e50 pop {r3, r4, r5, r6, r7, pc}
 *   @0x223e54 mov r0, r6
 *   @0x223e58 bl 0xb6850 <fclose@plt>
 *   @0x223e5c cmp r4, #0
 *   @0x223e60 beq 0x223e78 <_ZN10COggThread8LogErrorEPKcz+0x260>
 *   @0x223e64 ldr r1, [pc, #0x3c]
 *   @0x223e68 mov r0, r4
 *   @0x223e6c mov r2, r5
 *   @0x223e70 add r1, pc, r1
 *   @0x223e74 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x223e78 mov r0, #0
 *   @0x223e7c pop {r3, r4, r5, r6, r7, pc}
 *   @0x223e80 cmp r4, #0
 *   @0x223e84 beq 0x223e78 <_ZN10COggThread8LogErrorEPKcz+0x260>
 *   @0x223e88 ldr r1, [pc, #0x1c]
 *   @0x223e8c mov r0, r4
 *   @0x223e90 mov r2, r7
 *   @0x223e94 add r1, pc, r1
 *   @0x223e98 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x223e9c mov r0, r6
 *   @0x223ea0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x223ea4 ldrsbeq r3, [r1], -r4
 *   @0x223ea8 andseq r0, r3, r8, lsr pc
 *
 * ══ §30/60 JS_String_prototype_slice(RValue&, CInstance*, CInstance*, int, RValue*)  0x255638  size 504  126 条（0x255638..0x255830）
 * @func 0x255638 0x255840  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CodepointToUTF16(int, unsigned short&, unsigned short&)×2 / CCodepointIterator_UTF8::GetNext()×2 / F_JS_ToInteger(RValue&)×2 / JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0
 * 字段偏移 top8: 0xc×3 / 0x8×2 / 0x10×2 / 0x68×1 / 0x-20×1 / 0x2c×1 / 0x38×1 / 0x3c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255638 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25563c sub sp, sp, #68
 *   @0x255640 add r4, sp, #64
 *   @0x255644 mov r8, r0
 *   @0x255648 mov r3, #6
 *   @0x25564c ldr r7, [sp, #0x68]
 *   @0x255650 str r1, [r4, #-0x20]!
 *   @0x255654 mov r0, r4
 *   @0x255658 str r3, [sp, #0x2c]
 *   @0x25565c bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x255660 cmp r0, #1
 *   @0x255664 beq 0x255810 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x255668 mov r1, r4
 *   @0x25566c add r0, sp, #48
 *   @0x255670 mov r2, #0
 *   @0x255674 mov r3, #0
 *   @0x255678 mov r6, #0
 *   @0x25567c strd r2, r3, [sp, #48]
 *   @0x255680 str r6, [sp, #0x38]
 *   @0x255684 mvn r3, #-16777216
 *   @0x255688 str r3, [sp, #0x3c]
 *   @0x25568c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255690 ldr r3, [sp, #0x30]
 *   @0x255694 add r5, sp, #20
 *   @0x255698 ldr r9, [pc, #0x184]
 *   @0x25569c add r11, sp, #4
 *   @0x2556a0 mov r0, r5
 *   @0x2556a4 add r10, sp, #6
 *   @0x2556a8 ldr r1, [r3]
 *   @0x2556ac ldr r9, [pc, r9]
 *   @0x2556b0 add r3, r9, #8
 *   @0x2556b4 str r3, [sp, #0x8]
 *   @0x2556b8 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x2556bc b 0x2556c8 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x2556c0 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x2556c4 add r6, r6, r0
 *   @0x2556c8 mov r0, r5
 *   @0x2556cc bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x2556d0 mov r1, r11
 *   @0x2556d4 mov r2, r10
 *   @0x2556d8 subs r4, r0, #0
 *   @0x2556dc bne 0x2556c0 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x2556e0 lsl r10, r6, #1
 *   @0x2556e4 ldr r1, [pc, #0x13c]
 *   @0x2556e8 mov r2, #70
 *   @0x2556ec mov r3, #1
 *   @0x2556f0 add r1, pc, r1
 *   @0x2556f4 mov r0, r10
 *   @0x2556f8 str r6, [sp, #0x10]
 *   @0x2556fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x255700 mov r2, r10
 *   @0x255704 mov r1, r4
 *   @0x255708 add r10, sp, #4
 *   @0x25570c add r6, sp, #6
 *   @0x255710 str r0, [sp, #0xc]
 *   @0x255714 bl 0xb65b0 <memset@plt>
 *   @0x255718 mov r0, r5
 *   @0x25571c bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv>
 *   @0x255720 mov r0, r5
 *   @0x255724 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x255728 mov r1, r10
 *   @0x25572c mov r2, r6
 *   @0x255730 cmp r0, #0
 *   @0x255734 beq 0x255768 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x255738 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x25573c ldr r1, [sp, #0xc]
 *   @0x255740 lsl r2, r4, #1
 *   @0x255744 mov r3, r0
 *   @0x255748 cmp r0, #2
 *   @0x25574c ldrh r0, [sp, #4]
 *   @0x255750 add r4, r4, r3
 *   @0x255754 strh r0, [r1, r2]
 *   @0x255758 ldrheq r3, [sp, #6]
 *   @0x25575c addeq r2, r1, r2
 *   @0x255760 strheq r3, [r2, #2]
 *   @0x255764 b 0x255720 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x255768 mov r0, r7
 *   @0x25576c ldr r4, [sp, #0x10]
 *   @0x255770 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x255774 ldr r3, [r7, #0x1c]
 *   @0x255778 cmp r3, #5
 *   @0x25577c vmov d7, r0, r1
 *   @0x255780 moveq r0, r4
 *   @0x255784 vcvt.s32.f64 s15, d7
 *   @0x255788 vmov r5, s15
 *   @0x25578c beq 0x2557a4 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x255790 add r0, r7, #16
 *   @0x255794 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x255798 vmov d7, r0, r1
 *   @0x25579c vcvt.s32.f64 s15, d7
 *   @0x2557a0 vmov r0, s15
 *   @0x2557a4 cmp r5, #0
 *   @0x2557a8 addlt r2, r4, r5
 *   @0x2557ac biclt r2, r2, r2, asr #31
 *   @0x2557b0 blt 0x2557c0 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x2557b4 cmp r5, r4
 *   @0x2557b8 movlt r2, r5
 *   @0x2557bc movge r2, r4
 *   @0x2557c0 cmp r0, #0
 *   @0x2557c4 addlt r3, r4, r0
 *   @0x2557c8 biclt r3, r3, r3, asr #31
 *   @0x2557cc blt 0x2557dc <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x2557d0 cmp r0, r4
 *   @0x2557d4 movlt r3, r0
 *   @0x2557d8 movge r3, r4
 *   @0x2557dc rsb r3, r2, r3
 *   @0x2557e0 add r0, sp, #12
 *   @0x2557e4 mov r1, r8
 *   @0x2557e8 bic r3, r3, r3, asr #31
 *   @0x2557ec bl 0x23cea8 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x2557f0 ldr r0, [sp, #0xc]
 *   @0x2557f4 add r9, r9, #8
 *   @0x2557f8 str r9, [sp, #0x8]
 *   @0x2557fc cmp r0, #0
 *   @0x255800 beq 0x255808 <_Z25JS_String_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x255804 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x255808 add sp, sp, #68
 *   @0x25580c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x255810 ldr r0, [pc, #0x14]
 *   @0x255814 add r0, pc, r0
 *   @0x255818 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25581c add sp, sp, #68
 *   @0x255820 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x255824 andseq r11, r9, r12, asr #28
 *   @0x255828 andeq r11, sp, r0, asr #18
 *   @0x25582c andseq r0, r0, r4, lsr r7
 *
 * ══ §31/60 JS_String_GetOwnProperty(YYObjectBase*, RValue*, char const*)  0x2581ec  size 504  126 条（0x2581ec..0x2583e4）
 * @func 0x2581ec 0x2583e4  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×3 / Code_Variable_Find_Slot_From_Local_Name(char const*) / YYCreateString(RValue*, char const*) / F_JS_ToInteger(RValue&) / F_JS_ToString(RValue&, RValue*) / 0xb6574 / YYObjectBase::FindValue(char const*) / JS_String_prototype_charAt(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x8×5 / 0xc×4 / 0x4×3 / 0x14×3 / 0x34×3 / 0x30×2 / 0x28×2 / 0x10×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2581ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2581f0 vpush {d8}
 *   @0x2581f4 mov r8, r0
 *   @0x2581f8 sub sp, sp, #60
 *   @0x2581fc mov r0, r2
 *   @0x258200 mov r7, r2
 *   @0x258204 mov r6, r1
 *   @0x258208 bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc>
 *   @0x25820c cmn r0, #1
 *   @0x258210 beq 0x258264 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x78>
 *   @0x258214 ldr r2, [r8, #0x4]
 *   @0x258218 cmp r2, #0
 *   @0x25821c beq 0x2583cc <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x1e0>
 *   @0x258220 add r3, r2, r0, lsl #4
 *   @0x258224 ldr r4, [r3, #0xc]
 *   @0x258228 mvn r0, #-16777216
 *   @0x25822c ldr r12, [r3]
 *   @0x258230 ldr r1, [r3, #0x4]
 *   @0x258234 ldr r2, [r3, #0x8]
 *   @0x258238 str r4, [r6, #0xc]
 *   @0x25823c ldr r3, [r6, #0xc]
 *   @0x258240 str r12, [r6]
 *   @0x258244 cmp r3, r0
 *   @0x258248 cmpne r3, #5
 *   @0x25824c str r1, [r6, #0x4]
 *   @0x258250 str r2, [r6, #0x8]
 *   @0x258254 beq 0x258264 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x78>
 *   @0x258258 add sp, sp, #60
 *   @0x25825c vpop {d8}
 *   @0x258260 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x258264 add r4, sp, #8
 *   @0x258268 mov r1, r7
 *   @0x25826c mov r3, #5
 *   @0x258270 str r3, [sp, #0x14]
 *   @0x258274 mov r0, r4
 *   @0x258278 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x25827c mov r0, r4
 *   @0x258280 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x258284 ldr r3, [sp, #0x14]
 *   @0x258288 sub r3, r3, #1
 *   @0x25828c bic r3, r3, #-16777216
 *   @0x258290 bic r3, r3, #3
 *   @0x258294 cmp r3, #0
 *   @0x258298 vmov d7, r0, r1
 *   @0x25829c vcvt.s32.f64 s16, d7
 *   @0x2582a0 beq 0x2583b4 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x1c8>
 *   @0x2582a4 vmov r2, s16
 *   @0x2582a8 add r11, sp, #40
 *   @0x2582ac add r10, sp, #24
 *   @0x2582b0 mov r3, #0
 *   @0x2582b4 mov r0, r11
 *   @0x2582b8 mov r12, #5
 *   @0x2582bc mov r1, r10
 *   @0x2582c0 str r3, [sp, #0x10]
 *   @0x2582c4 str r3, [sp, #0x8]
 *   @0x2582c8 mov r4, #0
 *   @0x2582cc str r3, [sp, #0x24]
 *   @0x2582d0 mov r5, #0
 *   @0x2582d4 str r3, [sp, #0x30]
 *   @0x2582d8 mvn r9, #-16777216
 *   @0x2582dc str r12, [sp, #0x14]
 *   @0x2582e0 strd r4, r5, [sp, #40]
 *   @0x2582e4 str r9, [sp, #0x34]
 *   @0x2582e8 cmp r2, #0
 *   @0x2582ec rsblt r2, r2, #0
 *   @0x2582f0 vmov s14, r2
 *   @0x2582f4 vcvt.f64.s32 d7, s14
 *   @0x2582f8 vstr d7, [sp, #24]
 *   @0x2582fc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x258300 ldr r3, [sp, #0x28]
 *   @0x258304 mov r1, r7
 *   @0x258308 ldr r0, [r3]
 *   @0x25830c bl 0xb6574 <strcmp@plt>
 *   @0x258310 ldr r3, [sp, #0x34]
 *   @0x258314 cmp r0, #0
 *   @0x258318 bne 0x258390 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x1a4>
 *   @0x25831c sub r3, r3, #1
 *   @0x258320 bic r3, r3, #-16777216
 *   @0x258324 bic r3, r3, #3
 *   @0x258328 cmp r3, #0
 *   @0x25832c beq 0x2583c0 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x1d4>
 *   @0x258330 ldr r1, [pc, #0xa8]
 *   @0x258334 mov r0, r8
 *   @0x258338 mov r4, #0
 *   @0x25833c mov r5, #5
 *   @0x258340 add r1, pc, r1
 *   @0x258344 str r4, [sp, #0x30]
 *   @0x258348 str r4, [sp, #0x28]
 *   @0x25834c str r5, [sp, #0x34]
 *   @0x258350 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x258354 vmov r2, s16
 *   @0x258358 ldr r3, [r0]
 *   @0x25835c ldr r3, [r3, #0x8]
 *   @0x258360 cmp r2, r3
 *   @0x258364 strge r5, [r6, #0xc]
 *   @0x258368 bge 0x258258 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x6c>
 *   @0x25836c mov r3, #1
 *   @0x258370 str r10, [sp]
 *   @0x258374 mov r1, r8
 *   @0x258378 mov r2, r4
 *   @0x25837c mov r0, r6
 *   @0x258380 bl 0x25540c <_Z26JS_String_prototype_charAtR6RValueP9CInstanceS2_iPS_>
 *   @0x258384 mov r3, #1
 *   @0x258388 str r3, [r6, #0x8]
 *   @0x25838c b 0x258258 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x6c>
 *   @0x258390 sub r3, r3, #1
 *   @0x258394 str r9, [r6, #0xc]
 *   @0x258398 and r3, r3, r9
 *   @0x25839c bic r3, r3, #3
 *   @0x2583a0 cmp r3, #0
 *   @0x2583a4 bne 0x258258 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x6c>
 *   @0x2583a8 mov r0, r11
 *   @0x2583ac bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2583b0 b 0x258258 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x6c>
 *   @0x2583b4 mov r0, r4
 *   @0x2583b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2583bc b 0x2582a4 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0xb8>
 *   @0x2583c0 mov r0, r11
 *   @0x2583c4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2583c8 b 0x258330 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x144>
 *   @0x2583cc mov r1, r0
 *   @0x2583d0 mov r0, r8
 *   @0x2583d4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2583d8 mov r3, r0
 *   @0x2583dc b 0x258224 <_Z24JS_String_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x38>
 *   @0x2583e0 andeq lr, pc, r12, lsl #16
 *
 * ══ §32/60 b2RopeJoint::SolvePositionConstraints(b2SolverData const&)  0x2d264c  size 504  126 条（0x2d264c..0x2d2844）
 * @func 0x2d264c 0x2d2844  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / 0xb6700 / 0xfebc8470
 * 字段偏移 top8: 0x60×2 / 0x64×2 / 0x18×2
 * VFP 指令 94 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d264c push {r4, r5, r6, r7, r8, lr}
 *   @0x2d2650 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2d2654 mov r4, r0
 *   @0x2d2658 ldr r7, [r0, #0x60]
 *   @0x2d265c mov r8, r1
 *   @0x2d2660 ldr r6, [r0, #0x64]
 *   @0x2d2664 ldr r5, [r1, #0x18]
 *   @0x2d2668 add r2, r7, r7, lsl #1
 *   @0x2d266c add r3, r6, r6, lsl #1
 *   @0x2d2670 add r2, r5, r2, lsl #2
 *   @0x2d2674 vldr s23, [r2, #8]
 *   @0x2d2678 vmov r0, s23
 *   @0x2d267c add r3, r5, r3, lsl #2
 *   @0x2d2680 vldr s27, [r2]
 *   @0x2d2684 vldr s22, [r3, #8]
 *   @0x2d2688 vldr s26, [r2, #4]
 *   @0x2d268c vldr s25, [r3]
 *   @0x2d2690 vldr s24, [r3, #4]
 *   @0x2d2694 bl 0xb6580 <sinf@plt>
 *   @0x2d2698 vmov s16, r0
 *   @0x2d269c vmov r0, s23
 *   @0x2d26a0 bl 0xb658c <cosf@plt>
 *   @0x2d26a4 vmov s17, r0
 *   @0x2d26a8 vmov r0, s22
 *   @0x2d26ac bl 0xb6580 <sinf@plt>
 *   @0x2d26b0 vmov s21, r0
 *   @0x2d26b4 vmov r0, s22
 *   @0x2d26b8 bl 0xb658c <cosf@plt>
 *   @0x2d26bc vldr s15, [r4, #140]
 *   @0x2d26c0 vldr s18, [r4, #80]
 *   @0x2d26c4 vsub.f32 s18, s18, s15
 *   @0x2d26c8 vldr s10, [r4, #76]
 *   @0x2d26cc vldr s13, [r4, #136]
 *   @0x2d26d0 vldr s19, [r4, #72]
 *   @0x2d26d4 vldr s11, [r4, #132]
 *   @0x2d26d8 vldr s12, [r4, #68]
 *   @0x2d26dc vldr s15, [r4, #128]
 *   @0x2d26e0 vsub.f32 s13, s10, s13
 *   @0x2d26e4 vsub.f32 s19, s19, s11
 *   @0x2d26e8 vsub.f32 s15, s12, s15
 *   @0x2d26ec vmov s14, r0
 *   @0x2d26f0 vmul.f32 s20, s18, s14
 *   @0x2d26f4 vmul.f32 s18, s18, s21
 *   @0x2d26f8 vmla.f32 s20, s13, s21
 *   @0x2d26fc vmul.f32 s21, s19, s17
 *   @0x2d2700 vnmls.f32 s18, s13, s14
 *   @0x2d2704 vmla.f32 s21, s15, s16
 *   @0x2d2708 vmul.f32 s19, s19, s16
 *   @0x2d270c vadd.f32 s16, s24, s20
 *   @0x2d2710 vsub.f32 s16, s16, s26
 *   @0x2d2714 vnmls.f32 s19, s15, s17
 *   @0x2d2718 vadd.f32 s17, s25, s18
 *   @0x2d271c vsub.f32 s16, s16, s21
 *   @0x2d2720 vsub.f32 s17, s17, s27
 *   @0x2d2724 vmul.f32 s14, s16, s16
 *   @0x2d2728 vsub.f32 s17, s17, s19
 *   @0x2d272c vmla.f32 s14, s17, s17
 *   @0x2d2730 vsqrt.f32 s15, s14
 *   @0x2d2734 vcmp.f32 s15, s15
 *   @0x2d2738 vmrs APSR_nzcv, fpscr
 *   @0x2d273c bne 0x2d2818 <_ZN11b2RopeJoint24SolvePositionConstraintsERK12b2SolverData+0x1cc>
 *   @0x2d2740 vldr s14, [pc, #236]
 *   @0x2d2744 vcmpe.f32 s15, s14
 *   @0x2d2748 vldr s12, [pc, #232]
 *   @0x2d274c vmrs APSR_nzcv, fpscr
 *   @0x2d2750 vmovpl.f32 s13, #1.000000e+00
 *   @0x2d2754 vldrmi s14, [pc, #224]
 *   @0x2d2758 vmovpl.f32 s14, s15
 *   @0x2d275c vdivpl.f32 s15, s13, s15
 *   @0x2d2760 vmulpl.f32 s17, s17, s15
 *   @0x2d2764 vmulpl.f32 s16, s16, s15
 *   @0x2d2768 vldr s15, [r4, #84]
 *   @0x2d276c vsub.f32 s15, s14, s15
 *   @0x2d2770 vcmpe.f32 s15, s12
 *   @0x2d2774 vmrs APSR_nzcv, fpscr
 *   @0x2d2778 bpl 0x2d278c <_ZN11b2RopeJoint24SolvePositionConstraintsERK12b2SolverData+0x140>
 *   @0x2d277c vcmpe.f32 s15, #0
 *   @0x2d2780 vmrs APSR_nzcv, fpscr
 *   @0x2d2784 vmovpl.f32 s12, s15
 *   @0x2d2788 vldrmi s12, [pc, #172]
 *   @0x2d278c vldr s14, [r4, #160]
 *   @0x2d2790 vldr s13, [r4, #144]
 *   @0x2d2794 vnmul.f32 s12, s14, s12
 *   @0x2d2798 vldr s9, [r4, #152]
 *   @0x2d279c vldr s14, [r4, #148]
 *   @0x2d27a0 vldr s10, [r4, #156]
 *   @0x2d27a4 add r7, r7, r7, lsl #1
 *   @0x2d27a8 add r6, r6, r6, lsl #1
 *   @0x2d27ac vldr s11, [pc, #140]
 *   @0x2d27b0 add r7, r5, r7, lsl #2
 *   @0x2d27b4 add r5, r5, r6, lsl #2
 *   @0x2d27b8 vmul.f32 s17, s12, s17
 *   @0x2d27bc vmul.f32 s16, s12, s16
 *   @0x2d27c0 vmul.f32 s21, s21, s17
 *   @0x2d27c4 vmul.f32 s20, s20, s17
 *   @0x2d27c8 vnmls.f32 s21, s19, s16
 *   @0x2d27cc vnmls.f32 s20, s18, s16
 *   @0x2d27d0 vmls.f32 s27, s13, s17
 *   @0x2d27d4 vmls.f32 s26, s13, s16
 *   @0x2d27d8 vstr s27, [r7]
 *   @0x2d27dc vmls.f32 s23, s21, s9
 *   @0x2d27e0 vstr s26, [r7, #4]
 *   @0x2d27e4 vmla.f32 s25, s14, s17
 *   @0x2d27e8 vstr s23, [r7, #8]
 *   @0x2d27ec vmla.f32 s24, s14, s16
 *   @0x2d27f0 vstr s25, [r5]
 *   @0x2d27f4 vmla.f32 s22, s20, s10
 *   @0x2d27f8 vstr s24, [r5, #4]
 *   @0x2d27fc vstr s22, [r5, #8]
 *   @0x2d2800 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2d2804 vcmpe.f32 s15, s11
 *   @0x2d2808 vmrs APSR_nzcv, fpscr
 *   @0x2d280c movpl r0, #0
 *   @0x2d2810 movmi r0, #1
 *   @0x2d2814 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2d2818 vmov r0, s14
 *   @0x2d281c bl 0xb6700 <sqrtf@plt>
 *   @0x2d2820 ldr r5, [r8, #0x18]
 *   @0x2d2824 ldr r7, [r4, #0x60]
 *   @0x2d2828 ldr r6, [r4, #0x64]
 *   @0x2d282c vmov s15, r0
 *   @0x2d2830 b 0x2d2740 <_ZN11b2RopeJoint24SolvePositionConstraintsERK12b2SolverData+0xf4>
 *   @0x2d2834 strlo r0, [r0], #-0
 *   @0x2d2838 cdplo p12, #0x4, c12, c12, c13, #0x6
 *   @0x2d283c andeq r0, r0, r0
 *   @0x2d2840 bllo 0xfebc8470 <b2_toiTime+0xfffffffffe46efcc>
 *
 * ══ §33/60 Code_Variable_Init(int, int, int)  0xd1d80  size 500  125 条（0xd1d80..0xd1f74）
 * @func 0xd1d80 0xd1f74  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×6 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0 / Code_Variable_Init(int, int, int)+0x184
 * 字段偏移 top8: 0xc×12 / 0x4×7 / 0x10×3 / 0x8×2 / 0x1cc×1 / 0x17c×1 / 0x15c×1 / 0x114×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1d80 push {r4, r5, r6, r7, lr}
 *   @0xd1d84 mov r6, r0
 *   @0xd1d88 ldr r4, [pc, #0x1cc]
 *   @0xd1d8c sub sp, sp, #12
 *   @0xd1d90 mov r5, r1
 *   @0xd1d94 ldr r4, [pc, r4]
 *   @0xd1d98 ldr r3, [r4]
 *   @0xd1d9c cmp r3, #0
 *   @0xd1da0 beq 0xd1dc8 <_Z18Code_Variable_Initiii+0x48>
 *   @0xd1da4 ldr r7, [r4, #0xc]
 *   @0xd1da8 subs r0, r7, #0
 *   @0xd1dac beq 0xd1f28 <_Z18Code_Variable_Initiii+0x1a8>
 *   @0xd1db0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1db4 mov r3, #0
 *   @0xd1db8 str r3, [r4, #0xc]
 *   @0xd1dbc str r3, [r4, #0x4]
 *   @0xd1dc0 mov r3, #0
 *   @0xd1dc4 str r3, [r4]
 *   @0xd1dc8 cmp r6, #0
 *   @0xd1dcc beq 0xd1e00 <_Z18Code_Variable_Initiii+0x80>
 *   @0xd1dd0 lsls r7, r6, #2
 *   @0xd1dd4 ldr r0, [r4, #0xc]
 *   @0xd1dd8 beq 0xd1f48 <_Z18Code_Variable_Initiii+0x1c8>
 *   @0xd1ddc ldr r2, [pc, #0x17c]
 *   @0xd1de0 mov r3, #0
 *   @0xd1de4 mov r1, r7
 *   @0xd1de8 str r3, [sp]
 *   @0xd1dec add r2, pc, r2
 *   @0xd1df0 movw r3, #0x11b
 *   @0xd1df4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd1df8 str r0, [r4, #0xc]
 *   @0xd1dfc str r6, [r4]
 *   @0xd1e00 ldr r4, [pc, #0x15c]
 *   @0xd1e04 ldr r4, [pc, r4]
 *   @0xd1e08 ldr r3, [r4]
 *   @0xd1e0c cmp r3, #0
 *   @0xd1e10 beq 0xd1e38 <_Z18Code_Variable_Initiii+0xb8>
 *   @0xd1e14 ldr r6, [r4, #0xc]
 *   @0xd1e18 subs r0, r6, #0
 *   @0xd1e1c beq 0xd1f18 <_Z18Code_Variable_Initiii+0x198>
 *   @0xd1e20 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1e24 mov r3, #0
 *   @0xd1e28 str r3, [r4, #0xc]
 *   @0xd1e2c str r3, [r4, #0x4]
 *   @0xd1e30 mov r3, #0
 *   @0xd1e34 str r3, [r4]
 *   @0xd1e38 cmp r5, #0
 *   @0xd1e3c beq 0xd1e70 <_Z18Code_Variable_Initiii+0xf0>
 *   @0xd1e40 lsls r6, r5, #2
 *   @0xd1e44 ldr r0, [r4, #0xc]
 *   @0xd1e48 beq 0xd1f38 <_Z18Code_Variable_Initiii+0x1b8>
 *   @0xd1e4c ldr r2, [pc, #0x114]
 *   @0xd1e50 mov r3, #0
 *   @0xd1e54 mov r1, r6
 *   @0xd1e58 str r3, [sp]
 *   @0xd1e5c add r2, pc, r2
 *   @0xd1e60 movw r3, #0x11b
 *   @0xd1e64 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd1e68 str r0, [r4, #0xc]
 *   @0xd1e6c str r5, [r4]
 *   @0xd1e70 mov r0, #20
 *   @0xd1e74 mov r5, #0
 *   @0xd1e78 bl 0x27c524 <_Znwj>
 *   @0xd1e7c ldr r1, [pc, #0xe8]
 *   @0xd1e80 mov r2, #128
 *   @0xd1e84 mov r3, #127
 *   @0xd1e88 add r1, pc, r1
 *   @0xd1e8c mov r4, r0
 *   @0xd1e90 str r2, [r0]
 *   @0xd1e94 str r3, [r4, #0x8]
 *   @0xd1e98 mov r2, #70
 *   @0xd1e9c mov r3, #1
 *   @0xd1ea0 mov r0, #1536
 *   @0xd1ea4 str r5, [r4, #0x10]
 *   @0xd1ea8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd1eac mov r2, #1536
 *   @0xd1eb0 mov r1, r5
 *   @0xd1eb4 str r0, [r4, #0x10]
 *   @0xd1eb8 bl 0xb65b0 <memset@plt>
 *   @0xd1ebc ldr r2, [r4]
 *   @0xd1ec0 vldr s15, [pc, #144]
 *   @0xd1ec4 str r5, [r4, #0x4]
 *   @0xd1ec8 cmp r2, r5
 *   @0xd1ecc vmov s13, r2
 *   @0xd1ed0 vcvt.f32.s32 s14, s13
 *   @0xd1ed4 vmul.f32 s15, s14, s15
 *   @0xd1ed8 vcvt.s32.f32 s15, s15
 *   @0xd1edc vstr s15, [r4, #12]
 *   @0xd1ee0 ble 0xd1f04 <_Z18Code_Variable_Initiii+0x184>
 *   @0xd1ee4 add r2, r2, r2, lsl #1
 *   @0xd1ee8 ldr r3, [r4, #0x10]
 *   @0xd1eec mov r1, r5
 *   @0xd1ef0 add r2, r3, r2, lsl #2
 *   @0xd1ef4 str r1, [r3, #0x8]
 *   @0xd1ef8 add r3, r3, #12
 *   @0xd1efc cmp r3, r2
 *   @0xd1f00 bne 0xd1ef4 <_Z18Code_Variable_Initiii+0x174>
 *   @0xd1f04 ldr r3, [pc, #0x64]
 *   @0xd1f08 ldr r3, [pc, r3]
 *   @0xd1f0c str r4, [r3]
 *   @0xd1f10 add sp, sp, #12
 *   @0xd1f14 pop {r4, r5, r6, r7, pc}
 *   @0xd1f18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1f1c str r6, [r4, #0xc]
 *   @0xd1f20 str r6, [r4, #0x4]
 *   @0xd1f24 b 0xd1e30 <_Z18Code_Variable_Initiii+0xb0>
 *   @0xd1f28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1f2c str r7, [r4, #0xc]
 *   @0xd1f30 str r7, [r4, #0x4]
 *   @0xd1f34 b 0xd1dc0 <_Z18Code_Variable_Initiii+0x40>
 *   @0xd1f38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1f3c str r6, [r4, #0xc]
 *   @0xd1f40 str r6, [r4, #0x4]
 *   @0xd1f44 b 0xd1e6c <_Z18Code_Variable_Initiii+0xec>
 *   @0xd1f48 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1f4c str r7, [r4, #0xc]
 *   @0xd1f50 str r7, [r4, #0x4]
 *   @0xd1f54 b 0xd1dfc <_Z18Code_Variable_Initiii+0x7c>
 *   @0xd1f58 svclo #0x19999a
 *   @0xd1f5c eorseq r11, r1, r8, lsl #28
 *   @0xd1f60 .word 0x002608f4
 *   @0xd1f64 mlaseq r1, r12, sp, r11
 *   @0xd1f68 eoreq r0, r6, r4, lsl #17
 *   @0xd1f6c eoreq pc, r5, r8, lsr #3
 *   @0xd1f70 mlaseq r1, r12, r12, r11
 *
 * ══ §34/60 F_SpriteCreateFromScreen(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b778  size 500  125 条（0x12b778..0x12b96c）
 * @func 0x12b778 0x12b96c  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×14 / Sprite_Data(int)×2 / CSprite::CreateFromBitmap(IBitmap*, bool, bool, bool, bool, int, int, bool)×2 / Sprite_AddEmpty() / GR_D3D_Screenshot_Part(int, int, int, int)
 * 字段偏移 top8: 0xc×3 / 0x1c×2 / 0x8×2 / 0x10×2 / 0x4×2 / 0x48×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12b77c sub sp, sp, #36
 *   @0x12b780 mov r6, #0
 *   @0x12b784 str r6, [r0, #0xc]
 *   @0x12b788 ldr r4, [sp, #0x48]
 *   @0x12b78c mov r5, r0
 *   @0x12b790 mov r8, r3
 *   @0x12b794 bl 0x1ef890 <_Z15Sprite_AddEmptyv>
 *   @0x12b798 mov r1, r6
 *   @0x12b79c vmov s15, r0
 *   @0x12b7a0 mov r7, r0
 *   @0x12b7a4 mov r0, r4
 *   @0x12b7a8 vcvt.f64.s32 d7, s15
 *   @0x12b7ac vmov r2, r3, d7
 *   @0x12b7b0 stm r5, {r2, r3}
 *   @0x12b7b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b7b8 mov r1, #1
 *   @0x12b7bc mov r10, r0
 *   @0x12b7c0 mov r0, r4
 *   @0x12b7c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b7c8 mov r1, #2
 *   @0x12b7cc mov r9, r0
 *   @0x12b7d0 mov r0, r4
 *   @0x12b7d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b7d8 mov r1, #3
 *   @0x12b7dc mov r5, r0
 *   @0x12b7e0 mov r0, r4
 *   @0x12b7e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b7e8 mov r2, r5
 *   @0x12b7ec mov r1, r9
 *   @0x12b7f0 mov r3, r0
 *   @0x12b7f4 mov r0, r10
 *   @0x12b7f8 bl 0x169b34 <_Z22GR_D3D_Screenshot_Partiiii>
 *   @0x12b7fc subs r5, r0, #0
 *   @0x12b800 beq 0x12b8d8 <_Z24F_SpriteCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x12b804 cmp r8, #8
 *   @0x12b808 beq 0x12b8e0 <_Z24F_SpriteCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x12b80c mov r0, r7
 *   @0x12b810 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b814 mov r1, #4
 *   @0x12b818 mov r7, r0
 *   @0x12b81c mov r0, r4
 *   @0x12b820 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b824 mov r1, #5
 *   @0x12b828 mov r10, r0
 *   @0x12b82c mov r0, r4
 *   @0x12b830 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b834 mov r1, #6
 *   @0x12b838 mov r8, r0
 *   @0x12b83c mov r0, r4
 *   @0x12b840 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b844 mov r1, #7
 *   @0x12b848 mov r3, r0
 *   @0x12b84c mov r0, r4
 *   @0x12b850 str r3, [sp, #0x1c]
 *   @0x12b854 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b858 mov r1, #8
 *   @0x12b85c mov r11, r0
 *   @0x12b860 mov r0, r4
 *   @0x12b864 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b868 mov r1, #9
 *   @0x12b86c mov r9, r0
 *   @0x12b870 mov r0, r4
 *   @0x12b874 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b878 ldr r3, [sp, #0x1c]
 *   @0x12b87c str r9, [sp, #0x8]
 *   @0x12b880 mov r1, r5
 *   @0x12b884 cmp r3, #0
 *   @0x12b888 str r6, [sp, #0x10]
 *   @0x12b88c movle r3, #0
 *   @0x12b890 movgt r3, #1
 *   @0x12b894 cmp r11, #0
 *   @0x12b898 movle r11, #0
 *   @0x12b89c movgt r11, #1
 *   @0x12b8a0 cmp r10, #0
 *   @0x12b8a4 stm sp, {r3, r11}
 *   @0x12b8a8 movle r2, #0
 *   @0x12b8ac movgt r2, #1
 *   @0x12b8b0 cmp r8, #0
 *   @0x12b8b4 movle r3, #0
 *   @0x12b8b8 movgt r3, #1
 *   @0x12b8bc str r0, [sp, #0xc]
 *   @0x12b8c0 mov r0, r7
 *   @0x12b8c4 bl 0x1e74ac <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib>
 *   @0x12b8c8 ldr r3, [r5]
 *   @0x12b8cc mov r0, r5
 *   @0x12b8d0 ldr r3, [r3, #0x4]
 *   @0x12b8d4 blx r3
 *   @0x12b8d8 add sp, sp, #36
 *   @0x12b8dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x12b8e0 mov r1, #4
 *   @0x12b8e4 mov r0, r4
 *   @0x12b8e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b8ec cmp r0, r6
 *   @0x12b8f0 mov r0, r7
 *   @0x12b8f4 movle r6, #0
 *   @0x12b8f8 movgt r6, #1
 *   @0x12b8fc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b900 mov r1, #5
 *   @0x12b904 mov r7, r0
 *   @0x12b908 mov r0, r4
 *   @0x12b90c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b910 mov r1, #6
 *   @0x12b914 mov r9, r0
 *   @0x12b918 mov r0, r4
 *   @0x12b91c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b920 mov r1, #7
 *   @0x12b924 mov r8, r0
 *   @0x12b928 mov r0, r4
 *   @0x12b92c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b930 cmp r9, #0
 *   @0x12b934 mov r2, #1
 *   @0x12b938 str r8, [sp, #0x8]
 *   @0x12b93c eor r1, r6, r2
 *   @0x12b940 movle r9, #0
 *   @0x12b944 movgt r9, #1
 *   @0x12b948 str r1, [sp, #0x10]
 *   @0x12b94c str r9, [sp]
 *   @0x12b950 mov r3, r6
 *   @0x12b954 str r2, [sp, #0x4]
 *   @0x12b958 mov r1, r5
 *   @0x12b95c str r0, [sp, #0xc]
 *   @0x12b960 mov r0, r7
 *   @0x12b964 bl 0x1e74ac <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib>
 *   @0x12b968 b 0x12b8c8 <_Z24F_SpriteCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x150>
 *
 * ══ §35/60 F_LayerDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bbeec  size 500  125 条（0x1bbeec..0x1bc0e0）
 * @func 0x1bbeec 0x1bc0e0  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::ChangeLayerDepth(CRoom*, CLayer*, int, bool) / F_LayerDepth(RValue&, CInstance*, CInstance*, int, RValue*)+0x154 / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×5 / 0xc×3 / 0x58×3 / 0x8×3 / 0x14×2 / 0x28×1 / 0x1ac×1 / 0x11c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bbeec push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1bbef0 cmp r3, #2
 *   @0x1bbef4 sub sp, sp, #8
 *   @0x1bbef8 mov r3, #0
 *   @0x1bbefc mov r4, r3
 *   @0x1bbf00 movt r3, #0xbff0
 *   @0x1bbf04 str r4, [r0, #0xc]
 *   @0x1bbf08 str r3, [r0, #0x4]
 *   @0x1bbf0c str r4, [r0]
 *   @0x1bbf10 ldr r5, [sp, #0x28]
 *   @0x1bbf14 beq 0x1bbf30 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1bbf18 ldr r0, [pc, #0x1ac]
 *   @0x1bbf1c mov r1, r4
 *   @0x1bbf20 add r0, pc, r0
 *   @0x1bbf24 add sp, sp, #8
 *   @0x1bbf28 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1bbf2c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bbf30 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bbf34 subs r6, r0, #0
 *   @0x1bbf38 beq 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x1bbf3c ldr r3, [r5, #0xc]
 *   @0x1bbf40 mov r1, r4
 *   @0x1bbf44 mov r0, r5
 *   @0x1bbf48 bic r3, r3, #-16777216
 *   @0x1bbf4c cmp r3, #1
 *   @0x1bbf50 beq 0x1bc060 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x1bbf54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bbf58 mov r1, r0
 *   @0x1bbf5c mov r0, r6
 *   @0x1bbf60 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bbf64 mov r4, r0
 *   @0x1bbf68 cmp r4, #0
 *   @0x1bbf6c beq 0x1bc078 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x1bbf70 mov r0, r5
 *   @0x1bbf74 mov r1, #1
 *   @0x1bbf78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bbf7c ldr r3, [r4, #0x4]
 *   @0x1bbf80 cmp r3, r0
 *   @0x1bbf84 mov r8, r0
 *   @0x1bbf88 beq 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x1bbf8c mov r1, r4
 *   @0x1bbf90 mov r0, r6
 *   @0x1bbf94 mov r2, r8
 *   @0x1bbf98 mov r3, #0
 *   @0x1bbf9c bl 0x1b8200 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib>
 *   @0x1bbfa0 ldr r4, [r4, #0x58]
 *   @0x1bbfa4 cmp r4, #0
 *   @0x1bbfa8 beq 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x1bbfac ldr r10, [pc, #0x11c]
 *   @0x1bbfb0 mov r9, #0
 *   @0x1bbfb4 add r10, pc, r10
 *   @0x1bbfb8 b 0x1bbfc8 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x1bbfbc ldr r4, [r4, #0x14]
 *   @0x1bbfc0 cmp r4, #0
 *   @0x1bbfc4 beq 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x1bbfc8 ldr r3, [r4]
 *   @0x1bbfcc cmp r3, #2
 *   @0x1bbfd0 bne 0x1bbfbc <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x1bbfd4 ldr r6, [r4, #0x20]
 *   @0x1bbfd8 cmp r6, #0
 *   @0x1bbfdc beq 0x1bbfbc <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x1bbfe0 vmov s14, r8
 *   @0x1bbfe4 ldr r7, [pc, #0xe8]
 *   @0x1bbfe8 vcvt.f32.s32 s15, s14
 *   @0x1bbfec ldr r7, [pc, r7]
 *   @0x1bbff0 ldr r1, [r7, #0x8]
 *   @0x1bbff4 ldr r3, [r7, #0x4]
 *   @0x1bbff8 cmp r1, r3
 *   @0x1bbffc vstr s15, [r6, #384]
 *   @0x1bc000 beq 0x1bc09c <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x1bc004 ldr r2, [r7]
 *   @0x1bc008 cmp r1, #0
 *   @0x1bc00c ble 0x1bc040 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1bc010 ldr r3, [r2]
 *   @0x1bc014 cmp r6, r3
 *   @0x1bc018 beq 0x1bbfbc <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x1bc01c mov r12, r2
 *   @0x1bc020 mov r3, #0
 *   @0x1bc024 b 0x1bc034 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x1bc028 ldr r5, [r12, #0x4]!
 *   @0x1bc02c cmp r6, r5
 *   @0x1bc030 beq 0x1bbfbc <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x1bc034 add r3, r3, #1
 *   @0x1bc038 cmp r3, r1
 *   @0x1bc03c bne 0x1bc028 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1bc040 str r6, [r2, r1, lsl #2]
 *   @0x1bc044 add r1, r1, #1
 *   @0x1bc048 ldr r4, [r4, #0x14]
 *   @0x1bc04c str r1, [r7, #0x8]
 *   @0x1bc050 cmp r4, #0
 *   @0x1bc054 bne 0x1bbfc8 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x1bc058 add sp, sp, #8
 *   @0x1bc05c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bc060 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bc064 mov r1, r0
 *   @0x1bc068 mov r0, r6
 *   @0x1bc06c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bc070 mov r4, r0
 *   @0x1bc074 b 0x1bbf68 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1bc078 ldr r3, [pc, #0x58]
 *   @0x1bc07c ldr r1, [pc, #0x58]
 *   @0x1bc080 ldr r3, [pc, r3]
 *   @0x1bc084 add r1, pc, r1
 *   @0x1bc088 ldr r0, [r3]
 *   @0x1bc08c ldr r3, [r0]
 *   @0x1bc090 ldr r3, [r3, #0xc]
 *   @0x1bc094 blx r3
 *   @0x1bc098 b 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x1bc09c lsl r3, r1, #1
 *   @0x1bc0a0 ldr r0, [r7]
 *   @0x1bc0a4 str r3, [r7, #0x4]
 *   @0x1bc0a8 lsl r1, r1, #3
 *   @0x1bc0ac mov r2, r10
 *   @0x1bc0b0 str r9, [sp]
 *   @0x1bc0b4 mov r3, #74
 *   @0x1bc0b8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1bc0bc ldr r1, [r7, #0x8]
 *   @0x1bc0c0 mov r2, r0
 *   @0x1bc0c4 str r0, [r7]
 *   @0x1bc0c8 b 0x1bc008 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1bc0cc andseq r1, r9, r12, ror lr
 *   @0x1bc0d0 andseq r5, r7, r12, ror r0
 *   @0x1bc0d4 strhteq r2, [r3], -r8
 *   @0x1bc0d8 mlaeq r3, r4, r6, r1
 *   @0x1bc0dc andseq r1, r9, r4, asr #26
 *
 * ══ §36/60 CSprite::DrawStretched(int, float, float, float, float, unsigned int, float)  0x1ecdc4  size 500  125 条（0x1ecdc4..0x1ecfb8）
 * @func 0x1ecdc4 0x1ecfb8  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::DrawStretched(int, float, float, float, float, unsigned int, float)+0xe0×5 / __aeabi_idivmod / GR_Texture_Draw(YYTPageEntry*, float, float, float, float, float, float, float, unsigned int, float) / GR_Texture_Draw(int, float, float, float, float, float, float, float, unsigned int, float) / CSprite::DrawSWF(int, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x50×4 / 0xc×4 / 0x10×3 / 0x2×2 / 0xf0×2 / 0x5c×2 / 0x7c×2 / 0x18×1
 * VFP 指令 39 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ecdc4 ldr r12, [r0, #0x18]
 *   @0x1ecdc8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1ecdcc vpush {d8}
 *   @0x1ecdd0 cmp r12, #0
 *   @0x1ecdd4 sub sp, sp, #36
 *   @0x1ecdd8 mov r4, r0
 *   @0x1ecddc mov r8, r2
 *   @0x1ecde0 mov r7, r3
 *   @0x1ecde4 vldr s16, [sp, #72]
 *   @0x1ecde8 ble 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1ecdec vcmpe.f32 s16, #0
 *   @0x1ecdf0 mov r5, #0
 *   @0x1ecdf4 vmrs APSR_nzcv, fpscr
 *   @0x1ecdf8 bls 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1ecdfc vldr s13, [sp, #76]
 *   @0x1ece00 vcmpe.f32 s13, #0
 *   @0x1ece04 vmrs APSR_nzcv, fpscr
 *   @0x1ece08 bls 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1ece0c ldr r6, [r0, #0x1c]
 *   @0x1ece10 cmp r6, #0
 *   @0x1ece14 ble 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1ece18 ldr r9, [r0, #0x20]
 *   @0x1ece1c cmp r9, #0
 *   @0x1ece20 ble 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1ece24 mov r0, r1
 *   @0x1ece28 mov r1, r12
 *   @0x1ece2c bl 0x318dec <__aeabi_idivmod>
 *   @0x1ece30 ldr r3, [r4, #0x74]
 *   @0x1ece34 cmp r3, #1
 *   @0x1ece38 mov r2, r1
 *   @0x1ece3c beq 0x1ecf54 <_ZN7CSprite13DrawStretchedEiffffjf+0x190>
 *   @0x1ece40 ldr r3, [r4, #0x54]
 *   @0x1ece44 vmov s15, r6
 *   @0x1ece48 cmp r3, #0
 *   @0x1ece4c vcvt.f32.s32 s14, s15
 *   @0x1ece50 beq 0x1eced8 <_ZN7CSprite13DrawStretchedEiffffjf+0x114>
 *   @0x1ece54 ldr r0, [r3, r1, lsl #2]
 *   @0x1ece58 vldr s13, [sp, #84]
 *   @0x1ece5c vstr s13, [sp, #20]
 *   @0x1ece60 vmov s13, r9
 *   @0x1ece64 ldr r2, [sp, #0x50]
 *   @0x1ece68 mov r1, r5
 *   @0x1ece6c vcvt.f32.s32 s15, s13
 *   @0x1ece70 str r7, [sp]
 *   @0x1ece74 str r5, [sp, #0xc]
 *   @0x1ece78 mov r3, r8
 *   @0x1ece7c str r2, [sp, #0x10]
 *   @0x1ece80 mov r2, r5
 *   @0x1ece84 vdiv.f32 s16, s16, s14
 *   @0x1ece88 vldr s14, [sp, #76]
 *   @0x1ece8c vdiv.f32 s15, s14, s15
 *   @0x1ece90 vstr s16, [sp, #4]
 *   @0x1ece94 vstr s15, [sp, #8]
 *   @0x1ece98 bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf>
 *   @0x1ece9c cmp r0, #0
 *   @0x1ecea0 beq 0x1eceb0 <_ZN7CSprite13DrawStretchedEiffffjf+0xec>
 *   @0x1ecea4 add sp, sp, #36
 *   @0x1ecea8 vpop {d8}
 *   @0x1eceac pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1eceb0 ldr r3, [pc, #0xf0]
 *   @0x1eceb4 ldr r1, [pc, #0xf0]
 *   @0x1eceb8 ldr r3, [pc, r3]
 *   @0x1ecebc ldr r2, [r4, #0x5c]
 *   @0x1ecec0 add r1, pc, r1
 *   @0x1ecec4 ldr r0, [r3]
 *   @0x1ecec8 ldr r3, [r0]
 *   @0x1ececc ldr r3, [r3, #0xc]
 *   @0x1eced0 blx r3
 *   @0x1eced4 b 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1eced8 ldr r0, [r4, #0x50]
 *   @0x1ecedc vldr s13, [sp, #84]
 *   @0x1ecee0 vdiv.f32 s16, s16, s14
 *   @0x1ecee4 vldr s14, [sp, #76]
 *   @0x1ecee8 mov r1, r5
 *   @0x1eceec mov r3, r8
 *   @0x1ecef0 ldr r0, [r0, r2, lsl #2]
 *   @0x1ecef4 vstr s13, [sp, #20]
 *   @0x1ecef8 vmov s13, r9
 *   @0x1ecefc ldr r2, [sp, #0x50]
 *   @0x1ecf00 str r7, [sp]
 *   @0x1ecf04 str r5, [sp, #0xc]
 *   @0x1ecf08 str r2, [sp, #0x10]
 *   @0x1ecf0c mov r2, r5
 *   @0x1ecf10 vcvt.f32.s32 s15, s13
 *   @0x1ecf14 vstr s16, [sp, #4]
 *   @0x1ecf18 vdiv.f32 s15, s14, s15
 *   @0x1ecf1c vstr s15, [sp, #8]
 *   @0x1ecf20 bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf>
 *   @0x1ecf24 cmp r0, #0
 *   @0x1ecf28 bne 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1ecf2c ldr r3, [pc, #0x7c]
 *   @0x1ecf30 ldr r1, [pc, #0x7c]
 *   @0x1ecf34 ldr r3, [pc, r3]
 *   @0x1ecf38 ldr r2, [r4, #0x5c]
 *   @0x1ecf3c add r1, pc, r1
 *   @0x1ecf40 ldr r0, [r3]
 *   @0x1ecf44 ldr r3, [r0]
 *   @0x1ecf48 ldr r3, [r3, #0xc]
 *   @0x1ecf4c blx r3
 *   @0x1ecf50 b 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1ecf54 vmov s15, r6
 *   @0x1ecf58 vldr s13, [sp, #84]
 *   @0x1ecf5c vstr s13, [sp, #24]
 *   @0x1ecf60 vmov s13, r9
 *   @0x1ecf64 vcvt.f32.s32 s14, s15
 *   @0x1ecf68 ldr r3, [sp, #0x50]
 *   @0x1ecf6c str r8, [sp]
 *   @0x1ecf70 mov r2, r5
 *   @0x1ecf74 str r7, [sp, #0x4]
 *   @0x1ecf78 mov r0, r4
 *   @0x1ecf7c str r3, [sp, #0x14]
 *   @0x1ecf80 mov r3, r5
 *   @0x1ecf84 str r5, [sp, #0x10]
 *   @0x1ecf88 vcvt.f32.s32 s15, s13
 *   @0x1ecf8c vdiv.f32 s16, s16, s14
 *   @0x1ecf90 vldr s14, [sp, #76]
 *   @0x1ecf94 vdiv.f32 s15, s14, s15
 *   @0x1ecf98 vstr s16, [sp, #8]
 *   @0x1ecf9c vstr s15, [sp, #12]
 *   @0x1ecfa0 bl 0x1ebf08 <_ZN7CSprite7DrawSWFEifffffffjf>
 *   @0x1ecfa4 b 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0>
 *   @0x1ecfa8 eoreq r0, r0, r12, asr r8
 *   @0x1ecfac ldrsbeq r5, [r6], -r4
 *   @0x1ecfb0 eoreq r0, r0, r0, ror #15
 *   @0x1ecfb4 andseq r5, r6, r8, asr r6
 *
 * ══ §37/60 JS_String_prototype_substring(RValue&, CInstance*, CInstance*, int, RValue*)  0x255830  size 500  125 条（0x255830..0x255a24）
 * @func 0x255830 0x255a24  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CodepointToUTF16(int, unsigned short&, unsigned short&)×2 / CCodepointIterator_UTF8::GetNext()×2 / F_JS_ToInteger(RValue&)×2 / JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0
 * 字段偏移 top8: 0xc×3 / 0x8×2 / 0x10×2 / 0x68×1 / 0x-20×1 / 0x2c×1 / 0x38×1 / 0x3c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255830 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x255834 sub sp, sp, #68
 *   @0x255838 add r4, sp, #64
 *   @0x25583c mov r8, r0
 *   @0x255840 mov r3, #6
 *   @0x255844 ldr r7, [sp, #0x68]
 *   @0x255848 str r1, [r4, #-0x20]!
 *   @0x25584c mov r0, r4
 *   @0x255850 str r3, [sp, #0x2c]
 *   @0x255854 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x255858 cmp r0, #1
 *   @0x25585c beq 0x255a04 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x255860 mov r1, r4
 *   @0x255864 add r0, sp, #48
 *   @0x255868 mov r2, #0
 *   @0x25586c mov r3, #0
 *   @0x255870 mov r6, #0
 *   @0x255874 strd r2, r3, [sp, #48]
 *   @0x255878 str r6, [sp, #0x38]
 *   @0x25587c mvn r3, #-16777216
 *   @0x255880 str r3, [sp, #0x3c]
 *   @0x255884 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255888 ldr r3, [sp, #0x30]
 *   @0x25588c add r5, sp, #20
 *   @0x255890 ldr r9, [pc, #0x180]
 *   @0x255894 add r11, sp, #4
 *   @0x255898 mov r0, r5
 *   @0x25589c add r10, sp, #6
 *   @0x2558a0 ldr r1, [r3]
 *   @0x2558a4 ldr r9, [pc, r9]
 *   @0x2558a8 add r3, r9, #8
 *   @0x2558ac str r3, [sp, #0x8]
 *   @0x2558b0 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x2558b4 b 0x2558c0 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x2558b8 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x2558bc add r6, r6, r0
 *   @0x2558c0 mov r0, r5
 *   @0x2558c4 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x2558c8 mov r1, r11
 *   @0x2558cc mov r2, r10
 *   @0x2558d0 subs r4, r0, #0
 *   @0x2558d4 bne 0x2558b8 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x2558d8 lsl r10, r6, #1
 *   @0x2558dc ldr r1, [pc, #0x138]
 *   @0x2558e0 mov r2, #70
 *   @0x2558e4 mov r3, #1
 *   @0x2558e8 add r1, pc, r1
 *   @0x2558ec mov r0, r10
 *   @0x2558f0 str r6, [sp, #0x10]
 *   @0x2558f4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2558f8 mov r2, r10
 *   @0x2558fc mov r1, r4
 *   @0x255900 add r10, sp, #4
 *   @0x255904 add r6, sp, #6
 *   @0x255908 str r0, [sp, #0xc]
 *   @0x25590c bl 0xb65b0 <memset@plt>
 *   @0x255910 mov r0, r5
 *   @0x255914 bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv>
 *   @0x255918 mov r0, r5
 *   @0x25591c bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x255920 mov r1, r10
 *   @0x255924 mov r2, r6
 *   @0x255928 cmp r0, #0
 *   @0x25592c beq 0x255960 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x255930 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x255934 ldr r1, [sp, #0xc]
 *   @0x255938 lsl r2, r4, #1
 *   @0x25593c mov r3, r0
 *   @0x255940 cmp r0, #2
 *   @0x255944 ldrh r0, [sp, #4]
 *   @0x255948 add r4, r4, r3
 *   @0x25594c strh r0, [r1, r2]
 *   @0x255950 ldrheq r3, [sp, #6]
 *   @0x255954 addeq r2, r1, r2
 *   @0x255958 strheq r3, [r2, #2]
 *   @0x25595c b 0x255918 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x255960 mov r0, r7
 *   @0x255964 ldr r4, [sp, #0x10]
 *   @0x255968 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x25596c ldr r3, [r7, #0x1c]
 *   @0x255970 cmp r3, #5
 *   @0x255974 vmov d7, r0, r1
 *   @0x255978 moveq r0, r4
 *   @0x25597c vcvt.s32.f64 s15, d7
 *   @0x255980 vmov r5, s15
 *   @0x255984 beq 0x25599c <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x255988 add r0, r7, #16
 *   @0x25598c bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x255990 vmov d7, r0, r1
 *   @0x255994 vcvt.s32.f64 s15, d7
 *   @0x255998 vmov r0, s15
 *   @0x25599c bic r2, r5, r5, asr #31
 *   @0x2559a0 bic r3, r0, r0, asr #31
 *   @0x2559a4 cmp r2, r4
 *   @0x2559a8 movge r2, r4
 *   @0x2559ac cmp r3, r4
 *   @0x2559b0 movge r3, r4
 *   @0x2559b4 cmp r2, r3
 *   @0x2559b8 bge 0x2559ec <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x2559bc add r0, sp, #12
 *   @0x2559c0 mov r1, r8
 *   @0x2559c4 rsb r3, r2, r3
 *   @0x2559c8 add r9, r9, #8
 *   @0x2559cc bl 0x23cea8 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x2559d0 ldr r0, [sp, #0xc]
 *   @0x2559d4 str r9, [sp, #0x8]
 *   @0x2559d8 cmp r0, #0
 *   @0x2559dc beq 0x2559e4 <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x2559e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2559e4 add sp, sp, #68
 *   @0x2559e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2559ec cmp r3, r2
 *   @0x2559f0 movge r1, r3
 *   @0x2559f4 movlt r1, r2
 *   @0x2559f8 mov r2, r3
 *   @0x2559fc mov r3, r1
 *   @0x255a00 b 0x2559bc <_Z29JS_String_prototype_substringR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x255a04 ldr r0, [pc, #0x14]
 *   @0x255a08 add r0, pc, r0
 *   @0x255a0c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x255a10 add sp, sp, #68
 *   @0x255a14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x255a18 andseq r11, r9, r4, asr r12
 *   @0x255a1c andeq r11, sp, r8, asr #14
 *   @0x255a20 andseq r0, r0, r0, asr #10
 *
 * ══ §38/60 b2PolygonShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const  0x2c5ca8  size 500  125 条（0x2c5ca8..0x2c5e9c）
 * @func 0x2c5ca8 0x2c5e9c  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700×2 / b2PolygonShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const+0x180 / b2PolygonShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const+0x18c
 * 字段偏移 top8: 0x4×2 / 0x94×1 / 0x20×1
 * VFP 指令 89 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5ca8 vldr s15, [r1, #4]
 *   @0x2c5cac vldr s11, [r2, #4]
 *   @0x2c5cb0 vsub.f32 s11, s11, s15
 *   @0x2c5cb4 vldr s13, [r1, #8]
 *   @0x2c5cb8 vldr s15, [r1, #12]
 *   @0x2c5cbc vldr s10, [r2]
 *   @0x2c5cc0 vldr s14, [r1]
 *   @0x2c5cc4 push {r4, r5, lr}
 *   @0x2c5cc8 vpush {d8}
 *   @0x2c5ccc sub sp, sp, #12
 *   @0x2c5cd0 ldr r4, [r0, #0x94]
 *   @0x2c5cd4 ldr r5, [sp, #0x20]
 *   @0x2c5cd8 cmp r4, #0
 *   @0x2c5cdc vmul.f32 s12, s11, s13
 *   @0x2c5ce0 vmul.f32 s11, s11, s15
 *   @0x2c5ce4 vsub.f32 s14, s10, s14
 *   @0x2c5ce8 vmls.f32 s11, s13, s14
 *   @0x2c5cec vmla.f32 s12, s14, s15
 *   @0x2c5cf0 ble 0x2c5e28 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x180>
 *   @0x2c5cf4 add r2, r0, #84
 *   @0x2c5cf8 mov r12, #0
 *   @0x2c5cfc vldr s9, [pc, #400]
 *   @0x2c5d00 vmov.f32 s17, s11
 *   @0x2c5d04 vmov.f32 s16, s12
 *   @0x2c5d08 vldr s15, [r2, #-60]
 *   @0x2c5d0c vldr s13, [r2, #4]
 *   @0x2c5d10 vldr s10, [r2, #-64]
 *   @0x2c5d14 vldr s14, [r2]
 *   @0x2c5d18 vsub.f32 s15, s11, s15
 *   @0x2c5d1c add r12, r12, #1
 *   @0x2c5d20 add r2, r2, #8
 *   @0x2c5d24 vmul.f32 s15, s15, s13
 *   @0x2c5d28 vsub.f32 s10, s12, s10
 *   @0x2c5d2c vmla.f32 s15, s10, s14
 *   @0x2c5d30 vcmpe.f32 s15, s9
 *   @0x2c5d34 vmrs APSR_nzcv, fpscr
 *   @0x2c5d38 vmovgt.f32 s17, s13
 *   @0x2c5d3c vmovgt.f32 s16, s14
 *   @0x2c5d40 vmovgt.f32 s9, s15
 *   @0x2c5d44 cmp r12, r4
 *   @0x2c5d48 bne 0x2c5d08 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x60>
 *   @0x2c5d4c vcmpe.f32 s9, #0
 *   @0x2c5d50 vmrs APSR_nzcv, fpscr
 *   @0x2c5d54 ble 0x2c5e34 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x18c>
 *   @0x2c5d58 vmul.f32 s9, s9, s9
 *   @0x2c5d5c add r0, r0, #20
 *   @0x2c5d60 mov r2, #0
 *   @0x2c5d64 vldr s13, [r0, #4]
 *   @0x2c5d68 vldr s14, [r0]
 *   @0x2c5d6c add r2, r2, #1
 *   @0x2c5d70 add r0, r0, #8
 *   @0x2c5d74 vsub.f32 s13, s11, s13
 *   @0x2c5d78 vmul.f32 s15, s13, s13
 *   @0x2c5d7c vsub.f32 s14, s12, s14
 *   @0x2c5d80 vmla.f32 s15, s14, s14
 *   @0x2c5d84 vcmpe.f32 s15, s9
 *   @0x2c5d88 vmrs APSR_nzcv, fpscr
 *   @0x2c5d8c vmovmi.f32 s17, s13
 *   @0x2c5d90 vmovmi.f32 s16, s14
 *   @0x2c5d94 vmovmi.f32 s9, s15
 *   @0x2c5d98 cmp r2, r4
 *   @0x2c5d9c bne 0x2c5d64 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0xbc>
 *   @0x2c5da0 vsqrt.f32 s15, s9
 *   @0x2c5da4 vcmp.f32 s15, s15
 *   @0x2c5da8 vmrs APSR_nzcv, fpscr
 *   @0x2c5dac bne 0x2c5e64 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x1bc>
 *   @0x2c5db0 vstr s15, [r3]
 *   @0x2c5db4 vldr s14, [r1, #12]
 *   @0x2c5db8 vmul.f32 s15, s14, s17
 *   @0x2c5dbc vldr s13, [r1, #8]
 *   @0x2c5dc0 vmla.f32 s15, s13, s16
 *   @0x2c5dc4 vmul.f32 s17, s13, s17
 *   @0x2c5dc8 vstr s15, [r5, #4]
 *   @0x2c5dcc vnmls.f32 s17, s14, s16
 *   @0x2c5dd0 vmul.f32 s15, s15, s15
 *   @0x2c5dd4 vstr s17, [r5]
 *   @0x2c5dd8 vmla.f32 s15, s17, s17
 *   @0x2c5ddc vsqrt.f32 s14, s15
 *   @0x2c5de0 vcmp.f32 s14, s14
 *   @0x2c5de4 vmrs APSR_nzcv, fpscr
 *   @0x2c5de8 bne 0x2c5e84 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x1dc>
 *   @0x2c5dec vldr s15, [pc, #164]
 *   @0x2c5df0 vcmpe.f32 s14, s15
 *   @0x2c5df4 vmrs APSR_nzcv, fpscr
 *   @0x2c5df8 bmi 0x2c5e1c <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x174>
 *   @0x2c5dfc vmov.f32 s12, #1.000000e+00
 *   @0x2c5e00 vldr s15, [r5]
 *   @0x2c5e04 vldr s13, [r5, #4]
 *   @0x2c5e08 vdiv.f32 s14, s12, s14
 *   @0x2c5e0c vmul.f32 s15, s15, s14
 *   @0x2c5e10 vmul.f32 s14, s13, s14
 *   @0x2c5e14 vstr s15, [r5]
 *   @0x2c5e18 vstr s14, [r5, #4]
 *   @0x2c5e1c add sp, sp, #12
 *   @0x2c5e20 vpop {d8}
 *   @0x2c5e24 pop {r4, r5, pc}
 *   @0x2c5e28 vmov.f32 s17, s11
 *   @0x2c5e2c vldr s9, [pc, #96]
 *   @0x2c5e30 vmov.f32 s16, s12
 *   @0x2c5e34 vstr s9, [r3]
 *   @0x2c5e38 vldr s14, [r1, #12]
 *   @0x2c5e3c vldr s13, [r1, #8]
 *   @0x2c5e40 vmul.f32 s15, s14, s17
 *   @0x2c5e44 vmul.f32 s17, s13, s17
 *   @0x2c5e48 vmla.f32 s15, s16, s13
 *   @0x2c5e4c vnmls.f32 s17, s16, s14
 *   @0x2c5e50 vstr s15, [r5, #4]
 *   @0x2c5e54 vstr s17, [r5]
 *   @0x2c5e58 add sp, sp, #12
 *   @0x2c5e5c vpop {d8}
 *   @0x2c5e60 pop {r4, r5, pc}
 *   @0x2c5e64 vmov r0, s9
 *   @0x2c5e68 str r1, [sp, #0x4]
 *   @0x2c5e6c str r3, [sp]
 *   @0x2c5e70 bl 0xb6700 <sqrtf@plt>
 *   @0x2c5e74 ldr r3, [sp]
 *   @0x2c5e78 ldr r1, [sp, #0x4]
 *   @0x2c5e7c vmov s15, r0
 *   @0x2c5e80 b 0x2c5db0 <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x108>
 *   @0x2c5e84 vmov r0, s15
 *   @0x2c5e88 bl 0xb6700 <sqrtf@plt>
 *   @0x2c5e8c vmov s14, r0
 *   @0x2c5e90 b 0x2c5dec <_ZNK14b2PolygonShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x144>
 *   @0x2c5e94 .word 0xff7fffff
 *   @0x2c5e98 strlo r0, [r0], #-0
 *
 * ══ §39/60 CFontGM::CFontGM(unsigned char*, int, int, int)  0xf6e8c  size 496  124 条（0xf6e8c..0xf707c）
 * @func 0xf6e8c 0xf707c  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6544
 * 字段偏移 top8: 0x4×4 / 0x8×3 / 0xc×3 / 0x18×3 / 0x1c×3 / 0x40×3 / 0x20×2 / 0xd×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6e8c ldr r12, [pc, #0x1dc]
 *   @0xf6e90 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xf6e94 ldr r12, [pc, r12]
 *   @0xf6e98 mov r4, r0
 *   @0xf6e9c mov r5, #0
 *   @0xf6ea0 add r12, r12, #8
 *   @0xf6ea4 str r5, [r0, #0x4]
 *   @0xf6ea8 str r12, [r0]
 *   @0xf6eac mov lr, #1056964608
 *   @0xf6eb0 str r5, [r0, #0x8]
 *   @0xf6eb4 mvn r0, #0
 *   @0xf6eb8 str r0, [r4, #0x20]
 *   @0xf6ebc mov r9, r3
 *   @0xf6ec0 str r0, [r4, #0x38]
 *   @0xf6ec4 mov r3, #1065353216
 *   @0xf6ec8 ldr r0, [pc, #0x1a4]
 *   @0xf6ecc mov r7, r2
 *   @0xf6ed0 str lr, [r4, #0x50]
 *   @0xf6ed4 mov r8, r1
 *   @0xf6ed8 str r3, [r4, #0x48]
 *   @0xf6edc add r0, pc, r0
 *   @0xf6ee0 str r3, [r4, #0x4c]
 *   @0xf6ee4 strb r5, [r4, #0xc]
 *   @0xf6ee8 strb r5, [r4, #0xd]
 *   @0xf6eec str r5, [r4, #0x18]
 *   @0xf6ef0 str r5, [r4, #0x1c]
 *   @0xf6ef4 str r5, [r4, #0x24]
 *   @0xf6ef8 str r5, [r4, #0x28]
 *   @0xf6efc str r5, [r4, #0x2c]
 *   @0xf6f00 str r5, [r4, #0x40]
 *   @0xf6f04 str r5, [r4, #0x44]
 *   @0xf6f08 str r5, [r4, #0x5c]
 *   @0xf6f0c str r5, [r4, #0x60]
 *   @0xf6f10 str r5, [r4, #0x64]
 *   @0xf6f14 str r5, [r4, #0x6c]
 *   @0xf6f18 str r5, [r4, #0x70]
 *   @0xf6f1c str r5, [r4, #0x74]
 *   @0xf6f20 str r5, [r4, #0x78]
 *   @0xf6f24 str r5, [r4, #0x7c]
 *   @0xf6f28 str r5, [r4, #0x80]
 *   @0xf6f2c str r5, [r4, #0x84]
 *   @0xf6f30 str r5, [r4, #0x88]
 *   @0xf6f34 str r5, [r4, #0x3c]
 *   @0xf6f38 str r5, [r4, #0x34]
 *   @0xf6f3c str r5, [r4, #0x30]
 *   @0xf6f40 ldr r6, [sp, #0x20]
 *   @0xf6f44 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf6f48 add r1, r9, #1
 *   @0xf6f4c str r7, [r4, #0x18]
 *   @0xf6f50 rsb r1, r7, r1
 *   @0xf6f54 str r1, [r4, #0x40]
 *   @0xf6f58 mov lr, #10
 *   @0xf6f5c mov r2, #243
 *   @0xf6f60 add r12, r1, r1, lsl #2
 *   @0xf6f64 mov r1, #3
 *   @0xf6f68 str r1, [r4, #0x14]
 *   @0xf6f6c mov r3, #1
 *   @0xf6f70 ldr r1, [pc, #0x100]
 *   @0xf6f74 strb r5, [r4, #0xc]
 *   @0xf6f78 strb r5, [r4, #0xd]
 *   @0xf6f7c add r1, pc, r1
 *   @0xf6f80 str r9, [r4, #0x1c]
 *   @0xf6f84 str r5, [r4, #0x10]
 *   @0xf6f88 str r5, [r4, #0x54]
 *   @0xf6f8c str r5, [r4, #0x8c]
 *   @0xf6f90 str lr, [r4, #0x8]
 *   @0xf6f94 str r0, [r4, #0x4]
 *   @0xf6f98 lsl r0, r12, #2
 *   @0xf6f9c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf6fa0 ldr r2, [r4, #0x18]
 *   @0xf6fa4 ldr r7, [r4, #0x1c]
 *   @0xf6fa8 ldr r3, [r4, #0x40]
 *   @0xf6fac cmp r2, r7
 *   @0xf6fb0 str r0, [r4, #0x44]
 *   @0xf6fb4 add r3, r0, r3, lsl #2
 *   @0xf6fb8 bgt 0xf7024 <_ZN7CFontGMC2EPhiii+0x198>
 *   @0xf6fbc add r3, r3, #16
 *   @0xf6fc0 sub r0, r0, #4
 *   @0xf6fc4 add r7, r7, #1
 *   @0xf6fc8 mov r1, r8
 *   @0xf6fcc sub r12, r3, #16
 *   @0xf6fd0 str r12, [r0, #0x4]!
 *   @0xf6fd4 strh r2, [r3, #-16]
 *   @0xf6fd8 add r2, r2, #1
 *   @0xf6fdc ldrb r12, [r1]
 *   @0xf6fe0 add r3, r3, #16
 *   @0xf6fe4 ldr lr, [r4, #0x2c]
 *   @0xf6fe8 add r1, r1, #4
 *   @0xf6fec strh r12, [r3, #-30]
 *   @0xf6ff0 ldrb r12, [r1, #-0x3]
 *   @0xf6ff4 strh r12, [r3, #-28]
 *   @0xf6ff8 ldrb r12, [r1, #-0x2]
 *   @0xf6ffc strh r12, [r3, #-26]
 *   @0xf7000 ldrb r12, [r1, #-0x1]
 *   @0xf7004 cmp r12, lr
 *   @0xf7008 strh r12, [r3, #-24]
 *   @0xf700c ldrb lr, [r1, #-0x2]
 *   @0xf7010 strh r5, [r3, #-20]
 *   @0xf7014 strh lr, [r3, #-22]
 *   @0xf7018 strgt r12, [r4, #0x2c]
 *   @0xf701c cmp r2, r7
 *   @0xf7020 bne 0xf6fcc <_ZN7CFontGMC2EPhiii+0x140>
 *   @0xf7024 mov r0, #22
 *   @0xf7028 bl 0xb6544 <malloc@plt>
 *   @0xf702c mov r3, #0
 *   @0xf7030 mov r1, #256
 *   @0xf7034 mov r2, #128
 *   @0xf7038 strh r6, [r0, #20]
 *   @0xf703c str r0, [r4, #0x3c]
 *   @0xf7040 strh r3, [r0]
 *   @0xf7044 strh r3, [r0, #2]
 *   @0xf7048 strh r3, [r0, #8]
 *   @0xf704c strh r3, [r0, #10]
 *   @0xf7050 strh r1, [r0, #4]
 *   @0xf7054 strh r1, [r0, #12]
 *   @0xf7058 strh r1, [r0, #16]
 *   @0xf705c strh r2, [r0, #6]
 *   @0xf7060 strh r2, [r0, #14]
 *   @0xf7064 strh r2, [r0, #18]
 *   @0xf7068 mov r0, r4
 *   @0xf706c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf7070 .word 0x002f6fb4
 *   @0xf7074 eoreq r0, r4, r0, lsr #22
 *   @0xf7078 eoreq r0, r4, r8, lsl #21
 *
 * ══ §40/60 InstanceRegionActivate(CInstance*)  0x10a390  size 496  124 条（0x10a390..0x10a580）
 * @func 0x10a390 0x10a580  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Exists(int)×2 / InstanceRegionActivate(CInstance*)+0x174 / InstanceRegionActivate(CInstance*)+0x8c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0x8c×1 / 0x64×1 / 0x19c×1 / 0xf0×1 / 0x170×1 / 0x148×1
 * VFP 指令 34 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10a390 push {r4, r5, lr}
 *   @0x10a394 mov r4, r0
 *   @0x10a398 sub sp, sp, #12
 *   @0x10a39c ldr r0, [r0, #0x8c]
 *   @0x10a3a0 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x10a3a4 cmp r0, #0
 *   @0x10a3a8 beq 0x10a48c <_Z22InstanceRegionActivateP9CInstance+0xfc>
 *   @0x10a3ac ldrb r3, [r4, #0x64]
 *   @0x10a3b0 cmp r3, #0
 *   @0x10a3b4 bne 0x10a554 <_Z22InstanceRegionActivateP9CInstance+0x1c4>
 *   @0x10a3b8 vldr s11, [r4, #232]
 *   @0x10a3bc vcvt.f32.s32 s14, s11
 *   @0x10a3c0 ldr r3, [pc, #0x19c]
 *   @0x10a3c4 add r3, pc, r3
 *   @0x10a3c8 vldr s15, [r3, #24]
 *   @0x10a3cc vldr s13, [r3, #16]
 *   @0x10a3d0 ldr r3, [r4, #0xf0]
 *   @0x10a3d4 vcmpe.f32 s14, s15
 *   @0x10a3d8 vmrs APSR_nzcv, fpscr
 *   @0x10a3dc movgt r3, #1
 *   @0x10a3e0 ble 0x10a504 <_Z22InstanceRegionActivateP9CInstance+0x174>
 *   @0x10a3e4 vldr s14, [r4, #244]
 *   @0x10a3e8 vcvt.f32.s32 s12, s14
 *   @0x10a3ec vldr s11, [r4, #236]
 *   @0x10a3f0 ldr r2, [pc, #0x170]
 *   @0x10a3f4 add r2, pc, r2
 *   @0x10a3f8 vldr s13, [r2, #20]
 *   @0x10a3fc vldr s15, [r2, #28]
 *   @0x10a400 vcvt.f32.s32 s14, s11
 *   @0x10a404 vcmp.f32 s12, s13
 *   @0x10a408 vmrs APSR_nzcv, fpscr
 *   @0x10a40c vcmpe.f32 s14, s15
 *   @0x10a410 movmi r3, #1
 *   @0x10a414 vmrs APSR_nzcv, fpscr
 *   @0x10a418 bgt 0x10a4fc <_Z22InstanceRegionActivateP9CInstance+0x16c>
 *   @0x10a41c ldr r2, [pc, #0x148]
 *   @0x10a420 add r2, pc, r2
 *   @0x10a424 ldrb r2, [r2, #0xc]
 *   @0x10a428 cmp r2, r3
 *   @0x10a42c beq 0x10a484 <_Z22InstanceRegionActivateP9CInstance+0xf4>
 *   @0x10a430 ldrb r12, [r4, #0x68]
 *   @0x10a434 cmp r12, #0
 *   @0x10a438 bne 0x10a484 <_Z22InstanceRegionActivateP9CInstance+0xf4>
 *   @0x10a43c ldrb r3, [r4, #0x69]
 *   @0x10a440 cmp r3, #0
 *   @0x10a444 beq 0x10a484 <_Z22InstanceRegionActivateP9CInstance+0xf4>
 *   @0x10a448 ldr r5, [pc, #0x120]
 *   @0x10a44c ldr r5, [pc, r5]
 *   @0x10a450 ldr r1, [r5, #0x8]
 *   @0x10a454 ldr r3, [r5, #0x4]
 *   @0x10a458 cmp r1, r3
 *   @0x10a45c beq 0x10a520 <_Z22InstanceRegionActivateP9CInstance+0x190>
 *   @0x10a460 ldr r3, [r5]
 *   @0x10a464 str r4, [r3, r1, lsl #2]
 *   @0x10a468 mov r0, r4
 *   @0x10a46c add r3, r1, #1
 *   @0x10a470 mov r1, #0
 *   @0x10a474 str r3, [r5, #0x8]
 *   @0x10a478 add sp, sp, #12
 *   @0x10a47c pop {r4, r5, lr}
 *   @0x10a480 b 0x19230c <_ZN9CInstance14SetDeactivatedEb>
 *   @0x10a484 add sp, sp, #12
 *   @0x10a488 pop {r4, r5, pc}
 *   @0x10a48c ldr r0, [r4, #0xac]
 *   @0x10a490 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x10a494 cmp r0, #0
 *   @0x10a498 bne 0x10a3ac <_Z22InstanceRegionActivateP9CInstance+0x1c>
 *   @0x10a49c ldr r3, [pc, #0xd0]
 *   @0x10a4a0 vldr s15, [r4, #180]
 *   @0x10a4a4 add r3, pc, r3
 *   @0x10a4a8 vldr s14, [r3, #24]
 *   @0x10a4ac vcmpe.f32 s15, s14
 *   @0x10a4b0 vldr s14, [r3, #16]
 *   @0x10a4b4 vmrs APSR_nzcv, fpscr
 *   @0x10a4b8 movgt r3, #1
 *   @0x10a4bc bgt 0x10a4d0 <_Z22InstanceRegionActivateP9CInstance+0x140>
 *   @0x10a4c0 vcmpe.f32 s15, s14
 *   @0x10a4c4 vmrs APSR_nzcv, fpscr
 *   @0x10a4c8 movpl r3, #0
 *   @0x10a4cc movmi r3, #1
 *   @0x10a4d0 ldr r2, [pc, #0xa0]
 *   @0x10a4d4 vldr s15, [r4, #184]
 *   @0x10a4d8 add r2, pc, r2
 *   @0x10a4dc vldr s14, [r2, #20]
 *   @0x10a4e0 vcmp.f32 s15, s14
 *   @0x10a4e4 vldr s14, [r2, #28]
 *   @0x10a4e8 vmrs APSR_nzcv, fpscr
 *   @0x10a4ec vcmpe.f32 s15, s14
 *   @0x10a4f0 movmi r3, #1
 *   @0x10a4f4 vmrs APSR_nzcv, fpscr
 *   @0x10a4f8 ble 0x10a41c <_Z22InstanceRegionActivateP9CInstance+0x8c>
 *   @0x10a4fc mov r3, #1
 *   @0x10a500 b 0x10a41c <_Z22InstanceRegionActivateP9CInstance+0x8c>
 *   @0x10a504 vmov s12, r3
 *   @0x10a508 vcvt.f32.s32 s15, s12
 *   @0x10a50c vcmpe.f32 s15, s13
 *   @0x10a510 vmrs APSR_nzcv, fpscr
 *   @0x10a514 movpl r3, #0
 *   @0x10a518 movmi r3, #1
 *   @0x10a51c b 0x10a3e4 <_Z22InstanceRegionActivateP9CInstance+0x54>
 *   @0x10a520 ldr r2, [pc, #0x54]
 *   @0x10a524 lsl r3, r1, #1
 *   @0x10a528 ldr r0, [r5]
 *   @0x10a52c lsl r1, r1, #3
 *   @0x10a530 str r3, [r5, #0x4]
 *   @0x10a534 add r2, pc, r2
 *   @0x10a538 mov r3, #74
 *   @0x10a53c str r12, [sp]
 *   @0x10a540 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10a544 ldr r1, [r5, #0x8]
 *   @0x10a548 mov r3, r0
 *   @0x10a54c str r0, [r5]
 *   @0x10a550 b 0x10a464 <_Z22InstanceRegionActivateP9CInstance+0xd4>
 *   @0x10a554 mov r0, r4
 *   @0x10a558 mov r1, #1
 *   @0x10a55c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x10a560 b 0x10a3b8 <_Z22InstanceRegionActivateP9CInstance+0x28>
 *   @0x10a564 eorseq r9, r7, r4, lsl r3
 *   @0x10a568 eorseq r9, r7, r4, ror #5
 *   @0x10a56c ldrhteq r9, [r7], -r8
 *   @0x10a570 .word 0x002e37fc
 *   @0x10a574 eorseq r9, r7, r4, lsr r2
 *   @0x10a578 eorseq r9, r7, r0, lsl #4
 *   @0x10a57c .word 0x00226afc
 *
 * ══ §41/60 FacebookRequestPermissionsM(int, bool)  0x15f8b8  size 496  124 条（0x15f8b8..0x15faa8）
 * @func 0x15f8b8 0x15faa8  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×6 / FacebookRequestPermissionsM(int, bool)+0x1cc×2 / F_DsListSize(RValue&, CInstance*, CInstance*, int, RValue*) / F_DsListFindValue(RValue&, CInstance*, CInstance*, int, RValue*) / FREE_RValue__Pre(RValue*) / _JNIEnv::CallStaticIntMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x10×4 / 0xc×3 / 0x160×2 / 0x8×2 / 0x18×2 / 0x29c×2 / 0x1c×2 / 0x44×2
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f8b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x15f8bc cmp r0, #0
 *   @0x15f8c0 sub sp, sp, #68
 *   @0x15f8c4 str r1, [sp, #0xc]
 *   @0x15f8c8 blt 0x15fa84 <_Z27FacebookRequestPermissionsMib+0x1cc>
 *   @0x15f8cc vmov s13, r0
 *   @0x15f8d0 add r7, sp, #16
 *   @0x15f8d4 mov r4, #0
 *   @0x15f8d8 add r9, sp, #32
 *   @0x15f8dc vcvt.f64.s32 d7, s13
 *   @0x15f8e0 mov r0, r7
 *   @0x15f8e4 mov r1, r4
 *   @0x15f8e8 mov r2, r4
 *   @0x15f8ec str r9, [sp]
 *   @0x15f8f0 mov r3, #1
 *   @0x15f8f4 str r4, [sp, #0x10]
 *   @0x15f8f8 str r4, [sp, #0x2c]
 *   @0x15f8fc vstr d7, [sp, #32]
 *   @0x15f900 bl 0xfc350 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_>
 *   @0x15f904 vldr d7, [sp, #16]
 *   @0x15f908 vcvt.s32.f64 s13, d7
 *   @0x15f90c vmov r8, s13
 *   @0x15f910 cmp r8, r4
 *   @0x15f914 ble 0x15fa84 <_Z27FacebookRequestPermissionsMib+0x1cc>
 *   @0x15f918 bl 0x290274 <getJNIEnv>
 *   @0x15f91c mov r5, r4
 *   @0x15f920 mov r6, r0
 *   @0x15f924 bl 0x290274 <getJNIEnv>
 *   @0x15f928 ldr r1, [pc, #0x160]
 *   @0x15f92c ldr r12, [pc, #0x160]
 *   @0x15f930 add r1, pc, r1
 *   @0x15f934 add r12, pc, r12
 *   @0x15f938 str r12, [sp, #0x8]
 *   @0x15f93c ldr r3, [r0]
 *   @0x15f940 ldr r3, [r3, #0x18]
 *   @0x15f944 blx r3
 *   @0x15f948 mov r10, r0
 *   @0x15f94c bl 0x290274 <getJNIEnv>
 *   @0x15f950 ldr r1, [pc, #0x140]
 *   @0x15f954 add r1, pc, r1
 *   @0x15f958 ldr r3, [r0]
 *   @0x15f95c ldr r3, [r3, #0x29c]
 *   @0x15f960 blx r3
 *   @0x15f964 ldr r12, [r6]
 *   @0x15f968 mov r2, r10
 *   @0x15f96c mov r1, r8
 *   @0x15f970 ldr r12, [r12, #0x2b0]
 *   @0x15f974 mov r3, r0
 *   @0x15f978 mov r0, r6
 *   @0x15f97c blx r12
 *   @0x15f980 ldr r3, [pc, #0x114]
 *   @0x15f984 ldr r3, [pc, r3]
 *   @0x15f988 ldr r6, [r3]
 *   @0x15f98c mov r10, r0
 *   @0x15f990 b 0x15f9ac <_Z27FacebookRequestPermissionsMib+0xf4>
 *   @0x15f994 cmp r4, r8
 *   @0x15f998 mov r3, #5
 *   @0x15f99c str r5, [sp, #0x18]
 *   @0x15f9a0 str r3, [sp, #0x1c]
 *   @0x15f9a4 str r5, [sp, #0x10]
 *   @0x15f9a8 beq 0x15fa50 <_Z27FacebookRequestPermissionsMib+0x198>
 *   @0x15f9ac vmov s13, r4
 *   @0x15f9b0 mov r1, #0
 *   @0x15f9b4 mov r2, r1
 *   @0x15f9b8 mov r0, r7
 *   @0x15f9bc vcvt.f64.s32 d7, s13
 *   @0x15f9c0 mov r3, #2
 *   @0x15f9c4 str r9, [sp]
 *   @0x15f9c8 str r5, [sp, #0x3c]
 *   @0x15f9cc vstr d7, [sp, #48]
 *   @0x15f9d0 bl 0x106634 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_>
 *   @0x15f9d4 ldr r3, [r6]
 *   @0x15f9d8 mov r0, r6
 *   @0x15f9dc ldr r2, [sp, #0x10]
 *   @0x15f9e0 ldr r1, [sp, #0x8]
 *   @0x15f9e4 ldr r3, [r3, #0xc]
 *   @0x15f9e8 ldr r2, [r2]
 *   @0x15f9ec blx r3
 *   @0x15f9f0 bl 0x290274 <getJNIEnv>
 *   @0x15f9f4 ldr r3, [sp, #0x10]
 *   @0x15f9f8 ldr r1, [r3]
 *   @0x15f9fc ldr r3, [r0]
 *   @0x15fa00 ldr r3, [r3, #0x29c]
 *   @0x15fa04 blx r3
 *   @0x15fa08 mov r11, r0
 *   @0x15fa0c bl 0x290274 <getJNIEnv>
 *   @0x15fa10 mov r3, r11
 *   @0x15fa14 mov r2, r4
 *   @0x15fa18 mov r1, r10
 *   @0x15fa1c add r4, r4, #1
 *   @0x15fa20 ldr r12, [r0]
 *   @0x15fa24 ldr r12, [r12, #0x2b8]
 *   @0x15fa28 blx r12
 *   @0x15fa2c ldr r3, [sp, #0x1c]
 *   @0x15fa30 sub r3, r3, #1
 *   @0x15fa34 bic r3, r3, #-16777216
 *   @0x15fa38 bic r3, r3, #3
 *   @0x15fa3c cmp r3, #0
 *   @0x15fa40 bne 0x15f994 <_Z27FacebookRequestPermissionsMib+0xdc>
 *   @0x15fa44 mov r0, r7
 *   @0x15fa48 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x15fa4c b 0x15f994 <_Z27FacebookRequestPermissionsMib+0xdc>
 *   @0x15fa50 bl 0x290274 <getJNIEnv>
 *   @0x15fa54 ldr r1, [pc, #0x44]
 *   @0x15fa58 ldr r2, [pc, #0x44]
 *   @0x15fa5c mov r3, r10
 *   @0x15fa60 ldr r12, [sp, #0xc]
 *   @0x15fa64 ldr r1, [pc, r1]
 *   @0x15fa68 ldr r2, [pc, r2]
 *   @0x15fa6c ldr r1, [r1]
 *   @0x15fa70 ldr r2, [r2]
 *   @0x15fa74 str r12, [sp]
 *   @0x15fa78 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x15fa7c add sp, sp, #68
 *   @0x15fa80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x15fa84 mvn r0, #0
 *   @0x15fa88 add sp, sp, #68
 *   @0x15fa8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x15fa90 andseq r9, lr, r0, lsr lr
 *   @0x15fa94 ldrsbeq r9, [lr], -r12
 *   @0x15fa98 andseq pc, r12, r2, ror #3
 *   @0x15fa9c mlaeq r8, r0, sp, sp
 *   @0x15faa0 eoreq sp, r8, r0, asr #30
 *   @0x15faa4 mlaeq r9, r12, r4, r0
 *
 * ══ §42/60 ReadJPEGFile(void*, int, int*, int*, bool)  0x18a728  size 496  124 条（0x18a728..0x18a918）
 * @func 0x18a728 0x18a918  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / jpeg_std_error / jpeg_CreateDecompress / jpeg_memory_src(jpeg_decompress_struct*, unsigned char const*, unsigned int) / jpeg_read_header / jpeg_start_decompress / jpeg_read_scanlines / ReadJPEGFile(void*, int, int*, int*, bool)+0xd8
 * 字段偏移 top8: 0xa4×4 / 0x-4×4 / 0x23c×2 / 0xe4×2 / 0xac×2 / 0xe8×2 / 0x-1×2 / 0x1d8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a728 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18a72c mov r7, r3
 *   @0x18a730 ldr r6, [pc, #0x1d8]
 *   @0x18a734 sub sp, sp, #580
 *   @0x18a738 mov r9, r0
 *   @0x18a73c add r0, sp, #4
 *   @0x18a740 ldr r6, [pc, r6]
 *   @0x18a744 mov r5, r1
 *   @0x18a748 mov r8, r2
 *   @0x18a74c add r4, sp, #576
 *   @0x18a750 ldr r3, [r6]
 *   @0x18a754 str r3, [sp, #0x23c]
 *   @0x18a758 bl 0x2b8fc0 <jpeg_std_error>
 *   @0x18a75c mov r1, #62
 *   @0x18a760 mov r2, #432
 *   @0x18a764 str r0, [r4, #-0x1b8]!
 *   @0x18a768 mov r0, r4
 *   @0x18a76c bl 0x2b2dfc <jpeg_CreateDecompress>
 *   @0x18a770 mov r0, r4
 *   @0x18a774 mov r1, r9
 *   @0x18a778 mov r2, r5
 *   @0x18a77c bl 0x18a690 <_Z15jpeg_memory_srcP22jpeg_decompress_structPKhj>
 *   @0x18a780 mov r0, r4
 *   @0x18a784 mov r1, #0
 *   @0x18a788 bl 0x2b31b8 <jpeg_read_header>
 *   @0x18a78c cmp r0, #2
 *   @0x18a790 beq 0x18a780 <_Z12ReadJPEGFilePviPiS0_b+0x58>
 *   @0x18a794 cmp r0, #0
 *   @0x18a798 beq 0x18a8f4 <_Z12ReadJPEGFilePviPiS0_b+0x1cc>
 *   @0x18a79c mov r0, r4
 *   @0x18a7a0 ldr r5, [pc, #0x16c]
 *   @0x18a7a4 bl 0x2b34a8 <jpeg_start_decompress>
 *   @0x18a7a8 ldr r0, [sp, #0xe4]
 *   @0x18a7ac ldr lr, [sp, #0xac]
 *   @0x18a7b0 add r5, pc, r5
 *   @0x18a7b4 ldr r12, [sp, #0xe8]
 *   @0x18a7b8 mov r2, #111
 *   @0x18a7bc str r0, [r8]
 *   @0x18a7c0 mov r1, r5
 *   @0x18a7c4 mov r3, #1
 *   @0x18a7c8 str r12, [r7]
 *   @0x18a7cc mul r0, lr, r0
 *   @0x18a7d0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18a7d4 ldr r12, [sp, #0xe4]
 *   @0x18a7d8 ldr lr, [sp, #0xe8]
 *   @0x18a7dc mov r1, r5
 *   @0x18a7e0 mov r2, #114
 *   @0x18a7e4 mov r3, #1
 *   @0x18a7e8 mul r12, lr, r12
 *   @0x18a7ec str r0, [sp]
 *   @0x18a7f0 lsl r0, r12, #2
 *   @0x18a7f4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18a7f8 mov r7, r0
 *   @0x18a7fc mov r8, r0
 *   @0x18a800 ldr r2, [sp, #0x100]
 *   @0x18a804 mov r0, r4
 *   @0x18a808 ldr r3, [sp, #0xa8]
 *   @0x18a80c cmp r2, r3
 *   @0x18a810 bhs 0x18a8dc <_Z12ReadJPEGFilePviPiS0_b+0x1b4>
 *   @0x18a814 mov r1, sp
 *   @0x18a818 mov r2, #1
 *   @0x18a81c bl 0x2b35c0 <jpeg_read_scanlines>
 *   @0x18a820 ldr r1, [sp, #0xa4]
 *   @0x18a824 ldr r2, [sp]
 *   @0x18a828 cmp r1, #0
 *   @0x18a82c beq 0x18a800 <_Z12ReadJPEGFilePviPiS0_b+0xd8>
 *   @0x18a830 add r3, r8, #4
 *   @0x18a834 mov lr, #0
 *   @0x18a838 b 0x18a878 <_Z12ReadJPEGFilePviPiS0_b+0x150>
 *   @0x18a83c cmp r12, #4
 *   @0x18a840 beq 0x18a8ac <_Z12ReadJPEGFilePviPiS0_b+0x184>
 *   @0x18a844 cmp r12, #1
 *   @0x18a848 bne 0x18a864 <_Z12ReadJPEGFilePviPiS0_b+0x13c>
 *   @0x18a84c ldrb r1, [r2], #1
 *   @0x18a850 orr r0, r1, #-16777216
 *   @0x18a854 orr r0, r0, r1, lsl #16
 *   @0x18a858 orr r1, r0, r1, lsl #8
 *   @0x18a85c str r1, [r3, #-0x4]
 *   @0x18a860 ldr r1, [sp, #0xa4]
 *   @0x18a864 add lr, lr, #1
 *   @0x18a868 mov r8, r3
 *   @0x18a86c cmp r1, lr
 *   @0x18a870 add r3, r3, #4
 *   @0x18a874 bls 0x18a800 <_Z12ReadJPEGFilePviPiS0_b+0xd8>
 *   @0x18a878 ldr r12, [sp, #0xac]
 *   @0x18a87c cmp r12, #3
 *   @0x18a880 bne 0x18a83c <_Z12ReadJPEGFilePviPiS0_b+0x114>
 *   @0x18a884 ldrb r1, [r2]
 *   @0x18a888 add r2, r2, #3
 *   @0x18a88c ldrb r12, [r2, #-0x1]
 *   @0x18a890 ldrb r0, [r2, #-0x2]
 *   @0x18a894 orr r1, r1, #-16777216
 *   @0x18a898 orr r1, r1, r12, lsl #16
 *   @0x18a89c orr r1, r1, r0, lsl #8
 *   @0x18a8a0 str r1, [r3, #-0x4]
 *   @0x18a8a4 ldr r1, [sp, #0xa4]
 *   @0x18a8a8 b 0x18a864 <_Z12ReadJPEGFilePviPiS0_b+0x13c>
 *   @0x18a8ac ldrb r1, [r2, #0x2]
 *   @0x18a8b0 add r2, r2, #4
 *   @0x18a8b4 ldrb r8, [r2, #-0x1]
 *   @0x18a8b8 ldrb r12, [r2, #-0x4]
 *   @0x18a8bc ldrb r0, [r2, #-0x3]
 *   @0x18a8c0 lsl r1, r1, #16
 *   @0x18a8c4 orr r1, r1, r8, lsl #24
 *   @0x18a8c8 orr r1, r1, r12
 *   @0x18a8cc orr r1, r1, r0, lsl #8
 *   @0x18a8d0 str r1, [r3, #-0x4]
 *   @0x18a8d4 ldr r1, [sp, #0xa4]
 *   @0x18a8d8 b 0x18a864 <_Z12ReadJPEGFilePviPiS0_b+0x13c>
 *   @0x18a8dc bl 0x2b32c0 <jpeg_finish_decompress>
 *   @0x18a8e0 mov r0, r4
 *   @0x18a8e4 bl 0x2b2f00 <jpeg_destroy_decompress>
 *   @0x18a8e8 ldr r0, [sp]
 *   @0x18a8ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18a8f0 mov r0, r7
 *   @0x18a8f4 ldr r2, [sp, #0x23c]
 *   @0x18a8f8 ldr r3, [r6]
 *   @0x18a8fc cmp r2, r3
 *   @0x18a900 bne 0x18a90c <_Z12ReadJPEGFilePviPiS0_b+0x1e4>
 *   @0x18a904 add sp, sp, #580
 *   @0x18a908 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18a90c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18a910 eoreq r3, r6, r0, lsl r2
 *   @0x18a914 andseq r1, r12, r4, lsl #19
 *
 * ══ §43/60 ObjectPool<CLayer>::~ObjectPool()  0x1b6a9c  size 496  124 条（0x1b6a9c..0x1b6c8c）
 * @func 0x1b6a9c 0x1b6c8c  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×8 / operator delete(void*)×3 / MemoryInWad(void*)×2
 * 字段偏移 top8: 0x14×8 / 0x1c×6 / 0x58×4 / 0x64×2 / 0x60×2 / 0x5c×2 / 0xc×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6a9c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1b6aa0 mov r9, r0
 *   @0x1b6aa4 ldr r7, [r0, #0xc]
 *   @0x1b6aa8 cmp r7, #0
 *   @0x1b6aac beq 0x1b6afc <_ZN10ObjectPoolI6CLayerED2Ev+0x60>
 *   @0x1b6ab0 ldr r4, [r0]
 *   @0x1b6ab4 cmp r4, #0
 *   @0x1b6ab8 beq 0x1b6afc <_ZN10ObjectPoolI6CLayerED2Ev+0x60>
 *   @0x1b6abc mov r8, #0
 *   @0x1b6ac0 b 0x1b6ae0 <_ZN10ObjectPoolI6CLayerED2Ev+0x44>
 *   @0x1b6ac4 cmp r7, #3
 *   @0x1b6ac8 beq 0x1b6b14 <_ZN10ObjectPoolI6CLayerED2Ev+0x78>
 *   @0x1b6acc cmp r7, #1
 *   @0x1b6ad0 beq 0x1b6bb8 <_ZN10ObjectPoolI6CLayerED2Ev+0x11c>
 *   @0x1b6ad4 cmp r6, #0
 *   @0x1b6ad8 beq 0x1b6afc <_ZN10ObjectPoolI6CLayerED2Ev+0x60>
 *   @0x1b6adc mov r4, r6
 *   @0x1b6ae0 cmp r7, #2
 *   @0x1b6ae4 ldr r6, [r4, #0x68]
 *   @0x1b6ae8 bne 0x1b6ac4 <_ZN10ObjectPoolI6CLayerED2Ev+0x28>
 *   @0x1b6aec mov r0, r4
 *   @0x1b6af0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6af4 cmp r6, #0
 *   @0x1b6af8 bne 0x1b6adc <_ZN10ObjectPoolI6CLayerED2Ev+0x40>
 *   @0x1b6afc mov r3, #0
 *   @0x1b6b00 mov r0, r9
 *   @0x1b6b04 str r3, [r9, #0x8]
 *   @0x1b6b08 str r3, [r9, #0x4]
 *   @0x1b6b0c str r3, [r9]
 *   @0x1b6b10 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b6b14 ldr r0, [r4, #0x1c]
 *   @0x1b6b18 bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0x1b6b1c cmp r0, #0
 *   @0x1b6b20 bne 0x1b6b2c <_ZN10ObjectPoolI6CLayerED2Ev+0x90>
 *   @0x1b6b24 ldr r0, [r4, #0x1c]
 *   @0x1b6b28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6b2c ldr r3, [r4, #0x64]
 *   @0x1b6b30 str r8, [r4, #0x1c]
 *   @0x1b6b34 cmp r3, #0
 *   @0x1b6b38 beq 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4>
 *   @0x1b6b3c ldr r0, [r4, #0x58]
 *   @0x1b6b40 cmp r0, #0
 *   @0x1b6b44 beq 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4>
 *   @0x1b6b48 cmp r3, #2
 *   @0x1b6b4c beq 0x1b6b88 <_ZN10ObjectPoolI6CLayerED2Ev+0xec>
 *   @0x1b6b50 cmp r3, #3
 *   @0x1b6b54 beq 0x1b6ba0 <_ZN10ObjectPoolI6CLayerED2Ev+0x104>
 *   @0x1b6b58 cmp r3, #1
 *   @0x1b6b5c beq 0x1b6c74 <_ZN10ObjectPoolI6CLayerED2Ev+0x1d8>
 *   @0x1b6b60 ldr r5, [r0, #0x14]
 *   @0x1b6b64 cmp r5, #0
 *   @0x1b6b68 mov r0, r5
 *   @0x1b6b6c bne 0x1b6b60 <_ZN10ObjectPoolI6CLayerED2Ev+0xc4>
 *   @0x1b6b70 str r8, [r4, #0x60]
 *   @0x1b6b74 mov r0, r4
 *   @0x1b6b78 str r8, [r4, #0x5c]
 *   @0x1b6b7c str r8, [r4, #0x58]
 *   @0x1b6b80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6b84 b 0x1b6ad4 <_ZN10ObjectPoolI6CLayerED2Ev+0x38>
 *   @0x1b6b88 ldr r5, [r0, #0x14]
 *   @0x1b6b8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6b90 cmp r5, #0
 *   @0x1b6b94 mov r0, r5
 *   @0x1b6b98 bne 0x1b6b88 <_ZN10ObjectPoolI6CLayerED2Ev+0xec>
 *   @0x1b6b9c b 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4>
 *   @0x1b6ba0 ldr r5, [r0, #0x14]
 *   @0x1b6ba4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6ba8 cmp r5, #0
 *   @0x1b6bac mov r0, r5
 *   @0x1b6bb0 bne 0x1b6ba0 <_ZN10ObjectPoolI6CLayerED2Ev+0x104>
 *   @0x1b6bb4 b 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4>
 *   @0x1b6bb8 ldr r0, [r4, #0x1c]
 *   @0x1b6bbc bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0x1b6bc0 cmp r0, #0
 *   @0x1b6bc4 bne 0x1b6bd0 <_ZN10ObjectPoolI6CLayerED2Ev+0x134>
 *   @0x1b6bc8 ldr r0, [r4, #0x1c]
 *   @0x1b6bcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6bd0 ldr r3, [r4, #0x64]
 *   @0x1b6bd4 str r8, [r4, #0x1c]
 *   @0x1b6bd8 cmp r3, #0
 *   @0x1b6bdc beq 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178>
 *   @0x1b6be0 ldr r0, [r4, #0x58]
 *   @0x1b6be4 cmp r0, #0
 *   @0x1b6be8 beq 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178>
 *   @0x1b6bec cmp r3, #2
 *   @0x1b6bf0 beq 0x1b6c2c <_ZN10ObjectPoolI6CLayerED2Ev+0x190>
 *   @0x1b6bf4 cmp r3, #3
 *   @0x1b6bf8 beq 0x1b6c44 <_ZN10ObjectPoolI6CLayerED2Ev+0x1a8>
 *   @0x1b6bfc cmp r3, #1
 *   @0x1b6c00 beq 0x1b6c5c <_ZN10ObjectPoolI6CLayerED2Ev+0x1c0>
 *   @0x1b6c04 ldr r5, [r0, #0x14]
 *   @0x1b6c08 cmp r5, #0
 *   @0x1b6c0c mov r0, r5
 *   @0x1b6c10 bne 0x1b6c04 <_ZN10ObjectPoolI6CLayerED2Ev+0x168>
 *   @0x1b6c14 str r8, [r4, #0x60]
 *   @0x1b6c18 mov r0, r4
 *   @0x1b6c1c str r8, [r4, #0x5c]
 *   @0x1b6c20 str r8, [r4, #0x58]
 *   @0x1b6c24 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6c28 b 0x1b6ad4 <_ZN10ObjectPoolI6CLayerED2Ev+0x38>
 *   @0x1b6c2c ldr r5, [r0, #0x14]
 *   @0x1b6c30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6c34 cmp r5, #0
 *   @0x1b6c38 mov r0, r5
 *   @0x1b6c3c bne 0x1b6c2c <_ZN10ObjectPoolI6CLayerED2Ev+0x190>
 *   @0x1b6c40 b 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178>
 *   @0x1b6c44 ldr r5, [r0, #0x14]
 *   @0x1b6c48 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6c4c cmp r5, #0
 *   @0x1b6c50 mov r0, r5
 *   @0x1b6c54 bne 0x1b6c44 <_ZN10ObjectPoolI6CLayerED2Ev+0x1a8>
 *   @0x1b6c58 b 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178>
 *   @0x1b6c5c ldr r5, [r0, #0x14]
 *   @0x1b6c60 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6c64 cmp r5, #0
 *   @0x1b6c68 mov r0, r5
 *   @0x1b6c6c bne 0x1b6c5c <_ZN10ObjectPoolI6CLayerED2Ev+0x1c0>
 *   @0x1b6c70 b 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178>
 *   @0x1b6c74 ldr r5, [r0, #0x14]
 *   @0x1b6c78 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6c7c cmp r5, #0
 *   @0x1b6c80 mov r0, r5
 *   @0x1b6c84 bne 0x1b6c74 <_ZN10ObjectPoolI6CLayerED2Ev+0x1d8>
 *   @0x1b6c88 b 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4>
 *
 * ══ §44/60 anon_22fa78  0x22fa78  size 496  124 条（0x22fa78..0x22fc68）
 * @func 0x22fa78 0x22fc68  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×4 / _vorbis_block_alloc×2 / _vorbis_block_ripcord / oggpack_readinit
 * 字段偏移 top8: 0x4×6 / 0x2×5 / 0x20×3 / 0xc×3 / 0x1c×2 / 0x24×2 / 0x40×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22fa78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22fa7c subs r11, r0, #0
 *   @0x22fa80 sub sp, sp, #12
 *   @0x22fa84 mov r5, r1
 *   @0x22fa88 mov r7, r2
 *   @0x22fa8c beq 0x22fba8 <vorbis_book_init_decode+0x5a4>
 *   @0x22fa90 ldr r2, [r11, #0x40]
 *   @0x22fa94 cmp r2, #0
 *   @0x22fa98 beq 0x22fc58 <vorbis_book_init_decode+0x654>
 *   @0x22fa9c ldr r6, [r2, #0x4]
 *   @0x22faa0 ldr r10, [r2, #0x48]
 *   @0x22faa4 cmp r6, #0
 *   @0x22faa8 moveq r9, r6
 *   @0x22faac ldrne r9, [r6, #0x1c]
 *   @0x22fab0 cmp r2, #0
 *   @0x22fab4 cmpne r10, #0
 *   @0x22fab8 add r4, r11, #4
 *   @0x22fabc beq 0x22fba8 <vorbis_book_init_decode+0x5a4>
 *   @0x22fac0 cmp r9, #0
 *   @0x22fac4 cmpne r6, #0
 *   @0x22fac8 beq 0x22fba8 <vorbis_book_init_decode+0x5a4>
 *   @0x22facc cmp r4, #0
 *   @0x22fad0 beq 0x22fba8 <vorbis_book_init_decode+0x5a4>
 *   @0x22fad4 mov r0, r11
 *   @0x22fad8 bl 0x227164 <_vorbis_block_ripcord>
 *   @0x22fadc ldm r5, {r1, r2}
 *   @0x22fae0 mov r0, r4
 *   @0x22fae4 bl 0x23385c <oggpack_readinit>
 *   @0x22fae8 mov r0, r4
 *   @0x22faec mov r1, #1
 *   @0x22faf0 bl 0x233b28 <oggpack_read>
 *   @0x22faf4 cmp r0, #0
 *   @0x22faf8 bne 0x22fc50 <vorbis_book_init_decode+0x64c>
 *   @0x22fafc mov r0, r4
 *   @0x22fb00 ldr r1, [r10, #0x8]
 *   @0x22fb04 bl 0x233b28 <oggpack_read>
 *   @0x22fb08 cmn r0, #1
 *   @0x22fb0c mov r8, r0
 *   @0x22fb10 beq 0x22fba8 <vorbis_book_init_decode+0x5a4>
 *   @0x22fb14 add r2, r9, r0, lsl #2
 *   @0x22fb18 str r2, [sp, #0x4]
 *   @0x22fb1c str r0, [r11, #0x28]
 *   @0x22fb20 ldr r2, [r2, #0x20]
 *   @0x22fb24 cmp r2, #0
 *   @0x22fb28 beq 0x22fba8 <vorbis_book_init_decode+0x5a4>
 *   @0x22fb2c ldr r2, [r2]
 *   @0x22fb30 cmp r2, #0
 *   @0x22fb34 str r2, [r11, #0x1c]
 *   @0x22fb38 streq r2, [r11, #0x18]
 *   @0x22fb3c streq r2, [r11, #0x20]
 *   @0x22fb40 bne 0x22fb80 <vorbis_book_init_decode+0x57c>
 *   @0x22fb44 ldrd r2, r3, [r5, #16]
 *   @0x22fb48 ldrd r0, r1, [r5, #24]
 *   @0x22fb4c strd r2, r3, [r11, #48]
 *   @0x22fb50 subs r4, r0, #3
 *   @0x22fb54 ldr r2, [r5, #0xc]
 *   @0x22fb58 sbc r5, r1, #0
 *   @0x22fb5c cmp r7, #0
 *   @0x22fb60 strd r4, r5, [r11, #56]
 *   @0x22fb64 streq r7, [r11, #0x24]
 *   @0x22fb68 str r2, [r11, #0x2c]
 *   @0x22fb6c moveq r0, r7
 *   @0x22fb70 streq r7, [r11]
 *   @0x22fb74 bne 0x22fbb4 <vorbis_book_init_decode+0x5b0>
 *   @0x22fb78 add sp, sp, #12
 *   @0x22fb7c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22fb80 mov r1, #1
 *   @0x22fb84 mov r0, r4
 *   @0x22fb88 bl 0x233b28 <oggpack_read>
 *   @0x22fb8c mov r1, #1
 *   @0x22fb90 str r0, [r11, #0x18]
 *   @0x22fb94 mov r0, r4
 *   @0x22fb98 bl 0x233b28 <oggpack_read>
 *   @0x22fb9c cmn r0, #1
 *   @0x22fba0 str r0, [r11, #0x20]
 *   @0x22fba4 bne 0x22fb44 <vorbis_book_init_decode+0x540>
 *   @0x22fba8 mvn r0, #135
 *   @0x22fbac add sp, sp, #12
 *   @0x22fbb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22fbb4 ldr r2, [r11, #0x1c]
 *   @0x22fbb8 mov r0, r11
 *   @0x22fbbc ldr r1, [r6, #0x4]
 *   @0x22fbc0 ldr r2, [r9, r2, lsl #2]
 *   @0x22fbc4 lsl r1, r1, #2
 *   @0x22fbc8 str r2, [r11, #0x24]
 *   @0x22fbcc bl 0x2270e4 <_vorbis_block_alloc>
 *   @0x22fbd0 ldr r2, [r6, #0x4]
 *   @0x22fbd4 cmp r2, #0
 *   @0x22fbd8 movgt r4, #0
 *   @0x22fbdc str r0, [r11]
 *   @0x22fbe0 movgt r5, r0
 *   @0x22fbe4 bgt 0x22fbf0 <vorbis_book_init_decode+0x5ec>
 *   @0x22fbe8 b 0x22fc14 <vorbis_book_init_decode+0x610>
 *   @0x22fbec ldr r5, [r11]
 *   @0x22fbf0 ldr r1, [r11, #0x24]
 *   @0x22fbf4 mov r0, r11
 *   @0x22fbf8 lsl r1, r1, #2
 *   @0x22fbfc bl 0x2270e4 <_vorbis_block_alloc>
 *   @0x22fc00 ldr r2, [r6, #0x4]
 *   @0x22fc04 str r0, [r5, r4, lsl #2]
 *   @0x22fc08 add r4, r4, #1
 *   @0x22fc0c cmp r2, r4
 *   @0x22fc10 bgt 0x22fbec <vorbis_book_init_decode+0x5e8>
 *   @0x22fc14 ldr r3, [sp, #0x4]
 *   @0x22fc18 mov r0, r11
 *   @0x22fc1c ldr r1, [r10, #0xc]
 *   @0x22fc20 ldr r2, [r3, #0x20]
 *   @0x22fc24 ldr r3, [pc, #0x3c]
 *   @0x22fc28 ldr r1, [r1, r8, lsl #2]
 *   @0x22fc2c ldr r2, [r2, #0xc]
 *   @0x22fc30 ldr r3, [pc, r3]
 *   @0x22fc34 add r2, r2, #72
 *   @0x22fc38 ldr r2, [r9, r2, lsl #2]
 *   @0x22fc3c ldr r3, [r3, r2, lsl #2]
 *   @0x22fc40 ldr r3, [r3, #0x10]
 *   @0x22fc44 blx r3
 *   @0x22fc48 add sp, sp, #12
 *   @0x22fc4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22fc50 mvn r0, #134
 *   @0x22fc54 b 0x22fb78 <vorbis_book_init_decode+0x574>
 *   @0x22fc58 mov r10, r2
 *   @0x22fc5c mov r6, r2
 *   @0x22fc60 mov r9, r2
 *   @0x22fc64 b 0x22fab0 <vorbis_book_init_decode+0x4ac>
 *
 * ══ §45/60 JS_BooleanObjectSetup()  0x243bf0  size 496  124 条（0x243bf0..0x243de0）
 * @func 0x243bf0 0x243de0  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x243c18→0x756444, 0x243c2c→0x756450, 0x243d38→0x544be0
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×4 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×3 / YYObjectBase::InternalGetYYVar(int)×3 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / YYObjectBase::Add(char const*, bool, int)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x28×2 / 0xe8×2 / 0x190×1 / 0x18c×1 / 0x184×1 / 0x180×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x243bf0 push {r4, r5, r6, r7, r8, lr}
 *   @0x243bf4 sub sp, sp, #24
 *   @0x243bf8 mov r4, #0
 *   @0x243bfc add r0, sp, #8
 *   @0x243c00 mov r1, r4
 *   @0x243c04 mov r2, r4
 *   @0x243c08 mov r3, r4
 *   @0x243c0c str r4, [sp]
 *   @0x243c10 ldr r6, [pc, #0x190]
 *   @0x243c14 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x243c18 ldr r3, [pc, #0x18c]
 *   @0x243c1c add r6, pc, r6
 *   @0x243c20 ldr r5, [sp, #0x8]
 *   @0x243c24 ldr r2, [pc, #0x184]
 *   @0x243c28 ldr r8, [r6, r3]
 *   @0x243c2c ldr r3, [pc, #0x180]
 *   @0x243c30 add r2, pc, r2
 *   @0x243c34 str r2, [r5, #0x40]
 *   @0x243c38 mov r0, r5
 *   @0x243c3c str r5, [r8]
 *   @0x243c40 ldr r3, [r6, r3]
 *   @0x243c44 ldr r1, [r3]
 *   @0x243c48 str r1, [r5, #0x18]
 *   @0x243c4c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x243c50 ldr r1, [r5, #0x28]
 *   @0x243c54 mov r0, r5
 *   @0x243c58 mov r2, r4
 *   @0x243c5c orr r1, r1, #1
 *   @0x243c60 str r1, [r5, #0x28]
 *   @0x243c64 ldr r1, [pc, #0x14c]
 *   @0x243c68 mov r3, r4
 *   @0x243c6c add r1, pc, r1
 *   @0x243c70 bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi>
 *   @0x243c74 ldr r3, [pc, #0x140]
 *   @0x243c78 mov r1, r4
 *   @0x243c7c mov r2, r4
 *   @0x243c80 ldr r0, [r6, r3]
 *   @0x243c84 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243c88 ldr r1, [pc, #0x130]
 *   @0x243c8c mov r3, r4
 *   @0x243c90 add r1, pc, r1
 *   @0x243c94 mov r2, r0
 *   @0x243c98 mov r0, r5
 *   @0x243c9c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243ca0 ldr r3, [pc, #0x11c]
 *   @0x243ca4 mov r1, r4
 *   @0x243ca8 mov r2, r4
 *   @0x243cac ldr r0, [r6, r3]
 *   @0x243cb0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243cb4 ldr r1, [pc, #0x10c]
 *   @0x243cb8 mov r3, r4
 *   @0x243cbc add r1, pc, r1
 *   @0x243cc0 mov r2, r0
 *   @0x243cc4 mov r0, r5
 *   @0x243cc8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243ccc ldr r3, [pc, #0xf8]
 *   @0x243cd0 mov r1, r4
 *   @0x243cd4 mov r2, r4
 *   @0x243cd8 ldr r0, [r6, r3]
 *   @0x243cdc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243ce0 ldr r12, [pc, #0xe8]
 *   @0x243ce4 ldr r1, [pc, #0xe8]
 *   @0x243ce8 mov r3, r4
 *   @0x243cec ldr r12, [r6, r12]
 *   @0x243cf0 add r1, pc, r1
 *   @0x243cf4 mov r7, r0
 *   @0x243cf8 mov r0, r5
 *   @0x243cfc mov r2, r7
 *   @0x243d00 str r12, [r7, #0x94]
 *   @0x243d04 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243d08 ldr r3, [r7, #0x4]
 *   @0x243d0c cmp r3, r4
 *   @0x243d10 beq 0x243d68 <_Z21JS_BooleanObjectSetupv+0x178>
 *   @0x243d14 ldr r1, [r8]
 *   @0x243d18 mov r0, r7
 *   @0x243d1c str r1, [r3]
 *   @0x243d20 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x243d24 ldr r1, [r7, #0x4]
 *   @0x243d28 cmp r1, #0
 *   @0x243d2c movne r3, #6
 *   @0x243d30 strne r3, [r1, #0xc]
 *   @0x243d34 beq 0x243d7c <_Z21JS_BooleanObjectSetupv+0x18c>
 *   @0x243d38 ldr r0, [pc, #0x98]
 *   @0x243d3c mov r3, #6
 *   @0x243d40 str r3, [r1, #0x8]
 *   @0x243d44 mov r2, r7
 *   @0x243d48 ldr r1, [pc, #0x8c]
 *   @0x243d4c mov r3, #0
 *   @0x243d50 ldr r0, [r6, r0]
 *   @0x243d54 add r1, pc, r1
 *   @0x243d58 ldr r0, [r0]
 *   @0x243d5c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243d60 add sp, sp, #24
 *   @0x243d64 pop {r4, r5, r6, r7, r8, pc}
 *   @0x243d68 mov r1, r3
 *   @0x243d6c mov r0, r7
 *   @0x243d70 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243d74 mov r3, r0
 *   @0x243d78 b 0x243d14 <_Z21JS_BooleanObjectSetupv+0x124>
 *   @0x243d7c mov r0, r7
 *   @0x243d80 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243d84 ldr r1, [r7, #0x4]
 *   @0x243d88 mov r3, #6
 *   @0x243d8c cmp r1, #0
 *   @0x243d90 str r3, [r0, #0xc]
 *   @0x243d94 bne 0x243d38 <_Z21JS_BooleanObjectSetupv+0x148>
 *   @0x243d98 mov r0, r7
 *   @0x243d9c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243da0 mov r1, r0
 *   @0x243da4 b 0x243d38 <_Z21JS_BooleanObjectSetupv+0x148>
 *   @0x243da8 andseq lr, r10, r4, lsr r0
 *   @0x243dac .word 0xfffff8d4
 *   @0x243db0 ldrsbeq r1, [r1], -r8
 *   @0x243db4 .word 0xffffc050
 *   @0x243db8 andseq r1, r1, r4, lsr #17
 *   @0x243dbc .word 0xfffffa68
 *   @0x243dc0 andeq lr, lr, r0, lsl #17
 *   @0x243dc4 .word 0xfffffa6c
 *   @0x243dc8 mulseq r1, r12, r9
 *   @0x243dcc .word 0xfffffa70
 *   @0x243dd0 .word 0xfffffa74
 *   @0x243dd4 andseq r1, r1, r4, lsr r8
 *   @0x243dd8 .word 0xffffbf64
 *   @0x243ddc ldrheq r1, [r1], -r4
 *
 * ══ §46/60 Java_com_yoyogames_runner_RunnerJNILib_HttpProgress  0x292f84  size 496  124 条（0x292f84..0x293174）
 * @func 0x292f84 0x293174  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / setJNIEnv / Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x168 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / YYStrDup(char const*)
 * 字段偏移 top8: 0x3c×7 / 0x34×4 / 0x20×3 / 0xc×2 / 0x24×2 / 0x38×2 / 0x30×1 / 0x2ac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292f84 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x292f88 sub sp, sp, #12
 *   @0x292f8c mov r9, r2
 *   @0x292f90 mov r8, r3
 *   @0x292f94 mov r6, r0
 *   @0x292f98 ldr r5, [sp, #0x30]
 *   @0x292f9c ldr r7, [sp, #0x34]
 *   @0x292fa0 bl 0x290614 <setJNIEnv>
 *   @0x292fa4 cmp r9, #0
 *   @0x292fa8 moveq r8, r9
 *   @0x292fac beq 0x292ff4 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x70>
 *   @0x292fb0 ldr r3, [r6]
 *   @0x292fb4 mov r0, r6
 *   @0x292fb8 mov r1, r9
 *   @0x292fbc ldr r3, [r3, #0x2ac]
 *   @0x292fc0 blx r3
 *   @0x292fc4 cmp r8, r0
 *   @0x292fc8 beq 0x292ff4 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x70>
 *   @0x292fcc ldr r12, [pc, #0x190]
 *   @0x292fd0 mov r2, r0
 *   @0x292fd4 ldr r1, [pc, #0x18c]
 *   @0x292fd8 mov r3, r8
 *   @0x292fdc ldr r12, [pc, r12]
 *   @0x292fe0 add r1, pc, r1
 *   @0x292fe4 ldr r0, [r12]
 *   @0x292fe8 ldr r12, [r0]
 *   @0x292fec ldr r12, [r12, #0xc]
 *   @0x292ff0 blx r12
 *   @0x292ff4 cmp r7, #0
 *   @0x292ff8 moveq r10, r7
 *   @0x292ffc beq 0x29301c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x98>
 *   @0x293000 ldr r3, [r6]
 *   @0x293004 mov r0, r6
 *   @0x293008 mov r1, r7
 *   @0x29300c mov r2, #0
 *   @0x293010 ldr r3, [r3, #0x2a4]
 *   @0x293014 blx r3
 *   @0x293018 mov r10, r0
 *   @0x29301c ldr r12, [pc, #0x148]
 *   @0x293020 ldr r12, [pc, r12]
 *   @0x293024 ldr r4, [r12]
 *   @0x293028 cmp r4, #0
 *   @0x29302c beq 0x293058 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xd4>
 *   @0x293030 ldr r3, [r4, #0x24]
 *   @0x293034 cmp r3, r5
 *   @0x293038 bne 0x29304c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xc8>
 *   @0x29303c b 0x29308c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x108>
 *   @0x293040 ldr r12, [r4, #0x24]
 *   @0x293044 cmp r12, r5
 *   @0x293048 beq 0x29308c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x108>
 *   @0x29304c ldr r4, [r4, #0x4]
 *   @0x293050 cmp r4, #0
 *   @0x293054 bne 0x293040 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xbc>
 *   @0x293058 cmp r10, #0
 *   @0x29305c cmpne r7, #0
 *   @0x293060 bne 0x29306c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xe8>
 *   @0x293064 add sp, sp, #12
 *   @0x293068 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29306c ldr r3, [r6]
 *   @0x293070 mov r1, r7
 *   @0x293074 mov r2, r10
 *   @0x293078 mov r0, r6
 *   @0x29307c ldr r3, [r3, #0x2a8]
 *   @0x293080 blx r3
 *   @0x293084 add sp, sp, #12
 *   @0x293088 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29308c ldr r3, [r4, #0x3c]
 *   @0x293090 ldr r2, [r4, #0x38]
 *   @0x293094 add r12, r3, r8
 *   @0x293098 cmp r12, r2
 *   @0x29309c ble 0x2930ec <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0x168>
 *   @0x2930a0 ldr r0, [sp, #0x3c]
 *   @0x2930a4 mov r3, #1
 *   @0x2930a8 ldr r1, [pc, #0xc0]
 *   @0x2930ac cmp r2, r0
 *   @0x2930b0 mov r2, #70
 *   @0x2930b4 addge r11, r12, #65536
 *   @0x2930b8 add r1, pc, r1
 *   @0x2930bc ldrlt r11, [sp, #0x3c]
 *   @0x2930c0 ldr r5, [r4, #0x34]
 *   @0x2930c4 mov r0, r11
 *   @0x2930c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2930cc mov r1, r5
 *   @0x2930d0 ldr r2, [r4, #0x3c]
 *   @0x2930d4 str r0, [r4, #0x34]
 *   @0x2930d8 bl 0xb65bc <memcpy@plt>
 *   @0x2930dc mov r0, r5
 *   @0x2930e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2930e4 ldr r3, [r4, #0x3c]
 *   @0x2930e8 str r11, [r4, #0x38]
 *   @0x2930ec ldr r12, [r6]
 *   @0x2930f0 mov r2, #3
 *   @0x2930f4 ldr r0, [sp, #0x3c]
 *   @0x2930f8 mov r1, r9
 *   @0x2930fc ldr lr, [r4, #0x34]
 *   @0x293100 str r2, [r4, #0xc]
 *   @0x293104 mov r2, #0
 *   @0x293108 str r0, [r4, #0x40]
 *   @0x29310c add r3, lr, r3
 *   @0x293110 mov r0, r6
 *   @0x293114 str r3, [sp]
 *   @0x293118 mov r3, r8
 *   @0x29311c ldr r12, [r12, #0x320]
 *   @0x293120 blx r12
 *   @0x293124 ldr r3, [r4, #0x3c]
 *   @0x293128 cmp r10, #0
 *   @0x29312c add r8, r3, r8
 *   @0x293130 str r8, [r4, #0x3c]
 *   @0x293134 beq 0x293064 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xe0>
 *   @0x293138 ldr r0, [r4, #0x20]
 *   @0x29313c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x293140 mov r3, #0
 *   @0x293144 mov r0, r10
 *   @0x293148 str r3, [r4, #0x20]
 *   @0x29314c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x293150 cmp r10, #0
 *   @0x293154 cmpne r7, #0
 *   @0x293158 str r0, [r4, #0x20]
 *   @0x29315c beq 0x293064 <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xe0>
 *   @0x293160 b 0x29306c <Java_com_yoyogames_runner_RunnerJNILib_HttpProgress+0xe8>
 *   @0x293164 andseq r10, r5, r4, ror #18
 *   @0x293168 andeq r6, r12, r8, asr #1
 *   @0x29316c ldrsbeq r10, [r5], -r8
 *   @0x293170 andeq sp, r9, r8, ror pc
 *
 * ══ §47/60 png_do_read_filler  0x2a8ebe  size 494  124 条（0x2a8ebe..0x2a90ac）
 * @func 0x2a8ebe 0x2a90ae  size 496  124 条
 * 部分覆盖: 本节 124/213 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-1×8 / 0x-2×6 / 0x1a×5 / 0x-3×5 / 0xa×4 / 0x-4×4 / 0x4×3 / 0x9×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8ebe push {r4, r5, r6, r7, lr}
 *   @0x2a8ec2 bvc 0x4322e6 <g_RomDisk+0x3aac6>
 *   @0x2a8ec6 uxtb r2, r2
 *   @0x2a8eca cmp r6, #0x0
 *   @0x2a8ece ldrb r6, [r0, #0x9]
 *   @0x2a8ed2 bne 0x2a8f16 <png_do_read_filler+0x58>
 *   @0x2a8ed6 strtmi r0, [r1], #-3968
 *   @0x2a8eda add.w r3, r1, r4
 *   @0x2a8ede beq 0x2a8ef6 <png_do_read_filler+0x38>
 *   @0x2a8ee2 cmp r5, r4
 *   @0x2a8ee6 andle r2, pc, #256
 *   @0x2a8eea ldrb r6, [r1, #-1]!
 *   @0x2a8eee adds r5, #0x1
 *   @0x2a8ef2 ldrb r6, [r5, r2, lsl #26]!
 *   @0x2a8ef6 subs r5, r1, r4
 *   @0x2a8efa beq 0x2a8f0a <png_do_read_filler+0x4c>
 *   @0x2a8efe .word 0xf8036d01
 *   @0x2a8f02 .word 0xf8036c01
 *   @0x2a8f06 ldrb r2, [r6, r2, lsl #26]!
 *   @0x2a8f0a movs r3, #0x2
 *   @0x2a8f0e strb r3, [r0, #0xa]
 *   @0x2a8f12 strb r3, [r0, #0xb]
 *   @0x2a8f16 cmp r6, #0x10
 *   @0x2a8f1a .word 0xf01380c7
 *   @0x2a8f1e b 0x1669d26 <b2_toiTime+0xf10882>
 *   @0x2a8f22 ldrtmi r0, [r1], #-1604
 *   @0x2a8f26 beq 0x2a8f50 <png_do_read_filler+0x92>
 *   @0x2a8f2a movs r6, #0x1
 *   @0x2a8f2e strb r5, [r3, #-1]
 *   @0x2a8f32 strb r2, [r3, #-2]
 *   @0x2a8f36 bhs 0x2a8f4c <png_do_read_filler+0x8e>
 *   @0x2a8f3a strlo r7, [r1], -r1, lsl #24
 *   @0x2a8f3e strb r7, [r3, #-3]
 *   @0x2a8f42 ldrb r7, [r1, #-2]!
 *   @0x2a8f46 strb r7, [r3, #-4]!
 *   @0x2a8f4a b 0x2a8f2c <png_do_read_filler+0x6e>
 *   @0x2a8f4e b 0x2a8fee <png_do_read_filler+0x130>
 *   @0x2a8f52 cmp r3, r4
 *   @0x2a8f56 ldrb r7, [r1, #-1]
 *   @0x2a8f5a adds r3, #0x1
 *   @0x2a8f5e .word 0xf8117c01
 *   @0x2a8f62 .word 0xf8067d02
 *   @0x2a8f66 .word 0xf8065c03
 *   @0x2a8f6a .word 0xf8067c02
 *   @0x2a8f6e strb r2, [pc, r4, lsl #26]!
 *   @0x2a8f72 movs r2, #0x2
 *   @0x2a8f76 strb r2, [r0, #0xa]
 *   @0x2a8f7a str r3, [r0, #0x4]
 *   @0x2a8f7e pop {r4, r5, r6, r7, pc}
 *   @0x2a8f82 bne.w 0x2a90aa <png_do_read_filler+0x1ec>
 *   @0x2a8f86 ldrb r6, [r0, #0x9]
 *   @0x2a8f8a bne 0x2a8ff8 <png_do_read_filler+0x13a>
 *   @0x2a8f8e .word 0xf04f0f80
 *   @0x2a8f92 andsle r0, r5, r3, lsl #10
 *   @0x2a8f96 mla r1, r5, r4, r1
 *   @0x2a8f9a movs r5, #0x1
 *   @0x2a8f9e cmp r5, r4
 *   @0x2a8fa2 eorle r2, r2, #256
 *   @0x2a8fa6 ldrb r6, [r1, #-1]
 *   @0x2a8faa adds r5, #0x1
 *   @0x2a8fae .word 0xf8116c02
 *   @0x2a8fb2 .word 0xf8036c02
 *   @0x2a8fb6 .word 0xf8116c03
 *   @0x2a8fba .word 0xf8036d03
 *   @0x2a8fbe strb r6, [sp, r4, lsl #26]!
 *   @0x2a8fc2 muls r5, r4, r5
 *   @0x2a8fc6 adds r3, r1, r4
 *   @0x2a8fca cmp r1, r5
 *   @0x2a8fce ldrb r6, [r1, #-1]
 *   @0x2a8fd2 strb r6, [r3, #-1]
 *   @0x2a8fd6 ldrb r6, [r1, #-2]
 *   @0x2a8fda strb r6, [r3, #-2]
 *   @0x2a8fde ldrb r6, [r1, #-3]!
 *   @0x2a8fe2 strb r6, [r3, #-3]
 *   @0x2a8fe6 strb r2, [r3, #-4]!
 *   @0x2a8fea b 0x2a8fca <png_do_read_filler+0x10c>
 *   @0x2a8fee strb r3, [r0, #0xa]
 *   @0x2a8ff2 movs r3, #0x20
 *   @0x2a8ff6 b 0x2a905a <png_do_read_filler+0x19c>
 *   @0x2a8ffa bne 0x2a90aa <png_do_read_filler+0x1ec>
 *   @0x2a8ffe ands r6, r3, #0x80
 *   @0x2a9002 mla r1, r7, r4, r1
 *   @0x2a9006 lsl.w r3, r4, #0x1
 *   @0x2a900a add r3, r1
 *   @0x2a900e movs r6, #0x1
 *   @0x2a9012 strb r5, [r3, #-1]
 *   @0x2a9016 strb r2, [r3, #-2]
 *   @0x2a901a bhs 0x2a9050 <png_do_read_filler+0x192>
 *   @0x2a901e strlo r7, [r1], -r1, lsl #24
 *   @0x2a9022 strb r7, [r3, #-3]
 *   @0x2a9026 ldrb r7, [r1, #-2]
 *   @0x2a902a strb r7, [r3, #-4]
 *   @0x2a902e ldrb r7, [r1, #-3]
 *   @0x2a9032 strb r7, [r3, #-5]
 *   @0x2a9036 ldrb r7, [r1, #-4]
 *   @0x2a903a strb r7, [r3, #-6]
 *   @0x2a903e ldrb r7, [r1, #-5]
 *   @0x2a9042 strb r7, [r3, #-7]
 *   @0x2a9046 ldrb r7, [r1, #-6]!
 *   @0x2a904a strb r7, [r3, #-8]!
 *   @0x2a904e b 0x2a9010 <png_do_read_filler+0x152>
 *   @0x2a9052 movs r3, #0x4
 *   @0x2a9056 movs r3, #0x40
 *   @0x2a905a str r4, [r0, #0x4]
 *   @0x2a905e cmp r6, r4
 *   @0x2a9062 ldrb r7, [r1, #-1]
 *   @0x2a9066 adds r6, #0x1
 *   @0x2a906a .word 0xf8117c01
 *   @0x2a906e .word 0xf8037c02
 *   @0x2a9072 .word 0xf8117c02
 *   @0x2a9076 .word 0xf8037c03
 *   @0x2a907a .word 0xf8117c03
 *   @0x2a907e .word 0xf8037c04
 *   @0x2a9082 .word 0xf8117c04
 *   @0x2a9086 .word 0xf8037c05
 *   @0x2a908a .word 0xf8117c05
 *   @0x2a908e .word 0xf8037d06
 *   @0x2a9092 .word 0xf8035c07
 *   @0x2a9096 .word 0xf8037c06
 *   @0x2a909a ldrb r2, [pc, r8, lsl #26]
 *   @0x2a909e movs r3, #0x4
 *   @0x2a90a2 strb r3, [r0, #0xa]
 *   @0x2a90a6 str r6, [r0, #0x4]
 *   @0x2a90aa pop {r4, r5, r6, r7, pc}
 *
 * ══ §48/60 F_ExternalDefine(RValue&, CInstance*, CInstance*, int, RValue*)  0x11485c  size 492  123 条（0x11485c..0x114a48）
 * @func 0x11485c 0x114a48  size 492  123 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / Error_Show_Action(char const*, bool)×4 / YYGetString(RValue const*, int)×2 / 0xb65b0 / F_ExternalDefine(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4 / F_ExternalDefine(RValue&, CInstance*, CInstance*, int, RValue*)+0xd8 / F_ExternalDefine(RValue&, CInstance*, CInstance*, int, RValue*)+0x130 / DLL_Define(char const*, char const*, int, int, int*, int)
 * 字段偏移 top8: 0xc×4 / 0x14×3 / 0x4×2 / 0x8×2 / 0x10×2 / 0x88×1 / 0x130×1 / 0x114×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11485c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x114860 sub sp, sp, #100
 *   @0x114864 add r7, sp, #28
 *   @0x114868 mov r11, #0
 *   @0x11486c ldr r4, [sp, #0x88]
 *   @0x114870 mov r1, r11
 *   @0x114874 str r11, [r0]
 *   @0x114878 mov r5, r0
 *   @0x11487c str r11, [r0, #0xc]
 *   @0x114880 mov r2, r11
 *   @0x114884 movt r2, #0xbff0
 *   @0x114888 str r2, [r0, #0x4]
 *   @0x11488c mov r2, #68
 *   @0x114890 mov r0, r7
 *   @0x114894 mov r9, r3
 *   @0x114898 bl 0xb65b0 <memset@plt>
 *   @0x11489c mov r1, r11
 *   @0x1148a0 mov r0, r4
 *   @0x1148a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1148a8 mov r1, #1
 *   @0x1148ac str r0, [sp, #0x8]
 *   @0x1148b0 mov r0, r4
 *   @0x1148b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1148b8 mov r1, #2
 *   @0x1148bc str r0, [sp, #0xc]
 *   @0x1148c0 mov r0, r4
 *   @0x1148c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1148c8 mov r1, #3
 *   @0x1148cc str r0, [sp, #0x10]
 *   @0x1148d0 mov r0, r4
 *   @0x1148d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1148d8 mov r1, #4
 *   @0x1148dc mov r10, r0
 *   @0x1148e0 mov r0, r4
 *   @0x1148e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1148e8 cmp r9, #4
 *   @0x1148ec mov r8, r0
 *   @0x1148f0 ble 0x114900 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1148f4 add r6, r0, #5
 *   @0x1148f8 cmp r6, r9
 *   @0x1148fc beq 0x114918 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x114900 ldr r0, [pc, #0x130]
 *   @0x114904 mov r1, #0
 *   @0x114908 add r0, pc, r0
 *   @0x11490c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x114910 add sp, sp, #100
 *   @0x114914 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x114918 cmp r0, #16
 *   @0x11491c ble 0x114934 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x114920 ldr r0, [pc, #0x114]
 *   @0x114924 mov r1, r11
 *   @0x114928 add r0, pc, r0
 *   @0x11492c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x114930 b 0x114910 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x114934 cmp r0, #4
 *   @0x114938 movgt r11, #5
 *   @0x11493c bgt 0x1149f0 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x114940 subs r2, r10, #1
 *   @0x114944 rsbs r10, r2, #0
 *   @0x114948 adcs r10, r10, r2
 *   @0x11494c cmp r8, #0
 *   @0x114950 str r10, [sp, #0x14]
 *   @0x114954 ble 0x11498c <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x114958 mov r9, #0
 *   @0x11495c mov r10, #5
 *   @0x114960 mov r11, r9
 *   @0x114964 mov r1, r10
 *   @0x114968 mov r0, r4
 *   @0x11496c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114970 add r10, r10, #1
 *   @0x114974 cmp r0, #1
 *   @0x114978 movne r0, r11
 *   @0x11497c cmp r10, r6
 *   @0x114980 str r0, [r7, r9]
 *   @0x114984 add r9, r9, #4
 *   @0x114988 bne 0x114964 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x11498c ldr r3, [sp, #0x14]
 *   @0x114990 mov r4, #0
 *   @0x114994 str r7, [sp]
 *   @0x114998 ldr r1, [sp, #0xc]
 *   @0x11499c str r3, [sp, #0x4]
 *   @0x1149a0 mov r3, r8
 *   @0x1149a4 ldr r2, [sp, #0x10]
 *   @0x1149a8 ldr r0, [sp, #0x8]
 *   @0x1149ac str r4, [r5, #0xc]
 *   @0x1149b0 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x1149b4 vmov.f64 d7, #-1.000000e+00
 *   @0x1149b8 vmov s13, r0
 *   @0x1149bc vcvt.f64.s32 d6, s13
 *   @0x1149c0 vmov r0, r1, d6
 *   @0x1149c4 vmov r2, s12
 *   @0x1149c8 vcmp.f64 d6, d7
 *   @0x1149cc vmrs APSR_nzcv, fpscr
 *   @0x1149d0 mov r3, r1
 *   @0x1149d4 stm r5, {r2, r3}
 *   @0x1149d8 bne 0x114910 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x1149dc ldr r0, [pc, #0x5c]
 *   @0x1149e0 mov r1, r4
 *   @0x1149e4 add r0, pc, r0
 *   @0x1149e8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1149ec b 0x114910 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x1149f0 mov r1, r11
 *   @0x1149f4 mov r0, r4
 *   @0x1149f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1149fc add r11, r11, #1
 *   @0x114a00 cmp r0, #0
 *   @0x114a04 bne 0x114a24 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x114a08 cmp r11, r6
 *   @0x114a0c bne 0x1149f0 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x114a10 subs r3, r10, #1
 *   @0x114a14 rsbs r10, r3, #0
 *   @0x114a18 adcs r10, r10, r3
 *   @0x114a1c str r10, [sp, #0x14]
 *   @0x114a20 b 0x114958 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x114a24 ldr r0, [pc, #0x18]
 *   @0x114a28 mov r1, #0
 *   @0x114a2c add r0, pc, r0
 *   @0x114a30 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x114a34 b 0x114910 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x114a38 eoreq r4, r2, r0, lsr #26
 *   @0x114a3c eoreq r4, r2, r0, lsr #27
 *   @0x114a40 .word 0x00224cbc
 *   @0x114a44 eoreq r4, r2, r12, lsr #24
 *
 * ══ §49/60 GR_Texture_Draw_Pos(YYTPageEntry*, float, float, float, float, float, float, float, float, unsigned int, float)  0x17467c  size 492  123 条（0x17467c..0x174868）
 * @func 0x17467c 0x174868  size 492  123 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / Graphics::AllocVerts(ePrimType, void*, int, int) / GR_Texture_Draw_Pos(YYTPageEntry*, float, float, float, float, float, float, float, float, unsigned int, float)+0x1cc
 * 字段偏移 top8: 0x4×2 / 0x3c×2 / 0x1a4×1 / 0x2×1 / 0x154×1 / 0x12c×1 / 0xc×1 / 0x84×1
 * VFP 指令 45 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17467c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x174680 subs r4, r0, #0
 *   @0x174684 mov r7, r1
 *   @0x174688 mov r6, r2
 *   @0x17468c mov r8, r3
 *   @0x174690 beq 0x1746a4 <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf+0x28>
 *   @0x174694 ldrsh r0, [r4, #20]
 *   @0x174698 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x17469c subs r5, r0, #0
 *   @0x1746a0 bne 0x1746b0 <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf+0x34>
 *   @0x1746a4 mov r5, #0
 *   @0x1746a8 mov r0, r5
 *   @0x1746ac pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1746b0 ldr r1, [pc, #0x1a4]
 *   @0x1746b4 mov r0, #4
 *   @0x1746b8 ldrsh r12, [r4, #20]
 *   @0x1746bc mov r2, #24
 *   @0x1746c0 ldr r1, [pc, r1]
 *   @0x1746c4 mov r3, #6
 *   @0x1746c8 ldr r1, [r1, #0x4]
 *   @0x1746cc ldr r9, [r1, r12, lsl #2]
 *   @0x1746d0 ldr r1, [r9]
 *   @0x1746d4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1746d8 vldr s15, [pc, #376]
 *   @0x1746dc vldr s14, [sp, #64]
 *   @0x1746e0 vmul.f32 s15, s14, s15
 *   @0x1746e4 vcvt.s32.f32 s15, s15
 *   @0x1746e8 mov r12, r0
 *   @0x1746ec vmov r0, s15
 *   @0x1746f0 cmp r0, #255
 *   @0x1746f4 movgt r0, #-16777216
 *   @0x1746f8 ble 0x174848 <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf+0x1cc>
 *   @0x1746fc ldrsh r11, [r4]
 *   @0x174700 vldr s11, [r9, #8]
 *   @0x174704 ldr r3, [pc, #0x154]
 *   @0x174708 ldr r1, [sp, #0x3c]
 *   @0x17470c vmov s14, r11
 *   @0x174710 ldr r3, [pc, r3]
 *   @0x174714 bic r2, r1, #-16777216
 *   @0x174718 str r6, [r12, #0x4]
 *   @0x17471c vcvt.f32.s32 s15, s14
 *   @0x174720 ldrb r3, [r3]
 *   @0x174724 orr r0, r0, r2
 *   @0x174728 vldr s14, [sp, #40]
 *   @0x17472c cmp r3, #0
 *   @0x174730 ldr r3, [pc, #0x12c]
 *   @0x174734 bicne r0, r0, #65536
 *   @0x174738 vstr s14, [r12, #28]
 *   @0x17473c ldr r3, [pc, r3]
 *   @0x174740 bicne r0, r0, #1
 *   @0x174744 orrne r2, r0, #65536
 *   @0x174748 moveq r2, r0
 *   @0x17474c ldr r3, [r3]
 *   @0x174750 vldr s14, [sp, #44]
 *   @0x174754 vmul.f32 s15, s15, s11
 *   @0x174758 orrne r10, r0, #1
 *   @0x17475c orrne r1, r2, #1
 *   @0x174760 moveq r1, r0
 *   @0x174764 moveq r10, r0
 *   @0x174768 vstr s14, [r12, #48]
 *   @0x17476c str r0, [r12, #0xc]
 *   @0x174770 vldr s14, [sp, #48]
 *   @0x174774 str r0, [r12, #0x84]
 *   @0x174778 vstr s14, [r12, #52]
 *   @0x17477c str r2, [r12, #0x3c]
 *   @0x174780 vldr s14, [sp, #44]
 *   @0x174784 str r3, [r12, #0x68]
 *   @0x174788 vstr s14, [r12, #72]
 *   @0x17478c str r2, [r12, #0x54]
 *   @0x174790 vldr s14, [sp, #48]
 *   @0x174794 str r3, [r12, #0x38]
 *   @0x174798 vstr s14, [r12, #76]
 *   @0x17479c str r7, [r12]
 *   @0x1747a0 vldr s14, [sp, #52]
 *   @0x1747a4 str r8, [r12, #0x18]
 *   @0x1747a8 vstr s14, [r12, #96]
 *   @0x1747ac str r7, [r12, #0x78]
 *   @0x1747b0 vldr s14, [sp, #56]
 *   @0x1747b4 str r6, [r12, #0x7c]
 *   @0x1747b8 vstr s14, [r12, #100]
 *   @0x1747bc str r10, [r12, #0x24]
 *   @0x1747c0 mov r0, r5
 *   @0x1747c4 str r1, [r12, #0x6c]
 *   @0x1747c8 vstr s15, [r12, #112]
 *   @0x1747cc vstr s15, [r12, #16]
 *   @0x1747d0 vstr s15, [r12, #136]
 *   @0x1747d4 str r3, [r12, #0x50]
 *   @0x1747d8 vldr s12, [r9, #12]
 *   @0x1747dc str r3, [r12, #0x20]
 *   @0x1747e0 str r3, [r12, #0x8]
 *   @0x1747e4 str r3, [r12, #0x80]
 *   @0x1747e8 ldrsh r3, [r4, #2]
 *   @0x1747ec vmov s15, r3
 *   @0x1747f0 vcvt.f32.s32 s13, s15
 *   @0x1747f4 vmul.f32 s13, s13, s12
 *   @0x1747f8 vstr s13, [r12, #44]
 *   @0x1747fc vstr s13, [r12, #20]
 *   @0x174800 vstr s13, [r12, #140]
 *   @0x174804 ldrsh r2, [r4, #4]
 *   @0x174808 add r2, r11, r2
 *   @0x17480c vmov s14, r2
 *   @0x174810 vcvt.f32.s32 s14, s14
 *   @0x174814 vmul.f32 s14, s11, s14
 *   @0x174818 vstr s14, [r12, #64]
 *   @0x17481c vstr s14, [r12, #88]
 *   @0x174820 vstr s14, [r12, #40]
 *   @0x174824 ldrsh r2, [r4, #6]
 *   @0x174828 add r2, r3, r2
 *   @0x17482c vmov s15, r2
 *   @0x174830 vcvt.f32.s32 s15, s15
 *   @0x174834 vmul.f32 s15, s12, s15
 *   @0x174838 vstr s15, [r12, #116]
 *   @0x17483c vstr s15, [r12, #68]
 *   @0x174840 vstr s15, [r12, #92]
 *   @0x174844 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x174848 cmp r0, #0
 *   @0x17484c lslge r0, r0, #24
 *   @0x174850 movlt r0, #0
 *   @0x174854 b 0x1746fc <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf+0x80>
 *   @0x174858 cmnmi pc, #0
 *   @0x17485c eoreq r9, r7, r12, asr r2
 *   @0x174860 eoreq r9, r7, r12, lsr r7
 *   @0x174864 eoreq r9, r7, r4, ror #3
 *
 * ══ §50/60 _spRotateTimeline_apply  0x281a2c  size 492  123 条（0x281a2c..0x281c18）
 * @func 0x281a2c 0x281c18  size 492  123 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spRotateTimeline_apply+0xc0 / _spRotateTimeline_apply+0x88 / anon_280ed0 / spCurveTimeline_getCurvePercent / _spRotateTimeline_apply+0x14c / _spRotateTimeline_apply+0x1ac
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x8×1 / 0x14×1 / 0x2×1
 * VFP 指令 80 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281a2c push {r3, r4, r5, r6, r7, lr}
 *   @0x281a30 vpush {d8}
 *   @0x281a34 vmov s16, r3
 *   @0x281a38 ldr r5, [r0, #0x10]
 *   @0x281a3c vldr s15, [r5]
 *   @0x281a40 vcmpe.f32 s15, s16
 *   @0x281a44 mov r4, r0
 *   @0x281a48 vmrs APSR_nzcv, fpscr
 *   @0x281a4c bgt 0x281ae4 <_spRotateTimeline_apply+0xb8>
 *   @0x281a50 ldr r2, [r0, #0xc]
 *   @0x281a54 ldr r1, [r1, #0x8]
 *   @0x281a58 sub r3, r2, #2
 *   @0x281a5c ldr r0, [r0, #0x14]
 *   @0x281a60 add r3, r5, r3, lsl #2
 *   @0x281a64 vldr s15, [r3]
 *   @0x281a68 vcmpe.f32 s16, s15
 *   @0x281a6c ldr r6, [r1, r0, lsl #2]
 *   @0x281a70 vmrs APSR_nzcv, fpscr
 *   @0x281a74 blt 0x281aec <_spRotateTimeline_apply+0xc0>
 *   @0x281a78 ldr r2, [r6]
 *   @0x281a7c vldr s15, [r3, #4]
 *   @0x281a80 vldr s14, [r2, #24]
 *   @0x281a84 vadd.f32 s15, s14, s15
 *   @0x281a88 vldr s12, [r6, #28]
 *   @0x281a8c vldr s13, [pc, #376]
 *   @0x281a90 vsub.f32 s15, s15, s12
 *   @0x281a94 vcmpe.f32 s15, s13
 *   @0x281a98 vmrs APSR_nzcv, fpscr
 *   @0x281a9c ble 0x281ab4 <_spRotateTimeline_apply+0x88>
 *   @0x281aa0 vldr s14, [pc, #360]
 *   @0x281aa4 vsub.f32 s15, s15, s14
 *   @0x281aa8 vcmpe.f32 s15, s13
 *   @0x281aac vmrs APSR_nzcv, fpscr
 *   @0x281ab0 bgt 0x281aa4 <_spRotateTimeline_apply+0x78>
 *   @0x281ab4 vldr s13, [pc, #344]
 *   @0x281ab8 vcmpe.f32 s15, s13
 *   @0x281abc vmrs APSR_nzcv, fpscr
 *   @0x281ac0 bpl 0x281ad8 <_spRotateTimeline_apply+0xac>
 *   @0x281ac4 vldr s14, [pc, #324]
 *   @0x281ac8 vadd.f32 s15, s15, s14
 *   @0x281acc vcmpe.f32 s15, s13
 *   @0x281ad0 vmrs APSR_nzcv, fpscr
 *   @0x281ad4 bmi 0x281ac8 <_spRotateTimeline_apply+0x9c>
 *   @0x281ad8 vldr s14, [sp, #40]
 *   @0x281adc vmla.f32 s12, s15, s14
 *   @0x281ae0 vstr s12, [r6, #28]
 *   @0x281ae4 vpop {d8}
 *   @0x281ae8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x281aec mov r1, r2
 *   @0x281af0 vmov.f32 s0, s16
 *   @0x281af4 mov r0, r5
 *   @0x281af8 mov r2, #2
 *   @0x281afc bl 0x280ed0 <printbuf_free+0x20>
 *   @0x281b00 vmov.f32 s14, #1.000000e+00
 *   @0x281b04 sub r7, r0, #1
 *   @0x281b08 asr r1, r0, #1
 *   @0x281b0c sub r1, r1, #1
 *   @0x281b10 mov r0, r4
 *   @0x281b14 lsl r7, r7, #2
 *   @0x281b18 add r5, r5, r7
 *   @0x281b1c vldr s15, [r5, #4]
 *   @0x281b20 vldr s13, [r5, #-4]
 *   @0x281b24 vsub.f32 s16, s16, s15
 *   @0x281b28 vldr s17, [r5]
 *   @0x281b2c vsub.f32 s15, s13, s15
 *   @0x281b30 vdiv.f32 s15, s16, s15
 *   @0x281b34 vsub.f32 s14, s14, s15
 *   @0x281b38 vmov r2, s14
 *   @0x281b3c bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x281b40 ldr r3, [r4, #0x10]
 *   @0x281b44 vldr s12, [pc, #192]
 *   @0x281b48 add r7, r3, r7
 *   @0x281b4c vldr s14, [r7, #8]
 *   @0x281b50 vsub.f32 s14, s14, s17
 *   @0x281b54 vcmpe.f32 s14, s12
 *   @0x281b58 vmrs APSR_nzcv, fpscr
 *   @0x281b5c vmov s15, r0
 *   @0x281b60 ble 0x281b78 <_spRotateTimeline_apply+0x14c>
 *   @0x281b64 vldr s13, [pc, #164]
 *   @0x281b68 vsub.f32 s14, s14, s13
 *   @0x281b6c vcmpe.f32 s14, s12
 *   @0x281b70 vmrs APSR_nzcv, fpscr
 *   @0x281b74 bgt 0x281b68 <_spRotateTimeline_apply+0x13c>
 *   @0x281b78 vldr s12, [pc, #148]
 *   @0x281b7c vcmpe.f32 s14, s12
 *   @0x281b80 vmrs APSR_nzcv, fpscr
 *   @0x281b84 bpl 0x281b9c <_spRotateTimeline_apply+0x170>
 *   @0x281b88 vldr s13, [pc, #128]
 *   @0x281b8c vadd.f32 s14, s14, s13
 *   @0x281b90 vcmpe.f32 s14, s12
 *   @0x281b94 vmrs APSR_nzcv, fpscr
 *   @0x281b98 bmi 0x281b8c <_spRotateTimeline_apply+0x160>
 *   @0x281b9c vmla.f32 s17, s14, s15
 *   @0x281ba0 ldr r3, [r6]
 *   @0x281ba4 vldr s14, [r3, #24]
 *   @0x281ba8 vldr s12, [r6, #28]
 *   @0x281bac vldr s13, [pc, #88]
 *   @0x281bb0 vadd.f32 s15, s17, s14
 *   @0x281bb4 vsub.f32 s15, s15, s12
 *   @0x281bb8 vcmpe.f32 s15, s13
 *   @0x281bbc vmrs APSR_nzcv, fpscr
 *   @0x281bc0 ble 0x281bd8 <_spRotateTimeline_apply+0x1ac>
 *   @0x281bc4 vldr s14, [pc, #68]
 *   @0x281bc8 vsub.f32 s15, s15, s14
 *   @0x281bcc vcmpe.f32 s15, s13
 *   @0x281bd0 vmrs APSR_nzcv, fpscr
 *   @0x281bd4 bgt 0x281bc8 <_spRotateTimeline_apply+0x19c>
 *   @0x281bd8 vldr s13, [pc, #52]
 *   @0x281bdc vcmpe.f32 s15, s13
 *   @0x281be0 vmrs APSR_nzcv, fpscr
 *   @0x281be4 bpl 0x281ad8 <_spRotateTimeline_apply+0xac>
 *   @0x281be8 vldr s14, [pc, #32]
 *   @0x281bec vadd.f32 s15, s15, s14
 *   @0x281bf0 vcmpe.f32 s15, s13
 *   @0x281bf4 vmrs APSR_nzcv, fpscr
 *   @0x281bf8 bmi 0x281bec <_spRotateTimeline_apply+0x1c0>
 *   @0x281bfc vldr s14, [sp, #40]
 *   @0x281c00 vmla.f32 s12, s15, s14
 *   @0x281c04 vstr s12, [r6, #28]
 *   @0x281c08 b 0x281ae4 <_spRotateTimeline_apply+0xb8>
 *   @0x281c0c teqmi r4, #0
 *   @0x281c10 .word 0x43b40000
 *   @0x281c14 teqgt r4, #0
 *
 * ══ §51/60 spSkeletonBounds_update  0x28a8b4  size 492  123 条（0x28a8b4..0x28aaa0）
 * @func 0x28a8b4 0x28aaa0  size 492  123 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2 / spSkeletonBounds_update+0x184 / spSkeletonBounds_update+0x180 / spPolygon_dispose / spPolygon_create / spBoundingBoxAttachment_computeWorldVertices / spSkeletonBounds_update+0x164 / _malloc
 * 字段偏移 top8: 0x10×6 / 0x4×6 / 0x8×6 / 0x1c×3 / 0x2×3 / 0x20×3 / 0x14×2 / 0x18×2
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a8b4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x28a8b8 mov r10, r1
 *   @0x28a8bc ldr r3, [r0, #0x1c]
 *   @0x28a8c0 mov r4, r0
 *   @0x28a8c4 ldr r1, [r1, #0x10]
 *   @0x28a8c8 mov r9, r2
 *   @0x28a8cc cmp r3, r1
 *   @0x28a8d0 blt 0x28aa38 <spSkeletonBounds_update+0x184>
 *   @0x28a8d4 cmp r1, #0
 *   @0x28a8d8 mov r2, #1325400064
 *   @0x28a8dc mov r3, #-822083584
 *   @0x28a8e0 mov r5, #0
 *   @0x28a8e4 str r2, [r4, #0xc]
 *   @0x28a8e8 str r2, [r4, #0x10]
 *   @0x28a8ec str r3, [r4, #0x14]
 *   @0x28a8f0 str r3, [r4, #0x18]
 *   @0x28a8f4 str r5, [r4]
 *   @0x28a8f8 bgt 0x28a90c <spSkeletonBounds_update+0x58>
 *   @0x28a8fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x28a900 add r5, r5, #1
 *   @0x28a904 cmp r1, r5
 *   @0x28a908 ble 0x28aa34 <spSkeletonBounds_update+0x180>
 *   @0x28a90c ldr r3, [r10, #0x14]
 *   @0x28a910 ldr r7, [r3, r5, lsl #2]
 *   @0x28a914 ldr r6, [r7, #0x18]
 *   @0x28a918 cmp r6, #0
 *   @0x28a91c beq 0x28a900 <spSkeletonBounds_update+0x4c>
 *   @0x28a920 ldr r3, [r6, #0x4]
 *   @0x28a924 cmp r3, #1
 *   @0x28a928 bne 0x28a900 <spSkeletonBounds_update+0x4c>
 *   @0x28a92c ldr r3, [r4]
 *   @0x28a930 ldr r2, [r4, #0x4]
 *   @0x28a934 str r6, [r2, r3, lsl #2]
 *   @0x28a938 ldr r2, [r4, #0x8]
 *   @0x28a93c add r11, r2, r3, lsl #2
 *   @0x28a940 ldr r8, [r2, r3, lsl #2]
 *   @0x28a944 cmp r8, #0
 *   @0x28a948 beq 0x28a970 <spSkeletonBounds_update+0xbc>
 *   @0x28a94c ldr r3, [r6, #0x20]
 *   @0x28a950 ldr r2, [r8, #0x8]
 *   @0x28a954 cmp r2, r3
 *   @0x28a958 bge 0x28a984 <spSkeletonBounds_update+0xd0>
 *   @0x28a95c mov r0, r8
 *   @0x28a960 bl 0x28a5b8 <spPolygon_dispose>
 *   @0x28a964 ldr r11, [r4]
 *   @0x28a968 ldr r3, [r4, #0x8]
 *   @0x28a96c add r11, r3, r11, lsl #2
 *   @0x28a970 ldr r0, [r6, #0x20]
 *   @0x28a974 bl 0x28a56c <spPolygon_create>
 *   @0x28a978 ldr r3, [r6, #0x20]
 *   @0x28a97c mov r8, r0
 *   @0x28a980 str r0, [r11]
 *   @0x28a984 str r3, [r8, #0x4]
 *   @0x28a988 mov r0, r6
 *   @0x28a98c mov r1, r7
 *   @0x28a990 ldr r2, [r8]
 *   @0x28a994 bl 0x285b40 <spBoundingBoxAttachment_computeWorldVertices>
 *   @0x28a998 cmp r9, #0
 *   @0x28a99c beq 0x28aa18 <spSkeletonBounds_update+0x164>
 *   @0x28a9a0 ldr r2, [r8, #0x4]
 *   @0x28a9a4 cmp r2, #0
 *   @0x28a9a8 ble 0x28aa18 <spSkeletonBounds_update+0x164>
 *   @0x28a9ac sub r2, r2, #1
 *   @0x28a9b0 ldr r3, [r8]
 *   @0x28a9b4 lsr r2, r2, #1
 *   @0x28a9b8 add r1, r3, #12
 *   @0x28a9bc add r3, r3, #4
 *   @0x28a9c0 add r2, r1, r2, lsl #3
 *   @0x28a9c4 vldr s14, [r3, #-4]
 *   @0x28a9c8 vldr s15, [r4, #12]
 *   @0x28a9cc vcmpe.f32 s14, s15
 *   @0x28a9d0 vldr s13, [r4, #16]
 *   @0x28a9d4 vldr s15, [r3]
 *   @0x28a9d8 add r3, r3, #8
 *   @0x28a9dc vmrs APSR_nzcv, fpscr
 *   @0x28a9e0 vcmpe.f32 s15, s13
 *   @0x28a9e4 vstrmi s14, [r4, #12]
 *   @0x28a9e8 vldr s13, [r4, #20]
 *   @0x28a9ec vmrs APSR_nzcv, fpscr
 *   @0x28a9f0 vcmpe.f32 s14, s13
 *   @0x28a9f4 vstrmi s15, [r4, #16]
 *   @0x28a9f8 vmrs APSR_nzcv, fpscr
 *   @0x28a9fc vstrgt s14, [r4, #20]
 *   @0x28aa00 vldr s14, [r4, #24]
 *   @0x28aa04 vcmpe.f32 s15, s14
 *   @0x28aa08 vmrs APSR_nzcv, fpscr
 *   @0x28aa0c vstrgt s15, [r4, #24]
 *   @0x28aa10 cmp r3, r2
 *   @0x28aa14 bne 0x28a9c4 <spSkeletonBounds_update+0x110>
 *   @0x28aa18 ldr r1, [r10, #0x10]
 *   @0x28aa1c add r5, r5, #1
 *   @0x28aa20 ldr r3, [r4]
 *   @0x28aa24 cmp r1, r5
 *   @0x28aa28 add r3, r3, #1
 *   @0x28aa2c str r3, [r4]
 *   @0x28aa30 bgt 0x28a90c <spSkeletonBounds_update+0x58>
 *   @0x28aa34 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x28aa38 ldr r0, [r0, #0x4]
 *   @0x28aa3c ldr r5, [pc, #0x58]
 *   @0x28aa40 bl 0x285c80 <_free>
 *   @0x28aa44 ldr r0, [r10, #0x10]
 *   @0x28aa48 mov r2, #113
 *   @0x28aa4c add r5, pc, r5
 *   @0x28aa50 lsl r0, r0, #2
 *   @0x28aa54 mov r1, r5
 *   @0x28aa58 bl 0x285c10 <_malloc>
 *   @0x28aa5c mov r2, r5
 *   @0x28aa60 mov r3, #115
 *   @0x28aa64 mov r1, #4
 *   @0x28aa68 str r0, [r4, #0x4]
 *   @0x28aa6c ldr r0, [r10, #0x10]
 *   @0x28aa70 bl 0x285c4c <_calloc>
 *   @0x28aa74 ldr r1, [r4, #0x8]
 *   @0x28aa78 ldr r2, [r4, #0x1c]
 *   @0x28aa7c mov r5, r0
 *   @0x28aa80 bl 0xb65bc <memcpy@plt>
 *   @0x28aa84 ldr r0, [r4, #0x8]
 *   @0x28aa88 bl 0x285c80 <_free>
 *   @0x28aa8c ldr r1, [r10, #0x10]
 *   @0x28aa90 str r5, [r4, #0x8]
 *   @0x28aa94 str r1, [r4, #0x1c]
 *   @0x28aa98 b 0x28a8d4 <spSkeletonBounds_update+0x20>
 *   @0x28aa9c andeq sp, r12, r0, lsr #32
 *
 * ══ §52/60 png_combine_row  0x2adc30  size 490  123 条（0x2adc30..0x2ade1a）
 * @func 0x2adc30 0x2ade1c  size 492  123 条
 * 部分覆盖: 本节 123/227 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x14d5cc4 / 0x152c8f4 / 0x4f00d8 / 0x14d5d48 / 0x152c978 / 0x4f0164 / 0x15309c0 / 0x1515db8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2adc30 cmp r2, #0xff
 *   @0x2adc34 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2adc38 mov r5, r2
 *   @0x2adc3c .word 0xf89011b0
 *   @0x2adc40 .word 0xf8d021cf
 *   @0x2adc44 smlabble pc, r12, r1, r4
 *   @0x2adc48 cmp r2, #0x7
 *   @0x2adc4c stmdble r2, {r0, r8}
 *   @0x2adc50 lsrs r2, r2, #0x3
 *   @0x2adc54 b 0x2adc5c <png_combine_row+0x2c>
 *   @0x2adc58 adds r2, #0x7
 *   @0x2adc5c mov r0, r3
 *   @0x2adc60 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2adc64 b.w 0x31bb0c <__udivdi3+0x474>
 *   @0x2adc68 cmp r2, #0x2
 *   @0x2adc6c cmp r2, #0x4
 *   @0x2adc70 bhs 0x30de88 <af_shaper_get_elem+0x36f6>
 *   @0x2adc74 bne.w 0x2adde4 <png_combine_row+0x1b4>
 *   @0x2adc78 ldr.w r2, [r0, #0x134]
 *   @0x2adc7c adds r1, #0x1
 *   @0x2adc80 movw r8, #0x7f7f
 *   @0x2adc84 and r2, r2, #0x10000
 *   @0x2adc88 cmp r2, #0x0
 *   @0x2adc8c moveq r7, #0x7
 *   @0x2adc90 ite eq
 *   @0x2adc94 .word 0xf04f0c00
 *   @0x2adc98 svclt #0xc0c07
 *   @0x2adc9c moveq.w r2, #0xffffffff
 *   @0x2adca0 movne r2, #0x1
 *   @0x2adca4 mov r0, r7
 *   @0x2adca8 cmp r6, r4
 *   @0x2adcac eormi r8, r10, #179
 *   @0x2adcb0 beq 0x2adcda <png_combine_row+0xaa>
 *   @0x2adcb4 .word 0xf1c09000
 *   @0x2adcb8 .word 0xf8930b07
 *   @0x2adcbc blx 0x14d5cc4 <b2_toiTime+0xd7c820>
 *   @0x2adcc0 blx 0x152c8f4 <b2_toiTime+0xdd3450>
 *   @0x2adcc4 b 0x5ac0cc <g_SWFlineaavertbuff+0x59004>
 *   @0x2adcc8 .word 0xf0090a0a
 *   @0x2adccc blx 0x4f00d8 <SrcVerts+0x4d11c>
 *   @0x2adcd0 b 0x152c0d8 <b2_toiTime+0xdd2c34>
 *   @0x2adcd4 .word 0xf883090a
 *   @0x2adcd8 strbmi r9, [r0, #-0x0]!
 *   @0x2adcdc bne 0x2adce6 <png_combine_row+0xb6>
 *   @0x2adce0 adds r3, #0x1
 *   @0x2adce4 b 0x2adcec <png_combine_row+0xbc>
 *   @0x2adce8 strbmi r9, [r8], #-4
 *   @0x2adcec cmp r2, #0x1
 *   @0x2adcf0 svclt #0x140601
 *   @0x2adcf4 asrne r2, r2, #0x1
 *   @0x2adcf8 b 0x2adca8 <png_combine_row+0x78>
 *   @0x2adcfc .word 0x31012134
 *   @0x2add00 movs r6, #0x0
 *   @0x2add04 and r2, r2, #0x10000
 *   @0x2add08 movw r8, #0x3f3f
 *   @0x2add0c cmp r2, #0x0
 *   @0x2add10 moveq r7, #0x6
 *   @0x2add14 ite eq
 *   @0x2add18 .word 0xf04f0c01
 *   @0x2add1c svclt #0xc0c02
 *   @0x2add20 moveq.w r10, #0x0
 *   @0x2add24 movne.w r10, #0x6
 *   @0x2add28 str.w r10, [sp, #0x4]
 *   @0x2add2c mov r2, r7
 *   @0x2add30 beq 0x2ade14 <png_combine_row+0x1e4>
 *   @0x2add34 beq 0x2add5e <png_combine_row+0x12e>
 *   @0x2add38 .word 0xf1c29000
 *   @0x2add3c .word 0xf8930b06
 *   @0x2add40 blx 0x14d5d48 <b2_toiTime+0xd7c8a4>
 *   @0x2add44 blx 0x152c978 <b2_toiTime+0xdd34d4>
 *   @0x2add48 b 0x5ac158 <g_SWFlineaavertbuff+0x59090>
 *   @0x2add4c .word 0xf0090a0a
 *   @0x2add50 blx 0x4f0164 <SrcVerts+0x4d1a8>
 *   @0x2add54 b 0x152c164 <b2_toiTime+0xdd2cc0>
 *   @0x2add58 .word 0xf883090a
 *   @0x2add5c .word 0xf8dd9000
 *   @0x2add60 strlo r9, [r1], -r4
 *   @0x2add64 cmp r2, r9
 *   @0x2add68 addeq r1, #0x1
 *   @0x2add6c moveq r2, r7
 *   @0x2add70 cmp r0, #0x1
 *   @0x2add74 asrne r0, r0, #0x1
 *   @0x2add78 b 0x2add2e <png_combine_row+0xfe>
 *   @0x2add7c .word 0x31010134
 *   @0x2add80 movs r7, #0x0
 *   @0x2add84 ands r8, r0, #0x10000
 *   @0x2add88 ittte ne
 *   @0x2add8c movne r2, #0x0
 *   @0x2add90 mvneq r12, #0x3
 *   @0x2add94 mov r0, r2
 *   @0x2add98 beq 0x2ade14 <png_combine_row+0x1e4>
 *   @0x2add9c beq 0x2addca <png_combine_row+0x19a>
 *   @0x2adda0 .word 0xf6409000
 *   @0x2adda4 .word 0xf1c07a0f
 *   @0x2adda8 blx 0x15309c0 <b2_toiTime+0xdd751c>
 *   @0x2addac .word 0xf893fb0b
 *   @0x2addb0 blx 0x1515db8 <b2_toiTime+0xdbc914>
 *   @0x2addb4 .word 0xf009f900
 *   @0x2addb8 b 0x5701fc <g_SWFlineaavertbuff+0x1d134>
 *   @0x2addbc blx 0x4f05ec <SrcVerts+0x4d630>
 *   @0x2addc0 b 0x152c1c8 <b2_toiTime+0xdd2d24>
 *   @0x2addc4 .word 0xf883090a
 *   @0x2addc8 strbmi r9, [r0, #-0x0]
 *   @0x2addcc add.w r7, r7, #0x1
 *   @0x2addd0 ittte eq
 *   @0x2addd4 addeq r3, #0x1
 *   @0x2addd8 addne r0, r12
 *   @0x2adddc ite ne
 *   @0x2adde0 moveq r6, #0x80
 *   @0x2adde4 add.w r8, r1, #0x1
 *   @0x2adde8 lsr.w r9, r2, #0x3
 *   @0x2addec movs r6, #0x80
 *   @0x2addf0 cmp r7, r4
 *   @0x2addf4 tst r6, r5
 *   @0x2addf8 mov r0, r3
 *   @0x2addfc mov r2, r9
 *   @0x2ade00 .word 0x4603ebde
 *   @0x2ade04 cmp r6, #0x1
 *   @0x2ade08 add r3, r9
 *   @0x2ade0c lsrne r6, r6, #0x1
 *   @0x2ade10 adds r7, #0x1
 *   @0x2ade14 add sp, #0xc
 *   @0x2ade18 strdeq r8, r9, [r0], -r0
 *
 * ══ §53/60 anon_fae18  0xfae18  size 488  122 条（0xfae18..0xfb000）
 * @func 0xfae18 0xfb000  size 488  122 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×4 / 0xb6550×4 / 0xb65bc×3 / __aeabi_idivmod×2 / SHA1Reset(SHA1Context*)×2 / SHA1Input(SHA1Context*, unsigned char const*, unsigned int)×2 / SHA1Result(SHA1Context*)×2 / YYUDID(char**)
 * 字段偏移 top8: 0x-110×4 / 0x-114×2 / 0x-28×2 / 0x-108×2 / 0x-11c×2 / 0x-118×2 / 0x1c8×1 / 0x-e4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfae18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfae1c add r11, sp, #32
 *   @0xfae20 ldr r1, [pc, #0x1c8]
 *   @0xfae24 sub sp, sp, #252
 *   @0xfae28 sub r0, r11, #36
 *   @0xfae2c ldr r1, [pc, r1]
 *   @0xfae30 mov r3, #0
 *   @0xfae34 str r3, [r0, #-0xe4]!
 *   @0xfae38 sub r8, r11, #260
 *   @0xfae3c ldr r3, [r1]
 *   @0xfae40 sub r7, r11, #248
 *   @0xfae44 str r1, [r11, #-0x114]
 *   @0xfae48 sub r6, r11, #144
 *   @0xfae4c ldr r5, [pc, #0x1a0]
 *   @0xfae50 str r3, [r11, #-0x28]
 *   @0xfae54 bl 0x15f574 <_Z6YYUDIDPPc>
 *   @0xfae58 ldr r4, [r11, #-0x108]
 *   @0xfae5c add r5, pc, r5
 *   @0xfae60 mov r0, r4
 *   @0xfae64 bl 0xb6538 <strlen@plt>
 *   @0xfae68 str r0, [r11, #-0x110]
 *   @0xfae6c mov r1, r0
 *   @0xfae70 mov r0, #2
 *   @0xfae74 bl 0x318dec <__aeabi_idivmod>
 *   @0xfae78 ldrb r0, [r4, r1]
 *   @0xfae7c ldr r1, [r11, #-0x110]
 *   @0xfae80 bl 0x318dec <__aeabi_idivmod>
 *   @0xfae84 mov r0, r8
 *   @0xfae88 tst r1, #1
 *   @0xfae8c mov r10, r1
 *   @0xfae90 ldrb r2, [r4, r1]
 *   @0xfae94 mov r4, #0
 *   @0xfae98 ldr r1, [pc, #0x158]
 *   @0xfae9c eoreq r2, r2, #41
 *   @0xfaea0 eorne r2, r2, #154
 *   @0xfaea4 add r1, pc, r1
 *   @0xfaea8 bl 0xb6550 <sprintf@plt>
 *   @0xfaeac ldr r3, [r11, #-0x110]
 *   @0xfaeb0 add r2, r3, #18
 *   @0xfaeb4 ldr r3, [r11, #-0x108]
 *   @0xfaeb8 bic r2, r2, #7
 *   @0xfaebc sub sp, sp, r2
 *   @0xfaec0 mov r2, r10
 *   @0xfaec4 mov r1, r3
 *   @0xfaec8 str r3, [r11, #-0x11c]
 *   @0xfaecc mov r0, sp
 *   @0xfaed0 bl 0xb65bc <memcpy@plt>
 *   @0xfaed4 mov r0, r8
 *   @0xfaed8 bl 0xb6538 <strlen@plt>
 *   @0xfaedc mov r1, r8
 *   @0xfaee0 mov r12, r0
 *   @0xfaee4 add r0, sp, r10
 *   @0xfaee8 mov r2, r12
 *   @0xfaeec str r12, [r11, #-0x118]
 *   @0xfaef0 bl 0xb65bc <memcpy@plt>
 *   @0xfaef4 ldr r12, [r11, #-0x118]
 *   @0xfaef8 ldr r1, [r11, #-0x110]
 *   @0xfaefc ldr r3, [r11, #-0x11c]
 *   @0xfaf00 add r0, r10, r12
 *   @0xfaf04 add r2, r1, #1
 *   @0xfaf08 add r0, sp, r0
 *   @0xfaf0c add r1, r3, r10
 *   @0xfaf10 rsb r2, r10, r2
 *   @0xfaf14 bl 0xb65bc <memcpy@plt>
 *   @0xfaf18 mov r0, r7
 *   @0xfaf1c bl 0x214294 <_Z9SHA1ResetP11SHA1Context>
 *   @0xfaf20 mov r0, sp
 *   @0xfaf24 bl 0xb6538 <strlen@plt>
 *   @0xfaf28 mov r1, sp
 *   @0xfaf2c add r2, r0, #1
 *   @0xfaf30 mov r0, r7
 *   @0xfaf34 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj>
 *   @0xfaf38 mov r0, r7
 *   @0xfaf3c bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context>
 *   @0xfaf40 ldr r1, [pc, #0xb4]
 *   @0xfaf44 mov r2, r10
 *   @0xfaf48 sub r0, r11, #256
 *   @0xfaf4c add r1, pc, r1
 *   @0xfaf50 bl 0xb6550 <sprintf@plt>
 *   @0xfaf54 mov r0, r6
 *   @0xfaf58 bl 0x214294 <_Z9SHA1ResetP11SHA1Context>
 *   @0xfaf5c mov r0, r8
 *   @0xfaf60 bl 0xb6538 <strlen@plt>
 *   @0xfaf64 mov r1, r8
 *   @0xfaf68 add r2, r0, #1
 *   @0xfaf6c mov r0, r6
 *   @0xfaf70 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj>
 *   @0xfaf74 mov r0, r6
 *   @0xfaf78 bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context>
 *   @0xfaf7c ldr r1, [pc, #0x7c]
 *   @0xfaf80 mov r0, #81
 *   @0xfaf84 movw r2, #0x696
 *   @0xfaf88 add r1, pc, r1
 *   @0xfaf8c mov r3, #1
 *   @0xfaf90 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfaf94 mov r9, r0
 *   @0xfaf98 mov r8, r0
 *   @0xfaf9c ldr r2, [r7, r4]
 *   @0xfafa0 mov r0, r8
 *   @0xfafa4 mov r1, r5
 *   @0xfafa8 bl 0xb6550 <sprintf@plt>
 *   @0xfafac add r0, r8, #8
 *   @0xfafb0 ldr r2, [r6, r4]
 *   @0xfafb4 mov r1, r5
 *   @0xfafb8 add r4, r4, #4
 *   @0xfafbc bl 0xb6550 <sprintf@plt>
 *   @0xfafc0 cmp r4, #20
 *   @0xfafc4 add r8, r8, #16
 *   @0xfafc8 bne 0xfaf9c <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x28c>
 *   @0xfafcc ldr r1, [r11, #-0x114]
 *   @0xfafd0 mov r0, r9
 *   @0xfafd4 ldr r2, [r11, #-0x28]
 *   @0xfafd8 ldr r3, [r1]
 *   @0xfafdc cmp r2, r3
 *   @0xfafe0 bne 0xfafec <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x2dc>
 *   @0xfafe4 sub sp, r11, #32
 *   @0xfafe8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfafec bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xfaff0 eoreq r2, pc, r4, lsr #22
 *   @0xfaff4 eoreq r7, r3, r0, asr r3
 *   @0xfaff8 eoreq r12, r3, r0, asr #26
 *   @0xfaffc eoreq r12, r3, r0, lsr #25
 *
 * ══ §54/60 GR_Draw_Healthbar(float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, int, bool, bool)  0x16c0d8  size 488  122 条（0x16c0d8..0x16c2c0）
 * @func 0x16c0d8 0x16c2c0  size 488  122 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Draw_Rectangle_Ext(float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, bool)×3 / GR_Draw_Healthbar(float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, int, bool, bool)+0x84 / GR_Color_Merge(unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x10×3 / 0x4×3 / 0x8×3 / 0xc×3 / 0x58×2 / 0x54×2 / 0x5c×2 / 0x60×2
 * VFP 指令 54 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c0d8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x16c0dc vpush {d8, d9, d10}
 *   @0x16c0e0 sub sp, sp, #28
 *   @0x16c0e4 vldr s16, [sp, #80]
 *   @0x16c0e8 vmov s18, r0
 *   @0x16c0ec ldrb r12, [sp, #0x68]
 *   @0x16c0f0 vmov s20, r1
 *   @0x16c0f4 vmov s17, r2
 *   @0x16c0f8 ldr r7, [sp, #0x58]
 *   @0x16c0fc cmp r12, #0
 *   @0x16c100 vmov s19, r3
 *   @0x16c104 ldr r12, [sp, #0x54]
 *   @0x16c108 ldr r6, [sp, #0x5c]
 *   @0x16c10c ldr r8, [sp, #0x60]
 *   @0x16c110 ldr r4, [sp, #0x64]
 *   @0x16c114 ldrb r5, [sp, #0x6c]
 *   @0x16c118 bne 0x16c228 <_Z17GR_Draw_Healthbarfffffjjjjibb+0x150>
 *   @0x16c11c vcmpe.f32 s16, #0
 *   @0x16c120 vmrs APSR_nzcv, fpscr
 *   @0x16c124 bmi 0x16c16c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x94>
 *   @0x16c128 vldr s15, [pc, #392]
 *   @0x16c12c vcmpe.f32 s16, s15
 *   @0x16c130 vmrs APSR_nzcv, fpscr
 *   @0x16c134 vmovgt.f32 s14, #1.000000e+00
 *   @0x16c138 vmovgt.f32 s16, s15
 *   @0x16c13c ble 0x16c15c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x84>
 *   @0x16c140 cmp r4, #3
 *   @0x16c144 addls pc, pc, r4, lsl #2
 *   @0x16c148 b 0x16c178 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xa0>
 *   @0x16c14c b 0x16c178 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xa0>
 *   @0x16c150 b 0x16c2a4 <_Z17GR_Draw_Healthbarfffffjjjjibb+0x1cc>
 *   @0x16c154 b 0x16c27c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x1a4>
 *   @0x16c158 b 0x16c290 <_Z17GR_Draw_Healthbarfffffjjjjibb+0x1b8>
 *   @0x16c15c vcmp.f32 s16, #0
 *   @0x16c160 vmrs APSR_nzcv, fpscr
 *   @0x16c164 vdivne.f32 s14, s16, s15
 *   @0x16c168 bne 0x16c140 <_Z17GR_Draw_Healthbarfffffjjjjibb+0x68>
 *   @0x16c16c add sp, sp, #28
 *   @0x16c170 vpop {d8, d9, d10}
 *   @0x16c174 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x16c178 vsub.f32 s17, s17, s18
 *   @0x16c17c vmov.f32 s15, s18
 *   @0x16c180 vmla.f32 s15, s14, s17
 *   @0x16c184 vmov.f32 s17, s15
 *   @0x16c188 vldr s15, [pc, #300]
 *   @0x16c18c mov r4, #0
 *   @0x16c190 vcmpe.f32 s16, s15
 *   @0x16c194 vmrs APSR_nzcv, fpscr
 *   @0x16c198 vsubgt.f32 s16, s16, s15
 *   @0x16c19c movgt r1, r8
 *   @0x16c1a0 movle r1, r6
 *   @0x16c1a4 movgt r0, r6
 *   @0x16c1a8 movle r0, r7
 *   @0x16c1ac vdivgt.f32 s16, s16, s15
 *   @0x16c1b0 vdivle.f32 s15, s16, s15
 *   @0x16c1b4 vmovgt r2, s16
 *   @0x16c1b8 vmovle r2, s15
 *   @0x16c1bc bl 0x16caa8 <_Z14GR_Color_Mergejjf>
 *   @0x16c1c0 str r4, [sp, #0x10]
 *   @0x16c1c4 vmov r1, s20
 *   @0x16c1c8 vmov r2, s17
 *   @0x16c1cc vmov r3, s19
 *   @0x16c1d0 str r0, [sp]
 *   @0x16c1d4 str r0, [sp, #0x4]
 *   @0x16c1d8 str r0, [sp, #0x8]
 *   @0x16c1dc str r0, [sp, #0xc]
 *   @0x16c1e0 vmov r0, s18
 *   @0x16c1e4 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x16c1e8 cmp r5, r4
 *   @0x16c1ec beq 0x16c16c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x94>
 *   @0x16c1f0 mov r3, #1
 *   @0x16c1f4 vmov r0, s18
 *   @0x16c1f8 str r3, [sp, #0x60]
 *   @0x16c1fc vmov r1, s20
 *   @0x16c200 vmov r2, s17
 *   @0x16c204 vmov r3, s19
 *   @0x16c208 str r4, [sp, #0x50]
 *   @0x16c20c str r4, [sp, #0x54]
 *   @0x16c210 str r4, [sp, #0x58]
 *   @0x16c214 str r4, [sp, #0x5c]
 *   @0x16c218 add sp, sp, #28
 *   @0x16c21c vpop {d8, d9, d10}
 *   @0x16c220 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x16c224 b 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x16c228 mov r9, #0
 *   @0x16c22c str r12, [sp]
 *   @0x16c230 str r12, [sp, #0x4]
 *   @0x16c234 str r12, [sp, #0x8]
 *   @0x16c238 str r12, [sp, #0xc]
 *   @0x16c23c str r9, [sp, #0x10]
 *   @0x16c240 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x16c244 cmp r5, r9
 *   @0x16c248 beq 0x16c11c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x44>
 *   @0x16c24c mov r3, #1
 *   @0x16c250 str r9, [sp]
 *   @0x16c254 str r3, [sp, #0x10]
 *   @0x16c258 str r9, [sp, #0x4]
 *   @0x16c25c str r9, [sp, #0x8]
 *   @0x16c260 str r9, [sp, #0xc]
 *   @0x16c264 vmov r0, s18
 *   @0x16c268 vmov r1, s20
 *   @0x16c26c vmov r2, s17
 *   @0x16c270 vmov r3, s19
 *   @0x16c274 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x16c278 b 0x16c11c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x44>
 *   @0x16c27c vsub.f32 s19, s19, s20
 *   @0x16c280 vmov.f32 s15, s20
 *   @0x16c284 vmla.f32 s15, s14, s19
 *   @0x16c288 vmov.f32 s19, s15
 *   @0x16c28c b 0x16c188 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xb0>
 *   @0x16c290 vsub.f32 s20, s19, s20
 *   @0x16c294 vmov.f32 s15, s19
 *   @0x16c298 vmls.f32 s15, s14, s20
 *   @0x16c29c vmov.f32 s20, s15
 *   @0x16c2a0 b 0x16c188 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xb0>
 *   @0x16c2a4 vsub.f32 s18, s17, s18
 *   @0x16c2a8 vmov.f32 s15, s17
 *   @0x16c2ac vmls.f32 s15, s14, s18
 *   @0x16c2b0 vmov.f32 s18, s15
 *   @0x16c2b4 b 0x16c188 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xb0>
 *   @0x16c2b8 sbcmi r0, r8, #0
 *   @0x16c2bc submi r0, r8, #0
 *
 * ══ §55/60 F_TilemapGetCellXAtPixel(RValue&, CInstance*, CInstance*, int, RValue*)  0x1beaa0  size 488  122 条（0x1beaa0..0x1bec88）
 * @func 0x1beaa0 0x1bec98  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show(char const*, bool)×3 / YYGetFloat(RValue const*, int)×2 / F_TilemapGetCellXAtPixel(RValue&, CInstance*, CInstance*, int, RValue*)+0x40×2 / CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / Background_Data(int) / 0xb6910
 * 字段偏移 top8: 0x4×3 / 0x30×3 / 0xc×2 / 0x144×2 / 0x1c×2 / 0x28×2 / 0x19c×1 / 0x-4×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1beaa0 cmp r3, #3
 *   @0x1beaa4 mov r3, #0
 *   @0x1beaa8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1beaac vpush {d8, d9}
 *   @0x1beab0 mov r4, r3
 *   @0x1beab4 sub sp, sp, #8
 *   @0x1beab8 movt r3, #0xbff0
 *   @0x1beabc mov r5, r0
 *   @0x1beac0 str r4, [r0, #0xc]
 *   @0x1beac4 str r3, [r0, #0x4]
 *   @0x1beac8 str r4, [r0]
 *   @0x1beacc beq 0x1beaec <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x1bead0 ldr r0, [pc, #0x19c]
 *   @0x1bead4 mov r1, r4
 *   @0x1bead8 add r0, pc, r0
 *   @0x1beadc bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1beae0 add sp, sp, #8
 *   @0x1beae4 vpop {d8, d9}
 *   @0x1beae8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1beaec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1beaf0 add r6, sp, #8
 *   @0x1beaf4 mov r1, r4
 *   @0x1beaf8 str r4, [r6, #-0x4]!
 *   @0x1beafc mov r7, r0
 *   @0x1beb00 ldr r0, [sp, #0x30]
 *   @0x1beb04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1beb08 mov r2, r6
 *   @0x1beb0c mov r1, r0
 *   @0x1beb10 mov r0, r7
 *   @0x1beb14 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1beb18 subs r4, r0, #0
 *   @0x1beb1c beq 0x1beb2c <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1beb20 ldr r3, [r4]
 *   @0x1beb24 cmp r3, #5
 *   @0x1beb28 beq 0x1beb58 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1beb2c ldr r3, [pc, #0x144]
 *   @0x1beb30 ldr r1, [pc, #0x144]
 *   @0x1beb34 ldr r3, [pc, r3]
 *   @0x1beb38 add r1, pc, r1
 *   @0x1beb3c ldr r0, [r3]
 *   @0x1beb40 ldr r3, [r0]
 *   @0x1beb44 ldr r3, [r3, #0xc]
 *   @0x1beb48 blx r3
 *   @0x1beb4c add sp, sp, #8
 *   @0x1beb50 vpop {d8, d9}
 *   @0x1beb54 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1beb58 ldr r3, [sp, #0x4]
 *   @0x1beb5c cmp r3, #0
 *   @0x1beb60 beq 0x1beb2c <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1beb64 ldr r1, [r4, #0x34]
 *   @0x1beb68 cmp r1, #0
 *   @0x1beb6c beq 0x1bec64 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x1beb70 ldr r0, [r4, #0x1c]
 *   @0x1beb74 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1beb78 subs r3, r0, #0
 *   @0x1beb7c beq 0x1bec50 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x1beb80 mov r1, #1
 *   @0x1beb84 ldr r0, [sp, #0x30]
 *   @0x1beb88 ldr r2, [sp, #0x4]
 *   @0x1beb8c vldr s16, [r4, #32]
 *   @0x1beb90 vldr s15, [r2, #8]
 *   @0x1beb94 vldr s18, [r2, #12]
 *   @0x1beb98 vadd.f32 s16, s16, s15
 *   @0x1beb9c ldr r6, [r3, #0x1c]
 *   @0x1beba0 ldr r8, [r3, #0x20]
 *   @0x1beba4 vldr s19, [r4, #36]
 *   @0x1beba8 ldr r7, [r4, #0x28]
 *   @0x1bebac ldr r4, [r4, #0x2c]
 *   @0x1bebb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bebb4 mov r1, #2
 *   @0x1bebb8 vmov s17, r0
 *   @0x1bebbc ldr r0, [sp, #0x30]
 *   @0x1bebc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bebc4 vsub.f32 s15, s17, s16
 *   @0x1bebc8 vcmpe.f32 s15, #0
 *   @0x1bebcc vmrs APSR_nzcv, fpscr
 *   @0x1bebd0 vmov s13, r0
 *   @0x1bebd4 bmi 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bebd8 mul r7, r7, r6
 *   @0x1bebdc vmov s12, r7
 *   @0x1bebe0 vcvt.f32.s32 s14, s12
 *   @0x1bebe4 vcmpe.f32 s14, s15
 *   @0x1bebe8 vmrs APSR_nzcv, fpscr
 *   @0x1bebec bls 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bebf0 vadd.f32 s18, s19, s18
 *   @0x1bebf4 vsub.f32 s13, s13, s18
 *   @0x1bebf8 vcmpe.f32 s13, #0
 *   @0x1bebfc vmrs APSR_nzcv, fpscr
 *   @0x1bec00 bmi 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bec04 mul r4, r4, r8
 *   @0x1bec08 vmov s12, r4
 *   @0x1bec0c vcvt.f32.s32 s14, s12
 *   @0x1bec10 vcmpe.f32 s14, s13
 *   @0x1bec14 vmrs APSR_nzcv, fpscr
 *   @0x1bec18 bls 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bec1c vmov.f32 s13, #1.000000e+00
 *   @0x1bec20 vmov s12, r6
 *   @0x1bec24 vcvt.f32.s32 s14, s12
 *   @0x1bec28 vdiv.f32 s14, s13, s14
 *   @0x1bec2c vmul.f32 s14, s15, s14
 *   @0x1bec30 vmov r0, s14
 *   @0x1bec34 bl 0xb6910 <floorf@plt>
 *   @0x1bec38 vmov s13, r0
 *   @0x1bec3c vcvt.s32.f32 s15, s13
 *   @0x1bec40 vcvt.f64.s32 d6, s15
 *   @0x1bec44 vmov r2, r3, d6
 *   @0x1bec48 stm r5, {r2, r3}
 *   @0x1bec4c b 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bec50 ldr r0, [pc, #0x28]
 *   @0x1bec54 mov r1, r3
 *   @0x1bec58 add r0, pc, r0
 *   @0x1bec5c bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bec60 b 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bec64 ldr r0, [pc, #0x18]
 *   @0x1bec68 add r0, pc, r0
 *   @0x1bec6c bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bec70 b 0x1beae0 <_Z24F_TilemapGetCellXAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bec74 andseq r0, r9, r0, ror #4
 *   @0x1bec78 eoreq lr, r2, r0, ror #23
 *   @0x1bec7c ldrheq r0, [r9], -r12
 *   @0x1bec80 andseq r0, r9, r8, asr r1
 *   @0x1bec84 andseq r0, r9, r12, lsl #2
 *
 * ══ §56/60 F_TilemapGetCellYAtPixel(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bec88  size 488  122 条（0x1bec88..0x1bee70）
 * @func 0x1bec88 0x1bee70  size 488  122 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show(char const*, bool)×3 / YYGetFloat(RValue const*, int)×2 / F_TilemapGetCellYAtPixel(RValue&, CInstance*, CInstance*, int, RValue*)+0x40×2 / CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / Background_Data(int) / 0xb6910
 * 字段偏移 top8: 0x4×3 / 0x30×3 / 0xc×2 / 0x144×2 / 0x1c×2 / 0x28×2 / 0x19c×1 / 0x-4×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bec88 cmp r3, #3
 *   @0x1bec8c mov r3, #0
 *   @0x1bec90 push {r4, r5, r6, r7, r8, lr}
 *   @0x1bec94 vpush {d8, d9}
 *   @0x1bec98 mov r4, r3
 *   @0x1bec9c sub sp, sp, #8
 *   @0x1beca0 movt r3, #0xbff0
 *   @0x1beca4 mov r5, r0
 *   @0x1beca8 str r4, [r0, #0xc]
 *   @0x1becac str r3, [r0, #0x4]
 *   @0x1becb0 str r4, [r0]
 *   @0x1becb4 beq 0x1becd4 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x1becb8 ldr r0, [pc, #0x19c]
 *   @0x1becbc mov r1, r4
 *   @0x1becc0 add r0, pc, r0
 *   @0x1becc4 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1becc8 add sp, sp, #8
 *   @0x1beccc vpop {d8, d9}
 *   @0x1becd0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1becd4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1becd8 add r6, sp, #8
 *   @0x1becdc mov r1, r4
 *   @0x1bece0 str r4, [r6, #-0x4]!
 *   @0x1bece4 mov r7, r0
 *   @0x1bece8 ldr r0, [sp, #0x30]
 *   @0x1becec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1becf0 mov r2, r6
 *   @0x1becf4 mov r1, r0
 *   @0x1becf8 mov r0, r7
 *   @0x1becfc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bed00 subs r4, r0, #0
 *   @0x1bed04 beq 0x1bed14 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bed08 ldr r3, [r4]
 *   @0x1bed0c cmp r3, #5
 *   @0x1bed10 beq 0x1bed40 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1bed14 ldr r3, [pc, #0x144]
 *   @0x1bed18 ldr r1, [pc, #0x144]
 *   @0x1bed1c ldr r3, [pc, r3]
 *   @0x1bed20 add r1, pc, r1
 *   @0x1bed24 ldr r0, [r3]
 *   @0x1bed28 ldr r3, [r0]
 *   @0x1bed2c ldr r3, [r3, #0xc]
 *   @0x1bed30 blx r3
 *   @0x1bed34 add sp, sp, #8
 *   @0x1bed38 vpop {d8, d9}
 *   @0x1bed3c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bed40 ldr r3, [sp, #0x4]
 *   @0x1bed44 cmp r3, #0
 *   @0x1bed48 beq 0x1bed14 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bed4c ldr r1, [r4, #0x34]
 *   @0x1bed50 cmp r1, #0
 *   @0x1bed54 beq 0x1bee4c <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x1bed58 ldr r0, [r4, #0x1c]
 *   @0x1bed5c bl 0xc3794 <_Z15Background_Datai>
 *   @0x1bed60 subs r3, r0, #0
 *   @0x1bed64 beq 0x1bee38 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x1bed68 mov r1, #1
 *   @0x1bed6c ldr r0, [sp, #0x30]
 *   @0x1bed70 ldr r2, [sp, #0x4]
 *   @0x1bed74 vldr s16, [r4, #32]
 *   @0x1bed78 vldr s15, [r2, #8]
 *   @0x1bed7c vldr s18, [r2, #12]
 *   @0x1bed80 vadd.f32 s16, s16, s15
 *   @0x1bed84 ldr r6, [r3, #0x1c]
 *   @0x1bed88 ldr r8, [r3, #0x20]
 *   @0x1bed8c vldr s19, [r4, #36]
 *   @0x1bed90 ldr r7, [r4, #0x28]
 *   @0x1bed94 ldr r4, [r4, #0x2c]
 *   @0x1bed98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bed9c mov r1, #2
 *   @0x1beda0 vmov s17, r0
 *   @0x1beda4 ldr r0, [sp, #0x30]
 *   @0x1beda8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bedac vsub.f32 s15, s17, s16
 *   @0x1bedb0 vcmpe.f32 s15, #0
 *   @0x1bedb4 vmrs APSR_nzcv, fpscr
 *   @0x1bedb8 vmov s13, r0
 *   @0x1bedbc bmi 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bedc0 mul r6, r7, r6
 *   @0x1bedc4 vmov s12, r6
 *   @0x1bedc8 vcvt.f32.s32 s14, s12
 *   @0x1bedcc vcmpe.f32 s14, s15
 *   @0x1bedd0 vmrs APSR_nzcv, fpscr
 *   @0x1bedd4 bls 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bedd8 vadd.f32 s18, s19, s18
 *   @0x1beddc vsub.f32 s13, s13, s18
 *   @0x1bede0 vcmpe.f32 s13, #0
 *   @0x1bede4 vmrs APSR_nzcv, fpscr
 *   @0x1bede8 bmi 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bedec mul r4, r4, r8
 *   @0x1bedf0 vmov s14, r4
 *   @0x1bedf4 vcvt.f32.s32 s15, s14
 *   @0x1bedf8 vcmpe.f32 s15, s13
 *   @0x1bedfc vmrs APSR_nzcv, fpscr
 *   @0x1bee00 bls 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bee04 vmov.f32 s14, #1.000000e+00
 *   @0x1bee08 vmov s12, r8
 *   @0x1bee0c vcvt.f32.s32 s15, s12
 *   @0x1bee10 vdiv.f32 s15, s14, s15
 *   @0x1bee14 vmul.f32 s15, s13, s15
 *   @0x1bee18 vmov r0, s15
 *   @0x1bee1c bl 0xb6910 <floorf@plt>
 *   @0x1bee20 vmov s13, r0
 *   @0x1bee24 vcvt.s32.f32 s15, s13
 *   @0x1bee28 vcvt.f64.s32 d6, s15
 *   @0x1bee2c vmov r2, r3, d6
 *   @0x1bee30 stm r5, {r2, r3}
 *   @0x1bee34 b 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bee38 ldr r0, [pc, #0x28]
 *   @0x1bee3c mov r1, r3
 *   @0x1bee40 add r0, pc, r0
 *   @0x1bee44 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bee48 b 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bee4c ldr r0, [pc, #0x18]
 *   @0x1bee50 add r0, pc, r0
 *   @0x1bee54 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bee58 b 0x1becc8 <_Z24F_TilemapGetCellYAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bee5c andseq r0, r9, r8, ror r1
 *   @0x1bee60 .word 0x0022e9f8
 *   @0x1bee64 ldrsbeq r0, [r9], -r4
 *   @0x1bee68 andseq r0, r9, r0, ror r0
 *   @0x1bee6c andseq r0, r9, r4, lsr #32
 *
 * ══ §57/60 zip_fopen_index  0x2a4584  size 488  122 条（0x2a4584..0x2a476c）
 * @func 0x2a4584 0x2a476c  size 488  122 条
 * 部分覆盖: 本节 122/213 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_error_set(zip_error*, int, int)×3 / zip_fclose×2 / zip_fopen_index+0x10 / zip_fopen_index+0xd0 / 0xb6c28 / _zip_error_init(zip_error*) / 0xb6ea4 / _zip_file_get_offset(zip*, int)
 * 字段偏移 top8: 0x20×3 / 0x30×3 / 0x4×2 / 0x10×2 / 0x18×2 / 0x14×2 / 0x1c×2 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4584 push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2a4588 subs r7, r1, #0x0
 *   @0x2a458c blt 0x2a4594 <zip_fopen_index+0x10>
 *   @0x2a4590 cmp r7, r3
 *   @0x2a4594 add.w r0, r5, #0xc
 *   @0x2a4598 movs r1, #0x12
 *   @0x2a459c bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a45a0 movs r4, #0x0
 *   @0x2a45a4 ands r4, r2, #0x8
 *   @0x2a45a8 bne 0x2a45be <zip_fopen_index+0x3a>
 *   @0x2a45ac ldr r3, [r0, #0x34]
 *   @0x2a45b0 ldr r3, [r3, r1]
 *   @0x2a45b4 cmp r3, #0x1
 *   @0x2a45b8 adds r0, #0xc
 *   @0x2a45bc b 0x2a45f8 <zip_fopen_index+0x74>
 *   @0x2a45c0 ldr r1, [r3, #0x4]
 *   @0x2a45c4 bge 0x2a4594 <zip_fopen_index+0x10>
 *   @0x2a45c8 ldmdavs r11, {r2, r3, r4, r5, r11}
 *   @0x2a45cc mul r8, r8, r7
 *   @0x2a45d0 add r3, r8
 *   @0x2a45d4 cbz r3, 0x2a4600 <zip_fopen_index+0x7c>
 *   @0x2a45d8 and r4, r2, #0x4
 *   @0x2a45dc bne 0x2a45ec <zip_fopen_index+0x68>
 *   @0x2a45e0 ite eq
 *   @0x2a45e4 .word 0xf04f0906
 *   @0x2a45e8 and r0, r11, r0, lsl #18
 *   @0x2a45ec mov.w r9, #0x0
 *   @0x2a45f0 cbnz r4, 0x2a4604 <zip_fopen_index+0x80>
 *   @0x2a45f4 tsths r0, r12
 *   @0x2a45f8 mov r2, r4
 *   @0x2a45fc adcs pc, r0, sp, lsr #29
 *   @0x2a4600 mov.w r9, #0x4
 *   @0x2a4604 movs r0, #0x34
 *   @0x2a4608 .word 0x4604ef9e
 *   @0x2a460c cbnz r0, 0x2a461c <zip_fopen_index+0x98>
 *   @0x2a4610 .word 0x210e000c
 *   @0x2a4614 mov r2, r4
 *   @0x2a4618 mlas r7, pc, lr, pc
 *   @0x2a461c ldr r3, [r5, #0x3c]
 *   @0x2a4620 subs r1, r3, #0x1
 *   @0x2a4624 blt 0x2a4654 <zip_fopen_index+0xd0>
 *   @0x2a4628 .word 0x6c280a0a
 *   @0x2a462c lsl.w r1, r10, #0x2
 *   @0x2a4630 blx 0xb6c28 <realloc@plt>
 *   @0x2a4634 mov r6, r0
 *   @0x2a4638 add.w r0, r5, #0xc
 *   @0x2a463c movs r1, #0xe
 *   @0x2a4640 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a4644 mov r0, r4
 *   @0x2a4648 ldrtmi lr, [r4], -r10, lsl #31
 *   @0x2a464c b 0x2a468c <zip_fopen_index+0x108>
 *   @0x2a4650 strtvs r10, [r8], #-60
 *   @0x2a4654 ldr r3, [r5, #0x38]
 *   @0x2a4658 ldr r2, [r5, #0x40]
 *   @0x2a465c adds r1, r3, #0x1
 *   @0x2a4660 str.w r4, [r2, r3, lsl #2]
 *   @0x2a4664 str r5, [r0], #4
 *   @0x2a4668 bl 0x2a434e <_Z15_zip_error_initP9zip_error>
 *   @0x2a466c str r6, [r4, #0x10]
 *   @0x2a4670 mov r1, r6
 *   @0x2a4674 blx 0xb6ea4 <crc32@plt>
 *   @0x2a4678 mov.w r3, #0xffffffff
 *   @0x2a467c str r6, [r4, #0x28]
 *   @0x2a4680 str r6, [r4, #0x20]
 *   @0x2a4684 str r6, [r4, #0x18]
 *   @0x2a4688 str r6, [r4, #0x30]
 *   @0x2a468c str.w r9, [r4, #0x10]
 *   @0x2a4690 mov r0, r5
 *   @0x2a4694 mov r1, r7
 *   @0x2a4698 add r3, r8
 *   @0x2a469c str r3, [r4, #0x14]
 *   @0x2a46a0 ldr r3, [r3]
 *   @0x2a46a4 ldr r3, [r3, #0x14]
 *   @0x2a46a8 ldr r3, [r5, #0x20]
 *   @0x2a46ac add r3, r8
 *   @0x2a46b0 str r3, [r4, #0x20]
 *   @0x2a46b4 ldr r3, [r3]
 *   @0x2a46b8 ldr r3, [r3, #0xc]
 *   @0x2a46bc bl 0x2a58ee <_Z20_zip_file_get_offsetP3zipi>
 *   @0x2a46c0 str r0, [r4, #0x18]
 *   @0x2a46c4 ldr r3, [r4, #0x10]
 *   @0x2a46c8 bmi 0x2a46d0 <zip_fopen_index+0x14c>
 *   @0x2a46cc str r3, [r4, #0x1c]
 *   @0x2a46d0 mov.w r0, #0x2000
 *   @0x2a46d4 blx 0xb6544 <malloc@plt>
 *   @0x2a46d8 mov r6, r0
 *   @0x2a46dc cbnz r0, 0x2a46f4 <zip_fopen_index+0x170>
 *   @0x2a46e0 .word 0x210e000c
 *   @0x2a46e4 mov r2, r6
 *   @0x2a46e8 qasxmi pc, r0, r7
 *   @0x2a46ec bl 0x2a4388 <zip_fclose>
 *   @0x2a46f0 mov r4, r6
 *   @0x2a46f4 mov.w r1, #0x2000
 *   @0x2a46f8 mov r2, r4
 *   @0x2a46fc .word 0xf1b0feec
 *   @0x2a4700 .word 0xdc050800
 *   @0x2a4704 add.w r0, r5, #0xc
 *   @0x2a4708 adds r1, r4, #0x4
 *   @0x2a470c and pc, r11, r3, lsl #28
 *   @0x2a4710 movs r0, #0x38
 *   @0x2a4714 .word 0x4606ef18
 *   @0x2a4718 str r0, [r4, #0x30]
 *   @0x2a471c add.w r0, r5, #0xc
 *   @0x2a4720 movs r1, #0xe
 *   @0x2a4724 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a4728 mov r0, r4
 *   @0x2a472c ldr pc, [r7, -sp, lsr #28]!
 *   @0x2a4730 ldr r3, [r4, #0x2c]
 *   @0x2a4734 ldr r2, [pc, #0x30]
 *   @0x2a4738 andvs r0, r7, #-2147483645
 *   @0x2a473c stm.w r0, {r3, r8}
 *   @0x2a4740 add r2, pc
 *   @0x2a4744 movs r3, #0x38
 *   @0x2a4748 blx 0xb6f10 <inflateInit2_@plt>
 *   @0x2a474c mov r2, r0
 *   @0x2a4750 add.w r0, r5, #0xc
 *   @0x2a4754 movs r1, #0xd
 *   @0x2a4758 qsub8mi pc, r0, pc
 *   @0x2a475c bl 0x2a4388 <zip_fclose>
 *   @0x2a4760 mov r4, r7
 *   @0x2a4764 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2a4768 ldrb r0, [r1, #0x2]
 *
 * ══ §58/60 png_check_IHDR  0x2a61b0  size 488  122 条（0x2a61b0..0x2a6398）
 * @func 0x2a61b0 0x2a6398  size 488  122 条
 * 部分覆盖: 本节 122/223 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×4 / png_check_IHDR+0xe0 / png_check_IHDR+0x118
 * 字段偏移 top8: 0x30×7 / 0x34×6 / 0x2c×4 / 0x168×1 / 0x150×1 / 0x13c×1 / 0x124×1 / 0x108×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a61b0 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a61b4 mov r5, r3
 *   @0x2a61b8 subs.w r8, r1, #0x0
 *   @0x2a61bc mov r4, r0
 *   @0x2a61c0 ldr r6, [sp, #0x30]
 *   @0x2a61c4 movwls r11, #0x1034
 *   @0x2a61c8 ldr.w r9, [sp, #0x3c]
 *   @0x2a61cc bne 0x2a61d4 <png_check_IHDR+0x24>
 *   @0x2a61d0 add r1, pc
 *   @0x2a61d4 mov.w r10, #0x0
 *   @0x2a61d8 bge 0x2a61e6 <png_check_IHDR+0x36>
 *   @0x2a61dc add r1, pc
 *   @0x2a61e0 .word 0xf04ff949
 *   @0x2a61e4 .word 0xf1080a01
 *   @0x2a61e8 bmi 0x18e660c <b2_toiTime+0x118d168>
 *   @0x2a61ec bic r1, r1, #0x7
 *   @0x2a61f0 cmp r1, r2
 *   @0x2a61f4 ldr r1, [pc, #0x168]
 *   @0x2a61f8 mov.w r10, #0x1
 *   @0x2a61fc add r1, pc
 *   @0x2a6200 .word 0xf8d4f939
 *   @0x2a6204 ldrmi r2, [r0, #0x308]
 *   @0x2a6208 bhi 0x2a6210 <png_check_IHDR+0x60>
 *   @0x2a620c cmp r8, r2
 *   @0x2a6210 ldr r1, [pc, #0x150]
 *   @0x2a6214 mov.w r10, #0x1
 *   @0x2a6218 add r1, pc
 *   @0x2a621c svchs #0xf92b
 *   @0x2a6220 bne 0x2a622a <png_check_IHDR+0x7a>
 *   @0x2a6224 mov r0, r4
 *   @0x2a6228 b 0x2a6232 <png_check_IHDR+0x82>
 *   @0x2a622c ldr r1, [pc, #0x13c]
 *   @0x2a6230 add r1, pc
 *   @0x2a6234 .word 0xf04ff91f
 *   @0x2a6238 .word 0xf8d40a01
 *   @0x2a623c addsmi r2, r7, #12, #6
 *   @0x2a6240 bhi 0x2a6248 <png_check_IHDR+0x98>
 *   @0x2a6244 cmp r7, r2
 *   @0x2a6248 ldr r1, [pc, #0x124]
 *   @0x2a624c mov.w r10, #0x1
 *   @0x2a6250 add r1, pc
 *   @0x2a6254 cdpne p9, #0x6, c15, c10, c15, #0x0
 *   @0x2a6258 cmp r2, #0x1
 *   @0x2a625c cmp r5, #0x4
 *   @0x2a6260 cmp r5, #0x8
 *   @0x2a6264 cmp r5, #0x10
 *   @0x2a6268 ldr r1, [pc, #0x108]
 *   @0x2a626c mov.w r10, #0x1
 *   @0x2a6270 add r1, pc
 *   @0x2a6274 .word 0xf026f8ff
 *   @0x2a6278 svchs #0x10704
 *   @0x2a627c beq 0x2a6282 <png_check_IHDR+0xd2>
 *   @0x2a6280 bls 0x2a6290 <png_check_IHDR+0xe0>
 *   @0x2a6284 mov r0, r4
 *   @0x2a6288 ldrbtmi r0, [r9], #-2561
 *   @0x2a628c bl 0x2a6474 <png_warning>
 *   @0x2a6290 cmp r6, #0x3
 *   @0x2a6294 cmp r5, #0x8
 *   @0x2a6298 b 0x2a62b4 <png_check_IHDR+0x104>
 *   @0x2a629c beq 0x2a62a2 <png_check_IHDR+0xf2>
 *   @0x2a62a0 bne 0x2a62b4 <png_check_IHDR+0x104>
 *   @0x2a62a4 bgt 0x2a62b4 <png_check_IHDR+0x104>
 *   @0x2a62a8 mov r0, r4
 *   @0x2a62ac ldrbtmi r0, [r9], #-2561
 *   @0x2a62b0 bl 0x2a6474 <png_warning>
 *   @0x2a62b4 cmp.w r11, #0x1
 *   @0x2a62b8 ble 0x2a62c8 <png_check_IHDR+0x118>
 *   @0x2a62bc mov r0, r4
 *   @0x2a62c0 ldrbtmi r0, [r9], #-2561
 *   @0x2a62c4 bl 0x2a6474 <png_warning>
 *   @0x2a62c8 ldr r3, [sp, #0x4]
 *   @0x2a62cc ldr r1, [pc, #0xb4]
 *   @0x2a62d0 mov.w r10, #0x1
 *   @0x2a62d4 add r1, pc
 *   @0x2a62d8 .word 0xf8d4f8cd
 *   @0x2a62dc ldrbeq r2, [r0], #300
 *   @0x2a62e0 bpl 0x2a62f2 <png_check_IHDR+0x142>
 *   @0x2a62e4 ldrdlt r2, r3, [r2, -r12]!
 *   @0x2a62e8 ldr r1, [pc, #0x9c]
 *   @0x2a62ec add r1, pc
 *   @0x2a62f0 .word 0xf1b9f8c1
 *   @0x2a62f4 andsle r0, sp, r0, lsl #30
 *   @0x2a62f8 ldr.w r2, [r4, #0x2dc]
 *   @0x2a62fc lsls r1, r2, #0x1d
 *   @0x2a6300 cmp.w r9, #0x40
 *   @0x2a6304 bne 0x2a6312 <png_check_IHDR+0x162>
 *   @0x2a6308 ldrbeq r2, [r2], #300
 *   @0x2a630c bmi 0x2a6312 <png_check_IHDR+0x162>
 *   @0x2a6310 beq 0x2a6320 <png_check_IHDR+0x170>
 *   @0x2a6314 mov r0, r4
 *   @0x2a6318 ldrbtmi r0, [r9], #-2561
 *   @0x2a631c bl 0x2a6474 <png_warning>
 *   @0x2a6320 ldr.w r2, [r4, #0x12c]
 *   @0x2a6324 lsls r3, r2, #0x13
 *   @0x2a6328 ldr r1, [pc, #0x64]
 *   @0x2a632c add r1, pc
 *   @0x2a6330 and pc, r2, r1, lsr #17
 *   @0x2a6334 cmp.w r10, #0x0
 *   @0x2a6338 beq 0x2a634a <png_check_IHDR+0x19a>
 *   @0x2a633c mov r0, r4
 *   @0x2a6340 add sp, #0xc
 *   @0x2a6344 .word 0xf0004ff0
 *   @0x2a6348 andlt r11, r3, r1, ror r8
 *   @0x2a634c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2a6350 .word 0xfff8 1fff
 *   @0x2a6354 rsbs r0, r0, #0
 *   @0x2a6358 str r0, [r4, #0x2c]
 *   @0x2a635c str r0, [r6, #0x2c]
 *   @0x2a6360 str r4, [r5, #0x2c]
 *   @0x2a6364 str r7, [r7, #0x2c]
 *   @0x2a6368 str r0, [r3, #0x30]
 *   @0x2a636c str r3, [r5, #0x30]
 *   @0x2a6370 str r0, [r5, #0x30]
 *   @0x2a6374 str r0, [r6, #0x30]
 *   @0x2a6378 str r0, [r6, #0x30]
 *   @0x2a637c str r7, [r4, #0x30]
 *   @0x2a6380 str r4, [r0, #0x34]
 *   @0x2a6384 str r3, [r2, #0x34]
 *   @0x2a6388 str r6, [r3, #0x34]
 *   @0x2a638c str r1, [r4, #0x34]
 *   @0x2a6390 str r5, [r5, #0x34]
 *   @0x2a6394 str r1, [r7, #0x34]
 *
 * ══ §59/60 png_set_text_2  0x2aeef8  size 488  122 条（0x2aeef8..0x2af0e0）
 * @func 0x2aeef8 0x2af0e0  size 488  122 条
 * 部分覆盖: 本节 122/224 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×3 / 0xb6538×2 / png_set_text_2+0x5a / png_warning / 0x369abc / png_set_text_2+0xe2 / png_write_gAMA+0x40 / png_set_text_2+0x192
 * 字段偏移 top8: 0x4×6 / 0x8×5 / 0x18×4 / 0x10×3 / 0x34×3 / 0x14×3 / 0xc×2 / 0x38×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aeef8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2aeefc sub sp, #0x1c
 *   @0x2aef00 mov r9, r2
 *   @0x2aef04 str r0, [sp, #0x10]
 *   @0x2aef08 movs r0, #0x0
 *   @0x2aef0c cmp r1, #0x0
 *   @0x2aef10 ldr r3, [sp, #0xc]
 *   @0x2aef14 beq 0x2aef08 <png_set_text_2+0x10>
 *   @0x2aef18 mov r1, r3
 *   @0x2aef1c add r1, r5
 *   @0x2aef20 ble 0x2aef52 <png_set_text_2+0x5a>
 *   @0x2aef24 mov.w r8, #0x1c
 *   @0x2aef28 cbz r6, 0x2aef60 <png_set_text_2+0x68>
 *   @0x2aef2c str r1, [r4, #0x34]
 *   @0x2aef30 .word 0xf7f7f101
 *   @0x2aef34 movvs pc, #240, #28
 *   @0x2aef38 cbnz r0, 0x2aef40 <png_set_text_2+0x48>
 *   @0x2aef3c str r6, [r4, #0x38]
 *   @0x2aef40 mov r1, r6
 *   @0x2aef44 .word 0xf607f207
 *   @0x2aef48 stmdals r4, {r1, r3, r4, r5, r8, r9, r11, sp, lr, pc}
 *   @0x2aef4c mov r1, r6
 *   @0x2aef50 movwhs pc, #0xed5
 *   @0x2aef54 str r3, [sp, #0x4]
 *   @0x2aef58 mov r5, r9
 *   @0x2aef5c str r3, [sp, #0x14]
 *   @0x2aef60 ldr r3, [sp, #0xc]
 *   @0x2aef64 add.w r1, r3, #0x8
 *   @0x2aef68 str r1, [r4, #0x34]
 *   @0x2aef6c .word 0xf7f7f101
 *   @0x2aef70 movvs pc, #3360
 *   @0x2aef74 cbnz r0, 0x2aef7c <png_set_text_2+0x84>
 *   @0x2aef78 str r7, [r4, #0x34]
 *   @0x2aef7c ldr.w r3, [r4, #0xb8]
 *   @0x2aef80 orr r3, r3, #0x4000
 *   @0x2aef84 str.w r3, [r4, #0xb8]
 *   @0x2aef88 b 0x2aef52 <png_set_text_2+0x5a>
 *   @0x2aef8c ldr r0, [r5, #0x4]
 *   @0x2aef90 str r3, [sp]
 *   @0x2aef94 ldr r3, [sp, #0x4]
 *   @0x2aef98 adds r3, #0x1
 *   @0x2aef9c ldr r2, [sp, #0x4]
 *   @0x2aefa0 cmp r2, r3
 *   @0x2aefa4 b 0x2aef08 <png_set_text_2+0x10>
 *   @0x2aefa8 adds r3, r2, #0x1
 *   @0x2aefac str r2, [sp, #0x8]
 *   @0x2aefb0 ldr r0, [sp, #0x10]
 *   @0x2aefb4 bl 0x2a6474 <png_warning>
 *   @0x2aefb8 b 0x2aef94 <png_set_text_2+0x9c>
 *   @0x2aefbc blls 0x369abc <_ZTS13C_UTF16String+0xb68>
 *   @0x2aefc0 cmp r3, #0x0
 *   @0x2aefc4 ble 0x2aefda <png_set_text_2+0xe2>
 *   @0x2aefc8 cbz r0, 0x2aefce <png_set_text_2+0xd6>
 *   @0x2aefcc selmi lr, r0, r6
 *   @0x2aefd0 ldr r0, [r5, #0x18]
 *   @0x2aefd4 blx 0xb6538 <strlen@plt>
 *   @0x2aefd8 b 0x2aefe0 <png_set_text_2+0xe8>
 *   @0x2aefdc mov r8, r7
 *   @0x2aefe0 mov r7, r0
 *   @0x2aefe4 ldr r0, [r5, #0x8]
 *   @0x2aefe8 vmlals.f64 d15, d0, d6
 *   @0x2aefec add r6, r11
 *   @0x2aeff0 ldrb r2, [r0]
 *   @0x2aeff4 ldr r2, [sp, #0x8]
 *   @0x2aeff8 blls 0x2b1800 <png_write_gAMA+0x40>
 *   @0x2aeffc cmp r2, #0x0
 *   @0x2af000 movgt r2, #0x1
 *   @0x2af004 .word 0xf84332ff
 *   @0x2af008 and r2, r6, r11
 *   @0x2af00c blx 0xb6538 <strlen@plt>
 *   @0x2af010 ldr r2, [sp, #0x8]
 *   @0x2af014 str.w r2, [r3, r11]
 *   @0x2af018 mov r10, r0
 *   @0x2af01c stmdals r4, {r2, r8}
 *   @0x2af020 add r1, r8
 *   @0x2af024 add r1, r10
 *   @0x2af028 rsbsvs pc, r0, r6, ror lr
 *   @0x2af02c cmp r0, #0x0
 *   @0x2af030 mov r2, r9
 *   @0x2af034 blx 0xb65bc <memcpy@plt>
 *   @0x2af038 ldr r2, [r6, #0x4]
 *   @0x2af03c .word 0xf8020300
 *   @0x2af040 .word 0xf1093009
 *   @0x2af044 stmdavs r10!, {r0, r8, r11}
 *   @0x2af048 ldr r0, [r6, #0x4]
 *   @0x2af04c ble 0x2af08a <png_set_text_2+0x192>
 *   @0x2af050 add r0, r9
 *   @0x2af054 ldr r1, [r5, #0x14]
 *   @0x2af058 ldmdbvs r2!, {r1, r4, r5, r7, r9, r11, sp, lr, pc} ^
 *   @0x2af05c mov.w r3, #0x0
 *   @0x2af060 strb.w r3, [r2, r8]
 *   @0x2af064 add.w r8, r8, #0x1
 *   @0x2af068 ldr r2, [r6, #0x14]
 *   @0x2af06c ldrtmi r0, [r10], -r8
 *   @0x2af070 str r0, [r6, #0x18]
 *   @0x2af074 blx 0xb65bc <memcpy@plt>
 *   @0x2af078 ldr r2, [r6, #0x18]
 *   @0x2af07c ldrbpl r0, [r3, #0x300]
 *   @0x2af080 adds r7, #0x1
 *   @0x2af084 add r2, r7
 *   @0x2af088 b 0x2af094 <png_set_text_2+0x19c>
 *   @0x2af08c add r0, r9
 *   @0x2af090 str r2, [r6, #0x18]
 *   @0x2af094 cmp.w r10, #0x0
 *   @0x2af098 beq 0x2af0a4 <png_set_text_2+0x1ac>
 *   @0x2af09c mov r2, r10
 *   @0x2af0a0 blx 0xb65bc <memcpy@plt>
 *   @0x2af0a4 ldr r2, [r6, #0x8]
 *   @0x2af0a8 .word 0xf8020300
 *   @0x2af0ac blls 0x2bb0dc <jinit_1pass_quantizer+0x3ac>
 *   @0x2af0b0 ldr.w r2, [r3, r11]
 *   @0x2af0b4 cmp r2, #0x0
 *   @0x2af0b8 movs r2, #0x0
 *   @0x2af0bc rscsvs r10, r2, r0, lsl r0
 *   @0x2af0c0 b 0x2af0ca <png_set_text_2+0x1d2>
 *   @0x2af0c4 str.w r10, [r6, #0xc]
 *   @0x2af0c8 str r3, [r6, #0x10]
 *   @0x2af0cc adds r3, #0x1
 *   @0x2af0d0 b 0x2aef94 <png_set_text_2+0x9c>
 *   @0x2af0d4 add sp, #0x1c
 *   @0x2af0d8 svclt #0x8ff0
 *   @0x2af0dc ldc p0, c0, [r12], #52
 *
 * ══ §60/60 Audio_SoundGain(int, float, int)  0x2178f0  size 400  86 条（0x2178f0..0x217a80）｜其中 14 条已由别的卡落锚，本节不再重复
 * @func 0x2178f0 0x217a80  size 400  86 条
 * 部分覆盖: 本节 86/100 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x217904→0x755363, 0x217920→0x755314, 0x217934→0x5428e8, 0x217948→0x54298c, 0x217980→0x3f52d0, 0x217a44→0x5428c0
 * 调用序列: __divsi3×2 / Audio_SoundGain(int, float, int)+0x134 / Audio_GetSound(int) / Audio_GetNoiseFromID(int) / CTimingSource::GetFPS()
 * 字段偏移 top8: 0x20×3 / 0x160×1 / 0x15c×1 / 0x144×1 / 0x134×1 / 0x124×1 / 0xc×1 / 0xf0×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2178f0 push {r4, r5, r6, lr}
 *   @0x2178f4 vpush {d8}
 *   @0x2178f8 mov r5, r0
 *   @0x217918 cmp r3, #0
 *   @0x21791c bne 0x217a1c <_Z15Audio_SoundGainifi+0x12c>
 *   @0x217920 ldr r3, [pc, #0x144]
 *   @0x217924 ldr r3, [r4, r3]
 *   @0x217928 ldrb r3, [r3]
 *   @0x217948 ldr r3, [pc, #0x124]
 *   @0x21794c ldr r3, [r4, r3]
 *   @0x217950 ldr r3, [r3]
 *   @0x217954 cmp r3, #0
 *   @0x217958 moveq r1, #33
 *   @0x21795c beq 0x217978 <_Z15Audio_SoundGainifi+0x88>
 *   @0x217960 ldr r1, [r3, #0xc]
 *   @0x217964 mov r0, #1000
 *   @0x217968 bl 0x318d10 <__divsi3>
 *   @0x21796c cmp r0, #1
 *   @0x217970 movge r1, r0
 *   @0x217974 movlt r1, #1
 *   @0x217978 mov r0, r6
 *   @0x21797c bl 0x318d10 <__divsi3>
 *   @0x217980 ldr r3, [pc, #0xf0]
 *   @0x217984 vcmp.f32 s16, #0
 *   @0x217988 vldr s15, [pc, #208]
 *   @0x21798c ldr r3, [r4, r3]
 *   @0x217990 ldr r3, [r3]
 *   @0x217994 cmp r0, #1
 *   @0x217998 movge r4, r0
 *   @0x21799c movlt r4, #1
 *   @0x2179a0 vmrs APSR_nzcv, fpscr
 *   @0x2179a4 vmovmi.f32 s16, s15
 *   @0x2179a8 cmp r3, r5
 *   @0x2179ac mov r0, r5
 *   @0x2179b0 ble 0x217a24 <_Z15Audio_SoundGainifi+0x134>
 *   @0x2179b4 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x2179b8 subs r3, r0, #0
 *   @0x2179bc beq 0x217a1c <_Z15Audio_SoundGainifi+0x12c>
 *   @0x2179c0 cmp r6, #0
 *   @0x2179c4 vldr s15, [r3, #4]
 *   @0x2179c8 bne 0x217a04 <_Z15Audio_SoundGainifi+0x114>
 *   @0x2179cc vcmp.f32 s15, s16
 *   @0x2179d0 vmrs APSR_nzcv, fpscr
 *   @0x2179d4 bne 0x2179e4 <_Z15Audio_SoundGainifi+0xf4>
 *   @0x2179d8 ldr r2, [r3, #0x20]
 *   @0x2179dc cmp r2, #0
 *   @0x2179e0 beq 0x217a1c <_Z15Audio_SoundGainifi+0x12c>
 *   @0x2179e4 vstr s16, [r3, #4]
 *   @0x2179e8 vmov r1, s16
 *   @0x2179ec vpop {d8}
 *   @0x2179f0 mov r0, r5
 *   @0x2179f4 mov r2, #0
 *   @0x2179f8 str r2, [r3, #0x20]
 *   @0x2179fc pop {r4, r5, r6, lr}
 *   @0x217a00 b 0x217688 <_Z24setGainForSoundImmediateif>
 *   @0x217a04 vsub.f32 s16, s16, s15
 *   @0x217a08 str r4, [r3, #0x20]
 *   @0x217a0c vmov s14, r4
 *   @0x217a10 vcvt.f32.s32 s15, s14
 *   @0x217a14 vdiv.f32 s16, s16, s15
 *   @0x217a18 vstr s16, [r3, #28]
 *   @0x217a1c vpop {d8}
 *   @0x217a20 pop {r4, r5, r6, pc}
 *   @0x217a24 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x217a28 cmp r0, #0
 *   @0x217a2c beq 0x217a1c <_Z15Audio_SoundGainifi+0x12c>
 *   @0x217a30 vmov r1, s16
 *   @0x217a34 mov r2, r6
 *   @0x217a38 vpop {d8}
 *   @0x217a3c pop {r4, r5, r6, lr}
 *   @0x217a40 b 0x217758 <_Z21Audio_SetGainForNoiseP6CNoisefi>
 *   @0x217a44 ldr r3, [pc, #0x30]
 *   @0x217a48 ldr r0, [r4, r3]
 *   @0x217a4c bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x217a50 vmov d7, r0, r1
 *   @0x217a54 vcvt.s32.f64 s15, d7
 *   @0x217a58 vmov r1, s15
 *   @0x217a5c b 0x217964 <_Z15Audio_SoundGainifi+0x74>
 *   @0x217a60 andeq r0, r0, r0
 *   @0x217a64 andseq r10, sp, r4, asr #6
 *   @0x217a68 .word 0xffffd3fc
 *   @0x217a6c .word 0xffffd0e0
 *   @0x217a70 .word 0xffffbcd4
 *   @0x217a74 .word 0xffffbcd8
 *   @0x217a78 .word 0xfffff794
 *   @0x217a7c .word 0xffffbcdc
 */
