/* cally 逆向卡：All_65 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 438 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/438 GV_Bbt(CInstance*, int, RValue*)  0x1fa990  size 76  19 条（0x1fa990..0x1fa9dc）
 * @func 0x1fa990 0x1fa9dc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x64×1 / 0xc×1 / 0xec×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa990 ldrb r3, [r0, #0x64]
 *   @0x1fa994 push {r4, r5, r6, lr}
 *   @0x1fa998 mov r6, r2
 *   @0x1fa99c mov r2, #0
 *   @0x1fa9a0 cmp r3, r2
 *   @0x1fa9a4 mov r4, r0
 *   @0x1fa9a8 str r2, [r6, #0xc]
 *   @0x1fa9ac beq 0x1fa9b8 <_Z6GV_BbtP9CInstanceiP6RValue+0x28>
 *   @0x1fa9b0 mov r1, #1
 *   @0x1fa9b4 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x1fa9b8 ldr r4, [r4, #0xec]
 *   @0x1fa9bc mov r0, #1
 *   @0x1fa9c0 vmov s15, r4
 *   @0x1fa9c4 vcvt.f64.s32 d7, s15
 *   @0x1fa9c8 vmov r4, r5, d7
 *   @0x1fa9cc vmov r2, s14
 *   @0x1fa9d0 mov r3, r5
 *   @0x1fa9d4 stm r6, {r2, r3}
 *   @0x1fa9d8 pop {r4, r5, r6, pc}
 *
 * ══ §2/438 SV_MouseLastButton(CInstance*, int, RValue*)  0x1fb3b8  size 76  19 条（0x1fb3b8..0x1fb404）
 * @func 0x1fb3b8 0x1fb404  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / IO_Button_Last_Set(int, int) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb3b8 push {r3, lr}
 *   @0x1fb3bc ldr r3, [r2, #0xc]
 *   @0x1fb3c0 bic r3, r3, #-16777216
 *   @0x1fb3c4 cmp r3, #0
 *   @0x1fb3c8 bne 0x1fb3f0 <_Z18SV_MouseLastButtonP9CInstanceiP6RValue+0x38>
 *   @0x1fb3cc ldr r12, [r2]
 *   @0x1fb3d0 ldr r3, [r2, #0x4]
 *   @0x1fb3d4 mov r1, r3
 *   @0x1fb3d8 mov r0, r12
 *   @0x1fb3dc bl 0xb66e8 <lrint@plt>
 *   @0x1fb3e0 mov r1, #0
 *   @0x1fb3e4 bl 0x18c06c <_Z18IO_Button_Last_Setii>
 *   @0x1fb3e8 mov r0, #1
 *   @0x1fb3ec pop {r3, pc}
 *   @0x1fb3f0 mov r0, r2
 *   @0x1fb3f4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb3f8 mov r12, r0
 *   @0x1fb3fc mov r3, r1
 *   @0x1fb400 b 0x1fb3d4 <_Z18SV_MouseLastButtonP9CInstanceiP6RValue+0x1c>
 *
 * ══ §3/438 SV_MouseButton(CInstance*, int, RValue*)  0x1fb404  size 76  19 条（0x1fb404..0x1fb450）
 * @func 0x1fb404 0x1fb450  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / IO_Button_Current_Set(int, int) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb404 push {r3, lr}
 *   @0x1fb408 ldr r3, [r2, #0xc]
 *   @0x1fb40c bic r3, r3, #-16777216
 *   @0x1fb410 cmp r3, #0
 *   @0x1fb414 bne 0x1fb43c <_Z14SV_MouseButtonP9CInstanceiP6RValue+0x38>
 *   @0x1fb418 ldr r12, [r2]
 *   @0x1fb41c ldr r3, [r2, #0x4]
 *   @0x1fb420 mov r1, r3
 *   @0x1fb424 mov r0, r12
 *   @0x1fb428 bl 0xb66e8 <lrint@plt>
 *   @0x1fb42c mov r1, #0
 *   @0x1fb430 bl 0x18c090 <_Z21IO_Button_Current_Setii>
 *   @0x1fb434 mov r0, #1
 *   @0x1fb438 pop {r3, pc}
 *   @0x1fb43c mov r0, r2
 *   @0x1fb440 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb444 mov r12, r0
 *   @0x1fb448 mov r3, r1
 *   @0x1fb44c b 0x1fb420 <_Z14SV_MouseButtonP9CInstanceiP6RValue+0x1c>
 *
 * ══ §4/438 SV_HSpeed(CInstance*, int, RValue*)  0x1fb698  size 76  19 条（0x1fb698..0x1fb6e4）
 * @func 0x1fb698 0x1fb6e4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetHspeed(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb698 ldr r3, [r2, #0xc]
 *   @0x1fb69c push {r4, r5, r6, lr}
 *   @0x1fb6a0 bic r3, r3, #-16777216
 *   @0x1fb6a4 cmp r3, #0
 *   @0x1fb6a8 mov r6, r0
 *   @0x1fb6ac bne 0x1fb6d0 <_Z9SV_HSpeedP9CInstanceiP6RValue+0x38>
 *   @0x1fb6b0 ldm r2, {r4, r5}
 *   @0x1fb6b4 vmov d7, r4, r5
 *   @0x1fb6b8 mov r0, r6
 *   @0x1fb6bc vcvt.f32.f64 s15, d7
 *   @0x1fb6c0 vmov r1, s15
 *   @0x1fb6c4 bl 0x1930f4 <_ZN9CInstance9SetHspeedEf>
 *   @0x1fb6c8 mov r0, #1
 *   @0x1fb6cc pop {r4, r5, r6, pc}
 *   @0x1fb6d0 mov r0, r2
 *   @0x1fb6d4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb6d8 mov r4, r0
 *   @0x1fb6dc mov r5, r1
 *   @0x1fb6e0 b 0x1fb6b4 <_Z9SV_HSpeedP9CInstanceiP6RValue+0x1c>
 *
 * ══ §5/438 SV_VSpeed(CInstance*, int, RValue*)  0x1fb6e4  size 76  19 条（0x1fb6e4..0x1fb730）
 * @func 0x1fb6e4 0x1fb730  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetVspeed(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb6e4 ldr r3, [r2, #0xc]
 *   @0x1fb6e8 push {r4, r5, r6, lr}
 *   @0x1fb6ec bic r3, r3, #-16777216
 *   @0x1fb6f0 cmp r3, #0
 *   @0x1fb6f4 mov r6, r0
 *   @0x1fb6f8 bne 0x1fb71c <_Z9SV_VSpeedP9CInstanceiP6RValue+0x38>
 *   @0x1fb6fc ldm r2, {r4, r5}
 *   @0x1fb700 vmov d7, r4, r5
 *   @0x1fb704 mov r0, r6
 *   @0x1fb708 vcvt.f32.f64 s15, d7
 *   @0x1fb70c vmov r1, s15
 *   @0x1fb710 bl 0x193114 <_ZN9CInstance9SetVspeedEf>
 *   @0x1fb714 mov r0, #1
 *   @0x1fb718 pop {r4, r5, r6, pc}
 *   @0x1fb71c mov r0, r2
 *   @0x1fb720 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb724 mov r4, r0
 *   @0x1fb728 mov r5, r1
 *   @0x1fb72c b 0x1fb700 <_Z9SV_VSpeedP9CInstanceiP6RValue+0x1c>
 *
 * ══ §6/438 SV_Direction(CInstance*, int, RValue*)  0x1fb730  size 76  19 条（0x1fb730..0x1fb77c）
 * @func 0x1fb730 0x1fb77c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetDirection(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb730 ldr r3, [r2, #0xc]
 *   @0x1fb734 push {r4, r5, r6, lr}
 *   @0x1fb738 bic r3, r3, #-16777216
 *   @0x1fb73c cmp r3, #0
 *   @0x1fb740 mov r6, r0
 *   @0x1fb744 bne 0x1fb768 <_Z12SV_DirectionP9CInstanceiP6RValue+0x38>
 *   @0x1fb748 ldm r2, {r4, r5}
 *   @0x1fb74c vmov d7, r4, r5
 *   @0x1fb750 mov r0, r6
 *   @0x1fb754 vcvt.f32.f64 s15, d7
 *   @0x1fb758 vmov r1, s15
 *   @0x1fb75c bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x1fb760 mov r0, #1
 *   @0x1fb764 pop {r4, r5, r6, pc}
 *   @0x1fb768 mov r0, r2
 *   @0x1fb76c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb770 mov r4, r0
 *   @0x1fb774 mov r5, r1
 *   @0x1fb778 b 0x1fb74c <_Z12SV_DirectionP9CInstanceiP6RValue+0x1c>
 *
 * ══ §7/438 SV_Speed(CInstance*, int, RValue*)  0x1fb77c  size 76  19 条（0x1fb77c..0x1fb7c8）
 * @func 0x1fb77c 0x1fb7c8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetSpeed(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb77c ldr r3, [r2, #0xc]
 *   @0x1fb780 push {r4, r5, r6, lr}
 *   @0x1fb784 bic r3, r3, #-16777216
 *   @0x1fb788 cmp r3, #0
 *   @0x1fb78c mov r6, r0
 *   @0x1fb790 bne 0x1fb7b4 <_Z8SV_SpeedP9CInstanceiP6RValue+0x38>
 *   @0x1fb794 ldm r2, {r4, r5}
 *   @0x1fb798 vmov d7, r4, r5
 *   @0x1fb79c mov r0, r6
 *   @0x1fb7a0 vcvt.f32.f64 s15, d7
 *   @0x1fb7a4 vmov r1, s15
 *   @0x1fb7a8 bl 0x1930d4 <_ZN9CInstance8SetSpeedEf>
 *   @0x1fb7ac mov r0, #1
 *   @0x1fb7b0 pop {r4, r5, r6, pc}
 *   @0x1fb7b4 mov r0, r2
 *   @0x1fb7b8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb7bc mov r4, r0
 *   @0x1fb7c0 mov r5, r1
 *   @0x1fb7c4 b 0x1fb798 <_Z8SV_SpeedP9CInstanceiP6RValue+0x1c>
 *
 * ══ §8/438 SV_ImageXScale(CInstance*, int, RValue*)  0x1fb828  size 76  19 条（0x1fb828..0x1fb874）
 * @func 0x1fb828 0x1fb874  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetImageScaleX(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb828 ldr r3, [r2, #0xc]
 *   @0x1fb82c push {r4, r5, r6, lr}
 *   @0x1fb830 bic r3, r3, #-16777216
 *   @0x1fb834 cmp r3, #0
 *   @0x1fb838 mov r6, r0
 *   @0x1fb83c bne 0x1fb860 <_Z14SV_ImageXScaleP9CInstanceiP6RValue+0x38>
 *   @0x1fb840 ldm r2, {r4, r5}
 *   @0x1fb844 vmov d7, r4, r5
 *   @0x1fb848 mov r0, r6
 *   @0x1fb84c vcvt.f32.f64 s15, d7
 *   @0x1fb850 vmov r1, s15
 *   @0x1fb854 bl 0x192fec <_ZN9CInstance14SetImageScaleXEf>
 *   @0x1fb858 mov r0, #1
 *   @0x1fb85c pop {r4, r5, r6, pc}
 *   @0x1fb860 mov r0, r2
 *   @0x1fb864 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb868 mov r4, r0
 *   @0x1fb86c mov r5, r1
 *   @0x1fb870 b 0x1fb844 <_Z14SV_ImageXScaleP9CInstanceiP6RValue+0x1c>
 *
 * ══ §9/438 SV_ImageYScale(CInstance*, int, RValue*)  0x1fb874  size 76  19 条（0x1fb874..0x1fb8c0）
 * @func 0x1fb874 0x1fb8c0  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetImageScaleY(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb874 ldr r3, [r2, #0xc]
 *   @0x1fb878 push {r4, r5, r6, lr}
 *   @0x1fb87c bic r3, r3, #-16777216
 *   @0x1fb880 cmp r3, #0
 *   @0x1fb884 mov r6, r0
 *   @0x1fb888 bne 0x1fb8ac <_Z14SV_ImageYScaleP9CInstanceiP6RValue+0x38>
 *   @0x1fb88c ldm r2, {r4, r5}
 *   @0x1fb890 vmov d7, r4, r5
 *   @0x1fb894 mov r0, r6
 *   @0x1fb898 vcvt.f32.f64 s15, d7
 *   @0x1fb89c vmov r1, s15
 *   @0x1fb8a0 bl 0x193014 <_ZN9CInstance14SetImageScaleYEf>
 *   @0x1fb8a4 mov r0, #1
 *   @0x1fb8a8 pop {r4, r5, r6, pc}
 *   @0x1fb8ac mov r0, r2
 *   @0x1fb8b0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb8b4 mov r4, r0
 *   @0x1fb8b8 mov r5, r1
 *   @0x1fb8bc b 0x1fb890 <_Z14SV_ImageYScaleP9CInstanceiP6RValue+0x1c>
 *
 * ══ §10/438 SV_PathPosition(CInstance*, int, RValue*)  0x1fb98c  size 76  19 条（0x1fb98c..0x1fb9d8）
 * @func 0x1fb98c 0x1fb9d8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetPathPosition(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb98c ldr r3, [r2, #0xc]
 *   @0x1fb990 push {r4, r5, r6, lr}
 *   @0x1fb994 bic r3, r3, #-16777216
 *   @0x1fb998 cmp r3, #0
 *   @0x1fb99c mov r6, r0
 *   @0x1fb9a0 bne 0x1fb9c4 <_Z15SV_PathPositionP9CInstanceiP6RValue+0x38>
 *   @0x1fb9a4 ldm r2, {r4, r5}
 *   @0x1fb9a8 vmov d7, r4, r5
 *   @0x1fb9ac mov r0, r6
 *   @0x1fb9b0 vcvt.f32.f64 s15, d7
 *   @0x1fb9b4 vmov r1, s15
 *   @0x1fb9b8 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1fb9bc mov r0, #1
 *   @0x1fb9c0 pop {r4, r5, r6, pc}
 *   @0x1fb9c4 mov r0, r2
 *   @0x1fb9c8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb9cc mov r4, r0
 *   @0x1fb9d0 mov r5, r1
 *   @0x1fb9d4 b 0x1fb9a8 <_Z15SV_PathPositionP9CInstanceiP6RValue+0x1c>
 *
 * ══ §11/438 SV_PathPositionPrevious(CInstance*, int, RValue*)  0x1fb9d8  size 76  19 条（0x1fb9d8..0x1fba24）
 * @func 0x1fb9d8 0x1fba24  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetPathPositionPrevious(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb9d8 ldr r3, [r2, #0xc]
 *   @0x1fb9dc push {r4, r5, r6, lr}
 *   @0x1fb9e0 bic r3, r3, #-16777216
 *   @0x1fb9e4 cmp r3, #0
 *   @0x1fb9e8 mov r6, r0
 *   @0x1fb9ec bne 0x1fba10 <_Z23SV_PathPositionPreviousP9CInstanceiP6RValue+0x38>
 *   @0x1fb9f0 ldm r2, {r4, r5}
 *   @0x1fb9f4 vmov d7, r4, r5
 *   @0x1fb9f8 mov r0, r6
 *   @0x1fb9fc vcvt.f32.f64 s15, d7
 *   @0x1fba00 vmov r1, s15
 *   @0x1fba04 bl 0x1935fc <_ZN9CInstance23SetPathPositionPreviousEf>
 *   @0x1fba08 mov r0, #1
 *   @0x1fba0c pop {r4, r5, r6, pc}
 *   @0x1fba10 mov r0, r2
 *   @0x1fba14 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fba18 mov r4, r0
 *   @0x1fba1c mov r5, r1
 *   @0x1fba20 b 0x1fb9f4 <_Z23SV_PathPositionPreviousP9CInstanceiP6RValue+0x1c>
 *
 * ══ §12/438 SV_PathSpeed(CInstance*, int, RValue*)  0x1fba24  size 76  19 条（0x1fba24..0x1fba70）
 * @func 0x1fba24 0x1fba70  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetPathSpeed(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fba24 ldr r3, [r2, #0xc]
 *   @0x1fba28 push {r4, r5, r6, lr}
 *   @0x1fba2c bic r3, r3, #-16777216
 *   @0x1fba30 cmp r3, #0
 *   @0x1fba34 mov r6, r0
 *   @0x1fba38 bne 0x1fba5c <_Z12SV_PathSpeedP9CInstanceiP6RValue+0x38>
 *   @0x1fba3c ldm r2, {r4, r5}
 *   @0x1fba40 vmov d7, r4, r5
 *   @0x1fba44 mov r0, r6
 *   @0x1fba48 vcvt.f32.f64 s15, d7
 *   @0x1fba4c vmov r1, s15
 *   @0x1fba50 bl 0x193634 <_ZN9CInstance12SetPathSpeedEf>
 *   @0x1fba54 mov r0, #1
 *   @0x1fba58 pop {r4, r5, r6, pc}
 *   @0x1fba5c mov r0, r2
 *   @0x1fba60 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fba64 mov r4, r0
 *   @0x1fba68 mov r5, r1
 *   @0x1fba6c b 0x1fba40 <_Z12SV_PathSpeedP9CInstanceiP6RValue+0x1c>
 *
 * ══ §13/438 CStream::ReadStream()  0x2019c4  size 76  19 条（0x2019c4..0x201a10）
 * @func 0x2019c4 0x201a10  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CStream::CStream(int) / CStream::ReadInteger() / CStream::CopyFrom(CStream*, long long) / CStream::SetPosition(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2019c4 push {r3, r4, r5, lr}
 *   @0x2019c8 mov r5, r0
 *   @0x2019cc mov r0, #32
 *   @0x2019d0 bl 0x27c524 <_Znwj>
 *   @0x2019d4 mov r1, #0
 *   @0x2019d8 mov r4, r0
 *   @0x2019dc bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x2019e0 mov r0, r5
 *   @0x2019e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x2019e8 mov r1, r5
 *   @0x2019ec mov r2, r0
 *   @0x2019f0 asr r3, r0, #31
 *   @0x2019f4 mov r0, r4
 *   @0x2019f8 bl 0x20170c <_ZN7CStream8CopyFromEPS_x>
 *   @0x2019fc mov r0, r4
 *   @0x201a00 mov r1, #0
 *   @0x201a04 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x201a08 mov r0, r4
 *   @0x201a0c pop {r3, r4, r5, pc}
 *
 * ══ §14/438 CStream::ReadBitmap()  0x201e9c  size 76  19 条（0x201e9c..0x201ee8）
 * @func 0x201e9c 0x201ee8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadBoolean() / IBitmap::Create() / CStream::ReadCompressedStream() / CStream::Free()
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201e9c push {r3, r4, r5, lr}
 *   @0x201ea0 mov r5, r0
 *   @0x201ea4 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x201ea8 cmp r0, #0
 *   @0x201eac popeq {r3, r4, r5, pc}
 *   @0x201eb0 bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0x201eb4 mov r4, r0
 *   @0x201eb8 mov r0, r5
 *   @0x201ebc bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv>
 *   @0x201ec0 ldr r3, [r4]
 *   @0x201ec4 ldr r3, [r3, #0x8]
 *   @0x201ec8 mov r5, r0
 *   @0x201ecc mov r0, r4
 *   @0x201ed0 mov r1, r5
 *   @0x201ed4 blx r3
 *   @0x201ed8 mov r0, r5
 *   @0x201edc bl 0x20133c <_ZN7CStream4FreeEv>
 *   @0x201ee0 mov r0, r4
 *   @0x201ee4 pop {r3, r4, r5, pc}
 *
 * ══ §15/438 Audio_PauseMusic()  0x218bfc  size 76  19 条（0x218bfc..0x218c48）
 * @func 0x218bfc 0x218c48  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x28×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218bfc ldr r3, [pc, #0x38]
 *   @0x218c00 ldr r3, [pc, r3]
 *   @0x218c04 ldrb r3, [r3]
 *   @0x218c08 cmp r3, #0
 *   @0x218c0c bxne lr
 *   @0x218c10 ldr r3, [pc, #0x28]
 *   @0x218c14 ldr r3, [pc, r3]
 *   @0x218c18 ldrb r3, [r3]
 *   @0x218c1c cmp r3, #0
 *   @0x218c20 bxne lr
 *   @0x218c24 ldr r3, [pc, #0x18]
 *   @0x218c28 ldr r3, [pc, r3]
 *   @0x218c2c ldr r0, [r3]
 *   @0x218c30 cmp r0, #0
 *   @0x218c34 bxeq lr
 *   @0x218c38 b 0x2208e8 <_ZN13SoundHardware10PauseMusicEv>
 *   @0x218c3c andseq r6, sp, r12, asr #8
 *   @0x218c40 andseq r6, sp, r12, lsl r1
 *   @0x218c44 ldrheq r8, [sp], -r8
 *
 * ══ §16/438 Audio_ResumeMusic()  0x218c48  size 76  19 条（0x218c48..0x218c94）
 * @func 0x218c48 0x218c94  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x28×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218c48 ldr r3, [pc, #0x38]
 *   @0x218c4c ldr r3, [pc, r3]
 *   @0x218c50 ldrb r3, [r3]
 *   @0x218c54 cmp r3, #0
 *   @0x218c58 bxne lr
 *   @0x218c5c ldr r3, [pc, #0x28]
 *   @0x218c60 ldr r3, [pc, r3]
 *   @0x218c64 ldrb r3, [r3]
 *   @0x218c68 cmp r3, #0
 *   @0x218c6c bxne lr
 *   @0x218c70 ldr r3, [pc, #0x18]
 *   @0x218c74 ldr r3, [pc, r3]
 *   @0x218c78 ldr r0, [r3]
 *   @0x218c7c cmp r0, #0
 *   @0x218c80 bxeq lr
 *   @0x218c84 b 0x22091c <_ZN13SoundHardware11ResumeMusicEv>
 *   @0x218c88 andseq r6, sp, r0, lsl #8
 *   @0x218c8c ldrsbeq r6, [sp], -r0
 *   @0x218c90 andseq r8, sp, r12, ror #14
 *
 * ══ §17/438 Audio_SyncGroupIsPlaying(int)  0x21d640  size 76  19 条（0x21d640..0x21d68c）
 * @func 0x21d640 0x21d68c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d640 ldr r3, [pc, #0x38]
 *   @0x21d644 ldr r3, [pc, r3]
 *   @0x21d648 ldrb r3, [r3]
 *   @0x21d64c cmp r3, #0
 *   @0x21d650 bne 0x21d668 <_Z24Audio_SyncGroupIsPlayingi+0x28>
 *   @0x21d654 ldr r3, [pc, #0x28]
 *   @0x21d658 ldr r3, [pc, r3]
 *   @0x21d65c ldrb r3, [r3]
 *   @0x21d660 cmp r3, #0
 *   @0x21d664 bne 0x21d670 <_Z24Audio_SyncGroupIsPlayingi+0x30>
 *   @0x21d668 mov r0, #0
 *   @0x21d66c bx lr
 *   @0x21d670 mov r1, r0
 *   @0x21d674 ldr r0, [pc, #0xc]
 *   @0x21d678 add r0, pc, r0
 *   @0x21d67c b 0x226254 <_ZN9COggAudio18IsSyncGroupPlayingEi>
 *   @0x21d680 andseq r1, sp, r8, lsl #20
 *   @0x21d684 ldrsbeq r1, [sp], -r8
 *   @0x21d688 subseq r7, r3, r12, lsl r12
 *
 * ══ §18/438 CNoise::CNoise()  0x21dad8  size 76  19 条（0x21dad8..0x21db24）
 * @func 0x21dad8 0x21db24  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x2c×1 / 0x10×1 / 0x30×1 / 0x1c×1 / 0x34×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21dad8 push {r4, lr}
 *   @0x21dadc mov r1, #0
 *   @0x21dae0 mov r2, #60
 *   @0x21dae4 mov r4, r0
 *   @0x21dae8 bl 0xb65b0 <memset@plt>
 *   @0x21daec ldr r3, [pc, #0x2c]
 *   @0x21daf0 mov r2, #1065353216
 *   @0x21daf4 mvn r1, #0
 *   @0x21daf8 ldr r3, [pc, r3]
 *   @0x21dafc mov r0, r4
 *   @0x21db00 str r1, [r4, #0x10]
 *   @0x21db04 ldr r3, [r3]
 *   @0x21db08 str r1, [r4, #0x30]
 *   @0x21db0c str r2, [r4, #0x1c]
 *   @0x21db10 str r3, [r4, #0x34]
 *   @0x21db14 str r2, [r4, #0x24]
 *   @0x21db18 str r2, [r4, #0x20]
 *   @0x21db1c pop {r4, pc}
 *   @0x21db20 ldrsbeq r3, [sp], -r0
 *
 * ══ §19/438 _alutInputStreamDestroy  0x221dcc  size 76  19 条（0x221dcc..0x221e18）
 * @func 0x221dcc 0x221e18  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2 / 0xb6850
 * 字段偏移 top8: 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221dcc push {r3, r4, r5, lr}
 *   @0x221dd0 mov r4, r0
 *   @0x221dd4 ldrb r3, [r0]
 *   @0x221dd8 cmp r3, #0
 *   @0x221ddc moveq r5, #1
 *   @0x221de0 bne 0x221e04 <_alutInputStreamDestroy+0x38>
 *   @0x221de4 ldr r0, [r4, #0x4]
 *   @0x221de8 cmp r0, #0
 *   @0x221dec beq 0x221df4 <_alutInputStreamDestroy+0x28>
 *   @0x221df0 bl 0xb655c <free@plt>
 *   @0x221df4 mov r0, r4
 *   @0x221df8 bl 0xb655c <free@plt>
 *   @0x221dfc mov r0, r5
 *   @0x221e00 pop {r3, r4, r5, pc}
 *   @0x221e04 ldr r0, [r0, #0xc]
 *   @0x221e08 bl 0xb6850 <fclose@plt>
 *   @0x221e0c rsbs r5, r0, #1
 *   @0x221e10 movlo r5, #0
 *   @0x221e14 b 0x221de4 <_alutInputStreamDestroy+0x18>
 *
 * ══ §20/438 OpenAL_MP3_SetVolume(float)  0x223254  size 76  19 条（0x223254..0x2232a0）
 * @func 0x223254 0x2232a0  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x24×2 / 0x-4×1 / 0x4×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223254 str lr, [sp, #-0x4]!
 *   @0x223258 vpush {d8}
 *   @0x22325c vmov s16, r0
 *   @0x223260 sub sp, sp, #12
 *   @0x223264 bl 0x290274 <getJNIEnv>
 *   @0x223268 vcvt.f64.f32 d7, s16
 *   @0x22326c ldr r2, [pc, #0x24]
 *   @0x223270 ldr r3, [pc, #0x24]
 *   @0x223274 ldr r2, [pc, r2]
 *   @0x223278 ldr r3, [pc, r3]
 *   @0x22327c ldr r1, [r2]
 *   @0x223280 ldr r2, [r3]
 *   @0x223284 vstr d7, [sp]
 *   @0x223288 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x22328c add sp, sp, #12
 *   @0x223290 vpop {d8}
 *   @0x223294 ldr pc, [sp], #4
 *   @0x223298 andseq r10, r12, r0, lsr r7
 *   @0x22329c ldrsheq lr, [r12], -r4
 *
 * ══ §21/438 COggThread::Suspend()  0x223844  size 76  19 条（0x223844..0x223890）
 * @func 0x223844 0x223890  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x802×1 / 0x831×1 / 0x20×1 / 0x80c×1 / 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223844 push {r3, lr}
 *   @0x223848 ldrb r3, [r0, #0x802]
 *   @0x22384c cmp r3, #0
 *   @0x223850 popeq {r3, pc}
 *   @0x223854 ldrb r3, [r0, #0x831]
 *   @0x223858 cmp r3, #0
 *   @0x22385c beq 0x223854 <_ZN10COggThread7SuspendEv+0x10>
 *   @0x223860 ldr r3, [pc, #0x20]
 *   @0x223864 ldr r2, [r0, #0x80c]
 *   @0x223868 ldr r3, [pc, r3]
 *   @0x22386c ldr r1, [pc, #0x18]
 *   @0x223870 ldr r0, [r3]
 *   @0x223874 add r1, pc, r1
 *   @0x223878 ldr r3, [r0]
 *   @0x22387c ldr r3, [r3, #0xc]
 *   @0x223880 blx r3
 *   @0x223884 pop {r3, pc}
 *   @0x223888 andseq r9, r12, r12, lsr #29
 *   @0x22388c ldrheq r1, [r3], -r4
 *
 * ══ §22/438 COggSyncThread::Suspend()  0x2248f4  size 76  19 条（0x2248f4..0x224940）
 * @func 0x2248f4 0x224940  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x803×1 / 0x84d×1 / 0x20×1 / 0x810×1 / 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2248f4 push {r3, lr}
 *   @0x2248f8 ldrb r3, [r0, #0x803]
 *   @0x2248fc cmp r3, #0
 *   @0x224900 popeq {r3, pc}
 *   @0x224904 ldrb r3, [r0, #0x84d]
 *   @0x224908 cmp r3, #0
 *   @0x22490c beq 0x224904 <_ZN14COggSyncThread7SuspendEv+0x10>
 *   @0x224910 ldr r3, [pc, #0x20]
 *   @0x224914 ldr r2, [r0, #0x810]
 *   @0x224918 ldr r3, [pc, r3]
 *   @0x22491c ldr r1, [pc, #0x18]
 *   @0x224920 ldr r0, [r3]
 *   @0x224924 add r1, pc, r1
 *   @0x224928 ldr r3, [r0]
 *   @0x22492c ldr r3, [r3, #0xc]
 *   @0x224930 blx r3
 *   @0x224934 pop {r3, pc}
 *   @0x224938 ldrsheq r8, [r12], -r12
 *   @0x22493c andseq r0, r3, r4, lsl #8
 *
 * ══ §23/438 IniFile::GetKey(char const*, char const*)  0x235ad0  size 76  19 条（0x235ad0..0x235b1c）
 * @func 0x235ad0 0x235b1c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetSection(char const*) / 0xb6574
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235ad0 push {r3, r4, r5, lr}
 *   @0x235ad4 mov r5, r2
 *   @0x235ad8 bl 0x235a90 <_ZN7IniFile10GetSectionEPKc>
 *   @0x235adc cmp r0, #0
 *   @0x235ae0 popeq {r3, r4, r5, pc}
 *   @0x235ae4 ldr r4, [r0, #0x4]
 *   @0x235ae8 cmp r4, #0
 *   @0x235aec bne 0x235b00 <_ZN7IniFile6GetKeyEPKcS1_+0x30>
 *   @0x235af0 b 0x235b14 <_ZN7IniFile6GetKeyEPKcS1_+0x44>
 *   @0x235af4 ldr r4, [r4]
 *   @0x235af8 cmp r4, #0
 *   @0x235afc beq 0x235b14 <_ZN7IniFile6GetKeyEPKcS1_+0x44>
 *   @0x235b00 mov r0, r5
 *   @0x235b04 ldr r1, [r4, #0x4]
 *   @0x235b08 bl 0xb6574 <strcmp@plt>
 *   @0x235b0c cmp r0, #0
 *   @0x235b10 bne 0x235af4 <_ZN7IniFile6GetKeyEPKcS1_+0x24>
 *   @0x235b14 mov r0, r4
 *   @0x235b18 pop {r3, r4, r5, pc}
 *
 * ══ §24/438 CPhysicsObject::SetFriction(int, float)  0x2379cc  size 76  19 条（0x2379cc..0x237a18）
 * @func 0x2379cc 0x237a18  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2379cc ldr r3, [r0, #0x1c]
 *   @0x2379d0 ldr r0, [r3, #0x4]
 *   @0x2379d4 ldr r3, [r3]
 *   @0x2379d8 and r0, r1, r0
 *   @0x2379dc ldr r3, [r3, r0, lsl #3]
 *   @0x2379e0 cmp r3, #0
 *   @0x2379e4 bne 0x2379f8 <_ZN14CPhysicsObject11SetFrictionEif+0x2c>
 *   @0x2379e8 bx lr
 *   @0x2379ec ldr r3, [r3, #0x4]
 *   @0x2379f0 cmp r3, #0
 *   @0x2379f4 beq 0x237a14 <_ZN14CPhysicsObject11SetFrictionEif+0x48>
 *   @0x2379f8 ldr r0, [r3, #0x8]
 *   @0x2379fc cmp r1, r0
 *   @0x237a00 bne 0x2379ec <_ZN14CPhysicsObject11SetFrictionEif+0x20>
 *   @0x237a04 ldr r3, [r3, #0xc]
 *   @0x237a08 cmp r3, #0
 *   @0x237a0c strne r2, [r3, #0x10]
 *   @0x237a10 bx lr
 *   @0x237a14 bx lr
 *
 * ══ §25/438 CPhysicsObject::SetRestitution(int, float)  0x237a68  size 76  19 条（0x237a68..0x237ab4）
 * @func 0x237a68 0x237ab4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237a68 ldr r3, [r0, #0x1c]
 *   @0x237a6c ldr r0, [r3, #0x4]
 *   @0x237a70 ldr r3, [r3]
 *   @0x237a74 and r0, r1, r0
 *   @0x237a78 ldr r3, [r3, r0, lsl #3]
 *   @0x237a7c cmp r3, #0
 *   @0x237a80 bne 0x237a94 <_ZN14CPhysicsObject14SetRestitutionEif+0x2c>
 *   @0x237a84 bx lr
 *   @0x237a88 ldr r3, [r3, #0x4]
 *   @0x237a8c cmp r3, #0
 *   @0x237a90 beq 0x237ab0 <_ZN14CPhysicsObject14SetRestitutionEif+0x48>
 *   @0x237a94 ldr r0, [r3, #0x8]
 *   @0x237a98 cmp r1, r0
 *   @0x237a9c bne 0x237a88 <_ZN14CPhysicsObject14SetRestitutionEif+0x20>
 *   @0x237aa0 ldr r3, [r3, #0xc]
 *   @0x237aa4 cmp r3, #0
 *   @0x237aa8 strne r2, [r3, #0x14]
 *   @0x237aac bx lr
 *   @0x237ab0 bx lr
 *
 * ══ §26/438 CPhysicsWorld::JoinParticleGroups(int, int)  0x239de8  size 76  19 条（0x239de8..0x239e34）
 * @func 0x239de8 0x239e34  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int)×2 / b2World::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*)
 * 字段偏移 top8: 0x10×1 / 0x48×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239de8 push {r4, r5, r6, lr}
 *   @0x239dec mov r5, r2
 *   @0x239df0 mov r4, r0
 *   @0x239df4 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x239df8 mov r1, r5
 *   @0x239dfc mov r6, r0
 *   @0x239e00 mov r0, r4
 *   @0x239e04 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x239e08 cmp r0, #0
 *   @0x239e0c cmpne r6, #0
 *   @0x239e10 popeq {r4, r5, r6, pc}
 *   @0x239e14 mov r2, r0
 *   @0x239e18 mov r1, r6
 *   @0x239e1c ldr r0, [r4, #0x10]
 *   @0x239e20 bl 0x2cb528 <_ZN7b2World18JoinParticleGroupsEP15b2ParticleGroupS1_>
 *   @0x239e24 ldr r3, [r4, #0x48]
 *   @0x239e28 mov r2, #0
 *   @0x239e2c str r2, [r3, r5, lsl #2]
 *   @0x239e30 pop {r4, r5, r6, pc}
 *
 * ══ §27/438 CPhysicsWorld::GetParticleGroupCentreX(int)  0x23a688  size 76  19 条（0x23a688..0x23a6d4）
 * @func 0x23a688 0x23a6d4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetCenter() const
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a688 push {r4, lr}
 *   @0x23a68c sub sp, sp, #8
 *   @0x23a690 mov r4, r0
 *   @0x23a694 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a698 subs r1, r0, #0
 *   @0x23a69c beq 0x23a6c0 <_ZN13CPhysicsWorld23GetParticleGroupCentreXEi+0x38>
 *   @0x23a6a0 mov r0, sp
 *   @0x23a6a4 bl 0x2d483c <_ZNK15b2ParticleGroup9GetCenterEv>
 *   @0x23a6a8 vldr s14, [sp]
 *   @0x23a6ac vldr s15, [r4, #96]
 *   @0x23a6b0 vdiv.f32 s15, s14, s15
 *   @0x23a6b4 vmov r0, s15
 *   @0x23a6b8 add sp, sp, #8
 *   @0x23a6bc pop {r4, pc}
 *   @0x23a6c0 vldr s15, [pc, #8]
 *   @0x23a6c4 vmov r0, s15
 *   @0x23a6c8 add sp, sp, #8
 *   @0x23a6cc pop {r4, pc}
 *   @0x23a6d0 andeq r0, r0, r0
 *
 * ══ §28/438 CPhysicsWorld::GetParticleGroupCentreY(int)  0x23a6d4  size 76  19 条（0x23a6d4..0x23a720）
 * @func 0x23a6d4 0x23a720  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetCenter() const
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a6d4 push {r4, lr}
 *   @0x23a6d8 sub sp, sp, #8
 *   @0x23a6dc mov r4, r0
 *   @0x23a6e0 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a6e4 subs r1, r0, #0
 *   @0x23a6e8 beq 0x23a70c <_ZN13CPhysicsWorld23GetParticleGroupCentreYEi+0x38>
 *   @0x23a6ec mov r0, sp
 *   @0x23a6f0 bl 0x2d483c <_ZNK15b2ParticleGroup9GetCenterEv>
 *   @0x23a6f4 vldr s14, [sp, #4]
 *   @0x23a6f8 vldr s15, [r4, #96]
 *   @0x23a6fc vdiv.f32 s15, s14, s15
 *   @0x23a700 vmov r0, s15
 *   @0x23a704 add sp, sp, #8
 *   @0x23a708 pop {r4, pc}
 *   @0x23a70c vldr s15, [pc, #8]
 *   @0x23a710 vmov r0, s15
 *   @0x23a714 add sp, sp, #8
 *   @0x23a718 pop {r4, pc}
 *   @0x23a71c andeq r0, r0, r0
 *
 * ══ §29/438 CPhysicsWorld::GetParticleGroupVelocityX(int)  0x23a720  size 76  19 条（0x23a720..0x23a76c）
 * @func 0x23a720 0x23a76c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetLinearVelocity() const
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a720 push {r4, lr}
 *   @0x23a724 sub sp, sp, #8
 *   @0x23a728 mov r4, r0
 *   @0x23a72c bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a730 subs r1, r0, #0
 *   @0x23a734 beq 0x23a758 <_ZN13CPhysicsWorld25GetParticleGroupVelocityXEi+0x38>
 *   @0x23a738 mov r0, sp
 *   @0x23a73c bl 0x2d4864 <_ZNK15b2ParticleGroup17GetLinearVelocityEv>
 *   @0x23a740 vldr s14, [sp]
 *   @0x23a744 vldr s15, [r4, #96]
 *   @0x23a748 vdiv.f32 s15, s14, s15
 *   @0x23a74c vmov r0, s15
 *   @0x23a750 add sp, sp, #8
 *   @0x23a754 pop {r4, pc}
 *   @0x23a758 vldr s15, [pc, #8]
 *   @0x23a75c vmov r0, s15
 *   @0x23a760 add sp, sp, #8
 *   @0x23a764 pop {r4, pc}
 *   @0x23a768 andeq r0, r0, r0
 *
 * ══ §30/438 CPhysicsWorld::GetParticleGroupVelocityY(int)  0x23a76c  size 76  19 条（0x23a76c..0x23a7b8）
 * @func 0x23a76c 0x23a7b8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetLinearVelocity() const
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a76c push {r4, lr}
 *   @0x23a770 sub sp, sp, #8
 *   @0x23a774 mov r4, r0
 *   @0x23a778 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a77c subs r1, r0, #0
 *   @0x23a780 beq 0x23a7a4 <_ZN13CPhysicsWorld25GetParticleGroupVelocityYEi+0x38>
 *   @0x23a784 mov r0, sp
 *   @0x23a788 bl 0x2d4864 <_ZNK15b2ParticleGroup17GetLinearVelocityEv>
 *   @0x23a78c vldr s14, [sp, #4]
 *   @0x23a790 vldr s15, [r4, #96]
 *   @0x23a794 vdiv.f32 s15, s14, s15
 *   @0x23a798 vmov r0, s15
 *   @0x23a79c add sp, sp, #8
 *   @0x23a7a0 pop {r4, pc}
 *   @0x23a7a4 vldr s15, [pc, #8]
 *   @0x23a7a8 vmov r0, s15
 *   @0x23a7ac add sp, sp, #8
 *   @0x23a7b0 pop {r4, pc}
 *   @0x23a7b4 andeq r0, r0, r0
 *
 * ══ §31/438 MemoryManager::Init()  0x27c23c  size 76  19 条（0x27c23c..0x27c288）
 * @func 0x27c23c 0x27c288  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x200×2 / 0x38×1 / 0x34×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c23c ldr r2, [pc, #0x38]
 *   @0x27c240 mov r1, #1
 *   @0x27c244 ldr r3, [pc, #0x34]
 *   @0x27c248 add r2, pc, r2
 *   @0x27c24c ldr r3, [pc, r3]
 *   @0x27c250 ldrb r0, [r2, #0x200]
 *   @0x27c254 strb r1, [r3]
 *   @0x27c258 cmp r0, #0
 *   @0x27c25c bxne lr
 *   @0x27c260 ldr r3, [pc, #0x1c]
 *   @0x27c264 strb r1, [r2, #0x200]
 *   @0x27c268 ldr r3, [pc, r3]
 *   @0x27c26c ldr r3, [r3]
 *   @0x27c270 cmp r3, #0
 *   @0x27c274 bxne lr
 *   @0x27c278 b 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38>
 *   @0x27c27c subeq r10, sp, r8, asr #4
 *   @0x27c280 andseq r5, r7, r4, lsl #12
 *   @0x27c284 ldrheq r5, [r7], -r4
 *
 * ══ §32/438 spSkeleton_setSlotsToSetupPose  0x28a064  size 76  19 条（0x28a064..0x28a0b0）
 * @func 0x28a064 0x28a0b0  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc / spSlot_setToSetupPose
 * 字段偏移 top8: 0x10×3 / 0x14×2 / 0x18×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a064 ldr r2, [r0, #0x10]
 *   @0x28a068 push {r3, r4, r5, lr}
 *   @0x28a06c mov r5, r0
 *   @0x28a070 ldr r1, [r5, #0x14]
 *   @0x28a074 lsl r2, r2, #2
 *   @0x28a078 ldr r0, [r0, #0x18]
 *   @0x28a07c bl 0xb65bc <memcpy@plt>
 *   @0x28a080 ldr r3, [r5, #0x10]
 *   @0x28a084 cmp r3, #0
 *   @0x28a088 pople {r3, r4, r5, pc}
 *   @0x28a08c mov r4, #0
 *   @0x28a090 ldr r3, [r5, #0x14]
 *   @0x28a094 ldr r0, [r3, r4, lsl #2]
 *   @0x28a098 add r4, r4, #1
 *   @0x28a09c bl 0x28ee80 <spSlot_setToSetupPose>
 *   @0x28a0a0 ldr r3, [r5, #0x10]
 *   @0x28a0a4 cmp r3, r4
 *   @0x28a0a8 bgt 0x28a090 <spSkeleton_setSlotsToSetupPose+0x2c>
 *   @0x28a0ac pop {r3, r4, r5, pc}
 *
 * ══ §33/438 spPolygon_create  0x28a56c  size 76  19 条（0x28a56c..0x28a5b8）
 * @func 0x28a56c 0x28a5b8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / _malloc
 * 字段偏移 top8: 0x38×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a56c push {r4, r5, r6, lr}
 *   @0x28a570 mov r3, #37
 *   @0x28a574 ldr r6, [pc, #0x38]
 *   @0x28a578 mov r5, r0
 *   @0x28a57c mov r1, #12
 *   @0x28a580 mov r0, #1
 *   @0x28a584 add r6, pc, r6
 *   @0x28a588 mov r2, r6
 *   @0x28a58c bl 0x285c4c <_calloc>
 *   @0x28a590 mov r1, r6
 *   @0x28a594 mov r2, #39
 *   @0x28a598 mov r4, r0
 *   @0x28a59c str r5, [r0, #0x8]
 *   @0x28a5a0 lsl r0, r5, #2
 *   @0x28a5a4 bl 0x285c10 <_malloc>
 *   @0x28a5a8 str r0, [r4]
 *   @0x28a5ac mov r0, r4
 *   @0x28a5b0 pop {r4, r5, r6, pc}
 *   @0x28a5b4 andeq sp, r12, r8, ror #9
 *
 * ══ §34/438 Java_com_yoyogames_runner_RunnerJNILib_Resume  0x292588  size 76  19 条（0x292588..0x2925d4）
 * @func 0x292588 0x2925d4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / 0xb6d54
 * 字段偏移 top8: 0x2c×2 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292588 push {r3, lr}
 *   @0x29258c bl 0x290614 <setJNIEnv>
 *   @0x292590 bl 0xb6d54 <alcResumeCurrentDevice@plt>
 *   @0x292594 ldr r3, [pc, #0x2c]
 *   @0x292598 ldr r1, [pc, #0x2c]
 *   @0x29259c ldr r3, [pc, r3]
 *   @0x2925a0 add r1, pc, r1
 *   @0x2925a4 ldr r0, [r3]
 *   @0x2925a8 ldr r3, [r0]
 *   @0x2925ac ldr r3, [r3, #0xc]
 *   @0x2925b0 blx r3
 *   @0x2925b4 ldr r3, [pc, #0x14]
 *   @0x2925b8 mov r2, #1
 *   @0x2925bc ldr r3, [pc, r3]
 *   @0x2925c0 strb r2, [r3]
 *   @0x2925c4 pop {r3, pc}
 *   @0x2925c8 andseq r11, r5, r8, ror r1
 *   @0x2925cc strheq r6, [r12], -r0
 *   @0x2925d0 andseq pc, r5, r0, lsl #7
 *
 * ══ §35/438 yySocket::Listen(int)  0x295240  size 76  19 条（0x295240..0x29528c）
 * @func 0x295240 0x29528c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6dd8 / yySocket::Listen(int)+0x1c
 * 字段偏移 top8: 0x20×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x295240 push {r4, lr}
 *   @0x295244 ldr r0, [r0]
 *   @0x295248 bl 0xb6dd8 <listen@plt>
 *   @0x29524c subs r4, r0, #0
 *   @0x295250 blt 0x29525c <_ZN8yySocket6ListenEi+0x1c>
 *   @0x295254 mov r0, r4
 *   @0x295258 pop {r4, pc}
 *   @0x29525c ldr r3, [pc, #0x20]
 *   @0x295260 ldr r1, [pc, #0x20]
 *   @0x295264 ldr r3, [pc, r3]
 *   @0x295268 add r1, pc, r1
 *   @0x29526c ldr r0, [r3]
 *   @0x295270 ldr r3, [r0]
 *   @0x295274 ldr r3, [r3, #0xc]
 *   @0x295278 blx r3
 *   @0x29527c mov r0, r4
 *   @0x295280 pop {r4, pc}
 *   @0x295284 ldrheq r8, [r5], -r0
 *   @0x295288 andeq r3, r12, r8, ror #31
 *
 * ══ §36/438 anon_29d720  0x29d720  size 76  19 条（0x29d720..0x29d76c）
 * @func 0x29d720 0x29d76c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CThread::Sleep(int) / DbgServer::Process() / Mutex::Lock() / Mutex::Unlock()
 * 字段偏移 top8: 0x14×2 / 0x3c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d720 push {r4, r5, r6, lr}
 *   @0x29d724 mov r4, r0
 *   @0x29d728 ldr r6, [pc, #0x3c]
 *   @0x29d72c ldr r6, [pc, r6]
 *   @0x29d730 b 0x29d738 <_Z23DebuggerMessageLoopTickv+0x50>
 *   @0x29d734 bl 0x27e114 <_ZN7CThread5SleepEi>
 *   @0x29d738 ldr r0, [r6]
 *   @0x29d73c bl 0x29d62c <_ZN9DbgServer7ProcessEv>
 *   @0x29d740 ldr r0, [r4, #0x14]
 *   @0x29d744 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x29d748 ldrb r5, [r4, #0x8]
 *   @0x29d74c ldr r0, [r4, #0x14]
 *   @0x29d750 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x29d754 mov r0, #16
 *   @0x29d758 uxtb r5, r5
 *   @0x29d75c cmp r5, #0
 *   @0x29d760 beq 0x29d734 <_Z23DebuggerMessageLoopTickv+0x4c>
 *   @0x29d764 mov r0, #0
 *   @0x29d768 pop {r4, r5, r6, pc}
 *
 * ══ §37/438 _zip_new(zip_error*)  0x2a597e  size 76  19 条（0x2a597e..0x2a59ca）
 * @func 0x2a597e 0x2a59ca  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 0x24×1 / 0x30×1 / 0x34×1 / 0x38×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a597e push {r3, r4, r5, lr}
 *   @0x2a5982 movs r0, #0x44
 *   @0x2a5986 .word 0x4604edde
 *   @0x2a598a cbnz r0, 0x2a5998 <_Z8_zip_newP9zip_error+0x1a>
 *   @0x2a598e movs r1, #0xe
 *   @0x2a5992 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a5996 b 0x2a59c6 <_Z8_zip_newP9zip_error+0x48>
 *   @0x2a599a adds r0, #0xc
 *   @0x2a599e .word 0xf8405c0c
 *   @0x2a59a2 .word 0xf8405c08
 *   @0x2a59a6 .word 0xf7fe5c04
 *   @0x2a59aa .word 0xf04ffcd1
 *   @0x2a59ae eorvs r3, r5, #-67108861
 *   @0x2a59b2 str r5, [r4, #0x24]
 *   @0x2a59b6 str r5, [r4, #0x30]
 *   @0x2a59ba str r5, [r4, #0x34]
 *   @0x2a59be str r5, [r4, #0x38]
 *   @0x2a59c2 str r5, [r4, #0x1c]
 *   @0x2a59c6 mov r0, r4
 *
 * ══ §38/438 png_set_tIME  0x2af100  size 76  19 条（0x2af100..0x2af14c）
 * @func 0x2af100 0x2af14c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_set_tIME+0x36
 * 字段偏移 top8: 0x2×1 / 0x3×1 / 0x4×1 / 0x6×1 / 0x3c×1 / 0x40×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af100 cbz r0, 0x2af146 <png_set_tIME+0x46>
 *   @0x2af104 ldr.w r3, [r0, #0x12c]
 *   @0x2af108 lsls r3, r3, #0x16
 *   @0x2af10c ldrb r3, [r2, #0x2]
 *   @0x2af110 cmp r3, #0xb
 *   @0x2af114 ldrb r3, [r2, #0x3]
 *   @0x2af118 cmp r3, #0x1e
 *   @0x2af11c ldrb r3, [r2, #0x4]
 *   @0x2af120 bhi 0x2af12e <png_set_tIME+0x2e>
 *   @0x2af124 cmp r3, #0x3b
 *   @0x2af128 ldrb r3, [r2, #0x6]
 *   @0x2af12c bls 0x2af136 <png_set_tIME+0x36>
 *   @0x2af130 add r1, pc
 *   @0x2af134 ldmdavs r3, {r0, r1, r2, r3, r4, r7, r8, r11, r12, sp, pc}
 *   @0x2af138 str r3, [r1, #0x3c]
 *   @0x2af13c str r3, [r1, #0x40]
 *   @0x2af140 orr r3, r3, #0x200
 *   @0x2af144 str r3, [r1, #0x8]
 *   @0x2af148 .word 0xeb2e 000d
 *
 * ══ §39/438 png_do_packswap  0x2af8e4  size 76  19 条（0x2af8e4..0x2af930）
 * @func 0x2af8e4 0x2af930  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x9×1 / 0x4×1 / 0x28×1 / 0x20×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af8e4 ldrb r3, [r0, #0x9]
 *   @0x2af8e8 bhi 0x2af922 <png_do_packswap+0x3e>
 *   @0x2af8ec ldr r2, [r0, #0x4]
 *   @0x2af8f0 cmp r3, #0x2
 *   @0x2af8f4 cmp r3, #0x4
 *   @0x2af8f8 ldr r3, [pc, #0x28]
 *   @0x2af8fc add.w r3, r3, #0x200
 *   @0x2af900 b 0x2af910 <png_do_packswap+0x2c>
 *   @0x2af904 add r3, pc
 *   @0x2af908 ldr r3, [pc, #0x20]
 *   @0x2af90c add.w r3, r3, #0x100
 *   @0x2af910 add r2, r1
 *   @0x2af914 mov r0, r1
 *   @0x2af918 ldrb r0, [r0]
 *   @0x2af91c strb r0, [r1], #1
 *   @0x2af920 b 0x2af912 <png_do_packswap+0x2e>
 *   @0x2af924 lsls r6, r4, #0x5
 *   @0x2af928 lsls r4, r3, #0x5
 *   @0x2af92c lsls r6, r2, #0x5
 *
 * ══ §40/438 png_set_compression_window_bits  0x2b08c4  size 76  19 条（0x2b08c4..0x2b0910）
 * @func 0x2b08c4 0x2b0910  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b08c4 push {r3, r4, r5, lr}
 *   @0x2b08c8 mov r5, r0
 *   @0x2b08cc cmp r1, #0xf
 *   @0x2b08d0 ldr r1, [pc, #0x30]
 *   @0x2b08d4 b 0x2b08de <png_set_compression_window_bits+0x1a>
 *   @0x2b08d8 bgt 0x2b08e4 <png_set_compression_window_bits+0x20>
 *   @0x2b08dc add r1, pc
 *   @0x2b08e0 and pc, r6, r9, asr #27
 *   @0x2b08e4 cmp r1, #0x8
 *   @0x2b08e8 ldr r1, [pc, #0x20]
 *   @0x2b08ec add r1, pc
 *   @0x2b08f0 .word 0xf8d5fdc1
 *   @0x2b08f4 .word 0xf8c53130
 *   @0x2b08f8 .word 0xf0434180
 *   @0x2b08fc .word 0xf8c50308
 *   @0x2b0900 ldclt p1, c3, [r8, #-192]!
 *   @0x2b0904 bvc 0x2b09d0 <png_write_png+0x78>
 *   @0x2b0908 bvc 0x2b0822 <png_set_filter+0x112>
 *   @0x2b090c bvc 0x2b0868 <png_set_filter+0x158>
 *
 * ══ §41/438 b2ChainShape::~b2ChainShape()  0x2c4958  size 76  19 条（0x2c4958..0x2c49a4）
 * @func 0x2c4958 0x2c49a4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Free(void*)
 * 字段偏移 top8: 0xc×2 / 0x3c×1 / 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4958 ldr r3, [pc, #0x3c]
 *   @0x2c495c push {r4, lr}
 *   @0x2c4960 ldr r3, [pc, r3]
 *   @0x2c4964 mov r4, r0
 *   @0x2c4968 add r3, r3, #8
 *   @0x2c496c ldr r0, [r0, #0xc]
 *   @0x2c4970 str r3, [r4]
 *   @0x2c4974 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c4978 ldr r3, [pc, #0x20]
 *   @0x2c497c mov r2, #0
 *   @0x2c4980 mov r0, r4
 *   @0x2c4984 ldr r3, [pc, r3]
 *   @0x2c4988 str r2, [r4, #0xc]
 *   @0x2c498c add r3, r3, #8
 *   @0x2c4990 str r2, [r4, #0x10]
 *   @0x2c4994 str r3, [r4]
 *   @0x2c4998 pop {r4, pc}
 *   @0x2c499c andseq r12, r2, r8, asr r11
 *   @0x2c49a0 andseq r12, r2, r12, lsl r11
 *
 * ══ §42/438 b2DynamicTree::ComputeHeight(int) const  0x2df84c  size 76  19 条（0x2df84c..0x2df898）
 * @func 0x2df84c 0x2df898  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::ComputeHeight(int) const×2
 * 字段偏移 top8: 0x4×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df84c add r1, r1, r1, lsl #3
 *   @0x2df850 ldr r3, [r0, #0x4]
 *   @0x2df854 push {r4, r5, r6, lr}
 *   @0x2df858 add r4, r3, r1, lsl #2
 *   @0x2df85c mov r5, r0
 *   @0x2df860 ldr r1, [r4, #0x18]
 *   @0x2df864 cmn r1, #1
 *   @0x2df868 beq 0x2df890 <_ZNK13b2DynamicTree13ComputeHeightEi+0x44>
 *   @0x2df86c bl 0x2df84c <_ZNK13b2DynamicTree13ComputeHeightEi>
 *   @0x2df870 ldr r1, [r4, #0x1c]
 *   @0x2df874 mov r6, r0
 *   @0x2df878 mov r0, r5
 *   @0x2df87c bl 0x2df84c <_ZNK13b2DynamicTree13ComputeHeightEi>
 *   @0x2df880 cmp r0, r6
 *   @0x2df884 movlt r0, r6
 *   @0x2df888 add r0, r0, #1
 *   @0x2df88c pop {r4, r5, r6, pc}
 *   @0x2df890 mov r0, #0
 *   @0x2df894 pop {r4, r5, r6, pc}
 *
 * ══ §43/438 b2ChainAndCircleContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)  0x2e1da8  size 76  19 条（0x2e1da8..0x2e1df4）
 * @func 0x2e1da8 0x2e1df4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2ChainAndCircleContact::b2ChainAndCircleContact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1da8 push {r4, r5, r6, r7, r8, lr}
 *   @0x2e1dac sub sp, sp, #8
 *   @0x2e1db0 mov r7, r0
 *   @0x2e1db4 mov r6, r1
 *   @0x2e1db8 ldr r0, [sp, #0x20]
 *   @0x2e1dbc mov r1, #148
 *   @0x2e1dc0 mov r5, r2
 *   @0x2e1dc4 mov r8, r3
 *   @0x2e1dc8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2e1dcc subs r4, r0, #0
 *   @0x2e1dd0 beq 0x2e1de8 <_ZN23b2ChainAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x40>
 *   @0x2e1dd4 str r8, [sp]
 *   @0x2e1dd8 mov r1, r7
 *   @0x2e1ddc mov r2, r6
 *   @0x2e1de0 mov r3, r5
 *   @0x2e1de4 bl 0x2e1d70 <_ZN23b2ChainAndCircleContactC2EP9b2FixtureiS1_i>
 *   @0x2e1de8 mov r0, r4
 *   @0x2e1dec add sp, sp, #8
 *   @0x2e1df0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §44/438 b2ChainAndPolygonContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)  0x2e1f34  size 76  19 条（0x2e1f34..0x2e1f80）
 * @func 0x2e1f34 0x2e1f80  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2ChainAndPolygonContact::b2ChainAndPolygonContact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1f34 push {r4, r5, r6, r7, r8, lr}
 *   @0x2e1f38 sub sp, sp, #8
 *   @0x2e1f3c mov r7, r0
 *   @0x2e1f40 mov r6, r1
 *   @0x2e1f44 ldr r0, [sp, #0x20]
 *   @0x2e1f48 mov r1, #148
 *   @0x2e1f4c mov r5, r2
 *   @0x2e1f50 mov r8, r3
 *   @0x2e1f54 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2e1f58 subs r4, r0, #0
 *   @0x2e1f5c beq 0x2e1f74 <_ZN24b2ChainAndPolygonContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x40>
 *   @0x2e1f60 str r8, [sp]
 *   @0x2e1f64 mov r1, r7
 *   @0x2e1f68 mov r2, r6
 *   @0x2e1f6c mov r3, r5
 *   @0x2e1f70 bl 0x2e1efc <_ZN24b2ChainAndPolygonContactC2EP9b2FixtureiS1_i>
 *   @0x2e1f74 mov r0, r4
 *   @0x2e1f78 add sp, sp, #8
 *   @0x2e1f7c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §45/438 anon_2e4e68  0x2e4e68  size 76  19 条（0x2e4e68..0x2e4eb4）
 * @func 0x2e4e68 0x2e4eb4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4e68 .word 0x460cb538
 *   @0x2e4e6c stmvs r9, {r0, r2, r9, r10, lr}
 *   @0x2e4e70 strheq pc, [r6], #-144
 *   @0x2e4e74 .word 0xffeaf7ff
 *   @0x2e4e78 eorslo r6, pc, r1, lsr #17
 *   @0x2e4e7c eorseq pc, pc, r0, lsr #32
 *   @0x2e4e80 rfeib r5!
 *   @0x2e4e84 .word 0xf7ff0048
 *   @0x2e4e88 stmvs r1!, {r0, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e4e8c eorseq pc, pc, r0, lsr #32
 *   @0x2e4e90 rfeib r5!
 *   @0x2e4e94 .word 0xf7ff004a
 *   @0x2e4e98 stmdavs r1!, {r0, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2e4e9c .word 0xf0203020
 *   @0x2e4ea0 .word 0x6160003f
 *   @0x2e4ea4 strheq pc, [r12], #-149
 *   @0x2e4ea8 .word 0xffd0f7ff
 *   @0x2e4eac .word 0xf0203020
 *   @0x2e4eb0 lsrvs r0, pc, r0
 *
 * ══ §46/438 ft_module_get_service  0x2e5f36  size 76  19 条（0x2e5f36..0x2e5f82）
 * @func 0x2e5f36 0x2e5f82  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5f36 push {r3, r4, r5, r6, r7, lr}
 *   @0x2e5f3a mov r5, r2
 *   @0x2e5f3e cbnz r0, 0x2e5f44 <ft_module_get_service+0xe>
 *   @0x2e5f42 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e5f46 ldr r3, [r3, #0x20]
 *   @0x2e5f4a blx r3
 *   @0x2e5f4e cbnz r0, 0x2e5f80 <ft_module_get_service+0x4a>
 *   @0x2e5f52 add.w r5, r3, #0x14
 *   @0x2e5f56 ldr r7, [r3, #0x10]
 *   @0x2e5f5a adcsmi r0, sp, #35389440
 *   @0x2e5f5e bhs 0x2e5f40 <ft_module_get_service+0xa>
 *   @0x2e5f62 adcmi r0, r0, #4, #22
 *   @0x2e5f66 beq 0x2e5f5c <ft_module_get_service+0x26>
 *   @0x2e5f6a ldr r3, [r3, #0x20]
 *   @0x2e5f6e beq 0x2e5f5c <ft_module_get_service+0x26>
 *   @0x2e5f72 blx r3
 *   @0x2e5f76 beq 0x2e5f5c <ft_module_get_service+0x26>
 *   @0x2e5f7a cmp r2, #0x0
 *   @0x2e5f7e b 0x2e5f40 <ft_module_get_service+0xa>
 *
 * ══ §47/438 FT_Get_SubGlyph_Info  0x2e602c  size 76  19 条（0x2e602c..0x2e6078）
 * @func 0x2e602c 0x2e6078  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0x4×1 / 0x14×1 / 0xc×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e602c push {r4, r5, r6, r7, lr}
 *   @0x2e6030 cbz r0, 0x2e606e <FT_Get_SubGlyph_Info+0x42>
 *   @0x2e6034 bicslt r5, r5, r4, lsl #1
 *   @0x2e6038 ldr r6, [r0, #0x48]
 *   @0x2e603c cmp r6, r7
 *   @0x2e6040 ldr.w r0, [r0, #0x80]
 *   @0x2e6044 cmp r1, r0
 *   @0x2e6048 lsls r1, r1, #0x5
 *   @0x2e604c ldr r1, [r5, r1]
 *   @0x2e6050 ldrh r2, [r0, #0x4]
 *   @0x2e6054 ldr r3, [sp, #0x14]
 *   @0x2e6058 str r2, [r3]
 *   @0x2e605c ldr r2, [r0, #0xc]
 *   @0x2e6060 add.w r3, r0, #0x10
 *   @0x2e6064 ldm r3, {r0, r1, r2, r3}
 *   @0x2e6068 andhs r0, r0, pc
 *   @0x2e606c pop {r4, r5, r6, r7, pc}
 *   @0x2e6070 pop {r4, r5, r6, r7, pc}
 *   @0x2e6074 ldr r0, [r6, #0x54]
 *
 * ══ §48/438 FT_Stream_ReadUShort  0x2e6b04  size 76  19 条（0x2e6b04..0x2e6b50）
 * @func 0x2e6b04 0x2e6b50  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6b04 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e6b08 str r3, [r1]
 *   @0x2e6b0c ldr r3, [r0, #0x8]
 *   @0x2e6b10 ldr r2, [r0, #0x4]
 *   @0x2e6b14 cmp r1, r2
 *   @0x2e6b18 ldr r7, [r0, #0x14]
 *   @0x2e6b1c add r6, sp, #0x4
 *   @0x2e6b20 movs r3, #0x2
 *   @0x2e6b24 blx r7
 *   @0x2e6b28 bne 0x2e6b46 <FT_Stream_ReadUShort+0x42>
 *   @0x2e6b2c b 0x2e6b34 <FT_Stream_ReadUShort+0x30>
 *   @0x2e6b30 adds r3, r2, r3
 *   @0x2e6b34 ldrb r0, [r3]
 *   @0x2e6b38 orr.w r3, r3, r0, lsl #8
 *   @0x2e6b3c ldr r2, [r4, #0x8]
 *   @0x2e6b40 adds r2, #0x2
 *   @0x2e6b44 b 0x2e6b4c <FT_Stream_ReadUShort+0x48>
 *   @0x2e6b48 movs r3, #0x55
 *   @0x2e6b4c add sp, #0xc
 *
 * ══ §49/438 FT_Stream_ReadUShortLE  0x2e6d24  size 76  19 条（0x2e6d24..0x2e6d70）
 * @func 0x2e6d24 0x2e6d70  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x4×1 / 0x14×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6d24 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e6d28 str r3, [r1]
 *   @0x2e6d2c ldr r3, [r0, #0x8]
 *   @0x2e6d30 ldr r2, [r0, #0x4]
 *   @0x2e6d34 cmp r1, r2
 *   @0x2e6d38 ldr r7, [r0, #0x14]
 *   @0x2e6d3c add r6, sp, #0x4
 *   @0x2e6d40 movs r3, #0x2
 *   @0x2e6d44 blx r7
 *   @0x2e6d48 bne 0x2e6d66 <FT_Stream_ReadUShortLE+0x42>
 *   @0x2e6d4c b 0x2e6d54 <FT_Stream_ReadUShortLE+0x30>
 *   @0x2e6d50 adds r3, r2, r3
 *   @0x2e6d54 ldrb r0, [r3, #0x1]
 *   @0x2e6d58 orr.w r3, r3, r0, lsl #8
 *   @0x2e6d5c ldr r2, [r4, #0x8]
 *   @0x2e6d60 adds r2, #0x2
 *   @0x2e6d64 b 0x2e6d6c <FT_Stream_ReadUShortLE+0x48>
 *   @0x2e6d68 movs r3, #0x55
 *   @0x2e6d6c add sp, #0xc
 *
 * ══ §50/438 FT_GlyphLoader_Reset  0x2e7340  size 76  19 条（0x2e7340..0x2e738c）
 * @func 0x2e7340 0x2e738c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free×3
 * 字段偏移 top8: 0x18×2 / 0x20×2 / 0x28×1 / 0x34×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7340 push {r4, r5, r6, lr}
 *   @0x2e7344 ldr r6, [r0]
 *   @0x2e7348 ldr r1, [r4, #0x18]
 *   @0x2e734c bl 0x2e7336 <ft_mem_free>
 *   @0x2e7350 mov r0, r6
 *   @0x2e7354 str r5, [r4, #0x18]
 *   @0x2e7358 ldrtmi pc, [r0], -lr, ror #31
 *   @0x2e735c ldr r1, [r4, #0x20]
 *   @0x2e7360 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7364 mov r0, r6
 *   @0x2e7368 str r5, [r4, #0x20]
 *   @0x2e736c ldrtmi pc, [r0], -r4, ror #31
 *   @0x2e7370 str r5, [r4, #0x28]
 *   @0x2e7374 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7378 str r5, [r4, #0x34]
 *   @0x2e737c mov r0, r4
 *   @0x2e7380 str r5, [r4, #0x8]
 *   @0x2e7384 pop.w {r4, r5, r6, lr}
 *   @0x2e7388 b.w 0x2e52bc <FT_GlyphLoader_Rewind>
 *
 * ══ §51/438 anon_318678  0x318678  size 76  19 条（0x318678..0x3186c4）
 * @func 0x318678 0x3186c4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x372ed4 / 0x330ed8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x318678 .word 0xf7feb538
 *   @0x31867c stmvs r1, {r0, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x318680 ldmib r1, {r0, r3, r6, r7, r8, r12, sp, pc} ^
 *   @0x318684 movwge r4, #0xe50e
 *   @0x318688 movwhs lr, #0x9d3
 *   @0x31868c rsbmi r4, r11, r2, rrx
 *   @0x318690 streq lr, [r3], #-2642
 *   @0x318694 movwhs sp, #0x4
 *   @0x318698 .word 0xf1016083
 *   @0x31869c ldclt p0, c0, [r8, #-224]!
 *   @0x3186a0 bllo 0x372ed4 <_ZTS13C_UTF16String+0x9f80>
 *   @0x3186a4 blhs 0x330ed8
 *   @0x3186a8 stmibvs r10, {r0, r1, r2, r4, r5, r6, r7, r8, r12, lr, pc} ^
 *   @0x3186ac .word 0xf1016082
 *   @0x3186b0 bicvs r0, r11, r8, lsr r0
 *   @0x3186b4 .word 0xf7ffbd38
 *   @0x3186b8 svclt #0xfdcb
 *   @0x3186bc andhi pc, r0, pc, lsr #7
 *   @0x3186c0 .word 0x432b2b00
 *
 * ══ §52/438 FT_Set_Pixel_Sizes  0x2e57d2  size 74  19 条（0x2e57d2..0x2e581c）
 * @func 0x2e57d2 0x2e581c  size 74  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e57d2 push {r4, lr}
 *   @0x2e57d6 strdlt r7, r8, [r6], lr
 *   @0x2e57da cbz r1, 0x2e57e4 <FT_Set_Pixel_Sizes+0x12>
 *   @0x2e57de it eq
 *   @0x2e57e2 b 0x2e57e8 <FT_Set_Pixel_Sizes+0x16>
 *   @0x2e57e6 mov r1, r2
 *   @0x2e57ea addsmi r7, r9, #-16777216
 *   @0x2e57ee it hi
 *   @0x2e57f2 b 0x2e57f8 <FT_Set_Pixel_Sizes+0x26>
 *   @0x2e57f6 mov r2, r1
 *   @0x2e57fa addsmi r7, r10, #-16777216
 *   @0x2e57fe it hi
 *   @0x2e5802 lsls r1, r1, #0x6
 *   @0x2e5806 add r1, sp, #0x4
 *   @0x2e580a lsls r2, r2, #0x6
 *   @0x2e580e str r2, [sp, #0xc]
 *   @0x2e5812 str r3, [sp, #0x14]
 *   @0x2e5816 andlt pc, r6, r10, lsl #31
 *   @0x2e581a pop {r4, pc}
 *
 * ══ §53/438 FT_Stream_ReadAt  0x2e6944  size 74  19 条（0x2e6944..0x2e698e）
 * @func 0x2e6944 0x2e698e  size 74  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6944 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2e6948 mov r4, r0
 *   @0x2e694c mov r5, r1
 *   @0x2e6950 cmp r1, r6
 *   @0x2e6954 ldr.w r12, [r0, #0x14]
 *   @0x2e6958 cmp.w r12, #0x0
 *   @0x2e695c beq 0x2e6964 <FT_Stream_ReadAt+0x20>
 *   @0x2e6960 mov r6, r0
 *   @0x2e6964 subs r6, r6, r1
 *   @0x2e6968 cmp r6, r3
 *   @0x2e696c movhs r6, r3
 *   @0x2e6970 add r1, r5
 *   @0x2e6974 blx 0xb65bc <memcpy@plt>
 *   @0x2e6978 add r5, r6
 *   @0x2e697c ite lo
 *   @0x2e6980 movhs r0, #0x0
 *   @0x2e6984 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e6988 movs r0, #0x55
 *   @0x2e698c ldrlt r8, [r0, #-0x1f0]
 *
 * ══ §54/438 FT_Stream_ReadChar  0x2e6aba  size 74  19 条（0x2e6aba..0x2e6b04）
 * @func 0x2e6aba 0x2e6b04  size 74  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6aba push {r0, r1, r4, r5, r6, lr}
 *   @0x2e6abe str r3, [r1]
 *   @0x2e6ac2 ldr r6, [r0, #0x14]
 *   @0x2e6ac6 strb.w r3, [sp, #0x7]
 *   @0x2e6aca cbz r6, 0x2e6adc <FT_Stream_ReadChar+0x22>
 *   @0x2e6ace add.w r2, sp, #0x7
 *   @0x2e6ad2 movs r3, #0x1
 *   @0x2e6ad6 cmp r0, #0x1
 *   @0x2e6ada b 0x2e6aec <FT_Stream_ReadChar+0x32>
 *   @0x2e6ade ldr r2, [r0, #0x4]
 *   @0x2e6ae2 bhs 0x2e6af8 <FT_Stream_ReadChar+0x3e>
 *   @0x2e6ae6 ldrb r3, [r2, r3]
 *   @0x2e6aea stmvs r3!, {r0, r1, r2, r12, sp}
 *   @0x2e6aee ldrb.w r0, [sp, #0x7]
 *   @0x2e6af2 adds r3, #0x1
 *   @0x2e6af6 b 0x2e6afe <FT_Stream_ReadChar+0x44>
 *   @0x2e6afa movs r3, #0x55
 *   @0x2e6afe sxtb r0, r0
 *   @0x2e6b02 pop {r4, r5, r6, pc}
 *
 * ══ §55/438 CSkeletonInstance::GetAttachment(char*) const  0xc07c8  size 72  18 条（0xc07c8..0xc0810）
 * @func 0xc07c8 0xc0810  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findSlot
 * 字段偏移 top8: 0x1c×1 / 0x18×1 / 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc07c8 push {r3, lr}
 *   @0xc07cc ldr r0, [r0, #0x1c]
 *   @0xc07d0 bl 0x28a18c <spSkeleton_findSlot>
 *   @0xc07d4 cmp r0, #0
 *   @0xc07d8 beq 0xc07f0 <_ZNK17CSkeletonInstance13GetAttachmentEPc+0x28>
 *   @0xc07dc ldr r3, [r0, #0x18]
 *   @0xc07e0 cmp r3, #0
 *   @0xc07e4 beq 0xc07fc <_ZNK17CSkeletonInstance13GetAttachmentEPc+0x34>
 *   @0xc07e8 ldr r0, [r3]
 *   @0xc07ec pop {r3, pc}
 *   @0xc07f0 ldr r0, [pc, #0x10]
 *   @0xc07f4 add r0, pc, r0
 *   @0xc07f8 pop {r3, pc}
 *   @0xc07fc ldr r0, [pc, #0x8]
 *   @0xc0800 add r0, pc, r0
 *   @0xc0804 pop {r3, pc}
 *   @0xc0808 eoreq lr, r6, r2, asr #6
 *   @0xc080c eoreq lr, r6, r6, lsr r3
 *
 * ══ §56/438 TErrStreamConsole::~TErrStreamConsole()  0xd3464  size 72  18 条（0xd3464..0xd34ac）
 * @func 0xd3464 0xd34ac  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / operator delete(void*)
 * 字段偏移 top8: 0x38×1 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3464 ldr r3, [pc, #0x38]
 *   @0xd3468 push {r4, lr}
 *   @0xd346c ldr r3, [pc, r3]
 *   @0xd3470 mov r4, r0
 *   @0xd3474 add r3, r3, #8
 *   @0xd3478 ldr r0, [r0, #0x8]
 *   @0xd347c str r3, [r4]
 *   @0xd3480 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd3484 ldr r3, [pc, #0x1c]
 *   @0xd3488 mov r0, r4
 *   @0xd348c ldr r3, [pc, r3]
 *   @0xd3490 add r3, r3, #8
 *   @0xd3494 str r3, [r4]
 *   @0xd3498 bl 0x27d1d0 <_ZdlPv>
 *   @0xd349c mov r0, r4
 *   @0xd34a0 pop {r4, pc}
 *   @0xd34a4 eorseq r10, r1, r12, asr r7
 *   @0xd34a8 ldrsbteq r10, [r1], -r4
 *
 * ══ §57/438 RemoveGCRoot(YYObjectBase*)  0xd5b60  size 72  18 条（0xd5b60..0xd5ba8）
 * @func 0xd5b60 0xd5ba8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGCGeneration::RemoveRoot(YYObjectBase*)
 * 字段偏移 top8: 0x38×2 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd5b60 ldr r3, [r0, #0x38]
 *   @0xd5b64 push {r4, r5, r6, lr}
 *   @0xd5b68 cmp r3, #0
 *   @0xd5b6c mov r6, r0
 *   @0xd5b70 poplt {r4, r5, r6, pc}
 *   @0xd5b74 ldr r4, [pc, #0x28]
 *   @0xd5b78 mov r5, #0
 *   @0xd5b7c ldr r4, [pc, r4]
 *   @0xd5b80 mov r0, r4
 *   @0xd5b84 mov r1, r6
 *   @0xd5b88 bl 0x1911c8 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase>
 *   @0xd5b8c ldr r3, [r6, #0x38]
 *   @0xd5b90 add r5, r5, #1
 *   @0xd5b94 add r4, r4, #88
 *   @0xd5b98 cmp r3, r5
 *   @0xd5b9c bge 0xd5b80 <_Z12RemoveGCRootP12YYObjectBase+0x20>
 *   @0xd5ba0 pop {r4, r5, r6, pc}
 *   @0xd5ba4 eorseq r8, r1, r4, ror #1
 *
 * ══ §58/438 VM::ClearBreakpoint(unsigned int*)  0xd832c  size 72  18 条（0xd832c..0xd8374）
 * @func 0xd832c 0xd8374  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd832c ldr r12, [pc, #0x3c]
 *   @0xd8330 mov r3, #0
 *   @0xd8334 ldr r12, [pc, r12]
 *   @0xd8338 b 0xd8348 <_ZN2VM15ClearBreakpointEPj+0x1c>
 *   @0xd833c add r3, r3, #1
 *   @0xd8340 cmp r3, #255
 *   @0xd8344 beq 0xd836c <_ZN2VM15ClearBreakpointEPj+0x40>
 *   @0xd8348 add r2, r12, r3, lsl #4
 *   @0xd834c ldr r1, [r2, #0x4]
 *   @0xd8350 cmp r1, r0
 *   @0xd8354 bne 0xd833c <_ZN2VM15ClearBreakpointEPj+0x10>
 *   @0xd8358 mvn r0, #0
 *   @0xd835c mov r1, #0
 *   @0xd8360 str r0, [r2, #0x4]
 *   @0xd8364 str r1, [r12, r3, lsl #4]
 *   @0xd8368 bx lr
 *   @0xd836c bx lr
 *   @0xd8370 ldrhteq r5, [r1], -r0
 *
 * ══ §59/438 CFontGM::InitTexture()  0xf7db4  size 72  18 条（0xf7db4..0xf7dfc）
 * @func 0xf7db4 0xf7dfc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::FreeTexture() / GR_Texture_Create_Bytes(int, int, DynamicArrayOfByte*)
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x24×1 / 0x28×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf7db4 push {r4, lr}
 *   @0xf7db8 mov r4, r0
 *   @0xf7dbc bl 0xf707c <_ZN7CFontGM11FreeTextureEv>
 *   @0xf7dc0 ldr r3, [r4, #0x20]
 *   @0xf7dc4 cmp r3, #0
 *   @0xf7dc8 popge {r4, pc}
 *   @0xf7dcc ldr r3, [r4, #0x4]
 *   @0xf7dd0 cmp r3, #0
 *   @0xf7dd4 popeq {r4, pc}
 *   @0xf7dd8 ldrb r3, [r3]
 *   @0xf7ddc cmp r3, #0
 *   @0xf7de0 popeq {r4, pc}
 *   @0xf7de4 ldr r0, [r4, #0x24]
 *   @0xf7de8 add r2, r4, #48
 *   @0xf7dec ldr r1, [r4, #0x28]
 *   @0xf7df0 bl 0x173fdc <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte>
 *   @0xf7df4 str r0, [r4, #0x38]
 *   @0xf7df8 pop {r4, pc}
 *
 * ══ §60/438 Font_Exists(int)  0xfa2a8  size 72  18 条（0xfa2a8..0xfa2f0）
 * @func 0xfa2a8 0xfa2f0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_Exists(int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa2a8 cmp r0, #0
 *   @0xfa2ac blt 0xfa2e0 <_Z11Font_Existsi+0x38>
 *   @0xfa2b0 ldr r3, [pc, #0x30]
 *   @0xfa2b4 ldr r3, [pc, r3]
 *   @0xfa2b8 ldr r3, [r3]
 *   @0xfa2bc cmp r0, r3
 *   @0xfa2c0 bge 0xfa2e0 <_Z11Font_Existsi+0x38>
 *   @0xfa2c4 ldr r3, [pc, #0x20]
 *   @0xfa2c8 ldr r3, [pc, r3]
 *   @0xfa2cc ldr r3, [r3, #0x4]
 *   @0xfa2d0 ldr r0, [r3, r0, lsl #2]
 *   @0xfa2d4 adds r0, r0, #0
 *   @0xfa2d8 movne r0, #1
 *   @0xfa2dc bx lr
 *   @0xfa2e0 mov r0, #0
 *   @0xfa2e4 bx lr
 *   @0xfa2e8 eoreq r3, pc, r12, lsr #23
 *   @0xfa2ec mlaeq pc, r4, r11, r3
 *
 * ══ §61/438 F_MpGridClearCell(RValue&, CInstance*, CInstance*, int, RValue*)  0x108ca0  size 72  18 条（0x108ca0..0x108ce8）
 * @func 0x108ca0 0x108ce8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108ca0 push {r4, r5, r6, lr}
 *   @0x108ca4 mov r1, #0
 *   @0x108ca8 ldr r4, [sp, #0x10]
 *   @0x108cac mov r0, r4
 *   @0x108cb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108cb4 mov r1, #1
 *   @0x108cb8 mov r6, r0
 *   @0x108cbc mov r0, r4
 *   @0x108cc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108cc4 mov r1, #2
 *   @0x108cc8 mov r5, r0
 *   @0x108ccc mov r0, r4
 *   @0x108cd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108cd4 mov r1, r5
 *   @0x108cd8 mov r2, r0
 *   @0x108cdc mov r0, r6
 *   @0x108ce0 pop {r4, r5, r6, lr}
 *   @0x108ce4 b 0x19a26c <_Z21Motion_Grid_ClearCelliii>
 *
 * ══ §62/438 F_MpGridAddCell(RValue&, CInstance*, CInstance*, int, RValue*)  0x108d58  size 72  18 条（0x108d58..0x108da0）
 * @func 0x108d58 0x108da0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108d58 push {r4, r5, r6, lr}
 *   @0x108d5c mov r1, #0
 *   @0x108d60 ldr r4, [sp, #0x10]
 *   @0x108d64 mov r0, r4
 *   @0x108d68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108d6c mov r1, #1
 *   @0x108d70 mov r6, r0
 *   @0x108d74 mov r0, r4
 *   @0x108d78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108d7c mov r1, #2
 *   @0x108d80 mov r5, r0
 *   @0x108d84 mov r0, r4
 *   @0x108d88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108d8c mov r1, r5
 *   @0x108d90 mov r2, r0
 *   @0x108d94 mov r0, r6
 *   @0x108d98 pop {r4, r5, r6, lr}
 *   @0x108d9c b 0x19a404 <_Z19Motion_Grid_AddCelliii>
 *
 * ══ §63/438 F_Log2(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e3f8  size 72  18 条（0x10e3f8..0x10e440）
 * @func 0x10e3f8 0x10e440  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb6730
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e3f8 push {r4, lr}
 *   @0x10e3fc mov r3, #0
 *   @0x10e400 mov r1, r3
 *   @0x10e404 str r3, [r0, #0xc]
 *   @0x10e408 mov r4, r0
 *   @0x10e40c ldr r0, [sp, #0x8]
 *   @0x10e410 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e414 bl 0xb6730 <log@plt>
 *   @0x10e418 vldr d7, [pc, #24]
 *   @0x10e41c vmov d6, r0, r1
 *   @0x10e420 vdiv.f64 d6, d6, d7
 *   @0x10e424 vmov r0, r1, d6
 *   @0x10e428 vmov r2, s12
 *   @0x10e42c mov r3, r1
 *   @0x10e430 stm r4, {r2, r3}
 *   @0x10e434 pop {r4, pc}
 *   @0x10e438 cdp2 p9, #0xf, c3, c10, c15, #0x7
 *   @0x10e43c svclo #0xe62e42
 *
 * ══ §64/438 F_ArrayHeight2D(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f3c0  size 72  18 条（0x10f3c0..0x10f408）
 * @func 0x10f3c0 0x10f408  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f3c0 cmp r3, #1
 *   @0x10f3c4 mov r3, #0
 *   @0x10f3c8 str r3, [r0, #0xc]
 *   @0x10f3cc str r3, [r0]
 *   @0x10f3d0 str r3, [r0, #0x4]
 *   @0x10f3d4 bxne lr
 *   @0x10f3d8 ldr r2, [sp]
 *   @0x10f3dc ldr r3, [r2, #0xc]
 *   @0x10f3e0 cmp r3, #2
 *   @0x10f3e4 bxne lr
 *   @0x10f3e8 ldr r3, [r2]
 *   @0x10f3ec cmp r3, #0
 *   @0x10f3f0 ldrne r2, [r3, #0x10]
 *   @0x10f3f4 vmovne s15, r2
 *   @0x10f3f8 vcvtne.f64.s32 d7, s15
 *   @0x10f3fc vmovne r2, r3, d7
 *   @0x10f400 stmne r0, {r2, r3}
 *   @0x10f404 bx lr
 *
 * ══ §65/438 F_AlarmGet(RValue&, CInstance*, CInstance*, int, RValue*)  0x115e44  size 72  18 条（0x115e44..0x115e8c）
 * @func 0x115e44 0x115e8c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CInstance::GetTimer(int)
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115e44 push {r3, r4, r5, lr}
 *   @0x115e48 mov r3, #0
 *   @0x115e4c mov r4, r0
 *   @0x115e50 str r3, [r0, #0xc]
 *   @0x115e54 mov r5, r1
 *   @0x115e58 ldr r0, [sp, #0x10]
 *   @0x115e5c mov r1, r3
 *   @0x115e60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115e64 mov r1, r0
 *   @0x115e68 mov r0, r5
 *   @0x115e6c bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x115e70 vmov s15, r0
 *   @0x115e74 vcvt.f64.s32 d7, s15
 *   @0x115e78 vmov r0, r1, d7
 *   @0x115e7c vmov r2, s14
 *   @0x115e80 mov r3, r1
 *   @0x115e84 stm r4, {r2, r3}
 *   @0x115e88 pop {r3, r4, r5, pc}
 *
 * ══ §66/438 F_DisplaySetColordepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x119f38  size 72  18 条（0x119f38..0x119f80）
 * @func 0x119f38 0x119f80  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / DisplaySetColorDepth(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119f38 push {r3, r4, r5, lr}
 *   @0x119f3c mov r5, #0
 *   @0x119f40 ldr r3, [sp, #0x10]
 *   @0x119f44 mov r4, r0
 *   @0x119f48 str r5, [r0, #0xc]
 *   @0x119f4c mov r1, r5
 *   @0x119f50 mov r0, r3
 *   @0x119f54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119f58 bl 0x17db8c <_Z20DisplaySetColorDepthi>
 *   @0x119f5c cmp r0, #0
 *   @0x119f60 moveq r5, r0
 *   @0x119f64 movne r3, r5
 *   @0x119f68 moveq r3, r5
 *   @0x119f6c movtne r3, #0x3ff0
 *   @0x119f70 str r5, [r4]
 *   @0x119f74 str r3, [r4, #0x4]
 *   @0x119f78 pop {r3, r4, r5, lr}
 *   @0x119f7c b 0x168c24 <_Z12GR_D3D_Resetv>
 *
 * ══ §67/438 F_DisplaySetFrequency(RValue&, CInstance*, CInstance*, int, RValue*)  0x119f80  size 72  18 条（0x119f80..0x119fc8）
 * @func 0x119f80 0x119fc8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / DisplaySetFrequency(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119f80 push {r3, r4, r5, lr}
 *   @0x119f84 mov r5, #0
 *   @0x119f88 ldr r3, [sp, #0x10]
 *   @0x119f8c mov r4, r0
 *   @0x119f90 str r5, [r0, #0xc]
 *   @0x119f94 mov r1, r5
 *   @0x119f98 mov r0, r3
 *   @0x119f9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119fa0 bl 0x17db78 <_Z19DisplaySetFrequencyi>
 *   @0x119fa4 cmp r0, #0
 *   @0x119fa8 moveq r5, r0
 *   @0x119fac movne r3, r5
 *   @0x119fb0 moveq r3, r5
 *   @0x119fb4 movtne r3, #0x3ff0
 *   @0x119fb8 str r5, [r4]
 *   @0x119fbc str r3, [r4, #0x4]
 *   @0x119fc0 pop {r3, r4, r5, lr}
 *   @0x119fc4 b 0x168c24 <_Z12GR_D3D_Resetv>
 *
 * ══ §68/438 F_SurfaceDepthDisable(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a11c  size 72  18 条（0x11a11c..0x11a164）
 * @func 0x11a11c 0x11a164  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a11c push {r3, lr}
 *   @0x11a120 mov r1, #0
 *   @0x11a124 ldr r0, [sp, #0x8]
 *   @0x11a128 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11a12c cmp r0, #0
 *   @0x11a130 bne 0x11a148 <_Z21F_SurfaceDepthDisableR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x11a134 ldr r3, [pc, #0x20]
 *   @0x11a138 mov r2, #1
 *   @0x11a13c ldr r3, [pc, r3]
 *   @0x11a140 strb r2, [r3]
 *   @0x11a144 pop {r3, pc}
 *   @0x11a148 ldr r3, [pc, #0x10]
 *   @0x11a14c mov r2, #0
 *   @0x11a150 ldr r3, [pc, r3]
 *   @0x11a154 strb r2, [r3]
 *   @0x11a158 pop {r3, pc}
 *   @0x11a15c eoreq r4, sp, r4, lsl #9
 *   @0x11a160 eoreq r4, sp, r0, ror r4
 *
 * ══ §69/438 F_DrawPointExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11adc4  size 72  18 条（0x11adc4..0x11ae0c）
 * @func 0x11adc4 0x11ae0c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11adc4 push {r4, r5, r6, lr}
 *   @0x11adc8 mov r1, #0
 *   @0x11adcc ldr r4, [sp, #0x10]
 *   @0x11add0 mov r0, r4
 *   @0x11add4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11add8 mov r1, #1
 *   @0x11addc mov r6, r0
 *   @0x11ade0 mov r0, r4
 *   @0x11ade4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ade8 mov r1, #2
 *   @0x11adec mov r5, r0
 *   @0x11adf0 mov r0, r4
 *   @0x11adf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11adf8 mov r1, r5
 *   @0x11adfc mov r2, r0
 *   @0x11ae00 mov r0, r6
 *   @0x11ae04 pop {r4, r5, r6, lr}
 *   @0x11ae08 b 0x16a168 <_Z20YYGML_draw_point_extffj>
 *
 * ══ §70/438 F_TileLayerDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c634  size 72  18 条（0x11c634..0x11c67c）
 * @func 0x11c634 0x11c67c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c634 push {r4, r5, r6, lr}
 *   @0x11c638 mov r1, #0
 *   @0x11c63c ldr r4, [sp, #0x10]
 *   @0x11c640 ldr r3, [pc, #0x30]
 *   @0x11c644 ldr r3, [pc, r3]
 *   @0x11c648 mov r0, r4
 *   @0x11c64c ldr r6, [r3]
 *   @0x11c650 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c654 mov r1, #1
 *   @0x11c658 mov r5, r0
 *   @0x11c65c mov r0, r4
 *   @0x11c660 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c664 mov r1, r5
 *   @0x11c668 mov r2, r0
 *   @0x11c66c mov r0, r6
 *   @0x11c670 pop {r4, r5, r6, lr}
 *   @0x11c674 b 0x1af9bc <_ZN5CRoom16ChangeTilesDepthEff>
 *   @0x11c678 eoreq r1, sp, r4, ror #5
 *
 * ══ §71/438 F_SkeletonGetDuration(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cbd0  size 72  18 条（0x11cbd0..0x11cc18）
 * @func 0x11cbd0 0x11cc18  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / CSkeletonInstance::GetDuration(char*) const
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cbd0 push {r4, r5, r6, lr}
 *   @0x11cbd4 mov r4, r0
 *   @0x11cbd8 mov r5, #0
 *   @0x11cbdc mov r0, r1
 *   @0x11cbe0 str r5, [r4, #0xc]
 *   @0x11cbe4 str r5, [r4]
 *   @0x11cbe8 str r5, [r4, #0x4]
 *   @0x11cbec bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cbf0 subs r6, r0, #0
 *   @0x11cbf4 popeq {r4, r5, r6, pc}
 *   @0x11cbf8 mov r1, r5
 *   @0x11cbfc ldr r0, [sp, #0x10]
 *   @0x11cc00 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11cc04 mov r1, r0
 *   @0x11cc08 mov r0, r6
 *   @0x11cc0c bl 0xc08c8 <_ZNK17CSkeletonInstance11GetDurationEPc>
 *   @0x11cc10 stm r4, {r0, r1}
 *   @0x11cc14 pop {r4, r5, r6, pc}
 *
 * ══ §72/438 F_SkeletonClearAnimation(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cc74  size 72  18 条（0x11cc74..0x11ccbc）
 * @func 0x11cc74 0x11ccbc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cc74 mov r3, r0
 *   @0x11cc78 mov r0, r1
 *   @0x11cc7c push {r4, r5, r6, lr}
 *   @0x11cc80 mov r4, #0
 *   @0x11cc84 str r4, [r3, #0xc]
 *   @0x11cc88 str r4, [r3]
 *   @0x11cc8c str r4, [r3, #0x4]
 *   @0x11cc90 ldr r5, [sp, #0x10]
 *   @0x11cc94 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cc98 subs r6, r0, #0
 *   @0x11cc9c popeq {r4, r5, r6, pc}
 *   @0x11cca0 mov r1, r4
 *   @0x11cca4 mov r0, r5
 *   @0x11cca8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ccac mov r1, r0
 *   @0x11ccb0 mov r0, r6
 *   @0x11ccb4 pop {r4, r5, r6, lr}
 *   @0x11ccb8 b 0xbe7f0 <_ZN17CSkeletonInstance14ClearAnimationEi>
 *
 * ══ §73/438 F_SkeletonGetNumBounds(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cd74  size 72  18 条（0x11cd74..0x11cdbc）
 * @func 0x11cd74 0x11cdbc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / CSkeletonInstance::GetNumBoundingBoxAttachments()
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cd74 push {r4, lr}
 *   @0x11cd78 mov r4, r0
 *   @0x11cd7c mov r3, #0
 *   @0x11cd80 mov r0, r1
 *   @0x11cd84 str r3, [r4, #0xc]
 *   @0x11cd88 str r3, [r4]
 *   @0x11cd8c str r3, [r4, #0x4]
 *   @0x11cd90 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cd94 cmp r0, #0
 *   @0x11cd98 popeq {r4, pc}
 *   @0x11cd9c bl 0xbeedc <_ZN17CSkeletonInstance28GetNumBoundingBoxAttachmentsEv>
 *   @0x11cda0 vmov s15, r0
 *   @0x11cda4 vcvt.f64.s32 d7, s15
 *   @0x11cda8 vmov r0, r1, d7
 *   @0x11cdac vmov r2, s14
 *   @0x11cdb0 mov r3, r1
 *   @0x11cdb4 stm r4, {r2, r3}
 *   @0x11cdb8 pop {r4, pc}
 *
 * ══ §74/438 F_ShowMenu(RValue&, CInstance*, CInstance*, int, RValue*)  0x1263a0  size 72  18 条（0x1263a0..0x1263e8）
 * @func 0x1263a0 0x1263e8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x38×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1263a0 ldr r3, [pc, #0x38]
 *   @0x1263a4 push {r4, lr}
 *   @0x1263a8 ldr r3, [pc, r3]
 *   @0x1263ac mov r4, r0
 *   @0x1263b0 ldr r1, [pc, #0x2c]
 *   @0x1263b4 ldr r0, [r3]
 *   @0x1263b8 add r1, pc, r1
 *   @0x1263bc ldr r3, [r0]
 *   @0x1263c0 ldr r3, [r3, #0xc]
 *   @0x1263c4 blx r3
 *   @0x1263c8 mov r3, #0
 *   @0x1263cc str r3, [r4, #0xc]
 *   @0x1263d0 str r3, [r4]
 *   @0x1263d4 str r3, [r4, #0x4]
 *   @0x1263d8 pop {r4, lr}
 *   @0x1263dc b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x1263e0 eoreq r7, r12, r12, ror #6
 *   @0x1263e4 eoreq r5, r1, r8, asr #27
 *
 * ══ §75/438 F_ShowMenuPos(RValue&, CInstance*, CInstance*, int, RValue*)  0x1263e8  size 72  18 条（0x1263e8..0x126430）
 * @func 0x1263e8 0x126430  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x38×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1263e8 ldr r3, [pc, #0x38]
 *   @0x1263ec push {r4, lr}
 *   @0x1263f0 ldr r3, [pc, r3]
 *   @0x1263f4 mov r4, r0
 *   @0x1263f8 ldr r1, [pc, #0x2c]
 *   @0x1263fc ldr r0, [r3]
 *   @0x126400 add r1, pc, r1
 *   @0x126404 ldr r3, [r0]
 *   @0x126408 ldr r3, [r3, #0xc]
 *   @0x12640c blx r3
 *   @0x126410 mov r3, #0
 *   @0x126414 str r3, [r4, #0xc]
 *   @0x126418 str r3, [r4]
 *   @0x12641c str r3, [r4, #0x4]
 *   @0x126420 pop {r4, lr}
 *   @0x126424 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126428 eoreq r7, r12, r4, lsr #6
 *   @0x12642c eoreq r5, r1, r12, lsr #27
 *
 * ══ §76/438 F_GetColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x126430  size 72  18 条（0x126430..0x126478）
 * @func 0x126430 0x126478  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x38×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126430 ldr r3, [pc, #0x38]
 *   @0x126434 push {r4, lr}
 *   @0x126438 ldr r3, [pc, r3]
 *   @0x12643c mov r4, r0
 *   @0x126440 ldr r1, [pc, #0x2c]
 *   @0x126444 ldr r0, [r3]
 *   @0x126448 add r1, pc, r1
 *   @0x12644c ldr r3, [r0]
 *   @0x126450 ldr r3, [r3, #0xc]
 *   @0x126454 blx r3
 *   @0x126458 mov r3, #0
 *   @0x12645c str r3, [r4, #0xc]
 *   @0x126460 str r3, [r4]
 *   @0x126464 str r3, [r4, #0x4]
 *   @0x126468 pop {r4, lr}
 *   @0x12646c b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126470 .word 0x002c72dc
 *   @0x126474 mlaeq r1, r8, sp, r5
 *
 * ══ §77/438 F_PartTypeScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1290f0  size 72  18 条（0x1290f0..0x129138）
 * @func 0x1290f0 0x129138  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1290f0 push {r4, r5, r6, lr}
 *   @0x1290f4 mov r1, #0
 *   @0x1290f8 ldr r4, [sp, #0x10]
 *   @0x1290fc mov r0, r4
 *   @0x129100 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129104 mov r1, #1
 *   @0x129108 mov r6, r0
 *   @0x12910c mov r0, r4
 *   @0x129110 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129114 mov r1, #2
 *   @0x129118 mov r5, r0
 *   @0x12911c mov r0, r4
 *   @0x129120 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129124 mov r1, r5
 *   @0x129128 mov r2, r0
 *   @0x12912c mov r0, r6
 *   @0x129130 pop {r4, r5, r6, lr}
 *   @0x129134 b 0x1a3278 <_Z18ParticleType_Scaleiff>
 *
 * ══ §78/438 F_PartTypeStep(RValue&, CInstance*, CInstance*, int, RValue*)  0x129180  size 72  18 条（0x129180..0x1291c8）
 * @func 0x129180 0x1291c8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129180 push {r4, r5, r6, lr}
 *   @0x129184 mov r1, #0
 *   @0x129188 ldr r4, [sp, #0x10]
 *   @0x12918c mov r0, r4
 *   @0x129190 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129194 mov r1, #1
 *   @0x129198 mov r6, r0
 *   @0x12919c mov r0, r4
 *   @0x1291a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1291a4 mov r1, #2
 *   @0x1291a8 mov r5, r0
 *   @0x1291ac mov r0, r4
 *   @0x1291b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1291b4 mov r1, r5
 *   @0x1291b8 mov r2, r0
 *   @0x1291bc mov r0, r6
 *   @0x1291c0 pop {r4, r5, r6, lr}
 *   @0x1291c4 b 0x1a32f0 <_Z17ParticleType_Stepiii>
 *
 * ══ §79/438 F_PartTypeDeath(RValue&, CInstance*, CInstance*, int, RValue*)  0x1291c8  size 72  18 条（0x1291c8..0x129210）
 * @func 0x1291c8 0x129210  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1291c8 push {r4, r5, r6, lr}
 *   @0x1291cc mov r1, #0
 *   @0x1291d0 ldr r4, [sp, #0x10]
 *   @0x1291d4 mov r0, r4
 *   @0x1291d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1291dc mov r1, #1
 *   @0x1291e0 mov r6, r0
 *   @0x1291e4 mov r0, r4
 *   @0x1291e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1291ec mov r1, #2
 *   @0x1291f0 mov r5, r0
 *   @0x1291f4 mov r0, r4
 *   @0x1291f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1291fc mov r1, r5
 *   @0x129200 mov r2, r0
 *   @0x129204 mov r0, r6
 *   @0x129208 pop {r4, r5, r6, lr}
 *   @0x12920c b 0x1a332c <_Z18ParticleType_Deathiii>
 *
 * ══ §80/438 F_PartTypeColorMix(RValue&, CInstance*, CInstance*, int, RValue*)  0x1293c4  size 72  18 条（0x1293c4..0x12940c）
 * @func 0x1293c4 0x12940c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1293c4 push {r4, r5, r6, lr}
 *   @0x1293c8 mov r1, #0
 *   @0x1293cc ldr r4, [sp, #0x10]
 *   @0x1293d0 mov r0, r4
 *   @0x1293d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1293d8 mov r1, #1
 *   @0x1293dc mov r6, r0
 *   @0x1293e0 mov r0, r4
 *   @0x1293e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1293e8 mov r1, #2
 *   @0x1293ec mov r5, r0
 *   @0x1293f0 mov r0, r4
 *   @0x1293f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1293f8 mov r1, r5
 *   @0x1293fc mov r2, r0
 *   @0x129400 mov r0, r6
 *   @0x129404 pop {r4, r5, r6, lr}
 *   @0x129408 b 0x1a34f4 <_Z22ParticleType_Color_Mixijj>
 *
 * ══ §81/438 F_PartTypeAlpha2(RValue&, CInstance*, CInstance*, int, RValue*)  0x129658  size 72  18 条（0x129658..0x1296a0）
 * @func 0x129658 0x1296a0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129658 push {r4, r5, r6, lr}
 *   @0x12965c mov r1, #0
 *   @0x129660 ldr r4, [sp, #0x10]
 *   @0x129664 mov r0, r4
 *   @0x129668 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12966c mov r1, #1
 *   @0x129670 mov r6, r0
 *   @0x129674 mov r0, r4
 *   @0x129678 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12967c mov r1, #2
 *   @0x129680 mov r5, r0
 *   @0x129684 mov r0, r4
 *   @0x129688 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12968c mov r1, r5
 *   @0x129690 mov r2, r0
 *   @0x129694 mov r0, r6
 *   @0x129698 pop {r4, r5, r6, lr}
 *   @0x12969c b 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *
 * ══ §82/438 F_PartSystemPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x1299cc  size 72  18 条（0x1299cc..0x129a14）
 * @func 0x1299cc 0x129a14  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1299cc push {r4, r5, r6, lr}
 *   @0x1299d0 mov r1, #0
 *   @0x1299d4 ldr r4, [sp, #0x10]
 *   @0x1299d8 mov r0, r4
 *   @0x1299dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1299e0 mov r1, #1
 *   @0x1299e4 mov r6, r0
 *   @0x1299e8 mov r0, r4
 *   @0x1299ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1299f0 mov r1, #2
 *   @0x1299f4 mov r5, r0
 *   @0x1299f8 mov r0, r4
 *   @0x1299fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129a00 mov r1, r5
 *   @0x129a04 mov r2, r0
 *   @0x129a08 mov r0, r6
 *   @0x129a0c pop {r4, r5, r6, lr}
 *   @0x129a10 b 0x1a4894 <_Z23ParticleSystem_Positioniff>
 *
 * ══ §83/438 F_SpriteGetNumber(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b388  size 72  18 条（0x12b388..0x12b3d0）
 * @func 0x12b388 0x12b3d0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b388 push {r4, lr}
 *   @0x12b38c mov r1, #0
 *   @0x12b390 mov r4, r0
 *   @0x12b394 ldr r0, [sp, #0x8]
 *   @0x12b398 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b39c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b3a0 mov r1, #0
 *   @0x12b3a4 cmp r0, #0
 *   @0x12b3a8 ldrne r2, [r0, #0x18]
 *   @0x12b3ac moveq r3, #0
 *   @0x12b3b0 moveq r2, #0
 *   @0x12b3b4 movteq r3, #0xbff0
 *   @0x12b3b8 str r1, [r4, #0xc]
 *   @0x12b3bc vmovne s15, r2
 *   @0x12b3c0 vcvtne.f64.s32 d7, s15
 *   @0x12b3c4 vmovne r2, r3, d7
 *   @0x12b3c8 stm r4, {r2, r3}
 *   @0x12b3cc pop {r4, pc}
 *
 * ══ §84/438 F_SpriteGetWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b3d0  size 72  18 条（0x12b3d0..0x12b418）
 * @func 0x12b3d0 0x12b418  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b3d0 push {r4, lr}
 *   @0x12b3d4 mov r1, #0
 *   @0x12b3d8 mov r4, r0
 *   @0x12b3dc ldr r0, [sp, #0x8]
 *   @0x12b3e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b3e4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b3e8 mov r1, #0
 *   @0x12b3ec cmp r0, #0
 *   @0x12b3f0 ldrne r2, [r0, #0x1c]
 *   @0x12b3f4 moveq r3, #0
 *   @0x12b3f8 moveq r2, #0
 *   @0x12b3fc movteq r3, #0xbff0
 *   @0x12b400 str r1, [r4, #0xc]
 *   @0x12b404 vmovne s15, r2
 *   @0x12b408 vcvtne.f64.s32 d7, s15
 *   @0x12b40c vmovne r2, r3, d7
 *   @0x12b410 stm r4, {r2, r3}
 *   @0x12b414 pop {r4, pc}
 *
 * ══ §85/438 F_SpriteGetHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b418  size 72  18 条（0x12b418..0x12b460）
 * @func 0x12b418 0x12b460  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b418 push {r4, lr}
 *   @0x12b41c mov r1, #0
 *   @0x12b420 mov r4, r0
 *   @0x12b424 ldr r0, [sp, #0x8]
 *   @0x12b428 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b42c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b430 mov r1, #0
 *   @0x12b434 cmp r0, #0
 *   @0x12b438 ldrne r2, [r0, #0x20]
 *   @0x12b43c moveq r3, #0
 *   @0x12b440 moveq r2, #0
 *   @0x12b444 movteq r3, #0xbff0
 *   @0x12b448 str r1, [r4, #0xc]
 *   @0x12b44c vmovne s15, r2
 *   @0x12b450 vcvtne.f64.s32 d7, s15
 *   @0x12b454 vmovne r2, r3, d7
 *   @0x12b458 stm r4, {r2, r3}
 *   @0x12b45c pop {r4, pc}
 *
 * ══ §86/438 F_SpriteGetTransparent(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b460  size 72  18 条（0x12b460..0x12b4a8）
 * @func 0x12b460 0x12b4a8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b460 push {r4, lr}
 *   @0x12b464 mov r1, #0
 *   @0x12b468 mov r4, r0
 *   @0x12b46c ldr r0, [sp, #0x8]
 *   @0x12b470 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b474 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b478 mov r1, #0
 *   @0x12b47c cmp r0, #0
 *   @0x12b480 ldrbne r2, [r0, #0x32]
 *   @0x12b484 moveq r3, #0
 *   @0x12b488 moveq r2, #0
 *   @0x12b48c movteq r3, #0xbff0
 *   @0x12b490 str r1, [r4, #0xc]
 *   @0x12b494 vmovne s15, r2
 *   @0x12b498 vcvtne.f64.s32 d7, s15
 *   @0x12b49c vmovne r2, r3, d7
 *   @0x12b4a0 stm r4, {r2, r3}
 *   @0x12b4a4 pop {r4, pc}
 *
 * ══ §87/438 F_SpriteGetSmooth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b4a8  size 72  18 条（0x12b4a8..0x12b4f0）
 * @func 0x12b4a8 0x12b4f0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b4a8 push {r4, lr}
 *   @0x12b4ac mov r1, #0
 *   @0x12b4b0 mov r4, r0
 *   @0x12b4b4 ldr r0, [sp, #0x8]
 *   @0x12b4b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b4bc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b4c0 mov r1, #0
 *   @0x12b4c4 cmp r0, #0
 *   @0x12b4c8 ldrbne r2, [r0, #0x33]
 *   @0x12b4cc moveq r3, #0
 *   @0x12b4d0 moveq r2, #0
 *   @0x12b4d4 movteq r3, #0xbff0
 *   @0x12b4d8 str r1, [r4, #0xc]
 *   @0x12b4dc vmovne s15, r2
 *   @0x12b4e0 vcvtne.f64.s32 d7, s15
 *   @0x12b4e4 vmovne r2, r3, d7
 *   @0x12b4e8 stm r4, {r2, r3}
 *   @0x12b4ec pop {r4, pc}
 *
 * ══ §88/438 F_SpriteGetPreload(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b4f0  size 72  18 条（0x12b4f0..0x12b538）
 * @func 0x12b4f0 0x12b538  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b4f0 push {r4, lr}
 *   @0x12b4f4 mov r1, #0
 *   @0x12b4f8 mov r4, r0
 *   @0x12b4fc ldr r0, [sp, #0x8]
 *   @0x12b500 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b504 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b508 mov r1, #0
 *   @0x12b50c cmp r0, #0
 *   @0x12b510 ldrbne r2, [r0, #0x34]
 *   @0x12b514 moveq r3, #0
 *   @0x12b518 moveq r2, #0
 *   @0x12b51c movteq r3, #0xbff0
 *   @0x12b520 str r1, [r4, #0xc]
 *   @0x12b524 vmovne s15, r2
 *   @0x12b528 vcvtne.f64.s32 d7, s15
 *   @0x12b52c vmovne r2, r3, d7
 *   @0x12b530 stm r4, {r2, r3}
 *   @0x12b534 pop {r4, pc}
 *
 * ══ §89/438 F_SpriteGetXoffset(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b538  size 72  18 条（0x12b538..0x12b580）
 * @func 0x12b538 0x12b580  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b538 push {r4, lr}
 *   @0x12b53c mov r1, #0
 *   @0x12b540 mov r4, r0
 *   @0x12b544 ldr r0, [sp, #0x8]
 *   @0x12b548 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b54c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b550 mov r1, #0
 *   @0x12b554 cmp r0, #0
 *   @0x12b558 ldrne r2, [r0, #0x24]
 *   @0x12b55c moveq r3, #0
 *   @0x12b560 moveq r2, #0
 *   @0x12b564 movteq r3, #0xbff0
 *   @0x12b568 str r1, [r4, #0xc]
 *   @0x12b56c vmovne s15, r2
 *   @0x12b570 vcvtne.f64.s32 d7, s15
 *   @0x12b574 vmovne r2, r3, d7
 *   @0x12b578 stm r4, {r2, r3}
 *   @0x12b57c pop {r4, pc}
 *
 * ══ §90/438 F_SpriteGetYoffset(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b580  size 72  18 条（0x12b580..0x12b5c8）
 * @func 0x12b580 0x12b5c8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b580 push {r4, lr}
 *   @0x12b584 mov r1, #0
 *   @0x12b588 mov r4, r0
 *   @0x12b58c ldr r0, [sp, #0x8]
 *   @0x12b590 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b594 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b598 mov r1, #0
 *   @0x12b59c cmp r0, #0
 *   @0x12b5a0 ldrne r2, [r0, #0x28]
 *   @0x12b5a4 moveq r3, #0
 *   @0x12b5a8 moveq r2, #0
 *   @0x12b5ac movteq r3, #0xbff0
 *   @0x12b5b0 str r1, [r4, #0xc]
 *   @0x12b5b4 vmovne s15, r2
 *   @0x12b5b8 vcvtne.f64.s32 d7, s15
 *   @0x12b5bc vmovne r2, r3, d7
 *   @0x12b5c0 stm r4, {r2, r3}
 *   @0x12b5c4 pop {r4, pc}
 *
 * ══ §91/438 F_SpriteGetBboxMode(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b5c8  size 72  18 条（0x12b5c8..0x12b610）
 * @func 0x12b5c8 0x12b610  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b5c8 push {r4, lr}
 *   @0x12b5cc mov r1, #0
 *   @0x12b5d0 mov r4, r0
 *   @0x12b5d4 ldr r0, [sp, #0x8]
 *   @0x12b5d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b5dc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b5e0 mov r1, #0
 *   @0x12b5e4 cmp r0, #0
 *   @0x12b5e8 ldrne r2, [r0, #0x4]
 *   @0x12b5ec moveq r3, #0
 *   @0x12b5f0 moveq r2, #0
 *   @0x12b5f4 movteq r3, #0xbff0
 *   @0x12b5f8 str r1, [r4, #0xc]
 *   @0x12b5fc vmovne s15, r2
 *   @0x12b600 vcvtne.f64.s32 d7, s15
 *   @0x12b604 vmovne r2, r3, d7
 *   @0x12b608 stm r4, {r2, r3}
 *   @0x12b60c pop {r4, pc}
 *
 * ══ §92/438 F_SpriteGetPrecise(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b610  size 72  18 条（0x12b610..0x12b658）
 * @func 0x12b610 0x12b658  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b610 push {r4, lr}
 *   @0x12b614 mov r1, #0
 *   @0x12b618 mov r4, r0
 *   @0x12b61c ldr r0, [sp, #0x8]
 *   @0x12b620 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b624 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b628 mov r1, #0
 *   @0x12b62c cmp r0, #0
 *   @0x12b630 ldrbne r2, [r0, #0x30]
 *   @0x12b634 moveq r3, #0
 *   @0x12b638 moveq r2, #0
 *   @0x12b63c movteq r3, #0xbff0
 *   @0x12b640 str r1, [r4, #0xc]
 *   @0x12b644 vmovne s15, r2
 *   @0x12b648 vcvtne.f64.s32 d7, s15
 *   @0x12b64c vmovne r2, r3, d7
 *   @0x12b650 stm r4, {r2, r3}
 *   @0x12b654 pop {r4, pc}
 *
 * ══ §93/438 F_SpriteGetBboxLeft(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b658  size 72  18 条（0x12b658..0x12b6a0）
 * @func 0x12b658 0x12b6a0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b658 push {r4, lr}
 *   @0x12b65c mov r1, #0
 *   @0x12b660 mov r4, r0
 *   @0x12b664 ldr r0, [sp, #0x8]
 *   @0x12b668 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b66c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b670 mov r1, #0
 *   @0x12b674 cmp r0, #0
 *   @0x12b678 ldrne r2, [r0, #0x8]
 *   @0x12b67c moveq r3, #0
 *   @0x12b680 moveq r2, #0
 *   @0x12b684 movteq r3, #0xbff0
 *   @0x12b688 str r1, [r4, #0xc]
 *   @0x12b68c vmovne s15, r2
 *   @0x12b690 vcvtne.f64.s32 d7, s15
 *   @0x12b694 vmovne r2, r3, d7
 *   @0x12b698 stm r4, {r2, r3}
 *   @0x12b69c pop {r4, pc}
 *
 * ══ §94/438 F_SpriteGetBboxRight(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b6a0  size 72  18 条（0x12b6a0..0x12b6e8）
 * @func 0x12b6a0 0x12b6e8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b6a0 push {r4, lr}
 *   @0x12b6a4 mov r1, #0
 *   @0x12b6a8 mov r4, r0
 *   @0x12b6ac ldr r0, [sp, #0x8]
 *   @0x12b6b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b6b4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b6b8 mov r1, #0
 *   @0x12b6bc cmp r0, #0
 *   @0x12b6c0 ldrne r2, [r0, #0x10]
 *   @0x12b6c4 moveq r3, #0
 *   @0x12b6c8 moveq r2, #0
 *   @0x12b6cc movteq r3, #0xbff0
 *   @0x12b6d0 str r1, [r4, #0xc]
 *   @0x12b6d4 vmovne s15, r2
 *   @0x12b6d8 vcvtne.f64.s32 d7, s15
 *   @0x12b6dc vmovne r2, r3, d7
 *   @0x12b6e0 stm r4, {r2, r3}
 *   @0x12b6e4 pop {r4, pc}
 *
 * ══ §95/438 F_SpriteGetBboxTop(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b6e8  size 72  18 条（0x12b6e8..0x12b730）
 * @func 0x12b6e8 0x12b730  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b6e8 push {r4, lr}
 *   @0x12b6ec mov r1, #0
 *   @0x12b6f0 mov r4, r0
 *   @0x12b6f4 ldr r0, [sp, #0x8]
 *   @0x12b6f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b6fc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b700 mov r1, #0
 *   @0x12b704 cmp r0, #0
 *   @0x12b708 ldrne r2, [r0, #0xc]
 *   @0x12b70c moveq r3, #0
 *   @0x12b710 moveq r2, #0
 *   @0x12b714 movteq r3, #0xbff0
 *   @0x12b718 str r1, [r4, #0xc]
 *   @0x12b71c vmovne s15, r2
 *   @0x12b720 vcvtne.f64.s32 d7, s15
 *   @0x12b724 vmovne r2, r3, d7
 *   @0x12b728 stm r4, {r2, r3}
 *   @0x12b72c pop {r4, pc}
 *
 * ══ §96/438 F_SpriteGetBboxBottom(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b730  size 72  18 条（0x12b730..0x12b778）
 * @func 0x12b730 0x12b778  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b730 push {r4, lr}
 *   @0x12b734 mov r1, #0
 *   @0x12b738 mov r4, r0
 *   @0x12b73c ldr r0, [sp, #0x8]
 *   @0x12b740 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b744 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b748 mov r1, #0
 *   @0x12b74c cmp r0, #0
 *   @0x12b750 ldrne r2, [r0, #0x14]
 *   @0x12b754 moveq r3, #0
 *   @0x12b758 moveq r2, #0
 *   @0x12b75c movteq r3, #0xbff0
 *   @0x12b760 str r1, [r4, #0xc]
 *   @0x12b764 vmovne s15, r2
 *   @0x12b768 vcvtne.f64.s32 d7, s15
 *   @0x12b76c vmovne r2, r3, d7
 *   @0x12b770 stm r4, {r2, r3}
 *   @0x12b774 pop {r4, pc}
 *
 * ══ §97/438 F_SoundGetKind(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cca8  size 72  18 条（0x12cca8..0x12ccf0）
 * @func 0x12cca8 0x12ccf0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sound_Data(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cca8 push {r4, lr}
 *   @0x12ccac mov r1, #0
 *   @0x12ccb0 mov r4, r0
 *   @0x12ccb4 ldr r0, [sp, #0x8]
 *   @0x12ccb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ccbc bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x12ccc0 mov r1, #0
 *   @0x12ccc4 cmp r0, #0
 *   @0x12ccc8 ldrne r2, [r0, #0x4]
 *   @0x12cccc moveq r3, #0
 *   @0x12ccd0 moveq r2, #0
 *   @0x12ccd4 movteq r3, #0xbff0
 *   @0x12ccd8 str r1, [r4, #0xc]
 *   @0x12ccdc vmovne s15, r2
 *   @0x12cce0 vcvtne.f64.s32 d7, s15
 *   @0x12cce4 vmovne r2, r3, d7
 *   @0x12cce8 stm r4, {r2, r3}
 *   @0x12ccec pop {r4, pc}
 *
 * ══ §98/438 F_SpriteSetBboxMode(RValue&, CInstance*, CInstance*, int, RValue*)  0x130da4  size 72  18 条（0x130da4..0x130dec）
 * @func 0x130da4 0x130dec  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int) / CSprite::SetBoundingBoxMode(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130da4 push {r4, r5, r6, lr}
 *   @0x130da8 mov r1, #0
 *   @0x130dac ldr r4, [sp, #0x10]
 *   @0x130db0 mov r0, r4
 *   @0x130db4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130db8 mov r5, r0
 *   @0x130dbc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x130dc0 subs r6, r0, #0
 *   @0x130dc4 popeq {r4, r5, r6, pc}
 *   @0x130dc8 mov r0, r4
 *   @0x130dcc mov r1, #1
 *   @0x130dd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130dd4 mov r1, r0
 *   @0x130dd8 mov r0, r6
 *   @0x130ddc bl 0x1e35c8 <_ZN7CSprite18SetBoundingBoxModeEi>
 *   @0x130de0 mov r0, r5
 *   @0x130de4 pop {r4, r5, r6, lr}
 *   @0x130de8 b 0x130cac <_Z20MarkInstancesAsDirtyi>
 *
 * ══ §99/438 F_AudioPlayMusic(RValue&, CInstance*, CInstance*, int, RValue*)  0x133954  size 72  18 条（0x133954..0x13399c）
 * @func 0x133954 0x13399c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133954 push {r3, lr}
 *   @0x133958 ldr r3, [pc, #0x30]
 *   @0x13395c ldr r3, [pc, r3]
 *   @0x133960 ldrb r3, [r3]
 *   @0x133964 cmp r3, #0
 *   @0x133968 popne {r3, pc}
 *   @0x13396c ldr r3, [pc, #0x20]
 *   @0x133970 ldr r1, [pc, #0x20]
 *   @0x133974 ldr r3, [pc, r3]
 *   @0x133978 add r1, pc, r1
 *   @0x13397c ldr r0, [r3]
 *   @0x133980 ldr r3, [r0]
 *   @0x133984 ldr r3, [r3, #0xc]
 *   @0x133988 blx r3
 *   @0x13398c pop {r3, pc}
 *   @0x133990 .word 0x002bb6f0
 *   @0x133994 eoreq r9, r11, r0, lsr #27
 *   @0x133998 eoreq r11, r0, r8, lsl #20
 *
 * ══ §100/438 F_AudioStopMusic(RValue&, CInstance*, CInstance*, int, RValue*)  0x13399c  size 72  18 条（0x13399c..0x1339e4）
 * @func 0x13399c 0x1339e4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13399c push {r3, lr}
 *   @0x1339a0 ldr r3, [pc, #0x30]
 *   @0x1339a4 ldr r3, [pc, r3]
 *   @0x1339a8 ldrb r3, [r3]
 *   @0x1339ac cmp r3, #0
 *   @0x1339b0 popne {r3, pc}
 *   @0x1339b4 ldr r3, [pc, #0x20]
 *   @0x1339b8 ldr r1, [pc, #0x20]
 *   @0x1339bc ldr r3, [pc, r3]
 *   @0x1339c0 add r1, pc, r1
 *   @0x1339c4 ldr r0, [r3]
 *   @0x1339c8 ldr r3, [r0]
 *   @0x1339cc ldr r3, [r3, #0xc]
 *   @0x1339d0 blx r3
 *   @0x1339d4 pop {r3, pc}
 *   @0x1339d8 eoreq r11, r11, r8, lsr #13
 *   @0x1339dc eoreq r9, r11, r8, asr sp
 *   @0x1339e0 eoreq r11, r0, r12, ror #19
 *
 * ══ §101/438 F_AudioPauseMusic(RValue&, CInstance*, CInstance*, int, RValue*)  0x1339e4  size 72  18 条（0x1339e4..0x133a2c）
 * @func 0x1339e4 0x133a2c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1339e4 push {r3, lr}
 *   @0x1339e8 ldr r3, [pc, #0x30]
 *   @0x1339ec ldr r3, [pc, r3]
 *   @0x1339f0 ldrb r3, [r3]
 *   @0x1339f4 cmp r3, #0
 *   @0x1339f8 popne {r3, pc}
 *   @0x1339fc ldr r3, [pc, #0x20]
 *   @0x133a00 ldr r1, [pc, #0x20]
 *   @0x133a04 ldr r3, [pc, r3]
 *   @0x133a08 add r1, pc, r1
 *   @0x133a0c ldr r0, [r3]
 *   @0x133a10 ldr r3, [r0]
 *   @0x133a14 ldr r3, [r3, #0xc]
 *   @0x133a18 blx r3
 *   @0x133a1c pop {r3, pc}
 *   @0x133a20 eoreq r11, r11, r0, ror #12
 *   @0x133a24 eoreq r9, r11, r0, lsl sp
 *   @0x133a28 .word 0x0020b9d0
 *
 * ══ §102/438 F_AudioResumeMusic(RValue&, CInstance*, CInstance*, int, RValue*)  0x133a2c  size 72  18 条（0x133a2c..0x133a74）
 * @func 0x133a2c 0x133a74  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133a2c push {r3, lr}
 *   @0x133a30 ldr r3, [pc, #0x30]
 *   @0x133a34 ldr r3, [pc, r3]
 *   @0x133a38 ldrb r3, [r3]
 *   @0x133a3c cmp r3, #0
 *   @0x133a40 popne {r3, pc}
 *   @0x133a44 ldr r3, [pc, #0x20]
 *   @0x133a48 ldr r1, [pc, #0x20]
 *   @0x133a4c ldr r3, [pc, r3]
 *   @0x133a50 add r1, pc, r1
 *   @0x133a54 ldr r0, [r3]
 *   @0x133a58 ldr r3, [r0]
 *   @0x133a5c ldr r3, [r3, #0xc]
 *   @0x133a60 blx r3
 *   @0x133a64 pop {r3, pc}
 *   @0x133a68 eoreq r11, r11, r8, lsl r6
 *   @0x133a6c eoreq r9, r11, r8, asr #25
 *   @0x133a70 .word 0x0020b9b4
 *
 * ══ §103/438 F_AudioMusicGain(RValue&, CInstance*, CInstance*, int, RValue*)  0x133acc  size 72  18 条（0x133acc..0x133b14）
 * @func 0x133acc 0x133b14  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133acc push {r3, lr}
 *   @0x133ad0 ldr r3, [pc, #0x30]
 *   @0x133ad4 ldr r3, [pc, r3]
 *   @0x133ad8 ldrb r3, [r3]
 *   @0x133adc cmp r3, #0
 *   @0x133ae0 popne {r3, pc}
 *   @0x133ae4 ldr r3, [pc, #0x20]
 *   @0x133ae8 ldr r1, [pc, #0x20]
 *   @0x133aec ldr r3, [pc, r3]
 *   @0x133af0 add r1, pc, r1
 *   @0x133af4 ldr r0, [r3]
 *   @0x133af8 ldr r3, [r0]
 *   @0x133afc ldr r3, [r3, #0xc]
 *   @0x133b00 blx r3
 *   @0x133b04 pop {r3, pc}
 *   @0x133b08 eoreq r11, r11, r8, ror r5
 *   @0x133b0c eoreq r9, r11, r8, lsr #24
 *   @0x133b10 eoreq r11, r0, r0, ror r9
 *
 * ══ §104/438 F_AudioSoundPitch(RValue&, CInstance*, CInstance*, int, RValue*)  0x135214  size 72  18 条（0x135214..0x13525c）
 * @func 0x135214 0x13525c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x38×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135214 push {r3, r4, r5, lr}
 *   @0x135218 ldr r3, [pc, #0x38]
 *   @0x13521c ldr r4, [sp, #0x10]
 *   @0x135220 ldr r3, [pc, r3]
 *   @0x135224 ldrb r1, [r3]
 *   @0x135228 cmp r1, #0
 *   @0x13522c popne {r3, r4, r5, pc}
 *   @0x135230 mov r0, r4
 *   @0x135234 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135238 mov r1, #1
 *   @0x13523c mov r5, r0
 *   @0x135240 mov r0, r4
 *   @0x135244 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x135248 mov r1, r0
 *   @0x13524c mov r0, r5
 *   @0x135250 pop {r3, r4, r5, lr}
 *   @0x135254 b 0x217460 <_Z16Audio_SoundPitchif>
 *   @0x135258 eoreq r9, r11, r12, lsr #28
 *
 * ══ §105/438 F_AudioSetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*)  0x1356d4  size 72  18 条（0x1356d4..0x13571c）
 * @func 0x1356d4 0x13571c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x38×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1356d4 push {r3, r4, r5, lr}
 *   @0x1356d8 ldr r3, [pc, #0x38]
 *   @0x1356dc ldr r4, [sp, #0x10]
 *   @0x1356e0 ldr r3, [pc, r3]
 *   @0x1356e4 ldrb r1, [r3]
 *   @0x1356e8 cmp r1, #0
 *   @0x1356ec popne {r3, r4, r5, pc}
 *   @0x1356f0 mov r0, r4
 *   @0x1356f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1356f8 mov r1, #1
 *   @0x1356fc mov r5, r0
 *   @0x135700 mov r0, r4
 *   @0x135704 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x135708 mov r1, r0
 *   @0x13570c mov r0, r5
 *   @0x135710 pop {r3, r4, r5, lr}
 *   @0x135714 b 0x2187ac <_Z17Audio_SetTrackPosif>
 *   @0x135718 eoreq r9, r11, r12, ror #18
 *
 * ══ §106/438 F_Audio_GroupLoadProgress(RValue&, CInstance*, CInstance*, int, RValue*)  0x135894  size 72  18 条（0x135894..0x1358dc）
 * @func 0x135894 0x1358dc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CAudioGroupMan::GetLoadProgress(int)
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135894 ldr r3, [pc, #0x38]
 *   @0x135898 push {r4, lr}
 *   @0x13589c ldr r3, [pc, r3]
 *   @0x1358a0 mov r4, r0
 *   @0x1358a4 ldrb r1, [r3]
 *   @0x1358a8 cmp r1, #0
 *   @0x1358ac popne {r4, pc}
 *   @0x1358b0 str r1, [r0, #0xc]
 *   @0x1358b4 ldr r0, [sp, #0x8]
 *   @0x1358b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1358bc ldr r3, [pc, #0x14]
 *   @0x1358c0 mov r1, r0
 *   @0x1358c4 ldr r0, [pc, r3]
 *   @0x1358c8 bl 0x21e218 <_ZN14CAudioGroupMan15GetLoadProgressEi>
 *   @0x1358cc stm r4, {r0, r1}
 *   @0x1358d0 pop {r4, pc}
 *   @0x1358d4 .word 0x002b97b0
 *   @0x1358d8 eoreq r9, r11, r12, lsl #15
 *
 * ══ §107/438 F_AudioSoundSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x135d40  size 72  18 条（0x135d40..0x135d88）
 * @func 0x135d40 0x135d88  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x38×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135d40 push {r3, r4, r5, lr}
 *   @0x135d44 ldr r3, [pc, #0x38]
 *   @0x135d48 ldr r4, [sp, #0x10]
 *   @0x135d4c ldr r3, [pc, r3]
 *   @0x135d50 ldrb r1, [r3]
 *   @0x135d54 cmp r1, #0
 *   @0x135d58 popne {r3, r4, r5, pc}
 *   @0x135d5c mov r0, r4
 *   @0x135d60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135d64 mov r1, #1
 *   @0x135d68 mov r5, r0
 *   @0x135d6c mov r0, r4
 *   @0x135d70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135d74 mov r1, r0
 *   @0x135d78 mov r0, r5
 *   @0x135d7c pop {r3, r4, r5, lr}
 *   @0x135d80 b 0x218444 <_Z26Audio_SoundSetListenerMaskij>
 *   @0x135d84 eoreq r9, r11, r0, lsl #6
 *
 * ══ §108/438 F_AudioEmitterSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x135dd4  size 72  18 条（0x135dd4..0x135e1c）
 * @func 0x135dd4 0x135e1c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x38×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135dd4 push {r3, r4, r5, lr}
 *   @0x135dd8 ldr r3, [pc, #0x38]
 *   @0x135ddc ldr r4, [sp, #0x10]
 *   @0x135de0 ldr r3, [pc, r3]
 *   @0x135de4 ldrb r1, [r3]
 *   @0x135de8 cmp r1, #0
 *   @0x135dec popne {r3, r4, r5, pc}
 *   @0x135df0 mov r0, r4
 *   @0x135df4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135df8 mov r1, #1
 *   @0x135dfc mov r5, r0
 *   @0x135e00 mov r0, r4
 *   @0x135e04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135e08 mov r1, r0
 *   @0x135e0c mov r0, r5
 *   @0x135e10 pop {r3, r4, r5, lr}
 *   @0x135e14 b 0x218520 <_Z28Audio_EmitterSetListenerMaskij>
 *   @0x135e18 eoreq r9, r11, r12, ror #4
 *
 * ══ §109/438 F_ParameterString(RValue&, CInstance*, CInstance*, int, RValue*)  0x13c440  size 72  18 条（0x13c440..0x13c488）
 * @func 0x13c440 0x13c488  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / ParamStr(char const*&, int) / YYCreateString(RValue*, char const*) / YYFree(void const*)
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c440 push {r4, r5, lr}
 *   @0x13c444 sub sp, sp, #12
 *   @0x13c448 add r4, sp, #8
 *   @0x13c44c mov r1, #0
 *   @0x13c450 mov r5, r0
 *   @0x13c454 ldr r0, [sp, #0x18]
 *   @0x13c458 str r1, [r4, #-0x4]!
 *   @0x13c45c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13c460 mov r1, r0
 *   @0x13c464 mov r0, r4
 *   @0x13c468 bl 0x13c3f0 <_Z8ParamStrRPKci>
 *   @0x13c46c mov r0, r5
 *   @0x13c470 ldr r1, [sp, #0x4]
 *   @0x13c474 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x13c478 ldr r0, [sp, #0x4]
 *   @0x13c47c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x13c480 add sp, sp, #12
 *   @0x13c484 pop {r4, r5, pc}
 *
 * ══ §110/438 json_parse_array(json_object*, char*)  0x13d274  size 72  18 条（0x13d274..0x13d2bc）
 * @func 0x13d274 0x13d2bc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CDS_List::CDS_List() / json_parse_array_to_list(json_object*, char*, CDS_List*) / FindFreeDsListIndex()
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d274 push {r4, r5, r6, lr}
 *   @0x13d278 mov r5, r0
 *   @0x13d27c mov r0, #16
 *   @0x13d280 mov r6, r1
 *   @0x13d284 bl 0x27c524 <_Znwj>
 *   @0x13d288 mov r4, r0
 *   @0x13d28c bl 0x202ff8 <_ZN8CDS_ListC2Ev>
 *   @0x13d290 mov r0, r5
 *   @0x13d294 mov r1, r6
 *   @0x13d298 mov r2, r4
 *   @0x13d29c bl 0x13d140 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List>
 *   @0x13d2a0 bl 0xfff10 <_Z19FindFreeDsListIndexv>
 *   @0x13d2a4 ldr r3, [pc, #0xc]
 *   @0x13d2a8 ldr r3, [pc, r3]
 *   @0x13d2ac ldr r3, [r3, #0x4]
 *   @0x13d2b0 str r4, [r3, r0, lsl #2]
 *   @0x13d2b4 pop {r4, r5, r6, pc}
 *   @0x13d2b8 .word 0x002b09d8
 *
 * ══ §111/438 F_D3DVertex(RValue&, CInstance*, CInstance*, int, RValue*)  0x143c8c  size 72  18 条（0x143c8c..0x143cd4）
 * @func 0x143c8c 0x143cd4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143c8c push {r4, r5, r6, lr}
 *   @0x143c90 mov r1, #0
 *   @0x143c94 ldr r4, [sp, #0x10]
 *   @0x143c98 mov r0, r4
 *   @0x143c9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143ca0 mov r1, #1
 *   @0x143ca4 mov r6, r0
 *   @0x143ca8 mov r0, r4
 *   @0x143cac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143cb0 mov r1, #2
 *   @0x143cb4 mov r5, r0
 *   @0x143cb8 mov r0, r4
 *   @0x143cbc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143cc0 mov r1, r5
 *   @0x143cc4 mov r2, r0
 *   @0x143cc8 mov r0, r6
 *   @0x143ccc pop {r4, r5, r6, lr}
 *   @0x143cd0 b 0x176e2c <_Z12GR_3D_Vertexfff>
 *
 * ══ §112/438 F_D3DTransformSetTranslation(RValue&, CInstance*, CInstance*, int, RValue*)  0x144e54  size 72  18 条（0x144e54..0x144e9c）
 * @func 0x144e54 0x144e9c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144e54 push {r4, r5, r6, lr}
 *   @0x144e58 mov r1, #0
 *   @0x144e5c ldr r4, [sp, #0x10]
 *   @0x144e60 mov r0, r4
 *   @0x144e64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144e68 mov r1, #1
 *   @0x144e6c mov r6, r0
 *   @0x144e70 mov r0, r4
 *   @0x144e74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144e78 mov r1, #2
 *   @0x144e7c mov r5, r0
 *   @0x144e80 mov r0, r4
 *   @0x144e84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144e88 mov r1, r5
 *   @0x144e8c mov r2, r0
 *   @0x144e90 mov r0, r6
 *   @0x144e94 pop {r4, r5, r6, lr}
 *   @0x144e98 b 0x163704 <_Z31GR_3D_Transform_Set_Translationfff>
 *
 * ══ §113/438 F_D3DTransformSetScaling(RValue&, CInstance*, CInstance*, int, RValue*)  0x144e9c  size 72  18 条（0x144e9c..0x144ee4）
 * @func 0x144e9c 0x144ee4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144e9c push {r4, r5, r6, lr}
 *   @0x144ea0 mov r1, #0
 *   @0x144ea4 ldr r4, [sp, #0x10]
 *   @0x144ea8 mov r0, r4
 *   @0x144eac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144eb0 mov r1, #1
 *   @0x144eb4 mov r6, r0
 *   @0x144eb8 mov r0, r4
 *   @0x144ebc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144ec0 mov r1, #2
 *   @0x144ec4 mov r5, r0
 *   @0x144ec8 mov r0, r4
 *   @0x144ecc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144ed0 mov r1, r5
 *   @0x144ed4 mov r2, r0
 *   @0x144ed8 mov r0, r6
 *   @0x144edc pop {r4, r5, r6, lr}
 *   @0x144ee0 b 0x16376c <_Z27GR_3D_Transform_Set_Scalingfff>
 *
 * ══ §114/438 F_D3DTransformAddTranslation(RValue&, CInstance*, CInstance*, int, RValue*)  0x144f88  size 72  18 条（0x144f88..0x144fd0）
 * @func 0x144f88 0x144fd0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144f88 push {r4, r5, r6, lr}
 *   @0x144f8c mov r1, #0
 *   @0x144f90 ldr r4, [sp, #0x10]
 *   @0x144f94 mov r0, r4
 *   @0x144f98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144f9c mov r1, #1
 *   @0x144fa0 mov r6, r0
 *   @0x144fa4 mov r0, r4
 *   @0x144fa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144fac mov r1, #2
 *   @0x144fb0 mov r5, r0
 *   @0x144fb4 mov r0, r4
 *   @0x144fb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144fbc mov r1, r5
 *   @0x144fc0 mov r2, r0
 *   @0x144fc4 mov r0, r6
 *   @0x144fc8 pop {r4, r5, r6, lr}
 *   @0x144fcc b 0x163898 <_Z31GR_3D_Transform_Add_Translationfff>
 *
 * ══ §115/438 F_D3DTransformAddScaling(RValue&, CInstance*, CInstance*, int, RValue*)  0x144fd0  size 72  18 条（0x144fd0..0x145018）
 * @func 0x144fd0 0x145018  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144fd0 push {r4, r5, r6, lr}
 *   @0x144fd4 mov r1, #0
 *   @0x144fd8 ldr r4, [sp, #0x10]
 *   @0x144fdc mov r0, r4
 *   @0x144fe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144fe4 mov r1, #1
 *   @0x144fe8 mov r6, r0
 *   @0x144fec mov r0, r4
 *   @0x144ff0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144ff4 mov r1, #2
 *   @0x144ff8 mov r5, r0
 *   @0x144ffc mov r0, r4
 *   @0x145000 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145004 mov r1, r5
 *   @0x145008 mov r2, r0
 *   @0x14500c mov r0, r6
 *   @0x145010 pop {r4, r5, r6, lr}
 *   @0x145014 b 0x163924 <_Z27GR_3D_Transform_Add_Scalingfff>
 *
 * ══ §116/438 F_IAP_ProductPurchased(RValue&, CInstance*, CInstance*, int, RValue*)  0x153234  size 72  18 条（0x153234..0x15327c）
 * @func 0x153234 0x15327c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / anon_153020+0x12c
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x153234 cmp r3, #0
 *   @0x153238 push {r3, r4, r5, lr}
 *   @0x15323c mov r5, #0
 *   @0x153240 mov r4, r0
 *   @0x153244 str r5, [r0, #0xc]
 *   @0x153248 str r5, [r0]
 *   @0x15324c str r5, [r0, #0x4]
 *   @0x153250 pople {r3, r4, r5, pc}
 *   @0x153254 mov r1, r5
 *   @0x153258 ldr r0, [sp, #0x10]
 *   @0x15325c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x153260 bl 0x15314c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x153264 mov r3, r5
 *   @0x153268 str r5, [r4]
 *   @0x15326c cmp r0, r5
 *   @0x153270 movtge r3, #0x3ff0
 *   @0x153274 str r3, [r4, #0x4]
 *   @0x153278 pop {r3, r4, r5, pc}
 *
 * ══ §117/438 F_YoYo_AchievementsShow(RValue&, CInstance*, CInstance*, int, RValue*)  0x1565c0  size 72  18 条（0x1565c0..0x156608）
 * @func 0x1565c0 0x156608  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1565c0 push {r4, r5, r6, lr}
 *   @0x1565c4 mov r1, #0
 *   @0x1565c8 ldr r4, [sp, #0x10]
 *   @0x1565cc mov r0, r4
 *   @0x1565d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1565d4 mov r1, #1
 *   @0x1565d8 mov r6, r0
 *   @0x1565dc mov r0, r4
 *   @0x1565e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1565e4 mov r1, #2
 *   @0x1565e8 mov r5, r0
 *   @0x1565ec mov r0, r4
 *   @0x1565f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1565f4 mov r1, r5
 *   @0x1565f8 mov r2, r0
 *   @0x1565fc mov r0, r6
 *   @0x156600 pop {r4, r5, r6, lr}
 *   @0x156604 b 0x16100c <_Z16Achievement_ShowiPci>
 *
 * ══ §118/438 F_YoYo_AchievementShowChallengeNotifications(RValue&, CInstance*, CInstance*, int, RValue*)  0x156758  size 72  18 条（0x156758..0x1567a0）
 * @func 0x156758 0x1567a0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156758 push {r4, r5, r6, lr}
 *   @0x15675c mov r1, #0
 *   @0x156760 ldr r4, [sp, #0x10]
 *   @0x156764 mov r0, r4
 *   @0x156768 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15676c mov r1, #0
 *   @0x156770 mov r6, r0
 *   @0x156774 mov r0, r4
 *   @0x156778 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15677c mov r1, #2
 *   @0x156780 mov r5, r0
 *   @0x156784 mov r0, r4
 *   @0x156788 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15678c mov r1, r5
 *   @0x156790 mov r2, r0
 *   @0x156794 mov r0, r6
 *   @0x156798 pop {r4, r5, r6, lr}
 *   @0x15679c b 0x161070 <_Z40Achievement_Show_Challenge_Notificationsiii>
 *
 * ══ §119/438 F_YoYo_EnableAdsEx(RValue&, CInstance*, CInstance*, int, RValue*)  0x156e10  size 72  18 条（0x156e10..0x156e58）
 * @func 0x156e10 0x156e58  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156e10 push {r4, r5, r6, lr}
 *   @0x156e14 mov r1, #0
 *   @0x156e18 ldr r4, [sp, #0x10]
 *   @0x156e1c mov r0, r4
 *   @0x156e20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156e24 mov r1, #1
 *   @0x156e28 mov r6, r0
 *   @0x156e2c mov r0, r4
 *   @0x156e30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156e34 mov r1, #2
 *   @0x156e38 mov r5, r0
 *   @0x156e3c mov r0, r4
 *   @0x156e40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156e44 mov r1, r5
 *   @0x156e48 mov r2, r0
 *   @0x156e4c mov r0, r6
 *   @0x156e50 pop {r4, r5, r6, lr}
 *   @0x156e54 b 0x15e390 <_Z15EnableAdServingiii>
 *
 * ══ §120/438 F_YoYo_OF_SendChallenge(RValue&, CInstance*, CInstance*, int, RValue*)  0x1570cc  size 72  18 条（0x1570cc..0x157114）
 * @func 0x1570cc 0x157114  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1570cc push {r4, r5, r6, lr}
 *   @0x1570d0 mov r1, #0
 *   @0x1570d4 ldr r4, [sp, #0x10]
 *   @0x1570d8 mov r0, r4
 *   @0x1570dc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1570e0 mov r1, #1
 *   @0x1570e4 mov r6, r0
 *   @0x1570e8 mov r0, r4
 *   @0x1570ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1570f0 mov r1, #2
 *   @0x1570f4 mov r5, r0
 *   @0x1570f8 mov r0, r4
 *   @0x1570fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157100 mov r1, r5
 *   @0x157104 mov r2, r0
 *   @0x157108 mov r0, r6
 *   @0x15710c pop {r4, r5, r6, lr}
 *   @0x157110 b 0x1616e0 <_Z21YoYo_OF_SendChallengePKcS0_S0_>
 *
 * ══ §121/438 F_YoYo_OF_SendSocial(RValue&, CInstance*, CInstance*, int, RValue*)  0x15712c  size 72  18 条（0x15712c..0x157174）
 * @func 0x15712c 0x157174  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15712c push {r4, r5, r6, lr}
 *   @0x157130 mov r1, #0
 *   @0x157134 ldr r4, [sp, #0x10]
 *   @0x157138 mov r0, r4
 *   @0x15713c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157140 mov r1, #1
 *   @0x157144 mov r6, r0
 *   @0x157148 mov r0, r4
 *   @0x15714c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157150 mov r1, #2
 *   @0x157154 mov r5, r0
 *   @0x157158 mov r0, r4
 *   @0x15715c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157160 mov r1, r5
 *   @0x157164 mov r2, r0
 *   @0x157168 mov r0, r6
 *   @0x15716c pop {r4, r5, r6, lr}
 *   @0x157170 b 0x1616e8 <_Z18YoYo_OF_SendSocialPKcS0_S0_>
 *
 * ══ §122/438 Push_GetLocalNotification(int, int)  0x161c00  size 72  18 条（0x161c00..0x161c48）
 * @func 0x161c00 0x161c48  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticIntMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x24×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161c00 push {r4, r5, lr}
 *   @0x161c04 sub sp, sp, #12
 *   @0x161c08 mov r4, r1
 *   @0x161c0c mov r5, r0
 *   @0x161c10 bl 0x290274 <getJNIEnv>
 *   @0x161c14 ldr r12, [pc, #0x24]
 *   @0x161c18 ldr r2, [pc, #0x24]
 *   @0x161c1c mov r3, r5
 *   @0x161c20 ldr r12, [pc, r12]
 *   @0x161c24 ldr r2, [pc, r2]
 *   @0x161c28 ldr r1, [r12]
 *   @0x161c2c ldr r2, [r2]
 *   @0x161c30 str r4, [sp]
 *   @0x161c34 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x161c38 add sp, sp, #12
 *   @0x161c3c pop {r4, r5, pc}
 *   @0x161c40 eoreq r11, r8, r4, lsl #27
 *   @0x161c44 eoreq lr, r8, r4, asr r3
 *
 * ══ §123/438 GR_3DM_LoadFromFile(int, char const*)  0x165250  size 72  18 条（0x165250..0x165298）
 * @func 0x165250 0x165298  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_LoadFromFile(int, char const*)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165250 cmp r0, #0
 *   @0x165254 blt 0x165288 <_Z19GR_3DM_LoadFromFileiPKc+0x38>
 *   @0x165258 ldr r3, [pc, #0x30]
 *   @0x16525c ldr r3, [pc, r3]
 *   @0x165260 ldr r3, [r3]
 *   @0x165264 cmp r0, r3
 *   @0x165268 bge 0x165288 <_Z19GR_3DM_LoadFromFileiPKc+0x38>
 *   @0x16526c ldr r3, [pc, #0x20]
 *   @0x165270 ldr r3, [pc, r3]
 *   @0x165274 ldr r3, [r3, #0x4]
 *   @0x165278 ldr r0, [r3, r0, lsl #2]
 *   @0x16527c cmp r0, #0
 *   @0x165280 beq 0x165288 <_Z19GR_3DM_LoadFromFileiPKc+0x38>
 *   @0x165284 b 0x163efc <_ZN9C3D_Model12LoadFromFileEPKc>
 *   @0x165288 mov r0, #0
 *   @0x16528c bx lr
 *   @0x165290 mlaeq r8, r4, lr, r10
 *   @0x165294 eoreq r10, r8, r4, lsl #29
 *
 * ══ §124/438 GR_3DM_LoadFromBuffer(int, int)  0x165298  size 72  18 条（0x165298..0x1652e0）
 * @func 0x165298 0x1652e0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_LoadFromBuffer(int, int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165298 cmp r0, #0
 *   @0x16529c blt 0x1652d0 <_Z21GR_3DM_LoadFromBufferii+0x38>
 *   @0x1652a0 ldr r3, [pc, #0x30]
 *   @0x1652a4 ldr r3, [pc, r3]
 *   @0x1652a8 ldr r3, [r3]
 *   @0x1652ac cmp r0, r3
 *   @0x1652b0 bge 0x1652d0 <_Z21GR_3DM_LoadFromBufferii+0x38>
 *   @0x1652b4 ldr r3, [pc, #0x20]
 *   @0x1652b8 ldr r3, [pc, r3]
 *   @0x1652bc ldr r3, [r3, #0x4]
 *   @0x1652c0 ldr r0, [r3, r0, lsl #2]
 *   @0x1652c4 cmp r0, #0
 *   @0x1652c8 beq 0x1652d0 <_Z21GR_3DM_LoadFromBufferii+0x38>
 *   @0x1652cc b 0x1641f0 <_ZN9C3D_Model14LoadFromBufferEi>
 *   @0x1652d0 mov r0, #0
 *   @0x1652d4 bx lr
 *   @0x1652d8 eoreq r10, r8, r12, asr #28
 *   @0x1652dc eoreq r10, r8, r12, lsr lr
 *
 * ══ §125/438 GR_3DM_SaveToFile(int, char const*)  0x1652e0  size 72  18 条（0x1652e0..0x165328）
 * @func 0x1652e0 0x165328  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_SaveToFile(int, char const*)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1652e0 cmp r0, #0
 *   @0x1652e4 blt 0x165318 <_Z17GR_3DM_SaveToFileiPKc+0x38>
 *   @0x1652e8 ldr r3, [pc, #0x30]
 *   @0x1652ec ldr r3, [pc, r3]
 *   @0x1652f0 ldr r3, [r3]
 *   @0x1652f4 cmp r0, r3
 *   @0x1652f8 bge 0x165318 <_Z17GR_3DM_SaveToFileiPKc+0x38>
 *   @0x1652fc ldr r3, [pc, #0x20]
 *   @0x165300 ldr r3, [pc, r3]
 *   @0x165304 ldr r3, [r3, #0x4]
 *   @0x165308 ldr r0, [r3, r0, lsl #2]
 *   @0x16530c cmp r0, #0
 *   @0x165310 beq 0x165318 <_Z17GR_3DM_SaveToFileiPKc+0x38>
 *   @0x165314 b 0x1644f8 <_ZN9C3D_Model10SaveToFileEPKc>
 *   @0x165318 mov r0, #0
 *   @0x16531c bx lr
 *   @0x165320 eoreq r10, r8, r4, lsl #28
 *   @0x165324 .word 0x0028adf4
 *
 * ══ §126/438 GR_3DM_SaveToBuffer(int, int)  0x165328  size 72  18 条（0x165328..0x165370）
 * @func 0x165328 0x165370  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_SaveToBuffer(int, int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165328 cmp r0, #0
 *   @0x16532c blt 0x165360 <_Z19GR_3DM_SaveToBufferii+0x38>
 *   @0x165330 ldr r3, [pc, #0x30]
 *   @0x165334 ldr r3, [pc, r3]
 *   @0x165338 ldr r3, [r3]
 *   @0x16533c cmp r0, r3
 *   @0x165340 bge 0x165360 <_Z19GR_3DM_SaveToBufferii+0x38>
 *   @0x165344 ldr r3, [pc, #0x20]
 *   @0x165348 ldr r3, [pc, r3]
 *   @0x16534c ldr r3, [r3, #0x4]
 *   @0x165350 ldr r0, [r3, r0, lsl #2]
 *   @0x165354 cmp r0, #0
 *   @0x165358 beq 0x165360 <_Z19GR_3DM_SaveToBufferii+0x38>
 *   @0x16535c b 0x1646f4 <_ZN9C3D_Model12SaveToBufferEi>
 *   @0x165360 mov r0, #0
 *   @0x165364 bx lr
 *   @0x165368 .word 0x0028adbc
 *   @0x16536c eoreq r10, r8, r12, lsr #27
 *
 * ══ §127/438 ConvertAlpha(float)  0x16ca2c  size 72  18 条（0x16ca2c..0x16ca74）
 * @func 0x16ca2c 0x16ca74  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertAlpha(float)+0x1c
 * 字段偏移 top8: 无
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ca2c vmov.f32 s14, #1.000000e+00
 *   @0x16ca30 vmov s15, r0
 *   @0x16ca34 vcmpe.f32 s15, s14
 *   @0x16ca38 vmrs APSR_nzcv, fpscr
 *   @0x16ca3c ble 0x16ca48 <_Z12ConvertAlphaf+0x1c>
 *   @0x16ca40 mov r0, #255
 *   @0x16ca44 bx lr
 *   @0x16ca48 vcmpe.f32 s15, #0
 *   @0x16ca4c vmrs APSR_nzcv, fpscr
 *   @0x16ca50 bpl 0x16ca5c <_Z12ConvertAlphaf+0x30>
 *   @0x16ca54 mov r0, #0
 *   @0x16ca58 bx lr
 *   @0x16ca5c vldr s14, [pc, #12]
 *   @0x16ca60 vmul.f32 s15, s15, s14
 *   @0x16ca64 vcvt.u32.f32 s15, s15
 *   @0x16ca68 vmov r0, s15
 *   @0x16ca6c bx lr
 *   @0x16ca70 cmnmi pc, #0
 *
 * ══ §128/438 FINALIZE_Graphics_Text()  0x1738fc  size 72  18 条（0x1738fc..0x173944）
 * @func 0x1738fc 0x173944  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1738fc push {r3, r4, r5, lr}
 *   @0x173900 mov r5, #0
 *   @0x173904 ldr r4, [pc, #0x30]
 *   @0x173908 ldr r3, [pc, #0x30]
 *   @0x17390c ldr r4, [pc, r4]
 *   @0x173910 ldr r3, [pc, r3]
 *   @0x173914 ldr r0, [r4]
 *   @0x173918 str r5, [r3]
 *   @0x17391c cmp r0, r5
 *   @0x173920 beq 0x173934 <_Z22FINALIZE_Graphics_Textv+0x38>
 *   @0x173924 ldr r3, [r0]
 *   @0x173928 ldr r3, [r3, #0x4]
 *   @0x17392c blx r3
 *   @0x173930 str r5, [r4]
 *   @0x173934 pop {r3, r4, r5, lr}
 *   @0x173938 b 0x173884 <_Z22GR_Text_ResetToDefaultv>
 *   @0x17393c eoreq r12, r7, r8, lsl #19
 *   @0x173940 eoreq r12, r7, r8, lsl #19
 *
 * ══ §129/438 GR_Texture_Get_Width(int)  0x1741f8  size 72  18 条（0x1741f8..0x174240）
 * @func 0x1741f8 0x174240  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)
 * 字段偏移 top8: 0x24×1 / 0x4×1 / 0x2×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1741f8 push {r4, lr}
 *   @0x1741fc mov r4, r0
 *   @0x174200 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x174204 cmp r0, #0
 *   @0x174208 vmoveq.f32 s15, #1.000000e+00
 *   @0x17420c beq 0x174234 <_Z20GR_Texture_Get_Widthi+0x3c>
 *   @0x174210 ldr r3, [pc, #0x24]
 *   @0x174214 ldr r3, [pc, r3]
 *   @0x174218 ldr r3, [r3, #0x4]
 *   @0x17421c ldr r3, [r3, r4, lsl #2]
 *   @0x174220 vldr s14, [r3, #8]
 *   @0x174224 ldrsh r3, [r3, #4]
 *   @0x174228 vmov s15, r3
 *   @0x17422c vcvt.f32.s32 s15, s15
 *   @0x174230 vmul.f32 s15, s15, s14
 *   @0x174234 vmov r0, s15
 *   @0x174238 pop {r4, pc}
 *   @0x17423c eoreq r9, r7, r8, lsl #14
 *
 * ══ §130/438 GR_Texture_Get_Height(int)  0x174240  size 72  18 条（0x174240..0x174288）
 * @func 0x174240 0x174288  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)
 * 字段偏移 top8: 0x24×1 / 0x4×1 / 0x2×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x174240 push {r4, lr}
 *   @0x174244 mov r4, r0
 *   @0x174248 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x17424c cmp r0, #0
 *   @0x174250 vmoveq.f32 s15, #1.000000e+00
 *   @0x174254 beq 0x17427c <_Z21GR_Texture_Get_Heighti+0x3c>
 *   @0x174258 ldr r3, [pc, #0x24]
 *   @0x17425c ldr r3, [pc, r3]
 *   @0x174260 ldr r3, [r3, #0x4]
 *   @0x174264 ldr r3, [r3, r4, lsl #2]
 *   @0x174268 vldr s14, [r3, #12]
 *   @0x17426c ldrsh r3, [r3, #6]
 *   @0x174270 vmov s15, r3
 *   @0x174274 vcvt.f32.s32 s15, s15
 *   @0x174278 vmul.f32 s15, s15, s14
 *   @0x17427c vmov r0, s15
 *   @0x174280 pop {r4, pc}
 *   @0x174284 eoreq r9, r7, r0, asr #13
 *
 * ══ §131/438 GR_3D_Light_Set_Ambient()  0x17f47c  size 72  18 条（0x17f47c..0x17f4c4）
 * @func 0x17f47c 0x17f4c4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f47c push {r3, lr}
 *   @0x17f480 ldr r3, [pc, #0x30]
 *   @0x17f484 ldr r3, [pc, r3]
 *   @0x17f488 ldr r3, [r3]
 *   @0x17f48c cmp r3, #0
 *   @0x17f490 popne {r3, pc}
 *   @0x17f494 ldr r3, [pc, #0x20]
 *   @0x17f498 movw r0, #0x408
 *   @0x17f49c ldr r2, [pc, #0x1c]
 *   @0x17f4a0 mov r1, #5632
 *   @0x17f4a4 ldr r3, [pc, r3]
 *   @0x17f4a8 ldr r2, [pc, r2]
 *   @0x17f4ac ldr r3, [r3]
 *   @0x17f4b0 blx r3
 *   @0x17f4b4 pop {r3, pc}
 *   @0x17f4b8 eoreq r0, r7, r4, lsl #31
 *   @0x17f4bc eoreq lr, r6, r8, lsr r4
 *   @0x17f4c0 eoreq r0, r7, r12, ror #31
 *
 * ══ §132/438 VertexBuffer::~VertexBuffer()  0x18373c  size 72  18 条（0x18373c..0x183784）
 * @func 0x18373c 0x183784  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0xc×2 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18373c push {r3, r4, r5, lr}
 *   @0x183740 mov r4, r0
 *   @0x183744 ldr r5, [r0, #0xc]
 *   @0x183748 cmp r5, #0
 *   @0x18374c beq 0x183778 <_ZN12VertexBufferD2Ev+0x3c>
 *   @0x183750 ldr r3, [pc, #0x28]
 *   @0x183754 mov r0, #1
 *   @0x183758 mov r1, r5
 *   @0x18375c ldr r3, [pc, r3]
 *   @0x183760 ldr r3, [r3]
 *   @0x183764 blx r3
 *   @0x183768 mov r0, r5
 *   @0x18376c bl 0x27d1d0 <_ZdlPv>
 *   @0x183770 mov r3, #0
 *   @0x183774 str r3, [r4, #0xc]
 *   @0x183778 mov r0, r4
 *   @0x18377c pop {r3, r4, r5, pc}
 *   @0x183780 eoreq r10, r6, r8, lsr #32
 *
 * ══ §133/438 Shader_Set_Texture(int, void*)  0x188354  size 72  18 条（0x188354..0x18839c）
 * @func 0x188354 0x18839c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush()
 * 字段偏移 top8: 0x20×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188354 cmp r0, #7
 *   @0x188358 push {r3, r4, r5, lr}
 *   @0x18835c mov r4, r0
 *   @0x188360 mov r5, r1
 *   @0x188364 pophi {r3, r4, r5, pc}
 *   @0x188368 cmp r1, #0
 *   @0x18836c popeq {r3, r4, r5, pc}
 *   @0x188370 ldr r3, [pc, #0x20]
 *   @0x188374 ldr r3, [pc, r3]
 *   @0x188378 ldr r3, [r3, r0, lsl #2]
 *   @0x18837c cmp r3, r1
 *   @0x188380 popeq {r3, r4, r5, pc}
 *   @0x188384 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x188388 mov r0, r4
 *   @0x18838c mov r1, r5
 *   @0x188390 pop {r3, r4, r5, lr}
 *   @0x188394 b 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x188398 eoreq r8, r6, r4, asr #3
 *
 * ══ §134/438 CGCGeneration::ResetClassStats()  0x191530  size 72  18 条（0x191530..0x191578）
 * @func 0x191530 0x191578  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / CGCGeneration::ResetClassStats()+0x1c
 * 字段偏移 top8: 0x4c×3 / 0x48×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191530 push {r3, r4, r5, lr}
 *   @0x191534 mov r5, r0
 *   @0x191538 ldr r3, [r0, #0x4c]
 *   @0x19153c cmp r3, #0
 *   @0x191540 movne r3, #0
 *   @0x191544 movne r4, r3
 *   @0x191548 beq 0x19156c <_ZN13CGCGeneration15ResetClassStatsEv+0x3c>
 *   @0x19154c ldr r2, [r5, #0x48]
 *   @0x191550 add r4, r4, #1
 *   @0x191554 ldr r0, [r2, r3, lsl #3]
 *   @0x191558 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19155c ldr r2, [r5, #0x4c]
 *   @0x191560 mov r3, r4
 *   @0x191564 cmp r4, r2
 *   @0x191568 blo 0x19154c <_ZN13CGCGeneration15ResetClassStatsEv+0x1c>
 *   @0x19156c mov r3, #0
 *   @0x191570 str r3, [r5, #0x4c]
 *   @0x191574 pop {r3, r4, r5, pc}
 *
 * ══ §135/438 YYObjectBase::FreeAll()  0x191794  size 72  18 条（0x191794..0x1917dc）
 * @func 0x191794 0x1917dc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191794 push {r3, r4, r5, lr}
 *   @0x191798 ldr r5, [pc, #0x38]
 *   @0x19179c ldr r5, [pc, r5]
 *   @0x1917a0 ldr r3, [r5]
 *   @0x1917a4 cmp r3, #0
 *   @0x1917a8 beq 0x1917cc <_ZN12YYObjectBase7FreeAllEv+0x38>
 *   @0x1917ac ldr r2, [r3]
 *   @0x1917b0 mov r0, r3
 *   @0x1917b4 ldr r4, [r3, #0x8]
 *   @0x1917b8 ldr r3, [r2, #0x4]
 *   @0x1917bc blx r3
 *   @0x1917c0 cmp r4, #0
 *   @0x1917c4 mov r3, r4
 *   @0x1917c8 bne 0x1917ac <_ZN12YYObjectBase7FreeAllEv+0x18>
 *   @0x1917cc mov r3, #0
 *   @0x1917d0 str r3, [r5]
 *   @0x1917d4 pop {r3, r4, r5, pc}
 *   @0x1917d8 eoreq r12, r5, r4, ror r4
 *
 * ══ §136/438 CPath::Shift(float, float)  0x1a7734  size 72  18 条（0x1a7734..0x1a777c）
 * @func 0x1a7734 0x1a777c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Shift(float, float)+0x44
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7734 ldr r3, [r0, #0x10]
 *   @0x1a7738 vmov s13, r1
 *   @0x1a773c vmov s12, r2
 *   @0x1a7740 cmp r3, #0
 *   @0x1a7744 ble 0x1a7778 <_ZN5CPath5ShiftEff+0x44>
 *   @0x1a7748 add r2, r3, r3, lsl #1
 *   @0x1a774c ldr r3, [r0, #0x4]
 *   @0x1a7750 add r2, r3, r2, lsl #2
 *   @0x1a7754 vldr s14, [r3]
 *   @0x1a7758 vldr s15, [r3, #4]
 *   @0x1a775c vadd.f32 s14, s14, s13
 *   @0x1a7760 add r3, r3, #12
 *   @0x1a7764 vadd.f32 s15, s15, s12
 *   @0x1a7768 vstr s14, [r3, #-12]
 *   @0x1a776c vstr s15, [r3, #-8]
 *   @0x1a7770 cmp r3, r2
 *   @0x1a7774 bne 0x1a7754 <_ZN5CPath5ShiftEff+0x20>
 *   @0x1a7778 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *
 * ══ §137/438 Path_Exists(int)  0x1a8008  size 72  18 条（0x1a8008..0x1a8050）
 * @func 0x1a8008 0x1a8050  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Path_Exists(int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8008 cmp r0, #0
 *   @0x1a800c blt 0x1a8040 <_Z11Path_Existsi+0x38>
 *   @0x1a8010 ldr r3, [pc, #0x30]
 *   @0x1a8014 ldr r3, [pc, r3]
 *   @0x1a8018 ldr r3, [r3]
 *   @0x1a801c cmp r0, r3
 *   @0x1a8020 bge 0x1a8040 <_Z11Path_Existsi+0x38>
 *   @0x1a8024 ldr r3, [pc, #0x20]
 *   @0x1a8028 add r3, pc, r3
 *   @0x1a802c ldr r3, [r3, #0x4]
 *   @0x1a8030 ldr r0, [r3, r0, lsl #2]
 *   @0x1a8034 adds r0, r0, #0
 *   @0x1a8038 movne r0, #1
 *   @0x1a803c bx lr
 *   @0x1a8040 mov r0, #0
 *   @0x1a8044 bx lr
 *   @0x1a8048 .word 0x002487b8
 *   @0x1a804c eorseq r10, r9, r0, lsl #10
 *
 * ══ §138/438 TFont::~TFont()  0x1a87ec  size 72  18 条（0x1a87ec..0x1a8834）
 * @func 0x1a87ec 0x1a8834  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x38×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a87ec ldr r3, [pc, #0x38]
 *   @0x1a87f0 push {r4, lr}
 *   @0x1a87f4 ldr r3, [pc, r3]
 *   @0x1a87f8 mov r4, r0
 *   @0x1a87fc add r3, r3, #8
 *   @0x1a8800 ldr r0, [r0, #0x8]
 *   @0x1a8804 str r3, [r4]
 *   @0x1a8808 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a880c ldr r3, [pc, #0x1c]
 *   @0x1a8810 mov r2, #0
 *   @0x1a8814 mov r0, r4
 *   @0x1a8818 ldr r3, [pc, r3]
 *   @0x1a881c str r2, [r4, #0x8]
 *   @0x1a8820 add r3, r3, #8
 *   @0x1a8824 str r3, [r4]
 *   @0x1a8828 pop {r4, pc}
 *   @0x1a882c eoreq r7, r4, r4, ror #31
 *   @0x1a8830 .word 0x00247fbc
 *
 * ══ §139/438 CLayerManager::GetTargetRoomObj()  0x1ba730  size 72  18 条（0x1ba730..0x1ba778）
 * @func 0x1ba730 0x1ba778  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1ba738→0x3f50e4, 0x1ba75c→0x54298c
 * 调用序列: Room_Data(int)
 * 字段偏移 top8: 0x30×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ba730 push {r4, lr}
 *   @0x1ba734 ldr r4, [pc, #0x30]
 *   @0x1ba738 ldr r3, [pc, #0x30]
 *   @0x1ba73c add r4, pc, r4
 *   @0x1ba740 ldr r3, [r4, r3]
 *   @0x1ba744 ldr r0, [r3]
 *   @0x1ba748 cmn r0, #1
 *   @0x1ba74c beq 0x1ba75c <_ZN13CLayerManager16GetTargetRoomObjEv+0x2c>
 *   @0x1ba750 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x1ba754 cmp r0, #0
 *   @0x1ba758 popne {r4, pc}
 *   @0x1ba75c ldr r3, [pc, #0x10]
 *   @0x1ba760 ldr r3, [r4, r3]
 *   @0x1ba764 ldr r0, [r3]
 *   @0x1ba768 pop {r4, pc}
 *   @0x1ba76c eoreq r7, r3, r4, lsl r5
 *   @0x1ba770 .word 0xffffec04
 *   @0x1ba774 .word 0xffffbcd8
 *
 * ══ §140/438 LocalRandom(unsigned int&, unsigned int&)  0x1dfb34  size 72  18 条（0x1dfb34..0x1dfb7c）
 * @func 0x1dfb34 0x1dfb7c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfb34 ldr r3, [r0]
 *   @0x1dfb38 movw r2, #0x9069
 *   @0x1dfb3c str r4, [sp, #-0x4]!
 *   @0x1dfb40 movw r12, #0x4650
 *   @0x1dfb44 uxth r4, r3
 *   @0x1dfb48 lsr r3, r3, #16
 *   @0x1dfb4c mla r2, r2, r4, r3
 *   @0x1dfb50 ldr r4, [sp], #4
 *   @0x1dfb54 str r2, [r0]
 *   @0x1dfb58 ldr r2, [r1]
 *   @0x1dfb5c uxth r3, r2
 *   @0x1dfb60 lsr r2, r2, #16
 *   @0x1dfb64 mla r3, r12, r3, r2
 *   @0x1dfb68 str r3, [r1]
 *   @0x1dfb6c ldr r0, [r0]
 *   @0x1dfb70 lsl r0, r0, #16
 *   @0x1dfb74 uxtah r0, r0, r3
 *   @0x1dfb78 bx lr
 *
 * ══ §141/438 Script_Exists(int)  0x1e0544  size 72  18 条（0x1e0544..0x1e058c）
 * @func 0x1e0544 0x1e058c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Script_Exists(int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0544 cmp r0, #0
 *   @0x1e0548 blt 0x1e057c <_Z13Script_Existsi+0x38>
 *   @0x1e054c ldr r3, [pc, #0x30]
 *   @0x1e0550 ldr r3, [pc, r3]
 *   @0x1e0554 ldr r3, [r3]
 *   @0x1e0558 cmp r0, r3
 *   @0x1e055c bge 0x1e057c <_Z13Script_Existsi+0x38>
 *   @0x1e0560 ldr r3, [pc, #0x20]
 *   @0x1e0564 ldr r3, [pc, r3]
 *   @0x1e0568 ldr r3, [r3, #0x4]
 *   @0x1e056c ldr r0, [r3, r0, lsl #2]
 *   @0x1e0570 adds r0, r0, #0
 *   @0x1e0574 movne r0, #1
 *   @0x1e0578 bx lr
 *   @0x1e057c mov r0, #0
 *   @0x1e0580 bx lr
 *   @0x1e0584 .word 0x002107dc
 *   @0x1e0588 eoreq r0, r1, r4, asr #15
 *
 * ══ §142/438 ShaderExists(int)  0x1e1294  size 72  18 条（0x1e1294..0x1e12dc）
 * @func 0x1e1294 0x1e12dc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ShaderExists(int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1294 cmp r0, #0
 *   @0x1e1298 blt 0x1e12cc <_Z12ShaderExistsi+0x38>
 *   @0x1e129c ldr r3, [pc, #0x30]
 *   @0x1e12a0 ldr r3, [pc, r3]
 *   @0x1e12a4 ldr r3, [r3]
 *   @0x1e12a8 cmp r0, r3
 *   @0x1e12ac bge 0x1e12cc <_Z12ShaderExistsi+0x38>
 *   @0x1e12b0 ldr r3, [pc, #0x20]
 *   @0x1e12b4 ldr r3, [pc, r3]
 *   @0x1e12b8 ldr r3, [r3]
 *   @0x1e12bc ldr r0, [r3, r0, lsl #2]
 *   @0x1e12c0 adds r0, r0, #0
 *   @0x1e12c4 movne r0, #1
 *   @0x1e12c8 bx lr
 *   @0x1e12cc mov r0, #0
 *   @0x1e12d0 bx lr
 *   @0x1e12d4 eoreq pc, r0, r4, lsr #21
 *   @0x1e12d8 mlaeq r0, r4, r10, pc
 *
 * ══ §143/438 CTimeLine::Find(int)  0x1f1c28  size 72  18 条（0x1f1c28..0x1f1c70）
 * @func 0x1f1c28 0x1f1c70  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimeLine::Find(int)+0x3c
 * 字段偏移 top8: 0x10×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1c28 ldr r12, [r0, #0x10]
 *   @0x1f1c2c cmp r12, #0
 *   @0x1f1c30 ble 0x1f1c64 <_ZN9CTimeLine4FindEi+0x3c>
 *   @0x1f1c34 ldr r3, [r0, #0x14]
 *   @0x1f1c38 mov r0, #0
 *   @0x1f1c3c ldr r2, [r3]
 *   @0x1f1c40 cmp r2, r1
 *   @0x1f1c44 bne 0x1f1c58 <_ZN9CTimeLine4FindEi+0x30>
 *   @0x1f1c48 b 0x1f1c6c <_ZN9CTimeLine4FindEi+0x44>
 *   @0x1f1c4c ldr r2, [r3, #0x4]!
 *   @0x1f1c50 cmp r2, r1
 *   @0x1f1c54 bxeq lr
 *   @0x1f1c58 add r0, r0, #1
 *   @0x1f1c5c cmp r0, r12
 *   @0x1f1c60 bne 0x1f1c4c <_ZN9CTimeLine4FindEi+0x24>
 *   @0x1f1c64 mvn r0, #0
 *   @0x1f1c68 bx lr
 *   @0x1f1c6c bx lr
 *
 * ══ §144/438 GV_PhysicsBullet(CInstance*, int, RValue*)  0x1f9934  size 72  18 条（0x1f9934..0x1f997c）
 * @func 0x1f9934 0x1f997c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9934 ldr r0, [r0, #0x84]
 *   @0x1f9938 push {r4, r5}
 *   @0x1f993c cmp r0, #0
 *   @0x1f9940 beq 0x1f9974 <_Z16GV_PhysicsBulletP9CInstanceiP6RValue+0x40>
 *   @0x1f9944 ldr r3, [r0]
 *   @0x1f9948 mov r1, #0
 *   @0x1f994c str r1, [r2, #0xc]
 *   @0x1f9950 mov r0, #1
 *   @0x1f9954 ldrh r4, [r3, #4]
 *   @0x1f9958 ubfx r4, r4, #0x3, #0x1
 *   @0x1f995c vmov s15, r4
 *   @0x1f9960 vcvt.f64.u32 d7, s15
 *   @0x1f9964 vmov r4, r5, d7
 *   @0x1f9968 vmov r1, s14
 *   @0x1f996c mov r3, r5
 *   @0x1f9970 stm r2, {r1, r3}
 *   @0x1f9974 pop {r4, r5}
 *   @0x1f9978 bx lr
 *
 * ══ §145/438 GV_PhysicsFixedRotation(CInstance*, int, RValue*)  0x1f9b1c  size 72  18 条（0x1f9b1c..0x1f9b64）
 * @func 0x1f9b1c 0x1f9b64  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9b1c ldr r0, [r0, #0x84]
 *   @0x1f9b20 push {r4, r5}
 *   @0x1f9b24 cmp r0, #0
 *   @0x1f9b28 beq 0x1f9b5c <_Z23GV_PhysicsFixedRotationP9CInstanceiP6RValue+0x40>
 *   @0x1f9b2c ldr r3, [r0]
 *   @0x1f9b30 mov r1, #0
 *   @0x1f9b34 str r1, [r2, #0xc]
 *   @0x1f9b38 mov r0, #1
 *   @0x1f9b3c ldrh r4, [r3, #4]
 *   @0x1f9b40 ubfx r4, r4, #0x4, #0x1
 *   @0x1f9b44 vmov s15, r4
 *   @0x1f9b48 vcvt.f64.u32 d7, s15
 *   @0x1f9b4c vmov r4, r5, d7
 *   @0x1f9b50 vmov r1, s14
 *   @0x1f9b54 mov r3, r5
 *   @0x1f9b58 stm r2, {r1, r3}
 *   @0x1f9b5c pop {r4, r5}
 *   @0x1f9b60 bx lr
 *
 * ══ §146/438 GV_PhysicsActive(CInstance*, int, RValue*)  0x1f9b64  size 72  18 条（0x1f9b64..0x1f9bac）
 * @func 0x1f9b64 0x1f9bac  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9b64 ldr r0, [r0, #0x84]
 *   @0x1f9b68 push {r4, r5}
 *   @0x1f9b6c cmp r0, #0
 *   @0x1f9b70 beq 0x1f9ba4 <_Z16GV_PhysicsActiveP9CInstanceiP6RValue+0x40>
 *   @0x1f9b74 ldr r3, [r0]
 *   @0x1f9b78 mov r1, #0
 *   @0x1f9b7c str r1, [r2, #0xc]
 *   @0x1f9b80 mov r0, #1
 *   @0x1f9b84 ldrh r4, [r3, #4]
 *   @0x1f9b88 ubfx r4, r4, #0x5, #0x1
 *   @0x1f9b8c vmov s15, r4
 *   @0x1f9b90 vcvt.f64.u32 d7, s15
 *   @0x1f9b94 vmov r4, r5, d7
 *   @0x1f9b98 vmov r1, s14
 *   @0x1f9b9c mov r3, r5
 *   @0x1f9ba0 stm r2, {r1, r3}
 *   @0x1f9ba4 pop {r4, r5}
 *   @0x1f9ba8 bx lr
 *
 * ══ §147/438 SV_KeyboardLastKey(CInstance*, int, RValue*)  0x1fb450  size 72  18 条（0x1fb450..0x1fb498）
 * @func 0x1fb450 0x1fb498  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / IO_Key_Last_Set(int) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb450 push {r3, lr}
 *   @0x1fb454 ldr r3, [r2, #0xc]
 *   @0x1fb458 bic r3, r3, #-16777216
 *   @0x1fb45c cmp r3, #0
 *   @0x1fb460 bne 0x1fb484 <_Z18SV_KeyboardLastKeyP9CInstanceiP6RValue+0x34>
 *   @0x1fb464 ldr r12, [r2]
 *   @0x1fb468 ldr r3, [r2, #0x4]
 *   @0x1fb46c mov r0, r12
 *   @0x1fb470 mov r1, r3
 *   @0x1fb474 bl 0xb66e8 <lrint@plt>
 *   @0x1fb478 bl 0x18bebc <_Z15IO_Key_Last_Seti>
 *   @0x1fb47c mov r0, #1
 *   @0x1fb480 pop {r3, pc}
 *   @0x1fb484 mov r0, r2
 *   @0x1fb488 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb48c mov r12, r0
 *   @0x1fb490 mov r3, r1
 *   @0x1fb494 b 0x1fb46c <_Z18SV_KeyboardLastKeyP9CInstanceiP6RValue+0x1c>
 *
 * ══ §148/438 SV_KeyboardKey(CInstance*, int, RValue*)  0x1fb498  size 72  18 条（0x1fb498..0x1fb4e0）
 * @func 0x1fb498 0x1fb4e0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / IO_Key_Current_Set(int) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb498 push {r3, lr}
 *   @0x1fb49c ldr r3, [r2, #0xc]
 *   @0x1fb4a0 bic r3, r3, #-16777216
 *   @0x1fb4a4 cmp r3, #0
 *   @0x1fb4a8 bne 0x1fb4cc <_Z14SV_KeyboardKeyP9CInstanceiP6RValue+0x34>
 *   @0x1fb4ac ldr r12, [r2]
 *   @0x1fb4b0 ldr r3, [r2, #0x4]
 *   @0x1fb4b4 mov r0, r12
 *   @0x1fb4b8 mov r1, r3
 *   @0x1fb4bc bl 0xb66e8 <lrint@plt>
 *   @0x1fb4c0 bl 0x18bed0 <_Z18IO_Key_Current_Seti>
 *   @0x1fb4c4 mov r0, #1
 *   @0x1fb4c8 pop {r3, pc}
 *   @0x1fb4cc mov r0, r2
 *   @0x1fb4d0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb4d4 mov r12, r0
 *   @0x1fb4d8 mov r3, r1
 *   @0x1fb4dc b 0x1fb4b4 <_Z14SV_KeyboardKeyP9CInstanceiP6RValue+0x1c>
 *
 * ══ §149/438 SV_PathEndAction(CInstance*, int, RValue*)  0x1fbf54  size 72  18 条（0x1fbf54..0x1fbf9c）
 * @func 0x1fbf54 0x1fbf9c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x140×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbf54 ldr r3, [r2, #0xc]
 *   @0x1fbf58 push {r4, lr}
 *   @0x1fbf5c bic r3, r3, #-16777216
 *   @0x1fbf60 cmp r3, #0
 *   @0x1fbf64 mov r4, r0
 *   @0x1fbf68 bne 0x1fbf90 <_Z16SV_PathEndActionP9CInstanceiP6RValue+0x3c>
 *   @0x1fbf6c ldm r2, {r0, r1}
 *   @0x1fbf70 vmov d6, r0, r1
 *   @0x1fbf74 vcvt.f32.f64 s15, d6
 *   @0x1fbf78 vcvt.f64.f32 d6, s15
 *   @0x1fbf7c vmov r0, r1, d6
 *   @0x1fbf80 bl 0xb66e8 <lrint@plt>
 *   @0x1fbf84 str r0, [r4, #0x140]
 *   @0x1fbf88 mov r0, #1
 *   @0x1fbf8c pop {r4, pc}
 *   @0x1fbf90 mov r0, r2
 *   @0x1fbf94 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbf98 b 0x1fbf70 <_Z16SV_PathEndActionP9CInstanceiP6RValue+0x1c>
 *
 * ══ §150/438 SV_TimelineIndex(CInstance*, int, RValue*)  0x1fbf9c  size 72  18 条（0x1fbf9c..0x1fbfe4）
 * @func 0x1fbf9c 0x1fbfe4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x14c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbf9c ldr r3, [r2, #0xc]
 *   @0x1fbfa0 push {r4, lr}
 *   @0x1fbfa4 bic r3, r3, #-16777216
 *   @0x1fbfa8 cmp r3, #0
 *   @0x1fbfac mov r4, r0
 *   @0x1fbfb0 bne 0x1fbfd8 <_Z16SV_TimelineIndexP9CInstanceiP6RValue+0x3c>
 *   @0x1fbfb4 ldm r2, {r0, r1}
 *   @0x1fbfb8 vmov d6, r0, r1
 *   @0x1fbfbc vcvt.f32.f64 s15, d6
 *   @0x1fbfc0 vcvt.f64.f32 d6, s15
 *   @0x1fbfc4 vmov r0, r1, d6
 *   @0x1fbfc8 bl 0xb66e8 <lrint@plt>
 *   @0x1fbfcc str r0, [r4, #0x14c]
 *   @0x1fbfd0 mov r0, #1
 *   @0x1fbfd4 pop {r4, pc}
 *   @0x1fbfd8 mov r0, r2
 *   @0x1fbfdc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbfe0 b 0x1fbfb8 <_Z16SV_TimelineIndexP9CInstanceiP6RValue+0x1c>
 *
 * ══ §151/438 CDS_Stack::MarkOnlyChildren4GC(unsigned int*, int)  0x202dd8  size 72  18 条（0x202dd8..0x202e20）
 * @func 0x202dd8 0x202e20  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_THISONLY(RValue const*, unsigned int*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202dd8 push {r3, r4, r5, r6, r7, lr}
 *   @0x202ddc mov r5, r0
 *   @0x202de0 ldr r3, [r0, #0x4]
 *   @0x202de4 mov r6, r1
 *   @0x202de8 mov r7, r2
 *   @0x202dec cmp r3, #0
 *   @0x202df0 pople {r3, r4, r5, r6, r7, pc}
 *   @0x202df4 mov r4, #0
 *   @0x202df8 ldr r0, [r5, #0xc]
 *   @0x202dfc mov r1, r6
 *   @0x202e00 mov r2, r7
 *   @0x202e04 add r0, r0, r4, lsl #4
 *   @0x202e08 add r4, r4, #1
 *   @0x202e0c bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x202e10 ldr r3, [r5, #0x4]
 *   @0x202e14 cmp r3, r4
 *   @0x202e18 bgt 0x202df8 <_ZN9CDS_Stack19MarkOnlyChildren4GCEPji+0x20>
 *   @0x202e1c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §152/438 CDS_Queue::MarkOnlyChildren4GC(unsigned int*, int)  0x202f60  size 72  18 条（0x202f60..0x202fa8）
 * @func 0x202f60 0x202fa8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_THISONLY(RValue const*, unsigned int*, int)
 * 字段偏移 top8: 0xc×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202f60 push {r3, r4, r5, r6, r7, lr}
 *   @0x202f64 mov r5, r0
 *   @0x202f68 ldr r3, [r0, #0xc]
 *   @0x202f6c mov r6, r1
 *   @0x202f70 mov r7, r2
 *   @0x202f74 cmp r3, #0
 *   @0x202f78 pople {r3, r4, r5, r6, r7, pc}
 *   @0x202f7c mov r4, #0
 *   @0x202f80 ldr r0, [r5, #0x10]
 *   @0x202f84 mov r1, r6
 *   @0x202f88 mov r2, r7
 *   @0x202f8c add r0, r0, r4, lsl #4
 *   @0x202f90 add r4, r4, #1
 *   @0x202f94 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x202f98 ldr r3, [r5, #0xc]
 *   @0x202f9c cmp r3, r4
 *   @0x202fa0 bgt 0x202f80 <_ZN9CDS_Queue19MarkOnlyChildren4GCEPji+0x20>
 *   @0x202fa4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §153/438 CDS_List::MarkOnlyChildren4GC(unsigned int*, int)  0x203134  size 72  18 条（0x203134..0x20317c）
 * @func 0x203134 0x20317c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_THISONLY(RValue const*, unsigned int*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203134 push {r3, r4, r5, r6, r7, lr}
 *   @0x203138 mov r5, r0
 *   @0x20313c ldr r3, [r0, #0x4]
 *   @0x203140 mov r6, r1
 *   @0x203144 mov r7, r2
 *   @0x203148 cmp r3, #0
 *   @0x20314c pople {r3, r4, r5, r6, r7, pc}
 *   @0x203150 mov r4, #0
 *   @0x203154 ldr r0, [r5, #0xc]
 *   @0x203158 mov r1, r6
 *   @0x20315c mov r2, r7
 *   @0x203160 add r0, r0, r4, lsl #4
 *   @0x203164 add r4, r4, #1
 *   @0x203168 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x20316c ldr r3, [r5, #0x4]
 *   @0x203170 cmp r3, r4
 *   @0x203174 bgt 0x203154 <_ZN8CDS_List19MarkOnlyChildren4GCEPji+0x20>
 *   @0x203178 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §154/438 Audio_SetListenerVelocity(int, double, double, double)  0x216608  size 72  18 条（0x216608..0x216650）
 * @func 0x216608 0x216650  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216608 cmp r0, #0
 *   @0x21660c vmov d7, r2, r3
 *   @0x216610 bxne lr
 *   @0x216614 ldr r3, [pc, #0x30]
 *   @0x216618 ldr r3, [pc, r3]
 *   @0x21661c ldr r3, [r3]
 *   @0x216620 cmp r3, #0
 *   @0x216624 bxeq lr
 *   @0x216628 vcvt.f32.f64 s14, d7
 *   @0x21662c vldr d5, [sp]
 *   @0x216630 vcvt.f32.f64 s13, d5
 *   @0x216634 vldr d5, [sp, #8]
 *   @0x216638 vstr s14, [r3, #12]
 *   @0x21663c vcvt.f32.f64 s15, d5
 *   @0x216640 vstr s13, [r3, #16]
 *   @0x216644 vstr s15, [r3, #20]
 *   @0x216648 bx lr
 *   @0x21664c andseq r10, sp, r4, asr #27
 *
 * ══ §155/438 CAudioGroup::IncLoadCount()  0x21ddf4  size 72  18 条（0x21ddf4..0x21de3c）
 * @func 0x21ddf4 0x21de3c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3 / Mutex::Lock()
 * 字段偏移 top8: 0x14×3 / 0x10×2 / 0x20×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21ddf4 push {r3, r4, r5, lr}
 *   @0x21ddf8 mov r4, r0
 *   @0x21ddfc ldr r3, [r4, #0x10]
 *   @0x21de00 mov r0, #100
 *   @0x21de04 ldr r1, [r4, #0x8]
 *   @0x21de08 add r3, r3, #1
 *   @0x21de0c str r3, [r4, #0x10]
 *   @0x21de10 mul r0, r0, r3
 *   @0x21de14 bl 0x318d10 <__divsi3>
 *   @0x21de18 ldr r3, [r4, #0x20]
 *   @0x21de1c mov r5, r0
 *   @0x21de20 ldr r0, [r3, #0x14]
 *   @0x21de24 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x21de28 ldr r3, [r4, #0x20]
 *   @0x21de2c str r5, [r4, #0x14]
 *   @0x21de30 ldr r0, [r3, #0x14]
 *   @0x21de34 pop {r3, r4, r5, lr}
 *   @0x21de38 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *
 * ══ §156/438 Sound_Exists(int)  0x21fbd0  size 72  18 条（0x21fbd0..0x21fc18）
 * @func 0x21fbd0 0x21fc18  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Exists(int)+0x3c
 * 字段偏移 top8: 0x34×1 / 0x10×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21fbd0 cmp r0, #0
 *   @0x21fbd4 blt 0x21fc0c <_Z12Sound_Existsi+0x3c>
 *   @0x21fbd8 ldr r3, [pc, #0x34]
 *   @0x21fbdc add r3, pc, r3
 *   @0x21fbe0 ldr r2, [r3, #0x10]
 *   @0x21fbe4 cmp r0, r2
 *   @0x21fbe8 bge 0x21fc0c <_Z12Sound_Existsi+0x3c>
 *   @0x21fbec ldr r2, [r3]
 *   @0x21fbf0 cmp r0, r2
 *   @0x21fbf4 bge 0x21fc0c <_Z12Sound_Existsi+0x3c>
 *   @0x21fbf8 ldr r3, [r3, #0x4]
 *   @0x21fbfc ldr r0, [r3, r0, lsl #2]
 *   @0x21fc00 adds r0, r0, #0
 *   @0x21fc04 movne r0, #1
 *   @0x21fc08 bx lr
 *   @0x21fc0c mov r0, #0
 *   @0x21fc10 bx lr
 *   @0x21fc14 subseq r5, r3, r12, asr r7
 *
 * ══ §157/438 _alutCreateBufferFromInputStream  0x2225cc  size 72  18 条（0x2225cc..0x222614）
 * @func 0x2225cc 0x222614  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_221ff4+0x4c / _alutInputStreamDestroy / _alutPassBufferData / _alutBufferDataDestroy
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2225cc push {r3, r4, r5, lr}
 *   @0x2225d0 subs r5, r0, #0
 *   @0x2225d4 beq 0x22260c <_alutCreateBufferFromInputStream+0x40>
 *   @0x2225d8 bl 0x222040 <_alutInputStreamReadUInt32LE+0x9c>
 *   @0x2225dc mov r4, r0
 *   @0x2225e0 mov r0, r5
 *   @0x2225e4 bl 0x221dcc <_alutInputStreamDestroy>
 *   @0x2225e8 cmp r4, #0
 *   @0x2225ec beq 0x22260c <_alutCreateBufferFromInputStream+0x40>
 *   @0x2225f0 mov r0, r4
 *   @0x2225f4 bl 0x221424 <_alutPassBufferData>
 *   @0x2225f8 mov r5, r0
 *   @0x2225fc mov r0, r4
 *   @0x222600 bl 0x2213b8 <_alutBufferDataDestroy>
 *   @0x222604 mov r0, r5
 *   @0x222608 pop {r3, r4, r5, pc}
 *   @0x22260c mov r0, #0
 *   @0x222610 pop {r3, r4, r5, pc}
 *
 * ══ §158/438 _alutFormatGetBitsPerSample  0x222b7c  size 72  18 条（0x222b7c..0x222bc4）
 * @func 0x222b7c 0x222bc4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222b7c sub r0, r0, #4352
 *   @0x222b80 cmp r0, #3
 *   @0x222b84 addls pc, pc, r0, lsl #2
 *   @0x222b88 b 0x222bbc <_alutFormatGetBitsPerSample+0x40>
 *   @0x222b8c b 0x222bac <_alutFormatGetBitsPerSample+0x30>
 *   @0x222b90 b 0x222b9c <_alutFormatGetBitsPerSample+0x20>
 *   @0x222b94 b 0x222bac <_alutFormatGetBitsPerSample+0x30>
 *   @0x222b98 b 0x222b9c <_alutFormatGetBitsPerSample+0x20>
 *   @0x222b9c mov r3, #16
 *   @0x222ba0 mov r0, #1
 *   @0x222ba4 str r3, [r1]
 *   @0x222ba8 bx lr
 *   @0x222bac mov r3, #8
 *   @0x222bb0 mov r0, #1
 *   @0x222bb4 str r3, [r1]
 *   @0x222bb8 bx lr
 *   @0x222bbc mov r0, #0
 *   @0x222bc0 bx lr
 *
 * ══ §159/438 ogg_read(void*, unsigned int, unsigned int, void*)  0x22368c  size 72  18 条（0x22368c..0x2236d4）
 * @func 0x22368c 0x2236d4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc
 * 字段偏移 top8: 0x2c0×3 / 0x2bc×1 / 0x2c×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22368c push {r3, r4, r5, lr}
 *   @0x223690 mov r4, r3
 *   @0x223694 ldr r3, [r3, #0x2bc]
 *   @0x223698 mul r2, r2, r1
 *   @0x22369c ldr r1, [r4, #0x2c0]
 *   @0x2236a0 ldr r5, [r3, #0x2c]
 *   @0x2236a4 ldr r3, [r3, #0x28]
 *   @0x2236a8 rsb r5, r1, r5
 *   @0x2236ac cmp r5, r2
 *   @0x2236b0 movge r5, r2
 *   @0x2236b4 add r1, r3, r1
 *   @0x2236b8 mov r2, r5
 *   @0x2236bc bl 0xb65bc <memcpy@plt>
 *   @0x2236c0 ldr r3, [r4, #0x2c0]
 *   @0x2236c4 mov r0, r5
 *   @0x2236c8 add r5, r3, r5
 *   @0x2236cc str r5, [r4, #0x2c0]
 *   @0x2236d0 pop {r3, r4, r5, pc}
 *
 * ══ §160/438 Section::~Section()  0x2353e0  size 72  18 条（0x2353e0..0x235428）
 * @func 0x2353e0 0x235428  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / Key::~Key() / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2353e0 push {r3, r4, r5, lr}
 *   @0x2353e4 mov r5, r0
 *   @0x2353e8 ldr r0, [r0, #0x8]
 *   @0x2353ec cmp r0, #0
 *   @0x2353f0 beq 0x235414 <_ZN7SectionD2Ev+0x34>
 *   @0x2353f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2353f8 b 0x235414 <_ZN7SectionD2Ev+0x34>
 *   @0x2353fc ldr r3, [r4]
 *   @0x235400 mov r0, r4
 *   @0x235404 str r3, [r5, #0x4]
 *   @0x235408 bl 0x2353b0 <_ZN3KeyD2Ev>
 *   @0x23540c mov r0, r4
 *   @0x235410 bl 0x27d1d0 <_ZdlPv>
 *   @0x235414 ldr r4, [r5, #0x4]
 *   @0x235418 cmp r4, #0
 *   @0x23541c bne 0x2353fc <_ZN7SectionD2Ev+0x1c>
 *   @0x235420 mov r0, r5
 *   @0x235424 pop {r3, r4, r5, pc}
 *
 * ══ §161/438 IniFile::_sysReadIniFile(char const*)  0x2360d8  size 72  18 条（0x2360d8..0x236120）
 * @func 0x2360d8 0x236120  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::SaveFileExists(char const*)
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2360d8 push {r4, lr}
 *   @0x2360dc mov r0, r1
 *   @0x2360e0 mov r4, r1
 *   @0x2360e4 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x2360e8 cmp r0, #0
 *   @0x2360ec bne 0x236104 <_ZN7IniFile15_sysReadIniFileEPKc+0x2c>
 *   @0x2360f0 ldr r1, [pc, #0x20]
 *   @0x2360f4 mov r0, r4
 *   @0x2360f8 pop {r4, lr}
 *   @0x2360fc ldr r1, [pc, r1]
 *   @0x236100 b 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x236104 ldr r1, [pc, #0x10]
 *   @0x236108 mov r0, r4
 *   @0x23610c pop {r4, lr}
 *   @0x236110 ldr r1, [pc, r1]
 *   @0x236114 b 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x236118 andseq r11, r11, r0, lsr #7
 *   @0x23611c andseq r11, r11, r12, lsl #7
 *
 * ══ §162/438 CPhysicsObject::ApplyAngularImpulse(float)  0x2372a4  size 72  18 条（0x2372a4..0x2372ec）
 * @func 0x2372a4 0x2372ec  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xa0×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2372a4 ldr r3, [r0]
 *   @0x2372a8 vmov s15, r1
 *   @0x2372ac ldr r2, [r3]
 *   @0x2372b0 cmp r2, #2
 *   @0x2372b4 bxne lr
 *   @0x2372b8 ldrh r2, [r3, #4]
 *   @0x2372bc tst r2, #2
 *   @0x2372c0 beq 0x2372d8 <_ZN14CPhysicsObject19ApplyAngularImpulseEf+0x34>
 *   @0x2372c4 vldr s14, [r3, #88]
 *   @0x2372c8 vldr s13, [r3, #144]
 *   @0x2372cc vmla.f32 s14, s15, s13
 *   @0x2372d0 vstr s14, [r3, #88]
 *   @0x2372d4 bx lr
 *   @0x2372d8 orr r2, r2, #2
 *   @0x2372dc mov r1, #0
 *   @0x2372e0 strh r2, [r3, #4]
 *   @0x2372e4 str r1, [r3, #0xa0]
 *   @0x2372e8 b 0x2372c4 <_ZN14CPhysicsObject19ApplyAngularImpulseEf+0x20>
 *
 * ══ §163/438 CPhysicsWorld::GetCurrentContactPointCount(CInstance*)  0x238e28  size 72  18 条（0x238e28..0x238e70）
 * @func 0x238e28 0x238e70  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetValidCollisionData(CInstance*) / CPhysicsWorld::GetCurrentContactPointCount(CInstance*)+0x40
 * 字段偏移 top8: 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238e28 push {r3, lr}
 *   @0x238e2c bl 0x238cb0 <_ZN13CPhysicsWorld21GetValidCollisionDataEP9CInstance>
 *   @0x238e30 cmp r0, #0
 *   @0x238e34 popeq {r3, pc}
 *   @0x238e38 ldr r1, [r0]
 *   @0x238e3c cmp r1, #0
 *   @0x238e40 ble 0x238e68 <_ZN13CPhysicsWorld27GetCurrentContactPointCountEP9CInstance+0x40>
 *   @0x238e44 mov r3, r0
 *   @0x238e48 add r1, r0, r1, lsl #6
 *   @0x238e4c mov r0, #0
 *   @0x238e50 ldr r2, [r3, #0x48]
 *   @0x238e54 add r3, r3, #64
 *   @0x238e58 cmp r3, r1
 *   @0x238e5c add r0, r0, r2
 *   @0x238e60 bne 0x238e50 <_ZN13CPhysicsWorld27GetCurrentContactPointCountEP9CInstance+0x28>
 *   @0x238e64 pop {r3, pc}
 *   @0x238e68 mov r0, #0
 *   @0x238e6c pop {r3, pc}
 *
 * ══ §164/438 CPhysicsWorld::GetParticleGroupOmega(int)  0x23a7b8  size 72  18 条（0x23a7b8..0x23a800）
 * @func 0x23a7b8 0x23a800  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetAngularVelocity() const
 * 字段偏移 top8: 无
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a7b8 push {r3, lr}
 *   @0x23a7bc bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a7c0 cmp r0, #0
 *   @0x23a7c4 beq 0x23a7e8 <_ZN13CPhysicsWorld21GetParticleGroupOmegaEi+0x30>
 *   @0x23a7c8 bl 0x2d488c <_ZNK15b2ParticleGroup18GetAngularVelocityEv>
 *   @0x23a7cc vldr s15, [pc, #32]
 *   @0x23a7d0 vldr s14, [pc, #32]
 *   @0x23a7d4 vmov s13, r0
 *   @0x23a7d8 vmul.f32 s15, s13, s15
 *   @0x23a7dc vdiv.f32 s15, s15, s14
 *   @0x23a7e0 vmov r0, s15
 *   @0x23a7e4 pop {r3, pc}
 *   @0x23a7e8 vldr s15, [pc, #12]
 *   @0x23a7ec vmov r0, s15
 *   @0x23a7f0 pop {r3, pc}
 *   @0x23a7f4 teqmi r4, #0
 *   @0x23a7f8 ldrdmi r0, r1, [r9], #-251
 *   @0x23a7fc andeq r0, r0, r0
 *
 * ══ §165/438 CPhysicsWorld::GetParticleGroupAngle(int)  0x23a878  size 72  18 条（0x23a878..0x23a8c0）
 * @func 0x23a878 0x23a8c0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetAngle() const
 * 字段偏移 top8: 无
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a878 push {r3, lr}
 *   @0x23a87c bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a880 cmp r0, #0
 *   @0x23a884 beq 0x23a8a8 <_ZN13CPhysicsWorld21GetParticleGroupAngleEi+0x30>
 *   @0x23a888 bl 0x2d4624 <_ZNK15b2ParticleGroup8GetAngleEv>
 *   @0x23a88c vldr s15, [pc, #32]
 *   @0x23a890 vldr s14, [pc, #32]
 *   @0x23a894 vmov s13, r0
 *   @0x23a898 vmul.f32 s15, s13, s15
 *   @0x23a89c vdiv.f32 s15, s15, s14
 *   @0x23a8a0 vmov r0, s15
 *   @0x23a8a4 pop {r3, pc}
 *   @0x23a8a8 vldr s15, [pc, #12]
 *   @0x23a8ac vmov r0, s15
 *   @0x23a8b0 pop {r3, pc}
 *   @0x23a8b4 teqmi r4, #0
 *   @0x23a8b8 ldrdmi r0, r1, [r9], #-251
 *   @0x23a8bc andeq r0, r0, r0
 *
 * ══ §166/438 CPhysicsDebugRender::TranslateColour(b2Color const&)  0x23c338  size 72  18 条（0x23c338..0x23c380）
 * @func 0x23c338 0x23c380  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c338 vldr s15, [pc, #60]
 *   @0x23c33c vldr s13, [r1]
 *   @0x23c340 vldr s14, [r1, #4]
 *   @0x23c344 vmul.f32 s13, s13, s15
 *   @0x23c348 vldr s12, [r1, #8]
 *   @0x23c34c vmul.f32 s14, s14, s15
 *   @0x23c350 vmul.f32 s15, s12, s15
 *   @0x23c354 vcvt.s32.f32 s13, s13
 *   @0x23c358 vcvt.s32.f32 s14, s14
 *   @0x23c35c vmov r0, s13
 *   @0x23c360 vcvt.s32.f32 s15, s15
 *   @0x23c364 vmov r1, s14
 *   @0x23c368 vmov r2, s15
 *   @0x23c36c uxtb r0, r0
 *   @0x23c370 uxtb r1, r1
 *   @0x23c374 uxtb r2, r2
 *   @0x23c378 b 0x169d80 <_Z20GR_Draw_Create_Coloriii>
 *   @0x23c37c orrmi r0, r0, #0
 *
 * ══ §167/438 C_UTF16String::~C_UTF16String()  0x23c748  size 72  18 条（0x23c748..0x23c790）
 * @func 0x23c748 0x23c790  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×1 / 0x2c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c748 push {r4, lr}
 *   @0x23c74c mov r4, r0
 *   @0x23c750 ldr r0, [r0, #0x4]
 *   @0x23c754 ldr r3, [pc, #0x2c]
 *   @0x23c758 cmp r0, #0
 *   @0x23c75c ldr r3, [pc, r3]
 *   @0x23c760 add r3, r3, #8
 *   @0x23c764 str r3, [r4]
 *   @0x23c768 beq 0x23c770 <_ZN13C_UTF16StringD2Ev+0x28>
 *   @0x23c76c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x23c770 ldr r3, [pc, #0x14]
 *   @0x23c774 mov r0, r4
 *   @0x23c778 ldr r3, [pc, r3]
 *   @0x23c77c add r3, r3, #8
 *   @0x23c780 str r3, [r4]
 *   @0x23c784 pop {r4, pc}
 *   @0x23c788 mulseq r11, r12, sp
 *   @0x23c78c andseq r4, r11, r8, ror sp
 *
 * ══ §168/438 YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int)  0x2400ec  size 72  18 条（0x2400ec..0x240134）
 * @func 0x2400ec 0x240134  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x24×1 / 0xc×1 / 0x8×1 / 0x11×1 / 0x18×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2400ec ldr r12, [r1, #0x24]
 *   @0x2400f0 mov r3, #0
 *   @0x2400f4 str r1, [r0]
 *   @0x2400f8 cmp r12, r3
 *   @0x2400fc str r2, [r0, #0xc]
 *   @0x240100 str r3, [r0, #0x4]
 *   @0x240104 str r3, [r0, #0x8]
 *   @0x240108 strb r3, [r0, #0x11]
 *   @0x24010c str r3, [r0, #0x18]
 *   @0x240110 strb r3, [r0, #0x10]
 *   @0x240114 str r3, [r0, #0x14]
 *   @0x240118 beq 0x240128 <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei+0x3c>
 *   @0x24011c ldr r3, [r1, #0x60]
 *   @0x240120 cmp r3, #0
 *   @0x240124 bxne lr
 *   @0x240128 mov r3, #2
 *   @0x24012c str r3, [r0, #0x4]
 *   @0x240130 bx lr
 *
 * ══ §169/438 F_JSFinishFinally(RValue&, CInstance*, CInstance*, int, RValue*)  0x24e2f4  size 72  18 条（0x24e2f4..0x24e33c）
 * @func 0x24e2f4 0x24e33c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UnwindExceptionStack()
 * 字段偏移 top8: 0x38×1 / 0x1c×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24e2f4 ldr r3, [pc, #0x38]
 *   @0x24e2f8 push {r4, lr}
 *   @0x24e2fc ldr r3, [pc, r3]
 *   @0x24e300 mov r4, r0
 *   @0x24e304 ldrb r3, [r3]
 *   @0x24e308 cmp r3, #0
 *   @0x24e30c popeq {r4, pc}
 *   @0x24e310 bl 0x24e0b4 <_Z20UnwindExceptionStackv>
 *   @0x24e314 ldr r12, [pc, #0x1c]
 *   @0x24e318 ldr r12, [pc, r12]
 *   @0x24e31c ldm r12!, {r0, r1, r2, r3}
 *   @0x24e320 str r0, [r4]
 *   @0x24e324 str r1, [r4, #0x4]
 *   @0x24e328 str r2, [r4, #0x8]
 *   @0x24e32c str r3, [r4, #0xc]
 *   @0x24e330 pop {r4, pc}
 *   @0x24e334 ldrsheq r3, [r10], -r8
 *   @0x24e338 andseq pc, r9, r0, lsl r10
 *
 * ══ §170/438 CThread::Start(void* (*)(void*), void*, CThread::ePriority)  0x27e0c0  size 72  18 条（0x27e0c0..0x27e108）
 * @func 0x27e0c0 0x27e108  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6cdc
 * 字段偏移 top8: 0xc×1 / 0x2c×1 / 0x10×1 / 0x9×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e0c0 push {r3, r4, r5, lr}
 *   @0x27e0c4 mov r5, #1
 *   @0x27e0c8 str r2, [r0, #0xc]
 *   @0x27e0cc mov r3, r0
 *   @0x27e0d0 ldr r2, [pc, #0x2c]
 *   @0x27e0d4 mov r4, r0
 *   @0x27e0d8 str r1, [r0, #0x10]
 *   @0x27e0dc mov r1, #0
 *   @0x27e0e0 strb r5, [r0, #0x9]
 *   @0x27e0e4 add r2, pc, r2
 *   @0x27e0e8 bl 0xb6cdc <pthread_create@plt>
 *   @0x27e0ec cmp r0, #0
 *   @0x27e0f0 str r0, [r4, #0x4]
 *   @0x27e0f4 movne r0, #0
 *   @0x27e0f8 strbne r0, [r4, #0x9]
 *   @0x27e0fc moveq r0, r5
 *   @0x27e100 pop {r3, r4, r5, pc}
 *   @0x27e104 .word 0xffffffb8
 *
 * ══ §171/438 spAnimationStateData_setMixByName  0x283c60  size 72  18 条（0x283c60..0x283ca8）
 * @func 0x283c60 0x283ca8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findAnimation×2
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283c60 push {r4, r5, r6, r7, r8, lr}
 *   @0x283c64 mov r4, r0
 *   @0x283c68 ldr r0, [r0]
 *   @0x283c6c mov r5, r2
 *   @0x283c70 mov r6, r3
 *   @0x283c74 bl 0x28b1dc <spSkeletonData_findAnimation>
 *   @0x283c78 subs r7, r0, #0
 *   @0x283c7c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x283c80 mov r1, r5
 *   @0x283c84 ldr r0, [r4]
 *   @0x283c88 bl 0x28b1dc <spSkeletonData_findAnimation>
 *   @0x283c8c subs r2, r0, #0
 *   @0x283c90 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x283c94 mov r0, r4
 *   @0x283c98 mov r1, r7
 *   @0x283c9c mov r3, r6
 *   @0x283ca0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x283ca4 b 0x283bb0 <spAnimationStateData_setMix>
 *
 * ══ §172/438 spBoundingBoxAttachment_create  0x285af8  size 72  18 条（0x285af8..0x285b40）
 * @func 0x285af8 0x285b40  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / _spAttachment_init
 * 字段偏移 top8: 0x38×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285af8 ldr r2, [pc, #0x38]
 *   @0x285afc mov r1, #36
 *   @0x285b00 push {r3, r4, r5, lr}
 *   @0x285b04 add r2, pc, r2
 *   @0x285b08 mov r5, r0
 *   @0x285b0c mov r3, #44
 *   @0x285b10 mov r0, #1
 *   @0x285b14 bl 0x285c4c <_calloc>
 *   @0x285b18 ldr r3, [pc, #0x1c]
 *   @0x285b1c mov r1, r5
 *   @0x285b20 mov r2, #1
 *   @0x285b24 ldr r3, [pc, r3]
 *   @0x285b28 mov r4, r0
 *   @0x285b2c bl 0x284c18 <_spAttachment_init>
 *   @0x285b30 mov r0, r4
 *   @0x285b34 pop {r3, r4, r5, pc}
 *   @0x285b38 andeq r1, sp, r0, asr r12
 *   @0x285b3c ldrsbeq r11, [r6], -r8
 *
 * ══ §173/438 spPathAttachment_create  0x2876f4  size 72  18 条（0x2876f4..0x28773c）
 * @func 0x2876f4 0x28773c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / _spAttachment_init
 * 字段偏移 top8: 0x38×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2876f4 ldr r2, [pc, #0x38]
 *   @0x2876f8 mov r1, #52
 *   @0x2876fc push {r3, r4, r5, lr}
 *   @0x287700 add r2, pc, r2
 *   @0x287704 mov r5, r0
 *   @0x287708 mov r3, #45
 *   @0x28770c mov r0, #1
 *   @0x287710 bl 0x285c4c <_calloc>
 *   @0x287714 ldr r3, [pc, #0x1c]
 *   @0x287718 mov r1, r5
 *   @0x28771c mov r2, #4
 *   @0x287720 ldr r3, [pc, r3]
 *   @0x287724 mov r4, r0
 *   @0x287728 bl 0x284c18 <_spAttachment_init>
 *   @0x28772c mov r0, r4
 *   @0x287730 pop {r3, r4, r5, pc}
 *   @0x287734 andeq r0, sp, r12, lsr r2
 *   @0x287738 andseq r10, r6, r4, ror #3
 *
 * ══ §174/438 png_zalloc  0x2a5aa8  size 72  18 条（0x2a5aa8..0x2a5af0）
 * @func 0x2a5aa8 0x2a5af0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivsi3 / png_malloc
 * 字段偏移 top8: 0x24×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5aa8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2a5aac mov r7, r2
 *   @0x2a5ab0 cbz r0, 0x2a5ace <png_zalloc+0x26>
 *   @0x2a5ab4 sasxmi r5, r1, r0
 *   @0x2a5ab8 mov.w r0, #0xffffffff
 *   @0x2a5abc blx 0x318c48 <__udivsi3>
 *   @0x2a5ac0 cmp r6, r0
 *   @0x2a5ac4 ldr r1, [pc, #0x24]
 *   @0x2a5ac8 add r1, pc
 *   @0x2a5acc .word 0x2000fcd3
 *   @0x2a5ad0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2a5ad4 strtmi r1, [r0], -r0, lsl #7
 *   @0x2a5ad8 str.w r3, [r4, #0x130]
 *   @0x2a5adc mul r1, r6, r7
 *   @0x2a5ae0 bl 0x2a6ca0 <png_malloc>
 *   @0x2a5ae4 str.w r5, [r4, #0x130]
 *   @0x2a5ae8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2a5aec str r3, [r6, #0x74]
 *
 * ══ §175/438 png_error  0x2a642c  size 72  18 条（0x2a642c..0x2a6474）
 * @func 0x2a642c 0x2a6474  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c88
 * 字段偏移 top8: 0x2c×2 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a642c push {r4, r5, r6, lr}
 *   @0x2a6430 mov r4, r0
 *   @0x2a6434 ldr.w r3, [r0, #0x104]
 *   @0x2a6438 cbz r3, 0x2a643c <png_error+0x10>
 *   @0x2a643c ldr r0, [pc, #0x2c]
 *   @0x2a6440 ldr r1, [pc, #0x2c]
 *   @0x2a6444 ldr r0, [r0]
 *   @0x2a6448 ldrbtmi r0, [r9], #-1448
 *   @0x2a644c mov r0, r5
 *   @0x2a6450 andhs lr, r10, r10, lsr #20
 *   @0x2a6454 mov r1, r5
 *   @0x2a6458 .word 0xb12cea2c
 *   @0x2a645c ldr.w r3, [r4, #0x100]
 *   @0x2a6460 cbz r3, 0x2a6468 <png_error+0x3c>
 *   @0x2a6464 movs r1, #0x1
 *   @0x2a6468 blx 0xb6c88 <abort@plt>
 *   @0x2a646c add sp, #0x18
 *   @0x2a6470 str r7, [r7, #0x24]
 *
 * ══ §176/438 png_handle_IEND  0x2ac0c8  size 72  18 条（0x2ac0c8..0x2ac110）
 * @func 0x2ac0c8 0x2ac110  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3eccf0
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ac0c8 push {r3, r4, r5, lr}
 *   @0x2ac0cc ldr.w r3, [r0, #0x12c]
 *   @0x2ac0d0 mov r5, r2
 *   @0x2ac0d4 blhs 0x3eccf0 <af_shaw_script_class>
 *   @0x2ac0d8 beq 0x2ac0e2 <png_handle_IEND+0x1a>
 *   @0x2ac0dc add r1, pc
 *   @0x2ac0e0 .word 0xf8d4f9a5
 *   @0x2ac0e4 .word 0xf043312c
 *   @0x2ac0e8 .word 0xf8c40318
 *   @0x2ac0ec .word 0xb125312c
 *   @0x2ac0f0 ldr r1, [pc, #0x18]
 *   @0x2ac0f4 add r1, pc
 *   @0x2ac0f8 .word 0x4620f9bd
 *   @0x2ac0fc mov r1, r5
 *   @0x2ac100 .word 0xf7ff4038
 *   @0x2ac104 svclt #0xbdc7
 *   @0x2ac108 lsrs r3, r2, #0x12
 *   @0x2ac10c lsrs r4, r1, #0x12
 *
 * ══ §177/438 jpeg_set_marker_processor  0x2b60a4  size 72  18 条（0x2b60a4..0x2b60ec）
 * @func 0x2b60a4 0x2b60ec  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x194×1 / 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b60a4 ldr r12, [r0, #0x194]
 *   @0x2b60a8 cmp r1, #254
 *   @0x2b60ac push {r4, lr}
 *   @0x2b60b0 streq r2, [r12, #0x18]
 *   @0x2b60b4 popeq {r4, pc}
 *   @0x2b60b8 sub r4, r1, #224
 *   @0x2b60bc cmp r4, #15
 *   @0x2b60c0 addls r1, r12, r1, lsl #2
 *   @0x2b60c4 strls r2, [r1, #-0x364]
 *   @0x2b60c8 popls {r4, pc}
 *   @0x2b60cc ldr r2, [r0]
 *   @0x2b60d0 mov r12, #68
 *   @0x2b60d4 str r1, [r2, #0x18]
 *   @0x2b60d8 ldr r3, [r0]
 *   @0x2b60dc str r12, [r2, #0x14]
 *   @0x2b60e0 ldr r3, [r3]
 *   @0x2b60e4 blx r3
 *   @0x2b60e8 pop {r4, pc}
 *
 * ══ §178/438 b2PrismaticJoint::GetReactionForce(float) const  0x2cf138  size 72  18 条（0x2cf138..0x2cf180）
 * @func 0x2cf138 0x2cf180  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf138 vldr s14, [r1, #116]
 *   @0x2cf13c vldr s15, [r1, #112]
 *   @0x2cf140 vadd.f32 s15, s14, s15
 *   @0x2cf144 vldr s9, [r1, #184]
 *   @0x2cf148 vldr s14, [r1, #188]
 *   @0x2cf14c vldr s12, [r1, #104]
 *   @0x2cf150 vldr s10, [r1, #196]
 *   @0x2cf154 vldr s11, [r1, #192]
 *   @0x2cf158 vmov s13, r2
 *   @0x2cf15c vmul.f32 s14, s15, s14
 *   @0x2cf160 vmul.f32 s15, s15, s9
 *   @0x2cf164 vmla.f32 s14, s12, s10
 *   @0x2cf168 vmla.f32 s15, s12, s11
 *   @0x2cf16c vmul.f32 s14, s13, s14
 *   @0x2cf170 vmul.f32 s15, s13, s15
 *   @0x2cf174 vstr s14, [r0, #4]
 *   @0x2cf178 vstr s15, [r0]
 *   @0x2cf17c bx lr
 *
 * ══ §179/438 b2ParticleColor::GetColor() const  0x2d44c8  size 72  18 条（0x2d44c8..0x2d4510）
 * @func 0x2d44c8 0x2d4510  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfe2f4718
 * 字段偏移 top8: 0x1×1 / 0x2×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d44c8 ldrb r2, [r1, #0x1]
 *   @0x2d44cc vldr s15, [pc, #56]
 *   @0x2d44d0 vmov s12, r2
 *   @0x2d44d4 ldrb r2, [r1]
 *   @0x2d44d8 ldrb r1, [r1, #0x2]
 *   @0x2d44dc vcvt.f32.s32 s12, s12
 *   @0x2d44e0 vmov s14, r2
 *   @0x2d44e4 vmov s13, r1
 *   @0x2d44e8 vcvt.f32.s32 s14, s14
 *   @0x2d44ec vcvt.f32.s32 s13, s13
 *   @0x2d44f0 vmul.f32 s12, s12, s15
 *   @0x2d44f4 vmul.f32 s14, s14, s15
 *   @0x2d44f8 vstr s12, [r0, #4]
 *   @0x2d44fc vmul.f32 s15, s13, s15
 *   @0x2d4500 vstr s14, [r0]
 *   @0x2d4504 vstr s15, [r0, #8]
 *   @0x2d4508 bx lr
 *   @0x2d450c bllo 0xfe2f4718 <b2_toiTime+0xfffffffffdb9b274>
 *
 * ══ §180/438 b2ParticleSystem::GetParticleUserDataBuffer()  0x2d98ac  size 72  18 条（0x2d98ac..0x2d98f4）
 * @func 0x2d98ac 0x2d98f4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / 0xb65b0
 * 字段偏移 top8: 0x60×2 / 0x28×2 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d98ac push {r3, r4, r5, lr}
 *   @0x2d98b0 mov r5, r0
 *   @0x2d98b4 ldr r4, [r0, #0x60]
 *   @0x2d98b8 cmp r4, #0
 *   @0x2d98bc beq 0x2d98cc <_ZN16b2ParticleSystem25GetParticleUserDataBufferEv+0x20>
 *   @0x2d98c0 str r4, [r5, #0x60]
 *   @0x2d98c4 mov r0, r4
 *   @0x2d98c8 pop {r3, r4, r5, pc}
 *   @0x2d98cc ldr r1, [r0, #0x28]
 *   @0x2d98d0 ldr r0, [r0, #0xd4]
 *   @0x2d98d4 lsl r1, r1, #2
 *   @0x2d98d8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2d98dc ldr r2, [r5, #0x28]
 *   @0x2d98e0 mov r1, #0
 *   @0x2d98e4 lsl r2, r2, #2
 *   @0x2d98e8 mov r4, r0
 *   @0x2d98ec bl 0xb65b0 <memset@plt>
 *   @0x2d98f0 b 0x2d98c0 <_ZN16b2ParticleSystem25GetParticleUserDataBufferEv+0x14>
 *
 * ══ §181/438 FT_Get_Track_Kerning  0x2e58ac  size 72  18 条（0x2e58ac..0x2e58f4）
 * @func 0x2e58ac 0x2e58f4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×1 / 0x20×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e58ac push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2e58b0 mov r7, r1
 *   @0x2e58b4 mov r5, r3
 *   @0x2e58b8 cbz r0, 0x2e58e4 <FT_Get_Track_Kerning+0x38>
 *   @0x2e58bc ldr r0, [r0, #0x60]
 *   @0x2e58c0 ldr r3, [r3, #0x20]
 *   @0x2e58c4 movs r0, #0x7
 *   @0x2e58c8 stmdbmi r9, {r4, r5, r6, r7, r8, pc}
 *   @0x2e58cc add r1, pc
 *   @0x2e58d0 cmp r0, #0x0
 *   @0x2e58d4 ldr r6, [r0]
 *   @0x2e58d8 mov r0, r4
 *   @0x2e58dc mov r3, r5
 *   @0x2e58e0 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e58e4 movs r0, #0x23
 *   @0x2e58e8 strdhs r8, r9, [r6], -r0
 *   @0x2e58ec pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e58f0 ldrh r0, [r3, #0x30]
 *
 * ══ §182/438 FT_Get_Postscript_Name  0x2e5b78  size 72  18 条（0x2e5b78..0x2e5bc0）
 * @func 0x2e5b78 0x2e5bc0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e9c78+0x4130
 * 字段偏移 top8: 0x1c×1 / 0x1a×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5b78 push {r4, lr}
 *   @0x2e5b7c cbnz r0, 0x2e5b82 <FT_Get_Postscript_Name+0xa>
 *   @0x2e5b80 pop {r4, pc}
 *   @0x2e5b84 ldmibvs r11, {r7, r12, sp} ^
 *   @0x2e5b88 adds r2, r3, #0x2
 *   @0x2e5b8c cbnz r3, 0x2e5bb0 <FT_Get_Postscript_Name+0x38>
 *   @0x2e5b90 ldr r2, [r0]
 *   @0x2e5b94 cbz r2, 0x2e5b9e <FT_Get_Postscript_Name+0x26>
 *   @0x2e5b98 add r1, pc
 *   @0x2e5b9c mov r3, r0
 *   @0x2e5ba0 blhs 0x2edda8 <FT_Done_Memory+0x4134>
 *   @0x2e5ba4 ite ne
 *   @0x2e5ba8 mvneq r1, #0x1
 *   @0x2e5bac str r1, [r2, #0x1c]
 *   @0x2e5bb0 ldr r3, [r3]
 *   @0x2e5bb4 beq 0x2e5b7e <FT_Get_Postscript_Name+0x6>
 *   @0x2e5bb8 blx r3
 *   @0x2e5bbc ldrh r7, [r3, #0x1a]
 *
 * ══ §183/438 FT_Load_Sfnt_Table  0x2e5bf4  size 72  18 条（0x2e5bf4..0x2e5c3c）
 * @func 0x2e5bf4 0x2e5c3c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x60×1 / 0x16×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5bf4 push.w {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x2e5bf8 mov r6, r1
 *   @0x2e5bfc mov r7, r3
 *   @0x2e5c00 cbz r0, 0x2e5c30 <FT_Load_Sfnt_Table+0x3c>
 *   @0x2e5c04 lsls r3, r0, #0x1c
 *   @0x2e5c08 ldr r0, [r4, #0x60]
 *   @0x2e5c0c ldr r5, [r5, #0x20]
 *   @0x2e5c10 movs r0, #0x7
 *   @0x2e5c14 ldr r1, [pc, #0x20]
 *   @0x2e5c18 blx r5
 *   @0x2e5c1c beq 0x2e5c10 <FT_Load_Sfnt_Table+0x1c>
 *   @0x2e5c20 mov r1, r6
 *   @0x2e5c24 mov r3, r7
 *   @0x2e5c28 ldr r5, [r0]
 *   @0x2e5c2c blx r5
 *   @0x2e5c30 movs r0, #0x23
 *   @0x2e5c34 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e5c38 ldrh r6, [r6, #0x16]
 *
 * ══ §184/438 FT_Sfnt_Table_Info  0x2e5c3c  size 72  18 条（0x2e5c3c..0x2e5c84）
 * @func 0x2e5c3c 0x2e5c84  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x60×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5c3c push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr}
 *   @0x2e5c40 mov r6, r1
 *   @0x2e5c44 mov r8, r3
 *   @0x2e5c48 cbz r0, 0x2e5c78 <FT_Sfnt_Table_Info+0x3c>
 *   @0x2e5c4c lsls r3, r0, #0x1c
 *   @0x2e5c50 ldr r0, [r4, #0x60]
 *   @0x2e5c54 ldr r5, [r5, #0x20]
 *   @0x2e5c58 movs r0, #0x7
 *   @0x2e5c5c ldr r1, [pc, #0x20]
 *   @0x2e5c60 blx r5
 *   @0x2e5c64 beq 0x2e5c58 <FT_Sfnt_Table_Info+0x1c>
 *   @0x2e5c68 ldrtmi r8, [r1], -r0
 *   @0x2e5c6c ldr r5, [r0, #0x8]
 *   @0x2e5c70 mov r0, r4
 *   @0x2e5c74 blx r5
 *   @0x2e5c78 movs r0, #0x23
 *   @0x2e5c7c pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e5c80 ldrh r6, [r5, #0x14]
 *
 * ══ §185/438 png_get_iCCP  0x2a68c0  size 70  18 条（0x2a68c0..0x2a6906）
 * @func 0x2a68c0 0x2a6906  size 70  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a68c0 push {r4, r5, lr}
 *   @0x2a68c4 ldr r4, [sp, #0x10]
 *   @0x2a68c8 cbz r1, 0x2a68f6 <png_get_iCCP+0x36>
 *   @0x2a68cc ands r0, r0, #0x1000
 *   @0x2a68d0 beq 0x2a6904 <png_get_iCCP+0x44>
 *   @0x2a68d4 cbz r5, 0x2a68fe <png_get_iCCP+0x3e>
 *   @0x2a68d8 ldr.w r0, [r1, #0xc4]
 *   @0x2a68dc str r0, [r2]
 *   @0x2a68e0 .word 0xf8d15080
 *   @0x2a68e4 eorvs r2, r10, r8, asr #1
 *   @0x2a68e8 ldr.w r2, [r1, #0xcc]
 *   @0x2a68ec str r2, [r4]
 *   @0x2a68f0 ldrsbvs r2, [r10], -r0
 *   @0x2a68f4 pop {r4, r5, pc}
 *   @0x2a68f8 pop {r4, r5, pc}
 *   @0x2a68fc pop {r4, r5, pc}
 *   @0x2a6900 pop {r4, r5, pc}
 *   @0x2a6904 pop {r4, r5, pc}
 *
 * ══ §186/438 FT_Vector_Transform_Scaled  0x2e5050  size 70  18 条（0x2e5050..0x2e5096）
 * @func 0x2e5050 0x2e5096  size 70  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_MulDiv×4
 * 字段偏移 top8: 0x4×2 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5050 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2e5054 mov r5, r1
 *   @0x2e5058 cbz r0, 0x2e5092 <FT_Vector_Transform_Scaled+0x42>
 *   @0x2e505c lsls r6, r2, #0x10
 *   @0x2e5060 ldr r0, [r0]
 *   @0x2e5064 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5068 ldr r1, [r5, #0x4]
 *   @0x2e506c mov r7, r0
 *   @0x2e5070 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5074 ldr r1, [r5, #0x8]
 *   @0x2e5078 add r7, r0
 *   @0x2e507c bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5080 ldr r1, [r5, #0xc]
 *   @0x2e5084 mov r8, r0
 *   @0x2e5088 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e508c str r7, [r4]
 *   @0x2e5090 str r0, [r4, #0x4]
 *   @0x2e5094 push {r4, r5, r6, r7, r8, pc}
 *
 * ══ §187/438 FT_Set_Char_Size  0x2e578c  size 70  18 条（0x2e578c..0x2e57d2）
 * @func 0x2e578c 0x2e57d2  size 70  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x8×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e578c push {r4, r5, lr}
 *   @0x2e5790 ldr r4, [sp, #0x28]
 *   @0x2e5794 cmp r2, #0x0
 *   @0x2e5798 moveq r2, r1
 *   @0x2e579c mov r1, r2
 *   @0x2e57a0 cmp r4, #0x0
 *   @0x2e57a4 moveq r4, r3
 *   @0x2e57a8 mov r3, r4
 *   @0x2e57ac it lt
 *   @0x2e57b0 cmp r2, #0x40
 *   @0x2e57b4 movlt r2, #0x40
 *   @0x2e57b8 movs r4, #0x48
 *   @0x2e57bc str r1, [sp, #0x8]
 *   @0x2e57c0 movs r5, #0x0
 *   @0x2e57c4 str r5, [sp, #0x4]
 *   @0x2e57c8 str r4, [sp, #0x14]
 *   @0x2e57cc andlt pc, r7, pc, lsr #31
 *   @0x2e57d0 pop {r4, r5, pc}
 *
 * ══ §188/438 FT_Attach_Stream  0x2e74bc  size 70  18 条（0x2e74bc..0x2e7502）
 * @func 0x2e74bc 0x2e7502  size 70  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Stream_New / FT_Stream_Free
 * 字段偏移 top8: 0x60×1 / 0x4×1 / 0x50×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e74bc push {r0, r1, r4, r5, r6, lr}
 *   @0x2e74c0 mov r4, r0
 *   @0x2e74c4 ldr r5, [r0, #0x60]
 *   @0x2e74c8 ldr r0, [r5, #0x4]
 *   @0x2e74cc bl 0x2e73dc <FT_Stream_New>
 *   @0x2e74d0 cbnz r0, 0x2e74fe <FT_Attach_Stream+0x42>
 *   @0x2e74d4 ldr r3, [r3, #0x50]
 *   @0x2e74d8 mov r0, r4
 *   @0x2e74dc blx r3
 *   @0x2e74e0 b 0x2e74e4 <FT_Attach_Stream+0x28>
 *   @0x2e74e4 ldr r1, [r6, #0x10]
 *   @0x2e74e8 cbz r1, 0x2e74f0 <FT_Attach_Stream+0x34>
 *   @0x2e74ec ubfx r1, r1, #0x1, #0x1
 *   @0x2e74f0 bl 0x2e745e <FT_Stream_Free>
 *   @0x2e74f4 mov r0, r4
 *   @0x2e74f8 movs r0, #0x23
 *   @0x2e74fc movs r0, #0x22
 *   @0x2e7500 pop {r4, r5, r6, pc}
 *
 * ══ §189/438 FT_GlyphLoader_CheckSubGlyphs  0x2e8274  size 70  18 条（0x2e8274..0x2e82ba）
 * @func 0x2e8274 0x2e82ba  size 70  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_GlyphLoader_CheckSubGlyphs+0x40 / ft_mem_realloc
 * 字段偏移 top8: 0xc×3 / 0x54×1 / 0x30×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8274 push {r4, r5, lr}
 *   @0x2e8278 mov r4, r0
 *   @0x2e827c ldr r5, [r4, #0x54]
 *   @0x2e8280 ldr r3, [r4, #0x30]
 *   @0x2e8284 add r3, r5
 *   @0x2e8288 add r1, r3
 *   @0x2e828c bls 0x2e82b4 <FT_GlyphLoader_CheckSubGlyphs+0x40>
 *   @0x2e8290 adds r5, r1, #0x1
 *   @0x2e8294 .word 0x21200501
 *   @0x2e8298 str r3, [sp]
 *   @0x2e829c str r3, [sp, #0x4]
 *   @0x2e82a0 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e82a4 ldr r3, [sp, #0xc]
 *   @0x2e82a8 cbnz r3, 0x2e82b4 <FT_GlyphLoader_CheckSubGlyphs+0x40>
 *   @0x2e82ac str r5, [r4, #0xc]
 *   @0x2e82b0 strvs r1, [r0, #0x43]!
 *   @0x2e82b4 ldr r0, [sp, #0xc]
 *   @0x2e82b8 pop {r4, r5, pc}
 *
 * ══ §190/438 F_Vertex_Create_Buffer_Ext_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8b80  size 68  17 条（0xc8b80..0xc8bc4）
 * @func 0xc8b80 0xc8bc4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int) / AllocBufferVertex(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8b80 push {r4, lr}
 *   @0xc8b84 mov r3, #0
 *   @0xc8b88 mov r1, r3
 *   @0xc8b8c str r3, [r0, #0xc]
 *   @0xc8b90 mov r4, r0
 *   @0xc8b94 ldr r0, [sp, #0x8]
 *   @0xc8b98 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc8b9c cmp r0, #256
 *   @0xc8ba0 movlo r0, #256
 *   @0xc8ba4 bl 0xc8978 <_Z17AllocBufferVertexi>
 *   @0xc8ba8 vmov s15, r0
 *   @0xc8bac vcvt.f64.s32 d7, s15
 *   @0xc8bb0 vmov r0, r1, d7
 *   @0xc8bb4 vmov r2, s14
 *   @0xc8bb8 mov r3, r1
 *   @0xc8bbc stm r4, {r2, r3}
 *   @0xc8bc0 pop {r4, pc}
 *
 * ══ §191/438 F_Vertex_Float1_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc9514  size 68  17 条（0xc9514..0xc9558）
 * @func 0xc9514 0xc9558  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextType(yyVertexType) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9514 push {r3, r4, r5, lr}
 *   @0xc9518 mov r1, r3
 *   @0xc951c ldr r4, [sp, #0x10]
 *   @0xc9520 mov r3, #2
 *   @0xc9524 mov r2, r4
 *   @0xc9528 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc952c cmp r0, #0
 *   @0xc9530 popeq {r3, r4, r5, pc}
 *   @0xc9534 mov r1, #1
 *   @0xc9538 bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType>
 *   @0xc953c subs r5, r0, #0
 *   @0xc9540 popeq {r3, r4, r5, pc}
 *   @0xc9544 mov r0, r4
 *   @0xc9548 mov r1, #1
 *   @0xc954c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc9550 str r0, [r5]
 *   @0xc9554 pop {r3, r4, r5, pc}
 *
 * ══ §192/438 IBuffer::~IBuffer()  0xcb818  size 68  17 条（0xcb818..0xcb85c）
 * @func 0xcb818 0xcb85c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×2 / 0x3c×1 / 0x34×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcb818 ldrb r2, [r0, #0x3c]
 *   @0xcb81c ldr r3, [pc, #0x34]
 *   @0xcb820 cmp r2, #0
 *   @0xcb824 ldr r3, [pc, r3]
 *   @0xcb828 push {r4, lr}
 *   @0xcb82c add r3, r3, #8
 *   @0xcb830 mov r4, r0
 *   @0xcb834 str r3, [r0]
 *   @0xcb838 beq 0xcb844 <_ZN7IBufferD2Ev+0x2c>
 *   @0xcb83c ldr r0, [r0, #0x4]
 *   @0xcb840 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcb844 mov r3, #0
 *   @0xcb848 mov r0, r4
 *   @0xcb84c str r3, [r4, #0x4]
 *   @0xcb850 str r3, [r4, #0xc]
 *   @0xcb854 pop {r4, pc}
 *   @0xcb858 eorseq r2, r2, r8, ror #5
 *
 * ══ §193/438 FINALIZE_Code_Function()  0xce274  size 68  17 条（0xce274..0xce2b8）
 * @func 0xce274 0xce2b8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x20×2 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce274 push {r4, lr}
 *   @0xce278 ldr r4, [pc, #0x2c]
 *   @0xce27c ldr r4, [pc, r4]
 *   @0xce280 ldr r0, [r4]
 *   @0xce284 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xce288 ldr r2, [pc, #0x20]
 *   @0xce28c ldr r1, [pc, #0x20]
 *   @0xce290 mov r3, #0
 *   @0xce294 ldr r2, [pc, r2]
 *   @0xce298 str r3, [r4]
 *   @0xce29c add r1, pc, r1
 *   @0xce2a0 str r3, [r2]
 *   @0xce2a4 str r3, [r1]
 *   @0xce2a8 pop {r4, pc}
 *   @0xce2ac mlaseq r1, r12, r8, pc
 *   @0xce2b0 eorseq pc, r1, r0, lsl #17
 *   @0xce2b4 eorseq r11, r10, r0, lsr #29
 *
 * ══ §194/438 dsListClear  0x101bd4  size 68  17 条（0x101bd4..0x101c18）
 * @func 0x101bd4 0x101c18  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsListClear(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x24×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101bd4 vmov s13, r0
 *   @0x101bd8 mov r12, #0
 *   @0x101bdc str lr, [sp, #-0x4]!
 *   @0x101be0 vcvt.f64.s32 d7, s13
 *   @0x101be4 sub sp, sp, #44
 *   @0x101be8 mov r1, r12
 *   @0x101bec add r3, sp, #24
 *   @0x101bf0 mov r2, r12
 *   @0x101bf4 str r3, [sp]
 *   @0x101bf8 add r0, sp, #8
 *   @0x101bfc mov r3, #1
 *   @0x101c00 str r12, [sp, #0x8]
 *   @0x101c04 str r12, [sp, #0x24]
 *   @0x101c08 vstr d7, [sp, #24]
 *   @0x101c0c bl 0xfc240 <_Z13F_DsListClearR6RValueP9CInstanceS2_iPS_>
 *   @0x101c10 add sp, sp, #44
 *   @0x101c14 ldr pc, [sp], #4
 *
 * ══ §195/438 F_Frac(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e364  size 68  17 条（0x10e364..0x10e3a8）
 * @func 0x10e364 0x10e3a8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb6718
 * 字段偏移 top8: 0xc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e364 push {r4, r5, r6, r7, lr}
 *   @0x10e368 sub sp, sp, #12
 *   @0x10e36c mov r3, #0
 *   @0x10e370 add r7, sp, #8
 *   @0x10e374 str r3, [r0, #0xc]
 *   @0x10e378 mov r6, r0
 *   @0x10e37c mov r1, r3
 *   @0x10e380 ldr r0, [sp, #0x20]
 *   @0x10e384 mov r4, #0
 *   @0x10e388 mov r5, #0
 *   @0x10e38c strd r4, r5, [r7, #-8]!
 *   @0x10e390 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e394 mov r2, sp
 *   @0x10e398 bl 0xb6718 <modf@plt>
 *   @0x10e39c stm r6, {r0, r1}
 *   @0x10e3a0 add sp, sp, #12
 *   @0x10e3a4 pop {r4, r5, r6, r7, pc}
 *
 * ══ §196/438 F_EventPerform(RValue&, CInstance*, CInstance*, int, RValue*)  0x1147e8  size 68  17 条（0x1147e8..0x11482c）
 * @func 0x1147e8 0x11482c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1147e8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1147ec mov r5, r1
 *   @0x1147f0 ldr r4, [sp, #0x18]
 *   @0x1147f4 mov r1, #0
 *   @0x1147f8 mov r7, r2
 *   @0x1147fc mov r0, r4
 *   @0x114800 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114804 mov r1, #1
 *   @0x114808 mov r6, r0
 *   @0x11480c mov r0, r4
 *   @0x114810 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114814 mov r1, r7
 *   @0x114818 mov r2, r6
 *   @0x11481c mov r3, r0
 *   @0x114820 mov r0, r5
 *   @0x114824 pop {r4, r5, r6, r7, r8, lr}
 *   @0x114828 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *
 * ══ §197/438 F_ColorGetRed(RValue&, CInstance*, CInstance*, int, RValue*)  0x119d78  size 68  17 条（0x119d78..0x119dbc）
 * @func 0x119d78 0x119dbc  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119d78 push {r4, lr}
 *   @0x119d7c mov r3, #0
 *   @0x119d80 mov r4, r0
 *   @0x119d84 str r3, [r0, #0xc]
 *   @0x119d88 mov r1, r3
 *   @0x119d8c ldr r0, [sp, #0x8]
 *   @0x119d90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119d94 asr r3, r0, #31
 *   @0x119d98 lsr r3, r3, #24
 *   @0x119d9c add r2, r0, r3
 *   @0x119da0 uxtb r2, r2
 *   @0x119da4 rsb r2, r3, r2
 *   @0x119da8 vmov s15, r2
 *   @0x119dac vcvt.f64.s32 d7, s15
 *   @0x119db0 vmov r2, r3, d7
 *   @0x119db4 stm r4, {r2, r3}
 *   @0x119db8 pop {r4, pc}
 *
 * ══ §198/438 F_DisplayReset(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a188  size 68  17 条（0x11a188..0x11a1cc）
 * @func 0x11a188 0x11a1cc  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Graphics::SetMultiSample(int) / YYGetBool(RValue const*, int) / Graphics::SetVSync(bool)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a188 push {r4, lr}
 *   @0x11a18c mov r1, #0
 *   @0x11a190 ldr r4, [sp, #0x8]
 *   @0x11a194 mov r0, r4
 *   @0x11a198 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a19c uxtb r0, r0
 *   @0x11a1a0 bl 0x17db20 <_ZN8Graphics14SetMultiSampleEi>
 *   @0x11a1a4 mov r1, #1
 *   @0x11a1a8 mov r0, r4
 *   @0x11a1ac bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11a1b0 bl 0x17db0c <_ZN8Graphics8SetVSyncEb>
 *   @0x11a1b4 ldr r3, [pc, #0xc]
 *   @0x11a1b8 mov r2, #1
 *   @0x11a1bc ldr r3, [pc, r3]
 *   @0x11a1c0 str r2, [r3]
 *   @0x11a1c4 pop {r4, pc}
 *   @0x11a1c8 eoreq r4, sp, r0, lsl r4
 *
 * ══ §199/438 F_DrawGetPixel(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a980  size 68  17 条（0x11a980..0x11a9c4）
 * @func 0x11a980 0x11a9c4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DrawGetPixelExt(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a980 push {r4, lr}
 *   @0x11a984 sub sp, sp, #8
 *   @0x11a988 mov r4, r0
 *   @0x11a98c ldr r12, [sp, #0x10]
 *   @0x11a990 str r12, [sp]
 *   @0x11a994 bl 0x11a8ec <_Z17F_DrawGetPixelExtR6RValueP9CInstanceS2_iPS_>
 *   @0x11a998 ldm r4, {r2, r3}
 *   @0x11a99c vmov d7, r2, r3
 *   @0x11a9a0 vcvt.u32.f64 s15, d7
 *   @0x11a9a4 vmov r2, s15
 *   @0x11a9a8 bic r2, r2, #-16777216
 *   @0x11a9ac vmov s15, r2
 *   @0x11a9b0 vcvt.f64.s32 d7, s15
 *   @0x11a9b4 vmov r2, r3, d7
 *   @0x11a9b8 stm r4, {r2, r3}
 *   @0x11a9bc add sp, sp, #8
 *   @0x11a9c0 pop {r4, pc}
 *
 * ══ §200/438 F_SurfaceSetTarget(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c9e0  size 68  17 条（0x11c9e0..0x11ca24）
 * @func 0x11c9e0 0x11ca24  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGML_surface_set_target_ext(int, int)
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c9e0 push {r3, r4, r5, lr}
 *   @0x11c9e4 mov r5, #0
 *   @0x11c9e8 mov r4, r0
 *   @0x11c9ec mov r1, r5
 *   @0x11c9f0 str r5, [r0, #0xc]
 *   @0x11c9f4 ldr r0, [sp, #0x10]
 *   @0x11c9f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c9fc mov r1, r0
 *   @0x11ca00 mov r0, r5
 *   @0x11ca04 bl 0x171574 <_Z28YYGML_surface_set_target_extii>
 *   @0x11ca08 vmov s15, r0
 *   @0x11ca0c vcvt.f64.u32 d7, s15
 *   @0x11ca10 vmov r0, r1, d7
 *   @0x11ca14 vmov r2, s14
 *   @0x11ca18 mov r3, r1
 *   @0x11ca1c stm r4, {r2, r3}
 *   @0x11ca20 pop {r3, r4, r5, pc}
 *
 * ══ §201/438 YYGML_draw_text(float, float, char const*)  0x122414  size 68  17 条（0x122414..0x122458）
 * @func 0x122414 0x122458  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*) / GR_Text_Draw(float, float, char const*, int, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122414 push {r4, r5, r6, lr}
 *   @0x122418 mov r5, r0
 *   @0x12241c sub sp, sp, #8
 *   @0x122420 mov r0, r2
 *   @0x122424 mov r6, r1
 *   @0x122428 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x12242c mvn r3, #0
 *   @0x122430 mov r1, r6
 *   @0x122434 str r3, [sp]
 *   @0x122438 mov r4, r0
 *   @0x12243c mov r0, r5
 *   @0x122440 mov r2, r4
 *   @0x122444 bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x122448 mov r0, r4
 *   @0x12244c add sp, sp, #8
 *   @0x122450 pop {r4, r5, r6, lr}
 *   @0x122454 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §202/438 F_LoadInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x125d04  size 68  17 条（0x125d04..0x125d48）
 * @func 0x125d04 0x125d48  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x34×1 / 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125d04 ldr r3, [pc, #0x34]
 *   @0x125d08 push {r4, lr}
 *   @0x125d0c ldr r3, [pc, r3]
 *   @0x125d10 mov r4, r0
 *   @0x125d14 ldr r1, [pc, #0x28]
 *   @0x125d18 ldr r0, [r3]
 *   @0x125d1c add r1, pc, r1
 *   @0x125d20 ldr r3, [r0]
 *   @0x125d24 ldr r3, [r3, #0xc]
 *   @0x125d28 blx r3
 *   @0x125d2c mov r3, #0
 *   @0x125d30 str r3, [r4, #0xc]
 *   @0x125d34 str r3, [r4]
 *   @0x125d38 str r3, [r4, #0x4]
 *   @0x125d3c pop {r4, pc}
 *   @0x125d40 eoreq r7, r12, r8, lsl #20
 *   @0x125d44 eoreq r6, r1, r4, asr #3
 *
 * ══ §203/438 F_SplashSetSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x126138  size 68  17 条（0x126138..0x12617c）
 * @func 0x126138 0x12617c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x8×1 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126138 push {r4, lr}
 *   @0x12613c mov r1, #0
 *   @0x126140 ldr r4, [sp, #0x8]
 *   @0x126144 mov r0, r4
 *   @0x126148 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12614c ldr r3, [pc, #0x20]
 *   @0x126150 mov r1, #1
 *   @0x126154 ldr r3, [pc, r3]
 *   @0x126158 str r0, [r3]
 *   @0x12615c mov r0, r4
 *   @0x126160 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126164 ldr r3, [pc, #0xc]
 *   @0x126168 ldr r3, [pc, r3]
 *   @0x12616c str r0, [r3]
 *   @0x126170 pop {r4, pc}
 *   @0x126174 eoreq r8, r12, r12, lsl #18
 *   @0x126178 .word 0x002c88fc
 *
 * ══ §204/438 F_RoomSetBackgroundColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e744  size 68  17 条（0x12e744..0x12e788）
 * @func 0x12e744 0x12e788  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Room_Data(int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e744 push {r3, r4, r5, lr}
 *   @0x12e748 mov r1, #0
 *   @0x12e74c ldr r4, [sp, #0x10]
 *   @0x12e750 mov r0, r4
 *   @0x12e754 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e758 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e75c subs r5, r0, #0
 *   @0x12e760 popeq {r3, r4, r5, pc}
 *   @0x12e764 mov r1, #1
 *   @0x12e768 mov r0, r4
 *   @0x12e76c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e770 mov r1, #2
 *   @0x12e774 str r0, [r5, #0x1c]
 *   @0x12e778 mov r0, r4
 *   @0x12e77c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e780 strb r0, [r5, #0x20]
 *   @0x12e784 pop {r3, r4, r5, pc}
 *
 * ══ §205/438 F_SoundBackgroundTempo(RValue&, CInstance*, CInstance*, int, RValue*)  0x133d18  size 68  17 条（0x133d18..0x133d5c）
 * @func 0x133d18 0x133d5c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x30×1 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133d18 push {r3, lr}
 *   @0x133d1c ldr r3, [pc, #0x30]
 *   @0x133d20 ldr r0, [sp, #0x8]
 *   @0x133d24 ldr r3, [pc, r3]
 *   @0x133d28 ldrb r3, [r3]
 *   @0x133d2c cmp r3, #0
 *   @0x133d30 popne {r3, pc}
 *   @0x133d34 ldr r3, [pc, #0x1c]
 *   @0x133d38 ldr r3, [pc, r3]
 *   @0x133d3c ldrb r1, [r3]
 *   @0x133d40 cmp r1, #0
 *   @0x133d44 popne {r3, pc}
 *   @0x133d48 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133d4c pop {r3, lr}
 *   @0x133d50 b 0x21eb78 <_Z20SND_Set_Global_Tempod>
 *   @0x133d54 eoreq r11, r11, r12
 *   @0x133d58 eoreq r11, r11, r4, lsl r3
 *
 * ══ §206/438 F_SoundGlobalVolume(RValue&, CInstance*, CInstance*, int, RValue*)  0x133d5c  size 68  17 条（0x133d5c..0x133da0）
 * @func 0x133d5c 0x133da0  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x30×1 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133d5c push {r3, lr}
 *   @0x133d60 ldr r3, [pc, #0x30]
 *   @0x133d64 ldr r0, [sp, #0x8]
 *   @0x133d68 ldr r3, [pc, r3]
 *   @0x133d6c ldrb r3, [r3]
 *   @0x133d70 cmp r3, #0
 *   @0x133d74 popne {r3, pc}
 *   @0x133d78 ldr r3, [pc, #0x1c]
 *   @0x133d7c ldr r3, [pc, r3]
 *   @0x133d80 ldrb r1, [r3]
 *   @0x133d84 cmp r1, #0
 *   @0x133d88 popne {r3, pc}
 *   @0x133d8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x133d90 pop {r3, lr}
 *   @0x133d94 b 0x21eb60 <_Z21SND_Set_Global_Volumef>
 *   @0x133d98 eoreq r10, r11, r8, asr #31
 *   @0x133d9c .word 0x002bb2d0
 *
 * ══ §207/438 F_SoundSetSearchDirectory(RValue&, CInstance*, CInstance*, int, RValue*)  0x133da0  size 68  17 条（0x133da0..0x133de4）
 * @func 0x133da0 0x133de4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x30×1 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133da0 push {r3, lr}
 *   @0x133da4 ldr r3, [pc, #0x30]
 *   @0x133da8 ldr r0, [sp, #0x8]
 *   @0x133dac ldr r3, [pc, r3]
 *   @0x133db0 ldrb r3, [r3]
 *   @0x133db4 cmp r3, #0
 *   @0x133db8 popne {r3, pc}
 *   @0x133dbc ldr r3, [pc, #0x1c]
 *   @0x133dc0 ldr r3, [pc, r3]
 *   @0x133dc4 ldrb r1, [r3]
 *   @0x133dc8 cmp r1, #0
 *   @0x133dcc popne {r3, pc}
 *   @0x133dd0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x133dd4 pop {r3, lr}
 *   @0x133dd8 b 0x21e9ec <_Z24SND_Set_Search_DirectoryPKc>
 *   @0x133ddc eoreq r10, r11, r4, lsl #31
 *   @0x133de0 eoreq r11, r11, r12, lsl #5
 *
 * ══ §208/438 F_AudioSystem(RValue&, CInstance*, CInstance*, int, RValue*)  0x1349a0  size 68  17 条（0x1349a0..0x1349e4）
 * @func 0x1349a0 0x1349e4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_Model()
 * 字段偏移 top8: 0x38×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1349a0 ldr r3, [pc, #0x38]
 *   @0x1349a4 push {r4, lr}
 *   @0x1349a8 ldr r3, [pc, r3]
 *   @0x1349ac mov r4, r0
 *   @0x1349b0 ldrb r3, [r3]
 *   @0x1349b4 cmp r3, #0
 *   @0x1349b8 popne {r4, pc}
 *   @0x1349bc str r3, [r0, #0xc]
 *   @0x1349c0 bl 0x216998 <_Z11Audio_Modelv>
 *   @0x1349c4 vmov s15, r0
 *   @0x1349c8 vcvt.f64.s32 d7, s15
 *   @0x1349cc vmov r0, r1, d7
 *   @0x1349d0 vmov r2, s14
 *   @0x1349d4 mov r3, r1
 *   @0x1349d8 stm r4, {r2, r3}
 *   @0x1349dc pop {r4, pc}
 *   @0x1349e0 eoreq r10, r11, r4, lsr #13
 *
 * ══ §209/438 F_AudioCreateEmitter(RValue&, CInstance*, CInstance*, int, RValue*)  0x1349e4  size 68  17 条（0x1349e4..0x134a28）
 * @func 0x1349e4 0x134a28  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_CreateEmitter()
 * 字段偏移 top8: 0x38×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1349e4 ldr r3, [pc, #0x38]
 *   @0x1349e8 push {r4, lr}
 *   @0x1349ec ldr r3, [pc, r3]
 *   @0x1349f0 mov r4, r0
 *   @0x1349f4 ldrb r3, [r3]
 *   @0x1349f8 cmp r3, #0
 *   @0x1349fc popne {r4, pc}
 *   @0x134a00 str r3, [r0, #0xc]
 *   @0x134a04 bl 0x2169ac <_Z19Audio_CreateEmitterv>
 *   @0x134a08 vmov s15, r0
 *   @0x134a0c vcvt.f64.s32 d7, s15
 *   @0x134a10 vmov r0, r1, d7
 *   @0x134a14 vmov r2, s14
 *   @0x134a18 mov r3, r1
 *   @0x134a1c stm r4, {r2, r3}
 *   @0x134a20 pop {r4, pc}
 *   @0x134a24 eoreq r10, r11, r0, ror #12
 *
 * ══ §210/438 F_Audio_GetRecorderCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x135b0c  size 68  17 条（0x135b0c..0x135b50）
 * @func 0x135b0c 0x135b50  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetRecorderCount()
 * 字段偏移 top8: 0x38×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135b0c ldr r3, [pc, #0x38]
 *   @0x135b10 push {r4, lr}
 *   @0x135b14 ldr r3, [pc, r3]
 *   @0x135b18 mov r4, r0
 *   @0x135b1c ldrb r3, [r3]
 *   @0x135b20 cmp r3, #0
 *   @0x135b24 popne {r4, pc}
 *   @0x135b28 str r3, [r0, #0xc]
 *   @0x135b2c bl 0x21c5b8 <_Z22Audio_GetRecorderCountv>
 *   @0x135b30 vmov s15, r0
 *   @0x135b34 vcvt.f64.s32 d7, s15
 *   @0x135b38 vmov r0, r1, d7
 *   @0x135b3c vmov r2, s14
 *   @0x135b40 mov r3, r1
 *   @0x135b44 stm r4, {r2, r3}
 *   @0x135b48 pop {r4, pc}
 *   @0x135b4c eoreq r9, r11, r8, lsr r5
 *
 * ══ §211/438 F_AudioGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x135e1c  size 68  17 条（0x135e1c..0x135e60）
 * @func 0x135e1c 0x135e60  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetListenerMask()
 * 字段偏移 top8: 0x38×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135e1c ldr r3, [pc, #0x38]
 *   @0x135e20 push {r4, lr}
 *   @0x135e24 ldr r3, [pc, r3]
 *   @0x135e28 mov r4, r0
 *   @0x135e2c ldrb r3, [r3]
 *   @0x135e30 cmp r3, #0
 *   @0x135e34 popne {r4, pc}
 *   @0x135e38 str r3, [r0, #0xc]
 *   @0x135e3c bl 0x21857c <_Z21Audio_GetListenerMaskv>
 *   @0x135e40 vmov s15, r0
 *   @0x135e44 vcvt.f64.u32 d7, s15
 *   @0x135e48 vmov r0, r1, d7
 *   @0x135e4c vmov r2, s14
 *   @0x135e50 mov r3, r1
 *   @0x135e54 stm r4, {r2, r3}
 *   @0x135e58 pop {r4, pc}
 *   @0x135e5c eoreq r9, r11, r8, lsr #4
 *
 * ══ §212/438 F_AudioGetListenerCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x135ed8  size 68  17 条（0x135ed8..0x135f1c）
 * @func 0x135ed8 0x135f1c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetListenerCount()
 * 字段偏移 top8: 0x38×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135ed8 ldr r3, [pc, #0x38]
 *   @0x135edc push {r4, lr}
 *   @0x135ee0 ldr r3, [pc, r3]
 *   @0x135ee4 mov r4, r0
 *   @0x135ee8 ldrb r3, [r3]
 *   @0x135eec cmp r3, #0
 *   @0x135ef0 popne {r4, pc}
 *   @0x135ef4 str r3, [r0, #0xc]
 *   @0x135ef8 bl 0x218638 <_Z22Audio_GetListenerCountv>
 *   @0x135efc vmov s15, r0
 *   @0x135f00 vcvt.f64.s32 d7, s15
 *   @0x135f04 vmov r0, r1, d7
 *   @0x135f08 vmov r2, s14
 *   @0x135f0c mov r3, r1
 *   @0x135f10 stm r4, {r2, r3}
 *   @0x135f14 pop {r4, pc}
 *   @0x135f18 eoreq r9, r11, r12, ror #2
 *
 * ══ §213/438 F_FileWriteLn(RValue&, CInstance*, CInstance*, int, RValue*)  0x139d94  size 68  17 条（0x139d94..0x139dd8）
 * @func 0x139d94 0x139dd8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139d94 ldr r3, [pc, #0x30]
 *   @0x139d98 ldr r3, [pc, r3]
 *   @0x139d9c ldr r3, [r3]
 *   @0x139da0 cmp r3, #2
 *   @0x139da4 beq 0x139db8 <_Z13F_FileWriteLnR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x139da8 ldr r0, [pc, #0x20]
 *   @0x139dac mov r1, #0
 *   @0x139db0 add r0, pc, r0
 *   @0x139db4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139db8 ldr r3, [pc, #0x14]
 *   @0x139dbc mov r0, #10
 *   @0x139dc0 ldr r3, [pc, r3]
 *   @0x139dc4 ldr r1, [r3, #0x8]
 *   @0x139dc8 b 0xb68b0 <fputc@plt>
 *   @0x139dcc .word 0x002b54d8
 *   @0x139dd0 .word 0x002062dc
 *   @0x139dd4 .word 0x002b54b4
 *
 * ══ §214/438 InitBinFiles()  0x13b830  size 68  17 条（0x13b830..0x13b874）
 * @func 0x13b830 0x13b874  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x30×1 / 0x-14×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13b830 ldr r0, [pc, #0x34]
 *   @0x13b834 mov r2, #0
 *   @0x13b838 ldr r1, [pc, #0x30]
 *   @0x13b83c ldr r0, [pc, r0]
 *   @0x13b840 ldr r1, [pc, r1]
 *   @0x13b844 add r3, r0, #8
 *   @0x13b848 sub r1, r1, #1
 *   @0x13b84c add r0, r0, #392
 *   @0x13b850 str r2, [r3]
 *   @0x13b854 add r3, r3, #12
 *   @0x13b858 str r2, [r3, #-0x14]
 *   @0x13b85c cmp r3, r0
 *   @0x13b860 strb r2, [r1, #0x1]!
 *   @0x13b864 bne 0x13b850 <_Z12InitBinFilesv+0x20>
 *   @0x13b868 bx lr
 *   @0x13b86c eoreq r3, r11, r4, asr r10
 *   @0x13b870 eoreq r3, r11, r12, asr #20
 *
 * ══ §215/438 InitTextFiles()  0x13b874  size 68  17 条（0x13b874..0x13b8b8）
 * @func 0x13b874 0x13b8b8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x30×1 / 0x-14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13b874 ldr r0, [pc, #0x34]
 *   @0x13b878 mov r2, #0
 *   @0x13b87c ldr r1, [pc, #0x30]
 *   @0x13b880 ldr r0, [pc, r0]
 *   @0x13b884 ldr r1, [pc, r1]
 *   @0x13b888 add r3, r0, #8
 *   @0x13b88c sub r1, r1, #4
 *   @0x13b890 add r0, r0, #392
 *   @0x13b894 str r2, [r3]
 *   @0x13b898 add r3, r3, #12
 *   @0x13b89c str r2, [r3, #-0x14]
 *   @0x13b8a0 cmp r3, r0
 *   @0x13b8a4 str r2, [r1, #0x4]!
 *   @0x13b8a8 bne 0x13b894 <_Z13InitTextFilesv+0x20>
 *   @0x13b8ac bx lr
 *   @0x13b8b0 .word 0x002b39f4
 *   @0x13b8b4 eoreq r3, r11, r12, ror #19
 *
 * ══ §216/438 F_PhysicsApplyTorque(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bf60  size 68  17 条（0x14bf60..0x14bfa4）
 * @func 0x14bf60 0x14bfa4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x84×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bf60 push {r4, lr}
 *   @0x14bf64 ldr r4, [r1, #0x84]
 *   @0x14bf68 ldr r0, [sp, #0x8]
 *   @0x14bf6c cmp r4, #0
 *   @0x14bf70 beq 0x14bf8c <_Z20F_PhysicsApplyTorqueR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x14bf74 mov r1, #0
 *   @0x14bf78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14bf7c mov r1, r0
 *   @0x14bf80 mov r0, r4
 *   @0x14bf84 pop {r4, lr}
 *   @0x14bf88 b 0x237260 <_ZN14CPhysicsObject11ApplyTorqueEf>
 *   @0x14bf8c ldr r0, [pc, #0xc]
 *   @0x14bf90 mov r1, r4
 *   @0x14bf94 pop {r4, lr}
 *   @0x14bf98 add r0, pc, r0
 *   @0x14bf9c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bfa0 andseq r7, pc, r12, asr #28
 *
 * ══ §217/438 F_YoYo_CheckPermission(RValue&, CInstance*, CInstance*, int, RValue*)  0x157674  size 68  17 条（0x157674..0x1576b8）
 * @func 0x157674 0x1576b8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYCheckPermission(char const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157674 push {r4, lr}
 *   @0x157678 mov r3, #0
 *   @0x15767c mov r1, r3
 *   @0x157680 str r3, [r0, #0xc]
 *   @0x157684 str r3, [r0]
 *   @0x157688 mov r4, r0
 *   @0x15768c str r3, [r0, #0x4]
 *   @0x157690 ldr r0, [sp, #0x8]
 *   @0x157694 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157698 bl 0x15f2dc <_Z17YYCheckPermissionPKc>
 *   @0x15769c vmov s15, r0
 *   @0x1576a0 vcvt.f64.s32 d7, s15
 *   @0x1576a4 vmov r0, r1, d7
 *   @0x1576a8 vmov r2, s14
 *   @0x1576ac mov r3, r1
 *   @0x1576b0 stm r4, {r2, r3}
 *   @0x1576b4 pop {r4, pc}
 *
 * ══ §218/438 GR_3D_Transform_Stack_Top()  0x163bd0  size 68  17 条（0x163bd0..0x163c14）
 * @func 0x163bd0 0x163c14  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Transform_Stack_Top()+0x34 / Graphics::SetMatrix(eMatrix, float*)
 * 字段偏移 top8: 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163bd0 push {r3, lr}
 *   @0x163bd4 ldr r3, [pc, #0x30]
 *   @0x163bd8 ldr r3, [pc, r3]
 *   @0x163bdc ldr r3, [r3]
 *   @0x163be0 cmp r3, #0
 *   @0x163be4 blt 0x163c04 <_Z25GR_3D_Transform_Stack_Topv+0x34>
 *   @0x163be8 ldr r1, [pc, #0x20]
 *   @0x163bec mov r0, #2
 *   @0x163bf0 ldr r1, [pc, r1]
 *   @0x163bf4 add r1, r1, r3, lsl #6
 *   @0x163bf8 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163bfc mov r0, #1
 *   @0x163c00 pop {r3, pc}
 *   @0x163c04 mov r0, #0
 *   @0x163c08 pop {r3, pc}
 *   @0x163c0c eoreq r12, r8, r12, lsl #10
 *   @0x163c10 .word 0x0028c4f8
 *
 * ══ §219/438 GR_D3D_Set_Blend(int)  0x168360  size 68  17 条（0x168360..0x1683a4）
 * @func 0x168360 0x1683a4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168360 cmp r0, #2
 *   @0x168364 beq 0x168398 <_Z16GR_D3D_Set_Blendi+0x38>
 *   @0x168368 cmp r0, #3
 *   @0x16836c beq 0x16838c <_Z16GR_D3D_Set_Blendi+0x2c>
 *   @0x168370 cmp r0, #1
 *   @0x168374 mov r0, #5
 *   @0x168378 beq 0x168384 <_Z16GR_D3D_Set_Blendi+0x24>
 *   @0x16837c mov r1, #6
 *   @0x168380 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii>
 *   @0x168384 mov r1, #2
 *   @0x168388 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii>
 *   @0x16838c mov r0, #1
 *   @0x168390 mov r1, #4
 *   @0x168394 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii>
 *   @0x168398 mov r0, #5
 *   @0x16839c mov r1, #4
 *   @0x1683a0 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii>
 *
 * ══ §220/438 GR_D3D_Set_Colour_Write_Enable(bool, bool, bool, bool)  0x1683a4  size 68  17 条（0x1683a4..0x1683e8）
 * @func 0x1683a4 0x1683e8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1683a4 cmp r1, #0
 *   @0x1683a8 ldr r12, [pc, #0x34]
 *   @0x1683ac movne r1, #2
 *   @0x1683b0 moveq r1, #0
 *   @0x1683b4 cmp r2, #0
 *   @0x1683b8 orr r0, r1, r0
 *   @0x1683bc mov r1, #24
 *   @0x1683c0 movne r2, #4
 *   @0x1683c4 moveq r2, #0
 *   @0x1683c8 cmp r3, #0
 *   @0x1683cc orr r2, r0, r2
 *   @0x1683d0 ldr r0, [pc, r12]
 *   @0x1683d4 movne r3, #8
 *   @0x1683d8 moveq r3, #0
 *   @0x1683dc orr r2, r2, r3
 *   @0x1683e0 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1683e4 eoreq r5, r8, r8, lsr #18
 *
 * ══ §221/438 GR_Window_View_Mouse_Get_X(int)  0x17aa2c  size 68  17 条（0x17aa2c..0x17aa70）
 * @func 0x17aa2c 0x17aa70  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_View_Convert(int, int, int, int&, int&)
 * 字段偏移 top8: 0x34×2 / 0x-4×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17aa2c ldr r1, [pc, #0x34]
 *   @0x17aa30 ldr r2, [pc, #0x34]
 *   @0x17aa34 str lr, [sp, #-0x4]!
 *   @0x17aa38 ldr r1, [pc, r1]
 *   @0x17aa3c sub sp, sp, #20
 *   @0x17aa40 ldr r2, [pc, r2]
 *   @0x17aa44 ldr r1, [r1]
 *   @0x17aa48 add r12, sp, #12
 *   @0x17aa4c ldr r2, [r2]
 *   @0x17aa50 add r3, sp, #8
 *   @0x17aa54 str r12, [sp]
 *   @0x17aa58 bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_>
 *   @0x17aa5c ldr r0, [sp, #0x8]
 *   @0x17aa60 add sp, sp, #20
 *   @0x17aa64 ldr pc, [sp], #4
 *   @0x17aa68 eoreq r5, r7, r4, ror #2
 *   @0x17aa6c eoreq r5, r7, r8, asr r1
 *
 * ══ §222/438 GR_Window_View_Mouse_Get_Y(int)  0x17aa70  size 68  17 条（0x17aa70..0x17aab4）
 * @func 0x17aa70 0x17aab4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_View_Convert(int, int, int, int&, int&)
 * 字段偏移 top8: 0x34×2 / 0x-4×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17aa70 ldr r1, [pc, #0x34]
 *   @0x17aa74 ldr r2, [pc, #0x34]
 *   @0x17aa78 str lr, [sp, #-0x4]!
 *   @0x17aa7c ldr r1, [pc, r1]
 *   @0x17aa80 sub sp, sp, #20
 *   @0x17aa84 ldr r2, [pc, r2]
 *   @0x17aa88 ldr r1, [r1]
 *   @0x17aa8c add r12, sp, #12
 *   @0x17aa90 ldr r2, [r2]
 *   @0x17aa94 add r3, sp, #8
 *   @0x17aa98 str r12, [sp]
 *   @0x17aa9c bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_>
 *   @0x17aaa0 ldr r0, [sp, #0xc]
 *   @0x17aaa4 add sp, sp, #20
 *   @0x17aaa8 ldr pc, [sp], #4
 *   @0x17aaac eoreq r5, r7, r0, lsr #2
 *   @0x17aab0 eoreq r5, r7, r4, lsl r1
 *
 * ══ §223/438 GraphicsRecorder::~GraphicsRecorder()  0x188ca4  size 68  17 条（0x188ca4..0x188ce8）
 * @func 0x188ca4 0x188ce8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / GraphicsRecorder::DeleteHWBuffers()
 * 字段偏移 top8: 0x14×1 / 0x24×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188ca4 push {r4, lr}
 *   @0x188ca8 mov r4, r0
 *   @0x188cac bl 0x1857d8 <_ZN16GraphicsRecorder15DeleteHWBuffersEv>
 *   @0x188cb0 ldr r0, [r4, #0x14]
 *   @0x188cb4 cmp r0, #0
 *   @0x188cb8 beq 0x188cc0 <_ZN16GraphicsRecorderD2Ev+0x1c>
 *   @0x188cbc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x188cc0 ldr r0, [r4, #0x24]
 *   @0x188cc4 cmp r0, #0
 *   @0x188cc8 beq 0x188cd0 <_ZN16GraphicsRecorderD2Ev+0x2c>
 *   @0x188ccc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x188cd0 ldr r0, [r4, #0x34]
 *   @0x188cd4 cmp r0, #0
 *   @0x188cd8 beq 0x188ce0 <_ZN16GraphicsRecorderD2Ev+0x3c>
 *   @0x188cdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x188ce0 mov r0, r4
 *   @0x188ce4 pop {r4, pc}
 *
 * ══ §224/438 anon_18a61c  0x18a61c  size 68  17 条（0x18a61c..0x18a660）
 * @func 0x18a61c 0x18a660  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a61c bx lr
 *   @0x18a620 mov r0, #1
 *   @0x18a624 bx lr
 *   @0x18a628 ldr r2, [r0, #0x18]
 *   @0x18a62c cmp r1, #0
 *   @0x18a630 ldr r3, [r2, #0x4]
 *   @0x18a634 bgt 0x18a640 <_Z17ReadPNGFileHeaderPviPiS0_b+0xf4>
 *   @0x18a638 b 0x18a648 <_Z17ReadPNGFileHeaderPviPiS0_b+0xfc>
 *   @0x18a63c rsb r1, r3, r1
 *   @0x18a640 cmp r1, r3
 *   @0x18a644 bgt 0x18a63c <_Z17ReadPNGFileHeaderPviPiS0_b+0xf0>
 *   @0x18a648 ldr r0, [r2]
 *   @0x18a64c rsb r3, r1, r3
 *   @0x18a650 str r3, [r2, #0x4]
 *   @0x18a654 add r1, r0, r1
 *   @0x18a658 str r1, [r2]
 *   @0x18a65c bx lr
 *
 * ══ §225/438 FreeVirtualKey(int)  0x18c608  size 68  17 条（0x18c608..0x18c64c）
 * @func 0x18c608 0x18c64c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c608 cmp r0, #0
 *   @0x18c60c bxlt lr
 *   @0x18c610 ldr r3, [pc, #0x2c]
 *   @0x18c614 ldr r3, [pc, r3]
 *   @0x18c618 ldr r3, [r3]
 *   @0x18c61c cmp r0, r3
 *   @0x18c620 bxge lr
 *   @0x18c624 mov r2, #44
 *   @0x18c628 ldr r3, [pc, #0x18]
 *   @0x18c62c mul r0, r2, r0
 *   @0x18c630 ldr r3, [pc, r3]
 *   @0x18c634 mov r2, #0
 *   @0x18c638 ldr r3, [r3]
 *   @0x18c63c strh r2, [r3, r0]
 *   @0x18c640 bx lr
 *   @0x18c644 eoreq r3, r6, r12, lsr r5
 *   @0x18c648 eoreq r3, r6, r4, lsr #10
 *
 * ══ §226/438 ParticleType_Destroy(int)  0x1a3160  size 68  17 条（0x1a3160..0x1a31a4）
 * @func 0x1a3160 0x1a31a4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int) / ParticleType_Clear(int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3160 push {r3, r4, r5, lr}
 *   @0x1a3164 mov r4, r0
 *   @0x1a3168 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a316c cmp r0, #0
 *   @0x1a3170 popeq {r3, r4, r5, pc}
 *   @0x1a3174 ldr r5, [pc, #0x24]
 *   @0x1a3178 mov r0, r4
 *   @0x1a317c bl 0x1a2f7c <_Z18ParticleType_Cleari>
 *   @0x1a3180 ldr r5, [pc, r5]
 *   @0x1a3184 ldr r3, [r5, #0x4]
 *   @0x1a3188 ldr r0, [r3, r4, lsl #2]
 *   @0x1a318c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a3190 ldr r3, [r5, #0x4]
 *   @0x1a3194 mov r2, #0
 *   @0x1a3198 str r2, [r3, r4, lsl #2]
 *   @0x1a319c pop {r3, r4, r5, pc}
 *   @0x1a31a0 eoreq sp, r4, r12, lsr #12
 *
 * ══ §227/438 ParticleType_Color_Mix(int, unsigned int, unsigned int)  0x1a34f4  size 68  17 条（0x1a34f4..0x1a3538）
 * @func 0x1a34f4 0x1a3538  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x1c×1 / 0x4×1 / 0x2×1 / 0x7c×1 / 0x80×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a34f4 push {r4, r5, r6, lr}
 *   @0x1a34f8 mov r6, r1
 *   @0x1a34fc mov r5, r2
 *   @0x1a3500 mov r4, r0
 *   @0x1a3504 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3508 cmp r0, #0
 *   @0x1a350c popeq {r4, r5, r6, pc}
 *   @0x1a3510 ldr r3, [pc, #0x1c]
 *   @0x1a3514 mov r2, #5
 *   @0x1a3518 ldr r3, [pc, r3]
 *   @0x1a351c ldr r3, [r3, #0x4]
 *   @0x1a3520 ldr r3, [r3, r4, lsl #2]
 *   @0x1a3524 str r6, [r3, #0x7c]
 *   @0x1a3528 str r5, [r3, #0x80]
 *   @0x1a352c str r2, [r3, #0x78]
 *   @0x1a3530 pop {r4, r5, r6, pc}
 *   @0x1a3534 mlaeq r4, r4, r2, sp
 *
 * ══ §228/438 ParticleType_Color2(int, unsigned int, unsigned int)  0x1a35d8  size 68  17 条（0x1a35d8..0x1a361c）
 * @func 0x1a35d8 0x1a361c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x1c×1 / 0x4×1 / 0x2×1 / 0x7c×1 / 0x80×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a35d8 push {r4, r5, r6, lr}
 *   @0x1a35dc mov r6, r1
 *   @0x1a35e0 mov r5, r2
 *   @0x1a35e4 mov r4, r0
 *   @0x1a35e8 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a35ec cmp r0, #0
 *   @0x1a35f0 popeq {r4, r5, r6, pc}
 *   @0x1a35f4 ldr r3, [pc, #0x1c]
 *   @0x1a35f8 mov r2, #1
 *   @0x1a35fc ldr r3, [pc, r3]
 *   @0x1a3600 ldr r3, [r3, #0x4]
 *   @0x1a3604 ldr r3, [r3, r4, lsl #2]
 *   @0x1a3608 str r6, [r3, #0x7c]
 *   @0x1a360c str r5, [r3, #0x80]
 *   @0x1a3610 str r2, [r3, #0x78]
 *   @0x1a3614 pop {r4, r5, r6, pc}
 *   @0x1a3618 .word 0x0024d1b0
 *
 * ══ §229/438 ParticleType_Alpha3(int, float, float, float)  0x1a36f8  size 68  17 条（0x1a36f8..0x1a373c）
 * @func 0x1a36f8 0x1a373c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x2×1 / 0x94×1 / 0x98×1 / 0x9c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a36f8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a36fc mov r7, r1
 *   @0x1a3700 mov r4, r0
 *   @0x1a3704 mov r6, r2
 *   @0x1a3708 mov r5, r3
 *   @0x1a370c bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3710 cmp r0, #0
 *   @0x1a3714 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a3718 ldr r12, [pc, #0x18]
 *   @0x1a371c ldr r12, [pc, r12]
 *   @0x1a3720 ldr r3, [r12, #0x4]
 *   @0x1a3724 ldr r0, [r3, r4, lsl #2]
 *   @0x1a3728 str r7, [r0, #0x94]
 *   @0x1a372c str r6, [r0, #0x98]
 *   @0x1a3730 str r5, [r0, #0x9c]
 *   @0x1a3734 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a3738 mlaeq r4, r0, r0, sp
 *
 * ══ §230/438 CPath::GetPoint(int)  0x1a5f34  size 68  17 条（0x1a5f34..0x1a5f78）
 * @func 0x1a5f34 0x1a5f78  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::GetPoint(int)+0x30
 * 字段偏移 top8: 0x10×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5f34 cmp r1, #0
 *   @0x1a5f38 blt 0x1a5f64 <_ZN5CPath8GetPointEi+0x30>
 *   @0x1a5f3c ldr r3, [r0, #0x10]
 *   @0x1a5f40 cmp r1, r3
 *   @0x1a5f44 bge 0x1a5f58 <_ZN5CPath8GetPointEi+0x24>
 *   @0x1a5f48 add r1, r1, r1, lsl #1
 *   @0x1a5f4c ldr r3, [r0, #0x4]
 *   @0x1a5f50 add r0, r3, r1, lsl #2
 *   @0x1a5f54 bx lr
 *   @0x1a5f58 ldr r0, [pc, #0x10]
 *   @0x1a5f5c ldr r0, [pc, r0]
 *   @0x1a5f60 bx lr
 *   @0x1a5f64 ldr r0, [pc, #0x8]
 *   @0x1a5f68 ldr r0, [pc, r0]
 *   @0x1a5f6c bx lr
 *   @0x1a5f70 eoreq r10, r4, r12, ror #16
 *   @0x1a5f74 eoreq r10, r4, r0, ror #16
 *
 * ══ §231/438 CPath::ChangePoint(int, float, float, float)  0x1a72f8  size 68  17 条（0x1a72f8..0x1a733c）
 * @func 0x1a72f8 0x1a733c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::ChangePoint(int, float, float, float)+0x1c / CPath::ChangePoint(int, float, float, float)+0x24
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a72f8 cmp r1, #0
 *   @0x1a72fc push {r4, r5}
 *   @0x1a7300 ldr r5, [sp, #0x8]
 *   @0x1a7304 blt 0x1a7314 <_ZN5CPath11ChangePointEifff+0x1c>
 *   @0x1a7308 ldr r4, [r0, #0x10]
 *   @0x1a730c cmp r1, r4
 *   @0x1a7310 blt 0x1a731c <_ZN5CPath11ChangePointEifff+0x24>
 *   @0x1a7314 pop {r4, r5}
 *   @0x1a7318 bx lr
 *   @0x1a731c ldr r12, [r0, #0x4]
 *   @0x1a7320 add r1, r1, r1, lsl #1
 *   @0x1a7324 add r1, r12, r1, lsl #2
 *   @0x1a7328 str r5, [r1, #0x8]
 *   @0x1a732c str r2, [r1]
 *   @0x1a7330 str r3, [r1, #0x4]
 *   @0x1a7334 pop {r4, r5}
 *   @0x1a7338 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *
 * ══ §232/438 CLayerManager::GetElementFromID(CLayer*, int)  0x1c07e4  size 68  17 条（0x1c07e4..0x1c0828）
 * @func 0x1c07e4 0x1c0828  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x58×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c07e4 cmp r0, #0
 *   @0x1c07e8 bxeq lr
 *   @0x1c07ec ldr r0, [r0, #0x58]
 *   @0x1c07f0 cmp r0, #0
 *   @0x1c07f4 bxeq lr
 *   @0x1c07f8 ldr r3, [r0, #0x4]
 *   @0x1c07fc cmp r3, r1
 *   @0x1c0800 beq 0x1c0824 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri+0x40>
 *   @0x1c0804 ldr r0, [r0, #0x14]
 *   @0x1c0808 cmp r0, #0
 *   @0x1c080c beq 0x1c0820 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri+0x3c>
 *   @0x1c0810 ldr r3, [r0, #0x4]
 *   @0x1c0814 cmp r3, r1
 *   @0x1c0818 bne 0x1c0804 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri+0x20>
 *   @0x1c081c bx lr
 *   @0x1c0820 bx lr
 *   @0x1c0824 bx lr
 *
 * ══ §233/438 F_GestureDragTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5560  size 68  17 条（0x1d5560..0x1d55a4）
 * @func 0x1d5560 0x1d55a4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi
 * 字段偏移 top8: 0x8×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5560 push {r4, lr}
 *   @0x1d5564 mov r1, #0
 *   @0x1d5568 ldr r0, [sp, #0x8]
 *   @0x1d556c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1d5570 vldr d7, [pc, #32]
 *   @0x1d5574 ldr r4, [pc, #0x24]
 *   @0x1d5578 ldr r4, [pc, r4]
 *   @0x1d557c vmov d6, r0, r1
 *   @0x1d5580 vmul.f64 d6, d6, d7
 *   @0x1d5584 vmov r0, r1, d6
 *   @0x1d5588 bl 0x3194a0 <__fixdfdi>
 *   @0x1d558c strd r0, r1, [r4]
 *   @0x1d5590 pop {r4, pc}
 *   @0x1d5594 nop
 *   @0x1d5598 andeq r0, r0, r0
 *   @0x1d559c smlawbmi lr, r0, r4, r8
 *   @0x1d55a0 eoreq r11, r1, r12, asr #12
 *
 * ══ §234/438 F_GestureDoubleTapTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d55a8  size 68  17 条（0x1d55a8..0x1d55ec）
 * @func 0x1d55a8 0x1d55ec  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi
 * 字段偏移 top8: 0x8×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d55a8 push {r4, lr}
 *   @0x1d55ac mov r1, #0
 *   @0x1d55b0 ldr r0, [sp, #0x8]
 *   @0x1d55b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1d55b8 vldr d7, [pc, #32]
 *   @0x1d55bc ldr r4, [pc, #0x24]
 *   @0x1d55c0 ldr r4, [pc, r4]
 *   @0x1d55c4 vmov d6, r0, r1
 *   @0x1d55c8 vmul.f64 d6, d6, d7
 *   @0x1d55cc vmov r0, r1, d6
 *   @0x1d55d0 bl 0x3194a0 <__fixdfdi>
 *   @0x1d55d4 strd r0, r1, [r4]
 *   @0x1d55d8 pop {r4, pc}
 *   @0x1d55dc nop
 *   @0x1d55e0 andeq r0, r0, r0
 *   @0x1d55e4 ldrdmi r1, r2, [r3, #-32]!
 *   @0x1d55e8 eoreq r11, r1, r0, lsl r6
 *
 * ══ §235/438 F_GestureRotateTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d55f0  size 68  17 条（0x1d55f0..0x1d5634）
 * @func 0x1d55f0 0x1d5634  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi
 * 字段偏移 top8: 0x8×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d55f0 push {r4, lr}
 *   @0x1d55f4 mov r1, #0
 *   @0x1d55f8 ldr r0, [sp, #0x8]
 *   @0x1d55fc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1d5600 vldr d7, [pc, #32]
 *   @0x1d5604 ldr r4, [pc, #0x24]
 *   @0x1d5608 ldr r4, [pc, r4]
 *   @0x1d560c vmov d6, r0, r1
 *   @0x1d5610 vmul.f64 d6, d6, d7
 *   @0x1d5614 vmov r0, r1, d6
 *   @0x1d5618 bl 0x3194a0 <__fixdfdi>
 *   @0x1d561c strd r0, r1, [r4]
 *   @0x1d5620 pop {r4, pc}
 *   @0x1d5624 nop
 *   @0x1d5628 andeq r0, r0, r0
 *   @0x1d562c smlawbmi lr, r0, r4, r8
 *   @0x1d5630 .word 0x0021b5dc
 *
 * ══ §236/438 fwrap(float, float)  0x1e62fc  size 68  17 条（0x1e62fc..0x1e6340）
 * @func 0x1e62fc 0x1e6340  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: fwrap(float, float)+0x38 / 0xb6910
 * 字段偏移 top8: 无
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e62fc push {r3, lr}
 *   @0x1e6300 vpush {d8}
 *   @0x1e6304 vmov s16, r1
 *   @0x1e6308 vmov s17, r0
 *   @0x1e630c vcmpe.f32 s16, #0
 *   @0x1e6310 vmrs APSR_nzcv, fpscr
 *   @0x1e6314 vmovls.f32 s16, s17
 *   @0x1e6318 bls 0x1e6334 <_Z5fwrapff+0x38>
 *   @0x1e631c vdiv.f32 s17, s17, s16
 *   @0x1e6320 vmov r0, s17
 *   @0x1e6324 bl 0xb6910 <floorf@plt>
 *   @0x1e6328 vmov s15, r0
 *   @0x1e632c vsub.f32 s17, s17, s15
 *   @0x1e6330 vmul.f32 s16, s17, s16
 *   @0x1e6334 vmov r0, s16
 *   @0x1e6338 vpop {d8}
 *   @0x1e633c pop {r3, pc}
 *
 * ══ §237/438 CVariableList::Find(int)  0x1f531c  size 68  17 条（0x1f531c..0x1f5360）
 * @func 0x1f531c 0x1f5360  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f531c and r3, r1, #3
 *   @0x1f5320 add r0, r0, r3, lsl #2
 *   @0x1f5324 ldr r0, [r0, #0x4]
 *   @0x1f5328 cmp r0, #0
 *   @0x1f532c bxeq lr
 *   @0x1f5330 ldr r3, [r0, #0x8]
 *   @0x1f5334 cmp r3, r1
 *   @0x1f5338 bne 0x1f534c <_ZN13CVariableList4FindEi+0x30>
 *   @0x1f533c b 0x1f535c <_ZN13CVariableList4FindEi+0x40>
 *   @0x1f5340 ldr r3, [r0, #0x8]
 *   @0x1f5344 cmp r3, r1
 *   @0x1f5348 bxeq lr
 *   @0x1f534c ldr r0, [r0]
 *   @0x1f5350 cmp r0, #0
 *   @0x1f5354 bne 0x1f5340 <_ZN13CVariableList4FindEi+0x24>
 *   @0x1f5358 bx lr
 *   @0x1f535c bx lr
 *
 * ══ §238/438 GV_InstanceCount(CInstance*, int, RValue*)  0x1f7b70  size 68  17 条（0x1f7b70..0x1f7bb4）
 * @func 0x1f7b70 0x1f7bb4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x88×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7b70 ldr r3, [pc, #0x38]
 *   @0x1f7b74 mov r1, #0
 *   @0x1f7b78 push {r4, r5}
 *   @0x1f7b7c ldr r3, [pc, r3]
 *   @0x1f7b80 str r1, [r2, #0xc]
 *   @0x1f7b84 mov r0, #1
 *   @0x1f7b88 ldr r3, [r3]
 *   @0x1f7b8c ldr r4, [r3, #0x88]
 *   @0x1f7b90 vmov s15, r4
 *   @0x1f7b94 vcvt.f64.s32 d7, s15
 *   @0x1f7b98 vmov r4, r5, d7
 *   @0x1f7b9c vmov r1, s14
 *   @0x1f7ba0 mov r3, r5
 *   @0x1f7ba4 pop {r4, r5}
 *   @0x1f7ba8 stm r2, {r1, r3}
 *   @0x1f7bac bx lr
 *   @0x1f7bb0 andseq r5, pc, r12, lsr #27
 *
 * ══ §239/438 GV_RoomWidth(CInstance*, int, RValue*)  0x1f7bb4  size 68  17 条（0x1f7bb4..0x1f7bf8）
 * @func 0x1f7bb4 0x1f7bf8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7bb4 ldr r3, [pc, #0x38]
 *   @0x1f7bb8 mov r1, #0
 *   @0x1f7bbc push {r4, r5}
 *   @0x1f7bc0 ldr r3, [pc, r3]
 *   @0x1f7bc4 str r1, [r2, #0xc]
 *   @0x1f7bc8 mov r0, #1
 *   @0x1f7bcc ldr r3, [r3]
 *   @0x1f7bd0 ldr r4, [r3, #0x10]
 *   @0x1f7bd4 vmov s15, r4
 *   @0x1f7bd8 vcvt.f64.s32 d7, s15
 *   @0x1f7bdc vmov r4, r5, d7
 *   @0x1f7be0 vmov r1, s14
 *   @0x1f7be4 mov r3, r5
 *   @0x1f7be8 pop {r4, r5}
 *   @0x1f7bec stm r2, {r1, r3}
 *   @0x1f7bf0 bx lr
 *   @0x1f7bf4 andseq r5, pc, r8, ror #26
 *
 * ══ §240/438 GV_RoomHeight(CInstance*, int, RValue*)  0x1f7bf8  size 68  17 条（0x1f7bf8..0x1f7c3c）
 * @func 0x1f7bf8 0x1f7c3c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7bf8 ldr r3, [pc, #0x38]
 *   @0x1f7bfc mov r1, #0
 *   @0x1f7c00 push {r4, r5}
 *   @0x1f7c04 ldr r3, [pc, r3]
 *   @0x1f7c08 str r1, [r2, #0xc]
 *   @0x1f7c0c mov r0, #1
 *   @0x1f7c10 ldr r3, [r3]
 *   @0x1f7c14 ldr r4, [r3, #0x14]
 *   @0x1f7c18 vmov s15, r4
 *   @0x1f7c1c vcvt.f64.s32 d7, s15
 *   @0x1f7c20 vmov r4, r5, d7
 *   @0x1f7c24 vmov r1, s14
 *   @0x1f7c28 mov r3, r5
 *   @0x1f7c2c pop {r4, r5}
 *   @0x1f7c30 stm r2, {r1, r3}
 *   @0x1f7c34 bx lr
 *   @0x1f7c38 andseq r5, pc, r4, lsr #26
 *
 * ══ §241/438 GV_RoomPersistent(CInstance*, int, RValue*)  0x1f7c3c  size 68  17 条（0x1f7c3c..0x1f7c80）
 * @func 0x1f7c3c 0x1f7c80  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x18×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7c3c ldr r3, [pc, #0x38]
 *   @0x1f7c40 mov r1, #0
 *   @0x1f7c44 push {r4, r5}
 *   @0x1f7c48 ldr r3, [pc, r3]
 *   @0x1f7c4c str r1, [r2, #0xc]
 *   @0x1f7c50 mov r0, #1
 *   @0x1f7c54 ldr r3, [r3]
 *   @0x1f7c58 ldrb r4, [r3, #0x18]
 *   @0x1f7c5c vmov s15, r4
 *   @0x1f7c60 vcvt.f64.u32 d7, s15
 *   @0x1f7c64 vmov r4, r5, d7
 *   @0x1f7c68 vmov r1, s14
 *   @0x1f7c6c mov r3, r5
 *   @0x1f7c70 pop {r4, r5}
 *   @0x1f7c74 stm r2, {r1, r3}
 *   @0x1f7c78 bx lr
 *   @0x1f7c7c andseq r5, pc, r0, ror #25
 *
 * ══ §242/438 GV_BackgroundColor(CInstance*, int, RValue*)  0x1f7c80  size 68  17 条（0x1f7c80..0x1f7cc4）
 * @func 0x1f7c80 0x1f7cc4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x1c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7c80 ldr r3, [pc, #0x38]
 *   @0x1f7c84 mov r1, #0
 *   @0x1f7c88 push {r4, r5}
 *   @0x1f7c8c ldr r3, [pc, r3]
 *   @0x1f7c90 str r1, [r2, #0xc]
 *   @0x1f7c94 mov r0, #1
 *   @0x1f7c98 ldr r3, [r3]
 *   @0x1f7c9c ldr r4, [r3, #0x1c]
 *   @0x1f7ca0 vmov s15, r4
 *   @0x1f7ca4 vcvt.f64.u32 d7, s15
 *   @0x1f7ca8 vmov r4, r5, d7
 *   @0x1f7cac vmov r1, s14
 *   @0x1f7cb0 mov r3, r5
 *   @0x1f7cb4 pop {r4, r5}
 *   @0x1f7cb8 stm r2, {r1, r3}
 *   @0x1f7cbc bx lr
 *   @0x1f7cc0 mulseq pc, r12, r12
 *
 * ══ §243/438 GV_BackgroundShowColor(CInstance*, int, RValue*)  0x1f7cc4  size 68  17 条（0x1f7cc4..0x1f7d08）
 * @func 0x1f7cc4 0x1f7d08  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x20×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7cc4 ldr r3, [pc, #0x38]
 *   @0x1f7cc8 mov r1, #0
 *   @0x1f7ccc push {r4, r5}
 *   @0x1f7cd0 ldr r3, [pc, r3]
 *   @0x1f7cd4 str r1, [r2, #0xc]
 *   @0x1f7cd8 mov r0, #1
 *   @0x1f7cdc ldr r3, [r3]
 *   @0x1f7ce0 ldrb r4, [r3, #0x20]
 *   @0x1f7ce4 vmov s15, r4
 *   @0x1f7ce8 vcvt.f64.u32 d7, s15
 *   @0x1f7cec vmov r4, r5, d7
 *   @0x1f7cf0 vmov r1, s14
 *   @0x1f7cf4 mov r3, r5
 *   @0x1f7cf8 pop {r4, r5}
 *   @0x1f7cfc stm r2, {r1, r3}
 *   @0x1f7d00 bx lr
 *   @0x1f7d04 andseq r5, pc, r8, asr r12
 *
 * ══ §244/438 GV_ViewEnabled(CInstance*, int, RValue*)  0x1f8130  size 68  17 条（0x1f8130..0x1f8174）
 * @func 0x1f8130 0x1f8174  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x44×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8130 ldr r3, [pc, #0x38]
 *   @0x1f8134 mov r1, #0
 *   @0x1f8138 push {r4, r5}
 *   @0x1f813c ldr r3, [pc, r3]
 *   @0x1f8140 str r1, [r2, #0xc]
 *   @0x1f8144 mov r0, #1
 *   @0x1f8148 ldr r3, [r3]
 *   @0x1f814c ldrb r4, [r3, #0x44]
 *   @0x1f8150 vmov s15, r4
 *   @0x1f8154 vcvt.f64.u32 d7, s15
 *   @0x1f8158 vmov r4, r5, d7
 *   @0x1f815c vmov r1, s14
 *   @0x1f8160 mov r3, r5
 *   @0x1f8164 pop {r4, r5}
 *   @0x1f8168 stm r2, {r1, r3}
 *   @0x1f816c bx lr
 *   @0x1f8170 andseq r5, pc, r12, ror #15
 *
 * ══ §245/438 SV_KeyboardLastChar(CInstance*, int, RValue*)  0x1fa7fc  size 68  17 条（0x1fa7fc..0x1fa840）
 * @func 0x1fa7fc 0x1fa840  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Char_Last_Set(char)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa7fc push {r3, lr}
 *   @0x1fa800 ldr r3, [r2, #0xc]
 *   @0x1fa804 bic r3, r3, #-16777216
 *   @0x1fa808 cmp r3, #1
 *   @0x1fa80c beq 0x1fa818 <_Z19SV_KeyboardLastCharP9CInstanceiP6RValue+0x1c>
 *   @0x1fa810 mov r0, #1
 *   @0x1fa814 pop {r3, pc}
 *   @0x1fa818 ldr r3, [r2]
 *   @0x1fa81c cmp r3, #0
 *   @0x1fa820 beq 0x1fa810 <_Z19SV_KeyboardLastCharP9CInstanceiP6RValue+0x14>
 *   @0x1fa824 ldr r3, [r3]
 *   @0x1fa828 cmp r3, #0
 *   @0x1fa82c beq 0x1fa810 <_Z19SV_KeyboardLastCharP9CInstanceiP6RValue+0x14>
 *   @0x1fa830 ldrb r0, [r3]
 *   @0x1fa834 bl 0x18bd20 <_Z16IO_Char_Last_Setc>
 *   @0x1fa838 mov r0, #1
 *   @0x1fa83c pop {r3, pc}
 *
 * ══ §246/438 DestroyDsList(int)  0x205378  size 68  17 条（0x205378..0x2053bc）
 * @func 0x205378 0x2053bc  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsListDestroy(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x24×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x205378 vmov s13, r0
 *   @0x20537c mov r12, #0
 *   @0x205380 str lr, [sp, #-0x4]!
 *   @0x205384 vcvt.f64.s32 d7, s13
 *   @0x205388 sub sp, sp, #44
 *   @0x20538c mov r1, r12
 *   @0x205390 add r3, sp, #24
 *   @0x205394 mov r2, r12
 *   @0x205398 str r3, [sp]
 *   @0x20539c add r0, sp, #8
 *   @0x2053a0 mov r3, #1
 *   @0x2053a4 str r12, [sp, #0x8]
 *   @0x2053a8 str r12, [sp, #0x24]
 *   @0x2053ac vstr d7, [sp, #24]
 *   @0x2053b0 bl 0xfb8e4 <_Z15F_DsListDestroyR6RValueP9CInstanceS2_iPS_>
 *   @0x2053b4 add sp, sp, #44
 *   @0x2053b8 ldr pc, [sp], #4
 *
 * ══ §247/438 SHA1Result(SHA1Context*)  0x2146e4  size 68  17 条（0x2146e4..0x214728）
 * @func 0x2146e4 0x214728  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SHA1PadMessage(SHA1Context*)
 * 字段偏移 top8: 0x60×2 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2146e4 ldr r3, [r0, #0x64]
 *   @0x2146e8 push {r4, lr}
 *   @0x2146ec cmp r3, #0
 *   @0x2146f0 mov r4, r0
 *   @0x2146f4 bne 0x214720 <_Z10SHA1ResultP11SHA1Context+0x3c>
 *   @0x2146f8 ldr r3, [r0, #0x60]
 *   @0x2146fc cmp r3, #0
 *   @0x214700 beq 0x21470c <_Z10SHA1ResultP11SHA1Context+0x28>
 *   @0x214704 mov r0, #1
 *   @0x214708 pop {r4, pc}
 *   @0x21470c bl 0x2145e8 <_Z14SHA1PadMessageP11SHA1Context>
 *   @0x214710 mov r3, #1
 *   @0x214714 mov r0, r3
 *   @0x214718 str r3, [r4, #0x60]
 *   @0x21471c pop {r4, pc}
 *   @0x214720 mov r0, #0
 *   @0x214724 pop {r4, pc}
 *
 * ══ §248/438 CAudioGroupMan::UnloadGroup(int)  0x21e19c  size 68  17 条（0x21e19c..0x21e1e0）
 * @func 0x21e19c 0x21e1e0  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::GetGroup(int) / CAudioGroup::SetLoadState(CAudioGroup::eLoadState) / Audio_StopAllGroup(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e19c push {r4, lr}
 *   @0x21e1a0 subs r4, r1, #0
 *   @0x21e1a4 bne 0x21e1b0 <_ZN14CAudioGroupMan11UnloadGroupEi+0x14>
 *   @0x21e1a8 mov r0, #0
 *   @0x21e1ac pop {r4, pc}
 *   @0x21e1b0 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x21e1b4 subs r3, r0, #0
 *   @0x21e1b8 beq 0x21e1a8 <_ZN14CAudioGroupMan11UnloadGroupEi+0xc>
 *   @0x21e1bc ldr r3, [r3]
 *   @0x21e1c0 cmp r3, #2
 *   @0x21e1c4 bne 0x21e1a8 <_ZN14CAudioGroupMan11UnloadGroupEi+0xc>
 *   @0x21e1c8 mov r1, #3
 *   @0x21e1cc bl 0x21dd48 <_ZN11CAudioGroup12SetLoadStateENS_10eLoadStateE>
 *   @0x21e1d0 mov r0, r4
 *   @0x21e1d4 bl 0x21ad0c <_Z18Audio_StopAllGroupi>
 *   @0x21e1d8 mov r0, #1
 *   @0x21e1dc pop {r4, pc}
 *
 * ══ §249/438 alutLoadMemoryFromFileImage  0x222754  size 68  17 条（0x222754..0x222798）
 * @func 0x222754 0x222798  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / _alutInputStreamConstructFromMemory
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222754 push {r4, r5, r6, r7, r8, lr}
 *   @0x222758 mov r7, r0
 *   @0x22275c mov r8, r1
 *   @0x222760 mov r6, r2
 *   @0x222764 mov r5, r3
 *   @0x222768 ldr r4, [sp, #0x18]
 *   @0x22276c bl 0x2219a8 <_alutSanityCheck>
 *   @0x222770 cmp r0, #0
 *   @0x222774 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x222778 mov r1, r8
 *   @0x22277c mov r0, r7
 *   @0x222780 bl 0x221d94 <_alutInputStreamConstructFromMemory>
 *   @0x222784 mov r1, r6
 *   @0x222788 mov r2, r5
 *   @0x22278c mov r3, r4
 *   @0x222790 pop {r4, r5, r6, r7, r8, lr}
 *   @0x222794 b 0x222664 <_alutLoadMemoryFromInputStream>
 *
 * ══ §250/438 _alutFormatGetNumChannels  0x222b38  size 68  17 条（0x222b38..0x222b7c）
 * @func 0x222b38 0x222b7c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222b38 sub r0, r0, #4352
 *   @0x222b3c cmp r0, #3
 *   @0x222b40 addls pc, pc, r0, lsl #2
 *   @0x222b44 b 0x222b74 <_alutFormatGetNumChannels+0x3c>
 *   @0x222b48 b 0x222b68 <_alutFormatGetNumChannels+0x30>
 *   @0x222b4c b 0x222b68 <_alutFormatGetNumChannels+0x30>
 *   @0x222b50 b 0x222b58 <_alutFormatGetNumChannels+0x20>
 *   @0x222b54 b 0x222b58 <_alutFormatGetNumChannels+0x20>
 *   @0x222b58 mov r3, #2
 *   @0x222b5c mov r0, #1
 *   @0x222b60 str r3, [r1]
 *   @0x222b64 bx lr
 *   @0x222b68 mov r0, #1
 *   @0x222b6c str r0, [r1]
 *   @0x222b70 bx lr
 *   @0x222b74 mov r0, #0
 *   @0x222b78 bx lr
 *
 * ══ §251/438 alutLoadMemoryHelloWorld  0x223028  size 68  17 条（0x223028..0x22306c）
 * @func 0x223028 0x22306c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / _alutInputStreamConstructFromMemory
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223028 push {r4, r5, r6, lr}
 *   @0x22302c mov r6, r0
 *   @0x223030 mov r5, r1
 *   @0x223034 mov r4, r2
 *   @0x223038 bl 0x2219a8 <_alutSanityCheck>
 *   @0x22303c cmp r0, #0
 *   @0x223040 popeq {r4, r5, r6, pc}
 *   @0x223044 ldr r0, [pc, #0x1c]
 *   @0x223048 movw r1, #0x200a
 *   @0x22304c add r0, pc, r0
 *   @0x223050 bl 0x221d94 <_alutInputStreamConstructFromMemory>
 *   @0x223054 mov r1, r6
 *   @0x223058 mov r2, r5
 *   @0x22305c mov r3, r4
 *   @0x223060 pop {r4, r5, r6, lr}
 *   @0x223064 b 0x222664 <_alutLoadMemoryFromInputStream>
 *   @0x223068 andseq r2, sp, r12, lsl #5
 *
 * ══ §252/438 COggThread::PauseResume_Sound(int, bool)  0x223b34  size 68  17 条（0x223b34..0x223b78）
 * @func 0x223b34 0x223b78  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Lock()
 * 字段偏移 top8: 0x2d6×2 / 0x804×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223b34 ldr r3, [r0, #0x804]
 *   @0x223b38 add r1, r1, r1, lsl #1
 *   @0x223b3c push {r4, r5, r6, lr}
 *   @0x223b40 add r5, r3, r1, lsl #8
 *   @0x223b44 mov r4, r0
 *   @0x223b48 mov r6, r2
 *   @0x223b4c bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x223b50 ldrb r3, [r5, #0x2d6]
 *   @0x223b54 tst r3, #1
 *   @0x223b58 beq 0x223b6c <_ZN10COggThread17PauseResume_SoundEib+0x38>
 *   @0x223b5c cmp r6, #0
 *   @0x223b60 orrne r3, r3, #4
 *   @0x223b64 biceq r3, r3, #4
 *   @0x223b68 strb r3, [r5, #0x2d6]
 *   @0x223b6c mov r0, r4
 *   @0x223b70 pop {r4, r5, r6, lr}
 *   @0x223b74 b 0x223aa4 <_ZN10COggThread6UnlockEv>
 *
 * ══ §253/438 COggSyncThread::PauseResume_Sound(int, bool)  0x224f34  size 68  17 条（0x224f34..0x224f78）
 * @func 0x224f34 0x224f78  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x2d6×2 / 0x804×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224f34 ldr r3, [r0, #0x804]
 *   @0x224f38 add r1, r1, r1, lsl #1
 *   @0x224f3c push {r4, r5, r6, lr}
 *   @0x224f40 add r5, r3, r1, lsl #8
 *   @0x224f44 mov r4, r0
 *   @0x224f48 mov r6, r2
 *   @0x224f4c bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x224f50 ldrb r3, [r5, #0x2d6]
 *   @0x224f54 tst r3, #1
 *   @0x224f58 beq 0x224f6c <_ZN14COggSyncThread17PauseResume_SoundEib+0x38>
 *   @0x224f5c cmp r6, #0
 *   @0x224f60 orrne r3, r3, #4
 *   @0x224f64 biceq r3, r3, #4
 *   @0x224f68 strb r3, [r5, #0x2d6]
 *   @0x224f6c mov r0, r4
 *   @0x224f70 pop {r4, r5, r6, lr}
 *   @0x224f74 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *
 * ══ §254/438 COggSyncThread::Quit()  0x2250c8  size 68  17 条（0x2250c8..0x22510c）
 * @func 0x2250c8 0x22510c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock() / COggSyncThread::Unlock() / COggSyncThread::WaitForThreadExit() / COggSyncThread::ShowError()
 * 字段偏移 top8: 0x803×1 / 0x802×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2250c8 ldrb r3, [r0, #0x803]
 *   @0x2250cc push {r4, lr}
 *   @0x2250d0 cmp r3, #0
 *   @0x2250d4 mov r4, r0
 *   @0x2250d8 popeq {r4, pc}
 *   @0x2250dc bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x2250e0 mov r3, #1
 *   @0x2250e4 mov r0, r4
 *   @0x2250e8 strb r3, [r4, #0x802]
 *   @0x2250ec bl 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x2250f0 mov r0, r4
 *   @0x2250f4 bl 0x2248e8 <_ZN14COggSyncThread17WaitForThreadExitEv>
 *   @0x2250f8 mov r0, r4
 *   @0x2250fc bl 0x225078 <_ZN14COggSyncThread9ShowErrorEv>
 *   @0x225100 mov r0, r4
 *   @0x225104 pop {r4, lr}
 *   @0x225108 b 0x224940 <_ZN14COggSyncThread7CleanUpEv>
 *
 * ══ §255/438 CPhysicsObject::ApplyTorque(float)  0x237260  size 68  17 条（0x237260..0x2372a4）
 * @func 0x237260 0x2372a4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xa0×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237260 ldr r3, [r0]
 *   @0x237264 vmov s15, r1
 *   @0x237268 ldr r2, [r3]
 *   @0x23726c cmp r2, #2
 *   @0x237270 bxne lr
 *   @0x237274 ldrh r2, [r3, #4]
 *   @0x237278 tst r2, #2
 *   @0x23727c beq 0x237290 <_ZN14CPhysicsObject11ApplyTorqueEf+0x30>
 *   @0x237280 vldr s14, [r3, #100]
 *   @0x237284 vadd.f32 s15, s14, s15
 *   @0x237288 vstr s15, [r3, #100]
 *   @0x23728c bx lr
 *   @0x237290 orr r2, r2, #2
 *   @0x237294 mov r1, #0
 *   @0x237298 strh r2, [r3, #4]
 *   @0x23729c str r1, [r3, #0xa0]
 *   @0x2372a0 b 0x237280 <_ZN14CPhysicsObject11ApplyTorqueEf+0x20>
 *
 * ══ §256/438 JS_IsGenericDescriptor(RValue*)  0x240858  size 68  17 条（0x240858..0x24089c）
 * @func 0x240858 0x24089c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_IsDataDescriptor(RValue*) / JS_IsAccessorDescriptor(RValue*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240858 ldr r3, [r0, #0xc]
 *   @0x24085c push {r4, lr}
 *   @0x240860 bic r3, r3, #-16777216
 *   @0x240864 cmp r3, #5
 *   @0x240868 mov r4, r0
 *   @0x24086c beq 0x24087c <_Z22JS_IsGenericDescriptorP6RValue+0x24>
 *   @0x240870 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x240874 cmp r0, #0
 *   @0x240878 beq 0x240884 <_Z22JS_IsGenericDescriptorP6RValue+0x2c>
 *   @0x24087c mov r0, #0
 *   @0x240880 pop {r4, pc}
 *   @0x240884 mov r0, r4
 *   @0x240888 bl 0x240828 <_Z23JS_IsAccessorDescriptorP6RValue>
 *   @0x24088c cmp r0, #0
 *   @0x240890 bne 0x24087c <_Z22JS_IsGenericDescriptorP6RValue+0x24>
 *   @0x240894 mov r0, #1
 *   @0x240898 pop {r4, pc}
 *
 * ══ §257/438 pcre_copy_named_substring  0x25f48c  size 68  17 条（0x25f48c..0x25f4d0）
 * @func 0x25f48c 0x25f4d0  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_25f37c
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f48c push {r4, r5, r6, r7, r8, lr}
 *   @0x25f490 mov r7, r1
 *   @0x25f494 ldr r1, [sp, #0x18]
 *   @0x25f498 mov r4, r3
 *   @0x25f49c mov r5, r2
 *   @0x25f4a0 ldr r8, [sp, #0x1c]
 *   @0x25f4a4 ldr r6, [sp, #0x20]
 *   @0x25f4a8 bl 0x25f37c <pcre_get_stringtable_entries+0x160>
 *   @0x25f4ac subs r3, r0, #0
 *   @0x25f4b0 pople {r4, r5, r6, r7, r8, pc}
 *   @0x25f4b4 str r8, [sp, #0x18]
 *   @0x25f4b8 mov r0, r7
 *   @0x25f4bc str r6, [sp, #0x1c]
 *   @0x25f4c0 mov r1, r5
 *   @0x25f4c4 mov r2, r4
 *   @0x25f4c8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x25f4cc b 0x25f424 <pcre_copy_substring>
 *
 * ══ §258/438 MemoryManager::DumpMemory(__sFILE*)  0x27c28c  size 68  17 条（0x27c28c..0x27c2d0）
 * @func 0x27c28c 0x27c2d0  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x28×1 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c28c ldr r2, [pc, #0x30]
 *   @0x27c290 push {r3, lr}
 *   @0x27c294 ldr r2, [pc, r2]
 *   @0x27c298 ldr r3, [pc, #0x28]
 *   @0x27c29c ldr r0, [r2]
 *   @0x27c2a0 ldr r3, [pc, r3]
 *   @0x27c2a4 ldr r1, [pc, #0x20]
 *   @0x27c2a8 ldr r2, [r3]
 *   @0x27c2ac add r1, pc, r1
 *   @0x27c2b0 ldr r12, [r0]
 *   @0x27c2b4 mov r3, r2
 *   @0x27c2b8 ldr r12, [r12, #0xc]
 *   @0x27c2bc blx r12
 *   @0x27c2c0 pop {r3, pc}
 *   @0x27c2c4 andseq r1, r7, r0, lsl #9
 *   @0x27c2c8 andseq r4, r7, r8, lsr r1
 *   @0x27c2cc andeq r10, sp, r12, lsl #30
 *
 * ══ §259/438 mc_debug  0x27e344  size 68  17 条（0x27e344..0x27e388）
 * @func 0x27e344 0x27e388  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6cf4
 * 字段偏移 top8: 0x4×2 / 0x34×1 / 0x-4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e344 push {r0, r1, r2, r3}
 *   @0x27e348 ldr r3, [pc, #0x34]
 *   @0x27e34c str lr, [sp, #-0x4]!
 *   @0x27e350 add r3, pc, r3
 *   @0x27e354 sub sp, sp, #12
 *   @0x27e358 ldr r3, [r3]
 *   @0x27e35c cmp r3, #0
 *   @0x27e360 beq 0x27e374 <mc_debug+0x30>
 *   @0x27e364 add r1, sp, #20
 *   @0x27e368 ldr r0, [sp, #0x10]
 *   @0x27e36c str r1, [sp, #0x4]
 *   @0x27e370 bl 0xb6cf4 <vprintf@plt>
 *   @0x27e374 add sp, sp, #12
 *   @0x27e378 ldr lr, [sp], #4
 *   @0x27e37c add sp, sp, #16
 *   @0x27e380 bx lr
 *   @0x27e384 subeq r8, sp, r0, ror #16
 *
 * ══ §260/438 _spCurveTimeline_init  0x2816d8  size 68  17 条（0x2816d8..0x28171c）
 * @func 0x2816d8 0x28171c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spTimeline_init / _calloc
 * 字段偏移 top8: 0x10×1 / 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2816d8 push {r3, r4, r5, lr}
 *   @0x2816dc mov r5, r2
 *   @0x2816e0 mov r2, r3
 *   @0x2816e4 ldr r3, [sp, #0x10]
 *   @0x2816e8 mov r4, r0
 *   @0x2816ec bl 0x281328 <_spTimeline_init>
 *   @0x2816f0 sub r12, r5, #1
 *   @0x2816f4 ldr r2, [pc, #0x1c]
 *   @0x2816f8 mov r1, #4
 *   @0x2816fc mov r3, #121
 *   @0x281700 add r0, r12, r12, lsl #3
 *   @0x281704 add r2, pc, r2
 *   @0x281708 add r0, r12, r0, lsl #1
 *   @0x28170c bl 0x285c4c <_calloc>
 *   @0x281710 str r0, [r4, #0x8]
 *   @0x281714 pop {r3, r4, r5, pc}
 *   @0x281718 andeq r5, sp, r12, asr #26
 *
 * ══ §261/438 _spTrackEntry_create  0x2830b0  size 68  17 条（0x2830b0..0x2830f4）
 * @func 0x2830b0 0x2830f4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x38×1 / 0x1c×1 / 0x24×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2830b0 ldr r2, [pc, #0x38]
 *   @0x2830b4 mov r1, #60
 *   @0x2830b8 push {r4, lr}
 *   @0x2830bc add r2, pc, r2
 *   @0x2830c0 mov r4, r0
 *   @0x2830c4 mov r3, #37
 *   @0x2830c8 mov r0, #1
 *   @0x2830cc bl 0x285c4c <_calloc>
 *   @0x2830d0 mov r2, #1065353216
 *   @0x2830d4 mov r1, #0
 *   @0x2830d8 movt r1, #0xbf80
 *   @0x2830dc str r4, [r0]
 *   @0x2830e0 str r1, [r0, #0x1c]
 *   @0x2830e4 str r2, [r0, #0x24]
 *   @0x2830e8 str r2, [r0, #0x34]
 *   @0x2830ec pop {r4, pc}
 *   @0x2830f0 andeq r4, sp, r12, asr #7
 *
 * ══ §262/438 spSkin_getAttachmentName  0x28ed58  size 68  17 条（0x28ed58..0x28ed9c）
 * @func 0x28ed58 0x28ed9c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ed58 ldr r0, [r0, #0x4]
 *   @0x28ed5c cmp r0, #0
 *   @0x28ed60 bxeq lr
 *   @0x28ed64 mov r12, #0
 *   @0x28ed68 b 0x28ed78 <spSkin_getAttachmentName+0x20>
 *   @0x28ed6c ldr r0, [r0, #0xc]
 *   @0x28ed70 cmp r0, #0
 *   @0x28ed74 beq 0x28ed98 <spSkin_getAttachmentName+0x40>
 *   @0x28ed78 ldr r3, [r0]
 *   @0x28ed7c cmp r3, r1
 *   @0x28ed80 bne 0x28ed6c <spSkin_getAttachmentName+0x14>
 *   @0x28ed84 cmp r12, r2
 *   @0x28ed88 add r12, r12, #1
 *   @0x28ed8c bne 0x28ed6c <spSkin_getAttachmentName+0x14>
 *   @0x28ed90 ldr r0, [r0, #0x4]
 *   @0x28ed94 bx lr
 *   @0x28ed98 bx lr
 *
 * ══ §263/438 Debug_QueryHeapMem(unsigned int&, unsigned long long&)  0x29c3a8  size 68  17 条（0x29c3a8..0x29c3ec）
 * @func 0x29c3a8 0x29c3ec  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6e8c
 * 字段偏移 top8: 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c3a8 push {r4, r5, r6, lr}
 *   @0x29c3ac sub sp, sp, #40
 *   @0x29c3b0 mov r5, r0
 *   @0x29c3b4 mov r6, #0
 *   @0x29c3b8 mov r2, #0
 *   @0x29c3bc str r6, [r0]
 *   @0x29c3c0 mov r3, #0
 *   @0x29c3c4 mov r0, sp
 *   @0x29c3c8 strd r2, r3, [r1]
 *   @0x29c3cc mov r4, r1
 *   @0x29c3d0 bl 0xb6e8c <mallinfo@plt>
 *   @0x29c3d4 ldr r2, [sp, #0x1c]
 *   @0x29c3d8 ldr r3, [sp, #0x20]
 *   @0x29c3dc str r2, [r5]
 *   @0x29c3e0 stm r4, {r3, r6}
 *   @0x29c3e4 add sp, sp, #40
 *   @0x29c3e8 pop {r4, r5, r6, pc}
 *
 * ══ §264/438 Debug_QuitDebugger()  0x29c6dc  size 68  17 条（0x29c6dc..0x29c720）
 * @func 0x29c6dc 0x29c720  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x24×1 / 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c6dc ldr r2, [pc, #0x30]
 *   @0x29c6e0 mov r12, #1
 *   @0x29c6e4 push {r3, lr}
 *   @0x29c6e8 ldr r2, [pc, r2]
 *   @0x29c6ec ldr r3, [pc, #0x24]
 *   @0x29c6f0 ldr r0, [r2]
 *   @0x29c6f4 ldr r3, [pc, r3]
 *   @0x29c6f8 ldr r1, [pc, #0x1c]
 *   @0x29c6fc strb r12, [r3]
 *   @0x29c700 add r1, pc, r1
 *   @0x29c704 ldr r3, [r0]
 *   @0x29c708 ldr r3, [r3, #0xc]
 *   @0x29c70c blx r3
 *   @0x29c710 pop {r3, pc}
 *   @0x29c714 andseq r1, r5, r8, asr r2
 *   @0x29c718 andseq r5, r5, r12, lsl r3
 *   @0x29c71c andeq sp, r11, r4, ror r3
 *
 * ══ §265/438 png_build_grayscale_palette  0x2a963c  size 68  17 条（0x2a963c..0x2a9680）
 * @func 0x2a963c 0x2a9680  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x4e9a74
 * 字段偏移 top8: 0x10×1 / 0x-3×1 / 0x18×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a963c push {r4, r5, lr}
 *   @0x2a9640 subs r0, #0x1
 *   @0x2a9644 bhi 0x2a9654 <png_build_grayscale_palette+0x18>
 *   @0x2a9648 add r3, pc
 *   @0x2a964c ldrmi r5, [r8], #-16
 *   @0x2a9650 ldrb r0, [r0, #0x10]
 *   @0x2a9654 movs r0, #0x0
 *   @0x2a9658 movs r3, #0x0
 *   @0x2a965c cmp r2, r5
 *   @0x2a9660 ble 0x4e9a74 <SrcVerts+0x46ab8>
 *   @0x2a9664 uxtb r4, r3
 *   @0x2a9668 strb r4, [r1, #-3]
 *   @0x2a966c add r3, r0
 *   @0x2a9670 .word 0xf8014c02
 *   @0x2a9674 ldrb r4, [r1, r1, lsl #24]!
 *   @0x2a9678 pop {r4, r5, pc}
 *   @0x2a967c str r4, [r4, #0x34]
 *
 * ══ §266/438 png_set_filler  0x2af7ce  size 68  17 条（0x2af7ce..0x2af812）
 * @func 0x2af7ce 0x2af812  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x33bfa6
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af7ce cbz r0, 0x2af810 <png_set_filler+0x42>
 *   @0x2af7d2 bhs 0x2fbcaa <ps_hints_apply+0xa8aa>
 *   @0x2af7d6 strh.w r1, [r0, #0x1f2]
 *   @0x2af7da orr r3, r3, #0x8000
 *   @0x2af7de str.w r3, [r0, #0x134]
 *   @0x2af7e2 ldr.w r3, [r0, #0x130]
 *   @0x2af7e6 ite eq
 *   @0x2af7ea .word 0xf0230380
 *   @0x2af7ee .word 0xf8c00380
 *   @0x2af7f2 .word 0xf8903130
 *   @0x2af7f6 blhs 0x33bfa6
 *   @0x2af7fa bne 0x2af800 <png_set_filler+0x32>
 *   @0x2af7fe b 0x2af80c <png_set_filler+0x3e>
 *   @0x2af802 ldrb.w r3, [r0, #0x1eb]
 *   @0x2af806 cmp r3, #0x7
 *   @0x2af80a movs r3, #0x2
 *   @0x2af80e ldrbmi r3, [r0, -pc, ror #3]!
 *
 * ══ §267/438 png_write_sRGB  0x2b184c  size 68  17 条（0x2b184c..0x2b1890）
 * @func 0x2b184c 0x2b1890  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x21×1 / 0x8×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b184c ldr r3, [pc, #0x38]
 *   @0x2b1850 push {r4, r5, lr}
 *   @0x2b1854 mov r4, r0
 *   @0x2b1858 ldr r0, [r3, #33]!
 *   @0x2b185c mov r5, r1
 *   @0x2b1860 str r0, [sp, #0x8]
 *   @0x2b1864 stcle p0, c3, [r4, #-48]
 *   @0x2b1868 ldr r1, [pc, #0x20]
 *   @0x2b186c add r1, pc
 *   @0x2b1870 strtmi pc, [r0], -r1, lsl #28
 *   @0x2b1874 add r1, sp, #0x8
 *   @0x2b1878 movs r3, #0x1
 *   @0x2b187c .word 0xf7ff5004
 *   @0x2b1880 andlt pc, r5, sp, lsl sp
 *   @0x2b1884 pop {r4, r5, pc}
 *   @0x2b1888 b 0x2b12a8 <png_write_chunk_end+0x12>
 *   @0x2b188c ldm r3, {r0, r1, r3, r5}
 *
 * ══ §268/438 jpeg_abort  0x2bc874  size 68  17 条（0x2bc874..0x2bc8b8）
 * @func 0x2bc874 0x2bc8b8  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x24×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc874 ldr r3, [r0, #0x4]
 *   @0x2bc878 push {r4, lr}
 *   @0x2bc87c cmp r3, #0
 *   @0x2bc880 mov r4, r0
 *   @0x2bc884 popeq {r4, pc}
 *   @0x2bc888 ldr r3, [r3, #0x24]
 *   @0x2bc88c mov r1, #1
 *   @0x2bc890 blx r3
 *   @0x2bc894 ldrb r3, [r4, #0x10]
 *   @0x2bc898 cmp r3, #0
 *   @0x2bc89c movne r2, #200
 *   @0x2bc8a0 movne r3, #0
 *   @0x2bc8a4 moveq r3, #100
 *   @0x2bc8a8 strne r3, [r4, #0x10c]
 *   @0x2bc8ac streq r3, [r4, #0x14]
 *   @0x2bc8b0 strne r2, [r4, #0x14]
 *   @0x2bc8b4 pop {r4, pc}
 *
 * ══ §269/438 b2PulleyJoint::ShiftOrigin(b2Vec2 const&)  0x2d06d8  size 68  17 条（0x2d06d8..0x2d071c）
 * @func 0x2d06d8 0x2d071c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d06d8 vldr s15, [r1]
 *   @0x2d06dc vldr s12, [r1, #4]
 *   @0x2d06e0 vldr s14, [r0, #68]
 *   @0x2d06e4 vldr s11, [r0, #72]
 *   @0x2d06e8 vsub.f32 s15, s14, s15
 *   @0x2d06ec vldr s13, [r0, #80]
 *   @0x2d06f0 vldr s14, [r0, #76]
 *   @0x2d06f4 vsub.f32 s12, s11, s12
 *   @0x2d06f8 vstr s15, [r0, #68]
 *   @0x2d06fc vldr s15, [r1]
 *   @0x2d0700 vstr s12, [r0, #72]
 *   @0x2d0704 vsub.f32 s14, s14, s15
 *   @0x2d0708 vldr s15, [r1, #4]
 *   @0x2d070c vsub.f32 s15, s13, s15
 *   @0x2d0710 vstr s14, [r0, #76]
 *   @0x2d0714 vstr s15, [r0, #80]
 *   @0x2d0718 bx lr
 *
 * ══ §270/438 b2ParticleSystem::DestroyParticlesInGroup(b2ParticleGroup*, bool)  0x2d52c4  size 68  17 条（0x2d52c4..0x2d5308）
 * @func 0x2d52c4 0x2d5308  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::DestroyParticle(int, bool)
 * 字段偏移 top8: 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d52c4 push {r3, r4, r5, r6, r7, lr}
 *   @0x2d52c8 mov r5, r1
 *   @0x2d52cc ldr r4, [r1, #0x4]
 *   @0x2d52d0 mov r7, r0
 *   @0x2d52d4 ldr r3, [r1, #0x8]
 *   @0x2d52d8 mov r6, r2
 *   @0x2d52dc cmp r4, r3
 *   @0x2d52e0 popge {r3, r4, r5, r6, r7, pc}
 *   @0x2d52e4 mov r1, r4
 *   @0x2d52e8 mov r0, r7
 *   @0x2d52ec mov r2, r6
 *   @0x2d52f0 add r4, r4, #1
 *   @0x2d52f4 bl 0x2d51c0 <_ZN16b2ParticleSystem15DestroyParticleEib>
 *   @0x2d52f8 ldr r3, [r5, #0x8]
 *   @0x2d52fc cmp r3, r4
 *   @0x2d5300 bgt 0x2d52e4 <_ZN16b2ParticleSystem23DestroyParticlesInGroupEP15b2ParticleGroupb+0x20>
 *   @0x2d5304 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §271/438 ft_synthesize_vertical_metrics  0x2e54e0  size 68  17 条（0x2e54e0..0x2e5524）
 * @func 0x2e54e0 0x2e5524  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e54e0 push {r3, r4, r5, lr}
 *   @0x2e54e4 ldr r3, [r0, #0xc]
 *   @0x2e54e8 cmp r3, #0x0
 *   @0x2e54ec cmp r5, r3
 *   @0x2e54f0 movlt r5, r3
 *   @0x2e54f4 it ne
 *   @0x2e54f8 stmdblt r9!, {r0, r2, r8, r10}
 *   @0x2e54fc movs r0, #0xc
 *   @0x2e5500 muls r0, r5, r0
 *   @0x2e5504 strmi lr, [r1], -r6, lsl #24
 *   @0x2e5508 ldr r3, [r4, #0x10]
 *   @0x2e550c ldr r2, [r4, #0x8]
 *   @0x2e5510 ldrdvs r7, r8, [r1, #85]!
 *   @0x2e5514 add.w r3, r3, r3, lsr #31
 *   @0x2e5518 asrs r5, r5, #0x1
 *   @0x2e551c sub.w r2, r2, r3, asr #1
 *   @0x2e5520 str r2, [r4, #0x14]
 *
 * ══ §272/438 FT_Select_Charmap  0x2e58f4  size 68  17 条（0x2e58f4..0x2e5938）
 * @func 0x2e58f4 0x2e5938  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x34×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e58f4 push {r4, r5, lr}
 *   @0x2e58f8 cbz r0, 0x2e5928 <FT_Select_Charmap+0x34>
 *   @0x2e58fc ldr r2, [pc, #0x34]
 *   @0x2e5900 bne 0x2e590a <FT_Select_Charmap+0x16>
 *   @0x2e5904 .word 0xf7ff4030
 *   @0x2e5908 bvs 0xfe393af4 <b2_toiTime+0xfffffffffdc3a650>
 *   @0x2e590c cbz r2, 0x2e5930 <FT_Select_Charmap+0x3c>
 *   @0x2e5910 add.w r5, r2, r0, lsl #2
 *   @0x2e5914 cmp r2, r5
 *   @0x2e5918 ldr r0, [r2], #4
 *   @0x2e591c ldr r4, [r0, #0x4]
 *   @0x2e5920 bne 0x2e5914 <FT_Select_Charmap+0x20>
 *   @0x2e5924 movs r0, #0x0
 *   @0x2e5928 movs r0, #0x23
 *   @0x2e592c movs r0, #0x6
 *   @0x2e5930 movs r0, #0x26
 *   @0x2e5934 ldr r3, [r4, #0x14]
 *
 * ══ §273/438 FT_Outline_Done_Internal  0x2e7dba  size 68  17 条（0x2e7dba..0x2e7dfe）
 * @func 0x2e7dba 0x2e7dfe  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free×2 / 0xb65b0
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7dba push {r4, r5, r6, lr}
 *   @0x2e7dbe mov r4, r1
 *   @0x2e7dc2 cbz r0, 0x2e7dfa <FT_Outline_Done_Internal+0x40>
 *   @0x2e7dc6 lsls r3, r3, #0x1f
 *   @0x2e7dca ldr r1, [r1, #0x4]
 *   @0x2e7dce bl 0x2e7336 <ft_mem_free>
 *   @0x2e7dd2 mov r0, r6
 *   @0x2e7dd6 str r5, [r4, #0x4]
 *   @0x2e7dda adcvs pc, r5, sp, lsr #21
 *   @0x2e7dde mov r0, r6
 *   @0x2e7de2 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7de6 str r5, [r4, #0xc]
 *   @0x2e7dea movs r1, #0x0
 *   @0x2e7dee blx 0xb65b0 <memset@plt>
 *   @0x2e7df2 movs r0, #0x0
 *   @0x2e7df6 movs r0, #0x14
 *   @0x2e7dfa movs r0, #0x6
 *
 * ══ §274/438 png_handle_as_unknown  0x2a5fe4  size 66  17 条（0x2a5fe4..0x2a6026）
 * @func 0x2a5fe4 0x2a6026  size 66  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5fe4 push {r4, r5, r6, lr}
 *   @0x2a5fe8 cbz r0, 0x2a6024 <png_handle_as_unknown+0x40>
 *   @0x2a5fec ldr.w r4, [r0, #0x2cc]
 *   @0x2a5ff0 cmp r4, #0x0
 *   @0x2a5ff4 movs r5, #0x5
 *   @0x2a5ff8 .word 0x436532d0
 *   @0x2a5ffc subs r5, #0x5
 *   @0x2a6000 mov r0, r6
 *   @0x2a6004 movs r2, #0x4
 *   @0x2a6008 stmdblt r8, {r2, r3, r4, r9, r10, r11, sp, lr, pc}
 *   @0x2a600c ldrb r0, [r5, #0x4]
 *   @0x2a6010 subs r4, #0x1
 *   @0x2a6014 mvnsle r0, r5, lsl #10
 *   @0x2a6018 mov r0, r4
 *   @0x2a601c mov r0, r1
 *   @0x2a6020 movs r0, #0x0
 *   @0x2a6024 pop {r4, r5, r6, pc}
 *
 * ══ §275/438 FT_Vector_Polarize  0x2e708c  size 66  17 条（0x2e708c..0x2e70ce）
 * @func 0x2e708c 0x2e70ce  size 66  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e490c+0x2d0 / anon_2e490c+0x22c / 0x366424 / 0x3244dc
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e708c push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e7090 mov r7, r2
 *   @0x2e7094 cbz r1, 0x2e70ca <FT_Vector_Polarize+0x3e>
 *   @0x2e7098 ldm r0, {r0, r1}
 *   @0x2e709c stmdblt r0, {r0, r1}
 *   @0x2e70a0 cbz r1, 0x2e70ca <FT_Vector_Polarize+0x3e>
 *   @0x2e70a4 bl 0x2e4bdc <_ZNK11b2GearJoint8GetRatioEv+0x2d8>
 *   @0x2e70a8 mov r5, r0
 *   @0x2e70ac bl 0x2e4b38 <_ZNK11b2GearJoint8GetRatioEv+0x234>
 *   @0x2e70b0 ldr r0, [sp]
 *   @0x2e70b4 blls 0x366424 <_ZTS12CDS_Priority+0x847c>
 *   @0x2e70b8 cmp r5, #0x0
 *   @0x2e70bc rsblt r5, r5, #0
 *   @0x2e70c0 blx 0x3244dc
 *   @0x2e70c4 eorsvs pc, r5, r5, lsl #10
 *   @0x2e70c8 str r3, [r7]
 *   @0x2e70cc pop {r4, r5, r6, r7, pc}
 *
 * ══ §276/438 FT_Done_GlyphSlot  0x2e7b1a  size 66  17 条（0x2e7b1a..0x2e7b5c）
 * @func 0x2e7b1a 0x2e7b5c  size 66  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7b1a push {r3, r4, r5, lr}
 *   @0x2e7b1e cbz r0, 0x2e7b5a <FT_Done_GlyphSlot+0x40>
 *   @0x2e7b22 movs r1, #0x0
 *   @0x2e7b26 ldr r5, [r3, #0x8]
 *   @0x2e7b2a cbz r3, 0x2e7b5a <FT_Done_GlyphSlot+0x40>
 *   @0x2e7b2e bne 0x2e7b54 <FT_Done_GlyphSlot+0x3a>
 *   @0x2e7b32 cbnz r1, 0x2e7b38 <FT_Done_GlyphSlot+0x1e>
 *   @0x2e7b36 b 0x2e7b3a <FT_Done_GlyphSlot+0x20>
 *   @0x2e7b3a ldr r3, [r4, #0x14]
 *   @0x2e7b3e mov r0, r4
 *   @0x2e7b42 mov r0, r4
 *   @0x2e7b46 qsub16mi pc, r8, r1
 *   @0x2e7b4a mov r1, r4
 *   @0x2e7b4e .word 0xf7ff4038
 *   @0x2e7b52 ssub8mi r11, r9, r1
 *   @0x2e7b56 ldr r3, [r3, #0x8]
 *   @0x2e7b5a pop {r3, r4, r5, pc}
 *
 * ══ §277/438 ft_mem_realloc  0x2e808e  size 66  17 条（0x2e808e..0x2e80d0）
 * @func 0x2e808e 0x2e80d0  size 66  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_qrealloc / ft_mem_realloc+0x34 / 0x4688e0 / 0xb65b0
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x4×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e808e push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr}
 *   @0x2e8092 add r5, sp, #0x10
 *   @0x2e8096 mov r6, r1
 *   @0x2e809a ldrmi r7, [r4], -r4, lsl #26
 *   @0x2e809e ldr r7, [sp, #0x28]
 *   @0x2e80a2 str r5, [sp, #0x4]
 *   @0x2e80a6 bl 0x2e8010 <ft_mem_qrealloc>
 *   @0x2e80aa ldr r1, [sp, #0xc]
 *   @0x2e80ae cbnz r1, 0x2e80c2 <ft_mem_realloc+0x34>
 *   @0x2e80b2 ble 0x2e80c2 <ft_mem_realloc+0x34>
 *   @0x2e80b6 blx 0x4688e0 <g_RomDisk+0x710c0>
 *   @0x2e80ba cmnmi r2, #4
 *   @0x2e80be blx 0xb65b0 <memset@plt>
 *   @0x2e80c2 ldr r2, [sp, #0xc]
 *   @0x2e80c6 ldr r3, [sp, #0x2c]
 *   @0x2e80ca add sp, #0x10
 *   @0x2e80ce ldrlt r8, [pc, #-0x1f0]
 *
 * ══ §278/438 ChangeToOldPoly(bool)  0xc44ac  size 64  16 条（0xc44ac..0xc44ec）
 * @func 0xc44ac 0xc44ec  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f2004
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc44ac cmp r0, #0
 *   @0xc44b0 bne 0xc44cc <_Z15ChangeToOldPolyb+0x20>
 *   @0xc44b4 ldr r2, [pc, #0x28]
 *   @0xc44b8 movw r3, #0x2d24
 *   @0xc44bc movt r3, #0xda44
 *   @0xc44c0 add r2, pc, r2
 *   @0xc44c4 str r3, [r2]
 *   @0xc44c8 bx lr
 *   @0xc44cc ldr r2, [pc, #0x14]
 *   @0xc44d0 movw r3, #0x2d20
 *   @0xc44d4 movt r3, #0xda44
 *   @0xc44d8 add r2, pc, r2
 *   @0xc44dc str r3, [r2]
 *   @0xc44e0 bx lr
 *   @0xc44e4 eorseq sp, r2, r12, lsr r11
 *   @0xc44e8 eorseq sp, r2, r4, lsr #22
 *
 * ══ §279/438 Buffer_Fast::Poke(int, eBuffer_Type, RValue*)  0xc4cc8  size 64  16 条（0xc4cc8..0xc4d08）
 * @func 0xc4cc8 0xc4d08  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4cc8 cmp r2, #1
 *   @0xc4ccc mov r2, r0
 *   @0xc4cd0 push {r3, r4, r5, lr}
 *   @0xc4cd4 mov r4, r1
 *   @0xc4cd8 popne {r3, r4, r5, pc}
 *   @0xc4cdc cmp r1, #0
 *   @0xc4ce0 poplt {r3, r4, r5, pc}
 *   @0xc4ce4 ldr r1, [r0, #0x10]
 *   @0xc4ce8 cmp r4, r1
 *   @0xc4cec popge {r3, r4, r5, pc}
 *   @0xc4cf0 mov r0, r3
 *   @0xc4cf4 mov r1, #0
 *   @0xc4cf8 ldr r5, [r2, #0xc]
 *   @0xc4cfc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc4d00 strb r0, [r5, r4]
 *   @0xc4d04 pop {r3, r4, r5, pc}
 *
 * ══ §280/438 TErrStreamConsole::~TErrStreamConsole()  0xd3424  size 64  16 条（0xd3424..0xd3464）
 * @func 0xd3424 0xd3464  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x30×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3424 ldr r3, [pc, #0x30]
 *   @0xd3428 push {r4, lr}
 *   @0xd342c ldr r3, [pc, r3]
 *   @0xd3430 mov r4, r0
 *   @0xd3434 add r3, r3, #8
 *   @0xd3438 ldr r0, [r0, #0x8]
 *   @0xd343c str r3, [r4]
 *   @0xd3440 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd3444 ldr r3, [pc, #0x14]
 *   @0xd3448 mov r0, r4
 *   @0xd344c ldr r3, [pc, r3]
 *   @0xd3450 add r3, r3, #8
 *   @0xd3454 str r3, [r4]
 *   @0xd3458 pop {r4, pc}
 *   @0xd345c mlaseq r1, r12, r7, r10
 *   @0xd3460 eorseq r10, r1, r4, lsl r5
 *
 * ══ §281/438 StepToStr(int)  0xf344c  size 64  16 条（0xf344c..0xf348c）
 * @func 0xf344c 0xf348c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf344c cmp r0, #1
 *   @0xf3450 beq 0xf3474 <_Z9StepToStri+0x28>
 *   @0xf3454 cmp r0, #2
 *   @0xf3458 bne 0xf3468 <_Z9StepToStri+0x1c>
 *   @0xf345c ldr r0, [pc, #0x1c]
 *   @0xf3460 add r0, pc, r0
 *   @0xf3464 bx lr
 *   @0xf3468 ldr r0, [pc, #0x14]
 *   @0xf346c add r0, pc, r0
 *   @0xf3470 bx lr
 *   @0xf3474 ldr r0, [pc, #0xc]
 *   @0xf3478 add r0, pc, r0
 *   @0xf347c bx lr
 *   @0xf3480 mlaeq r4, r0, r11, r3
 *   @0xf3484 eoreq r11, r3, r10, asr #13
 *   @0xf3488 eoreq r3, r4, r0, ror r11
 *
 * ══ §282/438 Font_Data(int)  0xfa3fc  size 64  16 条（0xfa3fc..0xfa43c）
 * @func 0xfa3fc 0xfa43c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_Data(int)+0x30
 * 字段偏移 top8: 0x28×1 / 0x18×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa3fc cmp r0, #0
 *   @0xfa400 blt 0xfa42c <_Z9Font_Datai+0x30>
 *   @0xfa404 ldr r3, [pc, #0x28]
 *   @0xfa408 ldr r3, [pc, r3]
 *   @0xfa40c ldr r3, [r3]
 *   @0xfa410 cmp r0, r3
 *   @0xfa414 bge 0xfa42c <_Z9Font_Datai+0x30>
 *   @0xfa418 ldr r3, [pc, #0x18]
 *   @0xfa41c ldr r3, [pc, r3]
 *   @0xfa420 ldr r3, [r3, #0x4]
 *   @0xfa424 ldr r0, [r3, r0, lsl #2]
 *   @0xfa428 bx lr
 *   @0xfa42c mov r0, #0
 *   @0xfa430 bx lr
 *   @0xfa434 eoreq r3, pc, r8, asr r10
 *   @0xfa438 eoreq r3, pc, r0, asr #20
 *
 * ══ §283/438 dsMapClear  0x1017d8  size 64  16 条（0x1017d8..0x101818）
 * @func 0x1017d8 0x101818  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x24×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1017d8 vmov s13, r0
 *   @0x1017dc mov r12, #0
 *   @0x1017e0 str lr, [sp, #-0x4]!
 *   @0x1017e4 vcvt.f64.s32 d7, s13
 *   @0x1017e8 sub sp, sp, #44
 *   @0x1017ec mov r1, r12
 *   @0x1017f0 add r3, sp, #24
 *   @0x1017f4 mov r2, r12
 *   @0x1017f8 str r3, [sp]
 *   @0x1017fc add r0, sp, #8
 *   @0x101800 mov r3, #1
 *   @0x101804 str r12, [sp, #0x24]
 *   @0x101808 vstr d7, [sp, #24]
 *   @0x10180c bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x101810 add sp, sp, #44
 *   @0x101814 ldr pc, [sp], #4
 *
 * ══ §284/438 F_MoveContactSolid(RValue&, CInstance*, CInstance*, int, RValue*)  0x1083cc  size 64  16 条（0x1083cc..0x10840c）
 * @func 0x1083cc 0x10840c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1083cc push {r4, r5, r6, lr}
 *   @0x1083d0 mov r6, r1
 *   @0x1083d4 ldr r4, [sp, #0x10]
 *   @0x1083d8 mov r1, #0
 *   @0x1083dc mov r0, r4
 *   @0x1083e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1083e4 mov r1, #1
 *   @0x1083e8 mov r5, r0
 *   @0x1083ec mov r0, r4
 *   @0x1083f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1083f4 mov r1, r5
 *   @0x1083f8 mov r3, #0
 *   @0x1083fc mov r2, r0
 *   @0x108400 mov r0, r6
 *   @0x108404 pop {r4, r5, r6, lr}
 *   @0x108408 b 0x1cad28 <_Z19Command_MoveContactP9CInstanceffb>
 *
 * ══ §285/438 F_MoveContactAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x10840c  size 64  16 条（0x10840c..0x10844c）
 * @func 0x10840c 0x10844c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10840c push {r4, r5, r6, lr}
 *   @0x108410 mov r6, r1
 *   @0x108414 ldr r4, [sp, #0x10]
 *   @0x108418 mov r1, #0
 *   @0x10841c mov r0, r4
 *   @0x108420 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108424 mov r1, #1
 *   @0x108428 mov r5, r0
 *   @0x10842c mov r0, r4
 *   @0x108430 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108434 mov r1, r5
 *   @0x108438 mov r3, #1
 *   @0x10843c mov r2, r0
 *   @0x108440 mov r0, r6
 *   @0x108444 pop {r4, r5, r6, lr}
 *   @0x108448 b 0x1cad28 <_Z19Command_MoveContactP9CInstanceffb>
 *
 * ══ §286/438 F_MoveOutsideSolid(RValue&, CInstance*, CInstance*, int, RValue*)  0x10844c  size 64  16 条（0x10844c..0x10848c）
 * @func 0x10844c 0x10848c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10844c push {r4, r5, r6, lr}
 *   @0x108450 mov r6, r1
 *   @0x108454 ldr r4, [sp, #0x10]
 *   @0x108458 mov r1, #0
 *   @0x10845c mov r0, r4
 *   @0x108460 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108464 mov r1, #1
 *   @0x108468 mov r5, r0
 *   @0x10846c mov r0, r4
 *   @0x108470 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108474 mov r1, r5
 *   @0x108478 mov r3, #0
 *   @0x10847c mov r2, r0
 *   @0x108480 mov r0, r6
 *   @0x108484 pop {r4, r5, r6, lr}
 *   @0x108488 b 0x1cae64 <_Z19Command_MoveOutsideP9CInstanceffb>
 *
 * ══ §287/438 F_MoveOutsideAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x10848c  size 64  16 条（0x10848c..0x1084cc）
 * @func 0x10848c 0x1084cc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10848c push {r4, r5, r6, lr}
 *   @0x108490 mov r6, r1
 *   @0x108494 ldr r4, [sp, #0x10]
 *   @0x108498 mov r1, #0
 *   @0x10849c mov r0, r4
 *   @0x1084a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1084a4 mov r1, #1
 *   @0x1084a8 mov r5, r0
 *   @0x1084ac mov r0, r4
 *   @0x1084b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1084b4 mov r1, r5
 *   @0x1084b8 mov r3, #1
 *   @0x1084bc mov r2, r0
 *   @0x1084c0 mov r0, r6
 *   @0x1084c4 pop {r4, r5, r6, lr}
 *   @0x1084c8 b 0x1cae64 <_Z19Command_MoveOutsideP9CInstanceffb>
 *
 * ══ §288/438 F_ArraySetPost(RValue&, CInstance*, CInstance*, int, RValue*)  0x10dd00  size 64  16 条（0x10dd00..0x10dd40）
 * @func 0x10dd00 0x10dd40  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dd00 push {r4, r5, r6, lr}
 *   @0x10dd04 mov r1, #1
 *   @0x10dd08 ldr r4, [sp, #0x10]
 *   @0x10dd0c mov r6, r0
 *   @0x10dd10 mov r0, r4
 *   @0x10dd14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10dd18 mov r1, r4
 *   @0x10dd1c mov r5, r0
 *   @0x10dd20 mov r0, r6
 *   @0x10dd24 mov r2, r5
 *   @0x10dd28 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x10dd2c mov r0, r4
 *   @0x10dd30 mov r2, r5
 *   @0x10dd34 add r1, r4, #32
 *   @0x10dd38 pop {r4, r5, r6, lr}
 *   @0x10dd3c b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *
 * ══ §289/438 F_Real(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ec24  size 64  16 条（0x10ec24..0x10ec64）
 * @func 0x10ec24 0x10ec64  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ec24 push {r4, lr}
 *   @0x10ec28 mov r2, #0
 *   @0x10ec2c ldr r3, [sp, #0x8]
 *   @0x10ec30 mov r4, r0
 *   @0x10ec34 str r2, [r0, #0xc]
 *   @0x10ec38 ldr r2, [r3, #0xc]
 *   @0x10ec3c bic r2, r2, #-16777216
 *   @0x10ec40 cmp r2, #0
 *   @0x10ec44 bne 0x10ec54 <_Z6F_RealR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x10ec48 ldm r3, {r0, r1}
 *   @0x10ec4c stm r4, {r0, r1}
 *   @0x10ec50 pop {r4, pc}
 *   @0x10ec54 mov r0, r3
 *   @0x10ec58 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x10ec5c stm r4, {r0, r1}
 *   @0x10ec60 pop {r4, pc}
 *
 * ══ §290/438 F_ColorGetHue(RValue&, CInstance*, CInstance*, int, RValue*)  0x11aae0  size 64  16 条（0x11aae0..0x11ab20）
 * @func 0x11aae0 0x11ab20  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Color_ColorToHSV(unsigned int)
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11aae0 push {r4, lr}
 *   @0x11aae4 sub sp, sp, #8
 *   @0x11aae8 mov r3, #0
 *   @0x11aaec mov r4, r0
 *   @0x11aaf0 mov r1, r3
 *   @0x11aaf4 str r3, [r0, #0xc]
 *   @0x11aaf8 ldr r0, [sp, #0x10]
 *   @0x11aafc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ab00 bl 0x20fca8 <_Z16Color_ColorToHSVj>
 *   @0x11ab04 uxtb r0, r0
 *   @0x11ab08 vmov s15, r0
 *   @0x11ab0c vcvt.f64.u32 d7, s15
 *   @0x11ab10 vmov r2, r3, d7
 *   @0x11ab14 stm r4, {r2, r3}
 *   @0x11ab18 add sp, sp, #8
 *   @0x11ab1c pop {r4, pc}
 *
 * ══ §291/438 F_ColorGetSaturation(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ab20  size 64  16 条（0x11ab20..0x11ab60）
 * @func 0x11ab20 0x11ab60  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Color_ColorToHSV(unsigned int)
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ab20 push {r4, lr}
 *   @0x11ab24 sub sp, sp, #8
 *   @0x11ab28 mov r3, #0
 *   @0x11ab2c mov r4, r0
 *   @0x11ab30 mov r1, r3
 *   @0x11ab34 str r3, [r0, #0xc]
 *   @0x11ab38 ldr r0, [sp, #0x10]
 *   @0x11ab3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ab40 bl 0x20fca8 <_Z16Color_ColorToHSVj>
 *   @0x11ab44 ubfx r0, r0, #0x8, #0x8
 *   @0x11ab48 vmov s15, r0
 *   @0x11ab4c vcvt.f64.u32 d7, s15
 *   @0x11ab50 vmov r2, r3, d7
 *   @0x11ab54 stm r4, {r2, r3}
 *   @0x11ab58 add sp, sp, #8
 *   @0x11ab5c pop {r4, pc}
 *
 * ══ §292/438 F_ColorGetValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ab60  size 64  16 条（0x11ab60..0x11aba0）
 * @func 0x11ab60 0x11aba0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Color_ColorToHSV(unsigned int)
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ab60 push {r4, lr}
 *   @0x11ab64 sub sp, sp, #8
 *   @0x11ab68 mov r3, #0
 *   @0x11ab6c mov r4, r0
 *   @0x11ab70 mov r1, r3
 *   @0x11ab74 str r3, [r0, #0xc]
 *   @0x11ab78 ldr r0, [sp, #0x10]
 *   @0x11ab7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ab80 bl 0x20fca8 <_Z16Color_ColorToHSVj>
 *   @0x11ab84 ubfx r0, r0, #0x10, #0x8
 *   @0x11ab88 vmov s15, r0
 *   @0x11ab8c vcvt.f64.u32 d7, s15
 *   @0x11ab90 vmov r2, r3, d7
 *   @0x11ab94 stm r4, {r2, r3}
 *   @0x11ab98 add sp, sp, #8
 *   @0x11ab9c pop {r4, pc}
 *
 * ══ §293/438 F_TextureExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bba4  size 64  16 条（0x11bba4..0x11bbe4）
 * @func 0x11bba4 0x11bbe4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetPtrOrInt(RValue const*, int) / GR_Texture_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bba4 push {r3, r4, r5, lr}
 *   @0x11bba8 mov r5, #0
 *   @0x11bbac mov r4, r0
 *   @0x11bbb0 mov r1, r5
 *   @0x11bbb4 str r5, [r0, #0xc]
 *   @0x11bbb8 ldr r0, [sp, #0x10]
 *   @0x11bbbc bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x11bbc0 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x11bbc4 cmp r0, #0
 *   @0x11bbc8 moveq r5, r0
 *   @0x11bbcc movne r3, r5
 *   @0x11bbd0 moveq r3, r5
 *   @0x11bbd4 movtne r3, #0x3ff0
 *   @0x11bbd8 str r5, [r4]
 *   @0x11bbdc str r3, [r4, #0x4]
 *   @0x11bbe0 pop {r3, r4, r5, pc}
 *
 * ══ §294/438 F_SurfaceExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c888  size 64  16 条（0x11c888..0x11c8c8）
 * @func 0x11c888 0x11c8c8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GR_Surface_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c888 push {r3, r4, r5, lr}
 *   @0x11c88c mov r5, #0
 *   @0x11c890 mov r4, r0
 *   @0x11c894 mov r1, r5
 *   @0x11c898 str r5, [r0, #0xc]
 *   @0x11c89c ldr r0, [sp, #0x10]
 *   @0x11c8a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c8a4 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11c8a8 cmp r0, #0
 *   @0x11c8ac moveq r5, r0
 *   @0x11c8b0 movne r3, r5
 *   @0x11c8b4 moveq r3, r5
 *   @0x11c8b8 movtne r3, #0x3ff0
 *   @0x11c8bc str r5, [r4]
 *   @0x11c8c0 str r3, [r4, #0x4]
 *   @0x11c8c4 pop {r3, r4, r5, pc}
 *
 * ══ §295/438 F_CheckKey(RValue&, CInstance*, CInstance*, int, RValue*)  0x127880  size 64  16 条（0x127880..0x1278c0）
 * @func 0x127880 0x1278c0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGML_keyboard_check(int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x127880 push {r3, r4, r5, lr}
 *   @0x127884 mov r5, #0
 *   @0x127888 mov r4, r0
 *   @0x12788c mov r1, r5
 *   @0x127890 str r5, [r0, #0xc]
 *   @0x127894 ldr r0, [sp, #0x10]
 *   @0x127898 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12789c bl 0x1277f8 <_Z20YYGML_keyboard_checki>
 *   @0x1278a0 cmp r0, #0
 *   @0x1278a4 moveq r5, r0
 *   @0x1278a8 movne r3, r5
 *   @0x1278ac moveq r3, r5
 *   @0x1278b0 movtne r3, #0x3ff0
 *   @0x1278b4 str r5, [r4]
 *   @0x1278b8 str r3, [r4, #0x4]
 *   @0x1278bc pop {r3, r4, r5, pc}
 *
 * ══ §296/438 F_YoYo_Win8_NULL(RValue&, CInstance*, CInstance*, int, RValue*)  0x128b18  size 64  16 条（0x128b18..0x128b58）
 * @func 0x128b18 0x128b58  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x128b18 push {r3, lr}
 *   @0x128b1c mov r2, #0
 *   @0x128b20 ldr r3, [pc, #0x28]
 *   @0x128b24 str r2, [r0]
 *   @0x128b28 ldr r3, [pc, r3]
 *   @0x128b2c str r2, [r0, #0x4]
 *   @0x128b30 str r2, [r0, #0xc]
 *   @0x128b34 ldr r0, [r3]
 *   @0x128b38 ldr r1, [pc, #0x14]
 *   @0x128b3c ldr r3, [r0]
 *   @0x128b40 add r1, pc, r1
 *   @0x128b44 ldr r3, [r3, #0xc]
 *   @0x128b48 blx r3
 *   @0x128b4c pop {r3, pc}
 *   @0x128b50 eoreq r4, r12, r12, ror #23
 *   @0x128b54 eoreq r3, r1, r0, lsl #31
 *
 * ══ §297/438 F_SpriteExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b1fc  size 64  16 条（0x12b1fc..0x12b23c）
 * @func 0x12b1fc 0x12b23c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b1fc push {r3, r4, r5, lr}
 *   @0x12b200 mov r4, #0
 *   @0x12b204 mov r5, r0
 *   @0x12b208 mov r1, r4
 *   @0x12b20c str r4, [r0, #0xc]
 *   @0x12b210 str r4, [r0]
 *   @0x12b214 str r4, [r0, #0x4]
 *   @0x12b218 ldr r0, [sp, #0x10]
 *   @0x12b21c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b220 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x12b224 cmp r0, r4
 *   @0x12b228 strne r4, [r5]
 *   @0x12b22c movne r3, r4
 *   @0x12b230 movtne r3, #0x3ff0
 *   @0x12b234 strne r3, [r5, #0x4]
 *   @0x12b238 pop {r3, r4, r5, pc}
 *
 * ══ §298/438 F_BackgroundExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c1a0  size 64  16 条（0x12c1a0..0x12c1e0）
 * @func 0x12c1a0 0x12c1e0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c1a0 push {r3, r4, r5, lr}
 *   @0x12c1a4 mov r4, #0
 *   @0x12c1a8 mov r5, r0
 *   @0x12c1ac mov r1, r4
 *   @0x12c1b0 str r4, [r0, #0xc]
 *   @0x12c1b4 str r4, [r0]
 *   @0x12c1b8 str r4, [r0, #0x4]
 *   @0x12c1bc ldr r0, [sp, #0x10]
 *   @0x12c1c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c1c4 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x12c1c8 cmp r0, r4
 *   @0x12c1cc strne r4, [r5]
 *   @0x12c1d0 movne r3, r4
 *   @0x12c1d4 movtne r3, #0x3ff0
 *   @0x12c1d8 strne r3, [r5, #0x4]
 *   @0x12c1dc pop {r3, r4, r5, pc}
 *
 * ══ §299/438 F_FontExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ccf0  size 64  16 条（0x12ccf0..0x12cd30）
 * @func 0x12ccf0 0x12cd30  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ccf0 push {r3, r4, r5, lr}
 *   @0x12ccf4 mov r4, #0
 *   @0x12ccf8 mov r5, r0
 *   @0x12ccfc mov r1, r4
 *   @0x12cd00 str r4, [r0, #0xc]
 *   @0x12cd04 str r4, [r0]
 *   @0x12cd08 str r4, [r0, #0x4]
 *   @0x12cd0c ldr r0, [sp, #0x10]
 *   @0x12cd10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cd14 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x12cd18 cmp r0, r4
 *   @0x12cd1c strne r4, [r5]
 *   @0x12cd20 movne r3, r4
 *   @0x12cd24 movtne r3, #0x3ff0
 *   @0x12cd28 strne r3, [r5, #0x4]
 *   @0x12cd2c pop {r3, r4, r5, pc}
 *
 * ══ §300/438 F_PathExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d390  size 64  16 条（0x12d390..0x12d3d0）
 * @func 0x12d390 0x12d3d0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d390 push {r3, r4, r5, lr}
 *   @0x12d394 mov r5, #0
 *   @0x12d398 mov r4, r0
 *   @0x12d39c mov r1, r5
 *   @0x12d3a0 str r5, [r0, #0xc]
 *   @0x12d3a4 ldr r0, [sp, #0x10]
 *   @0x12d3a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d3ac bl 0x1a8008 <_Z11Path_Existsi>
 *   @0x12d3b0 cmp r0, #0
 *   @0x12d3b4 moveq r5, r0
 *   @0x12d3b8 movne r3, r5
 *   @0x12d3bc moveq r3, r5
 *   @0x12d3c0 movtne r3, #0x3ff0
 *   @0x12d3c4 str r5, [r4]
 *   @0x12d3c8 str r3, [r4, #0x4]
 *   @0x12d3cc pop {r3, r4, r5, pc}
 *
 * ══ §301/438 F_TimeLineExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x12de44  size 64  16 条（0x12de44..0x12de84）
 * @func 0x12de44 0x12de84  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / TimeLine_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12de44 push {r3, r4, r5, lr}
 *   @0x12de48 mov r5, #0
 *   @0x12de4c mov r4, r0
 *   @0x12de50 mov r1, r5
 *   @0x12de54 str r5, [r0, #0xc]
 *   @0x12de58 ldr r0, [sp, #0x10]
 *   @0x12de5c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12de60 bl 0x1f2b18 <_Z15TimeLine_Existsi>
 *   @0x12de64 cmp r0, #0
 *   @0x12de68 moveq r5, r0
 *   @0x12de6c movne r3, r5
 *   @0x12de70 moveq r3, r5
 *   @0x12de74 movtne r3, #0x3ff0
 *   @0x12de78 str r5, [r4]
 *   @0x12de7c str r3, [r4, #0x4]
 *   @0x12de80 pop {r3, r4, r5, pc}
 *
 * ══ §302/438 F_RoomExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e280  size 64  16 条（0x12e280..0x12e2c0）
 * @func 0x12e280 0x12e2c0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e280 push {r3, r4, r5, lr}
 *   @0x12e284 mov r5, #0
 *   @0x12e288 mov r4, r0
 *   @0x12e28c mov r1, r5
 *   @0x12e290 str r5, [r0, #0xc]
 *   @0x12e294 ldr r0, [sp, #0x10]
 *   @0x12e298 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e29c bl 0x1b52f8 <_Z11Room_Existsi>
 *   @0x12e2a0 cmp r0, #0
 *   @0x12e2a4 moveq r5, r0
 *   @0x12e2a8 movne r3, r5
 *   @0x12e2ac moveq r3, r5
 *   @0x12e2b0 movtne r3, #0x3ff0
 *   @0x12e2b4 str r5, [r4]
 *   @0x12e2b8 str r3, [r4, #0x4]
 *   @0x12e2bc pop {r3, r4, r5, pc}
 *
 * ══ §303/438 F_AudioDebug(RValue&, CInstance*, CInstance*, int, RValue*)  0x1361a8  size 64  16 条（0x1361a8..0x1361e8）
 * @func 0x1361a8 0x1361e8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x30×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1361a8 push {r3, lr}
 *   @0x1361ac ldr r3, [pc, #0x30]
 *   @0x1361b0 ldr r2, [sp, #0x8]
 *   @0x1361b4 ldr r3, [pc, r3]
 *   @0x1361b8 ldrb r1, [r3]
 *   @0x1361bc cmp r1, #0
 *   @0x1361c0 popne {r3, pc}
 *   @0x1361c4 str r1, [r0, #0xc]
 *   @0x1361c8 mov r0, r2
 *   @0x1361cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1361d0 pop {r3, lr}
 *   @0x1361d4 cmp r0, #0
 *   @0x1361d8 movle r0, #0
 *   @0x1361dc movgt r0, #1
 *   @0x1361e0 b 0x21d6bc <_Z11Audio_Debugb>
 *   @0x1361e4 mlaeq r11, r8, lr, r8
 *
 * ══ §304/438 YYGML_action_fullscreen(int)  0x141ddc  size 64  16 条（0x141ddc..0x141e1c）
 * @func 0x141ddc 0x141e1c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_FullScreen()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141ddc cmp r0, #1
 *   @0x141de0 push {r3, lr}
 *   @0x141de4 beq 0x141e10 <_Z23YYGML_action_fullscreeni+0x34>
 *   @0x141de8 cmp r0, #2
 *   @0x141dec beq 0x141e04 <_Z23YYGML_action_fullscreeni+0x28>
 *   @0x141df0 bl 0x17af24 <_Z24GR_Window_Get_FullScreenv>
 *   @0x141df4 pop {r3, lr}
 *   @0x141df8 eor r0, r0, #1
 *   @0x141dfc uxtb r0, r0
 *   @0x141e00 b 0x17af10 <_Z24GR_Window_Set_FullScreenb>
 *   @0x141e04 mov r0, #1
 *   @0x141e08 pop {r3, lr}
 *   @0x141e0c b 0x17af10 <_Z24GR_Window_Set_FullScreenb>
 *   @0x141e10 mov r0, #0
 *   @0x141e14 pop {r3, lr}
 *   @0x141e18 b 0x17af10 <_Z24GR_Window_Set_FullScreenb>
 *
 * ══ §305/438 F_IAP_RestoreAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x1552b4  size 64  16 条（0x1552b4..0x1552f4）
 * @func 0x1552b4 0x1552f4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_154a70
 * 字段偏移 top8: 0x-4×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1552b4 str lr, [sp, #-0x4]!
 *   @0x1552b8 sub sp, sp, #12
 *   @0x1552bc ldr r1, [pc, #0x2c]
 *   @0x1552c0 mov r3, #0
 *   @0x1552c4 mov r2, #0
 *   @0x1552c8 str r3, [sp]
 *   @0x1552cc add r1, pc, r1
 *   @0x1552d0 mov r0, #1
 *   @0x1552d4 mov r3, #0
 *   @0x1552d8 movt r3, #0x4010
 *   @0x1552dc bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x1552e0 mov r1, #4
 *   @0x1552e4 add sp, sp, #12
 *   @0x1552e8 ldr lr, [sp], #4
 *   @0x1552ec b 0x153acc <_Z16InitIAPFunctionsv+0x5f8>
 *   @0x1552f0 andseq r0, pc, r12, asr lr
 *
 * ══ §306/438 F_YoYo_WinPhone_License_Trial(RValue&, CInstance*, CInstance*, int, RValue*)  0x156224  size 64  16 条（0x156224..0x156264）
 * @func 0x156224 0x156264  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156224 push {r3, lr}
 *   @0x156228 mov r2, #0
 *   @0x15622c ldr r3, [pc, #0x28]
 *   @0x156230 str r2, [r0]
 *   @0x156234 ldr r3, [pc, r3]
 *   @0x156238 str r2, [r0, #0x4]
 *   @0x15623c str r2, [r0, #0xc]
 *   @0x156240 ldr r0, [r3]
 *   @0x156244 ldr r1, [pc, #0x14]
 *   @0x156248 ldr r3, [r0]
 *   @0x15624c add r1, pc, r1
 *   @0x156250 ldr r3, [r3, #0xc]
 *   @0x156254 blx r3
 *   @0x156258 pop {r3, pc}
 *   @0x15625c eoreq r7, r9, r0, ror #9
 *   @0x156260 andseq r0, pc, r0, asr #5
 *
 * ══ §307/438 F_YoYo_WinPhone_SetTile_Iconic_WideContent(RValue&, CInstance*, CInstance*, int, RValue*)  0x1562c4  size 64  16 条（0x1562c4..0x156304）
 * @func 0x1562c4 0x156304  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1562c4 push {r3, lr}
 *   @0x1562c8 mov r2, #0
 *   @0x1562cc ldr r3, [pc, #0x28]
 *   @0x1562d0 str r2, [r0]
 *   @0x1562d4 ldr r3, [pc, r3]
 *   @0x1562d8 str r2, [r0, #0x4]
 *   @0x1562dc str r2, [r0, #0xc]
 *   @0x1562e0 ldr r0, [r3]
 *   @0x1562e4 ldr r1, [pc, #0x14]
 *   @0x1562e8 ldr r3, [r0]
 *   @0x1562ec add r1, pc, r1
 *   @0x1562f0 ldr r3, [r3, #0xc]
 *   @0x1562f4 blx r3
 *   @0x1562f8 pop {r3, pc}
 *   @0x1562fc eoreq r7, r9, r0, asr #8
 *   @0x156300 andseq r0, pc, r0, lsr #4
 *
 * ══ §308/438 F_YoYo_FacebookCheckPermission(RValue&, CInstance*, CInstance*, int, RValue*)  0x157550  size 64  16 条（0x157550..0x157590）
 * @func 0x157550 0x157590  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / FacebookCheckPermissionM(char*)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157550 push {r3, r4, r5, lr}
 *   @0x157554 mov r5, #0
 *   @0x157558 mov r4, r0
 *   @0x15755c mov r1, r5
 *   @0x157560 str r5, [r0, #0xc]
 *   @0x157564 ldr r0, [sp, #0x10]
 *   @0x157568 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x15756c bl 0x15e848 <_Z24FacebookCheckPermissionMPc>
 *   @0x157570 cmp r0, #0
 *   @0x157574 moveq r5, r0
 *   @0x157578 movne r3, r5
 *   @0x15757c moveq r3, r5
 *   @0x157580 movtne r3, #0x3ff0
 *   @0x157584 str r5, [r4]
 *   @0x157588 str r3, [r4, #0x4]
 *   @0x15758c pop {r3, r4, r5, pc}
 *
 * ══ §309/438 F_YoYo_FacebookRequestReadPermissions(RValue&, CInstance*, CInstance*, int, RValue*)  0x157590  size 64  16 条（0x157590..0x1575d0）
 * @func 0x157590 0x1575d0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / FacebookRequestPermissionsM(int, bool)
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157590 push {r3, r4, r5, lr}
 *   @0x157594 mov r5, #0
 *   @0x157598 mov r4, r0
 *   @0x15759c mov r1, r5
 *   @0x1575a0 str r5, [r0, #0xc]
 *   @0x1575a4 ldr r0, [sp, #0x10]
 *   @0x1575a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1575ac mov r1, r5
 *   @0x1575b0 bl 0x15f8b8 <_Z27FacebookRequestPermissionsMib>
 *   @0x1575b4 vmov s15, r0
 *   @0x1575b8 vcvt.f64.s32 d7, s15
 *   @0x1575bc vmov r0, r1, d7
 *   @0x1575c0 vmov r2, s14
 *   @0x1575c4 mov r3, r1
 *   @0x1575c8 stm r4, {r2, r3}
 *   @0x1575cc pop {r3, r4, r5, pc}
 *
 * ══ §310/438 F_YoYo_FacebookRequestPublishPermissions(RValue&, CInstance*, CInstance*, int, RValue*)  0x1575d0  size 64  16 条（0x1575d0..0x157610）
 * @func 0x1575d0 0x157610  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / FacebookRequestPermissionsM(int, bool)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1575d0 push {r4, lr}
 *   @0x1575d4 mov r3, #0
 *   @0x1575d8 mov r1, r3
 *   @0x1575dc str r3, [r0, #0xc]
 *   @0x1575e0 mov r4, r0
 *   @0x1575e4 ldr r0, [sp, #0x8]
 *   @0x1575e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1575ec mov r1, #1
 *   @0x1575f0 bl 0x15f8b8 <_Z27FacebookRequestPermissionsMib>
 *   @0x1575f4 vmov s15, r0
 *   @0x1575f8 vcvt.f64.s32 d7, s15
 *   @0x1575fc vmov r0, r1, d7
 *   @0x157600 vmov r2, s14
 *   @0x157604 mov r3, r1
 *   @0x157608 stm r4, {r2, r3}
 *   @0x15760c pop {r4, pc}
 *
 * ══ §311/438 DisableAdServing(int)  0x15e3e8  size 64  16 条（0x15e3e8..0x15e428）
 * @func 0x15e3e8 0x15e428  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e3e8 push {r4, lr}
 *   @0x15e3ec mov r4, r0
 *   @0x15e3f0 bl 0x290274 <getJNIEnv>
 *   @0x15e3f4 ldr r1, [pc, #0x24]
 *   @0x15e3f8 mov r3, r4
 *   @0x15e3fc ldr r2, [pc, #0x20]
 *   @0x15e400 ldr r1, [pc, r1]
 *   @0x15e404 ldr r2, [pc, r2]
 *   @0x15e408 ldr r1, [r1]
 *   @0x15e40c ldr r2, [r2]
 *   @0x15e410 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e414 mov r0, #0
 *   @0x15e418 mov r1, #0
 *   @0x15e41c pop {r4, pc}
 *   @0x15e420 eoreq pc, r8, r4, lsr #11
 *   @0x15e424 eoreq r1, r9, r12, ror r10
 *
 * ══ §312/438 GR_3D_Transform_Set_Rotation_Axis(float, float, float, float)  0x163858  size 64  16 条（0x163858..0x163898）
 * @func 0x163858 0x163898  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::CreateRotationAxis(yyMatrix*, yyVector3*, float) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163858 push {r4, lr}
 *   @0x16385c sub sp, sp, #80
 *   @0x163860 add r4, sp, #16
 *   @0x163864 str r0, [sp, #0x4]
 *   @0x163868 str r1, [sp, #0x8]
 *   @0x16386c mov r0, r4
 *   @0x163870 add r1, sp, #4
 *   @0x163874 str r2, [sp, #0xc]
 *   @0x163878 eor r2, r3, #-2147483648
 *   @0x16387c bl 0x27a8b8 <_ZN8yyMatrix18CreateRotationAxisEPS_P9yyVector3f>
 *   @0x163880 mov r1, r4
 *   @0x163884 mov r0, #2
 *   @0x163888 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x16388c bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163890 add sp, sp, #80
 *   @0x163894 pop {r4, pc}
 *
 * ══ §313/438 GR_3DM_Clear(int)  0x165210  size 64  16 条（0x165210..0x165250）
 * @func 0x165210 0x165250  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x18×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165210 cmp r0, #0
 *   @0x165214 bxlt lr
 *   @0x165218 ldr r3, [pc, #0x28]
 *   @0x16521c ldr r3, [pc, r3]
 *   @0x165220 ldr r3, [r3]
 *   @0x165224 cmp r0, r3
 *   @0x165228 bxge lr
 *   @0x16522c ldr r3, [pc, #0x18]
 *   @0x165230 ldr r3, [pc, r3]
 *   @0x165234 ldr r3, [r3, #0x4]
 *   @0x165238 ldr r0, [r3, r0, lsl #2]
 *   @0x16523c cmp r0, #0
 *   @0x165240 bxeq lr
 *   @0x165244 b 0x163ce0 <_ZN9C3D_Model5ClearEv>
 *   @0x165248 .word 0x0028aed4
 *   @0x16524c eoreq r10, r8, r4, asr #29
 *
 * ══ §314/438 _DestroyBlankTexture()  0x168be0  size 64  16 条（0x168be0..0x168c20）
 * @func 0x168be0 0x168c20  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Free(int)
 * 字段偏移 top8: 0x2c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168be0 push {r4, lr}
 *   @0x168be4 ldr r4, [pc, #0x2c]
 *   @0x168be8 ldr r4, [pc, r4]
 *   @0x168bec ldr r0, [r4]
 *   @0x168bf0 cmn r0, #1
 *   @0x168bf4 popeq {r4, pc}
 *   @0x168bf8 bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0x168bfc ldr r3, [pc, #0x18]
 *   @0x168c00 mov r2, #0
 *   @0x168c04 mvn r1, #0
 *   @0x168c08 ldr r3, [pc, r3]
 *   @0x168c0c str r1, [r4]
 *   @0x168c10 str r2, [r3]
 *   @0x168c14 pop {r4, pc}
 *   @0x168c18 eoreq r7, r8, r4, asr #10
 *   @0x168c1c eoreq r7, r8, r8, lsr #10
 *
 * ══ §315/438 F_CameraSetDefault(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f544  size 64  16 条（0x16f544..0x16f584）
 * @func 0x16f544 0x16f584  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int)
 * 字段偏移 top8: 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f544 push {r4, lr}
 *   @0x16f548 mov r1, #0
 *   @0x16f54c ldr r0, [sp, #0x8]
 *   @0x16f550 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f554 mov r4, r0
 *   @0x16f558 ldr r0, [pc, #0x1c]
 *   @0x16f55c mov r1, r4
 *   @0x16f560 ldr r0, [pc, r0]
 *   @0x16f564 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f568 cmp r0, #0
 *   @0x16f56c ldrne r3, [pc, #0xc]
 *   @0x16f570 ldrne r3, [pc, r3]
 *   @0x16f574 strne r4, [r3]
 *   @0x16f578 pop {r4, pc}
 *   @0x16f57c eoreq lr, r7, r4, lsl r7
 *   @0x16f580 eoreq r0, r8, r12, ror #25
 *
 * ══ §316/438 GR_Texture_Fill(int, TDWordArray*)  0x173d70  size 64  16 条（0x173d70..0x173db0）
 * @func 0x173d70 0x173db0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::CopySurface(void*, int, int, int, void*)
 * 字段偏移 top8: 0x4×3 / 0x34×1 / 0x-4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173d70 ldr r3, [pc, #0x34]
 *   @0x173d74 ldr r12, [r1, #0x4]
 *   @0x173d78 mov r1, #0
 *   @0x173d7c ldr r3, [pc, r3]
 *   @0x173d80 str lr, [sp, #-0x4]!
 *   @0x173d84 sub sp, sp, #12
 *   @0x173d88 ldr r3, [r3, #0x4]
 *   @0x173d8c ldr r3, [r3, r0, lsl #2]
 *   @0x173d90 ldrsh r2, [r3, #4]
 *   @0x173d94 ldr r0, [r3]
 *   @0x173d98 ldrsh r3, [r3, #6]
 *   @0x173d9c str r12, [sp]
 *   @0x173da0 bl 0x183000 <_ZN8Graphics11CopySurfaceEPviiiS0_>
 *   @0x173da4 add sp, sp, #12
 *   @0x173da8 ldr pc, [sp], #4
 *   @0x173dac eoreq r9, r7, r0, lsr #23
 *
 * ══ §317/438 IO_Key_Clear(int)  0x18bf54  size 64  16 条（0x18bf54..0x18bf94）
 * @func 0x18bf54 0x18bf94  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bf54 cmp r0, #255
 *   @0x18bf58 bxhi lr
 *   @0x18bf5c ldr r12, [pc, #0x24]
 *   @0x18bf60 mov r2, #0
 *   @0x18bf64 ldr r1, [pc, #0x20]
 *   @0x18bf68 ldr r3, [pc, #0x20]
 *   @0x18bf6c ldr r12, [pc, r12]
 *   @0x18bf70 ldr r1, [pc, r1]
 *   @0x18bf74 ldr r3, [pc, r3]
 *   @0x18bf78 strb r2, [r12, r0]
 *   @0x18bf7c strb r2, [r1, r0]
 *   @0x18bf80 strb r2, [r3, r0]
 *   @0x18bf84 bx lr
 *   @0x18bf88 eoreq r4, r6, r4, ror r6
 *   @0x18bf8c eoreq r4, r6, r8, ror r6
 *   @0x18bf90 eoreq r4, r6, r0, ror r6
 *
 * ══ §318/438 PB_DSMapCleanup(HTTP_REQ_CONTEXT*)  0x18d7f4  size 64  16 条（0x18d7f4..0x18d834）
 * @func 0x18d7f4 0x18d834  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DestroyDsMap(int) / PB_DSMapCleanup(HTTP_REQ_CONTEXT*)+0x2c / FreeIBuffer(int) / operator delete(void*)
 * 字段偏移 top8: 0x1c×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d7f4 push {r3, r4, r5, lr}
 *   @0x18d7f8 mov r5, r0
 *   @0x18d7fc ldr r4, [r0, #0x1c]
 *   @0x18d800 cmp r4, #0
 *   @0x18d804 popeq {r3, r4, r5, pc}
 *   @0x18d808 ldr r0, [r4]
 *   @0x18d80c bl 0x205334 <_Z12DestroyDsMapi>
 *   @0x18d810 ldr r0, [r4, #0x8]
 *   @0x18d814 cmp r0, #0
 *   @0x18d818 blt 0x18d820 <_Z15PB_DSMapCleanupP16HTTP_REQ_CONTEXT+0x2c>
 *   @0x18d81c bl 0xc6a88 <_Z11FreeIBufferi>
 *   @0x18d820 mov r0, r4
 *   @0x18d824 bl 0x27d1d0 <_ZdlPv>
 *   @0x18d828 mov r3, #0
 *   @0x18d82c str r3, [r5, #0x1c]
 *   @0x18d830 pop {r3, r4, r5, pc}
 *
 * ══ §319/438 _RefFactory<YYObjectBase*>::Create(YYObjectBase*, int&)  0x199ed0  size 64  16 条（0x199ed0..0x199f10）
 * @func 0x199ed0 0x199f10  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / YYObjectBase::YYObjectBase(int, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199ed0 cmp r0, #0
 *   @0x199ed4 mov r0, #100
 *   @0x199ed8 push {r4, lr}
 *   @0x199edc movne r3, #100
 *   @0x199ee0 moveq r3, #0
 *   @0x199ee4 str r3, [r1]
 *   @0x199ee8 bl 0x27c524 <_Znwj>
 *   @0x199eec ldr r3, [pc, #0x18]
 *   @0x199ef0 mvn r2, #-16777216
 *   @0x199ef4 ldr r3, [pc, r3]
 *   @0x199ef8 ldr r1, [r3]
 *   @0x199efc mov r4, r0
 *   @0x199f00 bl 0x19188c <_ZN12YYObjectBaseC2Eii>
 *   @0x199f04 mov r0, r4
 *   @0x199f08 pop {r4, pc}
 *   @0x199f0c eoreq r3, r5, r0, lsr #28
 *
 * ══ §320/438 ParticleSystem_Emitter_Destroy(int, int)  0x1a38ac  size 64  16 条（0x1a38ac..0x1a38ec）
 * @func 0x1a38ac 0x1a38ec  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Emitter_Exists(int, int)
 * 字段偏移 top8: 0x2×2 / 0x1c×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a38ac push {r3, r4, r5, lr}
 *   @0x1a38b0 mov r5, r0
 *   @0x1a38b4 mov r4, r1
 *   @0x1a38b8 bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii>
 *   @0x1a38bc cmp r0, #0
 *   @0x1a38c0 popeq {r3, r4, r5, pc}
 *   @0x1a38c4 ldr r3, [pc, #0x1c]
 *   @0x1a38c8 mov r2, #0
 *   @0x1a38cc ldr r3, [pc, r3]
 *   @0x1a38d0 ldr r3, [r3, #0x4]
 *   @0x1a38d4 ldr r3, [r3, r5, lsl #2]
 *   @0x1a38d8 ldr r3, [r3, #0x10]
 *   @0x1a38dc ldr r3, [r3, r4, lsl #2]
 *   @0x1a38e0 strb r2, [r3]
 *   @0x1a38e4 pop {r3, r4, r5, pc}
 *   @0x1a38e8 eoreq r12, r4, r12, ror #29
 *
 * ══ §321/438 ParticleSystem_AutoDraw(int)  0x1a5d98  size 64  16 条（0x1a5d98..0x1a5dd8）
 * @func 0x1a5d98 0x1a5dd8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1 / 0x29×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5d98 push {r4, lr}
 *   @0x1a5d9c mov r4, r0
 *   @0x1a5da0 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a5da4 cmp r0, #0
 *   @0x1a5da8 popeq {r4, pc}
 *   @0x1a5dac ldr r3, [pc, #0x20]
 *   @0x1a5db0 ldr r3, [pc, r3]
 *   @0x1a5db4 ldr r3, [r3, #0x4]
 *   @0x1a5db8 ldr r3, [r3, r4, lsl #2]
 *   @0x1a5dbc ldrb r3, [r3, #0x29]
 *   @0x1a5dc0 cmp r3, #0
 *   @0x1a5dc4 popeq {r4, pc}
 *   @0x1a5dc8 mov r0, r4
 *   @0x1a5dcc pop {r4, lr}
 *   @0x1a5dd0 b 0x1a56ac <_Z19ParticleSystem_Drawi>
 *   @0x1a5dd4 eoreq r10, r4, r8, lsl #20
 *
 * ══ §322/438 RomDisk::LoadTexture(int)  0x1a8750  size 64  16 条（0x1a8750..0x1a8790）
 * @func 0x1a8750 0x1a8790  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RomDisk::Load(int) / RomDisk::Size(int) / Graphics::CreateTextureFromFile(unsigned char*, unsigned int, ImageInfo*, eTextureFormat, bool)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8750 push {r4, r5, lr}
 *   @0x1a8754 sub sp, sp, #44
 *   @0x1a8758 mov r5, r0
 *   @0x1a875c bl 0x1a86fc <_ZN7RomDisk4LoadEi>
 *   @0x1a8760 mov r4, r0
 *   @0x1a8764 mov r0, r5
 *   @0x1a8768 bl 0x1a8728 <_ZN7RomDisk4SizeEi>
 *   @0x1a876c mov r3, #1
 *   @0x1a8770 add r2, sp, #12
 *   @0x1a8774 str r3, [sp]
 *   @0x1a8778 mov r3, #0
 *   @0x1a877c mov r1, r0
 *   @0x1a8780 mov r0, r4
 *   @0x1a8784 bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb>
 *   @0x1a8788 add sp, sp, #44
 *   @0x1a878c pop {r4, r5, pc}
 *
 * ══ §323/438 TBitmap::SetDIB(SDIB*, int)  0x1a88fc  size 64  16 条（0x1a88fc..0x1a893c）
 * @func 0x1a88fc 0x1a893c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×2 / 0x14×2 / 0x8×1 / 0x4×1 / 0x1c×1 / 0x20×1 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a88fc ldr r3, [r1, #0x10]
 *   @0x1a8900 mov r12, #7
 *   @0x1a8904 push {r4, r5, r6}
 *   @0x1a8908 ldr r5, [r1, #0x14]
 *   @0x1a890c lsl r4, r3, #2
 *   @0x1a8910 ldr r6, [r1, #0x8]
 *   @0x1a8914 str r1, [r0, #0x4]
 *   @0x1a8918 str r5, [r0, #0x1c]
 *   @0x1a891c add r1, r1, r6
 *   @0x1a8920 str r4, [r0, #0x20]
 *   @0x1a8924 str r2, [r0, #0x10]
 *   @0x1a8928 str r1, [r0, #0xc]
 *   @0x1a892c str r3, [r0, #0x18]
 *   @0x1a8930 str r12, [r0, #0x14]
 *   @0x1a8934 pop {r4, r5, r6}
 *   @0x1a8938 bx lr
 *
 * ══ §324/438 BitmapLoader::~BitmapLoader()  0x1a8acc  size 64  16 条（0x1a8acc..0x1a8b0c）
 * @func 0x1a8acc 0x1a8b0c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8acc ldr r3, [pc, #0x30]
 *   @0x1a8ad0 push {r4, lr}
 *   @0x1a8ad4 ldr r3, [pc, r3]
 *   @0x1a8ad8 mov r4, r0
 *   @0x1a8adc add r3, r3, #8
 *   @0x1a8ae0 ldr r0, [r0, #0x4]
 *   @0x1a8ae4 str r3, [r4]
 *   @0x1a8ae8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a8aec ldr r3, [pc, #0x14]
 *   @0x1a8af0 mov r0, r4
 *   @0x1a8af4 ldr r3, [pc, r3]
 *   @0x1a8af8 add r3, r3, #8
 *   @0x1a8afc str r3, [r4]
 *   @0x1a8b00 pop {r4, pc}
 *   @0x1a8b04 eoreq r7, r4, r0, lsr sp
 *   @0x1a8b08 eoreq r7, r4, r8, lsl #26
 *
 * ══ §325/438 OverwriteGameINIKey(IniFile*, IniFile*, char const*, char const*)  0x1dee44  size 64  16 条（0x1dee44..0x1dee84）
 * @func 0x1dee44 0x1dee84  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetKey(char const*, char const*)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dee44 push {r4, r5, r6, lr}
 *   @0x1dee48 mov r4, r2
 *   @0x1dee4c mov r6, r0
 *   @0x1dee50 mov r2, r3
 *   @0x1dee54 mov r0, r1
 *   @0x1dee58 mov r1, r4
 *   @0x1dee5c mov r5, r3
 *   @0x1dee60 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1dee64 subs r3, r0, #0
 *   @0x1dee68 popeq {r4, r5, r6, pc}
 *   @0x1dee6c mov r0, r6
 *   @0x1dee70 mov r1, r4
 *   @0x1dee74 mov r2, r5
 *   @0x1dee78 ldr r3, [r3, #0x8]
 *   @0x1dee7c pop {r4, r5, r6, lr}
 *   @0x1dee80 b 0x235edc <_ZN7IniFile6SetKeyEPKcS1_S1_>
 *
 * ══ §326/438 CScript::CScript(char const*)  0x1dfc04  size 64  16 条（0x1dfc04..0x1dfc44）
 * @func 0x1dfc04 0x1dfc44  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CScript::Clear()
 * 字段偏移 top8: 0x34×1 / 0x14×1 / 0x4×1 / 0x8×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfc04 ldr r2, [pc, #0x34]
 *   @0x1dfc08 mov r3, #0
 *   @0x1dfc0c push {r4, lr}
 *   @0x1dfc10 ldr r2, [pc, r2]
 *   @0x1dfc14 mov r4, r0
 *   @0x1dfc18 str r1, [r0, #0x14]
 *   @0x1dfc1c str r3, [r0, #0x4]
 *   @0x1dfc20 add r2, r2, #8
 *   @0x1dfc24 str r3, [r0, #0x8]
 *   @0x1dfc28 str r2, [r0]
 *   @0x1dfc2c str r3, [r0, #0x10]
 *   @0x1dfc30 str r3, [r0, #0x18]
 *   @0x1dfc34 bl 0x1dfbb0 <_ZN7CScript5ClearEv>
 *   @0x1dfc38 mov r0, r4
 *   @0x1dfc3c pop {r4, pc}
 *   @0x1dfc40 eoreq r1, r1, r4, lsl r1
 *
 * ══ §327/438 GetShader(int)  0x1e1254  size 64  16 条（0x1e1254..0x1e1294）
 * @func 0x1e1254 0x1e1294  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetShader(int)+0x30
 * 字段偏移 top8: 0x28×1 / 0x18×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1254 cmp r0, #0
 *   @0x1e1258 blt 0x1e1284 <_Z9GetShaderi+0x30>
 *   @0x1e125c ldr r3, [pc, #0x28]
 *   @0x1e1260 ldr r3, [pc, r3]
 *   @0x1e1264 ldr r3, [r3]
 *   @0x1e1268 cmp r0, r3
 *   @0x1e126c bge 0x1e1284 <_Z9GetShaderi+0x30>
 *   @0x1e1270 ldr r3, [pc, #0x18]
 *   @0x1e1274 ldr r3, [pc, r3]
 *   @0x1e1278 ldr r3, [r3]
 *   @0x1e127c ldr r0, [r3, r0, lsl #2]
 *   @0x1e1280 bx lr
 *   @0x1e1284 mov r0, #0
 *   @0x1e1288 bx lr
 *   @0x1e128c eoreq pc, r0, r4, ror #21
 *   @0x1e1290 .word 0x0020fad4
 *
 * ══ §328/438 ClearVertexFormats()  0x1e32a8  size 64  16 条（0x1e32a8..0x1e32e8）
 * @func 0x1e32a8 0x1e32e8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FINALIZE_VertexFormats()
 * 字段偏移 top8: 0x20×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e32a8 push {r3, lr}
 *   @0x1e32ac bl 0x1e3180 <_Z22FINALIZE_VertexFormatsv>
 *   @0x1e32b0 mov r2, #0
 *   @0x1e32b4 ldr r0, [pc, #0x20]
 *   @0x1e32b8 ldr r1, [pc, #0x20]
 *   @0x1e32bc ldr r3, [pc, #0x20]
 *   @0x1e32c0 ldr r0, [pc, r0]
 *   @0x1e32c4 ldr r1, [pc, r1]
 *   @0x1e32c8 ldr r3, [pc, r3]
 *   @0x1e32cc str r2, [r0]
 *   @0x1e32d0 str r2, [r1]
 *   @0x1e32d4 str r2, [r3]
 *   @0x1e32d8 pop {r3, pc}
 *   @0x1e32dc eoreq sp, r0, r0, ror #21
 *   @0x1e32e0 eoreq sp, r0, r12, asr #21
 *   @0x1e32e4 eoreq sp, r0, r12, asr #21
 *
 * ══ §329/438 TimeLine_Exists(int)  0x1f2b18  size 64  16 条（0x1f2b18..0x1f2b58）
 * @func 0x1f2b18 0x1f2b58  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TimeLine_Exists(int)+0x34
 * 字段偏移 top8: 0x2c×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2b18 cmp r0, #0
 *   @0x1f2b1c blt 0x1f2b4c <_Z15TimeLine_Existsi+0x34>
 *   @0x1f2b20 ldr r3, [pc, #0x2c]
 *   @0x1f2b24 add r3, pc, r3
 *   @0x1f2b28 ldr r3, [r3]
 *   @0x1f2b2c ldr r2, [r3]
 *   @0x1f2b30 cmp r0, r2
 *   @0x1f2b34 bge 0x1f2b4c <_Z15TimeLine_Existsi+0x34>
 *   @0x1f2b38 ldr r3, [r3, #0x4]
 *   @0x1f2b3c ldr r0, [r3, r0, lsl #2]
 *   @0x1f2b40 adds r0, r0, #0
 *   @0x1f2b44 movne r0, #1
 *   @0x1f2b48 bx lr
 *   @0x1f2b4c mov r0, #0
 *   @0x1f2b50 bx lr
 *   @0x1f2b54 subseq r0, r6, r8, asr #11
 *
 * ══ §330/438 RVariable::RVariable(char const*)  0x1f5138  size 64  16 条（0x1f5138..0x1f5178）
 * @func 0x1f5138 0x1f5178  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / CalcCRC_string(char const*)
 * 字段偏移 top8: 0x4×1 / 0x18×1 / 0x1c×1 / 0x24×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5138 push {r3, r4, r5, lr}
 *   @0x1f513c mov r4, r0
 *   @0x1f5140 mov r3, #0
 *   @0x1f5144 mov r5, r1
 *   @0x1f5148 str r3, [r4]
 *   @0x1f514c add r0, r0, #8
 *   @0x1f5150 str r3, [r4, #0x4]
 *   @0x1f5154 str r3, [r4, #0x18]
 *   @0x1f5158 str r3, [r4, #0x1c]
 *   @0x1f515c str r3, [r4, #0x24]
 *   @0x1f5160 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x1f5164 mov r0, r5
 *   @0x1f5168 bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x1f516c str r0, [r4, #0x28]
 *   @0x1f5170 mov r0, r4
 *   @0x1f5174 pop {r3, r4, r5, pc}
 *
 * ══ §331/438 GV_ArgumentRelative(CInstance*, int, RValue*)  0x1f79ac  size 64  16 条（0x1f79ac..0x1f79ec）
 * @func 0x1f79ac 0x1f79ec  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f79ac ldr r3, [pc, #0x34]
 *   @0x1f79b0 mov r1, #0
 *   @0x1f79b4 push {r4, r5}
 *   @0x1f79b8 ldr r3, [pc, r3]
 *   @0x1f79bc str r1, [r2, #0xc]
 *   @0x1f79c0 mov r0, #1
 *   @0x1f79c4 ldrb r4, [r3]
 *   @0x1f79c8 vmov s15, r4
 *   @0x1f79cc vcvt.f64.s32 d7, s15
 *   @0x1f79d0 vmov r4, r5, d7
 *   @0x1f79d4 vmov r1, s14
 *   @0x1f79d8 mov r3, r5
 *   @0x1f79dc pop {r4, r5}
 *   @0x1f79e0 stm r2, {r1, r3}
 *   @0x1f79e4 bx lr
 *   @0x1f79e8 andseq r6, pc, r4, lsl #3
 *
 * ══ §332/438 GV_Room(CInstance*, int, RValue*)  0x1f79ec  size 64  16 条（0x1f79ec..0x1f7a2c）
 * @func 0x1f79ec 0x1f7a2c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f79ec ldr r3, [pc, #0x34]
 *   @0x1f79f0 mov r1, #0
 *   @0x1f79f4 push {r4, r5}
 *   @0x1f79f8 ldr r3, [pc, r3]
 *   @0x1f79fc str r1, [r2, #0xc]
 *   @0x1f7a00 mov r0, #1
 *   @0x1f7a04 ldr r4, [r3]
 *   @0x1f7a08 vmov s15, r4
 *   @0x1f7a0c vcvt.f64.s32 d7, s15
 *   @0x1f7a10 vmov r4, r5, d7
 *   @0x1f7a14 vmov r1, s14
 *   @0x1f7a18 mov r3, r5
 *   @0x1f7a1c pop {r4, r5}
 *   @0x1f7a20 stm r2, {r1, r3}
 *   @0x1f7a24 bx lr
 *   @0x1f7a28 ldrsbeq r7, [pc], -r12
 *
 * ══ §333/438 GV_TransitionKind(CInstance*, int, RValue*)  0x1f7a2c  size 64  16 条（0x1f7a2c..0x1f7a6c）
 * @func 0x1f7a2c 0x1f7a6c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7a2c ldr r3, [pc, #0x34]
 *   @0x1f7a30 mov r1, #0
 *   @0x1f7a34 push {r4, r5}
 *   @0x1f7a38 ldr r3, [pc, r3]
 *   @0x1f7a3c str r1, [r2, #0xc]
 *   @0x1f7a40 mov r0, #1
 *   @0x1f7a44 ldr r4, [r3]
 *   @0x1f7a48 vmov s15, r4
 *   @0x1f7a4c vcvt.f64.s32 d7, s15
 *   @0x1f7a50 vmov r4, r5, d7
 *   @0x1f7a54 vmov r1, s14
 *   @0x1f7a58 mov r3, r5
 *   @0x1f7a5c pop {r4, r5}
 *   @0x1f7a60 stm r2, {r1, r3}
 *   @0x1f7a64 bx lr
 *   @0x1f7a68 andseq r6, pc, r0, ror r6
 *
 * ══ §334/438 GV_Score(CInstance*, int, RValue*)  0x1f7a84  size 64  16 条（0x1f7a84..0x1f7ac4）
 * @func 0x1f7a84 0x1f7ac4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7a84 ldr r3, [pc, #0x34]
 *   @0x1f7a88 mov r1, #0
 *   @0x1f7a8c push {r4, r5}
 *   @0x1f7a90 ldr r3, [pc, r3]
 *   @0x1f7a94 str r1, [r2, #0xc]
 *   @0x1f7a98 mov r0, #1
 *   @0x1f7a9c ldr r4, [r3]
 *   @0x1f7aa0 vmov s15, r4
 *   @0x1f7aa4 vcvt.f64.s32 d7, s15
 *   @0x1f7aa8 vmov r4, r5, d7
 *   @0x1f7aac vmov r1, s14
 *   @0x1f7ab0 mov r3, r5
 *   @0x1f7ab4 pop {r4, r5}
 *   @0x1f7ab8 stm r2, {r1, r3}
 *   @0x1f7abc bx lr
 *   @0x1f7ac0 ldrsheq r6, [pc], -r4
 *
 * ══ §335/438 GV_Lives(CInstance*, int, RValue*)  0x1f7ac4  size 64  16 条（0x1f7ac4..0x1f7b04）
 * @func 0x1f7ac4 0x1f7b04  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7ac4 ldr r3, [pc, #0x34]
 *   @0x1f7ac8 mov r1, #0
 *   @0x1f7acc push {r4, r5}
 *   @0x1f7ad0 ldr r3, [pc, r3]
 *   @0x1f7ad4 str r1, [r2, #0xc]
 *   @0x1f7ad8 mov r0, #1
 *   @0x1f7adc ldr r4, [r3]
 *   @0x1f7ae0 vmov s15, r4
 *   @0x1f7ae4 vcvt.f64.s32 d7, s15
 *   @0x1f7ae8 vmov r4, r5, d7
 *   @0x1f7aec vmov r1, s14
 *   @0x1f7af0 mov r3, r5
 *   @0x1f7af4 pop {r4, r5}
 *   @0x1f7af8 stm r2, {r1, r3}
 *   @0x1f7afc bx lr
 *   @0x1f7b00 andseq r7, pc, r0, lsl #18
 *
 * ══ §336/438 GV_GameId(CInstance*, int, RValue*)  0x1f7b30  size 64  16 条（0x1f7b30..0x1f7b70）
 * @func 0x1f7b30 0x1f7b70  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7b30 ldr r3, [pc, #0x34]
 *   @0x1f7b34 mov r1, #0
 *   @0x1f7b38 push {r4, r5}
 *   @0x1f7b3c ldr r3, [pc, r3]
 *   @0x1f7b40 str r1, [r2, #0xc]
 *   @0x1f7b44 mov r0, #1
 *   @0x1f7b48 ldr r4, [r3]
 *   @0x1f7b4c vmov s15, r4
 *   @0x1f7b50 vcvt.f64.s32 d7, s15
 *   @0x1f7b54 vmov r4, r5, d7
 *   @0x1f7b58 vmov r1, s14
 *   @0x1f7b5c mov r3, r5
 *   @0x1f7b60 pop {r4, r5}
 *   @0x1f7b64 stm r2, {r1, r3}
 *   @0x1f7b68 bx lr
 *   @0x1f7b6c ldrsbeq r8, [pc], -r8
 *
 * ══ §337/438 GV_ViewCurrent(CInstance*, int, RValue*)  0x1f8174  size 64  16 条（0x1f8174..0x1f81b4）
 * @func 0x1f8174 0x1f81b4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8174 ldr r3, [pc, #0x34]
 *   @0x1f8178 mov r1, #0
 *   @0x1f817c push {r4, r5}
 *   @0x1f8180 ldr r3, [pc, r3]
 *   @0x1f8184 str r1, [r2, #0xc]
 *   @0x1f8188 mov r0, #1
 *   @0x1f818c ldr r4, [r3]
 *   @0x1f8190 vmov s15, r4
 *   @0x1f8194 vcvt.f64.s32 d7, s15
 *   @0x1f8198 vmov r4, r5, d7
 *   @0x1f819c vmov r1, s14
 *   @0x1f81a0 mov r3, r5
 *   @0x1f81a4 pop {r4, r5}
 *   @0x1f81a8 stm r2, {r1, r3}
 *   @0x1f81ac bx lr
 *   @0x1f81b0 andseq r6, pc, r0, asr r4
 *
 * ══ §338/438 GV_ShowScore(CInstance*, int, RValue*)  0x1f868c  size 64  16 条（0x1f868c..0x1f86cc）
 * @func 0x1f868c 0x1f86cc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f868c ldr r3, [pc, #0x34]
 *   @0x1f8690 mov r1, #0
 *   @0x1f8694 push {r4, r5}
 *   @0x1f8698 ldr r3, [pc, r3]
 *   @0x1f869c str r1, [r2, #0xc]
 *   @0x1f86a0 mov r0, #1
 *   @0x1f86a4 ldrb r4, [r3]
 *   @0x1f86a8 vmov s15, r4
 *   @0x1f86ac vcvt.f64.u32 d7, s15
 *   @0x1f86b0 vmov r4, r5, d7
 *   @0x1f86b4 vmov r1, s14
 *   @0x1f86b8 mov r3, r5
 *   @0x1f86bc pop {r4, r5}
 *   @0x1f86c0 stm r2, {r1, r3}
 *   @0x1f86c4 bx lr
 *   @0x1f86c8 andseq r6, pc, r4, asr pc
 *
 * ══ §339/438 GV_ShowLives(CInstance*, int, RValue*)  0x1f86cc  size 64  16 条（0x1f86cc..0x1f870c）
 * @func 0x1f86cc 0x1f870c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f86cc ldr r3, [pc, #0x34]
 *   @0x1f86d0 mov r1, #0
 *   @0x1f86d4 push {r4, r5}
 *   @0x1f86d8 ldr r3, [pc, r3]
 *   @0x1f86dc str r1, [r2, #0xc]
 *   @0x1f86e0 mov r0, #1
 *   @0x1f86e4 ldrb r4, [r3]
 *   @0x1f86e8 vmov s15, r4
 *   @0x1f86ec vcvt.f64.u32 d7, s15
 *   @0x1f86f0 vmov r4, r5, d7
 *   @0x1f86f4 vmov r1, s14
 *   @0x1f86f8 mov r3, r5
 *   @0x1f86fc pop {r4, r5}
 *   @0x1f8700 stm r2, {r1, r3}
 *   @0x1f8704 bx lr
 *   @0x1f8708 andseq r6, pc, r12, lsl pc
 *
 * ══ §340/438 GV_ShowHealth(CInstance*, int, RValue*)  0x1f870c  size 64  16 条（0x1f870c..0x1f874c）
 * @func 0x1f870c 0x1f874c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f870c ldr r3, [pc, #0x34]
 *   @0x1f8710 mov r1, #0
 *   @0x1f8714 push {r4, r5}
 *   @0x1f8718 ldr r3, [pc, r3]
 *   @0x1f871c str r1, [r2, #0xc]
 *   @0x1f8720 mov r0, #1
 *   @0x1f8724 ldrb r4, [r3]
 *   @0x1f8728 vmov s15, r4
 *   @0x1f872c vcvt.f64.u32 d7, s15
 *   @0x1f8730 vmov r4, r5, d7
 *   @0x1f8734 vmov r1, s14
 *   @0x1f8738 mov r3, r5
 *   @0x1f873c pop {r4, r5}
 *   @0x1f8740 stm r2, {r1, r3}
 *   @0x1f8744 bx lr
 *   @0x1f8748 andseq r6, pc, r4, ror #29
 *
 * ══ §341/438 GV_CursorSprite(CInstance*, int, RValue*)  0x1f874c  size 64  16 条（0x1f874c..0x1f878c）
 * @func 0x1f874c 0x1f878c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f874c ldr r3, [pc, #0x34]
 *   @0x1f8750 mov r1, #0
 *   @0x1f8754 push {r4, r5}
 *   @0x1f8758 ldr r3, [pc, r3]
 *   @0x1f875c str r1, [r2, #0xc]
 *   @0x1f8760 mov r0, #1
 *   @0x1f8764 ldr r4, [r3]
 *   @0x1f8768 vmov s15, r4
 *   @0x1f876c vcvt.f64.s32 d7, s15
 *   @0x1f8770 vmov r4, r5, d7
 *   @0x1f8774 vmov r1, s14
 *   @0x1f8778 mov r3, r5
 *   @0x1f877c pop {r4, r5}
 *   @0x1f8780 stm r2, {r1, r3}
 *   @0x1f8784 bx lr
 *   @0x1f8788 mulseq pc, r0, r12
 *
 * ══ §342/438 GV_FontTexturePageSize(CInstance*, int, RValue*)  0x1f878c  size 64  16 条（0x1f878c..0x1f87cc）
 * @func 0x1f878c 0x1f87cc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f878c ldr r3, [pc, #0x34]
 *   @0x1f8790 mov r1, #10
 *   @0x1f8794 push {r4, r5}
 *   @0x1f8798 ldr r3, [pc, r3]
 *   @0x1f879c str r1, [r2, #0xc]
 *   @0x1f87a0 mov r0, #1
 *   @0x1f87a4 ldr r4, [r3]
 *   @0x1f87a8 vmov s15, r4
 *   @0x1f87ac vcvt.f64.s32 d7, s15
 *   @0x1f87b0 vmov r4, r5, d7
 *   @0x1f87b4 vmov r1, s14
 *   @0x1f87b8 mov r3, r5
 *   @0x1f87bc pop {r4, r5}
 *   @0x1f87c0 stm r2, {r1, r3}
 *   @0x1f87c4 bx lr
 *   @0x1f87c8 ldrheq r5, [pc], -r12
 *
 * ══ §343/438 GV_Fps(CInstance*, int, RValue*)  0x1f87cc  size 64  16 条（0x1f87cc..0x1f880c）
 * @func 0x1f87cc 0x1f880c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f87cc ldr r3, [pc, #0x34]
 *   @0x1f87d0 mov r1, #0
 *   @0x1f87d4 push {r4, r5}
 *   @0x1f87d8 ldr r3, [pc, r3]
 *   @0x1f87dc str r1, [r2, #0xc]
 *   @0x1f87e0 mov r0, #1
 *   @0x1f87e4 ldr r4, [r3]
 *   @0x1f87e8 vmov s15, r4
 *   @0x1f87ec vcvt.f64.s32 d7, s15
 *   @0x1f87f0 vmov r4, r5, d7
 *   @0x1f87f4 vmov r1, s14
 *   @0x1f87f8 mov r3, r5
 *   @0x1f87fc pop {r4, r5}
 *   @0x1f8800 stm r2, {r1, r3}
 *   @0x1f8804 bx lr
 *   @0x1f8808 mulseq pc, r4, pc
 *
 * ══ §344/438 GV_EventType(CInstance*, int, RValue*)  0x1f88d4  size 64  16 条（0x1f88d4..0x1f8914）
 * @func 0x1f88d4 0x1f8914  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f88d4 ldr r3, [pc, #0x34]
 *   @0x1f88d8 mov r1, #0
 *   @0x1f88dc push {r4, r5}
 *   @0x1f88e0 ldr r3, [pc, r3]
 *   @0x1f88e4 str r1, [r2, #0xc]
 *   @0x1f88e8 mov r0, #1
 *   @0x1f88ec ldr r4, [r3]
 *   @0x1f88f0 vmov s15, r4
 *   @0x1f88f4 vcvt.f64.s32 d7, s15
 *   @0x1f88f8 vmov r4, r5, d7
 *   @0x1f88fc vmov r1, s14
 *   @0x1f8900 mov r3, r5
 *   @0x1f8904 pop {r4, r5}
 *   @0x1f8908 stm r2, {r1, r3}
 *   @0x1f890c bx lr
 *   @0x1f8910 ldrsbeq r5, [pc], -r0
 *
 * ══ §345/438 GV_EventNumber(CInstance*, int, RValue*)  0x1f8914  size 64  16 条（0x1f8914..0x1f8954）
 * @func 0x1f8914 0x1f8954  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8914 ldr r3, [pc, #0x34]
 *   @0x1f8918 mov r1, #0
 *   @0x1f891c push {r4, r5}
 *   @0x1f8920 ldr r3, [pc, r3]
 *   @0x1f8924 str r1, [r2, #0xc]
 *   @0x1f8928 mov r0, #1
 *   @0x1f892c ldr r4, [r3]
 *   @0x1f8930 vmov s15, r4
 *   @0x1f8934 vcvt.f64.s32 d7, s15
 *   @0x1f8938 vmov r4, r5, d7
 *   @0x1f893c vmov r1, s14
 *   @0x1f8940 mov r3, r5
 *   @0x1f8944 pop {r4, r5}
 *   @0x1f8948 stm r2, {r1, r3}
 *   @0x1f894c bx lr
 *   @0x1f8950 mulseq pc, r4, r4
 *
 * ══ §346/438 GV_EventObject(CInstance*, int, RValue*)  0x1f8954  size 64  16 条（0x1f8954..0x1f8994）
 * @func 0x1f8954 0x1f8994  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8954 ldr r3, [pc, #0x34]
 *   @0x1f8958 mov r1, #0
 *   @0x1f895c push {r4, r5}
 *   @0x1f8960 ldr r3, [pc, r3]
 *   @0x1f8964 str r1, [r2, #0xc]
 *   @0x1f8968 mov r0, #1
 *   @0x1f896c ldr r4, [r3]
 *   @0x1f8970 vmov s15, r4
 *   @0x1f8974 vcvt.f64.s32 d7, s15
 *   @0x1f8978 vmov r4, r5, d7
 *   @0x1f897c vmov r1, s14
 *   @0x1f8980 mov r3, r5
 *   @0x1f8984 pop {r4, r5}
 *   @0x1f8988 stm r2, {r1, r3}
 *   @0x1f898c bx lr
 *   @0x1f8990 andseq r5, pc, r8, asr r4
 *
 * ══ §347/438 GV_EventAction(CInstance*, int, RValue*)  0x1f8994  size 64  16 条（0x1f8994..0x1f89d4）
 * @func 0x1f8994 0x1f89d4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8994 ldr r3, [pc, #0x34]
 *   @0x1f8998 mov r1, #0
 *   @0x1f899c push {r4, r5}
 *   @0x1f89a0 ldr r3, [pc, r3]
 *   @0x1f89a4 str r1, [r2, #0xc]
 *   @0x1f89a8 mov r0, #1
 *   @0x1f89ac ldr r4, [r3]
 *   @0x1f89b0 vmov s15, r4
 *   @0x1f89b4 vcvt.f64.s32 d7, s15
 *   @0x1f89b8 vmov r4, r5, d7
 *   @0x1f89bc vmov r1, s14
 *   @0x1f89c0 mov r3, r5
 *   @0x1f89c4 pop {r4, r5}
 *   @0x1f89c8 stm r2, {r1, r3}
 *   @0x1f89cc bx lr
 *   @0x1f89d0 andseq r5, pc, r12, lsl #8
 *
 * ══ §348/438 GV_ErrorOccurred(CInstance*, int, RValue*)  0x1f89ec  size 64  16 条（0x1f89ec..0x1f8a2c）
 * @func 0x1f89ec 0x1f8a2c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f89ec ldr r3, [pc, #0x34]
 *   @0x1f89f0 mov r1, #0
 *   @0x1f89f4 push {r4, r5}
 *   @0x1f89f8 ldr r3, [pc, r3]
 *   @0x1f89fc str r1, [r2, #0xc]
 *   @0x1f8a00 mov r0, #1
 *   @0x1f8a04 ldrb r4, [r3]
 *   @0x1f8a08 vmov s15, r4
 *   @0x1f8a0c vcvt.f64.u32 d7, s15
 *   @0x1f8a10 vmov r4, r5, d7
 *   @0x1f8a14 vmov r1, s14
 *   @0x1f8a18 mov r3, r5
 *   @0x1f8a1c pop {r4, r5}
 *   @0x1f8a20 stm r2, {r1, r3}
 *   @0x1f8a24 bx lr
 *   @0x1f8a28 andseq r5, pc, r8, lsr #7
 *
 * ══ §349/438 SV_ErrorOccurred(CInstance*, int, RValue*)  0x1f8a2c  size 64  16 条（0x1f8a2c..0x1f8a6c）
 * @func 0x1f8a2c 0x1f8a6c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8a2c vmov.f64 d7, #5.000000e-01
 *   @0x1f8a30 ldr r3, [pc, #0x30]
 *   @0x1f8a34 push {r4, r5}
 *   @0x1f8a38 ldr r3, [pc, r3]
 *   @0x1f8a3c ldr r4, [r2]
 *   @0x1f8a40 mov r0, #1
 *   @0x1f8a44 ldr r5, [r2, #0x4]
 *   @0x1f8a48 vmov d6, r4, r5
 *   @0x1f8a4c pop {r4, r5}
 *   @0x1f8a50 vcmpe.f64 d6, d7
 *   @0x1f8a54 vmrs APSR_nzcv, fpscr
 *   @0x1f8a58 movlt r2, #0
 *   @0x1f8a5c movge r2, #1
 *   @0x1f8a60 strb r2, [r3]
 *   @0x1f8a64 bx lr
 *   @0x1f8a68 andseq r5, pc, r8, ror #6
 *
 * ══ §350/438 GV_GamemakerRegistered(CInstance*, int, RValue*)  0x1f8a98  size 64  16 条（0x1f8a98..0x1f8ad8）
 * @func 0x1f8a98 0x1f8ad8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8a98 ldr r3, [pc, #0x34]
 *   @0x1f8a9c mov r1, #0
 *   @0x1f8aa0 push {r4, r5}
 *   @0x1f8aa4 ldr r3, [pc, r3]
 *   @0x1f8aa8 str r1, [r2, #0xc]
 *   @0x1f8aac mov r0, #1
 *   @0x1f8ab0 ldrb r4, [r3]
 *   @0x1f8ab4 vmov s15, r4
 *   @0x1f8ab8 vcvt.f64.u32 d7, s15
 *   @0x1f8abc vmov r4, r5, d7
 *   @0x1f8ac0 vmov r1, s14
 *   @0x1f8ac4 mov r3, r5
 *   @0x1f8ac8 pop {r4, r5}
 *   @0x1f8acc stm r2, {r1, r3}
 *   @0x1f8ad0 bx lr
 *   @0x1f8ad4 andseq r8, pc, r8, lsl r2
 *
 * ══ §351/438 GV_ApplicationSurface(CInstance*, int, RValue*)  0x1f8ad8  size 64  16 条（0x1f8ad8..0x1f8b18）
 * @func 0x1f8ad8 0x1f8b18  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8ad8 ldr r3, [pc, #0x34]
 *   @0x1f8adc mov r1, #0
 *   @0x1f8ae0 push {r4, r5}
 *   @0x1f8ae4 ldr r3, [pc, r3]
 *   @0x1f8ae8 str r1, [r2, #0xc]
 *   @0x1f8aec mov r0, #1
 *   @0x1f8af0 ldr r4, [r3]
 *   @0x1f8af4 vmov s15, r4
 *   @0x1f8af8 vcvt.f64.s32 d7, s15
 *   @0x1f8afc vmov r4, r5, d7
 *   @0x1f8b00 vmov r1, s14
 *   @0x1f8b04 mov r3, r5
 *   @0x1f8b08 pop {r4, r5}
 *   @0x1f8b0c stm r2, {r1, r3}
 *   @0x1f8b10 bx lr
 *   @0x1f8b14 ldrsheq r5, [pc], -r4
 *
 * ══ §352/438 GV_ImageSingle(CInstance*, int, RValue*)  0x1f8fc8  size 64  16 条（0x1f8fc8..0x1f9008）
 * @func 0x1f8fc8 0x1f9008  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8fc8 vldr s15, [r0, #148]
 *   @0x1f8fcc vcmp.f32 s15, #0
 *   @0x1f8fd0 mov r3, #0
 *   @0x1f8fd4 str r3, [r2, #0xc]
 *   @0x1f8fd8 vmrs APSR_nzcv, fpscr
 *   @0x1f8fdc vldreq s15, [r0, #144]
 *   @0x1f8fe0 vcvteq.f64.f32 d6, s15
 *   @0x1f8fe4 strne r3, [r2]
 *   @0x1f8fe8 movne r3, #0
 *   @0x1f8fec movtne r3, #0xbff0
 *   @0x1f8ff0 strne r3, [r2, #0x4]
 *   @0x1f8ff4 vmoveq r0, r1, d6
 *   @0x1f8ff8 moveq r3, r1
 *   @0x1f8ffc stmeq r2, {r0, r3}
 *   @0x1f9000 mov r0, #1
 *   @0x1f9004 bx lr
 *
 * ══ §353/438 GV_AsyncLoad(CInstance*, int, RValue*)  0x1f93b4  size 64  16 条（0x1f93b4..0x1f93f4）
 * @func 0x1f93b4 0x1f93f4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f93b4 ldr r3, [pc, #0x34]
 *   @0x1f93b8 mov r1, #0
 *   @0x1f93bc push {r4, r5}
 *   @0x1f93c0 ldr r3, [pc, r3]
 *   @0x1f93c4 str r1, [r2, #0xc]
 *   @0x1f93c8 mov r0, #1
 *   @0x1f93cc ldr r4, [r3]
 *   @0x1f93d0 vmov s15, r4
 *   @0x1f93d4 vcvt.f64.s32 d7, s15
 *   @0x1f93d8 vmov r4, r5, d7
 *   @0x1f93dc vmov r1, s14
 *   @0x1f93e0 mov r3, r5
 *   @0x1f93e4 pop {r4, r5}
 *   @0x1f93e8 stm r2, {r1, r3}
 *   @0x1f93ec bx lr
 *   @0x1f93f0 andseq r6, pc, r8, asr r7
 *
 * ══ §354/438 GV_EventData(CInstance*, int, RValue*)  0x1f93f4  size 64  16 条（0x1f93f4..0x1f9434）
 * @func 0x1f93f4 0x1f9434  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f93f4 ldr r3, [pc, #0x34]
 *   @0x1f93f8 mov r1, #0
 *   @0x1f93fc push {r4, r5}
 *   @0x1f9400 ldr r3, [pc, r3]
 *   @0x1f9404 str r1, [r2, #0xc]
 *   @0x1f9408 mov r0, #1
 *   @0x1f940c ldr r4, [r3]
 *   @0x1f9410 vmov s15, r4
 *   @0x1f9414 vcvt.f64.s32 d7, s15
 *   @0x1f9418 vmov r4, r5, d7
 *   @0x1f941c vmov r1, s14
 *   @0x1f9420 mov r3, r5
 *   @0x1f9424 pop {r4, r5}
 *   @0x1f9428 stm r2, {r1, r3}
 *   @0x1f942c bx lr
 *   @0x1f9430 andseq r4, pc, r8, lsr r5
 *
 * ══ §355/438 GV_IAPEventData(CInstance*, int, RValue*)  0x1f9434  size 64  16 条（0x1f9434..0x1f9474）
 * @func 0x1f9434 0x1f9474  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9434 ldr r3, [pc, #0x34]
 *   @0x1f9438 mov r1, #0
 *   @0x1f943c push {r4, r5}
 *   @0x1f9440 ldr r3, [pc, r3]
 *   @0x1f9444 str r1, [r2, #0xc]
 *   @0x1f9448 mov r0, #1
 *   @0x1f944c ldr r4, [r3]
 *   @0x1f9450 vmov s15, r4
 *   @0x1f9454 vcvt.f64.s32 d7, s15
 *   @0x1f9458 vmov r4, r5, d7
 *   @0x1f945c vmov r1, s14
 *   @0x1f9460 mov r3, r5
 *   @0x1f9464 pop {r4, r5}
 *   @0x1f9468 stm r2, {r1, r3}
 *   @0x1f946c bx lr
 *   @0x1f9470 andseq r6, pc, r0, asr #13
 *
 * ══ §356/438 GV_PhysicsMass(CInstance*, int, RValue*)  0x1f9474  size 64  16 条（0x1f9474..0x1f94b4）
 * @func 0x1f9474 0x1f94b4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9474 ldr r0, [r0, #0x84]
 *   @0x1f9478 push {r4, r5}
 *   @0x1f947c cmp r0, #0
 *   @0x1f9480 beq 0x1f94ac <_Z14GV_PhysicsMassP9CInstanceiP6RValue+0x38>
 *   @0x1f9484 ldr r3, [r0]
 *   @0x1f9488 vldr s15, [r3, #132]
 *   @0x1f948c vcvt.f64.f32 d6, s15
 *   @0x1f9490 mov r0, #1
 *   @0x1f9494 mov r3, #0
 *   @0x1f9498 str r3, [r2, #0xc]
 *   @0x1f949c vmov r4, r5, d6
 *   @0x1f94a0 vmov r1, s12
 *   @0x1f94a4 mov r3, r5
 *   @0x1f94a8 stm r2, {r1, r3}
 *   @0x1f94ac pop {r4, r5}
 *   @0x1f94b0 bx lr
 *
 * ══ §357/438 GV_PhysicsAngularDamping(CInstance*, int, RValue*)  0x1f974c  size 64  16 条（0x1f974c..0x1f978c）
 * @func 0x1f974c 0x1f978c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f974c ldr r0, [r0, #0x84]
 *   @0x1f9750 push {r4, r5}
 *   @0x1f9754 cmp r0, #0
 *   @0x1f9758 beq 0x1f9784 <_Z24GV_PhysicsAngularDampingP9CInstanceiP6RValue+0x38>
 *   @0x1f975c ldr r3, [r0]
 *   @0x1f9760 vldr s15, [r3, #152]
 *   @0x1f9764 vcvt.f64.f32 d6, s15
 *   @0x1f9768 mov r0, #1
 *   @0x1f976c mov r3, #0
 *   @0x1f9770 str r3, [r2, #0xc]
 *   @0x1f9774 vmov r4, r5, d6
 *   @0x1f9778 vmov r1, s12
 *   @0x1f977c mov r3, r5
 *   @0x1f9780 stm r2, {r1, r3}
 *   @0x1f9784 pop {r4, r5}
 *   @0x1f9788 bx lr
 *
 * ══ §358/438 GV_PhysicsLinearDamping(CInstance*, int, RValue*)  0x1f978c  size 64  16 条（0x1f978c..0x1f97cc）
 * @func 0x1f978c 0x1f97cc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f978c ldr r0, [r0, #0x84]
 *   @0x1f9790 push {r4, r5}
 *   @0x1f9794 cmp r0, #0
 *   @0x1f9798 beq 0x1f97c4 <_Z23GV_PhysicsLinearDampingP9CInstanceiP6RValue+0x38>
 *   @0x1f979c ldr r3, [r0]
 *   @0x1f97a0 vldr s15, [r3, #148]
 *   @0x1f97a4 vcvt.f64.f32 d6, s15
 *   @0x1f97a8 mov r0, #1
 *   @0x1f97ac mov r3, #0
 *   @0x1f97b0 str r3, [r2, #0xc]
 *   @0x1f97b4 vmov r4, r5, d6
 *   @0x1f97b8 vmov r1, s12
 *   @0x1f97bc mov r3, r5
 *   @0x1f97c0 stm r2, {r1, r3}
 *   @0x1f97c4 pop {r4, r5}
 *   @0x1f97c8 bx lr
 *
 * ══ §359/438 GV_GetDisplayAA(CInstance*, int, RValue*)  0x1f9a88  size 64  16 条（0x1f9a88..0x1f9ac8）
 * @func 0x1f9a88 0x1f9ac8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9a88 ldr r3, [pc, #0x34]
 *   @0x1f9a8c mov r1, #0
 *   @0x1f9a90 push {r4, r5}
 *   @0x1f9a94 ldr r3, [pc, r3]
 *   @0x1f9a98 str r1, [r2, #0xc]
 *   @0x1f9a9c mov r0, #1
 *   @0x1f9aa0 ldr r4, [r3]
 *   @0x1f9aa4 vmov s15, r4
 *   @0x1f9aa8 vcvt.f64.s32 d7, s15
 *   @0x1f9aac vmov r4, r5, d7
 *   @0x1f9ab0 vmov r1, s14
 *   @0x1f9ab4 mov r3, r5
 *   @0x1f9ab8 pop {r4, r5}
 *   @0x1f9abc stm r2, {r1, r3}
 *   @0x1f9ac0 bx lr
 *   @0x1f9ac4 andseq r7, pc, r8, lsr #7
 *
 * ══ §360/438 GV_CurrentYear(CInstance*, int, RValue*)  0x1fa2b0  size 64  16 条（0x1fa2b0..0x1fa2f0）
 * @func 0x1fa2b0 0x1fa2f0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CurrentTimeToTM()
 * 字段偏移 top8: 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa2b0 push {r4, r5, r6, lr}
 *   @0x1fa2b4 mov r3, #0
 *   @0x1fa2b8 str r3, [r2, #0xc]
 *   @0x1fa2bc mov r6, r2
 *   @0x1fa2c0 bl 0x117a10 <_Z15CurrentTimeToTMv>
 *   @0x1fa2c4 ldr r4, [r0, #0x14]
 *   @0x1fa2c8 mov r0, #1
 *   @0x1fa2cc add r4, r4, #1888
 *   @0x1fa2d0 add r4, r4, #12
 *   @0x1fa2d4 vmov s15, r4
 *   @0x1fa2d8 vcvt.f64.s32 d7, s15
 *   @0x1fa2dc vmov r4, r5, d7
 *   @0x1fa2e0 vmov r2, s14
 *   @0x1fa2e4 mov r3, r5
 *   @0x1fa2e8 stm r6, {r2, r3}
 *   @0x1fa2ec pop {r4, r5, r6, pc}
 *
 * ══ §361/438 CEmitter::CEmitter()  0x2157c8  size 64  16 条（0x2157c8..0x215808）
 * @func 0x2157c8 0x215808  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CEmitter::Reset()
 * 字段偏移 top8: 0x34×1 / 0x38×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2157c8 push {r4, lr}
 *   @0x2157cc mov r2, #0
 *   @0x2157d0 mov r4, r0
 *   @0x2157d4 str r2, [r0, #0x34]
 *   @0x2157d8 str r2, [r0, #0x38]
 *   @0x2157dc movw r3, #0x4f80
 *   @0x2157e0 movt r3, #0xc7c3
 *   @0x2157e4 str r3, [r0]
 *   @0x2157e8 str r3, [r0, #0x4]
 *   @0x2157ec str r3, [r0, #0x8]
 *   @0x2157f0 str r3, [r0, #0xc]
 *   @0x2157f4 str r3, [r0, #0x10]
 *   @0x2157f8 str r3, [r0, #0x14]
 *   @0x2157fc bl 0x215774 <_ZN8CEmitter5ResetEv>
 *   @0x215800 mov r0, r4
 *   @0x215804 pop {r4, pc}
 *
 * ══ §362/438 Sound_Data(int)  0x21fcd4  size 64  16 条（0x21fcd4..0x21fd14）
 * @func 0x21fcd4 0x21fd14  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Data(int)+0x34
 * 字段偏移 top8: 0x2c×1 / 0x10×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21fcd4 cmp r0, #0
 *   @0x21fcd8 blt 0x21fd08 <_Z10Sound_Datai+0x34>
 *   @0x21fcdc ldr r3, [pc, #0x2c]
 *   @0x21fce0 add r3, pc, r3
 *   @0x21fce4 ldr r2, [r3, #0x10]
 *   @0x21fce8 cmp r0, r2
 *   @0x21fcec bge 0x21fd08 <_Z10Sound_Datai+0x34>
 *   @0x21fcf0 ldr r2, [r3]
 *   @0x21fcf4 cmp r0, r2
 *   @0x21fcf8 bge 0x21fd08 <_Z10Sound_Datai+0x34>
 *   @0x21fcfc ldr r3, [r3, #0x4]
 *   @0x21fd00 ldr r0, [r3, r0, lsl #2]
 *   @0x21fd04 bx lr
 *   @0x21fd08 mov r0, #0
 *   @0x21fd0c bx lr
 *   @0x21fd10 subseq r5, r3, r8, asr r6
 *
 * ══ §363/438 _alutBufferDataConstruct  0x221378  size 64  16 条（0x221378..0x2213b8）
 * @func 0x221378 0x2213b8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutMalloc
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221378 push {r3, r4, r5, r6, r7, lr}
 *   @0x22137c mov r4, r0
 *   @0x221380 mov r0, #20
 *   @0x221384 mov r7, r1
 *   @0x221388 mov r6, r2
 *   @0x22138c mov r5, r3
 *   @0x221390 bl 0x222a98 <_alutMalloc>
 *   @0x221394 cmp r0, #0
 *   @0x221398 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x22139c vldr s15, [sp, #24]
 *   @0x2213a0 str r4, [r0]
 *   @0x2213a4 vstr s15, [r0, #16]
 *   @0x2213a8 str r7, [r0, #0x4]
 *   @0x2213ac str r6, [r0, #0x8]
 *   @0x2213b0 str r5, [r0, #0xc]
 *   @0x2213b4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §364/438 alutGetMIMETypes  0x222864  size 64  16 条（0x222864..0x2228a4）
 * @func 0x222864 0x2228a4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / _alutSetError
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222864 push {r4, lr}
 *   @0x222868 mov r4, r0
 *   @0x22286c bl 0x2219a8 <_alutSanityCheck>
 *   @0x222870 cmp r0, #0
 *   @0x222874 popeq {r4, pc}
 *   @0x222878 sub r4, r4, #768
 *   @0x22287c cmp r4, #1
 *   @0x222880 bhi 0x222890 <alutGetMIMETypes+0x2c>
 *   @0x222884 ldr r0, [pc, #0x14]
 *   @0x222888 add r0, pc, r0
 *   @0x22288c pop {r4, pc}
 *   @0x222890 movw r0, #0x201
 *   @0x222894 bl 0x221940 <_alutSetError>
 *   @0x222898 mov r0, #0
 *   @0x22289c pop {r4, pc}
 *   @0x2228a0 andseq r2, r3, r8, ror r3
 *
 * ══ §365/438 ogg_page_packets  0x2340ec  size 64  16 条（0x2340ec..0x23412c）
 * @func 0x2340ec 0x23412c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2340ec ldr r2, [r0]
 *   @0x2340f0 ldrb r12, [r2, #0x1a]
 *   @0x2340f4 cmp r12, #0
 *   @0x2340f8 beq 0x234124 <ogg_page_packets+0x38>
 *   @0x2340fc mov r0, #0
 *   @0x234100 add r2, r2, #26
 *   @0x234104 mov r3, r0
 *   @0x234108 ldrb r1, [r2, #0x1]!
 *   @0x23410c add r3, r3, #1
 *   @0x234110 cmp r1, #255
 *   @0x234114 addne r0, r0, #1
 *   @0x234118 cmp r12, r3
 *   @0x23411c bgt 0x234108 <ogg_page_packets+0x1c>
 *   @0x234120 bx lr
 *   @0x234124 mov r0, r12
 *   @0x234128 bx lr
 *
 * ══ §366/438 IniFile::GetSection(char const*)  0x235a90  size 64  16 条（0x235a90..0x235ad0）
 * @func 0x235a90 0x235ad0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235a90 push {r3, r4, r5, lr}
 *   @0x235a94 mov r5, r1
 *   @0x235a98 ldr r4, [r0, #0x8]
 *   @0x235a9c cmp r4, #0
 *   @0x235aa0 bne 0x235ab4 <_ZN7IniFile10GetSectionEPKc+0x24>
 *   @0x235aa4 b 0x235ac8 <_ZN7IniFile10GetSectionEPKc+0x38>
 *   @0x235aa8 ldr r4, [r4]
 *   @0x235aac cmp r4, #0
 *   @0x235ab0 beq 0x235ac8 <_ZN7IniFile10GetSectionEPKc+0x38>
 *   @0x235ab4 mov r0, r5
 *   @0x235ab8 ldr r1, [r4, #0x8]
 *   @0x235abc bl 0xb6574 <strcmp@plt>
 *   @0x235ac0 cmp r0, #0
 *   @0x235ac4 bne 0x235aa8 <_ZN7IniFile10GetSectionEPKc+0x18>
 *   @0x235ac8 mov r0, r4
 *   @0x235acc pop {r3, r4, r5, pc}
 *
 * ══ §367/438 InLeapYear(double)  0x244be8  size 64  16 条（0x244be8..0x244c28）
 * @func 0x244be8 0x244c28  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YearFromTime(double) / DaysInYear(double)
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244be8 push {r3, lr}
 *   @0x244bec bl 0x244b90 <_Z12YearFromTimed>
 *   @0x244bf0 bl 0x244a08 <_Z10DaysInYeard>
 *   @0x244bf4 vldr d7, [pc, #36]
 *   @0x244bf8 vmov d6, r0, r1
 *   @0x244bfc vcmp.f64 d6, d7
 *   @0x244c00 vmrs APSR_nzcv, fpscr
 *   @0x244c04 moveq r0, #0
 *   @0x244c08 movne r0, #1
 *   @0x244c0c vmov s15, r0
 *   @0x244c10 vcvt.f64.s32 d7, s15
 *   @0x244c14 vmov r0, r1, d7
 *   @0x244c18 pop {r3, pc}
 *   @0x244c1c nop
 *   @0x244c20 andeq r0, r0, r0
 *   @0x244c24 rsbsmi sp, r6, r0
 *
 * ══ §368/438 F_JS_Object_getPrototypeOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x250650  size 64  16 条（0x250650..0x250690）
 * @func 0x250650 0x250690  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x250650 cmp r3, #0
 *   @0x250654 ldr r3, [sp]
 *   @0x250658 beq 0x25066c <_Z26F_JS_Object_getPrototypeOfR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x25065c ldr r2, [r3, #0xc]
 *   @0x250660 bic r2, r2, #-16777216
 *   @0x250664 cmp r2, #6
 *   @0x250668 beq 0x250678 <_Z26F_JS_Object_getPrototypeOfR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x25066c ldr r0, [pc, #0x18]
 *   @0x250670 add r0, pc, r0
 *   @0x250674 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x250678 ldr r3, [r3]
 *   @0x25067c str r2, [r0, #0xc]
 *   @0x250680 ldr r3, [r3, #0x18]
 *   @0x250684 str r3, [r0]
 *   @0x250688 bx lr
 *   @0x25068c ldrsbeq r5, [r0], -r8
 *
 * ══ §369/438 JS_Number_Call(RValue&, CInstance*, CInstance*, int, RValue*)  0x252d14  size 64  16 条（0x252d14..0x252d54）
 * @func 0x252d14 0x252d54  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&)
 * 字段偏移 top8: 0x8×2 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252d14 push {r3, lr}
 *   @0x252d18 cmp r3, #0
 *   @0x252d1c ldr r1, [sp, #0x8]
 *   @0x252d20 bne 0x252d34 <_Z14JS_Number_CallR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x252d24 str r3, [r0]
 *   @0x252d28 str r3, [r0, #0x4]
 *   @0x252d2c str r3, [r0, #0xc]
 *   @0x252d30 pop {r3, pc}
 *   @0x252d34 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252d38 cmp r0, #1
 *   @0x252d3c popne {r3, pc}
 *   @0x252d40 ldr r0, [pc, #0x8]
 *   @0x252d44 pop {r3, lr}
 *   @0x252d48 add r0, pc, r0
 *   @0x252d4c b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252d50 andseq r3, r0, r8, lsl #17
 *
 * ══ §370/438 mc_error  0x27e388  size 64  16 条（0x27e388..0x27e3c8）
 * @func 0x27e388 0x27e3c8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6d00
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x-4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e388 push {r0, r1, r2, r3}
 *   @0x27e38c ldr r0, [pc, #0x30]
 *   @0x27e390 str lr, [sp, #-0x4]!
 *   @0x27e394 sub sp, sp, #12
 *   @0x27e398 add r3, sp, #20
 *   @0x27e39c ldr r0, [pc, r0]
 *   @0x27e3a0 ldr r1, [sp, #0x10]
 *   @0x27e3a4 add r0, r0, #168
 *   @0x27e3a8 mov r2, r3
 *   @0x27e3ac str r3, [sp, #0x4]
 *   @0x27e3b0 bl 0xb6d00 <vfprintf@plt>
 *   @0x27e3b4 add sp, sp, #12
 *   @0x27e3b8 ldr lr, [sp], #4
 *   @0x27e3bc add sp, sp, #16
 *   @0x27e3c0 bx lr
 *   @0x27e3c4 andseq r3, r7, r8, lsr #1
 *
 * ══ §371/438 mc_info  0x27e3c8  size 64  16 条（0x27e3c8..0x27e408）
 * @func 0x27e3c8 0x27e408  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6d00
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x-4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e3c8 push {r0, r1, r2, r3}
 *   @0x27e3cc ldr r0, [pc, #0x30]
 *   @0x27e3d0 str lr, [sp, #-0x4]!
 *   @0x27e3d4 sub sp, sp, #12
 *   @0x27e3d8 add r3, sp, #20
 *   @0x27e3dc ldr r0, [pc, r0]
 *   @0x27e3e0 ldr r1, [sp, #0x10]
 *   @0x27e3e4 add r0, r0, #168
 *   @0x27e3e8 mov r2, r3
 *   @0x27e3ec str r3, [sp, #0x4]
 *   @0x27e3f0 bl 0xb6d00 <vfprintf@plt>
 *   @0x27e3f4 add sp, sp, #12
 *   @0x27e3f8 ldr lr, [sp], #4
 *   @0x27e3fc add sp, sp, #16
 *   @0x27e400 bx lr
 *   @0x27e404 andseq r3, r7, r8, rrx
 *
 * ══ §372/438 lh_char_hash  0x2807bc  size 64  16 条（0x2807bc..0x2807fc）
 * @func 0x2807bc 0x2807fc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2807bc ldrb r3, [r0]
 *   @0x2807c0 cmp r3, #0
 *   @0x2807c4 beq 0x2807f4 <lh_char_hash+0x38>
 *   @0x2807c8 mov r2, r0
 *   @0x2807cc mov r0, #0
 *   @0x2807d0 add r1, r0, r0, lsl #7
 *   @0x2807d4 mov r0, #1
 *   @0x2807d8 add r1, r1, r3
 *   @0x2807dc ldrb r3, [r2, #0x1]!
 *   @0x2807e0 movt r0, #0x9e37
 *   @0x2807e4 cmp r3, #0
 *   @0x2807e8 add r0, r1, r0
 *   @0x2807ec bne 0x2807d0 <lh_char_hash+0x14>
 *   @0x2807f0 bx lr
 *   @0x2807f4 mov r0, r3
 *   @0x2807f8 bx lr
 *
 * ══ §373/438 spColorTimeline_setFrame  0x282b54  size 64  16 条（0x282b54..0x282b94）
 * @func 0x282b54 0x282b94  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×2 / 0x8×2 / 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282b54 add r1, r1, r1, lsl #2
 *   @0x282b58 ldr r0, [r0, #0x10]
 *   @0x282b5c add r12, r1, #1
 *   @0x282b60 push {r4, r5}
 *   @0x282b64 add r1, r0, r1, lsl #2
 *   @0x282b68 ldr r5, [sp, #0x8]
 *   @0x282b6c add r0, r0, r12, lsl #2
 *   @0x282b70 ldr r4, [sp, #0xc]
 *   @0x282b74 ldr r12, [sp, #0x10]
 *   @0x282b78 str r2, [r1]
 *   @0x282b7c str r5, [r0, #0x4]
 *   @0x282b80 str r4, [r0, #0x8]
 *   @0x282b84 str r3, [r0]
 *   @0x282b88 str r12, [r0, #0xc]
 *   @0x282b8c pop {r4, r5}
 *   @0x282b90 bx lr
 *
 * ══ §374/438 spTransformConstraintTimeline_setFrame  0x282fd0  size 64  16 条（0x282fd0..0x283010）
 * @func 0x282fd0 0x283010  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×2 / 0x8×2 / 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282fd0 add r1, r1, r1, lsl #2
 *   @0x282fd4 ldr r0, [r0, #0x10]
 *   @0x282fd8 add r12, r1, #1
 *   @0x282fdc push {r4, r5}
 *   @0x282fe0 add r1, r0, r1, lsl #2
 *   @0x282fe4 ldr r5, [sp, #0x8]
 *   @0x282fe8 add r0, r0, r12, lsl #2
 *   @0x282fec ldr r4, [sp, #0xc]
 *   @0x282ff0 ldr r12, [sp, #0x10]
 *   @0x282ff4 str r2, [r1]
 *   @0x282ff8 str r5, [r0, #0x4]
 *   @0x282ffc str r4, [r0, #0x8]
 *   @0x283000 str r3, [r0]
 *   @0x283004 str r12, [r0, #0xc]
 *   @0x283008 pop {r4, r5}
 *   @0x28300c bx lr
 *
 * ══ §375/438 spAnimationState_clearTracks  0x2835ec  size 64  16 条（0x2835ec..0x28362c）
 * @func 0x2835ec 0x28362c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAnimationState_clearTracks+0x34 / spAnimationState_clearTrack
 * 字段偏移 top8: 0xc×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2835ec push {r3, r4, r5, lr}
 *   @0x2835f0 mov r5, r0
 *   @0x2835f4 ldr r3, [r0, #0xc]
 *   @0x2835f8 cmp r3, #0
 *   @0x2835fc movgt r4, #0
 *   @0x283600 ble 0x283620 <spAnimationState_clearTracks+0x34>
 *   @0x283604 mov r1, r4
 *   @0x283608 mov r0, r5
 *   @0x28360c bl 0x283558 <spAnimationState_clearTrack>
 *   @0x283610 ldr r3, [r5, #0xc]
 *   @0x283614 add r4, r4, #1
 *   @0x283618 cmp r3, r4
 *   @0x28361c bgt 0x283604 <spAnimationState_clearTracks+0x18>
 *   @0x283620 mov r3, #0
 *   @0x283624 str r3, [r5, #0xc]
 *   @0x283628 pop {r3, r4, r5, pc}
 *
 * ══ §376/438 spAnimationState_addAnimationByName  0x283a6c  size 64  16 条（0x283a6c..0x283aac）
 * @func 0x283a6c 0x283aac  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findAnimation
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283a6c push {r4, r5, r6, r7, r8, lr}
 *   @0x283a70 mov r4, r0
 *   @0x283a74 ldr r0, [r0]
 *   @0x283a78 mov r5, r1
 *   @0x283a7c mov r1, r2
 *   @0x283a80 ldr r7, [sp, #0x18]
 *   @0x283a84 mov r6, r3
 *   @0x283a88 ldr r0, [r0]
 *   @0x283a8c bl 0x28b1dc <spSkeletonData_findAnimation>
 *   @0x283a90 str r7, [sp, #0x18]
 *   @0x283a94 mov r1, r5
 *   @0x283a98 mov r3, r6
 *   @0x283a9c mov r2, r0
 *   @0x283aa0 mov r0, r4
 *   @0x283aa4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x283aa8 b 0x28399c <spAnimationState_addAnimation>
 *
 * ══ §377/438 Java_com_yoyogames_runner_RunnerJNILib_Pause  0x2925d4  size 64  16 条（0x2925d4..0x292614）
 * @func 0x2925d4 0x292614  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / 0xb6d60 / ForgetAllGamePads()
 * 字段偏移 top8: 0x28×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2925d4 push {r3, lr}
 *   @0x2925d8 bl 0x290614 <setJNIEnv>
 *   @0x2925dc ldr r3, [pc, #0x28]
 *   @0x2925e0 ldr r1, [pc, #0x28]
 *   @0x2925e4 ldr r3, [pc, r3]
 *   @0x2925e8 add r1, pc, r1
 *   @0x2925ec ldr r0, [r3]
 *   @0x2925f0 ldr r3, [r0]
 *   @0x2925f4 ldr r3, [r3, #0xc]
 *   @0x2925f8 blx r3
 *   @0x2925fc bl 0xb6d60 <alcPauseCurrentDevice@plt>
 *   @0x292600 bl 0x18e8ec <_Z17ForgetAllGamePadsv>
 *   @0x292604 pop {r3, lr}
 *   @0x292608 b 0x159d44 <RaiseOSPauseEvent>
 *   @0x29260c andseq r11, r5, r0, lsr r1
 *   @0x292610 andeq r6, r12, r4, ror r9
 *
 * ══ §378/438 PollServersOnly()  0x298db4  size 64  16 条（0x298db4..0x298df4）
 * @func 0x298db4 0x298df4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyServer::Process()
 * 字段偏移 top8: 0x30×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x298db4 push {r3, r4, r5, lr}
 *   @0x298db8 ldr r4, [pc, #0x30]
 *   @0x298dbc ldr r4, [pc, r4]
 *   @0x298dc0 add r5, r4, #768
 *   @0x298dc4 ldrb r3, [r4]
 *   @0x298dc8 cmp r3, #0
 *   @0x298dcc beq 0x298de0 <_Z15PollServersOnlyv+0x2c>
 *   @0x298dd0 ldr r0, [r4, #0x8]
 *   @0x298dd4 cmp r0, #0
 *   @0x298dd8 beq 0x298de0 <_Z15PollServersOnlyv+0x2c>
 *   @0x298ddc bl 0x297f98 <_ZN8yyServer7ProcessEv>
 *   @0x298de0 add r4, r4, #12
 *   @0x298de4 cmp r4, r5
 *   @0x298de8 bne 0x298dc4 <_Z15PollServersOnlyv+0x10>
 *   @0x298dec pop {r3, r4, r5, pc}
 *   @0x298df0 andseq r8, r5, r8, ror #23
 *
 * ══ §379/438 Debug_WriteErrorMessage(Buffer_Standard*)  0x29c108  size 64  16 条（0x29c108..0x29c148）
 * @func 0x29c108 0x29c148  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WriteString(Buffer_Standard*, char const*)
 * 字段偏移 top8: 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c108 push {r4, lr}
 *   @0x29c10c ldr r4, [pc, #0x2c]
 *   @0x29c110 ldr r4, [pc, r4]
 *   @0x29c114 ldr r1, [r4]
 *   @0x29c118 cmp r1, #0
 *   @0x29c11c beq 0x29c130 <_Z23Debug_WriteErrorMessageP15Buffer_Standard+0x28>
 *   @0x29c120 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29c124 mov r3, #0
 *   @0x29c128 str r3, [r4]
 *   @0x29c12c pop {r4, pc}
 *   @0x29c130 ldr r1, [pc, #0xc]
 *   @0x29c134 pop {r4, lr}
 *   @0x29c138 add r1, pc, r1
 *   @0x29c13c b 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29c140 andseq r1, r5, r12, ror r12
 *   @0x29c144 strdeq r2, r3, [r9], -lr
 *
 * ══ §380/438 Debug_FreeTags()  0x29c5c8  size 64  16 条（0x29c5c8..0x29c608）
 * @func 0x29c5c8 0x29c608  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x30×1 / 0xc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c5c8 push {r3, r4, r5, lr}
 *   @0x29c5cc ldr r5, [pc, #0x30]
 *   @0x29c5d0 add r5, pc, r5
 *   @0x29c5d4 ldrh r3, [r5, #8]
 *   @0x29c5d8 cmp r3, #0
 *   @0x29c5dc popeq {r3, r4, r5, pc}
 *   @0x29c5e0 mov r4, #0
 *   @0x29c5e4 ldr r3, [r5, #0xc]
 *   @0x29c5e8 ldr r0, [r3, r4, lsl #2]
 *   @0x29c5ec add r4, r4, #1
 *   @0x29c5f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29c5f4 ldrh r3, [r5, #8]
 *   @0x29c5f8 cmp r3, r4
 *   @0x29c5fc bgt 0x29c5e4 <_Z14Debug_FreeTagsv+0x1c>
 *   @0x29c600 pop {r3, r4, r5, pc}
 *   @0x29c604 subeq r11, r11, r8, lsr r6
 *
 * ══ §381/438 Debug_GetSelectedInstance(Buffer_Standard*, Buffer_Standard*)  0x29c608  size 64  16 条（0x29c608..0x29c648）
 * @func 0x29c608 0x29c648  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×2 / 0x30×1 / 0x38×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c608 mov r2, r1
 *   @0x29c60c mov r0, #0
 *   @0x29c610 ldr r12, [r2], #44
 *   @0x29c614 movt r0, #0xffe0
 *   @0x29c618 push {r3, lr}
 *   @0x29c61c movw r3, #0xffff
 *   @0x29c620 str r0, [r1, #0x2c]
 *   @0x29c624 movt r3, #0x41ef
 *   @0x29c628 mov r0, #0
 *   @0x29c62c str r3, [r1, #0x30]
 *   @0x29c630 str r0, [r1, #0x38]
 *   @0x29c634 mov r0, r1
 *   @0x29c638 ldr r3, [r12, #0x8]
 *   @0x29c63c mov r1, #5
 *   @0x29c640 blx r3
 *   @0x29c644 pop {r3, pc}
 *
 * ══ §382/438 DbgServer::DbgServer(bool)  0x29cf24  size 64  16 条（0x29cf24..0x29cf64）
 * @func 0x29cf24 0x29cf64  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / yyServer::yyServer(bool)
 * 字段偏移 top8: 0x5×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cf24 push {r3, r4, r5, r6, r7, lr}
 *   @0x29cf28 mov r4, r0
 *   @0x29cf2c mov r5, #0
 *   @0x29cf30 mov r0, #44
 *   @0x29cf34 str r5, [r4]
 *   @0x29cf38 mov r6, r1
 *   @0x29cf3c bl 0x27c524 <_Znwj>
 *   @0x29cf40 mov r1, r5
 *   @0x29cf44 mov r7, r0
 *   @0x29cf48 bl 0x2970f8 <_ZN8yyServerC2Eb>
 *   @0x29cf4c mov r3, #1
 *   @0x29cf50 str r7, [r4]
 *   @0x29cf54 strb r6, [r4, #0x5]
 *   @0x29cf58 mov r0, r4
 *   @0x29cf5c strb r3, [r4, #0x4]
 *   @0x29cf60 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §383/438 CProfiler::EndStep()  0x2a0960  size 64  16 条（0x2a0960..0x2a09a0）
 * @func 0x2a0960 0x2a09a0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CProfiler::Pop() / Timing_Time
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a0960 push {r4, r5, r6, r7, r8, lr}
 *   @0x2a0964 mov r8, r0
 *   @0x2a0968 bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x2a096c bl 0x215148 <Timing_Time>
 *   @0x2a0970 ldrd r4, r5, [r8]
 *   @0x2a0974 ldrd r2, r3, [r8, #88]
 *   @0x2a0978 ldrd r6, r7, [r8, #96]
 *   @0x2a097c subs r0, r0, r4
 *   @0x2a0980 sbc r1, r1, r5
 *   @0x2a0984 subs r0, r0, r2
 *   @0x2a0988 sbc r1, r1, r3
 *   @0x2a098c strd r0, r1, [r8, #104]
 *   @0x2a0990 adds r4, r6, r0
 *   @0x2a0994 adc r5, r7, r1
 *   @0x2a0998 strd r4, r5, [r8, #96]
 *   @0x2a099c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §384/438 jpeg_input_complete  0x2b3240  size 64  16 条（0x2b3240..0x2b3280）
 * @func 0x2b3240 0x2b3280  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_input_complete+0x34
 * 字段偏移 top8: 0x14×2 / 0x18×1 / 0x190×1 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b3240 ldr r3, [r0, #0x14]
 *   @0x2b3244 push {r4, lr}
 *   @0x2b3248 sub r2, r3, #200
 *   @0x2b324c cmp r2, #10
 *   @0x2b3250 mov r4, r0
 *   @0x2b3254 bls 0x2b3274 <jpeg_input_complete+0x34>
 *   @0x2b3258 ldr r2, [r0]
 *   @0x2b325c mov r1, #20
 *   @0x2b3260 str r3, [r2, #0x18]
 *   @0x2b3264 ldr r3, [r0]
 *   @0x2b3268 str r1, [r2, #0x14]
 *   @0x2b326c ldr r3, [r3]
 *   @0x2b3270 blx r3
 *   @0x2b3274 ldr r3, [r4, #0x190]
 *   @0x2b3278 ldrb r0, [r3, #0x11]
 *   @0x2b327c pop {r4, pc}
 *
 * ══ §385/438 jpeg_has_multiple_scans  0x2b3280  size 64  16 条（0x2b3280..0x2b32c0）
 * @func 0x2b3280 0x2b32c0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_has_multiple_scans+0x34
 * 字段偏移 top8: 0x14×2 / 0x18×1 / 0x190×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b3280 ldr r3, [r0, #0x14]
 *   @0x2b3284 push {r4, lr}
 *   @0x2b3288 sub r2, r3, #202
 *   @0x2b328c cmp r2, #8
 *   @0x2b3290 mov r4, r0
 *   @0x2b3294 bls 0x2b32b4 <jpeg_has_multiple_scans+0x34>
 *   @0x2b3298 ldr r2, [r0]
 *   @0x2b329c mov r1, #20
 *   @0x2b32a0 str r3, [r2, #0x18]
 *   @0x2b32a4 ldr r3, [r0]
 *   @0x2b32a8 str r1, [r2, #0x14]
 *   @0x2b32ac ldr r3, [r3]
 *   @0x2b32b0 blx r3
 *   @0x2b32b4 ldr r3, [r4, #0x190]
 *   @0x2b32b8 ldrb r0, [r3, #0x10]
 *   @0x2b32bc pop {r4, pc}
 *
 * ══ §386/438 DGifGetCode(GifFileType*, int*, unsigned char**)  0x2c2804  size 64  16 条（0x2c2804..0x2c2844）
 * @func 0x2c2804 0x2c2844  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0x40×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2804 push {r4, r5}
 *   @0x2c2808 mov r5, r1
 *   @0x2c280c ldr r4, [r0, #0x48]
 *   @0x2c2810 ldr r3, [r4]
 *   @0x2c2814 ands r3, r3, #8
 *   @0x2c2818 bne 0x2c2830 <_Z11DGifGetCodeP11GifFileTypePiPPh+0x2c>
 *   @0x2c281c mov r2, #111
 *   @0x2c2820 str r2, [r0, #0x40]
 *   @0x2c2824 pop {r4, r5}
 *   @0x2c2828 mov r0, r3
 *   @0x2c282c bx lr
 *   @0x2c2830 ldr r3, [r4, #0x8]
 *   @0x2c2834 mov r1, r2
 *   @0x2c2838 str r3, [r5]
 *   @0x2c283c pop {r4, r5}
 *   @0x2c2840 b 0x2c25c0 <_Z15DGifGetCodeNextP11GifFileTypePPh>
 *
 * ══ §387/438 GifApplyTranslation(SavedImage*, unsigned char*)  0x2c2efc  size 64  16 条（0x2c2efc..0x2c2f3c）
 * @func 0x2c2efc 0x2c2f3c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GifApplyTranslation(SavedImage*, unsigned char*)+0x38
 * 字段偏移 top8: 0x-4×1 / 0xc×1 / 0x8×1 / 0x18×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2efc str r4, [sp, #-0x4]!
 *   @0x2c2f00 ldr r3, [r0, #0xc]
 *   @0x2c2f04 ldr r4, [r0, #0x8]
 *   @0x2c2f08 mul r4, r4, r3
 *   @0x2c2f0c cmp r4, #0
 *   @0x2c2f10 ble 0x2c2f34 <_Z19GifApplyTranslationP10SavedImagePh+0x38>
 *   @0x2c2f14 mov r3, #0
 *   @0x2c2f18 ldr r2, [r0, #0x18]
 *   @0x2c2f1c ldrb r12, [r2, r3]
 *   @0x2c2f20 ldrb r12, [r1, r12]
 *   @0x2c2f24 strb r12, [r2, r3]
 *   @0x2c2f28 add r3, r3, #1
 *   @0x2c2f2c cmp r3, r4
 *   @0x2c2f30 bne 0x2c2f18 <_Z19GifApplyTranslationP10SavedImagePh+0x1c>
 *   @0x2c2f34 ldr r4, [sp], #4
 *   @0x2c2f38 bx lr
 *
 * ══ §388/438 b2DistanceJoint::GetAnchorA() const  0x2cc9e0  size 64  16 条（0x2cc9e0..0x2cca20）
 * @func 0x2cc9e0 0x2cca20  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc9e0 ldr r3, [r1, #0x30]
 *   @0x2cc9e4 vldr s15, [r1, #84]
 *   @0x2cc9e8 vldr s12, [r3, #24]
 *   @0x2cc9ec vldr s11, [r3, #20]
 *   @0x2cc9f0 vmul.f32 s14, s12, s15
 *   @0x2cc9f4 vldr s13, [r1, #80]
 *   @0x2cc9f8 vldr s9, [r3, #16]
 *   @0x2cc9fc vldr s10, [r3, #12]
 *   @0x2cca00 vmul.f32 s15, s11, s15
 *   @0x2cca04 vmla.f32 s14, s13, s11
 *   @0x2cca08 vnmls.f32 s15, s12, s13
 *   @0x2cca0c vadd.f32 s14, s14, s9
 *   @0x2cca10 vadd.f32 s15, s15, s10
 *   @0x2cca14 vstr s14, [r0, #4]
 *   @0x2cca18 vstr s15, [r0]
 *   @0x2cca1c bx lr
 *
 * ══ §389/438 b2DistanceJoint::GetAnchorB() const  0x2cca20  size 64  16 条（0x2cca20..0x2cca60）
 * @func 0x2cca20 0x2cca60  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cca20 ldr r3, [r1, #0x34]
 *   @0x2cca24 vldr s15, [r1, #92]
 *   @0x2cca28 vldr s12, [r3, #24]
 *   @0x2cca2c vldr s11, [r3, #20]
 *   @0x2cca30 vmul.f32 s14, s12, s15
 *   @0x2cca34 vldr s13, [r1, #88]
 *   @0x2cca38 vldr s9, [r3, #16]
 *   @0x2cca3c vldr s10, [r3, #12]
 *   @0x2cca40 vmul.f32 s15, s11, s15
 *   @0x2cca44 vmla.f32 s14, s13, s11
 *   @0x2cca48 vnmls.f32 s15, s12, s13
 *   @0x2cca4c vadd.f32 s14, s14, s9
 *   @0x2cca50 vadd.f32 s15, s15, s10
 *   @0x2cca54 vstr s14, [r0, #4]
 *   @0x2cca58 vstr s15, [r0]
 *   @0x2cca5c bx lr
 *
 * ══ §390/438 b2FrictionJoint::GetAnchorA() const  0x2cd328  size 64  16 条（0x2cd328..0x2cd368）
 * @func 0x2cd328 0x2cd368  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd328 ldr r3, [r1, #0x30]
 *   @0x2cd32c vldr s15, [r1, #72]
 *   @0x2cd330 vldr s12, [r3, #24]
 *   @0x2cd334 vldr s11, [r3, #20]
 *   @0x2cd338 vmul.f32 s14, s12, s15
 *   @0x2cd33c vldr s13, [r1, #68]
 *   @0x2cd340 vldr s9, [r3, #16]
 *   @0x2cd344 vldr s10, [r3, #12]
 *   @0x2cd348 vmul.f32 s15, s11, s15
 *   @0x2cd34c vmla.f32 s14, s13, s11
 *   @0x2cd350 vnmls.f32 s15, s12, s13
 *   @0x2cd354 vadd.f32 s14, s14, s9
 *   @0x2cd358 vadd.f32 s15, s15, s10
 *   @0x2cd35c vstr s14, [r0, #4]
 *   @0x2cd360 vstr s15, [r0]
 *   @0x2cd364 bx lr
 *
 * ══ §391/438 b2FrictionJoint::GetAnchorB() const  0x2cd368  size 64  16 条（0x2cd368..0x2cd3a8）
 * @func 0x2cd368 0x2cd3a8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd368 ldr r3, [r1, #0x34]
 *   @0x2cd36c vldr s15, [r1, #80]
 *   @0x2cd370 vldr s12, [r3, #24]
 *   @0x2cd374 vldr s11, [r3, #20]
 *   @0x2cd378 vmul.f32 s14, s12, s15
 *   @0x2cd37c vldr s13, [r1, #76]
 *   @0x2cd380 vldr s9, [r3, #16]
 *   @0x2cd384 vldr s10, [r3, #12]
 *   @0x2cd388 vmul.f32 s15, s11, s15
 *   @0x2cd38c vmla.f32 s14, s13, s11
 *   @0x2cd390 vnmls.f32 s15, s12, s13
 *   @0x2cd394 vadd.f32 s14, s14, s9
 *   @0x2cd398 vadd.f32 s15, s15, s10
 *   @0x2cd39c vstr s14, [r0, #4]
 *   @0x2cd3a0 vstr s15, [r0]
 *   @0x2cd3a4 bx lr
 *
 * ══ §392/438 b2MouseJoint::GetAnchorB() const  0x2ce968  size 64  16 条（0x2ce968..0x2ce9a8）
 * @func 0x2ce968 0x2ce9a8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce968 ldr r3, [r1, #0x34]
 *   @0x2ce96c vldr s15, [r1, #72]
 *   @0x2ce970 vldr s12, [r3, #24]
 *   @0x2ce974 vldr s11, [r3, #20]
 *   @0x2ce978 vmul.f32 s14, s12, s15
 *   @0x2ce97c vldr s13, [r1, #68]
 *   @0x2ce980 vldr s9, [r3, #16]
 *   @0x2ce984 vldr s10, [r3, #12]
 *   @0x2ce988 vmul.f32 s15, s11, s15
 *   @0x2ce98c vmla.f32 s14, s13, s11
 *   @0x2ce990 vnmls.f32 s15, s12, s13
 *   @0x2ce994 vadd.f32 s14, s14, s9
 *   @0x2ce998 vadd.f32 s15, s15, s10
 *   @0x2ce99c vstr s14, [r0, #4]
 *   @0x2ce9a0 vstr s15, [r0]
 *   @0x2ce9a4 bx lr
 *
 * ══ §393/438 b2PrismaticJoint::GetAnchorA() const  0x2cf0b8  size 64  16 条（0x2cf0b8..0x2cf0f8）
 * @func 0x2cf0b8 0x2cf0f8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf0b8 ldr r3, [r1, #0x30]
 *   @0x2cf0bc vldr s15, [r1, #72]
 *   @0x2cf0c0 vldr s12, [r3, #24]
 *   @0x2cf0c4 vldr s11, [r3, #20]
 *   @0x2cf0c8 vmul.f32 s14, s12, s15
 *   @0x2cf0cc vldr s13, [r1, #68]
 *   @0x2cf0d0 vldr s9, [r3, #16]
 *   @0x2cf0d4 vldr s10, [r3, #12]
 *   @0x2cf0d8 vmul.f32 s15, s11, s15
 *   @0x2cf0dc vmla.f32 s14, s13, s11
 *   @0x2cf0e0 vnmls.f32 s15, s12, s13
 *   @0x2cf0e4 vadd.f32 s14, s14, s9
 *   @0x2cf0e8 vadd.f32 s15, s15, s10
 *   @0x2cf0ec vstr s14, [r0, #4]
 *   @0x2cf0f0 vstr s15, [r0]
 *   @0x2cf0f4 bx lr
 *
 * ══ §394/438 b2PrismaticJoint::GetAnchorB() const  0x2cf0f8  size 64  16 条（0x2cf0f8..0x2cf138）
 * @func 0x2cf0f8 0x2cf138  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf0f8 ldr r3, [r1, #0x34]
 *   @0x2cf0fc vldr s15, [r1, #80]
 *   @0x2cf100 vldr s12, [r3, #24]
 *   @0x2cf104 vldr s11, [r3, #20]
 *   @0x2cf108 vmul.f32 s14, s12, s15
 *   @0x2cf10c vldr s13, [r1, #76]
 *   @0x2cf110 vldr s9, [r3, #16]
 *   @0x2cf114 vldr s10, [r3, #12]
 *   @0x2cf118 vmul.f32 s15, s11, s15
 *   @0x2cf11c vmla.f32 s14, s13, s11
 *   @0x2cf120 vnmls.f32 s15, s12, s13
 *   @0x2cf124 vadd.f32 s14, s14, s9
 *   @0x2cf128 vadd.f32 s15, s15, s10
 *   @0x2cf12c vstr s14, [r0, #4]
 *   @0x2cf130 vstr s15, [r0]
 *   @0x2cf134 bx lr
 *
 * ══ §395/438 b2PrismaticJoint::EnableMotor(bool)  0x2d043c  size 64  16 条（0x2d043c..0x2d047c）
 * @func 0x2d043c 0x2d047c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x89×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d043c ldr r3, [r0, #0x30]
 *   @0x2d0440 ldrh r2, [r3, #4]
 *   @0x2d0444 tst r2, #2
 *   @0x2d0448 orreq r2, r2, #2
 *   @0x2d044c strheq r2, [r3, #4]
 *   @0x2d0450 moveq r12, #0
 *   @0x2d0454 streq r12, [r3, #0xa0]
 *   @0x2d0458 ldr r3, [r0, #0x34]
 *   @0x2d045c ldrh r2, [r3, #4]
 *   @0x2d0460 tst r2, #2
 *   @0x2d0464 orreq r2, r2, #2
 *   @0x2d0468 strheq r2, [r3, #4]
 *   @0x2d046c moveq r12, #0
 *   @0x2d0470 streq r12, [r3, #0xa0]
 *   @0x2d0474 strb r1, [r0, #0x89]
 *   @0x2d0478 bx lr
 *
 * ══ §396/438 b2PrismaticJoint::SetMotorSpeed(float)  0x2d047c  size 64  16 条（0x2d047c..0x2d04bc）
 * @func 0x2d047c 0x2d04bc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x84×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d047c ldr r3, [r0, #0x30]
 *   @0x2d0480 ldrh r2, [r3, #4]
 *   @0x2d0484 tst r2, #2
 *   @0x2d0488 orreq r2, r2, #2
 *   @0x2d048c strheq r2, [r3, #4]
 *   @0x2d0490 moveq r12, #0
 *   @0x2d0494 streq r12, [r3, #0xa0]
 *   @0x2d0498 ldr r3, [r0, #0x34]
 *   @0x2d049c ldrh r2, [r3, #4]
 *   @0x2d04a0 tst r2, #2
 *   @0x2d04a4 orreq r2, r2, #2
 *   @0x2d04a8 strheq r2, [r3, #4]
 *   @0x2d04ac moveq r12, #0
 *   @0x2d04b0 streq r12, [r3, #0xa0]
 *   @0x2d04b4 str r1, [r0, #0x84]
 *   @0x2d04b8 bx lr
 *
 * ══ §397/438 b2PrismaticJoint::SetMaxMotorForce(float)  0x2d04bc  size 64  16 条（0x2d04bc..0x2d04fc）
 * @func 0x2d04bc 0x2d04fc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d04bc ldr r3, [r0, #0x30]
 *   @0x2d04c0 ldrh r2, [r3, #4]
 *   @0x2d04c4 tst r2, #2
 *   @0x2d04c8 orreq r2, r2, #2
 *   @0x2d04cc strheq r2, [r3, #4]
 *   @0x2d04d0 moveq r12, #0
 *   @0x2d04d4 streq r12, [r3, #0xa0]
 *   @0x2d04d8 ldr r3, [r0, #0x34]
 *   @0x2d04dc ldrh r2, [r3, #4]
 *   @0x2d04e0 tst r2, #2
 *   @0x2d04e4 orreq r2, r2, #2
 *   @0x2d04e8 strheq r2, [r3, #4]
 *   @0x2d04ec moveq r12, #0
 *   @0x2d04f0 streq r12, [r3, #0xa0]
 *   @0x2d04f4 str r1, [r0, #0x80]
 *   @0x2d04f8 bx lr
 *
 * ══ §398/438 b2PulleyJoint::GetAnchorA() const  0x2d0624  size 64  16 条（0x2d0624..0x2d0664）
 * @func 0x2d0624 0x2d0664  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0624 ldr r3, [r1, #0x30]
 *   @0x2d0628 vldr s15, [r1, #96]
 *   @0x2d062c vldr s12, [r3, #24]
 *   @0x2d0630 vldr s11, [r3, #20]
 *   @0x2d0634 vmul.f32 s14, s12, s15
 *   @0x2d0638 vldr s13, [r1, #92]
 *   @0x2d063c vldr s9, [r3, #16]
 *   @0x2d0640 vldr s10, [r3, #12]
 *   @0x2d0644 vmul.f32 s15, s11, s15
 *   @0x2d0648 vmla.f32 s14, s13, s11
 *   @0x2d064c vnmls.f32 s15, s12, s13
 *   @0x2d0650 vadd.f32 s14, s14, s9
 *   @0x2d0654 vadd.f32 s15, s15, s10
 *   @0x2d0658 vstr s14, [r0, #4]
 *   @0x2d065c vstr s15, [r0]
 *   @0x2d0660 bx lr
 *
 * ══ §399/438 b2PulleyJoint::GetAnchorB() const  0x2d0664  size 64  16 条（0x2d0664..0x2d06a4）
 * @func 0x2d0664 0x2d06a4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0664 ldr r3, [r1, #0x34]
 *   @0x2d0668 vldr s15, [r1, #104]
 *   @0x2d066c vldr s12, [r3, #24]
 *   @0x2d0670 vldr s11, [r3, #20]
 *   @0x2d0674 vmul.f32 s14, s12, s15
 *   @0x2d0678 vldr s13, [r1, #100]
 *   @0x2d067c vldr s9, [r3, #16]
 *   @0x2d0680 vldr s10, [r3, #12]
 *   @0x2d0684 vmul.f32 s15, s11, s15
 *   @0x2d0688 vmla.f32 s14, s13, s11
 *   @0x2d068c vnmls.f32 s15, s12, s13
 *   @0x2d0690 vadd.f32 s14, s14, s9
 *   @0x2d0694 vadd.f32 s15, s15, s10
 *   @0x2d0698 vstr s14, [r0, #4]
 *   @0x2d069c vstr s15, [r0]
 *   @0x2d06a0 bx lr
 *
 * ══ §400/438 b2RevoluteJoint::GetAnchorA() const  0x2d128c  size 64  16 条（0x2d128c..0x2d12cc）
 * @func 0x2d128c 0x2d12cc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d128c ldr r3, [r1, #0x30]
 *   @0x2d1290 vldr s15, [r1, #72]
 *   @0x2d1294 vldr s12, [r3, #24]
 *   @0x2d1298 vldr s11, [r3, #20]
 *   @0x2d129c vmul.f32 s14, s12, s15
 *   @0x2d12a0 vldr s13, [r1, #68]
 *   @0x2d12a4 vldr s9, [r3, #16]
 *   @0x2d12a8 vldr s10, [r3, #12]
 *   @0x2d12ac vmul.f32 s15, s11, s15
 *   @0x2d12b0 vmla.f32 s14, s13, s11
 *   @0x2d12b4 vnmls.f32 s15, s12, s13
 *   @0x2d12b8 vadd.f32 s14, s14, s9
 *   @0x2d12bc vadd.f32 s15, s15, s10
 *   @0x2d12c0 vstr s14, [r0, #4]
 *   @0x2d12c4 vstr s15, [r0]
 *   @0x2d12c8 bx lr
 *
 * ══ §401/438 b2RevoluteJoint::GetAnchorB() const  0x2d12cc  size 64  16 条（0x2d12cc..0x2d130c）
 * @func 0x2d12cc 0x2d130c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d12cc ldr r3, [r1, #0x34]
 *   @0x2d12d0 vldr s15, [r1, #80]
 *   @0x2d12d4 vldr s12, [r3, #24]
 *   @0x2d12d8 vldr s11, [r3, #20]
 *   @0x2d12dc vmul.f32 s14, s12, s15
 *   @0x2d12e0 vldr s13, [r1, #76]
 *   @0x2d12e4 vldr s9, [r3, #16]
 *   @0x2d12e8 vldr s10, [r3, #12]
 *   @0x2d12ec vmul.f32 s15, s11, s15
 *   @0x2d12f0 vmla.f32 s14, s13, s11
 *   @0x2d12f4 vnmls.f32 s15, s12, s13
 *   @0x2d12f8 vadd.f32 s14, s14, s9
 *   @0x2d12fc vadd.f32 s15, s15, s10
 *   @0x2d1300 vstr s14, [r0, #4]
 *   @0x2d1304 vstr s15, [r0]
 *   @0x2d1308 bx lr
 *
 * ══ §402/438 b2RevoluteJoint::EnableMotor(bool)  0x2d214c  size 64  16 条（0x2d214c..0x2d218c）
 * @func 0x2d214c 0x2d218c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d214c ldr r3, [r0, #0x30]
 *   @0x2d2150 ldrh r2, [r3, #4]
 *   @0x2d2154 tst r2, #2
 *   @0x2d2158 orreq r2, r2, #2
 *   @0x2d215c strheq r2, [r3, #4]
 *   @0x2d2160 moveq r12, #0
 *   @0x2d2164 streq r12, [r3, #0xa0]
 *   @0x2d2168 ldr r3, [r0, #0x34]
 *   @0x2d216c ldrh r2, [r3, #4]
 *   @0x2d2170 tst r2, #2
 *   @0x2d2174 orreq r2, r2, #2
 *   @0x2d2178 strheq r2, [r3, #4]
 *   @0x2d217c moveq r12, #0
 *   @0x2d2180 streq r12, [r3, #0xa0]
 *   @0x2d2184 strb r1, [r0, #0x64]
 *   @0x2d2188 bx lr
 *
 * ══ §403/438 b2RevoluteJoint::SetMotorSpeed(float)  0x2d21a0  size 64  16 条（0x2d21a0..0x2d21e0）
 * @func 0x2d21a0 0x2d21e0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d21a0 ldr r3, [r0, #0x30]
 *   @0x2d21a4 ldrh r2, [r3, #4]
 *   @0x2d21a8 tst r2, #2
 *   @0x2d21ac orreq r2, r2, #2
 *   @0x2d21b0 strheq r2, [r3, #4]
 *   @0x2d21b4 moveq r12, #0
 *   @0x2d21b8 streq r12, [r3, #0xa0]
 *   @0x2d21bc ldr r3, [r0, #0x34]
 *   @0x2d21c0 ldrh r2, [r3, #4]
 *   @0x2d21c4 tst r2, #2
 *   @0x2d21c8 orreq r2, r2, #2
 *   @0x2d21cc strheq r2, [r3, #4]
 *   @0x2d21d0 moveq r12, #0
 *   @0x2d21d4 streq r12, [r3, #0xa0]
 *   @0x2d21d8 str r1, [r0, #0x6c]
 *   @0x2d21dc bx lr
 *
 * ══ §404/438 b2RevoluteJoint::SetMaxMotorTorque(float)  0x2d21e0  size 64  16 条（0x2d21e0..0x2d2220）
 * @func 0x2d21e0 0x2d2220  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d21e0 ldr r3, [r0, #0x30]
 *   @0x2d21e4 ldrh r2, [r3, #4]
 *   @0x2d21e8 tst r2, #2
 *   @0x2d21ec orreq r2, r2, #2
 *   @0x2d21f0 strheq r2, [r3, #4]
 *   @0x2d21f4 moveq r12, #0
 *   @0x2d21f8 streq r12, [r3, #0xa0]
 *   @0x2d21fc ldr r3, [r0, #0x34]
 *   @0x2d2200 ldrh r2, [r3, #4]
 *   @0x2d2204 tst r2, #2
 *   @0x2d2208 orreq r2, r2, #2
 *   @0x2d220c strheq r2, [r3, #4]
 *   @0x2d2210 moveq r12, #0
 *   @0x2d2214 streq r12, [r3, #0xa0]
 *   @0x2d2218 str r1, [r0, #0x68]
 *   @0x2d221c bx lr
 *
 * ══ §405/438 b2RopeJoint::GetAnchorA() const  0x2d246c  size 64  16 条（0x2d246c..0x2d24ac）
 * @func 0x2d246c 0x2d24ac  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d246c ldr r3, [r1, #0x30]
 *   @0x2d2470 vldr s15, [r1, #72]
 *   @0x2d2474 vldr s12, [r3, #24]
 *   @0x2d2478 vldr s11, [r3, #20]
 *   @0x2d247c vmul.f32 s14, s12, s15
 *   @0x2d2480 vldr s13, [r1, #68]
 *   @0x2d2484 vldr s9, [r3, #16]
 *   @0x2d2488 vldr s10, [r3, #12]
 *   @0x2d248c vmul.f32 s15, s11, s15
 *   @0x2d2490 vmla.f32 s14, s13, s11
 *   @0x2d2494 vnmls.f32 s15, s12, s13
 *   @0x2d2498 vadd.f32 s14, s14, s9
 *   @0x2d249c vadd.f32 s15, s15, s10
 *   @0x2d24a0 vstr s14, [r0, #4]
 *   @0x2d24a4 vstr s15, [r0]
 *   @0x2d24a8 bx lr
 *
 * ══ §406/438 b2RopeJoint::GetAnchorB() const  0x2d24ac  size 64  16 条（0x2d24ac..0x2d24ec）
 * @func 0x2d24ac 0x2d24ec  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d24ac ldr r3, [r1, #0x34]
 *   @0x2d24b0 vldr s15, [r1, #80]
 *   @0x2d24b4 vldr s12, [r3, #24]
 *   @0x2d24b8 vldr s11, [r3, #20]
 *   @0x2d24bc vmul.f32 s14, s12, s15
 *   @0x2d24c0 vldr s13, [r1, #76]
 *   @0x2d24c4 vldr s9, [r3, #16]
 *   @0x2d24c8 vldr s10, [r3, #12]
 *   @0x2d24cc vmul.f32 s15, s11, s15
 *   @0x2d24d0 vmla.f32 s14, s13, s11
 *   @0x2d24d4 vnmls.f32 s15, s12, s13
 *   @0x2d24d8 vadd.f32 s14, s14, s9
 *   @0x2d24dc vadd.f32 s15, s15, s10
 *   @0x2d24e0 vstr s14, [r0, #4]
 *   @0x2d24e4 vstr s15, [r0]
 *   @0x2d24e8 bx lr
 *
 * ══ §407/438 b2WeldJoint::GetAnchorA() const  0x2d2de0  size 64  16 条（0x2d2de0..0x2d2e20）
 * @func 0x2d2de0 0x2d2e20  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2de0 ldr r3, [r1, #0x30]
 *   @0x2d2de4 vldr s15, [r1, #84]
 *   @0x2d2de8 vldr s12, [r3, #24]
 *   @0x2d2dec vldr s11, [r3, #20]
 *   @0x2d2df0 vmul.f32 s14, s12, s15
 *   @0x2d2df4 vldr s13, [r1, #80]
 *   @0x2d2df8 vldr s9, [r3, #16]
 *   @0x2d2dfc vldr s10, [r3, #12]
 *   @0x2d2e00 vmul.f32 s15, s11, s15
 *   @0x2d2e04 vmla.f32 s14, s13, s11
 *   @0x2d2e08 vnmls.f32 s15, s12, s13
 *   @0x2d2e0c vadd.f32 s14, s14, s9
 *   @0x2d2e10 vadd.f32 s15, s15, s10
 *   @0x2d2e14 vstr s14, [r0, #4]
 *   @0x2d2e18 vstr s15, [r0]
 *   @0x2d2e1c bx lr
 *
 * ══ §408/438 b2WeldJoint::GetAnchorB() const  0x2d2e20  size 64  16 条（0x2d2e20..0x2d2e60）
 * @func 0x2d2e20 0x2d2e60  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2e20 ldr r3, [r1, #0x34]
 *   @0x2d2e24 vldr s15, [r1, #92]
 *   @0x2d2e28 vldr s12, [r3, #24]
 *   @0x2d2e2c vldr s11, [r3, #20]
 *   @0x2d2e30 vmul.f32 s14, s12, s15
 *   @0x2d2e34 vldr s13, [r1, #88]
 *   @0x2d2e38 vldr s9, [r3, #16]
 *   @0x2d2e3c vldr s10, [r3, #12]
 *   @0x2d2e40 vmul.f32 s15, s11, s15
 *   @0x2d2e44 vmla.f32 s14, s13, s11
 *   @0x2d2e48 vnmls.f32 s15, s12, s13
 *   @0x2d2e4c vadd.f32 s14, s14, s9
 *   @0x2d2e50 vadd.f32 s15, s15, s10
 *   @0x2d2e54 vstr s14, [r0, #4]
 *   @0x2d2e58 vstr s15, [r0]
 *   @0x2d2e5c bx lr
 *
 * ══ §409/438 b2WheelJoint::GetAnchorA() const  0x2d392c  size 64  16 条（0x2d392c..0x2d396c）
 * @func 0x2d392c 0x2d396c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d392c ldr r3, [r1, #0x30]
 *   @0x2d3930 vldr s15, [r1, #80]
 *   @0x2d3934 vldr s12, [r3, #24]
 *   @0x2d3938 vldr s11, [r3, #20]
 *   @0x2d393c vmul.f32 s14, s12, s15
 *   @0x2d3940 vldr s13, [r1, #76]
 *   @0x2d3944 vldr s9, [r3, #16]
 *   @0x2d3948 vldr s10, [r3, #12]
 *   @0x2d394c vmul.f32 s15, s11, s15
 *   @0x2d3950 vmla.f32 s14, s13, s11
 *   @0x2d3954 vnmls.f32 s15, s12, s13
 *   @0x2d3958 vadd.f32 s14, s14, s9
 *   @0x2d395c vadd.f32 s15, s15, s10
 *   @0x2d3960 vstr s14, [r0, #4]
 *   @0x2d3964 vstr s15, [r0]
 *   @0x2d3968 bx lr
 *
 * ══ §410/438 b2WheelJoint::GetAnchorB() const  0x2d396c  size 64  16 条（0x2d396c..0x2d39ac）
 * @func 0x2d396c 0x2d39ac  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d396c ldr r3, [r1, #0x34]
 *   @0x2d3970 vldr s15, [r1, #88]
 *   @0x2d3974 vldr s12, [r3, #24]
 *   @0x2d3978 vldr s11, [r3, #20]
 *   @0x2d397c vmul.f32 s14, s12, s15
 *   @0x2d3980 vldr s13, [r1, #84]
 *   @0x2d3984 vldr s9, [r3, #16]
 *   @0x2d3988 vldr s10, [r3, #12]
 *   @0x2d398c vmul.f32 s15, s11, s15
 *   @0x2d3990 vmla.f32 s14, s13, s11
 *   @0x2d3994 vnmls.f32 s15, s12, s13
 *   @0x2d3998 vadd.f32 s14, s14, s9
 *   @0x2d399c vadd.f32 s15, s15, s10
 *   @0x2d39a0 vstr s14, [r0, #4]
 *   @0x2d39a4 vstr s15, [r0]
 *   @0x2d39a8 bx lr
 *
 * ══ §411/438 b2WheelJoint::GetReactionForce(float) const  0x2d39ac  size 64  16 条（0x2d39ac..0x2d39ec）
 * @func 0x2d39ac 0x2d39ec  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d39ac vldr s15, [r1, #116]
 *   @0x2d39b0 vldr s14, [r1, #176]
 *   @0x2d39b4 vldr s9, [r1, #172]
 *   @0x2d39b8 vmul.f32 s14, s15, s14
 *   @0x2d39bc vldr s12, [r1, #108]
 *   @0x2d39c0 vldr s10, [r1, #184]
 *   @0x2d39c4 vldr s11, [r1, #180]
 *   @0x2d39c8 vmov s13, r2
 *   @0x2d39cc vmul.f32 s15, s15, s9
 *   @0x2d39d0 vmla.f32 s14, s12, s10
 *   @0x2d39d4 vmla.f32 s15, s12, s11
 *   @0x2d39d8 vmul.f32 s14, s13, s14
 *   @0x2d39dc vmul.f32 s15, s13, s15
 *   @0x2d39e0 vstr s14, [r0, #4]
 *   @0x2d39e4 vstr s15, [r0]
 *   @0x2d39e8 bx lr
 *
 * ══ §412/438 b2WheelJoint::EnableMotor(bool)  0x2d43a4  size 64  16 条（0x2d43a4..0x2d43e4）
 * @func 0x2d43a4 0x2d43e4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d43a4 ldr r3, [r0, #0x30]
 *   @0x2d43a8 ldrh r2, [r3, #4]
 *   @0x2d43ac tst r2, #2
 *   @0x2d43b0 orreq r2, r2, #2
 *   @0x2d43b4 strheq r2, [r3, #4]
 *   @0x2d43b8 moveq r12, #0
 *   @0x2d43bc streq r12, [r3, #0xa0]
 *   @0x2d43c0 ldr r3, [r0, #0x34]
 *   @0x2d43c4 ldrh r2, [r3, #4]
 *   @0x2d43c8 tst r2, #2
 *   @0x2d43cc orreq r2, r2, #2
 *   @0x2d43d0 strheq r2, [r3, #4]
 *   @0x2d43d4 moveq r12, #0
 *   @0x2d43d8 streq r12, [r3, #0xa0]
 *   @0x2d43dc strb r1, [r0, #0x80]
 *   @0x2d43e0 bx lr
 *
 * ══ §413/438 b2WheelJoint::SetMotorSpeed(float)  0x2d43e4  size 64  16 条（0x2d43e4..0x2d4424）
 * @func 0x2d43e4 0x2d4424  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d43e4 ldr r3, [r0, #0x30]
 *   @0x2d43e8 ldrh r2, [r3, #4]
 *   @0x2d43ec tst r2, #2
 *   @0x2d43f0 orreq r2, r2, #2
 *   @0x2d43f4 strheq r2, [r3, #4]
 *   @0x2d43f8 moveq r12, #0
 *   @0x2d43fc streq r12, [r3, #0xa0]
 *   @0x2d4400 ldr r3, [r0, #0x34]
 *   @0x2d4404 ldrh r2, [r3, #4]
 *   @0x2d4408 tst r2, #2
 *   @0x2d440c orreq r2, r2, #2
 *   @0x2d4410 strheq r2, [r3, #4]
 *   @0x2d4414 moveq r12, #0
 *   @0x2d4418 streq r12, [r3, #0xa0]
 *   @0x2d441c str r1, [r0, #0x7c]
 *   @0x2d4420 bx lr
 *
 * ══ §414/438 b2WheelJoint::SetMaxMotorTorque(float)  0x2d4424  size 64  16 条（0x2d4424..0x2d4464）
 * @func 0x2d4424 0x2d4464  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4424 ldr r3, [r0, #0x30]
 *   @0x2d4428 ldrh r2, [r3, #4]
 *   @0x2d442c tst r2, #2
 *   @0x2d4430 orreq r2, r2, #2
 *   @0x2d4434 strheq r2, [r3, #4]
 *   @0x2d4438 moveq r12, #0
 *   @0x2d443c streq r12, [r3, #0xa0]
 *   @0x2d4440 ldr r3, [r0, #0x34]
 *   @0x2d4444 ldrh r2, [r3, #4]
 *   @0x2d4448 tst r2, #2
 *   @0x2d444c orreq r2, r2, #2
 *   @0x2d4450 strheq r2, [r3, #4]
 *   @0x2d4454 moveq r12, #0
 *   @0x2d4458 streq r12, [r3, #0xa0]
 *   @0x2d445c str r1, [r0, #0x78]
 *   @0x2d4460 bx lr
 *
 * ══ §415/438 b2BroadPhase::UnBufferMove(int)  0x2dc8e4  size 64  16 条（0x2dc8e4..0x2dc924）
 * @func 0x2dc8e4 0x2dc924  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BroadPhase::UnBufferMove(int)+0x38
 * 字段偏移 top8: 0x28×1 / 0x20×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc8e4 push {r4, r5}
 *   @0x2dc8e8 ldr r4, [r0, #0x28]
 *   @0x2dc8ec cmp r4, #0
 *   @0x2dc8f0 ble 0x2dc91c <_ZN12b2BroadPhase12UnBufferMoveEi+0x38>
 *   @0x2dc8f4 ldr r2, [r0, #0x20]
 *   @0x2dc8f8 mov r3, #0
 *   @0x2dc8fc mvn r5, #0
 *   @0x2dc900 ldr r12, [r2], #4
 *   @0x2dc904 add r3, r3, #1
 *   @0x2dc908 cmp r12, r1
 *   @0x2dc90c streq r5, [r2, #-0x4]
 *   @0x2dc910 ldreq r4, [r0, #0x28]
 *   @0x2dc914 cmp r4, r3
 *   @0x2dc918 bgt 0x2dc900 <_ZN12b2BroadPhase12UnBufferMoveEi+0x1c>
 *   @0x2dc91c pop {r4, r5}
 *   @0x2dc920 bx lr
 *
 * ══ §416/438 b2GearJoint::GetAnchorA() const  0x2e3a2c  size 64  16 条（0x2e3a2c..0x2e3a6c）
 * @func 0x2e3a2c 0x2e3a6c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e3a2c ldr r3, [r1, #0x30]
 *   @0x2e3a30 vldr s15, [r1, #96]
 *   @0x2e3a34 vldr s12, [r3, #24]
 *   @0x2e3a38 vldr s11, [r3, #20]
 *   @0x2e3a3c vmul.f32 s14, s12, s15
 *   @0x2e3a40 vldr s13, [r1, #92]
 *   @0x2e3a44 vldr s9, [r3, #16]
 *   @0x2e3a48 vldr s10, [r3, #12]
 *   @0x2e3a4c vmul.f32 s15, s11, s15
 *   @0x2e3a50 vmla.f32 s14, s13, s11
 *   @0x2e3a54 vnmls.f32 s15, s12, s13
 *   @0x2e3a58 vadd.f32 s14, s14, s9
 *   @0x2e3a5c vadd.f32 s15, s15, s10
 *   @0x2e3a60 vstr s14, [r0, #4]
 *   @0x2e3a64 vstr s15, [r0]
 *   @0x2e3a68 bx lr
 *
 * ══ §417/438 b2GearJoint::GetAnchorB() const  0x2e3a6c  size 64  16 条（0x2e3a6c..0x2e3aac）
 * @func 0x2e3a6c 0x2e3aac  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e3a6c ldr r3, [r1, #0x34]
 *   @0x2e3a70 vldr s15, [r1, #104]
 *   @0x2e3a74 vldr s12, [r3, #24]
 *   @0x2e3a78 vldr s11, [r3, #20]
 *   @0x2e3a7c vmul.f32 s14, s12, s15
 *   @0x2e3a80 vldr s13, [r1, #100]
 *   @0x2e3a84 vldr s9, [r3, #16]
 *   @0x2e3a88 vldr s10, [r3, #12]
 *   @0x2e3a8c vmul.f32 s15, s11, s15
 *   @0x2e3a90 vmla.f32 s14, s13, s11
 *   @0x2e3a94 vnmls.f32 s15, s12, s13
 *   @0x2e3a98 vadd.f32 s14, s14, s9
 *   @0x2e3a9c vadd.f32 s15, s15, s10
 *   @0x2e3aa0 vstr s14, [r0, #4]
 *   @0x2e3aa4 vstr s15, [r0]
 *   @0x2e3aa8 bx lr
 *
 * ══ §418/438 anon_2e7a2c  0x2e7a2c  size 64  16 条（0x2e7a2c..0x2e7a6c）
 * @func 0x2e7a2c 0x2e7a6c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7a2c stmdavs r3, {r2, r9, r10, lr} ^
 *   @0x2e7a30 stmvs r11!, {r0, r2, r3, r4, r9, r10, r11, sp, lr} ^
 *   @0x2e7a34 mrrcvs p8, #0xa, r6, r11, c14
 *   @0x2e7a38 ldrmi r11, [r8, r3, lsl #2]
 *   @0x2e7a3c .word 0xf7ff4620
 *   @0x2e7a40 .word 0xf8d4fd70
 *   @0x2e7a44 .word 0xb193309c
 *   @0x2e7a48 ldmdavs r2, {r1, r3, r5, r11, sp, lr}
 *   @0x2e7a4c strvc pc, [r0, #-0x412]
 *   @0x2e7a50 ldmdavs r8, {r0, r2, r8, r12, lr, pc}
 *   @0x2e7a54 ldc2 p7, c15, [r10], {255}
 *   @0x2e7a58 ldrsblo pc, [r12], r4
 *   @0x2e7a5c shadd16mi r6, r0, sp
 *   @0x2e7a60 ldrsbne pc, [r12], r4
 *   @0x2e7a64 stc2l p7, c15, [r7], #-1020
 *   @0x2e7a68 .word 0xf8c42300
 *
 * ══ §419/438 __gnu_unwind_frame  0x31aab8  size 64  16 条（0x31aab8..0x31aaf8）
 * @func 0x31aab8 0x31aaf8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __gnu_unwind_execute
 * 字段偏移 top8: 0x4×3 / 0x4c×1 / 0x8×1 / 0xc×1 / 0x7×1 / 0xd×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31aab8 push {r0, r1, r2, r3, r4, lr}
 *   @0x31aabc ldr r3, [r0, #0x4c]
 *   @0x31aac0 mov r0, r1
 *   @0x31aac4 add r1, sp, #4
 *   @0x31aac8 ldr r2, [r3, #0x4]
 *   @0x31aacc lsl r2, r2, #8
 *   @0x31aad0 str r2, [sp, #0x4]
 *   @0x31aad4 add r2, r3, #8
 *   @0x31aad8 str r2, [sp, #0x8]
 *   @0x31aadc mov r2, #3
 *   @0x31aae0 strb r2, [sp, #0xc]
 *   @0x31aae4 ldrb r3, [r3, #0x7]
 *   @0x31aae8 strb r3, [sp, #0xd]
 *   @0x31aaec bl 0x31a73c <__gnu_unwind_execute>
 *   @0x31aaf0 add sp, sp, #20
 *   @0x31aaf4 ldr pc, [sp], #4
 *
 * ══ §420/438 FT_GlyphLoader_Add  0x2e52f8  size 62  16 条（0x2e52f8..0x2e5336）
 * @func 0x2e52f8 0x2e5336  size 62  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x16×2 / 0x30×2 / 0x38×1 / 0x54×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e52f8 push {r4, r5, lr}
 *   @0x2e52fc ldrh r2, [r0, #0x16]
 *   @0x2e5300 ldrh r3, [r0, #0x38]
 *   @0x2e5304 strh r1, [r0, #0x16]
 *   @0x2e5308 sxth r4, r3
 *   @0x2e530c ldr r1, [r0, #0x30]
 *   @0x2e5310 ldr r3, [r0, #0x54]
 *   @0x2e5314 str r3, [r0, #0x30]
 *   @0x2e5318 cmp r3, r4
 *   @0x2e531c ldr r1, [r0, #0x44]
 *   @0x2e5320 ldrmi r5, [r5], #-19
 *   @0x2e5324 strh.w r5, [r1, r3, lsl #1]
 *   @0x2e5328 adds r3, #0x1
 *   @0x2e532c pop.w {r4, r5, lr}
 *   @0x2e5330 b.w 0x2e52dc <FT_GlyphLoader_Prepare>
 *   @0x2e5334 pop {r4, r5, pc}
 *
 * ══ §421/438 FT_Get_Next_Char  0x2e597e  size 62  16 条（0x2e597e..0x2e59bc）
 * @func 0x2e597e 0x2e59bc  size 62  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×3 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e597e push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e5982 mov r4, r0
 *   @0x2e5986 ldr r5, [r0, #0x5c]
 *   @0x2e598a ldr r3, [r0, #0x10]
 *   @0x2e598e add r6, sp, #0x8
 *   @0x2e5992 stmvs r11!, {r2, r8, r10, r11, r12} ^
 *   @0x2e5996 mov r0, r5
 *   @0x2e599a ldr r3, [r3, #0x10]
 *   @0x2e599e ldr r2, [r4, #0x10]
 *   @0x2e59a2 mov r3, r0
 *   @0x2e59a6 cbz r0, 0x2e59b2 <FT_Get_Next_Char+0x34>
 *   @0x2e59aa b 0x2e59b4 <FT_Get_Next_Char+0x36>
 *   @0x2e59ae b 0x2e59b2 <FT_Get_Next_Char+0x34>
 *   @0x2e59b2 mov r0, r3
 *   @0x2e59b6 str r3, [r7]
 *   @0x2e59ba pop {r4, r5, r6, r7, pc}
 *
 * ══ §422/438 FT_Stream_TryRead  0x2e69a0  size 62  16 条（0x2e69a0..0x2e69de）
 * @func 0x2e69a0 0x2e69de  size 62  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc
 * 字段偏移 top8: 0x8×3 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e69a0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2e69a4 ldr r5, [r0, #0x4]
 *   @0x2e69a8 ldr r1, [r0, #0x8]
 *   @0x2e69ac cmp r1, r5
 *   @0x2e69b0 ldr r6, [r0, #0x14]
 *   @0x2e69b4 mov r2, r7
 *   @0x2e69b8 mov r5, r0
 *   @0x2e69bc subs r5, r5, r1
 *   @0x2e69c0 cmp r2, r5
 *   @0x2e69c4 movlo r5, r2
 *   @0x2e69c8 add r1, r3
 *   @0x2e69cc blx 0xb65bc <memcpy@plt>
 *   @0x2e69d0 ldr r3, [r4, #0x8]
 *   @0x2e69d4 str r3, [r4, #0x8]
 *   @0x2e69d8 movs r5, #0x0
 *   @0x2e69dc pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §423/438 FT_New_Library  0x2e72f8  size 62  16 条（0x2e72f8..0x2e7336）
 * @func 0x2e72f8 0x2e7336  size 62  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x366f48
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e72f8 push {r0, r1, r2, r4, r5, lr}
 *   @0x2e72fc mov r5, r0
 *   @0x2e7300 cbz r1, 0x2e732c <FT_New_Library+0x34>
 *   @0x2e7304 add r2, sp, #0x4
 *   @0x2e7308 blls 0x366f48 <_ZTS12CDS_Priority+0x8fa0>
 *   @0x2e730c cbnz r3, 0x2e7330 <FT_New_Library+0x38>
 *   @0x2e7310 str r5, [r0]
 *   @0x2e7314 movs r2, #0x8
 *   @0x2e7318 addvs r3, r2, r8, lsr #1
 *   @0x2e731c movs r2, #0x1
 *   @0x2e7320 sbcvs r3, r3, r4, lsr #1
 *   @0x2e7324 str.w r2, [r0, #0xbc]
 *   @0x2e7328 str r0, [r4]
 *   @0x2e732c movs r0, #0x6
 *   @0x2e7330 mov r0, r3
 *   @0x2e7334 pop {r4, r5, pc}
 *
 * ══ §424/438 F_BUFFER_SizeOf(RValue&, CInstance*, CInstance*, int, RValue*)  0xc50b0  size 60  15 条（0xc50b0..0xc50ec）
 * @func 0xc50b0 0xc50ec  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / IBuffer::SizeOf(eBuffer_Type)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc50b0 push {r4, lr}
 *   @0xc50b4 mov r3, #0
 *   @0xc50b8 mov r1, r3
 *   @0xc50bc str r3, [r0, #0xc]
 *   @0xc50c0 mov r4, r0
 *   @0xc50c4 ldr r0, [sp, #0x8]
 *   @0xc50c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc50cc bl 0xcd100 <_ZN7IBuffer6SizeOfE12eBuffer_Type>
 *   @0xc50d0 vmov s15, r0
 *   @0xc50d4 vcvt.f64.s32 d7, s15
 *   @0xc50d8 vmov r0, r1, d7
 *   @0xc50dc vmov r2, s14
 *   @0xc50e0 mov r3, r1
 *   @0xc50e4 stm r4, {r2, r3}
 *   @0xc50e8 pop {r4, pc}
 *
 * ══ §425/438 YYGML_DeleteWithIterator(SWithIterator*, YYObjectBase**, YYObjectBase**)  0xd8230  size 60  15 条（0xd8230..0xd826c）
 * @func 0xd8230 0xd826c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8230 push {r4, r5, r6, lr}
 *   @0xd8234 mov r4, r0
 *   @0xd8238 ldr r0, [r0, #0x8]
 *   @0xd823c mov r5, r1
 *   @0xd8240 mov r6, r2
 *   @0xd8244 cmp r0, #0
 *   @0xd8248 beq 0xd8258 <_Z24YYGML_DeleteWithIteratorP13SWithIteratorPP12YYObjectBaseS3_+0x28>
 *   @0xd824c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd8250 mov r3, #0
 *   @0xd8254 str r3, [r4, #0x8]
 *   @0xd8258 ldr r3, [r4]
 *   @0xd825c str r3, [r5]
 *   @0xd8260 ldr r3, [r4, #0x4]
 *   @0xd8264 str r3, [r6]
 *   @0xd8268 pop {r4, r5, r6, pc}
 *
 * ══ §426/438 ParamSize(int)  0xec108  size 60  15 条（0xec108..0xec144）
 * @func 0xec108 0xec144  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec108 and r0, r0, #15
 *   @0xec10c cmp r0, #6
 *   @0xec110 bhi 0xec13c <_Z9ParamSizei+0x34>
 *   @0xec114 mov r3, #1
 *   @0xec118 lsl r0, r3, r0
 *   @0xec11c tst r0, #118
 *   @0xec120 beq 0xec12c <_Z9ParamSizei+0x24>
 *   @0xec124 mov r0, #4
 *   @0xec128 bx lr
 *   @0xec12c tst r0, #9
 *   @0xec130 moveq r0, #0
 *   @0xec134 movne r0, #8
 *   @0xec138 bx lr
 *   @0xec13c mov r0, #0
 *   @0xec140 bx lr
 *
 * ══ §427/438 F_MoveSnap(RValue&, CInstance*, CInstance*, int, RValue*)  0x108160  size 60  15 条（0x108160..0x10819c）
 * @func 0x108160 0x10819c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108160 push {r4, r5, r6, lr}
 *   @0x108164 mov r6, r1
 *   @0x108168 ldr r4, [sp, #0x10]
 *   @0x10816c mov r1, #0
 *   @0x108170 mov r0, r4
 *   @0x108174 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108178 mov r1, #1
 *   @0x10817c mov r5, r0
 *   @0x108180 mov r0, r4
 *   @0x108184 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108188 mov r1, r5
 *   @0x10818c mov r2, r0
 *   @0x108190 mov r0, r6
 *   @0x108194 pop {r4, r5, r6, lr}
 *   @0x108198 b 0x1c9594 <_Z12Command_SnapP9CInstanceff>
 *
 * ══ §428/438 F_MotionAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x108560  size 60  15 条（0x108560..0x10859c）
 * @func 0x108560 0x10859c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108560 push {r4, r5, r6, lr}
 *   @0x108564 mov r6, r1
 *   @0x108568 ldr r4, [sp, #0x10]
 *   @0x10856c mov r1, #0
 *   @0x108570 mov r0, r4
 *   @0x108574 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108578 mov r1, #1
 *   @0x10857c mov r5, r0
 *   @0x108580 mov r0, r4
 *   @0x108584 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108588 mov r1, r5
 *   @0x10858c mov r2, r0
 *   @0x108590 mov r0, r6
 *   @0x108594 pop {r4, r5, r6, lr}
 *   @0x108598 b 0x193ec0 <_ZN9CInstance11AddTo_SpeedEff>
 *
 * ══ §429/438 F_InstanceChange(RValue&, CInstance*, CInstance*, int, RValue*)  0x10993c  size 60  15 条（0x10993c..0x109978）
 * @func 0x10993c 0x109978  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10993c push {r4, r5, r6, lr}
 *   @0x109940 mov r6, r1
 *   @0x109944 ldr r4, [sp, #0x10]
 *   @0x109948 mov r1, #0
 *   @0x10994c mov r0, r4
 *   @0x109950 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109954 mov r1, #1
 *   @0x109958 mov r5, r0
 *   @0x10995c mov r0, r4
 *   @0x109960 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x109964 mov r1, r5
 *   @0x109968 mov r2, r0
 *   @0x10996c mov r0, r6
 *   @0x109970 pop {r4, r5, r6, lr}
 *   @0x109974 b 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib>
 *
 * ══ §430/438 F_Round(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e2d8  size 60  15 条（0x10e2d8..0x10e314）
 * @func 0x10e2d8 0x10e314  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb66e8
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e2d8 push {r4, lr}
 *   @0x10e2dc mov r3, #0
 *   @0x10e2e0 mov r1, r3
 *   @0x10e2e4 str r3, [r0, #0xc]
 *   @0x10e2e8 mov r4, r0
 *   @0x10e2ec ldr r0, [sp, #0x8]
 *   @0x10e2f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e2f4 bl 0xb66e8 <lrint@plt>
 *   @0x10e2f8 vmov s15, r0
 *   @0x10e2fc vcvt.f64.s32 d7, s15
 *   @0x10e300 vmov r0, r1, d7
 *   @0x10e304 vmov r2, s14
 *   @0x10e308 mov r3, r1
 *   @0x10e30c stm r4, {r2, r3}
 *   @0x10e310 pop {r4, pc}
 *
 * ══ §431/438 F_DateSetTimezone(RValue&, CInstance*, CInstance*, int, RValue*)  0x1147ac  size 60  15 条（0x1147ac..0x1147e8）
 * @func 0x1147ac 0x1147e8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f2140
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1147ac push {r3, lr}
 *   @0x1147b0 mov r3, #0
 *   @0x1147b4 mov r1, r3
 *   @0x1147b8 str r3, [r0, #0xc]
 *   @0x1147bc str r3, [r0]
 *   @0x1147c0 str r3, [r0, #0x4]
 *   @0x1147c4 ldr r0, [sp, #0x8]
 *   @0x1147c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1147cc ldr r3, [pc, #0x10]
 *   @0x1147d0 add r3, pc, r3
 *   @0x1147d4 rsbs r0, r0, #1
 *   @0x1147d8 movlo r0, #0
 *   @0x1147dc strb r0, [r3]
 *   @0x1147e0 pop {r3, pc}
 *   @0x1147e4 eoreq sp, sp, r8, ror #18
 *
 * ══ §432/438 F_AlarmSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x115e08  size 60  15 条（0x115e08..0x115e44）
 * @func 0x115e08 0x115e44  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115e08 push {r4, r5, r6, lr}
 *   @0x115e0c mov r6, r1
 *   @0x115e10 ldr r4, [sp, #0x10]
 *   @0x115e14 mov r1, #0
 *   @0x115e18 mov r0, r4
 *   @0x115e1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115e20 mov r1, #1
 *   @0x115e24 mov r5, r0
 *   @0x115e28 mov r0, r4
 *   @0x115e2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115e30 mov r1, r5
 *   @0x115e34 mov r2, r0
 *   @0x115e38 mov r0, r6
 *   @0x115e3c pop {r4, r5, r6, lr}
 *   @0x115e40 b 0x193148 <_ZN9CInstance8SetTimerEii>
 *
 * ══ §433/438 F_WindowViewMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a80c  size 60  15 条（0x11a80c..0x11a848）
 * @func 0x11a80c 0x11a848  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GR_Window_View_Mouse_Get_X(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a80c push {r4, lr}
 *   @0x11a810 mov r3, #0
 *   @0x11a814 mov r1, r3
 *   @0x11a818 str r3, [r0, #0xc]
 *   @0x11a81c mov r4, r0
 *   @0x11a820 ldr r0, [sp, #0x8]
 *   @0x11a824 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a828 bl 0x17aa2c <_Z26GR_Window_View_Mouse_Get_Xi>
 *   @0x11a82c vmov s15, r0
 *   @0x11a830 vcvt.f64.s32 d7, s15
 *   @0x11a834 vmov r0, r1, d7
 *   @0x11a838 vmov r2, s14
 *   @0x11a83c mov r3, r1
 *   @0x11a840 stm r4, {r2, r3}
 *   @0x11a844 pop {r4, pc}
 *
 * ══ §434/438 F_WindowViewMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a848  size 60  15 条（0x11a848..0x11a884）
 * @func 0x11a848 0x11a884  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GR_Window_View_Mouse_Get_Y(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a848 push {r4, lr}
 *   @0x11a84c mov r3, #0
 *   @0x11a850 mov r1, r3
 *   @0x11a854 str r3, [r0, #0xc]
 *   @0x11a858 mov r4, r0
 *   @0x11a85c ldr r0, [sp, #0x8]
 *   @0x11a860 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a864 bl 0x17aa70 <_Z26GR_Window_View_Mouse_Get_Yi>
 *   @0x11a868 vmov s15, r0
 *   @0x11a86c vcvt.f64.s32 d7, s15
 *   @0x11a870 vmov r0, r1, d7
 *   @0x11a874 vmov r2, s14
 *   @0x11a878 mov r3, r1
 *   @0x11a87c stm r4, {r2, r3}
 *   @0x11a880 pop {r4, pc}
 *
 * ══ §435/438 F_TextureGetWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bbe4  size 60  15 条（0x11bbe4..0x11bc20）
 * @func 0x11bbe4 0x11bc20  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetPtrOrInt(RValue const*, int) / GR_Texture_Get_Width(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bbe4 push {r4, lr}
 *   @0x11bbe8 mov r3, #0
 *   @0x11bbec mov r1, r3
 *   @0x11bbf0 str r3, [r0, #0xc]
 *   @0x11bbf4 mov r4, r0
 *   @0x11bbf8 ldr r0, [sp, #0x8]
 *   @0x11bbfc bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x11bc00 bl 0x1741f8 <_Z20GR_Texture_Get_Widthi>
 *   @0x11bc04 vmov s15, r0
 *   @0x11bc08 vcvt.f64.f32 d7, s15
 *   @0x11bc0c vmov r0, r1, d7
 *   @0x11bc10 vmov r2, s14
 *   @0x11bc14 mov r3, r1
 *   @0x11bc18 stm r4, {r2, r3}
 *   @0x11bc1c pop {r4, pc}
 *
 * ══ §436/438 F_TextureGetHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bc20  size 60  15 条（0x11bc20..0x11bc5c）
 * @func 0x11bc20 0x11bc5c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetPtrOrInt(RValue const*, int) / GR_Texture_Get_Height(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bc20 push {r4, lr}
 *   @0x11bc24 mov r3, #0
 *   @0x11bc28 mov r1, r3
 *   @0x11bc2c str r3, [r0, #0xc]
 *   @0x11bc30 mov r4, r0
 *   @0x11bc34 ldr r0, [sp, #0x8]
 *   @0x11bc38 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x11bc3c bl 0x174240 <_Z21GR_Texture_Get_Heighti>
 *   @0x11bc40 vmov s15, r0
 *   @0x11bc44 vcvt.f64.f32 d7, s15
 *   @0x11bc48 vmov r0, r1, d7
 *   @0x11bc4c vmov r2, s14
 *   @0x11bc50 mov r3, r1
 *   @0x11bc54 stm r4, {r2, r3}
 *   @0x11bc58 pop {r4, pc}
 *
 * ══ §437/438 F_SurfaceGetWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c940  size 60  15 条（0x11c940..0x11c97c）
 * @func 0x11c940 0x11c97c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GR_Surface_Get_Width(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c940 push {r4, lr}
 *   @0x11c944 mov r3, #0
 *   @0x11c948 mov r1, r3
 *   @0x11c94c str r3, [r0, #0xc]
 *   @0x11c950 mov r4, r0
 *   @0x11c954 ldr r0, [sp, #0x8]
 *   @0x11c958 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c95c bl 0x1714d4 <_Z20GR_Surface_Get_Widthi>
 *   @0x11c960 vmov s15, r0
 *   @0x11c964 vcvt.f64.s32 d7, s15
 *   @0x11c968 vmov r0, r1, d7
 *   @0x11c96c vmov r2, s14
 *   @0x11c970 mov r3, r1
 *   @0x11c974 stm r4, {r2, r3}
 *   @0x11c978 pop {r4, pc}
 *
 * ══ §438/438 CBackground::Smooth()  0xc2d90  size 8  2 条（0xc2d90..0xc2d98）
 * @func 0xc2d90 0xc2d98  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2d90 ldrb r0, [r0, #0x9]
 *   @0xc2d94 bx lr
 */
