/* cally 逆向卡：All_63 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 321 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/321 F_ActionSpriteSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d8e0  size 100  25 条（0x13d8e0..0x13d944）
 * @func 0x13d8e0 0x13d944  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_SetSprite(CInstance*, int)
 * 字段偏移 top8: 0x18×1 / 0x94×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d8e0 push {r4, r5, r6, lr}
 *   @0x13d8e4 vpush {d8}
 *   @0x13d8e8 mov r5, r1
 *   @0x13d8ec ldr r4, [sp, #0x18]
 *   @0x13d8f0 mov r1, #0
 *   @0x13d8f4 mov r0, r4
 *   @0x13d8f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d8fc mov r1, #1
 *   @0x13d900 mov r6, r0
 *   @0x13d904 mov r0, r4
 *   @0x13d908 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d90c mov r1, #2
 *   @0x13d910 vmov s16, r0
 *   @0x13d914 mov r0, r4
 *   @0x13d918 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d91c mov r1, r6
 *   @0x13d920 mov r4, r0
 *   @0x13d924 mov r0, r5
 *   @0x13d928 bl 0x1c9dbc <_Z17Command_SetSpriteP9CInstancei>
 *   @0x13d92c vcmpe.f32 s16, #0
 *   @0x13d930 str r4, [r5, #0x94]
 *   @0x13d934 vmrs APSR_nzcv, fpscr
 *   @0x13d938 vstrge s16, [r5, #144]
 *   @0x13d93c vpop {d8}
 *   @0x13d940 pop {r4, r5, r6, pc}
 *
 * ══ §2/321 F_ActionPartEmitDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1400a0  size 100  25 条（0x1400a0..0x140104）
 * @func 0x1400a0 0x140104  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_ActionPartEmitDestroy(RValue&, CInstance*, CInstance*, int, RValue*)+0x48 / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x10×1 / 0x44×1 / 0x30×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1400a0 push {r3, r4, r5, lr}
 *   @0x1400a4 mov r1, #0
 *   @0x1400a8 ldr r0, [sp, #0x10]
 *   @0x1400ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1400b0 ldr r4, [pc, #0x44]
 *   @0x1400b4 ldr r4, [pc, r4]
 *   @0x1400b8 ldr r3, [r4]
 *   @0x1400bc cmp r3, #0
 *   @0x1400c0 mov r5, r0
 *   @0x1400c4 blt 0x1400e8 <_Z23F_ActionPartEmitDestroyR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1400c8 ldr r3, [pc, #0x30]
 *   @0x1400cc ldr r3, [pc, r3]
 *   @0x1400d0 ldr r1, [r3, r5, lsl #2]
 *   @0x1400d4 cmp r1, #0
 *   @0x1400d8 poplt {r3, r4, r5, pc}
 *   @0x1400dc ldr r0, [r4]
 *   @0x1400e0 pop {r3, r4, r5, lr}
 *   @0x1400e4 b 0x1a38ac <_Z30ParticleSystem_Emitter_Destroyii>
 *   @0x1400e8 mvn r0, #0
 *   @0x1400ec mov r1, #1
 *   @0x1400f0 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x1400f4 str r0, [r4]
 *   @0x1400f8 b 0x1400c8 <_Z23F_ActionPartEmitDestroyR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1400fc eoreq pc, r10, r8, lsr #6
 *   @0x140100 eoreq pc, r10, r8, lsl r3
 *
 * ══ §3/321 F_GPUGetZFunc(RValue&, CInstance*, CInstance*, int, RValue*)  0x147dc8  size 100  25 条（0x147dc8..0x147e2c）
 * @func 0x147dc8 0x147e2c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147dc8 cmp r3, #0
 *   @0x147dcc mov r1, #0
 *   @0x147dd0 push {r4, lr}
 *   @0x147dd4 mov r4, r0
 *   @0x147dd8 str r1, [r0, #0xc]
 *   @0x147ddc str r1, [r0]
 *   @0x147de0 str r1, [r0, #0x4]
 *   @0x147de4 bne 0x147e14 <_Z13F_GPUGetZFuncR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x147de8 ldr r0, [pc, #0x34]
 *   @0x147dec mov r1, #9
 *   @0x147df0 ldr r0, [pc, r0]
 *   @0x147df4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147df8 vmov s15, r0
 *   @0x147dfc vcvt.f64.u32 d7, s15
 *   @0x147e00 vmov r0, r1, d7
 *   @0x147e04 vmov r2, s14
 *   @0x147e08 mov r3, r1
 *   @0x147e0c stm r4, {r2, r3}
 *   @0x147e10 pop {r4, pc}
 *   @0x147e14 ldr r0, [pc, #0xc]
 *   @0x147e18 pop {r4, lr}
 *   @0x147e1c add r0, pc, r0
 *   @0x147e20 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147e24 eoreq r5, r10, r8, lsl #30
 *   @0x147e28 andseq r10, pc, r12, lsl #2
 *
 * ══ §4/321 F_GPUGetCullmode(RValue&, CInstance*, CInstance*, int, RValue*)  0x147e98  size 100  25 条（0x147e98..0x147efc）
 * @func 0x147e98 0x147efc  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147e98 cmp r3, #0
 *   @0x147e9c mov r1, #0
 *   @0x147ea0 push {r4, lr}
 *   @0x147ea4 mov r4, r0
 *   @0x147ea8 str r1, [r0, #0xc]
 *   @0x147eac str r1, [r0]
 *   @0x147eb0 str r1, [r0, #0x4]
 *   @0x147eb4 bne 0x147ee4 <_Z16F_GPUGetCullmodeR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x147eb8 ldr r0, [pc, #0x34]
 *   @0x147ebc mov r1, #8
 *   @0x147ec0 ldr r0, [pc, r0]
 *   @0x147ec4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147ec8 vmov s15, r0
 *   @0x147ecc vcvt.f64.u32 d7, s15
 *   @0x147ed0 vmov r0, r1, d7
 *   @0x147ed4 vmov r2, s14
 *   @0x147ed8 mov r3, r1
 *   @0x147edc stm r4, {r2, r3}
 *   @0x147ee0 pop {r4, pc}
 *   @0x147ee4 ldr r0, [pc, #0xc]
 *   @0x147ee8 pop {r4, lr}
 *   @0x147eec add r0, pc, r0
 *   @0x147ef0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147ef4 eoreq r5, r10, r8, lsr lr
 *   @0x147ef8 andseq r10, pc, r4, lsr #1
 *
 * ══ §5/321 F_GPUGetBlendModeSrc(RValue&, CInstance*, CInstance*, int, RValue*)  0x148180  size 100  25 条（0x148180..0x1481e4）
 * @func 0x148180 0x1481f4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148180 cmp r3, #0
 *   @0x148184 mov r1, #0
 *   @0x148188 push {r4, lr}
 *   @0x14818c mov r4, r0
 *   @0x148190 str r1, [r0, #0xc]
 *   @0x148194 str r1, [r0]
 *   @0x148198 str r1, [r0, #0x4]
 *   @0x14819c bne 0x1481cc <_Z20F_GPUGetBlendModeSrcR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x1481a0 ldr r0, [pc, #0x34]
 *   @0x1481a4 mov r1, #6
 *   @0x1481a8 ldr r0, [pc, r0]
 *   @0x1481ac bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x1481b0 vmov s15, r0
 *   @0x1481b4 vcvt.f64.u32 d7, s15
 *   @0x1481b8 vmov r0, r1, d7
 *   @0x1481bc vmov r2, s14
 *   @0x1481c0 mov r3, r1
 *   @0x1481c4 stm r4, {r2, r3}
 *   @0x1481c8 pop {r4, pc}
 *   @0x1481cc ldr r0, [pc, #0xc]
 *   @0x1481d0 pop {r4, lr}
 *   @0x1481d4 add r0, pc, r0
 *   @0x1481d8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1481dc eoreq r5, r10, r0, asr r11
 *   @0x1481e0 mulseq pc, r12, lr
 *
 * ══ §6/321 F_GPUGetBlendModeDest(RValue&, CInstance*, CInstance*, int, RValue*)  0x1481e4  size 100  25 条（0x1481e4..0x148248）
 * @func 0x1481e4 0x148258  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1481e4 cmp r3, #0
 *   @0x1481e8 mov r1, #0
 *   @0x1481ec push {r4, lr}
 *   @0x1481f0 mov r4, r0
 *   @0x1481f4 str r1, [r0, #0xc]
 *   @0x1481f8 str r1, [r0]
 *   @0x1481fc str r1, [r0, #0x4]
 *   @0x148200 bne 0x148230 <_Z21F_GPUGetBlendModeDestR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x148204 ldr r0, [pc, #0x34]
 *   @0x148208 mov r1, #7
 *   @0x14820c ldr r0, [pc, r0]
 *   @0x148210 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x148214 vmov s15, r0
 *   @0x148218 vcvt.f64.u32 d7, s15
 *   @0x14821c vmov r0, r1, d7
 *   @0x148220 vmov r2, s14
 *   @0x148224 mov r3, r1
 *   @0x148228 stm r4, {r2, r3}
 *   @0x14822c pop {r4, pc}
 *   @0x148230 ldr r0, [pc, #0xc]
 *   @0x148234 pop {r4, lr}
 *   @0x148238 add r0, pc, r0
 *   @0x14823c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148240 eoreq r5, r10, r12, ror #21
 *   @0x148244 andseq r9, pc, r0, ror lr
 *
 * ══ §7/321 F_GPUGetBlendModeSrcAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x148248  size 100  25 条（0x148248..0x1482ac）
 * @func 0x148248 0x1482bc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148248 cmp r3, #0
 *   @0x14824c mov r1, #0
 *   @0x148250 push {r4, lr}
 *   @0x148254 mov r4, r0
 *   @0x148258 str r1, [r0, #0xc]
 *   @0x14825c str r1, [r0]
 *   @0x148260 str r1, [r0, #0x4]
 *   @0x148264 bne 0x148294 <_Z25F_GPUGetBlendModeSrcAlphaR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x148268 ldr r0, [pc, #0x34]
 *   @0x14826c mov r1, #34
 *   @0x148270 ldr r0, [pc, r0]
 *   @0x148274 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x148278 vmov s15, r0
 *   @0x14827c vcvt.f64.u32 d7, s15
 *   @0x148280 vmov r0, r1, d7
 *   @0x148284 vmov r2, s14
 *   @0x148288 mov r3, r1
 *   @0x14828c stm r4, {r2, r3}
 *   @0x148290 pop {r4, pc}
 *   @0x148294 ldr r0, [pc, #0xc]
 *   @0x148298 pop {r4, lr}
 *   @0x14829c add r0, pc, r0
 *   @0x1482a0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1482a4 eoreq r5, r10, r8, lsl #21
 *   @0x1482a8 andseq r9, pc, r4, asr #28
 *
 * ══ §8/321 F_GPUGetBlendModeDestAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1482ac  size 100  25 条（0x1482ac..0x148310）
 * @func 0x1482ac 0x148310  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1482ac cmp r3, #0
 *   @0x1482b0 mov r1, #0
 *   @0x1482b4 push {r4, lr}
 *   @0x1482b8 mov r4, r0
 *   @0x1482bc str r1, [r0, #0xc]
 *   @0x1482c0 str r1, [r0]
 *   @0x1482c4 str r1, [r0, #0x4]
 *   @0x1482c8 bne 0x1482f8 <_Z26F_GPUGetBlendModeDestAlphaR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x1482cc ldr r0, [pc, #0x34]
 *   @0x1482d0 mov r1, #35
 *   @0x1482d4 ldr r0, [pc, r0]
 *   @0x1482d8 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x1482dc vmov s15, r0
 *   @0x1482e0 vcvt.f64.u32 d7, s15
 *   @0x1482e4 vmov r0, r1, d7
 *   @0x1482e8 vmov r2, s14
 *   @0x1482ec mov r3, r1
 *   @0x1482f0 stm r4, {r2, r3}
 *   @0x1482f4 pop {r4, pc}
 *   @0x1482f8 ldr r0, [pc, #0xc]
 *   @0x1482fc pop {r4, lr}
 *   @0x148300 add r0, pc, r0
 *   @0x148304 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148308 eoreq r5, r10, r4, lsr #20
 *   @0x14830c andseq r9, pc, r12, lsl lr
 *
 * ══ §9/321 F_GPUGetAlphaTestRef(RValue&, CInstance*, CInstance*, int, RValue*)  0x14842c  size 100  25 条（0x14842c..0x148490）
 * @func 0x14842c 0x1484a0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14842c cmp r3, #0
 *   @0x148430 mov r1, #0
 *   @0x148434 push {r4, lr}
 *   @0x148438 mov r4, r0
 *   @0x14843c str r1, [r0, #0xc]
 *   @0x148440 str r1, [r0]
 *   @0x148444 str r1, [r0, #0x4]
 *   @0x148448 bne 0x148478 <_Z20F_GPUGetAlphaTestRefR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14844c ldr r0, [pc, #0x34]
 *   @0x148450 mov r1, #10
 *   @0x148454 ldr r0, [pc, r0]
 *   @0x148458 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x14845c vmov s15, r0
 *   @0x148460 vcvt.f64.u32 d7, s15
 *   @0x148464 vmov r0, r1, d7
 *   @0x148468 vmov r2, s14
 *   @0x14846c mov r3, r1
 *   @0x148470 stm r4, {r2, r3}
 *   @0x148474 pop {r4, pc}
 *   @0x148478 ldr r0, [pc, #0xc]
 *   @0x14847c pop {r4, lr}
 *   @0x148480 add r0, pc, r0
 *   @0x148484 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148488 eoreq r5, r10, r4, lsr #17
 *   @0x14848c andseq r9, pc, r4, asr sp
 *
 * ══ §10/321 F_GPUGetAlphaTestFunc(RValue&, CInstance*, CInstance*, int, RValue*)  0x148490  size 100  25 条（0x148490..0x1484f4）
 * @func 0x148490 0x1484f4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148490 cmp r3, #0
 *   @0x148494 mov r1, #0
 *   @0x148498 push {r4, lr}
 *   @0x14849c mov r4, r0
 *   @0x1484a0 str r1, [r0, #0xc]
 *   @0x1484a4 str r1, [r0]
 *   @0x1484a8 str r1, [r0, #0x4]
 *   @0x1484ac bne 0x1484dc <_Z21F_GPUGetAlphaTestFuncR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x1484b0 ldr r0, [pc, #0x34]
 *   @0x1484b4 mov r1, #11
 *   @0x1484b8 ldr r0, [pc, r0]
 *   @0x1484bc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x1484c0 vmov s15, r0
 *   @0x1484c4 vcvt.f64.u32 d7, s15
 *   @0x1484c8 vmov r0, r1, d7
 *   @0x1484cc vmov r2, s14
 *   @0x1484d0 mov r3, r1
 *   @0x1484d4 stm r4, {r2, r3}
 *   @0x1484d8 pop {r4, pc}
 *   @0x1484dc ldr r0, [pc, #0xc]
 *   @0x1484e0 pop {r4, lr}
 *   @0x1484e4 add r0, pc, r0
 *   @0x1484e8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1484ec eoreq r5, r10, r0, asr #16
 *   @0x1484f0 andseq r9, pc, r8, lsr #26
 *
 * ══ §11/321 SGamepadMapping::SGamepadMapping(char const*, char const*)  0x15272c  size 100  25 条（0x15272c..0x152790）
 * @func 0x15272c 0x152790  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)×2
 * 字段偏移 top8: 0x4×1 / 0xc×1 / 0x8×1 / 0x-c×1 / 0x-14×1 / 0x-10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15272c push {r4, r5, r6, lr}
 *   @0x152730 mov r4, r0
 *   @0x152734 mov r5, #0
 *   @0x152738 mov r0, r1
 *   @0x15273c str r5, [r4]
 *   @0x152740 mov r6, r2
 *   @0x152744 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x152748 str r0, [r4, #0x4]
 *   @0x15274c mov r0, r6
 *   @0x152750 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x152754 mvn r6, #0
 *   @0x152758 add r3, r4, #28
 *   @0x15275c add r12, r4, #280
 *   @0x152760 mov r1, r5
 *   @0x152764 mov r2, r6
 *   @0x152768 str r6, [r4, #0xc]
 *   @0x15276c str r0, [r4, #0x8]
 *   @0x152770 str r1, [r3, #-0xc]
 *   @0x152774 add r3, r3, #12
 *   @0x152778 str r2, [r3, #-0x14]
 *   @0x15277c str r2, [r3, #-0x10]
 *   @0x152780 cmp r3, r12
 *   @0x152784 bne 0x152770 <_ZN15SGamepadMappingC2EPKcS1_+0x44>
 *   @0x152788 mov r0, r4
 *   @0x15278c pop {r4, r5, r6, pc}
 *
 * ══ §12/321 F_ApplicationGetPos(RValue&, CInstance*, CInstance*, int, RValue*)  0x158980  size 100  25 条（0x158980..0x1589e4）
 * @func 0x158980 0x1589e4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Get_FullScreenOffset(int&, int&, int&, int&) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 无
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158980 push {r4, lr}
 *   @0x158984 sub sp, sp, #40
 *   @0x158988 mov r4, r0
 *   @0x15898c add r1, sp, #28
 *   @0x158990 add r0, sp, #24
 *   @0x158994 add r2, sp, #32
 *   @0x158998 add r3, sp, #36
 *   @0x15899c bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x1589a0 vldr s11, [sp, #28]
 *   @0x1589a4 vcvt.f64.s32 d7, s11
 *   @0x1589a8 vldr s11, [sp, #32]
 *   @0x1589ac mov r0, r4
 *   @0x1589b0 mov r1, #4
 *   @0x1589b4 vcvt.f64.s32 d6, s11
 *   @0x1589b8 vstr d7, [sp]
 *   @0x1589bc vldr s11, [sp, #36]
 *   @0x1589c0 vcvt.f64.s32 d7, s11
 *   @0x1589c4 vstr d6, [sp, #8]
 *   @0x1589c8 vstr d7, [sp, #16]
 *   @0x1589cc vldr s15, [sp, #24]
 *   @0x1589d0 vcvt.f64.s32 d7, s15
 *   @0x1589d4 vmov r2, r3, d7
 *   @0x1589d8 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x1589dc add sp, sp, #40
 *   @0x1589e0 pop {r4, pc}
 *
 * ══ §13/321 Achievement_Show(int, char*, int)  0x16100c  size 100  25 条（0x16100c..0x161070）
 * @func 0x16100c 0x161070  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16100c push {r4, r5, r6, lr}
 *   @0x161010 sub sp, sp, #8
 *   @0x161014 mov r5, r2
 *   @0x161018 mov r6, r0
 *   @0x16101c mov r4, r1
 *   @0x161020 bl 0x290274 <getJNIEnv>
 *   @0x161024 mov r1, r4
 *   @0x161028 ldr r3, [r0]
 *   @0x16102c ldr r3, [r3, #0x29c]
 *   @0x161030 blx r3
 *   @0x161034 mov r4, r0
 *   @0x161038 bl 0x290274 <getJNIEnv>
 *   @0x16103c ldr r1, [pc, #0x24]
 *   @0x161040 mov r3, r6
 *   @0x161044 ldr r12, [pc, #0x20]
 *   @0x161048 ldr r1, [pc, r1]
 *   @0x16104c ldr r12, [pc, r12]
 *   @0x161050 ldr r1, [r1]
 *   @0x161054 ldr r2, [r12]
 *   @0x161058 stm sp, {r4, r5}
 *   @0x16105c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161060 add sp, sp, #8
 *   @0x161064 pop {r4, r5, r6, pc}
 *   @0x161068 eoreq r12, r8, r12, asr r9
 *   @0x16106c eoreq lr, r8, r4, ror #29
 *
 * ══ §14/321 GR_3D_Transform_Add_Rotation_Axis(float, float, float, float)  0x163a9c  size 100  25 条（0x163a9c..0x163b00）
 * @func 0x163a9c 0x163b00  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::CreateRotationAxis(yyMatrix*, yyVector3*, float) / Graphics::GetMatrix(eMatrix, float*) / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163a9c push {r4, r5, lr}
 *   @0x163aa0 sub sp, sp, #212
 *   @0x163aa4 add r4, sp, #80
 *   @0x163aa8 add r5, sp, #16
 *   @0x163aac str r0, [sp, #0x4]
 *   @0x163ab0 str r1, [sp, #0x8]
 *   @0x163ab4 mov r0, r4
 *   @0x163ab8 str r2, [sp, #0xc]
 *   @0x163abc add r1, sp, #4
 *   @0x163ac0 eor r2, r3, #-2147483648
 *   @0x163ac4 bl 0x27a8b8 <_ZN8yyMatrix18CreateRotationAxisEPS_P9yyVector3f>
 *   @0x163ac8 mov r1, r5
 *   @0x163acc mov r0, #2
 *   @0x163ad0 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x163ad4 mov r2, r4
 *   @0x163ad8 add r4, sp, #144
 *   @0x163adc mov r1, r5
 *   @0x163ae0 mov r0, r4
 *   @0x163ae4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x163ae8 mov r1, r4
 *   @0x163aec mov r0, #2
 *   @0x163af0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163af4 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163af8 add sp, sp, #212
 *   @0x163afc pop {r4, r5, pc}
 *
 * ══ §15/321 GR_Texture_Add(void*, int, int)  0x173bb4  size 100  25 条（0x173bb4..0x173c18）
 * @func 0x173bb4 0x173c18  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocTexture()
 * 字段偏移 top8: 0x4×2 / 0x3c×1 / 0x2×1 / 0x6×1 / 0x10×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173bb4 push {r4, r5, r6, lr}
 *   @0x173bb8 mov r5, r1
 *   @0x173bbc mov r4, r2
 *   @0x173bc0 mov r6, r0
 *   @0x173bc4 bl 0x173944 <_Z12AllocTexturev>
 *   @0x173bc8 vmov s12, r5
 *   @0x173bcc vmov.f32 s15, #1.000000e+00
 *   @0x173bd0 ldr r3, [pc, #0x3c]
 *   @0x173bd4 mov r2, #1
 *   @0x173bd8 ldr r3, [pc, r3]
 *   @0x173bdc ldr r3, [r3, #0x4]
 *   @0x173be0 vcvt.f32.s32 s14, s12
 *   @0x173be4 vmov s12, r4
 *   @0x173be8 vcvt.f32.s32 s13, s12
 *   @0x173bec vdiv.f32 s14, s15, s14
 *   @0x173bf0 ldr r3, [r3, r0, lsl #2]
 *   @0x173bf4 str r6, [r3]
 *   @0x173bf8 strh r5, [r3, #4]
 *   @0x173bfc strh r4, [r3, #6]
 *   @0x173c00 strb r2, [r3, #0x10]
 *   @0x173c04 vdiv.f32 s15, s15, s13
 *   @0x173c08 vstr s14, [r3, #8]
 *   @0x173c0c vstr s15, [r3, #12]
 *   @0x173c10 pop {r4, r5, r6, pc}
 *   @0x173c14 eoreq r9, r7, r4, asr #26
 *
 * ══ §16/321 GR_Texture_Create_Direct(CBitmap32*)  0x173e70  size 100  25 条（0x173e70..0x173ed4）
 * @func 0x173e70 0x173ed4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::GetWidth()×2 / CBitmap32::GetHeight()×2 / CBitmap32::GetData()
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173e70 push {r4, r5, r6, r7, r8, lr}
 *   @0x173e74 subs r4, r0, #0
 *   @0x173e78 beq 0x173ecc <_Z24GR_Texture_Create_DirectP9CBitmap32+0x5c>
 *   @0x173e7c bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x173e80 mov r5, r0
 *   @0x173e84 mov r0, r4
 *   @0x173e88 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x173e8c mov r7, r0
 *   @0x173e90 mov r0, r4
 *   @0x173e94 bl 0x167970 <_ZN9CBitmap327GetDataEv>
 *   @0x173e98 ldr r8, [r0, #0x4]
 *   @0x173e9c mov r0, r4
 *   @0x173ea0 bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x173ea4 mov r6, r0
 *   @0x173ea8 mov r0, r4
 *   @0x173eac bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x173eb0 mov r2, r8
 *   @0x173eb4 mov r1, r7
 *   @0x173eb8 mul r3, r0, r6
 *   @0x173ebc mov r0, r5
 *   @0x173ec0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x173ec4 lsl r3, r3, #2
 *   @0x173ec8 b 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj>
 *   @0x173ecc mvn r0, #0
 *   @0x173ed0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §17/321 GR_Texture_Set(int)  0x1742f8  size 100  25 条（0x1742f8..0x17435c）
 * @func 0x1742f8 0x17435c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x174314→0x48ffe4, 0x174328→0x48ffec, 0x17432c→0x48ffe4
 * 调用序列: GR_Texture_Exists(int)
 * 字段偏移 top8: 0x44×1 / 0x38×1 / 0x28×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1742f8 push {r4, lr}
 *   @0x1742fc mov r4, r0
 *   @0x174300 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x174304 ldr r3, [pc, #0x44]
 *   @0x174308 add r3, pc, r3
 *   @0x17430c subs r1, r0, #0
 *   @0x174310 bne 0x174328 <_Z14GR_Texture_Seti+0x30>
 *   @0x174314 ldr r2, [pc, #0x38]
 *   @0x174318 pop {r4, lr}
 *   @0x17431c ldr r3, [r3, r2]
 *   @0x174320 ldr r0, [r3]
 *   @0x174324 b 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x174328 ldr r1, [pc, #0x28]
 *   @0x17432c ldr r2, [pc, #0x20]
 *   @0x174330 ldr r1, [r3, r1]
 *   @0x174334 ldr r2, [r3, r2]
 *   @0x174338 ldr r3, [r1, #0x4]
 *   @0x17433c ldr r0, [r2]
 *   @0x174340 ldr r3, [r3, r4, lsl #2]
 *   @0x174344 pop {r4, lr}
 *   @0x174348 ldr r1, [r3]
 *   @0x17434c b 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x174350 eoreq sp, r7, r8, asr #18
 *   @0x174354 .word 0xffffe4d4
 *   @0x174358 .word 0xffffbccc
 *
 * ══ §18/321 anon_1891d4  0x1891d4  size 100  25 条（0x1891d4..0x189238）
 * @func 0x1891d4 0x189238  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_get_io_ptr×2 / 0xb65bc×2
 * 字段偏移 top8: 0x4×6
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1891d4 push {r4, r5, r6, lr}
 *   @0x1891d8 mov r6, r1
 *   @0x1891dc mov r5, r2
 *   @0x1891e0 blx 0x2a5f20 <png_get_io_ptr>
 *   @0x1891e4 mov r2, r5
 *   @0x1891e8 mov r4, r0
 *   @0x1891ec mov r0, r6
 *   @0x1891f0 ldr r1, [r4, #0x4]
 *   @0x1891f4 bl 0xb65bc <memcpy@plt>
 *   @0x1891f8 ldr r3, [r4, #0x4]
 *   @0x1891fc add r5, r3, r5
 *   @0x189200 str r5, [r4, #0x4]
 *   @0x189204 pop {r4, r5, r6, pc}
 *   @0x189208 push {r4, r5, r6, lr}
 *   @0x18920c mov r6, r1
 *   @0x189210 mov r5, r2
 *   @0x189214 blx 0x2a5f20 <png_get_io_ptr>
 *   @0x189218 mov r2, r5
 *   @0x18921c mov r4, r0
 *   @0x189220 mov r0, r6
 *   @0x189224 ldr r1, [r4, #0x4]
 *   @0x189228 bl 0xb65bc <memcpy@plt>
 *   @0x18922c ldr r3, [r4, #0x4]
 *   @0x189230 add r5, r3, r5
 *   @0x189234 str r5, [r4, #0x4]
 *
 * ══ §19/321 LoadSave::ReadBundleFile(char const*, int*)  0x18f848  size 100  25 条（0x18f848..0x18f8ac）
 * @func 0x18f848 0x18f8bc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetBundleFileName(char*, int, char const*) / LoadSave::_ReadFile(char const*, int*) / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f848 push {r4, r5, r6, lr}
 *   @0x18f84c sub sp, sp, #2048
 *   @0x18f850 ldr r4, [pc, #0x50]
 *   @0x18f854 sub sp, sp, #8
 *   @0x18f858 add r5, sp, #4
 *   @0x18f85c mov r2, r0
 *   @0x18f860 ldr r4, [pc, r4]
 *   @0x18f864 mov r6, r1
 *   @0x18f868 mov r0, r5
 *   @0x18f86c mov r1, #2048
 *   @0x18f870 ldr r3, [r4]
 *   @0x18f874 str r3, [sp, #0x804]
 *   @0x18f878 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x18f87c mov r0, r5
 *   @0x18f880 mov r1, r6
 *   @0x18f884 bl 0x18f594 <_ZN8LoadSave9_ReadFileEPKcPi>
 *   @0x18f888 ldr r2, [sp, #0x804]
 *   @0x18f88c ldr r3, [r4]
 *   @0x18f890 cmp r2, r3
 *   @0x18f894 bne 0x18f8a4 <_ZN8LoadSave14ReadBundleFileEPKcPi+0x5c>
 *   @0x18f898 add sp, sp, #2048
 *   @0x18f89c add sp, sp, #8
 *   @0x18f8a0 pop {r4, r5, r6, pc}
 *   @0x18f8a4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18f8a8 .word 0x0025e0f0
 *
 * ══ §20/321 LoadSave::ReadSaveFile(char const*, int*)  0x18fb08  size 100  25 条（0x18fb08..0x18fb6c）
 * @func 0x18fb08 0x18fb6c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*) / _ReadSaveFile(char const*, int*) / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18fb08 push {r4, r5, r6, lr}
 *   @0x18fb0c sub sp, sp, #2048
 *   @0x18fb10 ldr r4, [pc, #0x50]
 *   @0x18fb14 sub sp, sp, #8
 *   @0x18fb18 add r5, sp, #4
 *   @0x18fb1c mov r2, r0
 *   @0x18fb20 ldr r4, [pc, r4]
 *   @0x18fb24 mov r6, r1
 *   @0x18fb28 mov r0, r5
 *   @0x18fb2c mov r1, #2048
 *   @0x18fb30 ldr r3, [r4]
 *   @0x18fb34 str r3, [sp, #0x804]
 *   @0x18fb38 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x18fb3c mov r0, r5
 *   @0x18fb40 mov r1, r6
 *   @0x18fb44 bl 0x18f4d0 <_Z13_ReadSaveFilePKcPi>
 *   @0x18fb48 ldr r2, [sp, #0x804]
 *   @0x18fb4c ldr r3, [r4]
 *   @0x18fb50 cmp r2, r3
 *   @0x18fb54 bne 0x18fb64 <_ZN8LoadSave12ReadSaveFileEPKcPi+0x5c>
 *   @0x18fb58 add sp, sp, #2048
 *   @0x18fb5c add sp, sp, #8
 *   @0x18fb60 pop {r4, r5, r6, pc}
 *   @0x18fb64 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18fb68 eoreq sp, r5, r0, lsr lr
 *
 * ══ §21/321 LoadSave::RemoveSaveFile(char const*)  0x18ffb0  size 100  25 条（0x18ffb0..0x190014）
 * @func 0x18ffb0 0x190014  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*) / 0xb6970 / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ffb0 push {r4, r5, lr}
 *   @0x18ffb4 sub sp, sp, #2048
 *   @0x18ffb8 ldr r4, [pc, #0x50]
 *   @0x18ffbc sub sp, sp, #12
 *   @0x18ffc0 add r5, sp, #4
 *   @0x18ffc4 mov r2, r0
 *   @0x18ffc8 ldr r4, [pc, r4]
 *   @0x18ffcc mov r1, #2048
 *   @0x18ffd0 mov r0, r5
 *   @0x18ffd4 ldr r3, [r4]
 *   @0x18ffd8 str r3, [sp, #0x804]
 *   @0x18ffdc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x18ffe0 mov r0, r5
 *   @0x18ffe4 bl 0xb6970 <remove@plt>
 *   @0x18ffe8 ldr r2, [sp, #0x804]
 *   @0x18ffec ldr r3, [r4]
 *   @0x18fff0 rsbs r0, r0, #1
 *   @0x18fff4 movlo r0, #0
 *   @0x18fff8 cmp r2, r3
 *   @0x18fffc bne 0x19000c <_ZN8LoadSave14RemoveSaveFileEPKc+0x5c>
 *   @0x190000 add sp, sp, #2048
 *   @0x190004 add sp, sp, #12
 *   @0x190008 pop {r4, r5, pc}
 *   @0x19000c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x190010 eoreq sp, r5, r8, lsl #19
 *
 * ══ §22/321 ParticleType_Color_RGB(int, int, int, int, int, int, int)  0x1a3490  size 100  25 条（0x1a3490..0x1a34f4）
 * @func 0x1a3490 0x1a34f4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x38×1 / 0x4×1 / 0x2×1 / 0x18×1 / 0x7c×1 / 0x88×1 / 0x1c×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3490 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a3494 mov r7, r1
 *   @0x1a3498 mov r6, r2
 *   @0x1a349c mov r5, r3
 *   @0x1a34a0 mov r4, r0
 *   @0x1a34a4 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a34a8 cmp r0, #0
 *   @0x1a34ac popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a34b0 ldr r12, [pc, #0x38]
 *   @0x1a34b4 mov r3, #3
 *   @0x1a34b8 ldr r12, [pc, r12]
 *   @0x1a34bc ldr r2, [r12, #0x4]
 *   @0x1a34c0 ldr r0, [r2, r4, lsl #2]
 *   @0x1a34c4 ldr r2, [sp, #0x18]
 *   @0x1a34c8 str r7, [r0, #0x7c]
 *   @0x1a34cc str r2, [r0, #0x88]
 *   @0x1a34d0 ldr r2, [sp, #0x1c]
 *   @0x1a34d4 str r6, [r0, #0x80]
 *   @0x1a34d8 str r5, [r0, #0x84]
 *   @0x1a34dc str r2, [r0, #0x8c]
 *   @0x1a34e0 ldr r2, [sp, #0x20]
 *   @0x1a34e4 str r3, [r0, #0x78]
 *   @0x1a34e8 str r2, [r0, #0x90]
 *   @0x1a34ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a34f0 .word 0x0024d2f4
 *
 * ══ §23/321 ParticleType_Color_HSV(int, int, int, int, int, int, int)  0x1a3538  size 100  25 条（0x1a3538..0x1a359c）
 * @func 0x1a3538 0x1a359c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x38×1 / 0x4×1 / 0x2×1 / 0x18×1 / 0x7c×1 / 0x88×1 / 0x1c×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3538 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a353c mov r7, r1
 *   @0x1a3540 mov r6, r2
 *   @0x1a3544 mov r5, r3
 *   @0x1a3548 mov r4, r0
 *   @0x1a354c bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3550 cmp r0, #0
 *   @0x1a3554 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a3558 ldr r12, [pc, #0x38]
 *   @0x1a355c mov r3, #4
 *   @0x1a3560 ldr r12, [pc, r12]
 *   @0x1a3564 ldr r2, [r12, #0x4]
 *   @0x1a3568 ldr r0, [r2, r4, lsl #2]
 *   @0x1a356c ldr r2, [sp, #0x18]
 *   @0x1a3570 str r7, [r0, #0x7c]
 *   @0x1a3574 str r2, [r0, #0x88]
 *   @0x1a3578 ldr r2, [sp, #0x1c]
 *   @0x1a357c str r6, [r0, #0x80]
 *   @0x1a3580 str r5, [r0, #0x84]
 *   @0x1a3584 str r2, [r0, #0x8c]
 *   @0x1a3588 ldr r2, [sp, #0x20]
 *   @0x1a358c str r3, [r0, #0x78]
 *   @0x1a3590 str r2, [r0, #0x90]
 *   @0x1a3594 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a3598 eoreq sp, r4, r12, asr #4
 *
 * ══ §24/321 Room_Previous(int)  0x1b5d40  size 100  25 条（0x1b5d40..0x1b5da4）
 * @func 0x1b5d40 0x1b5db4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Previous(int)+0x58
 * 字段偏移 top8: 0x4×3 / 0x58×1 / 0x-4×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5d40 ldr r3, [pc, #0x58]
 *   @0x1b5d44 str r4, [sp, #-0x4]!
 *   @0x1b5d48 add r3, pc, r3
 *   @0x1b5d4c mov r4, r0
 *   @0x1b5d50 ldr r12, [r3, #0x10]
 *   @0x1b5d54 cmp r12, #1
 *   @0x1b5d58 ble 0x1b5d98 <_Z13Room_Previousi+0x58>
 *   @0x1b5d5c ldr r2, [r3, #0x14]
 *   @0x1b5d60 ldm r2, {r0, r3}
 *   @0x1b5d64 cmp r3, r4
 *   @0x1b5d68 beq 0x1b5d90 <_Z13Room_Previousi+0x50>
 *   @0x1b5d6c mov r3, #1
 *   @0x1b5d70 b 0x1b5d84 <_Z13Room_Previousi+0x44>
 *   @0x1b5d74 ldr r0, [r2, #0x4]!
 *   @0x1b5d78 ldr r1, [r2, #0x4]
 *   @0x1b5d7c cmp r1, r4
 *   @0x1b5d80 beq 0x1b5d90 <_Z13Room_Previousi+0x50>
 *   @0x1b5d84 add r3, r3, #1
 *   @0x1b5d88 cmp r3, r12
 *   @0x1b5d8c bne 0x1b5d74 <_Z13Room_Previousi+0x34>
 *   @0x1b5d90 ldr r4, [sp], #4
 *   @0x1b5d94 bx lr
 *   @0x1b5d98 mvn r0, #0
 *   @0x1b5d9c b 0x1b5d90 <_Z13Room_Previousi+0x50>
 *   @0x1b5da0 eorseq r12, r8, r0, lsl #17
 *
 * ══ §25/321 F_LayerForceDrawDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b6864  size 100  25 条（0x1b6864..0x1b68c8）
 * @func 0x1b6864 0x1b68c8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x24×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6864 cmp r3, #2
 *   @0x1b6868 push {r4, lr}
 *   @0x1b686c ldr r4, [sp, #0x8]
 *   @0x1b6870 beq 0x1b6888 <_Z21F_LayerForceDrawDepthR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x1b6874 ldr r0, [pc, #0x40]
 *   @0x1b6878 mov r1, #0
 *   @0x1b687c pop {r4, lr}
 *   @0x1b6880 add r0, pc, r0
 *   @0x1b6884 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b6888 mov r1, #0
 *   @0x1b688c mov r0, r4
 *   @0x1b6890 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1b6894 ldr r3, [pc, #0x24]
 *   @0x1b6898 mov r1, #1
 *   @0x1b689c ldr r3, [pc, r3]
 *   @0x1b68a0 strb r0, [r3]
 *   @0x1b68a4 mov r0, r4
 *   @0x1b68a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b68ac ldr r3, [pc, #0x10]
 *   @0x1b68b0 ldr r3, [pc, r3]
 *   @0x1b68b4 str r0, [r3]
 *   @0x1b68b8 pop {r4, pc}
 *   @0x1b68bc andseq r6, r9, r8, asr sp
 *   @0x1b68c0 mlaeq r3, r4, pc, r9
 *   @0x1b68c4 eoreq r9, r3, r4, lsl #31
 *
 * ══ §26/321 GV_PhysicsPositionX(CInstance*, int, RValue*)  0x1f95bc  size 100  25 条（0x1f95bc..0x1f9620）
 * @func 0x1f95bc 0x1f9630  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1 / 0x84×1 / 0xb4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f95bc ldr r3, [pc, #0x58]
 *   @0x1f95c0 ldr r1, [r0, #0x84]
 *   @0x1f95c4 ldr r3, [pc, r3]
 *   @0x1f95c8 push {r4, r5}
 *   @0x1f95cc ldr r3, [r3]
 *   @0x1f95d0 ldr r3, [r3, #0xb4]
 *   @0x1f95d4 cmp r1, #0
 *   @0x1f95d8 cmpne r3, #0
 *   @0x1f95dc moveq r0, #0
 *   @0x1f95e0 movne r0, #1
 *   @0x1f95e4 beq 0x1f9614 <_Z19GV_PhysicsPositionXP9CInstanceiP6RValue+0x58>
 *   @0x1f95e8 ldr r12, [r1]
 *   @0x1f95ec mov r1, #0
 *   @0x1f95f0 vldr s14, [r12, #12]
 *   @0x1f95f4 str r1, [r2, #0xc]
 *   @0x1f95f8 vldr s15, [r3, #96]
 *   @0x1f95fc vdiv.f32 s15, s14, s15
 *   @0x1f9600 vcvt.f64.f32 d6, s15
 *   @0x1f9604 vmov r4, r5, d6
 *   @0x1f9608 vmov r1, s12
 *   @0x1f960c mov r3, r5
 *   @0x1f9610 stm r2, {r1, r3}
 *   @0x1f9614 pop {r4, r5}
 *   @0x1f9618 bx lr
 *   @0x1f961c andseq r4, pc, r4, ror #6
 *
 * ══ §27/321 GV_PhysicsPositionY(CInstance*, int, RValue*)  0x1f9620  size 100  25 条（0x1f9620..0x1f9684）
 * @func 0x1f9620 0x1f9694  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1 / 0x84×1 / 0xb4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9620 ldr r3, [pc, #0x58]
 *   @0x1f9624 ldr r1, [r0, #0x84]
 *   @0x1f9628 ldr r3, [pc, r3]
 *   @0x1f962c push {r4, r5}
 *   @0x1f9630 ldr r3, [r3]
 *   @0x1f9634 ldr r3, [r3, #0xb4]
 *   @0x1f9638 cmp r1, #0
 *   @0x1f963c cmpne r3, #0
 *   @0x1f9640 moveq r0, #0
 *   @0x1f9644 movne r0, #1
 *   @0x1f9648 beq 0x1f9678 <_Z19GV_PhysicsPositionYP9CInstanceiP6RValue+0x58>
 *   @0x1f964c ldr r12, [r1]
 *   @0x1f9650 mov r1, #0
 *   @0x1f9654 vldr s14, [r12, #16]
 *   @0x1f9658 str r1, [r2, #0xc]
 *   @0x1f965c vldr s15, [r3, #96]
 *   @0x1f9660 vdiv.f32 s15, s14, s15
 *   @0x1f9664 vcvt.f64.f32 d6, s15
 *   @0x1f9668 vmov r4, r5, d6
 *   @0x1f966c vmov r1, s12
 *   @0x1f9670 mov r3, r5
 *   @0x1f9674 stm r2, {r1, r3}
 *   @0x1f9678 pop {r4, r5}
 *   @0x1f967c bx lr
 *   @0x1f9680 andseq r4, pc, r0, lsl #6
 *
 * ══ §28/321 GV_PhysicsLinearVelocityX(CInstance*, int, RValue*)  0x1f9684  size 100  25 条（0x1f9684..0x1f96e8）
 * @func 0x1f9684 0x1f96f8  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1 / 0x84×1 / 0xb4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9684 ldr r3, [pc, #0x58]
 *   @0x1f9688 ldr r1, [r0, #0x84]
 *   @0x1f968c ldr r3, [pc, r3]
 *   @0x1f9690 push {r4, r5}
 *   @0x1f9694 ldr r3, [r3]
 *   @0x1f9698 ldr r3, [r3, #0xb4]
 *   @0x1f969c cmp r1, #0
 *   @0x1f96a0 cmpne r3, #0
 *   @0x1f96a4 moveq r0, #0
 *   @0x1f96a8 movne r0, #1
 *   @0x1f96ac beq 0x1f96dc <_Z25GV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x58>
 *   @0x1f96b0 ldr r12, [r1]
 *   @0x1f96b4 mov r1, #0
 *   @0x1f96b8 vldr s14, [r12, #80]
 *   @0x1f96bc str r1, [r2, #0xc]
 *   @0x1f96c0 vldr s15, [r3, #96]
 *   @0x1f96c4 vdiv.f32 s15, s14, s15
 *   @0x1f96c8 vcvt.f64.f32 d6, s15
 *   @0x1f96cc vmov r4, r5, d6
 *   @0x1f96d0 vmov r1, s12
 *   @0x1f96d4 mov r3, r5
 *   @0x1f96d8 stm r2, {r1, r3}
 *   @0x1f96dc pop {r4, r5}
 *   @0x1f96e0 bx lr
 *   @0x1f96e4 mulseq pc, r12, r2
 *
 * ══ §29/321 GV_PhysicsLinearVelocityY(CInstance*, int, RValue*)  0x1f96e8  size 100  25 条（0x1f96e8..0x1f974c）
 * @func 0x1f96e8 0x1f974c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1 / 0x84×1 / 0xb4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f96e8 ldr r3, [pc, #0x58]
 *   @0x1f96ec ldr r1, [r0, #0x84]
 *   @0x1f96f0 ldr r3, [pc, r3]
 *   @0x1f96f4 push {r4, r5}
 *   @0x1f96f8 ldr r3, [r3]
 *   @0x1f96fc ldr r3, [r3, #0xb4]
 *   @0x1f9700 cmp r1, #0
 *   @0x1f9704 cmpne r3, #0
 *   @0x1f9708 moveq r0, #0
 *   @0x1f970c movne r0, #1
 *   @0x1f9710 beq 0x1f9740 <_Z25GV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x58>
 *   @0x1f9714 ldr r12, [r1]
 *   @0x1f9718 mov r1, #0
 *   @0x1f971c vldr s14, [r12, #84]
 *   @0x1f9720 str r1, [r2, #0xc]
 *   @0x1f9724 vldr s15, [r3, #96]
 *   @0x1f9728 vdiv.f32 s15, s14, s15
 *   @0x1f972c vcvt.f64.f32 d6, s15
 *   @0x1f9730 vmov r4, r5, d6
 *   @0x1f9734 vmov r1, s12
 *   @0x1f9738 mov r3, r5
 *   @0x1f973c stm r2, {r1, r3}
 *   @0x1f9740 pop {r4, r5}
 *   @0x1f9744 bx lr
 *   @0x1f9748 andseq r4, pc, r8, lsr r2
 *
 * ══ §30/321 GV_PhysicsCOM_X(CInstance*, int, RValue*)  0x1f97cc  size 100  25 条（0x1f97cc..0x1f9830）
 * @func 0x1f97cc 0x1f9840  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1 / 0x84×1 / 0xb4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f97cc ldr r3, [pc, #0x58]
 *   @0x1f97d0 ldr r1, [r0, #0x84]
 *   @0x1f97d4 ldr r3, [pc, r3]
 *   @0x1f97d8 push {r4, r5}
 *   @0x1f97dc ldr r3, [r3]
 *   @0x1f97e0 ldr r3, [r3, #0xb4]
 *   @0x1f97e4 cmp r1, #0
 *   @0x1f97e8 cmpne r3, #0
 *   @0x1f97ec moveq r0, #0
 *   @0x1f97f0 movne r0, #1
 *   @0x1f97f4 beq 0x1f9824 <_Z15GV_PhysicsCOM_XP9CInstanceiP6RValue+0x58>
 *   @0x1f97f8 ldr r12, [r1]
 *   @0x1f97fc mov r1, #0
 *   @0x1f9800 vldr s14, [r12, #60]
 *   @0x1f9804 str r1, [r2, #0xc]
 *   @0x1f9808 vldr s15, [r3, #96]
 *   @0x1f980c vdiv.f32 s15, s14, s15
 *   @0x1f9810 vcvt.f64.f32 d6, s15
 *   @0x1f9814 vmov r4, r5, d6
 *   @0x1f9818 vmov r1, s12
 *   @0x1f981c mov r3, r5
 *   @0x1f9820 stm r2, {r1, r3}
 *   @0x1f9824 pop {r4, r5}
 *   @0x1f9828 bx lr
 *   @0x1f982c andseq r4, pc, r4, asr r1
 *
 * ══ §31/321 GV_PhysicsCOM_Y(CInstance*, int, RValue*)  0x1f9830  size 100  25 条（0x1f9830..0x1f9894）
 * @func 0x1f9830 0x1f9894  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1 / 0x84×1 / 0xb4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9830 ldr r3, [pc, #0x58]
 *   @0x1f9834 ldr r1, [r0, #0x84]
 *   @0x1f9838 ldr r3, [pc, r3]
 *   @0x1f983c push {r4, r5}
 *   @0x1f9840 ldr r3, [r3]
 *   @0x1f9844 ldr r3, [r3, #0xb4]
 *   @0x1f9848 cmp r1, #0
 *   @0x1f984c cmpne r3, #0
 *   @0x1f9850 moveq r0, #0
 *   @0x1f9854 movne r0, #1
 *   @0x1f9858 beq 0x1f9888 <_Z15GV_PhysicsCOM_YP9CInstanceiP6RValue+0x58>
 *   @0x1f985c ldr r12, [r1]
 *   @0x1f9860 mov r1, #0
 *   @0x1f9864 vldr s14, [r12, #64]
 *   @0x1f9868 str r1, [r2, #0xc]
 *   @0x1f986c vldr s15, [r3, #96]
 *   @0x1f9870 vdiv.f32 s15, s14, s15
 *   @0x1f9874 vcvt.f64.f32 d6, s15
 *   @0x1f9878 vmov r4, r5, d6
 *   @0x1f987c vmov r1, s12
 *   @0x1f9880 mov r3, r5
 *   @0x1f9884 stm r2, {r1, r3}
 *   @0x1f9888 pop {r4, r5}
 *   @0x1f988c bx lr
 *   @0x1f9890 ldrsheq r4, [pc], -r0
 *
 * ══ §32/321 Audio_EmitterExists(int)  0x217324  size 100  25 条（0x217324..0x217388）
 * @func 0x217324 0x217388  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×2 / 0x54×1 / 0x44×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217324 ldr r3, [pc, #0x54]
 *   @0x217328 mov r2, r0
 *   @0x21732c ldr r3, [pc, r3]
 *   @0x217330 ldrb r3, [r3]
 *   @0x217334 cmp r3, #0
 *   @0x217338 bne 0x217378 <_Z19Audio_EmitterExistsi+0x54>
 *   @0x21733c ldr r1, [pc, #0x40]
 *   @0x217340 add r1, pc, r1
 *   @0x217344 ldr r0, [r1, #0x40]
 *   @0x217348 cmp r0, r2
 *   @0x21734c movgt r0, #0
 *   @0x217350 movle r0, #1
 *   @0x217354 orrs r0, r0, r2, lsr #31
 *   @0x217358 bne 0x217370 <_Z19Audio_EmitterExistsi+0x4c>
 *   @0x21735c ldr r3, [r1, #0x44]
 *   @0x217360 ldr r3, [r3, r2, lsl #2]
 *   @0x217364 cmp r3, #0
 *   @0x217368 ldrbne r0, [r3, #0x18]
 *   @0x21736c bx lr
 *   @0x217370 mov r0, r3
 *   @0x217374 bx lr
 *   @0x217378 mov r0, #0
 *   @0x21737c bx lr
 *   @0x217380 andseq r7, sp, r0, lsr #26
 *   @0x217384 subseq sp, r3, r4, asr pc
 *
 * ══ §33/321 Audio_GetSoundPitch(int)  0x2173fc  size 100  25 条（0x2173fc..0x217460）
 * @func 0x2173fc 0x217460  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetNoiseFromID(int) / Audio_GetSound(int)
 * 字段偏移 top8: 0x50×1 / 0x40×1 / 0x20×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2173fc push {r3, lr}
 *   @0x217400 ldr r3, [pc, #0x50]
 *   @0x217404 ldr r3, [pc, r3]
 *   @0x217408 ldrb r3, [r3]
 *   @0x21740c cmp r3, #0
 *   @0x217410 beq 0x217450 <_Z19Audio_GetSoundPitchi+0x54>
 *   @0x217414 ldr r3, [pc, #0x40]
 *   @0x217418 ldr r3, [pc, r3]
 *   @0x21741c ldr r3, [r3]
 *   @0x217420 cmp r3, r0
 *   @0x217424 bgt 0x21743c <_Z19Audio_GetSoundPitchi+0x40>
 *   @0x217428 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x21742c cmp r0, #0
 *   @0x217430 beq 0x217450 <_Z19Audio_GetSoundPitchi+0x54>
 *   @0x217434 ldr r0, [r0, #0x20]
 *   @0x217438 pop {r3, pc}
 *   @0x21743c bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x217440 cmp r0, #0
 *   @0x217444 beq 0x217450 <_Z19Audio_GetSoundPitchi+0x54>
 *   @0x217448 ldr r0, [r0, #0x8]
 *   @0x21744c pop {r3, pc}
 *   @0x217450 mov r0, #1065353216
 *   @0x217454 pop {r3, pc}
 *   @0x217458 andseq r7, sp, r12, lsr #18
 *   @0x21745c andseq r9, sp, r12, asr #31
 *
 * ══ §34/321 Audio_GetSoundGain(int)  0x21788c  size 100  25 条（0x21788c..0x2178f0）
 * @func 0x21788c 0x2178f0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetNoiseFromID(int) / Audio_GetSound(int)
 * 字段偏移 top8: 0x50×1 / 0x40×1 / 0x24×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21788c push {r3, lr}
 *   @0x217890 ldr r3, [pc, #0x50]
 *   @0x217894 ldr r3, [pc, r3]
 *   @0x217898 ldrb r3, [r3]
 *   @0x21789c cmp r3, #0
 *   @0x2178a0 beq 0x2178e0 <_Z18Audio_GetSoundGaini+0x54>
 *   @0x2178a4 ldr r3, [pc, #0x40]
 *   @0x2178a8 ldr r3, [pc, r3]
 *   @0x2178ac ldr r3, [r3]
 *   @0x2178b0 cmp r3, r0
 *   @0x2178b4 bgt 0x2178cc <_Z18Audio_GetSoundGaini+0x40>
 *   @0x2178b8 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x2178bc cmp r0, #0
 *   @0x2178c0 beq 0x2178e0 <_Z18Audio_GetSoundGaini+0x54>
 *   @0x2178c4 ldr r0, [r0, #0x24]
 *   @0x2178c8 pop {r3, pc}
 *   @0x2178cc bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x2178d0 cmp r0, #0
 *   @0x2178d4 beq 0x2178e0 <_Z18Audio_GetSoundGaini+0x54>
 *   @0x2178d8 ldr r0, [r0, #0x4]
 *   @0x2178dc pop {r3, pc}
 *   @0x2178e0 mov r0, #0
 *   @0x2178e4 pop {r3, pc}
 *   @0x2178e8 mulseq sp, r12, r4
 *   @0x2178ec andseq r9, sp, r12, lsr r11
 *
 * ══ §35/321 CAudioGroupMan::CreateGroups(int)  0x21de4c  size 100  25 条（0x21de4c..0x21deb0）
 * @func 0x21de4c 0x21dec0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / operator new(unsigned int) / CAudioGroup::CAudioGroup(int)
 * 字段偏移 top8: 0x50×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21de4c push {r3, r4, r5, r6, r7, lr}
 *   @0x21de50 mov r6, r1
 *   @0x21de54 ldr r1, [pc, #0x50]
 *   @0x21de58 mov r7, r0
 *   @0x21de5c mov r2, #164
 *   @0x21de60 lsl r0, r6, #2
 *   @0x21de64 add r1, pc, r1
 *   @0x21de68 mov r3, #1
 *   @0x21de6c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x21de70 cmp r6, #0
 *   @0x21de74 stm r7, {r0, r6}
 *   @0x21de78 pople {r3, r4, r5, r6, r7, pc}
 *   @0x21de7c mov r4, #0
 *   @0x21de80 mov r0, #40
 *   @0x21de84 bl 0x27c524 <_Znwj>
 *   @0x21de88 mov r1, r4
 *   @0x21de8c mov r5, r0
 *   @0x21de90 bl 0x21db54 <_ZN11CAudioGroupC2Ei>
 *   @0x21de94 ldr r3, [r7]
 *   @0x21de98 str r5, [r3, r4, lsl #2]
 *   @0x21de9c add r4, r4, #1
 *   @0x21dea0 cmp r4, r6
 *   @0x21dea4 bne 0x21de80 <_ZN14CAudioGroupMan12CreateGroupsEi+0x34>
 *   @0x21dea8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x21deac ldrsbeq r6, [r3], -r12
 *
 * ══ §36/321 SoundHardware::SetMasterVolume(float)  0x220884  size 100  25 条（0x220884..0x2208e8）
 * @func 0x220884 0x2208e8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×2 / 0x44×1 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220884 push {r3, r4, r5, lr}
 *   @0x220888 mov r4, r0
 *   @0x22088c ldr r3, [pc, #0x44]
 *   @0x220890 mov r5, r1
 *   @0x220894 ldr r3, [pc, r3]
 *   @0x220898 ldrb r3, [r3]
 *   @0x22089c cmp r3, #0
 *   @0x2208a0 beq 0x2208d0 <_ZN13SoundHardware15SetMasterVolumeEf+0x4c>
 *   @0x2208a4 ldr r3, [pc, #0x30]
 *   @0x2208a8 ldr r2, [pc, #0x30]
 *   @0x2208ac ldr r3, [pc, r3]
 *   @0x2208b0 ldr r1, [pc, #0x2c]
 *   @0x2208b4 add r2, pc, r2
 *   @0x2208b8 ldr r0, [r3]
 *   @0x2208bc add r1, pc, r1
 *   @0x2208c0 add r2, r2, #84
 *   @0x2208c4 ldr r3, [r0]
 *   @0x2208c8 ldr r3, [r3, #0xc]
 *   @0x2208cc blx r3
 *   @0x2208d0 str r5, [r4]
 *   @0x2208d4 pop {r3, r4, r5, pc}
 *   @0x2208d8 mulseq sp, r4, r11
 *   @0x2208dc andseq r12, r12, r8, ror #28
 *   @0x2208e0 andseq sp, r3, r4, lsl r7
 *   @0x2208e4 andseq r3, r3, r0, lsl #31
 *
 * ══ §37/321 alutLoadWAVMemory  0x2227f8  size 100  25 条（0x2227f8..0x22285c）
 * @func 0x2227f8 0x22285c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutInputStreamConstructFromMemory / _alutLoadMemoryFromInputStream
 * 字段偏移 top8: 0x20×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2227f8 push {r4, r5, r6, r7, r8, lr}
 *   @0x2227fc sub sp, sp, #8
 *   @0x222800 mov r8, r3
 *   @0x222804 mov r7, r1
 *   @0x222808 mvn r1, #-2147483648
 *   @0x22280c mov r6, r2
 *   @0x222810 ldr r5, [sp, #0x20]
 *   @0x222814 ldr r4, [sp, #0x24]
 *   @0x222818 bl 0x221d94 <_alutInputStreamConstructFromMemory>
 *   @0x22281c add r3, sp, #4
 *   @0x222820 mov r1, r7
 *   @0x222824 mov r2, r8
 *   @0x222828 bl 0x222664 <_alutLoadMemoryFromInputStream>
 *   @0x22282c ldr r3, [r6]
 *   @0x222830 cmp r3, #0
 *   @0x222834 beq 0x222854 <alutLoadWAVMemory+0x5c>
 *   @0x222838 cmp r5, #0
 *   @0x22283c vldrne s15, [sp, #4]
 *   @0x222840 vcvtne.s32.f32 s15, s15
 *   @0x222844 vstrne s15, [r5]
 *   @0x222848 cmp r4, #0
 *   @0x22284c movne r3, #0
 *   @0x222850 strbne r3, [r4]
 *   @0x222854 add sp, sp, #8
 *   @0x222858 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §38/321 COggThread::StartThread()  0x2237d4  size 100  25 条（0x2237d4..0x223838）
 * @func 0x2237d4 0x223838  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CThread::Start(void* (*)(void*), void*, CThread::ePriority)
 * 字段偏移 top8: 0x28×2 / 0x50×1 / 0x81c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2237d4 ldr r1, [pc, #0x50]
 *   @0x2237d8 push {r3, r4, r5, lr}
 *   @0x2237dc mov r4, r0
 *   @0x2237e0 add r0, r0, #2064
 *   @0x2237e4 mov r2, r4
 *   @0x2237e8 add r0, r0, #8
 *   @0x2237ec add r1, pc, r1
 *   @0x2237f0 mov r3, #0
 *   @0x2237f4 bl 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE>
 *   @0x2237f8 subs r5, r0, #0
 *   @0x2237fc bne 0x223824 <_ZN10COggThread11StartThreadEv+0x50>
 *   @0x223800 ldr r3, [pc, #0x28]
 *   @0x223804 ldr r1, [pc, #0x28]
 *   @0x223808 ldr r3, [pc, r3]
 *   @0x22380c ldr r2, [r4, #0x81c]
 *   @0x223810 add r1, pc, r1
 *   @0x223814 ldr r0, [r3]
 *   @0x223818 ldr r3, [r0]
 *   @0x22381c ldr r3, [r3, #0xc]
 *   @0x223820 blx r3
 *   @0x223824 mov r0, r5
 *   @0x223828 pop {r3, r4, r5, pc}
 *   @0x22382c strheq r0, [r0], -r4
 *   @0x223830 andseq r9, r12, r12, lsl #30
 *   @0x223834 ldrsheq r1, [r3], -r8
 *
 * ══ §39/321 COggAudio::COggAudio()  0x225cb4  size 100  25 条（0x225cb4..0x225d18）
 * @func 0x225cb4 0x225d18  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×2 / 0x10×2 / 0x50×1 / 0x8×1 / 0xc×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225cb4 push {r4, r5, r6, lr}
 *   @0x225cb8 sub sp, sp, #8
 *   @0x225cbc ldr r2, [pc, #0x50]
 *   @0x225cc0 mov r4, r0
 *   @0x225cc4 mov r5, #0
 *   @0x225cc8 mov r6, #8
 *   @0x225ccc str r5, [r0]
 *   @0x225cd0 mov r1, #32
 *   @0x225cd4 str r5, [r0, #0x8]
 *   @0x225cd8 movw r3, #0x11b
 *   @0x225cdc str r5, [r4, #0x4]
 *   @0x225ce0 mov r0, r5
 *   @0x225ce4 str r5, [r4, #0x10]
 *   @0x225ce8 add r2, pc, r2
 *   @0x225cec str r5, [sp]
 *   @0x225cf0 str r6, [r4, #0xc]
 *   @0x225cf4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x225cf8 str r6, [r4, #0x4]
 *   @0x225cfc str r5, [r4, #0x14]
 *   @0x225d00 str r5, [r4, #0x18]
 *   @0x225d04 str r0, [r4, #0x10]
 *   @0x225d08 mov r0, r4
 *   @0x225d0c add sp, sp, #8
 *   @0x225d10 pop {r4, r5, r6, pc}
 *   @0x225d14 andseq r7, r2, r8, lsl #12
 *
 * ══ §40/321 COggAudio::Suspend()  0x22609c  size 100  25 条（0x22609c..0x226100）
 * @func 0x22609c 0x226100  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Suspend()
 * 字段偏移 top8: 0x14×2 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22609c push {r4, r5, r6, lr}
 *   @0x2260a0 mov r6, r0
 *   @0x2260a4 ldr r0, [r0]
 *   @0x2260a8 cmp r0, #0
 *   @0x2260ac popeq {r4, r5, r6, pc}
 *   @0x2260b0 ldr r3, [pc, #0x44]
 *   @0x2260b4 mov r2, #1
 *   @0x2260b8 ldr r1, [r6, #0x14]
 *   @0x2260bc ldr r3, [pc, r3]
 *   @0x2260c0 cmp r1, #0
 *   @0x2260c4 strb r2, [r3]
 *   @0x2260c8 pople {r4, r5, r6, pc}
 *   @0x2260cc mov r4, #0
 *   @0x2260d0 mov r5, r4
 *   @0x2260d4 add r0, r0, r4
 *   @0x2260d8 add r5, r5, #1
 *   @0x2260dc bl 0x223844 <_ZN10COggThread7SuspendEv>
 *   @0x2260e0 ldr r3, [r6, #0x14]
 *   @0x2260e4 add r4, r4, #2096
 *   @0x2260e8 cmp r3, r5
 *   @0x2260ec add r4, r4, #4
 *   @0x2260f0 pople {r4, r5, r6, pc}
 *   @0x2260f4 ldr r0, [r6]
 *   @0x2260f8 b 0x2260d4 <_ZN9COggAudio7SuspendEv+0x38>
 *   @0x2260fc ldrheq r11, [r12], -r12
 *
 * ══ §41/321 ogg_stream_pageout  0x234a1c  size 100  25 条（0x234a1c..0x234a80）
 * @func 0x234a1c 0x234a80  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_check
 * 字段偏移 top8: 0x148×1 / 0x1c×1 / 0x14c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234a1c push {r4, r5, r6, lr}
 *   @0x234a20 mov r5, r1
 *   @0x234a24 mov r4, r0
 *   @0x234a28 bl 0x23412c <ogg_stream_check>
 *   @0x234a2c cmp r0, #0
 *   @0x234a30 bne 0x234a78 <ogg_stream_pageout+0x5c>
 *   @0x234a34 ldr r3, [r4, #0x148]
 *   @0x234a38 ldr r2, [r4, #0x1c]
 *   @0x234a3c cmp r3, #0
 *   @0x234a40 bne 0x234a6c <ogg_stream_pageout+0x50>
 *   @0x234a44 cmp r2, #0
 *   @0x234a48 beq 0x234a58 <ogg_stream_pageout+0x3c>
 *   @0x234a4c ldr r2, [r4, #0x14c]
 *   @0x234a50 rsbs r2, r2, #1
 *   @0x234a54 movlo r2, #0
 *   @0x234a58 mov r0, r4
 *   @0x234a5c mov r1, r5
 *   @0x234a60 mov r3, #4096
 *   @0x234a64 pop {r4, r5, r6, lr}
 *   @0x234a68 b 0x234434 <ogg_page_checksum_set+0xe0>
 *   @0x234a6c adds r2, r2, #0
 *   @0x234a70 movne r2, #1
 *   @0x234a74 b 0x234a58 <ogg_stream_pageout+0x3c>
 *   @0x234a78 mov r0, #0
 *   @0x234a7c pop {r4, r5, r6, pc}
 *
 * ══ §42/321 CPhysicsDebugRender::DrawSegment(b2Vec2 const&, b2Vec2 const&, b2Color const&)  0x23c5d0  size 100  25 条（0x23c5d0..0x23c634）
 * @func 0x23c5d0 0x23c634  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsDebugRender::TranslateColour(b2Color const&) / YYGML_draw_set_colour(unsigned int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c5d0 push {r4, r5, r6, lr}
 *   @0x23c5d4 mov r4, r1
 *   @0x23c5d8 mov r1, r3
 *   @0x23c5dc mov r5, r2
 *   @0x23c5e0 mov r6, r0
 *   @0x23c5e4 bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color>
 *   @0x23c5e8 bl 0x169d98 <_Z21YYGML_draw_set_colourj>
 *   @0x23c5ec vmov.f32 s10, #1.000000e+00
 *   @0x23c5f0 ldr r3, [r6, #0x8]
 *   @0x23c5f4 vldr s15, [r3, #96]
 *   @0x23c5f8 vldr s11, [r4]
 *   @0x23c5fc vldr s12, [r4, #4]
 *   @0x23c600 vldr s13, [r5]
 *   @0x23c604 vldr s14, [r5, #4]
 *   @0x23c608 pop {r4, r5, r6, lr}
 *   @0x23c60c vdiv.f32 s15, s10, s15
 *   @0x23c610 vmul.f32 s11, s15, s11
 *   @0x23c614 vmul.f32 s12, s15, s12
 *   @0x23c618 vmov r0, s11
 *   @0x23c61c vmul.f32 s13, s15, s13
 *   @0x23c620 vmov r1, s12
 *   @0x23c624 vmul.f32 s14, s15, s14
 *   @0x23c628 vmov r2, s13
 *   @0x23c62c vmov r3, s14
 *   @0x23c630 b 0x16a21c <_Z12GR_Draw_Lineffff>
 *
 * ══ §43/321 JS_Math_acos(RValue&, CInstance*, CInstance*, int, RValue*)  0x2521dc  size 100  25 条（0x2521dc..0x252240）
 * @func 0x2521dc 0x252250  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_acos(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb6c4c
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2521dc cmp r3, #0
 *   @0x2521e0 push {r3, r4, r5, lr}
 *   @0x2521e4 mov r5, #0
 *   @0x2521e8 mov r4, r0
 *   @0x2521ec ldr r1, [sp, #0x10]
 *   @0x2521f0 str r5, [r0, #0xc]
 *   @0x2521f4 ble 0x25221c <_Z12JS_Math_acosR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x2521f8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x2521fc cmp r0, #1
 *   @0x252200 beq 0x25222c <_Z12JS_Math_acosR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x252204 mov r1, r5
 *   @0x252208 mov r0, r4
 *   @0x25220c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252210 bl 0xb6c4c <acos@plt>
 *   @0x252214 stm r4, {r0, r1}
 *   @0x252218 pop {r3, r4, r5, pc}
 *   @0x25221c mvn r2, #0
 *   @0x252220 mvn r3, #-2147483648
 *   @0x252224 stm r0, {r2, r3}
 *   @0x252228 pop {r3, r4, r5, pc}
 *   @0x25222c ldr r0, [pc, #0x8]
 *   @0x252230 pop {r3, r4, r5, lr}
 *   @0x252234 add r0, pc, r0
 *   @0x252238 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25223c andseq r3, r0, r4, lsl sp
 *
 * ══ §44/321 JS_Math_asin(RValue&, CInstance*, CInstance*, int, RValue*)  0x252240  size 100  25 条（0x252240..0x2522a4）
 * @func 0x252240 0x2522b4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_asin(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb6c58
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252240 cmp r3, #0
 *   @0x252244 push {r3, r4, r5, lr}
 *   @0x252248 mov r5, #0
 *   @0x25224c mov r4, r0
 *   @0x252250 ldr r1, [sp, #0x10]
 *   @0x252254 str r5, [r0, #0xc]
 *   @0x252258 ble 0x252280 <_Z12JS_Math_asinR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x25225c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252260 cmp r0, #1
 *   @0x252264 beq 0x252290 <_Z12JS_Math_asinR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x252268 mov r1, r5
 *   @0x25226c mov r0, r4
 *   @0x252270 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252274 bl 0xb6c58 <asin@plt>
 *   @0x252278 stm r4, {r0, r1}
 *   @0x25227c pop {r3, r4, r5, pc}
 *   @0x252280 mvn r2, #0
 *   @0x252284 mvn r3, #-2147483648
 *   @0x252288 stm r0, {r2, r3}
 *   @0x25228c pop {r3, r4, r5, pc}
 *   @0x252290 ldr r0, [pc, #0x8]
 *   @0x252294 pop {r3, r4, r5, lr}
 *   @0x252298 add r0, pc, r0
 *   @0x25229c b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2522a0 ldrheq r3, [r0], -r0
 *
 * ══ §45/321 JS_Math_atan(RValue&, CInstance*, CInstance*, int, RValue*)  0x2522a4  size 100  25 条（0x2522a4..0x252308）
 * @func 0x2522a4 0x252308  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_atan(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb6c64
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2522a4 cmp r3, #0
 *   @0x2522a8 push {r3, r4, r5, lr}
 *   @0x2522ac mov r5, #0
 *   @0x2522b0 mov r4, r0
 *   @0x2522b4 ldr r1, [sp, #0x10]
 *   @0x2522b8 str r5, [r0, #0xc]
 *   @0x2522bc ble 0x2522e4 <_Z12JS_Math_atanR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x2522c0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x2522c4 cmp r0, #1
 *   @0x2522c8 beq 0x2522f4 <_Z12JS_Math_atanR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x2522cc mov r1, r5
 *   @0x2522d0 mov r0, r4
 *   @0x2522d4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2522d8 bl 0xb6c64 <atan@plt>
 *   @0x2522dc stm r4, {r0, r1}
 *   @0x2522e0 pop {r3, r4, r5, pc}
 *   @0x2522e4 mvn r2, #0
 *   @0x2522e8 mvn r3, #-2147483648
 *   @0x2522ec stm r0, {r2, r3}
 *   @0x2522f0 pop {r3, r4, r5, pc}
 *   @0x2522f4 ldr r0, [pc, #0x8]
 *   @0x2522f8 pop {r3, r4, r5, lr}
 *   @0x2522fc add r0, pc, r0
 *   @0x252300 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252304 andseq r3, r0, r12, asr #24
 *
 * ══ §46/321 JS_Math_ceil(RValue&, CInstance*, CInstance*, int, RValue*)  0x2523cc  size 100  25 条（0x2523cc..0x252430）
 * @func 0x2523cc 0x252440  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_ceil(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb670c
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2523cc cmp r3, #0
 *   @0x2523d0 push {r3, r4, r5, lr}
 *   @0x2523d4 mov r5, #0
 *   @0x2523d8 mov r4, r0
 *   @0x2523dc ldr r1, [sp, #0x10]
 *   @0x2523e0 str r5, [r0, #0xc]
 *   @0x2523e4 ble 0x25240c <_Z12JS_Math_ceilR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x2523e8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x2523ec cmp r0, #1
 *   @0x2523f0 beq 0x25241c <_Z12JS_Math_ceilR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x2523f4 mov r1, r5
 *   @0x2523f8 mov r0, r4
 *   @0x2523fc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252400 bl 0xb670c <ceil@plt>
 *   @0x252404 stm r4, {r0, r1}
 *   @0x252408 pop {r3, r4, r5, pc}
 *   @0x25240c mvn r2, #0
 *   @0x252410 mvn r3, #-2147483648
 *   @0x252414 stm r0, {r2, r3}
 *   @0x252418 pop {r3, r4, r5, pc}
 *   @0x25241c ldr r0, [pc, #0x8]
 *   @0x252420 pop {r3, r4, r5, lr}
 *   @0x252424 add r0, pc, r0
 *   @0x252428 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25242c andseq r3, r0, r4, lsr #22
 *
 * ══ §47/321 JS_Math_cos(RValue&, CInstance*, CInstance*, int, RValue*)  0x252430  size 100  25 条（0x252430..0x252494）
 * @func 0x252430 0x2524a4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_cos(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb67e4
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252430 cmp r3, #0
 *   @0x252434 push {r3, r4, r5, lr}
 *   @0x252438 mov r5, #0
 *   @0x25243c mov r4, r0
 *   @0x252440 ldr r1, [sp, #0x10]
 *   @0x252444 str r5, [r0, #0xc]
 *   @0x252448 ble 0x252470 <_Z11JS_Math_cosR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x25244c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252450 cmp r0, #1
 *   @0x252454 beq 0x252480 <_Z11JS_Math_cosR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x252458 mov r1, r5
 *   @0x25245c mov r0, r4
 *   @0x252460 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252464 bl 0xb67e4 <cos@plt>
 *   @0x252468 stm r4, {r0, r1}
 *   @0x25246c pop {r3, r4, r5, pc}
 *   @0x252470 mvn r2, #0
 *   @0x252474 mvn r3, #-2147483648
 *   @0x252478 stm r0, {r2, r3}
 *   @0x25247c pop {r3, r4, r5, pc}
 *   @0x252480 ldr r0, [pc, #0x8]
 *   @0x252484 pop {r3, r4, r5, lr}
 *   @0x252488 add r0, pc, r0
 *   @0x25248c b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252490 andseq r3, r0, r0, asr #21
 *
 * ══ §48/321 JS_Math_exp(RValue&, CInstance*, CInstance*, int, RValue*)  0x252494  size 100  25 条（0x252494..0x2524f8）
 * @func 0x252494 0x252508  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_exp(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb6724
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252494 cmp r3, #0
 *   @0x252498 push {r3, r4, r5, lr}
 *   @0x25249c mov r5, #0
 *   @0x2524a0 mov r4, r0
 *   @0x2524a4 ldr r1, [sp, #0x10]
 *   @0x2524a8 str r5, [r0, #0xc]
 *   @0x2524ac ble 0x2524d4 <_Z11JS_Math_expR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x2524b0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x2524b4 cmp r0, #1
 *   @0x2524b8 beq 0x2524e4 <_Z11JS_Math_expR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x2524bc mov r1, r5
 *   @0x2524c0 mov r0, r4
 *   @0x2524c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2524c8 bl 0xb6724 <exp@plt>
 *   @0x2524cc stm r4, {r0, r1}
 *   @0x2524d0 pop {r3, r4, r5, pc}
 *   @0x2524d4 mvn r2, #0
 *   @0x2524d8 mvn r3, #-2147483648
 *   @0x2524dc stm r0, {r2, r3}
 *   @0x2524e0 pop {r3, r4, r5, pc}
 *   @0x2524e4 ldr r0, [pc, #0x8]
 *   @0x2524e8 pop {r3, r4, r5, lr}
 *   @0x2524ec add r0, pc, r0
 *   @0x2524f0 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2524f4 andseq r3, r0, r12, asr r10
 *
 * ══ §49/321 JS_Math_floor(RValue&, CInstance*, CInstance*, int, RValue*)  0x2524f8  size 100  25 条（0x2524f8..0x25255c）
 * @func 0x2524f8 0x25256c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_floor(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb6598
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2524f8 cmp r3, #0
 *   @0x2524fc push {r3, r4, r5, lr}
 *   @0x252500 mov r5, #0
 *   @0x252504 mov r4, r0
 *   @0x252508 ldr r1, [sp, #0x10]
 *   @0x25250c str r5, [r0, #0xc]
 *   @0x252510 ble 0x252538 <_Z13JS_Math_floorR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x252514 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252518 cmp r0, #1
 *   @0x25251c beq 0x252548 <_Z13JS_Math_floorR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x252520 mov r1, r5
 *   @0x252524 mov r0, r4
 *   @0x252528 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x25252c bl 0xb6598 <floor@plt>
 *   @0x252530 stm r4, {r0, r1}
 *   @0x252534 pop {r3, r4, r5, pc}
 *   @0x252538 mvn r2, #0
 *   @0x25253c mvn r3, #-2147483648
 *   @0x252540 stm r0, {r2, r3}
 *   @0x252544 pop {r3, r4, r5, pc}
 *   @0x252548 ldr r0, [pc, #0x8]
 *   @0x25254c pop {r3, r4, r5, lr}
 *   @0x252550 add r0, pc, r0
 *   @0x252554 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252558 ldrsheq r3, [r0], -r8
 *
 * ══ §50/321 JS_Math_log(RValue&, CInstance*, CInstance*, int, RValue*)  0x25255c  size 100  25 条（0x25255c..0x2525c0）
 * @func 0x25255c 0x2525c0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_log(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb6730
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25255c cmp r3, #0
 *   @0x252560 push {r3, r4, r5, lr}
 *   @0x252564 mov r5, #0
 *   @0x252568 mov r4, r0
 *   @0x25256c ldr r1, [sp, #0x10]
 *   @0x252570 str r5, [r0, #0xc]
 *   @0x252574 ble 0x25259c <_Z11JS_Math_logR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x252578 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25257c cmp r0, #1
 *   @0x252580 beq 0x2525ac <_Z11JS_Math_logR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x252584 mov r1, r5
 *   @0x252588 mov r0, r4
 *   @0x25258c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252590 bl 0xb6730 <log@plt>
 *   @0x252594 stm r4, {r0, r1}
 *   @0x252598 pop {r3, r4, r5, pc}
 *   @0x25259c mvn r2, #0
 *   @0x2525a0 mvn r3, #-2147483648
 *   @0x2525a4 stm r0, {r2, r3}
 *   @0x2525a8 pop {r3, r4, r5, pc}
 *   @0x2525ac ldr r0, [pc, #0x8]
 *   @0x2525b0 pop {r3, r4, r5, lr}
 *   @0x2525b4 add r0, pc, r0
 *   @0x2525b8 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2525bc mulseq r0, r4, r9
 *
 * ══ §51/321 JS_Math_sin(RValue&, CInstance*, CInstance*, int, RValue*)  0x252a98  size 100  25 条（0x252a98..0x252afc）
 * @func 0x252a98 0x252afc  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_sin(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb67d8
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252a98 cmp r3, #0
 *   @0x252a9c push {r3, r4, r5, lr}
 *   @0x252aa0 mov r5, #0
 *   @0x252aa4 mov r4, r0
 *   @0x252aa8 ldr r1, [sp, #0x10]
 *   @0x252aac str r5, [r0, #0xc]
 *   @0x252ab0 ble 0x252ad8 <_Z11JS_Math_sinR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x252ab4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252ab8 cmp r0, #1
 *   @0x252abc beq 0x252ae8 <_Z11JS_Math_sinR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x252ac0 mov r1, r5
 *   @0x252ac4 mov r0, r4
 *   @0x252ac8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252acc bl 0xb67d8 <sin@plt>
 *   @0x252ad0 stm r4, {r0, r1}
 *   @0x252ad4 pop {r3, r4, r5, pc}
 *   @0x252ad8 mvn r2, #0
 *   @0x252adc mvn r3, #-2147483648
 *   @0x252ae0 stm r0, {r2, r3}
 *   @0x252ae4 pop {r3, r4, r5, pc}
 *   @0x252ae8 ldr r0, [pc, #0x8]
 *   @0x252aec pop {r3, r4, r5, lr}
 *   @0x252af0 add r0, pc, r0
 *   @0x252af4 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252af8 andseq r3, r0, r8, asr r4
 *
 * ══ §52/321 JS_Math_tan(RValue&, CInstance*, CInstance*, int, RValue*)  0x252b84  size 100  25 条（0x252b84..0x252be8）
 * @func 0x252b84 0x252be8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_tan(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb6c7c
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252b84 cmp r3, #0
 *   @0x252b88 push {r3, r4, r5, lr}
 *   @0x252b8c mov r5, #0
 *   @0x252b90 mov r4, r0
 *   @0x252b94 ldr r1, [sp, #0x10]
 *   @0x252b98 str r5, [r0, #0xc]
 *   @0x252b9c ble 0x252bc4 <_Z11JS_Math_tanR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x252ba0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252ba4 cmp r0, #1
 *   @0x252ba8 beq 0x252bd4 <_Z11JS_Math_tanR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x252bac mov r1, r5
 *   @0x252bb0 mov r0, r4
 *   @0x252bb4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252bb8 bl 0xb6c7c <tan@plt>
 *   @0x252bbc stm r4, {r0, r1}
 *   @0x252bc0 pop {r3, r4, r5, pc}
 *   @0x252bc4 mvn r2, #0
 *   @0x252bc8 mvn r3, #-2147483648
 *   @0x252bcc stm r0, {r2, r3}
 *   @0x252bd0 pop {r3, r4, r5, pc}
 *   @0x252bd4 ldr r0, [pc, #0x8]
 *   @0x252bd8 pop {r3, r4, r5, lr}
 *   @0x252bdc add r0, pc, r0
 *   @0x252be0 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252be4 andseq r3, r0, r12, ror #6
 *
 * ══ §53/321 spAnimationState_setAnimation  0x283900  size 100  25 条（0x283900..0x283964）
 * @func 0x283900 0x283964  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spAnimationState_expandToIndex / _spAnimationState_disposeAllEntries / _spAnimationState_setCurrent
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0xc×1 / 0x10×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283900 push {r4, r5, r6, r7, r8, lr}
 *   @0x283904 mov r6, r2
 *   @0x283908 mov r8, r3
 *   @0x28390c mov r5, r0
 *   @0x283910 mov r7, r1
 *   @0x283914 bl 0x28362c <_spAnimationState_expandToIndex>
 *   @0x283918 cmp r0, #0
 *   @0x28391c beq 0x28392c <spAnimationState_setAnimation+0x2c>
 *   @0x283920 ldr r1, [r0, #0x4]
 *   @0x283924 mov r0, r5
 *   @0x283928 bl 0x28319c <_spAnimationState_disposeAllEntries>
 *   @0x28392c ldr r3, [r5, #0x1c]
 *   @0x283930 mov r0, r5
 *   @0x283934 blx r3
 *   @0x283938 ldr r3, [r6, #0x4]
 *   @0x28393c mov r1, r7
 *   @0x283940 mov r4, r0
 *   @0x283944 str r6, [r0, #0xc]
 *   @0x283948 str r8, [r0, #0x10]
 *   @0x28394c mov r2, r4
 *   @0x283950 str r3, [r0, #0x20]
 *   @0x283954 mov r0, r5
 *   @0x283958 bl 0x283698 <_spAnimationState_setCurrent>
 *   @0x28395c mov r0, r4
 *   @0x283960 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §54/321 Json_getItem  0x2873c4  size 100  25 条（0x2873c4..0x287428）
 * @func 0x2873c4 0x287428  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66d0
 * 字段偏移 top8: 0x4×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2873c4 push {r4, r5, r6, lr}
 *   @0x2873c8 mov r5, r1
 *   @0x2873cc ldr r4, [r0, #0x4]
 *   @0x2873d0 cmp r4, #0
 *   @0x2873d4 beq 0x287420 <Json_getItem+0x5c>
 *   @0x2873d8 adds r6, r1, #0
 *   @0x2873dc movne r6, #1
 *   @0x2873e0 b 0x2873f8 <Json_getItem+0x34>
 *   @0x2873e4 cmp r0, r5
 *   @0x2873e8 beq 0x287420 <Json_getItem+0x5c>
 *   @0x2873ec ldr r4, [r4]
 *   @0x2873f0 cmp r4, #0
 *   @0x2873f4 beq 0x287420 <Json_getItem+0x5c>
 *   @0x2873f8 ldr r0, [r4, #0x1c]
 *   @0x2873fc cmp r0, #0
 *   @0x287400 moveq r3, #0
 *   @0x287404 andne r3, r6, #1
 *   @0x287408 cmp r3, #0
 *   @0x28740c beq 0x2873e4 <Json_getItem+0x20>
 *   @0x287410 mov r1, r5
 *   @0x287414 bl 0xb66d0 <strcasecmp@plt>
 *   @0x287418 cmp r0, #0
 *   @0x28741c bne 0x2873ec <Json_getItem+0x28>
 *   @0x287420 mov r0, r4
 *   @0x287424 pop {r4, r5, r6, pc}
 *
 * ══ §55/321 spRegionAttachment_create  0x288f78  size 100  25 条（0x288f78..0x288fdc）
 * @func 0x288f78 0x288fec  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / _spAttachment_init
 * 字段偏移 top8: 0x38×2 / 0x54×1 / 0x1c×1 / 0x20×1 / 0x30×1 / 0x34×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x288f78 ldr r2, [pc, #0x54]
 *   @0x288f7c mov r1, #156
 *   @0x288f80 push {r3, r4, r5, lr}
 *   @0x288f84 add r2, pc, r2
 *   @0x288f88 mov r5, r0
 *   @0x288f8c mov r3, #43
 *   @0x288f90 mov r0, #1
 *   @0x288f94 bl 0x285c4c <_calloc>
 *   @0x288f98 ldr r3, [pc, #0x38]
 *   @0x288f9c mov r12, #1065353216
 *   @0x288fa0 mov r1, r5
 *   @0x288fa4 mov r2, #0
 *   @0x288fa8 ldr r3, [pc, r3]
 *   @0x288fac mov r4, r0
 *   @0x288fb0 str r12, [r0, #0x1c]
 *   @0x288fb4 str r12, [r0, #0x20]
 *   @0x288fb8 str r12, [r0, #0x30]
 *   @0x288fbc str r12, [r0, #0x34]
 *   @0x288fc0 str r12, [r0, #0x38]
 *   @0x288fc4 str r12, [r0, #0x3c]
 *   @0x288fc8 bl 0x284c18 <_spAttachment_init>
 *   @0x288fcc mov r0, r4
 *   @0x288fd0 pop {r3, r4, r5, pc}
 *   @0x288fd4 andeq lr, r12, r0, ror r10
 *   @0x288fd8 andseq r8, r6, r0, ror #18
 *
 * ══ §56/321 spRegionAttachment_setUVs  0x288fdc  size 100  25 条（0x288fdc..0x289040）
 * @func 0x288fdc 0x289040  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x7c×2 / 0x80×2 / 0x84×2 / 0x88×2 / 0x8c×2 / 0x90×2 / 0x94×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x288fdc str r4, [sp, #-0x4]!
 *   @0x288fe0 ldr r4, [sp, #0x8]
 *   @0x288fe4 ldr r12, [sp, #0x4]
 *   @0x288fe8 cmp r4, #0
 *   @0x288fec bne 0x289018 <spRegionAttachment_setUVs+0x3c>
 *   @0x288ff0 str r1, [r0, #0x7c]
 *   @0x288ff4 str r12, [r0, #0x80]
 *   @0x288ff8 str r1, [r0, #0x84]
 *   @0x288ffc str r2, [r0, #0x88]
 *   @0x289000 str r3, [r0, #0x8c]
 *   @0x289004 str r2, [r0, #0x90]
 *   @0x289008 str r3, [r0, #0x94]
 *   @0x28900c str r12, [r0, #0x98]
 *   @0x289010 ldr r4, [sp], #4
 *   @0x289014 bx lr
 *   @0x289018 str r1, [r0, #0x84]
 *   @0x28901c str r12, [r0, #0x88]
 *   @0x289020 str r1, [r0, #0x8c]
 *   @0x289024 str r2, [r0, #0x90]
 *   @0x289028 str r3, [r0, #0x94]
 *   @0x28902c str r2, [r0, #0x98]
 *   @0x289030 str r3, [r0, #0x7c]
 *   @0x289034 str r12, [r0, #0x80]
 *   @0x289038 ldr r4, [sp], #4
 *   @0x28903c bx lr
 *
 * ══ §57/321 spSkeletonBounds_getPolygon  0x28ad78  size 100  25 条（0x28ad78..0x28addc）
 * @func 0x28ad78 0x28addc  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonBounds_getPolygon+0x44
 * 字段偏移 top8: 0x4×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ad78 push {r4, r5}
 *   @0x28ad7c ldr r4, [r0]
 *   @0x28ad80 cmp r4, #0
 *   @0x28ad84 ble 0x28adbc <spSkeletonBounds_getPolygon+0x44>
 *   @0x28ad88 ldr r2, [r0, #0x4]
 *   @0x28ad8c ldr r3, [r2]
 *   @0x28ad90 cmp r3, r1
 *   @0x28ad94 movne r3, #0
 *   @0x28ad98 bne 0x28adac <spSkeletonBounds_getPolygon+0x34>
 *   @0x28ad9c b 0x28adc8 <spSkeletonBounds_getPolygon+0x50>
 *   @0x28ada0 ldr r12, [r2, #0x4]!
 *   @0x28ada4 cmp r12, r1
 *   @0x28ada8 beq 0x28adcc <spSkeletonBounds_getPolygon+0x54>
 *   @0x28adac add r3, r3, #1
 *   @0x28adb0 cmp r3, r4
 *   @0x28adb4 lsl r5, r3, #2
 *   @0x28adb8 bne 0x28ada0 <spSkeletonBounds_getPolygon+0x28>
 *   @0x28adbc mov r0, #0
 *   @0x28adc0 pop {r4, r5}
 *   @0x28adc4 bx lr
 *   @0x28adc8 mov r5, #0
 *   @0x28adcc ldr r3, [r0, #0x8]
 *   @0x28add0 ldr r0, [r3, r5]
 *   @0x28add4 pop {r4, r5}
 *   @0x28add8 bx lr
 *
 * ══ §58/321 Java_com_yoyogames_runner_RunnerJNILib_dsListAddString  0x292bd4  size 100  25 条（0x292bd4..0x292c38）
 * @func 0x292bd4 0x292c38  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / dsListAddString
 * 字段偏移 top8: 0x2a4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292bd4 push {r3, r4, r5, r6, r7, lr}
 *   @0x292bd8 mov r4, r0
 *   @0x292bdc mov r5, r3
 *   @0x292be0 mov r7, r2
 *   @0x292be4 bl 0x290614 <setJNIEnv>
 *   @0x292be8 ldr r3, [r4]
 *   @0x292bec mov r1, r5
 *   @0x292bf0 mov r2, #0
 *   @0x292bf4 mov r0, r4
 *   @0x292bf8 ldr r3, [r3, #0x2a4]
 *   @0x292bfc blx r3
 *   @0x292c00 mov r6, r0
 *   @0x292c04 mov r0, r7
 *   @0x292c08 mov r1, r6
 *   @0x292c0c bl 0x101d20 <dsListAddString>
 *   @0x292c10 cmp r6, #0
 *   @0x292c14 cmpne r5, #0
 *   @0x292c18 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x292c1c ldr r3, [r4]
 *   @0x292c20 mov r1, r5
 *   @0x292c24 mov r2, r6
 *   @0x292c28 mov r0, r4
 *   @0x292c2c ldr r3, [r3, #0x2a8]
 *   @0x292c30 blx r3
 *   @0x292c34 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §59/321 png_write_chunk_start  0x2b11a0  size 100  25 条（0x2b11a0..0x2b1204）
 * @func 0x2b11a0 0x2b1204  size 100  25 条
 * 部分覆盖: 本节 25/44 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_data / png_reset_crc / 0xb65d4
 * 字段偏移 top8: 0x5c×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b11a0 ldr r3, [pc, #0x5c]
 *   @0x2b11a4 add r3, pc
 *   @0x2b11a8 mov r5, r1
 *   @0x2b11ac ldr r1, [r3]
 *   @0x2b11b0 mov r7, r3
 *   @0x2b11b4 cbz r0, 0x2b11f0 <png_write_chunk_start+0x50>
 *   @0x2b11b8 movs r3, #0x22
 *   @0x2b11bc str.w r3, [r0, #0x334]
 *   @0x2b11c0 mov r0, r6
 *   @0x2b11c4 stmdavs r8!, {r0, r1, r2, r3, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2b11c8 mov r1, r6
 *   @0x2b11cc str r0, [sp, #0x8]
 *   @0x2b11d0 bl 0x2afbf0 <png_write_data>
 *   @0x2b11d4 ldr r3, [r5]
 *   @0x2b11d8 str.w r3, [r4, #0x1e0]
 *   @0x2b11dc bl 0x2a5af4 <png_reset_crc>
 *   @0x2b11e0 mov r0, r4
 *   @0x2b11e4 movs r2, #0x4
 *   @0x2b11e8 movths pc, #0x2c8f
 *   @0x2b11ec str.w r3, [r4, #0x334]
 *   @0x2b11f0 ldr r2, [sp, #0xc]
 *   @0x2b11f4 cmp r2, r3
 *   @0x2b11f8 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b11fc add sp, #0x14
 *   @0x2b1200 stm r7!, {r4, r5, r7}
 *
 * ══ §60/321 jinit_huff_decoder  0x2bf19c  size 100  25 条（0x2bf19c..0x2bf200）
 * @func 0x2bf19c 0x2bf200  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×3 / 0x4×1 / 0x198×1 / 0x28×1 / 0x3c×1 / 0x2c×1 / 0x40×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bf19c ldr r3, [r0, #0x4]
 *   @0x2bf1a0 mov r1, #1
 *   @0x2bf1a4 push {r4, lr}
 *   @0x2bf1a8 mov r2, #172
 *   @0x2bf1ac ldr r3, [r3]
 *   @0x2bf1b0 mov r4, r0
 *   @0x2bf1b4 blx r3
 *   @0x2bf1b8 ldr r1, [pc, #0x38]
 *   @0x2bf1bc ldr r2, [pc, #0x38]
 *   @0x2bf1c0 mov r3, #0
 *   @0x2bf1c4 add r1, pc, r1
 *   @0x2bf1c8 add r2, pc, r2
 *   @0x2bf1cc str r0, [r4, #0x198]
 *   @0x2bf1d0 stm r0, {r1, r2}
 *   @0x2bf1d4 str r3, [r0, #0x38]
 *   @0x2bf1d8 str r3, [r0, #0x28]
 *   @0x2bf1dc str r3, [r0, #0x3c]
 *   @0x2bf1e0 str r3, [r0, #0x2c]
 *   @0x2bf1e4 str r3, [r0, #0x40]
 *   @0x2bf1e8 str r3, [r0, #0x30]
 *   @0x2bf1ec str r3, [r0, #0x44]
 *   @0x2bf1f0 str r3, [r0, #0x34]
 *   @0x2bf1f4 pop {r4, pc}
 *   @0x2bf1f8 .word 0xfffff6e4
 *   @0x2bf1fc .word 0xfffffac4
 *
 * ══ §61/321 FreeLastSavedImage(GifFileType*)  0x2c306c  size 100  25 条（0x2c306c..0x2c30d0）
 * @func 0x2c306c 0x2c30d0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GifFreeMapObject(ColorMapObject*) / 0xb655c
 * 字段偏移 top8: 0x18×3 / 0x14×2 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c306c cmp r0, #0
 *   @0x2c3070 push {r4, lr}
 *   @0x2c3074 popeq {r4, pc}
 *   @0x2c3078 ldr r2, [r0, #0x34]
 *   @0x2c307c cmp r2, #0
 *   @0x2c3080 popeq {r4, pc}
 *   @0x2c3084 ldr r3, [r0, #0x18]
 *   @0x2c3088 sub r3, r3, #1
 *   @0x2c308c str r3, [r0, #0x18]
 *   @0x2c3090 add r3, r3, r3, lsl #3
 *   @0x2c3094 add r4, r2, r3, lsl #2
 *   @0x2c3098 ldr r0, [r4, #0x14]
 *   @0x2c309c cmp r0, #0
 *   @0x2c30a0 beq 0x2c30b0 <_Z18FreeLastSavedImageP11GifFileType+0x44>
 *   @0x2c30a4 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c30a8 mov r3, #0
 *   @0x2c30ac str r3, [r4, #0x14]
 *   @0x2c30b0 ldr r0, [r4, #0x18]
 *   @0x2c30b4 cmp r0, #0
 *   @0x2c30b8 beq 0x2c30c0 <_Z18FreeLastSavedImageP11GifFileType+0x54>
 *   @0x2c30bc bl 0xb655c <free@plt>
 *   @0x2c30c0 add r0, r4, #28
 *   @0x2c30c4 add r1, r4, #32
 *   @0x2c30c8 pop {r4, lr}
 *   @0x2c30cc b 0x2c2ff8 <_Z17GifFreeExtensionsPiPP14ExtensionBlock>
 *
 * ══ §62/321 b2CircleShape::TestPoint(b2Transform const&, b2Vec2 const&) const  0x2c4d40  size 100  25 条（0x2c4d40..0x2c4da4）
 * @func 0x2c4d40 0x2c4da4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 22 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4d40 vldr s8, [r0, #16]
 *   @0x2c4d44 vldr s10, [r1, #12]
 *   @0x2c4d48 vmul.f32 s13, s10, s8
 *   @0x2c4d4c vldr s11, [r0, #12]
 *   @0x2c4d50 vldr s9, [r1, #8]
 *   @0x2c4d54 vldr s5, [r1, #4]
 *   @0x2c4d58 vldr s15, [r2, #4]
 *   @0x2c4d5c vldr s6, [r1]
 *   @0x2c4d60 vldr s7, [r2]
 *   @0x2c4d64 vldr s12, [r0, #8]
 *   @0x2c4d68 vmul.f32 s14, s9, s8
 *   @0x2c4d6c vmla.f32 s13, s11, s9
 *   @0x2c4d70 vnmls.f32 s14, s10, s11
 *   @0x2c4d74 vadd.f32 s13, s13, s5
 *   @0x2c4d78 vsub.f32 s15, s15, s13
 *   @0x2c4d7c vadd.f32 s14, s14, s6
 *   @0x2c4d80 vmul.f32 s15, s15, s15
 *   @0x2c4d84 vsub.f32 s14, s7, s14
 *   @0x2c4d88 vmla.f32 s15, s14, s14
 *   @0x2c4d8c vmul.f32 s12, s12, s12
 *   @0x2c4d90 vcmpe.f32 s12, s15
 *   @0x2c4d94 vmrs APSR_nzcv, fpscr
 *   @0x2c4d98 movlt r0, #0
 *   @0x2c4d9c movge r0, #1
 *   @0x2c4da0 bx lr
 *
 * ══ §63/321 FT_Select_Metrics  0x2e5524  size 100  25 条（0x2e5524..0x2e5588）
 * @func 0x2e5524 0x2e5588  size 100  25 条
 * 部分覆盖: 本节 25/48 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×3 / 0x20×2 / 0xc×2 / 0x58×1 / 0x14×1 / 0x1c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5524 push {r4, r5, r6, lr}
 *   @0x2e5528 ldr r2, [r0, #0x20]
 *   @0x2e552c ldr r4, [r0, #0x58]
 *   @0x2e5530 ldr r3, [r5, #0x8]
 *   @0x2e5534 asrs r3, r3, #0x6
 *   @0x2e5538 ldr r3, [r5, #0xc]
 *   @0x2e553c asrs r3, r3, #0x6
 *   @0x2e5540 ldr r3, [r0, #0x8]
 *   @0x2e5544 andsle r0, r2, r1, lsl #6
 *   @0x2e5548 ldrh.w r1, [r6, #0x44]
 *   @0x2e554c ldr r0, [r5, #0x8]
 *   @0x2e5550 strhvs pc, [r0, -r2]!
 *   @0x2e5554 ldrh.w r1, [r6, #0x44]
 *   @0x2e5558 ldr r0, [r5, #0xc]
 *   @0x2e555c .word 0xf104fcac
 *   @0x2e5560 .word 0x6160010c
 *   @0x2e5564 mov r0, r6
 *   @0x2e5568 .word 0xf7ff4070
 *   @0x2e556c .word 0xf44fbc7d
 *   @0x2e5570 smlawbvs r0, r0, r0, r3
 *   @0x2e5574 str r0, [r4, #0x14]
 *   @0x2e5578 str r3, [r4, #0x1c]
 *   @0x2e557c ldrsh r3, [r2, r1]
 *   @0x2e5580 str r3, [r4, #0x20]
 *   @0x2e5584 str r3, [r4, #0x24]
 *
 * ══ §64/321 FT_Raccess_Guess  0x2e68cc  size 100  25 条（0x2e68cc..0x2e6930）
 * @func 0x2e68cc 0x2e6930  size 100  25 条
 * 部分覆盖: 本节 25/48 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e68cc push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e68d0 movs r4, #0x0
 *   @0x2e68d4 addlt r11, r5, r8, asr r0
 *   @0x2e68d8 mov r8, r0
 *   @0x2e68dc add r11, pc
 *   @0x2e68e0 mov r6, r3
 *   @0x2e68e4 mov r3, r6
 *   @0x2e68e8 .word 0xb147ab04
 *   @0x2e68ec mov r0, r7
 *   @0x2e68f0 str r3, [sp, #0xc]
 *   @0x2e68f4 stcls p15, c15, [pc, #-864]
 *   @0x2e68f8 str r0, [r5, r4]
 *   @0x2e68fc b 0x2e6902 <FT_Raccess_Guess+0x36>
 *   @0x2e6900 str r7, [r5, r4]
 *   @0x2e6904 ldr r2, [r5, r4]
 *   @0x2e6908 ldr r2, [sp, #0x38]
 *   @0x2e690c ldr.w r5, [r11, r4, lsl #1]
 *   @0x2e6910 mov r1, r7
 *   @0x2e6914 str r2, [sp]
 *   @0x2e6918 blx r5
 *   @0x2e691c str r0, [r5, r4]
 *   @0x2e6920 cmp r4, #0x24
 *   @0x2e6924 add sp, #0x14
 *   @0x2e6928 svclt #0x8ff0
 *   @0x2e692c movs r0, #0x88
 *
 * ══ §65/321 FT_Vector_Rotate  0x2e6fc4  size 100  25 条（0x2e6fc4..0x2e7028）
 * @func 0x2e6fc4 0x2e7028  size 100  25 条
 * 部分覆盖: 本节 25/46 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e490c+0x1b8 / FT_Vector_Rotate+0x54 / 0x3c4ba8
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6fc4 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e6fc8 mov r4, r0
 *   @0x2e6fcc cbz r1, 0x2e7024 <FT_Vector_Rotate+0x60>
 *   @0x2e6fd0 stm.w sp, {r0, r1}
 *   @0x2e6fd4 cbnz r0, 0x2e6fd8 <FT_Vector_Rotate+0x14>
 *   @0x2e6fd8 mov r0, sp
 *   @0x2e6fdc shsub8mi pc, r9, pc
 *   @0x2e6fe0 mov r5, r0
 *   @0x2e6fe4 bl 0x2e4ac4 <_ZNK11b2GearJoint8GetRatioEv+0x1c0>
 *   @0x2e6fe8 ldr r0, [sp]
 *   @0x2e6fec .word 0x4606fd3e
 *   @0x2e6ff0 ldr r0, [sp, #0x4]
 *   @0x2e6ff4 stchs p13, c15, [r0, #-232]
 *   @0x2e6ff8 ble 0x2e7018 <FT_Vector_Rotate+0x54>
 *   @0x2e6ffc movs r2, #0x1
 *   @0x2e7000 ldmne r2!, {r0, r1, r8, r9, r12, sp, lr, pc} ^
 *   @0x2e7004 add r3, r0
 *   @0x2e7008 bl 0x3c4ba8 <error_g0017+0x1d84c>
 *   @0x2e700c smulwtmi lr, r0, r0
 *   @0x2e7010 asr.w r5, r0, r5
 *   @0x2e7014 str r6, [r4]
 *   @0x2e7018 rsbs r5, r5, #0
 *   @0x2e701c lsl.w r5, r0, r5
 *   @0x2e7020 str r6, [r4]
 *   @0x2e7024 add sp, #0xc
 *
 * ══ §66/321 png_get_pCAL  0x2a6a08  size 98  25 条（0x2a6a08..0x2a6a6a）
 * @func 0x2a6a08 0x2a6a6c  size 100  25 条
 * 部分覆盖: 本节 25/44 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6a08 push {r4, r5, r6, r7, lr}
 *   @0x2a6a0c ldr r6, [sp, #0x18]
 *   @0x2a6a10 ldr r4, [sp, #0x20]
 *   @0x2a6a14 teqlt r8, #36
 *   @0x2a6a18 cbz r1, 0x2a6a66 <png_get_pCAL+0x5e>
 *   @0x2a6a1c ands r0, r0, #0x400
 *   @0x2a6a20 beq 0x2a6a68 <png_get_pCAL+0x60>
 *   @0x2a6a24 cbz r3, 0x2a6a66 <png_get_pCAL+0x5e>
 *   @0x2a6a28 cbz r6, 0x2a6a66 <png_get_pCAL+0x5e>
 *   @0x2a6a2c cbz r4, 0x2a6a66 <png_get_pCAL+0x5e>
 *   @0x2a6a30 andsle r0, r8, r0, lsl #30
 *   @0x2a6a34 ldr.w r0, [r1, #0xa0]
 *   @0x2a6a38 str r0, [r2]
 *   @0x2a6a3c .word 0xf8d16080
 *   @0x2a6a40 andsvs r2, r10, r4, lsr #1
 *   @0x2a6a44 ldr.w r3, [r1, #0xa8]
 *   @0x2a6a48 str r3, [r7]
 *   @0x2a6a4c ldrhtvs r3, [r3], -r4
 *   @0x2a6a50 ldrb.w r3, [r1, #0xb5]
 *   @0x2a6a54 str r3, [r5]
 *   @0x2a6a58 eorvs r3, r3, r12, lsr #1
 *   @0x2a6a5c ldr.w r3, [r1, #0xb0]
 *   @0x2a6a60 str.w r3, [r12]
 *   @0x2a6a64 pop {r4, r5, r6, r7, pc}
 *   @0x2a6a68 pop {r4, r5, r6, r7, pc}
 *
 * ══ §67/321 Background_InitTextures()  0xc3578  size 96  24 条（0xc3578..0xc35d8）
 * @func 0xc3578 0xc35d8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::InitTexture() / CBackground::InitLocalTPE()
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x4c×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3578 push {r4, r5, r6, lr}
 *   @0xc357c ldr r6, [pc, #0x4c]
 *   @0xc3580 ldr r6, [pc, r6]
 *   @0xc3584 ldr r3, [r6]
 *   @0xc3588 cmp r3, #0
 *   @0xc358c pople {r4, r5, r6, pc}
 *   @0xc3590 ldr r5, [pc, #0x3c]
 *   @0xc3594 mov r4, #0
 *   @0xc3598 add r5, pc, r5
 *   @0xc359c ldr r3, [r5, #0x4]
 *   @0xc35a0 ldr r0, [r3, r4, lsl #2]
 *   @0xc35a4 cmp r0, #0
 *   @0xc35a8 beq 0xc35bc <_Z23Background_InitTexturesv+0x44>
 *   @0xc35ac bl 0xc1e60 <_ZN11CBackground11InitTextureEv>
 *   @0xc35b0 ldr r3, [r5, #0x4]
 *   @0xc35b4 ldr r0, [r3, r4, lsl #2]
 *   @0xc35b8 bl 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv>
 *   @0xc35bc ldr r3, [r6]
 *   @0xc35c0 add r4, r4, #1
 *   @0xc35c4 cmp r3, r4
 *   @0xc35c8 bgt 0xc359c <_Z23Background_InitTexturesv+0x24>
 *   @0xc35cc pop {r4, r5, r6, pc}
 *   @0xc35d0 eorseq r10, r2, r8, asr #7
 *   @0xc35d4 eorseq r6, r11, r0, lsl r7
 *
 * ══ §68/321 strlwr(char*)  0xc4a14  size 96  24 条（0xc4a14..0xc4a74）
 * @func 0xc4a14 0xc4a84  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0x30×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4a14 ldrb r3, [r0]
 *   @0xc4a18 push {r4, r5}
 *   @0xc4a1c cmp r3, #0
 *   @0xc4a20 beq 0xc4a64 <_Z6strlwrPc+0x50>
 *   @0xc4a24 ldr r5, [pc, #0x40]
 *   @0xc4a28 add r2, r0, #1
 *   @0xc4a2c ldr r5, [pc, r5]
 *   @0xc4a30 ldr r12, [r5]
 *   @0xc4a34 add r3, r3, #1
 *   @0xc4a38 ldr r1, [pc, #0x30]
 *   @0xc4a3c lsl r4, r3, #1
 *   @0xc4a40 ldrb r3, [r12, r3]
 *   @0xc4a44 tst r3, #1
 *   @0xc4a48 ldrne r1, [pc, r1]
 *   @0xc4a4c ldrne r3, [r1]
 *   @0xc4a50 ldrhne r3, [r3, r4]
 *   @0xc4a54 strbne r3, [r2, #-0x1]
 *   @0xc4a58 ldrb r3, [r2], #1
 *   @0xc4a5c cmp r3, #0
 *   @0xc4a60 bne 0xc4a30 <_Z6strlwrPc+0x1c>
 *   @0xc4a64 pop {r4, r5}
 *   @0xc4a68 bx lr
 *   @0xc4a6c eorseq r8, r2, r4, asr pc
 *   @0xc4a70 eorseq r8, r2, r12, lsr pc
 *
 * ══ §69/321 strupr(char*)  0xc4a74  size 96  24 条（0xc4a74..0xc4ad4）
 * @func 0xc4a74 0xc4ad4  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0x30×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4a74 ldrb r3, [r0]
 *   @0xc4a78 push {r4, r5}
 *   @0xc4a7c cmp r3, #0
 *   @0xc4a80 beq 0xc4ac4 <_Z6struprPc+0x50>
 *   @0xc4a84 ldr r5, [pc, #0x40]
 *   @0xc4a88 add r2, r0, #1
 *   @0xc4a8c ldr r5, [pc, r5]
 *   @0xc4a90 ldr r12, [r5]
 *   @0xc4a94 add r3, r3, #1
 *   @0xc4a98 ldr r1, [pc, #0x30]
 *   @0xc4a9c lsl r4, r3, #1
 *   @0xc4aa0 ldrb r3, [r12, r3]
 *   @0xc4aa4 tst r3, #2
 *   @0xc4aa8 ldrne r1, [pc, r1]
 *   @0xc4aac ldrne r3, [r1]
 *   @0xc4ab0 ldrhne r3, [r3, r4]
 *   @0xc4ab4 strbne r3, [r2, #-0x1]
 *   @0xc4ab8 ldrb r3, [r2], #1
 *   @0xc4abc cmp r3, #0
 *   @0xc4ac0 bne 0xc4a90 <_Z6struprPc+0x1c>
 *   @0xc4ac4 pop {r4, r5}
 *   @0xc4ac8 bx lr
 *   @0xc4acc ldrshteq r8, [r2], -r4
 *   @0xc4ad0 eorseq r8, r2, r0, ror #29
 *
 * ══ §70/321 YYGML_BUFFER_Write(int, int, YYRValue const&)  0xc7064  size 96  24 条（0xc7064..0xc70c4）
 * @func 0xc7064 0xc70c4  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_BUFFER_Write(int, int, YYRValue const&)+0x40 / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x44×1 / 0x4×1 / 0x2×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7064 cmp r0, #0
 *   @0xc7068 push {r3, lr}
 *   @0xc706c blt 0xc70a4 <_Z18YYGML_BUFFER_WriteiiRK8YYRValue+0x40>
 *   @0xc7070 ldr r3, [pc, #0x44]
 *   @0xc7074 add r3, pc, r3
 *   @0xc7078 ldr r12, [r3]
 *   @0xc707c cmp r0, r12
 *   @0xc7080 bge 0xc70a4 <_Z18YYGML_BUFFER_WriteiiRK8YYRValue+0x40>
 *   @0xc7084 ldr r3, [r3, #0x4]
 *   @0xc7088 ldr r0, [r3, r0, lsl #2]
 *   @0xc708c cmp r0, #0
 *   @0xc7090 beq 0xc70a4 <_Z18YYGML_BUFFER_WriteiiRK8YYRValue+0x40>
 *   @0xc7094 ldr r3, [r0]
 *   @0xc7098 ldr r3, [r3, #0x8]
 *   @0xc709c blx r3
 *   @0xc70a0 pop {r3, pc}
 *   @0xc70a4 ldr r0, [pc, #0x14]
 *   @0xc70a8 mov r1, #0
 *   @0xc70ac add r0, pc, r0
 *   @0xc70b0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc70b4 mvn r0, #0
 *   @0xc70b8 pop {r3, pc}
 *   @0xc70bc eorseq r3, r11, r0, lsr #1
 *   @0xc70c0 eoreq r9, r6, r8, lsl #22
 *
 * ══ §71/321 F_Vertex_ARGB_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc93f4  size 96  24 条（0xc93f4..0xc9454）
 * @func 0xc93f4 0xc9464  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc93f4 push {r3, r4, r5, lr}
 *   @0xc93f8 mov r1, r3
 *   @0xc93fc ldr r4, [sp, #0x10]
 *   @0xc9400 mov r3, #2
 *   @0xc9404 mov r2, r4
 *   @0xc9408 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc940c cmp r0, #0
 *   @0xc9410 popeq {r3, r4, r5, pc}
 *   @0xc9414 mov r1, #2
 *   @0xc9418 mov r2, #5
 *   @0xc941c bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType>
 *   @0xc9420 subs r5, r0, #0
 *   @0xc9424 popeq {r3, r4, r5, pc}
 *   @0xc9428 mov r0, r4
 *   @0xc942c mov r1, #1
 *   @0xc9430 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc9434 bic r3, r0, #16711680
 *   @0xc9438 ubfx r2, r0, #0x10, #0x8
 *   @0xc943c bic r3, r3, #255
 *   @0xc9440 uxtb r0, r0
 *   @0xc9444 orr r3, r3, r2
 *   @0xc9448 orr r3, r3, r0, lsl #16
 *   @0xc944c str r3, [r5]
 *   @0xc9450 pop {r3, r4, r5, pc}
 *
 * ══ §72/321 AddActiveInstances(CObjectGM*)  0xd7ca0  size 96  24 条（0xd7ca0..0xd7d00）
 * @func 0xd7ca0 0xd7d00  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HandleInstance(CInstance*)
 * 字段偏移 top8: 0x8×3 / 0xd0×1 / 0x68×1 / 0x69×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd7ca0 push {r4, lr}
 *   @0xd7ca4 ldr r4, [r0, #0xd0]
 *   @0xd7ca8 cmp r4, #0
 *   @0xd7cac popeq {r4, pc}
 *   @0xd7cb0 ldr r3, [r4, #0x8]
 *   @0xd7cb4 cmp r3, #0
 *   @0xd7cb8 popeq {r4, pc}
 *   @0xd7cbc ldr r0, [r4, #0x8]
 *   @0xd7cc0 ldr r4, [r4]
 *   @0xd7cc4 cmp r0, #0
 *   @0xd7cc8 beq 0xd7ce8 <_Z18AddActiveInstancesP9CObjectGM+0x48>
 *   @0xd7ccc ldrb r3, [r0, #0x68]
 *   @0xd7cd0 cmp r3, #0
 *   @0xd7cd4 bne 0xd7ce8 <_Z18AddActiveInstancesP9CObjectGM+0x48>
 *   @0xd7cd8 ldrb r3, [r0, #0x69]
 *   @0xd7cdc cmp r3, #0
 *   @0xd7ce0 bne 0xd7ce8 <_Z18AddActiveInstancesP9CObjectGM+0x48>
 *   @0xd7ce4 bl 0xd3fd0 <_Z14HandleInstanceP9CInstance>
 *   @0xd7ce8 cmp r4, #0
 *   @0xd7cec popeq {r4, pc}
 *   @0xd7cf0 ldr r3, [r4, #0x8]
 *   @0xd7cf4 cmp r3, #0
 *   @0xd7cf8 bne 0xd7cbc <_Z18AddActiveInstancesP9CObjectGM+0x1c>
 *   @0xd7cfc pop {r4, pc}
 *
 * ══ §73/321 questionDialogAsync  0xf2a70  size 96  24 条（0xf2a70..0xf2ad0）
 * @func 0xf2a70 0xf2ad0  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2a70 push {r4, r5, lr}
 *   @0xf2a74 sub sp, sp, #12
 *   @0xf2a78 mov r4, r2
 *   @0xf2a7c mov r5, r1
 *   @0xf2a80 bl 0x290274 <getJNIEnv>
 *   @0xf2a84 mov r1, r5
 *   @0xf2a88 ldr r3, [r0]
 *   @0xf2a8c ldr r3, [r3, #0x29c]
 *   @0xf2a90 blx r3
 *   @0xf2a94 mov r5, r0
 *   @0xf2a98 bl 0x290274 <getJNIEnv>
 *   @0xf2a9c ldr r1, [pc, #0x24]
 *   @0xf2aa0 mov r3, r5
 *   @0xf2aa4 ldr r12, [pc, #0x20]
 *   @0xf2aa8 ldr r1, [pc, r1]
 *   @0xf2aac ldr r12, [pc, r12]
 *   @0xf2ab0 ldr r1, [r1]
 *   @0xf2ab4 ldr r2, [r12]
 *   @0xf2ab8 str r4, [sp]
 *   @0xf2abc bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0xf2ac0 add sp, sp, #12
 *   @0xf2ac4 pop {r4, r5, pc}
 *   @0xf2ac8 .word 0x002faefc
 *   @0xf2acc eoreq r11, pc, r12, asr r3
 *
 * ══ §74/321 showMessage  0xf2b4c  size 96  24 条（0xf2b4c..0xf2bac）
 * @func 0xf2b4c 0xf2bac  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2b4c push {r4, r5, lr}
 *   @0xf2b50 sub sp, sp, #12
 *   @0xf2b54 mov r4, r2
 *   @0xf2b58 mov r5, r1
 *   @0xf2b5c bl 0x290274 <getJNIEnv>
 *   @0xf2b60 mov r1, r5
 *   @0xf2b64 ldr r3, [r0]
 *   @0xf2b68 ldr r3, [r3, #0x29c]
 *   @0xf2b6c blx r3
 *   @0xf2b70 mov r5, r0
 *   @0xf2b74 bl 0x290274 <getJNIEnv>
 *   @0xf2b78 ldr r1, [pc, #0x24]
 *   @0xf2b7c mov r3, r5
 *   @0xf2b80 ldr r12, [pc, #0x20]
 *   @0xf2b84 ldr r1, [pc, r1]
 *   @0xf2b88 ldr r12, [pc, r12]
 *   @0xf2b8c ldr r1, [r1]
 *   @0xf2b90 ldr r2, [r12]
 *   @0xf2b94 str r4, [sp]
 *   @0xf2b98 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0xf2b9c add sp, sp, #12
 *   @0xf2ba0 pop {r4, r5, pc}
 *   @0xf2ba4 eoreq r10, pc, r0, lsr #28
 *   @0xf2ba8 eoreq r11, pc, r8, lsl #5
 *
 * ══ §75/321 F_PositionEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0x109a58  size 96  24 条（0x109a58..0x109ab8）
 * @func 0x109a58 0x109ab8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / Command_ObjectAt(float, float, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109a58 push {r3, r4, r5, r6, r7, lr}
 *   @0x109a5c mov r5, #0
 *   @0x109a60 ldr r6, [sp, #0x18]
 *   @0x109a64 mov r4, r0
 *   @0x109a68 str r5, [r0, #0xc]
 *   @0x109a6c mov r1, r5
 *   @0x109a70 mov r0, r6
 *   @0x109a74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109a78 mov r1, #1
 *   @0x109a7c mov r7, r0
 *   @0x109a80 mov r0, r6
 *   @0x109a84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109a88 mvn r2, #2
 *   @0x109a8c mov r1, r0
 *   @0x109a90 mov r0, r7
 *   @0x109a94 bl 0x1c9da8 <_Z16Command_ObjectAtffi>
 *   @0x109a98 cmp r0, #0
 *   @0x109a9c moveq r3, #0
 *   @0x109aa0 moveq r5, r0
 *   @0x109aa4 movteq r3, #0x3ff0
 *   @0x109aa8 movne r3, r5
 *   @0x109aac str r5, [r4]
 *   @0x109ab0 str r3, [r4, #0x4]
 *   @0x109ab4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §76/321 F_Lerp(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e018  size 96  24 条（0x10e018..0x10e078）
 * @func 0x10e018 0x10e078  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e018 push {r3, r4, r5, lr}
 *   @0x10e01c vpush {d8, d9}
 *   @0x10e020 mov r5, r0
 *   @0x10e024 ldr r4, [sp, #0x20]
 *   @0x10e028 mov r1, #0
 *   @0x10e02c str r1, [r0, #0xc]
 *   @0x10e030 mov r0, r4
 *   @0x10e034 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e038 vmov d8, r0, r1
 *   @0x10e03c mov r0, r4
 *   @0x10e040 mov r1, #1
 *   @0x10e044 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e048 vmov d6, r0, r1
 *   @0x10e04c mov r0, r4
 *   @0x10e050 mov r1, #2
 *   @0x10e054 vsub.f64 d9, d6, d8
 *   @0x10e058 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e05c vmov.f64 d7, d8
 *   @0x10e060 vmov d6, r0, r1
 *   @0x10e064 vmla.f64 d7, d9, d6
 *   @0x10e068 vmov r2, r3, d7
 *   @0x10e06c stm r5, {r2, r3}
 *   @0x10e070 vpop {d8, d9}
 *   @0x10e074 pop {r3, r4, r5, pc}
 *
 * ══ §77/321 F_ArrayGet2D(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f408  size 96  24 条（0x10f408..0x10f468）
 * @func 0x10f408 0x10f468  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f408 cmp r3, #3
 *   @0x10f40c push {r3, r4, r5, r6, r7, lr}
 *   @0x10f410 mov r5, r0
 *   @0x10f414 ldr r4, [sp, #0x18]
 *   @0x10f418 popne {r3, r4, r5, r6, r7, pc}
 *   @0x10f41c ldr r6, [r4, #0xc]
 *   @0x10f420 cmp r6, #2
 *   @0x10f424 popne {r3, r4, r5, r6, r7, pc}
 *   @0x10f428 ldr r3, [r4]
 *   @0x10f42c cmp r3, #0
 *   @0x10f430 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x10f434 mov r0, r4
 *   @0x10f438 mov r1, #1
 *   @0x10f43c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10f440 mov r1, r6
 *   @0x10f444 mov r7, r0
 *   @0x10f448 mov r0, r4
 *   @0x10f44c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10f450 mov r2, #32000
 *   @0x10f454 mov r1, r4
 *   @0x10f458 mla r2, r2, r7, r0
 *   @0x10f45c mov r0, r5
 *   @0x10f460 pop {r3, r4, r5, r6, r7, lr}
 *   @0x10f464 b 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *
 * ══ §78/321 F_DateHourSpan(RValue&, CInstance*, CInstance*, int, RValue*)  0x115504  size 96  24 条（0x115504..0x115564）
 * @func 0x115504 0x115564  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115504 push {r3, r4, r5, lr}
 *   @0x115508 vpush {d8}
 *   @0x11550c mov r3, #0
 *   @0x115510 ldr r5, [sp, #0x18]
 *   @0x115514 mov r1, r3
 *   @0x115518 str r3, [r0, #0xc]
 *   @0x11551c mov r4, r0
 *   @0x115520 str r3, [r0]
 *   @0x115524 str r3, [r0, #0x4]
 *   @0x115528 mov r0, r5
 *   @0x11552c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115530 vmov d8, r0, r1
 *   @0x115534 mov r0, r5
 *   @0x115538 mov r1, #1
 *   @0x11553c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115540 vmov.f64 d7, #2.400000e+01
 *   @0x115544 vmov d6, r0, r1
 *   @0x115548 vsub.f64 d8, d8, d6
 *   @0x11554c vmul.f64 d8, d8, d7
 *   @0x115550 vabs.f64 d7, d8
 *   @0x115554 vmov r2, r3, d7
 *   @0x115558 stm r4, {r2, r3}
 *   @0x11555c vpop {d8}
 *   @0x115560 pop {r3, r4, r5, pc}
 *
 * ══ §79/321 F_DisplaySetSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x119ed8  size 96  24 条（0x119ed8..0x119f38）
 * @func 0x119ed8 0x119f38  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / DisplaySetSize(int, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119ed8 push {r3, r4, r5, r6, r7, lr}
 *   @0x119edc mov r5, #0
 *   @0x119ee0 ldr r6, [sp, #0x18]
 *   @0x119ee4 mov r4, r0
 *   @0x119ee8 str r5, [r0, #0xc]
 *   @0x119eec mov r1, r5
 *   @0x119ef0 mov r0, r6
 *   @0x119ef4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119ef8 mov r1, #1
 *   @0x119efc mov r7, r0
 *   @0x119f00 mov r0, r6
 *   @0x119f04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119f08 mov r1, r0
 *   @0x119f0c mov r0, r7
 *   @0x119f10 bl 0x17db6c <_Z14DisplaySetSizeii>
 *   @0x119f14 cmp r0, #0
 *   @0x119f18 moveq r5, r0
 *   @0x119f1c movne r3, r5
 *   @0x119f20 moveq r3, r5
 *   @0x119f24 movtne r3, #0x3ff0
 *   @0x119f28 str r5, [r4]
 *   @0x119f2c str r3, [r4, #0x4]
 *   @0x119f30 pop {r3, r4, r5, r6, r7, lr}
 *   @0x119f34 b 0x168c24 <_Z12GR_D3D_Resetv>
 *
 * ══ §80/321 YYGML_draw_text_transformed(float, float, char const*, float, float, float)  0x122458  size 96  24 条（0x122458..0x1224b8）
 * @func 0x122458 0x1224b8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*) / GR_Text_Draw_Transformed(float, float, char const*, int, int, float, float, float)
 * 字段偏移 top8: 0x30×1 / 0x34×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122458 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x12245c sub sp, sp, #20
 *   @0x122460 mov r5, r0
 *   @0x122464 mov r0, r2
 *   @0x122468 mov r7, r3
 *   @0x12246c mov r6, r1
 *   @0x122470 ldr r8, [sp, #0x30]
 *   @0x122474 ldr r9, [sp, #0x34]
 *   @0x122478 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x12247c mvn r12, #0
 *   @0x122480 str r7, [sp, #0x4]
 *   @0x122484 str r8, [sp, #0x8]
 *   @0x122488 mov r1, r6
 *   @0x12248c str r9, [sp, #0xc]
 *   @0x122490 mov r3, r12
 *   @0x122494 str r12, [sp]
 *   @0x122498 mov r4, r0
 *   @0x12249c mov r2, r0
 *   @0x1224a0 mov r0, r5
 *   @0x1224a4 bl 0x173068 <_Z24GR_Text_Draw_TransformedffPKciifff>
 *   @0x1224a8 mov r0, r4
 *   @0x1224ac add sp, sp, #20
 *   @0x1224b0 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1224b4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §81/321 F_HighscoreSetColors(RValue&, CInstance*, CInstance*, int, RValue*)  0x1261a0  size 96  24 条（0x1261a0..0x126200）
 * @func 0x1261a0 0x126200  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x8×1 / 0x38×1 / 0x24×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1261a0 push {r4, lr}
 *   @0x1261a4 mov r1, #0
 *   @0x1261a8 ldr r4, [sp, #0x8]
 *   @0x1261ac mov r0, r4
 *   @0x1261b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1261b4 ldr r3, [pc, #0x38]
 *   @0x1261b8 mov r1, #1
 *   @0x1261bc ldr r3, [pc, r3]
 *   @0x1261c0 str r0, [r3]
 *   @0x1261c4 mov r0, r4
 *   @0x1261c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1261cc ldr r3, [pc, #0x24]
 *   @0x1261d0 mov r1, #2
 *   @0x1261d4 ldr r3, [pc, r3]
 *   @0x1261d8 str r0, [r3]
 *   @0x1261dc mov r0, r4
 *   @0x1261e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1261e4 ldr r3, [pc, #0x10]
 *   @0x1261e8 ldr r3, [pc, r3]
 *   @0x1261ec str r0, [r3]
 *   @0x1261f0 pop {r4, pc}
 *   @0x1261f4 .word 0x002c88b0
 *   @0x1261f8 mlaeq r12, r12, r8, r8
 *   @0x1261fc eoreq r8, r12, r12, lsl #17
 *
 * ══ §82/321 F_FileWriteString(RValue&, CInstance*, CInstance*, int, RValue*)  0x139cc8  size 96  24 条（0x139cc8..0x139d28）
 * @func 0x139cc8 0x139d28  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×2 / 0x3c×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139cc8 push {r3, lr}
 *   @0x139ccc mov r1, #0
 *   @0x139cd0 ldr r0, [sp, #0x8]
 *   @0x139cd4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x139cd8 ldr r3, [pc, #0x3c]
 *   @0x139cdc ldr r3, [pc, r3]
 *   @0x139ce0 ldr r3, [r3]
 *   @0x139ce4 cmp r3, #2
 *   @0x139ce8 bne 0x139d08 <_Z17F_FileWriteStringR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x139cec cmp r0, #0
 *   @0x139cf0 popeq {r3, pc}
 *   @0x139cf4 ldr r3, [pc, #0x24]
 *   @0x139cf8 ldr r3, [pc, r3]
 *   @0x139cfc ldr r1, [r3, #0x8]
 *   @0x139d00 pop {r3, lr}
 *   @0x139d04 b 0xb6898 <fputs@plt>
 *   @0x139d08 ldr r0, [pc, #0x14]
 *   @0x139d0c mov r1, #0
 *   @0x139d10 pop {r3, lr}
 *   @0x139d14 add r0, pc, r0
 *   @0x139d18 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139d1c mlaeq r11, r4, r5, r5
 *   @0x139d20 eoreq r5, r11, r12, ror r5
 *   @0x139d24 eoreq r6, r0, r8, ror r3
 *
 * ══ §83/321 F_ActionWebpage(RValue&, CInstance*, CInstance*, int, RValue*)  0x140210  size 96  24 条（0x140210..0x140270）
 * @func 0x140210 0x140270  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetCurrentDir() / YYGetString(RValue const*, int) / File_ShellExecute(char const*, char const*, char const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×1 / 0x2c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140210 push {r3, r4, r5, lr}
 *   @0x140214 ldr r5, [sp, #0x10]
 *   @0x140218 bl 0x214e1c <_Z13GetCurrentDirv>
 *   @0x14021c mov r1, #0
 *   @0x140220 mov r4, r0
 *   @0x140224 mov r0, r5
 *   @0x140228 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x14022c cmp r0, #0
 *   @0x140230 beq 0x14024c <_Z15F_ActionWebpageR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x140234 ldr r1, [pc, #0x2c]
 *   @0x140238 mov r2, r4
 *   @0x14023c add r1, pc, r1
 *   @0x140240 bl 0x214ddc <_Z17File_ShellExecutePKcS0_S0_>
 *   @0x140244 cmp r0, #0
 *   @0x140248 bne 0x14025c <_Z15F_ActionWebpageR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14024c ldr r0, [pc, #0x18]
 *   @0x140250 mov r1, #0
 *   @0x140254 add r0, pc, r0
 *   @0x140258 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14025c mov r0, r4
 *   @0x140260 pop {r3, r4, r5, lr}
 *   @0x140264 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x140268 ldrsheq lr, [lr], -r10
 *   @0x14026c .word 0x002006d4
 *
 * ══ §84/321 F_ActionSetLife(RValue&, CInstance*, CInstance*, int, RValue*)  0x140c1c  size 96  24 条（0x140c1c..0x140c7c）
 * @func 0x140c1c 0x140c7c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x40×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140c1c push {r3, lr}
 *   @0x140c20 mov r1, #0
 *   @0x140c24 ldr r0, [sp, #0x8]
 *   @0x140c28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140c2c ldr r2, [pc, #0x40]
 *   @0x140c30 ldr r3, [pc, #0x40]
 *   @0x140c34 ldr r2, [pc, r2]
 *   @0x140c38 ldr r3, [pc, r3]
 *   @0x140c3c ldrb r1, [r2]
 *   @0x140c40 ldr r2, [r3]
 *   @0x140c44 cmp r1, #0
 *   @0x140c48 addne r0, r0, r2
 *   @0x140c4c cmp r2, #0
 *   @0x140c50 str r0, [r3]
 *   @0x140c54 pople {r3, pc}
 *   @0x140c58 ldr r3, [r3]
 *   @0x140c5c cmp r3, #0
 *   @0x140c60 popgt {r3, pc}
 *   @0x140c64 mov r0, #7
 *   @0x140c68 mov r1, #6
 *   @0x140c6c pop {r3, lr}
 *   @0x140c70 b 0xf33b0 <_Z17Perform_Event_Allii>
 *   @0x140c74 eoreq r12, r10, r8, lsl #30
 *   @0x140c78 mlaeq r10, r8, r7, lr
 *
 * ══ §85/321 YYGML_action_linear_step(CInstance*, float, float, float, bool)  0x1416cc  size 96  24 条（0x1416cc..0x14172c）
 * @func 0x1416cc 0x14172c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Motion_Linear_Step(CInstance*, float, float, float, int, bool)
 * 字段偏移 top8: 0x54×1 / 0x10×1 / 0x4×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1416cc ldr r12, [pc, #0x54]
 *   @0x1416d0 vmov s15, r2
 *   @0x1416d4 push {r4, lr}
 *   @0x1416d8 ldr r12, [pc, r12]
 *   @0x1416dc sub sp, sp, #8
 *   @0x1416e0 vmov s14, r1
 *   @0x1416e4 ldrb r12, [r12]
 *   @0x1416e8 ldrb lr, [sp, #0x10]
 *   @0x1416ec cmp r12, #0
 *   @0x1416f0 str lr, [sp, #0x4]
 *   @0x1416f4 vldrne s12, [r0, #180]
 *   @0x1416f8 vldrne s13, [r0, #184]
 *   @0x1416fc vaddne.f32 s12, s14, s12
 *   @0x141700 mvnne r2, #2
 *   @0x141704 mvneq r12, #2
 *   @0x141708 strne r2, [sp]
 *   @0x14170c streq r12, [sp]
 *   @0x141710 vaddne.f32 s13, s15, s13
 *   @0x141714 vmovne r1, s12
 *   @0x141718 vmovne r2, s13
 *   @0x14171c bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib>
 *   @0x141720 add sp, sp, #8
 *   @0x141724 pop {r4, pc}
 *   @0x141728 eoreq r12, r10, r4, ror #8
 *
 * ══ §86/321 YYGML_action_kill_object(CInstance*)  0x141a98  size 96  24 条（0x141a98..0x141af8）
 * @func 0x141a98 0x141af8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Perform_Event(CInstance*, CInstance*, int, int)×2
 * 字段偏移 top8: 0x6a×2 / 0x14×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141a98 push {r4, r5, r6, lr}
 *   @0x141a9c mov r4, r0
 *   @0x141aa0 ldrb r5, [r0, #0x6a]
 *   @0x141aa4 cmp r5, #0
 *   @0x141aa8 popne {r4, r5, r6, pc}
 *   @0x141aac mov r6, #1
 *   @0x141ab0 mov r1, r0
 *   @0x141ab4 strb r6, [r0, #0x6a]
 *   @0x141ab8 mov r2, r6
 *   @0x141abc mov r3, r5
 *   @0x141ac0 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x141ac4 mov r3, r5
 *   @0x141ac8 mov r2, #12
 *   @0x141acc mov r0, r4
 *   @0x141ad0 mov r1, r4
 *   @0x141ad4 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x141ad8 ldr r3, [pc, #0x14]
 *   @0x141adc strb r6, [r4, #0x68]
 *   @0x141ae0 ldr r3, [pc, r3]
 *   @0x141ae4 ldr r2, [r3]
 *   @0x141ae8 add r2, r2, r6
 *   @0x141aec str r2, [r3]
 *   @0x141af0 pop {r4, r5, r6, pc}
 *   @0x141af4 .word 0x002ac5d4
 *
 * ══ §87/321 F_PhysicsDebugRenderAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d148  size 96  24 条（0x14d148..0x14d1a8）
 * @func 0x14d148 0x14d1a8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0xb4×2 / 0x4c×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d148 push {r4, lr}
 *   @0x14d14c ldr r4, [pc, #0x4c]
 *   @0x14d150 ldr r0, [sp, #0x8]
 *   @0x14d154 ldr r4, [pc, r4]
 *   @0x14d158 ldr r3, [r4]
 *   @0x14d15c cmp r3, #0
 *   @0x14d160 beq 0x14d18c <_Z23F_PhysicsDebugRenderAllR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x14d164 ldr r3, [r3, #0xb4]
 *   @0x14d168 cmp r3, #0
 *   @0x14d16c beq 0x14d18c <_Z23F_PhysicsDebugRenderAllR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x14d170 mov r1, #0
 *   @0x14d174 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14d178 ldr r3, [r4]
 *   @0x14d17c pop {r4, lr}
 *   @0x14d180 mov r1, r0
 *   @0x14d184 ldr r0, [r3, #0xb4]
 *   @0x14d188 b 0x238438 <_ZN13CPhysicsWorld11DebugRenderEj>
 *   @0x14d18c ldr r0, [pc, #0x10]
 *   @0x14d190 mov r1, #0
 *   @0x14d194 pop {r4, lr}
 *   @0x14d198 add r0, pc, r0
 *   @0x14d19c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d1a0 .word 0x002a07d4
 *   @0x14d1a4 andseq r6, pc, r12, lsl #25
 *
 * ══ §88/321 F_YoYo_GetAdsWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1593a4  size 96  24 条（0x1593a4..0x159404）
 * @func 0x1593a4 0x159414  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_YoYo_GetAdsWidth(RValue&, CInstance*, CInstance*, int, RValue*)+0x3c / AdDisplayWidth(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1593a4 push {r3, r4, r5, lr}
 *   @0x1593a8 mov r4, #0
 *   @0x1593ac ldr r3, [sp, #0x10]
 *   @0x1593b0 mov r5, r0
 *   @0x1593b4 str r4, [r0, #0xc]
 *   @0x1593b8 mov r1, r4
 *   @0x1593bc mov r0, r3
 *   @0x1593c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1593c4 cmp r0, #4
 *   @0x1593c8 bls 0x1593e0 <_Z18F_YoYo_GetAdsWidthR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1593cc ldr r0, [pc, #0x2c]
 *   @0x1593d0 mov r1, r4
 *   @0x1593d4 pop {r3, r4, r5, lr}
 *   @0x1593d8 add r0, pc, r0
 *   @0x1593dc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1593e0 bl 0x15e4c8 <_Z14AdDisplayWidthi>
 *   @0x1593e4 vmov s15, r0
 *   @0x1593e8 vcvt.f64.s32 d7, s15
 *   @0x1593ec vmov r0, r1, d7
 *   @0x1593f0 vmov r2, s14
 *   @0x1593f4 mov r3, r1
 *   @0x1593f8 stm r5, {r2, r3}
 *   @0x1593fc pop {r3, r4, r5, pc}
 *   @0x159400 andseq sp, lr, r0, asr #13
 *
 * ══ §89/321 F_YoYo_GetAdsHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x159404  size 96  24 条（0x159404..0x159464）
 * @func 0x159404 0x159464  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_YoYo_GetAdsHeight(RValue&, CInstance*, CInstance*, int, RValue*)+0x3c / AdDisplayHeight(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159404 push {r3, r4, r5, lr}
 *   @0x159408 mov r4, #0
 *   @0x15940c ldr r3, [sp, #0x10]
 *   @0x159410 mov r5, r0
 *   @0x159414 str r4, [r0, #0xc]
 *   @0x159418 mov r1, r4
 *   @0x15941c mov r0, r3
 *   @0x159420 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x159424 cmp r0, #4
 *   @0x159428 bls 0x159440 <_Z19F_YoYo_GetAdsHeightR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x15942c ldr r0, [pc, #0x2c]
 *   @0x159430 mov r1, r4
 *   @0x159434 pop {r3, r4, r5, lr}
 *   @0x159438 add r0, pc, r0
 *   @0x15943c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x159440 bl 0x15e500 <_Z15AdDisplayHeighti>
 *   @0x159444 vmov s15, r0
 *   @0x159448 vcvt.f64.s32 d7, s15
 *   @0x15944c vmov r0, r1, d7
 *   @0x159450 vmov r2, s14
 *   @0x159454 mov r3, r1
 *   @0x159458 stm r5, {r2, r3}
 *   @0x15945c pop {r3, r4, r5, pc}
 *   @0x159460 andseq sp, lr, r0, ror #12
 *
 * ══ §90/321 RestrictOrientation(bool, bool, bool, bool)  0x15f1bc  size 96  24 条（0x15f1bc..0x15f21c）
 * @func 0x15f1bc 0x15f21c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x34×2 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f1bc push {r4, r5, r6, r7, lr}
 *   @0x15f1c0 sub sp, sp, #20
 *   @0x15f1c4 mov r7, r1
 *   @0x15f1c8 mov r6, r2
 *   @0x15f1cc mov r4, r3
 *   @0x15f1d0 mov r5, r0
 *   @0x15f1d4 bl 0x290274 <getJNIEnv>
 *   @0x15f1d8 ldr lr, [pc, #0x34]
 *   @0x15f1dc ldr r12, [pc, #0x34]
 *   @0x15f1e0 mov r3, r5
 *   @0x15f1e4 ldr lr, [pc, lr]
 *   @0x15f1e8 mov r5, #0
 *   @0x15f1ec ldr r12, [pc, r12]
 *   @0x15f1f0 ldr r1, [lr]
 *   @0x15f1f4 ldr r2, [r12]
 *   @0x15f1f8 str r7, [sp]
 *   @0x15f1fc str r6, [sp, #0x4]
 *   @0x15f200 str r4, [sp, #0x8]
 *   @0x15f204 str r5, [sp, #0xc]
 *   @0x15f208 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f20c add sp, sp, #20
 *   @0x15f210 pop {r4, r5, r6, r7, pc}
 *   @0x15f214 eoreq lr, r8, r0, asr #15
 *   @0x15f218 eoreq r0, r9, r0, ror #25
 *
 * ══ §91/321 SetAndroidLaunchedFromPlayer(char const*, bool)  0x15f61c  size 96  24 条（0x15f61c..0x15f67c）
 * @func 0x15f61c 0x15f67c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f61c push {r4, r5, lr}
 *   @0x15f620 sub sp, sp, #12
 *   @0x15f624 mov r4, r1
 *   @0x15f628 mov r5, r0
 *   @0x15f62c bl 0x290274 <getJNIEnv>
 *   @0x15f630 mov r1, r5
 *   @0x15f634 ldr r3, [r0]
 *   @0x15f638 ldr r3, [r3, #0x29c]
 *   @0x15f63c blx r3
 *   @0x15f640 mov r5, r0
 *   @0x15f644 bl 0x290274 <getJNIEnv>
 *   @0x15f648 ldr r12, [pc, #0x24]
 *   @0x15f64c mov r3, r5
 *   @0x15f650 ldr r2, [pc, #0x20]
 *   @0x15f654 ldr r12, [pc, r12]
 *   @0x15f658 ldr r2, [pc, r2]
 *   @0x15f65c ldr r1, [r12]
 *   @0x15f660 ldr r2, [r2]
 *   @0x15f664 str r4, [sp]
 *   @0x15f668 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f66c add sp, sp, #12
 *   @0x15f670 pop {r4, r5, pc}
 *   @0x15f674 eoreq lr, r8, r0, asr r3
 *   @0x15f678 eoreq r0, r9, r4, lsr #17
 *
 * ══ §92/321 Os_Get_Info()  0x161220  size 96  24 条（0x161220..0x161280）
 * @func 0x161220 0x161280  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticIntMethod(_jclass*, _jmethodID*, ...) / DS_AutoMutex::DS_AutoMutex() / GetDsMap(int) / AddGraphicsInfo(CDS_Map*) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x44×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161220 push {r4, r5, lr}
 *   @0x161224 sub sp, sp, #12
 *   @0x161228 bl 0x290274 <getJNIEnv>
 *   @0x16122c ldr r2, [pc, #0x44]
 *   @0x161230 ldr r3, [pc, #0x44]
 *   @0x161234 add r5, sp, #4
 *   @0x161238 ldr r2, [pc, r2]
 *   @0x16123c ldr r3, [pc, r3]
 *   @0x161240 ldr r1, [r2]
 *   @0x161244 ldr r2, [r3]
 *   @0x161248 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x16124c mov r4, r0
 *   @0x161250 mov r0, r5
 *   @0x161254 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x161258 mov r0, r4
 *   @0x16125c bl 0x2052d4 <_Z8GetDsMapi>
 *   @0x161260 bl 0x17d284 <_Z15AddGraphicsInfoP7CDS_Map>
 *   @0x161264 mov r0, r5
 *   @0x161268 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x16126c mov r0, r4
 *   @0x161270 add sp, sp, #12
 *   @0x161274 pop {r4, r5, pc}
 *   @0x161278 eoreq r12, r8, r12, ror #14
 *   @0x16127c .word 0x0028ecd0
 *
 * ══ §93/321 GR_3DM_Destroy(int)  0x1651b0  size 96  24 条（0x1651b0..0x165210）
 * @func 0x1651b0 0x165210  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: C3D_Model::~C3D_Model() / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x44×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1651b0 push {r4, r5, r6, lr}
 *   @0x1651b4 subs r4, r0, #0
 *   @0x1651b8 poplt {r4, r5, r6, pc}
 *   @0x1651bc ldr r3, [pc, #0x44]
 *   @0x1651c0 ldr r3, [pc, r3]
 *   @0x1651c4 ldr r3, [r3]
 *   @0x1651c8 cmp r4, r3
 *   @0x1651cc popge {r4, r5, r6, pc}
 *   @0x1651d0 ldr r5, [pc, #0x34]
 *   @0x1651d4 ldr r5, [pc, r5]
 *   @0x1651d8 ldr r3, [r5, #0x4]
 *   @0x1651dc ldr r6, [r3, r4, lsl #2]
 *   @0x1651e0 cmp r6, #0
 *   @0x1651e4 popeq {r4, r5, r6, pc}
 *   @0x1651e8 mov r0, r6
 *   @0x1651ec bl 0x164ff8 <_ZN9C3D_ModelD2Ev>
 *   @0x1651f0 mov r0, r6
 *   @0x1651f4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1651f8 ldr r3, [r5, #0x4]
 *   @0x1651fc mov r2, #0
 *   @0x165200 str r2, [r3, r4, lsl #2]
 *   @0x165204 pop {r4, r5, r6, pc}
 *   @0x165208 eoreq r10, r8, r0, lsr pc
 *   @0x16520c eoreq r10, r8, r0, lsr #30
 *
 * ══ §94/321 CBitmap32::SetAlpha(int)  0x167270  size 96  24 条（0x167270..0x1672d0）
 * @func 0x167270 0x1672d0  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::SetAlpha(int)+0x58
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x8×2 / 0x-4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167270 ldrb r3, [r0, #0x4]
 *   @0x167274 str r4, [sp, #-0x4]!
 *   @0x167278 cmp r3, #0
 *   @0x16727c beq 0x1672c8 <_ZN9CBitmap328SetAlphaEi+0x58>
 *   @0x167280 ldr r3, [r0, #0xc]
 *   @0x167284 lsl r1, r1, #24
 *   @0x167288 ldr r2, [r0, #0x8]
 *   @0x16728c mul r3, r2, r3
 *   @0x167290 cmp r3, #0
 *   @0x167294 ble 0x1672c8 <_ZN9CBitmap328SetAlphaEi+0x58>
 *   @0x167298 ldr r2, [r0, #0x14]
 *   @0x16729c mov r3, #0
 *   @0x1672a0 ldr r12, [r2]
 *   @0x1672a4 add r3, r3, #1
 *   @0x1672a8 bic r12, r12, #-16777216
 *   @0x1672ac add r12, r12, r1
 *   @0x1672b0 str r12, [r2], #4
 *   @0x1672b4 ldr r12, [r0, #0xc]
 *   @0x1672b8 ldr r4, [r0, #0x8]
 *   @0x1672bc mul r12, r4, r12
 *   @0x1672c0 cmp r12, r3
 *   @0x1672c4 bgt 0x1672a0 <_ZN9CBitmap328SetAlphaEi+0x30>
 *   @0x1672c8 ldr r4, [sp], #4
 *   @0x1672cc bx lr
 *
 * ══ §95/321 F_CameraApply(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f47c  size 96  24 条（0x16f47c..0x16f4dc）
 * @func 0x16f47c 0x16f4dc  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x2c×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f47c cmp r3, #1
 *   @0x16f480 push {r3, lr}
 *   @0x16f484 mov r3, #0
 *   @0x16f488 mov r1, r3
 *   @0x16f48c movt r3, #0xbff0
 *   @0x16f490 str r1, [r0, #0xc]
 *   @0x16f494 stm r0, {r1, r3}
 *   @0x16f498 ldr r0, [sp, #0x8]
 *   @0x16f49c beq 0x16f4b0 <_Z13F_CameraApplyR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16f4a0 ldr r0, [pc, #0x2c]
 *   @0x16f4a4 pop {r3, lr}
 *   @0x16f4a8 add r0, pc, r0
 *   @0x16f4ac b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f4b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f4b4 ldr r3, [pc, #0x1c]
 *   @0x16f4b8 mov r1, r0
 *   @0x16f4bc ldr r0, [pc, r3]
 *   @0x16f4c0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f4c4 cmp r0, #0
 *   @0x16f4c8 popeq {r3, pc}
 *   @0x16f4cc pop {r3, lr}
 *   @0x16f4d0 b 0x16d3bc <_ZN7CCamera13ApplyMatricesEv>
 *   @0x16f4d4 andseq r11, sp, r4, lsl #17
 *   @0x16f4d8 .word 0x0027e7b8
 *
 * ══ §96/321 Graphics::TextureFlush(bool)  0x1767d0  size 96  24 条（0x1767d0..0x176830）
 * @func 0x1767d0 0x176830  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::FlushTexture(void*)×2
 * 字段偏移 top8: 0x34×2 / 0x54×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1767d0 ldr r3, [pc, #0x54]
 *   @0x1767d4 push {r4, lr}
 *   @0x1767d8 ldr r3, [pc, r3]
 *   @0x1767dc ldr r4, [r3]
 *   @0x1767e0 cmp r4, #0
 *   @0x1767e4 popeq {r4, pc}
 *   @0x1767e8 cmp r0, #0
 *   @0x1767ec bne 0x176814 <_ZN8Graphics12TextureFlushEb+0x44>
 *   @0x1767f0 ldr r3, [r4, #0x10]
 *   @0x1767f4 mov r0, r4
 *   @0x1767f8 tst r3, #64
 *   @0x1767fc bne 0x176804 <_ZN8Graphics12TextureFlushEb+0x34>
 *   @0x176800 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x176804 ldr r4, [r4, #0x34]
 *   @0x176808 cmp r4, #0
 *   @0x17680c bne 0x1767f0 <_ZN8Graphics12TextureFlushEb+0x20>
 *   @0x176810 pop {r4, pc}
 *   @0x176814 mov r0, r4
 *   @0x176818 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x17681c ldr r4, [r4, #0x34]
 *   @0x176820 cmp r4, #0
 *   @0x176824 bne 0x176814 <_ZN8Graphics12TextureFlushEb+0x44>
 *   @0x176828 pop {r4, pc}
 *   @0x17682c .word 0x00279adc
 *
 * ══ §97/321 Graphics::ResetVBuffers()  0x1851b8  size 96  24 条（0x1851b8..0x185218）
 * @func 0x1851b8 0x185218  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1851c0→0x4a2fb8, 0x1851c8→0x3f2928, 0x1851d8→0x4a2fa8, 0x1851dc→0x4a2fa4
 * 调用序列: 无
 * 字段偏移 top8: 0x30×2 / 0x44×1 / 0x40×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1851b8 ldr r3, [pc, #0x44]
 *   @0x1851bc mov r2, #0
 *   @0x1851c0 ldr r1, [pc, #0x40]
 *   @0x1851c4 add r3, pc, r3
 *   @0x1851c8 ldr r12, [pc, #0x3c]
 *   @0x1851cc push {r4, r5}
 *   @0x1851d0 mvn r4, #0
 *   @0x1851d4 ldr r5, [r3, r1]
 *   @0x1851d8 ldr r0, [pc, #0x30]
 *   @0x1851dc ldr r1, [pc, #0x30]
 *   @0x1851e0 str r2, [r5]
 *   @0x1851e4 ldr r12, [r3, r12]
 *   @0x1851e8 str r4, [r12]
 *   @0x1851ec ldr r0, [r3, r0]
 *   @0x1851f0 pop {r4, r5}
 *   @0x1851f4 str r2, [r0]
 *   @0x1851f8 ldr r3, [r3, r1]
 *   @0x1851fc str r2, [r3]
 *   @0x185200 bx lr
 *   @0x185204 eoreq r12, r6, r12, lsl #21
 *   @0x185208 .word 0xffffe944
 *   @0x18520c .word 0xffffe948
 *   @0x185210 .word 0xffffe94c
 *   @0x185214 .word 0xffffe950
 *
 * ══ §98/321 ParticleSystem_Emitter_Clear(int, int)  0x1a38ec  size 96  24 条（0x1a38ec..0x1a394c）
 * @func 0x1a38ec 0x1a394c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Emitter_Exists(int, int)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x10×2 / 0x3c×1 / 0x8×1 / 0xc×1 / 0x14×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a38ec push {r3, r4, r5, lr}
 *   @0x1a38f0 mov r5, r0
 *   @0x1a38f4 mov r4, r1
 *   @0x1a38f8 bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii>
 *   @0x1a38fc cmp r0, #0
 *   @0x1a3900 popeq {r3, r4, r5, pc}
 *   @0x1a3904 ldr r3, [pc, #0x3c]
 *   @0x1a3908 mov r2, #0
 *   @0x1a390c mov r12, #0
 *   @0x1a3910 ldr r3, [pc, r3]
 *   @0x1a3914 ldr r3, [r3, #0x4]
 *   @0x1a3918 ldr r3, [r3, r5, lsl #2]
 *   @0x1a391c ldr r3, [r3, #0x10]
 *   @0x1a3920 ldr r3, [r3, r4, lsl #2]
 *   @0x1a3924 str r12, [r3, #0x8]
 *   @0x1a3928 str r12, [r3, #0xc]
 *   @0x1a392c str r12, [r3, #0x10]
 *   @0x1a3930 str r12, [r3, #0x14]
 *   @0x1a3934 str r2, [r3, #0x4]
 *   @0x1a3938 str r2, [r3, #0x20]
 *   @0x1a393c str r2, [r3, #0x1c]
 *   @0x1a3940 str r2, [r3, #0x18]
 *   @0x1a3944 pop {r3, r4, r5, pc}
 *   @0x1a3948 eoreq r12, r4, r8, lsr #29
 *
 * ══ §99/321 Room_Next(int)  0x1b5da4  size 96  24 条（0x1b5da4..0x1b5e04）
 * @func 0x1b5da4 0x1b5e04  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×3 / 0x54×1 / 0x10×1 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5da4 ldr r1, [pc, #0x54]
 *   @0x1b5da8 mov r12, r0
 *   @0x1b5dac add r1, pc, r1
 *   @0x1b5db0 ldr r2, [r1, #0x10]
 *   @0x1b5db4 subs r3, r2, #2
 *   @0x1b5db8 bmi 0x1b5df8 <_Z9Room_Nexti+0x54>
 *   @0x1b5dbc ldr r1, [r1, #0x14]
 *   @0x1b5dc0 sub r0, r2, #1
 *   @0x1b5dc4 add r2, r1, r0, lsl #2
 *   @0x1b5dc8 ldr r0, [r1, r0, lsl #2]
 *   @0x1b5dcc ldr r1, [r2, #-0x4]
 *   @0x1b5dd0 cmp r1, r12
 *   @0x1b5dd4 bne 0x1b5dec <_Z9Room_Nexti+0x48>
 *   @0x1b5dd8 bx lr
 *   @0x1b5ddc ldr r0, [r2, #-0x4]!
 *   @0x1b5de0 ldr r1, [r2, #-0x4]
 *   @0x1b5de4 cmp r1, r12
 *   @0x1b5de8 bxeq lr
 *   @0x1b5dec subs r3, r3, #1
 *   @0x1b5df0 bhs 0x1b5ddc <_Z9Room_Nexti+0x38>
 *   @0x1b5df4 bx lr
 *   @0x1b5df8 mvn r0, #0
 *   @0x1b5dfc bx lr
 *   @0x1b5e00 eorseq r12, r8, r12, lsl r8
 *
 * ══ §100/321 F_TilemapTileGetIndex(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b6658  size 96  24 条（0x1b6658..0x1b66b8）
 * @func 0x1b6658 0x1b66b8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x2c×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6658 cmp r3, #1
 *   @0x1b665c mov r3, #0
 *   @0x1b6660 push {r4, lr}
 *   @0x1b6664 mov r1, r3
 *   @0x1b6668 mov r4, r0
 *   @0x1b666c movt r3, #0xbff0
 *   @0x1b6670 str r1, [r0, #0xc]
 *   @0x1b6674 stm r0, {r1, r3}
 *   @0x1b6678 ldr r0, [sp, #0x8]
 *   @0x1b667c beq 0x1b6690 <_Z21F_TilemapTileGetIndexR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1b6680 ldr r0, [pc, #0x2c]
 *   @0x1b6684 pop {r4, lr}
 *   @0x1b6688 add r0, pc, r0
 *   @0x1b668c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b6690 str r1, [r4]
 *   @0x1b6694 str r1, [r4, #0x4]
 *   @0x1b6698 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b669c ubfx r2, r0, #0x0, #0x13
 *   @0x1b66a0 vmov s15, r2
 *   @0x1b66a4 vcvt.f64.s32 d7, s15
 *   @0x1b66a8 vmov r2, r3, d7
 *   @0x1b66ac stm r4, {r2, r3}
 *   @0x1b66b0 pop {r4, pc}
 *   @0x1b66b4 andseq r6, r9, r12, lsr lr
 *
 * ══ §101/321 SLinkedList<CGesture>::~SLinkedList()  0x1d57a4  size 96  24 条（0x1d57a4..0x1d5804）
 * @func 0x1d57a4 0x1d5804  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d57a4 push {r4, r5, r6, lr}
 *   @0x1d57a8 mov r6, r0
 *   @0x1d57ac ldr r4, [r0]
 *   @0x1d57b0 cmp r4, #0
 *   @0x1d57b4 beq 0x1d57ec <_ZN11SLinkedListI8CGestureED2Ev+0x48>
 *   @0x1d57b8 ldr r3, [r4, #0x8]
 *   @0x1d57bc ldr r5, [r4]
 *   @0x1d57c0 cmp r3, #0
 *   @0x1d57c4 mov r0, r3
 *   @0x1d57c8 beq 0x1d57d8 <_ZN11SLinkedListI8CGestureED2Ev+0x34>
 *   @0x1d57cc ldr r3, [r3]
 *   @0x1d57d0 ldr r3, [r3, #0x4]
 *   @0x1d57d4 blx r3
 *   @0x1d57d8 mov r0, r4
 *   @0x1d57dc mov r4, r5
 *   @0x1d57e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d57e4 cmp r5, #0
 *   @0x1d57e8 bne 0x1d57b8 <_ZN11SLinkedListI8CGestureED2Ev+0x14>
 *   @0x1d57ec mov r3, #0
 *   @0x1d57f0 mov r0, r6
 *   @0x1d57f4 str r3, [r6, #0x8]
 *   @0x1d57f8 str r3, [r6, #0x4]
 *   @0x1d57fc str r3, [r6]
 *   @0x1d5800 pop {r4, r5, r6, pc}
 *
 * ══ §102/321 SLinkedList<CGestureEvent>::~SLinkedList()  0x1dba10  size 96  24 条（0x1dba10..0x1dba70）
 * @func 0x1dba10 0x1dba70  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGestureEvent::~CGestureEvent() / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dba10 push {r3, r4, r5, r6, r7, lr}
 *   @0x1dba14 mov r7, r0
 *   @0x1dba18 ldr r4, [r0]
 *   @0x1dba1c cmp r4, #0
 *   @0x1dba20 beq 0x1dba58 <_ZN11SLinkedListI13CGestureEventED2Ev+0x48>
 *   @0x1dba24 ldr r5, [r4, #0x8]
 *   @0x1dba28 ldr r6, [r4]
 *   @0x1dba2c cmp r5, #0
 *   @0x1dba30 mov r0, r5
 *   @0x1dba34 beq 0x1dba44 <_ZN11SLinkedListI13CGestureEventED2Ev+0x34>
 *   @0x1dba38 bl 0x1db510 <_ZN13CGestureEventD2Ev>
 *   @0x1dba3c mov r0, r5
 *   @0x1dba40 bl 0x27d1d0 <_ZdlPv>
 *   @0x1dba44 mov r0, r4
 *   @0x1dba48 mov r4, r6
 *   @0x1dba4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dba50 cmp r6, #0
 *   @0x1dba54 bne 0x1dba24 <_ZN11SLinkedListI13CGestureEventED2Ev+0x14>
 *   @0x1dba58 mov r3, #0
 *   @0x1dba5c mov r0, r7
 *   @0x1dba60 str r3, [r7, #0x8]
 *   @0x1dba64 str r3, [r7, #0x4]
 *   @0x1dba68 str r3, [r7]
 *   @0x1dba6c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §103/321 RewriteOldCodeInstruction(unsigned char*, int, void*)  0x1dc830  size 96  24 条（0x1dc830..0x1dc890）
 * @func 0x1dc830 0x1dc890  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParamSize(int)
 * 字段偏移 top8: 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc830 ldr r2, [r0, r1]
 *   @0x1dc834 push {r3, r4, r5, lr}
 *   @0x1dc838 bic r4, r2, #520093696
 *   @0x1dc83c ldr r3, [pc, #0x48]
 *   @0x1dc840 lsr r12, r2, #24
 *   @0x1dc844 and r5, r12, #31
 *   @0x1dc848 ldr r3, [pc, r3]
 *   @0x1dc84c ldrb r3, [r5, r3]
 *   @0x1dc850 cmp r3, #21
 *   @0x1dc854 subeq r5, r12, #16
 *   @0x1dc858 orr r3, r4, r3, lsl #24
 *   @0x1dc85c biceq r4, r3, #65280
 *   @0x1dc860 moveq r3, r5
 *   @0x1dc864 orreq r3, r4, r3, lsl #8
 *   @0x1dc868 tst r12, #64
 *   @0x1dc86c str r3, [r0, r1]
 *   @0x1dc870 add r4, r1, #4
 *   @0x1dc874 beq 0x1dc884 <_Z25RewriteOldCodeInstructionPhiPv+0x54>
 *   @0x1dc878 ubfx r0, r2, #0x10, #0x8
 *   @0x1dc87c bl 0xec108 <_Z9ParamSizei>
 *   @0x1dc880 add r4, r4, r0
 *   @0x1dc884 mov r0, r4
 *   @0x1dc888 pop {r3, r4, r5, pc}
 *   @0x1dc88c eoreq r4, r1, r8, asr r4
 *
 * ══ §104/321 CSprite::GetTexture(int)  0x1e57f4  size 96  24 条（0x1e57f4..0x1e5854）
 * @func 0x1e57f4 0x1e5854  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::GetTexture(int)+0x58 / __aeabi_idivmod
 * 字段偏移 top8: 0x74×1 / 0x18×1 / 0x54×1 / 0x36×1 / 0x50×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e57f4 push {r3, r4, r5, lr}
 *   @0x1e57f8 mov r4, r0
 *   @0x1e57fc ldr r3, [r0, #0x74]
 *   @0x1e5800 cmp r3, #1
 *   @0x1e5804 beq 0x1e584c <_ZN7CSprite10GetTextureEi+0x58>
 *   @0x1e5808 ldr r5, [r0, #0x18]
 *   @0x1e580c cmp r5, #0
 *   @0x1e5810 ble 0x1e584c <_ZN7CSprite10GetTextureEi+0x58>
 *   @0x1e5814 mov r0, r1
 *   @0x1e5818 mov r1, r5
 *   @0x1e581c bl 0x318dec <__aeabi_idivmod>
 *   @0x1e5820 ldr r3, [r4, #0x54]
 *   @0x1e5824 cmp r1, #0
 *   @0x1e5828 addlt r1, r1, r5
 *   @0x1e582c cmp r3, #0
 *   @0x1e5830 beq 0x1e5840 <_ZN7CSprite10GetTextureEi+0x4c>
 *   @0x1e5834 ldrb r2, [r4, #0x36]
 *   @0x1e5838 cmp r2, #0
 *   @0x1e583c beq 0x1e5844 <_ZN7CSprite10GetTextureEi+0x50>
 *   @0x1e5840 ldr r3, [r4, #0x50]
 *   @0x1e5844 ldr r0, [r3, r1, lsl #2]
 *   @0x1e5848 pop {r3, r4, r5, pc}
 *   @0x1e584c mvn r0, #0
 *   @0x1e5850 pop {r3, r4, r5, pc}
 *
 * ══ §105/321 GV_PhysicsPositionXPrevious(CInstance*, int, RValue*)  0x1f99c8  size 96  24 条（0x1f99c8..0x1f9a28）
 * @func 0x1f99c8 0x1f9a38  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1 / 0x84×1 / 0xb4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f99c8 ldr r3, [pc, #0x54]
 *   @0x1f99cc ldr r1, [r0, #0x84]
 *   @0x1f99d0 ldr r3, [pc, r3]
 *   @0x1f99d4 push {r4, r5}
 *   @0x1f99d8 ldr r3, [r3]
 *   @0x1f99dc ldr r3, [r3, #0xb4]
 *   @0x1f99e0 cmp r1, #0
 *   @0x1f99e4 cmpne r3, #0
 *   @0x1f99e8 moveq r0, #0
 *   @0x1f99ec movne r0, #1
 *   @0x1f99f0 beq 0x1f9a1c <_Z27GV_PhysicsPositionXPreviousP9CInstanceiP6RValue+0x54>
 *   @0x1f99f4 vldr s14, [r1, #12]
 *   @0x1f99f8 mov r12, #0
 *   @0x1f99fc str r12, [r2, #0xc]
 *   @0x1f9a00 vldr s15, [r3, #96]
 *   @0x1f9a04 vdiv.f32 s15, s14, s15
 *   @0x1f9a08 vcvt.f64.f32 d6, s15
 *   @0x1f9a0c vmov r4, r5, d6
 *   @0x1f9a10 vmov r1, s12
 *   @0x1f9a14 mov r3, r5
 *   @0x1f9a18 stm r2, {r1, r3}
 *   @0x1f9a1c pop {r4, r5}
 *   @0x1f9a20 bx lr
 *   @0x1f9a24 andseq r3, pc, r8, asr pc
 *
 * ══ §106/321 GV_PhysicsPositionYPrevious(CInstance*, int, RValue*)  0x1f9a28  size 96  24 条（0x1f9a28..0x1f9a88）
 * @func 0x1f9a28 0x1f9a88  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1 / 0x84×1 / 0xb4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9a28 ldr r3, [pc, #0x54]
 *   @0x1f9a2c ldr r1, [r0, #0x84]
 *   @0x1f9a30 ldr r3, [pc, r3]
 *   @0x1f9a34 push {r4, r5}
 *   @0x1f9a38 ldr r3, [r3]
 *   @0x1f9a3c ldr r3, [r3, #0xb4]
 *   @0x1f9a40 cmp r1, #0
 *   @0x1f9a44 cmpne r3, #0
 *   @0x1f9a48 moveq r0, #0
 *   @0x1f9a4c movne r0, #1
 *   @0x1f9a50 beq 0x1f9a7c <_Z27GV_PhysicsPositionYPreviousP9CInstanceiP6RValue+0x54>
 *   @0x1f9a54 vldr s14, [r1, #16]
 *   @0x1f9a58 mov r12, #0
 *   @0x1f9a5c str r12, [r2, #0xc]
 *   @0x1f9a60 vldr s15, [r3, #96]
 *   @0x1f9a64 vdiv.f32 s15, s14, s15
 *   @0x1f9a68 vcvt.f64.f32 d6, s15
 *   @0x1f9a6c vmov r4, r5, d6
 *   @0x1f9a70 vmov r1, s12
 *   @0x1f9a74 mov r3, r5
 *   @0x1f9a78 stm r2, {r1, r3}
 *   @0x1f9a7c pop {r4, r5}
 *   @0x1f9a80 bx lr
 *   @0x1f9a84 ldrsheq r3, [pc], -r8
 *
 * ══ §107/321 GV_SpriteWidth(CInstance*, int, RValue*)  0x1faf28  size 96  24 条（0x1faf28..0x1faf88）
 * @func 0x1faf28 0x1faf98  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Exists(int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8c×2 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1faf28 push {r3, r4, r5, lr}
 *   @0x1faf2c mov r3, #0
 *   @0x1faf30 mov r5, r0
 *   @0x1faf34 ldr r0, [r0, #0x8c]
 *   @0x1faf38 str r3, [r2, #0xc]
 *   @0x1faf3c mov r4, r2
 *   @0x1faf40 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1faf44 cmp r0, #0
 *   @0x1faf48 streq r0, [r4]
 *   @0x1faf4c streq r0, [r4, #0x4]
 *   @0x1faf50 beq 0x1faf80 <_Z14GV_SpriteWidthP9CInstanceiP6RValue+0x58>
 *   @0x1faf54 ldr r0, [r5, #0x8c]
 *   @0x1faf58 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1faf5c vldr s14, [r5, #152]
 *   @0x1faf60 vldr s15, [r0, #28]
 *   @0x1faf64 vcvt.f32.s32 s15, s15
 *   @0x1faf68 vmul.f32 s15, s15, s14
 *   @0x1faf6c vcvt.f64.f32 d6, s15
 *   @0x1faf70 vmov r0, r1, d6
 *   @0x1faf74 vmov r2, s12
 *   @0x1faf78 mov r3, r1
 *   @0x1faf7c stm r4, {r2, r3}
 *   @0x1faf80 mov r0, #1
 *   @0x1faf84 pop {r3, r4, r5, pc}
 *
 * ══ §108/321 GV_SpriteHeight(CInstance*, int, RValue*)  0x1faf88  size 96  24 条（0x1faf88..0x1fafe8）
 * @func 0x1faf88 0x1faff8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Exists(int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8c×2 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1faf88 push {r3, r4, r5, lr}
 *   @0x1faf8c mov r3, #0
 *   @0x1faf90 mov r5, r0
 *   @0x1faf94 ldr r0, [r0, #0x8c]
 *   @0x1faf98 str r3, [r2, #0xc]
 *   @0x1faf9c mov r4, r2
 *   @0x1fafa0 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1fafa4 cmp r0, #0
 *   @0x1fafa8 streq r0, [r4]
 *   @0x1fafac streq r0, [r4, #0x4]
 *   @0x1fafb0 beq 0x1fafe0 <_Z15GV_SpriteHeightP9CInstanceiP6RValue+0x58>
 *   @0x1fafb4 ldr r0, [r5, #0x8c]
 *   @0x1fafb8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1fafbc vldr s14, [r5, #156]
 *   @0x1fafc0 vldr s15, [r0, #32]
 *   @0x1fafc4 vcvt.f32.s32 s15, s15
 *   @0x1fafc8 vmul.f32 s15, s15, s14
 *   @0x1fafcc vcvt.f64.f32 d6, s15
 *   @0x1fafd0 vmov r0, r1, d6
 *   @0x1fafd4 vmov r2, s12
 *   @0x1fafd8 mov r3, r1
 *   @0x1fafdc stm r4, {r2, r3}
 *   @0x1fafe0 mov r0, #1
 *   @0x1fafe4 pop {r3, r4, r5, pc}
 *
 * ══ §109/321 GV_SpriteXOffset(CInstance*, int, RValue*)  0x1fafe8  size 96  24 条（0x1fafe8..0x1fb048）
 * @func 0x1fafe8 0x1fb058  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Exists(int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8c×2 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fafe8 push {r3, r4, r5, lr}
 *   @0x1fafec mov r3, #0
 *   @0x1faff0 mov r5, r0
 *   @0x1faff4 ldr r0, [r0, #0x8c]
 *   @0x1faff8 str r3, [r2, #0xc]
 *   @0x1faffc mov r4, r2
 *   @0x1fb000 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1fb004 cmp r0, #0
 *   @0x1fb008 streq r0, [r4]
 *   @0x1fb00c streq r0, [r4, #0x4]
 *   @0x1fb010 beq 0x1fb040 <_Z16GV_SpriteXOffsetP9CInstanceiP6RValue+0x58>
 *   @0x1fb014 ldr r0, [r5, #0x8c]
 *   @0x1fb018 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1fb01c vldr s14, [r5, #152]
 *   @0x1fb020 vldr s15, [r0, #36]
 *   @0x1fb024 vcvt.f32.s32 s15, s15
 *   @0x1fb028 vmul.f32 s15, s15, s14
 *   @0x1fb02c vcvt.f64.f32 d6, s15
 *   @0x1fb030 vmov r0, r1, d6
 *   @0x1fb034 vmov r2, s12
 *   @0x1fb038 mov r3, r1
 *   @0x1fb03c stm r4, {r2, r3}
 *   @0x1fb040 mov r0, #1
 *   @0x1fb044 pop {r3, r4, r5, pc}
 *
 * ══ §110/321 GV_SpriteYOffset(CInstance*, int, RValue*)  0x1fb048  size 96  24 条（0x1fb048..0x1fb0a8）
 * @func 0x1fb048 0x1fb0a8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Exists(int) / Sprite_Data(int)
 * 字段偏移 top8: 0x8c×2 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb048 push {r3, r4, r5, lr}
 *   @0x1fb04c mov r3, #0
 *   @0x1fb050 mov r5, r0
 *   @0x1fb054 ldr r0, [r0, #0x8c]
 *   @0x1fb058 str r3, [r2, #0xc]
 *   @0x1fb05c mov r4, r2
 *   @0x1fb060 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1fb064 cmp r0, #0
 *   @0x1fb068 streq r0, [r4]
 *   @0x1fb06c streq r0, [r4, #0x4]
 *   @0x1fb070 beq 0x1fb0a0 <_Z16GV_SpriteYOffsetP9CInstanceiP6RValue+0x58>
 *   @0x1fb074 ldr r0, [r5, #0x8c]
 *   @0x1fb078 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1fb07c vldr s14, [r5, #156]
 *   @0x1fb080 vldr s15, [r0, #40]
 *   @0x1fb084 vcvt.f32.s32 s15, s15
 *   @0x1fb088 vmul.f32 s15, s15, s14
 *   @0x1fb08c vcvt.f64.f32 d6, s15
 *   @0x1fb090 vmov r0, r1, d6
 *   @0x1fb094 vmov r2, s12
 *   @0x1fb098 mov r3, r1
 *   @0x1fb09c stm r4, {r2, r3}
 *   @0x1fb0a0 mov r0, #1
 *   @0x1fb0a4 pop {r3, r4, r5, pc}
 *
 * ══ §111/321 SV_Alarm(CInstance*, int, RValue*)  0x1fb7c8  size 96  24 条（0x1fb7c8..0x1fb828）
 * @func 0x1fb7c8 0x1fb828  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / CInstance::SetTimer(int, int) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb7c8 push {r3, r4, r5, lr}
 *   @0x1fb7cc cmp r1, #11
 *   @0x1fb7d0 ldr r3, [r2, #0xc]
 *   @0x1fb7d4 mov r5, r0
 *   @0x1fb7d8 movls r4, r1
 *   @0x1fb7dc movhi r4, #0
 *   @0x1fb7e0 bic r3, r3, #-16777216
 *   @0x1fb7e4 cmp r3, #0
 *   @0x1fb7e8 bne 0x1fb81c <_Z8SV_AlarmP9CInstanceiP6RValue+0x54>
 *   @0x1fb7ec ldm r2, {r0, r1}
 *   @0x1fb7f0 vmov d6, r0, r1
 *   @0x1fb7f4 vcvt.f32.f64 s15, d6
 *   @0x1fb7f8 vcvt.f64.f32 d6, s15
 *   @0x1fb7fc vmov r0, r1, d6
 *   @0x1fb800 bl 0xb66e8 <lrint@plt>
 *   @0x1fb804 mov r1, r4
 *   @0x1fb808 mov r2, r0
 *   @0x1fb80c mov r0, r5
 *   @0x1fb810 bl 0x193148 <_ZN9CInstance8SetTimerEii>
 *   @0x1fb814 mov r0, #1
 *   @0x1fb818 pop {r3, r4, r5, pc}
 *   @0x1fb81c mov r0, r2
 *   @0x1fb820 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb824 b 0x1fb7f0 <_Z8SV_AlarmP9CInstanceiP6RValue+0x28>
 *
 * ══ §112/321 CStream::ReadString()  0x201950  size 96  24 条（0x201950..0x2019b0）
 * @func 0x201950 0x2019b0  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadBuffer(void*, int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×2 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201950 push {r4, r5, lr}
 *   @0x201954 sub sp, sp, #12
 *   @0x201958 add r1, sp, #4
 *   @0x20195c mov r2, #4
 *   @0x201960 mov r5, r0
 *   @0x201964 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x201968 ldr r0, [sp, #0x4]
 *   @0x20196c cmp r0, #0
 *   @0x201970 beq 0x2019a4 <_ZN7CStream10ReadStringEv+0x54>
 *   @0x201974 ldr r1, [pc, #0x30]
 *   @0x201978 movw r2, #0x239
 *   @0x20197c mov r3, #1
 *   @0x201980 add r0, r0, #1
 *   @0x201984 add r1, pc, r1
 *   @0x201988 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20198c ldr r2, [sp, #0x4]
 *   @0x201990 mov r4, r0
 *   @0x201994 mov r0, r5
 *   @0x201998 mov r1, r4
 *   @0x20199c bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x2019a0 mov r0, r4
 *   @0x2019a4 add sp, sp, #12
 *   @0x2019a8 pop {r4, r5, pc}
 *   @0x2019ac andseq r1, r5, r4, lsr #27
 *
 * ══ §113/321 CStream::WriteString(char const*)  0x201b58  size 96  24 条（0x201b58..0x201bb8）
 * @func 0x201b58 0x201bb8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::Write(void*, int)×2 / 0xb6538
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201b58 push {r4, r5, lr}
 *   @0x201b5c subs r5, r1, #0
 *   @0x201b60 sub sp, sp, #12
 *   @0x201b64 mov r3, #0
 *   @0x201b68 mov r4, r0
 *   @0x201b6c str r3, [sp, #0x4]
 *   @0x201b70 beq 0x201b80 <_ZN7CStream11WriteStringEPKc+0x28>
 *   @0x201b74 mov r0, r5
 *   @0x201b78 bl 0xb6538 <strlen@plt>
 *   @0x201b7c str r0, [sp, #0x4]
 *   @0x201b80 mov r2, #4
 *   @0x201b84 mov r0, r4
 *   @0x201b88 add r1, sp, #4
 *   @0x201b8c bl 0x2014c8 <_ZN7CStream5WriteEPvi>
 *   @0x201b90 ldr r2, [sp, #0x4]
 *   @0x201b94 cmp r2, #0
 *   @0x201b98 bne 0x201ba4 <_ZN7CStream11WriteStringEPKc+0x4c>
 *   @0x201b9c add sp, sp, #12
 *   @0x201ba0 pop {r4, r5, pc}
 *   @0x201ba4 mov r0, r4
 *   @0x201ba8 mov r1, r5
 *   @0x201bac bl 0x2014c8 <_ZN7CStream5WriteEPvi>
 *   @0x201bb0 add sp, sp, #12
 *   @0x201bb4 pop {r4, r5, pc}
 *
 * ══ §114/321 Audio_GetNoiseFromQueuedSoundID(int)  0x216560  size 96  24 条（0x216560..0x2165c0）
 * @func 0x216560 0x2165c0  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetNoiseFromQueuedSoundID(int)+0x4c
 * 字段偏移 top8: 0x4×2 / 0x54×1 / 0x-4×1 / 0x38×1 / 0x3c×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216560 ldr r3, [pc, #0x54]
 *   @0x216564 str r4, [sp, #-0x4]!
 *   @0x216568 add r3, pc, r3
 *   @0x21656c ldr r4, [r3, #0x38]
 *   @0x216570 cmp r4, #0
 *   @0x216574 ble 0x2165ac <_Z31Audio_GetNoiseFromQueuedSoundIDi+0x4c>
 *   @0x216578 ldr r1, [r3, #0x3c]
 *   @0x21657c mov r3, #0
 *   @0x216580 sub r1, r1, #4
 *   @0x216584 ldr r2, [r1, #0x4]!
 *   @0x216588 add r3, r3, #1
 *   @0x21658c ldr r12, [r2, #0x8]
 *   @0x216590 cmp r12, #0
 *   @0x216594 bne 0x2165a4 <_Z31Audio_GetNoiseFromQueuedSoundIDi+0x44>
 *   @0x216598 ldr r12, [r2, #0x18]
 *   @0x21659c cmp r12, r0
 *   @0x2165a0 beq 0x2165b0 <_Z31Audio_GetNoiseFromQueuedSoundIDi+0x50>
 *   @0x2165a4 cmp r3, r4
 *   @0x2165a8 bne 0x216584 <_Z31Audio_GetNoiseFromQueuedSoundIDi+0x24>
 *   @0x2165ac mov r2, #0
 *   @0x2165b0 mov r0, r2
 *   @0x2165b4 ldr r4, [sp], #4
 *   @0x2165b8 bx lr
 *   @0x2165bc subseq lr, r3, r12, lsr #26
 *
 * ══ §115/321 alutLoadWAVFile  0x222798  size 96  24 条（0x222798..0x2227f8）
 * @func 0x222798 0x222808  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutInputStreamConstructFromFile / _alutLoadMemoryFromInputStream
 * 字段偏移 top8: 0x20×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222798 push {r4, r5, r6, r7, r8, lr}
 *   @0x22279c sub sp, sp, #8
 *   @0x2227a0 mov r7, r3
 *   @0x2227a4 mov r8, r1
 *   @0x2227a8 mov r6, r2
 *   @0x2227ac ldr r5, [sp, #0x20]
 *   @0x2227b0 ldr r4, [sp, #0x24]
 *   @0x2227b4 bl 0x221ce0 <_alutInputStreamConstructFromFile>
 *   @0x2227b8 mov r1, r8
 *   @0x2227bc mov r2, r7
 *   @0x2227c0 add r3, sp, #4
 *   @0x2227c4 bl 0x222664 <_alutLoadMemoryFromInputStream>
 *   @0x2227c8 cmp r0, #0
 *   @0x2227cc str r0, [r6]
 *   @0x2227d0 beq 0x2227f0 <alutLoadWAVFile+0x58>
 *   @0x2227d4 cmp r5, #0
 *   @0x2227d8 vldrne s15, [sp, #4]
 *   @0x2227dc vcvtne.s32.f32 s15, s15
 *   @0x2227e0 vstrne s15, [r5]
 *   @0x2227e4 cmp r4, #0
 *   @0x2227e8 movne r3, #0
 *   @0x2227ec strbne r3, [r4]
 *   @0x2227f0 add sp, sp, #8
 *   @0x2227f4 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §116/321 ogg_sync_pageout  0x234e4c  size 96  24 条（0x234e4c..0x234eac）
 * @func 0x234e4c 0x234eac  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_sync_check / ogg_sync_pageseek / ogg_sync_pageout+0x1c
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234e4c push {r3, r4, r5, lr}
 *   @0x234e50 mov r5, r1
 *   @0x234e54 mov r4, r0
 *   @0x234e58 bl 0x234b80 <ogg_sync_check>
 *   @0x234e5c cmp r0, #0
 *   @0x234e60 beq 0x234e78 <ogg_sync_pageout+0x2c>
 *   @0x234e64 b 0x234e94 <ogg_sync_pageout+0x48>
 *   @0x234e68 beq 0x234e94 <ogg_sync_pageout+0x48>
 *   @0x234e6c ldr r3, [r4, #0x10]
 *   @0x234e70 cmp r3, #0
 *   @0x234e74 beq 0x234e9c <ogg_sync_pageout+0x50>
 *   @0x234e78 mov r0, r4
 *   @0x234e7c mov r1, r5
 *   @0x234e80 bl 0x234c90 <ogg_sync_pageseek>
 *   @0x234e84 cmp r0, #0
 *   @0x234e88 ble 0x234e68 <ogg_sync_pageout+0x1c>
 *   @0x234e8c mov r0, #1
 *   @0x234e90 pop {r3, r4, r5, pc}
 *   @0x234e94 mov r0, #0
 *   @0x234e98 pop {r3, r4, r5, pc}
 *   @0x234e9c mov r3, #1
 *   @0x234ea0 mvn r0, #0
 *   @0x234ea4 str r3, [r4, #0x10]
 *   @0x234ea8 pop {r3, r4, r5, pc}
 *
 * ══ §117/321 IniFile::~IniFile()  0x235428  size 96  24 条（0x235428..0x235488）
 * @func 0x235428 0x235488  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Section::~Section() / operator delete(void*)
 * 字段偏移 top8: 0x8×3 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235428 push {r3, r4, r5, lr}
 *   @0x23542c mov r5, r0
 *   @0x235430 ldr r4, [r0, #0x8]
 *   @0x235434 cmp r4, #0
 *   @0x235438 beq 0x235460 <_ZN7IniFileD2Ev+0x38>
 *   @0x23543c ldr r3, [r4]
 *   @0x235440 mov r0, r4
 *   @0x235444 str r3, [r5, #0x8]
 *   @0x235448 bl 0x2353e0 <_ZN7SectionD2Ev>
 *   @0x23544c mov r0, r4
 *   @0x235450 bl 0x27d1d0 <_ZdlPv>
 *   @0x235454 ldr r4, [r5, #0x8]
 *   @0x235458 cmp r4, #0
 *   @0x23545c bne 0x23543c <_ZN7IniFileD2Ev+0x14>
 *   @0x235460 ldr r0, [r5]
 *   @0x235464 cmp r0, #0
 *   @0x235468 beq 0x235470 <_ZN7IniFileD2Ev+0x48>
 *   @0x23546c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x235470 ldr r0, [r5, #0x10]
 *   @0x235474 cmp r0, #0
 *   @0x235478 beq 0x235480 <_ZN7IniFileD2Ev+0x58>
 *   @0x23547c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x235480 mov r0, r5
 *   @0x235484 pop {r3, r4, r5, pc}
 *
 * ══ §118/321 IniFile::IsWhiteSpace()  0x235518  size 96  24 条（0x235518..0x235578）
 * @func 0x235518 0x235578  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235518 ldr r3, [r0, #0xc]
 *   @0x23551c ldr r2, [r0, #0x4]
 *   @0x235520 cmp r3, r2
 *   @0x235524 bge 0x235568 <_ZN7IniFile12IsWhiteSpaceEv+0x50>
 *   @0x235528 ldr r2, [r0, #0x10]
 *   @0x23552c ldrb r3, [r2, r3]
 *   @0x235530 sub r0, r3, #9
 *   @0x235534 cmp r3, #32
 *   @0x235538 cmpne r0, #1
 *   @0x23553c movhi r0, #0
 *   @0x235540 movls r0, #1
 *   @0x235544 bxls lr
 *   @0x235548 cmp r3, #13
 *   @0x23554c beq 0x235570 <_ZN7IniFile12IsWhiteSpaceEv+0x58>
 *   @0x235550 cmp r3, #35
 *   @0x235554 beq 0x235570 <_ZN7IniFile12IsWhiteSpaceEv+0x58>
 *   @0x235558 subs r3, r3, #59
 *   @0x23555c rsbs r0, r3, #0
 *   @0x235560 adcs r0, r0, r3
 *   @0x235564 bx lr
 *   @0x235568 mov r0, #0
 *   @0x23556c bx lr
 *   @0x235570 mov r0, #1
 *   @0x235574 bx lr
 *
 * ══ §119/321 F_JSTryHook(RValue&, CInstance*, CInstance*, int, RValue*)  0x23ca0c  size 96  24 条（0x23ca0c..0x23ca6c）
 * @func 0x23ca0c 0x23ca6c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / operator new(unsigned int)
 * 字段偏移 top8: 0x28×3 / 0x54×1 / 0x10×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23ca0c ldr r3, [pc, #0x54]
 *   @0x23ca10 push {r4, r5, r6, lr}
 *   @0x23ca14 ldr r3, [pc, r3]
 *   @0x23ca18 ldr r6, [sp, #0x10]
 *   @0x23ca1c ldr r3, [r3]
 *   @0x23ca20 ldr r5, [r3, #0x28]
 *   @0x23ca24 cmp r5, #0
 *   @0x23ca28 popeq {r4, r5, r6, pc}
 *   @0x23ca2c mov r0, #12
 *   @0x23ca30 bl 0x27c524 <_Znwj>
 *   @0x23ca34 ldr r3, [r5, #0x28]
 *   @0x23ca38 mov r1, #0
 *   @0x23ca3c mov r4, r0
 *   @0x23ca40 mov r0, r6
 *   @0x23ca44 str r3, [r4]
 *   @0x23ca48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x23ca4c mov r1, #1
 *   @0x23ca50 str r0, [r4, #0x4]
 *   @0x23ca54 mov r0, r6
 *   @0x23ca58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x23ca5c str r0, [r4, #0x8]
 *   @0x23ca60 str r4, [r5, #0x28]
 *   @0x23ca64 pop {r4, r5, r6, pc}
 *   @0x23ca68 mulseq r11, r4, r1
 *
 * ══ §120/321 F_JS_Object_preventExtensions(RValue&, CInstance*, CInstance*, int, RValue*)  0x250ad0  size 96  24 条（0x250ad0..0x250b30）
 * @func 0x250ad0 0x250b30  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×3 / 0x28×2 / 0x4×2 / 0x8×2 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x250ad0 cmp r3, #0
 *   @0x250ad4 ldr r3, [sp]
 *   @0x250ad8 beq 0x250aec <_Z29F_JS_Object_preventExtensionsR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x250adc ldr r2, [r3, #0xc]
 *   @0x250ae0 bic r2, r2, #-16777216
 *   @0x250ae4 cmp r2, #6
 *   @0x250ae8 beq 0x250af8 <_Z29F_JS_Object_preventExtensionsR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x250aec ldr r0, [pc, #0x38]
 *   @0x250af0 add r0, pc, r0
 *   @0x250af4 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x250af8 ldr r2, [r3]
 *   @0x250afc ldr r1, [r2, #0x28]
 *   @0x250b00 bic r1, r1, #1
 *   @0x250b04 str r1, [r2, #0x28]
 *   @0x250b08 ldr r12, [r3]
 *   @0x250b0c ldr r1, [r3, #0x4]
 *   @0x250b10 ldr r2, [r3, #0x8]
 *   @0x250b14 ldr r3, [r3, #0xc]
 *   @0x250b18 str r12, [r0]
 *   @0x250b1c str r1, [r0, #0x4]
 *   @0x250b20 str r2, [r0, #0x8]
 *   @0x250b24 str r3, [r0, #0xc]
 *   @0x250b28 bx lr
 *   @0x250b2c andseq r5, r0, r8, asr r4
 *
 * ══ §121/321 JS_Number_Prototype_valueOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x252d54  size 96  24 条（0x252d54..0x252db4）
 * @func 0x252d54 0x252db4  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / YYObjectBase::FindValue(char const*)
 * 字段偏移 top8: 0x44×1 / 0x40×1 / 0x2c×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252d54 push {r3, r4, r5, lr}
 *   @0x252d58 mov r5, r1
 *   @0x252d5c ldr r1, [pc, #0x44]
 *   @0x252d60 mov r4, r0
 *   @0x252d64 ldr r0, [r5, #0x40]
 *   @0x252d68 add r1, pc, r1
 *   @0x252d6c bl 0xb6574 <strcmp@plt>
 *   @0x252d70 cmp r0, #0
 *   @0x252d74 bne 0x252d98 <_Z27JS_Number_Prototype_valueOfR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x252d78 ldr r1, [pc, #0x2c]
 *   @0x252d7c str r0, [r4, #0xc]
 *   @0x252d80 mov r0, r5
 *   @0x252d84 add r1, pc, r1
 *   @0x252d88 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x252d8c ldm r0, {r2, r3}
 *   @0x252d90 stm r4, {r2, r3}
 *   @0x252d94 pop {r3, r4, r5, pc}
 *   @0x252d98 ldr r0, [pc, #0x10]
 *   @0x252d9c pop {r3, r4, r5, lr}
 *   @0x252da0 add r0, pc, r0
 *   @0x252da4 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252da8 andseq r2, r0, r8, lsr #24
 *   @0x252dac andseq r2, r0, r12, lsl #15
 *   @0x252db0 andseq r3, r0, r8, lsr #3
 *
 * ══ §122/321 JS_Number_Prototype_toLocaleString(RValue&, CInstance*, CInstance*, int, RValue*)  0x256e74  size 96  24 条（0x256e74..0x256ed4）
 * @func 0x256e74 0x256ed4  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / YYObjectBase::FindValue(char const*)
 * 字段偏移 top8: 0x44×1 / 0x40×1 / 0x2c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x256e74 push {r3, r4, r5, lr}
 *   @0x256e78 mov r4, r1
 *   @0x256e7c ldr r1, [pc, #0x44]
 *   @0x256e80 mov r5, r0
 *   @0x256e84 ldr r0, [r4, #0x40]
 *   @0x256e88 add r1, pc, r1
 *   @0x256e8c bl 0xb6574 <strcmp@plt>
 *   @0x256e90 cmp r0, #0
 *   @0x256e94 bne 0x256eb8 <_Z34JS_Number_Prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x256e98 ldr r1, [pc, #0x2c]
 *   @0x256e9c mov r0, r4
 *   @0x256ea0 add r1, pc, r1
 *   @0x256ea4 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x256ea8 mov r1, r0
 *   @0x256eac mov r0, r5
 *   @0x256eb0 pop {r3, r4, r5, lr}
 *   @0x256eb4 b 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256eb8 ldr r0, [pc, #0x10]
 *   @0x256ebc pop {r3, r4, r5, lr}
 *   @0x256ec0 add r0, pc, r0
 *   @0x256ec4 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x256ec8 andeq lr, pc, r8, lsl #22
 *   @0x256ecc andeq lr, pc, r0, ror r6
 *   @0x256ed0 andeq pc, pc, r8, lsl #1
 *
 * ══ §123/321 _spMeshAttachment_dispose  0x28747c  size 96  24 条（0x28747c..0x2874dc）
 * @func 0x28747c 0x2874ec  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×5 / _spAttachment_deinit / _spVertexAttachment_deinit
 * 字段偏移 top8: 0x54×1 / 0x5c×1 / 0x7c×1 / 0x58×1 / 0x64×1 / 0x88×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28747c push {r4, lr}
 *   @0x287480 mov r4, r0
 *   @0x287484 ldr r0, [r0, #0x54]
 *   @0x287488 bl 0x285c80 <_free>
 *   @0x28748c ldr r0, [r4, #0x5c]
 *   @0x287490 bl 0x285c80 <_free>
 *   @0x287494 ldr r3, [r4, #0x7c]
 *   @0x287498 mov r0, r4
 *   @0x28749c cmp r3, #0
 *   @0x2874a0 beq 0x2874b4 <_spMeshAttachment_dispose+0x38>
 *   @0x2874a4 bl 0x284c84 <_spAttachment_deinit>
 *   @0x2874a8 mov r0, r4
 *   @0x2874ac pop {r4, lr}
 *   @0x2874b0 b 0x285c80 <_free>
 *   @0x2874b4 bl 0x28f62c <_spVertexAttachment_deinit>
 *   @0x2874b8 ldr r0, [r4, #0x58]
 *   @0x2874bc bl 0x285c80 <_free>
 *   @0x2874c0 ldr r0, [r4, #0x64]
 *   @0x2874c4 bl 0x285c80 <_free>
 *   @0x2874c8 ldr r0, [r4, #0x88]
 *   @0x2874cc bl 0x285c80 <_free>
 *   @0x2874d0 mov r0, r4
 *   @0x2874d4 pop {r4, lr}
 *   @0x2874d8 b 0x285c80 <_free>
 *
 * ══ §124/321 spSkeleton_findIkConstraint  0x28a438  size 96  24 条（0x28a438..0x28a498）
 * @func 0x28a438 0x28a4a8  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findIkConstraint+0x54 / 0xb6574
 * 字段偏移 top8: 0x1c×1 / 0x20×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a438 push {r4, r5, r6, r7, r8, lr}
 *   @0x28a43c mov r8, r1
 *   @0x28a440 ldr r7, [r0, #0x1c]
 *   @0x28a444 cmp r7, #0
 *   @0x28a448 ble 0x28a48c <spSkeleton_findIkConstraint+0x54>
 *   @0x28a44c ldr r6, [r0, #0x20]
 *   @0x28a450 mov r4, #0
 *   @0x28a454 sub r6, r6, #4
 *   @0x28a458 b 0x28a464 <spSkeleton_findIkConstraint+0x2c>
 *   @0x28a45c cmp r4, r7
 *   @0x28a460 beq 0x28a48c <spSkeleton_findIkConstraint+0x54>
 *   @0x28a464 ldr r5, [r6, #0x4]!
 *   @0x28a468 mov r1, r8
 *   @0x28a46c add r4, r4, #1
 *   @0x28a470 ldr r3, [r5]
 *   @0x28a474 ldr r0, [r3]
 *   @0x28a478 bl 0xb6574 <strcmp@plt>
 *   @0x28a47c cmp r0, #0
 *   @0x28a480 bne 0x28a45c <spSkeleton_findIkConstraint+0x24>
 *   @0x28a484 mov r0, r5
 *   @0x28a488 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28a48c mov r5, #0
 *   @0x28a490 mov r0, r5
 *   @0x28a494 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §125/321 spSkeleton_findTransformConstraint  0x28a498  size 96  24 条（0x28a498..0x28a4f8）
 * @func 0x28a498 0x28a508  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findTransformConstraint+0x54 / 0xb6574
 * 字段偏移 top8: 0x28×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a498 push {r4, r5, r6, r7, r8, lr}
 *   @0x28a49c mov r8, r1
 *   @0x28a4a0 ldr r7, [r0, #0x28]
 *   @0x28a4a4 cmp r7, #0
 *   @0x28a4a8 ble 0x28a4ec <spSkeleton_findTransformConstraint+0x54>
 *   @0x28a4ac ldr r6, [r0, #0x2c]
 *   @0x28a4b0 mov r4, #0
 *   @0x28a4b4 sub r6, r6, #4
 *   @0x28a4b8 b 0x28a4c4 <spSkeleton_findTransformConstraint+0x2c>
 *   @0x28a4bc cmp r4, r7
 *   @0x28a4c0 beq 0x28a4ec <spSkeleton_findTransformConstraint+0x54>
 *   @0x28a4c4 ldr r5, [r6, #0x4]!
 *   @0x28a4c8 mov r1, r8
 *   @0x28a4cc add r4, r4, #1
 *   @0x28a4d0 ldr r3, [r5]
 *   @0x28a4d4 ldr r0, [r3]
 *   @0x28a4d8 bl 0xb6574 <strcmp@plt>
 *   @0x28a4dc cmp r0, #0
 *   @0x28a4e0 bne 0x28a4bc <spSkeleton_findTransformConstraint+0x24>
 *   @0x28a4e4 mov r0, r5
 *   @0x28a4e8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28a4ec mov r5, #0
 *   @0x28a4f0 mov r0, r5
 *   @0x28a4f4 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §126/321 spSkeleton_findPathConstraint  0x28a4f8  size 96  24 条（0x28a4f8..0x28a558）
 * @func 0x28a4f8 0x28a558  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findPathConstraint+0x54 / 0xb6574
 * 字段偏移 top8: 0x30×1 / 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a4f8 push {r4, r5, r6, r7, r8, lr}
 *   @0x28a4fc mov r8, r1
 *   @0x28a500 ldr r7, [r0, #0x30]
 *   @0x28a504 cmp r7, #0
 *   @0x28a508 ble 0x28a54c <spSkeleton_findPathConstraint+0x54>
 *   @0x28a50c ldr r6, [r0, #0x34]
 *   @0x28a510 mov r4, #0
 *   @0x28a514 sub r6, r6, #4
 *   @0x28a518 b 0x28a524 <spSkeleton_findPathConstraint+0x2c>
 *   @0x28a51c cmp r4, r7
 *   @0x28a520 beq 0x28a54c <spSkeleton_findPathConstraint+0x54>
 *   @0x28a524 ldr r5, [r6, #0x4]!
 *   @0x28a528 mov r1, r8
 *   @0x28a52c add r4, r4, #1
 *   @0x28a530 ldr r3, [r5]
 *   @0x28a534 ldr r0, [r3]
 *   @0x28a538 bl 0xb6574 <strcmp@plt>
 *   @0x28a53c cmp r0, #0
 *   @0x28a540 bne 0x28a51c <spSkeleton_findPathConstraint+0x24>
 *   @0x28a544 mov r0, r5
 *   @0x28a548 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28a54c mov r5, #0
 *   @0x28a550 mov r0, r5
 *   @0x28a554 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §127/321 spSkeletonBounds_aabbIntersectsSkeleton  0x28ac2c  size 96  24 条（0x28ac2c..0x28ac8c）
 * @func 0x28ac2c 0x28ac8c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonBounds_aabbIntersectsSkeleton+0x58
 * 字段偏移 top8: 无
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ac2c vldr s14, [r0, #12]
 *   @0x28ac30 vldr s15, [r1, #20]
 *   @0x28ac34 vcmpe.f32 s14, s15
 *   @0x28ac38 vmrs APSR_nzcv, fpscr
 *   @0x28ac3c bpl 0x28ac84 <spSkeletonBounds_aabbIntersectsSkeleton+0x58>
 *   @0x28ac40 vldr s14, [r0, #20]
 *   @0x28ac44 vldr s15, [r1, #12]
 *   @0x28ac48 vcmpe.f32 s14, s15
 *   @0x28ac4c vmrs APSR_nzcv, fpscr
 *   @0x28ac50 ble 0x28ac84 <spSkeletonBounds_aabbIntersectsSkeleton+0x58>
 *   @0x28ac54 vldr s14, [r0, #16]
 *   @0x28ac58 vldr s15, [r1, #24]
 *   @0x28ac5c vcmpe.f32 s14, s15
 *   @0x28ac60 vmrs APSR_nzcv, fpscr
 *   @0x28ac64 bpl 0x28ac84 <spSkeletonBounds_aabbIntersectsSkeleton+0x58>
 *   @0x28ac68 vldr s14, [r0, #24]
 *   @0x28ac6c vldr s15, [r1, #16]
 *   @0x28ac70 vcmpe.f32 s14, s15
 *   @0x28ac74 vmrs APSR_nzcv, fpscr
 *   @0x28ac78 movle r0, #0
 *   @0x28ac7c movgt r0, #1
 *   @0x28ac80 bx lr
 *   @0x28ac84 mov r0, #0
 *   @0x28ac88 bx lr
 *
 * ══ §128/321 GetSocketIndex(yySocket*)  0x299624  size 96  24 条（0x299624..0x299684）
 * @func 0x299624 0x299684  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x54×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299624 ldr r2, [pc, #0x54]
 *   @0x299628 mov r3, #0
 *   @0x29962c str r4, [sp, #-0x4]!
 *   @0x299630 mov r1, r3
 *   @0x299634 ldr r2, [pc, r2]
 *   @0x299638 b 0x299648 <_Z14GetSocketIndexP8yySocket+0x24>
 *   @0x29963c cmp r3, #768
 *   @0x299640 add r1, r1, #1
 *   @0x299644 beq 0x299674 <_Z14GetSocketIndexP8yySocket+0x50>
 *   @0x299648 ldrb r12, [r2, r3]
 *   @0x29964c add r4, r2, r3
 *   @0x299650 add r3, r3, #12
 *   @0x299654 cmp r12, #0
 *   @0x299658 beq 0x29963c <_Z14GetSocketIndexP8yySocket+0x18>
 *   @0x29965c ldr r12, [r4, #0x4]
 *   @0x299660 cmp r12, r0
 *   @0x299664 bne 0x29963c <_Z14GetSocketIndexP8yySocket+0x18>
 *   @0x299668 mov r0, r1
 *   @0x29966c ldr r4, [sp], #4
 *   @0x299670 bx lr
 *   @0x299674 mvn r0, #0
 *   @0x299678 ldr r4, [sp], #4
 *   @0x29967c bx lr
 *   @0x299680 andseq r8, r5, r0, ror r3
 *
 * ══ §129/321 RelyAddPacket(SRelyEntry*)  0x299a9c  size 96  24 条（0x299a9c..0x299afc）
 * @func 0x299a9c 0x299afc  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x299aa0→0x7578dc, 0x299ab8→0x7578d8, 0x299adc→0x7578d8
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×2 / 0x20×2 / 0x38×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299a9c ldr r3, [pc, #0x4c]
 *   @0x299aa0 ldr r2, [pc, #0x4c]
 *   @0x299aa4 add r3, pc, r3
 *   @0x299aa8 ldr r2, [r3, r2]
 *   @0x299aac ldr r1, [r2]
 *   @0x299ab0 cmp r1, #0
 *   @0x299ab4 beq 0x299adc <_Z13RelyAddPacketP10SRelyEntry+0x40>
 *   @0x299ab8 ldr r2, [pc, #0x38]
 *   @0x299abc mov r1, #0
 *   @0x299ac0 ldr r2, [r3, r2]
 *   @0x299ac4 ldr r3, [r2]
 *   @0x299ac8 str r0, [r2]
 *   @0x299acc str r0, [r3, #0x20]
 *   @0x299ad0 str r3, [r0, #0x24]
 *   @0x299ad4 str r1, [r0, #0x20]
 *   @0x299ad8 bx lr
 *   @0x299adc ldr r1, [pc, #0x14]
 *   @0x299ae0 str r0, [r2]
 *   @0x299ae4 ldr r3, [r3, r1]
 *   @0x299ae8 str r0, [r3]
 *   @0x299aec bx lr
 *   @0x299af0 andseq r8, r5, r12, lsr #3
 *   @0x299af4 .word 0xfffffda4
 *   @0x299af8 .word 0xfffffda8
 *
 * ══ §130/321 Debug_GetGameStructure(bool)  0x29c720  size 96  24 条（0x29c720..0x29c780）
 * @func 0x29c720 0x29c780  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29c728→0x542979, 0x29c730→0x47f290, 0x29c740→0x3f2098, 0x29c744→0x47f296
 * 调用序列: 无
 * 字段偏移 top8: 0x30×2 / 0x44×1 / 0x40×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c720 ldr r3, [pc, #0x44]
 *   @0x29c724 mov r2, #0
 *   @0x29c728 ldr r1, [pc, #0x40]
 *   @0x29c72c add r3, pc, r3
 *   @0x29c730 ldr r12, [pc, #0x3c]
 *   @0x29c734 push {r4, r5, r6}
 *   @0x29c738 mvn r4, #0
 *   @0x29c73c ldr r6, [r3, r1]
 *   @0x29c740 ldr r5, [pc, #0x30]
 *   @0x29c744 ldr r1, [pc, #0x30]
 *   @0x29c748 strb r0, [r6]
 *   @0x29c74c ldr r0, [r3, r5]
 *   @0x29c750 str r4, [r0]
 *   @0x29c754 ldr r0, [r3, r12]
 *   @0x29c758 pop {r4, r5, r6}
 *   @0x29c75c str r2, [r0]
 *   @0x29c760 ldr r3, [r3, r1]
 *   @0x29c764 strb r2, [r3]
 *   @0x29c768 bx lr
 *   @0x29c76c andseq r5, r5, r4, lsr #10
 *   @0x29c770 .word 0xffffdfa0
 *   @0x29c774 .word 0xffffc0f0
 *   @0x29c778 .word 0xffffc0f8
 *   @0x29c77c .word 0xfffffdbc
 *
 * ══ §131/321 png_read_rows  0x2a77e0  size 96  24 条（0x2a77e0..0x2a7840）
 * @func 0x2a77e0 0x2a7840  size 96  24 条
 * 部分覆盖: 本节 24/42 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_read_row×2
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a77e0 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2a77e4 mov r7, r1
 *   @0x2a77e8 mov r8, r3
 *   @0x2a77ec cbz r0, 0x2a783c <png_read_rows+0x5c>
 *   @0x2a77f0 cbz r2, 0x2a780e <png_read_rows+0x2e>
 *   @0x2a77f4 cmp r5, r8
 *   @0x2a77f8 ldr.w r1, [r7, r5, lsl #2]
 *   @0x2a77fc mov r0, r6
 *   @0x2a7800 strlo r2, [r1, #-0x25]
 *   @0x2a7804 bl 0x2a7488 <png_read_row>
 *   @0x2a7808 b 0x2a77f4 <png_read_rows+0x14>
 *   @0x2a780c strbmi r8, [r4, #-0x1f0]
 *   @0x2a7810 beq 0x2a7822 <png_read_rows+0x42>
 *   @0x2a7814 ldrtmi r1, [r0], -r4, lsr #32
 *   @0x2a7818 movs r2, #0x0
 *   @0x2a781c bl 0x2a7488 <png_read_row>
 *   @0x2a7820 b 0x2a780e <png_read_rows+0x2e>
 *   @0x2a7824 strdlt r8, r9, [r10, #-16]
 *   @0x2a7828 cmp r7, r8
 *   @0x2a782c ldr.w r2, [r4, r7, lsl #2]
 *   @0x2a7830 mov r0, r6
 *   @0x2a7834 adds r7, #0x1
 *   @0x2a7838 ldrb pc, [r5, r7, lsr #28]!
 *   @0x2a783c pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §132/321 png_write_sig  0x2b1140  size 96  24 条（0x2b1140..0x2b11a0）
 * @func 0x2b1140 0x2b11b0  size 112  28 条
 * 部分覆盖: 本节 28/48 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 27/46 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 26/44 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 25/42 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_data / 0xb65d4
 * 字段偏移 top8: 0x50×2 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1140 push {r4, r5, lr}
 *   @0x2b1144 ldr r5, [pc, #0x50]
 *   @0x2b1148 ldr r2, [pc, #0x50]
 *   @0x2b114c ldr r5, [r5]
 *   @0x2b1150 ldr r3, [r5]
 *   @0x2b1154 ldr r1, [r2, #0x4]
 *   @0x2b1158 add r3, sp, #0x4
 *   @0x2b115c movwgt r2, #0x31f0
 *   @0x2b1160 add r1, sp, #0x4
 *   @0x2b1164 add r1, r2
 *   @0x2b1168 qasxmi r3, r0, r4
 *   @0x2b116c rsb.w r2, r2, #0x8
 *   @0x2b1170 bl 0x2afbf0 <png_write_data>
 *   @0x2b1174 ldrb.w r3, [r4, #0x1f0]
 *   @0x2b1178 cmp r3, #0x2
 *   @0x2b117c ldr.w r3, [r4, #0x12c]
 *   @0x2b1180 orr r3, r3, #0x1000
 *   @0x2b1184 str.w r3, [r4, #0x12c]
 *   @0x2b1188 ldr r2, [sp, #0xc]
 *   @0x2b118c cmp r2, r3
 *   @0x2b1190 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b1194 add sp, #0x14
 *   @0x2b1198 ldm r0!, {r1, r3}
 *   @0x2b119c .word 0xec12 000d
 *
 * ══ §133/321 b2CircleShape::ComputeMass(b2MassData*, float) const  0x2c4dfc  size 96  24 条（0x2c4dfc..0x2c4e5c）
 * @func 0x2c4dfc 0x2c4e5c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4dfc vmov s15, r2
 *   @0x2c4e00 vldr s13, [pc, #80]
 *   @0x2c4e04 vldr s14, [r0, #8]
 *   @0x2c4e08 mov r3, r0
 *   @0x2c4e0c vmul.f32 s13, s15, s13
 *   @0x2c4e10 add r0, r0, #12
 *   @0x2c4e14 mov r2, r1
 *   @0x2c4e18 mov r12, r1
 *   @0x2c4e1c ldm r0, {r0, r1}
 *   @0x2c4e20 vmul.f32 s13, s13, s14
 *   @0x2c4e24 vmul.f32 s13, s14, s13
 *   @0x2c4e28 vstmia r2!, {s13}
 *   @0x2c4e2c stm r2, {r0, r1}
 *   @0x2c4e30 vldr s15, [r3, #16]
 *   @0x2c4e34 vmul.f32 s15, s15, s15
 *   @0x2c4e38 vldr s12, [r3, #12]
 *   @0x2c4e3c vmov.f32 s11, #5.000000e-01
 *   @0x2c4e40 vmla.f32 s15, s12, s12
 *   @0x2c4e44 vmul.f32 s12, s14, s11
 *   @0x2c4e48 vmla.f32 s15, s14, s12
 *   @0x2c4e4c vmul.f32 s15, s13, s15
 *   @0x2c4e50 vstr s15, [r12, #12]
 *   @0x2c4e54 bx lr
 *   @0x2c4e58 ldrdmi r0, r1, [r9], #-251
 *
 * ══ §134/321 b2Contact::AddType(b2Contact* (*)(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*), void (*)(b2Contact*, b2BlockAllocator*), b2Shape::Type, b2Shape::Type)  0x2cbe4c  size 96  24 条（0x2cbe4c..0x2cbeac）
 * @func 0x2cbe4c 0x2cbeac  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cbe4c push {r4, r5}
 *   @0x2cbe50 add r4, r2, r2, lsl #1
 *   @0x2cbe54 add r5, r3, r3, lsl #1
 *   @0x2cbe58 ldr r12, [pc, #0x48]
 *   @0x2cbe5c cmp r2, r3
 *   @0x2cbe60 lsl r2, r4, #4
 *   @0x2cbe64 add r2, r2, r5, lsl #2
 *   @0x2cbe68 ldr r12, [pc, r12]
 *   @0x2cbe6c add r3, r12, r2
 *   @0x2cbe70 str r0, [r12, r2]
 *   @0x2cbe74 mov r2, #1
 *   @0x2cbe78 str r1, [r3, #0x4]
 *   @0x2cbe7c strb r2, [r3, #0x8]
 *   @0x2cbe80 beq 0x2cbea0 <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_+0x54>
 *   @0x2cbe84 lsl r5, r5, #4
 *   @0x2cbe88 mov r2, #0
 *   @0x2cbe8c add r4, r5, r4, lsl #2
 *   @0x2cbe90 add r3, r12, r4
 *   @0x2cbe94 str r0, [r12, r4]
 *   @0x2cbe98 str r1, [r3, #0x4]
 *   @0x2cbe9c strb r2, [r3, #0x8]
 *   @0x2cbea0 pop {r4, r5}
 *   @0x2cbea4 bx lr
 *   @0x2cbea8 mulseq r2, r12, r12
 *
 * ══ §135/321 b2DynamicTree::ValidateStructure(int) const  0x2df8a0  size 96  24 条（0x2df8a0..0x2df900）
 * @func 0x2df8a0 0x2df910  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::ValidateStructure(int) const
 * 字段偏移 top8: 0x4×2 / 0x18×2 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df8a0 cmn r1, #1
 *   @0x2df8a4 push {r3, r4, r5, lr}
 *   @0x2df8a8 mov r5, r0
 *   @0x2df8ac popeq {r3, r4, r5, pc}
 *   @0x2df8b0 add r1, r1, r1, lsl #3
 *   @0x2df8b4 ldr r3, [r0, #0x4]
 *   @0x2df8b8 add r3, r3, r1, lsl #2
 *   @0x2df8bc ldr r1, [r3, #0x18]
 *   @0x2df8c0 ldr r4, [r3, #0x1c]
 *   @0x2df8c4 cmn r1, #1
 *   @0x2df8c8 bne 0x2df8e8 <_ZNK13b2DynamicTree17ValidateStructureEi+0x48>
 *   @0x2df8cc pop {r3, r4, r5, pc}
 *   @0x2df8d0 ldr r2, [r5, #0x4]
 *   @0x2df8d4 add r3, r2, r3, lsl #2
 *   @0x2df8d8 ldr r1, [r3, #0x18]
 *   @0x2df8dc ldr r4, [r3, #0x1c]
 *   @0x2df8e0 cmn r1, #1
 *   @0x2df8e4 popeq {r3, r4, r5, pc}
 *   @0x2df8e8 mov r0, r5
 *   @0x2df8ec bl 0x2df8a0 <_ZNK13b2DynamicTree17ValidateStructureEi>
 *   @0x2df8f0 cmn r4, #1
 *   @0x2df8f4 add r3, r4, r4, lsl #3
 *   @0x2df8f8 bne 0x2df8d0 <_ZNK13b2DynamicTree17ValidateStructureEi+0x30>
 *   @0x2df8fc pop {r3, r4, r5, pc}
 *
 * ══ §136/321 b2DynamicTree::ValidateMetrics(int) const  0x2df900  size 96  24 条（0x2df900..0x2df960）
 * @func 0x2df900 0x2df960  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::ValidateMetrics(int) const
 * 字段偏移 top8: 0x4×2 / 0x18×2 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df900 cmn r1, #1
 *   @0x2df904 push {r3, r4, r5, lr}
 *   @0x2df908 mov r5, r0
 *   @0x2df90c popeq {r3, r4, r5, pc}
 *   @0x2df910 add r1, r1, r1, lsl #3
 *   @0x2df914 ldr r3, [r0, #0x4]
 *   @0x2df918 add r3, r3, r1, lsl #2
 *   @0x2df91c ldr r1, [r3, #0x18]
 *   @0x2df920 ldr r4, [r3, #0x1c]
 *   @0x2df924 cmn r1, #1
 *   @0x2df928 bne 0x2df948 <_ZNK13b2DynamicTree15ValidateMetricsEi+0x48>
 *   @0x2df92c pop {r3, r4, r5, pc}
 *   @0x2df930 ldr r2, [r5, #0x4]
 *   @0x2df934 add r3, r2, r3, lsl #2
 *   @0x2df938 ldr r1, [r3, #0x18]
 *   @0x2df93c ldr r4, [r3, #0x1c]
 *   @0x2df940 cmn r1, #1
 *   @0x2df944 popeq {r3, r4, r5, pc}
 *   @0x2df948 mov r0, r5
 *   @0x2df94c bl 0x2df900 <_ZNK13b2DynamicTree15ValidateMetricsEi>
 *   @0x2df950 cmn r4, #1
 *   @0x2df954 add r3, r4, r4, lsl #3
 *   @0x2df958 bne 0x2df930 <_ZNK13b2DynamicTree15ValidateMetricsEi+0x30>
 *   @0x2df95c pop {r3, r4, r5, pc}
 *
 * ══ §137/321 FT_MulDiv_No_Round  0x2e4dec  size 96  24 条（0x2e4dec..0x2e4e4c）
 * @func 0x2e4dec 0x2e4e4c  size 96  24 条
 * 部分覆盖: 本节 24/46 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e490c+0x332
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4dec push {r0, r1, r2, r4, r5, lr}
 *   @0x2e4df0 it lt
 *   @0x2e4df4 mov r4, r2
 *   @0x2e4df8 movlt.w r5, #0xffffffff
 *   @0x2e4dfc movge r5, #0x1
 *   @0x2e4e00 itt lt
 *   @0x2e4e04 rsblt r1, r1, #0
 *   @0x2e4e08 itt lt
 *   @0x2e4e0c rsblt r5, r5, #0
 *   @0x2e4e10 adds r3, r1, r0
 *   @0x2e4e14 andle r3, r1, #0, #30
 *   @0x2e4e18 muls r0, r1, r0
 *   @0x2e4e1c mov r2, sp
 *   @0x2e4e20 stmdals r1, {r0, r2, r4, r5, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2e4e24 cbnz r0, 0x2e4e30 <FT_MulDiv_No_Round+0x44>
 *   @0x2e4e28 mov r1, r4
 *   @0x2e4e2c and lr, r8, lr, lsl #30
 *   @0x2e4e30 cmp r0, r4
 *   @0x2e4e34 bhs 0x2e4e3e <FT_MulDiv_No_Round+0x52>
 *   @0x2e4e38 bl 0x2e4c3e <_ZNK11b2GearJoint8GetRatioEv+0x33a>
 *   @0x2e4e3c b 0x2e4e42 <FT_MulDiv_No_Round+0x56>
 *   @0x2e4e40 strlo r4, [r1, #-0x0]
 *   @0x2e4e44 it eq
 *   @0x2e4e48 add sp, #0xc
 *
 * ══ §138/321 FT_Request_Size  0x2e572c  size 96  24 条（0x2e572c..0x2e578c）
 * @func 0x2e572c 0x2e578c  size 96  24 条
 * 部分覆盖: 本节 24/47 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Request_Size+0x5a / 0x366374 / FT_Select_Size
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e572c push {r0, r1, r2, r4, r5, lr}
 *   @0x2e5730 cbz r0, 0x2e5782 <FT_Request_Size+0x56>
 *   @0x2e5734 ldr r2, [r1, #0x4]
 *   @0x2e5738 blt 0x2e5786 <FT_Request_Size+0x5a>
 *   @0x2e573c cmp r2, #0x0
 *   @0x2e5740 ldr r3, [r1]
 *   @0x2e5744 bhi 0x2e5786 <FT_Request_Size+0x5a>
 *   @0x2e5748 movs r2, #0x0
 *   @0x2e574c str r2, [r3, #0xc]
 *   @0x2e5750 ldr r3, [r3, #0xc]
 *   @0x2e5754 cbz r5, 0x2e575c <FT_Request_Size+0x30>
 *   @0x2e5758 blx r5
 *   @0x2e575c ldr r3, [r0, #0x8]
 *   @0x2e5760 blhs 0x366374 <_ZTS12CDS_Priority+0x83cc>
 *   @0x2e5764 bne 0x2e577a <FT_Request_Size+0x4e>
 *   @0x2e5768 add r3, sp, #0x4
 *   @0x2e576c ldmdblt r8, {r0, r1, r3, r4, r6, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2e5770 mov r0, r4
 *   @0x2e5774 bl 0x2e56fa <FT_Select_Size>
 *   @0x2e5778 b 0x2e5788 <FT_Request_Size+0x5c>
 *   @0x2e577c strtmi pc, [r8], -r5, lsl #30
 *   @0x2e5780 b 0x2e5788 <FT_Request_Size+0x5c>
 *   @0x2e5784 b 0x2e5788 <FT_Request_Size+0x5c>
 *   @0x2e5788 add sp, #0xc
 *
 * ══ §139/321 FT_Outline_Copy  0x2e636c  size 96  24 条（0x2e636c..0x2e63cc）
 * @func 0x2e636c 0x2e63cc  size 96  24 条
 * 部分覆盖: 本节 24/48 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×2 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e636c push {r3, r4, r5, lr}
 *   @0x2e6370 mov r4, r0
 *   @0x2e6374 cbz r1, 0x2e63c0 <FT_Outline_Copy+0x54>
 *   @0x2e6378 ldr r3, [r1]
 *   @0x2e637c bne 0x2e63c4 <FT_Outline_Copy+0x58>
 *   @0x2e6380 beq 0x2e63c8 <FT_Outline_Copy+0x5c>
 *   @0x2e6384 cbz r2, 0x2e639e <FT_Outline_Copy+0x32>
 *   @0x2e6388 ldr r0, [r1, #0x4]
 *   @0x2e638c lsls r2, r2, #0x3
 *   @0x2e6390 stmvs r8!, {r1, r2, r4, r8, r11, sp, lr, pc}
 *   @0x2e6394 ldr r1, [r4, #0x8]
 *   @0x2e6398 .word 0xf5d02002
 *   @0x2e639c stmdahi r2!, {r4, r8, r11, sp, lr, pc}
 *   @0x2e63a0 cbz r2, 0x2e63ae <FT_Outline_Copy+0x42>
 *   @0x2e63a4 ldr r0, [r5, #0xc]
 *   @0x2e63a8 lsls r2, r2, #0x1
 *   @0x2e63ac stmdbvs r2!, {r3, r8, r11, sp, lr, pc}
 *   @0x2e63b0 ldr r3, [r5, #0x10]
 *   @0x2e63b4 .word 0xf0030201
 *   @0x2e63b8 tstmi r3, #67108864
 *   @0x2e63bc str r3, [r5, #0x10]
 *   @0x2e63c0 movs r0, #0x14
 *   @0x2e63c4 movs r0, #0x6
 *   @0x2e63c8 movs r0, #0x0
 *
 * ══ §140/321 CSkeletonSprite::~CSkeletonSprite()  0xbd910  size 92  23 条（0xbd910..0xbd96c）
 * @func 0xbd910 0xbd96c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_dispose / spSkeletonJson_dispose / spAtlas_dispose
 * 字段偏移 top8: 0x4×1 / 0x28×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd910 push {r3, r4, r5, lr}
 *   @0xbd914 mov r5, r0
 *   @0xbd918 ldr r0, [r0, #0x4]
 *   @0xbd91c cmp r0, #0
 *   @0xbd920 beq 0xbd928 <_ZN15CSkeletonSpriteD2Ev+0x18>
 *   @0xbd924 bl 0x28adf8 <spSkeletonData_dispose>
 *   @0xbd928 ldr r0, [r5]
 *   @0xbd92c cmp r0, #0
 *   @0xbd930 beq 0xbd938 <_ZN15CSkeletonSpriteD2Ev+0x28>
 *   @0xbd934 bl 0x28b74c <spSkeletonJson_dispose>
 *   @0xbd938 ldr r4, [pc, #0x28]
 *   @0xbd93c mov r3, #1
 *   @0xbd940 ldr r0, [r5, #0x8]
 *   @0xbd944 ldr r4, [pc, r4]
 *   @0xbd948 cmp r0, #0
 *   @0xbd94c strb r3, [r4]
 *   @0xbd950 beq 0xbd958 <_ZN15CSkeletonSpriteD2Ev+0x48>
 *   @0xbd954 bl 0x284120 <spAtlas_dispose>
 *   @0xbd958 mov r3, #0
 *   @0xbd95c mov r0, r5
 *   @0xbd960 strb r3, [r4]
 *   @0xbd964 pop {r3, r4, r5, pc}
 *   @0xbd968 ldrsbteq pc, [r2], -r4
 *
 * ══ §141/321 UnicodeToASCII(char const*)  0xc4684  size 92  23 条（0xc4684..0xc46e0）
 * @func 0xc4684 0xc46e0  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65ec / MemoryManager::Alloc(unsigned int, char const*, int, bool) / UnicodeToASCII(char const*)+0x4c
 * 字段偏移 top8: 0x44×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4684 push {r3, r4, r5, lr}
 *   @0xc4688 mov r5, r0
 *   @0xc468c bl 0xb65ec <wcslen@plt>
 *   @0xc4690 ldr r1, [pc, #0x44]
 *   @0xc4694 mov r2, #214
 *   @0xc4698 mov r3, #1
 *   @0xc469c add r1, pc, r1
 *   @0xc46a0 mov r4, r0
 *   @0xc46a4 add r0, r0, #1
 *   @0xc46a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xc46ac cmp r4, #0
 *   @0xc46b0 subgt r2, r5, #2
 *   @0xc46b4 movgt r3, #0
 *   @0xc46b8 ble 0xc46d0 <_Z14UnicodeToASCIIPKc+0x4c>
 *   @0xc46bc ldrh r1, [r2, #2]!
 *   @0xc46c0 strb r1, [r0, r3]
 *   @0xc46c4 add r3, r3, #1
 *   @0xc46c8 cmp r4, r3
 *   @0xc46cc bne 0xc46bc <_Z14UnicodeToASCIIPKc+0x38>
 *   @0xc46d0 mov r3, #0
 *   @0xc46d4 strb r3, [r0, r4]
 *   @0xc46d8 pop {r3, r4, r5, pc}
 *   @0xc46dc eoreq r12, r6, r8, ror #8
 *
 * ══ §142/321 Variable_GetName(int)  0xd1d04  size 92  23 条（0xd1d04..0xd1d60）
 * @func 0xd1d04 0xd1d60  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x28×1 / 0x2×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1d04 sub r0, r0, #99328
 *   @0xd1d08 subs r0, r0, #672
 *   @0xd1d0c bmi 0xd1d44 <_Z16Variable_GetNamei+0x40>
 *   @0xd1d10 ldr r3, [pc, #0x38]
 *   @0xd1d14 ldr r3, [pc, r3]
 *   @0xd1d18 ldr r3, [r3]
 *   @0xd1d1c cmp r0, r3
 *   @0xd1d20 bge 0xd1d38 <_Z16Variable_GetNamei+0x34>
 *   @0xd1d24 ldr r3, [pc, #0x28]
 *   @0xd1d28 ldr r3, [pc, r3]
 *   @0xd1d2c ldr r3, [r3]
 *   @0xd1d30 ldr r0, [r3, r0, lsl #2]
 *   @0xd1d34 bx lr
 *   @0xd1d38 ldr r0, [pc, #0x18]
 *   @0xd1d3c add r0, pc, r0
 *   @0xd1d40 bx lr
 *   @0xd1d44 ldr r0, [pc, #0x10]
 *   @0xd1d48 add r0, pc, r0
 *   @0xd1d4c bx lr
 *   @0xd1d50 eorseq r11, r1, r0, lsl #29
 *   @0xd1d54 eorseq r11, r1, r0, ror lr
 *   @0xd1d58 eoreq r0, r6, r12, lsl r10
 *   @0xd1d5c eoreq r0, r6, r0, lsl r10
 *
 * ══ §143/321 CExtensionFile::ConstantFindName(char const*)  0xf4f34  size 92  23 条（0xf4f34..0xf4f90）
 * @func 0xf4f34 0xf4f90  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::ConstantFindName(char const*)+0x50 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4f34 push {r4, r5, r6, r7, r8, lr}
 *   @0xf4f38 mov r8, r1
 *   @0xf4f3c ldr r7, [r0, #0x28]
 *   @0xf4f40 cmp r7, #0
 *   @0xf4f44 ble 0xf4f84 <_ZN14CExtensionFile16ConstantFindNameEPKc+0x50>
 *   @0xf4f48 ldr r6, [r0, #0x24]
 *   @0xf4f4c mov r4, #0
 *   @0xf4f50 sub r6, r6, #4
 *   @0xf4f54 b 0xf4f60 <_ZN14CExtensionFile16ConstantFindNameEPKc+0x2c>
 *   @0xf4f58 cmp r4, r7
 *   @0xf4f5c beq 0xf4f84 <_ZN14CExtensionFile16ConstantFindNameEPKc+0x50>
 *   @0xf4f60 ldr r5, [r6, #0x4]!
 *   @0xf4f64 mov r1, r8
 *   @0xf4f68 add r4, r4, #1
 *   @0xf4f6c ldr r0, [r5, #0x4]
 *   @0xf4f70 bl 0xb6574 <strcmp@plt>
 *   @0xf4f74 cmp r0, #0
 *   @0xf4f78 bne 0xf4f58 <_ZN14CExtensionFile16ConstantFindNameEPKc+0x24>
 *   @0xf4f7c mov r0, r5
 *   @0xf4f80 pop {r4, r5, r6, r7, r8, pc}
 *   @0xf4f84 mov r5, #0
 *   @0xf4f88 mov r0, r5
 *   @0xf4f8c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §144/321 dsListAddInt  0x101c18  size 92  23 条（0x101c18..0x101c74）
 * @func 0x101c18 0x101c84  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsListAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x20×1 / 0x30×1 / 0x24×1 / 0x34×1 / 0x4×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101c18 vmov s11, r1
 *   @0x101c1c mov r12, #0
 *   @0x101c20 str lr, [sp, #-0x4]!
 *   @0x101c24 vcvt.f64.s32 d6, s11
 *   @0x101c28 vmov s11, r0
 *   @0x101c2c sub sp, sp, #60
 *   @0x101c30 add r3, sp, #24
 *   @0x101c34 mov r1, r12
 *   @0x101c38 str r3, [sp]
 *   @0x101c3c mov r2, r12
 *   @0x101c40 mov r3, #2
 *   @0x101c44 add r0, sp, #8
 *   @0x101c48 str r12, [sp, #0x8]
 *   @0x101c4c str r12, [sp, #0x20]
 *   @0x101c50 vcvt.f64.s32 d7, s11
 *   @0x101c54 str r12, [sp, #0x30]
 *   @0x101c58 str r12, [sp, #0x24]
 *   @0x101c5c vstr d6, [sp, #40]
 *   @0x101c60 str r12, [sp, #0x34]
 *   @0x101c64 vstr d7, [sp, #24]
 *   @0x101c68 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_>
 *   @0x101c6c add sp, sp, #60
 *   @0x101c70 ldr pc, [sp], #4
 *
 * ══ §145/321 F_MpPotentialSettings(RValue&, CInstance*, CInstance*, int, RValue*)  0x108b68  size 92  23 条（0x108b68..0x108bc4）
 * @func 0x108b68 0x108bc4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108b68 push {r4, r5, r6, r7, r8, lr}
 *   @0x108b6c mov r1, #0
 *   @0x108b70 ldr r4, [sp, #0x18]
 *   @0x108b74 mov r0, r4
 *   @0x108b78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108b7c mov r1, #1
 *   @0x108b80 mov r7, r0
 *   @0x108b84 mov r0, r4
 *   @0x108b88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108b8c mov r1, #2
 *   @0x108b90 mov r6, r0
 *   @0x108b94 mov r0, r4
 *   @0x108b98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108b9c mov r1, #3
 *   @0x108ba0 mov r5, r0
 *   @0x108ba4 mov r0, r4
 *   @0x108ba8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x108bac mov r1, r6
 *   @0x108bb0 mov r2, r5
 *   @0x108bb4 mov r3, r0
 *   @0x108bb8 mov r0, r7
 *   @0x108bbc pop {r4, r5, r6, r7, r8, lr}
 *   @0x108bc0 b 0x19cb18 <_Z25Motion_Potential_Settingsfffb>
 *
 * ══ §146/321 F_PositionChange(RValue&, CInstance*, CInstance*, int, RValue*)  0x1099fc  size 92  23 条（0x1099fc..0x109a58）
 * @func 0x1099fc 0x109a68  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1099fc push {r4, r5, r6, r7, r8, lr}
 *   @0x109a00 mov r1, #0
 *   @0x109a04 ldr r4, [sp, #0x18]
 *   @0x109a08 mov r0, r4
 *   @0x109a0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109a10 mov r1, #1
 *   @0x109a14 mov r7, r0
 *   @0x109a18 mov r0, r4
 *   @0x109a1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109a20 mov r1, #2
 *   @0x109a24 mov r6, r0
 *   @0x109a28 mov r0, r4
 *   @0x109a2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109a30 mov r1, #3
 *   @0x109a34 mov r5, r0
 *   @0x109a38 mov r0, r4
 *   @0x109a3c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x109a40 mov r1, r6
 *   @0x109a44 mov r2, r5
 *   @0x109a48 mov r3, r0
 *   @0x109a4c mov r0, r7
 *   @0x109a50 pop {r4, r5, r6, r7, r8, lr}
 *   @0x109a54 b 0x1c9cf8 <_Z16Command_ChangeAtffib>
 *
 * ══ §147/321 RTree<CInstance*, int, float, 6, 2>::Search(int const*, int const*, bool (*)(CInstance*, void*), void*)  0x10d720  size 92  23 条（0x10d720..0x10d77c）
 * @func 0x10d720 0x10d77c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::Search(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Rect*, int&, bool (*)(CInstance*, void*), void*)
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0xc×2 / 0x38×1 / 0x14×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10d720 push {r4, r5, r6, r7, lr}
 *   @0x10d724 sub sp, sp, #36
 *   @0x10d728 ldr r4, [r0, #0x10]
 *   @0x10d72c mov r12, r2
 *   @0x10d730 ldr r7, [sp, #0x38]
 *   @0x10d734 add r2, sp, #16
 *   @0x10d738 ldr r6, [r1]
 *   @0x10d73c mov lr, #0
 *   @0x10d740 ldr r5, [r1, #0x4]
 *   @0x10d744 mov r1, r4
 *   @0x10d748 ldm r12, {r4, r12}
 *   @0x10d74c str r3, [sp]
 *   @0x10d750 add r3, sp, #12
 *   @0x10d754 str r7, [sp, #0x4]
 *   @0x10d758 str r6, [sp, #0x10]
 *   @0x10d75c str r5, [sp, #0x14]
 *   @0x10d760 str r4, [sp, #0x18]
 *   @0x10d764 str r12, [sp, #0x1c]
 *   @0x10d768 str lr, [sp, #0xc]
 *   @0x10d76c bl 0x10d558 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_>
 *   @0x10d770 ldr r0, [sp, #0xc]
 *   @0x10d774 add sp, sp, #36
 *   @0x10d778 pop {r4, r5, r6, r7, pc}
 *
 * ══ §148/321 F_Logn(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e440  size 92  23 条（0x10e440..0x10e49c）
 * @func 0x10e440 0x10e49c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2 / 0xb6730×2
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e440 push {r4, r5, r6, lr}
 *   @0x10e444 vpush {d8}
 *   @0x10e448 mov r4, r0
 *   @0x10e44c ldr r5, [sp, #0x18]
 *   @0x10e450 mov r6, #0
 *   @0x10e454 mov r1, #1
 *   @0x10e458 str r6, [r0, #0xc]
 *   @0x10e45c mov r0, r5
 *   @0x10e460 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e464 bl 0xb6730 <log@plt>
 *   @0x10e468 vmov d8, r0, r1
 *   @0x10e46c mov r0, r5
 *   @0x10e470 mov r1, r6
 *   @0x10e474 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e478 bl 0xb6730 <log@plt>
 *   @0x10e47c vmov d7, r0, r1
 *   @0x10e480 vdiv.f64 d7, d8, d7
 *   @0x10e484 vmov r0, r1, d7
 *   @0x10e488 vmov r2, s14
 *   @0x10e48c mov r3, r1
 *   @0x10e490 stm r4, {r2, r3}
 *   @0x10e494 vpop {d8}
 *   @0x10e498 pop {r4, r5, r6, pc}
 *
 * ══ §149/321 F_WindowSetRectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a4dc  size 92  23 条（0x11a4dc..0x11a538）
 * @func 0x11a4dc 0x11a538  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a4dc push {r4, r5, r6, r7, r8, lr}
 *   @0x11a4e0 mov r1, #0
 *   @0x11a4e4 ldr r4, [sp, #0x18]
 *   @0x11a4e8 mov r0, r4
 *   @0x11a4ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a4f0 mov r1, #1
 *   @0x11a4f4 mov r7, r0
 *   @0x11a4f8 mov r0, r4
 *   @0x11a4fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a500 mov r1, #2
 *   @0x11a504 mov r6, r0
 *   @0x11a508 mov r0, r4
 *   @0x11a50c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a510 mov r1, #3
 *   @0x11a514 mov r5, r0
 *   @0x11a518 mov r0, r4
 *   @0x11a51c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a520 mov r1, r6
 *   @0x11a524 mov r2, r5
 *   @0x11a528 mov r3, r0
 *   @0x11a52c mov r0, r7
 *   @0x11a530 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11a534 b 0x17add4 <_Z23GR_Window_Set_Rectangleiiii>
 *
 * ══ §150/321 F_DrawSetColorWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ac54  size 92  23 条（0x11ac54..0x11acb0）
 * @func 0x11ac54 0x11acb0  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ac54 push {r4, r5, r6, r7, r8, lr}
 *   @0x11ac58 mov r1, #0
 *   @0x11ac5c ldr r4, [sp, #0x18]
 *   @0x11ac60 mov r0, r4
 *   @0x11ac64 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11ac68 mov r1, #1
 *   @0x11ac6c mov r7, r0
 *   @0x11ac70 mov r0, r4
 *   @0x11ac74 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11ac78 mov r1, #2
 *   @0x11ac7c mov r6, r0
 *   @0x11ac80 mov r0, r4
 *   @0x11ac84 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11ac88 mov r1, #3
 *   @0x11ac8c mov r5, r0
 *   @0x11ac90 mov r0, r4
 *   @0x11ac94 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11ac98 mov r1, r6
 *   @0x11ac9c mov r2, r5
 *   @0x11aca0 mov r3, r0
 *   @0x11aca4 mov r0, r7
 *   @0x11aca8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11acac b 0x1683a4 <_Z30GR_D3D_Set_Colour_Write_Enablebbbb>
 *
 * ══ §151/321 F_DrawLine(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ae0c  size 92  23 条（0x11ae0c..0x11ae68）
 * @func 0x11ae0c 0x11ae68  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ae0c push {r4, r5, r6, r7, r8, lr}
 *   @0x11ae10 mov r1, #0
 *   @0x11ae14 ldr r4, [sp, #0x18]
 *   @0x11ae18 mov r0, r4
 *   @0x11ae1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ae20 mov r1, #1
 *   @0x11ae24 mov r7, r0
 *   @0x11ae28 mov r0, r4
 *   @0x11ae2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ae30 mov r1, #2
 *   @0x11ae34 mov r6, r0
 *   @0x11ae38 mov r0, r4
 *   @0x11ae3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ae40 mov r1, #3
 *   @0x11ae44 mov r5, r0
 *   @0x11ae48 mov r0, r4
 *   @0x11ae4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ae50 mov r1, r6
 *   @0x11ae54 mov r2, r5
 *   @0x11ae58 mov r3, r0
 *   @0x11ae5c mov r0, r7
 *   @0x11ae60 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11ae64 b 0x16a21c <_Z12GR_Draw_Lineffff>
 *
 * ══ §152/321 F_DrawCircle(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b138  size 92  23 条（0x11b138..0x11b194）
 * @func 0x11b138 0x11b194  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b138 push {r4, r5, r6, r7, r8, lr}
 *   @0x11b13c mov r1, #0
 *   @0x11b140 ldr r4, [sp, #0x18]
 *   @0x11b144 mov r0, r4
 *   @0x11b148 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b14c mov r1, #1
 *   @0x11b150 mov r7, r0
 *   @0x11b154 mov r0, r4
 *   @0x11b158 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b15c mov r1, #2
 *   @0x11b160 mov r6, r0
 *   @0x11b164 mov r0, r4
 *   @0x11b168 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b16c mov r1, #3
 *   @0x11b170 mov r5, r0
 *   @0x11b174 mov r0, r4
 *   @0x11b178 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b17c mov r1, r6
 *   @0x11b180 mov r2, r5
 *   @0x11b184 mov r3, r0
 *   @0x11b188 mov r0, r7
 *   @0x11b18c pop {r4, r5, r6, r7, r8, lr}
 *   @0x11b190 b 0x16b198 <_Z14GR_Draw_Circlefffb>
 *
 * ══ §153/321 F_DrawVertexColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ba60  size 92  23 条（0x11ba60..0x11babc）
 * @func 0x11ba60 0x11bacc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ba60 push {r4, r5, r6, r7, r8, lr}
 *   @0x11ba64 mov r1, #0
 *   @0x11ba68 ldr r4, [sp, #0x18]
 *   @0x11ba6c mov r0, r4
 *   @0x11ba70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ba74 mov r1, #1
 *   @0x11ba78 mov r7, r0
 *   @0x11ba7c mov r0, r4
 *   @0x11ba80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ba84 mov r1, #2
 *   @0x11ba88 mov r6, r0
 *   @0x11ba8c mov r0, r4
 *   @0x11ba90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ba94 mov r1, #3
 *   @0x11ba98 mov r5, r0
 *   @0x11ba9c mov r0, r4
 *   @0x11baa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11baa4 mov r1, r6
 *   @0x11baa8 mov r2, r5
 *   @0x11baac mov r3, r0
 *   @0x11bab0 mov r0, r7
 *   @0x11bab4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11bab8 b 0x16bae0 <_Z20GR_Draw_Vertex_Colorffjf>
 *
 * ══ §154/321 F_DrawVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x11babc  size 92  23 条（0x11babc..0x11bb18）
 * @func 0x11babc 0x11bb18  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11babc push {r4, r5, r6, r7, r8, lr}
 *   @0x11bac0 mov r1, #0
 *   @0x11bac4 ldr r4, [sp, #0x18]
 *   @0x11bac8 mov r0, r4
 *   @0x11bacc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bad0 mov r1, #1
 *   @0x11bad4 mov r7, r0
 *   @0x11bad8 mov r0, r4
 *   @0x11badc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bae0 mov r1, #2
 *   @0x11bae4 mov r6, r0
 *   @0x11bae8 mov r0, r4
 *   @0x11baec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11baf0 mov r1, #3
 *   @0x11baf4 mov r5, r0
 *   @0x11baf8 mov r0, r4
 *   @0x11bafc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bb00 mov r1, r6
 *   @0x11bb04 mov r2, r5
 *   @0x11bb08 mov r3, r0
 *   @0x11bb0c mov r0, r7
 *   @0x11bb10 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11bb14 b 0x16bb70 <_Z22GR_Draw_Vertex_Textureffff>
 *
 * ══ §155/321 F_TileLayerShift(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c4d0  size 92  23 条（0x11c4d0..0x11c52c）
 * @func 0x11c4d0 0x11c52c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x18×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c4d0 push {r4, r5, r6, r7, r8, lr}
 *   @0x11c4d4 mov r1, #0
 *   @0x11c4d8 ldr r4, [sp, #0x18]
 *   @0x11c4dc ldr r3, [pc, #0x44]
 *   @0x11c4e0 ldr r3, [pc, r3]
 *   @0x11c4e4 mov r0, r4
 *   @0x11c4e8 ldr r7, [r3]
 *   @0x11c4ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c4f0 mov r1, #1
 *   @0x11c4f4 mov r6, r0
 *   @0x11c4f8 mov r0, r4
 *   @0x11c4fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c500 mov r1, #2
 *   @0x11c504 mov r5, r0
 *   @0x11c508 mov r0, r4
 *   @0x11c50c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c510 mov r1, r6
 *   @0x11c514 mov r2, r5
 *   @0x11c518 mov r3, r0
 *   @0x11c51c mov r0, r7
 *   @0x11c520 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11c524 b 0x1af6c8 <_ZN5CRoom15ShiftTilesDepthEfff>
 *   @0x11c528 eoreq r1, sp, r8, asr #8
 *
 * ══ §156/321 F_TileLayerDeleteAt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c5d8  size 92  23 条（0x11c5d8..0x11c634）
 * @func 0x11c5d8 0x11c634  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x18×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c5d8 push {r4, r5, r6, r7, r8, lr}
 *   @0x11c5dc mov r1, #0
 *   @0x11c5e0 ldr r4, [sp, #0x18]
 *   @0x11c5e4 ldr r3, [pc, #0x44]
 *   @0x11c5e8 ldr r3, [pc, r3]
 *   @0x11c5ec mov r0, r4
 *   @0x11c5f0 ldr r7, [r3]
 *   @0x11c5f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c5f8 mov r1, #1
 *   @0x11c5fc mov r6, r0
 *   @0x11c600 mov r0, r4
 *   @0x11c604 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c608 mov r1, #2
 *   @0x11c60c mov r5, r0
 *   @0x11c610 mov r0, r4
 *   @0x11c614 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c618 mov r1, r6
 *   @0x11c61c mov r2, r5
 *   @0x11c620 mov r3, r0
 *   @0x11c624 mov r0, r7
 *   @0x11c628 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11c62c b 0x1af860 <_ZN5CRoom18DeleteTilesAtDepthEfff>
 *   @0x11c630 eoreq r1, sp, r0, asr #6
 *
 * ══ §157/321 F_SkeletonGetFrames(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cc18  size 92  23 条（0x11cc18..0x11cc74）
 * @func 0x11cc18 0x11cc74  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / CSkeletonInstance::GetFrames(char*) const
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cc18 push {r4, r5, r6, lr}
 *   @0x11cc1c mov r4, r0
 *   @0x11cc20 mov r5, #0
 *   @0x11cc24 mov r0, r1
 *   @0x11cc28 str r5, [r4, #0xc]
 *   @0x11cc2c str r5, [r4]
 *   @0x11cc30 str r5, [r4, #0x4]
 *   @0x11cc34 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cc38 subs r6, r0, #0
 *   @0x11cc3c popeq {r4, r5, r6, pc}
 *   @0x11cc40 mov r1, r5
 *   @0x11cc44 ldr r0, [sp, #0x10]
 *   @0x11cc48 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11cc4c mov r1, r0
 *   @0x11cc50 mov r0, r6
 *   @0x11cc54 bl 0xc0930 <_ZNK17CSkeletonInstance9GetFramesEPc>
 *   @0x11cc58 vmov s15, r0
 *   @0x11cc5c vcvt.f64.s32 d7, s15
 *   @0x11cc60 vmov r0, r1, d7
 *   @0x11cc64 vmov r2, s14
 *   @0x11cc68 mov r3, r1
 *   @0x11cc6c stm r4, {r2, r3}
 *   @0x11cc70 pop {r4, r5, r6, pc}
 *
 * ══ §158/321 F_SkeletonAnimationGetFrame(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ccbc  size 92  23 条（0x11ccbc..0x11cd18）
 * @func 0x11ccbc 0x11cd28  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetInt32(RValue const*, int) / CSkeletonInstance::ImageIndex(int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ccbc push {r4, r5, r6, lr}
 *   @0x11ccc0 mov r4, r0
 *   @0x11ccc4 mov r5, #0
 *   @0x11ccc8 mov r0, r1
 *   @0x11cccc str r5, [r4, #0xc]
 *   @0x11ccd0 str r5, [r4]
 *   @0x11ccd4 str r5, [r4, #0x4]
 *   @0x11ccd8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11ccdc subs r6, r0, #0
 *   @0x11cce0 popeq {r4, r5, r6, pc}
 *   @0x11cce4 mov r1, r5
 *   @0x11cce8 ldr r0, [sp, #0x10]
 *   @0x11ccec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ccf0 mov r1, r0
 *   @0x11ccf4 mov r0, r6
 *   @0x11ccf8 bl 0xbe30c <_ZN17CSkeletonInstance10ImageIndexEi>
 *   @0x11ccfc vmov s15, r0
 *   @0x11cd00 vcvt.f64.f32 d7, s15
 *   @0x11cd04 vmov r0, r1, d7
 *   @0x11cd08 vmov r2, s14
 *   @0x11cd0c mov r3, r1
 *   @0x11cd10 stm r4, {r2, r3}
 *   @0x11cd14 pop {r4, r5, r6, pc}
 *
 * ══ §159/321 F_SkeletonAnimationSetFrame(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cd18  size 92  23 条（0x11cd18..0x11cd74）
 * @func 0x11cd18 0x11cd74  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cd18 mov r3, r0
 *   @0x11cd1c mov r0, r1
 *   @0x11cd20 push {r4, r5, r6, lr}
 *   @0x11cd24 mov r4, #0
 *   @0x11cd28 str r4, [r3, #0xc]
 *   @0x11cd2c str r4, [r3]
 *   @0x11cd30 str r4, [r3, #0x4]
 *   @0x11cd34 ldr r5, [sp, #0x10]
 *   @0x11cd38 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cd3c subs r6, r0, #0
 *   @0x11cd40 popeq {r4, r5, r6, pc}
 *   @0x11cd44 mov r1, r4
 *   @0x11cd48 mov r0, r5
 *   @0x11cd4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11cd50 mov r1, #1
 *   @0x11cd54 mov r4, r0
 *   @0x11cd58 mov r0, r5
 *   @0x11cd5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11cd60 mov r1, r4
 *   @0x11cd64 mov r2, r0
 *   @0x11cd68 mov r0, r6
 *   @0x11cd6c pop {r4, r5, r6, lr}
 *   @0x11cd70 b 0xbe3e8 <_ZN17CSkeletonInstance13SetImageIndexEif>
 *
 * ══ §160/321 F_SkeletonSetSkin(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d198  size 92  23 条（0x11d198..0x11d1f4）
 * @func 0x11d198 0x11d1f4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / CSkeletonInstance::SelectSkin(char const*)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d198 push {r4, r5, r6, lr}
 *   @0x11d19c mov r4, r0
 *   @0x11d1a0 mov r5, #0
 *   @0x11d1a4 mov r3, #0
 *   @0x11d1a8 mov r0, r1
 *   @0x11d1ac movt r3, #0xbff0
 *   @0x11d1b0 str r5, [r4, #0xc]
 *   @0x11d1b4 str r3, [r4, #0x4]
 *   @0x11d1b8 str r5, [r4]
 *   @0x11d1bc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d1c0 subs r6, r0, #0
 *   @0x11d1c4 popeq {r4, r5, r6, pc}
 *   @0x11d1c8 mov r1, r5
 *   @0x11d1cc ldr r0, [sp, #0x10]
 *   @0x11d1d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d1d4 mov r1, r0
 *   @0x11d1d8 mov r0, r6
 *   @0x11d1dc bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc>
 *   @0x11d1e0 mov r3, r5
 *   @0x11d1e4 str r5, [r4]
 *   @0x11d1e8 movt r3, #0x3ff0
 *   @0x11d1ec str r3, [r4, #0x4]
 *   @0x11d1f0 pop {r4, r5, r6, pc}
 *
 * ══ §161/321 F_PartTypeColor3(RValue&, CInstance*, CInstance*, int, RValue*)  0x1295c8  size 92  23 条（0x1295c8..0x129624）
 * @func 0x1295c8 0x129624  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1295c8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1295cc mov r1, #0
 *   @0x1295d0 ldr r4, [sp, #0x18]
 *   @0x1295d4 mov r0, r4
 *   @0x1295d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1295dc mov r1, #1
 *   @0x1295e0 mov r7, r0
 *   @0x1295e4 mov r0, r4
 *   @0x1295e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1295ec mov r1, #2
 *   @0x1295f0 mov r6, r0
 *   @0x1295f4 mov r0, r4
 *   @0x1295f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1295fc mov r1, #3
 *   @0x129600 mov r5, r0
 *   @0x129604 mov r0, r4
 *   @0x129608 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12960c mov r1, r6
 *   @0x129610 mov r2, r5
 *   @0x129614 mov r3, r0
 *   @0x129618 mov r0, r7
 *   @0x12961c pop {r4, r5, r6, r7, r8, lr}
 *   @0x129620 b 0x1a361c <_Z19ParticleType_Color3ijjj>
 *
 * ══ §162/321 F_PartTypeAlpha3(RValue&, CInstance*, CInstance*, int, RValue*)  0x1296a0  size 92  23 条（0x1296a0..0x1296fc）
 * @func 0x1296a0 0x1296fc  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1296a0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1296a4 mov r1, #0
 *   @0x1296a8 ldr r4, [sp, #0x18]
 *   @0x1296ac mov r0, r4
 *   @0x1296b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1296b4 mov r1, #1
 *   @0x1296b8 mov r7, r0
 *   @0x1296bc mov r0, r4
 *   @0x1296c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1296c4 mov r1, #2
 *   @0x1296c8 mov r6, r0
 *   @0x1296cc mov r0, r4
 *   @0x1296d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1296d4 mov r1, #3
 *   @0x1296d8 mov r5, r0
 *   @0x1296dc mov r0, r4
 *   @0x1296e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1296e4 mov r1, r6
 *   @0x1296e8 mov r2, r5
 *   @0x1296ec mov r3, r0
 *   @0x1296f0 mov r0, r7
 *   @0x1296f4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1296f8 b 0x1a36f8 <_Z19ParticleType_Alpha3ifff>
 *
 * ══ §163/321 F_PartEmitterBurst(RValue&, CInstance*, CInstance*, int, RValue*)  0x129dc0  size 92  23 条（0x129dc0..0x129e1c）
 * @func 0x129dc0 0x129e2c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129dc0 push {r4, r5, r6, r7, r8, lr}
 *   @0x129dc4 mov r1, #0
 *   @0x129dc8 ldr r4, [sp, #0x18]
 *   @0x129dcc mov r0, r4
 *   @0x129dd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129dd4 mov r1, #1
 *   @0x129dd8 mov r7, r0
 *   @0x129ddc mov r0, r4
 *   @0x129de0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129de4 mov r1, #2
 *   @0x129de8 mov r6, r0
 *   @0x129dec mov r0, r4
 *   @0x129df0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129df4 mov r1, #3
 *   @0x129df8 mov r5, r0
 *   @0x129dfc mov r0, r4
 *   @0x129e00 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129e04 mov r1, r6
 *   @0x129e08 mov r2, r5
 *   @0x129e0c mov r3, r0
 *   @0x129e10 mov r0, r7
 *   @0x129e14 pop {r4, r5, r6, r7, r8, lr}
 *   @0x129e18 b 0x1a3cf0 <_Z28ParticleSystem_Emitter_Burstiiii>
 *
 * ══ §164/321 F_PartEmitterStream(RValue&, CInstance*, CInstance*, int, RValue*)  0x129e1c  size 92  23 条（0x129e1c..0x129e78）
 * @func 0x129e1c 0x129e78  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129e1c push {r4, r5, r6, r7, r8, lr}
 *   @0x129e20 mov r1, #0
 *   @0x129e24 ldr r4, [sp, #0x18]
 *   @0x129e28 mov r0, r4
 *   @0x129e2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129e30 mov r1, #1
 *   @0x129e34 mov r7, r0
 *   @0x129e38 mov r0, r4
 *   @0x129e3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129e40 mov r1, #2
 *   @0x129e44 mov r6, r0
 *   @0x129e48 mov r0, r4
 *   @0x129e4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129e50 mov r1, #3
 *   @0x129e54 mov r5, r0
 *   @0x129e58 mov r0, r4
 *   @0x129e5c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129e60 mov r1, r6
 *   @0x129e64 mov r2, r5
 *   @0x129e68 mov r3, r0
 *   @0x129e6c mov r0, r7
 *   @0x129e70 pop {r4, r5, r6, r7, r8, lr}
 *   @0x129e74 b 0x1a3ad4 <_Z29ParticleSystem_Emitter_Streamiiii>
 *
 * ══ §165/321 F_TimeLineMaxMoment(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e000  size 92  23 条（0x12e000..0x12e05c）
 * @func 0x12e000 0x12e05c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / TimeLine_Data(int) / CTimeLine::GetCount() / CTimeLine::GetStep(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e000 push {r3, r4, r5, lr}
 *   @0x12e004 mov r1, #0
 *   @0x12e008 mov r4, r0
 *   @0x12e00c ldr r0, [sp, #0x10]
 *   @0x12e010 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e014 bl 0x1f2c48 <_Z13TimeLine_Datai>
 *   @0x12e018 subs r5, r0, #0
 *   @0x12e01c beq 0x12e04c <_Z19F_TimeLineMaxMomentR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12e020 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv>
 *   @0x12e024 sub r1, r0, #1
 *   @0x12e028 mov r0, r5
 *   @0x12e02c bl 0x1f1738 <_ZN9CTimeLine7GetStepEi>
 *   @0x12e030 vmov s15, r0
 *   @0x12e034 vcvt.f64.s32 d7, s15
 *   @0x12e038 vmov r2, r3, d7
 *   @0x12e03c mov r1, #0
 *   @0x12e040 stm r4, {r2, r3}
 *   @0x12e044 str r1, [r4, #0xc]
 *   @0x12e048 pop {r3, r4, r5, pc}
 *   @0x12e04c mov r3, #0
 *   @0x12e050 mov r2, #0
 *   @0x12e054 movt r3, #0xbff0
 *   @0x12e058 b 0x12e03c <_Z19F_TimeLineMaxMomentR6RValueP9CInstanceS2_iPS_+0x3c>
 *
 * ══ §166/321 F_AudioGetEmitterPositionX(RValue&, CInstance*, CInstance*, int, RValue*)  0x135340  size 92  23 条（0x135340..0x13539c）
 * @func 0x135340 0x1353ac  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetEmitterPosition(int)
 * 字段偏移 top8: 0x50×1 / 0xc×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135340 ldr r3, [pc, #0x50]
 *   @0x135344 push {r4, lr}
 *   @0x135348 ldr r3, [pc, r3]
 *   @0x13534c sub sp, sp, #16
 *   @0x135350 mov r4, r0
 *   @0x135354 ldrb r1, [r3]
 *   @0x135358 cmp r1, #0
 *   @0x13535c beq 0x135368 <_Z26F_AudioGetEmitterPositionXR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x135360 add sp, sp, #16
 *   @0x135364 pop {r4, pc}
 *   @0x135368 str r1, [r0, #0xc]
 *   @0x13536c ldr r0, [sp, #0x18]
 *   @0x135370 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135374 mov r1, r0
 *   @0x135378 add r0, sp, #4
 *   @0x13537c bl 0x216e6c <_Z24Audio_GetEmitterPositioni>
 *   @0x135380 vldr s15, [sp, #4]
 *   @0x135384 vcvt.f64.f32 d6, s15
 *   @0x135388 vmov r2, r3, d6
 *   @0x13538c stm r4, {r2, r3}
 *   @0x135390 add sp, sp, #16
 *   @0x135394 pop {r4, pc}
 *   @0x135398 eoreq r9, r11, r4, lsl #26
 *
 * ══ §167/321 F_AudioGetEmitterPositionY(RValue&, CInstance*, CInstance*, int, RValue*)  0x13539c  size 92  23 条（0x13539c..0x1353f8）
 * @func 0x13539c 0x135408  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetEmitterPosition(int)
 * 字段偏移 top8: 0x50×1 / 0xc×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13539c ldr r3, [pc, #0x50]
 *   @0x1353a0 push {r4, lr}
 *   @0x1353a4 ldr r3, [pc, r3]
 *   @0x1353a8 sub sp, sp, #16
 *   @0x1353ac mov r4, r0
 *   @0x1353b0 ldrb r1, [r3]
 *   @0x1353b4 cmp r1, #0
 *   @0x1353b8 beq 0x1353c4 <_Z26F_AudioGetEmitterPositionYR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1353bc add sp, sp, #16
 *   @0x1353c0 pop {r4, pc}
 *   @0x1353c4 str r1, [r0, #0xc]
 *   @0x1353c8 ldr r0, [sp, #0x18]
 *   @0x1353cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1353d0 mov r1, r0
 *   @0x1353d4 add r0, sp, #4
 *   @0x1353d8 bl 0x216e6c <_Z24Audio_GetEmitterPositioni>
 *   @0x1353dc vldr s15, [sp, #8]
 *   @0x1353e0 vcvt.f64.f32 d6, s15
 *   @0x1353e4 vmov r2, r3, d6
 *   @0x1353e8 stm r4, {r2, r3}
 *   @0x1353ec add sp, sp, #16
 *   @0x1353f0 pop {r4, pc}
 *   @0x1353f4 eoreq r9, r11, r8, lsr #25
 *
 * ══ §168/321 F_AudioGetEmitterPositionZ(RValue&, CInstance*, CInstance*, int, RValue*)  0x1353f8  size 92  23 条（0x1353f8..0x135454）
 * @func 0x1353f8 0x135464  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetEmitterPosition(int)
 * 字段偏移 top8: 0x50×1 / 0xc×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1353f8 ldr r3, [pc, #0x50]
 *   @0x1353fc push {r4, lr}
 *   @0x135400 ldr r3, [pc, r3]
 *   @0x135404 sub sp, sp, #16
 *   @0x135408 mov r4, r0
 *   @0x13540c ldrb r1, [r3]
 *   @0x135410 cmp r1, #0
 *   @0x135414 beq 0x135420 <_Z26F_AudioGetEmitterPositionZR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x135418 add sp, sp, #16
 *   @0x13541c pop {r4, pc}
 *   @0x135420 str r1, [r0, #0xc]
 *   @0x135424 ldr r0, [sp, #0x18]
 *   @0x135428 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13542c mov r1, r0
 *   @0x135430 add r0, sp, #4
 *   @0x135434 bl 0x216e6c <_Z24Audio_GetEmitterPositioni>
 *   @0x135438 vldr s15, [sp, #12]
 *   @0x13543c vcvt.f64.f32 d6, s15
 *   @0x135440 vmov r2, r3, d6
 *   @0x135444 stm r4, {r2, r3}
 *   @0x135448 add sp, sp, #16
 *   @0x13544c pop {r4, pc}
 *   @0x135450 eoreq r9, r11, r12, asr #24
 *
 * ══ §169/321 F_AudioGetEmitterVelocityX(RValue&, CInstance*, CInstance*, int, RValue*)  0x135454  size 92  23 条（0x135454..0x1354b0）
 * @func 0x135454 0x1354c0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetEmitterVelocity(int)
 * 字段偏移 top8: 0x50×1 / 0xc×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135454 ldr r3, [pc, #0x50]
 *   @0x135458 push {r4, lr}
 *   @0x13545c ldr r3, [pc, r3]
 *   @0x135460 sub sp, sp, #16
 *   @0x135464 mov r4, r0
 *   @0x135468 ldrb r1, [r3]
 *   @0x13546c cmp r1, #0
 *   @0x135470 beq 0x13547c <_Z26F_AudioGetEmitterVelocityXR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x135474 add sp, sp, #16
 *   @0x135478 pop {r4, pc}
 *   @0x13547c str r1, [r0, #0xc]
 *   @0x135480 ldr r0, [sp, #0x18]
 *   @0x135484 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135488 mov r1, r0
 *   @0x13548c add r0, sp, #4
 *   @0x135490 bl 0x216f4c <_Z24Audio_GetEmitterVelocityi>
 *   @0x135494 vldr s15, [sp, #4]
 *   @0x135498 vcvt.f64.f32 d6, s15
 *   @0x13549c vmov r2, r3, d6
 *   @0x1354a0 stm r4, {r2, r3}
 *   @0x1354a4 add sp, sp, #16
 *   @0x1354a8 pop {r4, pc}
 *   @0x1354ac .word 0x002b9bf0
 *
 * ══ §170/321 F_AudioGetEmitterVelocityY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1354b0  size 92  23 条（0x1354b0..0x13550c）
 * @func 0x1354b0 0x13551c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetEmitterVelocity(int)
 * 字段偏移 top8: 0x50×1 / 0xc×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1354b0 ldr r3, [pc, #0x50]
 *   @0x1354b4 push {r4, lr}
 *   @0x1354b8 ldr r3, [pc, r3]
 *   @0x1354bc sub sp, sp, #16
 *   @0x1354c0 mov r4, r0
 *   @0x1354c4 ldrb r1, [r3]
 *   @0x1354c8 cmp r1, #0
 *   @0x1354cc beq 0x1354d8 <_Z26F_AudioGetEmitterVelocityYR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1354d0 add sp, sp, #16
 *   @0x1354d4 pop {r4, pc}
 *   @0x1354d8 str r1, [r0, #0xc]
 *   @0x1354dc ldr r0, [sp, #0x18]
 *   @0x1354e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1354e4 mov r1, r0
 *   @0x1354e8 add r0, sp, #4
 *   @0x1354ec bl 0x216f4c <_Z24Audio_GetEmitterVelocityi>
 *   @0x1354f0 vldr s15, [sp, #8]
 *   @0x1354f4 vcvt.f64.f32 d6, s15
 *   @0x1354f8 vmov r2, r3, d6
 *   @0x1354fc stm r4, {r2, r3}
 *   @0x135500 add sp, sp, #16
 *   @0x135504 pop {r4, pc}
 *   @0x135508 mlaeq r11, r4, r11, r9
 *
 * ══ §171/321 F_AudioGetEmitterVelocityZ(RValue&, CInstance*, CInstance*, int, RValue*)  0x13550c  size 92  23 条（0x13550c..0x135568）
 * @func 0x13550c 0x135568  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetEmitterVelocity(int)
 * 字段偏移 top8: 0x50×1 / 0xc×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13550c ldr r3, [pc, #0x50]
 *   @0x135510 push {r4, lr}
 *   @0x135514 ldr r3, [pc, r3]
 *   @0x135518 sub sp, sp, #16
 *   @0x13551c mov r4, r0
 *   @0x135520 ldrb r1, [r3]
 *   @0x135524 cmp r1, #0
 *   @0x135528 beq 0x135534 <_Z26F_AudioGetEmitterVelocityZR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x13552c add sp, sp, #16
 *   @0x135530 pop {r4, pc}
 *   @0x135534 str r1, [r0, #0xc]
 *   @0x135538 ldr r0, [sp, #0x18]
 *   @0x13553c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135540 mov r1, r0
 *   @0x135544 add r0, sp, #4
 *   @0x135548 bl 0x216f4c <_Z24Audio_GetEmitterVelocityi>
 *   @0x13554c vldr s15, [sp, #12]
 *   @0x135550 vcvt.f64.f32 d6, s15
 *   @0x135554 vmov r2, r3, d6
 *   @0x135558 stm r4, {r2, r3}
 *   @0x13555c add sp, sp, #16
 *   @0x135560 pop {r4, pc}
 *   @0x135564 eoreq r9, r11, r8, lsr r11
 *
 * ══ §172/321 F_Audio_GroupSetGain(RValue&, CInstance*, CInstance*, int, RValue*)  0x135954  size 92  23 条（0x135954..0x1359b0）
 * @func 0x135954 0x1359b0  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x50×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135954 ldr r3, [pc, #0x50]
 *   @0x135958 push {r4, r5, r6, lr}
 *   @0x13595c ldr r3, [pc, r3]
 *   @0x135960 ldr r4, [sp, #0x10]
 *   @0x135964 ldrb r1, [r3]
 *   @0x135968 cmp r1, #0
 *   @0x13596c popne {r4, r5, r6, pc}
 *   @0x135970 mov r0, r4
 *   @0x135974 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135978 mov r1, #1
 *   @0x13597c mov r6, r0
 *   @0x135980 mov r0, r4
 *   @0x135984 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x135988 mov r1, #2
 *   @0x13598c mov r5, r0
 *   @0x135990 mov r0, r4
 *   @0x135994 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135998 mov r1, r5
 *   @0x13599c mov r2, r0
 *   @0x1359a0 mov r0, r6
 *   @0x1359a4 pop {r4, r5, r6, lr}
 *   @0x1359a8 b 0x218b84 <_Z18Audio_SetGainGroupifi>
 *   @0x1359ac .word 0x002b96f0
 *
 * ══ §173/321 findfirstnonspace(char const*, int, int)  0x13c350  size 92  23 条（0x13c350..0x13c3ac）
 * @func 0x13c350 0x13c3ac  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: findfirstnonspace(char const*, int, int)+0x50
 * 字段偏移 top8: 0x1×2 / 0x-4×1 / 0x44×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c350 cmp r2, #0
 *   @0x13c354 str r4, [sp, #-0x4]!
 *   @0x13c358 ble 0x13c3a0 <_Z17findfirstnonspacePKcii+0x50>
 *   @0x13c35c ldr r3, [pc, #0x44]
 *   @0x13c360 ldrb r4, [r0]
 *   @0x13c364 ldr r3, [pc, r3]
 *   @0x13c368 ldr r12, [r3]
 *   @0x13c36c add r3, r12, r4
 *   @0x13c370 ldrb r3, [r3, #0x1]
 *   @0x13c374 tst r3, #8
 *   @0x13c378 bne 0x13c394 <_Z17findfirstnonspacePKcii+0x44>
 *   @0x13c37c b 0x13c3a0 <_Z17findfirstnonspacePKcii+0x50>
 *   @0x13c380 ldrb r3, [r0]
 *   @0x13c384 add r3, r12, r3
 *   @0x13c388 ldrb r3, [r3, #0x1]
 *   @0x13c38c tst r3, #8
 *   @0x13c390 beq 0x13c3a0 <_Z17findfirstnonspacePKcii+0x50>
 *   @0x13c394 subs r2, r2, #1
 *   @0x13c398 add r0, r0, r1
 *   @0x13c39c bne 0x13c380 <_Z17findfirstnonspacePKcii+0x30>
 *   @0x13c3a0 ldr r4, [sp], #4
 *   @0x13c3a4 bx lr
 *   @0x13c3a8 eoreq r1, r11, r12, lsl r6
 *
 * ══ §174/321 YYGML_action_end_sound(int)  0x141bb8  size 92  23 条（0x141bb8..0x141c14）
 * @func 0x141bb8 0x141c14  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Data(int) / CSound::GetSoundId()
 * 字段偏移 top8: 0xc×2 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141bb8 ldr r3, [pc, #0x4c]
 *   @0x141bbc push {r4, lr}
 *   @0x141bc0 ldr r3, [pc, r3]
 *   @0x141bc4 ldrb r3, [r3]
 *   @0x141bc8 cmp r3, #0
 *   @0x141bcc bne 0x141bf4 <_Z22YYGML_action_end_soundi+0x3c>
 *   @0x141bd0 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x141bd4 subs r1, r0, #0
 *   @0x141bd8 beq 0x141bfc <_Z22YYGML_action_end_soundi+0x44>
 *   @0x141bdc ldr r4, [r1, #0xc]
 *   @0x141be0 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x141be4 mov r1, r0
 *   @0x141be8 mov r0, r4
 *   @0x141bec pop {r4, lr}
 *   @0x141bf0 b 0x21ecf4 <_Z8SND_StopPKci>
 *   @0x141bf4 pop {r4, lr}
 *   @0x141bf8 b 0x21a210 <_Z15Audio_StopSoundi>
 *   @0x141bfc ldr r0, [pc, #0xc]
 *   @0x141c00 pop {r4, lr}
 *   @0x141c04 add r0, pc, r0
 *   @0x141c08 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x141c0c eoreq sp, r10, r0, ror r1
 *   @0x141c10 andseq lr, pc, r12, ror lr
 *
 * ══ §175/321 F_D3DTransformSetRotationAxis(RValue&, CInstance*, CInstance*, int, RValue*)  0x144f2c  size 92  23 条（0x144f2c..0x144f88）
 * @func 0x144f2c 0x144f88  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144f2c push {r4, r5, r6, r7, r8, lr}
 *   @0x144f30 mov r1, #0
 *   @0x144f34 ldr r4, [sp, #0x18]
 *   @0x144f38 mov r0, r4
 *   @0x144f3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144f40 mov r1, #1
 *   @0x144f44 mov r7, r0
 *   @0x144f48 mov r0, r4
 *   @0x144f4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144f50 mov r1, #2
 *   @0x144f54 mov r6, r0
 *   @0x144f58 mov r0, r4
 *   @0x144f5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144f60 mov r1, #3
 *   @0x144f64 mov r5, r0
 *   @0x144f68 mov r0, r4
 *   @0x144f6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144f70 mov r1, r6
 *   @0x144f74 mov r2, r5
 *   @0x144f78 mov r3, r0
 *   @0x144f7c mov r0, r7
 *   @0x144f80 pop {r4, r5, r6, r7, r8, lr}
 *   @0x144f84 b 0x163858 <_Z33GR_3D_Transform_Set_Rotation_Axisffff>
 *
 * ══ §176/321 F_D3DTransformAddRotationAxis(RValue&, CInstance*, CInstance*, int, RValue*)  0x145060  size 92  23 条（0x145060..0x1450bc）
 * @func 0x145060 0x1450bc  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145060 push {r4, r5, r6, r7, r8, lr}
 *   @0x145064 mov r1, #0
 *   @0x145068 ldr r4, [sp, #0x18]
 *   @0x14506c mov r0, r4
 *   @0x145070 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145074 mov r1, #1
 *   @0x145078 mov r7, r0
 *   @0x14507c mov r0, r4
 *   @0x145080 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145084 mov r1, #2
 *   @0x145088 mov r6, r0
 *   @0x14508c mov r0, r4
 *   @0x145090 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145094 mov r1, #3
 *   @0x145098 mov r5, r0
 *   @0x14509c mov r0, r4
 *   @0x1450a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1450a4 mov r1, r6
 *   @0x1450a8 mov r2, r5
 *   @0x1450ac mov r3, r0
 *   @0x1450b0 mov r0, r7
 *   @0x1450b4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1450b8 b 0x163a9c <_Z33GR_3D_Transform_Add_Rotation_Axisffff>
 *
 * ══ §177/321 F_D3DModelVertex(RValue&, CInstance*, CInstance*, int, RValue*)  0x1454fc  size 92  23 条（0x1454fc..0x145558）
 * @func 0x1454fc 0x145558  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1454fc push {r4, r5, r6, r7, r8, lr}
 *   @0x145500 mov r1, #0
 *   @0x145504 ldr r4, [sp, #0x18]
 *   @0x145508 mov r0, r4
 *   @0x14550c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145510 mov r1, #1
 *   @0x145514 mov r7, r0
 *   @0x145518 mov r0, r4
 *   @0x14551c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145520 mov r1, #2
 *   @0x145524 mov r6, r0
 *   @0x145528 mov r0, r4
 *   @0x14552c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145530 mov r1, #3
 *   @0x145534 mov r5, r0
 *   @0x145538 mov r0, r4
 *   @0x14553c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145540 mov r1, r6
 *   @0x145544 mov r2, r5
 *   @0x145548 mov r3, r0
 *   @0x14554c mov r0, r7
 *   @0x145550 pop {r4, r5, r6, r7, r8, lr}
 *   @0x145554 b 0x165444 <_Z13GR_3DM_Vertexifff>
 *
 * ══ §178/321 F_GPUSetZTestEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x1465f0  size 92  23 条（0x1465f0..0x14664c）
 * @func 0x1465f0 0x14665c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1465f0 cmp r3, #1
 *   @0x1465f4 mov r2, #0
 *   @0x1465f8 push {r4, lr}
 *   @0x1465fc mov r1, r2
 *   @0x146600 mov r4, r3
 *   @0x146604 movt r2, #0xbff0
 *   @0x146608 str r1, [r0, #0xc]
 *   @0x14660c stm r0, {r1, r2}
 *   @0x146610 ldr r0, [sp, #0x8]
 *   @0x146614 beq 0x146628 <_Z19F_GPUSetZTestEnableR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x146618 ldr r0, [pc, #0x24]
 *   @0x14661c pop {r4, lr}
 *   @0x146620 add r0, pc, r0
 *   @0x146624 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146628 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14662c ldr r3, [pc, #0x14]
 *   @0x146630 mov r1, r4
 *   @0x146634 pop {r4, lr}
 *   @0x146638 mov r2, r0
 *   @0x14663c ldr r0, [pc, r3]
 *   @0x146640 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146644 ldrheq r11, [pc], -r12
 *   @0x146648 .word 0x002a76bc
 *
 * ══ §179/321 F_D3DBuildFrustum(RValue&, CInstance*, CInstance*, int, RValue*)  0x149cc4  size 92  23 条（0x149cc4..0x149d20）
 * @func 0x149cc4 0x149d20  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GetMatrix(eMatrix, float*)×2 / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / BuildFrustum(yyMatrix*)
 * 字段偏移 top8: 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149cc4 push {r4, r5, r6, lr}
 *   @0x149cc8 sub sp, sp, #192
 *   @0x149ccc add r5, sp, #64
 *   @0x149cd0 mov r4, r0
 *   @0x149cd4 mov r1, sp
 *   @0x149cd8 mov r0, #0
 *   @0x149cdc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x149ce0 mov r1, r5
 *   @0x149ce4 mov r0, #1
 *   @0x149ce8 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x149cec mov r2, r5
 *   @0x149cf0 add r5, sp, #128
 *   @0x149cf4 mov r1, sp
 *   @0x149cf8 mov r0, r5
 *   @0x149cfc bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x149d00 mov r0, r5
 *   @0x149d04 bl 0x149b40 <_Z12BuildFrustumP8yyMatrix>
 *   @0x149d08 mov r3, #0
 *   @0x149d0c str r3, [r4]
 *   @0x149d10 str r3, [r4, #0x4]
 *   @0x149d14 str r3, [r4, #0xc]
 *   @0x149d18 add sp, sp, #192
 *   @0x149d1c pop {r4, r5, r6, pc}
 *
 * ══ §180/321 F_PhysicsDebugRender(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d0ec  size 92  23 条（0x14d0ec..0x14d148）
 * @func 0x14d0ec 0x14d158  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×1 / 0xb4×1 / 0x84×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d0ec ldr r3, [pc, #0x4c]
 *   @0x14d0f0 ldr r3, [pc, r3]
 *   @0x14d0f4 ldr r3, [r3]
 *   @0x14d0f8 cmp r3, #0
 *   @0x14d0fc beq 0x14d12c <_Z20F_PhysicsDebugRenderR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14d100 ldr r3, [r3, #0xb4]
 *   @0x14d104 cmp r3, #0
 *   @0x14d108 beq 0x14d12c <_Z20F_PhysicsDebugRenderR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14d10c ldr r0, [r1, #0x84]
 *   @0x14d110 cmp r0, #0
 *   @0x14d114 beq 0x14d13c <_Z20F_PhysicsDebugRenderR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x14d118 vmov.f32 s14, #1.000000e+00
 *   @0x14d11c vldr s15, [r3, #96]
 *   @0x14d120 vdiv.f32 s15, s14, s15
 *   @0x14d124 vmov r1, s15
 *   @0x14d128 b 0x2376dc <_ZN14CPhysicsObject11DebugRenderEf>
 *   @0x14d12c ldr r0, [pc, #0x10]
 *   @0x14d130 mov r1, #0
 *   @0x14d134 add r0, pc, r0
 *   @0x14d138 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d13c bx lr
 *   @0x14d140 eoreq r0, r10, r8, lsr r8
 *   @0x14d144 ldrsheq r6, [pc], -r0
 *
 * ══ §181/321 F_PhysicsDestroyParticle(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d358  size 92  23 条（0x14d358..0x14d3b4）
 * @func 0x14d358 0x14d3b4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4c×1 / 0x8×1 / 0xb4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d358 ldr r3, [pc, #0x4c]
 *   @0x14d35c push {r4, lr}
 *   @0x14d360 ldr r3, [pc, r3]
 *   @0x14d364 ldr r0, [sp, #0x8]
 *   @0x14d368 ldr r3, [r3]
 *   @0x14d36c cmp r3, #0
 *   @0x14d370 beq 0x14d398 <_Z24F_PhysicsDestroyParticleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14d374 ldr r4, [r3, #0xb4]
 *   @0x14d378 cmp r4, #0
 *   @0x14d37c beq 0x14d398 <_Z24F_PhysicsDestroyParticleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14d380 mov r1, #0
 *   @0x14d384 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d388 mov r1, r0
 *   @0x14d38c mov r0, r4
 *   @0x14d390 pop {r4, lr}
 *   @0x14d394 b 0x23999c <_ZN13CPhysicsWorld14DeleteParticleEi>
 *   @0x14d398 ldr r0, [pc, #0x10]
 *   @0x14d39c mov r1, #0
 *   @0x14d3a0 pop {r4, lr}
 *   @0x14d3a4 add r0, pc, r0
 *   @0x14d3a8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d3ac eoreq r0, r10, r8, asr #11
 *   @0x14d3b0 andseq r6, pc, r12, asr #24
 *
 * ══ §182/321 F_PhysicsParticleGroupSetCircle(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d99c  size 92  23 条（0x14d99c..0x14d9f8）
 * @func 0x14d99c 0x14d9f8  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x4c×1 / 0x8×1 / 0xb4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d99c ldr r3, [pc, #0x4c]
 *   @0x14d9a0 push {r4, lr}
 *   @0x14d9a4 ldr r3, [pc, r3]
 *   @0x14d9a8 ldr r0, [sp, #0x8]
 *   @0x14d9ac ldr r3, [r3]
 *   @0x14d9b0 cmp r3, #0
 *   @0x14d9b4 beq 0x14d9dc <_Z31F_PhysicsParticleGroupSetCircleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14d9b8 ldr r4, [r3, #0xb4]
 *   @0x14d9bc cmp r4, #0
 *   @0x14d9c0 beq 0x14d9dc <_Z31F_PhysicsParticleGroupSetCircleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14d9c4 mov r1, #0
 *   @0x14d9c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d9cc mov r1, r0
 *   @0x14d9d0 mov r0, r4
 *   @0x14d9d4 pop {r4, lr}
 *   @0x14d9d8 b 0x239a6c <_ZN13CPhysicsWorld19ParticleGroupCircleEf>
 *   @0x14d9dc ldr r0, [pc, #0x10]
 *   @0x14d9e0 mov r1, #0
 *   @0x14d9e4 pop {r4, lr}
 *   @0x14d9e8 add r0, pc, r0
 *   @0x14d9ec b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d9f0 eoreq pc, r9, r4, lsl #31
 *   @0x14d9f4 mulseq pc, r0, r8
 *
 * ══ §183/321 F_PhysicsDeleteParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x14dc0c  size 92  23 条（0x14dc0c..0x14dc68）
 * @func 0x14dc0c 0x14dc68  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4c×1 / 0x8×1 / 0xb4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14dc0c ldr r3, [pc, #0x4c]
 *   @0x14dc10 push {r4, lr}
 *   @0x14dc14 ldr r3, [pc, r3]
 *   @0x14dc18 ldr r0, [sp, #0x8]
 *   @0x14dc1c ldr r3, [r3]
 *   @0x14dc20 cmp r3, #0
 *   @0x14dc24 beq 0x14dc4c <_Z28F_PhysicsDeleteParticleGroupR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14dc28 ldr r4, [r3, #0xb4]
 *   @0x14dc2c cmp r4, #0
 *   @0x14dc30 beq 0x14dc4c <_Z28F_PhysicsDeleteParticleGroupR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14dc34 mov r1, #0
 *   @0x14dc38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dc3c mov r1, r0
 *   @0x14dc40 mov r0, r4
 *   @0x14dc44 pop {r4, lr}
 *   @0x14dc48 b 0x239e34 <_ZN13CPhysicsWorld19DeleteParticleGroupEi>
 *   @0x14dc4c ldr r0, [pc, #0x10]
 *   @0x14dc50 mov r1, #0
 *   @0x14dc54 pop {r4, lr}
 *   @0x14dc58 add r0, pc, r0
 *   @0x14dc5c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14dc60 eoreq pc, r9, r4, lsl sp
 *   @0x14dc64 andseq r6, pc, r0, ror #10
 *
 * ══ §184/321 F_PhysicsParticleSetMaxCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e998  size 92  23 条（0x14e998..0x14e9f4）
 * @func 0x14e998 0x14e9f4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x4c×1 / 0x8×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e998 ldr r3, [pc, #0x4c]
 *   @0x14e99c push {r4, lr}
 *   @0x14e9a0 ldr r3, [pc, r3]
 *   @0x14e9a4 ldr r0, [sp, #0x8]
 *   @0x14e9a8 ldr r3, [r3]
 *   @0x14e9ac cmp r3, #0
 *   @0x14e9b0 beq 0x14e9d8 <_Z28F_PhysicsParticleSetMaxCountR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14e9b4 ldr r4, [r3, #0xb4]
 *   @0x14e9b8 cmp r4, #0
 *   @0x14e9bc beq 0x14e9d8 <_Z28F_PhysicsParticleSetMaxCountR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14e9c0 mov r1, #0
 *   @0x14e9c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e9c8 mov r1, r0
 *   @0x14e9cc ldr r0, [r4, #0x10]
 *   @0x14e9d0 pop {r4, lr}
 *   @0x14e9d4 b 0x2cb438 <_ZN7b2World19SetParticleMaxCountEi>
 *   @0x14e9d8 ldr r0, [pc, #0x10]
 *   @0x14e9dc mov r1, #0
 *   @0x14e9e0 pop {r4, lr}
 *   @0x14e9e4 add r0, pc, r0
 *   @0x14e9e8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e9ec eoreq lr, r9, r8, lsl #31
 *   @0x14e9f0 andseq r6, pc, r12, lsr r2
 *
 * ══ §185/321 F_PhysicsParticleSetDensity(RValue&, CInstance*, CInstance*, int, RValue*)  0x14ea5c  size 92  23 条（0x14ea5c..0x14eab8）
 * @func 0x14ea5c 0x14eac8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x4c×1 / 0x8×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14ea5c ldr r3, [pc, #0x4c]
 *   @0x14ea60 push {r4, lr}
 *   @0x14ea64 ldr r3, [pc, r3]
 *   @0x14ea68 ldr r0, [sp, #0x8]
 *   @0x14ea6c ldr r3, [r3]
 *   @0x14ea70 cmp r3, #0
 *   @0x14ea74 beq 0x14ea9c <_Z27F_PhysicsParticleSetDensityR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14ea78 ldr r4, [r3, #0xb4]
 *   @0x14ea7c cmp r4, #0
 *   @0x14ea80 beq 0x14ea9c <_Z27F_PhysicsParticleSetDensityR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14ea84 mov r1, #0
 *   @0x14ea88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14ea8c mov r1, r0
 *   @0x14ea90 ldr r0, [r4, #0x10]
 *   @0x14ea94 pop {r4, lr}
 *   @0x14ea98 b 0x2cb444 <_ZN7b2World18SetParticleDensityEf>
 *   @0x14ea9c ldr r0, [pc, #0x10]
 *   @0x14eaa0 mov r1, #0
 *   @0x14eaa4 pop {r4, lr}
 *   @0x14eaa8 add r0, pc, r0
 *   @0x14eaac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14eab0 eoreq lr, r9, r4, asr #29
 *   @0x14eab4 ldrsbeq r6, [pc], -r8
 *
 * ══ §186/321 F_PhysicsParticleSetDamping(RValue&, CInstance*, CInstance*, int, RValue*)  0x14eab8  size 92  23 条（0x14eab8..0x14eb14）
 * @func 0x14eab8 0x14eb24  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x4c×1 / 0x8×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14eab8 ldr r3, [pc, #0x4c]
 *   @0x14eabc push {r4, lr}
 *   @0x14eac0 ldr r3, [pc, r3]
 *   @0x14eac4 ldr r0, [sp, #0x8]
 *   @0x14eac8 ldr r3, [r3]
 *   @0x14eacc cmp r3, #0
 *   @0x14ead0 beq 0x14eaf8 <_Z27F_PhysicsParticleSetDampingR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14ead4 ldr r4, [r3, #0xb4]
 *   @0x14ead8 cmp r4, #0
 *   @0x14eadc beq 0x14eaf8 <_Z27F_PhysicsParticleSetDampingR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14eae0 mov r1, #0
 *   @0x14eae4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14eae8 mov r1, r0
 *   @0x14eaec ldr r0, [r4, #0x10]
 *   @0x14eaf0 pop {r4, lr}
 *   @0x14eaf4 b 0x2cb474 <_ZN7b2World18SetParticleDampingEf>
 *   @0x14eaf8 ldr r0, [pc, #0x10]
 *   @0x14eafc mov r1, #0
 *   @0x14eb00 pop {r4, lr}
 *   @0x14eb04 add r0, pc, r0
 *   @0x14eb08 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14eb0c eoreq lr, r9, r8, ror #28
 *   @0x14eb10 ldrsbeq r6, [pc], -r8
 *
 * ══ §187/321 F_PhysicsParticleSetGravityScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x14eb14  size 92  23 条（0x14eb14..0x14eb70）
 * @func 0x14eb14 0x14eb70  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x4c×1 / 0x8×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14eb14 ldr r3, [pc, #0x4c]
 *   @0x14eb18 push {r4, lr}
 *   @0x14eb1c ldr r3, [pc, r3]
 *   @0x14eb20 ldr r0, [sp, #0x8]
 *   @0x14eb24 ldr r3, [r3]
 *   @0x14eb28 cmp r3, #0
 *   @0x14eb2c beq 0x14eb54 <_Z32F_PhysicsParticleSetGravityScaleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14eb30 ldr r4, [r3, #0xb4]
 *   @0x14eb34 cmp r4, #0
 *   @0x14eb38 beq 0x14eb54 <_Z32F_PhysicsParticleSetGravityScaleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14eb3c mov r1, #0
 *   @0x14eb40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14eb44 mov r1, r0
 *   @0x14eb48 ldr r0, [r4, #0x10]
 *   @0x14eb4c pop {r4, lr}
 *   @0x14eb50 b 0x2cb45c <_ZN7b2World23SetParticleGravityScaleEf>
 *   @0x14eb54 ldr r0, [pc, #0x10]
 *   @0x14eb58 mov r1, #0
 *   @0x14eb5c pop {r4, lr}
 *   @0x14eb60 add r0, pc, r0
 *   @0x14eb64 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14eb68 eoreq lr, r9, r12, lsl #28
 *   @0x14eb6c ldrsbeq r6, [pc], -r12
 *
 * ══ §188/321 F_YoYo_LeaveRating(RValue&, CInstance*, CInstance*, int, RValue*)  0x156ea0  size 92  23 条（0x156ea0..0x156efc）
 * @func 0x156ea0 0x156efc  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×4
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156ea0 push {r4, r5, r6, r7, r8, lr}
 *   @0x156ea4 mov r1, #0
 *   @0x156ea8 ldr r4, [sp, #0x18]
 *   @0x156eac mov r0, r4
 *   @0x156eb0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156eb4 mov r1, #1
 *   @0x156eb8 mov r7, r0
 *   @0x156ebc mov r0, r4
 *   @0x156ec0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156ec4 mov r1, #2
 *   @0x156ec8 mov r6, r0
 *   @0x156ecc mov r0, r4
 *   @0x156ed0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156ed4 mov r1, #3
 *   @0x156ed8 mov r5, r0
 *   @0x156edc mov r0, r4
 *   @0x156ee0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156ee4 mov r1, r6
 *   @0x156ee8 mov r2, r5
 *   @0x156eec mov r3, r0
 *   @0x156ef0 mov r0, r7
 *   @0x156ef4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x156ef8 b 0x15e538 <_Z11LeaveRatingPcPKcS1_S1_>
 *
 * ══ §189/321 FacebookInitM()  0x15e7ec  size 92  23 条（0x15e7ec..0x15e848）
 * @func 0x15e7ec 0x15e858  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x40×1 / 0x29c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e7ec push {r4, lr}
 *   @0x15e7f0 bl 0x290274 <getJNIEnv>
 *   @0x15e7f4 ldr r3, [pc, #0x40]
 *   @0x15e7f8 ldr r3, [pc, r3]
 *   @0x15e7fc ldr r1, [r3]
 *   @0x15e800 ldr r3, [r0]
 *   @0x15e804 ldr r3, [r3, #0x29c]
 *   @0x15e808 blx r3
 *   @0x15e80c mov r4, r0
 *   @0x15e810 bl 0x290274 <getJNIEnv>
 *   @0x15e814 ldr r1, [pc, #0x24]
 *   @0x15e818 mov r3, r4
 *   @0x15e81c ldr r2, [pc, #0x20]
 *   @0x15e820 ldr r1, [pc, r1]
 *   @0x15e824 ldr r2, [pc, r2]
 *   @0x15e828 ldr r1, [r1]
 *   @0x15e82c ldr r2, [r2]
 *   @0x15e830 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e834 mov r0, #1
 *   @0x15e838 pop {r4, pc}
 *   @0x15e83c .word 0x002916b0
 *   @0x15e840 eoreq pc, r8, r4, lsl #3
 *   @0x15e844 eoreq r1, r9, r8, lsl #13
 *
 * ══ §190/321 GR_D3D_Set_Blend_Ext(int, int)  0x168304  size 92  23 条（0x168304..0x168360）
 * @func 0x168304 0x168360  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::SetRenderState(eRenderState, unsigned int)×3
 * 字段偏移 top8: 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168304 push {r4, r5, r6, lr}
 *   @0x168308 mov r2, r0
 *   @0x16830c ldr r4, [pc, #0x48]
 *   @0x168310 mov r5, r1
 *   @0x168314 mov r6, r0
 *   @0x168318 mov r1, #6
 *   @0x16831c ldr r4, [pc, r4]
 *   @0x168320 mov r0, r4
 *   @0x168324 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168328 mov r0, r4
 *   @0x16832c mov r2, r5
 *   @0x168330 mov r1, #7
 *   @0x168334 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168338 mov r0, r4
 *   @0x16833c mov r2, r6
 *   @0x168340 mov r1, #34
 *   @0x168344 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168348 mov r0, r4
 *   @0x16834c mov r2, r5
 *   @0x168350 mov r1, #35
 *   @0x168354 pop {r4, r5, r6, lr}
 *   @0x168358 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x16835c .word 0x002859dc
 *
 * ══ §191/321 GR_Draw_Circle(float, float, float, bool)  0x16b198  size 92  23 条（0x16b198..0x16b1f4）
 * @func 0x16b198 0x16b1f4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _Draw_Ellipse(float, float, float, float, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x4×2 / 0x4c×1 / 0x-4×1 / 0x8×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16b198 vmov s15, r2
 *   @0x16b19c ldr r12, [pc, #0x4c]
 *   @0x16b1a0 vmov s13, r0
 *   @0x16b1a4 vmov s14, r1
 *   @0x16b1a8 ldr r12, [pc, r12]
 *   @0x16b1ac vsub.f32 s12, s13, s15
 *   @0x16b1b0 ldr r2, [r12]
 *   @0x16b1b4 str lr, [sp, #-0x4]!
 *   @0x16b1b8 sub sp, sp, #20
 *   @0x16b1bc str r3, [sp, #0x8]
 *   @0x16b1c0 str r2, [sp]
 *   @0x16b1c4 str r2, [sp, #0x4]
 *   @0x16b1c8 vadd.f32 s13, s13, s15
 *   @0x16b1cc vmov r0, s12
 *   @0x16b1d0 vsub.f32 s12, s14, s15
 *   @0x16b1d4 vmov r2, s13
 *   @0x16b1d8 vadd.f32 s15, s14, s15
 *   @0x16b1dc vmov r1, s12
 *   @0x16b1e0 vmov r3, s15
 *   @0x16b1e4 bl 0x16af3c <_Z13_Draw_Ellipseffffjjb>
 *   @0x16b1e8 add sp, sp, #20
 *   @0x16b1ec ldr pc, [sp], #4
 *   @0x16b1f0 eoreq r2, r8, r4, asr r11
 *
 * ══ §192/321 CCameraManager::Clean()  0x16dd34  size 92  23 条（0x16dd34..0x16dd90）
 * @func 0x16dd34 0x16dd90  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::Clean()+0x40 / CCamera::~CCamera() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x14×3 / 0xc×2 / 0x2×2 / 0x4×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16dd34 push {r3, r4, r5, lr}
 *   @0x16dd38 mov r5, r0
 *   @0x16dd3c ldr r3, [r0, #0x14]
 *   @0x16dd40 cmp r3, #0
 *   @0x16dd44 movgt r4, #0
 *   @0x16dd48 ble 0x16dd74 <_ZN14CCameraManager5CleanEv+0x40>
 *   @0x16dd4c ldr r3, [r5, #0xc]
 *   @0x16dd50 ldr r0, [r3, r4, lsl #2]
 *   @0x16dd54 bl 0x16d120 <_ZN7CCameraD2Ev>
 *   @0x16dd58 ldr r3, [r5, #0xc]
 *   @0x16dd5c ldr r0, [r3, r4, lsl #2]
 *   @0x16dd60 add r4, r4, #1
 *   @0x16dd64 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x16dd68 ldr r3, [r5, #0x14]
 *   @0x16dd6c cmp r3, r4
 *   @0x16dd70 bgt 0x16dd4c <_ZN14CCameraManager5CleanEv+0x18>
 *   @0x16dd74 mov r3, #0
 *   @0x16dd78 str r3, [r5]
 *   @0x16dd7c str r3, [r5, #0x4]
 *   @0x16dd80 str r3, [r5, #0x8]
 *   @0x16dd84 str r3, [r5, #0x14]
 *   @0x16dd88 str r3, [r5, #0x18]
 *   @0x16dd8c pop {r3, r4, r5, pc}
 *
 * ══ §193/321 GR_3D_Set_Ambient(unsigned int)  0x17f5fc  size 92  23 条（0x17f5fc..0x17f658）
 * @func 0x17f5fc 0x17f658  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0xc×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f5fc ubfx r3, r0, #0x8, #0x8
 *   @0x17f600 vldr s15, [pc, #72]
 *   @0x17f604 mov r2, #1065353216
 *   @0x17f608 vmov s14, r3
 *   @0x17f60c uxtb r3, r0
 *   @0x17f610 ubfx r0, r0, #0x10, #0x8
 *   @0x17f614 vmov s12, r3
 *   @0x17f618 ldr r3, [pc, #0x34]
 *   @0x17f61c vmov s11, r0
 *   @0x17f620 vcvt.f32.s32 s14, s14
 *   @0x17f624 ldr r3, [pc, r3]
 *   @0x17f628 str r2, [r3, #0xc]
 *   @0x17f62c vcvt.f32.s32 s12, s12
 *   @0x17f630 vcvt.f32.s32 s13, s11
 *   @0x17f634 vdiv.f32 s12, s12, s15
 *   @0x17f638 vdiv.f32 s14, s14, s15
 *   @0x17f63c vstr s12, [r3]
 *   @0x17f640 vdiv.f32 s15, s13, s15
 *   @0x17f644 vstr s14, [r3, #4]
 *   @0x17f648 vstr s15, [r3, #8]
 *   @0x17f64c b 0x17f47c <_Z23GR_3D_Light_Set_Ambientv>
 *   @0x17f650 cmnmi pc, #0
 *   @0x17f654 eoreq r0, r7, r0, ror lr
 *
 * ══ §194/321 CIAPProduct::GetProductType(CIAPProduct const&)  0x18b10c  size 92  23 条（0x18b10c..0x18b168）
 * @func 0x18b10c 0x18b168  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66d0×2
 * 字段偏移 top8: 0x10×1 / 0x3c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b10c push {r4, lr}
 *   @0x18b110 ldr r4, [r0, #0x10]
 *   @0x18b114 cmp r4, #0
 *   @0x18b118 beq 0x18b158 <_ZN11CIAPProduct14GetProductTypeERKS_+0x4c>
 *   @0x18b11c ldr r1, [pc, #0x3c]
 *   @0x18b120 mov r0, r4
 *   @0x18b124 add r1, pc, r1
 *   @0x18b128 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18b12c cmp r0, #0
 *   @0x18b130 bne 0x18b13c <_ZN11CIAPProduct14GetProductTypeERKS_+0x30>
 *   @0x18b134 mov r0, #2
 *   @0x18b138 pop {r4, pc}
 *   @0x18b13c ldr r1, [pc, #0x20]
 *   @0x18b140 mov r0, r4
 *   @0x18b144 add r1, pc, r1
 *   @0x18b148 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18b14c adds r0, r0, #0
 *   @0x18b150 movne r0, #1
 *   @0x18b154 pop {r4, pc}
 *   @0x18b158 mov r0, #1
 *   @0x18b15c pop {r4, pc}
 *   @0x18b160 ldrheq r1, [r12], -r0
 *   @0x18b164 andseq r1, r12, r0, lsr #1
 *
 * ══ §195/321 IO_Button_Clear(int, int)  0x18c1b0  size 92  23 条（0x18c1b0..0x18c20c）
 * @func 0x18c1b0 0x18c20c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x30×1 / 0x2c×1 / 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c1b0 sub r0, r0, #1
 *   @0x18c1b4 cmp r0, #2
 *   @0x18c1b8 str r4, [sp, #-0x4]!
 *   @0x18c1bc bhi 0x18c1f8 <_Z15IO_Button_Clearii+0x48>
 *   @0x18c1c0 cmp r1, #9
 *   @0x18c1c4 bhi 0x18c1f8 <_Z15IO_Button_Clearii+0x48>
 *   @0x18c1c8 ldr r4, [pc, #0x30]
 *   @0x18c1cc add r1, r1, r1, lsl #1
 *   @0x18c1d0 ldr r12, [pc, #0x2c]
 *   @0x18c1d4 add r0, r1, r0
 *   @0x18c1d8 ldr r3, [pc, #0x28]
 *   @0x18c1dc ldr r4, [pc, r4]
 *   @0x18c1e0 ldr r12, [pc, r12]
 *   @0x18c1e4 mov r2, #0
 *   @0x18c1e8 ldr r3, [pc, r3]
 *   @0x18c1ec strb r2, [r4, r0]
 *   @0x18c1f0 strb r2, [r12, r0]
 *   @0x18c1f4 strb r2, [r3, r0]
 *   @0x18c1f8 ldr r4, [sp], #4
 *   @0x18c1fc bx lr
 *   @0x18c200 eoreq r4, r6, r8, lsl r4
 *   @0x18c204 eoreq r4, r6, r12, lsl r4
 *   @0x18c208 eoreq r4, r6, r0, lsl r4
 *
 * ══ §196/321 LoadSave::fgetc(_YYFILE*)  0x18df2c  size 92  23 条（0x18df2c..0x18df88）
 * @func 0x18df2c 0x18df88  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::yyfeof(_YYFILE*) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18df2c push {r3, r4, r5, lr}
 *   @0x18df30 mov r4, r0
 *   @0x18df34 bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE>
 *   @0x18df38 mov r1, #1
 *   @0x18df3c subs r5, r0, #0
 *   @0x18df40 ldr r0, [r4]
 *   @0x18df44 beq 0x18df60 <_ZN8LoadSave5fgetcEP7_YYFILE+0x34>
 *   @0x18df48 ldr r3, [r0]
 *   @0x18df4c mov r2, r1
 *   @0x18df50 ldr r3, [r3, #0x10]
 *   @0x18df54 blx r3
 *   @0x18df58 mov r0, #255
 *   @0x18df5c pop {r3, r4, r5, pc}
 *   @0x18df60 ldr r12, [r0]
 *   @0x18df64 add r4, r0, #44
 *   @0x18df68 mov r2, r4
 *   @0x18df6c ldr r3, [r12, #0xc]
 *   @0x18df70 blx r3
 *   @0x18df74 mov r0, r4
 *   @0x18df78 mov r1, r5
 *   @0x18df7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18df80 uxtb r0, r0
 *   @0x18df84 pop {r3, r4, r5, pc}
 *
 * ══ §197/321 LoadSave::BundleFileExists(char const*)  0x18f8ac  size 92  23 条（0x18f8ac..0x18f908）
 * @func 0x18f8ac 0x18f918  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetBundleFileName(char*, int, char const*) / LoadSave::_FileExists(char*) / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f8ac push {r4, r5, lr}
 *   @0x18f8b0 sub sp, sp, #2048
 *   @0x18f8b4 ldr r4, [pc, #0x48]
 *   @0x18f8b8 sub sp, sp, #12
 *   @0x18f8bc add r5, sp, #4
 *   @0x18f8c0 mov r2, r0
 *   @0x18f8c4 ldr r4, [pc, r4]
 *   @0x18f8c8 mov r1, #2048
 *   @0x18f8cc mov r0, r5
 *   @0x18f8d0 ldr r3, [r4]
 *   @0x18f8d4 str r3, [sp, #0x804]
 *   @0x18f8d8 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x18f8dc mov r0, r5
 *   @0x18f8e0 bl 0x18f6c0 <_ZN8LoadSave11_FileExistsEPc>
 *   @0x18f8e4 ldr r2, [sp, #0x804]
 *   @0x18f8e8 ldr r3, [r4]
 *   @0x18f8ec cmp r2, r3
 *   @0x18f8f0 bne 0x18f900 <_ZN8LoadSave16BundleFileExistsEPKc+0x54>
 *   @0x18f8f4 add sp, sp, #2048
 *   @0x18f8f8 add sp, sp, #12
 *   @0x18f8fc pop {r4, r5, pc}
 *   @0x18f900 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18f904 eoreq lr, r5, r12, lsl #1
 *
 * ══ §198/321 LoadSave::GetBundleFileSize(char const*)  0x18f908  size 92  23 条（0x18f908..0x18f964）
 * @func 0x18f908 0x18f964  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetBundleFileName(char*, int, char const*) / LoadSave::_FileExists(char*) / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f908 push {r4, r5, lr}
 *   @0x18f90c sub sp, sp, #2048
 *   @0x18f910 ldr r4, [pc, #0x48]
 *   @0x18f914 sub sp, sp, #12
 *   @0x18f918 add r5, sp, #4
 *   @0x18f91c mov r2, r0
 *   @0x18f920 ldr r4, [pc, r4]
 *   @0x18f924 mov r1, #2048
 *   @0x18f928 mov r0, r5
 *   @0x18f92c ldr r3, [r4]
 *   @0x18f930 str r3, [sp, #0x804]
 *   @0x18f934 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x18f938 mov r0, r5
 *   @0x18f93c bl 0x18f6c0 <_ZN8LoadSave11_FileExistsEPc>
 *   @0x18f940 ldr r2, [sp, #0x804]
 *   @0x18f944 ldr r3, [r4]
 *   @0x18f948 cmp r2, r3
 *   @0x18f94c bne 0x18f95c <_ZN8LoadSave17GetBundleFileSizeEPKc+0x54>
 *   @0x18f950 add sp, sp, #2048
 *   @0x18f954 add sp, sp, #12
 *   @0x18f958 pop {r4, r5, pc}
 *   @0x18f95c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18f960 eoreq lr, r5, r0, lsr r0
 *
 * ══ §199/321 LoadSave::GetSaveFileSize(char const*)  0x18fbe8  size 92  23 条（0x18fbe8..0x18fc44）
 * @func 0x18fbe8 0x18fc44  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*) / LoadSave::_GetSize(char const*) / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18fbe8 push {r4, r5, lr}
 *   @0x18fbec sub sp, sp, #2048
 *   @0x18fbf0 ldr r4, [pc, #0x48]
 *   @0x18fbf4 sub sp, sp, #12
 *   @0x18fbf8 add r5, sp, #4
 *   @0x18fbfc mov r2, r0
 *   @0x18fc00 ldr r4, [pc, r4]
 *   @0x18fc04 mov r1, #2048
 *   @0x18fc08 mov r0, r5
 *   @0x18fc0c ldr r3, [r4]
 *   @0x18fc10 str r3, [sp, #0x804]
 *   @0x18fc14 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x18fc18 mov r0, r5
 *   @0x18fc1c bl 0x18f734 <_ZN8LoadSave8_GetSizeEPKc>
 *   @0x18fc20 ldr r2, [sp, #0x804]
 *   @0x18fc24 ldr r3, [r4]
 *   @0x18fc28 cmp r2, r3
 *   @0x18fc2c bne 0x18fc3c <_ZN8LoadSave15GetSaveFileSizeEPKc+0x54>
 *   @0x18fc30 add sp, sp, #2048
 *   @0x18fc34 add sp, sp, #12
 *   @0x18fc38 pop {r4, r5, pc}
 *   @0x18fc3c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18fc40 eoreq sp, r5, r0, asr sp
 *
 * ══ §200/321 Motion_Grid_Destroy(int)  0x19a178  size 92  23 条（0x19a178..0x19a1d4）
 * @func 0x19a178 0x19a1d4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×2 / 0x40×1 / 0x30×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19a178 push {r3, r4, r5, lr}
 *   @0x19a17c subs r4, r0, #0
 *   @0x19a180 poplt {r3, r4, r5, pc}
 *   @0x19a184 ldr r3, [pc, #0x40]
 *   @0x19a188 ldr r3, [pc, r3]
 *   @0x19a18c ldr r3, [r3]
 *   @0x19a190 cmp r4, r3
 *   @0x19a194 popge {r3, r4, r5, pc}
 *   @0x19a198 ldr r5, [pc, #0x30]
 *   @0x19a19c ldr r5, [pc, r5]
 *   @0x19a1a0 ldr r3, [r5]
 *   @0x19a1a4 ldr r0, [r3, r4, lsl #2]
 *   @0x19a1a8 cmp r0, #0
 *   @0x19a1ac popeq {r3, r4, r5, pc}
 *   @0x19a1b0 ldr r3, [r0]
 *   @0x19a1b4 ldr r3, [r3, #0x4]
 *   @0x19a1b8 blx r3
 *   @0x19a1bc ldr r3, [r5]
 *   @0x19a1c0 mov r2, #0
 *   @0x19a1c4 str r2, [r3, r4, lsl #2]
 *   @0x19a1c8 pop {r3, r4, r5, pc}
 *   @0x19a1cc eoreq r6, r5, r4, lsr #10
 *   @0x19a1d0 eoreq r6, r5, r4, lsl r5
 *
 * ══ §201/321 RomDisk::MemoryInRomDisk(void*)  0x1a8790  size 92  23 条（0x1a8790..0x1a87ec）
 * @func 0x1a8790 0x1a87ec  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8790 ldr r3, [pc, #0x4c]
 *   @0x1a8794 asr r1, r0, #31
 *   @0x1a8798 ldr r12, [pc, #0x48]
 *   @0x1a879c ldr r3, [pc, r3]
 *   @0x1a87a0 ldr r12, [pc, r12]
 *   @0x1a87a4 ldr r2, [r3]
 *   @0x1a87a8 ldr r12, [r12]
 *   @0x1a87ac push {r4, r5}
 *   @0x1a87b0 asr r3, r2, #31
 *   @0x1a87b4 adds r4, r2, r12
 *   @0x1a87b8 adc r5, r3, #0
 *   @0x1a87bc cmp r1, r5
 *   @0x1a87c0 cmpeq r0, r4
 *   @0x1a87c4 pop {r4, r5}
 *   @0x1a87c8 movhs r12, #0
 *   @0x1a87cc movlo r12, #1
 *   @0x1a87d0 cmp r1, r3
 *   @0x1a87d4 cmpeq r0, r2
 *   @0x1a87d8 movlo r0, #0
 *   @0x1a87dc andhs r0, r12, #1
 *   @0x1a87e0 bx lr
 *   @0x1a87e4 eoreq r8, r4, r4, asr #32
 *   @0x1a87e8 eoreq r8, r4, r12, lsr r0
 *
 * ══ §202/321 F_TileSetEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b6358  size 92  23 条（0x1b6358..0x1b63b4）
 * @func 0x1b6358 0x1b63b4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6358 cmp r3, #1
 *   @0x1b635c mov r3, #0
 *   @0x1b6360 push {r4, lr}
 *   @0x1b6364 mov r1, r3
 *   @0x1b6368 mov r4, r0
 *   @0x1b636c movt r3, #0xbff0
 *   @0x1b6370 str r1, [r0, #0xc]
 *   @0x1b6374 stm r0, {r1, r3}
 *   @0x1b6378 ldr r0, [sp, #0x8]
 *   @0x1b637c beq 0x1b6390 <_Z14F_TileSetEmptyR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1b6380 ldr r0, [pc, #0x28]
 *   @0x1b6384 pop {r4, lr}
 *   @0x1b6388 add r0, pc, r0
 *   @0x1b638c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b6390 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6394 lsr r0, r0, #19
 *   @0x1b6398 lsl r2, r0, #19
 *   @0x1b639c vmov s15, r2
 *   @0x1b63a0 vcvt.f64.s32 d7, s15
 *   @0x1b63a4 vmov r2, r3, d7
 *   @0x1b63a8 stm r4, {r2, r3}
 *   @0x1b63ac pop {r4, pc}
 *   @0x1b63b0 andseq r7, r9, r8, lsl r0
 *
 * ══ §203/321 CLayerManager::GetElementFromName(CLayer*, char const*)  0x1c048c  size 92  23 条（0x1c048c..0x1c04e8）
 * @func 0x1c048c 0x1c04f8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66d0
 * 字段偏移 top8: 0x58×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c048c cmp r0, #0
 *   @0x1c0490 push {r3, r4, r5, lr}
 *   @0x1c0494 mov r5, r1
 *   @0x1c0498 popeq {r3, r4, r5, pc}
 *   @0x1c049c cmp r1, #0
 *   @0x1c04a0 beq 0x1c04e0 <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x54>
 *   @0x1c04a4 ldr r4, [r0, #0x58]
 *   @0x1c04a8 cmp r4, #0
 *   @0x1c04ac beq 0x1c04d8 <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x4c>
 *   @0x1c04b0 ldr r1, [r4, #0xc]
 *   @0x1c04b4 mov r0, r5
 *   @0x1c04b8 cmp r1, #0
 *   @0x1c04bc beq 0x1c04cc <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x40>
 *   @0x1c04c0 bl 0xb66d0 <strcasecmp@plt>
 *   @0x1c04c4 cmp r0, #0
 *   @0x1c04c8 beq 0x1c04d8 <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x4c>
 *   @0x1c04cc ldr r4, [r4, #0x14]
 *   @0x1c04d0 cmp r4, #0
 *   @0x1c04d4 bne 0x1c04b0 <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc+0x24>
 *   @0x1c04d8 mov r0, r4
 *   @0x1c04dc pop {r3, r4, r5, pc}
 *   @0x1c04e0 mov r0, r1
 *   @0x1c04e4 pop {r3, r4, r5, pc}
 *
 * ══ §204/321 CLayerManager::GetElementFromName(CRoom*, char const*, CLayer**)  0x1c04e8  size 92  23 条（0x1c04e8..0x1c0544）
 * @func 0x1c04e8 0x1c0544  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetElementFromName(CLayer*, char const*)
 * 字段偏移 top8: 0xd4×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c04e8 cmp r0, #0
 *   @0x1c04ec push {r4, r5, r6, lr}
 *   @0x1c04f0 mov r5, r1
 *   @0x1c04f4 mov r6, r2
 *   @0x1c04f8 beq 0x1c0530 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x48>
 *   @0x1c04fc cmp r1, #0
 *   @0x1c0500 beq 0x1c0530 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x48>
 *   @0x1c0504 ldr r4, [r0, #0xd4]
 *   @0x1c0508 cmp r4, #0
 *   @0x1c050c beq 0x1c0530 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x48>
 *   @0x1c0510 mov r0, r4
 *   @0x1c0514 mov r1, r5
 *   @0x1c0518 bl 0x1c048c <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc>
 *   @0x1c051c cmp r0, #0
 *   @0x1c0520 bne 0x1c0538 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x50>
 *   @0x1c0524 ldr r4, [r4, #0x68]
 *   @0x1c0528 cmp r4, #0
 *   @0x1c052c bne 0x1c0510 <_ZN13CLayerManager18GetElementFromNameEP5CRoomPKcPP6CLayer+0x28>
 *   @0x1c0530 mov r0, #0
 *   @0x1c0534 pop {r4, r5, r6, pc}
 *   @0x1c0538 cmp r6, #0
 *   @0x1c053c strne r4, [r6]
 *   @0x1c0540 pop {r4, r5, r6, pc}
 *
 * ══ §205/321 CVariableList::Init(int)  0x1f54f4  size 92  23 条（0x1f54f4..0x1f5550）
 * @func 0x1f54f4 0x1f5550  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CVariableList::Alloc(int)
 * 字段偏移 top8: 0x28×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f54f4 and r3, r1, #3
 *   @0x1f54f8 push {r4, lr}
 *   @0x1f54fc add r3, r0, r3, lsl #2
 *   @0x1f5500 mov r4, r0
 *   @0x1f5504 ldr r3, [r3, #0x4]
 *   @0x1f5508 cmp r3, #0
 *   @0x1f550c beq 0x1f5538 <_ZN13CVariableList4InitEi+0x44>
 *   @0x1f5510 ldr r2, [r3, #0x28]
 *   @0x1f5514 cmp r2, r1
 *   @0x1f5518 bne 0x1f552c <_ZN13CVariableList4InitEi+0x38>
 *   @0x1f551c pop {r4, pc}
 *   @0x1f5520 ldr r2, [r3, #0x28]
 *   @0x1f5524 cmp r2, r1
 *   @0x1f5528 popeq {r4, pc}
 *   @0x1f552c ldr r3, [r3]
 *   @0x1f5530 cmp r3, #0
 *   @0x1f5534 bne 0x1f5520 <_ZN13CVariableList4InitEi+0x2c>
 *   @0x1f5538 mov r0, r1
 *   @0x1f553c bl 0x1f50cc <_ZN13CVariableList5AllocEi>
 *   @0x1f5540 mov r1, r0
 *   @0x1f5544 mov r0, r4
 *   @0x1f5548 pop {r4, lr}
 *   @0x1f554c b 0x1f51e8 <_ZN13CVariableList3AddEP9RVariable>
 *
 * ══ §206/321 SV_TransitionKind(CInstance*, int, RValue*)  0x1fa778  size 92  23 条（0x1fa778..0x1fa7d4）
 * @func 0x1fa778 0x1fa7d4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8
 * 字段偏移 top8: 0x38×2 / 0x4×1 / 0x34×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa778 push {r4, lr}
 *   @0x1fa77c ldr r1, [r2, #0x4]
 *   @0x1fa780 ldr r0, [r2]
 *   @0x1fa784 bl 0xb66e8 <lrint@plt>
 *   @0x1fa788 ldr r3, [pc, #0x38]
 *   @0x1fa78c ldr r4, [pc, #0x38]
 *   @0x1fa790 ldr r3, [pc, r3]
 *   @0x1fa794 ldr r1, [pc, #0x34]
 *   @0x1fa798 ldr r4, [pc, r4]
 *   @0x1fa79c ldr r3, [r3]
 *   @0x1fa7a0 add r1, pc, r1
 *   @0x1fa7a4 ldr r2, [r3]
 *   @0x1fa7a8 ldr r2, [r2, #0xc]
 *   @0x1fa7ac str r0, [r4]
 *   @0x1fa7b0 mov r0, r3
 *   @0x1fa7b4 blx r2
 *   @0x1fa7b8 mov r3, #0
 *   @0x1fa7bc mov r0, #1
 *   @0x1fa7c0 str r3, [r4]
 *   @0x1fa7c4 pop {r4, pc}
 *   @0x1fa7c8 andseq r2, pc, r4, lsl #31
 *   @0x1fa7cc andseq r3, pc, r0, lsl r9
 *   @0x1fa7d0 andseq r8, r5, r8, ror #2
 *
 * ══ §207/321 GV_PhysicsCollisionPointCount(CInstance*, int, RValue*)  0x1fab68  size 92  23 条（0x1fab68..0x1fabc4）
 * @func 0x1fab68 0x1fabc4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetCurrentContactPointCount(CInstance*)
 * 字段偏移 top8: 0x50×1 / 0xb4×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fab68 ldr r3, [pc, #0x50]
 *   @0x1fab6c mov r1, r0
 *   @0x1fab70 push {r4, r5, r6, lr}
 *   @0x1fab74 ldr r3, [pc, r3]
 *   @0x1fab78 mov r6, r2
 *   @0x1fab7c ldr r3, [r3]
 *   @0x1fab80 ldr r0, [r3, #0xb4]
 *   @0x1fab84 cmp r0, #0
 *   @0x1fab88 moveq r3, r0
 *   @0x1fab8c beq 0x1fabb8 <_Z29GV_PhysicsCollisionPointCountP9CInstanceiP6RValue+0x50>
 *   @0x1fab90 mov r3, #0
 *   @0x1fab94 str r3, [r2, #0xc]
 *   @0x1fab98 bl 0x238e28 <_ZN13CPhysicsWorld27GetCurrentContactPointCountEP9CInstance>
 *   @0x1fab9c mov r3, #1
 *   @0x1faba0 vmov s15, r0
 *   @0x1faba4 vcvt.f64.s32 d7, s15
 *   @0x1faba8 vmov r4, r5, d7
 *   @0x1fabac vmov r1, s14
 *   @0x1fabb0 mov r2, r5
 *   @0x1fabb4 stm r6, {r1, r2}
 *   @0x1fabb8 mov r0, r3
 *   @0x1fabbc pop {r4, r5, r6, pc}
 *   @0x1fabc0 ldrheq r2, [pc], -r4
 *
 * ══ §208/321 CStream::CStream(int)  0x2010ec  size 92  23 条（0x2010ec..0x201148）
 * @func 0x2010ec 0x201148  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x18×2 / 0xc×1 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2010ec cmp r1, #0
 *   @0x2010f0 mov r2, #0
 *   @0x2010f4 push {r4, lr}
 *   @0x2010f8 mov r4, r0
 *   @0x2010fc mov r3, #0
 *   @0x201100 mov r0, #0
 *   @0x201104 sub sp, sp, #8
 *   @0x201108 strd r2, r3, [r4, #16]
 *   @0x20110c strb r0, [r4]
 *   @0x201110 str r0, [r4, #0x18]
 *   @0x201114 str r0, [r4, #0xc]
 *   @0x201118 str r1, [r4, #0x8]
 *   @0x20111c beq 0x201138 <_ZN7CStreamC2Ei+0x4c>
 *   @0x201120 ldr r2, [pc, #0x1c]
 *   @0x201124 mov r3, #76
 *   @0x201128 str r0, [sp]
 *   @0x20112c add r2, pc, r2
 *   @0x201130 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x201134 str r0, [r4, #0x18]
 *   @0x201138 mov r0, r4
 *   @0x20113c add sp, sp, #8
 *   @0x201140 pop {r4, pc}
 *   @0x201144 ldrsheq r2, [r5], -r12
 *
 * ══ §209/321 Color_ColorToHSV(unsigned int)  0x20fca8  size 92  23 条（0x20fca8..0x20fd04）
 * @func 0x20fca8 0x20fd04  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Color_ColorToRGB(unsigned int&) / Color_RGBtoHSV(TRGB)
 * 字段偏移 top8: 0xc×2 / 0x-4×1 / 0x-c×1 / 0xd×1 / 0xe×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20fca8 str lr, [sp, #-0x4]!
 *   @0x20fcac sub sp, sp, #20
 *   @0x20fcb0 add r3, sp, #16
 *   @0x20fcb4 str r0, [r3, #-0xc]!
 *   @0x20fcb8 mov r0, r3
 *   @0x20fcbc bl 0x20fa00 <_Z16Color_ColorToRGBRj>
 *   @0x20fcc0 strb r0, [sp, #0xc]
 *   @0x20fcc4 ubfx r3, r0, #0x8, #0x8
 *   @0x20fcc8 ubfx r0, r0, #0x10, #0x8
 *   @0x20fccc strb r3, [sp, #0xd]
 *   @0x20fcd0 strb r0, [sp, #0xe]
 *   @0x20fcd4 ldr r0, [sp, #0xc]
 *   @0x20fcd8 bl 0x20fa48 <_Z14Color_RGBtoHSV4TRGB>
 *   @0x20fcdc mov r3, #0
 *   @0x20fce0 uxtb r1, r0
 *   @0x20fce4 ubfx r2, r0, #0x8, #0x8
 *   @0x20fce8 bfi r3, r1, #0, #8
 *   @0x20fcec ubfx r0, r0, #0x10, #0x8
 *   @0x20fcf0 bfi r3, r2, #8, #8
 *   @0x20fcf4 bfi r3, r0, #16, #8
 *   @0x20fcf8 mov r0, r3
 *   @0x20fcfc add sp, sp, #20
 *   @0x20fd00 ldr pc, [sp], #4
 *
 * ══ §210/321 Audio_EmitterSetListenerMask(int, unsigned int)  0x218520  size 92  23 条（0x218520..0x21857c）
 * @func 0x218520 0x21857c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0x38×1 / 0x20×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218520 ldr r3, [pc, #0x48]
 *   @0x218524 ldr r3, [pc, r3]
 *   @0x218528 ldrb r3, [r3]
 *   @0x21852c cmp r3, #0
 *   @0x218530 bxne lr
 *   @0x218534 ldr r3, [pc, #0x38]
 *   @0x218538 ldr r3, [pc, r3]
 *   @0x21853c ldrb r3, [r3]
 *   @0x218540 cmp r3, #0
 *   @0x218544 bxeq lr
 *   @0x218548 cmp r0, #0
 *   @0x21854c bxlt lr
 *   @0x218550 ldr r3, [pc, #0x20]
 *   @0x218554 add r3, pc, r3
 *   @0x218558 ldr r2, [r3, #0x40]
 *   @0x21855c cmp r0, r2
 *   @0x218560 ldrlt r3, [r3, #0x44]
 *   @0x218564 ldrlt r3, [r3, r0, lsl #2]
 *   @0x218568 strlt r1, [r3, #0x30]
 *   @0x21856c bx lr
 *   @0x218570 andseq r6, sp, r8, lsr #22
 *   @0x218574 ldrsheq r6, [sp], -r8
 *   @0x218578 subseq r12, r3, r0, asr #26
 *
 * ══ §211/321 CAudioGroupMan::Finalise()  0x21deb0  size 92  23 条（0x21deb0..0x21df0c）
 * @func 0x21deb0 0x21df0c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::Finalise()+0x44 / CAudioGroup::~CAudioGroup() / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21deb0 ldm r0, {r2, r3}
 *   @0x21deb4 push {r4, r5, r6, lr}
 *   @0x21deb8 cmp r3, #0
 *   @0x21debc mov r6, r0
 *   @0x21dec0 movgt r4, #0
 *   @0x21dec4 ble 0x21def4 <_ZN14CAudioGroupMan8FinaliseEv+0x44>
 *   @0x21dec8 ldr r5, [r2, r4, lsl #2]
 *   @0x21decc add r4, r4, #1
 *   @0x21ded0 cmp r5, #0
 *   @0x21ded4 mov r0, r5
 *   @0x21ded8 beq 0x21deec <_ZN14CAudioGroupMan8FinaliseEv+0x3c>
 *   @0x21dedc bl 0x21db80 <_ZN11CAudioGroupD2Ev>
 *   @0x21dee0 mov r0, r5
 *   @0x21dee4 bl 0x27d1d0 <_ZdlPv>
 *   @0x21dee8 ldm r6, {r2, r3}
 *   @0x21deec cmp r3, r4
 *   @0x21def0 bgt 0x21dec8 <_ZN14CAudioGroupMan8FinaliseEv+0x18>
 *   @0x21def4 mov r0, r2
 *   @0x21def8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21defc mov r3, #0
 *   @0x21df00 str r3, [r6]
 *   @0x21df04 str r3, [r6, #0x4]
 *   @0x21df08 pop {r4, r5, r6, pc}
 *
 * ══ §212/321 SoundHardware::FindDataChunk(void*, int)  0x2203fc  size 92  23 条（0x2203fc..0x220458）
 * @func 0x2203fc 0x220458  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×2 / 0x40×1 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2203fc push {r3, lr}
 *   @0x220400 ldr r3, [pc, #0x40]
 *   @0x220404 ldr r3, [pc, r3]
 *   @0x220408 ldrb r3, [r3]
 *   @0x22040c cmp r3, #0
 *   @0x220410 beq 0x220440 <_ZN13SoundHardware13FindDataChunkEPvi+0x44>
 *   @0x220414 ldr r3, [pc, #0x30]
 *   @0x220418 ldr r2, [pc, #0x30]
 *   @0x22041c ldr r3, [pc, r3]
 *   @0x220420 ldr r1, [pc, #0x2c]
 *   @0x220424 add r2, pc, r2
 *   @0x220428 ldr r0, [r3]
 *   @0x22042c add r1, pc, r1
 *   @0x220430 add r2, r2, #16
 *   @0x220434 ldr r3, [r0]
 *   @0x220438 ldr r3, [r3, #0xc]
 *   @0x22043c blx r3
 *   @0x220440 mov r0, #0
 *   @0x220444 pop {r3, pc}
 *   @0x220448 andseq r1, sp, r4, lsr #32
 *   @0x22044c ldrsheq sp, [r12], -r8
 *   @0x220450 andseq sp, r3, r4, lsr #23
 *   @0x220454 andseq r4, r3, r0, lsl r4
 *
 * ══ §213/321 SOggChannel::Init(unsigned int)  0x223474  size 92  23 条（0x223474..0x2234d0）
 * @func 0x223474 0x2234d0  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: checkAL(char const*)×2 / 0xb6af0 / 0xb6544
 * 字段偏移 top8: 0x44×1 / 0x2b4×1 / 0x2c×1 / 0x2d4×1 / 0x29c×1 / 0x2a0×1 / 0x2a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223474 push {r4, lr}
 *   @0x223478 mov r4, r0
 *   @0x22347c ldr r0, [pc, #0x44]
 *   @0x223480 str r1, [r4, #0x2b4]
 *   @0x223484 add r0, pc, r0
 *   @0x223488 bl 0x215fd0 <_Z7checkALPKc>
 *   @0x22348c add r1, r4, #684
 *   @0x223490 mov r0, #2
 *   @0x223494 bl 0xb6af0 <alGenBuffers@plt>
 *   @0x223498 ldr r0, [pc, #0x2c]
 *   @0x22349c add r0, pc, r0
 *   @0x2234a0 bl 0x215fd0 <_Z7checkALPKc>
 *   @0x2234a4 mov r3, #1
 *   @0x2234a8 mov r0, #32768
 *   @0x2234ac strb r3, [r4, #0x2d4]
 *   @0x2234b0 bl 0xb6544 <malloc@plt>
 *   @0x2234b4 add r3, r0, #16384
 *   @0x2234b8 str r0, [r4, #0x29c]
 *   @0x2234bc str r0, [r4, #0x2a0]
 *   @0x2234c0 str r3, [r4, #0x2a4]
 *   @0x2234c4 pop {r4, pc}
 *   @0x2234c8 andseq r1, r3, r8, asr #16
 *   @0x2234cc andseq r1, r3, r0, asr r8
 *
 * ══ §214/321 F_NewGMLArray(RValue&, CInstance*, CInstance*, int, RValue*)  0x23cbe4  size 92  23 条（0x23cbe4..0x23cc40）
 * @func 0x23cbe4 0x23cc40  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ARRAY_RefAlloc(void*) / PushContextStack(YYObjectBase*) / F_NewGMLArray(RValue&, CInstance*, CInstance*, int, RValue*)+0x54 / SET_RValue_Array(RValue*, RValue*, int)
 * 字段偏移 top8: 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cbe4 push {r3, r4, r5, r6, r7, lr}
 *   @0x23cbe8 mov r2, #2
 *   @0x23cbec str r2, [r0, #0xc]
 *   @0x23cbf0 mov r7, r3
 *   @0x23cbf4 mov r6, r0
 *   @0x23cbf8 ldr r5, [sp, #0x18]
 *   @0x23cbfc bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x23cc00 str r0, [r6]
 *   @0x23cc04 mov r0, #0
 *   @0x23cc08 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x23cc0c cmp r7, #0
 *   @0x23cc10 movgt r4, #0
 *   @0x23cc14 ble 0x23cc38 <_Z13F_NewGMLArrayR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x23cc18 mov r1, r5
 *   @0x23cc1c mov r2, r4
 *   @0x23cc20 mov r0, r6
 *   @0x23cc24 add r4, r4, #1
 *   @0x23cc28 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x23cc2c cmp r4, r7
 *   @0x23cc30 add r5, r5, #16
 *   @0x23cc34 bne 0x23cc18 <_Z13F_NewGMLArrayR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x23cc38 pop {r3, r4, r5, r6, r7, lr}
 *   @0x23cc3c b 0xd3a34 <_Z15PopContextStackv>
 *
 * ══ §215/321 TimeClip(double)  0x245e78  size 92  23 条（0x245e78..0x245ed4）
 * @func 0x245e78 0x245ed4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: myisinf(double)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245e78 push {r3, lr}
 *   @0x245e7c vpush {d8}
 *   @0x245e80 vmov d8, r0, r1
 *   @0x245e84 bl 0x24364c <_Z7myisinfd>
 *   @0x245e88 cmp r0, #0
 *   @0x245e8c bne 0x245eb4 <_Z8TimeClipd+0x3c>
 *   @0x245e90 vabs.f64 d6, d8
 *   @0x245e94 vldr d7, [pc, #44]
 *   @0x245e98 vcmpe.f64 d6, d7
 *   @0x245e9c vmrs APSR_nzcv, fpscr
 *   @0x245ea0 bgt 0x245eb4 <_Z8TimeClipd+0x3c>
 *   @0x245ea4 vmov r0, r1, d8
 *   @0x245ea8 vpop {d8}
 *   @0x245eac pop {r3, lr}
 *   @0x245eb0 b 0xb6598 <floor@plt>
 *   @0x245eb4 vpop {d8}
 *   @0x245eb8 ldr r3, [pc, #0x10]
 *   @0x245ebc ldr r3, [pc, r3]
 *   @0x245ec0 ldrd r0, r1, [r3]
 *   @0x245ec4 pop {r3, pc}
 *   @0x245ec8 sbcsgt r0, r12, #0
 *   @0x245ecc teqmi lr, #8, #4
 *   @0x245ed0 andseq r11, r10, r12, ror #16
 *
 * ══ §216/321 F_JS_Object_isExtensible(RValue&, CInstance*, CInstance*, int, RValue*)  0x250690  size 92  23 条（0x250690..0x2506ec）
 * @func 0x250690 0x2506ec  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x34×1 / 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x250690 cmp r3, #0
 *   @0x250694 ldr r3, [sp]
 *   @0x250698 beq 0x2506ac <_Z24F_JS_Object_isExtensibleR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x25069c ldr r2, [r3, #0xc]
 *   @0x2506a0 bic r2, r2, #-16777216
 *   @0x2506a4 cmp r2, #6
 *   @0x2506a8 beq 0x2506b8 <_Z24F_JS_Object_isExtensibleR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x2506ac ldr r0, [pc, #0x34]
 *   @0x2506b0 add r0, pc, r0
 *   @0x2506b4 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2506b8 ldr r3, [r3]
 *   @0x2506bc mov r2, #13
 *   @0x2506c0 str r2, [r0, #0xc]
 *   @0x2506c4 ldr r3, [r3, #0x28]
 *   @0x2506c8 ands r3, r3, #1
 *   @0x2506cc movne r2, #0
 *   @0x2506d0 moveq r2, r3
 *   @0x2506d4 movne r3, r2
 *   @0x2506d8 movtne r2, #0x3ff0
 *   @0x2506dc str r3, [r0]
 *   @0x2506e0 str r2, [r0, #0x4]
 *   @0x2506e4 bx lr
 *   @0x2506e8 mulseq r0, r8, r8
 *
 * ══ §217/321 F_JSStringCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x256070  size 92  23 条（0x256070..0x2560cc）
 * @func 0x256070 0x2560cc  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToString(RValue&, RValue*)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x1c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x256070 cmp r3, #0
 *   @0x256074 mov r12, r0
 *   @0x256078 push {r3, lr}
 *   @0x25607c ldr r1, [sp, #0x8]
 *   @0x256080 beq 0x2560b0 <_Z14F_JSStringCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x256084 ldr r2, [r1, #0xc]
 *   @0x256088 mvn r3, #-16777216
 *   @0x25608c cmp r2, r3
 *   @0x256090 beq 0x2560b0 <_Z14F_JSStringCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x256094 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256098 cmp r0, #1
 *   @0x25609c popne {r3, pc}
 *   @0x2560a0 ldr r0, [pc, #0x1c]
 *   @0x2560a4 pop {r3, lr}
 *   @0x2560a8 add r0, pc, r0
 *   @0x2560ac b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2560b0 ldr r1, [pc, #0x10]
 *   @0x2560b4 mov r0, r12
 *   @0x2560b8 pop {r3, lr}
 *   @0x2560bc add r1, pc, r1
 *   @0x2560c0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2560c4 andeq pc, pc, r0, lsr #29
 *   @0x2560c8 andeq r8, sp, r10, ror r10
 *
 * ══ §218/321 SMemoryArray::Free(void*)  0x27dda4  size 92  23 条（0x27dda4..0x27de00）
 * @func 0x27dda4 0x27de00  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3
 * 字段偏移 top8: 0x14×2 / 0x8×1 / 0xc×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27dda4 push {r4, lr}
 *   @0x27dda8 mov r4, r0
 *   @0x27ddac ldr r0, [r0, #0x8]
 *   @0x27ddb0 cmp r0, r1
 *   @0x27ddb4 bhi 0x27ddf4 <_ZN12SMemoryArray4FreeEPv+0x50>
 *   @0x27ddb8 ldr r3, [r4, #0xc]
 *   @0x27ddbc cmp r1, r3
 *   @0x27ddc0 bhi 0x27ddf4 <_ZN12SMemoryArray4FreeEPv+0x50>
 *   @0x27ddc4 rsb r0, r0, r1
 *   @0x27ddc8 ldr r1, [r4, #0x18]
 *   @0x27ddcc bl 0x318d10 <__divsi3>
 *   @0x27ddd0 ldr r2, [r4, #0x14]
 *   @0x27ddd4 mov r3, #1
 *   @0x27ddd8 ldr r1, [r4, #0x10]
 *   @0x27dddc add r2, r2, r3
 *   @0x27dde0 str r2, [r4, #0x14]
 *   @0x27dde4 lsl r2, r2, r3
 *   @0x27dde8 strh r0, [r1, r2]
 *   @0x27ddec mov r0, r3
 *   @0x27ddf0 pop {r4, pc}
 *   @0x27ddf4 mov r3, #0
 *   @0x27ddf8 mov r0, r3
 *   @0x27ddfc pop {r4, pc}
 *
 * ══ §219/321 CheckFastCRC()  0x27de64  size 92  23 条（0x27de64..0x27dec0）
 * @func 0x27de64 0x27dec0  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x50×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27de64 ldr r12, [pc, #0x50]
 *   @0x27de68 mov r1, #0
 *   @0x27de6c ldr r12, [pc, r12]
 *   @0x27de70 sub r12, r12, #4
 *   @0x27de74 mov r3, r1
 *   @0x27de78 mov r0, #8
 *   @0x27de7c tst r3, #1
 *   @0x27de80 lsr r2, r3, #1
 *   @0x27de84 lsreq r3, r3, #1
 *   @0x27de88 movwne r3, #0x8320
 *   @0x27de8c movtne r3, #0xedb8
 *   @0x27de90 eorne r3, r2, r3
 *   @0x27de94 subs r0, r0, #1
 *   @0x27de98 bne 0x27de7c <_Z12CheckFastCRCv+0x18>
 *   @0x27de9c ldr r2, [r12, #0x4]!
 *   @0x27dea0 cmp r3, r2
 *   @0x27dea4 bxne lr
 *   @0x27dea8 add r1, r1, #1
 *   @0x27deac cmp r1, #256
 *   @0x27deb0 bne 0x27de74 <_Z12CheckFastCRCv+0x10>
 *   @0x27deb4 mov r0, #1
 *   @0x27deb8 bx lr
 *   @0x27debc ldrheq r2, [r7], -r4
 *
 * ══ §220/321 spMeshAttachment_create  0x2874dc  size 92  23 条（0x2874dc..0x287538）
 * @func 0x2874dc 0x287538  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / _spAttachment_init
 * 字段偏移 top8: 0x4c×1 / 0x30×1 / 0x68×1 / 0x6c×1 / 0x70×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2874dc ldr r2, [pc, #0x4c]
 *   @0x2874e0 mov r1, #148
 *   @0x2874e4 push {r3, r4, r5, lr}
 *   @0x2874e8 add r2, pc, r2
 *   @0x2874ec mov r5, r0
 *   @0x2874f0 mov r3, #50
 *   @0x2874f4 mov r0, #1
 *   @0x2874f8 bl 0x285c4c <_calloc>
 *   @0x2874fc ldr r3, [pc, #0x30]
 *   @0x287500 mov r12, #1065353216
 *   @0x287504 mov r1, r5
 *   @0x287508 mov r2, #2
 *   @0x28750c ldr r3, [pc, r3]
 *   @0x287510 mov r4, r0
 *   @0x287514 str r12, [r0, #0x68]
 *   @0x287518 str r12, [r0, #0x6c]
 *   @0x28751c str r12, [r0, #0x70]
 *   @0x287520 str r12, [r0, #0x74]
 *   @0x287524 bl 0x284c18 <_spAttachment_init>
 *   @0x287528 mov r0, r4
 *   @0x28752c pop {r3, r4, r5, pc}
 *   @0x287530 andeq r0, sp, r8, lsl r4
 *   @0x287534 ldrsheq r10, [r6], -r4
 *
 * ══ §221/321 spSkeleton_findBoneIndex  0x28a130  size 92  23 条（0x28a130..0x28a18c）
 * @func 0x28a130 0x28a18c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findBoneIndex+0x54 / 0xb6574
 * 字段偏移 top8: 0x4×3 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a130 push {r3, r4, r5, r6, r7, lr}
 *   @0x28a134 mov r7, r1
 *   @0x28a138 ldr r6, [r0, #0x4]
 *   @0x28a13c cmp r6, #0
 *   @0x28a140 ble 0x28a184 <spSkeleton_findBoneIndex+0x54>
 *   @0x28a144 ldr r3, [r0]
 *   @0x28a148 mov r4, #0
 *   @0x28a14c ldr r5, [r3, #0x14]
 *   @0x28a150 sub r5, r5, #4
 *   @0x28a154 b 0x28a164 <spSkeleton_findBoneIndex+0x34>
 *   @0x28a158 add r4, r4, #1
 *   @0x28a15c cmp r4, r6
 *   @0x28a160 beq 0x28a184 <spSkeleton_findBoneIndex+0x54>
 *   @0x28a164 ldr r3, [r5, #0x4]!
 *   @0x28a168 mov r1, r7
 *   @0x28a16c ldr r0, [r3, #0x4]
 *   @0x28a170 bl 0xb6574 <strcmp@plt>
 *   @0x28a174 cmp r0, #0
 *   @0x28a178 bne 0x28a158 <spSkeleton_findBoneIndex+0x28>
 *   @0x28a17c mov r0, r4
 *   @0x28a180 pop {r3, r4, r5, r6, r7, pc}
 *   @0x28a184 mvn r0, #0
 *   @0x28a188 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §222/321 spSkeletonData_findBone  0x28afbc  size 92  23 条（0x28afbc..0x28b018）
 * @func 0x28afbc 0x28b018  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findBone+0x50 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28afbc push {r4, r5, r6, r7, r8, lr}
 *   @0x28afc0 mov r8, r1
 *   @0x28afc4 ldr r7, [r0, #0x10]
 *   @0x28afc8 cmp r7, #0
 *   @0x28afcc ble 0x28b00c <spSkeletonData_findBone+0x50>
 *   @0x28afd0 ldr r6, [r0, #0x14]
 *   @0x28afd4 mov r4, #0
 *   @0x28afd8 sub r6, r6, #4
 *   @0x28afdc b 0x28afe8 <spSkeletonData_findBone+0x2c>
 *   @0x28afe0 cmp r4, r7
 *   @0x28afe4 beq 0x28b00c <spSkeletonData_findBone+0x50>
 *   @0x28afe8 ldr r5, [r6, #0x4]!
 *   @0x28afec mov r1, r8
 *   @0x28aff0 add r4, r4, #1
 *   @0x28aff4 ldr r0, [r5, #0x4]
 *   @0x28aff8 bl 0xb6574 <strcmp@plt>
 *   @0x28affc cmp r0, #0
 *   @0x28b000 bne 0x28afe0 <spSkeletonData_findBone+0x24>
 *   @0x28b004 mov r0, r5
 *   @0x28b008 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28b00c mov r5, #0
 *   @0x28b010 mov r0, r5
 *   @0x28b014 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §223/321 spSkeletonData_findSlot  0x28b070  size 92  23 条（0x28b070..0x28b0cc）
 * @func 0x28b070 0x28b0cc  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findSlot+0x50 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b070 push {r4, r5, r6, r7, r8, lr}
 *   @0x28b074 mov r8, r1
 *   @0x28b078 ldr r7, [r0, #0x18]
 *   @0x28b07c cmp r7, #0
 *   @0x28b080 ble 0x28b0c0 <spSkeletonData_findSlot+0x50>
 *   @0x28b084 ldr r6, [r0, #0x1c]
 *   @0x28b088 mov r4, #0
 *   @0x28b08c sub r6, r6, #4
 *   @0x28b090 b 0x28b09c <spSkeletonData_findSlot+0x2c>
 *   @0x28b094 cmp r4, r7
 *   @0x28b098 beq 0x28b0c0 <spSkeletonData_findSlot+0x50>
 *   @0x28b09c ldr r5, [r6, #0x4]!
 *   @0x28b0a0 mov r1, r8
 *   @0x28b0a4 add r4, r4, #1
 *   @0x28b0a8 ldr r0, [r5, #0x4]
 *   @0x28b0ac bl 0xb6574 <strcmp@plt>
 *   @0x28b0b0 cmp r0, #0
 *   @0x28b0b4 bne 0x28b094 <spSkeletonData_findSlot+0x24>
 *   @0x28b0b8 mov r0, r5
 *   @0x28b0bc pop {r4, r5, r6, r7, r8, pc}
 *   @0x28b0c0 mov r5, #0
 *   @0x28b0c4 mov r0, r5
 *   @0x28b0c8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §224/321 spSkeletonData_findEvent  0x28b180  size 92  23 条（0x28b180..0x28b1dc）
 * @func 0x28b180 0x28b1ec  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findEvent+0x50 / 0xb6574
 * 字段偏移 top8: 0x2c×1 / 0x30×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b180 push {r4, r5, r6, r7, r8, lr}
 *   @0x28b184 mov r8, r1
 *   @0x28b188 ldr r7, [r0, #0x2c]
 *   @0x28b18c cmp r7, #0
 *   @0x28b190 ble 0x28b1d0 <spSkeletonData_findEvent+0x50>
 *   @0x28b194 ldr r6, [r0, #0x30]
 *   @0x28b198 mov r4, #0
 *   @0x28b19c sub r6, r6, #4
 *   @0x28b1a0 b 0x28b1ac <spSkeletonData_findEvent+0x2c>
 *   @0x28b1a4 cmp r4, r7
 *   @0x28b1a8 beq 0x28b1d0 <spSkeletonData_findEvent+0x50>
 *   @0x28b1ac ldr r5, [r6, #0x4]!
 *   @0x28b1b0 mov r1, r8
 *   @0x28b1b4 add r4, r4, #1
 *   @0x28b1b8 ldr r0, [r5]
 *   @0x28b1bc bl 0xb6574 <strcmp@plt>
 *   @0x28b1c0 cmp r0, #0
 *   @0x28b1c4 bne 0x28b1a4 <spSkeletonData_findEvent+0x24>
 *   @0x28b1c8 mov r0, r5
 *   @0x28b1cc pop {r4, r5, r6, r7, r8, pc}
 *   @0x28b1d0 mov r5, #0
 *   @0x28b1d4 mov r0, r5
 *   @0x28b1d8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §225/321 spSkeletonData_findAnimation  0x28b1dc  size 92  23 条（0x28b1dc..0x28b238）
 * @func 0x28b1dc 0x28b248  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findAnimation+0x50 / 0xb6574
 * 字段偏移 top8: 0x34×1 / 0x38×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b1dc push {r4, r5, r6, r7, r8, lr}
 *   @0x28b1e0 mov r8, r1
 *   @0x28b1e4 ldr r7, [r0, #0x34]
 *   @0x28b1e8 cmp r7, #0
 *   @0x28b1ec ble 0x28b22c <spSkeletonData_findAnimation+0x50>
 *   @0x28b1f0 ldr r6, [r0, #0x38]
 *   @0x28b1f4 mov r4, #0
 *   @0x28b1f8 sub r6, r6, #4
 *   @0x28b1fc b 0x28b208 <spSkeletonData_findAnimation+0x2c>
 *   @0x28b200 cmp r4, r7
 *   @0x28b204 beq 0x28b22c <spSkeletonData_findAnimation+0x50>
 *   @0x28b208 ldr r5, [r6, #0x4]!
 *   @0x28b20c mov r1, r8
 *   @0x28b210 add r4, r4, #1
 *   @0x28b214 ldr r0, [r5]
 *   @0x28b218 bl 0xb6574 <strcmp@plt>
 *   @0x28b21c cmp r0, #0
 *   @0x28b220 bne 0x28b200 <spSkeletonData_findAnimation+0x24>
 *   @0x28b224 mov r0, r5
 *   @0x28b228 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28b22c mov r5, #0
 *   @0x28b230 mov r0, r5
 *   @0x28b234 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §226/321 spSkeletonData_findIkConstraint  0x28b238  size 92  23 条（0x28b238..0x28b294）
 * @func 0x28b238 0x28b2a4  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findIkConstraint+0x50 / 0xb6574
 * 字段偏移 top8: 0x3c×1 / 0x40×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b238 push {r4, r5, r6, r7, r8, lr}
 *   @0x28b23c mov r8, r1
 *   @0x28b240 ldr r7, [r0, #0x3c]
 *   @0x28b244 cmp r7, #0
 *   @0x28b248 ble 0x28b288 <spSkeletonData_findIkConstraint+0x50>
 *   @0x28b24c ldr r6, [r0, #0x40]
 *   @0x28b250 mov r4, #0
 *   @0x28b254 sub r6, r6, #4
 *   @0x28b258 b 0x28b264 <spSkeletonData_findIkConstraint+0x2c>
 *   @0x28b25c cmp r4, r7
 *   @0x28b260 beq 0x28b288 <spSkeletonData_findIkConstraint+0x50>
 *   @0x28b264 ldr r5, [r6, #0x4]!
 *   @0x28b268 mov r1, r8
 *   @0x28b26c add r4, r4, #1
 *   @0x28b270 ldr r0, [r5]
 *   @0x28b274 bl 0xb6574 <strcmp@plt>
 *   @0x28b278 cmp r0, #0
 *   @0x28b27c bne 0x28b25c <spSkeletonData_findIkConstraint+0x24>
 *   @0x28b280 mov r0, r5
 *   @0x28b284 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28b288 mov r5, #0
 *   @0x28b28c mov r0, r5
 *   @0x28b290 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §227/321 spSkeletonData_findTransformConstraint  0x28b294  size 92  23 条（0x28b294..0x28b2f0）
 * @func 0x28b294 0x28b300  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findTransformConstraint+0x50 / 0xb6574
 * 字段偏移 top8: 0x44×1 / 0x48×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b294 push {r4, r5, r6, r7, r8, lr}
 *   @0x28b298 mov r8, r1
 *   @0x28b29c ldr r7, [r0, #0x44]
 *   @0x28b2a0 cmp r7, #0
 *   @0x28b2a4 ble 0x28b2e4 <spSkeletonData_findTransformConstraint+0x50>
 *   @0x28b2a8 ldr r6, [r0, #0x48]
 *   @0x28b2ac mov r4, #0
 *   @0x28b2b0 sub r6, r6, #4
 *   @0x28b2b4 b 0x28b2c0 <spSkeletonData_findTransformConstraint+0x2c>
 *   @0x28b2b8 cmp r4, r7
 *   @0x28b2bc beq 0x28b2e4 <spSkeletonData_findTransformConstraint+0x50>
 *   @0x28b2c0 ldr r5, [r6, #0x4]!
 *   @0x28b2c4 mov r1, r8
 *   @0x28b2c8 add r4, r4, #1
 *   @0x28b2cc ldr r0, [r5]
 *   @0x28b2d0 bl 0xb6574 <strcmp@plt>
 *   @0x28b2d4 cmp r0, #0
 *   @0x28b2d8 bne 0x28b2b8 <spSkeletonData_findTransformConstraint+0x24>
 *   @0x28b2dc mov r0, r5
 *   @0x28b2e0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28b2e4 mov r5, #0
 *   @0x28b2e8 mov r0, r5
 *   @0x28b2ec pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §228/321 spSkeletonData_findPathConstraint  0x28b2f0  size 92  23 条（0x28b2f0..0x28b34c）
 * @func 0x28b2f0 0x28b34c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findPathConstraint+0x50 / 0xb6574
 * 字段偏移 top8: 0x4c×1 / 0x50×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b2f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x28b2f4 mov r8, r1
 *   @0x28b2f8 ldr r7, [r0, #0x4c]
 *   @0x28b2fc cmp r7, #0
 *   @0x28b300 ble 0x28b340 <spSkeletonData_findPathConstraint+0x50>
 *   @0x28b304 ldr r6, [r0, #0x50]
 *   @0x28b308 mov r4, #0
 *   @0x28b30c sub r6, r6, #4
 *   @0x28b310 b 0x28b31c <spSkeletonData_findPathConstraint+0x2c>
 *   @0x28b314 cmp r4, r7
 *   @0x28b318 beq 0x28b340 <spSkeletonData_findPathConstraint+0x50>
 *   @0x28b31c ldr r5, [r6, #0x4]!
 *   @0x28b320 mov r1, r8
 *   @0x28b324 add r4, r4, #1
 *   @0x28b328 ldr r0, [r5]
 *   @0x28b32c bl 0xb6574 <strcmp@plt>
 *   @0x28b330 cmp r0, #0
 *   @0x28b334 bne 0x28b314 <spSkeletonData_findPathConstraint+0x24>
 *   @0x28b338 mov r0, r5
 *   @0x28b33c pop {r4, r5, r6, r7, r8, pc}
 *   @0x28b340 mov r5, #0
 *   @0x28b344 mov r0, r5
 *   @0x28b348 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §229/321 yySocket::SetTimeout(int, int)  0x294ed4  size 92  23 条（0x294ed4..0x294f30）
 * @func 0x294ed4 0x294f30  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6d9c×2
 * 字段偏移 top8: 0xb4×1 / 0xb8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294ed4 push {r4, r5, r6, lr}
 *   @0x294ed8 add r6, r0, #180
 *   @0x294edc sub sp, sp, #8
 *   @0x294ee0 mov r4, r0
 *   @0x294ee4 mov r5, #4
 *   @0x294ee8 ldr r0, [r0]
 *   @0x294eec mov r3, r6
 *   @0x294ef0 str r1, [r4, #0xb4]
 *   @0x294ef4 str r2, [r4, #0xb8]
 *   @0x294ef8 mov r1, #1
 *   @0x294efc str r5, [sp]
 *   @0x294f00 mov r2, #20
 *   @0x294f04 bl 0xb6d9c <setsockopt@plt>
 *   @0x294f08 cmp r0, #0
 *   @0x294f0c bne 0x294f28 <_ZN8yySocket10SetTimeoutEii+0x54>
 *   @0x294f10 ldr r0, [r4]
 *   @0x294f14 mov r3, r6
 *   @0x294f18 str r5, [sp]
 *   @0x294f1c mov r1, #1
 *   @0x294f20 mov r2, #21
 *   @0x294f24 bl 0xb6d9c <setsockopt@plt>
 *   @0x294f28 add sp, sp, #8
 *   @0x294f2c pop {r4, r5, r6, pc}
 *
 * ══ §230/321 png_sig_cmp  0x2a5a4c  size 92  23 条（0x2a5a4c..0x2a5aa8）
 * @func 0x2a5a4c 0x2a5aa8  size 92  23 条
 * 部分覆盖: 本节 23/43 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65d4
 * 字段偏移 top8: 0x4c×1 / 0x40×1 / 0xc×1 / 0x1b×1 / 0x178×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5a4c push {r0, r1, r2, r3, r4, r5, r6, lr}
 *   @0x2a5a50 ldr r4, [pc, #0x4c]
 *   @0x2a5a54 add r5, sp, #0x4
 *   @0x2a5a58 add r4, pc
 *   @0x2a5a5c ldr r1, [r4]
 *   @0x2a5a60 ldr r1, [pc, #0x40]
 *   @0x2a5a64 ldr r0, [r1]
 *   @0x2a5a68 stm r5!, {r0, r1}
 *   @0x2a5a6c cbnz r2, 0x2a5a72 <png_sig_cmp+0x26>
 *   @0x2a5a70 movs r2, #0x8
 *   @0x2a5a74 bhi 0x2a5a8c <png_sig_cmp+0x40>
 *   @0x2a5a78 adds r0, r6, r3
 *   @0x2a5a7c add r1, sp, #0x4
 *   @0x2a5a80 rsbhi.w r2, r3, #0x8
 *   @0x2a5a84 add r1, r3
 *   @0x2a5a88 ldrd lr, pc, [r1], -r12
 *   @0x2a5a8c mov.w r0, #0xffffffff
 *   @0x2a5a90 ldr r2, [sp, #0xc]
 *   @0x2a5a94 cmp r2, r3
 *   @0x2a5a98 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a5a9c add sp, #0x10
 *   @0x2a5aa0 ldrb r4, [r7, #0x1b]
 *   @0x2a5aa4 ldr r6, [sp, #0x178]
 *
 * ══ §231/321 png_set_background  0x2a8128  size 92  23 条（0x2a8128..0x2a8184）
 * @func 0x2a8128 0x2a8184  size 92  23 条
 * 部分覆盖: 本节 23/37 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0x4×1 / 0x1f4×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8128 push {r4, r5, lr}
 *   @0x2a812c strmi r7, [r4], -r3, lsl #22
 *   @0x2a8130 cbz r0, 0x2a817e <png_set_background+0x56>
 *   @0x2a8134 ldr r1, [pc, #0x48]
 *   @0x2a8138 ldrbtmi r4, [r9], #-48
 *   @0x2a813c b.w 0x2a6474 <png_warning>
 *   @0x2a8140 ldr.w r0, [r0, #0x134]
 *   @0x2a8144 vcvt.f32.f64 s14, d7
 *   @0x2a8148 cmp r3, #0x0
 *   @0x2a814c movne.w r3, #0x100
 *   @0x2a8150 moveq r3, #0x0
 *   @0x2a8154 .word 0xf8c40080
 *   @0x2a8158 stmdavs r8, {r2, r4, r5, r8}
 *   @0x2a815c str.w r0, [r4, #0x1fc]
 *   @0x2a8160 ldr r0, [r1, #0x4]
 *   @0x2a8164 stmdbhi r9, {r9}
 *   @0x2a8168 vstr s14, [r4, #504]
 *   @0x2a816c strb.w r2, [r4, #0x1f4]
 *   @0x2a8170 ldr.w r2, [r4, #0x134]
 *   @0x2a8174 strh.w r1, [r4, #0x204]
 *   @0x2a8178 orrs r2, r3
 *   @0x2a817c ldclt p1, c2, [r0, #-208]!
 *   @0x2a8180 ldr r0, [pc, #0x1f4]
 *
 * ══ §232/321 png_do_invert  0x2af85a  size 92  23 条（0x2af85a..0x2af8b6）
 * @func 0x2af85a 0x2af8b6  size 92  23 条
 * 部分覆盖: 本节 23/44 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x16×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af85a push {r4, lr}
 *   @0x2af85e cbnz r3, 0x2af874 <png_do_invert+0x1a>
 *   @0x2af862 add r3, r1
 *   @0x2af866 beq 0x2af872 <png_do_invert+0x18>
 *   @0x2af86a mvns r2, r2
 *   @0x2af86e ldrb r2, [r8, r1, lsl #22]!
 *   @0x2af872 pop {r4, pc}
 *   @0x2af876 movw r2, #0x804
 *   @0x2af87a cmp r3, r2
 *   @0x2af87e ldr r2, [r0, #0x4]
 *   @0x2af882 cmp r3, r2
 *   @0x2af886 ldrb r0, [r1, r3]
 *   @0x2af88a strb r0, [r1, r3]
 *   @0x2af88e b 0x2af882 <png_do_invert+0x28>
 *   @0x2af892 movw r2, #0x1004
 *   @0x2af896 cmp r3, r2
 *   @0x2af89a ldr r0, [r0, #0x4]
 *   @0x2af89e cmp r3, r0
 *   @0x2af8a2 ldrb r2, [r1, r3]
 *   @0x2af8a6 strb r2, [r1, r3]
 *   @0x2af8aa adds r3, #0x4
 *   @0x2af8ae mvns r4, r4
 *   @0x2af8b2 b 0x2af89e <png_do_invert+0x44>
 *
 * ══ §233/321 void std::priv::__unguarded_linear_insert<b2Pair*, b2Pair, bool (*)(b2Pair const&, b2Pair const&)>(b2Pair*, b2Pair, bool (*)(b2Pair const&, b2Pair const&))  0x2c7ed0  size 92  23 条（0x2c7ed0..0x2c7f2c）
 * @func 0x2c7ed0 0x2c7f2c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7ed0 push {r4, r5, r6, r7, lr}
 *   @0x2c7ed4 sub sp, sp, #12
 *   @0x2c7ed8 mov r5, r0
 *   @0x2c7edc mov r7, r3
 *   @0x2c7ee0 mov r6, sp
 *   @0x2c7ee4 sub r4, r0, #8
 *   @0x2c7ee8 stm sp, {r1, r2}
 *   @0x2c7eec b 0x2c7efc <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x2c>
 *   @0x2c7ef0 ldm r2, {r0, r1}
 *   @0x2c7ef4 stm r5, {r0, r1}
 *   @0x2c7ef8 mov r5, r12
 *   @0x2c7efc mov r1, r4
 *   @0x2c7f00 mov r0, sp
 *   @0x2c7f04 blx r7
 *   @0x2c7f08 mov r12, r4
 *   @0x2c7f0c sub r4, r4, #8
 *   @0x2c7f10 add r2, r4, #8
 *   @0x2c7f14 cmp r0, #0
 *   @0x2c7f18 bne 0x2c7ef0 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x20>
 *   @0x2c7f1c ldm r6, {r0, r1}
 *   @0x2c7f20 stm r5, {r0, r1}
 *   @0x2c7f24 add sp, sp, #12
 *   @0x2c7f28 pop {r4, r5, r6, r7, pc}
 *
 * ══ §234/321 b2Fixture::DestroyProxies(b2BroadPhase*)  0x2c8770  size 92  23 条（0x2c8770..0x2c87cc）
 * @func 0x2c8770 0x2c87cc  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Fixture::DestroyProxies(b2BroadPhase*)+0x50 / b2BroadPhase::DestroyProxy(int)
 * 字段偏移 top8: 0x1c×3 / 0x18×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c8770 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c8774 mov r7, r0
 *   @0x2c8778 ldr r3, [r0, #0x1c]
 *   @0x2c877c mov r8, r1
 *   @0x2c8780 cmp r3, #0
 *   @0x2c8784 movgt r4, #0
 *   @0x2c8788 mvngt r9, #0
 *   @0x2c878c movgt r5, r4
 *   @0x2c8790 ble 0x2c87c0 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase+0x50>
 *   @0x2c8794 ldr r6, [r7, #0x18]
 *   @0x2c8798 mov r0, r8
 *   @0x2c879c add r5, r5, #1
 *   @0x2c87a0 add r6, r6, r4
 *   @0x2c87a4 add r4, r4, #28
 *   @0x2c87a8 ldr r1, [r6, #0x18]
 *   @0x2c87ac bl 0x2dc924 <_ZN12b2BroadPhase12DestroyProxyEi>
 *   @0x2c87b0 ldr r3, [r7, #0x1c]
 *   @0x2c87b4 str r9, [r6, #0x18]
 *   @0x2c87b8 cmp r3, r5
 *   @0x2c87bc bgt 0x2c8794 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase+0x24>
 *   @0x2c87c0 mov r3, #0
 *   @0x2c87c4 str r3, [r7, #0x1c]
 *   @0x2c87c8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §235/321 b2World::SetAllowSleeping(bool)  0x2c95e0  size 92  23 条（0x2c95e0..0x2c963c）
 * @func 0x2c95e0 0x2c963c  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c95e0 movw r3, #0x9240
 *   @0x2c95e4 movt r3, #0x1
 *   @0x2c95e8 ldrb r2, [r0, r3]
 *   @0x2c95ec cmp r2, r1
 *   @0x2c95f0 bxeq lr
 *   @0x2c95f4 cmp r1, #0
 *   @0x2c95f8 strb r1, [r0, r3]
 *   @0x2c95fc bxne lr
 *   @0x2c9600 movw r3, #0x9228
 *   @0x2c9604 movt r3, #0x1
 *   @0x2c9608 ldr r3, [r0, r3]
 *   @0x2c960c cmp r3, #0
 *   @0x2c9610 bxeq lr
 *   @0x2c9614 mov r1, #0
 *   @0x2c9618 ldrh r2, [r3, #4]
 *   @0x2c961c tst r2, #2
 *   @0x2c9620 orr r2, r2, #2
 *   @0x2c9624 streq r1, [r3, #0xa0]
 *   @0x2c9628 strheq r2, [r3, #4]
 *   @0x2c962c ldr r3, [r3, #0x70]
 *   @0x2c9630 cmp r3, #0
 *   @0x2c9634 bne 0x2c9618 <_ZN7b2World16SetAllowSleepingEb+0x38>
 *   @0x2c9638 bx lr
 *
 * ══ §236/321 FT_Done_Face  0x2e8bdc  size 92  23 条（0x2e8bdc..0x2e8c38）
 * @func 0x2e8bdc 0x2e8c38  size 92  23 条
 * 部分覆盖: 本节 23/39 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_List_Find / FT_List_Remove / ft_mem_free
 * 字段偏移 top8: 0x60×2 / 0x40×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8bdc push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2e8be0 mov r4, r0
 *   @0x2e8be4 ldr r3, [r0, #0x60]
 *   @0x2e8be8 ldr.w r3, [r0, #0x80]
 *   @0x2e8bec ldr r2, [r3, #0x40]
 *   @0x2e8bf0 str r2, [r3, #0x40]
 *   @0x2e8bf4 .word 0x6c1b3080
 *   @0x2e8bf8 cmp r3, #0x0
 *   @0x2e8bfc ldr r5, [r0, #0x60]
 *   @0x2e8c00 add.w r8, r5, #0x10
 *   @0x2e8c04 ldr r7, [r5, #0x8]
 *   @0x2e8c08 bl 0x2e890e <FT_List_Find>
 *   @0x2e8c0c mov r6, r0
 *   @0x2e8c10 mov r0, r8
 *   @0x2e8c14 bl 0x2e89f2 <FT_List_Remove>
 *   @0x2e8c18 mov r0, r7
 *   @0x2e8c1c bl 0x2e7336 <ft_mem_free>
 *   @0x2e8c20 mov r0, r7
 *   @0x2e8c24 mov r2, r5
 *   @0x2e8c28 mul r2, r9, pc
 *   @0x2e8c2c movs r0, #0x23
 *   @0x2e8c30 strdhs r8, r9, [r0], -r0
 *   @0x2e8c34 pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §237/321 FT_GlyphSlot_Own_Bitmap  0x314dc0  size 92  23 条（0x314dc0..0x314e1c）
 * @func 0x314dc0 0x314e1c  size 92  23 条
 * 部分覆盖: 本节 23/41 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Bitmap_Init
 * 字段偏移 top8: 0x4×2 / 0x48×1 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x314dc0 push {r4, r5, r6, r7, lr}
 *   @0x314dc4 sub sp, #0x1c
 *   @0x314dc8 ldr r3, [r0, #0x48]
 *   @0x314dcc cmp r3, r2
 *   @0x314dd0 ldr.w r3, [r0, #0x9c]
 *   @0x314dd4 ldr r3, [r3, #0x4]
 *   @0x314dd8 bmi 0x314e12 <FT_GlyphSlot_Own_Bitmap+0x52>
 *   @0x314ddc strbtmi r0, [r8], -r12, asr #8
 *   @0x314de0 bl 0x3149bc <FT_Bitmap_Init>
 *   @0x314de4 ldr r0, [r6]
 *   @0x314de8 mov r2, sp
 *   @0x314dec .word 0x4607fdf5
 *   @0x314df0 cbnz r0, 0x314e0c <FT_GlyphSlot_Own_Bitmap+0x4c>
 *   @0x314df4 ldm r5!, {r0, r1, r2, r3}
 *   @0x314df8 ldm.w r5, {r0, r1}
 *   @0x314dfc stm.w r4, {r0, r1}
 *   @0x314e00 ldr.w r3, [r6, #0x9c]
 *   @0x314e04 ldr r2, [r3, #0x4]
 *   @0x314e08 subsvs r0, r10, r1, lsl #4
 *   @0x314e0c mov r0, r7
 *   @0x314e10 b 0x314e14 <FT_GlyphSlot_Own_Bitmap+0x54>
 *   @0x314e14 add sp, #0x1c
 *   @0x314e18 strb r3, [r6, #0x11]
 *
 * ══ §238/321 _Unwind_VRS_Get  0x319be4  size 92  23 条（0x319be4..0x319c40）
 * @func 0x319be4 0x319c40  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319be4 cmp r1, #4
 *   @0x319be8 addls pc, pc, r1, lsl #2
 *   @0x319bec b 0x319c38 <_Unwind_VRS_Get+0x54>
 *   @0x319bf0 b 0x319c0c <_Unwind_VRS_Get+0x28>
 *   @0x319bf4 b 0x319c04 <_Unwind_VRS_Get+0x20>
 *   @0x319bf8 b 0x319c38 <_Unwind_VRS_Get+0x54>
 *   @0x319bfc b 0x319c04 <_Unwind_VRS_Get+0x20>
 *   @0x319c00 b 0x319c04 <_Unwind_VRS_Get+0x20>
 *   @0x319c04 mov r0, #1
 *   @0x319c08 bx lr
 *   @0x319c0c cmp r2, #15
 *   @0x319c10 cmpls r3, #0
 *   @0x319c14 moveq r3, #0
 *   @0x319c18 movne r3, #1
 *   @0x319c1c bne 0x319c38 <_Unwind_VRS_Get+0x54>
 *   @0x319c20 add r2, r0, r2, lsl #2
 *   @0x319c24 mov r0, r3
 *   @0x319c28 ldr r1, [r2, #0x4]
 *   @0x319c2c ldr r2, [sp]
 *   @0x319c30 str r1, [r2]
 *   @0x319c34 bx lr
 *   @0x319c38 mov r0, #2
 *   @0x319c3c bx lr
 *
 * ══ §239/321 _Unwind_VRS_Set  0x319c68  size 92  23 条（0x319c68..0x319cc4）
 * @func 0x319c68 0x319cc4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319c68 cmp r1, #4
 *   @0x319c6c addls pc, pc, r1, lsl #2
 *   @0x319c70 b 0x319cbc <_Unwind_VRS_Set+0x54>
 *   @0x319c74 b 0x319c90 <_Unwind_VRS_Set+0x28>
 *   @0x319c78 b 0x319c88 <_Unwind_VRS_Set+0x20>
 *   @0x319c7c b 0x319cbc <_Unwind_VRS_Set+0x54>
 *   @0x319c80 b 0x319c88 <_Unwind_VRS_Set+0x20>
 *   @0x319c84 b 0x319c88 <_Unwind_VRS_Set+0x20>
 *   @0x319c88 mov r0, #1
 *   @0x319c8c bx lr
 *   @0x319c90 cmp r2, #15
 *   @0x319c94 cmpls r3, #0
 *   @0x319c98 moveq r3, #0
 *   @0x319c9c movne r3, #1
 *   @0x319ca0 bne 0x319cbc <_Unwind_VRS_Set+0x54>
 *   @0x319ca4 ldr r1, [sp]
 *   @0x319ca8 add r2, r0, r2, lsl #2
 *   @0x319cac mov r0, r3
 *   @0x319cb0 ldr r1, [r1]
 *   @0x319cb4 str r1, [r2, #0x4]
 *   @0x319cb8 bx lr
 *   @0x319cbc mov r0, #2
 *   @0x319cc0 bx lr
 *
 * ══ §240/321 F_Vertex_Position_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc92a0  size 88  22 条（0xc92a0..0xc92f8）
 * @func 0xc92a0 0xc92f8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType)
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc92a0 push {r3, r4, r5, lr}
 *   @0xc92a4 mov r1, r3
 *   @0xc92a8 ldr r4, [sp, #0x10]
 *   @0xc92ac mov r3, #3
 *   @0xc92b0 mov r2, r4
 *   @0xc92b4 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc92b8 cmp r0, #0
 *   @0xc92bc popeq {r3, r4, r5, pc}
 *   @0xc92c0 mov r1, #1
 *   @0xc92c4 mov r2, #2
 *   @0xc92c8 bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType>
 *   @0xc92cc subs r5, r0, #0
 *   @0xc92d0 popeq {r3, r4, r5, pc}
 *   @0xc92d4 mov r1, #1
 *   @0xc92d8 mov r0, r4
 *   @0xc92dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc92e0 mov r1, #2
 *   @0xc92e4 str r0, [r5]
 *   @0xc92e8 mov r0, r4
 *   @0xc92ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc92f0 str r0, [r5, #0x4]
 *   @0xc92f4 pop {r3, r4, r5, pc}
 *
 * ══ §241/321 F_Vertex_TexCoord_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc9454  size 88  22 条（0xc9454..0xc94ac）
 * @func 0xc9454 0xc94ac  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType)
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9454 push {r3, r4, r5, lr}
 *   @0xc9458 mov r1, r3
 *   @0xc945c ldr r4, [sp, #0x10]
 *   @0xc9460 mov r3, #3
 *   @0xc9464 mov r2, r4
 *   @0xc9468 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc946c cmp r0, #0
 *   @0xc9470 popeq {r3, r4, r5, pc}
 *   @0xc9474 mov r1, #4
 *   @0xc9478 mov r2, #2
 *   @0xc947c bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType>
 *   @0xc9480 subs r5, r0, #0
 *   @0xc9484 popeq {r3, r4, r5, pc}
 *   @0xc9488 mov r1, #1
 *   @0xc948c mov r0, r4
 *   @0xc9490 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc9494 mov r1, #2
 *   @0xc9498 str r0, [r5]
 *   @0xc949c mov r0, r4
 *   @0xc94a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc94a4 str r0, [r5, #0x4]
 *   @0xc94a8 pop {r3, r4, r5, pc}
 *
 * ══ §242/321 IBuffer::IBuffer()  0xcc900  size 88  22 条（0xcc900..0xcc958）
 * @func 0xcc900 0xcc958  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×1 / 0x4×1 / 0xc×1 / 0x10×1 / 0x8×1 / 0x1c×1 / 0x20×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcc900 ldr r12, [pc, #0x4c]
 *   @0xcc904 mov r2, #0
 *   @0xcc908 mov r1, #1
 *   @0xcc90c str r2, [r0, #0x4]
 *   @0xcc910 ldr r12, [pc, r12]
 *   @0xcc914 str r2, [r0, #0xc]
 *   @0xcc918 add r12, r12, #8
 *   @0xcc91c str r2, [r0, #0x10]
 *   @0xcc920 str r12, [r0]
 *   @0xcc924 str r2, [r0, #0x8]
 *   @0xcc928 str r2, [r0, #0x1c]
 *   @0xcc92c str r2, [r0, #0x20]
 *   @0xcc930 str r2, [r0, #0x24]
 *   @0xcc934 str r2, [r0, #0x38]
 *   @0xcc938 str r2, [r0, #0x2c]
 *   @0xcc93c str r2, [r0, #0x30]
 *   @0xcc940 str r2, [r0, #0x28]
 *   @0xcc944 str r1, [r0, #0x14]
 *   @0xcc948 str r1, [r0, #0x18]
 *   @0xcc94c strb r1, [r0, #0x3c]
 *   @0xcc950 bx lr
 *   @0xcc954 ldrshteq r1, [r2], -r12
 *
 * ══ §243/321 IBuffer::Save(char const*, int, int)  0xcd7ac  size 88  22 条（0xcd7ac..0xcd804）
 * @func 0xcd7ac 0xcd804  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::SaveToFileInMemory(char**, int*, int, int, int) / LoadSave::WriteFile(char const*, char const*, int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x-8×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd7ac push {r4, lr}
 *   @0xcd7b0 sub sp, sp, #16
 *   @0xcd7b4 add r12, sp, #16
 *   @0xcd7b8 mov lr, #0
 *   @0xcd7bc str r3, [sp]
 *   @0xcd7c0 mov r4, r1
 *   @0xcd7c4 str lr, [r12, #-0x8]!
 *   @0xcd7c8 mov r3, r2
 *   @0xcd7cc mov r1, r12
 *   @0xcd7d0 str lr, [sp, #0x4]
 *   @0xcd7d4 add r2, sp, #12
 *   @0xcd7d8 bl 0xcd660 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii>
 *   @0xcd7dc ldr r1, [sp, #0x8]
 *   @0xcd7e0 ldr r2, [sp, #0xc]
 *   @0xcd7e4 mov r0, r4
 *   @0xcd7e8 bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i>
 *   @0xcd7ec mov r4, r0
 *   @0xcd7f0 ldr r0, [sp, #0x8]
 *   @0xcd7f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcd7f8 mov r0, r4
 *   @0xcd7fc add sp, sp, #16
 *   @0xcd800 pop {r4, pc}
 *
 * ══ §244/321 dsListAddInt64  0x101c74  size 88  22 条（0x101c74..0x101ccc）
 * @func 0x101c74 0x101ccc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsListAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x20×1 / 0x30×1 / 0x24×1 / 0x34×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101c74 vmov s13, r0
 *   @0x101c78 mov r12, #0
 *   @0x101c7c str lr, [sp, #-0x4]!
 *   @0x101c80 vcvt.f64.s32 d7, s13
 *   @0x101c84 sub sp, sp, #60
 *   @0x101c88 mov r1, r12
 *   @0x101c8c add r0, sp, #8
 *   @0x101c90 mov lr, #10
 *   @0x101c94 strd r2, r3, [sp, #40]
 *   @0x101c98 add r3, sp, #24
 *   @0x101c9c mov r2, r12
 *   @0x101ca0 str r3, [sp]
 *   @0x101ca4 mov r3, #2
 *   @0x101ca8 str r12, [sp, #0x8]
 *   @0x101cac str r12, [sp, #0x20]
 *   @0x101cb0 str r12, [sp, #0x30]
 *   @0x101cb4 vstr d7, [sp, #24]
 *   @0x101cb8 str r12, [sp, #0x24]
 *   @0x101cbc str lr, [sp, #0x34]
 *   @0x101cc0 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_>
 *   @0x101cc4 add sp, sp, #60
 *   @0x101cc8 ldr pc, [sp], #4
 *
 * ══ §245/321 YYGML_instance_destroy(CInstance*, CInstance*, int, YYRValue**)  0x10b1f0  size 88  22 条（0x10b1f0..0x10b248）
 * @func 0x10b1f0 0x10b248  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_instance_destroy(CInstance*, CInstance*, int, YYRValue**)+0x44 / BOOL_RValue(RValue const*) / INT32_RValue(RValue const*)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10b1f0 cmp r2, #1
 *   @0x10b1f4 push {r4, r5, r6, r7, r8, lr}
 *   @0x10b1f8 mov r5, r0
 *   @0x10b1fc mov r6, r1
 *   @0x10b200 mov r4, r3
 *   @0x10b204 ble 0x10b234 <_Z22YYGML_instance_destroyP9CInstanceS0_iPP8YYRValue+0x44>
 *   @0x10b208 ldr r0, [r3, #0x4]
 *   @0x10b20c bl 0xd1294 <_Z11BOOL_RValuePK6RValue>
 *   @0x10b210 mov r7, r0
 *   @0x10b214 ldr r0, [r4]
 *   @0x10b218 bl 0xd11b0 <_Z12INT32_RValuePK6RValue>
 *   @0x10b21c mov r2, r0
 *   @0x10b220 mov r0, r5
 *   @0x10b224 mov r1, r6
 *   @0x10b228 mov r3, r7
 *   @0x10b22c pop {r4, r5, r6, r7, r8, lr}
 *   @0x10b230 b 0x10b12c <_Z17DoInstanceDestroyP9CInstanceS0_ib>
 *   @0x10b234 movne r7, #1
 *   @0x10b238 mvnne r2, #0
 *   @0x10b23c bne 0x10b220 <_Z22YYGML_instance_destroyP9CInstanceS0_iPP8YYRValue+0x30>
 *   @0x10b240 mov r7, r2
 *   @0x10b244 b 0x10b214 <_Z22YYGML_instance_destroyP9CInstanceS0_iPP8YYRValue+0x24>
 *
 * ══ §246/321 F_ArrayLength1D(RValue&, CInstance*, CInstance*, int, RValue*)  0x10dbb8  size 88  22 条（0x10dbb8..0x10dc10）
 * @func 0x10dbb8 0x10dc10  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dbb8 ldr r3, [sp]
 *   @0x10dbbc mov r2, #0
 *   @0x10dbc0 str r2, [r0, #0xc]
 *   @0x10dbc4 ldr r2, [r3, #0xc]
 *   @0x10dbc8 cmp r2, #2
 *   @0x10dbcc beq 0x10dbe0 <_Z15F_ArrayLength1DR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x10dbd0 mov r2, #0
 *   @0x10dbd4 mov r3, #0
 *   @0x10dbd8 stm r0, {r2, r3}
 *   @0x10dbdc bx lr
 *   @0x10dbe0 ldr r3, [r3]
 *   @0x10dbe4 cmp r3, #0
 *   @0x10dbe8 beq 0x10dbd0 <_Z15F_ArrayLength1DR6RValueP9CInstanceS2_iPS_+0x18>
 *   @0x10dbec ldr r3, [r3, #0x4]
 *   @0x10dbf0 cmp r3, #0
 *   @0x10dbf4 beq 0x10dbd0 <_Z15F_ArrayLength1DR6RValueP9CInstanceS2_iPS_+0x18>
 *   @0x10dbf8 ldr r2, [r3]
 *   @0x10dbfc vmov s15, r2
 *   @0x10dc00 vcvt.f64.s32 d7, s15
 *   @0x10dc04 vmov r2, r3, d7
 *   @0x10dc08 stm r0, {r2, r3}
 *   @0x10dc0c bx lr
 *
 * ══ §247/321 F_EventObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x114654  size 88  22 条（0x114654..0x1146ac）
 * @func 0x114654 0x1146ac  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114654 push {r4, r5, r6, r7, r8, lr}
 *   @0x114658 mov r5, r1
 *   @0x11465c ldr r4, [sp, #0x18]
 *   @0x114660 mov r1, #0
 *   @0x114664 mov r8, r2
 *   @0x114668 mov r0, r4
 *   @0x11466c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114670 mov r1, #1
 *   @0x114674 mov r7, r0
 *   @0x114678 mov r0, r4
 *   @0x11467c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114680 mov r1, #2
 *   @0x114684 mov r6, r0
 *   @0x114688 mov r0, r4
 *   @0x11468c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114690 mov r1, r8
 *   @0x114694 mov r2, r7
 *   @0x114698 mov r3, r6
 *   @0x11469c str r0, [sp, #0x18]
 *   @0x1146a0 mov r0, r5
 *   @0x1146a4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1146a8 b 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii>
 *
 * ══ §248/321 F_DateCompareDate(RValue&, CInstance*, CInstance*, int, RValue*)  0x11471c  size 88  22 条（0x11471c..0x114774）
 * @func 0x11471c 0x114774  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11471c push {r3, r4, r5, r6, r7, lr}
 *   @0x114720 mov r5, #0
 *   @0x114724 ldr r6, [sp, #0x18]
 *   @0x114728 mov r1, r5
 *   @0x11472c str r5, [r0, #0xc]
 *   @0x114730 mov r4, r0
 *   @0x114734 mov r0, r6
 *   @0x114738 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11473c mov r1, #1
 *   @0x114740 mov r7, r0
 *   @0x114744 mov r0, r6
 *   @0x114748 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11474c cmp r7, r0
 *   @0x114750 moveq r3, r5
 *   @0x114754 beq 0x114768 <_Z17F_DateCompareDateR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x114758 movgt r3, r5
 *   @0x11475c movle r3, #0
 *   @0x114760 movtgt r3, #0x3ff0
 *   @0x114764 movtle r3, #0xbff0
 *   @0x114768 str r5, [r4]
 *   @0x11476c str r3, [r4, #0x4]
 *   @0x114770 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §249/321 F_DateCurrentDateTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x114ed8  size 88  22 条（0x114ed8..0x114f30）
 * @func 0x114ed8 0x114f40  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67fc
 * 字段偏移 top8: 0xc×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114ed8 mov r3, #0
 *   @0x114edc push {r4, lr}
 *   @0x114ee0 mov r4, r0
 *   @0x114ee4 str r3, [r4, #0xc]
 *   @0x114ee8 mov r0, r3
 *   @0x114eec bl 0xb67fc <time@plt>
 *   @0x114ef0 vmov.f64 d6, #5.000000e-01
 *   @0x114ef4 vldr d5, [pc, #36]
 *   @0x114ef8 vldr d7, [pc, #40]
 *   @0x114efc vmov s7, r0
 *   @0x114f00 vcvt.f64.s32 d4, s7
 *   @0x114f04 vadd.f64 d6, d4, d6
 *   @0x114f08 vdiv.f64 d6, d6, d5
 *   @0x114f0c vadd.f64 d5, d6, d7
 *   @0x114f10 vmov r2, r3, d5
 *   @0x114f14 stm r4, {r2, r3}
 *   @0x114f18 pop {r4, pc}
 *   @0x114f1c nop
 *   @0x114f20 andeq r0, r0, r0
 *   @0x114f24 rscsmi r1, r5, r0, lsl #16
 *   @0x114f28 andeq r0, r0, r0
 *   @0x114f2c sbcsmi pc, r8, r0, asr #16
 *
 * ══ §250/321 F_DateCurrentDate(RValue&, CInstance*, CInstance*, int, RValue*)  0x114f30  size 88  22 条（0x114f30..0x114f88）
 * @func 0x114f30 0x114f98  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67fc
 * 字段偏移 top8: 0xc×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114f30 mov r3, #0
 *   @0x114f34 push {r4, lr}
 *   @0x114f38 mov r4, r0
 *   @0x114f3c str r3, [r4, #0xc]
 *   @0x114f40 mov r0, r3
 *   @0x114f44 bl 0xb67fc <time@plt>
 *   @0x114f48 vmov.f64 d6, #5.000000e-01
 *   @0x114f4c vldr d5, [pc, #36]
 *   @0x114f50 vldr d7, [pc, #40]
 *   @0x114f54 vmov s7, r0
 *   @0x114f58 vcvt.f64.s32 d4, s7
 *   @0x114f5c vadd.f64 d6, d4, d6
 *   @0x114f60 vdiv.f64 d6, d6, d5
 *   @0x114f64 vadd.f64 d5, d6, d7
 *   @0x114f68 vmov r2, r3, d5
 *   @0x114f6c stm r4, {r2, r3}
 *   @0x114f70 pop {r4, pc}
 *   @0x114f74 nop
 *   @0x114f78 andeq r0, r0, r0
 *   @0x114f7c rscsmi r1, r5, r0, lsl #16
 *   @0x114f80 andeq r0, r0, r0
 *   @0x114f84 sbcsmi pc, r8, r0, asr #16
 *
 * ══ §251/321 F_DateCurrentTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x114f88  size 88  22 条（0x114f88..0x114fe0）
 * @func 0x114f88 0x114fe0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67fc
 * 字段偏移 top8: 0xc×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114f88 mov r3, #0
 *   @0x114f8c push {r4, lr}
 *   @0x114f90 mov r4, r0
 *   @0x114f94 str r3, [r4, #0xc]
 *   @0x114f98 mov r0, r3
 *   @0x114f9c bl 0xb67fc <time@plt>
 *   @0x114fa0 vmov.f64 d6, #5.000000e-01
 *   @0x114fa4 vldr d5, [pc, #36]
 *   @0x114fa8 vldr d7, [pc, #40]
 *   @0x114fac vmov s7, r0
 *   @0x114fb0 vcvt.f64.s32 d4, s7
 *   @0x114fb4 vadd.f64 d6, d4, d6
 *   @0x114fb8 vdiv.f64 d6, d6, d5
 *   @0x114fbc vadd.f64 d5, d6, d7
 *   @0x114fc0 vmov r2, r3, d5
 *   @0x114fc4 stm r4, {r2, r3}
 *   @0x114fc8 pop {r4, pc}
 *   @0x114fcc nop
 *   @0x114fd0 andeq r0, r0, r0
 *   @0x114fd4 rscsmi r1, r5, r0, lsl #16
 *   @0x114fd8 andeq r0, r0, r0
 *   @0x114fdc sbcsmi pc, r8, r0, asr #16
 *
 * ══ §252/321 F_TileDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x11e718  size 88  22 条（0x11e718..0x11e770）
 * @func 0x11e718 0x11e770  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileDelete(RValue&, CInstance*, CInstance*, int, RValue*)+0x3c
 * 字段偏移 top8: 0x10×2 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11e718 push {r3, r4, r5, lr}
 *   @0x11e71c mov r1, #0
 *   @0x11e720 ldr r4, [pc, #0x40]
 *   @0x11e724 ldr r0, [sp, #0x10]
 *   @0x11e728 ldr r4, [pc, r4]
 *   @0x11e72c ldr r5, [r4]
 *   @0x11e730 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e734 mov r1, r0
 *   @0x11e738 mov r0, r5
 *   @0x11e73c bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x11e740 subs r1, r0, #0
 *   @0x11e744 blt 0x11e754 <_Z12F_TileDeleteR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x11e748 ldr r0, [r4]
 *   @0x11e74c pop {r3, r4, r5, lr}
 *   @0x11e750 b 0x1af35c <_ZN5CRoom10DeleteTileEi>
 *   @0x11e754 ldr r0, [pc, #0x10]
 *   @0x11e758 mov r1, #0
 *   @0x11e75c pop {r3, r4, r5, lr}
 *   @0x11e760 add r0, pc, r0
 *   @0x11e764 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11e768 eoreq pc, r12, r0, lsl #4
 *   @0x11e76c mlaeq r1, r12, r10, r11
 *
 * ══ §253/321 F_GetLoginAsync(RValue&, CInstance*, CInstance*, int, RValue*)  0x12663c  size 88  22 条（0x12663c..0x126694）
 * @func 0x12663c 0x126694  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / InputQuery::LoginASync(char const*, char const*)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12663c push {r4, r5, r6, lr}
 *   @0x126640 mov r1, #0
 *   @0x126644 ldr r5, [sp, #0x10]
 *   @0x126648 mov r4, r0
 *   @0x12664c mov r0, r5
 *   @0x126650 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126654 mov r1, #1
 *   @0x126658 mov r6, r0
 *   @0x12665c mov r0, r5
 *   @0x126660 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126664 mov r1, r0
 *   @0x126668 mov r0, r6
 *   @0x12666c bl 0xf272c <_ZN10InputQuery10LoginASyncEPKcS1_>
 *   @0x126670 mov r3, #0
 *   @0x126674 str r3, [r4, #0xc]
 *   @0x126678 vmov s15, r0
 *   @0x12667c vcvt.f64.s32 d7, s15
 *   @0x126680 vmov r0, r1, d7
 *   @0x126684 vmov r2, s14
 *   @0x126688 mov r3, r1
 *   @0x12668c stm r4, {r2, r3}
 *   @0x126690 pop {r4, r5, r6, pc}
 *
 * ══ §254/321 F_SpriteDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c148  size 88  22 条（0x12c148..0x12c1a0）
 * @func 0x12c148 0x12c1a0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int) / Sprite_Delete(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c148 push {r3, r4, r5, lr}
 *   @0x12c14c mov r1, #0
 *   @0x12c150 mov r4, r0
 *   @0x12c154 ldr r0, [sp, #0x10]
 *   @0x12c158 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c15c mov r5, r0
 *   @0x12c160 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12c164 cmp r0, #0
 *   @0x12c168 beq 0x12c190 <_Z14F_SpriteDeleteR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12c16c mov r0, r5
 *   @0x12c170 bl 0x1ef1ec <_Z13Sprite_Deletei>
 *   @0x12c174 vmov s15, r0
 *   @0x12c178 vcvt.f64.s32 d7, s15
 *   @0x12c17c vmov r2, r3, d7
 *   @0x12c180 mov r1, #0
 *   @0x12c184 stm r4, {r2, r3}
 *   @0x12c188 str r1, [r4, #0xc]
 *   @0x12c18c pop {r3, r4, r5, pc}
 *   @0x12c190 mov r3, #0
 *   @0x12c194 mov r2, #0
 *   @0x12c198 movt r3, #0xbff0
 *   @0x12c19c b 0x12c180 <_Z14F_SpriteDeleteR6RValueP9CInstanceS2_iPS_+0x38>
 *
 * ══ §255/321 F_BackgroundSetAlphaFromBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c398  size 88  22 条（0x12c398..0x12c3f0）
 * @func 0x12c398 0x12c3f0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Background_Data(int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c398 push {r4, r5, r6, lr}
 *   @0x12c39c mov r1, #0
 *   @0x12c3a0 ldr r4, [sp, #0x10]
 *   @0x12c3a4 mov r0, r4
 *   @0x12c3a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c3ac mov r1, #1
 *   @0x12c3b0 mov r5, r0
 *   @0x12c3b4 mov r0, r4
 *   @0x12c3b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c3bc mov r6, r0
 *   @0x12c3c0 mov r0, r5
 *   @0x12c3c4 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c3c8 mov r4, r0
 *   @0x12c3cc mov r0, r6
 *   @0x12c3d0 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c3d4 cmp r0, #0
 *   @0x12c3d8 cmpne r4, #0
 *   @0x12c3dc mov r1, r0
 *   @0x12c3e0 popeq {r4, r5, r6, pc}
 *   @0x12c3e4 mov r0, r4
 *   @0x12c3e8 pop {r4, r5, r6, lr}
 *   @0x12c3ec b 0xc1f50 <_ZN11CBackground22SetAlphaFromBackgroundEPS_>
 *
 * ══ §256/321 F_SoundExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cba4  size 88  22 条（0x12cba4..0x12cbfc）
 * @func 0x12cba4 0x12cbfc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_Exists(int) / Sound_Exists(int)
 * 字段偏移 top8: 0x8×1 / 0x38×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cba4 push {r4, lr}
 *   @0x12cba8 mov r1, #0
 *   @0x12cbac mov r4, r0
 *   @0x12cbb0 ldr r0, [sp, #0x8]
 *   @0x12cbb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cbb8 ldr r3, [pc, #0x38]
 *   @0x12cbbc ldr r3, [pc, r3]
 *   @0x12cbc0 ldrb r3, [r3]
 *   @0x12cbc4 cmp r3, #0
 *   @0x12cbc8 beq 0x12cbf0 <_Z13F_SoundExistsR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12cbcc bl 0x217260 <_Z12Audio_Existsi>
 *   @0x12cbd0 cmp r0, #0
 *   @0x12cbd4 mov r3, #0
 *   @0x12cbd8 str r3, [r4, #0xc]
 *   @0x12cbdc movne r0, r3
 *   @0x12cbe0 moveq r3, r0
 *   @0x12cbe4 movtne r3, #0x3ff0
 *   @0x12cbe8 stm r4, {r0, r3}
 *   @0x12cbec pop {r4, pc}
 *   @0x12cbf0 bl 0x21fbd0 <_Z12Sound_Existsi>
 *   @0x12cbf4 b 0x12cbd0 <_Z13F_SoundExistsR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x12cbf8 eoreq r2, r12, r4, ror r1
 *
 * ══ §257/321 F_SoundGetPreload(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cc50  size 88  22 条（0x12cc50..0x12cca8）
 * @func 0x12cc50 0x12cca8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sound_Data(int)
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cc50 push {r4, lr}
 *   @0x12cc54 mov r1, #0
 *   @0x12cc58 mov r4, r0
 *   @0x12cc5c ldr r0, [sp, #0x8]
 *   @0x12cc60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cc64 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x12cc68 cmp r0, #0
 *   @0x12cc6c beq 0x12cca0 <_Z17F_SoundGetPreloadR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x12cc70 ldrb r2, [r0, #0x14]
 *   @0x12cc74 mov r3, #0
 *   @0x12cc78 str r3, [r4, #0xc]
 *   @0x12cc7c cmp r2, r3
 *   @0x12cc80 movne r2, #0
 *   @0x12cc84 movtne r2, #0x3ff0
 *   @0x12cc88 bne 0x12cc94 <_Z17F_SoundGetPreloadR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x12cc8c mov r3, #0
 *   @0x12cc90 mov r2, r3
 *   @0x12cc94 str r3, [r4]
 *   @0x12cc98 str r2, [r4, #0x4]
 *   @0x12cc9c pop {r4, pc}
 *   @0x12cca0 str r0, [r4, #0xc]
 *   @0x12cca4 b 0x12cc8c <_Z17F_SoundGetPreloadR6RValueP9CInstanceS2_iPS_+0x3c>
 *
 * ══ §258/321 F_FontGetBold(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cdd8  size 88  22 条（0x12cdd8..0x12ce30）
 * @func 0x12cdd8 0x12ce40  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Data(int) / CFontGM::GetBold()
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cdd8 push {r4, lr}
 *   @0x12cddc mov r1, #0
 *   @0x12cde0 mov r4, r0
 *   @0x12cde4 ldr r0, [sp, #0x8]
 *   @0x12cde8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cdec bl 0xfa3fc <_Z9Font_Datai>
 *   @0x12cdf0 subs r3, r0, #0
 *   @0x12cdf4 beq 0x12ce20 <_Z13F_FontGetBoldR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12cdf8 bl 0xf93d8 <_ZN7CFontGM7GetBoldEv>
 *   @0x12cdfc mov r3, #0
 *   @0x12ce00 str r3, [r4, #0xc]
 *   @0x12ce04 cmp r0, r3
 *   @0x12ce08 movne r2, #0
 *   @0x12ce0c movtne r2, #0x3ff0
 *   @0x12ce10 beq 0x12ce24 <_Z13F_FontGetBoldR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12ce14 str r3, [r4]
 *   @0x12ce18 str r2, [r4, #0x4]
 *   @0x12ce1c pop {r4, pc}
 *   @0x12ce20 str r3, [r4, #0xc]
 *   @0x12ce24 mov r3, #0
 *   @0x12ce28 mov r2, r3
 *   @0x12ce2c b 0x12ce14 <_Z13F_FontGetBoldR6RValueP9CInstanceS2_iPS_+0x3c>
 *
 * ══ §259/321 F_FontGetItalic(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ce30  size 88  22 条（0x12ce30..0x12ce88）
 * @func 0x12ce30 0x12ce88  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Data(int) / CFontGM::GetItalic()
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ce30 push {r4, lr}
 *   @0x12ce34 mov r1, #0
 *   @0x12ce38 mov r4, r0
 *   @0x12ce3c ldr r0, [sp, #0x8]
 *   @0x12ce40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ce44 bl 0xfa3fc <_Z9Font_Datai>
 *   @0x12ce48 subs r3, r0, #0
 *   @0x12ce4c beq 0x12ce78 <_Z15F_FontGetItalicR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12ce50 bl 0xf93e0 <_ZN7CFontGM9GetItalicEv>
 *   @0x12ce54 mov r3, #0
 *   @0x12ce58 str r3, [r4, #0xc]
 *   @0x12ce5c cmp r0, r3
 *   @0x12ce60 movne r2, #0
 *   @0x12ce64 movtne r2, #0x3ff0
 *   @0x12ce68 beq 0x12ce7c <_Z15F_FontGetItalicR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12ce6c str r3, [r4]
 *   @0x12ce70 str r2, [r4, #0x4]
 *   @0x12ce74 pop {r4, pc}
 *   @0x12ce78 str r3, [r4, #0xc]
 *   @0x12ce7c mov r3, #0
 *   @0x12ce80 mov r2, r3
 *   @0x12ce84 b 0x12ce6c <_Z15F_FontGetItalicR6RValueP9CInstanceS2_iPS_+0x3c>
 *
 * ══ §260/321 F_PathGetClosed(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d58c  size 88  22 条（0x12d58c..0x12d5e4）
 * @func 0x12d58c 0x12d5e4  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / CPath::GetClosed()
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d58c push {r4, lr}
 *   @0x12d590 mov r1, #0
 *   @0x12d594 mov r4, r0
 *   @0x12d598 ldr r0, [sp, #0x8]
 *   @0x12d59c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d5a0 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d5a4 subs r3, r0, #0
 *   @0x12d5a8 beq 0x12d5d4 <_Z15F_PathGetClosedR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12d5ac bl 0x1a7bd8 <_ZN5CPath9GetClosedEv>
 *   @0x12d5b0 mov r3, #0
 *   @0x12d5b4 str r3, [r4, #0xc]
 *   @0x12d5b8 cmp r0, r3
 *   @0x12d5bc movne r2, #0
 *   @0x12d5c0 movtne r2, #0x3ff0
 *   @0x12d5c4 beq 0x12d5d8 <_Z15F_PathGetClosedR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12d5c8 str r3, [r4]
 *   @0x12d5cc str r2, [r4, #0x4]
 *   @0x12d5d0 pop {r4, pc}
 *   @0x12d5d4 str r3, [r4, #0xc]
 *   @0x12d5d8 mov r3, #0
 *   @0x12d5dc mov r2, r3
 *   @0x12d5e0 b 0x12d5c8 <_Z15F_PathGetClosedR6RValueP9CInstanceS2_iPS_+0x3c>
 *
 * ══ §261/321 F_RoomDuplicate(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e7ec  size 88  22 条（0x12e7ec..0x12e844）
 * @func 0x12e7ec 0x12e844  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Data(int) / Room_Duplicate(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e7ec push {r3, r4, r5, lr}
 *   @0x12e7f0 mov r1, #0
 *   @0x12e7f4 mov r4, r0
 *   @0x12e7f8 ldr r0, [sp, #0x10]
 *   @0x12e7fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e800 mov r5, r0
 *   @0x12e804 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e808 cmp r0, #0
 *   @0x12e80c beq 0x12e834 <_Z15F_RoomDuplicateR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12e810 mov r0, r5
 *   @0x12e814 bl 0x1b56e0 <_Z14Room_Duplicatei>
 *   @0x12e818 vmov s15, r0
 *   @0x12e81c vcvt.f64.s32 d7, s15
 *   @0x12e820 vmov r2, r3, d7
 *   @0x12e824 mov r1, #0
 *   @0x12e828 stm r4, {r2, r3}
 *   @0x12e82c str r1, [r4, #0xc]
 *   @0x12e830 pop {r3, r4, r5, pc}
 *   @0x12e834 mov r3, #0
 *   @0x12e838 mov r2, #0
 *   @0x12e83c movt r3, #0xbff0
 *   @0x12e840 b 0x12e824 <_Z15F_RoomDuplicateR6RValueP9CInstanceS2_iPS_+0x38>
 *
 * ══ §262/321 F_AudioMusicIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*)  0x133a74  size 88  22 条（0x133a74..0x133acc）
 * @func 0x133a74 0x133acc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×2 / 0xc×2 / 0x3c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133a74 push {r3, r4, r5, lr}
 *   @0x133a78 mov r5, r0
 *   @0x133a7c ldr r3, [pc, #0x3c]
 *   @0x133a80 ldr r3, [pc, r3]
 *   @0x133a84 ldrb r4, [r3]
 *   @0x133a88 cmp r4, #0
 *   @0x133a8c popne {r3, r4, r5, pc}
 *   @0x133a90 ldr r3, [pc, #0x2c]
 *   @0x133a94 ldr r1, [pc, #0x2c]
 *   @0x133a98 ldr r3, [pc, r3]
 *   @0x133a9c add r1, pc, r1
 *   @0x133aa0 ldr r0, [r3]
 *   @0x133aa4 ldr r3, [r0]
 *   @0x133aa8 ldr r3, [r3, #0xc]
 *   @0x133aac blx r3
 *   @0x133ab0 str r4, [r5, #0xc]
 *   @0x133ab4 str r4, [r5]
 *   @0x133ab8 str r4, [r5, #0x4]
 *   @0x133abc pop {r3, r4, r5, pc}
 *   @0x133ac0 eoreq r11, r11, r12, asr #11
 *   @0x133ac4 eoreq r9, r11, r12, ror r12
 *   @0x133ac8 mlaeq r0, r4, r9, r11
 *
 * ══ §263/321 F_AudioCreateSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x135f1c  size 88  22 条（0x135f1c..0x135f74）
 * @func 0x135f1c 0x135f74  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_CreateSyncGroup(bool)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135f1c ldr r3, [pc, #0x4c]
 *   @0x135f20 push {r4, lr}
 *   @0x135f24 ldr r3, [pc, r3]
 *   @0x135f28 mov r4, r0
 *   @0x135f2c ldrb r1, [r3]
 *   @0x135f30 cmp r1, #0
 *   @0x135f34 popne {r4, pc}
 *   @0x135f38 str r1, [r0, #0xc]
 *   @0x135f3c ldr r0, [sp, #0x8]
 *   @0x135f40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135f44 cmp r0, #0
 *   @0x135f48 movle r0, #0
 *   @0x135f4c movgt r0, #1
 *   @0x135f50 bl 0x21d3c4 <_Z21Audio_CreateSyncGroupb>
 *   @0x135f54 vmov s15, r0
 *   @0x135f58 vcvt.f64.s32 d7, s15
 *   @0x135f5c vmov r0, r1, d7
 *   @0x135f60 vmov r2, s14
 *   @0x135f64 mov r3, r1
 *   @0x135f68 stm r4, {r2, r3}
 *   @0x135f6c pop {r4, pc}
 *   @0x135f70 eoreq r9, r11, r8, lsr #2
 *
 * ══ §264/321 F_FileFindNext(RValue&, CInstance*, CInstance*, int, RValue*)  0x13927c  size 88  22 条（0x13927c..0x1392d4）
 * @func 0x13927c 0x1392d4  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x28×1 / 0x4×1 / 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13927c ldr r3, [pc, #0x48]
 *   @0x139280 mov r1, #0
 *   @0x139284 str r1, [r0]
 *   @0x139288 mov r1, #1
 *   @0x13928c ldr r3, [pc, r3]
 *   @0x139290 str r1, [r0, #0xc]
 *   @0x139294 ldrb r3, [r3]
 *   @0x139298 cmp r3, #0
 *   @0x13929c bxeq lr
 *   @0x1392a0 ldr r3, [pc, #0x28]
 *   @0x1392a4 ldr r3, [pc, r3]
 *   @0x1392a8 ldr r2, [r3]
 *   @0x1392ac ldr r1, [r3, #0x4]
 *   @0x1392b0 add r2, r2, #1
 *   @0x1392b4 str r2, [r3]
 *   @0x1392b8 cmp r2, r1
 *   @0x1392bc bxge lr
 *   @0x1392c0 ldr r3, [r3, #0x8]
 *   @0x1392c4 ldr r1, [r3, r2, lsl #2]
 *   @0x1392c8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1392cc .word 0x002b5ff8
 *   @0x1392d0 eoreq r5, r11, r4, ror #31
 *
 * ══ §265/321 F_FileReadReal(RValue&, CInstance*, CInstance*, int, RValue*)  0x139c70  size 88  22 条（0x139c70..0x139cc8）
 * @func 0x139c70 0x139cd8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0x30×1 / 0x24×1 / 0xc×1 / 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139c70 ldr r3, [pc, #0x40]
 *   @0x139c74 ldr r3, [pc, r3]
 *   @0x139c78 ldr r3, [r3]
 *   @0x139c7c cmp r3, #1
 *   @0x139c80 beq 0x139c94 <_Z14F_FileReadRealR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x139c84 ldr r0, [pc, #0x30]
 *   @0x139c88 mov r1, #0
 *   @0x139c8c add r0, pc, r0
 *   @0x139c90 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139c94 ldr r3, [pc, #0x24]
 *   @0x139c98 mov r1, #0
 *   @0x139c9c str r1, [r0, #0xc]
 *   @0x139ca0 mov r2, r0
 *   @0x139ca4 ldr r3, [pc, r3]
 *   @0x139ca8 ldr r1, [pc, #0x14]
 *   @0x139cac ldr r0, [r3, #0x8]
 *   @0x139cb0 add r1, pc, r1
 *   @0x139cb4 b 0xb688c <fscanf@plt>
 *   @0x139cb8 .word 0x002b55fc
 *   @0x139cbc eoreq r6, r0, r8, ror #10
 *   @0x139cc0 .word 0x002b55d0
 *   @0x139cc4 eoreq r6, r0, r4, ror #10
 *
 * ══ §266/321 YYGML_ini_close()  0x13b988  size 88  22 条（0x13b988..0x13b9e0）
 * @func 0x13b988 0x13b9e0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::WriteIniFile() / IniFile::~IniFile() / operator delete(void*)
 * 字段偏移 top8: 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13b988 push {r4, r5, r6, lr}
 *   @0x13b98c ldr r4, [pc, #0x48]
 *   @0x13b990 ldr r4, [pc, r4]
 *   @0x13b994 ldr r0, [r4]
 *   @0x13b998 cmp r0, #0
 *   @0x13b99c beq 0x13b9d4 <_Z15YYGML_ini_closev+0x4c>
 *   @0x13b9a0 bl 0x235d3c <_ZN7IniFile12WriteIniFileEv>
 *   @0x13b9a4 ldr r5, [r4]
 *   @0x13b9a8 cmp r5, #0
 *   @0x13b9ac mov r6, r0
 *   @0x13b9b0 beq 0x13b9c4 <_Z15YYGML_ini_closev+0x3c>
 *   @0x13b9b4 mov r0, r5
 *   @0x13b9b8 bl 0x235428 <_ZN7IniFileD2Ev>
 *   @0x13b9bc mov r0, r5
 *   @0x13b9c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x13b9c4 mov r3, #0
 *   @0x13b9c8 str r3, [r4]
 *   @0x13b9cc mov r0, r6
 *   @0x13b9d0 pop {r4, r5, r6, pc}
 *   @0x13b9d4 mov r6, r0
 *   @0x13b9d8 b 0x13b9cc <_Z15YYGML_ini_closev+0x44>
 *   @0x13b9dc eoreq r3, r11, r4, lsl #18
 *
 * ══ §267/321 F_ActionSetHspeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x13da28  size 88  22 条（0x13da28..0x13da80）
 * @func 0x13da28 0x13da80  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x38×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13da28 push {r4, lr}
 *   @0x13da2c mov r4, r1
 *   @0x13da30 ldr r0, [sp, #0x8]
 *   @0x13da34 mov r1, #0
 *   @0x13da38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13da3c ldr r3, [pc, #0x38]
 *   @0x13da40 ldr r3, [pc, r3]
 *   @0x13da44 ldrb r3, [r3]
 *   @0x13da48 cmp r3, #0
 *   @0x13da4c vmov s15, r0
 *   @0x13da50 bne 0x13da64 <_Z17F_ActionSetHspeedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x13da54 mov r0, r4
 *   @0x13da58 vmov r1, s15
 *   @0x13da5c pop {r4, lr}
 *   @0x13da60 b 0x1930f4 <_ZN9CInstance9SetHspeedEf>
 *   @0x13da64 vldr s14, [r4, #224]
 *   @0x13da68 vadd.f32 s14, s15, s14
 *   @0x13da6c mov r0, r4
 *   @0x13da70 pop {r4, lr}
 *   @0x13da74 vmov r1, s14
 *   @0x13da78 b 0x1930f4 <_ZN9CInstance9SetHspeedEf>
 *   @0x13da7c .word 0x002b00fc
 *
 * ══ §268/321 F_ActionSetVspeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x13da90  size 88  22 条（0x13da90..0x13dae8）
 * @func 0x13da90 0x13dae8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x38×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13da90 push {r4, lr}
 *   @0x13da94 mov r4, r1
 *   @0x13da98 ldr r0, [sp, #0x8]
 *   @0x13da9c mov r1, #0
 *   @0x13daa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13daa4 ldr r3, [pc, #0x38]
 *   @0x13daa8 ldr r3, [pc, r3]
 *   @0x13daac ldrb r3, [r3]
 *   @0x13dab0 cmp r3, #0
 *   @0x13dab4 vmov s15, r0
 *   @0x13dab8 bne 0x13dacc <_Z17F_ActionSetVspeedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x13dabc mov r0, r4
 *   @0x13dac0 vmov r1, s15
 *   @0x13dac4 pop {r4, lr}
 *   @0x13dac8 b 0x193114 <_ZN9CInstance9SetVspeedEf>
 *   @0x13dacc vldr s14, [r4, #228]
 *   @0x13dad0 vadd.f32 s14, s15, s14
 *   @0x13dad4 mov r0, r4
 *   @0x13dad8 pop {r4, lr}
 *   @0x13dadc vmov r1, s14
 *   @0x13dae0 b 0x193114 <_ZN9CInstance9SetVspeedEf>
 *   @0x13dae4 mlaeq r11, r4, r0, r0
 *
 * ══ §269/321 F_ActionPathPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e0dc  size 88  22 条（0x13e0dc..0x13e134）
 * @func 0x13e0dc 0x13e144  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x38×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e0dc push {r4, lr}
 *   @0x13e0e0 mov r4, r1
 *   @0x13e0e4 ldr r0, [sp, #0x8]
 *   @0x13e0e8 mov r1, #0
 *   @0x13e0ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e0f0 ldr r3, [pc, #0x38]
 *   @0x13e0f4 ldr r3, [pc, r3]
 *   @0x13e0f8 ldrb r3, [r3]
 *   @0x13e0fc cmp r3, #0
 *   @0x13e100 vmov s15, r0
 *   @0x13e104 bne 0x13e118 <_Z20F_ActionPathPositionR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x13e108 mov r0, r4
 *   @0x13e10c vmov r1, s15
 *   @0x13e110 pop {r4, lr}
 *   @0x13e114 b 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x13e118 vldr s14, [r4, #300]
 *   @0x13e11c vadd.f32 s14, s15, s14
 *   @0x13e120 mov r0, r4
 *   @0x13e124 pop {r4, lr}
 *   @0x13e128 vmov r1, s14
 *   @0x13e12c b 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x13e130 eoreq pc, r10, r8, asr #20
 *
 * ══ §270/321 F_ActionPathSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e134  size 88  22 条（0x13e134..0x13e18c）
 * @func 0x13e134 0x13e18c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x38×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e134 push {r4, lr}
 *   @0x13e138 mov r4, r1
 *   @0x13e13c ldr r0, [sp, #0x8]
 *   @0x13e140 mov r1, #0
 *   @0x13e144 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e148 ldr r3, [pc, #0x38]
 *   @0x13e14c ldr r3, [pc, r3]
 *   @0x13e150 ldrb r3, [r3]
 *   @0x13e154 cmp r3, #0
 *   @0x13e158 vmov s15, r0
 *   @0x13e15c bne 0x13e170 <_Z17F_ActionPathSpeedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x13e160 mov r0, r4
 *   @0x13e164 vmov r1, s15
 *   @0x13e168 pop {r4, lr}
 *   @0x13e16c b 0x193634 <_ZN9CInstance12SetPathSpeedEf>
 *   @0x13e170 vldr s14, [r4, #308]
 *   @0x13e174 vadd.f32 s14, s15, s14
 *   @0x13e178 mov r0, r4
 *   @0x13e17c pop {r4, lr}
 *   @0x13e180 vmov r1, s14
 *   @0x13e184 b 0x193634 <_ZN9CInstance12SetPathSpeedEf>
 *   @0x13e188 .word 0x002af9f0
 *
 * ══ §271/321 F_D3DModelLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*)  0x145334  size 88  22 条（0x145334..0x14538c）
 * @func 0x145334 0x14538c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x44×1 / 0x10×1 / 0x3c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145334 push {r3, r4, r5, lr}
 *   @0x145338 ldr r3, [pc, #0x44]
 *   @0x14533c ldr r4, [sp, #0x10]
 *   @0x145340 ldr r3, [pc, r3]
 *   @0x145344 ldr r1, [pc, #0x3c]
 *   @0x145348 ldr r0, [r3]
 *   @0x14534c add r1, pc, r1
 *   @0x145350 ldr r3, [r0]
 *   @0x145354 ldr r3, [r3, #0xc]
 *   @0x145358 blx r3
 *   @0x14535c mov r0, r4
 *   @0x145360 mov r1, #1
 *   @0x145364 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145368 mov r1, #0
 *   @0x14536c mov r5, r0
 *   @0x145370 mov r0, r4
 *   @0x145374 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145378 mov r1, r5
 *   @0x14537c pop {r3, r4, r5, lr}
 *   @0x145380 b 0x165298 <_Z21GR_3DM_LoadFromBufferii>
 *   @0x145384 .word 0x002a83d4
 *   @0x145388 andseq r12, pc, r8, lsl #5
 *
 * ══ §272/321 F_GPUSetBlendEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x146598  size 88  22 条（0x146598..0x1465f0）
 * @func 0x146598 0x146600  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146598 cmp r3, #1
 *   @0x14659c push {r3, lr}
 *   @0x1465a0 mov r3, #0
 *   @0x1465a4 mov r1, r3
 *   @0x1465a8 movt r3, #0xbff0
 *   @0x1465ac str r1, [r0, #0xc]
 *   @0x1465b0 stm r0, {r1, r3}
 *   @0x1465b4 ldr r0, [sp, #0x8]
 *   @0x1465b8 beq 0x1465cc <_Z19F_GPUSetBlendEnableR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1465bc ldr r0, [pc, #0x24]
 *   @0x1465c0 pop {r3, lr}
 *   @0x1465c4 add r0, pc, r0
 *   @0x1465c8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1465cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1465d0 ldr r3, [pc, #0x14]
 *   @0x1465d4 mov r1, #12
 *   @0x1465d8 mov r2, r0
 *   @0x1465dc ldr r0, [pc, r3]
 *   @0x1465e0 pop {r3, lr}
 *   @0x1465e4 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1465e8 andseq r11, pc, r0, asr #1
 *   @0x1465ec eoreq r7, r10, r12, lsl r7
 *
 * ══ §273/321 F_GPUSetZFunc(RValue&, CInstance*, CInstance*, int, RValue*)  0x14664c  size 88  22 条（0x14664c..0x1466a4）
 * @func 0x14664c 0x1466b4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14664c cmp r3, #1
 *   @0x146650 push {r3, lr}
 *   @0x146654 mov r3, #0
 *   @0x146658 mov r1, r3
 *   @0x14665c movt r3, #0xbff0
 *   @0x146660 str r1, [r0, #0xc]
 *   @0x146664 stm r0, {r1, r3}
 *   @0x146668 ldr r0, [sp, #0x8]
 *   @0x14666c beq 0x146680 <_Z13F_GPUSetZFuncR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x146670 ldr r0, [pc, #0x24]
 *   @0x146674 pop {r3, lr}
 *   @0x146678 add r0, pc, r0
 *   @0x14667c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146680 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x146684 ldr r3, [pc, #0x14]
 *   @0x146688 mov r1, #9
 *   @0x14668c mov r2, r0
 *   @0x146690 ldr r0, [pc, r3]
 *   @0x146694 pop {r3, lr}
 *   @0x146698 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x14669c ldrheq r11, [pc], -r12
 *   @0x1466a0 eoreq r7, r10, r8, ror #12
 *
 * ══ §274/321 F_GPUSetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x1466a4  size 88  22 条（0x1466a4..0x1466fc）
 * @func 0x1466a4 0x14670c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1466a4 cmp r3, #1
 *   @0x1466a8 push {r3, lr}
 *   @0x1466ac mov r3, #0
 *   @0x1466b0 mov r1, r3
 *   @0x1466b4 movt r3, #0xbff0
 *   @0x1466b8 str r1, [r0, #0xc]
 *   @0x1466bc stm r0, {r1, r3}
 *   @0x1466c0 ldr r0, [sp, #0x8]
 *   @0x1466c4 beq 0x1466d8 <_Z20F_GPUSetZWriteEnableR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1466c8 ldr r0, [pc, #0x24]
 *   @0x1466cc pop {r3, lr}
 *   @0x1466d0 add r0, pc, r0
 *   @0x1466d4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1466d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1466dc ldr r3, [pc, #0x14]
 *   @0x1466e0 mov r1, #4
 *   @0x1466e4 mov r2, r0
 *   @0x1466e8 ldr r0, [pc, r3]
 *   @0x1466ec pop {r3, lr}
 *   @0x1466f0 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1466f4 mulseq pc, r12, r0
 *   @0x1466f8 eoreq r7, r10, r0, lsl r6
 *
 * ══ §275/321 F_GPUSetCullmode(RValue&, CInstance*, CInstance*, int, RValue*)  0x1466fc  size 88  22 条（0x1466fc..0x146754）
 * @func 0x1466fc 0x146754  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1466fc cmp r3, #1
 *   @0x146700 push {r3, lr}
 *   @0x146704 mov r3, #0
 *   @0x146708 mov r1, r3
 *   @0x14670c movt r3, #0xbff0
 *   @0x146710 str r1, [r0, #0xc]
 *   @0x146714 stm r0, {r1, r3}
 *   @0x146718 ldr r0, [sp, #0x8]
 *   @0x14671c beq 0x146730 <_Z16F_GPUSetCullmodeR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x146720 ldr r0, [pc, #0x24]
 *   @0x146724 pop {r3, lr}
 *   @0x146728 add r0, pc, r0
 *   @0x14672c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146730 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x146734 ldr r3, [pc, #0x14]
 *   @0x146738 mov r1, #8
 *   @0x14673c mov r2, r0
 *   @0x146740 ldr r0, [pc, r3]
 *   @0x146744 pop {r3, lr}
 *   @0x146748 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x14674c andseq r11, pc, r0, lsr #1
 *   @0x146750 .word 0x002a75b8
 *
 * ══ §276/321 F_GPUSetAlphaTestEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x1468d4  size 88  22 条（0x1468d4..0x14692c）
 * @func 0x1468d4 0x14693c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1468d4 cmp r3, #1
 *   @0x1468d8 push {r3, lr}
 *   @0x1468dc mov r3, #0
 *   @0x1468e0 mov r1, r3
 *   @0x1468e4 movt r3, #0xbff0
 *   @0x1468e8 str r1, [r0, #0xc]
 *   @0x1468ec stm r0, {r1, r3}
 *   @0x1468f0 ldr r0, [sp, #0x8]
 *   @0x1468f4 beq 0x146908 <_Z23F_GPUSetAlphaTestEnableR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1468f8 ldr r0, [pc, #0x24]
 *   @0x1468fc pop {r3, lr}
 *   @0x146900 add r0, pc, r0
 *   @0x146904 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146908 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14690c ldr r3, [pc, #0x14]
 *   @0x146910 mov r1, #5
 *   @0x146914 mov r2, r0
 *   @0x146918 ldr r0, [pc, r3]
 *   @0x14691c pop {r3, lr}
 *   @0x146920 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146924 andseq r10, pc, r0, asr #30
 *   @0x146928 eoreq r7, r10, r0, ror #7
 *
 * ══ §277/321 F_GPUSetAlphaTestRef(RValue&, CInstance*, CInstance*, int, RValue*)  0x14692c  size 88  22 条（0x14692c..0x146984）
 * @func 0x14692c 0x146994  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14692c cmp r3, #1
 *   @0x146930 push {r3, lr}
 *   @0x146934 mov r3, #0
 *   @0x146938 mov r1, r3
 *   @0x14693c movt r3, #0xbff0
 *   @0x146940 str r1, [r0, #0xc]
 *   @0x146944 stm r0, {r1, r3}
 *   @0x146948 ldr r0, [sp, #0x8]
 *   @0x14694c beq 0x146960 <_Z20F_GPUSetAlphaTestRefR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x146950 ldr r0, [pc, #0x24]
 *   @0x146954 pop {r3, lr}
 *   @0x146958 add r0, pc, r0
 *   @0x14695c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146960 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x146964 ldr r3, [pc, #0x14]
 *   @0x146968 mov r1, #10
 *   @0x14696c mov r2, r0
 *   @0x146970 ldr r0, [pc, r3]
 *   @0x146974 pop {r3, lr}
 *   @0x146978 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x14697c andseq r10, pc, r8, ror #29
 *   @0x146980 eoreq r7, r10, r8, lsl #7
 *
 * ══ §278/321 F_GPUSetAlphaTestFunc(RValue&, CInstance*, CInstance*, int, RValue*)  0x146984  size 88  22 条（0x146984..0x1469dc）
 * @func 0x146984 0x1469dc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146984 cmp r3, #1
 *   @0x146988 push {r3, lr}
 *   @0x14698c mov r3, #0
 *   @0x146990 mov r1, r3
 *   @0x146994 movt r3, #0xbff0
 *   @0x146998 str r1, [r0, #0xc]
 *   @0x14699c stm r0, {r1, r3}
 *   @0x1469a0 ldr r0, [sp, #0x8]
 *   @0x1469a4 beq 0x1469b8 <_Z21F_GPUSetAlphaTestFuncR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1469a8 ldr r0, [pc, #0x24]
 *   @0x1469ac pop {r3, lr}
 *   @0x1469b0 add r0, pc, r0
 *   @0x1469b4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1469b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1469bc ldr r3, [pc, #0x14]
 *   @0x1469c0 mov r1, #11
 *   @0x1469c4 mov r2, r0
 *   @0x1469c8 ldr r0, [pc, r3]
 *   @0x1469cc pop {r3, lr}
 *   @0x1469d0 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1469d4 andseq r10, pc, r12, ror #29
 *   @0x1469d8 eoreq r7, r10, r0, lsr r3
 *
 * ══ §279/321 F_GPUSetLightingEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x149e10  size 88  22 条（0x149e10..0x149e68）
 * @func 0x149e10 0x149e68  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149e10 cmp r3, #1
 *   @0x149e14 push {r3, lr}
 *   @0x149e18 mov r3, #0
 *   @0x149e1c mov r1, r3
 *   @0x149e20 movt r3, #0xbff0
 *   @0x149e24 str r1, [r0, #0xc]
 *   @0x149e28 stm r0, {r1, r3}
 *   @0x149e2c ldr r0, [sp, #0x8]
 *   @0x149e30 beq 0x149e44 <_Z22F_GPUSetLightingEnableR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x149e34 ldr r0, [pc, #0x24]
 *   @0x149e38 pop {r3, lr}
 *   @0x149e3c add r0, pc, r0
 *   @0x149e40 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149e44 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x149e48 ldr r3, [pc, #0x14]
 *   @0x149e4c mov r1, #21
 *   @0x149e50 mov r2, r0
 *   @0x149e54 ldr r0, [pc, r3]
 *   @0x149e58 pop {r3, lr}
 *   @0x149e5c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x149e60 mulseq pc, r8, r11
 *   @0x149e64 eoreq r3, r10, r4, lsr #29
 *
 * ══ §280/321 Push_InitQueue()  0x155ba0  size 88  22 条（0x155ba0..0x155bf8）
 * @func 0x155ba0 0x155bf8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / Mutex::Mutex(char const*)
 * 字段偏移 top8: 0x40×1 / 0x28×1 / 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155ba0 push {r4, r5, r6, lr}
 *   @0x155ba4 ldr r4, [pc, #0x40]
 *   @0x155ba8 add r4, pc, r4
 *   @0x155bac ldrb r5, [r4]
 *   @0x155bb0 cmp r5, #0
 *   @0x155bb4 popne {r4, r5, r6, pc}
 *   @0x155bb8 mov r0, #8
 *   @0x155bbc bl 0x27c524 <_Znwj>
 *   @0x155bc0 ldr r1, [pc, #0x28]
 *   @0x155bc4 add r1, pc, r1
 *   @0x155bc8 mov r6, r0
 *   @0x155bcc bl 0x27e070 <_ZN5MutexC2EPKc>
 *   @0x155bd0 ldr r3, [pc, #0x1c]
 *   @0x155bd4 mov r2, #1
 *   @0x155bd8 str r6, [r4, #0x4]
 *   @0x155bdc ldr r3, [pc, r3]
 *   @0x155be0 strb r2, [r4]
 *   @0x155be4 str r5, [r3]
 *   @0x155be8 pop {r4, r5, r6, pc}
 *   @0x155bec ldrhteq lr, [r2], -r4
 *   @0x155bf0 andseq r0, pc, r8, asr #16
 *   @0x155bf4 eoreq r9, r9, r8, lsr pc
 *
 * ══ §281/321 F_YoYo_AchievementEvent(RValue&, CInstance*, CInstance*, int, RValue*)  0x156b50  size 88  22 条（0x156b50..0x156ba8）
 * @func 0x156b50 0x156ba8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x40×2 / 0xc×2 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156b50 push {r3, r4, r5, lr}
 *   @0x156b54 mov r4, r0
 *   @0x156b58 ldr r3, [pc, #0x40]
 *   @0x156b5c ldr r1, [pc, #0x40]
 *   @0x156b60 ldr r3, [pc, r3]
 *   @0x156b64 ldr r5, [sp, #0x10]
 *   @0x156b68 add r1, pc, r1
 *   @0x156b6c ldr r0, [r3]
 *   @0x156b70 ldr r2, [r0]
 *   @0x156b74 ldr r3, [r2, #0xc]
 *   @0x156b78 blx r3
 *   @0x156b7c mov r3, #0
 *   @0x156b80 mov r0, r5
 *   @0x156b84 str r3, [r4, #0xc]
 *   @0x156b88 str r3, [r4]
 *   @0x156b8c mov r1, r3
 *   @0x156b90 str r3, [r4, #0x4]
 *   @0x156b94 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156b98 pop {r3, r4, r5, lr}
 *   @0x156b9c b 0x1611b8 <_Z17Achievement_EventPc>
 *   @0x156ba0 eoreq r6, r9, r0, ror #27
 *   @0x156ba4 andseq pc, lr, r8, ror r10
 *
 * ══ §282/321 EnableAdServing(int, int, int)  0x15e390  size 88  22 条（0x15e390..0x15e3e8）
 * @func 0x15e390 0x15e3e8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x30×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e390 push {r4, r5, r6, lr}
 *   @0x15e394 sub sp, sp, #8
 *   @0x15e398 mov r5, r1
 *   @0x15e39c mov r4, r2
 *   @0x15e3a0 mov r6, r0
 *   @0x15e3a4 bl 0x290274 <getJNIEnv>
 *   @0x15e3a8 ldr lr, [pc, #0x30]
 *   @0x15e3ac mov r3, r6
 *   @0x15e3b0 ldr r12, [pc, #0x2c]
 *   @0x15e3b4 ldr lr, [pc, lr]
 *   @0x15e3b8 ldr r12, [pc, r12]
 *   @0x15e3bc ldr r1, [lr]
 *   @0x15e3c0 ldr r2, [r12]
 *   @0x15e3c4 str r5, [sp]
 *   @0x15e3c8 str r4, [sp, #0x4]
 *   @0x15e3cc bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e3d0 mov r0, #0
 *   @0x15e3d4 mov r1, #0
 *   @0x15e3d8 add sp, sp, #8
 *   @0x15e3dc pop {r4, r5, r6, pc}
 *   @0x15e3e0 .word 0x0028f5f0
 *   @0x15e3e4 eoreq r1, r9, r4, asr #21
 *
 * ══ §283/321 FacebookCheckPermissionM(char*)  0x15e848  size 88  22 条（0x15e848..0x15e8a0）
 * @func 0x15e848 0x15e8a0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticBooleanMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e848 push {r4, lr}
 *   @0x15e84c mov r4, r0
 *   @0x15e850 bl 0x290274 <getJNIEnv>
 *   @0x15e854 mov r1, r4
 *   @0x15e858 ldr r3, [r0]
 *   @0x15e85c ldr r3, [r3, #0x29c]
 *   @0x15e860 blx r3
 *   @0x15e864 mov r4, r0
 *   @0x15e868 bl 0x290274 <getJNIEnv>
 *   @0x15e86c ldr r1, [pc, #0x24]
 *   @0x15e870 mov r3, r4
 *   @0x15e874 ldr r2, [pc, #0x20]
 *   @0x15e878 ldr r1, [pc, r1]
 *   @0x15e87c ldr r2, [pc, r2]
 *   @0x15e880 ldr r1, [r1]
 *   @0x15e884 ldr r2, [r2]
 *   @0x15e888 bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e88c adds r0, r0, #0
 *   @0x15e890 movne r0, #1
 *   @0x15e894 pop {r4, pc}
 *   @0x15e898 eoreq pc, r8, r12, lsr #2
 *   @0x15e89c eoreq r1, r9, r4, lsr r6
 *
 * ══ §284/321 OpenURL(char const*)  0x160eec  size 88  22 条（0x160eec..0x160f44）
 * @func 0x160eec 0x160f44  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160eec push {r4, lr}
 *   @0x160ef0 mov r4, r0
 *   @0x160ef4 bl 0x290274 <getJNIEnv>
 *   @0x160ef8 mov r1, r4
 *   @0x160efc ldr r3, [r0]
 *   @0x160f00 ldr r3, [r3, #0x29c]
 *   @0x160f04 blx r3
 *   @0x160f08 mov r4, r0
 *   @0x160f0c bl 0x290274 <getJNIEnv>
 *   @0x160f10 ldr r1, [pc, #0x24]
 *   @0x160f14 mov r3, r4
 *   @0x160f18 ldr r2, [pc, #0x20]
 *   @0x160f1c ldr r1, [pc, r1]
 *   @0x160f20 ldr r2, [pc, r2]
 *   @0x160f24 ldr r1, [r1]
 *   @0x160f28 ldr r2, [r2]
 *   @0x160f2c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x160f30 mov r0, #0
 *   @0x160f34 mov r1, #0
 *   @0x160f38 pop {r4, pc}
 *   @0x160f3c eoreq r12, r8, r8, lsl #21
 *   @0x160f40 .word 0x0028effc
 *
 * ══ §285/321 F_CameraGetActive(RValue&, CInstance*, CInstance*, int, RValue*)  0x16ec44  size 88  22 条（0x16ec44..0x16ec9c）
 * @func 0x16ec44 0x16ec9c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::GetActiveCamera() / CCamera::GetID()
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ec44 ldr r1, [pc, #0x4c]
 *   @0x16ec48 mov r2, #0
 *   @0x16ec4c push {r4, lr}
 *   @0x16ec50 mov r4, r0
 *   @0x16ec54 mov r3, r2
 *   @0x16ec58 movt r2, #0xbff0
 *   @0x16ec5c str r3, [r0, #0xc]
 *   @0x16ec60 str r2, [r0, #0x4]
 *   @0x16ec64 ldr r0, [pc, r1]
 *   @0x16ec68 str r3, [r4]
 *   @0x16ec6c bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv>
 *   @0x16ec70 cmp r0, #0
 *   @0x16ec74 popeq {r4, pc}
 *   @0x16ec78 bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16ec7c vmov s15, r0
 *   @0x16ec80 vcvt.f64.s32 d7, s15
 *   @0x16ec84 vmov r0, r1, d7
 *   @0x16ec88 vmov r2, s14
 *   @0x16ec8c mov r3, r1
 *   @0x16ec90 stm r4, {r2, r3}
 *   @0x16ec94 pop {r4, pc}
 *   @0x16ec98 eoreq pc, r7, r0, lsl r0
 *
 * ══ §286/321 CheckInRect(int, int, int, int)  0x17b5cc  size 88  22 条（0x17b5cc..0x17b624）
 * @func 0x17b5cc 0x17b624  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckInRect(int, int, int, int)+0x48×2
 * 字段偏移 top8: 0x48×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b5cc ldr r12, [pc, #0x48]
 *   @0x17b5d0 ldr r12, [pc, r12]
 *   @0x17b5d4 ldr r12, [r12]
 *   @0x17b5d8 cmp r12, r0
 *   @0x17b5dc ble 0x17b614 <_Z11CheckInRectiiii+0x48>
 *   @0x17b5e0 add r0, r0, r2
 *   @0x17b5e4 cmp r12, r0
 *   @0x17b5e8 bge 0x17b614 <_Z11CheckInRectiiii+0x48>
 *   @0x17b5ec ldr r2, [pc, #0x2c]
 *   @0x17b5f0 ldr r2, [pc, r2]
 *   @0x17b5f4 ldr r2, [r2]
 *   @0x17b5f8 cmp r2, r1
 *   @0x17b5fc ble 0x17b614 <_Z11CheckInRectiiii+0x48>
 *   @0x17b600 add r0, r1, r3
 *   @0x17b604 cmp r2, r0
 *   @0x17b608 movge r0, #0
 *   @0x17b60c movlt r0, #1
 *   @0x17b610 bx lr
 *   @0x17b614 mov r0, #0
 *   @0x17b618 bx lr
 *   @0x17b61c mlaeq r7, r4, sp, r4
 *   @0x17b620 eoreq r4, r7, r8, ror sp
 *
 * ══ §287/321 Shader_SetM(int)  0x1880ec  size 88  22 条（0x1880ec..0x188144）
 * @func 0x1880ec 0x188144  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1880f0→0x3f2930, 0x188108→0x3f2934, 0x18810c→0x532fbc
 * 调用序列: 无
 * 字段偏移 top8: 0x40×2 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1880ec ldr r3, [pc, #0x40]
 *   @0x1880f0 ldr r2, [pc, #0x40]
 *   @0x1880f4 add r3, pc, r3
 *   @0x1880f8 ldr r2, [r3, r2]
 *   @0x1880fc ldr r1, [r2]
 *   @0x188100 cmp r1, r0
 *   @0x188104 bxeq lr
 *   @0x188108 ldr r1, [pc, #0x2c]
 *   @0x18810c ldr r12, [pc, #0x2c]
 *   @0x188110 ldr r1, [r3, r1]
 *   @0x188114 ldr r3, [r3, r12]
 *   @0x188118 str r0, [r2]
 *   @0x18811c ldr r1, [r1]
 *   @0x188120 cmp r1, r0
 *   @0x188124 moveq r1, #0
 *   @0x188128 movne r1, #1
 *   @0x18812c strb r1, [r3]
 *   @0x188130 bx lr
 *   @0x188134 eoreq r9, r6, r12, asr r11
 *   @0x188138 .word 0xffffe96c
 *   @0x18813c .word 0xffffe940
 *   @0x188140 .word 0xffffe964
 *
 * ══ §288/321 ForgetAllGamePads()  0x18e8ec  size 88  22 条（0x18e8ec..0x18e944）
 * @func 0x18e8ec 0x18e944  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GMGamePad::SetConnected(bool)
 * 字段偏移 top8: 0x48×1 / 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e8ec ldr r3, [pc, #0x48]
 *   @0x18e8f0 push {r4, r5, r6, lr}
 *   @0x18e8f4 ldr r3, [pc, r3]
 *   @0x18e8f8 ldr r6, [r3]
 *   @0x18e8fc cmp r6, #0
 *   @0x18e900 pople {r4, r5, r6, pc}
 *   @0x18e904 ldr r3, [pc, #0x34]
 *   @0x18e908 mov r4, #0
 *   @0x18e90c ldr r3, [pc, r3]
 *   @0x18e910 ldr r5, [r3]
 *   @0x18e914 sub r5, r5, #4
 *   @0x18e918 ldr r0, [r5, #0x4]!
 *   @0x18e91c mov r1, #0
 *   @0x18e920 add r4, r4, #1
 *   @0x18e924 cmp r0, r1
 *   @0x18e928 beq 0x18e930 <_Z17ForgetAllGamePadsv+0x44>
 *   @0x18e92c bl 0x18e7f4 <_ZN9GMGamePad12SetConnectedEb>
 *   @0x18e930 cmp r4, r6
 *   @0x18e934 bne 0x18e918 <_Z17ForgetAllGamePadsv+0x2c>
 *   @0x18e938 pop {r4, r5, r6, pc}
 *   @0x18e93c eoreq r1, r6, r12, ror #2
 *   @0x18e940 eoreq r1, r6, r8, asr r1
 *
 * ══ §289/321 GMGamePad::GMGamePad()  0x18e97c  size 88  22 条（0x18e97c..0x18e9d4）
 * @func 0x18e97c 0x18e9d4  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GMGamePad::SetDeviceId(char const*)
 * 字段偏移 top8: 0x4c×1 / 0x20×1 / 0x4×1 / 0x28×1 / 0x8×1 / 0x24×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e97c ldr r1, [pc, #0x4c]
 *   @0x18e980 mov r3, #0
 *   @0x18e984 push {r4, lr}
 *   @0x18e988 mov r2, #0
 *   @0x18e98c mov r12, #1056964608
 *   @0x18e990 mov r4, r0
 *   @0x18e994 strb r3, [r0]
 *   @0x18e998 add r1, pc, r1
 *   @0x18e99c str r2, [r0, #0x20]
 *   @0x18e9a0 str r3, [r0, #0x4]
 *   @0x18e9a4 str r2, [r0, #0x28]
 *   @0x18e9a8 str r3, [r0, #0x8]
 *   @0x18e9ac str r2, [r0, #0x24]
 *   @0x18e9b0 str r3, [r0, #0xc]
 *   @0x18e9b4 str r3, [r0, #0x10]
 *   @0x18e9b8 str r3, [r0, #0x14]
 *   @0x18e9bc str r3, [r0, #0x18]
 *   @0x18e9c0 str r12, [r0, #0x1c]
 *   @0x18e9c4 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc>
 *   @0x18e9c8 mov r0, r4
 *   @0x18e9cc pop {r4, pc}
 *   @0x18e9d0 mulseq r10, lr, r1
 *
 * ══ §290/321 VMFlipRequest(unsigned int, unsigned int)  0x18f004  size 88  22 条（0x18f004..0x18f05c）
 * @func 0x18f004 0x18f05c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f004 rsbs r3, r0, #1
 *   @0x18f008 movlo r3, #0
 *   @0x18f00c cmp r1, #0
 *   @0x18f010 moveq r3, #0
 *   @0x18f014 cmp r3, #0
 *   @0x18f018 bxeq lr
 *   @0x18f01c ldr r3, [pc, #0x2c]
 *   @0x18f020 ldr r3, [pc, r3]
 *   @0x18f024 ldrb r2, [r3]
 *   @0x18f028 eor r2, r2, #1
 *   @0x18f02c strb r2, [r3]
 *   @0x18f030 cmp r2, #0
 *   @0x18f034 bne 0x18f044 <_Z13VMFlipRequestjj+0x40>
 *   @0x18f038 ldr r0, [pc, #0x14]
 *   @0x18f03c add r0, pc, r0
 *   @0x18f040 b 0xb694c <puts@plt>
 *   @0x18f044 ldr r0, [pc, #0xc]
 *   @0x18f048 add r0, pc, r0
 *   @0x18f04c b 0xb694c <puts@plt>
 *   @0x18f050 eoreq r1, r6, r8, lsr #12
 *   @0x18f054 andseq sp, r11, r12, ror #7
 *   @0x18f058 ldrsbeq sp, [r11], -r4
 *
 * ══ §291/321 LoadSave::_GetSize(char const*)  0x18f734  size 88  22 条（0x18f734..0x18f78c）
 * @func 0x18f734 0x18f78c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844 / 0xb68d4 / 0xb6958 / 0xb6850
 * 字段偏移 top8: 0x4c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f734 ldr r1, [pc, #0x4c]
 *   @0x18f738 push {r4, lr}
 *   @0x18f73c add r1, pc, r1
 *   @0x18f740 sub sp, sp, #8
 *   @0x18f744 bl 0xb6844 <fopen@plt>
 *   @0x18f748 subs r4, r0, #0
 *   @0x18f74c beq 0x18f780 <_ZN8LoadSave8_GetSizeEPKc+0x4c>
 *   @0x18f750 mov r1, #0
 *   @0x18f754 mov r2, #2
 *   @0x18f758 bl 0xb68d4 <fseek@plt>
 *   @0x18f75c mov r0, r4
 *   @0x18f760 add r1, sp, #4
 *   @0x18f764 bl 0xb6958 <fgetpos@plt>
 *   @0x18f768 mov r0, r4
 *   @0x18f76c ldr r4, [sp, #0x4]
 *   @0x18f770 bl 0xb6850 <fclose@plt>
 *   @0x18f774 mov r0, r4
 *   @0x18f778 add sp, sp, #8
 *   @0x18f77c pop {r4, pc}
 *   @0x18f780 mvn r4, #0
 *   @0x18f784 b 0x18f774 <_ZN8LoadSave8_GetSizeEPKc+0x40>
 *   @0x18f788 ldrheq r8, [r10], -r12
 *
 * ══ §292/321 CGesturePinch::IsUsingTouch(int)  0x1d7644  size 88  22 条（0x1d7644..0x1d769c）
 * @func 0x1d7644 0x1d76ac  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetTouchActionFromUID(int)×2
 * 字段偏移 top8: 0x28×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d7644 push {r4, r5, r6, lr}
 *   @0x1d7648 mov r4, r0
 *   @0x1d764c ldr r0, [r0, #0x28]
 *   @0x1d7650 mov r6, r1
 *   @0x1d7654 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi>
 *   @0x1d7658 mov r5, r0
 *   @0x1d765c ldr r0, [r4, #0x2c]
 *   @0x1d7660 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi>
 *   @0x1d7664 cmp r5, #0
 *   @0x1d7668 beq 0x1d7678 <_ZN13CGesturePinch12IsUsingTouchEi+0x34>
 *   @0x1d766c ldr r3, [r5]
 *   @0x1d7670 cmp r3, r6
 *   @0x1d7674 beq 0x1d7694 <_ZN13CGesturePinch12IsUsingTouchEi+0x50>
 *   @0x1d7678 cmp r0, #0
 *   @0x1d767c popeq {r4, r5, r6, pc}
 *   @0x1d7680 ldr r0, [r0]
 *   @0x1d7684 subs r3, r6, r0
 *   @0x1d7688 rsbs r0, r3, #0
 *   @0x1d768c adcs r0, r0, r3
 *   @0x1d7690 pop {r4, r5, r6, pc}
 *   @0x1d7694 mov r0, #1
 *   @0x1d7698 pop {r4, r5, r6, pc}
 *
 * ══ §293/321 CGestureRotate::IsUsingTouch(int)  0x1d769c  size 88  22 条（0x1d769c..0x1d76f4）
 * @func 0x1d769c 0x1d76f4  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetTouchActionFromUID(int)×2
 * 字段偏移 top8: 0x28×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d769c push {r4, r5, r6, lr}
 *   @0x1d76a0 mov r4, r0
 *   @0x1d76a4 ldr r0, [r0, #0x28]
 *   @0x1d76a8 mov r6, r1
 *   @0x1d76ac bl 0x1d75f4 <_Z21GetTouchActionFromUIDi>
 *   @0x1d76b0 mov r5, r0
 *   @0x1d76b4 ldr r0, [r4, #0x2c]
 *   @0x1d76b8 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi>
 *   @0x1d76bc cmp r5, #0
 *   @0x1d76c0 beq 0x1d76d0 <_ZN14CGestureRotate12IsUsingTouchEi+0x34>
 *   @0x1d76c4 ldr r3, [r5]
 *   @0x1d76c8 cmp r3, r6
 *   @0x1d76cc beq 0x1d76ec <_ZN14CGestureRotate12IsUsingTouchEi+0x50>
 *   @0x1d76d0 cmp r0, #0
 *   @0x1d76d4 popeq {r4, r5, r6, pc}
 *   @0x1d76d8 ldr r0, [r0]
 *   @0x1d76dc subs r3, r6, r0
 *   @0x1d76e0 rsbs r0, r3, #0
 *   @0x1d76e4 adcs r0, r0, r3
 *   @0x1d76e8 pop {r4, r5, r6, pc}
 *   @0x1d76ec mov r0, #1
 *   @0x1d76f0 pop {r4, r5, r6, pc}
 *
 * ══ §294/321 F_Shader_Set_Uniform_Matrix(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e1b70  size 88  22 条（0x1e1b70..0x1e1bc8）
 * @func 0x1e1b70 0x1e1bc8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush() / FlushShader() / Graphics::GetMatrix(eMatrix, float*) / YYGetInt32(RValue const*, int) / Shader_Set_Uniform_Matrix_N(int, int, float*)
 * 字段偏移 top8: 0x50×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1b70 push {r4, r5, lr}
 *   @0x1e1b74 sub sp, sp, #68
 *   @0x1e1b78 ldr r5, [sp, #0x50]
 *   @0x1e1b7c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e1b80 ldr r3, [pc, #0x3c]
 *   @0x1e1b84 ldr r3, [pc, r3]
 *   @0x1e1b88 ldrb r3, [r3]
 *   @0x1e1b8c cmp r3, #0
 *   @0x1e1b90 beq 0x1e1b98 <_Z27F_Shader_Set_Uniform_MatrixR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1e1b94 bl 0x1e1520 <_Z11FlushShaderv>
 *   @0x1e1b98 mov r1, sp
 *   @0x1e1b9c mov r0, #2
 *   @0x1e1ba0 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x1e1ba4 mov r0, r5
 *   @0x1e1ba8 mov r1, #0
 *   @0x1e1bac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e1bb0 mov r2, sp
 *   @0x1e1bb4 mov r1, #1
 *   @0x1e1bb8 bl 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf>
 *   @0x1e1bbc add sp, sp, #68
 *   @0x1e1bc0 pop {r4, r5, pc}
 *   @0x1e1bc4 eoreq pc, r0, r8, asr #3
 *
 * ══ §295/321 GV_PhysicsInertia(CInstance*, int, RValue*)  0x1f94b4  size 88  22 条（0x1f94b4..0x1f950c）
 * @func 0x1f94b4 0x1f951c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f94b4 ldr r0, [r0, #0x84]
 *   @0x1f94b8 push {r4, r5}
 *   @0x1f94bc cmp r0, #0
 *   @0x1f94c0 beq 0x1f9504 <_Z17GV_PhysicsInertiaP9CInstanceiP6RValue+0x50>
 *   @0x1f94c4 ldr r3, [r0]
 *   @0x1f94c8 vldr s14, [r3, #48]
 *   @0x1f94cc vmul.f32 s14, s14, s14
 *   @0x1f94d0 vldr s13, [r3, #44]
 *   @0x1f94d4 vldr s12, [r3, #132]
 *   @0x1f94d8 vldr s15, [r3, #140]
 *   @0x1f94dc mov r0, #1
 *   @0x1f94e0 mov r3, #0
 *   @0x1f94e4 str r3, [r2, #0xc]
 *   @0x1f94e8 vmla.f32 s14, s13, s13
 *   @0x1f94ec vmla.f32 s15, s14, s12
 *   @0x1f94f0 vcvt.f64.f32 d6, s15
 *   @0x1f94f4 vmov r4, r5, d6
 *   @0x1f94f8 vmov r1, s12
 *   @0x1f94fc mov r3, r5
 *   @0x1f9500 stm r2, {r1, r3}
 *   @0x1f9504 pop {r4, r5}
 *   @0x1f9508 bx lr
 *
 * ══ §296/321 GV_PhysicsAngularVelocity(CInstance*, int, RValue*)  0x1f950c  size 88  22 条（0x1f950c..0x1f9564）
 * @func 0x1f950c 0x1f9574  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f950c ldr r0, [r0, #0x84]
 *   @0x1f9510 push {r4, r5}
 *   @0x1f9514 cmp r0, #0
 *   @0x1f9518 beq 0x1f9554 <_Z25GV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x48>
 *   @0x1f951c ldr r3, [r0]
 *   @0x1f9520 vldr s15, [pc, #52]
 *   @0x1f9524 vldr s14, [r3, #88]
 *   @0x1f9528 vmul.f32 s15, s14, s15
 *   @0x1f952c vldr s14, [pc, #44]
 *   @0x1f9530 mov r0, #1
 *   @0x1f9534 mov r3, #0
 *   @0x1f9538 str r3, [r2, #0xc]
 *   @0x1f953c vdiv.f32 s15, s15, s14
 *   @0x1f9540 vcvt.f64.f32 d6, s15
 *   @0x1f9544 vmov r4, r5, d6
 *   @0x1f9548 vmov r1, s12
 *   @0x1f954c mov r3, r5
 *   @0x1f9550 stm r2, {r1, r3}
 *   @0x1f9554 pop {r4, r5}
 *   @0x1f9558 bx lr
 *   @0x1f955c teqmi r4, #0
 *   @0x1f9560 ldrdmi r0, r1, [r9], #-251
 *
 * ══ §297/321 GV_PhysicsAngle(CInstance*, int, RValue*)  0x1f9564  size 88  22 条（0x1f9564..0x1f95bc）
 * @func 0x1f9564 0x1f95cc  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9564 ldr r0, [r0, #0x84]
 *   @0x1f9568 push {r4, r5}
 *   @0x1f956c cmp r0, #0
 *   @0x1f9570 beq 0x1f95ac <_Z15GV_PhysicsAngleP9CInstanceiP6RValue+0x48>
 *   @0x1f9574 ldr r3, [r0]
 *   @0x1f9578 vldr s15, [pc, #52]
 *   @0x1f957c vldr s14, [r3, #72]
 *   @0x1f9580 vmul.f32 s15, s14, s15
 *   @0x1f9584 vldr s14, [pc, #44]
 *   @0x1f9588 mov r0, #1
 *   @0x1f958c mov r3, #0
 *   @0x1f9590 str r3, [r2, #0xc]
 *   @0x1f9594 vdiv.f32 s15, s15, s14
 *   @0x1f9598 vcvt.f64.f32 d6, s15
 *   @0x1f959c vmov r4, r5, d6
 *   @0x1f95a0 vmov r1, s12
 *   @0x1f95a4 mov r3, r5
 *   @0x1f95a8 stm r2, {r1, r3}
 *   @0x1f95ac pop {r4, r5}
 *   @0x1f95b0 bx lr
 *   @0x1f95b4 teqmi r4, #0
 *   @0x1f95b8 ldrdmi r0, r1, [r9], #-251
 *
 * ══ §298/321 SV_RoomCaption(CInstance*, int, RValue*)  0x1fae58  size 88  22 条（0x1fae58..0x1faeb0）
 * @func 0x1fae58 0x1faeb0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x8×2 / 0xc×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fae58 ldr r1, [r2, #0xc]
 *   @0x1fae5c push {r3, r4, r5, lr}
 *   @0x1fae60 bic r1, r1, #-16777216
 *   @0x1fae64 ldr r3, [pc, #0x40]
 *   @0x1fae68 cmp r1, #1
 *   @0x1fae6c ldr r3, [pc, r3]
 *   @0x1fae70 movne r5, #0
 *   @0x1fae74 ldr r4, [r3]
 *   @0x1fae78 bne 0x1fae88 <_Z14SV_RoomCaptionP9CInstanceiP6RValue+0x30>
 *   @0x1fae7c ldr r5, [r2]
 *   @0x1fae80 cmp r5, #0
 *   @0x1fae84 ldrne r5, [r5]
 *   @0x1fae88 ldr r0, [r4, #0x8]
 *   @0x1fae8c cmp r0, #0
 *   @0x1fae90 beq 0x1fae98 <_Z14SV_RoomCaptionP9CInstanceiP6RValue+0x40>
 *   @0x1fae94 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1fae98 mov r0, r5
 *   @0x1fae9c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1faea0 str r0, [r4, #0x8]
 *   @0x1faea4 mov r0, #1
 *   @0x1faea8 pop {r3, r4, r5, pc}
 *   @0x1faeac ldrheq r2, [pc], -r12
 *
 * ══ §299/321 SV_ViewXview(CInstance*, int, RValue*)  0x1fc278  size 88  22 条（0x1fc278..0x1fc2d0）
 * @func 0x1fc278 0x1fc2e0  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc278 ldr r3, [pc, #0x4c]
 *   @0x1fc27c cmp r1, #7
 *   @0x1fc280 ldr r0, [r2, #0xc]
 *   @0x1fc284 ldr r3, [pc, r3]
 *   @0x1fc288 movhi r1, #0
 *   @0x1fc28c bic r0, r0, #-16777216
 *   @0x1fc290 add r1, r1, #18
 *   @0x1fc294 ldr r3, [r3]
 *   @0x1fc298 cmp r0, #0
 *   @0x1fc29c push {r4, lr}
 *   @0x1fc2a0 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc2a4 bne 0x1fc2c0 <_Z12SV_ViewXviewP9CInstanceiP6RValue+0x48>
 *   @0x1fc2a8 ldm r2, {r0, r1}
 *   @0x1fc2ac vmov d6, r0, r1
 *   @0x1fc2b0 mov r0, #1
 *   @0x1fc2b4 vcvt.f32.f64 s15, d6
 *   @0x1fc2b8 vstr s15, [r4, #4]
 *   @0x1fc2bc pop {r4, pc}
 *   @0x1fc2c0 mov r0, r2
 *   @0x1fc2c4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc2c8 b 0x1fc2ac <_Z12SV_ViewXviewP9CInstanceiP6RValue+0x34>
 *   @0x1fc2cc andseq r1, pc, r4, lsr #13
 *
 * ══ §300/321 SV_ViewYview(CInstance*, int, RValue*)  0x1fc2d0  size 88  22 条（0x1fc2d0..0x1fc328）
 * @func 0x1fc2d0 0x1fc338  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc2d0 ldr r3, [pc, #0x4c]
 *   @0x1fc2d4 cmp r1, #7
 *   @0x1fc2d8 ldr r0, [r2, #0xc]
 *   @0x1fc2dc ldr r3, [pc, r3]
 *   @0x1fc2e0 movhi r1, #0
 *   @0x1fc2e4 bic r0, r0, #-16777216
 *   @0x1fc2e8 add r1, r1, #18
 *   @0x1fc2ec ldr r3, [r3]
 *   @0x1fc2f0 cmp r0, #0
 *   @0x1fc2f4 push {r4, lr}
 *   @0x1fc2f8 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc2fc bne 0x1fc318 <_Z12SV_ViewYviewP9CInstanceiP6RValue+0x48>
 *   @0x1fc300 ldm r2, {r0, r1}
 *   @0x1fc304 vmov d6, r0, r1
 *   @0x1fc308 mov r0, #1
 *   @0x1fc30c vcvt.f32.f64 s15, d6
 *   @0x1fc310 vstr s15, [r4, #8]
 *   @0x1fc314 pop {r4, pc}
 *   @0x1fc318 mov r0, r2
 *   @0x1fc31c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc320 b 0x1fc304 <_Z12SV_ViewYviewP9CInstanceiP6RValue+0x34>
 *   @0x1fc324 andseq r1, pc, r12, asr #12
 *
 * ══ §301/321 SV_ViewWview(CInstance*, int, RValue*)  0x1fc328  size 88  22 条（0x1fc328..0x1fc380）
 * @func 0x1fc328 0x1fc390  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc328 ldr r3, [pc, #0x4c]
 *   @0x1fc32c cmp r1, #7
 *   @0x1fc330 ldr r0, [r2, #0xc]
 *   @0x1fc334 ldr r3, [pc, r3]
 *   @0x1fc338 movhi r1, #0
 *   @0x1fc33c bic r0, r0, #-16777216
 *   @0x1fc340 add r1, r1, #18
 *   @0x1fc344 ldr r3, [r3]
 *   @0x1fc348 cmp r0, #0
 *   @0x1fc34c push {r4, lr}
 *   @0x1fc350 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc354 bne 0x1fc370 <_Z12SV_ViewWviewP9CInstanceiP6RValue+0x48>
 *   @0x1fc358 ldm r2, {r0, r1}
 *   @0x1fc35c vmov d6, r0, r1
 *   @0x1fc360 mov r0, #1
 *   @0x1fc364 vcvt.f32.f64 s15, d6
 *   @0x1fc368 vstr s15, [r4, #12]
 *   @0x1fc36c pop {r4, pc}
 *   @0x1fc370 mov r0, r2
 *   @0x1fc374 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc378 b 0x1fc35c <_Z12SV_ViewWviewP9CInstanceiP6RValue+0x34>
 *   @0x1fc37c ldrsheq r1, [pc], -r4
 *
 * ══ §302/321 SV_ViewHview(CInstance*, int, RValue*)  0x1fc380  size 88  22 条（0x1fc380..0x1fc3d8）
 * @func 0x1fc380 0x1fc3d8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc380 ldr r3, [pc, #0x4c]
 *   @0x1fc384 cmp r1, #7
 *   @0x1fc388 ldr r0, [r2, #0xc]
 *   @0x1fc38c ldr r3, [pc, r3]
 *   @0x1fc390 movhi r1, #0
 *   @0x1fc394 bic r0, r0, #-16777216
 *   @0x1fc398 add r1, r1, #18
 *   @0x1fc39c ldr r3, [r3]
 *   @0x1fc3a0 cmp r0, #0
 *   @0x1fc3a4 push {r4, lr}
 *   @0x1fc3a8 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc3ac bne 0x1fc3c8 <_Z12SV_ViewHviewP9CInstanceiP6RValue+0x48>
 *   @0x1fc3b0 ldm r2, {r0, r1}
 *   @0x1fc3b4 vmov d6, r0, r1
 *   @0x1fc3b8 mov r0, #1
 *   @0x1fc3bc vcvt.f32.f64 s15, d6
 *   @0x1fc3c0 vstr s15, [r4, #16]
 *   @0x1fc3c4 pop {r4, pc}
 *   @0x1fc3c8 mov r0, r2
 *   @0x1fc3cc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc3d0 b 0x1fc3b4 <_Z12SV_ViewHviewP9CInstanceiP6RValue+0x34>
 *   @0x1fc3d4 mulseq pc, r12, r5
 *
 * ══ §303/321 SV_ViewAngle(CInstance*, int, RValue*)  0x1fc578  size 88  22 条（0x1fc578..0x1fc5d0）
 * @func 0x1fc578 0x1fc5d0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc578 ldr r3, [pc, #0x4c]
 *   @0x1fc57c cmp r1, #7
 *   @0x1fc580 ldr r0, [r2, #0xc]
 *   @0x1fc584 ldr r3, [pc, r3]
 *   @0x1fc588 movhi r1, #0
 *   @0x1fc58c bic r0, r0, #-16777216
 *   @0x1fc590 add r1, r1, #18
 *   @0x1fc594 ldr r3, [r3]
 *   @0x1fc598 cmp r0, #0
 *   @0x1fc59c push {r4, lr}
 *   @0x1fc5a0 ldr r4, [r3, r1, lsl #2]
 *   @0x1fc5a4 bne 0x1fc5c0 <_Z12SV_ViewAngleP9CInstanceiP6RValue+0x48>
 *   @0x1fc5a8 ldm r2, {r0, r1}
 *   @0x1fc5ac vmov d6, r0, r1
 *   @0x1fc5b0 mov r0, #1
 *   @0x1fc5b4 vcvt.f32.f64 s15, d6
 *   @0x1fc5b8 vstr s15, [r4, #36]
 *   @0x1fc5bc pop {r4, pc}
 *   @0x1fc5c0 mov r0, r2
 *   @0x1fc5c4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc5c8 b 0x1fc5ac <_Z12SV_ViewAngleP9CInstanceiP6RValue+0x34>
 *   @0x1fc5cc andseq r1, pc, r4, lsr #7
 *
 * ══ §304/321 SV_BackgroundX(CInstance*, int, RValue*)  0x1fca18  size 88  22 条（0x1fca18..0x1fca70）
 * @func 0x1fca18 0x1fca80  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fca18 ldr r3, [pc, #0x4c]
 *   @0x1fca1c cmp r1, #7
 *   @0x1fca20 ldr r0, [r2, #0xc]
 *   @0x1fca24 ldr r3, [pc, r3]
 *   @0x1fca28 movhi r1, #0
 *   @0x1fca2c bic r0, r0, #-16777216
 *   @0x1fca30 ldr r3, [r3]
 *   @0x1fca34 cmp r0, #0
 *   @0x1fca38 push {r4, lr}
 *   @0x1fca3c add r1, r3, r1, lsl #2
 *   @0x1fca40 ldr r4, [r1, #0x24]
 *   @0x1fca44 bne 0x1fca60 <_Z14SV_BackgroundXP9CInstanceiP6RValue+0x48>
 *   @0x1fca48 ldm r2, {r0, r1}
 *   @0x1fca4c vmov d6, r0, r1
 *   @0x1fca50 mov r0, #1
 *   @0x1fca54 vcvt.f32.f64 s15, d6
 *   @0x1fca58 vstr s15, [r4, #8]
 *   @0x1fca5c pop {r4, pc}
 *   @0x1fca60 mov r0, r2
 *   @0x1fca64 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fca68 b 0x1fca4c <_Z14SV_BackgroundXP9CInstanceiP6RValue+0x34>
 *   @0x1fca6c andseq r0, pc, r4, lsl #30
 *
 * ══ §305/321 SV_BackgroundY(CInstance*, int, RValue*)  0x1fca70  size 88  22 条（0x1fca70..0x1fcac8）
 * @func 0x1fca70 0x1fcac8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fca70 ldr r3, [pc, #0x4c]
 *   @0x1fca74 cmp r1, #7
 *   @0x1fca78 ldr r0, [r2, #0xc]
 *   @0x1fca7c ldr r3, [pc, r3]
 *   @0x1fca80 movhi r1, #0
 *   @0x1fca84 bic r0, r0, #-16777216
 *   @0x1fca88 ldr r3, [r3]
 *   @0x1fca8c cmp r0, #0
 *   @0x1fca90 push {r4, lr}
 *   @0x1fca94 add r1, r3, r1, lsl #2
 *   @0x1fca98 ldr r4, [r1, #0x24]
 *   @0x1fca9c bne 0x1fcab8 <_Z14SV_BackgroundYP9CInstanceiP6RValue+0x48>
 *   @0x1fcaa0 ldm r2, {r0, r1}
 *   @0x1fcaa4 vmov d6, r0, r1
 *   @0x1fcaa8 mov r0, #1
 *   @0x1fcaac vcvt.f32.f64 s15, d6
 *   @0x1fcab0 vstr s15, [r4, #12]
 *   @0x1fcab4 pop {r4, pc}
 *   @0x1fcab8 mov r0, r2
 *   @0x1fcabc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcac0 b 0x1fcaa4 <_Z14SV_BackgroundYP9CInstanceiP6RValue+0x34>
 *   @0x1fcac4 andseq r0, pc, r12, lsr #29
 *
 * ══ §306/321 SV_BackgroundXScale(CInstance*, int, RValue*)  0x1fcbd0  size 88  22 条（0x1fcbd0..0x1fcc28）
 * @func 0x1fcbd0 0x1fcc38  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fcbd0 ldr r3, [pc, #0x4c]
 *   @0x1fcbd4 cmp r1, #7
 *   @0x1fcbd8 ldr r0, [r2, #0xc]
 *   @0x1fcbdc ldr r3, [pc, r3]
 *   @0x1fcbe0 movhi r1, #0
 *   @0x1fcbe4 bic r0, r0, #-16777216
 *   @0x1fcbe8 ldr r3, [r3]
 *   @0x1fcbec cmp r0, #0
 *   @0x1fcbf0 push {r4, lr}
 *   @0x1fcbf4 add r1, r3, r1, lsl #2
 *   @0x1fcbf8 ldr r4, [r1, #0x24]
 *   @0x1fcbfc bne 0x1fcc18 <_Z19SV_BackgroundXScaleP9CInstanceiP6RValue+0x48>
 *   @0x1fcc00 ldm r2, {r0, r1}
 *   @0x1fcc04 vmov d6, r0, r1
 *   @0x1fcc08 mov r0, #1
 *   @0x1fcc0c vcvt.f32.f64 s15, d6
 *   @0x1fcc10 vstr s15, [r4, #28]
 *   @0x1fcc14 pop {r4, pc}
 *   @0x1fcc18 mov r0, r2
 *   @0x1fcc1c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcc20 b 0x1fcc04 <_Z19SV_BackgroundXScaleP9CInstanceiP6RValue+0x34>
 *   @0x1fcc24 andseq r0, pc, r12, asr #26
 *
 * ══ §307/321 SV_BackgroundYScale(CInstance*, int, RValue*)  0x1fcc28  size 88  22 条（0x1fcc28..0x1fcc80）
 * @func 0x1fcc28 0x1fcc90  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fcc28 ldr r3, [pc, #0x4c]
 *   @0x1fcc2c cmp r1, #7
 *   @0x1fcc30 ldr r0, [r2, #0xc]
 *   @0x1fcc34 ldr r3, [pc, r3]
 *   @0x1fcc38 movhi r1, #0
 *   @0x1fcc3c bic r0, r0, #-16777216
 *   @0x1fcc40 ldr r3, [r3]
 *   @0x1fcc44 cmp r0, #0
 *   @0x1fcc48 push {r4, lr}
 *   @0x1fcc4c add r1, r3, r1, lsl #2
 *   @0x1fcc50 ldr r4, [r1, #0x24]
 *   @0x1fcc54 bne 0x1fcc70 <_Z19SV_BackgroundYScaleP9CInstanceiP6RValue+0x48>
 *   @0x1fcc58 ldm r2, {r0, r1}
 *   @0x1fcc5c vmov d6, r0, r1
 *   @0x1fcc60 mov r0, #1
 *   @0x1fcc64 vcvt.f32.f64 s15, d6
 *   @0x1fcc68 vstr s15, [r4, #32]
 *   @0x1fcc6c pop {r4, pc}
 *   @0x1fcc70 mov r0, r2
 *   @0x1fcc74 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcc78 b 0x1fcc5c <_Z19SV_BackgroundYScaleP9CInstanceiP6RValue+0x34>
 *   @0x1fcc7c ldrsheq r0, [pc], -r4
 *
 * ══ §308/321 SV_BackgroundHSpeed(CInstance*, int, RValue*)  0x1fcc80  size 88  22 条（0x1fcc80..0x1fccd8）
 * @func 0x1fcc80 0x1fcce8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fcc80 ldr r3, [pc, #0x4c]
 *   @0x1fcc84 cmp r1, #7
 *   @0x1fcc88 ldr r0, [r2, #0xc]
 *   @0x1fcc8c ldr r3, [pc, r3]
 *   @0x1fcc90 movhi r1, #0
 *   @0x1fcc94 bic r0, r0, #-16777216
 *   @0x1fcc98 ldr r3, [r3]
 *   @0x1fcc9c cmp r0, #0
 *   @0x1fcca0 push {r4, lr}
 *   @0x1fcca4 add r1, r3, r1, lsl #2
 *   @0x1fcca8 ldr r4, [r1, #0x24]
 *   @0x1fccac bne 0x1fccc8 <_Z19SV_BackgroundHSpeedP9CInstanceiP6RValue+0x48>
 *   @0x1fccb0 ldm r2, {r0, r1}
 *   @0x1fccb4 vmov d6, r0, r1
 *   @0x1fccb8 mov r0, #1
 *   @0x1fccbc vcvt.f32.f64 s15, d6
 *   @0x1fccc0 vstr s15, [r4, #20]
 *   @0x1fccc4 pop {r4, pc}
 *   @0x1fccc8 mov r0, r2
 *   @0x1fcccc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fccd0 b 0x1fccb4 <_Z19SV_BackgroundHSpeedP9CInstanceiP6RValue+0x34>
 *   @0x1fccd4 mulseq pc, r12, r12
 *
 * ══ §309/321 SV_BackgroundVSpeed(CInstance*, int, RValue*)  0x1fccd8  size 88  22 条（0x1fccd8..0x1fcd30）
 * @func 0x1fccd8 0x1fcd30  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fccd8 ldr r3, [pc, #0x4c]
 *   @0x1fccdc cmp r1, #7
 *   @0x1fcce0 ldr r0, [r2, #0xc]
 *   @0x1fcce4 ldr r3, [pc, r3]
 *   @0x1fcce8 movhi r1, #0
 *   @0x1fccec bic r0, r0, #-16777216
 *   @0x1fccf0 ldr r3, [r3]
 *   @0x1fccf4 cmp r0, #0
 *   @0x1fccf8 push {r4, lr}
 *   @0x1fccfc add r1, r3, r1, lsl #2
 *   @0x1fcd00 ldr r4, [r1, #0x24]
 *   @0x1fcd04 bne 0x1fcd20 <_Z19SV_BackgroundVSpeedP9CInstanceiP6RValue+0x48>
 *   @0x1fcd08 ldm r2, {r0, r1}
 *   @0x1fcd0c vmov d6, r0, r1
 *   @0x1fcd10 mov r0, #1
 *   @0x1fcd14 vcvt.f32.f64 s15, d6
 *   @0x1fcd18 vstr s15, [r4, #24]
 *   @0x1fcd1c pop {r4, pc}
 *   @0x1fcd20 mov r0, r2
 *   @0x1fcd24 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcd28 b 0x1fcd0c <_Z19SV_BackgroundVSpeedP9CInstanceiP6RValue+0x34>
 *   @0x1fcd2c andseq r0, pc, r4, asr #24
 *
 * ══ §310/321 SV_BackgroundAlpha(CInstance*, int, RValue*)  0x1fcdcc  size 88  22 条（0x1fcdcc..0x1fce24）
 * @func 0x1fcdcc 0x1fce34  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4c×1 / 0xc×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fcdcc ldr r3, [pc, #0x4c]
 *   @0x1fcdd0 cmp r1, #7
 *   @0x1fcdd4 ldr r0, [r2, #0xc]
 *   @0x1fcdd8 ldr r3, [pc, r3]
 *   @0x1fcddc movhi r1, #0
 *   @0x1fcde0 bic r0, r0, #-16777216
 *   @0x1fcde4 ldr r3, [r3]
 *   @0x1fcde8 cmp r0, #0
 *   @0x1fcdec push {r4, lr}
 *   @0x1fcdf0 add r1, r3, r1, lsl #2
 *   @0x1fcdf4 ldr r4, [r1, #0x24]
 *   @0x1fcdf8 bne 0x1fce14 <_Z18SV_BackgroundAlphaP9CInstanceiP6RValue+0x48>
 *   @0x1fcdfc ldm r2, {r0, r1}
 *   @0x1fce00 vmov d6, r0, r1
 *   @0x1fce04 mov r0, #1
 *   @0x1fce08 vcvt.f32.f64 s15, d6
 *   @0x1fce0c vstr s15, [r4, #40]
 *   @0x1fce10 pop {r4, pc}
 *   @0x1fce14 mov r0, r2
 *   @0x1fce18 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fce1c b 0x1fce00 <_Z18SV_BackgroundAlphaP9CInstanceiP6RValue+0x34>
 *   @0x1fce20 andseq r0, pc, r0, asr r11
 *
 * ══ §311/321 SV_RoomHeight(CInstance*, int, RValue*)  0x1fce24  size 88  22 条（0x1fce24..0x1fce7c）
 * @func 0x1fce24 0x1fce8c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x48×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fce24 ldr r1, [r2, #0xc]
 *   @0x1fce28 ldr r3, [pc, #0x48]
 *   @0x1fce2c bic r1, r1, #-16777216
 *   @0x1fce30 ldr r3, [pc, r3]
 *   @0x1fce34 cmp r1, #0
 *   @0x1fce38 push {r4, lr}
 *   @0x1fce3c ldr r4, [r3]
 *   @0x1fce40 bne 0x1fce64 <_Z13SV_RoomHeightP9CInstanceiP6RValue+0x40>
 *   @0x1fce44 ldr r12, [r2]
 *   @0x1fce48 ldr r3, [r2, #0x4]
 *   @0x1fce4c mov r0, r12
 *   @0x1fce50 mov r1, r3
 *   @0x1fce54 bl 0xb66e8 <lrint@plt>
 *   @0x1fce58 str r0, [r4, #0x14]
 *   @0x1fce5c mov r0, #1
 *   @0x1fce60 pop {r4, pc}
 *   @0x1fce64 mov r0, r2
 *   @0x1fce68 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fce6c mov r12, r0
 *   @0x1fce70 mov r3, r1
 *   @0x1fce74 b 0x1fce4c <_Z13SV_RoomHeightP9CInstanceiP6RValue+0x28>
 *   @0x1fce78 ldrsheq r0, [pc], -r8
 *
 * ══ §312/321 SV_RoomWidth(CInstance*, int, RValue*)  0x1fce7c  size 88  22 条（0x1fce7c..0x1fced4）
 * @func 0x1fce7c 0x1fced4  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x48×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fce7c ldr r1, [r2, #0xc]
 *   @0x1fce80 ldr r3, [pc, #0x48]
 *   @0x1fce84 bic r1, r1, #-16777216
 *   @0x1fce88 ldr r3, [pc, r3]
 *   @0x1fce8c cmp r1, #0
 *   @0x1fce90 push {r4, lr}
 *   @0x1fce94 ldr r4, [r3]
 *   @0x1fce98 bne 0x1fcebc <_Z12SV_RoomWidthP9CInstanceiP6RValue+0x40>
 *   @0x1fce9c ldr r12, [r2]
 *   @0x1fcea0 ldr r3, [r2, #0x4]
 *   @0x1fcea4 mov r0, r12
 *   @0x1fcea8 mov r1, r3
 *   @0x1fceac bl 0xb66e8 <lrint@plt>
 *   @0x1fceb0 str r0, [r4, #0x10]
 *   @0x1fceb4 mov r0, #1
 *   @0x1fceb8 pop {r4, pc}
 *   @0x1fcebc mov r0, r2
 *   @0x1fcec0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcec4 mov r12, r0
 *   @0x1fcec8 mov r3, r1
 *   @0x1fcecc b 0x1fcea4 <_Z12SV_RoomWidthP9CInstanceiP6RValue+0x28>
 *   @0x1fced0 andseq r0, pc, r0, lsr #21
 *
 * ══ §313/321 SV_BackgroundColor(CInstance*, int, RValue*)  0x1fd010  size 88  22 条（0x1fd010..0x1fd068）
 * @func 0x1fd010 0x1fd068  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x48×1 / 0x4×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fd010 ldr r1, [r2, #0xc]
 *   @0x1fd014 ldr r3, [pc, #0x48]
 *   @0x1fd018 bic r1, r1, #-16777216
 *   @0x1fd01c ldr r3, [pc, r3]
 *   @0x1fd020 cmp r1, #0
 *   @0x1fd024 push {r4, lr}
 *   @0x1fd028 ldr r4, [r3]
 *   @0x1fd02c bne 0x1fd050 <_Z18SV_BackgroundColorP9CInstanceiP6RValue+0x40>
 *   @0x1fd030 ldr r12, [r2]
 *   @0x1fd034 ldr r3, [r2, #0x4]
 *   @0x1fd038 mov r0, r12
 *   @0x1fd03c mov r1, r3
 *   @0x1fd040 bl 0xb66e8 <lrint@plt>
 *   @0x1fd044 str r0, [r4, #0x1c]
 *   @0x1fd048 mov r0, #1
 *   @0x1fd04c pop {r4, pc}
 *   @0x1fd050 mov r0, r2
 *   @0x1fd054 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fd058 mov r12, r0
 *   @0x1fd05c mov r3, r1
 *   @0x1fd060 b 0x1fd038 <_Z18SV_BackgroundColorP9CInstanceiP6RValue+0x28>
 *   @0x1fd064 andseq r0, pc, r12, lsl #18
 *
 * ══ §314/321 CStream::WriteInteger(int)  0x201a10  size 88  22 条（0x201a10..0x201a68）
 * @func 0x201a10 0x201a68  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::_AllocExtraSpace(int)
 * 字段偏移 top8: 0x10×1 / 0x8×1 / 0x18×1 / 0x1×1 / 0x2×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201a10 push {r3, r4, r5, lr}
 *   @0x201a14 mov r4, r0
 *   @0x201a18 mov r5, r1
 *   @0x201a1c mov r1, #4
 *   @0x201a20 bl 0x201414 <_ZN7CStream16_AllocExtraSpaceEi>
 *   @0x201a24 ldr r2, [r4, #0x10]
 *   @0x201a28 ldr r1, [r4, #0x8]
 *   @0x201a2c ldr r3, [r4, #0x18]
 *   @0x201a30 cmp r1, r2
 *   @0x201a34 pople {r3, r4, r5, pc}
 *   @0x201a38 strb r5, [r3, r2]!
 *   @0x201a3c asr r1, r5, #8
 *   @0x201a40 asr r2, r5, #16
 *   @0x201a44 strb r1, [r3, #0x1]
 *   @0x201a48 strb r2, [r3, #0x2]
 *   @0x201a4c lsr r5, r5, #24
 *   @0x201a50 strb r5, [r3, #0x3]
 *   @0x201a54 ldrd r2, r3, [r4, #16]
 *   @0x201a58 adds r2, r2, #4
 *   @0x201a5c adc r3, r3, #0
 *   @0x201a60 strd r2, r3, [r4, #16]
 *   @0x201a64 pop {r3, r4, r5, pc}
 *
 * ══ §315/321 cAudio_Sound::~cAudio_Sound()  0x218f24  size 88  22 条（0x218f24..0x218f7c）
 * @func 0x218f24 0x218f7c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / 0xb6ad8 / 0xb6ae4
 * 字段偏移 top8: 0x30×2 / 0x18×2 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218f24 push {r3, r4, r5, lr}
 *   @0x218f28 mov r4, r0
 *   @0x218f2c ldr r0, [r0]
 *   @0x218f30 mov r5, #0
 *   @0x218f34 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x218f38 ldr r0, [r4, #0x30]
 *   @0x218f3c str r5, [r4]
 *   @0x218f40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x218f44 str r5, [r4, #0x30]
 *   @0x218f48 ldr r0, [r4, #0x18]
 *   @0x218f4c bl 0xb6ad8 <alIsBuffer@plt>
 *   @0x218f50 cmp r0, r5
 *   @0x218f54 beq 0x218f6c <_ZN12cAudio_SoundD2Ev+0x48>
 *   @0x218f58 mov r0, #1
 *   @0x218f5c add r1, r4, #24
 *   @0x218f60 bl 0xb6ae4 <alDeleteBuffers@plt>
 *   @0x218f64 mvn r3, #0
 *   @0x218f68 str r3, [r4, #0x18]
 *   @0x218f6c mov r3, #0
 *   @0x218f70 mov r0, r4
 *   @0x218f74 str r3, [r4, #0x58]
 *   @0x218f78 pop {r3, r4, r5, pc}
 *
 * ══ §316/321 CAudioGroup::GetLoadProgress()  0x21dd9c  size 88  22 条（0x21dd9c..0x21ddf4）
 * @func 0x21dd9c 0x21ddf4  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / Mutex::Unlock()
 * 字段偏移 top8: 0x14×3 / 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21dd9c ldr r3, [r0]
 *   @0x21dda0 push {r4, lr}
 *   @0x21dda4 cmp r3, #2
 *   @0x21dda8 mov r4, r0
 *   @0x21ddac beq 0x21ddec <_ZN11CAudioGroup15GetLoadProgressEv+0x50>
 *   @0x21ddb0 cmp r3, #1
 *   @0x21ddb4 beq 0x21ddc0 <_ZN11CAudioGroup15GetLoadProgressEv+0x24>
 *   @0x21ddb8 mov r0, #0
 *   @0x21ddbc pop {r4, pc}
 *   @0x21ddc0 ldr r0, [r0, #0x20]
 *   @0x21ddc4 cmp r0, #0
 *   @0x21ddc8 popeq {r4, pc}
 *   @0x21ddcc ldr r0, [r0, #0x14]
 *   @0x21ddd0 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x21ddd4 ldr r3, [r4, #0x20]
 *   @0x21ddd8 ldr r4, [r4, #0x14]
 *   @0x21dddc ldr r0, [r3, #0x14]
 *   @0x21dde0 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x21dde4 mov r0, r4
 *   @0x21dde8 pop {r4, pc}
 *   @0x21ddec mov r0, #100
 *   @0x21ddf0 pop {r4, pc}
 *
 * ══ §317/321 _alutOutputStreamConstruct  0x2228a4  size 88  22 条（0x2228a4..0x2228fc）
 * @func 0x2228a4 0x2228fc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutMalloc×2 / 0xb655c
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2228a4 push {r4, r5, r6, lr}
 *   @0x2228a8 mov r6, r0
 *   @0x2228ac mov r0, #12
 *   @0x2228b0 bl 0x222a98 <_alutMalloc>
 *   @0x2228b4 subs r4, r0, #0
 *   @0x2228b8 beq 0x2228e4 <_alutOutputStreamConstruct+0x40>
 *   @0x2228bc mov r0, r6
 *   @0x2228c0 bl 0x222a98 <_alutMalloc>
 *   @0x2228c4 cmp r0, #0
 *   @0x2228c8 mov r5, r0
 *   @0x2228cc str r0, [r4]
 *   @0x2228d0 beq 0x2228ec <_alutOutputStreamConstruct+0x48>
 *   @0x2228d4 str r0, [r4, #0x4]
 *   @0x2228d8 mov r0, r4
 *   @0x2228dc str r6, [r4, #0x8]
 *   @0x2228e0 pop {r4, r5, r6, pc}
 *   @0x2228e4 mov r0, r4
 *   @0x2228e8 pop {r4, r5, r6, pc}
 *   @0x2228ec mov r0, r4
 *   @0x2228f0 bl 0xb655c <free@plt>
 *   @0x2228f4 mov r0, r5
 *   @0x2228f8 pop {r4, r5, r6, pc}
 *
 * ══ §318/321 AddTimingEvent(COggSyncThread*, unsigned int, long long, long long)  0x224df0  size 88  22 条（0x224df0..0x224e48）
 * @func 0x224df0 0x224e48  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock() / operator new(unsigned int)
 * 字段偏移 top8: 0x28×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224df0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x224df4 mov r8, r1
 *   @0x224df8 mov r6, r2
 *   @0x224dfc mov r7, r3
 *   @0x224e00 mov r9, r0
 *   @0x224e04 ldrd r4, r5, [sp, #32]
 *   @0x224e08 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x224e0c mov r0, #32
 *   @0x224e10 bl 0x27c524 <_Znwj>
 *   @0x224e14 ldr r2, [pc, #0x28]
 *   @0x224e18 ldr r2, [pc, r2]
 *   @0x224e1c ldr r1, [r2]
 *   @0x224e20 mov r3, r0
 *   @0x224e24 mov r0, r9
 *   @0x224e28 str r8, [r3]
 *   @0x224e2c strd r6, r7, [r3, #8]
 *   @0x224e30 strd r4, r5, [r3, #16]
 *   @0x224e34 str r3, [r2]
 *   @0x224e38 str r1, [r3, #0x18]
 *   @0x224e3c pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x224e40 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x224e44 andseq r12, r12, r4, ror #12
 *
 * ══ §319/321 ov_serialnumber  0x231280  size 88  22 条（0x231280..0x2312d8）
 * @func 0x231280 0x2312d8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_serialnumber+0x38 / ov_serialnumber+0x28
 * 字段偏移 top8: 0x4×1 / 0x34×1 / 0x5c×1 / 0x40×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231280 ldr r2, [r0, #0x4]
 *   @0x231284 ldr r3, [r0, #0x34]
 *   @0x231288 cmp r2, #0
 *   @0x23128c bne 0x2312b0 <ov_serialnumber+0x30>
 *   @0x231290 cmp r1, r3
 *   @0x231294 subge r1, r3, #1
 *   @0x231298 bge 0x231290 <ov_serialnumber+0x10>
 *   @0x23129c cmp r1, #0
 *   @0x2312a0 mvn r1, #0
 *   @0x2312a4 bge 0x231290 <ov_serialnumber+0x10>
 *   @0x2312a8 ldr r0, [r0, #0x5c]
 *   @0x2312ac bx lr
 *   @0x2312b0 cmp r3, r1
 *   @0x2312b4 bgt 0x2312c4 <ov_serialnumber+0x44>
 *   @0x2312b8 sub r1, r3, #1
 *   @0x2312bc cmp r3, r1
 *   @0x2312c0 ble 0x2312b8 <ov_serialnumber+0x38>
 *   @0x2312c4 cmp r1, #0
 *   @0x2312c8 blt 0x2312a8 <ov_serialnumber+0x28>
 *   @0x2312cc ldr r3, [r0, #0x40]
 *   @0x2312d0 ldr r0, [r3, r1, lsl #2]
 *   @0x2312d4 bx lr
 *
 * ══ §320/321 ov_fopen  0x231d3c  size 88  22 条（0x231d3c..0x231d94）
 * @func 0x231d3c 0x231d94  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844 / ov_open / 0xb6850
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231d3c push {r3, r4, r5, lr}
 *   @0x231d40 mov r4, r1
 *   @0x231d44 ldr r1, [pc, #0x44]
 *   @0x231d48 add r1, pc, r1
 *   @0x231d4c bl 0xb6844 <fopen@plt>
 *   @0x231d50 subs r5, r0, #0
 *   @0x231d54 beq 0x231d88 <ov_fopen+0x4c>
 *   @0x231d58 mov r2, #0
 *   @0x231d5c mov r1, r4
 *   @0x231d60 mov r3, r2
 *   @0x231d64 bl 0x231cec <ov_open>
 *   @0x231d68 subs r4, r0, #0
 *   @0x231d6c bne 0x231d78 <ov_fopen+0x3c>
 *   @0x231d70 mov r0, r4
 *   @0x231d74 pop {r3, r4, r5, pc}
 *   @0x231d78 mov r0, r5
 *   @0x231d7c bl 0xb6850 <fclose@plt>
 *   @0x231d80 mov r0, r4
 *   @0x231d84 pop {r3, r4, r5, pc}
 *   @0x231d88 mvn r0, #0
 *   @0x231d8c pop {r3, r4, r5, pc}
 *   @0x231d90 ldrheq r5, [r0], -r0
 *
 * ══ §321/321 GLFuncImportDestroy()  0xbd6a4  size 64  16 条（0xbd6a4..0xbd6e4）
 * @func 0xbd6a4 0xbd6e4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb652c
 * 字段偏移 top8: 0x2c×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd6a4 push {r3, r4, r5, lr}
 *   @0xbd6a8 ldr r4, [pc, #0x2c]
 *   @0xbd6ac ldr r4, [pc, r4]
 *   @0xbd6b0 ldr r3, [r4]
 *   @0xbd6b4 cmp r3, #0
 *   @0xbd6b8 popeq {r3, r4, r5, pc}
 *   @0xbd6bc ldr r5, [pc, #0x1c]
 *   @0xbd6c0 add r5, pc, r5
 *   @0xbd6c4 ldr r0, [r5]
 *   @0xbd6c8 bl 0xb652c <dlclose@plt>
 *   @0xbd6cc mov r3, #0
 *   @0xbd6d0 str r3, [r5]
 *   @0xbd6d4 str r3, [r4]
 *   @0xbd6d8 pop {r3, r4, r5, pc}
 *   @0xbd6dc eorseq r0, r3, r4, rrx
 *   @0xbd6e0 eorseq r12, r11, r8, asr #7
 */
