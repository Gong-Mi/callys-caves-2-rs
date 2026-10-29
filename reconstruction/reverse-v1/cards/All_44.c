/* cally 逆向卡：All_44 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 70 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/70 b2WheelJoint::SolvePositionConstraints(b2SolverData const&)  0x2d3bc0  size 448  112 条（0x2d3bc0..0x2d3d80）
 * @func 0x2d3bc0 0x2d3d80  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / 0xfebc99ac
 * 字段偏移 top8: 0x84×1 / 0x88×1 / 0x18×1
 * VFP 指令 94 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3bc0 push {r4, r5, r6, lr}
 *   @0x2d3bc4 vpush {d8, d9, d10, d11, d12}
 *   @0x2d3bc8 mov r4, r0
 *   @0x2d3bcc ldr r6, [r0, #0x84]
 *   @0x2d3bd0 ldr r5, [r0, #0x88]
 *   @0x2d3bd4 ldr r3, [r1, #0x18]
 *   @0x2d3bd8 add r6, r6, r6, lsl #1
 *   @0x2d3bdc add r5, r5, r5, lsl #1
 *   @0x2d3be0 add r6, r3, r6, lsl #2
 *   @0x2d3be4 vldr s19, [r6, #8]
 *   @0x2d3be8 vmov r0, s19
 *   @0x2d3bec add r5, r3, r5, lsl #2
 *   @0x2d3bf0 bl 0xb6580 <sinf@plt>
 *   @0x2d3bf4 vldr s18, [r5, #8]
 *   @0x2d3bf8 vldr s20, [r6, #4]
 *   @0x2d3bfc vmov s16, r0
 *   @0x2d3c00 vmov r0, s19
 *   @0x2d3c04 bl 0xb658c <cosf@plt>
 *   @0x2d3c08 vmov s17, r0
 *   @0x2d3c0c vmov r0, s18
 *   @0x2d3c10 bl 0xb6580 <sinf@plt>
 *   @0x2d3c14 vmov s21, r0
 *   @0x2d3c18 vmov r0, s18
 *   @0x2d3c1c bl 0xb658c <cosf@plt>
 *   @0x2d3c20 vldr s15, [r4, #152]
 *   @0x2d3c24 vldr s11, [r4, #88]
 *   @0x2d3c28 vsub.f32 s11, s11, s15
 *   @0x2d3c2c vldr s12, [r4, #148]
 *   @0x2d3c30 vldr s25, [r4, #84]
 *   @0x2d3c34 vldr s8, [r4, #80]
 *   @0x2d3c38 vldr s10, [r4, #144]
 *   @0x2d3c3c vldr s14, [r4, #196]
 *   @0x2d3c40 vldr s2, [r4, #164]
 *   @0x2d3c44 vldr s6, [r4, #156]
 *   @0x2d3c48 vldr s7, [r4, #160]
 *   @0x2d3c4c vldr s13, [r4, #140]
 *   @0x2d3c50 vldr s0, [r4, #76]
 *   @0x2d3c54 vldr s15, [r4, #104]
 *   @0x2d3c58 vldr s4, [r5, #4]
 *   @0x2d3c5c vldr s23, [r4, #100]
 *   @0x2d3c60 vldr s3, [r5]
 *   @0x2d3c64 vldr s1, [r6]
 *   @0x2d3c68 vldr s22, [r4, #200]
 *   @0x2d3c6c vldr s5, [r4, #168]
 *   @0x2d3c70 vsub.f32 s25, s25, s12
 *   @0x2d3c74 vsub.f32 s10, s8, s10
 *   @0x2d3c78 vsub.f32 s0, s0, s13
 *   @0x2d3c7c vmov s24, r0
 *   @0x2d3c80 vmul.f32 s9, s11, s24
 *   @0x2d3c84 vmul.f32 s11, s11, s21
 *   @0x2d3c88 vmla.f32 s9, s25, s21
 *   @0x2d3c8c vmul.f32 s21, s2, s14
 *   @0x2d3c90 vmul.f32 s8, s10, s17
 *   @0x2d3c94 vadd.f32 s13, s6, s7
 *   @0x2d3c98 vmla.f32 s13, s14, s21
 *   @0x2d3c9c vmul.f32 s14, s15, s16
 *   @0x2d3ca0 vmul.f32 s15, s15, s17
 *   @0x2d3ca4 vmla.f32 s8, s0, s16
 *   @0x2d3ca8 vmul.f32 s10, s10, s16
 *   @0x2d3cac vsub.f32 s12, s4, s20
 *   @0x2d3cb0 vnmls.f32 s11, s25, s24
 *   @0x2d3cb4 vmla.f32 s15, s23, s16
 *   @0x2d3cb8 vadd.f32 s12, s9, s12
 *   @0x2d3cbc vnmls.f32 s10, s0, s17
 *   @0x2d3cc0 vsub.f32 s0, s3, s1
 *   @0x2d3cc4 vsub.f32 s12, s12, s8
 *   @0x2d3cc8 vnmls.f32 s14, s23, s17
 *   @0x2d3ccc vadd.f32 s0, s11, s0
 *   @0x2d3cd0 vmul.f32 s21, s5, s22
 *   @0x2d3cd4 vadd.f32 s8, s8, s12
 *   @0x2d3cd8 vmul.f32 s12, s12, s15
 *   @0x2d3cdc vsub.f32 s0, s0, s10
 *   @0x2d3ce0 vmla.f32 s13, s22, s21
 *   @0x2d3ce4 vmla.f32 s12, s0, s14
 *   @0x2d3ce8 vmul.f32 s9, s9, s14
 *   @0x2d3cec vcmp.f32 s13, #0
 *   @0x2d3cf0 vnmls.f32 s9, s11, s15
 *   @0x2d3cf4 vmrs APSR_nzcv, fpscr
 *   @0x2d3cf8 vldreq s13, [pc, #120]
 *   @0x2d3cfc vnegne.f32 s11, s12
 *   @0x2d3d00 vdivne.f32 s13, s11, s13
 *   @0x2d3d04 vmul.f32 s8, s14, s8
 *   @0x2d3d08 vadd.f32 s10, s10, s0
 *   @0x2d3d0c vnmls.f32 s8, s15, s10
 *   @0x2d3d10 vmul.f32 s14, s13, s14
 *   @0x2d3d14 vmul.f32 s15, s13, s15
 *   @0x2d3d18 vmul.f32 s8, s13, s8
 *   @0x2d3d1c vmul.f32 s13, s13, s9
 *   @0x2d3d20 vmls.f32 s20, s6, s15
 *   @0x2d3d24 vmls.f32 s19, s2, s8
 *   @0x2d3d28 vstr s20, [r6, #4]
 *   @0x2d3d2c vmla.f32 s4, s7, s15
 *   @0x2d3d30 vstr s19, [r6, #8]
 *   @0x2d3d34 vldr s15, [pc, #64]
 *   @0x2d3d38 vmla.f32 s18, s5, s13
 *   @0x2d3d3c vmls.f32 s1, s6, s14
 *   @0x2d3d40 vmla.f32 s3, s7, s14
 *   @0x2d3d44 vstr s1, [r6]
 *   @0x2d3d48 vcmpe.f32 s12, #0
 *   @0x2d3d4c vstr s3, [r5]
 *   @0x2d3d50 vstr s4, [r5, #4]
 *   @0x2d3d54 vstr s18, [r5, #8]
 *   @0x2d3d58 vpop {d8, d9, d10, d11, d12}
 *   @0x2d3d5c vmrs APSR_nzcv, fpscr
 *   @0x2d3d60 vnegle.f32 s12, s12
 *   @0x2d3d64 vcmpe.f32 s12, s15
 *   @0x2d3d68 vmrs APSR_nzcv, fpscr
 *   @0x2d3d6c movhi r0, #0
 *   @0x2d3d70 movls r0, #1
 *   @0x2d3d74 pop {r4, r5, r6, pc}
 *   @0x2d3d78 andeq r0, r0, r0
 *   @0x2d3d7c bllo 0xfebc99ac <b2_toiTime+0xfffffffffe470508>
 *
 * ══ §2/70 CSkeletonInstance::EventCallback(int, spEventType, spEvent*, int)  0xbebe4  size 444  111 条（0xbebe4..0xbeda0）
 * @func 0xbebe4 0xbeda0  size 444  111 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...) / Perform_Event(CInstance*, CInstance*, int, int) / CSkeletonInstance::EventCallback(int, spEventType, spEvent*, int)+0x170 / DS_AutoMutex::DS_AutoMutex() / CDS_Map::~CDS_Map() / operator delete(void*) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x4×3 / 0x10×2 / 0x30×2 / 0x168×1 / 0x144×1 / 0x40×1 / 0x110×1 / 0x20×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbebe4 cmp r2, #3
 *   @0xbebe8 push {r4, r5, r6, r7, lr}
 *   @0xbebec sub sp, sp, #84
 *   @0xbebf0 bne 0xbed5c <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x178>
 *   @0xbebf4 cmp r3, #0
 *   @0xbebf8 beq 0xbed5c <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x178>
 *   @0xbebfc ldr r0, [r3]
 *   @0xbec00 cmp r0, #0
 *   @0xbec04 beq 0xbed5c <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x178>
 *   @0xbec08 ldr r5, [pc, #0x168]
 *   @0xbec0c ldr r5, [pc, r5]
 *   @0xbec10 ldr r2, [r5]
 *   @0xbec14 cmp r2, #0
 *   @0xbec18 beq 0xbed5c <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x178>
 *   @0xbec1c ldr r2, [r3, #0x10]
 *   @0xbec20 cmp r2, #0
 *   @0xbec24 beq 0xbed70 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x18c>
 *   @0xbec28 ldr r0, [r0]
 *   @0xbec2c vmov s15, r1
 *   @0xbec30 ldr r6, [pc, #0x144]
 *   @0xbec34 vldr s12, [r3, #8]
 *   @0xbec38 cmp r0, #0
 *   @0xbec3c vldr s14, [r3, #12]
 *   @0xbec40 add r6, pc, r6
 *   @0xbec44 vcvt.f64.s32 d5, s15
 *   @0xbec48 movne r6, r0
 *   @0xbec4c cmp r2, #0
 *   @0xbec50 movne r1, r2
 *   @0xbec54 vcvt.f64.s32 d6, s12
 *   @0xbec58 vcvt.f64.f32 d7, s14
 *   @0xbec5c beq 0xbed64 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x180>
 *   @0xbec60 str r1, [sp, #0x40]
 *   @0xbec64 mov r1, #0
 *   @0xbec68 ldr r0, [pc, #0x110]
 *   @0xbec6c mov r2, #0
 *   @0xbec70 str r1, [sp, #0x10]
 *   @0xbec74 mov r3, #0
 *   @0xbec78 str r1, [sp, #0x20]
 *   @0xbec7c add r0, pc, r0
 *   @0xbec80 str r1, [sp, #0x30]
 *   @0xbec84 vstr d5, [sp, #8]
 *   @0xbec88 ldr r4, [pc, #0xf4]
 *   @0xbec8c vstr d6, [sp, #24]
 *   @0xbec90 ldr lr, [pc, #0xf0]
 *   @0xbec94 vstr d7, [sp, #40]
 *   @0xbec98 ldr r12, [pc, #0xec]
 *   @0xbec9c add r4, pc, r4
 *   @0xbeca0 ldr r1, [pc, #0xe8]
 *   @0xbeca4 add lr, pc, lr
 *   @0xbeca8 add r12, pc, r12
 *   @0xbecac strd r2, r3, [sp, #56]
 *   @0xbecb0 str r0, [sp, #0x4]
 *   @0xbecb4 add r1, pc, r1
 *   @0xbecb8 str r4, [sp, #0x14]
 *   @0xbecbc mov r0, #5
 *   @0xbecc0 str lr, [sp, #0x24]
 *   @0xbecc4 str r12, [sp, #0x34]
 *   @0xbecc8 str r6, [sp]
 *   @0xbeccc bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0xbecd0 ldr r4, [pc, #0xbc]
 *   @0xbecd4 ldr r1, [r5]
 *   @0xbecd8 mov r3, #59
 *   @0xbecdc ldr r4, [pc, r4]
 *   @0xbece0 mov r2, #7
 *   @0xbece4 str r0, [r4]
 *   @0xbece8 mov r0, r1
 *   @0xbecec bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0xbecf0 ldr r3, [r4]
 *   @0xbecf4 cmp r3, #0
 *   @0xbecf8 blt 0xbed54 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x170>
 *   @0xbecfc add r7, sp, #76
 *   @0xbed00 ldr r5, [pc, #0x90]
 *   @0xbed04 mov r0, r7
 *   @0xbed08 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xbed0c ldr r5, [pc, r5]
 *   @0xbed10 ldr r2, [r4]
 *   @0xbed14 ldr r3, [r5, #0x4]
 *   @0xbed18 add r1, r3, r2, lsl #2
 *   @0xbed1c ldr r6, [r3, r2, lsl #2]
 *   @0xbed20 cmp r6, #0
 *   @0xbed24 beq 0xbed44 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x160>
 *   @0xbed28 mov r0, r6
 *   @0xbed2c bl 0x20d9e8 <_ZN7CDS_MapD2Ev>
 *   @0xbed30 mov r0, r6
 *   @0xbed34 bl 0x27d1d0 <_ZdlPv>
 *   @0xbed38 ldr r1, [r4]
 *   @0xbed3c ldr r3, [r5, #0x4]
 *   @0xbed40 add r1, r3, r1, lsl #2
 *   @0xbed44 mov r3, #0
 *   @0xbed48 mov r0, r7
 *   @0xbed4c str r3, [r1]
 *   @0xbed50 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xbed54 mvn r3, #0
 *   @0xbed58 str r3, [r4]
 *   @0xbed5c add sp, sp, #84
 *   @0xbed60 pop {r4, r5, r6, r7, pc}
 *   @0xbed64 ldr r1, [pc, #0x30]
 *   @0xbed68 add r1, pc, r1
 *   @0xbed6c b 0xbec60 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x7c>
 *   @0xbed70 ldr r2, [r0, #0xc]
 *   @0xbed74 b 0xbec28 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x44>
 *   @0xbed78 eorseq lr, r2, r8, lsr #26
 *   @0xbed7c .word 0x0026fef6
 *   @0xbed80 mlaeq r7, r4, r11, r1
 *   @0xbed84 eoreq r1, r7, r12, ror r11
 *   @0xbed88 eoreq r1, r7, r12, ror r11
 *   @0xbed8c eoreq r1, r7, r0, lsl #23
 *   @0xbed90 eoreq r1, r7, r4, asr r11
 *   @0xbed94 eorseq lr, r2, r12, asr r12
 *   @0xbed98 eorseq lr, r2, r0, lsr r12
 *   @0xbed9c eoreq pc, r6, lr, asr #27
 *
 * ══ §3/70 VM::GetDSGrid(Buffer_Standard*, int, int)  0xdb70c  size 444  111 条（0xdb70c..0xdb8c8）
 * @func 0xdb70c 0xdb8c8  size 444  111 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetTheGrids(int&) / VM::GetDSGrid(Buffer_Standard*, int, int)+0x17c / VM::GetDSGrid(Buffer_Standard*, int, int)+0x140 / VM::GetDSGrid(Buffer_Standard*, int, int)+0x12c / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*) / VM::GetDSGrid(Buffer_Standard*, int, int)+0xc8
 * 字段偏移 top8: 0x8×6 / 0x38×5 / 0x4×4 / 0x30×4 / 0x2c×4 / 0xc×1 / 0x2×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb70c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xdb710 sub sp, sp, #20
 *   @0xdb714 mov r8, r0
 *   @0xdb718 add r0, sp, #12
 *   @0xdb71c mov r4, r1
 *   @0xdb720 mov r7, r2
 *   @0xdb724 bl 0x10026c <_Z11GetTheGridsRi>
 *   @0xdb728 cmp r4, #0
 *   @0xdb72c blt 0xdb888 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x17c>
 *   @0xdb730 ldr r3, [sp, #0xc]
 *   @0xdb734 cmp r4, r3
 *   @0xdb738 bge 0xdb888 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x17c>
 *   @0xdb73c ldr r6, [r0, r4, lsl #2]
 *   @0xdb740 cmp r6, #0
 *   @0xdb744 beq 0xdb888 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x17c>
 *   @0xdb748 ldr r3, [r6, #0x4]
 *   @0xdb74c add r10, r8, #44
 *   @0xdb750 ldr r12, [r8]
 *   @0xdb754 mov r11, #0
 *   @0xdb758 ldr r9, [r6, #0x8]
 *   @0xdb75c mov r2, r10
 *   @0xdb760 vmov s15, r3
 *   @0xdb764 str r11, [r8, #0x38]
 *   @0xdb768 mov r1, #5
 *   @0xdb76c mov r0, r8
 *   @0xdb770 vcvt.f64.u32 d7, s15
 *   @0xdb774 vmov r4, r5, d7
 *   @0xdb778 vstr s14, [r8, #44]
 *   @0xdb77c str r5, [r8, #0x30]
 *   @0xdb780 ldr r12, [r12, #0x8]
 *   @0xdb784 str r3, [sp, #0x4]
 *   @0xdb788 blx r12
 *   @0xdb78c vmov s13, r9
 *   @0xdb790 ldr lr, [r8]
 *   @0xdb794 mov r2, r10
 *   @0xdb798 vcvt.f64.u32 d7, s13
 *   @0xdb79c str r11, [r8, #0x38]
 *   @0xdb7a0 mov r0, r8
 *   @0xdb7a4 mov r1, #5
 *   @0xdb7a8 vstr s14, [r8, #44]
 *   @0xdb7ac vstr s15, [r8, #48]
 *   @0xdb7b0 ldr r12, [lr, #0x8]
 *   @0xdb7b4 blx r12
 *   @0xdb7b8 cmp r7, r11
 *   @0xdb7bc ldr r3, [sp, #0x4]
 *   @0xdb7c0 blt 0xdb84c <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x140>
 *   @0xdb7c4 mov r5, #0
 *   @0xdb7c8 movt r5, #0x3ff0
 *   @0xdb7cc mov r4, #0
 *   @0xdb7d0 mov r3, #1
 *   @0xdb7d4 ldr r0, [r8]
 *   @0xdb7d8 mov r2, r10
 *   @0xdb7dc str r4, [r8, #0x2c]
 *   @0xdb7e0 add r10, r7, r3
 *   @0xdb7e4 str r5, [r8, #0x30]
 *   @0xdb7e8 mov r1, #0
 *   @0xdb7ec ldr r3, [r0, #0x8]
 *   @0xdb7f0 mov r0, r8
 *   @0xdb7f4 str r1, [r8, #0x38]
 *   @0xdb7f8 mov r1, #5
 *   @0xdb7fc blx r3
 *   @0xdb800 cmp r7, r10
 *   @0xdb804 bge 0xdb844 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x138>
 *   @0xdb808 cmp r9, #0
 *   @0xdb80c ble 0xdb838 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x12c>
 *   @0xdb810 mov r4, #0
 *   @0xdb814 ldr r0, [r6, #0x4]
 *   @0xdb818 mov r1, r8
 *   @0xdb81c ldr r3, [r6]
 *   @0xdb820 mla r0, r0, r4, r7
 *   @0xdb824 add r4, r4, #1
 *   @0xdb828 add r0, r3, r0, lsl #4
 *   @0xdb82c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdb830 cmp r4, r9
 *   @0xdb834 bne 0xdb814 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x108>
 *   @0xdb838 add r7, r7, #1
 *   @0xdb83c cmp r7, r10
 *   @0xdb840 bne 0xdb808 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0xfc>
 *   @0xdb844 add sp, sp, #20
 *   @0xdb848 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xdb84c mul r2, r9, r3
 *   @0xdb850 cmp r2, #400
 *   @0xdb854 movle r7, r11
 *   @0xdb858 ble 0xdb7d4 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0xc8>
 *   @0xdb85c ldr r3, [r8]
 *   @0xdb860 mov r2, r10
 *   @0xdb864 str r11, [r8, #0x2c]
 *   @0xdb868 mov r0, r8
 *   @0xdb86c str r11, [r8, #0x30]
 *   @0xdb870 mov r1, #5
 *   @0xdb874 str r11, [r8, #0x38]
 *   @0xdb878 ldr r3, [r3, #0x8]
 *   @0xdb87c blx r3
 *   @0xdb880 add sp, sp, #20
 *   @0xdb884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xdb888 mov r2, r8
 *   @0xdb88c mov r1, #0
 *   @0xdb890 ldr r0, [r2], #44
 *   @0xdb894 movt r1, #0xffe0
 *   @0xdb898 movw r3, #0xffff
 *   @0xdb89c str r1, [r8, #0x2c]
 *   @0xdb8a0 movt r3, #0x41ef
 *   @0xdb8a4 mov r1, #0
 *   @0xdb8a8 str r3, [r8, #0x30]
 *   @0xdb8ac ldr r3, [r0, #0x8]
 *   @0xdb8b0 mov r0, r8
 *   @0xdb8b4 str r1, [r8, #0x38]
 *   @0xdb8b8 mov r1, #5
 *   @0xdb8bc blx r3
 *   @0xdb8c0 add sp, sp, #20
 *   @0xdb8c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §4/70 F_DsMapSecureSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb004  size 444  111 条（0xfb004..0xfb1c0）
 * @func 0xfb004 0xfb1c0  size 444  111 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×7 / MemoryManager::Free(void const*)×4 / YYGetInt32(RValue const*, int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65bc×2 / anon_fae18 / DSMapToJSON(int, char**) / base64_encode(char const*, unsigned int, char*)
 * 字段偏移 top8: 0x4×5 / 0x38×1 / 0xc×1 / 0x-14×1 / 0x11c×1 / 0x14×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb004 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfb008 sub sp, sp, #24
 *   @0xfb00c mov r4, #0
 *   @0xfb010 mov r8, r0
 *   @0xfb014 ldr r5, [sp, #0x38]
 *   @0xfb018 mov r1, r4
 *   @0xfb01c str r4, [r0, #0xc]
 *   @0xfb020 str r4, [r0]
 *   @0xfb024 str r4, [r0, #0x4]
 *   @0xfb028 mov r0, r5
 *   @0xfb02c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfb030 mov r1, #1
 *   @0xfb034 mov r6, r0
 *   @0xfb038 mov r0, r5
 *   @0xfb03c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfb040 mov r5, r0
 *   @0xfb044 bl 0xfae18 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0xfb048 add r1, sp, #24
 *   @0xfb04c str r4, [r1, #-0x14]!
 *   @0xfb050 mov r7, r0
 *   @0xfb054 mov r0, r6
 *   @0xfb058 bl 0x13c1d8 <_Z11DSMapToJSONiPPc>
 *   @0xfb05c ldr r0, [sp, #0x4]
 *   @0xfb060 subs r3, r0, r4
 *   @0xfb064 rsbs r10, r3, #0
 *   @0xfb068 adcs r10, r10, r3
 *   @0xfb06c cmp r10, r4
 *   @0xfb070 bne 0xfb1a4 <_Z23F_DsMapSecureSaveBufferR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0xfb074 bl 0xb6538 <strlen@plt>
 *   @0xfb078 movw r3, #0xaaab
 *   @0xfb07c movt r3, #0xaaaa
 *   @0xfb080 add r0, r0, #1
 *   @0xfb084 lsl r0, r0, #2
 *   @0xfb088 umull r2, r0, r3, r0
 *   @0xfb08c lsr r0, r0, #1
 *   @0xfb090 add r0, r0, #4
 *   @0xfb094 ldr r4, [pc, #0x11c]
 *   @0xfb098 mov r3, #1
 *   @0xfb09c movw r2, #0x6dc
 *   @0xfb0a0 add r4, pc, r4
 *   @0xfb0a4 mov r1, r4
 *   @0xfb0a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfb0ac ldr r9, [sp, #0x4]
 *   @0xfb0b0 mov r6, r0
 *   @0xfb0b4 mov r0, r9
 *   @0xfb0b8 bl 0xb6538 <strlen@plt>
 *   @0xfb0bc mov r2, r6
 *   @0xfb0c0 add r1, r0, #1
 *   @0xfb0c4 mov r0, r9
 *   @0xfb0c8 bl 0x1d1e60 <_Z13base64_encodePKcjPc>
 *   @0xfb0cc mov r0, r7
 *   @0xfb0d0 bl 0xb6538 <strlen@plt>
 *   @0xfb0d4 mov r9, r0
 *   @0xfb0d8 mov r0, r6
 *   @0xfb0dc bl 0xb6538 <strlen@plt>
 *   @0xfb0e0 mov r3, #1
 *   @0xfb0e4 mov r1, r4
 *   @0xfb0e8 movw r2, #0x6e1
 *   @0xfb0ec add r0, r0, r9
 *   @0xfb0f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfb0f4 mov r9, r0
 *   @0xfb0f8 mov r0, r7
 *   @0xfb0fc bl 0xb6538 <strlen@plt>
 *   @0xfb100 mov r1, r7
 *   @0xfb104 mov r2, r0
 *   @0xfb108 mov r0, r9
 *   @0xfb10c bl 0xb65bc <memcpy@plt>
 *   @0xfb110 mov r0, r7
 *   @0xfb114 bl 0xb6538 <strlen@plt>
 *   @0xfb118 mov r4, r0
 *   @0xfb11c mov r0, r6
 *   @0xfb120 bl 0xb6538 <strlen@plt>
 *   @0xfb124 mov r1, r6
 *   @0xfb128 mov r2, r0
 *   @0xfb12c add r0, r9, r4
 *   @0xfb130 add r4, sp, #8
 *   @0xfb134 bl 0xb65bc <memcpy@plt>
 *   @0xfb138 mov r1, r9
 *   @0xfb13c mov r3, #1
 *   @0xfb140 mov r0, r4
 *   @0xfb144 str r3, [sp, #0x14]
 *   @0xfb148 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xfb14c mov r2, r4
 *   @0xfb150 mov r0, r5
 *   @0xfb154 mov r1, #13
 *   @0xfb158 bl 0xc7064 <_Z18YYGML_BUFFER_WriteiiRK8YYRValue>
 *   @0xfb15c vmov s15, r0
 *   @0xfb160 mov r0, r7
 *   @0xfb164 vcvt.f64.s32 d7, s15
 *   @0xfb168 vmov r4, r5, d7
 *   @0xfb16c vmov r2, s14
 *   @0xfb170 mov r3, r5
 *   @0xfb174 stm r8, {r2, r3}
 *   @0xfb178 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb17c cmp r10, #0
 *   @0xfb180 bne 0xfb18c <_Z23F_DsMapSecureSaveBufferR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0xfb184 ldr r0, [sp, #0x4]
 *   @0xfb188 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb18c mov r0, r6
 *   @0xfb190 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb194 mov r0, r9
 *   @0xfb198 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb19c add sp, sp, #24
 *   @0xfb1a0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfb1a4 ldr r3, [pc, #0x10]
 *   @0xfb1a8 mov r0, #9
 *   @0xfb1ac add r3, pc, r3
 *   @0xfb1b0 str r3, [sp, #0x4]
 *   @0xfb1b4 b 0xfb094 <_Z23F_DsMapSecureSaveBufferR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xfb1b8 .word 0x0023cafc
 *   @0xfb1bc eoreq r12, r3, r8, asr #20
 *
 * ══ §5/70 F_DebugEvent(RValue&, CInstance*, CInstance*, int, RValue*)  0x114bf4  size 444  104 条（0x114bf4..0x114db0）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x114bf4 0x114db0  size 444  104 条
 * 部分覆盖: 本节 104/111 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x114c4c→0x47b23b, 0x114c5c→0x5428e8, 0x114c70→0x544c38, 0x114ccc→0x47f294, 0x114ce8→0x47b23b, 0x114d30→0x3f20a8, 0x114d44→0x47f294, 0x114d6c→0x3f20a8
 * 调用序列: 0xb65e0×7 / YYGetString(RValue const*, int) / memLogEvent(char const*, ...) / MemoryManager::DumpMemory(__sFILE*)
 * 字段偏移 top8: 0x50×2 / 0x10×1 / 0x170×1 / 0x164×1 / 0x14c×1 / 0x134×1 / 0x128×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114bf4 push {r3, r4, r5, lr}
 *   @0x114bf8 mov r1, #0
 *   @0x114bfc ldr r0, [sp, #0x10]
 *   @0x114c00 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x114c04 ldr r4, [pc, #0x170]
 *   @0x114c08 add r4, pc, r4
 *   @0x114c0c mov r5, r0
 *   @0x114c10 bl 0x27ba28 <_Z11memLogEventPKcz>
 *   @0x114c14 ldr r1, [pc, #0x164]
 *   @0x114c18 mov r0, r5
 *   @0x114c1c mov r2, #6
 *   @0x114c20 add r1, pc, r1
 *   @0x114c24 bl 0xb65e0 <strncmp@plt>
 *   @0x114c28 cmp r0, #0
 *   @0x114c2c beq 0x114ce0 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x114c30 ldr r1, [pc, #0x14c]
 *   @0x114c34 mov r0, r5
 *   @0x114c38 mov r2, #9
 *   @0x114c3c add r1, pc, r1
 *   @0x114c40 bl 0xb65e0 <strncmp@plt>
 *   @0x114c44 cmp r0, #0
 *   @0x114c48 bne 0x114c94 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x114c4c ldr r3, [pc, #0x134]
 *   @0x114c50 mov r2, #1
 *   @0x114c70 ldr r3, [pc, #0x118]
 *   @0x114c74 ldr r3, [r4, r3]
 *   @0x114c78 ldr r3, [r3]
 *   @0x114c7c cmp r3, #0
 *   @0x114c80 popne {r3, r4, r5, pc}
 *   @0x114c84 mov r1, r5
 *   @0x114c88 mov r0, #1
 *   @0x114c8c pop {r3, r4, r5, lr}
 *   @0x114c90 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x114c94 ldr r1, [pc, #0xf8]
 *   @0x114c98 mov r0, r5
 *   @0x114c9c mov r2, #10
 *   @0x114ca0 add r1, pc, r1
 *   @0x114ca4 bl 0xb65e0 <strncmp@plt>
 *   @0x114ca8 cmp r0, #0
 *   @0x114cac beq 0x114ce8 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x114cb0 ldr r1, [pc, #0xe0]
 *   @0x114cb4 mov r0, r5
 *   @0x114cb8 mov r2, #15
 *   @0x114cbc add r1, pc, r1
 *   @0x114cc0 bl 0xb65e0 <strncmp@plt>
 *   @0x114cc4 cmp r0, #0
 *   @0x114cc8 bne 0x114cf8 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x114ccc ldr r3, [pc, #0xc8]
 *   @0x114cd0 mov r2, #1
 *   @0x114cd4 ldr r3, [r4, r3]
 *   @0x114cd8 strb r2, [r3]
 *   @0x114cdc b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x114ce0 bl 0x27c28c <_ZN13MemoryManager10DumpMemoryEP7__sFILE>
 *   @0x114ce4 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x114ce8 ldr r3, [pc, #0x98]
 *   @0x114cec ldr r3, [r4, r3]
 *   @0x114cf0 strb r0, [r3]
 *   @0x114cf4 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x114cf8 ldr r1, [pc, #0xa0]
 *   @0x114cfc mov r0, r5
 *   @0x114d00 mov r2, #14
 *   @0x114d04 add r1, pc, r1
 *   @0x114d08 bl 0xb65e0 <strncmp@plt>
 *   @0x114d0c cmp r0, #0
 *   @0x114d10 beq 0x114d44 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x114d14 ldr r1, [pc, #0x88]
 *   @0x114d18 mov r0, r5
 *   @0x114d1c mov r2, #15
 *   @0x114d20 add r1, pc, r1
 *   @0x114d24 bl 0xb65e0 <strncmp@plt>
 *   @0x114d28 cmp r0, #0
 *   @0x114d2c bne 0x114d54 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x114d30 ldr r3, [pc, #0x70]
 *   @0x114d34 mov r2, #1
 *   @0x114d38 ldr r3, [r4, r3]
 *   @0x114d3c strb r2, [r3]
 *   @0x114d40 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x114d44 ldr r3, [pc, #0x50]
 *   @0x114d48 ldr r3, [r4, r3]
 *   @0x114d4c strb r0, [r3]
 *   @0x114d50 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x114d54 ldr r1, [pc, #0x50]
 *   @0x114d58 mov r0, r5
 *   @0x114d5c mov r2, #15
 *   @0x114d60 add r1, pc, r1
 *   @0x114d64 bl 0xb65e0 <strncmp@plt>
 *   @0x114d68 cmp r0, #0
 *   @0x114d6c ldreq r3, [pc, #0x34]
 *   @0x114d70 ldreq r3, [r4, r3]
 *   @0x114d74 strbeq r0, [r3]
 *   @0x114d78 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x114d7c eoreq sp, sp, r8, asr #32
 *   @0x114d80 .word 0x00224ad4
 *   @0x114d84 eoreq r4, r2, r4, asr #21
 *   @0x114d88 .word 0xffffc7cc
 *   @0x114d8c .word 0xffffbcd4
 *   @0x114d90 .word 0xffffc7d0
 *   @0x114d94 eoreq r4, r2, r12, ror #20
 *   @0x114d98 eoreq r4, r2, r12, asr r10
 *   @0x114d9c .word 0xffffc0fc
 *   @0x114da0 eoreq r4, r2, r4, lsr #20
 *   @0x114da4 eoreq r4, r2, r8, lsl r10
 *   @0x114da8 .word 0xffffc7d4
 *   @0x114dac eoreq r4, r2, r8, ror #19
 *
 * ══ §6/70 TimeLine_Init()  0x1f25b4  size 444  111 条（0x1f25b4..0x1f2770）
 * @func 0x1f25b4 0x1f2770  size 444  111 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×5 / operator delete(void*)×2 / operator new(unsigned int)×2 / TimeLine_Init()+0xa4 / TimeLine_Init()+0x3c / TimeLine_Init()+0x14c / MemoryManager::IsAllocated(void const*) / TimeLine_Init()+0x10c
 * 字段偏移 top8: 0x4×17 / 0x2×3 / 0x1a8×1 / 0xdc×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f25b4 ldr r3, [pc, #0x1a8]
 *   @0x1f25b8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f25bc ldr r6, [pc, r3]
 *   @0x1f25c0 cmp r6, #0
 *   @0x1f25c4 beq 0x1f2678 <_Z13TimeLine_Initv+0xc4>
 *   @0x1f25c8 ldr r12, [r6]
 *   @0x1f25cc cmp r12, #0
 *   @0x1f25d0 beq 0x1f2670 <_Z13TimeLine_Initv+0xbc>
 *   @0x1f25d4 ldr r5, [r6, #0x4]
 *   @0x1f25d8 cmp r5, #0
 *   @0x1f25dc beq 0x1f2754 <_Z13TimeLine_Initv+0x1a0>
 *   @0x1f25e0 cmp r12, #0
 *   @0x1f25e4 ble 0x1f2658 <_Z13TimeLine_Initv+0xa4>
 *   @0x1f25e8 mov r4, #0
 *   @0x1f25ec mov r8, r4
 *   @0x1f25f0 ldr r1, [r5]
 *   @0x1f25f4 movw r3, #0xfeee
 *   @0x1f25f8 movt r3, #0xfeee
 *   @0x1f25fc movw r2, #0xfeee
 *   @0x1f2600 cmp r1, r3
 *   @0x1f2604 movt r2, #0xfeee
 *   @0x1f2608 lsl r7, r4, #2
 *   @0x1f260c beq 0x1f264c <_Z13TimeLine_Initv+0x98>
 *   @0x1f2610 ldr r3, [r5, r4, lsl #2]
 *   @0x1f2614 add r1, r5, r7
 *   @0x1f2618 cmp r3, #0
 *   @0x1f261c mov r0, r3
 *   @0x1f2620 beq 0x1f264c <_Z13TimeLine_Initv+0x98>
 *   @0x1f2624 ldr r3, [r3]
 *   @0x1f2628 cmp r3, r2
 *   @0x1f262c beq 0x1f2644 <_Z13TimeLine_Initv+0x90>
 *   @0x1f2630 ldr r3, [r3, #0x4]
 *   @0x1f2634 blx r3
 *   @0x1f2638 ldr r1, [r6, #0x4]
 *   @0x1f263c ldr r12, [r6]
 *   @0x1f2640 add r1, r1, r7
 *   @0x1f2644 str r8, [r1]
 *   @0x1f2648 ldr r5, [r6, #0x4]
 *   @0x1f264c add r4, r4, #1
 *   @0x1f2650 cmp r4, r12
 *   @0x1f2654 blt 0x1f25f0 <_Z13TimeLine_Initv+0x3c>
 *   @0x1f2658 mov r0, r5
 *   @0x1f265c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2660 mov r3, #0
 *   @0x1f2664 str r3, [r6, #0x4]
 *   @0x1f2668 mov r3, #0
 *   @0x1f266c str r3, [r6]
 *   @0x1f2670 mov r0, r6
 *   @0x1f2674 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f2678 mov r0, #8
 *   @0x1f267c mov r4, #0
 *   @0x1f2680 bl 0x27c524 <_Znwj>
 *   @0x1f2684 ldr r3, [pc, #0xdc]
 *   @0x1f2688 add r3, pc, r3
 *   @0x1f268c ldr r5, [r3, #0x4]
 *   @0x1f2690 cmp r5, r4
 *   @0x1f2694 str r4, [r0]
 *   @0x1f2698 str r4, [r0, #0x4]
 *   @0x1f269c str r0, [r3]
 *   @0x1f26a0 beq 0x1f2720 <_Z13TimeLine_Initv+0x16c>
 *   @0x1f26a4 ldr r6, [r5, #0x4]
 *   @0x1f26a8 cmp r6, r4
 *   @0x1f26ac beq 0x1f2744 <_Z13TimeLine_Initv+0x190>
 *   @0x1f26b0 ldr r3, [r5]
 *   @0x1f26b4 cmp r3, r4
 *   @0x1f26b8 ble 0x1f2700 <_Z13TimeLine_Initv+0x14c>
 *   @0x1f26bc mov r7, r4
 *   @0x1f26c0 ldr r3, [r5, #0x4]
 *   @0x1f26c4 lsl r6, r4, #2
 *   @0x1f26c8 ldr r0, [r3, r4, lsl #2]
 *   @0x1f26cc bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x1f26d0 cmp r0, #0
 *   @0x1f26d4 beq 0x1f26e4 <_Z13TimeLine_Initv+0x130>
 *   @0x1f26d8 ldr r3, [r5, #0x4]
 *   @0x1f26dc ldr r0, [r3, r4, lsl #2]
 *   @0x1f26e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f26e4 ldr r2, [r5]
 *   @0x1f26e8 add r4, r4, #1
 *   @0x1f26ec ldr r3, [r5, #0x4]
 *   @0x1f26f0 cmp r4, r2
 *   @0x1f26f4 str r7, [r3, r6]
 *   @0x1f26f8 blt 0x1f26c0 <_Z13TimeLine_Initv+0x10c>
 *   @0x1f26fc ldr r6, [r5, #0x4]
 *   @0x1f2700 mov r0, r6
 *   @0x1f2704 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2708 mov r3, #0
 *   @0x1f270c str r3, [r5, #0x4]
 *   @0x1f2710 mov r3, #0
 *   @0x1f2714 mov r0, r5
 *   @0x1f2718 str r3, [r5]
 *   @0x1f271c bl 0x27d1d0 <_ZdlPv>
 *   @0x1f2720 mov r0, #8
 *   @0x1f2724 bl 0x27c524 <_Znwj>
 *   @0x1f2728 ldr r2, [pc, #0x3c]
 *   @0x1f272c mov r3, #0
 *   @0x1f2730 add r2, pc, r2
 *   @0x1f2734 str r3, [r0]
 *   @0x1f2738 str r3, [r0, #0x4]
 *   @0x1f273c str r0, [r2, #0x4]
 *   @0x1f2740 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f2744 mov r0, r6
 *   @0x1f2748 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f274c str r6, [r5, #0x4]
 *   @0x1f2750 b 0x1f2710 <_Z13TimeLine_Initv+0x15c>
 *   @0x1f2754 mov r0, r5
 *   @0x1f2758 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f275c str r5, [r6, #0x4]
 *   @0x1f2760 b 0x1f2668 <_Z13TimeLine_Initv+0xb4>
 *   @0x1f2764 subseq r0, r6, r0, lsr r11
 *   @0x1f2768 subseq r0, r6, r4, ror #20
 *   @0x1f276c ldrheq r0, [r6], #-156
 *
 * ══ §7/70 Audio_GetListenerData(int)  0x2167dc  size 444  111 条（0x2167dc..0x216998）
 * @func 0x2167dc 0x216998  size 444  111 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...)
 * 字段偏移 top8: 0x138×2 / 0x12c×2 / 0x100×2 / 0x170×1 / 0x160×1 / 0x4×1 / 0x148×1 / 0x10×1
 * VFP 指令 36 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2167dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2167e0 subs r4, r0, #0
 *   @0x2167e4 sub sp, sp, #188
 *   @0x2167e8 bne 0x21695c <_Z21Audio_GetListenerDatai+0x180>
 *   @0x2167ec ldr r3, [pc, #0x170]
 *   @0x2167f0 ldr r3, [pc, r3]
 *   @0x2167f4 ldr r12, [r3]
 *   @0x2167f8 cmp r12, #0
 *   @0x2167fc beq 0x21695c <_Z21Audio_GetListenerDatai+0x180>
 *   @0x216800 ldr lr, [pc, #0x160]
 *   @0x216804 vldr s15, [r12]
 *   @0x216808 str r4, [sp]
 *   @0x21680c vcvt.f64.f32 d6, s15
 *   @0x216810 add lr, pc, lr
 *   @0x216814 str lr, [sp, #0x4]
 *   @0x216818 vldr s14, [r12, #4]
 *   @0x21681c ldr r1, [pc, #0x148]
 *   @0x216820 str r4, [sp, #0x10]
 *   @0x216824 mov r0, #12
 *   @0x216828 add r1, pc, r1
 *   @0x21682c str r1, [sp, #0x14]
 *   @0x216830 ldr r1, [pc, #0x138]
 *   @0x216834 ldr r11, [pc, #0x138]
 *   @0x216838 vcvt.f64.f32 d7, s14
 *   @0x21683c add r1, pc, r1
 *   @0x216840 add r11, pc, r11
 *   @0x216844 ldr r10, [pc, #0x12c]
 *   @0x216848 ldr r9, [pc, #0x12c]
 *   @0x21684c add r10, pc, r10
 *   @0x216850 ldr r8, [pc, #0x128]
 *   @0x216854 add r9, pc, r9
 *   @0x216858 ldr r7, [pc, #0x124]
 *   @0x21685c add r8, pc, r8
 *   @0x216860 ldr r6, [pc, #0x120]
 *   @0x216864 add r7, pc, r7
 *   @0x216868 ldr r5, [pc, #0x11c]
 *   @0x21686c vstr d7, [sp, #8]
 *   @0x216870 vldr s14, [r12, #8]
 *   @0x216874 vcvt.f64.f32 d7, s14
 *   @0x216878 str r1, [sp, #0x24]
 *   @0x21687c str r4, [sp, #0x20]
 *   @0x216880 add r6, pc, r6
 *   @0x216884 add r5, pc, r5
 *   @0x216888 ldr lr, [pc, #0x100]
 *   @0x21688c ldr r1, [pc, #0x100]
 *   @0x216890 add lr, pc, lr
 *   @0x216894 vmov r2, r3, d6
 *   @0x216898 add r1, pc, r1
 *   @0x21689c vstr d7, [sp, #24]
 *   @0x2168a0 vldr s14, [r12, #12]
 *   @0x2168a4 vcvt.f64.f32 d7, s14
 *   @0x2168a8 str r4, [sp, #0x30]
 *   @0x2168ac str r11, [sp, #0x34]
 *   @0x2168b0 vstr d7, [sp, #40]
 *   @0x2168b4 vldr s14, [r12, #16]
 *   @0x2168b8 vcvt.f64.f32 d7, s14
 *   @0x2168bc str r4, [sp, #0x40]
 *   @0x2168c0 str r10, [sp, #0x44]
 *   @0x2168c4 vstr d7, [sp, #56]
 *   @0x2168c8 vldr s14, [r12, #20]
 *   @0x2168cc vcvt.f64.f32 d7, s14
 *   @0x2168d0 str r4, [sp, #0x50]
 *   @0x2168d4 str r9, [sp, #0x54]
 *   @0x2168d8 vstr d7, [sp, #72]
 *   @0x2168dc vldr s14, [r12, #24]
 *   @0x2168e0 vcvt.f64.f32 d7, s14
 *   @0x2168e4 str r4, [sp, #0x60]
 *   @0x2168e8 str r8, [sp, #0x64]
 *   @0x2168ec vstr d7, [sp, #88]
 *   @0x2168f0 vldr s14, [r12, #28]
 *   @0x2168f4 vcvt.f64.f32 d7, s14
 *   @0x2168f8 str r4, [sp, #0x70]
 *   @0x2168fc str r7, [sp, #0x74]
 *   @0x216900 vstr d7, [sp, #104]
 *   @0x216904 vldr s14, [r12, #32]
 *   @0x216908 vcvt.f64.f32 d7, s14
 *   @0x21690c vstr d7, [sp, #120]
 *   @0x216910 str r4, [sp, #0x80]
 *   @0x216914 str r6, [sp, #0x84]
 *   @0x216918 vldr s14, [r12, #36]
 *   @0x21691c vcvt.f64.f32 d7, s14
 *   @0x216920 str r4, [sp, #0x90]
 *   @0x216924 str r5, [sp, #0x94]
 *   @0x216928 vstr d7, [sp, #136]
 *   @0x21692c vldr s14, [r12, #40]
 *   @0x216930 vcvt.f64.f32 d7, s14
 *   @0x216934 str r4, [sp, #0xa0]
 *   @0x216938 str lr, [sp, #0xa4]
 *   @0x21693c vstr d7, [sp, #152]
 *   @0x216940 vldr s14, [r12, #44]
 *   @0x216944 vcvt.f64.f32 d7, s14
 *   @0x216948 str r4, [sp, #0xb0]
 *   @0x21694c vstr d7, [sp, #168]
 *   @0x216950 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x216954 add sp, sp, #188
 *   @0x216958 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21695c mvn r0, #0
 *   @0x216960 b 0x216954 <_Z21Audio_GetListenerDatai+0x178>
 *   @0x216964 andseq r10, sp, r12, ror #23
 *   @0x216968 andseq r10, r1, r8, rrx
 *   @0x21696c andseq sp, r3, r0, lsr #7
 *   @0x216970 mulseq r3, r0, r3
 *   @0x216974 mulseq r3, r0, r3
 *   @0x216978 andseq sp, r3, r8, lsl #7
 *   @0x21697c andseq sp, r3, r4, lsl #7
 *   @0x216980 andseq sp, r3, r8, lsl #7
 *   @0x216984 andseq sp, r3, r12, lsl #7
 *   @0x216988 andseq sp, r3, r12, ror r3
 *   @0x21698c andseq sp, r3, r0, lsl #7
 *   @0x216990 andseq sp, r3, r12, ror r3
 *   @0x216994 ldrsbeq r9, [r1], -r12
 *
 * ══ §8/70 F_BackgroundGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*)  0x1211b4  size 440  110 条（0x1211b4..0x12136c）
 * @func 0x1211b4 0x12136c  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateArray(RValue*, int, ...)×2 / YYGetInt32(RValue const*, int) / Background_Exists(int) / Background_Data(int) / CBackground::GetTexture() / F_BackgroundGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*)+0x50
 * 字段偏移 top8: 0x48×1 / 0x16c×1 / 0x118×1 / 0x4×1 / 0x2×1
 * VFP 指令 45 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1211b4 push {r4, r5, r6, lr}
 *   @0x1211b8 sub sp, sp, #56
 *   @0x1211bc mov r1, #0
 *   @0x1211c0 mov r6, r0
 *   @0x1211c4 ldr r0, [sp, #0x48]
 *   @0x1211c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1211cc mov r4, r0
 *   @0x1211d0 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x1211d4 subs r1, r0, #0
 *   @0x1211d8 beq 0x121248 <_Z21F_BackgroundGetBaseUVR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x1211dc mov r0, r4
 *   @0x1211e0 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1211e4 bl 0xc1e8c <_ZN11CBackground10GetTextureEv>
 *   @0x1211e8 subs r12, r0, #0
 *   @0x1211ec blt 0x121204 <_Z21F_BackgroundGetBaseUVR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x1211f0 ldr r3, [pc, #0x16c]
 *   @0x1211f4 ldr r3, [pc, r3]
 *   @0x1211f8 ldr r2, [r3]
 *   @0x1211fc cmp r12, r2
 *   @0x121200 bgt 0x12125c <_Z21F_BackgroundGetBaseUVR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x121204 mov r4, #0
 *   @0x121208 mov r2, #0
 *   @0x12120c mov r3, #0
 *   @0x121210 mov r0, r6
 *   @0x121214 mov r1, #8
 *   @0x121218 strd r2, r3, [sp]
 *   @0x12121c strd r2, r3, [sp, #24]
 *   @0x121220 mov r5, #0
 *   @0x121224 strd r2, r3, [sp, #32]
 *   @0x121228 movt r5, #0x3ff0
 *   @0x12122c strd r4, r5, [sp, #8]
 *   @0x121230 strd r4, r5, [sp, #16]
 *   @0x121234 strd r4, r5, [sp, #40]
 *   @0x121238 strd r4, r5, [sp, #48]
 *   @0x12123c bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x121240 add sp, sp, #56
 *   @0x121244 pop {r4, r5, r6, pc}
 *   @0x121248 ldr r0, [pc, #0x118]
 *   @0x12124c add r0, pc, r0
 *   @0x121250 add sp, sp, #56
 *   @0x121254 pop {r4, r5, r6, lr}
 *   @0x121258 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12125c ldrsh r4, [r12, #20]
 *   @0x121260 vmov.f32 s13, #1.000000e+00
 *   @0x121264 ldr r3, [r3, #0x4]
 *   @0x121268 mov r0, r6
 *   @0x12126c ldrsh r2, [r12, #2]
 *   @0x121270 mov r1, #8
 *   @0x121274 ldrsh lr, [r12]
 *   @0x121278 ldr r3, [r3, r4, lsl #2]
 *   @0x12127c vmov s12, r2
 *   @0x121280 ldr r3, [r3]
 *   @0x121284 vldr s15, [r3, #8]
 *   @0x121288 vldr s9, [r3, #4]
 *   @0x12128c vcvt.f32.s32 s15, s15
 *   @0x121290 vdiv.f32 s15, s13, s15
 *   @0x121294 vcvt.f32.s32 s9, s9
 *   @0x121298 vcvt.f32.s32 s10, s12
 *   @0x12129c vdiv.f32 s9, s13, s9
 *   @0x1212a0 vmov s13, lr
 *   @0x1212a4 vmul.f32 s10, s10, s15
 *   @0x1212a8 vcvt.f64.f32 d5, s10
 *   @0x1212ac vstr d5, [sp]
 *   @0x1212b0 ldrsh r3, [r12, #12]
 *   @0x1212b4 vcvt.f32.s32 s14, s13
 *   @0x1212b8 add r3, lr, r3
 *   @0x1212bc vmov s12, r3
 *   @0x1212c0 vcvt.f32.s32 s12, s12
 *   @0x1212c4 vmul.f32 s12, s12, s9
 *   @0x1212c8 vcvt.f64.f32 d6, s12
 *   @0x1212cc vstr d6, [sp, #8]
 *   @0x1212d0 ldrsh r3, [r12, #14]
 *   @0x1212d4 vmul.f32 s9, s14, s9
 *   @0x1212d8 add r3, r2, r3
 *   @0x1212dc vmov s14, r3
 *   @0x1212e0 vcvt.f32.s32 s14, s14
 *   @0x1212e4 vmul.f32 s14, s14, s15
 *   @0x1212e8 vcvt.f64.f32 d7, s14
 *   @0x1212ec vstr d7, [sp, #16]
 *   @0x1212f0 ldrsh r3, [r12, #8]
 *   @0x1212f4 vcvt.f64.f32 d6, s9
 *   @0x1212f8 vmov s14, r3
 *   @0x1212fc vcvt.f64.s32 d7, s14
 *   @0x121300 vmov r2, r3, d6
 *   @0x121304 vstr d7, [sp, #24]
 *   @0x121308 ldrsh lr, [r12, #10]
 *   @0x12130c vmov s14, lr
 *   @0x121310 vcvt.f64.s32 d7, s14
 *   @0x121314 vstr d7, [sp, #32]
 *   @0x121318 ldrsh lr, [r12, #4]
 *   @0x12131c vmov s12, lr
 *   @0x121320 ldrsh lr, [r12, #16]
 *   @0x121324 vcvt.f64.s32 d6, s12
 *   @0x121328 vmov s14, lr
 *   @0x12132c vcvt.f64.s32 d7, s14
 *   @0x121330 vdiv.f64 d7, d6, d7
 *   @0x121334 vstr d7, [sp, #40]
 *   @0x121338 ldrsh lr, [r12, #6]
 *   @0x12133c ldrsh r12, [r12, #18]
 *   @0x121340 vmov s12, lr
 *   @0x121344 vmov s14, r12
 *   @0x121348 vcvt.f64.s32 d6, s12
 *   @0x12134c vcvt.f64.s32 d7, s14
 *   @0x121350 vdiv.f64 d7, d6, d7
 *   @0x121354 vstr d7, [sp, #48]
 *   @0x121358 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x12135c add sp, sp, #56
 *   @0x121360 pop {r4, r5, r6, pc}
 *   @0x121364 eoreq r12, r12, r8, lsr #14
 *   @0x121368 eoreq r8, r1, r4, lsr #30
 *
 * ══ §9/70 F_BackgroundPrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f9f8  size 440  110 条（0x12f9f8..0x12fbb0）
 * @func 0x12f9f8 0x12fbb0  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x12fa58→0x3eb70c, 0x12fa7c→0x3eb70c, 0x12fad8→0x3eb70c, 0x12fb10→0x48ffec, 0x12fb70→0x3eb70c
 * 调用序列: F_BackgroundPrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*)+0x168×2 / Graphics::PrefetchTexture(void*)×2 / YYGetInt32(RValue const*, int) / Background_Data(int) / CBackground::GetTexture() / F_BackgroundPrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*)+0x14c
 * 字段偏移 top8: 0x4×7 / 0xc×6 / 0x13c×2 / 0x108×2 / 0x2×2 / 0x20×1 / 0x17c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f9f8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12f9fc mov r4, #0
 *   @0x12fa00 ldr r2, [sp, #0x20]
 *   @0x12fa04 mov r3, r4
 *   @0x12fa08 str r4, [r0, #0xc]
 *   @0x12fa0c movt r3, #0xbff0
 *   @0x12fa10 ldr r5, [pc, #0x17c]
 *   @0x12fa14 mov r6, r0
 *   @0x12fa18 ldr r1, [r2, #0xc]
 *   @0x12fa1c add r5, pc, r5
 *   @0x12fa20 str r4, [r0]
 *   @0x12fa24 cmp r1, #2
 *   @0x12fa28 str r3, [r0, #0x4]
 *   @0x12fa2c bne 0x12fa78 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12fa30 ldr r7, [r2]
 *   @0x12fa34 cmp r7, #0
 *   @0x12fa38 beq 0x12fa54 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x12fa3c ldr r3, [r7, #0x4]
 *   @0x12fa40 cmp r3, #0
 *   @0x12fa44 beq 0x12fa54 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x12fa48 ldr r2, [r7, #0x10]
 *   @0x12fa4c cmp r2, #1
 *   @0x12fa50 beq 0x12fa88 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x12fa54 ldr r1, [pc, #0x13c]
 *   @0x12fa58 ldr r3, [pc, #0x13c]
 *   @0x12fa5c add r1, pc, r1
 *   @0x12fa60 ldr r3, [r5, r3]
 *   @0x12fa64 ldr r0, [r3]
 *   @0x12fa68 ldr r3, [r0]
 *   @0x12fa6c ldr r3, [r3, #0xc]
 *   @0x12fa70 blx r3
 *   @0x12fa74 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x12fa78 ldr r1, [pc, #0x120]
 *   @0x12fa7c ldr r3, [pc, #0x118]
 *   @0x12fa80 add r1, pc, r1
 *   @0x12fa84 b 0x12fa60 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x12fa88 ldr r2, [r3]
 *   @0x12fa8c cmp r2, #0
 *   @0x12fa90 ble 0x12fb60 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x12fa94 ldr r9, [pc, #0x108]
 *   @0x12fa98 ldr r8, [pc, #0x108]
 *   @0x12fa9c add r9, pc, r9
 *   @0x12faa0 add r8, pc, r8
 *   @0x12faa4 b 0x12fad0 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x12faa8 ldr r3, [r5, r12]
 *   @0x12faac ldr r0, [r3]
 *   @0x12fab0 ldr r3, [r0]
 *   @0x12fab4 ldr r3, [r3, #0xc]
 *   @0x12fab8 blx r3
 *   @0x12fabc ldr r3, [r7, #0x4]
 *   @0x12fac0 add r4, r4, #1
 *   @0x12fac4 ldr r2, [r3]
 *   @0x12fac8 cmp r2, r4
 *   @0x12facc ble 0x12fb60 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x12fad0 ldr r3, [r3, #0x4]
 *   @0x12fad4 mov r1, r8
 *   @0x12fad8 ldr r12, [pc, #0xbc]
 *   @0x12fadc mov r2, r4
 *   @0x12fae0 add r3, r3, r4, lsl #4
 *   @0x12fae4 mov r0, r3
 *   @0x12fae8 ldr r3, [r3, #0xc]
 *   @0x12faec cmp r3, #0
 *   @0x12faf0 bne 0x12faa8 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x12faf4 mov r1, r3
 *   @0x12faf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12fafc mov r10, r0
 *   @0x12fb00 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12fb04 cmp r0, #0
 *   @0x12fb08 beq 0x12fb70 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x12fb0c bl 0xc1e8c <_ZN11CBackground10GetTextureEv>
 *   @0x12fb10 ldr r3, [pc, #0x94]
 *   @0x12fb14 ldr r3, [r5, r3]
 *   @0x12fb18 ldr r2, [r3]
 *   @0x12fb1c cmp r0, r2
 *   @0x12fb20 bls 0x12fb44 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x12fb24 cmn r0, #1
 *   @0x12fb28 beq 0x12fb44 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x12fb2c ldrsh r2, [r0, #20]
 *   @0x12fb30 ldr r3, [r3, #0x4]
 *   @0x12fb34 ldr r3, [r3, r2, lsl #2]
 *   @0x12fb38 ldr r0, [r3]
 *   @0x12fb3c bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv>
 *   @0x12fb40 b 0x12fabc <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x12fb44 ldr r3, [r3, #0x4]
 *   @0x12fb48 ldr r3, [r3, r0, lsl #2]
 *   @0x12fb4c cmp r3, #0
 *   @0x12fb50 beq 0x12fabc <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x12fb54 ldr r0, [r3]
 *   @0x12fb58 bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv>
 *   @0x12fb5c b 0x12fabc <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x12fb60 mov r3, #0
 *   @0x12fb64 str r3, [r6]
 *   @0x12fb68 str r3, [r6, #0x4]
 *   @0x12fb6c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x12fb70 ldr r3, [pc, #0x24]
 *   @0x12fb74 mov r2, r10
 *   @0x12fb78 mov r1, r9
 *   @0x12fb7c ldr r3, [r5, r3]
 *   @0x12fb80 ldr r0, [r3]
 *   @0x12fb84 ldr r3, [r0]
 *   @0x12fb88 ldr r3, [r3, #0xc]
 *   @0x12fb8c blx r3
 *   @0x12fb90 b 0x12fabc <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x12fb94 eoreq r2, r12, r4, lsr r2
 *   @0x12fb98 eoreq sp, r0, r4, asr #31
 *   @0x12fb9c .word 0xffffbac4
 *   @0x12fba0 eoreq sp, r0, r8, asr pc
 *   @0x12fba4 .word 0x0020dff4
 *   @0x12fba8 .word 0x0020dfb4
 *   @0x12fbac .word 0xffffbccc
 *
 * ══ §10/70 F_PhysicsTestOverlap(RValue&, CInstance*, CInstance*, int, RValue*)  0x14cc60  size 440  110 条（0x14cc60..0x14ce18）
 * @func 0x14cc60 0x14ce18  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / WithObjIterator::operator*()×2 / Error_Show_Action(char const*, bool)×2 / YYGetInt32(RValue const*, int) / WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) / WithObjIterator::Next() / CPhysicsWorld::TestOverlap(CInstance*, CInstance*, float, float, float)
 * 字段偏移 top8: 0xb4×4 / 0x4×2 / 0x84×1 / 0x60×1 / 0xc×1 / 0x160×1 / 0x68×1 / 0x69×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14cc60 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x14cc64 vpush {d8, d9}
 *   @0x14cc68 mov r7, r0
 *   @0x14cc6c mov r8, r1
 *   @0x14cc70 mov r0, #0
 *   @0x14cc74 str r0, [r7]
 *   @0x14cc78 sub sp, sp, #48
 *   @0x14cc7c str r0, [r7, #0x4]
 *   @0x14cc80 mov r10, r2
 *   @0x14cc84 ldr r1, [r1, #0x84]
 *   @0x14cc88 ldr r6, [sp, #0x60]
 *   @0x14cc8c cmp r1, r0
 *   @0x14cc90 str r0, [r7, #0xc]
 *   @0x14cc94 beq 0x14cdec <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x14cc98 mov r0, r6
 *   @0x14cc9c mov r1, #3
 *   @0x14cca0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14cca4 ldr r5, [pc, #0x160]
 *   @0x14cca8 ldr r5, [pc, r5]
 *   @0x14ccac ldr r3, [r5]
 *   @0x14ccb0 cmn r0, #1
 *   @0x14ccb4 mov r9, r0
 *   @0x14ccb8 ldreq r9, [r8, #0x78]
 *   @0x14ccbc cmp r3, #0
 *   @0x14ccc0 beq 0x14cdd0 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x14ccc4 ldr r3, [r3, #0xb4]
 *   @0x14ccc8 cmp r3, #0
 *   @0x14cccc beq 0x14cdd0 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x14ccd0 mov r0, r6
 *   @0x14ccd4 mov r1, #0
 *   @0x14ccd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14ccdc ldr r3, [r5]
 *   @0x14cce0 mov r1, #1
 *   @0x14cce4 vldr s16, [pc, #280]
 *   @0x14cce8 add r4, sp, #12
 *   @0x14ccec ldr r3, [r3, #0xb4]
 *   @0x14ccf0 vldr s18, [r3, #96]
 *   @0x14ccf4 vmov s14, r0
 *   @0x14ccf8 mov r0, r6
 *   @0x14ccfc vmul.f32 s18, s14, s18
 *   @0x14cd00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cd04 ldr r3, [r5]
 *   @0x14cd08 mov r1, #2
 *   @0x14cd0c ldr r3, [r3, #0xb4]
 *   @0x14cd10 vldr s17, [r3, #96]
 *   @0x14cd14 vmov s15, r0
 *   @0x14cd18 mov r0, r6
 *   @0x14cd1c vmul.f32 s17, s15, s17
 *   @0x14cd20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cd24 mov r12, #0
 *   @0x14cd28 mov r1, r9
 *   @0x14cd2c mov r3, r10
 *   @0x14cd30 mov r2, r8
 *   @0x14cd34 str r12, [sp]
 *   @0x14cd38 vldr s15, [pc, #200]
 *   @0x14cd3c vmov s14, r0
 *   @0x14cd40 mov r0, r4
 *   @0x14cd44 vmul.f32 s16, s14, s16
 *   @0x14cd48 vdiv.f32 s16, s16, s15
 *   @0x14cd4c bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b>
 *   @0x14cd50 b 0x14cd5c <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x14cd54 mov r0, r4
 *   @0x14cd58 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv>
 *   @0x14cd5c mov r0, r4
 *   @0x14cd60 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x14cd64 cmp r0, #0
 *   @0x14cd68 mov r0, r4
 *   @0x14cd6c beq 0x14cdc4 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x14cd70 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x14cd74 ldrb r3, [r0, #0x68]
 *   @0x14cd78 cmp r3, #0
 *   @0x14cd7c bne 0x14cd54 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x14cd80 ldrb r6, [r0, #0x69]
 *   @0x14cd84 cmp r6, #0
 *   @0x14cd88 bne 0x14cd54 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x14cd8c ldr r12, [r5]
 *   @0x14cd90 mov r2, r0
 *   @0x14cd94 mov r1, r8
 *   @0x14cd98 vmov r3, s18
 *   @0x14cd9c ldr r0, [r12, #0xb4]
 *   @0x14cda0 vstr s17, [sp]
 *   @0x14cda4 vstr s16, [sp, #4]
 *   @0x14cda8 bl 0x239818 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff>
 *   @0x14cdac cmp r0, #0
 *   @0x14cdb0 beq 0x14cd54 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x14cdb4 mov r3, #0
 *   @0x14cdb8 str r6, [r7]
 *   @0x14cdbc movt r3, #0x3ff0
 *   @0x14cdc0 str r3, [r7, #0x4]
 *   @0x14cdc4 add sp, sp, #48
 *   @0x14cdc8 vpop {d8, d9}
 *   @0x14cdcc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x14cdd0 ldr r0, [pc, #0x38]
 *   @0x14cdd4 mov r1, #0
 *   @0x14cdd8 add r0, pc, r0
 *   @0x14cddc bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cde0 add sp, sp, #48
 *   @0x14cde4 vpop {d8, d9}
 *   @0x14cde8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x14cdec ldr r0, [pc, #0x20]
 *   @0x14cdf0 add r0, pc, r0
 *   @0x14cdf4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cdf8 add sp, sp, #48
 *   @0x14cdfc vpop {d8, d9}
 *   @0x14ce00 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x14ce04 ldrdmi r0, r1, [r9], #-251
 *   @0x14ce08 teqmi r4, #0
 *   @0x14ce0c eoreq r0, r10, r0, lsl #25
 *   @0x14ce10 andseq r7, pc, r12, asr #32
 *   @0x14ce14 ldrsheq r6, [pc], -r4
 *
 * ══ §11/70 CBitmap32::CBitmap32(IBitmap*, bool, bool, int)  0x166fd0  size 440  110 条（0x166fd0..0x167188）
 * @func 0x166fd0 0x167188  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / CBitmap32::CBitmap32(IBitmap*, bool, bool, int)+0x178 / 0xb65bc / CBitmap32::RemoveBackground() / CBitmap32::SmoothEdges()
 * 字段偏移 top8: 0x8×6 / 0x4×5 / 0xc×5 / 0x10×3 / 0x14×3 / 0x1a8×1 / 0x34×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x166fd0 ldr r12, [pc, #0x1a8]
 *   @0x166fd4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x166fd8 subs r5, r1, #0
 *   @0x166fdc ldr r12, [pc, r12]
 *   @0x166fe0 mov r1, #0
 *   @0x166fe4 add r12, r12, #8
 *   @0x166fe8 sub sp, sp, #12
 *   @0x166fec mov r4, r0
 *   @0x166ff0 mov r7, r2
 *   @0x166ff4 mov r8, r3
 *   @0x166ff8 str r12, [r0]
 *   @0x166ffc strb r1, [r0, #0x4]
 *   @0x167000 str r1, [r0, #0x8]
 *   @0x167004 str r1, [r0, #0xc]
 *   @0x167008 str r1, [r0, #0x10]
 *   @0x16700c str r1, [r0, #0x14]
 *   @0x167010 beq 0x167058 <_ZN9CBitmap32C2EP7IBitmapbbi+0x88>
 *   @0x167014 ldr r3, [r5]
 *   @0x167018 mov r0, r5
 *   @0x16701c ldr r3, [r3, #0x34]
 *   @0x167020 blx r3
 *   @0x167024 cmp r0, #0
 *   @0x167028 beq 0x167040 <_ZN9CBitmap32C2EP7IBitmapbbi+0x70>
 *   @0x16702c ldr r3, [r5]
 *   @0x167030 mov r0, r5
 *   @0x167034 mov r1, r5
 *   @0x167038 ldr r3, [r3, #0x2c]
 *   @0x16703c blx r3
 *   @0x167040 ldr r3, [r5]
 *   @0x167044 mov r0, r5
 *   @0x167048 ldr r3, [r3, #0x20]
 *   @0x16704c blx r3
 *   @0x167050 cmp r0, #7
 *   @0x167054 beq 0x167064 <_ZN9CBitmap32C2EP7IBitmapbbi+0x94>
 *   @0x167058 mov r0, r4
 *   @0x16705c add sp, sp, #12
 *   @0x167060 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x167064 ldr r3, [r5]
 *   @0x167068 mov r9, #1
 *   @0x16706c mov r0, r5
 *   @0x167070 strb r9, [r4, #0x4]
 *   @0x167074 mov r6, #0
 *   @0x167078 ldr r3, [r3, #0x10]
 *   @0x16707c blx r3
 *   @0x167080 ldr r3, [r5]
 *   @0x167084 ldr r3, [r3, #0x18]
 *   @0x167088 str r0, [r4, #0x8]
 *   @0x16708c mov r0, r5
 *   @0x167090 blx r3
 *   @0x167094 ldr r12, [r4, #0x8]
 *   @0x167098 ldr r1, [pc, #0xe4]
 *   @0x16709c mov r3, r9
 *   @0x1670a0 movw r2, #0x342
 *   @0x1670a4 add r1, pc, r1
 *   @0x1670a8 str r0, [r4, #0xc]
 *   @0x1670ac mul r0, r12, r0
 *   @0x1670b0 lsl r0, r0, #2
 *   @0x1670b4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1670b8 ldr r9, [r4, #0xc]
 *   @0x1670bc ldr lr, [r4, #0x8]
 *   @0x1670c0 add r2, sp, #8
 *   @0x1670c4 ldr r12, [r5]
 *   @0x1670c8 mov r3, sp
 *   @0x1670cc mov r1, r6
 *   @0x1670d0 str r6, [sp]
 *   @0x1670d4 mul lr, r9, lr
 *   @0x1670d8 str r6, [r2, #-0x4]!
 *   @0x1670dc lsl lr, lr, #2
 *   @0x1670e0 str lr, [r4, #0x10]
 *   @0x1670e4 str r0, [r4, #0x14]
 *   @0x1670e8 mov r0, r5
 *   @0x1670ec ldr r12, [r12, #0x24]
 *   @0x1670f0 blx r12
 *   @0x1670f4 ldr r3, [r4, #0xc]
 *   @0x1670f8 ldr r12, [r4, #0x14]
 *   @0x1670fc cmp r3, r6
 *   @0x167100 mov r9, r0
 *   @0x167104 ble 0x167148 <_ZN9CBitmap32C2EP7IBitmapbbi+0x178>
 *   @0x167108 ldr r2, [r4, #0x8]
 *   @0x16710c ldr r1, [sp, #0x4]
 *   @0x167110 lsl r2, r2, #2
 *   @0x167114 mov r0, r12
 *   @0x167118 add r6, r6, #1
 *   @0x16711c bl 0xb65bc <memcpy@plt>
 *   @0x167120 ldr r3, [r4, #0xc]
 *   @0x167124 ldr r2, [r4, #0x8]
 *   @0x167128 ldr r1, [sp, #0x4]
 *   @0x16712c cmp r3, r6
 *   @0x167130 ldr r3, [sp]
 *   @0x167134 lsl r2, r2, #2
 *   @0x167138 add r1, r1, r3
 *   @0x16713c str r1, [sp, #0x4]
 *   @0x167140 add r12, r0, r2
 *   @0x167144 bgt 0x167114 <_ZN9CBitmap32C2EP7IBitmapbbi+0x144>
 *   @0x167148 ldr r3, [r5]
 *   @0x16714c mov r1, r9
 *   @0x167150 mov r0, r5
 *   @0x167154 ldr r3, [r3, #0x28]
 *   @0x167158 blx r3
 *   @0x16715c cmp r7, #0
 *   @0x167160 beq 0x167058 <_ZN9CBitmap32C2EP7IBitmapbbi+0x88>
 *   @0x167164 mov r0, r4
 *   @0x167168 bl 0x166404 <_ZN9CBitmap3216RemoveBackgroundEv>
 *   @0x16716c cmp r8, #0
 *   @0x167170 beq 0x167058 <_ZN9CBitmap32C2EP7IBitmapbbi+0x88>
 *   @0x167174 mov r0, r4
 *   @0x167178 bl 0x1661fc <_ZN9CBitmap3211SmoothEdgesEv>
 *   @0x16717c b 0x167058 <_ZN9CBitmap32C2EP7IBitmapbbi+0x88>
 *   @0x167180 eoreq r9, r8, r12, lsl r1
 *   @0x167184 andseq r3, lr, r12, lsl r5
 *
 * ══ §12/70 Motion_Grid_Create(int, int, int, int, int, int)  0x199fc0  size 440  110 条（0x199fc0..0x19a178）
 * @func 0x199fc0 0x19a178  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / Motion_Grid_Create(int, int, int, int, int, int)+0x180 / operator new(unsigned int) / Motion_Grid_Create(int, int, int, int, int, int)+0x158 / Motion_Grid_Create(int, int, int, int, int, int)+0x14c / Motion_Grid_Create(int, int, int, int, int, int)+0x120
 * 字段偏移 top8: 0x4×4 / 0x14×3 / 0x18×3 / 0x1c×2 / 0x190×1 / 0x184×1 / 0x17c×1 / 0x128×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199fc0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x199fc4 sub sp, sp, #12
 *   @0x199fc8 ldr r7, [pc, #0x190]
 *   @0x199fcc mov r11, r3
 *   @0x199fd0 str r0, [sp]
 *   @0x199fd4 mov r10, r2
 *   @0x199fd8 ldr r0, [pc, #0x184]
 *   @0x199fdc add r7, pc, r7
 *   @0x199fe0 str r1, [sp, #0x4]
 *   @0x199fe4 ldr r3, [pc, #0x17c]
 *   @0x199fe8 ldr r4, [r7, r0]
 *   @0x199fec ldr r1, [r4]
 *   @0x199ff0 cmp r1, #0
 *   @0x199ff4 ble 0x19a140 <_Z18Motion_Grid_Createiiiiii+0x180>
 *   @0x199ff8 ldr r8, [r7, r3]
 *   @0x199ffc ldr r3, [r8]
 *   @0x19a000 cmp r3, #0
 *   @0x19a004 beq 0x19a12c <_Z18Motion_Grid_Createiiiiii+0x16c>
 *   @0x19a008 ldr r6, [r3]
 *   @0x19a00c cmp r6, #0
 *   @0x19a010 beq 0x19a138 <_Z18Motion_Grid_Createiiiiii+0x178>
 *   @0x19a014 mov r5, #0
 *   @0x19a018 b 0x19a028 <_Z18Motion_Grid_Createiiiiii+0x68>
 *   @0x19a01c ldr r2, [r3, #0x4]!
 *   @0x19a020 cmp r2, #0
 *   @0x19a024 beq 0x19a060 <_Z18Motion_Grid_Createiiiiii+0xa0>
 *   @0x19a028 add r5, r5, #1
 *   @0x19a02c cmp r5, r1
 *   @0x19a030 lsl r6, r5, #2
 *   @0x19a034 bne 0x19a01c <_Z18Motion_Grid_Createiiiiii+0x5c>
 *   @0x19a038 add r1, r1, #1
 *   @0x19a03c ldr r2, [pc, #0x128]
 *   @0x19a040 mov r3, #97
 *   @0x19a044 mov r0, r8
 *   @0x19a048 add r2, pc, r2
 *   @0x19a04c lsl r1, r1, #2
 *   @0x19a050 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19a054 ldr r3, [r4]
 *   @0x19a058 add r3, r3, #1
 *   @0x19a05c str r3, [r4]
 *   @0x19a060 mov r0, #36
 *   @0x19a064 mov r9, #0
 *   @0x19a068 bl 0x27c524 <_Znwj>
 *   @0x19a06c ldr r12, [sp]
 *   @0x19a070 ldr r3, [pc, #0xf8]
 *   @0x19a074 mul r2, r11, r10
 *   @0x19a078 ldr r1, [r7, r3]
 *   @0x19a07c mov r3, #55
 *   @0x19a080 add r1, r1, #8
 *   @0x19a084 mov r4, r0
 *   @0x19a088 add r0, r0, #28
 *   @0x19a08c str r12, [r4, #0x4]
 *   @0x19a090 ldr r12, [sp, #0x4]
 *   @0x19a094 str r1, [r4]
 *   @0x19a098 lsl r1, r2, #2
 *   @0x19a09c str r2, [r4, #0x20]
 *   @0x19a0a0 str r12, [r4, #0x8]
 *   @0x19a0a4 ldr r12, [sp, #0x30]
 *   @0x19a0a8 ldr r2, [pc, #0xc4]
 *   @0x19a0ac str r10, [r4, #0x14]
 *   @0x19a0b0 str r12, [r4, #0xc]
 *   @0x19a0b4 add r2, pc, r2
 *   @0x19a0b8 ldr r12, [sp, #0x34]
 *   @0x19a0bc str r11, [r4, #0x18]
 *   @0x19a0c0 str r9, [r4, #0x1c]
 *   @0x19a0c4 str r12, [r4, #0x10]
 *   @0x19a0c8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19a0cc ldr r3, [r4, #0x14]
 *   @0x19a0d0 cmp r3, r9
 *   @0x19a0d4 ble 0x19a118 <_Z18Motion_Grid_Createiiiiii+0x158>
 *   @0x19a0d8 ldr r2, [r4, #0x18]
 *   @0x19a0dc mov r0, r9
 *   @0x19a0e0 cmp r2, #0
 *   @0x19a0e4 ble 0x19a10c <_Z18Motion_Grid_Createiiiiii+0x14c>
 *   @0x19a0e8 ldr r1, [r4, #0x1c]
 *   @0x19a0ec mov r3, #0
 *   @0x19a0f0 mla r2, r2, r9, r3
 *   @0x19a0f4 add r3, r3, #1
 *   @0x19a0f8 str r0, [r1, r2, lsl #2]
 *   @0x19a0fc ldr r2, [r4, #0x18]
 *   @0x19a100 cmp r2, r3
 *   @0x19a104 bgt 0x19a0f0 <_Z18Motion_Grid_Createiiiiii+0x130>
 *   @0x19a108 ldr r3, [r4, #0x14]
 *   @0x19a10c add r9, r9, #1
 *   @0x19a110 cmp r9, r3
 *   @0x19a114 blt 0x19a0e0 <_Z18Motion_Grid_Createiiiiii+0x120>
 *   @0x19a118 ldr r3, [r8]
 *   @0x19a11c mov r0, r5
 *   @0x19a120 str r4, [r3, r6]
 *   @0x19a124 add sp, sp, #12
 *   @0x19a128 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19a12c mov r6, r3
 *   @0x19a130 mov r5, r3
 *   @0x19a134 b 0x19a060 <_Z18Motion_Grid_Createiiiiii+0xa0>
 *   @0x19a138 mov r5, r6
 *   @0x19a13c b 0x19a060 <_Z18Motion_Grid_Createiiiiii+0xa0>
 *   @0x19a140 movne r6, #0
 *   @0x19a144 ldrne r8, [r7, r3]
 *   @0x19a148 movne r5, r6
 *   @0x19a14c bne 0x19a060 <_Z18Motion_Grid_Createiiiiii+0xa0>
 *   @0x19a150 mov r6, r1
 *   @0x19a154 mov r5, r1
 *   @0x19a158 ldr r8, [r7, r3]
 *   @0x19a15c b 0x19a038 <_Z18Motion_Grid_Createiiiiii+0x78>
 *   @0x19a160 eoreq r7, r5, r4, ror r12
 *   @0x19a164 .word 0xffffea5c
 *   @0x19a168 .word 0xffffea60
 *   @0x19a16c ldrsbeq r2, [r11], -r0
 *   @0x19a170 .word 0xffffea58
 *   @0x19a174 mulseq r11, r12, r12
 *
 * ══ §13/70 ObjectPool<CLayerOldTilemapElement>::~ObjectPool()  0x1b6c8c  size 440  110 条（0x1b6c8c..0x1b6e44）
 * @func 0x1b6c8c 0x1b6e44  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×6 / operator delete(void*)×3
 * 字段偏移 top8: 0x704×8 / 0x24×4 / 0x30×2 / 0x2c×2 / 0x28×2 / 0xc×1 / 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6c8c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1b6c90 mov r9, r0
 *   @0x1b6c94 ldr r7, [r0, #0xc]
 *   @0x1b6c98 cmp r7, #0
 *   @0x1b6c9c beq 0x1b6cec <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x60>
 *   @0x1b6ca0 ldr r4, [r0]
 *   @0x1b6ca4 cmp r4, #0
 *   @0x1b6ca8 beq 0x1b6cec <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x60>
 *   @0x1b6cac mov r8, #0
 *   @0x1b6cb0 b 0x1b6cd0 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x44>
 *   @0x1b6cb4 cmp r7, #3
 *   @0x1b6cb8 beq 0x1b6d04 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x78>
 *   @0x1b6cbc cmp r7, #1
 *   @0x1b6cc0 beq 0x1b6d8c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x100>
 *   @0x1b6cc4 cmp r6, #0
 *   @0x1b6cc8 beq 0x1b6cec <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x60>
 *   @0x1b6ccc mov r4, r6
 *   @0x1b6cd0 cmp r7, #2
 *   @0x1b6cd4 ldr r6, [r4, #0x14]
 *   @0x1b6cd8 bne 0x1b6cb4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x28>
 *   @0x1b6cdc mov r0, r4
 *   @0x1b6ce0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6ce4 cmp r6, #0
 *   @0x1b6ce8 bne 0x1b6ccc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x40>
 *   @0x1b6cec mov r3, #0
 *   @0x1b6cf0 mov r0, r9
 *   @0x1b6cf4 str r3, [r9, #0x8]
 *   @0x1b6cf8 str r3, [r9, #0x4]
 *   @0x1b6cfc str r3, [r9]
 *   @0x1b6d00 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b6d04 ldr r3, [r4, #0x30]
 *   @0x1b6d08 cmp r3, #0
 *   @0x1b6d0c beq 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8>
 *   @0x1b6d10 ldr r0, [r4, #0x24]
 *   @0x1b6d14 cmp r0, #0
 *   @0x1b6d18 beq 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8>
 *   @0x1b6d1c cmp r3, #2
 *   @0x1b6d20 beq 0x1b6d5c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xd0>
 *   @0x1b6d24 cmp r3, #3
 *   @0x1b6d28 beq 0x1b6d74 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xe8>
 *   @0x1b6d2c cmp r3, #1
 *   @0x1b6d30 beq 0x1b6e2c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x1a0>
 *   @0x1b6d34 ldr r5, [r0, #0x704]
 *   @0x1b6d38 cmp r5, #0
 *   @0x1b6d3c mov r0, r5
 *   @0x1b6d40 bne 0x1b6d34 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xa8>
 *   @0x1b6d44 str r8, [r4, #0x2c]
 *   @0x1b6d48 mov r0, r4
 *   @0x1b6d4c str r8, [r4, #0x28]
 *   @0x1b6d50 str r8, [r4, #0x24]
 *   @0x1b6d54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6d58 b 0x1b6cc4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x38>
 *   @0x1b6d5c ldr r5, [r0, #0x704]
 *   @0x1b6d60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6d64 cmp r5, #0
 *   @0x1b6d68 mov r0, r5
 *   @0x1b6d6c bne 0x1b6d5c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xd0>
 *   @0x1b6d70 b 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8>
 *   @0x1b6d74 ldr r5, [r0, #0x704]
 *   @0x1b6d78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6d7c cmp r5, #0
 *   @0x1b6d80 mov r0, r5
 *   @0x1b6d84 bne 0x1b6d74 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xe8>
 *   @0x1b6d88 b 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8>
 *   @0x1b6d8c ldr r3, [r4, #0x30]
 *   @0x1b6d90 cmp r3, #0
 *   @0x1b6d94 beq 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140>
 *   @0x1b6d98 ldr r0, [r4, #0x24]
 *   @0x1b6d9c cmp r0, #0
 *   @0x1b6da0 beq 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140>
 *   @0x1b6da4 cmp r3, #2
 *   @0x1b6da8 beq 0x1b6de4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x158>
 *   @0x1b6dac cmp r3, #3
 *   @0x1b6db0 beq 0x1b6dfc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x170>
 *   @0x1b6db4 cmp r3, #1
 *   @0x1b6db8 beq 0x1b6e14 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x188>
 *   @0x1b6dbc ldr r5, [r0, #0x704]
 *   @0x1b6dc0 cmp r5, #0
 *   @0x1b6dc4 mov r0, r5
 *   @0x1b6dc8 bne 0x1b6dbc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x130>
 *   @0x1b6dcc str r8, [r4, #0x2c]
 *   @0x1b6dd0 mov r0, r4
 *   @0x1b6dd4 str r8, [r4, #0x28]
 *   @0x1b6dd8 str r8, [r4, #0x24]
 *   @0x1b6ddc bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6de0 b 0x1b6cc4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x38>
 *   @0x1b6de4 ldr r5, [r0, #0x704]
 *   @0x1b6de8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6dec cmp r5, #0
 *   @0x1b6df0 mov r0, r5
 *   @0x1b6df4 bne 0x1b6de4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x158>
 *   @0x1b6df8 b 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140>
 *   @0x1b6dfc ldr r5, [r0, #0x704]
 *   @0x1b6e00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6e04 cmp r5, #0
 *   @0x1b6e08 mov r0, r5
 *   @0x1b6e0c bne 0x1b6dfc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x170>
 *   @0x1b6e10 b 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140>
 *   @0x1b6e14 ldr r5, [r0, #0x704]
 *   @0x1b6e18 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6e1c cmp r5, #0
 *   @0x1b6e20 mov r0, r5
 *   @0x1b6e24 bne 0x1b6e14 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x188>
 *   @0x1b6e28 b 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140>
 *   @0x1b6e2c ldr r5, [r0, #0x704]
 *   @0x1b6e30 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6e34 cmp r5, #0
 *   @0x1b6e38 mov r0, r5
 *   @0x1b6e3c bne 0x1b6e2c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x1a0>
 *   @0x1b6e40 b 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8>
 *
 * ══ §14/70 Sound_Init()  0x21f2e4  size 440  110 条（0x21f2e4..0x21f49c）
 * @func 0x21f2e4 0x21f49c  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×5 / Sound_Init()+0xb0 / CSound::~CSound() / operator delete(void*) / Sound_Init()+0x44 / Sound_Init()+0x144 / MemoryManager::IsAllocated(void const*) / Sound_Init()+0x108
 * 字段偏移 top8: 0xc×6 / 0x4×5 / 0x2×3 / 0x8×3 / 0x188×1 / 0x164×1 / 0x160×1 / 0xe0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f2e4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21f2e8 ldr r8, [pc, #0x188]
 *   @0x21f2ec add r8, pc, r8
 *   @0x21f2f0 ldr r3, [r8]
 *   @0x21f2f4 cmp r3, #0
 *   @0x21f2f8 beq 0x21f3bc <_Z10Sound_Initv+0xd8>
 *   @0x21f2fc ldr r5, [r8, #0x4]
 *   @0x21f300 cmp r5, #0
 *   @0x21f304 beq 0x21f468 <_Z10Sound_Initv+0x184>
 *   @0x21f308 cmp r3, #0
 *   @0x21f30c ble 0x21f394 <_Z10Sound_Initv+0xb0>
 *   @0x21f310 ldr r10, [pc, #0x164]
 *   @0x21f314 mov r4, #0
 *   @0x21f318 ldr r11, [pc, #0x160]
 *   @0x21f31c mov r9, r4
 *   @0x21f320 add r10, pc, r10
 *   @0x21f324 add r11, pc, r11
 *   @0x21f328 ldr r1, [r5]
 *   @0x21f32c movw r3, #0xfeee
 *   @0x21f330 movt r3, #0xfeee
 *   @0x21f334 movw r2, #0xfeee
 *   @0x21f338 cmp r1, r3
 *   @0x21f33c movt r2, #0xfeee
 *   @0x21f340 lsl r7, r4, #2
 *   @0x21f344 beq 0x21f384 <_Z10Sound_Initv+0xa0>
 *   @0x21f348 ldr r6, [r5, r4, lsl #2]
 *   @0x21f34c add r3, r5, r7
 *   @0x21f350 cmp r6, #0
 *   @0x21f354 mov r0, r6
 *   @0x21f358 beq 0x21f384 <_Z10Sound_Initv+0xa0>
 *   @0x21f35c ldr r1, [r6]
 *   @0x21f360 cmp r1, r2
 *   @0x21f364 beq 0x21f37c <_Z10Sound_Initv+0x98>
 *   @0x21f368 bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x21f36c mov r0, r6
 *   @0x21f370 bl 0x27d1d0 <_ZdlPv>
 *   @0x21f374 ldr r3, [r11, #0x4]
 *   @0x21f378 add r3, r3, r7
 *   @0x21f37c str r9, [r3]
 *   @0x21f380 ldr r5, [r10, #0x4]
 *   @0x21f384 ldr r3, [r8]
 *   @0x21f388 add r4, r4, #1
 *   @0x21f38c cmp r4, r3
 *   @0x21f390 blt 0x21f328 <_Z10Sound_Initv+0x44>
 *   @0x21f394 mov r0, r5
 *   @0x21f398 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f39c ldr r3, [pc, #0xe0]
 *   @0x21f3a0 mov r2, #0
 *   @0x21f3a4 add r3, pc, r3
 *   @0x21f3a8 str r2, [r3, #0x4]
 *   @0x21f3ac ldr r3, [pc, #0xd4]
 *   @0x21f3b0 mov r2, #0
 *   @0x21f3b4 add r3, pc, r3
 *   @0x21f3b8 str r2, [r3]
 *   @0x21f3bc ldr r5, [pc, #0xc8]
 *   @0x21f3c0 add r5, pc, r5
 *   @0x21f3c4 ldr r6, [r5, #0xc]
 *   @0x21f3c8 cmp r6, #0
 *   @0x21f3cc beq 0x21f458 <_Z10Sound_Initv+0x174>
 *   @0x21f3d0 ldr r3, [r5, #0x8]
 *   @0x21f3d4 cmp r3, #0
 *   @0x21f3d8 ble 0x21f428 <_Z10Sound_Initv+0x144>
 *   @0x21f3dc ldr r8, [pc, #0xac]
 *   @0x21f3e0 mov r4, #0
 *   @0x21f3e4 mov r7, r4
 *   @0x21f3e8 add r8, pc, r8
 *   @0x21f3ec ldr r0, [r6, r4, lsl #2]
 *   @0x21f3f0 lsl r6, r4, #2
 *   @0x21f3f4 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x21f3f8 cmp r0, #0
 *   @0x21f3fc beq 0x21f40c <_Z10Sound_Initv+0x128>
 *   @0x21f400 ldr r3, [r8, #0xc]
 *   @0x21f404 ldr r0, [r3, r4, lsl #2]
 *   @0x21f408 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f40c ldr r2, [r5, #0x8]
 *   @0x21f410 add r4, r4, #1
 *   @0x21f414 ldr r3, [r5, #0xc]
 *   @0x21f418 cmp r4, r2
 *   @0x21f41c str r7, [r3, r6]
 *   @0x21f420 ldr r6, [r5, #0xc]
 *   @0x21f424 blt 0x21f3ec <_Z10Sound_Initv+0x108>
 *   @0x21f428 mov r0, r6
 *   @0x21f42c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f430 ldr r3, [pc, #0x5c]
 *   @0x21f434 mov r2, #0
 *   @0x21f438 add r3, pc, r3
 *   @0x21f43c str r2, [r3, #0xc]
 *   @0x21f440 ldr r3, [pc, #0x50]
 *   @0x21f444 mov r2, #0
 *   @0x21f448 add r3, pc, r3
 *   @0x21f44c str r2, [r3, #0x8]
 *   @0x21f450 str r2, [r3, #0x10]
 *   @0x21f454 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21f458 mov r0, r6
 *   @0x21f45c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f460 str r6, [r5, #0xc]
 *   @0x21f464 b 0x21f440 <_Z10Sound_Initv+0x15c>
 *   @0x21f468 mov r0, r5
 *   @0x21f46c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f470 str r5, [r8, #0x4]
 *   @0x21f474 b 0x21f3ac <_Z10Sound_Initv+0xc8>
 *   @0x21f478 subseq r6, r3, r12, asr #32
 *   @0x21f47c subseq r6, r3, r8, lsl r0
 *   @0x21f480 subseq r6, r3, r4, lsl r0
 *   @0x21f484 .word 0x00535f94
 *   @0x21f488 subseq r5, r3, r4, lsl #31
 *   @0x21f48c subseq r5, r3, r8, ror pc
 *   @0x21f490 subseq r5, r3, r0, asr pc
 *   @0x21f494 subseq r5, r3, r0, lsl #30
 *   @0x21f498 ldrsheq r5, [r3], #-224
 *
 * ══ §15/70 png_do_strip_filler  0x2af930  size 440  110 条（0x2af930..0x2afae8）
 * @func 0x2af930 0x2afae8  size 440  110 条
 * 部分覆盖: 本节 110/181 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-3×7 / 0x-2×7 / 0x-1×6 / 0x-4×5 / 0xb×4 / 0x-5×4 / 0x-6×3 / 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af930 push {r4, r5, r6, lr}
 *   @0x2af934 ldr r3, [r0]
 *   @0x2af938 beq 0x2af946 <png_do_strip_filler+0x16>
 *   @0x2af93c bne.w 0x2afa42 <png_do_strip_filler+0x112>
 *   @0x2af940 lsls r5, r2, #0x9
 *   @0x2af944 bvc 0xfe40fc74 <b2_toiTime+0xfffffffffdcb67d0>
 *   @0x2af948 cmp r5, #0x4
 *   @0x2af94c ldrb r4, [r0, #0x9]
 *   @0x2af950 .word 0x2c080580
 *   @0x2af954 bne 0x2af9b2 <png_do_strip_filler+0x82>
 *   @0x2af958 movs r5, #0x3
 *   @0x2af95c mla r5, r5, r3, r1
 *   @0x2af960 b 0x2af992 <png_do_strip_filler+0x62>
 *   @0x2af964 adds r1, #0x3
 *   @0x2af968 cmp r5, r3
 *   @0x2af96c ldrb r6, [r4]
 *   @0x2af970 adds r4, #0x4
 *   @0x2af974 strb r6, [r1, #-3]
 *   @0x2af978 ldrb r6, [r4, #-3]
 *   @0x2af97c strb r6, [r1, #-2]
 *   @0x2af980 ldrb r6, [r4, #-2]
 *   @0x2af984 strb r6, [r1, #-1]
 *   @0x2af988 b 0x2af968 <png_do_strip_filler+0x38>
 *   @0x2af98c strb r1, [r0, #0xb]
 *   @0x2af990 b 0x2afa00 <png_do_strip_filler+0xd0>
 *   @0x2af994 beq 0x2af98a <png_do_strip_filler+0x5a>
 *   @0x2af998 adds r4, #0x3
 *   @0x2af99c strb r6, [r4, #-3]
 *   @0x2af9a0 ldrb r6, [r1, #-2]
 *   @0x2af9a4 strb r6, [r4, #-2]
 *   @0x2af9a8 ldrb r6, [r1, #-1]
 *   @0x2af9ac strb r6, [r4, #-1]
 *   @0x2af9b0 b 0x2af992 <png_do_strip_filler+0x62>
 *   @0x2af9b4 mov r4, r1
 *   @0x2af9b8 add.w r4, r1, #0x8
 *   @0x2af9bc adds r1, #0x6
 *   @0x2af9c0 cmp r5, r3
 *   @0x2af9c4 ldrb r6, [r4]
 *   @0x2af9c8 adds r4, #0x8
 *   @0x2af9cc strb r6, [r1, #-6]
 *   @0x2af9d0 ldrb r6, [r4, #-7]
 *   @0x2af9d4 strb r6, [r1, #-5]
 *   @0x2af9d8 ldrb r6, [r4, #-6]
 *   @0x2af9dc strb r6, [r1, #-4]
 *   @0x2af9e0 ldrb r6, [r4, #-5]
 *   @0x2af9e4 strb r6, [r1, #-3]
 *   @0x2af9e8 ldrb r6, [r4, #-4]
 *   @0x2af9ec strb r6, [r1, #-2]
 *   @0x2af9f0 ldrb r6, [r4, #-3]
 *   @0x2af9f4 strb r6, [r1, #-1]
 *   @0x2af9f8 b 0x2af9c0 <png_do_strip_filler+0x90>
 *   @0x2af9fc strb r1, [r0, #0xb]
 *   @0x2afa00 muls r3, r1, r3
 *   @0x2afa04 movs r3, #0x3
 *   @0x2afa08 cmp r5, r3
 *   @0x2afa0c ldrb r6, [r1, #0x2]
 *   @0x2afa10 adds r1, #0x8
 *   @0x2afa14 strb r6, [r4, #-6]
 *   @0x2afa18 ldrb r6, [r1, #-5]
 *   @0x2afa1c strb r6, [r4, #-5]
 *   @0x2afa20 ldrb r6, [r1, #-4]
 *   @0x2afa24 strb r6, [r4, #-4]
 *   @0x2afa28 ldrb r6, [r1, #-3]
 *   @0x2afa2c strb r6, [r4, #-3]
 *   @0x2afa30 ldrb r6, [r1, #-2]
 *   @0x2afa34 strb r6, [r4, #-2]
 *   @0x2afa38 ldrb r6, [r1, #-1]
 *   @0x2afa3c strb r6, [r4, #-1]
 *   @0x2afa40 b 0x2afa08 <png_do_strip_filler+0xd8>
 *   @0x2afa44 cmp r4, #0x4
 *   @0x2afa48 lsls r4, r2, #0x9
 *   @0x2afa4c ldrb r4, [r0, #0xa]
 *   @0x2afa50 bne 0x2afada <png_do_strip_filler+0x1aa>
 *   @0x2afa54 cmp r4, #0x8
 *   @0x2afa58 tstle r3, r0, lsl #9
 *   @0x2afa5c cbz r4, 0x2afa74 <png_do_strip_filler+0x144>
 *   @0x2afa60 cmp r4, r3
 *   @0x2afa64 ldrb.w r5, [r1, r4, lsl #1]
 *   @0x2afa68 strb r5, [r1, r4]
 *   @0x2afa6c b 0x2afa60 <png_do_strip_filler+0x130>
 *   @0x2afa70 strb r1, [r0, #0xb]
 *   @0x2afa74 cmp r4, r3
 *   @0x2afa78 add.w r5, r1, r4, lsl #1
 *   @0x2afa7c ldrb r5, [r5, #0x1]
 *   @0x2afa80 adds r4, #0x1
 *   @0x2afa84 cbnz r4, 0x2afa8a <png_do_strip_filler+0x15a>
 *   @0x2afa88 b 0x2afabc <png_do_strip_filler+0x18c>
 *   @0x2afa8c adds r1, #0x2
 *   @0x2afa90 cmp r5, r3
 *   @0x2afa94 .word 0xf1010404
 *   @0x2afa98 andle r0, r9, #-2147483648
 *   @0x2afa9c ldrb r6, [r4, #-4]
 *   @0x2afaa0 adds r5, #0x1
 *   @0x2afaa4 .word 0xf8146c02
 *   @0x2afaa8 .word 0xf8016c03
 *   @0x2afaac strb r6, [pc, r1, lsl #24]!
 *   @0x2afab0 lsls r3, r3, #0x1
 *   @0x2afab4 strb r1, [r0, #0xb]
 *   @0x2afab8 movs r3, #0x1
 *   @0x2afabc cmp r4, r3
 *   @0x2afac0 rscsle r0, r5, r2, lsl #10
 *   @0x2afac4 ldrb r6, [r1, #0x2]
 *   @0x2afac8 adds r1, #0x4
 *   @0x2afacc .word 0xf8116c02
 *   @0x2afad0 .word 0xf8056c01
 *   @0x2afad4 ldrb r6, [r1, r1, lsl #24]!
 *   @0x2afad8 strb r3, [r0, #0xa]
 *   @0x2afadc bpl 0x2afae6 <png_do_strip_filler+0x1b6>
 *   @0x2afae0 bic r3, r3, #0x4
 *   @0x2afae4 strb r3, [r0, #0x8]
 *
 * ══ §16/70 b2World::DrawJoint(b2Joint*)  0x2cab3c  size 440  110 条（0x2cab3c..0x2cacf4）
 * @func 0x2cab3c 0x2cacf4  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PulleyJoint::GetGroundAnchorA() const / b2PulleyJoint::GetGroundAnchorB() const
 * 字段偏移 top8: 0x1c×7 / 0x34×2 / 0x4×2 / 0x30×1 / 0x38×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cab3c ldr r2, [r1, #0x30]
 *   @0x2cab40 ldr r3, [r1, #0x34]
 *   @0x2cab44 add r2, r2, #12
 *   @0x2cab48 ldr r12, [r1]
 *   @0x2cab4c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2cab50 mov r4, r1
 *   @0x2cab54 sub sp, sp, #64
 *   @0x2cab58 mov r9, r0
 *   @0x2cab5c ldm r2, {r0, r1}
 *   @0x2cab60 add r3, r3, #12
 *   @0x2cab64 add r6, sp, #4
 *   @0x2cab68 ldr r2, [r12]
 *   @0x2cab6c add r5, sp, #12
 *   @0x2cab70 add r8, sp, #20
 *   @0x2cab74 stm r6, {r0, r1}
 *   @0x2cab78 add r7, sp, #28
 *   @0x2cab7c ldm r3, {r0, r1}
 *   @0x2cab80 stm r5, {r0, r1}
 *   @0x2cab84 mov r1, r4
 *   @0x2cab88 mov r0, r8
 *   @0x2cab8c blx r2
 *   @0x2cab90 ldr r3, [r4]
 *   @0x2cab94 mov r1, r4
 *   @0x2cab98 mov r0, r7
 *   @0x2cab9c ldr r3, [r3, #0x4]
 *   @0x2caba0 blx r3
 *   @0x2caba4 ldr r3, [r4, #0x4]
 *   @0x2caba8 mov r1, #1056964608
 *   @0x2cabac movw r2, #0xcccd
 *   @0x2cabb0 cmp r3, #4
 *   @0x2cabb4 movt r2, #0x3f4c
 *   @0x2cabb8 str r1, [sp, #0x34]
 *   @0x2cabbc str r2, [sp, #0x38]
 *   @0x2cabc0 str r2, [sp, #0x3c]
 *   @0x2cabc4 beq 0x2cac6c <_ZN7b2World9DrawJointEP7b2Joint+0x130>
 *   @0x2cabc8 cmp r3, #5
 *   @0x2cabcc beq 0x2cac38 <_ZN7b2World9DrawJointEP7b2Joint+0xfc>
 *   @0x2cabd0 cmp r3, #3
 *   @0x2cabd4 beq 0x2cac40 <_ZN7b2World9DrawJointEP7b2Joint+0x104>
 *   @0x2cabd8 movw r4, #0x9248
 *   @0x2cabdc movt r4, #0x1
 *   @0x2cabe0 mov r1, r6
 *   @0x2cabe4 add r6, sp, #52
 *   @0x2cabe8 ldr r0, [r9, r4]
 *   @0x2cabec mov r2, r8
 *   @0x2cabf0 mov r3, r6
 *   @0x2cabf4 ldr r12, [r0]
 *   @0x2cabf8 ldr r12, [r12, #0x1c]
 *   @0x2cabfc blx r12
 *   @0x2cac00 ldr r0, [r9, r4]
 *   @0x2cac04 mov r1, r8
 *   @0x2cac08 mov r3, r6
 *   @0x2cac0c mov r2, r7
 *   @0x2cac10 ldr r12, [r0]
 *   @0x2cac14 ldr r12, [r12, #0x1c]
 *   @0x2cac18 blx r12
 *   @0x2cac1c ldr r0, [r9, r4]
 *   @0x2cac20 mov r3, r6
 *   @0x2cac24 mov r1, r5
 *   @0x2cac28 mov r2, r7
 *   @0x2cac2c ldr r12, [r0]
 *   @0x2cac30 ldr r12, [r12, #0x1c]
 *   @0x2cac34 blx r12
 *   @0x2cac38 add sp, sp, #64
 *   @0x2cac3c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2cac40 movw r3, #0x9248
 *   @0x2cac44 movt r3, #0x1
 *   @0x2cac48 mov r1, r8
 *   @0x2cac4c mov r2, r7
 *   @0x2cac50 ldr r0, [r9, r3]
 *   @0x2cac54 add r3, sp, #52
 *   @0x2cac58 ldr r12, [r0]
 *   @0x2cac5c ldr r12, [r12, #0x1c]
 *   @0x2cac60 blx r12
 *   @0x2cac64 add sp, sp, #64
 *   @0x2cac68 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2cac6c add r10, sp, #36
 *   @0x2cac70 add r6, sp, #44
 *   @0x2cac74 mov r1, r4
 *   @0x2cac78 movw r5, #0x9248
 *   @0x2cac7c mov r0, r10
 *   @0x2cac80 movt r5, #0x1
 *   @0x2cac84 bl 0x2d1154 <_ZNK13b2PulleyJoint16GetGroundAnchorAEv>
 *   @0x2cac88 mov r1, r4
 *   @0x2cac8c mov r0, r6
 *   @0x2cac90 add r4, sp, #52
 *   @0x2cac94 bl 0x2d116c <_ZNK13b2PulleyJoint16GetGroundAnchorBEv>
 *   @0x2cac98 ldr r0, [r9, r5]
 *   @0x2cac9c mov r2, r8
 *   @0x2caca0 mov r1, r10
 *   @0x2caca4 mov r3, r4
 *   @0x2caca8 ldr r12, [r0]
 *   @0x2cacac ldr r12, [r12, #0x1c]
 *   @0x2cacb0 blx r12
 *   @0x2cacb4 ldr r0, [r9, r5]
 *   @0x2cacb8 mov r2, r7
 *   @0x2cacbc mov r1, r6
 *   @0x2cacc0 mov r3, r4
 *   @0x2cacc4 ldr r12, [r0]
 *   @0x2cacc8 ldr r12, [r12, #0x1c]
 *   @0x2caccc blx r12
 *   @0x2cacd0 ldr r0, [r9, r5]
 *   @0x2cacd4 mov r1, r10
 *   @0x2cacd8 mov r2, r6
 *   @0x2cacdc mov r3, r4
 *   @0x2cace0 ldr r12, [r0]
 *   @0x2cace4 ldr r12, [r12, #0x1c]
 *   @0x2cace8 blx r12
 *   @0x2cacec add sp, sp, #64
 *   @0x2cacf0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §17/70 F_Rectangle_In_Triangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x10c4c4  size 436  109 条（0x10c4c4..0x10c678）
 * @func 0x10c4c4 0x10c678  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×10 / Point_In_Triangle(float, float, float, float, float, float, float, float)×4
 * 字段偏移 top8: 0xc×5 / 0x4×4 / 0x8×4 / 0x10×3 / 0x14×3 / 0x18×3 / 0x1c×3 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c4c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10c4c8 sub sp, sp, #36
 *   @0x10c4cc mov r11, r0
 *   @0x10c4d0 mov r1, #0
 *   @0x10c4d4 ldr r6, [sp, #0x48]
 *   @0x10c4d8 mov r0, r6
 *   @0x10c4dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c4e0 mov r1, #1
 *   @0x10c4e4 str r0, [sp, #0x10]
 *   @0x10c4e8 mov r0, r6
 *   @0x10c4ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c4f0 mov r1, #2
 *   @0x10c4f4 str r0, [sp, #0x14]
 *   @0x10c4f8 mov r0, r6
 *   @0x10c4fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c500 mov r1, #3
 *   @0x10c504 str r0, [sp, #0x18]
 *   @0x10c508 mov r0, r6
 *   @0x10c50c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c510 mov r1, #4
 *   @0x10c514 str r0, [sp, #0x1c]
 *   @0x10c518 mov r0, r6
 *   @0x10c51c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c520 mov r1, #5
 *   @0x10c524 mov r5, r0
 *   @0x10c528 mov r0, r6
 *   @0x10c52c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c530 mov r1, #6
 *   @0x10c534 mov r4, r0
 *   @0x10c538 mov r0, r6
 *   @0x10c53c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c540 mov r1, #7
 *   @0x10c544 mov r9, r0
 *   @0x10c548 mov r0, r6
 *   @0x10c54c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c550 mov r1, #8
 *   @0x10c554 mov r8, r0
 *   @0x10c558 mov r0, r6
 *   @0x10c55c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c560 mov r1, #9
 *   @0x10c564 mov r7, r0
 *   @0x10c568 mov r0, r6
 *   @0x10c56c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c570 str r9, [sp]
 *   @0x10c574 str r8, [sp, #0x4]
 *   @0x10c578 mov r3, #0
 *   @0x10c57c str r7, [sp, #0x8]
 *   @0x10c580 mov r2, r5
 *   @0x10c584 ldr r1, [sp, #0x14]
 *   @0x10c588 mov r6, r0
 *   @0x10c58c str r0, [sp, #0xc]
 *   @0x10c590 str r3, [r11, #0xc]
 *   @0x10c594 mov r3, r4
 *   @0x10c598 ldr r0, [sp, #0x10]
 *   @0x10c59c bl 0x10c328 <_Z17Point_In_Triangleffffffff>
 *   @0x10c5a0 ldr r1, [sp, #0x14]
 *   @0x10c5a4 mov r2, r5
 *   @0x10c5a8 mov r3, r4
 *   @0x10c5ac str r9, [sp]
 *   @0x10c5b0 str r8, [sp, #0x4]
 *   @0x10c5b4 str r7, [sp, #0x8]
 *   @0x10c5b8 str r6, [sp, #0xc]
 *   @0x10c5bc mov r10, r0
 *   @0x10c5c0 ldr r0, [sp, #0x18]
 *   @0x10c5c4 bl 0x10c328 <_Z17Point_In_Triangleffffffff>
 *   @0x10c5c8 ldr r1, [sp, #0x1c]
 *   @0x10c5cc mov r2, r5
 *   @0x10c5d0 mov r3, r4
 *   @0x10c5d4 str r9, [sp]
 *   @0x10c5d8 str r8, [sp, #0x4]
 *   @0x10c5dc str r7, [sp, #0x8]
 *   @0x10c5e0 str r6, [sp, #0xc]
 *   @0x10c5e4 cmp r0, #0
 *   @0x10c5e8 ldr r0, [sp, #0x18]
 *   @0x10c5ec orrne r10, r10, #2
 *   @0x10c5f0 bl 0x10c328 <_Z17Point_In_Triangleffffffff>
 *   @0x10c5f4 str r9, [sp]
 *   @0x10c5f8 mov r2, r5
 *   @0x10c5fc str r8, [sp, #0x4]
 *   @0x10c600 mov r3, r4
 *   @0x10c604 str r7, [sp, #0x8]
 *   @0x10c608 str r6, [sp, #0xc]
 *   @0x10c60c ldr r1, [sp, #0x1c]
 *   @0x10c610 cmp r0, #0
 *   @0x10c614 ldr r0, [sp, #0x10]
 *   @0x10c618 orrne r10, r10, #4
 *   @0x10c61c bl 0x10c328 <_Z17Point_In_Triangleffffffff>
 *   @0x10c620 cmp r0, #0
 *   @0x10c624 beq 0x10c648 <_Z23F_Rectangle_In_TriangleR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x10c628 orr r10, r10, #8
 *   @0x10c62c cmp r10, #15
 *   @0x10c630 beq 0x10c660 <_Z23F_Rectangle_In_TriangleR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x10c634 mov r2, #0
 *   @0x10c638 mov r3, #1073741824
 *   @0x10c63c stm r11, {r2, r3}
 *   @0x10c640 add sp, sp, #36
 *   @0x10c644 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10c648 cmp r10, #0
 *   @0x10c64c streq r10, [r11]
 *   @0x10c650 streq r10, [r11, #0x4]
 *   @0x10c654 bne 0x10c634 <_Z23F_Rectangle_In_TriangleR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x10c658 add sp, sp, #36
 *   @0x10c65c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10c660 mov r3, #0
 *   @0x10c664 mov r2, r3
 *   @0x10c668 movt r3, #0x3ff0
 *   @0x10c66c stm r11, {r2, r3}
 *   @0x10c670 add sp, sp, #36
 *   @0x10c674 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §18/70 F_DrawBackgroundPart(RValue&, CInstance*, CInstance*, int, RValue*)  0x11dd70  size 436  109 条（0x11dd70..0x11df24）
 * @func 0x11dd70 0x11df24  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×12 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Get_Alpha()×2 / Sprite_Data(int) / CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float) / Background_Data(int) / CBackground::DrawPart(float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x14×3 / 0x4×2 / 0x8×2 / 0xc×2 / 0x18×2 / 0x10×2 / 0x1a4×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11dd70 ldr r3, [pc, #0x1a4]
 *   @0x11dd74 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11dd78 ldr r3, [pc, r3]
 *   @0x11dd7c sub sp, sp, #32
 *   @0x11dd80 ldrb r1, [r3]
 *   @0x11dd84 ldr r4, [sp, #0x40]
 *   @0x11dd88 cmp r1, #0
 *   @0x11dd8c mov r0, r4
 *   @0x11dd90 beq 0x11de50 <_Z20F_DrawBackgroundPartR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x11dd94 mov r1, #0
 *   @0x11dd98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11dd9c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11dda0 subs r5, r0, #0
 *   @0x11dda4 beq 0x11df04 <_Z20F_DrawBackgroundPartR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x11dda8 mov r0, r4
 *   @0x11ddac mov r1, #1
 *   @0x11ddb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ddb4 mov r1, #2
 *   @0x11ddb8 mov r7, r0
 *   @0x11ddbc mov r0, r4
 *   @0x11ddc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ddc4 mov r1, #3
 *   @0x11ddc8 mov r6, r0
 *   @0x11ddcc mov r0, r4
 *   @0x11ddd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ddd4 mov r1, #4
 *   @0x11ddd8 mov r10, r0
 *   @0x11dddc mov r0, r4
 *   @0x11dde0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11dde4 mov r1, #5
 *   @0x11dde8 mov r9, r0
 *   @0x11ddec mov r0, r4
 *   @0x11ddf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ddf4 mov r1, #6
 *   @0x11ddf8 mov r8, r0
 *   @0x11ddfc mov r0, r4
 *   @0x11de00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11de04 mov r4, r0
 *   @0x11de08 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11de0c mov r12, #1065353216
 *   @0x11de10 mvn lr, #-16777216
 *   @0x11de14 str r10, [sp]
 *   @0x11de18 mov r2, r7
 *   @0x11de1c str r9, [sp, #0x4]
 *   @0x11de20 mov r3, r6
 *   @0x11de24 str r8, [sp, #0x8]
 *   @0x11de28 mov r1, #0
 *   @0x11de2c str r4, [sp, #0xc]
 *   @0x11de30 str lr, [sp, #0x18]
 *   @0x11de34 str r12, [sp, #0x10]
 *   @0x11de38 str r12, [sp, #0x14]
 *   @0x11de3c str r0, [sp, #0x1c]
 *   @0x11de40 mov r0, r5
 *   @0x11de44 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf>
 *   @0x11de48 add sp, sp, #32
 *   @0x11de4c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11de50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11de54 bl 0xc3794 <_Z15Background_Datai>
 *   @0x11de58 subs r5, r0, #0
 *   @0x11de5c beq 0x11df04 <_Z20F_DrawBackgroundPartR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x11de60 mov r0, r4
 *   @0x11de64 mov r1, #1
 *   @0x11de68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11de6c mov r1, #2
 *   @0x11de70 mov r8, r0
 *   @0x11de74 mov r0, r4
 *   @0x11de78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11de7c mov r1, #3
 *   @0x11de80 mov r7, r0
 *   @0x11de84 mov r0, r4
 *   @0x11de88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11de8c mov r1, #4
 *   @0x11de90 mov r6, r0
 *   @0x11de94 mov r0, r4
 *   @0x11de98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11de9c mov r1, #5
 *   @0x11dea0 mov r10, r0
 *   @0x11dea4 mov r0, r4
 *   @0x11dea8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11deac mov r1, #6
 *   @0x11deb0 mov r9, r0
 *   @0x11deb4 mov r0, r4
 *   @0x11deb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11debc mov r4, r0
 *   @0x11dec0 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11dec4 mov r12, #1065353216
 *   @0x11dec8 mvn lr, #-16777216
 *   @0x11decc str r10, [sp]
 *   @0x11ded0 mov r1, r8
 *   @0x11ded4 str r9, [sp, #0x4]
 *   @0x11ded8 mov r2, r7
 *   @0x11dedc str r4, [sp, #0x8]
 *   @0x11dee0 mov r3, r6
 *   @0x11dee4 str lr, [sp, #0x14]
 *   @0x11dee8 str r12, [sp, #0xc]
 *   @0x11deec str r12, [sp, #0x10]
 *   @0x11def0 str r0, [sp, #0x18]
 *   @0x11def4 mov r0, r5
 *   @0x11def8 bl 0xc2184 <_ZN11CBackground8DrawPartEffffffffjf>
 *   @0x11defc add sp, sp, #32
 *   @0x11df00 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11df04 ldr r0, [pc, #0x14]
 *   @0x11df08 mov r1, #0
 *   @0x11df0c add r0, pc, r0
 *   @0x11df10 add sp, sp, #32
 *   @0x11df14 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11df18 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11df1c eoreq pc, r12, r12, lsr #23
 *   @0x11df20 eoreq r12, r1, r8, asr #5
 *
 * ══ §19/70 FINALIZE_Instance_Class()  0x1959f4  size 436  109 条（0x1959f4..0x195ba8）
 * @func 0x1959f4 0x195ba8  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×7 / 0x8×7 / 0xc×3 / 0x3×2 / 0x1a0×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1959f4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1959f8 mov r3, #0
 *   @0x1959fc ldr r6, [pc, #0x1a0]
 *   @0x195a00 ldr r6, [pc, r6]
 *   @0x195a04 ldm r6, {r2, r7}
 *   @0x195a08 b 0x195a14 <_Z23FINALIZE_Instance_Classv+0x20>
 *   @0x195a0c cmp r3, r7
 *   @0x195a10 bgt 0x195b9c <_Z23FINALIZE_Instance_Classv+0x1a8>
 *   @0x195a14 mov r8, r3
 *   @0x195a18 add r3, r3, #1
 *   @0x195a1c ldr r5, [r2, r8, lsl #3]
 *   @0x195a20 cmp r5, #0
 *   @0x195a24 beq 0x195a0c <_Z23FINALIZE_Instance_Classv+0x18>
 *   @0x195a28 ldr r0, [r6]
 *   @0x195a2c cmp r5, #0
 *   @0x195a30 beq 0x195b1c <_Z23FINALIZE_Instance_Classv+0x128>
 *   @0x195a34 ldr r1, [r5, #0xc]
 *   @0x195a38 cmp r1, #0
 *   @0x195a3c beq 0x195b1c <_Z23FINALIZE_Instance_Classv+0x128>
 *   @0x195a40 ldr r5, [r5, #0x4]
 *   @0x195a44 cmp r5, #0
 *   @0x195a48 beq 0x195ae4 <_Z23FINALIZE_Instance_Classv+0xf0>
 *   @0x195a4c ldr r2, [r1, #0x78]
 *   @0x195a50 and r3, r7, r2
 *   @0x195a54 ldr r4, [r0, r3, lsl #3]
 *   @0x195a58 add r12, r0, r3, lsl #3
 *   @0x195a5c cmp r4, #0
 *   @0x195a60 beq 0x195a2c <_Z23FINALIZE_Instance_Classv+0x38>
 *   @0x195a64 ldr r1, [r4, #0x8]
 *   @0x195a68 cmp r2, r1
 *   @0x195a6c beq 0x195a88 <_Z23FINALIZE_Instance_Classv+0x94>
 *   @0x195a70 ldr r4, [r4, #0x4]
 *   @0x195a74 cmp r4, #0
 *   @0x195a78 beq 0x195a2c <_Z23FINALIZE_Instance_Classv+0x38>
 *   @0x195a7c ldr r3, [r4, #0x8]
 *   @0x195a80 cmp r2, r3
 *   @0x195a84 bne 0x195a70 <_Z23FINALIZE_Instance_Classv+0x7c>
 *   @0x195a88 ldr r2, [r4]
 *   @0x195a8c ldr r0, [r4, #0xc]
 *   @0x195a90 cmp r2, #0
 *   @0x195a94 ldrne r3, [r4, #0x4]
 *   @0x195a98 ldreq r1, [r4, #0x4]
 *   @0x195a9c strne r3, [r2, #0x4]
 *   @0x195aa0 ldrne r1, [r4, #0x4]
 *   @0x195aa4 streq r1, [r12]
 *   @0x195aa8 cmp r1, #0
 *   @0x195aac streq r2, [r12, #0x4]
 *   @0x195ab0 strne r2, [r1]
 *   @0x195ab4 cmp r0, #0
 *   @0x195ab8 beq 0x195ac8 <_Z23FINALIZE_Instance_Classv+0xd4>
 *   @0x195abc ldr r3, [r0]
 *   @0x195ac0 ldr r3, [r3, #0x4]
 *   @0x195ac4 blx r3
 *   @0x195ac8 mov r0, r4
 *   @0x195acc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x195ad0 ldr r3, [r6, #0x8]
 *   @0x195ad4 ldr r7, [r6, #0x4]
 *   @0x195ad8 sub r3, r3, #1
 *   @0x195adc str r3, [r6, #0x8]
 *   @0x195ae0 b 0x195a28 <_Z23FINALIZE_Instance_Classv+0x34>
 *   @0x195ae4 add r2, r8, #1
 *   @0x195ae8 cmp r2, r7
 *   @0x195aec bgt 0x195b14 <_Z23FINALIZE_Instance_Classv+0x120>
 *   @0x195af0 add r3, r0, r8, lsl #3
 *   @0x195af4 ldr r5, [r3, #0x8]
 *   @0x195af8 mov r8, r2
 *   @0x195afc add r3, r3, #8
 *   @0x195b00 add r2, r2, #1
 *   @0x195b04 cmp r5, #0
 *   @0x195b08 bne 0x195a4c <_Z23FINALIZE_Instance_Classv+0x58>
 *   @0x195b0c cmp r7, r2
 *   @0x195b10 bge 0x195af4 <_Z23FINALIZE_Instance_Classv+0x100>
 *   @0x195b14 mvn r8, #0
 *   @0x195b18 b 0x195a4c <_Z23FINALIZE_Instance_Classv+0x58>
 *   @0x195b1c cmp r7, #0
 *   @0x195b20 poplt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x195b24 lsl r8, r7, #3
 *   @0x195b28 mov r9, #0
 *   @0x195b2c ldr r3, [r6]
 *   @0x195b30 add r2, r3, r8
 *   @0x195b34 ldr r4, [r3, r8]
 *   @0x195b38 str r9, [r3, r8]
 *   @0x195b3c cmp r4, #0
 *   @0x195b40 str r9, [r2, #0x4]
 *   @0x195b44 beq 0x195b88 <_Z23FINALIZE_Instance_Classv+0x194>
 *   @0x195b48 ldr r3, [r4, #0xc]
 *   @0x195b4c ldr r5, [r4, #0x4]
 *   @0x195b50 cmp r3, #0
 *   @0x195b54 mov r0, r3
 *   @0x195b58 beq 0x195b68 <_Z23FINALIZE_Instance_Classv+0x174>
 *   @0x195b5c ldr r3, [r3]
 *   @0x195b60 ldr r3, [r3, #0x4]
 *   @0x195b64 blx r3
 *   @0x195b68 mov r0, r4
 *   @0x195b6c mov r4, r5
 *   @0x195b70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x195b74 ldr r3, [r6, #0x8]
 *   @0x195b78 cmp r5, #0
 *   @0x195b7c sub r3, r3, #1
 *   @0x195b80 str r3, [r6, #0x8]
 *   @0x195b84 bne 0x195b48 <_Z23FINALIZE_Instance_Classv+0x154>
 *   @0x195b88 sub r7, r7, #1
 *   @0x195b8c sub r8, r8, #8
 *   @0x195b90 cmn r7, #1
 *   @0x195b94 bne 0x195b2c <_Z23FINALIZE_Instance_Classv+0x138>
 *   @0x195b98 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x195b9c mvn r8, #0
 *   @0x195ba0 b 0x195a28 <_Z23FINALIZE_Instance_Classv+0x34>
 *   @0x195ba4 eoreq r8, r5, r4, asr #4
 *
 * ══ §20/70 F_LayerGetAllElements(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bbc4c  size 436  109 条（0x1bbc4c..0x1bbe00）
 * @func 0x1bbc4c 0x1bbe00  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / ARRAY_RefAlloc(void*) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0x4×11 / 0xc×5 / 0x24×2 / 0x20×1 / 0x170×1 / 0x60×1 / 0x10c×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bbc4c cmp r3, #1
 *   @0x1bbc50 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1bbc54 mov r3, #0
 *   @0x1bbc58 mov r5, r3
 *   @0x1bbc5c mov r4, r0
 *   @0x1bbc60 movt r3, #0xbff0
 *   @0x1bbc64 str r5, [r0, #0xc]
 *   @0x1bbc68 str r3, [r0, #0x4]
 *   @0x1bbc6c str r5, [r0]
 *   @0x1bbc70 ldr r6, [sp, #0x20]
 *   @0x1bbc74 beq 0x1bbc8c <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bbc78 ldr r0, [pc, #0x170]
 *   @0x1bbc7c mov r1, r5
 *   @0x1bbc80 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1bbc84 add r0, pc, r0
 *   @0x1bbc88 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bbc8c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bbc90 subs r7, r0, #0
 *   @0x1bbc94 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1bbc98 ldr r3, [r6, #0xc]
 *   @0x1bbc9c mov r0, r6
 *   @0x1bbca0 mov r1, r5
 *   @0x1bbca4 bic r3, r3, #-16777216
 *   @0x1bbca8 cmp r3, #1
 *   @0x1bbcac beq 0x1bbdb4 <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1bbcb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bbcb4 mov r1, r0
 *   @0x1bbcb8 mov r0, r7
 *   @0x1bbcbc bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bbcc0 mov r5, r0
 *   @0x1bbcc4 cmp r5, #0
 *   @0x1bbcc8 beq 0x1bbdcc <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x1bbccc ldr r6, [r5, #0x60]
 *   @0x1bbcd0 mov r3, #2
 *   @0x1bbcd4 mov r0, r4
 *   @0x1bbcd8 str r3, [r4, #0xc]
 *   @0x1bbcdc bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x1bbce0 ldr r9, [pc, #0x10c]
 *   @0x1bbce4 mov r8, #1
 *   @0x1bbce8 movw r2, #0x14b7
 *   @0x1bbcec add r9, pc, r9
 *   @0x1bbcf0 mov r3, r8
 *   @0x1bbcf4 mov r1, r9
 *   @0x1bbcf8 mov r7, r0
 *   @0x1bbcfc str r0, [r4]
 *   @0x1bbd00 str r8, [r0, #0x10]
 *   @0x1bbd04 mov r0, #8
 *   @0x1bbd08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1bbd0c mov r3, r8
 *   @0x1bbd10 movw r2, #0x14b8
 *   @0x1bbd14 mov r1, r9
 *   @0x1bbd18 str r0, [r7, #0x4]
 *   @0x1bbd1c lsl r0, r6, #4
 *   @0x1bbd20 ldr r12, [r4]
 *   @0x1bbd24 ldr r7, [r12, #0x4]
 *   @0x1bbd28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1bbd2c ldr r12, [r5, #0x58]
 *   @0x1bbd30 cmp r12, #0
 *   @0x1bbd34 str r0, [r7, #0x4]
 *   @0x1bbd38 ldr r3, [r4]
 *   @0x1bbd3c ldr r2, [r3, #0x4]
 *   @0x1bbd40 str r6, [r2]
 *   @0x1bbd44 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1bbd48 cmp r6, #0
 *   @0x1bbd4c pople {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1bbd50 mov r1, #0
 *   @0x1bbd54 ldr r3, [r4]
 *   @0x1bbd58 mov r7, r1
 *   @0x1bbd5c b 0x1bbd70 <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1bbd60 cmp r1, r6
 *   @0x1bbd64 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1bbd68 ldr r3, [r4]
 *   @0x1bbd6c ldr r2, [r3, #0x4]
 *   @0x1bbd70 vldr s15, [r12, #4]
 *   @0x1bbd74 vcvt.f64.s32 d7, s15
 *   @0x1bbd78 ldr r0, [r3, #0x4]
 *   @0x1bbd7c lsl r5, r1, #4
 *   @0x1bbd80 ldr r8, [r2, #0x4]
 *   @0x1bbd84 ldr r0, [r0, #0x4]
 *   @0x1bbd88 add r8, r8, r5
 *   @0x1bbd8c add r5, r0, r5
 *   @0x1bbd90 str r7, [r8, #0xc]
 *   @0x1bbd94 vmov r2, r3, d7
 *   @0x1bbd98 str r2, [r0, r1, lsl #4]
 *   @0x1bbd9c add r1, r1, #1
 *   @0x1bbda0 str r3, [r5, #0x4]
 *   @0x1bbda4 ldr r12, [r12, #0x14]
 *   @0x1bbda8 cmp r12, #0
 *   @0x1bbdac bne 0x1bbd60 <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x1bbdb0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1bbdb4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bbdb8 mov r1, r0
 *   @0x1bbdbc mov r0, r7
 *   @0x1bbdc0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bbdc4 mov r5, r0
 *   @0x1bbdc8 b 0x1bbcc4 <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bbdcc ldr r3, [pc, #0x24]
 *   @0x1bbdd0 ldr r1, [pc, #0x24]
 *   @0x1bbdd4 ldr r3, [pc, r3]
 *   @0x1bbdd8 add r1, pc, r1
 *   @0x1bbddc ldr r0, [r3]
 *   @0x1bbde0 ldr r3, [r0]
 *   @0x1bbde4 ldr r3, [r3, #0xc]
 *   @0x1bbde8 blx r3
 *   @0x1bbdec pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1bbdf0 andseq r2, r9, r4, lsl #1
 *   @0x1bbdf4 andseq r1, r9, r0, lsl #21
 *   @0x1bbdf8 eoreq r1, r3, r0, asr #18
 *   @0x1bbdfc andseq r1, r9, r0, ror #30
 *
 * ══ §21/70 F_LayerBackgroundCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c6ea4  size 436  109 条（0x1c6ea4..0x1c7058）
 * @func 0x1c6ea4 0x1c7058  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetNewBackgroundElement() / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::AddNewElement(CRoom*, CLayer*, CLayerElementBase*, bool) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×4 / 0x4×4 / 0x1c×4 / 0x20×3 / 0x8×2 / 0x9×2 / 0x24×2 / 0x18×2
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c6ea4 cmp r3, #2
 *   @0x1c6ea8 mov r3, #0
 *   @0x1c6eac push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1c6eb0 mov r4, r3
 *   @0x1c6eb4 mov r5, r0
 *   @0x1c6eb8 movt r3, #0xbff0
 *   @0x1c6ebc str r4, [r0, #0xc]
 *   @0x1c6ec0 str r3, [r0, #0x4]
 *   @0x1c6ec4 str r4, [r0]
 *   @0x1c6ec8 ldr r6, [sp, #0x20]
 *   @0x1c6ecc beq 0x1c6ee4 <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c6ed0 ldr r0, [pc, #0x16c]
 *   @0x1c6ed4 mov r1, r4
 *   @0x1c6ed8 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1c6edc add r0, pc, r0
 *   @0x1c6ee0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c6ee4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c6ee8 ldr r3, [r6, #0xc]
 *   @0x1c6eec mov r1, r4
 *   @0x1c6ef0 bic r3, r3, #-16777216
 *   @0x1c6ef4 cmp r3, #1
 *   @0x1c6ef8 mov r8, r0
 *   @0x1c6efc mov r0, r6
 *   @0x1c6f00 beq 0x1c7004 <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x1c6f04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c6f08 mov r1, r0
 *   @0x1c6f0c mov r0, r8
 *   @0x1c6f10 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c6f14 mov r9, r0
 *   @0x1c6f18 cmp r9, #0
 *   @0x1c6f1c beq 0x1c701c <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x1c6f20 bl 0x1c0bd8 <_ZN13CLayerManager23GetNewBackgroundElementEv>
 *   @0x1c6f24 ldr r1, [pc, #0x11c]
 *   @0x1c6f28 movw r2, #0xe61
 *   @0x1c6f2c mov r3, #1
 *   @0x1c6f30 add r1, pc, r1
 *   @0x1c6f34 mov r7, r0
 *   @0x1c6f38 mov r0, #44
 *   @0x1c6f3c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c6f40 subs r4, r0, #0
 *   @0x1c6f44 beq 0x1c6f70 <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x1c6f48 mov r3, #0
 *   @0x1c6f4c mov r2, #0
 *   @0x1c6f50 str r3, [r4, #0x4]
 *   @0x1c6f54 str r2, [r4, #0x1c]
 *   @0x1c6f58 strb r3, [r4, #0x8]
 *   @0x1c6f5c str r2, [r4, #0x20]
 *   @0x1c6f60 strb r3, [r4, #0x9]
 *   @0x1c6f64 str r2, [r4, #0x24]
 *   @0x1c6f68 str r3, [r4, #0x18]
 *   @0x1c6f6c str r3, [r4, #0x28]
 *   @0x1c6f70 str r4, [r7, #0x1c]
 *   @0x1c6f74 mov r10, #1065353216
 *   @0x1c6f78 mov r1, #1
 *   @0x1c6f7c mov r0, r6
 *   @0x1c6f80 strb r1, [r4]
 *   @0x1c6f84 mov r6, #0
 *   @0x1c6f88 str r10, [r4, #0xc]
 *   @0x1c6f8c strb r6, [r4, #0x14]
 *   @0x1c6f90 strb r6, [r4, #0x1]
 *   @0x1c6f94 str r10, [r4, #0x10]
 *   @0x1c6f98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c6f9c ldr r3, [pc, #0xa8]
 *   @0x1c6fa0 ldr r12, [r7, #0x1c]
 *   @0x1c6fa4 mov r1, r9
 *   @0x1c6fa8 ldr r3, [pc, r3]
 *   @0x1c6fac mvn lr, #0
 *   @0x1c6fb0 mov r2, r7
 *   @0x1c6fb4 mov r9, #0
 *   @0x1c6fb8 ldr r3, [r3]
 *   @0x1c6fbc cmp r3, r8
 *   @0x1c6fc0 movne r3, #0
 *   @0x1c6fc4 moveq r3, #1
 *   @0x1c6fc8 str r0, [r4, #0x4]
 *   @0x1c6fcc mov r0, r8
 *   @0x1c6fd0 strb r6, [r12, #0x8]
 *   @0x1c6fd4 strb r6, [r12, #0x9]
 *   @0x1c6fd8 str r10, [r12, #0x1c]
 *   @0x1c6fdc str r10, [r12, #0x24]
 *   @0x1c6fe0 str lr, [r12, #0x18]
 *   @0x1c6fe4 str r9, [r12, #0x20]
 *   @0x1c6fe8 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1c6fec ldr r2, [r7, #0x4]
 *   @0x1c6ff0 vmov s15, r2
 *   @0x1c6ff4 vcvt.f64.s32 d7, s15
 *   @0x1c6ff8 vmov r2, r3, d7
 *   @0x1c6ffc stm r5, {r2, r3}
 *   @0x1c7000 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1c7004 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c7008 mov r1, r0
 *   @0x1c700c mov r0, r8
 *   @0x1c7010 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c7014 mov r9, r0
 *   @0x1c7018 b 0x1c6f18 <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1c701c ldr r3, [pc, #0x2c]
 *   @0x1c7020 mov r2, r9
 *   @0x1c7024 ldr r1, [pc, #0x28]
 *   @0x1c7028 ldr r3, [pc, r3]
 *   @0x1c702c add r1, pc, r1
 *   @0x1c7030 ldr r0, [r3]
 *   @0x1c7034 ldr r3, [r0]
 *   @0x1c7038 ldr r3, [r3, #0xc]
 *   @0x1c703c blx r3
 *   @0x1c7040 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1c7044 andseq r9, r8, r0, ror r10
 *   @0x1c7048 andseq r6, r8, r12, lsr r8
 *   @0x1c704c eoreq r6, r2, r0, lsl #19
 *   @0x1c7050 eoreq r6, r2, r12, ror #13
 *   @0x1c7054 andseq r9, r8, r8, asr r9
 *
 * ══ §22/70 JS_Array_prototype_concat(RValue&, CInstance*, CInstance*, int, RValue*)  0x259af8  size 436  109 条（0x259af8..0x259cac）
 * @func 0x259af8 0x259cac  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SetArrayEntry(YYObjectBase*, unsigned int, RValue*)×2 / YYObjectBase::InternalGetYYVar(int)×2 / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) / JS_Array_prototype_concat(RValue&, CInstance*, CInstance*, int, RValue*)+0x120 / 0xb6574 / F_JS_ToString(RValue&, RValue*) / FREE_RValue__Pre(RValue*) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×4 / 0x2c×4 / 0x8×3 / 0x4×3 / 0x1c×1 / 0x10×1 / 0x150×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x259af8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x259afc sub sp, sp, #52
 *   @0x259b00 mov r12, #0
 *   @0x259b04 mov r5, r0
 *   @0x259b08 str r3, [sp, #0x8]
 *   @0x259b0c mov r3, r12
 *   @0x259b10 str r12, [sp]
 *   @0x259b14 mov r4, r1
 *   @0x259b18 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x259b1c ldr r0, [r5]
 *   @0x259b20 mov r3, #6
 *   @0x259b24 str r3, [sp, #0x1c]
 *   @0x259b28 str r4, [sp, #0x10]
 *   @0x259b2c ldr r3, [r0, #0x4]
 *   @0x259b30 cmp r3, #0
 *   @0x259b34 beq 0x259c98 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x259b38 add r0, r3, #16
 *   @0x259b3c ldr r12, [sp, #0x8]
 *   @0x259b40 ldr r8, [r0]
 *   @0x259b44 cmp r12, #0
 *   @0x259b48 blt 0x259c18 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x259b4c ldr r3, [pc, #0x150]
 *   @0x259b50 mov r6, #0
 *   @0x259b54 add r5, sp, #16
 *   @0x259b58 add r9, sp, #32
 *   @0x259b5c mov r4, r6
 *   @0x259b60 mvn r7, #-16777216
 *   @0x259b64 add r3, pc, r3
 *   @0x259b68 str r3, [sp, #0xc]
 *   @0x259b6c ldr r3, [r5, #0xc]
 *   @0x259b70 bic r3, r3, #-16777216
 *   @0x259b74 cmp r3, #6
 *   @0x259b78 bne 0x259c20 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x259b7c ldr r10, [r5]
 *   @0x259b80 ldr r1, [sp, #0xc]
 *   @0x259b84 ldr r0, [r10, #0x40]
 *   @0x259b88 bl 0xb6574 <strcmp@plt>
 *   @0x259b8c cmp r0, #0
 *   @0x259b90 bne 0x259c20 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x259b94 ldr r2, [r10, #0x4]
 *   @0x259b98 cmp r2, #0
 *   @0x259b9c beq 0x259c88 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x259ba0 add r0, r2, #16
 *   @0x259ba4 ldr r3, [r0]
 *   @0x259ba8 ldr r11, [r3, #0x2c]
 *   @0x259bac ldr r10, [r3, #0x4]
 *   @0x259bb0 cmp r11, #0
 *   @0x259bb4 bne 0x259bc8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x259bb8 b 0x259bf8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x259bbc subs r11, r11, #1
 *   @0x259bc0 add r10, r10, #16
 *   @0x259bc4 beq 0x259bf8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x259bc8 ldr r3, [r10, #0xc]
 *   @0x259bcc bic r3, r3, #-16777216
 *   @0x259bd0 cmp r3, r7
 *   @0x259bd4 beq 0x259bbc <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x259bd8 mov r1, r4
 *   @0x259bdc mov r2, r10
 *   @0x259be0 mov r0, r8
 *   @0x259be4 add r4, r4, #1
 *   @0x259be8 bl 0x247904 <_Z13SetArrayEntryP12YYObjectBasejP6RValue>
 *   @0x259bec subs r11, r11, #1
 *   @0x259bf0 add r10, r10, #16
 *   @0x259bf4 bne 0x259bc8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x259bf8 cmp r6, #0
 *   @0x259bfc ldr r12, [sp, #0x8]
 *   @0x259c00 add r6, r6, #1
 *   @0x259c04 ldreq r3, [sp, #0x58]
 *   @0x259c08 subeq r5, r3, #16
 *   @0x259c0c cmp r12, r6
 *   @0x259c10 add r5, r5, #16
 *   @0x259c14 bge 0x259b6c <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x259c18 add sp, sp, #52
 *   @0x259c1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x259c20 mov r0, r9
 *   @0x259c24 mov r1, r5
 *   @0x259c28 mov r12, #5
 *   @0x259c2c str r12, [sp, #0x2c]
 *   @0x259c30 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x259c34 cmp r0, #1
 *   @0x259c38 beq 0x259c74 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x259c3c mov r1, r4
 *   @0x259c40 mov r0, r8
 *   @0x259c44 mov r2, r9
 *   @0x259c48 add r4, r4, #1
 *   @0x259c4c bl 0x247904 <_Z13SetArrayEntryP12YYObjectBasejP6RValue>
 *   @0x259c50 ldr r3, [sp, #0x2c]
 *   @0x259c54 sub r3, r3, #1
 *   @0x259c58 bic r3, r3, #-16777216
 *   @0x259c5c bic r3, r3, #3
 *   @0x259c60 cmp r3, #0
 *   @0x259c64 bne 0x259bf8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x259c68 mov r0, r9
 *   @0x259c6c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x259c70 b 0x259bf8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x259c74 ldr r0, [pc, #0x2c]
 *   @0x259c78 add r0, pc, r0
 *   @0x259c7c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x259c80 add sp, sp, #52
 *   @0x259c84 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x259c88 mov r0, r10
 *   @0x259c8c mov r1, #1
 *   @0x259c90 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x259c94 b 0x259ba4 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x259c98 mov r1, #1
 *   @0x259c9c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x259ca0 b 0x259b3c <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x259ca4 strheq r10, [sp], -r4
 *   @0x259ca8 andeq r12, pc, r0, ror #31
 *
 * ══ §23/70 jinit_memory_mgr  0x2ba0b4  size 436  109 条（0x2ba0b4..0x2ba268）
 * @func 0x2ba0b4 0x2ba268  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_mem_init / jpeg_get_small / 0xb6a24 / 0xb68f8 / jinit_memory_mgr+0x14c / jpeg_mem_term
 * 字段偏移 top8: 0x4×6 / 0x124×3 / 0x14×2 / 0x18×2 / 0x2c×2 / 0x3×2 / 0x148×1 / 0x144×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ba0b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ba0b8 mov r3, #0
 *   @0x2ba0bc sub sp, sp, #12
 *   @0x2ba0c0 str r3, [r0, #0x4]
 *   @0x2ba0c4 mov r5, r0
 *   @0x2ba0c8 bl 0x2c142c <jpeg_mem_init>
 *   @0x2ba0cc mov r1, #84
 *   @0x2ba0d0 str r0, [sp, #0x4]
 *   @0x2ba0d4 mov r0, r5
 *   @0x2ba0d8 bl 0x2c137c <jpeg_get_small>
 *   @0x2ba0dc subs r4, r0, #0
 *   @0x2ba0e0 beq 0x2ba208 <jinit_memory_mgr+0x154>
 *   @0x2ba0e4 ldr r11, [pc, #0x148]
 *   @0x2ba0e8 mov r2, #51712
 *   @0x2ba0ec ldr r0, [pc, #0x144]
 *   @0x2ba0f0 movt r2, #0x3b9a
 *   @0x2ba0f4 add r11, pc, r11
 *   @0x2ba0f8 str r11, [r4]
 *   @0x2ba0fc ldr r11, [sp, #0x4]
 *   @0x2ba100 add r0, pc, r0
 *   @0x2ba104 str r2, [r4, #0x30]
 *   @0x2ba108 mov r3, #0
 *   @0x2ba10c str r0, [r4, #0x20]
 *   @0x2ba110 ldr r10, [pc, #0x124]
 *   @0x2ba114 ldr r9, [pc, #0x124]
 *   @0x2ba118 ldr r8, [pc, #0x124]
 *   @0x2ba11c add r10, pc, r10
 *   @0x2ba120 ldr r7, [pc, #0x120]
 *   @0x2ba124 add r9, pc, r9
 *   @0x2ba128 ldr r6, [pc, #0x11c]
 *   @0x2ba12c add r8, pc, r8
 *   @0x2ba130 ldr lr, [pc, #0x118]
 *   @0x2ba134 add r7, pc, r7
 *   @0x2ba138 ldr r12, [pc, #0x114]
 *   @0x2ba13c add r6, pc, r6
 *   @0x2ba140 ldr r1, [pc, #0x110]
 *   @0x2ba144 add lr, pc, lr
 *   @0x2ba148 ldr r2, [pc, #0x10c]
 *   @0x2ba14c add r12, pc, r12
 *   @0x2ba150 ldr r0, [pc, #0x108]
 *   @0x2ba154 add r1, pc, r1
 *   @0x2ba158 str r3, [r4, #0x38]
 *   @0x2ba15c add r2, pc, r2
 *   @0x2ba160 str r3, [r4, #0x40]
 *   @0x2ba164 add r0, pc, r0
 *   @0x2ba168 str r3, [r4, #0x34]
 *   @0x2ba16c str r3, [r4, #0x3c]
 *   @0x2ba170 str r3, [r4, #0x44]
 *   @0x2ba174 str r3, [r4, #0x48]
 *   @0x2ba178 mov r3, #84
 *   @0x2ba17c str r10, [r4, #0x4]
 *   @0x2ba180 str r9, [r4, #0x8]
 *   @0x2ba184 str r8, [r4, #0xc]
 *   @0x2ba188 str r7, [r4, #0x10]
 *   @0x2ba18c str r6, [r4, #0x14]
 *   @0x2ba190 str lr, [r4, #0x18]
 *   @0x2ba194 str r12, [r4, #0x1c]
 *   @0x2ba198 str r1, [r4, #0x24]
 *   @0x2ba19c str r2, [r4, #0x28]
 *   @0x2ba1a0 str r11, [r4, #0x2c]
 *   @0x2ba1a4 str r3, [r4, #0x4c]
 *   @0x2ba1a8 str r4, [r5, #0x4]
 *   @0x2ba1ac bl 0xb6a24 <getenv@plt>
 *   @0x2ba1b0 cmp r0, #0
 *   @0x2ba1b4 beq 0x2ba200 <jinit_memory_mgr+0x14c>
 *   @0x2ba1b8 ldr r1, [pc, #0xa4]
 *   @0x2ba1bc add r2, sp, #4
 *   @0x2ba1c0 add r3, sp, #3
 *   @0x2ba1c4 mov r12, #120
 *   @0x2ba1c8 add r1, pc, r1
 *   @0x2ba1cc strb r12, [sp, #0x3]
 *   @0x2ba1d0 bl 0xb68f8 <sscanf@plt>
 *   @0x2ba1d4 cmp r0, #0
 *   @0x2ba1d8 ble 0x2ba200 <jinit_memory_mgr+0x14c>
 *   @0x2ba1dc ldrb r3, [sp, #0x3]
 *   @0x2ba1e0 and r3, r3, #223
 *   @0x2ba1e4 cmp r3, #77
 *   @0x2ba1e8 ldr r3, [sp, #0x4]
 *   @0x2ba1ec moveq r2, #1000
 *   @0x2ba1f0 muleq r3, r2, r3
 *   @0x2ba1f4 mov r2, #1000
 *   @0x2ba1f8 mul r3, r2, r3
 *   @0x2ba1fc str r3, [r4, #0x2c]
 *   @0x2ba200 add sp, sp, #12
 *   @0x2ba204 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ba208 mov r0, r5
 *   @0x2ba20c bl 0x2c1438 <jpeg_mem_term>
 *   @0x2ba210 ldr r3, [r5]
 *   @0x2ba214 mov r1, #54
 *   @0x2ba218 mov r0, r5
 *   @0x2ba21c str r4, [r3, #0x18]
 *   @0x2ba220 ldr r2, [r5]
 *   @0x2ba224 str r1, [r3, #0x14]
 *   @0x2ba228 ldr r3, [r2]
 *   @0x2ba22c blx r3
 *   @0x2ba230 b 0x2ba0e4 <jinit_memory_mgr+0x30>
 *   @0x2ba234 .word 0xfffff0d4
 *   @0x2ba238 .word 0xfffff538
 *   @0x2ba23c .word 0xfffff6fc
 *   @0x2ba240 .word 0xfffff8a8
 *   @0x2ba244 .word 0xfffff7d8
 *   @0x2ba248 .word 0xfffff2bc
 *   @0x2ba24c .word 0xfffff234
 *   @0x2ba250 .word 0xfffff950
 *   @0x2ba254 .word 0xfffffba0
 *   @0x2ba258 .word 0xfffff31c
 *   @0x2ba25c .word 0xfffff49c
 *   @0x2ba260 andeq r1, r10, r4, asr #11
 *   @0x2ba264 andeq r1, r10, r8, ror #10
 *
 * ══ §24/70 F_DsExists(RValue&, CInstance*, CInstance*, int, RValue*)  0xffaec  size 432  108 条（0xffaec..0xffc9c）
 * @func 0xffaec 0xffc9c  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsExists(RValue&, CInstance*, CInstance*, int, RValue*)+0xac×6 / YYGetInt32(RValue const*, int)×2 / DS_AutoMutex::DS_AutoMutex() / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0x15c×1 / 0xc×1 / 0xf8×1 / 0xe8×1 / 0x2×1 / 0xb0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xffaec push {r4, r5, r6, r7, r8, lr}
 *   @0xffaf0 sub sp, sp, #8
 *   @0xffaf4 add r6, sp, #4
 *   @0xffaf8 mov r4, r0
 *   @0xffafc ldr r7, [sp, #0x20]
 *   @0xffb00 mov r0, r6
 *   @0xffb04 ldr r5, [pc, #0x15c]
 *   @0xffb08 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xffb0c mov r1, #0
 *   @0xffb10 mov r3, r1
 *   @0xffb14 str r1, [r4, #0xc]
 *   @0xffb18 movt r3, #0x3ff0
 *   @0xffb1c mov r0, r7
 *   @0xffb20 stm r4, {r1, r3}
 *   @0xffb24 add r5, pc, r5
 *   @0xffb28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xffb2c mov r1, #1
 *   @0xffb30 mov r8, r0
 *   @0xffb34 mov r0, r7
 *   @0xffb38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xffb3c sub r0, r0, #1
 *   @0xffb40 cmp r0, #5
 *   @0xffb44 addls pc, pc, r0, lsl #2
 *   @0xffb48 b 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffb4c b 0xffbb4 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0xffb50 b 0xffbd8 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xffb54 b 0xffbfc <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0xffb58 b 0xffc20 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0xffb5c b 0xffc44 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0xffb60 b 0xffb64 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xffb64 cmp r8, #0
 *   @0xffb68 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffb6c ldr r3, [pc, #0xf8]
 *   @0xffb70 ldr r3, [r5, r3]
 *   @0xffb74 ldr r3, [r3]
 *   @0xffb78 cmp r8, r3
 *   @0xffb7c bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffb80 ldr r3, [pc, #0xe8]
 *   @0xffb84 ldr r3, [r5, r3]
 *   @0xffb88 ldr r3, [r3, #0x4]
 *   @0xffb8c ldr r3, [r3, r8, lsl #2]
 *   @0xffb90 cmp r3, #0
 *   @0xffb94 bne 0xffba4 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xffb98 mov r3, #0
 *   @0xffb9c str r3, [r4]
 *   @0xffba0 str r3, [r4, #0x4]
 *   @0xffba4 mov r0, r6
 *   @0xffba8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xffbac add sp, sp, #8
 *   @0xffbb0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xffbb4 cmp r8, #0
 *   @0xffbb8 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffbbc ldr r3, [pc, #0xb0]
 *   @0xffbc0 ldr r3, [r5, r3]
 *   @0xffbc4 ldr r3, [r3]
 *   @0xffbc8 cmp r8, r3
 *   @0xffbcc bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffbd0 ldr r3, [pc, #0xa0]
 *   @0xffbd4 b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xffbd8 cmp r8, #0
 *   @0xffbdc blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffbe0 ldr r3, [pc, #0x94]
 *   @0xffbe4 ldr r3, [r5, r3]
 *   @0xffbe8 ldr r3, [r3]
 *   @0xffbec cmp r8, r3
 *   @0xffbf0 bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffbf4 ldr r3, [pc, #0x84]
 *   @0xffbf8 b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xffbfc cmp r8, #0
 *   @0xffc00 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffc04 ldr r3, [pc, #0x78]
 *   @0xffc08 ldr r3, [r5, r3]
 *   @0xffc0c ldr r3, [r3]
 *   @0xffc10 cmp r8, r3
 *   @0xffc14 bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffc18 ldr r3, [pc, #0x68]
 *   @0xffc1c b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xffc20 cmp r8, #0
 *   @0xffc24 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffc28 ldr r3, [pc, #0x5c]
 *   @0xffc2c ldr r3, [r5, r3]
 *   @0xffc30 ldr r3, [r3]
 *   @0xffc34 cmp r8, r3
 *   @0xffc38 bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffc3c ldr r3, [pc, #0x4c]
 *   @0xffc40 b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xffc44 cmp r8, #0
 *   @0xffc48 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffc4c ldr r3, [pc, #0x40]
 *   @0xffc50 ldr r3, [r5, r3]
 *   @0xffc54 ldr r3, [r3]
 *   @0xffc58 cmp r8, r3
 *   @0xffc5c bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xffc60 ldr r3, [pc, #0x30]
 *   @0xffc64 b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xffc68 eoreq r2, pc, r12, lsr #2
 *   @0xffc6c .word 0xffffc224
 *   @0xffc70 .word 0xffffc228
 *   @0xffc74 .word 0xffffc028
 *   @0xffc78 .word 0xffffbcec
 *   @0xffc7c .word 0xffffc02c
 *   @0xffc80 .word 0xffffc030
 *   @0xffc84 .word 0xffffc22c
 *   @0xffc88 .word 0xffffc230
 *   @0xffc8c .word 0xffffc21c
 *   @0xffc90 .word 0xffffc220
 *   @0xffc94 .word 0xffffc234
 *   @0xffc98 .word 0xffffc238
 *
 * ══ §25/70 F_SpriteAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f4c0  size 432  108 条（0x12f4c0..0x12f670）
 * @func 0x12f4c0 0x12f670  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×12 / YYGetString(RValue const*, int)×2 / Sprite_Add(char const*, int, bool, bool, bool, bool, int, int)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x14×2 / 0x8×2 / 0x40×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f4c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12f4c4 cmp r3, #6
 *   @0x12f4c8 sub sp, sp, #28
 *   @0x12f4cc mov r3, #0
 *   @0x12f4d0 mov r6, r3
 *   @0x12f4d4 mov r5, r0
 *   @0x12f4d8 movt r3, #0xbff0
 *   @0x12f4dc str r6, [r0, #0xc]
 *   @0x12f4e0 str r3, [r0, #0x4]
 *   @0x12f4e4 str r6, [r0]
 *   @0x12f4e8 ldr r4, [sp, #0x40]
 *   @0x12f4ec beq 0x12f5dc <_Z11F_SpriteAddR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x12f4f0 mov r1, r6
 *   @0x12f4f4 mov r0, r4
 *   @0x12f4f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12f4fc mov r1, #1
 *   @0x12f500 mov r6, r0
 *   @0x12f504 mov r0, r4
 *   @0x12f508 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f50c mov r1, #2
 *   @0x12f510 mov r10, r0
 *   @0x12f514 mov r0, r4
 *   @0x12f518 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f51c mov r1, #3
 *   @0x12f520 mov r8, r0
 *   @0x12f524 mov r0, r4
 *   @0x12f528 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f52c mov r1, #4
 *   @0x12f530 mov r7, r0
 *   @0x12f534 mov r0, r4
 *   @0x12f538 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f53c mov r1, #5
 *   @0x12f540 mov r3, r0
 *   @0x12f544 mov r0, r4
 *   @0x12f548 str r3, [sp, #0x14]
 *   @0x12f54c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f550 mov r1, #6
 *   @0x12f554 mov r11, r0
 *   @0x12f558 mov r0, r4
 *   @0x12f55c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f560 mov r1, #7
 *   @0x12f564 mov r9, r0
 *   @0x12f568 mov r0, r4
 *   @0x12f56c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f570 ldr r3, [sp, #0x14]
 *   @0x12f574 mov r1, r10
 *   @0x12f578 str r9, [sp, #0x8]
 *   @0x12f57c cmp r3, #0
 *   @0x12f580 movle r3, #0
 *   @0x12f584 movgt r3, #1
 *   @0x12f588 cmp r11, #0
 *   @0x12f58c movle r11, #0
 *   @0x12f590 movgt r11, #1
 *   @0x12f594 cmp r8, #0
 *   @0x12f598 stm sp, {r3, r11}
 *   @0x12f59c movle r2, #0
 *   @0x12f5a0 movgt r2, #1
 *   @0x12f5a4 cmp r7, #0
 *   @0x12f5a8 movle r3, #0
 *   @0x12f5ac movgt r3, #1
 *   @0x12f5b0 str r0, [sp, #0xc]
 *   @0x12f5b4 mov r0, r6
 *   @0x12f5b8 bl 0x1f114c <_Z10Sprite_AddPKcibbbbii>
 *   @0x12f5bc vmov s15, r0
 *   @0x12f5c0 vcvt.f64.s32 d7, s15
 *   @0x12f5c4 vmov r0, r1, d7
 *   @0x12f5c8 vmov r2, s14
 *   @0x12f5cc mov r3, r1
 *   @0x12f5d0 stm r5, {r2, r3}
 *   @0x12f5d4 add sp, sp, #28
 *   @0x12f5d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x12f5dc mov r1, r6
 *   @0x12f5e0 mov r0, r4
 *   @0x12f5e4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12f5e8 mov r1, #1
 *   @0x12f5ec mov r7, r0
 *   @0x12f5f0 mov r0, r4
 *   @0x12f5f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f5f8 mov r1, #2
 *   @0x12f5fc mov r9, r0
 *   @0x12f600 mov r0, r4
 *   @0x12f604 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f608 mov r1, #3
 *   @0x12f60c mov r8, r0
 *   @0x12f610 mov r0, r4
 *   @0x12f614 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f618 mov r1, #4
 *   @0x12f61c mov r11, r0
 *   @0x12f620 mov r0, r4
 *   @0x12f624 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f628 mov r1, #5
 *   @0x12f62c mov r10, r0
 *   @0x12f630 mov r0, r4
 *   @0x12f634 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f638 cmp r11, r6
 *   @0x12f63c str r10, [sp, #0x8]
 *   @0x12f640 mov r1, r9
 *   @0x12f644 movle r11, #0
 *   @0x12f648 movgt r11, #1
 *   @0x12f64c cmp r8, r6
 *   @0x12f650 str r11, [sp]
 *   @0x12f654 str r6, [sp, #0x4]
 *   @0x12f658 mov r2, r6
 *   @0x12f65c movle r3, #0
 *   @0x12f660 movgt r3, #1
 *   @0x12f664 str r0, [sp, #0xc]
 *   @0x12f668 mov r0, r7
 *   @0x12f66c b 0x12f5b8 <_Z11F_SpriteAddR6RValueP9CInstanceS2_iPS_+0xf8>
 *
 * ══ §26/70 F_ActionDrawScore(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f1bc  size 432  108 条（0x13f1bc..0x13f36c）
 * @func 0x13f1bc 0x13f37c  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb6538×2 / YYGetFloat(RValue const*, int)×2 / MemoryManager::Free(void const*)×2 / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / 0xb65c8 / 0xb65a4
 * 字段偏移 top8: 0xc×8 / 0x8×2 / 0x54×2 / 0x120×2 / 0x188×1 / 0x184×1 / 0x88×1 / 0x-48×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f1bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13f1c0 vpush {d8}
 *   @0x13f1c4 mov r7, #64
 *   @0x13f1c8 ldr r4, [pc, #0x188]
 *   @0x13f1cc sub sp, sp, #92
 *   @0x13f1d0 ldr r9, [pc, #0x184]
 *   @0x13f1d4 mov r0, r7
 *   @0x13f1d8 ldr r4, [pc, r4]
 *   @0x13f1dc movw r2, #0x5a9
 *   @0x13f1e0 add r9, pc, r9
 *   @0x13f1e4 mov r3, #1
 *   @0x13f1e8 ldr r12, [r4]
 *   @0x13f1ec mov r8, r1
 *   @0x13f1f0 mov r1, r9
 *   @0x13f1f4 ldr r5, [sp, #0x88]
 *   @0x13f1f8 str r7, [sp, #0x8]
 *   @0x13f1fc add r6, sp, #20
 *   @0x13f200 str r12, [sp, #0x54]
 *   @0x13f204 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13f208 add r3, r5, #32
 *   @0x13f20c mov r1, #0
 *   @0x13f210 mov r2, r0
 *   @0x13f214 str r0, [sp, #0xc]
 *   @0x13f218 add r0, sp, #88
 *   @0x13f21c str r2, [r0, #-0x48]!
 *   @0x13f220 strb r1, [r2]
 *   @0x13f224 add r1, sp, #12
 *   @0x13f228 add r2, sp, #8
 *   @0x13f22c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x13f230 ldr r0, [sp, #0xc]
 *   @0x13f234 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x13f238 ldr r3, [pc, #0x120]
 *   @0x13f23c ldr r2, [pc, #0x120]
 *   @0x13f240 mov r1, r7
 *   @0x13f244 ldr r3, [pc, r3]
 *   @0x13f248 mov r0, r6
 *   @0x13f24c add r2, pc, r2
 *   @0x13f250 ldr r3, [r3]
 *   @0x13f254 bl 0xb65c8 <snprintf@plt>
 *   @0x13f258 mov r0, r6
 *   @0x13f25c bl 0xb6538 <strlen@plt>
 *   @0x13f260 ldr r10, [sp, #0xc]
 *   @0x13f264 mov r11, r0
 *   @0x13f268 mov r0, r10
 *   @0x13f26c bl 0xb6538 <strlen@plt>
 *   @0x13f270 ldr r3, [sp, #0x8]
 *   @0x13f274 mov r7, r0
 *   @0x13f278 add r0, r11, r0
 *   @0x13f27c add r0, r0, #1
 *   @0x13f280 cmp r0, r3
 *   @0x13f284 movle r0, r10
 *   @0x13f288 bgt 0x13f320 <_Z17F_ActionDrawScoreR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x13f28c mov r1, r6
 *   @0x13f290 add r0, r0, r7
 *   @0x13f294 bl 0xb65a4 <strcpy@plt>
 *   @0x13f298 mov r1, #0
 *   @0x13f29c mov r0, r5
 *   @0x13f2a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f2a4 mov r1, #1
 *   @0x13f2a8 vmov s16, r0
 *   @0x13f2ac mov r0, r5
 *   @0x13f2b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f2b4 ldr r3, [pc, #0xac]
 *   @0x13f2b8 mvn r1, #0
 *   @0x13f2bc ldr r2, [sp, #0xc]
 *   @0x13f2c0 ldr r3, [pc, r3]
 *   @0x13f2c4 ldrb r3, [r3]
 *   @0x13f2c8 str r1, [sp]
 *   @0x13f2cc cmp r3, #0
 *   @0x13f2d0 vldrne s13, [r8, #180]
 *   @0x13f2d4 vldrne s14, [r8, #184]
 *   @0x13f2d8 mov r3, r1
 *   @0x13f2dc vmov s15, r0
 *   @0x13f2e0 vaddne.f32 s13, s16, s13
 *   @0x13f2e4 vmoveq r0, s16
 *   @0x13f2e8 vmoveq r1, s15
 *   @0x13f2ec vaddne.f32 s14, s15, s14
 *   @0x13f2f0 vmovne r0, s13
 *   @0x13f2f4 vmovne r1, s14
 *   @0x13f2f8 bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x13f2fc ldr r0, [sp, #0xc]
 *   @0x13f300 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13f304 ldr r2, [sp, #0x54]
 *   @0x13f308 ldr r3, [r4]
 *   @0x13f30c cmp r2, r3
 *   @0x13f310 bne 0x13f354 <_Z17F_ActionDrawScoreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x13f314 add sp, sp, #92
 *   @0x13f318 vpop {d8}
 *   @0x13f31c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13f320 mov r3, #1
 *   @0x13f324 mov r1, r9
 *   @0x13f328 movw r2, #0x5b6
 *   @0x13f32c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13f330 ldr r1, [sp, #0xc]
 *   @0x13f334 add r2, r7, #1
 *   @0x13f338 mov r10, r0
 *   @0x13f33c bl 0xb65bc <memcpy@plt>
 *   @0x13f340 ldr r0, [sp, #0xc]
 *   @0x13f344 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13f348 str r10, [sp, #0xc]
 *   @0x13f34c mov r0, r10
 *   @0x13f350 b 0x13f28c <_Z17F_ActionDrawScoreR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x13f354 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13f358 eoreq lr, r10, r8, ror r7
 *   @0x13f35c eoreq r1, r0, r12, lsl #14
 *   @0x13f360 eoreq pc, r10, r0, asr #16
 *   @0x13f364 andseq r3, pc, r0, asr #5
 *   @0x13f368 eoreq lr, r10, r12, ror r8
 *
 * ══ §27/70 F_ActionDrawLife(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f36c  size 432  108 条（0x13f36c..0x13f51c）
 * @func 0x13f36c 0x13f51c  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb6538×2 / YYGetFloat(RValue const*, int)×2 / MemoryManager::Free(void const*)×2 / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / 0xb65c8 / 0xb65a4
 * 字段偏移 top8: 0xc×8 / 0x8×2 / 0x54×2 / 0x120×2 / 0x188×1 / 0x184×1 / 0x88×1 / 0x-48×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f36c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13f370 vpush {d8}
 *   @0x13f374 mov r12, #16
 *   @0x13f378 ldr r4, [pc, #0x188]
 *   @0x13f37c sub sp, sp, #92
 *   @0x13f380 ldr r9, [pc, #0x184]
 *   @0x13f384 mov r0, r12
 *   @0x13f388 ldr r4, [pc, r4]
 *   @0x13f38c movw r2, #0x608
 *   @0x13f390 add r9, pc, r9
 *   @0x13f394 mov r3, #1
 *   @0x13f398 ldr lr, [r4]
 *   @0x13f39c mov r7, r1
 *   @0x13f3a0 mov r1, r9
 *   @0x13f3a4 str r12, [sp, #0x8]
 *   @0x13f3a8 ldr r5, [sp, #0x88]
 *   @0x13f3ac add r6, sp, #20
 *   @0x13f3b0 str lr, [sp, #0x54]
 *   @0x13f3b4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13f3b8 add r3, r5, #32
 *   @0x13f3bc mov r1, #0
 *   @0x13f3c0 mov r2, r0
 *   @0x13f3c4 str r0, [sp, #0xc]
 *   @0x13f3c8 add r0, sp, #88
 *   @0x13f3cc str r2, [r0, #-0x48]!
 *   @0x13f3d0 strb r1, [r2]
 *   @0x13f3d4 add r1, sp, #12
 *   @0x13f3d8 add r2, sp, #8
 *   @0x13f3dc bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x13f3e0 ldr r0, [sp, #0xc]
 *   @0x13f3e4 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x13f3e8 ldr r3, [pc, #0x120]
 *   @0x13f3ec ldr r2, [pc, #0x120]
 *   @0x13f3f0 mov r1, #64
 *   @0x13f3f4 ldr r3, [pc, r3]
 *   @0x13f3f8 mov r0, r6
 *   @0x13f3fc add r2, pc, r2
 *   @0x13f400 ldr r3, [r3]
 *   @0x13f404 bl 0xb65c8 <snprintf@plt>
 *   @0x13f408 mov r0, r6
 *   @0x13f40c bl 0xb6538 <strlen@plt>
 *   @0x13f410 ldr r10, [sp, #0xc]
 *   @0x13f414 mov r11, r0
 *   @0x13f418 mov r0, r10
 *   @0x13f41c bl 0xb6538 <strlen@plt>
 *   @0x13f420 ldr r3, [sp, #0x8]
 *   @0x13f424 mov r8, r0
 *   @0x13f428 add r0, r11, r0
 *   @0x13f42c add r0, r0, #1
 *   @0x13f430 cmp r0, r3
 *   @0x13f434 movle r0, r10
 *   @0x13f438 bgt 0x13f4d0 <_Z16F_ActionDrawLifeR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x13f43c mov r1, r6
 *   @0x13f440 add r0, r0, r8
 *   @0x13f444 bl 0xb65a4 <strcpy@plt>
 *   @0x13f448 mov r1, #0
 *   @0x13f44c mov r0, r5
 *   @0x13f450 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f454 mov r1, #1
 *   @0x13f458 vmov s16, r0
 *   @0x13f45c mov r0, r5
 *   @0x13f460 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f464 ldr r3, [pc, #0xac]
 *   @0x13f468 mvn r1, #0
 *   @0x13f46c ldr r2, [sp, #0xc]
 *   @0x13f470 ldr r3, [pc, r3]
 *   @0x13f474 ldrb r3, [r3]
 *   @0x13f478 str r1, [sp]
 *   @0x13f47c cmp r3, #0
 *   @0x13f480 vldrne s13, [r7, #180]
 *   @0x13f484 vldrne s14, [r7, #184]
 *   @0x13f488 mov r3, r1
 *   @0x13f48c vmov s15, r0
 *   @0x13f490 vaddne.f32 s13, s16, s13
 *   @0x13f494 vmoveq r0, s16
 *   @0x13f498 vmoveq r1, s15
 *   @0x13f49c vaddne.f32 s14, s15, s14
 *   @0x13f4a0 vmovne r0, s13
 *   @0x13f4a4 vmovne r1, s14
 *   @0x13f4a8 bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x13f4ac ldr r0, [sp, #0xc]
 *   @0x13f4b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13f4b4 ldr r2, [sp, #0x54]
 *   @0x13f4b8 ldr r3, [r4]
 *   @0x13f4bc cmp r2, r3
 *   @0x13f4c0 bne 0x13f504 <_Z16F_ActionDrawLifeR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x13f4c4 add sp, sp, #92
 *   @0x13f4c8 vpop {d8}
 *   @0x13f4cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13f4d0 mov r3, #1
 *   @0x13f4d4 mov r1, r9
 *   @0x13f4d8 movw r2, #0x615
 *   @0x13f4dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13f4e0 ldr r1, [sp, #0xc]
 *   @0x13f4e4 add r2, r8, #1
 *   @0x13f4e8 mov r10, r0
 *   @0x13f4ec bl 0xb65bc <memcpy@plt>
 *   @0x13f4f0 ldr r0, [sp, #0xc]
 *   @0x13f4f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13f4f8 str r10, [sp, #0xc]
 *   @0x13f4fc mov r0, r10
 *   @0x13f500 b 0x13f43c <_Z16F_ActionDrawLifeR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x13f504 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13f508 eoreq lr, r10, r8, asr #11
 *   @0x13f50c eoreq r1, r0, r12, asr r5
 *   @0x13f510 .word 0x002affdc
 *   @0x13f514 andseq r3, pc, r0, lsl r1
 *   @0x13f518 eoreq lr, r10, r12, asr #13
 *
 * ══ §28/70 GR_D3D_Init(void*, int, int, int)  0x16973c  size 432  108 条（0x16973c..0x1698ec）
 * @func 0x16973c 0x1698ec  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16976c→0x3f238c, 0x169788→0x3f2388, 0x169834→0x4859c8, 0x169858→0x3f26c0, 0x16985c→0x3f26bc
 * 调用序列: Graphics_DisplayWidth()×2 / Graphics_DisplayHeight()×2 / DisplayColorDepth()×2 / GR_D3D_Init(void*, int, int, int)+0x18c / GR_D3D_Init(void*, int, int, int)+0x184 / ShowMessage(char const*) / Graphics::OpenWindow(void*, int, int, int) / Graphics::SetMatrix(eMatrix, float*)
 * 字段偏移 top8: 0x84×2 / 0x170×1 / 0x160×1 / 0x148×1 / 0x128×1 / 0x40×1 / 0x44×1 / 0x30×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16973c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x169740 sub sp, sp, #72
 *   @0x169744 mov r6, r1
 *   @0x169748 mov r10, r0
 *   @0x16974c mov r4, r2
 *   @0x169750 mov r9, r3
 *   @0x169754 bl 0x17db24 <_Z21Graphics_DisplayWidthv>
 *   @0x169758 ldr r5, [pc, #0x170]
 *   @0x16975c add r5, pc, r5
 *   @0x169760 cmp r0, r6
 *   @0x169764 movgt r0, r6
 *   @0x169768 ble 0x1698c8 <_Z11GR_D3D_InitPviii+0x18c>
 *   @0x16976c ldr r3, [pc, #0x160]
 *   @0x169770 ldr r8, [r5, r3]
 *   @0x169774 str r0, [r8]
 *   @0x169778 bl 0x17db38 <_Z22Graphics_DisplayHeightv>
 *   @0x16977c cmp r0, r4
 *   @0x169780 movgt r0, r4
 *   @0x169784 ble 0x1698c0 <_Z11GR_D3D_InitPviii+0x184>
 *   @0x169788 ldr r3, [pc, #0x148]
 *   @0x16978c ldr r7, [r5, r3]
 *   @0x169790 str r0, [r7]
 *   @0x169794 bl 0x17db54 <_Z17DisplayColorDepthv>
 *   @0x169798 cmp r0, #16
 *   @0x16979c beq 0x1697c4 <_Z11GR_D3D_InitPviii+0x88>
 *   @0x1697a0 bl 0x17db54 <_Z17DisplayColorDepthv>
 *   @0x1697a4 cmp r0, #32
 *   @0x1697a8 beq 0x1697c4 <_Z11GR_D3D_InitPviii+0x88>
 *   @0x1697ac ldr r0, [pc, #0x128]
 *   @0x1697b0 add r0, pc, r0
 *   @0x1697b4 bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x1697b8 mov r0, #0
 *   @0x1697bc add sp, sp, #72
 *   @0x1697c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1697c4 ldr r2, [r7]
 *   @0x1697c8 mov r3, r9
 *   @0x1697cc ldr r1, [r8]
 *   @0x1697d0 mov r0, r10
 *   @0x1697d4 bl 0x17dbcc <_ZN8Graphics10OpenWindowEPviii>
 *   @0x1697d8 add r1, sp, #8
 *   @0x1697dc mov r4, #0
 *   @0x1697e0 mov r6, #1065353216
 *   @0x1697e4 str r4, [sp, #0x40]
 *   @0x1697e8 str r6, [sp, #0x44]
 *   @0x1697ec str r6, [sp, #0x30]
 *   @0x1697f0 str r6, [sp, #0x1c]
 *   @0x1697f4 str r6, [sp, #0x8]
 *   @0x1697f8 str r4, [sp, #0x3c]
 *   @0x1697fc str r4, [sp, #0x38]
 *   @0x169800 str r4, [sp, #0x34]
 *   @0x169804 str r4, [sp, #0x2c]
 *   @0x169808 str r4, [sp, #0x28]
 *   @0x16980c str r4, [sp, #0x24]
 *   @0x169810 str r4, [sp, #0x20]
 *   @0x169814 str r4, [sp, #0x18]
 *   @0x169818 str r4, [sp, #0x14]
 *   @0x16981c str r4, [sp, #0x10]
 *   @0x169820 str r4, [sp, #0xc]
 *   @0x169824 mov r7, r0
 *   @0x169828 mov r0, #2
 *   @0x16982c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x169830 bl 0x173db0 <_Z15GR_Texture_Initv>
 *   @0x169834 ldr r3, [pc, #0xa4]
 *   @0x169838 ldr r0, [r5, r3]
 *   @0x16983c bl 0x167c34 <_ZN18RenderStateManager5ResetEv>
 *   @0x169840 bl 0x168a50 <_Z20GR_D3D_Settings_Initv>
 *   @0x169844 mov r0, #0
 *   @0x169848 mov r1, r6
 *   @0x16984c mov r2, r0
 *   @0x169850 mov r3, #7
 *   @0x169854 bl 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags>
 *   @0x169858 ldr r2, [pc, #0x84]
 *   @0x16985c ldr r3, [pc, #0x84]
 *   @0x169860 mov r0, #0
 *   @0x169864 mov r1, r0
 *   @0x169868 ldr r6, [r5, r2]
 *   @0x16986c ldr r5, [r5, r3]
 *   @0x169870 ldr r2, [r6]
 *   @0x169874 ldr r3, [r5]
 *   @0x169878 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii>
 *   @0x16987c ldr r2, [r6]
 *   @0x169880 str r4, [sp]
 *   @0x169884 mov r0, r4
 *   @0x169888 ldr r3, [r5]
 *   @0x16988c mov r1, r4
 *   @0x169890 vmov s15, r2
 *   @0x169894 vcvt.f32.s32 s15, s15
 *   @0x169898 vmov r2, s15
 *   @0x16989c vmov s15, r3
 *   @0x1698a0 vcvt.f32.s32 s15, s15
 *   @0x1698a4 vmov r3, s15
 *   @0x1698a8 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff>
 *   @0x1698ac bl 0x17f38c <_ZN8Graphics4InitEv>
 *   @0x1698b0 bl 0x168b64 <_Z19_CreateBlankTexturev>
 *   @0x1698b4 mov r0, r7
 *   @0x1698b8 add sp, sp, #72
 *   @0x1698bc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1698c0 bl 0x17db38 <_Z22Graphics_DisplayHeightv>
 *   @0x1698c4 b 0x169788 <_Z11GR_D3D_InitPviii+0x4c>
 *   @0x1698c8 bl 0x17db24 <_Z21Graphics_DisplayWidthv>
 *   @0x1698cc b 0x16976c <_Z11GR_D3D_InitPviii+0x30>
 *   @0x1698d0 .word 0x002884f4
 *   @0x1698d4 .word 0xffffe4e4
 *   @0x1698d8 .word 0xffffe4e8
 *   @0x1698dc andseq r1, lr, r8
 *   @0x1698e0 .word 0xffffc0a8
 *   @0x1698e4 .word 0xffffe24c
 *   @0x1698e8 .word 0xffffe250
 *
 * ══ §29/70 F_LayerAddInstance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c6cf4  size 432  108 条（0x1c6cf4..0x1c6ea4）
 * @func 0x1c6cf4 0x1c6eb4  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / CLayerManager::GetLayerFromID(CRoom*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerIDForInstance(CRoom*, int) / CLayerManager::RemoveStorageInstanceFromLayer(CRoom*, CLayer*, int) / CLayerManager::GetNewInstanceElement() / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x4×3 / 0x1c×2 / 0x10×1 / 0x16c×1 / 0x120×1 / 0x8c×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c6cf4 cmp r3, #2
 *   @0x1c6cf8 mov r3, #0
 *   @0x1c6cfc push {r4, r5, r6, lr}
 *   @0x1c6d00 mov r4, r3
 *   @0x1c6d04 ldr r6, [sp, #0x10]
 *   @0x1c6d08 movt r3, #0xbff0
 *   @0x1c6d0c str r4, [r0, #0xc]
 *   @0x1c6d10 str r3, [r0, #0x4]
 *   @0x1c6d14 str r4, [r0]
 *   @0x1c6d18 beq 0x1c6d30 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1c6d1c ldr r0, [pc, #0x16c]
 *   @0x1c6d20 mov r1, r4
 *   @0x1c6d24 pop {r4, r5, r6, lr}
 *   @0x1c6d28 add r0, pc, r0
 *   @0x1c6d2c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c6d30 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c6d34 ldr r3, [r6, #0xc]
 *   @0x1c6d38 mov r1, r4
 *   @0x1c6d3c bic r3, r3, #-16777216
 *   @0x1c6d40 cmp r3, #1
 *   @0x1c6d44 mov r5, r0
 *   @0x1c6d48 mov r0, r6
 *   @0x1c6d4c beq 0x1c6de0 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1c6d50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c6d54 mov r1, r0
 *   @0x1c6d58 mov r0, r5
 *   @0x1c6d5c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c6d60 mov r4, r0
 *   @0x1c6d64 cmp r4, #0
 *   @0x1c6d68 beq 0x1c6e7c <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x1c6d6c ldr r3, [pc, #0x120]
 *   @0x1c6d70 mov r0, r6
 *   @0x1c6d74 mov r1, #1
 *   @0x1c6d78 ldr r3, [pc, r3]
 *   @0x1c6d7c ldr r3, [r3]
 *   @0x1c6d80 cmp r5, r3
 *   @0x1c6d84 beq 0x1c6df8 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x1c6d88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c6d8c mov r6, r0
 *   @0x1c6d90 mov r0, r5
 *   @0x1c6d94 mov r1, r6
 *   @0x1c6d98 bl 0x1b8cb8 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi>
 *   @0x1c6d9c cmn r0, #1
 *   @0x1c6da0 beq 0x1c6dc0 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x1c6da4 mov r1, r0
 *   @0x1c6da8 mov r0, r5
 *   @0x1c6dac bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c6db0 mov r2, r6
 *   @0x1c6db4 mov r1, r0
 *   @0x1c6db8 mov r0, r5
 *   @0x1c6dbc bl 0x1b9ea4 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri>
 *   @0x1c6dc0 bl 0x1c0cdc <_ZN13CLayerManager21GetNewInstanceElementEv>
 *   @0x1c6dc4 mov r1, r4
 *   @0x1c6dc8 mov r3, #0
 *   @0x1c6dcc str r6, [r0, #0x1c]
 *   @0x1c6dd0 mov r2, r0
 *   @0x1c6dd4 mov r0, r5
 *   @0x1c6dd8 pop {r4, r5, r6, lr}
 *   @0x1c6ddc b 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1c6de0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c6de4 mov r1, r0
 *   @0x1c6de8 mov r0, r5
 *   @0x1c6dec bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c6df0 mov r4, r0
 *   @0x1c6df4 b 0x1c6d64 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1c6df8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c6dfc cmp r0, #0
 *   @0x1c6e00 blt 0x1c6e24 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x1c6e04 ldr r3, [pc, #0x8c]
 *   @0x1c6e08 ldr r3, [pc, r3]
 *   @0x1c6e0c ldr r2, [r3, #0x4]
 *   @0x1c6e10 ldr r3, [r3]
 *   @0x1c6e14 and r2, r0, r2
 *   @0x1c6e18 ldr r3, [r3, r2, lsl #3]
 *   @0x1c6e1c cmp r3, #0
 *   @0x1c6e20 bne 0x1c6e44 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x1c6e24 ldr r0, [pc, #0x70]
 *   @0x1c6e28 mov r1, #0
 *   @0x1c6e2c pop {r4, r5, r6, lr}
 *   @0x1c6e30 add r0, pc, r0
 *   @0x1c6e34 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c6e38 ldr r3, [r3, #0x4]
 *   @0x1c6e3c cmp r3, #0
 *   @0x1c6e40 beq 0x1c6e24 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x1c6e44 ldr r2, [r3, #0x8]
 *   @0x1c6e48 cmp r0, r2
 *   @0x1c6e4c bne 0x1c6e38 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1c6e50 ldr r6, [r3, #0xc]
 *   @0x1c6e54 cmp r6, #0
 *   @0x1c6e58 beq 0x1c6e24 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x1c6e5c mov r0, r5
 *   @0x1c6e60 mov r1, r6
 *   @0x1c6e64 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance>
 *   @0x1c6e68 mov r0, r5
 *   @0x1c6e6c mov r1, r4
 *   @0x1c6e70 mov r2, r6
 *   @0x1c6e74 pop {r4, r5, r6, lr}
 *   @0x1c6e78 b 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance>
 *   @0x1c6e7c ldr r0, [pc, #0x1c]
 *   @0x1c6e80 mov r1, r4
 *   @0x1c6e84 pop {r4, r5, r6, lr}
 *   @0x1c6e88 add r0, pc, r0
 *   @0x1c6e8c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c6e90 andseq r9, r8, r12, ror #22
 *   @0x1c6e94 .word 0x00226bb0
 *   @0x1c6e98 eoreq r6, r2, r12, lsr lr
 *   @0x1c6e9c andseq r9, r8, r0, ror #21
 *   @0x1c6ea0 andseq r9, r8, r0, asr #20
 *
 * ══ §30/70 EncodeScore(char const*&, char const*, int)  0x1dbe98  size 432  108 条（0x1dbe98..0x1dc048）
 * @func 0x1dbe98 0x1dc048  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / 0xb6538 / EncodeScore(char const*&, char const*, int)+0xb4 / EncodeScore(char const*&, char const*, int)+0x178 / YYStrDup(char const*) / 0xb65d4
 * 字段偏移 top8: 0x4×5 / 0x-7fc×2 / 0x198×1 / 0x1×1 / 0xec×1 / 0x-2×1 / 0x-1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dbe98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dbe9c sub sp, sp, #6144
 *   @0x1dbea0 ldr r4, [pc, #0x198]
 *   @0x1dbea4 sub sp, sp, #12
 *   @0x1dbea8 add r12, sp, #8192
 *   @0x1dbeac add r10, sp, #8
 *   @0x1dbeb0 ldr r4, [pc, r4]
 *   @0x1dbeb4 mov r5, r0
 *   @0x1dbeb8 mov r11, r1
 *   @0x1dbebc mov r6, r2
 *   @0x1dbec0 ldr r3, [r4]
 *   @0x1dbec4 movw r2, #0x401
 *   @0x1dbec8 mov r0, sp
 *   @0x1dbecc mov r1, #0
 *   @0x1dbed0 sub r7, r10, #8
 *   @0x1dbed4 mov r9, sp
 *   @0x1dbed8 str r3, [r12, #-0x7fc]
 *   @0x1dbedc bl 0xb65b0 <memset@plt>
 *   @0x1dbee0 add r2, r10, #56
 *   @0x1dbee4 asr r12, r6, #31
 *   @0x1dbee8 cmp r6, #0
 *   @0x1dbeec add r3, r6, #255
 *   @0x1dbef0 lsr r12, r12, #24
 *   @0x1dbef4 movge r3, r6
 *   @0x1dbef8 add lr, r6, r12
 *   @0x1dbefc asr r6, r3, #8
 *   @0x1dbf00 uxtb lr, lr
 *   @0x1dbf04 rsb r12, r12, lr
 *   @0x1dbf08 str r12, [r9, #0x4]!
 *   @0x1dbf0c cmp r9, r2
 *   @0x1dbf10 bne 0x1dbee4 <_Z11EncodeScoreRPKcS0_i+0x4c>
 *   @0x1dbf14 cmp r11, #0
 *   @0x1dbf18 moveq r8, #16
 *   @0x1dbf1c beq 0x1dbf50 <_Z11EncodeScoreRPKcS0_i+0xb8>
 *   @0x1dbf20 mov r0, r11
 *   @0x1dbf24 bl 0xb6538 <strlen@plt>
 *   @0x1dbf28 cmp r0, #0
 *   @0x1dbf2c subgt r2, r11, #1
 *   @0x1dbf30 addgt r3, r10, #56
 *   @0x1dbf34 addgt r12, r9, r0, lsl #2
 *   @0x1dbf38 ble 0x1dbf4c <_Z11EncodeScoreRPKcS0_i+0xb4>
 *   @0x1dbf3c ldrb r1, [r2, #0x1]!
 *   @0x1dbf40 str r1, [r3, #0x4]!
 *   @0x1dbf44 cmp r3, r12
 *   @0x1dbf48 bne 0x1dbf3c <_Z11EncodeScoreRPKcS0_i+0xa4>
 *   @0x1dbf4c add r8, r0, #16
 *   @0x1dbf50 ldr r1, [pc, #0xec]
 *   @0x1dbf54 mov r2, r7
 *   @0x1dbf58 mov r3, #1
 *   @0x1dbf5c movw r0, #0x401
 *   @0x1dbf60 ldr r1, [pc, r1]
 *   @0x1dbf64 ldr r1, [r1]
 *   @0x1dbf68 ldr lr, [r2, #0x4]
 *   @0x1dbf6c add lr, r3, lr
 *   @0x1dbf70 add r3, r3, #1
 *   @0x1dbf74 add lr, lr, r1
 *   @0x1dbf78 cmp r3, r0
 *   @0x1dbf7c asr r12, lr, #31
 *   @0x1dbf80 lsr r12, r12, #24
 *   @0x1dbf84 add lr, lr, r12
 *   @0x1dbf88 uxtb lr, lr
 *   @0x1dbf8c rsb r12, r12, lr
 *   @0x1dbf90 str r12, [r2, #0x4]!
 *   @0x1dbf94 bne 0x1dbf68 <_Z11EncodeScoreRPKcS0_i+0xd0>
 *   @0x1dbf98 add r6, sp, #4096
 *   @0x1dbf9c mov r1, #0
 *   @0x1dbfa0 add r6, r6, #8
 *   @0x1dbfa4 str r1, [r5]
 *   @0x1dbfa8 sub r6, r6, #4
 *   @0x1dbfac mov r2, #2048
 *   @0x1dbfb0 mov r0, r6
 *   @0x1dbfb4 bl 0xb65b0 <memset@plt>
 *   @0x1dbfb8 cmp r8, #0
 *   @0x1dbfbc addgt lr, r7, r8, lsl #2
 *   @0x1dbfc0 movgt r1, r7
 *   @0x1dbfc4 movgt r2, r6
 *   @0x1dbfc8 ble 0x1dc010 <_Z11EncodeScoreRPKcS0_i+0x178>
 *   @0x1dbfcc ldr r3, [r1, #0x4]!
 *   @0x1dbfd0 add r2, r2, #2
 *   @0x1dbfd4 cmp r3, #0
 *   @0x1dbfd8 add r0, r3, #15
 *   @0x1dbfdc asr r12, r3, #31
 *   @0x1dbfe0 movge r0, r3
 *   @0x1dbfe4 cmp r1, lr
 *   @0x1dbfe8 lsr r12, r12, #28
 *   @0x1dbfec asr r0, r0, #4
 *   @0x1dbff0 add r3, r3, r12
 *   @0x1dbff4 add r0, r0, #65
 *   @0x1dbff8 and r3, r3, #15
 *   @0x1dbffc strb r0, [r2, #-0x2]
 *   @0x1dc000 rsb r12, r12, r3
 *   @0x1dc004 add r12, r12, #65
 *   @0x1dc008 strb r12, [r2, #-0x1]
 *   @0x1dc00c bne 0x1dbfcc <_Z11EncodeScoreRPKcS0_i+0x134>
 *   @0x1dc010 mov r0, r6
 *   @0x1dc014 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1dc018 add r2, sp, #8192
 *   @0x1dc01c ldr r3, [r2, #-0x7fc]
 *   @0x1dc020 str r0, [r5]
 *   @0x1dc024 ldr r2, [r4]
 *   @0x1dc028 cmp r3, r2
 *   @0x1dc02c bne 0x1dc03c <_Z11EncodeScoreRPKcS0_i+0x1a4>
 *   @0x1dc030 add sp, sp, #6144
 *   @0x1dc034 add sp, sp, #12
 *   @0x1dc038 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dc03c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1dc040 eoreq r1, r1, r0, lsr #21
 *   @0x1dc044 .word 0x00214bb4
 *
 * ══ §31/70 Audio_SoundPitch(int, float)  0x217460  size 432  101 条（0x217460..0x217610）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x217460 0x217610  size 432  101 条
 * 部分覆盖: 本节 101/108 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x217474→0x755363, 0x21748c→0x755314, 0x2174b4→0x3f52d0, 0x217554→0x75531c, 0x2175b0→0x75531c
 * 调用序列: Audio_SoundPitch(int, float)+0x12c×2 / Audio_SoundPitch(int, float)+0x134 / Audio_GetSound(int) / 0xb6a78 / Audio_GetNoiseFromID(int) / 0x21fd280
 * 字段偏移 top8: 0x38×3 / 0x10×2 / 0x2×2 / 0x17c×1 / 0x178×1 / 0x164×1 / 0x140×1 / 0x128×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217460 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x217464 vpush {d8}
 *   @0x217468 mov r6, r0
 *   @0x217488 bne 0x21758c <_Z16Audio_SoundPitchif+0x12c>
 *   @0x21748c ldr r3, [pc, #0x164]
 *   @0x217490 ldr r3, [r5, r3]
 *   @0x217494 ldrb r3, [r3]
 *   @0x217498 cmp r3, #0
 *   @0x21749c beq 0x21758c <_Z16Audio_SoundPitchif+0x12c>
 *   @0x2174a0 vldr s15, [pc, #320]
 *   @0x2174a4 vcmpe.f32 s16, s15
 *   @0x2174a8 vmrs APSR_nzcv, fpscr
 *   @0x2174ac vmovmi.f32 s16, s15
 *   @0x2174b0 bpl 0x2175d4 <_Z16Audio_SoundPitchif+0x174>
 *   @0x2174b4 ldr r3, [pc, #0x140]
 *   @0x2174b8 mov r0, r6
 *   @0x2174bc ldr r3, [r5, r3]
 *   @0x2174c0 ldr r3, [r3]
 *   @0x2174c4 cmp r3, r6
 *   @0x2174c8 ble 0x217594 <_Z16Audio_SoundPitchif+0x134>
 *   @0x2174cc bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x2174d0 ldr r3, [pc, #0x128]
 *   @0x2174d4 add r3, pc, r3
 *   @0x2174d8 ldr r7, [r3, #0x38]
 *   @0x2174dc cmp r0, #0
 *   @0x2174e0 vstrne s16, [r0, #8]
 *   @0x2174e4 cmp r7, #0
 *   @0x2174e8 ble 0x21758c <_Z16Audio_SoundPitchif+0x12c>
 *   @0x2174ec ldr r9, [pc, #0x110]
 *   @0x2174f0 mov r3, r7
 *   @0x2174f4 ldr r8, [pc, #0x10c]
 *   @0x2174f8 mov r4, #0
 *   @0x2174fc add r9, pc, r9
 *   @0x217500 add r8, pc, r8
 *   @0x217504 b 0x217518 <_Z16Audio_SoundPitchif+0xb8>
 *   @0x217508 add r4, r4, #1
 *   @0x21750c cmp r4, r7
 *   @0x217510 beq 0x21758c <_Z16Audio_SoundPitchif+0x12c>
 *   @0x217514 ldr r3, [r8, #0x38]
 *   @0x217518 cmp r4, r3
 *   @0x21751c ldrlt r3, [r9, #0x3c]
 *   @0x217520 movge r3, #0
 *   @0x217524 ldrlt r3, [r3, r4, lsl #2]
 *   @0x217528 ldr r2, [r3, #0x18]
 *   @0x21752c cmp r2, r6
 *   @0x217530 bne 0x217508 <_Z16Audio_SoundPitchif+0xa8>
 *   @0x217534 ldrb r2, [r3, #0x5]
 *   @0x217538 cmp r2, #0
 *   @0x21753c beq 0x217508 <_Z16Audio_SoundPitchif+0xa8>
 *   @0x217540 ldr r2, [r3, #0x8]
 *   @0x217544 cmp r2, #0
 *   @0x217548 bne 0x217508 <_Z16Audio_SoundPitchif+0xa8>
 *   @0x21754c ldr r2, [r3, #0x38]
 *   @0x217550 movw r1, #0x1003
 *   @0x217554 ldr r12, [pc, #0xb0]
 *   @0x217558 add r4, r4, #1
 *   @0x21755c cmp r2, #0
 *   @0x217560 vldrne s15, [r2, #44]
 *   @0x217564 ldr r0, [r3, #0x10]
 *   @0x217568 vmulne.f32 s15, s16, s15
 *   @0x21756c ldr r3, [r5, r12]
 *   @0x217570 ldr r3, [r3]
 *   @0x217574 ldr r0, [r3, r0, lsl #2]
 *   @0x217578 vmoveq.f32 s15, s16
 *   @0x21757c vmov r2, s15
 *   @0x217580 bl 0xb6a78 <alSourcef@plt>
 *   @0x217584 cmp r4, r7
 *   @0x217588 bne 0x217514 <_Z16Audio_SoundPitchif+0xb4>
 *   @0x21758c vpop {d8}
 *   @0x217590 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x217594 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x217598 cmp r0, #0
 *   @0x21759c beq 0x21758c <_Z16Audio_SoundPitchif+0x12c>
 *   @0x2175a0 ldr r3, [r0, #0x10]
 *   @0x2175a4 vstr s16, [r0, #32]
 *   @0x2175a8 cmp r3, #0
 *   @0x2175ac blt 0x21758c <_Z16Audio_SoundPitchif+0x12c>
 *   @0x2175b0 ldr r0, [pc, #0x54]
 *   @0x2175b4 movw r1, #0x1003
 *   @0x2175b8 vmov r2, s16
 *   @0x2175bc vpop {d8}
 *   @0x2175c0 ldr r0, [r5, r0]
 *   @0x2175c4 ldr r0, [r0]
 *   @0x2175c8 ldr r0, [r0, r3, lsl #2]
 *   @0x2175cc pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2175d0 b 0xb6a78 <alSourcef@plt>
 *   @0x2175d4 vldr s15, [pc, #16]
 *   @0x2175d8 vcmp.f32 s16, s15
 *   @0x2175dc vmrs APSR_nzcv, fpscr
 *   @0x2175e0 vmovgt.f32 s16, s15
 *   @0x2175e4 b 0x2174b4 <_Z16Audio_SoundPitchif+0x54>
 *   @0x2175e8 bllo 0x21fd280 <b2_toiTime+0x1aa3ddc>
 *   @0x2175ec orrmi r0, r0, #0
 *   @0x2175f0 ldrsbeq r10, [sp], -r8
 *   @0x2175f4 .word 0xffffd3fc
 *   @0x2175f8 .word 0xffffd0e0
 *   @0x2175fc .word 0xfffff794
 *   @0x217600 subseq sp, r3, r0, asr #27
 *   @0x217604 .word 0x0053dd98
 *   @0x217608 .word 0x0053dd94
 *   @0x21760c .word 0xfffff77c
 *
 * ══ §32/70 JS_Array_prototype_some(RValue&, CInstance*, CInstance*, int, RValue*)  0x25158c  size 432  108 条（0x25158c..0x25173c）
 * @func 0x25158c 0x25173c  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×3 / JSThrowTypeError(char const*)×2 / JS_Array_prototype_some(RValue&, CInstance*, CInstance*, int, RValue*)+0x60 / JS_IsCallable(RValue&) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*) / JS_ToBoolean(RValue&)
 * 字段偏移 top8: 0xc×5 / 0x4×5 / 0x78×2 / 0x24×1 / 0x140×1 / 0x3c×1 / 0x4c×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25158c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x251590 sub sp, sp, #84
 *   @0x251594 mov r4, r3
 *   @0x251598 mov r3, #13
 *   @0x25159c str r0, [sp, #0xc]
 *   @0x2515a0 mov r0, #0
 *   @0x2515a4 ldr r12, [sp, #0xc]
 *   @0x2515a8 mov r2, r0
 *   @0x2515ac movt r2, #0x3ff0
 *   @0x2515b0 str r0, [r12]
 *   @0x2515b4 str r2, [r12, #0x4]
 *   @0x2515b8 ldr r2, [r1, #0x4]
 *   @0x2515bc str r3, [r12, #0xc]
 *   @0x2515c0 cmp r2, r0
 *   @0x2515c4 beq 0x251724 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x2515c8 add r0, r2, #16
 *   @0x2515cc ldr r6, [r0]
 *   @0x2515d0 cmp r4, #0
 *   @0x2515d4 ldr r8, [r6, #0x24]
 *   @0x2515d8 ble 0x2515ec <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x2515dc ldr r0, [sp, #0x78]
 *   @0x2515e0 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x2515e4 cmp r0, #0
 *   @0x2515e8 bne 0x251600 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x2515ec ldr r0, [pc, #0x140]
 *   @0x2515f0 add r0, pc, r0
 *   @0x2515f4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2515f8 add sp, sp, #84
 *   @0x2515fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251600 cmp r4, #1
 *   @0x251604 moveq r12, #0
 *   @0x251608 streq r12, [sp, #0x8]
 *   @0x25160c ldrne r12, [sp, #0x78]
 *   @0x251610 ldrne r12, [r12, #0x10]
 *   @0x251614 strne r12, [sp, #0x8]
 *   @0x251618 cmp r8, #0
 *   @0x25161c beq 0x2516f8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x251620 mov r10, #0
 *   @0x251624 add r5, sp, #32
 *   @0x251628 add r7, sp, #16
 *   @0x25162c mov r4, r10
 *   @0x251630 mov r11, r10
 *   @0x251634 mvn r9, #-16777216
 *   @0x251638 b 0x2516cc <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x25163c add r0, r0, r10
 *   @0x251640 ldr r3, [r0, #0xc]
 *   @0x251644 bic r3, r3, #-16777216
 *   @0x251648 cmp r3, r9
 *   @0x25164c beq 0x2516bc <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x251650 ldr r0, [r6, #0x4]
 *   @0x251654 cmp r0, #0
 *   @0x251658 beq 0x2516e8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x25165c add r0, r0, r10
 *   @0x251660 vmov s13, r4
 *   @0x251664 mov r12, #6
 *   @0x251668 ldm r0, {r0, r1, r2, r3}
 *   @0x25166c vcvt.f64.u32 d7, s13
 *   @0x251670 str r5, [sp]
 *   @0x251674 str r11, [sp, #0x3c]
 *   @0x251678 str r12, [sp, #0x4c]
 *   @0x25167c stm r5, {r0, r1, r2, r3}
 *   @0x251680 mov r1, r7
 *   @0x251684 ldr r0, [sp, #0x8]
 *   @0x251688 mov r3, #3
 *   @0x25168c ldr r2, [sp, #0x78]
 *   @0x251690 vstr d7, [sp, #48]
 *   @0x251694 str r6, [sp, #0x40]
 *   @0x251698 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x25169c cmp r0, #2
 *   @0x2516a0 beq 0x2515f8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x2516a4 cmp r0, #1
 *   @0x2516a8 beq 0x251710 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x2516ac mov r0, r7
 *   @0x2516b0 bl 0x2404bc <_Z12JS_ToBooleanR6RValue>
 *   @0x2516b4 cmp r0, #0
 *   @0x2516b8 bne 0x2515f8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x2516bc add r4, r4, #1
 *   @0x2516c0 add r10, r10, #16
 *   @0x2516c4 cmp r4, r8
 *   @0x2516c8 beq 0x2516f8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x2516cc ldr r0, [r6, #0x4]
 *   @0x2516d0 cmp r0, #0
 *   @0x2516d4 bne 0x25163c <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x2516d8 mov r0, r6
 *   @0x2516dc mov r1, r4
 *   @0x2516e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2516e4 b 0x251640 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x2516e8 mov r0, r6
 *   @0x2516ec mov r1, r4
 *   @0x2516f0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2516f4 b 0x251660 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x2516f8 ldr r12, [sp, #0xc]
 *   @0x2516fc mov r3, #0
 *   @0x251700 str r3, [r12]
 *   @0x251704 str r3, [r12, #0x4]
 *   @0x251708 add sp, sp, #84
 *   @0x25170c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251710 ldr r0, [pc, #0x20]
 *   @0x251714 add r0, pc, r0
 *   @0x251718 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25171c add sp, sp, #84
 *   @0x251720 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251724 mov r0, r1
 *   @0x251728 mov r1, #1
 *   @0x25172c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251730 b 0x2515cc <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x251734 andseq r4, r0, r4, lsr #25
 *   @0x251738 andseq r4, r0, r0, asr #22
 *
 * ══ §33/70 anon_2a399c  0x2a399c  size 432  108 条（0x2a399c..0x2a3b4c）
 * @func 0x2a399c 0x2a3b4c  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3e1c12
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a399c .word 0x4604b538
 *   @0x2a39a0 sbclt r4, r0, #13631488
 *   @0x2a39a4 b 0xfeb611f8 <b2_toiTime+0xfffffffffe407d54>
 *   @0x2a39a8 .word 0xf3c44629
 *   @0x2a39ac .word 0xf6132007
 *   @0x2a39b0 qadd8mi lr, r9, lr
 *   @0x2a39b4 andmi pc, r7, r4, asr #7
 *   @0x2a39b8 b 0xfe8e120c <b2_toiTime+0xfffffffffe187d68>
 *   @0x2a39bc strtmi r0, [r9], -r0, lsr #28
 *   @0x2a39c0 ldrhtmi lr, [r8], -sp
 *   @0x2a39c4 ldmdalt r2!, {r3, r4, r5, r6, r12, sp, lr, pc} ^
 *   @0x2a39c8 .word 0x4604b538
 *   @0x2a39cc sbclt r4, r0, #13631488
 *   @0x2a39d0 b 0xfe5e1224 <b2_toiTime+0xfffffffffde87d80>
 *   @0x2a39d4 strtmi r0, [r9], -r0, lsr #20
 *   @0x2a39d8 ldrhtmi lr, [r8], -sp
 *   @0x2a39dc stmdalt r6!, {r3, r4, r5, r6, r12, sp, lr, pc} ^
 *   @0x2a39e0 mvnsmi lr, sp, lsr #18
 *   @0x2a39e4 strmi r4, [sp], -r0, lsl #13
 *   @0x2a39e8 sadd16mi r4, r6, pc
 *   @0x2a39ec mcrrne p1, #0x0, r11, r8, c10
 *   @0x2a39f0 strmi lr, [r8], -r0
 *   @0x2a39f4 stc p6, c15, [r6, #72]!
 *   @0x2a39f8 stmdblt r8!, {r2, r9, r10, lr}
 *   @0x2a39fc .word 0x210e4638
 *   @0x2a3a00 .word 0xf0004622
 *   @0x2a3a04 eor pc, r3, r9, lsr #25
 *   @0x2a3a08 strtmi r2, [r10], -r1, lsl #2
 *   @0x2a3a0c .word 0xf6124643
 *   @0x2a3a10 adcmi lr, r8, #92, #30
 *   @0x2a3a14 strtmi sp, [r0], -r12, lsl #4
 *   @0x2a3a18 stc p6, c15, [r0, #72]!
 *   @0x2a3a1c stm r12!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^
 *   @0x2a3a20 stmdavs r2, {r0, r2, r8, sp}
 *   @0x2a3a24 .word 0xf0004638
 *   @0x2a3a28 mulhs r0, r7, r12
 *   @0x2a3a2c ldrhhi lr, [r0, #141]!
 *   @0x2a3a30 stmdbne r2!, {r1, r2, r4, r5, r6, r8, r12, sp, pc} ^
 *   @0x2a3a34 eorhs r2, r0, r0, lsl #6
 *   @0x2a3a38 strtmi r5, [r3], -r3, ror #10
 *   @0x2a3a3c sadd8mi r4, r9, r3
 *   @0x2a3a40 stmdavc r9, {r1, r2, r9, r12, lr, pc}
 *   @0x2a3a44 stmdbhs r0, {r0, r8, r9, r12, sp}
 *   @0x2a3a48 .word 0xf803d1f8
 *   @0x2a3a4c ldrb r0, [r5, r1, lsl #24]!
 *   @0x2a3a50 pop {r5, r9, r10, lr}
 *   @0x2a3a54 strlt r8, [r0, #-0x1f0]
 *   @0x2a3a58 .word 0xf04fb08d
 *   @0x2a3a5c movwls r3, #0x93ff
 *   @0x2a3a60 movths pc, #0x63c1
 *   @0x2a3a64 movwls r3, #0x6350
 *   @0x2a3a68 movtne pc, #0x33c1
 *   @0x2a3a6c tsteq pc, r1
 *   @0x2a3a70 movwls r3, #0x5b01
 *   @0x2a3a74 bichs pc, r4, #192, #6
 *   @0x2a3a78 .word 0xf3c09303
 *   @0x2a3a7c subeq r1, r0, r5, asr #6
 *   @0x2a3a80 .word 0xf0009302
 *   @0x2a3a84 stmdage r12, {r1, r2, r3, r4, r5, r8, r9}
 *   @0x2a3a88 .word 0xf8409104
 *   @0x2a3a8c .word 0xf6133d2c
 *   @0x2a3a90 andlt lr, sp, r4, lsr r10
 *   @0x2a3a94 blx 0x3e1c12 <error_g0017+0x3a8b6>
 *   @0x2a3a98 mvnsmi lr, sp, lsr #18
 *   @0x2a3a9c strmi r4, [r12], -r6, lsl #12
 *   @0x2a3aa0 sadd8mi r4, r7, r8
 *   @0x2a3aa4 mcrrne p1, #0x0, r11, r8, c10
 *   @0x2a3aa8 strmi lr, [r8], -r0
 *   @0x2a3aac stcl p6, c15, [r10, #-72]
 *   @0x2a3ab0 stmdblt r8!, {r0, r2, r9, r10, lr}
 *   @0x2a3ab4 .word 0x210e4640
 *   @0x2a3ab8 .word 0xf000462a
 *   @0x2a3abc ands pc, r6, sp, asr #24
 *   @0x2a3ac0 qasxmi r6, r2, r1
 *   @0x2a3ac4 ldcl p6, c15, [r10, #-72]!
 *   @0x2a3ac8 strtmi r6, [r3], #-2099
 *   @0x2a3acc cmnlt r7, r3, lsr r0
 *   @0x2a3ad0 movwhs r1, #0x92a
 *   @0x2a3ad4 strpl r2, [r11, #-0x20]!
 *   @0x2a3ad8 addsmi r4, r3, #45088768
 *   @0x2a3adc andle r4, r6, #26214400
 *   @0x2a3ae0 movwlo r7, #0x1809
 *   @0x2a3ae4 mvnsle r2, r0, lsl #18
 *   @0x2a3ae8 .word 0x0c01f803
 *   @0x2a3aec qsub8mi lr, r8, r5
 *   @0x2a3af0 ldrhhi lr, [r0, #141]!
 *   @0x2a3af4 mvnsmi lr, sp, lsr #18
 *   @0x2a3af8 strmi r4, [sp], -r7, lsl #12
 *   @0x2a3afc sadd8mi r4, r6, r8
 *   @0x2a3b00 mcrrne p1, #0x0, r11, r8, c10
 *   @0x2a3b04 strmi lr, [r8], -r0
 *   @0x2a3b08 ldc p6, c15, [r12, #-72]
 *   @0x2a3b0c stmdblt r8!, {r2, r9, r10, lr}
 *   @0x2a3b10 .word 0x210e4640
 *   @0x2a3b14 .word 0xf0004622
 *   @0x2a3b18 ands pc, r5, pc, lsl r12
 *   @0x2a3b1c qasxmi r4, r1, r8
 *   @0x2a3b20 strtmi r2, [r11], -r1, lsl #4
 *   @0x2a3b24 ldm r10!, {r1, r3, r5, r9, r10, r12, sp, lr, pc}
 *   @0x2a3b28 stmdbne r2!, {r1, r2, r4, r5, r6, r8, r12, sp, pc} ^
 *   @0x2a3b2c eorhs r2, r0, r0, lsl #6
 *   @0x2a3b30 strtmi r5, [r3], -r3, ror #10
 *   @0x2a3b34 sadd8mi r4, r9, r3
 *   @0x2a3b38 stmdavc r9, {r1, r2, r9, r12, lr, pc}
 *   @0x2a3b3c stmdbhs r0, {r0, r8, r9, r12, sp}
 *   @0x2a3b40 .word 0xf803d1f8
 *   @0x2a3b44 ldrb r0, [r5, r1, lsl #24]!
 *   @0x2a3b48 pop {r5, r9, r10, lr}
 *
 * ══ §34/70 b2EdgeShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const  0x2c534c  size 432  108 条（0x2c534c..0x2c54fc）
 * @func 0x2c534c 0x2c54fc  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x4×3 / 0x-4×1
 * VFP 指令 86 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c534c str lr, [sp, #-0x4]!
 *   @0x2c5350 vpush {d8, d9, d10, d11, d12}
 *   @0x2c5354 vldr s21, [r0, #16]
 *   @0x2c5358 vldr s19, [r0, #24]
 *   @0x2c535c vsub.f32 s19, s19, s21
 *   @0x2c5360 vldr s20, [r0, #12]
 *   @0x2c5364 vldr s22, [r0, #20]
 *   @0x2c5368 vldr s14, [r3, #4]
 *   @0x2c536c vldr s18, [r2, #4]
 *   @0x2c5370 vldr s13, [r2, #12]
 *   @0x2c5374 vldr s15, [r3, #12]
 *   @0x2c5378 vldr s11, [r3, #8]
 *   @0x2c537c vldr s10, [r3]
 *   @0x2c5380 vldr s9, [r2]
 *   @0x2c5384 vldr s7, [r2, #8]
 *   @0x2c5388 sub sp, sp, #12
 *   @0x2c538c vmul.f32 s23, s19, s19
 *   @0x2c5390 vsub.f32 s22, s22, s20
 *   @0x2c5394 vmov.f32 s8, s23
 *   @0x2c5398 vneg.f32 s16, s22
 *   @0x2c539c vmla.f32 s8, s16, s16
 *   @0x2c53a0 vsub.f32 s18, s18, s14
 *   @0x2c53a4 vsub.f32 s13, s13, s14
 *   @0x2c53a8 vsqrt.f32 s14, s8
 *   @0x2c53ac vmul.f32 s17, s18, s11
 *   @0x2c53b0 vmul.f32 s12, s11, s13
 *   @0x2c53b4 vmul.f32 s18, s18, s15
 *   @0x2c53b8 vmul.f32 s13, s15, s13
 *   @0x2c53bc vsub.f32 s9, s9, s10
 *   @0x2c53c0 vsub.f32 s10, s7, s10
 *   @0x2c53c4 vneg.f32 s11, s11
 *   @0x2c53c8 vmla.f32 s17, s9, s15
 *   @0x2c53cc vmla.f32 s18, s9, s11
 *   @0x2c53d0 vmla.f32 s12, s15, s10
 *   @0x2c53d4 vmla.f32 s13, s11, s10
 *   @0x2c53d8 vcmp.f32 s14, s14
 *   @0x2c53dc vsub.f32 s24, s12, s17
 *   @0x2c53e0 vmrs APSR_nzcv, fpscr
 *   @0x2c53e4 vsub.f32 s25, s13, s18
 *   @0x2c53e8 bne 0x2c54d8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x18c>
 *   @0x2c53ec vldr s15, [pc, #260]
 *   @0x2c53f0 vcmpe.f32 s14, s15
 *   @0x2c53f4 vmrs APSR_nzcv, fpscr
 *   @0x2c53f8 vmovpl.f32 s15, #1.000000e+00
 *   @0x2c53fc vdivpl.f32 s14, s15, s14
 *   @0x2c5400 vmulpl.f32 s16, s16, s14
 *   @0x2c5404 vmulpl.f32 s14, s19, s14
 *   @0x2c5408 vmul.f32 s15, s16, s25
 *   @0x2c540c vmovmi.f32 s14, s19
 *   @0x2c5410 vmla.f32 s15, s14, s24
 *   @0x2c5414 vcmp.f32 s15, #0
 *   @0x2c5418 vmrs APSR_nzcv, fpscr
 *   @0x2c541c beq 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c>
 *   @0x2c5420 vsub.f32 s11, s21, s18
 *   @0x2c5424 vmul.f32 s11, s16, s11
 *   @0x2c5428 vsub.f32 s13, s20, s17
 *   @0x2c542c vmla.f32 s11, s14, s13
 *   @0x2c5430 vdiv.f32 s15, s11, s15
 *   @0x2c5434 vcmpe.f32 s15, #0
 *   @0x2c5438 vmrs APSR_nzcv, fpscr
 *   @0x2c543c bmi 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c>
 *   @0x2c5440 vldr s13, [r2, #16]
 *   @0x2c5444 vcmpe.f32 s15, s13
 *   @0x2c5448 vmrs APSR_nzcv, fpscr
 *   @0x2c544c bgt 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c>
 *   @0x2c5450 vmla.f32 s23, s22, s22
 *   @0x2c5454 vcmp.f32 s23, #0
 *   @0x2c5458 vmrs APSR_nzcv, fpscr
 *   @0x2c545c beq 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c>
 *   @0x2c5460 vmla.f32 s18, s15, s25
 *   @0x2c5464 vmla.f32 s17, s15, s24
 *   @0x2c5468 vsub.f32 s21, s18, s21
 *   @0x2c546c vmul.f32 s19, s19, s21
 *   @0x2c5470 vsub.f32 s20, s17, s20
 *   @0x2c5474 vmla.f32 s19, s22, s20
 *   @0x2c5478 vdiv.f32 s23, s19, s23
 *   @0x2c547c vcmpe.f32 s23, #0
 *   @0x2c5480 vmrs APSR_nzcv, fpscr
 *   @0x2c5484 bmi 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c>
 *   @0x2c5488 vmov.f32 s13, #1.000000e+00
 *   @0x2c548c vcmpe.f32 s23, s13
 *   @0x2c5490 vmrs APSR_nzcv, fpscr
 *   @0x2c5494 bgt 0x2c54c8 <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x17c>
 *   @0x2c5498 vcmpe.f32 s11, #0
 *   @0x2c549c vstr s15, [r1, #8]
 *   @0x2c54a0 vmrs APSR_nzcv, fpscr
 *   @0x2c54a4 vneggt.f32 s14, s14
 *   @0x2c54a8 movgt r0, #1
 *   @0x2c54ac vstrle s14, [r1]
 *   @0x2c54b0 vstrle s16, [r1, #4]
 *   @0x2c54b4 movle r0, #1
 *   @0x2c54b8 vneggt.f32 s16, s16
 *   @0x2c54bc vstrgt s14, [r1]
 *   @0x2c54c0 vstrgt s16, [r1, #4]
 *   @0x2c54c4 b 0x2c54cc <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x180>
 *   @0x2c54c8 mov r0, #0
 *   @0x2c54cc add sp, sp, #12
 *   @0x2c54d0 vpop {d8, d9, d10, d11, d12}
 *   @0x2c54d4 ldr pc, [sp], #4
 *   @0x2c54d8 vmov r0, s8
 *   @0x2c54dc str r1, [sp, #0x4]
 *   @0x2c54e0 str r2, [sp]
 *   @0x2c54e4 bl 0xb6700 <sqrtf@plt>
 *   @0x2c54e8 ldr r2, [sp]
 *   @0x2c54ec ldr r1, [sp, #0x4]
 *   @0x2c54f0 vmov s14, r0
 *   @0x2c54f4 b 0x2c53ec <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xa0>
 *   @0x2c54f8 strlo r0, [r0], #-0
 *
 * ══ §35/70 b2PrismaticJoint::Dump()  0x2cf1ac  size 432  108 条（0x2cf1ac..0x2cf35c）
 * @func 0x2cf1ac 0x2cf35c  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×14
 * 字段偏移 top8: 0x8×2 / 0x88×2 / 0x30×1 / 0x34×1 / 0x158×1 / 0x148×1 / 0x13c×1 / 0x130×1
 * VFP 指令 33 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf1ac push {r4, r5, r6, lr}
 *   @0x2cf1b0 mov r4, r0
 *   @0x2cf1b4 ldr r2, [r4, #0x30]
 *   @0x2cf1b8 sub sp, sp, #8
 *   @0x2cf1bc ldr r3, [r4, #0x34]
 *   @0x2cf1c0 ldr r0, [pc, #0x158]
 *   @0x2cf1c4 ldr r6, [r2, #0x8]
 *   @0x2cf1c8 add r0, pc, r0
 *   @0x2cf1cc ldr r5, [r3, #0x8]
 *   @0x2cf1d0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf1d4 ldr r0, [pc, #0x148]
 *   @0x2cf1d8 mov r1, r6
 *   @0x2cf1dc add r0, pc, r0
 *   @0x2cf1e0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf1e4 ldr r0, [pc, #0x13c]
 *   @0x2cf1e8 mov r1, r5
 *   @0x2cf1ec add r0, pc, r0
 *   @0x2cf1f0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf1f4 ldr r0, [pc, #0x130]
 *   @0x2cf1f8 ldrb r1, [r4, #0x3d]
 *   @0x2cf1fc add r0, pc, r0
 *   @0x2cf200 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf204 vldr s13, [r4, #68]
 *   @0x2cf208 vldr s14, [r4, #72]
 *   @0x2cf20c vcvt.f64.f32 d5, s13
 *   @0x2cf210 ldr r0, [pc, #0x118]
 *   @0x2cf214 add r0, pc, r0
 *   @0x2cf218 vcvt.f64.f32 d7, s14
 *   @0x2cf21c vmov r2, r3, d5
 *   @0x2cf220 vstr d7, [sp]
 *   @0x2cf224 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf228 vldr s13, [r4, #76]
 *   @0x2cf22c vldr s14, [r4, #80]
 *   @0x2cf230 vcvt.f64.f32 d5, s13
 *   @0x2cf234 ldr r0, [pc, #0xf8]
 *   @0x2cf238 add r0, pc, r0
 *   @0x2cf23c vcvt.f64.f32 d7, s14
 *   @0x2cf240 vmov r2, r3, d5
 *   @0x2cf244 vstr d7, [sp]
 *   @0x2cf248 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf24c vldr s13, [r4, #84]
 *   @0x2cf250 vldr s14, [r4, #88]
 *   @0x2cf254 vcvt.f64.f32 d5, s13
 *   @0x2cf258 ldr r0, [pc, #0xd8]
 *   @0x2cf25c add r0, pc, r0
 *   @0x2cf260 vcvt.f64.f32 d7, s14
 *   @0x2cf264 vmov r2, r3, d5
 *   @0x2cf268 vstr d7, [sp]
 *   @0x2cf26c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf270 vldr s15, [r4, #100]
 *   @0x2cf274 vcvt.f64.f32 d6, s15
 *   @0x2cf278 ldr r0, [pc, #0xbc]
 *   @0x2cf27c add r0, pc, r0
 *   @0x2cf280 vmov r2, r3, d6
 *   @0x2cf284 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf288 ldr r0, [pc, #0xb0]
 *   @0x2cf28c ldrb r1, [r4, #0x88]
 *   @0x2cf290 add r0, pc, r0
 *   @0x2cf294 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf298 vldr s15, [r4, #120]
 *   @0x2cf29c vcvt.f64.f32 d5, s15
 *   @0x2cf2a0 ldr r0, [pc, #0x9c]
 *   @0x2cf2a4 add r0, pc, r0
 *   @0x2cf2a8 vmov r2, r3, d5
 *   @0x2cf2ac bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf2b0 vldr s15, [r4, #124]
 *   @0x2cf2b4 vcvt.f64.f32 d6, s15
 *   @0x2cf2b8 ldr r0, [pc, #0x88]
 *   @0x2cf2bc add r0, pc, r0
 *   @0x2cf2c0 vmov r2, r3, d6
 *   @0x2cf2c4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf2c8 ldr r0, [pc, #0x7c]
 *   @0x2cf2cc ldrb r1, [r4, #0x89]
 *   @0x2cf2d0 add r0, pc, r0
 *   @0x2cf2d4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf2d8 vldr s15, [r4, #132]
 *   @0x2cf2dc vcvt.f64.f32 d5, s15
 *   @0x2cf2e0 ldr r0, [pc, #0x68]
 *   @0x2cf2e4 add r0, pc, r0
 *   @0x2cf2e8 vmov r2, r3, d5
 *   @0x2cf2ec bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf2f0 vldr s15, [r4, #128]
 *   @0x2cf2f4 vcvt.f64.f32 d6, s15
 *   @0x2cf2f8 ldr r0, [pc, #0x54]
 *   @0x2cf2fc add r0, pc, r0
 *   @0x2cf300 vmov r2, r3, d6
 *   @0x2cf304 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf308 ldr r0, [pc, #0x48]
 *   @0x2cf30c ldr r1, [r4, #0x38]
 *   @0x2cf310 add r0, pc, r0
 *   @0x2cf314 add sp, sp, #8
 *   @0x2cf318 pop {r4, r5, r6, lr}
 *   @0x2cf31c b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cf320 andeq r12, r8, r0, lsr #30
 *   @0x2cf324 ldrdeq r12, sp, [r8], -r0
 *   @0x2cf328 ldrdeq r12, sp, [r8], -r12
 *   @0x2cf32c andeq r12, r8, r8, ror #25
 *   @0x2cf330 strdeq r12, sp, [r8], -r4
 *   @0x2cf334 strdeq r12, sp, [r8], -r12
 *   @0x2cf338 andeq r12, r8, r8, lsr #29
 *   @0x2cf33c strheq r12, [r8], -r0
 *   @0x2cf340 strheq r12, [r8], -r12
 *   @0x2cf344 andeq r12, r8, r8, asr #29
 *   @0x2cf348 ldrdeq r12, sp, [r8], -r4
 *   @0x2cf34c andeq r12, r8, r4, ror #29
 *   @0x2cf350 strdeq r12, sp, [r8], -r0
 *   @0x2cf354 strdeq r12, sp, [r8], -r4
 *   @0x2cf358 andeq r12, r8, r8, lsr #25
 *
 * ══ §36/70 VM::PokeDSStack(int, int, RValue&)  0xe4d6c  size 428  107 条（0xe4d6c..0xe4f18）
 * @func 0xe4d6c 0xe4f28  size 444  111 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::PokeDSStack(int, int, RValue&)+0xec×2 / GetTheStacks(int&) / FREE_RValue__Pre(RValue*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×10 / 0xc×6 / 0x8×4 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe4d6c push {r4, r5, r6, r7, lr}
 *   @0xe4d70 sub sp, sp, #12
 *   @0xe4d74 mov r4, r0
 *   @0xe4d78 add r0, sp, #4
 *   @0xe4d7c mov r5, r1
 *   @0xe4d80 mov r6, r2
 *   @0xe4d84 bl 0xffc9c <_Z12GetTheStacksRi>
 *   @0xe4d88 cmp r4, #0
 *   @0xe4d8c blt 0xe4e58 <_ZN2VM11PokeDSStackEiiR6RValue+0xec>
 *   @0xe4d90 ldr r3, [sp, #0x4]
 *   @0xe4d94 cmp r4, r3
 *   @0xe4d98 bge 0xe4e58 <_ZN2VM11PokeDSStackEiiR6RValue+0xec>
 *   @0xe4d9c ldr r0, [r0, r4, lsl #2]
 *   @0xe4da0 cmp r0, #0
 *   @0xe4da4 beq 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0>
 *   @0xe4da8 cmp r5, #0
 *   @0xe4dac blt 0xe4e58 <_ZN2VM11PokeDSStackEiiR6RValue+0xec>
 *   @0xe4db0 ldr r3, [r0, #0x4]
 *   @0xe4db4 cmp r5, r3
 *   @0xe4db8 bge 0xe4e58 <_ZN2VM11PokeDSStackEiiR6RValue+0xec>
 *   @0xe4dbc sub r3, r3, #1
 *   @0xe4dc0 ldr r7, [r0, #0xc]
 *   @0xe4dc4 rsb r5, r5, r3
 *   @0xe4dc8 add r4, r7, r5, lsl #4
 *   @0xe4dcc ldr r3, [r4, #0xc]
 *   @0xe4dd0 sub r3, r3, #1
 *   @0xe4dd4 bic r3, r3, #-16777216
 *   @0xe4dd8 bic r3, r3, #3
 *   @0xe4ddc cmp r3, #0
 *   @0xe4de0 beq 0xe4e74 <_ZN2VM11PokeDSStackEiiR6RValue+0x108>
 *   @0xe4de4 mov r3, #5
 *   @0xe4de8 str r3, [r4, #0xc]
 *   @0xe4dec ldr r1, [r6, #0xc]
 *   @0xe4df0 mov r3, #0
 *   @0xe4df4 str r3, [r4, #0x8]
 *   @0xe4df8 str r3, [r7, r5, lsl #4]
 *   @0xe4dfc ldr r2, [r6, #0x8]
 *   @0xe4e00 str r1, [r4, #0xc]
 *   @0xe4e04 ldr r3, [r6, #0xc]
 *   @0xe4e08 str r2, [r4, #0x8]
 *   @0xe4e0c bic r3, r3, #-16777216
 *   @0xe4e10 cmp r3, #14
 *   @0xe4e14 addls pc, pc, r3, lsl #2
 *   @0xe4e18 b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4e1c b 0xe4e80 <_ZN2VM11PokeDSStackEiiR6RValue+0x114>
 *   @0xe4e20 b 0xe4e98 <_ZN2VM11PokeDSStackEiiR6RValue+0x12c>
 *   @0xe4e24 b 0xe4eb8 <_ZN2VM11PokeDSStackEiiR6RValue+0x14c>
 *   @0xe4e28 b 0xe4e64 <_ZN2VM11PokeDSStackEiiR6RValue+0xf8>
 *   @0xe4e2c b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4e30 b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4e34 b 0xe4ef0 <_ZN2VM11PokeDSStackEiiR6RValue+0x184>
 *   @0xe4e38 b 0xe4e64 <_ZN2VM11PokeDSStackEiiR6RValue+0xf8>
 *   @0xe4e3c b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4e40 b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4e44 b 0xe4e80 <_ZN2VM11PokeDSStackEiiR6RValue+0x114>
 *   @0xe4e48 b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4e4c b 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4e50 b 0xe4e80 <_ZN2VM11PokeDSStackEiiR6RValue+0x114>
 *   @0xe4e54 b 0xe4e64 <_ZN2VM11PokeDSStackEiiR6RValue+0xf8>
 *   @0xe4e58 mov r0, #0
 *   @0xe4e5c add sp, sp, #12
 *   @0xe4e60 pop {r4, r5, r6, r7, pc}
 *   @0xe4e64 ldr r3, [r6]
 *   @0xe4e68 mov r0, #1
 *   @0xe4e6c str r3, [r7, r5, lsl #4]
 *   @0xe4e70 b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0>
 *   @0xe4e74 mov r0, r4
 *   @0xe4e78 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe4e7c b 0xe4de4 <_ZN2VM11PokeDSStackEiiR6RValue+0x78>
 *   @0xe4e80 ldr r2, [r6]
 *   @0xe4e84 mov r0, #1
 *   @0xe4e88 ldr r3, [r6, #0x4]
 *   @0xe4e8c str r2, [r7, r5, lsl #4]
 *   @0xe4e90 str r3, [r4, #0x4]
 *   @0xe4e94 b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0>
 *   @0xe4e98 ldr r3, [r6]
 *   @0xe4e9c mov r0, #1
 *   @0xe4ea0 cmp r3, #0
 *   @0xe4ea4 ldrne r2, [r3, #0x4]
 *   @0xe4ea8 addne r2, r2, #1
 *   @0xe4eac strne r2, [r3, #0x4]
 *   @0xe4eb0 str r3, [r7, r5, lsl #4]
 *   @0xe4eb4 b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0>
 *   @0xe4eb8 ldr r3, [r6]
 *   @0xe4ebc cmp r3, #0
 *   @0xe4ec0 str r3, [r7, r5, lsl #4]
 *   @0xe4ec4 beq 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4ec8 ldr r1, [r3, #0x8]
 *   @0xe4ecc ldr r2, [r3]
 *   @0xe4ed0 cmp r1, #0
 *   @0xe4ed4 streq r4, [r3, #0x8]
 *   @0xe4ed8 add r2, r2, #1
 *   @0xe4edc str r2, [r3]
 *   @0xe4ee0 moveq r0, #1
 *   @0xe4ee4 beq 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0>
 *   @0xe4ee8 mov r0, #1
 *   @0xe4eec b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0>
 *   @0xe4ef0 ldr r3, [r6]
 *   @0xe4ef4 str r3, [r7, r5, lsl #4]
 *   @0xe4ef8 ldr r3, [r6]
 *   @0xe4efc cmp r3, #0
 *   @0xe4f00 beq 0xe4ee8 <_ZN2VM11PokeDSStackEiiR6RValue+0x17c>
 *   @0xe4f04 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xe4f08 ldr r1, [r6]
 *   @0xe4f0c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xe4f10 mov r0, #1
 *   @0xe4f14 b 0xe4e5c <_ZN2VM11PokeDSStackEiiR6RValue+0xf0>
 *
 * ══ §37/70 F_FileTextOpenWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0x13b084  size 428  107 条（0x13b084..0x13b230）
 * @func 0x13b084 0x13b230  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13b0dc→0x483724, 0x13b104→0x4837a4, 0x13b1e0→0x3eb70c
 * 调用序列: YYGetString(RValue const*, int) / MemoryManager::Free(void const*) / LoadSave::_GetSaveFileName(char*, int, char const*) / EnsureDirectoryIsCreated(char const*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / LoadSave::fopen(char const*, char const*)
 * 字段偏移 top8: 0xc×4 / 0x4×4 / 0x8×3 / 0x414×2 / 0x178×1 / 0x174×1 / 0x440×1 / 0x130×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13b084 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13b088 sub sp, sp, #1040
 *   @0x13b08c ldr r6, [pc, #0x178]
 *   @0x13b090 sub sp, sp, #12
 *   @0x13b094 ldr r3, [pc, #0x174]
 *   @0x13b098 mov r5, r0
 *   @0x13b09c add r6, pc, r6
 *   @0x13b0a0 mov r1, #0
 *   @0x13b0a4 ldr r0, [sp, #0x440]
 *   @0x13b0a8 mov r4, #1
 *   @0x13b0ac ldr r3, [r6, r3]
 *   @0x13b0b0 str r3, [sp, #0x8]
 *   @0x13b0b4 ldr r3, [r3]
 *   @0x13b0b8 str r3, [sp, #0x414]
 *   @0x13b0bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13b0c0 mov r1, #0
 *   @0x13b0c4 mov r3, r1
 *   @0x13b0c8 movt r1, #0xbff0
 *   @0x13b0cc str r3, [r5, #0xc]
 *   @0x13b0d0 str r1, [r5, #0x4]
 *   @0x13b0d4 str r3, [r5]
 *   @0x13b0d8 mov r2, r0
 *   @0x13b0dc ldr r0, [pc, #0x130]
 *   @0x13b0e0 ldr r3, [r6, r0]
 *   @0x13b0e4 str r3, [sp, #0xc]
 *   @0x13b0e8 b 0x13b0f8 <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x13b0ec add r4, r4, #1
 *   @0x13b0f0 cmp r4, #32
 *   @0x13b0f4 beq 0x13b1cc <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x13b0f8 ldr r11, [r3, #0x4]!
 *   @0x13b0fc cmp r11, #0
 *   @0x13b100 bne 0x13b0ec <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x13b104 ldr r3, [pc, #0x10c]
 *   @0x13b108 add r10, r4, r4, lsl #1
 *   @0x13b10c add r9, sp, #20
 *   @0x13b110 lsl r10, r10, #2
 *   @0x13b114 ldr r8, [r6, r3]
 *   @0x13b118 add r7, r8, r10
 *   @0x13b11c ldr r0, [r8, r10]
 *   @0x13b120 str r2, [sp, #0x4]
 *   @0x13b124 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13b128 ldr r2, [sp, #0x4]
 *   @0x13b12c mov r1, #1024
 *   @0x13b130 str r11, [r8, r10]
 *   @0x13b134 mov r0, r9
 *   @0x13b138 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13b13c mov r0, r9
 *   @0x13b140 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x13b144 mov r0, r9
 *   @0x13b148 bl 0xb6538 <strlen@plt>
 *   @0x13b14c ldr r1, [pc, #0xc8]
 *   @0x13b150 mov r3, #1
 *   @0x13b154 movw r2, #0x35b
 *   @0x13b158 add r1, pc, r1
 *   @0x13b15c add r0, r0, r3
 *   @0x13b160 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13b164 mov r1, r9
 *   @0x13b168 mov r11, r0
 *   @0x13b16c bl 0xb65a4 <strcpy@plt>
 *   @0x13b170 ldr r1, [pc, #0xa8]
 *   @0x13b174 mov r0, r11
 *   @0x13b178 str r11, [r8, r10]
 *   @0x13b17c add r1, pc, r1
 *   @0x13b180 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x13b184 cmp r0, #0
 *   @0x13b188 str r0, [r7, #0x8]
 *   @0x13b18c beq 0x13b1e0 <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x13b190 vmov s15, r4
 *   @0x13b194 ldr r0, [sp, #0xc]
 *   @0x13b198 mov r1, #2
 *   @0x13b19c vcvt.f64.s32 d7, s15
 *   @0x13b1a0 str r1, [r0, r4, lsl #2]
 *   @0x13b1a4 vmov r2, r3, d7
 *   @0x13b1a8 stm r5, {r2, r3}
 *   @0x13b1ac ldr r1, [sp, #0x8]
 *   @0x13b1b0 ldr r2, [sp, #0x414]
 *   @0x13b1b4 ldr r3, [r1]
 *   @0x13b1b8 cmp r2, r3
 *   @0x13b1bc bne 0x13b208 <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x13b1c0 add sp, sp, #1040
 *   @0x13b1c4 add sp, sp, #12
 *   @0x13b1c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13b1cc ldr r0, [pc, #0x50]
 *   @0x13b1d0 mov r1, #0
 *   @0x13b1d4 add r0, pc, r0
 *   @0x13b1d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13b1dc b 0x13b1ac <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x13b1e0 ldr r3, [pc, #0x40]
 *   @0x13b1e4 mov r2, r11
 *   @0x13b1e8 ldr r1, [pc, #0x3c]
 *   @0x13b1ec ldr r3, [r6, r3]
 *   @0x13b1f0 add r1, pc, r1
 *   @0x13b1f4 ldr r0, [r3]
 *   @0x13b1f8 ldr r3, [r0]
 *   @0x13b1fc ldr r3, [r3, #0xc]
 *   @0x13b200 blx r3
 *   @0x13b204 b 0x13b1ac <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x13b208 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13b20c .word 0x002b6bb4
 *   @0x13b210 .word 0xffffbd00
 *   @0x13b214 .word 0xffffd620
 *   @0x13b218 .word 0xffffd624
 *   @0x13b21c .word 0x00204ef8
 *   @0x13b220 .word 0x002051f0
 *   @0x13b224 eoreq r4, r0, r12, lsr #28
 *   @0x13b228 .word 0xffffbac4
 *   @0x13b22c eoreq r4, r0, r4, ror #27
 *
 * ══ §38/70 Effect_Create(bool, int, float, float, int, unsigned int)  0x1a25d0  size 428  107 条（0x1a25d0..0x1a277c）
 * @func 0x1a25d0 0x1a277c  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Eff_Check_Systems()
 * 字段偏移 top8: 0x20×13 / 0x24×1 / 0x174×1 / 0x130×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a25d0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a25d4 mov r5, r0
 *   @0x1a25d8 mov r4, r1
 *   @0x1a25dc mov r9, r2
 *   @0x1a25e0 ldr r6, [sp, #0x20]
 *   @0x1a25e4 mov r8, r3
 *   @0x1a25e8 ldr r7, [sp, #0x24]
 *   @0x1a25ec bl 0x1a24f4 <_Z17Eff_Check_Systemsv>
 *   @0x1a25f0 cmp r5, #0
 *   @0x1a25f4 beq 0x1a2640 <_Z13Effect_Createbiffij+0x70>
 *   @0x1a25f8 ldr r0, [pc, #0x174]
 *   @0x1a25fc ldr r0, [pc, r0]
 *   @0x1a2600 ldr r0, [r0]
 *   @0x1a2604 cmp r4, #11
 *   @0x1a2608 addls pc, pc, r4, lsl #2
 *   @0x1a260c b 0x1a2770 <_Z13Effect_Createbiffij+0x1a0>
 *   @0x1a2610 b 0x1a2668 <_Z13Effect_Createbiffij+0x98>
 *   @0x1a2614 b 0x1a2680 <_Z13Effect_Createbiffij+0xb0>
 *   @0x1a2618 b 0x1a2698 <_Z13Effect_Createbiffij+0xc8>
 *   @0x1a261c b 0x1a26b0 <_Z13Effect_Createbiffij+0xe0>
 *   @0x1a2620 b 0x1a26c8 <_Z13Effect_Createbiffij+0xf8>
 *   @0x1a2624 b 0x1a26e0 <_Z13Effect_Createbiffij+0x110>
 *   @0x1a2628 b 0x1a26f8 <_Z13Effect_Createbiffij+0x128>
 *   @0x1a262c b 0x1a2710 <_Z13Effect_Createbiffij+0x140>
 *   @0x1a2630 b 0x1a2728 <_Z13Effect_Createbiffij+0x158>
 *   @0x1a2634 b 0x1a2740 <_Z13Effect_Createbiffij+0x170>
 *   @0x1a2638 b 0x1a2758 <_Z13Effect_Createbiffij+0x188>
 *   @0x1a263c b 0x1a2650 <_Z13Effect_Createbiffij+0x80>
 *   @0x1a2640 ldr r0, [pc, #0x130]
 *   @0x1a2644 ldr r0, [pc, r0]
 *   @0x1a2648 ldr r0, [r0]
 *   @0x1a264c b 0x1a2604 <_Z13Effect_Createbiffij+0x34>
 *   @0x1a2650 str r7, [sp, #0x20]
 *   @0x1a2654 mov r1, r9
 *   @0x1a2658 mov r3, r6
 *   @0x1a265c mov r2, r8
 *   @0x1a2660 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a2664 b 0x1a21b8 <_Z12Eff_Effect11iffij>
 *   @0x1a2668 str r7, [sp, #0x20]
 *   @0x1a266c mov r1, r9
 *   @0x1a2670 mov r3, r6
 *   @0x1a2674 mov r2, r8
 *   @0x1a2678 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a267c b 0x1a005c <_Z12Eff_Effect00iffij>
 *   @0x1a2680 str r7, [sp, #0x20]
 *   @0x1a2684 mov r1, r9
 *   @0x1a2688 mov r3, r6
 *   @0x1a268c mov r2, r8
 *   @0x1a2690 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a2694 b 0x1a0614 <_Z12Eff_Effect01iffij>
 *   @0x1a2698 str r7, [sp, #0x20]
 *   @0x1a269c mov r1, r9
 *   @0x1a26a0 mov r3, r6
 *   @0x1a26a4 mov r2, r8
 *   @0x1a26a8 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a26ac b 0x1a0848 <_Z12Eff_Effect02iffij>
 *   @0x1a26b0 str r7, [sp, #0x20]
 *   @0x1a26b4 mov r1, r9
 *   @0x1a26b8 mov r3, r6
 *   @0x1a26bc mov r2, r8
 *   @0x1a26c0 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a26c4 b 0x1a0ab0 <_Z12Eff_Effect03iffij>
 *   @0x1a26c8 str r7, [sp, #0x20]
 *   @0x1a26cc mov r1, r9
 *   @0x1a26d0 mov r3, r6
 *   @0x1a26d4 mov r2, r8
 *   @0x1a26d8 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a26dc b 0x1a0e64 <_Z12Eff_Effect04iffij>
 *   @0x1a26e0 str r7, [sp, #0x20]
 *   @0x1a26e4 mov r1, r9
 *   @0x1a26e8 mov r3, r6
 *   @0x1a26ec mov r2, r8
 *   @0x1a26f0 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a26f4 b 0x1a1194 <_Z12Eff_Effect05iffij>
 *   @0x1a26f8 str r7, [sp, #0x20]
 *   @0x1a26fc mov r1, r9
 *   @0x1a2700 mov r3, r6
 *   @0x1a2704 mov r2, r8
 *   @0x1a2708 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a270c b 0x1a1590 <_Z12Eff_Effect06iffij>
 *   @0x1a2710 str r7, [sp, #0x20]
 *   @0x1a2714 mov r1, r9
 *   @0x1a2718 mov r3, r6
 *   @0x1a271c mov r2, r8
 *   @0x1a2720 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a2724 b 0x1a17ec <_Z12Eff_Effect07iffij>
 *   @0x1a2728 str r7, [sp, #0x20]
 *   @0x1a272c mov r1, r9
 *   @0x1a2730 mov r3, r6
 *   @0x1a2734 mov r2, r8
 *   @0x1a2738 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a273c b 0x1a1a44 <_Z12Eff_Effect08iffij>
 *   @0x1a2740 str r7, [sp, #0x20]
 *   @0x1a2744 mov r1, r9
 *   @0x1a2748 mov r3, r6
 *   @0x1a274c mov r2, r8
 *   @0x1a2750 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a2754 b 0x1a1c9c <_Z12Eff_Effect09iffij>
 *   @0x1a2758 str r7, [sp, #0x20]
 *   @0x1a275c mov r1, r9
 *   @0x1a2760 mov r3, r6
 *   @0x1a2764 mov r2, r8
 *   @0x1a2768 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a276c b 0x1a1ed0 <_Z12Eff_Effect10iffij>
 *   @0x1a2770 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a2774 eoreq lr, r4, r8, lsr #3
 *   @0x1a2778 eoreq lr, r4, r4, ror #2
 *
 * ══ §39/70 _spAtlasAttachmentLoader_createAttachment  0x284a08  size 428  107 条（0x284a08..0x284bb4）
 * @func 0x284a08 0x284bb4  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAtlas_findRegion×2 / _spAttachmentLoader_setError×2 / spPathAttachment_create / spMeshAttachment_create / spBoundingBoxAttachment_create / spRegionAttachment_create / spRegionAttachment_setUVs / _spAttachmentLoader_setUnknownTypeError
 * 字段偏移 top8: 0x20×6 / 0xc×4 / 0x30×4 / 0x24×3 / 0x28×3 / 0x2c×3 / 0x38×3 / 0x18×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284a08 push {r4, r5, r6, r7, r8, lr}
 *   @0x284a0c mov r6, r0
 *   @0x284a10 sub sp, sp, #8
 *   @0x284a14 mov r5, r3
 *   @0x284a18 cmp r2, #4
 *   @0x284a1c addls pc, pc, r2, lsl #2
 *   @0x284a20 b 0x284b60 <_spAtlasAttachmentLoader_createAttachment+0x158>
 *   @0x284a24 b 0x284ae0 <_spAtlasAttachmentLoader_createAttachment+0xd8>
 *   @0x284a28 b 0x284ad0 <_spAtlasAttachmentLoader_createAttachment+0xc8>
 *   @0x284a2c b 0x284a48 <_spAtlasAttachmentLoader_createAttachment+0x40>
 *   @0x284a30 b 0x284a48 <_spAtlasAttachmentLoader_createAttachment+0x40>
 *   @0x284a34 b 0x284a38 <_spAtlasAttachmentLoader_createAttachment+0x30>
 *   @0x284a38 mov r0, r3
 *   @0x284a3c bl 0x2876f4 <spPathAttachment_create>
 *   @0x284a40 add sp, sp, #8
 *   @0x284a44 pop {r4, r5, r6, r7, r8, pc}
 *   @0x284a48 ldr r0, [r0, #0xc]
 *   @0x284a4c ldr r1, [sp, #0x20]
 *   @0x284a50 bl 0x284958 <spAtlas_findRegion>
 *   @0x284a54 subs r4, r0, #0
 *   @0x284a58 beq 0x284b90 <_spAtlasAttachmentLoader_createAttachment+0x188>
 *   @0x284a5c mov r0, r5
 *   @0x284a60 bl 0x2874dc <spMeshAttachment_create>
 *   @0x284a64 ldr r2, [r4, #0x14]
 *   @0x284a68 ldr r7, [r4, #0x24]
 *   @0x284a6c ldr r6, [r4, #0x28]
 *   @0x284a70 ldr r5, [r4, #0xc]
 *   @0x284a74 ldr r12, [r4, #0x10]
 *   @0x284a78 ldr r1, [r4, #0x2c]
 *   @0x284a7c ldr r8, [r4, #0x20]
 *   @0x284a80 mov r3, r0
 *   @0x284a84 ldr r0, [r4, #0x38]
 *   @0x284a88 str r2, [r3, #0x40]
 *   @0x284a8c ldr r2, [r4, #0x18]
 *   @0x284a90 str r2, [r3, #0x44]
 *   @0x284a94 ldr r2, [r4, #0x1c]
 *   @0x284a98 str r2, [r3, #0x48]
 *   @0x284a9c ldr r2, [r4, #0x30]
 *   @0x284aa0 str r0, [r3, #0x50]
 *   @0x284aa4 mov r0, r3
 *   @0x284aa8 str r4, [r3, #0x24]
 *   @0x284aac str r8, [r3, #0x4c]
 *   @0x284ab0 str r7, [r3, #0x28]
 *   @0x284ab4 str r6, [r3, #0x2c]
 *   @0x284ab8 str r5, [r3, #0x30]
 *   @0x284abc str r12, [r3, #0x34]
 *   @0x284ac0 str r1, [r3, #0x38]
 *   @0x284ac4 str r2, [r3, #0x3c]
 *   @0x284ac8 add sp, sp, #8
 *   @0x284acc pop {r4, r5, r6, r7, r8, pc}
 *   @0x284ad0 mov r0, r3
 *   @0x284ad4 bl 0x285af8 <spBoundingBoxAttachment_create>
 *   @0x284ad8 add sp, sp, #8
 *   @0x284adc pop {r4, r5, r6, r7, r8, pc}
 *   @0x284ae0 ldr r0, [r0, #0xc]
 *   @0x284ae4 ldr r1, [sp, #0x20]
 *   @0x284ae8 bl 0x284958 <spAtlas_findRegion>
 *   @0x284aec subs r4, r0, #0
 *   @0x284af0 beq 0x284b74 <_spAtlasAttachmentLoader_createAttachment+0x16c>
 *   @0x284af4 mov r0, r5
 *   @0x284af8 bl 0x288f78 <spRegionAttachment_create>
 *   @0x284afc ldr r12, [r4, #0x20]
 *   @0x284b00 ldr r1, [r4, #0x14]
 *   @0x284b04 ldr r2, [r4, #0x18]
 *   @0x284b08 ldr r3, [r4, #0x1c]
 *   @0x284b0c str r4, [r0, #0x40]
 *   @0x284b10 mov r5, r0
 *   @0x284b14 str r12, [sp]
 *   @0x284b18 ldr r12, [r4, #0x38]
 *   @0x284b1c str r12, [sp, #0x4]
 *   @0x284b20 bl 0x288fdc <spRegionAttachment_setUVs>
 *   @0x284b24 ldr r7, [r4, #0x24]
 *   @0x284b28 ldr r6, [r4, #0x28]
 *   @0x284b2c mov r0, r5
 *   @0x284b30 ldr r12, [r4, #0xc]
 *   @0x284b34 ldr r1, [r4, #0x10]
 *   @0x284b38 ldr r2, [r4, #0x2c]
 *   @0x284b3c ldr r3, [r4, #0x30]
 *   @0x284b40 str r7, [r5, #0x44]
 *   @0x284b44 str r6, [r5, #0x48]
 *   @0x284b48 str r12, [r5, #0x4c]
 *   @0x284b4c str r1, [r5, #0x50]
 *   @0x284b50 str r2, [r5, #0x54]
 *   @0x284b54 str r3, [r5, #0x58]
 *   @0x284b58 add sp, sp, #8
 *   @0x284b5c pop {r4, r5, r6, r7, r8, pc}
 *   @0x284b60 mov r1, r2
 *   @0x284b64 bl 0x284e68 <_spAttachmentLoader_setUnknownTypeError>
 *   @0x284b68 mov r0, #0
 *   @0x284b6c add sp, sp, #8
 *   @0x284b70 pop {r4, r5, r6, r7, r8, pc}
 *   @0x284b74 ldr r1, [pc, #0x30]
 *   @0x284b78 mov r0, r6
 *   @0x284b7c ldr r2, [sp, #0x20]
 *   @0x284b80 add r1, pc, r1
 *   @0x284b84 bl 0x284df0 <_spAttachmentLoader_setError>
 *   @0x284b88 mov r0, r4
 *   @0x284b8c b 0x284a40 <_spAtlasAttachmentLoader_createAttachment+0x38>
 *   @0x284b90 ldr r1, [pc, #0x18]
 *   @0x284b94 mov r0, r6
 *   @0x284b98 ldr r2, [sp, #0x20]
 *   @0x284b9c add r1, pc, r1
 *   @0x284ba0 bl 0x284df0 <_spAttachmentLoader_setError>
 *   @0x284ba4 mov r0, r4
 *   @0x284ba8 b 0x284a40 <_spAtlasAttachmentLoader_createAttachment+0x38>
 *   @0x284bac andeq r2, sp, r12, ror r10
 *   @0x284bb0 andeq r2, sp, r0, ror #20
 *
 * ══ §40/70 yyServer::ProcessUDP()  0x297dec  size 428  107 条（0x297dec..0x297f98）
 * @func 0x297dec 0x297f98  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2 / yyServer::ProcessUDP()+0x18c×2 / 0xb6d84 / yyServer::ProcessUDP()+0x19c / yySocket::ReadFrom(void*, unsigned int, unsigned int, char**, int*) / 0xb65a4 / yyServer::ProcessDataPacket(yySocket*, unsigned char*, int) / yySocket::Peek()
 * 字段偏移 top8: 0xc×7 / 0x10×5 / 0x8×4 / 0x4×3 / 0x14×3 / 0x194×1 / 0x20×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x297dec ldr r1, [r0, #0x8]
 *   @0x297df0 mov r2, #128
 *   @0x297df4 ldr r3, [pc, #0x194]
 *   @0x297df8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x297dfc add r6, r1, #8
 *   @0x297e00 sub sp, sp, #44
 *   @0x297e04 ldr r12, [r0]
 *   @0x297e08 ldr r11, [r0, #0x4]
 *   @0x297e0c ldr r3, [pc, r3]
 *   @0x297e10 str r1, [sp, #0x14]
 *   @0x297e14 mov r5, r0
 *   @0x297e18 add r1, r11, #8
 *   @0x297e1c mov r0, r6
 *   @0x297e20 str r12, [r3]
 *   @0x297e24 bl 0xb65bc <memcpy@plt>
 *   @0x297e28 ldr r2, [sp, #0x14]
 *   @0x297e2c mov r4, #0
 *   @0x297e30 add r1, r11, #136
 *   @0x297e34 add r0, r2, #136
 *   @0x297e38 mov r2, #4096
 *   @0x297e3c bl 0xb65bc <memcpy@plt>
 *   @0x297e40 add r12, sp, #32
 *   @0x297e44 mov r1, r6
 *   @0x297e48 mov r2, r4
 *   @0x297e4c mov r3, r4
 *   @0x297e50 mov r0, #1024
 *   @0x297e54 str r12, [sp]
 *   @0x297e58 str r4, [sp, #0x20]
 *   @0x297e5c str r4, [sp, #0x24]
 *   @0x297e60 bl 0xb6d84 <select@plt>
 *   @0x297e64 cmp r0, r4
 *   @0x297e68 ble 0x297f88 <_ZN8yyServer10ProcessUDPEv+0x19c>
 *   @0x297e6c ldr r3, [pc, #0x120]
 *   @0x297e70 add r10, sp, #24
 *   @0x297e74 add r9, sp, #28
 *   @0x297e78 add r11, r11, #132
 *   @0x297e7c add r3, pc, r3
 *   @0x297e80 mov r1, #1024
 *   @0x297e84 str r3, [sp, #0x10]
 *   @0x297e88 str r11, [sp, #0xc]
 *   @0x297e8c str r1, [sp, #0x8]
 *   @0x297e90 ldr r2, [sp, #0xc]
 *   @0x297e94 ldr r4, [r2, #0x4]!
 *   @0x297e98 cmp r4, #0
 *   @0x297e9c str r2, [sp, #0xc]
 *   @0x297ea0 beq 0x297f78 <_ZN8yyServer10ProcessUDPEv+0x18c>
 *   @0x297ea4 ldr r3, [r4]
 *   @0x297ea8 ldr r1, [sp, #0x14]
 *   @0x297eac and r2, r3, #31
 *   @0x297eb0 asr r3, r3, #5
 *   @0x297eb4 add r3, r3, #2
 *   @0x297eb8 ldr r3, [r1, r3, lsl #2]
 *   @0x297ebc mov r1, #1
 *   @0x297ec0 ands r3, r3, r1, lsl r2
 *   @0x297ec4 beq 0x297f78 <_ZN8yyServer10ProcessUDPEv+0x18c>
 *   @0x297ec8 ldr r7, [r5, #0xc]
 *   @0x297ecc add r8, r4, #108
 *   @0x297ed0 ldr r6, [r5, #0x10]
 *   @0x297ed4 b 0x297f30 <_ZN8yyServer10ProcessUDPEv+0x144>
 *   @0x297ed8 mov r3, #0
 *   @0x297edc cmp r11, r3
 *   @0x297ee0 mov r2, r6
 *   @0x297ee4 mov r1, r7
 *   @0x297ee8 mov r0, r4
 *   @0x297eec ble 0x297f78 <_ZN8yyServer10ProcessUDPEv+0x18c>
 *   @0x297ef0 str r10, [sp]
 *   @0x297ef4 str r9, [sp, #0x4]
 *   @0x297ef8 bl 0x2952ec <_ZN8yySocket8ReadFromEPvjjPPcPi>
 *   @0x297efc subs r11, r0, #0
 *   @0x297f00 mov r0, r8
 *   @0x297f04 ble 0x297f78 <_ZN8yyServer10ProcessUDPEv+0x18c>
 *   @0x297f08 ldr r1, [sp, #0x18]
 *   @0x297f0c bl 0xb65a4 <strcpy@plt>
 *   @0x297f10 ldr r12, [sp, #0x1c]
 *   @0x297f14 ldr r2, [r5, #0xc]
 *   @0x297f18 mov r3, r11
 *   @0x297f1c mov r0, r5
 *   @0x297f20 mov r1, r4
 *   @0x297f24 str r12, [r4, #0xac]
 *   @0x297f28 str r12, [r4, #0xb0]
 *   @0x297f2c bl 0x2975a4 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi>
 *   @0x297f30 mov r0, r4
 *   @0x297f34 bl 0x295438 <_ZN8yySocket4PeekEv>
 *   @0x297f38 ldr r3, [r5, #0x10]
 *   @0x297f3c cmp r0, r3
 *   @0x297f40 mov r11, r0
 *   @0x297f44 ble 0x297ed8 <_ZN8yyServer10ProcessUDPEv+0xec>
 *   @0x297f48 add r6, r3, #32768
 *   @0x297f4c mov r2, #0
 *   @0x297f50 mov r3, #74
 *   @0x297f54 str r2, [sp]
 *   @0x297f58 mov r1, r6
 *   @0x297f5c ldr r0, [r5, #0xc]
 *   @0x297f60 ldr r2, [sp, #0x10]
 *   @0x297f64 str r6, [r5, #0x10]
 *   @0x297f68 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x297f6c mov r7, r0
 *   @0x297f70 str r0, [r5, #0xc]
 *   @0x297f74 b 0x297ed8 <_ZN8yyServer10ProcessUDPEv+0xec>
 *   @0x297f78 ldr r3, [sp, #0x8]
 *   @0x297f7c subs r3, r3, #1
 *   @0x297f80 str r3, [sp, #0x8]
 *   @0x297f84 bne 0x297e90 <_ZN8yyServer10ProcessUDPEv+0xa4>
 *   @0x297f88 add sp, sp, #44
 *   @0x297f8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x297f90 mulseq r5, r4, r11
 *   @0x297f94 strheq r9, [r9], -r4
 *
 * ══ §41/70 Debug_GetInstances(Buffer_Standard*, Buffer_Standard*)  0x29ab8c  size 428  107 条（0x29ab8c..0x29ad38）
 * @func 0x29ab8c 0x29ad38  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)×2 / Debug_GetInstances(Buffer_Standard*, Buffer_Standard*)+0x160 / Debug_GetInstances(Buffer_Standard*, Buffer_Standard*)+0x12c / VM::WriteInstanceBuiltInVariables(Buffer_Standard*, CInstance*)
 * 字段偏移 top8: 0x8×6 / 0x4×5 / 0x38×4 / 0xc×3 / 0x30×3 / 0x2c×2 / 0xbc×1 / 0x3×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29ab8c ldr r12, [r0]
 *   @0x29ab90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29ab94 add r7, r0, #44
 *   @0x29ab98 mov r10, r1
 *   @0x29ab9c sub sp, sp, #12
 *   @0x29aba0 mov r2, r7
 *   @0x29aba4 mov r6, #0
 *   @0x29aba8 ldr r12, [r12, #0xc]
 *   @0x29abac mov r1, #5
 *   @0x29abb0 mov r8, r0
 *   @0x29abb4 blx r12
 *   @0x29abb8 mov r1, r6
 *   @0x29abbc mov r0, r7
 *   @0x29abc0 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29abc4 ldr r12, [r10]
 *   @0x29abc8 add r9, r10, #44
 *   @0x29abcc str r6, [r10, #0x38]
 *   @0x29abd0 mov r1, #5
 *   @0x29abd4 mov r2, r9
 *   @0x29abd8 vmov s15, r0
 *   @0x29abdc str r0, [sp, #0x4]
 *   @0x29abe0 mov r0, r10
 *   @0x29abe4 vcvt.f64.u32 d7, s15
 *   @0x29abe8 vmov r4, r5, d7
 *   @0x29abec vstr s14, [r10, #44]
 *   @0x29abf0 str r5, [r10, #0x30]
 *   @0x29abf4 ldr r12, [r12, #0x8]
 *   @0x29abf8 blx r12
 *   @0x29abfc ldr r3, [sp, #0x4]
 *   @0x29ac00 cmp r3, r6
 *   @0x29ac04 ble 0x29acec <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x160>
 *   @0x29ac08 mov r11, r6
 *   @0x29ac0c movt r11, #0x3ff0
 *   @0x29ac10 mov r5, r6
 *   @0x29ac14 ldr r12, [r8]
 *   @0x29ac18 mov r2, r7
 *   @0x29ac1c mov r1, #5
 *   @0x29ac20 mov r0, r8
 *   @0x29ac24 ldr r12, [r12, #0xc]
 *   @0x29ac28 blx r12
 *   @0x29ac2c mov r1, #0
 *   @0x29ac30 mov r0, r7
 *   @0x29ac34 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29ac38 ldr r3, [r10]
 *   @0x29ac3c str r5, [r10, #0x38]
 *   @0x29ac40 mov r1, #5
 *   @0x29ac44 mov r2, r9
 *   @0x29ac48 vmov s13, r0
 *   @0x29ac4c mov r4, r0
 *   @0x29ac50 mov r0, r10
 *   @0x29ac54 vcvt.f64.u32 d7, s13
 *   @0x29ac58 vstr s14, [r10, #44]
 *   @0x29ac5c vstr s15, [r10, #48]
 *   @0x29ac60 ldr r12, [r3, #0x8]
 *   @0x29ac64 blx r12
 *   @0x29ac68 cmp r4, #0
 *   @0x29ac6c blt 0x29acb8 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x12c>
 *   @0x29ac70 ldr r2, [pc, #0xbc]
 *   @0x29ac74 ldr r2, [pc, r2]
 *   @0x29ac78 ldr r1, [r2, #0x4]
 *   @0x29ac7c ldr r2, [r2]
 *   @0x29ac80 and r1, r4, r1
 *   @0x29ac84 ldr r2, [r2, r1, lsl #3]
 *   @0x29ac88 cmp r2, #0
 *   @0x29ac8c beq 0x29acb8 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x12c>
 *   @0x29ac90 ldr r1, [r2, #0x8]
 *   @0x29ac94 cmp r4, r1
 *   @0x29ac98 bne 0x29acac <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x120>
 *   @0x29ac9c b 0x29acf4 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x168>
 *   @0x29aca0 ldr r3, [r2, #0x8]
 *   @0x29aca4 cmp r4, r3
 *   @0x29aca8 beq 0x29acf4 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x168>
 *   @0x29acac ldr r2, [r2, #0x4]
 *   @0x29acb0 cmp r2, #0
 *   @0x29acb4 bne 0x29aca0 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x114>
 *   @0x29acb8 ldr r12, [r10]
 *   @0x29acbc mov r0, r10
 *   @0x29acc0 str r5, [r10, #0x2c]
 *   @0x29acc4 mov r1, #5
 *   @0x29acc8 str r5, [r10, #0x30]
 *   @0x29accc mov r2, r9
 *   @0x29acd0 str r5, [r10, #0x38]
 *   @0x29acd4 ldr r12, [r12, #0x8]
 *   @0x29acd8 blx r12
 *   @0x29acdc ldr r3, [sp, #0x4]
 *   @0x29ace0 add r6, r6, #1
 *   @0x29ace4 cmp r3, r6
 *   @0x29ace8 bne 0x29ac14 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x88>
 *   @0x29acec add sp, sp, #12
 *   @0x29acf0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29acf4 ldr r4, [r2, #0xc]
 *   @0x29acf8 cmp r4, #0
 *   @0x29acfc beq 0x29acb8 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x12c>
 *   @0x29ad00 ldr r12, [r10]
 *   @0x29ad04 mov r0, r10
 *   @0x29ad08 str r5, [r10, #0x2c]
 *   @0x29ad0c mov r1, #5
 *   @0x29ad10 str r11, [r10, #0x30]
 *   @0x29ad14 mov r2, r9
 *   @0x29ad18 str r5, [r10, #0x38]
 *   @0x29ad1c ldr r12, [r12, #0x8]
 *   @0x29ad20 blx r12
 *   @0x29ad24 mov r0, r10
 *   @0x29ad28 mov r1, r4
 *   @0x29ad2c bl 0xd96f0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance>
 *   @0x29ad30 b 0x29acdc <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x150>
 *   @0x29ad34 ldrsbeq r2, [r5], -r0
 *
 * ══ §42/70 jinit_merged_upsampler  0x2b6f9c  size 428  107 条（0x2b6f9c..0x2b7148）
 * @func 0x2b6f9c 0x2b7148  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×9 / 0x1a0×2 / 0x140×2 / 0x20×2 / 0xc×2 / 0x10×2 / 0x14×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b6f9c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b6fa0 mov r1, #1
 *   @0x2b6fa4 ldr r3, [r0, #0x4]
 *   @0x2b6fa8 mov r2, #48
 *   @0x2b6fac mov r4, r0
 *   @0x2b6fb0 ldr r3, [r3]
 *   @0x2b6fb4 blx r3
 *   @0x2b6fb8 mov r3, #0
 *   @0x2b6fbc ldr r1, [pc, #0x170]
 *   @0x2b6fc0 add r1, pc, r1
 *   @0x2b6fc4 str r0, [r4, #0x1a0]
 *   @0x2b6fc8 mov r5, r0
 *   @0x2b6fcc strb r3, [r0, #0x8]
 *   @0x2b6fd0 ldr r2, [r4, #0x64]
 *   @0x2b6fd4 ldr r12, [r4, #0x5c]
 *   @0x2b6fd8 ldr r0, [r4, #0x114]
 *   @0x2b6fdc str r1, [r5]
 *   @0x2b6fe0 mul r2, r12, r2
 *   @0x2b6fe4 cmp r0, #2
 *   @0x2b6fe8 str r2, [r5, #0x28]
 *   @0x2b6fec beq 0x2b7100 <jinit_merged_upsampler+0x164>
 *   @0x2b6ff0 ldr r1, [pc, #0x140]
 *   @0x2b6ff4 ldr r2, [pc, #0x140]
 *   @0x2b6ff8 add r1, pc, r1
 *   @0x2b6ffc str r3, [r5, #0x20]
 *   @0x2b7000 add r2, pc, r2
 *   @0x2b7004 str r1, [r5, #0x4]
 *   @0x2b7008 str r2, [r5, #0xc]
 *   @0x2b700c ldr r3, [r4, #0x4]
 *   @0x2b7010 mov r0, r4
 *   @0x2b7014 mov r1, #1
 *   @0x2b7018 mov r2, #1024
 *   @0x2b701c ldr r5, [r4, #0x1a0]
 *   @0x2b7020 ldr r3, [r3]
 *   @0x2b7024 blx r3
 *   @0x2b7028 ldr r3, [r4, #0x4]
 *   @0x2b702c mov r1, #1
 *   @0x2b7030 mov r2, #1024
 *   @0x2b7034 ldr r3, [r3]
 *   @0x2b7038 str r0, [r5, #0x10]
 *   @0x2b703c mov r0, r4
 *   @0x2b7040 blx r3
 *   @0x2b7044 ldr r3, [r4, #0x4]
 *   @0x2b7048 mov r1, #1
 *   @0x2b704c mov r2, #1024
 *   @0x2b7050 ldr r3, [r3]
 *   @0x2b7054 str r0, [r5, #0x14]
 *   @0x2b7058 mov r0, r4
 *   @0x2b705c blx r3
 *   @0x2b7060 ldr r3, [r4, #0x4]
 *   @0x2b7064 mov r1, #1
 *   @0x2b7068 mov r2, #1024
 *   @0x2b706c ldr r3, [r3]
 *   @0x2b7070 str r0, [r5, #0x18]
 *   @0x2b7074 mov r0, r4
 *   @0x2b7078 blx r3
 *   @0x2b707c ldr r9, [r5, #0x10]
 *   @0x2b7080 ldr r8, [r5, #0x14]
 *   @0x2b7084 mov r4, #36096
 *   @0x2b7088 ldr r7, [r5, #0x18]
 *   @0x2b708c mov r12, #26880
 *   @0x2b7090 mov r2, #44800
 *   @0x2b7094 mov r3, #2944
 *   @0x2b7098 movt r4, #0x2c
 *   @0x2b709c movt r12, #0x5b
 *   @0x2b70a0 movt r2, #0xff1d
 *   @0x2b70a4 movt r3, #0xff4d
 *   @0x2b70a8 mov r1, #0
 *   @0x2b70ac str r0, [r5, #0x1c]
 *   @0x2b70b0 asr r6, r3, #16
 *   @0x2b70b4 asr r5, r2, #16
 *   @0x2b70b8 str r6, [r9, r1]
 *   @0x2b70bc add r3, r3, #91136
 *   @0x2b70c0 str r5, [r8, r1]
 *   @0x2b70c4 add r2, r2, #115712
 *   @0x2b70c8 str r12, [r7, r1]
 *   @0x2b70cc add r3, r3, #744
 *   @0x2b70d0 str r4, [r0, r1]
 *   @0x2b70d4 add r1, r1, #4
 *   @0x2b70d8 cmp r1, #1024
 *   @0x2b70dc add r2, r2, #416
 *   @0x2b70e0 sub r12, r12, #46592
 *   @0x2b70e4 sub r4, r4, #22528
 *   @0x2b70e8 add r3, r3, #1
 *   @0x2b70ec add r2, r2, #2
 *   @0x2b70f0 sub r12, r12, #210
 *   @0x2b70f4 sub r4, r4, #26
 *   @0x2b70f8 bne 0x2b70b0 <jinit_merged_upsampler+0x114>
 *   @0x2b70fc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2b7100 ldr r3, [r4, #0x4]
 *   @0x2b7104 mov r0, r4
 *   @0x2b7108 ldr lr, [pc, #0x30]
 *   @0x2b710c mov r1, #1
 *   @0x2b7110 ldr r12, [pc, #0x2c]
 *   @0x2b7114 add lr, pc, lr
 *   @0x2b7118 ldr r3, [r3, #0x4]
 *   @0x2b711c add r12, pc, r12
 *   @0x2b7120 str lr, [r5, #0x4]
 *   @0x2b7124 str r12, [r5, #0xc]
 *   @0x2b7128 blx r3
 *   @0x2b712c str r0, [r5, #0x20]
 *   @0x2b7130 b 0x2b700c <jinit_merged_upsampler+0x70>
 *   @0x2b7134 .word 0xfffffa70
 *   @0x2b7138 .word 0xfffffa50
 *   @0x2b713c .word 0xfffffa8c
 *   @0x2b7140 .word 0xfffffd7c
 *   @0x2b7144 .word 0xfffffb18
 *
 * ══ §43/70 F_BUFFER_Create_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6c78  size 424  106 条（0xc6c78..0xc6e20）
 * @func 0xc6c78 0xc6e20  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / GetBufferVertex(int) / GetVertexFormat(int) / CreateBuffer(int, eBuffer_Format, int) / GetIBuffer(int) / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool) / IsBigEndian() / VertexFormat::EndianSwapBuffer(unsigned char*, int, int, int, bool)
 * 字段偏移 top8: 0xc×3 / 0x1c×3 / 0x4×2 / 0x28×2 / 0x38×1 / 0x20×1 / 0x144×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6c78 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc6c7c sub sp, sp, #24
 *   @0xc6c80 mov r4, #0
 *   @0xc6c84 mov r6, r0
 *   @0xc6c88 ldr r5, [sp, #0x38]
 *   @0xc6c8c mov r1, r4
 *   @0xc6c90 str r4, [r0, #0xc]
 *   @0xc6c94 mov r3, r4
 *   @0xc6c98 str r4, [r0]
 *   @0xc6c9c movt r3, #0xbff0
 *   @0xc6ca0 str r3, [r0, #0x4]
 *   @0xc6ca4 mov r0, r5
 *   @0xc6ca8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6cac bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc6cb0 subs r7, r0, #0
 *   @0xc6cb4 beq 0xc6dfc <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0xc6cb8 ldrb r8, [r7, #0x20]
 *   @0xc6cbc mov r1, r4
 *   @0xc6cc0 ldr r0, [pc, #0x144]
 *   @0xc6cc4 cmp r8, #0
 *   @0xc6cc8 add r0, pc, r0
 *   @0xc6ccc bne 0xc6da4 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0xc6cd0 ldr r3, [r7, #0x1c]
 *   @0xc6cd4 cmp r3, #0
 *   @0xc6cd8 beq 0xc6db0 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0xc6cdc ldr r3, [r7, #0x28]
 *   @0xc6ce0 cmn r3, #1
 *   @0xc6ce4 beq 0xc6db0 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0xc6ce8 mov r0, r5
 *   @0xc6cec mov r1, #2
 *   @0xc6cf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6cf4 sub r3, r0, #1
 *   @0xc6cf8 mov r4, r0
 *   @0xc6cfc cmp r3, #1024
 *   @0xc6d00 bhs 0xc6de4 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0xc6d04 ldr r0, [r7, #0x28]
 *   @0xc6d08 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc6d0c ldr r3, [r7, #0x1c]
 *   @0xc6d10 mov r1, #1
 *   @0xc6d14 ldr r10, [r0, #0x14]
 *   @0xc6d18 mov r9, r0
 *   @0xc6d1c mov r0, r5
 *   @0xc6d20 mul r10, r10, r3
 *   @0xc6d24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6d28 mov r2, r4
 *   @0xc6d2c mov r1, r0
 *   @0xc6d30 mov r0, r10
 *   @0xc6d34 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati>
 *   @0xc6d38 vmov s15, r0
 *   @0xc6d3c vcvt.f64.s32 d7, s15
 *   @0xc6d40 vmov r4, r5, d7
 *   @0xc6d44 vmov r2, s14
 *   @0xc6d48 mov r3, r5
 *   @0xc6d4c stm r6, {r2, r3}
 *   @0xc6d50 bl 0xc6720 <_Z10GetIBufferi>
 *   @0xc6d54 subs r5, r0, #0
 *   @0xc6d58 beq 0xc6d98 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0xc6d5c ldr r1, [r7]
 *   @0xc6d60 mov r2, r10
 *   @0xc6d64 mov r3, r8
 *   @0xc6d68 str r8, [sp, #0x4]
 *   @0xc6d6c mvn r4, #0
 *   @0xc6d70 str r8, [sp, #0x8]
 *   @0xc6d74 str r8, [sp, #0xc]
 *   @0xc6d78 str r8, [sp, #0x10]
 *   @0xc6d7c str r4, [sp]
 *   @0xc6d80 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0xc6d84 bl 0x212e98 <_Z11IsBigEndianv>
 *   @0xc6d88 cmp r0, #0
 *   @0xc6d8c bne 0xc6dc8 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0xc6d90 add sp, sp, #24
 *   @0xc6d94 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc6d98 ldr r0, [pc, #0x70]
 *   @0xc6d9c mov r1, r5
 *   @0xc6da0 add r0, pc, r0
 *   @0xc6da4 add sp, sp, #24
 *   @0xc6da8 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc6dac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6db0 ldr r0, [pc, #0x5c]
 *   @0xc6db4 mov r1, #0
 *   @0xc6db8 add r0, pc, r0
 *   @0xc6dbc add sp, sp, #24
 *   @0xc6dc0 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc6dc4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6dc8 ldr r1, [r5, #0xc]
 *   @0xc6dcc mov r0, r9
 *   @0xc6dd0 ldr r2, [r7, #0x1c]
 *   @0xc6dd4 mov r3, r8
 *   @0xc6dd8 stm sp, {r4, r8}
 *   @0xc6ddc bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib>
 *   @0xc6de0 b 0xc6d90 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0xc6de4 ldr r0, [pc, #0x2c]
 *   @0xc6de8 mov r1, r8
 *   @0xc6dec add r0, pc, r0
 *   @0xc6df0 add sp, sp, #24
 *   @0xc6df4 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc6df8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6dfc ldr r0, [pc, #0x18]
 *   @0xc6e00 mov r1, r7
 *   @0xc6e04 add r0, pc, r0
 *   @0xc6e08 b 0xc6da4 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0xc6e0c .word 0x0026a4b0
 *   @0xc6e10 .word 0x0026a4b8
 *   @0xc6e14 eoreq r10, r6, r4, lsl r4
 *   @0xc6e18 eoreq r10, r6, r0, lsr r4
 *   @0xc6e1c eoreq r10, r6, r8, lsr #6
 *
 * ══ §44/70 VM::GetGlobalVariables(Buffer_Standard*, bool)  0xd8c20  size 424  106 条（0xd8c20..0xd8dc8）
 * @func 0xd8c20 0xd8dc8  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×2 / VM::GetGlobalVariables(Buffer_Standard*, bool)+0x198 / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)
 * 字段偏移 top8: 0x4×4 / 0x30×3 / 0x38×3 / 0x8×3 / 0x1c×2 / 0x10×2 / 0x2c×1 / 0x14c×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8c20 ldr r3, [r0]
 *   @0xd8c24 ldr r12, [r0, #0x1c]
 *   @0xd8c28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd8c2c vpush {d8}
 *   @0xd8c30 add r9, r0, #44
 *   @0xd8c34 sub sp, sp, #12
 *   @0xd8c38 mov r7, #0
 *   @0xd8c3c mov r4, r1
 *   @0xd8c40 str r7, [r0, #0x2c]
 *   @0xd8c44 str r7, [r0, #0x30]
 *   @0xd8c48 mov r2, r9
 *   @0xd8c4c mov r1, #5
 *   @0xd8c50 str r7, [r0, #0x38]
 *   @0xd8c54 ldr r3, [r3, #0x8]
 *   @0xd8c58 mov r6, r0
 *   @0xd8c5c str r12, [sp, #0x4]
 *   @0xd8c60 blx r3
 *   @0xd8c64 cmp r4, r7
 *   @0xd8c68 beq 0xd8d8c <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x16c>
 *   @0xd8c6c ldr r10, [pc, #0x14c]
 *   @0xd8c70 ldr r10, [pc, r10]
 *   @0xd8c74 ldr r3, [r10]
 *   @0xd8c78 cmp r3, r7
 *   @0xd8c7c ble 0xd8db8 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x198>
 *   @0xd8c80 ldr r8, [pc, #0x13c]
 *   @0xd8c84 mov r11, r7
 *   @0xd8c88 str r7, [sp]
 *   @0xd8c8c ldr r8, [pc, r8]
 *   @0xd8c90 ldr r0, [r8]
 *   @0xd8c94 ldr r2, [r0, #0x4]
 *   @0xd8c98 cmp r2, #0
 *   @0xd8c9c add r12, r2, r7
 *   @0xd8ca0 beq 0xd8d98 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x178>
 *   @0xd8ca4 ldr r12, [r12, #0xc]
 *   @0xd8ca8 mvn r3, #-16777216
 *   @0xd8cac mov r1, #6
 *   @0xd8cb0 mov r2, r9
 *   @0xd8cb4 cmp r12, r3
 *   @0xd8cb8 mov r0, r6
 *   @0xd8cbc beq 0xd8d10 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0xf0>
 *   @0xd8cc0 vmov s15, r11
 *   @0xd8cc4 mov r12, #0
 *   @0xd8cc8 str r12, [r6, #0x38]
 *   @0xd8ccc vcvt.f64.s32 d7, s15
 *   @0xd8cd0 ldr r12, [r6]
 *   @0xd8cd4 vmov r4, r5, d7
 *   @0xd8cd8 vstr s14, [r6, #44]
 *   @0xd8cdc str r5, [r6, #0x30]
 *   @0xd8ce0 ldr r12, [r12, #0x8]
 *   @0xd8ce4 blx r12
 *   @0xd8ce8 ldr r1, [r8]
 *   @0xd8cec ldr r2, [r1, #0x4]
 *   @0xd8cf0 cmp r2, #0
 *   @0xd8cf4 add r0, r2, r7
 *   @0xd8cf8 beq 0xd8da8 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x188>
 *   @0xd8cfc ldr r3, [sp]
 *   @0xd8d00 mov r1, r6
 *   @0xd8d04 add r3, r3, #1
 *   @0xd8d08 str r3, [sp]
 *   @0xd8d0c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xd8d10 ldr r2, [r10]
 *   @0xd8d14 add r11, r11, #1
 *   @0xd8d18 add r7, r7, #16
 *   @0xd8d1c cmp r2, r11
 *   @0xd8d20 bgt 0xd8c90 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x70>
 *   @0xd8d24 vldr s16, [sp]
 *   @0xd8d28 ldr r3, [r6]
 *   @0xd8d2c mov r1, #0
 *   @0xd8d30 ldr r2, [sp, #0x4]
 *   @0xd8d34 mov r0, r6
 *   @0xd8d38 mov r7, r1
 *   @0xd8d3c ldr r8, [r6, #0x1c]
 *   @0xd8d40 ldr r3, [r3, #0x10]
 *   @0xd8d44 blx r3
 *   @0xd8d48 vcvt.f64.u32 d7, s16
 *   @0xd8d4c ldr r3, [r6]
 *   @0xd8d50 mov r2, r9
 *   @0xd8d54 mov r1, #5
 *   @0xd8d58 str r7, [r6, #0x38]
 *   @0xd8d5c mov r0, r6
 *   @0xd8d60 vmov r4, r5, d7
 *   @0xd8d64 vstr s14, [r6, #44]
 *   @0xd8d68 str r5, [r6, #0x30]
 *   @0xd8d6c ldr r3, [r3, #0x8]
 *   @0xd8d70 blx r3
 *   @0xd8d74 ldr r3, [r6]
 *   @0xd8d78 mov r1, r7
 *   @0xd8d7c mov r2, r8
 *   @0xd8d80 mov r0, r6
 *   @0xd8d84 ldr r3, [r3, #0x10]
 *   @0xd8d88 blx r3
 *   @0xd8d8c add sp, sp, #12
 *   @0xd8d90 vpop {d8}
 *   @0xd8d94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd8d98 mov r1, r11
 *   @0xd8d9c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0xd8da0 mov r12, r0
 *   @0xd8da4 b 0xd8ca4 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x84>
 *   @0xd8da8 mov r0, r1
 *   @0xd8dac mov r1, r11
 *   @0xd8db0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0xd8db4 b 0xd8cfc <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0xdc>
 *   @0xd8db8 vmov s16, r7
 *   @0xd8dbc b 0xd8d28 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x108>
 *   @0xd8dc0 mlaseq r1, r8, r0, r5
 *   @0xd8dc4 eorseq r4, r1, r8, lsr #30
 *
 * ══ §45/70 VM::GetInstanceVariables(Buffer_Standard*, YYObjectBase*, bool, int, int)  0xd9548  size 424  106 条（0xd9548..0xd96f0）
 * @func 0xd9548 0xd96f0  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::GetInstanceVariables(Buffer_Standard*, YYObjectBase*, bool, int, int)+0x1a0 / VM::GetInstanceVariables(Buffer_Standard*, YYObjectBase*, bool, int, int)+0xc0 / VM::GetInstanceVariables(Buffer_Standard*, YYObjectBase*, bool, int, int)+0xa0 / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)
 * 字段偏移 top8: 0x4×7 / 0x8×6 / 0x38×3 / 0xc×3 / 0x10×3 / 0x1c×2 / 0x30×2 / 0x2c×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd9548 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd954c vpush {d8}
 *   @0xd9550 sub sp, sp, #20
 *   @0xd9554 ldr lr, [r0]
 *   @0xd9558 add r12, r0, #44
 *   @0xd955c str r3, [sp, #0x8]
 *   @0xd9560 mov r4, r2
 *   @0xd9564 ldr r3, [r0, #0x1c]
 *   @0xd9568 eor r4, r4, #1
 *   @0xd956c str r12, [sp, #0x4]
 *   @0xd9570 mov r7, r1
 *   @0xd9574 mov r12, #0
 *   @0xd9578 ldr r2, [sp, #0x4]
 *   @0xd957c str r12, [r0, #0x2c]
 *   @0xd9580 mov r1, #5
 *   @0xd9584 str r12, [r0, #0x30]
 *   @0xd9588 cmp r7, #0
 *   @0xd958c orreq r4, r4, #1
 *   @0xd9590 ldr r6, [lr, #0x8]
 *   @0xd9594 mov r5, r0
 *   @0xd9598 str r12, [r0, #0x38]
 *   @0xd959c str r3, [sp, #0xc]
 *   @0xd95a0 blx r6
 *   @0xd95a4 cmp r4, #0
 *   @0xd95a8 bne 0xd96dc <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x194>
 *   @0xd95ac ldr r2, [r7, #0x60]
 *   @0xd95b0 cmp r2, #0
 *   @0xd95b4 beq 0xd96dc <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x194>
 *   @0xd95b8 ldr r8, [r2, #0x4]
 *   @0xd95bc cmp r8, #0
 *   @0xd95c0 ble 0xd96e8 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x1a0>
 *   @0xd95c4 mvn r11, #-16777216
 *   @0xd95c8 mov r9, r4
 *   @0xd95cc ldr r3, [r2, #0x4]
 *   @0xd95d0 cmp r3, r4
 *   @0xd95d4 movlt r3, #0
 *   @0xd95d8 blt 0xd9608 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0xc0>
 *   @0xd95dc ldr r3, [r2, #0x10]
 *   @0xd95e0 mov r2, #0
 *   @0xd95e4 b 0xd95ec <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0xa4>
 *   @0xd95e8 add r3, r3, #12
 *   @0xd95ec ldr r1, [r3, #0x8]
 *   @0xd95f0 cmp r1, #0
 *   @0xd95f4 ble 0xd95e8 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0xa0>
 *   @0xd95f8 cmp r4, r2
 *   @0xd95fc add r2, r2, #1
 *   @0xd9600 bne 0xd95e8 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0xa0>
 *   @0xd9604 ldr r10, [r3], #4
 *   @0xd9608 ldr r6, [r3]
 *   @0xd960c ldr r3, [r6, #0xc]
 *   @0xd9610 bic r3, r3, #-16777216
 *   @0xd9614 cmp r3, r11
 *   @0xd9618 beq 0xd9664 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x11c>
 *   @0xd961c ldr r12, [sp, #0x8]
 *   @0xd9620 mov r2, #0
 *   @0xd9624 mov r1, #6
 *   @0xd9628 str r2, [r5, #0x38]
 *   @0xd962c add r3, r12, r10
 *   @0xd9630 ldr r12, [r5]
 *   @0xd9634 mov r0, r5
 *   @0xd9638 ldr r2, [sp, #0x4]
 *   @0xd963c vmov s13, r3
 *   @0xd9640 add r9, r9, #1
 *   @0xd9644 vcvt.f64.s32 d7, s13
 *   @0xd9648 vstr s14, [r5, #44]
 *   @0xd964c vstr s15, [r5, #48]
 *   @0xd9650 ldr r3, [r12, #0x8]
 *   @0xd9654 blx r3
 *   @0xd9658 mov r0, r6
 *   @0xd965c mov r1, r5
 *   @0xd9660 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xd9664 add r4, r4, #1
 *   @0xd9668 cmp r4, r8
 *   @0xd966c ldrne r2, [r7, #0x60]
 *   @0xd9670 bne 0xd95cc <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x84>
 *   @0xd9674 vmov s16, r9
 *   @0xd9678 ldr r3, [r5]
 *   @0xd967c mov r1, #0
 *   @0xd9680 ldr r2, [sp, #0xc]
 *   @0xd9684 mov r0, r5
 *   @0xd9688 mov r4, r1
 *   @0xd968c ldr r8, [r5, #0x1c]
 *   @0xd9690 ldr r3, [r3, #0x10]
 *   @0xd9694 blx r3
 *   @0xd9698 vcvt.f64.u32 d7, s16
 *   @0xd969c ldr r3, [r5]
 *   @0xd96a0 mov r1, #5
 *   @0xd96a4 ldr r2, [sp, #0x4]
 *   @0xd96a8 mov r0, r5
 *   @0xd96ac str r4, [r5, #0x38]
 *   @0xd96b0 vmov r6, r7, d7
 *   @0xd96b4 vstr s14, [r5, #44]
 *   @0xd96b8 str r7, [r5, #0x30]
 *   @0xd96bc ldr r3, [r3, #0x8]
 *   @0xd96c0 blx r3
 *   @0xd96c4 ldr r3, [r5]
 *   @0xd96c8 mov r1, r4
 *   @0xd96cc mov r2, r8
 *   @0xd96d0 mov r0, r5
 *   @0xd96d4 ldr r3, [r3, #0x10]
 *   @0xd96d8 blx r3
 *   @0xd96dc add sp, sp, #20
 *   @0xd96e0 vpop {d8}
 *   @0xd96e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd96e8 vmov s16, r4
 *   @0xd96ec b 0xd9678 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x130>
 *
 * ══ §46/70 F_DrawBackgroundTiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x11f498  size 424  99 条（0x11f498..0x11f640）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x11f498 0x11f640  size 424  99 条
 * 部分覆盖: 本节 99/106 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x11f4a8→0x5428e8, 0x11f4f8→0x54298c, 0x11f5a0→0x54298c
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Get_Alpha()×2 / Sprite_Data(int) / CSprite::DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) / Background_Data(int) / CBackground::DrawTiled(float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x20×3 / 0x184×2 / 0x8×2 / 0xc×2 / 0x10×2 / 0x4×2 / 0x48×1 / 0x138×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11f498 push {r4, r5, r6, r7, lr}
 *   @0x11f49c vpush {d8}
 *   @0x11f4bc ldrb r1, [r3]
 *   @0x11f4c0 cmp r1, #0
 *   @0x11f4c4 beq 0x11f574 <_Z21F_DrawBackgroundTiledR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x11f4c8 mov r1, #0
 *   @0x11f4cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f4d0 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11f4d4 subs r6, r0, #0
 *   @0x11f4d8 beq 0x11f614 <_Z21F_DrawBackgroundTiledR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x11f4dc mov r0, r5
 *   @0x11f4e0 mov r1, #1
 *   @0x11f4e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f4e8 mov r1, #2
 *   @0x11f4ec mov r7, r0
 *   @0x11f4f0 mov r0, r5
 *   @0x11f4f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f4f8 ldr r3, [pc, #0x138]
 *   @0x11f4fc ldr r3, [r4, r3]
 *   @0x11f500 ldr r1, [r3]
 *   @0x11f504 vldr s17, [r1, #16]
 *   @0x11f508 vldr s16, [r1, #20]
 *   @0x11f50c vcvt.f32.s32 s17, s17
 *   @0x11f510 vcvt.f32.s32 s16, s16
 *   @0x11f514 mov r5, r0
 *   @0x11f518 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11f51c mov r1, #1
 *   @0x11f520 mov r12, #0
 *   @0x11f524 str r1, [sp, #0x8]
 *   @0x11f528 vstr s17, [sp, #24]
 *   @0x11f52c str r1, [sp, #0xc]
 *   @0x11f530 mov r2, r7
 *   @0x11f534 str r12, [sp, #0x10]
 *   @0x11f538 mov r3, r5
 *   @0x11f53c str r12, [sp, #0x14]
 *   @0x11f540 mov r1, #0
 *   @0x11f544 mvn r12, #-16777216
 *   @0x11f548 vstr s16, [sp, #28]
 *   @0x11f54c str r12, [sp, #0x20]
 *   @0x11f550 mov r12, #1065353216
 *   @0x11f554 str r12, [sp]
 *   @0x11f558 str r12, [sp, #0x4]
 *   @0x11f55c str r0, [sp, #0x24]
 *   @0x11f560 mov r0, r6
 *   @0x11f564 bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf>
 *   @0x11f568 add sp, sp, #44
 *   @0x11f56c vpop {d8}
 *   @0x11f570 pop {r4, r5, r6, r7, pc}
 *   @0x11f574 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f578 bl 0xc3794 <_Z15Background_Datai>
 *   @0x11f57c subs r6, r0, #0
 *   @0x11f580 beq 0x11f614 <_Z21F_DrawBackgroundTiledR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x11f584 mov r0, r5
 *   @0x11f588 mov r1, #1
 *   @0x11f58c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f590 mov r1, #2
 *   @0x11f594 mov r7, r0
 *   @0x11f598 mov r0, r5
 *   @0x11f59c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f5a0 ldr r3, [pc, #0x90]
 *   @0x11f5a4 ldr r3, [r4, r3]
 *   @0x11f5a8 ldr r3, [r3]
 *   @0x11f5ac vldr s17, [r3, #16]
 *   @0x11f5b0 vldr s16, [r3, #20]
 *   @0x11f5b4 vcvt.f32.s32 s17, s17
 *   @0x11f5b8 vcvt.f32.s32 s16, s16
 *   @0x11f5bc mov r5, r0
 *   @0x11f5c0 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11f5c4 mov r12, #0
 *   @0x11f5c8 mov r3, #1
 *   @0x11f5cc vstr s17, [sp, #20]
 *   @0x11f5d0 str r3, [sp, #0x4]
 *   @0x11f5d4 str r3, [sp, #0x8]
 *   @0x11f5d8 mov r1, r7
 *   @0x11f5dc mov r2, r5
 *   @0x11f5e0 str r12, [sp, #0xc]
 *   @0x11f5e4 str r12, [sp, #0x10]
 *   @0x11f5e8 mvn r3, #-16777216
 *   @0x11f5ec vstr s16, [sp, #24]
 *   @0x11f5f0 str r3, [sp, #0x1c]
 *   @0x11f5f4 mov r3, #1065353216
 *   @0x11f5f8 str r3, [sp]
 *   @0x11f5fc str r0, [sp, #0x20]
 *   @0x11f600 mov r0, r6
 *   @0x11f604 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf>
 *   @0x11f608 add sp, sp, #44
 *   @0x11f60c vpop {d8}
 *   @0x11f610 pop {r4, r5, r6, r7, pc}
 *   @0x11f614 ldr r0, [pc, #0x20]
 *   @0x11f618 mov r1, #0
 *   @0x11f61c add r0, pc, r0
 *   @0x11f620 add sp, sp, #44
 *   @0x11f624 vpop {d8}
 *   @0x11f628 pop {r4, r5, r6, r7, lr}
 *   @0x11f62c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11f630 eoreq r2, sp, r4, lsr #15
 *   @0x11f634 .word 0xffffbcd4
 *   @0x11f638 .word 0xffffbcd8
 *   @0x11f63c .word 0x0021abb8
 *
 * ══ §47/70 F_D3DBuildMatrixLookat(RValue&, CInstance*, CInstance*, int, RValue*)  0x144ae0  size 424  106 条（0x144ae0..0x144c88）
 * @func 0x144ae0 0x144c88  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / yyMatrix::LookAtLH(yyMatrix*, yyVector3*, yyVector3*, yyVector3*) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0x130×1 / 0x7c×1 / 0x80×1 / 0x84×1 / 0x88×1 / 0x8c×1 / 0x90×1 / 0x94×1
 * VFP 指令 50 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144ae0 push {r4, r5, r6, r7, lr}
 *   @0x144ae4 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x144ae8 sub sp, sp, #228
 *   @0x144aec mov r5, r0
 *   @0x144af0 mov r1, #0
 *   @0x144af4 ldr r4, [sp, #0x130]
 *   @0x144af8 mov r0, r4
 *   @0x144afc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b00 mov r1, #1
 *   @0x144b04 mov r7, r0
 *   @0x144b08 mov r0, r4
 *   @0x144b0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b10 mov r1, #2
 *   @0x144b14 mov r6, r0
 *   @0x144b18 mov r0, r4
 *   @0x144b1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b20 mov r1, #3
 *   @0x144b24 str r7, [sp, #0x7c]
 *   @0x144b28 str r6, [sp, #0x80]
 *   @0x144b2c str r0, [sp, #0x84]
 *   @0x144b30 mov r0, r4
 *   @0x144b34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b38 mov r1, #4
 *   @0x144b3c mov r7, r0
 *   @0x144b40 mov r0, r4
 *   @0x144b44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b48 mov r1, #5
 *   @0x144b4c mov r6, r0
 *   @0x144b50 mov r0, r4
 *   @0x144b54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b58 mov r1, #6
 *   @0x144b5c str r7, [sp, #0x88]
 *   @0x144b60 str r6, [sp, #0x8c]
 *   @0x144b64 str r0, [sp, #0x90]
 *   @0x144b68 mov r0, r4
 *   @0x144b6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b70 mov r1, #7
 *   @0x144b74 mov r7, r0
 *   @0x144b78 mov r0, r4
 *   @0x144b7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b80 mov r1, #8
 *   @0x144b84 mov r6, r0
 *   @0x144b88 mov r0, r4
 *   @0x144b8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144b90 add r1, sp, #124
 *   @0x144b94 add r2, sp, #136
 *   @0x144b98 add r3, sp, #148
 *   @0x144b9c str r7, [sp, #0x94]
 *   @0x144ba0 str r6, [sp, #0x98]
 *   @0x144ba4 str r0, [sp, #0x9c]
 *   @0x144ba8 add r0, sp, #160
 *   @0x144bac bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x144bb0 vldr s14, [sp, #164]
 *   @0x144bb4 vcvt.f64.f32 d7, s14
 *   @0x144bb8 vldr s26, [sp, #168]
 *   @0x144bbc vldr s24, [sp, #172]
 *   @0x144bc0 vldr s22, [sp, #176]
 *   @0x144bc4 vldr s20, [sp, #180]
 *   @0x144bc8 vldr s18, [sp, #184]
 *   @0x144bcc vldr s16, [sp, #188]
 *   @0x144bd0 vldr s0, [sp, #192]
 *   @0x144bd4 vldr s2, [sp, #196]
 *   @0x144bd8 vldr s4, [sp, #200]
 *   @0x144bdc vldr s6, [sp, #204]
 *   @0x144be0 vldr s8, [sp, #208]
 *   @0x144be4 vldr s10, [sp, #212]
 *   @0x144be8 vldr s12, [sp, #216]
 *   @0x144bec vstr d7, [sp]
 *   @0x144bf0 vldr s14, [sp, #220]
 *   @0x144bf4 vcvt.f64.f32 d7, s14
 *   @0x144bf8 vldr s28, [sp, #160]
 *   @0x144bfc mov r0, r5
 *   @0x144c00 mov r1, #16
 *   @0x144c04 vcvt.f64.f32 d0, s0
 *   @0x144c08 vstr d7, [sp, #112]
 *   @0x144c0c vcvt.f64.f32 d1, s2
 *   @0x144c10 vstr d0, [sp, #56]
 *   @0x144c14 vcvt.f64.f32 d2, s4
 *   @0x144c18 vstr d1, [sp, #64]
 *   @0x144c1c vcvt.f64.f32 d3, s6
 *   @0x144c20 vstr d2, [sp, #72]
 *   @0x144c24 vcvt.f64.f32 d4, s8
 *   @0x144c28 vstr d3, [sp, #80]
 *   @0x144c2c vcvt.f64.f32 d5, s10
 *   @0x144c30 vstr d4, [sp, #88]
 *   @0x144c34 vcvt.f64.f32 d6, s12
 *   @0x144c38 vstr d5, [sp, #96]
 *   @0x144c3c vcvt.f64.f32 d7, s28
 *   @0x144c40 vstr d6, [sp, #104]
 *   @0x144c44 vcvt.f64.f32 d13, s26
 *   @0x144c48 vmov r2, r3, d7
 *   @0x144c4c vcvt.f64.f32 d12, s24
 *   @0x144c50 vstr d13, [sp, #8]
 *   @0x144c54 vcvt.f64.f32 d11, s22
 *   @0x144c58 vstr d12, [sp, #16]
 *   @0x144c5c vcvt.f64.f32 d10, s20
 *   @0x144c60 vstr d11, [sp, #24]
 *   @0x144c64 vcvt.f64.f32 d9, s18
 *   @0x144c68 vstr d10, [sp, #32]
 *   @0x144c6c vcvt.f64.f32 d8, s16
 *   @0x144c70 vstr d9, [sp, #40]
 *   @0x144c74 vstr d8, [sp, #48]
 *   @0x144c78 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x144c7c add sp, sp, #228
 *   @0x144c80 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x144c84 pop {r4, r5, r6, r7, pc}
 *
 * ══ §48/70 DeleteShaderManagerResources()  0x18639c  size 424  106 条（0x18639c..0x186544）
 * @func 0x18639c 0x186544  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1863a4→0x532fc0, 0x1863e0→0x479b38, 0x1863fc→0x479b34, 0x186418→0x479b34
 * 调用序列: MemoryManager::Free(void const*)×5 / operator delete[](void*)×5 / DeleteShaderManagerResources()+0x184 / operator delete(void*)
 * 字段偏移 top8: 0x4×4 / 0x14×3 / 0x78×3 / 0x18c×2 / 0x-4×2 / 0x2c×2 / 0x34×2 / 0x38×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18639c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1863a0 ldr r9, [pc, #0x18c]
 *   @0x1863a4 ldr r3, [pc, #0x18c]
 *   @0x1863a8 add r9, pc, r9
 *   @0x1863ac ldr r7, [r9, r3]
 *   @0x1863b0 ldr r3, [r7]
 *   @0x1863b4 ldr r0, [r7, #0x4]
 *   @0x1863b8 cmp r3, #0
 *   @0x1863bc movgt r6, #0
 *   @0x1863c0 movgt r8, r6
 *   @0x1863c4 ble 0x186520 <_Z28DeleteShaderManagerResourcesv+0x184>
 *   @0x1863c8 ldr r4, [r0, r6, lsl #2]
 *   @0x1863cc cmp r4, #0
 *   @0x1863d0 beq 0x186510 <_Z28DeleteShaderManagerResourcesv+0x174>
 *   @0x1863d4 ldr r0, [r4, #0x8]
 *   @0x1863d8 cmn r0, #1
 *   @0x1863dc beq 0x1863f0 <_Z28DeleteShaderManagerResourcesv+0x54>
 *   @0x1863e0 ldr r3, [pc, #0x154]
 *   @0x1863e4 ldr r3, [r9, r3]
 *   @0x1863e8 ldr r3, [r3]
 *   @0x1863ec blx r3
 *   @0x1863f0 ldr r0, [r4]
 *   @0x1863f4 cmn r0, #1
 *   @0x1863f8 beq 0x18640c <_Z28DeleteShaderManagerResourcesv+0x70>
 *   @0x1863fc ldr r3, [pc, #0x13c]
 *   @0x186400 ldr r3, [r9, r3]
 *   @0x186404 ldr r3, [r3]
 *   @0x186408 blx r3
 *   @0x18640c ldr r0, [r4, #0x4]
 *   @0x186410 cmn r0, #1
 *   @0x186414 beq 0x186428 <_Z28DeleteShaderManagerResourcesv+0x8c>
 *   @0x186418 ldr r3, [pc, #0x120]
 *   @0x18641c ldr r3, [r9, r3]
 *   @0x186420 ldr r3, [r3]
 *   @0x186424 blx r3
 *   @0x186428 ldr r0, [r4, #0xc]
 *   @0x18642c cmp r0, #0
 *   @0x186430 beq 0x186438 <_Z28DeleteShaderManagerResourcesv+0x9c>
 *   @0x186434 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x186438 ldr r0, [r4, #0x10]
 *   @0x18643c cmp r0, #0
 *   @0x186440 beq 0x186448 <_Z28DeleteShaderManagerResourcesv+0xac>
 *   @0x186444 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x186448 ldr r0, [r4, #0x14]
 *   @0x18644c cmp r0, #0
 *   @0x186450 beq 0x186488 <_Z28DeleteShaderManagerResourcesv+0xec>
 *   @0x186454 ldr r5, [r0, #-0x4]
 *   @0x186458 add r5, r5, r5, lsl #1
 *   @0x18645c add r5, r0, r5, lsl #2
 *   @0x186460 cmp r0, r5
 *   @0x186464 beq 0x18647c <_Z28DeleteShaderManagerResourcesv+0xe0>
 *   @0x186468 ldr r0, [r5, #-0xc]!
 *   @0x18646c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x186470 ldr r0, [r4, #0x14]
 *   @0x186474 cmp r0, r5
 *   @0x186478 bne 0x186468 <_Z28DeleteShaderManagerResourcesv+0xcc>
 *   @0x18647c sub r0, r0, #8
 *   @0x186480 bl 0x27d1d4 <_ZdaPv>
 *   @0x186484 str r8, [r4, #0x14]
 *   @0x186488 ldr r0, [r4, #0x2c]
 *   @0x18648c cmp r0, #0
 *   @0x186490 beq 0x18649c <_Z28DeleteShaderManagerResourcesv+0x100>
 *   @0x186494 bl 0x27d1d4 <_ZdaPv>
 *   @0x186498 str r8, [r4, #0x2c]
 *   @0x18649c ldr r0, [r4, #0x34]
 *   @0x1864a0 cmp r0, #0
 *   @0x1864a4 beq 0x1864b0 <_Z28DeleteShaderManagerResourcesv+0x114>
 *   @0x1864a8 bl 0x27d1d4 <_ZdaPv>
 *   @0x1864ac str r8, [r4, #0x34]
 *   @0x1864b0 ldr r0, [r4, #0x38]
 *   @0x1864b4 cmp r0, #0
 *   @0x1864b8 beq 0x1864c4 <_Z28DeleteShaderManagerResourcesv+0x128>
 *   @0x1864bc bl 0x27d1d4 <_ZdaPv>
 *   @0x1864c0 str r8, [r4, #0x38]
 *   @0x1864c4 ldr r0, [r4, #0x78]
 *   @0x1864c8 cmp r0, #0
 *   @0x1864cc beq 0x186504 <_Z28DeleteShaderManagerResourcesv+0x168>
 *   @0x1864d0 ldr r5, [r0, #-0x4]
 *   @0x1864d4 rsb r5, r5, r5, lsl #3
 *   @0x1864d8 add r5, r0, r5, lsl #2
 *   @0x1864dc cmp r0, r5
 *   @0x1864e0 beq 0x1864f8 <_Z28DeleteShaderManagerResourcesv+0x15c>
 *   @0x1864e4 ldr r0, [r5, #-0x1c]!
 *   @0x1864e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1864ec ldr r0, [r4, #0x78]
 *   @0x1864f0 cmp r0, r5
 *   @0x1864f4 bne 0x1864e4 <_Z28DeleteShaderManagerResourcesv+0x148>
 *   @0x1864f8 sub r0, r0, #8
 *   @0x1864fc bl 0x27d1d4 <_ZdaPv>
 *   @0x186500 str r8, [r4, #0x78]
 *   @0x186504 mov r0, r4
 *   @0x186508 bl 0x27d1d0 <_ZdlPv>
 *   @0x18650c ldr r0, [r7, #0x4]
 *   @0x186510 ldr r3, [r7]
 *   @0x186514 add r6, r6, #1
 *   @0x186518 cmp r3, r6
 *   @0x18651c bgt 0x1863c8 <_Z28DeleteShaderManagerResourcesv+0x2c>
 *   @0x186520 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x186524 mov r3, #0
 *   @0x186528 str r3, [r7, #0x4]
 *   @0x18652c str r3, [r7]
 *   @0x186530 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x186534 eoreq r11, r6, r8, lsr #17
 *   @0x186538 .word 0xffffe968
 *   @0x18653c .word 0xffffbb78
 *   @0x186540 .word 0xffffbb7c
 *
 * ══ §49/70 CLayerManager::BuildOldTilemapElementRuntimeData(CRoom*, CLayer*, CLayerOldTilemapElement*)  0x1ba514  size 424  106 条（0x1ba514..0x1ba6bc）
 * @func 0x1ba514 0x1ba6bc  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CLayerManager::GetTilesFromPool(int) / CLayerManager::BuildOldTilemapElementRuntimeData(CRoom*, CLayer*, CLayerOldTilemapElement*)+0x14c / operator delete(void*)
 * 字段偏移 top8: 0x704×4 / 0x20×3 / 0xc×3 / 0x8×3 / 0x1c×2 / 0x700×2 / 0x2c×2 / 0x10×2
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ba514 ldr r3, [r2, #0x1c]
 *   @0x1ba518 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ba51c sub sp, sp, #20
 *   @0x1ba520 ldr r9, [r3]
 *   @0x1ba524 mov r8, r2
 *   @0x1ba528 mov r0, sp
 *   @0x1ba52c str r9, [r2, #0x20]
 *   @0x1ba530 mov r1, r9
 *   @0x1ba534 bl 0x1ba3b8 <_ZN13CLayerManager16GetTilesFromPoolEi>
 *   @0x1ba538 ldm sp, {r0, r1, r2, r3}
 *   @0x1ba53c add r12, r8, #36
 *   @0x1ba540 ldr r4, [sp, #0xc]
 *   @0x1ba544 cmp r4, #0
 *   @0x1ba548 stm r12, {r0, r1, r2, r3}
 *   @0x1ba54c beq 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c>
 *   @0x1ba550 ldr r0, [sp]
 *   @0x1ba554 cmp r0, #0
 *   @0x1ba558 beq 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c>
 *   @0x1ba55c cmp r4, #2
 *   @0x1ba560 beq 0x1ba670 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x15c>
 *   @0x1ba564 cmp r4, #3
 *   @0x1ba568 beq 0x1ba688 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x174>
 *   @0x1ba56c cmp r4, #1
 *   @0x1ba570 beq 0x1ba6a0 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x18c>
 *   @0x1ba574 ldr r0, [r0, #0x704]
 *   @0x1ba578 cmp r0, #0
 *   @0x1ba57c bne 0x1ba574 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x60>
 *   @0x1ba580 cmp r9, #0
 *   @0x1ba584 ble 0x1ba660 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x14c>
 *   @0x1ba588 ldr r12, [r8, #0x24]
 *   @0x1ba58c ldr r6, [r8, #0x1c]
 *   @0x1ba590 cmp r12, #0
 *   @0x1ba594 beq 0x1ba660 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x14c>
 *   @0x1ba598 mov r4, #0
 *   @0x1ba59c mov r11, #1
 *   @0x1ba5a0 mov r5, r4
 *   @0x1ba5a4 vldr s11, [pc, #268]
 *   @0x1ba5a8 ldr r2, [r6, #0x4]!
 *   @0x1ba5ac vldr s10, [r2]
 *   @0x1ba5b0 vcvt.f32.s32 s14, s10
 *   @0x1ba5b4 rsb r5, r5, r5, lsl #3
 *   @0x1ba5b8 ldr r1, [r12, #0x700]
 *   @0x1ba5bc vldr s13, [r2, #4]
 *   @0x1ba5c0 ldr r0, [r2, #0x2c]
 *   @0x1ba5c4 add r3, r12, r5, lsl #3
 *   @0x1ba5c8 vldr s12, [r2, #36]
 *   @0x1ba5cc ldr r10, [r2, #0xc]
 *   @0x1ba5d0 add r4, r4, #1
 *   @0x1ba5d4 add r1, r1, #1
 *   @0x1ba5d8 lsr r7, r0, #24
 *   @0x1ba5dc ands r5, r4, #31
 *   @0x1ba5e0 bic r0, r0, #-16777216
 *   @0x1ba5e4 vmov s15, r7
 *   @0x1ba5e8 ldr r7, [r2, #0x8]
 *   @0x1ba5ec vstr s14, [r3]
 *   @0x1ba5f0 vldr s14, [r2, #28]
 *   @0x1ba5f4 vcvt.f32.s32 s15, s15
 *   @0x1ba5f8 str r7, [r3, #0x8]
 *   @0x1ba5fc ldr r7, [r2, #0x10]
 *   @0x1ba600 str r7, [r3, #0x10]
 *   @0x1ba604 ldr r7, [r2, #0x14]
 *   @0x1ba608 vdiv.f32 s15, s15, s11
 *   @0x1ba60c str r10, [r3, #0xc]
 *   @0x1ba610 ldr r10, [r2, #0x18]
 *   @0x1ba614 str r7, [r3, #0x14]
 *   @0x1ba618 ldr r7, [r2, #0x20]
 *   @0x1ba61c ldr r2, [r2, #0x28]
 *   @0x1ba620 vstr s12, [r3, #36]
 *   @0x1ba624 str r10, [r3, #0x18]
 *   @0x1ba628 str r7, [r3, #0x20]
 *   @0x1ba62c str r2, [r3, #0x28]
 *   @0x1ba630 strb r11, [r3, #0x34]
 *   @0x1ba634 str r0, [r3, #0x2c]
 *   @0x1ba638 vcvt.f32.s32 s13, s13
 *   @0x1ba63c vstr s15, [r3, #48]
 *   @0x1ba640 vcvt.f32.s32 s14, s14
 *   @0x1ba644 vstr s13, [r3, #4]
 *   @0x1ba648 vstr s14, [r3, #28]
 *   @0x1ba64c str r1, [r12, #0x700]
 *   @0x1ba650 ldreq r12, [r12, #0x704]
 *   @0x1ba654 cmp r12, #0
 *   @0x1ba658 cmpne r9, r4
 *   @0x1ba65c bgt 0x1ba5a8 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x94>
 *   @0x1ba660 mov r3, #1
 *   @0x1ba664 strb r3, [r8, #0x8]
 *   @0x1ba668 add sp, sp, #20
 *   @0x1ba66c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ba670 ldr r4, [r0, #0x704]
 *   @0x1ba674 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1ba678 cmp r4, #0
 *   @0x1ba67c mov r0, r4
 *   @0x1ba680 bne 0x1ba670 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x15c>
 *   @0x1ba684 b 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c>
 *   @0x1ba688 ldr r4, [r0, #0x704]
 *   @0x1ba68c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1ba690 cmp r4, #0
 *   @0x1ba694 mov r0, r4
 *   @0x1ba698 bne 0x1ba688 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x174>
 *   @0x1ba69c b 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c>
 *   @0x1ba6a0 ldr r4, [r0, #0x704]
 *   @0x1ba6a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1ba6a8 cmp r4, #0
 *   @0x1ba6ac mov r0, r4
 *   @0x1ba6b0 bne 0x1ba6a0 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x18c>
 *   @0x1ba6b4 b 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c>
 *   @0x1ba6b8 cmnmi pc, #0
 *
 * ══ §50/70 F_LayerRemoveInstance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c1398  size 424  106 条（0x1c1398..0x1c1540）
 * @func 0x1c1398 0x1c1540  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / F_LayerRemoveInstance(RValue&, CInstance*, CInstance*, int, RValue*)+0x170 / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x174×2 / 0x90×2 / 0x3c×2 / 0x18×1 / 0x150×1 / 0xf0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c1398 push {r3, r4, r5, r6, r7, lr}
 *   @0x1c139c cmp r3, #2
 *   @0x1c13a0 ldr r5, [pc, #0x174]
 *   @0x1c13a4 mov r3, #0
 *   @0x1c13a8 mov r4, r3
 *   @0x1c13ac ldr r6, [sp, #0x18]
 *   @0x1c13b0 movt r3, #0xbff0
 *   @0x1c13b4 add r5, pc, r5
 *   @0x1c13b8 str r4, [r0, #0xc]
 *   @0x1c13bc str r3, [r0, #0x4]
 *   @0x1c13c0 str r4, [r0]
 *   @0x1c13c4 beq 0x1c13dc <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1c13c8 ldr r0, [pc, #0x150]
 *   @0x1c13cc mov r1, r4
 *   @0x1c13d0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c13d4 add r0, pc, r0
 *   @0x1c13d8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c13dc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c13e0 ldr r3, [r6, #0xc]
 *   @0x1c13e4 mov r1, r4
 *   @0x1c13e8 bic r3, r3, #-16777216
 *   @0x1c13ec cmp r3, #1
 *   @0x1c13f0 mov r7, r0
 *   @0x1c13f4 mov r0, r6
 *   @0x1c13f8 beq 0x1c14b4 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1c13fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c1400 mov r1, r0
 *   @0x1c1404 mov r0, r7
 *   @0x1c1408 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c140c mov r4, r0
 *   @0x1c1410 cmp r4, #0
 *   @0x1c1414 beq 0x1c14f4 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x1c1418 mov r0, r6
 *   @0x1c141c mov r1, #1
 *   @0x1c1420 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c1424 cmp r0, #0
 *   @0x1c1428 blt 0x1c1508 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x1c142c ldr r3, [pc, #0xf0]
 *   @0x1c1430 ldr r3, [r5, r3]
 *   @0x1c1434 ldr r2, [r3, #0x4]
 *   @0x1c1438 ldr r3, [r3]
 *   @0x1c143c and r2, r0, r2
 *   @0x1c1440 ldr r3, [r3, r2, lsl #3]
 *   @0x1c1444 cmp r3, #0
 *   @0x1c1448 bne 0x1c145c <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x1c144c b 0x1c1508 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x1c1450 ldr r3, [r3, #0x4]
 *   @0x1c1454 cmp r3, #0
 *   @0x1c1458 beq 0x1c1508 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x1c145c ldr r2, [r3, #0x8]
 *   @0x1c1460 cmp r0, r2
 *   @0x1c1464 bne 0x1c1450 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1c1468 ldr r2, [r3, #0xc]
 *   @0x1c146c cmp r2, #0
 *   @0x1c1470 beq 0x1c1508 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x1c1474 ldrb r3, [r2, #0x174]
 *   @0x1c1478 cmp r3, #0
 *   @0x1c147c beq 0x1c14e4 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x1c1480 ldr r1, [r2, #0x170]
 *   @0x1c1484 ldr r3, [r4]
 *   @0x1c1488 cmp r1, r3
 *   @0x1c148c beq 0x1c14cc <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1c1490 ldr r1, [pc, #0x90]
 *   @0x1c1494 ldr r3, [pc, #0x90]
 *   @0x1c1498 add r1, pc, r1
 *   @0x1c149c ldr r3, [r5, r3]
 *   @0x1c14a0 ldr r0, [r3]
 *   @0x1c14a4 ldr r3, [r0]
 *   @0x1c14a8 ldr r3, [r3, #0xc]
 *   @0x1c14ac blx r3
 *   @0x1c14b0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c14b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c14b8 mov r1, r0
 *   @0x1c14bc mov r0, r7
 *   @0x1c14c0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c14c4 mov r4, r0
 *   @0x1c14c8 b 0x1c1410 <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1c14cc ldr r3, [pc, #0x5c]
 *   @0x1c14d0 mov r1, r4
 *   @0x1c14d4 ldr r3, [r5, r3]
 *   @0x1c14d8 ldr r0, [r3]
 *   @0x1c14dc pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c14e0 b 0x1b991c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance>
 *   @0x1c14e4 ldr r1, [pc, #0x48]
 *   @0x1c14e8 ldr r3, [pc, #0x3c]
 *   @0x1c14ec add r1, pc, r1
 *   @0x1c14f0 b 0x1c149c <_Z21F_LayerRemoveInstanceR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x1c14f4 ldr r0, [pc, #0x3c]
 *   @0x1c14f8 mov r1, r4
 *   @0x1c14fc pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c1500 add r0, pc, r0
 *   @0x1c1504 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c1508 ldr r0, [pc, #0x2c]
 *   @0x1c150c mov r1, #0
 *   @0x1c1510 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c1514 add r0, pc, r0
 *   @0x1c1518 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c151c mlaeq r3, r12, r8, r0
 *   @0x1c1520 mulseq r8, r4, r6
 *   @0x1c1524 .word 0xffffbff4
 *   @0x1c1528 andseq lr, r8, r4, asr #13
 *   @0x1c152c .word 0xffffbac4
 *   @0x1c1530 .word 0xffffbcd8
 *   @0x1c1534 andseq lr, r8, r8, lsr r6
 *   @0x1c1538 mulseq r8, r12, r5
 *   @0x1c153c ldrsbeq lr, [r8], -r4
 *
 * ══ §51/70 JS_Date_UTC(RValue&, CInstance*, CInstance*, int, RValue*)  0x245ed8  size 424  103 条（0x245ed8..0x246080）
 * @func 0x245ed8 0x246080  size 424  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×7 / JS_Date_UTC(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0 / JS_Date_UTC(RValue&, CInstance*, CInstance*, int, RValue*)+0x130 / MakeDay(double, double, double) / MakeTime(double, double, double, double) / MakeDate(double, double) / TimeClip(double)
 * 字段偏移 top8: 0x58×1 / 0xc×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245ed8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x245edc vpush {d8}
 *   @0x245ee0 subs r8, r3, #0
 *   @0x245ee4 sub sp, sp, #48
 *   @0x245ee8 mov r10, r0
 *   @0x245eec ldr r9, [sp, #0x58]
 *   @0x245ef0 ble 0x245fa8 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x245ef4 mov r0, r9
 *   @0x245ef8 mov r1, #0
 *   @0x245efc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x245f00 cmp r8, #1
 *   @0x245f04 vmov d8, r0, r1
 *   @0x245f08 beq 0x245fac <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x245f0c mov r0, r9
 *   @0x245f10 mov r1, #1
 *   @0x245f14 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x245f18 cmp r8, #2
 *   @0x245f1c strd r0, r1, [sp, #40]
 *   @0x245f20 beq 0x245fb4 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x245f24 mov r0, r9
 *   @0x245f28 mov r1, #2
 *   @0x245f2c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x245f30 cmp r8, #3
 *   @0x245f34 strd r0, r1, [sp, #16]
 *   @0x245f38 beq 0x245fbc <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x245f3c mov r0, r9
 *   @0x245f40 mov r1, #3
 *   @0x245f44 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x245f48 cmp r8, #4
 *   @0x245f4c strd r0, r1, [sp, #24]
 *   @0x245f50 beq 0x245fc4 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x245f54 mov r0, r9
 *   @0x245f58 mov r1, #4
 *   @0x245f5c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x245f60 cmp r8, #5
 *   @0x245f64 strd r0, r1, [sp, #32]
 *   @0x245f68 beq 0x245fcc <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x245f6c mov r0, r9
 *   @0x245f70 mov r1, #5
 *   @0x245f74 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x245f78 cmp r8, #6
 *   @0x245f7c moveq r6, #0
 *   @0x245f80 moveq r7, #0
 *   @0x245f84 mov r4, r0
 *   @0x245f88 mov r5, r1
 *   @0x245f8c beq 0x245fdc <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x245f90 mov r0, r9
 *   @0x245f94 mov r1, #6
 *   @0x245f98 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x245f9c mov r6, r0
 *   @0x245fa0 mov r7, r1
 *   @0x245fa4 b 0x245fdc <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x245fa8 vldr d8, [pc, #184]
 *   @0x245fac vldr d7, [pc, #180]
 *   @0x245fb0 vstr d7, [sp, #40]
 *   @0x245fb4 vmov.f64 d7, #1.000000e+00
 *   @0x245fb8 vstr d7, [sp, #16]
 *   @0x245fbc vldr d7, [pc, #164]
 *   @0x245fc0 vstr d7, [sp, #24]
 *   @0x245fc4 vldr d7, [pc, #156]
 *   @0x245fc8 vstr d7, [sp, #32]
 *   @0x245fcc mov r4, #0
 *   @0x245fd0 mov r5, #0
 *   @0x245fd4 mov r6, r4
 *   @0x245fd8 mov r7, r5
 *   @0x245fdc vcmp.f64 d8, d8
 *   @0x245fe0 vmrs APSR_nzcv, fpscr
 *   @0x245fe4 bvs 0x246008 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x245fe8 vcmpe.f64 d8, #0
 *   @0x245fec vmrs APSR_nzcv, fpscr
 *   @0x245ff0 blt 0x246008 <_Z11JS_Date_UTCR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x245ff4 vldr d7, [pc, #116]
 *   @0x245ff8 vcmpe.f64 d8, d7
 *   @0x245ffc vmrs APSR_nzcv, fpscr
 *   @0x246000 vldrls d7, [pc, #112]
 *   @0x246004 vaddls.f64 d8, d8, d7
 *   @0x246008 vldr d7, [sp, #16]
 *   @0x24600c ldrd r2, r3, [sp, #40]
 *   @0x246010 vstr d7, [sp]
 *   @0x246014 vmov r0, r1, d8
 *   @0x246018 bl 0x245370 <_Z7MakeDayddd>
 *   @0x24601c ldrd r2, r3, [sp, #32]
 *   @0x246020 strd r4, r5, [sp]
 *   @0x246024 strd r6, r7, [sp, #8]
 *   @0x246028 mov r8, r0
 *   @0x24602c mov r9, r1
 *   @0x246030 ldrd r0, r1, [sp, #24]
 *   @0x246034 bl 0x2451d8 <_Z8MakeTimedddd>
 *   @0x246038 mov r2, r0
 *   @0x24603c mov r3, r1
 *   @0x246040 mov r0, r8
 *   @0x246044 mov r1, r9
 *   @0x246048 bl 0x245480 <_Z8MakeDatedd>
 *   @0x24604c bl 0x245e78 <_Z8TimeClipd>
 *   @0x246050 mov r3, #0
 *   @0x246054 str r3, [r10, #0xc]
 *   @0x246058 stm r10, {r0, r1}
 *   @0x24605c add sp, sp, #48
 *   @0x246060 vpop {d8}
 *   @0x246064 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x246074 subsmi r12, r8, r0
 *   @0x246078 andeq r0, r0, r0
 *   @0x24607c addsmi r11, sp, r0
 *
 * ══ §52/70 JS_Array_prototype_every(RValue&, CInstance*, CInstance*, int, RValue*)  0x2513e4  size 424  106 条（0x2513e4..0x25158c）
 * @func 0x2513e4 0x25159c  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×3 / JSThrowTypeError(char const*)×2 / JS_Array_prototype_every(RValue&, CInstance*, CInstance*, int, RValue*)+0x54 / JS_IsCallable(RValue&) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*) / JS_ToBoolean(RValue&)
 * 字段偏移 top8: 0x4×4 / 0xc×4 / 0x78×2 / 0x24×1 / 0x144×1 / 0x3c×1 / 0x4c×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2513e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2513e8 mov r2, #0
 *   @0x2513ec str r2, [r0]
 *   @0x2513f0 sub sp, sp, #84
 *   @0x2513f4 str r2, [r0, #0x4]
 *   @0x2513f8 mov r4, r3
 *   @0x2513fc ldr r2, [r1, #0x4]
 *   @0x251400 mov r3, #13
 *   @0x251404 str r0, [sp, #0xc]
 *   @0x251408 cmp r2, #0
 *   @0x25140c str r3, [r0, #0xc]
 *   @0x251410 beq 0x251574 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x251414 add r0, r2, #16
 *   @0x251418 ldr r6, [r0]
 *   @0x25141c cmp r4, #0
 *   @0x251420 ldr r8, [r6, #0x24]
 *   @0x251424 ble 0x251438 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x251428 ldr r0, [sp, #0x78]
 *   @0x25142c bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x251430 cmp r0, #0
 *   @0x251434 bne 0x25144c <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x251438 ldr r0, [pc, #0x144]
 *   @0x25143c add r0, pc, r0
 *   @0x251440 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x251444 add sp, sp, #84
 *   @0x251448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25144c cmp r4, #1
 *   @0x251450 moveq r12, #0
 *   @0x251454 streq r12, [sp, #0x8]
 *   @0x251458 ldrne r12, [sp, #0x78]
 *   @0x25145c ldrne r12, [r12, #0x10]
 *   @0x251460 strne r12, [sp, #0x8]
 *   @0x251464 cmp r8, #0
 *   @0x251468 beq 0x251544 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x25146c mov r10, #0
 *   @0x251470 add r5, sp, #32
 *   @0x251474 add r7, sp, #16
 *   @0x251478 mov r4, r10
 *   @0x25147c mov r11, r10
 *   @0x251480 mvn r9, #-16777216
 *   @0x251484 b 0x251518 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x251488 add r0, r0, r10
 *   @0x25148c ldr r3, [r0, #0xc]
 *   @0x251490 bic r3, r3, #-16777216
 *   @0x251494 cmp r3, r9
 *   @0x251498 beq 0x251508 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x25149c ldr r0, [r6, #0x4]
 *   @0x2514a0 cmp r0, #0
 *   @0x2514a4 beq 0x251534 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x2514a8 add r0, r0, r10
 *   @0x2514ac vmov s13, r4
 *   @0x2514b0 mov r12, #6
 *   @0x2514b4 ldm r0, {r0, r1, r2, r3}
 *   @0x2514b8 vcvt.f64.u32 d7, s13
 *   @0x2514bc str r5, [sp]
 *   @0x2514c0 str r11, [sp, #0x3c]
 *   @0x2514c4 str r12, [sp, #0x4c]
 *   @0x2514c8 stm r5, {r0, r1, r2, r3}
 *   @0x2514cc mov r1, r7
 *   @0x2514d0 ldr r0, [sp, #0x8]
 *   @0x2514d4 mov r3, #3
 *   @0x2514d8 ldr r2, [sp, #0x78]
 *   @0x2514dc vstr d7, [sp, #48]
 *   @0x2514e0 str r6, [sp, #0x40]
 *   @0x2514e4 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x2514e8 cmp r0, #2
 *   @0x2514ec beq 0x251444 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x2514f0 cmp r0, #1
 *   @0x2514f4 beq 0x251560 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x2514f8 mov r0, r7
 *   @0x2514fc bl 0x2404bc <_Z12JS_ToBooleanR6RValue>
 *   @0x251500 cmp r0, #0
 *   @0x251504 beq 0x251444 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x251508 add r4, r4, #1
 *   @0x25150c add r10, r10, #16
 *   @0x251510 cmp r4, r8
 *   @0x251514 beq 0x251544 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x251518 ldr r0, [r6, #0x4]
 *   @0x25151c cmp r0, #0
 *   @0x251520 bne 0x251488 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x251524 mov r0, r6
 *   @0x251528 mov r1, r4
 *   @0x25152c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251530 b 0x25148c <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x251534 mov r0, r6
 *   @0x251538 mov r1, r4
 *   @0x25153c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251540 b 0x2514ac <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x251544 ldr r12, [sp, #0xc]
 *   @0x251548 mov r3, #0
 *   @0x25154c mov r2, r3
 *   @0x251550 movt r3, #0x3ff0
 *   @0x251554 stm r12, {r2, r3}
 *   @0x251558 add sp, sp, #84
 *   @0x25155c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251560 ldr r0, [pc, #0x20]
 *   @0x251564 add r0, pc, r0
 *   @0x251568 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25156c add sp, sp, #84
 *   @0x251570 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251574 mov r0, r1
 *   @0x251578 mov r1, #1
 *   @0x25157c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251580 b 0x251418 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x251584 ldrsbeq r4, [r0], -r8
 *   @0x251588 andseq r4, r0, r0, ror r12
 *
 * ══ §53/70 AllocBufferVertex(int)  0xc8978  size 420  105 条（0xc8978..0xc8b1c）
 * @func 0xc8978 0xc8b1c  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / AllocBufferVertex(int)+0x174 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×2 / 0x10×2 / 0x14×2 / 0x20×2 / 0x30×2 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8978 ldr r3, [pc, #0x180]
 *   @0xc897c push {r4, r5, r6, r7, r8, lr}
 *   @0xc8980 add r3, pc, r3
 *   @0xc8984 mov r7, r0
 *   @0xc8988 sub sp, sp, #8
 *   @0xc898c ldm r3, {r0, r5}
 *   @0xc8990 cmp r5, #0
 *   @0xc8994 ble 0xc8aec <_Z17AllocBufferVertexi+0x174>
 *   @0xc8998 ldr r6, [r0]
 *   @0xc899c cmp r6, #0
 *   @0xc89a0 movne r3, r0
 *   @0xc89a4 movne r4, #0
 *   @0xc89a8 bne 0xc89bc <_Z17AllocBufferVertexi+0x44>
 *   @0xc89ac b 0xc8a70 <_Z17AllocBufferVertexi+0xf8>
 *   @0xc89b0 ldr r2, [r3, #0x4]!
 *   @0xc89b4 cmp r2, #0
 *   @0xc89b8 beq 0xc8a74 <_Z17AllocBufferVertexi+0xfc>
 *   @0xc89bc add r4, r4, #1
 *   @0xc89c0 cmp r4, r5
 *   @0xc89c4 lsl r6, r4, #2
 *   @0xc89c8 bne 0xc89b0 <_Z17AllocBufferVertexi+0x38>
 *   @0xc89cc ldr r3, [pc, #0x130]
 *   @0xc89d0 lsl r1, r5, #3
 *   @0xc89d4 lsl r2, r5, #1
 *   @0xc89d8 add r3, pc, r3
 *   @0xc89dc str r2, [r3, #0x4]
 *   @0xc89e0 ldr r2, [pc, #0x120]
 *   @0xc89e4 mov r8, #0
 *   @0xc89e8 mov r3, #74
 *   @0xc89ec str r8, [sp]
 *   @0xc89f0 add r2, pc, r2
 *   @0xc89f4 ldr r4, [pc, #0x110]
 *   @0xc89f8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc89fc add r4, pc, r4
 *   @0xc8a00 str r0, [r4]
 *   @0xc8a04 mov r0, #52
 *   @0xc8a08 bl 0x27c524 <_Znwj>
 *   @0xc8a0c ldr r1, [pc, #0xfc]
 *   @0xc8a10 mov r2, #66
 *   @0xc8a14 mov r3, #1
 *   @0xc8a18 add r1, pc, r1
 *   @0xc8a1c mov r6, r0
 *   @0xc8a20 mov r0, r7
 *   @0xc8a24 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xc8a28 ldr r2, [r4]
 *   @0xc8a2c mov r4, r5
 *   @0xc8a30 mvn r3, #0
 *   @0xc8a34 stmib r6, {r7, r8}
 *   @0xc8a38 str r8, [r6, #0xc]
 *   @0xc8a3c str r8, [r6, #0x18]
 *   @0xc8a40 str r8, [r6, #0x10]
 *   @0xc8a44 str r8, [r6, #0x14]
 *   @0xc8a48 strb r8, [r6, #0x20]
 *   @0xc8a4c str r8, [r6, #0x30]
 *   @0xc8a50 str r8, [r6, #0x2c]
 *   @0xc8a54 str r3, [r6, #0x24]
 *   @0xc8a58 str r3, [r6, #0x28]
 *   @0xc8a5c str r0, [r6]
 *   @0xc8a60 mov r0, r4
 *   @0xc8a64 str r6, [r2, r5, lsl #2]
 *   @0xc8a68 add sp, sp, #8
 *   @0xc8a6c pop {r4, r5, r6, r7, r8, pc}
 *   @0xc8a70 mov r4, r6
 *   @0xc8a74 mov r0, #52
 *   @0xc8a78 bl 0x27c524 <_Znwj>
 *   @0xc8a7c ldr r1, [pc, #0x90]
 *   @0xc8a80 mov r2, #66
 *   @0xc8a84 mov r3, #1
 *   @0xc8a88 add r1, pc, r1
 *   @0xc8a8c mov r5, r0
 *   @0xc8a90 mov r0, r7
 *   @0xc8a94 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xc8a98 ldr r1, [pc, #0x78]
 *   @0xc8a9c mov r3, #0
 *   @0xc8aa0 mvn r2, #0
 *   @0xc8aa4 add r1, pc, r1
 *   @0xc8aa8 str r7, [r5, #0x4]
 *   @0xc8aac str r3, [r5, #0x8]
 *   @0xc8ab0 ldr r1, [r1]
 *   @0xc8ab4 str r3, [r5, #0xc]
 *   @0xc8ab8 str r3, [r5, #0x18]
 *   @0xc8abc str r3, [r5, #0x10]
 *   @0xc8ac0 str r3, [r5, #0x14]
 *   @0xc8ac4 strb r3, [r5, #0x20]
 *   @0xc8ac8 str r3, [r5, #0x30]
 *   @0xc8acc str r3, [r5, #0x2c]
 *   @0xc8ad0 str r2, [r5, #0x24]
 *   @0xc8ad4 str r2, [r5, #0x28]
 *   @0xc8ad8 str r0, [r5]
 *   @0xc8adc mov r0, r4
 *   @0xc8ae0 str r5, [r1, r6]
 *   @0xc8ae4 add sp, sp, #8
 *   @0xc8ae8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc8aec moveq r2, #32
 *   @0xc8af0 moveq r1, #128
 *   @0xc8af4 streq r2, [r3, #0x4]
 *   @0xc8af8 beq 0xc89e0 <_Z17AllocBufferVertexi+0x68>
 *   @0xc8afc b 0xc89cc <_Z17AllocBufferVertexi+0x54>
 *   @0xc8b00 ldrhteq r1, [r11], -r4
 *   @0xc8b04 eorseq r1, r11, r12, asr r7
 *   @0xc8b08 eoreq r8, r6, r0, asr #12
 *   @0xc8b0c eorseq r1, r11, r8, lsr r7
 *   @0xc8b10 eoreq r8, r6, r4, asr #31
 *   @0xc8b14 eoreq r8, r6, r4, asr pc
 *   @0xc8b18 mlaseq r11, r0, r6, r1
 *
 * ══ §54/70 F_Vertex_Create_Buffer_From_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8d3c  size 420  105 条（0xc8d3c..0xc8ee0）
 * @func 0xc8d3c 0xc8ee0  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / GetIBuffer(int) / GetVertexFormat(int) / AllocBufferVertex(int) / GetBufferVertex(int) / IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool) / IsBigEndian() / VertexFormat::EndianSwapBuffer(unsigned char*, int, int, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x10×4 / 0x18×3 / 0x14×2 / 0x1c×2 / 0x4×2 / 0x8×2 / 0x48×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8d3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc8d40 cmp r3, #4
 *   @0xc8d44 sub sp, sp, #36
 *   @0xc8d48 mov r3, #0
 *   @0xc8d4c mov r1, r3
 *   @0xc8d50 mov r4, r0
 *   @0xc8d54 movt r3, #0xbff0
 *   @0xc8d58 str r1, [r0, #0xc]
 *   @0xc8d5c stm r0, {r1, r3}
 *   @0xc8d60 ldr r5, [sp, #0x48]
 *   @0xc8d64 beq 0xc8d80 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xc8d68 ldr r0, [pc, #0x160]
 *   @0xc8d6c add r0, pc, r0
 *   @0xc8d70 mov r1, #1
 *   @0xc8d74 add sp, sp, #36
 *   @0xc8d78 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc8d7c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8d80 mov r0, r5
 *   @0xc8d84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8d88 bl 0xc6720 <_Z10GetIBufferi>
 *   @0xc8d8c subs r9, r0, #0
 *   @0xc8d90 beq 0xc8eb8 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0xc8d94 mov r1, #1
 *   @0xc8d98 mov r0, r5
 *   @0xc8d9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8da0 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc8da4 subs r11, r0, #0
 *   @0xc8da8 beq 0xc8ec4 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0xc8dac mov r0, r5
 *   @0xc8db0 mov r1, #2
 *   @0xc8db4 ldr r7, [r11, #0x14]
 *   @0xc8db8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8dbc mov r1, #3
 *   @0xc8dc0 mov r10, r0
 *   @0xc8dc4 mov r0, r5
 *   @0xc8dc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8dcc mul r7, r7, r0
 *   @0xc8dd0 mov r8, r0
 *   @0xc8dd4 mov r0, r7
 *   @0xc8dd8 bl 0xc8978 <_Z17AllocBufferVertexi>
 *   @0xc8ddc str r0, [sp, #0x1c]
 *   @0xc8de0 bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc8de4 subs r5, r0, #0
 *   @0xc8de8 beq 0xc8df8 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0xc8dec ldrb r6, [r5, #0x20]
 *   @0xc8df0 cmp r6, #0
 *   @0xc8df4 beq 0xc8e10 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0xc8df8 ldr r0, [pc, #0xd4]
 *   @0xc8dfc mov r1, #1
 *   @0xc8e00 add r0, pc, r0
 *   @0xc8e04 add sp, sp, #36
 *   @0xc8e08 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc8e0c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8e10 ldr r2, [r9, #0xc]
 *   @0xc8e14 mov r1, r7
 *   @0xc8e18 ldr r3, [r9, #0x10]
 *   @0xc8e1c ldr r0, [r5]
 *   @0xc8e20 str r10, [sp]
 *   @0xc8e24 str r7, [sp, #0x4]
 *   @0xc8e28 str r6, [sp, #0x8]
 *   @0xc8e2c str r6, [sp, #0xc]
 *   @0xc8e30 ldr lr, [r9, #0x18]
 *   @0xc8e34 subs r12, lr, #2
 *   @0xc8e38 rsbs lr, r12, #0
 *   @0xc8e3c adcs lr, lr, r12
 *   @0xc8e40 str lr, [sp, #0x10]
 *   @0xc8e44 bl 0xccd94 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb>
 *   @0xc8e48 vldr s15, [sp, #28]
 *   @0xc8e4c vcvt.f64.s32 d7, s15
 *   @0xc8e50 ldm r11, {r0, r1}
 *   @0xc8e54 str r6, [r5, #0x18]
 *   @0xc8e58 str r6, [r5, #0x8]
 *   @0xc8e5c str r1, [r5, #0x14]
 *   @0xc8e60 mvn r1, #0
 *   @0xc8e64 str r0, [r5, #0x28]
 *   @0xc8e68 str r7, [r5, #0xc]
 *   @0xc8e6c str r8, [r5, #0x1c]
 *   @0xc8e70 vmov r2, r3, d7
 *   @0xc8e74 str r6, [r5, #0x10]
 *   @0xc8e78 str r6, [r5, #0x2c]
 *   @0xc8e7c str r1, [r5, #0x24]
 *   @0xc8e80 stm r4, {r2, r3}
 *   @0xc8e84 bl 0x212e98 <_Z11IsBigEndianv>
 *   @0xc8e88 cmp r0, #0
 *   @0xc8e8c beq 0xc8eb0 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0xc8e90 ldr r1, [r5]
 *   @0xc8e94 mvn r3, #0
 *   @0xc8e98 mov r0, r11
 *   @0xc8e9c str r3, [sp]
 *   @0xc8ea0 mov r2, r8
 *   @0xc8ea4 str r6, [sp, #0x4]
 *   @0xc8ea8 mov r3, r6
 *   @0xc8eac bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib>
 *   @0xc8eb0 add sp, sp, #36
 *   @0xc8eb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc8eb8 ldr r0, [pc, #0x18]
 *   @0xc8ebc add r0, pc, r0
 *   @0xc8ec0 b 0xc8d70 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0xc8ec4 ldr r0, [pc, #0x10]
 *   @0xc8ec8 add r0, pc, r0
 *   @0xc8ecc b 0xc8d70 <_Z38F_Vertex_Create_Buffer_From_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0xc8ed0 eoreq r8, r6, r4, ror #27
 *   @0xc8ed4 eoreq r8, r6, r4, lsr #28
 *   @0xc8ed8 .word 0x00268cd4
 *   @0xc8edc eoreq r8, r6, r0, lsl sp
 *
 * ══ §55/70 IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool)  0xccd94  size 420  105 条（0xccd94..0xccf38）
 * @func 0xccd94 0xccf38  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool)+0x19c×3 / 0xb65bc×2 / __aeabi_idivmod×2 / IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool)+0x68 / IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool)+0x94 / IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool)+0xb4 / IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool)+0x114 / IBuffer::CopyMemoryToMemory(unsigned char*, int, unsigned char*, int, int, int, int, bool, bool)+0x140
 * 字段偏移 top8: 0x28×1 / 0x2c×1 / 0x30×1 / 0x34×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xccd94 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xccd98 subs r10, r0, #0
 *   @0xccd9c mov r9, r2
 *   @0xccda0 mov r5, r3
 *   @0xccda4 mov r6, r1
 *   @0xccda8 ldr r12, [sp, #0x28]
 *   @0xccdac ldr r7, [sp, #0x2c]
 *   @0xccdb0 ldr r4, [sp, #0x30]
 *   @0xccdb4 ldrb r2, [sp, #0x34]
 *   @0xccdb8 ldrb r3, [sp, #0x38]
 *   @0xccdbc beq 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c>
 *   @0xccdc0 cmp r1, #0
 *   @0xccdc4 ble 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c>
 *   @0xccdc8 cmp r9, #0
 *   @0xccdcc beq 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c>
 *   @0xccdd0 cmp r5, #0
 *   @0xccdd4 ble 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c>
 *   @0xccdd8 cmp r7, #0
 *   @0xccddc movlt r7, r5
 *   @0xccde0 cmp r3, #0
 *   @0xccde4 bne 0xcceb0 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x11c>
 *   @0xccde8 cmp r12, #0
 *   @0xccdec movlt r12, r3
 *   @0xccdf0 blt 0xccdfc <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x68>
 *   @0xccdf4 cmp r5, r12
 *   @0xccdf8 suble r12, r5, #1
 *   @0xccdfc add r1, r12, r7
 *   @0xcce00 cmp r5, r1
 *   @0xcce04 rsblt r7, r12, r5
 *   @0xcce08 cmp r2, #0
 *   @0xcce0c beq 0xcceec <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x158>
 *   @0xcce10 cmp r4, #0
 *   @0xcce14 bge 0xcce2c <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x98>
 *   @0xcce18 adds r4, r4, r6
 *   @0xcce1c bmi 0xcce18 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x84>
 *   @0xcce20 cmp r6, r4
 *   @0xcce24 bgt 0xcce34 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0xa0>
 *   @0xcce28 rsb r4, r6, r4
 *   @0xcce2c cmp r6, r4
 *   @0xcce30 ble 0xcce28 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x94>
 *   @0xcce34 add r2, r7, r4
 *   @0xcce38 cmp r6, r2
 *   @0xcce3c blt 0xcce48 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0xb4>
 *   @0xcce40 cmp r3, #0
 *   @0xcce44 beq 0xccf10 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x17c>
 *   @0xcce48 cmp r7, #0
 *   @0xcce4c ble 0xccea8 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x114>
 *   @0xcce50 rsb r3, r12, r5
 *   @0xcce54 rsb r8, r4, r6
 *   @0xcce58 cmp r8, r3
 *   @0xcce5c movge r8, r3
 *   @0xcce60 add r1, r9, r12
 *   @0xcce64 cmp r8, r7
 *   @0xcce68 movge r8, r7
 *   @0xcce6c add r0, r10, r4
 *   @0xcce70 add r11, r12, r8
 *   @0xcce74 rsb r7, r8, r7
 *   @0xcce78 mov r2, r8
 *   @0xcce7c bl 0xb65bc <memcpy@plt>
 *   @0xcce80 add r0, r4, r8
 *   @0xcce84 mov r1, r6
 *   @0xcce88 bl 0x318dec <__aeabi_idivmod>
 *   @0xcce8c mov r0, r11
 *   @0xcce90 mov r4, r1
 *   @0xcce94 mov r1, r5
 *   @0xcce98 bl 0x318dec <__aeabi_idivmod>
 *   @0xcce9c cmp r7, #0
 *   @0xccea0 mov r12, r1
 *   @0xccea4 bgt 0xcce50 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0xbc>
 *   @0xccea8 mov r0, r4
 *   @0xcceac pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcceb0 cmp r12, #0
 *   @0xcceb4 bge 0xccec0 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x12c>
 *   @0xcceb8 adds r12, r12, r5
 *   @0xccebc bmi 0xcceb8 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x124>
 *   @0xccec0 cmp r12, r5
 *   @0xccec4 blt 0xcced4 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x140>
 *   @0xccec8 rsb r12, r5, r12
 *   @0xccecc cmp r5, r12
 *   @0xcced0 ble 0xccec8 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x134>
 *   @0xcced4 add r3, r12, r7
 *   @0xcced8 cmp r5, r3
 *   @0xccedc movge r3, #0
 *   @0xccee0 movlt r3, #1
 *   @0xccee4 cmp r2, #0
 *   @0xccee8 bne 0xcce10 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x7c>
 *   @0xcceec cmp r4, #0
 *   @0xccef0 blt 0xccf28 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x194>
 *   @0xccef4 cmp r6, r4
 *   @0xccef8 ble 0xccf30 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x19c>
 *   @0xccefc add r2, r7, r4
 *   @0xccf00 cmp r6, r2
 *   @0xccf04 rsblt r7, r4, r6
 *   @0xccf08 cmp r3, #0
 *   @0xccf0c bne 0xcce48 <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0xb4>
 *   @0xccf10 add r0, r10, r4
 *   @0xccf14 add r1, r9, r12
 *   @0xccf18 mov r2, r7
 *   @0xccf1c bl 0xb65bc <memcpy@plt>
 *   @0xccf20 add r0, r4, r7
 *   @0xccf24 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xccf28 mov r4, r2
 *   @0xccf2c b 0xccefc <_ZN7IBuffer18CopyMemoryToMemoryEPhiS0_iiiibb+0x168>
 *   @0xccf30 mvn r0, #0
 *   @0xccf34 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §56/70 VM::PokeDSPriority(int, int, RValue&)  0xe50b4  size 420  105 条（0xe50b4..0xe5258）
 * @func 0xe50b4 0xe5258  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::PokeDSPriority(int, int, RValue&)+0xe4×2 / GetThePriorityQueues(int&) / FREE_RValue__Pre(RValue*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×10 / 0xc×6 / 0x8×4 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe50b4 push {r4, r5, r6, r7, lr}
 *   @0xe50b8 sub sp, sp, #12
 *   @0xe50bc mov r4, r0
 *   @0xe50c0 add r0, sp, #4
 *   @0xe50c4 mov r5, r1
 *   @0xe50c8 mov r6, r2
 *   @0xe50cc bl 0x100244 <_Z20GetThePriorityQueuesRi>
 *   @0xe50d0 cmp r4, #0
 *   @0xe50d4 blt 0xe5198 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe4>
 *   @0xe50d8 ldr r3, [sp, #0x4]
 *   @0xe50dc cmp r4, r3
 *   @0xe50e0 bge 0xe5198 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe4>
 *   @0xe50e4 ldr r0, [r0, r4, lsl #2]
 *   @0xe50e8 cmp r0, #0
 *   @0xe50ec beq 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8>
 *   @0xe50f0 cmp r5, #0
 *   @0xe50f4 blt 0xe5198 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe4>
 *   @0xe50f8 ldr r3, [r0, #0x4]
 *   @0xe50fc cmp r5, r3
 *   @0xe5100 bge 0xe5198 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe4>
 *   @0xe5104 ldr r7, [r0, #0xc]
 *   @0xe5108 add r4, r7, r5, lsl #4
 *   @0xe510c ldr r3, [r4, #0xc]
 *   @0xe5110 sub r3, r3, #1
 *   @0xe5114 bic r3, r3, #-16777216
 *   @0xe5118 bic r3, r3, #3
 *   @0xe511c cmp r3, #0
 *   @0xe5120 beq 0xe51b4 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x100>
 *   @0xe5124 mov r3, #5
 *   @0xe5128 str r3, [r4, #0xc]
 *   @0xe512c ldr r1, [r6, #0xc]
 *   @0xe5130 mov r3, #0
 *   @0xe5134 str r3, [r4, #0x8]
 *   @0xe5138 str r3, [r7, r5, lsl #4]
 *   @0xe513c ldr r2, [r6, #0x8]
 *   @0xe5140 str r1, [r4, #0xc]
 *   @0xe5144 ldr r3, [r6, #0xc]
 *   @0xe5148 str r2, [r4, #0x8]
 *   @0xe514c bic r3, r3, #-16777216
 *   @0xe5150 cmp r3, #14
 *   @0xe5154 addls pc, pc, r3, lsl #2
 *   @0xe5158 b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe515c b 0xe51c0 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x10c>
 *   @0xe5160 b 0xe51d8 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x124>
 *   @0xe5164 b 0xe51f8 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x144>
 *   @0xe5168 b 0xe51a4 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xf0>
 *   @0xe516c b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe5170 b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe5174 b 0xe5230 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x17c>
 *   @0xe5178 b 0xe51a4 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xf0>
 *   @0xe517c b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe5180 b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe5184 b 0xe51c0 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x10c>
 *   @0xe5188 b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe518c b 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe5190 b 0xe51c0 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x10c>
 *   @0xe5194 b 0xe51a4 <_ZN2VM14PokeDSPriorityEiiR6RValue+0xf0>
 *   @0xe5198 mov r0, #0
 *   @0xe519c add sp, sp, #12
 *   @0xe51a0 pop {r4, r5, r6, r7, pc}
 *   @0xe51a4 ldr r3, [r6]
 *   @0xe51a8 mov r0, #1
 *   @0xe51ac str r3, [r7, r5, lsl #4]
 *   @0xe51b0 b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8>
 *   @0xe51b4 mov r0, r4
 *   @0xe51b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe51bc b 0xe5124 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x70>
 *   @0xe51c0 ldr r2, [r6]
 *   @0xe51c4 mov r0, #1
 *   @0xe51c8 ldr r3, [r6, #0x4]
 *   @0xe51cc str r2, [r7, r5, lsl #4]
 *   @0xe51d0 str r3, [r4, #0x4]
 *   @0xe51d4 b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8>
 *   @0xe51d8 ldr r3, [r6]
 *   @0xe51dc mov r0, #1
 *   @0xe51e0 cmp r3, #0
 *   @0xe51e4 ldrne r2, [r3, #0x4]
 *   @0xe51e8 addne r2, r2, #1
 *   @0xe51ec strne r2, [r3, #0x4]
 *   @0xe51f0 str r3, [r7, r5, lsl #4]
 *   @0xe51f4 b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8>
 *   @0xe51f8 ldr r3, [r6]
 *   @0xe51fc cmp r3, #0
 *   @0xe5200 str r3, [r7, r5, lsl #4]
 *   @0xe5204 beq 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe5208 ldr r1, [r3, #0x8]
 *   @0xe520c ldr r2, [r3]
 *   @0xe5210 cmp r1, #0
 *   @0xe5214 streq r4, [r3, #0x8]
 *   @0xe5218 add r2, r2, #1
 *   @0xe521c str r2, [r3]
 *   @0xe5220 moveq r0, #1
 *   @0xe5224 beq 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8>
 *   @0xe5228 mov r0, #1
 *   @0xe522c b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8>
 *   @0xe5230 ldr r3, [r6]
 *   @0xe5234 str r3, [r7, r5, lsl #4]
 *   @0xe5238 ldr r3, [r6]
 *   @0xe523c cmp r3, #0
 *   @0xe5240 beq 0xe5228 <_ZN2VM14PokeDSPriorityEiiR6RValue+0x174>
 *   @0xe5244 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xe5248 ldr r1, [r6]
 *   @0xe524c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xe5250 mov r0, #1
 *   @0xe5254 b 0xe519c <_ZN2VM14PokeDSPriorityEiiR6RValue+0xe8>
 *
 * ══ §57/70 F_ActionCreateObjectRandom(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e330  size 420  105 条（0x13e330..0x13e4d4）
 * @func 0x13e330 0x13e4d4  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13e3f0→0x47a174, 0x13e404→0x54298c, 0x13e46c→0x54298c
 * 调用序列: Object_Exists(int)×5 / YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×2 / CRoom::AddInstance(float, float, int)×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / YYRandom(int)
 * 字段偏移 top8: 0x38×1 / 0x178×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x-10×1 / 0xd4×1 / 0xc4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e330 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x13e334 vpush {d8}
 *   @0x13e338 sub sp, sp, #16
 *   @0x13e33c mov r9, r1
 *   @0x13e340 mov r1, #0
 *   @0x13e344 ldr r4, [sp, #0x38]
 *   @0x13e348 ldr r5, [pc, #0x178]
 *   @0x13e34c mov r0, r4
 *   @0x13e350 add r5, pc, r5
 *   @0x13e354 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e358 mov r1, #1
 *   @0x13e35c mov r6, r0
 *   @0x13e360 mov r0, r4
 *   @0x13e364 str r6, [sp]
 *   @0x13e368 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e36c mov r1, #2
 *   @0x13e370 mov r7, r0
 *   @0x13e374 mov r0, r4
 *   @0x13e378 str r7, [sp, #0x4]
 *   @0x13e37c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e380 mov r1, #3
 *   @0x13e384 mov r8, r0
 *   @0x13e388 mov r0, r4
 *   @0x13e38c str r8, [sp, #0x8]
 *   @0x13e390 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e394 mov r1, #4
 *   @0x13e398 mov r10, r0
 *   @0x13e39c mov r0, r4
 *   @0x13e3a0 str r10, [sp, #0xc]
 *   @0x13e3a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e3a8 mov r1, #5
 *   @0x13e3ac vmov s17, r0
 *   @0x13e3b0 mov r0, r4
 *   @0x13e3b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e3b8 vmov s16, r0
 *   @0x13e3bc mov r0, r6
 *   @0x13e3c0 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x13e3c4 cmp r0, #0
 *   @0x13e3c8 beq 0x13e494 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x13e3cc mov r0, #4
 *   @0x13e3d0 bl 0xc4600 <_Z8YYRandomi>
 *   @0x13e3d4 add r3, sp, #16
 *   @0x13e3d8 add r0, r3, r0, lsl #2
 *   @0x13e3dc ldr r4, [r0, #-0x10]
 *   @0x13e3e0 mov r0, r4
 *   @0x13e3e4 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x13e3e8 cmp r0, #0
 *   @0x13e3ec beq 0x13e3cc <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13e3f0 ldr r3, [pc, #0xd4]
 *   @0x13e3f4 ldr r3, [r5, r3]
 *   @0x13e3f8 ldrb r3, [r3]
 *   @0x13e3fc cmp r3, #0
 *   @0x13e400 bne 0x13e460 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x13e404 ldr r0, [pc, #0xc4]
 *   @0x13e408 mov r3, r4
 *   @0x13e40c vmov r1, s17
 *   @0x13e410 vmov r2, s16
 *   @0x13e414 ldr r0, [r5, r0]
 *   @0x13e418 ldr r0, [r0]
 *   @0x13e41c bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi>
 *   @0x13e420 mov r4, r0
 *   @0x13e424 mov r0, r4
 *   @0x13e428 mov r1, r4
 *   @0x13e42c mov r2, #14
 *   @0x13e430 mov r3, #0
 *   @0x13e434 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x13e438 mov r2, #0
 *   @0x13e43c mov r3, r2
 *   @0x13e440 mov r0, r4
 *   @0x13e444 mov r1, r4
 *   @0x13e448 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x13e44c mov r3, #1
 *   @0x13e450 strb r3, [r4, #0x6c]
 *   @0x13e454 add sp, sp, #16
 *   @0x13e458 vpop {d8}
 *   @0x13e45c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x13e460 vldr s14, [r9, #180]
 *   @0x13e464 vldr s15, [r9, #184]
 *   @0x13e468 vadd.f32 s14, s17, s14
 *   @0x13e46c ldr r2, [pc, #0x5c]
 *   @0x13e470 mov r3, r4
 *   @0x13e474 ldr r2, [r5, r2]
 *   @0x13e478 ldr r0, [r2]
 *   @0x13e47c vadd.f32 s15, s16, s15
 *   @0x13e480 vmov r1, s14
 *   @0x13e484 vmov r2, s15
 *   @0x13e488 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi>
 *   @0x13e48c mov r4, r0
 *   @0x13e490 b 0x13e424 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x13e494 mov r0, r7
 *   @0x13e498 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x13e49c cmp r0, #0
 *   @0x13e4a0 bne 0x13e3cc <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13e4a4 mov r0, r8
 *   @0x13e4a8 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x13e4ac cmp r0, #0
 *   @0x13e4b0 bne 0x13e3cc <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13e4b4 mov r0, r10
 *   @0x13e4b8 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x13e4bc cmp r0, #0
 *   @0x13e4c0 beq 0x13e454 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x13e4c4 b 0x13e3cc <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13e4c8 eoreq r3, r11, r0, lsl #18
 *   @0x13e4cc .word 0xffffbeec
 *   @0x13e4d0 .word 0xffffbcd8
 *
 * ══ §58/70 YYGML_action_move(CInstance*, char const*, float)  0x141394  size 420  105 条（0x141394..0x141538）
 * @func 0x141394 0x141538  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / CInstance::SetSpeed(float) / YYRandom(int) / CInstance::SetDirection(float)
 * 字段偏移 top8: 0x170×1 / 0x12c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141394 push {r4, r5, r6, lr}
 *   @0x141398 subs r4, r1, #0
 *   @0x14139c mov r5, r0
 *   @0x1413a0 mov r6, r2
 *   @0x1413a4 beq 0x1413b8 <_Z17YYGML_action_moveP9CInstancePKcf+0x24>
 *   @0x1413a8 mov r0, r4
 *   @0x1413ac bl 0xb6538 <strlen@plt>
 *   @0x1413b0 cmp r0, #9
 *   @0x1413b4 beq 0x1413cc <_Z17YYGML_action_moveP9CInstancePKcf+0x38>
 *   @0x1413b8 ldr r0, [pc, #0x170]
 *   @0x1413bc mov r1, #0
 *   @0x1413c0 pop {r4, r5, r6, lr}
 *   @0x1413c4 add r0, pc, r0
 *   @0x1413c8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1413cc mov r3, #0
 *   @0x1413d0 mov r12, r3
 *   @0x1413d4 cmp r12, #0
 *   @0x1413d8 bne 0x1413ec <_Z17YYGML_action_moveP9CInstancePKcf+0x58>
 *   @0x1413dc ldrb r12, [r4, r3]
 *   @0x1413e0 subs r2, r12, #49
 *   @0x1413e4 rsbs r12, r2, #0
 *   @0x1413e8 adcs r12, r12, r2
 *   @0x1413ec add r3, r3, #1
 *   @0x1413f0 cmp r3, #9
 *   @0x1413f4 bne 0x1413d4 <_Z17YYGML_action_moveP9CInstancePKcf+0x40>
 *   @0x1413f8 cmp r12, #0
 *   @0x1413fc popeq {r4, r5, r6, pc}
 *   @0x141400 ldr r3, [pc, #0x12c]
 *   @0x141404 ldr r3, [pc, r3]
 *   @0x141408 ldrb r3, [r3]
 *   @0x14140c cmp r3, #0
 *   @0x141410 vldrne s15, [r5, #208]
 *   @0x141414 vmovne s14, r6
 *   @0x141418 movne r0, r5
 *   @0x14141c moveq r1, r6
 *   @0x141420 moveq r0, r5
 *   @0x141424 vaddne.f32 s14, s14, s15
 *   @0x141428 vmovne r1, s14
 *   @0x14142c bl 0x1930d4 <_ZN9CInstance8SetSpeedEf>
 *   @0x141430 mov r0, #9
 *   @0x141434 bl 0xc4600 <_Z8YYRandomi>
 *   @0x141438 ldrb r3, [r4, r0]
 *   @0x14143c cmp r3, #49
 *   @0x141440 bne 0x141430 <_Z17YYGML_action_moveP9CInstancePKcf+0x9c>
 *   @0x141444 cmp r0, #8
 *   @0x141448 addls pc, pc, r0, lsl #2
 *   @0x14144c b 0x141474 <_Z17YYGML_action_moveP9CInstancePKcf+0xe0>
 *   @0x141450 b 0x14148c <_Z17YYGML_action_moveP9CInstancePKcf+0xf8>
 *   @0x141454 b 0x1414a0 <_Z17YYGML_action_moveP9CInstancePKcf+0x10c>
 *   @0x141458 b 0x1414b4 <_Z17YYGML_action_moveP9CInstancePKcf+0x120>
 *   @0x14145c b 0x1414c8 <_Z17YYGML_action_moveP9CInstancePKcf+0x134>
 *   @0x141460 b 0x1414dc <_Z17YYGML_action_moveP9CInstancePKcf+0x148>
 *   @0x141464 b 0x1414f8 <_Z17YYGML_action_moveP9CInstancePKcf+0x164>
 *   @0x141468 b 0x141508 <_Z17YYGML_action_moveP9CInstancePKcf+0x174>
 *   @0x14146c b 0x14151c <_Z17YYGML_action_moveP9CInstancePKcf+0x188>
 *   @0x141470 b 0x141478 <_Z17YYGML_action_moveP9CInstancePKcf+0xe4>
 *   @0x141474 pop {r4, r5, r6, pc}
 *   @0x141478 mov r0, r5
 *   @0x14147c mov r1, #0
 *   @0x141480 pop {r4, r5, r6, lr}
 *   @0x141484 movt r1, #0x4234
 *   @0x141488 b 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x14148c mov r0, r5
 *   @0x141490 mov r1, #0
 *   @0x141494 pop {r4, r5, r6, lr}
 *   @0x141498 movt r1, #0x4361
 *   @0x14149c b 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x1414a0 mov r0, r5
 *   @0x1414a4 mov r1, #0
 *   @0x1414a8 pop {r4, r5, r6, lr}
 *   @0x1414ac movt r1, #0x4387
 *   @0x1414b0 b 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x1414b4 mov r0, r5
 *   @0x1414b8 mov r1, #32768
 *   @0x1414bc pop {r4, r5, r6, lr}
 *   @0x1414c0 movt r1, #0x439d
 *   @0x1414c4 b 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x1414c8 mov r0, r5
 *   @0x1414cc mov r1, #0
 *   @0x1414d0 pop {r4, r5, r6, lr}
 *   @0x1414d4 movt r1, #0x4334
 *   @0x1414d8 b 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x1414dc mov r0, r5
 *   @0x1414e0 mov r1, #0
 *   @0x1414e4 bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x1414e8 mov r0, r5
 *   @0x1414ec mov r1, #0
 *   @0x1414f0 pop {r4, r5, r6, lr}
 *   @0x1414f4 b 0x1930d4 <_ZN9CInstance8SetSpeedEf>
 *   @0x1414f8 mov r0, r5
 *   @0x1414fc mov r1, #0
 *   @0x141500 pop {r4, r5, r6, lr}
 *   @0x141504 b 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x141508 mov r0, r5
 *   @0x14150c mov r1, #0
 *   @0x141510 pop {r4, r5, r6, lr}
 *   @0x141514 movt r1, #0x4307
 *   @0x141518 b 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x14151c mov r0, r5
 *   @0x141520 mov r1, #0
 *   @0x141524 pop {r4, r5, r6, lr}
 *   @0x141528 movt r1, #0x42b4
 *   @0x14152c b 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x141530 andseq pc, pc, r4, asr #12
 *   @0x141534 eoreq r12, r10, r8, lsr r7
 *
 * ══ §59/70 YYAnalyticsEventExt(char const*, int, SKeyValueNumber const*)  0x15f3d0  size 420  105 条（0x15f3d0..0x15f574）
 * @func 0x15f3d0 0x15f574  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×9 / YYAnalyticsEventExt(char const*, int, SKeyValueNumber const*)+0x130 / 0xb65c8 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...) / 0xb65d4
 * 字段偏移 top8: 0x29c×4 / 0xc×2 / 0x34×2 / 0x2b8×2 / 0x17c×1 / 0x158×1 / 0x18×1 / 0x140×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f3d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x15f3d4 sub sp, sp, #60
 *   @0x15f3d8 ldr r10, [pc, #0x17c]
 *   @0x15f3dc mov r5, r2
 *   @0x15f3e0 lsl r8, r1, #1
 *   @0x15f3e4 str r0, [sp, #0xc]
 *   @0x15f3e8 ldr r10, [pc, r10]
 *   @0x15f3ec ldr r3, [r10]
 *   @0x15f3f0 str r3, [sp, #0x34]
 *   @0x15f3f4 bl 0x290274 <getJNIEnv>
 *   @0x15f3f8 mov r4, r0
 *   @0x15f3fc bl 0x290274 <getJNIEnv>
 *   @0x15f400 ldr r1, [pc, #0x158]
 *   @0x15f404 add r1, pc, r1
 *   @0x15f408 ldr r3, [r0]
 *   @0x15f40c ldr r3, [r3, #0x18]
 *   @0x15f410 blx r3
 *   @0x15f414 mov r6, r0
 *   @0x15f418 bl 0x290274 <getJNIEnv>
 *   @0x15f41c ldr r1, [pc, #0x140]
 *   @0x15f420 add r1, pc, r1
 *   @0x15f424 ldr r3, [r0]
 *   @0x15f428 ldr r3, [r3, #0x29c]
 *   @0x15f42c blx r3
 *   @0x15f430 ldr r12, [r4]
 *   @0x15f434 mov r2, r6
 *   @0x15f438 mov r1, r8
 *   @0x15f43c ldr r12, [r12, #0x2b0]
 *   @0x15f440 mov r3, r0
 *   @0x15f444 mov r0, r4
 *   @0x15f448 blx r12
 *   @0x15f44c cmp r8, #0
 *   @0x15f450 mov r6, r0
 *   @0x15f454 ble 0x15f500 <_Z19YYAnalyticsEventExtPKciPK15SKeyValueNumber+0x130>
 *   @0x15f458 ldr r9, [pc, #0x108]
 *   @0x15f45c add r5, r5, #16
 *   @0x15f460 add r7, sp, #20
 *   @0x15f464 mov r4, #0
 *   @0x15f468 add r9, pc, r9
 *   @0x15f46c bl 0x290274 <getJNIEnv>
 *   @0x15f470 ldr r1, [r5, #-0x10]
 *   @0x15f474 add r5, r5, #16
 *   @0x15f478 ldr r3, [r0]
 *   @0x15f47c ldr r3, [r3, #0x29c]
 *   @0x15f480 blx r3
 *   @0x15f484 mov r11, r0
 *   @0x15f488 bl 0x290274 <getJNIEnv>
 *   @0x15f48c mov r3, r11
 *   @0x15f490 mov r2, r4
 *   @0x15f494 mov r1, r6
 *   @0x15f498 ldr r12, [r0]
 *   @0x15f49c ldr r12, [r12, #0x2b8]
 *   @0x15f4a0 blx r12
 *   @0x15f4a4 vldr d7, [r5, #-24]
 *   @0x15f4a8 vcvt.s32.f64 s13, d7
 *   @0x15f4ac mov r2, r9
 *   @0x15f4b0 mov r1, #32
 *   @0x15f4b4 mov r0, r7
 *   @0x15f4b8 vmov r3, s13
 *   @0x15f4bc bl 0xb65c8 <snprintf@plt>
 *   @0x15f4c0 bl 0x290274 <getJNIEnv>
 *   @0x15f4c4 mov r1, r7
 *   @0x15f4c8 ldr r3, [r0]
 *   @0x15f4cc ldr r3, [r3, #0x29c]
 *   @0x15f4d0 blx r3
 *   @0x15f4d4 mov r11, r0
 *   @0x15f4d8 bl 0x290274 <getJNIEnv>
 *   @0x15f4dc add r2, r4, #1
 *   @0x15f4e0 mov r3, r11
 *   @0x15f4e4 mov r1, r6
 *   @0x15f4e8 add r4, r4, #2
 *   @0x15f4ec ldr r12, [r0]
 *   @0x15f4f0 ldr r12, [r12, #0x2b8]
 *   @0x15f4f4 blx r12
 *   @0x15f4f8 cmp r8, r4
 *   @0x15f4fc bgt 0x15f46c <_Z19YYAnalyticsEventExtPKciPK15SKeyValueNumber+0x9c>
 *   @0x15f500 bl 0x290274 <getJNIEnv>
 *   @0x15f504 ldr r1, [sp, #0xc]
 *   @0x15f508 ldr r3, [r0]
 *   @0x15f50c ldr r3, [r3, #0x29c]
 *   @0x15f510 blx r3
 *   @0x15f514 mov r4, r0
 *   @0x15f518 bl 0x290274 <getJNIEnv>
 *   @0x15f51c ldr r1, [pc, #0x48]
 *   @0x15f520 mov r3, r4
 *   @0x15f524 ldr r2, [pc, #0x44]
 *   @0x15f528 ldr r1, [pc, r1]
 *   @0x15f52c ldr r2, [pc, r2]
 *   @0x15f530 ldr r1, [r1]
 *   @0x15f534 ldr r2, [r2]
 *   @0x15f538 str r6, [sp]
 *   @0x15f53c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f540 ldr r2, [sp, #0x34]
 *   @0x15f544 ldr r3, [r10]
 *   @0x15f548 cmp r2, r3
 *   @0x15f54c bne 0x15f558 <_Z19YYAnalyticsEventExtPKciPK15SKeyValueNumber+0x188>
 *   @0x15f550 add sp, sp, #60
 *   @0x15f554 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x15f558 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x15f55c eoreq lr, r8, r8, ror #10
 *   @0x15f560 andseq r10, lr, r12, asr r3
 *   @0x15f564 andseq pc, r12, r6, lsl r7
 *   @0x15f568 andseq r3, sp, r4, lsr #1
 *   @0x15f56c eoreq lr, r8, r12, ror r4
 *   @0x15f570 eoreq r0, r9, r8, asr #19
 *
 * ══ §60/70 Graphics::Surface_SetRect(void*, void*, int, int, int, int)  0x17e6ac  size 420  105 条（0x17e6ac..0x17e850）
 * @func 0x17e6ac 0x17e850  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush()
 * 字段偏移 top8: 0x1c×2 / 0x18×2 / 0x10×2 / 0x4×2 / 0x8×2 / 0xc×2 / 0x50×1 / 0x148×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17e6ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17e6b0 sub sp, sp, #44
 *   @0x17e6b4 mov r9, r2
 *   @0x17e6b8 mov r8, r3
 *   @0x17e6bc mov r5, r0
 *   @0x17e6c0 ldr r10, [sp, #0x50]
 *   @0x17e6c4 mov r4, r1
 *   @0x17e6c8 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17e6cc cmp r9, #0
 *   @0x17e6d0 ldmib r4, {r1, r3}
 *   @0x17e6d4 addlt r7, r10, r9
 *   @0x17e6d8 rsblt r2, r9, #0
 *   @0x17e6dc movge r7, r10
 *   @0x17e6e0 movlt r9, #0
 *   @0x17e6e4 movge r2, #0
 *   @0x17e6e8 cmp r8, #0
 *   @0x17e6ec rsblt r12, r8, #0
 *   @0x17e6f0 ldr r11, [pc, #0x148]
 *   @0x17e6f4 ldrlt r0, [sp, #0x54]
 *   @0x17e6f8 movge r12, #0
 *   @0x17e6fc ldrge r6, [sp, #0x54]
 *   @0x17e700 add r11, pc, r11
 *   @0x17e704 addlt r6, r0, r8
 *   @0x17e708 add r0, r9, r7
 *   @0x17e70c movlt r8, #0
 *   @0x17e710 cmp r1, r0
 *   @0x17e714 rsblt r7, r9, r1
 *   @0x17e718 add r1, r8, r6
 *   @0x17e71c cmp r3, r1
 *   @0x17e720 rsblt r6, r8, r3
 *   @0x17e724 cmp r7, #0
 *   @0x17e728 cmpgt r6, #0
 *   @0x17e72c movgt r3, #0
 *   @0x17e730 movle r3, #1
 *   @0x17e734 bgt 0x17e740 <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0x94>
 *   @0x17e738 add sp, sp, #44
 *   @0x17e73c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17e740 ldr lr, [pc, #0xfc]
 *   @0x17e744 add r1, sp, #40
 *   @0x17e748 movw r0, #0x8069
 *   @0x17e74c str r3, [r1, #-0x4]!
 *   @0x17e750 ldr r3, [r11, lr]
 *   @0x17e754 ldr r3, [r3]
 *   @0x17e758 str r2, [sp, #0x1c]
 *   @0x17e75c str r12, [sp, #0x18]
 *   @0x17e760 blx r3
 *   @0x17e764 ldr r3, [pc, #0xdc]
 *   @0x17e768 ldr r1, [r4, #0x14]
 *   @0x17e76c movw r0, #0xde1
 *   @0x17e770 ldr r3, [r11, r3]
 *   @0x17e774 ldr r3, [r3]
 *   @0x17e778 blx r3
 *   @0x17e77c ldr r2, [sp, #0x1c]
 *   @0x17e780 ldr r12, [sp, #0x18]
 *   @0x17e784 orrs r1, r12, r2
 *   @0x17e788 beq 0x17e7f4 <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0x148>
 *   @0x17e78c mla r2, r10, r12, r2
 *   @0x17e790 ldr r3, [pc, #0xb4]
 *   @0x17e794 lsl r10, r10, #2
 *   @0x17e798 mov r4, #0
 *   @0x17e79c ldr r11, [r11, r3]
 *   @0x17e7a0 add r5, r5, r2, lsl #2
 *   @0x17e7a4 str r5, [sp, #0x10]
 *   @0x17e7a8 mov r3, #1
 *   @0x17e7ac str r7, [sp]
 *   @0x17e7b0 movw r0, #0xde1
 *   @0x17e7b4 str r3, [sp, #0x4]
 *   @0x17e7b8 movw r3, #0x1908
 *   @0x17e7bc str r3, [sp, #0x8]
 *   @0x17e7c0 movw r3, #0x1401
 *   @0x17e7c4 str r3, [sp, #0xc]
 *   @0x17e7c8 mov r1, #0
 *   @0x17e7cc add r3, r4, r8
 *   @0x17e7d0 mov r2, r9
 *   @0x17e7d4 add r4, r4, #1
 *   @0x17e7d8 ldr r12, [r11]
 *   @0x17e7dc blx r12
 *   @0x17e7e0 cmp r6, r4
 *   @0x17e7e4 add r5, r5, r10
 *   @0x17e7e8 bgt 0x17e7a4 <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0xf8>
 *   @0x17e7ec add sp, sp, #44
 *   @0x17e7f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17e7f4 ldr r3, [sp, #0x54]
 *   @0x17e7f8 cmp r7, r10
 *   @0x17e7fc cmpeq r6, r3
 *   @0x17e800 bne 0x17e78c <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0xe0>
 *   @0x17e804 ldr r0, [pc, #0x40]
 *   @0x17e808 movw r4, #0x1908
 *   @0x17e80c movw lr, #0x1401
 *   @0x17e810 mov r2, r9
 *   @0x17e814 mov r3, r8
 *   @0x17e818 ldr r12, [r11, r0]
 *   @0x17e81c movw r0, #0xde1
 *   @0x17e820 str r7, [sp]
 *   @0x17e824 str r6, [sp, #0x4]
 *   @0x17e828 ldr r12, [r12]
 *   @0x17e82c str r5, [sp, #0x10]
 *   @0x17e830 str r4, [sp, #0x8]
 *   @0x17e834 str lr, [sp, #0xc]
 *   @0x17e838 blx r12
 *   @0x17e83c b 0x17e738 <_ZN8Graphics15Surface_SetRectEPvS0_iiii+0x8c>
 *   @0x17e840 eoreq r3, r7, r0, asr r5
 *   @0x17e844 .word 0xffffbb48
 *   @0x17e848 .word 0xffffbb20
 *   @0x17e84c .word 0xffffbb30
 *
 * ══ §61/70 LoadShader(unsigned int, char const*, char**)  0x1865bc  size 420  105 条（0x1865bc..0x186760）
 * @func 0x1865bc 0x186760  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1865cc→0x479b1c, 0x1865ec→0x479b18, 0x186608→0x479b14, 0x18661c→0x479b10, 0x18667c→0x479b0c, 0x1866a0→0x3eb70c, 0x1866f8→0x479b34
 * 调用序列: SetupErrorString(char**, char*)×2 / 0xb6544 / 0xb655c
 * 字段偏移 top8: 0xc×4 / 0x4×2 / 0xa4×2 / 0x168×1 / 0x164×1 / 0x148×1 / 0x130×1 / 0x120×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1865bc push {r4, r5, r6, r7, r8, lr}
 *   @0x1865c0 sub sp, sp, #16
 *   @0x1865c4 ldr r4, [pc, #0x168]
 *   @0x1865c8 mov r6, r2
 *   @0x1865cc ldr r3, [pc, #0x164]
 *   @0x1865d0 add r4, pc, r4
 *   @0x1865d4 str r1, [sp, #0x4]
 *   @0x1865d8 ldr r3, [r4, r3]
 *   @0x1865dc ldr r3, [r3]
 *   @0x1865e0 blx r3
 *   @0x1865e4 subs r5, r0, #0
 *   @0x1865e8 beq 0x186718 <_Z10LoadShaderjPKcPPc+0x15c>
 *   @0x1865ec ldr r12, [pc, #0x148]
 *   @0x1865f0 mov r1, #1
 *   @0x1865f4 add r2, sp, #4
 *   @0x1865f8 mov r3, #0
 *   @0x1865fc ldr r12, [r4, r12]
 *   @0x186600 ldr r12, [r12]
 *   @0x186604 blx r12
 *   @0x186608 ldr r3, [pc, #0x130]
 *   @0x18660c mov r0, r5
 *   @0x186610 ldr r3, [r4, r3]
 *   @0x186614 ldr r3, [r3]
 *   @0x186618 blx r3
 *   @0x18661c ldr r3, [pc, #0x120]
 *   @0x186620 mov r0, r5
 *   @0x186624 movw r1, #0x8b81
 *   @0x186628 add r2, sp, #8
 *   @0x18662c ldr r7, [r4, r3]
 *   @0x186630 ldr r3, [r7]
 *   @0x186634 blx r3
 *   @0x186638 ldr r3, [sp, #0x8]
 *   @0x18663c cmp r3, #0
 *   @0x186640 movne r0, r5
 *   @0x186644 beq 0x186650 <_Z10LoadShaderjPKcPPc+0x94>
 *   @0x186648 add sp, sp, #16
 *   @0x18664c pop {r4, r5, r6, r7, r8, pc}
 *   @0x186650 add r2, sp, #16
 *   @0x186654 ldr r12, [r7]
 *   @0x186658 mov r0, r5
 *   @0x18665c movw r1, #0x8b84
 *   @0x186660 str r3, [r2, #-0x4]!
 *   @0x186664 blx r12
 *   @0x186668 ldr r0, [sp, #0xc]
 *   @0x18666c cmp r0, #1
 *   @0x186670 movle r0, #1024
 *   @0x186674 strle r0, [sp, #0xc]
 *   @0x186678 bl 0xb6544 <malloc@plt>
 *   @0x18667c ldr r12, [pc, #0xc4]
 *   @0x186680 ldr r1, [sp, #0xc]
 *   @0x186684 mov r2, #0
 *   @0x186688 ldr r12, [r4, r12]
 *   @0x18668c ldr r12, [r12]
 *   @0x186690 mov r7, r0
 *   @0x186694 mov r3, r0
 *   @0x186698 mov r0, r5
 *   @0x18669c blx r12
 *   @0x1866a0 ldr r3, [pc, #0xa4]
 *   @0x1866a4 ldr r1, [pc, #0xa4]
 *   @0x1866a8 mov r2, r7
 *   @0x1866ac ldr r3, [r4, r3]
 *   @0x1866b0 add r1, pc, r1
 *   @0x1866b4 ldr r8, [r3]
 *   @0x1866b8 ldr r3, [r8]
 *   @0x1866bc mov r0, r8
 *   @0x1866c0 ldr r3, [r3, #0xc]
 *   @0x1866c4 blx r3
 *   @0x1866c8 ldr r3, [r8]
 *   @0x1866cc ldr r1, [pc, #0x80]
 *   @0x1866d0 mov r0, r8
 *   @0x1866d4 ldr r2, [sp, #0x4]
 *   @0x1866d8 ldr r3, [r3, #0xc]
 *   @0x1866dc add r1, pc, r1
 *   @0x1866e0 blx r3
 *   @0x1866e4 mov r1, r7
 *   @0x1866e8 mov r0, r6
 *   @0x1866ec bl 0x186544 <_Z16SetupErrorStringPPcS_>
 *   @0x1866f0 mov r0, r7
 *   @0x1866f4 bl 0xb655c <free@plt>
 *   @0x1866f8 ldr r3, [pc, #0x58]
 *   @0x1866fc mov r0, r5
 *   @0x186700 ldr r3, [r4, r3]
 *   @0x186704 ldr r3, [r3]
 *   @0x186708 blx r3
 *   @0x18670c mov r0, #0
 *   @0x186710 add sp, sp, #16
 *   @0x186714 pop {r4, r5, r6, r7, r8, pc}
 *   @0x186718 ldr r1, [pc, #0x3c]
 *   @0x18671c mov r0, r6
 *   @0x186720 add r1, pc, r1
 *   @0x186724 bl 0x186544 <_Z16SetupErrorStringPPcS_>
 *   @0x186728 mov r0, r5
 *   @0x18672c add sp, sp, #16
 *   @0x186730 pop {r4, r5, r6, r7, r8, pc}
 *   @0x186734 eoreq r11, r6, r0, lsl #13
 *   @0x186738 .word 0xffffbb94
 *   @0x18673c .word 0xffffbb98
 *   @0x186740 .word 0xffffbb9c
 *   @0x186744 .word 0xffffbba0
 *   @0x186748 .word 0xffffbba4
 *   @0x18674c .word 0xffffbac4
 *   @0x186750 andseq r5, r12, r0, ror r5
 *   @0x186754 andseq r5, r12, r0, ror #10
 *   @0x186758 .word 0xffffbb7c
 *   @0x18675c ldrsbeq r5, [r12], -r12
 *
 * ══ §62/70 F_LayerTilemapCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c719c  size 420  105 条（0x1c719c..0x1c7340）
 * @func 0x1c719c 0x1c7340  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetNewTilemapElement() / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0 / CLayerManager::AddNewElement(CRoom*, CLayer*, CLayerElementBase*, bool)
 * 字段偏移 top8: 0x28×4 / 0xc×3 / 0x2c×3 / 0x4×2 / 0x18×1 / 0x15c×1 / 0x1c×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c719c cmp r3, #6
 *   @0x1c71a0 mov r3, #0
 *   @0x1c71a4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c71a8 mov r5, r3
 *   @0x1c71ac mov r4, r0
 *   @0x1c71b0 movt r3, #0xbff0
 *   @0x1c71b4 str r5, [r0, #0xc]
 *   @0x1c71b8 str r3, [r0, #0x4]
 *   @0x1c71bc str r5, [r0]
 *   @0x1c71c0 ldr r6, [sp, #0x18]
 *   @0x1c71c4 beq 0x1c71dc <_Z20F_LayerTilemapCreateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c71c8 ldr r0, [pc, #0x15c]
 *   @0x1c71cc mov r1, r5
 *   @0x1c71d0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c71d4 add r0, pc, r0
 *   @0x1c71d8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c71dc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c71e0 ldr r3, [r6, #0xc]
 *   @0x1c71e4 mov r1, r5
 *   @0x1c71e8 bic r3, r3, #-16777216
 *   @0x1c71ec cmp r3, #1
 *   @0x1c71f0 mov r8, r0
 *   @0x1c71f4 mov r0, r6
 *   @0x1c71f8 beq 0x1c72ec <_Z20F_LayerTilemapCreateR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x1c71fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c7200 mov r1, r0
 *   @0x1c7204 mov r0, r8
 *   @0x1c7208 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c720c mov r7, r0
 *   @0x1c7210 cmp r7, #0
 *   @0x1c7214 beq 0x1c7304 <_Z20F_LayerTilemapCreateR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1c7218 bl 0x1c1034 <_ZN13CLayerManager20GetNewTilemapElementEv>
 *   @0x1c721c mov r1, #3
 *   @0x1c7220 mov r5, r0
 *   @0x1c7224 mov r0, r6
 *   @0x1c7228 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c722c mov r1, #1
 *   @0x1c7230 str r0, [r5, #0x1c]
 *   @0x1c7234 mov r0, r6
 *   @0x1c7238 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1c723c mov r1, #2
 *   @0x1c7240 str r0, [r5, #0x20]
 *   @0x1c7244 mov r0, r6
 *   @0x1c7248 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1c724c mov r1, #4
 *   @0x1c7250 str r0, [r5, #0x24]
 *   @0x1c7254 mov r0, r6
 *   @0x1c7258 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c725c mov r1, #5
 *   @0x1c7260 str r0, [r5, #0x28]
 *   @0x1c7264 mov r0, r6
 *   @0x1c7268 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c726c ldr r12, [r5, #0x28]
 *   @0x1c7270 ldr r1, [pc, #0xb8]
 *   @0x1c7274 movw r2, #0x105c
 *   @0x1c7278 mov r3, #1
 *   @0x1c727c add r1, pc, r1
 *   @0x1c7280 str r0, [r5, #0x2c]
 *   @0x1c7284 mul r0, r12, r0
 *   @0x1c7288 lsl r0, r0, #2
 *   @0x1c728c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c7290 ldr r3, [r5, #0x28]
 *   @0x1c7294 ldr r2, [r5, #0x2c]
 *   @0x1c7298 mov r1, #0
 *   @0x1c729c mul r2, r2, r3
 *   @0x1c72a0 lsl r2, r2, #2
 *   @0x1c72a4 str r0, [r5, #0x34]
 *   @0x1c72a8 bl 0xb65b0 <memset@plt>
 *   @0x1c72ac ldr r3, [pc, #0x80]
 *   @0x1c72b0 mov r2, r5
 *   @0x1c72b4 mov r0, r8
 *   @0x1c72b8 ldr r3, [pc, r3]
 *   @0x1c72bc mov r1, r7
 *   @0x1c72c0 ldr r3, [r3]
 *   @0x1c72c4 subs r12, r3, r8
 *   @0x1c72c8 rsbs r3, r12, #0
 *   @0x1c72cc adcs r3, r3, r12
 *   @0x1c72d0 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1c72d4 ldr r2, [r5, #0x4]
 *   @0x1c72d8 vmov s15, r2
 *   @0x1c72dc vcvt.f64.s32 d7, s15
 *   @0x1c72e0 vmov r2, r3, d7
 *   @0x1c72e4 stm r4, {r2, r3}
 *   @0x1c72e8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c72ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c72f0 mov r1, r0
 *   @0x1c72f4 mov r0, r8
 *   @0x1c72f8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c72fc mov r7, r0
 *   @0x1c7300 b 0x1c7210 <_Z20F_LayerTilemapCreateR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1c7304 ldr r3, [pc, #0x2c]
 *   @0x1c7308 mov r2, r7
 *   @0x1c730c ldr r1, [pc, #0x28]
 *   @0x1c7310 ldr r3, [pc, r3]
 *   @0x1c7314 add r1, pc, r1
 *   @0x1c7318 ldr r0, [r3]
 *   @0x1c731c ldr r3, [r0]
 *   @0x1c7320 ldr r3, [r3, #0xc]
 *   @0x1c7324 blx r3
 *   @0x1c7328 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c732c andseq r9, r8, r8, ror r8
 *   @0x1c7330 ldrsheq r6, [r8], -r0
 *   @0x1c7334 eoreq r6, r2, r0, ror r6
 *   @0x1c7338 eoreq r6, r2, r4, lsl #8
 *   @0x1c733c andseq r9, r8, r12, ror #14
 *
 * ══ §63/70 FINALIZE_Run_Global()  0x1cba6c  size 420  105 条（0x1cba6c..0x1cbc10）
 * @func 0x1cba6c 0x1cbc10  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1cba7c→0x542944, 0x1cba84→0x3f510c, 0x1cba88→0x3f5108, 0x1cba90→0x3f50fc, 0x1cba94→0x3f50f8, 0x1cbaa0→0x542938, 0x1cbab4→0x542924, 0x1cbac8→0x54295c
 * 调用序列: MemoryManager::Free(void const*)×6 / YYObjectBase::Free(YYObjectBase*)
 * 字段偏移 top8: 0x4×3 / 0x140×2 / 0x13c×2 / 0xd0×2 / 0xac×2 / 0x148×1 / 0x144×1 / 0x134×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cba6c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cba70 mov r5, #0
 *   @0x1cba74 ldr r4, [pc, #0x148]
 *   @0x1cba78 mov r8, #1
 *   @0x1cba7c ldr r3, [pc, #0x144]
 *   @0x1cba80 add r4, pc, r4
 *   @0x1cba84 ldr r11, [pc, #0x140]
 *   @0x1cba88 ldr r10, [pc, #0x140]
 *   @0x1cba8c ldr r6, [r4, r3]
 *   @0x1cba90 ldr r9, [pc, #0x13c]
 *   @0x1cba94 ldr r7, [pc, #0x13c]
 *   @0x1cba98 ldr r0, [r6]
 *   @0x1cba9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1cbaa0 ldr r3, [pc, #0x134]
 *   @0x1cbaa4 str r5, [r6]
 *   @0x1cbaa8 ldr r6, [r4, r3]
 *   @0x1cbaac ldr r0, [r6]
 *   @0x1cbab0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1cbab4 ldr r3, [pc, #0x124]
 *   @0x1cbab8 str r5, [r6]
 *   @0x1cbabc ldr r6, [r4, r3]
 *   @0x1cbac0 ldr r0, [r6]
 *   @0x1cbac4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1cbac8 ldr r3, [pc, #0x114]
 *   @0x1cbacc str r5, [r6]
 *   @0x1cbad0 ldr r6, [r4, r3]
 *   @0x1cbad4 ldr r0, [r6]
 *   @0x1cbad8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1cbadc ldr r3, [pc, #0x104]
 *   @0x1cbae0 str r5, [r6]
 *   @0x1cbae4 ldr r6, [r4, r3]
 *   @0x1cbae8 ldr r0, [r6]
 *   @0x1cbaec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1cbaf0 ldr r3, [pc, #0xf4]
 *   @0x1cbaf4 str r5, [r6]
 *   @0x1cbaf8 ldr r6, [r4, r3]
 *   @0x1cbafc ldr r0, [r6]
 *   @0x1cbb00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1cbb04 ldr r2, [pc, #0xe4]
 *   @0x1cbb08 str r5, [r6]
 *   @0x1cbb0c movw r1, #0xdead
 *   @0x1cbb10 ldr r3, [pc, #0xdc]
 *   @0x1cbb14 movt r1, #0xfeee
 *   @0x1cbb18 ldr r0, [r4, r2]
 *   @0x1cbb1c mvn r2, #0
 *   @0x1cbb20 ldr r12, [pc, #0xd0]
 *   @0x1cbb24 ldr r6, [pc, #0xd0]
 *   @0x1cbb28 str r5, [r0]
 *   @0x1cbb2c ldr r0, [r4, r3]
 *   @0x1cbb30 mov r3, r0
 *   @0x1cbb34 str r5, [r3], #4
 *   @0x1cbb38 add r3, r3, #4
 *   @0x1cbb3c str r5, [r0, #0x4]
 *   @0x1cbb40 str r5, [r3], #4
 *   @0x1cbb44 str r5, [r3]
 *   @0x1cbb48 ldr r3, [r4, r12]
 *   @0x1cbb4c ldr r12, [pc, #0xac]
 *   @0x1cbb50 ldr r0, [pc, #0xac]
 *   @0x1cbb54 str r1, [r3]
 *   @0x1cbb58 ldr r3, [r4, r11]
 *   @0x1cbb5c ldr r1, [pc, #0xa4]
 *   @0x1cbb60 str r2, [r3]
 *   @0x1cbb64 ldr r10, [r4, r10]
 *   @0x1cbb68 ldr r3, [pc, #0x9c]
 *   @0x1cbb6c str r2, [r10]
 *   @0x1cbb70 ldr r9, [r4, r9]
 *   @0x1cbb74 strb r8, [r9]
 *   @0x1cbb78 ldr r7, [r4, r7]
 *   @0x1cbb7c str r2, [r7]
 *   @0x1cbb80 ldr r6, [r4, r6]
 *   @0x1cbb84 str r2, [r6]
 *   @0x1cbb88 ldr r12, [r4, r12]
 *   @0x1cbb8c strb r5, [r12]
 *   @0x1cbb90 ldr r0, [r4, r0]
 *   @0x1cbb94 str r5, [r0]
 *   @0x1cbb98 ldr r1, [r4, r1]
 *   @0x1cbb9c str r2, [r1]
 *   @0x1cbba0 ldr r4, [r4, r3]
 *   @0x1cbba4 ldr r0, [r4]
 *   @0x1cbba8 cmp r0, r5
 *   @0x1cbbac beq 0x1cbbb4 <_Z19FINALIZE_Run_Globalv+0x148>
 *   @0x1cbbb0 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_>
 *   @0x1cbbb4 mov r3, #0
 *   @0x1cbbb8 str r3, [r4]
 *   @0x1cbbbc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cbbc0 b 0x191794 <_ZN12YYObjectBase7FreeAllEv>
 *   @0x1cbbc4 .word 0x002261d0
 *   @0x1cbbc8 .word 0xffffd9a0
 *   @0x1cbbcc .word 0xffffdf38
 *   @0x1cbbd0 .word 0xffffdf40
 *   @0x1cbbd4 .word 0xffffdf34
 *   @0x1cbbd8 .word 0xffffc990
 *   @0x1cbbdc .word 0xffffd9a8
 *   @0x1cbbe0 .word 0xffffd9b0
 *   @0x1cbbe4 .word 0xffffeecc
 *   @0x1cbbe8 .word 0xffffeed0
 *   @0x1cbbec .word 0xffffea08
 *   @0x1cbbf0 .word 0xffffeec4
 *   @0x1cbbf4 .word 0xffffeed4
 *   @0x1cbbf8 .word 0xffffc988
 *   @0x1cbbfc .word 0xffffc994
 *   @0x1cbc00 .word 0xffffc98c
 *   @0x1cbc04 .word 0xffffebec
 *   @0x1cbc08 .word 0xffffeec8
 *   @0x1cbc0c .word 0xffffbf64
 *
 * ══ §64/70 CSprite::AddFromBitmap(IBitmap*, bool, bool, bool)  0x1e5988  size 420  105 条（0x1e5988..0x1e5b2c）
 * @func 0x1e5988 0x1e5b2c  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / MemoryManager::Free(void const*)×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CBitmap32::CBitmap32(IBitmap*, bool, bool, int) / CSprite::AddFromBitmap(IBitmap*, bool, bool, bool)+0xd4 / CBitmap32::Stretch(int, int) / CSprite::InitTexture() / CSprite::InitLocalTPE()
 * 字段偏移 top8: 0x18×8 / 0x2×5 / 0x48×4 / 0x20×3 / 0x44×3 / 0x54×3 / 0x4×2 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e5988 ldr r12, [r0, #0x18]
 *   @0x1e598c push {r4, r5, r6, r7, r8, lr}
 *   @0x1e5990 cmp r12, #0
 *   @0x1e5994 sub sp, sp, #8
 *   @0x1e5998 mov r5, r0
 *   @0x1e599c mov r4, r1
 *   @0x1e59a0 mov r7, r2
 *   @0x1e59a4 mov r6, r3
 *   @0x1e59a8 ldrb r8, [sp, #0x20]
 *   @0x1e59ac beq 0x1e5af8 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x170>
 *   @0x1e59b0 add r1, r12, #1
 *   @0x1e59b4 ldr r2, [pc, #0x16c]
 *   @0x1e59b8 add r0, r5, #72
 *   @0x1e59bc str r1, [r5, #0x18]
 *   @0x1e59c0 movw r3, #0x663
 *   @0x1e59c4 add r2, pc, r2
 *   @0x1e59c8 lsl r1, r1, #2
 *   @0x1e59cc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e59d0 ldr r2, [r5, #0x18]
 *   @0x1e59d4 ldr r3, [r5, #0x48]
 *   @0x1e59d8 cmp r8, #0
 *   @0x1e59dc sub r2, r2, #-1073741823
 *   @0x1e59e0 ldr r0, [r3, r2, lsl #2]
 *   @0x1e59e4 beq 0x1e5ab4 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x12c>
 *   @0x1e59e8 cmp r0, #0
 *   @0x1e59ec beq 0x1e59fc <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x74>
 *   @0x1e59f0 ldr r3, [r0]
 *   @0x1e59f4 ldr r3, [r3, #0x4]
 *   @0x1e59f8 blx r3
 *   @0x1e59fc mov r0, #24
 *   @0x1e5a00 bl 0x27c524 <_Znwj>
 *   @0x1e5a04 mov r2, r7
 *   @0x1e5a08 mov r3, r6
 *   @0x1e5a0c mov r12, #0
 *   @0x1e5a10 mov r1, r4
 *   @0x1e5a14 str r12, [sp]
 *   @0x1e5a18 mov r8, r0
 *   @0x1e5a1c bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi>
 *   @0x1e5a20 ldr r2, [r5, #0x18]
 *   @0x1e5a24 ldr r3, [r5, #0x48]
 *   @0x1e5a28 sub r2, r2, #-1073741823
 *   @0x1e5a2c str r8, [r3, r2, lsl #2]
 *   @0x1e5a30 ldr r3, [r5, #0x44]
 *   @0x1e5a34 cmp r3, #0
 *   @0x1e5a38 movgt r4, #0
 *   @0x1e5a3c ble 0x1e5a5c <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0xd4>
 *   @0x1e5a40 ldr r3, [r5, #0x54]
 *   @0x1e5a44 ldr r0, [r3, r4, lsl #2]
 *   @0x1e5a48 add r4, r4, #1
 *   @0x1e5a4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e5a50 ldr r3, [r5, #0x44]
 *   @0x1e5a54 cmp r3, r4
 *   @0x1e5a58 bgt 0x1e5a40 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0xb8>
 *   @0x1e5a5c ldr r0, [r5, #0x54]
 *   @0x1e5a60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e5a64 ldr r3, [r5, #0x18]
 *   @0x1e5a68 ldr r2, [r5, #0x48]
 *   @0x1e5a6c mov r0, #0
 *   @0x1e5a70 sub r1, r3, #-1073741823
 *   @0x1e5a74 str r0, [r5, #0x54]
 *   @0x1e5a78 str r3, [r5, #0x44]
 *   @0x1e5a7c ldr r0, [r2, r1, lsl #2]
 *   @0x1e5a80 ldr r1, [r5, #0x1c]
 *   @0x1e5a84 ldr r2, [r5, #0x20]
 *   @0x1e5a88 bl 0x1673ac <_ZN9CBitmap327StretchEii>
 *   @0x1e5a8c mov r0, r5
 *   @0x1e5a90 bl 0x1e5748 <_ZN7CSprite11InitTextureEv>
 *   @0x1e5a94 mov r0, r5
 *   @0x1e5a98 bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv>
 *   @0x1e5a9c mov r0, r5
 *   @0x1e5aa0 bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv>
 *   @0x1e5aa4 mov r0, r5
 *   @0x1e5aa8 add sp, sp, #8
 *   @0x1e5aac pop {r4, r5, r6, r7, r8, lr}
 *   @0x1e5ab0 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv>
 *   @0x1e5ab4 cmp r0, #0
 *   @0x1e5ab8 beq 0x1e5ac8 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x140>
 *   @0x1e5abc ldr r3, [r0]
 *   @0x1e5ac0 ldr r3, [r3, #0x4]
 *   @0x1e5ac4 blx r3
 *   @0x1e5ac8 mov r0, #24
 *   @0x1e5acc bl 0x27c524 <_Znwj>
 *   @0x1e5ad0 mov r2, r7
 *   @0x1e5ad4 mov r3, r6
 *   @0x1e5ad8 mov r1, r4
 *   @0x1e5adc mov r8, r0
 *   @0x1e5ae0 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb>
 *   @0x1e5ae4 ldr r2, [r5, #0x18]
 *   @0x1e5ae8 ldr r3, [r5, #0x48]
 *   @0x1e5aec sub r2, r2, #-1073741823
 *   @0x1e5af0 str r8, [r3, r2, lsl #2]
 *   @0x1e5af4 b 0x1e5a30 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0xa8>
 *   @0x1e5af8 ldr r3, [r1]
 *   @0x1e5afc mov r0, r1
 *   @0x1e5b00 ldr r3, [r3, #0x10]
 *   @0x1e5b04 blx r3
 *   @0x1e5b08 ldr r3, [r4]
 *   @0x1e5b0c ldr r3, [r3, #0x18]
 *   @0x1e5b10 str r0, [r5, #0x1c]
 *   @0x1e5b14 mov r0, r4
 *   @0x1e5b18 blx r3
 *   @0x1e5b1c ldr r12, [r5, #0x18]
 *   @0x1e5b20 str r0, [r5, #0x20]
 *   @0x1e5b24 b 0x1e59b0 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x28>
 *   @0x1e5b28 andseq r12, r6, r0, ror #20
 *
 * ══ §65/70 FINALIZE_Timeline_Main()  0x1f3174  size 420  105 条（0x1f3174..0x1f3318）
 * @func 0x1f3174 0x1f3318  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×5 / operator delete(void*)×2 / FINALIZE_Timeline_Main()+0xa4 / FINALIZE_Timeline_Main()+0x3c / FINALIZE_Timeline_Main()+0x144 / MemoryManager::IsAllocated(void const*) / FINALIZE_Timeline_Main()+0x108
 * 字段偏移 top8: 0x4×14 / 0x2×3 / 0x18c×1 / 0xcc×1 / 0xc0×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3174 ldr r3, [pc, #0x18c]
 *   @0x1f3178 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f317c ldr r6, [pc, r3]
 *   @0x1f3180 cmp r6, #0
 *   @0x1f3184 beq 0x1f3248 <_Z22FINALIZE_Timeline_Mainv+0xd4>
 *   @0x1f3188 ldr r12, [r6]
 *   @0x1f318c cmp r12, #0
 *   @0x1f3190 beq 0x1f3230 <_Z22FINALIZE_Timeline_Mainv+0xbc>
 *   @0x1f3194 ldr r5, [r6, #0x4]
 *   @0x1f3198 cmp r5, #0
 *   @0x1f319c beq 0x1f32f8 <_Z22FINALIZE_Timeline_Mainv+0x184>
 *   @0x1f31a0 cmp r12, #0
 *   @0x1f31a4 ble 0x1f3218 <_Z22FINALIZE_Timeline_Mainv+0xa4>
 *   @0x1f31a8 mov r4, #0
 *   @0x1f31ac mov r8, r4
 *   @0x1f31b0 ldr r1, [r5]
 *   @0x1f31b4 movw r3, #0xfeee
 *   @0x1f31b8 movt r3, #0xfeee
 *   @0x1f31bc movw r2, #0xfeee
 *   @0x1f31c0 cmp r1, r3
 *   @0x1f31c4 movt r2, #0xfeee
 *   @0x1f31c8 lsl r7, r4, #2
 *   @0x1f31cc beq 0x1f320c <_Z22FINALIZE_Timeline_Mainv+0x98>
 *   @0x1f31d0 ldr r3, [r5, r4, lsl #2]
 *   @0x1f31d4 add r1, r5, r7
 *   @0x1f31d8 cmp r3, #0
 *   @0x1f31dc mov r0, r3
 *   @0x1f31e0 beq 0x1f320c <_Z22FINALIZE_Timeline_Mainv+0x98>
 *   @0x1f31e4 ldr r3, [r3]
 *   @0x1f31e8 cmp r3, r2
 *   @0x1f31ec beq 0x1f3204 <_Z22FINALIZE_Timeline_Mainv+0x90>
 *   @0x1f31f0 ldr r3, [r3, #0x4]
 *   @0x1f31f4 blx r3
 *   @0x1f31f8 ldr r1, [r6, #0x4]
 *   @0x1f31fc ldr r12, [r6]
 *   @0x1f3200 add r1, r1, r7
 *   @0x1f3204 str r8, [r1]
 *   @0x1f3208 ldr r5, [r6, #0x4]
 *   @0x1f320c add r4, r4, #1
 *   @0x1f3210 cmp r4, r12
 *   @0x1f3214 blt 0x1f31b0 <_Z22FINALIZE_Timeline_Mainv+0x3c>
 *   @0x1f3218 mov r0, r5
 *   @0x1f321c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f3220 mov r3, #0
 *   @0x1f3224 str r3, [r6, #0x4]
 *   @0x1f3228 mov r3, #0
 *   @0x1f322c str r3, [r6]
 *   @0x1f3230 mov r0, r6
 *   @0x1f3234 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f3238 ldr r3, [pc, #0xcc]
 *   @0x1f323c mov r2, #0
 *   @0x1f3240 add r3, pc, r3
 *   @0x1f3244 str r2, [r3]
 *   @0x1f3248 ldr r3, [pc, #0xc0]
 *   @0x1f324c add r3, pc, r3
 *   @0x1f3250 ldr r5, [r3, #0x4]
 *   @0x1f3254 cmp r5, #0
 *   @0x1f3258 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1f325c ldr r6, [r5, #0x4]
 *   @0x1f3260 cmp r6, #0
 *   @0x1f3264 beq 0x1f32e8 <_Z22FINALIZE_Timeline_Mainv+0x174>
 *   @0x1f3268 ldr r3, [r5]
 *   @0x1f326c cmp r3, #0
 *   @0x1f3270 ble 0x1f32b8 <_Z22FINALIZE_Timeline_Mainv+0x144>
 *   @0x1f3274 mov r4, #0
 *   @0x1f3278 mov r7, r4
 *   @0x1f327c ldr r0, [r6, r4, lsl #2]
 *   @0x1f3280 lsl r6, r4, #2
 *   @0x1f3284 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x1f3288 cmp r0, #0
 *   @0x1f328c beq 0x1f329c <_Z22FINALIZE_Timeline_Mainv+0x128>
 *   @0x1f3290 ldr r3, [r5, #0x4]
 *   @0x1f3294 ldr r0, [r3, r4, lsl #2]
 *   @0x1f3298 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f329c ldr r2, [r5]
 *   @0x1f32a0 add r4, r4, #1
 *   @0x1f32a4 ldr r3, [r5, #0x4]
 *   @0x1f32a8 cmp r4, r2
 *   @0x1f32ac str r7, [r3, r6]
 *   @0x1f32b0 ldr r6, [r5, #0x4]
 *   @0x1f32b4 blt 0x1f327c <_Z22FINALIZE_Timeline_Mainv+0x108>
 *   @0x1f32b8 mov r0, r6
 *   @0x1f32bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f32c0 mov r3, #0
 *   @0x1f32c4 str r3, [r5, #0x4]
 *   @0x1f32c8 mov r4, #0
 *   @0x1f32cc mov r0, r5
 *   @0x1f32d0 str r4, [r5]
 *   @0x1f32d4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f32d8 ldr r3, [pc, #0x34]
 *   @0x1f32dc add r3, pc, r3
 *   @0x1f32e0 str r4, [r3, #0x4]
 *   @0x1f32e4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f32e8 mov r0, r6
 *   @0x1f32ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f32f0 str r6, [r5, #0x4]
 *   @0x1f32f4 b 0x1f32c8 <_Z22FINALIZE_Timeline_Mainv+0x154>
 *   @0x1f32f8 mov r0, r5
 *   @0x1f32fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f3300 str r5, [r6, #0x4]
 *   @0x1f3304 b 0x1f3228 <_Z22FINALIZE_Timeline_Mainv+0xb4>
 *   @0x1f3308 subseq pc, r5, r0, ror pc
 *   @0x1f330c subseq pc, r5, r12, lsr #29
 *   @0x1f3310 subseq pc, r5, r0, lsr #29
 *   @0x1f3314 subseq pc, r5, r0, lsl lr
 *
 * ══ §66/70 CStream::ReadEncryptedStream()  0x201ee8  size 420  105 条（0x201ee8..0x20208c）
 * @func 0x201ee8 0x20208c  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×5 / CStream::ReadEncryptedStream()+0x50 / CStream::Read(void*, int) / CStream::ReadEncryptedStream()+0x84 / operator new(unsigned int) / CStream::CStream(int) / CStream::CopyFrom(CStream*, long long) / CStream::GetMemory()
 * 字段偏移 top8: 0x-1×4 / 0x204×2 / 0x-104×2 / 0x190×1 / 0x-2×1 / 0x-204×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201ee8 push {r4, r5, r6, r7, r8, lr}
 *   @0x201eec sub sp, sp, #520
 *   @0x201ef0 ldr r5, [pc, #0x190]
 *   @0x201ef4 mov r7, r0
 *   @0x201ef8 ldr r5, [pc, r5]
 *   @0x201efc ldr r3, [r5]
 *   @0x201f00 str r3, [sp, #0x204]
 *   @0x201f04 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x201f08 mov r6, r0
 *   @0x201f0c mov r0, r7
 *   @0x201f10 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x201f14 cmp r6, #0
 *   @0x201f18 movgt r4, #1
 *   @0x201f1c mov r8, r0
 *   @0x201f20 ble 0x201f38 <_ZN7CStream19ReadEncryptedStreamEv+0x50>
 *   @0x201f24 add r4, r4, #1
 *   @0x201f28 mov r0, r7
 *   @0x201f2c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x201f30 cmp r6, r4
 *   @0x201f34 bge 0x201f24 <_ZN7CStream19ReadEncryptedStreamEv+0x3c>
 *   @0x201f38 add r4, sp, #4
 *   @0x201f3c mov r0, r7
 *   @0x201f40 mov r2, #256
 *   @0x201f44 mov r1, r4
 *   @0x201f48 bl 0x20172c <_ZN7CStream4ReadEPvi>
 *   @0x201f4c cmp r8, #0
 *   @0x201f50 movgt r6, #1
 *   @0x201f54 ble 0x201f6c <_ZN7CStream19ReadEncryptedStreamEv+0x84>
 *   @0x201f58 add r6, r6, #1
 *   @0x201f5c mov r0, r7
 *   @0x201f60 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x201f64 cmp r8, r6
 *   @0x201f68 bge 0x201f58 <_ZN7CStream19ReadEncryptedStreamEv+0x70>
 *   @0x201f6c mov r3, #0
 *   @0x201f70 ldrb r2, [r4, r3]
 *   @0x201f74 add r1, sp, #520
 *   @0x201f78 add r2, r1, r2
 *   @0x201f7c strb r3, [r2, #-0x104]
 *   @0x201f80 add r3, r3, #1
 *   @0x201f84 cmp r3, #256
 *   @0x201f88 bne 0x201f70 <_ZN7CStream19ReadEncryptedStreamEv+0x88>
 *   @0x201f8c mov r0, r7
 *   @0x201f90 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x201f94 mov r6, r0
 *   @0x201f98 mov r0, #32
 *   @0x201f9c bl 0x27c524 <_Znwj>
 *   @0x201fa0 mov r1, #0
 *   @0x201fa4 mov r4, r0
 *   @0x201fa8 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x201fac asr r3, r6, #31
 *   @0x201fb0 mov r2, r6
 *   @0x201fb4 mov r0, r4
 *   @0x201fb8 mov r1, r7
 *   @0x201fbc bl 0x20170c <_ZN7CStream8CopyFromEPS_x>
 *   @0x201fc0 mov r0, r4
 *   @0x201fc4 bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x201fc8 sub r3, r6, #1
 *   @0x201fcc cmp r3, #0
 *   @0x201fd0 ble 0x202078 <_ZN7CStream19ReadEncryptedStreamEv+0x190>
 *   @0x201fd4 add r6, r0, r6
 *   @0x201fd8 mov r1, r3
 *   @0x201fdc mov r2, r6
 *   @0x201fe0 ldrb lr, [r2, #-0x1]
 *   @0x201fe4 add r7, sp, #520
 *   @0x201fe8 ldrb r12, [r2, #-0x2]
 *   @0x201fec add lr, r7, lr
 *   @0x201ff0 ldrb lr, [lr, #-0x104]
 *   @0x201ff4 rsb lr, r12, lr
 *   @0x201ff8 rsb lr, r1, lr
 *   @0x201ffc asr r12, lr, #31
 *   @0x202000 lsr r12, r12, #24
 *   @0x202004 add lr, lr, r12
 *   @0x202008 uxtb lr, lr
 *   @0x20200c subs r12, lr, r12
 *   @0x202010 addmi r12, r12, #256
 *   @0x202014 subs r1, r1, #1
 *   @0x202018 strb r12, [r2, #-0x1]!
 *   @0x20201c bne 0x201fe0 <_ZN7CStream19ReadEncryptedStreamEv+0xf8>
 *   @0x202020 mov r1, r6
 *   @0x202024 add r12, sp, #520
 *   @0x202028 uxtab r2, r12, r3
 *   @0x20202c ldrb r12, [r1, #-0x1]
 *   @0x202030 ldrb r2, [r2, #-0x204]
 *   @0x202034 rsb r2, r2, r3
 *   @0x202038 subs r3, r3, #1
 *   @0x20203c bic r2, r2, r2, asr #31
 *   @0x202040 ldrb lr, [r0, r2]
 *   @0x202044 strb lr, [r1, #-0x1]!
 *   @0x202048 strb r12, [r0, r2]
 *   @0x20204c bpl 0x202024 <_ZN7CStream19ReadEncryptedStreamEv+0x13c>
 *   @0x202050 mov r0, r4
 *   @0x202054 mov r1, #0
 *   @0x202058 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x20205c ldr r2, [sp, #0x204]
 *   @0x202060 ldr r3, [r5]
 *   @0x202064 mov r0, r4
 *   @0x202068 cmp r2, r3
 *   @0x20206c bne 0x202084 <_ZN7CStream19ReadEncryptedStreamEv+0x19c>
 *   @0x202070 add sp, sp, #520
 *   @0x202074 pop {r4, r5, r6, r7, r8, pc}
 *   @0x202078 addeq r6, r0, r6
 *   @0x20207c bne 0x202050 <_ZN7CStream19ReadEncryptedStreamEv+0x168>
 *   @0x202080 b 0x202020 <_ZN7CStream19ReadEncryptedStreamEv+0x138>
 *   @0x202084 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x202088 andseq r11, lr, r8, asr r10
 *
 * ══ §67/70 CDS_List::Clear()  0x20e478  size 420  105 条（0x20e478..0x20e61c）
 * @func 0x20e478 0x20e61c  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x20e4f8→0x4836b8, 0x20e50c→0x4836bc, 0x20e5b8→0x4836ac, 0x20e5cc→0x4836b0
 * 调用序列: DS_AutoMutex::DS_AutoMutex() / CDS_List::Clear()+0x128 / CDS_List::Clear()+0x100 / CDS_List::Clear()+0x108 / FREE_RValue__Pre(RValue*) / DS_AutoMutex::~DS_AutoMutex() / CDS_Map::~CDS_Map() / operator delete(void*)
 * 字段偏移 top8: 0x4×10 / 0xc×8 / 0x2×3 / 0x8×3 / 0x178×1 / 0x10c×1 / 0xfc×1 / 0x54×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20e478 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20e47c sub sp, sp, #28
 *   @0x20e480 add r7, sp, #20
 *   @0x20e484 mov r10, r0
 *   @0x20e488 ldr r6, [pc, #0x178]
 *   @0x20e48c mov r0, r7
 *   @0x20e490 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x20e494 ldr r3, [r10, #0x4]
 *   @0x20e498 add r6, pc, r6
 *   @0x20e49c cmp r3, #0
 *   @0x20e4a0 movgt r5, #0
 *   @0x20e4a4 movgt r11, #5
 *   @0x20e4a8 movgt r9, r5
 *   @0x20e4ac ble 0x20e5a0 <_ZN8CDS_List5ClearEv+0x128>
 *   @0x20e4b0 ldr r0, [r10, #0xc]
 *   @0x20e4b4 lsl r1, r5, #4
 *   @0x20e4b8 add r4, r0, r1
 *   @0x20e4bc ldr r3, [r4, #0xc]
 *   @0x20e4c0 uxth r8, r3
 *   @0x20e4c4 cmp r8, #0
 *   @0x20e4c8 bne 0x20e554 <_ZN8CDS_List5ClearEv+0xdc>
 *   @0x20e4cc tst r3, #-1073741824
 *   @0x20e4d0 beq 0x20e580 <_ZN8CDS_List5ClearEv+0x108>
 *   @0x20e4d4 ldr r2, [r0, r1]
 *   @0x20e4d8 cmp r3, #0
 *   @0x20e4dc ldr r3, [r4, #0x4]
 *   @0x20e4e0 vmov d7, r2, r3
 *   @0x20e4e4 vcvt.s32.f64 s15, d7
 *   @0x20e4e8 vmov r2, s15
 *   @0x20e4ec blt 0x20e578 <_ZN8CDS_List5ClearEv+0x100>
 *   @0x20e4f0 cmp r2, #0
 *   @0x20e4f4 blt 0x20e580 <_ZN8CDS_List5ClearEv+0x108>
 *   @0x20e4f8 ldr r3, [pc, #0x10c]
 *   @0x20e4fc ldr r3, [r6, r3]
 *   @0x20e500 ldr r3, [r3]
 *   @0x20e504 cmp r2, r3
 *   @0x20e508 bge 0x20e580 <_ZN8CDS_List5ClearEv+0x108>
 *   @0x20e50c ldr r3, [pc, #0xfc]
 *   @0x20e510 ldr r3, [r6, r3]
 *   @0x20e514 ldr r0, [r3, #0x4]
 *   @0x20e518 ldr r0, [r0, r2, lsl #2]
 *   @0x20e51c cmp r0, #0
 *   @0x20e520 beq 0x20e580 <_ZN8CDS_List5ClearEv+0x108>
 *   @0x20e524 ldr r12, [r0]
 *   @0x20e528 ldr r12, [r12, #0x4]
 *   @0x20e52c stm sp, {r1, r2, r3}
 *   @0x20e530 blx r12
 *   @0x20e534 ldr r3, [sp, #0x8]
 *   @0x20e538 ldr r3, [r3, #0x4]
 *   @0x20e53c ldr r2, [sp, #0x4]
 *   @0x20e540 ldr r1, [sp]
 *   @0x20e544 str r8, [r3, r2, lsl #2]
 *   @0x20e548 ldr r4, [r10, #0xc]
 *   @0x20e54c add r4, r4, r1
 *   @0x20e550 ldrh r8, [r4, #12]
 *   @0x20e554 sub r3, r8, #1
 *   @0x20e558 str r8, [r4, #0xc]
 *   @0x20e55c bic r3, r3, #-16777216
 *   @0x20e560 bic r3, r3, #3
 *   @0x20e564 cmp r3, #0
 *   @0x20e568 bne 0x20e584 <_ZN8CDS_List5ClearEv+0x10c>
 *   @0x20e56c mov r0, r4
 *   @0x20e570 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20e574 b 0x20e584 <_ZN8CDS_List5ClearEv+0x10c>
 *   @0x20e578 cmp r2, #0
 *   @0x20e57c bge 0x20e5b8 <_ZN8CDS_List5ClearEv+0x140>
 *   @0x20e580 str r9, [r4, #0xc]
 *   @0x20e584 str r9, [r4]
 *   @0x20e588 add r5, r5, #1
 *   @0x20e58c ldr r3, [r10, #0x4]
 *   @0x20e590 str r9, [r4, #0x8]
 *   @0x20e594 cmp r3, r5
 *   @0x20e598 str r11, [r4, #0xc]
 *   @0x20e59c bgt 0x20e4b0 <_ZN8CDS_List5ClearEv+0x38>
 *   @0x20e5a0 mov r3, #0
 *   @0x20e5a4 mov r0, r7
 *   @0x20e5a8 str r3, [r10, #0x4]
 *   @0x20e5ac bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x20e5b0 add sp, sp, #28
 *   @0x20e5b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20e5b8 ldr r3, [pc, #0x54]
 *   @0x20e5bc ldr r3, [r6, r3]
 *   @0x20e5c0 ldr r3, [r3]
 *   @0x20e5c4 cmp r2, r3
 *   @0x20e5c8 bge 0x20e580 <_ZN8CDS_List5ClearEv+0x108>
 *   @0x20e5cc ldr r3, [pc, #0x44]
 *   @0x20e5d0 ldr r12, [r6, r3]
 *   @0x20e5d4 ldr r3, [r12, #0x4]
 *   @0x20e5d8 ldr r3, [r3, r2, lsl #2]
 *   @0x20e5dc cmp r3, #0
 *   @0x20e5e0 beq 0x20e580 <_ZN8CDS_List5ClearEv+0x108>
 *   @0x20e5e4 mov r0, r3
 *   @0x20e5e8 stm sp, {r1, r2, r3, r12}
 *   @0x20e5ec bl 0x20d9e8 <_ZN7CDS_MapD2Ev>
 *   @0x20e5f0 ldr r3, [sp, #0x8]
 *   @0x20e5f4 mov r0, r3
 *   @0x20e5f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x20e5fc ldr r12, [sp, #0xc]
 *   @0x20e600 ldr r3, [r12, #0x4]
 *   @0x20e604 b 0x20e53c <_ZN8CDS_List5ClearEv+0xc4>
 *   @0x20e608 ldrheq r3, [lr], -r8
 *   @0x20e60c .word 0xffffc02c
 *   @0x20e610 .word 0xffffc030
 *   @0x20e614 .word 0xffffc028
 *   @0x20e618 .word 0xffffbcec
 *
 * ══ §68/70 _spTransformConstraintTimeline_apply  0x282548  size 420  105 条（0x282548..0x2826ec）
 * @func 0x282548 0x2826ec  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spTransformConstraintTimeline_apply+0xa8 / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x2c×1 / 0x14×1 / 0x2×1
 * VFP 指令 73 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282548 push {r3, r4, r5, r6, r7, lr}
 *   @0x28254c vpush {d8}
 *   @0x282550 vmov s17, r3
 *   @0x282554 vldr s16, [sp, #40]
 *   @0x282558 ldr r6, [r0, #0x10]
 *   @0x28255c vldr s15, [r6]
 *   @0x282560 vcmpe.f32 s15, s17
 *   @0x282564 mov r5, r0
 *   @0x282568 vmrs APSR_nzcv, fpscr
 *   @0x28256c bgt 0x2825e8 <_spTransformConstraintTimeline_apply+0xa0>
 *   @0x282570 ldr r2, [r0, #0xc]
 *   @0x282574 ldr r1, [r1, #0x2c]
 *   @0x282578 sub r3, r2, #5
 *   @0x28257c ldr r0, [r0, #0x14]
 *   @0x282580 add r3, r6, r3, lsl #2
 *   @0x282584 vldr s15, [r3]
 *   @0x282588 vcmpe.f32 s17, s15
 *   @0x28258c ldr r4, [r1, r0, lsl #2]
 *   @0x282590 vmrs APSR_nzcv, fpscr
 *   @0x282594 blt 0x2825f0 <_spTransformConstraintTimeline_apply+0xa8>
 *   @0x282598 vldr s11, [r3, #4]
 *   @0x28259c vldr s12, [r4, #16]
 *   @0x2825a0 vsub.f32 s11, s11, s12
 *   @0x2825a4 vldr s13, [r4, #20]
 *   @0x2825a8 vldr s14, [r4, #24]
 *   @0x2825ac vldr s15, [r4, #28]
 *   @0x2825b0 vmla.f32 s12, s11, s16
 *   @0x2825b4 vstr s12, [r4, #16]
 *   @0x2825b8 vldr s12, [r3, #8]
 *   @0x2825bc vsub.f32 s12, s12, s13
 *   @0x2825c0 vmla.f32 s13, s12, s16
 *   @0x2825c4 vstr s13, [r4, #20]
 *   @0x2825c8 vldr s13, [r3, #12]
 *   @0x2825cc vsub.f32 s13, s13, s14
 *   @0x2825d0 vmla.f32 s14, s13, s16
 *   @0x2825d4 vstr s14, [r4, #24]
 *   @0x2825d8 vldr s14, [r3, #16]
 *   @0x2825dc vsub.f32 s14, s14, s15
 *   @0x2825e0 vmla.f32 s15, s14, s16
 *   @0x2825e4 vstr s15, [r4, #28]
 *   @0x2825e8 vpop {d8}
 *   @0x2825ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x2825f0 mov r1, r2
 *   @0x2825f4 vmov.f32 s0, s17
 *   @0x2825f8 mov r0, r6
 *   @0x2825fc mov r2, #5
 *   @0x282600 bl 0x280ed0 <printbuf_free+0x20>
 *   @0x282604 vmov.f32 s14, #1.000000e+00
 *   @0x282608 lsl r3, r0, #2
 *   @0x28260c mov r2, r0
 *   @0x282610 sub r7, r3, #20
 *   @0x282614 add r3, r6, r3
 *   @0x282618 add r6, r6, r7
 *   @0x28261c vldr s15, [r3]
 *   @0x282620 vldr s13, [r6]
 *   @0x282624 vsub.f32 s13, s13, s15
 *   @0x282628 movw r3, #0x6667
 *   @0x28262c movt r3, #0x6666
 *   @0x282630 mvn r1, r0
 *   @0x282634 mov r0, r5
 *   @0x282638 smull r12, r2, r3, r2
 *   @0x28263c lsr r1, r1, #31
 *   @0x282640 vsub.f32 s15, s17, s15
 *   @0x282644 rsb r1, r1, r2, asr #1
 *   @0x282648 vdiv.f32 s15, s15, s13
 *   @0x28264c vsub.f32 s14, s14, s15
 *   @0x282650 vmov r2, s14
 *   @0x282654 bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x282658 ldr r3, [r5, #0x10]
 *   @0x28265c vldr s8, [r4, #16]
 *   @0x282660 vldr s10, [r4, #20]
 *   @0x282664 add r3, r3, r7
 *   @0x282668 vldr s7, [r3, #4]
 *   @0x28266c vldr s6, [r3, #24]
 *   @0x282670 vsub.f32 s6, s6, s7
 *   @0x282674 vldr s9, [r3, #8]
 *   @0x282678 vldr s11, [r3, #12]
 *   @0x28267c vldr s13, [r3, #16]
 *   @0x282680 vldr s12, [r4, #24]
 *   @0x282684 vldr s14, [r4, #28]
 *   @0x282688 vmov s15, r0
 *   @0x28268c vmla.f32 s7, s6, s15
 *   @0x282690 vsub.f32 s7, s7, s8
 *   @0x282694 vmla.f32 s8, s7, s16
 *   @0x282698 vstr s8, [r4, #16]
 *   @0x28269c vldr s8, [r3, #28]
 *   @0x2826a0 vsub.f32 s8, s8, s9
 *   @0x2826a4 vmla.f32 s9, s8, s15
 *   @0x2826a8 vsub.f32 s9, s9, s10
 *   @0x2826ac vmla.f32 s10, s9, s16
 *   @0x2826b0 vstr s10, [r4, #20]
 *   @0x2826b4 vldr s10, [r3, #32]
 *   @0x2826b8 vsub.f32 s10, s10, s11
 *   @0x2826bc vmla.f32 s11, s10, s15
 *   @0x2826c0 vsub.f32 s11, s11, s12
 *   @0x2826c4 vmla.f32 s12, s11, s16
 *   @0x2826c8 vstr s12, [r4, #24]
 *   @0x2826cc vldr s12, [r3, #36]
 *   @0x2826d0 vsub.f32 s12, s12, s13
 *   @0x2826d4 vmla.f32 s13, s12, s15
 *   @0x2826d8 vsub.f32 s13, s13, s14
 *   @0x2826dc vmla.f32 s14, s13, s16
 *   @0x2826e0 vpop {d8}
 *   @0x2826e4 vstr s14, [r4, #28]
 *   @0x2826e8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §69/70 png_do_expand_palette  0x2aa398  size 420  105 条（0x2aa398..0x2aa53c）
 * @func 0x2aa398 0x2aa53c  size 420  105 条
 * 部分覆盖: 本节 105/193 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e9c78+0x1bac / 0x14f8030 / anon_2e9c78+0x1bdc / 0x14f8068
 * 字段偏移 top8: 0x9×3 / 0x4×3 / 0x8×2 / 0x12×2 / 0x3×2 / 0x20×1 / 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aa398 push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2aa39c ldrb r5, [r0, #0x8]
 *   @0x2aa3a0 cmp r5, #0x3
 *   @0x2aa3a4 .word 0xf89080c9
 *   @0x2aa3a8 .word 0xf1bcc009
 *   @0x2aa3ac stmdale r9!, {r0, r1, r2, r8, r9, r10, r11} ^
 *   @0x2aa3b0 cmp.w r12, #0x2
 *   @0x2aa3b4 beq 0x2aa408 <png_do_expand_palette+0x70>
 *   @0x2aa3b8 suble r0, r3, r4, lsl #30
 *   @0x2aa3bc cmp.w r12, #0x1
 *   @0x2aa3c0 bne 0x2aa47c <png_do_expand_palette+0xe4>
 *   @0x2aa3c4 stclne p9, c3, [r7, #1020]!
 *   @0x2aa3c8 mvn.w r10, r4
 *   @0x2aa3cc add.w r6, r1, r9, lsr #3
 *   @0x2aa3d0 add r9, r1
 *   @0x2aa3d4 add.w r5, r9, #0xffffffff
 *   @0x2aa3d8 and r7, r7, #0x7
 *   @0x2aa3dc add r10, r9
 *   @0x2aa3e0 beq 0x2aa47c <png_do_expand_palette+0xe4>
 *   @0x2aa3e4 stclo p0, c9, [r1, #-0]
 *   @0x2aa3e8 asr.w r9, r9, r7
 *   @0x2aa3ec ands r9, r9, #0x1
 *   @0x2aa3f0 ite ne
 *   @0x2aa3f4 .word 0xf885c002
 *   @0x2aa3f8 svchs #0x79002
 *   @0x2aa3fc itet eq
 *   @0x2aa400 .word 0x370136ff
 *   @0x2aa404 moveq r7, #0x0
 *   @0x2aa408 adds r5, r4, #0x3
 *   @0x2aa40c mvns r5, r5
 *   @0x2aa410 bl 0x2eb824 <FT_Done_Memory+0x1bb0>
 *   @0x2aa414 strmi r0, [pc], #-1687
 *   @0x2aa418 lsls r5, r5, #0x1
 *   @0x2aa41c strbmi r0, [r7, #-0x807]
 *   @0x2aa420 beq 0x2aa47c <png_do_expand_palette+0xe4>
 *   @0x2aa424 stchs p0, c9, [r6, #-0]
 *   @0x2aa428 it eq
 *   @0x2aa42c blx 0x14f8030 <b2_toiTime+0xd9eb8c>
 *   @0x2aa430 svclt #0x8f905
 *   @0x2aa434 moveq r5, #0x0
 *   @0x2aa438 svclt #0x180903
 *   @0x2aa43c addne r5, #0x2
 *   @0x2aa440 strb r9, [r12, r1, lsl #18]!
 *   @0x2aa444 subs r7, r4, #0x1
 *   @0x2aa448 bl 0x2eb854 <FT_Done_Memory+0x1be0>
 *   @0x2aa44c strmi r0, [pc], #-1623
 *   @0x2aa450 lsls r5, r5, #0x2
 *   @0x2aa454 strbmi r0, [r7, #-0x807]
 *   @0x2aa458 beq 0x2aa47c <png_do_expand_palette+0xe4>
 *   @0x2aa45c stchs p0, c9, [r4, #-0]
 *   @0x2aa460 it eq
 *   @0x2aa464 blx 0x14f8068 <b2_toiTime+0xd9ebc4>
 *   @0x2aa468 svclt #0x8f905
 *   @0x2aa46c moveq r5, #0x0
 *   @0x2aa470 svclt #0x18090f
 *   @0x2aa474 addne r5, #0x4
 *   @0x2aa478 strb r9, [r12, r1, lsl #18]!
 *   @0x2aa47c movs r5, #0x8
 *   @0x2aa480 strb r5, [r0, #0x9]
 *   @0x2aa484 ldrb r5, [r0, #0x9]
 *   @0x2aa488 bne 0x2aa538 <png_do_expand_palette+0x1a0>
 *   @0x2aa48c cbz r3, 0x2aa4ec <png_do_expand_palette+0x154>
 *   @0x2aa490 mov.w r8, #0xff
 *   @0x2aa494 adds r5, r1, r6
 *   @0x2aa498 subs r5, #0x2
 *   @0x2aa49c strbmi r0, [r1, #-0xc01]!
 *   @0x2aa4a0 beq 0x2aa4da <png_do_expand_palette+0x142>
 *   @0x2aa4a4 stclo p9, c7, [r4, #-4]
 *   @0x2aa4a8 ldr r4, [sp, #0x20]
 *   @0x2aa4ac itee ge
 *   @0x2aa4b0 ldclpl p0, c8, [pc, #20]
 *   @0x2aa4b4 strblt r7, [r5, #0x5]
 *   @0x2aa4b8 add.w r7, r7, r7, lsl #1
 *   @0x2aa4bc add r7, r2
 *   @0x2aa4c0 strb r7, [r5, #0x4]
 *   @0x2aa4c4 add.w r7, r7, r7, lsl #1
 *   @0x2aa4c8 add r7, r2
 *   @0x2aa4cc strb r7, [r5, #0x3]
 *   @0x2aa4d0 add.w r7, r7, r7, lsl #1
 *   @0x2aa4d4 ldrb r7, [r2, r7]
 *   @0x2aa4d8 b 0x2aa49e <png_do_expand_palette+0x106>
 *   @0x2aa4dc str r6, [r0, #0x4]
 *   @0x2aa4e0 movs r3, #0x20
 *   @0x2aa4e4 movs r3, #0x6
 *   @0x2aa4e8 movs r3, #0x4
 *   @0x2aa4ec movs r5, #0x3
 *   @0x2aa4f0 muls r5, r4, r5
 *   @0x2aa4f4 add r4, r3
 *   @0x2aa4f8 add r1, r6
 *   @0x2aa4fc cmp r3, r4
 *   @0x2aa500 ldrb r6, [r3, #0x1]
 *   @0x2aa504 add.w r6, r6, r6, lsl #1
 *   @0x2aa508 add r6, r2
 *   @0x2aa50c strb r6, [r1, #0x3]
 *   @0x2aa510 add.w r6, r6, r6, lsl #1
 *   @0x2aa514 add r6, r2
 *   @0x2aa518 strb r6, [r1, #0x2]
 *   @0x2aa51c add.w r6, r6, r6, lsl #1
 *   @0x2aa520 ldrb r6, [r2, r6]
 *   @0x2aa524 b 0x2aa4fa <png_do_expand_palette+0x162>
 *   @0x2aa528 strb r3, [r0, #0x9]
 *   @0x2aa52c strb r3, [r0, #0xb]
 *   @0x2aa530 strb r3, [r0, #0x8]
 *   @0x2aa534 str r5, [r0, #0x4]
 *   @0x2aa538 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §70/70 VM::PokeDSQueue(int, int, RValue&)  0xe4f18  size 412  103 条（0xe4f18..0xe50b4）
 * @func 0xe4f18 0xe50c4  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetTheQueues(int&) / VM::PokeDSQueue(int, int, RValue&)+0xf4 / FREE_RValue__Pre(RValue*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×8 / 0x8×5 / 0xc×5 / 0x2×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe4f18 push {r4, r5, r6, r7, r8, lr}
 *   @0xe4f1c sub sp, sp, #8
 *   @0xe4f20 mov r4, r0
 *   @0xe4f24 add r0, sp, #4
 *   @0xe4f28 mov r6, r1
 *   @0xe4f2c mov r5, r2
 *   @0xe4f30 bl 0xffee8 <_Z12GetTheQueuesRi>
 *   @0xe4f34 cmp r4, #0
 *   @0xe4f38 blt 0xe500c <_ZN2VM11PokeDSQueueEiiR6RValue+0xf4>
 *   @0xe4f3c ldr r3, [sp, #0x4]
 *   @0xe4f40 cmp r4, r3
 *   @0xe4f44 bge 0xe500c <_ZN2VM11PokeDSQueueEiiR6RValue+0xf4>
 *   @0xe4f48 ldr r3, [r0, r4, lsl #2]
 *   @0xe4f4c ldr r2, [r3, #0x8]
 *   @0xe4f50 ldr r4, [r3, #0x4]
 *   @0xe4f54 rsb r4, r2, r4
 *   @0xe4f58 cmp r6, r4
 *   @0xe4f5c movgt r4, #0
 *   @0xe4f60 movle r4, #1
 *   @0xe4f64 cmp r6, #0
 *   @0xe4f68 movlt r4, #0
 *   @0xe4f6c cmp r4, #0
 *   @0xe4f70 beq 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe4f74 ldr r8, [r3, #0x10]
 *   @0xe4f78 add r6, r2, r6
 *   @0xe4f7c add r7, r8, r6, lsl #4
 *   @0xe4f80 ldr r3, [r7, #0xc]
 *   @0xe4f84 sub r3, r3, #1
 *   @0xe4f88 bic r3, r3, #-16777216
 *   @0xe4f8c bic r3, r3, #3
 *   @0xe4f90 cmp r3, #0
 *   @0xe4f94 beq 0xe5040 <_ZN2VM11PokeDSQueueEiiR6RValue+0x128>
 *   @0xe4f98 mov r3, #5
 *   @0xe4f9c str r3, [r7, #0xc]
 *   @0xe4fa0 ldr r1, [r5, #0xc]
 *   @0xe4fa4 mov r3, #0
 *   @0xe4fa8 str r3, [r7, #0x8]
 *   @0xe4fac str r3, [r8, r6, lsl #4]
 *   @0xe4fb0 ldr r2, [r5, #0x8]
 *   @0xe4fb4 str r1, [r7, #0xc]
 *   @0xe4fb8 ldr r3, [r5, #0xc]
 *   @0xe4fbc str r2, [r7, #0x8]
 *   @0xe4fc0 bic r3, r3, #-16777216
 *   @0xe4fc4 cmp r3, #14
 *   @0xe4fc8 addls pc, pc, r3, lsl #2
 *   @0xe4fcc b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe4fd0 b 0xe5030 <_ZN2VM11PokeDSQueueEiiR6RValue+0x118>
 *   @0xe4fd4 b 0xe5070 <_ZN2VM11PokeDSQueueEiiR6RValue+0x158>
 *   @0xe4fd8 b 0xe5088 <_ZN2VM11PokeDSQueueEiiR6RValue+0x170>
 *   @0xe4fdc b 0xe501c <_ZN2VM11PokeDSQueueEiiR6RValue+0x104>
 *   @0xe4fe0 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe4fe4 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe4fe8 b 0xe504c <_ZN2VM11PokeDSQueueEiiR6RValue+0x134>
 *   @0xe4fec b 0xe501c <_ZN2VM11PokeDSQueueEiiR6RValue+0x104>
 *   @0xe4ff0 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe4ff4 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe4ff8 b 0xe5030 <_ZN2VM11PokeDSQueueEiiR6RValue+0x118>
 *   @0xe4ffc b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe5000 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe5004 b 0xe5030 <_ZN2VM11PokeDSQueueEiiR6RValue+0x118>
 *   @0xe5008 b 0xe501c <_ZN2VM11PokeDSQueueEiiR6RValue+0x104>
 *   @0xe500c mov r4, #0
 *   @0xe5010 mov r0, r4
 *   @0xe5014 add sp, sp, #8
 *   @0xe5018 pop {r4, r5, r6, r7, r8, pc}
 *   @0xe501c ldr r3, [r5]
 *   @0xe5020 mov r0, r4
 *   @0xe5024 str r3, [r8, r6, lsl #4]
 *   @0xe5028 add sp, sp, #8
 *   @0xe502c pop {r4, r5, r6, r7, r8, pc}
 *   @0xe5030 ldm r5, {r2, r3}
 *   @0xe5034 str r2, [r8, r6, lsl #4]
 *   @0xe5038 str r3, [r7, #0x4]
 *   @0xe503c b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe5040 mov r0, r7
 *   @0xe5044 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe5048 b 0xe4f98 <_ZN2VM11PokeDSQueueEiiR6RValue+0x80>
 *   @0xe504c ldr r3, [r5]
 *   @0xe5050 str r3, [r8, r6, lsl #4]
 *   @0xe5054 ldr r3, [r5]
 *   @0xe5058 cmp r3, #0
 *   @0xe505c beq 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe5060 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xe5064 ldr r1, [r5]
 *   @0xe5068 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xe506c b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe5070 ldr r3, [r5]
 *   @0xe5074 cmp r3, #0
 *   @0xe5078 ldrne r2, [r3, #0x4]
 *   @0xe507c addne r2, r2, #1
 *   @0xe5080 strne r2, [r3, #0x4]
 *   @0xe5084 b 0xe5020 <_ZN2VM11PokeDSQueueEiiR6RValue+0x108>
 *   @0xe5088 ldr r3, [r5]
 *   @0xe508c cmp r3, #0
 *   @0xe5090 str r3, [r8, r6, lsl #4]
 *   @0xe5094 beq 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 *   @0xe5098 ldr r1, [r3, #0x8]
 *   @0xe509c ldr r2, [r3]
 *   @0xe50a0 cmp r1, #0
 *   @0xe50a4 streq r7, [r3, #0x8]
 *   @0xe50a8 add r2, r2, #1
 *   @0xe50ac str r2, [r3]
 *   @0xe50b0 b 0xe5010 <_ZN2VM11PokeDSQueueEiiR6RValue+0xf8>
 */
