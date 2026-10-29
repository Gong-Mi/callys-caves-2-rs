/* cally 逆向卡：All_62 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 281 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/281 F_MpGridAddRectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x108e08  size 112  28 条（0x108e08..0x108e78）
 * @func 0x108e08 0x108e78  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108e08 push {r4, r5, r6, r7, r8, lr}
 *   @0x108e0c mov r1, #0
 *   @0x108e10 ldr r4, [sp, #0x18]
 *   @0x108e14 mov r0, r4
 *   @0x108e18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108e1c mov r1, #1
 *   @0x108e20 mov r5, r0
 *   @0x108e24 mov r0, r4
 *   @0x108e28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108e2c mov r1, #2
 *   @0x108e30 mov r8, r0
 *   @0x108e34 mov r0, r4
 *   @0x108e38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108e3c mov r1, #3
 *   @0x108e40 mov r7, r0
 *   @0x108e44 mov r0, r4
 *   @0x108e48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108e4c mov r1, #4
 *   @0x108e50 mov r6, r0
 *   @0x108e54 mov r0, r4
 *   @0x108e58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108e5c mov r1, r8
 *   @0x108e60 mov r2, r7
 *   @0x108e64 mov r3, r6
 *   @0x108e68 str r0, [sp, #0x18]
 *   @0x108e6c mov r0, r5
 *   @0x108e70 pop {r4, r5, r6, r7, r8, lr}
 *   @0x108e74 b 0x19a4f4 <_Z24Motion_Grid_AddRectangleiiiii>
 *
 * ══ §2/281 F_RoomPrevious(RValue&, CInstance*, CInstance*, int, RValue*)  0x109b08  size 112  28 条（0x109b08..0x109b78）
 * @func 0x109b08 0x109b88  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Exists(int) / Room_First() / Room_Previous(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109b08 push {r3, r4, r5, lr}
 *   @0x109b0c mov r1, #0
 *   @0x109b10 mov r4, r0
 *   @0x109b14 ldr r0, [sp, #0x10]
 *   @0x109b18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109b1c mov r3, #0
 *   @0x109b20 str r3, [r4, #0xc]
 *   @0x109b24 mov r5, r0
 *   @0x109b28 bl 0x1b52f8 <_Z11Room_Existsi>
 *   @0x109b2c cmp r0, #0
 *   @0x109b30 bne 0x109b48 <_Z14F_RoomPreviousR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x109b34 mov r3, #0
 *   @0x109b38 mov r2, r3
 *   @0x109b3c movt r3, #0xbff0
 *   @0x109b40 stm r4, {r2, r3}
 *   @0x109b44 pop {r3, r4, r5, pc}
 *   @0x109b48 bl 0x1b5d08 <_Z10Room_Firstv>
 *   @0x109b4c cmp r0, r5
 *   @0x109b50 beq 0x109b34 <_Z14F_RoomPreviousR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x109b54 mov r0, r5
 *   @0x109b58 bl 0x1b5d40 <_Z13Room_Previousi>
 *   @0x109b5c vmov s15, r0
 *   @0x109b60 vcvt.f64.s32 d7, s15
 *   @0x109b64 vmov r0, r1, d7
 *   @0x109b68 vmov r2, s14
 *   @0x109b6c mov r3, r1
 *   @0x109b70 stm r4, {r2, r3}
 *   @0x109b74 pop {r3, r4, r5, pc}
 *
 * ══ §3/281 F_RoomNext(RValue&, CInstance*, CInstance*, int, RValue*)  0x109b78  size 112  28 条（0x109b78..0x109be8）
 * @func 0x109b78 0x109be8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Exists(int) / Room_Last() / Room_Next(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109b78 push {r3, r4, r5, lr}
 *   @0x109b7c mov r1, #0
 *   @0x109b80 mov r4, r0
 *   @0x109b84 ldr r0, [sp, #0x10]
 *   @0x109b88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109b8c mov r3, #0
 *   @0x109b90 str r3, [r4, #0xc]
 *   @0x109b94 mov r5, r0
 *   @0x109b98 bl 0x1b52f8 <_Z11Room_Existsi>
 *   @0x109b9c cmp r0, #0
 *   @0x109ba0 bne 0x109bb8 <_Z10F_RoomNextR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x109ba4 mov r3, #0
 *   @0x109ba8 mov r2, r3
 *   @0x109bac movt r3, #0xbff0
 *   @0x109bb0 stm r4, {r2, r3}
 *   @0x109bb4 pop {r3, r4, r5, pc}
 *   @0x109bb8 bl 0x1b5d20 <_Z9Room_Lastv>
 *   @0x109bbc cmp r0, r5
 *   @0x109bc0 beq 0x109ba4 <_Z10F_RoomNextR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x109bc4 mov r0, r5
 *   @0x109bc8 bl 0x1b5da4 <_Z9Room_Nexti>
 *   @0x109bcc vmov s15, r0
 *   @0x109bd0 vcvt.f64.s32 d7, s15
 *   @0x109bd4 vmov r0, r1, d7
 *   @0x109bd8 vmov r2, s14
 *   @0x109bdc mov r3, r1
 *   @0x109be0 stm r4, {r2, r3}
 *   @0x109be4 pop {r3, r4, r5, pc}
 *
 * ══ §4/281 F_Clamp(RValue&, CInstance*, CInstance*, int, RValue*)  0x10dfa8  size 112  28 条（0x10dfa8..0x10e018）
 * @func 0x10dfa8 0x10e018  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dfa8 push {r3, r4, r5, lr}
 *   @0x10dfac vpush {d8, d9}
 *   @0x10dfb0 mov r5, r0
 *   @0x10dfb4 ldr r4, [sp, #0x20]
 *   @0x10dfb8 mov r1, #0
 *   @0x10dfbc str r1, [r0, #0xc]
 *   @0x10dfc0 mov r0, r4
 *   @0x10dfc4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10dfc8 vmov d9, r0, r1
 *   @0x10dfcc mov r0, r4
 *   @0x10dfd0 mov r1, #1
 *   @0x10dfd4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10dfd8 vmov d8, r0, r1
 *   @0x10dfdc mov r0, r4
 *   @0x10dfe0 mov r1, #2
 *   @0x10dfe4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10dfe8 vcmpe.f64 d9, d8
 *   @0x10dfec vmrs APSR_nzcv, fpscr
 *   @0x10dff0 vmovpl.f64 d8, d9
 *   @0x10dff4 vmov d7, r0, r1
 *   @0x10dff8 vcmpe.f64 d8, d7
 *   @0x10dffc vmrs APSR_nzcv, fpscr
 *   @0x10e000 vmovle r0, r1, d8
 *   @0x10e004 mov r2, r0
 *   @0x10e008 mov r3, r1
 *   @0x10e00c stm r5, {r2, r3}
 *   @0x10e010 vpop {d8, d9}
 *   @0x10e014 pop {r3, r4, r5, pc}
 *
 * ══ §5/281 F_DotProduct(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e078  size 112  28 条（0x10e078..0x10e0e8）
 * @func 0x10e078 0x10e0e8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×4
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e078 push {r3, r4, r5, lr}
 *   @0x10e07c vpush {d8, d9, d10}
 *   @0x10e080 mov r5, r0
 *   @0x10e084 ldr r4, [sp, #0x28]
 *   @0x10e088 mov r1, #0
 *   @0x10e08c str r1, [r0, #0xc]
 *   @0x10e090 mov r0, r4
 *   @0x10e094 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e098 vmov d9, r0, r1
 *   @0x10e09c mov r0, r4
 *   @0x10e0a0 mov r1, #1
 *   @0x10e0a4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e0a8 vmov d10, r0, r1
 *   @0x10e0ac mov r0, r4
 *   @0x10e0b0 mov r1, #2
 *   @0x10e0b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e0b8 vmov d8, r0, r1
 *   @0x10e0bc mov r0, r4
 *   @0x10e0c0 mov r1, #3
 *   @0x10e0c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e0c8 vmov d6, r0, r1
 *   @0x10e0cc vmul.f64 d7, d10, d6
 *   @0x10e0d0 vmla.f64 d7, d9, d8
 *   @0x10e0d4 vmov r2, s14
 *   @0x10e0d8 vmov r3, s15
 *   @0x10e0dc stm r5, {r2, r3}
 *   @0x10e0e0 vpop {d8, d9, d10}
 *   @0x10e0e4 pop {r3, r4, r5, pc}
 *
 * ══ §6/281 F_DSin(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e514  size 112  28 条（0x10e514..0x10e584）
 * @func 0x10e514 0x10e584  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / 0xb6580
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e514 mov r3, #0
 *   @0x10e518 push {r4, lr}
 *   @0x10e51c mov r1, r3
 *   @0x10e520 str r3, [r0, #0xc]
 *   @0x10e524 mov r4, r0
 *   @0x10e528 ldr r0, [sp, #0x8]
 *   @0x10e52c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e530 vldr s14, [pc, #64]
 *   @0x10e534 vldr s15, [pc, #64]
 *   @0x10e538 vmov s12, r0
 *   @0x10e53c vmul.f32 s14, s12, s14
 *   @0x10e540 vdiv.f32 s15, s14, s15
 *   @0x10e544 vmov r0, s15
 *   @0x10e548 bl 0xb6580 <sinf@plt>
 *   @0x10e54c vldr s14, [pc, #44]
 *   @0x10e550 vmov s15, r0
 *   @0x10e554 vabs.f32 s13, s15
 *   @0x10e558 vcmpe.f32 s13, s14
 *   @0x10e55c vmrs APSR_nzcv, fpscr
 *   @0x10e560 vcvtpl.f64.f32 d6, s15
 *   @0x10e564 movmi r2, #0
 *   @0x10e568 movmi r3, #0
 *   @0x10e56c vmovpl r2, r3, d6
 *   @0x10e570 stm r4, {r2, r3}
 *   @0x10e574 pop {r4, pc}
 *   @0x10e578 ldrdmi r0, r1, [r9], #-251
 *   @0x10e57c teqmi r4, #0
 *   @0x10e580 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §7/281 F_DCos(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e5d4  size 112  28 条（0x10e5d4..0x10e644）
 * @func 0x10e5d4 0x10e644  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / 0xb658c
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e5d4 mov r3, #0
 *   @0x10e5d8 push {r4, lr}
 *   @0x10e5dc mov r1, r3
 *   @0x10e5e0 str r3, [r0, #0xc]
 *   @0x10e5e4 mov r4, r0
 *   @0x10e5e8 ldr r0, [sp, #0x8]
 *   @0x10e5ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e5f0 vldr s14, [pc, #64]
 *   @0x10e5f4 vldr s15, [pc, #64]
 *   @0x10e5f8 vmov s12, r0
 *   @0x10e5fc vmul.f32 s14, s12, s14
 *   @0x10e600 vdiv.f32 s15, s14, s15
 *   @0x10e604 vmov r0, s15
 *   @0x10e608 bl 0xb658c <cosf@plt>
 *   @0x10e60c vldr s14, [pc, #44]
 *   @0x10e610 vmov s15, r0
 *   @0x10e614 vabs.f32 s13, s15
 *   @0x10e618 vcmpe.f32 s13, s14
 *   @0x10e61c vmrs APSR_nzcv, fpscr
 *   @0x10e620 vcvtpl.f64.f32 d6, s15
 *   @0x10e624 movmi r2, #0
 *   @0x10e628 movmi r3, #0
 *   @0x10e62c vmovpl r2, r3, d6
 *   @0x10e630 stm r4, {r2, r3}
 *   @0x10e634 pop {r4, pc}
 *   @0x10e638 ldrdmi r0, r1, [r9], #-251
 *   @0x10e63c teqmi r4, #0
 *   @0x10e640 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §8/281 F_DTan(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e694  size 112  28 条（0x10e694..0x10e704）
 * @func 0x10e694 0x10e704  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / 0xb6748
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e694 mov r3, #0
 *   @0x10e698 push {r4, lr}
 *   @0x10e69c mov r1, r3
 *   @0x10e6a0 str r3, [r0, #0xc]
 *   @0x10e6a4 mov r4, r0
 *   @0x10e6a8 ldr r0, [sp, #0x8]
 *   @0x10e6ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e6b0 vldr s14, [pc, #64]
 *   @0x10e6b4 vldr s15, [pc, #64]
 *   @0x10e6b8 vmov s12, r0
 *   @0x10e6bc vmul.f32 s14, s12, s14
 *   @0x10e6c0 vdiv.f32 s15, s14, s15
 *   @0x10e6c4 vmov r0, s15
 *   @0x10e6c8 bl 0xb6748 <tanf@plt>
 *   @0x10e6cc vldr s14, [pc, #44]
 *   @0x10e6d0 vmov s15, r0
 *   @0x10e6d4 vabs.f32 s13, s15
 *   @0x10e6d8 vcmpe.f32 s13, s14
 *   @0x10e6dc vmrs APSR_nzcv, fpscr
 *   @0x10e6e0 vcvtpl.f64.f32 d6, s15
 *   @0x10e6e4 movmi r2, #0
 *   @0x10e6e8 movmi r3, #0
 *   @0x10e6ec vmovpl r2, r3, d6
 *   @0x10e6f0 stm r4, {r2, r3}
 *   @0x10e6f4 pop {r4, pc}
 *   @0x10e6f8 ldrdmi r0, r1, [r9], #-251
 *   @0x10e6fc teqmi r4, #0
 *   @0x10e700 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §9/281 F_DateValidTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x1146ac  size 112  28 条（0x1146ac..0x11471c）
 * @func 0x1146ac 0x11471c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1146ac push {r4, r5, r6, r7, r8, lr}
 *   @0x1146b0 mov r4, #0
 *   @0x1146b4 ldr r6, [sp, #0x18]
 *   @0x1146b8 mov r1, r4
 *   @0x1146bc str r4, [r0, #0xc]
 *   @0x1146c0 mov r5, r0
 *   @0x1146c4 str r4, [r0]
 *   @0x1146c8 str r4, [r0, #0x4]
 *   @0x1146cc mov r0, r6
 *   @0x1146d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1146d4 mov r1, #1
 *   @0x1146d8 mov r7, r0
 *   @0x1146dc mov r0, r6
 *   @0x1146e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1146e4 mov r1, #2
 *   @0x1146e8 mov r8, r0
 *   @0x1146ec mov r0, r6
 *   @0x1146f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1146f4 cmp r7, #23
 *   @0x1146f8 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x1146fc cmp r8, #59
 *   @0x114700 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x114704 cmp r0, #59
 *   @0x114708 strls r4, [r5]
 *   @0x11470c movls r3, r4
 *   @0x114710 movtls r3, #0x3ff0
 *   @0x114714 strls r3, [r5, #0x4]
 *   @0x114718 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §10/281 F_DrawLineWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ae68  size 112  28 条（0x11ae68..0x11aed8）
 * @func 0x11ae68 0x11aee8  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ae68 push {r4, r5, r6, r7, r8, lr}
 *   @0x11ae6c mov r1, #0
 *   @0x11ae70 ldr r4, [sp, #0x18]
 *   @0x11ae74 mov r0, r4
 *   @0x11ae78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ae7c mov r1, #1
 *   @0x11ae80 mov r5, r0
 *   @0x11ae84 mov r0, r4
 *   @0x11ae88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ae8c mov r1, #2
 *   @0x11ae90 mov r8, r0
 *   @0x11ae94 mov r0, r4
 *   @0x11ae98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ae9c mov r1, #3
 *   @0x11aea0 mov r7, r0
 *   @0x11aea4 mov r0, r4
 *   @0x11aea8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11aeac mov r1, #4
 *   @0x11aeb0 mov r6, r0
 *   @0x11aeb4 mov r0, r4
 *   @0x11aeb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11aebc mov r1, r8
 *   @0x11aec0 mov r2, r7
 *   @0x11aec4 mov r3, r6
 *   @0x11aec8 str r0, [sp, #0x18]
 *   @0x11aecc mov r0, r5
 *   @0x11aed0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11aed4 b 0x16a2ec <_Z18GR_Draw_Line_Widthfffff>
 *
 * ══ §11/281 F_DrawRectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x11aed8  size 112  28 条（0x11aed8..0x11af48）
 * @func 0x11aed8 0x11af48  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11aed8 push {r4, r5, r6, r7, r8, lr}
 *   @0x11aedc mov r1, #0
 *   @0x11aee0 ldr r4, [sp, #0x18]
 *   @0x11aee4 mov r0, r4
 *   @0x11aee8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11aeec mov r1, #1
 *   @0x11aef0 mov r5, r0
 *   @0x11aef4 mov r0, r4
 *   @0x11aef8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11aefc mov r1, #2
 *   @0x11af00 mov r8, r0
 *   @0x11af04 mov r0, r4
 *   @0x11af08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11af0c mov r1, #3
 *   @0x11af10 mov r7, r0
 *   @0x11af14 mov r0, r4
 *   @0x11af18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11af1c mov r1, #4
 *   @0x11af20 mov r6, r0
 *   @0x11af24 mov r0, r4
 *   @0x11af28 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11af2c mov r1, r8
 *   @0x11af30 mov r2, r7
 *   @0x11af34 mov r3, r6
 *   @0x11af38 str r0, [sp, #0x18]
 *   @0x11af3c mov r0, r5
 *   @0x11af40 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11af44 b 0x16aa1c <_Z20YYGML_draw_rectangleffffb>
 *
 * ══ §12/281 F_DrawEllipse(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b194  size 112  28 条（0x11b194..0x11b204）
 * @func 0x11b194 0x11b214  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b194 push {r4, r5, r6, r7, r8, lr}
 *   @0x11b198 mov r1, #0
 *   @0x11b19c ldr r4, [sp, #0x18]
 *   @0x11b1a0 mov r0, r4
 *   @0x11b1a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b1a8 mov r1, #1
 *   @0x11b1ac mov r5, r0
 *   @0x11b1b0 mov r0, r4
 *   @0x11b1b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b1b8 mov r1, #2
 *   @0x11b1bc mov r8, r0
 *   @0x11b1c0 mov r0, r4
 *   @0x11b1c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b1c8 mov r1, #3
 *   @0x11b1cc mov r7, r0
 *   @0x11b1d0 mov r0, r4
 *   @0x11b1d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b1d8 mov r1, #4
 *   @0x11b1dc mov r6, r0
 *   @0x11b1e0 mov r0, r4
 *   @0x11b1e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b1e8 mov r1, r8
 *   @0x11b1ec mov r2, r7
 *   @0x11b1f0 mov r3, r6
 *   @0x11b1f4 str r0, [sp, #0x18]
 *   @0x11b1f8 mov r0, r5
 *   @0x11b1fc pop {r4, r5, r6, r7, r8, lr}
 *   @0x11b200 b 0x16b278 <_Z15GR_Draw_Ellipseffffb>
 *
 * ══ §13/281 F_DrawArrow(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b204  size 112  28 条（0x11b204..0x11b274）
 * @func 0x11b204 0x11b284  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b204 push {r4, r5, r6, r7, r8, lr}
 *   @0x11b208 mov r1, #0
 *   @0x11b20c ldr r4, [sp, #0x18]
 *   @0x11b210 mov r0, r4
 *   @0x11b214 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b218 mov r1, #1
 *   @0x11b21c mov r5, r0
 *   @0x11b220 mov r0, r4
 *   @0x11b224 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b228 mov r1, #2
 *   @0x11b22c mov r8, r0
 *   @0x11b230 mov r0, r4
 *   @0x11b234 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b238 mov r1, #3
 *   @0x11b23c mov r7, r0
 *   @0x11b240 mov r0, r4
 *   @0x11b244 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b248 mov r1, #4
 *   @0x11b24c mov r6, r0
 *   @0x11b250 mov r0, r4
 *   @0x11b254 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b258 mov r1, r8
 *   @0x11b25c mov r2, r7
 *   @0x11b260 mov r3, r6
 *   @0x11b264 str r0, [sp, #0x18]
 *   @0x11b268 mov r0, r5
 *   @0x11b26c pop {r4, r5, r6, r7, r8, lr}
 *   @0x11b270 b 0x16bee4 <_Z13GR_Draw_Arrowfffff>
 *
 * ══ §14/281 F_DrawButton(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b274  size 112  28 条（0x11b274..0x11b2e4）
 * @func 0x11b274 0x11b2e4  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b274 push {r4, r5, r6, r7, r8, lr}
 *   @0x11b278 mov r1, #0
 *   @0x11b27c ldr r4, [sp, #0x18]
 *   @0x11b280 mov r0, r4
 *   @0x11b284 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b288 mov r1, #1
 *   @0x11b28c mov r5, r0
 *   @0x11b290 mov r0, r4
 *   @0x11b294 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b298 mov r1, #2
 *   @0x11b29c mov r8, r0
 *   @0x11b2a0 mov r0, r4
 *   @0x11b2a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b2a8 mov r1, #3
 *   @0x11b2ac mov r7, r0
 *   @0x11b2b0 mov r0, r4
 *   @0x11b2b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b2b8 mov r1, #4
 *   @0x11b2bc mov r6, r0
 *   @0x11b2c0 mov r0, r4
 *   @0x11b2c4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b2c8 mov r1, r8
 *   @0x11b2cc mov r2, r7
 *   @0x11b2d0 mov r3, r6
 *   @0x11b2d4 str r0, [sp, #0x18]
 *   @0x11b2d8 mov r0, r5
 *   @0x11b2dc pop {r4, r5, r6, r7, r8, lr}
 *   @0x11b2e0 b 0x16bfc4 <_Z14GR_Draw_Buttonffffb>
 *
 * ══ §15/281 YYGML_draw_text_color(float, float, char const*, int, int, int, int, float)  0x1224b8  size 112  28 条（0x1224b8..0x122528）
 * @func 0x1224b8 0x122528  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*) / GR_Text_Draw_Color(float, float, char const*, int, int, unsigned int, unsigned int, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x40×1 / 0x44×1 / 0x48×1 / 0x4c×1 / 0x4×1 / 0x8×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1224b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1224bc sub sp, sp, #28
 *   @0x1224c0 mov r5, r0
 *   @0x1224c4 mov r0, r2
 *   @0x1224c8 mov r10, r3
 *   @0x1224cc ldr r7, [sp, #0x40]
 *   @0x1224d0 ldr r6, [sp, #0x44]
 *   @0x1224d4 mov r8, r1
 *   @0x1224d8 ldr r9, [sp, #0x48]
 *   @0x1224dc ldr r11, [sp, #0x4c]
 *   @0x1224e0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1224e4 mvn r12, #0
 *   @0x1224e8 str r10, [sp, #0x4]
 *   @0x1224ec str r7, [sp, #0x8]
 *   @0x1224f0 mov r3, r12
 *   @0x1224f4 str r11, [sp, #0x14]
 *   @0x1224f8 mov r1, r8
 *   @0x1224fc str r6, [sp, #0xc]
 *   @0x122500 str r9, [sp, #0x10]
 *   @0x122504 str r12, [sp]
 *   @0x122508 mov r4, r0
 *   @0x12250c mov r2, r0
 *   @0x122510 mov r0, r5
 *   @0x122514 bl 0x173338 <_Z18GR_Text_Draw_ColorffPKciijjjjf>
 *   @0x122518 mov r0, r4
 *   @0x12251c add sp, sp, #28
 *   @0x122520 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x122524 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §16/281 F_PartTypeSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x129010  size 112  28 条（0x129010..0x129080）
 * @func 0x129010 0x129080  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)×3 / YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129010 push {r4, r5, r6, r7, r8, lr}
 *   @0x129014 mov r1, #0
 *   @0x129018 ldr r4, [sp, #0x18]
 *   @0x12901c mov r0, r4
 *   @0x129020 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129024 mov r1, #1
 *   @0x129028 mov r5, r0
 *   @0x12902c mov r0, r4
 *   @0x129030 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129034 mov r1, #2
 *   @0x129038 mov r8, r0
 *   @0x12903c mov r0, r4
 *   @0x129040 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x129044 mov r1, #3
 *   @0x129048 mov r7, r0
 *   @0x12904c mov r0, r4
 *   @0x129050 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x129054 mov r1, #4
 *   @0x129058 mov r6, r0
 *   @0x12905c mov r0, r4
 *   @0x129060 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x129064 mov r1, r8
 *   @0x129068 mov r2, r7
 *   @0x12906c mov r3, r6
 *   @0x129070 str r0, [sp, #0x18]
 *   @0x129074 mov r0, r5
 *   @0x129078 pop {r4, r5, r6, r7, r8, lr}
 *   @0x12907c b 0x1a31e0 <_Z19ParticleType_Spriteiibbb>
 *
 * ══ §17/281 F_PathGetTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d448  size 112  28 条（0x12d448..0x12d4b8）
 * @func 0x12d448 0x12d4b8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / CPath::GetPathTime() / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d448 push {r3, r4, r5, lr}
 *   @0x12d44c vpush {d8}
 *   @0x12d450 mov r1, #0
 *   @0x12d454 ldr r5, [sp, #0x18]
 *   @0x12d458 mov r4, r0
 *   @0x12d45c mov r0, r5
 *   @0x12d460 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d464 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d468 cmp r0, #0
 *   @0x12d46c beq 0x12d4a8 <_Z13F_PathGetTimeR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x12d470 bl 0x1a7bc0 <_ZN5CPath11GetPathTimeEv>
 *   @0x12d474 mov r1, #1
 *   @0x12d478 vmov s16, r0
 *   @0x12d47c mov r0, r5
 *   @0x12d480 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12d484 vmov s14, r0
 *   @0x12d488 vmul.f32 s16, s16, s14
 *   @0x12d48c vcvt.f64.f32 d7, s16
 *   @0x12d490 vmov r2, r3, d7
 *   @0x12d494 stm r4, {r2, r3}
 *   @0x12d498 mov r1, #0
 *   @0x12d49c vpop {d8}
 *   @0x12d4a0 str r1, [r4, #0xc]
 *   @0x12d4a4 pop {r3, r4, r5, pc}
 *   @0x12d4a8 mov r3, #0
 *   @0x12d4ac mov r2, #0
 *   @0x12d4b0 movt r3, #0xbff0
 *   @0x12d4b4 b 0x12d494 <_Z13F_PathGetTimeR6RValueP9CInstanceS2_iPS_+0x4c>
 *
 * ══ §18/281 F_TimeLineMomentAddScript(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e05c  size 112  28 条（0x12e05c..0x12e0cc）
 * @func 0x12e05c 0x12e0cc  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / TimeLine_Data(int) / CTimeLine::Find(int) / F_TimeLineMomentAddScript(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e05c push {r4, r5, r6, lr}
 *   @0x12e060 mov r1, #0
 *   @0x12e064 ldr r4, [sp, #0x10]
 *   @0x12e068 mov r0, r4
 *   @0x12e06c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e070 bl 0x1f2c48 <_Z13TimeLine_Datai>
 *   @0x12e074 subs r5, r0, #0
 *   @0x12e078 popeq {r4, r5, r6, pc}
 *   @0x12e07c mov r0, r4
 *   @0x12e080 mov r1, #1
 *   @0x12e084 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e088 mov r1, #2
 *   @0x12e08c mov r6, r0
 *   @0x12e090 mov r0, r4
 *   @0x12e094 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e098 mov r1, r6
 *   @0x12e09c mov r4, r0
 *   @0x12e0a0 mov r0, r5
 *   @0x12e0a4 bl 0x1f1c28 <_ZN9CTimeLine4FindEi>
 *   @0x12e0a8 mov r1, r6
 *   @0x12e0ac mov r2, r4
 *   @0x12e0b0 cmp r0, #0
 *   @0x12e0b4 mov r0, r5
 *   @0x12e0b8 blt 0x12e0c4 <_Z25F_TimeLineMomentAddScriptR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x12e0bc pop {r4, r5, r6, lr}
 *   @0x12e0c0 b 0x1f1f9c <_ZN9CTimeLine16MakeMomentScriptEii>
 *   @0x12e0c4 pop {r4, r5, r6, lr}
 *   @0x12e0c8 b 0x1f1d80 <_ZN9CTimeLine15AddMomentScriptEii>
 *
 * ══ §19/281 YYGML_ini_open_from_string(char const*)  0x13ba08  size 112  28 条（0x13ba08..0x13ba78）
 * @func 0x13ba08 0x13ba78  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::WriteIniFile() / MemoryManager::Free(void const*) / IniFile::~IniFile() / operator delete(void*) / operator new(unsigned int) / IniFile::IniFile()
 * 字段偏移 top8: 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ba08 push {r4, r5, r6, lr}
 *   @0x13ba0c mov r6, r0
 *   @0x13ba10 ldr r4, [pc, #0x5c]
 *   @0x13ba14 ldr r4, [pc, r4]
 *   @0x13ba18 ldr r0, [r4]
 *   @0x13ba1c cmp r0, #0
 *   @0x13ba20 beq 0x13ba50 <_Z26YYGML_ini_open_from_stringPKc+0x48>
 *   @0x13ba24 bl 0x235d3c <_ZN7IniFile12WriteIniFileEv>
 *   @0x13ba28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13ba2c ldr r5, [r4]
 *   @0x13ba30 cmp r5, #0
 *   @0x13ba34 beq 0x13ba48 <_Z26YYGML_ini_open_from_stringPKc+0x40>
 *   @0x13ba38 mov r0, r5
 *   @0x13ba3c bl 0x235428 <_ZN7IniFileD2Ev>
 *   @0x13ba40 mov r0, r5
 *   @0x13ba44 bl 0x27d1d0 <_ZdlPv>
 *   @0x13ba48 mov r3, #0
 *   @0x13ba4c str r3, [r4]
 *   @0x13ba50 mov r0, #28
 *   @0x13ba54 bl 0x27c524 <_Znwj>
 *   @0x13ba58 mov r5, r0
 *   @0x13ba5c bl 0x235488 <_ZN7IniFileC2Ev>
 *   @0x13ba60 mov r0, r5
 *   @0x13ba64 mov r1, r6
 *   @0x13ba68 str r5, [r4]
 *   @0x13ba6c pop {r4, r5, r6, lr}
 *   @0x13ba70 b 0x236250 <_ZN7IniFile7SetTextEPKc>
 *   @0x13ba74 eoreq r3, r11, r0, lsl #17
 *
 * ══ §20/281 YYGML_ini_open(char const*)  0x13baac  size 112  28 条（0x13baac..0x13bb1c）
 * @func 0x13baac 0x13bb1c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::WriteIniFile() / MemoryManager::Free(void const*) / IniFile::~IniFile() / operator delete(void*) / operator new(unsigned int) / IniFile::IniFile(char*, bool)
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13baac push {r4, r5, r6, lr}
 *   @0x13bab0 subs r6, r0, #0
 *   @0x13bab4 popeq {r4, r5, r6, pc}
 *   @0x13bab8 ldr r4, [pc, #0x58]
 *   @0x13babc ldr r4, [pc, r4]
 *   @0x13bac0 ldr r0, [r4]
 *   @0x13bac4 cmp r0, #0
 *   @0x13bac8 beq 0x13baf8 <_Z14YYGML_ini_openPKc+0x4c>
 *   @0x13bacc bl 0x235d3c <_ZN7IniFile12WriteIniFileEv>
 *   @0x13bad0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13bad4 ldr r5, [r4]
 *   @0x13bad8 cmp r5, #0
 *   @0x13badc beq 0x13baf0 <_Z14YYGML_ini_openPKc+0x44>
 *   @0x13bae0 mov r0, r5
 *   @0x13bae4 bl 0x235428 <_ZN7IniFileD2Ev>
 *   @0x13bae8 mov r0, r5
 *   @0x13baec bl 0x27d1d0 <_ZdlPv>
 *   @0x13baf0 mov r3, #0
 *   @0x13baf4 str r3, [r4]
 *   @0x13baf8 mov r0, #28
 *   @0x13bafc bl 0x27c524 <_Znwj>
 *   @0x13bb00 mov r1, r6
 *   @0x13bb04 mov r2, #0
 *   @0x13bb08 mov r5, r0
 *   @0x13bb0c bl 0x2362b8 <_ZN7IniFileC2EPcb>
 *   @0x13bb10 str r5, [r4]
 *   @0x13bb14 pop {r4, r5, r6, pc}
 *   @0x13bb18 .word 0x002b37d8
 *
 * ══ §21/281 YYGML_ini_read_real(char const*, char const*, double)  0x13bb34  size 112  28 条（0x13bb34..0x13bba4）
 * @func 0x13bb34 0x13bba4  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetKey(char const*, char const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x60×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13bb34 ldr r12, [pc, #0x60]
 *   @0x13bb38 push {r4, r5, r6, lr}
 *   @0x13bb3c ldr r12, [pc, r12]
 *   @0x13bb40 mov r6, r0
 *   @0x13bb44 mov lr, r1
 *   @0x13bb48 ldr r0, [r12]
 *   @0x13bb4c mov r4, r2
 *   @0x13bb50 mov r5, r3
 *   @0x13bb54 cmp r0, #0
 *   @0x13bb58 beq 0x13bb80 <_Z19YYGML_ini_read_realPKcS0_d+0x4c>
 *   @0x13bb5c mov r1, r6
 *   @0x13bb60 mov r2, lr
 *   @0x13bb64 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x13bb68 cmp r0, #0
 *   @0x13bb6c beq 0x13bb90 <_Z19YYGML_ini_read_realPKcS0_d+0x5c>
 *   @0x13bb70 ldr r0, [r0, #0x8]
 *   @0x13bb74 mov r1, #0
 *   @0x13bb78 pop {r4, r5, r6, lr}
 *   @0x13bb7c b 0xb6658 <strtod@plt>
 *   @0x13bb80 mov r1, r0
 *   @0x13bb84 ldr r0, [pc, #0x14]
 *   @0x13bb88 add r0, pc, r0
 *   @0x13bb8c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13bb90 mov r0, r4
 *   @0x13bb94 mov r1, r5
 *   @0x13bb98 pop {r4, r5, r6, pc}
 *   @0x13bb9c eoreq r3, r11, r8, asr r7
 *   @0x13bba0 eoreq r4, r0, r0, ror #13
 *
 * ══ §22/281 F_ActionTimelineSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d840  size 112  28 条（0x13d840..0x13d8b0）
 * @func 0x13d840 0x13d8b0  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x18×1 / 0x14c×1 / 0x154×1 / 0x15c×1 / 0x15d×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d840 push {r4, r5, r6, r7, r8, lr}
 *   @0x13d844 mov r5, r1
 *   @0x13d848 ldr r4, [sp, #0x18]
 *   @0x13d84c mov r1, #0
 *   @0x13d850 mov r0, r4
 *   @0x13d854 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d858 mov r1, #1
 *   @0x13d85c mov r8, r0
 *   @0x13d860 mov r0, r4
 *   @0x13d864 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d868 mov r1, #2
 *   @0x13d86c mov r6, r0
 *   @0x13d870 mov r0, r4
 *   @0x13d874 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d878 mov r1, #3
 *   @0x13d87c mov r7, r0
 *   @0x13d880 mov r0, r4
 *   @0x13d884 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d888 rsbs r7, r7, #1
 *   @0x13d88c str r8, [r5, #0x14c]
 *   @0x13d890 movlo r7, #0
 *   @0x13d894 str r6, [r5, #0x154]
 *   @0x13d898 strb r7, [r5, #0x15c]
 *   @0x13d89c subs r3, r0, #1
 *   @0x13d8a0 rsbs r0, r3, #0
 *   @0x13d8a4 adcs r0, r0, r3
 *   @0x13d8a8 strb r0, [r5, #0x15d]
 *   @0x13d8ac pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §23/281 F_ActionSetSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d944  size 112  28 条（0x13d944..0x13d9b4）
 * @func 0x13d944 0x13d9b4  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int) / Command_SetSprite(CInstance*, int) / F_ActionSetSprite(RValue&, CInstance*, CInstance*, int, RValue*)+0x68 / CInstance::SetImageScaleX(float)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d944 push {r4, r5, r6, lr}
 *   @0x13d948 vpush {d8}
 *   @0x13d94c mov r4, r1
 *   @0x13d950 ldr r5, [sp, #0x18]
 *   @0x13d954 mov r1, #0
 *   @0x13d958 mov r0, r5
 *   @0x13d95c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d960 mov r1, #1
 *   @0x13d964 mov r6, r0
 *   @0x13d968 mov r0, r5
 *   @0x13d96c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d970 mov r1, r6
 *   @0x13d974 vmov s16, r0
 *   @0x13d978 mov r0, r4
 *   @0x13d97c bl 0x1c9dbc <_Z17Command_SetSpriteP9CInstancei>
 *   @0x13d980 vcmpe.f32 s16, #0
 *   @0x13d984 vmrs APSR_nzcv, fpscr
 *   @0x13d988 ble 0x13d9ac <_Z17F_ActionSetSpriteR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x13d98c mov r0, r4
 *   @0x13d990 vmov r1, s16
 *   @0x13d994 bl 0x192fec <_ZN9CInstance14SetImageScaleXEf>
 *   @0x13d998 vmov r1, s16
 *   @0x13d99c vpop {d8}
 *   @0x13d9a0 mov r0, r4
 *   @0x13d9a4 pop {r4, r5, r6, lr}
 *   @0x13d9a8 b 0x193014 <_ZN9CInstance14SetImageScaleYEf>
 *   @0x13d9ac vpop {d8}
 *   @0x13d9b0 pop {r4, r5, r6, pc}
 *
 * ══ §24/281 F_D3DVertexColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x143cd4  size 112  28 条（0x143cd4..0x143d44）
 * @func 0x143cd4 0x143d54  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143cd4 push {r4, r5, r6, r7, r8, lr}
 *   @0x143cd8 mov r1, #0
 *   @0x143cdc ldr r4, [sp, #0x18]
 *   @0x143ce0 mov r0, r4
 *   @0x143ce4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143ce8 mov r1, #1
 *   @0x143cec mov r5, r0
 *   @0x143cf0 mov r0, r4
 *   @0x143cf4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143cf8 mov r1, #2
 *   @0x143cfc mov r8, r0
 *   @0x143d00 mov r0, r4
 *   @0x143d04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143d08 mov r1, #3
 *   @0x143d0c mov r7, r0
 *   @0x143d10 mov r0, r4
 *   @0x143d14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x143d18 mov r1, #4
 *   @0x143d1c mov r6, r0
 *   @0x143d20 mov r0, r4
 *   @0x143d24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143d28 mov r1, r8
 *   @0x143d2c mov r2, r7
 *   @0x143d30 mov r3, r6
 *   @0x143d34 str r0, [sp, #0x18]
 *   @0x143d38 mov r0, r5
 *   @0x143d3c pop {r4, r5, r6, r7, r8, lr}
 *   @0x143d40 b 0x176ed4 <_Z18GR_3D_Vertex_Colorfffjf>
 *
 * ══ §25/281 F_D3DVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x143d44  size 112  28 条（0x143d44..0x143db4）
 * @func 0x143d44 0x143db4  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143d44 push {r4, r5, r6, r7, r8, lr}
 *   @0x143d48 mov r1, #0
 *   @0x143d4c ldr r4, [sp, #0x18]
 *   @0x143d50 mov r0, r4
 *   @0x143d54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143d58 mov r1, #1
 *   @0x143d5c mov r5, r0
 *   @0x143d60 mov r0, r4
 *   @0x143d64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143d68 mov r1, #2
 *   @0x143d6c mov r8, r0
 *   @0x143d70 mov r0, r4
 *   @0x143d74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143d78 mov r1, #3
 *   @0x143d7c mov r7, r0
 *   @0x143d80 mov r0, r4
 *   @0x143d84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143d88 mov r1, #4
 *   @0x143d8c mov r6, r0
 *   @0x143d90 mov r0, r4
 *   @0x143d94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143d98 mov r1, r8
 *   @0x143d9c mov r2, r7
 *   @0x143da0 mov r3, r6
 *   @0x143da4 str r0, [sp, #0x18]
 *   @0x143da8 mov r0, r5
 *   @0x143dac pop {r4, r5, r6, r7, r8, lr}
 *   @0x143db0 b 0x176f7c <_Z20GR_3D_Vertex_Texturefffff>
 *
 * ══ §26/281 F_D3DSetProjectionOrtho(RValue&, CInstance*, CInstance*, int, RValue*)  0x1448a0  size 112  28 条（0x1448a0..0x144910）
 * @func 0x1448a0 0x144920  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1448a0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1448a4 mov r1, #0
 *   @0x1448a8 ldr r4, [sp, #0x18]
 *   @0x1448ac mov r0, r4
 *   @0x1448b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1448b4 mov r1, #1
 *   @0x1448b8 mov r5, r0
 *   @0x1448bc mov r0, r4
 *   @0x1448c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1448c4 mov r1, #2
 *   @0x1448c8 mov r8, r0
 *   @0x1448cc mov r0, r4
 *   @0x1448d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1448d4 mov r1, #3
 *   @0x1448d8 mov r7, r0
 *   @0x1448dc mov r0, r4
 *   @0x1448e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1448e4 mov r1, #4
 *   @0x1448e8 mov r6, r0
 *   @0x1448ec mov r0, r4
 *   @0x1448f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1448f4 mov r1, r8
 *   @0x1448f8 mov r2, r7
 *   @0x1448fc mov r3, r6
 *   @0x144900 str r0, [sp, #0x18]
 *   @0x144904 mov r0, r5
 *   @0x144908 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14490c b 0x1633e8 <_Z22GR_3D_Projection_Orthofffff>
 *
 * ══ §27/281 F_D3DSetProjectionPerspective(RValue&, CInstance*, CInstance*, int, RValue*)  0x144910  size 112  28 条（0x144910..0x144980）
 * @func 0x144910 0x144980  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144910 push {r4, r5, r6, r7, r8, lr}
 *   @0x144914 mov r1, #0
 *   @0x144918 ldr r4, [sp, #0x18]
 *   @0x14491c mov r0, r4
 *   @0x144920 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144924 mov r1, #1
 *   @0x144928 mov r5, r0
 *   @0x14492c mov r0, r4
 *   @0x144930 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144934 mov r1, #2
 *   @0x144938 mov r8, r0
 *   @0x14493c mov r0, r4
 *   @0x144940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144944 mov r1, #3
 *   @0x144948 mov r7, r0
 *   @0x14494c mov r0, r4
 *   @0x144950 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144954 mov r1, #4
 *   @0x144958 mov r6, r0
 *   @0x14495c mov r0, r4
 *   @0x144960 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144964 mov r1, r8
 *   @0x144968 mov r2, r7
 *   @0x14496c mov r3, r6
 *   @0x144970 str r0, [sp, #0x18]
 *   @0x144974 mov r0, r5
 *   @0x144978 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14497c b 0x163548 <_Z28GR_3D_Projection_Perspectivefffff>
 *
 * ══ §28/281 F_D3DModelDraw(RValue&, CInstance*, CInstance*, int, RValue*)  0x145440  size 112  28 条（0x145440..0x1454b0）
 * @func 0x145440 0x1454b0  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetPtrOrInt(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145440 push {r4, r5, r6, r7, r8, lr}
 *   @0x145444 mov r1, #4
 *   @0x145448 ldr r4, [sp, #0x18]
 *   @0x14544c mov r0, r4
 *   @0x145450 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x145454 mov r1, #0
 *   @0x145458 mov r8, r0
 *   @0x14545c mov r0, r4
 *   @0x145460 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145464 mov r1, #1
 *   @0x145468 mov r7, r0
 *   @0x14546c mov r0, r4
 *   @0x145470 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145474 mov r1, #2
 *   @0x145478 mov r6, r0
 *   @0x14547c mov r0, r4
 *   @0x145480 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145484 mov r1, #3
 *   @0x145488 mov r5, r0
 *   @0x14548c mov r0, r4
 *   @0x145490 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145494 str r8, [sp, #0x18]
 *   @0x145498 mov r1, r6
 *   @0x14549c mov r2, r5
 *   @0x1454a0 mov r3, r0
 *   @0x1454a4 mov r0, r7
 *   @0x1454a8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1454ac b 0x165370 <_Z11GR_3DM_Drawifffi>
 *
 * ══ §29/281 F_D3DLightEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x147364  size 112  28 条（0x147364..0x1473d4）
 * @func 0x147364 0x1473d4  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x34×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147364 push {r3, r4, r5, lr}
 *   @0x147368 mov r1, #0
 *   @0x14736c ldr r5, [sp, #0x10]
 *   @0x147370 mov r0, r5
 *   @0x147374 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x147378 cmp r0, #7
 *   @0x14737c mov r4, r0
 *   @0x147380 bhi 0x1473b8 <_Z16F_D3DLightEnableR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x147384 mov r0, r5
 *   @0x147388 mov r1, #1
 *   @0x14738c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x147390 ldr r3, [pc, #0x34]
 *   @0x147394 ldr r3, [pc, r3]
 *   @0x147398 vmov s14, r0
 *   @0x14739c mov r1, r0
 *   @0x1473a0 mov r0, r4
 *   @0x1473a4 add r4, r3, r4, lsl #2
 *   @0x1473a8 vcvt.f32.u32 s15, s14
 *   @0x1473ac vstr s15, [r4]
 *   @0x1473b0 pop {r3, r4, r5, lr}
 *   @0x1473b4 b 0x17f920 <_Z18GR_3D_Light_Enableib>
 *   @0x1473b8 ldr r0, [pc, #0x10]
 *   @0x1473bc mov r1, #0
 *   @0x1473c0 pop {r3, r4, r5, lr}
 *   @0x1473c4 add r0, pc, r0
 *   @0x1473c8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1473cc mlaeq r10, r0, r2, r8
 *   @0x1473d0 andseq r10, pc, r12, lsr r6
 *
 * ══ §30/281 F_GPUGetTexMipFilter(RValue&, CInstance*, CInstance*, int, RValue*)  0x1486c4  size 112  28 条（0x1486c4..0x148734）
 * @func 0x1486c4 0x148734  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x38×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1486c4 subs r1, r3, #0
 *   @0x1486c8 push {r4, lr}
 *   @0x1486cc mov r4, r0
 *   @0x1486d0 mov r0, #0
 *   @0x1486d4 mov r2, r0
 *   @0x1486d8 movt r0, #0xbff0
 *   @0x1486dc str r2, [r4, #0xc]
 *   @0x1486e0 str r0, [r4, #0x4]
 *   @0x1486e4 str r2, [r4]
 *   @0x1486e8 bne 0x148718 <_Z20F_GPUGetTexMipFilterR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1486ec ldr r0, [pc, #0x38]
 *   @0x1486f0 mov r2, #4
 *   @0x1486f4 ldr r0, [pc, r0]
 *   @0x1486f8 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x1486fc vmov s15, r0
 *   @0x148700 vcvt.f64.u32 d7, s15
 *   @0x148704 vmov r0, r1, d7
 *   @0x148708 vmov r2, s14
 *   @0x14870c mov r3, r1
 *   @0x148710 stm r4, {r2, r3}
 *   @0x148714 pop {r4, pc}
 *   @0x148718 ldr r0, [pc, #0x10]
 *   @0x14871c mov r1, r2
 *   @0x148720 pop {r4, lr}
 *   @0x148724 add r0, pc, r0
 *   @0x148728 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14872c eoreq r5, r10, r4, lsl #12
 *   @0x148730 andseq r9, pc, r8, lsr #24
 *
 * ══ §31/281 F_GPUGetTexMipBias(RValue&, CInstance*, CInstance*, int, RValue*)  0x1487b0  size 112  28 条（0x1487b0..0x148820）
 * @func 0x1487b0 0x148820  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x38×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1487b0 subs r1, r3, #0
 *   @0x1487b4 push {r4, lr}
 *   @0x1487b8 mov r4, r0
 *   @0x1487bc mov r0, #0
 *   @0x1487c0 mov r2, r0
 *   @0x1487c4 movt r0, #0xbff0
 *   @0x1487c8 str r2, [r4, #0xc]
 *   @0x1487cc str r0, [r4, #0x4]
 *   @0x1487d0 str r2, [r4]
 *   @0x1487d4 bne 0x148804 <_Z18F_GPUGetTexMipBiasR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1487d8 ldr r0, [pc, #0x38]
 *   @0x1487dc mov r2, #7
 *   @0x1487e0 ldr r0, [pc, r0]
 *   @0x1487e4 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x1487e8 vmov s15, r0
 *   @0x1487ec vcvt.f64.f32 d7, s15
 *   @0x1487f0 vmov r0, r1, d7
 *   @0x1487f4 vmov r2, s14
 *   @0x1487f8 mov r3, r1
 *   @0x1487fc stm r4, {r2, r3}
 *   @0x148800 pop {r4, pc}
 *   @0x148804 ldr r0, [pc, #0x10]
 *   @0x148808 mov r1, r2
 *   @0x14880c pop {r4, lr}
 *   @0x148810 add r0, pc, r0
 *   @0x148814 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148818 eoreq r5, r10, r8, lsl r5
 *   @0x14881c andseq r9, pc, r12, asr #23
 *
 * ══ §32/281 F_GPUGetTexMinMip(RValue&, CInstance*, CInstance*, int, RValue*)  0x14889c  size 112  28 条（0x14889c..0x14890c）
 * @func 0x14889c 0x14890c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x38×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14889c subs r1, r3, #0
 *   @0x1488a0 push {r4, lr}
 *   @0x1488a4 mov r4, r0
 *   @0x1488a8 mov r0, #0
 *   @0x1488ac mov r2, r0
 *   @0x1488b0 movt r0, #0xbff0
 *   @0x1488b4 str r2, [r4, #0xc]
 *   @0x1488b8 str r0, [r4, #0x4]
 *   @0x1488bc str r2, [r4]
 *   @0x1488c0 bne 0x1488f0 <_Z17F_GPUGetTexMinMipR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1488c4 ldr r0, [pc, #0x38]
 *   @0x1488c8 mov r2, #5
 *   @0x1488cc ldr r0, [pc, r0]
 *   @0x1488d0 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x1488d4 vmov s15, r0
 *   @0x1488d8 vcvt.f64.f32 d7, s15
 *   @0x1488dc vmov r0, r1, d7
 *   @0x1488e0 vmov r2, s14
 *   @0x1488e4 mov r3, r1
 *   @0x1488e8 stm r4, {r2, r3}
 *   @0x1488ec pop {r4, pc}
 *   @0x1488f0 ldr r0, [pc, #0x10]
 *   @0x1488f4 mov r1, r2
 *   @0x1488f8 pop {r4, lr}
 *   @0x1488fc add r0, pc, r0
 *   @0x148900 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148904 eoreq r5, r10, r12, lsr #8
 *   @0x148908 andseq r9, pc, r12, ror #22
 *
 * ══ §33/281 F_GPUGetTexMaxMip(RValue&, CInstance*, CInstance*, int, RValue*)  0x148988  size 112  28 条（0x148988..0x1489f8）
 * @func 0x148988 0x1489f8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x38×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148988 subs r1, r3, #0
 *   @0x14898c push {r4, lr}
 *   @0x148990 mov r4, r0
 *   @0x148994 mov r0, #0
 *   @0x148998 mov r2, r0
 *   @0x14899c movt r0, #0xbff0
 *   @0x1489a0 str r2, [r4, #0xc]
 *   @0x1489a4 str r0, [r4, #0x4]
 *   @0x1489a8 str r2, [r4]
 *   @0x1489ac bne 0x1489dc <_Z17F_GPUGetTexMaxMipR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1489b0 ldr r0, [pc, #0x38]
 *   @0x1489b4 mov r2, #6
 *   @0x1489b8 ldr r0, [pc, r0]
 *   @0x1489bc bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x1489c0 vmov s15, r0
 *   @0x1489c4 vcvt.f64.f32 d7, s15
 *   @0x1489c8 vmov r0, r1, d7
 *   @0x1489cc vmov r2, s14
 *   @0x1489d0 mov r3, r1
 *   @0x1489d4 stm r4, {r2, r3}
 *   @0x1489d8 pop {r4, pc}
 *   @0x1489dc ldr r0, [pc, #0x10]
 *   @0x1489e0 mov r1, r2
 *   @0x1489e4 pop {r4, lr}
 *   @0x1489e8 add r0, pc, r0
 *   @0x1489ec b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1489f0 eoreq r5, r10, r0, asr #6
 *   @0x1489f4 andseq r9, pc, r8, lsl #22
 *
 * ══ §34/281 F_GPUGetTexMaxAniso(RValue&, CInstance*, CInstance*, int, RValue*)  0x148a74  size 112  28 条（0x148a74..0x148ae4）
 * @func 0x148a74 0x148ae4  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x38×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148a74 subs r1, r3, #0
 *   @0x148a78 push {r4, lr}
 *   @0x148a7c mov r4, r0
 *   @0x148a80 mov r0, #0
 *   @0x148a84 mov r2, r0
 *   @0x148a88 movt r0, #0xbff0
 *   @0x148a8c str r2, [r4, #0xc]
 *   @0x148a90 str r0, [r4, #0x4]
 *   @0x148a94 str r2, [r4]
 *   @0x148a98 bne 0x148ac8 <_Z19F_GPUGetTexMaxAnisoR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x148a9c ldr r0, [pc, #0x38]
 *   @0x148aa0 mov r2, #8
 *   @0x148aa4 ldr r0, [pc, r0]
 *   @0x148aa8 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x148aac vmov s15, r0
 *   @0x148ab0 vcvt.f64.u32 d7, s15
 *   @0x148ab4 vmov r0, r1, d7
 *   @0x148ab8 vmov r2, s14
 *   @0x148abc mov r3, r1
 *   @0x148ac0 stm r4, {r2, r3}
 *   @0x148ac4 pop {r4, pc}
 *   @0x148ac8 ldr r0, [pc, #0x10]
 *   @0x148acc mov r1, r2
 *   @0x148ad0 pop {r4, lr}
 *   @0x148ad4 add r0, pc, r0
 *   @0x148ad8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148adc eoreq r5, r10, r4, asr r2
 *   @0x148ae0 andseq r9, pc, r4, lsl #21
 *
 * ══ §35/281 F_GPUGetTexMipEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x148b60  size 112  28 条（0x148b60..0x148bd0）
 * @func 0x148b60 0x148bd0  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x38×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148b60 subs r1, r3, #0
 *   @0x148b64 push {r4, lr}
 *   @0x148b68 mov r4, r0
 *   @0x148b6c mov r0, #0
 *   @0x148b70 mov r2, r0
 *   @0x148b74 movt r0, #0xbff0
 *   @0x148b78 str r2, [r4, #0xc]
 *   @0x148b7c str r0, [r4, #0x4]
 *   @0x148b80 str r2, [r4]
 *   @0x148b84 bne 0x148bb4 <_Z20F_GPUGetTexMipEnableR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x148b88 ldr r0, [pc, #0x38]
 *   @0x148b8c mov r2, #9
 *   @0x148b90 ldr r0, [pc, r0]
 *   @0x148b94 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x148b98 vmov s15, r0
 *   @0x148b9c vcvt.f64.u32 d7, s15
 *   @0x148ba0 vmov r0, r1, d7
 *   @0x148ba4 vmov r2, s14
 *   @0x148ba8 mov r3, r1
 *   @0x148bac stm r4, {r2, r3}
 *   @0x148bb0 pop {r4, pc}
 *   @0x148bb4 ldr r0, [pc, #0x10]
 *   @0x148bb8 mov r1, r2
 *   @0x148bbc pop {r4, lr}
 *   @0x148bc0 add r0, pc, r0
 *   @0x148bc4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148bc8 eoreq r5, r10, r8, ror #2
 *   @0x148bcc andseq r9, pc, r4, lsl #20
 *
 * ══ §36/281 Frustum_TestSphere(float, float, float, float)  0x149d20  size 112  28 条（0x149d20..0x149d90）
 * @func 0x149d20 0x149d90  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149d20 ldr r12, [pc, #0x64]
 *   @0x149d24 vmov s9, r1
 *   @0x149d28 vmov s10, r2
 *   @0x149d2c ldr r12, [pc, r12]
 *   @0x149d30 vmov s8, r0
 *   @0x149d34 add r2, r12, #8
 *   @0x149d38 add r1, r12, #104
 *   @0x149d3c vmov s11, r3
 *   @0x149d40 vldr s15, [r2, #-4]
 *   @0x149d44 vmul.f32 s15, s9, s15
 *   @0x149d48 vldr s12, [r2, #-8]
 *   @0x149d4c vldr s13, [r2]
 *   @0x149d50 vldr s14, [r2, #4]
 *   @0x149d54 add r2, r2, #16
 *   @0x149d58 vmla.f32 s15, s8, s12
 *   @0x149d5c vmla.f32 s15, s10, s13
 *   @0x149d60 vadd.f32 s15, s15, s14
 *   @0x149d64 vadd.f32 s15, s11, s15
 *   @0x149d68 vcmpe.f32 s15, #0
 *   @0x149d6c vmrs APSR_nzcv, fpscr
 *   @0x149d70 bmi 0x149d84 <_Z18Frustum_TestSphereffff+0x64>
 *   @0x149d74 cmp r2, r1
 *   @0x149d78 bne 0x149d40 <_Z18Frustum_TestSphereffff+0x20>
 *   @0x149d7c mov r0, #1065353216
 *   @0x149d80 bx lr
 *   @0x149d84 mov r0, #0
 *   @0x149d88 bx lr
 *   @0x149d8c eoreq r5, r10, r8, lsl #18
 *
 * ══ §37/281 GR_3D_Projection_LookAt(float, float, float, float, float, float, float, float, float)  0x163280  size 112  28 条（0x163280..0x1632f0）
 * @func 0x163280 0x1632f0  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::LookAtLH(yyMatrix*, yyVector3*, yyVector3*, yyVector3*) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x8c×1 / 0x90×1 / 0x80×1 / 0x84×1 / 0x88×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163280 push {r4, r5, r6, r7, lr}
 *   @0x163284 sub sp, sp, #108
 *   @0x163288 add r4, sp, #40
 *   @0x16328c ldr lr, [sp, #0x8c]
 *   @0x163290 ldr r12, [sp, #0x90]
 *   @0x163294 ldr r7, [sp, #0x80]
 *   @0x163298 ldr r6, [sp, #0x84]
 *   @0x16329c ldr r5, [sp, #0x88]
 *   @0x1632a0 str r0, [sp, #0x4]
 *   @0x1632a4 mov r0, r4
 *   @0x1632a8 str r1, [sp, #0x8]
 *   @0x1632ac add r1, sp, #4
 *   @0x1632b0 str r2, [sp, #0xc]
 *   @0x1632b4 add r2, sp, #16
 *   @0x1632b8 str r3, [sp, #0x10]
 *   @0x1632bc add r3, sp, #28
 *   @0x1632c0 str lr, [sp, #0x20]
 *   @0x1632c4 str r12, [sp, #0x24]
 *   @0x1632c8 str r7, [sp, #0x14]
 *   @0x1632cc str r6, [sp, #0x18]
 *   @0x1632d0 str r5, [sp, #0x1c]
 *   @0x1632d4 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x1632d8 mov r1, r4
 *   @0x1632dc mov r0, #0
 *   @0x1632e0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1632e4 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1632e8 add sp, sp, #108
 *   @0x1632ec pop {r4, r5, r6, r7, pc}
 *
 * ══ §38/281 GR_D3D_GetPixel(int, int)  0x169d00  size 112  28 条（0x169d00..0x169d70）
 * @func 0x169d00 0x169d70  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GrabScreenRect(int, int, int, int, int*, int*) / YYFree(void const*)
 * 字段偏移 top8: 0x58×1 / 0x54×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169d00 push {r4, lr}
 *   @0x169d04 sub sp, sp, #16
 *   @0x169d08 ldr r12, [pc, #0x58]
 *   @0x169d0c mov r3, r1
 *   @0x169d10 ldr lr, [pc, #0x54]
 *   @0x169d14 mov r2, r0
 *   @0x169d18 ldr r12, [pc, r12]
 *   @0x169d1c ldr lr, [pc, lr]
 *   @0x169d20 ldr r0, [r12]
 *   @0x169d24 add r12, sp, #8
 *   @0x169d28 ldr r1, [lr]
 *   @0x169d2c add lr, sp, #12
 *   @0x169d30 str r12, [sp]
 *   @0x169d34 mov r12, #1
 *   @0x169d38 str lr, [sp, #0x4]
 *   @0x169d3c str r12, [sp, #0x8]
 *   @0x169d40 str r12, [sp, #0xc]
 *   @0x169d44 bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_>
 *   @0x169d48 subs r3, r0, #0
 *   @0x169d4c moveq r0, r3
 *   @0x169d50 beq 0x169d60 <_Z15GR_D3D_GetPixelii+0x60>
 *   @0x169d54 ldr r4, [r3]
 *   @0x169d58 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x169d5c mov r0, r4
 *   @0x169d60 add sp, sp, #16
 *   @0x169d64 pop {r4, pc}
 *   @0x169d68 eoreq r6, r8, r12, lsl r4
 *   @0x169d6c eoreq r6, r8, r12, lsl r4
 *
 * ══ §39/281 YYGML_draw_set_alpha(float)  0x169dc4  size 112  28 条（0x169dc4..0x169e34）
 * @func 0x169dc4 0x169e34  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_draw_set_alpha(float)+0x44 / GR_D3DColor_Change_Alpha(unsigned int, unsigned int)
 * 字段偏移 top8: 0x44×1 / 0x40×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169dc4 vmov.f32 s14, #1.000000e+00
 *   @0x169dc8 vmov s15, r0
 *   @0x169dcc push {r4, lr}
 *   @0x169dd0 vcmpe.f32 s15, s14
 *   @0x169dd4 vmrs APSR_nzcv, fpscr
 *   @0x169dd8 movgt r2, #255
 *   @0x169ddc ble 0x169e08 <_Z20YYGML_draw_set_alphaf+0x44>
 *   @0x169de0 ldr r4, [pc, #0x44]
 *   @0x169de4 mov r1, r2
 *   @0x169de8 ldr r3, [pc, #0x40]
 *   @0x169dec ldr r4, [pc, r4]
 *   @0x169df0 ldr r3, [pc, r3]
 *   @0x169df4 ldr r0, [r4]
 *   @0x169df8 str r2, [r3]
 *   @0x169dfc bl 0x16ca9c <_Z24GR_D3DColor_Change_Alphajj>
 *   @0x169e00 str r0, [r4]
 *   @0x169e04 pop {r4, pc}
 *   @0x169e08 vcmpe.f32 s15, #0
 *   @0x169e0c vmrs APSR_nzcv, fpscr
 *   @0x169e10 vldrpl s14, [pc, #16]
 *   @0x169e14 vmulpl.f32 s15, s15, s14
 *   @0x169e18 movmi r2, #0
 *   @0x169e1c vcvtpl.u32.f32 s15, s15
 *   @0x169e20 vmovpl r2, s15
 *   @0x169e24 b 0x169de0 <_Z20YYGML_draw_set_alphaf+0x1c>
 *   @0x169e28 cmnmi pc, #0
 *   @0x169e2c eoreq r3, r8, r0, lsl pc
 *   @0x169e30 eoreq r3, r8, r0, lsl pc
 *
 * ══ §40/281 GR_Draw_Ellipse_Ext(float, float, float, float, unsigned int, unsigned int, bool)  0x16b2ac  size 112  28 条（0x16b2ac..0x16b31c）
 * @func 0x16b2ac 0x16b31c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Color_To_D3DColor(unsigned int, unsigned int)×2
 * 字段偏移 top8: 0x28×2 / 0x2c×2 / 0x30×2 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16b2ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16b2b0 sub sp, sp, #4
 *   @0x16b2b4 ldr r4, [pc, #0x5c]
 *   @0x16b2b8 mov r5, r0
 *   @0x16b2bc mov r6, r1
 *   @0x16b2c0 ldr r0, [sp, #0x28]
 *   @0x16b2c4 ldr r4, [pc, r4]
 *   @0x16b2c8 mov r9, r2
 *   @0x16b2cc mov r8, r3
 *   @0x16b2d0 ldr r7, [sp, #0x2c]
 *   @0x16b2d4 ldr r1, [r4]
 *   @0x16b2d8 ldrb r10, [sp, #0x30]
 *   @0x16b2dc bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16b2e0 ldr r1, [r4]
 *   @0x16b2e4 mov r11, r0
 *   @0x16b2e8 mov r0, r7
 *   @0x16b2ec bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16b2f0 str r11, [sp, #0x28]
 *   @0x16b2f4 str r10, [sp, #0x30]
 *   @0x16b2f8 mov r1, r6
 *   @0x16b2fc mov r2, r9
 *   @0x16b300 mov r3, r8
 *   @0x16b304 str r0, [sp, #0x2c]
 *   @0x16b308 mov r0, r5
 *   @0x16b30c add sp, sp, #4
 *   @0x16b310 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16b314 b 0x16af3c <_Z13_Draw_Ellipseffffjjb>
 *   @0x16b318 eoreq r2, r8, r12, lsr r10
 *
 * ══ §41/281 GR_Surface_Draw(int, float, float, float, float, float, unsigned int, float)  0x171dbc  size 112  28 条（0x171dbc..0x171e2c）
 * @func 0x171dbc 0x171e2c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int) / GR_Texture_Draw(int, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x10×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171dbc push {r4, r5, r6, lr}
 *   @0x171dc0 sub sp, sp, #24
 *   @0x171dc4 mov r4, r1
 *   @0x171dc8 mov r6, r2
 *   @0x171dcc mov r5, r3
 *   @0x171dd0 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x171dd4 cmp r0, #0
 *   @0x171dd8 beq 0x171e20 <_Z15GR_Surface_Drawifffffjf+0x64>
 *   @0x171ddc vldr s14, [sp, #44]
 *   @0x171de0 vldr s15, [pc, #64]
 *   @0x171de4 vmul.f32 s15, s14, s15
 *   @0x171de8 ldr r3, [sp, #0x30]
 *   @0x171dec mov r1, #0
 *   @0x171df0 ldr r0, [r0, #0x4]
 *   @0x171df4 vldr s14, [sp, #40]
 *   @0x171df8 str r6, [sp]
 *   @0x171dfc vstr s14, [sp, #8]
 *   @0x171e00 str r3, [sp, #0x10]
 *   @0x171e04 vldr s14, [sp, #52]
 *   @0x171e08 str r5, [sp, #0x4]
 *   @0x171e0c vstr s14, [sp, #20]
 *   @0x171e10 mov r3, r4
 *   @0x171e14 mov r2, r1
 *   @0x171e18 vstr s15, [sp, #12]
 *   @0x171e1c bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf>
 *   @0x171e20 add sp, sp, #24
 *   @0x171e24 pop {r4, r5, r6, pc}
 *   @0x171e28 vstmialo lr, {s30, s31}
 *
 * ══ §42/281 Object_Init()  0x19e908  size 112  28 条（0x19e908..0x19e978）
 * @func 0x19e908 0x19e978  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0
 * 字段偏移 top8: 0x54×1 / 0x44×1 / 0x4×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e908 push {r3, r4, r5, lr}
 *   @0x19e90c mov r0, #12
 *   @0x19e910 ldr r3, [pc, #0x54]
 *   @0x19e914 mov r5, #0
 *   @0x19e918 ldr r3, [pc, r3]
 *   @0x19e91c str r5, [r3]
 *   @0x19e920 bl 0x27c524 <_Znwj>
 *   @0x19e924 ldr r1, [pc, #0x44]
 *   @0x19e928 movw r3, #0x1ff
 *   @0x19e92c mov r2, #187
 *   @0x19e930 add r1, pc, r1
 *   @0x19e934 mov r4, r0
 *   @0x19e938 mov r0, #4096
 *   @0x19e93c str r3, [r4, #0x4]
 *   @0x19e940 mov r3, #1
 *   @0x19e944 str r5, [r4, #0x8]
 *   @0x19e948 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x19e94c mov r1, r5
 *   @0x19e950 mov r2, #4096
 *   @0x19e954 str r0, [r4]
 *   @0x19e958 bl 0xb65b0 <memset@plt>
 *   @0x19e95c ldr r3, [pc, #0x10]
 *   @0x19e960 ldr r3, [pc, r3]
 *   @0x19e964 str r4, [r3]
 *   @0x19e968 pop {r3, r4, r5, pc}
 *   @0x19e96c eoreq r1, r5, r12, asr #27
 *   @0x19e970 andseq lr, r10, r12, ror r3
 *   @0x19e974 .word 0x0024f2dc
 *
 * ══ §43/281 F_TileSetIndex(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b63b4  size 112  28 条（0x1b63b4..0x1b6424）
 * @func 0x1b63b4 0x1b6424  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x3c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b63b4 cmp r3, #2
 *   @0x1b63b8 mov r3, #0
 *   @0x1b63bc push {r4, r5, r6, lr}
 *   @0x1b63c0 mov r1, r3
 *   @0x1b63c4 mov r4, r0
 *   @0x1b63c8 movt r3, #0xbff0
 *   @0x1b63cc str r1, [r0, #0xc]
 *   @0x1b63d0 stm r0, {r1, r3}
 *   @0x1b63d4 ldr r5, [sp, #0x10]
 *   @0x1b63d8 beq 0x1b63ec <_Z14F_TileSetIndexR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1b63dc ldr r0, [pc, #0x3c]
 *   @0x1b63e0 pop {r4, r5, r6, lr}
 *   @0x1b63e4 add r0, pc, r0
 *   @0x1b63e8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b63ec mov r0, r5
 *   @0x1b63f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b63f4 mov r1, #1
 *   @0x1b63f8 mov r6, r0
 *   @0x1b63fc mov r0, r5
 *   @0x1b6400 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6404 lsr r6, r6, #19
 *   @0x1b6408 orr r0, r0, r6, lsl #19
 *   @0x1b640c vmov s15, r0
 *   @0x1b6410 vcvt.f64.s32 d7, s15
 *   @0x1b6414 vmov r2, r3, d7
 *   @0x1b6418 stm r4, {r2, r3}
 *   @0x1b641c pop {r4, r5, r6, pc}
 *   @0x1b6420 andseq r6, r9, r12, ror #31
 *
 * ══ §44/281 F_LayerBackgroundDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c02cc  size 112  28 条（0x1c02cc..0x1c033c）
 * @func 0x1c02cc 0x1c034c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c02cc cmp r3, #1
 *   @0x1c02d0 mov r1, #0
 *   @0x1c02d4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c02d8 mov r4, r1
 *   @0x1c02dc mov r5, r3
 *   @0x1c02e0 movt r1, #0xbff0
 *   @0x1c02e4 str r4, [r0, #0xc]
 *   @0x1c02e8 str r1, [r0, #0x4]
 *   @0x1c02ec str r4, [r0]
 *   @0x1c02f0 ldr r6, [sp, #0x18]
 *   @0x1c02f4 beq 0x1c030c <_Z24F_LayerBackgroundDestroyR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c02f8 ldr r0, [pc, #0x38]
 *   @0x1c02fc mov r1, r4
 *   @0x1c0300 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c0304 add r0, pc, r0
 *   @0x1c0308 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c030c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0310 mov r1, r4
 *   @0x1c0314 mov r7, r0
 *   @0x1c0318 mov r0, r6
 *   @0x1c031c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0320 mov r2, r5
 *   @0x1c0324 mov r3, r4
 *   @0x1c0328 mov r1, r0
 *   @0x1c032c mov r0, r7
 *   @0x1c0330 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c0334 b 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1c0338 andseq pc, r8, r12, lsr #9
 *
 * ══ §45/281 F_LayerSpriteDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c033c  size 112  28 条（0x1c033c..0x1c03ac）
 * @func 0x1c033c 0x1c03bc  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c033c cmp r3, #1
 *   @0x1c0340 mov r1, #0
 *   @0x1c0344 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c0348 mov r4, r1
 *   @0x1c034c mov r5, r3
 *   @0x1c0350 movt r1, #0xbff0
 *   @0x1c0354 str r4, [r0, #0xc]
 *   @0x1c0358 str r1, [r0, #0x4]
 *   @0x1c035c str r4, [r0]
 *   @0x1c0360 ldr r6, [sp, #0x18]
 *   @0x1c0364 beq 0x1c037c <_Z20F_LayerSpriteDestroyR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c0368 ldr r0, [pc, #0x38]
 *   @0x1c036c mov r1, r4
 *   @0x1c0370 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c0374 add r0, pc, r0
 *   @0x1c0378 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c037c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0380 mov r1, r4
 *   @0x1c0384 mov r7, r0
 *   @0x1c0388 mov r0, r6
 *   @0x1c038c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0390 mov r2, r5
 *   @0x1c0394 mov r3, r4
 *   @0x1c0398 mov r1, r0
 *   @0x1c039c mov r0, r7
 *   @0x1c03a0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c03a4 b 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1c03a8 andseq pc, r8, r4, ror r4
 *
 * ══ §46/281 F_LayerTilemapDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c03ac  size 112  28 条（0x1c03ac..0x1c041c）
 * @func 0x1c03ac 0x1c042c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c03ac cmp r3, #1
 *   @0x1c03b0 mov r1, #0
 *   @0x1c03b4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c03b8 mov r4, r1
 *   @0x1c03bc mov r5, r3
 *   @0x1c03c0 movt r1, #0xbff0
 *   @0x1c03c4 str r4, [r0, #0xc]
 *   @0x1c03c8 str r1, [r0, #0x4]
 *   @0x1c03cc str r4, [r0]
 *   @0x1c03d0 ldr r6, [sp, #0x18]
 *   @0x1c03d4 beq 0x1c03ec <_Z21F_LayerTilemapDestroyR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c03d8 ldr r0, [pc, #0x38]
 *   @0x1c03dc mov r1, r4
 *   @0x1c03e0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c03e4 add r0, pc, r0
 *   @0x1c03e8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c03ec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c03f0 mov r1, r4
 *   @0x1c03f4 mov r7, r0
 *   @0x1c03f8 mov r0, r6
 *   @0x1c03fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0400 mov r2, r5
 *   @0x1c0404 mov r3, r4
 *   @0x1c0408 mov r1, r0
 *   @0x1c040c mov r0, r7
 *   @0x1c0410 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c0414 b 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1c0418 andseq pc, r8, r8, lsr r4
 *
 * ══ §47/281 F_LayerTileDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c041c  size 112  28 条（0x1c041c..0x1c048c）
 * @func 0x1c041c 0x1c048c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c041c cmp r3, #1
 *   @0x1c0420 mov r1, #0
 *   @0x1c0424 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c0428 mov r4, r1
 *   @0x1c042c mov r5, r3
 *   @0x1c0430 movt r1, #0xbff0
 *   @0x1c0434 str r4, [r0, #0xc]
 *   @0x1c0438 str r1, [r0, #0x4]
 *   @0x1c043c str r4, [r0]
 *   @0x1c0440 ldr r6, [sp, #0x18]
 *   @0x1c0444 beq 0x1c045c <_Z18F_LayerTileDestroyR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c0448 ldr r0, [pc, #0x38]
 *   @0x1c044c mov r1, r4
 *   @0x1c0450 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c0454 add r0, pc, r0
 *   @0x1c0458 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c045c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0460 mov r1, r4
 *   @0x1c0464 mov r7, r0
 *   @0x1c0468 mov r0, r6
 *   @0x1c046c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0470 mov r2, r5
 *   @0x1c0474 mov r3, r4
 *   @0x1c0478 mov r1, r0
 *   @0x1c047c mov r0, r7
 *   @0x1c0480 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c0484 b 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1c0488 ldrsheq pc, [r8], -r12
 *
 * ══ §48/281 CVariableList::Alloc(char const*)  0x1f5178  size 112  28 条（0x1f5178..0x1f51e8）
 * @func 0x1f5178 0x1f51e8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CalcCRC_string(char const*) / YYSetString(RValue*, char const*) / operator new(unsigned int) / RVariable::RVariable(char const*)
 * 字段偏移 top8: 0x5c×1 / 0x4×1 / 0x18×1 / 0x1c×1 / 0x24×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5178 push {r3, r4, r5, lr}
 *   @0x1f517c mov r5, r0
 *   @0x1f5180 ldr r3, [pc, #0x5c]
 *   @0x1f5184 ldr r3, [pc, r3]
 *   @0x1f5188 ldr r4, [r3]
 *   @0x1f518c cmp r4, #0
 *   @0x1f5190 beq 0x1f51c8 <_ZN13CVariableList5AllocEPKc+0x50>
 *   @0x1f5194 ldr r2, [r4, #0x4]
 *   @0x1f5198 str r2, [r3]
 *   @0x1f519c bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x1f51a0 mov r3, #0
 *   @0x1f51a4 mov r1, r5
 *   @0x1f51a8 str r3, [r4, #0x18]
 *   @0x1f51ac str r3, [r4, #0x1c]
 *   @0x1f51b0 str r3, [r4, #0x24]
 *   @0x1f51b4 str r0, [r4, #0x28]
 *   @0x1f51b8 add r0, r4, #8
 *   @0x1f51bc bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x1f51c0 mov r0, r4
 *   @0x1f51c4 pop {r3, r4, r5, pc}
 *   @0x1f51c8 mov r0, #44
 *   @0x1f51cc bl 0x27c524 <_Znwj>
 *   @0x1f51d0 mov r1, r5
 *   @0x1f51d4 mov r4, r0
 *   @0x1f51d8 bl 0x1f5138 <_ZN9RVariableC2EPKc>
 *   @0x1f51dc mov r0, r4
 *   @0x1f51e0 pop {r3, r4, r5, pc}
 *   @0x1f51e4 ldrheq r11, [pc], -r0
 *
 * ══ §49/281 SV_ShowLives(CInstance*, int, RValue*)  0x1fb564  size 112  28 条（0x1fb564..0x1fb5d4）
 * @func 0x1fb564 0x1fb5e4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x38×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb564 push {r3, lr}
 *   @0x1fb568 ldr r3, [r2, #0xc]
 *   @0x1fb56c bic r3, r3, #-16777216
 *   @0x1fb570 cmp r3, #0
 *   @0x1fb574 bne 0x1fb5bc <_Z12SV_ShowLivesP9CInstanceiP6RValue+0x58>
 *   @0x1fb578 ldr r12, [r2]
 *   @0x1fb57c ldr r3, [r2, #0x4]
 *   @0x1fb580 mov r1, r3
 *   @0x1fb584 mov r0, r12
 *   @0x1fb588 bl 0xb66e8 <lrint@plt>
 *   @0x1fb58c vmov.f64 d7, #5.000000e-01
 *   @0x1fb590 ldr r3, [pc, #0x38]
 *   @0x1fb594 ldr r3, [pc, r3]
 *   @0x1fb598 vmov s11, r0
 *   @0x1fb59c mov r0, #1
 *   @0x1fb5a0 vcvt.f64.s32 d6, s11
 *   @0x1fb5a4 vcmpe.f64 d6, d7
 *   @0x1fb5a8 vmrs APSR_nzcv, fpscr
 *   @0x1fb5ac movle r2, #0
 *   @0x1fb5b0 movgt r2, #1
 *   @0x1fb5b4 strb r2, [r3]
 *   @0x1fb5b8 pop {r3, pc}
 *   @0x1fb5bc mov r0, r2
 *   @0x1fb5c0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb5c4 mov r12, r0
 *   @0x1fb5c8 mov r3, r1
 *   @0x1fb5cc b 0x1fb580 <_Z12SV_ShowLivesP9CInstanceiP6RValue+0x1c>
 *   @0x1fb5d0 andseq r4, pc, r0, rrx
 *
 * ══ §50/281 SV_ShowHealth(CInstance*, int, RValue*)  0x1fb5d4  size 112  28 条（0x1fb5d4..0x1fb644）
 * @func 0x1fb5d4 0x1fb644  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x38×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb5d4 push {r3, lr}
 *   @0x1fb5d8 ldr r3, [r2, #0xc]
 *   @0x1fb5dc bic r3, r3, #-16777216
 *   @0x1fb5e0 cmp r3, #0
 *   @0x1fb5e4 bne 0x1fb62c <_Z13SV_ShowHealthP9CInstanceiP6RValue+0x58>
 *   @0x1fb5e8 ldr r12, [r2]
 *   @0x1fb5ec ldr r3, [r2, #0x4]
 *   @0x1fb5f0 mov r1, r3
 *   @0x1fb5f4 mov r0, r12
 *   @0x1fb5f8 bl 0xb66e8 <lrint@plt>
 *   @0x1fb5fc vmov.f64 d7, #5.000000e-01
 *   @0x1fb600 ldr r3, [pc, #0x38]
 *   @0x1fb604 ldr r3, [pc, r3]
 *   @0x1fb608 vmov s11, r0
 *   @0x1fb60c mov r0, #1
 *   @0x1fb610 vcvt.f64.s32 d6, s11
 *   @0x1fb614 vcmpe.f64 d6, d7
 *   @0x1fb618 vmrs APSR_nzcv, fpscr
 *   @0x1fb61c movle r2, #0
 *   @0x1fb620 movgt r2, #1
 *   @0x1fb624 strb r2, [r3]
 *   @0x1fb628 pop {r3, pc}
 *   @0x1fb62c mov r0, r2
 *   @0x1fb630 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb634 mov r12, r0
 *   @0x1fb638 mov r3, r1
 *   @0x1fb63c b 0x1fb5f0 <_Z13SV_ShowHealthP9CInstanceiP6RValue+0x1c>
 *   @0x1fb640 ldrsheq r3, [pc], -r8
 *
 * ══ §51/281 CStream::Decrypt(int, int, int)  0x202380  size 112  28 条（0x202380..0x2023f0）
 * @func 0x202380 0x2023f0  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SetKey(int) / CStream::Decrypt(int, int, int)+0x5c / CStream::GetMemory() / CStream::GetSize()
 * 字段偏移 top8: 0x30×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202380 push {r4, r5, r6, lr}
 *   @0x202384 mov r6, r0
 *   @0x202388 mov r0, r1
 *   @0x20238c mov r5, r3
 *   @0x202390 mov r4, r2
 *   @0x202394 bl 0x202294 <_Z6SetKeyi>
 *   @0x202398 cmp r5, #0
 *   @0x20239c ble 0x2023dc <_ZN7CStream7DecryptEiii+0x5c>
 *   @0x2023a0 mov r0, r6
 *   @0x2023a4 add r5, r4, r5
 *   @0x2023a8 bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x2023ac cmp r4, r5
 *   @0x2023b0 popge {r4, r5, r6, pc}
 *   @0x2023b4 ldr r1, [pc, #0x30]
 *   @0x2023b8 add r2, r0, r4
 *   @0x2023bc add r0, r0, r5
 *   @0x2023c0 ldr r1, [pc, r1]
 *   @0x2023c4 ldrb r3, [r2]
 *   @0x2023c8 ldrb r3, [r1, r3]
 *   @0x2023cc strb r3, [r2], #1
 *   @0x2023d0 cmp r2, r0
 *   @0x2023d4 bne 0x2023c4 <_ZN7CStream7DecryptEiii+0x44>
 *   @0x2023d8 pop {r4, r5, r6, pc}
 *   @0x2023dc mov r0, r6
 *   @0x2023e0 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x2023e4 rsb r5, r4, r0
 *   @0x2023e8 b 0x2023a0 <_ZN7CStream7DecryptEiii+0x20>
 *   @0x2023ec andseq lr, lr, r0, asr #31
 *
 * ══ §52/281 CDS_Priority::Find(RValue*)  0x203f90  size 112  28 条（0x203f90..0x204000）
 * @func 0x203f90 0x204000  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Priority::Find(RValue*)+0x64×2 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x4×2 / 0x4c×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203f90 ldr r3, [r0, #0x4]
 *   @0x203f94 push {r4, r5, r6, r7, r8, lr}
 *   @0x203f98 cmp r3, #0
 *   @0x203f9c mov r5, r0
 *   @0x203fa0 mov r8, r1
 *   @0x203fa4 ble 0x203ff4 <_ZN12CDS_Priority4FindEP6RValue+0x64>
 *   @0x203fa8 ldr r7, [pc, #0x4c]
 *   @0x203fac mov r4, #0
 *   @0x203fb0 ldr r7, [pc, r7]
 *   @0x203fb4 b 0x203fc4 <_ZN12CDS_Priority4FindEP6RValue+0x34>
 *   @0x203fb8 ldr r3, [r5, #0x4]
 *   @0x203fbc cmp r3, r4
 *   @0x203fc0 ble 0x203ff4 <_ZN12CDS_Priority4FindEP6RValue+0x64>
 *   @0x203fc4 ldr r0, [r5, #0xc]
 *   @0x203fc8 lsl r6, r4, #4
 *   @0x203fcc mov r1, r8
 *   @0x203fd0 ldrd r2, r3, [r7]
 *   @0x203fd4 add r0, r0, r6
 *   @0x203fd8 add r4, r4, #1
 *   @0x203fdc bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x203fe0 cmp r0, #0
 *   @0x203fe4 bne 0x203fb8 <_ZN12CDS_Priority4FindEP6RValue+0x28>
 *   @0x203fe8 ldr r0, [r5, #0x14]
 *   @0x203fec add r0, r0, r6
 *   @0x203ff0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x203ff4 mov r0, #0
 *   @0x203ff8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x203ffc ldrsbeq sp, [lr], -r4
 *
 * ══ §53/281 _CountLinesInText(char*)  0x212ea0  size 112  28 条（0x212ea0..0x212f10）
 * @func 0x212ea0 0x212f10  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x212ea0 cmp r0, #0
 *   @0x212ea4 bxeq lr
 *   @0x212ea8 ldrb r3, [r0]
 *   @0x212eac cmp r3, #0
 *   @0x212eb0 beq 0x212f08 <_Z17_CountLinesInTextPc+0x68>
 *   @0x212eb4 mov r1, #0
 *   @0x212eb8 mov r2, r0
 *   @0x212ebc mov r0, r1
 *   @0x212ec0 b 0x212ed4 <_Z17_CountLinesInTextPc+0x34>
 *   @0x212ec4 mov r1, #0
 *   @0x212ec8 ldrb r3, [r2, #0x1]!
 *   @0x212ecc cmp r3, #0
 *   @0x212ed0 beq 0x212f04 <_Z17_CountLinesInTextPc+0x64>
 *   @0x212ed4 cmp r3, #13
 *   @0x212ed8 addeq r0, r0, #1
 *   @0x212edc moveq r1, #1
 *   @0x212ee0 beq 0x212ec8 <_Z17_CountLinesInTextPc+0x28>
 *   @0x212ee4 cmp r3, #10
 *   @0x212ee8 bne 0x212ec4 <_Z17_CountLinesInTextPc+0x24>
 *   @0x212eec cmp r1, #0
 *   @0x212ef0 addeq r0, r0, #1
 *   @0x212ef4 bne 0x212ec4 <_Z17_CountLinesInTextPc+0x24>
 *   @0x212ef8 ldrb r3, [r2, #0x1]!
 *   @0x212efc cmp r3, #0
 *   @0x212f00 bne 0x212ed4 <_Z17_CountLinesInTextPc+0x34>
 *   @0x212f04 bx lr
 *   @0x212f08 mov r0, r3
 *   @0x212f0c bx lr
 *
 * ══ §54/281 Audio_GetEmitterVelocity(int)  0x216f4c  size 112  28 条（0x216f4c..0x216fbc）
 * @func 0x216f4c 0x216fcc  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetEmitterVelocity(int)+0x34 / Audio_GetEmitterVelocity(int)+0x4c
 * 字段偏移 top8: 0x44×2 / 0x60×1 / 0x40×1 / 0x4×1 / 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216f4c ldr r2, [pc, #0x60]
 *   @0x216f50 mov r3, r0
 *   @0x216f54 ldr r2, [pc, r2]
 *   @0x216f58 ldrb r2, [r2]
 *   @0x216f5c cmp r2, #0
 *   @0x216f60 beq 0x216f80 <_Z24Audio_GetEmitterVelocityi+0x34>
 *   @0x216f64 cmp r1, #0
 *   @0x216f68 blt 0x216f80 <_Z24Audio_GetEmitterVelocityi+0x34>
 *   @0x216f6c ldr r2, [pc, #0x44]
 *   @0x216f70 add r2, pc, r2
 *   @0x216f74 ldr r0, [r2, #0x40]
 *   @0x216f78 cmp r1, r0
 *   @0x216f7c blt 0x216f98 <_Z24Audio_GetEmitterVelocityi+0x4c>
 *   @0x216f80 mov r2, #0
 *   @0x216f84 mov r0, r3
 *   @0x216f88 str r2, [r3]
 *   @0x216f8c str r2, [r3, #0x4]
 *   @0x216f90 str r2, [r3, #0x8]
 *   @0x216f94 bx lr
 *   @0x216f98 ldr r2, [r2, #0x44]
 *   @0x216f9c ldr r2, [r2, r1, lsl #2]
 *   @0x216fa0 add r2, r2, #12
 *   @0x216fa4 ldm r2, {r0, r1, r2}
 *   @0x216fa8 stm r3, {r0, r1, r2}
 *   @0x216fac mov r0, r3
 *   @0x216fb0 bx lr
 *   @0x216fb4 ldrsbeq r7, [sp], -r12
 *   @0x216fb8 subseq lr, r3, r4, lsr #6
 *
 * ══ §55/281 Audio_SetEmitterGain(int, double)  0x21803c  size 112  28 条（0x21803c..0x2180ac）
 * @func 0x21803c 0x2180bc  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1 / 0x48×1 / 0x24×1 / 0x40×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21803c ldr r1, [pc, #0x5c]
 *   @0x218040 vmov d7, r2, r3
 *   @0x218044 ldr r1, [pc, r1]
 *   @0x218048 ldrb r3, [r1]
 *   @0x21804c cmp r3, #0
 *   @0x218050 bxne lr
 *   @0x218054 ldr r3, [pc, #0x48]
 *   @0x218058 ldr r3, [pc, r3]
 *   @0x21805c ldrb r3, [r3]
 *   @0x218060 cmp r3, #0
 *   @0x218064 bxeq lr
 *   @0x218068 vcmpe.f64 d7, #0
 *   @0x21806c vmrs APSR_nzcv, fpscr
 *   @0x218070 bxlt lr
 *   @0x218074 cmp r0, #0
 *   @0x218078 bxlt lr
 *   @0x21807c ldr r3, [pc, #0x24]
 *   @0x218080 add r3, pc, r3
 *   @0x218084 ldr r2, [r3, #0x40]
 *   @0x218088 cmp r0, r2
 *   @0x21808c vcvtlt.f32.f64 s14, d7
 *   @0x218090 ldrlt r3, [r3, #0x44]
 *   @0x218094 ldrlt r3, [r3, r0, lsl #2]
 *   @0x218098 vstrlt s14, [r3, #40]
 *   @0x21809c bx lr
 *   @0x2180a0 andseq r7, sp, r8
 *   @0x2180a4 ldrsbeq r6, [sp], -r8
 *   @0x2180a8 subseq sp, r3, r4, lsl r2
 *
 * ══ §56/281 _alutFormatConstruct  0x222ac8  size 112  28 条（0x222ac8..0x222b38）
 * @func 0x222ac8 0x222b38  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222ac8 cmp r0, #1
 *   @0x222acc beq 0x222af8 <_alutFormatConstruct+0x30>
 *   @0x222ad0 cmp r0, #2
 *   @0x222ad4 bne 0x222b08 <_alutFormatConstruct+0x40>
 *   @0x222ad8 cmp r1, #8
 *   @0x222adc beq 0x222b28 <_alutFormatConstruct+0x60>
 *   @0x222ae0 cmp r1, #16
 *   @0x222ae4 bne 0x222b08 <_alutFormatConstruct+0x40>
 *   @0x222ae8 movw r3, #0x1103
 *   @0x222aec mov r0, #1
 *   @0x222af0 str r3, [r2]
 *   @0x222af4 bx lr
 *   @0x222af8 cmp r1, #8
 *   @0x222afc beq 0x222b1c <_alutFormatConstruct+0x54>
 *   @0x222b00 cmp r1, #16
 *   @0x222b04 beq 0x222b10 <_alutFormatConstruct+0x48>
 *   @0x222b08 mov r0, #0
 *   @0x222b0c bx lr
 *   @0x222b10 movw r3, #0x1101
 *   @0x222b14 str r3, [r2]
 *   @0x222b18 bx lr
 *   @0x222b1c mov r3, #4352
 *   @0x222b20 str r3, [r2]
 *   @0x222b24 bx lr
 *   @0x222b28 movw r3, #0x1102
 *   @0x222b2c mov r0, #1
 *   @0x222b30 str r3, [r2]
 *   @0x222b34 bx lr
 *
 * ══ §57/281 ogg_seek(void*, long long, int)  0x2235f4  size 112  28 条（0x2235f4..0x223664）
 * @func 0x2235f4 0x223664  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c0×5 / 0x2c×3 / 0x2bc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2235f4 ldr r3, [sp]
 *   @0x2235f8 ldr r1, [r0, #0x2bc]
 *   @0x2235fc cmp r3, #1
 *   @0x223600 beq 0x223644 <_Z8ogg_seekPvxi+0x50>
 *   @0x223604 cmp r3, #2
 *   @0x223608 beq 0x223634 <_Z8ogg_seekPvxi+0x40>
 *   @0x22360c cmp r3, #0
 *   @0x223610 beq 0x22361c <_Z8ogg_seekPvxi+0x28>
 *   @0x223614 mvn r0, #0
 *   @0x223618 bx lr
 *   @0x22361c ldr r3, [r1, #0x2c]
 *   @0x223620 str r2, [r0, #0x2c0]
 *   @0x223624 cmp r2, r3
 *   @0x223628 bhi 0x223658 <_Z8ogg_seekPvxi+0x64>
 *   @0x22362c mov r0, #0
 *   @0x223630 bx lr
 *   @0x223634 ldr r3, [r1, #0x2c]
 *   @0x223638 rsb r2, r2, r3
 *   @0x22363c str r2, [r0, #0x2c0]
 *   @0x223640 b 0x223624 <_Z8ogg_seekPvxi+0x30>
 *   @0x223644 ldr r12, [r0, #0x2c0]
 *   @0x223648 ldr r3, [r1, #0x2c]
 *   @0x22364c add r2, r12, r2
 *   @0x223650 str r2, [r0, #0x2c0]
 *   @0x223654 b 0x223624 <_Z8ogg_seekPvxi+0x30>
 *   @0x223658 str r3, [r0, #0x2c0]
 *   @0x22365c mvn r0, #0
 *   @0x223660 bx lr
 *
 * ══ §58/281 oggpack_adv  0x233a7c  size 112  28 条（0x233a7c..0x233aec）
 * @func 0x233a7c 0x233aec  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_adv+0x40
 * 字段偏移 top8: 0x4×5 / 0xc×3 / 0x10×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233a7c ldr r2, [r0, #0x4]
 *   @0x233a80 ldr r3, [r0, #0x10]
 *   @0x233a84 add r1, r1, r2
 *   @0x233a88 ldr r2, [r0]
 *   @0x233a8c add r12, r1, #7
 *   @0x233a90 str r4, [sp, #-0x4]!
 *   @0x233a94 sub r4, r3, r12, asr #3
 *   @0x233a98 cmp r2, r4
 *   @0x233a9c ble 0x233abc <oggpack_adv+0x40>
 *   @0x233aa0 str r3, [r0]
 *   @0x233aa4 mov r2, #0
 *   @0x233aa8 mov r3, #1
 *   @0x233aac str r2, [r0, #0xc]
 *   @0x233ab0 str r3, [r0, #0x4]
 *   @0x233ab4 ldr r4, [sp], #4
 *   @0x233ab8 bx lr
 *   @0x233abc cmp r1, #0
 *   @0x233ac0 ldr r3, [r0, #0xc]
 *   @0x233ac4 ldr r4, [sp], #4
 *   @0x233ac8 movge r12, r1
 *   @0x233acc and r1, r1, #7
 *   @0x233ad0 asr r12, r12, #3
 *   @0x233ad4 str r1, [r0, #0x4]
 *   @0x233ad8 add r2, r2, r12
 *   @0x233adc add r12, r3, r12
 *   @0x233ae0 str r2, [r0]
 *   @0x233ae4 str r12, [r0, #0xc]
 *   @0x233ae8 bx lr
 *
 * ══ §59/281 IniFile::NextLine()  0x2354a8  size 112  28 条（0x2354a8..0x235518）
 * @func 0x2354a8 0x235518  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x14×2 / 0x10×1 / 0x-4×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2354a8 ldr r1, [r0, #0x10]
 *   @0x2354ac ldr r3, [r0, #0xc]
 *   @0x2354b0 str r4, [sp, #-0x4]!
 *   @0x2354b4 add r2, r1, r3
 *   @0x2354b8 ldrb r12, [r1, r3]
 *   @0x2354bc cmp r12, #13
 *   @0x2354c0 cmpne r12, #10
 *   @0x2354c4 beq 0x2354fc <_ZN7IniFile8NextLineEv+0x54>
 *   @0x2354c8 ldr r12, [r0, #0x4]
 *   @0x2354cc cmp r3, r12
 *   @0x2354d0 bge 0x2354fc <_ZN7IniFile8NextLineEv+0x54>
 *   @0x2354d4 add r12, r1, r12
 *   @0x2354d8 rsb r4, r1, #1
 *   @0x2354dc add r3, r4, r2
 *   @0x2354e0 str r3, [r0, #0xc]
 *   @0x2354e4 ldrb r1, [r2, #0x1]!
 *   @0x2354e8 cmp r1, #13
 *   @0x2354ec cmpne r1, #10
 *   @0x2354f0 beq 0x2354fc <_ZN7IniFile8NextLineEv+0x54>
 *   @0x2354f4 cmp r2, r12
 *   @0x2354f8 bne 0x2354dc <_ZN7IniFile8NextLineEv+0x34>
 *   @0x2354fc ldr r2, [r0, #0x14]
 *   @0x235500 add r3, r3, #1
 *   @0x235504 ldr r4, [sp], #4
 *   @0x235508 str r3, [r0, #0xc]
 *   @0x23550c add r3, r2, #1
 *   @0x235510 str r3, [r0, #0x14]
 *   @0x235514 bx lr
 *
 * ══ §60/281 CPhysicsFixture::SetBoxShape(float, float)  0x2367d8  size 112  28 条（0x2367d8..0x236848）
 * @func 0x2367d8 0x236848  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::DeleteShape() / operator new(unsigned int) / b2PolygonShape::SetAsBox(float, float)
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x10×1 / 0x8×1 / 0x94×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2367d8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2367dc mov r7, r1
 *   @0x2367e0 mov r5, r0
 *   @0x2367e4 mov r6, r2
 *   @0x2367e8 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv>
 *   @0x2367ec mov r0, #152
 *   @0x2367f0 bl 0x27c524 <_Znwj>
 *   @0x2367f4 ldr r3, [pc, #0x48]
 *   @0x2367f8 mov r12, #2
 *   @0x2367fc mov r1, r7
 *   @0x236800 ldr r3, [pc, r3]
 *   @0x236804 movw lr, #0xd70a
 *   @0x236808 add r3, r3, #8
 *   @0x23680c movt lr, #0x3c23
 *   @0x236810 mov r2, r6
 *   @0x236814 stm r0, {r3, r12}
 *   @0x236818 mov r3, #0
 *   @0x23681c mov r12, #0
 *   @0x236820 str r3, [r0, #0xc]
 *   @0x236824 str r3, [r0, #0x10]
 *   @0x236828 mov r4, r0
 *   @0x23682c str lr, [r0, #0x8]
 *   @0x236830 str r12, [r0, #0x94]
 *   @0x236834 bl 0x2c5e9c <_ZN14b2PolygonShape8SetAsBoxEff>
 *   @0x236838 ldr r3, [r5, #0x20]
 *   @0x23683c str r4, [r3]
 *   @0x236840 pop {r3, r4, r5, r6, r7, pc}
 *   @0x236844 ldrheq r10, [r11], -r0
 *
 * ══ §61/281 anon_237b04  0x237b04  size 112  28 条（0x237b04..0x237b74）
 * @func 0x237b04 0x237b74  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6550 / Error_Show_Action(char const*, bool) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x58×1 / 0x50×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237b04 push {r4, r5, lr}
 *   @0x237b08 sub sp, sp, #1024
 *   @0x237b0c ldr r4, [pc, #0x58]
 *   @0x237b10 sub sp, sp, #12
 *   @0x237b14 add r5, sp, #4
 *   @0x237b18 ldr r3, [pc, #0x50]
 *   @0x237b1c ldr r4, [pc, r4]
 *   @0x237b20 ldr r1, [pc, #0x4c]
 *   @0x237b24 mov r2, r0
 *   @0x237b28 ldr r3, [pc, r3]
 *   @0x237b2c ldr r12, [r4]
 *   @0x237b30 add r1, pc, r1
 *   @0x237b34 mov r0, r5
 *   @0x237b38 str r12, [sp, #0x404]
 *   @0x237b3c bl 0xb6550 <sprintf@plt>
 *   @0x237b40 mov r0, r5
 *   @0x237b44 mov r1, #0
 *   @0x237b48 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x237b4c ldr r2, [sp, #0x404]
 *   @0x237b50 ldr r3, [r4]
 *   @0x237b54 cmp r2, r3
 *   @0x237b58 bne 0x237b68 <_ZN17b2ContactListenerD0Ev+0x8c>
 *   @0x237b5c add sp, sp, #1024
 *   @0x237b60 add sp, sp, #12
 *   @0x237b64 pop {r4, r5, pc}
 *   @0x237b68 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x237b6c andseq r5, r11, r4, lsr lr
 *   @0x237b70 mulseq r11, r12, r9
 *
 * ══ §62/281 CPhysicsWorld::ParticleGroupPoly()  0x239b98  size 112  28 条（0x239b98..0x239c08）
 * @func 0x239b98 0x239c08  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)
 * 字段偏移 top8: 0x3c×3 / 0x4×2 / 0x8×1 / 0x94×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239b98 push {r4, lr}
 *   @0x239b9c mov r4, r0
 *   @0x239ba0 ldr r0, [r0, #0x3c]
 *   @0x239ba4 cmp r0, #0
 *   @0x239ba8 beq 0x239bb8 <_ZN13CPhysicsWorld17ParticleGroupPolyEv+0x20>
 *   @0x239bac ldr r2, [r0]
 *   @0x239bb0 ldr r3, [r2, #0x4]
 *   @0x239bb4 blx r3
 *   @0x239bb8 mov r0, #152
 *   @0x239bbc bl 0x27c524 <_Znwj>
 *   @0x239bc0 ldr r2, [pc, #0x3c]
 *   @0x239bc4 mov r1, #2
 *   @0x239bc8 ldr r2, [pc, r2]
 *   @0x239bcc add r2, r2, #8
 *   @0x239bd0 mov r3, r0
 *   @0x239bd4 movw r0, #0xd70a
 *   @0x239bd8 str r1, [r3, #0x4]
 *   @0x239bdc movt r0, #0x3c23
 *   @0x239be0 str r2, [r3]
 *   @0x239be4 mov r1, #0
 *   @0x239be8 mov r2, #0
 *   @0x239bec str r0, [r3, #0x8]
 *   @0x239bf0 str r1, [r3, #0x94]
 *   @0x239bf4 str r2, [r3, #0xc]
 *   @0x239bf8 str r2, [r3, #0x10]
 *   @0x239bfc str r3, [r4, #0x3c]
 *   @0x239c00 pop {r4, pc}
 *   @0x239c04 andseq r7, r11, r8, ror #17
 *
 * ══ §63/281 F_JS_Array_isArray(RValue&, CInstance*, CInstance*, int, RValue*)  0x23cd14  size 112  28 条（0x23cd14..0x23cd84）
 * @func 0x23cd14 0x23cd84  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 0xc×2 / 0x8×2 / 0x4×2 / 0x28×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cd14 cmp r3, #0
 *   @0x23cd18 mov r3, #13
 *   @0x23cd1c push {r4, lr}
 *   @0x23cd20 mov r4, r0
 *   @0x23cd24 str r3, [r0, #0xc]
 *   @0x23cd28 beq 0x23cd3c <_Z18F_JS_Array_isArrayR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x23cd2c ldr r2, [sp, #0x8]
 *   @0x23cd30 ldr r3, [r2, #0xc]
 *   @0x23cd34 cmp r3, #6
 *   @0x23cd38 beq 0x23cd4c <_Z18F_JS_Array_isArrayR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x23cd3c mov r3, #0
 *   @0x23cd40 str r3, [r4]
 *   @0x23cd44 str r3, [r4, #0x4]
 *   @0x23cd48 pop {r4, pc}
 *   @0x23cd4c ldr r2, [sp, #0x8]
 *   @0x23cd50 ldr r1, [pc, #0x28]
 *   @0x23cd54 ldr r3, [r2]
 *   @0x23cd58 add r1, pc, r1
 *   @0x23cd5c ldr r0, [r3, #0x40]
 *   @0x23cd60 bl 0xb6574 <strcmp@plt>
 *   @0x23cd64 cmp r0, #0
 *   @0x23cd68 bne 0x23cd3c <_Z18F_JS_Array_isArrayR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x23cd6c mov r3, #0
 *   @0x23cd70 str r0, [r4]
 *   @0x23cd74 movt r3, #0x3ff0
 *   @0x23cd78 str r3, [r4, #0x4]
 *   @0x23cd7c pop {r4, pc}
 *   @0x23cd80 andeq r7, pc, r0, asr #23
 *
 * ══ §64/281 json_parse(json_object*, RValue&)  0x24beac  size 112  28 条（0x24beac..0x24bf1c）
 * @func 0x24beac 0x24bf1c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_get_type
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24beac push {r3, r4, r5, lr}
 *   @0x24beb0 subs r4, r0, #0
 *   @0x24beb4 mov r5, r1
 *   @0x24beb8 beq 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60>
 *   @0x24bebc bl 0x27e828 <json_object_get_type>
 *   @0x24bec0 cmp r0, #6
 *   @0x24bec4 addls pc, pc, r0, lsl #2
 *   @0x24bec8 b 0x24bf08 <_Z10json_parseP11json_objectR6RValue+0x5c>
 *   @0x24becc b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60>
 *   @0x24bed0 b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60>
 *   @0x24bed4 b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60>
 *   @0x24bed8 b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60>
 *   @0x24bedc b 0x24bef8 <_Z10json_parseP11json_objectR6RValue+0x4c>
 *   @0x24bee0 b 0x24bee8 <_Z10json_parseP11json_objectR6RValue+0x3c>
 *   @0x24bee4 b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60>
 *   @0x24bee8 mov r0, r4
 *   @0x24beec mov r1, r5
 *   @0x24bef0 pop {r3, r4, r5, lr}
 *   @0x24bef4 b 0x24bf1c <_Z18json_parse_jsarrayP11json_objectR6RValue>
 *   @0x24bef8 mov r0, r4
 *   @0x24befc mov r1, r5
 *   @0x24bf00 pop {r3, r4, r5, lr}
 *   @0x24bf04 b 0x24bd20 <_Z20json_parse_to_objectP11json_objectR6RValue>
 *   @0x24bf08 pop {r3, r4, r5, pc}
 *   @0x24bf0c mov r0, r4
 *   @0x24bf10 mov r1, r5
 *   @0x24bf14 pop {r3, r4, r5, lr}
 *   @0x24bf18 b 0x13c274 <_Z10json_valueP11json_objectP6RValue>
 *
 * ══ §65/281 spAttachmentTimeline_setFrame  0x282c1c  size 112  28 条（0x282c1c..0x282c8c）
 * @func 0x282c1c 0x282c8c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free / 0xb6538 / _malloc
 * 字段偏移 top8: 0x14×3 / 0x2×3 / 0xc×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282c1c push {r4, r5, r6, lr}
 *   @0x282c20 mov r4, r1
 *   @0x282c24 ldr r1, [r0, #0xc]
 *   @0x282c28 mov r5, r0
 *   @0x282c2c ldr r0, [r0, #0x14]
 *   @0x282c30 mov r6, r3
 *   @0x282c34 add r3, r1, r4, lsl #2
 *   @0x282c38 ldr r0, [r0, r4, lsl #2]
 *   @0x282c3c str r2, [r3]
 *   @0x282c40 bl 0x285c80 <_free>
 *   @0x282c44 cmp r6, #0
 *   @0x282c48 beq 0x282c7c <spAttachmentTimeline_setFrame+0x60>
 *   @0x282c4c mov r0, r6
 *   @0x282c50 ldr r5, [r5, #0x14]
 *   @0x282c54 bl 0xb6538 <strlen@plt>
 *   @0x282c58 ldr r1, [pc, #0x28]
 *   @0x282c5c movw r2, #0x22f
 *   @0x282c60 add r1, pc, r1
 *   @0x282c64 add r0, r0, #1
 *   @0x282c68 bl 0x285c10 <_malloc>
 *   @0x282c6c mov r1, r6
 *   @0x282c70 str r0, [r5, r4, lsl #2]
 *   @0x282c74 pop {r4, r5, r6, lr}
 *   @0x282c78 b 0xb65a4 <strcpy@plt>
 *   @0x282c7c ldr r3, [r5, #0x14]
 *   @0x282c80 str r6, [r3, r4, lsl #2]
 *   @0x282c84 pop {r4, r5, r6, pc}
 *   @0x282c88 strdeq r4, r5, [sp], -r0
 *
 * ══ §66/281 _spAttachmentLoader_setUnknownTypeError  0x284e68  size 112  28 条（0x284e68..0x284ed8）
 * @func 0x284e68 0x284ed8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6550 / _spAttachmentLoader_setError / 0xb65d4
 * 字段偏移 top8: 0x14×2 / 0x54×1 / 0x4c×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284e68 push {r4, r5, r6, lr}
 *   @0x284e6c sub sp, sp, #24
 *   @0x284e70 ldr r4, [pc, #0x54]
 *   @0x284e74 mov r2, r1
 *   @0x284e78 add r5, sp, #4
 *   @0x284e7c ldr r1, [pc, #0x4c]
 *   @0x284e80 ldr r4, [pc, r4]
 *   @0x284e84 mov r6, r0
 *   @0x284e88 add r1, pc, r1
 *   @0x284e8c mov r0, r5
 *   @0x284e90 ldr r3, [r4]
 *   @0x284e94 str r3, [sp, #0x14]
 *   @0x284e98 bl 0xb6550 <sprintf@plt>
 *   @0x284e9c ldr r1, [pc, #0x30]
 *   @0x284ea0 mov r2, r5
 *   @0x284ea4 mov r0, r6
 *   @0x284ea8 add r1, pc, r1
 *   @0x284eac bl 0x284df0 <_spAttachmentLoader_setError>
 *   @0x284eb0 ldr r2, [sp, #0x14]
 *   @0x284eb4 ldr r3, [r4]
 *   @0x284eb8 cmp r2, r3
 *   @0x284ebc bne 0x284ec8 <_spAttachmentLoader_setUnknownTypeError+0x60>
 *   @0x284ec0 add sp, sp, #24
 *   @0x284ec4 pop {r4, r5, r6, pc}
 *   @0x284ec8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x284ecc ldrsbeq r8, [r6], -r0
 *   @0x284ed0 andeq sp, r10, r4, lsl #13
 *   @0x284ed4 andeq r2, sp, r4, lsr #16
 *
 * ══ §67/281 Java_com_yoyogames_runner_RunnerJNILib_DsMapAddDouble  0x293c20  size 112  28 条（0x293c20..0x293c90）
 * @func 0x293c20 0x293c90  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / F_DsMapAdd_Internal(int, char*, double)
 * 字段偏移 top8: 0x2a4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x293c20 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x293c24 mov r6, r0
 *   @0x293c28 mov r7, r3
 *   @0x293c2c mov r9, r2
 *   @0x293c30 ldrd r4, r5, [sp, #32]
 *   @0x293c34 bl 0x290614 <setJNIEnv>
 *   @0x293c38 ldr r3, [r6]
 *   @0x293c3c mov r1, r7
 *   @0x293c40 mov r2, #0
 *   @0x293c44 mov r0, r6
 *   @0x293c48 ldr r3, [r3, #0x2a4]
 *   @0x293c4c blx r3
 *   @0x293c50 mov r2, r4
 *   @0x293c54 mov r3, r5
 *   @0x293c58 mov r8, r0
 *   @0x293c5c mov r0, r9
 *   @0x293c60 mov r1, r8
 *   @0x293c64 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x293c68 cmp r8, #0
 *   @0x293c6c cmpne r7, #0
 *   @0x293c70 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x293c74 ldr r3, [r6]
 *   @0x293c78 mov r1, r7
 *   @0x293c7c mov r2, r8
 *   @0x293c80 mov r0, r6
 *   @0x293c84 ldr r3, [r3, #0x2a8]
 *   @0x293c88 blx r3
 *   @0x293c8c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §68/281 Java_com_yoyogames_runner_RunnerJNILib_GCMPushResult  0x294c4c  size 112  28 条（0x294c4c..0x294cbc）
 * @func 0x294c4c 0x294cbc  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / Push_SendEvent(bool, ePushEventType, char const*)
 * 字段偏移 top8: 0x18×1 / 0x2a4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294c4c push {r4, r5, r6, r7, r8, lr}
 *   @0x294c50 mov r4, r0
 *   @0x294c54 mov r5, r2
 *   @0x294c58 mov r8, r3
 *   @0x294c5c ldrb r7, [sp, #0x18]
 *   @0x294c60 bl 0x290614 <setJNIEnv>
 *   @0x294c64 ldr r3, [r4]
 *   @0x294c68 mov r1, r5
 *   @0x294c6c mov r2, #0
 *   @0x294c70 mov r0, r4
 *   @0x294c74 ldr r3, [r3, #0x2a4]
 *   @0x294c78 blx r3
 *   @0x294c7c mov r1, r8
 *   @0x294c80 mov r6, r0
 *   @0x294c84 adds r0, r7, #0
 *   @0x294c88 mov r2, r6
 *   @0x294c8c movne r0, #1
 *   @0x294c90 bl 0x155f84 <_Z14Push_SendEventb14ePushEventTypePKc>
 *   @0x294c94 cmp r6, #0
 *   @0x294c98 cmpne r5, #0
 *   @0x294c9c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x294ca0 ldr r3, [r4]
 *   @0x294ca4 mov r1, r5
 *   @0x294ca8 mov r2, r6
 *   @0x294cac mov r0, r4
 *   @0x294cb0 ldr r3, [r3, #0x2a8]
 *   @0x294cb4 blx r3
 *   @0x294cb8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §69/281 yySocket::WaitForData(int, int)  0x2962b0  size 112  28 条（0x2962b0..0x296320）
 * @func 0x2962b0 0x296320  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time×3 / yySocket::ReadDataStream(int) / PollServersOnly()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2962b0 push {r4, r5, r6, r8, r9, r10, r11, lr}
 *   @0x2962b4 mov r4, r1
 *   @0x2962b8 mov r11, r0
 *   @0x2962bc mov r10, r2
 *   @0x2962c0 bl 0x215148 <Timing_Time>
 *   @0x2962c4 mov r6, #1000
 *   @0x2962c8 mul r6, r6, r4
 *   @0x2962cc asr r5, r6, #31
 *   @0x2962d0 mov r4, r6
 *   @0x2962d4 mov r8, r0
 *   @0x2962d8 mov r9, r1
 *   @0x2962dc mov r0, r11
 *   @0x2962e0 mov r1, r10
 *   @0x2962e4 bl 0x2960b4 <_ZN8yySocket14ReadDataStreamEi>
 *   @0x2962e8 subs r6, r0, #0
 *   @0x2962ec beq 0x2962fc <_ZN8yySocket11WaitForDataEii+0x4c>
 *   @0x2962f0 bl 0x215148 <Timing_Time>
 *   @0x2962f4 mov r0, r6
 *   @0x2962f8 pop {r4, r5, r6, r8, r9, r10, r11, pc}
 *   @0x2962fc bl 0x298db4 <_Z15PollServersOnlyv>
 *   @0x296300 bl 0x215148 <Timing_Time>
 *   @0x296304 subs r0, r0, r8
 *   @0x296308 sbc r1, r1, r9
 *   @0x29630c cmp r4, r0
 *   @0x296310 sbcs r3, r5, r1
 *   @0x296314 bge 0x2962dc <_ZN8yySocket11WaitForDataEii+0x2c>
 *   @0x296318 mov r0, r6
 *   @0x29631c pop {r4, r5, r6, r8, r9, r10, r11, pc}
 *
 * ══ §70/281 png_write_tEXt  0x2b1f94  size 112  28 条（0x2b1f94..0x2b2004）
 * @func 0x2b1f94 0x2b2004  size 112  28 条
 * 部分覆盖: 本节 28/51 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_chunk_data×2 / png_check_keyword / 0xb6538 / png_write_tEXt
 * 字段偏移 top8: 0x4×2 / 0x68×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1f94 ldr r3, [pc, #0x68]
 *   @0x2b1f98 add r3, pc
 *   @0x2b1f9c sub sp, #0x14
 *   @0x2b1fa0 ldrmi r0, [r5], -r9, asr #30
 *   @0x2b1fa4 add r2, sp, #0x4
 *   @0x2b1fa8 str r0, [sp, #0x8]
 *   @0x2b1fac strb.w r3, [sp, #0xc]
 *   @0x2b1fb0 bl 0x2af5b0 <png_check_keyword>
 *   @0x2b1fb4 mov r7, r0
 *   @0x2b1fb8 cbz r5, 0x2b1fc8 <png_write_tEXt+0x34>
 *   @0x2b1fbc cbz r6, 0x2b1fca <png_write_tEXt+0x36>
 *   @0x2b1fc0 blx 0xb6538 <strlen@plt>
 *   @0x2b1fc4 mov r6, r0
 *   @0x2b1fc8 mov r6, r5
 *   @0x2b1fcc mov r0, r4
 *   @0x2b1fd0 adds r2, r6, r7
 *   @0x2b1fd4 strtmi pc, [r0], -r5, ror #17
 *   @0x2b1fd8 ldr r1, [sp, #0x4]
 *   @0x2b1fdc bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b1fe0 cbz r6, 0x2b1fec <png_write_tEXt+0x58>
 *   @0x2b1fe4 mov r1, r5
 *   @0x2b1fe8 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b1fec mov r0, r4
 *   @0x2b1ff0 qsaxmi pc, r0, r2
 *   @0x2b1ff4 ldr r1, [sp, #0x4]
 *   @0x2b1ff8 andlt pc, r5, r1, lsl #29
 *   @0x2b1ffc pop {r4, r5, r6, r7, pc}
 *   @0x2b2000 ble 0x2b1f94 <png_write_tEXt>
 *
 * ══ §71/281 jpeg_start_output  0x2b3780  size 112  28 条（0x2b3780..0x2b37f0）
 * @func 0x2b3780 0x2b37f0  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×2 / 0x190×1 / 0x11×1 / 0x7c×1 / 0x84×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b3780 push {r3, r4, r5, lr}
 *   @0x2b3784 mov r4, r0
 *   @0x2b3788 ldr r3, [r0, #0x14]
 *   @0x2b378c mov r5, r1
 *   @0x2b3790 cmp r3, #204
 *   @0x2b3794 cmpne r3, #207
 *   @0x2b3798 bne 0x2b37d0 <jpeg_start_output+0x50>
 *   @0x2b379c ldr r3, [r4, #0x190]
 *   @0x2b37a0 cmp r5, #1
 *   @0x2b37a4 movlt r5, #1
 *   @0x2b37a8 ldrb r3, [r3, #0x11]
 *   @0x2b37ac cmp r3, #0
 *   @0x2b37b0 beq 0x2b37c0 <jpeg_start_output+0x40>
 *   @0x2b37b4 ldr r3, [r4, #0x7c]
 *   @0x2b37b8 cmp r5, r3
 *   @0x2b37bc movge r5, r3
 *   @0x2b37c0 str r5, [r4, #0x84]
 *   @0x2b37c4 mov r0, r4
 *   @0x2b37c8 pop {r3, r4, r5, lr}
 *   @0x2b37cc b 0x2b33a4 <jpeg_finish_decompress+0xe4>
 *   @0x2b37d0 ldr r2, [r0]
 *   @0x2b37d4 mov r1, #20
 *   @0x2b37d8 str r3, [r2, #0x18]
 *   @0x2b37dc ldr r3, [r0]
 *   @0x2b37e0 str r1, [r2, #0x14]
 *   @0x2b37e4 ldr r3, [r3]
 *   @0x2b37e8 blx r3
 *   @0x2b37ec b 0x2b379c <jpeg_start_output+0x1c>
 *
 * ══ §72/281 b2CircleShape::Clone(b2BlockAllocator*) const  0x2c4e9c  size 112  28 条（0x2c4e9c..0x2c4f0c）
 * @func 0x2c4e9c 0x2c4f0c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int)
 * 字段偏移 top8: 0x8×3 / 0x4×3 / 0x48×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4e9c push {r4, lr}
 *   @0x2c4ea0 mov r4, r0
 *   @0x2c4ea4 mov r0, r1
 *   @0x2c4ea8 mov r1, #20
 *   @0x2c4eac bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2c4eb0 subs r3, r0, #0
 *   @0x2c4eb4 beq 0x2c4ee0 <_ZNK13b2CircleShape5CloneEP16b2BlockAllocator+0x44>
 *   @0x2c4eb8 ldr r2, [pc, #0x48]
 *   @0x2c4ebc mov r1, #0
 *   @0x2c4ec0 mov r0, #0
 *   @0x2c4ec4 str r1, [r3, #0x8]
 *   @0x2c4ec8 ldr r2, [pc, r2]
 *   @0x2c4ecc str r0, [r3, #0x4]
 *   @0x2c4ed0 add r2, r2, #8
 *   @0x2c4ed4 str r1, [r3, #0xc]
 *   @0x2c4ed8 str r2, [r3]
 *   @0x2c4edc str r1, [r3, #0x10]
 *   @0x2c4ee0 add r1, r4, #12
 *   @0x2c4ee4 ldr r12, [r4, #0x4]
 *   @0x2c4ee8 ldr r4, [r4, #0x8]
 *   @0x2c4eec add r2, r3, #12
 *   @0x2c4ef0 ldm r1, {r0, r1}
 *   @0x2c4ef4 str r12, [r3, #0x4]
 *   @0x2c4ef8 str r4, [r3, #0x8]
 *   @0x2c4efc stm r2, {r0, r1}
 *   @0x2c4f00 mov r0, r3
 *   @0x2c4f04 pop {r4, pc}
 *   @0x2c4f08 andseq r12, r2, r4, ror #11
 *
 * ══ §73/281 b2World::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const  0x2cbd48  size 112  28 条（0x2cbd48..0x2cbdb8）
 * @func 0x2cbd48 0x2cbdb8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: void b2DynamicTree::RayCast<b2WorldRayCastWrapper>(b2WorldRayCastWrapper*, b2RayCastInput const&) const / b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const
 * 字段偏移 top8: 0x4×1 / 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cbd48 push {r4, r5, r6, r7, lr}
 *   @0x2cbd4c mov r6, r1
 *   @0x2cbd50 sub sp, sp, #36
 *   @0x2cbd54 add r7, r0, #102400
 *   @0x2cbd58 ldm r2, {r0, r1}
 *   @0x2cbd5c mov r5, r3
 *   @0x2cbd60 add r3, sp, #12
 *   @0x2cbd64 add r12, r7, #472
 *   @0x2cbd68 mov r4, r2
 *   @0x2cbd6c mov lr, #1065353216
 *   @0x2cbd70 stm r3, {r0, r1}
 *   @0x2cbd74 mov r2, r3
 *   @0x2cbd78 ldm r5, {r0, r1}
 *   @0x2cbd7c add r3, sp, #20
 *   @0x2cbd80 str r12, [sp, #0x4]
 *   @0x2cbd84 str lr, [sp, #0x1c]
 *   @0x2cbd88 stm r3, {r0, r1}
 *   @0x2cbd8c mov r0, r12
 *   @0x2cbd90 add r1, sp, #4
 *   @0x2cbd94 str r6, [sp, #0x8]
 *   @0x2cbd98 bl 0x2cb8e0 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput>
 *   @0x2cbd9c add r0, r7, #628
 *   @0x2cbda0 mov r1, r6
 *   @0x2cbda4 mov r2, r4
 *   @0x2cbda8 mov r3, r5
 *   @0x2cbdac bl 0x2d9c4c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_>
 *   @0x2cbdb0 add sp, sp, #36
 *   @0x2cbdb4 pop {r4, r5, r6, r7, pc}
 *
 * ══ §74/281 b2DynamicTree::ShiftOrigin(b2Vec2 const&)  0x2dfc84  size 112  28 条（0x2dfc84..0x2dfcf4）
 * @func 0x2dfc84 0x2dfcf4  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dfc84 ldr r2, [r0, #0xc]
 *   @0x2dfc88 cmp r2, #0
 *   @0x2dfc8c bxle lr
 *   @0x2dfc90 ldr r3, [r0, #0x4]
 *   @0x2dfc94 add r0, r2, r2, lsl #3
 *   @0x2dfc98 add r2, r3, #8
 *   @0x2dfc9c add r0, r3, r0, lsl #2
 *   @0x2dfca0 vldr s14, [r3]
 *   @0x2dfca4 vldr s15, [r1]
 *   @0x2dfca8 vsub.f32 s15, s14, s15
 *   @0x2dfcac vldr s14, [r3, #4]
 *   @0x2dfcb0 add r3, r3, #36
 *   @0x2dfcb4 add r2, r2, #36
 *   @0x2dfcb8 vstr s15, [r3, #-36]
 *   @0x2dfcbc vldr s15, [r1, #4]
 *   @0x2dfcc0 vsub.f32 s15, s14, s15
 *   @0x2dfcc4 vstr s15, [r3, #-32]
 *   @0x2dfcc8 vldr s14, [r2, #-36]
 *   @0x2dfccc vldr s15, [r1]
 *   @0x2dfcd0 vsub.f32 s15, s14, s15
 *   @0x2dfcd4 vldr s14, [r2, #-32]
 *   @0x2dfcd8 cmp r3, r0
 *   @0x2dfcdc vstr s15, [r2, #-36]
 *   @0x2dfce0 vldr s15, [r1, #4]
 *   @0x2dfce4 vsub.f32 s15, s14, s15
 *   @0x2dfce8 vstr s15, [r2, #-32]
 *   @0x2dfcec bne 0x2dfca0 <_ZN13b2DynamicTree11ShiftOriginERK6b2Vec2+0x1c>
 *   @0x2dfcf0 bx lr
 *
 * ══ §75/281 FT_Stream_Open  0x2e9bd4  size 112  28 条（0x2e9bd4..0x2e9c44）
 * @func 0x2e9bd4 0x2e9c44  size 112  28 条
 * 部分覆盖: 本节 28/51 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844 / 0xb68d4 / 0xb6850 / 0x4e5594
 * 字段偏移 top8: 0xc×2 / 0x18×2 / 0x8×1 / 0x48×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9bd4 push {r4, r5, r6, lr}
 *   @0x2e9bd8 cmp r0, #0x0
 *   @0x2e9bdc movs r5, #0x0
 *   @0x2e9be0 str r5, [r0, #0xc]
 *   @0x2e9be4 str r5, [r0, #0x8]
 *   @0x2e9be8 str r5, [r0, #0x18]
 *   @0x2e9bec ldr r1, [pc, #0x48]
 *   @0x2e9bf0 blx 0xb6844 <fopen@plt>
 *   @0x2e9bf4 mov r6, r0
 *   @0x2e9bf8 mov r1, r5
 *   @0x2e9bfc blx 0xb68d4 <fseek@plt>
 *   @0x2e9c00 mov r0, r6
 *   @0x2e9c04 rsbvs lr, r0, lr, ror #28
 *   @0x2e9c08 cbnz r0, 0x2e9c14 <FT_Stream_Open+0x40>
 *   @0x2e9c0c blx 0xb6850 <fclose@plt>
 *   @0x2e9c10 movs r0, #0x51
 *   @0x2e9c14 mov r0, r6
 *   @0x2e9c18 mov r2, r5
 *   @0x2e9c1c blmi 0x4e5594 <SrcVerts+0x425d8>
 *   @0x2e9c20 str r6, [r4, #0xc]
 *   @0x2e9c24 add r3, pc
 *   @0x2e9c28 ldr r3, [pc, #0x14]
 *   @0x2e9c2c str r3, [r4, #0x18]
 *   @0x2e9c30 movs r0, #0x28
 *   @0x2e9c34 movs r0, #0x1
 *   @0x2e9c38 movs r4, #0xd
 *   @0x2e9c3c .word 0xff67 ffff
 *   @0x2e9c40 .word 0xff4d ffff
 *
 * ══ §76/281 zip_fclose  0x2a4388  size 110  28 条（0x2a4388..0x2a43f6）
 * @func 0x2a4388 0x2a43f8  size 112  28 条
 * 部分覆盖: 本节 28/49 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb69e8 / 0xade728 / 0xb655c
 * 字段偏移 top8: 0x30×1 / 0x2c×1 / 0x38×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4388 push {r4, r5, r6, lr}
 *   @0x2a438c ldr r0, [r0, #0x30]
 *   @0x2a4390 blx 0xb69e8 <inflateEnd@plt>
 *   @0x2a4394 ldr r0, [r4, #0x2c]
 *   @0x2a4398 blvs 0xade728 <b2_toiTime+0x385284>
 *   @0x2a439c blx 0xb655c <free@plt>
 *   @0x2a43a0 ldr r0, [r4]
 *   @0x2a43a4 ldr r1, [r0, #0x38]
 *   @0x2a43a8 bge 0x2a43d2 <zip_fclose+0x4a>
 *   @0x2a43ac add.w r6, r2, r3, lsl #2
 *   @0x2a43b0 ldr.w r5, [r2, r3, lsl #2]
 *   @0x2a43b4 cmp r5, r4
 *   @0x2a43b8 add.w r3, r1, #0x40000000
 *   @0x2a43bc subs r3, #0x1
 *   @0x2a43c0 eorsvs r3, r3, r3, lsr #32
 *   @0x2a43c4 ldr r3, [r4]
 *   @0x2a43c8 subs r2, #0x1
 *   @0x2a43cc b 0x2a43d2 <zip_fclose+0x4a>
 *   @0x2a43d0 b 0x2a43a6 <zip_fclose+0x1e>
 *   @0x2a43d4 cbnz r5, 0x2a43ec <zip_fclose+0x64>
 *   @0x2a43d8 and r3, r3, #0x5
 *   @0x2a43dc cmp r3, #0x5
 *   @0x2a43e0 ldr r5, [r4, #0x28]
 *   @0x2a43e4 cmp r5, r3
 *   @0x2a43e8 movne r5, #0x7
 *   @0x2a43ec mov r0, r4
 *   @0x2a43f0 .word 0x4628e8b6
 *   @0x2a43f4 pop {r4, r5, r6, pc}
 *
 * ══ §77/281 FT_Matrix_Multiply  0x2e4f0e  size 110  28 条（0x2e4f0e..0x2e4f7c）
 * @func 0x2e4f0e 0x2e4f7e  size 112  28 条
 * 部分覆盖: 本节 28/51 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_MulFix×4
 * 字段偏移 top8: 0xc×5 / 0x8×3 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4f0e push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e4f12 mov r4, r1
 *   @0x2e4f16 cmp r0, #0x0
 *   @0x2e4f1a cmp r1, #0x0
 *   @0x2e4f1e ldr r1, [r1]
 *   @0x2e4f22 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f26 ldr r1, [r4, #0x8]
 *   @0x2e4f2a ldr r0, [r5, #0x4]
 *   @0x2e4f2e stmdavs r1!, {r1, r2, r3, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2e4f32 add r8, r0
 *   @0x2e4f36 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f3a ldr r1, [r4, #0xc]
 *   @0x2e4f3e ldr r0, [r5, #0x4]
 *   @0x2e4f42 stmdavs r1!, {r2, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e4f46 add r7, r0
 *   @0x2e4f4a bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f4e ldr r1, [r4, #0x8]
 *   @0x2e4f52 ldr r0, [r5, #0xc]
 *   @0x2e4f56 stmdavs r1!, {r1, r3, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2e4f5a add r6, r0
 *   @0x2e4f5e bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f62 ldr r1, [r4, #0xc]
 *   @0x2e4f66 ldr r0, [r5, #0xc]
 *   @0x2e4f6a .word 0xf8c4ff70
 *   @0x2e4f6e rsbvs r8, r7, r0
 *   @0x2e4f72 str r6, [r4, #0x8]
 *   @0x2e4f76 str r0, [r4, #0xc]
 *   @0x2e4f7a ldrblt r8, [r0, #-0x3f8]!
 *
 * ══ §78/281 ASYNC_SAVE_LOAD_REQ_CONTEXT::~ASYNC_SAVE_LOAD_REQ_CONTEXT()  0xc4d60  size 108  27 条（0xc4d60..0xc4dcc）
 * @func 0xc4d60 0xc4dcc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT()
 * 字段偏移 top8: 0x44×2 / 0x48×2 / 0x54×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4d60 push {r4, r5, r6, lr}
 *   @0xc4d64 mov r6, r0
 *   @0xc4d68 ldr r4, [r0, #0x44]
 *   @0xc4d6c ldr r3, [pc, #0x54]
 *   @0xc4d70 cmp r4, #0
 *   @0xc4d74 ldr r3, [pc, r3]
 *   @0xc4d78 add r3, r3, #8
 *   @0xc4d7c str r3, [r0]
 *   @0xc4d80 beq 0xc4da4 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXTD2Ev+0x44>
 *   @0xc4d84 ldr r5, [r4]
 *   @0xc4d88 ldr r0, [r4, #0x8]
 *   @0xc4d8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc4d90 ldr r0, [r4, #0xc]
 *   @0xc4d94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc4d98 cmp r5, #0
 *   @0xc4d9c mov r4, r5
 *   @0xc4da0 bne 0xc4d84 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXTD2Ev+0x24>
 *   @0xc4da4 ldr r0, [r6, #0x48]
 *   @0xc4da8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc4dac mov r3, #0
 *   @0xc4db0 mov r0, r6
 *   @0xc4db4 str r3, [r6, #0x44]
 *   @0xc4db8 str r3, [r6, #0x48]
 *   @0xc4dbc bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev>
 *   @0xc4dc0 mov r0, r6
 *   @0xc4dc4 pop {r4, r5, r6, pc}
 *   @0xc4dc8 eorseq r8, r2, r0, asr #24
 *
 * ══ §79/281 InvalidateFrozenVBs()  0xc8fe8  size 108  27 条（0xc8fe8..0xc9054）
 * @func 0xc8fe8 0xc9054  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VertexBuffer::~VertexBuffer() / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x30×2 / 0x5c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8fe8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xc8fec ldr r7, [pc, #0x5c]
 *   @0xc8ff0 add r7, pc, r7
 *   @0xc8ff4 ldr r3, [r7, #0x4]
 *   @0xc8ff8 cmp r3, #0
 *   @0xc8ffc pople {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc9000 mov r4, #0
 *   @0xc9004 mov r8, r7
 *   @0xc9008 mov r9, r4
 *   @0xc900c ldr r3, [r7]
 *   @0xc9010 ldr r5, [r3, r4, lsl #2]
 *   @0xc9014 add r4, r4, #1
 *   @0xc9018 cmp r5, #0
 *   @0xc901c beq 0xc9040 <_Z19InvalidateFrozenVBsv+0x58>
 *   @0xc9020 ldr r6, [r5, #0x30]
 *   @0xc9024 cmp r6, #0
 *   @0xc9028 mov r0, r6
 *   @0xc902c beq 0xc9040 <_Z19InvalidateFrozenVBsv+0x58>
 *   @0xc9030 bl 0x18373c <_ZN12VertexBufferD2Ev>
 *   @0xc9034 mov r0, r6
 *   @0xc9038 bl 0x27d1d0 <_ZdlPv>
 *   @0xc903c str r9, [r5, #0x30]
 *   @0xc9040 ldr r3, [r8, #0x4]
 *   @0xc9044 cmp r3, r4
 *   @0xc9048 bgt 0xc900c <_Z19InvalidateFrozenVBsv+0x24>
 *   @0xc904c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc9050 eorseq r1, r11, r4, asr #2
 *
 * ══ §80/281 Function_Replace(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*))  0xce070  size 108  27 条（0xce070..0xce0dc）
 * @func 0xce070 0xce0dc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 0x40×2 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce070 ldr r3, [pc, #0x5c]
 *   @0xce074 push {r4, r5, r6, r7, r8, lr}
 *   @0xce078 ldr r3, [pc, r3]
 *   @0xce07c mov r7, r0
 *   @0xce080 mov r8, r1
 *   @0xce084 ldr r6, [r3]
 *   @0xce088 cmp r6, #0
 *   @0xce08c pople {r4, r5, r6, r7, r8, pc}
 *   @0xce090 ldr r3, [pc, #0x40]
 *   @0xce094 mov r5, #0
 *   @0xce098 ldr r3, [pc, r3]
 *   @0xce09c ldr r4, [r3]
 *   @0xce0a0 b 0xce0b0 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E+0x40>
 *   @0xce0a4 cmp r5, r6
 *   @0xce0a8 add r4, r4, #80
 *   @0xce0ac beq 0xce0d0 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E+0x60>
 *   @0xce0b0 mov r0, r4
 *   @0xce0b4 mov r1, r7
 *   @0xce0b8 bl 0xb6574 <strcmp@plt>
 *   @0xce0bc add r5, r5, #1
 *   @0xce0c0 cmp r0, #0
 *   @0xce0c4 bne 0xce0a4 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E+0x34>
 *   @0xce0c8 str r8, [r4, #0x40]
 *   @0xce0cc pop {r4, r5, r6, r7, r8, pc}
 *   @0xce0d0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xce0d4 mlaseq r1, r12, r10, pc
 *   @0xce0d8 eorseq pc, r1, r0, lsl #21
 *
 * ══ §81/281 YYGML_CallScriptFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**)  0xd7c34  size 108  27 条（0xd7c34..0xd7ca0）
 * @func 0xd7c34 0xd7ca0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Script_Data(int) / YYGML_CallScriptFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**)+0x60
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x20×1 / 0x10×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd7c34 push {r4, r5, r6, r7, lr}
 *   @0xd7c38 sub sp, sp, #12
 *   @0xd7c3c mov r5, r0
 *   @0xd7c40 mov r4, r2
 *   @0xd7c44 ldr r0, [sp, #0x20]
 *   @0xd7c48 mov r7, r1
 *   @0xd7c4c mov r6, r3
 *   @0xd7c50 bl 0x1e069c <_Z11Script_Datai>
 *   @0xd7c54 mov r2, #0
 *   @0xd7c58 str r2, [r4, #0xc]
 *   @0xd7c5c str r2, [r4]
 *   @0xd7c60 str r2, [r4, #0x4]
 *   @0xd7c64 ldr r2, [r0, #0x10]
 *   @0xd7c68 cmp r2, #0
 *   @0xd7c6c blt 0xd7c94 <_Z24YYGML_CallScriptFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x60>
 *   @0xd7c70 ldr r12, [r0, #0xc]
 *   @0xd7c74 mov r1, r7
 *   @0xd7c78 ldr r3, [sp, #0x24]
 *   @0xd7c7c mov r0, r5
 *   @0xd7c80 mov r2, r4
 *   @0xd7c84 str r3, [sp]
 *   @0xd7c88 mov r3, r6
 *   @0xd7c8c ldr r12, [r12, #0x4]
 *   @0xd7c90 blx r12
 *   @0xd7c94 mov r0, r4
 *   @0xd7c98 add sp, sp, #12
 *   @0xd7c9c pop {r4, r5, r6, r7, pc}
 *
 * ══ §82/281 FINALIZE_Event_Action()  0xf2c9c  size 108  27 条（0xf2c9c..0xf2d08）
 * @func 0xf2c9c 0xf2d08  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x2×2 / 0x58×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c9c push {r3, r4, r5, r6, r7, lr}
 *   @0xf2ca0 ldr r5, [pc, #0x58]
 *   @0xf2ca4 ldr r5, [pc, r5]
 *   @0xf2ca8 ldr r3, [r5]
 *   @0xf2cac cmp r3, #0
 *   @0xf2cb0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0xf2cb4 ldr r6, [pc, #0x48]
 *   @0xf2cb8 ldr r6, [pc, r6]
 *   @0xf2cbc ldr r2, [r6]
 *   @0xf2cc0 cmp r2, #0
 *   @0xf2cc4 pople {r3, r4, r5, r6, r7, pc}
 *   @0xf2cc8 mov r4, #0
 *   @0xf2ccc mov r7, r4
 *   @0xf2cd0 ldr r0, [r3, r4, lsl #2]
 *   @0xf2cd4 cmp r0, #0
 *   @0xf2cd8 beq 0xf2ce8 <_Z21FINALIZE_Event_Actionv+0x4c>
 *   @0xf2cdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf2ce0 ldr r3, [r5]
 *   @0xf2ce4 str r7, [r3, r4, lsl #2]
 *   @0xf2ce8 ldr r3, [r6]
 *   @0xf2cec add r4, r4, #1
 *   @0xf2cf0 cmp r3, r4
 *   @0xf2cf4 pople {r3, r4, r5, r6, r7, pc}
 *   @0xf2cf8 ldr r3, [r5]
 *   @0xf2cfc b 0xf2cd0 <_Z21FINALIZE_Event_Actionv+0x34>
 *   @0xf2d00 eoreq r11, pc, r4, ror r1
 *   @0xf2d04 eoreq r11, pc, r4, ror #2
 *
 * ══ §83/281 CExtensionFunction::~CExtensionFunction()  0xf476c  size 108  27 条（0xf476c..0xf47d8）
 * @func 0xf476c 0xf47d8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x5c×2 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf476c push {r4, lr}
 *   @0xf4770 mov r4, r0
 *   @0xf4774 ldr r0, [r0, #0x4]
 *   @0xf4778 ldr r3, [pc, #0x54]
 *   @0xf477c cmp r0, #0
 *   @0xf4780 ldr r3, [pc, r3]
 *   @0xf4784 add r3, r3, #8
 *   @0xf4788 str r3, [r4]
 *   @0xf478c beq 0xf479c <_ZN18CExtensionFunctionD2Ev+0x30>
 *   @0xf4790 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf4794 mov r3, #0
 *   @0xf4798 str r3, [r4, #0x4]
 *   @0xf479c ldr r0, [r4, #0x8]
 *   @0xf47a0 cmp r0, #0
 *   @0xf47a4 beq 0xf47b4 <_ZN18CExtensionFunctionD2Ev+0x48>
 *   @0xf47a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf47ac mov r3, #0
 *   @0xf47b0 str r3, [r4, #0x8]
 *   @0xf47b4 ldr r0, [r4, #0x5c]
 *   @0xf47b8 cmp r0, #0
 *   @0xf47bc beq 0xf47cc <_ZN18CExtensionFunctionD2Ev+0x60>
 *   @0xf47c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf47c4 mov r3, #0
 *   @0xf47c8 str r3, [r4, #0x5c]
 *   @0xf47cc mov r0, r4
 *   @0xf47d0 pop {r4, pc}
 *   @0xf47d4 eoreq r9, pc, r8, lsr #13
 *
 * ══ §84/281 CExtensionFile::~CExtensionFile()  0xf50e4  size 108  27 条（0xf50e4..0xf5150）
 * @func 0xf50e4 0xf5150  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×5 / CExtensionFile::Clear()
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x10×2 / 0x18×2 / 0x24×2 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf50e4 push {r3, r4, r5, lr}
 *   @0xf50e8 mov r4, r0
 *   @0xf50ec ldr r3, [pc, #0x58]
 *   @0xf50f0 mov r5, #0
 *   @0xf50f4 ldr r0, [r0, #0x4]
 *   @0xf50f8 ldr r3, [pc, r3]
 *   @0xf50fc add r3, r3, #8
 *   @0xf5100 str r3, [r4]
 *   @0xf5104 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5108 ldr r0, [r4, #0xc]
 *   @0xf510c str r5, [r4, #0x4]
 *   @0xf5110 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5114 ldr r0, [r4, #0x10]
 *   @0xf5118 str r5, [r4, #0xc]
 *   @0xf511c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5120 mov r0, r4
 *   @0xf5124 str r5, [r4, #0x10]
 *   @0xf5128 bl 0xf5064 <_ZN14CExtensionFile5ClearEv>
 *   @0xf512c ldr r0, [r4, #0x18]
 *   @0xf5130 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5134 ldr r0, [r4, #0x24]
 *   @0xf5138 str r5, [r4, #0x18]
 *   @0xf513c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5140 str r5, [r4, #0x24]
 *   @0xf5144 mov r0, r4
 *   @0xf5148 pop {r3, r4, r5, pc}
 *   @0xf514c eoreq r8, pc, r4, lsr sp
 *
 * ══ §85/281 F_DsStackClear(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb9e4  size 108  27 条（0xfb9e4..0xfba50）
 * @func 0xfb9e4 0xfba50  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsStackClear(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb9e4 push {r3, lr}
 *   @0xfb9e8 mov r1, #0
 *   @0xfb9ec ldr r0, [sp, #0x8]
 *   @0xfb9f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfb9f4 cmp r0, #0
 *   @0xfb9f8 blt 0xfba30 <_Z14F_DsStackClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfb9fc ldr r3, [pc, #0x40]
 *   @0xfba00 ldr r3, [pc, r3]
 *   @0xfba04 ldr r3, [r3]
 *   @0xfba08 cmp r0, r3
 *   @0xfba0c bge 0xfba30 <_Z14F_DsStackClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfba10 ldr r3, [pc, #0x30]
 *   @0xfba14 ldr r3, [pc, r3]
 *   @0xfba18 ldr r3, [r3, #0x4]
 *   @0xfba1c ldr r0, [r3, r0, lsl #2]
 *   @0xfba20 cmp r0, #0
 *   @0xfba24 beq 0xfba30 <_Z14F_DsStackClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfba28 pop {r3, lr}
 *   @0xfba2c b 0x20f270 <_ZN9CDS_Stack5ClearEv>
 *   @0xfba30 ldr r0, [pc, #0x14]
 *   @0xfba34 mov r1, #0
 *   @0xfba38 pop {r3, lr}
 *   @0xfba3c add r0, pc, r0
 *   @0xfba40 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfba44 eoreq r2, pc, r12, ror r4
 *   @0xfba48 eoreq r2, pc, r12, ror #8
 *   @0xfba4c eoreq r12, r3, r0, asr #3
 *
 * ══ §86/281 F_DsListClear(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc240  size 108  27 条（0xfc240..0xfc2ac）
 * @func 0xfc240 0xfc2ac  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsListClear(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc240 push {r3, lr}
 *   @0xfc244 mov r1, #0
 *   @0xfc248 ldr r0, [sp, #0x8]
 *   @0xfc24c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc250 cmp r0, #0
 *   @0xfc254 blt 0xfc28c <_Z13F_DsListClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfc258 ldr r3, [pc, #0x40]
 *   @0xfc25c ldr r3, [pc, r3]
 *   @0xfc260 ldr r3, [r3]
 *   @0xfc264 cmp r0, r3
 *   @0xfc268 bge 0xfc28c <_Z13F_DsListClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfc26c ldr r3, [pc, #0x30]
 *   @0xfc270 ldr r3, [pc, r3]
 *   @0xfc274 ldr r3, [r3, #0x4]
 *   @0xfc278 ldr r0, [r3, r0, lsl #2]
 *   @0xfc27c cmp r0, #0
 *   @0xfc280 beq 0xfc28c <_Z13F_DsListClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfc284 pop {r3, lr}
 *   @0xfc288 b 0x20e478 <_ZN8CDS_List5ClearEv>
 *   @0xfc28c ldr r0, [pc, #0x14]
 *   @0xfc290 mov r1, #0
 *   @0xfc294 pop {r3, lr}
 *   @0xfc298 add r0, pc, r0
 *   @0xfc29c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc2a0 eoreq r1, pc, r0, lsr #20
 *   @0xfc2a4 eoreq r1, pc, r0, lsl r10
 *   @0xfc2a8 eoreq r11, r3, r4, ror #18
 *
 * ══ §87/281 F_DsListShuffle(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc8e8  size 108  27 条（0xfc8e8..0xfc954）
 * @func 0xfc8e8 0xfc954  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsListShuffle(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc8e8 push {r3, lr}
 *   @0xfc8ec mov r1, #0
 *   @0xfc8f0 ldr r0, [sp, #0x8]
 *   @0xfc8f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc8f8 cmp r0, #0
 *   @0xfc8fc blt 0xfc934 <_Z15F_DsListShuffleR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfc900 ldr r3, [pc, #0x40]
 *   @0xfc904 ldr r3, [pc, r3]
 *   @0xfc908 ldr r3, [r3]
 *   @0xfc90c cmp r0, r3
 *   @0xfc910 bge 0xfc934 <_Z15F_DsListShuffleR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfc914 ldr r3, [pc, #0x30]
 *   @0xfc918 ldr r3, [pc, r3]
 *   @0xfc91c ldr r3, [r3, #0x4]
 *   @0xfc920 ldr r0, [r3, r0, lsl #2]
 *   @0xfc924 cmp r0, #0
 *   @0xfc928 beq 0xfc934 <_Z15F_DsListShuffleR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfc92c pop {r3, lr}
 *   @0xfc930 b 0x203360 <_ZN8CDS_List7ShuffleEv>
 *   @0xfc934 ldr r0, [pc, #0x14]
 *   @0xfc938 mov r1, #0
 *   @0xfc93c pop {r3, lr}
 *   @0xfc940 add r0, pc, r0
 *   @0xfc944 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc948 eoreq r1, pc, r8, ror r3
 *   @0xfc94c eoreq r1, pc, r8, ror #6
 *   @0xfc950 .word 0x0023b2bc
 *
 * ══ §88/281 F_DsPriorityClear(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcab0  size 108  27 条（0xfcab0..0xfcb1c）
 * @func 0xfcab0 0xfcb1c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityClear(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcab0 push {r3, lr}
 *   @0xfcab4 mov r1, #0
 *   @0xfcab8 ldr r0, [sp, #0x8]
 *   @0xfcabc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcac0 cmp r0, #0
 *   @0xfcac4 blt 0xfcafc <_Z17F_DsPriorityClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfcac8 ldr r3, [pc, #0x40]
 *   @0xfcacc ldr r3, [pc, r3]
 *   @0xfcad0 ldr r3, [r3]
 *   @0xfcad4 cmp r0, r3
 *   @0xfcad8 bge 0xfcafc <_Z17F_DsPriorityClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfcadc ldr r3, [pc, #0x30]
 *   @0xfcae0 ldr r3, [pc, r3]
 *   @0xfcae4 ldr r3, [r3, #0x4]
 *   @0xfcae8 ldr r0, [r3, r0, lsl #2]
 *   @0xfcaec cmp r0, #0
 *   @0xfcaf0 beq 0xfcafc <_Z17F_DsPriorityClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfcaf4 pop {r3, lr}
 *   @0xfcaf8 b 0x209768 <_ZN12CDS_Priority5ClearEv>
 *   @0xfcafc ldr r0, [pc, #0x14]
 *   @0xfcb00 mov r1, #0
 *   @0xfcb04 pop {r3, lr}
 *   @0xfcb08 add r0, pc, r0
 *   @0xfcb0c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfcb10 eoreq r1, pc, r8, lsr #7
 *   @0xfcb14 mlaeq pc, r8, r3, r1
 *   @0xfcb18 .word 0x0023b0f4
 *
 * ══ §89/281 F_DsGridShuffle(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe898  size 108  27 条（0xfe898..0xfe904）
 * @func 0xfe898 0xfe904  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsGridShuffle(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe898 push {r3, lr}
 *   @0xfe89c mov r1, #0
 *   @0xfe8a0 ldr r0, [sp, #0x8]
 *   @0xfe8a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe8a8 cmp r0, #0
 *   @0xfe8ac blt 0xfe8e4 <_Z15F_DsGridShuffleR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfe8b0 ldr r3, [pc, #0x40]
 *   @0xfe8b4 ldr r3, [pc, r3]
 *   @0xfe8b8 ldr r3, [r3]
 *   @0xfe8bc cmp r0, r3
 *   @0xfe8c0 bge 0xfe8e4 <_Z15F_DsGridShuffleR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfe8c4 ldr r3, [pc, #0x30]
 *   @0xfe8c8 ldr r3, [pc, r3]
 *   @0xfe8cc ldr r3, [r3, #0x4]
 *   @0xfe8d0 ldr r0, [r3, r0, lsl #2]
 *   @0xfe8d4 cmp r0, #0
 *   @0xfe8d8 beq 0xfe8e4 <_Z15F_DsGridShuffleR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfe8dc pop {r3, lr}
 *   @0xfe8e0 b 0x20cd98 <_ZN8CDS_Grid7ShuffleEv>
 *   @0xfe8e4 ldr r0, [pc, #0x14]
 *   @0xfe8e8 mov r1, #0
 *   @0xfe8ec pop {r3, lr}
 *   @0xfe8f0 add r0, pc, r0
 *   @0xfe8f4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe8f8 .word 0x002ef5d0
 *   @0xfe8fc eoreq pc, lr, r0, asr #11
 *   @0xfe900 eoreq r9, r3, r12, lsl #6
 *
 * ══ §90/281 dsListAddString  0x101d20  size 108  27 条（0x101d20..0x101d8c）
 * @func 0x101d20 0x101d8c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / F_DsListAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x8×1 / 0x34×1 / 0x20×1 / 0x30×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101d20 vmov s13, r0
 *   @0x101d24 mov r2, #0
 *   @0x101d28 push {r4, r5, lr}
 *   @0x101d2c vcvt.f64.s32 d7, s13
 *   @0x101d30 sub sp, sp, #60
 *   @0x101d34 mov r3, #0
 *   @0x101d38 add r5, sp, #56
 *   @0x101d3c mov r4, #0
 *   @0x101d40 strd r2, r3, [sp, #40]
 *   @0x101d44 add r0, sp, #40
 *   @0x101d48 mvn r12, #-16777216
 *   @0x101d4c str r4, [sp, #0x8]
 *   @0x101d50 str r12, [sp, #0x34]
 *   @0x101d54 str r4, [sp, #0x20]
 *   @0x101d58 vmov r2, r3, d7
 *   @0x101d5c str r4, [sp, #0x30]
 *   @0x101d60 str r4, [sp, #0x24]
 *   @0x101d64 strd r2, r3, [r5, #-32]!
 *   @0x101d68 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x101d6c mov r1, r4
 *   @0x101d70 str r5, [sp]
 *   @0x101d74 mov r2, r4
 *   @0x101d78 add r0, sp, #8
 *   @0x101d7c mov r3, #2
 *   @0x101d80 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_>
 *   @0x101d84 add sp, sp, #60
 *   @0x101d88 pop {r4, r5, pc}
 *
 * ══ §91/281 F_DateDaySpan(RValue&, CInstance*, CInstance*, int, RValue*)  0x115498  size 108  27 条（0x115498..0x115504）
 * @func 0x115498 0x115504  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115498 push {r3, r4, r5, lr}
 *   @0x11549c vpush {d8}
 *   @0x1154a0 mov r3, #0
 *   @0x1154a4 ldr r5, [sp, #0x18]
 *   @0x1154a8 mov r1, r3
 *   @0x1154ac str r3, [r0, #0xc]
 *   @0x1154b0 mov r4, r0
 *   @0x1154b4 str r3, [r0]
 *   @0x1154b8 str r3, [r0, #0x4]
 *   @0x1154bc mov r0, r5
 *   @0x1154c0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1154c4 vmov d8, r0, r1
 *   @0x1154c8 mov r0, r5
 *   @0x1154cc mov r1, #1
 *   @0x1154d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1154d4 vmov d7, r0, r1
 *   @0x1154d8 vcmpe.f64 d8, d7
 *   @0x1154dc vmrs APSR_nzcv, fpscr
 *   @0x1154e0 vmovpl.f64 d6, d7
 *   @0x1154e4 vmovpl.f64 d7, d8
 *   @0x1154e8 vmovpl.f64 d8, d6
 *   @0x1154ec vsub.f64 d8, d7, d8
 *   @0x1154f0 vabs.f64 d7, d8
 *   @0x1154f4 vmov r2, r3, d7
 *   @0x1154f8 stm r4, {r2, r3}
 *   @0x1154fc vpop {d8}
 *   @0x115500 pop {r3, r4, r5, pc}
 *
 * ══ §92/281 F_DateValidDate(RValue&, CInstance*, CInstance*, int, RValue*)  0x118054  size 108  27 条（0x118054..0x1180c0）
 * @func 0x118054 0x1180c0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / date_is_valid(int, int, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x118054 push {r4, r5, r6, r7, r8, lr}
 *   @0x118058 mov r4, #0
 *   @0x11805c ldr r6, [sp, #0x18]
 *   @0x118060 mov r5, r0
 *   @0x118064 str r4, [r0, #0xc]
 *   @0x118068 mov r1, r4
 *   @0x11806c str r4, [r0]
 *   @0x118070 str r4, [r0, #0x4]
 *   @0x118074 mov r0, r6
 *   @0x118078 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11807c mov r1, #1
 *   @0x118080 mov r7, r0
 *   @0x118084 mov r0, r6
 *   @0x118088 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11808c mov r1, #2
 *   @0x118090 mov r8, r0
 *   @0x118094 mov r0, r6
 *   @0x118098 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11809c mov r1, r8
 *   @0x1180a0 mov r2, r7
 *   @0x1180a4 bl 0x117eec <_Z13date_is_validiii>
 *   @0x1180a8 cmp r0, r4
 *   @0x1180ac strne r4, [r5]
 *   @0x1180b0 movne r3, r4
 *   @0x1180b4 movtne r3, #0x3ff0
 *   @0x1180b8 strne r3, [r5, #0x4]
 *   @0x1180bc pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §93/281 F_StringWidthExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11be38  size 108  27 条（0x11be38..0x11bea4）
 * @func 0x11be38 0x11beb4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / YYStrDup(char const*) / GR_Text_Width(char const*, int, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11be38 push {r3, r4, r5, r6, r7, lr}
 *   @0x11be3c mov r1, #0
 *   @0x11be40 ldr r5, [sp, #0x18]
 *   @0x11be44 mov r4, r0
 *   @0x11be48 str r1, [r0, #0xc]
 *   @0x11be4c mov r0, r5
 *   @0x11be50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11be54 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x11be58 mov r1, #1
 *   @0x11be5c mov r6, r0
 *   @0x11be60 mov r0, r5
 *   @0x11be64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11be68 mov r1, #2
 *   @0x11be6c mov r7, r0
 *   @0x11be70 mov r0, r5
 *   @0x11be74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11be78 mov r1, r7
 *   @0x11be7c mov r2, r0
 *   @0x11be80 mov r0, r6
 *   @0x11be84 bl 0x172bc8 <_Z13GR_Text_WidthPKcii>
 *   @0x11be88 vmov s15, r0
 *   @0x11be8c mov r0, r6
 *   @0x11be90 vcvt.f64.s32 d7, s15
 *   @0x11be94 vmov r2, r3, d7
 *   @0x11be98 stm r4, {r2, r3}
 *   @0x11be9c pop {r3, r4, r5, r6, r7, lr}
 *   @0x11bea0 b 0xcef90 <_Z6YYFreePKv>
 *
 * ══ §94/281 F_StringHeightExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bea4  size 108  27 条（0x11bea4..0x11bf10）
 * @func 0x11bea4 0x11bf10  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / YYStrDup(char const*) / GR_Text_Height(char const*, int, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bea4 push {r3, r4, r5, r6, r7, lr}
 *   @0x11bea8 mov r1, #0
 *   @0x11beac ldr r5, [sp, #0x18]
 *   @0x11beb0 mov r4, r0
 *   @0x11beb4 str r1, [r0, #0xc]
 *   @0x11beb8 mov r0, r5
 *   @0x11bebc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11bec0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x11bec4 mov r1, #1
 *   @0x11bec8 mov r6, r0
 *   @0x11becc mov r0, r5
 *   @0x11bed0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bed4 mov r1, #2
 *   @0x11bed8 mov r7, r0
 *   @0x11bedc mov r0, r5
 *   @0x11bee0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bee4 mov r1, r7
 *   @0x11bee8 mov r2, r0
 *   @0x11beec mov r0, r6
 *   @0x11bef0 bl 0x172d08 <_Z14GR_Text_HeightPKcii>
 *   @0x11bef4 vmov s15, r0
 *   @0x11bef8 mov r0, r6
 *   @0x11befc vcvt.f64.s32 d7, s15
 *   @0x11bf00 vmov r2, r3, d7
 *   @0x11bf04 stm r4, {r2, r3}
 *   @0x11bf08 pop {r3, r4, r5, r6, r7, lr}
 *   @0x11bf0c b 0xcef90 <_Z6YYFreePKv>
 *
 * ══ §95/281 F_SkeletonSetAnimation(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cafc  size 108  27 条（0x11cafc..0x11cb68）
 * @func 0x11cafc 0x11cb78  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / CSkeletonInstance::SelectAnimation(char const*)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x90×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cafc push {r4, r5, r6, lr}
 *   @0x11cb00 mov r4, r0
 *   @0x11cb04 mov r0, r1
 *   @0x11cb08 mov r5, r1
 *   @0x11cb0c bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cb10 subs r6, r0, #0
 *   @0x11cb14 beq 0x11cb54 <_Z22F_SkeletonSetAnimationR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x11cb18 mov r1, #0
 *   @0x11cb1c ldr r0, [sp, #0x10]
 *   @0x11cb20 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11cb24 mov r1, r0
 *   @0x11cb28 mov r0, r6
 *   @0x11cb2c bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc>
 *   @0x11cb30 mov r1, #0
 *   @0x11cb34 mov r3, r1
 *   @0x11cb38 mov r2, r1
 *   @0x11cb3c movt r3, #0x3ff0
 *   @0x11cb40 mov r0, #0
 *   @0x11cb44 str r0, [r5, #0x90]
 *   @0x11cb48 str r1, [r4, #0xc]
 *   @0x11cb4c stm r4, {r2, r3}
 *   @0x11cb50 pop {r4, r5, r6, pc}
 *   @0x11cb54 mov r2, r6
 *   @0x11cb58 mov r3, r6
 *   @0x11cb5c str r6, [r4, #0xc]
 *   @0x11cb60 stm r4, {r2, r3}
 *   @0x11cb64 pop {r4, r5, r6, pc}
 *
 * ══ §96/281 YYGML_sound_stop(int)  0x1366a8  size 108  27 条（0x1366a8..0x136714）
 * @func 0x1366a8 0x136714  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Data(int) / CSound::GetSoundId()
 * 字段偏移 top8: 0x58×1 / 0x44×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1366a8 ldr r3, [pc, #0x58]
 *   @0x1366ac push {r4, lr}
 *   @0x1366b0 ldr r3, [pc, r3]
 *   @0x1366b4 ldrb r3, [r3]
 *   @0x1366b8 cmp r3, #0
 *   @0x1366bc popne {r4, pc}
 *   @0x1366c0 ldr r3, [pc, #0x44]
 *   @0x1366c4 ldr r3, [pc, r3]
 *   @0x1366c8 ldrb r3, [r3]
 *   @0x1366cc cmp r3, #0
 *   @0x1366d0 popne {r4, pc}
 *   @0x1366d4 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x1366d8 subs r1, r0, #0
 *   @0x1366dc beq 0x1366f8 <_Z16YYGML_sound_stopi+0x50>
 *   @0x1366e0 ldr r4, [r1, #0xc]
 *   @0x1366e4 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x1366e8 mov r1, r0
 *   @0x1366ec mov r0, r4
 *   @0x1366f0 pop {r4, lr}
 *   @0x1366f4 b 0x21ecf4 <_Z8SND_StopPKci>
 *   @0x1366f8 ldr r0, [pc, #0x10]
 *   @0x1366fc pop {r4, lr}
 *   @0x136700 add r0, pc, r0
 *   @0x136704 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x136708 eoreq r8, r11, r0, lsl #13
 *   @0x13670c eoreq r8, r11, r8, lsl #19
 *   @0x136710 eoreq r8, r0, r12, lsl #27
 *
 * ══ §97/281 F_DirectoryDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x1386a0  size 108  27 条（0x1386a0..0x13870c）
 * @func 0x1386a0 0x13870c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / LoadSave::_GetSaveFileName(char*, int, char const*) / DestroyDir(char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x58×1 / 0x418×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1386a0 push {r4, r5, lr}
 *   @0x1386a4 sub sp, sp, #1024
 *   @0x1386a8 ldr r4, [pc, #0x58]
 *   @0x1386ac sub sp, sp, #12
 *   @0x1386b0 mov r1, #0
 *   @0x1386b4 ldr r4, [pc, r4]
 *   @0x1386b8 ldr r0, [sp, #0x418]
 *   @0x1386bc ldr r3, [r4]
 *   @0x1386c0 str r3, [sp, #0x404]
 *   @0x1386c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1386c8 subs r2, r0, #0
 *   @0x1386cc beq 0x1386e8 <_Z17F_DirectoryDeleteR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1386d0 add r5, sp, #4
 *   @0x1386d4 mov r1, #1024
 *   @0x1386d8 mov r0, r5
 *   @0x1386dc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1386e0 mov r0, r5
 *   @0x1386e4 bl 0x214e18 <_Z10DestroyDirPKc>
 *   @0x1386e8 ldr r2, [sp, #0x404]
 *   @0x1386ec ldr r3, [r4]
 *   @0x1386f0 cmp r2, r3
 *   @0x1386f4 bne 0x138704 <_Z17F_DirectoryDeleteR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x1386f8 add sp, sp, #1024
 *   @0x1386fc add sp, sp, #12
 *   @0x138700 pop {r4, r5, pc}
 *   @0x138704 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x138708 mlaeq r11, r12, r2, r5
 *
 * ══ §98/281 F_FileWriteReal(RValue&, CInstance*, CInstance*, int, RValue*)  0x139d28  size 108  27 条（0x139d28..0x139d94）
 * @func 0x139d28 0x139d94  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x8×2 / 0x44×1 / 0x34×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139d28 push {r4, lr}
 *   @0x139d2c mov r1, #0
 *   @0x139d30 ldr r0, [sp, #0x8]
 *   @0x139d34 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x139d38 ldr r3, [pc, #0x44]
 *   @0x139d3c ldr r3, [pc, r3]
 *   @0x139d40 ldr r3, [r3]
 *   @0x139d44 cmp r3, #2
 *   @0x139d48 beq 0x139d60 <_Z15F_FileWriteRealR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x139d4c ldr r0, [pc, #0x34]
 *   @0x139d50 mov r1, #0
 *   @0x139d54 pop {r4, lr}
 *   @0x139d58 add r0, pc, r0
 *   @0x139d5c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139d60 ldr r12, [pc, #0x24]
 *   @0x139d64 mov r3, r1
 *   @0x139d68 ldr r1, [pc, #0x20]
 *   @0x139d6c mov r2, r0
 *   @0x139d70 ldr r12, [pc, r12]
 *   @0x139d74 add r1, pc, r1
 *   @0x139d78 ldr r0, [r12, #0x8]
 *   @0x139d7c pop {r4, lr}
 *   @0x139d80 b 0xb68a4 <fprintf@plt>
 *   @0x139d84 eoreq r5, r11, r4, lsr r5
 *   @0x139d88 eoreq r6, r0, r4, lsr r3
 *   @0x139d8c eoreq r5, r11, r4, lsl #10
 *   @0x139d90 eoreq r6, r0, r4, lsr #9
 *
 * ══ §99/281 F_LoadCSV(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a36c  size 108  27 条（0x13a36c..0x13a3d8）
 * @func 0x13a36c 0x13a3d8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / LoadCSV(char*)
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x30×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a36c push {r4, lr}
 *   @0x13a370 mov r3, #0
 *   @0x13a374 ldr r2, [sp, #0x8]
 *   @0x13a378 mov r1, r3
 *   @0x13a37c movt r3, #0xbff0
 *   @0x13a380 str r1, [r0, #0xc]
 *   @0x13a384 stm r0, {r1, r3}
 *   @0x13a388 mov r4, r0
 *   @0x13a38c ldr r3, [r2, #0xc]
 *   @0x13a390 bic r3, r3, #-16777216
 *   @0x13a394 cmp r3, #1
 *   @0x13a398 beq 0x13a3ac <_Z9F_LoadCSVR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x13a39c ldr r0, [pc, #0x30]
 *   @0x13a3a0 pop {r4, lr}
 *   @0x13a3a4 add r0, pc, r0
 *   @0x13a3a8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a3ac mov r0, r2
 *   @0x13a3b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a3b4 bl 0x213528 <_Z7LoadCSVPc>
 *   @0x13a3b8 vmov s15, r0
 *   @0x13a3bc vcvt.f64.s32 d7, s15
 *   @0x13a3c0 vmov r0, r1, d7
 *   @0x13a3c4 vmov r2, s14
 *   @0x13a3c8 mov r3, r1
 *   @0x13a3cc stm r4, {r2, r3}
 *   @0x13a3d0 pop {r4, pc}
 *   @0x13a3d4 eoreq r5, r0, r0, lsl pc
 *
 * ══ §100/281 F_ActionSetCursor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1401a4  size 108  27 条（0x1401a4..0x140210）
 * @func 0x1401a4 0x140210  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x8×1 / 0x48×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1401a4 push {r4, lr}
 *   @0x1401a8 mov r1, #0
 *   @0x1401ac ldr r4, [sp, #0x8]
 *   @0x1401b0 mov r0, r4
 *   @0x1401b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1401b8 ldr r3, [pc, #0x48]
 *   @0x1401bc mov r1, #1
 *   @0x1401c0 ldr r3, [pc, r3]
 *   @0x1401c4 str r0, [r3]
 *   @0x1401c8 mov r0, r4
 *   @0x1401cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1401d0 ldr r3, [pc, #0x34]
 *   @0x1401d4 ldr r3, [pc, r3]
 *   @0x1401d8 cmp r0, #0
 *   @0x1401dc movle r0, #0
 *   @0x1401e0 movgt r0, #1
 *   @0x1401e4 cmp r0, #0
 *   @0x1401e8 strb r0, [r3]
 *   @0x1401ec bne 0x1401fc <_Z17F_ActionSetCursorR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x1401f0 mvn r0, #0
 *   @0x1401f4 pop {r4, lr}
 *   @0x1401f8 b 0x17af8c <_Z20GR_Window_Set_Cursori>
 *   @0x1401fc mov r0, #0
 *   @0x140200 pop {r4, lr}
 *   @0x140204 b 0x17af8c <_Z20GR_Window_Set_Cursori>
 *   @0x140208 eoreq pc, r10, r8, lsr #4
 *   @0x14020c eoreq pc, r10, r8, lsl r2
 *
 * ══ §101/281 F_ActionSetHealth(RValue&, CInstance*, CInstance*, int, RValue*)  0x140c7c  size 108  27 条（0x140c7c..0x140ce8）
 * @func 0x140c7c 0x140ce8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x4c×2 / 0x8×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140c7c push {r3, lr}
 *   @0x140c80 mov r1, #0
 *   @0x140c84 ldr r0, [sp, #0x8]
 *   @0x140c88 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x140c8c ldr r2, [pc, #0x4c]
 *   @0x140c90 ldr r3, [pc, #0x4c]
 *   @0x140c94 ldr r2, [pc, r2]
 *   @0x140c98 ldr r3, [pc, r3]
 *   @0x140c9c vldr d7, [r3]
 *   @0x140ca0 ldrb r2, [r2]
 *   @0x140ca4 vcmpe.f64 d7, #0
 *   @0x140ca8 cmp r2, #0
 *   @0x140cac vmov d6, r0, r1
 *   @0x140cb0 vaddne.f64 d6, d6, d7
 *   @0x140cb4 vmrs APSR_nzcv, fpscr
 *   @0x140cb8 vstr d6, [r3]
 *   @0x140cbc pople {r3, pc}
 *   @0x140cc0 vldr d7, [r3]
 *   @0x140cc4 vcmpe.f64 d7, #0
 *   @0x140cc8 vmrs APSR_nzcv, fpscr
 *   @0x140ccc pophi {r3, pc}
 *   @0x140cd0 mov r0, #7
 *   @0x140cd4 mov r1, #9
 *   @0x140cd8 pop {r3, lr}
 *   @0x140cdc b 0xf33b0 <_Z17Perform_Event_Allii>
 *   @0x140ce0 eoreq r12, r10, r8, lsr #29
 *   @0x140ce4 eoreq lr, r10, r0, asr #14
 *
 * ══ §102/281 YYGML_action_set_alarm(CInstance*, int, int)  0x141c34  size 108  27 条（0x141c34..0x141ca0）
 * @func 0x141c34 0x141ca0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::GetTimer(int)×2 / YYGML_action_set_alarm(CInstance*, int, int)+0x24
 * 字段偏移 top8: 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141c34 ldr r3, [pc, #0x60]
 *   @0x141c38 push {r4, r5, r6, lr}
 *   @0x141c3c ldr r3, [pc, r3]
 *   @0x141c40 mov r6, r1
 *   @0x141c44 mov r4, r2
 *   @0x141c48 ldrb r3, [r3]
 *   @0x141c4c mov r5, r0
 *   @0x141c50 cmp r3, #0
 *   @0x141c54 bne 0x141c6c <_Z22YYGML_action_set_alarmP9CInstanceii+0x38>
 *   @0x141c58 mov r0, r5
 *   @0x141c5c mov r1, r4
 *   @0x141c60 mov r2, r6
 *   @0x141c64 pop {r4, r5, r6, lr}
 *   @0x141c68 b 0x193148 <_ZN9CInstance8SetTimerEii>
 *   @0x141c6c mov r1, r2
 *   @0x141c70 bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x141c74 cmp r0, #0
 *   @0x141c78 blt 0x141c58 <_Z22YYGML_action_set_alarmP9CInstanceii+0x24>
 *   @0x141c7c mov r1, r4
 *   @0x141c80 mov r0, r5
 *   @0x141c84 bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x141c88 mov r1, r4
 *   @0x141c8c add r2, r0, r6
 *   @0x141c90 mov r0, r5
 *   @0x141c94 pop {r4, r5, r6, lr}
 *   @0x141c98 b 0x193148 <_ZN9CInstance8SetTimerEii>
 *   @0x141c9c eoreq r11, r10, r0, lsl #30
 *
 * ══ §103/281 F_D3DMatrixStackClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x143948  size 108  27 条（0x143948..0x1439b4）
 * @func 0x143948 0x1439b4  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1 / 0x58×1 / 0x38×1 / 0x34×1 / 0x30×1 / 0x2c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143948 ldr r0, [pc, #0x5c]
 *   @0x14394c mov r2, #0
 *   @0x143950 ldr r3, [pc, #0x58]
 *   @0x143954 mov r1, #1065353216
 *   @0x143958 ldr r0, [pc, r0]
 *   @0x14395c mov r12, #0
 *   @0x143960 ldr r3, [pc, r3]
 *   @0x143964 str r12, [r0]
 *   @0x143968 str r2, [r3, #0x38]
 *   @0x14396c str r2, [r3, #0x34]
 *   @0x143970 str r2, [r3, #0x30]
 *   @0x143974 str r2, [r3, #0x2c]
 *   @0x143978 str r2, [r3, #0x24]
 *   @0x14397c str r2, [r3, #0x20]
 *   @0x143980 str r2, [r3, #0x1c]
 *   @0x143984 str r2, [r3, #0x18]
 *   @0x143988 str r2, [r3, #0x10]
 *   @0x14398c str r2, [r3, #0xc]
 *   @0x143990 str r2, [r3, #0x8]
 *   @0x143994 str r2, [r3, #0x4]
 *   @0x143998 str r1, [r3, #0x3c]
 *   @0x14399c str r1, [r3, #0x28]
 *   @0x1439a0 str r1, [r3, #0x14]
 *   @0x1439a4 str r1, [r3]
 *   @0x1439a8 bx lr
 *   @0x1439ac eoreq r11, r10, r12, lsr #25
 *   @0x1439b0 eoreq r11, r10, r8, lsr #25
 *
 * ══ §104/281 F_GPUGetBlendEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x147cf0  size 108  27 条（0x147cf0..0x147d5c）
 * @func 0x147cf0 0x147d6c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147cf0 push {r3, r4, r5, lr}
 *   @0x147cf4 subs r5, r3, #0
 *   @0x147cf8 mov r1, #0
 *   @0x147cfc mov r4, r0
 *   @0x147d00 str r1, [r0, #0xc]
 *   @0x147d04 str r1, [r0]
 *   @0x147d08 str r1, [r0, #0x4]
 *   @0x147d0c bne 0x147d44 <_Z19F_GPUGetBlendEnableR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x147d10 ldr r0, [pc, #0x3c]
 *   @0x147d14 mov r1, #12
 *   @0x147d18 ldr r0, [pc, r0]
 *   @0x147d1c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147d20 cmp r0, #0
 *   @0x147d24 moveq r3, r0
 *   @0x147d28 movne r2, #0
 *   @0x147d2c movne r3, r5
 *   @0x147d30 movtne r2, #0x3ff0
 *   @0x147d34 moveq r2, r3
 *   @0x147d38 str r3, [r4]
 *   @0x147d3c str r2, [r4, #0x4]
 *   @0x147d40 pop {r3, r4, r5, pc}
 *   @0x147d44 ldr r0, [pc, #0xc]
 *   @0x147d48 pop {r3, r4, r5, lr}
 *   @0x147d4c add r0, pc, r0
 *   @0x147d50 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147d54 eoreq r5, r10, r0, ror #31
 *   @0x147d58 andseq r10, pc, r12, ror #2
 *
 * ══ §105/281 F_GPUGetZTestEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x147d5c  size 108  27 条（0x147d5c..0x147dc8）
 * @func 0x147d5c 0x147dc8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147d5c push {r3, r4, r5, lr}
 *   @0x147d60 subs r5, r3, #0
 *   @0x147d64 mov r1, #0
 *   @0x147d68 mov r4, r0
 *   @0x147d6c str r1, [r0, #0xc]
 *   @0x147d70 str r1, [r0]
 *   @0x147d74 str r1, [r0, #0x4]
 *   @0x147d78 bne 0x147db0 <_Z19F_GPUGetZTestEnableR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x147d7c ldr r0, [pc, #0x3c]
 *   @0x147d80 mov r1, #1
 *   @0x147d84 ldr r0, [pc, r0]
 *   @0x147d88 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147d8c cmp r0, #0
 *   @0x147d90 moveq r3, r0
 *   @0x147d94 movne r2, #0
 *   @0x147d98 movne r3, r5
 *   @0x147d9c movtne r2, #0x3ff0
 *   @0x147da0 moveq r2, r3
 *   @0x147da4 str r3, [r4]
 *   @0x147da8 str r2, [r4, #0x4]
 *   @0x147dac pop {r3, r4, r5, pc}
 *   @0x147db0 ldr r0, [pc, #0xc]
 *   @0x147db4 pop {r3, r4, r5, lr}
 *   @0x147db8 add r0, pc, r0
 *   @0x147dbc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147dc0 eoreq r5, r10, r4, ror pc
 *   @0x147dc4 andseq r10, pc, r8, lsr r1
 *
 * ══ §106/281 F_GPUGetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x147e2c  size 108  27 条（0x147e2c..0x147e98）
 * @func 0x147e2c 0x147e98  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147e2c push {r3, r4, r5, lr}
 *   @0x147e30 subs r5, r3, #0
 *   @0x147e34 mov r1, #0
 *   @0x147e38 mov r4, r0
 *   @0x147e3c str r1, [r0, #0xc]
 *   @0x147e40 str r1, [r0]
 *   @0x147e44 str r1, [r0, #0x4]
 *   @0x147e48 bne 0x147e80 <_Z20F_GPUGetZWriteEnableR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x147e4c ldr r0, [pc, #0x3c]
 *   @0x147e50 mov r1, #4
 *   @0x147e54 ldr r0, [pc, r0]
 *   @0x147e58 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147e5c cmp r0, #0
 *   @0x147e60 moveq r3, r0
 *   @0x147e64 movne r2, #0
 *   @0x147e68 movne r3, r5
 *   @0x147e6c movtne r2, #0x3ff0
 *   @0x147e70 moveq r2, r3
 *   @0x147e74 str r3, [r4]
 *   @0x147e78 str r2, [r4, #0x4]
 *   @0x147e7c pop {r3, r4, r5, pc}
 *   @0x147e80 ldr r0, [pc, #0xc]
 *   @0x147e84 pop {r3, r4, r5, lr}
 *   @0x147e88 add r0, pc, r0
 *   @0x147e8c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147e90 eoreq r5, r10, r4, lsr #29
 *   @0x147e94 ldrsbeq r10, [pc], -r0
 *
 * ══ §107/281 F_GPUGetAlphaTestEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x1483c0  size 108  27 条（0x1483c0..0x14842c）
 * @func 0x1483c0 0x14842c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1483c0 push {r3, r4, r5, lr}
 *   @0x1483c4 subs r5, r3, #0
 *   @0x1483c8 mov r1, #0
 *   @0x1483cc mov r4, r0
 *   @0x1483d0 str r1, [r0, #0xc]
 *   @0x1483d4 str r1, [r0]
 *   @0x1483d8 str r1, [r0, #0x4]
 *   @0x1483dc bne 0x148414 <_Z23F_GPUGetAlphaTestEnableR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1483e0 ldr r0, [pc, #0x3c]
 *   @0x1483e4 mov r1, #5
 *   @0x1483e8 ldr r0, [pc, r0]
 *   @0x1483ec bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x1483f0 cmp r0, #0
 *   @0x1483f4 moveq r3, r0
 *   @0x1483f8 movne r2, #0
 *   @0x1483fc movne r3, r5
 *   @0x148400 movtne r2, #0x3ff0
 *   @0x148404 moveq r2, r3
 *   @0x148408 str r3, [r4]
 *   @0x14840c str r2, [r4, #0x4]
 *   @0x148410 pop {r3, r4, r5, pc}
 *   @0x148414 ldr r0, [pc, #0xc]
 *   @0x148418 pop {r3, r4, r5, lr}
 *   @0x14841c add r0, pc, r0
 *   @0x148420 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148424 eoreq r5, r10, r0, lsl r9
 *   @0x148428 andseq r9, pc, r12, ror sp
 *
 * ══ §108/281 F_GPUGetTexRepeat(RValue&, CInstance*, CInstance*, int, RValue*)  0x1485d8  size 108  27 条（0x1485d8..0x148644）
 * @func 0x1485d8 0x148644  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1485d8 push {r3, r4, r5, lr}
 *   @0x1485dc subs r5, r3, #0
 *   @0x1485e0 mov r1, #0
 *   @0x1485e4 mov r4, r0
 *   @0x1485e8 str r1, [r0, #0xc]
 *   @0x1485ec str r1, [r0]
 *   @0x1485f0 str r1, [r0, #0x4]
 *   @0x1485f4 bne 0x14862c <_Z17F_GPUGetTexRepeatR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1485f8 ldr r0, [pc, #0x3c]
 *   @0x1485fc mov r1, r5
 *   @0x148600 mov r2, #2
 *   @0x148604 ldr r0, [pc, r0]
 *   @0x148608 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x14860c cmp r0, #0
 *   @0x148610 moveq r3, #0
 *   @0x148614 moveq r5, r0
 *   @0x148618 movteq r3, #0x3ff0
 *   @0x14861c movne r3, r5
 *   @0x148620 str r5, [r4]
 *   @0x148624 str r3, [r4, #0x4]
 *   @0x148628 pop {r3, r4, r5, pc}
 *   @0x14862c ldr r0, [pc, #0xc]
 *   @0x148630 pop {r3, r4, r5, lr}
 *   @0x148634 add r0, pc, r0
 *   @0x148638 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14863c .word 0x002a56f4
 *   @0x148640 mulseq pc, r4, r12
 *
 * ══ §109/281 F_GPUGetLightingEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x149ee0  size 108  27 条（0x149ee0..0x149f4c）
 * @func 0x149ee0 0x149f4c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149ee0 push {r3, r4, r5, lr}
 *   @0x149ee4 subs r5, r3, #0
 *   @0x149ee8 mov r1, #0
 *   @0x149eec mov r4, r0
 *   @0x149ef0 str r1, [r0, #0xc]
 *   @0x149ef4 str r1, [r0]
 *   @0x149ef8 str r1, [r0, #0x4]
 *   @0x149efc bne 0x149f34 <_Z22F_GPUGetLightingEnableR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x149f00 ldr r0, [pc, #0x3c]
 *   @0x149f04 mov r1, #21
 *   @0x149f08 ldr r0, [pc, r0]
 *   @0x149f0c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x149f10 cmp r0, #0
 *   @0x149f14 moveq r3, r0
 *   @0x149f18 movne r2, #0
 *   @0x149f1c movne r3, r5
 *   @0x149f20 movtne r2, #0x3ff0
 *   @0x149f24 moveq r2, r3
 *   @0x149f28 str r3, [r4]
 *   @0x149f2c str r2, [r4, #0x4]
 *   @0x149f30 pop {r3, r4, r5, pc}
 *   @0x149f34 ldr r0, [pc, #0xc]
 *   @0x149f38 pop {r3, r4, r5, lr}
 *   @0x149f3c add r0, pc, r0
 *   @0x149f40 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149f44 .word 0x002a3df0
 *   @0x149f48 andseq r8, pc, r0, asr r11
 *
 * ══ §110/281 F_PhysicsSetFriction(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c10c  size 108  27 条（0x14c10c..0x14c178）
 * @func 0x14c10c 0x14c188  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x84×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c10c push {r4, r5, r6, lr}
 *   @0x14c110 mov r3, #0
 *   @0x14c114 str r3, [r0]
 *   @0x14c118 str r3, [r0, #0x4]
 *   @0x14c11c ldr r4, [r1, #0x84]
 *   @0x14c120 ldr r5, [sp, #0x10]
 *   @0x14c124 cmp r4, r3
 *   @0x14c128 str r3, [r0, #0xc]
 *   @0x14c12c beq 0x14c160 <_Z20F_PhysicsSetFrictionR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x14c130 mov r1, r3
 *   @0x14c134 mov r0, r5
 *   @0x14c138 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c13c mov r1, #1
 *   @0x14c140 mov r6, r0
 *   @0x14c144 mov r0, r5
 *   @0x14c148 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c14c mov r1, r6
 *   @0x14c150 mov r2, r0
 *   @0x14c154 mov r0, r4
 *   @0x14c158 pop {r4, r5, r6, lr}
 *   @0x14c15c b 0x2379cc <_ZN14CPhysicsObject11SetFrictionEif>
 *   @0x14c160 ldr r0, [pc, #0xc]
 *   @0x14c164 mov r1, r4
 *   @0x14c168 pop {r4, r5, r6, lr}
 *   @0x14c16c add r0, pc, r0
 *   @0x14c170 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c174 andseq r7, pc, r8, ror r12
 *
 * ══ §111/281 F_PhysicsSetDensity(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c178  size 108  27 条（0x14c178..0x14c1e4）
 * @func 0x14c178 0x14c1f4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x84×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c178 push {r4, r5, r6, lr}
 *   @0x14c17c mov r3, #0
 *   @0x14c180 str r3, [r0]
 *   @0x14c184 str r3, [r0, #0x4]
 *   @0x14c188 ldr r4, [r1, #0x84]
 *   @0x14c18c ldr r5, [sp, #0x10]
 *   @0x14c190 cmp r4, r3
 *   @0x14c194 str r3, [r0, #0xc]
 *   @0x14c198 beq 0x14c1cc <_Z19F_PhysicsSetDensityR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x14c19c mov r1, r3
 *   @0x14c1a0 mov r0, r5
 *   @0x14c1a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c1a8 mov r1, #1
 *   @0x14c1ac mov r6, r0
 *   @0x14c1b0 mov r0, r5
 *   @0x14c1b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c1b8 mov r1, r6
 *   @0x14c1bc mov r2, r0
 *   @0x14c1c0 mov r0, r4
 *   @0x14c1c4 pop {r4, r5, r6, lr}
 *   @0x14c1c8 b 0x237a18 <_ZN14CPhysicsObject10SetDensityEif>
 *   @0x14c1cc ldr r0, [pc, #0xc]
 *   @0x14c1d0 mov r1, r4
 *   @0x14c1d4 pop {r4, r5, r6, lr}
 *   @0x14c1d8 add r0, pc, r0
 *   @0x14c1dc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c1e0 andseq r7, pc, r12, lsl #24
 *
 * ══ §112/281 F_PhysicsSetRestitution(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c1e4  size 108  27 条（0x14c1e4..0x14c250）
 * @func 0x14c1e4 0x14c250  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x84×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c1e4 push {r4, r5, r6, lr}
 *   @0x14c1e8 mov r3, #0
 *   @0x14c1ec str r3, [r0]
 *   @0x14c1f0 str r3, [r0, #0x4]
 *   @0x14c1f4 ldr r4, [r1, #0x84]
 *   @0x14c1f8 ldr r5, [sp, #0x10]
 *   @0x14c1fc cmp r4, r3
 *   @0x14c200 str r3, [r0, #0xc]
 *   @0x14c204 beq 0x14c238 <_Z23F_PhysicsSetRestitutionR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x14c208 mov r1, r3
 *   @0x14c20c mov r0, r5
 *   @0x14c210 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c214 mov r1, #1
 *   @0x14c218 mov r6, r0
 *   @0x14c21c mov r0, r5
 *   @0x14c220 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c224 mov r1, r6
 *   @0x14c228 mov r2, r0
 *   @0x14c22c mov r0, r4
 *   @0x14c230 pop {r4, r5, r6, lr}
 *   @0x14c234 b 0x237a68 <_ZN14CPhysicsObject14SetRestitutionEif>
 *   @0x14c238 ldr r0, [pc, #0xc]
 *   @0x14c23c mov r1, r4
 *   @0x14c240 pop {r4, r5, r6, lr}
 *   @0x14c244 add r0, pc, r0
 *   @0x14c248 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c24c andseq r7, pc, r0, lsr #23
 *
 * ══ §113/281 F_PhysicsBindFixture(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c6a0  size 108  27 条（0x14c6a0..0x14c70c）
 * @func 0x14c6a0 0x14c70c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / anon_14c57c
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c6a0 push {r3, r4, r5, r6, r7, lr}
 *   @0x14c6a4 mov r3, #0
 *   @0x14c6a8 ldr r5, [sp, #0x18]
 *   @0x14c6ac mov r4, r0
 *   @0x14c6b0 str r3, [r0, #0xc]
 *   @0x14c6b4 mov r6, r1
 *   @0x14c6b8 mov r1, r3
 *   @0x14c6bc mov r0, r5
 *   @0x14c6c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c6c4 mov r1, #1
 *   @0x14c6c8 mov r7, r0
 *   @0x14c6cc mov r0, r5
 *   @0x14c6d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c6d4 vldr s0, [pc, #44]
 *   @0x14c6d8 mov r1, r7
 *   @0x14c6dc vmov.f32 s1, s0
 *   @0x14c6e0 mov r2, r0
 *   @0x14c6e4 mov r0, r6
 *   @0x14c6e8 bl 0x14c57c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x14c6ec vmov s15, r0
 *   @0x14c6f0 vcvt.f64.s32 d7, s15
 *   @0x14c6f4 vmov r0, r1, d7
 *   @0x14c6f8 vmov r2, s14
 *   @0x14c6fc mov r3, r1
 *   @0x14c700 stm r4, {r2, r3}
 *   @0x14c704 pop {r3, r4, r5, r6, r7, pc}
 *   @0x14c708 andeq r0, r0, r0
 *
 * ══ §114/281 F_PhysicsSetUpdateSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x14cfc0  size 108  27 条（0x14cfc0..0x14d02c）
 * @func 0x14cfc0 0x14d03c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x58×2 / 0xb4×2 / 0x8×1 / 0x20×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14cfc0 ldr r3, [pc, #0x58]
 *   @0x14cfc4 push {r4, lr}
 *   @0x14cfc8 ldr r3, [pc, r3]
 *   @0x14cfcc ldr r0, [sp, #0x8]
 *   @0x14cfd0 ldr r4, [r3]
 *   @0x14cfd4 cmp r4, #0
 *   @0x14cfd8 beq 0x14d00c <_Z23F_PhysicsSetUpdateSpeedR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14cfdc ldr r1, [r4, #0xb4]
 *   @0x14cfe0 cmp r1, #0
 *   @0x14cfe4 beq 0x14cffc <_Z23F_PhysicsSetUpdateSpeedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x14cfe8 mov r1, #0
 *   @0x14cfec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14cff0 ldr r3, [r4, #0xb4]
 *   @0x14cff4 str r0, [r3, #0x58]
 *   @0x14cff8 pop {r4, pc}
 *   @0x14cffc ldr r0, [pc, #0x20]
 *   @0x14d000 pop {r4, lr}
 *   @0x14d004 add r0, pc, r0
 *   @0x14d008 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d00c ldr r0, [pc, #0x14]
 *   @0x14d010 mov r1, r4
 *   @0x14d014 pop {r4, lr}
 *   @0x14d018 add r0, pc, r0
 *   @0x14d01c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d020 eoreq r0, r10, r0, ror #18
 *   @0x14d024 andseq r6, pc, r0, lsr #28
 *   @0x14d028 ldrsheq r6, [pc], -r4
 *
 * ══ §115/281 F_PhysicsSetUpdateIterations(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d02c  size 108  27 条（0x14d02c..0x14d098）
 * @func 0x14d02c 0x14d098  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xb4×2 / 0x58×1 / 0x8×1 / 0x5c×1 / 0x20×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d02c ldr r3, [pc, #0x58]
 *   @0x14d030 push {r4, lr}
 *   @0x14d034 ldr r3, [pc, r3]
 *   @0x14d038 ldr r0, [sp, #0x8]
 *   @0x14d03c ldr r4, [r3]
 *   @0x14d040 cmp r4, #0
 *   @0x14d044 beq 0x14d078 <_Z28F_PhysicsSetUpdateIterationsR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14d048 ldr r1, [r4, #0xb4]
 *   @0x14d04c cmp r1, #0
 *   @0x14d050 beq 0x14d068 <_Z28F_PhysicsSetUpdateIterationsR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x14d054 mov r1, #0
 *   @0x14d058 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d05c ldr r3, [r4, #0xb4]
 *   @0x14d060 str r0, [r3, #0x5c]
 *   @0x14d064 pop {r4, pc}
 *   @0x14d068 ldr r0, [pc, #0x20]
 *   @0x14d06c pop {r4, lr}
 *   @0x14d070 add r0, pc, r0
 *   @0x14d074 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d078 ldr r0, [pc, #0x14]
 *   @0x14d07c mov r1, r4
 *   @0x14d080 pop {r4, lr}
 *   @0x14d084 add r0, pc, r0
 *   @0x14d088 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d08c .word 0x002a08f4
 *   @0x14d090 ldrheq r6, [pc], -r4
 *   @0x14d094 andseq r6, pc, r8, lsl #29
 *
 * ══ §116/281 F_GamepadGetButtonThreshold(RValue&, CInstance*, CInstance*, int, RValue*)  0x1512e4  size 108  27 条（0x1512e4..0x151350）
 * @func 0x1512e4 0x151360  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x8×1 / 0x30×1 / 0x20×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1512e4 push {r4, lr}
 *   @0x1512e8 mov r3, #0
 *   @0x1512ec mov r4, r0
 *   @0x1512f0 str r3, [r0, #0xc]
 *   @0x1512f4 str r3, [r0]
 *   @0x1512f8 mov r1, r3
 *   @0x1512fc str r3, [r0, #0x4]
 *   @0x151300 ldr r0, [sp, #0x8]
 *   @0x151304 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151308 cmp r0, #0
 *   @0x15130c poplt {r4, pc}
 *   @0x151310 ldr r3, [pc, #0x30]
 *   @0x151314 ldr r3, [pc, r3]
 *   @0x151318 ldr r3, [r3]
 *   @0x15131c cmp r0, r3
 *   @0x151320 popge {r4, pc}
 *   @0x151324 ldr r3, [pc, #0x20]
 *   @0x151328 ldr r3, [pc, r3]
 *   @0x15132c ldr r3, [r3]
 *   @0x151330 ldr r3, [r3, r0, lsl #2]
 *   @0x151334 vldr s15, [r3, #28]
 *   @0x151338 vcvt.f64.f32 d6, s15
 *   @0x15133c vmov r2, r3, d6
 *   @0x151340 stm r4, {r2, r3}
 *   @0x151344 pop {r4, pc}
 *   @0x151348 eoreq lr, r9, r12, asr #14
 *   @0x15134c eoreq lr, r9, r12, lsr r7
 *
 * ══ §117/281 F_GamepadGetAxisDeadzone(RValue&, CInstance*, CInstance*, int, RValue*)  0x151350  size 108  27 条（0x151350..0x1513bc）
 * @func 0x151350 0x1513cc  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x8×1 / 0x30×1 / 0x20×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151350 push {r4, lr}
 *   @0x151354 mov r3, #0
 *   @0x151358 mov r4, r0
 *   @0x15135c str r3, [r0, #0xc]
 *   @0x151360 str r3, [r0]
 *   @0x151364 mov r1, r3
 *   @0x151368 str r3, [r0, #0x4]
 *   @0x15136c ldr r0, [sp, #0x8]
 *   @0x151370 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151374 cmp r0, #0
 *   @0x151378 poplt {r4, pc}
 *   @0x15137c ldr r3, [pc, #0x30]
 *   @0x151380 ldr r3, [pc, r3]
 *   @0x151384 ldr r3, [r3]
 *   @0x151388 cmp r0, r3
 *   @0x15138c popge {r4, pc}
 *   @0x151390 ldr r3, [pc, #0x20]
 *   @0x151394 ldr r3, [pc, r3]
 *   @0x151398 ldr r3, [r3]
 *   @0x15139c ldr r3, [r3, r0, lsl #2]
 *   @0x1513a0 vldr s15, [r3, #32]
 *   @0x1513a4 vcvt.f64.f32 d6, s15
 *   @0x1513a8 vmov r2, r3, d6
 *   @0x1513ac stm r4, {r2, r3}
 *   @0x1513b0 pop {r4, pc}
 *   @0x1513b4 eoreq lr, r9, r0, ror #13
 *   @0x1513b8 .word 0x0029e6d0
 *
 * ══ §118/281 F_IO_ShowVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*)  0x15648c  size 108  27 条（0x15648c..0x1564f8）
 * @func 0x15648c 0x156508  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_IO_ShowVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*)+0x3c / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x30×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15648c push {r4, lr}
 *   @0x156490 mov r1, #0
 *   @0x156494 ldr r0, [sp, #0x8]
 *   @0x156498 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15649c subs r4, r0, #1
 *   @0x1564a0 bmi 0x1564b8 <_Z19F_IO_ShowVirtualKeyR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x1564a4 ldr r3, [pc, #0x40]
 *   @0x1564a8 ldr r3, [pc, r3]
 *   @0x1564ac ldr r3, [r3]
 *   @0x1564b0 cmp r4, r3
 *   @0x1564b4 blt 0x1564c8 <_Z19F_IO_ShowVirtualKeyR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1564b8 ldr r0, [pc, #0x30]
 *   @0x1564bc mov r1, #0
 *   @0x1564c0 add r0, pc, r0
 *   @0x1564c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1564c8 ldr r3, [pc, #0x24]
 *   @0x1564cc mov r0, #44
 *   @0x1564d0 mul r0, r0, r4
 *   @0x1564d4 ldr r3, [pc, r3]
 *   @0x1564d8 ldr r3, [r3]
 *   @0x1564dc ldrh r2, [r3, r0]
 *   @0x1564e0 orr r2, r2, #2
 *   @0x1564e4 strh r2, [r3, r0]
 *   @0x1564e8 pop {r4, pc}
 *   @0x1564ec eoreq r9, r9, r8, lsr #13
 *   @0x1564f0 andseq r0, pc, r8, lsl #1
 *   @0x1564f4 eoreq r9, r9, r0, lsl #13
 *
 * ══ §119/281 F_IO_HideVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*)  0x1564f8  size 108  27 条（0x1564f8..0x156564）
 * @func 0x1564f8 0x156564  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_IO_HideVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*)+0x3c / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x30×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1564f8 push {r4, lr}
 *   @0x1564fc mov r1, #0
 *   @0x156500 ldr r0, [sp, #0x8]
 *   @0x156504 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156508 subs r4, r0, #1
 *   @0x15650c bmi 0x156524 <_Z19F_IO_HideVirtualKeyR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x156510 ldr r3, [pc, #0x40]
 *   @0x156514 ldr r3, [pc, r3]
 *   @0x156518 ldr r3, [r3]
 *   @0x15651c cmp r4, r3
 *   @0x156520 blt 0x156534 <_Z19F_IO_HideVirtualKeyR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x156524 ldr r0, [pc, #0x30]
 *   @0x156528 mov r1, #0
 *   @0x15652c add r0, pc, r0
 *   @0x156530 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x156534 ldr r3, [pc, #0x24]
 *   @0x156538 mov r0, #44
 *   @0x15653c mul r0, r0, r4
 *   @0x156540 ldr r3, [pc, r3]
 *   @0x156544 ldr r3, [r3]
 *   @0x156548 ldrh r2, [r3, r0]
 *   @0x15654c bic r2, r2, #2
 *   @0x156550 strh r2, [r3, r0]
 *   @0x156554 pop {r4, pc}
 *   @0x156558 eoreq r9, r9, r12, lsr r6
 *   @0x15655c andseq r0, pc, r12, lsl r0
 *   @0x156560 eoreq r9, r9, r4, lsl r6
 *
 * ══ §120/281 F_YoYo_AchievementLoadLeaderboard(RValue&, CInstance*, CInstance*, int, RValue*)  0x156654  size 108  27 条（0x156654..0x1566c0）
 * @func 0x156654 0x1566c0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156654 push {r4, r5, r6, r7, r8, lr}
 *   @0x156658 mov r3, #0
 *   @0x15665c ldr r4, [sp, #0x18]
 *   @0x156660 mov r1, r3
 *   @0x156664 str r3, [r0, #0xc]
 *   @0x156668 str r3, [r0]
 *   @0x15666c str r3, [r0, #0x4]
 *   @0x156670 mov r0, r4
 *   @0x156674 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156678 mov r1, #1
 *   @0x15667c mov r7, r0
 *   @0x156680 mov r0, r4
 *   @0x156684 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156688 mov r1, #2
 *   @0x15668c mov r6, r0
 *   @0x156690 mov r0, r4
 *   @0x156694 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156698 mov r1, #3
 *   @0x15669c mov r5, r0
 *   @0x1566a0 mov r0, r4
 *   @0x1566a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1566a8 mov r1, r6
 *   @0x1566ac mov r2, r5
 *   @0x1566b0 mov r3, r0
 *   @0x1566b4 mov r0, r7
 *   @0x1566b8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1566bc b 0x16107c <_Z28Achievement_Load_LeaderboardPciii>
 *
 * ══ §121/281 Achievement_Load_Leaderboard(char*, int, int, int)  0x16107c  size 108  27 条（0x16107c..0x1610e8）
 * @func 0x16107c 0x1610e8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×1 / 0x28×1 / 0x24×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16107c push {r4, r5, r6, r7, lr}
 *   @0x161080 sub sp, sp, #20
 *   @0x161084 mov r7, r2
 *   @0x161088 mov r5, r1
 *   @0x16108c mov r4, r3
 *   @0x161090 mov r6, r0
 *   @0x161094 bl 0x290274 <getJNIEnv>
 *   @0x161098 mov r1, r6
 *   @0x16109c ldr r3, [r0]
 *   @0x1610a0 ldr r3, [r3, #0x29c]
 *   @0x1610a4 blx r3
 *   @0x1610a8 mov r6, r0
 *   @0x1610ac bl 0x290274 <getJNIEnv>
 *   @0x1610b0 ldr lr, [pc, #0x28]
 *   @0x1610b4 mov r3, r6
 *   @0x1610b8 ldr r12, [pc, #0x24]
 *   @0x1610bc ldr lr, [pc, lr]
 *   @0x1610c0 ldr r12, [pc, r12]
 *   @0x1610c4 ldr r1, [lr]
 *   @0x1610c8 ldr r2, [r12]
 *   @0x1610cc stm sp, {r5, r7}
 *   @0x1610d0 str r4, [sp, #0x8]
 *   @0x1610d4 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x1610d8 add sp, sp, #20
 *   @0x1610dc pop {r4, r5, r6, r7, pc}
 *   @0x1610e0 eoreq r12, r8, r8, ror #17
 *   @0x1610e4 eoreq lr, r8, r4, ror lr
 *
 * ══ §122/281 Cloud_Synchronise(int (*)(HTTP_REQ_CONTEXT*, void*, int*))  0x161390  size 108  27 条（0x161390..0x1613fc）
 * @func 0x161390 0x1613fc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / getJNIEnv
 * 字段偏移 top8: 0x20×2 / 0x4×1 / 0x8×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161390 push {r4, r5, lr}
 *   @0x161394 mov r5, r0
 *   @0x161398 sub sp, sp, #20
 *   @0x16139c mov r0, #68
 *   @0x1613a0 bl 0x27c524 <_Znwj>
 *   @0x1613a4 mov r12, #0
 *   @0x1613a8 mov r3, r5
 *   @0x1613ac mov r1, r12
 *   @0x1613b0 mov r2, r12
 *   @0x1613b4 str r12, [sp]
 *   @0x1613b8 str r12, [sp, #0x4]
 *   @0x1613bc str r12, [sp, #0x8]
 *   @0x1613c0 mov r4, r0
 *   @0x1613c4 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x1613c8 bl 0x290274 <getJNIEnv>
 *   @0x1613cc ldr r1, [pc, #0x20]
 *   @0x1613d0 ldr r2, [pc, #0x20]
 *   @0x1613d4 ldr r1, [pc, r1]
 *   @0x1613d8 ldr r3, [r4, #0x24]
 *   @0x1613dc ldr r2, [pc, r2]
 *   @0x1613e0 ldr r1, [r1]
 *   @0x1613e4 ldr r2, [r2]
 *   @0x1613e8 add sp, sp, #20
 *   @0x1613ec pop {r4, r5, lr}
 *   @0x1613f0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x1613f4 .word 0x0028c5d0
 *   @0x1613f8 eoreq lr, r8, r4, ror r11
 *
 * ══ §123/281 GR_D3D_Reset()  0x168c24  size 108  27 条（0x168c24..0x168c90）
 * @func 0x168c24 0x168c90  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_FreeAll() / Graphics::GraphicsReset() / Graphics::Clear(unsigned int, float, int, eClearFlags) / RenderStateManager::Force() / GR_D3D_Settings_Init()
 * 字段偏移 top8: 0x2c×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168c24 push {r4, lr}
 *   @0x168c28 bl 0x171c64 <_Z18GR_Surface_FreeAllv>
 *   @0x168c2c bl 0x17dd48 <_ZN8Graphics13GraphicsResetEv>
 *   @0x168c30 subs r4, r0, #0
 *   @0x168c34 bne 0x168c40 <_Z12GR_D3D_Resetv+0x1c>
 *   @0x168c38 mov r0, r4
 *   @0x168c3c pop {r4, pc}
 *   @0x168c40 mov r0, #0
 *   @0x168c44 mov r3, #7
 *   @0x168c48 mov r1, #1065353216
 *   @0x168c4c mov r2, r0
 *   @0x168c50 bl 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags>
 *   @0x168c54 ldr r3, [pc, #0x2c]
 *   @0x168c58 ldr r3, [pc, r3]
 *   @0x168c5c ldrb r3, [r3]
 *   @0x168c60 cmp r3, #0
 *   @0x168c64 beq 0x168c7c <_Z12GR_D3D_Resetv+0x58>
 *   @0x168c68 ldr r0, [pc, #0x1c]
 *   @0x168c6c ldr r0, [pc, r0]
 *   @0x168c70 bl 0x168294 <_ZN18RenderStateManager5ForceEv>
 *   @0x168c74 mov r0, r4
 *   @0x168c78 pop {r4, pc}
 *   @0x168c7c bl 0x168a50 <_Z20GR_D3D_Settings_Initv>
 *   @0x168c80 mov r0, r4
 *   @0x168c84 pop {r4, pc}
 *   @0x168c88 eoreq r4, r8, r12, asr #25
 *   @0x168c8c eoreq r5, r8, r12, lsl #1
 *
 * ══ §124/281 GR_Draw_Set_Color4(int, int, int, float)  0x169e60  size 108  27 条（0x169e60..0x169ecc）
 * @func 0x169e60 0x169ecc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Draw_Set_Color4(int, int, int, float)+0x40 / GR_RGBA_To_D3DColor(int, int, int, unsigned int)
 * 字段偏移 top8: 0x40×1 / 0x30×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169e60 vmov.f32 s14, #1.000000e+00
 *   @0x169e64 vmov s15, r3
 *   @0x169e68 push {r3, lr}
 *   @0x169e6c vcmpe.f32 s15, s14
 *   @0x169e70 vmrs APSR_nzcv, fpscr
 *   @0x169e74 movgt lr, #255
 *   @0x169e78 ble 0x169ea0 <_Z18GR_Draw_Set_Color4iiif+0x40>
 *   @0x169e7c ldr r12, [pc, #0x40]
 *   @0x169e80 mov r3, lr
 *   @0x169e84 ldr r12, [pc, r12]
 *   @0x169e88 str lr, [r12]
 *   @0x169e8c bl 0x16ca74 <_Z19GR_RGBA_To_D3DColoriiij>
 *   @0x169e90 ldr r3, [pc, #0x30]
 *   @0x169e94 ldr r3, [pc, r3]
 *   @0x169e98 str r0, [r3]
 *   @0x169e9c pop {r3, pc}
 *   @0x169ea0 vcmpe.f32 s15, #0
 *   @0x169ea4 vmrs APSR_nzcv, fpscr
 *   @0x169ea8 vldrpl s14, [pc, #16]
 *   @0x169eac vmulpl.f32 s15, s15, s14
 *   @0x169eb0 movmi lr, #0
 *   @0x169eb4 vcvtpl.u32.f32 s15, s15
 *   @0x169eb8 vmovpl lr, s15
 *   @0x169ebc b 0x169e7c <_Z18GR_Draw_Set_Color4iiif+0x1c>
 *   @0x169ec0 cmnmi pc, #0
 *   @0x169ec4 eoreq r3, r8, r12, ror lr
 *   @0x169ec8 eoreq r3, r8, r8, ror #28
 *
 * ══ §125/281 GR_Window_Views_Mouse_Set(int, int)  0x17ac80  size 108  27 条（0x17ac80..0x17acec）
 * @func 0x17ac80 0x17acec  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17ac80 ldr r3, [pc, #0x5c]
 *   @0x17ac84 mov r2, r1
 *   @0x17ac88 push {r4, r5, r6}
 *   @0x17ac8c ldr r3, [pc, r3]
 *   @0x17ac90 mov r6, r0
 *   @0x17ac94 ldr r3, [r3]
 *   @0x17ac98 cmp r3, #0
 *   @0x17ac9c beq 0x17acdc <_Z25GR_Window_Views_Mouse_Setii+0x5c>
 *   @0x17aca0 ldr r5, [pc, #0x40]
 *   @0x17aca4 mov r3, #0
 *   @0x17aca8 mov r0, r3
 *   @0x17acac ldr r5, [pc, r5]
 *   @0x17acb0 b 0x17acc0 <_Z25GR_Window_Views_Mouse_Setii+0x40>
 *   @0x17acb4 add r0, r0, #1
 *   @0x17acb8 cmp r0, #32
 *   @0x17acbc beq 0x17acdc <_Z25GR_Window_Views_Mouse_Setii+0x5c>
 *   @0x17acc0 ldrb r4, [r5, r3]
 *   @0x17acc4 add r3, r3, #48
 *   @0x17acc8 cmp r4, #0
 *   @0x17accc beq 0x17acb4 <_Z25GR_Window_Views_Mouse_Setii+0x34>
 *   @0x17acd0 mov r1, r6
 *   @0x17acd4 pop {r4, r5, r6}
 *   @0x17acd8 b 0x17aae0 <_Z24GR_Window_View_Mouse_Setiii>
 *   @0x17acdc pop {r4, r5, r6}
 *   @0x17ace0 bx lr
 *   @0x17ace4 eoreq r5, r7, r8, ror r6
 *   @0x17ace8 eoreq r5, r7, r4, asr r6
 *
 * ══ §126/281 GraphicsPerf::strwidth(char const*, int)  0x17c49c  size 108  27 条（0x17c49c..0x17c508）
 * @func 0x17c49c 0x17c508  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GraphicsPerf::strwidth(char const*, int)+0x60
 * 字段偏移 top8: 0x-4×1 / 0x48×1 / 0x1×1 / 0x-7e×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c49c str r4, [sp, #-0x4]!
 *   @0x17c4a0 ldrb r3, [r0]
 *   @0x17c4a4 cmp r3, #0
 *   @0x17c4a8 beq 0x17c4f4 <_ZN12GraphicsPerf8strwidthEPKci+0x58>
 *   @0x17c4ac cmp r1, #0
 *   @0x17c4b0 ble 0x17c4fc <_ZN12GraphicsPerf8strwidthEPKci+0x60>
 *   @0x17c4b4 ldr r4, [pc, #0x48]
 *   @0x17c4b8 mov r2, r0
 *   @0x17c4bc add r1, r0, r1
 *   @0x17c4c0 mov r0, #0
 *   @0x17c4c4 ldr r4, [pc, r4]
 *   @0x17c4c8 b 0x17c4d4 <_ZN12GraphicsPerf8strwidthEPKci+0x38>
 *   @0x17c4cc cmp r2, r1
 *   @0x17c4d0 beq 0x17c4ec <_ZN12GraphicsPerf8strwidthEPKci+0x50>
 *   @0x17c4d4 add r12, r4, r3, lsl #2
 *   @0x17c4d8 ldrb r3, [r2, #0x1]!
 *   @0x17c4dc ldrb r12, [r12, #-0x7e]
 *   @0x17c4e0 cmp r3, #0
 *   @0x17c4e4 add r0, r0, r12
 *   @0x17c4e8 bne 0x17c4cc <_ZN12GraphicsPerf8strwidthEPKci+0x30>
 *   @0x17c4ec ldr r4, [sp], #4
 *   @0x17c4f0 bx lr
 *   @0x17c4f4 mov r0, r3
 *   @0x17c4f8 b 0x17c4ec <_ZN12GraphicsPerf8strwidthEPKci+0x50>
 *   @0x17c4fc mov r0, #0
 *   @0x17c500 b 0x17c4ec <_ZN12GraphicsPerf8strwidthEPKci+0x50>
 *   @0x17c504 .word 0x00273dd8
 *
 * ══ §127/281 AllocateVirtualKey()  0x18c590  size 108  27 条（0x18c590..0x18c5fc）
 * @func 0x18c590 0x18c5fc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocateVirtualKey()+0x54
 * 字段偏移 top8: 0x5c×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c590 ldr r3, [pc, #0x5c]
 *   @0x18c594 ldr r3, [pc, r3]
 *   @0x18c598 ldr r12, [r3]
 *   @0x18c59c cmp r12, #0
 *   @0x18c5a0 ble 0x18c5e4 <_Z18AllocateVirtualKeyv+0x54>
 *   @0x18c5a4 ldr r3, [pc, #0x4c]
 *   @0x18c5a8 ldr r3, [pc, r3]
 *   @0x18c5ac ldr r2, [r3]
 *   @0x18c5b0 ldrsh r3, [r2]
 *   @0x18c5b4 cmp r3, #0
 *   @0x18c5b8 beq 0x18c5ec <_Z18AllocateVirtualKeyv+0x5c>
 *   @0x18c5bc add r2, r2, #44
 *   @0x18c5c0 mov r3, #0
 *   @0x18c5c4 b 0x18c5d4 <_Z18AllocateVirtualKeyv+0x44>
 *   @0x18c5c8 ldrsh r1, [r2], #44
 *   @0x18c5cc cmp r1, #0
 *   @0x18c5d0 bxeq lr
 *   @0x18c5d4 add r3, r3, #1
 *   @0x18c5d8 mov r0, r2
 *   @0x18c5dc cmp r3, r12
 *   @0x18c5e0 bne 0x18c5c8 <_Z18AllocateVirtualKeyv+0x38>
 *   @0x18c5e4 mov r0, #0
 *   @0x18c5e8 bx lr
 *   @0x18c5ec mov r0, r2
 *   @0x18c5f0 bx lr
 *   @0x18c5f4 .word 0x002635bc
 *   @0x18c5f8 eoreq r3, r6, r12, lsr #11
 *
 * ══ §128/281 LoadSave::fclose(_YYFILE*)  0x18ddb8  size 108  27 条（0x18ddb8..0x18de24）
 * @func 0x18ddb8 0x18de24  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0xc×1 / 0x20×1 / 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ddb8 ldrb r3, [r0, #0xc]
 *   @0x18ddbc push {r4, lr}
 *   @0x18ddc0 cmp r3, #0
 *   @0x18ddc4 mov r4, r0
 *   @0x18ddc8 beq 0x18ddf0 <_ZN8LoadSave6fcloseEP7_YYFILE+0x38>
 *   @0x18ddcc ldr r1, [r0, #0x8]
 *   @0x18ddd0 cmp r1, #0
 *   @0x18ddd4 beq 0x18de00 <_ZN8LoadSave6fcloseEP7_YYFILE+0x48>
 *   @0x18ddd8 ldr r0, [r0]
 *   @0x18dddc mov r2, #0
 *   @0x18dde0 ldr r12, [r0]
 *   @0x18dde4 ldr r3, [r0, #0x20]
 *   @0x18dde8 ldr r12, [r12, #0x1c]
 *   @0x18ddec blx r12
 *   @0x18ddf0 ldr r0, [r4, #0x8]
 *   @0x18ddf4 cmp r0, #0
 *   @0x18ddf8 beq 0x18de00 <_ZN8LoadSave6fcloseEP7_YYFILE+0x48>
 *   @0x18ddfc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18de00 ldr r0, [r4]
 *   @0x18de04 cmp r0, #0
 *   @0x18de08 beq 0x18de18 <_ZN8LoadSave6fcloseEP7_YYFILE+0x60>
 *   @0x18de0c ldr r3, [r0]
 *   @0x18de10 ldr r3, [r3, #0x4]
 *   @0x18de14 blx r3
 *   @0x18de18 mov r0, r4
 *   @0x18de1c pop {r4, lr}
 *   @0x18de20 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §129/281 TranslateGamepadAxisM(int, int)  0x190b44  size 108  27 条（0x190b44..0x190bb0）
 * @func 0x190b44 0x190bb0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TranslateGamepadAxisM(int, int)+0x38
 * 字段偏移 top8: 0x40×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190b44 cmp r1, #32768
 *   @0x190b48 blt 0x190b7c <_Z21TranslateGamepadAxisMii+0x38>
 *   @0x190b4c cmp r0, #0
 *   @0x190b50 beq 0x190b84 <_Z21TranslateGamepadAxisMii+0x40>
 *   @0x190b54 cmp r0, #63
 *   @0x190b58 bgt 0x190ba4 <_Z21TranslateGamepadAxisMii+0x60>
 *   @0x190b5c add r0, r0, r0, lsl #1
 *   @0x190b60 sub r1, r1, #32768
 *   @0x190b64 ldr r3, [pc, #0x40]
 *   @0x190b68 rsb r0, r0, r0, lsl #3
 *   @0x190b6c add r1, r0, r1
 *   @0x190b70 add r3, pc, r3
 *   @0x190b74 add r0, r3, r1, lsl #2
 *   @0x190b78 ldr r1, [r0, #0x1c]
 *   @0x190b7c mov r0, r1
 *   @0x190b80 bx lr
 *   @0x190b84 sub r1, r1, #32768
 *   @0x190b88 movw r3, #0x8001
 *   @0x190b8c sub r1, r1, #17
 *   @0x190b90 cmp r1, #1
 *   @0x190b94 mvnhi r1, #0
 *   @0x190b98 movls r1, r3
 *   @0x190b9c mov r0, r1
 *   @0x190ba0 bx lr
 *   @0x190ba4 mvn r1, #0
 *   @0x190ba8 b 0x190b7c <_Z21TranslateGamepadAxisMii+0x38>
 *   @0x190bac ldrhteq r4, [r10], -r8
 *
 * ══ §130/281 CInstance::AddTo_Speed(float, float)  0x193ec0  size 108  27 条（0x193ec0..0x193f2c）
 * @func 0x193ec0 0x193f2c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb658c / 0xb6580
 * 字段偏移 top8: 无
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x193ec0 vmov s14, r1
 *   @0x193ec4 vldr s15, [pc, #88]
 *   @0x193ec8 push {r4, lr}
 *   @0x193ecc vpush {d8}
 *   @0x193ed0 vldr s17, [pc, #80]
 *   @0x193ed4 vmul.f32 s17, s14, s17
 *   @0x193ed8 mov r4, r0
 *   @0x193edc vmov s16, r2
 *   @0x193ee0 vdiv.f32 s17, s17, s15
 *   @0x193ee4 vmov r0, s17
 *   @0x193ee8 bl 0xb658c <cosf@plt>
 *   @0x193eec vldr s15, [r4, #224]
 *   @0x193ef0 vmov s14, r0
 *   @0x193ef4 vmov r0, s17
 *   @0x193ef8 vmla.f32 s15, s14, s16
 *   @0x193efc vstr s15, [r4, #224]
 *   @0x193f00 bl 0xb6580 <sinf@plt>
 *   @0x193f04 vldr s15, [r4, #228]
 *   @0x193f08 vmov s14, r0
 *   @0x193f0c mov r0, r4
 *   @0x193f10 vmls.f32 s15, s14, s16
 *   @0x193f14 vpop {d8}
 *   @0x193f18 vstr s15, [r4, #228]
 *   @0x193f1c pop {r4, lr}
 *   @0x193f20 b 0x1928d8 <_ZN9CInstance14Compute_Speed1Ev>
 *   @0x193f24 teqmi r4, #0
 *   @0x193f28 ldrdmi r0, r1, [r9], #-251
 *
 * ══ §131/281 YYObjectBase::Add(char const*, double, int)  0x1999d0  size 108  27 条（0x1999d0..0x199a3c）
 * @func 0x1999d0 0x199a4c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1999d0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1999d4 mov r4, r1
 *   @0x1999d8 mov r6, r2
 *   @0x1999dc mov r5, r3
 *   @0x1999e0 mov r7, r0
 *   @0x1999e4 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x1999e8 cmp r0, #0
 *   @0x1999ec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1999f0 mov r1, r4
 *   @0x1999f4 mov r0, r7
 *   @0x1999f8 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x1999fc ldr r3, [r0, #0xc]
 *   @0x199a00 mov r4, r0
 *   @0x199a04 sub r3, r3, #1
 *   @0x199a08 bic r3, r3, #-16777216
 *   @0x199a0c bic r3, r3, #3
 *   @0x199a10 cmp r3, #0
 *   @0x199a14 beq 0x199a34 <_ZN12YYObjectBase3AddEPKcdi+0x64>
 *   @0x199a18 ldr r2, [sp, #0x18]
 *   @0x199a1c mov r3, #0
 *   @0x199a20 str r6, [r4]
 *   @0x199a24 str r5, [r4, #0x4]
 *   @0x199a28 str r2, [r4, #0x8]
 *   @0x199a2c str r3, [r4, #0xc]
 *   @0x199a30 pop {r3, r4, r5, r6, r7, pc}
 *   @0x199a34 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x199a38 b 0x199a18 <_ZN12YYObjectBase3AddEPKcdi+0x48>
 *
 * ══ §132/281 YYObjectBase::Add(char const*, long long, int)  0x199a3c  size 108  27 条（0x199a3c..0x199aa8）
 * @func 0x199a3c 0x199aa8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199a3c push {r3, r4, r5, r6, r7, lr}
 *   @0x199a40 mov r4, r1
 *   @0x199a44 mov r6, r2
 *   @0x199a48 mov r5, r3
 *   @0x199a4c mov r7, r0
 *   @0x199a50 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x199a54 cmp r0, #0
 *   @0x199a58 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x199a5c mov r1, r4
 *   @0x199a60 mov r0, r7
 *   @0x199a64 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x199a68 ldr r3, [r0, #0xc]
 *   @0x199a6c mov r4, r0
 *   @0x199a70 sub r3, r3, #1
 *   @0x199a74 bic r3, r3, #-16777216
 *   @0x199a78 bic r3, r3, #3
 *   @0x199a7c cmp r3, #0
 *   @0x199a80 beq 0x199aa0 <_ZN12YYObjectBase3AddEPKcxi+0x64>
 *   @0x199a84 ldr r2, [sp, #0x18]
 *   @0x199a88 mov r3, #10
 *   @0x199a8c str r6, [r4]
 *   @0x199a90 str r5, [r4, #0x4]
 *   @0x199a94 str r2, [r4, #0x8]
 *   @0x199a98 str r3, [r4, #0xc]
 *   @0x199a9c pop {r3, r4, r5, r6, r7, pc}
 *   @0x199aa0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x199aa4 b 0x199a84 <_ZN12YYObjectBase3AddEPKcxi+0x48>
 *
 * ══ §133/281 CreateDesktopWindow(int, int)  0x1a8854  size 108  27 条（0x1a8854..0x1a88c0）
 * @func 0x1a8854 0x1a88c0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a885c→0x542550, 0x1a8868→0x54254c, 0x1a8870→0x3f50a0, 0x1a8874→0x3f509c, 0x1a8880→0x542554
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×2 / 0x4c×1 / 0x48×1 / 0x40×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8854 ldr r3, [pc, #0x4c]
 *   @0x1a8858 mov r2, #0
 *   @0x1a885c ldr r12, [pc, #0x48]
 *   @0x1a8860 add r3, pc, r3
 *   @0x1a8864 push {r4, r5, r6, r7}
 *   @0x1a8868 ldr r6, [pc, #0x40]
 *   @0x1a886c ldr r7, [r3, r12]
 *   @0x1a8870 ldr r5, [pc, #0x3c]
 *   @0x1a8874 ldr r4, [pc, #0x3c]
 *   @0x1a8878 str r2, [r7]
 *   @0x1a887c ldr r6, [r3, r6]
 *   @0x1a8880 ldr r12, [pc, #0x34]
 *   @0x1a8884 str r2, [r6]
 *   @0x1a8888 ldr r5, [r3, r5]
 *   @0x1a888c str r0, [r5]
 *   @0x1a8890 ldr r0, [r3, r4]
 *   @0x1a8894 pop {r4, r5, r6, r7}
 *   @0x1a8898 str r1, [r0]
 *   @0x1a889c ldr r3, [r3, r12]
 *   @0x1a88a0 str r2, [r3]
 *   @0x1a88a4 bx lr
 *   @0x1a88a8 .word 0x002493f0
 *   @0x1a88ac .word 0xffffeb94
 *   @0x1a88b0 .word 0xffffeb98
 *   @0x1a88b4 .word 0xffffeb9c
 *   @0x1a88b8 .word 0xffffeba0
 *   @0x1a88bc .word 0xffffeba4
 *
 * ══ §134/281 RTree<CInstance*, int, float, 6, 2>::~RTree()  0x1cbdec  size 108  27 条（0x1cbdec..0x1cbe58）
 * @func 0x1cbdec 0x1cbe58  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / RTree<CInstance*, int, float, 6, 2>::~RTree()+0x50 / RTree<CInstance*, int, float, 6, 2>::~RTree()+0x34 / operator delete(void*)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x54×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cbdec push {r4, r5, r6, lr}
 *   @0x1cbdf0 mov r6, r0
 *   @0x1cbdf4 ldr r5, [r0, #0x4]
 *   @0x1cbdf8 ldr r3, [pc, #0x54]
 *   @0x1cbdfc cmp r5, #0
 *   @0x1cbe00 ldr r3, [pc, r3]
 *   @0x1cbe04 add r3, r3, #8
 *   @0x1cbe08 str r3, [r0]
 *   @0x1cbe0c beq 0x1cbe4c <_ZN5RTreeIP9CInstanceifLi6ELi2EED2Ev+0x60>
 *   @0x1cbe10 ldr r3, [r5, #0x8]
 *   @0x1cbe14 cmp r3, #0
 *   @0x1cbe18 movgt r4, #0
 *   @0x1cbe1c ble 0x1cbe3c <_ZN5RTreeIP9CInstanceifLi6ELi2EED2Ev+0x50>
 *   @0x1cbe20 ldr r3, [r5, #0x4]
 *   @0x1cbe24 ldr r0, [r3, r4, lsl #2]
 *   @0x1cbe28 add r4, r4, #1
 *   @0x1cbe2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1cbe30 ldr r3, [r5, #0x8]
 *   @0x1cbe34 cmp r4, r3
 *   @0x1cbe38 blt 0x1cbe20 <_ZN5RTreeIP9CInstanceifLi6ELi2EED2Ev+0x34>
 *   @0x1cbe3c ldr r0, [r5, #0x4]
 *   @0x1cbe40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1cbe44 mov r0, r5
 *   @0x1cbe48 bl 0x27d1d0 <_ZdlPv>
 *   @0x1cbe4c mov r0, r6
 *   @0x1cbe50 pop {r4, r5, r6, pc}
 *   @0x1cbe54 eoreq r4, r2, r12, lsr #26
 *
 * ══ §135/281 cARRAY_CLASS_NO_DELETE<CInstance*>::~cARRAY_CLASS_NO_DELETE()  0x1d16b8  size 108  27 条（0x1d16b8..0x1d1724）
 * @func 0x1d16b8 0x1d1724  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / cARRAY_CLASS_NO_DELETE<CInstance*>::~cARRAY_CLASS_NO_DELETE()+0x3c
 * 字段偏移 top8: 0x4×4 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d16b8 push {r3, r4, r5, lr}
 *   @0x1d16bc mov r5, r0
 *   @0x1d16c0 ldr r4, [r0, #0x4]
 *   @0x1d16c4 cmp r4, #0
 *   @0x1d16c8 beq 0x1d1714 <_ZN22cARRAY_CLASS_NO_DELETEIP9CInstanceED2Ev+0x5c>
 *   @0x1d16cc ldr r2, [r0]
 *   @0x1d16d0 cmp r2, #0
 *   @0x1d16d4 ble 0x1d16f4 <_ZN22cARRAY_CLASS_NO_DELETEIP9CInstanceED2Ev+0x3c>
 *   @0x1d16d8 mov r3, #0
 *   @0x1d16dc mov r1, r3
 *   @0x1d16e0 str r1, [r4, r3, lsl #2]
 *   @0x1d16e4 add r3, r3, #1
 *   @0x1d16e8 cmp r3, r2
 *   @0x1d16ec ldr r4, [r5, #0x4]
 *   @0x1d16f0 bne 0x1d16e0 <_ZN22cARRAY_CLASS_NO_DELETEIP9CInstanceED2Ev+0x28>
 *   @0x1d16f4 mov r0, r4
 *   @0x1d16f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d16fc mov r3, #0
 *   @0x1d1700 str r3, [r5, #0x4]
 *   @0x1d1704 mov r3, #0
 *   @0x1d1708 mov r0, r5
 *   @0x1d170c str r3, [r5]
 *   @0x1d1710 pop {r3, r4, r5, pc}
 *   @0x1d1714 mov r0, r4
 *   @0x1d1718 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d171c str r4, [r5, #0x4]
 *   @0x1d1720 b 0x1d1704 <_ZN22cARRAY_CLASS_NO_DELETEIP9CInstanceED2Ev+0x4c>
 *
 * ══ §136/281 DecodeString(char*)  0x1d222c  size 108  27 条（0x1d222c..0x1d2298）
 * @func 0x1d222c 0x1d2298  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×2 / 0x5c×1 / 0x58×1 / 0x-4×1 / 0xb×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d222c ldr r3, [pc, #0x5c]
 *   @0x1d2230 mov r1, r0
 *   @0x1d2234 ldr r2, [pc, #0x58]
 *   @0x1d2238 ldr r3, [pc, r3]
 *   @0x1d223c str r4, [sp, #-0x4]!
 *   @0x1d2240 ldr r2, [pc, r2]
 *   @0x1d2244 ldr r12, [r3]
 *   @0x1d2248 add r4, r12, #1
 *   @0x1d224c cmp r4, #3
 *   @0x1d2250 add r0, r2, r12, lsl #11
 *   @0x1d2254 movgt r4, #0
 *   @0x1d2258 str r4, [r3]
 *   @0x1d225c mov r3, #0
 *   @0x1d2260 strb r3, [r2, r12, lsl #11]
 *   @0x1d2264 ldrb r3, [r1]
 *   @0x1d2268 cmp r3, #0
 *   @0x1d226c beq 0x1d2288 <_Z12DecodeStringPc+0x5c>
 *   @0x1d2270 mov r2, r0
 *   @0x1d2274 eor r3, r3, #26
 *   @0x1d2278 strb r3, [r2], #1
 *   @0x1d227c ldrb r3, [r1, #0x1]!
 *   @0x1d2280 cmp r3, #0
 *   @0x1d2284 bne 0x1d2274 <_Z12DecodeStringPc+0x48>
 *   @0x1d2288 ldr r4, [sp], #4
 *   @0x1d228c bx lr
 *   @0x1d2290 eoreq lr, r1, r4, lsl r9
 *   @0x1d2294 eoreq lr, r1, r0, lsl r9
 *
 * ══ §137/281 CVariableList::Alloc(int)  0x1f50cc  size 108  27 条（0x1f50cc..0x1f5138）
 * @func 0x1f50cc 0x1f5138  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / RVariable::RVariable(int)
 * 字段偏移 top8: 0x58×1 / 0x4×1 / 0x8×1 / 0x18×1 / 0x1c×1 / 0x24×1 / 0x14×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f50cc push {r3, r4, r5, lr}
 *   @0x1f50d0 mov r5, r0
 *   @0x1f50d4 ldr r3, [pc, #0x58]
 *   @0x1f50d8 ldr r3, [pc, r3]
 *   @0x1f50dc ldr r4, [r3]
 *   @0x1f50e0 cmp r4, #0
 *   @0x1f50e4 beq 0x1f511c <_ZN13CVariableList5AllocEi+0x50>
 *   @0x1f50e8 ldr r0, [r4, #0x4]
 *   @0x1f50ec mov r2, #0
 *   @0x1f50f0 mov r1, #7
 *   @0x1f50f4 str r5, [r4, #0x8]
 *   @0x1f50f8 str r2, [r4, #0x18]
 *   @0x1f50fc str r0, [r3]
 *   @0x1f5100 str r2, [r4, #0x1c]
 *   @0x1f5104 str r2, [r4, #0x24]
 *   @0x1f5108 str r1, [r4, #0x14]
 *   @0x1f510c and r5, r5, #3
 *   @0x1f5110 mov r0, r4
 *   @0x1f5114 str r5, [r4, #0x28]
 *   @0x1f5118 pop {r3, r4, r5, pc}
 *   @0x1f511c mov r0, #44
 *   @0x1f5120 bl 0x27c524 <_Znwj>
 *   @0x1f5124 mov r1, r5
 *   @0x1f5128 mov r4, r0
 *   @0x1f512c bl 0x1f50a4 <_ZN9RVariableC2Ei>
 *   @0x1f5130 b 0x1f510c <_ZN13CVariableList5AllocEi+0x40>
 *   @0x1f5134 andseq r11, pc, r12, asr sp
 *
 * ══ §138/281 SV_PhysicsAngularDamping(CInstance*, int, RValue*)  0x1feafc  size 108  27 条（0x1feafc..0x1feb68）
 * @func 0x1feafc 0x1feb78  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1feafc push {r3, r4, r6, r7, r8, lr}
 *   @0x1feb00 mov r1, #1
 *   @0x1feb04 mov r6, r2
 *   @0x1feb08 mov r2, #0
 *   @0x1feb0c mov r4, r0
 *   @0x1feb10 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1feb14 subs r7, r0, #0
 *   @0x1feb18 beq 0x1feb4c <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x50>
 *   @0x1feb1c ldr r8, [r4, #0x84]
 *   @0x1feb20 cmp r8, #0
 *   @0x1feb24 beq 0x1feb60 <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x64>
 *   @0x1feb28 ldr r3, [r6, #0xc]
 *   @0x1feb2c bic r3, r3, #-16777216
 *   @0x1feb30 cmp r3, #0
 *   @0x1feb34 bne 0x1feb54 <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x58>
 *   @0x1feb38 ldm r6, {r0, r1}
 *   @0x1feb3c vmov d6, r0, r1
 *   @0x1feb40 ldr r3, [r8]
 *   @0x1feb44 vcvt.f32.f64 s15, d6
 *   @0x1feb48 vstr s15, [r3, #152]
 *   @0x1feb4c mov r0, r7
 *   @0x1feb50 pop {r3, r4, r6, r7, r8, pc}
 *   @0x1feb54 mov r0, r6
 *   @0x1feb58 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1feb5c b 0x1feb3c <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x40>
 *   @0x1feb60 mov r7, r8
 *   @0x1feb64 b 0x1feb4c <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x50>
 *
 * ══ §139/281 SV_PhysicsLinearDamping(CInstance*, int, RValue*)  0x1feb68  size 108  27 条（0x1feb68..0x1febd4）
 * @func 0x1feb68 0x1febd4  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1feb68 push {r3, r4, r6, r7, r8, lr}
 *   @0x1feb6c mov r1, #1
 *   @0x1feb70 mov r6, r2
 *   @0x1feb74 mov r2, #0
 *   @0x1feb78 mov r4, r0
 *   @0x1feb7c bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1feb80 subs r7, r0, #0
 *   @0x1feb84 beq 0x1febb8 <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x50>
 *   @0x1feb88 ldr r8, [r4, #0x84]
 *   @0x1feb8c cmp r8, #0
 *   @0x1feb90 beq 0x1febcc <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x64>
 *   @0x1feb94 ldr r3, [r6, #0xc]
 *   @0x1feb98 bic r3, r3, #-16777216
 *   @0x1feb9c cmp r3, #0
 *   @0x1feba0 bne 0x1febc0 <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x58>
 *   @0x1feba4 ldm r6, {r0, r1}
 *   @0x1feba8 vmov d6, r0, r1
 *   @0x1febac ldr r3, [r8]
 *   @0x1febb0 vcvt.f32.f64 s15, d6
 *   @0x1febb4 vstr s15, [r3, #148]
 *   @0x1febb8 mov r0, r7
 *   @0x1febbc pop {r3, r4, r6, r7, r8, pc}
 *   @0x1febc0 mov r0, r6
 *   @0x1febc4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1febc8 b 0x1feba8 <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x40>
 *   @0x1febcc mov r7, r8
 *   @0x1febd0 b 0x1febb8 <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x50>
 *
 * ══ §140/281 CStream::Seek(int, short)  0x201284  size 108  27 条（0x201284..0x2012f0）
 * @func 0x201284 0x2012f0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201284 cmp r2, #1
 *   @0x201288 mov r12, r0
 *   @0x20128c push {r4, r5}
 *   @0x201290 beq 0x2012b8 <_ZN7CStream4SeekEis+0x34>
 *   @0x201294 cmp r2, #2
 *   @0x201298 beq 0x2012d4 <_ZN7CStream4SeekEis+0x50>
 *   @0x20129c cmp r2, #0
 *   @0x2012a0 streq r1, [r12, #0x10]
 *   @0x2012a4 streq r2, [r12, #0x14]
 *   @0x2012a8 ldrne r0, [r0, #0x10]
 *   @0x2012ac moveq r0, r1
 *   @0x2012b0 pop {r4, r5}
 *   @0x2012b4 bx lr
 *   @0x2012b8 ldrd r4, r5, [r0, #16]
 *   @0x2012bc adds r2, r4, r1
 *   @0x2012c0 adc r3, r5, r1, asr #31
 *   @0x2012c4 strd r2, r3, [r0, #16]
 *   @0x2012c8 pop {r4, r5}
 *   @0x2012cc mov r0, r2
 *   @0x2012d0 bx lr
 *   @0x2012d4 ldr r0, [r0, #0x8]
 *   @0x2012d8 mov r3, #0
 *   @0x2012dc pop {r4, r5}
 *   @0x2012e0 add r0, r1, r0
 *   @0x2012e4 str r3, [r12, #0x14]
 *   @0x2012e8 str r0, [r12, #0x10]
 *   @0x2012ec bx lr
 *
 * ══ §141/281 CStream::ReadReal()  0x20187c  size 108  27 条（0x20187c..0x2018e8）
 * @func 0x20187c 0x2018f8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadReal()+0x58
 * 字段偏移 top8: 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20187c ldrd r2, r3, [r0, #16]
 *   @0x201880 ldr r1, [r0, #0x8]
 *   @0x201884 push {r4, r5}
 *   @0x201888 cmp r1, r2
 *   @0x20188c sub sp, sp, #8
 *   @0x201890 mov r4, #0
 *   @0x201894 mov r5, #0
 *   @0x201898 ldr r12, [r0, #0x18]
 *   @0x20189c strd r4, r5, [sp]
 *   @0x2018a0 ble 0x2018d4 <_ZN7CStream8ReadRealEv+0x58>
 *   @0x2018a4 add r5, r12, r2
 *   @0x2018a8 mov r4, sp
 *   @0x2018ac mov r1, #0
 *   @0x2018b0 ldrb r12, [r5, r1]
 *   @0x2018b4 strb r12, [r4, r1]
 *   @0x2018b8 add r1, r1, #1
 *   @0x2018bc cmp r1, #8
 *   @0x2018c0 bne 0x2018b0 <_ZN7CStream8ReadRealEv+0x34>
 *   @0x2018c4 ldrd r4, r5, [sp]
 *   @0x2018c8 adds r2, r2, #8
 *   @0x2018cc adc r3, r3, #0
 *   @0x2018d0 strd r2, r3, [r0, #16]
 *   @0x2018d4 mov r0, r4
 *   @0x2018d8 mov r1, r5
 *   @0x2018dc add sp, sp, #8
 *   @0x2018e0 pop {r4, r5}
 *   @0x2018e4 bx lr
 *
 * ══ §142/281 CDS_Grid::MarkOnlyChildren4GC(unsigned int*, int)  0x205240  size 108  27 条（0x205240..0x2052ac）
 * @func 0x205240 0x2052ac  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::MarkOnlyChildren4GC(unsigned int*, int)+0x5c / RVALUE_GC_THISONLY(RValue const*, unsigned int*, int)
 * 字段偏移 top8: 0x8×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x205240 push {r4, r5, r6, r7, r8, lr}
 *   @0x205244 mov r7, r1
 *   @0x205248 ldr r1, [r0, #0x8]
 *   @0x20524c mov r5, r0
 *   @0x205250 mov r8, r2
 *   @0x205254 cmp r1, #0
 *   @0x205258 pople {r4, r5, r6, r7, r8, pc}
 *   @0x20525c ldr r3, [r0, #0x4]
 *   @0x205260 mov r6, #0
 *   @0x205264 cmp r3, #0
 *   @0x205268 ble 0x20529c <_ZN8CDS_Grid19MarkOnlyChildren4GCEPji+0x5c>
 *   @0x20526c mov r4, #0
 *   @0x205270 mla r3, r3, r6, r4
 *   @0x205274 ldr r0, [r5]
 *   @0x205278 mov r1, r7
 *   @0x20527c mov r2, r8
 *   @0x205280 add r4, r4, #1
 *   @0x205284 add r0, r0, r3, lsl #4
 *   @0x205288 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x20528c ldr r3, [r5, #0x4]
 *   @0x205290 cmp r3, r4
 *   @0x205294 bgt 0x205270 <_ZN8CDS_Grid19MarkOnlyChildren4GCEPji+0x30>
 *   @0x205298 ldr r1, [r5, #0x8]
 *   @0x20529c add r6, r6, #1
 *   @0x2052a0 cmp r1, r6
 *   @0x2052a4 bgt 0x205264 <_ZN8CDS_Grid19MarkOnlyChildren4GCEPji+0x24>
 *   @0x2052a8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §143/281 CDS_Priority::CDS_Priority()  0x209864  size 108  27 条（0x209864..0x2098d0）
 * @func 0x209864 0x2098d0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Priority::Clear()
 * 字段偏移 top8: 0x60×1 / 0x10×1 / 0x11×1 / 0x12×1 / 0x13×1 / 0x14×1 / 0x15×1 / 0x16×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x209864 ldr r2, [pc, #0x60]
 *   @0x209868 mov r3, #0
 *   @0x20986c push {r4, lr}
 *   @0x209870 ldr r2, [pc, r2]
 *   @0x209874 mov r4, r0
 *   @0x209878 strb r3, [r0, #0x10]
 *   @0x20987c strb r3, [r0, #0x11]
 *   @0x209880 add r2, r2, #8
 *   @0x209884 strb r3, [r0, #0x12]
 *   @0x209888 str r2, [r0]
 *   @0x20988c strb r3, [r0, #0x13]
 *   @0x209890 strb r3, [r0, #0x14]
 *   @0x209894 strb r3, [r0, #0x15]
 *   @0x209898 strb r3, [r0, #0x16]
 *   @0x20989c strb r3, [r0, #0x17]
 *   @0x2098a0 strb r3, [r0, #0x8]
 *   @0x2098a4 strb r3, [r0, #0x9]
 *   @0x2098a8 strb r3, [r0, #0xa]
 *   @0x2098ac strb r3, [r0, #0xb]
 *   @0x2098b0 strb r3, [r0, #0xc]
 *   @0x2098b4 strb r3, [r0, #0xd]
 *   @0x2098b8 strb r3, [r0, #0xe]
 *   @0x2098bc strb r3, [r0, #0xf]
 *   @0x2098c0 bl 0x209768 <_ZN12CDS_Priority5ClearEv>
 *   @0x2098c4 mov r0, r4
 *   @0x2098c8 pop {r4, pc}
 *   @0x2098cc andseq r7, lr, r12, lsr #22
 *
 * ══ §144/281 Audio_NoiseIsPaused(CNoise*)  0x216450  size 108  27 条（0x216450..0x2164bc）
 * @func 0x216450 0x2164bc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a9c
 * 字段偏移 top8: 0x5×1 / 0x44×1 / 0x10×1 / 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216450 cmp r0, #0
 *   @0x216454 push {r4, lr}
 *   @0x216458 sub sp, sp, #8
 *   @0x21645c beq 0x2164a8 <_Z19Audio_NoiseIsPausedP6CNoise+0x58>
 *   @0x216460 ldrb r4, [r0, #0x5]
 *   @0x216464 cmp r4, #0
 *   @0x216468 beq 0x21649c <_Z19Audio_NoiseIsPausedP6CNoise+0x4c>
 *   @0x21646c ldr r3, [pc, #0x44]
 *   @0x216470 add r2, sp, #4
 *   @0x216474 ldr r0, [r0, #0x10]
 *   @0x216478 movw r1, #0x1010
 *   @0x21647c ldr r3, [pc, r3]
 *   @0x216480 ldr r3, [r3]
 *   @0x216484 ldr r0, [r3, r0, lsl #2]
 *   @0x216488 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x21648c ldr r2, [sp, #0x4]
 *   @0x216490 movw r3, #0x1013
 *   @0x216494 cmp r2, r3
 *   @0x216498 movne r4, #0
 *   @0x21649c mov r0, r4
 *   @0x2164a0 add sp, sp, #8
 *   @0x2164a4 pop {r4, pc}
 *   @0x2164a8 mov r4, r0
 *   @0x2164ac mov r0, r4
 *   @0x2164b0 add sp, sp, #8
 *   @0x2164b4 pop {r4, pc}
 *   @0x2164b8 andseq r10, sp, r0, asr pc
 *
 * ══ §145/281 Audio_GetEmitterPosition(int)  0x216e6c  size 108  27 条（0x216e6c..0x216ed8）
 * @func 0x216e6c 0x216ed8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetEmitterPosition(int)+0x34 / Audio_GetEmitterPosition(int)+0x4c
 * 字段偏移 top8: 0x40×2 / 0x5c×1 / 0x4×1 / 0x8×1 / 0x44×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216e6c ldr r2, [pc, #0x5c]
 *   @0x216e70 mov r3, r0
 *   @0x216e74 ldr r2, [pc, r2]
 *   @0x216e78 ldrb r2, [r2]
 *   @0x216e7c cmp r2, #0
 *   @0x216e80 beq 0x216ea0 <_Z24Audio_GetEmitterPositioni+0x34>
 *   @0x216e84 cmp r1, #0
 *   @0x216e88 blt 0x216ea0 <_Z24Audio_GetEmitterPositioni+0x34>
 *   @0x216e8c ldr r2, [pc, #0x40]
 *   @0x216e90 add r2, pc, r2
 *   @0x216e94 ldr r0, [r2, #0x40]
 *   @0x216e98 cmp r1, r0
 *   @0x216e9c blt 0x216eb8 <_Z24Audio_GetEmitterPositioni+0x4c>
 *   @0x216ea0 mov r2, #0
 *   @0x216ea4 mov r0, r3
 *   @0x216ea8 str r2, [r3]
 *   @0x216eac str r2, [r3, #0x4]
 *   @0x216eb0 str r2, [r3, #0x8]
 *   @0x216eb4 bx lr
 *   @0x216eb8 ldr r2, [r2, #0x44]
 *   @0x216ebc ldr r2, [r2, r1, lsl #2]
 *   @0x216ec0 ldm r2, {r0, r1, r2}
 *   @0x216ec4 stm r3, {r0, r1, r2}
 *   @0x216ec8 mov r0, r3
 *   @0x216ecc bx lr
 *   @0x216ed0 ldrheq r7, [sp], -r12
 *   @0x216ed4 subseq lr, r3, r4, lsl #8
 *
 * ══ §146/281 Audio_GetNoiseFromID(int)  0x216fbc  size 108  27 条（0x216fbc..0x217028）
 * @func 0x216fbc 0x217028  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetNoiseFromID(int)+0x58
 * 字段偏移 top8: 0x4×2 / 0x60×1 / 0x-4×1 / 0x38×1 / 0x3c×1 / 0x5×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216fbc ldr r3, [pc, #0x60]
 *   @0x216fc0 str r4, [sp, #-0x4]!
 *   @0x216fc4 add r3, pc, r3
 *   @0x216fc8 ldr r4, [r3, #0x38]
 *   @0x216fcc cmp r4, #0
 *   @0x216fd0 ble 0x217014 <_Z20Audio_GetNoiseFromIDi+0x58>
 *   @0x216fd4 ldr r1, [r3, #0x3c]
 *   @0x216fd8 mov r3, #0
 *   @0x216fdc sub r1, r1, #4
 *   @0x216fe0 ldr r2, [r1, #0x4]!
 *   @0x216fe4 add r3, r3, #1
 *   @0x216fe8 ldrb r12, [r2, #0x5]
 *   @0x216fec cmp r12, #0
 *   @0x216ff0 beq 0x21700c <_Z20Audio_GetNoiseFromIDi+0x50>
 *   @0x216ff4 ldr r12, [r2, #0x8]
 *   @0x216ff8 cmp r12, #0
 *   @0x216ffc bne 0x21700c <_Z20Audio_GetNoiseFromIDi+0x50>
 *   @0x217000 ldr r12, [r2, #0x14]
 *   @0x217004 cmp r12, r0
 *   @0x217008 beq 0x217018 <_Z20Audio_GetNoiseFromIDi+0x5c>
 *   @0x21700c cmp r3, r4
 *   @0x217010 bne 0x216fe0 <_Z20Audio_GetNoiseFromIDi+0x24>
 *   @0x217014 mov r2, #0
 *   @0x217018 mov r0, r2
 *   @0x21701c ldr r4, [sp], #4
 *   @0x217020 bx lr
 *   @0x217024 ldrsbeq lr, [r3], #-32
 *
 * ══ §147/281 enumerateCaptureDevices()  0x21c54c  size 108  27 条（0x21c54c..0x21c5b8）
 * @func 0x21c54c 0x21c5b8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: deviceListClear() / 0xb6b50 / deviceListAdd(char const*) / 0xb6538
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21c54c push {r3, r4, r5, lr}
 *   @0x21c550 bl 0x21c470 <_Z15deviceListClearv>
 *   @0x21c554 mov r0, #0
 *   @0x21c558 mov r1, #784
 *   @0x21c55c bl 0xb6b50 <alcGetString@plt>
 *   @0x21c560 subs r4, r0, #0
 *   @0x21c564 beq 0x21c5b0 <_Z23enumerateCaptureDevicesv+0x64>
 *   @0x21c568 ldrb r5, [r4]
 *   @0x21c56c cmp r5, #0
 *   @0x21c570 beq 0x21c5a8 <_Z23enumerateCaptureDevicesv+0x5c>
 *   @0x21c574 mov r5, #0
 *   @0x21c578 b 0x21c588 <_Z23enumerateCaptureDevicesv+0x3c>
 *   @0x21c57c ldrb r3, [r4]
 *   @0x21c580 cmp r3, #0
 *   @0x21c584 beq 0x21c5a8 <_Z23enumerateCaptureDevicesv+0x5c>
 *   @0x21c588 mov r0, r4
 *   @0x21c58c add r5, r5, #1
 *   @0x21c590 bl 0x21c2e0 <_Z13deviceListAddPKc>
 *   @0x21c594 mov r0, r4
 *   @0x21c598 bl 0xb6538 <strlen@plt>
 *   @0x21c59c add r0, r0, #1
 *   @0x21c5a0 adds r4, r4, r0
 *   @0x21c5a4 bne 0x21c57c <_Z23enumerateCaptureDevicesv+0x30>
 *   @0x21c5a8 mov r0, r5
 *   @0x21c5ac pop {r3, r4, r5, pc}
 *   @0x21c5b0 mov r5, r4
 *   @0x21c5b4 b 0x21c5a8 <_Z23enumerateCaptureDevicesv+0x5c>
 *
 * ══ §148/281 COggSyncThread::StartThread()  0x2249e0  size 108  27 条（0x2249e0..0x224a4c）
 * @func 0x2249e0 0x224a4c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CThread::Start(void* (*)(void*), void*, CThread::ePriority) / COggSyncThread::CleanUp()
 * 字段偏移 top8: 0x30×2 / 0x58×1 / 0x838×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2249e0 ldr r1, [pc, #0x58]
 *   @0x2249e4 push {r3, r4, r5, lr}
 *   @0x2249e8 mov r4, r0
 *   @0x2249ec add r0, r0, #2096
 *   @0x2249f0 mov r2, r4
 *   @0x2249f4 add r0, r0, #4
 *   @0x2249f8 add r1, pc, r1
 *   @0x2249fc mov r3, #0
 *   @0x224a00 bl 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE>
 *   @0x224a04 subs r5, r0, #0
 *   @0x224a08 bne 0x224a38 <_ZN14COggSyncThread11StartThreadEv+0x58>
 *   @0x224a0c ldr r3, [pc, #0x30]
 *   @0x224a10 ldr r1, [pc, #0x30]
 *   @0x224a14 ldr r3, [pc, r3]
 *   @0x224a18 ldr r2, [r4, #0x838]
 *   @0x224a1c add r1, pc, r1
 *   @0x224a20 ldr r0, [r3]
 *   @0x224a24 ldr r3, [r0]
 *   @0x224a28 ldr r3, [r3, #0xc]
 *   @0x224a2c blx r3
 *   @0x224a30 mov r0, r4
 *   @0x224a34 bl 0x224940 <_ZN14COggSyncThread7CleanUpEv>
 *   @0x224a38 mov r0, r5
 *   @0x224a3c pop {r3, r4, r5, pc}
 *   @0x224a40 strheq r0, [r0], -r0
 *   @0x224a44 andseq r8, r12, r0, lsl #26
 *   @0x224a48 andseq r0, r3, r12, ror #5
 *
 * ══ §149/281 res0_inverse  0x22e73c  size 108  27 条（0x22e73c..0x22e7a8）
 * @func 0x22e73c 0x22e7b8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: res0_inverse+0x44
 * 字段偏移 top8: 0xc×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22e73c push {r4, r5, r6}
 *   @0x22e740 ldr r6, [sp, #0xc]
 *   @0x22e744 cmp r6, #0
 *   @0x22e748 ble 0x22e780 <res0_inverse+0x44>
 *   @0x22e74c mov r12, #0
 *   @0x22e750 lsl r6, r6, #2
 *   @0x22e754 mov r5, r12
 *   @0x22e758 ldr r4, [r3, r12]
 *   @0x22e75c cmp r4, #0
 *   @0x22e760 ldrne r4, [r2, r12]
 *   @0x22e764 add r12, r12, #4
 *   @0x22e768 strne r4, [r2, r5, lsl #2]
 *   @0x22e76c addne r5, r5, #1
 *   @0x22e770 cmp r12, r6
 *   @0x22e774 bne 0x22e758 <res0_inverse+0x1c>
 *   @0x22e778 cmp r5, #0
 *   @0x22e77c bne 0x22e78c <res0_inverse+0x50>
 *   @0x22e780 mov r0, #0
 *   @0x22e784 pop {r4, r5, r6}
 *   @0x22e788 bx lr
 *   @0x22e78c ldr r12, [pc, #0x10]
 *   @0x22e790 mov r3, r5
 *   @0x22e794 ldr r12, [pc, r12]
 *   @0x22e798 str r12, [sp, #0xc]
 *   @0x22e79c pop {r4, r5, r6}
 *   @0x22e7a0 b 0x22e430 <res0_look+0x258>
 *   @0x22e7a4 ldrsheq r2, [r12], -r8
 *
 * ══ §150/281 res1_inverse  0x22e7a8  size 108  27 条（0x22e7a8..0x22e814）
 * @func 0x22e7a8 0x22e814  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: res1_inverse+0x44
 * 字段偏移 top8: 0xc×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22e7a8 push {r4, r5, r6}
 *   @0x22e7ac ldr r6, [sp, #0xc]
 *   @0x22e7b0 cmp r6, #0
 *   @0x22e7b4 ble 0x22e7ec <res1_inverse+0x44>
 *   @0x22e7b8 mov r12, #0
 *   @0x22e7bc lsl r6, r6, #2
 *   @0x22e7c0 mov r5, r12
 *   @0x22e7c4 ldr r4, [r3, r12]
 *   @0x22e7c8 cmp r4, #0
 *   @0x22e7cc ldrne r4, [r2, r12]
 *   @0x22e7d0 add r12, r12, #4
 *   @0x22e7d4 strne r4, [r2, r5, lsl #2]
 *   @0x22e7d8 addne r5, r5, #1
 *   @0x22e7dc cmp r12, r6
 *   @0x22e7e0 bne 0x22e7c4 <res1_inverse+0x1c>
 *   @0x22e7e4 cmp r5, #0
 *   @0x22e7e8 bne 0x22e7f8 <res1_inverse+0x50>
 *   @0x22e7ec mov r0, #0
 *   @0x22e7f0 pop {r4, r5, r6}
 *   @0x22e7f4 bx lr
 *   @0x22e7f8 ldr r12, [pc, #0x10]
 *   @0x22e7fc mov r3, r5
 *   @0x22e800 ldr r12, [pc, r12]
 *   @0x22e804 str r12, [sp, #0xc]
 *   @0x22e808 pop {r4, r5, r6}
 *   @0x22e80c b 0x22e430 <res0_look+0x258>
 *   @0x22e810 mulseq r12, r0, r12
 *
 * ══ §151/281 ov_bitrate_instant  0x231214  size 108  27 条（0x231214..0x231280）
 * @func 0x231214 0x231280  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_bitrate_instant+0x64 / anon_319414
 * 字段偏移 top8: 0x4×1 / 0x58×1 / 0x48×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231214 push {r3, r4, r5, lr}
 *   @0x231218 mov r4, r0
 *   @0x23121c ldr r3, [r0, #0x4]
 *   @0x231220 ldr r2, [r0, #0x58]
 *   @0x231224 cmp r3, #0
 *   @0x231228 ldrne r5, [r0, #0x60]
 *   @0x23122c moveq r5, r3
 *   @0x231230 cmp r2, #1
 *   @0x231234 ble 0x231278 <ov_bitrate_instant+0x64>
 *   @0x231238 ldrd r2, r3, [r0, #112]
 *   @0x23123c orrs r1, r2, r3
 *   @0x231240 beq 0x231270 <ov_bitrate_instant+0x5c>
 *   @0x231244 ldrd r0, r1, [r0, #104]
 *   @0x231248 bl 0x319414 <__aeabi_ldivmod>
 *   @0x23124c ldr r1, [r4, #0x48]
 *   @0x231250 mov r2, #0
 *   @0x231254 mov r3, #0
 *   @0x231258 add r5, r1, r5, lsl #5
 *   @0x23125c ldr r1, [r5, #0x8]
 *   @0x231260 strd r2, r3, [r4, #104]
 *   @0x231264 strd r2, r3, [r4, #112]
 *   @0x231268 mul r0, r0, r1
 *   @0x23126c pop {r3, r4, r5, pc}
 *   @0x231270 mvn r0, #0
 *   @0x231274 pop {r3, r4, r5, pc}
 *   @0x231278 mvn r0, #130
 *   @0x23127c pop {r3, r4, r5, pc}
 *
 * ══ §152/281 IniFile::SkipWhiteSpace()  0x235578  size 108  27 条（0x235578..0x2355e4）
 * @func 0x235578 0x2355e4  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::IsWhiteSpace() / IniFile::NextLine()
 * 字段偏移 top8: 0xc×3 / 0x10×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235578 push {r4, lr}
 *   @0x23557c mov r4, r0
 *   @0x235580 mov r0, r4
 *   @0x235584 bl 0x235518 <_ZN7IniFile12IsWhiteSpaceEv>
 *   @0x235588 cmp r0, #0
 *   @0x23558c popeq {r4, pc}
 *   @0x235590 ldr r3, [r4, #0xc]
 *   @0x235594 ldr r2, [r4, #0x4]
 *   @0x235598 cmp r3, r2
 *   @0x23559c popge {r4, pc}
 *   @0x2355a0 ldr r2, [r4, #0x10]
 *   @0x2355a4 ldrb r2, [r2, r3]
 *   @0x2355a8 cmp r2, #35
 *   @0x2355ac cmpne r2, #59
 *   @0x2355b0 bne 0x2355c8 <_ZN7IniFile14SkipWhiteSpaceEv+0x50>
 *   @0x2355b4 mov r0, r4
 *   @0x2355b8 bl 0x2354a8 <_ZN7IniFile8NextLineEv>
 *   @0x2355bc ldr r3, [r4, #0xc]
 *   @0x2355c0 ldr r2, [r4, #0x10]
 *   @0x2355c4 ldrb r2, [r2, r3]
 *   @0x2355c8 cmp r2, #10
 *   @0x2355cc add r3, r3, #1
 *   @0x2355d0 str r3, [r4, #0xc]
 *   @0x2355d4 ldreq r2, [r4, #0x14]
 *   @0x2355d8 addeq r2, r2, #1
 *   @0x2355dc streq r2, [r4, #0x14]
 *   @0x2355e0 b 0x235580 <_ZN7IniFile14SkipWhiteSpaceEv+0x8>
 *
 * ══ §153/281 MakeDate(double, double)  0x245480  size 108  27 条（0x245480..0x2454ec）
 * @func 0x245480 0x2454ec  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: myisinf(double)×2
 * 字段偏移 top8: 0x3c×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245480 push {r3, r4, r5, lr}
 *   @0x245484 vpush {d8}
 *   @0x245488 mov r4, r2
 *   @0x24548c mov r5, r3
 *   @0x245490 vmov d8, r0, r1
 *   @0x245494 bl 0x24364c <_Z7myisinfd>
 *   @0x245498 cmp r0, #0
 *   @0x24549c beq 0x2454b4 <_Z8MakeDatedd+0x34>
 *   @0x2454a0 vpop {d8}
 *   @0x2454a4 ldr r3, [pc, #0x3c]
 *   @0x2454a8 ldr r3, [pc, r3]
 *   @0x2454ac ldrd r0, r1, [r3]
 *   @0x2454b0 pop {r3, r4, r5, pc}
 *   @0x2454b4 mov r0, r4
 *   @0x2454b8 mov r1, r5
 *   @0x2454bc bl 0x24364c <_Z7myisinfd>
 *   @0x2454c0 cmp r0, #0
 *   @0x2454c4 bne 0x2454a0 <_Z8MakeDatedd+0x20>
 *   @0x2454c8 vmov d6, r4, r5
 *   @0x2454cc vldr d7, [pc, #12]
 *   @0x2454d0 vmla.f64 d6, d8, d7
 *   @0x2454d4 vpop {d8}
 *   @0x2454d8 vmov r0, r1, d6
 *   @0x2454dc pop {r3, r4, r5, pc}
 *   @0x2454e0 andeq r0, r0, r0
 *   @0x2454e4 orrsmi r9, r4, r0, ror r9
 *   @0x2454e8 andseq r12, r10, r0, lsl #5
 *
 * ══ §154/281 CalcCRC(char const*, unsigned int)  0x27dec0  size 108  27 条（0x27dec0..0x27df2c）
 * @func 0x27dec0 0x27df2c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: InitFastCRC()
 * 字段偏移 top8: 0x54×1 / 0x34×1 / 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27dec0 push {r3, r4, r5, lr}
 *   @0x27dec4 mov r5, r0
 *   @0x27dec8 ldr r3, [pc, #0x54]
 *   @0x27decc mov r4, r1
 *   @0x27ded0 ldr r3, [pc, r3]
 *   @0x27ded4 ldrb r3, [r3]
 *   @0x27ded8 cmp r3, #0
 *   @0x27dedc beq 0x27df1c <_Z7CalcCRCPKcj+0x5c>
 *   @0x27dee0 ldrb r3, [r5]
 *   @0x27dee4 cmp r3, #0
 *   @0x27dee8 beq 0x27df14 <_Z7CalcCRCPKcj+0x54>
 *   @0x27deec ldr r1, [pc, #0x34]
 *   @0x27def0 mov r0, r5
 *   @0x27def4 ldr r1, [pc, r1]
 *   @0x27def8 eor r2, r4, r3
 *   @0x27defc ldrb r3, [r0, #0x1]!
 *   @0x27df00 uxtb r2, r2
 *   @0x27df04 cmp r3, #0
 *   @0x27df08 ldr r2, [r1, r2, lsl #2]
 *   @0x27df0c eor r4, r2, r4, lsr #8
 *   @0x27df10 bne 0x27def8 <_Z7CalcCRCPKcj+0x38>
 *   @0x27df14 mov r0, r4
 *   @0x27df18 pop {r3, r4, r5, pc}
 *   @0x27df1c bl 0x27de00 <_Z11InitFastCRCv>
 *   @0x27df20 b 0x27dee0 <_Z7CalcCRCPKcj+0x20>
 *   @0x27df24 ldrheq r3, [r7], -r4
 *   @0x27df28 andseq r2, r7, r12, lsr #28
 *
 * ══ §155/281 CalcCRC(char const*, int, unsigned int)  0x27df34  size 108  27 条（0x27df34..0x27dfa0）
 * @func 0x27df34 0x27dfa0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CalcCRC(char const*, int, unsigned int)+0x54 / InitFastCRC()
 * 字段偏移 top8: 0x5c×1 / 0x34×1 / 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27df34 ldr r3, [pc, #0x5c]
 *   @0x27df38 push {r4, r5, r6, lr}
 *   @0x27df3c ldr r3, [pc, r3]
 *   @0x27df40 mov r5, r0
 *   @0x27df44 mov r6, r1
 *   @0x27df48 ldrb r3, [r3]
 *   @0x27df4c mov r4, r2
 *   @0x27df50 cmp r3, #0
 *   @0x27df54 beq 0x27df90 <_Z7CalcCRCPKcij+0x5c>
 *   @0x27df58 cmp r6, #0
 *   @0x27df5c ble 0x27df88 <_Z7CalcCRCPKcij+0x54>
 *   @0x27df60 ldr r2, [pc, #0x34]
 *   @0x27df64 add r1, r5, r6
 *   @0x27df68 ldr r2, [pc, r2]
 *   @0x27df6c ldrb r3, [r5], #1
 *   @0x27df70 eor r3, r3, r4
 *   @0x27df74 cmp r5, r1
 *   @0x27df78 uxtb r3, r3
 *   @0x27df7c ldr r3, [r2, r3, lsl #2]
 *   @0x27df80 eor r4, r3, r4, lsr #8
 *   @0x27df84 bne 0x27df6c <_Z7CalcCRCPKcij+0x38>
 *   @0x27df88 mov r0, r4
 *   @0x27df8c pop {r4, r5, r6, pc}
 *   @0x27df90 bl 0x27de00 <_Z11InitFastCRCv>
 *   @0x27df94 b 0x27df58 <_Z7CalcCRCPKcij+0x24>
 *   @0x27df98 andseq r3, r7, r8, asr #18
 *   @0x27df9c ldrheq r2, [r7], -r8
 *
 * ══ §156/281 json_object_to_json_string  0x27e830  size 108  27 条（0x27e830..0x27e89c）
 * @func 0x27e830 0x27e89c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: printbuf_reset / json_object_to_json_string+0x54 / printbuf_new
 * 字段偏移 top8: 0x10×4 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e830 push {r4, lr}
 *   @0x27e834 subs r4, r0, #0
 *   @0x27e838 beq 0x27e88c <json_object_to_json_string+0x5c>
 *   @0x27e83c ldr r0, [r4, #0x10]
 *   @0x27e840 cmp r0, #0
 *   @0x27e844 beq 0x27e870 <json_object_to_json_string+0x40>
 *   @0x27e848 bl 0x280e9c <printbuf_reset>
 *   @0x27e84c ldr r1, [r4, #0x10]
 *   @0x27e850 ldr r3, [r4, #0x8]
 *   @0x27e854 mov r0, r4
 *   @0x27e858 blx r3
 *   @0x27e85c cmp r0, #0
 *   @0x27e860 blt 0x27e884 <json_object_to_json_string+0x54>
 *   @0x27e864 ldr r3, [r4, #0x10]
 *   @0x27e868 ldr r0, [r3]
 *   @0x27e86c pop {r4, pc}
 *   @0x27e870 bl 0x280cc8 <printbuf_new>
 *   @0x27e874 cmp r0, #0
 *   @0x27e878 mov r1, r0
 *   @0x27e87c str r0, [r4, #0x10]
 *   @0x27e880 bne 0x27e850 <json_object_to_json_string+0x20>
 *   @0x27e884 mov r0, #0
 *   @0x27e888 pop {r4, pc}
 *   @0x27e88c ldr r0, [pc, #0x4]
 *   @0x27e890 add r0, pc, r0
 *   @0x27e894 pop {r4, pc}
 *   @0x27e898 andeq r3, r11, r4, lsl r10
 *
 * ══ §157/281 anon_280ed0  0x280ed0  size 108  27 条（0x280ed0..0x280f3c）
 * @func 0x280ed0 0x280f3c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280ed0 push {r4, r5, r6, r7, r8, lr}
 *   @0x280ed4 vpush {d8}
 *   @0x280ed8 mov r8, r0
 *   @0x280edc mov r0, r1
 *   @0x280ee0 mov r1, r2
 *   @0x280ee4 mov r7, r2
 *   @0x280ee8 vmov.f32 s16, s0
 *   @0x280eec bl 0x318d10 <__divsi3>
 *   @0x280ef0 subs r0, r0, #2
 *   @0x280ef4 moveq r0, r7
 *   @0x280ef8 beq 0x280f38 <printbuf_free+0x88>
 *   @0x280efc asr r4, r0, #1
 *   @0x280f00 mov r12, #0
 *   @0x280f04 add r5, r4, #1
 *   @0x280f08 mul r6, r7, r5
 *   @0x280f0c add r6, r8, r6, lsl #2
 *   @0x280f10 vldr s15, [r6]
 *   @0x280f14 vcmpe.f32 s15, s16
 *   @0x280f18 vmrs APSR_nzcv, fpscr
 *   @0x280f1c movls r12, r5
 *   @0x280f20 movhi r0, r4
 *   @0x280f24 add r4, r12, r0
 *   @0x280f28 cmp r12, r0
 *   @0x280f2c asr r4, r4, #1
 *   @0x280f30 bne 0x280f04 <printbuf_free+0x54>
 *   @0x280f34 mla r0, r12, r7, r7
 *   @0x280f38 vpop {d8}
 *
 * ══ §158/281 _spAttachment_init  0x284c18  size 108  27 条（0x284c18..0x284c84）
 * @func 0x284c18 0x284c84  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x58×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284c18 push {r4, r5, r6, r7, r8, lr}
 *   @0x284c1c mov r4, r0
 *   @0x284c20 ldr r6, [pc, #0x58]
 *   @0x284c24 mov r5, r1
 *   @0x284c28 mov r7, r2
 *   @0x284c2c mov r8, r3
 *   @0x284c30 add r6, pc, r6
 *   @0x284c34 mov r3, #43
 *   @0x284c38 mov r1, #4
 *   @0x284c3c mov r0, #1
 *   @0x284c40 mov r2, r6
 *   @0x284c44 bl 0x285c4c <_calloc>
 *   @0x284c48 mov r1, r0
 *   @0x284c4c mov r0, r5
 *   @0x284c50 str r1, [r4, #0x8]
 *   @0x284c54 str r8, [r1]
 *   @0x284c58 bl 0xb6538 <strlen@plt>
 *   @0x284c5c mov r1, r6
 *   @0x284c60 mov r2, #46
 *   @0x284c64 add r0, r0, #1
 *   @0x284c68 bl 0x285c10 <_malloc>
 *   @0x284c6c mov r1, r5
 *   @0x284c70 str r0, [r4]
 *   @0x284c74 bl 0xb65a4 <strcpy@plt>
 *   @0x284c78 str r7, [r4, #0x4]
 *   @0x284c7c pop {r4, r5, r6, r7, r8, pc}
 *   @0x284c80 andeq r2, sp, r4, lsr #20
 *
 * ══ §159/281 spBone_worldToLocalRotationX  0x285528  size 108  27 条（0x285528..0x285594）
 * @func 0x285528 0x2855a4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70
 * 字段偏移 top8: 0x8×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285528 push {r3, lr}
 *   @0x28552c ldr r3, [r0, #0x8]
 *   @0x285530 cmp r3, #0
 *   @0x285534 vldreq s15, [r0, #28]
 *   @0x285538 beq 0x285588 <spBone_worldToLocalRotationX+0x60>
 *   @0x28553c vldr s13, [r0, #52]
 *   @0x285540 vldr s14, [r3, #64]
 *   @0x285544 vmul.f32 s14, s13, s14
 *   @0x285548 vldr s12, [r0, #64]
 *   @0x28554c vldr s15, [r3, #56]
 *   @0x285550 vldr s10, [r3, #52]
 *   @0x285554 vldr s11, [r3, #68]
 *   @0x285558 vmul.f32 s15, s12, s15
 *   @0x28555c vnmls.f32 s14, s12, s10
 *   @0x285560 vnmls.f32 s15, s13, s11
 *   @0x285564 vcvt.f64.f32 d6, s14
 *   @0x285568 vmov r0, r1, d6
 *   @0x28556c vcvt.f64.f32 d6, s15
 *   @0x285570 vmov r2, r3, d6
 *   @0x285574 bl 0xb6c70 <atan2@plt>
 *   @0x285578 vldr s15, [pc, #16]
 *   @0x28557c vmov d6, r0, r1
 *   @0x285580 vcvt.f32.f64 s14, d6
 *   @0x285584 vmul.f32 s15, s14, s15
 *   @0x285588 vmov r0, s15
 *   @0x28558c pop {r3, pc}
 *   @0x285590 rsbmi r2, r5, #224, #28
 *
 * ══ §160/281 spBone_worldToLocalRotationY  0x285594  size 108  27 条（0x285594..0x285600）
 * @func 0x285594 0x285600  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70
 * 字段偏移 top8: 0x8×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285594 push {r3, lr}
 *   @0x285598 ldr r3, [r0, #0x8]
 *   @0x28559c cmp r3, #0
 *   @0x2855a0 vldreq s15, [r0, #28]
 *   @0x2855a4 beq 0x2855f4 <spBone_worldToLocalRotationY+0x60>
 *   @0x2855a8 vldr s13, [r0, #56]
 *   @0x2855ac vldr s14, [r3, #64]
 *   @0x2855b0 vmul.f32 s14, s13, s14
 *   @0x2855b4 vldr s12, [r0, #68]
 *   @0x2855b8 vldr s15, [r3, #56]
 *   @0x2855bc vldr s10, [r3, #52]
 *   @0x2855c0 vldr s11, [r3, #68]
 *   @0x2855c4 vmul.f32 s15, s12, s15
 *   @0x2855c8 vnmls.f32 s14, s12, s10
 *   @0x2855cc vnmls.f32 s15, s13, s11
 *   @0x2855d0 vcvt.f64.f32 d6, s14
 *   @0x2855d4 vmov r0, r1, d6
 *   @0x2855d8 vcvt.f64.f32 d6, s15
 *   @0x2855dc vmov r2, r3, d6
 *   @0x2855e0 bl 0xb6c70 <atan2@plt>
 *   @0x2855e4 vldr s15, [pc, #16]
 *   @0x2855e8 vmov d6, r0, r1
 *   @0x2855ec vcvt.f32.f64 s14, d6
 *   @0x2855f0 vmul.f32 s15, s14, s15
 *   @0x2855f4 vmov r0, s15
 *   @0x2855f8 pop {r3, pc}
 *   @0x2855fc rsbmi r2, r5, #224, #28
 *
 * ══ §161/281 Java_com_yoyogames_runner_RunnerJNILib_dsMapAddInt  0x292b68  size 108  27 条（0x292b68..0x292bd4）
 * @func 0x292b68 0x292bd4  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / dsMapAddInt
 * 字段偏移 top8: 0x18×1 / 0x2a4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292b68 push {r4, r5, r6, r7, r8, lr}
 *   @0x292b6c mov r4, r0
 *   @0x292b70 mov r5, r3
 *   @0x292b74 mov r8, r2
 *   @0x292b78 ldr r7, [sp, #0x18]
 *   @0x292b7c bl 0x290614 <setJNIEnv>
 *   @0x292b80 ldr r3, [r4]
 *   @0x292b84 mov r1, r5
 *   @0x292b88 mov r2, #0
 *   @0x292b8c mov r0, r4
 *   @0x292b90 ldr r3, [r3, #0x2a4]
 *   @0x292b94 blx r3
 *   @0x292b98 mov r2, r7
 *   @0x292b9c mov r6, r0
 *   @0x292ba0 mov r0, r8
 *   @0x292ba4 mov r1, r6
 *   @0x292ba8 bl 0x101850 <dsMapAddInt>
 *   @0x292bac cmp r6, #0
 *   @0x292bb0 cmpne r5, #0
 *   @0x292bb4 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x292bb8 ldr r3, [r4]
 *   @0x292bbc mov r1, r5
 *   @0x292bc0 mov r2, r6
 *   @0x292bc4 mov r0, r4
 *   @0x292bc8 ldr r3, [r3, #0x2a8]
 *   @0x292bcc blx r3
 *   @0x292bd0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §162/281 AllocSocket()  0x298e28  size 108  27 条（0x298e28..0x298e94）
 * @func 0x298e28 0x298e94  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x60×1 / 0x-4×1 / 0x1×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x298e28 ldr r1, [pc, #0x60]
 *   @0x298e2c mov r3, #0
 *   @0x298e30 str r4, [sp, #-0x4]!
 *   @0x298e34 mov r0, r3
 *   @0x298e38 ldr r1, [pc, r1]
 *   @0x298e3c b 0x298e4c <_Z11AllocSocketv+0x24>
 *   @0x298e40 add r0, r0, #1
 *   @0x298e44 cmp r0, #64
 *   @0x298e48 beq 0x298e84 <_Z11AllocSocketv+0x5c>
 *   @0x298e4c ldrb r2, [r1, r3]
 *   @0x298e50 add r3, r3, #12
 *   @0x298e54 cmp r2, #0
 *   @0x298e58 bne 0x298e40 <_Z11AllocSocketv+0x18>
 *   @0x298e5c add r12, r0, r0, lsl #1
 *   @0x298e60 mov r4, #1
 *   @0x298e64 lsl r12, r12, #2
 *   @0x298e68 add r3, r1, r12
 *   @0x298e6c strb r4, [r1, r12]
 *   @0x298e70 strb r2, [r3, #0x1]
 *   @0x298e74 str r2, [r3, #0x4]
 *   @0x298e78 str r2, [r3, #0x8]
 *   @0x298e7c ldr r4, [sp], #4
 *   @0x298e80 bx lr
 *   @0x298e84 mvn r0, #0
 *   @0x298e88 ldr r4, [sp], #4
 *   @0x298e8c bx lr
 *   @0x298e90 andseq r8, r5, r12, ror #22
 *
 * ══ §163/281 png_read_chunk_header  0x2adbc4  size 108  27 条（0x2adbc4..0x2adc30）
 * @func 0x2adbc4 0x2adc30  size 108  27 条
 * 部分覆盖: 本节 27/45 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_read_data / png_get_uint_31 / png_calculate_crc / png_check_chunk_name / 0xb65d4
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2adbc4 push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr}
 *   @0x2adbc8 add r6, sp, #0x4
 *   @0x2adbcc mov r4, r0
 *   @0x2adbd0 mov r1, r6
 *   @0x2adbd4 ldr r5, [r5]
 *   @0x2adbd8 stmdavs r11!, {r4, r5, r6, r7, r8, r9, r10, r12, sp, lr}
 *   @0x2adbdc str r3, [sp, #0xc]
 *   @0x2adbe0 str.w r3, [r0, #0x334]
 *   @0x2adbe4 bl 0x2a8030 <png_read_data>
 *   @0x2adbe8 mov r1, r6
 *   @0x2adbec bl 0x2abb6c <png_get_uint_31>
 *   @0x2adbf0 mov r8, r0
 *   @0x2adbf4 str.w r0, [r4, #0x1e0]
 *   @0x2adbf8 mov r0, r4
 *   @0x2adbfc andhs pc, r4, #492
 *   @0x2adc00 mov r0, r4
 *   @0x2adc04 bl 0x2a5b08 <png_calculate_crc>
 *   @0x2adc08 mov r0, r4
 *   @0x2adc0c bl 0x2adb74 <png_check_chunk_name>
 *   @0x2adc10 movs r3, #0x41
 *   @0x2adc14 mov r0, r8
 *   @0x2adc18 stmdavs r11!, {r2, r4, r5, r8, r9, r12, sp}
 *   @0x2adc1c cmp r2, r3
 *   @0x2adc20 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2adc24 add sp, #0x10
 *   @0x2adc28 svclt #0x81f0
 *   @0x2adc2c stc2 p0, c0, [r2, #76]
 *
 * ══ §164/281 anon_2b1228  0x2b1228  size 108  27 条（0x2b1228..0x2b1294）
 * @func 0x2b1228 0x2b1294  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x1d02a44 / 0x681cb4
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1228 stmdavs r9, {r0, r2, r3, r9, r10, lr}
 *   @0x2b122c bllt 0x1d02a44 <b2_toiTime+0x15a95a0>
 *   @0x2b1230 stmvs r11!, {r1, r2, r3, r9, r10, lr}
 *   @0x2b1234 ble 0x681cb4 <g_SWFlinevertbuff+0x2ebec>
 *   @0x2b1238 strtmi r6, [r0], -r11, lsr #18
 *   @0x2b123c ldrsbhs pc, [r4, #-132]!
 *   @0x2b1240 eorne pc, r6, r3, asr r8
 *   @0x2b1244 .word 0xffdef7ff
 *   @0x2b1248 strtmi r6, [r0], -r11, lsr #18
 *   @0x2b124c eorne pc, r6, r3, asr r8
 *   @0x2b1250 .word 0xf7f53601
 *   @0x2b1254 ubfx pc, r3, #0x1a, #0xd
 *   @0x2b1258 tstlt r11, r11, ror #17
 *   @0x2b125c stmdbvs r9!, {r5, r9, r10, lr}
 *   @0x2b1260 stc2l p7, c15, [r12, #-980]
 *   @0x2b1264 .word 0x3148f8d4
 *   @0x2b1268 ldrsbhs pc, [r4, #-132]!
 *   @0x2b126c andle r4, r5, #805306377
 *   @0x2b1270 .word 0xf8d44620
 *   @0x2b1274 bne 0xff73583c <b2_toiTime+0xfffffffffefdc398>
 *   @0x2b1278 .word 0xffc4f7ff
 *   @0x2b127c addsvc pc, r12, r4, lsl #10
 *   @0x2b1280 cdp p6, #0x6, c15, c10, c5, #0x0
 *   @0x2b1284 .word 0xf8c42300
 *   @0x2b1288 ldcllt p1, c3, [r0, #-400]!
 *   @0x2b128c pop {r1, r3, r5, r6, r11, sp, lr}
 *   @0x2b1290 .word 0xf7ff4070
 *
 * ══ §165/281 png_write_hIST  0x2b1f28  size 108  27 条（0x2b1f28..0x2b1f94）
 * @func 0x2b1f28 0x2b1fa4  size 124  31 条
 * 部分覆盖: 本节 31/56 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 30/54 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 29/52 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 28/50 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning / png_save_uint_16 / png_write_chunk_end
 * 字段偏移 top8: 0x8×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1f28 push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr}
 *   @0x2b1f2c mov r4, r0
 *   @0x2b1f30 mov r8, r1
 *   @0x2b1f34 add r3, pc
 *   @0x2b1f38 ldmdbvc r11, {r2, r6, r8, r9, r10, r11}
 *   @0x2b1f3c str r0, [sp, #0x8]
 *   @0x2b1f40 strb.w r3, [sp, #0xc]
 *   @0x2b1f44 ldrh.w r3, [r4, #0x1dc]
 *   @0x2b1f48 cmp r2, r3
 *   @0x2b1f4c ldr r1, [pc, #0x40]
 *   @0x2b1f50 bl 0x2a6474 <png_warning>
 *   @0x2b1f54 b 0x2b1f84 <png_write_hIST+0x5c>
 *   @0x2b1f58 lsls r2, r2, #0x1
 *   @0x2b1f5c svcge #0x1f921
 *   @0x2b1f60 movs r5, #0x0
 *   @0x2b1f64 bge 0x2b1f7e <png_write_hIST+0x56>
 *   @0x2b1f68 shadd16mi r1, r8, r5
 *   @0x2b1f6c bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1f70 mov r0, r4
 *   @0x2b1f74 movs r2, #0x2
 *   @0x2b1f78 strlo pc, [r1, #-0x945]
 *   @0x2b1f7c b 0x2b1f62 <png_write_hIST+0x3a>
 *   @0x2b1f80 bl 0x2b1296 <png_write_chunk_end>
 *   @0x2b1f84 add sp, #0x10
 *   @0x2b1f88 svclt #0x81f0
 *   @0x2b1f8c udf #0x2c
 *   @0x2b1f90 stm r6!, {r6, r7}
 *
 * ══ §166/281 b2BlockAllocator::Clear()  0x2c674c  size 108  27 条（0x2c674c..0x2c67b8）
 * @func 0x2c674c 0x2c67b8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Clear()+0x38 / b2Free(void*) / 0xb65b0
 * 字段偏移 top8: 0x4×4 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c674c ldr r3, [r0, #0x4]
 *   @0x2c6750 push {r4, r5, r6, lr}
 *   @0x2c6754 cmp r3, #0
 *   @0x2c6758 mov r5, r0
 *   @0x2c675c movgt r4, #0
 *   @0x2c6760 ble 0x2c6784 <_ZN16b2BlockAllocator5ClearEv+0x38>
 *   @0x2c6764 ldr r3, [r5]
 *   @0x2c6768 add r3, r3, r4, lsl #3
 *   @0x2c676c add r4, r4, #1
 *   @0x2c6770 ldr r0, [r3, #0x4]
 *   @0x2c6774 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c6778 ldr r3, [r5, #0x4]
 *   @0x2c677c cmp r3, r4
 *   @0x2c6780 bgt 0x2c6764 <_ZN16b2BlockAllocator5ClearEv+0x18>
 *   @0x2c6784 ldr r2, [r5, #0x8]
 *   @0x2c6788 mov r6, r5
 *   @0x2c678c ldr r0, [r6], #12
 *   @0x2c6790 mov r4, #0
 *   @0x2c6794 mov r1, r4
 *   @0x2c6798 str r4, [r5, #0x4]
 *   @0x2c679c lsl r2, r2, #3
 *   @0x2c67a0 bl 0xb65b0 <memset@plt>
 *   @0x2c67a4 mov r0, r6
 *   @0x2c67a8 mov r1, r4
 *   @0x2c67ac mov r2, #56
 *   @0x2c67b0 pop {r4, r5, r6, lr}
 *   @0x2c67b4 b 0xb65b0 <memset@plt>
 *
 * ══ §167/281 b2FrictionJoint::b2FrictionJoint(b2FrictionJointDef const*)  0x2cda14  size 108  27 条（0x2cda14..0x2cda80）
 * @func 0x2cda14 0x2cda80  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0x4c×1 / 0x24×1 / 0x44×1 / 0x28×1 / 0x60×1 / 0x64×1 / 0x54×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cda14 push {r3, r4, r5, r6, r7, lr}
 *   @0x2cda18 mov r4, r0
 *   @0x2cda1c mov r5, r1
 *   @0x2cda20 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2cda24 add r3, r5, #20
 *   @0x2cda28 ldr r2, [pc, #0x4c]
 *   @0x2cda2c add r6, r5, #28
 *   @0x2cda30 ldr r7, [r5, #0x24]
 *   @0x2cda34 ldm r3, {r0, r1}
 *   @0x2cda38 ldr r2, [pc, r2]
 *   @0x2cda3c mov r3, r4
 *   @0x2cda40 add r2, r2, #8
 *   @0x2cda44 str r2, [r3], #68
 *   @0x2cda48 add r12, r4, #76
 *   @0x2cda4c stm r3, {r0, r1}
 *   @0x2cda50 mov r3, #0
 *   @0x2cda54 ldm r6, {r0, r1}
 *   @0x2cda58 ldr r2, [r5, #0x28]
 *   @0x2cda5c stm r12, {r0, r1}
 *   @0x2cda60 mov r0, r4
 *   @0x2cda64 str r7, [r4, #0x60]
 *   @0x2cda68 str r2, [r4, #0x64]
 *   @0x2cda6c str r3, [r4, #0x54]
 *   @0x2cda70 str r3, [r4, #0x58]
 *   @0x2cda74 str r3, [r4, #0x5c]
 *   @0x2cda78 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2cda7c andseq r4, r2, r4, lsr #2
 *
 * ══ §168/281 b2MotorJoint::b2MotorJoint(b2MotorJointDef const*)  0x2ce6c4  size 108  27 条（0x2ce6c4..0x2ce730）
 * @func 0x2ce6c4 0x2ce730  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0x50×2 / 0x1c×1 / 0x20×1 / 0x24×1 / 0x44×1 / 0x28×1 / 0x4c×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce6c4 push {r3, r4, r5, r6, r7, lr}
 *   @0x2ce6c8 mov r4, r0
 *   @0x2ce6cc mov r5, r1
 *   @0x2ce6d0 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2ce6d4 ldr r2, [pc, #0x50]
 *   @0x2ce6d8 add r1, r5, #20
 *   @0x2ce6dc mov r3, r4
 *   @0x2ce6e0 ldr r7, [r5, #0x1c]
 *   @0x2ce6e4 ldr r2, [pc, r2]
 *   @0x2ce6e8 ldm r1, {r0, r1}
 *   @0x2ce6ec ldr r6, [r5, #0x20]
 *   @0x2ce6f0 add r2, r2, #8
 *   @0x2ce6f4 ldr r12, [r5, #0x24]
 *   @0x2ce6f8 str r2, [r3], #68
 *   @0x2ce6fc ldr r2, [r5, #0x28]
 *   @0x2ce700 stm r3, {r0, r1}
 *   @0x2ce704 mov r3, #0
 *   @0x2ce708 str r7, [r4, #0x4c]
 *   @0x2ce70c mov r0, r4
 *   @0x2ce710 str r6, [r4, #0x5c]
 *   @0x2ce714 str r12, [r4, #0x60]
 *   @0x2ce718 str r2, [r4, #0x64]
 *   @0x2ce71c str r3, [r4, #0x50]
 *   @0x2ce720 str r3, [r4, #0x54]
 *   @0x2ce724 str r3, [r4, #0x58]
 *   @0x2ce728 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2ce72c andseq r3, r2, r12, ror r4
 *
 * ══ §169/281 b2RopeJoint::b2RopeJoint(b2RopeJointDef const*)  0x2d2b48  size 108  27 条（0x2d2b48..0x2d2bb4）
 * @func 0x2d2b48 0x2d2bb4  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0x4c×1 / 0x24×1 / 0x44×1 / 0x54×1 / 0xa4×1 / 0xa0×1 / 0x5c×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2b48 push {r4, r5, r6, lr}
 *   @0x2d2b4c mov r4, r0
 *   @0x2d2b50 mov r5, r1
 *   @0x2d2b54 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2d2b58 add r3, r5, #20
 *   @0x2d2b5c ldr r2, [pc, #0x4c]
 *   @0x2d2b60 add r6, r5, #28
 *   @0x2d2b64 ldr r5, [r5, #0x24]
 *   @0x2d2b68 ldm r3, {r0, r1}
 *   @0x2d2b6c ldr r2, [pc, r2]
 *   @0x2d2b70 mov r3, r4
 *   @0x2d2b74 add r2, r2, #8
 *   @0x2d2b78 str r2, [r3], #68
 *   @0x2d2b7c add r12, r4, #76
 *   @0x2d2b80 stm r3, {r0, r1}
 *   @0x2d2b84 mov r2, #0
 *   @0x2d2b88 ldm r6, {r0, r1}
 *   @0x2d2b8c mov r3, #0
 *   @0x2d2b90 stm r12, {r0, r1}
 *   @0x2d2b94 mov r0, r4
 *   @0x2d2b98 str r5, [r4, #0x54]
 *   @0x2d2b9c str r2, [r4, #0xa4]
 *   @0x2d2ba0 str r3, [r4, #0xa0]
 *   @0x2d2ba4 str r3, [r4, #0x5c]
 *   @0x2d2ba8 str r3, [r4, #0x58]
 *   @0x2d2bac pop {r4, r5, r6, pc}
 *   @0x2d2bb0 andseq pc, r1, r8
 *
 * ══ §170/281 FT_Done_Size  0x2e8a0c  size 106  27 条（0x2e8a0c..0x2e8a76）
 * @func 0x2e8a0c 0x2e8a78  size 108  27 条
 * 部分覆盖: 本节 27/48 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_List_Remove / ft_mem_free / anon_2e7b5e+0x22a
 * 字段偏移 top8: 0x58×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8a0c push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e8a10 mov r5, r0
 *   @0x2e8a14 movs r0, #0x24
 *   @0x2e8a18 stmdavs r4, {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e8a1c cbz r4, 0x2e8a6a <FT_Done_Size+0x5e>
 *   @0x2e8a20 cbz r6, 0x2e8a70 <FT_Done_Size+0x64>
 *   @0x2e8a24 strtmi r0, [r9], -r12, ror #18
 *   @0x2e8a28 ldr.w r8, [r6, #0x8]
 *   @0x2e8a2c mov r0, r9
 *   @0x2e8a30 strmi pc, [r7], -lr, ror #30
 *   @0x2e8a34 cmp r0, #0x0
 *   @0x2e8a38 mov r0, r9
 *   @0x2e8a3c bl 0x2e89f2 <FT_List_Remove>
 *   @0x2e8a40 mov r0, r8
 *   @0x2e8a44 bl 0x2e7336 <ft_mem_free>
 *   @0x2e8a48 ldr r3, [r4, #0x58]
 *   @0x2e8a4c bne 0x2e8a5a <FT_Done_Size+0x4e>
 *   @0x2e8a50 str r3, [r4, #0x58]
 *   @0x2e8a54 cbz r3, 0x2e8a5a <FT_Done_Size+0x4e>
 *   @0x2e8a58 str r3, [r4, #0x58]
 *   @0x2e8a5c mov r1, r5
 *   @0x2e8a60 bl 0x2e7d88 <FT_Done_GlyphSlot+0x26e>
 *   @0x2e8a64 movs r0, #0x0
 *   @0x2e8a68 .word 0x202383f8
 *   @0x2e8a6c pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e8a70 movs r0, #0x22
 *   @0x2e8a74 ldrshlt r8, [r8, #-56]!
 *
 * ══ §171/281 TT_New_Context  0x300208  size 106  27 条（0x300208..0x300272）
 * @func 0x300208 0x300274  size 108  27 条
 * 部分覆盖: 本节 27/50 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_alloc / 0x3ffee4 / 0x3ffe78
 * 字段偏移 top8: 0x8×2 / 0x18×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x300208 push {r4, r5, lr}
 *   @0x30020c cbnz r0, 0x300212 <TT_New_Context+0xa>
 *   @0x300210 b 0x30026e <TT_New_Context+0x66>
 *   @0x300214 add r2, sp, #0x8
 *   @0x300218 qadd16mi r7, r8, pc
 *   @0x30021c bl 0x2e7126 <ft_mem_alloc>
 *   @0x300220 ldr r2, [sp, #0x8]
 *   @0x300224 cmp r2, #0x0
 *   @0x300228 str r5, [r0, #0x8]
 *   @0x30022c add r1, sp, #0xc
 *   @0x300230 strhls r3, [r1, -r4]
 *   @0x300234 mov r0, r5
 *   @0x300238 movs r1, #0x10
 *   @0x30023c blls 0x3ffee4 <g_RomDisk+0x86c4>
 *   @0x300240 str.w r0, [r4, #0x1b8]
 *   @0x300244 cbnz r3, 0x300260 <TT_New_Context+0x58>
 *   @0x300248 .word 0xf8a431bc
 *   @0x30024c strhvs r3, [r3, #-30]!
 *   @0x300250 str.w r3, [r4, #0x188]
 *   @0x300254 str r3, [r4, #0x18]
 *   @0x300258 eorvs r3, r3, r12, lsl #3
 *   @0x30025c str r3, [r4, #0x4]
 *   @0x300260 mov r0, r4
 *   @0x300264 blls 0x3ffe78 <g_RomDisk+0x8658>
 *   @0x300268 cmp r3, #0x0
 *   @0x30026c mov r0, r4
 *   @0x300270 pop {r4, r5, pc}
 *
 * ══ §172/281 F_Vertex_Delete_Buffer_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8f80  size 104  26 条（0xc8f80..0xc8fe8）
 * @func 0xc8f80 0xc8ff8  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int) / FreeBufferVertex(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x30×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8f80 cmp r3, #1
 *   @0xc8f84 mov r2, #0
 *   @0xc8f88 push {r4, lr}
 *   @0xc8f8c mov r1, r2
 *   @0xc8f90 mov r4, r3
 *   @0xc8f94 movt r2, #0xbff0
 *   @0xc8f98 str r1, [r0, #0xc]
 *   @0xc8f9c stm r0, {r1, r2}
 *   @0xc8fa0 ldr r0, [sp, #0x8]
 *   @0xc8fa4 beq 0xc8fbc <_Z28F_Vertex_Delete_Buffer_debugR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0xc8fa8 ldr r0, [pc, #0x30]
 *   @0xc8fac mov r1, #1
 *   @0xc8fb0 pop {r4, lr}
 *   @0xc8fb4 add r0, pc, r0
 *   @0xc8fb8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8fbc bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc8fc0 bl 0xc8ee0 <_Z16FreeBufferVertexi>
 *   @0xc8fc4 cmp r0, #0
 *   @0xc8fc8 popne {r4, pc}
 *   @0xc8fcc ldr r0, [pc, #0x10]
 *   @0xc8fd0 mov r1, r4
 *   @0xc8fd4 pop {r4, lr}
 *   @0xc8fd8 add r0, pc, r0
 *   @0xc8fdc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8fe0 .word 0x00268cb8
 *   @0xc8fe4 eoreq r8, r6, r4, asr #25
 *
 * ══ §173/281 YYGML_vertex_end(int)  0xc9108  size 104  26 条（0xc9108..0xc9170）
 * @func 0xc9108 0xc9170  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetBufferVertex(int)
 * 字段偏移 top8: 0x18×2 / 0x24×2 / 0x20×1 / 0x2c×1 / 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9108 push {r3, lr}
 *   @0xc910c bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc9110 cmp r0, #0
 *   @0xc9114 beq 0xc9148 <_Z16YYGML_vertex_endi+0x40>
 *   @0xc9118 ldrb r3, [r0, #0x20]
 *   @0xc911c cmp r3, #0
 *   @0xc9120 bne 0xc9148 <_Z16YYGML_vertex_endi+0x40>
 *   @0xc9124 ldr r3, [r0, #0x18]
 *   @0xc9128 cmp r3, #0
 *   @0xc912c bne 0xc9158 <_Z16YYGML_vertex_endi+0x50>
 *   @0xc9130 ldr r2, [r0, #0x24]
 *   @0xc9134 mvn r1, #0
 *   @0xc9138 str r3, [r0, #0x2c]
 *   @0xc913c str r1, [r0, #0x24]
 *   @0xc9140 str r2, [r0, #0x28]
 *   @0xc9144 pop {r3, pc}
 *   @0xc9148 ldr r0, [pc, #0x18]
 *   @0xc914c pop {r3, lr}
 *   @0xc9150 add r0, pc, r0
 *   @0xc9154 b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc9158 ldr r0, [pc, #0xc]
 *   @0xc915c pop {r3, lr}
 *   @0xc9160 add r0, pc, r0
 *   @0xc9164 b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc9168 eoreq r8, r6, r4, asr #23
 *   @0xc916c .word 0x00268bd8
 *
 * ══ §174/281 F_Vertex_Position_3d_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc92f8  size 104  26 条（0xc92f8..0xc9360）
 * @func 0xc92f8 0xc9360  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc92f8 push {r3, r4, r5, lr}
 *   @0xc92fc mov r1, r3
 *   @0xc9300 ldr r4, [sp, #0x10]
 *   @0xc9304 mov r3, #4
 *   @0xc9308 mov r2, r4
 *   @0xc930c bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc9310 cmp r0, #0
 *   @0xc9314 popeq {r3, r4, r5, pc}
 *   @0xc9318 mov r1, #1
 *   @0xc931c mov r2, #3
 *   @0xc9320 bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType>
 *   @0xc9324 subs r5, r0, #0
 *   @0xc9328 popeq {r3, r4, r5, pc}
 *   @0xc932c mov r1, #1
 *   @0xc9330 mov r0, r4
 *   @0xc9334 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc9338 mov r1, #2
 *   @0xc933c str r0, [r5]
 *   @0xc9340 mov r0, r4
 *   @0xc9344 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc9348 mov r1, #3
 *   @0xc934c str r0, [r5, #0x4]
 *   @0xc9350 mov r0, r4
 *   @0xc9354 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc9358 str r0, [r5, #0x8]
 *   @0xc935c pop {r3, r4, r5, pc}
 *
 * ══ §175/281 F_Vertex_Normal_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc94ac  size 104  26 条（0xc94ac..0xc9514）
 * @func 0xc94ac 0xc9514  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc94ac push {r3, r4, r5, lr}
 *   @0xc94b0 mov r1, r3
 *   @0xc94b4 ldr r4, [sp, #0x10]
 *   @0xc94b8 mov r3, #4
 *   @0xc94bc mov r2, r4
 *   @0xc94c0 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc94c4 cmp r0, #0
 *   @0xc94c8 popeq {r3, r4, r5, pc}
 *   @0xc94cc mov r1, #3
 *   @0xc94d0 mov r2, r1
 *   @0xc94d4 bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType>
 *   @0xc94d8 subs r5, r0, #0
 *   @0xc94dc popeq {r3, r4, r5, pc}
 *   @0xc94e0 mov r1, #1
 *   @0xc94e4 mov r0, r4
 *   @0xc94e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc94ec mov r1, #2
 *   @0xc94f0 str r0, [r5]
 *   @0xc94f4 mov r0, r4
 *   @0xc94f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc94fc mov r1, #3
 *   @0xc9500 str r0, [r5, #0x4]
 *   @0xc9504 mov r0, r4
 *   @0xc9508 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc950c str r0, [r5, #0x8]
 *   @0xc9510 pop {r3, r4, r5, pc}
 *
 * ══ §176/281 VMWriteBuffer::Add(int, ...)  0xec674  size 104  26 条（0xec674..0xec6dc）
 * @func 0xec674 0xec6dc  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VMWriteBuffer::Reserve(int) / VMWriteBuffer::Add(int, ...)+0x58
 * 字段偏移 top8: 0x4×3 / 0x1c×2 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec674 push {r1, r2, r3}
 *   @0xec678 push {r4, r5, lr}
 *   @0xec67c sub sp, sp, #8
 *   @0xec680 mov r5, r0
 *   @0xec684 ldr r4, [sp, #0x14]
 *   @0xec688 lsl r1, r4, #2
 *   @0xec68c bl 0xec604 <_ZN13VMWriteBuffer7ReserveEi>
 *   @0xec690 cmp r4, #0
 *   @0xec694 add r3, sp, #24
 *   @0xec698 str r3, [sp, #0x4]
 *   @0xec69c ble 0xec6cc <_ZN13VMWriteBuffer3AddEiz+0x58>
 *   @0xec6a0 ldr r0, [r5, #0x1c]
 *   @0xec6a4 add r1, sp, #20
 *   @0xec6a8 mov r3, #0
 *   @0xec6ac mov r2, r0
 *   @0xec6b0 add r3, r3, #1
 *   @0xec6b4 ldr r12, [r1, #0x4]!
 *   @0xec6b8 cmp r3, r4
 *   @0xec6bc str r12, [r2], #4
 *   @0xec6c0 bne 0xec6b0 <_ZN13VMWriteBuffer3AddEiz+0x3c>
 *   @0xec6c4 add r3, r0, r3, lsl #2
 *   @0xec6c8 str r3, [r5, #0x1c]
 *   @0xec6cc add sp, sp, #8
 *   @0xec6d0 pop {r4, r5, lr}
 *   @0xec6d4 add sp, sp, #12
 *   @0xec6d8 bx lr
 *
 * ══ §177/281 InputQuery::SetResult(int, int, char const*)  0xf274c  size 104  26 条（0xf274c..0xf27b4）
 * @func 0xf274c 0xf27b4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 0x54×1 / 0x4×1 / 0x24×1 / 0x28×1 / 0xc×1 / 0x34×1 / 0x38×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf274c push {r3, r4, r5, lr}
 *   @0xf2750 mov r5, r2
 *   @0xf2754 ldr r3, [pc, #0x54]
 *   @0xf2758 ldr r3, [pc, r3]
 *   @0xf275c ldr r4, [r3]
 *   @0xf2760 cmp r4, #0
 *   @0xf2764 bne 0xf2778 <_ZN10InputQuery9SetResultEiiPKc+0x2c>
 *   @0xf2768 pop {r3, r4, r5, pc}
 *   @0xf276c ldr r4, [r4, #0x4]
 *   @0xf2770 cmp r4, #0
 *   @0xf2774 beq 0xf27ac <_ZN10InputQuery9SetResultEiiPKc+0x60>
 *   @0xf2778 ldr r3, [r4, #0x24]
 *   @0xf277c cmp r3, r0
 *   @0xf2780 bne 0xf276c <_ZN10InputQuery9SetResultEiiPKc+0x20>
 *   @0xf2784 mov r3, #7
 *   @0xf2788 str r1, [r4, #0x28]
 *   @0xf278c mov r0, r5
 *   @0xf2790 str r3, [r4, #0xc]
 *   @0xf2794 bl 0xb6538 <strlen@plt>
 *   @0xf2798 str r5, [r4, #0x34]
 *   @0xf279c add r0, r0, #1
 *   @0xf27a0 str r0, [r4, #0x38]
 *   @0xf27a4 str r0, [r4, #0x3c]
 *   @0xf27a8 pop {r3, r4, r5, pc}
 *   @0xf27ac pop {r3, r4, r5, pc}
 *   @0xf27b0 eoreq r11, pc, r0, lsr #13
 *
 * ══ §178/281 CFontGM::CFont_CreateFont(char const*, int, int, int, int, int)  0xf9f4c  size 104  26 条（0xf9f4c..0xf9fb4）
 * @func 0xf9f4c 0xf9fb4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CFontGM::CFontGM(char const*, int, bool, bool, int, int)
 * 字段偏移 top8: 0x30×1 / 0x34×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9f4c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xf9f50 sub sp, sp, #16
 *   @0xf9f54 mov r9, r0
 *   @0xf9f58 mov r0, #144
 *   @0xf9f5c mov r8, r1
 *   @0xf9f60 mov r7, r2
 *   @0xf9f64 mov r10, r3
 *   @0xf9f68 ldr r5, [sp, #0x30]
 *   @0xf9f6c ldr r4, [sp, #0x34]
 *   @0xf9f70 bl 0x27c524 <_Znwj>
 *   @0xf9f74 subs r2, r10, #1
 *   @0xf9f78 mov r1, r9
 *   @0xf9f7c rsbs r3, r2, #0
 *   @0xf9f80 str r5, [sp, #0x4]
 *   @0xf9f84 adcs r3, r3, r2
 *   @0xf9f88 subs r12, r7, #1
 *   @0xf9f8c str r3, [sp]
 *   @0xf9f90 rsbs r3, r12, #0
 *   @0xf9f94 str r4, [sp, #0x8]
 *   @0xf9f98 mov r2, r8
 *   @0xf9f9c adcs r3, r3, r12
 *   @0xf9fa0 mov r6, r0
 *   @0xf9fa4 bl 0xf9e08 <_ZN7CFontGMC2EPKcibbii>
 *   @0xf9fa8 mov r0, r6
 *   @0xf9fac add sp, sp, #16
 *   @0xf9fb0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §179/281 F_MpGridGetCell(RValue&, CInstance*, CInstance*, int, RValue*)  0x108da0  size 104  26 条（0x108da0..0x108e08）
 * @func 0x108da0 0x108e18  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Motion_Grid_GetCell(int, int, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108da0 push {r3, r4, r5, r6, r7, lr}
 *   @0x108da4 mov r1, #0
 *   @0x108da8 ldr r4, [sp, #0x18]
 *   @0x108dac mov r5, r0
 *   @0x108db0 str r1, [r0, #0xc]
 *   @0x108db4 mov r0, r4
 *   @0x108db8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108dbc mov r1, #1
 *   @0x108dc0 mov r7, r0
 *   @0x108dc4 mov r0, r4
 *   @0x108dc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108dcc mov r1, #2
 *   @0x108dd0 mov r6, r0
 *   @0x108dd4 mov r0, r4
 *   @0x108dd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108ddc mov r1, r6
 *   @0x108de0 mov r2, r0
 *   @0x108de4 mov r0, r7
 *   @0x108de8 bl 0x19a478 <_Z19Motion_Grid_GetCelliii>
 *   @0x108dec vmov s15, r0
 *   @0x108df0 vcvt.f64.s32 d7, s15
 *   @0x108df4 vmov r0, r1, d7
 *   @0x108df8 vmov r2, s14
 *   @0x108dfc mov r3, r1
 *   @0x108e00 stm r5, {r2, r3}
 *   @0x108e04 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §180/281 YYGML_instance_number(CInstance*, CInstance*, int)  0x10afe4  size 104  26 条（0x10afe4..0x10b04c）
 * @func 0x10afe4 0x10b04c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x68×2 / 0x69×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10afe4 cmn r2, #2
 *   @0x10afe8 beq 0x10b01c <_Z21YYGML_instance_numberP9CInstanceS0_i+0x38>
 *   @0x10afec cmn r2, #1
 *   @0x10aff0 bne 0x10b014 <_Z21YYGML_instance_numberP9CInstanceS0_i+0x30>
 *   @0x10aff4 cmp r0, #0
 *   @0x10aff8 bxeq lr
 *   @0x10affc ldrb r3, [r0, #0x68]
 *   @0x10b000 cmp r3, #0
 *   @0x10b004 bne 0x10b030 <_Z21YYGML_instance_numberP9CInstanceS0_i+0x4c>
 *   @0x10b008 ldrb r0, [r0, #0x69]
 *   @0x10b00c eor r0, r0, #1
 *   @0x10b010 bx lr
 *   @0x10b014 mov r0, r2
 *   @0x10b018 b 0x1c8ed0 <_Z22Command_InstanceNumberi>
 *   @0x10b01c cmp r1, #0
 *   @0x10b020 beq 0x10b044 <_Z21YYGML_instance_numberP9CInstanceS0_i+0x60>
 *   @0x10b024 ldrb r3, [r1, #0x68]
 *   @0x10b028 cmp r3, #0
 *   @0x10b02c beq 0x10b038 <_Z21YYGML_instance_numberP9CInstanceS0_i+0x54>
 *   @0x10b030 mov r0, #0
 *   @0x10b034 bx lr
 *   @0x10b038 ldrb r0, [r1, #0x69]
 *   @0x10b03c eor r0, r0, #1
 *   @0x10b040 bx lr
 *   @0x10b044 mov r0, r1
 *   @0x10b048 bx lr
 *
 * ══ §181/281 F_ArrayLength2D(RValue&, CInstance*, CInstance*, int, RValue*)  0x10dc98  size 104  26 条（0x10dc98..0x10dd00）
 * @func 0x10dc98 0x10dd00  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0xc×2 / 0x4×2 / 0x3×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dc98 push {r3, r4, r5, lr}
 *   @0x10dc9c mov r1, #1
 *   @0x10dca0 ldr r5, [sp, #0x10]
 *   @0x10dca4 mov r4, r0
 *   @0x10dca8 mov r0, r5
 *   @0x10dcac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10dcb0 mov r3, #0
 *   @0x10dcb4 str r3, [r4, #0xc]
 *   @0x10dcb8 ldr r2, [r5, #0xc]
 *   @0x10dcbc str r3, [r4]
 *   @0x10dcc0 cmp r2, #2
 *   @0x10dcc4 str r3, [r4, #0x4]
 *   @0x10dcc8 popne {r3, r4, r5, pc}
 *   @0x10dccc ldr r3, [r5]
 *   @0x10dcd0 cmp r3, #0
 *   @0x10dcd4 popeq {r3, r4, r5, pc}
 *   @0x10dcd8 ldr r2, [r3, #0x10]
 *   @0x10dcdc cmp r0, r2
 *   @0x10dce0 popge {r3, r4, r5, pc}
 *   @0x10dce4 ldr r3, [r3, #0x4]
 *   @0x10dce8 ldr r2, [r3, r0, lsl #3]
 *   @0x10dcec vmov s15, r2
 *   @0x10dcf0 vcvt.f64.s32 d7, s15
 *   @0x10dcf4 vmov r2, r3, d7
 *   @0x10dcf8 stm r4, {r2, r3}
 *   @0x10dcfc pop {r3, r4, r5, pc}
 *
 * ══ §182/281 F_DArcTan(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e9cc  size 104  26 条（0x10e9cc..0x10ea34）
 * @func 0x10e9cc 0x10ea44  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / 0xb676c
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e9cc mov r3, #0
 *   @0x10e9d0 push {r4, lr}
 *   @0x10e9d4 mov r1, r3
 *   @0x10e9d8 str r3, [r0, #0xc]
 *   @0x10e9dc mov r4, r0
 *   @0x10e9e0 ldr r0, [sp, #0x8]
 *   @0x10e9e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e9e8 bl 0xb676c <atanf@plt>
 *   @0x10e9ec vldr s15, [pc, #52]
 *   @0x10e9f0 vldr s13, [pc, #52]
 *   @0x10e9f4 vldr s14, [pc, #52]
 *   @0x10e9f8 vmov s12, r0
 *   @0x10e9fc vmul.f32 s15, s12, s15
 *   @0x10ea00 vdiv.f32 s15, s15, s13
 *   @0x10ea04 vabs.f32 s13, s15
 *   @0x10ea08 vcmpe.f32 s13, s14
 *   @0x10ea0c vmrs APSR_nzcv, fpscr
 *   @0x10ea10 vcvtpl.f64.f32 d6, s15
 *   @0x10ea14 movmi r2, #0
 *   @0x10ea18 movmi r3, #0
 *   @0x10ea1c vmovpl r2, r3, d6
 *   @0x10ea20 stm r4, {r2, r3}
 *   @0x10ea24 pop {r4, pc}
 *   @0x10ea28 teqmi r4, #0
 *   @0x10ea2c ldrdmi r0, r1, [r9], #-251
 *   @0x10ea30 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §183/281 F_ArcTan2(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ea34  size 104  26 条（0x10ea34..0x10ea9c）
 * @func 0x10ea34 0x10ea9c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / 0xb6778
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ea34 push {r4, r5, r6, lr}
 *   @0x10ea38 mov r1, #0
 *   @0x10ea3c ldr r5, [sp, #0x10]
 *   @0x10ea40 mov r4, r0
 *   @0x10ea44 str r1, [r0, #0xc]
 *   @0x10ea48 mov r0, r5
 *   @0x10ea4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10ea50 mov r1, #1
 *   @0x10ea54 mov r6, r0
 *   @0x10ea58 mov r0, r5
 *   @0x10ea5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10ea60 mov r1, r0
 *   @0x10ea64 mov r0, r6
 *   @0x10ea68 bl 0xb6778 <atan2f@plt>
 *   @0x10ea6c vldr s14, [pc, #36]
 *   @0x10ea70 vmov s15, r0
 *   @0x10ea74 vabs.f32 s13, s15
 *   @0x10ea78 vcmpe.f32 s13, s14
 *   @0x10ea7c vmrs APSR_nzcv, fpscr
 *   @0x10ea80 vcvtpl.f64.f32 d6, s15
 *   @0x10ea84 movmi r2, #0
 *   @0x10ea88 movmi r3, #0
 *   @0x10ea8c vmovpl r2, r3, d6
 *   @0x10ea90 stm r4, {r2, r3}
 *   @0x10ea94 pop {r4, r5, r6, pc}
 *   @0x10ea98 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §184/281 F_StringPos(RValue&, CInstance*, CInstance*, int, RValue*)  0x111294  size 104  26 条（0x111294..0x1112fc）
 * @func 0x111294 0x1112fc  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / StringPos(char const*, char const*)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111294 push {r4, r5, r6, lr}
 *   @0x111298 mov r1, #0
 *   @0x11129c ldr r5, [sp, #0x10]
 *   @0x1112a0 mov r4, r0
 *   @0x1112a4 mov r0, r5
 *   @0x1112a8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1112ac mov r1, #1
 *   @0x1112b0 mov r6, r0
 *   @0x1112b4 mov r0, r5
 *   @0x1112b8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1112bc mov r3, #0
 *   @0x1112c0 str r3, [r4, #0xc]
 *   @0x1112c4 cmp r6, r3
 *   @0x1112c8 cmpne r0, r3
 *   @0x1112cc mov r1, r0
 *   @0x1112d0 streq r3, [r4]
 *   @0x1112d4 streq r3, [r4, #0x4]
 *   @0x1112d8 popeq {r4, r5, r6, pc}
 *   @0x1112dc mov r0, r6
 *   @0x1112e0 bl 0x1111e0 <_Z9StringPosPKcS0_>
 *   @0x1112e4 add r0, r0, #1
 *   @0x1112e8 vmov s15, r0
 *   @0x1112ec vcvt.f64.s32 d7, s15
 *   @0x1112f0 vmov r2, r3, d7
 *   @0x1112f4 stm r4, {r2, r3}
 *   @0x1112f8 pop {r4, r5, r6, pc}
 *
 * ══ §185/281 F_DateYearSpan(RValue&, CInstance*, CInstance*, int, RValue*)  0x115360  size 104  26 条（0x115360..0x1153c8）
 * @func 0x115360 0x1153d8  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115360 push {r3, r4, r5, lr}
 *   @0x115364 vpush {d8}
 *   @0x115368 mov r3, #0
 *   @0x11536c ldr r5, [sp, #0x18]
 *   @0x115370 mov r1, r3
 *   @0x115374 str r3, [r0, #0xc]
 *   @0x115378 mov r4, r0
 *   @0x11537c str r3, [r0]
 *   @0x115380 str r3, [r0, #0x4]
 *   @0x115384 mov r0, r5
 *   @0x115388 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11538c vmov d8, r0, r1
 *   @0x115390 mov r0, r5
 *   @0x115394 mov r1, #1
 *   @0x115398 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11539c vldr d7, [pc, #28]
 *   @0x1153a0 vmov d6, r0, r1
 *   @0x1153a4 vsub.f64 d8, d8, d6
 *   @0x1153a8 vmul.f64 d8, d8, d7
 *   @0x1153ac vabs.f64 d7, d8
 *   @0x1153b0 vmov r2, r3, d7
 *   @0x1153b4 stm r4, {r2, r3}
 *   @0x1153b8 vpop {d8}
 *   @0x1153bc pop {r3, r4, r5, pc}
 *   @0x1153c0 rscsvc r2, r2, #5046272
 *   @0x1153c4 svclo #0x666db0
 *
 * ══ §186/281 F_DateMonthSpan(RValue&, CInstance*, CInstance*, int, RValue*)  0x1153c8  size 104  26 条（0x1153c8..0x115430）
 * @func 0x1153c8 0x115440  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1153c8 push {r3, r4, r5, lr}
 *   @0x1153cc vpush {d8}
 *   @0x1153d0 mov r3, #0
 *   @0x1153d4 ldr r5, [sp, #0x18]
 *   @0x1153d8 mov r1, r3
 *   @0x1153dc str r3, [r0, #0xc]
 *   @0x1153e0 mov r4, r0
 *   @0x1153e4 str r3, [r0]
 *   @0x1153e8 str r3, [r0, #0x4]
 *   @0x1153ec mov r0, r5
 *   @0x1153f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1153f4 vmov d8, r0, r1
 *   @0x1153f8 mov r0, r5
 *   @0x1153fc mov r1, #1
 *   @0x115400 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115404 vldr d7, [pc, #28]
 *   @0x115408 vmov d6, r0, r1
 *   @0x11540c vsub.f64 d8, d8, d6
 *   @0x115410 vmul.f64 d8, d8, d7
 *   @0x115414 vabs.f64 d7, d8
 *   @0x115418 vmov r2, r3, d7
 *   @0x11541c stm r4, {r2, r3}
 *   @0x115420 vpop {d8}
 *   @0x115424 pop {r3, r4, r5, pc}
 *   @0x115428 shasxpl r9, r5, r10
 *   @0x11542c svclo #0xa0d244
 *
 * ══ §187/281 F_DateWeekSpan(RValue&, CInstance*, CInstance*, int, RValue*)  0x115430  size 104  26 条（0x115430..0x115498）
 * @func 0x115430 0x1154a8  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115430 push {r3, r4, r5, lr}
 *   @0x115434 vpush {d8}
 *   @0x115438 mov r3, #0
 *   @0x11543c ldr r5, [sp, #0x18]
 *   @0x115440 mov r1, r3
 *   @0x115444 str r3, [r0, #0xc]
 *   @0x115448 mov r4, r0
 *   @0x11544c str r3, [r0]
 *   @0x115450 str r3, [r0, #0x4]
 *   @0x115454 mov r0, r5
 *   @0x115458 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11545c vmov d8, r0, r1
 *   @0x115460 mov r0, r5
 *   @0x115464 mov r1, #1
 *   @0x115468 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11546c vldr d7, [pc, #28]
 *   @0x115470 vmov d6, r0, r1
 *   @0x115474 vsub.f64 d8, d8, d6
 *   @0x115478 vmul.f64 d8, d8, d7
 *   @0x11547c vabs.f64 d7, d8
 *   @0x115480 vmov r2, r3, d7
 *   @0x115484 stm r4, {r2, r3}
 *   @0x115488 vpop {d8}
 *   @0x11548c pop {r3, r4, r5, pc}
 *   @0x115490 subls r2, r9, #-1845493760
 *   @0x115494 svclo #0xc24924
 *
 * ══ §188/281 F_DateMinuteSpan(RValue&, CInstance*, CInstance*, int, RValue*)  0x115568  size 104  26 条（0x115568..0x1155d0）
 * @func 0x115568 0x1155e0  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115568 push {r3, r4, r5, lr}
 *   @0x11556c vpush {d8}
 *   @0x115570 mov r3, #0
 *   @0x115574 ldr r5, [sp, #0x18]
 *   @0x115578 mov r1, r3
 *   @0x11557c str r3, [r0, #0xc]
 *   @0x115580 mov r4, r0
 *   @0x115584 str r3, [r0]
 *   @0x115588 str r3, [r0, #0x4]
 *   @0x11558c mov r0, r5
 *   @0x115590 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115594 vmov d8, r0, r1
 *   @0x115598 mov r0, r5
 *   @0x11559c mov r1, #1
 *   @0x1155a0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1155a4 vldr d7, [pc, #28]
 *   @0x1155a8 vmov d6, r0, r1
 *   @0x1155ac vsub.f64 d8, d8, d6
 *   @0x1155b0 vmul.f64 d8, d8, d7
 *   @0x1155b4 vabs.f64 d7, d8
 *   @0x1155b8 vmov r2, r3, d7
 *   @0x1155bc stm r4, {r2, r3}
 *   @0x1155c0 vpop {d8}
 *   @0x1155c4 pop {r3, r4, r5, pc}
 *   @0x1155c8 andeq r0, r0, r0
 *   @0x1155cc addsmi r8, r6, r0
 *
 * ══ §189/281 F_DateSecondSpan(RValue&, CInstance*, CInstance*, int, RValue*)  0x1155d0  size 104  26 条（0x1155d0..0x115638）
 * @func 0x1155d0 0x115638  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1155d0 push {r3, r4, r5, lr}
 *   @0x1155d4 vpush {d8}
 *   @0x1155d8 mov r3, #0
 *   @0x1155dc ldr r5, [sp, #0x18]
 *   @0x1155e0 mov r1, r3
 *   @0x1155e4 str r3, [r0, #0xc]
 *   @0x1155e8 mov r4, r0
 *   @0x1155ec str r3, [r0]
 *   @0x1155f0 str r3, [r0, #0x4]
 *   @0x1155f4 mov r0, r5
 *   @0x1155f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1155fc vmov d8, r0, r1
 *   @0x115600 mov r0, r5
 *   @0x115604 mov r1, #1
 *   @0x115608 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11560c vldr d7, [pc, #28]
 *   @0x115610 vmov d6, r0, r1
 *   @0x115614 vsub.f64 d8, d8, d6
 *   @0x115618 vmul.f64 d8, d8, d7
 *   @0x11561c vabs.f64 d7, d8
 *   @0x115620 vmov r2, r3, d7
 *   @0x115624 stm r4, {r2, r3}
 *   @0x115628 vpop {d8}
 *   @0x11562c pop {r3, r4, r5, pc}
 *   @0x115630 andeq r0, r0, r0
 *   @0x115634 rscsmi r1, r5, r0, lsl #16
 *
 * ══ §190/281 F_MergeColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x11aba0  size 104  26 条（0x11aba0..0x11ac08）
 * @func 0x11aba0 0x11ac08  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int) / Color_Merge(unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11aba0 push {r3, r4, r5, r6, r7, lr}
 *   @0x11aba4 mov r1, #0
 *   @0x11aba8 ldr r4, [sp, #0x18]
 *   @0x11abac mov r5, r0
 *   @0x11abb0 str r1, [r0, #0xc]
 *   @0x11abb4 mov r0, r4
 *   @0x11abb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11abbc mov r1, #1
 *   @0x11abc0 mov r7, r0
 *   @0x11abc4 mov r0, r4
 *   @0x11abc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11abcc mov r1, #2
 *   @0x11abd0 mov r6, r0
 *   @0x11abd4 mov r0, r4
 *   @0x11abd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11abdc mov r1, r6
 *   @0x11abe0 mov r2, r0
 *   @0x11abe4 mov r0, r7
 *   @0x11abe8 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0x11abec vmov s15, r0
 *   @0x11abf0 vcvt.f64.u32 d7, s15
 *   @0x11abf4 vmov r0, r1, d7
 *   @0x11abf8 vmov r2, s14
 *   @0x11abfc mov r3, r1
 *   @0x11ac00 stm r5, {r2, r3}
 *   @0x11ac04 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §191/281 F_SkeletonGetAnimation(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cb68  size 104  26 条（0x11cb68..0x11cbd0）
 * @func 0x11cb68 0x11cbd0  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / CSkeletonInstance::GetAnimation(int) const / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cb68 push {r4, r5, r6, r7, r8, lr}
 *   @0x11cb6c mov r4, r0
 *   @0x11cb70 mov r2, #1
 *   @0x11cb74 mov r0, r1
 *   @0x11cb78 str r2, [r4, #0xc]
 *   @0x11cb7c mov r5, #0
 *   @0x11cb80 str r5, [r4]
 *   @0x11cb84 mov r6, r3
 *   @0x11cb88 ldr r8, [sp, #0x18]
 *   @0x11cb8c bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cb90 subs r7, r0, #0
 *   @0x11cb94 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x11cb98 cmp r6, #1
 *   @0x11cb9c movne r1, r5
 *   @0x11cba0 beq 0x11cbbc <_Z22F_SkeletonGetAnimationR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x11cba4 mov r0, r7
 *   @0x11cba8 bl 0xc01b0 <_ZNK17CSkeletonInstance12GetAnimationEi>
 *   @0x11cbac mov r1, r0
 *   @0x11cbb0 mov r0, r4
 *   @0x11cbb4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11cbb8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x11cbbc mov r1, r5
 *   @0x11cbc0 mov r0, r8
 *   @0x11cbc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11cbc8 mov r1, r0
 *   @0x11cbcc b 0x11cba4 <_Z22F_SkeletonGetAnimationR6RValueP9CInstanceS2_iPS_+0x3c>
 *
 * ══ §192/281 F_DrawSurface(RValue&, CInstance*, CInstance*, int, RValue*)  0x11e8ec  size 104  26 条（0x11e8ec..0x11e954）
 * @func 0x11e8ec 0x11e954  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / GR_Surface_Exists(int)
 * 字段偏移 top8: 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11e8ec push {r4, r5, r6, lr}
 *   @0x11e8f0 mov r1, #0
 *   @0x11e8f4 ldr r4, [sp, #0x10]
 *   @0x11e8f8 mov r0, r4
 *   @0x11e8fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e900 mov r5, r0
 *   @0x11e904 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11e908 subs r1, r0, #0
 *   @0x11e90c beq 0x11e940 <_Z13F_DrawSurfaceR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x11e910 mov r0, r4
 *   @0x11e914 mov r1, #1
 *   @0x11e918 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e91c mov r1, #2
 *   @0x11e920 mov r6, r0
 *   @0x11e924 mov r0, r4
 *   @0x11e928 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e92c mov r1, r6
 *   @0x11e930 mov r2, r0
 *   @0x11e934 mov r0, r5
 *   @0x11e938 pop {r4, r5, r6, lr}
 *   @0x11e93c b 0x171d90 <_Z21GR_Surface_DrawSimpleiff>
 *   @0x11e940 ldr r0, [pc, #0x8]
 *   @0x11e944 pop {r4, r5, r6, lr}
 *   @0x11e948 add r0, pc, r0
 *   @0x11e94c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11e950 eoreq r11, r1, r0, lsr #18
 *
 * ══ §193/281 YYGML_draw_sprite_ext(CInstance*, int, int, float, float, float, float, float, int, float)  0x123174  size 104  26 条（0x123174..0x1231dc）
 * @func 0x123174 0x1231dc  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Data(int)
 * 字段偏移 top8: 0x28×2 / 0x2c×2 / 0x30×2 / 0x34×2 / 0x38×2 / 0x3c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x123174 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x123178 subs r4, r2, #0
 *   @0x12317c vldrlt s15, [r0, #144]
 *   @0x123180 sub sp, sp, #4
 *   @0x123184 mov r0, r1
 *   @0x123188 vcvtlt.s32.f32 s15, s15
 *   @0x12318c mov r6, r3
 *   @0x123190 ldr r5, [sp, #0x28]
 *   @0x123194 ldr r11, [sp, #0x2c]
 *   @0x123198 ldr r10, [sp, #0x30]
 *   @0x12319c ldr r9, [sp, #0x34]
 *   @0x1231a0 ldr r7, [sp, #0x38]
 *   @0x1231a4 ldr r8, [sp, #0x3c]
 *   @0x1231a8 vmovlt r4, s15
 *   @0x1231ac bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1231b0 str r11, [sp, #0x28]
 *   @0x1231b4 mov r2, r6
 *   @0x1231b8 str r10, [sp, #0x2c]
 *   @0x1231bc mov r3, r5
 *   @0x1231c0 str r9, [sp, #0x30]
 *   @0x1231c4 str r7, [sp, #0x34]
 *   @0x1231c8 str r8, [sp, #0x38]
 *   @0x1231cc mov r1, r4
 *   @0x1231d0 add sp, sp, #4
 *   @0x1231d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1231d8 b 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *
 * ══ §194/281 F_BackgroundDuplicate(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cb3c  size 104  26 条（0x12cb3c..0x12cba4）
 * @func 0x12cb3c 0x12cba4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Exists(int) / Background_Duplicate(int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cb3c push {r3, r4, r5, lr}
 *   @0x12cb40 mov r1, #0
 *   @0x12cb44 mov r4, r0
 *   @0x12cb48 ldr r0, [sp, #0x10]
 *   @0x12cb4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cb50 mov r5, r0
 *   @0x12cb54 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x12cb58 subs r1, r0, #0
 *   @0x12cb5c beq 0x12cb84 <_Z21F_BackgroundDuplicateR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12cb60 mov r0, r5
 *   @0x12cb64 bl 0xc3ff4 <_Z20Background_Duplicatei>
 *   @0x12cb68 vmov s15, r0
 *   @0x12cb6c vcvt.f64.s32 d7, s15
 *   @0x12cb70 vmov r2, r3, d7
 *   @0x12cb74 mov r1, #0
 *   @0x12cb78 stm r4, {r2, r3}
 *   @0x12cb7c str r1, [r4, #0xc]
 *   @0x12cb80 pop {r3, r4, r5, pc}
 *   @0x12cb84 ldr r0, [pc, #0x14]
 *   @0x12cb88 add r0, pc, r0
 *   @0x12cb8c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12cb90 mov r3, #0
 *   @0x12cb94 mov r2, #0
 *   @0x12cb98 movt r3, #0xbff0
 *   @0x12cb9c b 0x12cb74 <_Z21F_BackgroundDuplicateR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x12cba0 eoreq r0, r1, r8, lsl #19
 *
 * ══ §195/281 F_PathGetPointX(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d684  size 104  26 条（0x12d684..0x12d6ec）
 * @func 0x12d684 0x12d6fc  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Path_Data(int) / CPath::GetPoint(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d684 push {r4, r5, r6, lr}
 *   @0x12d688 mov r1, #0
 *   @0x12d68c ldr r5, [sp, #0x10]
 *   @0x12d690 mov r4, r0
 *   @0x12d694 mov r0, r5
 *   @0x12d698 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d69c bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d6a0 subs r6, r0, #0
 *   @0x12d6a4 beq 0x12d6dc <_Z15F_PathGetPointXR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x12d6a8 mov r1, #1
 *   @0x12d6ac mov r0, r5
 *   @0x12d6b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d6b4 mov r1, r0
 *   @0x12d6b8 mov r0, r6
 *   @0x12d6bc bl 0x1a5f34 <_ZN5CPath8GetPointEi>
 *   @0x12d6c0 vldr s15, [r0]
 *   @0x12d6c4 vcvt.f64.f32 d6, s15
 *   @0x12d6c8 vmov r2, r3, d6
 *   @0x12d6cc mov r1, #0
 *   @0x12d6d0 stm r4, {r2, r3}
 *   @0x12d6d4 str r1, [r4, #0xc]
 *   @0x12d6d8 pop {r4, r5, r6, pc}
 *   @0x12d6dc mov r3, #0
 *   @0x12d6e0 mov r2, #0
 *   @0x12d6e4 movt r3, #0xbff0
 *   @0x12d6e8 b 0x12d6cc <_Z15F_PathGetPointXR6RValueP9CInstanceS2_iPS_+0x48>
 *
 * ══ §196/281 F_PathGetPointY(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d6ec  size 104  26 条（0x12d6ec..0x12d754）
 * @func 0x12d6ec 0x12d764  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Path_Data(int) / CPath::GetPoint(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d6ec push {r4, r5, r6, lr}
 *   @0x12d6f0 mov r1, #0
 *   @0x12d6f4 ldr r5, [sp, #0x10]
 *   @0x12d6f8 mov r4, r0
 *   @0x12d6fc mov r0, r5
 *   @0x12d700 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d704 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d708 subs r6, r0, #0
 *   @0x12d70c beq 0x12d744 <_Z15F_PathGetPointYR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x12d710 mov r1, #1
 *   @0x12d714 mov r0, r5
 *   @0x12d718 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d71c mov r1, r0
 *   @0x12d720 mov r0, r6
 *   @0x12d724 bl 0x1a5f34 <_ZN5CPath8GetPointEi>
 *   @0x12d728 vldr s15, [r0, #4]
 *   @0x12d72c vcvt.f64.f32 d6, s15
 *   @0x12d730 vmov r2, r3, d6
 *   @0x12d734 mov r1, #0
 *   @0x12d738 stm r4, {r2, r3}
 *   @0x12d73c str r1, [r4, #0xc]
 *   @0x12d740 pop {r4, r5, r6, pc}
 *   @0x12d744 mov r3, #0
 *   @0x12d748 mov r2, #0
 *   @0x12d74c movt r3, #0xbff0
 *   @0x12d750 b 0x12d734 <_Z15F_PathGetPointYR6RValueP9CInstanceS2_iPS_+0x48>
 *
 * ══ §197/281 F_PathGetPointSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d754  size 104  26 条（0x12d754..0x12d7bc）
 * @func 0x12d754 0x12d7cc  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Path_Data(int) / CPath::GetPoint(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d754 push {r4, r5, r6, lr}
 *   @0x12d758 mov r1, #0
 *   @0x12d75c ldr r5, [sp, #0x10]
 *   @0x12d760 mov r4, r0
 *   @0x12d764 mov r0, r5
 *   @0x12d768 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d76c bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d770 subs r6, r0, #0
 *   @0x12d774 beq 0x12d7ac <_Z19F_PathGetPointSpeedR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x12d778 mov r1, #1
 *   @0x12d77c mov r0, r5
 *   @0x12d780 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d784 mov r1, r0
 *   @0x12d788 mov r0, r6
 *   @0x12d78c bl 0x1a5f34 <_ZN5CPath8GetPointEi>
 *   @0x12d790 vldr s15, [r0, #8]
 *   @0x12d794 vcvt.f64.f32 d6, s15
 *   @0x12d798 vmov r2, r3, d6
 *   @0x12d79c mov r1, #0
 *   @0x12d7a0 stm r4, {r2, r3}
 *   @0x12d7a4 str r1, [r4, #0xc]
 *   @0x12d7a8 pop {r4, r5, r6, pc}
 *   @0x12d7ac mov r3, #0
 *   @0x12d7b0 mov r2, #0
 *   @0x12d7b4 movt r3, #0xbff0
 *   @0x12d7b8 b 0x12d79c <_Z19F_PathGetPointSpeedR6RValueP9CInstanceS2_iPS_+0x48>
 *
 * ══ §198/281 F_PathGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d7bc  size 104  26 条（0x12d7bc..0x12d824）
 * @func 0x12d7bc 0x12d834  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / YYGetFloat(RValue const*, int) / CPath::XPosition(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d7bc push {r4, r5, r6, lr}
 *   @0x12d7c0 mov r1, #0
 *   @0x12d7c4 ldr r5, [sp, #0x10]
 *   @0x12d7c8 mov r4, r0
 *   @0x12d7cc mov r0, r5
 *   @0x12d7d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d7d4 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d7d8 subs r6, r0, #0
 *   @0x12d7dc beq 0x12d814 <_Z10F_PathGetXR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x12d7e0 mov r1, #1
 *   @0x12d7e4 mov r0, r5
 *   @0x12d7e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12d7ec mov r1, r0
 *   @0x12d7f0 mov r0, r6
 *   @0x12d7f4 bl 0x1a7598 <_ZN5CPath9XPositionEf>
 *   @0x12d7f8 vmov s15, r0
 *   @0x12d7fc vcvt.f64.f32 d7, s15
 *   @0x12d800 vmov r2, r3, d7
 *   @0x12d804 mov r1, #0
 *   @0x12d808 stm r4, {r2, r3}
 *   @0x12d80c str r1, [r4, #0xc]
 *   @0x12d810 pop {r4, r5, r6, pc}
 *   @0x12d814 mov r3, #0
 *   @0x12d818 mov r2, #0
 *   @0x12d81c movt r3, #0xbff0
 *   @0x12d820 b 0x12d804 <_Z10F_PathGetXR6RValueP9CInstanceS2_iPS_+0x48>
 *
 * ══ §199/281 F_PathGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d824  size 104  26 条（0x12d824..0x12d88c）
 * @func 0x12d824 0x12d89c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / YYGetFloat(RValue const*, int) / CPath::YPosition(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d824 push {r4, r5, r6, lr}
 *   @0x12d828 mov r1, #0
 *   @0x12d82c ldr r5, [sp, #0x10]
 *   @0x12d830 mov r4, r0
 *   @0x12d834 mov r0, r5
 *   @0x12d838 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d83c bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d840 subs r6, r0, #0
 *   @0x12d844 beq 0x12d87c <_Z10F_PathGetYR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x12d848 mov r1, #1
 *   @0x12d84c mov r0, r5
 *   @0x12d850 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12d854 mov r1, r0
 *   @0x12d858 mov r0, r6
 *   @0x12d85c bl 0x1a75c0 <_ZN5CPath9YPositionEf>
 *   @0x12d860 vmov s15, r0
 *   @0x12d864 vcvt.f64.f32 d7, s15
 *   @0x12d868 vmov r2, r3, d7
 *   @0x12d86c mov r1, #0
 *   @0x12d870 stm r4, {r2, r3}
 *   @0x12d874 str r1, [r4, #0xc]
 *   @0x12d878 pop {r4, r5, r6, pc}
 *   @0x12d87c mov r3, #0
 *   @0x12d880 mov r2, #0
 *   @0x12d884 movt r3, #0xbff0
 *   @0x12d888 b 0x12d86c <_Z10F_PathGetYR6RValueP9CInstanceS2_iPS_+0x48>
 *
 * ══ §200/281 F_PathGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d88c  size 104  26 条（0x12d88c..0x12d8f4）
 * @func 0x12d88c 0x12d8f4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / YYGetFloat(RValue const*, int) / CPath::Speed(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d88c push {r4, r5, r6, lr}
 *   @0x12d890 mov r1, #0
 *   @0x12d894 ldr r5, [sp, #0x10]
 *   @0x12d898 mov r4, r0
 *   @0x12d89c mov r0, r5
 *   @0x12d8a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d8a4 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d8a8 subs r6, r0, #0
 *   @0x12d8ac beq 0x12d8e4 <_Z14F_PathGetSpeedR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x12d8b0 mov r1, #1
 *   @0x12d8b4 mov r0, r5
 *   @0x12d8b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12d8bc mov r1, r0
 *   @0x12d8c0 mov r0, r6
 *   @0x12d8c4 bl 0x1a75e8 <_ZN5CPath5SpeedEf>
 *   @0x12d8c8 vmov s15, r0
 *   @0x12d8cc vcvt.f64.f32 d7, s15
 *   @0x12d8d0 vmov r2, r3, d7
 *   @0x12d8d4 mov r1, #0
 *   @0x12d8d8 stm r4, {r2, r3}
 *   @0x12d8dc str r1, [r4, #0xc]
 *   @0x12d8e0 pop {r4, r5, r6, pc}
 *   @0x12d8e4 mov r3, #0
 *   @0x12d8e8 mov r2, #0
 *   @0x12d8ec movt r3, #0xbff0
 *   @0x12d8f0 b 0x12d8d4 <_Z14F_PathGetSpeedR6RValueP9CInstanceS2_iPS_+0x48>
 *
 * ══ §201/281 F_ActionSleep(RValue&, CInstance*, CInstance*, int, RValue*)  0x13eae0  size 104  26 条（0x13eae0..0x13eb48）
 * @func 0x13eae0 0x13eb48  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / YYGetBool(RValue const*, int) / Draw_Room() / GR_D3D_Finish_Frame(bool) / GR_D3D_Start_Frame() / 0xb66e8
 * 字段偏移 top8: 0x10×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13eae0 push {r4, lr}
 *   @0x13eae4 vpush {d8}
 *   @0x13eae8 mov r1, #0
 *   @0x13eaec ldr r4, [sp, #0x10]
 *   @0x13eaf0 mov r0, r4
 *   @0x13eaf4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13eaf8 vmov d8, r0, r1
 *   @0x13eafc mov r0, r4
 *   @0x13eb00 mov r1, #1
 *   @0x13eb04 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x13eb08 cmp r0, #0
 *   @0x13eb0c beq 0x13eb20 <_Z13F_ActionSleepR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x13eb10 bl 0x1b3e98 <_Z9Draw_Roomv>
 *   @0x13eb14 mov r0, #1
 *   @0x13eb18 bl 0x169a58 <_Z19GR_D3D_Finish_Frameb>
 *   @0x13eb1c bl 0x1699c0 <_Z18GR_D3D_Start_Framev>
 *   @0x13eb20 vldr d7, [pc, #24]
 *   @0x13eb24 vmul.f64 d6, d8, d7
 *   @0x13eb28 vmov r0, r1, d6
 *   @0x13eb2c bl 0xb66e8 <lrint@plt>
 *   @0x13eb30 vpop {d8}
 *   @0x13eb34 pop {r4, lr}
 *   @0x13eb38 asr r1, r0, #31
 *   @0x13eb3c b 0x2151f0 <Timing_Sleep>
 *   @0x13eb40 andeq r0, r0, r0
 *   @0x13eb44 addmi r4, pc, r0
 *
 * ══ §202/281 F_D3DBuildMatrixIdentity(RValue&, CInstance*, CInstance*, int, RValue*)  0x144a78  size 104  26 条（0x144a78..0x144ae0）
 * @func 0x144a78 0x144ae0  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144a78 push {r4, r5, lr}
 *   @0x144a7c sub sp, sp, #124
 *   @0x144a80 mov r4, #0
 *   @0x144a84 mov r5, #0
 *   @0x144a88 mov r2, #0
 *   @0x144a8c mov r1, #16
 *   @0x144a90 strd r4, r5, [sp]
 *   @0x144a94 mov r3, #0
 *   @0x144a98 strd r4, r5, [sp, #8]
 *   @0x144a9c movt r3, #0x3ff0
 *   @0x144aa0 strd r4, r5, [sp, #16]
 *   @0x144aa4 strd r4, r5, [sp, #24]
 *   @0x144aa8 strd r4, r5, [sp, #40]
 *   @0x144aac strd r4, r5, [sp, #48]
 *   @0x144ab0 strd r4, r5, [sp, #56]
 *   @0x144ab4 strd r4, r5, [sp, #64]
 *   @0x144ab8 strd r4, r5, [sp, #80]
 *   @0x144abc strd r4, r5, [sp, #88]
 *   @0x144ac0 strd r4, r5, [sp, #96]
 *   @0x144ac4 strd r4, r5, [sp, #104]
 *   @0x144ac8 strd r2, r3, [sp, #32]
 *   @0x144acc strd r2, r3, [sp, #72]
 *   @0x144ad0 strd r2, r3, [sp, #112]
 *   @0x144ad4 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x144ad8 add sp, sp, #124
 *   @0x144adc pop {r4, r5, pc}
 *
 * ══ §203/281 F_YoYo_DrawTextureFlush(RValue&, CInstance*, CInstance*, int, RValue*)  0x146530  size 104  26 条（0x146530..0x146598）
 * @func 0x146530 0x146598  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush() / Graphics::TextureFlush(bool)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x34×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146530 push {r4, lr}
 *   @0x146534 mov r4, #0
 *   @0x146538 str r4, [r0, #0xc]
 *   @0x14653c str r4, [r0]
 *   @0x146540 str r4, [r0, #0x4]
 *   @0x146544 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x146548 mov r0, r4
 *   @0x14654c bl 0x1767d0 <_ZN8Graphics12TextureFlushEb>
 *   @0x146550 ldr r3, [pc, #0x34]
 *   @0x146554 ldr r3, [pc, r3]
 *   @0x146558 ldrb r3, [r3]
 *   @0x14655c cmp r3, r4
 *   @0x146560 popeq {r4, pc}
 *   @0x146564 ldr r3, [pc, #0x24]
 *   @0x146568 ldr r3, [pc, r3]
 *   @0x14656c ldr r3, [r3]
 *   @0x146570 cmp r3, r4
 *   @0x146574 popne {r4, pc}
 *   @0x146578 ldr r1, [pc, #0x14]
 *   @0x14657c mov r0, #4
 *   @0x146580 pop {r4, lr}
 *   @0x146584 add r1, pc, r1
 *   @0x146588 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x14658c .word 0x002a73d0
 *   @0x146590 .word 0x002a7eb8
 *   @0x146594 andseq r11, pc, r8, ror #1
 *
 * ══ §204/281 F_GPUGetTexFilter(RValue&, CInstance*, CInstance*, int, RValue*)  0x1484f4  size 104  26 条（0x1484f4..0x14855c）
 * @func 0x1484f4 0x14855c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1484f4 push {r3, r4, r5, lr}
 *   @0x1484f8 subs r5, r3, #0
 *   @0x1484fc mov r1, #0
 *   @0x148500 mov r4, r0
 *   @0x148504 str r1, [r0, #0xc]
 *   @0x148508 str r1, [r0]
 *   @0x14850c str r1, [r0, #0x4]
 *   @0x148510 bne 0x148544 <_Z17F_GPUGetTexFilterR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x148514 ldr r0, [pc, #0x38]
 *   @0x148518 mov r1, r5
 *   @0x14851c mov r2, r5
 *   @0x148520 ldr r0, [pc, r0]
 *   @0x148524 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x148528 str r5, [r4]
 *   @0x14852c cmp r0, #1
 *   @0x148530 moveq r3, #0
 *   @0x148534 movne r3, r5
 *   @0x148538 movteq r3, #0x3ff0
 *   @0x14853c str r3, [r4, #0x4]
 *   @0x148540 pop {r3, r4, r5, pc}
 *   @0x148544 ldr r0, [pc, #0xc]
 *   @0x148548 pop {r3, r4, r5, lr}
 *   @0x14854c add r0, pc, r0
 *   @0x148550 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148554 .word 0x002a57d8
 *   @0x148558 ldrsheq r9, [pc], -r8
 *
 * ══ §205/281 F_PhysicsJointSetValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bc48  size 104  26 条（0x14bc48..0x14bcb0）
 * @func 0x14bc48 0x14bcb0  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CPhysicsJointFactory::FindJoint(unsigned int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bc48 push {r4, r5, r6, lr}
 *   @0x14bc4c mov r1, #0
 *   @0x14bc50 ldr r4, [sp, #0x10]
 *   @0x14bc54 mov r0, r4
 *   @0x14bc58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bc5c bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj>
 *   @0x14bc60 subs r5, r0, #0
 *   @0x14bc64 beq 0x14bc98 <_Z22F_PhysicsJointSetValueR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x14bc68 mov r0, r4
 *   @0x14bc6c mov r1, #1
 *   @0x14bc70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bc74 mov r1, #2
 *   @0x14bc78 mov r6, r0
 *   @0x14bc7c mov r0, r4
 *   @0x14bc80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14bc84 mov r1, r6
 *   @0x14bc88 mov r2, r0
 *   @0x14bc8c mov r0, r5
 *   @0x14bc90 pop {r4, r5, r6, lr}
 *   @0x14bc94 b 0x23bb14 <_ZN13CPhysicsJoint8SetValueEif>
 *   @0x14bc98 ldr r0, [pc, #0xc]
 *   @0x14bc9c mov r1, r5
 *   @0x14bca0 pop {r4, r5, r6, lr}
 *   @0x14bca4 add r0, pc, r0
 *   @0x14bca8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bcac andseq r8, pc, r8, lsr #2
 *
 * ══ §206/281 F_PhysicsParticleSetRadius(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e9f4  size 104  26 条（0x14e9f4..0x14ea5c）
 * @func 0x14e9f4 0x14ea5c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x58×1 / 0x8×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e9f4 ldr r3, [pc, #0x58]
 *   @0x14e9f8 push {r4, lr}
 *   @0x14e9fc ldr r3, [pc, r3]
 *   @0x14ea00 ldr r0, [sp, #0x8]
 *   @0x14ea04 ldr r3, [r3]
 *   @0x14ea08 cmp r3, #0
 *   @0x14ea0c beq 0x14ea40 <_Z26F_PhysicsParticleSetRadiusR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14ea10 ldr r4, [r3, #0xb4]
 *   @0x14ea14 cmp r4, #0
 *   @0x14ea18 beq 0x14ea40 <_Z26F_PhysicsParticleSetRadiusR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14ea1c mov r1, #0
 *   @0x14ea20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14ea24 vldr s15, [r4, #96]
 *   @0x14ea28 vmov s14, r0
 *   @0x14ea2c ldr r0, [r4, #0x10]
 *   @0x14ea30 pop {r4, lr}
 *   @0x14ea34 vmul.f32 s15, s14, s15
 *   @0x14ea38 vmov r1, s15
 *   @0x14ea3c b 0x2cb48c <_ZN7b2World17SetParticleRadiusEf>
 *   @0x14ea40 ldr r0, [pc, #0x10]
 *   @0x14ea44 mov r1, #0
 *   @0x14ea48 pop {r4, lr}
 *   @0x14ea4c add r0, pc, r0
 *   @0x14ea50 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ea54 eoreq lr, r9, r12, lsr #30
 *   @0x14ea58 andseq r6, pc, r4, lsr r2
 *
 * ══ §207/281 F_GamepadGetDescription(RValue&, CInstance*, CInstance*, int, RValue*)  0x1513bc  size 104  26 条（0x1513bc..0x151424）
 * @func 0x1513bc 0x151424  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x2c×1 / 0x1c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1513bc push {r4, lr}
 *   @0x1513c0 mov r2, #1
 *   @0x1513c4 ldr r3, [sp, #0x8]
 *   @0x1513c8 mov r1, #0
 *   @0x1513cc str r2, [r0, #0xc]
 *   @0x1513d0 mov r4, r0
 *   @0x1513d4 str r1, [r0]
 *   @0x1513d8 mov r0, r3
 *   @0x1513dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1513e0 subs r2, r0, #0
 *   @0x1513e4 poplt {r4, pc}
 *   @0x1513e8 ldr r3, [pc, #0x2c]
 *   @0x1513ec ldr r3, [pc, r3]
 *   @0x1513f0 ldr r3, [r3]
 *   @0x1513f4 cmp r2, r3
 *   @0x1513f8 popge {r4, pc}
 *   @0x1513fc ldr r3, [pc, #0x1c]
 *   @0x151400 mov r0, r4
 *   @0x151404 pop {r4, lr}
 *   @0x151408 ldr r3, [pc, r3]
 *   @0x15140c ldr r3, [r3]
 *   @0x151410 ldr r1, [r3, r2, lsl #2]
 *   @0x151414 add r1, r1, #44
 *   @0x151418 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x15141c eoreq lr, r9, r4, ror r6
 *   @0x151420 eoreq lr, r9, r12, asr r6
 *
 * ══ §208/281 F_Push_CancelLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*)  0x155ae8  size 104  26 条（0x155ae8..0x155b50）
 * @func 0x155ae8 0x155b50  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Push_CancelLocalNotification(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x10×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155ae8 push {r4, lr}
 *   @0x155aec mov r1, #0
 *   @0x155af0 mov r3, r1
 *   @0x155af4 str r1, [r0, #0xc]
 *   @0x155af8 movt r3, #0xbff0
 *   @0x155afc mov r4, r0
 *   @0x155b00 stm r0, {r1, r3}
 *   @0x155b04 ldr r0, [sp, #0x8]
 *   @0x155b08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x155b0c bl 0x161c48 <_Z28Push_CancelLocalNotificationi>
 *   @0x155b10 vmov s15, r0
 *   @0x155b14 vcvt.f64.s32 d7, s15
 *   @0x155b18 vmov r0, r1, d7
 *   @0x155b1c vmov r2, s14
 *   @0x155b20 vcmp.f64 d7, #0
 *   @0x155b24 vmrs APSR_nzcv, fpscr
 *   @0x155b28 mov r3, r1
 *   @0x155b2c stm r4, {r2, r3}
 *   @0x155b30 popeq {r4, pc}
 *   @0x155b34 ldr r3, [pc, #0x10]
 *   @0x155b38 add r3, pc, r3
 *   @0x155b3c ldr r2, [r3]
 *   @0x155b40 sub r2, r2, #1
 *   @0x155b44 str r2, [r3]
 *   @0x155b48 pop {r4, pc}
 *   @0x155b4c eoreq r12, r9, r12, lsl r8
 *
 * ══ §209/281 F_YoYo_FacebookDialog(RValue&, CInstance*, CInstance*, int, RValue*)  0x157328  size 104  26 条（0x157328..0x157390）
 * @func 0x157328 0x157390  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / FacebookDialogM(char*, int, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157328 push {r3, r4, r5, r6, r7, lr}
 *   @0x15732c mov r1, #0
 *   @0x157330 ldr r4, [sp, #0x18]
 *   @0x157334 mov r5, r0
 *   @0x157338 str r1, [r0, #0xc]
 *   @0x15733c mov r0, r4
 *   @0x157340 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157344 mov r1, #1
 *   @0x157348 mov r7, r0
 *   @0x15734c mov r0, r4
 *   @0x157350 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x157354 mov r1, #2
 *   @0x157358 mov r6, r0
 *   @0x15735c mov r0, r4
 *   @0x157360 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x157364 mov r1, r6
 *   @0x157368 mov r2, r0
 *   @0x15736c mov r0, r7
 *   @0x157370 bl 0x15ff70 <_Z15FacebookDialogMPcii>
 *   @0x157374 vmov s15, r0
 *   @0x157378 vcvt.f64.s32 d7, s15
 *   @0x15737c vmov r0, r1, d7
 *   @0x157380 vmov r2, s14
 *   @0x157384 mov r3, r1
 *   @0x157388 stm r5, {r2, r3}
 *   @0x15738c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §210/281 F_YoYo_MoveAdsEx(RValue&, CInstance*, CInstance*, int, RValue*)  0x159304  size 104  26 条（0x159304..0x15936c）
 * @func 0x159304 0x15936c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_YoYo_MoveAdsEx(RValue&, CInstance*, CInstance*, int, RValue*)+0x34
 * 字段偏移 top8: 0x10×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159304 push {r4, r5, r6, lr}
 *   @0x159308 mov r1, #2
 *   @0x15930c ldr r4, [sp, #0x10]
 *   @0x159310 mov r0, r4
 *   @0x159314 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x159318 cmp r0, #4
 *   @0x15931c mov r5, r0
 *   @0x159320 bls 0x159338 <_Z16F_YoYo_MoveAdsExR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x159324 ldr r0, [pc, #0x3c]
 *   @0x159328 mov r1, #0
 *   @0x15932c pop {r4, r5, r6, lr}
 *   @0x159330 add r0, pc, r0
 *   @0x159334 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x159338 mov r0, r4
 *   @0x15933c mov r1, #0
 *   @0x159340 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x159344 mov r1, #1
 *   @0x159348 mov r6, r0
 *   @0x15934c mov r0, r4
 *   @0x159350 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x159354 mov r2, r5
 *   @0x159358 mov r1, r0
 *   @0x15935c mov r0, r6
 *   @0x159360 pop {r4, r5, r6, lr}
 *   @0x159364 b 0x15e340 <_Z6MoveAdiii>
 *   @0x159368 andseq sp, lr, r8, ror #14
 *
 * ══ §211/281 GR_3D_Transform_Set_Identity()  0x16369c  size 104  26 条（0x16369c..0x163704）
 * @func 0x16369c 0x163714  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x38×1 / 0x34×1 / 0x30×1 / 0x2c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16369c str lr, [sp, #-0x4]!
 *   @0x1636a0 sub sp, sp, #68
 *   @0x1636a4 mov r0, #2
 *   @0x1636a8 mov r3, #0
 *   @0x1636ac mov r1, sp
 *   @0x1636b0 mov r2, #1065353216
 *   @0x1636b4 str r3, [sp, #0x38]
 *   @0x1636b8 str r3, [sp, #0x34]
 *   @0x1636bc str r3, [sp, #0x30]
 *   @0x1636c0 str r3, [sp, #0x2c]
 *   @0x1636c4 str r3, [sp, #0x24]
 *   @0x1636c8 str r3, [sp, #0x20]
 *   @0x1636cc str r3, [sp, #0x1c]
 *   @0x1636d0 str r3, [sp, #0x18]
 *   @0x1636d4 str r2, [sp, #0x3c]
 *   @0x1636d8 str r2, [sp, #0x28]
 *   @0x1636dc str r2, [sp, #0x14]
 *   @0x1636e0 str r2, [sp]
 *   @0x1636e4 str r3, [sp, #0x10]
 *   @0x1636e8 str r3, [sp, #0xc]
 *   @0x1636ec str r3, [sp, #0x8]
 *   @0x1636f0 str r3, [sp, #0x4]
 *   @0x1636f4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1636f8 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1636fc add sp, sp, #68
 *   @0x163700 ldr pc, [sp], #4
 *
 * ══ §212/281 GR_3D_Transform_Set_Translation(float, float, float)  0x163704  size 104  26 条（0x163704..0x16376c）
 * @func 0x163704 0x16377c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x30×1 / 0x34×1 / 0x38×1 / 0x2c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163704 str lr, [sp, #-0x4]!
 *   @0x163708 sub sp, sp, #68
 *   @0x16370c mov r3, #0
 *   @0x163710 mov r12, #1065353216
 *   @0x163714 str r0, [sp, #0x30]
 *   @0x163718 mov r0, #2
 *   @0x16371c str r1, [sp, #0x34]
 *   @0x163720 mov r1, sp
 *   @0x163724 str r2, [sp, #0x38]
 *   @0x163728 str r3, [sp, #0x2c]
 *   @0x16372c str r3, [sp, #0x24]
 *   @0x163730 str r3, [sp, #0x20]
 *   @0x163734 str r3, [sp, #0x1c]
 *   @0x163738 str r3, [sp, #0x18]
 *   @0x16373c str r3, [sp, #0x10]
 *   @0x163740 str r3, [sp, #0xc]
 *   @0x163744 str r12, [sp, #0x3c]
 *   @0x163748 str r12, [sp, #0x28]
 *   @0x16374c str r12, [sp, #0x14]
 *   @0x163750 str r12, [sp]
 *   @0x163754 str r3, [sp, #0x8]
 *   @0x163758 str r3, [sp, #0x4]
 *   @0x16375c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163760 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163764 add sp, sp, #68
 *   @0x163768 ldr pc, [sp], #4
 *
 * ══ §213/281 GR_3D_Transform_Set_Scaling(float, float, float)  0x16376c  size 104  26 条（0x16376c..0x1637d4）
 * @func 0x16376c 0x1637d4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x14×1 / 0x28×1 / 0x38×1 / 0x34×1 / 0x30×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16376c str lr, [sp, #-0x4]!
 *   @0x163770 sub sp, sp, #68
 *   @0x163774 mov r3, #0
 *   @0x163778 mov r12, #1065353216
 *   @0x16377c str r0, [sp]
 *   @0x163780 mov r0, #2
 *   @0x163784 str r1, [sp, #0x14]
 *   @0x163788 mov r1, sp
 *   @0x16378c str r2, [sp, #0x28]
 *   @0x163790 str r3, [sp, #0x38]
 *   @0x163794 str r3, [sp, #0x34]
 *   @0x163798 str r3, [sp, #0x30]
 *   @0x16379c str r3, [sp, #0x2c]
 *   @0x1637a0 str r3, [sp, #0x24]
 *   @0x1637a4 str r3, [sp, #0x20]
 *   @0x1637a8 str r3, [sp, #0x1c]
 *   @0x1637ac str r12, [sp, #0x3c]
 *   @0x1637b0 str r3, [sp, #0x18]
 *   @0x1637b4 str r3, [sp, #0x10]
 *   @0x1637b8 str r3, [sp, #0xc]
 *   @0x1637bc str r3, [sp, #0x8]
 *   @0x1637c0 str r3, [sp, #0x4]
 *   @0x1637c4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1637c8 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1637cc add sp, sp, #68
 *   @0x1637d0 ldr pc, [sp], #4
 *
 * ══ §214/281 F_CameraCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x16edfc  size 104  26 条（0x16edfc..0x16ee64）
 * @func 0x16edfc 0x16ee64  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::CreateCamera() / CCamera::GetID()
 * 字段偏移 top8: 0xc×2 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16edfc cmp r3, #0
 *   @0x16ee00 mov r3, #0
 *   @0x16ee04 push {r4, lr}
 *   @0x16ee08 mov r1, r3
 *   @0x16ee0c mov r4, r0
 *   @0x16ee10 movt r3, #0xbff0
 *   @0x16ee14 str r1, [r0, #0xc]
 *   @0x16ee18 stm r0, {r1, r3}
 *   @0x16ee1c bne 0x16ee4c <_Z14F_CameraCreateR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x16ee20 ldr r0, [pc, #0x34]
 *   @0x16ee24 ldr r0, [pc, r0]
 *   @0x16ee28 bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv>
 *   @0x16ee2c bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16ee30 vmov s15, r0
 *   @0x16ee34 vcvt.f64.s32 d7, s15
 *   @0x16ee38 vmov r0, r1, d7
 *   @0x16ee3c vmov r2, s14
 *   @0x16ee40 mov r3, r1
 *   @0x16ee44 stm r4, {r2, r3}
 *   @0x16ee48 pop {r4, pc}
 *   @0x16ee4c ldr r0, [pc, #0xc]
 *   @0x16ee50 pop {r4, lr}
 *   @0x16ee54 add r0, pc, r0
 *   @0x16ee58 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16ee5c eoreq lr, r7, r0, asr lr
 *   @0x16ee60 andseq r11, sp, r0, ror lr
 *
 * ══ §215/281 F_CameraGetDefault(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f4dc  size 104  26 条（0x16f4dc..0x16f544）
 * @func 0x16f4dc 0x16f544  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::GetCamera(int) / CCamera::GetID()
 * 字段偏移 top8: 0x58×1 / 0x48×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f4dc ldr r3, [pc, #0x58]
 *   @0x16f4e0 mov r2, #0
 *   @0x16f4e4 push {r4, lr}
 *   @0x16f4e8 ldr r3, [pc, r3]
 *   @0x16f4ec mov r4, r0
 *   @0x16f4f0 ldr r0, [pc, #0x48]
 *   @0x16f4f4 str r2, [r4]
 *   @0x16f4f8 mov r1, #0
 *   @0x16f4fc ldr r0, [pc, r0]
 *   @0x16f500 movt r1, #0xbff0
 *   @0x16f504 str r2, [r4, #0xc]
 *   @0x16f508 str r1, [r4, #0x4]
 *   @0x16f50c ldr r1, [r3]
 *   @0x16f510 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f514 cmp r0, #0
 *   @0x16f518 popeq {r4, pc}
 *   @0x16f51c bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16f520 vmov s15, r0
 *   @0x16f524 vcvt.f64.s32 d7, s15
 *   @0x16f528 vmov r0, r1, d7
 *   @0x16f52c vmov r2, s14
 *   @0x16f530 mov r3, r1
 *   @0x16f534 stm r4, {r2, r3}
 *   @0x16f538 pop {r4, pc}
 *   @0x16f53c eoreq r0, r8, r4, ror sp
 *   @0x16f540 eoreq lr, r7, r8, ror r7
 *
 * ══ §216/281 GR_Text_Set_Font(int)  0x172ac8  size 104  26 条（0x172ac8..0x172b30）
 * @func 0x172ac8 0x172b30  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x172ae4→0x48ffd8, 0x172af8→0x3f2410, 0x172b0c→0x3f2410
 * 调用序列: Font_Exists(int) / MakeDefaultFont()
 * 字段偏移 top8: 0x48×1 / 0x3c×1 / 0x2c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172ac8 push {r3, r4, r5, lr}
 *   @0x172acc mov r5, r0
 *   @0x172ad0 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x172ad4 ldr r4, [pc, #0x48]
 *   @0x172ad8 add r4, pc, r4
 *   @0x172adc cmp r0, #0
 *   @0x172ae0 bne 0x172b0c <_Z16GR_Text_Set_Fonti+0x44>
 *   @0x172ae4 ldr r3, [pc, #0x3c]
 *   @0x172ae8 ldr r3, [r4, r3]
 *   @0x172aec ldr r3, [r3]
 *   @0x172af0 cmp r3, #0
 *   @0x172af4 beq 0x172b1c <_Z16GR_Text_Set_Fonti+0x54>
 *   @0x172af8 ldr r3, [pc, #0x2c]
 *   @0x172afc mvn r2, #0
 *   @0x172b00 ldr r3, [r4, r3]
 *   @0x172b04 str r2, [r3]
 *   @0x172b08 pop {r3, r4, r5, pc}
 *   @0x172b0c ldr r3, [pc, #0x18]
 *   @0x172b10 ldr r3, [r4, r3]
 *   @0x172b14 str r5, [r3]
 *   @0x172b18 pop {r3, r4, r5, pc}
 *   @0x172b1c bl 0x172468 <_Z15MakeDefaultFontv>
 *   @0x172b20 b 0x172af8 <_Z16GR_Text_Set_Fonti+0x30>
 *   @0x172b24 eoreq pc, r7, r8, ror r1
 *   @0x172b28 .word 0xffffe644
 *   @0x172b2c .word 0xffffe650
 *
 * ══ §217/281 GMGamePad::SetMotorSpeeds(float, float)  0x18eee8  size 104  26 条（0x18eee8..0x18ef50）
 * @func 0x18eee8 0x18ef50  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18eee8 vmov s14, r1
 *   @0x18eeec vmov s15, r2
 *   @0x18eef0 vcmpe.f32 s14, #0
 *   @0x18eef4 vmrs APSR_nzcv, fpscr
 *   @0x18eef8 bmi 0x18ef34 <_ZN9GMGamePad14SetMotorSpeedsEff+0x4c>
 *   @0x18eefc vmov.f32 s13, #1.000000e+00
 *   @0x18ef00 vcmp.f32 s14, s13
 *   @0x18ef04 vmrs APSR_nzcv, fpscr
 *   @0x18ef08 vcmpe.f32 s15, #0
 *   @0x18ef0c vmovgt.f32 s14, s13
 *   @0x18ef10 vmrs APSR_nzcv, fpscr
 *   @0x18ef14 bmi 0x18ef44 <_ZN9GMGamePad14SetMotorSpeedsEff+0x5c>
 *   @0x18ef18 vmov.f32 s13, #1.000000e+00
 *   @0x18ef1c vcmp.f32 s15, s13
 *   @0x18ef20 vmrs APSR_nzcv, fpscr
 *   @0x18ef24 vmovgt.f32 s15, s13
 *   @0x18ef28 vstr s14, [r0, #36]
 *   @0x18ef2c vstr s15, [r0, #40]
 *   @0x18ef30 bx lr
 *   @0x18ef34 vcmpe.f32 s15, #0
 *   @0x18ef38 vldr s14, [pc, #12]
 *   @0x18ef3c vmrs APSR_nzcv, fpscr
 *   @0x18ef40 bpl 0x18ef18 <_ZN9GMGamePad14SetMotorSpeedsEff+0x30>
 *   @0x18ef44 vldr s15, [pc]
 *   @0x18ef48 b 0x18ef28 <_ZN9GMGamePad14SetMotorSpeedsEff+0x40>
 *   @0x18ef4c andeq r0, r0, r0
 *
 * ══ §218/281 YYObjectBase::AddNull(char const*, int)  0x199df4  size 104  26 条（0x199df4..0x199e5c）
 * @func 0x199df4 0x199e5c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199df4 push {r4, r5, r6, lr}
 *   @0x199df8 mov r4, r1
 *   @0x199dfc mov r5, r2
 *   @0x199e00 mov r6, r0
 *   @0x199e04 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x199e08 cmp r0, #0
 *   @0x199e0c popeq {r4, r5, r6, pc}
 *   @0x199e10 mov r1, r4
 *   @0x199e14 mov r0, r6
 *   @0x199e18 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x199e1c ldr r3, [r0, #0xc]
 *   @0x199e20 mov r4, r0
 *   @0x199e24 sub r3, r3, #1
 *   @0x199e28 bic r3, r3, #-16777216
 *   @0x199e2c bic r3, r3, #3
 *   @0x199e30 cmp r3, #0
 *   @0x199e34 beq 0x199e54 <_ZN12YYObjectBase7AddNullEPKci+0x60>
 *   @0x199e38 mov r3, #0
 *   @0x199e3c mov r2, #12
 *   @0x199e40 str r5, [r4, #0x8]
 *   @0x199e44 str r3, [r4]
 *   @0x199e48 str r3, [r4, #0x4]
 *   @0x199e4c str r2, [r4, #0xc]
 *   @0x199e50 pop {r4, r5, r6, pc}
 *   @0x199e54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x199e58 b 0x199e38 <_ZN12YYObjectBase7AddNullEPKci+0x44>
 *
 * ══ §219/281 ParticleSystem_Emitter_Region(int, int, float, float, float, float, int, int)  0x1a394c  size 104  26 条（0x1a394c..0x1a39b4）
 * @func 0x1a394c 0x1a39b4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Emitter_Exists(int, int)
 * 字段偏移 top8: 0x2×2 / 0x3c×1 / 0x4×1 / 0x10×1 / 0x20×1 / 0x8×1 / 0x1c×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a394c push {r3, r4, r5, r6, r7, lr}
 *   @0x1a3950 mov r7, r2
 *   @0x1a3954 mov r6, r3
 *   @0x1a3958 mov r5, r0
 *   @0x1a395c mov r4, r1
 *   @0x1a3960 bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii>
 *   @0x1a3964 cmp r0, #0
 *   @0x1a3968 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a396c ldr r12, [pc, #0x3c]
 *   @0x1a3970 vldr s15, [sp, #24]
 *   @0x1a3974 ldr r12, [pc, r12]
 *   @0x1a3978 ldr r3, [r12, #0x4]
 *   @0x1a397c ldr r3, [r3, r5, lsl #2]
 *   @0x1a3980 ldr r3, [r3, #0x10]
 *   @0x1a3984 ldr r1, [r3, r4, lsl #2]
 *   @0x1a3988 vstr s15, [r1, #16]
 *   @0x1a398c ldr r3, [sp, #0x20]
 *   @0x1a3990 vldr s15, [sp, #28]
 *   @0x1a3994 vstr s15, [r1, #20]
 *   @0x1a3998 str r7, [r1, #0x8]
 *   @0x1a399c str r3, [r1, #0x1c]
 *   @0x1a39a0 ldr r3, [sp, #0x24]
 *   @0x1a39a4 str r6, [r1, #0xc]
 *   @0x1a39a8 str r3, [r1, #0x18]
 *   @0x1a39ac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a39b0 eoreq r12, r4, r4, asr #28
 *
 * ══ §220/281 SV_ViewXport(CInstance*, int, RValue*)  0x1fc3d8  size 104  26 条（0x1fc3d8..0x1fc440）
 * @func 0x1fc3d8 0x1fc450  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc3d8 ldr r3, [pc, #0x5c]
 *   @0x1fc3dc cmp r1, #7
 *   @0x1fc3e0 ldr r0, [r2, #0xc]
 *   @0x1fc3e4 ldr r3, [pc, r3]
 *   @0x1fc3e8 movhi r1, #0
 *   @0x1fc3ec bic r0, r0, #-16777216
 *   @0x1fc3f0 add r1, r1, #18
 *   @0x1fc3f4 ldr r3, [r3]
 *   @0x1fc3f8 cmp r0, #0
 *   @0x1fc3fc push {r4, lr}
 *   @0x1fc400 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc404 bne 0x1fc428 <_Z12SV_ViewXportP9CInstanceiP6RValue+0x50>
 *   @0x1fc408 ldr r12, [r2]
 *   @0x1fc40c ldr r3, [r2, #0x4]
 *   @0x1fc410 mov r0, r12
 *   @0x1fc414 mov r1, r3
 *   @0x1fc418 bl 0xb66e8 <lrint@plt>
 *   @0x1fc41c str r0, [r4, #0x14]
 *   @0x1fc420 mov r0, #1
 *   @0x1fc424 pop {r4, pc}
 *   @0x1fc428 mov r0, r2
 *   @0x1fc42c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc430 mov r12, r0
 *   @0x1fc434 mov r3, r1
 *   @0x1fc438 b 0x1fc410 <_Z12SV_ViewXportP9CInstanceiP6RValue+0x38>
 *   @0x1fc43c andseq r1, pc, r4, asr #10
 *
 * ══ §221/281 SV_ViewYport(CInstance*, int, RValue*)  0x1fc440  size 104  26 条（0x1fc440..0x1fc4a8）
 * @func 0x1fc440 0x1fc4b8  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc440 ldr r3, [pc, #0x5c]
 *   @0x1fc444 cmp r1, #7
 *   @0x1fc448 ldr r0, [r2, #0xc]
 *   @0x1fc44c ldr r3, [pc, r3]
 *   @0x1fc450 movhi r1, #0
 *   @0x1fc454 bic r0, r0, #-16777216
 *   @0x1fc458 add r1, r1, #18
 *   @0x1fc45c ldr r3, [r3]
 *   @0x1fc460 cmp r0, #0
 *   @0x1fc464 push {r4, lr}
 *   @0x1fc468 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc46c bne 0x1fc490 <_Z12SV_ViewYportP9CInstanceiP6RValue+0x50>
 *   @0x1fc470 ldr r12, [r2]
 *   @0x1fc474 ldr r3, [r2, #0x4]
 *   @0x1fc478 mov r0, r12
 *   @0x1fc47c mov r1, r3
 *   @0x1fc480 bl 0xb66e8 <lrint@plt>
 *   @0x1fc484 str r0, [r4, #0x18]
 *   @0x1fc488 mov r0, #1
 *   @0x1fc48c pop {r4, pc}
 *   @0x1fc490 mov r0, r2
 *   @0x1fc494 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc498 mov r12, r0
 *   @0x1fc49c mov r3, r1
 *   @0x1fc4a0 b 0x1fc478 <_Z12SV_ViewYportP9CInstanceiP6RValue+0x38>
 *   @0x1fc4a4 ldrsbeq r1, [pc], -r12
 *
 * ══ §222/281 SV_ViewWport(CInstance*, int, RValue*)  0x1fc4a8  size 104  26 条（0x1fc4a8..0x1fc510）
 * @func 0x1fc4a8 0x1fc520  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc4a8 ldr r3, [pc, #0x5c]
 *   @0x1fc4ac cmp r1, #7
 *   @0x1fc4b0 ldr r0, [r2, #0xc]
 *   @0x1fc4b4 ldr r3, [pc, r3]
 *   @0x1fc4b8 movhi r1, #0
 *   @0x1fc4bc bic r0, r0, #-16777216
 *   @0x1fc4c0 add r1, r1, #18
 *   @0x1fc4c4 ldr r3, [r3]
 *   @0x1fc4c8 cmp r0, #0
 *   @0x1fc4cc push {r4, lr}
 *   @0x1fc4d0 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc4d4 bne 0x1fc4f8 <_Z12SV_ViewWportP9CInstanceiP6RValue+0x50>
 *   @0x1fc4d8 ldr r12, [r2]
 *   @0x1fc4dc ldr r3, [r2, #0x4]
 *   @0x1fc4e0 mov r0, r12
 *   @0x1fc4e4 mov r1, r3
 *   @0x1fc4e8 bl 0xb66e8 <lrint@plt>
 *   @0x1fc4ec str r0, [r4, #0x1c]
 *   @0x1fc4f0 mov r0, #1
 *   @0x1fc4f4 pop {r4, pc}
 *   @0x1fc4f8 mov r0, r2
 *   @0x1fc4fc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc500 mov r12, r0
 *   @0x1fc504 mov r3, r1
 *   @0x1fc508 b 0x1fc4e0 <_Z12SV_ViewWportP9CInstanceiP6RValue+0x38>
 *   @0x1fc50c andseq r1, pc, r4, ror r4
 *
 * ══ §223/281 SV_ViewHport(CInstance*, int, RValue*)  0x1fc510  size 104  26 条（0x1fc510..0x1fc578）
 * @func 0x1fc510 0x1fc578  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc510 ldr r3, [pc, #0x5c]
 *   @0x1fc514 cmp r1, #7
 *   @0x1fc518 ldr r0, [r2, #0xc]
 *   @0x1fc51c ldr r3, [pc, r3]
 *   @0x1fc520 movhi r1, #0
 *   @0x1fc524 bic r0, r0, #-16777216
 *   @0x1fc528 add r1, r1, #18
 *   @0x1fc52c ldr r3, [r3]
 *   @0x1fc530 cmp r0, #0
 *   @0x1fc534 push {r4, lr}
 *   @0x1fc538 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc53c bne 0x1fc560 <_Z12SV_ViewHportP9CInstanceiP6RValue+0x50>
 *   @0x1fc540 ldr r12, [r2]
 *   @0x1fc544 ldr r3, [r2, #0x4]
 *   @0x1fc548 mov r0, r12
 *   @0x1fc54c mov r1, r3
 *   @0x1fc550 bl 0xb66e8 <lrint@plt>
 *   @0x1fc554 str r0, [r4, #0x20]
 *   @0x1fc558 mov r0, #1
 *   @0x1fc55c pop {r4, pc}
 *   @0x1fc560 mov r0, r2
 *   @0x1fc564 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc568 mov r12, r0
 *   @0x1fc56c mov r3, r1
 *   @0x1fc570 b 0x1fc548 <_Z12SV_ViewHportP9CInstanceiP6RValue+0x38>
 *   @0x1fc574 andseq r1, pc, r12, lsl #8
 *
 * ══ §224/281 SV_ViewHBorder(CInstance*, int, RValue*)  0x1fc5d0  size 104  26 条（0x1fc5d0..0x1fc638）
 * @func 0x1fc5d0 0x1fc648  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc5d0 ldr r3, [pc, #0x5c]
 *   @0x1fc5d4 cmp r1, #7
 *   @0x1fc5d8 ldr r0, [r2, #0xc]
 *   @0x1fc5dc ldr r3, [pc, r3]
 *   @0x1fc5e0 movhi r1, #0
 *   @0x1fc5e4 bic r0, r0, #-16777216
 *   @0x1fc5e8 add r1, r1, #18
 *   @0x1fc5ec ldr r3, [r3]
 *   @0x1fc5f0 cmp r0, #0
 *   @0x1fc5f4 push {r4, lr}
 *   @0x1fc5f8 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc5fc bne 0x1fc620 <_Z14SV_ViewHBorderP9CInstanceiP6RValue+0x50>
 *   @0x1fc600 ldr r12, [r2]
 *   @0x1fc604 ldr r3, [r2, #0x4]
 *   @0x1fc608 mov r0, r12
 *   @0x1fc60c mov r1, r3
 *   @0x1fc610 bl 0xb66e8 <lrint@plt>
 *   @0x1fc614 str r0, [r4, #0x28]
 *   @0x1fc618 mov r0, #1
 *   @0x1fc61c pop {r4, pc}
 *   @0x1fc620 mov r0, r2
 *   @0x1fc624 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc628 mov r12, r0
 *   @0x1fc62c mov r3, r1
 *   @0x1fc630 b 0x1fc608 <_Z14SV_ViewHBorderP9CInstanceiP6RValue+0x38>
 *   @0x1fc634 andseq r1, pc, r12, asr #6
 *
 * ══ §225/281 SV_ViewVBorder(CInstance*, int, RValue*)  0x1fc638  size 104  26 条（0x1fc638..0x1fc6a0）
 * @func 0x1fc638 0x1fc6b0  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc638 ldr r3, [pc, #0x5c]
 *   @0x1fc63c cmp r1, #7
 *   @0x1fc640 ldr r0, [r2, #0xc]
 *   @0x1fc644 ldr r3, [pc, r3]
 *   @0x1fc648 movhi r1, #0
 *   @0x1fc64c bic r0, r0, #-16777216
 *   @0x1fc650 add r1, r1, #18
 *   @0x1fc654 ldr r3, [r3]
 *   @0x1fc658 cmp r0, #0
 *   @0x1fc65c push {r4, lr}
 *   @0x1fc660 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc664 bne 0x1fc688 <_Z14SV_ViewVBorderP9CInstanceiP6RValue+0x50>
 *   @0x1fc668 ldr r12, [r2]
 *   @0x1fc66c ldr r3, [r2, #0x4]
 *   @0x1fc670 mov r0, r12
 *   @0x1fc674 mov r1, r3
 *   @0x1fc678 bl 0xb66e8 <lrint@plt>
 *   @0x1fc67c str r0, [r4, #0x2c]
 *   @0x1fc680 mov r0, #1
 *   @0x1fc684 pop {r4, pc}
 *   @0x1fc688 mov r0, r2
 *   @0x1fc68c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc690 mov r12, r0
 *   @0x1fc694 mov r3, r1
 *   @0x1fc698 b 0x1fc670 <_Z14SV_ViewVBorderP9CInstanceiP6RValue+0x38>
 *   @0x1fc69c andseq r1, pc, r4, ror #5
 *
 * ══ §226/281 SV_ViewHSpeed(CInstance*, int, RValue*)  0x1fc6a0  size 104  26 条（0x1fc6a0..0x1fc708）
 * @func 0x1fc6a0 0x1fc718  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc6a0 ldr r3, [pc, #0x5c]
 *   @0x1fc6a4 cmp r1, #7
 *   @0x1fc6a8 ldr r0, [r2, #0xc]
 *   @0x1fc6ac ldr r3, [pc, r3]
 *   @0x1fc6b0 movhi r1, #0
 *   @0x1fc6b4 bic r0, r0, #-16777216
 *   @0x1fc6b8 add r1, r1, #18
 *   @0x1fc6bc ldr r3, [r3]
 *   @0x1fc6c0 cmp r0, #0
 *   @0x1fc6c4 push {r4, lr}
 *   @0x1fc6c8 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc6cc bne 0x1fc6f0 <_Z13SV_ViewHSpeedP9CInstanceiP6RValue+0x50>
 *   @0x1fc6d0 ldr r12, [r2]
 *   @0x1fc6d4 ldr r3, [r2, #0x4]
 *   @0x1fc6d8 mov r0, r12
 *   @0x1fc6dc mov r1, r3
 *   @0x1fc6e0 bl 0xb66e8 <lrint@plt>
 *   @0x1fc6e4 str r0, [r4, #0x30]
 *   @0x1fc6e8 mov r0, #1
 *   @0x1fc6ec pop {r4, pc}
 *   @0x1fc6f0 mov r0, r2
 *   @0x1fc6f4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc6f8 mov r12, r0
 *   @0x1fc6fc mov r3, r1
 *   @0x1fc700 b 0x1fc6d8 <_Z13SV_ViewHSpeedP9CInstanceiP6RValue+0x38>
 *   @0x1fc704 andseq r1, pc, r12, ror r2
 *
 * ══ §227/281 SV_ViewVSpeed(CInstance*, int, RValue*)  0x1fc708  size 104  26 条（0x1fc708..0x1fc770）
 * @func 0x1fc708 0x1fc780  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc708 ldr r3, [pc, #0x5c]
 *   @0x1fc70c cmp r1, #7
 *   @0x1fc710 ldr r0, [r2, #0xc]
 *   @0x1fc714 ldr r3, [pc, r3]
 *   @0x1fc718 movhi r1, #0
 *   @0x1fc71c bic r0, r0, #-16777216
 *   @0x1fc720 add r1, r1, #18
 *   @0x1fc724 ldr r3, [r3]
 *   @0x1fc728 cmp r0, #0
 *   @0x1fc72c push {r4, lr}
 *   @0x1fc730 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc734 bne 0x1fc758 <_Z13SV_ViewVSpeedP9CInstanceiP6RValue+0x50>
 *   @0x1fc738 ldr r12, [r2]
 *   @0x1fc73c ldr r3, [r2, #0x4]
 *   @0x1fc740 mov r0, r12
 *   @0x1fc744 mov r1, r3
 *   @0x1fc748 bl 0xb66e8 <lrint@plt>
 *   @0x1fc74c str r0, [r4, #0x34]
 *   @0x1fc750 mov r0, #1
 *   @0x1fc754 pop {r4, pc}
 *   @0x1fc758 mov r0, r2
 *   @0x1fc75c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc760 mov r12, r0
 *   @0x1fc764 mov r3, r1
 *   @0x1fc768 b 0x1fc740 <_Z13SV_ViewVSpeedP9CInstanceiP6RValue+0x38>
 *   @0x1fc76c andseq r1, pc, r4, lsl r2
 *
 * ══ §228/281 SV_ViewObject(CInstance*, int, RValue*)  0x1fc770  size 104  26 条（0x1fc770..0x1fc7d8）
 * @func 0x1fc770 0x1fc7e8  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc770 ldr r3, [pc, #0x5c]
 *   @0x1fc774 cmp r1, #7
 *   @0x1fc778 ldr r0, [r2, #0xc]
 *   @0x1fc77c ldr r3, [pc, r3]
 *   @0x1fc780 movhi r1, #0
 *   @0x1fc784 bic r0, r0, #-16777216
 *   @0x1fc788 add r1, r1, #18
 *   @0x1fc78c ldr r3, [r3]
 *   @0x1fc790 cmp r0, #0
 *   @0x1fc794 push {r4, lr}
 *   @0x1fc798 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc79c bne 0x1fc7c0 <_Z13SV_ViewObjectP9CInstanceiP6RValue+0x50>
 *   @0x1fc7a0 ldr r12, [r2]
 *   @0x1fc7a4 ldr r3, [r2, #0x4]
 *   @0x1fc7a8 mov r0, r12
 *   @0x1fc7ac mov r1, r3
 *   @0x1fc7b0 bl 0xb66e8 <lrint@plt>
 *   @0x1fc7b4 str r0, [r4, #0x38]
 *   @0x1fc7b8 mov r0, #1
 *   @0x1fc7bc pop {r4, pc}
 *   @0x1fc7c0 mov r0, r2
 *   @0x1fc7c4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc7c8 mov r12, r0
 *   @0x1fc7cc mov r3, r1
 *   @0x1fc7d0 b 0x1fc7a8 <_Z13SV_ViewObjectP9CInstanceiP6RValue+0x38>
 *   @0x1fc7d4 andseq r1, pc, r12, lsr #3
 *
 * ══ §229/281 SV_ViewSurfaceID(CInstance*, int, RValue*)  0x1fc7d8  size 104  26 条（0x1fc7d8..0x1fc840）
 * @func 0x1fc7d8 0x1fc850  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc7d8 ldr r3, [pc, #0x5c]
 *   @0x1fc7dc cmp r1, #7
 *   @0x1fc7e0 ldr r0, [r2, #0xc]
 *   @0x1fc7e4 ldr r3, [pc, r3]
 *   @0x1fc7e8 movhi r1, #0
 *   @0x1fc7ec bic r0, r0, #-16777216
 *   @0x1fc7f0 add r1, r1, #18
 *   @0x1fc7f4 ldr r3, [r3]
 *   @0x1fc7f8 cmp r0, #0
 *   @0x1fc7fc push {r4, lr}
 *   @0x1fc800 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc804 bne 0x1fc828 <_Z16SV_ViewSurfaceIDP9CInstanceiP6RValue+0x50>
 *   @0x1fc808 ldr r12, [r2]
 *   @0x1fc80c ldr r3, [r2, #0x4]
 *   @0x1fc810 mov r0, r12
 *   @0x1fc814 mov r1, r3
 *   @0x1fc818 bl 0xb66e8 <lrint@plt>
 *   @0x1fc81c str r0, [r4, #0x3c]
 *   @0x1fc820 mov r0, #1
 *   @0x1fc824 pop {r4, pc}
 *   @0x1fc828 mov r0, r2
 *   @0x1fc82c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc830 mov r12, r0
 *   @0x1fc834 mov r3, r1
 *   @0x1fc838 b 0x1fc810 <_Z16SV_ViewSurfaceIDP9CInstanceiP6RValue+0x38>
 *   @0x1fc83c andseq r1, pc, r4, asr #2
 *
 * ══ §230/281 SV_ViewCamera(CInstance*, int, RValue*)  0x1fc840  size 104  26 条（0x1fc840..0x1fc8a8）
 * @func 0x1fc840 0x1fc8a8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x5c×1 / 0xc×1 / 0x2×1 / 0x4×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc840 ldr r3, [pc, #0x5c]
 *   @0x1fc844 cmp r1, #7
 *   @0x1fc848 ldr r0, [r2, #0xc]
 *   @0x1fc84c ldr r3, [pc, r3]
 *   @0x1fc850 movhi r1, #0
 *   @0x1fc854 bic r0, r0, #-16777216
 *   @0x1fc858 add r1, r1, #18
 *   @0x1fc85c ldr r3, [r3]
 *   @0x1fc860 cmp r0, #0
 *   @0x1fc864 push {r4, lr}
 *   @0x1fc868 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc86c bne 0x1fc890 <_Z13SV_ViewCameraP9CInstanceiP6RValue+0x50>
 *   @0x1fc870 ldr r12, [r2]
 *   @0x1fc874 ldr r3, [r2, #0x4]
 *   @0x1fc878 mov r0, r12
 *   @0x1fc87c mov r1, r3
 *   @0x1fc880 bl 0xb66e8 <lrint@plt>
 *   @0x1fc884 str r0, [r4, #0x40]
 *   @0x1fc888 mov r0, #1
 *   @0x1fc88c pop {r4, pc}
 *   @0x1fc890 mov r0, r2
 *   @0x1fc894 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc898 mov r12, r0
 *   @0x1fc89c mov r3, r1
 *   @0x1fc8a0 b 0x1fc878 <_Z13SV_ViewCameraP9CInstanceiP6RValue+0x38>
 *   @0x1fc8a4 ldrsbeq r1, [pc], -r12
 *
 * ══ §231/281 SV_BackgroundIndex(CInstance*, int, RValue*)  0x1fc9b0  size 104  26 条（0x1fc9b0..0x1fca18）
 * @func 0x1fc9b0 0x1fca18  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4×2 / 0x5c×1 / 0xc×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc9b0 ldr r3, [pc, #0x5c]
 *   @0x1fc9b4 cmp r1, #7
 *   @0x1fc9b8 ldr r0, [r2, #0xc]
 *   @0x1fc9bc ldr r3, [pc, r3]
 *   @0x1fc9c0 movhi r1, #0
 *   @0x1fc9c4 bic r0, r0, #-16777216
 *   @0x1fc9c8 ldr r3, [r3]
 *   @0x1fc9cc cmp r0, #0
 *   @0x1fc9d0 push {r4, lr}
 *   @0x1fc9d4 add r1, r3, r1, lsl #2
 *   @0x1fc9d8 ldr r4, [r1, #0x24]
 *   @0x1fc9dc bne 0x1fca00 <_Z18SV_BackgroundIndexP9CInstanceiP6RValue+0x50>
 *   @0x1fc9e0 ldr r12, [r2]
 *   @0x1fc9e4 ldr r3, [r2, #0x4]
 *   @0x1fc9e8 mov r0, r12
 *   @0x1fc9ec mov r1, r3
 *   @0x1fc9f0 bl 0xb66e8 <lrint@plt>
 *   @0x1fc9f4 str r0, [r4, #0x4]
 *   @0x1fc9f8 mov r0, #1
 *   @0x1fc9fc pop {r4, pc}
 *   @0x1fca00 mov r0, r2
 *   @0x1fca04 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fca08 mov r12, r0
 *   @0x1fca0c mov r3, r1
 *   @0x1fca10 b 0x1fc9e8 <_Z18SV_BackgroundIndexP9CInstanceiP6RValue+0x38>
 *   @0x1fca14 andseq r0, pc, r12, ror #30
 *
 * ══ §232/281 CStream::ReadString(char const*&)  0x2018e8  size 104  26 条（0x2018e8..0x201950）
 * @func 0x2018e8 0x201950  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadBuffer(void*, int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×2 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2018e8 push {r4, r5, r6, lr}
 *   @0x2018ec sub sp, sp, #8
 *   @0x2018f0 mov r4, r1
 *   @0x2018f4 mov r2, #4
 *   @0x2018f8 add r1, sp, r2
 *   @0x2018fc mov r5, r0
 *   @0x201900 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x201904 ldr r0, [sp, #0x4]
 *   @0x201908 cmp r0, #0
 *   @0x20190c streq r0, [r4]
 *   @0x201910 beq 0x201944 <_ZN7CStream10ReadStringERPKc+0x5c>
 *   @0x201914 ldr r1, [pc, #0x30]
 *   @0x201918 movw r2, #0x21e
 *   @0x20191c mov r3, #1
 *   @0x201920 add r0, r0, #1
 *   @0x201924 add r1, pc, r1
 *   @0x201928 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20192c ldr r2, [sp, #0x4]
 *   @0x201930 mov r6, r0
 *   @0x201934 mov r0, r5
 *   @0x201938 mov r1, r6
 *   @0x20193c bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x201940 str r6, [r4]
 *   @0x201944 add sp, sp, #8
 *   @0x201948 pop {r4, r5, r6, pc}
 *   @0x20194c andseq r1, r5, r4, lsl #28
 *
 * ══ §233/281 CDS_List::Find(RValue*)  0x20318c  size 104  26 条（0x20318c..0x2031f4）
 * @func 0x20318c 0x2031f4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_List::Find(RValue*)+0x5c×2 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x4×2 / 0x44×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20318c push {r3, r4, r5, r6, r7, lr}
 *   @0x203190 mov r5, r0
 *   @0x203194 ldr r3, [r0, #0x4]
 *   @0x203198 mov r7, r1
 *   @0x20319c cmp r3, #0
 *   @0x2031a0 ble 0x2031e8 <_ZN8CDS_List4FindEP6RValue+0x5c>
 *   @0x2031a4 ldr r6, [pc, #0x44]
 *   @0x2031a8 mov r4, #0
 *   @0x2031ac ldr r6, [pc, r6]
 *   @0x2031b0 b 0x2031c4 <_ZN8CDS_List4FindEP6RValue+0x38>
 *   @0x2031b4 ldr r3, [r5, #0x4]
 *   @0x2031b8 add r4, r4, #1
 *   @0x2031bc cmp r3, r4
 *   @0x2031c0 ble 0x2031e8 <_ZN8CDS_List4FindEP6RValue+0x5c>
 *   @0x2031c4 ldr r0, [r5, #0xc]
 *   @0x2031c8 mov r1, r7
 *   @0x2031cc ldrd r2, r3, [r6]
 *   @0x2031d0 add r0, r0, r4, lsl #4
 *   @0x2031d4 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x2031d8 cmp r0, #0
 *   @0x2031dc bne 0x2031b4 <_ZN8CDS_List4FindEP6RValue+0x28>
 *   @0x2031e0 mov r0, r4
 *   @0x2031e4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2031e8 mvn r0, #0
 *   @0x2031ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x2031f0 ldrsbeq lr, [lr], -r8
 *
 * ══ §234/281 CEmitter::RemoveNoiseFromEmitter(CNoise*)  0x2158dc  size 104  26 条（0x2158dc..0x215944）
 * @func 0x2158dc 0x215944  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CEmitter::RemoveNoiseFromEmitter(CNoise*)+0x4c
 * 字段偏移 top8: 0x38×2 / 0x4×2 / 0x-4×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2158dc str r4, [sp, #-0x4]!
 *   @0x2158e0 ldr r4, [r0, #0x34]
 *   @0x2158e4 cmp r4, #0
 *   @0x2158e8 ble 0x215928 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x4c>
 *   @0x2158ec ldr r0, [r0, #0x38]
 *   @0x2158f0 ldr r3, [r0]
 *   @0x2158f4 cmp r1, r3
 *   @0x2158f8 addne r2, r0, #4
 *   @0x2158fc movne r3, #0
 *   @0x215900 bne 0x215914 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x38>
 *   @0x215904 b 0x215930 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x54>
 *   @0x215908 ldr r12, [r0]
 *   @0x21590c cmp r1, r12
 *   @0x215910 beq 0x215930 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x54>
 *   @0x215914 add r3, r3, #1
 *   @0x215918 mov r0, r2
 *   @0x21591c cmp r3, r4
 *   @0x215920 add r2, r2, #4
 *   @0x215924 bne 0x215908 <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise+0x2c>
 *   @0x215928 ldr r4, [sp], #4
 *   @0x21592c bx lr
 *   @0x215930 mov r3, #0
 *   @0x215934 ldr r4, [sp], #4
 *   @0x215938 str r3, [r1, #0x38]
 *   @0x21593c str r3, [r0]
 *   @0x215940 bx lr
 *
 * ══ §235/281 Audio_GetEmitterGain(int)  0x2180ac  size 104  26 条（0x2180ac..0x218114）
 * @func 0x2180ac 0x218114  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetEmitterGain(int)+0x54
 * 字段偏移 top8: 0x44×2 / 0x54×1 / 0x2c×1 / 0x40×1 / 0x2×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2180ac ldr r3, [pc, #0x54]
 *   @0x2180b0 ldr r3, [pc, r3]
 *   @0x2180b4 ldrb r3, [r3]
 *   @0x2180b8 cmp r3, #0
 *   @0x2180bc bne 0x218100 <_Z20Audio_GetEmitterGaini+0x54>
 *   @0x2180c0 ldr r3, [pc, #0x44]
 *   @0x2180c4 ldr r3, [pc, r3]
 *   @0x2180c8 ldrb r3, [r3]
 *   @0x2180cc cmp r3, #0
 *   @0x2180d0 beq 0x218100 <_Z20Audio_GetEmitterGaini+0x54>
 *   @0x2180d4 cmp r0, #0
 *   @0x2180d8 blt 0x218100 <_Z20Audio_GetEmitterGaini+0x54>
 *   @0x2180dc ldr r3, [pc, #0x2c]
 *   @0x2180e0 add r3, pc, r3
 *   @0x2180e4 ldr r2, [r3, #0x40]
 *   @0x2180e8 cmp r0, r2
 *   @0x2180ec bge 0x218100 <_Z20Audio_GetEmitterGaini+0x54>
 *   @0x2180f0 ldr r3, [r3, #0x44]
 *   @0x2180f4 ldr r3, [r3, r0, lsl #2]
 *   @0x2180f8 ldr r0, [r3, #0x28]
 *   @0x2180fc bx lr
 *   @0x218100 mov r0, #0
 *   @0x218104 bx lr
 *   @0x218108 mulseq sp, r12, pc
 *   @0x21810c andseq r6, sp, r12, ror #24
 *   @0x218110 ldrheq sp, [r3], #-20
 *
 * ══ §236/281 Audio_GetEmitterPitch(int)  0x2182e0  size 104  26 条（0x2182e0..0x218348）
 * @func 0x2182e0 0x218348  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetEmitterPitch(int)+0x54
 * 字段偏移 top8: 0x44×2 / 0x2c×2 / 0x54×1 / 0x40×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2182e0 ldr r3, [pc, #0x54]
 *   @0x2182e4 ldr r3, [pc, r3]
 *   @0x2182e8 ldrb r3, [r3]
 *   @0x2182ec cmp r3, #0
 *   @0x2182f0 bne 0x218334 <_Z21Audio_GetEmitterPitchi+0x54>
 *   @0x2182f4 ldr r3, [pc, #0x44]
 *   @0x2182f8 ldr r3, [pc, r3]
 *   @0x2182fc ldrb r3, [r3]
 *   @0x218300 cmp r3, #0
 *   @0x218304 beq 0x218334 <_Z21Audio_GetEmitterPitchi+0x54>
 *   @0x218308 cmp r0, #0
 *   @0x21830c blt 0x218334 <_Z21Audio_GetEmitterPitchi+0x54>
 *   @0x218310 ldr r3, [pc, #0x2c]
 *   @0x218314 add r3, pc, r3
 *   @0x218318 ldr r2, [r3, #0x40]
 *   @0x21831c cmp r0, r2
 *   @0x218320 bge 0x218334 <_Z21Audio_GetEmitterPitchi+0x54>
 *   @0x218324 ldr r3, [r3, #0x44]
 *   @0x218328 ldr r3, [r3, r0, lsl #2]
 *   @0x21832c ldr r0, [r3, #0x2c]
 *   @0x218330 bx lr
 *   @0x218334 mov r0, #1065353216
 *   @0x218338 bx lr
 *   @0x21833c andseq r6, sp, r8, ror #26
 *   @0x218340 andseq r6, sp, r8, lsr r10
 *   @0x218344 subseq r12, r3, r0, lsl #31
 *
 * ══ §237/281 Audio_SoundGetListenerMask(int)  0x2183dc  size 104  26 条（0x2183dc..0x218444）
 * @func 0x2183dc 0x218444  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_SoundGetListenerMask(int)+0x48 / Audio_GetNoiseFromID(int)
 * 字段偏移 top8: 0x50×1 / 0x40×1 / 0x30×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2183dc push {r3, lr}
 *   @0x2183e0 ldr r3, [pc, #0x50]
 *   @0x2183e4 ldr r3, [pc, r3]
 *   @0x2183e8 ldrb r3, [r3]
 *   @0x2183ec cmp r3, #0
 *   @0x2183f0 bne 0x21841c <_Z26Audio_SoundGetListenerMaski+0x40>
 *   @0x2183f4 ldr r3, [pc, #0x40]
 *   @0x2183f8 ldr r3, [pc, r3]
 *   @0x2183fc ldrb r3, [r3]
 *   @0x218400 cmp r3, #0
 *   @0x218404 beq 0x21841c <_Z26Audio_SoundGetListenerMaski+0x40>
 *   @0x218408 ldr r3, [pc, #0x30]
 *   @0x21840c ldr r3, [pc, r3]
 *   @0x218410 ldr r3, [r3]
 *   @0x218414 cmp r3, r0
 *   @0x218418 ble 0x218424 <_Z26Audio_SoundGetListenerMaski+0x48>
 *   @0x21841c mov r0, #1
 *   @0x218420 pop {r3, pc}
 *   @0x218424 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x218428 cmp r0, #0
 *   @0x21842c beq 0x21841c <_Z26Audio_SoundGetListenerMaski+0x40>
 *   @0x218430 ldr r0, [r0, #0x34]
 *   @0x218434 pop {r3, pc}
 *   @0x218438 andseq r6, sp, r8, ror #24
 *   @0x21843c andseq r6, sp, r8, lsr r9
 *   @0x218440 ldrsbeq r8, [sp], -r8
 *
 * ══ §238/281 Audio_EmitterGetListenerMask(int)  0x2184b8  size 104  26 条（0x2184b8..0x218520）
 * @func 0x2184b8 0x218520  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_EmitterGetListenerMask(int)+0x54
 * 字段偏移 top8: 0x44×2 / 0x54×1 / 0x2c×1 / 0x40×1 / 0x2×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2184b8 ldr r3, [pc, #0x54]
 *   @0x2184bc ldr r3, [pc, r3]
 *   @0x2184c0 ldrb r3, [r3]
 *   @0x2184c4 cmp r3, #0
 *   @0x2184c8 bne 0x21850c <_Z28Audio_EmitterGetListenerMaski+0x54>
 *   @0x2184cc ldr r3, [pc, #0x44]
 *   @0x2184d0 ldr r3, [pc, r3]
 *   @0x2184d4 ldrb r3, [r3]
 *   @0x2184d8 cmp r3, #0
 *   @0x2184dc beq 0x21850c <_Z28Audio_EmitterGetListenerMaski+0x54>
 *   @0x2184e0 cmp r0, #0
 *   @0x2184e4 blt 0x21850c <_Z28Audio_EmitterGetListenerMaski+0x54>
 *   @0x2184e8 ldr r3, [pc, #0x2c]
 *   @0x2184ec add r3, pc, r3
 *   @0x2184f0 ldr r2, [r3, #0x40]
 *   @0x2184f4 cmp r0, r2
 *   @0x2184f8 bge 0x21850c <_Z28Audio_EmitterGetListenerMaski+0x54>
 *   @0x2184fc ldr r3, [r3, #0x44]
 *   @0x218500 ldr r3, [r3, r0, lsl #2]
 *   @0x218504 ldr r0, [r3, #0x30]
 *   @0x218508 bx lr
 *   @0x21850c mov r0, #1
 *   @0x218510 bx lr
 *   @0x218514 mulseq sp, r0, r11
 *   @0x218518 andseq r6, sp, r0, ror #16
 *   @0x21851c subseq r12, r3, r8, lsr #27
 *
 * ══ §239/281 Audio_Find(char const*)  0x219794  size 104  26 条（0x219794..0x2197fc）
 * @func 0x219794 0x2197fc  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_Find(char const*)+0x5c / 0xb6574
 * 字段偏移 top8: 0x5c×1 / 0x48×1 / 0x4c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x219794 ldr r3, [pc, #0x5c]
 *   @0x219798 push {r4, r5, r6, r7, r8, lr}
 *   @0x21979c add r3, pc, r3
 *   @0x2197a0 mov r8, r0
 *   @0x2197a4 ldr r7, [r3, #0x48]
 *   @0x2197a8 cmp r7, #0
 *   @0x2197ac ble 0x2197f0 <_Z10Audio_FindPKc+0x5c>
 *   @0x2197b0 ldr r5, [r3, #0x4c]
 *   @0x2197b4 mov r4, #0
 *   @0x2197b8 mvn r6, #0
 *   @0x2197bc sub r5, r5, #4
 *   @0x2197c0 ldr r0, [r5, #0x4]!
 *   @0x2197c4 mov r1, r8
 *   @0x2197c8 cmp r0, #0
 *   @0x2197cc beq 0x2197dc <_Z10Audio_FindPKc+0x48>
 *   @0x2197d0 bl 0xb6574 <strcmp@plt>
 *   @0x2197d4 cmp r0, #0
 *   @0x2197d8 moveq r6, r4
 *   @0x2197dc add r4, r4, #1
 *   @0x2197e0 cmp r4, r7
 *   @0x2197e4 bne 0x2197c0 <_Z10Audio_FindPKc+0x2c>
 *   @0x2197e8 mov r0, r6
 *   @0x2197ec pop {r4, r5, r6, r7, r8, pc}
 *   @0x2197f0 mvn r6, #0
 *   @0x2197f4 b 0x2197e8 <_Z10Audio_FindPKc+0x54>
 *   @0x2197f8 ldrsheq r11, [r3], #-168
 *
 * ══ §240/281 Audio_SetNoiseInactive(CNoise*)  0x21a048  size 104  26 条（0x21a048..0x21a0b0）
 * @func 0x21a048 0x21a0b0  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CEmitter::RemoveNoiseFromEmitter(CNoise*) / Audio_Unqueue_Processed_Buffers(CNoise*, int, bool)
 * 字段偏移 top8: 0x38×2 / 0x5×1 / 0x8×1 / 0xd×1 / 0x18×1 / 0x1c×1 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21a048 push {r3, r4, r5, lr}
 *   @0x21a04c mov r4, r0
 *   @0x21a050 ldr r0, [r0, #0x38]
 *   @0x21a054 mov r5, #0
 *   @0x21a058 strb r5, [r4, #0x5]
 *   @0x21a05c cmp r0, r5
 *   @0x21a060 str r5, [r4, #0x8]
 *   @0x21a064 strb r5, [r4, #0xd]
 *   @0x21a068 beq 0x21a078 <_Z22Audio_SetNoiseInactiveP6CNoise+0x30>
 *   @0x21a06c mov r1, r4
 *   @0x21a070 bl 0x2158dc <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise>
 *   @0x21a074 str r5, [r4, #0x38]
 *   @0x21a078 mov r0, r4
 *   @0x21a07c ldr r1, [r4, #0x18]
 *   @0x21a080 mov r2, #1
 *   @0x21a084 bl 0x219e68 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib>
 *   @0x21a088 ldr r3, [pc, #0x1c]
 *   @0x21a08c ldr r0, [r4, #0x10]
 *   @0x21a090 movw r1, #0x1009
 *   @0x21a094 ldr r3, [pc, r3]
 *   @0x21a098 mov r2, #0
 *   @0x21a09c ldr r3, [r3]
 *   @0x21a0a0 ldr r0, [r3, r0, lsl #2]
 *   @0x21a0a4 pop {r3, r4, r5, lr}
 *   @0x21a0a8 b 0xb6a6c <alSourcei@plt>
 *   @0x21a0ac andseq r7, sp, r8, lsr r3
 *
 * ══ §241/281 SND_AddFromMemory(void*, int)  0x21e9f8  size 104  26 条（0x21e9f8..0x21ea60）
 * @func 0x21e9f8 0x21ea60  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SND_AddEmpty(int) / SoundHardware::Load(void*, int, int)
 * 字段偏移 top8: 0x4×2 / 0x48×1 / 0x24×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e9f8 push {r4, r5, r6, lr}
 *   @0x21e9fc mov r6, r0
 *   @0x21ea00 mov r0, r1
 *   @0x21ea04 bl 0x21e7f4 <_Z12SND_AddEmptyi>
 *   @0x21ea08 ldr r3, [pc, #0x48]
 *   @0x21ea0c ldr r3, [pc, r3]
 *   @0x21ea10 ldr r3, [r3, #0x4]
 *   @0x21ea14 add r5, r0, r0, lsl #2
 *   @0x21ea18 mov r4, r0
 *   @0x21ea1c add r5, r3, r5, lsl #2
 *   @0x21ea20 ldr r3, [r5, #0x4]
 *   @0x21ea24 bic r3, r3, #2
 *   @0x21ea28 cmp r3, #1
 *   @0x21ea2c beq 0x21ea50 <_Z17SND_AddFromMemoryPvi+0x58>
 *   @0x21ea30 ldr r0, [pc, #0x24]
 *   @0x21ea34 add r1, r6, #4
 *   @0x21ea38 ldr r2, [r6]
 *   @0x21ea3c mov r3, r4
 *   @0x21ea40 add r0, pc, r0
 *   @0x21ea44 ldr r0, [r0]
 *   @0x21ea48 bl 0x22054c <_ZN13SoundHardware4LoadEPvii>
 *   @0x21ea4c str r0, [r5, #0x8]
 *   @0x21ea50 mov r0, r4
 *   @0x21ea54 pop {r4, r5, r6, pc}
 *   @0x21ea58 andseq r2, sp, r12, lsl #20
 *   @0x21ea5c subseq r6, r3, r4, ror #17
 *
 * ══ §242/281 alutInitWithoutContext  0x221b10  size 104  26 条（0x221b10..0x221b78）
 * @func 0x221b10 0x221b78  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSetError×2
 * 字段偏移 top8: 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221b10 ldr r3, [pc, #0x5c]
 *   @0x221b14 push {r4, lr}
 *   @0x221b18 add r3, pc, r3
 *   @0x221b1c ldr r4, [r3]
 *   @0x221b20 cmp r4, #0
 *   @0x221b24 bne 0x221b54 <alutInitWithoutContext+0x44>
 *   @0x221b28 rsbs r1, r1, #1
 *   @0x221b2c movlo r1, #0
 *   @0x221b30 cmp r0, #0
 *   @0x221b34 movne r0, r1
 *   @0x221b38 eoreq r0, r1, #1
 *   @0x221b3c cmp r0, #0
 *   @0x221b40 bne 0x221b64 <alutInitWithoutContext+0x54>
 *   @0x221b44 mov r2, #2
 *   @0x221b48 mov r0, #1
 *   @0x221b4c str r2, [r3]
 *   @0x221b50 pop {r4, pc}
 *   @0x221b54 movw r0, #0x203
 *   @0x221b58 bl 0x221940 <_alutSetError>
 *   @0x221b5c mov r0, #0
 *   @0x221b60 pop {r4, pc}
 *   @0x221b64 movw r0, #0x202
 *   @0x221b68 bl 0x221940 <_alutSetError>
 *   @0x221b6c mov r0, r4
 *   @0x221b70 pop {r4, pc}
 *   @0x221b74 subseq r3, r3, r0, asr r9
 *
 * ══ §243/281 ov_test_open  0x231d94  size 104  26 条（0x231d94..0x231dfc）
 * @func 0x231d94 0x231dfc  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_231ac4 / ov_clear
 * 字段偏移 top8: 0x58×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231d94 push {r3, r4, r5, lr}
 *   @0x231d98 mov r4, r0
 *   @0x231d9c ldr r3, [r0, #0x58]
 *   @0x231da0 cmp r3, #1
 *   @0x231da4 mvnne r3, #130
 *   @0x231da8 bne 0x231dc8 <ov_test_open+0x34>
 *   @0x231dac ldr r3, [r0, #0x4]
 *   @0x231db0 mov r2, #2
 *   @0x231db4 str r2, [r0, #0x58]
 *   @0x231db8 cmp r3, #0
 *   @0x231dbc moveq r2, #3
 *   @0x231dc0 streq r2, [r0, #0x58]
 *   @0x231dc4 bne 0x231dd0 <ov_test_open+0x3c>
 *   @0x231dc8 mov r0, r3
 *   @0x231dcc pop {r3, r4, r5, pc}
 *   @0x231dd0 bl 0x231ac4 <ov_raw_seek+0x4ac>
 *   @0x231dd4 subs r5, r0, #0
 *   @0x231dd8 bne 0x231de8 <ov_test_open+0x54>
 *   @0x231ddc mov r3, r5
 *   @0x231de0 mov r0, r3
 *   @0x231de4 pop {r3, r4, r5, pc}
 *   @0x231de8 mov r3, #0
 *   @0x231dec mov r0, r4
 *   @0x231df0 str r3, [r4]
 *   @0x231df4 bl 0x230ec4 <ov_clear>
 *   @0x231df8 b 0x231ddc <ov_test_open+0x48>
 *
 * ══ §244/281 ogg_stream_pageout_fill  0x234a80  size 104  26 条（0x234a80..0x234ae8）
 * @func 0x234a80 0x234ae8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_check
 * 字段偏移 top8: 0x148×1 / 0x1c×1 / 0x14c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234a80 push {r4, r5, r6, lr}
 *   @0x234a84 mov r6, r1
 *   @0x234a88 mov r5, r2
 *   @0x234a8c mov r4, r0
 *   @0x234a90 bl 0x23412c <ogg_stream_check>
 *   @0x234a94 cmp r0, #0
 *   @0x234a98 bne 0x234ae0 <ogg_stream_pageout_fill+0x60>
 *   @0x234a9c ldr r3, [r4, #0x148]
 *   @0x234aa0 ldr r2, [r4, #0x1c]
 *   @0x234aa4 cmp r3, #0
 *   @0x234aa8 bne 0x234ad4 <ogg_stream_pageout_fill+0x54>
 *   @0x234aac cmp r2, #0
 *   @0x234ab0 beq 0x234ac0 <ogg_stream_pageout_fill+0x40>
 *   @0x234ab4 ldr r2, [r4, #0x14c]
 *   @0x234ab8 rsbs r2, r2, #1
 *   @0x234abc movlo r2, #0
 *   @0x234ac0 mov r0, r4
 *   @0x234ac4 mov r1, r6
 *   @0x234ac8 mov r3, r5
 *   @0x234acc pop {r4, r5, r6, lr}
 *   @0x234ad0 b 0x234434 <ogg_page_checksum_set+0xe0>
 *   @0x234ad4 adds r2, r2, #0
 *   @0x234ad8 movne r2, #1
 *   @0x234adc b 0x234ac0 <ogg_stream_pageout_fill+0x40>
 *   @0x234ae0 mov r0, #0
 *   @0x234ae4 pop {r4, r5, r6, pc}
 *
 * ══ §245/281 IniFile::SetText(char const*)  0x236250  size 104  26 条（0x236250..0x2362b8）
 * @func 0x236250 0x2362b8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4
 * 字段偏移 top8: 0x10×2 / 0x44×1 / 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236250 push {r3, r4, r5, lr}
 *   @0x236254 mov r4, r0
 *   @0x236258 mov r0, r1
 *   @0x23625c mov r5, r1
 *   @0x236260 bl 0xb6538 <strlen@plt>
 *   @0x236264 ldr r1, [pc, #0x44]
 *   @0x236268 mov r3, #1
 *   @0x23626c mov r2, #109
 *   @0x236270 add r1, pc, r1
 *   @0x236274 add r0, r0, r3
 *   @0x236278 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x23627c mov r1, r5
 *   @0x236280 str r0, [r4, #0x10]
 *   @0x236284 bl 0xb65a4 <strcpy@plt>
 *   @0x236288 ldr r0, [r4, #0x10]
 *   @0x23628c bl 0xb6538 <strlen@plt>
 *   @0x236290 ldr r3, [pc, #0x1c]
 *   @0x236294 ldr r3, [pc, r3]
 *   @0x236298 mov r2, r0
 *   @0x23629c mov r0, r4
 *   @0x2362a0 str r2, [r4, #0x4]
 *   @0x2362a4 str r2, [r3]
 *   @0x2362a8 pop {r3, r4, r5, lr}
 *   @0x2362ac b 0x236120 <_ZN7IniFile11ReadIniFileEv>
 *   @0x2362b0 andseq lr, r1, r4, ror lr
 *   @0x2362b4 andseq r11, r11, r8, lsl #4
 *
 * ══ §246/281 JS_String_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*)  0x25129c  size 104  26 条（0x25129c..0x251304）
 * @func 0x25129c 0x251304  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / YYObjectBase::FindValue(char const*) / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x4c×1 / 0x40×1 / 0x34×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25129c push {r4, r5, r6, lr}
 *   @0x2512a0 mov r4, r1
 *   @0x2512a4 ldr r1, [pc, #0x4c]
 *   @0x2512a8 mov r5, r0
 *   @0x2512ac ldr r0, [r4, #0x40]
 *   @0x2512b0 add r1, pc, r1
 *   @0x2512b4 bl 0xb6574 <strcmp@plt>
 *   @0x2512b8 subs r6, r0, #0
 *   @0x2512bc bne 0x2512e8 <_Z28JS_String_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x2512c0 ldr r1, [pc, #0x34]
 *   @0x2512c4 mov r0, r4
 *   @0x2512c8 add r1, pc, r1
 *   @0x2512cc bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x2512d0 mov r1, r6
 *   @0x2512d4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x2512d8 mov r1, r0
 *   @0x2512dc mov r0, r5
 *   @0x2512e0 pop {r4, r5, r6, lr}
 *   @0x2512e4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2512e8 ldr r0, [pc, #0x10]
 *   @0x2512ec pop {r4, r5, r6, lr}
 *   @0x2512f0 add r0, pc, r0
 *   @0x2512f4 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2512f8 andseq r4, r0, r0, lsl #11
 *   @0x2512fc andseq r4, r0, r8, asr #4
 *   @0x251300 andseq r4, r0, r8, asr r12
 *
 * ══ §247/281 pcre_copy_substring  0x25f424  size 104  26 条（0x25f424..0x25f48c）
 * @func 0x25f424 0x25f48c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc
 * 字段偏移 top8: 0x2×2 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f424 push {r3, r4, r5, lr}
 *   @0x25f428 lsr r5, r3, #31
 *   @0x25f42c cmp r3, r2
 *   @0x25f430 orrge r5, r5, #1
 *   @0x25f434 ldr r12, [sp, #0x10]
 *   @0x25f438 cmp r5, #0
 *   @0x25f43c bne 0x25f484 <pcre_copy_substring+0x60>
 *   @0x25f440 lsl r3, r3, #1
 *   @0x25f444 add r2, r3, #1
 *   @0x25f448 ldr r3, [r1, r3, lsl #2]
 *   @0x25f44c ldr r4, [r1, r2, lsl #2]
 *   @0x25f450 ldr r2, [sp, #0x14]
 *   @0x25f454 rsb r4, r3, r4
 *   @0x25f458 cmp r4, r2
 *   @0x25f45c bge 0x25f47c <pcre_copy_substring+0x58>
 *   @0x25f460 add r1, r0, r3
 *   @0x25f464 mov r2, r4
 *   @0x25f468 mov r0, r12
 *   @0x25f46c bl 0xb65bc <memcpy@plt>
 *   @0x25f470 strb r5, [r0, r4]
 *   @0x25f474 mov r0, r4
 *   @0x25f478 pop {r3, r4, r5, pc}
 *   @0x25f47c mvn r0, #5
 *   @0x25f480 pop {r3, r4, r5, pc}
 *   @0x25f484 mvn r0, #6
 *   @0x25f488 pop {r3, r4, r5, pc}
 *
 * ══ §248/281 spBone_worldToLocal  0x285994  size 104  26 条（0x285994..0x2859fc）
 * @func 0x285994 0x2859fc  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285994 vldr s13, [r0, #56]
 *   @0x285998 vldr s14, [r0, #64]
 *   @0x28599c vmul.f32 s15, s13, s14
 *   @0x2859a0 vldr s10, [r0, #52]
 *   @0x2859a4 vldr s12, [r0, #68]
 *   @0x2859a8 vldr s9, [r0, #72]
 *   @0x2859ac vldr s11, [r0, #60]
 *   @0x2859b0 ldr r0, [sp]
 *   @0x2859b4 vnmls.f32 s15, s10, s12
 *   @0x2859b8 vmov.f32 s8, #1.000000e+00
 *   @0x2859bc vdiv.f32 s15, s8, s15
 *   @0x2859c0 vmov s8, r2
 *   @0x2859c4 vsub.f32 s9, s8, s9
 *   @0x2859c8 vmov s8, r1
 *   @0x2859cc vsub.f32 s11, s8, s11
 *   @0x2859d0 vmul.f32 s13, s9, s13
 *   @0x2859d4 vmul.f32 s14, s11, s14
 *   @0x2859d8 vmul.f32 s13, s13, s15
 *   @0x2859dc vmul.f32 s10, s9, s10
 *   @0x2859e0 vmul.f32 s12, s11, s12
 *   @0x2859e4 vmul.f32 s14, s14, s15
 *   @0x2859e8 vnmls.f32 s13, s12, s15
 *   @0x2859ec vnmls.f32 s14, s10, s15
 *   @0x2859f0 vstr s13, [r3]
 *   @0x2859f4 vstr s14, [r0]
 *   @0x2859f8 bx lr
 *
 * ══ §249/281 spIkConstraintData_create  0x2866f0  size 104  26 条（0x2866f0..0x286758）
 * @func 0x2866f0 0x286758  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x54×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2866f0 push {r4, r5, r6, lr}
 *   @0x2866f4 mov r3, #36
 *   @0x2866f8 ldr r6, [pc, #0x54]
 *   @0x2866fc mov r5, r0
 *   @0x286700 mov r1, #24
 *   @0x286704 mov r0, #1
 *   @0x286708 add r6, pc, r6
 *   @0x28670c mov r2, r6
 *   @0x286710 bl 0x285c4c <_calloc>
 *   @0x286714 mov r4, r0
 *   @0x286718 mov r0, r5
 *   @0x28671c bl 0xb6538 <strlen@plt>
 *   @0x286720 mov r1, r6
 *   @0x286724 mov r2, #37
 *   @0x286728 add r0, r0, #1
 *   @0x28672c bl 0x285c10 <_malloc>
 *   @0x286730 mov r1, r5
 *   @0x286734 str r0, [r4]
 *   @0x286738 bl 0xb65a4 <strcpy@plt>
 *   @0x28673c mov r2, #1065353216
 *   @0x286740 mov r3, #1
 *   @0x286744 mov r0, r4
 *   @0x286748 str r3, [r4, #0x10]
 *   @0x28674c str r2, [r4, #0x14]
 *   @0x286750 pop {r4, r5, r6, pc}
 *   @0x286754 andeq r1, sp, r0, ror r1
 *
 * ══ §250/281 _Entry_create  0x28ebb8  size 104  26 条（0x28ebb8..0x28ec20）
 * @func 0x28ebb8 0x28ec20  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x54×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ebb8 push {r4, r5, r6, r7, r8, lr}
 *   @0x28ebbc mov r3, #36
 *   @0x28ebc0 ldr r6, [pc, #0x54]
 *   @0x28ebc4 mov r5, r1
 *   @0x28ebc8 mov r8, r0
 *   @0x28ebcc mov r7, r2
 *   @0x28ebd0 add r6, pc, r6
 *   @0x28ebd4 mov r1, #16
 *   @0x28ebd8 mov r0, #1
 *   @0x28ebdc mov r2, r6
 *   @0x28ebe0 bl 0x285c4c <_calloc>
 *   @0x28ebe4 mov r4, r0
 *   @0x28ebe8 str r8, [r0]
 *   @0x28ebec mov r0, r5
 *   @0x28ebf0 bl 0xb6538 <strlen@plt>
 *   @0x28ebf4 mov r1, r6
 *   @0x28ebf8 mov r2, #38
 *   @0x28ebfc add r0, r0, #1
 *   @0x28ec00 bl 0x285c10 <_malloc>
 *   @0x28ec04 mov r1, r5
 *   @0x28ec08 str r0, [r4, #0x4]
 *   @0x28ec0c bl 0xb65a4 <strcpy@plt>
 *   @0x28ec10 str r7, [r4, #0x8]
 *   @0x28ec14 mov r0, r4
 *   @0x28ec18 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28ec1c strheq r9, [r12], -r8
 *
 * ══ §251/281 ImportGLLibrary()  0x28fce4  size 104  26 条（0x28fce4..0x28fd4c）
 * @func 0x28fce4 0x28fd4c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GLFuncImport(bool) / GLFuncImportDestroy()
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fce4 push {r4, lr}
 *   @0x28fce8 ldr r4, [pc, #0x58]
 *   @0x28fcec ldr r4, [pc, r4]
 *   @0x28fcf0 ldr r0, [r4]
 *   @0x28fcf4 cmp r0, #1
 *   @0x28fcf8 movne r0, #0
 *   @0x28fcfc bl 0xba710 <_Z12GLFuncImportb>
 *   @0x28fd00 cmp r0, #2
 *   @0x28fd04 moveq r3, #1
 *   @0x28fd08 streq r3, [r4]
 *   @0x28fd0c popeq {r4, pc}
 *   @0x28fd10 ldr r3, [r4]
 *   @0x28fd14 cmp r3, #1
 *   @0x28fd18 beq 0x28fd28 <_Z15ImportGLLibraryv+0x44>
 *   @0x28fd1c mov r3, #0
 *   @0x28fd20 str r3, [r4]
 *   @0x28fd24 pop {r4, pc}
 *   @0x28fd28 cmp r0, #3
 *   @0x28fd2c bne 0x28fd1c <_Z15ImportGLLibraryv+0x38>
 *   @0x28fd30 bl 0xbd6a4 <_Z19GLFuncImportDestroyv>
 *   @0x28fd34 mov r3, #0
 *   @0x28fd38 mov r0, r3
 *   @0x28fd3c str r3, [r4]
 *   @0x28fd40 pop {r4, lr}
 *   @0x28fd44 b 0xba710 <_Z12GLFuncImportb>
 *   @0x28fd48 andseq r0, r6, r12, lsl r7
 *
 * ══ §252/281 CProfiler::AddNodeDirect(int, int, unsigned int)  0x2a06d0  size 104  26 条（0x2a06d0..0x2a0738）
 * @func 0x2a06d0 0x2a0738  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CProfiler::FindOrCreateNode(int, int)
 * 字段偏移 top8: 0x20×2 / 0x5c×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a06d0 ldr r12, [pc, #0x5c]
 *   @0x2a06d4 push {r4, r5, r6, lr}
 *   @0x2a06d8 ldr r12, [pc, r12]
 *   @0x2a06dc mov r6, r3
 *   @0x2a06e0 mov r4, r0
 *   @0x2a06e4 ldrb r3, [r12]
 *   @0x2a06e8 cmp r3, #0
 *   @0x2a06ec popeq {r4, r5, r6, pc}
 *   @0x2a06f0 bl 0x2a04f4 <_ZN9CProfiler16FindOrCreateNodeEii>
 *   @0x2a06f4 ldr r3, [r4, #0xc]
 *   @0x2a06f8 ldr r3, [r3, #0x8]
 *   @0x2a06fc add r0, r0, r0, lsl #2
 *   @0x2a0700 add r0, r3, r0, lsl #3
 *   @0x2a0704 ldrd r4, r5, [r0, #8]
 *   @0x2a0708 ldrd r2, r3, [r0, #16]
 *   @0x2a070c adds r4, r4, #1
 *   @0x2a0710 ldr r1, [r0, #0x20]
 *   @0x2a0714 adc r5, r5, #0
 *   @0x2a0718 adds r2, r2, r6
 *   @0x2a071c adc r3, r3, #0
 *   @0x2a0720 add r6, r1, r6
 *   @0x2a0724 strd r4, r5, [r0, #8]
 *   @0x2a0728 strd r2, r3, [r0, #16]
 *   @0x2a072c str r6, [r0, #0x20]
 *   @0x2a0730 pop {r4, r5, r6, pc}
 *   @0x2a0734 mulseq r4, r0, r4
 *
 * ══ §253/281 Init()  0x2a2914  size 104  26 条（0x2a2914..0x2a297c）
 * @func 0x2a2914 0x2a297c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RomDisk::Init(unsigned char*) / Timing_Init / InitFastCRC() / INITIALIZE_PlatformSpecific() / INITIALIZE_Support_File() / INITIALIZE_Graphics_Draw() / INITIALIZE_Code_Constant() / INITIALIZE_Graphics_Window()
 * 字段偏移 top8: 0x58×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a2914 ldr r0, [pc, #0x58]
 *   @0x2a2918 push {r3, lr}
 *   @0x2a291c ldr r0, [pc, r0]
 *   @0x2a2920 bl 0x1a86ac <_ZN7RomDisk4InitEPh>
 *   @0x2a2924 bl 0x2151b8 <Timing_Init>
 *   @0x2a2928 bl 0x27de00 <_Z11InitFastCRCv>
 *   @0x2a292c bl 0x28fe6c <_Z27INITIALIZE_PlatformSpecificv>
 *   @0x2a2930 bl 0x214e10 <_Z23INITIALIZE_Support_Filev>
 *   @0x2a2934 bl 0x16c2c0 <_Z24INITIALIZE_Graphics_Drawv>
 *   @0x2a2938 bl 0xee01c <_Z24INITIALIZE_Code_Constantv>
 *   @0x2a293c bl 0x179d3c <_Z26INITIALIZE_Graphics_Windowv>
 *   @0x2a2940 bl 0x1a5dd8 <_Z24INITIALIZE_Particle_Mainv>
 *   @0x2a2944 bl 0x1cb778 <_Z21INITIALIZE_Run_Globalv>
 *   @0x2a2948 bl 0x21f210 <_Z24INITIALIZE_Sound_DirectXv>
 *   @0x2a294c bl 0x1ffbd0 <_Z27INITIALIZE_Variable_BuiltInv>
 *   @0x2a2950 bl 0x1a8518 <_Z15INITIALIZE_Pathv>
 *   @0x2a2954 bl 0x1dc3b8 <_Z16INITIALIZE_Scorev>
 *   @0x2a2958 bl 0x1d37a4 <_Z15INITIALIZE_Mainv>
 *   @0x2a295c ldr r0, [pc, #0x14]
 *   @0x2a2960 ldr r0, [pc, r0]
 *   @0x2a2964 bl 0x16ddac <_ZN14CCameraManager17SetupGMLFunctionsEv>
 *   @0x2a2968 bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x2a296c mov r0, #1
 *   @0x2a2970 pop {r3, pc}
 *   @0x2a2974 andseq pc, r4, r0, ror #2
 *   @0x2a2978 andseq r11, r4, r4, lsl r3
 *
 * ══ §254/281 png_crc_error  0x2abc2a  size 104  26 条（0x2abc2a..0x2abc92）
 * @func 0x2abc2a 0x2abc92  size 104  26 条
 * 部分覆盖: 本节 26/43 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_read_data / anon_2b8084+0x352
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2abc2a push {r0, r1, r2, r4, r5, lr}
 *   @0x2abc2e ldrb.w r3, [r0, #0x1e0]
 *   @0x2abc32 ldr.w r5, [r0, #0x130]
 *   @0x2abc36 tst.w r3, #0x20
 *   @0x2abc3a beq 0x2abc4a <png_crc_error+0x20>
 *   @0x2abc3e .word 0xf5b57540
 *   @0x2abc42 svclt #0x187540
 *   @0x2abc46 movne r5, #0x1
 *   @0x2abc4a eor r5, r5, #0x800
 *   @0x2abc4e ubfx r5, r5, #0xb, #0x1
 *   @0x2abc52 movs r3, #0x81
 *   @0x2abc56 str.w r3, [r4, #0x334]
 *   @0x2abc5a add r1, sp, #0x4
 *   @0x2abc5e bl 0x2a8030 <png_read_data>
 *   @0x2abc62 cbz r5, 0x2abc8c <png_crc_error+0x62>
 *   @0x2abc66 .word 0xf89d0005
 *   @0x2abc6a .word 0xf89d3004
 *   @0x2abc6e streq r5, [r0], #-6
 *   @0x2abc72 add.w r0, r0, r3, lsl #24
 *   @0x2abc76 ldrb.w r3, [sp, #0x7]
 *   @0x2abc7a add r0, r3
 *   @0x2abc7e bl 0x2b83d6 <jinit_phuff_decoder+0x3fa>
 *   @0x2abc82 bne 0xff2b3c9e <b2_toiTime+0xfffffffffeb5a7fa>
 *   @0x2abc86 it ne
 *   @0x2abc8a b 0x2abc8e <png_crc_error+0x64>
 *   @0x2abc8e add sp, #0xc
 *
 * ══ §255/281 b2Mat33::GetInverse22(b2Mat33*) const  0x2c6940  size 104  26 条（0x2c6940..0x2c69a8）
 * @func 0x2c6940 0x2c69a8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x14×1 / 0x18×1 / 0x1c×1 / 0x20×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6940 vldr s12, [r0, #12]
 *   @0x2c6944 vldr s13, [r0, #4]
 *   @0x2c6948 vmul.f32 s15, s12, s13
 *   @0x2c694c vldr s11, [r0]
 *   @0x2c6950 vldr s10, [r0, #16]
 *   @0x2c6954 mov r3, #0
 *   @0x2c6958 str r3, [r1, #0x8]
 *   @0x2c695c str r3, [r1, #0x14]
 *   @0x2c6960 str r3, [r1, #0x18]
 *   @0x2c6964 str r3, [r1, #0x1c]
 *   @0x2c6968 str r3, [r1, #0x20]
 *   @0x2c696c vnmls.f32 s15, s11, s10
 *   @0x2c6970 vcmp.f32 s15, #0
 *   @0x2c6974 vmrs APSR_nzcv, fpscr
 *   @0x2c6978 vmovne.f32 s14, #1.000000e+00
 *   @0x2c697c vdivne.f32 s15, s14, s15
 *   @0x2c6980 vneg.f32 s14, s15
 *   @0x2c6984 vmul.f32 s10, s15, s10
 *   @0x2c6988 vmul.f32 s12, s14, s12
 *   @0x2c698c vstr s10, [r1]
 *   @0x2c6990 vmul.f32 s15, s15, s11
 *   @0x2c6994 vstr s12, [r1, #12]
 *   @0x2c6998 vmul.f32 s14, s13, s14
 *   @0x2c699c vstr s15, [r1, #16]
 *   @0x2c69a0 vstr s14, [r1, #4]
 *   @0x2c69a4 bx lr
 *
 * ══ §256/281 FT_Render_Glyph_Internal  0x2e5e70  size 104  26 条（0x2e5e70..0x2e5ed8）
 * @func 0x2e5e70 0x2e5ed8  size 104  26 条
 * 部分覆盖: 本节 26/48 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Lookup_Renderer
 * 字段偏移 top8: 0x11×2 / 0x4c×1 / 0x4×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5e70 push.w {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x2e5e74 mov r6, r1
 *   @0x2e5e78 mov r5, r0
 *   @0x2e5e7c mov r7, r2
 *   @0x2e5e80 cmp r1, r3
 *   @0x2e5e84 ldr r3, [pc, #0x4c]
 *   @0x2e5e88 cmp r1, r3
 *   @0x2e5e8c ldr.w r3, [r5, #0x94]
 *   @0x2e5e90 ldr.w r0, [r0, #0x9c]
 *   @0x2e5e94 str r3, [sp, #0x4]
 *   @0x2e5e98 add r2, sp, #0x4
 *   @0x2e5e9c .word 0xf10dffcc
 *   @0x2e5ea0 strhs r0, [r7], #-2052
 *   @0x2e5ea4 cbz r0, 0x2e5ec6 <FT_Render_Glyph_Internal+0x56>
 *   @0x2e5ea8 mov r1, r6
 *   @0x2e5eac movs r3, #0x0
 *   @0x2e5eb0 mov r4, r0
 *   @0x2e5eb4 uxtb r3, r0
 *   @0x2e5eb8 bne 0x2e5ec6 <FT_Render_Glyph_Internal+0x56>
 *   @0x2e5ebc ldr r1, [r6, #0x48]
 *   @0x2e5ec0 bl 0x2e5e36 <FT_Lookup_Renderer>
 *   @0x2e5ec4 b 0x2e5ea4 <FT_Render_Glyph_Internal+0x34>
 *   @0x2e5ec8 add sp, #0x8
 *   @0x2e5ecc svclt #0x81f0
 *   @0x2e5ed0 strb r3, [r6, #0x11]
 *   @0x2e5ed4 strb r4, [r5, #0x11]
 *
 * ══ §257/281 FT_Set_Renderer  0x2e8a9c  size 104  26 条（0x2e8a9c..0x2e8b04）
 * @func 0x2e8a9c 0x2e8b04  size 104  26 条
 * 部分覆盖: 本节 26/47 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_List_Find
 * 字段偏移 top8: 0x28×1 / 0x34×1 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8a9c push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2e8aa0 mov r4, r1
 *   @0x2e8aa4 mov r6, r3
 *   @0x2e8aa8 cbz r0, 0x2e8afa <FT_Set_Renderer+0x5e>
 *   @0x2e8aac movs r0, #0x6
 *   @0x2e8ab0 strdlt r8, r9, [r10, -r0]
 *   @0x2e8ab4 cmp r3, #0x0
 *   @0x2e8ab8 add.w r8, r7, #0x94
 *   @0x2e8abc mov r1, r4
 *   @0x2e8ac0 bl 0x2e890e <FT_List_Find>
 *   @0x2e8ac4 mov r1, r0
 *   @0x2e8ac8 beq 0x2e8aac <FT_Set_Renderer+0x10>
 *   @0x2e8acc adds r6, #0x8
 *   @0x2e8ad0 stmdbvs r3!, {r1, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e8ad4 ldr r2, [pc, #0x28]
 *   @0x2e8ad8 it eq
 *   @0x2e8adc stmvs r3!, {r2, r3, r4, r7, lr} ^
 *   @0x2e8ae0 ldr r7, [r3, #0x34]
 *   @0x2e8ae4 ldmdb r6, {r1, r2}
 *   @0x2e8ae8 mov r0, r4
 *   @0x2e8aec adds r6, #0x8
 *   @0x2e8af0 subs r5, #0x1
 *   @0x2e8af4 mov r0, r5
 *   @0x2e8af8 .word 0x202181f0
 *   @0x2e8afc pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e8b00 strb r4, [r5, #0x11]
 *
 * ══ §258/281 _zip_entry_new(zip*)  0x2a5790  size 102  26 条（0x2a5790..0x2a57f6）
 * @func 0x2a5790 0x2a57f8  size 104  26 条
 * 部分覆盖: 本节 26/48 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544 / _zip_entry_new(zip*)+0x40 / 0xb6c28
 * 字段偏移 top8: 0x2c×3 / 0x30×1 / 0x34×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5790 push {r3, r4, r5, lr}
 *   @0x2a5794 cbnz r0, 0x2a57a4 <_Z14_zip_entry_newP3zip+0x14>
 *   @0x2a5798 blx 0xb6544 <malloc@plt>
 *   @0x2a579c mov r5, r0
 *   @0x2a57a0 cbnz r5, 0x2a57da <_Z14_zip_entry_newP3zip+0x4a>
 *   @0x2a57a4 ldr r3, [r0, #0x30]
 *   @0x2a57a8 subs r1, r3, #0x1
 *   @0x2a57ac blt 0x2a57d0 <_Z14_zip_entry_newP3zip+0x40>
 *   @0x2a57b0 movs r1, #0x14
 *   @0x2a57b4 muls r1, r3, r1
 *   @0x2a57b8 blx 0xb6c28 <realloc@plt>
 *   @0x2a57bc mov r5, r0
 *   @0x2a57c0 cbnz r0, 0x2a57d0 <_Z14_zip_entry_newP3zip+0x40>
 *   @0x2a57c4 .word 0x210e000c
 *   @0x2a57c8 mov r2, r5
 *   @0x2a57cc ands pc, r0, r5, asr #27
 *   @0x2a57d0 ldr r2, [r4, #0x2c]
 *   @0x2a57d4 ldr r3, [r4, #0x34]
 *   @0x2a57d8 movwhs r3, #0x502
 *   @0x2a57dc mov.w r2, #0xffffffff
 *   @0x2a57e0 str r3, [r5]
 *   @0x2a57e4 str r3, [r5, #0xc]
 *   @0x2a57e8 str r3, [r5, #0x4]
 *   @0x2a57ec ldr r3, [r4, #0x2c]
 *   @0x2a57f0 str r3, [r4, #0x2c]
 *   @0x2a57f4 pop {r3, r4, r5, pc}
 *
 * ══ §259/281 ASCIIToUnicode(char const*)  0xc4620  size 100  25 条（0xc4620..0xc4684）
 * @func 0xc4620 0xc4684  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / ASCIIToUnicode(char const*)+0x50
 * 字段偏移 top8: 0x4c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4620 push {r3, r4, r5, lr}
 *   @0xc4624 mov r5, r0
 *   @0xc4628 bl 0xb6538 <strlen@plt>
 *   @0xc462c ldr r1, [pc, #0x4c]
 *   @0xc4630 mov r2, #191
 *   @0xc4634 mov r3, #1
 *   @0xc4638 add r1, pc, r1
 *   @0xc463c mov r4, r0
 *   @0xc4640 add r0, r0, #1
 *   @0xc4644 lsl r0, r0, #1
 *   @0xc4648 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xc464c cmp r4, #0
 *   @0xc4650 movgt r3, #0
 *   @0xc4654 subgt r2, r0, #2
 *   @0xc4658 ble 0xc4670 <_Z14ASCIIToUnicodePKc+0x50>
 *   @0xc465c ldrb r1, [r5, r3]
 *   @0xc4660 add r3, r3, #1
 *   @0xc4664 cmp r4, r3
 *   @0xc4668 strh r1, [r2, #2]!
 *   @0xc466c bne 0xc465c <_Z14ASCIIToUnicodePKc+0x3c>
 *   @0xc4670 lsl r4, r4, #1
 *   @0xc4674 mov r3, #0
 *   @0xc4678 strh r3, [r0, r4]
 *   @0xc467c pop {r3, r4, r5, pc}
 *   @0xc4680 eoreq r12, r6, r12, asr #9
 *
 * ══ §260/281 FreeAllBuffers()  0xc7b44  size 100  25 条（0xc7b44..0xc7ba8）
 * @func 0xc7b44 0xc7ba8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7b44 push {r3, r4, r5, r6, r7, lr}
 *   @0xc7b48 ldr r5, [pc, #0x54]
 *   @0xc7b4c add r5, pc, r5
 *   @0xc7b50 ldr r3, [r5]
 *   @0xc7b54 cmp r3, #0
 *   @0xc7b58 pople {r3, r4, r5, r6, r7, pc}
 *   @0xc7b5c mov r4, #0
 *   @0xc7b60 mov r7, r5
 *   @0xc7b64 mov r6, r4
 *   @0xc7b68 ldr r3, [r5, #0x4]
 *   @0xc7b6c ldr r3, [r3, r4, lsl #2]
 *   @0xc7b70 cmp r3, #0
 *   @0xc7b74 mov r0, r3
 *   @0xc7b78 beq 0xc7b90 <_Z14FreeAllBuffersv+0x4c>
 *   @0xc7b7c ldr r3, [r3]
 *   @0xc7b80 ldr r3, [r3, #0x4]
 *   @0xc7b84 blx r3
 *   @0xc7b88 ldr r3, [r5, #0x4]
 *   @0xc7b8c str r6, [r3, r4, lsl #2]
 *   @0xc7b90 ldr r3, [r7]
 *   @0xc7b94 add r4, r4, #1
 *   @0xc7b98 cmp r3, r4
 *   @0xc7b9c bgt 0xc7b68 <_Z14FreeAllBuffersv+0x24>
 *   @0xc7ba0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc7ba4 eorseq r2, r11, r8, asr #11
 *
 * ══ §261/281 F_Vertex_Get_Buffer_Size(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8914  size 100  25 条（0xc8914..0xc8978）
 * @func 0xc8914 0xc8978  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GetBufferVertex(int)
 * 字段偏移 top8: 0x4×2 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8914 push {r4, lr}
 *   @0xc8918 mov r1, #0
 *   @0xc891c ldr r3, [sp, #0x8]
 *   @0xc8920 mov r4, r0
 *   @0xc8924 str r1, [r0, #0xc]
 *   @0xc8928 mov r0, r3
 *   @0xc892c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8930 bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc8934 cmp r0, #0
 *   @0xc8938 beq 0xc8954 <_Z24F_Vertex_Get_Buffer_SizeR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0xc893c ldr r2, [r0, #0x4]
 *   @0xc8940 vmov s15, r2
 *   @0xc8944 vcvt.f64.u32 d7, s15
 *   @0xc8948 vmov r2, r3, d7
 *   @0xc894c stm r4, {r2, r3}
 *   @0xc8950 pop {r4, pc}
 *   @0xc8954 str r0, [r4]
 *   @0xc8958 mov r3, #0
 *   @0xc895c ldr r0, [pc, #0x10]
 *   @0xc8960 movt r3, #0xbff0
 *   @0xc8964 str r3, [r4, #0x4]
 *   @0xc8968 add r0, pc, r0
 *   @0xc896c pop {r4, lr}
 *   @0xc8970 b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc8974 eoreq r9, r6, r0, asr r0
 *
 * ══ §262/281 F_Vertex_Create_Buffer_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8b1c  size 100  25 条（0xc8b1c..0xc8b80）
 * @func 0xc8b1c 0xc8b80  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocBufferVertex(int)
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8b1c cmp r3, #0
 *   @0xc8b20 mov r2, #0
 *   @0xc8b24 push {r4, lr}
 *   @0xc8b28 mov r3, r2
 *   @0xc8b2c mov r4, r0
 *   @0xc8b30 movt r2, #0xbff0
 *   @0xc8b34 str r3, [r0, #0xc]
 *   @0xc8b38 str r2, [r0, #0x4]
 *   @0xc8b3c str r3, [r0]
 *   @0xc8b40 bne 0xc8b68 <_Z28F_Vertex_Create_Buffer_debugR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xc8b44 mov r0, #32768
 *   @0xc8b48 bl 0xc8978 <_Z17AllocBufferVertexi>
 *   @0xc8b4c vmov s15, r0
 *   @0xc8b50 vcvt.f64.s32 d7, s15
 *   @0xc8b54 vmov r0, r1, d7
 *   @0xc8b58 vmov r2, s14
 *   @0xc8b5c mov r3, r1
 *   @0xc8b60 stm r4, {r2, r3}
 *   @0xc8b64 pop {r4, pc}
 *   @0xc8b68 ldr r0, [pc, #0xc]
 *   @0xc8b6c mov r1, #1
 *   @0xc8b70 pop {r4, lr}
 *   @0xc8b74 add r0, pc, r0
 *   @0xc8b78 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8b7c eoreq r8, r6, r0, lsr #29
 *
 * ══ §263/281 F_Vertex_Float3_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc95ac  size 100  25 条（0xc95ac..0xc9610）
 * @func 0xc95ac 0xc9610  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextType(yyVertexType)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc95ac push {r3, r4, r5, lr}
 *   @0xc95b0 mov r1, r3
 *   @0xc95b4 ldr r4, [sp, #0x10]
 *   @0xc95b8 mov r3, #4
 *   @0xc95bc mov r2, r4
 *   @0xc95c0 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc95c4 cmp r0, #0
 *   @0xc95c8 popeq {r3, r4, r5, pc}
 *   @0xc95cc mov r1, #3
 *   @0xc95d0 bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType>
 *   @0xc95d4 subs r5, r0, #0
 *   @0xc95d8 popeq {r3, r4, r5, pc}
 *   @0xc95dc mov r1, #1
 *   @0xc95e0 mov r0, r4
 *   @0xc95e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc95e8 mov r1, #2
 *   @0xc95ec str r0, [r5]
 *   @0xc95f0 mov r0, r4
 *   @0xc95f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc95f8 mov r1, #3
 *   @0xc95fc str r0, [r5, #0x4]
 *   @0xc9600 mov r0, r4
 *   @0xc9604 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc9608 str r0, [r5, #0x8]
 *   @0xc960c pop {r3, r4, r5, pc}
 *
 * ══ §264/281 CFontGM::~CFontGM()  0xf7d34  size 100  25 条（0xf7d34..0xf7d98）
 * @func 0xf7d34 0xf7d98  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::Clear() / operator delete(void*)
 * 字段偏移 top8: 0x5c×2 / 0x50×1 / 0x64×1 / 0x68×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf7d34 push {r3, r4, r5, lr}
 *   @0xf7d38 mov r5, r0
 *   @0xf7d3c ldr r3, [pc, #0x50]
 *   @0xf7d40 ldr r3, [pc, r3]
 *   @0xf7d44 add r3, r3, #8
 *   @0xf7d48 str r3, [r0]
 *   @0xf7d4c bl 0xf70a0 <_ZN7CFontGM5ClearEv>
 *   @0xf7d50 ldr r0, [r5, #0x5c]
 *   @0xf7d54 mov r2, #0
 *   @0xf7d58 mvn r3, #0
 *   @0xf7d5c cmp r0, r2
 *   @0xf7d60 str r2, [r5, #0x64]
 *   @0xf7d64 str r3, [r5, #0x68]
 *   @0xf7d68 beq 0xf7d80 <_ZN7CFontGMD2Ev+0x4c>
 *   @0xf7d6c ldr r4, [r0]
 *   @0xf7d70 bl 0x27d1d0 <_ZdlPv>
 *   @0xf7d74 cmp r4, #0
 *   @0xf7d78 mov r0, r4
 *   @0xf7d7c bne 0xf7d6c <_ZN7CFontGMD2Ev+0x38>
 *   @0xf7d80 mov r3, #0
 *   @0xf7d84 mov r0, r5
 *   @0xf7d88 str r3, [r5, #0x5c]
 *   @0xf7d8c str r3, [r5, #0x60]
 *   @0xf7d90 pop {r3, r4, r5, pc}
 *   @0xf7d94 eoreq r6, pc, r8, lsl #2
 *
 * ══ §265/281 YYGML_ds_stack_pop(int)  0xffe84  size 100  25 条（0xffe84..0xffee8）
 * @func 0xffe84 0xffee8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_ds_stack_pop(int)+0x40 / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x44×1 / 0x34×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xffe84 cmp r0, #0
 *   @0xffe88 push {r3, lr}
 *   @0xffe8c blt 0xffec4 <_Z18YYGML_ds_stack_popi+0x40>
 *   @0xffe90 ldr r3, [pc, #0x44]
 *   @0xffe94 ldr r3, [pc, r3]
 *   @0xffe98 ldr r3, [r3]
 *   @0xffe9c cmp r0, r3
 *   @0xffea0 bge 0xffec4 <_Z18YYGML_ds_stack_popi+0x40>
 *   @0xffea4 ldr r3, [pc, #0x34]
 *   @0xffea8 ldr r3, [pc, r3]
 *   @0xffeac ldr r3, [r3, #0x4]
 *   @0xffeb0 ldr r0, [r3, r0, lsl #2]
 *   @0xffeb4 cmp r0, #0
 *   @0xffeb8 beq 0xffec4 <_Z18YYGML_ds_stack_popi+0x40>
 *   @0xffebc pop {r3, lr}
 *   @0xffec0 b 0x202d00 <_ZN9CDS_Stack3PopEv>
 *   @0xffec4 ldr r0, [pc, #0x18]
 *   @0xffec8 mov r1, #0
 *   @0xffecc add r0, pc, r0
 *   @0xffed0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xffed4 mov r0, #0
 *   @0xffed8 pop {r3, pc}
 *   @0xffedc eoreq sp, lr, r8, ror #31
 *   @0xffee0 .word 0x002edfd8
 *   @0xffee4 eoreq r7, r3, r0, lsr sp
 *
 * ══ §266/281 F_PlaceFree(RValue&, CInstance*, CInstance*, int, RValue*)  0x10789c  size 100  25 条（0x10789c..0x107900）
 * @func 0x10789c 0x107900  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / Command_IsFree(CInstance*, float, float)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10789c push {r4, r5, r6, r7, r8, lr}
 *   @0x1078a0 mov r5, #0
 *   @0x1078a4 ldr r6, [sp, #0x18]
 *   @0x1078a8 mov r4, r0
 *   @0x1078ac str r5, [r0, #0xc]
 *   @0x1078b0 mov r8, r1
 *   @0x1078b4 mov r1, r5
 *   @0x1078b8 mov r0, r6
 *   @0x1078bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1078c0 mov r1, #1
 *   @0x1078c4 mov r7, r0
 *   @0x1078c8 mov r0, r6
 *   @0x1078cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1078d0 mov r1, r7
 *   @0x1078d4 mov r2, r0
 *   @0x1078d8 mov r0, r8
 *   @0x1078dc bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x1078e0 cmp r0, #0
 *   @0x1078e4 moveq r5, r0
 *   @0x1078e8 movne r3, r5
 *   @0x1078ec moveq r3, r5
 *   @0x1078f0 movtne r3, #0x3ff0
 *   @0x1078f4 str r5, [r4]
 *   @0x1078f8 str r3, [r4, #0x4]
 *   @0x1078fc pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §267/281 F_PlaceEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0x107f50  size 100  25 条（0x107f50..0x107fb4）
 * @func 0x107f50 0x107fb4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / Command_IsEmpty(CInstance*, float, float)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x107f50 push {r4, r5, r6, r7, r8, lr}
 *   @0x107f54 mov r5, #0
 *   @0x107f58 ldr r6, [sp, #0x18]
 *   @0x107f5c mov r4, r0
 *   @0x107f60 str r5, [r0, #0xc]
 *   @0x107f64 mov r8, r1
 *   @0x107f68 mov r1, r5
 *   @0x107f6c mov r0, r6
 *   @0x107f70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107f74 mov r1, #1
 *   @0x107f78 mov r7, r0
 *   @0x107f7c mov r0, r6
 *   @0x107f80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107f84 mov r1, r7
 *   @0x107f88 mov r2, r0
 *   @0x107f8c mov r0, r8
 *   @0x107f90 bl 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff>
 *   @0x107f94 cmp r0, #0
 *   @0x107f98 moveq r5, r0
 *   @0x107f9c movne r3, r5
 *   @0x107fa0 moveq r3, r5
 *   @0x107fa4 movtne r3, #0x3ff0
 *   @0x107fa8 str r5, [r4]
 *   @0x107fac str r3, [r4, #0x4]
 *   @0x107fb0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §268/281 ImageBGRAtoRGBA(unsigned char*, int, int)  0x120e38  size 100  25 条（0x120e38..0x120e9c）
 * @func 0x120e38 0x120e9c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ImageBGRAtoRGBA(unsigned char*, int, int)+0x5c / ImageBGRAtoRGBA(unsigned char*, int, int)+0x50
 * 字段偏移 top8: 0x-4×1 / 0x2×1 / 0x-8×1 / 0x-2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120e38 cmp r2, #0
 *   @0x120e3c push {r4, r5, r6, r7, r8}
 *   @0x120e40 ble 0x120e94 <_Z15ImageBGRAtoRGBAPhii+0x5c>
 *   @0x120e44 lsl r8, r1, #2
 *   @0x120e48 mov r7, #0
 *   @0x120e4c cmp r1, #0
 *   @0x120e50 ble 0x120e88 <_Z15ImageBGRAtoRGBAPhii+0x50>
 *   @0x120e54 add r12, r0, #4
 *   @0x120e58 mov r3, r0
 *   @0x120e5c mov r4, #0
 *   @0x120e60 ldrb r5, [r12, #-0x4]
 *   @0x120e64 add r4, r4, #1
 *   @0x120e68 ldrb r6, [r3, #0x2]
 *   @0x120e6c cmp r4, r1
 *   @0x120e70 add r12, r12, #4
 *   @0x120e74 add r3, r3, #4
 *   @0x120e78 strb r6, [r12, #-0x8]
 *   @0x120e7c strb r5, [r3, #-0x2]
 *   @0x120e80 bne 0x120e60 <_Z15ImageBGRAtoRGBAPhii+0x28>
 *   @0x120e84 add r0, r0, r8
 *   @0x120e88 add r7, r7, #1
 *   @0x120e8c cmp r7, r2
 *   @0x120e90 bne 0x120e4c <_Z15ImageBGRAtoRGBAPhii+0x14>
 *   @0x120e94 pop {r4, r5, r6, r7, r8}
 *   @0x120e98 bx lr
 *
 * ══ §269/281 F_PathDuplicate(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d9d8  size 100  25 条（0x12d9d8..0x12da3c）
 * @func 0x12d9d8 0x12da3c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / Path_Duplicate(int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×2 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d9d8 push {r3, r4, r5, lr}
 *   @0x12d9dc mov r1, #0
 *   @0x12d9e0 mov r4, r0
 *   @0x12d9e4 ldr r0, [sp, #0x10]
 *   @0x12d9e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d9ec mov r5, r0
 *   @0x12d9f0 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d9f4 subs r1, r0, #0
 *   @0x12d9f8 beq 0x12da20 <_Z15F_PathDuplicateR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12d9fc mov r0, r5
 *   @0x12da00 bl 0x1a8320 <_Z14Path_Duplicatei>
 *   @0x12da04 vmov s15, r0
 *   @0x12da08 vcvt.f64.s32 d7, s15
 *   @0x12da0c vmov r2, r3, d7
 *   @0x12da10 mov r1, #0
 *   @0x12da14 stm r4, {r2, r3}
 *   @0x12da18 str r1, [r4, #0xc]
 *   @0x12da1c pop {r3, r4, r5, pc}
 *   @0x12da20 ldr r0, [pc, #0x10]
 *   @0x12da24 add r0, pc, r0
 *   @0x12da28 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12da2c mov r2, #0
 *   @0x12da30 mov r3, #0
 *   @0x12da34 b 0x12da10 <_Z15F_PathDuplicateR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x12da38 eoreq pc, r0, r12, asr #23
 *
 * ══ §270/281 F_PathAddPoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dab0  size 100  25 条（0x12dab0..0x12db14）
 * @func 0x12dab0 0x12db14  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Path_Data(int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dab0 push {r4, r5, r6, r7, r8, lr}
 *   @0x12dab4 mov r1, #0
 *   @0x12dab8 ldr r4, [sp, #0x18]
 *   @0x12dabc mov r0, r4
 *   @0x12dac0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dac4 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dac8 subs r5, r0, #0
 *   @0x12dacc popeq {r4, r5, r6, r7, r8, pc}
 *   @0x12dad0 mov r0, r4
 *   @0x12dad4 mov r1, #1
 *   @0x12dad8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dadc mov r1, #2
 *   @0x12dae0 mov r7, r0
 *   @0x12dae4 mov r0, r4
 *   @0x12dae8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12daec mov r1, #3
 *   @0x12daf0 mov r6, r0
 *   @0x12daf4 mov r0, r4
 *   @0x12daf8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dafc mov r1, r7
 *   @0x12db00 mov r2, r6
 *   @0x12db04 mov r3, r0
 *   @0x12db08 mov r0, r5
 *   @0x12db0c pop {r4, r5, r6, r7, r8, lr}
 *   @0x12db10 b 0x1a72c0 <_ZN5CPath8AddPointEfff>
 *
 * ══ §271/281 F_RoomSetCamera(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e544  size 100  25 条（0x12e544..0x12e5a8）
 * @func 0x12e544 0x12e5a8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Room_Data(int)
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e544 push {r4, r5, r6, lr}
 *   @0x12e548 mov r1, #0
 *   @0x12e54c ldr r4, [sp, #0x10]
 *   @0x12e550 mov r0, r4
 *   @0x12e554 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e558 mov r1, #1
 *   @0x12e55c mov r6, r0
 *   @0x12e560 mov r0, r4
 *   @0x12e564 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e568 mov r1, #2
 *   @0x12e56c mov r5, r0
 *   @0x12e570 mov r0, r4
 *   @0x12e574 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e578 mov r4, r0
 *   @0x12e57c mov r0, r6
 *   @0x12e580 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e584 cmp r0, #0
 *   @0x12e588 popeq {r4, r5, r6, pc}
 *   @0x12e58c cmp r5, #7
 *   @0x12e590 pophi {r4, r5, r6, pc}
 *   @0x12e594 add r5, r5, #18
 *   @0x12e598 ldr r3, [r0, r5, lsl #2]
 *   @0x12e59c cmp r3, #0
 *   @0x12e5a0 strne r4, [r3, #0x40]
 *   @0x12e5a4 pop {r4, r5, r6, pc}
 *
 * ══ §272/281 F_MCICommand(RValue&, CInstance*, CInstance*, int, RValue*)  0x1338f0  size 100  25 条（0x1338f0..0x133954）
 * @func 0x1338f0 0x133954  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x104×2 / 0x50×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1338f0 push {r4, r5, r6, lr}
 *   @0x1338f4 sub sp, sp, #264
 *   @0x1338f8 ldr r4, [pc, #0x50]
 *   @0x1338fc add r6, sp, #4
 *   @0x133900 mov r5, r0
 *   @0x133904 mov r2, #256
 *   @0x133908 ldr r4, [pc, r4]
 *   @0x13390c mov r1, #0
 *   @0x133910 mov r0, r6
 *   @0x133914 ldr r3, [r4]
 *   @0x133918 str r3, [sp, #0x104]
 *   @0x13391c bl 0xb65b0 <memset@plt>
 *   @0x133920 mov r3, #1
 *   @0x133924 mov r1, r6
 *   @0x133928 str r3, [r5, #0xc]
 *   @0x13392c mov r0, r5
 *   @0x133930 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x133934 ldr r2, [sp, #0x104]
 *   @0x133938 ldr r3, [r4]
 *   @0x13393c cmp r2, r3
 *   @0x133940 bne 0x13394c <_Z12F_MCICommandR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x133944 add sp, sp, #264
 *   @0x133948 pop {r4, r5, r6, pc}
 *   @0x13394c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x133950 eoreq r10, r11, r8, asr #32
 *
 * ══ §273/281 F_Audio_LoadGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x135768  size 100  25 条（0x135768..0x1357cc）
 * @func 0x135768 0x1357dc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CAudioGroupMan::LoadGroup(int)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x10×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135768 push {r3, r4, r5, lr}
 *   @0x13576c mov r5, r0
 *   @0x135770 ldr r3, [pc, #0x4c]
 *   @0x135774 ldr r3, [pc, r3]
 *   @0x135778 ldrb r4, [r3]
 *   @0x13577c cmp r4, #0
 *   @0x135780 popne {r3, r4, r5, pc}
 *   @0x135784 str r4, [r0, #0xc]
 *   @0x135788 mov r1, r4
 *   @0x13578c ldr r0, [sp, #0x10]
 *   @0x135790 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135794 ldr r3, [pc, #0x2c]
 *   @0x135798 mov r1, r0
 *   @0x13579c ldr r0, [pc, r3]
 *   @0x1357a0 bl 0x21e018 <_ZN14CAudioGroupMan9LoadGroupEi>
 *   @0x1357a4 cmp r0, #0
 *   @0x1357a8 moveq r4, r0
 *   @0x1357ac movne r3, #0
 *   @0x1357b0 moveq r3, r4
 *   @0x1357b4 movtne r3, #0x3ff0
 *   @0x1357b8 str r4, [r5]
 *   @0x1357bc str r3, [r5, #0x4]
 *   @0x1357c0 pop {r3, r4, r5, pc}
 *   @0x1357c4 .word 0x002b98d8
 *   @0x1357c8 .word 0x002b98b4
 *
 * ══ §274/281 F_Audio_UnloadGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x1357cc  size 100  25 条（0x1357cc..0x135830）
 * @func 0x1357cc 0x135840  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CAudioGroupMan::UnloadGroup(int)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x10×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1357cc push {r3, r4, r5, lr}
 *   @0x1357d0 mov r5, r0
 *   @0x1357d4 ldr r3, [pc, #0x4c]
 *   @0x1357d8 ldr r3, [pc, r3]
 *   @0x1357dc ldrb r4, [r3]
 *   @0x1357e0 cmp r4, #0
 *   @0x1357e4 popne {r3, r4, r5, pc}
 *   @0x1357e8 str r4, [r0, #0xc]
 *   @0x1357ec mov r1, r4
 *   @0x1357f0 ldr r0, [sp, #0x10]
 *   @0x1357f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1357f8 ldr r3, [pc, #0x2c]
 *   @0x1357fc mov r1, r0
 *   @0x135800 ldr r0, [pc, r3]
 *   @0x135804 bl 0x21e19c <_ZN14CAudioGroupMan11UnloadGroupEi>
 *   @0x135808 cmp r0, #0
 *   @0x13580c moveq r4, r0
 *   @0x135810 movne r3, #0
 *   @0x135814 moveq r3, r4
 *   @0x135818 movtne r3, #0x3ff0
 *   @0x13581c str r4, [r5]
 *   @0x135820 str r3, [r5, #0x4]
 *   @0x135824 pop {r3, r4, r5, pc}
 *   @0x135828 eoreq r9, r11, r4, ror r8
 *   @0x13582c eoreq r9, r11, r0, asr r8
 *
 * ══ §275/281 F_Audio_GroupIsLoaded(RValue&, CInstance*, CInstance*, int, RValue*)  0x135830  size 100  25 条（0x135830..0x135894）
 * @func 0x135830 0x135894  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CAudioGroupMan::IsGroupLoaded(int)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x10×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135830 push {r3, r4, r5, lr}
 *   @0x135834 mov r5, r0
 *   @0x135838 ldr r3, [pc, #0x4c]
 *   @0x13583c ldr r3, [pc, r3]
 *   @0x135840 ldrb r4, [r3]
 *   @0x135844 cmp r4, #0
 *   @0x135848 popne {r3, r4, r5, pc}
 *   @0x13584c str r4, [r0, #0xc]
 *   @0x135850 mov r1, r4
 *   @0x135854 ldr r0, [sp, #0x10]
 *   @0x135858 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13585c ldr r3, [pc, #0x2c]
 *   @0x135860 mov r1, r0
 *   @0x135864 ldr r0, [pc, r3]
 *   @0x135868 bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi>
 *   @0x13586c cmp r0, #0
 *   @0x135870 moveq r4, r0
 *   @0x135874 movne r3, #0
 *   @0x135878 moveq r3, r4
 *   @0x13587c movtne r3, #0x3ff0
 *   @0x135880 str r4, [r5]
 *   @0x135884 str r3, [r5, #0x4]
 *   @0x135888 pop {r3, r4, r5, pc}
 *   @0x13588c eoreq r9, r11, r0, lsl r8
 *   @0x135890 eoreq r9, r11, r12, ror #15
 *
 * ══ §276/281 F_AudioPlayInSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x135fa8  size 100  25 条（0x135fa8..0x13600c）
 * @func 0x135fa8 0x13600c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Audio_PlayInSyncGroup(int, int)
 * 字段偏移 top8: 0x10×2 / 0x50×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135fa8 push {r3, r4, r5, lr}
 *   @0x135fac mov r4, r0
 *   @0x135fb0 ldr r3, [pc, #0x50]
 *   @0x135fb4 ldr r3, [pc, r3]
 *   @0x135fb8 ldrb r1, [r3]
 *   @0x135fbc cmp r1, #0
 *   @0x135fc0 popne {r3, r4, r5, pc}
 *   @0x135fc4 str r1, [r0, #0xc]
 *   @0x135fc8 ldr r0, [sp, #0x10]
 *   @0x135fcc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135fd0 mov r1, #1
 *   @0x135fd4 mov r5, r0
 *   @0x135fd8 ldr r0, [sp, #0x10]
 *   @0x135fdc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135fe0 mov r1, r0
 *   @0x135fe4 mov r0, r5
 *   @0x135fe8 bl 0x21d434 <_Z21Audio_PlayInSyncGroupii>
 *   @0x135fec vmov s15, r0
 *   @0x135ff0 vcvt.f64.s32 d7, s15
 *   @0x135ff4 vmov r0, r1, d7
 *   @0x135ff8 vmov r2, s14
 *   @0x135ffc mov r3, r1
 *   @0x136000 stm r4, {r2, r3}
 *   @0x136004 pop {r3, r4, r5, pc}
 *   @0x136008 mlaeq r11, r8, r0, r9
 *
 * ══ §277/281 F_IniKeyDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a2bc  size 100  25 条（0x13a2bc..0x13a320）
 * @func 0x13a2bc 0x13a320  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1 / 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a2bc push {r3, r4, r5, lr}
 *   @0x13a2c0 mov r1, #0
 *   @0x13a2c4 ldr r4, [sp, #0x10]
 *   @0x13a2c8 mov r0, r4
 *   @0x13a2cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a2d0 mov r1, #1
 *   @0x13a2d4 mov r5, r0
 *   @0x13a2d8 mov r0, r4
 *   @0x13a2dc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a2e0 ldr r3, [pc, #0x30]
 *   @0x13a2e4 ldr r3, [pc, r3]
 *   @0x13a2e8 mov r2, r0
 *   @0x13a2ec ldr r0, [r3]
 *   @0x13a2f0 cmp r0, #0
 *   @0x13a2f4 beq 0x13a304 <_Z14F_IniKeyDeleteR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x13a2f8 mov r1, r5
 *   @0x13a2fc pop {r3, r4, r5, lr}
 *   @0x13a300 b 0x235b94 <_ZN7IniFile9DeleteKeyEPKcS1_>
 *   @0x13a304 mov r1, r0
 *   @0x13a308 ldr r0, [pc, #0xc]
 *   @0x13a30c pop {r3, r4, r5, lr}
 *   @0x13a310 add r0, pc, r0
 *   @0x13a314 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a318 .word 0x002b4fb0
 *   @0x13a31c eoreq r5, r0, r0, lsl #31
 *
 * ══ §278/281 FINALIZE_Function_File()  0x13cf04  size 100  25 条（0x13cf04..0x13cf68）
 * @func 0x13cf04 0x13cf68  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6850 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x4c×1 / 0x-8×1 / 0x-14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13cf04 push {r3, r4, r5, r6, r7, lr}
 *   @0x13cf08 mov r6, #0
 *   @0x13cf0c ldr r5, [pc, #0x4c]
 *   @0x13cf10 ldr r5, [pc, r5]
 *   @0x13cf14 add r4, r5, #8
 *   @0x13cf18 add r7, r5, #392
 *   @0x13cf1c ldr r0, [r5, #0x8]
 *   @0x13cf20 cmp r0, #0
 *   @0x13cf24 beq 0x13cf30 <_Z22FINALIZE_Function_Filev+0x2c>
 *   @0x13cf28 bl 0xb6850 <fclose@plt>
 *   @0x13cf2c str r6, [r5, #0x8]
 *   @0x13cf30 ldr r0, [r4, #-0x8]
 *   @0x13cf34 add r4, r4, #12
 *   @0x13cf38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13cf3c str r6, [r4, #-0x14]
 *   @0x13cf40 cmp r4, r7
 *   @0x13cf44 add r5, r5, #12
 *   @0x13cf48 mov r3, #0
 *   @0x13cf4c bne 0x13cf1c <_Z22FINALIZE_Function_Filev+0x18>
 *   @0x13cf50 ldr r2, [pc, #0xc]
 *   @0x13cf54 ldr r2, [pc, r2]
 *   @0x13cf58 str r3, [r2]
 *   @0x13cf5c pop {r3, r4, r5, r6, r7, pc}
 *   @0x13cf60 eoreq r2, r11, r0, lsl #7
 *   @0x13cf64 eoreq r0, r11, r4, lsr #29
 *
 * ══ §279/281 json_parse(json_object*)  0x13d0dc  size 100  25 条（0x13d0dc..0x13d140）
 * @func 0x13d0dc 0x13d140  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::DS_AutoMutex() / operator new(unsigned int) / CDS_Map::CDS_Map() / json_parse_to_map(json_object*, CDS_Map*) / FindFreeDsMapIndex() / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d0dc push {r4, r5, r6, lr}
 *   @0x13d0e0 sub sp, sp, #8
 *   @0x13d0e4 add r5, sp, #4
 *   @0x13d0e8 mov r6, r0
 *   @0x13d0ec mov r0, r5
 *   @0x13d0f0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x13d0f4 mov r0, #4
 *   @0x13d0f8 bl 0x27c524 <_Znwj>
 *   @0x13d0fc mov r4, r0
 *   @0x13d100 bl 0x203624 <_ZN7CDS_MapC2Ev>
 *   @0x13d104 mov r1, r4
 *   @0x13d108 mov r0, r6
 *   @0x13d10c bl 0x13cf68 <_Z17json_parse_to_mapP11json_objectP7CDS_Map>
 *   @0x13d110 bl 0x100014 <_Z18FindFreeDsMapIndexv>
 *   @0x13d114 ldr r3, [pc, #0x20]
 *   @0x13d118 ldr r3, [pc, r3]
 *   @0x13d11c ldr r3, [r3, #0x4]
 *   @0x13d120 mov r6, r0
 *   @0x13d124 mov r0, r5
 *   @0x13d128 str r4, [r3, r6, lsl #2]
 *   @0x13d12c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x13d130 mov r0, r6
 *   @0x13d134 add sp, sp, #8
 *   @0x13d138 pop {r4, r5, r6, pc}
 *   @0x13d13c eoreq r0, r11, r4, lsr #16
 *
 * ══ §280/281 CAudioGroupMan::GetLoadProgress(int)  0x21e218  size 80  18 条（0x21e218..0x21e268）
 * @func 0x21e218 0x21e260  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::GetGroup(int) / CAudioGroup::GetLoadProgress()
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e218 cmp r1, #0
 *   @0x21e21c push {r3, lr}
 *   @0x21e220 bne 0x21e230 <_ZN14CAudioGroupMan15GetLoadProgressEi+0x18>
 *   @0x21e224 vldr d7, [pc, #44]
 *   @0x21e228 vmov r0, r1, d7
 *   @0x21e22c pop {r3, pc}
 *   @0x21e230 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x21e234 cmp r0, #0
 *   @0x21e238 beq 0x21e250 <_ZN14CAudioGroupMan15GetLoadProgressEi+0x38>
 *   @0x21e23c bl 0x21dd9c <_ZN11CAudioGroup15GetLoadProgressEv>
 *   @0x21e240 vmov s13, r0
 *   @0x21e244 vcvt.f64.s32 d7, s13
 *   @0x21e248 vmov r0, r1, d7
 *   @0x21e24c pop {r3, pc}
 *   @0x21e250 vldr d7, [pc, #8]
 *   @0x21e254 b 0x21e228 <_ZN14CAudioGroupMan15GetLoadProgressEi+0x10>
 *   @0x21e258 andeq r0, r0, r0
 *   @0x21e25c subsmi r0, r9, r0
 *
 * ══ §281/281 InitialiseHandledContainer()  0xd3edc  size 4  1 条（0xd3edc..0xd3ee0）
 * @func 0xd3edc 0xd3ee0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3edc bx lr
 */
