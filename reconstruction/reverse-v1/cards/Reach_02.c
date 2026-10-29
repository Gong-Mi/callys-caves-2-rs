/* cally 逆向卡：Reach_02 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 13 个函数｜锚点 6999 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/13 b2World::SolveTOI  0x2c9ab4  size 2980  745 条（0x2c9ab4..0x2ca658）
 * @func 0x2c9ab4 0x2ca658  size 2980  745 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×6 / 0xb658c×6 / b2DistanceProxy::Set(b2Shape const*, int)×2 / b2Contact::Update(b2ContactListener*)×2 / b2Island::b2Island(int, int, int, b2StackAllocator*, b2ContactListener*) / b2TimeOfImpact(b2TOIOutput*, b2TOIInput const*) / b2Island::SolveTOI(b2TimeStep const&, int, int) / b2World::SolveTOI(b2TimeStep const&)+0x7a0
 * 字段偏移 top8: 0x4×35 / 0x10×11 / 0xc×11 / 0x8×11 / 0x18×8 / 0x9c×7 / 0x2c×6 / 0x80×6
 * VFP 指令 241 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c9ab4 movw r3, #0x9220
 *   @0x2c9ab8 movt r3, #0x1
 *   @0x2c9abc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c9ac0 vpush {d8, d9, d10}
 *   @0x2c9ac4 sub sp, sp, #316
 *   @0x2c9ac8 ldr r3, [r0, r3]
 *   @0x2c9acc add r2, sp, #128
 *   @0x2c9ad0 str r0, [sp, #0x10]
 *   @0x2c9ad4 str r2, [sp, #0x24]
 *   @0x2c9ad8 add r2, r0, #68
 *   @0x2c9adc str r1, [sp, #0x20]
 *   @0x2c9ae0 add r0, sp, #128
 *   @0x2c9ae4 str r2, [sp]
 *   @0x2c9ae8 mov r1, #64
 *   @0x2c9aec str r3, [sp, #0x4]
 *   @0x2c9af0 mov r2, #32
 *   @0x2c9af4 mov r3, #0
 *   @0x2c9af8 bl 0x2e1130 <_ZN8b2IslandC2EiiiP16b2StackAllocatorP17b2ContactListener>
 *   @0x2c9afc ldr lr, [sp, #0x10]
 *   @0x2c9b00 movw r3, #0x9253
 *   @0x2c9b04 movt r3, #0x1
 *   @0x2c9b08 ldrb r3, [lr, r3]
 *   @0x2c9b0c cmp r3, #0
 *   @0x2c9b10 bne 0x2ca4f0 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa3c>
 *   @0x2c9b14 movw r3, #0x9214
 *   @0x2c9b18 movt r3, #0x1
 *   @0x2c9b1c ldr r4, [lr, r3]
 *   @0x2c9b20 ldr lr, [sp, #0x10]
 *   @0x2c9b24 cmp r4, #0
 *   @0x2c9b28 movw r1, #0x9220
 *   @0x2c9b2c movw r2, #0x9252
 *   @0x2c9b30 add r3, lr, #102400
 *   @0x2c9b34 movt r1, #0x1
 *   @0x2c9b38 add r3, r3, #472
 *   @0x2c9b3c movt r2, #0x1
 *   @0x2c9b40 str r3, [sp, #0x2c]
 *   @0x2c9b44 vldr s19, [pc, #448]
 *   @0x2c9b48 str r1, [sp, #0x1c]
 *   @0x2c9b4c vldr s20, [pc, #444]
 *   @0x2c9b50 str r2, [sp, #0x28]
 *   @0x2c9b54 beq 0x2ca288 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7d4>
 *   @0x2c9b58 mov r8, #0
 *   @0x2c9b5c vmov.f32 s16, #1.000000e+00
 *   @0x2c9b60 add r10, sp, #180
 *   @0x2c9b64 add r11, sp, #208
 *   @0x2c9b68 mov r9, r8
 *   @0x2c9b6c b 0x2c9b90 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xdc>
 *   @0x2c9b70 vldr s15, [r4, #132]
 *   @0x2c9b74 vcmpe.f32 s15, s16
 *   @0x2c9b78 vmrs APSR_nzcv, fpscr
 *   @0x2c9b7c vmovmi.f32 s16, s15
 *   @0x2c9b80 movmi r8, r4
 *   @0x2c9b84 ldr r4, [r4, #0xc]
 *   @0x2c9b88 cmp r4, #0
 *   @0x2c9b8c beq 0x2c9d14 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x260>
 *   @0x2c9b90 ldr r3, [r4, #0x4]
 *   @0x2c9b94 tst r3, #4
 *   @0x2c9b98 beq 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0>
 *   @0x2c9b9c ldr r2, [r4, #0x80]
 *   @0x2c9ba0 cmp r2, #8
 *   @0x2c9ba4 bgt 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0>
 *   @0x2c9ba8 tst r3, #32
 *   @0x2c9bac bne 0x2c9b70 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xbc>
 *   @0x2c9bb0 ldr r3, [r4, #0x30]
 *   @0x2c9bb4 ldr r5, [r4, #0x34]
 *   @0x2c9bb8 ldrb r2, [r3, #0x2c]
 *   @0x2c9bbc cmp r2, #0
 *   @0x2c9bc0 bne 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0>
 *   @0x2c9bc4 ldrb r2, [r5, #0x2c]
 *   @0x2c9bc8 cmp r2, #0
 *   @0x2c9bcc bne 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0>
 *   @0x2c9bd0 ldr r6, [r3, #0x8]
 *   @0x2c9bd4 ldr r7, [r5, #0x8]
 *   @0x2c9bd8 ldrh r1, [r6, #4]
 *   @0x2c9bdc ldr r12, [r6]
 *   @0x2c9be0 and r0, r1, #2
 *   @0x2c9be4 ldr lr, [r7]
 *   @0x2c9be8 uxth r0, r0
 *   @0x2c9bec cmp r0, #0
 *   @0x2c9bf0 beq 0x2c9bfc <_ZN7b2World8SolveTOIERK10b2TimeStep+0x148>
 *   @0x2c9bf4 adds r0, r12, #0
 *   @0x2c9bf8 movne r0, #1
 *   @0x2c9bfc ldrh r2, [r7, #4]
 *   @0x2c9c00 tst r2, #2
 *   @0x2c9c04 beq 0x2ca390 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x8dc>
 *   @0x2c9c08 cmp lr, #0
 *   @0x2c9c0c beq 0x2ca390 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x8dc>
 *   @0x2c9c10 tst r1, #8
 *   @0x2c9c14 movne r12, #1
 *   @0x2c9c18 bne 0x2c9c24 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x170>
 *   @0x2c9c1c subs r12, r12, #2
 *   @0x2c9c20 movne r12, #1
 *   @0x2c9c24 tst r2, #8
 *   @0x2c9c28 bne 0x2c9c34 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x180>
 *   @0x2c9c2c cmp lr, #2
 *   @0x2c9c30 beq 0x2ca5dc <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb28>
 *   @0x2c9c34 vldr s17, [r6, #76]
 *   @0x2c9c38 vldr s15, [r7, #76]
 *   @0x2c9c3c vcmpe.f32 s17, s15
 *   @0x2c9c40 vmrs APSR_nzcv, fpscr
 *   @0x2c9c44 bmi 0x2ca570 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xabc>
 *   @0x2c9c48 bgt 0x2ca604 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb50>
 *   @0x2c9c4c ldr r12, [r4, #0x3c]
 *   @0x2c9c50 mov r0, r10
 *   @0x2c9c54 ldr r2, [r4, #0x38]
 *   @0x2c9c58 vstr s19, [sp, #204]
 *   @0x2c9c5c str r9, [sp, #0xc4]
 *   @0x2c9c60 vstr s19, [sp, #232]
 *   @0x2c9c64 str r9, [sp, #0xc8]
 *   @0x2c9c68 add r6, r6, #44
 *   @0x2c9c6c str r9, [sp, #0xe0]
 *   @0x2c9c70 vmov.f32 s18, #1.000000e+00
 *   @0x2c9c74 str r9, [sp, #0xe4]
 *   @0x2c9c78 ldr r1, [r3, #0xc]
 *   @0x2c9c7c str r12, [sp, #0x8]
 *   @0x2c9c80 bl 0x2c3b74 <_ZN15b2DistanceProxy3SetEPK7b2Shapei>
 *   @0x2c9c84 ldr r12, [sp, #0x8]
 *   @0x2c9c88 mov r0, r11
 *   @0x2c9c8c ldr r1, [r5, #0xc]
 *   @0x2c9c90 add r5, sp, #236
 *   @0x2c9c94 mov r2, r12
 *   @0x2c9c98 bl 0x2c3b74 <_ZN15b2DistanceProxy3SetEPK7b2Shapei>
 *   @0x2c9c9c ldm r6!, {r0, r1, r2, r3}
 *   @0x2c9ca0 add lr, r7, #44
 *   @0x2c9ca4 add r12, sp, #272
 *   @0x2c9ca8 stm r5!, {r0, r1, r2, r3}
 *   @0x2c9cac ldm r6!, {r0, r1, r2, r3}
 *   @0x2c9cb0 stm r5!, {r0, r1, r2, r3}
 *   @0x2c9cb4 ldr r3, [r6]
 *   @0x2c9cb8 str r3, [r5]
 *   @0x2c9cbc ldm lr!, {r0, r1, r2, r3}
 *   @0x2c9cc0 stm r12!, {r0, r1, r2, r3}
 *   @0x2c9cc4 ldm lr!, {r0, r1, r2, r3}
 *   @0x2c9cc8 stm r12!, {r0, r1, r2, r3}
 *   @0x2c9ccc add r0, sp, #92
 *   @0x2c9cd0 ldr r3, [lr]
 *   @0x2c9cd4 mov r1, r10
 *   @0x2c9cd8 vstr s18, [sp, #308]
 *   @0x2c9cdc str r3, [r12]
 *   @0x2c9ce0 bl 0x2e0930 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput>
 *   @0x2c9ce4 ldr r3, [sp, #0x5c]
 *   @0x2c9ce8 vldr s15, [sp, #96]
 *   @0x2c9cec cmp r3, #3
 *   @0x2c9cf0 vmovne.f32 s15, s18
 *   @0x2c9cf4 beq 0x2ca5e8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb34>
 *   @0x2c9cf8 ldr r3, [r4, #0x4]
 *   @0x2c9cfc vstr s15, [r4, #132]
 *   @0x2c9d00 orr r3, r3, #32
 *   @0x2c9d04 str r3, [r4, #0x4]
 *   @0x2c9d08 b 0x2c9b74 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xc0>
 *   @0x2c9d0c andeq r0, r0, r0
 *   @0x2c9d10 svclo #0x7fffec
 *   @0x2c9d14 cmp r8, #0
 *   @0x2c9d18 beq 0x2ca288 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7d4>
 *   @0x2c9d1c vcmpe.f32 s16, s20
 *   @0x2c9d20 vmrs APSR_nzcv, fpscr
 *   @0x2c9d24 bgt 0x2ca288 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7d4>
 *   @0x2c9d28 ldr r2, [r8, #0x30]
 *   @0x2c9d2c add r10, sp, #56
 *   @0x2c9d30 ldr r3, [r8, #0x34]
 *   @0x2c9d34 add r11, sp, #92
 *   @0x2c9d38 mov r6, r10
 *   @0x2c9d3c vmov.f32 s21, #1.000000e+00
 *   @0x2c9d40 ldr r4, [r2, #0x8]
 *   @0x2c9d44 mov r12, r11
 *   @0x2c9d48 ldr r5, [r3, #0x8]
 *   @0x2c9d4c add r2, r4, #44
 *   @0x2c9d50 str r2, [sp, #0x18]
 *   @0x2c9d54 add r9, r5, #44
 *   @0x2c9d58 add lr, r4, #52
 *   @0x2c9d5c mov r7, r2
 *   @0x2c9d60 str lr, [sp, #0x14]
 *   @0x2c9d64 ldm r7!, {r0, r1, r2, r3}
 *   @0x2c9d68 add lr, r4, #60
 *   @0x2c9d6c str lr, [sp, #0xc]
 *   @0x2c9d70 mov lr, r9
 *   @0x2c9d74 stm r6!, {r0, r1, r2, r3}
 *   @0x2c9d78 ldm r7!, {r0, r1, r2, r3}
 *   @0x2c9d7c stm r6!, {r0, r1, r2, r3}
 *   @0x2c9d80 ldm lr!, {r0, r1, r2, r3}
 *   @0x2c9d84 ldr r7, [r7]
 *   @0x2c9d88 stm r12!, {r0, r1, r2, r3}
 *   @0x2c9d8c ldm lr!, {r0, r1, r2, r3}
 *   @0x2c9d90 str r7, [r6]
 *   @0x2c9d94 stm r12!, {r0, r1, r2, r3}
 *   @0x2c9d98 ldr r3, [lr]
 *   @0x2c9d9c ldr lr, [sp, #0x14]
 *   @0x2c9da0 str r3, [r12]
 *   @0x2c9da4 vldr s12, [r4, #76]
 *   @0x2c9da8 vsub.f32 s14, s16, s12
 *   @0x2c9dac vldr s13, [r4, #52]
 *   @0x2c9db0 vldr s15, [r4, #56]
 *   @0x2c9db4 vldr s10, [r4, #60]
 *   @0x2c9db8 vldr s11, [r4, #64]
 *   @0x2c9dbc vldr s9, [r4, #72]
 *   @0x2c9dc0 vldr s17, [r4, #68]
 *   @0x2c9dc4 vstr s16, [r4, #76]
 *   @0x2c9dc8 vsub.f32 s12, s21, s12
 *   @0x2c9dcc vdiv.f32 s14, s14, s12
 *   @0x2c9dd0 vsub.f32 s10, s10, s13
 *   @0x2c9dd4 vsub.f32 s11, s11, s15
 *   @0x2c9dd8 vsub.f32 s12, s9, s17
 *   @0x2c9ddc vmla.f32 s13, s14, s10
 *   @0x2c9de0 vmla.f32 s15, s14, s11
 *   @0x2c9de4 vstr s13, [r4, #52]
 *   @0x2c9de8 vmla.f32 s17, s14, s12
 *   @0x2c9dec vstr s15, [r4, #56]
 *   @0x2c9df0 ldm lr, {r0, r1}
 *   @0x2c9df4 ldr lr, [sp, #0xc]
 *   @0x2c9df8 vstr s17, [r4, #68]
 *   @0x2c9dfc stm lr, {r0, r1}
 *   @0x2c9e00 vstr s17, [r4, #72]
 *   @0x2c9e04 vmov r0, s17
 *   @0x2c9e08 bl 0xb6580 <sinf@plt>
 *   @0x2c9e0c vmov s18, r0
 *   @0x2c9e10 vstr s18, [r4, #20]
 *   @0x2c9e14 vmov r0, s17
 *   @0x2c9e18 bl 0xb658c <cosf@plt>
 *   @0x2c9e1c vldr s14, [r4, #48]
 *   @0x2c9e20 vmul.f32 s13, s14, s18
 *   @0x2c9e24 vldr s15, [r4, #44]
 *   @0x2c9e28 vldr s10, [r4, #60]
 *   @0x2c9e2c vldr s11, [r4, #64]
 *   @0x2c9e30 add r2, r5, #52
 *   @0x2c9e34 add r3, r5, #60
 *   @0x2c9e38 vmov s12, r0
 *   @0x2c9e3c str r0, [r4, #0x18]
 *   @0x2c9e40 vmul.f32 s14, s14, s12
 *   @0x2c9e44 vnmls.f32 s13, s15, s12
 *   @0x2c9e48 vmla.f32 s14, s15, s18
 *   @0x2c9e4c vsub.f32 s13, s10, s13
 *   @0x2c9e50 vsub.f32 s14, s11, s14
 *   @0x2c9e54 vstr s13, [r4, #12]
 *   @0x2c9e58 vstr s14, [r4, #16]
 *   @0x2c9e5c vldr s12, [r5, #76]
 *   @0x2c9e60 vsub.f32 s21, s21, s12
 *   @0x2c9e64 vldr s13, [r5, #52]
 *   @0x2c9e68 vldr s14, [r5, #56]
 *   @0x2c9e6c vldr s10, [r5, #60]
 *   @0x2c9e70 vldr s11, [r5, #64]
 *   @0x2c9e74 vldr s9, [r5, #72]
 *   @0x2c9e78 vldr s17, [r5, #68]
 *   @0x2c9e7c vstr s16, [r5, #76]
 *   @0x2c9e80 vsub.f32 s15, s16, s12
 *   @0x2c9e84 vdiv.f32 s15, s15, s21
 *   @0x2c9e88 vsub.f32 s10, s10, s13
 *   @0x2c9e8c vsub.f32 s11, s11, s14
 *   @0x2c9e90 vsub.f32 s12, s9, s17
 *   @0x2c9e94 vmla.f32 s13, s15, s10
 *   @0x2c9e98 vmla.f32 s14, s15, s11
 *   @0x2c9e9c vstr s13, [r5, #52]
 *   @0x2c9ea0 vmla.f32 s17, s15, s12
 *   @0x2c9ea4 vstr s14, [r5, #56]
 *   @0x2c9ea8 ldm r2, {r0, r1}
 *   @0x2c9eac vstr s17, [r5, #68]
 *   @0x2c9eb0 stm r3, {r0, r1}
 *   @0x2c9eb4 vstr s17, [r5, #72]
 *   @0x2c9eb8 vmov r0, s17
 *   @0x2c9ebc bl 0xb6580 <sinf@plt>
 *   @0x2c9ec0 vmov s18, r0
 *   @0x2c9ec4 vstr s18, [r5, #20]
 *   @0x2c9ec8 vmov r0, s17
 *   @0x2c9ecc bl 0xb658c <cosf@plt>
 *   @0x2c9ed0 vldr s15, [r5, #48]
 *   @0x2c9ed4 vmul.f32 s14, s15, s18
 *   @0x2c9ed8 vldr s12, [r5, #44]
 *   @0x2c9edc vldr s10, [r5, #60]
 *   @0x2c9ee0 vldr s11, [r5, #64]
 *   @0x2c9ee4 ldr r3, [sp, #0x10]
 *   @0x2c9ee8 ldr r2, [sp, #0x1c]
 *   @0x2c9eec vmov s13, r0
 *   @0x2c9ef0 str r0, [r5, #0x18]
 *   @0x2c9ef4 mov r0, r8
 *   @0x2c9ef8 vmul.f32 s15, s15, s13
 *   @0x2c9efc vnmls.f32 s14, s12, s13
 *   @0x2c9f00 vmla.f32 s15, s12, s18
 *   @0x2c9f04 vsub.f32 s14, s10, s14
 *   @0x2c9f08 vsub.f32 s15, s11, s15
 *   @0x2c9f0c vstr s14, [r5, #12]
 *   @0x2c9f10 vstr s15, [r5, #16]
 *   @0x2c9f14 ldr r1, [r3, r2]
 *   @0x2c9f18 bl 0x2cc1ec <_ZN9b2Contact6UpdateEP17b2ContactListener>
 *   @0x2c9f1c ldr r12, [r8, #0x4]
 *   @0x2c9f20 ldr r2, [r8, #0x80]
 *   @0x2c9f24 and r1, r12, #6
 *   @0x2c9f28 bic r3, r12, #32
 *   @0x2c9f2c cmp r1, #6
 *   @0x2c9f30 add r2, r2, #1
 *   @0x2c9f34 str r3, [r8, #0x4]
 *   @0x2c9f38 str r2, [r8, #0x80]
 *   @0x2c9f3c bne 0x2ca2a0 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7ec>
 *   @0x2c9f40 ldrh r2, [r4, #4]
 *   @0x2c9f44 tst r2, #2
 *   @0x2c9f48 orreq r2, r2, #2
 *   @0x2c9f4c vstreq s19, [r4, #160]
 *   @0x2c9f50 strheq r2, [r4, #4]
 *   @0x2c9f54 ldrh r2, [r5, #4]
 *   @0x2c9f58 mov r10, #0
 *   @0x2c9f5c ldr r1, [sp, #0x88]
 *   @0x2c9f60 mov r0, #2
 *   @0x2c9f64 tst r2, #2
 *   @0x2c9f68 vstreq s19, [r5, #160]
 *   @0x2c9f6c orreq r2, r2, #2
 *   @0x2c9f70 strheq r2, [r5, #4]
 *   @0x2c9f74 str r10, [sp, #0xa0]
 *   @0x2c9f78 mov r2, #1
 *   @0x2c9f7c str r10, [r4, #0x8]
 *   @0x2c9f80 orr r3, r3, r2
 *   @0x2c9f84 str r4, [r1]
 *   @0x2c9f88 mov r11, r4
 *   @0x2c9f8c ldr r1, [sp, #0x88]
 *   @0x2c9f90 add lr, sp, #180
 *   @0x2c9f94 str r2, [r5, #0x8]
 *   @0x2c9f98 vmov.f32 s17, #1.000000e+00
 *   @0x2c9f9c str r4, [sp, #0x30]
 *   @0x2c9fa0 mov r9, r4
 *   @0x2c9fa4 str r5, [r1, #0x4]
 *   @0x2c9fa8 ldr r1, [sp, #0x8c]
 *   @0x2c9fac str r2, [sp, #0xa4]
 *   @0x2c9fb0 ldrh r2, [r4, #4]
 *   @0x2c9fb4 str r0, [sp, #0x9c]
 *   @0x2c9fb8 orr r2, r2, #1
 *   @0x2c9fbc str r8, [r1]
 *   @0x2c9fc0 strh r2, [r4, #4]
 *   @0x2c9fc4 ldrh r2, [r5, #4]
 *   @0x2c9fc8 str lr, [sp, #0xc]
 *   @0x2c9fcc orr r2, r2, #1
 *   @0x2c9fd0 strh r2, [r5, #4]
 *   @0x2c9fd4 str r3, [r8, #0x4]
 *   @0x2c9fd8 ldr r3, [r11]
 *   @0x2c9fdc str r5, [sp, #0x34]
 *   @0x2c9fe0 cmp r3, #2
 *   @0x2c9fe4 beq 0x2ca008 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x554>
 *   @0x2c9fe8 add r10, r10, #4
 *   @0x2c9fec cmp r10, #8
 *   @0x2c9ff0 beq 0x2ca184 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6d0>
 *   @0x2c9ff4 add r3, sp, #48
 *   @0x2c9ff8 ldr r11, [r10, r3]
 *   @0x2c9ffc ldr r3, [r11]
 *   @0x2ca000 cmp r3, #2
 *   @0x2ca004 bne 0x2c9fe8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x534>
 *   @0x2ca008 ldr r4, [r11, #0x80]
 *   @0x2ca00c cmp r4, #0
 *   @0x2ca010 beq 0x2c9fe8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x534>
 *   @0x2ca014 ldr r2, [sp, #0x9c]
 *   @0x2ca018 ldr r3, [sp, #0xa8]
 *   @0x2ca01c cmp r2, r3
 *   @0x2ca020 beq 0x2c9fe8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x534>
 *   @0x2ca024 ldr r2, [sp, #0xa4]
 *   @0x2ca028 ldr r3, [sp, #0xac]
 *   @0x2ca02c cmp r2, r3
 *   @0x2ca030 strne r5, [sp, #0x14]
 *   @0x2ca034 movne r5, r11
 *   @0x2ca038 bne 0x2ca130 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x67c>
 *   @0x2ca03c b 0x2c9fe8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x534>
 *   @0x2ca040 ldr r2, [r6, #0x34]
 *   @0x2ca044 ldr r3, [r6, #0x30]
 *   @0x2ca048 ldrb r2, [r2, #0x2c]
 *   @0x2ca04c ldrb r3, [r3, #0x2c]
 *   @0x2ca050 orrs r3, r2, r3
 *   @0x2ca054 bne 0x2ca104 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x650>
 *   @0x2ca058 add r8, r7, #44
 *   @0x2ca05c add r12, sp, #180
 *   @0x2ca060 ldrh r11, [r7, #4]
 *   @0x2ca064 mov lr, r8
 *   @0x2ca068 ldm lr!, {r0, r1, r2, r3}
 *   @0x2ca06c tst r11, #1
 *   @0x2ca070 stm r12!, {r0, r1, r2, r3}
 *   @0x2ca074 ldm lr!, {r0, r1, r2, r3}
 *   @0x2ca078 stm r12!, {r0, r1, r2, r3}
 *   @0x2ca07c ldr r3, [lr]
 *   @0x2ca080 str r3, [r12]
 *   @0x2ca084 beq 0x2ca410 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x95c>
 *   @0x2ca088 ldr r3, [sp, #0x10]
 *   @0x2ca08c mov r0, r6
 *   @0x2ca090 ldr r2, [sp, #0x1c]
 *   @0x2ca094 ldr r1, [r3, r2]
 *   @0x2ca098 bl 0x2cc1ec <_ZN9b2Contact6UpdateEP17b2ContactListener>
 *   @0x2ca09c ldr r3, [r6, #0x4]
 *   @0x2ca0a0 tst r3, #4
 *   @0x2ca0a4 beq 0x2ca39c <_ZN7b2World8SolveTOIERK10b2TimeStep+0x8e8>
 *   @0x2ca0a8 tst r3, #2
 *   @0x2ca0ac beq 0x2ca39c <_ZN7b2World8SolveTOIERK10b2TimeStep+0x8e8>
 *   @0x2ca0b0 ldrh r1, [r7, #4]
 *   @0x2ca0b4 orr r3, r3, #1
 *   @0x2ca0b8 ldr r2, [sp, #0xa4]
 *   @0x2ca0bc ldr r0, [sp, #0x8c]
 *   @0x2ca0c0 tst r1, #1
 *   @0x2ca0c4 str r3, [r6, #0x4]
 *   @0x2ca0c8 add r3, r2, #1
 *   @0x2ca0cc str r3, [sp, #0xa4]
 *   @0x2ca0d0 str r6, [r0, r2, lsl #2]
 *   @0x2ca0d4 bne 0x2ca104 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x650>
 *   @0x2ca0d8 ldr r3, [r7]
 *   @0x2ca0dc orr r2, r1, #1
 *   @0x2ca0e0 strh r2, [r7, #4]
 *   @0x2ca0e4 cmp r3, #0
 *   @0x2ca0e8 bne 0x2ca5c8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb14>
 *   @0x2ca0ec ldr r3, [sp, #0x9c]
 *   @0x2ca0f0 ldr r1, [sp, #0x88]
 *   @0x2ca0f4 add r2, r3, #1
 *   @0x2ca0f8 str r3, [r7, #0x8]
 *   @0x2ca0fc str r7, [r1, r3, lsl #2]
 *   @0x2ca100 str r2, [sp, #0x9c]
 *   @0x2ca104 ldr r4, [r4, #0xc]
 *   @0x2ca108 cmp r4, #0
 *   @0x2ca10c beq 0x2ca174 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c0>
 *   @0x2ca110 ldr r2, [sp, #0x9c]
 *   @0x2ca114 ldr r3, [sp, #0xa8]
 *   @0x2ca118 cmp r2, r3
 *   @0x2ca11c beq 0x2ca174 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c0>
 *   @0x2ca120 ldr r2, [sp, #0xa4]
 *   @0x2ca124 ldr r3, [sp, #0xac]
 *   @0x2ca128 cmp r2, r3
 *   @0x2ca12c beq 0x2ca174 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c0>
 *   @0x2ca130 ldr r6, [r4, #0x4]
 *   @0x2ca134 ldr r3, [r6, #0x4]
 *   @0x2ca138 tst r3, #1
 *   @0x2ca13c bne 0x2ca104 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x650>
 *   @0x2ca140 ldr r7, [r4]
 *   @0x2ca144 ldr r3, [r7]
 *   @0x2ca148 cmp r3, #2
 *   @0x2ca14c bne 0x2ca040 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x58c>
 *   @0x2ca150 ldrh r3, [r5, #4]
 *   @0x2ca154 tst r3, #8
 *   @0x2ca158 bne 0x2ca040 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x58c>
 *   @0x2ca15c ldrh r3, [r7, #4]
 *   @0x2ca160 tst r3, #8
 *   @0x2ca164 bne 0x2ca040 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x58c>
 *   @0x2ca168 ldr r4, [r4, #0xc]
 *   @0x2ca16c cmp r4, #0
 *   @0x2ca170 bne 0x2ca110 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x65c>
 *   @0x2ca174 add r10, r10, #4
 *   @0x2ca178 ldr r5, [sp, #0x14]
 *   @0x2ca17c cmp r10, #8
 *   @0x2ca180 bne 0x2c9ff4 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x540>
 *   @0x2ca184 vmov.f32 s15, #1.000000e+00
 *   @0x2ca188 ldr lr, [sp, #0x20]
 *   @0x2ca18c vldr s14, [lr]
 *   @0x2ca190 mov r2, #20
 *   @0x2ca194 str r2, [sp, #0xc4]
 *   @0x2ca198 add r1, sp, #180
 *   @0x2ca19c ldr r3, [lr, #0xc]
 *   @0x2ca1a0 add r0, sp, #128
 *   @0x2ca1a4 mov r6, #0
 *   @0x2ca1a8 str r3, [sp, #0xc0]
 *   @0x2ca1ac ldr r3, [r5, #0x8]
 *   @0x2ca1b0 ldr r2, [r9, #0x8]
 *   @0x2ca1b4 strb r6, [sp, #0xc8]
 *   @0x2ca1b8 vsub.f32 s16, s15, s16
 *   @0x2ca1bc vstr s15, [sp, #188]
 *   @0x2ca1c0 vmul.f32 s16, s16, s14
 *   @0x2ca1c4 vdiv.f32 s15, s15, s16
 *   @0x2ca1c8 vstr s16, [sp, #180]
 *   @0x2ca1cc vstr s15, [sp, #184]
 *   @0x2ca1d0 bl 0x2e12c4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii>
 *   @0x2ca1d4 ldr r1, [sp, #0x9c]
 *   @0x2ca1d8 cmp r1, r6
 *   @0x2ca1dc movgt r5, r6
 *   @0x2ca1e0 bgt 0x2ca1f4 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x740>
 *   @0x2ca1e4 b 0x2ca254 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7a0>
 *   @0x2ca1e8 add r5, r5, #1
 *   @0x2ca1ec cmp r1, r5
 *   @0x2ca1f0 ble 0x2ca254 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7a0>
 *   @0x2ca1f4 ldr r3, [sp, #0x88]
 *   @0x2ca1f8 ldr r4, [r3, r5, lsl #2]
 *   @0x2ca1fc ldr r2, [r4]
 *   @0x2ca200 ldrh r3, [r4, #4]
 *   @0x2ca204 cmp r2, #2
 *   @0x2ca208 bic r3, r3, #1
 *   @0x2ca20c strh r3, [r4, #4]
 *   @0x2ca210 bne 0x2ca1e8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x734>
 *   @0x2ca214 mov r0, r4
 *   @0x2ca218 bl 0x2c72cc <_ZN6b2Body19SynchronizeFixturesEv>
 *   @0x2ca21c ldr r3, [r4, #0x80]
 *   @0x2ca220 cmp r3, #0
 *   @0x2ca224 beq 0x2ca244 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x790>
 *   @0x2ca228 ldr r2, [r3, #0x4]
 *   @0x2ca22c ldr r3, [r3, #0xc]
 *   @0x2ca230 ldr r1, [r2, #0x4]
 *   @0x2ca234 cmp r3, #0
 *   @0x2ca238 bic r1, r1, #33
 *   @0x2ca23c str r1, [r2, #0x4]
 *   @0x2ca240 bne 0x2ca228 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x774>
 *   @0x2ca244 ldr r1, [sp, #0x9c]
 *   @0x2ca248 add r5, r5, #1
 *   @0x2ca24c cmp r1, r5
 *   @0x2ca250 bgt 0x2ca1f4 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x740>
 *   @0x2ca254 ldr r0, [sp, #0x2c]
 *   @0x2ca258 bl 0x2c84d8 <_ZN16b2ContactManager15FindNewContactsEv>
 *   @0x2ca25c ldr r2, [sp, #0x10]
 *   @0x2ca260 ldr r1, [sp, #0x28]
 *   @0x2ca264 ldrb r3, [r2, r1]
 *   @0x2ca268 cmp r3, #0
 *   @0x2ca26c bne 0x2ca4c8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa14>
 *   @0x2ca270 ldr lr, [sp, #0x10]
 *   @0x2ca274 movw r3, #0x9214
 *   @0x2ca278 movt r3, #0x1
 *   @0x2ca27c ldr r4, [lr, r3]
 *   @0x2ca280 cmp r4, #0
 *   @0x2ca284 bne 0x2c9b58 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa4>
 *   @0x2ca288 ldr r1, [sp, #0x10]
 *   @0x2ca28c movw r3, #0x9253
 *   @0x2ca290 movt r3, #0x1
 *   @0x2ca294 mov r2, #1
 *   @0x2ca298 strb r2, [r1, r3]
 *   @0x2ca29c b 0x2ca4dc <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa28>
 *   @0x2ca2a0 ldm r10!, {r0, r1, r2, r3}
 *   @0x2ca2a4 bic r12, r12, #36
 *   @0x2ca2a8 ldr lr, [sp, #0x18]
 *   @0x2ca2ac mov r6, r9
 *   @0x2ca2b0 str r12, [r8, #0x4]
 *   @0x2ca2b4 mov r12, r11
 *   @0x2ca2b8 stm lr!, {r0, r1, r2, r3}
 *   @0x2ca2bc ldm r10!, {r0, r1, r2, r3}
 *   @0x2ca2c0 ldr r7, [r10]
 *   @0x2ca2c4 stm lr!, {r0, r1, r2, r3}
 *   @0x2ca2c8 str r7, [lr]
 *   @0x2ca2cc ldm r12!, {r0, r1, r2, r3}
 *   @0x2ca2d0 stm r6!, {r0, r1, r2, r3}
 *   @0x2ca2d4 ldm r12!, {r0, r1, r2, r3}
 *   @0x2ca2d8 stm r6!, {r0, r1, r2, r3}
 *   @0x2ca2dc ldr r3, [r12]
 *   @0x2ca2e0 ldr r7, [r4, #0x48]
 *   @0x2ca2e4 str r3, [r6]
 *   @0x2ca2e8 mov r0, r7
 *   @0x2ca2ec bl 0xb6580 <sinf@plt>
 *   @0x2ca2f0 vmov s16, r0
 *   @0x2ca2f4 mov r0, r7
 *   @0x2ca2f8 vstr s16, [r4, #20]
 *   @0x2ca2fc bl 0xb658c <cosf@plt>
 *   @0x2ca300 vldr s15, [r4, #48]
 *   @0x2ca304 vmul.f32 s14, s15, s16
 *   @0x2ca308 vldr s12, [r4, #44]
 *   @0x2ca30c vldr s11, [r4, #64]
 *   @0x2ca310 vldr s10, [r4, #60]
 *   @0x2ca314 vmov s13, r0
 *   @0x2ca318 str r0, [r4, #0x18]
 *   @0x2ca31c vmul.f32 s15, s15, s13
 *   @0x2ca320 vnmls.f32 s14, s12, s13
 *   @0x2ca324 vmla.f32 s15, s12, s16
 *   @0x2ca328 vsub.f32 s14, s10, s14
 *   @0x2ca32c vsub.f32 s15, s11, s15
 *   @0x2ca330 vstr s14, [r4, #12]
 *   @0x2ca334 vstr s15, [r4, #16]
 *   @0x2ca338 ldr r4, [r5, #0x48]
 *   @0x2ca33c mov r0, r4
 *   @0x2ca340 bl 0xb6580 <sinf@plt>
 *   @0x2ca344 vmov s16, r0
 *   @0x2ca348 mov r0, r4
 *   @0x2ca34c vstr s16, [r5, #20]
 *   @0x2ca350 bl 0xb658c <cosf@plt>
 *   @0x2ca354 vldr s15, [r5, #48]
 *   @0x2ca358 vmul.f32 s14, s15, s16
 *   @0x2ca35c vldr s12, [r5, #44]
 *   @0x2ca360 vldr s11, [r5, #64]
 *   @0x2ca364 vldr s10, [r5, #60]
 *   @0x2ca368 vmov s13, r0
 *   @0x2ca36c str r0, [r5, #0x18]
 *   @0x2ca370 vmul.f32 s15, s15, s13
 *   @0x2ca374 vnmls.f32 s14, s12, s13
 *   @0x2ca378 vmla.f32 s15, s12, s16
 *   @0x2ca37c vsub.f32 s14, s10, s14
 *   @0x2ca380 vsub.f32 s15, s11, s15
 *   @0x2ca384 vstr s14, [r5, #12]
 *   @0x2ca388 vstr s15, [r5, #16]
 *   @0x2ca38c b 0x2ca270 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7bc>
 *   @0x2ca390 cmp r0, #0
 *   @0x2ca394 beq 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0>
 *   @0x2ca398 b 0x2c9c10 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x15c>
 *   @0x2ca39c add r12, sp, #180
 *   @0x2ca3a0 ldm r12!, {r0, r1, r2, r3}
 *   @0x2ca3a4 stm r8!, {r0, r1, r2, r3}
 *   @0x2ca3a8 ldm r12!, {r0, r1, r2, r3}
 *   @0x2ca3ac stm r8!, {r0, r1, r2, r3}
 *   @0x2ca3b0 ldr r3, [r12]
 *   @0x2ca3b4 ldr r6, [r7, #0x48]
 *   @0x2ca3b8 str r3, [r8]
 *   @0x2ca3bc mov r0, r6
 *   @0x2ca3c0 bl 0xb6580 <sinf@plt>
 *   @0x2ca3c4 vmov s18, r0
 *   @0x2ca3c8 mov r0, r6
 *   @0x2ca3cc vstr s18, [r7, #20]
 *   @0x2ca3d0 bl 0xb658c <cosf@plt>
 *   @0x2ca3d4 vldr s15, [r7, #48]
 *   @0x2ca3d8 vmul.f32 s14, s15, s18
 *   @0x2ca3dc vldr s12, [r7, #44]
 *   @0x2ca3e0 vldr s11, [r7, #64]
 *   @0x2ca3e4 vldr s10, [r7, #60]
 *   @0x2ca3e8 vmov s13, r0
 *   @0x2ca3ec str r0, [r7, #0x18]
 *   @0x2ca3f0 vmul.f32 s15, s15, s13
 *   @0x2ca3f4 vnmls.f32 s14, s12, s13
 *   @0x2ca3f8 vmla.f32 s15, s12, s18
 *   @0x2ca3fc vsub.f32 s14, s10, s14
 *   @0x2ca400 vsub.f32 s15, s11, s15
 *   @0x2ca404 vstr s14, [r7, #12]
 *   @0x2ca408 vstr s15, [r7, #16]
 *   @0x2ca40c b 0x2ca104 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x650>
 *   @0x2ca410 vldr s12, [r7, #76]
 *   @0x2ca414 vsub.f32 s15, s16, s12
 *   @0x2ca418 vldr s13, [r7, #52]
 *   @0x2ca41c vldr s14, [r7, #56]
 *   @0x2ca420 vldr s10, [r7, #60]
 *   @0x2ca424 vldr s11, [r7, #64]
 *   @0x2ca428 vldr s9, [r7, #72]
 *   @0x2ca42c vldr s18, [r7, #68]
 *   @0x2ca430 add r2, r7, #52
 *   @0x2ca434 add r3, r7, #60
 *   @0x2ca438 vstr s16, [r7, #76]
 *   @0x2ca43c vsub.f32 s12, s17, s12
 *   @0x2ca440 vdiv.f32 s15, s15, s12
 *   @0x2ca444 vsub.f32 s10, s10, s13
 *   @0x2ca448 vsub.f32 s11, s11, s14
 *   @0x2ca44c vsub.f32 s12, s9, s18
 *   @0x2ca450 vmla.f32 s13, s15, s10
 *   @0x2ca454 vmla.f32 s14, s15, s11
 *   @0x2ca458 vstr s13, [r7, #52]
 *   @0x2ca45c vmla.f32 s18, s15, s12
 *   @0x2ca460 vstr s14, [r7, #56]
 *   @0x2ca464 ldm r2, {r0, r1}
 *   @0x2ca468 vstr s18, [r7, #68]
 *   @0x2ca46c stm r3, {r0, r1}
 *   @0x2ca470 vstr s18, [r7, #72]
 *   @0x2ca474 vmov r0, s18
 *   @0x2ca478 bl 0xb6580 <sinf@plt>
 *   @0x2ca47c vmov s21, r0
 *   @0x2ca480 vstr s21, [r7, #20]
 *   @0x2ca484 vmov r0, s18
 *   @0x2ca488 bl 0xb658c <cosf@plt>
 *   @0x2ca48c vldr s15, [r7, #48]
 *   @0x2ca490 vmul.f32 s14, s15, s21
 *   @0x2ca494 vldr s12, [r7, #44]
 *   @0x2ca498 vldr s11, [r7, #64]
 *   @0x2ca49c vldr s10, [r7, #60]
 *   @0x2ca4a0 vmov s13, r0
 *   @0x2ca4a4 str r0, [r7, #0x18]
 *   @0x2ca4a8 vmul.f32 s15, s15, s13
 *   @0x2ca4ac vnmls.f32 s14, s12, s13
 *   @0x2ca4b0 vmla.f32 s15, s12, s21
 *   @0x2ca4b4 vsub.f32 s14, s10, s14
 *   @0x2ca4b8 vsub.f32 s15, s11, s15
 *   @0x2ca4bc vstr s14, [r7, #12]
 *   @0x2ca4c0 vstr s15, [r7, #16]
 *   @0x2ca4c4 b 0x2ca088 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x5d4>
 *   @0x2ca4c8 ldr lr, [sp, #0x10]
 *   @0x2ca4cc movw r3, #0x9253
 *   @0x2ca4d0 movt r3, #0x1
 *   @0x2ca4d4 mov r2, #0
 *   @0x2ca4d8 strb r2, [lr, r3]
 *   @0x2ca4dc add r0, sp, #128
 *   @0x2ca4e0 bl 0x2e11d8 <_ZN8b2IslandD2Ev>
 *   @0x2ca4e4 add sp, sp, #316
 *   @0x2ca4e8 vpop {d8, d9, d10}
 *   @0x2ca4ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ca4f0 ldr r1, [sp, #0x10]
 *   @0x2ca4f4 movw r3, #0x9228
 *   @0x2ca4f8 movt r3, #0x1
 *   @0x2ca4fc ldr r3, [r1, r3]
 *   @0x2ca500 cmp r3, #0
 *   @0x2ca504 movne r1, #0
 *   @0x2ca508 beq 0x2ca528 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa74>
 *   @0x2ca50c ldrh r2, [r3, #4]
 *   @0x2ca510 str r1, [r3, #0x4c]
 *   @0x2ca514 bic r2, r2, #1
 *   @0x2ca518 strh r2, [r3, #4]
 *   @0x2ca51c ldr r3, [r3, #0x70]
 *   @0x2ca520 cmp r3, #0
 *   @0x2ca524 bne 0x2ca50c <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa58>
 *   @0x2ca528 ldr r2, [sp, #0x10]
 *   @0x2ca52c movw r3, #0x9214
 *   @0x2ca530 movt r3, #0x1
 *   @0x2ca534 ldr r4, [r2, r3]
 *   @0x2ca538 cmp r4, #0
 *   @0x2ca53c movne r0, #1065353216
 *   @0x2ca540 movne r3, r4
 *   @0x2ca544 movne r1, #0
 *   @0x2ca548 beq 0x2c9b20 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c>
 *   @0x2ca54c ldr r2, [r3, #0x4]
 *   @0x2ca550 str r0, [r3, #0x84]
 *   @0x2ca554 str r1, [r3, #0x80]
 *   @0x2ca558 bic r2, r2, #33
 *   @0x2ca55c str r2, [r3, #0x4]
 *   @0x2ca560 ldr r3, [r3, #0xc]
 *   @0x2ca564 cmp r3, #0
 *   @0x2ca568 bne 0x2ca54c <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa98>
 *   @0x2ca56c b 0x2c9b20 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c>
 *   @0x2ca570 vmov.f32 s8, #1.000000e+00
 *   @0x2ca574 vstr s15, [r6, #76]
 *   @0x2ca578 vldr s12, [r6, #52]
 *   @0x2ca57c vldr s13, [r6, #56]
 *   @0x2ca580 vldr s14, [r6, #68]
 *   @0x2ca584 vldr s9, [r6, #60]
 *   @0x2ca588 vldr s10, [r6, #64]
 *   @0x2ca58c vldr s11, [r6, #72]
 *   @0x2ca590 vsub.f32 s8, s8, s17
 *   @0x2ca594 vsub.f32 s7, s15, s17
 *   @0x2ca598 vmov.f32 s17, s15
 *   @0x2ca59c vdiv.f32 s15, s7, s8
 *   @0x2ca5a0 vsub.f32 s9, s9, s12
 *   @0x2ca5a4 vsub.f32 s10, s10, s13
 *   @0x2ca5a8 vsub.f32 s11, s11, s14
 *   @0x2ca5ac vmla.f32 s12, s15, s9
 *   @0x2ca5b0 vmla.f32 s13, s15, s10
 *   @0x2ca5b4 vstr s12, [r6, #52]
 *   @0x2ca5b8 vmla.f32 s14, s15, s11
 *   @0x2ca5bc vstr s13, [r6, #56]
 *   @0x2ca5c0 vstr s14, [r6, #68]
 *   @0x2ca5c4 b 0x2c9c4c <_ZN7b2World8SolveTOIERK10b2TimeStep+0x198>
 *   @0x2ca5c8 tst r1, #2
 *   @0x2ca5cc vstreq s19, [r7, #160]
 *   @0x2ca5d0 orreq r1, r1, #3
 *   @0x2ca5d4 strheq r1, [r7, #4]
 *   @0x2ca5d8 b 0x2ca0ec <_ZN7b2World8SolveTOIERK10b2TimeStep+0x638>
 *   @0x2ca5dc cmp r12, #0
 *   @0x2ca5e0 beq 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0>
 *   @0x2ca5e4 b 0x2c9c34 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x180>
 *   @0x2ca5e8 vsub.f32 s14, s18, s17
 *   @0x2ca5ec vmla.f32 s17, s14, s15
 *   @0x2ca5f0 vmov.f32 s15, s17
 *   @0x2ca5f4 vcmpe.f32 s17, s18
 *   @0x2ca5f8 vmrs APSR_nzcv, fpscr
 *   @0x2ca5fc vmovpl.f32 s15, s18
 *   @0x2ca600 b 0x2c9cf8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x244>
 *   @0x2ca604 vmov.f32 s8, #1.000000e+00
 *   @0x2ca608 vldr s12, [r7, #52]
 *   @0x2ca60c vldr s13, [r7, #56]
 *   @0x2ca610 vldr s14, [r7, #68]
 *   @0x2ca614 vldr s9, [r7, #60]
 *   @0x2ca618 vldr s10, [r7, #64]
 *   @0x2ca61c vldr s11, [r7, #72]
 *   @0x2ca620 vstr s17, [r7, #76]
 *   @0x2ca624 vsub.f32 s8, s8, s15
 *   @0x2ca628 vsub.f32 s15, s17, s15
 *   @0x2ca62c vdiv.f32 s15, s15, s8
 *   @0x2ca630 vsub.f32 s9, s9, s12
 *   @0x2ca634 vsub.f32 s10, s10, s13
 *   @0x2ca638 vsub.f32 s11, s11, s14
 *   @0x2ca63c vmla.f32 s12, s15, s9
 *   @0x2ca640 vmla.f32 s13, s15, s10
 *   @0x2ca644 vstr s12, [r7, #52]
 *   @0x2ca648 vmla.f32 s14, s15, s11
 *   @0x2ca64c vstr s13, [r7, #56]
 *   @0x2ca650 vstr s14, [r7, #68]
 *   @0x2ca654 b 0x2c9c4c <_ZN7b2World8SolveTOIERK10b2TimeStep+0x198>
 *
 * ══ §2/13 MarkAndSweepGen  0xd5ba8  size 2872  0 条（0xd5ba8..0xd66e0）
 * ⚠ 本节 718 条锚点与语义已升格为正文卡 cards/GC_MarkAndSweepGen.c；这里只保留结构事实
 * @func 0xd5ba8 0xd66e0  size 2872  718 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd5bac→0x47f295, 0xd5bf4→0x536f08, 0xd5bfc→0x536da8, 0xd5c24→0x536f0c, 0xd5c28→0x536d9c, 0xd5c64→0x536da0, 0xd5ca4→0x536da0, 0xd5cd8→0x54298c
 * 调用序列: CGCGeneration::AddDynamicRoot(YYObjectBase*, bool)×4 / Timing_Time×2 / 0xb65b0×2 / YYObjectBase::Mark4GC(unsigned int*, int)×2 / CGCGeneration::RemoveRoot(YYObjectBase*)×2 / YYObjectBase::Free(YYObjectBase*)×2 / MarkAndSweepGen(int, int, bool)+0x914×2 / MarkAndSweepGen(int, int, bool)+0x4c
 * 字段偏移 top8: 0x1c×18 / 0x14×18 / 0x4×14 / 0x10×12 / 0x18×11 / 0x38×11 / 0x24×10 / 0x8×8
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *
 * ══ §3/13 Call_Real_std  0x21012c  size 2444  611 条（0x21012c..0x210ab8）
 * @func 0x21012c 0x210ab8  size 2444  611 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×25 / 0x8fc×1 / 0x8dc×1 / 0x5c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21012c ldr r12, [pc, #0x8fc]
 *   @0x210130 mov r3, r1
 *   @0x210134 push {r4, r5, r6, lr}
 *   @0x210138 ldr r12, [pc, r12]
 *   @0x21013c mov r6, r2
 *   @0x210140 sub sp, sp, #112
 *   @0x210144 ldrb r2, [r12]
 *   @0x210148 cmp r2, #0
 *   @0x21014c bne 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x210150 ldr r1, [pc, #0x8dc]
 *   @0x210154 ldr r1, [pc, r1]
 *   @0x210158 ldr r12, [r1]
 *   @0x21015c cmp r0, r12
 *   @0x210160 ldrlt r2, [r1, #0x4]
 *   @0x210164 ldrlt r2, [r2, r0, lsl #2]
 *   @0x210168 ldr r1, [r2, #0x5c]
 *   @0x21016c cmp r1, #0
 *   @0x210170 str r1, [r6, #0xc]
 *   @0x210174 ldr r1, [r2, #0x14]
 *   @0x210178 sub r1, r1, #5
 *   @0x21017c bne 0x210240 <_Z13Call_Real_stdiPdP6RValue+0x114>
 *   @0x210180 cmp r1, #11
 *   @0x210184 addls pc, pc, r1, lsl #2
 *   @0x210188 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x21018c b 0x210760 <_Z13Call_Real_stdiPdP6RValue+0x634>
 *   @0x210190 b 0x210790 <_Z13Call_Real_stdiPdP6RValue+0x664>
 *   @0x210194 b 0x2107c8 <_Z13Call_Real_stdiPdP6RValue+0x69c>
 *   @0x210198 b 0x210808 <_Z13Call_Real_stdiPdP6RValue+0x6dc>
 *   @0x21019c b 0x210850 <_Z13Call_Real_stdiPdP6RValue+0x724>
 *   @0x2101a0 b 0x2108a0 <_Z13Call_Real_stdiPdP6RValue+0x774>
 *   @0x2101a4 b 0x2108f8 <_Z13Call_Real_stdiPdP6RValue+0x7cc>
 *   @0x2101a8 b 0x210958 <_Z13Call_Real_stdiPdP6RValue+0x82c>
 *   @0x2101ac b 0x2109c0 <_Z13Call_Real_stdiPdP6RValue+0x894>
 *   @0x2101b0 b 0x210a38 <_Z13Call_Real_stdiPdP6RValue+0x90c>
 *   @0x2101b4 b 0x2101bc <_Z13Call_Real_stdiPdP6RValue+0x90>
 *   @0x2101b8 b 0x21027c <_Z13Call_Real_stdiPdP6RValue+0x150>
 *   @0x2101bc ldrd r0, r1, [r3, #16]
 *   @0x2101c0 ldrd r4, r5, [r3, #24]
 *   @0x2101c4 strd r0, r1, [sp]
 *   @0x2101c8 strd r4, r5, [sp, #8]
 *   @0x2101cc ldrd r0, r1, [r3, #32]
 *   @0x2101d0 ldrd r4, r5, [r3, #40]
 *   @0x2101d4 strd r0, r1, [sp, #16]
 *   @0x2101d8 strd r4, r5, [sp, #24]
 *   @0x2101dc ldrd r0, r1, [r3, #48]
 *   @0x2101e0 ldrd r4, r5, [r3, #56]
 *   @0x2101e4 strd r0, r1, [sp, #32]
 *   @0x2101e8 strd r4, r5, [sp, #40]
 *   @0x2101ec ldrd r0, r1, [r3, #64]
 *   @0x2101f0 ldrd r4, r5, [r3, #72]
 *   @0x2101f4 strd r0, r1, [sp, #48]
 *   @0x2101f8 strd r4, r5, [sp, #56]
 *   @0x2101fc ldrd r0, r1, [r3, #80]
 *   @0x210200 ldrd r4, r5, [r3, #88]
 *   @0x210204 strd r0, r1, [sp, #64]
 *   @0x210208 strd r4, r5, [sp, #72]
 *   @0x21020c ldrd r0, r1, [r3, #96]
 *   @0x210210 ldrd r4, r5, [r3, #104]
 *   @0x210214 strd r0, r1, [sp, #80]
 *   @0x210218 strd r4, r5, [sp, #88]
 *   @0x21021c ldrd r4, r5, [r3, #112]
 *   @0x210220 ldrd r0, r1, [r3]
 *   @0x210224 strd r4, r5, [sp, #96]
 *   @0x210228 ldr r12, [r2, #0xc]
 *   @0x21022c ldrd r2, r3, [r3, #8]
 *   @0x210230 blx r12
 *   @0x210234 stm r6, {r0, r1}
 *   @0x210238 add sp, sp, #112
 *   @0x21023c pop {r4, r5, r6, pc}
 *   @0x210240 cmp r1, #11
 *   @0x210244 addls pc, pc, r1, lsl #2
 *   @0x210248 b 0x210ab0 <_Z13Call_Real_stdiPdP6RValue+0x984>
 *   @0x21024c b 0x210304 <_Z13Call_Real_stdiPdP6RValue+0x1d8>
 *   @0x210250 b 0x210340 <_Z13Call_Real_stdiPdP6RValue+0x214>
 *   @0x210254 b 0x210378 <_Z13Call_Real_stdiPdP6RValue+0x24c>
 *   @0x210258 b 0x2103b8 <_Z13Call_Real_stdiPdP6RValue+0x28c>
 *   @0x21025c b 0x210400 <_Z13Call_Real_stdiPdP6RValue+0x2d4>
 *   @0x210260 b 0x210450 <_Z13Call_Real_stdiPdP6RValue+0x324>
 *   @0x210264 b 0x2104a8 <_Z13Call_Real_stdiPdP6RValue+0x37c>
 *   @0x210268 b 0x210508 <_Z13Call_Real_stdiPdP6RValue+0x3dc>
 *   @0x21026c b 0x210570 <_Z13Call_Real_stdiPdP6RValue+0x444>
 *   @0x210270 b 0x2105e0 <_Z13Call_Real_stdiPdP6RValue+0x4b4>
 *   @0x210274 b 0x210658 <_Z13Call_Real_stdiPdP6RValue+0x52c>
 *   @0x210278 b 0x2106d8 <_Z13Call_Real_stdiPdP6RValue+0x5ac>
 *   @0x21027c ldrd r0, r1, [r3, #16]
 *   @0x210280 ldrd r4, r5, [r3, #24]
 *   @0x210284 strd r0, r1, [sp]
 *   @0x210288 strd r4, r5, [sp, #8]
 *   @0x21028c ldrd r0, r1, [r3, #32]
 *   @0x210290 ldrd r4, r5, [r3, #40]
 *   @0x210294 strd r0, r1, [sp, #16]
 *   @0x210298 strd r4, r5, [sp, #24]
 *   @0x21029c ldrd r0, r1, [r3, #48]
 *   @0x2102a0 ldrd r4, r5, [r3, #56]
 *   @0x2102a4 strd r0, r1, [sp, #32]
 *   @0x2102a8 strd r4, r5, [sp, #40]
 *   @0x2102ac ldrd r0, r1, [r3, #64]
 *   @0x2102b0 ldrd r4, r5, [r3, #72]
 *   @0x2102b4 strd r0, r1, [sp, #48]
 *   @0x2102b8 strd r4, r5, [sp, #56]
 *   @0x2102bc ldrd r0, r1, [r3, #80]
 *   @0x2102c0 ldrd r4, r5, [r3, #88]
 *   @0x2102c4 strd r0, r1, [sp, #64]
 *   @0x2102c8 strd r4, r5, [sp, #72]
 *   @0x2102cc ldrd r0, r1, [r3, #96]
 *   @0x2102d0 ldrd r4, r5, [r3, #104]
 *   @0x2102d4 strd r0, r1, [sp, #80]
 *   @0x2102d8 strd r4, r5, [sp, #88]
 *   @0x2102dc ldrd r0, r1, [r3, #112]
 *   @0x2102e0 ldrd r4, r5, [r3, #120]
 *   @0x2102e4 strd r0, r1, [sp, #96]
 *   @0x2102e8 strd r4, r5, [sp, #104]
 *   @0x2102ec ldrd r0, r1, [r3]
 *   @0x2102f0 ldr r12, [r2, #0xc]
 *   @0x2102f4 ldrd r2, r3, [r3, #8]
 *   @0x2102f8 blx r12
 *   @0x2102fc stm r6, {r0, r1}
 *   @0x210300 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x210304 ldrd r0, r1, [r3, #16]
 *   @0x210308 ldrd r4, r5, [r3, #24]
 *   @0x21030c strd r0, r1, [sp]
 *   @0x210310 strd r4, r5, [sp, #8]
 *   @0x210314 ldrd r4, r5, [r3, #32]
 *   @0x210318 ldrd r0, r1, [r3]
 *   @0x21031c strd r4, r5, [sp, #16]
 *   @0x210320 ldr r12, [r2, #0xc]
 *   @0x210324 ldrd r2, r3, [r3, #8]
 *   @0x210328 blx r12
 *   @0x21032c mov r1, r0
 *   @0x210330 mov r0, r6
 *   @0x210334 add sp, sp, #112
 *   @0x210338 pop {r4, r5, r6, lr}
 *   @0x21033c b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x210340 ldrd r0, r1, [r3, #16]
 *   @0x210344 ldrd r4, r5, [r3, #24]
 *   @0x210348 strd r0, r1, [sp]
 *   @0x21034c strd r4, r5, [sp, #8]
 *   @0x210350 ldrd r0, r1, [r3, #32]
 *   @0x210354 ldrd r4, r5, [r3, #40]
 *   @0x210358 strd r0, r1, [sp, #16]
 *   @0x21035c strd r4, r5, [sp, #24]
 *   @0x210360 ldrd r0, r1, [r3]
 *   @0x210364 ldr r12, [r2, #0xc]
 *   @0x210368 ldrd r2, r3, [r3, #8]
 *   @0x21036c blx r12
 *   @0x210370 mov r1, r0
 *   @0x210374 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x210378 ldrd r0, r1, [r3, #16]
 *   @0x21037c ldrd r4, r5, [r3, #24]
 *   @0x210380 strd r0, r1, [sp]
 *   @0x210384 strd r4, r5, [sp, #8]
 *   @0x210388 ldrd r0, r1, [r3, #32]
 *   @0x21038c ldrd r4, r5, [r3, #40]
 *   @0x210390 strd r0, r1, [sp, #16]
 *   @0x210394 strd r4, r5, [sp, #24]
 *   @0x210398 ldrd r4, r5, [r3, #48]
 *   @0x21039c ldrd r0, r1, [r3]
 *   @0x2103a0 strd r4, r5, [sp, #32]
 *   @0x2103a4 ldr r12, [r2, #0xc]
 *   @0x2103a8 ldrd r2, r3, [r3, #8]
 *   @0x2103ac blx r12
 *   @0x2103b0 mov r1, r0
 *   @0x2103b4 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x2103b8 ldrd r0, r1, [r3, #16]
 *   @0x2103bc ldrd r4, r5, [r3, #24]
 *   @0x2103c0 strd r0, r1, [sp]
 *   @0x2103c4 strd r4, r5, [sp, #8]
 *   @0x2103c8 ldrd r0, r1, [r3, #32]
 *   @0x2103cc ldrd r4, r5, [r3, #40]
 *   @0x2103d0 strd r0, r1, [sp, #16]
 *   @0x2103d4 strd r4, r5, [sp, #24]
 *   @0x2103d8 ldrd r0, r1, [r3, #48]
 *   @0x2103dc ldrd r4, r5, [r3, #56]
 *   @0x2103e0 strd r0, r1, [sp, #32]
 *   @0x2103e4 strd r4, r5, [sp, #40]
 *   @0x2103e8 ldrd r0, r1, [r3]
 *   @0x2103ec ldr r12, [r2, #0xc]
 *   @0x2103f0 ldrd r2, r3, [r3, #8]
 *   @0x2103f4 blx r12
 *   @0x2103f8 mov r1, r0
 *   @0x2103fc b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x210400 ldrd r0, r1, [r3, #16]
 *   @0x210404 ldrd r4, r5, [r3, #24]
 *   @0x210408 strd r0, r1, [sp]
 *   @0x21040c strd r4, r5, [sp, #8]
 *   @0x210410 ldrd r0, r1, [r3, #32]
 *   @0x210414 ldrd r4, r5, [r3, #40]
 *   @0x210418 strd r0, r1, [sp, #16]
 *   @0x21041c strd r4, r5, [sp, #24]
 *   @0x210420 ldrd r0, r1, [r3, #48]
 *   @0x210424 ldrd r4, r5, [r3, #56]
 *   @0x210428 strd r0, r1, [sp, #32]
 *   @0x21042c strd r4, r5, [sp, #40]
 *   @0x210430 ldrd r4, r5, [r3, #64]
 *   @0x210434 ldrd r0, r1, [r3]
 *   @0x210438 strd r4, r5, [sp, #48]
 *   @0x21043c ldr r12, [r2, #0xc]
 *   @0x210440 ldrd r2, r3, [r3, #8]
 *   @0x210444 blx r12
 *   @0x210448 mov r1, r0
 *   @0x21044c b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x210450 ldrd r0, r1, [r3, #16]
 *   @0x210454 ldrd r4, r5, [r3, #24]
 *   @0x210458 strd r0, r1, [sp]
 *   @0x21045c strd r4, r5, [sp, #8]
 *   @0x210460 ldrd r0, r1, [r3, #32]
 *   @0x210464 ldrd r4, r5, [r3, #40]
 *   @0x210468 strd r0, r1, [sp, #16]
 *   @0x21046c strd r4, r5, [sp, #24]
 *   @0x210470 ldrd r0, r1, [r3, #48]
 *   @0x210474 ldrd r4, r5, [r3, #56]
 *   @0x210478 strd r0, r1, [sp, #32]
 *   @0x21047c strd r4, r5, [sp, #40]
 *   @0x210480 ldrd r0, r1, [r3, #64]
 *   @0x210484 ldrd r4, r5, [r3, #72]
 *   @0x210488 strd r0, r1, [sp, #48]
 *   @0x21048c strd r4, r5, [sp, #56]
 *   @0x210490 ldrd r0, r1, [r3]
 *   @0x210494 ldr r12, [r2, #0xc]
 *   @0x210498 ldrd r2, r3, [r3, #8]
 *   @0x21049c blx r12
 *   @0x2104a0 mov r1, r0
 *   @0x2104a4 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x2104a8 ldrd r0, r1, [r3, #16]
 *   @0x2104ac ldrd r4, r5, [r3, #24]
 *   @0x2104b0 strd r0, r1, [sp]
 *   @0x2104b4 strd r4, r5, [sp, #8]
 *   @0x2104b8 ldrd r0, r1, [r3, #32]
 *   @0x2104bc ldrd r4, r5, [r3, #40]
 *   @0x2104c0 strd r0, r1, [sp, #16]
 *   @0x2104c4 strd r4, r5, [sp, #24]
 *   @0x2104c8 ldrd r0, r1, [r3, #48]
 *   @0x2104cc ldrd r4, r5, [r3, #56]
 *   @0x2104d0 strd r0, r1, [sp, #32]
 *   @0x2104d4 strd r4, r5, [sp, #40]
 *   @0x2104d8 ldrd r0, r1, [r3, #64]
 *   @0x2104dc ldrd r4, r5, [r3, #72]
 *   @0x2104e0 strd r0, r1, [sp, #48]
 *   @0x2104e4 strd r4, r5, [sp, #56]
 *   @0x2104e8 ldrd r4, r5, [r3, #80]
 *   @0x2104ec ldrd r0, r1, [r3]
 *   @0x2104f0 strd r4, r5, [sp, #64]
 *   @0x2104f4 ldr r12, [r2, #0xc]
 *   @0x2104f8 ldrd r2, r3, [r3, #8]
 *   @0x2104fc blx r12
 *   @0x210500 mov r1, r0
 *   @0x210504 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x210508 ldrd r0, r1, [r3, #16]
 *   @0x21050c ldrd r4, r5, [r3, #24]
 *   @0x210510 strd r0, r1, [sp]
 *   @0x210514 strd r4, r5, [sp, #8]
 *   @0x210518 ldrd r0, r1, [r3, #32]
 *   @0x21051c ldrd r4, r5, [r3, #40]
 *   @0x210520 strd r0, r1, [sp, #16]
 *   @0x210524 strd r4, r5, [sp, #24]
 *   @0x210528 ldrd r0, r1, [r3, #48]
 *   @0x21052c ldrd r4, r5, [r3, #56]
 *   @0x210530 strd r0, r1, [sp, #32]
 *   @0x210534 strd r4, r5, [sp, #40]
 *   @0x210538 ldrd r0, r1, [r3, #64]
 *   @0x21053c ldrd r4, r5, [r3, #72]
 *   @0x210540 strd r0, r1, [sp, #48]
 *   @0x210544 strd r4, r5, [sp, #56]
 *   @0x210548 ldrd r0, r1, [r3, #80]
 *   @0x21054c ldrd r4, r5, [r3, #88]
 *   @0x210550 strd r0, r1, [sp, #64]
 *   @0x210554 strd r4, r5, [sp, #72]
 *   @0x210558 ldrd r0, r1, [r3]
 *   @0x21055c ldr r12, [r2, #0xc]
 *   @0x210560 ldrd r2, r3, [r3, #8]
 *   @0x210564 blx r12
 *   @0x210568 mov r1, r0
 *   @0x21056c b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x210570 ldrd r0, r1, [r3, #16]
 *   @0x210574 ldrd r4, r5, [r3, #24]
 *   @0x210578 strd r0, r1, [sp]
 *   @0x21057c strd r4, r5, [sp, #8]
 *   @0x210580 ldrd r0, r1, [r3, #32]
 *   @0x210584 ldrd r4, r5, [r3, #40]
 *   @0x210588 strd r0, r1, [sp, #16]
 *   @0x21058c strd r4, r5, [sp, #24]
 *   @0x210590 ldrd r0, r1, [r3, #48]
 *   @0x210594 ldrd r4, r5, [r3, #56]
 *   @0x210598 strd r0, r1, [sp, #32]
 *   @0x21059c strd r4, r5, [sp, #40]
 *   @0x2105a0 ldrd r0, r1, [r3, #64]
 *   @0x2105a4 ldrd r4, r5, [r3, #72]
 *   @0x2105a8 strd r0, r1, [sp, #48]
 *   @0x2105ac strd r4, r5, [sp, #56]
 *   @0x2105b0 ldrd r0, r1, [r3, #80]
 *   @0x2105b4 ldrd r4, r5, [r3, #88]
 *   @0x2105b8 strd r0, r1, [sp, #64]
 *   @0x2105bc strd r4, r5, [sp, #72]
 *   @0x2105c0 ldrd r4, r5, [r3, #96]
 *   @0x2105c4 ldrd r0, r1, [r3]
 *   @0x2105c8 strd r4, r5, [sp, #80]
 *   @0x2105cc ldr r12, [r2, #0xc]
 *   @0x2105d0 ldrd r2, r3, [r3, #8]
 *   @0x2105d4 blx r12
 *   @0x2105d8 mov r1, r0
 *   @0x2105dc b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x2105e0 ldrd r0, r1, [r3, #16]
 *   @0x2105e4 ldrd r4, r5, [r3, #24]
 *   @0x2105e8 strd r0, r1, [sp]
 *   @0x2105ec strd r4, r5, [sp, #8]
 *   @0x2105f0 ldrd r0, r1, [r3, #32]
 *   @0x2105f4 ldrd r4, r5, [r3, #40]
 *   @0x2105f8 strd r0, r1, [sp, #16]
 *   @0x2105fc strd r4, r5, [sp, #24]
 *   @0x210600 ldrd r0, r1, [r3, #48]
 *   @0x210604 ldrd r4, r5, [r3, #56]
 *   @0x210608 strd r0, r1, [sp, #32]
 *   @0x21060c strd r4, r5, [sp, #40]
 *   @0x210610 ldrd r0, r1, [r3, #64]
 *   @0x210614 ldrd r4, r5, [r3, #72]
 *   @0x210618 strd r0, r1, [sp, #48]
 *   @0x21061c strd r4, r5, [sp, #56]
 *   @0x210620 ldrd r0, r1, [r3, #80]
 *   @0x210624 ldrd r4, r5, [r3, #88]
 *   @0x210628 strd r0, r1, [sp, #64]
 *   @0x21062c strd r4, r5, [sp, #72]
 *   @0x210630 ldrd r0, r1, [r3, #96]
 *   @0x210634 ldrd r4, r5, [r3, #104]
 *   @0x210638 strd r0, r1, [sp, #80]
 *   @0x21063c strd r4, r5, [sp, #88]
 *   @0x210640 ldrd r0, r1, [r3]
 *   @0x210644 ldr r12, [r2, #0xc]
 *   @0x210648 ldrd r2, r3, [r3, #8]
 *   @0x21064c blx r12
 *   @0x210650 mov r1, r0
 *   @0x210654 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x210658 ldrd r0, r1, [r3, #16]
 *   @0x21065c ldrd r4, r5, [r3, #24]
 *   @0x210660 strd r0, r1, [sp]
 *   @0x210664 strd r4, r5, [sp, #8]
 *   @0x210668 ldrd r0, r1, [r3, #32]
 *   @0x21066c ldrd r4, r5, [r3, #40]
 *   @0x210670 strd r0, r1, [sp, #16]
 *   @0x210674 strd r4, r5, [sp, #24]
 *   @0x210678 ldrd r0, r1, [r3, #48]
 *   @0x21067c ldrd r4, r5, [r3, #56]
 *   @0x210680 strd r0, r1, [sp, #32]
 *   @0x210684 strd r4, r5, [sp, #40]
 *   @0x210688 ldrd r0, r1, [r3, #64]
 *   @0x21068c ldrd r4, r5, [r3, #72]
 *   @0x210690 strd r0, r1, [sp, #48]
 *   @0x210694 strd r4, r5, [sp, #56]
 *   @0x210698 ldrd r0, r1, [r3, #80]
 *   @0x21069c ldrd r4, r5, [r3, #88]
 *   @0x2106a0 strd r0, r1, [sp, #64]
 *   @0x2106a4 strd r4, r5, [sp, #72]
 *   @0x2106a8 ldrd r0, r1, [r3, #96]
 *   @0x2106ac ldrd r4, r5, [r3, #104]
 *   @0x2106b0 strd r0, r1, [sp, #80]
 *   @0x2106b4 strd r4, r5, [sp, #88]
 *   @0x2106b8 ldrd r4, r5, [r3, #112]
 *   @0x2106bc ldrd r0, r1, [r3]
 *   @0x2106c0 strd r4, r5, [sp, #96]
 *   @0x2106c4 ldr r12, [r2, #0xc]
 *   @0x2106c8 ldrd r2, r3, [r3, #8]
 *   @0x2106cc blx r12
 *   @0x2106d0 mov r1, r0
 *   @0x2106d4 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x2106d8 ldrd r0, r1, [r3, #16]
 *   @0x2106dc ldrd r4, r5, [r3, #24]
 *   @0x2106e0 strd r0, r1, [sp]
 *   @0x2106e4 strd r4, r5, [sp, #8]
 *   @0x2106e8 ldrd r0, r1, [r3, #32]
 *   @0x2106ec ldrd r4, r5, [r3, #40]
 *   @0x2106f0 strd r0, r1, [sp, #16]
 *   @0x2106f4 strd r4, r5, [sp, #24]
 *   @0x2106f8 ldrd r0, r1, [r3, #48]
 *   @0x2106fc ldrd r4, r5, [r3, #56]
 *   @0x210700 strd r0, r1, [sp, #32]
 *   @0x210704 strd r4, r5, [sp, #40]
 *   @0x210708 ldrd r0, r1, [r3, #64]
 *   @0x21070c ldrd r4, r5, [r3, #72]
 *   @0x210710 strd r0, r1, [sp, #48]
 *   @0x210714 strd r4, r5, [sp, #56]
 *   @0x210718 ldrd r0, r1, [r3, #80]
 *   @0x21071c ldrd r4, r5, [r3, #88]
 *   @0x210720 strd r0, r1, [sp, #64]
 *   @0x210724 strd r4, r5, [sp, #72]
 *   @0x210728 ldrd r0, r1, [r3, #96]
 *   @0x21072c ldrd r4, r5, [r3, #104]
 *   @0x210730 strd r0, r1, [sp, #80]
 *   @0x210734 strd r4, r5, [sp, #88]
 *   @0x210738 ldrd r0, r1, [r3, #112]
 *   @0x21073c ldrd r4, r5, [r3, #120]
 *   @0x210740 strd r0, r1, [sp, #96]
 *   @0x210744 strd r4, r5, [sp, #104]
 *   @0x210748 ldrd r0, r1, [r3]
 *   @0x21074c ldr r12, [r2, #0xc]
 *   @0x210750 ldrd r2, r3, [r3, #8]
 *   @0x210754 blx r12
 *   @0x210758 mov r1, r0
 *   @0x21075c b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *   @0x210760 ldrd r0, r1, [r3, #16]
 *   @0x210764 ldrd r4, r5, [r3, #24]
 *   @0x210768 strd r0, r1, [sp]
 *   @0x21076c strd r4, r5, [sp, #8]
 *   @0x210770 ldrd r4, r5, [r3, #32]
 *   @0x210774 ldrd r0, r1, [r3]
 *   @0x210778 strd r4, r5, [sp, #16]
 *   @0x21077c ldr r12, [r2, #0xc]
 *   @0x210780 ldrd r2, r3, [r3, #8]
 *   @0x210784 blx r12
 *   @0x210788 stm r6, {r0, r1}
 *   @0x21078c b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x210790 ldrd r0, r1, [r3, #16]
 *   @0x210794 ldrd r4, r5, [r3, #24]
 *   @0x210798 strd r0, r1, [sp]
 *   @0x21079c strd r4, r5, [sp, #8]
 *   @0x2107a0 ldrd r0, r1, [r3, #32]
 *   @0x2107a4 ldrd r4, r5, [r3, #40]
 *   @0x2107a8 strd r0, r1, [sp, #16]
 *   @0x2107ac strd r4, r5, [sp, #24]
 *   @0x2107b0 ldrd r0, r1, [r3]
 *   @0x2107b4 ldr r12, [r2, #0xc]
 *   @0x2107b8 ldrd r2, r3, [r3, #8]
 *   @0x2107bc blx r12
 *   @0x2107c0 stm r6, {r0, r1}
 *   @0x2107c4 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x2107c8 ldrd r0, r1, [r3, #16]
 *   @0x2107cc ldrd r4, r5, [r3, #24]
 *   @0x2107d0 strd r0, r1, [sp]
 *   @0x2107d4 strd r4, r5, [sp, #8]
 *   @0x2107d8 ldrd r0, r1, [r3, #32]
 *   @0x2107dc ldrd r4, r5, [r3, #40]
 *   @0x2107e0 strd r0, r1, [sp, #16]
 *   @0x2107e4 strd r4, r5, [sp, #24]
 *   @0x2107e8 ldrd r4, r5, [r3, #48]
 *   @0x2107ec ldrd r0, r1, [r3]
 *   @0x2107f0 strd r4, r5, [sp, #32]
 *   @0x2107f4 ldr r12, [r2, #0xc]
 *   @0x2107f8 ldrd r2, r3, [r3, #8]
 *   @0x2107fc blx r12
 *   @0x210800 stm r6, {r0, r1}
 *   @0x210804 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x210808 ldrd r0, r1, [r3, #16]
 *   @0x21080c ldrd r4, r5, [r3, #24]
 *   @0x210810 strd r0, r1, [sp]
 *   @0x210814 strd r4, r5, [sp, #8]
 *   @0x210818 ldrd r0, r1, [r3, #32]
 *   @0x21081c ldrd r4, r5, [r3, #40]
 *   @0x210820 strd r0, r1, [sp, #16]
 *   @0x210824 strd r4, r5, [sp, #24]
 *   @0x210828 ldrd r0, r1, [r3, #48]
 *   @0x21082c ldrd r4, r5, [r3, #56]
 *   @0x210830 strd r0, r1, [sp, #32]
 *   @0x210834 strd r4, r5, [sp, #40]
 *   @0x210838 ldrd r0, r1, [r3]
 *   @0x21083c ldr r12, [r2, #0xc]
 *   @0x210840 ldrd r2, r3, [r3, #8]
 *   @0x210844 blx r12
 *   @0x210848 stm r6, {r0, r1}
 *   @0x21084c b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x210850 ldrd r0, r1, [r3, #16]
 *   @0x210854 ldrd r4, r5, [r3, #24]
 *   @0x210858 strd r0, r1, [sp]
 *   @0x21085c strd r4, r5, [sp, #8]
 *   @0x210860 ldrd r0, r1, [r3, #32]
 *   @0x210864 ldrd r4, r5, [r3, #40]
 *   @0x210868 strd r0, r1, [sp, #16]
 *   @0x21086c strd r4, r5, [sp, #24]
 *   @0x210870 ldrd r0, r1, [r3, #48]
 *   @0x210874 ldrd r4, r5, [r3, #56]
 *   @0x210878 strd r0, r1, [sp, #32]
 *   @0x21087c strd r4, r5, [sp, #40]
 *   @0x210880 ldrd r4, r5, [r3, #64]
 *   @0x210884 ldrd r0, r1, [r3]
 *   @0x210888 strd r4, r5, [sp, #48]
 *   @0x21088c ldr r12, [r2, #0xc]
 *   @0x210890 ldrd r2, r3, [r3, #8]
 *   @0x210894 blx r12
 *   @0x210898 stm r6, {r0, r1}
 *   @0x21089c b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x2108a0 ldrd r0, r1, [r3, #16]
 *   @0x2108a4 ldrd r4, r5, [r3, #24]
 *   @0x2108a8 strd r0, r1, [sp]
 *   @0x2108ac strd r4, r5, [sp, #8]
 *   @0x2108b0 ldrd r0, r1, [r3, #32]
 *   @0x2108b4 ldrd r4, r5, [r3, #40]
 *   @0x2108b8 strd r0, r1, [sp, #16]
 *   @0x2108bc strd r4, r5, [sp, #24]
 *   @0x2108c0 ldrd r0, r1, [r3, #48]
 *   @0x2108c4 ldrd r4, r5, [r3, #56]
 *   @0x2108c8 strd r0, r1, [sp, #32]
 *   @0x2108cc strd r4, r5, [sp, #40]
 *   @0x2108d0 ldrd r0, r1, [r3, #64]
 *   @0x2108d4 ldrd r4, r5, [r3, #72]
 *   @0x2108d8 strd r0, r1, [sp, #48]
 *   @0x2108dc strd r4, r5, [sp, #56]
 *   @0x2108e0 ldrd r0, r1, [r3]
 *   @0x2108e4 ldr r12, [r2, #0xc]
 *   @0x2108e8 ldrd r2, r3, [r3, #8]
 *   @0x2108ec blx r12
 *   @0x2108f0 stm r6, {r0, r1}
 *   @0x2108f4 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x2108f8 ldrd r0, r1, [r3, #16]
 *   @0x2108fc ldrd r4, r5, [r3, #24]
 *   @0x210900 strd r0, r1, [sp]
 *   @0x210904 strd r4, r5, [sp, #8]
 *   @0x210908 ldrd r0, r1, [r3, #32]
 *   @0x21090c ldrd r4, r5, [r3, #40]
 *   @0x210910 strd r0, r1, [sp, #16]
 *   @0x210914 strd r4, r5, [sp, #24]
 *   @0x210918 ldrd r0, r1, [r3, #48]
 *   @0x21091c ldrd r4, r5, [r3, #56]
 *   @0x210920 strd r0, r1, [sp, #32]
 *   @0x210924 strd r4, r5, [sp, #40]
 *   @0x210928 ldrd r0, r1, [r3, #64]
 *   @0x21092c ldrd r4, r5, [r3, #72]
 *   @0x210930 strd r0, r1, [sp, #48]
 *   @0x210934 strd r4, r5, [sp, #56]
 *   @0x210938 ldrd r4, r5, [r3, #80]
 *   @0x21093c ldrd r0, r1, [r3]
 *   @0x210940 strd r4, r5, [sp, #64]
 *   @0x210944 ldr r12, [r2, #0xc]
 *   @0x210948 ldrd r2, r3, [r3, #8]
 *   @0x21094c blx r12
 *   @0x210950 stm r6, {r0, r1}
 *   @0x210954 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x210958 ldrd r0, r1, [r3, #16]
 *   @0x21095c ldrd r4, r5, [r3, #24]
 *   @0x210960 strd r0, r1, [sp]
 *   @0x210964 strd r4, r5, [sp, #8]
 *   @0x210968 ldrd r0, r1, [r3, #32]
 *   @0x21096c ldrd r4, r5, [r3, #40]
 *   @0x210970 strd r0, r1, [sp, #16]
 *   @0x210974 strd r4, r5, [sp, #24]
 *   @0x210978 ldrd r0, r1, [r3, #48]
 *   @0x21097c ldrd r4, r5, [r3, #56]
 *   @0x210980 strd r0, r1, [sp, #32]
 *   @0x210984 strd r4, r5, [sp, #40]
 *   @0x210988 ldrd r0, r1, [r3, #64]
 *   @0x21098c ldrd r4, r5, [r3, #72]
 *   @0x210990 strd r0, r1, [sp, #48]
 *   @0x210994 strd r4, r5, [sp, #56]
 *   @0x210998 ldrd r0, r1, [r3, #80]
 *   @0x21099c ldrd r4, r5, [r3, #88]
 *   @0x2109a0 strd r0, r1, [sp, #64]
 *   @0x2109a4 strd r4, r5, [sp, #72]
 *   @0x2109a8 ldrd r0, r1, [r3]
 *   @0x2109ac ldr r12, [r2, #0xc]
 *   @0x2109b0 ldrd r2, r3, [r3, #8]
 *   @0x2109b4 blx r12
 *   @0x2109b8 stm r6, {r0, r1}
 *   @0x2109bc b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x2109c0 ldrd r0, r1, [r3, #16]
 *   @0x2109c4 ldrd r4, r5, [r3, #24]
 *   @0x2109c8 strd r0, r1, [sp]
 *   @0x2109cc strd r4, r5, [sp, #8]
 *   @0x2109d0 ldrd r0, r1, [r3, #32]
 *   @0x2109d4 ldrd r4, r5, [r3, #40]
 *   @0x2109d8 strd r0, r1, [sp, #16]
 *   @0x2109dc strd r4, r5, [sp, #24]
 *   @0x2109e0 ldrd r0, r1, [r3, #48]
 *   @0x2109e4 ldrd r4, r5, [r3, #56]
 *   @0x2109e8 strd r0, r1, [sp, #32]
 *   @0x2109ec strd r4, r5, [sp, #40]
 *   @0x2109f0 ldrd r0, r1, [r3, #64]
 *   @0x2109f4 ldrd r4, r5, [r3, #72]
 *   @0x2109f8 strd r0, r1, [sp, #48]
 *   @0x2109fc strd r4, r5, [sp, #56]
 *   @0x210a00 ldrd r0, r1, [r3, #80]
 *   @0x210a04 ldrd r4, r5, [r3, #88]
 *   @0x210a08 strd r0, r1, [sp, #64]
 *   @0x210a0c strd r4, r5, [sp, #72]
 *   @0x210a10 ldrd r4, r5, [r3, #96]
 *   @0x210a14 ldrd r0, r1, [r3]
 *   @0x210a18 strd r4, r5, [sp, #80]
 *   @0x210a1c ldr r12, [r2, #0xc]
 *   @0x210a20 ldrd r2, r3, [r3, #8]
 *   @0x210a24 blx r12
 *   @0x210a28 stm r6, {r0, r1}
 *   @0x210a2c b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x210a30 andseq r1, lr, r4, ror r2
 *   @0x210a34 andseq r1, lr, r12, asr r2
 *   @0x210a38 ldrd r0, r1, [r3, #16]
 *   @0x210a3c ldrd r4, r5, [r3, #24]
 *   @0x210a40 strd r0, r1, [sp]
 *   @0x210a44 strd r4, r5, [sp, #8]
 *   @0x210a48 ldrd r0, r1, [r3, #32]
 *   @0x210a4c ldrd r4, r5, [r3, #40]
 *   @0x210a50 strd r0, r1, [sp, #16]
 *   @0x210a54 strd r4, r5, [sp, #24]
 *   @0x210a58 ldrd r0, r1, [r3, #48]
 *   @0x210a5c ldrd r4, r5, [r3, #56]
 *   @0x210a60 strd r0, r1, [sp, #32]
 *   @0x210a64 strd r4, r5, [sp, #40]
 *   @0x210a68 ldrd r0, r1, [r3, #64]
 *   @0x210a6c ldrd r4, r5, [r3, #72]
 *   @0x210a70 strd r0, r1, [sp, #48]
 *   @0x210a74 strd r4, r5, [sp, #56]
 *   @0x210a78 ldrd r0, r1, [r3, #80]
 *   @0x210a7c ldrd r4, r5, [r3, #88]
 *   @0x210a80 strd r0, r1, [sp, #64]
 *   @0x210a84 strd r4, r5, [sp, #72]
 *   @0x210a88 ldrd r0, r1, [r3, #96]
 *   @0x210a8c ldrd r4, r5, [r3, #104]
 *   @0x210a90 strd r0, r1, [sp, #80]
 *   @0x210a94 strd r4, r5, [sp, #88]
 *   @0x210a98 ldrd r0, r1, [r3]
 *   @0x210a9c ldr r12, [r2, #0xc]
 *   @0x210aa0 ldrd r2, r3, [r3, #8]
 *   @0x210aa4 blx r12
 *   @0x210aa8 stm r6, {r0, r1}
 *   @0x210aac b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c>
 *   @0x210ab0 mov r1, #0
 *   @0x210ab4 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204>
 *
 * ══ §4/13 Call_Real  0x21161c  size 2444  611 条（0x21161c..0x211fa8）
 * @func 0x21161c 0x211fa8  size 2444  611 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×25 / 0x8fc×1 / 0x8dc×1 / 0x5c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21161c ldr r12, [pc, #0x8fc]
 *   @0x211620 mov r3, r1
 *   @0x211624 push {r4, r5, r6, lr}
 *   @0x211628 ldr r12, [pc, r12]
 *   @0x21162c mov r6, r2
 *   @0x211630 sub sp, sp, #112
 *   @0x211634 ldrb r2, [r12]
 *   @0x211638 cmp r2, #0
 *   @0x21163c bne 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211640 ldr r1, [pc, #0x8dc]
 *   @0x211644 ldr r1, [pc, r1]
 *   @0x211648 ldr r12, [r1]
 *   @0x21164c cmp r0, r12
 *   @0x211650 ldrlt r2, [r1, #0x4]
 *   @0x211654 ldrlt r2, [r2, r0, lsl #2]
 *   @0x211658 ldr r1, [r2, #0x5c]
 *   @0x21165c cmp r1, #0
 *   @0x211660 str r1, [r6, #0xc]
 *   @0x211664 ldr r1, [r2, #0x14]
 *   @0x211668 sub r1, r1, #5
 *   @0x21166c bne 0x2116e0 <_Z9Call_RealiPdP6RValue+0xc4>
 *   @0x211670 cmp r1, #11
 *   @0x211674 addls pc, pc, r1, lsl #2
 *   @0x211678 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x21167c b 0x2116ac <_Z9Call_RealiPdP6RValue+0x90>
 *   @0x211680 b 0x211c08 <_Z9Call_RealiPdP6RValue+0x5ec>
 *   @0x211684 b 0x211c40 <_Z9Call_RealiPdP6RValue+0x624>
 *   @0x211688 b 0x211c80 <_Z9Call_RealiPdP6RValue+0x664>
 *   @0x21168c b 0x211cc8 <_Z9Call_RealiPdP6RValue+0x6ac>
 *   @0x211690 b 0x211d18 <_Z9Call_RealiPdP6RValue+0x6fc>
 *   @0x211694 b 0x211d70 <_Z9Call_RealiPdP6RValue+0x754>
 *   @0x211698 b 0x211dd0 <_Z9Call_RealiPdP6RValue+0x7b4>
 *   @0x21169c b 0x211e38 <_Z9Call_RealiPdP6RValue+0x81c>
 *   @0x2116a0 b 0x211ea8 <_Z9Call_RealiPdP6RValue+0x88c>
 *   @0x2116a4 b 0x211f28 <_Z9Call_RealiPdP6RValue+0x90c>
 *   @0x2116a8 b 0x21171c <_Z9Call_RealiPdP6RValue+0x100>
 *   @0x2116ac ldrd r0, r1, [r3, #16]
 *   @0x2116b0 ldrd r4, r5, [r3, #24]
 *   @0x2116b4 strd r0, r1, [sp]
 *   @0x2116b8 strd r4, r5, [sp, #8]
 *   @0x2116bc ldrd r4, r5, [r3, #32]
 *   @0x2116c0 ldrd r0, r1, [r3]
 *   @0x2116c4 strd r4, r5, [sp, #16]
 *   @0x2116c8 ldr r12, [r2, #0xc]
 *   @0x2116cc ldrd r2, r3, [r3, #8]
 *   @0x2116d0 blx r12
 *   @0x2116d4 stm r6, {r0, r1}
 *   @0x2116d8 add sp, sp, #112
 *   @0x2116dc pop {r4, r5, r6, pc}
 *   @0x2116e0 cmp r1, #11
 *   @0x2116e4 addls pc, pc, r1, lsl #2
 *   @0x2116e8 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x2116ec b 0x2117a4 <_Z9Call_RealiPdP6RValue+0x188>
 *   @0x2116f0 b 0x2117e8 <_Z9Call_RealiPdP6RValue+0x1cc>
 *   @0x2116f4 b 0x211820 <_Z9Call_RealiPdP6RValue+0x204>
 *   @0x2116f8 b 0x211860 <_Z9Call_RealiPdP6RValue+0x244>
 *   @0x2116fc b 0x2118a8 <_Z9Call_RealiPdP6RValue+0x28c>
 *   @0x211700 b 0x2118f8 <_Z9Call_RealiPdP6RValue+0x2dc>
 *   @0x211704 b 0x211950 <_Z9Call_RealiPdP6RValue+0x334>
 *   @0x211708 b 0x2119b0 <_Z9Call_RealiPdP6RValue+0x394>
 *   @0x21170c b 0x211a18 <_Z9Call_RealiPdP6RValue+0x3fc>
 *   @0x211710 b 0x211a88 <_Z9Call_RealiPdP6RValue+0x46c>
 *   @0x211714 b 0x211b00 <_Z9Call_RealiPdP6RValue+0x4e4>
 *   @0x211718 b 0x211b80 <_Z9Call_RealiPdP6RValue+0x564>
 *   @0x21171c ldrd r0, r1, [r3, #16]
 *   @0x211720 ldrd r4, r5, [r3, #24]
 *   @0x211724 strd r0, r1, [sp]
 *   @0x211728 strd r4, r5, [sp, #8]
 *   @0x21172c ldrd r0, r1, [r3, #32]
 *   @0x211730 ldrd r4, r5, [r3, #40]
 *   @0x211734 strd r0, r1, [sp, #16]
 *   @0x211738 strd r4, r5, [sp, #24]
 *   @0x21173c ldrd r0, r1, [r3, #48]
 *   @0x211740 ldrd r4, r5, [r3, #56]
 *   @0x211744 strd r0, r1, [sp, #32]
 *   @0x211748 strd r4, r5, [sp, #40]
 *   @0x21174c ldrd r0, r1, [r3, #64]
 *   @0x211750 ldrd r4, r5, [r3, #72]
 *   @0x211754 strd r0, r1, [sp, #48]
 *   @0x211758 strd r4, r5, [sp, #56]
 *   @0x21175c ldrd r0, r1, [r3, #80]
 *   @0x211760 ldrd r4, r5, [r3, #88]
 *   @0x211764 strd r0, r1, [sp, #64]
 *   @0x211768 strd r4, r5, [sp, #72]
 *   @0x21176c ldrd r0, r1, [r3, #96]
 *   @0x211770 ldrd r4, r5, [r3, #104]
 *   @0x211774 strd r0, r1, [sp, #80]
 *   @0x211778 strd r4, r5, [sp, #88]
 *   @0x21177c ldrd r0, r1, [r3, #112]
 *   @0x211780 ldrd r4, r5, [r3, #120]
 *   @0x211784 strd r0, r1, [sp, #96]
 *   @0x211788 strd r4, r5, [sp, #104]
 *   @0x21178c ldrd r0, r1, [r3]
 *   @0x211790 ldr r12, [r2, #0xc]
 *   @0x211794 ldrd r2, r3, [r3, #8]
 *   @0x211798 blx r12
 *   @0x21179c stm r6, {r0, r1}
 *   @0x2117a0 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x2117a4 ldrd r0, r1, [r3, #16]
 *   @0x2117a8 ldrd r4, r5, [r3, #24]
 *   @0x2117ac strd r0, r1, [sp]
 *   @0x2117b0 strd r4, r5, [sp, #8]
 *   @0x2117b4 ldrd r4, r5, [r3, #32]
 *   @0x2117b8 ldrd r0, r1, [r3]
 *   @0x2117bc strd r4, r5, [sp, #16]
 *   @0x2117c0 ldr r12, [r2, #0xc]
 *   @0x2117c4 ldrd r2, r3, [r3, #8]
 *   @0x2117c8 blx r12
 *   @0x2117cc mov r1, r0
 *   @0x2117d0 cmp r1, #0
 *   @0x2117d4 beq 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x2117d8 mov r0, r6
 *   @0x2117dc add sp, sp, #112
 *   @0x2117e0 pop {r4, r5, r6, lr}
 *   @0x2117e4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2117e8 ldrd r0, r1, [r3, #16]
 *   @0x2117ec ldrd r4, r5, [r3, #24]
 *   @0x2117f0 strd r0, r1, [sp]
 *   @0x2117f4 strd r4, r5, [sp, #8]
 *   @0x2117f8 ldrd r0, r1, [r3, #32]
 *   @0x2117fc ldrd r4, r5, [r3, #40]
 *   @0x211800 strd r0, r1, [sp, #16]
 *   @0x211804 strd r4, r5, [sp, #24]
 *   @0x211808 ldrd r0, r1, [r3]
 *   @0x21180c ldr r12, [r2, #0xc]
 *   @0x211810 ldrd r2, r3, [r3, #8]
 *   @0x211814 blx r12
 *   @0x211818 mov r1, r0
 *   @0x21181c b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x211820 ldrd r0, r1, [r3, #16]
 *   @0x211824 ldrd r4, r5, [r3, #24]
 *   @0x211828 strd r0, r1, [sp]
 *   @0x21182c strd r4, r5, [sp, #8]
 *   @0x211830 ldrd r0, r1, [r3, #32]
 *   @0x211834 ldrd r4, r5, [r3, #40]
 *   @0x211838 strd r0, r1, [sp, #16]
 *   @0x21183c strd r4, r5, [sp, #24]
 *   @0x211840 ldrd r4, r5, [r3, #48]
 *   @0x211844 ldrd r0, r1, [r3]
 *   @0x211848 strd r4, r5, [sp, #32]
 *   @0x21184c ldr r12, [r2, #0xc]
 *   @0x211850 ldrd r2, r3, [r3, #8]
 *   @0x211854 blx r12
 *   @0x211858 mov r1, r0
 *   @0x21185c b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x211860 ldrd r0, r1, [r3, #16]
 *   @0x211864 ldrd r4, r5, [r3, #24]
 *   @0x211868 strd r0, r1, [sp]
 *   @0x21186c strd r4, r5, [sp, #8]
 *   @0x211870 ldrd r0, r1, [r3, #32]
 *   @0x211874 ldrd r4, r5, [r3, #40]
 *   @0x211878 strd r0, r1, [sp, #16]
 *   @0x21187c strd r4, r5, [sp, #24]
 *   @0x211880 ldrd r0, r1, [r3, #48]
 *   @0x211884 ldrd r4, r5, [r3, #56]
 *   @0x211888 strd r0, r1, [sp, #32]
 *   @0x21188c strd r4, r5, [sp, #40]
 *   @0x211890 ldrd r0, r1, [r3]
 *   @0x211894 ldr r12, [r2, #0xc]
 *   @0x211898 ldrd r2, r3, [r3, #8]
 *   @0x21189c blx r12
 *   @0x2118a0 mov r1, r0
 *   @0x2118a4 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x2118a8 ldrd r0, r1, [r3, #16]
 *   @0x2118ac ldrd r4, r5, [r3, #24]
 *   @0x2118b0 strd r0, r1, [sp]
 *   @0x2118b4 strd r4, r5, [sp, #8]
 *   @0x2118b8 ldrd r0, r1, [r3, #32]
 *   @0x2118bc ldrd r4, r5, [r3, #40]
 *   @0x2118c0 strd r0, r1, [sp, #16]
 *   @0x2118c4 strd r4, r5, [sp, #24]
 *   @0x2118c8 ldrd r0, r1, [r3, #48]
 *   @0x2118cc ldrd r4, r5, [r3, #56]
 *   @0x2118d0 strd r0, r1, [sp, #32]
 *   @0x2118d4 strd r4, r5, [sp, #40]
 *   @0x2118d8 ldrd r4, r5, [r3, #64]
 *   @0x2118dc ldrd r0, r1, [r3]
 *   @0x2118e0 strd r4, r5, [sp, #48]
 *   @0x2118e4 ldr r12, [r2, #0xc]
 *   @0x2118e8 ldrd r2, r3, [r3, #8]
 *   @0x2118ec blx r12
 *   @0x2118f0 mov r1, r0
 *   @0x2118f4 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x2118f8 ldrd r0, r1, [r3, #16]
 *   @0x2118fc ldrd r4, r5, [r3, #24]
 *   @0x211900 strd r0, r1, [sp]
 *   @0x211904 strd r4, r5, [sp, #8]
 *   @0x211908 ldrd r0, r1, [r3, #32]
 *   @0x21190c ldrd r4, r5, [r3, #40]
 *   @0x211910 strd r0, r1, [sp, #16]
 *   @0x211914 strd r4, r5, [sp, #24]
 *   @0x211918 ldrd r0, r1, [r3, #48]
 *   @0x21191c ldrd r4, r5, [r3, #56]
 *   @0x211920 strd r0, r1, [sp, #32]
 *   @0x211924 strd r4, r5, [sp, #40]
 *   @0x211928 ldrd r0, r1, [r3, #64]
 *   @0x21192c ldrd r4, r5, [r3, #72]
 *   @0x211930 strd r0, r1, [sp, #48]
 *   @0x211934 strd r4, r5, [sp, #56]
 *   @0x211938 ldrd r0, r1, [r3]
 *   @0x21193c ldr r12, [r2, #0xc]
 *   @0x211940 ldrd r2, r3, [r3, #8]
 *   @0x211944 blx r12
 *   @0x211948 mov r1, r0
 *   @0x21194c b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x211950 ldrd r0, r1, [r3, #16]
 *   @0x211954 ldrd r4, r5, [r3, #24]
 *   @0x211958 strd r0, r1, [sp]
 *   @0x21195c strd r4, r5, [sp, #8]
 *   @0x211960 ldrd r0, r1, [r3, #32]
 *   @0x211964 ldrd r4, r5, [r3, #40]
 *   @0x211968 strd r0, r1, [sp, #16]
 *   @0x21196c strd r4, r5, [sp, #24]
 *   @0x211970 ldrd r0, r1, [r3, #48]
 *   @0x211974 ldrd r4, r5, [r3, #56]
 *   @0x211978 strd r0, r1, [sp, #32]
 *   @0x21197c strd r4, r5, [sp, #40]
 *   @0x211980 ldrd r0, r1, [r3, #64]
 *   @0x211984 ldrd r4, r5, [r3, #72]
 *   @0x211988 strd r0, r1, [sp, #48]
 *   @0x21198c strd r4, r5, [sp, #56]
 *   @0x211990 ldrd r4, r5, [r3, #80]
 *   @0x211994 ldrd r0, r1, [r3]
 *   @0x211998 strd r4, r5, [sp, #64]
 *   @0x21199c ldr r12, [r2, #0xc]
 *   @0x2119a0 ldrd r2, r3, [r3, #8]
 *   @0x2119a4 blx r12
 *   @0x2119a8 mov r1, r0
 *   @0x2119ac b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x2119b0 ldrd r0, r1, [r3, #16]
 *   @0x2119b4 ldrd r4, r5, [r3, #24]
 *   @0x2119b8 strd r0, r1, [sp]
 *   @0x2119bc strd r4, r5, [sp, #8]
 *   @0x2119c0 ldrd r0, r1, [r3, #32]
 *   @0x2119c4 ldrd r4, r5, [r3, #40]
 *   @0x2119c8 strd r0, r1, [sp, #16]
 *   @0x2119cc strd r4, r5, [sp, #24]
 *   @0x2119d0 ldrd r0, r1, [r3, #48]
 *   @0x2119d4 ldrd r4, r5, [r3, #56]
 *   @0x2119d8 strd r0, r1, [sp, #32]
 *   @0x2119dc strd r4, r5, [sp, #40]
 *   @0x2119e0 ldrd r0, r1, [r3, #64]
 *   @0x2119e4 ldrd r4, r5, [r3, #72]
 *   @0x2119e8 strd r0, r1, [sp, #48]
 *   @0x2119ec strd r4, r5, [sp, #56]
 *   @0x2119f0 ldrd r0, r1, [r3, #80]
 *   @0x2119f4 ldrd r4, r5, [r3, #88]
 *   @0x2119f8 strd r0, r1, [sp, #64]
 *   @0x2119fc strd r4, r5, [sp, #72]
 *   @0x211a00 ldrd r0, r1, [r3]
 *   @0x211a04 ldr r12, [r2, #0xc]
 *   @0x211a08 ldrd r2, r3, [r3, #8]
 *   @0x211a0c blx r12
 *   @0x211a10 mov r1, r0
 *   @0x211a14 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x211a18 ldrd r0, r1, [r3, #16]
 *   @0x211a1c ldrd r4, r5, [r3, #24]
 *   @0x211a20 strd r0, r1, [sp]
 *   @0x211a24 strd r4, r5, [sp, #8]
 *   @0x211a28 ldrd r0, r1, [r3, #32]
 *   @0x211a2c ldrd r4, r5, [r3, #40]
 *   @0x211a30 strd r0, r1, [sp, #16]
 *   @0x211a34 strd r4, r5, [sp, #24]
 *   @0x211a38 ldrd r0, r1, [r3, #48]
 *   @0x211a3c ldrd r4, r5, [r3, #56]
 *   @0x211a40 strd r0, r1, [sp, #32]
 *   @0x211a44 strd r4, r5, [sp, #40]
 *   @0x211a48 ldrd r0, r1, [r3, #64]
 *   @0x211a4c ldrd r4, r5, [r3, #72]
 *   @0x211a50 strd r0, r1, [sp, #48]
 *   @0x211a54 strd r4, r5, [sp, #56]
 *   @0x211a58 ldrd r0, r1, [r3, #80]
 *   @0x211a5c ldrd r4, r5, [r3, #88]
 *   @0x211a60 strd r0, r1, [sp, #64]
 *   @0x211a64 strd r4, r5, [sp, #72]
 *   @0x211a68 ldrd r4, r5, [r3, #96]
 *   @0x211a6c ldrd r0, r1, [r3]
 *   @0x211a70 strd r4, r5, [sp, #80]
 *   @0x211a74 ldr r12, [r2, #0xc]
 *   @0x211a78 ldrd r2, r3, [r3, #8]
 *   @0x211a7c blx r12
 *   @0x211a80 mov r1, r0
 *   @0x211a84 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x211a88 ldrd r0, r1, [r3, #16]
 *   @0x211a8c ldrd r4, r5, [r3, #24]
 *   @0x211a90 strd r0, r1, [sp]
 *   @0x211a94 strd r4, r5, [sp, #8]
 *   @0x211a98 ldrd r0, r1, [r3, #32]
 *   @0x211a9c ldrd r4, r5, [r3, #40]
 *   @0x211aa0 strd r0, r1, [sp, #16]
 *   @0x211aa4 strd r4, r5, [sp, #24]
 *   @0x211aa8 ldrd r0, r1, [r3, #48]
 *   @0x211aac ldrd r4, r5, [r3, #56]
 *   @0x211ab0 strd r0, r1, [sp, #32]
 *   @0x211ab4 strd r4, r5, [sp, #40]
 *   @0x211ab8 ldrd r0, r1, [r3, #64]
 *   @0x211abc ldrd r4, r5, [r3, #72]
 *   @0x211ac0 strd r0, r1, [sp, #48]
 *   @0x211ac4 strd r4, r5, [sp, #56]
 *   @0x211ac8 ldrd r0, r1, [r3, #80]
 *   @0x211acc ldrd r4, r5, [r3, #88]
 *   @0x211ad0 strd r0, r1, [sp, #64]
 *   @0x211ad4 strd r4, r5, [sp, #72]
 *   @0x211ad8 ldrd r0, r1, [r3, #96]
 *   @0x211adc ldrd r4, r5, [r3, #104]
 *   @0x211ae0 strd r0, r1, [sp, #80]
 *   @0x211ae4 strd r4, r5, [sp, #88]
 *   @0x211ae8 ldrd r0, r1, [r3]
 *   @0x211aec ldr r12, [r2, #0xc]
 *   @0x211af0 ldrd r2, r3, [r3, #8]
 *   @0x211af4 blx r12
 *   @0x211af8 mov r1, r0
 *   @0x211afc b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x211b00 ldrd r0, r1, [r3, #16]
 *   @0x211b04 ldrd r4, r5, [r3, #24]
 *   @0x211b08 strd r0, r1, [sp]
 *   @0x211b0c strd r4, r5, [sp, #8]
 *   @0x211b10 ldrd r0, r1, [r3, #32]
 *   @0x211b14 ldrd r4, r5, [r3, #40]
 *   @0x211b18 strd r0, r1, [sp, #16]
 *   @0x211b1c strd r4, r5, [sp, #24]
 *   @0x211b20 ldrd r0, r1, [r3, #48]
 *   @0x211b24 ldrd r4, r5, [r3, #56]
 *   @0x211b28 strd r0, r1, [sp, #32]
 *   @0x211b2c strd r4, r5, [sp, #40]
 *   @0x211b30 ldrd r0, r1, [r3, #64]
 *   @0x211b34 ldrd r4, r5, [r3, #72]
 *   @0x211b38 strd r0, r1, [sp, #48]
 *   @0x211b3c strd r4, r5, [sp, #56]
 *   @0x211b40 ldrd r0, r1, [r3, #80]
 *   @0x211b44 ldrd r4, r5, [r3, #88]
 *   @0x211b48 strd r0, r1, [sp, #64]
 *   @0x211b4c strd r4, r5, [sp, #72]
 *   @0x211b50 ldrd r0, r1, [r3, #96]
 *   @0x211b54 ldrd r4, r5, [r3, #104]
 *   @0x211b58 strd r0, r1, [sp, #80]
 *   @0x211b5c strd r4, r5, [sp, #88]
 *   @0x211b60 ldrd r4, r5, [r3, #112]
 *   @0x211b64 ldrd r0, r1, [r3]
 *   @0x211b68 strd r4, r5, [sp, #96]
 *   @0x211b6c ldr r12, [r2, #0xc]
 *   @0x211b70 ldrd r2, r3, [r3, #8]
 *   @0x211b74 blx r12
 *   @0x211b78 mov r1, r0
 *   @0x211b7c b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x211b80 ldrd r0, r1, [r3, #16]
 *   @0x211b84 ldrd r4, r5, [r3, #24]
 *   @0x211b88 strd r0, r1, [sp]
 *   @0x211b8c strd r4, r5, [sp, #8]
 *   @0x211b90 ldrd r0, r1, [r3, #32]
 *   @0x211b94 ldrd r4, r5, [r3, #40]
 *   @0x211b98 strd r0, r1, [sp, #16]
 *   @0x211b9c strd r4, r5, [sp, #24]
 *   @0x211ba0 ldrd r0, r1, [r3, #48]
 *   @0x211ba4 ldrd r4, r5, [r3, #56]
 *   @0x211ba8 strd r0, r1, [sp, #32]
 *   @0x211bac strd r4, r5, [sp, #40]
 *   @0x211bb0 ldrd r0, r1, [r3, #64]
 *   @0x211bb4 ldrd r4, r5, [r3, #72]
 *   @0x211bb8 strd r0, r1, [sp, #48]
 *   @0x211bbc strd r4, r5, [sp, #56]
 *   @0x211bc0 ldrd r0, r1, [r3, #80]
 *   @0x211bc4 ldrd r4, r5, [r3, #88]
 *   @0x211bc8 strd r0, r1, [sp, #64]
 *   @0x211bcc strd r4, r5, [sp, #72]
 *   @0x211bd0 ldrd r0, r1, [r3, #96]
 *   @0x211bd4 ldrd r4, r5, [r3, #104]
 *   @0x211bd8 strd r0, r1, [sp, #80]
 *   @0x211bdc strd r4, r5, [sp, #88]
 *   @0x211be0 ldrd r0, r1, [r3, #112]
 *   @0x211be4 ldrd r4, r5, [r3, #120]
 *   @0x211be8 strd r0, r1, [sp, #96]
 *   @0x211bec strd r4, r5, [sp, #104]
 *   @0x211bf0 ldrd r0, r1, [r3]
 *   @0x211bf4 ldr r12, [r2, #0xc]
 *   @0x211bf8 ldrd r2, r3, [r3, #8]
 *   @0x211bfc blx r12
 *   @0x211c00 mov r1, r0
 *   @0x211c04 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4>
 *   @0x211c08 ldrd r0, r1, [r3, #16]
 *   @0x211c0c ldrd r4, r5, [r3, #24]
 *   @0x211c10 strd r0, r1, [sp]
 *   @0x211c14 strd r4, r5, [sp, #8]
 *   @0x211c18 ldrd r0, r1, [r3, #32]
 *   @0x211c1c ldrd r4, r5, [r3, #40]
 *   @0x211c20 strd r0, r1, [sp, #16]
 *   @0x211c24 strd r4, r5, [sp, #24]
 *   @0x211c28 ldrd r0, r1, [r3]
 *   @0x211c2c ldr r12, [r2, #0xc]
 *   @0x211c30 ldrd r2, r3, [r3, #8]
 *   @0x211c34 blx r12
 *   @0x211c38 stm r6, {r0, r1}
 *   @0x211c3c b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211c40 ldrd r0, r1, [r3, #16]
 *   @0x211c44 ldrd r4, r5, [r3, #24]
 *   @0x211c48 strd r0, r1, [sp]
 *   @0x211c4c strd r4, r5, [sp, #8]
 *   @0x211c50 ldrd r0, r1, [r3, #32]
 *   @0x211c54 ldrd r4, r5, [r3, #40]
 *   @0x211c58 strd r0, r1, [sp, #16]
 *   @0x211c5c strd r4, r5, [sp, #24]
 *   @0x211c60 ldrd r4, r5, [r3, #48]
 *   @0x211c64 ldrd r0, r1, [r3]
 *   @0x211c68 strd r4, r5, [sp, #32]
 *   @0x211c6c ldr r12, [r2, #0xc]
 *   @0x211c70 ldrd r2, r3, [r3, #8]
 *   @0x211c74 blx r12
 *   @0x211c78 stm r6, {r0, r1}
 *   @0x211c7c b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211c80 ldrd r0, r1, [r3, #16]
 *   @0x211c84 ldrd r4, r5, [r3, #24]
 *   @0x211c88 strd r0, r1, [sp]
 *   @0x211c8c strd r4, r5, [sp, #8]
 *   @0x211c90 ldrd r0, r1, [r3, #32]
 *   @0x211c94 ldrd r4, r5, [r3, #40]
 *   @0x211c98 strd r0, r1, [sp, #16]
 *   @0x211c9c strd r4, r5, [sp, #24]
 *   @0x211ca0 ldrd r0, r1, [r3, #48]
 *   @0x211ca4 ldrd r4, r5, [r3, #56]
 *   @0x211ca8 strd r0, r1, [sp, #32]
 *   @0x211cac strd r4, r5, [sp, #40]
 *   @0x211cb0 ldrd r0, r1, [r3]
 *   @0x211cb4 ldr r12, [r2, #0xc]
 *   @0x211cb8 ldrd r2, r3, [r3, #8]
 *   @0x211cbc blx r12
 *   @0x211cc0 stm r6, {r0, r1}
 *   @0x211cc4 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211cc8 ldrd r0, r1, [r3, #16]
 *   @0x211ccc ldrd r4, r5, [r3, #24]
 *   @0x211cd0 strd r0, r1, [sp]
 *   @0x211cd4 strd r4, r5, [sp, #8]
 *   @0x211cd8 ldrd r0, r1, [r3, #32]
 *   @0x211cdc ldrd r4, r5, [r3, #40]
 *   @0x211ce0 strd r0, r1, [sp, #16]
 *   @0x211ce4 strd r4, r5, [sp, #24]
 *   @0x211ce8 ldrd r0, r1, [r3, #48]
 *   @0x211cec ldrd r4, r5, [r3, #56]
 *   @0x211cf0 strd r0, r1, [sp, #32]
 *   @0x211cf4 strd r4, r5, [sp, #40]
 *   @0x211cf8 ldrd r4, r5, [r3, #64]
 *   @0x211cfc ldrd r0, r1, [r3]
 *   @0x211d00 strd r4, r5, [sp, #48]
 *   @0x211d04 ldr r12, [r2, #0xc]
 *   @0x211d08 ldrd r2, r3, [r3, #8]
 *   @0x211d0c blx r12
 *   @0x211d10 stm r6, {r0, r1}
 *   @0x211d14 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211d18 ldrd r0, r1, [r3, #16]
 *   @0x211d1c ldrd r4, r5, [r3, #24]
 *   @0x211d20 strd r0, r1, [sp]
 *   @0x211d24 strd r4, r5, [sp, #8]
 *   @0x211d28 ldrd r0, r1, [r3, #32]
 *   @0x211d2c ldrd r4, r5, [r3, #40]
 *   @0x211d30 strd r0, r1, [sp, #16]
 *   @0x211d34 strd r4, r5, [sp, #24]
 *   @0x211d38 ldrd r0, r1, [r3, #48]
 *   @0x211d3c ldrd r4, r5, [r3, #56]
 *   @0x211d40 strd r0, r1, [sp, #32]
 *   @0x211d44 strd r4, r5, [sp, #40]
 *   @0x211d48 ldrd r0, r1, [r3, #64]
 *   @0x211d4c ldrd r4, r5, [r3, #72]
 *   @0x211d50 strd r0, r1, [sp, #48]
 *   @0x211d54 strd r4, r5, [sp, #56]
 *   @0x211d58 ldrd r0, r1, [r3]
 *   @0x211d5c ldr r12, [r2, #0xc]
 *   @0x211d60 ldrd r2, r3, [r3, #8]
 *   @0x211d64 blx r12
 *   @0x211d68 stm r6, {r0, r1}
 *   @0x211d6c b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211d70 ldrd r0, r1, [r3, #16]
 *   @0x211d74 ldrd r4, r5, [r3, #24]
 *   @0x211d78 strd r0, r1, [sp]
 *   @0x211d7c strd r4, r5, [sp, #8]
 *   @0x211d80 ldrd r0, r1, [r3, #32]
 *   @0x211d84 ldrd r4, r5, [r3, #40]
 *   @0x211d88 strd r0, r1, [sp, #16]
 *   @0x211d8c strd r4, r5, [sp, #24]
 *   @0x211d90 ldrd r0, r1, [r3, #48]
 *   @0x211d94 ldrd r4, r5, [r3, #56]
 *   @0x211d98 strd r0, r1, [sp, #32]
 *   @0x211d9c strd r4, r5, [sp, #40]
 *   @0x211da0 ldrd r0, r1, [r3, #64]
 *   @0x211da4 ldrd r4, r5, [r3, #72]
 *   @0x211da8 strd r0, r1, [sp, #48]
 *   @0x211dac strd r4, r5, [sp, #56]
 *   @0x211db0 ldrd r4, r5, [r3, #80]
 *   @0x211db4 ldrd r0, r1, [r3]
 *   @0x211db8 strd r4, r5, [sp, #64]
 *   @0x211dbc ldr r12, [r2, #0xc]
 *   @0x211dc0 ldrd r2, r3, [r3, #8]
 *   @0x211dc4 blx r12
 *   @0x211dc8 stm r6, {r0, r1}
 *   @0x211dcc b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211dd0 ldrd r0, r1, [r3, #16]
 *   @0x211dd4 ldrd r4, r5, [r3, #24]
 *   @0x211dd8 strd r0, r1, [sp]
 *   @0x211ddc strd r4, r5, [sp, #8]
 *   @0x211de0 ldrd r0, r1, [r3, #32]
 *   @0x211de4 ldrd r4, r5, [r3, #40]
 *   @0x211de8 strd r0, r1, [sp, #16]
 *   @0x211dec strd r4, r5, [sp, #24]
 *   @0x211df0 ldrd r0, r1, [r3, #48]
 *   @0x211df4 ldrd r4, r5, [r3, #56]
 *   @0x211df8 strd r0, r1, [sp, #32]
 *   @0x211dfc strd r4, r5, [sp, #40]
 *   @0x211e00 ldrd r0, r1, [r3, #64]
 *   @0x211e04 ldrd r4, r5, [r3, #72]
 *   @0x211e08 strd r0, r1, [sp, #48]
 *   @0x211e0c strd r4, r5, [sp, #56]
 *   @0x211e10 ldrd r0, r1, [r3, #80]
 *   @0x211e14 ldrd r4, r5, [r3, #88]
 *   @0x211e18 strd r0, r1, [sp, #64]
 *   @0x211e1c strd r4, r5, [sp, #72]
 *   @0x211e20 ldrd r0, r1, [r3]
 *   @0x211e24 ldr r12, [r2, #0xc]
 *   @0x211e28 ldrd r2, r3, [r3, #8]
 *   @0x211e2c blx r12
 *   @0x211e30 stm r6, {r0, r1}
 *   @0x211e34 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211e38 ldrd r0, r1, [r3, #16]
 *   @0x211e3c ldrd r4, r5, [r3, #24]
 *   @0x211e40 strd r0, r1, [sp]
 *   @0x211e44 strd r4, r5, [sp, #8]
 *   @0x211e48 ldrd r0, r1, [r3, #32]
 *   @0x211e4c ldrd r4, r5, [r3, #40]
 *   @0x211e50 strd r0, r1, [sp, #16]
 *   @0x211e54 strd r4, r5, [sp, #24]
 *   @0x211e58 ldrd r0, r1, [r3, #48]
 *   @0x211e5c ldrd r4, r5, [r3, #56]
 *   @0x211e60 strd r0, r1, [sp, #32]
 *   @0x211e64 strd r4, r5, [sp, #40]
 *   @0x211e68 ldrd r0, r1, [r3, #64]
 *   @0x211e6c ldrd r4, r5, [r3, #72]
 *   @0x211e70 strd r0, r1, [sp, #48]
 *   @0x211e74 strd r4, r5, [sp, #56]
 *   @0x211e78 ldrd r0, r1, [r3, #80]
 *   @0x211e7c ldrd r4, r5, [r3, #88]
 *   @0x211e80 strd r0, r1, [sp, #64]
 *   @0x211e84 strd r4, r5, [sp, #72]
 *   @0x211e88 ldrd r4, r5, [r3, #96]
 *   @0x211e8c ldrd r0, r1, [r3]
 *   @0x211e90 strd r4, r5, [sp, #80]
 *   @0x211e94 ldr r12, [r2, #0xc]
 *   @0x211e98 ldrd r2, r3, [r3, #8]
 *   @0x211e9c blx r12
 *   @0x211ea0 stm r6, {r0, r1}
 *   @0x211ea4 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211ea8 ldrd r0, r1, [r3, #16]
 *   @0x211eac ldrd r4, r5, [r3, #24]
 *   @0x211eb0 strd r0, r1, [sp]
 *   @0x211eb4 strd r4, r5, [sp, #8]
 *   @0x211eb8 ldrd r0, r1, [r3, #32]
 *   @0x211ebc ldrd r4, r5, [r3, #40]
 *   @0x211ec0 strd r0, r1, [sp, #16]
 *   @0x211ec4 strd r4, r5, [sp, #24]
 *   @0x211ec8 ldrd r0, r1, [r3, #48]
 *   @0x211ecc ldrd r4, r5, [r3, #56]
 *   @0x211ed0 strd r0, r1, [sp, #32]
 *   @0x211ed4 strd r4, r5, [sp, #40]
 *   @0x211ed8 ldrd r0, r1, [r3, #64]
 *   @0x211edc ldrd r4, r5, [r3, #72]
 *   @0x211ee0 strd r0, r1, [sp, #48]
 *   @0x211ee4 strd r4, r5, [sp, #56]
 *   @0x211ee8 ldrd r0, r1, [r3, #80]
 *   @0x211eec ldrd r4, r5, [r3, #88]
 *   @0x211ef0 strd r0, r1, [sp, #64]
 *   @0x211ef4 strd r4, r5, [sp, #72]
 *   @0x211ef8 ldrd r0, r1, [r3, #96]
 *   @0x211efc ldrd r4, r5, [r3, #104]
 *   @0x211f00 strd r0, r1, [sp, #80]
 *   @0x211f04 strd r4, r5, [sp, #88]
 *   @0x211f08 ldrd r0, r1, [r3]
 *   @0x211f0c ldr r12, [r2, #0xc]
 *   @0x211f10 ldrd r2, r3, [r3, #8]
 *   @0x211f14 blx r12
 *   @0x211f18 stm r6, {r0, r1}
 *   @0x211f1c b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *   @0x211f20 andseq pc, sp, r4, lsl #27
 *   @0x211f24 andseq pc, sp, r12, ror #26
 *   @0x211f28 ldrd r0, r1, [r3, #16]
 *   @0x211f2c ldrd r4, r5, [r3, #24]
 *   @0x211f30 strd r0, r1, [sp]
 *   @0x211f34 strd r4, r5, [sp, #8]
 *   @0x211f38 ldrd r0, r1, [r3, #32]
 *   @0x211f3c ldrd r4, r5, [r3, #40]
 *   @0x211f40 strd r0, r1, [sp, #16]
 *   @0x211f44 strd r4, r5, [sp, #24]
 *   @0x211f48 ldrd r0, r1, [r3, #48]
 *   @0x211f4c ldrd r4, r5, [r3, #56]
 *   @0x211f50 strd r0, r1, [sp, #32]
 *   @0x211f54 strd r4, r5, [sp, #40]
 *   @0x211f58 ldrd r0, r1, [r3, #64]
 *   @0x211f5c ldrd r4, r5, [r3, #72]
 *   @0x211f60 strd r0, r1, [sp, #48]
 *   @0x211f64 strd r4, r5, [sp, #56]
 *   @0x211f68 ldrd r0, r1, [r3, #80]
 *   @0x211f6c ldrd r4, r5, [r3, #88]
 *   @0x211f70 strd r0, r1, [sp, #64]
 *   @0x211f74 strd r4, r5, [sp, #72]
 *   @0x211f78 ldrd r0, r1, [r3, #96]
 *   @0x211f7c ldrd r4, r5, [r3, #104]
 *   @0x211f80 strd r0, r1, [sp, #80]
 *   @0x211f84 strd r4, r5, [sp, #88]
 *   @0x211f88 ldrd r4, r5, [r3, #112]
 *   @0x211f8c ldrd r0, r1, [r3]
 *   @0x211f90 strd r4, r5, [sp, #96]
 *   @0x211f94 ldr r12, [r2, #0xc]
 *   @0x211f98 ldrd r2, r3, [r3, #8]
 *   @0x211f9c blx r12
 *   @0x211fa0 stm r6, {r0, r1}
 *   @0x211fa4 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc>
 *
 * ══ §5/13 vmGetCallStack  0xdb934  size 2336  584 条（0xdb934..0xdc254）
 * @func 0xdb934 0xdc254  size 2336  584 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×13 / YYAlloc(int)×12 / 0xb65bc×12 / 0xb6538×4 / 0xb65a4×4 / YYStrBuilder::operator<<(int)×4 / VM::DebugInfo(VMBuffer*, int)×2 / VM::DebugLineNumber(VMDebugInfo*, char const*, char**)×2
 * 字段偏移 top8: 0x34×33 / 0x2c×26 / 0x30×26 / 0x4×15 / 0x8×15 / 0x24×4 / 0x20×3 / 0x18×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb934 ldr r3, [pc, #0x8f0]
 *   @0xdb938 mov r2, #0
 *   @0xdb93c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xdb940 ldr r3, [pc, r3]
 *   @0xdb944 sub sp, sp, #60
 *   @0xdb948 ldr r6, [r3]
 *   @0xdb94c str r2, [sp, #0x2c]
 *   @0xdb950 cmp r6, r2
 *   @0xdb954 str r2, [sp, #0x30]
 *   @0xdb958 str r2, [sp, #0x34]
 *   @0xdb95c beq 0xdc218 <_Z14vmGetCallStackv+0x8e4>
 *   @0xdb960 ldr r3, [pc, #0x8c8]
 *   @0xdb964 add r10, sp, #44
 *   @0xdb968 add r3, pc, r3
 *   @0xdb96c str r3, [sp, #0x20]
 *   @0xdb970 ldr r3, [pc, #0x8bc]
 *   @0xdb974 add r3, pc, r3
 *   @0xdb978 str r3, [sp, #0x24]
 *   @0xdb97c ldr r3, [pc, #0x8b4]
 *   @0xdb980 add r3, pc, r3
 *   @0xdb984 str r3, [sp, #0x18]
 *   @0xdb988 ldr r3, [pc, #0x8ac]
 *   @0xdb98c add r3, pc, r3
 *   @0xdb990 str r3, [sp, #0x1c]
 *   @0xdb994 ldr r3, [pc, #0x8a4]
 *   @0xdb998 add r3, pc, r3
 *   @0xdb99c str r3, [sp, #0x10]
 *   @0xdb9a0 ldr r3, [pc, #0x89c]
 *   @0xdb9a4 add r3, pc, r3
 *   @0xdb9a8 str r3, [sp, #0x14]
 *   @0xdb9ac ldr r0, [r6, #0x38]
 *   @0xdb9b0 mov r3, #0
 *   @0xdb9b4 str r3, [sp, #0x28]
 *   @0xdb9b8 cmp r0, r3
 *   @0xdb9bc beq 0xdc050 <_Z14vmGetCallStackv+0x71c>
 *   @0xdb9c0 ldr r1, [r6, #0x54]
 *   @0xdb9c4 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0xdb9c8 ldr r1, [r6, #0x3c]
 *   @0xdb9cc add r2, sp, #40
 *   @0xdb9d0 bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0xdb9d4 ldr r8, [r6, #0x34]
 *   @0xdb9d8 cmp r8, #0
 *   @0xdb9dc ldreq r4, [sp, #0x34]
 *   @0xdb9e0 mov r5, r0
 *   @0xdb9e4 beq 0xdba88 <_Z14vmGetCallStackv+0x154>
 *   @0xdb9e8 mov r0, r8
 *   @0xdb9ec bl 0xb6538 <strlen@plt>
 *   @0xdb9f0 ldr r2, [sp, #0x34]
 *   @0xdb9f4 ldr r3, [sp, #0x30]
 *   @0xdb9f8 add r1, r0, #1
 *   @0xdb9fc mov r4, r0
 *   @0xdba00 mvn r0, r2
 *   @0xdba04 add r0, r3, r0
 *   @0xdba08 cmp r1, r0
 *   @0xdba0c ble 0xdba6c <_Z14vmGetCallStackv+0x138>
 *   @0xdba10 cmp r3, #0
 *   @0xdba14 add r2, r1, r2
 *   @0xdba18 ldr r7, [sp, #0x2c]
 *   @0xdba1c moveq r3, r1
 *   @0xdba20 add r3, r3, r3, lsl #1
 *   @0xdba24 add r3, r3, r3, lsr #31
 *   @0xdba28 asr r9, r3, #1
 *   @0xdba2c cmp r9, r2
 *   @0xdba30 addlt r2, r2, r2, lsl #1
 *   @0xdba34 addlt r2, r2, r2, lsr #31
 *   @0xdba38 asrlt r9, r2, #1
 *   @0xdba3c mov r0, r9
 *   @0xdba40 bl 0xcef4c <_Z7YYAlloci>
 *   @0xdba44 ldr r2, [sp, #0x30]
 *   @0xdba48 mov r1, r7
 *   @0xdba4c str r0, [sp, #0x2c]
 *   @0xdba50 bl 0xb65bc <memcpy@plt>
 *   @0xdba54 cmp r7, #0
 *   @0xdba58 str r9, [sp, #0x30]
 *   @0xdba5c beq 0xdba68 <_Z14vmGetCallStackv+0x134>
 *   @0xdba60 mov r0, r7
 *   @0xdba64 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdba68 ldr r2, [sp, #0x34]
 *   @0xdba6c ldr r0, [sp, #0x2c]
 *   @0xdba70 mov r1, r8
 *   @0xdba74 add r0, r0, r2
 *   @0xdba78 bl 0xb65a4 <strcpy@plt>
 *   @0xdba7c ldr r3, [sp, #0x34]
 *   @0xdba80 add r4, r4, r3
 *   @0xdba84 str r4, [sp, #0x34]
 *   @0xdba88 ldr r3, [sp, #0x30]
 *   @0xdba8c mvn r2, r4
 *   @0xdba90 add r2, r3, r2
 *   @0xdba94 cmp r2, #1
 *   @0xdba98 bgt 0xdbaf8 <_Z14vmGetCallStackv+0x1c4>
 *   @0xdba9c cmp r3, #0
 *   @0xdbaa0 add r4, r4, #2
 *   @0xdbaa4 addne r3, r3, r3, lsl #1
 *   @0xdbaa8 moveq r7, #3
 *   @0xdbaac addne r3, r3, r3, lsr #31
 *   @0xdbab0 asrne r7, r3, #1
 *   @0xdbab4 cmp r4, r7
 *   @0xdbab8 addgt r4, r4, r4, lsl #1
 *   @0xdbabc addgt r4, r4, r4, lsr #31
 *   @0xdbac0 asrgt r7, r4, #1
 *   @0xdbac4 ldr r4, [sp, #0x2c]
 *   @0xdbac8 mov r0, r7
 *   @0xdbacc bl 0xcef4c <_Z7YYAlloci>
 *   @0xdbad0 ldr r2, [sp, #0x30]
 *   @0xdbad4 mov r1, r4
 *   @0xdbad8 str r0, [sp, #0x2c]
 *   @0xdbadc bl 0xb65bc <memcpy@plt>
 *   @0xdbae0 cmp r4, #0
 *   @0xdbae4 str r7, [sp, #0x30]
 *   @0xdbae8 beq 0xdbaf4 <_Z14vmGetCallStackv+0x1c0>
 *   @0xdbaec mov r0, r4
 *   @0xdbaf0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdbaf4 ldr r4, [sp, #0x34]
 *   @0xdbaf8 ldr r0, [sp, #0x18]
 *   @0xdbafc mov r1, r5
 *   @0xdbb00 ldr r3, [sp, #0x2c]
 *   @0xdbb04 ldrh r2, [r0]
 *   @0xdbb08 mov r0, r10
 *   @0xdbb0c strh r2, [r3, r4]
 *   @0xdbb10 ldr r3, [sp, #0x34]
 *   @0xdbb14 add r3, r3, #1
 *   @0xdbb18 str r3, [sp, #0x34]
 *   @0xdbb1c bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0xdbb20 ldmib r0, {r2, r3}
 *   @0xdbb24 mov r5, r0
 *   @0xdbb28 mvn r1, r3
 *   @0xdbb2c add r1, r2, r1
 *   @0xdbb30 cmp r1, #1
 *   @0xdbb34 bgt 0xdbb94 <_Z14vmGetCallStackv+0x260>
 *   @0xdbb38 cmp r2, #0
 *   @0xdbb3c add r3, r3, #2
 *   @0xdbb40 addne r2, r2, r2, lsl #1
 *   @0xdbb44 ldr r4, [r5]
 *   @0xdbb48 moveq r7, #3
 *   @0xdbb4c addne r2, r2, r2, lsr #31
 *   @0xdbb50 asrne r7, r2, #1
 *   @0xdbb54 cmp r3, r7
 *   @0xdbb58 addgt r3, r3, r3, lsl #1
 *   @0xdbb5c addgt r3, r3, r3, lsr #31
 *   @0xdbb60 asrgt r7, r3, #1
 *   @0xdbb64 mov r0, r7
 *   @0xdbb68 bl 0xcef4c <_Z7YYAlloci>
 *   @0xdbb6c ldr r2, [r5, #0x4]
 *   @0xdbb70 mov r1, r4
 *   @0xdbb74 str r0, [r5]
 *   @0xdbb78 bl 0xb65bc <memcpy@plt>
 *   @0xdbb7c cmp r4, #0
 *   @0xdbb80 str r7, [r5, #0x4]
 *   @0xdbb84 beq 0xdbb90 <_Z14vmGetCallStackv+0x25c>
 *   @0xdbb88 mov r0, r4
 *   @0xdbb8c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdbb90 ldr r3, [r5, #0x8]
 *   @0xdbb94 ldr r2, [r5]
 *   @0xdbb98 ldr r0, [sp, #0x1c]
 *   @0xdbb9c ldrh r1, [r0]
 *   @0xdbba0 strh r1, [r2, r3]
 *   @0xdbba4 ldr r3, [r5, #0x8]
 *   @0xdbba8 ldr r4, [r6, #0x28]
 *   @0xdbbac add r3, r3, #1
 *   @0xdbbb0 str r3, [r5, #0x8]
 *   @0xdbbb4 ldr r3, [pc, #0x68c]
 *   @0xdbbb8 ldr r5, [r6, #0x4c]
 *   @0xdbbbc add r3, pc, r3
 *   @0xdbbc0 str r3, [sp, #0x8]
 *   @0xdbbc4 ldr r3, [pc, #0x680]
 *   @0xdbbc8 add r3, pc, r3
 *   @0xdbbcc str r3, [sp, #0xc]
 *   @0xdbbd0 b 0xdbe00 <_Z14vmGetCallStackv+0x4cc>
 *   @0xdbbd4 ldr r1, [r4]
 *   @0xdbbd8 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0xdbbdc add r2, sp, #56
 *   @0xdbbe0 mov r3, #0
 *   @0xdbbe4 ldr r1, [r4, #0x20]
 *   @0xdbbe8 str r3, [r2, #-0x10]!
 *   @0xdbbec bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0xdbbf0 ldr r11, [r4, #0x24]
 *   @0xdbbf4 cmp r11, #0
 *   @0xdbbf8 ldreq r7, [sp, #0x34]
 *   @0xdbbfc mov r8, r0
 *   @0xdbc00 beq 0xdbcac <_Z14vmGetCallStackv+0x378>
 *   @0xdbc04 mov r0, r11
 *   @0xdbc08 bl 0xb6538 <strlen@plt>
 *   @0xdbc0c ldr r2, [sp, #0x34]
 *   @0xdbc10 ldr r3, [sp, #0x30]
 *   @0xdbc14 add r1, r0, #1
 *   @0xdbc18 mov r7, r0
 *   @0xdbc1c mvn r0, r2
 *   @0xdbc20 add r0, r3, r0
 *   @0xdbc24 cmp r1, r0
 *   @0xdbc28 ble 0xdbc90 <_Z14vmGetCallStackv+0x35c>
 *   @0xdbc2c cmp r3, #0
 *   @0xdbc30 add r2, r1, r2
 *   @0xdbc34 ldr r9, [sp, #0x2c]
 *   @0xdbc38 moveq r3, r1
 *   @0xdbc3c add r3, r3, r3, lsl #1
 *   @0xdbc40 add r3, r3, r3, lsr #31
 *   @0xdbc44 asr r3, r3, #1
 *   @0xdbc48 cmp r3, r2
 *   @0xdbc4c addlt r2, r2, r2, lsl #1
 *   @0xdbc50 addlt r2, r2, r2, lsr #31
 *   @0xdbc54 asrlt r3, r2, #1
 *   @0xdbc58 str r3, [sp, #0x4]
 *   @0xdbc5c mov r0, r3
 *   @0xdbc60 bl 0xcef4c <_Z7YYAlloci>
 *   @0xdbc64 ldr r2, [sp, #0x30]
 *   @0xdbc68 mov r1, r9
 *   @0xdbc6c str r0, [sp, #0x2c]
 *   @0xdbc70 bl 0xb65bc <memcpy@plt>
 *   @0xdbc74 ldr r3, [sp, #0x4]
 *   @0xdbc78 cmp r9, #0
 *   @0xdbc7c str r3, [sp, #0x30]
 *   @0xdbc80 beq 0xdbc8c <_Z14vmGetCallStackv+0x358>
 *   @0xdbc84 mov r0, r9
 *   @0xdbc88 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdbc8c ldr r2, [sp, #0x34]
 *   @0xdbc90 ldr r0, [sp, #0x2c]
 *   @0xdbc94 mov r1, r11
 *   @0xdbc98 add r0, r0, r2
 *   @0xdbc9c bl 0xb65a4 <strcpy@plt>
 *   @0xdbca0 ldr r3, [sp, #0x34]
 *   @0xdbca4 add r7, r7, r3
 *   @0xdbca8 str r7, [sp, #0x34]
 *   @0xdbcac ldr r3, [sp, #0x30]
 *   @0xdbcb0 mvn r2, r7
 *   @0xdbcb4 add r2, r3, r2
 *   @0xdbcb8 cmp r2, #1
 *   @0xdbcbc bgt 0xdbd1c <_Z14vmGetCallStackv+0x3e8>
 *   @0xdbcc0 cmp r3, #0
 *   @0xdbcc4 add r7, r7, #2
 *   @0xdbcc8 addne r3, r3, r3, lsl #1
 *   @0xdbccc moveq r9, #3
 *   @0xdbcd0 addne r3, r3, r3, lsr #31
 *   @0xdbcd4 asrne r9, r3, #1
 *   @0xdbcd8 cmp r7, r9
 *   @0xdbcdc addgt r7, r7, r7, lsl #1
 *   @0xdbce0 addgt r7, r7, r7, lsr #31
 *   @0xdbce4 asrgt r9, r7, #1
 *   @0xdbce8 ldr r7, [sp, #0x2c]
 *   @0xdbcec mov r0, r9
 *   @0xdbcf0 bl 0xcef4c <_Z7YYAlloci>
 *   @0xdbcf4 ldr r2, [sp, #0x30]
 *   @0xdbcf8 mov r1, r7
 *   @0xdbcfc str r0, [sp, #0x2c]
 *   @0xdbd00 bl 0xb65bc <memcpy@plt>
 *   @0xdbd04 cmp r7, #0
 *   @0xdbd08 str r9, [sp, #0x30]
 *   @0xdbd0c beq 0xdbd18 <_Z14vmGetCallStackv+0x3e4>
 *   @0xdbd10 mov r0, r7
 *   @0xdbd14 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdbd18 ldr r7, [sp, #0x34]
 *   @0xdbd1c ldr r0, [sp, #0x8]
 *   @0xdbd20 mov r1, r8
 *   @0xdbd24 ldr r3, [sp, #0x2c]
 *   @0xdbd28 ldrh r2, [r0]
 *   @0xdbd2c mov r0, r10
 *   @0xdbd30 strh r2, [r3, r7]
 *   @0xdbd34 ldr r3, [sp, #0x34]
 *   @0xdbd38 add r3, r3, #1
 *   @0xdbd3c str r3, [sp, #0x34]
 *   @0xdbd40 bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0xdbd44 ldr r3, [r0, #0x8]
 *   @0xdbd48 mov r8, r0
 *   @0xdbd4c ldr r9, [r0, #0x4]
 *   @0xdbd50 mvn r2, r3
 *   @0xdbd54 add r2, r9, r2
 *   @0xdbd58 cmp r2, #1
 *   @0xdbd5c bgt 0xdbdbc <_Z14vmGetCallStackv+0x488>
 *   @0xdbd60 cmp r9, #0
 *   @0xdbd64 add r3, r3, #2
 *   @0xdbd68 addne r9, r9, r9, lsl #1
 *   @0xdbd6c ldr r7, [r8]
 *   @0xdbd70 moveq r9, #3
 *   @0xdbd74 addne r9, r9, r9, lsr #31
 *   @0xdbd78 asrne r9, r9, #1
 *   @0xdbd7c cmp r3, r9
 *   @0xdbd80 addgt r3, r3, r3, lsl #1
 *   @0xdbd84 addgt r3, r3, r3, lsr #31
 *   @0xdbd88 asrgt r9, r3, #1
 *   @0xdbd8c mov r0, r9
 *   @0xdbd90 bl 0xcef4c <_Z7YYAlloci>
 *   @0xdbd94 ldr r2, [r8, #0x4]
 *   @0xdbd98 mov r1, r7
 *   @0xdbd9c str r0, [r8]
 *   @0xdbda0 bl 0xb65bc <memcpy@plt>
 *   @0xdbda4 cmp r7, #0
 *   @0xdbda8 str r9, [r8, #0x4]
 *   @0xdbdac beq 0xdbdb8 <_Z14vmGetCallStackv+0x484>
 *   @0xdbdb0 mov r0, r7
 *   @0xdbdb4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdbdb8 ldr r3, [r8, #0x8]
 *   @0xdbdbc ldr r0, [sp, #0xc]
 *   @0xdbdc0 ldr r2, [r8]
 *   @0xdbdc4 ldrh r1, [r0]
 *   @0xdbdc8 strh r1, [r2, r3]
 *   @0xdbdcc ldr r0, [sp, #0x28]
 *   @0xdbdd0 ldr r3, [r8, #0x8]
 *   @0xdbdd4 cmp r0, #0
 *   @0xdbdd8 add r3, r3, #1
 *   @0xdbddc str r3, [r8, #0x8]
 *   @0xdbde0 beq 0xdbde8 <_Z14vmGetCallStackv+0x4b4>
 *   @0xdbde4 bl 0xb655c <free@plt>
 *   @0xdbde8 ldr r2, [r4, #0xc]
 *   @0xdbdec sub r5, r5, #1
 *   @0xdbdf0 ldr r4, [r6, #0x40]
 *   @0xdbdf4 ldr r3, [r6, #0x8]
 *   @0xdbdf8 rsb r4, r2, r4
 *   @0xdbdfc add r4, r3, r4
 *   @0xdbe00 cmp r5, #0
 *   @0xdbe04 ble 0xdc008 <_Z14vmGetCallStackv+0x6d4>
 *   @0xdbe08 ldr r3, [r4, #0x18]
 *   @0xdbe0c cmp r3, #0
 *   @0xdbe10 beq 0xdc008 <_Z14vmGetCallStackv+0x6d4>
 *   @0xdbe14 ldr r0, [r4, #0x1c]
 *   @0xdbe18 cmp r0, #0
 *   @0xdbe1c bne 0xdbbd4 <_Z14vmGetCallStackv+0x2a0>
 *   @0xdbe20 ldr r9, [r4, #0x24]
 *   @0xdbe24 cmp r9, #0
 *   @0xdbe28 ldreq r7, [sp, #0x34]
 *   @0xdbe2c beq 0xdbed8 <_Z14vmGetCallStackv+0x5a4>
 *   @0xdbe30 mov r0, r9
 *   @0xdbe34 bl 0xb6538 <strlen@plt>
 *   @0xdbe38 ldr r2, [sp, #0x34]
 *   @0xdbe3c ldr r3, [sp, #0x30]
 *   @0xdbe40 add r1, r0, #1
 *   @0xdbe44 mov r7, r0
 *   @0xdbe48 mvn r0, r2
 *   @0xdbe4c add r0, r3, r0
 *   @0xdbe50 cmp r1, r0
 *   @0xdbe54 ble 0xdbebc <_Z14vmGetCallStackv+0x588>
 *   @0xdbe58 cmp r3, #0
 *   @0xdbe5c add r2, r1, r2
 *   @0xdbe60 ldr r8, [sp, #0x2c]
 *   @0xdbe64 moveq r3, r1
 *   @0xdbe68 add r3, r3, r3, lsl #1
 *   @0xdbe6c add r3, r3, r3, lsr #31
 *   @0xdbe70 asr r3, r3, #1
 *   @0xdbe74 cmp r3, r2
 *   @0xdbe78 addlt r2, r2, r2, lsl #1
 *   @0xdbe7c addlt r2, r2, r2, lsr #31
 *   @0xdbe80 asrlt r3, r2, #1
 *   @0xdbe84 str r3, [sp, #0x4]
 *   @0xdbe88 mov r0, r3
 *   @0xdbe8c bl 0xcef4c <_Z7YYAlloci>
 *   @0xdbe90 ldr r2, [sp, #0x30]
 *   @0xdbe94 mov r1, r8
 *   @0xdbe98 str r0, [sp, #0x2c]
 *   @0xdbe9c bl 0xb65bc <memcpy@plt>
 *   @0xdbea0 ldr r3, [sp, #0x4]
 *   @0xdbea4 cmp r8, #0
 *   @0xdbea8 str r3, [sp, #0x30]
 *   @0xdbeac beq 0xdbeb8 <_Z14vmGetCallStackv+0x584>
 *   @0xdbeb0 mov r0, r8
 *   @0xdbeb4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdbeb8 ldr r2, [sp, #0x34]
 *   @0xdbebc ldr r0, [sp, #0x2c]
 *   @0xdbec0 mov r1, r9
 *   @0xdbec4 add r0, r0, r2
 *   @0xdbec8 bl 0xb65a4 <strcpy@plt>
 *   @0xdbecc ldr r3, [sp, #0x34]
 *   @0xdbed0 add r7, r7, r3
 *   @0xdbed4 str r7, [sp, #0x34]
 *   @0xdbed8 ldr r3, [sp, #0x30]
 *   @0xdbedc mvn r2, r7
 *   @0xdbee0 add r2, r3, r2
 *   @0xdbee4 cmp r2, #1
 *   @0xdbee8 bgt 0xdbf48 <_Z14vmGetCallStackv+0x614>
 *   @0xdbeec cmp r3, #0
 *   @0xdbef0 add r7, r7, #2
 *   @0xdbef4 addne r3, r3, r3, lsl #1
 *   @0xdbef8 moveq r8, #3
 *   @0xdbefc addne r3, r3, r3, lsr #31
 *   @0xdbf00 asrne r8, r3, #1
 *   @0xdbf04 cmp r7, r8
 *   @0xdbf08 addgt r7, r7, r7, lsl #1
 *   @0xdbf0c addgt r7, r7, r7, lsr #31
 *   @0xdbf10 asrgt r8, r7, #1
 *   @0xdbf14 ldr r7, [sp, #0x2c]
 *   @0xdbf18 mov r0, r8
 *   @0xdbf1c bl 0xcef4c <_Z7YYAlloci>
 *   @0xdbf20 ldr r2, [sp, #0x30]
 *   @0xdbf24 mov r1, r7
 *   @0xdbf28 str r0, [sp, #0x2c]
 *   @0xdbf2c bl 0xb65bc <memcpy@plt>
 *   @0xdbf30 cmp r7, #0
 *   @0xdbf34 str r8, [sp, #0x30]
 *   @0xdbf38 beq 0xdbf44 <_Z14vmGetCallStackv+0x610>
 *   @0xdbf3c mov r0, r7
 *   @0xdbf40 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdbf44 ldr r7, [sp, #0x34]
 *   @0xdbf48 ldr r1, [sp, #0x10]
 *   @0xdbf4c mov r0, r10
 *   @0xdbf50 ldr r3, [sp, #0x2c]
 *   @0xdbf54 ldrh r2, [r1]
 *   @0xdbf58 mvn r1, #0
 *   @0xdbf5c strh r2, [r3, r7]
 *   @0xdbf60 ldr r3, [sp, #0x34]
 *   @0xdbf64 add r3, r3, #1
 *   @0xdbf68 str r3, [sp, #0x34]
 *   @0xdbf6c bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0xdbf70 ldr r3, [r0, #0x8]
 *   @0xdbf74 mov r8, r0
 *   @0xdbf78 ldr r9, [r0, #0x4]
 *   @0xdbf7c mvn r2, r3
 *   @0xdbf80 add r2, r9, r2
 *   @0xdbf84 cmp r2, #1
 *   @0xdbf88 bgt 0xdbfe8 <_Z14vmGetCallStackv+0x6b4>
 *   @0xdbf8c cmp r9, #0
 *   @0xdbf90 add r3, r3, #2
 *   @0xdbf94 addne r9, r9, r9, lsl #1
 *   @0xdbf98 ldr r7, [r8]
 *   @0xdbf9c moveq r9, #3
 *   @0xdbfa0 addne r9, r9, r9, lsr #31
 *   @0xdbfa4 asrne r9, r9, #1
 *   @0xdbfa8 cmp r3, r9
 *   @0xdbfac addgt r3, r3, r3, lsl #1
 *   @0xdbfb0 addgt r3, r3, r3, lsr #31
 *   @0xdbfb4 asrgt r9, r3, #1
 *   @0xdbfb8 mov r0, r9
 *   @0xdbfbc bl 0xcef4c <_Z7YYAlloci>
 *   @0xdbfc0 ldr r2, [r8, #0x4]
 *   @0xdbfc4 mov r1, r7
 *   @0xdbfc8 str r0, [r8]
 *   @0xdbfcc bl 0xb65bc <memcpy@plt>
 *   @0xdbfd0 cmp r7, #0
 *   @0xdbfd4 str r9, [r8, #0x4]
 *   @0xdbfd8 beq 0xdbfe4 <_Z14vmGetCallStackv+0x6b0>
 *   @0xdbfdc mov r0, r7
 *   @0xdbfe0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdbfe4 ldr r3, [r8, #0x8]
 *   @0xdbfe8 ldr r0, [sp, #0x14]
 *   @0xdbfec ldr r2, [r8]
 *   @0xdbff0 ldrh r1, [r0]
 *   @0xdbff4 strh r1, [r2, r3]
 *   @0xdbff8 ldr r3, [r8, #0x8]
 *   @0xdbffc add r3, r3, #1
 *   @0xdc000 str r3, [r8, #0x8]
 *   @0xdc004 b 0xdbde8 <_Z14vmGetCallStackv+0x4b4>
 *   @0xdc008 ldr r6, [r6, #0x4]
 *   @0xdc00c cmp r6, #0
 *   @0xdc010 bne 0xdb9ac <_Z14vmGetCallStackv+0x78>
 *   @0xdc014 ldr r3, [sp, #0x34]
 *   @0xdc018 cmp r3, #0
 *   @0xdc01c mov r3, #0
 *   @0xdc020 addeq r0, sp, #52
 *   @0xdc024 str r3, [sp, #0x34]
 *   @0xdc028 ldrne r0, [sp, #0x2c]
 *   @0xdc02c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xdc030 mov r4, r0
 *   @0xdc034 ldr r0, [sp, #0x2c]
 *   @0xdc038 cmp r0, #0
 *   @0xdc03c beq 0xdc044 <_Z14vmGetCallStackv+0x710>
 *   @0xdc040 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdc044 mov r0, r4
 *   @0xdc048 add sp, sp, #60
 *   @0xdc04c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xdc050 ldr r7, [r6, #0x34]
 *   @0xdc054 cmp r7, #0
 *   @0xdc058 ldreq r4, [sp, #0x34]
 *   @0xdc05c beq 0xdc100 <_Z14vmGetCallStackv+0x7cc>
 *   @0xdc060 mov r0, r7
 *   @0xdc064 bl 0xb6538 <strlen@plt>
 *   @0xdc068 ldr r2, [sp, #0x34]
 *   @0xdc06c ldr r3, [sp, #0x30]
 *   @0xdc070 add r1, r0, #1
 *   @0xdc074 mov r4, r0
 *   @0xdc078 mvn r0, r2
 *   @0xdc07c add r0, r3, r0
 *   @0xdc080 cmp r1, r0
 *   @0xdc084 ble 0xdc0e4 <_Z14vmGetCallStackv+0x7b0>
 *   @0xdc088 cmp r3, #0
 *   @0xdc08c add r2, r1, r2
 *   @0xdc090 ldr r5, [sp, #0x2c]
 *   @0xdc094 moveq r3, r1
 *   @0xdc098 add r3, r3, r3, lsl #1
 *   @0xdc09c add r3, r3, r3, lsr #31
 *   @0xdc0a0 asr r8, r3, #1
 *   @0xdc0a4 cmp r8, r2
 *   @0xdc0a8 addlt r2, r2, r2, lsl #1
 *   @0xdc0ac addlt r2, r2, r2, lsr #31
 *   @0xdc0b0 asrlt r8, r2, #1
 *   @0xdc0b4 mov r0, r8
 *   @0xdc0b8 bl 0xcef4c <_Z7YYAlloci>
 *   @0xdc0bc ldr r2, [sp, #0x30]
 *   @0xdc0c0 mov r1, r5
 *   @0xdc0c4 str r0, [sp, #0x2c]
 *   @0xdc0c8 bl 0xb65bc <memcpy@plt>
 *   @0xdc0cc cmp r5, #0
 *   @0xdc0d0 str r8, [sp, #0x30]
 *   @0xdc0d4 beq 0xdc0e0 <_Z14vmGetCallStackv+0x7ac>
 *   @0xdc0d8 mov r0, r5
 *   @0xdc0dc bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdc0e0 ldr r2, [sp, #0x34]
 *   @0xdc0e4 ldr r0, [sp, #0x2c]
 *   @0xdc0e8 mov r1, r7
 *   @0xdc0ec add r0, r0, r2
 *   @0xdc0f0 bl 0xb65a4 <strcpy@plt>
 *   @0xdc0f4 ldr r3, [sp, #0x34]
 *   @0xdc0f8 add r4, r4, r3
 *   @0xdc0fc str r4, [sp, #0x34]
 *   @0xdc100 ldr r3, [sp, #0x30]
 *   @0xdc104 mvn r2, r4
 *   @0xdc108 add r2, r3, r2
 *   @0xdc10c cmp r2, #1
 *   @0xdc110 bgt 0xdc170 <_Z14vmGetCallStackv+0x83c>
 *   @0xdc114 cmp r3, #0
 *   @0xdc118 add r4, r4, #2
 *   @0xdc11c addne r3, r3, r3, lsl #1
 *   @0xdc120 moveq r5, #3
 *   @0xdc124 addne r3, r3, r3, lsr #31
 *   @0xdc128 asrne r5, r3, #1
 *   @0xdc12c cmp r4, r5
 *   @0xdc130 addgt r4, r4, r4, lsl #1
 *   @0xdc134 addgt r4, r4, r4, lsr #31
 *   @0xdc138 asrgt r5, r4, #1
 *   @0xdc13c ldr r4, [sp, #0x2c]
 *   @0xdc140 mov r0, r5
 *   @0xdc144 bl 0xcef4c <_Z7YYAlloci>
 *   @0xdc148 ldr r2, [sp, #0x30]
 *   @0xdc14c mov r1, r4
 *   @0xdc150 str r0, [sp, #0x2c]
 *   @0xdc154 bl 0xb65bc <memcpy@plt>
 *   @0xdc158 cmp r4, #0
 *   @0xdc15c str r5, [sp, #0x30]
 *   @0xdc160 beq 0xdc16c <_Z14vmGetCallStackv+0x838>
 *   @0xdc164 mov r0, r4
 *   @0xdc168 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdc16c ldr r4, [sp, #0x34]
 *   @0xdc170 ldr r1, [sp, #0x20]
 *   @0xdc174 mov r0, r10
 *   @0xdc178 ldr r3, [sp, #0x2c]
 *   @0xdc17c ldrh r2, [r1]
 *   @0xdc180 mvn r1, #0
 *   @0xdc184 strh r2, [r3, r4]
 *   @0xdc188 ldr r3, [sp, #0x34]
 *   @0xdc18c add r3, r3, #1
 *   @0xdc190 str r3, [sp, #0x34]
 *   @0xdc194 bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0xdc198 ldmib r0, {r2, r3}
 *   @0xdc19c mov r5, r0
 *   @0xdc1a0 mvn r1, r3
 *   @0xdc1a4 add r1, r2, r1
 *   @0xdc1a8 cmp r1, #1
 *   @0xdc1ac bgt 0xdc20c <_Z14vmGetCallStackv+0x8d8>
 *   @0xdc1b0 cmp r2, #0
 *   @0xdc1b4 add r3, r3, #2
 *   @0xdc1b8 addne r2, r2, r2, lsl #1
 *   @0xdc1bc ldr r4, [r5]
 *   @0xdc1c0 moveq r7, #3
 *   @0xdc1c4 addne r2, r2, r2, lsr #31
 *   @0xdc1c8 asrne r7, r2, #1
 *   @0xdc1cc cmp r3, r7
 *   @0xdc1d0 addgt r3, r3, r3, lsl #1
 *   @0xdc1d4 addgt r3, r3, r3, lsr #31
 *   @0xdc1d8 asrgt r7, r3, #1
 *   @0xdc1dc mov r0, r7
 *   @0xdc1e0 bl 0xcef4c <_Z7YYAlloci>
 *   @0xdc1e4 ldr r2, [r5, #0x4]
 *   @0xdc1e8 mov r1, r4
 *   @0xdc1ec str r0, [r5]
 *   @0xdc1f0 bl 0xb65bc <memcpy@plt>
 *   @0xdc1f4 cmp r4, #0
 *   @0xdc1f8 str r7, [r5, #0x4]
 *   @0xdc1fc beq 0xdc208 <_Z14vmGetCallStackv+0x8d4>
 *   @0xdc200 mov r0, r4
 *   @0xdc204 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdc208 ldr r3, [r5, #0x8]
 *   @0xdc20c ldr r2, [r5]
 *   @0xdc210 ldr r0, [sp, #0x24]
 *   @0xdc214 b 0xdbb9c <_Z14vmGetCallStackv+0x268>
 *   @0xdc218 ldr r0, [pc, #0x30]
 *   @0xdc21c add r0, pc, r0
 *   @0xdc220 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xdc224 mov r4, r0
 *   @0xdc228 b 0xdc034 <_Z14vmGetCallStackv+0x700>
 *   @0xdc22c eorseq r2, r1, r8, ror #4
 *   @0xdc230 eoreq r7, r5, r12, lsr #6
 *   @0xdc234 eoreq r7, r5, r4, lsr #6
 *   @0xdc238 eoreq r7, r5, r4, lsl r3
 *   @0xdc23c eoreq r7, r5, r12, lsl #6
 *   @0xdc240 .word 0x002572fc
 *   @0xdc244 .word 0x002572f4
 *   @0xdc248 .word 0x002570d8
 *   @0xdc24c .word 0x002570d0
 *   @0xdc250 eoreq r6, r5, r0, ror #20
 *
 * ══ §6/13 b2Distance  0x2c3fa0  size 2248  562 条（0x2c3fa0..0x2c4868）
 * @func 0x2c3fa0 0x2c4868  size 2248  562 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2c3fb8→0x759128, 0x2c4398→0x759124, 0x2c4428→0x759120, 0x2c45d8→0x7593b4
 * 调用序列: 0xb6700×4 / b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*)+0x7c / b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*)+0x704 / b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*)+0x24c / b2Simplex::Solve3() / b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*)+0x66c / b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*)+0x660 / b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*)+0x5dc
 * 字段偏移 top8: 0x84×11 / 0x10×4 / 0x4×3 / 0x2c×3 / 0x1c×3 / 0x30×2 / 0x14×2 / 0x20×2
 * VFP 指令 314 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c3fa0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c3fa4 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2c3fa8 mov r5, r1
 *   @0x2c3fac vldr s21, [r2, #56]
 *   @0x2c3fb0 ldr r7, [pc, #0x5e4]
 *   @0x2c3fb4 mov r4, r2
 *   @0x2c3fb8 ldr r1, [pc, #0x5e0]
 *   @0x2c3fbc vldr s20, [r2, #60]
 *   @0x2c3fc0 add r7, pc, r7
 *   @0x2c3fc4 ldrh r3, [r5, #4]
 *   @0x2c3fc8 sub sp, sp, #140
 *   @0x2c3fcc mov r8, r0
 *   @0x2c3fd0 ldr r2, [r7, r1]
 *   @0x2c3fd4 cmp r3, #0
 *   @0x2c3fd8 str r3, [sp, #0x84]
 *   @0x2c3fdc vldr s19, [r4, #64]
 *   @0x2c3fe0 vldr s17, [r4, #68]
 *   @0x2c3fe4 vldr s23, [r4, #72]
 *   @0x2c3fe8 ldr r3, [r2]
 *   @0x2c3fec vldr s22, [r4, #76]
 *   @0x2c3ff0 vldr s18, [r4, #80]
 *   @0x2c3ff4 vldr s16, [r4, #84]
 *   @0x2c3ff8 add r3, r3, #1
 *   @0x2c3ffc str r3, [r2]
 *   @0x2c4000 beq 0x2c4118 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x178>
 *   @0x2c4004 ldr r10, [r4, #0x10]
 *   @0x2c4008 sub r2, r5, #1
 *   @0x2c400c ldr r6, [r4, #0x2c]
 *   @0x2c4010 add r3, sp, #56
 *   @0x2c4014 mov r1, #0
 *   @0x2c4018 mov r11, #0
 *   @0x2c401c add r2, r2, #1
 *   @0x2c4020 ldrb r12, [r2, #0x6]
 *   @0x2c4024 ldrb r0, [r2, #0x9]
 *   @0x2c4028 add r1, r1, #1
 *   @0x2c402c add r3, r3, #36
 *   @0x2c4030 str r12, [r3, #-0x28]
 *   @0x2c4034 add r12, r10, r12, lsl #3
 *   @0x2c4038 str r0, [r3, #-0x24]
 *   @0x2c403c add r0, r6, r0, lsl #3
 *   @0x2c4040 vldr s13, [r12, #4]
 *   @0x2c4044 vldr s15, [r0, #4]
 *   @0x2c4048 vmul.f32 s12, s13, s19
 *   @0x2c404c vldr s10, [r12]
 *   @0x2c4050 vldr s11, [r0]
 *   @0x2c4054 str r11, [r3, #-0x2c]
 *   @0x2c4058 vmul.f32 s14, s15, s18
 *   @0x2c405c vmul.f32 s13, s13, s17
 *   @0x2c4060 vmul.f32 s15, s15, s16
 *   @0x2c4064 vnmls.f32 s12, s10, s17
 *   @0x2c4068 vmla.f32 s13, s10, s19
 *   @0x2c406c vnmls.f32 s14, s11, s16
 *   @0x2c4070 vmla.f32 s15, s11, s18
 *   @0x2c4074 vadd.f32 s12, s21, s12
 *   @0x2c4078 vadd.f32 s13, s20, s13
 *   @0x2c407c vstr s12, [r3, #-68]
 *   @0x2c4080 vadd.f32 s14, s14, s23
 *   @0x2c4084 vstr s13, [r3, #-64]
 *   @0x2c4088 vadd.f32 s15, s15, s22
 *   @0x2c408c vstr s14, [r3, #-60]
 *   @0x2c4090 vstr s15, [r3, #-56]
 *   @0x2c4094 vsub.f32 s14, s14, s12
 *   @0x2c4098 vsub.f32 s15, s15, s13
 *   @0x2c409c vstr s14, [r3, #-52]
 *   @0x2c40a0 vstr s15, [r3, #-48]
 *   @0x2c40a4 ldr r9, [sp, #0x84]
 *   @0x2c40a8 cmp r1, r9
 *   @0x2c40ac blt 0x2c401c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x7c>
 *   @0x2c40b0 cmp r9, #1
 *   @0x2c40b4 ble 0x2c46a4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x704>
 *   @0x2c40b8 cmp r9, #3
 *   @0x2c40bc vldr s24, [r5]
 *   @0x2c40c0 beq 0x2c4768 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x7c8>
 *   @0x2c40c4 vldr s12, [sp, #44]
 *   @0x2c40c8 vldr s14, [sp, #80]
 *   @0x2c40cc vsub.f32 s14, s12, s14
 *   @0x2c40d0 vldr s13, [sp, #40]
 *   @0x2c40d4 vldr s15, [sp, #76]
 *   @0x2c40d8 vmul.f32 s14, s14, s14
 *   @0x2c40dc vsub.f32 s15, s13, s15
 *   @0x2c40e0 vmla.f32 s14, s15, s15
 *   @0x2c40e4 vsqrt.f32 s15, s14
 *   @0x2c40e8 vcmp.f32 s15, s15
 *   @0x2c40ec vmrs APSR_nzcv, fpscr
 *   @0x2c40f0 bne 0x2c4858 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x8b8>
 *   @0x2c40f4 vmov.f32 s14, #5.000000e-01
 *   @0x2c40f8 vmul.f32 s14, s24, s14
 *   @0x2c40fc vcmpe.f32 s14, s15
 *   @0x2c4100 vmrs APSR_nzcv, fpscr
 *   @0x2c4104 bgt 0x2c4118 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x178>
 *   @0x2c4108 vadd.f32 s24, s24, s24
 *   @0x2c410c vcmpe.f32 s24, s15
 *   @0x2c4110 vmrs APSR_nzcv, fpscr
 *   @0x2c4114 bpl 0x2c4690 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x6f0>
 *   @0x2c4118 ldr r3, [r4, #0x2c]
 *   @0x2c411c vldr s15, [r3, #4]
 *   @0x2c4120 ldr r2, [r4, #0x10]
 *   @0x2c4124 vmul.f32 s14, s15, s18
 *   @0x2c4128 vldr s13, [r2, #4]
 *   @0x2c412c vldr s11, [r3]
 *   @0x2c4130 vldr s10, [r2]
 *   @0x2c4134 mov r3, #1
 *   @0x2c4138 mov r9, r3
 *   @0x2c413c str r3, [sp, #0x84]
 *   @0x2c4140 mov r3, #0
 *   @0x2c4144 str r3, [sp, #0x34]
 *   @0x2c4148 str r3, [sp, #0x38]
 *   @0x2c414c mov r3, #1065353216
 *   @0x2c4150 str r3, [sp, #0x30]
 *   @0x2c4154 vmul.f32 s12, s13, s19
 *   @0x2c4158 vmul.f32 s15, s15, s16
 *   @0x2c415c vmul.f32 s13, s13, s17
 *   @0x2c4160 vnmls.f32 s12, s10, s17
 *   @0x2c4164 vmla.f32 s13, s10, s19
 *   @0x2c4168 vnmls.f32 s14, s11, s16
 *   @0x2c416c vmla.f32 s15, s11, s18
 *   @0x2c4170 vadd.f32 s12, s21, s12
 *   @0x2c4174 vadd.f32 s13, s20, s13
 *   @0x2c4178 vstr s12, [sp, #24]
 *   @0x2c417c vadd.f32 s14, s14, s23
 *   @0x2c4180 vstr s13, [sp, #28]
 *   @0x2c4184 vadd.f32 s15, s15, s22
 *   @0x2c4188 vstr s14, [sp, #32]
 *   @0x2c418c vstr s15, [sp, #36]
 *   @0x2c4190 vsub.f32 s14, s14, s12
 *   @0x2c4194 vsub.f32 s15, s15, s13
 *   @0x2c4198 vstr s14, [sp, #40]
 *   @0x2c419c vstr s15, [sp, #44]
 *   @0x2c41a0 vneg.f32 s26, s19
 *   @0x2c41a4 mov r6, #0
 *   @0x2c41a8 vldr s24, [pc, #996]
 *   @0x2c41ac vneg.f32 s25, s18
 *   @0x2c41b0 cmp r9, #0
 *   @0x2c41b4 ble 0x2c41ec <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x24c>
 *   @0x2c41b8 add r2, sp, #24
 *   @0x2c41bc lsl r11, r9, #2
 *   @0x2c41c0 add r1, sp, #12
 *   @0x2c41c4 mov r10, sp
 *   @0x2c41c8 mov r3, #0
 *   @0x2c41cc ldr r12, [r2, #0x1c]
 *   @0x2c41d0 add r2, r2, #36
 *   @0x2c41d4 ldr r0, [r2, #-0x4]
 *   @0x2c41d8 str r12, [r10, r3]
 *   @0x2c41dc str r0, [r1, r3]
 *   @0x2c41e0 add r3, r3, #4
 *   @0x2c41e4 cmp r3, r11
 *   @0x2c41e8 bne 0x2c41cc <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x22c>
 *   @0x2c41ec cmp r9, #2
 *   @0x2c41f0 beq 0x2c45c8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x628>
 *   @0x2c41f4 cmp r9, #3
 *   @0x2c41f8 bne 0x2c45b4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x614>
 *   @0x2c41fc add r0, sp, #24
 *   @0x2c4200 bl 0x2c3d14 <_ZN9b2Simplex6Solve3Ev>
 *   @0x2c4204 ldr r1, [sp, #0x84]
 *   @0x2c4208 cmp r1, #3
 *   @0x2c420c beq 0x2c45c0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x620>
 *   @0x2c4210 cmp r1, #1
 *   @0x2c4214 beq 0x2c45ec <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x64c>
 *   @0x2c4218 cmp r1, #2
 *   @0x2c421c bne 0x2c45d8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x638>
 *   @0x2c4220 vldr s14, [sp, #44]
 *   @0x2c4224 vldr s9, [sp, #80]
 *   @0x2c4228 vsub.f32 s9, s9, s14
 *   @0x2c422c vldr s13, [sp, #40]
 *   @0x2c4230 vldr s12, [sp, #76]
 *   @0x2c4234 vnmul.f32 s15, s13, s9
 *   @0x2c4238 vsub.f32 s12, s12, s13
 *   @0x2c423c vnmla.f32 s15, s14, s12
 *   @0x2c4240 vcmpe.f32 s15, #0
 *   @0x2c4244 vmrs APSR_nzcv, fpscr
 *   @0x2c4248 vneggt.f32 s9, s9
 *   @0x2c424c vnegle.f32 s12, s12
 *   @0x2c4250 vmul.f32 s15, s12, s12
 *   @0x2c4254 vmla.f32 s15, s9, s9
 *   @0x2c4258 vcmpe.f32 s15, s24
 *   @0x2c425c vmrs APSR_nzcv, fpscr
 *   @0x2c4260 bmi 0x2c45c0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x620>
 *   @0x2c4264 vneg.f32 s11, s12
 *   @0x2c4268 ldr r10, [r4, #0x10]
 *   @0x2c426c vldr s13, [r10, #4]
 *   @0x2c4270 ldr r0, [r4, #0x14]
 *   @0x2c4274 add r1, r1, r1, lsl #3
 *   @0x2c4278 add r3, sp, #24
 *   @0x2c427c cmp r0, #1
 *   @0x2c4280 vldr s14, [r10]
 *   @0x2c4284 vmul.f32 s10, s11, s17
 *   @0x2c4288 add r1, r3, r1, lsl #2
 *   @0x2c428c vneg.f32 s15, s9
 *   @0x2c4290 vmul.f32 s11, s11, s19
 *   @0x2c4294 vmla.f32 s10, s15, s26
 *   @0x2c4298 vmla.f32 s11, s15, s17
 *   @0x2c429c vmul.f32 s13, s10, s13
 *   @0x2c42a0 vmla.f32 s13, s11, s14
 *   @0x2c42a4 ble 0x2c460c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x66c>
 *   @0x2c42a8 add r3, r10, #8
 *   @0x2c42ac mov r2, #0
 *   @0x2c42b0 mov r12, #1
 *   @0x2c42b4 vldr s15, [r3, #4]
 *   @0x2c42b8 vldr s14, [r3]
 *   @0x2c42bc add r3, r3, #8
 *   @0x2c42c0 vmul.f32 s15, s10, s15
 *   @0x2c42c4 vmla.f32 s15, s11, s14
 *   @0x2c42c8 vcmpe.f32 s13, s15
 *   @0x2c42cc vmrs APSR_nzcv, fpscr
 *   @0x2c42d0 movmi r2, r12
 *   @0x2c42d4 add r12, r12, #1
 *   @0x2c42d8 vmovmi.f32 s13, s15
 *   @0x2c42dc cmp r12, r0
 *   @0x2c42e0 bne 0x2c42b4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x314>
 *   @0x2c42e4 lsl r3, r2, #3
 *   @0x2c42e8 add r10, r10, r3
 *   @0x2c42ec vldr s15, [r10, #4]
 *   @0x2c42f0 vmul.f32 s14, s15, s19
 *   @0x2c42f4 vldr s13, [r10]
 *   @0x2c42f8 ldr r11, [r4, #0x2c]
 *   @0x2c42fc ldr r10, [r4, #0x30]
 *   @0x2c4300 str r2, [r1, #0x1c]
 *   @0x2c4304 cmp r10, #1
 *   @0x2c4308 vmul.f32 s15, s15, s17
 *   @0x2c430c vmul.f32 s11, s12, s16
 *   @0x2c4310 vmla.f32 s15, s13, s19
 *   @0x2c4314 vnmls.f32 s14, s13, s17
 *   @0x2c4318 vmla.f32 s11, s9, s25
 *   @0x2c431c vmul.f32 s12, s12, s18
 *   @0x2c4320 vadd.f32 s10, s15, s20
 *   @0x2c4324 vadd.f32 s8, s14, s21
 *   @0x2c4328 vstr s10, [r1, #4]
 *   @0x2c432c vmla.f32 s12, s9, s16
 *   @0x2c4330 vstr s8, [r1]
 *   @0x2c4334 vldr s13, [r11, #4]
 *   @0x2c4338 vldr s15, [r11]
 *   @0x2c433c vmul.f32 s13, s11, s13
 *   @0x2c4340 vmla.f32 s13, s12, s15
 *   @0x2c4344 ble 0x2c4600 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x660>
 *   @0x2c4348 add r3, r11, #8
 *   @0x2c434c mov r0, #0
 *   @0x2c4350 mov r12, #1
 *   @0x2c4354 vldr s15, [r3, #4]
 *   @0x2c4358 vldr s14, [r3]
 *   @0x2c435c add r3, r3, #8
 *   @0x2c4360 vmul.f32 s15, s11, s15
 *   @0x2c4364 vmla.f32 s15, s12, s14
 *   @0x2c4368 vcmpe.f32 s13, s15
 *   @0x2c436c vmrs APSR_nzcv, fpscr
 *   @0x2c4370 movmi r0, r12
 *   @0x2c4374 add r12, r12, #1
 *   @0x2c4378 vmovmi.f32 s13, s15
 *   @0x2c437c cmp r12, r10
 *   @0x2c4380 bne 0x2c4354 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x3b4>
 *   @0x2c4384 lsl r3, r0, #3
 *   @0x2c4388 add r11, r11, r3
 *   @0x2c438c vldr s15, [r11, #4]
 *   @0x2c4390 vmul.f32 s14, s15, s18
 *   @0x2c4394 vldr s13, [r11]
 *   @0x2c4398 ldr r3, [pc, #0x204]
 *   @0x2c439c cmp r9, #0
 *   @0x2c43a0 str r0, [r1, #0x20]
 *   @0x2c43a4 add r6, r6, #1
 *   @0x2c43a8 vmul.f32 s15, s15, s16
 *   @0x2c43ac vnmls.f32 s14, s13, s16
 *   @0x2c43b0 vmla.f32 s15, s13, s18
 *   @0x2c43b4 vadd.f32 s14, s14, s23
 *   @0x2c43b8 vadd.f32 s15, s15, s22
 *   @0x2c43bc vstr s14, [r1, #8]
 *   @0x2c43c0 vstr s15, [r1, #12]
 *   @0x2c43c4 vsub.f32 s14, s14, s8
 *   @0x2c43c8 vsub.f32 s15, s15, s10
 *   @0x2c43cc vstr s14, [r1, #16]
 *   @0x2c43d0 vstr s15, [r1, #20]
 *   @0x2c43d4 ldr r3, [r7, r3]
 *   @0x2c43d8 ldr r1, [r3]
 *   @0x2c43dc add r1, r1, #1
 *   @0x2c43e0 str r1, [r3]
 *   @0x2c43e4 ble 0x2c457c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x5dc>
 *   @0x2c43e8 mov r3, #0
 *   @0x2c43ec mov r10, sp
 *   @0x2c43f0 mov r12, r3
 *   @0x2c43f4 b 0x2c4404 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x464>
 *   @0x2c43f8 cmp r12, r9
 *   @0x2c43fc add r3, r3, #4
 *   @0x2c4400 beq 0x2c457c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x5dc>
 *   @0x2c4404 ldr r1, [r10, r3]
 *   @0x2c4408 add r12, r12, #1
 *   @0x2c440c cmp r1, r2
 *   @0x2c4410 bne 0x2c43f8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x458>
 *   @0x2c4414 add r1, sp, #12
 *   @0x2c4418 ldr r1, [r1, r3]
 *   @0x2c441c cmp r1, r0
 *   @0x2c4420 bne 0x2c43f8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x458>
 *   @0x2c4424 ldr r9, [sp, #0x84]
 *   @0x2c4428 ldr r3, [pc, #0x178]
 *   @0x2c442c ldr r3, [r7, r3]
 *   @0x2c4430 ldr r2, [r3]
 *   @0x2c4434 cmp r6, r2
 *   @0x2c4438 strge r6, [r3]
 *   @0x2c443c strlt r2, [r3]
 *   @0x2c4440 cmp r9, #2
 *   @0x2c4444 beq 0x2c470c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x76c>
 *   @0x2c4448 cmp r9, #3
 *   @0x2c444c beq 0x2c46b0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x710>
 *   @0x2c4450 cmp r9, #1
 *   @0x2c4454 addeq r2, sp, #24
 *   @0x2c4458 addeq r3, r8, #8
 *   @0x2c445c ldmeq r2, {r0, r1}
 *   @0x2c4460 addeq r2, sp, #32
 *   @0x2c4464 stmeq r8, {r0, r1}
 *   @0x2c4468 ldmeq r2, {r0, r1}
 *   @0x2c446c stmeq r3, {r0, r1}
 *   @0x2c4470 vldr s13, [r8]
 *   @0x2c4474 vldr s15, [r8, #8]
 *   @0x2c4478 vldr s12, [r8, #4]
 *   @0x2c447c vldr s14, [r8, #12]
 *   @0x2c4480 vsub.f32 s14, s12, s14
 *   @0x2c4484 vmul.f32 s14, s14, s14
 *   @0x2c4488 vsub.f32 s15, s13, s15
 *   @0x2c448c vmla.f32 s14, s15, s15
 *   @0x2c4490 vsqrt.f32 s15, s14
 *   @0x2c4494 vcmp.f32 s15, s15
 *   @0x2c4498 vmrs APSR_nzcv, fpscr
 *   @0x2c449c bne 0x2c4848 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x8a8>
 *   @0x2c44a0 ldr r9, [sp, #0x84]
 *   @0x2c44a4 vstr s15, [r8, #16]
 *   @0x2c44a8 str r6, [r8, #0x14]
 *   @0x2c44ac cmp r9, #2
 *   @0x2c44b0 beq 0x2c4658 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x6b8>
 *   @0x2c44b4 cmp r9, #3
 *   @0x2c44b8 beq 0x2c4618 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x678>
 *   @0x2c44bc mov r0, r9
 *   @0x2c44c0 vldr s15, [pc, #208]
 *   @0x2c44c4 cmp r9, #0
 *   @0x2c44c8 vstr s15, [r5]
 *   @0x2c44cc strh r9, [r5, #4]
 *   @0x2c44d0 ble 0x2c44fc <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x55c>
 *   @0x2c44d4 add r3, sp, #24
 *   @0x2c44d8 add r0, r5, r0
 *   @0x2c44dc ldr r1, [r3, #0x1c]
 *   @0x2c44e0 add r5, r5, #1
 *   @0x2c44e4 ldr r2, [r3, #0x20]
 *   @0x2c44e8 add r3, r3, #36
 *   @0x2c44ec strb r1, [r5, #0x5]
 *   @0x2c44f0 cmp r5, r0
 *   @0x2c44f4 strb r2, [r5, #0x8]
 *   @0x2c44f8 bne 0x2c44dc <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x53c>
 *   @0x2c44fc ldrb r3, [r4, #0x58]
 *   @0x2c4500 cmp r3, #0
 *   @0x2c4504 beq 0x2c4570 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x5d0>
 *   @0x2c4508 vldr s17, [r4, #24]
 *   @0x2c450c vldr s16, [r4, #52]
 *   @0x2c4510 vadd.f32 s14, s17, s16
 *   @0x2c4514 vldr s15, [r8, #16]
 *   @0x2c4518 vcmpe.f32 s15, s14
 *   @0x2c451c vmrs APSR_nzcv, fpscr
 *   @0x2c4520 ble 0x2c4534 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x594>
 *   @0x2c4524 vldr s13, [pc, #132]
 *   @0x2c4528 vcmpe.f32 s15, s13
 *   @0x2c452c vmrs APSR_nzcv, fpscr
 *   @0x2c4530 bgt 0x2c479c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x7fc>
 *   @0x2c4534 vldr s11, [r8]
 *   @0x2c4538 vldr s14, [r8, #8]
 *   @0x2c453c vmov.f32 s15, #5.000000e-01
 *   @0x2c4540 vldr s12, [r8, #4]
 *   @0x2c4544 vldr s13, [r8, #12]
 *   @0x2c4548 mov r3, #0
 *   @0x2c454c str r3, [r8, #0x10]
 *   @0x2c4550 vadd.f32 s14, s11, s14
 *   @0x2c4554 vadd.f32 s13, s12, s13
 *   @0x2c4558 vmul.f32 s14, s14, s15
 *   @0x2c455c vmul.f32 s15, s13, s15
 *   @0x2c4560 vstr s14, [r8]
 *   @0x2c4564 vstr s14, [r8, #8]
 *   @0x2c4568 vstr s15, [r8, #4]
 *   @0x2c456c vstr s15, [r8, #12]
 *   @0x2c4570 add sp, sp, #140
 *   @0x2c4574 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2c4578 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c457c ldr r9, [sp, #0x84]
 *   @0x2c4580 cmp r6, #20
 *   @0x2c4584 add r9, r9, #1
 *   @0x2c4588 str r9, [sp, #0x84]
 *   @0x2c458c bne 0x2c41b0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x210>
 *   @0x2c4590 b 0x2c4428 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x488>
 *   @0x2c4594 .word 0x28800000
 *   @0x2c4598 andeq r0, r0, r0
 *   @0x2c459c mulseq r2, r0, r12
 *   @0x2c45a0 .word 0xfffffe78
 *   @0x2c45a4 .word 0xfffffe7c
 *   @0x2c45a8 .word 0xfffffe80
 *   @0x2c45ac .word 0xfffff888
 *   @0x2c45b0 strlo r0, [r0], #-0
 *   @0x2c45b4 mov r1, r9
 *   @0x2c45b8 cmp r1, #3
 *   @0x2c45bc bne 0x2c4210 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x270>
 *   @0x2c45c0 mov r9, r1
 *   @0x2c45c4 b 0x2c4428 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x488>
 *   @0x2c45c8 add r0, sp, #24
 *   @0x2c45cc bl 0x2c3c50 <_ZN9b2Simplex6Solve2Ev>
 *   @0x2c45d0 ldr r1, [sp, #0x84]
 *   @0x2c45d4 b 0x2c4208 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x268>
 *   @0x2c45d8 ldr r3, [pc, #-0x34]
 *   @0x2c45dc ldr r3, [r7, r3]
 *   @0x2c45e0 vldr s9, [r3]
 *   @0x2c45e4 vldr s12, [r3, #4]
 *   @0x2c45e8 b 0x2c4250 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x2b0>
 *   @0x2c45ec vldr s9, [sp, #40]
 *   @0x2c45f0 vldr s12, [sp, #44]
 *   @0x2c45f4 vneg.f32 s9, s9
 *   @0x2c45f8 vneg.f32 s12, s12
 *   @0x2c45fc b 0x2c4250 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x2b0>
 *   @0x2c4600 mov r3, #0
 *   @0x2c4604 mov r0, r3
 *   @0x2c4608 b 0x2c4388 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x3e8>
 *   @0x2c460c mov r3, #0
 *   @0x2c4610 mov r2, r3
 *   @0x2c4614 b 0x2c42e8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x348>
 *   @0x2c4618 vldr s13, [sp, #40]
 *   @0x2c461c vldr s14, [sp, #44]
 *   @0x2c4620 vldr s15, [sp, #112]
 *   @0x2c4624 vldr s10, [sp, #80]
 *   @0x2c4628 vsub.f32 s15, s15, s13
 *   @0x2c462c vldr s11, [sp, #76]
 *   @0x2c4630 vldr s12, [sp, #116]
 *   @0x2c4634 mov r0, r9
 *   @0x2c4638 strh r9, [r5, #4]
 *   @0x2c463c vsub.f32 s10, s10, s14
 *   @0x2c4640 vmul.f32 s15, s10, s15
 *   @0x2c4644 vsub.f32 s13, s11, s13
 *   @0x2c4648 vsub.f32 s14, s12, s14
 *   @0x2c464c vnmls.f32 s15, s13, s14
 *   @0x2c4650 vstr s15, [r5]
 *   @0x2c4654 b 0x2c44d4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x534>
 *   @0x2c4658 vldr s12, [sp, #44]
 *   @0x2c465c vldr s14, [sp, #80]
 *   @0x2c4660 vsub.f32 s14, s12, s14
 *   @0x2c4664 vldr s13, [sp, #40]
 *   @0x2c4668 vldr s15, [sp, #76]
 *   @0x2c466c vmul.f32 s14, s14, s14
 *   @0x2c4670 vsub.f32 s15, s13, s15
 *   @0x2c4674 vmla.f32 s14, s15, s15
 *   @0x2c4678 vsqrt.f32 s15, s14
 *   @0x2c467c vcmp.f32 s15, s15
 *   @0x2c4680 vmrs APSR_nzcv, fpscr
 *   @0x2c4684 bne 0x2c4834 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x894>
 *   @0x2c4688 mov r0, r9
 *   @0x2c468c b 0x2c44c4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x524>
 *   @0x2c4690 vldr s14, [pc, #-232]
 *   @0x2c4694 vcmpe.f32 s15, s14
 *   @0x2c4698 vmrs APSR_nzcv, fpscr
 *   @0x2c469c bmi 0x2c4118 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x178>
 *   @0x2c46a0 ldr r9, [sp, #0x84]
 *   @0x2c46a4 cmp r9, #0
 *   @0x2c46a8 bne 0x2c41a0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x200>
 *   @0x2c46ac b 0x2c4118 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x178>
 *   @0x2c46b0 vldr s12, [sp, #84]
 *   @0x2c46b4 vldr s13, [sp, #60]
 *   @0x2c46b8 vldr s7, [sp, #64]
 *   @0x2c46bc vmul.f32 s13, s12, s13
 *   @0x2c46c0 vldr s14, [sp, #48]
 *   @0x2c46c4 vldr s8, [sp, #24]
 *   @0x2c46c8 vldr s9, [sp, #28]
 *   @0x2c46cc vldr s15, [sp, #120]
 *   @0x2c46d0 vldr s10, [sp, #96]
 *   @0x2c46d4 vldr s11, [sp, #100]
 *   @0x2c46d8 add r3, r8, #8
 *   @0x2c46dc vmul.f32 s12, s12, s7
 *   @0x2c46e0 vmla.f32 s13, s14, s8
 *   @0x2c46e4 vmla.f32 s12, s14, s9
 *   @0x2c46e8 vmla.f32 s13, s15, s10
 *   @0x2c46ec vmla.f32 s12, s15, s11
 *   @0x2c46f0 vstr s13, [r8]
 *   @0x2c46f4 vstr s12, [r8, #4]
 *   @0x2c46f8 ldm r8, {r0, r1}
 *   @0x2c46fc stm r3, {r0, r1}
 *   @0x2c4700 vldr s15, [r8, #8]
 *   @0x2c4704 vldr s14, [r8, #12]
 *   @0x2c4708 b 0x2c4480 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x4e0>
 *   @0x2c470c vldr s14, [sp, #84]
 *   @0x2c4710 vldr s13, [sp, #60]
 *   @0x2c4714 vldr s12, [sp, #64]
 *   @0x2c4718 vmul.f32 s13, s14, s13
 *   @0x2c471c vldr s15, [sp, #68]
 *   @0x2c4720 vldr s6, [sp, #72]
 *   @0x2c4724 vldr s11, [sp, #48]
 *   @0x2c4728 vldr s7, [sp, #24]
 *   @0x2c472c vldr s8, [sp, #28]
 *   @0x2c4730 vldr s9, [sp, #32]
 *   @0x2c4734 vldr s10, [sp, #36]
 *   @0x2c4738 vmul.f32 s12, s14, s12
 *   @0x2c473c vmul.f32 s15, s14, s15
 *   @0x2c4740 vmul.f32 s14, s14, s6
 *   @0x2c4744 vmla.f32 s13, s11, s7
 *   @0x2c4748 vmla.f32 s12, s11, s8
 *   @0x2c474c vstr s13, [r8]
 *   @0x2c4750 vmla.f32 s15, s11, s9
 *   @0x2c4754 vstr s12, [r8, #4]
 *   @0x2c4758 vmla.f32 s14, s11, s10
 *   @0x2c475c vstr s15, [r8, #8]
 *   @0x2c4760 vstr s14, [r8, #12]
 *   @0x2c4764 b 0x2c4480 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x4e0>
 *   @0x2c4768 vldr s13, [sp, #40]
 *   @0x2c476c vldr s14, [sp, #44]
 *   @0x2c4770 vldr s15, [sp, #112]
 *   @0x2c4774 vldr s10, [sp, #80]
 *   @0x2c4778 vsub.f32 s15, s15, s13
 *   @0x2c477c vldr s11, [sp, #76]
 *   @0x2c4780 vldr s12, [sp, #116]
 *   @0x2c4784 vsub.f32 s10, s10, s14
 *   @0x2c4788 vmul.f32 s15, s10, s15
 *   @0x2c478c vsub.f32 s13, s11, s13
 *   @0x2c4790 vsub.f32 s14, s12, s14
 *   @0x2c4794 vnmls.f32 s15, s13, s14
 *   @0x2c4798 b 0x2c40f4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x154>
 *   @0x2c479c vldr s13, [r8, #4]
 *   @0x2c47a0 vldr s18, [r8, #12]
 *   @0x2c47a4 vsub.f32 s18, s18, s13
 *   @0x2c47a8 vldr s19, [r8, #8]
 *   @0x2c47ac vldr s13, [r8]
 *   @0x2c47b0 vmul.f32 s12, s18, s18
 *   @0x2c47b4 vsub.f32 s19, s19, s13
 *   @0x2c47b8 vmla.f32 s12, s19, s19
 *   @0x2c47bc vsqrt.f32 s13, s12
 *   @0x2c47c0 vsub.f32 s15, s15, s14
 *   @0x2c47c4 vcmp.f32 s13, s13
 *   @0x2c47c8 vstr s15, [r8, #16]
 *   @0x2c47cc vmrs APSR_nzcv, fpscr
 *   @0x2c47d0 bne 0x2c4824 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x884>
 *   @0x2c47d4 vldr s15, [pc, #-556]
 *   @0x2c47d8 vcmpe.f32 s13, s15
 *   @0x2c47dc vldr s12, [r8]
 *   @0x2c47e0 vldr s14, [r8, #8]
 *   @0x2c47e4 vmrs APSR_nzcv, fpscr
 *   @0x2c47e8 vmovpl.f32 s15, #1.000000e+00
 *   @0x2c47ec vdivpl.f32 s13, s15, s13
 *   @0x2c47f0 vldr s15, [r8, #12]
 *   @0x2c47f4 vmulpl.f32 s19, s19, s13
 *   @0x2c47f8 vmulpl.f32 s18, s18, s13
 *   @0x2c47fc vldr s13, [r8, #4]
 *   @0x2c4800 vmla.f32 s12, s17, s19
 *   @0x2c4804 vmla.f32 s13, s17, s18
 *   @0x2c4808 vstr s12, [r8]
 *   @0x2c480c vmls.f32 s14, s16, s19
 *   @0x2c4810 vstr s13, [r8, #4]
 *   @0x2c4814 vmls.f32 s15, s16, s18
 *   @0x2c4818 vstr s14, [r8, #8]
 *   @0x2c481c vstr s15, [r8, #12]
 *   @0x2c4820 b 0x2c4570 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x5d0>
 *   @0x2c4824 vmov r0, s12
 *   @0x2c4828 bl 0xb6700 <sqrtf@plt>
 *   @0x2c482c vmov s13, r0
 *   @0x2c4830 b 0x2c47d4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x834>
 *   @0x2c4834 vmov r0, s14
 *   @0x2c4838 bl 0xb6700 <sqrtf@plt>
 *   @0x2c483c ldr r9, [sp, #0x84]
 *   @0x2c4840 vmov s15, r0
 *   @0x2c4844 b 0x2c4688 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x6e8>
 *   @0x2c4848 vmov r0, s14
 *   @0x2c484c bl 0xb6700 <sqrtf@plt>
 *   @0x2c4850 vmov s15, r0
 *   @0x2c4854 b 0x2c44a0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x500>
 *   @0x2c4858 vmov r0, s14
 *   @0x2c485c bl 0xb6700 <sqrtf@plt>
 *   @0x2c4860 vmov s15, r0
 *   @0x2c4864 b 0x2c40f4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x154>
 *
 * ══ §7/13 Error_Show_Action  0xecf70  size 2184  546 条（0xecf70..0xed7f8）
 * @func 0xecf70 0xed7f8  size 2184  546 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xecfdc→0x47f298, 0xecfe4→0x542900, 0xed350→0x542908, 0xed37c→0x542904, 0xed390→0x54290c, 0xed4b0→0x47f3c5, 0xed4e0→0x3eb930, 0xed50c→0x3eb688
 * 调用序列: TErrStreamConsole::Output(char const*, ...)×11 / VM::DebugInfo(VMBuffer*, int)×3 / VM::DebugLineNumber(VMDebugInfo*, char const*, char**)×3 / TErrStreamConsole::TErrStreamConsole()×3 / VM::DebugLine(VMDebugInfo*, char const*)×3 / 0xb655c×3 / 0xb65c8×3 / 0xb65e0×2
 * 字段偏移 top8: 0x20×16 / 0x3c×14 / 0x14×12 / 0x34×8 / 0x8×7 / 0x24×6 / 0x28×5 / 0x4c×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xecf70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xecf74 sub sp, sp, #32768
 *   @0xecf78 sub sp, sp, #124
 *   @0xecf7c ldr r12, [pc, #0x7ec]
 *   @0xecf80 add r8, sp, #120
 *   @0xecf84 ldr r3, [pc, #0x7e8]
 *   @0xecf88 add r12, pc, r12
 *   @0xecf8c str r12, [sp, #0x20]
 *   @0xecf90 sub r12, r8, #4
 *   @0xecf94 str r12, [sp, #0x38]
 *   @0xecf98 ldr r12, [sp, #0x20]
 *   @0xecf9c mov r2, #32768
 *   @0xecfa0 str r0, [sp, #0x3c]
 *   @0xecfa4 add lr, sp, r2
 *   @0xecfa8 str r1, [sp, #0x54]
 *   @0xecfac add r0, sp, #116
 *   @0xecfb0 ldr r3, [r12, r3]
 *   @0xecfb4 mov r1, #0
 *   @0xecfb8 str r3, [sp, #0x48]
 *   @0xecfbc ldr r3, [r3]
 *   @0xecfc0 str r3, [lr, #0x74]
 *   @0xecfc4 bl 0xb65b0 <memset@plt>
 *   @0xecfc8 ldr r12, [sp, #0x54]
 *   @0xecfcc cmp r12, #0
 *   @0xecfd0 bne 0xed5c0 <_Z17Error_Show_ActionPKcb+0x650>
 *   @0xecfd4 ldr r12, [sp, #0x20]
 *   @0xecfd8 add lr, sp, #32768
 *   @0xecfdc ldr r2, [pc, #0x794]
 *   @0xecfe0 movw r4, #0x7fe0
 *   @0xecfe4 ldr r3, [pc, #0x790]
 *   @0xecfe8 movt r4, #0xffff
 *   @0xecfec add lr, lr, #120
 *   @0xecff0 mov r1, #0
 *   @0xecff4 ldr r2, [r12, r2]
 *   @0xecff8 str r1, [lr, r4]
 *   @0xecffc ldr r3, [r12, r3]
 *   @0xed000 ldr r2, [r2]
 *   @0xed004 ldr r3, [r3]
 *   @0xed008 cmp r2, r1
 *   @0xed00c str r2, [sp, #0x34]
 *   @0xed010 add r3, r3, #1
 *   @0xed014 str r3, [sp, #0x24]
 *   @0xed018 beq 0xed330 <_Z17Error_Show_ActionPKcb+0x3c0>
 *   @0xed01c ldr r0, [r2, #0x38]
 *   @0xed020 cmp r0, r1
 *   @0xed024 beq 0xed668 <_Z17Error_Show_ActionPKcb+0x6f8>
 *   @0xed028 ldr r1, [r2, #0x44]
 *   @0xed02c sub r12, r8, #32
 *   @0xed030 str r12, [sp, #0x28]
 *   @0xed034 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0xed038 ldr r12, [sp, #0x34]
 *   @0xed03c ldr r2, [sp, #0x28]
 *   @0xed040 ldr r1, [r12, #0x3c]
 *   @0xed044 str r0, [sp, #0x4c]
 *   @0xed048 bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0xed04c add lr, sp, #32768
 *   @0xed050 add lr, lr, #120
 *   @0xed054 ldr r4, [lr, r4]
 *   @0xed058 cmp r4, #0
 *   @0xed05c str r0, [sp, #0x50]
 *   @0xed060 beq 0xed080 <_Z17Error_Show_ActionPKcb+0x110>
 *   @0xed064 ldr r1, [pc, #0x714]
 *   @0xed068 mov r0, r4
 *   @0xed06c mov r2, #10
 *   @0xed070 add r1, pc, r1
 *   @0xed074 bl 0xb65e0 <strncmp@plt>
 *   @0xed078 cmp r0, #0
 *   @0xed07c beq 0xed55c <_Z17Error_Show_ActionPKcb+0x5ec>
 *   @0xed080 sub r8, r8, #28
 *   @0xed084 add r12, sp, #104
 *   @0xed088 str r12, [sp, #0x14]
 *   @0xed08c mov r4, #1
 *   @0xed090 ldr r12, [pc, #0x6ec]
 *   @0xed094 mov r0, r8
 *   @0xed098 ldr r5, [sp, #0x34]
 *   @0xed09c add r12, pc, r12
 *   @0xed0a0 str r12, [sp, #0x30]
 *   @0xed0a4 bl 0xd4190 <_ZN17TErrStreamConsoleC2Ev>
 *   @0xed0a8 ldr r12, [pc, #0x6d8]
 *   @0xed0ac add r12, pc, r12
 *   @0xed0b0 str r12, [sp, #0x40]
 *   @0xed0b4 ldr r12, [pc, #0x6d0]
 *   @0xed0b8 add r12, pc, r12
 *   @0xed0bc str r12, [sp, #0x44]
 *   @0xed0c0 ldr r12, [pc, #0x6c8]
 *   @0xed0c4 add r12, pc, r12
 *   @0xed0c8 str r12, [sp, #0x2c]
 *   @0xed0cc ldr r12, [pc, #0x6c0]
 *   @0xed0d0 add r12, pc, r12
 *   @0xed0d4 str r12, [sp, #0x18]
 *   @0xed0d8 ldr r12, [pc, #0x6b8]
 *   @0xed0dc add r12, pc, r12
 *   @0xed0e0 str r12, [sp, #0x1c]
 *   @0xed0e4 ldr r1, [r5, #0x44]
 *   @0xed0e8 ldr r0, [r5, #0x38]
 *   @0xed0ec bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0xed0f0 ldr r1, [r5, #0x3c]
 *   @0xed0f4 ldr r2, [sp, #0x28]
 *   @0xed0f8 mov r6, r0
 *   @0xed0fc bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0xed100 cmp r4, #0
 *   @0xed104 mov r7, r0
 *   @0xed108 bne 0xed2f4 <_Z17Error_Show_ActionPKcb+0x384>
 *   @0xed10c add r0, sp, #32768
 *   @0xed110 movw r2, #0x7fe0
 *   @0xed114 add r0, r0, #120
 *   @0xed118 movt r2, #0xffff
 *   @0xed11c ldr r1, [r5, #0x3c]
 *   @0xed120 ldr r2, [r0, r2]
 *   @0xed124 mov r0, r6
 *   @0xed128 cmp r2, #0
 *   @0xed12c ldreq r4, [r5, #0x34]
 *   @0xed130 movne r4, r2
 *   @0xed134 bl 0xec1a8 <_ZN2VM9DebugLineEP11VMDebugInfoPKc>
 *   @0xed138 mov r3, r7
 *   @0xed13c ldr r1, [sp, #0x30]
 *   @0xed140 mov r2, r4
 *   @0xed144 str r0, [sp]
 *   @0xed148 mov r0, r8
 *   @0xed14c bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed150 add r1, sp, #32768
 *   @0xed154 movw r3, #0x7fe0
 *   @0xed158 add r1, r1, #120
 *   @0xed15c movt r3, #0xffff
 *   @0xed160 ldr r0, [r1, r3]
 *   @0xed164 cmp r0, #0
 *   @0xed168 beq 0xed170 <_Z17Error_Show_ActionPKcb+0x200>
 *   @0xed16c bl 0xb655c <free@plt>
 *   @0xed170 ldr r6, [r5, #0x4c]
 *   @0xed174 cmp r6, #0
 *   @0xed178 ble 0xed2cc <_Z17Error_Show_ActionPKcb+0x35c>
 *   @0xed17c ldr r4, [r5, #0x28]
 *   @0xed180 movw r7, #0x7ff0
 *   @0xed184 movt r7, #0xffff
 *   @0xed188 ldr r3, [r4, #0x18]
 *   @0xed18c cmp r3, #0
 *   @0xed190 beq 0xed2cc <_Z17Error_Show_ActionPKcb+0x35c>
 *   @0xed194 ldr r0, [r4, #0x1c]
 *   @0xed198 cmp r0, #0
 *   @0xed19c beq 0xed2e0 <_Z17Error_Show_ActionPKcb+0x370>
 *   @0xed1a0 ldr r1, [r4]
 *   @0xed1a4 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0xed1a8 add r2, sp, #32768
 *   @0xed1ac add r2, r2, #120
 *   @0xed1b0 mov r3, #0
 *   @0xed1b4 str r3, [r2, r7]
 *   @0xed1b8 ldr r2, [sp, #0x14]
 *   @0xed1bc ldr r1, [r4, #0x20]
 *   @0xed1c0 mov r10, r0
 *   @0xed1c4 bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0xed1c8 add r12, sp, #32768
 *   @0xed1cc ldr r1, [r4, #0x20]
 *   @0xed1d0 add r12, r12, #120
 *   @0xed1d4 ldr r2, [r12, r7]
 *   @0xed1d8 cmp r2, #0
 *   @0xed1dc ldreq r9, [r4, #0x24]
 *   @0xed1e0 movne r9, r2
 *   @0xed1e4 mov r11, r0
 *   @0xed1e8 mov r0, r10
 *   @0xed1ec bl 0xec1a8 <_ZN2VM9DebugLineEP11VMDebugInfoPKc>
 *   @0xed1f0 mov r3, r11
 *   @0xed1f4 mov r2, r9
 *   @0xed1f8 ldr r1, [sp, #0x18]
 *   @0xed1fc str r0, [sp]
 *   @0xed200 mov r0, r8
 *   @0xed204 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed208 add lr, sp, #32768
 *   @0xed20c add lr, lr, #120
 *   @0xed210 ldr r11, [lr, r7]
 *   @0xed214 cmp r11, #0
 *   @0xed218 beq 0xed2b0 <_Z17Error_Show_ActionPKcb+0x340>
 *   @0xed21c mov r0, r11
 *   @0xed220 ldr r1, [sp, #0x1c]
 *   @0xed224 mov r2, #10
 *   @0xed228 bl 0xb65e0 <strncmp@plt>
 *   @0xed22c cmp r0, #0
 *   @0xed230 bne 0xed2a8 <_Z17Error_Show_ActionPKcb+0x338>
 *   @0xed234 mov r0, r11
 *   @0xed238 bl 0xb6538 <strlen@plt>
 *   @0xed23c ldr r12, [sp, #0x20]
 *   @0xed240 ldr r2, [pc, #0x554]
 *   @0xed244 ldr r2, [r12, r2]
 *   @0xed248 ldr r12, [r2]
 *   @0xed24c sub r0, r0, #1
 *   @0xed250 add r2, r11, r0
 *   @0xed254 ldrb r3, [r11, r0]
 *   @0xed258 add r3, r12, r3
 *   @0xed25c ldrb r3, [r3, #0x1]
 *   @0xed260 tst r3, #4
 *   @0xed264 beq 0xed288 <_Z17Error_Show_ActionPKcb+0x318>
 *   @0xed268 sub r3, r2, #1
 *   @0xed26c mov r2, r3
 *   @0xed270 sub r3, r3, #1
 *   @0xed274 ldrb r1, [r2]
 *   @0xed278 add r1, r12, r1
 *   @0xed27c ldrb r1, [r1, #0x1]
 *   @0xed280 tst r1, #4
 *   @0xed284 bne 0xed26c <_Z17Error_Show_ActionPKcb+0x2fc>
 *   @0xed288 add r0, r2, #1
 *   @0xed28c bl 0xb66b8 <atoi@plt>
 *   @0xed290 add lr, sp, #32768
 *   @0xed294 add lr, lr, #120
 *   @0xed298 ldr r11, [lr, r7]
 *   @0xed29c cmp r11, #0
 *   @0xed2a0 str r0, [sp, #0x24]
 *   @0xed2a4 beq 0xed2b0 <_Z17Error_Show_ActionPKcb+0x340>
 *   @0xed2a8 mov r0, r11
 *   @0xed2ac bl 0xb655c <free@plt>
 *   @0xed2b0 ldr r2, [r4, #0xc]
 *   @0xed2b4 subs r6, r6, #1
 *   @0xed2b8 ldr r4, [r5, #0x40]
 *   @0xed2bc ldr r3, [r5, #0x8]
 *   @0xed2c0 rsb r4, r2, r4
 *   @0xed2c4 add r4, r3, r4
 *   @0xed2c8 bne 0xed188 <_Z17Error_Show_ActionPKcb+0x218>
 *   @0xed2cc ldr r5, [r5, #0x4]
 *   @0xed2d0 cmp r5, #0
 *   @0xed2d4 beq 0xed350 <_Z17Error_Show_ActionPKcb+0x3e0>
 *   @0xed2d8 mov r4, #0
 *   @0xed2dc b 0xed0e4 <_Z17Error_Show_ActionPKcb+0x174>
 *   @0xed2e0 mov r0, r8
 *   @0xed2e4 ldr r1, [sp, #0x2c]
 *   @0xed2e8 ldr r2, [r4, #0x24]
 *   @0xed2ec bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed2f0 b 0xed2b0 <_Z17Error_Show_ActionPKcb+0x340>
 *   @0xed2f4 mov r0, r8
 *   @0xed2f8 ldr r1, [sp, #0x40]
 *   @0xed2fc bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed300 add lr, sp, #32768
 *   @0xed304 add lr, lr, #120
 *   @0xed308 movw r3, #0x7fe0
 *   @0xed30c movt r3, #0xffff
 *   @0xed310 mov r0, r8
 *   @0xed314 ldr r1, [sp, #0x44]
 *   @0xed318 ldr r2, [lr, r3]
 *   @0xed31c mov r3, r7
 *   @0xed320 cmp r2, #0
 *   @0xed324 ldreq r2, [r5, #0x34]
 *   @0xed328 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed32c b 0xed150 <_Z17Error_Show_ActionPKcb+0x1e0>
 *   @0xed330 ldr r12, [sp, #0x34]
 *   @0xed334 sub r8, r8, #28
 *   @0xed338 mov r0, r8
 *   @0xed33c str r12, [sp, #0x4c]
 *   @0xed340 str r12, [sp, #0x50]
 *   @0xed344 add r12, sp, #104
 *   @0xed348 str r12, [sp, #0x14]
 *   @0xed34c bl 0xd4190 <_ZN17TErrStreamConsoleC2Ev>
 *   @0xed350 ldr r3, [pc, #0x448]
 *   @0xed354 ldr r12, [sp, #0x20]
 *   @0xed358 ldr r3, [r12, r3]
 *   @0xed35c ldr r0, [r3]
 *   @0xed360 cmn r0, #1
 *   @0xed364 beq 0xed5e0 <_Z17Error_Show_ActionPKcb+0x670>
 *   @0xed368 movw r3, #0x86a0
 *   @0xed36c movt r3, #0x1
 *   @0xed370 cmp r0, r3
 *   @0xed374 beq 0xed67c <_Z17Error_Show_ActionPKcb+0x70c>
 *   @0xed378 ldr r12, [sp, #0x20]
 *   @0xed37c ldr r3, [pc, #0x420]
 *   @0xed380 ldr r3, [r12, r3]
 *   @0xed384 ldr r1, [r3]
 *   @0xed388 bl 0xf41fc <_Z14Get_Event_Nameii>
 *   @0xed38c ldr r12, [sp, #0x20]
 *   @0xed390 ldr r3, [pc, #0x410]
 *   @0xed394 ldr r3, [r12, r3]
 *   @0xed398 mov r4, r0
 *   @0xed39c ldr r0, [r3]
 *   @0xed3a0 bl 0x19ed54 <_Z11Object_Namei>
 *   @0xed3a4 ldr r12, [sp, #0x3c]
 *   @0xed3a8 cmp r12, #0
 *   @0xed3ac mov r3, r0
 *   @0xed3b0 beq 0xed720 <_Z17Error_Show_ActionPKcb+0x7b0>
 *   @0xed3b4 ldr r12, [sp, #0x24]
 *   @0xed3b8 add r0, sp, #116
 *   @0xed3bc ldr r2, [pc, #0x3e8]
 *   @0xed3c0 movw r1, #0x7fff
 *   @0xed3c4 str r3, [sp, #0x8]
 *   @0xed3c8 mov r3, r0
 *   @0xed3cc str r12, [sp]
 *   @0xed3d0 add r2, pc, r2
 *   @0xed3d4 ldr r12, [sp, #0x3c]
 *   @0xed3d8 str r4, [sp, #0x4]
 *   @0xed3dc str r12, [sp, #0xc]
 *   @0xed3e0 bl 0xb65c8 <snprintf@plt>
 *   @0xed3e4 ldr r0, [sp, #0x14]
 *   @0xed3e8 bl 0xd4190 <_ZN17TErrStreamConsoleC2Ev>
 *   @0xed3ec ldr r1, [pc, #0x3bc]
 *   @0xed3f0 ldr r0, [sp, #0x14]
 *   @0xed3f4 add r1, pc, r1
 *   @0xed3f8 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed3fc ldr r1, [pc, #0x3b0]
 *   @0xed400 ldr r0, [sp, #0x14]
 *   @0xed404 add r2, sp, #116
 *   @0xed408 add r1, pc, r1
 *   @0xed40c bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed410 ldr r12, [sp, #0x34]
 *   @0xed414 cmp r12, #0
 *   @0xed418 beq 0xed474 <_Z17Error_Show_ActionPKcb+0x504>
 *   @0xed41c ldr r3, [r12, #0x38]
 *   @0xed420 cmp r3, #0
 *   @0xed424 beq 0xed740 <_Z17Error_Show_ActionPKcb+0x7d0>
 *   @0xed428 add lr, sp, #32768
 *   @0xed42c movw r3, #0x7fe0
 *   @0xed430 add lr, lr, #120
 *   @0xed434 movt r3, #0xffff
 *   @0xed438 ldr r0, [sp, #0x4c]
 *   @0xed43c ldr r2, [lr, r3]
 *   @0xed440 cmp r2, #0
 *   @0xed444 ldreq r4, [r12, #0x34]
 *   @0xed448 movne r4, r2
 *   @0xed44c ldr r12, [sp, #0x34]
 *   @0xed450 ldr r1, [r12, #0x3c]
 *   @0xed454 bl 0xec1a8 <_ZN2VM9DebugLineEP11VMDebugInfoPKc>
 *   @0xed458 ldr r1, [pc, #0x358]
 *   @0xed45c mov r2, r4
 *   @0xed460 ldr r3, [sp, #0x50]
 *   @0xed464 add r1, pc, r1
 *   @0xed468 str r0, [sp]
 *   @0xed46c ldr r0, [sp, #0x14]
 *   @0xed470 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed474 ldr r1, [pc, #0x340]
 *   @0xed478 ldr r0, [sp, #0x14]
 *   @0xed47c add r1, pc, r1
 *   @0xed480 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed484 ldr r0, [sp, #0x14]
 *   @0xed488 ldr r1, [r8, #0x8]
 *   @0xed48c bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed490 add lr, sp, #32768
 *   @0xed494 movw r3, #0x7fe0
 *   @0xed498 add lr, lr, #120
 *   @0xed49c movt r3, #0xffff
 *   @0xed4a0 ldr r0, [lr, r3]
 *   @0xed4a4 cmp r0, #0
 *   @0xed4a8 beq 0xed4b0 <_Z17Error_Show_ActionPKcb+0x540>
 *   @0xed4ac bl 0xb655c <free@plt>
 *   @0xed4b0 ldr r3, [pc, #0x308]
 *   @0xed4b4 ldr r12, [sp, #0x20]
 *   @0xed4b8 ldr r3, [r12, r3]
 *   @0xed4bc ldrb r3, [r3]
 *   @0xed4c0 cmp r3, #0
 *   @0xed4c4 bne 0xed4d8 <_Z17Error_Show_ActionPKcb+0x568>
 *   @0xed4c8 ldr r12, [sp, #0x14]
 *   @0xed4cc ldr r1, [sp, #0x54]
 *   @0xed4d0 ldr r0, [r12, #0x8]
 *   @0xed4d4 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0xed4d8 ldr r12, [sp, #0x14]
 *   @0xed4dc add lr, sp, #32768
 *   @0xed4e0 ldr r3, [pc, #0x2dc]
 *   @0xed4e4 add lr, lr, #120
 *   @0xed4e8 movw r4, #0x7ff0
 *   @0xed4ec movt r4, #0xffff
 *   @0xed4f0 ldr r0, [r12, #0x8]
 *   @0xed4f4 ldr r12, [sp, #0x20]
 *   @0xed4f8 ldr r5, [r12, r3]
 *   @0xed4fc add r5, r5, #8
 *   @0xed500 str r5, [lr, r4]
 *   @0xed504 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xed508 ldr r12, [sp, #0x20]
 *   @0xed50c ldr r2, [pc, #0x2b4]
 *   @0xed510 add lr, sp, #32768
 *   @0xed514 add lr, lr, #120
 *   @0xed518 movw r3, #0x7fe4
 *   @0xed51c movt r3, #0xffff
 *   @0xed520 ldr r0, [r8, #0x8]
 *   @0xed524 ldr r2, [r12, r2]
 *   @0xed528 str r5, [lr, r3]
 *   @0xed52c add r3, r2, #8
 *   @0xed530 str r3, [lr, r4]
 *   @0xed534 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xed538 ldr r12, [sp, #0x48]
 *   @0xed53c add r0, sp, #32768
 *   @0xed540 ldr r2, [r0, #0x74]
 *   @0xed544 ldr r3, [r12]
 *   @0xed548 cmp r2, r3
 *   @0xed54c bne 0xed76c <_Z17Error_Show_ActionPKcb+0x7fc>
 *   @0xed550 add sp, sp, #32768
 *   @0xed554 add sp, sp, #124
 *   @0xed558 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xed55c mov r0, r4
 *   @0xed560 bl 0xb6538 <strlen@plt>
 *   @0xed564 ldr r12, [sp, #0x20]
 *   @0xed568 ldr r3, [pc, #0x22c]
 *   @0xed56c ldr r3, [r12, r3]
 *   @0xed570 ldr r12, [r3]
 *   @0xed574 sub r0, r0, #1
 *   @0xed578 add r2, r4, r0
 *   @0xed57c ldrb r3, [r4, r0]
 *   @0xed580 add r3, r12, r3
 *   @0xed584 ldrb r3, [r3, #0x1]
 *   @0xed588 tst r3, #4
 *   @0xed58c beq 0xed5b0 <_Z17Error_Show_ActionPKcb+0x640>
 *   @0xed590 sub r3, r2, #1
 *   @0xed594 mov r2, r3
 *   @0xed598 sub r3, r3, #1
 *   @0xed59c ldrb r1, [r2]
 *   @0xed5a0 add r1, r12, r1
 *   @0xed5a4 ldrb r1, [r1, #0x1]
 *   @0xed5a8 tst r1, #4
 *   @0xed5ac bne 0xed594 <_Z17Error_Show_ActionPKcb+0x624>
 *   @0xed5b0 add r0, r2, #1
 *   @0xed5b4 bl 0xb66b8 <atoi@plt>
 *   @0xed5b8 str r0, [sp, #0x24]
 *   @0xed5bc b 0xed080 <_Z17Error_Show_ActionPKcb+0x110>
 *   @0xed5c0 ldr r3, [pc, #0x204]
 *   @0xed5c4 add r3, pc, r3
 *   @0xed5c8 ldm r3, {r0, r1}
 *   @0xed5cc lsr r3, r1, #16
 *   @0xed5d0 strb r3, [r8, #0x2]
 *   @0xed5d4 str r0, [r8, #-0x4]
 *   @0xed5d8 strh r1, [r8]
 *   @0xed5dc b 0xecfd4 <_Z17Error_Show_ActionPKcb+0x64>
 *   @0xed5e0 ldr r3, [pc, #0x1e8]
 *   @0xed5e4 ldr r3, [r12, r3]
 *   @0xed5e8 ldrb r3, [r3]
 *   @0xed5ec cmp r3, #0
 *   @0xed5f0 beq 0xed6e4 <_Z17Error_Show_ActionPKcb+0x774>
 *   @0xed5f4 ldr lr, [pc, #0x1d8]
 *   @0xed5f8 add r12, sp, #116
 *   @0xed5fc add lr, pc, lr
 *   @0xed600 ldm lr!, {r0, r1, r2, r3}
 *   @0xed604 stm r12!, {r0, r1, r2, r3}
 *   @0xed608 ldm lr!, {r0, r1, r2, r3}
 *   @0xed60c stm r12!, {r0, r1, r2, r3}
 *   @0xed610 ldm lr!, {r0, r1, r2, r3}
 *   @0xed614 stm r12!, {r0, r1, r2, r3}
 *   @0xed618 ldm lr, {r0, r1, r2}
 *   @0xed61c stm r12!, {r0, r1}
 *   @0xed620 strb r2, [r12]
 *   @0xed624 ldr r12, [sp, #0x3c]
 *   @0xed628 cmp r12, #0
 *   @0xed62c beq 0xed730 <_Z17Error_Show_ActionPKcb+0x7c0>
 *   @0xed630 ldr r3, [pc, #0x1a0]
 *   @0xed634 add r0, sp, #116
 *   @0xed638 ldr lr, [sp, #0x20]
 *   @0xed63c movw r1, #0x7fff
 *   @0xed640 ldr r2, [pc, #0x194]
 *   @0xed644 ldr r12, [lr, r3]
 *   @0xed648 add r2, pc, r2
 *   @0xed64c ldr r3, [sp, #0x3c]
 *   @0xed650 str r3, [sp, #0x4]
 *   @0xed654 mov r3, r0
 *   @0xed658 ldr r12, [r12]
 *   @0xed65c str r12, [sp]
 *   @0xed660 bl 0xb65c8 <snprintf@plt>
 *   @0xed664 b 0xed3e4 <_Z17Error_Show_ActionPKcb+0x474>
 *   @0xed668 add r12, sp, #88
 *   @0xed66c str r0, [sp, #0x4c]
 *   @0xed670 str r12, [sp, #0x28]
 *   @0xed674 str r0, [sp, #0x50]
 *   @0xed678 b 0xed080 <_Z17Error_Show_ActionPKcb+0x110>
 *   @0xed67c ldr r12, [sp, #0x20]
 *   @0xed680 ldr r3, [pc, #0x120]
 *   @0xed684 ldr r3, [r12, r3]
 *   @0xed688 ldr r0, [r3]
 *   @0xed68c bl 0x1f2b58 <_Z13TimeLine_Namei>
 *   @0xed690 ldr r12, [sp, #0x3c]
 *   @0xed694 cmp r12, #0
 *   @0xed698 mov r3, r0
 *   @0xed69c beq 0xed75c <_Z17Error_Show_ActionPKcb+0x7ec>
 *   @0xed6a0 ldr r12, [sp, #0x24]
 *   @0xed6a4 add r0, sp, #116
 *   @0xed6a8 ldr r2, [pc, #0xf4]
 *   @0xed6ac movw r1, #0x7fff
 *   @0xed6b0 str r12, [sp]
 *   @0xed6b4 ldr r12, [sp, #0x20]
 *   @0xed6b8 ldr r2, [r12, r2]
 *   @0xed6bc ldr r12, [sp, #0x3c]
 *   @0xed6c0 str r3, [sp, #0x8]
 *   @0xed6c4 mov r3, r0
 *   @0xed6c8 str r12, [sp, #0xc]
 *   @0xed6cc ldr r12, [r2]
 *   @0xed6d0 ldr r2, [pc, #0x108]
 *   @0xed6d4 str r12, [sp, #0x4]
 *   @0xed6d8 add r2, pc, r2
 *   @0xed6dc bl 0xb65c8 <snprintf@plt>
 *   @0xed6e0 b 0xed3e4 <_Z17Error_Show_ActionPKcb+0x474>
 *   @0xed6e4 ldr lr, [pc, #0xf8]
 *   @0xed6e8 add r12, sp, #116
 *   @0xed6ec add lr, pc, lr
 *   @0xed6f0 ldm lr!, {r0, r1, r2, r3}
 *   @0xed6f4 stm r12!, {r0, r1, r2, r3}
 *   @0xed6f8 ldm lr!, {r0, r1, r2, r3}
 *   @0xed6fc stm r12!, {r0, r1, r2, r3}
 *   @0xed700 ldm lr!, {r0, r1, r2, r3}
 *   @0xed704 stm r12!, {r0, r1, r2, r3}
 *   @0xed708 ldm lr, {r0, r1}
 *   @0xed70c lsr r3, r1, #16
 *   @0xed710 str r0, [r12], #4
 *   @0xed714 strh r1, [r12], #2
 *   @0xed718 strb r3, [r12]
 *   @0xed71c b 0xed624 <_Z17Error_Show_ActionPKcb+0x6b4>
 *   @0xed720 ldr r12, [pc, #0xc0]
 *   @0xed724 add r12, pc, r12
 *   @0xed728 str r12, [sp, #0x3c]
 *   @0xed72c b 0xed3b4 <_Z17Error_Show_ActionPKcb+0x444>
 *   @0xed730 ldr r12, [pc, #0xb4]
 *   @0xed734 add r12, pc, r12
 *   @0xed738 str r12, [sp, #0x3c]
 *   @0xed73c b 0xed630 <_Z17Error_Show_ActionPKcb+0x6c0>
 *   @0xed740 ldr r12, [sp, #0x34]
 *   @0xed744 ldr r1, [pc, #0xa4]
 *   @0xed748 ldr r0, [sp, #0x14]
 *   @0xed74c ldr r2, [r12, #0x34]
 *   @0xed750 add r1, pc, r1
 *   @0xed754 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz>
 *   @0xed758 b 0xed474 <_Z17Error_Show_ActionPKcb+0x504>
 *   @0xed75c ldr r12, [pc, #0x90]
 *   @0xed760 add r12, pc, r12
 *   @0xed764 str r12, [sp, #0x3c]
 *   @0xed768 b 0xed6a0 <_Z17Error_Show_ActionPKcb+0x730>
 *   @0xed76c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xed770 eorseq r4, r0, r8, asr #25
 *   @0xed774 .word 0xffffbd00
 *   @0xed778 .word 0xffffbf58
 *   @0xed77c .word 0xffffc15c
 *   @0xed780 eoreq r7, r4, r4, lsl #23
 *   @0xed784 eoreq r7, r4, r4, ror #23
 *   @0xed788 eoreq r7, r4, r4, asr r11
 *   @0xed78c eoreq r7, r4, r8, lsr #23
 *   @0xed790 eoreq r7, r4, r0, ror #23
 *   @0xed794 .word 0x00247bb0
 *   @0xed798 eoreq r7, r4, r8, lsl r11
 *   @0xed79c .word 0xffffbd30
 *   @0xed7a0 .word 0xffffc160
 *   @0xed7a4 .word 0xffffc164
 *   @0xed7a8 .word 0xffffc168
 *   @0xed7ac mlaeq r4, r12, r9, r7
 *   @0xed7b0 .word 0x002479b0
 *   @0xed7b4 mlaeq r4, r12, r8, r7
 *   @0xed7b8 eoreq r7, r4, r0, lsr #19
 *   @0xed7bc eoreq r7, r4, r8, lsr #18
 *   @0xed7c0 .word 0xffffc140
 *   @0xed7c4 .word 0xffffbf78
 *   @0xed7c8 .word 0xffffbd10
 *   @0xed7cc eoreq r7, r4, r8, lsr #12
 *   @0xed7d0 .word 0xffffc16c
 *   @0xed7d4 eoreq r7, r4, r4, ror #13
 *   @0xed7d8 .word 0xffffc170
 *   @0xed7dc .word 0x002476d4
 *   @0xed7e0 eoreq r7, r4, r0, asr r6
 *   @0xed7e4 .word 0x002475bc
 *   @0xed7e8 eoreq r1, r4, r2, lsl r4
 *   @0xed7ec eoreq r1, r4, r2, lsl #8
 *   @0xed7f0 eoreq r7, r4, r12, asr #13
 *   @0xed7f4 .word 0x002413d6
 *
 * ══ §8/13 bucketAlloc  0x27c53c  size 2072  518 条（0x27c53c..0x27cd54）
 * @func 0x27c53c 0x27cd54  size 2072  518 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x27c568→0x75669a, 0x27c57c→0x75669c, 0x27c588→0x756728, 0x27c58c→0x756714, 0x27c5a0→0x7566a0, 0x27c5a4→0x7566d8, 0x27c5a8→0x756700, 0x27c5b4→0x7566ec
 * 调用序列: 0xb65b0×13 / operator new(unsigned int)×7 / addPageToGlobalPageList(void*, void*)×7 / 0xb6544 / bucketAlloc(unsigned int, bool)+0x258 / bucketAlloc(unsigned int, bool)+0x2c4 / bucketAlloc(unsigned int, bool)+0x1b8 / bucketAlloc(unsigned int, bool)+0x314
 * 字段偏移 top8: 0x4×30 / 0x8×30 / 0x10×23 / 0xc×22 / 0x1×7 / 0x78c×3 / 0x201×2 / 0x79c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c53c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27c540 mov r5, r0
 *   @0x27c544 ldr r7, [pc, #0x7d0]
 *   @0x27c548 sub sp, sp, #12
 *   @0x27c54c ldr r6, [pc, #0x7cc]
 *   @0x27c550 mov r8, r1
 *   @0x27c554 add r7, pc, r7
 *   @0x27c558 add r6, pc, r6
 *   @0x27c55c ldrb r4, [r7, #0x201]
 *   @0x27c560 cmp r4, #0
 *   @0x27c564 bne 0x27c644 <_Z11bucketAllocjb+0x108>
 *   @0x27c568 ldr r3, [pc, #0x7b4]
 *   @0x27c56c ldr r3, [r6, r3]
 *   @0x27c570 ldrb r3, [r3]
 *   @0x27c574 cmp r3, #0
 *   @0x27c578 beq 0x27c6e8 <_Z11bucketAllocjb+0x1ac>
 *   @0x27c57c ldr r3, [pc, #0x7a4]
 *   @0x27c580 mov r0, #128
 *   @0x27c584 mov r2, #16
 *   @0x27c588 ldr r10, [pc, #0x79c]
 *   @0x27c58c ldr r9, [pc, #0x79c]
 *   @0x27c590 mov r11, #1
 *   @0x27c594 ldr r3, [r6, r3]
 *   @0x27c598 str r2, [r3]
 *   @0x27c59c bl 0xb6544 <malloc@plt>
 *   @0x27c5a0 ldr r3, [pc, #0x78c]
 *   @0x27c5a4 ldr r2, [pc, #0x78c]
 *   @0x27c5a8 ldr r12, [pc, #0x78c]
 *   @0x27c5ac ldr r3, [r6, r3]
 *   @0x27c5b0 str r2, [sp]
 *   @0x27c5b4 ldr r1, [pc, #0x784]
 *   @0x27c5b8 str r3, [sp, #0x4]
 *   @0x27c5bc ldr r2, [sp, #0x4]
 *   @0x27c5c0 ldr r3, [pc, #0x77c]
 *   @0x27c5c4 str r0, [r2]
 *   @0x27c5c8 ldr r0, [r6, r10]
 *   @0x27c5cc ldr r2, [sp]
 *   @0x27c5d0 str r4, [r0, #0x4]
 *   @0x27c5d4 str r4, [r0, #0x8]
 *   @0x27c5d8 str r4, [r0, #0xc]
 *   @0x27c5dc ldr r0, [r6, r9]
 *   @0x27c5e0 str r4, [r0, #0x4]
 *   @0x27c5e4 str r4, [r0, #0x8]
 *   @0x27c5e8 str r4, [r0, #0xc]
 *   @0x27c5ec ldr r0, [r6, r12]
 *   @0x27c5f0 str r4, [r0, #0x4]
 *   @0x27c5f4 str r4, [r0, #0x8]
 *   @0x27c5f8 str r4, [r0, #0xc]
 *   @0x27c5fc ldr r1, [r6, r1]
 *   @0x27c600 str r4, [r1, #0x4]
 *   @0x27c604 str r4, [r1, #0x8]
 *   @0x27c608 str r4, [r1, #0xc]
 *   @0x27c60c ldr r2, [r6, r2]
 *   @0x27c610 str r4, [r2, #0x4]
 *   @0x27c614 str r4, [r2, #0x8]
 *   @0x27c618 str r4, [r2, #0xc]
 *   @0x27c61c ldr r2, [pc, #0x724]
 *   @0x27c620 ldr r2, [r6, r2]
 *   @0x27c624 str r4, [r2, #0x4]
 *   @0x27c628 str r4, [r2, #0x8]
 *   @0x27c62c str r4, [r2, #0xc]
 *   @0x27c630 ldr r3, [r6, r3]
 *   @0x27c634 strb r11, [r7, #0x201]
 *   @0x27c638 str r4, [r3, #0x4]
 *   @0x27c63c str r4, [r3, #0x8]
 *   @0x27c640 str r4, [r3, #0xc]
 *   @0x27c644 cmp r5, #16384
 *   @0x27c648 cmpne r5, #256
 *   @0x27c64c movls r4, #0
 *   @0x27c650 movhi r4, #1
 *   @0x27c654 bhi 0x27c6e8 <_Z11bucketAllocjb+0x1ac>
 *   @0x27c658 cmp r5, #8
 *   @0x27c65c bls 0x27c794 <_Z11bucketAllocjb+0x258>
 *   @0x27c660 cmp r5, #16
 *   @0x27c664 bls 0x27c800 <_Z11bucketAllocjb+0x2c4>
 *   @0x27c668 cmp r5, #32
 *   @0x27c66c bls 0x27c6f4 <_Z11bucketAllocjb+0x1b8>
 *   @0x27c670 cmp r5, #64
 *   @0x27c674 bls 0x27c850 <_Z11bucketAllocjb+0x314>
 *   @0x27c678 cmp r5, #128
 *   @0x27c67c bls 0x27c8a0 <_Z11bucketAllocjb+0x364>
 *   @0x27c680 cmp r5, #256
 *   @0x27c684 bls 0x27c744 <_Z11bucketAllocjb+0x208>
 *   @0x27c688 cmp r5, #16384
 *   @0x27c68c bne 0x27c984 <_Z11bucketAllocjb+0x448>
 *   @0x27c690 ldr r3, [pc, #0x6ac]
 *   @0x27c694 ldr r4, [r6, r3]
 *   @0x27c698 ldr r5, [r4, #0x8]
 *   @0x27c69c cmp r5, #0
 *   @0x27c6a0 beq 0x27ca4c <_Z11bucketAllocjb+0x510>
 *   @0x27c6a4 ldr r1, [r4, #0x10]
 *   @0x27c6a8 ldr r2, [r5]
 *   @0x27c6ac ldr r3, [r4, #0xc]
 *   @0x27c6b0 cmp r8, #0
 *   @0x27c6b4 sub r1, r1, #1
 *   @0x27c6b8 str r2, [r4, #0x8]
 *   @0x27c6bc add r3, r3, #1
 *   @0x27c6c0 str r1, [r4, #0x10]
 *   @0x27c6c4 str r3, [r4, #0xc]
 *   @0x27c6c8 beq 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c6cc mov r0, r5
 *   @0x27c6d0 mov r1, #0
 *   @0x27c6d4 mov r2, #16384
 *   @0x27c6d8 bl 0xb65b0 <memset@plt>
 *   @0x27c6dc mov r0, r5
 *   @0x27c6e0 add sp, sp, #12
 *   @0x27c6e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27c6e8 mov r0, #0
 *   @0x27c6ec add sp, sp, #12
 *   @0x27c6f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27c6f4 ldr r3, [pc, #0x640]
 *   @0x27c6f8 ldr r4, [r6, r3]
 *   @0x27c6fc ldr r5, [r4, #0x8]
 *   @0x27c700 cmp r5, #0
 *   @0x27c704 beq 0x27cb6c <_Z11bucketAllocjb+0x630>
 *   @0x27c708 ldr r3, [r4, #0x10]
 *   @0x27c70c ldr r2, [r5]
 *   @0x27c710 ldr r1, [r4, #0xc]
 *   @0x27c714 cmp r8, #0
 *   @0x27c718 sub r3, r3, #1
 *   @0x27c71c str r2, [r4, #0x8]
 *   @0x27c720 str r3, [r4, #0x10]
 *   @0x27c724 add r3, r1, #1
 *   @0x27c728 str r3, [r4, #0xc]
 *   @0x27c72c beq 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c730 mov r0, r5
 *   @0x27c734 mov r1, #0
 *   @0x27c738 mov r2, #32
 *   @0x27c73c bl 0xb65b0 <memset@plt>
 *   @0x27c740 b 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c744 ldr r3, [pc, #0x5fc]
 *   @0x27c748 ldr r4, [r6, r3]
 *   @0x27c74c ldr r5, [r4, #0x8]
 *   @0x27c750 cmp r5, #0
 *   @0x27c754 beq 0x27c8f0 <_Z11bucketAllocjb+0x3b4>
 *   @0x27c758 ldr r3, [r4, #0x10]
 *   @0x27c75c ldr r2, [r5]
 *   @0x27c760 ldr r1, [r4, #0xc]
 *   @0x27c764 cmp r8, #0
 *   @0x27c768 sub r3, r3, #1
 *   @0x27c76c str r2, [r4, #0x8]
 *   @0x27c770 str r3, [r4, #0x10]
 *   @0x27c774 add r3, r1, #1
 *   @0x27c778 str r3, [r4, #0xc]
 *   @0x27c77c beq 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c780 mov r0, r5
 *   @0x27c784 mov r1, #0
 *   @0x27c788 mov r2, #256
 *   @0x27c78c bl 0xb65b0 <memset@plt>
 *   @0x27c790 b 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c794 ldr r3, [pc, #0x590]
 *   @0x27c798 ldr r4, [r6, r3]
 *   @0x27c79c ldr r0, [r4, #0x8]
 *   @0x27c7a0 cmp r0, #0
 *   @0x27c7a4 beq 0x27c9bc <_Z11bucketAllocjb+0x480>
 *   @0x27c7a8 ldr r3, [r4, #0x10]
 *   @0x27c7ac ldr r2, [r0]
 *   @0x27c7b0 ldr r1, [r4, #0xc]
 *   @0x27c7b4 cmp r8, #0
 *   @0x27c7b8 sub r3, r3, #1
 *   @0x27c7bc str r2, [r4, #0x8]
 *   @0x27c7c0 str r3, [r4, #0x10]
 *   @0x27c7c4 add r3, r1, #1
 *   @0x27c7c8 str r3, [r4, #0xc]
 *   @0x27c7cc beq 0x27c6e0 <_Z11bucketAllocjb+0x1a4>
 *   @0x27c7d0 mov r3, r0
 *   @0x27c7d4 mov r2, #0
 *   @0x27c7d8 strb r2, [r3], #1
 *   @0x27c7dc add r3, r3, #1
 *   @0x27c7e0 strb r2, [r0, #0x1]
 *   @0x27c7e4 strb r2, [r3], #1
 *   @0x27c7e8 strb r2, [r3], #1
 *   @0x27c7ec strb r2, [r3], #1
 *   @0x27c7f0 strb r2, [r3], #1
 *   @0x27c7f4 strb r2, [r3], #1
 *   @0x27c7f8 strb r2, [r3]
 *   @0x27c7fc b 0x27c6e0 <_Z11bucketAllocjb+0x1a4>
 *   @0x27c800 ldr r3, [pc, #0x528]
 *   @0x27c804 ldr r4, [r6, r3]
 *   @0x27c808 ldr r5, [r4, #0x8]
 *   @0x27c80c cmp r5, #0
 *   @0x27c810 beq 0x27cadc <_Z11bucketAllocjb+0x5a0>
 *   @0x27c814 ldr r3, [r4, #0x10]
 *   @0x27c818 ldr r2, [r5]
 *   @0x27c81c ldr r1, [r4, #0xc]
 *   @0x27c820 cmp r8, #0
 *   @0x27c824 sub r3, r3, #1
 *   @0x27c828 str r2, [r4, #0x8]
 *   @0x27c82c str r3, [r4, #0x10]
 *   @0x27c830 add r3, r1, #1
 *   @0x27c834 str r3, [r4, #0xc]
 *   @0x27c838 beq 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c83c mov r0, r5
 *   @0x27c840 mov r1, #0
 *   @0x27c844 mov r2, #16
 *   @0x27c848 bl 0xb65b0 <memset@plt>
 *   @0x27c84c b 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c850 ldr r3, [pc, #0x4e8]
 *   @0x27c854 ldr r4, [r6, r3]
 *   @0x27c858 ldr r5, [r4, #0x8]
 *   @0x27c85c cmp r5, #0
 *   @0x27c860 beq 0x27cbfc <_Z11bucketAllocjb+0x6c0>
 *   @0x27c864 ldr r3, [r4, #0x10]
 *   @0x27c868 ldr r2, [r5]
 *   @0x27c86c ldr r1, [r4, #0xc]
 *   @0x27c870 cmp r8, #0
 *   @0x27c874 sub r3, r3, #1
 *   @0x27c878 str r2, [r4, #0x8]
 *   @0x27c87c str r3, [r4, #0x10]
 *   @0x27c880 add r3, r1, #1
 *   @0x27c884 str r3, [r4, #0xc]
 *   @0x27c888 beq 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c88c mov r0, r5
 *   @0x27c890 mov r1, #0
 *   @0x27c894 mov r2, #64
 *   @0x27c898 bl 0xb65b0 <memset@plt>
 *   @0x27c89c b 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c8a0 ldr r3, [pc, #0x490]
 *   @0x27c8a4 ldr r4, [r6, r3]
 *   @0x27c8a8 ldr r5, [r4, #0x8]
 *   @0x27c8ac cmp r5, #0
 *   @0x27c8b0 beq 0x27cc8c <_Z11bucketAllocjb+0x750>
 *   @0x27c8b4 ldr r3, [r4, #0x10]
 *   @0x27c8b8 ldr r2, [r5]
 *   @0x27c8bc ldr r1, [r4, #0xc]
 *   @0x27c8c0 cmp r8, #0
 *   @0x27c8c4 sub r3, r3, #1
 *   @0x27c8c8 str r2, [r4, #0x8]
 *   @0x27c8cc str r3, [r4, #0x10]
 *   @0x27c8d0 add r3, r1, #1
 *   @0x27c8d4 str r3, [r4, #0xc]
 *   @0x27c8d8 beq 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c8dc mov r0, r5
 *   @0x27c8e0 mov r1, #0
 *   @0x27c8e4 mov r2, #128
 *   @0x27c8e8 bl 0xb65b0 <memset@plt>
 *   @0x27c8ec b 0x27c6dc <_Z11bucketAllocjb+0x1a0>
 *   @0x27c8f0 mov r0, #264
 *   @0x27c8f4 movt r0, #0x10
 *   @0x27c8f8 bl 0x27c524 <_Znwj>
 *   @0x27c8fc mov r1, #120
 *   @0x27c900 mov r2, #256
 *   @0x27c904 movt r2, #0x10
 *   @0x27c908 mov r6, r0
 *   @0x27c90c add r0, r0, #8
 *   @0x27c910 bl 0xb65b0 <memset@plt>
 *   @0x27c914 ldr r3, [r4, #0x4]
 *   @0x27c918 movw r1, #0x107
 *   @0x27c91c movt r1, #0x10
 *   @0x27c920 mov r0, r6
 *   @0x27c924 add r1, r6, r1
 *   @0x27c928 str r3, [r6]
 *   @0x27c92c add r7, r6, #264
 *   @0x27c930 bic r7, r7, #255
 *   @0x27c934 str r6, [r4, #0x4]
 *   @0x27c938 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_>
 *   @0x27c93c ldr r1, [r4, #0x8]
 *   @0x27c940 add r5, r7, #1044480
 *   @0x27c944 mov r3, r7
 *   @0x27c948 ldr r0, [r4, #0x10]
 *   @0x27c94c add r12, r5, #3840
 *   @0x27c950 str r4, [r6, #0x4]
 *   @0x27c954 mov r2, r7
 *   @0x27c958 str r1, [r3], #256
 *   @0x27c95c b 0x27c964 <_Z11bucketAllocjb+0x428>
 *   @0x27c960 mov r2, r1
 *   @0x27c964 mov r1, r3
 *   @0x27c968 str r2, [r3], #256
 *   @0x27c96c cmp r3, r12
 *   @0x27c970 bne 0x27c960 <_Z11bucketAllocjb+0x424>
 *   @0x27c974 add r3, r0, #4080
 *   @0x27c978 add r5, r5, #3584
 *   @0x27c97c add r3, r3, #15
 *   @0x27c980 b 0x27c760 <_Z11bucketAllocjb+0x224>
 *   @0x27c984 ldr r0, [pc, #0x3c0]
 *   @0x27c988 mov r3, r5
 *   @0x27c98c ldr r1, [pc, #0x3bc]
 *   @0x27c990 mov r2, r5
 *   @0x27c994 ldr r0, [r6, r0]
 *   @0x27c998 add r1, pc, r1
 *   @0x27c99c ldr r0, [r0]
 *   @0x27c9a0 ldr r12, [r0]
 *   @0x27c9a4 ldr r12, [r12, #0xc]
 *   @0x27c9a8 blx r12
 *   @0x27c9ac mov r3, #42
 *   @0x27c9b0 mov r0, r4
 *   @0x27c9b4 str r3, [r4]
 *   @0x27c9b8 b 0x27c6e0 <_Z11bucketAllocjb+0x1a4>
 *   @0x27c9bc mov r0, #16
 *   @0x27c9c0 movt r0, #0x2
 *   @0x27c9c4 bl 0x27c524 <_Znwj>
 *   @0x27c9c8 mov r2, #8
 *   @0x27c9cc mov r1, #120
 *   @0x27c9d0 mov r5, r0
 *   @0x27c9d4 add r0, r0, r2
 *   @0x27c9d8 movt r2, #0x2
 *   @0x27c9dc add r6, r5, #16
 *   @0x27c9e0 bl 0xb65b0 <memset@plt>
 *   @0x27c9e4 ldr r3, [r4, #0x4]
 *   @0x27c9e8 add r1, r5, #131072
 *   @0x27c9ec mov r0, r5
 *   @0x27c9f0 add r1, r1, #15
 *   @0x27c9f4 bic r6, r6, #7
 *   @0x27c9f8 str r3, [r5]
 *   @0x27c9fc str r5, [r4, #0x4]
 *   @0x27ca00 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_>
 *   @0x27ca04 ldr r1, [r4, #0x8]
 *   @0x27ca08 add r0, r6, #130048
 *   @0x27ca0c mov r3, r6
 *   @0x27ca10 ldr r7, [r4, #0x10]
 *   @0x27ca14 add r12, r0, #1016
 *   @0x27ca18 str r4, [r5, #0x4]
 *   @0x27ca1c mov r2, r6
 *   @0x27ca20 str r1, [r3], #8
 *   @0x27ca24 b 0x27ca2c <_Z11bucketAllocjb+0x4f0>
 *   @0x27ca28 mov r2, r1
 *   @0x27ca2c mov r1, r3
 *   @0x27ca30 str r2, [r3], #8
 *   @0x27ca34 cmp r3, r12
 *   @0x27ca38 bne 0x27ca28 <_Z11bucketAllocjb+0x4ec>
 *   @0x27ca3c add r3, r7, #16320
 *   @0x27ca40 add r0, r0, #1008
 *   @0x27ca44 add r3, r3, #63
 *   @0x27ca48 b 0x27c7b0 <_Z11bucketAllocjb+0x274>
 *   @0x27ca4c movw r0, #0x4008
 *   @0x27ca50 movt r0, #0x4
 *   @0x27ca54 bl 0x27c524 <_Znwj>
 *   @0x27ca58 mov r1, #120
 *   @0x27ca5c mov r2, #278528
 *   @0x27ca60 mov r6, r0
 *   @0x27ca64 add r0, r0, #8
 *   @0x27ca68 bl 0xb65b0 <memset@plt>
 *   @0x27ca6c ldr r2, [r4, #0x4]
 *   @0x27ca70 add r3, r6, #16384
 *   @0x27ca74 add r1, r6, #278528
 *   @0x27ca78 add r3, r3, #8
 *   @0x27ca7c add r1, r1, #7
 *   @0x27ca80 str r2, [r6]
 *   @0x27ca84 bic r3, r3, #16320
 *   @0x27ca88 mov r0, r6
 *   @0x27ca8c bic r5, r3, #63
 *   @0x27ca90 str r6, [r4, #0x4]
 *   @0x27ca94 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_>
 *   @0x27ca98 ldr r0, [r4, #0x8]
 *   @0x27ca9c add r3, r5, #16384
 *   @0x27caa0 ldr r1, [r4, #0x10]
 *   @0x27caa4 add r12, r5, #245760
 *   @0x27caa8 str r4, [r6, #0x4]
 *   @0x27caac mov r2, r5
 *   @0x27cab0 str r0, [r5]
 *   @0x27cab4 b 0x27cabc <_Z11bucketAllocjb+0x580>
 *   @0x27cab8 mov r2, r0
 *   @0x27cabc str r2, [r3]
 *   @0x27cac0 mov r0, r3
 *   @0x27cac4 add r3, r3, #16384
 *   @0x27cac8 cmp r3, r12
 *   @0x27cacc bne 0x27cab8 <_Z11bucketAllocjb+0x57c>
 *   @0x27cad0 add r1, r1, #15
 *   @0x27cad4 add r5, r5, #229376
 *   @0x27cad8 b 0x27c6ac <_Z11bucketAllocjb+0x170>
 *   @0x27cadc mov r0, #24
 *   @0x27cae0 movt r0, #0x4
 *   @0x27cae4 bl 0x27c524 <_Znwj>
 *   @0x27cae8 mov r1, #120
 *   @0x27caec mov r2, #16
 *   @0x27caf0 movt r2, #0x4
 *   @0x27caf4 mov r6, r0
 *   @0x27caf8 add r0, r0, #8
 *   @0x27cafc bl 0xb65b0 <memset@plt>
 *   @0x27cb00 ldr r3, [r4, #0x4]
 *   @0x27cb04 add r1, r6, #262144
 *   @0x27cb08 mov r0, r6
 *   @0x27cb0c add r1, r1, #23
 *   @0x27cb10 add r7, r6, #24
 *   @0x27cb14 str r3, [r6]
 *   @0x27cb18 bic r7, r7, #15
 *   @0x27cb1c str r6, [r4, #0x4]
 *   @0x27cb20 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_>
 *   @0x27cb24 ldr r1, [r4, #0x8]
 *   @0x27cb28 add r5, r7, #261120
 *   @0x27cb2c mov r3, r7
 *   @0x27cb30 ldr r0, [r4, #0x10]
 *   @0x27cb34 add r12, r5, #1008
 *   @0x27cb38 str r4, [r6, #0x4]
 *   @0x27cb3c mov r2, r7
 *   @0x27cb40 str r1, [r3], #16
 *   @0x27cb44 b 0x27cb4c <_Z11bucketAllocjb+0x610>
 *   @0x27cb48 mov r2, r1
 *   @0x27cb4c mov r1, r3
 *   @0x27cb50 str r2, [r3], #16
 *   @0x27cb54 cmp r3, r12
 *   @0x27cb58 bne 0x27cb48 <_Z11bucketAllocjb+0x60c>
 *   @0x27cb5c add r3, r0, #16320
 *   @0x27cb60 add r5, r5, #992
 *   @0x27cb64 add r3, r3, #63
 *   @0x27cb68 b 0x27c81c <_Z11bucketAllocjb+0x2e0>
 *   @0x27cb6c mov r0, #40
 *   @0x27cb70 movt r0, #0x4
 *   @0x27cb74 bl 0x27c524 <_Znwj>
 *   @0x27cb78 mov r1, #120
 *   @0x27cb7c mov r2, #32
 *   @0x27cb80 movt r2, #0x4
 *   @0x27cb84 mov r6, r0
 *   @0x27cb88 add r0, r0, #8
 *   @0x27cb8c bl 0xb65b0 <memset@plt>
 *   @0x27cb90 ldr r3, [r4, #0x4]
 *   @0x27cb94 add r1, r6, #262144
 *   @0x27cb98 mov r0, r6
 *   @0x27cb9c add r1, r1, #39
 *   @0x27cba0 add r7, r6, #40
 *   @0x27cba4 str r3, [r6]
 *   @0x27cba8 bic r7, r7, #31
 *   @0x27cbac str r6, [r4, #0x4]
 *   @0x27cbb0 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_>
 *   @0x27cbb4 ldr r1, [r4, #0x8]
 *   @0x27cbb8 add r5, r7, #261120
 *   @0x27cbbc mov r3, r7
 *   @0x27cbc0 ldr r0, [r4, #0x10]
 *   @0x27cbc4 add r12, r5, #992
 *   @0x27cbc8 str r4, [r6, #0x4]
 *   @0x27cbcc mov r2, r7
 *   @0x27cbd0 str r1, [r3], #32
 *   @0x27cbd4 b 0x27cbdc <_Z11bucketAllocjb+0x6a0>
 *   @0x27cbd8 mov r2, r1
 *   @0x27cbdc mov r1, r3
 *   @0x27cbe0 str r2, [r3], #32
 *   @0x27cbe4 cmp r3, r12
 *   @0x27cbe8 bne 0x27cbd8 <_Z11bucketAllocjb+0x69c>
 *   @0x27cbec add r3, r0, #8128
 *   @0x27cbf0 add r5, r5, #960
 *   @0x27cbf4 add r3, r3, #63
 *   @0x27cbf8 b 0x27c710 <_Z11bucketAllocjb+0x1d4>
 *   @0x27cbfc mov r0, #72
 *   @0x27cc00 movt r0, #0x8
 *   @0x27cc04 bl 0x27c524 <_Znwj>
 *   @0x27cc08 mov r1, #120
 *   @0x27cc0c mov r2, #64
 *   @0x27cc10 movt r2, #0x8
 *   @0x27cc14 mov r6, r0
 *   @0x27cc18 add r0, r0, #8
 *   @0x27cc1c bl 0xb65b0 <memset@plt>
 *   @0x27cc20 ldr r3, [r4, #0x4]
 *   @0x27cc24 add r1, r6, #524288
 *   @0x27cc28 mov r0, r6
 *   @0x27cc2c add r1, r1, #71
 *   @0x27cc30 add r7, r6, #72
 *   @0x27cc34 str r3, [r6]
 *   @0x27cc38 bic r7, r7, #63
 *   @0x27cc3c str r6, [r4, #0x4]
 *   @0x27cc40 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_>
 *   @0x27cc44 ldr r1, [r4, #0x8]
 *   @0x27cc48 add r5, r7, #520192
 *   @0x27cc4c mov r3, r7
 *   @0x27cc50 ldr r0, [r4, #0x10]
 *   @0x27cc54 add r12, r5, #4032
 *   @0x27cc58 str r4, [r6, #0x4]
 *   @0x27cc5c mov r2, r7
 *   @0x27cc60 str r1, [r3], #64
 *   @0x27cc64 b 0x27cc6c <_Z11bucketAllocjb+0x730>
 *   @0x27cc68 mov r2, r1
 *   @0x27cc6c mov r1, r3
 *   @0x27cc70 str r2, [r3], #64
 *   @0x27cc74 cmp r3, r12
 *   @0x27cc78 bne 0x27cc68 <_Z11bucketAllocjb+0x72c>
 *   @0x27cc7c add r3, r0, #8128
 *   @0x27cc80 add r5, r5, #3968
 *   @0x27cc84 add r3, r3, #63
 *   @0x27cc88 b 0x27c86c <_Z11bucketAllocjb+0x330>
 *   @0x27cc8c mov r0, #136
 *   @0x27cc90 movt r0, #0x8
 *   @0x27cc94 bl 0x27c524 <_Znwj>
 *   @0x27cc98 mov r1, #120
 *   @0x27cc9c mov r2, #128
 *   @0x27cca0 movt r2, #0x8
 *   @0x27cca4 mov r6, r0
 *   @0x27cca8 add r0, r0, #8
 *   @0x27ccac bl 0xb65b0 <memset@plt>
 *   @0x27ccb0 ldr r3, [r4, #0x4]
 *   @0x27ccb4 add r1, r6, #524288
 *   @0x27ccb8 mov r0, r6
 *   @0x27ccbc add r1, r1, #135
 *   @0x27ccc0 add r7, r6, #136
 *   @0x27ccc4 str r3, [r6]
 *   @0x27ccc8 bic r7, r7, #127
 *   @0x27cccc str r6, [r4, #0x4]
 *   @0x27ccd0 bl 0x27bcf8 <_Z23addPageToGlobalPageListPvS_>
 *   @0x27ccd4 ldr r1, [r4, #0x8]
 *   @0x27ccd8 add r5, r7, #520192
 *   @0x27ccdc mov r3, r7
 *   @0x27cce0 ldr r0, [r4, #0x10]
 *   @0x27cce4 add r12, r5, #3968
 *   @0x27cce8 str r4, [r6, #0x4]
 *   @0x27ccec mov r2, r7
 *   @0x27ccf0 str r1, [r3], #128
 *   @0x27ccf4 b 0x27ccfc <_Z11bucketAllocjb+0x7c0>
 *   @0x27ccf8 mov r2, r1
 *   @0x27ccfc mov r1, r3
 *   @0x27cd00 str r2, [r3], #128
 *   @0x27cd04 cmp r3, r12
 *   @0x27cd08 bne 0x27ccf8 <_Z11bucketAllocjb+0x7bc>
 *   @0x27cd0c add r3, r0, #4080
 *   @0x27cd10 add r5, r5, #3840
 *   @0x27cd14 add r3, r3, #15
 *   @0x27cd18 b 0x27c8bc <_Z11bucketAllocjb+0x380>
 *   @0x27cd1c subeq r9, sp, r12, lsr pc
 *   @0x27cd20 ldrsheq r5, [r7], -r8
 *   @0x27cd24 .word 0xfffffc00
 *   @0x27cd28 .word 0xfffffbdc
 *   @0x27cd2c .word 0xfffffbe8
 *   @0x27cd30 .word 0xfffffbec
 *   @0x27cd34 .word 0xfffffbe0
 *   @0x27cd38 .word 0xfffffbf8
 *   @0x27cd3c .word 0xfffffbf0
 *   @0x27cd40 .word 0xfffffbf4
 *   @0x27cd44 .word 0xfffffc08
 *   @0x27cd48 .word 0xfffffbfc
 *   @0x27cd4c .word 0xffffbac4
 *   @0x27cd50 andeq r10, sp, r12, ror r8
 *
 * ══ §9/13 _book_unquantize  0x22ee18  size 1852  463 条（0x22ee18..0x22f554）
 * @func 0x22ee18 0x22f554  size 1852  463 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34×2 / _ilog×2 / _book_unquantize+0x2cc / _book_unquantize+0x2a8 / _book_unquantize+0x3e0 / _book_unquantize+0x160 / _book_unquantize+0x30c / 0xb655c
 * 字段偏移 top8: 0x1c×16 / 0x28×12 / 0x4×11 / 0x8×9 / 0x20×9 / 0x2×8 / 0xc×7 / 0x2c×7
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22ee18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22ee1c sub sp, sp, #60
 *   @0x22ee20 mov r4, r0
 *   @0x22ee24 str r1, [sp, #0x30]
 *   @0x22ee28 ldr r1, [r0, #0xc]
 *   @0x22ee2c str r2, [sp, #0x8]
 *   @0x22ee30 sub r1, r1, #1
 *   @0x22ee34 str r3, [sp, #0x14]
 *   @0x22ee38 cmp r1, #1
 *   @0x22ee3c movhi r0, #0
 *   @0x22ee40 bhi 0x22f130 <_book_unquantize+0x318>
 *   @0x22ee44 ldr r3, [r4, #0x10]
 *   @0x22ee48 ubfx r2, r3, #0x0, #0x15
 *   @0x22ee4c str r2, [sp, #0x1c]
 *   @0x22ee50 cmp r2, #0
 *   @0x22ee54 bne 0x22f138 <_book_unquantize+0x320>
 *   @0x22ee58 movw r3, #0xd8f1
 *   @0x22ee5c movt r3, #0xffff
 *   @0x22ee60 str r3, [sp, #0x28]
 *   @0x22ee64 ldr r3, [r4, #0x14]
 *   @0x22ee68 ubfx r12, r3, #0x0, #0x15
 *   @0x22ee6c str r12, [sp, #0x18]
 *   @0x22ee70 cmp r12, #0
 *   @0x22ee74 beq 0x22f234 <_book_unquantize+0x41c>
 *   @0x22ee78 ubfx r2, r3, #0x15, #0xa
 *   @0x22ee7c sub r2, r2, #788
 *   @0x22ee80 str r2, [sp, #0x24]
 *   @0x22ee84 ldr r1, [sp, #0x24]
 *   @0x22ee88 mov r2, r12
 *   @0x22ee8c lsl r2, r2, #1
 *   @0x22ee90 sub r1, r1, #1
 *   @0x22ee94 tst r2, #1073741824
 *   @0x22ee98 beq 0x22ee8c <_book_unquantize+0x74>
 *   @0x22ee9c cmp r3, #0
 *   @0x22eea0 str r2, [sp, #0x18]
 *   @0x22eea4 str r1, [sp, #0x24]
 *   @0x22eea8 rsblt r2, r2, #0
 *   @0x22eeac strlt r2, [sp, #0x18]
 *   @0x22eeb0 ldr r12, [sp, #0x30]
 *   @0x22eeb4 mov r1, #4
 *   @0x22eeb8 ldr r8, [r4]
 *   @0x22eebc mul r5, r12, r8
 *   @0x22eec0 mov r0, r5
 *   @0x22eec4 bl 0xb6c34 <calloc@plt>
 *   @0x22eec8 mov r1, #4
 *   @0x22eecc str r0, [sp, #0xc]
 *   @0x22eed0 mov r0, r5
 *   @0x22eed4 bl 0xb6c34 <calloc@plt>
 *   @0x22eed8 ldr r2, [sp, #0x28]
 *   @0x22eedc ldr r3, [sp, #0x14]
 *   @0x22eee0 str r2, [r3]
 *   @0x22eee4 ldr r7, [r4, #0xc]
 *   @0x22eee8 cmp r7, #1
 *   @0x22eeec mov r6, r0
 *   @0x22eef0 beq 0x22f244 <_book_unquantize+0x42c>
 *   @0x22eef4 cmp r7, #2
 *   @0x22eef8 bne 0x22f0e4 <_book_unquantize+0x2cc>
 *   @0x22eefc ldr r1, [r4, #0x4]
 *   @0x22ef00 cmp r1, #0
 *   @0x22ef04 ble 0x22f0e4 <_book_unquantize+0x2cc>
 *   @0x22ef08 ldr r3, [sp, #0x1c]
 *   @0x22ef0c mov r2, #0
 *   @0x22ef10 ldr r6, [sp, #0x14]
 *   @0x22ef14 mov r5, r2
 *   @0x22ef18 str r2, [sp, #0x20]
 *   @0x22ef1c asr r3, r3, #1
 *   @0x22ef20 str r3, [sp, #0x2c]
 *   @0x22ef24 mov r3, r8
 *   @0x22ef28 str r0, [sp, #0x10]
 *   @0x22ef2c ldr r12, [sp, #0x8]
 *   @0x22ef30 cmp r12, #0
 *   @0x22ef34 beq 0x22ef48 <_book_unquantize+0x130>
 *   @0x22ef38 ldr r2, [r4, #0x8]
 *   @0x22ef3c ldr r2, [r2, r5, lsl #2]
 *   @0x22ef40 cmp r2, #0
 *   @0x22ef44 beq 0x22f0cc <_book_unquantize+0x2b4>
 *   @0x22ef48 cmp r3, #0
 *   @0x22ef4c ble 0x22f0c0 <_book_unquantize+0x2a8>
 *   @0x22ef50 ldr r12, [sp, #0x20]
 *   @0x22ef54 mov r8, #0
 *   @0x22ef58 ldr r1, [sp, #0x18]
 *   @0x22ef5c mov r11, r8
 *   @0x22ef60 ldr r2, [sp, #0x8]
 *   @0x22ef64 mov r10, r8
 *   @0x22ef68 subs r1, r1, r8
 *   @0x22ef6c add r9, r2, r12, lsl #2
 *   @0x22ef70 movne r1, #1
 *   @0x22ef74 str r1, [sp, #0x4]
 *   @0x22ef78 mla r3, r3, r5, r10
 *   @0x22ef7c ldr r2, [r4, #0x20]
 *   @0x22ef80 ldr r2, [r2, r3, lsl #2]
 *   @0x22ef84 eor r7, r2, r2, asr #31
 *   @0x22ef88 sub r7, r7, r2, asr #31
 *   @0x22ef8c mov r0, r7
 *   @0x22ef90 bl 0x22eaf0 <_ilog>
 *   @0x22ef94 ldr r1, [sp, #0x4]
 *   @0x22ef98 sub r0, r0, #31
 *   @0x22ef9c rsb r3, r0, #0
 *   @0x22efa0 lsls r2, r7, r3
 *   @0x22efa4 moveq r3, #0
 *   @0x22efa8 andne r3, r1, #1
 *   @0x22efac cmp r3, #0
 *   @0x22efb0 beq 0x22f53c <_book_unquantize+0x724>
 *   @0x22efb4 ldr r12, [sp, #0x18]
 *   @0x22efb8 smull r2, r3, r12, r2
 *   @0x22efbc ldr r12, [sp, #0x1c]
 *   @0x22efc0 cmp r12, #0
 *   @0x22efc4 ldr r12, [sp, #0x24]
 *   @0x22efc8 add r0, r12, r0
 *   @0x22efcc add r1, r0, #32
 *   @0x22efd0 mov lr, r3
 *   @0x22efd4 beq 0x22f048 <_book_unquantize+0x230>
 *   @0x22efd8 cmp r3, #0
 *   @0x22efdc bne 0x22eff4 <_book_unquantize+0x1dc>
 *   @0x22efe0 cmp r11, #0
 *   @0x22efe4 bne 0x22f174 <_book_unquantize+0x35c>
 *   @0x22efe8 ldr r1, [sp, #0x28]
 *   @0x22efec ldr lr, [sp, #0x1c]
 *   @0x22eff0 b 0x22f060 <_book_unquantize+0x248>
 *   @0x22eff4 ldr r12, [sp, #0x28]
 *   @0x22eff8 cmp r12, r1
 *   @0x22effc ble 0x22f1f8 <_book_unquantize+0x3e0>
 *   @0x22f000 rsb lr, r1, r12
 *   @0x22f004 add r1, r12, #1
 *   @0x22f008 add r0, lr, #1
 *   @0x22f00c cmp r0, #31
 *   @0x22f010 bgt 0x22f228 <_book_unquantize+0x410>
 *   @0x22f014 mov r12, #1
 *   @0x22f018 add r3, r3, r12, lsl lr
 *   @0x22f01c ldr lr, [sp, #0x2c]
 *   @0x22f020 asr r3, r3, r0
 *   @0x22f024 add lr, lr, r3
 *   @0x22f028 ands r2, lr, #-1073741824
 *   @0x22f02c movne r3, #0
 *   @0x22f030 moveq r3, #1
 *   @0x22f034 cmp r2, #-1073741824
 *   @0x22f038 orreq r3, r3, #1
 *   @0x22f03c cmp r3, #0
 *   @0x22f040 lslne lr, lr, #1
 *   @0x22f044 subne r1, r1, #1
 *   @0x22f048 cmp r11, #0
 *   @0x22f04c beq 0x22f060 <_book_unquantize+0x248>
 *   @0x22f050 cmp lr, #0
 *   @0x22f054 moveq r1, r8
 *   @0x22f058 moveq lr, r11
 *   @0x22f05c bne 0x22f17c <_book_unquantize+0x364>
 *   @0x22f060 ldr r3, [r4, #0x1c]
 *   @0x22f064 ldr r2, [sp, #0x8]
 *   @0x22f068 cmp r3, #0
 *   @0x22f06c movne r8, r1
 *   @0x22f070 movne r11, lr
 *   @0x22f074 cmp r2, #0
 *   @0x22f078 ldrne r2, [r4]
 *   @0x22f07c ldreq r3, [r4]
 *   @0x22f080 ldrne r0, [r9]
 *   @0x22f084 ldreq r12, [sp, #0x20]
 *   @0x22f088 movne r3, r2
 *   @0x22f08c mlane r2, r0, r2, r10
 *   @0x22f090 mlaeq r2, r12, r3, r10
 *   @0x22f094 ldr r12, [sp, #0xc]
 *   @0x22f098 add r10, r10, #1
 *   @0x22f09c str lr, [r12, r2, lsl #2]
 *   @0x22f0a0 ldr r12, [sp, #0x10]
 *   @0x22f0a4 str r1, [r12, r2, lsl #2]
 *   @0x22f0a8 ldr r2, [r6]
 *   @0x22f0ac cmp r2, r1
 *   @0x22f0b0 strlt r1, [r6]
 *   @0x22f0b4 cmp r10, r3
 *   @0x22f0b8 blt 0x22ef78 <_book_unquantize+0x160>
 *   @0x22f0bc ldr r1, [r4, #0x4]
 *   @0x22f0c0 ldr r2, [sp, #0x20]
 *   @0x22f0c4 add r2, r2, #1
 *   @0x22f0c8 str r2, [sp, #0x20]
 *   @0x22f0cc add r5, r5, #1
 *   @0x22f0d0 cmp r1, r5
 *   @0x22f0d4 bgt 0x22ef2c <_book_unquantize+0x114>
 *   @0x22f0d8 ldr r12, [sp, #0x30]
 *   @0x22f0dc ldr r6, [sp, #0x10]
 *   @0x22f0e0 mul r5, r3, r12
 *   @0x22f0e4 cmp r5, #0
 *   @0x22f0e8 ble 0x22f124 <_book_unquantize+0x30c>
 *   @0x22f0ec ldr r2, [sp, #0x14]
 *   @0x22f0f0 lsl r5, r5, #2
 *   @0x22f0f4 mov r1, #0
 *   @0x22f0f8 ldr r12, [r2]
 *   @0x22f0fc ldr r2, [sp, #0xc]
 *   @0x22f100 ldr r3, [r6, r1]
 *   @0x22f104 cmp r3, r12
 *   @0x22f108 rsb r3, r3, r12
 *   @0x22f10c ldrlt r0, [r2, r1]
 *   @0x22f110 asrlt r3, r0, r3
 *   @0x22f114 strlt r3, [r2, r1]
 *   @0x22f118 add r1, r1, #4
 *   @0x22f11c cmp r1, r5
 *   @0x22f120 bne 0x22f100 <_book_unquantize+0x2e8>
 *   @0x22f124 mov r0, r6
 *   @0x22f128 bl 0xb655c <free@plt>
 *   @0x22f12c ldr r0, [sp, #0xc]
 *   @0x22f130 add sp, sp, #60
 *   @0x22f134 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22f138 ubfx r2, r3, #0x15, #0xa
 *   @0x22f13c sub r2, r2, #788
 *   @0x22f140 str r2, [sp, #0x28]
 *   @0x22f144 ldr r1, [sp, #0x28]
 *   @0x22f148 ldr r2, [sp, #0x1c]
 *   @0x22f14c lsl r2, r2, #1
 *   @0x22f150 sub r1, r1, #1
 *   @0x22f154 tst r2, #1073741824
 *   @0x22f158 beq 0x22f14c <_book_unquantize+0x334>
 *   @0x22f15c cmp r3, #0
 *   @0x22f160 str r2, [sp, #0x1c]
 *   @0x22f164 str r1, [sp, #0x28]
 *   @0x22f168 rsblt r2, r2, #0
 *   @0x22f16c strlt r2, [sp, #0x1c]
 *   @0x22f170 b 0x22ee64 <_book_unquantize+0x4c>
 *   @0x22f174 ldr lr, [sp, #0x1c]
 *   @0x22f178 ldr r1, [sp, #0x28]
 *   @0x22f17c cmp r1, r8
 *   @0x22f180 bge 0x22f1d0 <_book_unquantize+0x3b8>
 *   @0x22f184 rsb r0, r1, r8
 *   @0x22f188 asr r3, r11, #1
 *   @0x22f18c add r2, r0, #1
 *   @0x22f190 add r1, r8, #1
 *   @0x22f194 cmp r2, #31
 *   @0x22f198 movgt lr, #0
 *   @0x22f19c movle r12, #1
 *   @0x22f1a0 addle lr, lr, r12, lsl r0
 *   @0x22f1a4 asrle lr, lr, r2
 *   @0x22f1a8 add lr, r3, lr
 *   @0x22f1ac ands r2, lr, #-1073741824
 *   @0x22f1b0 movne r3, #0
 *   @0x22f1b4 moveq r3, #1
 *   @0x22f1b8 cmp r2, #-1073741824
 *   @0x22f1bc orreq r3, r3, #1
 *   @0x22f1c0 cmp r3, #0
 *   @0x22f1c4 lslne lr, lr, #1
 *   @0x22f1c8 subne r1, r1, #1
 *   @0x22f1cc b 0x22f060 <_book_unquantize+0x248>
 *   @0x22f1d0 rsb r2, r8, r1
 *   @0x22f1d4 asr lr, lr, #1
 *   @0x22f1d8 add r3, r2, #1
 *   @0x22f1dc add r1, r1, #1
 *   @0x22f1e0 cmp r3, #31
 *   @0x22f1e4 movle r0, #1
 *   @0x22f1e8 movgt r3, #0
 *   @0x22f1ec addle r2, r11, r0, lsl r2
 *   @0x22f1f0 asrle r3, r2, r3
 *   @0x22f1f4 b 0x22f1a8 <_book_unquantize+0x390>
 *   @0x22f1f8 ldr r12, [sp, #0x28]
 *   @0x22f1fc asr r3, r3, #1
 *   @0x22f200 rsb r2, r12, r1
 *   @0x22f204 add r1, r0, #33
 *   @0x22f208 add lr, r2, #1
 *   @0x22f20c cmp lr, #31
 *   @0x22f210 movgt lr, #0
 *   @0x22f214 ldrle r12, [sp, #0x1c]
 *   @0x22f218 movle r0, #1
 *   @0x22f21c addle r2, r12, r0, lsl r2
 *   @0x22f220 asrle lr, r2, lr
 *   @0x22f224 b 0x22f024 <_book_unquantize+0x20c>
 *   @0x22f228 ldr lr, [sp, #0x2c]
 *   @0x22f22c mov r3, #0
 *   @0x22f230 b 0x22f024 <_book_unquantize+0x20c>
 *   @0x22f234 movw r2, #0xd8f1
 *   @0x22f238 movt r2, #0xffff
 *   @0x22f23c str r2, [sp, #0x24]
 *   @0x22f240 b 0x22eeb0 <_book_unquantize+0x98>
 *   @0x22f244 mov r0, r4
 *   @0x22f248 bl 0x22ed88 <_book_maptype1_quantvals>
 *   @0x22f24c ldr r1, [r4, #0x4]
 *   @0x22f250 cmp r1, #0
 *   @0x22f254 mov r8, r0
 *   @0x22f258 ble 0x22f514 <_book_unquantize+0x6fc>
 *   @0x22f25c ldr r12, [sp, #0x1c]
 *   @0x22f260 mov r3, #0
 *   @0x22f264 ldr r2, [r4]
 *   @0x22f268 str r3, [sp, #0x2c]
 *   @0x22f26c asr r12, r12, #1
 *   @0x22f270 str r3, [sp, #0x4]
 *   @0x22f274 str r12, [sp, #0x34]
 *   @0x22f278 str r6, [sp, #0x20]
 *   @0x22f27c ldr r12, [sp, #0x8]
 *   @0x22f280 cmp r12, #0
 *   @0x22f284 beq 0x22f29c <_book_unquantize+0x484>
 *   @0x22f288 ldr r3, [r4, #0x8]
 *   @0x22f28c ldr r12, [sp, #0x4]
 *   @0x22f290 ldr r3, [r3, r12, lsl #2]
 *   @0x22f294 cmp r3, #0
 *   @0x22f298 beq 0x22f48c <_book_unquantize+0x674>
 *   @0x22f29c cmp r2, #0
 *   @0x22f2a0 ble 0x22f480 <_book_unquantize+0x668>
 *   @0x22f2a4 ldr r2, [sp, #0x18]
 *   @0x22f2a8 mov r9, #0
 *   @0x22f2ac ldr r12, [sp, #0x8]
 *   @0x22f2b0 mov r6, r9
 *   @0x22f2b4 subs r2, r2, r9
 *   @0x22f2b8 mov r5, r9
 *   @0x22f2bc mov r11, #1
 *   @0x22f2c0 movne r2, #1
 *   @0x22f2c4 str r2, [sp, #0x10]
 *   @0x22f2c8 ldr r2, [sp, #0x2c]
 *   @0x22f2cc add r10, r12, r2, lsl #2
 *   @0x22f2d0 ldr r0, [sp, #0x4]
 *   @0x22f2d4 mov r1, r11
 *   @0x22f2d8 bl 0x318d10 <__divsi3>
 *   @0x22f2dc mov r1, r8
 *   @0x22f2e0 bl 0x318dec <__aeabi_idivmod>
 *   @0x22f2e4 ldr r3, [r4, #0x20]
 *   @0x22f2e8 ldr r2, [r3, r1, lsl #2]
 *   @0x22f2ec eor r7, r2, r2, asr #31
 *   @0x22f2f0 sub r7, r7, r2, asr #31
 *   @0x22f2f4 mov r0, r7
 *   @0x22f2f8 bl 0x22eaf0 <_ilog>
 *   @0x22f2fc sub r0, r0, #31
 *   @0x22f300 rsb r3, r0, #0
 *   @0x22f304 lsls r2, r7, r3
 *   @0x22f308 ldr r3, [sp, #0x10]
 *   @0x22f30c moveq r1, #0
 *   @0x22f310 andne r1, r3, #1
 *   @0x22f314 cmp r1, #0
 *   @0x22f318 beq 0x22f524 <_book_unquantize+0x70c>
 *   @0x22f31c ldr r12, [sp, #0x18]
 *   @0x22f320 smull r2, r3, r12, r2
 *   @0x22f324 ldr r12, [sp, #0x1c]
 *   @0x22f328 cmp r12, #0
 *   @0x22f32c ldr r12, [sp, #0x24]
 *   @0x22f330 add r0, r12, r0
 *   @0x22f334 add r1, r0, #32
 *   @0x22f338 mov lr, r3
 *   @0x22f33c beq 0x22f400 <_book_unquantize+0x5e8>
 *   @0x22f340 cmp r3, #0
 *   @0x22f344 bne 0x22f3ac <_book_unquantize+0x594>
 *   @0x22f348 cmp r6, #0
 *   @0x22f34c ldr r1, [sp, #0x28]
 *   @0x22f350 ldr lr, [sp, #0x1c]
 *   @0x22f354 beq 0x22f418 <_book_unquantize+0x600>
 *   @0x22f358 cmp r1, r9
 *   @0x22f35c bge 0x22f4b0 <_book_unquantize+0x698>
 *   @0x22f360 rsb r0, r1, r9
 *   @0x22f364 asr r3, r6, #1
 *   @0x22f368 add r2, r0, #1
 *   @0x22f36c add r1, r9, #1
 *   @0x22f370 cmp r2, #31
 *   @0x22f374 movgt lr, #0
 *   @0x22f378 movle r12, #1
 *   @0x22f37c addle lr, lr, r12, lsl r0
 *   @0x22f380 asrle lr, lr, r2
 *   @0x22f384 add lr, r3, lr
 *   @0x22f388 ands r2, lr, #-1073741824
 *   @0x22f38c movne r3, #0
 *   @0x22f390 moveq r3, #1
 *   @0x22f394 cmp r2, #-1073741824
 *   @0x22f398 orreq r3, r3, #1
 *   @0x22f39c cmp r3, #0
 *   @0x22f3a0 lslne lr, lr, #1
 *   @0x22f3a4 subne r1, r1, #1
 *   @0x22f3a8 b 0x22f418 <_book_unquantize+0x600>
 *   @0x22f3ac ldr r12, [sp, #0x28]
 *   @0x22f3b0 cmp r12, r1
 *   @0x22f3b4 ble 0x22f4d8 <_book_unquantize+0x6c0>
 *   @0x22f3b8 rsb lr, r1, r12
 *   @0x22f3bc add r1, r12, #1
 *   @0x22f3c0 add r0, lr, #1
 *   @0x22f3c4 cmp r0, #31
 *   @0x22f3c8 bgt 0x22f508 <_book_unquantize+0x6f0>
 *   @0x22f3cc mov r12, #1
 *   @0x22f3d0 add r3, r3, r12, lsl lr
 *   @0x22f3d4 ldr lr, [sp, #0x34]
 *   @0x22f3d8 asr r3, r3, r0
 *   @0x22f3dc add lr, lr, r3
 *   @0x22f3e0 ands r2, lr, #-1073741824
 *   @0x22f3e4 movne r3, #0
 *   @0x22f3e8 moveq r3, #1
 *   @0x22f3ec cmp r2, #-1073741824
 *   @0x22f3f0 orreq r3, r3, #1
 *   @0x22f3f4 cmp r3, #0
 *   @0x22f3f8 lslne lr, lr, #1
 *   @0x22f3fc subne r1, r1, #1
 *   @0x22f400 cmp r6, #0
 *   @0x22f404 beq 0x22f418 <_book_unquantize+0x600>
 *   @0x22f408 cmp lr, #0
 *   @0x22f40c moveq r1, r9
 *   @0x22f410 moveq lr, r6
 *   @0x22f414 bne 0x22f358 <_book_unquantize+0x540>
 *   @0x22f418 ldr r3, [r4, #0x1c]
 *   @0x22f41c ldr r2, [sp, #0x8]
 *   @0x22f420 cmp r3, #0
 *   @0x22f424 mul r11, r8, r11
 *   @0x22f428 movne r9, r1
 *   @0x22f42c movne r6, lr
 *   @0x22f430 cmp r2, #0
 *   @0x22f434 ldrne r3, [r4]
 *   @0x22f438 ldreq r2, [r4]
 *   @0x22f43c ldrne r0, [r10]
 *   @0x22f440 ldreq r12, [sp, #0x2c]
 *   @0x22f444 movne r2, r3
 *   @0x22f448 mlane r3, r0, r3, r5
 *   @0x22f44c mlaeq r3, r12, r2, r5
 *   @0x22f450 ldr r12, [sp, #0xc]
 *   @0x22f454 add r5, r5, #1
 *   @0x22f458 str lr, [r12, r3, lsl #2]
 *   @0x22f45c ldr r12, [sp, #0x20]
 *   @0x22f460 str r1, [r12, r3, lsl #2]
 *   @0x22f464 ldr r12, [sp, #0x14]
 *   @0x22f468 ldr r3, [r12]
 *   @0x22f46c cmp r3, r1
 *   @0x22f470 strlt r1, [r12]
 *   @0x22f474 cmp r5, r2
 *   @0x22f478 blt 0x22f2d0 <_book_unquantize+0x4b8>
 *   @0x22f47c ldr r1, [r4, #0x4]
 *   @0x22f480 ldr r3, [sp, #0x2c]
 *   @0x22f484 add r3, r3, #1
 *   @0x22f488 str r3, [sp, #0x2c]
 *   @0x22f48c ldr r12, [sp, #0x4]
 *   @0x22f490 add r12, r12, #1
 *   @0x22f494 str r12, [sp, #0x4]
 *   @0x22f498 cmp r1, r12
 *   @0x22f49c bgt 0x22f27c <_book_unquantize+0x464>
 *   @0x22f4a0 ldr r12, [sp, #0x30]
 *   @0x22f4a4 ldr r6, [sp, #0x20]
 *   @0x22f4a8 mul r5, r2, r12
 *   @0x22f4ac b 0x22f0e4 <_book_unquantize+0x2cc>
 *   @0x22f4b0 rsb r2, r9, r1
 *   @0x22f4b4 asr lr, lr, #1
 *   @0x22f4b8 add r3, r2, #1
 *   @0x22f4bc add r1, r1, #1
 *   @0x22f4c0 cmp r3, #31
 *   @0x22f4c4 movle r0, #1
 *   @0x22f4c8 movgt r3, #0
 *   @0x22f4cc addle r2, r6, r0, lsl r2
 *   @0x22f4d0 asrle r3, r2, r3
 *   @0x22f4d4 b 0x22f384 <_book_unquantize+0x56c>
 *   @0x22f4d8 ldr r12, [sp, #0x28]
 *   @0x22f4dc asr r3, r3, #1
 *   @0x22f4e0 rsb r2, r12, r1
 *   @0x22f4e4 add r1, r0, #33
 *   @0x22f4e8 add lr, r2, #1
 *   @0x22f4ec cmp lr, #31
 *   @0x22f4f0 movgt lr, #0
 *   @0x22f4f4 ldrle r12, [sp, #0x1c]
 *   @0x22f4f8 movle r0, #1
 *   @0x22f4fc addle r2, r12, r0, lsl r2
 *   @0x22f500 asrle lr, r2, lr
 *   @0x22f504 b 0x22f3dc <_book_unquantize+0x5c4>
 *   @0x22f508 ldr lr, [sp, #0x34]
 *   @0x22f50c mov r3, #0
 *   @0x22f510 b 0x22f3dc <_book_unquantize+0x5c4>
 *   @0x22f514 ldr r5, [r4]
 *   @0x22f518 ldr r12, [sp, #0x30]
 *   @0x22f51c mul r5, r5, r12
 *   @0x22f520 b 0x22f0e4 <_book_unquantize+0x2cc>
 *   @0x22f524 ldr r3, [sp, #0x1c]
 *   @0x22f528 cmp r3, #0
 *   @0x22f52c bne 0x22f348 <_book_unquantize+0x530>
 *   @0x22f530 ldr lr, [sp, #0x1c]
 *   @0x22f534 mov r1, lr
 *   @0x22f538 b 0x22f400 <_book_unquantize+0x5e8>
 *   @0x22f53c ldr r12, [sp, #0x1c]
 *   @0x22f540 cmp r12, #0
 *   @0x22f544 bne 0x22efe0 <_book_unquantize+0x1c8>
 *   @0x22f548 ldr lr, [sp, #0x1c]
 *   @0x22f54c mov r1, lr
 *   @0x22f550 b 0x22f048 <_book_unquantize+0x230>
 *
 * ══ §10/13 GET_RValue  0xd13bc  size 1840  460 条（0xd13bc..0xd1aec）
 * @func 0xd13bc 0xd1aec  size 1840  460 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd15c4→0x75505d, 0xd15cc→0x755058, 0xd15d4→0x755054, 0xd15f4→0x755050, 0xd1608→0x75504c, 0xd16a4→0x755050, 0xd1a48→0x75505d, 0xd1a50→0x755058
 * 调用序列: LOCK_RVALUE_MUTEX()×9 / UNLOCK_RVALUE_MUTEX()×9 / YYFree(void const*)×9 / operator delete(void*)×9 / FREE_RValue__Pre(RValue*)×3 / _RefThing<char const*>::dec()×3 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2
 * 字段偏移 top8: 0x4×33 / 0x8×21 / 0xc×19 / 0x84×2 / 0x6fc×1 / 0x6e0×1 / 0x50c×1 / 0x508×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd13bc ldr r3, [r1, #0xc]
 *   @0xd13c0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xd13c4 mov r5, r1
 *   @0xd13c8 bic r1, r3, #-16777216
 *   @0xd13cc ldr r6, [pc, #0x6fc]
 *   @0xd13d0 cmp r1, #2
 *   @0xd13d4 sub sp, sp, #12
 *   @0xd13d8 add r6, pc, r6
 *   @0xd13dc mov r4, r0
 *   @0xd13e0 beq 0xd1594 <_Z10GET_RValueP6RValueS0_i+0x1d8>
 *   @0xd13e4 cmp r2, #-2147483648
 *   @0xd13e8 beq 0xd13f8 <_Z10GET_RValueP6RValueS0_i+0x3c>
 *   @0xd13ec ldr r0, [pc, #0x6e0]
 *   @0xd13f0 add r0, pc, r0
 *   @0xd13f4 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd13f8 ldr r2, [r4, #0xc]
 *   @0xd13fc bic r3, r2, #-16777216
 *   @0xd1400 cmp r3, #1
 *   @0xd1404 beq 0xd149c <_Z10GET_RValueP6RValueS0_i+0xe0>
 *   @0xd1408 cmp r3, #2
 *   @0xd140c bne 0xd1434 <_Z10GET_RValueP6RValueS0_i+0x78>
 *   @0xd1410 sub r2, r2, #1
 *   @0xd1414 bic r2, r2, #-16777216
 *   @0xd1418 bic r2, r2, #3
 *   @0xd141c cmp r2, #0
 *   @0xd1420 beq 0xd1588 <_Z10GET_RValueP6RValueS0_i+0x1cc>
 *   @0xd1424 mov r2, #0
 *   @0xd1428 mov r3, #5
 *   @0xd142c str r2, [r4, #0x8]
 *   @0xd1430 str r3, [r4, #0xc]
 *   @0xd1434 ldr r3, [r5, #0xc]
 *   @0xd1438 mov r1, #0
 *   @0xd143c ldr r2, [r5, #0x8]
 *   @0xd1440 str r1, [r4]
 *   @0xd1444 str r3, [r4, #0xc]
 *   @0xd1448 ldr r3, [r5, #0xc]
 *   @0xd144c str r2, [r4, #0x8]
 *   @0xd1450 bic r3, r3, #-16777216
 *   @0xd1454 cmp r3, #14
 *   @0xd1458 addls pc, pc, r3, lsl #2
 *   @0xd145c b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1460 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128>
 *   @0xd1464 b 0xd1524 <_Z10GET_RValueP6RValueS0_i+0x168>
 *   @0xd1468 b 0xd154c <_Z10GET_RValueP6RValueS0_i+0x190>
 *   @0xd146c b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114>
 *   @0xd1470 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1474 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1478 b 0xd14fc <_Z10GET_RValueP6RValueS0_i+0x140>
 *   @0xd147c b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114>
 *   @0xd1480 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1484 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1488 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128>
 *   @0xd148c b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1490 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1494 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128>
 *   @0xd1498 b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114>
 *   @0xd149c ldr r6, [r4]
 *   @0xd14a0 cmp r6, #0
 *   @0xd14a4 beq 0xd14c4 <_Z10GET_RValueP6RValueS0_i+0x108>
 *   @0xd14a8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd14ac ldr r7, [r6, #0x4]
 *   @0xd14b0 sub r7, r7, #1
 *   @0xd14b4 str r7, [r6, #0x4]
 *   @0xd14b8 cmp r7, #0
 *   @0xd14bc beq 0xd162c <_Z10GET_RValueP6RValueS0_i+0x270>
 *   @0xd14c0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd14c4 mov r3, #0
 *   @0xd14c8 str r3, [r4]
 *   @0xd14cc b 0xd1434 <_Z10GET_RValueP6RValueS0_i+0x78>
 *   @0xd14d0 ldr r3, [r5]
 *   @0xd14d4 mov r0, #1
 *   @0xd14d8 str r3, [r4]
 *   @0xd14dc add sp, sp, #12
 *   @0xd14e0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xd14e4 ldr r2, [r5]
 *   @0xd14e8 mov r0, #1
 *   @0xd14ec ldr r3, [r5, #0x4]
 *   @0xd14f0 stm r4, {r2, r3}
 *   @0xd14f4 add sp, sp, #12
 *   @0xd14f8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xd14fc ldr r3, [r5]
 *   @0xd1500 str r3, [r4]
 *   @0xd1504 ldr r3, [r5]
 *   @0xd1508 cmp r3, #0
 *   @0xd150c beq 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1510 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xd1514 ldr r1, [r5]
 *   @0xd1518 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xd151c mov r0, #1
 *   @0xd1520 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120>
 *   @0xd1524 ldr r3, [r5]
 *   @0xd1528 cmp r3, #0
 *   @0xd152c beq 0xd153c <_Z10GET_RValueP6RValueS0_i+0x180>
 *   @0xd1530 ldr r2, [r3, #0x4]
 *   @0xd1534 add r2, r2, #1
 *   @0xd1538 str r2, [r3, #0x4]
 *   @0xd153c mov r0, #1
 *   @0xd1540 str r3, [r4]
 *   @0xd1544 add sp, sp, #12
 *   @0xd1548 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xd154c ldr r3, [r5]
 *   @0xd1550 cmp r3, #0
 *   @0xd1554 str r3, [r4]
 *   @0xd1558 beq 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd155c ldr r1, [r3, #0x8]
 *   @0xd1560 ldr r2, [r3]
 *   @0xd1564 cmp r1, #0
 *   @0xd1568 streq r4, [r3, #0x8]
 *   @0xd156c add r2, r2, #1
 *   @0xd1570 str r2, [r3]
 *   @0xd1574 moveq r0, #1
 *   @0xd1578 beq 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120>
 *   @0xd157c mov r0, #1
 *   @0xd1580 add sp, sp, #12
 *   @0xd1584 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xd1588 mov r0, r4
 *   @0xd158c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xd1590 b 0xd1424 <_Z10GET_RValueP6RValueS0_i+0x68>
 *   @0xd1594 cmp r2, #-2147483648
 *   @0xd1598 beq 0xd185c <_Z10GET_RValueP6RValueS0_i+0x4a0>
 *   @0xd159c mov r1, r2
 *   @0xd15a0 mov r0, sp
 *   @0xd15a4 mov r2, #32000
 *   @0xd15a8 bl 0xb664c <ldiv@plt>
 *   @0xd15ac ldr r3, [r5, #0xc]
 *   @0xd15b0 ldr r2, [sp]
 *   @0xd15b4 bic r3, r3, #-16777216
 *   @0xd15b8 ldr r7, [sp, #0x4]
 *   @0xd15bc cmp r3, #2
 *   @0xd15c0 beq 0xd16c8 <_Z10GET_RValueP6RValueS0_i+0x30c>
 *   @0xd15c4 ldr r0, [pc, #0x50c]
 *   @0xd15c8 mov r12, #1
 *   @0xd15cc ldr r1, [pc, #0x508]
 *   @0xd15d0 cmp r3, #2
 *   @0xd15d4 ldr r3, [pc, #0x504]
 *   @0xd15d8 ldr r0, [r6, r0]
 *   @0xd15dc strb r12, [r0]
 *   @0xd15e0 ldr r1, [r6, r1]
 *   @0xd15e4 str r2, [r1]
 *   @0xd15e8 ldr r3, [r6, r3]
 *   @0xd15ec str r7, [r3]
 *   @0xd15f0 beq 0xd169c <_Z10GET_RValueP6RValueS0_i+0x2e0>
 *   @0xd15f4 ldr r3, [pc, #0x4e8]
 *   @0xd15f8 mvn r1, #0
 *   @0xd15fc mov r2, #0
 *   @0xd1600 ldr r3, [r6, r3]
 *   @0xd1604 str r2, [r3]
 *   @0xd1608 ldr r2, [pc, #0x4d8]
 *   @0xd160c mov r3, #0
 *   @0xd1610 mov r0, r3
 *   @0xd1614 ldr r2, [r6, r2]
 *   @0xd1618 str r3, [r4, #0xc]
 *   @0xd161c str r3, [r4, #0x4]
 *   @0xd1620 str r1, [r2]
 *   @0xd1624 str r3, [r4]
 *   @0xd1628 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120>
 *   @0xd162c ldr r0, [r6]
 *   @0xd1630 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd1634 str r7, [r6]
 *   @0xd1638 str r7, [r6, #0x8]
 *   @0xd163c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd1640 ldr r7, [r6, #0x4]
 *   @0xd1644 sub r7, r7, #1
 *   @0xd1648 str r7, [r6, #0x4]
 *   @0xd164c cmp r7, #0
 *   @0xd1650 beq 0xd1664 <_Z10GET_RValueP6RValueS0_i+0x2a8>
 *   @0xd1654 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd1658 mov r0, r6
 *   @0xd165c bl 0x27d1d0 <_ZdlPv>
 *   @0xd1660 b 0xd14c0 <_Z10GET_RValueP6RValueS0_i+0x104>
 *   @0xd1664 ldr r0, [r6]
 *   @0xd1668 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd166c str r7, [r6]
 *   @0xd1670 str r7, [r6, #0x8]
 *   @0xd1674 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd1678 ldr r7, [r6, #0x4]
 *   @0xd167c sub r7, r7, #1
 *   @0xd1680 str r7, [r6, #0x4]
 *   @0xd1684 cmp r7, #0
 *   @0xd1688 beq 0xd19e4 <_Z10GET_RValueP6RValueS0_i+0x628>
 *   @0xd168c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd1690 mov r0, r6
 *   @0xd1694 bl 0x27d1d0 <_ZdlPv>
 *   @0xd1698 b 0xd1654 <_Z10GET_RValueP6RValueS0_i+0x298>
 *   @0xd169c mov r3, #0
 *   @0xd16a0 ldr r2, [r5]
 *   @0xd16a4 ldr r1, [pc, #0x438]
 *   @0xd16a8 cmp r2, #0
 *   @0xd16ac ldr r1, [r6, r1]
 *   @0xd16b0 ldrne r2, [r2, #0x10]
 *   @0xd16b4 cmp r3, #0
 *   @0xd16b8 str r2, [r1]
 *   @0xd16bc mvneq r1, #0
 *   @0xd16c0 ldrne r1, [r3]
 *   @0xd16c4 b 0xd1608 <_Z10GET_RValueP6RValueS0_i+0x24c>
 *   @0xd16c8 ldr r1, [r5]
 *   @0xd16cc ldr r0, [r1, #0x8]
 *   @0xd16d0 cmp r0, #0
 *   @0xd16d4 streq r5, [r1, #0x8]
 *   @0xd16d8 cmp r2, #0
 *   @0xd16dc blt 0xd15c4 <_Z10GET_RValueP6RValueS0_i+0x208>
 *   @0xd16e0 ldr r0, [r1, #0x10]
 *   @0xd16e4 cmp r0, r2
 *   @0xd16e8 ble 0xd15c4 <_Z10GET_RValueP6RValueS0_i+0x208>
 *   @0xd16ec ldr r1, [r1, #0x4]
 *   @0xd16f0 cmp r7, #0
 *   @0xd16f4 add r3, r1, r2, lsl #3
 *   @0xd16f8 blt 0xd1a48 <_Z10GET_RValueP6RValueS0_i+0x68c>
 *   @0xd16fc ldr r1, [r1, r2, lsl #3]
 *   @0xd1700 cmp r7, r1
 *   @0xd1704 bge 0xd1a48 <_Z10GET_RValueP6RValueS0_i+0x68c>
 *   @0xd1708 ldr r9, [r3, #0x4]
 *   @0xd170c adds r8, r9, r7, lsl #4
 *   @0xd1710 beq 0xd1a48 <_Z10GET_RValueP6RValueS0_i+0x68c>
 *   @0xd1714 ldr r2, [r4, #0xc]
 *   @0xd1718 bic r3, r2, #-16777216
 *   @0xd171c cmp r3, #1
 *   @0xd1720 beq 0xd1828 <_Z10GET_RValueP6RValueS0_i+0x46c>
 *   @0xd1724 cmp r3, #2
 *   @0xd1728 bne 0xd1750 <_Z10GET_RValueP6RValueS0_i+0x394>
 *   @0xd172c sub r3, r2, #1
 *   @0xd1730 bic r3, r3, #-16777216
 *   @0xd1734 bic r3, r3, #3
 *   @0xd1738 cmp r3, #0
 *   @0xd173c beq 0xd1a3c <_Z10GET_RValueP6RValueS0_i+0x680>
 *   @0xd1740 mov r2, #0
 *   @0xd1744 mov r3, #5
 *   @0xd1748 str r2, [r4, #0x8]
 *   @0xd174c str r3, [r4, #0xc]
 *   @0xd1750 ldr r3, [r8, #0xc]
 *   @0xd1754 mov r1, #0
 *   @0xd1758 ldr r2, [r8, #0x8]
 *   @0xd175c str r1, [r4]
 *   @0xd1760 str r3, [r4, #0xc]
 *   @0xd1764 ldr r3, [r8, #0xc]
 *   @0xd1768 str r2, [r4, #0x8]
 *   @0xd176c bic r3, r3, #-16777216
 *   @0xd1770 cmp r3, #14
 *   @0xd1774 addls pc, pc, r3, lsl #2
 *   @0xd1778 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd177c b 0xd17c8 <_Z10GET_RValueP6RValueS0_i+0x40c>
 *   @0xd1780 b 0xd1818 <_Z10GET_RValueP6RValueS0_i+0x45c>
 *   @0xd1784 b 0xd1804 <_Z10GET_RValueP6RValueS0_i+0x448>
 *   @0xd1788 b 0xd17b8 <_Z10GET_RValueP6RValueS0_i+0x3fc>
 *   @0xd178c b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1790 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1794 b 0xd17dc <_Z10GET_RValueP6RValueS0_i+0x420>
 *   @0xd1798 b 0xd17b8 <_Z10GET_RValueP6RValueS0_i+0x3fc>
 *   @0xd179c b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd17a0 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd17a4 b 0xd17c8 <_Z10GET_RValueP6RValueS0_i+0x40c>
 *   @0xd17a8 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd17ac b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd17b0 b 0xd17c8 <_Z10GET_RValueP6RValueS0_i+0x40c>
 *   @0xd17b4 b 0xd17b8 <_Z10GET_RValueP6RValueS0_i+0x3fc>
 *   @0xd17b8 ldr r3, [r9, r7, lsl #4]
 *   @0xd17bc mov r0, #1
 *   @0xd17c0 str r3, [r4]
 *   @0xd17c4 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120>
 *   @0xd17c8 ldr r2, [r9, r7, lsl #4]
 *   @0xd17cc mov r0, #1
 *   @0xd17d0 ldr r3, [r8, #0x4]
 *   @0xd17d4 stm r4, {r2, r3}
 *   @0xd17d8 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120>
 *   @0xd17dc ldr r3, [r9, r7, lsl #4]
 *   @0xd17e0 str r3, [r4]
 *   @0xd17e4 ldr r3, [r9, r7, lsl #4]
 *   @0xd17e8 cmp r3, #0
 *   @0xd17ec beq 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd17f0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xd17f4 ldr r1, [r9, r7, lsl #4]
 *   @0xd17f8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xd17fc mov r0, #1
 *   @0xd1800 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120>
 *   @0xd1804 ldr r3, [r9, r7, lsl #4]
 *   @0xd1808 cmp r3, #0
 *   @0xd180c str r3, [r4]
 *   @0xd1810 bne 0xd155c <_Z10GET_RValueP6RValueS0_i+0x1a0>
 *   @0xd1814 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1818 ldr r3, [r9, r7, lsl #4]
 *   @0xd181c cmp r3, #0
 *   @0xd1820 bne 0xd1530 <_Z10GET_RValueP6RValueS0_i+0x174>
 *   @0xd1824 b 0xd153c <_Z10GET_RValueP6RValueS0_i+0x180>
 *   @0xd1828 ldr r5, [r4]
 *   @0xd182c cmp r5, #0
 *   @0xd1830 beq 0xd1850 <_Z10GET_RValueP6RValueS0_i+0x494>
 *   @0xd1834 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd1838 ldr r6, [r5, #0x4]
 *   @0xd183c sub r6, r6, #1
 *   @0xd1840 str r6, [r5, #0x4]
 *   @0xd1844 cmp r6, #0
 *   @0xd1848 beq 0xd19ac <_Z10GET_RValueP6RValueS0_i+0x5f0>
 *   @0xd184c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd1850 mov r3, #0
 *   @0xd1854 str r3, [r4]
 *   @0xd1858 b 0xd1750 <_Z10GET_RValueP6RValueS0_i+0x394>
 *   @0xd185c ldr r2, [r5]
 *   @0xd1860 ldr r1, [r2, #0x8]
 *   @0xd1864 cmp r1, #0
 *   @0xd1868 streq r5, [r2, #0x8]
 *   @0xd186c ldr r1, [r4, #0xc]
 *   @0xd1870 bic r2, r1, #-16777216
 *   @0xd1874 cmp r2, #1
 *   @0xd1878 beq 0xd1910 <_Z10GET_RValueP6RValueS0_i+0x554>
 *   @0xd187c cmp r2, #2
 *   @0xd1880 bne 0xd18ac <_Z10GET_RValueP6RValueS0_i+0x4f0>
 *   @0xd1884 sub r1, r1, #1
 *   @0xd1888 bic r1, r1, #-16777216
 *   @0xd188c bic r1, r1, #3
 *   @0xd1890 cmp r1, #0
 *   @0xd1894 beq 0xd19a0 <_Z10GET_RValueP6RValueS0_i+0x5e4>
 *   @0xd1898 mov r3, #0
 *   @0xd189c mov r2, #5
 *   @0xd18a0 str r3, [r4, #0x8]
 *   @0xd18a4 str r2, [r4, #0xc]
 *   @0xd18a8 ldr r3, [r5, #0xc]
 *   @0xd18ac ldr r2, [r5, #0x8]
 *   @0xd18b0 mov r1, #0
 *   @0xd18b4 str r3, [r4, #0xc]
 *   @0xd18b8 ldr r3, [r5, #0xc]
 *   @0xd18bc str r1, [r4]
 *   @0xd18c0 bic r3, r3, #-16777216
 *   @0xd18c4 str r2, [r4, #0x8]
 *   @0xd18c8 cmp r3, #14
 *   @0xd18cc addls pc, pc, r3, lsl #2
 *   @0xd18d0 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd18d4 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128>
 *   @0xd18d8 b 0xd1524 <_Z10GET_RValueP6RValueS0_i+0x168>
 *   @0xd18dc b 0xd154c <_Z10GET_RValueP6RValueS0_i+0x190>
 *   @0xd18e0 b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114>
 *   @0xd18e4 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd18e8 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd18ec b 0xd14fc <_Z10GET_RValueP6RValueS0_i+0x140>
 *   @0xd18f0 b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114>
 *   @0xd18f4 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd18f8 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd18fc b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128>
 *   @0xd1900 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1904 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0>
 *   @0xd1908 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128>
 *   @0xd190c b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114>
 *   @0xd1910 ldr r6, [r4]
 *   @0xd1914 cmp r6, #0
 *   @0xd1918 beq 0xd193c <_Z10GET_RValueP6RValueS0_i+0x580>
 *   @0xd191c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd1920 ldr r7, [r6, #0x4]
 *   @0xd1924 sub r7, r7, #1
 *   @0xd1928 str r7, [r6, #0x4]
 *   @0xd192c cmp r7, #0
 *   @0xd1930 beq 0xd1948 <_Z10GET_RValueP6RValueS0_i+0x58c>
 *   @0xd1934 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd1938 ldr r3, [r5, #0xc]
 *   @0xd193c mov r2, #0
 *   @0xd1940 str r2, [r4]
 *   @0xd1944 b 0xd18ac <_Z10GET_RValueP6RValueS0_i+0x4f0>
 *   @0xd1948 ldr r0, [r6]
 *   @0xd194c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd1950 str r7, [r6]
 *   @0xd1954 str r7, [r6, #0x8]
 *   @0xd1958 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd195c ldr r7, [r6, #0x4]
 *   @0xd1960 sub r7, r7, #1
 *   @0xd1964 str r7, [r6, #0x4]
 *   @0xd1968 cmp r7, #0
 *   @0xd196c bne 0xd1990 <_Z10GET_RValueP6RValueS0_i+0x5d4>
 *   @0xd1970 ldr r0, [r6]
 *   @0xd1974 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd1978 mov r0, r6
 *   @0xd197c str r7, [r6]
 *   @0xd1980 str r7, [r6, #0x8]
 *   @0xd1984 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xd1988 mov r0, r6
 *   @0xd198c bl 0x27d1d0 <_ZdlPv>
 *   @0xd1990 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd1994 mov r0, r6
 *   @0xd1998 bl 0x27d1d0 <_ZdlPv>
 *   @0xd199c b 0xd1934 <_Z10GET_RValueP6RValueS0_i+0x578>
 *   @0xd19a0 mov r0, r4
 *   @0xd19a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xd19a8 b 0xd1898 <_Z10GET_RValueP6RValueS0_i+0x4dc>
 *   @0xd19ac ldr r0, [r5]
 *   @0xd19b0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd19b4 str r6, [r5]
 *   @0xd19b8 str r6, [r5, #0x8]
 *   @0xd19bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd19c0 ldr r6, [r5, #0x4]
 *   @0xd19c4 sub r6, r6, #1
 *   @0xd19c8 str r6, [r5, #0x4]
 *   @0xd19cc cmp r6, #0
 *   @0xd19d0 beq 0xd1a74 <_Z10GET_RValueP6RValueS0_i+0x6b8>
 *   @0xd19d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd19d8 mov r0, r5
 *   @0xd19dc bl 0x27d1d0 <_ZdlPv>
 *   @0xd19e0 b 0xd184c <_Z10GET_RValueP6RValueS0_i+0x490>
 *   @0xd19e4 ldr r0, [r6]
 *   @0xd19e8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd19ec str r7, [r6]
 *   @0xd19f0 str r7, [r6, #0x8]
 *   @0xd19f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd19f8 ldr r7, [r6, #0x4]
 *   @0xd19fc sub r7, r7, #1
 *   @0xd1a00 str r7, [r6, #0x4]
 *   @0xd1a04 cmp r7, #0
 *   @0xd1a08 bne 0xd1a2c <_Z10GET_RValueP6RValueS0_i+0x670>
 *   @0xd1a0c ldr r0, [r6]
 *   @0xd1a10 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd1a14 mov r0, r6
 *   @0xd1a18 str r7, [r6]
 *   @0xd1a1c str r7, [r6, #0x8]
 *   @0xd1a20 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xd1a24 mov r0, r6
 *   @0xd1a28 bl 0x27d1d0 <_ZdlPv>
 *   @0xd1a2c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd1a30 mov r0, r6
 *   @0xd1a34 bl 0x27d1d0 <_ZdlPv>
 *   @0xd1a38 b 0xd168c <_Z10GET_RValueP6RValueS0_i+0x2d0>
 *   @0xd1a3c mov r0, r4
 *   @0xd1a40 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xd1a44 b 0xd1740 <_Z10GET_RValueP6RValueS0_i+0x384>
 *   @0xd1a48 ldr r12, [pc, #0x88]
 *   @0xd1a4c mov r8, #1
 *   @0xd1a50 ldr r0, [pc, #0x84]
 *   @0xd1a54 ldr r1, [pc, #0x84]
 *   @0xd1a58 ldr r12, [r6, r12]
 *   @0xd1a5c strb r8, [r12]
 *   @0xd1a60 ldr r0, [r6, r0]
 *   @0xd1a64 str r2, [r0]
 *   @0xd1a68 ldr r2, [r6, r1]
 *   @0xd1a6c str r7, [r2]
 *   @0xd1a70 b 0xd16a0 <_Z10GET_RValueP6RValueS0_i+0x2e4>
 *   @0xd1a74 ldr r0, [r5]
 *   @0xd1a78 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd1a7c str r6, [r5]
 *   @0xd1a80 str r6, [r5, #0x8]
 *   @0xd1a84 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd1a88 ldr r3, [r5, #0x4]
 *   @0xd1a8c sub r3, r3, #1
 *   @0xd1a90 str r3, [r5, #0x4]
 *   @0xd1a94 cmp r3, #0
 *   @0xd1a98 bne 0xd1ac0 <_Z10GET_RValueP6RValueS0_i+0x704>
 *   @0xd1a9c ldr r0, [r5]
 *   @0xd1aa0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd1aa4 mov r3, #0
 *   @0xd1aa8 mov r0, r5
 *   @0xd1aac str r3, [r5]
 *   @0xd1ab0 str r3, [r5, #0x8]
 *   @0xd1ab4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xd1ab8 mov r0, r5
 *   @0xd1abc bl 0x27d1d0 <_ZdlPv>
 *   @0xd1ac0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd1ac4 mov r0, r5
 *   @0xd1ac8 bl 0x27d1d0 <_ZdlPv>
 *   @0xd1acc b 0xd19d4 <_Z10GET_RValueP6RValueS0_i+0x618>
 *   @0xd1ad0 eorseq r0, r2, r8, ror r8
 *   @0xd1ad4 .word 0x002612bc
 *   @0xd1ad8 .word 0xffffbf24
 *   @0xd1adc .word 0xffffbf28
 *   @0xd1ae0 .word 0xffffbf2c
 *   @0xd1ae4 .word 0xffffbf30
 *   @0xd1ae8 .word 0xffffbf34
 *
 * ══ §11/13 DrawLayerTilemapElement  0x1b2124  size 1808  452 条（0x1b2124..0x1b2834）
 * @func 0x1b2124 0x1b2834  size 1808  452 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / DrawLayerTilemapElement(tagYYRECT*, CLayer*, CLayerTilemapElement*, float, float, float)+0x34×2 / __aeabi_uidivmod×2 / __udivsi3×2 / Background_Exists(int) / Background_Data(int) / CalcLayerTilemapParams(CBackground*, RTexture**, float&, float&, float&, float&, float&, float&, float&, float&, bool&) / DrawLayerTilemapElement(tagYYRECT*, CLayer*, CLayerTilemapElement*, float, float, float)+0x338
 * 字段偏移 top8: 0x3c×8 / 0x40×7 / 0x44×7 / 0x34×7 / 0x30×6 / 0x38×5 / 0x2c×5 / 0x1c×4
 * VFP 指令 186 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b2124 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1b2128 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1b212c sub sp, sp, #140
 *   @0x1b2130 vldr s27, [sp, #240]
 *   @0x1b2134 mov r4, r0
 *   @0x1b2138 ldr r0, [r2, #0x1c]
 *   @0x1b213c mov r7, r2
 *   @0x1b2140 str r1, [sp, #0x40]
 *   @0x1b2144 vmov s26, r3
 *   @0x1b2148 vldr s16, [sp, #244]
 *   @0x1b214c bl 0xc3640 <_Z17Background_Existsi>
 *   @0x1b2150 cmp r0, #0
 *   @0x1b2154 bne 0x1b2164 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x40>
 *   @0x1b2158 add sp, sp, #140
 *   @0x1b215c vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1b2160 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1b2164 ldr r0, [r7, #0x1c]
 *   @0x1b2168 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1b216c add r3, sp, #108
 *   @0x1b2170 add r1, sp, #132
 *   @0x1b2174 str r3, [sp]
 *   @0x1b2178 add r2, sp, #100
 *   @0x1b217c add r3, sp, #112
 *   @0x1b2180 str r3, [sp, #0x4]
 *   @0x1b2184 add r3, sp, #116
 *   @0x1b2188 str r3, [sp, #0x8]
 *   @0x1b218c add r3, sp, #120
 *   @0x1b2190 str r3, [sp, #0xc]
 *   @0x1b2194 add r3, sp, #124
 *   @0x1b2198 str r3, [sp, #0x10]
 *   @0x1b219c add r3, sp, #128
 *   @0x1b21a0 str r3, [sp, #0x14]
 *   @0x1b21a4 add r3, sp, #99
 *   @0x1b21a8 str r3, [sp, #0x18]
 *   @0x1b21ac add r3, sp, #104
 *   @0x1b21b0 mov r11, r0
 *   @0x1b21b4 bl 0x1b19c4 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb>
 *   @0x1b21b8 ldr r10, [sp, #0x40]
 *   @0x1b21bc cmp r10, #0
 *   @0x1b21c0 beq 0x1b21e8 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0xc4>
 *   @0x1b21c4 vldr s15, [r7, #32]
 *   @0x1b21c8 vldr s26, [r10, #8]
 *   @0x1b21cc vldr s27, [r10, #12]
 *   @0x1b21d0 vadd.f32 s26, s26, s15
 *   @0x1b21d4 vldr s15, [r7, #36]
 *   @0x1b21d8 ldr r3, [pc, #0x3ec]
 *   @0x1b21dc ldr r3, [pc, r3]
 *   @0x1b21e0 vldr s16, [r3]
 *   @0x1b21e4 vadd.f32 s27, s27, s15
 *   @0x1b21e8 ldr r3, [sp, #0x84]
 *   @0x1b21ec cmp r3, #0
 *   @0x1b21f0 beq 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34>
 *   @0x1b21f4 ldr r3, [pc, #0x3d4]
 *   @0x1b21f8 ldrb r2, [sp, #0x63]
 *   @0x1b21fc ldr r3, [pc, r3]
 *   @0x1b2200 ldr r1, [r7, #0x38]
 *   @0x1b2204 cmp r2, #0
 *   @0x1b2208 ldr r3, [r3]
 *   @0x1b220c and r10, r3, r1
 *   @0x1b2210 bne 0x1b247c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x358>
 *   @0x1b2214 vmov.f32 s16, #1.000000e+00
 *   @0x1b2218 vldr s9, [r11, #28]
 *   @0x1b221c vldr s10, [r11, #32]
 *   @0x1b2220 vldr s13, [r11, #36]
 *   @0x1b2224 vldr s14, [r11, #40]
 *   @0x1b2228 ldr r1, [r7, #0x2c]
 *   @0x1b222c vldr s29, [sp, #124]
 *   @0x1b2230 vldr s30, [sp, #128]
 *   @0x1b2234 cmp r1, #0
 *   @0x1b2238 vcvt.f32.s32 s21, s9
 *   @0x1b223c vcvt.f32.s32 s22, s10
 *   @0x1b2240 vcvt.f32.s32 s17, s13
 *   @0x1b2244 vcvt.f32.s32 s18, s14
 *   @0x1b2248 vmul.f32 s21, s21, s29
 *   @0x1b224c vmul.f32 s22, s22, s30
 *   @0x1b2250 vmul.f32 s17, s29, s17
 *   @0x1b2254 vmul.f32 s18, s30, s18
 *   @0x1b2258 vdiv.f32 s29, s16, s29
 *   @0x1b225c vdiv.f32 s30, s16, s30
 *   @0x1b2260 ble 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34>
 *   @0x1b2264 str r2, [sp, #0x44]
 *   @0x1b2268 mov r3, r2
 *   @0x1b226c ldr r2, [r7, #0x28]
 *   @0x1b2270 mvn r9, #0
 *   @0x1b2274 vldr s28, [pc, #844]
 *   @0x1b2278 vmov.f32 s20, #-2.000000e+00
 *   @0x1b227c vmov.f32 s19, #5.000000e-01
 *   @0x1b2280 cmp r2, #0
 *   @0x1b2284 ble 0x1b245c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x338>
 *   @0x1b2288 lsl r5, r3, #2
 *   @0x1b228c mov r8, r3
 *   @0x1b2290 mov r4, #0
 *   @0x1b2294 ldr r3, [r7, #0x34]
 *   @0x1b2298 ldr r6, [r3, r5]
 *   @0x1b229c and r6, r6, r10
 *   @0x1b22a0 ubfx r3, r6, #0x0, #0x13
 *   @0x1b22a4 cmp r3, #0
 *   @0x1b22a8 beq 0x1b2444 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x320>
 *   @0x1b22ac vldr s15, [r7, #48]
 *   @0x1b22b0 vcvt.s32.f32 s15, s15
 *   @0x1b22b4 ldr r0, [r11, #0x30]
 *   @0x1b22b8 ldr r1, [r11, #0x40]
 *   @0x1b22bc vmov r12, s15
 *   @0x1b22c0 mla r3, r0, r3, r12
 *   @0x1b22c4 ldr r3, [r1, r3, lsl #2]
 *   @0x1b22c8 cmp r3, #0
 *   @0x1b22cc mov r0, r3
 *   @0x1b22d0 beq 0x1b2444 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x320>
 *   @0x1b22d4 vldr s31, [r11, #28]
 *   @0x1b22d8 vmov r12, s31
 *   @0x1b22dc ldr r2, [r11, #0x20]
 *   @0x1b22e0 vmov.f32 s23, s17
 *   @0x1b22e4 ldr r1, [sp, #0x44]
 *   @0x1b22e8 str r2, [sp, #0x3c]
 *   @0x1b22ec ldr r2, [r11, #0x2c]
 *   @0x1b22f0 vcvt.f32.s32 s31, s31
 *   @0x1b22f4 str r3, [sp, #0x30]
 *   @0x1b22f8 str r2, [sp, #0x38]
 *   @0x1b22fc vmul.f32 s31, s31, s19
 *   @0x1b2300 mul r12, r12, r4
 *   @0x1b2304 vmov s25, r12
 *   @0x1b2308 ldr r12, [sp, #0x3c]
 *   @0x1b230c vcvt.f32.s32 s25, s25
 *   @0x1b2310 mul r12, r12, r1
 *   @0x1b2314 mov r1, r2
 *   @0x1b2318 vmov s24, r12
 *   @0x1b231c bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x1b2320 vadd.f32 s15, s17, s17
 *   @0x1b2324 ldr r3, [sp, #0x30]
 *   @0x1b2328 ldr r2, [sp, #0x38]
 *   @0x1b232c mov r0, r3
 *   @0x1b2330 vadd.f32 s15, s15, s21
 *   @0x1b2334 vcvt.f32.s32 s24, s24
 *   @0x1b2338 vadd.f32 s25, s25, s26
 *   @0x1b233c vmov s9, r1
 *   @0x1b2340 mov r1, r2
 *   @0x1b2344 vcvt.f32.u32 s14, s9
 *   @0x1b2348 vmla.f32 s23, s14, s15
 *   @0x1b234c bl 0x318c48 <__udivsi3>
 *   @0x1b2350 ubfx r1, r6, #0x1c, #0x1
 *   @0x1b2354 ubfx r2, r6, #0x1d, #0x1
 *   @0x1b2358 vldr s10, [sp, #60]
 *   @0x1b235c tst r6, #1073741824
 *   @0x1b2360 vmov s13, r1
 *   @0x1b2364 ubfx r3, r6, #0x1e, #0x1
 *   @0x1b2368 vmov s14, r2
 *   @0x1b236c ldr r12, [sp, #0x40]
 *   @0x1b2370 vmov s8, r3
 *   @0x1b2374 vmov r3, s21
 *   @0x1b2378 vcvt.f32.s32 s13, s13
 *   @0x1b237c vmov r1, s23
 *   @0x1b2380 vcvt.f32.s32 s14, s14
 *   @0x1b2384 vmov s9, r0
 *   @0x1b2388 mov r0, r11
 *   @0x1b238c vcvt.f32.u32 s11, s9
 *   @0x1b2390 vcvt.f32.s32 s15, s10
 *   @0x1b2394 vmov.f32 s9, s16
 *   @0x1b2398 vmov.f32 s10, s16
 *   @0x1b239c vadd.f32 s12, s18, s18
 *   @0x1b23a0 vmla.f32 s9, s13, s20
 *   @0x1b23a4 vmla.f32 s10, s14, s20
 *   @0x1b23a8 vmul.f32 s15, s15, s19
 *   @0x1b23ac vadd.f32 s12, s12, s22
 *   @0x1b23b0 vmov.f32 s7, s18
 *   @0x1b23b4 vmla.f32 s7, s11, s12
 *   @0x1b23b8 vmov.f32 s11, s31
 *   @0x1b23bc vmov r2, s7
 *   @0x1b23c0 vmov.f32 s12, s15
 *   @0x1b23c4 vmlsne.f32 s31, s31, s9
 *   @0x1b23c8 vmlane.f32 s15, s15, s10
 *   @0x1b23cc vmlseq.f32 s11, s11, s9
 *   @0x1b23d0 vmlseq.f32 s12, s12, s10
 *   @0x1b23d4 vadd.f32 s24, s24, s27
 *   @0x1b23d8 vaddne.f32 s15, s15, s25
 *   @0x1b23dc vaddne.f32 s31, s31, s24
 *   @0x1b23e0 vaddeq.f32 s15, s11, s25
 *   @0x1b23e4 vaddeq.f32 s31, s12, s24
 *   @0x1b23e8 vcvt.f32.s32 s8, s8
 *   @0x1b23ec vmov.f32 s13, s9
 *   @0x1b23f0 vldr s9, [r12, #8]
 *   @0x1b23f4 vmov.f32 s14, s10
 *   @0x1b23f8 vldr s10, [r12, #12]
 *   @0x1b23fc vstr s22, [sp]
 *   @0x1b2400 str r9, [sp, #0x18]
 *   @0x1b2404 str r9, [sp, #0x1c]
 *   @0x1b2408 vstr s16, [sp, #40]
 *   @0x1b240c str r9, [sp, #0x20]
 *   @0x1b2410 vmul.f32 s8, s8, s28
 *   @0x1b2414 str r9, [sp, #0x24]
 *   @0x1b2418 vmul.f32 s13, s13, s29
 *   @0x1b241c vstr s8, [sp, #20]
 *   @0x1b2420 vmul.f32 s14, s14, s30
 *   @0x1b2424 vstr s13, [sp, #12]
 *   @0x1b2428 vadd.f32 s15, s15, s9
 *   @0x1b242c vstr s14, [sp, #16]
 *   @0x1b2430 vadd.f32 s31, s31, s10
 *   @0x1b2434 vstr s15, [sp, #4]
 *   @0x1b2438 vstr s31, [sp, #8]
 *   @0x1b243c bl 0xc2238 <_ZN11CBackground11DrawGeneralEfffffffffjjjjf>
 *   @0x1b2440 ldr r2, [r7, #0x28]
 *   @0x1b2444 add r4, r4, #1
 *   @0x1b2448 add r5, r5, #4
 *   @0x1b244c cmp r2, r4
 *   @0x1b2450 add r3, r4, r8
 *   @0x1b2454 bgt 0x1b2294 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x170>
 *   @0x1b2458 ldr r1, [r7, #0x2c]
 *   @0x1b245c ldr r12, [sp, #0x44]
 *   @0x1b2460 add r12, r12, #1
 *   @0x1b2464 str r12, [sp, #0x44]
 *   @0x1b2468 cmp r1, r12
 *   @0x1b246c bgt 0x1b2280 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x15c>
 *   @0x1b2470 add sp, sp, #140
 *   @0x1b2474 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1b2478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1b247c bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv>
 *   @0x1b2480 vcvt.s32.f32 s9, s26
 *   @0x1b2484 movw r2, #0xaaab
 *   @0x1b2488 movt r2, #0x2aaa
 *   @0x1b248c ldr r5, [r11, #0x1c]
 *   @0x1b2490 mov r1, r5
 *   @0x1b2494 mov r3, r0
 *   @0x1b2498 ldr r0, [r4, #0x8]
 *   @0x1b249c smull r12, r2, r2, r3
 *   @0x1b24a0 vmov r12, s9
 *   @0x1b24a4 vstr s9, [sp, #52]
 *   @0x1b24a8 sub r2, r2, r3, asr #31
 *   @0x1b24ac str r2, [sp, #0x54]
 *   @0x1b24b0 rsb r0, r12, r0
 *   @0x1b24b4 add r0, r5, r0
 *   @0x1b24b8 bl 0x318d10 <__divsi3>
 *   @0x1b24bc vcvt.s32.f32 s10, s27
 *   @0x1b24c0 ldr r9, [r11, #0x20]
 *   @0x1b24c4 vmov s13, r5
 *   @0x1b24c8 mov r1, r9
 *   @0x1b24cc vmov r8, s10
 *   @0x1b24d0 vcvt.f32.s32 s21, s13
 *   @0x1b24d4 mov r2, r0
 *   @0x1b24d8 ldr r0, [r4, #0xc]
 *   @0x1b24dc str r2, [sp, #0x38]
 *   @0x1b24e0 rsb r0, r8, r0
 *   @0x1b24e4 add r0, r9, r0
 *   @0x1b24e8 bl 0x318d10 <__divsi3>
 *   @0x1b24ec ldr r12, [sp, #0x34]
 *   @0x1b24f0 mov r1, r5
 *   @0x1b24f4 mov r6, r0
 *   @0x1b24f8 ldr r0, [r4]
 *   @0x1b24fc rsb r0, r12, r0
 *   @0x1b2500 bl 0x318d10 <__divsi3>
 *   @0x1b2504 ldr r3, [r4, #0x4]
 *   @0x1b2508 vmov s14, r9
 *   @0x1b250c ldr r4, [r7, #0x28]
 *   @0x1b2510 ldr r2, [sp, #0x38]
 *   @0x1b2514 mov r1, r9
 *   @0x1b2518 vcvt.f32.s32 s22, s14
 *   @0x1b251c cmp r2, r4
 *   @0x1b2520 movge r2, r4
 *   @0x1b2524 str r2, [sp, #0x3c]
 *   @0x1b2528 bic r0, r0, r0, asr #31
 *   @0x1b252c str r0, [sp, #0x4c]
 *   @0x1b2530 rsb r0, r8, r3
 *   @0x1b2534 bl 0x318d10 <__divsi3>
 *   @0x1b2538 ldr r2, [r7, #0x2c]
 *   @0x1b253c ldr r12, [sp, #0x3c]
 *   @0x1b2540 ldr r1, [sp, #0x4c]
 *   @0x1b2544 cmp r6, r2
 *   @0x1b2548 movge r6, r2
 *   @0x1b254c str r6, [sp, #0x58]
 *   @0x1b2550 rsb r3, r1, r12
 *   @0x1b2554 ldr r12, [r11, #0x2c]
 *   @0x1b2558 str r12, [sp, #0x44]
 *   @0x1b255c bic r0, r0, r0, asr #31
 *   @0x1b2560 rsb r2, r0, r6
 *   @0x1b2564 cmp r0, r6
 *   @0x1b2568 vmov s20, r0
 *   @0x1b256c mul r2, r2, r3
 *   @0x1b2570 str r2, [sp, #0x50]
 *   @0x1b2574 bge 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34>
 *   @0x1b2578 ldr r12, [sp, #0x3c]
 *   @0x1b257c mov r3, #0
 *   @0x1b2580 mvn r9, #0
 *   @0x1b2584 str r10, [sp, #0x40]
 *   @0x1b2588 rsb r12, r12, r1
 *   @0x1b258c str r12, [sp, #0x5c]
 *   @0x1b2590 mov r12, r11
 *   @0x1b2594 mov r11, r3
 *   @0x1b2598 vstr s20, [sp, #72]
 *   @0x1b259c ldr r10, [sp, #0x4c]
 *   @0x1b25a0 ldr r0, [sp, #0x3c]
 *   @0x1b25a4 ldr r1, [sp, #0x48]
 *   @0x1b25a8 cmp r10, r0
 *   @0x1b25ac mla r4, r4, r1, r10
 *   @0x1b25b0 bge 0x1b27e8 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x6c4>
 *   @0x1b25b4 lsl r5, r4, #2
 *   @0x1b25b8 ldr r8, [sp, #0x50]
 *   @0x1b25bc mov r4, r10
 *   @0x1b25c0 vmov s20, r1
 *   @0x1b25c4 b 0x1b26bc <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x598>
 *   @0x1b25c8 adcsgt r0, r4, #0
 *   @0x1b25cc eoreq r11, r3, r4, asr #14
 *   @0x1b25d0 eoreq lr, r3, r12, lsl r6
 *   @0x1b25d4 tst r6, #268435456
 *   @0x1b25d8 vmovne.f32 s8, s17
 *   @0x1b25dc vmoveq.f32 s8, s14
 *   @0x1b25e0 vmovne.f32 s17, s14
 *   @0x1b25e4 tst r6, #536870912
 *   @0x1b25e8 vmovne.f32 s10, s13
 *   @0x1b25ec vmoveq.f32 s10, s15
 *   @0x1b25f0 vmovne.f32 s13, s15
 *   @0x1b25f4 tst r6, #1073741824
 *   @0x1b25f8 bne 0x1b2808 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x6e4>
 *   @0x1b25fc vmov.f32 s7, s13
 *   @0x1b2600 vmov.f32 s9, s17
 *   @0x1b2604 vmov.f32 s14, s8
 *   @0x1b2608 vmov.f32 s15, s10
 *   @0x1b260c vstr s19, [r3]
 *   @0x1b2610 vstr s18, [r3, #4]
 *   @0x1b2614 vstr s16, [r3, #8]
 *   @0x1b2618 vstr s17, [r3, #16]
 *   @0x1b261c vstr s15, [r3, #20]
 *   @0x1b2620 str r9, [r3, #0xc]
 *   @0x1b2624 vstr s11, [r3, #24]
 *   @0x1b2628 vstr s18, [r3, #28]
 *   @0x1b262c vstr s16, [r3, #32]
 *   @0x1b2630 vstr s14, [r3, #40]
 *   @0x1b2634 vstr s10, [r3, #44]
 *   @0x1b2638 str r9, [r3, #0x24]
 *   @0x1b263c vstr s19, [r3, #48]
 *   @0x1b2640 vstr s12, [r3, #52]
 *   @0x1b2644 vstr s16, [r3, #56]
 *   @0x1b2648 vstr s9, [r3, #64]
 *   @0x1b264c vstr s13, [r3, #68]
 *   @0x1b2650 str r9, [r3, #0x3c]
 *   @0x1b2654 vstr s19, [r3, #72]
 *   @0x1b2658 vstr s12, [r3, #76]
 *   @0x1b265c vstr s16, [r3, #80]
 *   @0x1b2660 vstr s9, [r3, #88]
 *   @0x1b2664 vstr s13, [r3, #92]
 *   @0x1b2668 str r9, [r3, #0x54]
 *   @0x1b266c vstr s11, [r3, #96]
 *   @0x1b2670 vstr s18, [r3, #100]
 *   @0x1b2674 vstr s16, [r3, #104]
 *   @0x1b2678 vstr s14, [r3, #112]
 *   @0x1b267c vstr s10, [r3, #116]
 *   @0x1b2680 str r9, [r3, #0x6c]
 *   @0x1b2684 vstr s11, [r3, #120]
 *   @0x1b2688 vstr s12, [r3, #124]
 *   @0x1b268c vstr s16, [r3, #128]
 *   @0x1b2690 sub r11, r11, #1
 *   @0x1b2694 vstr s8, [r3, #136]
 *   @0x1b2698 vstr s7, [r3, #140]
 *   @0x1b269c str r9, [r3, #0x84]
 *   @0x1b26a0 add r3, r3, #144
 *   @0x1b26a4 ldr r10, [sp, #0x3c]
 *   @0x1b26a8 add r4, r4, #1
 *   @0x1b26ac sub r8, r8, #1
 *   @0x1b26b0 add r5, r5, #4
 *   @0x1b26b4 cmp r4, r10
 *   @0x1b26b8 beq 0x1b27d8 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x6b4>
 *   @0x1b26bc ldr r2, [r7, #0x34]
 *   @0x1b26c0 ldr r10, [sp, #0x40]
 *   @0x1b26c4 ldr r6, [r2, r5]
 *   @0x1b26c8 and r6, r6, r10
 *   @0x1b26cc ubfx r2, r6, #0x0, #0x13
 *   @0x1b26d0 cmp r2, #0
 *   @0x1b26d4 beq 0x1b26a4 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x580>
 *   @0x1b26d8 vldr s15, [r7, #48]
 *   @0x1b26dc vcvt.s32.f32 s15, s15
 *   @0x1b26e0 ldr r0, [r12, #0x30]
 *   @0x1b26e4 ldr r1, [r12, #0x40]
 *   @0x1b26e8 vmov r10, s15
 *   @0x1b26ec mla r2, r0, r2, r10
 *   @0x1b26f0 ldr r10, [r1, r2, lsl #2]
 *   @0x1b26f4 cmp r10, #0
 *   @0x1b26f8 beq 0x1b26a4 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x580>
 *   @0x1b26fc cmp r11, #0
 *   @0x1b2700 bne 0x1b2738 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x614>
 *   @0x1b2704 ldr r11, [sp, #0x54]
 *   @0x1b2708 mov r0, #4
 *   @0x1b270c ldr r1, [sp, #0x84]
 *   @0x1b2710 mov r2, #24
 *   @0x1b2714 cmp r11, r8
 *   @0x1b2718 movge r11, r8
 *   @0x1b271c add r3, r11, r11, lsl #1
 *   @0x1b2720 ldr r1, [r1]
 *   @0x1b2724 str r12, [sp, #0x34]
 *   @0x1b2728 lsl r3, r3, #1
 *   @0x1b272c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1b2730 ldr r12, [sp, #0x34]
 *   @0x1b2734 mov r3, r0
 *   @0x1b2738 vmov s9, r4
 *   @0x1b273c mov r0, r10
 *   @0x1b2740 vmov.f32 s19, s26
 *   @0x1b2744 ldr r1, [sp, #0x44]
 *   @0x1b2748 str r3, [sp, #0x30]
 *   @0x1b274c str r12, [sp, #0x34]
 *   @0x1b2750 vcvt.f32.s32 s15, s9
 *   @0x1b2754 vmla.f32 s19, s15, s21
 *   @0x1b2758 vcvt.f32.s32 s15, s20
 *   @0x1b275c vmov.f32 s18, s27
 *   @0x1b2760 vmla.f32 s18, s15, s22
 *   @0x1b2764 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x1b2768 mov r0, r10
 *   @0x1b276c vldr s15, [sp, #116]
 *   @0x1b2770 vldr s17, [sp, #100]
 *   @0x1b2774 vmov s10, r1
 *   @0x1b2778 ldr r1, [sp, #0x44]
 *   @0x1b277c vcvt.f32.u32 s14, s10
 *   @0x1b2780 vmla.f32 s17, s14, s15
 *   @0x1b2784 bl 0x318c48 <__udivsi3>
 *   @0x1b2788 vldr s12, [sp, #120]
 *   @0x1b278c vldr s15, [sp, #104]
 *   @0x1b2790 tst r6, #1879048192
 *   @0x1b2794 vldr s14, [sp, #108]
 *   @0x1b2798 vldr s13, [sp, #112]
 *   @0x1b279c ldr r3, [sp, #0x30]
 *   @0x1b27a0 ldr r12, [sp, #0x34]
 *   @0x1b27a4 vadd.f32 s14, s17, s14
 *   @0x1b27a8 vadd.f32 s11, s19, s21
 *   @0x1b27ac vmov s9, r0
 *   @0x1b27b0 vcvt.f32.u32 s10, s9
 *   @0x1b27b4 vmla.f32 s15, s10, s12
 *   @0x1b27b8 vadd.f32 s12, s18, s22
 *   @0x1b27bc vadd.f32 s13, s15, s13
 *   @0x1b27c0 bne 0x1b25d4 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x4b0>
 *   @0x1b27c4 vmov.f32 s7, s13
 *   @0x1b27c8 vmov.f32 s8, s14
 *   @0x1b27cc vmov.f32 s9, s17
 *   @0x1b27d0 vmov.f32 s10, s15
 *   @0x1b27d4 b 0x1b260c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x4e8>
 *   @0x1b27d8 ldr r0, [sp, #0x50]
 *   @0x1b27dc ldr r10, [sp, #0x5c]
 *   @0x1b27e0 add r0, r10, r0
 *   @0x1b27e4 str r0, [sp, #0x50]
 *   @0x1b27e8 ldr r10, [sp, #0x48]
 *   @0x1b27ec ldr r0, [sp, #0x58]
 *   @0x1b27f0 add r10, r10, #1
 *   @0x1b27f4 str r10, [sp, #0x48]
 *   @0x1b27f8 cmp r10, r0
 *   @0x1b27fc beq 0x1b281c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x6f8>
 *   @0x1b2800 ldr r4, [r7, #0x28]
 *   @0x1b2804 b 0x1b259c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x478>
 *   @0x1b2808 vmov.f32 s7, s10
 *   @0x1b280c vmov.f32 s9, s8
 *   @0x1b2810 vmov.f32 s14, s17
 *   @0x1b2814 vmov.f32 s15, s13
 *   @0x1b2818 b 0x1b260c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x4e8>
 *   @0x1b281c cmp r11, #0
 *   @0x1b2820 ble 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34>
 *   @0x1b2824 add r0, r11, r11, lsl #1
 *   @0x1b2828 lsl r0, r0, #1
 *   @0x1b282c bl 0x185600 <_ZN8Graphics9FreeVertsEi>
 *   @0x1b2830 b 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34>
 *
 * ══ §12/13 spIkConstraint_apply2  0x285f7c  size 1792  448 条（0x285f7c..0x28667c）
 * @func 0x285f7c 0x28667c  size 1792  448 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70×7 / 0xb66f4×3 / 0xb6c4c×2 / 0xb67d8×2 / spBone_updateWorldTransformWith×2 / spIkConstraint_apply2+0x618 / spIkConstraint_apply2+0x38c / spIkConstraint_apply2+0x374
 * 字段偏移 top8: 0x8×2 / 0x20×2 / 0x24×2 / 0x4×2 / 0xc×2 / 0x80×1 / 0x2c×1
 * VFP 指令 355 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285f7c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x285f80 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x285f84 sub sp, sp, #32
 *   @0x285f88 vldr s20, [sp, #132]
 *   @0x285f8c vcmp.f32 s20, #0
 *   @0x285f90 mov r5, r1
 *   @0x285f94 vldr s19, [r1, #20]
 *   @0x285f98 vldr s24, [r1, #32]
 *   @0x285f9c mov r4, r0
 *   @0x285fa0 vldr s22, [r0, #20]
 *   @0x285fa4 vldr s21, [r0, #24]
 *   @0x285fa8 vldr s16, [r0, #32]
 *   @0x285fac vldr s17, [r0, #36]
 *   @0x285fb0 ldr r1, [r0, #0x8]
 *   @0x285fb4 vmov s2, r2
 *   @0x285fb8 ldr r8, [sp, #0x80]
 *   @0x285fbc vmov s3, r3
 *   @0x285fc0 vmrs APSR_nzcv, fpscr
 *   @0x285fc4 beq 0x286574 <spIkConstraint_apply2+0x5f8>
 *   @0x285fc8 vcmpe.f32 s16, #0
 *   @0x285fcc vmrs APSR_nzcv, fpscr
 *   @0x285fd0 vcmpe.f32 s17, #0
 *   @0x285fd4 mvnmi r7, #0
 *   @0x285fd8 movmi r10, #180
 *   @0x285fdc movpl r7, #1
 *   @0x285fe0 movpl r10, #0
 *   @0x285fe4 vnegmi.f32 s16, s16
 *   @0x285fe8 vmrs APSR_nzcv, fpscr
 *   @0x285fec rsbmi r7, r7, #0
 *   @0x285ff0 vnegmi.f32 s17, s17
 *   @0x285ff4 vsub.f32 s13, s16, s17
 *   @0x285ff8 vcmpe.f32 s24, #0
 *   @0x285ffc vmrs APSR_nzcv, fpscr
 *   @0x286000 vcmpe.f32 s13, #0
 *   @0x286004 movmi r9, #180
 *   @0x286008 movpl r9, #0
 *   @0x28600c vnegmi.f32 s24, s24
 *   @0x286010 vmrs APSR_nzcv, fpscr
 *   @0x286014 bmi 0x28655c <spIkConstraint_apply2+0x5e0>
 *   @0x286018 vldr s15, [pc, #768]
 *   @0x28601c vcmpe.f32 s13, s15
 *   @0x286020 vmrs APSR_nzcv, fpscr
 *   @0x286024 movhi r6, #0
 *   @0x286028 movls r6, #1
 *   @0x28602c cmp r6, #0
 *   @0x286030 beq 0x2862d0 <spIkConstraint_apply2+0x354>
 *   @0x286034 vldr s23, [r5, #24]
 *   @0x286038 vldr s4, [r4, #56]
 *   @0x28603c vldr s13, [r4, #68]
 *   @0x286040 vmul.f32 s4, s23, s4
 *   @0x286044 vldr s11, [r4, #52]
 *   @0x286048 vldr s12, [r4, #64]
 *   @0x28604c vldr s14, [r4, #60]
 *   @0x286050 vldr s15, [r4, #72]
 *   @0x286054 vmul.f32 s13, s23, s13
 *   @0x286058 vmla.f32 s4, s19, s11
 *   @0x28605c vmla.f32 s13, s19, s12
 *   @0x286060 vadd.f32 s4, s4, s14
 *   @0x286064 vadd.f32 s13, s13, s15
 *   @0x286068 vldr s10, [r1, #56]
 *   @0x28606c vldr s9, [r1, #64]
 *   @0x286070 vldr s7, [r1, #52]
 *   @0x286074 vldr s8, [r1, #68]
 *   @0x286078 vldr s6, [r1, #60]
 *   @0x28607c vldr s5, [r1, #72]
 *   @0x286080 vmul.f32 s12, s10, s9
 *   @0x286084 vnmls.f32 s12, s7, s8
 *   @0x286088 vmov.f32 s11, #1.000000e+00
 *   @0x28608c vsub.f32 s4, s4, s6
 *   @0x286090 vdiv.f32 s11, s11, s12
 *   @0x286094 vmul.f32 s12, s9, s4
 *   @0x286098 vsub.f32 s13, s13, s5
 *   @0x28609c vnmls.f32 s12, s7, s13
 *   @0x2860a0 vmul.f32 s13, s10, s13
 *   @0x2860a4 vnmls.f32 s13, s8, s4
 *   @0x2860a8 vmov.f32 s14, s21
 *   @0x2860ac vnmls.f32 s14, s12, s11
 *   @0x2860b0 vmov.f32 s15, s22
 *   @0x2860b4 vnmls.f32 s15, s13, s11
 *   @0x2860b8 vmul.f32 s12, s14, s14
 *   @0x2860bc vmla.f32 s12, s15, s15
 *   @0x2860c0 vcvt.f64.f32 d6, s12
 *   @0x2860c4 vsqrt.f64 d7, d6
 *   @0x2860c8 vsub.f32 s6, s2, s6
 *   @0x2860cc vsub.f32 s5, s3, s5
 *   @0x2860d0 vmul.f32 s9, s9, s6
 *   @0x2860d4 vmul.f32 s10, s10, s5
 *   @0x2860d8 vnmls.f32 s9, s7, s5
 *   @0x2860dc vnmls.f32 s10, s8, s6
 *   @0x2860e0 vcmp.f64 d7, d7
 *   @0x2860e4 vmov.f32 s28, s21
 *   @0x2860e8 vmrs APSR_nzcv, fpscr
 *   @0x2860ec vmov.f32 s25, s22
 *   @0x2860f0 vnmls.f32 s28, s9, s11
 *   @0x2860f4 vnmls.f32 s25, s10, s11
 *   @0x2860f8 bne 0x28664c <spIkConstraint_apply2+0x6d0>
 *   @0x2860fc cmp r6, #0
 *   @0x286100 ldr r3, [r5]
 *   @0x286104 vldr s29, [r3, #12]
 *   @0x286108 vcvt.f32.f64 s18, d7
 *   @0x28610c vmul.f32 s29, s24, s29
 *   @0x286110 beq 0x286344 <spIkConstraint_apply2+0x3c8>
 *   @0x286114 vmul.f32 s15, s28, s28
 *   @0x286118 vmla.f32 s15, s25, s25
 *   @0x28611c vmls.f32 s15, s18, s18
 *   @0x286120 vmul.f32 s16, s29, s16
 *   @0x286124 vadd.f32 s17, s18, s18
 *   @0x286128 vmls.f32 s15, s16, s16
 *   @0x28612c vmul.f32 s17, s17, s16
 *   @0x286130 vdiv.f32 s17, s15, s17
 *   @0x286134 vmov.f32 s15, #-1.000000e+00
 *   @0x286138 vcmpe.f32 s17, s15
 *   @0x28613c vmrs APSR_nzcv, fpscr
 *   @0x286140 bmi 0x286588 <spIkConstraint_apply2+0x60c>
 *   @0x286144 vmov.f32 s13, #1.000000e+00
 *   @0x286148 vcmpe.f32 s17, s13
 *   @0x28614c vmrs APSR_nzcv, fpscr
 *   @0x286150 vmovgt.f64 d7, #1.000000e+00
 *   @0x286154 vmovgt.f32 s17, s13
 *   @0x286158 ble 0x286594 <spIkConstraint_apply2+0x618>
 *   @0x28615c vmov r0, r1, d7
 *   @0x286160 bl 0xb6c4c <acos@plt>
 *   @0x286164 vmov s10, r8
 *   @0x286168 vmla.f32 s18, s16, s17
 *   @0x28616c vcvt.f32.s32 s26, s10
 *   @0x286170 vmov d6, r0, r1
 *   @0x286174 vcvt.f32.f64 s17, d6
 *   @0x286178 vmul.f32 s26, s17, s26
 *   @0x28617c vcvt.f64.f32 d7, s26
 *   @0x286180 vmov r0, r1, d7
 *   @0x286184 bl 0xb67d8 <sin@plt>
 *   @0x286188 vmov d5, r0, r1
 *   @0x28618c vcvt.f32.f64 s29, d5
 *   @0x286190 vmul.f32 s16, s29, s16
 *   @0x286194 vmul.f32 s13, s25, s16
 *   @0x286198 vmul.f32 s29, s28, s16
 *   @0x28619c vnmls.f32 s13, s28, s18
 *   @0x2861a0 vmla.f32 s29, s25, s18
 *   @0x2861a4 vcvt.f64.f32 d7, s13
 *   @0x2861a8 vcvt.f64.f32 d5, s29
 *   @0x2861ac vmov r0, r1, d7
 *   @0x2861b0 vmov r2, r3, d5
 *   @0x2861b4 bl 0xb6c70 <atan2@plt>
 *   @0x2861b8 vmov d6, r0, r1
 *   @0x2861bc vcvt.f32.f64 s18, d6
 *   @0x2861c0 vcvt.f64.f32 d7, s23
 *   @0x2861c4 vcvt.f64.f32 d5, s19
 *   @0x2861c8 vmov r0, r1, d7
 *   @0x2861cc vmov r2, r3, d5
 *   @0x2861d0 bl 0xb6c70 <atan2@plt>
 *   @0x2861d4 vldr s12, [pc, #328]
 *   @0x2861d8 vmov s11, r7
 *   @0x2861dc vldr s13, [r4, #28]
 *   @0x2861e0 vmov s10, r10
 *   @0x2861e4 vldr s15, [pc, #316]
 *   @0x2861e8 vcvt.f32.s32 s16, s11
 *   @0x2861ec vcvt.f32.s32 s14, s10
 *   @0x2861f0 vmov d5, r0, r1
 *   @0x2861f4 vcvt.f32.f64 s17, d5
 *   @0x2861f8 vmul.f32 s17, s17, s16
 *   @0x2861fc vsub.f32 s18, s18, s17
 *   @0x286200 vmla.f32 s14, s18, s12
 *   @0x286204 vsub.f32 s14, s14, s13
 *   @0x286208 vcmpe.f32 s14, s15
 *   @0x28620c vmrs APSR_nzcv, fpscr
 *   @0x286210 ble 0x286308 <spIkConstraint_apply2+0x38c>
 *   @0x286214 vldr s15, [pc, #272]
 *   @0x286218 vsub.f32 s14, s14, s15
 *   @0x28621c ldr r2, [r4, #0x20]
 *   @0x286220 mov r0, r4
 *   @0x286224 ldr r3, [r4, #0x24]
 *   @0x286228 vmov r1, s22
 *   @0x28622c str r2, [sp]
 *   @0x286230 str r3, [sp, #0x4]
 *   @0x286234 mov r3, #0
 *   @0x286238 vmov r2, s21
 *   @0x28623c str r3, [sp, #0x8]
 *   @0x286240 str r3, [sp, #0xc]
 *   @0x286244 vmla.f32 s13, s14, s20
 *   @0x286248 vmov r3, s13
 *   @0x28624c bl 0x284f18 <spBone_updateWorldTransformWith>
 *   @0x286250 vadd.f32 s26, s26, s17
 *   @0x286254 vldr s13, [r5, #40]
 *   @0x286258 vldr s15, [pc, #196]
 *   @0x28625c vmov s10, r9
 *   @0x286260 vldr s14, [r5, #28]
 *   @0x286264 vldr s12, [pc, #188]
 *   @0x286268 vmov.f32 s11, s13
 *   @0x28626c vnmls.f32 s11, s26, s15
 *   @0x286270 vcvt.f32.s32 s15, s10
 *   @0x286274 vmla.f32 s15, s16, s11
 *   @0x286278 vsub.f32 s15, s15, s14
 *   @0x28627c vcmpe.f32 s15, s12
 *   @0x286280 vmrs APSR_nzcv, fpscr
 *   @0x286284 ble 0x2862f0 <spIkConstraint_apply2+0x374>
 *   @0x286288 vldr s12, [pc, #156]
 *   @0x28628c vsub.f32 s15, s15, s12
 *   @0x286290 vstr s13, [sp, #8]
 *   @0x286294 ldr r2, [r5, #0x20]
 *   @0x286298 ldr r3, [r5, #0x24]
 *   @0x28629c mov r0, r5
 *   @0x2862a0 vmov r1, s19
 *   @0x2862a4 str r2, [sp]
 *   @0x2862a8 str r3, [sp, #0x4]
 *   @0x2862ac ldr r3, [r5, #0x2c]
 *   @0x2862b0 vmov r2, s23
 *   @0x2862b4 vmla.f32 s14, s15, s20
 *   @0x2862b8 str r3, [sp, #0xc]
 *   @0x2862bc vmov r3, s14
 *   @0x2862c0 bl 0x284f18 <spBone_updateWorldTransformWith>
 *   @0x2862c4 add sp, sp, #32
 *   @0x2862c8 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2862cc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2862d0 vldr s14, [r4, #52]
 *   @0x2862d4 vldr s4, [r4, #60]
 *   @0x2862d8 vldr s15, [r4, #64]
 *   @0x2862dc vldr s13, [r4, #72]
 *   @0x2862e0 vmla.f32 s4, s19, s14
 *   @0x2862e4 vldr s23, [pc, #80]
 *   @0x2862e8 vmla.f32 s13, s19, s15
 *   @0x2862ec b 0x286068 <spIkConstraint_apply2+0xec>
 *   @0x2862f0 vldr s12, [pc, #56]
 *   @0x2862f4 vcmpe.f32 s15, s12
 *   @0x2862f8 vmrs APSR_nzcv, fpscr
 *   @0x2862fc vldrmi s12, [pc, #40]
 *   @0x286300 vaddmi.f32 s15, s15, s12
 *   @0x286304 b 0x286290 <spIkConstraint_apply2+0x314>
 *   @0x286308 vldr s15, [pc, #32]
 *   @0x28630c vcmpe.f32 s14, s15
 *   @0x286310 vmrs APSR_nzcv, fpscr
 *   @0x286314 vldrmi s15, [pc, #16]
 *   @0x286318 vaddmi.f32 s14, s14, s15
 *   @0x28631c b 0x28621c <spIkConstraint_apply2+0x2a0>
 *   @0x286320 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x286324 rsbmi r2, r5, #224, #28
 *   @0x286328 teqmi r4, #0
 *   @0x28632c .word 0x43b40000
 *   @0x286330 teqgt r4, #0
 *   @0x286334 svcvc #0x7fffff
 *   @0x286338 ldrdmi r0, r1, [r9], #-251
 *   @0x28633c andeq r0, r0, r0
 *   @0x286340 ldmlt r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x286344 vmul.f32 s27, s28, s28
 *   @0x286348 vmul.f32 s24, s16, s29
 *   @0x28634c vmla.f32 s27, s25, s25
 *   @0x286350 vmul.f32 s30, s24, s24
 *   @0x286354 vmul.f32 s29, s17, s29
 *   @0x286358 vcvt.f64.f32 d7, s28
 *   @0x28635c vcvt.f64.f32 d5, s25
 *   @0x286360 vmov r0, r1, d7
 *   @0x286364 vmov r2, r3, d5
 *   @0x286368 bl 0xb6c70 <atan2@plt>
 *   @0x28636c vmul.f32 s26, s29, s29
 *   @0x286370 vmul.f32 s15, s18, s18
 *   @0x286374 vmul.f32 s25, s30, s27
 *   @0x286378 vmla.f32 s25, s26, s15
 *   @0x28637c vmov d7, r0, r1
 *   @0x286380 vsub.f32 s11, s26, s30
 *   @0x286384 vmov.f32 s12, #4.000000e+00
 *   @0x286388 vstr s11, [sp, #20]
 *   @0x28638c vmov.f32 s31, #-2.000000e+00
 *   @0x286390 vmls.f32 s25, s30, s26
 *   @0x286394 vmul.f32 s12, s11, s12
 *   @0x286398 vmul.f32 s31, s26, s31
 *   @0x28639c vmul.f32 s12, s12, s25
 *   @0x2863a0 vmul.f32 s31, s31, s18
 *   @0x2863a4 vnmls.f32 s12, s31, s31
 *   @0x2863a8 vadd.f32 s28, s18, s24
 *   @0x2863ac vmul.f32 s10, s28, s28
 *   @0x2863b0 vcvt.f32.f64 s15, d7
 *   @0x2863b4 vstr s10, [sp, #24]
 *   @0x2863b8 vcmpe.f32 s12, #0
 *   @0x2863bc vstr s15, [sp, #28]
 *   @0x2863c0 vmrs APSR_nzcv, fpscr
 *   @0x2863c4 blt 0x286440 <spIkConstraint_apply2+0x4c4>
 *   @0x2863c8 vcvt.f64.f32 d6, s12
 *   @0x2863cc vsqrt.f64 d7, d6
 *   @0x2863d0 vcmp.f64 d7, d7
 *   @0x2863d4 vmrs APSR_nzcv, fpscr
 *   @0x2863d8 bne 0x28665c <spIkConstraint_apply2+0x6e0>
 *   @0x2863dc vcvt.f32.f64 s14, d7
 *   @0x2863e0 vldr s11, [sp, #20]
 *   @0x2863e4 vcmpe.f32 s31, #0
 *   @0x2863e8 vmrs APSR_nzcv, fpscr
 *   @0x2863ec vnegmi.f32 s14, s14
 *   @0x2863f0 vmov.f32 s15, #5.000000e-01
 *   @0x2863f4 vadd.f32 s31, s31, s14
 *   @0x2863f8 vnmul.f32 s31, s31, s15
 *   @0x2863fc vdiv.f32 s15, s31, s11
 *   @0x286400 vdiv.f32 s25, s25, s31
 *   @0x286404 vcmpe.f32 s15, #0
 *   @0x286408 vmrs APSR_nzcv, fpscr
 *   @0x28640c vcmpe.f32 s25, #0
 *   @0x286410 vnegmi.f32 s13, s15
 *   @0x286414 vmovpl.f32 s13, s15
 *   @0x286418 vmrs APSR_nzcv, fpscr
 *   @0x28641c vnegmi.f32 s14, s25
 *   @0x286420 vmovpl.f32 s14, s25
 *   @0x286424 vcmp.f32 s13, s14
 *   @0x286428 vmrs APSR_nzcv, fpscr
 *   @0x28642c vmovmi.f32 s25, s15
 *   @0x286430 vmul.f32 s12, s25, s25
 *   @0x286434 vcmpe.f32 s27, s12
 *   @0x286438 vmrs APSR_nzcv, fpscr
 *   @0x28643c bge 0x2865d4 <spIkConstraint_apply2+0x658>
 *   @0x286440 vsub.f32 s25, s18, s24
 *   @0x286444 vldr s13, [sp, #24]
 *   @0x286448 vldr s15, [pc, #-284]
 *   @0x28644c vmul.f32 s31, s25, s25
 *   @0x286450 vcmpe.f32 s13, #0
 *   @0x286454 vmrs APSR_nzcv, fpscr
 *   @0x286458 vcmpe.f32 s31, s15
 *   @0x28645c vldrle s28, [pc, #-296]
 *   @0x286460 vstrle s28, [sp, #24]
 *   @0x286464 vmrs APSR_nzcv, fpscr
 *   @0x286468 vmovpl.f32 s31, s15
 *   @0x28646c vldrpl s25, [pc, #-312]
 *   @0x286470 vldrmi s14, [pc, #-320]
 *   @0x286474 vstrpl s25, [sp, #20]
 *   @0x286478 vstrmi s14, [sp, #20]
 *   @0x28647c vnmul.f32 s15, s24, s18
 *   @0x286480 vsub.f32 s26, s30, s26
 *   @0x286484 vdiv.f32 s26, s15, s26
 *   @0x286488 vcvt.f64.f32 d5, s26
 *   @0x28648c vmov r0, r1, d5
 *   @0x286490 bl 0xb6c4c <acos@plt>
 *   @0x286494 vmov d6, r0, r1
 *   @0x286498 vcvt.f32.f64 s26, d6
 *   @0x28649c vcvt.f64.f32 d8, s26
 *   @0x2864a0 vmov r0, r1, d8
 *   @0x2864a4 bl 0xb67e4 <cos@plt>
 *   @0x2864a8 vmov d5, r0, r1
 *   @0x2864ac vcvt.f32.f64 s15, d5
 *   @0x2864b0 vmov r0, r1, d8
 *   @0x2864b4 vmla.f32 s18, s15, s24
 *   @0x2864b8 bl 0xb67d8 <sin@plt>
 *   @0x2864bc vldr s14, [sp, #24]
 *   @0x2864c0 vmov d6, r0, r1
 *   @0x2864c4 vcvt.f32.f64 s15, d6
 *   @0x2864c8 vmul.f32 s29, s15, s29
 *   @0x2864cc vmul.f32 s15, s29, s29
 *   @0x2864d0 vmla.f32 s15, s18, s18
 *   @0x2864d4 vcmpe.f32 s31, s15
 *   @0x2864d8 vmrs APSR_nzcv, fpscr
 *   @0x2864dc vcmpe.f32 s14, s15
 *   @0x2864e0 vstrgt s26, [sp, #20]
 *   @0x2864e4 vldrle s13, [pc, #-432]
 *   @0x2864e8 vmovgt.f32 s31, s15
 *   @0x2864ec vmovgt.f32 s13, s29
 *   @0x2864f0 vmovgt.f32 s25, s18
 *   @0x2864f4 vmrs APSR_nzcv, fpscr
 *   @0x2864f8 vldrpl s29, [pc, #-452]
 *   @0x2864fc vmovpl.f32 s15, s14
 *   @0x286500 vmov.f32 s14, #5.000000e-01
 *   @0x286504 vadd.f32 s15, s31, s15
 *   @0x286508 vmul.f32 s15, s15, s14
 *   @0x28650c vcmpe.f32 s27, s15
 *   @0x286510 vmovpl.f32 s18, s28
 *   @0x286514 vmovpl.f32 s26, s29
 *   @0x286518 vmrs APSR_nzcv, fpscr
 *   @0x28651c bhi 0x28659c <spIkConstraint_apply2+0x620>
 *   @0x286520 vmov s15, r8
 *   @0x286524 vcvt.f64.f32 d5, s25
 *   @0x286528 vcvt.f32.s32 s26, s15
 *   @0x28652c vmov r2, r3, d5
 *   @0x286530 vmul.f32 s13, s26, s13
 *   @0x286534 vcvt.f64.f32 d7, s13
 *   @0x286538 vmov r0, r1, d7
 *   @0x28653c bl 0xb6c70 <atan2@plt>
 *   @0x286540 vldr s15, [sp, #20]
 *   @0x286544 vmul.f32 s26, s15, s26
 *   @0x286548 vmov d5, r0, r1
 *   @0x28654c vcvt.f32.f64 s18, d5
 *   @0x286550 vldr s11, [sp, #28]
 *   @0x286554 vsub.f32 s18, s11, s18
 *   @0x286558 b 0x2861c0 <spIkConstraint_apply2+0x244>
 *   @0x28655c vldr s15, [pc, #-548]
 *   @0x286560 vcmpe.f32 s13, s15
 *   @0x286564 vmrs APSR_nzcv, fpscr
 *   @0x286568 movlt r6, #0
 *   @0x28656c movge r6, #1
 *   @0x286570 b 0x28602c <spIkConstraint_apply2+0xb0>
 *   @0x286574 mov r0, r5
 *   @0x286578 add sp, sp, #32
 *   @0x28657c vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x286580 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x286584 b 0x285348 <spBone_updateWorldTransform>
 *   @0x286588 vmov.f32 s17, s15
 *   @0x28658c vmov.f64 d7, #-1.000000e+00
 *   @0x286590 b 0x28615c <spIkConstraint_apply2+0x1e0>
 *   @0x286594 vcvt.f64.f32 d7, s17
 *   @0x286598 b 0x28615c <spIkConstraint_apply2+0x1e0>
 *   @0x28659c vmov s12, r8
 *   @0x2865a0 vcvt.f64.f32 d7, s18
 *   @0x2865a4 vcvt.f32.s32 s17, s12
 *   @0x2865a8 vmov r2, r3, d7
 *   @0x2865ac vmul.f32 s29, s17, s29
 *   @0x2865b0 vcvt.f64.f32 d5, s29
 *   @0x2865b4 vmov r0, r1, d5
 *   @0x2865b8 bl 0xb6c70 <atan2@plt>
 *   @0x2865bc vmul.f32 s26, s26, s17
 *   @0x2865c0 vmov d6, r0, r1
 *   @0x2865c4 vcvt.f32.f64 s18, d6
 *   @0x2865c8 vldr s13, [sp, #28]
 *   @0x2865cc vsub.f32 s18, s13, s18
 *   @0x2865d0 b 0x2861c0 <spIkConstraint_apply2+0x244>
 *   @0x2865d4 vsub.f32 s12, s27, s12
 *   @0x2865d8 vcvt.f64.f32 d6, s12
 *   @0x2865dc vsqrt.f64 d7, d6
 *   @0x2865e0 vcmp.f64 d7, d7
 *   @0x2865e4 vmrs APSR_nzcv, fpscr
 *   @0x2865e8 bne 0x28666c <spIkConstraint_apply2+0x6f0>
 *   @0x2865ec vmov s12, r8
 *   @0x2865f0 vcvt.f32.f64 s14, d7
 *   @0x2865f4 vcvt.f32.s32 s15, s12
 *   @0x2865f8 vmul.f32 s24, s14, s15
 *   @0x2865fc vcvt.f64.f32 d7, s25
 *   @0x286600 vcvt.f64.f32 d5, s24
 *   @0x286604 vmov r2, r3, d7
 *   @0x286608 vmov r0, r1, d5
 *   @0x28660c bl 0xb6c70 <atan2@plt>
 *   @0x286610 vsub.f32 s25, s25, s18
 *   @0x286614 vdiv.f32 s17, s24, s17
 *   @0x286618 vmov d6, r0, r1
 *   @0x28661c vdiv.f32 s16, s25, s16
 *   @0x286620 vcvt.f64.f32 d5, s17
 *   @0x286624 vcvt.f64.f32 d7, s16
 *   @0x286628 vmov r0, r1, d5
 *   @0x28662c vldr s11, [sp, #28]
 *   @0x286630 vcvt.f32.f64 s18, d6
 *   @0x286634 vmov r2, r3, d7
 *   @0x286638 vsub.f32 s18, s11, s18
 *   @0x28663c bl 0xb6c70 <atan2@plt>
 *   @0x286640 vmov d6, r0, r1
 *   @0x286644 vcvt.f32.f64 s26, d6
 *   @0x286648 b 0x2861c0 <spIkConstraint_apply2+0x244>
 *   @0x28664c vmov r0, r1, d6
 *   @0x286650 bl 0xb66f4 <sqrt@plt>
 *   @0x286654 vmov d7, r0, r1
 *   @0x286658 b 0x2860fc <spIkConstraint_apply2+0x180>
 *   @0x28665c vmov r0, r1, d6
 *   @0x286660 bl 0xb66f4 <sqrt@plt>
 *   @0x286664 vmov d7, r0, r1
 *   @0x286668 b 0x2863dc <spIkConstraint_apply2+0x460>
 *   @0x28666c vmov r0, r1, d6
 *   @0x286670 bl 0xb66f4 <sqrt@plt>
 *   @0x286674 vmov d7, r0, r1
 *   @0x286678 b 0x2865ec <spIkConstraint_apply2+0x670>
 *
 * ══ §13/13 KeyToStr  0xf348c  size 1124  281 条（0xf348c..0xf38f0）
 * @func 0xf348c 0xf38f0  size 1124  281 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65c8×4 / KeyToStr(int)+0x384 / KeyToStr(int)+0x3ac
 * 字段偏移 top8: 0x200×1 / 0x1d8×1 / 0x1d4×1 / 0x1b8×1 / 0x1b0×1 / 0x1a8×1 / 0x1a0×1 / 0x198×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf348c push {r3, r4, r5, lr}
 *   @0xf3490 mov r4, r0
 *   @0xf3494 cmp r0, #111
 *   @0xf3498 addls pc, pc, r0, lsl #2
 *   @0xf349c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34a0 b 0xf36c0 <_Z8KeyToStri+0x234>
 *   @0xf34a4 b 0xf36b4 <_Z8KeyToStri+0x228>
 *   @0xf34a8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34ac b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34b0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34b4 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34b8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34bc b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34c0 b 0xf3660 <_Z8KeyToStri+0x1d4>
 *   @0xf34c4 b 0xf37c8 <_Z8KeyToStri+0x33c>
 *   @0xf34c8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34cc b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34d0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34d4 b 0xf37bc <_Z8KeyToStri+0x330>
 *   @0xf34d8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34dc b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34e0 b 0xf37b0 <_Z8KeyToStri+0x324>
 *   @0xf34e4 b 0xf37a4 <_Z8KeyToStri+0x318>
 *   @0xf34e8 b 0xf3798 <_Z8KeyToStri+0x30c>
 *   @0xf34ec b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34f0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34f4 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34f8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf34fc b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3500 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3504 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3508 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf350c b 0xf378c <_Z8KeyToStri+0x300>
 *   @0xf3510 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3514 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3518 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf351c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3520 b 0xf3780 <_Z8KeyToStri+0x2f4>
 *   @0xf3524 b 0xf3774 <_Z8KeyToStri+0x2e8>
 *   @0xf3528 b 0xf3768 <_Z8KeyToStri+0x2dc>
 *   @0xf352c b 0xf375c <_Z8KeyToStri+0x2d0>
 *   @0xf3530 b 0xf3750 <_Z8KeyToStri+0x2c4>
 *   @0xf3534 b 0xf3744 <_Z8KeyToStri+0x2b8>
 *   @0xf3538 b 0xf3738 <_Z8KeyToStri+0x2ac>
 *   @0xf353c b 0xf372c <_Z8KeyToStri+0x2a0>
 *   @0xf3540 b 0xf3720 <_Z8KeyToStri+0x294>
 *   @0xf3544 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3548 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf354c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3550 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3554 b 0xf3714 <_Z8KeyToStri+0x288>
 *   @0xf3558 b 0xf36f0 <_Z8KeyToStri+0x264>
 *   @0xf355c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3560 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3564 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3568 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf356c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3570 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3574 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3578 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf357c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3580 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3584 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3588 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf358c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3590 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3594 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3598 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf359c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35a0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35a4 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35a8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35ac b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35b0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35b4 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35b8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35bc b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35c0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35c4 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35c8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35cc b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35d0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35d4 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35d8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35dc b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35e0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35e4 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35e8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35ec b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35f0 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35f4 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35f8 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf35fc b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3600 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3604 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3608 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf360c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3610 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3614 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3618 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf361c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3620 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3624 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3628 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf362c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3630 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3634 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3638 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf363c b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3640 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3644 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3648 b 0xf36e4 <_Z8KeyToStri+0x258>
 *   @0xf364c b 0xf36d8 <_Z8KeyToStri+0x24c>
 *   @0xf3650 b 0xf37d4 <_Z8KeyToStri+0x348>
 *   @0xf3654 b 0xf36cc <_Z8KeyToStri+0x240>
 *   @0xf3658 b 0xf3708 <_Z8KeyToStri+0x27c>
 *   @0xf365c b 0xf36fc <_Z8KeyToStri+0x270>
 *   @0xf3660 ldr r0, [pc, #0x200]
 *   @0xf3664 add r0, pc, r0
 *   @0xf3668 sub r3, r4, #65
 *   @0xf366c cmp r3, #25
 *   @0xf3670 bls 0xf3810 <_Z8KeyToStri+0x384>
 *   @0xf3674 sub r3, r4, #96
 *   @0xf3678 cmp r3, #9
 *   @0xf367c bls 0xf3838 <_Z8KeyToStri+0x3ac>
 *   @0xf3680 sub r3, r4, #112
 *   @0xf3684 cmp r3, #11
 *   @0xf3688 pophi {r3, r4, r5, pc}
 *   @0xf368c ldr r0, [pc, #0x1d8]
 *   @0xf3690 sub r3, r4, #111
 *   @0xf3694 ldr r2, [pc, #0x1d4]
 *   @0xf3698 mov r1, #64
 *   @0xf369c add r0, pc, r0
 *   @0xf36a0 add r2, pc, r2
 *   @0xf36a4 mov r4, r0
 *   @0xf36a8 bl 0xb65c8 <snprintf@plt>
 *   @0xf36ac mov r0, r4
 *   @0xf36b0 pop {r3, r4, r5, pc}
 *   @0xf36b4 ldr r0, [pc, #0x1b8]
 *   @0xf36b8 add r0, pc, r0
 *   @0xf36bc b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf36c0 ldr r0, [pc, #0x1b0]
 *   @0xf36c4 add r0, pc, r0
 *   @0xf36c8 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf36cc ldr r0, [pc, #0x1a8]
 *   @0xf36d0 add r0, pc, r0
 *   @0xf36d4 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf36d8 ldr r0, [pc, #0x1a0]
 *   @0xf36dc add r0, pc, r0
 *   @0xf36e0 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf36e4 ldr r0, [pc, #0x198]
 *   @0xf36e8 add r0, pc, r0
 *   @0xf36ec b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf36f0 ldr r0, [pc, #0x190]
 *   @0xf36f4 add r0, pc, r0
 *   @0xf36f8 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf36fc ldr r0, [pc, #0x188]
 *   @0xf3700 add r0, pc, r0
 *   @0xf3704 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3708 ldr r0, [pc, #0x180]
 *   @0xf370c add r0, pc, r0
 *   @0xf3710 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3714 ldr r0, [pc, #0x178]
 *   @0xf3718 add r0, pc, r0
 *   @0xf371c b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3720 ldr r0, [pc, #0x170]
 *   @0xf3724 add r0, pc, r0
 *   @0xf3728 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf372c ldr r0, [pc, #0x168]
 *   @0xf3730 add r0, pc, r0
 *   @0xf3734 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3738 ldr r0, [pc, #0x160]
 *   @0xf373c add r0, pc, r0
 *   @0xf3740 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3744 ldr r0, [pc, #0x158]
 *   @0xf3748 add r0, pc, r0
 *   @0xf374c b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3750 ldr r0, [pc, #0x150]
 *   @0xf3754 add r0, pc, r0
 *   @0xf3758 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf375c ldr r0, [pc, #0x148]
 *   @0xf3760 add r0, pc, r0
 *   @0xf3764 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3768 ldr r0, [pc, #0x140]
 *   @0xf376c add r0, pc, r0
 *   @0xf3770 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3774 ldr r0, [pc, #0x138]
 *   @0xf3778 add r0, pc, r0
 *   @0xf377c b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3780 ldr r0, [pc, #0x130]
 *   @0xf3784 add r0, pc, r0
 *   @0xf3788 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf378c ldr r0, [pc, #0x128]
 *   @0xf3790 add r0, pc, r0
 *   @0xf3794 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3798 ldr r0, [pc, #0x120]
 *   @0xf379c add r0, pc, r0
 *   @0xf37a0 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf37a4 ldr r0, [pc, #0x118]
 *   @0xf37a8 add r0, pc, r0
 *   @0xf37ac b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf37b0 ldr r0, [pc, #0x110]
 *   @0xf37b4 add r0, pc, r0
 *   @0xf37b8 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf37bc ldr r0, [pc, #0x108]
 *   @0xf37c0 add r0, pc, r0
 *   @0xf37c4 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf37c8 ldr r0, [pc, #0x100]
 *   @0xf37cc add r0, pc, r0
 *   @0xf37d0 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf37d4 sub r3, r0, #48
 *   @0xf37d8 cmp r3, #9
 *   @0xf37dc bhi 0xf385c <_Z8KeyToStri+0x3d0>
 *   @0xf37e0 ldr r5, [pc, #0xec]
 *   @0xf37e4 mov r3, r0
 *   @0xf37e8 ldr r2, [pc, #0xe8]
 *   @0xf37ec mov r1, #64
 *   @0xf37f0 add r5, pc, r5
 *   @0xf37f4 add r2, pc, r2
 *   @0xf37f8 mov r0, r5
 *   @0xf37fc bl 0xb65c8 <snprintf@plt>
 *   @0xf3800 sub r3, r4, #65
 *   @0xf3804 cmp r3, #25
 *   @0xf3808 mov r0, r5
 *   @0xf380c bhi 0xf3674 <_Z8KeyToStri+0x1e8>
 *   @0xf3810 ldr r0, [pc, #0xc4]
 *   @0xf3814 mov r3, r4
 *   @0xf3818 ldr r2, [pc, #0xc0]
 *   @0xf381c mov r1, #64
 *   @0xf3820 add r0, pc, r0
 *   @0xf3824 add r2, pc, r2
 *   @0xf3828 mov r4, r0
 *   @0xf382c bl 0xb65c8 <snprintf@plt>
 *   @0xf3830 mov r0, r4
 *   @0xf3834 pop {r3, r4, r5, pc}
 *   @0xf3838 ldr r4, [pc, #0xa4]
 *   @0xf383c mov r1, #64
 *   @0xf3840 ldr r2, [pc, #0xa0]
 *   @0xf3844 add r4, pc, r4
 *   @0xf3848 add r2, pc, r2
 *   @0xf384c mov r0, r4
 *   @0xf3850 bl 0xb65c8 <snprintf@plt>
 *   @0xf3854 mov r0, r4
 *   @0xf3858 pop {r3, r4, r5, pc}
 *   @0xf385c ldr r0, [pc, #0x88]
 *   @0xf3860 add r0, pc, r0
 *   @0xf3864 b 0xf3668 <_Z8KeyToStri+0x1dc>
 *   @0xf3868 eoreq r3, r4, r4, ror r10
 *   @0xf386c eorseq pc, r8, r12, ror #26
 *   @0xf3870 eoreq r3, r4, r0, ror r10
 *   @0xf3874 eoreq r3, r4, r12, lsr #20
 *   @0xf3878 eoreq r3, r4, r12, lsr #20
 *   @0xf387c eoreq r3, r4, r8, asr #18
 *   @0xf3880 eoreq r3, r4, r8, asr #18
 *   @0xf3884 eoreq r3, r4, r8, asr #18
 *   @0xf3888 eoreq r3, r4, r8, asr #18
 *   @0xf388c eoreq r3, r4, r0, lsl #18
 *   @0xf3890 eoreq r3, r4, r0, lsl #18
 *   @0xf3894 eoreq r3, r4, r0, lsr r9
 *   @0xf3898 eoreq r3, r4, r0, lsr r9
 *   @0xf389c eoreq r3, r4, r12, lsr #18
 *   @0xf38a0 eoreq r3, r4, r8, lsr #18
 *   @0xf38a4 eoreq r3, r4, r4, lsr #18
 *   @0xf38a8 eoreq r3, r4, r0, lsr #18
 *   @0xf38ac eoreq r3, r4, r12, lsl r9
 *   @0xf38b0 eoreq r3, r4, r8, lsl r9
 *   @0xf38b4 eoreq r3, r4, r8, lsl r9
 *   @0xf38b8 eoreq r3, r4, r8, lsl r9
 *   @0xf38bc eoreq r3, r4, r4, lsl r9
 *   @0xf38c0 eoreq r3, r4, r4, lsl r9
 *   @0xf38c4 eoreq r3, r4, r0, lsl r9
 *   @0xf38c8 eoreq r3, r4, r12, lsl #18
 *   @0xf38cc eoreq r3, r4, r8, lsl #18
 *   @0xf38d0 eoreq r3, r4, r4, lsl #18
 *   @0xf38d4 eorseq pc, r8, r8, lsl r12
 *   @0xf38d8 eoreq r3, r4, r8, lsl #18
 *   @0xf38dc eorseq pc, r8, r8, ror #23
 *   @0xf38e0 .word 0x002438d8
 *   @0xf38e4 eorseq pc, r8, r4, asr #23
 *   @0xf38e8 .word 0x002438bc
 *   @0xf38ec mlaeq r4, r4, r7, r3
 */
