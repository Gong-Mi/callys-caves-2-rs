/* cally 逆向卡：Reach_12 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 289 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/289 RenderStateManager::SetSamplerState  0x167ef4  size 152  38 条（0x167ef4..0x167f8c）
 * @func 0x167ef4 0x167f8c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x270×2 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167ef4 add r1, r1, r1, lsl #2
 *   @0x167ef8 push {r4, r5, r6, r7, r8}
 *   @0x167efc add r2, r2, r1, lsl #1
 *   @0x167f00 add r12, r0, r2, lsl #2
 *   @0x167f04 ldr r1, [r12, #0x270]
 *   @0x167f08 cmp r1, r3
 *   @0x167f0c beq 0x167f5c <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej+0x68>
 *   @0x167f10 ldr r1, [r12, #0xa0]
 *   @0x167f14 cmp r1, r3
 *   @0x167f18 mov r1, #1
 *   @0x167f1c beq 0x167f64 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej+0x70>
 *   @0x167f20 sub r6, r2, #32
 *   @0x167f24 rsb r8, r2, #32
 *   @0x167f28 lsl r5, r1, r6
 *   @0x167f2c ldrd r6, r7, [r0, #8]
 *   @0x167f30 orr r5, r5, r1, lsr r8
 *   @0x167f34 lsl r4, r1, r2
 *   @0x167f38 orr r4, r4, r6
 *   @0x167f3c orr r5, r5, r7
 *   @0x167f40 strd r4, r5, [r0, #8]
 *   @0x167f44 str r3, [r12, #0x270]
 *   @0x167f48 mov r1, #944
 *   @0x167f4c ldrd r2, r3, [r0]
 *   @0x167f50 orr r2, r2, r4
 *   @0x167f54 orr r3, r3, r5
 *   @0x167f58 strd r2, r3, [r0, r1]
 *   @0x167f5c pop {r4, r5, r6, r7, r8}
 *   @0x167f60 bx lr
 *   @0x167f64 sub r4, r2, #32
 *   @0x167f68 rsb r8, r2, #32
 *   @0x167f6c lsl r7, r1, r4
 *   @0x167f70 ldrd r4, r5, [r0, #8]
 *   @0x167f74 orr r7, r7, r1, lsr r8
 *   @0x167f78 lsl r6, r1, r2
 *   @0x167f7c bic r4, r4, r6
 *   @0x167f80 bic r5, r5, r7
 *   @0x167f84 strd r4, r5, [r0, #8]
 *   @0x167f88 b 0x167f44 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej+0x50>
 *
 * ══ §2/289 CCameraManager::AddCameraToList  0x16ed1c  size 152  38 条（0x16ed1c..0x16edb4）
 * @func 0x16ed1c 0x16edb4  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCamera::SetID(int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x14×3 / 0xc×3 / 0x10×2 / 0x2×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ed1c push {r4, r5, lr}
 *   @0x16ed20 subs r5, r1, #0
 *   @0x16ed24 sub sp, sp, #12
 *   @0x16ed28 mov r4, r0
 *   @0x16ed2c beq 0x16ed70 <_ZN14CCameraManager15AddCameraToListEP7CCamerai+0x54>
 *   @0x16ed30 cmn r2, #1
 *   @0x16ed34 ldreq r1, [r0]
 *   @0x16ed38 movne r1, r2
 *   @0x16ed3c moveq r0, r5
 *   @0x16ed40 movne r0, r5
 *   @0x16ed44 addeq r3, r1, #1
 *   @0x16ed48 streq r3, [r4]
 *   @0x16ed4c bl 0x16d124 <_ZN7CCamera5SetIDEi>
 *   @0x16ed50 ldr r3, [r4, #0x14]
 *   @0x16ed54 ldr r2, [r4, #0x10]
 *   @0x16ed58 cmp r3, r2
 *   @0x16ed5c beq 0x16ed78 <_ZN14CCameraManager15AddCameraToListEP7CCamerai+0x5c>
 *   @0x16ed60 ldr r2, [r4, #0xc]
 *   @0x16ed64 add r1, r3, #1
 *   @0x16ed68 str r1, [r4, #0x14]
 *   @0x16ed6c str r5, [r2, r3, lsl #2]
 *   @0x16ed70 add sp, sp, #12
 *   @0x16ed74 pop {r4, r5, pc}
 *   @0x16ed78 lsl r2, r3, #1
 *   @0x16ed7c str r2, [r4, #0x10]
 *   @0x16ed80 ldr r2, [pc, #0x28]
 *   @0x16ed84 lsl r1, r3, #3
 *   @0x16ed88 ldr r0, [r4, #0xc]
 *   @0x16ed8c mov r3, #0
 *   @0x16ed90 add r2, pc, r2
 *   @0x16ed94 str r3, [sp]
 *   @0x16ed98 mov r3, #74
 *   @0x16ed9c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x16eda0 ldr r3, [r4, #0x14]
 *   @0x16eda4 mov r2, r0
 *   @0x16eda8 str r0, [r4, #0xc]
 *   @0x16edac b 0x16ed64 <_ZN14CCameraManager15AddCameraToListEP7CCamerai+0x48>
 *   @0x16edb0 andseq r2, r12, r0, lsr #5
 *
 * ══ §3/289 CCameraManager::FindCameraInList  0x16f234  size 152  38 条（0x16f234..0x16f2cc）
 * @func 0x16f234 0x16f2cc  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCamera::GetID()×2 / CCameraManager::FindCameraInList(int)+0x7c×2
 * 字段偏移 top8: 0x18×3 / 0x14×3 / 0xc×2 / 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f234 ldr r3, [r0, #0x18]
 *   @0x16f238 ldr r2, [r0, #0x14]
 *   @0x16f23c push {r4, r5, r6, lr}
 *   @0x16f240 cmp r3, r2
 *   @0x16f244 mov r5, r0
 *   @0x16f248 mov r6, r1
 *   @0x16f24c bge 0x16f270 <_ZN14CCameraManager16FindCameraInListEi+0x3c>
 *   @0x16f250 ldr r1, [r0, #0xc]
 *   @0x16f254 ldr r0, [r1, r3, lsl #2]
 *   @0x16f258 cmp r0, #0
 *   @0x16f25c beq 0x16f270 <_ZN14CCameraManager16FindCameraInListEi+0x3c>
 *   @0x16f260 bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16f264 cmp r0, r6
 *   @0x16f268 beq 0x16f2c4 <_ZN14CCameraManager16FindCameraInListEi+0x90>
 *   @0x16f26c ldr r2, [r5, #0x14]
 *   @0x16f270 cmp r2, #0
 *   @0x16f274 movgt r4, #0
 *   @0x16f278 ble 0x16f2b0 <_ZN14CCameraManager16FindCameraInListEi+0x7c>
 *   @0x16f27c ldr r3, [r5, #0xc]
 *   @0x16f280 ldr r0, [r3, r4, lsl #2]
 *   @0x16f284 cmp r0, #0
 *   @0x16f288 beq 0x16f2a4 <_ZN14CCameraManager16FindCameraInListEi+0x70>
 *   @0x16f28c bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16f290 cmp r0, r6
 *   @0x16f294 beq 0x16f2b8 <_ZN14CCameraManager16FindCameraInListEi+0x84>
 *   @0x16f298 cmp r6, r0
 *   @0x16f29c blt 0x16f2b0 <_ZN14CCameraManager16FindCameraInListEi+0x7c>
 *   @0x16f2a0 ldr r2, [r5, #0x14]
 *   @0x16f2a4 add r4, r4, #1
 *   @0x16f2a8 cmp r2, r4
 *   @0x16f2ac bgt 0x16f27c <_ZN14CCameraManager16FindCameraInListEi+0x48>
 *   @0x16f2b0 mvn r0, #0
 *   @0x16f2b4 pop {r4, r5, r6, pc}
 *   @0x16f2b8 str r4, [r5, #0x18]
 *   @0x16f2bc mov r0, r4
 *   @0x16f2c0 pop {r4, r5, r6, pc}
 *   @0x16f2c4 ldr r0, [r5, #0x18]
 *   @0x16f2c8 pop {r4, r5, r6, pc}
 *
 * ══ §4/289 topRenderBufferStack  0x1807ec  size 152  38 条（0x1807ec..0x180884）
 * @func 0x1807ec 0x180884  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: topRenderBufferStack()+0x64 / initRenderBufferStack()
 * 字段偏移 top8: 0x80×1 / 0x70×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1807ec push {r3, r4, r5, lr}
 *   @0x1807f0 mov r5, r0
 *   @0x1807f4 ldr r3, [pc, #0x80]
 *   @0x1807f8 ldr r3, [pc, r3]
 *   @0x1807fc ldrb r3, [r3]
 *   @0x180800 cmp r3, #0
 *   @0x180804 beq 0x180848 <_Z20topRenderBufferStackv+0x5c>
 *   @0x180808 ldr r3, [pc, #0x70]
 *   @0x18080c add r3, pc, r3
 *   @0x180810 ldr r4, [r3]
 *   @0x180814 cmp r4, #0
 *   @0x180818 ble 0x180850 <_Z20topRenderBufferStackv+0x64>
 *   @0x18081c sub r4, r4, #1
 *   @0x180820 mov r12, r5
 *   @0x180824 rsb r4, r4, r4, lsl #3
 *   @0x180828 add r4, r3, r4, lsl #2
 *   @0x18082c add r4, r4, #4
 *   @0x180830 ldm r4!, {r0, r1, r2, r3}
 *   @0x180834 stm r12!, {r0, r1, r2, r3}
 *   @0x180838 ldm r4, {r0, r1, r2}
 *   @0x18083c stm r12, {r0, r1, r2}
 *   @0x180840 mov r0, r5
 *   @0x180844 pop {r3, r4, r5, pc}
 *   @0x180848 bl 0x180650 <_Z21initRenderBufferStackv>
 *   @0x18084c b 0x180808 <_Z20topRenderBufferStackv+0x1c>
 *   @0x180850 mov r3, #0
 *   @0x180854 mvn r2, #0
 *   @0x180858 str r3, [r5]
 *   @0x18085c mov r0, r5
 *   @0x180860 str r3, [r5, #0x4]
 *   @0x180864 str r3, [r5, #0x8]
 *   @0x180868 str r3, [r5, #0xc]
 *   @0x18086c str r3, [r5, #0x10]
 *   @0x180870 str r2, [r5, #0x14]
 *   @0x180874 str r2, [r5, #0x18]
 *   @0x180878 pop {r3, r4, r5, pc}
 *   @0x18087c eoreq pc, r6, r12, lsr sp
 *   @0x180880 ldrshteq r1, [r2], -r0
 *
 * ══ §5/289 _CreateTextureIfInvalid  0x182500  size 152  38 条（0x182500..0x182598）
 * @func 0x182500 0x182598  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::FlushTexture(void*)
 * 字段偏移 top8: 0x10×3 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182500 push {r4, r5, r6, lr}
 *   @0x182504 subs r5, r0, #0
 *   @0x182508 mov r6, r1
 *   @0x18250c mov r4, r2
 *   @0x182510 popeq {r4, r5, r6, pc}
 *   @0x182514 cmn r2, #1
 *   @0x182518 ldr r3, [r5, #0x14]
 *   @0x18251c beq 0x182570 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x70>
 *   @0x182520 cmp r2, #1
 *   @0x182524 beq 0x18257c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x7c>
 *   @0x182528 cmp r2, #0
 *   @0x18252c bne 0x182558 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x58>
 *   @0x182530 ldr r2, [r5, #0x10]
 *   @0x182534 tst r2, #32
 *   @0x182538 beq 0x182570 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x70>
 *   @0x18253c mov r0, r5
 *   @0x182540 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x182544 mov r0, r5
 *   @0x182548 mov r1, r6
 *   @0x18254c mov r2, r4
 *   @0x182550 pop {r4, r5, r6, lr}
 *   @0x182554 b 0x182104 <_Z14_CreateTextureP7Textureb10eMipEnable>
 *   @0x182558 cmp r2, #2
 *   @0x18255c bne 0x182570 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x70>
 *   @0x182560 ldr r2, [r5, #0x10]
 *   @0x182564 and r2, r2, #48
 *   @0x182568 cmp r2, #16
 *   @0x18256c beq 0x18253c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x3c>
 *   @0x182570 cmn r3, #1
 *   @0x182574 popne {r4, r5, r6, pc}
 *   @0x182578 b 0x18253c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x3c>
 *   @0x18257c ldr r2, [r5, #0x10]
 *   @0x182580 and r2, r2, #96
 *   @0x182584 cmp r2, #64
 *   @0x182588 beq 0x18253c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x3c>
 *   @0x18258c cmn r3, #1
 *   @0x182590 popne {r4, r5, r6, pc}
 *   @0x182594 b 0x18253c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x3c>
 *
 * ══ §6/289 LoadSave::HTTP_Get  0x18fc68  size 152  38 条（0x18fc68..0x18fd00）
 * @func 0x18fc68 0x18fd00  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool)
 * 字段偏移 top8: 0x28×3 / 0x24×2 / 0x8×1 / 0x4×1 / 0x29c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18fc68 push {r4, r5, r6, r7, r8, lr}
 *   @0x18fc6c sub sp, sp, #16
 *   @0x18fc70 mov r4, r0
 *   @0x18fc74 mov r0, #68
 *   @0x18fc78 mov r7, r2
 *   @0x18fc7c mov r8, r3
 *   @0x18fc80 ldr r6, [sp, #0x28]
 *   @0x18fc84 bl 0x27c524 <_Znwj>
 *   @0x18fc88 mov r12, #0
 *   @0x18fc8c mov r2, #131072
 *   @0x18fc90 str r12, [sp, #0x8]
 *   @0x18fc94 mov r3, r7
 *   @0x18fc98 mov r1, r4
 *   @0x18fc9c str r8, [sp]
 *   @0x18fca0 str r6, [sp, #0x4]
 *   @0x18fca4 mov r5, r0
 *   @0x18fca8 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x18fcac bl 0x290274 <getJNIEnv>
 *   @0x18fcb0 mov r1, r4
 *   @0x18fcb4 ldr r3, [r0]
 *   @0x18fcb8 ldr r3, [r3, #0x29c]
 *   @0x18fcbc blx r3
 *   @0x18fcc0 mov r4, r0
 *   @0x18fcc4 bl 0x290274 <getJNIEnv>
 *   @0x18fcc8 ldr r1, [pc, #0x28]
 *   @0x18fccc mov r3, r4
 *   @0x18fcd0 ldr r2, [pc, #0x24]
 *   @0x18fcd4 ldr r12, [r5, #0x24]
 *   @0x18fcd8 ldr r1, [pc, r1]
 *   @0x18fcdc ldr r2, [pc, r2]
 *   @0x18fce0 ldr r1, [r1]
 *   @0x18fce4 ldr r2, [r2]
 *   @0x18fce8 str r12, [sp, #0x28]
 *   @0x18fcec add sp, sp, #16
 *   @0x18fcf0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x18fcf4 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x18fcf8 eoreq sp, r5, r12, asr #25
 *   @0x18fcfc eoreq r0, r6, r0, lsl #19
 *
 * ══ §7/289 CLayerManager::CleanElementRuntimeData  0x1b8ed0  size 152  38 条（0x1b8ed0..0x1b8f68）
 * @func 0x1b8ed0 0x1b8f68  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::CleanTileElementRuntimeData(CLayerTileElement*) / CLayerManager::CleanBackgroundElementRuntimeData(CLayerBackgroundElement*) / CLayerManager::CleanInstanceElementRuntimeData(CLayerInstanceElement*) / CLayerManager::CleanOldTilemapElementRuntimeData(CLayerOldTilemapElement*) / CLayerManager::CleanSpriteElementRuntimeData(CLayerSpriteElement*) / CLayerManager::CleanTilemapElementRuntimeData(CLayerTilemapElement*) / CLayerManager::CleanParticleElementRuntimeData(CLayerParticleElement*)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8ed0 push {r4, lr}
 *   @0x1b8ed4 subs r4, r0, #0
 *   @0x1b8ed8 popeq {r4, pc}
 *   @0x1b8edc ldr r3, [r4]
 *   @0x1b8ee0 sub r3, r3, #1
 *   @0x1b8ee4 cmp r3, #6
 *   @0x1b8ee8 addls pc, pc, r3, lsl #2
 *   @0x1b8eec b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44>
 *   @0x1b8ef0 b 0x1b8f20 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x50>
 *   @0x1b8ef4 b 0x1b8f2c <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x5c>
 *   @0x1b8ef8 b 0x1b8f38 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x68>
 *   @0x1b8efc b 0x1b8f44 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x74>
 *   @0x1b8f00 b 0x1b8f50 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x80>
 *   @0x1b8f04 b 0x1b8f5c <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x8c>
 *   @0x1b8f08 b 0x1b8f0c <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x3c>
 *   @0x1b8f0c mov r0, r4
 *   @0x1b8f10 bl 0x1b8ecc <_ZN13CLayerManager27CleanTileElementRuntimeDataEP17CLayerTileElement>
 *   @0x1b8f14 mov r3, #0
 *   @0x1b8f18 strb r3, [r4, #0x8]
 *   @0x1b8f1c pop {r4, pc}
 *   @0x1b8f20 mov r0, r4
 *   @0x1b8f24 bl 0x1b8d98 <_ZN13CLayerManager33CleanBackgroundElementRuntimeDataEP23CLayerBackgroundElement>
 *   @0x1b8f28 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44>
 *   @0x1b8f2c mov r0, r4
 *   @0x1b8f30 bl 0x1b8d9c <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement>
 *   @0x1b8f34 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44>
 *   @0x1b8f38 mov r0, r4
 *   @0x1b8f3c bl 0x1b8e0c <_ZN13CLayerManager33CleanOldTilemapElementRuntimeDataEP23CLayerOldTilemapElement>
 *   @0x1b8f40 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44>
 *   @0x1b8f44 mov r0, r4
 *   @0x1b8f48 bl 0x1b8ec0 <_ZN13CLayerManager29CleanSpriteElementRuntimeDataEP19CLayerSpriteElement>
 *   @0x1b8f4c b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44>
 *   @0x1b8f50 mov r0, r4
 *   @0x1b8f54 bl 0x1b8ec4 <_ZN13CLayerManager30CleanTilemapElementRuntimeDataEP20CLayerTilemapElement>
 *   @0x1b8f58 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44>
 *   @0x1b8f5c mov r0, r4
 *   @0x1b8f60 bl 0x1b8ec8 <_ZN13CLayerManager31CleanParticleElementRuntimeDataEP21CLayerParticleElement>
 *   @0x1b8f64 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44>
 *
 * ══ §8/289 ov_pcm_total  0x23138c  size 152  38 条（0x23138c..0x231424）
 * @func 0x23138c 0x231424  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_pcm_total+0x8c×2 / ov_pcm_total+0x48 / ov_pcm_total+0x80 / ov_pcm_total / ov_pcm_total+0x5c
 * 字段偏移 top8: 0x34×2 / 0x58×1 / 0x4×1 / 0x44×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23138c push {r3, r4, r5, r6, r7, lr}
 *   @0x231390 mov r7, r0
 *   @0x231394 ldr r3, [r0, #0x58]
 *   @0x231398 cmp r3, #1
 *   @0x23139c ble 0x231418 <ov_pcm_total+0x8c>
 *   @0x2313a0 ldr r3, [r0, #0x4]
 *   @0x2313a4 cmp r3, #0
 *   @0x2313a8 beq 0x231418 <ov_pcm_total+0x8c>
 *   @0x2313ac ldr r3, [r0, #0x34]
 *   @0x2313b0 cmp r3, r1
 *   @0x2313b4 ble 0x231418 <ov_pcm_total+0x8c>
 *   @0x2313b8 cmp r1, #0
 *   @0x2313bc blt 0x2313d4 <ov_pcm_total+0x48>
 *   @0x2313c0 ldr r3, [r0, #0x44]
 *   @0x2313c4 add r1, r3, r1, lsl #4
 *   @0x2313c8 ldr r0, [r1, #0x8]
 *   @0x2313cc ldr r1, [r1, #0xc]
 *   @0x2313d0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2313d4 cmp r3, #0
 *   @0x2313d8 mov r4, #0
 *   @0x2313dc mov r5, #0
 *   @0x2313e0 ble 0x23140c <ov_pcm_total+0x80>
 *   @0x2313e4 mov r6, #0
 *   @0x2313e8 mov r1, r6
 *   @0x2313ec mov r0, r7
 *   @0x2313f0 bl 0x23138c <ov_pcm_total>
 *   @0x2313f4 ldr r3, [r7, #0x34]
 *   @0x2313f8 add r6, r6, #1
 *   @0x2313fc adds r4, r4, r0
 *   @0x231400 adc r5, r5, r1
 *   @0x231404 cmp r6, r3
 *   @0x231408 blt 0x2313e8 <ov_pcm_total+0x5c>
 *   @0x23140c mov r0, r4
 *   @0x231410 mov r1, r5
 *   @0x231414 pop {r3, r4, r5, r6, r7, pc}
 *   @0x231418 mvn r0, #130
 *   @0x23141c mvn r1, #0
 *   @0x231420 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §9/289 __gtdf2  0x31afa4  size 152  38 条（0x31afa4..0x31b03c）
 * @func 0x31afa4 0x31b03c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31afa4 mvn r12, #0
 *   @0x31afa8 b 0x31afb8 <__nedf2+0x4>
 *   @0x31afac mov r12, #1
 *   @0x31afb0 b 0x31afb8 <__nedf2+0x4>
 *   @0x31afb4 mov r12, #1
 *   @0x31afb8 str r12, [sp, #-0x4]!
 *   @0x31afbc lsl r12, r1, #1
 *   @0x31afc0 mvns r12, r12, asr #21
 *   @0x31afc4 lsl r12, r3, #1
 *   @0x31afc8 mvnsne r12, r12, asr #21
 *   @0x31afcc beq 0x31b00c <__nedf2+0x58>
 *   @0x31afd0 add sp, sp, #4
 *   @0x31afd4 orrs r12, r0, r1, lsl #1
 *   @0x31afd8 orrseq r12, r2, r3, lsl #1
 *   @0x31afdc teqne r1, r3
 *   @0x31afe0 teqeq r0, r2
 *   @0x31afe4 moveq r0, #0
 *   @0x31afe8 bxeq lr
 *   @0x31afec cmn r0, #0
 *   @0x31aff0 teq r1, r3
 *   @0x31aff4 cmppl r1, r3
 *   @0x31aff8 cmpeq r0, r2
 *   @0x31affc asrhs r0, r3, #31
 *   @0x31b000 mvnlo r0, r3, asr #31
 *   @0x31b004 orr r0, r0, #1
 *   @0x31b008 bx lr
 *   @0x31b00c lsl r12, r1, #1
 *   @0x31b010 mvns r12, r12, asr #21
 *   @0x31b014 bne 0x31b020 <__nedf2+0x6c>
 *   @0x31b018 orrs r12, r0, r1, lsl #12
 *   @0x31b01c bne 0x31b034 <__nedf2+0x80>
 *   @0x31b020 lsl r12, r3, #1
 *   @0x31b024 mvns r12, r12, asr #21
 *   @0x31b028 bne 0x31afd0 <__nedf2+0x1c>
 *   @0x31b02c orrs r12, r2, r3, lsl #12
 *   @0x31b030 beq 0x31afd0 <__nedf2+0x1c>
 *   @0x31b034 ldr r0, [sp], #4
 *   @0x31b038 bx lr
 *
 * ══ §10/289 CSkeletonInstance::GetAnimation  0xc01b0  size 148  37 条（0xc01b0..0xc0244）
 * @func 0xc01b0 0xc0244  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::GetAnimation(int) const+0x50
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x10×1 / 0x2×1 / 0x34×1 / 0x2c×1 / 0x24×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc01b0 cmp r1, #0
 *   @0xc01b4 blt 0xc0200 <_ZNK17CSkeletonInstance12GetAnimationEi+0x50>
 *   @0xc01b8 ldr r3, [r0, #0x28]
 *   @0xc01bc cmp r3, #0
 *   @0xc01c0 beq 0xc020c <_ZNK17CSkeletonInstance12GetAnimationEi+0x5c>
 *   @0xc01c4 ldr r2, [r3, #0xc]
 *   @0xc01c8 cmp r1, r2
 *   @0xc01cc bge 0xc01f4 <_ZNK17CSkeletonInstance12GetAnimationEi+0x44>
 *   @0xc01d0 ldr r3, [r3, #0x10]
 *   @0xc01d4 ldr r3, [r3, r1, lsl #2]
 *   @0xc01d8 cmp r3, #0
 *   @0xc01dc beq 0xc0218 <_ZNK17CSkeletonInstance12GetAnimationEi+0x68>
 *   @0xc01e0 ldr r3, [r3, #0xc]
 *   @0xc01e4 cmp r3, #0
 *   @0xc01e8 beq 0xc0224 <_ZNK17CSkeletonInstance12GetAnimationEi+0x74>
 *   @0xc01ec ldr r0, [r3]
 *   @0xc01f0 bx lr
 *   @0xc01f4 ldr r0, [pc, #0x34]
 *   @0xc01f8 add r0, pc, r0
 *   @0xc01fc bx lr
 *   @0xc0200 ldr r0, [pc, #0x2c]
 *   @0xc0204 add r0, pc, r0
 *   @0xc0208 bx lr
 *   @0xc020c ldr r0, [pc, #0x24]
 *   @0xc0210 add r0, pc, r0
 *   @0xc0214 bx lr
 *   @0xc0218 ldr r0, [pc, #0x1c]
 *   @0xc021c add r0, pc, r0
 *   @0xc0220 bx lr
 *   @0xc0224 ldr r0, [pc, #0x14]
 *   @0xc0228 add r0, pc, r0
 *   @0xc022c bx lr
 *   @0xc0230 eoreq lr, r6, lr, lsr r9
 *   @0xc0234 eoreq lr, r6, r2, lsr r9
 *   @0xc0238 eoreq lr, r6, r6, lsr #18
 *   @0xc023c eoreq lr, r6, r10, lsl r9
 *   @0xc0240 eoreq lr, r6, lr, lsl #18
 *
 * ══ §11/289 F_Shader_Set  0x1e207c  size 148  37 条（0x1e207c..0x1e2110）
 * @func 0x1e207c 0x1e2110  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Set(Shader*)×2 / YYGetInt32(RValue const*, int) / F_Shader_Set(RValue&, CInstance*, CInstance*, int, RValue*)+0x34 / F_Shader_Set(RValue&, CInstance*, CInstance*, int, RValue*)+0x48
 * 字段偏移 top8: 0x8×1 / 0x5c×1 / 0x4c×1 / 0x3c×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e207c push {r3, lr}
 *   @0x1e2080 mov r1, #0
 *   @0x1e2084 ldr r0, [sp, #0x8]
 *   @0x1e2088 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e208c cmn r0, #1
 *   @0x1e2090 beq 0x1e20f4 <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1e2094 cmp r0, #0
 *   @0x1e2098 blt 0x1e20b0 <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1e209c ldr r3, [pc, #0x5c]
 *   @0x1e20a0 ldr r3, [pc, r3]
 *   @0x1e20a4 ldr r3, [r3]
 *   @0x1e20a8 cmp r0, r3
 *   @0x1e20ac blt 0x1e20c4 <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1e20b0 ldr r0, [pc, #0x4c]
 *   @0x1e20b4 mov r1, #0
 *   @0x1e20b8 pop {r3, lr}
 *   @0x1e20bc add r0, pc, r0
 *   @0x1e20c0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e20c4 ldr r3, [pc, #0x3c]
 *   @0x1e20c8 ldr r3, [pc, r3]
 *   @0x1e20cc ldr r3, [r3]
 *   @0x1e20d0 ldr r0, [r3, r0, lsl #2]
 *   @0x1e20d4 bl 0x1e2024 <_Z10Shader_SetP6Shader>
 *   @0x1e20d8 ldr r3, [pc, #0x2c]
 *   @0x1e20dc ldr r3, [pc, r3]
 *   @0x1e20e0 ldrb r3, [r3]
 *   @0x1e20e4 cmp r3, #0
 *   @0x1e20e8 popeq {r3, pc}
 *   @0x1e20ec pop {r3, lr}
 *   @0x1e20f0 b 0x1e1520 <_Z11FlushShaderv>
 *   @0x1e20f4 mov r0, #0
 *   @0x1e20f8 bl 0x1e2024 <_Z10Shader_SetP6Shader>
 *   @0x1e20fc b 0x1e20d8 <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1e2100 eoreq lr, r0, r4, lsr #25
 *   @0x1e2104 ldrheq pc, [r6], -r8
 *   @0x1e2108 eoreq lr, r0, r0, lsl #25
 *   @0x1e210c eoreq lr, r0, r0, ror r12
 *
 * ══ §12/289 CTimeLine::FindLarger  0x1f1c70  size 148  37 条（0x1f1c70..0x1f1d04）
 * @func 0x1f1c70 0x1f1d04  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimeLine::FindLarger(double)+0x78 / CTimeLine::FindLarger(double)+0x8c / CTimeLine::FindLarger(double)+0x80
 * 字段偏移 top8: 0x10×1 / 0x14×1 / 0x2×1 / 0x4×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1c70 vmov d6, r2, r3
 *   @0x1f1c74 ldr r2, [r0, #0x10]
 *   @0x1f1c78 cmp r2, #0
 *   @0x1f1c7c beq 0x1f1ce8 <_ZN9CTimeLine10FindLargerEd+0x78>
 *   @0x1f1c80 ldr r1, [r0, #0x14]
 *   @0x1f1c84 sub r3, r2, #1
 *   @0x1f1c88 ldr r3, [r1, r3, lsl #2]
 *   @0x1f1c8c vmov s14, r3
 *   @0x1f1c90 vcvt.f64.s32 d7, s14
 *   @0x1f1c94 vcmpe.f64 d7, d6
 *   @0x1f1c98 vmrs APSR_nzcv, fpscr
 *   @0x1f1c9c bmi 0x1f1ce8 <_ZN9CTimeLine10FindLargerEd+0x78>
 *   @0x1f1ca0 cmp r2, #0
 *   @0x1f1ca4 ble 0x1f1ce8 <_ZN9CTimeLine10FindLargerEd+0x78>
 *   @0x1f1ca8 vldr s11, [r1]
 *   @0x1f1cac vcvt.f64.s32 d7, s11
 *   @0x1f1cb0 vcmpe.f64 d6, d7
 *   @0x1f1cb4 vmrs APSR_nzcv, fpscr
 *   @0x1f1cb8 bls 0x1f1cfc <_ZN9CTimeLine10FindLargerEd+0x8c>
 *   @0x1f1cbc mov r3, #0
 *   @0x1f1cc0 b 0x1f1cdc <_ZN9CTimeLine10FindLargerEd+0x6c>
 *   @0x1f1cc4 ldr r0, [r1, #0x4]!
 *   @0x1f1cc8 vmov s14, r0
 *   @0x1f1ccc vcvt.f64.s32 d7, s14
 *   @0x1f1cd0 vcmpe.f64 d6, d7
 *   @0x1f1cd4 vmrs APSR_nzcv, fpscr
 *   @0x1f1cd8 bls 0x1f1cf0 <_ZN9CTimeLine10FindLargerEd+0x80>
 *   @0x1f1cdc add r3, r3, #1
 *   @0x1f1ce0 cmp r3, r2
 *   @0x1f1ce4 bne 0x1f1cc4 <_ZN9CTimeLine10FindLargerEd+0x54>
 *   @0x1f1ce8 mov r0, r2
 *   @0x1f1cec bx lr
 *   @0x1f1cf0 mov r2, r3
 *   @0x1f1cf4 mov r0, r2
 *   @0x1f1cf8 bx lr
 *   @0x1f1cfc mov r2, #0
 *   @0x1f1d00 b 0x1f1ce8 <_ZN9CTimeLine10FindLargerEd+0x78>
 *
 * ══ §13/289 ogg_stream_init  0x2341a4  size 148  37 条（0x2341a4..0x234238）
 * @func 0x2341a4 0x234238  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×3 / 0xb65b0 / ogg_stream_clear
 * 字段偏移 top8: 0x4×1 / 0x18×1 / 0x10×1 / 0x14×1 / 0x150×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2341a4 push {r3, r4, r5, r6, r7, lr}
 *   @0x2341a8 subs r4, r0, #0
 *   @0x2341ac mov r7, r1
 *   @0x2341b0 beq 0x234220 <ogg_stream_init+0x7c>
 *   @0x2341b4 mov r1, #0
 *   @0x2341b8 mov r2, #360
 *   @0x2341bc bl 0xb65b0 <memset@plt>
 *   @0x2341c0 mov r3, #16384
 *   @0x2341c4 mov r0, r3
 *   @0x2341c8 str r3, [r4, #0x4]
 *   @0x2341cc mov r3, #1024
 *   @0x2341d0 str r3, [r4, #0x18]
 *   @0x2341d4 bl 0xb6544 <malloc@plt>
 *   @0x2341d8 mov r5, r0
 *   @0x2341dc mov r0, #4096
 *   @0x2341e0 str r5, [r4]
 *   @0x2341e4 bl 0xb6544 <malloc@plt>
 *   @0x2341e8 mov r6, r0
 *   @0x2341ec mov r0, #8192
 *   @0x2341f0 str r6, [r4, #0x10]
 *   @0x2341f4 bl 0xb6544 <malloc@plt>
 *   @0x2341f8 cmp r5, #0
 *   @0x2341fc str r0, [r4, #0x14]
 *   @0x234200 beq 0x234228 <ogg_stream_init+0x84>
 *   @0x234204 cmp r6, #0
 *   @0x234208 beq 0x234228 <ogg_stream_init+0x84>
 *   @0x23420c cmp r0, #0
 *   @0x234210 beq 0x234228 <ogg_stream_init+0x84>
 *   @0x234214 str r7, [r4, #0x150]
 *   @0x234218 mov r0, #0
 *   @0x23421c pop {r3, r4, r5, r6, r7, pc}
 *   @0x234220 mvn r0, #0
 *   @0x234224 pop {r3, r4, r5, r6, r7, pc}
 *   @0x234228 mov r0, r4
 *   @0x23422c bl 0x234150 <ogg_stream_clear>
 *   @0x234230 mvn r0, #0
 *   @0x234234 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §14/289 lo0bits_D2A  0x23d2d4  size 148  37 条（0x23d2d4..0x23d368）
 * @func 0x23d2d4 0x23d368  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d2d4 ldr r3, [r0]
 *   @0x23d2d8 mov r2, r0
 *   @0x23d2dc ands r0, r3, #7
 *   @0x23d2e0 beq 0x23d308 <lo0bits_D2A+0x34>
 *   @0x23d2e4 tst r3, #1
 *   @0x23d2e8 bne 0x23d360 <lo0bits_D2A+0x8c>
 *   @0x23d2ec tst r3, #2
 *   @0x23d2f0 lsrne r3, r3, #1
 *   @0x23d2f4 lsreq r3, r3, #2
 *   @0x23d2f8 movne r0, #1
 *   @0x23d2fc moveq r0, #2
 *   @0x23d300 str r3, [r2]
 *   @0x23d304 bx lr
 *   @0x23d308 uxth r1, r3
 *   @0x23d30c cmp r1, #0
 *   @0x23d310 lsreq r3, r3, #16
 *   @0x23d314 moveq r0, #16
 *   @0x23d318 tst r3, #255
 *   @0x23d31c lsreq r3, r3, #8
 *   @0x23d320 addeq r0, r0, #8
 *   @0x23d324 tst r3, #15
 *   @0x23d328 lsreq r3, r3, #4
 *   @0x23d32c addeq r0, r0, #4
 *   @0x23d330 tst r3, #3
 *   @0x23d334 lsreq r3, r3, #2
 *   @0x23d338 addeq r0, r0, #2
 *   @0x23d33c tst r3, #1
 *   @0x23d340 bne 0x23d358 <lo0bits_D2A+0x84>
 *   @0x23d344 lsrs r3, r3, #1
 *   @0x23d348 bne 0x23d354 <lo0bits_D2A+0x80>
 *   @0x23d34c mov r0, #32
 *   @0x23d350 bx lr
 *   @0x23d354 add r0, r0, #1
 *   @0x23d358 str r3, [r2]
 *   @0x23d35c bx lr
 *   @0x23d360 mov r0, #0
 *   @0x23d364 bx lr
 *
 * ══ §15/289 spAnimationState_clearTrack  0x283558  size 148  37 条（0x283558..0x2835ec）
 * @func 0x283558 0x2835ec  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAnimationState_clearTrack+0x8c
 * 字段偏移 top8: 0x10×2 / 0x2×2 / 0xc×1 / 0x28×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283558 ldr r3, [r0, #0xc]
 *   @0x28355c push {r4, r5, r6, lr}
 *   @0x283560 cmp r3, r1
 *   @0x283564 sub sp, sp, #8
 *   @0x283568 mov r4, r0
 *   @0x28356c mov r5, r1
 *   @0x283570 ble 0x2835e4 <spAnimationState_clearTrack+0x8c>
 *   @0x283574 ldr r3, [r0, #0x10]
 *   @0x283578 ldr r6, [r3, r1, lsl #2]
 *   @0x28357c cmp r6, #0
 *   @0x283580 beq 0x2835e4 <spAnimationState_clearTrack+0x8c>
 *   @0x283584 ldr r12, [r6, #0x28]
 *   @0x283588 cmp r12, #0
 *   @0x28358c beq 0x2835a0 <spAnimationState_clearTrack+0x48>
 *   @0x283590 mov r3, #0
 *   @0x283594 mov r2, #1
 *   @0x283598 str r3, [sp]
 *   @0x28359c blx r12
 *   @0x2835a0 ldr r12, [r4, #0x8]
 *   @0x2835a4 cmp r12, #0
 *   @0x2835a8 beq 0x2835c4 <spAnimationState_clearTrack+0x6c>
 *   @0x2835ac mov r3, #0
 *   @0x2835b0 mov r0, r4
 *   @0x2835b4 str r3, [sp]
 *   @0x2835b8 mov r1, r5
 *   @0x2835bc mov r2, #1
 *   @0x2835c0 blx r12
 *   @0x2835c4 ldr r3, [r4, #0x10]
 *   @0x2835c8 mov r2, #0
 *   @0x2835cc mov r1, r6
 *   @0x2835d0 mov r0, r4
 *   @0x2835d4 str r2, [r3, r5, lsl #2]
 *   @0x2835d8 add sp, sp, #8
 *   @0x2835dc pop {r4, r5, r6, lr}
 *   @0x2835e0 b 0x28319c <_spAnimationState_disposeAllEntries>
 *   @0x2835e4 add sp, sp, #8
 *   @0x2835e8 pop {r4, r5, r6, pc}
 *
 * ══ §16/289 ReadString  0x29e69c  size 148  37 条（0x29e69c..0x29e730）
 * @func 0x29e69c 0x29e730  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / ReadString(Buffer_Standard*)+0x88 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29e69c ldr r3, [r0]
 *   @0x29e6a0 mov r1, #5
 *   @0x29e6a4 push {r4, r5, r6, r7, r8, lr}
 *   @0x29e6a8 add r5, r0, #44
 *   @0x29e6ac ldr r3, [r3, #0xc]
 *   @0x29e6b0 mov r6, r0
 *   @0x29e6b4 mov r2, r5
 *   @0x29e6b8 blx r3
 *   @0x29e6bc mov r1, #0
 *   @0x29e6c0 mov r0, r5
 *   @0x29e6c4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29e6c8 ldr r1, [pc, #0x5c]
 *   @0x29e6cc mov r2, #85
 *   @0x29e6d0 mov r3, #1
 *   @0x29e6d4 add r1, pc, r1
 *   @0x29e6d8 mov r8, r0
 *   @0x29e6dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29e6e0 cmp r8, #0
 *   @0x29e6e4 mov r7, r0
 *   @0x29e6e8 ble 0x29e724 <_Z10ReadStringP15Buffer_Standard+0x88>
 *   @0x29e6ec mov r4, #0
 *   @0x29e6f0 ldr r3, [r6]
 *   @0x29e6f4 mov r1, #1
 *   @0x29e6f8 mov r2, r5
 *   @0x29e6fc mov r0, r6
 *   @0x29e700 ldr r3, [r3, #0xc]
 *   @0x29e704 blx r3
 *   @0x29e708 mov r0, r5
 *   @0x29e70c mov r1, #0
 *   @0x29e710 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29e714 strb r0, [r7, r4]
 *   @0x29e718 add r4, r4, #1
 *   @0x29e71c cmp r8, r4
 *   @0x29e720 bne 0x29e6f0 <_Z10ReadStringP15Buffer_Standard+0x54>
 *   @0x29e724 mov r0, r7
 *   @0x29e728 pop {r4, r5, r6, r7, r8, pc}
 *   @0x29e72c strdeq r11, r12, [r11], -r12
 *
 * ══ §17/289 F_DsQueueSize  0xfbf24  size 144  36 条（0xfbf24..0xfbfb4）
 * @func 0xfbf24 0xfbfb4  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsQueueSize(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / CDS_Queue::Size()
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbf24 push {r4, lr}
 *   @0xfbf28 mov r1, #0
 *   @0xfbf2c mov r4, r0
 *   @0xfbf30 ldr r0, [sp, #0x8]
 *   @0xfbf34 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbf38 cmp r0, #0
 *   @0xfbf3c blt 0xfbf94 <_Z13F_DsQueueSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfbf40 ldr r3, [pc, #0x60]
 *   @0xfbf44 ldr r3, [pc, r3]
 *   @0xfbf48 ldr r3, [r3]
 *   @0xfbf4c cmp r0, r3
 *   @0xfbf50 bge 0xfbf94 <_Z13F_DsQueueSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfbf54 ldr r3, [pc, #0x50]
 *   @0xfbf58 ldr r3, [pc, r3]
 *   @0xfbf5c ldr r3, [r3, #0x4]
 *   @0xfbf60 ldr r0, [r3, r0, lsl #2]
 *   @0xfbf64 cmp r0, #0
 *   @0xfbf68 beq 0xfbf94 <_Z13F_DsQueueSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfbf6c mov r3, #0
 *   @0xfbf70 str r3, [r4, #0xc]
 *   @0xfbf74 bl 0x2052b4 <_ZN9CDS_Queue4SizeEv>
 *   @0xfbf78 vmov s15, r0
 *   @0xfbf7c vcvt.f64.s32 d7, s15
 *   @0xfbf80 vmov r0, r1, d7
 *   @0xfbf84 vmov r2, s14
 *   @0xfbf88 mov r3, r1
 *   @0xfbf8c stm r4, {r2, r3}
 *   @0xfbf90 pop {r4, pc}
 *   @0xfbf94 ldr r0, [pc, #0x14]
 *   @0xfbf98 mov r1, #0
 *   @0xfbf9c pop {r4, lr}
 *   @0xfbfa0 add r0, pc, r0
 *   @0xfbfa4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbfa8 eoreq r1, pc, r8, lsr #30
 *   @0xfbfac eoreq r1, pc, r8, lsl pc
 *   @0xfbfb0 eoreq r11, r3, r12, asr r12
 *
 * ══ §18/289 utf8_strrchr  0x10fbbc  size 144  36 条（0x10fbbc..0x10fc4c）
 * @func 0x10fbbc 0x10fc4c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / utf8_strrchr+0x30 / utf8_strrchr+0x80 / utf8_extract_char
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10fbbc push {r4, r5, r6, r7, r8, lr}
 *   @0x10fbc0 sub sp, sp, #8
 *   @0x10fbc4 mov r5, r0
 *   @0x10fbc8 mov r6, r1
 *   @0x10fbcc mov r8, r2
 *   @0x10fbd0 bl 0xb6538 <strlen@plt>
 *   @0x10fbd4 adds r4, r5, r0
 *   @0x10fbd8 addlo r7, sp, #4
 *   @0x10fbdc blo 0x10fbec <utf8_strrchr+0x30>
 *   @0x10fbe0 b 0x10fc3c <utf8_strrchr+0x80>
 *   @0x10fbe4 cmp r4, r5
 *   @0x10fbe8 blo 0x10fc3c <utf8_strrchr+0x80>
 *   @0x10fbec mov r0, r7
 *   @0x10fbf0 str r4, [sp, #0x4]
 *   @0x10fbf4 bl 0x10fb38 <utf8_extract_char>
 *   @0x10fbf8 cmp r6, r0
 *   @0x10fbfc beq 0x10fc40 <utf8_strrchr+0x84>
 *   @0x10fc00 cmp r8, r0
 *   @0x10fc04 beq 0x10fc40 <utf8_strrchr+0x84>
 *   @0x10fc08 ldrsb r3, [r4]
 *   @0x10fc0c cmp r3, #0
 *   @0x10fc10 subge r4, r4, #1
 *   @0x10fc14 bge 0x10fbe4 <utf8_strrchr+0x28>
 *   @0x10fc18 sub r3, r4, #1
 *   @0x10fc1c mov r4, r3
 *   @0x10fc20 sub r3, r3, #1
 *   @0x10fc24 ldrb r12, [r4]
 *   @0x10fc28 and r12, r12, #192
 *   @0x10fc2c cmp r12, #128
 *   @0x10fc30 beq 0x10fc1c <utf8_strrchr+0x60>
 *   @0x10fc34 cmp r4, r5
 *   @0x10fc38 bhs 0x10fbec <utf8_strrchr+0x30>
 *   @0x10fc3c mov r4, #0
 *   @0x10fc40 mov r0, r4
 *   @0x10fc44 add sp, sp, #8
 *   @0x10fc48 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §19/289 utf8_add_char  0x10fe28  size 144  36 条（0x10fe28..0x10feb8）
 * @func 0x10fe28 0x10feb8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_add_char+0x50 / utf8_add_char+0x64
 * 字段偏移 top8: 0x1×2 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10fe28 cmp r1, #127
 *   @0x10fe2c ldr r3, [r0]
 *   @0x10fe30 bls 0x10fe78 <utf8_add_char+0x50>
 *   @0x10fe34 cmp r1, #2048
 *   @0x10fe38 blo 0x10fe8c <utf8_add_char+0x64>
 *   @0x10fe3c lsr r12, r1, #12
 *   @0x10fe40 ubfx r2, r1, #0x6, #0x6
 *   @0x10fe44 sub r12, r12, #32
 *   @0x10fe48 strb r12, [r3]
 *   @0x10fe4c ldr r3, [r0]
 *   @0x10fe50 sub r2, r2, #128
 *   @0x10fe54 and r1, r1, #63
 *   @0x10fe58 sub r1, r1, #128
 *   @0x10fe5c strb r2, [r3, #0x1]
 *   @0x10fe60 ldr r3, [r0]
 *   @0x10fe64 strb r1, [r3, #0x2]
 *   @0x10fe68 ldr r3, [r0]
 *   @0x10fe6c add r3, r3, #3
 *   @0x10fe70 str r3, [r0]
 *   @0x10fe74 bx lr
 *   @0x10fe78 strb r1, [r3]
 *   @0x10fe7c ldr r3, [r0]
 *   @0x10fe80 add r3, r3, #1
 *   @0x10fe84 str r3, [r0]
 *   @0x10fe88 bx lr
 *   @0x10fe8c asr r2, r1, #6
 *   @0x10fe90 and r1, r1, #63
 *   @0x10fe94 sub r2, r2, #64
 *   @0x10fe98 strb r2, [r3]
 *   @0x10fe9c ldr r3, [r0]
 *   @0x10fea0 sub r1, r1, #128
 *   @0x10fea4 strb r1, [r3, #0x1]
 *   @0x10fea8 ldr r3, [r0]
 *   @0x10feac add r3, r3, #2
 *   @0x10feb0 str r3, [r0]
 *   @0x10feb4 bx lr
 *
 * ══ §20/289 RenderStateManager::SetRenderState  0x167e64  size 144  36 条（0x167e64..0x167ef4）
 * @func 0x167e64 0x167ef4  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1e0×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167e64 add r3, r0, r1, lsl #2
 *   @0x167e68 push {r4, r5, r6, r7, r8}
 *   @0x167e6c ldr r12, [r3, #0x1e0]
 *   @0x167e70 cmp r12, r2
 *   @0x167e74 beq 0x167ec4 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej+0x60>
 *   @0x167e78 ldr r12, [r3, #0x10]
 *   @0x167e7c cmp r12, r2
 *   @0x167e80 mov r12, #1
 *   @0x167e84 beq 0x167ecc <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej+0x68>
 *   @0x167e88 sub r6, r1, #32
 *   @0x167e8c rsb r8, r1, #32
 *   @0x167e90 lsl r5, r12, r6
 *   @0x167e94 ldrd r6, r7, [r0]
 *   @0x167e98 orr r5, r5, r12, lsr r8
 *   @0x167e9c lsl r4, r12, r1
 *   @0x167ea0 orr r4, r4, r6
 *   @0x167ea4 orr r5, r5, r7
 *   @0x167ea8 strd r4, r5, [r0]
 *   @0x167eac str r2, [r3, #0x1e0]
 *   @0x167eb0 mov r1, #944
 *   @0x167eb4 ldrd r2, r3, [r0, #8]
 *   @0x167eb8 orr r2, r2, r4
 *   @0x167ebc orr r3, r3, r5
 *   @0x167ec0 strd r2, r3, [r0, r1]
 *   @0x167ec4 pop {r4, r5, r6, r7, r8}
 *   @0x167ec8 bx lr
 *   @0x167ecc sub r4, r1, #32
 *   @0x167ed0 rsb r8, r1, #32
 *   @0x167ed4 lsl r7, r12, r4
 *   @0x167ed8 ldrd r4, r5, [r0]
 *   @0x167edc orr r7, r7, r12, lsr r8
 *   @0x167ee0 lsl r6, r12, r1
 *   @0x167ee4 bic r4, r4, r6
 *   @0x167ee8 bic r5, r5, r7
 *   @0x167eec strd r4, r5, [r0]
 *   @0x167ef0 b 0x167eac <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej+0x48>
 *
 * ══ §21/289 IO_Key_Clear_All  0x18bf94  size 144  36 条（0x18bf94..0x18c024）
 * @func 0x18bf94 0x18c024  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18bf9c→0x534ea4, 0x18bfb4→0x534ea0, 0x18bfb8→0x5356aa, 0x18bfc4→0x534da0, 0x18bfc8→0x534ba0, 0x18bfd0→0x534ca0
 * 调用序列: 无
 * 字段偏移 top8: 0x54×2 / 0x4c×2 / 0x6c×1 / 0x68×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bf94 ldr r1, [pc, #0x6c]
 *   @0x18bf98 mov r0, #0
 *   @0x18bf9c ldr r12, [pc, #0x68]
 *   @0x18bfa0 mov r3, r0
 *   @0x18bfa4 add r1, pc, r1
 *   @0x18bfa8 mov r2, r0
 *   @0x18bfac push {r4, r5, r6, r7}
 *   @0x18bfb0 ldr r7, [r1, r12]
 *   @0x18bfb4 ldr r4, [pc, #0x54]
 *   @0x18bfb8 ldr r6, [pc, #0x54]
 *   @0x18bfbc str r0, [r7]
 *   @0x18bfc0 ldr r7, [r1, r4]
 *   @0x18bfc4 ldr r12, [pc, #0x4c]
 *   @0x18bfc8 ldr r5, [pc, #0x4c]
 *   @0x18bfcc str r0, [r7]
 *   @0x18bfd0 ldr r4, [pc, #0x48]
 *   @0x18bfd4 ldr r6, [r1, r6]
 *   @0x18bfd8 strh r0, [r6]
 *   @0x18bfdc ldr r12, [r1, r12]
 *   @0x18bfe0 ldr r0, [r1, r5]
 *   @0x18bfe4 ldr r1, [r1, r4]
 *   @0x18bfe8 strb r2, [r12, r3]
 *   @0x18bfec strb r2, [r0, r3]
 *   @0x18bff0 strb r2, [r1, r3]
 *   @0x18bff4 add r3, r3, #1
 *   @0x18bff8 cmp r3, #256
 *   @0x18bffc bne 0x18bfe8 <_Z16IO_Key_Clear_Allv+0x54>
 *   @0x18c000 pop {r4, r5, r6, r7}
 *   @0x18c004 bx lr
 *   @0x18c008 eoreq r5, r6, r12, lsr #25
 *   @0x18c00c .word 0xffffe988
 *   @0x18c010 .word 0xffffe98c
 *   @0x18c014 .word 0xffffe980
 *   @0x18c018 .word 0xffffe990
 *   @0x18c01c .word 0xffffe998
 *   @0x18c020 .word 0xffffe994
 *
 * ══ §22/289 ParticleSystem_LargestDepth  0x1a570c  size 144  36 条（0x1a570c..0x1a579c）
 * @func 0x1a570c 0x1a579c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_LargestDepth()+0x7c / ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x78×1 / 0x58×1 / 0x4×1 / 0x2×1 / 0x29×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a570c push {r3, r4, r5, lr}
 *   @0x1a5710 vpush {d8}
 *   @0x1a5714 ldr r5, [pc, #0x78]
 *   @0x1a5718 ldr r5, [pc, r5]
 *   @0x1a571c ldr r3, [r5]
 *   @0x1a5720 cmp r3, #0
 *   @0x1a5724 ble 0x1a5788 <_Z27ParticleSystem_LargestDepthv+0x7c>
 *   @0x1a5728 mov r4, #0
 *   @0x1a572c vldr s16, [pc, #92]
 *   @0x1a5730 mov r0, r4
 *   @0x1a5734 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a5738 ldr r3, [pc, #0x58]
 *   @0x1a573c cmp r0, #0
 *   @0x1a5740 beq 0x1a576c <_Z27ParticleSystem_LargestDepthv+0x60>
 *   @0x1a5744 ldr r3, [pc, r3]
 *   @0x1a5748 ldr r3, [r3, #0x4]
 *   @0x1a574c ldr r3, [r3, r4, lsl #2]
 *   @0x1a5750 ldrb r2, [r3, #0x29]
 *   @0x1a5754 cmp r2, #0
 *   @0x1a5758 beq 0x1a576c <_Z27ParticleSystem_LargestDepthv+0x60>
 *   @0x1a575c vldr s15, [r3, #28]
 *   @0x1a5760 vcmp.f32 s15, s16
 *   @0x1a5764 vmrs APSR_nzcv, fpscr
 *   @0x1a5768 vmovgt.f32 s16, s15
 *   @0x1a576c ldr r3, [r5]
 *   @0x1a5770 add r4, r4, #1
 *   @0x1a5774 cmp r3, r4
 *   @0x1a5778 bgt 0x1a5730 <_Z27ParticleSystem_LargestDepthv+0x24>
 *   @0x1a577c vmov r0, s16
 *   @0x1a5780 vpop {d8}
 *   @0x1a5784 pop {r3, r4, r5, pc}
 *   @0x1a5788 vldr s16, [pc]
 *   @0x1a578c b 0x1a577c <_Z27ParticleSystem_LargestDepthv+0x70>
 *   @0x1a5790 vmulgt.f64 d22, d14, d24
 *   @0x1a5794 mlaeq r4, r12, r0, r11
 *   @0x1a5798 eoreq r11, r4, r4, ror r0
 *
 * ══ §23/289 ForceDirectories  0x2150b4  size 144  36 条（0x2150b4..0x215144）
 * @func 0x2150b4 0x215144  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExtractFilePath(char const*)×2 / ExcludeTrailingPathDelimiter(char const*) / 0xb6538 / DirectoryExists(char const*) / 0xb6574 / ForceDirectories(char const*) / 0xb6a00
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2150b4 subs r3, r0, #0
 *   @0x2150b8 push {r4, lr}
 *   @0x2150bc beq 0x2150cc <_Z16ForceDirectoriesPKc+0x18>
 *   @0x2150c0 ldrb r3, [r3]
 *   @0x2150c4 cmp r3, #0
 *   @0x2150c8 bne 0x2150d4 <_Z16ForceDirectoriesPKc+0x20>
 *   @0x2150cc mov r0, #0
 *   @0x2150d0 pop {r4, pc}
 *   @0x2150d4 bl 0x215078 <_Z28ExcludeTrailingPathDelimiterPKc>
 *   @0x2150d8 mov r4, r0
 *   @0x2150dc bl 0xb6538 <strlen@plt>
 *   @0x2150e0 cmp r0, #2
 *   @0x2150e4 bhi 0x2150f0 <_Z16ForceDirectoriesPKc+0x3c>
 *   @0x2150e8 mov r0, #1
 *   @0x2150ec pop {r4, pc}
 *   @0x2150f0 mov r0, r4
 *   @0x2150f4 bl 0x214f24 <_Z15DirectoryExistsPKc>
 *   @0x2150f8 cmp r0, #0
 *   @0x2150fc bne 0x2150e8 <_Z16ForceDirectoriesPKc+0x34>
 *   @0x215100 mov r0, r4
 *   @0x215104 bl 0x214f5c <_Z15ExtractFilePathPKc>
 *   @0x215108 mov r1, r4
 *   @0x21510c bl 0xb6574 <strcmp@plt>
 *   @0x215110 cmp r0, #0
 *   @0x215114 beq 0x2150e8 <_Z16ForceDirectoriesPKc+0x34>
 *   @0x215118 mov r0, r4
 *   @0x21511c bl 0x214f5c <_Z15ExtractFilePathPKc>
 *   @0x215120 bl 0x2150b4 <_Z16ForceDirectoriesPKc>
 *   @0x215124 cmp r0, #0
 *   @0x215128 beq 0x2150cc <_Z16ForceDirectoriesPKc+0x18>
 *   @0x21512c mov r0, r4
 *   @0x215130 movw r1, #0x1fd
 *   @0x215134 bl 0xb6a00 <mkdir@plt>
 *   @0x215138 rsbs r0, r0, #1
 *   @0x21513c movlo r0, #0
 *   @0x215140 pop {r4, pc}
 *
 * ══ §24/289 SND_Init  0x21e940  size 144  36 条（0x21e940..0x21e9d0）
 * @func 0x21e940 0x21e9d0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator new(unsigned int) / SoundHardware::SoundHardware() / SoundHardware::Init() / Audio_Init(SoundHardware*)
 * 字段偏移 top8: 0x4×3 / 0x6c×1 / 0x64×1 / 0x38×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e940 push {r3, r4, r5, lr}
 *   @0x21e944 mov r0, #4
 *   @0x21e948 bl 0x27c524 <_Znwj>
 *   @0x21e94c ldr r4, [pc, #0x6c]
 *   @0x21e950 mov r5, r0
 *   @0x21e954 bl 0x220188 <_ZN13SoundHardwareC2Ev>
 *   @0x21e958 ldr r3, [pc, #0x64]
 *   @0x21e95c mov r0, r5
 *   @0x21e960 add r3, pc, r3
 *   @0x21e964 str r5, [r3]
 *   @0x21e968 bl 0x22021c <_ZN13SoundHardware4InitEv>
 *   @0x21e96c ldr r4, [pc, r4]
 *   @0x21e970 ldr r5, [r4, #0x4]
 *   @0x21e974 subs r0, r5, #0
 *   @0x21e978 beq 0x21e9b4 <_Z8SND_Initv+0x74>
 *   @0x21e97c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21e980 mov r3, #0
 *   @0x21e984 str r3, [r4, #0x4]
 *   @0x21e988 ldr r2, [pc, #0x38]
 *   @0x21e98c mov r5, #0
 *   @0x21e990 ldr r3, [pc, #0x34]
 *   @0x21e994 add r2, pc, r2
 *   @0x21e998 str r5, [r4]
 *   @0x21e99c ldr r3, [pc, r3]
 *   @0x21e9a0 ldr r0, [r2]
 *   @0x21e9a4 str r5, [r3]
 *   @0x21e9a8 bl 0x2166bc <_Z10Audio_InitP13SoundHardware>
 *   @0x21e9ac mov r0, r5
 *   @0x21e9b0 pop {r3, r4, r5, pc}
 *   @0x21e9b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21e9b8 str r5, [r4, #0x4]
 *   @0x21e9bc b 0x21e988 <_Z8SND_Initv+0x48>
 *   @0x21e9c0 andseq r2, sp, r12, lsr #21
 *   @0x21e9c4 subseq r6, r3, r4, asr #19
 *   @0x21e9c8 .word 0x00536990
 *   @0x21e9cc andseq r2, sp, r8, ror r10
 *
 * ══ §25/289 _book_maptype1_quantvals  0x22ed88  size 144  36 条（0x22ed88..0x22ee18）
 * @func 0x22ed88 0x22ee18  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _ilog / __divsi3 / _book_maptype1_quantvals+0x78 / _book_maptype1_quantvals+0x84 / _book_maptype1_quantvals+0x8c
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22ed88 push {r3, r4, r5, lr}
 *   @0x22ed8c mov r5, r0
 *   @0x22ed90 ldr r0, [r0, #0x4]
 *   @0x22ed94 bl 0x22eaf0 <_ilog>
 *   @0x22ed98 ldm r5, {r4, r5}
 *   @0x22ed9c sub r3, r4, #1
 *   @0x22eda0 mov r1, r4
 *   @0x22eda4 sub r0, r0, #1
 *   @0x22eda8 mul r0, r3, r0
 *   @0x22edac bl 0x318d10 <__divsi3>
 *   @0x22edb0 asr r0, r5, r0
 *   @0x22edb4 cmp r4, #0
 *   @0x22edb8 mov r2, #1
 *   @0x22edbc ble 0x22ee00 <_book_maptype1_quantvals+0x78>
 *   @0x22edc0 add r1, r0, r2
 *   @0x22edc4 mov r12, r2
 *   @0x22edc8 mov r3, #0
 *   @0x22edcc add r3, r3, #1
 *   @0x22edd0 cmp r3, r4
 *   @0x22edd4 mul r12, r0, r12
 *   @0x22edd8 mul r2, r1, r2
 *   @0x22eddc bne 0x22edcc <_book_maptype1_quantvals+0x44>
 *   @0x22ede0 cmp r5, r12
 *   @0x22ede4 blt 0x22ee0c <_book_maptype1_quantvals+0x84>
 *   @0x22ede8 cmp r5, r2
 *   @0x22edec blt 0x22ee14 <_book_maptype1_quantvals+0x8c>
 *   @0x22edf0 cmp r4, #0
 *   @0x22edf4 add r0, r0, #1
 *   @0x22edf8 mov r2, #1
 *   @0x22edfc bgt 0x22edc0 <_book_maptype1_quantvals+0x38>
 *   @0x22ee00 mov r12, r2
 *   @0x22ee04 cmp r5, r12
 *   @0x22ee08 bge 0x22ede8 <_book_maptype1_quantvals+0x60>
 *   @0x22ee0c sub r0, r0, #1
 *   @0x22ee10 b 0x22edb4 <_book_maptype1_quantvals+0x2c>
 *   @0x22ee14 pop {r3, r4, r5, pc}
 *
 * ══ §26/289 vorbis_packet_blocksize  0x22fc7c  size 144  36 条（0x22fc7c..0x22fd0c）
 * @func 0x22fc7c 0x22fd0c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×2 / oggpack_readinit / vorbis_packet_blocksize+0x58
 * 字段偏移 top8: 0x2×2 / 0x1c×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22fc7c push {r4, r5, lr}
 *   @0x22fc80 sub sp, sp, #28
 *   @0x22fc84 add r4, sp, #4
 *   @0x22fc88 mov r3, r1
 *   @0x22fc8c ldr r5, [r0, #0x1c]
 *   @0x22fc90 ldr r1, [r1]
 *   @0x22fc94 mov r0, r4
 *   @0x22fc98 ldr r2, [r3, #0x4]
 *   @0x22fc9c bl 0x23385c <oggpack_readinit>
 *   @0x22fca0 mov r0, r4
 *   @0x22fca4 mov r1, #1
 *   @0x22fca8 bl 0x233b28 <oggpack_read>
 *   @0x22fcac cmp r0, #0
 *   @0x22fcb0 bne 0x22fcfc <vorbis_packet_blocksize+0x80>
 *   @0x22fcb4 ldr r3, [r5, #0x8]
 *   @0x22fcb8 mov r1, r0
 *   @0x22fcbc cmp r3, #1
 *   @0x22fcc0 ble 0x22fcd4 <vorbis_packet_blocksize+0x58>
 *   @0x22fcc4 asr r3, r3, #1
 *   @0x22fcc8 add r1, r1, #1
 *   @0x22fccc cmp r3, #1
 *   @0x22fcd0 bgt 0x22fcc4 <vorbis_packet_blocksize+0x48>
 *   @0x22fcd4 mov r0, r4
 *   @0x22fcd8 bl 0x233b28 <oggpack_read>
 *   @0x22fcdc cmn r0, #1
 *   @0x22fce0 beq 0x22fd04 <vorbis_packet_blocksize+0x88>
 *   @0x22fce4 add r0, r0, #8
 *   @0x22fce8 ldr r3, [r5, r0, lsl #2]
 *   @0x22fcec ldr r3, [r3]
 *   @0x22fcf0 ldr r0, [r5, r3, lsl #2]
 *   @0x22fcf4 add sp, sp, #28
 *   @0x22fcf8 pop {r4, r5, pc}
 *   @0x22fcfc mvn r0, #134
 *   @0x22fd00 b 0x22fcf4 <vorbis_packet_blocksize+0x78>
 *   @0x22fd04 mvn r0, #135
 *   @0x22fd08 b 0x22fcf4 <vorbis_packet_blocksize+0x78>
 *
 * ══ §27/289 json_object_get_int  0x27eb28  size 144  36 条（0x27eb28..0x27ebb8）
 * @func 0x27eb28 0x27ebb8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68f8
 * 字段偏移 top8: 0x4×4 / 0x18×2 / 0x-4×1 / 0x30×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27eb28 cmp r0, #0
 *   @0x27eb2c str lr, [sp, #-0x4]!
 *   @0x27eb30 sub sp, sp, #12
 *   @0x27eb34 beq 0x27eb70 <json_object_get_int+0x48>
 *   @0x27eb38 ldr r3, [r0]
 *   @0x27eb3c sub r3, r3, #1
 *   @0x27eb40 cmp r3, #5
 *   @0x27eb44 addls pc, pc, r3, lsl #2
 *   @0x27eb48 b 0x27eb70 <json_object_get_int+0x48>
 *   @0x27eb4c b 0x27eb64 <json_object_get_int+0x3c>
 *   @0x27eb50 b 0x27eba0 <json_object_get_int+0x78>
 *   @0x27eb54 b 0x27eb64 <json_object_get_int+0x3c>
 *   @0x27eb58 b 0x27eb70 <json_object_get_int+0x48>
 *   @0x27eb5c b 0x27eb70 <json_object_get_int+0x48>
 *   @0x27eb60 b 0x27eb7c <json_object_get_int+0x54>
 *   @0x27eb64 ldr r0, [r0, #0x18]
 *   @0x27eb68 add sp, sp, #12
 *   @0x27eb6c ldr pc, [sp], #4
 *   @0x27eb70 mov r0, #0
 *   @0x27eb74 add sp, sp, #12
 *   @0x27eb78 ldr pc, [sp], #4
 *   @0x27eb7c ldr r1, [pc, #0x30]
 *   @0x27eb80 add r2, sp, #4
 *   @0x27eb84 ldr r0, [r0, #0x18]
 *   @0x27eb88 add r1, pc, r1
 *   @0x27eb8c bl 0xb68f8 <sscanf@plt>
 *   @0x27eb90 cmp r0, #1
 *   @0x27eb94 bne 0x27eb70 <json_object_get_int+0x48>
 *   @0x27eb98 ldr r0, [sp, #0x4]
 *   @0x27eb9c b 0x27eb68 <json_object_get_int+0x40>
 *   @0x27eba0 vldr d7, [r0, #24]
 *   @0x27eba4 vcvt.s32.f64 s13, d7
 *   @0x27eba8 vmov r0, s13
 *   @0x27ebac add sp, sp, #12
 *   @0x27ebb0 ldr pc, [sp], #4
 *   @0x27ebb4 andeq r3, r11, r4, lsl #19
 *
 * ══ §28/289 lh_table_lookup_entry  0x280b1c  size 144  36 条（0x280b1c..0x280bac）
 * @func 0x280b1c 0x280bac  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_uidivmod
 * 字段偏移 top8: 0x28×3 / 0x10×2 / 0x30×1 / 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280b1c push {r3, r4, r5, r6, r7, lr}
 *   @0x280b20 mov r5, r0
 *   @0x280b24 ldr r3, [r0, #0x30]
 *   @0x280b28 mov r0, r1
 *   @0x280b2c mov r6, r1
 *   @0x280b30 blx r3
 *   @0x280b34 ldr r1, [r5]
 *   @0x280b38 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x280b3c ldr r3, [r5, #0x10]
 *   @0x280b40 ldr r2, [r5, #0x28]
 *   @0x280b44 add r3, r3, #1
 *   @0x280b48 str r3, [r5, #0x10]
 *   @0x280b4c mov r4, r1
 *   @0x280b50 b 0x280b80 <lh_table_lookup_entry+0x64>
 *   @0x280b54 cmn r3, #2
 *   @0x280b58 beq 0x280b70 <lh_table_lookup_entry+0x54>
 *   @0x280b5c ldr r3, [r5, #0x34]
 *   @0x280b60 blx r3
 *   @0x280b64 cmp r0, #0
 *   @0x280b68 bne 0x280ba0 <lh_table_lookup_entry+0x84>
 *   @0x280b6c ldr r2, [r5, #0x28]
 *   @0x280b70 ldr r3, [r5]
 *   @0x280b74 add r4, r4, #1
 *   @0x280b78 cmp r4, r3
 *   @0x280b7c moveq r4, #0
 *   @0x280b80 ldr r3, [r2, r4, lsl #4]
 *   @0x280b84 mov r1, r6
 *   @0x280b88 lsl r7, r4, #4
 *   @0x280b8c cmn r3, #1
 *   @0x280b90 mov r0, r3
 *   @0x280b94 bne 0x280b54 <lh_table_lookup_entry+0x38>
 *   @0x280b98 mov r0, #0
 *   @0x280b9c pop {r3, r4, r5, r6, r7, pc}
 *   @0x280ba0 ldr r0, [r5, #0x28]
 *   @0x280ba4 add r0, r0, r7
 *   @0x280ba8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §29/289 RelyAckBuildPacket  0x29996c  size 144  36 条（0x29996c..0x2999fc）
 * @func 0x29996c 0x2999fc  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(void const*, unsigned int, unsigned int)×3 / RelyAckNumPackets(SRelyAck*) / RelyAckBuildPacket(SRelyAck*)+0x88 / CreateBuffer(int, eBuffer_Format, int) / GetIBuffer(int)
 * 字段偏移 top8: 0x409×2 / 0x408×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29996c push {r4, r5, r6, lr}
 *   @0x299970 mov r4, r0
 *   @0x299974 bl 0x299944 <_Z17RelyAckNumPacketsP8SRelyAck>
 *   @0x299978 cmp r0, #0
 *   @0x29997c ble 0x2999f4 <_Z18RelyAckBuildPacketP8SRelyAck+0x88>
 *   @0x299980 mov r1, #3
 *   @0x299984 mov r2, #1
 *   @0x299988 lsl r0, r0, #2
 *   @0x29998c bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati>
 *   @0x299990 mov r5, r0
 *   @0x299994 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x299998 ldrb r3, [r4, #0x408]
 *   @0x29999c ldrb r2, [r4, #0x409]
 *   @0x2999a0 cmp r2, r3
 *   @0x2999a4 add r1, r4, r3, lsl #2
 *   @0x2999a8 mov r6, r0
 *   @0x2999ac bhs 0x2999dc <_Z18RelyAckBuildPacketP8SRelyAck+0x70>
 *   @0x2999b0 rsb r3, r3, #255
 *   @0x2999b4 add r1, r1, #12
 *   @0x2999b8 mov r2, #4
 *   @0x2999bc bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x2999c0 mov r0, r6
 *   @0x2999c4 add r1, r4, #12
 *   @0x2999c8 ldrb r3, [r4, #0x409]
 *   @0x2999cc mov r2, #4
 *   @0x2999d0 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x2999d4 mov r0, r5
 *   @0x2999d8 pop {r4, r5, r6, pc}
 *   @0x2999dc rsb r3, r3, r2
 *   @0x2999e0 add r1, r1, #12
 *   @0x2999e4 mov r2, #4
 *   @0x2999e8 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x2999ec mov r0, r5
 *   @0x2999f0 pop {r4, r5, r6, pc}
 *   @0x2999f4 mvn r0, #0
 *   @0x2999f8 pop {r4, r5, r6, pc}
 *
 * ══ §30/289 CSkeletonInstance::~CSkeletonInstance  0xbe194  size 140  35 条（0xbe194..0xbe220）
 * @func 0xbe194 0xbe220  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / spAnimationState_dispose / spAnimationStateData_dispose / spSkeletonBounds_dispose / spSkeleton_dispose / CSkeletonInstance::~CSkeletonInstance()+0x74 / spAtlas_dispose / spAttachment_dispose
 * 字段偏移 top8: 0x1c×2 / 0x10×2 / 0x18×2 / 0x2×2 / 0x14×2 / 0x28×1 / 0x2c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe194 push {r3, r4, r5, lr}
 *   @0xbe198 mov r5, r0
 *   @0xbe19c ldr r0, [r0, #0x28]
 *   @0xbe1a0 cmp r0, #0
 *   @0xbe1a4 beq 0xbe1b4 <_ZN17CSkeletonInstanceD2Ev+0x20>
 *   @0xbe1a8 bl 0x2831cc <spAnimationState_dispose>
 *   @0xbe1ac ldr r0, [r5, #0x2c]
 *   @0xbe1b0 bl 0x283b58 <spAnimationStateData_dispose>
 *   @0xbe1b4 ldr r3, [r5, #0x1c]
 *   @0xbe1b8 cmp r3, #0
 *   @0xbe1bc beq 0xbe1d0 <_ZN17CSkeletonInstanceD2Ev+0x3c>
 *   @0xbe1c0 ldr r0, [r5, #0x20]
 *   @0xbe1c4 bl 0x28a858 <spSkeletonBounds_dispose>
 *   @0xbe1c8 ldr r0, [r5, #0x1c]
 *   @0xbe1cc bl 0x2894cc <spSkeleton_dispose>
 *   @0xbe1d0 ldr r3, [r5, #0x10]
 *   @0xbe1d4 cmp r3, #0
 *   @0xbe1d8 ble 0xbe208 <_ZN17CSkeletonInstanceD2Ev+0x74>
 *   @0xbe1dc mov r4, #0
 *   @0xbe1e0 ldr r3, [r5, #0x18]
 *   @0xbe1e4 ldr r0, [r3, r4, lsl #2]
 *   @0xbe1e8 bl 0x284120 <spAtlas_dispose>
 *   @0xbe1ec ldr r3, [r5, #0x14]
 *   @0xbe1f0 ldr r0, [r3, r4, lsl #2]
 *   @0xbe1f4 add r4, r4, #1
 *   @0xbe1f8 bl 0x284cb4 <spAttachment_dispose>
 *   @0xbe1fc ldr r3, [r5, #0x10]
 *   @0xbe200 cmp r3, r4
 *   @0xbe204 bgt 0xbe1e0 <_ZN17CSkeletonInstanceD2Ev+0x4c>
 *   @0xbe208 ldr r0, [r5, #0x14]
 *   @0xbe20c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xbe210 ldr r0, [r5, #0x18]
 *   @0xbe214 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xbe218 mov r0, r5
 *   @0xbe21c pop {r3, r4, r5, pc}
 *
 * ══ §31/289 CSkeletonInstance::CloneAttachment  0xbfc8c  size 140  35 条（0xbfc8c..0xbfd18）
 * @func 0xbfc8c 0xbfd18  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::CreateAttachment(char const*, char const*, short, int, int, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x4×4 / 0x14×3 / 0x18×3 / 0x1c×3 / 0x20×3 / 0xc×2 / 0x24×2 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbfc8c ldr r3, [r1, #0x4]
 *   @0xbfc90 push {r4, r5, r6, r7, r8, lr}
 *   @0xbfc94 cmp r3, #0
 *   @0xbfc98 sub sp, sp, #48
 *   @0xbfc9c bne 0xbfd10 <_ZN17CSkeletonInstance15CloneAttachmentEP12spAttachmentP7spAtlas+0x84>
 *   @0xbfca0 ldr r12, [r2, #0x4]
 *   @0xbfca4 ldr r8, [r1, #0x14]
 *   @0xbfca8 ldr r7, [r1, #0x18]
 *   @0xbfcac ldr r3, [r12, #0x48]
 *   @0xbfcb0 ldr lr, [r12, #0xc]
 *   @0xbfcb4 ldr r6, [r1, #0x1c]
 *   @0xbfcb8 ldr r5, [r1, #0x20]
 *   @0xbfcbc ldr r4, [r1, #0x24]
 *   @0xbfcc0 ldr r2, [r3, #0x4]
 *   @0xbfcc4 ldr r1, [r12]
 *   @0xbfcc8 ldrsh r3, [r3, #28]
 *   @0xbfccc str lr, [sp]
 *   @0xbfcd0 ldr lr, [r12, #0x10]
 *   @0xbfcd4 str lr, [sp, #0x4]
 *   @0xbfcd8 ldr lr, [r12, #0x14]
 *   @0xbfcdc str lr, [sp, #0x8]
 *   @0xbfce0 ldr lr, [r12, #0x18]
 *   @0xbfce4 str lr, [sp, #0xc]
 *   @0xbfce8 ldr lr, [r12, #0x1c]
 *   @0xbfcec str lr, [sp, #0x10]
 *   @0xbfcf0 ldr r12, [r12, #0x20]
 *   @0xbfcf4 str r8, [sp, #0x18]
 *   @0xbfcf8 str r7, [sp, #0x1c]
 *   @0xbfcfc str r12, [sp, #0x14]
 *   @0xbfd00 str r6, [sp, #0x20]
 *   @0xbfd04 str r5, [sp, #0x24]
 *   @0xbfd08 str r4, [sp, #0x28]
 *   @0xbfd0c bl 0xbf9a0 <_ZN17CSkeletonInstance16CreateAttachmentEPKcS1_siifffffffff>
 *   @0xbfd10 add sp, sp, #48
 *   @0xbfd14 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §32/289 EnsureDirectoryIsCreated  0x13ad20  size 140  35 条（0x13ad20..0x13adac）
 * @func 0x13ad20 0x13adac  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6868×2 / 0xb65a4 / ForceDirectories(char const*) / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ad20 push {r4, r5, lr}
 *   @0x13ad24 sub sp, sp, #2048
 *   @0x13ad28 ldr r4, [pc, #0x78]
 *   @0x13ad2c sub sp, sp, #12
 *   @0x13ad30 add r5, sp, #4
 *   @0x13ad34 mov r1, r0
 *   @0x13ad38 ldr r4, [pc, r4]
 *   @0x13ad3c mov r0, r5
 *   @0x13ad40 ldr r3, [r4]
 *   @0x13ad44 str r3, [sp, #0x804]
 *   @0x13ad48 bl 0xb65a4 <strcpy@plt>
 *   @0x13ad4c mov r0, r5
 *   @0x13ad50 mov r1, #92
 *   @0x13ad54 bl 0xb6868 <strrchr@plt>
 *   @0x13ad58 subs r3, r0, #0
 *   @0x13ad5c beq 0x13ad8c <_Z24EnsureDirectoryIsCreatedPKc+0x6c>
 *   @0x13ad60 mov r2, #0
 *   @0x13ad64 mov r0, r5
 *   @0x13ad68 strb r2, [r3]
 *   @0x13ad6c bl 0x2150b4 <_Z16ForceDirectoriesPKc>
 *   @0x13ad70 ldr r2, [sp, #0x804]
 *   @0x13ad74 ldr r3, [r4]
 *   @0x13ad78 cmp r2, r3
 *   @0x13ad7c bne 0x13ada4 <_Z24EnsureDirectoryIsCreatedPKc+0x84>
 *   @0x13ad80 add sp, sp, #2048
 *   @0x13ad84 add sp, sp, #12
 *   @0x13ad88 pop {r4, r5, pc}
 *   @0x13ad8c mov r0, r5
 *   @0x13ad90 mov r1, #47
 *   @0x13ad94 bl 0xb6868 <strrchr@plt>
 *   @0x13ad98 subs r3, r0, #0
 *   @0x13ad9c beq 0x13ad70 <_Z24EnsureDirectoryIsCreatedPKc+0x50>
 *   @0x13ada0 b 0x13ad60 <_Z24EnsureDirectoryIsCreatedPKc+0x40>
 *   @0x13ada4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13ada8 eoreq r2, r11, r8, lsl r12
 *
 * ══ §33/289 Script_Find  0x1e0610  size 140  35 条（0x1e0610..0x1e069c）
 * @func 0x1e0610 0x1e069c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 0x-4×2 / 0x70×1 / 0x60×1 / 0x5c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0610 push {r3, r4, r5, r6, r7, lr}
 *   @0x1e0614 mov r7, r0
 *   @0x1e0618 ldr r3, [pc, #0x70]
 *   @0x1e061c ldr r3, [pc, r3]
 *   @0x1e0620 ldr r5, [r3]
 *   @0x1e0624 subs r4, r5, #1
 *   @0x1e0628 bmi 0x1e0680 <_Z11Script_FindPKc+0x70>
 *   @0x1e062c ldr r2, [pc, #0x60]
 *   @0x1e0630 lsl r5, r5, #2
 *   @0x1e0634 ldr r3, [pc, #0x5c]
 *   @0x1e0638 ldr r2, [pc, r2]
 *   @0x1e063c ldr r3, [pc, r3]
 *   @0x1e0640 ldr r6, [r2, #0x4]
 *   @0x1e0644 ldr r3, [r3]
 *   @0x1e0648 add r6, r6, r5
 *   @0x1e064c add r5, r3, r5
 *   @0x1e0650 ldr r3, [r6, #-0x4]!
 *   @0x1e0654 mov r1, r7
 *   @0x1e0658 cmp r3, #0
 *   @0x1e065c beq 0x1e0670 <_Z11Script_FindPKc+0x60>
 *   @0x1e0660 ldr r0, [r5, #-0x4]
 *   @0x1e0664 bl 0xb6574 <strcmp@plt>
 *   @0x1e0668 cmp r0, #0
 *   @0x1e066c beq 0x1e0688 <_Z11Script_FindPKc+0x78>
 *   @0x1e0670 sub r4, r4, #1
 *   @0x1e0674 sub r5, r5, #4
 *   @0x1e0678 cmn r4, #1
 *   @0x1e067c bne 0x1e0650 <_Z11Script_FindPKc+0x40>
 *   @0x1e0680 mvn r0, #0
 *   @0x1e0684 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1e0688 mov r0, r4
 *   @0x1e068c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1e0690 eoreq r0, r1, r0, lsl r7
 *   @0x1e0694 .word 0x002106f0
 *   @0x1e0698 .word 0x002106f4
 *
 * ══ §34/289 Variable_Global_SetVar  0x1f38f8  size 140  35 条（0x1f38f8..0x1f3984）
 * @func 0x1f38f8 0x1f3984  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: PushContextStack(YYObjectBase*) / SET_RValue(RValue*, RValue*, int) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x78×1 / 0x24×1 / 0x4×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f38f8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1f38fc mov r7, r0
 *   @0x1f3900 ldr r4, [pc, #0x78]
 *   @0x1f3904 mov r5, r1
 *   @0x1f3908 mov r6, r2
 *   @0x1f390c ldr r4, [pc, r4]
 *   @0x1f3910 ldr r0, [r4]
 *   @0x1f3914 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x1f3918 ldr r0, [r4]
 *   @0x1f391c ldr r12, [r0, #0x24]
 *   @0x1f3920 cmp r12, #0
 *   @0x1f3924 beq 0x1f396c <_Z22Variable_Global_SetVariiP6RValue+0x74>
 *   @0x1f3928 ldr r12, [r0, #0x4]
 *   @0x1f392c sub r7, r7, #99328
 *   @0x1f3930 sub r1, r7, #672
 *   @0x1f3934 cmp r12, #0
 *   @0x1f3938 beq 0x1f3974 <_Z22Variable_Global_SetVariiP6RValue+0x7c>
 *   @0x1f393c add r4, r12, r1, lsl #4
 *   @0x1f3940 ldr r7, [r4, #0xc]
 *   @0x1f3944 mov r2, r5
 *   @0x1f3948 mov r1, r6
 *   @0x1f394c ldr r5, [r4, #0x8]
 *   @0x1f3950 mov r0, r4
 *   @0x1f3954 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f3958 mvn r3, #-16777216
 *   @0x1f395c cmp r7, r3
 *   @0x1f3960 strne r5, [r4, #0x8]
 *   @0x1f3964 moveq r3, #7
 *   @0x1f3968 streq r3, [r4, #0x8]
 *   @0x1f396c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1f3970 b 0xd3a34 <_Z15PopContextStackv>
 *   @0x1f3974 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f3978 mov r4, r0
 *   @0x1f397c b 0x1f3940 <_Z22Variable_Global_SetVariiP6RValue+0x48>
 *   @0x1f3980 andseq r10, pc, r8, lsr #5
 *
 * ══ §35/289 _alutSanityCheck  0x2219a8  size 140  35 条（0x2219a8..0x221a34）
 * @func 0x2219a8 0x221a34  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSetError×4 / 0xb6a3c / 0xb6a54 / 0xb6b98 / 0xb6ba4
 * 字段偏移 top8: 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2219a8 push {r3, r4, r5, lr}
 *   @0x2219ac ldr r3, [pc, #0x7c]
 *   @0x2219b0 ldr r4, [pc, r3]
 *   @0x2219b4 cmp r4, #0
 *   @0x2219b8 beq 0x221a00 <_alutSanityCheck+0x58>
 *   @0x2219bc bl 0xb6a3c <alcGetCurrentContext@plt>
 *   @0x2219c0 subs r5, r0, #0
 *   @0x2219c4 beq 0x221a20 <_alutSanityCheck+0x78>
 *   @0x2219c8 bl 0xb6a54 <alGetError@plt>
 *   @0x2219cc subs r4, r0, #0
 *   @0x2219d0 bne 0x2219f0 <_alutSanityCheck+0x48>
 *   @0x2219d4 mov r0, r5
 *   @0x2219d8 bl 0xb6b98 <alcGetContextsDevice@plt>
 *   @0x2219dc bl 0xb6ba4 <alcGetError@plt>
 *   @0x2219e0 cmp r0, #0
 *   @0x2219e4 bne 0x221a10 <_alutSanityCheck+0x68>
 *   @0x2219e8 mov r0, #1
 *   @0x2219ec pop {r3, r4, r5, pc}
 *   @0x2219f0 movw r0, #0x205
 *   @0x2219f4 bl 0x221940 <_alutSetError>
 *   @0x2219f8 mov r0, #0
 *   @0x2219fc pop {r3, r4, r5, pc}
 *   @0x221a00 movw r0, #0x203
 *   @0x221a04 bl 0x221940 <_alutSetError>
 *   @0x221a08 mov r0, r4
 *   @0x221a0c pop {r3, r4, r5, pc}
 *   @0x221a10 movw r0, #0x206
 *   @0x221a14 bl 0x221940 <_alutSetError>
 *   @0x221a18 mov r0, r4
 *   @0x221a1c pop {r3, r4, r5, pc}
 *   @0x221a20 mov r0, #516
 *   @0x221a24 bl 0x221940 <_alutSetError>
 *   @0x221a28 mov r0, r5
 *   @0x221a2c pop {r3, r4, r5, pc}
 *   @0x221a30 ldrheq r3, [r3], #-168
 *
 * ══ §36/289 spSkeleton_updateWorldTransform  0x289ee4  size 140  35 条（0x289ee4..0x289f70）
 * @func 0x289ee4 0x289f70  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spTransformConstraint_apply / spPathConstraint_apply / spBone_updateWorldTransform / spIkConstraint_apply
 * 字段偏移 top8: 0x60×5 / 0x4×4 / 0x68×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x289ee4 ldr r2, [r0, #0x60]
 *   @0x289ee8 push {r3, r4, r5, lr}
 *   @0x289eec cmp r2, #0
 *   @0x289ef0 mov r5, r0
 *   @0x289ef4 pople {r3, r4, r5, pc}
 *   @0x289ef8 mov r4, #0
 *   @0x289efc ldr r3, [r5, #0x68]
 *   @0x289f00 add r1, r3, r4, lsl #3
 *   @0x289f04 ldr r3, [r3, r4, lsl #3]
 *   @0x289f08 cmp r3, #3
 *   @0x289f0c addls pc, pc, r3, lsl #2
 *   @0x289f10 b 0x289f30 <spSkeleton_updateWorldTransform+0x4c>
 *   @0x289f14 b 0x289f50 <spSkeleton_updateWorldTransform+0x6c>
 *   @0x289f18 b 0x289f60 <spSkeleton_updateWorldTransform+0x7c>
 *   @0x289f1c b 0x289f40 <spSkeleton_updateWorldTransform+0x5c>
 *   @0x289f20 b 0x289f24 <spSkeleton_updateWorldTransform+0x40>
 *   @0x289f24 ldr r0, [r1, #0x4]
 *   @0x289f28 bl 0x28f110 <spTransformConstraint_apply>
 *   @0x289f2c ldr r2, [r5, #0x60]
 *   @0x289f30 add r4, r4, #1
 *   @0x289f34 cmp r2, r4
 *   @0x289f38 bgt 0x289efc <spSkeleton_updateWorldTransform+0x18>
 *   @0x289f3c pop {r3, r4, r5, pc}
 *   @0x289f40 ldr r0, [r1, #0x4]
 *   @0x289f44 bl 0x288788 <spPathConstraint_apply>
 *   @0x289f48 ldr r2, [r5, #0x60]
 *   @0x289f4c b 0x289f30 <spSkeleton_updateWorldTransform+0x4c>
 *   @0x289f50 ldr r0, [r1, #0x4]
 *   @0x289f54 bl 0x285348 <spBone_updateWorldTransform>
 *   @0x289f58 ldr r2, [r5, #0x60]
 *   @0x289f5c b 0x289f30 <spSkeleton_updateWorldTransform+0x4c>
 *   @0x289f60 ldr r0, [r1, #0x4]
 *   @0x289f64 bl 0x28667c <spIkConstraint_apply>
 *   @0x289f68 ldr r2, [r5, #0x60]
 *   @0x289f6c b 0x289f30 <spSkeleton_updateWorldTransform+0x4c>
 *
 * ══ §37/289 spSkeleton_setSkin  0x28a250  size 140  35 条（0x28a250..0x28a2dc）
 * @func 0x28a250 0x28a2dc  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkin_attachAll / spSkeleton_setSkin+0x28 / spSkin_getAttachment / spSlot_setAttachment
 * 字段偏移 top8: 0x38×3 / 0x10×2 / 0x14×1 / 0x2×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a250 push {r3, r4, r5, r6, r7, lr}
 *   @0x28a254 subs r7, r1, #0
 *   @0x28a258 mov r5, r0
 *   @0x28a25c beq 0x28a278 <spSkeleton_setSkin+0x28>
 *   @0x28a260 ldr r2, [r0, #0x38]
 *   @0x28a264 cmp r2, #0
 *   @0x28a268 beq 0x28a280 <spSkeleton_setSkin+0x30>
 *   @0x28a26c mov r0, r7
 *   @0x28a270 mov r1, r5
 *   @0x28a274 bl 0x28ed9c <spSkin_attachAll>
 *   @0x28a278 str r7, [r5, #0x38]
 *   @0x28a27c pop {r3, r4, r5, r6, r7, pc}
 *   @0x28a280 ldr r12, [r0, #0x10]
 *   @0x28a284 cmp r12, #0
 *   @0x28a288 movgt r4, r2
 *   @0x28a28c ble 0x28a278 <spSkeleton_setSkin+0x28>
 *   @0x28a290 ldr r3, [r5, #0x14]
 *   @0x28a294 mov r1, r4
 *   @0x28a298 mov r0, r7
 *   @0x28a29c ldr r6, [r3, r4, lsl #2]
 *   @0x28a2a0 ldr r3, [r6]
 *   @0x28a2a4 ldr r2, [r3, #0xc]
 *   @0x28a2a8 cmp r2, #0
 *   @0x28a2ac beq 0x28a2c8 <spSkeleton_setSkin+0x78>
 *   @0x28a2b0 bl 0x28ed00 <spSkin_getAttachment>
 *   @0x28a2b4 subs r1, r0, #0
 *   @0x28a2b8 mov r0, r6
 *   @0x28a2bc beq 0x28a2c4 <spSkeleton_setSkin+0x74>
 *   @0x28a2c0 bl 0x28ee1c <spSlot_setAttachment>
 *   @0x28a2c4 ldr r12, [r5, #0x10]
 *   @0x28a2c8 add r4, r4, #1
 *   @0x28a2cc cmp r12, r4
 *   @0x28a2d0 bgt 0x28a290 <spSkeleton_setSkin+0x40>
 *   @0x28a2d4 str r7, [r5, #0x38]
 *   @0x28a2d8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §38/289 b2Fixture::CreateProxies  0x2c86e4  size 140  35 条（0x2c86e4..0x2c8770）
 * @func 0x2c86e4 0x2c8770  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BroadPhase::CreateProxy(b2AABB const&, void*)
 * 字段偏移 top8: 0xc×3 / 0x1c×3 / 0x18×2 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c86e4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c86e8 mov r6, r0
 *   @0x2c86ec ldr r0, [r0, #0xc]
 *   @0x2c86f0 mov r8, r1
 *   @0x2c86f4 mov r9, r2
 *   @0x2c86f8 ldr r3, [r0]
 *   @0x2c86fc ldr r3, [r3, #0xc]
 *   @0x2c8700 blx r3
 *   @0x2c8704 cmp r0, #0
 *   @0x2c8708 str r0, [r6, #0x1c]
 *   @0x2c870c pople {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c8710 mov r7, #0
 *   @0x2c8714 mov r5, r7
 *   @0x2c8718 ldr r0, [r6, #0xc]
 *   @0x2c871c mov r3, r5
 *   @0x2c8720 ldr r4, [r6, #0x18]
 *   @0x2c8724 mov r2, r9
 *   @0x2c8728 ldr r12, [r0]
 *   @0x2c872c add r4, r4, r7
 *   @0x2c8730 add r7, r7, #28
 *   @0x2c8734 mov r1, r4
 *   @0x2c8738 ldr r12, [r12, #0x1c]
 *   @0x2c873c blx r12
 *   @0x2c8740 mov r0, r8
 *   @0x2c8744 mov r1, r4
 *   @0x2c8748 mov r2, r4
 *   @0x2c874c bl 0x2dc888 <_ZN12b2BroadPhase11CreateProxyERK6b2AABBPv>
 *   @0x2c8750 ldr r3, [r6, #0x1c]
 *   @0x2c8754 str r5, [r4, #0x14]
 *   @0x2c8758 add r5, r5, #1
 *   @0x2c875c cmp r3, r5
 *   @0x2c8760 str r6, [r4, #0x10]
 *   @0x2c8764 str r0, [r4, #0x18]
 *   @0x2c8768 bgt 0x2c8718 <_ZN9b2Fixture13CreateProxiesEP12b2BroadPhaseRK11b2Transform+0x34>
 *   @0x2c876c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §39/289 __floatundisf  0x319388  size 140  35 条（0x319388..0x319414）
 * @func 0x319388 0x319414  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatdisf+0x60
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319388 orrs r2, r0, r1
 *   @0x31938c bxeq lr
 *   @0x319390 mov r3, #0
 *   @0x319394 b 0x3193b0 <__floatdisf+0x18>
 *   @0x319398 orrs r2, r0, r1
 *   @0x31939c bxeq lr
 *   @0x3193a0 ands r3, r1, #-2147483648
 *   @0x3193a4 bpl 0x3193b0 <__floatdisf+0x18>
 *   @0x3193a8 rsbs r0, r0, #0
 *   @0x3193ac rsc r1, r1, #0
 *   @0x3193b0 movs r12, r1
 *   @0x3193b4 moveq r12, r0
 *   @0x3193b8 moveq r1, r0
 *   @0x3193bc moveq r0, #0
 *   @0x3193c0 orr r3, r3, #1526726656
 *   @0x3193c4 subeq r3, r3, #268435456
 *   @0x3193c8 sub r3, r3, #8388608
 *   @0x3193cc clz r2, r12
 *   @0x3193d0 subs r2, r2, #8
 *   @0x3193d4 sub r3, r3, r2, lsl #23
 *   @0x3193d8 blt 0x3193f8 <__floatdisf+0x60>
 *   @0x3193dc add r3, r3, r1, lsl r2
 *   @0x3193e0 lsl r12, r0, r2
 *   @0x3193e4 rsb r2, r2, #32
 *   @0x3193e8 cmp r12, #-2147483648
 *   @0x3193ec adc r0, r3, r0, lsr r2
 *   @0x3193f0 biceq r0, r0, #1
 *   @0x3193f4 bx lr
 *   @0x3193f8 add r2, r2, #32
 *   @0x3193fc lsl r12, r1, r2
 *   @0x319400 rsb r2, r2, #32
 *   @0x319404 orrs r0, r0, r12, lsl #1
 *   @0x319408 adc r0, r3, r1, lsr r2
 *   @0x31940c biceq r0, r0, r12, lsr #31
 *   @0x319410 bx lr
 *
 * ══ §40/289 cARRAY_OF_POINTERS::setLength  0xd1b3c  size 136  34 条（0xd1b3c..0xd1bc4）
 * @func 0xd1b3c 0xd1bc4  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×2 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1b3c ldr r3, [r0]
 *   @0xd1b40 push {r4, r5, lr}
 *   @0xd1b44 cmp r3, r1
 *   @0xd1b48 sub sp, sp, #12
 *   @0xd1b4c mov r5, r0
 *   @0xd1b50 mov r4, r1
 *   @0xd1b54 beq 0xd1b8c <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x50>
 *   @0xd1b58 cmp r1, #0
 *   @0xd1b5c ldr r0, [r0, #0xc]
 *   @0xd1b60 beq 0xd1b94 <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x58>
 *   @0xd1b64 lsls r1, r1, #2
 *   @0xd1b68 beq 0xd1bac <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x70>
 *   @0xd1b6c ldr r2, [pc, #0x4c]
 *   @0xd1b70 mov r3, #0
 *   @0xd1b74 str r3, [sp]
 *   @0xd1b78 movw r3, #0x11b
 *   @0xd1b7c add r2, pc, r2
 *   @0xd1b80 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd1b84 str r0, [r5, #0xc]
 *   @0xd1b88 str r4, [r5]
 *   @0xd1b8c add sp, sp, #12
 *   @0xd1b90 pop {r4, r5, pc}
 *   @0xd1b94 cmp r0, #0
 *   @0xd1b98 beq 0xd1bac <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x70>
 *   @0xd1b9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1ba0 str r4, [r5, #0xc]
 *   @0xd1ba4 str r4, [r5, #0x4]
 *   @0xd1ba8 b 0xd1b88 <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x4c>
 *   @0xd1bac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1bb0 mov r3, #0
 *   @0xd1bb4 str r3, [r5, #0xc]
 *   @0xd1bb8 str r3, [r5, #0x4]
 *   @0xd1bbc b 0xd1b88 <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x4c>
 *   @0xd1bc0 eoreq r0, r6, r4, ror #22
 *
 * ══ §41/289 CheckConstName  0xedc04  size 136  34 条（0xedc04..0xedc8c）
 * @func 0xedc04 0xedc8c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckConstName(char const*)+0x34×2 / 0xb6538
 * 字段偏移 top8: 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xedc04 push {r4, lr}
 *   @0xedc08 mov r4, r0
 *   @0xedc0c ldrb r3, [r0]
 *   @0xedc10 cmp r3, #0
 *   @0xedc14 beq 0xedc6c <_Z14CheckConstNamePKc+0x68>
 *   @0xedc18 bic r2, r3, #32
 *   @0xedc1c sub r2, r2, #65
 *   @0xedc20 cmp r2, #25
 *   @0xedc24 bhi 0xedc74 <_Z14CheckConstNamePKc+0x70>
 *   @0xedc28 mov r0, r4
 *   @0xedc2c bl 0xb6538 <strlen@plt>
 *   @0xedc30 mov r1, r4
 *   @0xedc34 mov r2, #1
 *   @0xedc38 cmp r2, r0
 *   @0xedc3c add r2, r2, #1
 *   @0xedc40 bge 0xedc84 <_Z14CheckConstNamePKc+0x80>
 *   @0xedc44 ldrb r3, [r1, #0x1]!
 *   @0xedc48 bic r12, r3, #32
 *   @0xedc4c sub r4, r3, #48
 *   @0xedc50 sub r12, r12, #65
 *   @0xedc54 cmp r12, #25
 *   @0xedc58 bls 0xedc38 <_Z14CheckConstNamePKc+0x34>
 *   @0xedc5c cmp r4, #9
 *   @0xedc60 bls 0xedc38 <_Z14CheckConstNamePKc+0x34>
 *   @0xedc64 cmp r3, #95
 *   @0xedc68 beq 0xedc38 <_Z14CheckConstNamePKc+0x34>
 *   @0xedc6c mov r0, #0
 *   @0xedc70 pop {r4, pc}
 *   @0xedc74 cmp r3, #95
 *   @0xedc78 beq 0xedc28 <_Z14CheckConstNamePKc+0x24>
 *   @0xedc7c mov r0, #0
 *   @0xedc80 pop {r4, pc}
 *   @0xedc84 mov r0, #1
 *   @0xedc88 pop {r4, pc}
 *
 * ══ §42/289 DrawLayerSpriteElement  0x1b193c  size 136  34 条（0x1b193c..0x1b19c4）
 * @func 0x1b193c 0x1b19c4  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Exists(int) / Sprite_Data(int) / CSprite::Draw(int, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x1c×2 / 0x38×1 / 0xc×1 / 0x2c×1 / 0x30×1 / 0x4×1 / 0x34×1 / 0x3c×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b193c push {r4, r5, lr}
 *   @0x1b1940 sub sp, sp, #28
 *   @0x1b1944 ldr r0, [r2, #0x1c]
 *   @0x1b1948 mov r4, r2
 *   @0x1b194c mov r5, r1
 *   @0x1b1950 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1b1954 cmp r0, #0
 *   @0x1b1958 beq 0x1b19bc <_Z22DrawLayerSpriteElementP9tagYYRECTP6CLayerP19CLayerSpriteElement+0x80>
 *   @0x1b195c ldr r0, [r4, #0x1c]
 *   @0x1b1960 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1b1964 vldr s15, [r4, #32]
 *   @0x1b1968 vcvt.s32.f32 s15, s15
 *   @0x1b196c ldr r3, [r4, #0x38]
 *   @0x1b1970 vldr s12, [r4, #64]
 *   @0x1b1974 vldr s13, [r5, #8]
 *   @0x1b1978 str r3, [sp, #0xc]
 *   @0x1b197c vldr s14, [r4, #68]
 *   @0x1b1980 ldr r2, [r4, #0x2c]
 *   @0x1b1984 ldr r3, [r4, #0x30]
 *   @0x1b1988 vmov r1, s15
 *   @0x1b198c vldr s15, [r5, #12]
 *   @0x1b1990 vadd.f32 s13, s12, s13
 *   @0x1b1994 str r2, [sp]
 *   @0x1b1998 str r3, [sp, #0x4]
 *   @0x1b199c ldr r2, [r4, #0x34]
 *   @0x1b19a0 ldr r3, [r4, #0x3c]
 *   @0x1b19a4 str r2, [sp, #0x8]
 *   @0x1b19a8 str r3, [sp, #0x10]
 *   @0x1b19ac vadd.f32 s15, s14, s15
 *   @0x1b19b0 vmov r2, s13
 *   @0x1b19b4 vmov r3, s15
 *   @0x1b19b8 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0x1b19bc add sp, sp, #28
 *   @0x1b19c0 pop {r4, r5, pc}
 *
 * ══ §43/289 Color_Merge  0x20ffb8  size 136  34 条（0x20ffb8..0x210040）
 * @func 0x20ffb8 0x210040  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Color_ColorToRGB(unsigned int&)×2 / Color_MergeRGB(TRGB, TRGB, float) / Color_RGBToColor(TRGB&)
 * 字段偏移 top8: 0xc×2 / 0x10×2 / 0x4×1 / 0xd×1 / 0xe×1 / 0x11×1 / 0x12×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20ffb8 push {r4, lr}
 *   @0x20ffbc sub sp, sp, #24
 *   @0x20ffc0 mov r4, r2
 *   @0x20ffc4 str r0, [sp, #0x4]
 *   @0x20ffc8 add r0, sp, #4
 *   @0x20ffcc str r1, [sp]
 *   @0x20ffd0 bl 0x20fa00 <_Z16Color_ColorToRGBRj>
 *   @0x20ffd4 mov r3, r0
 *   @0x20ffd8 mov r0, sp
 *   @0x20ffdc ubfx r2, r3, #0x8, #0x8
 *   @0x20ffe0 strb r3, [sp, #0xc]
 *   @0x20ffe4 strb r2, [sp, #0xd]
 *   @0x20ffe8 ubfx r3, r3, #0x10, #0x8
 *   @0x20ffec strb r3, [sp, #0xe]
 *   @0x20fff0 bl 0x20fa00 <_Z16Color_ColorToRGBRj>
 *   @0x20fff4 mov r2, r4
 *   @0x20fff8 strb r0, [sp, #0x10]
 *   @0x20fffc ubfx r3, r0, #0x8, #0x8
 *   @0x210000 ubfx r0, r0, #0x10, #0x8
 *   @0x210004 strb r3, [sp, #0x11]
 *   @0x210008 strb r0, [sp, #0x12]
 *   @0x21000c ldr r1, [sp, #0x10]
 *   @0x210010 ldr r0, [sp, #0xc]
 *   @0x210014 bl 0x20fee0 <_Z14Color_MergeRGB4TRGBS_f>
 *   @0x210018 mov r3, r0
 *   @0x21001c add r0, sp, #20
 *   @0x210020 ubfx r2, r3, #0x8, #0x8
 *   @0x210024 strb r3, [sp, #0x14]
 *   @0x210028 strb r2, [sp, #0x15]
 *   @0x21002c ubfx r3, r3, #0x10, #0x8
 *   @0x210030 strb r3, [sp, #0x16]
 *   @0x210034 bl 0x20fa2c <_Z16Color_RGBToColorR4TRGB>
 *   @0x210038 add sp, sp, #24
 *   @0x21003c pop {r4, pc}
 *
 * ══ §44/289 vorbis_comment_clear  0x22ac4c  size 136  34 条（0x22ac4c..0x22acd4）
 * @func 0x22ac4c 0x22acd4  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×4 / vorbis_comment_clear+0x4c
 * 字段偏移 top8: 0x8×2 / 0x2×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22ac4c push {r3, r4, r5, lr}
 *   @0x22ac50 subs r5, r0, #0
 *   @0x22ac54 popeq {r3, r4, r5, pc}
 *   @0x22ac58 ldr r3, [r5]
 *   @0x22ac5c cmp r3, #0
 *   @0x22ac60 beq 0x22aca0 <vorbis_comment_clear+0x54>
 *   @0x22ac64 ldr r2, [r5, #0x8]
 *   @0x22ac68 cmp r2, #0
 *   @0x22ac6c ble 0x22ac98 <vorbis_comment_clear+0x4c>
 *   @0x22ac70 mov r4, #0
 *   @0x22ac74 ldr r0, [r3, r4, lsl #2]
 *   @0x22ac78 add r4, r4, #1
 *   @0x22ac7c cmp r0, #0
 *   @0x22ac80 beq 0x22ac90 <vorbis_comment_clear+0x44>
 *   @0x22ac84 bl 0xb655c <free@plt>
 *   @0x22ac88 ldr r3, [r5]
 *   @0x22ac8c ldr r2, [r5, #0x8]
 *   @0x22ac90 cmp r2, r4
 *   @0x22ac94 bgt 0x22ac74 <vorbis_comment_clear+0x28>
 *   @0x22ac98 mov r0, r3
 *   @0x22ac9c bl 0xb655c <free@plt>
 *   @0x22aca0 ldr r0, [r5, #0x4]
 *   @0x22aca4 cmp r0, #0
 *   @0x22aca8 beq 0x22acb0 <vorbis_comment_clear+0x64>
 *   @0x22acac bl 0xb655c <free@plt>
 *   @0x22acb0 ldr r0, [r5, #0xc]
 *   @0x22acb4 cmp r0, #0
 *   @0x22acb8 beq 0x22acc0 <vorbis_comment_clear+0x74>
 *   @0x22acbc bl 0xb655c <free@plt>
 *   @0x22acc0 mov r0, r5
 *   @0x22acc4 mov r1, #0
 *   @0x22acc8 mov r2, #16
 *   @0x22accc pop {r3, r4, r5, lr}
 *   @0x22acd0 b 0xb65b0 <memset@plt>
 *
 * ══ §45/289 JS_StandardBuiltInObjectConstructor  0x23cabc  size 136  34 条（0x23cabc..0x23cb44）
 * @func 0x23cabc 0x23cb44  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x23cacc→0x756450
 * 调用序列: YYSetInstance(RValue*) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x28×3 / 0x5c×2 / 0x40×2 / 0x18×1 / 0x3c×1 / 0x2c×1 / 0x4c×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cabc push {r3, r4, r5, lr}
 *   @0x23cac0 mov r4, r0
 *   @0x23cac4 bl 0xdc37c <_Z13YYSetInstanceP6RValue>
 *   @0x23cac8 ldr r5, [pc, #0x5c]
 *   @0x23cacc ldr r3, [pc, #0x5c]
 *   @0x23cad0 add r5, pc, r5
 *   @0x23cad4 ldr r4, [r4]
 *   @0x23cad8 ldr r3, [r5, r3]
 *   @0x23cadc mov r0, r4
 *   @0x23cae0 ldr r1, [r3]
 *   @0x23cae4 str r1, [r4, #0x18]
 *   @0x23cae8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x23caec ldr r3, [pc, #0x40]
 *   @0x23caf0 ldr r1, [r4, #0x28]
 *   @0x23caf4 ldr r2, [pc, #0x3c]
 *   @0x23caf8 orr r1, r1, #1
 *   @0x23cafc str r1, [r4, #0x28]
 *   @0x23cb00 add r2, pc, r2
 *   @0x23cb04 str r2, [r4, #0x40]
 *   @0x23cb08 ldr r2, [pc, #0x2c]
 *   @0x23cb0c ldr r1, [r5, r3]
 *   @0x23cb10 ldr r3, [pc, #0x28]
 *   @0x23cb14 str r1, [r4, #0x4c]
 *   @0x23cb18 ldr r2, [r5, r2]
 *   @0x23cb1c str r2, [r4, #0x50]
 *   @0x23cb20 ldr r3, [r5, r3]
 *   @0x23cb24 str r3, [r4, #0x54]
 *   @0x23cb28 pop {r3, r4, r5, pc}
 *   @0x23cb2c andseq r5, r11, r0, lsl #3
 *   @0x23cb30 .word 0xffffc050
 *   @0x23cb34 .word 0xfffff8ac
 *   @0x23cb38 ldrsbeq r8, [r1], -r4
 *   @0x23cb3c .word 0xfffff8b0
 *   @0x23cb40 .word 0xfffff8b4
 *
 * ══ §46/289 getRadixChar  0x23fe14  size 136  34 条（0x23fe14..0x23fe9c）
 * @func 0x23fe14 0x23fe9c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getRadixChar(char, int)+0x60
 * 字段偏移 top8: 0x1×2 / 0x4×2 / 0x-4×1 / 0x6c×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23fe14 cmp r1, #0
 *   @0x23fe18 str r4, [sp, #-0x4]!
 *   @0x23fe1c ble 0x23fe74 <_Z12getRadixCharci+0x60>
 *   @0x23fe20 ldr r2, [pc, #0x6c]
 *   @0x23fe24 ldr r2, [pc, r2]
 *   @0x23fe28 ldrb r3, [r2]
 *   @0x23fe2c cmp r3, r0
 *   @0x23fe30 beq 0x23fe8c <_Z12getRadixCharci+0x78>
 *   @0x23fe34 ldr r12, [pc, #0x5c]
 *   @0x23fe38 ldr r12, [pc, r12]
 *   @0x23fe3c ldrb r3, [r12]
 *   @0x23fe40 cmp r3, r0
 *   @0x23fe44 beq 0x23fe8c <_Z12getRadixCharci+0x78>
 *   @0x23fe48 mov r3, #0
 *   @0x23fe4c b 0x23fe68 <_Z12getRadixCharci+0x54>
 *   @0x23fe50 ldrb r4, [r2, #0x1]!
 *   @0x23fe54 cmp r4, r0
 *   @0x23fe58 beq 0x23fe80 <_Z12getRadixCharci+0x6c>
 *   @0x23fe5c ldrb r4, [r12, #0x1]!
 *   @0x23fe60 cmp r4, r0
 *   @0x23fe64 beq 0x23fe80 <_Z12getRadixCharci+0x6c>
 *   @0x23fe68 add r3, r3, #1
 *   @0x23fe6c cmp r3, r1
 *   @0x23fe70 bne 0x23fe50 <_Z12getRadixCharci+0x3c>
 *   @0x23fe74 mvn r0, #0
 *   @0x23fe78 ldr r4, [sp], #4
 *   @0x23fe7c bx lr
 *   @0x23fe80 mov r0, r3
 *   @0x23fe84 ldr r4, [sp], #4
 *   @0x23fe88 bx lr
 *   @0x23fe8c mov r0, #0
 *   @0x23fe90 b 0x23fe84 <_Z12getRadixCharci+0x70>
 *   @0x23fe94 ldrsheq r1, [r11], -r0
 *   @0x23fe98 andseq r1, r11, r0, ror #13
 *
 * ══ §47/289 b2World::~b2World  0x2c8f74  size 136  34 条（0x2c8f74..0x2c8ffc）
 * @func 0x2c8f74 0x2c8ffc  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Fixture::Destroy(b2BlockAllocator*) / b2ParticleSystem::~b2ParticleSystem() / b2BroadPhase::~b2BroadPhase() / b2StackAllocator::~b2StackAllocator() / b2BlockAllocator::~b2BlockAllocator()
 * 字段偏移 top8: 0x74×1 / 0x70×1 / 0x4×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c8f74 push {r3, r4, r5, r6, r7, lr}
 *   @0x2c8f78 movw r3, #0x9228
 *   @0x2c8f7c movt r3, #0x1
 *   @0x2c8f80 mov r5, r0
 *   @0x2c8f84 ldr r2, [r0, r3]
 *   @0x2c8f88 cmp r2, #0
 *   @0x2c8f8c beq 0x2c8fd0 <_ZN7b2WorldD2Ev+0x5c>
 *   @0x2c8f90 mov r6, #0
 *   @0x2c8f94 ldr r3, [r2, #0x74]
 *   @0x2c8f98 ldr r7, [r2, #0x70]
 *   @0x2c8f9c cmp r3, #0
 *   @0x2c8fa0 beq 0x2c8fc4 <_ZN7b2WorldD2Ev+0x50>
 *   @0x2c8fa4 ldr r4, [r3, #0x4]
 *   @0x2c8fa8 mov r0, r3
 *   @0x2c8fac str r6, [r3, #0x1c]
 *   @0x2c8fb0 mov r1, r5
 *   @0x2c8fb4 bl 0x2c85f0 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator>
 *   @0x2c8fb8 cmp r4, #0
 *   @0x2c8fbc mov r3, r4
 *   @0x2c8fc0 bne 0x2c8fa4 <_ZN7b2WorldD2Ev+0x30>
 *   @0x2c8fc4 cmp r7, #0
 *   @0x2c8fc8 movne r2, r7
 *   @0x2c8fcc bne 0x2c8f94 <_ZN7b2WorldD2Ev+0x20>
 *   @0x2c8fd0 add r4, r5, #102400
 *   @0x2c8fd4 add r0, r4, #628
 *   @0x2c8fd8 bl 0x2d50c8 <_ZN16b2ParticleSystemD2Ev>
 *   @0x2c8fdc add r0, r4, #472
 *   @0x2c8fe0 bl 0x2dc7f4 <_ZN12b2BroadPhaseD2Ev>
 *   @0x2c8fe4 add r0, r5, #68
 *   @0x2c8fe8 bl 0x2e0f40 <_ZN16b2StackAllocatorD2Ev>
 *   @0x2c8fec mov r0, r5
 *   @0x2c8ff0 bl 0x2c6578 <_ZN16b2BlockAllocatorD2Ev>
 *   @0x2c8ff4 mov r0, r5
 *   @0x2c8ff8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §48/289 IBuffer::IBuffer  0xcca38  size 132  33 条（0xcca38..0xccabc）
 * @func 0xcca38 0xccabc  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::GetPOW2Alignment(int)
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x70×1 / 0x4×1 / 0xc×1 / 0x10×1 / 0x20×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcca38 push {r4, r5, r6, r7, r8, lr}
 *   @0xcca3c mov r4, r0
 *   @0xcca40 ldr r12, [pc, #0x70]
 *   @0xcca44 mov r5, r2
 *   @0xcca48 ldr r0, [sp, #0x18]
 *   @0xcca4c mov r6, r1
 *   @0xcca50 ldr r12, [pc, r12]
 *   @0xcca54 ldrb r7, [sp, #0x1c]
 *   @0xcca58 add r12, r12, #8
 *   @0xcca5c ubfx r0, r0, #0x0, #0x9
 *   @0xcca60 str r12, [r4]
 *   @0xcca64 mov r8, r3
 *   @0xcca68 bl 0xcc958 <_ZN7IBuffer16GetPOW2AlignmentEi>
 *   @0xcca6c mov r1, #0
 *   @0xcca70 str r6, [r4, #0x4]
 *   @0xcca74 str r6, [r4, #0xc]
 *   @0xcca78 str r8, [r4, #0x18]
 *   @0xcca7c str r5, [r4, #0x10]
 *   @0xcca80 str r5, [r4, #0x20]
 *   @0xcca84 strb r7, [r4, #0x3c]
 *   @0xcca88 str r1, [r4, #0x1c]
 *   @0xcca8c str r1, [r4, #0x24]
 *   @0xcca90 str r1, [r4, #0x38]
 *   @0xcca94 str r1, [r4, #0x2c]
 *   @0xcca98 str r1, [r4, #0x30]
 *   @0xcca9c str r1, [r4, #0x28]
 *   @0xccaa0 mov r2, r0
 *   @0xccaa4 mov r0, r4
 *   @0xccaa8 add r12, r5, r2
 *   @0xccaac str r2, [r4, #0x14]
 *   @0xccab0 str r12, [r4, #0x8]
 *   @0xccab4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xccab8 ldrhteq r1, [r2], -r12
 *
 * ══ §49/289 IterateInstances  0xd410c  size 132  33 条（0xd410c..0xd4190）
 * @func 0xd410c 0xd4190  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1ac×2 / 0x74×1 / 0x8×1 / 0x4×1 / 0x14×1 / 0x1a4×1 / 0x1a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd410c push {r4, r5, r6, r7, r8, r9, r10}
 *   @0xd4110 ldr r6, [pc, #0x74]
 *   @0xd4114 add r6, pc, r6
 *   @0xd4118 ldr r2, [r6]
 *   @0xd411c cmp r2, r6
 *   @0xd4120 beq 0xd4184 <_Z16IterateInstancesPP12YYObjectBaseP6VMExec+0x78>
 *   @0xd4124 mov r5, #0
 *   @0xd4128 mov r12, r0
 *   @0xd412c mov r9, r6
 *   @0xd4130 mov r8, r5
 *   @0xd4134 ldr r3, [r6, #0x8]
 *   @0xd4138 str r5, [r12], #4
 *   @0xd413c mov r0, r12
 *   @0xd4140 rsb r3, r3, r2
 *   @0xd4144 ldr r2, [r2]
 *   @0xd4148 str r3, [r1, #0x14]
 *   @0xd414c add r4, r3, #420
 *   @0xd4150 ldr r7, [r3, #0x1ac]
 *   @0xd4154 mov r5, r3
 *   @0xd4158 cmp r7, r6
 *   @0xd415c ldreq r10, [r3, #0x1a8]
 *   @0xd4160 ldreq r7, [r3, #0x1a4]
 *   @0xd4164 streq r10, [r7, #0x4]
 *   @0xd4168 ldreq r10, [r3, #0x1a8]
 *   @0xd416c streq r7, [r10]
 *   @0xd4170 cmp r2, r9
 *   @0xd4174 str r4, [r3, #0x1a4]
 *   @0xd4178 str r4, [r3, #0x1a8]
 *   @0xd417c str r8, [r3, #0x1ac]
 *   @0xd4180 bne 0xd4134 <_Z16IterateInstancesPP12YYObjectBaseP6VMExec+0x28>
 *   @0xd4184 pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0xd4188 bx lr
 *   @0xd418c eorseq r6, r10, r0, lsr #1
 *
 * ══ §50/289 utf8_extract_char  0x10fb38  size 132  33 条（0x10fb38..0x10fbbc）
 * @func 0x10fb38 0x10fbbc  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x1×2 / 0x-4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10fb38 ldr r3, [r0]
 *   @0x10fb3c mov r1, r0
 *   @0x10fb40 str r4, [sp, #-0x4]!
 *   @0x10fb44 ldrb r2, [r3]
 *   @0x10fb48 tst r2, #128
 *   @0x10fb4c beq 0x10fb88 <utf8_extract_char+0x50>
 *   @0x10fb50 tst r2, #32
 *   @0x10fb54 beq 0x10fb9c <utf8_extract_char+0x64>
 *   @0x10fb58 ldrb r4, [r3, #0x1]
 *   @0x10fb5c add r12, r3, #3
 *   @0x10fb60 ldrb r0, [r3, #0x2]
 *   @0x10fb64 and r3, r4, #63
 *   @0x10fb68 str r12, [r1]
 *   @0x10fb6c and r0, r0, #63
 *   @0x10fb70 ldr r4, [sp], #4
 *   @0x10fb74 lsl r3, r3, #6
 *   @0x10fb78 add r2, r3, r2, lsl #12
 *   @0x10fb7c add r0, r0, r2
 *   @0x10fb80 uxth r0, r0
 *   @0x10fb84 bx lr
 *   @0x10fb88 mov r0, r2
 *   @0x10fb8c add r3, r3, #1
 *   @0x10fb90 str r3, [r1]
 *   @0x10fb94 ldr r4, [sp], #4
 *   @0x10fb98 bx lr
 *   @0x10fb9c ldrb r0, [r3, #0x1]
 *   @0x10fba0 and r2, r2, #31
 *   @0x10fba4 add r3, r3, #2
 *   @0x10fba8 ldr r4, [sp], #4
 *   @0x10fbac and r0, r0, #63
 *   @0x10fbb0 str r3, [r1]
 *   @0x10fbb4 add r0, r0, r2, lsl #6
 *   @0x10fbb8 bx lr
 *
 * ══ §51/289 LinkCacheAchievementToEnd  0x159824  size 132  33 条（0x159824..0x1598a8）
 * @func 0x159824 0x1598a8  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x15982c→0x484aa0, 0x159858→0x484a98, 0x159860→0x484a9c, 0x159880→0x484aa4
 * 调用序列: 无
 * 字段偏移 top8: 0x68×1 / 0x64×1 / 0x4×1 / 0x3c×1 / 0x38×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159824 ldr r3, [pc, #0x68]
 *   @0x159828 mov r2, #0
 *   @0x15982c ldr r1, [pc, #0x64]
 *   @0x159830 add r3, pc, r3
 *   @0x159834 str r2, [r0]
 *   @0x159838 str r2, [r0, #0x4]
 *   @0x15983c ldr r1, [r3, r1]
 *   @0x159840 ldr r2, [r1]
 *   @0x159844 cmp r2, #0
 *   @0x159848 strne r0, [r2]
 *   @0x15984c strne r2, [r0, #0x4]
 *   @0x159850 strne r0, [r1]
 *   @0x159854 beq 0x159880 <_Z25LinkCacheAchievementToEndP16SAchivementCache+0x5c>
 *   @0x159858 ldr r2, [pc, #0x3c]
 *   @0x15985c mov r1, #1
 *   @0x159860 ldr r0, [pc, #0x38]
 *   @0x159864 ldr r2, [r3, r2]
 *   @0x159868 ldr r12, [r2]
 *   @0x15986c add r12, r12, r1
 *   @0x159870 str r12, [r2]
 *   @0x159874 ldr r3, [r3, r0]
 *   @0x159878 strb r1, [r3]
 *   @0x15987c bx lr
 *   @0x159880 ldr r2, [pc, #0x1c]
 *   @0x159884 ldr r2, [r3, r2]
 *   @0x159888 str r0, [r1]
 *   @0x15988c str r0, [r2]
 *   @0x159890 b 0x159858 <_Z25LinkCacheAchievementToEndP16SAchivementCache+0x34>
 *   @0x159894 eoreq r8, r9, r0, lsr #8
 *   @0x159898 .word 0xffffdf80
 *   @0x15989c .word 0xffffdf7c
 *   @0x1598a0 .word 0xffffdf78
 *   @0x1598a4 .word 0xffffdf74
 *
 * ══ §52/289 RenderStateManager::SaveStates  0x167fcc  size 132  33 条（0x167fcc..0x168050）
 * @func 0x167fcc 0x168050  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167fcc push {r4, r5, r6, lr}
 *   @0x167fd0 movw r5, #0x3db8
 *   @0x167fd4 mov r4, r0
 *   @0x167fd8 ldr r0, [r0, r5]
 *   @0x167fdc mov r6, #464
 *   @0x167fe0 add r1, r4, #480
 *   @0x167fe4 mov r2, #144
 *   @0x167fe8 mla r0, r6, r0, r4
 *   @0x167fec add r0, r0, #952
 *   @0x167ff0 bl 0xb65bc <memcpy@plt>
 *   @0x167ff4 ldr r3, [r4, r5]
 *   @0x167ff8 add r1, r4, #624
 *   @0x167ffc mov r2, #320
 *   @0x168000 mla r0, r6, r3, r4
 *   @0x168004 add r0, r0, #1088
 *   @0x168008 add r0, r0, #8
 *   @0x16800c bl 0xb65bc <memcpy@plt>
 *   @0x168010 ldr r3, [r4, r5]
 *   @0x168014 cmp r3, #31
 *   @0x168018 addle r3, r3, #1
 *   @0x16801c strle r3, [r4, r5]
 *   @0x168020 pople {r4, r5, r6, pc}
 *   @0x168024 ldr r3, [pc, #0x1c]
 *   @0x168028 ldr r1, [pc, #0x1c]
 *   @0x16802c ldr r3, [pc, r3]
 *   @0x168030 add r1, pc, r1
 *   @0x168034 ldr r0, [r3]
 *   @0x168038 ldr r3, [r0]
 *   @0x16803c ldr r3, [r3, #0xc]
 *   @0x168040 blx r3
 *   @0x168044 pop {r4, r5, r6, pc}
 *   @0x168048 eoreq r5, r8, r8, ror #13
 *   @0x16804c andseq r2, lr, r12, lsr #14
 *
 * ══ §53/289 GR_Texture_Free_Only  0x171ae4  size 132  33 条（0x171ae4..0x171b68）
 * @func 0x171ae4 0x171b68  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush() / _FreeSurfaceData(int)
 * 字段偏移 top8: 0x54×1 / 0x8×1 / 0x4×1 / 0xc×1 / 0x28×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171ae4 push {r4, lr}
 *   @0x171ae8 mov r4, r0
 *   @0x171aec bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x171af0 mov r0, r4
 *   @0x171af4 bl 0x171a90 <_Z16_FreeSurfaceDatai>
 *   @0x171af8 subs r3, r0, #0
 *   @0x171afc beq 0x171b54 <_Z20GR_Texture_Free_Onlyi+0x70>
 *   @0x171b00 ldr r2, [pc, #0x54]
 *   @0x171b04 mov r1, #0
 *   @0x171b08 mvn r0, #0
 *   @0x171b0c str r1, [r3, #0x8]
 *   @0x171b10 ldr r2, [pc, r2]
 *   @0x171b14 str r0, [r3, #0x4]
 *   @0x171b18 str r1, [r3, #0xc]
 *   @0x171b1c ldr r3, [r2]
 *   @0x171b20 cmp r3, r4
 *   @0x171b24 beq 0x171b30 <_Z20GR_Texture_Free_Onlyi+0x4c>
 *   @0x171b28 mov r0, #1
 *   @0x171b2c pop {r4, pc}
 *   @0x171b30 ldr r1, [pc, #0x28]
 *   @0x171b34 mov r2, #1
 *   @0x171b38 ldr r3, [pc, #0x24]
 *   @0x171b3c mov r0, r2
 *   @0x171b40 ldr r1, [pc, r1]
 *   @0x171b44 ldr r3, [pc, r3]
 *   @0x171b48 str r2, [r1]
 *   @0x171b4c str r2, [r3]
 *   @0x171b50 pop {r4, pc}
 *   @0x171b54 mov r0, r3
 *   @0x171b58 pop {r4, pc}
 *   @0x171b5c eoreq r12, r7, r8, asr #21
 *   @0x171b60 eoreq lr, r7, r8, asr #32
 *   @0x171b64 eoreq lr, r7, r12, asr #32
 *
 * ══ §54/289 CScript::Compile  0x1dfe10  size 132  33 条（0x1dfe10..0x1dfe94）
 * @func 0x1dfe10 0x1dfe94  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CCode::CCode(int, bool)
 * 字段偏移 top8: 0x10×2 / 0x70×1 / 0x58×1 / 0x8×1 / 0x24×1 / 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfe10 ldr r3, [pc, #0x70]
 *   @0x1dfe14 push {r4, r5, r6, lr}
 *   @0x1dfe18 ldr r3, [pc, r3]
 *   @0x1dfe1c mov r4, r0
 *   @0x1dfe20 ldrb r5, [r3]
 *   @0x1dfe24 cmp r5, #0
 *   @0x1dfe28 bne 0x1dfe64 <_ZN7CScript7CompileEv+0x54>
 *   @0x1dfe2c ldr r3, [pc, #0x58]
 *   @0x1dfe30 ldr r3, [pc, r3]
 *   @0x1dfe34 ldr r0, [r3]
 *   @0x1dfe38 cmp r0, #0
 *   @0x1dfe3c popeq {r4, r5, r6, pc}
 *   @0x1dfe40 mov r0, #124
 *   @0x1dfe44 bl 0x27c524 <_Znwj>
 *   @0x1dfe48 mov r2, r5
 *   @0x1dfe4c ldr r1, [r4, #0x10]
 *   @0x1dfe50 mov r6, r0
 *   @0x1dfe54 bl 0xcefc8 <_ZN5CCodeC2Eib>
 *   @0x1dfe58 str r6, [r4, #0x8]
 *   @0x1dfe5c mov r0, #1
 *   @0x1dfe60 pop {r4, r5, r6, pc}
 *   @0x1dfe64 ldr r3, [pc, #0x24]
 *   @0x1dfe68 mov r0, #1
 *   @0x1dfe6c ldr r2, [r4, #0x10]
 *   @0x1dfe70 ldr r3, [pc, r3]
 *   @0x1dfe74 ldr r3, [r3]
 *   @0x1dfe78 ldr r3, [r3, #0x1c]
 *   @0x1dfe7c add r3, r3, r2, lsl #3
 *   @0x1dfe80 str r3, [r4, #0xc]
 *   @0x1dfe84 pop {r4, r5, r6, pc}
 *   @0x1dfe88 eoreq sp, r0, r4, lsl #26
 *   @0x1dfe8c eoreq sp, r0, r8, lsl sp
 *   @0x1dfe90 .word 0x0020dcd0
 *
 * ══ §55/289 Script_Name  0x1e058c  size 132  33 条（0x1e058c..0x1e0610）
 * @func 0x1e058c 0x1e0610  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Script_Name(int)+0x54
 * 字段偏移 top8: 0x2×2 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x38×1 / 0x28×1 / 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e058c cmp r0, #0
 *   @0x1e0590 blt 0x1e05e0 <_Z11Script_Namei+0x54>
 *   @0x1e0594 ldr r3, [pc, #0x5c]
 *   @0x1e0598 ldr r3, [pc, r3]
 *   @0x1e059c ldr r3, [r3]
 *   @0x1e05a0 cmp r0, r3
 *   @0x1e05a4 bge 0x1e05d4 <_Z11Script_Namei+0x48>
 *   @0x1e05a8 ldr r3, [pc, #0x4c]
 *   @0x1e05ac ldr r3, [pc, r3]
 *   @0x1e05b0 ldr r3, [r3, #0x4]
 *   @0x1e05b4 ldr r3, [r3, r0, lsl #2]
 *   @0x1e05b8 cmp r3, #0
 *   @0x1e05bc beq 0x1e05ec <_Z11Script_Namei+0x60>
 *   @0x1e05c0 ldr r3, [pc, #0x38]
 *   @0x1e05c4 ldr r3, [pc, r3]
 *   @0x1e05c8 ldr r3, [r3]
 *   @0x1e05cc ldr r0, [r3, r0, lsl #2]
 *   @0x1e05d0 bx lr
 *   @0x1e05d4 ldr r0, [pc, #0x28]
 *   @0x1e05d8 add r0, pc, r0
 *   @0x1e05dc bx lr
 *   @0x1e05e0 ldr r0, [pc, #0x20]
 *   @0x1e05e4 add r0, pc, r0
 *   @0x1e05e8 bx lr
 *   @0x1e05ec ldr r0, [pc, #0x18]
 *   @0x1e05f0 add r0, pc, r0
 *   @0x1e05f4 bx lr
 *   @0x1e05f8 mlaeq r1, r4, r7, r0
 *   @0x1e05fc eoreq r0, r1, r12, ror r7
 *   @0x1e0600 eoreq r0, r1, r12, ror #14
 *   @0x1e0604 andseq r0, r5, r8, ror #9
 *   @0x1e0608 ldrsbeq r0, [r5], -r12
 *   @0x1e060c ldrsbeq r0, [r5], -r0
 *
 * ══ §56/289 GetVertexFormat  0x1e2cd0  size 132  33 条（0x1e2cd0..0x1e2d54）
 * @func 0x1e2cd0 0x1e2d54  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x74×1 / 0x58×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2cd0 ldr r1, [pc, #0x74]
 *   @0x1e2cd4 ldr r1, [pc, r1]
 *   @0x1e2cd8 ldr r3, [r1]
 *   @0x1e2cdc cmp r3, #0
 *   @0x1e2ce0 beq 0x1e2cf0 <_Z15GetVertexFormati+0x20>
 *   @0x1e2ce4 ldr r2, [r3]
 *   @0x1e2ce8 cmp r2, r0
 *   @0x1e2cec beq 0x1e2d44 <_Z15GetVertexFormati+0x74>
 *   @0x1e2cf0 ldr r3, [pc, #0x58]
 *   @0x1e2cf4 ldr r3, [pc, r3]
 *   @0x1e2cf8 ldr r2, [r3, #0x4]
 *   @0x1e2cfc ldr r3, [r3]
 *   @0x1e2d00 and r2, r0, r2
 *   @0x1e2d04 ldr r3, [r3, r2, lsl #3]
 *   @0x1e2d08 cmp r3, #0
 *   @0x1e2d0c bne 0x1e2d20 <_Z15GetVertexFormati+0x50>
 *   @0x1e2d10 b 0x1e2d38 <_Z15GetVertexFormati+0x68>
 *   @0x1e2d14 ldr r3, [r3, #0x4]
 *   @0x1e2d18 cmp r3, #0
 *   @0x1e2d1c beq 0x1e2d38 <_Z15GetVertexFormati+0x68>
 *   @0x1e2d20 ldr r2, [r3, #0x8]
 *   @0x1e2d24 cmp r0, r2
 *   @0x1e2d28 bne 0x1e2d14 <_Z15GetVertexFormati+0x44>
 *   @0x1e2d2c ldr r0, [r3, #0xc]
 *   @0x1e2d30 str r0, [r1]
 *   @0x1e2d34 bx lr
 *   @0x1e2d38 mov r0, r3
 *   @0x1e2d3c str r0, [r1]
 *   @0x1e2d40 bx lr
 *   @0x1e2d44 mov r0, r3
 *   @0x1e2d48 bx lr
 *   @0x1e2d4c eoreq lr, r0, r4, asr #1
 *   @0x1e2d50 eoreq lr, r0, r8, lsr #1
 *
 * ══ §57/289 CheckALError  0x220198  size 132  33 条（0x220198..0x22021c）
 * @func 0x220198 0x22021c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a54 / alutGetError / alutGetErrorString
 * 字段偏移 top8: 0xc×2 / 0x50×1 / 0x3c×1 / 0x28×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220198 push {r3, r4, r5, lr}
 *   @0x22019c bl 0xb6a54 <alGetError@plt>
 *   @0x2201a0 subs r2, r0, #0
 *   @0x2201a4 bne 0x2201e4 <_Z12CheckALErrorv+0x4c>
 *   @0x2201a8 bl 0x221714 <alutGetError>
 *   @0x2201ac cmp r0, #0
 *   @0x2201b0 popeq {r3, r4, r5, pc}
 *   @0x2201b4 ldr r3, [pc, #0x50]
 *   @0x2201b8 ldr r3, [pc, r3]
 *   @0x2201bc ldr r4, [r3]
 *   @0x2201c0 ldr r3, [r4]
 *   @0x2201c4 ldr r5, [r3, #0xc]
 *   @0x2201c8 bl 0x221730 <alutGetErrorString>
 *   @0x2201cc ldr r1, [pc, #0x3c]
 *   @0x2201d0 add r1, pc, r1
 *   @0x2201d4 mov r2, r0
 *   @0x2201d8 mov r0, r4
 *   @0x2201dc blx r5
 *   @0x2201e0 pop {r3, r4, r5, pc}
 *   @0x2201e4 ldr r0, [pc, #0x28]
 *   @0x2201e8 mov r3, r2
 *   @0x2201ec ldr r1, [pc, #0x24]
 *   @0x2201f0 ldr r0, [pc, r0]
 *   @0x2201f4 add r1, pc, r1
 *   @0x2201f8 ldr r0, [r0]
 *   @0x2201fc ldr r12, [r0]
 *   @0x220200 ldr r12, [r12, #0xc]
 *   @0x220204 blx r12
 *   @0x220208 b 0x2201a8 <_Z12CheckALErrorv+0x10>
 *   @0x22020c andseq sp, r12, r12, asr r5
 *   @0x220210 andseq r4, r3, r8, asr r6
 *   @0x220214 andseq sp, r12, r4, lsr #10
 *   @0x220218 andseq r4, r3, r12, lsl r6
 *
 * ══ §58/289 COggThread::COggThread  0x223750  size 132  33 条（0x223750..0x2237d4）
 * @func 0x223750 0x2237d4  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / Mutex::Mutex(char const*) / 0xb65b0
 * 字段偏移 top8: 0x820×1 / 0x818×1 / 0x81c×1 / 0x821×1 / 0x824×1 / 0x828×1 / 0x4c×1 / 0x82c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223750 push {r4, r5, r6, lr}
 *   @0x223754 mov r4, r0
 *   @0x223758 mov r5, #0
 *   @0x22375c mov r0, #8
 *   @0x223760 strb r5, [r4, #0x820]
 *   @0x223764 str r5, [r4, #0x818]
 *   @0x223768 str r5, [r4, #0x81c]
 *   @0x22376c strb r5, [r4, #0x821]
 *   @0x223770 str r5, [r4, #0x824]
 *   @0x223774 str r5, [r4, #0x828]
 *   @0x223778 bl 0x27c524 <_Znwj>
 *   @0x22377c ldr r1, [pc, #0x4c]
 *   @0x223780 add r1, pc, r1
 *   @0x223784 mov r6, r0
 *   @0x223788 bl 0x27e070 <_ZN5MutexC2EPKc>
 *   @0x22378c str r6, [r4, #0x82c]
 *   @0x223790 mov r0, r4
 *   @0x223794 strb r5, [r4, #0x800]
 *   @0x223798 mov r1, r5
 *   @0x22379c mov r2, #2048
 *   @0x2237a0 bl 0xb65b0 <memset@plt>
 *   @0x2237a4 mvn r3, #0
 *   @0x2237a8 strb r5, [r4, #0x801]
 *   @0x2237ac mov r0, r4
 *   @0x2237b0 strb r5, [r4, #0x802]
 *   @0x2237b4 str r5, [r4, #0x808]
 *   @0x2237b8 str r5, [r4, #0x810]
 *   @0x2237bc strb r5, [r4, #0x831]
 *   @0x2237c0 str r5, [r4, #0x804]
 *   @0x2237c4 str r5, [r4, #0x814]
 *   @0x2237c8 str r3, [r4, #0x80c]
 *   @0x2237cc pop {r4, r5, r6, pc}
 *   @0x2237d0 andseq pc, r0, r4, lsr r0
 *
 * ══ §59/289 yyMatrix::SetZRotation  0x27aedc  size 132  33 条（0x27aedc..0x27af60）
 * @func 0x27aedc 0x27af60  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x38×1 / 0x34×1 / 0x30×1 / 0x2c×1 / 0x24×1 / 0x20×1 / 0x1c×1 / 0x18×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27aedc vmov s15, r1
 *   @0x27aee0 mov r3, #0
 *   @0x27aee4 push {r4, lr}
 *   @0x27aee8 vpush {d8}
 *   @0x27aeec vldr s17, [pc, #104]
 *   @0x27aef0 vmul.f32 s17, s15, s17
 *   @0x27aef4 mov r4, r0
 *   @0x27aef8 str r3, [r0, #0x38]
 *   @0x27aefc str r3, [r0, #0x34]
 *   @0x27af00 str r3, [r0, #0x30]
 *   @0x27af04 str r3, [r0, #0x2c]
 *   @0x27af08 str r3, [r0, #0x24]
 *   @0x27af0c str r3, [r0, #0x20]
 *   @0x27af10 str r3, [r0, #0x1c]
 *   @0x27af14 str r3, [r0, #0x18]
 *   @0x27af18 str r3, [r0, #0xc]
 *   @0x27af1c str r3, [r0, #0x8]
 *   @0x27af20 mov r3, #1065353216
 *   @0x27af24 str r3, [r4, #0x3c]
 *   @0x27af28 vmov r0, s17
 *   @0x27af2c str r3, [r4, #0x28]
 *   @0x27af30 bl 0xb6580 <sinf@plt>
 *   @0x27af34 vmov s16, r0
 *   @0x27af38 vmov r0, s17
 *   @0x27af3c bl 0xb658c <cosf@plt>
 *   @0x27af40 vneg.f32 s15, s16
 *   @0x27af44 vstr s16, [r4, #16]
 *   @0x27af48 vstr s15, [r4, #4]
 *   @0x27af4c str r0, [r4]
 *   @0x27af50 str r0, [r4, #0x14]
 *   @0x27af54 vpop {d8}
 *   @0x27af58 pop {r4, pc}
 *   @0x27af5c vstmialo lr, {s30, s31}
 *
 * ══ §60/289 utf8_get_charW  0x27eefc  size 132  33 条（0x27eefc..0x27ef80）
 * @func 0x27eefc 0x27ef80  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×2 / 0x2×2 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27eefc mov r3, r0
 *   @0x27ef00 ldrb r0, [r0]
 *   @0x27ef04 tst r0, #128
 *   @0x27ef08 bxeq lr
 *   @0x27ef0c tst r0, #32
 *   @0x27ef10 beq 0x27ef4c <utf8_get_charW+0x50>
 *   @0x27ef14 tst r0, #16
 *   @0x27ef18 ldrb r1, [r3, #0x1]
 *   @0x27ef1c beq 0x27ef60 <utf8_get_charW+0x64>
 *   @0x27ef20 ldrb r2, [r3, #0x2]
 *   @0x27ef24 and r1, r1, #63
 *   @0x27ef28 and r0, r0, #7
 *   @0x27ef2c ldrb r3, [r3, #0x3]
 *   @0x27ef30 and r2, r2, #63
 *   @0x27ef34 lsl r1, r1, #12
 *   @0x27ef38 add r0, r1, r0, lsl #18
 *   @0x27ef3c and r3, r3, #63
 *   @0x27ef40 add r0, r0, r2, lsl #6
 *   @0x27ef44 add r0, r0, r3
 *   @0x27ef48 bx lr
 *   @0x27ef4c ldrb r3, [r3, #0x1]
 *   @0x27ef50 and r0, r0, #31
 *   @0x27ef54 and r3, r3, #63
 *   @0x27ef58 add r0, r3, r0, lsl #6
 *   @0x27ef5c bx lr
 *   @0x27ef60 lsl r2, r0, #12
 *   @0x27ef64 ldrb r3, [r3, #0x2]
 *   @0x27ef68 and r1, r1, #63
 *   @0x27ef6c uxth r2, r2
 *   @0x27ef70 and r3, r3, #63
 *   @0x27ef74 add r0, r2, r1, lsl #6
 *   @0x27ef78 add r0, r0, r3
 *   @0x27ef7c bx lr
 *
 * ══ §61/289 spSkeletonBounds_intersectsSegment  0x28acf4  size 132  33 条（0x28acf4..0x28ad78）
 * @func 0x28acf4 0x28ad78  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonBounds_intersectsSegment+0x78 / spPolygon_intersectsSegment
 * 字段偏移 top8: 0x28×1 / 0x8×1 / 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28acf4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x28acf8 mov r6, r1
 *   @0x28acfc ldr r1, [r0]
 *   @0x28ad00 sub sp, sp, #8
 *   @0x28ad04 mov r5, r0
 *   @0x28ad08 mov r7, r2
 *   @0x28ad0c cmp r1, #0
 *   @0x28ad10 mov r8, r3
 *   @0x28ad14 ldr r10, [sp, #0x28]
 *   @0x28ad18 movgt r4, #0
 *   @0x28ad1c bgt 0x28ad30 <spSkeletonBounds_intersectsSegment+0x3c>
 *   @0x28ad20 b 0x28ad6c <spSkeletonBounds_intersectsSegment+0x78>
 *   @0x28ad24 ldr r0, [r5]
 *   @0x28ad28 cmp r0, r4
 *   @0x28ad2c ble 0x28ad6c <spSkeletonBounds_intersectsSegment+0x78>
 *   @0x28ad30 ldr r0, [r5, #0x8]
 *   @0x28ad34 mov r1, r6
 *   @0x28ad38 mov r2, r7
 *   @0x28ad3c mov r3, r8
 *   @0x28ad40 lsl r9, r4, #2
 *   @0x28ad44 ldr r0, [r0, r4, lsl #2]
 *   @0x28ad48 add r4, r4, #1
 *   @0x28ad4c str r10, [sp]
 *   @0x28ad50 bl 0x28a6a8 <spPolygon_intersectsSegment>
 *   @0x28ad54 cmp r0, #0
 *   @0x28ad58 beq 0x28ad24 <spSkeletonBounds_intersectsSegment+0x30>
 *   @0x28ad5c ldr r3, [r5, #0x4]
 *   @0x28ad60 ldr r0, [r3, r9]
 *   @0x28ad64 add sp, sp, #8
 *   @0x28ad68 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x28ad6c mov r0, #0
 *   @0x28ad70 add sp, sp, #8
 *   @0x28ad74 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §62/289 yyServer::DeleteSocket  0x2974d4  size 132  33 条（0x2974d4..0x297558）
 * @func 0x2974d4 0x297558  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x28×2 / 0x8×2 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2974d4 push {r4, r5}
 *   @0x2974d8 mov r3, #0
 *   @0x2974dc ldr r4, [r0, #0x4]
 *   @0x2974e0 add r2, r4, #132
 *   @0x2974e4 b 0x2974f4 <_ZN8yyServer12DeleteSocketEP8yySocket+0x20>
 *   @0x2974e8 add r3, r3, #1
 *   @0x2974ec cmp r3, #1024
 *   @0x2974f0 beq 0x297548 <_ZN8yyServer12DeleteSocketEP8yySocket+0x74>
 *   @0x2974f4 ldr r12, [r2, #0x4]!
 *   @0x2974f8 cmp r1, r12
 *   @0x2974fc bne 0x2974e8 <_ZN8yyServer12DeleteSocketEP8yySocket+0x14>
 *   @0x297500 add r3, r3, #34
 *   @0x297504 ldr r5, [r0, #0x28]
 *   @0x297508 mov r12, #0
 *   @0x29750c mov r2, #1
 *   @0x297510 str r12, [r4, r3, lsl #2]
 *   @0x297514 mov r12, r2
 *   @0x297518 ldr r3, [r1]
 *   @0x29751c sub r1, r5, #1
 *   @0x297520 and r5, r3, #31
 *   @0x297524 asr r3, r3, #5
 *   @0x297528 add r4, r4, r3, lsl #2
 *   @0x29752c ldr r3, [r4, #0x8]
 *   @0x297530 bic r2, r3, r2, lsl r5
 *   @0x297534 str r2, [r4, #0x8]
 *   @0x297538 str r1, [r0, #0x28]
 *   @0x29753c mov r0, r12
 *   @0x297540 pop {r4, r5}
 *   @0x297544 bx lr
 *   @0x297548 mov r12, #0
 *   @0x29754c mov r0, r12
 *   @0x297550 pop {r4, r5}
 *   @0x297554 bx lr
 *
 * ══ §63/289 b2StackAllocator::Free  0x2e0ffc  size 132  33 条（0x2e0ffc..0x2e1080）
 * @func 0x2e0ffc 0x2e1080  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Free(void*)
 * 字段偏移 top8: 0x-8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e0ffc push {r4, r5, r6, lr}
 *   @0x2e1000 movw r6, #0x918c
 *   @0x2e1004 movt r6, #0x1
 *   @0x2e1008 mov r4, r0
 *   @0x2e100c ldr r3, [r0, r6]
 *   @0x2e1010 add r5, r3, r3, lsl #1
 *   @0x2e1014 add r5, r0, r5, lsl #2
 *   @0x2e1018 add r5, r5, #102400
 *   @0x2e101c add r5, r5, #8
 *   @0x2e1020 ldrb r2, [r5], #4
 *   @0x2e1024 cmp r2, #0
 *   @0x2e1028 bne 0x2e106c <_ZN16b2StackAllocator4FreeEPv+0x70>
 *   @0x2e102c mov r2, #102400
 *   @0x2e1030 ldr r1, [r5, #-0x8]
 *   @0x2e1034 ldr r12, [r0, r2]
 *   @0x2e1038 mov r0, r3
 *   @0x2e103c rsb r3, r1, r12
 *   @0x2e1040 str r3, [r4, r2]
 *   @0x2e1044 movw r3, #0x9004
 *   @0x2e1048 movt r3, #0x1
 *   @0x2e104c movw r2, #0x918c
 *   @0x2e1050 movt r2, #0x1
 *   @0x2e1054 ldr r12, [r4, r3]
 *   @0x2e1058 sub r0, r0, #1
 *   @0x2e105c rsb r1, r1, r12
 *   @0x2e1060 str r1, [r4, r3]
 *   @0x2e1064 str r0, [r4, r2]
 *   @0x2e1068 pop {r4, r5, r6, pc}
 *   @0x2e106c mov r0, r1
 *   @0x2e1070 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2e1074 ldr r0, [r4, r6]
 *   @0x2e1078 ldr r1, [r5, #-0x8]
 *   @0x2e107c b 0x2e1044 <_ZN16b2StackAllocator4FreeEPv+0x48>
 *
 * ══ §64/289 F_BUFFER_Delete  0xc52a4  size 128  32 条（0xc52a4..0xc5324）
 * @func 0xc52a4 0xc5324  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0x10×2 / 0x2×2 / 0x58×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc52a4 push {r3, r4, r5, lr}
 *   @0xc52a8 mov r1, #0
 *   @0xc52ac ldr r0, [sp, #0x10]
 *   @0xc52b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc52b4 subs r4, r0, #0
 *   @0xc52b8 poplt {r3, r4, r5, pc}
 *   @0xc52bc ldr r5, [pc, #0x58]
 *   @0xc52c0 add r5, pc, r5
 *   @0xc52c4 ldr r3, [r5]
 *   @0xc52c8 cmp r4, r3
 *   @0xc52cc popge {r3, r4, r5, pc}
 *   @0xc52d0 ldr r3, [r5, #0x4]
 *   @0xc52d4 ldr r0, [r3, r4, lsl #2]
 *   @0xc52d8 cmp r0, #0
 *   @0xc52dc popeq {r3, r4, r5, pc}
 *   @0xc52e0 ldr r3, [r0, #0x28]
 *   @0xc52e4 cmp r3, #0
 *   @0xc52e8 bgt 0xc5308 <_Z15F_BUFFER_DeleteR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xc52ec ldr r3, [r0]
 *   @0xc52f0 ldr r3, [r3, #0x4]
 *   @0xc52f4 blx r3
 *   @0xc52f8 ldr r3, [r5, #0x4]
 *   @0xc52fc mov r2, #0
 *   @0xc5300 str r2, [r3, r4, lsl #2]
 *   @0xc5304 pop {r3, r4, r5, pc}
 *   @0xc5308 ldr r0, [pc, #0x10]
 *   @0xc530c mov r1, #0
 *   @0xc5310 pop {r3, r4, r5, lr}
 *   @0xc5314 add r0, pc, r0
 *   @0xc5318 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc531c eorseq r4, r11, r4, asr lr
 *   @0xc5320 eoreq r11, r6, r12, ror r8
 *
 * ══ §65/289 InstanceHandled  0xd3f50  size 128  32 条（0xd3f50..0xd3fd0）
 * @func 0xd3f50 0xd3fd0  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1ac×2 / 0x4×2 / 0x6c×1 / 0x-4×1 / 0x34×1 / 0x1a4×1 / 0x1a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3f50 mov r3, r0
 *   @0xd3f54 ldr r0, [pc, #0x6c]
 *   @0xd3f58 ldr r1, [r3, #0x1ac]
 *   @0xd3f5c add r2, r3, #420
 *   @0xd3f60 add r0, pc, r0
 *   @0xd3f64 subs r1, r1, r0
 *   @0xd3f68 rsbs r0, r1, #0
 *   @0xd3f6c adcs r0, r0, r1
 *   @0xd3f70 cmp r0, #0
 *   @0xd3f74 str r4, [sp, #-0x4]!
 *   @0xd3f78 mov r4, #0
 *   @0xd3f7c ldrne r12, [r3, #0x1a8]
 *   @0xd3f80 ldrne r1, [r3, #0x1a4]
 *   @0xd3f84 strne r12, [r1, #0x4]
 *   @0xd3f88 ldrne r12, [r3, #0x1a8]
 *   @0xd3f8c strne r1, [r12]
 *   @0xd3f90 ldr r1, [pc, #0x34]
 *   @0xd3f94 str r4, [r3, #0x1ac]
 *   @0xd3f98 add r1, pc, r1
 *   @0xd3f9c str r2, [r3, #0x1a4]
 *   @0xd3fa0 str r2, [r3, #0x1a8]
 *   @0xd3fa4 ldr r12, [r1, #0x4]
 *   @0xd3fa8 ldr r4, [sp], #4
 *   @0xd3fac cmp r2, r12
 *   @0xd3fb0 strne r1, [r3, #0x1a4]
 *   @0xd3fb4 strne r12, [r3, #0x1a8]
 *   @0xd3fb8 strne r2, [r1, #0x4]
 *   @0xd3fbc strne r2, [r12]
 *   @0xd3fc0 strne r1, [r3, #0x1ac]
 *   @0xd3fc4 bx lr
 *   @0xd3fc8 eorseq r6, r10, r4, asr r2
 *   @0xd3fcc eorseq r6, r10, r12, lsl r2
 *
 * ══ §66/289 Extension_Function_GetId  0xf61c0  size 128  32 条（0xf61c0..0xf6240）
 * @func 0xf61c0 0xf6240  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Extension_Function_GetId(char const*)+0x70 / CExtensionPackage::FunctionFindName(char const*) / CExtensionFunction::GetId()
 * 字段偏移 top8: 0x68×1 / 0x58×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf61c0 push {r4, r5, r6, r7, r8, lr}
 *   @0xf61c4 mov r6, r0
 *   @0xf61c8 ldr r5, [pc, #0x68]
 *   @0xf61cc ldr r5, [pc, r5]
 *   @0xf61d0 ldr r3, [r5]
 *   @0xf61d4 cmp r3, #0
 *   @0xf61d8 ble 0xf6230 <_Z24Extension_Function_GetIdPKc+0x70>
 *   @0xf61dc ldr r7, [pc, #0x58]
 *   @0xf61e0 mvn r8, #0
 *   @0xf61e4 mov r4, #0
 *   @0xf61e8 add r7, pc, r7
 *   @0xf61ec ldr r3, [r7, #0x4]
 *   @0xf61f0 mov r1, r6
 *   @0xf61f4 ldr r0, [r3, r4, lsl #2]
 *   @0xf61f8 add r4, r4, #1
 *   @0xf61fc cmp r0, #0
 *   @0xf6200 beq 0xf621c <_Z24Extension_Function_GetIdPKc+0x5c>
 *   @0xf6204 bl 0xf5494 <_ZN17CExtensionPackage16FunctionFindNameEPKc>
 *   @0xf6208 cmp r0, #0
 *   @0xf620c beq 0xf621c <_Z24Extension_Function_GetIdPKc+0x5c>
 *   @0xf6210 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf6214 subs r8, r0, #0
 *   @0xf6218 bge 0xf6228 <_Z24Extension_Function_GetIdPKc+0x68>
 *   @0xf621c ldr r3, [r5]
 *   @0xf6220 cmp r3, r4
 *   @0xf6224 bgt 0xf61ec <_Z24Extension_Function_GetIdPKc+0x2c>
 *   @0xf6228 mov r0, r8
 *   @0xf622c pop {r4, r5, r6, r7, r8, pc}
 *   @0xf6230 mvn r8, #0
 *   @0xf6234 b 0xf6228 <_Z24Extension_Function_GetIdPKc+0x68>
 *   @0xf6238 eoreq r7, pc, r8, ror #24
 *   @0xf623c eorseq sp, r8, r0, ror #8
 *
 * ══ §67/289 CCameraManager::DestroyCamera  0x16f2cc  size 128  32 条（0x16f2cc..0x16f34c）
 * @func 0x16f2cc 0x16f34c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::FindCameraInList(int) / CCamera::~CCamera() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×2 / 0x14×2 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f2cc push {r3, r4, r5, r6, r7, lr}
 *   @0x16f2d0 mov r5, r0
 *   @0x16f2d4 bl 0x16f234 <_ZN14CCameraManager16FindCameraInListEi>
 *   @0x16f2d8 cmn r0, #1
 *   @0x16f2dc mov r4, r0
 *   @0x16f2e0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x16f2e4 ldr r1, [r5, #0xc]
 *   @0x16f2e8 lsl r7, r0, #2
 *   @0x16f2ec ldr r2, [r5, #0x4]
 *   @0x16f2f0 ldr r6, [r1, r0, lsl #2]
 *   @0x16f2f4 cmp r2, r6
 *   @0x16f2f8 mov r0, r6
 *   @0x16f2fc moveq r3, #0
 *   @0x16f300 streq r3, [r5, #0x4]
 *   @0x16f304 bl 0x16d120 <_ZN7CCameraD2Ev>
 *   @0x16f308 mov r0, r6
 *   @0x16f30c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x16f310 ldr r0, [r5, #0x14]
 *   @0x16f314 sub r0, r0, #1
 *   @0x16f318 str r0, [r5, #0x14]
 *   @0x16f31c cmp r4, r0
 *   @0x16f320 popge {r3, r4, r5, r6, r7, pc}
 *   @0x16f324 mov r3, r7
 *   @0x16f328 ldr r1, [r5, #0xc]
 *   @0x16f32c add r2, r3, #4
 *   @0x16f330 add r4, r4, #1
 *   @0x16f334 cmp r4, r0
 *   @0x16f338 ldr r12, [r1, r2]
 *   @0x16f33c str r12, [r1, r3]
 *   @0x16f340 mov r3, r2
 *   @0x16f344 bne 0x16f328 <_ZN14CCameraManager13DestroyCameraEi+0x5c>
 *   @0x16f348 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §68/289 isTextureBoundAsRenderTarget  0x180884  size 128  32 条（0x180884..0x180904）
 * @func 0x180884 0x180904  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: isTextureBoundAsRenderTarget(Texture*)+0x68
 * 字段偏移 top8: 0x18×1 / 0x5c×1 / 0x4c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180884 cmp r0, #0
 *   @0x180888 bxeq lr
 *   @0x18088c ldr r0, [r0, #0x18]
 *   @0x180890 cmp r0, #0
 *   @0x180894 bxeq lr
 *   @0x180898 ldr r3, [pc, #0x5c]
 *   @0x18089c ldr r3, [pc, r3]
 *   @0x1808a0 ldrb r3, [r3]
 *   @0x1808a4 cmp r3, #0
 *   @0x1808a8 beq 0x1808ec <_Z28isTextureBoundAsRenderTargetP7Texture+0x68>
 *   @0x1808ac ldr r2, [pc, #0x4c]
 *   @0x1808b0 add r2, pc, r2
 *   @0x1808b4 ldr r3, [r2]
 *   @0x1808b8 cmp r3, #0
 *   @0x1808bc blt 0x1808ec <_Z28isTextureBoundAsRenderTargetP7Texture+0x68>
 *   @0x1808c0 rsb r1, r3, r3, lsl #3
 *   @0x1808c4 add r2, r2, #4
 *   @0x1808c8 mov r3, #0
 *   @0x1808cc add r1, r2, r1, lsl #2
 *   @0x1808d0 add r2, r1, r3
 *   @0x1808d4 add r3, r3, #4
 *   @0x1808d8 ldr r2, [r2, #0x4]
 *   @0x1808dc cmp r0, r2
 *   @0x1808e0 beq 0x1808f4 <_Z28isTextureBoundAsRenderTargetP7Texture+0x70>
 *   @0x1808e4 cmp r3, #16
 *   @0x1808e8 bne 0x1808d0 <_Z28isTextureBoundAsRenderTargetP7Texture+0x4c>
 *   @0x1808ec mov r0, #0
 *   @0x1808f0 bx lr
 *   @0x1808f4 mov r0, #1
 *   @0x1808f8 bx lr
 *   @0x1808fc mlaeq r6, r8, r12, pc
 *   @0x180900 eorseq r1, r2, r12, asr #22
 *
 * ══ §69/289 YYObjectBase::Add  0x1998e0  size 128  32 条（0x1998e0..0x199960）
 * @func 0x1998e0 0x199960  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1998e0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1998e4 mov r4, r1
 *   @0x1998e8 mov r5, r2
 *   @0x1998ec mov r6, r3
 *   @0x1998f0 mov r7, r0
 *   @0x1998f4 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x1998f8 cmp r0, #0
 *   @0x1998fc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x199900 mov r1, r4
 *   @0x199904 mov r0, r7
 *   @0x199908 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x19990c ldr r3, [r0, #0xc]
 *   @0x199910 mov r4, r0
 *   @0x199914 sub r3, r3, #1
 *   @0x199918 bic r3, r3, #-16777216
 *   @0x19991c bic r3, r3, #3
 *   @0x199920 cmp r3, #0
 *   @0x199924 beq 0x199958 <_ZN12YYObjectBase3AddEPKcbi+0x78>
 *   @0x199928 cmp r5, #0
 *   @0x19992c mov r3, #0
 *   @0x199930 str r3, [r4]
 *   @0x199934 movne r5, r3
 *   @0x199938 moveq r2, r5
 *   @0x19993c movne r2, r5
 *   @0x199940 mov r3, #13
 *   @0x199944 movtne r2, #0x3ff0
 *   @0x199948 str r5, [r4]
 *   @0x19994c stmib r4, {r2, r6}
 *   @0x199950 str r3, [r4, #0xc]
 *   @0x199954 pop {r3, r4, r5, r6, r7, pc}
 *   @0x199958 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x19995c b 0x199928 <_ZN12YYObjectBase3AddEPKcbi+0x48>
 *
 * ══ §70/289 CObjectGM::Compile  0x19d9f4  size 128  32 条（0x19d9f4..0x19da74）
 * @func 0x19d9f4 0x19da74  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::Compile()+0x60 / CEvent::Compile()
 * 字段偏移 top8: 0x4c×2 / 0x50×2 / 0x68×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d9f4 push {r4, r5, r6, r7, r8, lr}
 *   @0x19d9f8 mov r5, r0
 *   @0x19d9fc ldr r8, [pc, #0x68]
 *   @0x19da00 mov r7, #0
 *   @0x19da04 ldr r8, [pc, r8]
 *   @0x19da08 ldr r2, [r5, #0x4c]
 *   @0x19da0c str r7, [r8]
 *   @0x19da10 cmp r2, #0
 *   @0x19da14 ble 0x19da54 <_ZN9CObjectGM7CompileEv+0x60>
 *   @0x19da18 ldr r6, [pc, #0x50]
 *   @0x19da1c mov r4, #0
 *   @0x19da20 ldr r6, [pc, r6]
 *   @0x19da24 ldr r3, [r5, #0x50]
 *   @0x19da28 str r4, [r6]
 *   @0x19da2c ldr r0, [r3, r4, lsl #2]
 *   @0x19da30 cmp r0, #0
 *   @0x19da34 beq 0x19da48 <_ZN9CObjectGM7CompileEv+0x54>
 *   @0x19da38 bl 0xf2e10 <_ZN6CEvent7CompileEv>
 *   @0x19da3c cmp r0, #0
 *   @0x19da40 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x19da44 ldr r2, [r5, #0x4c]
 *   @0x19da48 add r4, r4, #1
 *   @0x19da4c cmp r2, r4
 *   @0x19da50 bgt 0x19da24 <_ZN9CObjectGM7CompileEv+0x30>
 *   @0x19da54 add r7, r7, #1
 *   @0x19da58 add r5, r5, #8
 *   @0x19da5c cmp r7, #15
 *   @0x19da60 bne 0x19da08 <_ZN9CObjectGM7CompileEv+0x14>
 *   @0x19da64 mov r0, #1
 *   @0x19da68 pop {r4, r5, r6, r7, r8, pc}
 *   @0x19da6c eoreq r0, r5, r12, lsr #7
 *   @0x19da70 mlaeq r5, r4, r3, r0
 *
 * ══ §71/289 CObjectGM::GetEventDirect  0x19da74  size 128  32 条（0x19da74..0x19daf4）
 * @func 0x19da74 0x19daf4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool) / CObjectGM::GetEventDirect(int, int)+0x34
 * 字段偏移 top8: 0x4c×2 / 0x50×1 / 0x2×1 / 0x8×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19da74 cmp r1, #14
 *   @0x19da78 push {r4, r5, r6, lr}
 *   @0x19da7c movls r3, #0
 *   @0x19da80 movhi r3, #1
 *   @0x19da84 mov r5, r1
 *   @0x19da88 orrs r3, r3, r2, lsr #31
 *   @0x19da8c mov r4, r2
 *   @0x19da90 mov r6, r0
 *   @0x19da94 bne 0x19dac8 <_ZN9CObjectGM14GetEventDirectEii+0x54>
 *   @0x19da98 add r5, r6, r5, lsl #3
 *   @0x19da9c ldr r3, [r5, #0x4c]
 *   @0x19daa0 cmp r4, r3
 *   @0x19daa4 bge 0x19dae8 <_ZN9CObjectGM14GetEventDirectEii+0x74>
 *   @0x19daa8 ldr r3, [r5, #0x50]
 *   @0x19daac ldr r0, [r3, r4, lsl #2]
 *   @0x19dab0 cmp r0, #0
 *   @0x19dab4 popeq {r4, r5, r6, pc}
 *   @0x19dab8 ldr r3, [r0, #0x8]
 *   @0x19dabc cmp r3, #0
 *   @0x19dac0 moveq r0, #0
 *   @0x19dac4 pop {r4, r5, r6, pc}
 *   @0x19dac8 ldr r0, [pc, #0x20]
 *   @0x19dacc add r5, r6, r5, lsl #3
 *   @0x19dad0 mov r1, #1
 *   @0x19dad4 add r0, pc, r0
 *   @0x19dad8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x19dadc ldr r3, [r5, #0x4c]
 *   @0x19dae0 cmp r4, r3
 *   @0x19dae4 blt 0x19daa8 <_ZN9CObjectGM14GetEventDirectEii+0x34>
 *   @0x19dae8 mov r0, #0
 *   @0x19daec pop {r4, r5, r6, pc}
 *   @0x19daf0 andseq pc, r10, r4, asr #6
 *
 * ══ §72/289 CGestureEvent::~CGestureEvent  0x1db510  size 128  32 条（0x1db510..0x1db590）
 * @func 0x1db510 0x1db590  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::DS_AutoMutex() / CDS_Map::~CDS_Map() / operator delete(void*) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x4×5 / 0x58×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1db510 ldr r3, [r0, #0x4]
 *   @0x1db514 push {r4, r5, r6, r7, lr}
 *   @0x1db518 cmn r3, #1
 *   @0x1db51c sub sp, sp, #12
 *   @0x1db520 mov r4, r0
 *   @0x1db524 beq 0x1db580 <_ZN13CGestureEventD2Ev+0x70>
 *   @0x1db528 add r7, sp, #4
 *   @0x1db52c ldr r5, [pc, #0x58]
 *   @0x1db530 mov r0, r7
 *   @0x1db534 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x1db538 ldr r5, [pc, r5]
 *   @0x1db53c ldr r2, [r4, #0x4]
 *   @0x1db540 ldr r3, [r5, #0x4]
 *   @0x1db544 add r1, r3, r2, lsl #2
 *   @0x1db548 ldr r6, [r3, r2, lsl #2]
 *   @0x1db54c cmp r6, #0
 *   @0x1db550 beq 0x1db570 <_ZN13CGestureEventD2Ev+0x60>
 *   @0x1db554 mov r0, r6
 *   @0x1db558 bl 0x20d9e8 <_ZN7CDS_MapD2Ev>
 *   @0x1db55c mov r0, r6
 *   @0x1db560 bl 0x27d1d0 <_ZdlPv>
 *   @0x1db564 ldr r1, [r4, #0x4]
 *   @0x1db568 ldr r3, [r5, #0x4]
 *   @0x1db56c add r1, r3, r1, lsl #2
 *   @0x1db570 mov r3, #0
 *   @0x1db574 mov r0, r7
 *   @0x1db578 str r3, [r1]
 *   @0x1db57c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1db580 mov r0, r4
 *   @0x1db584 add sp, sp, #12
 *   @0x1db588 pop {r4, r5, r6, r7, pc}
 *   @0x1db58c eoreq r2, r1, r4, lsl #8
 *
 * ══ §73/289 ExtractFilePath  0x214f5c  size 128  32 条（0x214f5c..0x214fdc）
 * @func 0x214f5c 0x214fdc  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_strrchr / ExtractFilePath(char const*)+0x68 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6568
 * 字段偏移 top8: 0x48×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214f5c push {r4, r5, r6, lr}
 *   @0x214f60 mov r1, #92
 *   @0x214f64 mov r2, #47
 *   @0x214f68 mov r5, r0
 *   @0x214f6c bl 0x10fbbc <utf8_strrchr>
 *   @0x214f70 cmp r0, #0
 *   @0x214f74 beq 0x214fc4 <_Z15ExtractFilePathPKc+0x68>
 *   @0x214f78 rsb r4, r5, r0
 *   @0x214f7c cmp r4, #0
 *   @0x214f80 ble 0x214fc4 <_Z15ExtractFilePathPKc+0x68>
 *   @0x214f84 ldr r1, [pc, #0x48]
 *   @0x214f88 mov r3, #1
 *   @0x214f8c mov r2, #70
 *   @0x214f90 add r0, r4, #1
 *   @0x214f94 add r1, pc, r1
 *   @0x214f98 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x214f9c mov r1, r5
 *   @0x214fa0 mov r2, r4
 *   @0x214fa4 mov r6, r0
 *   @0x214fa8 bl 0xb6568 <strncpy@plt>
 *   @0x214fac cmp r6, #0
 *   @0x214fb0 mov r3, #0
 *   @0x214fb4 strb r3, [r6, r4]
 *   @0x214fb8 beq 0x214fc4 <_Z15ExtractFilePathPKc+0x68>
 *   @0x214fbc mov r0, r6
 *   @0x214fc0 pop {r4, r5, r6, pc}
 *   @0x214fc4 ldr r0, [pc, #0xc]
 *   @0x214fc8 pop {r4, r5, r6, lr}
 *   @0x214fcc add r0, pc, r0
 *   @0x214fd0 b 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x214fd4 mulseq r1, r12, r0
 *   @0x214fd8 andseq r9, r1, r10, ror #22
 *
 * ══ §74/289 SOggChannel::SOggChannel  0x2233f4  size 128  32 条（0x2233f4..0x223474）
 * @func 0x2233f4 0x223474  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x2b8×1 / 0x2f8×1 / 0x298×1 / 0x2bc×1 / 0x2c0×1 / 0x2c4×1 / 0x2d5×1 / 0x2ec×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2233f4 push {r4, lr}
 *   @0x2233f8 mov r1, #0
 *   @0x2233fc mov r2, #664
 *   @0x223400 mov r4, r0
 *   @0x223404 bl 0xb65b0 <memset@plt>
 *   @0x223408 mov r0, #752
 *   @0x22340c mov r12, #1065353216
 *   @0x223410 mvn r3, #0
 *   @0x223414 mov r1, #3
 *   @0x223418 str r3, [r4, #0x2b8]
 *   @0x22341c str r1, [r4, #0x2f8]
 *   @0x223420 mvn r2, #0
 *   @0x223424 mov r1, #0
 *   @0x223428 mvn r3, #-2147483648
 *   @0x22342c strd r2, r3, [r4, r0]
 *   @0x223430 mov r0, r4
 *   @0x223434 str r1, [r4, #0x298]
 *   @0x223438 str r1, [r4, #0x2bc]
 *   @0x22343c str r1, [r4, #0x2c0]
 *   @0x223440 str r1, [r4, #0x2c4]
 *   @0x223444 strb r1, [r4, #0x2d5]
 *   @0x223448 str r12, [r4, #0x2ec]
 *   @0x22344c strb r1, [r4, #0x2d6]
 *   @0x223450 str r1, [r4, #0x2d8]
 *   @0x223454 strb r1, [r4, #0x2d4]
 *   @0x223458 str r1, [r4, #0x2e0]
 *   @0x22345c strb r1, [r4, #0x2fc]
 *   @0x223460 str r1, [r4, #0x2a8]
 *   @0x223464 str r1, [r4, #0x29c]
 *   @0x223468 str r1, [r4, #0x2a0]
 *   @0x22346c str r1, [r4, #0x2a4]
 *   @0x223470 pop {r4, pc}
 *
 * ══ §75/289 CPhysicsFixture::CPhysicsFixture  0x236454  size 128  32 条（0x236454..0x2364d4）
 * @func 0x236454 0x2364d4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)
 * 字段偏移 top8: 0x1c×2 / 0x4×2 / 0x18×2 / 0x8×2 / 0xc×2 / 0x20×2 / 0x10×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236454 push {r3, r4, r5, r6, r7, lr}
 *   @0x236458 mov r5, #0
 *   @0x23645c mov r4, r0
 *   @0x236460 mov r6, #0
 *   @0x236464 str r1, [r0, #0x1c]
 *   @0x236468 mov r7, #1
 *   @0x23646c str r6, [r0]
 *   @0x236470 str r6, [r0, #0x4]
 *   @0x236474 strb r5, [r0, #0x18]
 *   @0x236478 strb r7, [r0, #0x8]
 *   @0x23647c mov r0, #36
 *   @0x236480 bl 0x27c524 <_Znwj>
 *   @0x236484 movw r2, #0xffff
 *   @0x236488 movw r1, #0xcccd
 *   @0x23648c movt r1, #0x3e4c
 *   @0x236490 str r7, [r0, #0x18]
 *   @0x236494 mov r3, r0
 *   @0x236498 str r6, [r0, #0xc]
 *   @0x23649c strh r5, [r0, #32]
 *   @0x2364a0 str r6, [r0, #0x10]
 *   @0x2364a4 str r5, [r0]
 *   @0x2364a8 str r5, [r0, #0x4]
 *   @0x2364ac strb r5, [r0, #0x14]
 *   @0x2364b0 str r1, [r0, #0x8]
 *   @0x2364b4 str r2, [r0, #0x1c]
 *   @0x2364b8 mov r0, r4
 *   @0x2364bc str r3, [r4, #0x20]
 *   @0x2364c0 strb r5, [r4, #0x19]
 *   @0x2364c4 str r5, [r4, #0xc]
 *   @0x2364c8 str r5, [r4, #0x10]
 *   @0x2364cc str r5, [r4, #0x14]
 *   @0x2364d0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §76/289 trailz_D2A  0x23dc44  size 128  32 条（0x23dc44..0x23dcc4）
 * @func 0x23dc44 0x23dcc4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lo0bits_D2A
 * 字段偏移 top8: 0x10×1 / 0x14×1 / 0x4×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23dc44 ldr r1, [r0, #0x10]
 *   @0x23dc48 add r3, r0, #20
 *   @0x23dc4c push {r4, lr}
 *   @0x23dc50 sub sp, sp, #8
 *   @0x23dc54 add r1, r3, r1, lsl #2
 *   @0x23dc58 cmp r3, r1
 *   @0x23dc5c bhs 0x23dcbc <trailz_D2A+0x78>
 *   @0x23dc60 ldr r4, [r0, #0x14]
 *   @0x23dc64 cmp r4, #0
 *   @0x23dc68 bne 0x23dc98 <trailz_D2A+0x54>
 *   @0x23dc6c add r3, r0, #24
 *   @0x23dc70 b 0x23dc80 <trailz_D2A+0x3c>
 *   @0x23dc74 ldr r2, [r3], #4
 *   @0x23dc78 cmp r2, #0
 *   @0x23dc7c bne 0x23dca0 <trailz_D2A+0x5c>
 *   @0x23dc80 cmp r1, r3
 *   @0x23dc84 add r4, r4, #32
 *   @0x23dc88 bhi 0x23dc74 <trailz_D2A+0x30>
 *   @0x23dc8c mov r0, r4
 *   @0x23dc90 add sp, sp, #8
 *   @0x23dc94 pop {r4, pc}
 *   @0x23dc98 mov r2, r4
 *   @0x23dc9c mov r4, #0
 *   @0x23dca0 add r0, sp, #8
 *   @0x23dca4 str r2, [r0, #-0x4]!
 *   @0x23dca8 bl 0x23d2d4 <lo0bits_D2A>
 *   @0x23dcac add r4, r4, r0
 *   @0x23dcb0 mov r0, r4
 *   @0x23dcb4 add sp, sp, #8
 *   @0x23dcb8 pop {r4, pc}
 *   @0x23dcbc mov r4, #0
 *   @0x23dcc0 b 0x23dc8c <trailz_D2A+0x48>
 *
 * ══ §77/289 Extension_Call_DLL_Function  0xf6344  size 124  31 条（0xf6344..0xf63c0）
 * @func 0xf6344 0xf63c0  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Extension_Call_DLL_Function(int, int, RValue*, RValue*)+0x40 / DLL_Call(int, int, RValue*, RValue*) / Ext_Call(int, int, RValue*, RValue*)
 * 字段偏移 top8: 0x2×2 / 0x5c×1 / 0x4c×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6344 push {r4, lr}
 *   @0xf6348 subs r4, r0, #0
 *   @0xf634c blt 0xf6384 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_+0x40>
 *   @0xf6350 ldr r12, [pc, #0x5c]
 *   @0xf6354 ldr r12, [pc, r12]
 *   @0xf6358 ldr r12, [r12]
 *   @0xf635c cmp r4, r12
 *   @0xf6360 bgt 0xf6384 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_+0x40>
 *   @0xf6364 ldr r12, [pc, #0x4c]
 *   @0xf6368 ldr r12, [pc, r12]
 *   @0xf636c ldr r12, [r12]
 *   @0xf6370 ldr r12, [r12, r4, lsl #2]
 *   @0xf6374 cmp r12, #0
 *   @0xf6378 beq 0xf638c <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_+0x48>
 *   @0xf637c cmp r12, #2
 *   @0xf6380 beq 0xf63a8 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_+0x64>
 *   @0xf6384 mov r0, #0
 *   @0xf6388 pop {r4, pc}
 *   @0xf638c ldr r0, [pc, #0x28]
 *   @0xf6390 ldr r0, [pc, r0]
 *   @0xf6394 ldr r0, [r0]
 *   @0xf6398 ldr r0, [r0, r4, lsl #2]
 *   @0xf639c bl 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *   @0xf63a0 mov r0, #1
 *   @0xf63a4 pop {r4, pc}
 *   @0xf63a8 bl 0x214a18 <_Z8Ext_CalliiP6RValueS0_>
 *   @0xf63ac mov r0, #1
 *   @0xf63b0 pop {r4, pc}
 *   @0xf63b4 eoreq r7, pc, r4, ror #21
 *   @0xf63b8 .word 0x002f79f0
 *   @0xf63bc eoreq r7, pc, r12, asr #19
 *
 * ══ §78/289 ParticleSystem_Particles_Clear  0x1a40d4  size 124  31 条（0x1a40d4..0x1a4150）
 * @func 0x1a40d4 0x1a4150  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / ParticleSystem_Exists(int) / ParticleSystem_Particles_Clear(int)+0x5c
 * 字段偏移 top8: 0x4×5 / 0x2×3 / 0x5c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a40d4 push {r4, r5, r6, lr}
 *   @0x1a40d8 mov r4, r0
 *   @0x1a40dc bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a40e0 cmp r0, #0
 *   @0x1a40e4 popeq {r4, r5, r6, pc}
 *   @0x1a40e8 ldr r3, [pc, #0x5c]
 *   @0x1a40ec ldr r3, [pc, r3]
 *   @0x1a40f0 ldr r3, [r3, #0x4]
 *   @0x1a40f4 ldr r5, [r3, r4, lsl #2]
 *   @0x1a40f8 ldr r3, [r5]
 *   @0x1a40fc cmp r3, #0
 *   @0x1a4100 movgt r4, #0
 *   @0x1a4104 movgt r6, r4
 *   @0x1a4108 ble 0x1a4130 <_Z30ParticleSystem_Particles_Cleari+0x5c>
 *   @0x1a410c ldr r3, [r5, #0x4]
 *   @0x1a4110 ldr r0, [r3, r4, lsl #2]
 *   @0x1a4114 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a4118 ldr r2, [r5, #0x4]
 *   @0x1a411c ldr r3, [r5]
 *   @0x1a4120 str r6, [r2, r4, lsl #2]
 *   @0x1a4124 add r4, r4, #1
 *   @0x1a4128 cmp r3, r4
 *   @0x1a412c bgt 0x1a410c <_Z30ParticleSystem_Particles_Cleari+0x38>
 *   @0x1a4130 ldr r0, [r5, #0x4]
 *   @0x1a4134 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a4138 mov r3, #0
 *   @0x1a413c str r3, [r5, #0x4]
 *   @0x1a4140 str r3, [r5]
 *   @0x1a4144 str r3, [r5, #0x8]
 *   @0x1a4148 pop {r4, r5, r6, pc}
 *   @0x1a414c eoreq r12, r4, r12, asr #13
 *
 * ══ §79/289 CLayerManager::AddNewElementAtDepth  0x1c6c78  size 124  31 条（0x1c6c78..0x1c6cf4）
 * @func 0x1c6c78 0x1c6cf4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetLayerWithDepth(CRoom*, int, bool) / CLayerManager::AddDynamicLayer(CRoom*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c6c78 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c6c7c subs r6, r0, #0
 *   @0x1c6c80 mov r5, r2
 *   @0x1c6c84 mov r7, r3
 *   @0x1c6c88 mov r8, r1
 *   @0x1c6c8c ldrb r4, [sp, #0x18]
 *   @0x1c6c90 beq 0x1c6cec <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x74>
 *   @0x1c6c94 cmp r2, #0
 *   @0x1c6c98 beq 0x1c6cec <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x74>
 *   @0x1c6c9c mov r2, r4
 *   @0x1c6ca0 bl 0x1b87f4 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib>
 *   @0x1c6ca4 cmp r0, #0
 *   @0x1c6ca8 movne r4, #0
 *   @0x1c6cac andeq r4, r4, #1
 *   @0x1c6cb0 mov r1, r0
 *   @0x1c6cb4 cmp r4, #0
 *   @0x1c6cb8 bne 0x1c6cd8 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x60>
 *   @0x1c6cbc cmp r1, #0
 *   @0x1c6cc0 beq 0x1c6cec <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x74>
 *   @0x1c6cc4 mov r0, r6
 *   @0x1c6cc8 mov r2, r5
 *   @0x1c6ccc mov r3, r7
 *   @0x1c6cd0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c6cd4 b 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1c6cd8 mov r1, r8
 *   @0x1c6cdc mov r0, r6
 *   @0x1c6ce0 bl 0x1c33e4 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi>
 *   @0x1c6ce4 mov r1, r0
 *   @0x1c6ce8 b 0x1c6cbc <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x44>
 *   @0x1c6cec mvn r0, #0
 *   @0x1c6cf0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §80/289 CTimeLine::FindSmaller  0x1f1d04  size 124  31 条（0x1f1d04..0x1f1d80）
 * @func 0x1f1d04 0x1f1d80  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x14×1 / 0x2×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1d04 vmov d6, r2, r3
 *   @0x1f1d08 ldr r2, [r0, #0x10]
 *   @0x1f1d0c cmp r2, #0
 *   @0x1f1d10 beq 0x1f1d78 <_ZN9CTimeLine11FindSmallerEd+0x74>
 *   @0x1f1d14 ldr r3, [r0, #0x14]
 *   @0x1f1d18 vldr s11, [r3]
 *   @0x1f1d1c vcvt.f64.s32 d7, s11
 *   @0x1f1d20 vcmpe.f64 d7, d6
 *   @0x1f1d24 vmrs APSR_nzcv, fpscr
 *   @0x1f1d28 bgt 0x1f1d78 <_ZN9CTimeLine11FindSmallerEd+0x74>
 *   @0x1f1d2c subs r0, r2, #1
 *   @0x1f1d30 bmi 0x1f1d78 <_ZN9CTimeLine11FindSmallerEd+0x74>
 *   @0x1f1d34 ldr r1, [r3, r0, lsl #2]
 *   @0x1f1d38 lsl r2, r0, #2
 *   @0x1f1d3c vmov s11, r1
 *   @0x1f1d40 vcvt.f64.s32 d7, s11
 *   @0x1f1d44 vcmpe.f64 d6, d7
 *   @0x1f1d48 vmrs APSR_nzcv, fpscr
 *   @0x1f1d4c bxge lr
 *   @0x1f1d50 add r3, r3, r2
 *   @0x1f1d54 b 0x1f1d6c <_ZN9CTimeLine11FindSmallerEd+0x68>
 *   @0x1f1d58 vldmdb r3!, {s14}
 *   @0x1f1d5c vcvt.f64.s32 d7, s14
 *   @0x1f1d60 vcmpe.f64 d6, d7
 *   @0x1f1d64 vmrs APSR_nzcv, fpscr
 *   @0x1f1d68 bxge lr
 *   @0x1f1d6c subs r0, r0, #1
 *   @0x1f1d70 bhs 0x1f1d58 <_ZN9CTimeLine11FindSmallerEd+0x54>
 *   @0x1f1d74 bx lr
 *   @0x1f1d78 mvn r0, #0
 *   @0x1f1d7c bx lr
 *
 * ══ §81/289 TimeLine_Prepare  0x1f2c80  size 124  31 条（0x1f2c80..0x1f2cfc）
 * @func 0x1f2c80 0x1f2cfc  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TimeLine_Prepare()+0x68×2 / CTimeLine::Compile()
 * 字段偏移 top8: 0x64×1 / 0x54×1 / 0x4×1 / 0x30×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2c80 push {r3, r4, r5, lr}
 *   @0x1f2c84 ldr r3, [pc, #0x64]
 *   @0x1f2c88 ldr r2, [pc, r3]
 *   @0x1f2c8c ldr r3, [r2]
 *   @0x1f2c90 cmp r3, #0
 *   @0x1f2c94 ble 0x1f2ce8 <_Z16TimeLine_Preparev+0x68>
 *   @0x1f2c98 ldr r5, [pc, #0x54]
 *   @0x1f2c9c mov r4, #0
 *   @0x1f2ca0 add r5, pc, r5
 *   @0x1f2ca4 b 0x1f2cbc <_Z16TimeLine_Preparev+0x3c>
 *   @0x1f2ca8 ldr r2, [r5]
 *   @0x1f2cac add r4, r4, #1
 *   @0x1f2cb0 ldr r3, [r2]
 *   @0x1f2cb4 cmp r3, r4
 *   @0x1f2cb8 ble 0x1f2ce8 <_Z16TimeLine_Preparev+0x68>
 *   @0x1f2cbc ldr r2, [r2, #0x4]
 *   @0x1f2cc0 ldr r3, [pc, #0x30]
 *   @0x1f2cc4 ldr r0, [r2, r4, lsl #2]
 *   @0x1f2cc8 cmp r0, #0
 *   @0x1f2ccc beq 0x1f2ca8 <_Z16TimeLine_Preparev+0x28>
 *   @0x1f2cd0 ldr r3, [pc, r3]
 *   @0x1f2cd4 str r4, [r3]
 *   @0x1f2cd8 bl 0x1f1bb4 <_ZN9CTimeLine7CompileEv>
 *   @0x1f2cdc cmp r0, #0
 *   @0x1f2ce0 bne 0x1f2ca8 <_Z16TimeLine_Preparev+0x28>
 *   @0x1f2ce4 pop {r3, r4, r5, pc}
 *   @0x1f2ce8 mov r0, #1
 *   @0x1f2cec pop {r3, r4, r5, pc}
 *   @0x1f2cf0 subseq r0, r6, r4, ror #8
 *   @0x1f2cf4 subseq r0, r6, r12, asr #8
 *   @0x1f2cf8 andseq r11, pc, r8, ror #1
 *
 * ══ §82/289 CDS_Priority::Mark4GC  0x203e28  size 124  31 条（0x203e28..0x203ea4）
 * @func 0x203e28 0x203ea4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC(RValue const*, unsigned int*, int)×2 / CDS_Priority::Mark4GC(unsigned int*, int)+0x44
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203e28 push {r3, r4, r5, r6, r7, lr}
 *   @0x203e2c mov r4, r0
 *   @0x203e30 ldr r3, [r0, #0x8]
 *   @0x203e34 mov r6, r1
 *   @0x203e38 mov r7, r2
 *   @0x203e3c cmp r3, #0
 *   @0x203e40 movgt r5, #0
 *   @0x203e44 ble 0x203e6c <_ZN12CDS_Priority7Mark4GCEPji+0x44>
 *   @0x203e48 ldr r0, [r4, #0xc]
 *   @0x203e4c mov r1, r6
 *   @0x203e50 mov r2, r7
 *   @0x203e54 add r0, r0, r5, lsl #4
 *   @0x203e58 add r5, r5, #1
 *   @0x203e5c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x203e60 ldr r3, [r4, #0x8]
 *   @0x203e64 cmp r3, r5
 *   @0x203e68 bgt 0x203e48 <_ZN12CDS_Priority7Mark4GCEPji+0x20>
 *   @0x203e6c ldr r3, [r4, #0x10]
 *   @0x203e70 cmp r3, #0
 *   @0x203e74 pople {r3, r4, r5, r6, r7, pc}
 *   @0x203e78 mov r5, #0
 *   @0x203e7c ldr r0, [r4, #0x14]
 *   @0x203e80 mov r1, r6
 *   @0x203e84 mov r2, r7
 *   @0x203e88 add r0, r0, r5, lsl #4
 *   @0x203e8c add r5, r5, #1
 *   @0x203e90 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x203e94 ldr r3, [r4, #0x10]
 *   @0x203e98 cmp r3, r5
 *   @0x203e9c bgt 0x203e7c <_ZN12CDS_Priority7Mark4GCEPji+0x54>
 *   @0x203ea0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §83/289 COggAudio::Init  0x225d18  size 124  31 条（0x225d18..0x225d94）
 * @func 0x225d18 0x225d94  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3 / operator new[](unsigned int) / COggThread::COggThread()
 * 字段偏移 top8: 0x14×1 / 0x18×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225d18 push {r3, r4, r5, r6, r7, lr}
 *   @0x225d1c mov r6, r0
 *   @0x225d20 str r1, [r6, #0x14]
 *   @0x225d24 mov r0, r2
 *   @0x225d28 mov r4, r1
 *   @0x225d2c bl 0x318d10 <__divsi3>
 *   @0x225d30 cmp r4, #1015808
 *   @0x225d34 sub r5, r4, #1
 *   @0x225d38 mul r0, r4, r0
 *   @0x225d3c str r0, [r6, #0x18]
 *   @0x225d40 movwls r0, #0x834
 *   @0x225d44 mulls r0, r0, r4
 *   @0x225d48 mvnhi r0, #0
 *   @0x225d4c addls r0, r0, #8
 *   @0x225d50 bl 0x27d14c <_Znaj>
 *   @0x225d54 cmn r5, #1
 *   @0x225d58 movw r3, #0x834
 *   @0x225d5c add r7, r0, #8
 *   @0x225d60 str r4, [r0, #0x4]
 *   @0x225d64 str r3, [r0]
 *   @0x225d68 movne r4, r7
 *   @0x225d6c beq 0x225d8c <_ZN9COggAudio4InitEii+0x74>
 *   @0x225d70 mov r0, r4
 *   @0x225d74 sub r5, r5, #1
 *   @0x225d78 bl 0x223750 <_ZN10COggThreadC2Ev>
 *   @0x225d7c cmn r5, #1
 *   @0x225d80 add r4, r4, #2096
 *   @0x225d84 add r4, r4, #4
 *   @0x225d88 bne 0x225d70 <_ZN9COggAudio4InitEii+0x58>
 *   @0x225d8c str r7, [r6]
 *   @0x225d90 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §84/289 vorbis_synthesis_pcmout  0x227c80  size 124  31 条（0x227c80..0x227cfc）
 * @func 0x227c80 0x227cfc  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: vorbis_synthesis_pcmout+0x70 / vorbis_synthesis_pcmout+0x5c
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x2×2 / 0x18×1 / 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x227c80 push {r4, r5, r6, r7}
 *   @0x227c84 ldr r6, [r0, #0x18]
 *   @0x227c88 ldr r3, [r0, #0x4]
 *   @0x227c8c cmp r6, #0
 *   @0x227c90 blt 0x227cf0 <vorbis_synthesis_pcmout+0x70>
 *   @0x227c94 ldr r7, [r0, #0x14]
 *   @0x227c98 cmp r6, r7
 *   @0x227c9c bge 0x227cf0 <vorbis_synthesis_pcmout+0x70>
 *   @0x227ca0 cmp r1, #0
 *   @0x227ca4 beq 0x227ce4 <vorbis_synthesis_pcmout+0x64>
 *   @0x227ca8 ldr r4, [r3, #0x4]
 *   @0x227cac cmp r4, #0
 *   @0x227cb0 lslgt r5, r6, #2
 *   @0x227cb4 movgt r3, #0
 *   @0x227cb8 ble 0x227cdc <vorbis_synthesis_pcmout+0x5c>
 *   @0x227cbc ldr r12, [r0, #0x8]
 *   @0x227cc0 ldr r2, [r0, #0xc]
 *   @0x227cc4 ldr r12, [r12, r3, lsl #2]
 *   @0x227cc8 add r12, r12, r5
 *   @0x227ccc str r12, [r2, r3, lsl #2]
 *   @0x227cd0 add r3, r3, #1
 *   @0x227cd4 cmp r3, r4
 *   @0x227cd8 bne 0x227cbc <vorbis_synthesis_pcmout+0x3c>
 *   @0x227cdc ldr r3, [r0, #0xc]
 *   @0x227ce0 str r3, [r1]
 *   @0x227ce4 rsb r0, r6, r7
 *   @0x227ce8 pop {r4, r5, r6, r7}
 *   @0x227cec bx lr
 *   @0x227cf0 mov r0, #0
 *   @0x227cf4 pop {r4, r5, r6, r7}
 *   @0x227cf8 bx lr
 *
 * ══ §85/289 anon_22ea70  0x22ea70  size 124  31 条（0x22ea70..0x22eaec）
 * @func 0x22ea70 0x22eaec  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22ea70 rev r0, r0
 *   @0x22ea74 movw r2, #0xf0f
 *   @0x22ea78 movw r3, #0xf0f0
 *   @0x22ea7c bfi r2, r2, #16, #16
 *   @0x22ea80 bfi r3, r3, #16, #16
 *   @0x22ea84 and r2, r2, r0, lsr #4
 *   @0x22ea88 and r0, r3, r0, lsl #4
 *   @0x22ea8c movw r3, #0x3333
 *   @0x22ea90 orr r0, r0, r2
 *   @0x22ea94 bfi r3, r3, #16, #16
 *   @0x22ea98 movw r2, #0xcccc
 *   @0x22ea9c bfi r2, r2, #16, #16
 *   @0x22eaa0 and r3, r3, r0, lsr #2
 *   @0x22eaa4 and r2, r2, r0, lsl #2
 *   @0x22eaa8 orr r1, r2, r3
 *   @0x22eaac movw r2, #0xaaaa
 *   @0x22eab0 movw r3, #0x5555
 *   @0x22eab4 bfi r2, r2, #16, #16
 *   @0x22eab8 bfi r3, r3, #16, #16
 *   @0x22eabc and r2, r2, r1, lsl #1
 *   @0x22eac0 and r0, r3, r1, lsr #1
 *   @0x22eac4 orr r0, r2, r0
 *   @0x22eac8 bx lr
 *   @0x22eacc ldr r3, [r0]
 *   @0x22ead0 ldr r1, [r1]
 *   @0x22ead4 ldr r2, [r3]
 *   @0x22ead8 ldr r3, [r1]
 *   @0x22eadc cmp r2, r3
 *   @0x22eae0 movls r0, #0
 *   @0x22eae4 movhi r0, #1
 *   @0x22eae8 sublo r0, r0, #1
 *
 * ══ §86/289 JS_IsCallable  0x24076c  size 124  31 条（0x24076c..0x2407e8）
 * @func 0x24076c 0x2407e8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_IsCallable(RValue&)+0x30 / JS_IsCallable(RValue&)+0x44 / YYError(char const*, ...)
 * 字段偏移 top8: 0xc×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24076c ldr r1, [r0, #0xc]
 *   @0x240770 push {r3, lr}
 *   @0x240774 bic r1, r1, #-16777216
 *   @0x240778 cmp r1, #7
 *   @0x24077c beq 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44>
 *   @0x240780 bgt 0x2407b8 <_Z13JS_IsCallableR6RValue+0x4c>
 *   @0x240784 cmp r1, #5
 *   @0x240788 beq 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44>
 *   @0x24078c ble 0x24079c <_Z13JS_IsCallableR6RValue+0x30>
 *   @0x240790 ldr r0, [r0]
 *   @0x240794 pop {r3, lr}
 *   @0x240798 b 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase>
 *   @0x24079c cmp r1, #1
 *   @0x2407a0 bls 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44>
 *   @0x2407a4 ldr r0, [pc, #0x38]
 *   @0x2407a8 add r0, pc, r0
 *   @0x2407ac bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x2407b0 mov r0, #0
 *   @0x2407b4 pop {r3, pc}
 *   @0x2407b8 cmp r1, #13
 *   @0x2407bc bgt 0x2407d4 <_Z13JS_IsCallableR6RValue+0x68>
 *   @0x2407c0 cmp r1, #12
 *   @0x2407c4 bge 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44>
 *   @0x2407c8 cmp r1, #10
 *   @0x2407cc bne 0x2407a4 <_Z13JS_IsCallableR6RValue+0x38>
 *   @0x2407d0 b 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44>
 *   @0x2407d4 mvn r3, #-16777216
 *   @0x2407d8 cmp r1, r3
 *   @0x2407dc bne 0x2407a4 <_Z13JS_IsCallableR6RValue+0x38>
 *   @0x2407e0 b 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44>
 *   @0x2407e4 andseq r4, r1, r8, lsl #27
 *
 * ══ §87/289 b2DynamicTree::CreateProxy  0x2df46c  size 124  31 条（0x2df46c..0x2df4e8）
 * @func 0x2df46c 0x2df4e8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::AllocateNode() / b2DynamicTree::InsertLeaf(int)
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x20×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df46c push {r3, r4, r5, r6, r7, lr}
 *   @0x2df470 mov r4, r1
 *   @0x2df474 mov r7, r2
 *   @0x2df478 mov r6, r0
 *   @0x2df47c bl 0x2de9bc <_ZN13b2DynamicTree12AllocateNodeEv>
 *   @0x2df480 vldr s14, [r4, #4]
 *   @0x2df484 vldr s13, [r4]
 *   @0x2df488 vldr s15, [pc, #84]
 *   @0x2df48c vsub.f32 s13, s13, s15
 *   @0x2df490 ldr r3, [r6, #0x4]
 *   @0x2df494 mov r2, #0
 *   @0x2df498 vsub.f32 s14, s14, s15
 *   @0x2df49c mov r5, r0
 *   @0x2df4a0 mov r0, r6
 *   @0x2df4a4 add r12, r5, r5, lsl #3
 *   @0x2df4a8 mov r1, r5
 *   @0x2df4ac add r3, r3, r12, lsl #2
 *   @0x2df4b0 vstr s13, [r3]
 *   @0x2df4b4 vstr s14, [r3, #4]
 *   @0x2df4b8 vldr s14, [r4, #12]
 *   @0x2df4bc vldr s13, [r4, #8]
 *   @0x2df4c0 vadd.f32 s14, s14, s15
 *   @0x2df4c4 str r7, [r3, #0x10]
 *   @0x2df4c8 str r2, [r3, #0x20]
 *   @0x2df4cc vadd.f32 s15, s13, s15
 *   @0x2df4d0 vstr s14, [r3, #12]
 *   @0x2df4d4 vstr s15, [r3, #8]
 *   @0x2df4d8 bl 0x2defd0 <_ZN13b2DynamicTree10InsertLeafEi>
 *   @0x2df4dc mov r0, r5
 *   @0x2df4e0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2df4e4 stcllo p12, c12, [r12, #820]
 *
 * ══ §88/289 Code_Function_GET_the_function  0xcdf0c  size 120  30 条（0xcdf0c..0xcdf84）
 * @func 0xcdf0c 0xcdf84  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Function_GET_the_function(int, char const**, void**, int*, int*)+0x68×2
 * 字段偏移 top8: 0x4×2 / 0x68×1 / 0x-4×1 / 0x4c×1 / 0x40×1 / 0x44×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcdf0c ldr r12, [pc, #0x68]
 *   @0xcdf10 str r4, [sp, #-0x4]!
 *   @0xcdf14 ldr r12, [pc, r12]
 *   @0xcdf18 ldr r12, [r12]
 *   @0xcdf1c cmp r12, r0
 *   @0xcdf20 blt 0xcdf74 <_Z30Code_Function_GET_the_functioniPPKcPPvPiS4_+0x68>
 *   @0xcdf24 cmp r0, #0
 *   @0xcdf28 blt 0xcdf74 <_Z30Code_Function_GET_the_functioniPPKcPPvPiS4_+0x68>
 *   @0xcdf2c ldr r12, [pc, #0x4c]
 *   @0xcdf30 add r0, r0, r0, lsl #2
 *   @0xcdf34 ldr r12, [pc, r12]
 *   @0xcdf38 lsl r0, r0, #4
 *   @0xcdf3c ldr r4, [r12]
 *   @0xcdf40 add r4, r4, r0
 *   @0xcdf44 str r4, [r1]
 *   @0xcdf48 ldr r1, [r12]
 *   @0xcdf4c add r1, r1, r0
 *   @0xcdf50 ldr r1, [r1, #0x40]
 *   @0xcdf54 str r1, [r2]
 *   @0xcdf58 ldr r2, [r12]
 *   @0xcdf5c add r0, r2, r0
 *   @0xcdf60 ldr r1, [r0, #0x44]
 *   @0xcdf64 ldrb r2, [r0, #0x48]
 *   @0xcdf68 str r1, [r3]
 *   @0xcdf6c ldr r3, [sp, #0x4]
 *   @0xcdf70 str r2, [r3]
 *   @0xcdf74 ldr r4, [sp], #4
 *   @0xcdf78 bx lr
 *   @0xcdf7c eorseq pc, r1, r0, lsl #24
 *   @0xcdf80 eorseq pc, r1, r4, ror #23
 *
 * ══ §89/289 Code_Execute_Special  0xd05d4  size 120  30 条（0xd05d4..0xd064c）
 * @func 0xd05d4 0xd064c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExecuteIt(CInstance*, CInstance*, CCode*, RValue*, int) / YYCreateString(RValue*, char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x34×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd05d4 push {r4, r5, lr}
 *   @0xd05d8 sub sp, sp, #12
 *   @0xd05dc mov r4, r3
 *   @0xd05e0 ldr r12, [sp, #0x18]
 *   @0xd05e4 str r12, [sp]
 *   @0xd05e8 bl 0xcf914 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei>
 *   @0xd05ec subs r5, r0, #0
 *   @0xd05f0 bne 0xd0630 <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei+0x5c>
 *   @0xd05f4 ldr r3, [r4, #0xc]
 *   @0xd05f8 sub r3, r3, #1
 *   @0xd05fc bic r3, r3, #-16777216
 *   @0xd0600 bic r3, r3, #3
 *   @0xd0604 cmp r3, #0
 *   @0xd0608 beq 0xd063c <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei+0x68>
 *   @0xd060c ldr r1, [pc, #0x34]
 *   @0xd0610 mov r3, #0
 *   @0xd0614 mov r2, #5
 *   @0xd0618 str r3, [r4, #0x8]
 *   @0xd061c mov r0, r4
 *   @0xd0620 str r3, [r4]
 *   @0xd0624 str r2, [r4, #0xc]
 *   @0xd0628 add r1, pc, r1
 *   @0xd062c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xd0630 mov r0, r5
 *   @0xd0634 add sp, sp, #12
 *   @0xd0638 pop {r4, r5, pc}
 *   @0xd063c mov r0, r4
 *   @0xd0640 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xd0644 b 0xd060c <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei+0x38>
 *   @0xd0648 eoreq r1, r6, r4, ror #30
 *
 * ══ §90/289 YYObjectBase::Add  0x199aa8  size 120  30 条（0x199aa8..0x199b20）
 * @func 0x199aa8 0x199b20  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / YYSetString(RValue*, char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199aa8 push {r3, r4, r5, r6, r7, lr}
 *   @0x199aac mov r4, r1
 *   @0x199ab0 mov r6, r2
 *   @0x199ab4 mov r5, r3
 *   @0x199ab8 mov r7, r0
 *   @0x199abc bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x199ac0 cmp r0, #0
 *   @0x199ac4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x199ac8 mov r1, r4
 *   @0x199acc mov r0, r7
 *   @0x199ad0 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x199ad4 ldr r3, [r0, #0xc]
 *   @0x199ad8 mov r4, r0
 *   @0x199adc sub r3, r3, #1
 *   @0x199ae0 bic r3, r3, #-16777216
 *   @0x199ae4 bic r3, r3, #3
 *   @0x199ae8 cmp r3, #0
 *   @0x199aec beq 0x199b18 <_ZN12YYObjectBase3AddEPKcS1_i+0x70>
 *   @0x199af0 mov r3, #0
 *   @0x199af4 mov r2, #5
 *   @0x199af8 mov r1, r6
 *   @0x199afc str r3, [r4, #0x8]
 *   @0x199b00 str r3, [r4]
 *   @0x199b04 mov r0, r4
 *   @0x199b08 str r2, [r4, #0xc]
 *   @0x199b0c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x199b10 str r5, [r4, #0x8]
 *   @0x199b14 pop {r3, r4, r5, r6, r7, pc}
 *   @0x199b18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x199b1c b 0x199af0 <_ZN12YYObjectBase3AddEPKcS1_i+0x48>
 *
 * ══ §91/289 CLayerManager::RemoveElement  0x1c013c  size 120  30 条（0x1c013c..0x1c01b4）
 * @func 0x1c013c 0x1c01b4  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / CLayerManager::RemoveElement(CRoom*, CLayer*, CLayerElementBase*, bool) / CLayerManager::RemoveLayer(CRoom*, int, bool)
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x19×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c013c push {r4, r5, r6, lr}
 *   @0x1c0140 subs r4, r0, #0
 *   @0x1c0144 sub sp, sp, #8
 *   @0x1c0148 mov r5, r2
 *   @0x1c014c mov r6, r3
 *   @0x1c0150 beq 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70>
 *   @0x1c0154 add r2, sp, #8
 *   @0x1c0158 mov r3, #0
 *   @0x1c015c str r3, [r2, #-0x4]!
 *   @0x1c0160 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1c0164 subs r2, r0, #0
 *   @0x1c0168 beq 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70>
 *   @0x1c016c mov r3, r6
 *   @0x1c0170 mov r0, r4
 *   @0x1c0174 ldr r1, [sp, #0x4]
 *   @0x1c0178 bl 0x1b8fdc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1c017c cmp r5, #0
 *   @0x1c0180 beq 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70>
 *   @0x1c0184 ldr r3, [sp, #0x4]
 *   @0x1c0188 ldrb r2, [r3, #0x19]
 *   @0x1c018c cmp r2, #0
 *   @0x1c0190 beq 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70>
 *   @0x1c0194 ldr r2, [r3, #0x60]
 *   @0x1c0198 cmp r2, #0
 *   @0x1c019c bne 0x1c01ac <_ZN13CLayerManager13RemoveElementEP5CRoomibb+0x70>
 *   @0x1c01a0 mov r0, r4
 *   @0x1c01a4 ldr r1, [r3]
 *   @0x1c01a8 bl 0x1b95d8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib>
 *   @0x1c01ac add sp, sp, #8
 *   @0x1c01b0 pop {r4, r5, r6, pc}
 *
 * ══ §92/289 RTree<CInstance*, int, float, 6, 2>::Remove  0x1cd978  size 120  30 条（0x1cd978..0x1cd9f0）
 * @func 0x1cd978 0x1cd9f0  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::RemoveRect(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node**)×2 / anon_1cbc10+0x50
 * 字段偏移 top8: 0x4×2 / 0x40×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cd978 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1cd97c add r5, r0, #16
 *   @0x1cd980 sub sp, sp, #36
 *   @0x1cd984 ldr r9, [r1]
 *   @0x1cd988 ldr r8, [r1, #0x4]
 *   @0x1cd98c mov r6, r3
 *   @0x1cd990 ldr lr, [r2]
 *   @0x1cd994 mov r3, r5
 *   @0x1cd998 ldr r12, [r2, #0x4]
 *   @0x1cd99c mov r1, sp
 *   @0x1cd9a0 mov r2, r6
 *   @0x1cd9a4 ldrb r7, [sp, #0x40]
 *   @0x1cd9a8 mov r4, r0
 *   @0x1cd9ac str r9, [sp]
 *   @0x1cd9b0 stmib sp, {r8, lr}
 *   @0x1cd9b4 str r12, [sp, #0xc]
 *   @0x1cd9b8 bl 0x1cd87c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE>
 *   @0x1cd9bc tst r0, r7
 *   @0x1cd9c0 beq 0x1cd9e8 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6RemoveEPKiS4_RKS1_b+0x70>
 *   @0x1cd9c4 add r7, sp, #16
 *   @0x1cd9c8 ldr r1, [r4, #0x10]
 *   @0x1cd9cc mov r0, r7
 *   @0x1cd9d0 bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4>
 *   @0x1cd9d4 mov r0, r4
 *   @0x1cd9d8 mov r1, r7
 *   @0x1cd9dc mov r2, r6
 *   @0x1cd9e0 mov r3, r5
 *   @0x1cd9e4 bl 0x1cd87c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE>
 *   @0x1cd9e8 add sp, sp, #36
 *   @0x1cd9ec pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §93/289 checkAL  0x215fd0  size 120  30 条（0x215fd0..0x216048）
 * @func 0x215fd0 0x216048  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a54
 * 字段偏移 top8: 0xc×2 / 0x24×2 / 0x44×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215fd0 push {r4, lr}
 *   @0x215fd4 mov r4, r0
 *   @0x215fd8 bl 0xb6a54 <alGetError@plt>
 *   @0x215fdc subs r2, r0, #0
 *   @0x215fe0 popeq {r4, pc}
 *   @0x215fe4 cmp r4, #0
 *   @0x215fe8 beq 0x216014 <_Z7checkALPKc+0x44>
 *   @0x215fec ldr r12, [pc, #0x44]
 *   @0x215ff0 mov r3, r4
 *   @0x215ff4 ldr r1, [pc, #0x40]
 *   @0x215ff8 ldr r12, [pc, r12]
 *   @0x215ffc add r1, pc, r1
 *   @0x216000 ldr r0, [r12]
 *   @0x216004 ldr r12, [r0]
 *   @0x216008 ldr r12, [r12, #0xc]
 *   @0x21600c blx r12
 *   @0x216010 pop {r4, pc}
 *   @0x216014 ldr r3, [pc, #0x24]
 *   @0x216018 ldr r1, [pc, #0x24]
 *   @0x21601c ldr r3, [pc, r3]
 *   @0x216020 add r1, pc, r1
 *   @0x216024 ldr r0, [r3]
 *   @0x216028 ldr r3, [r0]
 *   @0x21602c ldr r3, [r3, #0xc]
 *   @0x216030 blx r3
 *   @0x216034 pop {r4, pc}
 *   @0x216038 andseq r7, sp, r12, lsl r7
 *   @0x21603c andseq sp, r3, r8, lsl r11
 *   @0x216040 ldrsheq r7, [sp], -r8
 *   @0x216044 andseq sp, r3, r12, lsl #22
 *
 * ══ §94/289 CPhysicsWorld::ApplyVisualOffset  0x2380b4  size 120  30 条（0x2380b4..0x23812c）
 * @func 0x2380b4 0x23812c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb658c / 0xb6580
 * 字段偏移 top8: 无
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2380b4 push {r3, r4, r5, lr}
 *   @0x2380b8 vpush {d8, d9}
 *   @0x2380bc vldr s16, [r2]
 *   @0x2380c0 vcmp.f32 s16, #0
 *   @0x2380c4 mov r4, r3
 *   @0x2380c8 mov r5, r1
 *   @0x2380cc vldr s17, [r2, #4]
 *   @0x2380d0 vmrs APSR_nzcv, fpscr
 *   @0x2380d4 bne 0x2380f4 <_ZN13CPhysicsWorld17ApplyVisualOffsetEfRK6b2Vec2RS0_+0x40>
 *   @0x2380d8 vcmp.f32 s17, #0
 *   @0x2380dc vmrs APSR_nzcv, fpscr
 *   @0x2380e0 vstreq s16, [r3]
 *   @0x2380e4 vstreq s17, [r3, #4]
 *   @0x2380e8 bne 0x2380f4 <_ZN13CPhysicsWorld17ApplyVisualOffsetEfRK6b2Vec2RS0_+0x40>
 *   @0x2380ec vpop {d8, d9}
 *   @0x2380f0 pop {r3, r4, r5, pc}
 *   @0x2380f4 mov r0, r5
 *   @0x2380f8 bl 0xb658c <cosf@plt>
 *   @0x2380fc vmov s18, r0
 *   @0x238100 mov r0, r5
 *   @0x238104 bl 0xb6580 <sinf@plt>
 *   @0x238108 vmov s15, r0
 *   @0x23810c vmul.f32 s14, s15, s17
 *   @0x238110 vmul.f32 s15, s16, s15
 *   @0x238114 vnmls.f32 s14, s16, s18
 *   @0x238118 vmla.f32 s15, s18, s17
 *   @0x23811c vstr s14, [r4]
 *   @0x238120 vpop {d8, d9}
 *   @0x238124 vstr s15, [r4, #4]
 *   @0x238128 pop {r3, r4, r5, pc}
 *
 * ══ §95/289 CalcCRC_string  0x27dfa8  size 120  30 条（0x27dfa8..0x27e020）
 * @func 0x27dfa8 0x27e020  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: InitFastCRC()
 * 字段偏移 top8: 0x68×1 / 0x3c×1 / 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27dfa8 ldr r3, [pc, #0x68]
 *   @0x27dfac push {r4, lr}
 *   @0x27dfb0 ldr r3, [pc, r3]
 *   @0x27dfb4 mov r4, r0
 *   @0x27dfb8 ldrb r3, [r3]
 *   @0x27dfbc cmp r3, #0
 *   @0x27dfc0 beq 0x27e010 <_Z14CalcCRC_stringPKc+0x68>
 *   @0x27dfc4 cmp r4, #0
 *   @0x27dfc8 beq 0x27e008 <_Z14CalcCRC_stringPKc+0x60>
 *   @0x27dfcc ldrb r3, [r4]
 *   @0x27dfd0 cmp r3, #0
 *   @0x27dfd4 beq 0x27e008 <_Z14CalcCRC_stringPKc+0x60>
 *   @0x27dfd8 ldr r12, [pc, #0x3c]
 *   @0x27dfdc mov r2, r4
 *   @0x27dfe0 mvn r0, #0
 *   @0x27dfe4 ldr r12, [pc, r12]
 *   @0x27dfe8 eor r1, r0, r3
 *   @0x27dfec ldrb r3, [r2, #0x1]!
 *   @0x27dff0 uxtb r1, r1
 *   @0x27dff4 cmp r3, #0
 *   @0x27dff8 ldr r1, [r12, r1, lsl #2]
 *   @0x27dffc eor r0, r1, r0, lsr #8
 *   @0x27e000 bne 0x27dfe8 <_Z14CalcCRC_stringPKc+0x40>
 *   @0x27e004 pop {r4, pc}
 *   @0x27e008 mvn r0, #0
 *   @0x27e00c pop {r4, pc}
 *   @0x27e010 bl 0x27de00 <_Z11InitFastCRCv>
 *   @0x27e014 b 0x27dfc4 <_Z14CalcCRC_stringPKc+0x1c>
 *   @0x27e018 ldrsbeq r3, [r7], -r4
 *   @0x27e01c andseq r2, r7, r12, lsr sp
 *
 * ══ §96/289 b2ChainShape::CreateLoop  0x2c4a68  size 120  30 条（0x2c4a68..0x2c4ae0）
 * @func 0x2c4a68 0x2c4ae0  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int) / 0xb65bc
 * 字段偏移 top8: 0x10×2 / 0xc×2 / 0x24×1 / 0x25×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4a68 add r2, r2, #1
 *   @0x2c4a6c push {r4, r5, r6, r7, r8, lr}
 *   @0x2c4a70 mov r4, r0
 *   @0x2c4a74 str r2, [r0, #0x10]
 *   @0x2c4a78 lsl r0, r2, #3
 *   @0x2c4a7c mov r6, r1
 *   @0x2c4a80 sub r5, r0, #8
 *   @0x2c4a84 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2c4a88 mov r1, r6
 *   @0x2c4a8c mov r2, r5
 *   @0x2c4a90 add r7, r4, #20
 *   @0x2c4a94 str r0, [r4, #0xc]
 *   @0x2c4a98 bl 0xb65bc <memcpy@plt>
 *   @0x2c4a9c ldr r3, [r4, #0xc]
 *   @0x2c4aa0 ldr r8, [r4, #0x10]
 *   @0x2c4aa4 add r12, r4, #28
 *   @0x2c4aa8 add r5, r3, r5
 *   @0x2c4aac add r6, r3, #8
 *   @0x2c4ab0 sub r8, r8, #-536870910
 *   @0x2c4ab4 ldm r3, {r0, r1}
 *   @0x2c4ab8 mov r2, #1
 *   @0x2c4abc add r3, r3, r8, lsl #3
 *   @0x2c4ac0 stm r5, {r0, r1}
 *   @0x2c4ac4 ldm r3, {r0, r1}
 *   @0x2c4ac8 stm r7, {r0, r1}
 *   @0x2c4acc ldm r6, {r0, r1}
 *   @0x2c4ad0 stm r12, {r0, r1}
 *   @0x2c4ad4 strb r2, [r4, #0x24]
 *   @0x2c4ad8 strb r2, [r4, #0x25]
 *   @0x2c4adc pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §97/289 CSkeletonInstance::StoreAttachment  0xbf92c  size 116  29 条（0xbf92c..0xbf9a0）
 * @func 0xbf92c 0xbf9a0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2
 * 字段偏移 top8: 0x10×4 / 0x2×2 / 0x58×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbf92c push {r3, r4, r5, r6, r7, lr}
 *   @0xbf930 mov r7, r1
 *   @0xbf934 ldr r3, [r0, #0x10]
 *   @0xbf938 mov r4, r0
 *   @0xbf93c ldr r5, [pc, #0x58]
 *   @0xbf940 mov r6, r2
 *   @0xbf944 add r1, r3, #1
 *   @0xbf948 add r0, r0, #20
 *   @0xbf94c add r5, pc, r5
 *   @0xbf950 movw r3, #0x6d9
 *   @0xbf954 lsl r1, r1, #2
 *   @0xbf958 mov r2, r5
 *   @0xbf95c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xbf960 ldr r1, [r4, #0x10]
 *   @0xbf964 mov r2, r5
 *   @0xbf968 movw r3, #0x6da
 *   @0xbf96c add r1, r1, #1
 *   @0xbf970 add r0, r4, #24
 *   @0xbf974 lsl r1, r1, #2
 *   @0xbf978 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xbf97c ldr r3, [r4, #0x10]
 *   @0xbf980 ldr r1, [r4, #0x14]
 *   @0xbf984 add r2, r3, #1
 *   @0xbf988 str r7, [r1, r3, lsl #2]
 *   @0xbf98c ldr r1, [r4, #0x18]
 *   @0xbf990 str r6, [r1, r3, lsl #2]
 *   @0xbf994 str r2, [r4, #0x10]
 *   @0xbf998 pop {r3, r4, r5, r6, r7, pc}
 *   @0xbf99c eoreq r0, r7, r4, ror lr
 *
 * ══ §98/289 YYCreateString  0xe5258  size 116  29 条（0xe5258..0xe52cc）
 * @func 0xe5258 0xe52cc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*) / operator new(unsigned int) / 0xb6538 / YYStrDup(char const*)
 * 字段偏移 top8: 0xc×3 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe5258 ldr r3, [r0, #0xc]
 *   @0xe525c push {r4, r5, r6, lr}
 *   @0xe5260 sub r3, r3, #1
 *   @0xe5264 bic r3, r3, #-16777216
 *   @0xe5268 mov r4, r0
 *   @0xe526c bic r3, r3, #3
 *   @0xe5270 mov r6, r1
 *   @0xe5274 cmp r3, #0
 *   @0xe5278 bne 0xe5280 <_Z14YYCreateStringP6RValuePKc+0x28>
 *   @0xe527c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe5280 mov r3, #0
 *   @0xe5284 mov r2, #5
 *   @0xe5288 str r3, [r4, #0x8]
 *   @0xe528c mov r0, #12
 *   @0xe5290 str r3, [r4]
 *   @0xe5294 str r2, [r4, #0xc]
 *   @0xe5298 bl 0x27c524 <_Znwj>
 *   @0xe529c mov r5, r0
 *   @0xe52a0 subs r0, r6, #0
 *   @0xe52a4 beq 0xe52ac <_Z14YYCreateStringP6RValuePKc+0x54>
 *   @0xe52a8 bl 0xb6538 <strlen@plt>
 *   @0xe52ac str r0, [r5, #0x8]
 *   @0xe52b0 mov r0, r6
 *   @0xe52b4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xe52b8 mov r3, #1
 *   @0xe52bc stm r5, {r0, r3}
 *   @0xe52c0 str r3, [r4, #0xc]
 *   @0xe52c4 str r5, [r4]
 *   @0xe52c8 pop {r4, r5, r6, pc}
 *
 * ══ §99/289 CLayerManager::CleanRoomLayerRuntimeData  0x1b8f68  size 116  29 条（0x1b8f68..0x1b8fdc）
 * @func 0x1b8f68 0x1b8fdc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::CleanElementRuntimeData(CLayerElementBase*)
 * 字段偏移 top8: 0xd4×1 / 0x58×1 / 0x14×1 / 0x68×1 / 0x24×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8f68 cmp r0, #0
 *   @0x1b8f6c push {r3, r4, r5, lr}
 *   @0x1b8f70 beq 0x1b8fac <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x44>
 *   @0x1b8f74 ldr r5, [r0, #0xd4]
 *   @0x1b8f78 cmp r5, #0
 *   @0x1b8f7c beq 0x1b8fac <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x44>
 *   @0x1b8f80 ldr r4, [r5, #0x58]
 *   @0x1b8f84 cmp r4, #0
 *   @0x1b8f88 beq 0x1b8fa0 <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x38>
 *   @0x1b8f8c mov r0, r4
 *   @0x1b8f90 bl 0x1b8ed0 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase>
 *   @0x1b8f94 ldr r4, [r4, #0x14]
 *   @0x1b8f98 cmp r4, #0
 *   @0x1b8f9c bne 0x1b8f8c <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x24>
 *   @0x1b8fa0 ldr r5, [r5, #0x68]
 *   @0x1b8fa4 cmp r5, #0
 *   @0x1b8fa8 bne 0x1b8f80 <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x18>
 *   @0x1b8fac ldr r4, [pc, #0x24]
 *   @0x1b8fb0 ldr r4, [pc, r4]
 *   @0x1b8fb4 ldr r0, [r4]
 *   @0x1b8fb8 cmp r0, #0
 *   @0x1b8fbc popeq {r3, r4, r5, pc}
 *   @0x1b8fc0 ldr r3, [r0]
 *   @0x1b8fc4 ldr r3, [r3, #0x4]
 *   @0x1b8fc8 blx r3
 *   @0x1b8fcc mov r3, #0
 *   @0x1b8fd0 str r3, [r4]
 *   @0x1b8fd4 pop {r3, r4, r5, pc}
 *   @0x1b8fd8 eoreq r4, r3, r0, asr #25
 *
 * ══ §100/289 CLayerManager::BuildElementRuntimeData  0x1ba6bc  size 116  29 条（0x1ba6bc..0x1ba730）
 * @func 0x1ba6bc 0x1ba730  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ba6bc cmp r0, #0
 *   @0x1ba6c0 bxeq lr
 *   @0x1ba6c4 cmp r1, #0
 *   @0x1ba6c8 bxeq lr
 *   @0x1ba6cc cmp r2, #0
 *   @0x1ba6d0 bxeq lr
 *   @0x1ba6d4 ldrb r3, [r2, #0x8]
 *   @0x1ba6d8 cmp r3, #0
 *   @0x1ba6dc bxne lr
 *   @0x1ba6e0 ldr r3, [r2]
 *   @0x1ba6e4 sub r3, r3, #1
 *   @0x1ba6e8 cmp r3, #6
 *   @0x1ba6ec addls pc, pc, r3, lsl #2
 *   @0x1ba6f0 b 0x1ba710 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x54>
 *   @0x1ba6f4 b 0x1ba72c <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x70>
 *   @0x1ba6f8 b 0x1ba728 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x6c>
 *   @0x1ba6fc b 0x1ba724 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x68>
 *   @0x1ba700 b 0x1ba720 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x64>
 *   @0x1ba704 b 0x1ba71c <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x60>
 *   @0x1ba708 b 0x1ba718 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x5c>
 *   @0x1ba70c b 0x1ba714 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x58>
 *   @0x1ba710 bx lr
 *   @0x1ba714 b 0x1b81f4 <_ZN13CLayerManager27BuildTileElementRuntimeDataEP5CRoomP6CLayerP17CLayerTileElement>
 *   @0x1ba718 b 0x1b81e8 <_ZN13CLayerManager31BuildParticleElementRuntimeDataEP5CRoomP6CLayerP21CLayerParticleElement>
 *   @0x1ba71c b 0x1b81dc <_ZN13CLayerManager30BuildTilemapElementRuntimeDataEP5CRoomP6CLayerP20CLayerTilemapElement>
 *   @0x1ba720 b 0x1b81d0 <_ZN13CLayerManager29BuildSpriteElementRuntimeDataEP5CRoomP6CLayerP19CLayerSpriteElement>
 *   @0x1ba724 b 0x1ba514 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement>
 *   @0x1ba728 b 0x1b8048 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement>
 *   @0x1ba72c b 0x1b803c <_ZN13CLayerManager33BuildBackgroundElementRuntimeDataEP5CRoomP6CLayerP23CLayerBackgroundElement>
 *
 * ══ §101/289 CollisionMarkTest  0x1cbfc0  size 116  29 条（0x1cbfc0..0x1cc034）
 * @func 0x1cbfc0 0x1cc034  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x194×2 / 0x64×1 / 0x54×1 / 0x18c×1 / 0x190×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cbfc0 ldr r3, [pc, #0x64]
 *   @0x1cbfc4 ldr r3, [pc, r3]
 *   @0x1cbfc8 ldrb r3, [r3]
 *   @0x1cbfcc cmp r3, #0
 *   @0x1cbfd0 bxeq lr
 *   @0x1cbfd4 ldr r3, [pc, #0x54]
 *   @0x1cbfd8 add r2, r0, #396
 *   @0x1cbfdc ldr r1, [r0, #0x194]
 *   @0x1cbfe0 ldr r3, [pc, r3]
 *   @0x1cbfe4 cmp r1, r3
 *   @0x1cbfe8 ldreq r12, [r0, #0x190]
 *   @0x1cbfec ldreq r1, [r0, #0x18c]
 *   @0x1cbff0 streq r12, [r1, #0x4]
 *   @0x1cbff4 ldreq r12, [r0, #0x190]
 *   @0x1cbff8 streq r1, [r12]
 *   @0x1cbffc mov r12, #0
 *   @0x1cc000 ldr r1, [r3]
 *   @0x1cc004 str r2, [r0, #0x18c]
 *   @0x1cc008 cmp r2, r1
 *   @0x1cc00c str r2, [r0, #0x190]
 *   @0x1cc010 str r12, [r0, #0x194]
 *   @0x1cc014 strne r1, [r0, #0x18c]
 *   @0x1cc018 strne r3, [r0, #0x190]
 *   @0x1cc01c strne r2, [r3]
 *   @0x1cc020 strne r2, [r1, #0x4]
 *   @0x1cc024 strne r3, [r0, #0x194]
 *   @0x1cc028 bx lr
 *   @0x1cc02c .word 0x002246bc
 *   @0x1cc030 eoreq r4, r2, r4, asr r11
 *
 * ══ §102/289 CollisionMarkDirty  0x1cc1d0  size 116  29 条（0x1cc1d0..0x1cc244）
 * @func 0x1cc1d0 0x1cc244  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a0×2 / 0x64×1 / 0x54×1 / 0x198×1 / 0x19c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cc1d0 ldr r3, [pc, #0x64]
 *   @0x1cc1d4 ldr r3, [pc, r3]
 *   @0x1cc1d8 ldrb r3, [r3]
 *   @0x1cc1dc cmp r3, #0
 *   @0x1cc1e0 bxeq lr
 *   @0x1cc1e4 ldr r3, [pc, #0x54]
 *   @0x1cc1e8 add r2, r0, #408
 *   @0x1cc1ec ldr r1, [r0, #0x1a0]
 *   @0x1cc1f0 ldr r3, [pc, r3]
 *   @0x1cc1f4 cmp r1, r3
 *   @0x1cc1f8 ldreq r12, [r0, #0x19c]
 *   @0x1cc1fc ldreq r1, [r0, #0x198]
 *   @0x1cc200 streq r12, [r1, #0x4]
 *   @0x1cc204 ldreq r12, [r0, #0x19c]
 *   @0x1cc208 streq r1, [r12]
 *   @0x1cc20c mov r12, #0
 *   @0x1cc210 ldr r1, [r3]
 *   @0x1cc214 str r2, [r0, #0x198]
 *   @0x1cc218 cmp r2, r1
 *   @0x1cc21c str r2, [r0, #0x19c]
 *   @0x1cc220 str r12, [r0, #0x1a0]
 *   @0x1cc224 strne r1, [r0, #0x198]
 *   @0x1cc228 strne r3, [r0, #0x19c]
 *   @0x1cc22c strne r2, [r3]
 *   @0x1cc230 strne r2, [r1, #0x4]
 *   @0x1cc234 strne r3, [r0, #0x1a0]
 *   @0x1cc238 b 0x1cbfc0 <_Z17CollisionMarkTestP9CInstance>
 *   @0x1cc23c eoreq r4, r2, r12, lsr #9
 *   @0x1cc240 eoreq r4, r2, r12, asr #18
 *
 * ══ §103/289 CTimeLine::Compile  0x1f1bb4  size 116  29 条（0x1f1bb4..0x1f1c28）
 * @func 0x1f1bb4 0x1f1c28  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimeLine::Compile()+0x64 / CEvent::Compile()
 * 字段偏移 top8: 0x8×2 / 0x2×2 / 0x64×1 / 0x40×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1bb4 ldr r3, [pc, #0x64]
 *   @0x1f1bb8 movw r2, #0x86a0
 *   @0x1f1bbc ldr r1, [r0, #0x8]
 *   @0x1f1bc0 movt r2, #0x1
 *   @0x1f1bc4 ldr r3, [pc, r3]
 *   @0x1f1bc8 cmp r1, #0
 *   @0x1f1bcc push {r4, r5, r6, lr}
 *   @0x1f1bd0 mov r5, r0
 *   @0x1f1bd4 str r2, [r3]
 *   @0x1f1bd8 ble 0x1f1c18 <_ZN9CTimeLine7CompileEv+0x64>
 *   @0x1f1bdc ldr r6, [pc, #0x40]
 *   @0x1f1be0 mov r4, #0
 *   @0x1f1be4 ldr r6, [pc, r6]
 *   @0x1f1be8 ldr r3, [r5, #0x14]
 *   @0x1f1bec ldr r2, [r5, #0xc]
 *   @0x1f1bf0 ldr r3, [r3, r4, lsl #2]
 *   @0x1f1bf4 ldr r0, [r2, r4, lsl #2]
 *   @0x1f1bf8 add r4, r4, #1
 *   @0x1f1bfc str r3, [r6]
 *   @0x1f1c00 bl 0xf2e10 <_ZN6CEvent7CompileEv>
 *   @0x1f1c04 cmp r0, #0
 *   @0x1f1c08 popeq {r4, r5, r6, pc}
 *   @0x1f1c0c ldr r3, [r5, #0x8]
 *   @0x1f1c10 cmp r3, r4
 *   @0x1f1c14 bgt 0x1f1be8 <_ZN9CTimeLine7CompileEv+0x34>
 *   @0x1f1c18 mov r0, #1
 *   @0x1f1c1c pop {r4, r5, r6, pc}
 *   @0x1f1c20 andseq r12, pc, r12, ror #3
 *   @0x1f1c24 ldrsbeq r12, [pc], -r0
 *
 * ══ §104/289 TimeLine_Name  0x1f2b58  size 116  29 条（0x1f2b58..0x1f2bcc）
 * @func 0x1f2b58 0x1f2bcc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TimeLine_Name(int)+0x4c
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x54×1 / 0x20×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2b58 cmp r0, #0
 *   @0x1f2b5c blt 0x1f2ba4 <_Z13TimeLine_Namei+0x4c>
 *   @0x1f2b60 ldr r3, [pc, #0x54]
 *   @0x1f2b64 add r3, pc, r3
 *   @0x1f2b68 ldr r2, [r3]
 *   @0x1f2b6c ldr r1, [r2]
 *   @0x1f2b70 cmp r0, r1
 *   @0x1f2b74 bge 0x1f2b98 <_Z13TimeLine_Namei+0x40>
 *   @0x1f2b78 ldr r2, [r2, #0x4]
 *   @0x1f2b7c ldr r2, [r2, r0, lsl #2]
 *   @0x1f2b80 cmp r2, #0
 *   @0x1f2b84 beq 0x1f2bb0 <_Z13TimeLine_Namei+0x58>
 *   @0x1f2b88 ldr r3, [r3, #0x4]
 *   @0x1f2b8c ldr r3, [r3, #0x4]
 *   @0x1f2b90 ldr r0, [r3, r0, lsl #2]
 *   @0x1f2b94 bx lr
 *   @0x1f2b98 ldr r0, [pc, #0x20]
 *   @0x1f2b9c add r0, pc, r0
 *   @0x1f2ba0 bx lr
 *   @0x1f2ba4 ldr r0, [pc, #0x18]
 *   @0x1f2ba8 add r0, pc, r0
 *   @0x1f2bac bx lr
 *   @0x1f2bb0 ldr r0, [pc, #0x10]
 *   @0x1f2bb4 add r0, pc, r0
 *   @0x1f2bb8 bx lr
 *   @0x1f2bbc subseq r0, r6, r8, lsl #11
 *   @0x1f2bc0 andseq sp, r3, r4, lsr #30
 *   @0x1f2bc4 andseq sp, r3, r8, lsl pc
 *   @0x1f2bc8 andseq sp, r3, r12, lsl #30
 *
 * ══ §105/289 isValidRadixChar  0x23fe9c  size 116  29 条（0x23fe9c..0x23ff10）
 * @func 0x23fe9c 0x23ff10  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: isValidRadixChar(char, int)+0x5c
 * 字段偏移 top8: 0x1×2 / 0x5c×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23fe9c cmp r1, #0
 *   @0x23fea0 ble 0x23fef8 <_Z16isValidRadixCharci+0x5c>
 *   @0x23fea4 ldr r2, [pc, #0x5c]
 *   @0x23fea8 ldr r2, [pc, r2]
 *   @0x23feac ldrb r3, [r2]
 *   @0x23feb0 cmp r3, r0
 *   @0x23feb4 beq 0x23ff00 <_Z16isValidRadixCharci+0x64>
 *   @0x23feb8 ldr r3, [pc, #0x4c]
 *   @0x23febc ldr r3, [pc, r3]
 *   @0x23fec0 ldrb r12, [r3]
 *   @0x23fec4 cmp r12, r0
 *   @0x23fec8 beq 0x23ff00 <_Z16isValidRadixCharci+0x64>
 *   @0x23fecc sub r12, r3, #1
 *   @0x23fed0 add r12, r12, r1
 *   @0x23fed4 b 0x23fef0 <_Z16isValidRadixCharci+0x54>
 *   @0x23fed8 ldrb r1, [r2, #0x1]!
 *   @0x23fedc cmp r1, r0
 *   @0x23fee0 beq 0x23ff00 <_Z16isValidRadixCharci+0x64>
 *   @0x23fee4 ldrb r1, [r3, #0x1]!
 *   @0x23fee8 cmp r1, r0
 *   @0x23feec beq 0x23ff00 <_Z16isValidRadixCharci+0x64>
 *   @0x23fef0 cmp r3, r12
 *   @0x23fef4 bne 0x23fed8 <_Z16isValidRadixCharci+0x3c>
 *   @0x23fef8 mov r0, #0
 *   @0x23fefc bx lr
 *   @0x23ff00 mov r0, #1
 *   @0x23ff04 bx lr
 *   @0x23ff08 andseq r1, r11, r12, ror #12
 *   @0x23ff0c andseq r1, r11, r12, asr r6
 *
 * ══ §106/289 spAnimationState_create  0x283128  size 116  29 条（0x283128..0x28319c）
 * @func 0x283128 0x28319c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / _malloc
 * 字段偏移 top8: 0x2c×2 / 0x58×1 / 0x1c×1 / 0x20×1 / 0x4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283128 push {r4, r5, r6, lr}
 *   @0x28312c mov r3, #61
 *   @0x283130 ldr r5, [pc, #0x58]
 *   @0x283134 mov r6, r0
 *   @0x283138 mov r1, #36
 *   @0x28313c mov r0, #1
 *   @0x283140 add r5, pc, r5
 *   @0x283144 mov r2, r5
 *   @0x283148 bl 0x285c4c <_calloc>
 *   @0x28314c mov r1, r5
 *   @0x283150 mov r2, #63
 *   @0x283154 mov r4, r0
 *   @0x283158 mov r0, #256
 *   @0x28315c bl 0x285c10 <_malloc>
 *   @0x283160 ldr r2, [pc, #0x2c]
 *   @0x283164 ldr r3, [pc, #0x2c]
 *   @0x283168 mov r1, #1065353216
 *   @0x28316c ldr r2, [pc, r2]
 *   @0x283170 str r6, [r4]
 *   @0x283174 ldr r3, [pc, r3]
 *   @0x283178 str r2, [r4, #0x1c]
 *   @0x28317c str r3, [r4, #0x20]
 *   @0x283180 str r1, [r4, #0x4]
 *   @0x283184 str r0, [r4, #0x18]
 *   @0x283188 mov r0, r4
 *   @0x28318c pop {r4, r5, r6, pc}
 *   @0x283190 andeq r4, sp, r8, asr #6
 *   @0x283194 andseq lr, r6, r0, lsl #15
 *   @0x283198 andseq lr, r6, r12, ror r7
 *
 * ══ §107/289 spIkConstraint_apply  0x28667c  size 116  29 条（0x28667c..0x2866f0）
 * @func 0x28667c 0x2866f0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spIkConstraint_apply2
 * 字段偏移 top8: 0x4×5 / 0xc×2 / 0x8×2 / 0x14×2 / 0x3c×2 / 0x48×2 / 0x-4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28667c ldr r3, [r0, #0x4]
 *   @0x286680 str lr, [sp, #-0x4]!
 *   @0x286684 cmp r3, #1
 *   @0x286688 sub sp, sp, #12
 *   @0x28668c beq 0x2866cc <spIkConstraint_apply+0x50>
 *   @0x286690 cmp r3, #2
 *   @0x286694 bne 0x2866c4 <spIkConstraint_apply+0x48>
 *   @0x286698 ldr r3, [r0, #0xc]
 *   @0x28669c ldr r1, [r0, #0x8]
 *   @0x2866a0 ldr lr, [r0, #0x14]
 *   @0x2866a4 ldr r12, [r0, #0x10]
 *   @0x2866a8 ldr r2, [r3, #0x3c]
 *   @0x2866ac ldr r0, [r1]
 *   @0x2866b0 ldr r3, [r3, #0x48]
 *   @0x2866b4 ldr r1, [r1, #0x4]
 *   @0x2866b8 str lr, [sp, #0x4]
 *   @0x2866bc str r12, [sp]
 *   @0x2866c0 bl 0x285f7c <spIkConstraint_apply2>
 *   @0x2866c4 add sp, sp, #12
 *   @0x2866c8 ldr pc, [sp], #4
 *   @0x2866cc ldr r2, [r0, #0xc]
 *   @0x2866d0 ldr r12, [r0, #0x8]
 *   @0x2866d4 ldr r3, [r0, #0x14]
 *   @0x2866d8 ldr r1, [r2, #0x3c]
 *   @0x2866dc ldr r0, [r12]
 *   @0x2866e0 ldr r2, [r2, #0x48]
 *   @0x2866e4 add sp, sp, #12
 *   @0x2866e8 ldr lr, [sp], #4
 *   @0x2866ec b 0x285e48 <spIkConstraint_apply1>
 *
 * ══ §108/289 __floatundidf  0x319150  size 116  29 条（0x319150..0x3191c4）
 * @func 0x319150 0x3191c4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319150 orrs r2, r0, r1
 *   @0x319154 bxeq lr
 *   @0x319158 push {r4, r5, lr}
 *   @0x31915c mov r5, #0
 *   @0x319160 b 0x319180 <__floatdidf+0x1c>
 *   @0x319164 orrs r2, r0, r1
 *   @0x319168 bxeq lr
 *   @0x31916c push {r4, r5, lr}
 *   @0x319170 ands r5, r1, #-2147483648
 *   @0x319174 bpl 0x319180 <__floatdidf+0x1c>
 *   @0x319178 rsbs r0, r0, #0
 *   @0x31917c rsc r1, r1, #0
 *   @0x319180 mov r4, #1024
 *   @0x319184 add r4, r4, #50
 *   @0x319188 lsrs r12, r1, #22
 *   @0x31918c beq 0x318f04 <__aeabi_dadd+0xec>
 *   @0x319190 mov r2, #3
 *   @0x319194 lsrs r12, r12, #3
 *   @0x319198 addne r2, r2, #3
 *   @0x31919c lsrs r12, r12, #3
 *   @0x3191a0 addne r2, r2, #3
 *   @0x3191a4 add r2, r2, r12, lsr #3
 *   @0x3191a8 rsb r3, r2, #32
 *   @0x3191ac lsl r12, r0, r3
 *   @0x3191b0 lsr r0, r0, r2
 *   @0x3191b4 orr r0, r0, r1, lsl r3
 *   @0x3191b8 lsr r1, r1, r2
 *   @0x3191bc add r4, r4, r2
 *   @0x3191c0 b 0x318f04 <__aeabi_dadd+0xec>
 *
 * ══ §109/289 __gtsf2  0x31b124  size 116  29 条（0x31b124..0x31b198）
 * @func 0x31b124 0x31b198  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b124 mvn r12, #0
 *   @0x31b128 b 0x31b138 <__nesf2+0x4>
 *   @0x31b12c mov r12, #1
 *   @0x31b130 b 0x31b138 <__nesf2+0x4>
 *   @0x31b134 mov r12, #1
 *   @0x31b138 str r12, [sp, #-0x4]!
 *   @0x31b13c lsl r2, r0, #1
 *   @0x31b140 lsl r3, r1, #1
 *   @0x31b144 mvns r12, r2, asr #24
 *   @0x31b148 mvnsne r12, r3, asr #24
 *   @0x31b14c beq 0x31b170 <__nesf2+0x3c>
 *   @0x31b150 add sp, sp, #4
 *   @0x31b154 orrs r12, r2, r3, lsr #1
 *   @0x31b158 teqne r0, r1
 *   @0x31b15c subspl r0, r2, r3
 *   @0x31b160 asrhi r0, r1, #31
 *   @0x31b164 mvnlo r0, r1, asr #31
 *   @0x31b168 orrne r0, r0, #1
 *   @0x31b16c bx lr
 *   @0x31b170 mvns r12, r2, asr #24
 *   @0x31b174 bne 0x31b180 <__nesf2+0x4c>
 *   @0x31b178 lsls r12, r0, #9
 *   @0x31b17c bne 0x31b190 <__nesf2+0x5c>
 *   @0x31b180 mvns r12, r3, asr #24
 *   @0x31b184 bne 0x31b150 <__nesf2+0x1c>
 *   @0x31b188 lsls r12, r1, #9
 *   @0x31b18c beq 0x31b150 <__nesf2+0x1c>
 *   @0x31b190 ldr r0, [sp], #4
 *   @0x31b194 bx lr
 *
 * ══ §110/289 ClearHandledContainer  0xd3ee0  size 112  28 条（0xd3ee0..0xd3f50）
 * @func 0xd3ee0 0xd3f50  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x5c×1 / 0x38×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3ee0 ldr r2, [pc, #0x5c]
 *   @0xd3ee4 add r2, pc, r2
 *   @0xd3ee8 ldr r3, [r2]
 *   @0xd3eec cmp r3, #0
 *   @0xd3ef0 beq 0xd3f08 <_Z21ClearHandledContainerv+0x28>
 *   @0xd3ef4 cmp r3, r2
 *   @0xd3ef8 strne r3, [r3]
 *   @0xd3efc strne r3, [r3, #0x4]
 *   @0xd3f00 movne r2, #0
 *   @0xd3f04 strne r2, [r3, #0x8]
 *   @0xd3f08 ldr r2, [pc, #0x38]
 *   @0xd3f0c add r2, pc, r2
 *   @0xd3f10 ldr r3, [r2, #0x4]
 *   @0xd3f14 cmp r3, #0
 *   @0xd3f18 beq 0xd3f30 <_Z21ClearHandledContainerv+0x50>
 *   @0xd3f1c cmp r3, r2
 *   @0xd3f20 strne r3, [r3]
 *   @0xd3f24 strne r3, [r3, #0x4]
 *   @0xd3f28 movne r2, #0
 *   @0xd3f2c strne r2, [r3, #0x8]
 *   @0xd3f30 ldr r3, [pc, #0x14]
 *   @0xd3f34 add r3, pc, r3
 *   @0xd3f38 str r3, [r3]
 *   @0xd3f3c str r3, [r3, #0x4]
 *   @0xd3f40 bx lr
 *   @0xd3f44 ldrsbteq r6, [r10], -r0
 *   @0xd3f48 eorseq r6, r10, r8, lsr #5
 *   @0xd3f4c eorseq r6, r10, r0, lsl #5
 *
 * ══ §111/289 YYObjectBase::Add  0x19946c  size 112  28 条（0x19946c..0x1994dc）
 * @func 0x19946c 0x1994dc  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19946c push {r3, r4, r5, r6, r7, lr}
 *   @0x199470 mov r4, r1
 *   @0x199474 mov r5, r2
 *   @0x199478 mov r7, r3
 *   @0x19947c mov r6, r0
 *   @0x199480 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x199484 cmp r0, #0
 *   @0x199488 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x19948c mov r1, r4
 *   @0x199490 mov r0, r6
 *   @0x199494 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x199498 ldr r3, [r0, #0xc]
 *   @0x19949c mov r4, r0
 *   @0x1994a0 sub r3, r3, #1
 *   @0x1994a4 bic r3, r3, #-16777216
 *   @0x1994a8 bic r3, r3, #3
 *   @0x1994ac cmp r3, #0
 *   @0x1994b0 beq 0x1994d4 <_ZN12YYObjectBase3AddEPKcPS_i+0x68>
 *   @0x1994b4 mov r3, #6
 *   @0x1994b8 str r5, [r4]
 *   @0x1994bc mov r0, r6
 *   @0x1994c0 str r7, [r4, #0x8]
 *   @0x1994c4 mov r1, r5
 *   @0x1994c8 str r3, [r4, #0xc]
 *   @0x1994cc pop {r3, r4, r5, r6, r7, lr}
 *   @0x1994d0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1994d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1994d8 b 0x1994b4 <_ZN12YYObjectBase3AddEPKcPS_i+0x48>
 *
 * ══ §112/289 YYObjectBase::Add  0x199960  size 112  28 条（0x199960..0x1999d0）
 * @func 0x199960 0x1999d0  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199960 push {r3, r4, r5, r6, r7, lr}
 *   @0x199964 mov r4, r1
 *   @0x199968 mov r6, r2
 *   @0x19996c mov r5, r3
 *   @0x199970 mov r7, r0
 *   @0x199974 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x199978 cmp r0, #0
 *   @0x19997c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x199980 mov r1, r4
 *   @0x199984 mov r0, r7
 *   @0x199988 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x19998c ldr r3, [r0, #0xc]
 *   @0x199990 mov r4, r0
 *   @0x199994 sub r3, r3, #1
 *   @0x199998 bic r3, r3, #-16777216
 *   @0x19999c bic r3, r3, #3
 *   @0x1999a0 cmp r3, #0
 *   @0x1999a4 beq 0x1999c8 <_ZN12YYObjectBase3AddEPKcii+0x68>
 *   @0x1999a8 vmov s15, r6
 *   @0x1999ac mov r1, #0
 *   @0x1999b0 str r5, [r4, #0x8]
 *   @0x1999b4 vcvt.f64.s32 d7, s15
 *   @0x1999b8 str r1, [r4, #0xc]
 *   @0x1999bc vmov r2, r3, d7
 *   @0x1999c0 stm r4, {r2, r3}
 *   @0x1999c4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1999c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1999cc b 0x1999a8 <_ZN12YYObjectBase3AddEPKcii+0x48>
 *
 * ══ §113/289 CLayerManager::CleanInstanceElementRuntimeData  0x1b8d9c  size 112  28 条（0x1b8d9c..0x1b8e0c）
 * @func 0x1b8d9c 0x1b8e0c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::CleanInstanceElementRuntimeData(CLayerInstanceElement*)+0x60
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x58×1 / 0x3×1 / 0x8×1 / 0xc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8d9c ldr r1, [r0, #0x1c]
 *   @0x1b8da0 cmp r1, #0
 *   @0x1b8da4 blt 0x1b8dfc <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x60>
 *   @0x1b8da8 ldr r3, [pc, #0x58]
 *   @0x1b8dac ldr r3, [pc, r3]
 *   @0x1b8db0 ldr r2, [r3, #0x4]
 *   @0x1b8db4 ldr r3, [r3]
 *   @0x1b8db8 and r2, r1, r2
 *   @0x1b8dbc ldr r3, [r3, r2, lsl #3]
 *   @0x1b8dc0 cmp r3, #0
 *   @0x1b8dc4 bne 0x1b8dd8 <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x3c>
 *   @0x1b8dc8 b 0x1b8dfc <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x60>
 *   @0x1b8dcc ldr r3, [r3, #0x4]
 *   @0x1b8dd0 cmp r3, #0
 *   @0x1b8dd4 beq 0x1b8dfc <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x60>
 *   @0x1b8dd8 ldr r2, [r3, #0x8]
 *   @0x1b8ddc cmp r1, r2
 *   @0x1b8de0 bne 0x1b8dcc <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement+0x30>
 *   @0x1b8de4 ldr r3, [r3, #0xc]
 *   @0x1b8de8 cmp r3, #0
 *   @0x1b8dec movne r1, #0
 *   @0x1b8df0 mvnne r2, #0
 *   @0x1b8df4 strbne r1, [r3, #0x174]
 *   @0x1b8df8 strne r2, [r3, #0x170]
 *   @0x1b8dfc mov r3, #0
 *   @0x1b8e00 str r3, [r0, #0x20]
 *   @0x1b8e04 bx lr
 *   @0x1b8e08 mlaeq r3, r8, lr, r4
 *
 * ══ §114/289 CTouchAction::CTouchAction  0x1d76f4  size 112  28 条（0x1d76f4..0x1d7764）
 * @func 0x1d76f4 0x1d7764  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1 / 0x10×1 / 0x20×1 / 0x4×1 / 0x24×1 / 0x18×1 / 0x828×1 / 0x82c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d76f4 ldr r12, [pc, #0x64]
 *   @0x1d76f8 mvn r2, #0
 *   @0x1d76fc push {r4, r5, r6, r7, r8}
 *   @0x1d7700 ldr r12, [pc, r12]
 *   @0x1d7704 movw r7, #0x838
 *   @0x1d7708 mvn r5, #0
 *   @0x1d770c ldr r4, [r12]
 *   @0x1d7710 mov r6, #0
 *   @0x1d7714 str r5, [r0]
 *   @0x1d7718 mvn r3, #0
 *   @0x1d771c str r5, [r0, #0x10]
 *   @0x1d7720 mov r8, #0
 *   @0x1d7724 str r6, [r0, #0x20]
 *   @0x1d7728 movt r8, #0xbf80
 *   @0x1d772c strd r2, r3, [r0, r7]
 *   @0x1d7730 add r5, r4, #1
 *   @0x1d7734 str r4, [r0, #0x4]
 *   @0x1d7738 str r5, [r12]
 *   @0x1d773c mov r12, #0
 *   @0x1d7740 str r6, [r0, #0x24]
 *   @0x1d7744 str r8, [r0, #0x18]
 *   @0x1d7748 strd r2, r3, [r0, #8]
 *   @0x1d774c str r12, [r0, #0x828]
 *   @0x1d7750 str r12, [r0, #0x82c]
 *   @0x1d7754 strb r12, [r0, #0x830]
 *   @0x1d7758 pop {r4, r5, r6, r7, r8}
 *   @0x1d775c bx lr
 *   @0x1d7760 eoreq r9, r1, r8, lsl #10
 *
 * ══ §115/289 CDS_Priority::Add4GC  0x203ea4  size 112  28 条（0x203ea4..0x203f14）
 * @func 0x203ea4 0x203f14  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_ADDROOT(RValue const*, CGCGeneration*)×2 / CDS_Priority::Add4GC(CGCGeneration*)+0x3c
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203ea4 ldr r3, [r0, #0x8]
 *   @0x203ea8 push {r4, r5, r6, lr}
 *   @0x203eac cmp r3, #0
 *   @0x203eb0 mov r4, r0
 *   @0x203eb4 mov r6, r1
 *   @0x203eb8 movgt r5, #0
 *   @0x203ebc ble 0x203ee0 <_ZN12CDS_Priority6Add4GCEP13CGCGeneration+0x3c>
 *   @0x203ec0 ldr r0, [r4, #0xc]
 *   @0x203ec4 mov r1, r6
 *   @0x203ec8 add r0, r0, r5, lsl #4
 *   @0x203ecc add r5, r5, #1
 *   @0x203ed0 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration>
 *   @0x203ed4 ldr r3, [r4, #0x8]
 *   @0x203ed8 cmp r3, r5
 *   @0x203edc bgt 0x203ec0 <_ZN12CDS_Priority6Add4GCEP13CGCGeneration+0x1c>
 *   @0x203ee0 ldr r3, [r4, #0x10]
 *   @0x203ee4 cmp r3, #0
 *   @0x203ee8 pople {r4, r5, r6, pc}
 *   @0x203eec mov r5, #0
 *   @0x203ef0 ldr r0, [r4, #0x14]
 *   @0x203ef4 mov r1, r6
 *   @0x203ef8 add r0, r0, r5, lsl #4
 *   @0x203efc add r5, r5, #1
 *   @0x203f00 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration>
 *   @0x203f04 ldr r3, [r4, #0x10]
 *   @0x203f08 cmp r3, r5
 *   @0x203f0c bgt 0x203ef0 <_ZN12CDS_Priority6Add4GCEP13CGCGeneration+0x4c>
 *   @0x203f10 pop {r4, r5, r6, pc}
 *
 * ══ §116/289 vorbis_synthesis_restart  0x22723c  size 112  28 条（0x22723c..0x2272ac）
 * @func 0x22723c 0x2272ac  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x48×1 / 0x-4×1 / 0x1c×1 / 0x18×1 / 0x30×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22723c ldr r12, [r0, #0x48]
 *   @0x227240 mov r1, r0
 *   @0x227244 str r4, [sp, #-0x4]!
 *   @0x227248 cmp r12, #0
 *   @0x22724c ldr r3, [r0, #0x4]
 *   @0x227250 beq 0x2272a4 <vorbis_synthesis_restart+0x68>
 *   @0x227254 cmp r3, #0
 *   @0x227258 beq 0x2272a4 <vorbis_synthesis_restart+0x68>
 *   @0x22725c ldr r3, [r3, #0x1c]
 *   @0x227260 cmp r3, #0
 *   @0x227264 beq 0x2272a4 <vorbis_synthesis_restart+0x68>
 *   @0x227268 ldr r4, [r3, #0x4]
 *   @0x22726c mvn r0, #0
 *   @0x227270 str r0, [r1, #0x18]
 *   @0x227274 mov r0, #0
 *   @0x227278 mvn r2, #0
 *   @0x22727c mvn r3, #0
 *   @0x227280 add r4, r4, r4, lsr #31
 *   @0x227284 strd r2, r3, [r1, #56]
 *   @0x227288 strd r2, r3, [r1, #64]
 *   @0x22728c asr r4, r4, #1
 *   @0x227290 str r4, [r1, #0x30]
 *   @0x227294 str r4, [r1, #0x14]
 *   @0x227298 strd r2, r3, [r12, #16]
 *   @0x22729c ldr r4, [sp], #4
 *   @0x2272a0 bx lr
 *   @0x2272a4 mvn r0, #0
 *   @0x2272a8 b 0x22729c <vorbis_synthesis_restart+0x60>
 *
 * ══ §117/289 YYGetPtr  0xcec18  size 108  27 条（0xcec18..0xcec84）
 * @func 0xcec18 0xcec84  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x34×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcec18 add r3, r0, r1, lsl #4
 *   @0xcec1c push {r4, lr}
 *   @0xcec20 sub sp, sp, #8
 *   @0xcec24 ldr r2, [r3, #0xc]
 *   @0xcec28 bic r2, r2, #-16777216
 *   @0xcec2c cmp r2, #3
 *   @0xcec30 bne 0xcec40 <_Z8YYGetPtrPK6RValuei+0x28>
 *   @0xcec34 ldr r0, [r0, r1, lsl #4]
 *   @0xcec38 add sp, sp, #8
 *   @0xcec3c pop {r4, pc}
 *   @0xcec40 ldr r2, [pc, #0x34]
 *   @0xcec44 mov r0, r3
 *   @0xcec48 ldr r2, [pc, r2]
 *   @0xcec4c ldr r4, [r2]
 *   @0xcec50 str r1, [sp, #0x4]
 *   @0xcec54 bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xcec58 ldr r1, [sp, #0x4]
 *   @0xcec5c add r2, r1, #1
 *   @0xcec60 mov r1, r4
 *   @0xcec64 mov r3, r0
 *   @0xcec68 ldr r0, [pc, #0x10]
 *   @0xcec6c add r0, pc, r0
 *   @0xcec70 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xcec74 mov r0, #0
 *   @0xcec78 b 0xcec38 <_Z8YYGetPtrPK6RValuei+0x20>
 *   @0xcec7c eorseq lr, r1, r8, ror #29
 *   @0xcec80 eoreq r3, r6, r8, asr #15
 *
 * ══ §118/289 Code_Variable_Find_Slot_From_Global_Name  0xd2054  size 108  27 条（0xd2054..0xd20c0）
 * @func 0xd2054 0xd20c0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Variable_Find_Slot_From_Global_Name(char const*)+0x58 / 0xb6574
 * 字段偏移 top8: 0x60×1 / 0x4×1 / 0xc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd2054 ldr r3, [pc, #0x60]
 *   @0xd2058 push {r4, r5, r6, r7, r8, lr}
 *   @0xd205c ldr r3, [pc, r3]
 *   @0xd2060 mov r6, r0
 *   @0xd2064 ldr r5, [r3, #0x4]
 *   @0xd2068 cmp r5, #0
 *   @0xd206c ble 0xd20ac <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x58>
 *   @0xd2070 ldr r7, [r3]
 *   @0xd2074 mov r4, #0
 *   @0xd2078 ldr r8, [r3, #0xc]
 *   @0xd207c cmp r4, r7
 *   @0xd2080 mov r0, r6
 *   @0xd2084 bge 0xd20a0 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x4c>
 *   @0xd2088 ldr r1, [r8, r4, lsl #2]
 *   @0xd208c cmp r1, #0
 *   @0xd2090 beq 0xd20a0 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x4c>
 *   @0xd2094 bl 0xb6574 <strcmp@plt>
 *   @0xd2098 cmp r0, #0
 *   @0xd209c beq 0xd20b4 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x60>
 *   @0xd20a0 add r4, r4, #1
 *   @0xd20a4 cmp r4, r5
 *   @0xd20a8 bne 0xd207c <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x28>
 *   @0xd20ac mvn r0, #0
 *   @0xd20b0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xd20b4 mov r0, r4
 *   @0xd20b8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xd20bc eorseq r11, r1, r0, asr #22
 *
 * ══ §119/289 YYStrDup  0xdb8c8  size 108  27 条（0xdb8c8..0xdb934）
 * @func 0xdb8c8 0xdb934  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: memLogPushContext(char const*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / memLogPopContext()
 * 字段偏移 top8: 0x54×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb8c8 push {r4, r5, r6, lr}
 *   @0xdb8cc mov r4, r0
 *   @0xdb8d0 ldr r0, [pc, #0x54]
 *   @0xdb8d4 add r0, pc, r0
 *   @0xdb8d8 bl 0x27b948 <_Z17memLogPushContextPKc>
 *   @0xdb8dc cmp r4, #0
 *   @0xdb8e0 beq 0xdb924 <_Z8YYStrDupPKc+0x5c>
 *   @0xdb8e4 mov r0, r4
 *   @0xdb8e8 bl 0xb6538 <strlen@plt>
 *   @0xdb8ec mov r3, #1
 *   @0xdb8f0 ldr r1, [pc, #0x38]
 *   @0xdb8f4 movw r2, #0x2cbd
 *   @0xdb8f8 add r1, pc, r1
 *   @0xdb8fc add r5, r0, r3
 *   @0xdb900 mov r0, r5
 *   @0xdb904 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xdb908 mov r1, r4
 *   @0xdb90c mov r2, r5
 *   @0xdb910 mov r6, r0
 *   @0xdb914 bl 0xb65bc <memcpy@plt>
 *   @0xdb918 bl 0x27b94c <_Z16memLogPopContextv>
 *   @0xdb91c mov r0, r6
 *   @0xdb920 pop {r4, r5, r6, pc}
 *   @0xdb924 mov r6, r4
 *   @0xdb928 b 0xdb918 <_Z8YYStrDupPKc+0x50>
 *   @0xdb92c mlaeq r5, r12, r3, r7
 *   @0xdb930 eoreq r6, r5, r4, lsl #29
 *
 * ══ §120/289 Code_Constant_Prepare  0xf1b44  size 108  27 条（0xf1b44..0xf1bb0）
 * @func 0xf1b44 0xf1bb0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Constant_Prepare()+0x58 / Code_Constant_Add(char const*, char const*)
 * 字段偏移 top8: 0x2×2 / 0x54×1 / 0x44×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1b44 push {r3, r4, r5, r6, r7, lr}
 *   @0xf1b48 ldr r5, [pc, #0x54]
 *   @0xf1b4c ldr r5, [pc, r5]
 *   @0xf1b50 ldr r3, [r5]
 *   @0xf1b54 cmp r3, #0
 *   @0xf1b58 ble 0xf1b9c <_Z21Code_Constant_Preparev+0x58>
 *   @0xf1b5c ldr r7, [pc, #0x44]
 *   @0xf1b60 mov r4, #0
 *   @0xf1b64 ldr r6, [pc, #0x40]
 *   @0xf1b68 ldr r7, [pc, r7]
 *   @0xf1b6c ldr r6, [pc, r6]
 *   @0xf1b70 ldr r2, [r7]
 *   @0xf1b74 ldr r3, [r6]
 *   @0xf1b78 ldr r0, [r2, r4, lsl #2]
 *   @0xf1b7c ldr r1, [r3, r4, lsl #2]
 *   @0xf1b80 add r4, r4, #1
 *   @0xf1b84 bl 0xf1a10 <_Z17Code_Constant_AddPKcS0_>
 *   @0xf1b88 cmp r0, #0
 *   @0xf1b8c popeq {r3, r4, r5, r6, r7, pc}
 *   @0xf1b90 ldr r3, [r5]
 *   @0xf1b94 cmp r3, r4
 *   @0xf1b98 bgt 0xf1b70 <_Z21Code_Constant_Preparev+0x2c>
 *   @0xf1b9c mov r0, #1
 *   @0xf1ba0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xf1ba4 eoreq r12, pc, r8, lsl #5
 *   @0xf1ba8 eoreq r12, pc, r0, ror r2
 *   @0xf1bac eoreq r12, pc, r0, ror r2
 *
 * ══ §121/289 F_DsQueueClear  0xfbe14  size 108  27 条（0xfbe14..0xfbe80）
 * @func 0xfbe14 0xfbe80  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsQueueClear(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c
 * 字段偏移 top8: 0x8×1 / 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbe14 push {r3, lr}
 *   @0xfbe18 mov r1, #0
 *   @0xfbe1c ldr r0, [sp, #0x8]
 *   @0xfbe20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbe24 cmp r0, #0
 *   @0xfbe28 blt 0xfbe60 <_Z14F_DsQueueClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfbe2c ldr r3, [pc, #0x40]
 *   @0xfbe30 ldr r3, [pc, r3]
 *   @0xfbe34 ldr r3, [r3]
 *   @0xfbe38 cmp r0, r3
 *   @0xfbe3c bge 0xfbe60 <_Z14F_DsQueueClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfbe40 ldr r3, [pc, #0x30]
 *   @0xfbe44 ldr r3, [pc, r3]
 *   @0xfbe48 ldr r3, [r3, #0x4]
 *   @0xfbe4c ldr r0, [r3, r0, lsl #2]
 *   @0xfbe50 cmp r0, #0
 *   @0xfbe54 beq 0xfbe60 <_Z14F_DsQueueClearR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xfbe58 pop {r3, lr}
 *   @0xfbe5c b 0x20eacc <_ZN9CDS_Queue5ClearEv>
 *   @0xfbe60 ldr r0, [pc, #0x14]
 *   @0xfbe64 mov r1, #0
 *   @0xfbe68 pop {r3, lr}
 *   @0xfbe6c add r0, pc, r0
 *   @0xfbe70 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbe74 eoreq r2, pc, r12, lsr r0
 *   @0xfbe78 eoreq r2, pc, r12, lsr #32
 *   @0xfbe7c mlaeq r3, r0, sp, r11
 *
 * ══ §122/289 FreeRValue  0x190e84  size 108  27 条（0x190e84..0x190ef0）
 * @func 0x190e84 0x190ef0  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FreeRValue(RValue*, RValue**, RValue**)+0x30
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×2 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190e84 ldr r12, [pc, #0x60]
 *   @0x190e88 ldr r12, [pc, r12]
 *   @0x190e8c ldr r3, [r12, #0x4]
 *   @0x190e90 cmp r3, #0
 *   @0x190e94 bxeq lr
 *   @0x190e98 add r1, r3, #8
 *   @0x190e9c add r2, r3, #1048576
 *   @0x190ea0 cmp r0, r1
 *   @0x190ea4 add r2, r2, #8
 *   @0x190ea8 blo 0x190eb4 <_Z10FreeRValueP6RValuePS0_S1_+0x30>
 *   @0x190eac cmp r2, r0
 *   @0x190eb0 bhi 0x190ec4 <_Z10FreeRValueP6RValuePS0_S1_+0x40>
 *   @0x190eb4 ldr r3, [r3]
 *   @0x190eb8 cmp r3, #0
 *   @0x190ebc bne 0x190e98 <_Z10FreeRValueP6RValuePS0_S1_+0x14>
 *   @0x190ec0 bx lr
 *   @0x190ec4 ldr r1, [r12, #0x8]
 *   @0x190ec8 ldr r2, [r12, #0x10]
 *   @0x190ecc ldr r3, [r12, #0xc]
 *   @0x190ed0 add r2, r2, #1
 *   @0x190ed4 str r1, [r0]
 *   @0x190ed8 sub r3, r3, #1
 *   @0x190edc str r0, [r12, #0x8]
 *   @0x190ee0 str r2, [r12, #0x10]
 *   @0x190ee4 str r3, [r12, #0xc]
 *   @0x190ee8 bx lr
 *   @0x190eec eoreq pc, r5, r8, ror #15
 *
 * ══ §123/289 CObjectGM::ClearInstanceInfo  0x19d36c  size 108  27 条（0x19d36c..0x19d3d8）
 * @func 0x19d36c 0x19d3d8  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0xc4×2 / 0xd0×2 / 0xcc×1 / 0xc8×1 / 0xd8×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d36c push {r3, r4, r5, lr}
 *   @0x19d370 mov r5, r0
 *   @0x19d374 ldr r0, [r0, #0xc4]
 *   @0x19d378 cmp r0, #0
 *   @0x19d37c beq 0x19d394 <_ZN9CObjectGM17ClearInstanceInfoEv+0x28>
 *   @0x19d380 ldr r4, [r0]
 *   @0x19d384 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d388 cmp r4, #0
 *   @0x19d38c mov r0, r4
 *   @0x19d390 bne 0x19d380 <_ZN9CObjectGM17ClearInstanceInfoEv+0x14>
 *   @0x19d394 ldr r0, [r5, #0xd0]
 *   @0x19d398 mov r3, #0
 *   @0x19d39c str r3, [r5, #0xcc]
 *   @0x19d3a0 cmp r0, r3
 *   @0x19d3a4 str r3, [r5, #0xc8]
 *   @0x19d3a8 str r3, [r5, #0xc4]
 *   @0x19d3ac beq 0x19d3c4 <_ZN9CObjectGM17ClearInstanceInfoEv+0x58>
 *   @0x19d3b0 ldr r4, [r0]
 *   @0x19d3b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d3b8 cmp r4, #0
 *   @0x19d3bc mov r0, r4
 *   @0x19d3c0 bne 0x19d3b0 <_ZN9CObjectGM17ClearInstanceInfoEv+0x44>
 *   @0x19d3c4 mov r3, #0
 *   @0x19d3c8 str r3, [r5, #0xd8]
 *   @0x19d3cc str r3, [r5, #0xd4]
 *   @0x19d3d0 str r3, [r5, #0xd0]
 *   @0x19d3d4 pop {r3, r4, r5, pc}
 *
 * ══ §124/289 CDS_Grid::Mark4GC  0x205170  size 108  27 条（0x205170..0x2051dc）
 * @func 0x205170 0x2051dc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::Mark4GC(unsigned int*, int)+0x5c / RVALUE_GC(RValue const*, unsigned int*, int)
 * 字段偏移 top8: 0x8×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x205170 push {r4, r5, r6, r7, r8, lr}
 *   @0x205174 mov r7, r1
 *   @0x205178 ldr r1, [r0, #0x8]
 *   @0x20517c mov r5, r0
 *   @0x205180 mov r8, r2
 *   @0x205184 cmp r1, #0
 *   @0x205188 pople {r4, r5, r6, r7, r8, pc}
 *   @0x20518c ldr r3, [r0, #0x4]
 *   @0x205190 mov r6, #0
 *   @0x205194 cmp r3, #0
 *   @0x205198 ble 0x2051cc <_ZN8CDS_Grid7Mark4GCEPji+0x5c>
 *   @0x20519c mov r4, #0
 *   @0x2051a0 mla r3, r3, r6, r4
 *   @0x2051a4 ldr r0, [r5]
 *   @0x2051a8 mov r1, r7
 *   @0x2051ac mov r2, r8
 *   @0x2051b0 add r4, r4, #1
 *   @0x2051b4 add r0, r0, r3, lsl #4
 *   @0x2051b8 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x2051bc ldr r3, [r5, #0x4]
 *   @0x2051c0 cmp r3, r4
 *   @0x2051c4 bgt 0x2051a0 <_ZN8CDS_Grid7Mark4GCEPji+0x30>
 *   @0x2051c8 ldr r1, [r5, #0x8]
 *   @0x2051cc add r6, r6, #1
 *   @0x2051d0 cmp r1, r6
 *   @0x2051d4 bgt 0x205194 <_ZN8CDS_Grid7Mark4GCEPji+0x24>
 *   @0x2051d8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §125/289 Timing_Time  0x215148  size 108  27 条（0x215148..0x2151b4）
 * @func 0x215148 0x2151b4  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a0c / __fixdfdi
 * 字段偏移 top8: 0x-4×1 / 0x24×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215148 str lr, [sp, #-0x4]!
 *   @0x21514c sub sp, sp, #12
 *   @0x215150 mov r0, #1
 *   @0x215154 mov r1, sp
 *   @0x215158 bl 0xb6a0c <clock_gettime@plt>
 *   @0x21515c vldr s7, [sp]
 *   @0x215160 vcvt.f64.s32 d4, s7
 *   @0x215164 vldr s7, [sp, #4]
 *   @0x215168 vldr d5, [pc, #48]
 *   @0x21516c vldr d6, [pc, #52]
 *   @0x215170 vcvt.f64.s32 d7, s7
 *   @0x215174 vmla.f64 d7, d4, d5
 *   @0x215178 vdiv.f64 d5, d7, d6
 *   @0x21517c vmov r0, r1, d5
 *   @0x215180 bl 0x3194a0 <__fixdfdi>
 *   @0x215184 ldr r3, [pc, #0x24]
 *   @0x215188 add r3, pc, r3
 *   @0x21518c ldrd r2, r3, [r3]
 *   @0x215190 subs r0, r0, r2
 *   @0x215194 sbc r1, r1, r3
 *   @0x215198 add sp, sp, #12
 *   @0x21519c ldr pc, [sp], #4
 *   @0x2151a0 andeq r0, r0, r0
 *   @0x2151a4 bicmi r12, sp, r5, ror #26
 *   @0x2151a8 andeq r0, r0, r0
 *   @0x2151ac addmi r4, pc, r0
 *   @0x2151b0 subseq r0, r4, r0, lsl #2
 *
 * ══ §126/289 Audio_SetListenerOrientation  0x216650  size 108  27 条（0x216650..0x2166bc）
 * @func 0x216650 0x2166bc  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216650 cmp r0, #0
 *   @0x216654 vmov d7, r2, r3
 *   @0x216658 bxne lr
 *   @0x21665c ldr r3, [pc, #0x54]
 *   @0x216660 ldr r3, [pc, r3]
 *   @0x216664 ldr r3, [r3]
 *   @0x216668 cmp r3, #0
 *   @0x21666c bxeq lr
 *   @0x216670 vcvt.f32.f64 s14, d7
 *   @0x216674 vldr d6, [sp]
 *   @0x216678 vcvt.f32.f64 s15, d6
 *   @0x21667c vstr s14, [r3, #24]
 *   @0x216680 vldr d6, [sp, #8]
 *   @0x216684 vstr s15, [r3, #28]
 *   @0x216688 vcvt.f32.f64 s14, d6
 *   @0x21668c vldr d6, [sp, #16]
 *   @0x216690 vcvt.f32.f64 s15, d6
 *   @0x216694 vstr s14, [r3, #32]
 *   @0x216698 vldr d6, [sp, #24]
 *   @0x21669c vstr s15, [r3, #36]
 *   @0x2166a0 vcvt.f32.f64 s14, d6
 *   @0x2166a4 vldr d6, [sp, #32]
 *   @0x2166a8 vcvt.f32.f64 s15, d6
 *   @0x2166ac vstr s14, [r3, #40]
 *   @0x2166b0 vstr s15, [r3, #44]
 *   @0x2166b4 bx lr
 *   @0x2166b8 andseq r10, sp, r12, ror sp
 *
 * ══ §127/289 vorbis_book_clear  0x22f598  size 108  27 条（0x22f598..0x22f604）
 * @func 0x22f598 0x22f604  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×5
 * 字段偏移 top8: 0x10×1 / 0x14×1 / 0x18×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22f598 push {r4, lr}
 *   @0x22f59c mov r4, r0
 *   @0x22f5a0 ldr r0, [r0, #0x10]
 *   @0x22f5a4 cmp r0, #0
 *   @0x22f5a8 beq 0x22f5b0 <vorbis_book_clear+0x18>
 *   @0x22f5ac bl 0xb655c <free@plt>
 *   @0x22f5b0 ldr r0, [r4, #0x14]
 *   @0x22f5b4 cmp r0, #0
 *   @0x22f5b8 beq 0x22f5c0 <vorbis_book_clear+0x28>
 *   @0x22f5bc bl 0xb655c <free@plt>
 *   @0x22f5c0 ldr r0, [r4, #0x18]
 *   @0x22f5c4 cmp r0, #0
 *   @0x22f5c8 beq 0x22f5d0 <vorbis_book_clear+0x38>
 *   @0x22f5cc bl 0xb655c <free@plt>
 *   @0x22f5d0 ldr r0, [r4, #0x1c]
 *   @0x22f5d4 cmp r0, #0
 *   @0x22f5d8 beq 0x22f5e0 <vorbis_book_clear+0x48>
 *   @0x22f5dc bl 0xb655c <free@plt>
 *   @0x22f5e0 ldr r0, [r4, #0x20]
 *   @0x22f5e4 cmp r0, #0
 *   @0x22f5e8 beq 0x22f5f0 <vorbis_book_clear+0x58>
 *   @0x22f5ec bl 0xb655c <free@plt>
 *   @0x22f5f0 mov r0, r4
 *   @0x22f5f4 mov r1, #0
 *   @0x22f5f8 mov r2, #52
 *   @0x22f5fc pop {r4, lr}
 *   @0x22f600 b 0xb65b0 <memset@plt>
 *
 * ══ §128/289 CPhysicsFixture::SetPolygonShape  0x2368f8  size 108  27 条（0x2368f8..0x236964）
 * @func 0x2368f8 0x236964  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::DeleteShape() / operator new(unsigned int)
 * 字段偏移 top8: 0x20×1 / 0x48×1 / 0x4×1 / 0x8×1 / 0x94×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2368f8 push {r4, lr}
 *   @0x2368fc mov r4, r0
 *   @0x236900 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv>
 *   @0x236904 mov r0, #152
 *   @0x236908 bl 0x27c524 <_Znwj>
 *   @0x23690c ldr r12, [r4, #0x20]
 *   @0x236910 ldr r2, [pc, #0x48]
 *   @0x236914 mov r1, #2
 *   @0x236918 ldr r2, [pc, r2]
 *   @0x23691c add r2, r2, #8
 *   @0x236920 mov r3, r0
 *   @0x236924 movw r0, #0xd70a
 *   @0x236928 str r1, [r3, #0x4]
 *   @0x23692c movt r0, #0x3c23
 *   @0x236930 str r2, [r3]
 *   @0x236934 mov r1, #8
 *   @0x236938 str r0, [r3, #0x8]
 *   @0x23693c mov r2, #0
 *   @0x236940 mov r0, r4
 *   @0x236944 str r2, [r3, #0x94]
 *   @0x236948 pop {r4, lr}
 *   @0x23694c mov r2, #0
 *   @0x236950 str r2, [r3, #0xc]
 *   @0x236954 str r2, [r3, #0x10]
 *   @0x236958 str r3, [r12]
 *   @0x23695c b 0x23658c <_ZN15CPhysicsFixture13AllocVerticesEi>
 *   @0x236960 mulseq r11, r8, r11
 *
 * ══ §129/289 _spAnimationState_expandToIndex  0x28362c  size 108  27 条（0x28362c..0x283698）
 * @func 0x28362c 0x283698  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spAnimationState_expandToIndex+0x20 / _calloc / 0xb65bc / _free
 * 字段偏移 top8: 0x10×4 / 0xc×3 / 0x2×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28362c ldr r3, [r0, #0xc]
 *   @0x283630 push {r4, r5, r6, lr}
 *   @0x283634 cmp r3, r1
 *   @0x283638 mov r4, r0
 *   @0x28363c ble 0x28364c <_spAnimationState_expandToIndex+0x20>
 *   @0x283640 ldr r3, [r0, #0x10]
 *   @0x283644 ldr r0, [r3, r1, lsl #2]
 *   @0x283648 pop {r4, r5, r6, pc}
 *   @0x28364c add r5, r1, #1
 *   @0x283650 ldr r2, [pc, #0x3c]
 *   @0x283654 mov r3, #221
 *   @0x283658 mov r1, #4
 *   @0x28365c add r2, pc, r2
 *   @0x283660 mov r0, r5
 *   @0x283664 bl 0x285c4c <_calloc>
 *   @0x283668 ldr r2, [r4, #0xc]
 *   @0x28366c ldr r1, [r4, #0x10]
 *   @0x283670 lsl r2, r2, #2
 *   @0x283674 mov r6, r0
 *   @0x283678 bl 0xb65bc <memcpy@plt>
 *   @0x28367c ldr r0, [r4, #0x10]
 *   @0x283680 bl 0x285c80 <_free>
 *   @0x283684 mov r0, #0
 *   @0x283688 str r6, [r4, #0x10]
 *   @0x28368c str r5, [r4, #0xc]
 *   @0x283690 pop {r4, r5, r6, pc}
 *   @0x283694 andeq r3, sp, r12, lsr #28
 *
 * ══ §130/289 spAnimationStateData_getMix  0x283ca8  size 108  27 条（0x283ca8..0x283d14）
 * @func 0x283ca8 0x283d14  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×5 / 0x8×3 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283ca8 ldr r12, [r0, #0x8]
 *   @0x283cac str r4, [sp, #-0x4]!
 *   @0x283cb0 cmp r12, #0
 *   @0x283cb4 bne 0x283cc8 <spAnimationStateData_getMix+0x20>
 *   @0x283cb8 b 0x283d08 <spAnimationStateData_getMix+0x60>
 *   @0x283cbc ldr r12, [r12, #0x8]
 *   @0x283cc0 cmp r12, #0
 *   @0x283cc4 beq 0x283d08 <spAnimationStateData_getMix+0x60>
 *   @0x283cc8 ldr r3, [r12]
 *   @0x283ccc cmp r3, r1
 *   @0x283cd0 bne 0x283cbc <spAnimationStateData_getMix+0x14>
 *   @0x283cd4 ldr r3, [r12, #0x4]
 *   @0x283cd8 cmp r3, #0
 *   @0x283cdc bne 0x283cf0 <spAnimationStateData_getMix+0x48>
 *   @0x283ce0 b 0x283cbc <spAnimationStateData_getMix+0x14>
 *   @0x283ce4 ldr r3, [r3, #0x8]
 *   @0x283ce8 cmp r3, #0
 *   @0x283cec beq 0x283cbc <spAnimationStateData_getMix+0x14>
 *   @0x283cf0 ldr r4, [r3]
 *   @0x283cf4 cmp r4, r2
 *   @0x283cf8 bne 0x283ce4 <spAnimationStateData_getMix+0x3c>
 *   @0x283cfc ldr r0, [r3, #0x4]
 *   @0x283d00 ldr r4, [sp], #4
 *   @0x283d04 bx lr
 *   @0x283d08 ldr r0, [r0, #0x4]
 *   @0x283d0c ldr r4, [sp], #4
 *   @0x283d10 bx lr
 *
 * ══ §131/289 spSlot_setToSetupPose  0x28ee80  size 108  27 条（0x28ee80..0x28eeec）
 * @func 0x28ee80 0x28eeec  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_getAttachmentForSlotIndex
 * 字段偏移 top8: 0x10×2 / 0x14×2 / 0x18×2 / 0xc×2 / 0x4×2 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ee80 ldr r3, [r0]
 *   @0x28ee84 push {r4, lr}
 *   @0x28ee88 mov r4, r0
 *   @0x28ee8c ldr r1, [r3, #0x10]
 *   @0x28ee90 ldr r2, [r3, #0x14]
 *   @0x28ee94 str r1, [r0, #0x8]
 *   @0x28ee98 ldr r1, [r3, #0x18]
 *   @0x28ee9c str r2, [r0, #0xc]
 *   @0x28eea0 ldr r2, [r3, #0xc]
 *   @0x28eea4 str r1, [r0, #0x10]
 *   @0x28eea8 ldr r1, [r3, #0x1c]
 *   @0x28eeac cmp r2, #0
 *   @0x28eeb0 str r1, [r0, #0x14]
 *   @0x28eeb4 beq 0x28eee0 <spSlot_setToSetupPose+0x60>
 *   @0x28eeb8 ldr r0, [r0, #0x4]
 *   @0x28eebc ldr r1, [r3]
 *   @0x28eec0 ldr r0, [r0, #0x4]
 *   @0x28eec4 bl 0x28a314 <spSkeleton_getAttachmentForSlotIndex>
 *   @0x28eec8 mov r3, #0
 *   @0x28eecc str r3, [r4, #0x18]
 *   @0x28eed0 mov r1, r0
 *   @0x28eed4 mov r0, r4
 *   @0x28eed8 pop {r4, lr}
 *   @0x28eedc b 0x28ee1c <spSlot_setAttachment>
 *   @0x28eee0 mov r1, r2
 *   @0x28eee4 pop {r4, lr}
 *   @0x28eee8 b 0x28ee1c <spSlot_setAttachment>
 *
 * ══ §132/289 RelyAckFindClient  0x2998d8  size 108  27 条（0x2998d8..0x299944）
 * @func 0x2998d8 0x299944  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 0x58×1 / 0x40c×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2998d8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2998dc mov r5, r0
 *   @0x2998e0 ldr r3, [pc, #0x58]
 *   @0x2998e4 mov r6, r1
 *   @0x2998e8 mov r7, r2
 *   @0x2998ec ldr r3, [pc, r3]
 *   @0x2998f0 ldr r4, [r3]
 *   @0x2998f4 cmp r4, #0
 *   @0x2998f8 bne 0x29990c <_Z17RelyAckFindClientPKcii+0x34>
 *   @0x2998fc b 0x299938 <_Z17RelyAckFindClientPKcii+0x60>
 *   @0x299900 ldr r4, [r4, #0x40c]
 *   @0x299904 cmp r4, #0
 *   @0x299908 beq 0x299938 <_Z17RelyAckFindClientPKcii+0x60>
 *   @0x29990c ldr r0, [r4]
 *   @0x299910 mov r1, r5
 *   @0x299914 bl 0xb6574 <strcmp@plt>
 *   @0x299918 cmp r0, #0
 *   @0x29991c bne 0x299900 <_Z17RelyAckFindClientPKcii+0x28>
 *   @0x299920 ldr r3, [r4, #0x4]
 *   @0x299924 cmp r3, r6
 *   @0x299928 bne 0x299900 <_Z17RelyAckFindClientPKcii+0x28>
 *   @0x29992c ldr r3, [r4, #0x8]
 *   @0x299930 cmp r3, r7
 *   @0x299934 bne 0x299900 <_Z17RelyAckFindClientPKcii+0x28>
 *   @0x299938 mov r0, r4
 *   @0x29993c pop {r3, r4, r5, r6, r7, pc}
 *   @0x299940 ldrsheq r8, [r5], -r12
 *
 * ══ §133/289 DebuggerDestroyIPSocket  0x29cd80  size 108  27 条（0x29cd80..0x29cdec）
 * @func 0x29cd80 0x29cdec  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DebuggerDestroyIPSocket()+0x48 / FreeSocket(int)
 * 字段偏移 top8: 0x4×3 / 0x40×2 / 0x50×1 / 0xc×1 / 0x18×1 / 0x218×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cd80 push {r4, lr}
 *   @0x29cd84 ldr r4, [pc, #0x50]
 *   @0x29cd88 add r4, pc, r4
 *   @0x29cd8c ldr r2, [r4, #0x4]
 *   @0x29cd90 cmp r2, #0
 *   @0x29cd94 blt 0x29cdc8 <_Z23DebuggerDestroyIPSocketv+0x48>
 *   @0x29cd98 ldr r3, [pc, #0x40]
 *   @0x29cd9c ldr r1, [pc, #0x40]
 *   @0x29cda0 ldr r3, [pc, r3]
 *   @0x29cda4 add r1, pc, r1
 *   @0x29cda8 ldr r0, [r3]
 *   @0x29cdac ldr r3, [r0]
 *   @0x29cdb0 ldr r3, [r3, #0xc]
 *   @0x29cdb4 blx r3
 *   @0x29cdb8 ldr r0, [r4, #0x4]
 *   @0x29cdbc bl 0x299244 <_Z10FreeSocketi>
 *   @0x29cdc0 mvn r3, #0
 *   @0x29cdc4 str r3, [r4, #0x4]
 *   @0x29cdc8 ldr r3, [pc, #0x18]
 *   @0x29cdcc mov r2, #0
 *   @0x29cdd0 add r3, pc, r3
 *   @0x29cdd4 strb r2, [r3, #0x218]
 *   @0x29cdd8 pop {r4, pc}
 *   @0x29cddc andseq r10, r5, r8, lsl #21
 *   @0x29cde0 andseq r0, r5, r0, lsr #23
 *   @0x29cde4 andeq r12, r11, r0, lsr sp
 *   @0x29cde8 subeq r10, r11, r8, lsr lr
 *
 * ══ §134/289 b2Body::ShouldCollide  0x2c7158  size 108  27 条（0x2c7158..0x2c71c4）
 * @func 0x2c7158 0x2c71c4  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x7c×1 / 0x4×1 / 0x3d×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7158 ldr r3, [r0]
 *   @0x2c715c cmp r3, #2
 *   @0x2c7160 beq 0x2c7178 <_ZNK6b2Body13ShouldCollideEPKS_+0x20>
 *   @0x2c7164 ldr r3, [r1]
 *   @0x2c7168 cmp r3, #2
 *   @0x2c716c beq 0x2c7178 <_ZNK6b2Body13ShouldCollideEPKS_+0x20>
 *   @0x2c7170 mov r0, #0
 *   @0x2c7174 bx lr
 *   @0x2c7178 ldr r3, [r0, #0x7c]
 *   @0x2c717c cmp r3, #0
 *   @0x2c7180 bne 0x2c7194 <_ZNK6b2Body13ShouldCollideEPKS_+0x3c>
 *   @0x2c7184 b 0x2c71bc <_ZNK6b2Body13ShouldCollideEPKS_+0x64>
 *   @0x2c7188 ldr r3, [r3, #0xc]
 *   @0x2c718c cmp r3, #0
 *   @0x2c7190 beq 0x2c71bc <_ZNK6b2Body13ShouldCollideEPKS_+0x64>
 *   @0x2c7194 ldr r2, [r3]
 *   @0x2c7198 cmp r2, r1
 *   @0x2c719c bne 0x2c7188 <_ZNK6b2Body13ShouldCollideEPKS_+0x30>
 *   @0x2c71a0 ldr r2, [r3, #0x4]
 *   @0x2c71a4 ldrb r0, [r2, #0x3d]
 *   @0x2c71a8 cmp r0, #0
 *   @0x2c71ac bxeq lr
 *   @0x2c71b0 ldr r3, [r3, #0xc]
 *   @0x2c71b4 cmp r3, #0
 *   @0x2c71b8 bne 0x2c7194 <_ZNK6b2Body13ShouldCollideEPKS_+0x3c>
 *   @0x2c71bc mov r0, #1
 *   @0x2c71c0 bx lr
 *
 * ══ §135/289 b2BroadPhase::BufferMove  0x2dc81c  size 108  27 条（0x2dc81c..0x2dc888）
 * @func 0x2dc81c 0x2dc888  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int) / 0xb65bc / b2Free(void*)
 * 字段偏移 top8: 0x28×5 / 0x20×3 / 0x24×2 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc81c push {r4, r5, r6, lr}
 *   @0x2dc820 mov r4, r0
 *   @0x2dc824 ldr r3, [r4, #0x24]
 *   @0x2dc828 mov r5, r1
 *   @0x2dc82c ldr r0, [r0, #0x28]
 *   @0x2dc830 cmp r0, r3
 *   @0x2dc834 beq 0x2dc850 <_ZN12b2BroadPhase10BufferMoveEi+0x34>
 *   @0x2dc838 ldr r3, [r4, #0x20]
 *   @0x2dc83c str r5, [r3, r0, lsl #2]
 *   @0x2dc840 ldr r3, [r4, #0x28]
 *   @0x2dc844 add r3, r3, #1
 *   @0x2dc848 str r3, [r4, #0x28]
 *   @0x2dc84c pop {r4, r5, r6, pc}
 *   @0x2dc850 lsl r3, r0, #1
 *   @0x2dc854 lsl r0, r0, #3
 *   @0x2dc858 str r3, [r4, #0x24]
 *   @0x2dc85c ldr r6, [r4, #0x20]
 *   @0x2dc860 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2dc864 ldr r2, [r4, #0x28]
 *   @0x2dc868 mov r1, r6
 *   @0x2dc86c lsl r2, r2, #2
 *   @0x2dc870 str r0, [r4, #0x20]
 *   @0x2dc874 bl 0xb65bc <memcpy@plt>
 *   @0x2dc878 mov r0, r6
 *   @0x2dc87c bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2dc880 ldr r0, [r4, #0x28]
 *   @0x2dc884 b 0x2dc838 <_ZN12b2BroadPhase10BufferMoveEi+0x1c>
 *
 * ══ §136/289 __fixunssfdi  0x3194e4  size 108  27 条（0x3194e4..0x319550）
 * @func 0x3194e4 0x319550  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __muldf3×2 / __fixunsdfsi×2 / __extendsfdf2 / __floatunsidf / __subdf3
 * 字段偏移 top8: 0x50×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3194e4 push {r4, r5, r6, lr}
 *   @0x3194e8 bl 0x319110 <__extendsfdf2>
 *   @0x3194ec mov r2, #0
 *   @0x3194f0 ldr r3, [pc, #0x50]
 *   @0x3194f4 mov r4, r0
 *   @0x3194f8 mov r5, r1
 *   @0x3194fc bl 0x31ab34 <__muldf3>
 *   @0x319500 bl 0x31b0d0 <__fixunsdfsi>
 *   @0x319504 mov r6, r0
 *   @0x319508 bl 0x3190c4 <__floatunsidf>
 *   @0x31950c mov r2, #0
 *   @0x319510 ldr r3, [pc, #0x34]
 *   @0x319514 bl 0x31ab34 <__muldf3>
 *   @0x319518 mov r2, r0
 *   @0x31951c mov r3, r1
 *   @0x319520 mov r0, r4
 *   @0x319524 mov r1, r5
 *   @0x319528 bl 0x318e14 <__subdf3>
 *   @0x31952c mov r5, r6
 *   @0x319530 bl 0x31b0d0 <__fixunsdfsi>
 *   @0x319534 mov r2, #0
 *   @0x319538 mov r1, r6
 *   @0x31953c orr r4, r2, r0
 *   @0x319540 mov r0, r4
 *   @0x319544 pop {r4, r5, r6, pc}
 *   @0x319548 ldcllo p0, c0, [r0, #0]!
 *   @0x31954c mvnsmi r0, r0
 *
 * ══ §137/289 fYYRandom  0xc4598  size 104  26 条（0xc4598..0xc4600）
 * @func 0xc4598 0xc4600  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYRandom()×2
 * 字段偏移 top8: 无
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4598 vmov.f64 d7, #1.000000e+00
 *   @0xc459c push {r3, lr}
 *   @0xc45a0 vpush {d8}
 *   @0xc45a4 vmov d8, r0, r1
 *   @0xc45a8 vcmp.f64 d8, d7
 *   @0xc45ac vmrs APSR_nzcv, fpscr
 *   @0xc45b0 beq 0xc45d8 <_Z9fYYRandomd+0x40>
 *   @0xc45b4 bl 0xc44ec <_Z8YYRandomv>
 *   @0xc45b8 vldr d7, [pc, #56]
 *   @0xc45bc vmov s11, r0
 *   @0xc45c0 vcvt.f64.u32 d6, s11
 *   @0xc45c4 vmul.f64 d7, d6, d7
 *   @0xc45c8 vmul.f64 d8, d7, d8
 *   @0xc45cc vmov r0, r1, d8
 *   @0xc45d0 vpop {d8}
 *   @0xc45d4 pop {r3, pc}
 *   @0xc45d8 bl 0xc44ec <_Z8YYRandomv>
 *   @0xc45dc vldr d7, [pc, #20]
 *   @0xc45e0 vmov s11, r0
 *   @0xc45e4 vcvt.f64.u32 d8, s11
 *   @0xc45e8 vmul.f64 d8, d8, d7
 *   @0xc45ec vmov r0, r1, d8
 *   @0xc45f0 vpop {d8}
 *   @0xc45f4 pop {r3, pc}
 *   @0xc45f8 andeq r0, r0, r0
 *   @0xc45fc ldcllo p0, c0, [r0, #0]!
 *
 * ══ §138/289 HandleInstance  0xd3fd0  size 104  26 条（0xd3fd0..0xd4038）
 * @func 0xd3fd0 0xd4038  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1ac×2 / 0x58×1 / 0x30×1 / 0x1a4×1 / 0x1a8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3fd0 ldr r2, [pc, #0x58]
 *   @0xd3fd4 add r3, r0, #420
 *   @0xd3fd8 ldr r1, [r0, #0x1ac]
 *   @0xd3fdc mov r12, #0
 *   @0xd3fe0 add r2, pc, r2
 *   @0xd3fe4 cmp r1, r2
 *   @0xd3fe8 ldreq r1, [r0, #0x1a8]
 *   @0xd3fec ldreq r2, [r0, #0x1a4]
 *   @0xd3ff0 streq r1, [r2, #0x4]
 *   @0xd3ff4 ldreq r1, [r0, #0x1a8]
 *   @0xd3ff8 streq r2, [r1]
 *   @0xd3ffc ldr r2, [pc, #0x30]
 *   @0xd4000 str r3, [r0, #0x1a4]
 *   @0xd4004 add r2, pc, r2
 *   @0xd4008 str r3, [r0, #0x1a8]
 *   @0xd400c str r12, [r0, #0x1ac]
 *   @0xd4010 ldr r1, [r2, #0x4]
 *   @0xd4014 cmp r3, r1
 *   @0xd4018 strne r2, [r0, #0x1a4]
 *   @0xd401c strne r1, [r0, #0x1a8]
 *   @0xd4020 strne r3, [r2, #0x4]
 *   @0xd4024 strne r3, [r1]
 *   @0xd4028 strne r2, [r0, #0x1ac]
 *   @0xd402c bx lr
 *   @0xd4030 ldrsbteq r6, [r10], -r4
 *   @0xd4034 ldrhteq r6, [r10], -r0
 *
 * ══ §139/289 SetZBuffer  0x16841c  size 104  26 条（0x16841c..0x168484）
 * @func 0x16841c 0x168484  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x168420→0x3f23bc, 0x168428→0x4859b0, 0x16844c→0x4859c8, 0x168460→0x4859c8
 * 调用序列: 无
 * 字段偏移 top8: 0x50×2 / 0x4c×1 / 0x2c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16841c ldr r3, [pc, #0x50]
 *   @0x168420 ldr r1, [pc, #0x50]
 *   @0x168424 add r3, pc, r3
 *   @0x168428 ldr r2, [pc, #0x4c]
 *   @0x16842c ldr r1, [r3, r1]
 *   @0x168430 strb r0, [r1]
 *   @0x168434 ldr r2, [r3, r2]
 *   @0x168438 ldrb r2, [r2]
 *   @0x16843c cmp r2, #0
 *   @0x168440 beq 0x16844c <_Z10SetZBufferb+0x30>
 *   @0x168444 cmp r0, #0
 *   @0x168448 bne 0x168460 <_Z10SetZBufferb+0x44>
 *   @0x16844c ldr r0, [pc, #0x2c]
 *   @0x168450 mov r1, #1
 *   @0x168454 mov r2, #0
 *   @0x168458 ldr r0, [r3, r0]
 *   @0x16845c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168460 ldr r0, [pc, #0x18]
 *   @0x168464 mov r1, #1
 *   @0x168468 mov r2, r1
 *   @0x16846c ldr r0, [r3, r0]
 *   @0x168470 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168474 eoreq r9, r8, r12, lsr #16
 *   @0x168478 .word 0xffffe4b4
 *   @0x16847c .word 0xffffc0b4
 *   @0x168480 .word 0xffffc0a8
 *
 * ══ §140/289 CInstance::SkeletonAnimation  0x193158  size 104  26 条（0x193158..0x1931c0）
 * @func 0x193158 0x1931c0  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Exists(int) / Sprite_Data(int) / operator new(unsigned int) / CSkeletonInstance::CSkeletonInstance(CSkeletonSprite*)
 * 字段偏移 top8: 0x88×3 / 0x8c×2 / 0x74×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x193158 push {r4, r5, r6, lr}
 *   @0x19315c mov r4, r0
 *   @0x193160 ldr r0, [r0, #0x8c]
 *   @0x193164 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x193168 cmp r0, #0
 *   @0x19316c bne 0x193178 <_ZN9CInstance17SkeletonAnimationEv+0x20>
 *   @0x193170 ldr r0, [r4, #0x88]
 *   @0x193174 pop {r4, r5, r6, pc}
 *   @0x193178 ldr r0, [r4, #0x8c]
 *   @0x19317c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x193180 ldr r3, [r0, #0x74]
 *   @0x193184 mov r5, r0
 *   @0x193188 ldr r0, [r4, #0x88]
 *   @0x19318c cmp r3, #2
 *   @0x193190 beq 0x193198 <_ZN9CInstance17SkeletonAnimationEv+0x40>
 *   @0x193194 pop {r4, r5, r6, pc}
 *   @0x193198 cmp r0, #0
 *   @0x19319c popne {r4, r5, r6, pc}
 *   @0x1931a0 mov r0, #52
 *   @0x1931a4 bl 0x27c524 <_Znwj>
 *   @0x1931a8 ldr r1, [r5, #0x58]
 *   @0x1931ac mov r6, r0
 *   @0x1931b0 bl 0xbe67c <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite>
 *   @0x1931b4 mov r0, r6
 *   @0x1931b8 str r6, [r4, #0x88]
 *   @0x1931bc pop {r4, r5, r6, pc}
 *
 * ══ §141/289 _alutSetError  0x221940  size 104  26 条（0x221940..0x2219a8）
 * @func 0x221940 0x2219a8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a24 / alutGetErrorString / 0xb68a4
 * 字段偏移 top8: 0x48×1 / 0x30×1 / 0x28×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221940 push {r4, lr}
 *   @0x221944 mov r4, r0
 *   @0x221948 ldr r0, [pc, #0x48]
 *   @0x22194c add r0, pc, r0
 *   @0x221950 bl 0xb6a24 <getenv@plt>
 *   @0x221954 cmp r0, #0
 *   @0x221958 beq 0x221980 <_alutSetError+0x40>
 *   @0x22195c mov r0, r4
 *   @0x221960 bl 0x221730 <alutGetErrorString>
 *   @0x221964 ldr r1, [pc, #0x30]
 *   @0x221968 add r1, pc, r1
 *   @0x22196c mov r2, r0
 *   @0x221970 ldr r0, [pc, #0x28]
 *   @0x221974 ldr r0, [pc, r0]
 *   @0x221978 add r0, r0, #168
 *   @0x22197c bl 0xb68a4 <fprintf@plt>
 *   @0x221980 ldr r3, [pc, #0x1c]
 *   @0x221984 add r3, pc, r3
 *   @0x221988 ldr r2, [r3]
 *   @0x22198c cmp r2, #0
 *   @0x221990 streq r4, [r3]
 *   @0x221994 pop {r4, pc}
 *   @0x221998 mulseq r3, r0, r2
 *   @0x22199c andseq r3, r3, r0, lsl #5
 *   @0x2219a0 ldrsbeq pc, [r12], -r0
 *   @0x2219a4 subseq r3, r3, r0, ror #21
 *
 * ══ §142/289 spSkeleton_findBone  0x28a0c8  size 104  26 条（0x28a0c8..0x28a130）
 * @func 0x28a0c8 0x28a130  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findBone+0x60 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a0c8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x28a0cc mov r9, r0
 *   @0x28a0d0 ldr r6, [r0, #0x4]
 *   @0x28a0d4 mov r7, r1
 *   @0x28a0d8 cmp r6, #0
 *   @0x28a0dc ble 0x28a128 <spSkeleton_findBone+0x60>
 *   @0x28a0e0 ldr r3, [r0]
 *   @0x28a0e4 mov r4, #0
 *   @0x28a0e8 mov r5, r4
 *   @0x28a0ec ldr r8, [r3, #0x14]
 *   @0x28a0f0 b 0x28a100 <spSkeleton_findBone+0x38>
 *   @0x28a0f4 cmp r5, r6
 *   @0x28a0f8 add r4, r4, #4
 *   @0x28a0fc beq 0x28a128 <spSkeleton_findBone+0x60>
 *   @0x28a100 ldr r3, [r8, r4]
 *   @0x28a104 mov r1, r7
 *   @0x28a108 add r5, r5, #1
 *   @0x28a10c ldr r0, [r3, #0x4]
 *   @0x28a110 bl 0xb6574 <strcmp@plt>
 *   @0x28a114 cmp r0, #0
 *   @0x28a118 bne 0x28a0f4 <spSkeleton_findBone+0x2c>
 *   @0x28a11c ldr r3, [r9, #0x8]
 *   @0x28a120 ldr r0, [r3, r4]
 *   @0x28a124 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x28a128 mov r0, #0
 *   @0x28a12c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §143/289 spSkeleton_findSlot  0x28a18c  size 104  26 条（0x28a18c..0x28a1f4）
 * @func 0x28a18c 0x28a1f4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findSlot+0x60 / 0xb6574
 * 字段偏移 top8: 0x10×1 / 0x1c×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a18c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x28a190 mov r9, r0
 *   @0x28a194 ldr r6, [r0, #0x10]
 *   @0x28a198 mov r7, r1
 *   @0x28a19c cmp r6, #0
 *   @0x28a1a0 ble 0x28a1ec <spSkeleton_findSlot+0x60>
 *   @0x28a1a4 ldr r3, [r0]
 *   @0x28a1a8 mov r4, #0
 *   @0x28a1ac mov r5, r4
 *   @0x28a1b0 ldr r8, [r3, #0x1c]
 *   @0x28a1b4 b 0x28a1c4 <spSkeleton_findSlot+0x38>
 *   @0x28a1b8 cmp r5, r6
 *   @0x28a1bc add r4, r4, #4
 *   @0x28a1c0 beq 0x28a1ec <spSkeleton_findSlot+0x60>
 *   @0x28a1c4 ldr r3, [r8, r4]
 *   @0x28a1c8 mov r1, r7
 *   @0x28a1cc add r5, r5, #1
 *   @0x28a1d0 ldr r0, [r3, #0x4]
 *   @0x28a1d4 bl 0xb6574 <strcmp@plt>
 *   @0x28a1d8 cmp r0, #0
 *   @0x28a1dc bne 0x28a1b8 <spSkeleton_findSlot+0x2c>
 *   @0x28a1e0 ldr r3, [r9, #0x14]
 *   @0x28a1e4 ldr r0, [r3, r4]
 *   @0x28a1e8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x28a1ec mov r0, #0
 *   @0x28a1f0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §144/289 spSkeletonBounds_containsPoint  0x28ac8c  size 104  26 条（0x28ac8c..0x28acf4）
 * @func 0x28ac8c 0x28acf4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonBounds_containsPoint+0x60 / spPolygon_containsPoint
 * 字段偏移 top8: 0x8×1 / 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ac8c ldr r3, [r0]
 *   @0x28ac90 push {r4, r5, r6, r7, r8, lr}
 *   @0x28ac94 cmp r3, #0
 *   @0x28ac98 mov r5, r0
 *   @0x28ac9c mov r6, r1
 *   @0x28aca0 mov r7, r2
 *   @0x28aca4 movgt r4, #0
 *   @0x28aca8 bgt 0x28acbc <spSkeletonBounds_containsPoint+0x30>
 *   @0x28acac b 0x28acec <spSkeletonBounds_containsPoint+0x60>
 *   @0x28acb0 ldr r3, [r5]
 *   @0x28acb4 cmp r3, r4
 *   @0x28acb8 ble 0x28acec <spSkeletonBounds_containsPoint+0x60>
 *   @0x28acbc ldr r3, [r5, #0x8]
 *   @0x28acc0 mov r1, r6
 *   @0x28acc4 mov r2, r7
 *   @0x28acc8 lsl r8, r4, #2
 *   @0x28accc ldr r0, [r3, r4, lsl #2]
 *   @0x28acd0 add r4, r4, #1
 *   @0x28acd4 bl 0x28a5d4 <spPolygon_containsPoint>
 *   @0x28acd8 cmp r0, #0
 *   @0x28acdc beq 0x28acb0 <spSkeletonBounds_containsPoint+0x24>
 *   @0x28ace0 ldr r3, [r5, #0x4]
 *   @0x28ace4 ldr r0, [r3, r8]
 *   @0x28ace8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28acec mov r0, #0
 *   @0x28acf0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §145/289 __fixunsdfdi  0x319550  size 104  26 条（0x319550..0x3195b8）
 * @func 0x319550 0x3195b8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __muldf3×2 / __fixunsdfsi×2 / __floatunsidf / __subdf3
 * 字段偏移 top8: 0x50×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319550 push {r4, r5, r6, lr}
 *   @0x319554 mov r2, #0
 *   @0x319558 ldr r3, [pc, #0x50]
 *   @0x31955c mov r4, r0
 *   @0x319560 mov r5, r1
 *   @0x319564 bl 0x31ab34 <__muldf3>
 *   @0x319568 bl 0x31b0d0 <__fixunsdfsi>
 *   @0x31956c mov r6, r0
 *   @0x319570 bl 0x3190c4 <__floatunsidf>
 *   @0x319574 mov r2, #0
 *   @0x319578 ldr r3, [pc, #0x34]
 *   @0x31957c bl 0x31ab34 <__muldf3>
 *   @0x319580 mov r2, r0
 *   @0x319584 mov r3, r1
 *   @0x319588 mov r0, r4
 *   @0x31958c mov r1, r5
 *   @0x319590 bl 0x318e14 <__subdf3>
 *   @0x319594 mov r5, r6
 *   @0x319598 bl 0x31b0d0 <__fixunsdfsi>
 *   @0x31959c mov r2, #0
 *   @0x3195a0 mov r1, r6
 *   @0x3195a4 orr r4, r2, r0
 *   @0x3195a8 mov r0, r4
 *   @0x3195ac pop {r4, r5, r6, pc}
 *   @0x3195b0 ldcllo p0, c0, [r0, #0]!
 *   @0x3195b4 mvnsmi r0, r0
 *
 * ══ §146/289 VM::DebugInfo  0xec144  size 100  25 条（0xec144..0xec1a8）
 * @func 0xec144 0xec1a8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::DebugInfo(VMBuffer*, int)+0x5c
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec144 cmp r0, #0
 *   @0xec148 str r4, [sp, #-0x4]!
 *   @0xec14c beq 0xec190 <_ZN2VM9DebugInfoEP8VMBufferi+0x4c>
 *   @0xec150 ldr r4, [r0, #0x4]
 *   @0xec154 ldr r2, [r0, #0x10]
 *   @0xec158 lsrs r4, r4, #3
 *   @0xec15c beq 0xec198 <_ZN2VM9DebugInfoEP8VMBufferi+0x54>
 *   @0xec160 ldr r3, [r2]
 *   @0xec164 cmp r1, r3
 *   @0xec168 blt 0xec1a0 <_ZN2VM9DebugInfoEP8VMBufferi+0x5c>
 *   @0xec16c mov r3, #0
 *   @0xec170 b 0xec180 <_ZN2VM9DebugInfoEP8VMBufferi+0x3c>
 *   @0xec174 ldr r12, [r2, #0x8]!
 *   @0xec178 cmp r12, r1
 *   @0xec17c bgt 0xec190 <_ZN2VM9DebugInfoEP8VMBufferi+0x4c>
 *   @0xec180 add r3, r3, #1
 *   @0xec184 mov r0, r2
 *   @0xec188 cmp r4, r3
 *   @0xec18c bne 0xec174 <_ZN2VM9DebugInfoEP8VMBufferi+0x30>
 *   @0xec190 ldr r4, [sp], #4
 *   @0xec194 bx lr
 *   @0xec198 mov r0, r4
 *   @0xec19c b 0xec190 <_ZN2VM9DebugInfoEP8VMBufferi+0x4c>
 *   @0xec1a0 mov r0, #0
 *   @0xec1a4 b 0xec190 <_ZN2VM9DebugInfoEP8VMBufferi+0x4c>
 *
 * ══ §147/289 IAP_GetProductDetailM  0x161ae8  size 100  25 条（0x161ae8..0x161b4c）
 * @func 0x161ae8 0x161b4c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×3 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×1 / 0x30×1 / 0x2c×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161ae8 push {r4, lr}
 *   @0x161aec mov r4, r0
 *   @0x161af0 bl 0x290274 <getJNIEnv>
 *   @0x161af4 mov r1, r4
 *   @0x161af8 ldr r3, [r0]
 *   @0x161afc ldr r3, [r3, #0x29c]
 *   @0x161b00 blx r3
 *   @0x161b04 mov r4, r0
 *   @0x161b08 bl 0x290274 <getJNIEnv>
 *   @0x161b0c ldr r12, [pc, #0x30]
 *   @0x161b10 mov r3, r4
 *   @0x161b14 ldr r2, [pc, #0x2c]
 *   @0x161b18 ldr r12, [pc, r12]
 *   @0x161b1c ldr r2, [pc, r2]
 *   @0x161b20 ldr r1, [r12]
 *   @0x161b24 ldr r2, [r2]
 *   @0x161b28 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161b2c bl 0x290274 <getJNIEnv>
 *   @0x161b30 mov r1, r4
 *   @0x161b34 ldr r3, [r0]
 *   @0x161b38 ldr r3, [r3, #0x5c]
 *   @0x161b3c blx r3
 *   @0x161b40 pop {r4, pc}
 *   @0x161b44 eoreq r11, r8, r12, lsl #29
 *   @0x161b48 eoreq lr, r8, r4, asr r4
 *
 * ══ §148/289 YYObjectBase::Add  0x199b20  size 100  25 条（0x199b20..0x199b84）
 * @func 0x199b20 0x199b84  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199b20 push {r3, r4, r5, r6, r7, lr}
 *   @0x199b24 mov r4, r1
 *   @0x199b28 mov r6, r2
 *   @0x199b2c mov r5, r3
 *   @0x199b30 mov r7, r0
 *   @0x199b34 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x199b38 cmp r0, #0
 *   @0x199b3c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x199b40 mov r1, r4
 *   @0x199b44 mov r0, r7
 *   @0x199b48 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x199b4c ldr r3, [r0, #0xc]
 *   @0x199b50 mov r4, r0
 *   @0x199b54 sub r3, r3, #1
 *   @0x199b58 bic r3, r3, #-16777216
 *   @0x199b5c bic r3, r3, #3
 *   @0x199b60 cmp r3, #0
 *   @0x199b64 beq 0x199b7c <_ZN12YYObjectBase3AddEPKcPvi+0x5c>
 *   @0x199b68 mov r3, #3
 *   @0x199b6c str r6, [r4]
 *   @0x199b70 str r5, [r4, #0x8]
 *   @0x199b74 str r3, [r4, #0xc]
 *   @0x199b78 pop {r3, r4, r5, r6, r7, pc}
 *   @0x199b7c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x199b80 b 0x199b68 <_ZN12YYObjectBase3AddEPKcPvi+0x48>
 *
 * ══ §149/289 CGesture::CGesture  0x1d7c0c  size 100  25 条（0x1d7c0c..0x1d7c70）
 * @func 0x1d7c0c 0x1d7c70  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1 / 0x48×1 / 0x8×1 / 0x14×1 / 0x4×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d7c0c ldr r12, [pc, #0x54]
 *   @0x1d7c10 mvn r2, #0
 *   @0x1d7c14 push {r4, r5, r6}
 *   @0x1d7c18 ldr r12, [pc, r12]
 *   @0x1d7c1c ldr r3, [pc, #0x48]
 *   @0x1d7c20 ldr r4, [r12]
 *   @0x1d7c24 ldr r3, [pc, r3]
 *   @0x1d7c28 str r2, [r0, #0x8]
 *   @0x1d7c2c add r6, r3, #8
 *   @0x1d7c30 add r5, r4, #1
 *   @0x1d7c34 mvn r2, #1
 *   @0x1d7c38 str r6, [r0]
 *   @0x1d7c3c str r2, [r0, #0x14]
 *   @0x1d7c40 mvn r3, #0
 *   @0x1d7c44 mvn r2, #0
 *   @0x1d7c48 str r4, [r0, #0x4]
 *   @0x1d7c4c str r5, [r12]
 *   @0x1d7c50 mov r4, #0
 *   @0x1d7c54 strd r2, r3, [r0, #24]
 *   @0x1d7c58 str r4, [r0, #0xc]
 *   @0x1d7c5c str r4, [r0, #0x10]
 *   @0x1d7c60 pop {r4, r5, r6}
 *   @0x1d7c64 bx lr
 *   @0x1d7c68 .word 0x00218ff4
 *   @0x1d7c6c eoreq r8, r1, r12, asr #31
 *
 * ══ §150/289 CDS_Map::CDS_Map  0x203680  size 100  25 条（0x203680..0x2036e4）
 * @func 0x203680 0x2036e4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0
 * 字段偏移 top8: 0x40×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203680 push {r3, r4, r5, r6, r7, lr}
 *   @0x203684 mov r6, r0
 *   @0x203688 mov r0, #12
 *   @0x20368c lsl r5, r1, #3
 *   @0x203690 mov r7, r1
 *   @0x203694 bl 0x27c524 <_Znwj>
 *   @0x203698 ldr r1, [pc, #0x40]
 *   @0x20369c mov r3, #1
 *   @0x2036a0 sub r7, r7, #1
 *   @0x2036a4 mov r2, #187
 *   @0x2036a8 add r1, pc, r1
 *   @0x2036ac mov r4, r0
 *   @0x2036b0 mov r0, r5
 *   @0x2036b4 str r7, [r4, #0x4]
 *   @0x2036b8 mov r7, #0
 *   @0x2036bc str r7, [r4, #0x8]
 *   @0x2036c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2036c4 mov r2, r5
 *   @0x2036c8 mov r1, r7
 *   @0x2036cc str r0, [r4]
 *   @0x2036d0 bl 0xb65b0 <memset@plt>
 *   @0x2036d4 str r4, [r6]
 *   @0x2036d8 mov r0, r6
 *   @0x2036dc pop {r3, r4, r5, r6, r7, pc}
 *   @0x2036e0 andseq r9, r4, r4, lsl #12
 *
 * ══ §151/289 CDS_Grid::Add4GC  0x2051dc  size 100  25 条（0x2051dc..0x205240）
 * @func 0x2051dc 0x205240  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::Add4GC(CGCGeneration*)+0x54 / RVALUE_GC_ADDROOT(RValue const*, CGCGeneration*)
 * 字段偏移 top8: 0x8×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2051dc ldr r2, [r0, #0x8]
 *   @0x2051e0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2051e4 cmp r2, #0
 *   @0x2051e8 mov r5, r0
 *   @0x2051ec mov r7, r1
 *   @0x2051f0 pople {r3, r4, r5, r6, r7, pc}
 *   @0x2051f4 ldr r3, [r0, #0x4]
 *   @0x2051f8 mov r6, #0
 *   @0x2051fc cmp r3, #0
 *   @0x205200 ble 0x205230 <_ZN8CDS_Grid6Add4GCEP13CGCGeneration+0x54>
 *   @0x205204 mov r4, #0
 *   @0x205208 mla r3, r3, r6, r4
 *   @0x20520c ldr r0, [r5]
 *   @0x205210 mov r1, r7
 *   @0x205214 add r4, r4, #1
 *   @0x205218 add r0, r0, r3, lsl #4
 *   @0x20521c bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration>
 *   @0x205220 ldr r3, [r5, #0x4]
 *   @0x205224 cmp r3, r4
 *   @0x205228 bgt 0x205208 <_ZN8CDS_Grid6Add4GCEP13CGCGeneration+0x2c>
 *   @0x20522c ldr r2, [r5, #0x8]
 *   @0x205230 add r6, r6, #1
 *   @0x205234 cmp r2, r6
 *   @0x205238 bgt 0x2051fc <_ZN8CDS_Grid6Add4GCEP13CGCGeneration+0x20>
 *   @0x20523c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §152/289 utf8proc_get_property  0x23f854  size 100  25 条（0x23f854..0x23f8b8）
 * @func 0x23f854 0x23f8b8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0x3c×1 / 0x30×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23f854 cmp r0, #1114112
 *   @0x23f858 bhs 0x23f89c <_Z21utf8proc_get_propertyi+0x48>
 *   @0x23f85c ldr r12, [pc, #0x44]
 *   @0x23f860 asr r2, r0, #8
 *   @0x23f864 movw r1, #0x654
 *   @0x23f868 ldr r3, [pc, #0x3c]
 *   @0x23f86c add r12, pc, r12
 *   @0x23f870 add r12, r12, r2, lsl #1
 *   @0x23f874 add r3, pc, r3
 *   @0x23f878 ldr r2, [pc, #0x30]
 *   @0x23f87c ldrh r1, [r12, r1]
 *   @0x23f880 add r2, pc, r2
 *   @0x23f884 uxtab r0, r1, r0
 *   @0x23f888 add r0, r3, r0, lsl #1
 *   @0x23f88c ldrh r3, [r0, #12]
 *   @0x23f890 add r3, r3, r3, lsl #2
 *   @0x23f894 add r0, r2, r3, lsl #3
 *   @0x23f898 bx lr
 *   @0x23f89c ldr r0, [pc, #0x10]
 *   @0x23f8a0 add r0, pc, r0
 *   @0x23f8a4 bx lr
 *   @0x23f8a8 andseq r11, r3, r12, lsr #13
 *   @0x23f8ac andseq r9, r2, r12, ror #13
 *   @0x23f8b0 andseq r7, r6, r8, ror #21
 *   @0x23f8b4 andseq r7, r6, r8, asr #21
 *
 * ══ §153/289 InitFastCRC  0x27de00  size 100  25 条（0x27de00..0x27de64）
 * @func 0x27de00 0x27de64  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27de00 ldr r12, [pc, #0x54]
 *   @0x27de04 mov r0, #0
 *   @0x27de08 ldr r12, [pc, r12]
 *   @0x27de0c sub r12, r12, #4
 *   @0x27de10 mov r3, r0
 *   @0x27de14 mov r2, #8
 *   @0x27de18 tst r3, #1
 *   @0x27de1c lsr r1, r3, #1
 *   @0x27de20 lsreq r3, r3, #1
 *   @0x27de24 movwne r3, #0x8320
 *   @0x27de28 movtne r3, #0xedb8
 *   @0x27de2c eorne r3, r1, r3
 *   @0x27de30 subs r2, r2, #1
 *   @0x27de34 bne 0x27de18 <_Z11InitFastCRCv+0x18>
 *   @0x27de38 add r0, r0, #1
 *   @0x27de3c str r3, [r12, #0x4]!
 *   @0x27de40 cmp r0, #256
 *   @0x27de44 bne 0x27de10 <_Z11InitFastCRCv+0x10>
 *   @0x27de48 ldr r3, [pc, #0x10]
 *   @0x27de4c mov r2, #1
 *   @0x27de50 ldr r3, [pc, r3]
 *   @0x27de54 strb r2, [r3]
 *   @0x27de58 bx lr
 *   @0x27de5c andseq r2, r7, r8, lsl pc
 *   @0x27de60 andseq r3, r7, r4, lsr r10
 *
 * ══ §154/289 array_list_new  0x27e14c  size 100  25 条（0x27e14c..0x27e1b0）
 * @func 0x27e14c 0x27e1b0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34×2 / 0xb655c
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e14c push {r3, r4, r5, lr}
 *   @0x27e150 mov r1, #16
 *   @0x27e154 mov r5, r0
 *   @0x27e158 mov r0, #1
 *   @0x27e15c bl 0xb6c34 <calloc@plt>
 *   @0x27e160 subs r4, r0, #0
 *   @0x27e164 beq 0x27e19c <array_list_new+0x50>
 *   @0x27e168 mov r1, #32
 *   @0x27e16c str r5, [r4, #0xc]
 *   @0x27e170 mov r3, #0
 *   @0x27e174 str r1, [r4, #0x8]
 *   @0x27e178 mov r0, #4
 *   @0x27e17c str r3, [r4, #0x4]
 *   @0x27e180 bl 0xb6c34 <calloc@plt>
 *   @0x27e184 mov r5, r0
 *   @0x27e188 cmp r5, #0
 *   @0x27e18c mov r0, r4
 *   @0x27e190 str r5, [r4]
 *   @0x27e194 beq 0x27e1a4 <array_list_new+0x58>
 *   @0x27e198 pop {r3, r4, r5, pc}
 *   @0x27e19c mov r0, r4
 *   @0x27e1a0 pop {r3, r4, r5, pc}
 *   @0x27e1a4 bl 0xb655c <free@plt>
 *   @0x27e1a8 mov r0, r5
 *   @0x27e1ac pop {r3, r4, r5, pc}
 *
 * ══ §155/289 spAtlasAttachmentLoader_create  0x284bb4  size 100  25 条（0x284bb4..0x284c18）
 * @func 0x284bb4 0x284c18  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / _spAttachmentLoader_init
 * 字段偏移 top8: 0x30×2 / 0x50×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284bb4 ldr r2, [pc, #0x50]
 *   @0x284bb8 mov r1, #16
 *   @0x284bbc push {r4, r5, lr}
 *   @0x284bc0 add r2, pc, r2
 *   @0x284bc4 sub sp, sp, #12
 *   @0x284bc8 mov r5, r0
 *   @0x284bcc mov r3, #93
 *   @0x284bd0 mov r0, #1
 *   @0x284bd4 bl 0x285c4c <_calloc>
 *   @0x284bd8 ldr r1, [pc, #0x30]
 *   @0x284bdc ldr r2, [pc, #0x30]
 *   @0x284be0 mov r12, #0
 *   @0x284be4 mov r3, r12
 *   @0x284be8 ldr r1, [pc, r1]
 *   @0x284bec str r12, [sp]
 *   @0x284bf0 ldr r2, [pc, r2]
 *   @0x284bf4 mov r4, r0
 *   @0x284bf8 bl 0x284cc8 <_spAttachmentLoader_init>
 *   @0x284bfc mov r0, r4
 *   @0x284c00 str r5, [r4, #0xc]
 *   @0x284c04 add sp, sp, #12
 *   @0x284c08 pop {r4, r5, pc}
 *   @0x284c0c andeq r2, sp, r0, asr r10
 *   @0x284c10 andseq r12, r6, r12, lsl #26
 *   @0x284c14 andseq r12, r6, r8, lsl #26
 *
 * ══ §156/289 spPathConstraint_dispose  0x287a70  size 100  25 条（0x287a70..0x287ad4）
 * @func 0x287a70 0x287ad4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×6
 * 字段偏移 top8: 0x8×1 / 0x24×1 / 0x2c×1 / 0x34×1 / 0x3c×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287a70 push {r4, lr}
 *   @0x287a74 mov r4, r0
 *   @0x287a78 ldr r0, [r0, #0x8]
 *   @0x287a7c bl 0x285c80 <_free>
 *   @0x287a80 ldr r0, [r4, #0x24]
 *   @0x287a84 bl 0x285c80 <_free>
 *   @0x287a88 ldr r0, [r4, #0x2c]
 *   @0x287a8c cmp r0, #0
 *   @0x287a90 beq 0x287a98 <spPathConstraint_dispose+0x28>
 *   @0x287a94 bl 0x285c80 <_free>
 *   @0x287a98 ldr r0, [r4, #0x34]
 *   @0x287a9c cmp r0, #0
 *   @0x287aa0 beq 0x287aa8 <spPathConstraint_dispose+0x38>
 *   @0x287aa4 bl 0x285c80 <_free>
 *   @0x287aa8 ldr r0, [r4, #0x3c]
 *   @0x287aac cmp r0, #0
 *   @0x287ab0 beq 0x287ab8 <spPathConstraint_dispose+0x48>
 *   @0x287ab4 bl 0x285c80 <_free>
 *   @0x287ab8 ldr r0, [r4, #0x44]
 *   @0x287abc cmp r0, #0
 *   @0x287ac0 beq 0x287ac8 <spPathConstraint_dispose+0x58>
 *   @0x287ac4 bl 0x285c80 <_free>
 *   @0x287ac8 mov r0, r4
 *   @0x287acc pop {r4, lr}
 *   @0x287ad0 b 0x285c80 <_free>
 *
 * ══ §157/289 spSkin_attachAll  0x28ed9c  size 100  25 条（0x28ed9c..0x28ee00）
 * @func 0x28ed9c 0x28ee00  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkin_getAttachment / spSlot_setAttachment
 * 字段偏移 top8: 0x4×2 / 0x14×1 / 0x8×1 / 0x2×1 / 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ed9c push {r3, r4, r5, r6, r7, lr}
 *   @0x28eda0 mov r7, r0
 *   @0x28eda4 ldr r4, [r2, #0x4]
 *   @0x28eda8 mov r6, r1
 *   @0x28edac cmp r4, #0
 *   @0x28edb0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x28edb4 ldr r12, [r6, #0x14]
 *   @0x28edb8 ldr r1, [r4]
 *   @0x28edbc ldr r2, [r4, #0x8]
 *   @0x28edc0 ldr r5, [r12, r1, lsl #2]
 *   @0x28edc4 ldr r12, [r5, #0x18]
 *   @0x28edc8 cmp r12, r2
 *   @0x28edcc beq 0x28ede0 <spSkin_attachAll+0x44>
 *   @0x28edd0 ldr r4, [r4, #0xc]
 *   @0x28edd4 cmp r4, #0
 *   @0x28edd8 bne 0x28edb4 <spSkin_attachAll+0x18>
 *   @0x28eddc pop {r3, r4, r5, r6, r7, pc}
 *   @0x28ede0 mov r0, r7
 *   @0x28ede4 ldr r2, [r4, #0x4]
 *   @0x28ede8 bl 0x28ed00 <spSkin_getAttachment>
 *   @0x28edec subs r1, r0, #0
 *   @0x28edf0 mov r0, r5
 *   @0x28edf4 beq 0x28edd0 <spSkin_attachAll+0x34>
 *   @0x28edf8 bl 0x28ee1c <spSlot_setAttachment>
 *   @0x28edfc b 0x28edd0 <spSkin_attachAll+0x34>
 *
 * ══ §158/289 RelyAddPacket  0x299afc  size 100  25 条（0x299afc..0x299b60）
 * @func 0x299afc 0x299b60  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34 / Timing_Time / YYStrDup(char const*)
 * 字段偏移 top8: 0x20×2 / 0x4×1 / 0xc×1 / 0x10×1 / 0x24×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299afc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x299b00 mov r5, r0
 *   @0x299b04 mov r6, r1
 *   @0x299b08 mov r0, #1
 *   @0x299b0c mov r1, #40
 *   @0x299b10 mov r9, r3
 *   @0x299b14 mov r8, r2
 *   @0x299b18 ldr r7, [sp, #0x20]
 *   @0x299b1c bl 0xb6c34 <calloc@plt>
 *   @0x299b20 str r7, [r0]
 *   @0x299b24 mov r4, r0
 *   @0x299b28 bl 0x215148 <Timing_Time>
 *   @0x299b2c str r9, [r4, #0x4]
 *   @0x299b30 strd r0, r1, [r4, #24]
 *   @0x299b34 mov r0, r6
 *   @0x299b38 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x299b3c mov r3, #0
 *   @0x299b40 str r8, [r4, #0xc]
 *   @0x299b44 str r5, [r4, #0x10]
 *   @0x299b48 str r3, [r4, #0x24]
 *   @0x299b4c str r3, [r4, #0x20]
 *   @0x299b50 str r0, [r4, #0x8]
 *   @0x299b54 mov r0, r4
 *   @0x299b58 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x299b5c b 0x299a9c <_Z13RelyAddPacketP10SRelyEntry>
 *
 * ══ §159/289 b2Timer::GetMilliseconds  0x2e10cc  size 100  25 条（0x2e10cc..0x2e1130）
 * @func 0x2e10cc 0x2e1130  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6f70 / 0xfe3a5aec
 * 字段偏移 top8: 0x4×2
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e10cc push {r4, lr}
 *   @0x2e10d0 sub sp, sp, #8
 *   @0x2e10d4 mov r4, r0
 *   @0x2e10d8 mov r1, #0
 *   @0x2e10dc mov r0, sp
 *   @0x2e10e0 bl 0xb6f70 <gettimeofday@plt>
 *   @0x2e10e4 ldr r2, [r4, #0x4]
 *   @0x2e10e8 ldr r1, [sp, #0x4]
 *   @0x2e10ec vldr s12, [pc, #52]
 *   @0x2e10f0 ldr r3, [r4]
 *   @0x2e10f4 vldr s14, [pc, #48]
 *   @0x2e10f8 rsb r2, r2, r1
 *   @0x2e10fc vmov s15, r2
 *   @0x2e1100 ldr r2, [sp]
 *   @0x2e1104 vcvt.f32.u32 s15, s15
 *   @0x2e1108 rsb r3, r3, r2
 *   @0x2e110c vmul.f32 s15, s15, s12
 *   @0x2e1110 vmov s12, r3
 *   @0x2e1114 vcvt.f32.u32 s13, s12
 *   @0x2e1118 vmla.f32 s15, s13, s14
 *   @0x2e111c vmov r0, s15
 *   @0x2e1120 add sp, sp, #8
 *   @0x2e1124 pop {r4, pc}
 *   @0x2e1128 blo 0xfe3a5aec <b2_toiTime+0xfffffffffdc4c648>
 *   @0x2e112c ldrbtmi r0, [r10], #-0
 *
 * ══ §160/289 b2ContactSolver::StoreImpulses  0x2e2ee8  size 100  25 条（0x2e2ee8..0x2e2f4c）
 * @func 0x2e2ee8 0x2e2f4c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ContactSolver::StoreImpulses()+0x54
 * 字段偏移 top8: 0x30×1 / 0x28×1 / 0x2c×1 / 0x2×1 / 0x-88×1 / 0x48×1 / 0x-84×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e2ee8 ldr r2, [r0, #0x30]
 *   @0x2e2eec cmp r2, #0
 *   @0x2e2ef0 bxle lr
 *   @0x2e2ef4 ldr r3, [r0, #0x28]
 *   @0x2e2ef8 mov r1, #156
 *   @0x2e2efc ldr r12, [r0, #0x2c]
 *   @0x2e2f00 add r3, r3, #152
 *   @0x2e2f04 mla r0, r1, r2, r3
 *   @0x2e2f08 ldmda r3, {r1, r2}
 *   @0x2e2f0c cmp r1, #0
 *   @0x2e2f10 ldr r2, [r12, r2, lsl #2]
 *   @0x2e2f14 ble 0x2e2f3c <_ZN15b2ContactSolver13StoreImpulsesEv+0x54>
 *   @0x2e2f18 cmp r1, #1
 *   @0x2e2f1c ldr r1, [r3, #-0x88]
 *   @0x2e2f20 str r1, [r2, #0x48]
 *   @0x2e2f24 ldr r1, [r3, #-0x84]
 *   @0x2e2f28 str r1, [r2, #0x4c]
 *   @0x2e2f2c ldrne r1, [r3, #-0x64]
 *   @0x2e2f30 strne r1, [r2, #0x5c]
 *   @0x2e2f34 ldrne r1, [r3, #-0x60]
 *   @0x2e2f38 strne r1, [r2, #0x60]
 *   @0x2e2f3c add r3, r3, #156
 *   @0x2e2f40 cmp r3, r0
 *   @0x2e2f44 bne 0x2e2f08 <_ZN15b2ContactSolver13StoreImpulsesEv+0x20>
 *   @0x2e2f48 bx lr
 *
 * ══ §161/289 ConvertCull  0x17fc68  size 96  24 条（0x17fc68..0x17fcc8）
 * @func 0x17fc68 0x17fcc8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fc68 cmp r0, #1
 *   @0x17fc6c beq 0x17fca0 <_Z11ConvertCull5eCull+0x38>
 *   @0x17fc70 cmp r0, #2
 *   @0x17fc74 bne 0x17fc98 <_Z11ConvertCull5eCull+0x30>
 *   @0x17fc78 ldr r3, [pc, #0x40]
 *   @0x17fc7c movw r2, #0x901
 *   @0x17fc80 ldr r3, [pc, r3]
 *   @0x17fc84 ldr r0, [r3]
 *   @0x17fc88 cmp r0, #1
 *   @0x17fc8c movne r0, r2
 *   @0x17fc90 moveq r0, #2304
 *   @0x17fc94 bx lr
 *   @0x17fc98 mvn r0, #0
 *   @0x17fc9c bx lr
 *   @0x17fca0 ldr r3, [pc, #0x1c]
 *   @0x17fca4 movw r2, #0x901
 *   @0x17fca8 ldr r3, [pc, r3]
 *   @0x17fcac ldr r0, [r3]
 *   @0x17fcb0 cmp r0, #1
 *   @0x17fcb4 moveq r0, r2
 *   @0x17fcb8 movne r0, #2304
 *   @0x17fcbc bx lr
 *   @0x17fcc0 eoreq r0, r7, r12, asr r4
 *   @0x17fcc4 eoreq r0, r7, r4, lsr r4
 *
 * ══ §162/289 Direction_To_Vector  0x1a2a38  size 96  24 条（0x1a2a38..0x1a2a98）
 * @func 0x1a2a38 0x1a2a98  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb658c / 0xb6580
 * 字段偏移 top8: 无
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a2a38 vmov s14, r0
 *   @0x1a2a3c vldr s15, [pc, #76]
 *   @0x1a2a40 push {r3, r4, r5, lr}
 *   @0x1a2a44 vpush {d8}
 *   @0x1a2a48 vldr s17, [pc, #68]
 *   @0x1a2a4c vmul.f32 s17, s14, s17
 *   @0x1a2a50 vmov s16, r1
 *   @0x1a2a54 mov r4, r2
 *   @0x1a2a58 mov r5, r3
 *   @0x1a2a5c vdiv.f32 s17, s17, s15
 *   @0x1a2a60 vmov r0, s17
 *   @0x1a2a64 bl 0xb658c <cosf@plt>
 *   @0x1a2a68 vmov s14, r0
 *   @0x1a2a6c vmov r0, s17
 *   @0x1a2a70 vmul.f32 s15, s14, s16
 *   @0x1a2a74 vstr s15, [r4]
 *   @0x1a2a78 bl 0xb6580 <sinf@plt>
 *   @0x1a2a7c vmov s15, r0
 *   @0x1a2a80 vnmul.f32 s16, s16, s15
 *   @0x1a2a84 vstr s16, [r5]
 *   @0x1a2a88 vpop {d8}
 *   @0x1a2a8c pop {r3, r4, r5, pc}
 *   @0x1a2a90 teqmi r4, #0
 *   @0x1a2a94 ldrdmi r0, r1, [r9], #-251
 *
 * ══ §163/289 ParticleSystem_Draw  0x1a56ac  size 96  24 条（0x1a56ac..0x1a570c）
 * @func 0x1a56ac 0x1a570c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x8×2 / 0x40×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a56ac push {r4, lr}
 *   @0x1a56b0 mov r4, r0
 *   @0x1a56b4 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a56b8 cmp r0, #0
 *   @0x1a56bc popeq {r4, pc}
 *   @0x1a56c0 ldr r3, [pc, #0x40]
 *   @0x1a56c4 ldr r3, [pc, r3]
 *   @0x1a56c8 ldr r3, [r3, #0x4]
 *   @0x1a56cc ldr r0, [r3, r4, lsl #2]
 *   @0x1a56d0 ldrb r3, [r0, #0x18]
 *   @0x1a56d4 cmp r3, #0
 *   @0x1a56d8 bne 0x1a56f4 <_Z19ParticleSystem_Drawi+0x48>
 *   @0x1a56dc ldr r1, [r0, #0x8]
 *   @0x1a56e0 mvn r2, #0
 *   @0x1a56e4 mov r3, r2
 *   @0x1a56e8 add r1, r1, r2
 *   @0x1a56ec pop {r4, lr}
 *   @0x1a56f0 b 0x1a5094 <_Z13DrawParticlesP15RParticleSystemiii>
 *   @0x1a56f4 mov r1, #0
 *   @0x1a56f8 ldr r2, [r0, #0x8]
 *   @0x1a56fc mov r3, #1
 *   @0x1a5700 pop {r4, lr}
 *   @0x1a5704 b 0x1a5094 <_Z13DrawParticlesP15RParticleSystemiii>
 *   @0x1a5708 .word 0x0024b0f4
 *
 * ══ §164/289 RTree<CInstance*, int, float, 6, 2>::AddBranch  0x1cd45c  size 96  24 条（0x1cd45c..0x1cd4bc）
 * @func 0x1cd45c 0x1cd4bc  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cd45c push {r3, r4, r5, r6, r7, lr}
 *   @0x1cd460 mov r6, r2
 *   @0x1cd464 ldr r5, [r6]
 *   @0x1cd468 mov r2, r1
 *   @0x1cd46c cmp r5, #5
 *   @0x1cd470 bgt 0x1cd4a8 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_+0x4c>
 *   @0x1cd474 mov r4, r1
 *   @0x1cd478 add r12, r5, r5, lsl #1
 *   @0x1cd47c ldm r4!, {r0, r1, r2, r3}
 *   @0x1cd480 add r12, r6, r12, lsl #3
 *   @0x1cd484 add r12, r12, #8
 *   @0x1cd488 mov r7, #0
 *   @0x1cd48c add r5, r5, #1
 *   @0x1cd490 stm r12!, {r0, r1, r2, r3}
 *   @0x1cd494 ldm r4, {r0, r1}
 *   @0x1cd498 stm r12, {r0, r1}
 *   @0x1cd49c mov r0, r7
 *   @0x1cd4a0 str r5, [r6]
 *   @0x1cd4a4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1cd4a8 mov r1, r6
 *   @0x1cd4ac mov r7, #1
 *   @0x1cd4b0 bl 0x1ccd60 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_>
 *   @0x1cd4b4 mov r0, r7
 *   @0x1cd4b8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §165/289 GetDsMap  0x2052d4  size 96  24 条（0x2052d4..0x205334）
 * @func 0x2052d4 0x205334  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetDsMap(int)+0x4c / DS_AutoMutex::DS_AutoMutex() / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x44×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2052d4 push {r4, r5, r6, lr}
 *   @0x2052d8 subs r5, r0, #0
 *   @0x2052dc sub sp, sp, #8
 *   @0x2052e0 blt 0x205320 <_Z8GetDsMapi+0x4c>
 *   @0x2052e4 ldr r4, [pc, #0x44]
 *   @0x2052e8 ldr r4, [pc, r4]
 *   @0x2052ec ldr r3, [r4]
 *   @0x2052f0 cmp r5, r3
 *   @0x2052f4 bge 0x205320 <_Z8GetDsMapi+0x4c>
 *   @0x2052f8 add r6, sp, #4
 *   @0x2052fc mov r0, r6
 *   @0x205300 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x205304 ldr r3, [r4, #0x4]
 *   @0x205308 mov r0, r6
 *   @0x20530c ldr r4, [r3, r5, lsl #2]
 *   @0x205310 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x205314 mov r0, r4
 *   @0x205318 add sp, sp, #8
 *   @0x20531c pop {r4, r5, r6, pc}
 *   @0x205320 mov r4, #0
 *   @0x205324 mov r0, r4
 *   @0x205328 add sp, sp, #8
 *   @0x20532c pop {r4, r5, r6, pc}
 *   @0x205330 andseq r8, lr, r4, asr r6
 *
 * ══ §166/289 GetJObjectToString  0x214908  size 96  24 条（0x214908..0x214968）
 * @func 0x214908 0x214968  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / YYStrDup(char const*)
 * 字段偏移 top8: 0x2a4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214908 push {r4, r5, r6, lr}
 *   @0x21490c sub sp, sp, #8
 *   @0x214910 mov r4, r0
 *   @0x214914 bl 0x290274 <getJNIEnv>
 *   @0x214918 mov r1, r4
 *   @0x21491c add r2, sp, #7
 *   @0x214920 ldr r3, [r0]
 *   @0x214924 ldr r3, [r3, #0x2a4]
 *   @0x214928 blx r3
 *   @0x21492c mov r5, r0
 *   @0x214930 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x214934 cmp r5, #0
 *   @0x214938 cmpne r4, #0
 *   @0x21493c mov r6, r0
 *   @0x214940 beq 0x21495c <_Z18GetJObjectToStringP8_jobject+0x54>
 *   @0x214944 bl 0x290274 <getJNIEnv>
 *   @0x214948 mov r1, r4
 *   @0x21494c mov r2, r5
 *   @0x214950 ldr r3, [r0]
 *   @0x214954 ldr r3, [r3, #0x2a8]
 *   @0x214958 blx r3
 *   @0x21495c mov r0, r6
 *   @0x214960 add sp, sp, #8
 *   @0x214964 pop {r4, r5, r6, pc}
 *
 * ══ §167/289 CAudioGroup::AddSound  0x21dc20  size 96  24 条（0x21dc20..0x21dc80）
 * @func 0x21dc20 0x21dc80  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x24×2 / 0x8×2 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21dc20 push {r3, r4, r5, lr}
 *   @0x21dc24 mov r4, r0
 *   @0x21dc28 ldr r3, [r0, #0x24]
 *   @0x21dc2c mov r5, r1
 *   @0x21dc30 cmp r3, #0
 *   @0x21dc34 beq 0x21dc58 <_ZN11CAudioGroup8AddSoundEP12cAudio_Sound+0x38>
 *   @0x21dc38 ldr r3, [r4, #0xc]
 *   @0x21dc3c ldr r2, [r4, #0x8]
 *   @0x21dc40 cmp r3, r2
 *   @0x21dc44 addlt r1, r3, #1
 *   @0x21dc48 strlt r1, [r4, #0xc]
 *   @0x21dc4c ldrlt r2, [r4, #0x24]
 *   @0x21dc50 strlt r5, [r2, r3, lsl #2]
 *   @0x21dc54 pop {r3, r4, r5, pc}
 *   @0x21dc58 ldr r0, [r0, #0x8]
 *   @0x21dc5c mov r2, #61
 *   @0x21dc60 ldr r1, [pc, #0x14]
 *   @0x21dc64 mov r3, #1
 *   @0x21dc68 add r1, pc, r1
 *   @0x21dc6c lsl r0, r0, #2
 *   @0x21dc70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x21dc74 str r0, [r4, #0x24]
 *   @0x21dc78 b 0x21dc38 <_ZN11CAudioGroup8AddSoundEP12cAudio_Sound+0x18>
 *   @0x21dc7c ldrsbeq r6, [r3], -r8
 *
 * ══ §168/289 ogg_stream_reset  0x235294  size 96  24 条（0x235294..0x2352f4）
 * @func 0x235294 0x2352f4  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_check
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x1c×1 / 0x20×1 / 0x24×1 / 0x144×1 / 0x148×1 / 0x14c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235294 push {r3, r4, r5, lr}
 *   @0x235298 mov r4, r0
 *   @0x23529c bl 0x23412c <ogg_stream_check>
 *   @0x2352a0 cmp r0, #0
 *   @0x2352a4 bne 0x2352ec <ogg_stream_reset+0x58>
 *   @0x2352a8 mov r5, #344
 *   @0x2352ac mov r12, #352
 *   @0x2352b0 str r0, [r4, #0x8]
 *   @0x2352b4 mov r2, #0
 *   @0x2352b8 mov r3, #0
 *   @0x2352bc str r0, [r4, #0xc]
 *   @0x2352c0 str r0, [r4, #0x1c]
 *   @0x2352c4 mvn r1, #0
 *   @0x2352c8 str r0, [r4, #0x20]
 *   @0x2352cc str r0, [r4, #0x24]
 *   @0x2352d0 str r0, [r4, #0x144]
 *   @0x2352d4 str r0, [r4, #0x148]
 *   @0x2352d8 str r0, [r4, #0x14c]
 *   @0x2352dc strd r2, r3, [r4, r5]
 *   @0x2352e0 strd r2, r3, [r4, r12]
 *   @0x2352e4 str r1, [r4, #0x154]
 *   @0x2352e8 pop {r3, r4, r5, pc}
 *   @0x2352ec mvn r0, #0
 *   @0x2352f0 pop {r3, r4, r5, pc}
 *
 * ══ §169/289 cmp_D2A  0x23d7c8  size 96  24 条（0x23d7c8..0x23d828）
 * @func 0x23d7c8 0x23d828  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×2 / 0x-4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d7c8 ldr r2, [r0, #0x10]
 *   @0x23d7cc ldr r3, [r1, #0x10]
 *   @0x23d7d0 subs r2, r2, r3
 *   @0x23d7d4 bne 0x23d818 <cmp_D2A+0x50>
 *   @0x23d7d8 lsl r2, r3, #2
 *   @0x23d7dc add r0, r0, #20
 *   @0x23d7e0 add r1, r1, #20
 *   @0x23d7e4 add r3, r0, r2
 *   @0x23d7e8 add r1, r1, r2
 *   @0x23d7ec b 0x23d7f8 <cmp_D2A+0x30>
 *   @0x23d7f0 cmp r0, r3
 *   @0x23d7f4 bhs 0x23d820 <cmp_D2A+0x58>
 *   @0x23d7f8 ldr r2, [r3, #-0x4]!
 *   @0x23d7fc ldr r12, [r1, #-0x4]!
 *   @0x23d800 cmp r2, r12
 *   @0x23d804 beq 0x23d7f0 <cmp_D2A+0x28>
 *   @0x23d808 cmp r12, r2
 *   @0x23d80c movls r0, #1
 *   @0x23d810 mvnhi r0, #0
 *   @0x23d814 bx lr
 *   @0x23d818 mov r0, r2
 *   @0x23d81c bx lr
 *   @0x23d820 mov r0, #0
 *   @0x23d824 bx lr
 *
 * ══ §170/289 IsNotCompatibleKind  0x2409a8  size 96  24 条（0x2409a8..0x240a08）
 * @func 0x2409a8 0x240a08  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2409a8 cmp r0, r1
 *   @0x2409ac beq 0x240a00 <_Z19IsNotCompatibleKindii+0x58>
 *   @0x2409b0 cmp r0, #13
 *   @0x2409b4 bhi 0x2409f0 <_Z19IsNotCompatibleKindii+0x48>
 *   @0x2409b8 mov r2, #1
 *   @0x2409bc movw r3, #0x2481
 *   @0x2409c0 lsl r0, r2, r0
 *   @0x2409c4 and r3, r0, r3
 *   @0x2409c8 cmp r3, #0
 *   @0x2409cc beq 0x2409f8 <_Z19IsNotCompatibleKindii+0x50>
 *   @0x2409d0 cmp r1, #13
 *   @0x2409d4 bhi 0x2409f8 <_Z19IsNotCompatibleKindii+0x50>
 *   @0x2409d8 lsl r1, r2, r1
 *   @0x2409dc movw r0, #0x2481
 *   @0x2409e0 and r0, r1, r0
 *   @0x2409e4 rsbs r0, r0, #1
 *   @0x2409e8 movlo r0, #0
 *   @0x2409ec bx lr
 *   @0x2409f0 mov r0, #1
 *   @0x2409f4 bx lr
 *   @0x2409f8 mov r0, r2
 *   @0x2409fc bx lr
 *   @0x240a00 mov r0, #0
 *   @0x240a04 bx lr
 *
 * ══ §171/289 spAtlasPage_create  0x284058  size 96  24 条（0x284058..0x2840b8）
 * @func 0x284058 0x2840b8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x4c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284058 push {r3, r4, r5, r6, r7, lr}
 *   @0x28405c mov r3, #37
 *   @0x284060 ldr r6, [pc, #0x4c]
 *   @0x284064 mov r5, r1
 *   @0x284068 mov r7, r0
 *   @0x28406c mov r1, #44
 *   @0x284070 add r6, pc, r6
 *   @0x284074 mov r0, #1
 *   @0x284078 mov r2, r6
 *   @0x28407c bl 0x285c4c <_calloc>
 *   @0x284080 mov r4, r0
 *   @0x284084 str r7, [r0]
 *   @0x284088 mov r0, r5
 *   @0x28408c bl 0xb6538 <strlen@plt>
 *   @0x284090 mov r1, r6
 *   @0x284094 mov r2, #39
 *   @0x284098 add r0, r0, #1
 *   @0x28409c bl 0x285c10 <_malloc>
 *   @0x2840a0 mov r1, r5
 *   @0x2840a4 str r0, [r4, #0x4]
 *   @0x2840a8 bl 0xb65a4 <strcpy@plt>
 *   @0x2840ac mov r0, r4
 *   @0x2840b0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2840b4 muleq sp, r4, r4
 *
 * ══ §172/289 spAttachmentLoader_createAttachment  0x284d58  size 96  24 条（0x284d58..0x284db8）
 * @func 0x284d58 0x284db8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284d58 push {r4, r5, r6, r7, r8, lr}
 *   @0x284d5c sub sp, sp, #8
 *   @0x284d60 mov r4, r0
 *   @0x284d64 ldr r0, [r0]
 *   @0x284d68 mov r8, r1
 *   @0x284d6c mov r7, r2
 *   @0x284d70 mov r6, r3
 *   @0x284d74 ldr r5, [sp, #0x20]
 *   @0x284d78 bl 0x285c80 <_free>
 *   @0x284d7c ldr r0, [r4, #0x4]
 *   @0x284d80 bl 0x285c80 <_free>
 *   @0x284d84 ldr r0, [r4, #0x8]
 *   @0x284d88 mov r12, #0
 *   @0x284d8c str r5, [sp]
 *   @0x284d90 mov r1, r8
 *   @0x284d94 mov r2, r7
 *   @0x284d98 ldr r5, [r0]
 *   @0x284d9c mov r3, r6
 *   @0x284da0 mov r0, r4
 *   @0x284da4 str r12, [r4]
 *   @0x284da8 str r12, [r4, #0x4]
 *   @0x284dac blx r5
 *   @0x284db0 add sp, sp, #8
 *   @0x284db4 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §173/289 GetIBuffer  0xc6754  size 92  23 条（0xc6754..0xc67b0）
 * @func 0xc6754 0xc67b0  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetIBuffer(void*)+0x48
 * 字段偏移 top8: 0x4×3 / 0x50×1 / 0x-4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6754 ldr r3, [pc, #0x50]
 *   @0xc6758 str r4, [sp, #-0x4]!
 *   @0xc675c add r3, pc, r3
 *   @0xc6760 ldr r4, [r3]
 *   @0xc6764 cmp r4, #0
 *   @0xc6768 ble 0xc679c <_Z10GetIBufferPv+0x48>
 *   @0xc676c ldr r1, [r3, #0x4]
 *   @0xc6770 mov r3, #0
 *   @0xc6774 sub r1, r1, #4
 *   @0xc6778 ldr r2, [r1, #0x4]!
 *   @0xc677c add r3, r3, #1
 *   @0xc6780 cmp r2, #0
 *   @0xc6784 beq 0xc6794 <_Z10GetIBufferPv+0x40>
 *   @0xc6788 ldr r12, [r2, #0xc]
 *   @0xc678c cmp r12, r0
 *   @0xc6790 beq 0xc67a0 <_Z10GetIBufferPv+0x4c>
 *   @0xc6794 cmp r3, r4
 *   @0xc6798 bne 0xc6778 <_Z10GetIBufferPv+0x24>
 *   @0xc679c mov r2, #0
 *   @0xc67a0 mov r0, r2
 *   @0xc67a4 ldr r4, [sp], #4
 *   @0xc67a8 bx lr
 *   @0xc67ac ldrhteq r3, [r11], -r8
 *
 * ══ §174/289 CExtensionFile::FunctionFindName  0xf4e84  size 92  23 条（0xf4e84..0xf4ee0）
 * @func 0xf4e84 0xf4ee0  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::FunctionFindName(char const*)+0x50 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4e84 push {r4, r5, r6, r7, r8, lr}
 *   @0xf4e88 mov r8, r1
 *   @0xf4e8c ldr r7, [r0, #0x1c]
 *   @0xf4e90 cmp r7, #0
 *   @0xf4e94 ble 0xf4ed4 <_ZN14CExtensionFile16FunctionFindNameEPKc+0x50>
 *   @0xf4e98 ldr r6, [r0, #0x18]
 *   @0xf4e9c mov r4, #0
 *   @0xf4ea0 sub r6, r6, #4
 *   @0xf4ea4 b 0xf4eb0 <_ZN14CExtensionFile16FunctionFindNameEPKc+0x2c>
 *   @0xf4ea8 cmp r4, r7
 *   @0xf4eac beq 0xf4ed4 <_ZN14CExtensionFile16FunctionFindNameEPKc+0x50>
 *   @0xf4eb0 ldr r5, [r6, #0x4]!
 *   @0xf4eb4 mov r1, r8
 *   @0xf4eb8 add r4, r4, #1
 *   @0xf4ebc ldr r0, [r5, #0x4]
 *   @0xf4ec0 bl 0xb6574 <strcmp@plt>
 *   @0xf4ec4 cmp r0, #0
 *   @0xf4ec8 bne 0xf4ea8 <_ZN14CExtensionFile16FunctionFindNameEPKc+0x24>
 *   @0xf4ecc mov r0, r5
 *   @0xf4ed0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xf4ed4 mov r5, #0
 *   @0xf4ed8 mov r0, r5
 *   @0xf4edc pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §175/289 Object_Exists  0x19ecf8  size 92  23 条（0x19ecf8..0x19ed54）
 * @func 0x19ecf8 0x19ed54  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x50×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19ecf8 ldr r3, [pc, #0x50]
 *   @0x19ecfc ldr r3, [pc, r3]
 *   @0x19ed00 ldr r3, [r3]
 *   @0x19ed04 ldr r2, [r3, #0x4]
 *   @0x19ed08 ldr r3, [r3]
 *   @0x19ed0c and r2, r0, r2
 *   @0x19ed10 ldr r3, [r3, r2, lsl #3]
 *   @0x19ed14 cmp r3, #0
 *   @0x19ed18 bne 0x19ed2c <_Z13Object_Existsi+0x34>
 *   @0x19ed1c b 0x19ed48 <_Z13Object_Existsi+0x50>
 *   @0x19ed20 ldr r3, [r3, #0x4]
 *   @0x19ed24 cmp r3, #0
 *   @0x19ed28 beq 0x19ed48 <_Z13Object_Existsi+0x50>
 *   @0x19ed2c ldr r2, [r3, #0x8]
 *   @0x19ed30 cmp r0, r2
 *   @0x19ed34 bne 0x19ed20 <_Z13Object_Existsi+0x28>
 *   @0x19ed38 ldr r0, [r3, #0xc]
 *   @0x19ed3c adds r0, r0, #0
 *   @0x19ed40 movne r0, #1
 *   @0x19ed44 bx lr
 *   @0x19ed48 mov r0, r3
 *   @0x19ed4c bx lr
 *   @0x19ed50 eoreq lr, r4, r0, asr #30
 *
 * ══ §176/289 MemoryInWad  0x1aad50  size 92  23 条（0x1aad50..0x1aadac）
 * @func 0x1aad50 0x1aadac  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1aad50 ldr r1, [pc, #0x4c]
 *   @0x1aad54 mov r2, r0
 *   @0x1aad58 ldr r12, [pc, #0x48]
 *   @0x1aad5c asr r3, r0, #31
 *   @0x1aad60 ldr r1, [pc, r1]
 *   @0x1aad64 ldr r12, [pc, r12]
 *   @0x1aad68 ldr r0, [r1]
 *   @0x1aad6c push {r4, r5}
 *   @0x1aad70 ldr r4, [r12]
 *   @0x1aad74 asr r1, r0, #31
 *   @0x1aad78 cmp r3, r1
 *   @0x1aad7c cmpeq r2, r0
 *   @0x1aad80 asr r5, r4, #31
 *   @0x1aad84 movhi r0, #0
 *   @0x1aad88 movls r0, #1
 *   @0x1aad8c cmp r3, r5
 *   @0x1aad90 cmpeq r2, r4
 *   @0x1aad94 pop {r4, r5}
 *   @0x1aad98 movlo r0, #0
 *   @0x1aad9c andhs r0, r0, #1
 *   @0x1aada0 bx lr
 *   @0x1aada4 eoreq r5, r4, r8, lsr #21
 *   @0x1aada8 eoreq r2, r4, r0, ror #23
 *
 * ══ §177/289 CDS_Map::CDS_Map  0x203624  size 92  23 条（0x203624..0x203680）
 * @func 0x203624 0x203680  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0
 * 字段偏移 top8: 0x3c×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203624 push {r4, r5, r6, lr}
 *   @0x203628 mov r5, r0
 *   @0x20362c mov r0, #12
 *   @0x203630 mov r6, #0
 *   @0x203634 bl 0x27c524 <_Znwj>
 *   @0x203638 ldr r1, [pc, #0x3c]
 *   @0x20363c mov r3, #255
 *   @0x203640 mov r2, #187
 *   @0x203644 add r1, pc, r1
 *   @0x203648 mov r4, r0
 *   @0x20364c str r3, [r0, #0x4]
 *   @0x203650 mov r3, #1
 *   @0x203654 str r6, [r4, #0x8]
 *   @0x203658 mov r0, #2048
 *   @0x20365c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x203660 mov r1, r6
 *   @0x203664 mov r2, #2048
 *   @0x203668 str r0, [r4]
 *   @0x20366c bl 0xb65b0 <memset@plt>
 *   @0x203670 str r4, [r5]
 *   @0x203674 mov r0, r5
 *   @0x203678 pop {r4, r5, r6, pc}
 *   @0x20367c andseq r9, r4, r8, ror #12
 *
 * ══ §178/289 hi0bits_D2A  0x23d41c  size 92  23 条（0x23d41c..0x23d478）
 * @func 0x23d41c 0x23d478  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: hi0bits_D2A+0x54
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d41c lsrs r3, r0, #16
 *   @0x23d420 lsleq r0, r0, #16
 *   @0x23d424 moveq r3, #16
 *   @0x23d428 movne r3, #0
 *   @0x23d42c tst r0, #-16777216
 *   @0x23d430 lsleq r0, r0, #8
 *   @0x23d434 addeq r3, r3, #8
 *   @0x23d438 tst r0, #-268435456
 *   @0x23d43c lsleq r0, r0, #4
 *   @0x23d440 addeq r3, r3, #4
 *   @0x23d444 tst r0, #-1073741824
 *   @0x23d448 lsleq r0, r0, #2
 *   @0x23d44c addeq r3, r3, #2
 *   @0x23d450 cmp r0, #0
 *   @0x23d454 blt 0x23d470 <hi0bits_D2A+0x54>
 *   @0x23d458 tst r0, #1073741824
 *   @0x23d45c bne 0x23d468 <hi0bits_D2A+0x4c>
 *   @0x23d460 mov r0, #32
 *   @0x23d464 bx lr
 *   @0x23d468 add r0, r3, #1
 *   @0x23d46c bx lr
 *   @0x23d470 mov r0, r3
 *   @0x23d474 bx lr
 *
 * ══ §179/289 spSkeleton_findSlotIndex  0x28a1f4  size 92  23 条（0x28a1f4..0x28a250）
 * @func 0x28a1f4 0x28a250  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findSlotIndex+0x54 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a1f4 push {r3, r4, r5, r6, r7, lr}
 *   @0x28a1f8 mov r7, r1
 *   @0x28a1fc ldr r6, [r0, #0x10]
 *   @0x28a200 cmp r6, #0
 *   @0x28a204 ble 0x28a248 <spSkeleton_findSlotIndex+0x54>
 *   @0x28a208 ldr r3, [r0]
 *   @0x28a20c mov r4, #0
 *   @0x28a210 ldr r5, [r3, #0x1c]
 *   @0x28a214 sub r5, r5, #4
 *   @0x28a218 b 0x28a228 <spSkeleton_findSlotIndex+0x34>
 *   @0x28a21c add r4, r4, #1
 *   @0x28a220 cmp r4, r6
 *   @0x28a224 beq 0x28a248 <spSkeleton_findSlotIndex+0x54>
 *   @0x28a228 ldr r3, [r5, #0x4]!
 *   @0x28a22c mov r1, r7
 *   @0x28a230 ldr r0, [r3, #0x4]
 *   @0x28a234 bl 0xb6574 <strcmp@plt>
 *   @0x28a238 cmp r0, #0
 *   @0x28a23c bne 0x28a21c <spSkeleton_findSlotIndex+0x28>
 *   @0x28a240 mov r0, r4
 *   @0x28a244 pop {r3, r4, r5, r6, r7, pc}
 *   @0x28a248 mvn r0, #0
 *   @0x28a24c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §180/289 spSkeleton_getAttachmentForSlotIndex  0x28a314  size 92  23 条（0x28a314..0x28a370）
 * @func 0x28a314 0x28a370  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkin_getAttachment
 * 字段偏移 top8: 0x38×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a314 cmn r1, #1
 *   @0x28a318 push {r4, r5, r6, lr}
 *   @0x28a31c mov r4, r1
 *   @0x28a320 mov r5, r0
 *   @0x28a324 mov r6, r2
 *   @0x28a328 beq 0x28a364 <spSkeleton_getAttachmentForSlotIndex+0x50>
 *   @0x28a32c ldr r0, [r0, #0x38]
 *   @0x28a330 cmp r0, #0
 *   @0x28a334 beq 0x28a344 <spSkeleton_getAttachmentForSlotIndex+0x30>
 *   @0x28a338 bl 0x28ed00 <spSkin_getAttachment>
 *   @0x28a33c cmp r0, #0
 *   @0x28a340 popne {r4, r5, r6, pc}
 *   @0x28a344 ldr r3, [r5]
 *   @0x28a348 ldr r0, [r3, #0x28]
 *   @0x28a34c cmp r0, #0
 *   @0x28a350 beq 0x28a36c <spSkeleton_getAttachmentForSlotIndex+0x58>
 *   @0x28a354 mov r1, r4
 *   @0x28a358 mov r2, r6
 *   @0x28a35c pop {r4, r5, r6, lr}
 *   @0x28a360 b 0x28ed00 <spSkin_getAttachment>
 *   @0x28a364 mov r0, #0
 *   @0x28a368 pop {r4, r5, r6, pc}
 *   @0x28a36c pop {r4, r5, r6, pc}
 *
 * ══ §181/289 spSkeletonBounds_dispose  0x28a858  size 92  23 条（0x28a858..0x28a8b4）
 * @func 0x28a858 0x28a8b4  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2 / spSkeletonBounds_dispose+0x40 / spPolygon_dispose
 * 字段偏移 top8: 0x1c×2 / 0x8×2 / 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a858 push {r3, r4, r5, lr}
 *   @0x28a85c mov r5, r0
 *   @0x28a860 ldr r3, [r0, #0x1c]
 *   @0x28a864 ldr r2, [r0, #0x8]
 *   @0x28a868 cmp r3, #0
 *   @0x28a86c movgt r4, #0
 *   @0x28a870 ble 0x28a898 <spSkeletonBounds_dispose+0x40>
 *   @0x28a874 ldr r0, [r2, r4, lsl #2]
 *   @0x28a878 add r4, r4, #1
 *   @0x28a87c cmp r0, #0
 *   @0x28a880 beq 0x28a890 <spSkeletonBounds_dispose+0x38>
 *   @0x28a884 bl 0x28a5b8 <spPolygon_dispose>
 *   @0x28a888 ldr r2, [r5, #0x8]
 *   @0x28a88c ldr r3, [r5, #0x1c]
 *   @0x28a890 cmp r3, r4
 *   @0x28a894 bgt 0x28a874 <spSkeletonBounds_dispose+0x1c>
 *   @0x28a898 mov r0, r2
 *   @0x28a89c bl 0x285c80 <_free>
 *   @0x28a8a0 ldr r0, [r5, #0x4]
 *   @0x28a8a4 bl 0x285c80 <_free>
 *   @0x28a8a8 mov r0, r5
 *   @0x28a8ac pop {r3, r4, r5, lr}
 *   @0x28a8b0 b 0x285c80 <_free>
 *
 * ══ §182/289 spSkeletonData_findSkin  0x28b124  size 92  23 条（0x28b124..0x28b180）
 * @func 0x28b124 0x28b180  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findSkin+0x50 / 0xb6574
 * 字段偏移 top8: 0x20×1 / 0x24×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b124 push {r4, r5, r6, r7, r8, lr}
 *   @0x28b128 mov r8, r1
 *   @0x28b12c ldr r7, [r0, #0x20]
 *   @0x28b130 cmp r7, #0
 *   @0x28b134 ble 0x28b174 <spSkeletonData_findSkin+0x50>
 *   @0x28b138 ldr r6, [r0, #0x24]
 *   @0x28b13c mov r4, #0
 *   @0x28b140 sub r6, r6, #4
 *   @0x28b144 b 0x28b150 <spSkeletonData_findSkin+0x2c>
 *   @0x28b148 cmp r4, r7
 *   @0x28b14c beq 0x28b174 <spSkeletonData_findSkin+0x50>
 *   @0x28b150 ldr r5, [r6, #0x4]!
 *   @0x28b154 mov r1, r8
 *   @0x28b158 add r4, r4, #1
 *   @0x28b15c ldr r0, [r5]
 *   @0x28b160 bl 0xb6574 <strcmp@plt>
 *   @0x28b164 cmp r0, #0
 *   @0x28b168 bne 0x28b148 <spSkeletonData_findSkin+0x24>
 *   @0x28b16c mov r0, r5
 *   @0x28b170 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28b174 mov r5, #0
 *   @0x28b178 mov r0, r5
 *   @0x28b17c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §183/289 yySocket::~yySocket  0x294cbc  size 92  23 条（0x294cbc..0x294d18）
 * @func 0x294cbc 0x294d18  size 92  23 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6d6c×2 / 0xb6d78×2 / yySocket::CommonDestructor()
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294cbc push {r4, lr}
 *   @0x294cc0 mov r4, r0
 *   @0x294cc4 bl 0x296044 <_ZN8yySocket16CommonDestructorEv>
 *   @0x294cc8 ldr r0, [r4]
 *   @0x294ccc cmn r0, #1
 *   @0x294cd0 beq 0x294cec <_ZN8yySocketD2Ev+0x30>
 *   @0x294cd4 mov r1, #2
 *   @0x294cd8 bl 0xb6d6c <shutdown@plt>
 *   @0x294cdc ldr r0, [r4]
 *   @0x294ce0 bl 0xb6d78 <close@plt>
 *   @0x294ce4 mvn r3, #0
 *   @0x294ce8 str r3, [r4]
 *   @0x294cec ldr r0, [r4, #0x4]
 *   @0x294cf0 cmn r0, #1
 *   @0x294cf4 beq 0x294d10 <_ZN8yySocketD2Ev+0x54>
 *   @0x294cf8 mov r1, #2
 *   @0x294cfc bl 0xb6d6c <shutdown@plt>
 *   @0x294d00 ldr r0, [r4, #0x4]
 *   @0x294d04 bl 0xb6d78 <close@plt>
 *   @0x294d08 mvn r3, #0
 *   @0x294d0c str r3, [r4, #0x4]
 *   @0x294d10 mov r0, r4
 *   @0x294d14 pop {r4, pc}
 *
 * ══ §184/289 CSkeletonInstance::PointCollision  0xbf374  size 88  22 条（0xbf374..0xbf3cc）
 * @func 0xbf374 0xbf3cc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) / spSkeletonBounds_containsPoint
 * 字段偏移 top8: 0x20×2 / 0x2c×1 / 0x30×1 / 0x24×1 / 0xc×1 / 0x4×1 / 0x28×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbf374 push {r4, r5, r6, lr}
 *   @0xbf378 sub sp, sp, #16
 *   @0xbf37c mov r12, #0
 *   @0xbf380 mov r6, r0
 *   @0xbf384 ldr lr, [sp, #0x20]
 *   @0xbf388 ldr r5, [sp, #0x2c]
 *   @0xbf38c ldr r4, [sp, #0x30]
 *   @0xbf390 str lr, [sp]
 *   @0xbf394 ldr lr, [sp, #0x24]
 *   @0xbf398 str r12, [sp, #0xc]
 *   @0xbf39c str lr, [sp, #0x4]
 *   @0xbf3a0 ldr lr, [sp, #0x28]
 *   @0xbf3a4 str lr, [sp, #0x8]
 *   @0xbf3a8 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbf3ac ldr r0, [r6, #0x20]
 *   @0xbf3b0 mov r1, r5
 *   @0xbf3b4 mov r2, r4
 *   @0xbf3b8 bl 0x28ac8c <spSkeletonBounds_containsPoint>
 *   @0xbf3bc adds r0, r0, #0
 *   @0xbf3c0 movne r0, #1
 *   @0xbf3c4 add sp, sp, #16
 *   @0xbf3c8 pop {r4, r5, r6, pc}
 *
 * ══ §185/289 GR_Texture_Free  0x173f84  size 88  22 条（0x173f84..0x173fdc）
 * @func 0x173f84 0x173fdc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / Graphics::FreeTexture(void*)
 * 字段偏移 top8: 0x2×3 / 0x4×2 / 0x38×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173f84 push {r3, r4, r5, lr}
 *   @0x173f88 mov r5, r0
 *   @0x173f8c bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x173f90 cmp r0, #0
 *   @0x173f94 popeq {r3, r4, r5, pc}
 *   @0x173f98 ldr r4, [pc, #0x38]
 *   @0x173f9c ldr r4, [pc, r4]
 *   @0x173fa0 ldr r3, [r4, #0x4]
 *   @0x173fa4 ldr r3, [r3, r5, lsl #2]
 *   @0x173fa8 ldr r0, [r3]
 *   @0x173fac cmp r0, #0
 *   @0x173fb0 beq 0x173fcc <_Z15GR_Texture_Freei+0x48>
 *   @0x173fb4 bl 0x180f98 <_ZN8Graphics11FreeTextureEPv>
 *   @0x173fb8 ldr r3, [r4, #0x4]
 *   @0x173fbc mov r1, #0
 *   @0x173fc0 ldr r2, [r3, r5, lsl #2]
 *   @0x173fc4 str r1, [r2]
 *   @0x173fc8 ldr r3, [r3, r5, lsl #2]
 *   @0x173fcc mov r2, #0
 *   @0x173fd0 strb r2, [r3, #0x10]
 *   @0x173fd4 pop {r3, r4, r5, pc}
 *   @0x173fd8 eoreq r9, r7, r0, lsl #19
 *
 * ══ §186/289 ParticleSystem_Emitter_Exists  0x1a3854  size 88  22 条（0x1a3854..0x1a38ac）
 * @func 0x1a3854 0x1a38ac  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int) / ParticleSystem_Emitter_Exists(int, int)+0x4c
 * 字段偏移 top8: 0x2×2 / 0x2c×1 / 0x4×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3854 push {r3, r4, r5, lr}
 *   @0x1a3858 mov r4, r1
 *   @0x1a385c mov r5, r0
 *   @0x1a3860 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a3864 cmp r0, #0
 *   @0x1a3868 popeq {r3, r4, r5, pc}
 *   @0x1a386c cmp r4, #0
 *   @0x1a3870 blt 0x1a38a0 <_Z29ParticleSystem_Emitter_Existsii+0x4c>
 *   @0x1a3874 ldr r3, [pc, #0x2c]
 *   @0x1a3878 ldr r3, [pc, r3]
 *   @0x1a387c ldr r3, [r3, #0x4]
 *   @0x1a3880 ldr r3, [r3, r5, lsl #2]
 *   @0x1a3884 ldr r2, [r3, #0x14]
 *   @0x1a3888 cmp r4, r2
 *   @0x1a388c bge 0x1a38a0 <_Z29ParticleSystem_Emitter_Existsii+0x4c>
 *   @0x1a3890 ldr r3, [r3, #0x10]
 *   @0x1a3894 ldr r3, [r3, r4, lsl #2]
 *   @0x1a3898 ldrb r0, [r3]
 *   @0x1a389c pop {r3, r4, r5, pc}
 *   @0x1a38a0 mov r0, #0
 *   @0x1a38a4 pop {r3, r4, r5, pc}
 *   @0x1a38a8 eoreq r12, r4, r0, asr #30
 *
 * ══ §187/289 Shader_Set  0x1e2024  size 88  22 条（0x1e2024..0x1e207c）
 * @func 0x1e2024 0x1e207c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1e2028→0x544c7c, 0x1e2040→0x544c80, 0x1e2044→0x544c78
 * 调用序列: 无
 * 字段偏移 top8: 0x40×2 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2024 ldr r3, [pc, #0x40]
 *   @0x1e2028 ldr r2, [pc, #0x40]
 *   @0x1e202c add r3, pc, r3
 *   @0x1e2030 ldr r2, [r3, r2]
 *   @0x1e2034 ldr r1, [r2]
 *   @0x1e2038 cmp r1, r0
 *   @0x1e203c bxeq lr
 *   @0x1e2040 ldr r1, [pc, #0x2c]
 *   @0x1e2044 ldr r12, [pc, #0x2c]
 *   @0x1e2048 ldr r1, [r3, r1]
 *   @0x1e204c ldr r3, [r3, r12]
 *   @0x1e2050 str r0, [r2]
 *   @0x1e2054 ldr r1, [r1]
 *   @0x1e2058 cmp r1, r0
 *   @0x1e205c moveq r1, #0
 *   @0x1e2060 movne r1, #1
 *   @0x1e2064 strb r1, [r3]
 *   @0x1e2068 bx lr
 *   @0x1e206c eoreq pc, r0, r4, lsr #24
 *   @0x1e2070 .word 0xfffff0f0
 *   @0x1e2074 .word 0xffffe828
 *   @0x1e2078 .word 0xfffff0fc
 *
 * ══ §188/289 DsQueueSize  0x2055c8  size 88  22 条（0x2055c8..0x205620）
 * @func 0x2055c8 0x205620  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DsQueueSize(int)+0x50 / F_DsQueueSize(RValue&, CInstance*, CInstance*, int, RValue*) / 0xb66e8
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x24×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2055c8 cmp r0, #0
 *   @0x2055cc str lr, [sp, #-0x4]!
 *   @0x2055d0 movlt r0, #0
 *   @0x2055d4 sub sp, sp, #44
 *   @0x2055d8 blt 0x205618 <_Z11DsQueueSizei+0x50>
 *   @0x2055dc vmov s13, r0
 *   @0x2055e0 mov r12, #0
 *   @0x2055e4 mov r1, r12
 *   @0x2055e8 add r3, sp, #24
 *   @0x2055ec vcvt.f64.s32 d7, s13
 *   @0x2055f0 str r3, [sp]
 *   @0x2055f4 add r0, sp, #8
 *   @0x2055f8 mov r2, r12
 *   @0x2055fc mov r3, #1
 *   @0x205600 str r12, [sp, #0x8]
 *   @0x205604 str r12, [sp, #0x24]
 *   @0x205608 vstr d7, [sp, #24]
 *   @0x20560c bl 0xfbf24 <_Z13F_DsQueueSizeR6RValueP9CInstanceS2_iPS_>
 *   @0x205610 ldrd r0, r1, [sp, #8]
 *   @0x205614 bl 0xb66e8 <lrint@plt>
 *   @0x205618 add sp, sp, #44
 *   @0x20561c ldr pc, [sp], #4
 *
 * ══ §189/289 json_object_new_object  0x27e89c  size 88  22 条（0x27e89c..0x27e8f4）
 * @func 0x27e89c 0x27e8f4  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_27e408+0x31c / lh_kchar_table_new
 * 字段偏移 top8: 0x30×1 / 0x2c×1 / 0x28×1 / 0x4×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e89c push {r4, lr}
 *   @0x27e8a0 mov r0, #4
 *   @0x27e8a4 bl 0x27e724 <mc_info+0x35c>
 *   @0x27e8a8 subs r4, r0, #0
 *   @0x27e8ac beq 0x27e8e0 <json_object_new_object+0x44>
 *   @0x27e8b0 ldr r12, [pc, #0x30]
 *   @0x27e8b4 mov r0, #16
 *   @0x27e8b8 ldr r3, [pc, #0x2c]
 *   @0x27e8bc mov r1, #0
 *   @0x27e8c0 ldr r2, [pc, #0x28]
 *   @0x27e8c4 add r12, pc, r12
 *   @0x27e8c8 add r3, pc, r3
 *   @0x27e8cc str r12, [r4, #0x4]
 *   @0x27e8d0 add r2, pc, r2
 *   @0x27e8d4 str r3, [r4, #0x8]
 *   @0x27e8d8 bl 0x2808ec <lh_kchar_table_new>
 *   @0x27e8dc str r0, [r4, #0x18]
 *   @0x27e8e0 mov r0, r4
 *   @0x27e8e4 pop {r4, pc}
 *   @0x27e8e8 .word 0xfffffe10
 *   @0x27e8ec andeq r0, r0, r0, asr #32
 *   @0x27e8f0 .word 0xffffff1c
 *
 * ══ §190/289 printbuf_new  0x280cc8  size 88  22 条（0x280cc8..0x280d20）
 * @func 0x280cc8 0x280d20  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34 / 0xb6544 / 0xb655c
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280cc8 push {r3, r4, r5, lr}
 *   @0x280ccc mov r0, #1
 *   @0x280cd0 mov r1, #12
 *   @0x280cd4 bl 0xb6c34 <calloc@plt>
 *   @0x280cd8 subs r4, r0, #0
 *   @0x280cdc beq 0x280d0c <printbuf_new+0x44>
 *   @0x280ce0 mov r0, #32
 *   @0x280ce4 mov r3, #0
 *   @0x280ce8 str r0, [r4, #0x8]
 *   @0x280cec str r3, [r4, #0x4]
 *   @0x280cf0 bl 0xb6544 <malloc@plt>
 *   @0x280cf4 mov r5, r0
 *   @0x280cf8 cmp r5, #0
 *   @0x280cfc mov r0, r4
 *   @0x280d00 str r5, [r4]
 *   @0x280d04 beq 0x280d14 <printbuf_new+0x4c>
 *   @0x280d08 pop {r3, r4, r5, pc}
 *   @0x280d0c mov r0, r4
 *   @0x280d10 pop {r3, r4, r5, pc}
 *   @0x280d14 bl 0xb655c <free@plt>
 *   @0x280d18 mov r0, r5
 *   @0x280d1c pop {r3, r4, r5, pc}
 *
 * ══ §191/289 spAnimationStateData_dispose  0x283b58  size 88  22 条（0x283b58..0x283bb0）
 * @func 0x283b58 0x283bb0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _ToEntry_dispose / _FromEntry_dispose
 * 字段偏移 top8: 0x8×3 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283b58 push {r4, r5, r6, lr}
 *   @0x283b5c mov r6, r0
 *   @0x283b60 ldr r5, [r0, #0x8]
 *   @0x283b64 cmp r5, #0
 *   @0x283b68 beq 0x283ba4 <spAnimationStateData_dispose+0x4c>
 *   @0x283b6c ldr r0, [r5, #0x4]
 *   @0x283b70 cmp r0, #0
 *   @0x283b74 beq 0x283b8c <spAnimationStateData_dispose+0x34>
 *   @0x283b78 ldr r4, [r0, #0x8]
 *   @0x283b7c bl 0x283af8 <_ToEntry_dispose>
 *   @0x283b80 cmp r4, #0
 *   @0x283b84 mov r0, r4
 *   @0x283b88 bne 0x283b78 <spAnimationStateData_dispose+0x20>
 *   @0x283b8c ldr r4, [r5, #0x8]
 *   @0x283b90 mov r0, r5
 *   @0x283b94 bl 0x283b28 <_FromEntry_dispose>
 *   @0x283b98 cmp r4, #0
 *   @0x283b9c movne r5, r4
 *   @0x283ba0 bne 0x283b6c <spAnimationStateData_dispose+0x14>
 *   @0x283ba4 mov r0, r6
 *   @0x283ba8 pop {r4, r5, r6, lr}
 *   @0x283bac b 0x285c80 <_free>
 *
 * ══ §192/289 spSkin_getAttachment  0x28ed00  size 88  22 条（0x28ed00..0x28ed58）
 * @func 0x28ed00 0x28ed58  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ed00 push {r4, r5, r6, lr}
 *   @0x28ed04 mov r5, r1
 *   @0x28ed08 ldr r4, [r0, #0x4]
 *   @0x28ed0c mov r6, r2
 *   @0x28ed10 cmp r4, #0
 *   @0x28ed14 bne 0x28ed28 <spSkin_getAttachment+0x28>
 *   @0x28ed18 b 0x28ed50 <spSkin_getAttachment+0x50>
 *   @0x28ed1c ldr r4, [r4, #0xc]
 *   @0x28ed20 cmp r4, #0
 *   @0x28ed24 beq 0x28ed50 <spSkin_getAttachment+0x50>
 *   @0x28ed28 ldr r3, [r4]
 *   @0x28ed2c cmp r3, r5
 *   @0x28ed30 bne 0x28ed1c <spSkin_getAttachment+0x1c>
 *   @0x28ed34 ldr r0, [r4, #0x4]
 *   @0x28ed38 mov r1, r6
 *   @0x28ed3c bl 0xb6574 <strcmp@plt>
 *   @0x28ed40 cmp r0, #0
 *   @0x28ed44 bne 0x28ed1c <spSkin_getAttachment+0x1c>
 *   @0x28ed48 ldr r0, [r4, #0x8]
 *   @0x28ed4c pop {r4, r5, r6, pc}
 *   @0x28ed50 mov r0, r4
 *   @0x28ed54 pop {r4, r5, r6, pc}
 *
 * ══ §193/289 yyServer::~yyServer  0x297184  size 88  22 条（0x297184..0x2971dc）
 * @func 0x297184 0x2971dc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / yySocket::~yySocket() / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x297184 push {r3, r4, r5, lr}
 *   @0x297188 mov r4, r0
 *   @0x29718c ldr r5, [r0]
 *   @0x297190 cmp r5, #0
 *   @0x297194 beq 0x2971a8 <_ZN8yyServerD2Ev+0x24>
 *   @0x297198 mov r0, r5
 *   @0x29719c bl 0x294cbc <_ZN8yySocketD2Ev>
 *   @0x2971a0 mov r0, r5
 *   @0x2971a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2971a8 mov r5, #0
 *   @0x2971ac ldr r0, [r4, #0x4]
 *   @0x2971b0 str r5, [r4]
 *   @0x2971b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2971b8 ldr r0, [r4, #0x8]
 *   @0x2971bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2971c0 ldr r0, [r4, #0xc]
 *   @0x2971c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2971c8 str r5, [r4, #0x4]
 *   @0x2971cc str r5, [r4, #0x8]
 *   @0x2971d0 mov r0, r4
 *   @0x2971d4 str r5, [r4, #0xc]
 *   @0x2971d8 pop {r3, r4, r5, pc}
 *
 * ══ §194/289 TErrStreamConsole::TErrStreamConsole  0xd4190  size 84  21 条（0xd4190..0xd41e4）
 * @func 0xd4190 0xd41e4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x44×1 / 0x40×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd4190 ldr r3, [pc, #0x44]
 *   @0xd4194 mov r2, #516
 *   @0xd4198 ldr r1, [pc, #0x40]
 *   @0xd419c push {r4, lr}
 *   @0xd41a0 ldr r3, [pc, r3]
 *   @0xd41a4 mov r4, r0
 *   @0xd41a8 add r1, pc, r1
 *   @0xd41ac mov r0, #102400
 *   @0xd41b0 add r3, r3, #8
 *   @0xd41b4 str r0, [r4, #0x4]
 *   @0xd41b8 str r3, [r4]
 *   @0xd41bc mov r3, #0
 *   @0xd41c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd41c4 mov r2, #0
 *   @0xd41c8 mov r3, r0
 *   @0xd41cc str r0, [r4, #0x8]
 *   @0xd41d0 mov r0, r4
 *   @0xd41d4 strb r2, [r3]
 *   @0xd41d8 pop {r4, pc}
 *   @0xd41dc eorseq r9, r1, r8, lsr #20
 *   @0xd41e0 .word 0x0025e5d4
 *
 * ══ §195/289 DS_AutoMutex::DS_AutoMutex  0xfec18  size 84  21 条（0xfec18..0xfec6c）
 * @func 0xfec18 0xfec6c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / 0xb6544 / Mutex::Init(char const*)
 * 字段偏移 top8: 0x3c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfec18 push {r3, r4, r5, lr}
 *   @0xfec1c mov r5, r0
 *   @0xfec20 ldr r4, [pc, #0x3c]
 *   @0xfec24 ldr r4, [pc, r4]
 *   @0xfec28 ldr r3, [r4]
 *   @0xfec2c cmp r3, #0
 *   @0xfec30 movne r0, r3
 *   @0xfec34 beq 0xfec44 <_ZN12DS_AutoMutexC2Ev+0x2c>
 *   @0xfec38 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0xfec3c mov r0, r5
 *   @0xfec40 pop {r3, r4, r5, pc}
 *   @0xfec44 mov r0, #8
 *   @0xfec48 bl 0xb6544 <malloc@plt>
 *   @0xfec4c ldr r1, [pc, #0x14]
 *   @0xfec50 add r1, pc, r1
 *   @0xfec54 str r0, [r4]
 *   @0xfec58 bl 0x27e038 <_ZN5Mutex4InitEPKc>
 *   @0xfec5c ldr r0, [r4]
 *   @0xfec60 b 0xfec38 <_ZN12DS_AutoMutexC2Ev+0x20>
 *   @0xfec64 eoreq pc, lr, r8, ror #4
 *   @0xfec68 eoreq r9, r3, r0, lsl r0
 *
 * ══ §196/289 CCameraManager::StartRoom  0x16ec9c  size 84  21 条（0x16ec9c..0x16ecf0）
 * @func 0x16ec9c 0x16ecf0  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CInstance::CInstance(float, float, int, int, bool)
 * 字段偏移 top8: 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ec9c push {r4, r5, r6, lr}
 *   @0x16eca0 mov r5, r0
 *   @0x16eca4 ldr r4, [r0, #0x8]
 *   @0x16eca8 sub sp, sp, #8
 *   @0x16ecac cmp r4, #0
 *   @0x16ecb0 beq 0x16ecbc <_ZN14CCameraManager9StartRoomEv+0x20>
 *   @0x16ecb4 add sp, sp, #8
 *   @0x16ecb8 pop {r4, r5, r6, pc}
 *   @0x16ecbc mov r0, #432
 *   @0x16ecc0 bl 0x27c524 <_Znwj>
 *   @0x16ecc4 mov r1, #0
 *   @0x16ecc8 mov r3, r4
 *   @0x16eccc str r4, [sp, #0x4]
 *   @0x16ecd0 mvn r2, #0
 *   @0x16ecd4 str r2, [sp]
 *   @0x16ecd8 mov r2, r1
 *   @0x16ecdc mov r6, r0
 *   @0x16ece0 bl 0x1994dc <_ZN9CInstanceC2Effiib>
 *   @0x16ece4 str r6, [r5, #0x8]
 *   @0x16ece8 add sp, sp, #8
 *   @0x16ecec pop {r4, r5, r6, pc}
 *
 * ══ §197/289 _FreeSurfaceData  0x171a90  size 84  21 条（0x171a90..0x171ae4）
 * @func 0x171a90 0x171ae4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int) / GR_Texture_Free(int) / YYGML_surface_reset_target()
 * 字段偏移 top8: 0x4×2 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171a90 push {r3, r4, r5, lr}
 *   @0x171a94 mov r4, r0
 *   @0x171a98 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x171a9c subs r5, r0, #0
 *   @0x171aa0 beq 0x171ad0 <_Z16_FreeSurfaceDatai+0x40>
 *   @0x171aa4 ldr r2, [pc, #0x34]
 *   @0x171aa8 ldr r2, [pc, r2]
 *   @0x171aac sub r3, r2, #4
 *   @0x171ab0 add r1, r2, #12
 *   @0x171ab4 ldr r2, [r3, #0x4]!
 *   @0x171ab8 cmp r2, r4
 *   @0x171abc beq 0x171ad8 <_Z16_FreeSurfaceDatai+0x48>
 *   @0x171ac0 cmp r3, r1
 *   @0x171ac4 bne 0x171ab4 <_Z16_FreeSurfaceDatai+0x24>
 *   @0x171ac8 ldr r0, [r5, #0x4]
 *   @0x171acc bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0x171ad0 mov r0, r5
 *   @0x171ad4 pop {r3, r4, r5, pc}
 *   @0x171ad8 bl 0x171808 <_Z26YYGML_surface_reset_targetv>
 *   @0x171adc b 0x171ac8 <_Z16_FreeSurfaceDatai+0x38>
 *   @0x171ae0 eoreq lr, r7, r4, asr #13
 *
 * ══ §198/289 GR_Window_View_UnDefine  0x179cac  size 84  21 条（0x179cac..0x179d00）
 * @func 0x179cac 0x179d00  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×1 / 0x4×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179cac cmp r0, #31
 *   @0x179cb0 bxhi lr
 *   @0x179cb4 ldr r3, [pc, #0x3c]
 *   @0x179cb8 lsl r2, r0, #1
 *   @0x179cbc add r1, r2, r0
 *   @0x179cc0 ldr r3, [pc, r3]
 *   @0x179cc4 ldrb r1, [r3, r1, lsl #4]
 *   @0x179cc8 cmp r1, #0
 *   @0x179ccc beq 0x179ce4 <_Z23GR_Window_View_UnDefinei+0x38>
 *   @0x179cd0 ldr r1, [pc, #0x24]
 *   @0x179cd4 ldr r1, [pc, r1]
 *   @0x179cd8 ldr r12, [r1]
 *   @0x179cdc sub r12, r12, #1
 *   @0x179ce0 str r12, [r1]
 *   @0x179ce4 add r2, r2, r0
 *   @0x179ce8 mov r1, #0
 *   @0x179cec lsl r2, r2, #4
 *   @0x179cf0 strb r1, [r3, r2]
 *   @0x179cf4 bx lr
 *   @0x179cf8 eoreq r6, r7, r0, asr #12
 *   @0x179cfc eoreq r6, r7, r0, lsr r6
 *
 * ══ §199/289 GetPOW2Size  0x181320  size 84  21 条（0x181320..0x181374）
 * @func 0x181320 0x181374  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetPOW2Size(int)+0x38 / GetPOW2Size(int)+0x48 / GetPOW2Size(int)+0x40 / GetPOW2Size(int)+0x24
 * 字段偏移 top8: 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x181320 ldr r3, [pc, #0x48]
 *   @0x181324 ldr r3, [pc, r3]
 *   @0x181328 ldr r2, [r3]
 *   @0x18132c cmp r2, #0
 *   @0x181330 ble 0x181358 <_Z11GetPOW2Sizei+0x38>
 *   @0x181334 cmp r0, #1
 *   @0x181338 ble 0x181368 <_Z11GetPOW2Sizei+0x48>
 *   @0x18133c mov r3, #1
 *   @0x181340 b 0x18134c <_Z11GetPOW2Sizei+0x2c>
 *   @0x181344 cmp r0, r3
 *   @0x181348 ble 0x181360 <_Z11GetPOW2Sizei+0x40>
 *   @0x18134c lsl r3, r3, #1
 *   @0x181350 cmp r3, r2
 *   @0x181354 ble 0x181344 <_Z11GetPOW2Sizei+0x24>
 *   @0x181358 mov r0, r2
 *   @0x18135c bx lr
 *   @0x181360 mov r0, r3
 *   @0x181364 bx lr
 *   @0x181368 mov r0, #1
 *   @0x18136c bx lr
 *   @0x181370 eoreq pc, r6, r12, ror #1
 *
 * ══ §200/289 CDS_Queue::CDS_Queue  0x20ed58  size 84  21 条（0x20ed58..0x20edac）
 * @func 0x20ed58 0x20edac  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Queue::Clear()
 * 字段偏移 top8: 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0xd×1 / 0xe×1 / 0xf×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20ed58 ldr r2, [pc, #0x48]
 *   @0x20ed5c mov r3, #0
 *   @0x20ed60 push {r4, lr}
 *   @0x20ed64 ldr r2, [pc, r2]
 *   @0x20ed68 mov r4, r0
 *   @0x20ed6c str r3, [r0, #0x4]
 *   @0x20ed70 str r3, [r0, #0x8]
 *   @0x20ed74 add r2, r2, #8
 *   @0x20ed78 strb r3, [r0, #0xc]
 *   @0x20ed7c str r2, [r0]
 *   @0x20ed80 strb r3, [r0, #0xd]
 *   @0x20ed84 strb r3, [r0, #0xe]
 *   @0x20ed88 strb r3, [r0, #0xf]
 *   @0x20ed8c strb r3, [r0, #0x10]
 *   @0x20ed90 strb r3, [r0, #0x11]
 *   @0x20ed94 strb r3, [r0, #0x12]
 *   @0x20ed98 strb r3, [r0, #0x13]
 *   @0x20ed9c bl 0x20eacc <_ZN9CDS_Queue5ClearEv>
 *   @0x20eda0 mov r0, r4
 *   @0x20eda4 pop {r4, pc}
 *   @0x20eda8 andseq r2, lr, r0, asr #12
 *
 * ══ §201/289 ogg_stream_clear  0x234150  size 84  21 条（0x234150..0x2341a4）
 * @func 0x234150 0x2341a4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×3 / 0xb65b0
 * 字段偏移 top8: 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234150 push {r4, lr}
 *   @0x234154 subs r4, r0, #0
 *   @0x234158 beq 0x23419c <ogg_stream_clear+0x4c>
 *   @0x23415c ldr r0, [r4]
 *   @0x234160 cmp r0, #0
 *   @0x234164 beq 0x23416c <ogg_stream_clear+0x1c>
 *   @0x234168 bl 0xb655c <free@plt>
 *   @0x23416c ldr r0, [r4, #0x10]
 *   @0x234170 cmp r0, #0
 *   @0x234174 beq 0x23417c <ogg_stream_clear+0x2c>
 *   @0x234178 bl 0xb655c <free@plt>
 *   @0x23417c ldr r0, [r4, #0x14]
 *   @0x234180 cmp r0, #0
 *   @0x234184 beq 0x23418c <ogg_stream_clear+0x3c>
 *   @0x234188 bl 0xb655c <free@plt>
 *   @0x23418c mov r0, r4
 *   @0x234190 mov r1, #0
 *   @0x234194 mov r2, #360
 *   @0x234198 bl 0xb65b0 <memset@plt>
 *   @0x23419c mov r0, #0
 *   @0x2341a0 pop {r4, pc}
 *
 * ══ §202/289 nrv_alloc_D2A  0x23dd14  size 84  21 条（0x23dd14..0x23dd68）
 * @func 0x23dd14 0x23dd68  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: rv_alloc_D2A
 * 字段偏移 top8: 0x1×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23dd14 push {r3, r4, r5, lr}
 *   @0x23dd18 mov r4, r0
 *   @0x23dd1c mov r0, r2
 *   @0x23dd20 mov r5, r1
 *   @0x23dd24 bl 0x23dcc4 <rv_alloc_D2A>
 *   @0x23dd28 ldrb r3, [r4]
 *   @0x23dd2c cmp r3, #0
 *   @0x23dd30 strb r3, [r0]
 *   @0x23dd34 beq 0x23dd60 <nrv_alloc_D2A+0x4c>
 *   @0x23dd38 add r3, r0, #1
 *   @0x23dd3c mov r12, r4
 *   @0x23dd40 ldrb r2, [r12, #0x1]!
 *   @0x23dd44 mov r4, r3
 *   @0x23dd48 cmp r2, #0
 *   @0x23dd4c strb r2, [r3], #1
 *   @0x23dd50 bne 0x23dd40 <nrv_alloc_D2A+0x2c>
 *   @0x23dd54 cmp r5, #0
 *   @0x23dd58 strne r4, [r5]
 *   @0x23dd5c pop {r3, r4, r5, pc}
 *   @0x23dd60 mov r4, r0
 *   @0x23dd64 b 0x23dd54 <nrv_alloc_D2A+0x40>
 *
 * ══ §203/289 spAnimationState_dispose  0x2831cc  size 84  21 条（0x2831cc..0x283220）
 * @func 0x2831cc 0x283220  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2 / spAnimationState_dispose+0x40 / _spAnimationState_disposeAllEntries
 * 字段偏移 top8: 0xc×2 / 0x10×2 / 0x18×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2831cc push {r3, r4, r5, lr}
 *   @0x2831d0 mov r5, r0
 *   @0x2831d4 ldr r0, [r0, #0x18]
 *   @0x2831d8 bl 0x285c80 <_free>
 *   @0x2831dc ldr r3, [r5, #0xc]
 *   @0x2831e0 cmp r3, #0
 *   @0x2831e4 movgt r4, #0
 *   @0x2831e8 ble 0x28320c <spAnimationState_dispose+0x40>
 *   @0x2831ec ldr r3, [r5, #0x10]
 *   @0x2831f0 mov r0, r5
 *   @0x2831f4 ldr r1, [r3, r4, lsl #2]
 *   @0x2831f8 add r4, r4, #1
 *   @0x2831fc bl 0x28319c <_spAnimationState_disposeAllEntries>
 *   @0x283200 ldr r3, [r5, #0xc]
 *   @0x283204 cmp r3, r4
 *   @0x283208 bgt 0x2831ec <spAnimationState_dispose+0x20>
 *   @0x28320c ldr r0, [r5, #0x10]
 *   @0x283210 bl 0x285c80 <_free>
 *   @0x283214 mov r0, r5
 *   @0x283218 pop {r3, r4, r5, lr}
 *   @0x28321c b 0x285c80 <_free>
 *
 * ══ §204/289 spAtlas_dispose  0x284120  size 84  21 条（0x284120..0x284174）
 * @func 0x284120 0x284174  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAtlasPage_dispose / spAtlasRegion_dispose
 * 字段偏移 top8: 0x28×1 / 0x4×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284120 push {r3, r4, r5, lr}
 *   @0x284124 mov r5, r0
 *   @0x284128 ldr r0, [r0]
 *   @0x28412c cmp r0, #0
 *   @0x284130 beq 0x284148 <spAtlas_dispose+0x28>
 *   @0x284134 ldr r4, [r0, #0x28]
 *   @0x284138 bl 0x2840b8 <spAtlasPage_dispose>
 *   @0x28413c cmp r4, #0
 *   @0x284140 mov r0, r4
 *   @0x284144 bne 0x284134 <spAtlas_dispose+0x14>
 *   @0x284148 ldr r0, [r5, #0x4]
 *   @0x28414c cmp r0, #0
 *   @0x284150 beq 0x284168 <spAtlas_dispose+0x48>
 *   @0x284154 ldr r4, [r0, #0x4c]
 *   @0x284158 bl 0x2840f4 <spAtlasRegion_dispose>
 *   @0x28415c cmp r4, #0
 *   @0x284160 mov r0, r4
 *   @0x284164 bne 0x284154 <spAtlas_dispose+0x34>
 *   @0x284168 mov r0, r5
 *   @0x28416c pop {r3, r4, r5, lr}
 *   @0x284170 b 0x285c80 <_free>
 *
 * ══ §205/289 __fixunsdfsi  0x31b0d0  size 84  21 条（0x31b0d0..0x31b124）
 * @func 0x31b0d0 0x31b124  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b0d0 lsls r2, r1, #1
 *   @0x31b0d4 bhs 0x31b104 <__fixunsdfsi+0x34>
 *   @0x31b0d8 adds r2, r2, #2097152
 *   @0x31b0dc bhs 0x31b10c <__fixunsdfsi+0x3c>
 *   @0x31b0e0 bpl 0x31b104 <__fixunsdfsi+0x34>
 *   @0x31b0e4 mvn r3, #992
 *   @0x31b0e8 subs r2, r3, r2, asr #21
 *   @0x31b0ec bmi 0x31b114 <__fixunsdfsi+0x44>
 *   @0x31b0f0 lsl r3, r1, #11
 *   @0x31b0f4 orr r3, r3, #-2147483648
 *   @0x31b0f8 orr r3, r3, r0, lsr #21
 *   @0x31b0fc lsr r0, r3, r2
 *   @0x31b100 bx lr
 *   @0x31b104 mov r0, #0
 *   @0x31b108 bx lr
 *   @0x31b10c orrs r0, r0, r1, lsl #12
 *   @0x31b110 bne 0x31b11c <__fixunsdfsi+0x4c>
 *   @0x31b114 mvn r0, #0
 *   @0x31b118 bx lr
 *   @0x31b11c mov r0, #0
 *   @0x31b120 bx lr
 *
 * ══ §206/289 CSkeletonInstance::CSkeletonInstance  0xbe67c  size 80  20 条（0xbe67c..0xbe6cc）
 * @func 0xbe67c 0xbe6cc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::SetupSkeletonData(spSkeletonData*)
 * 字段偏移 top8: 0x4×2 / 0x5×1 / 0x10×1 / 0x14×1 / 0x18×1 / 0x1c×1 / 0x20×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe67c ldr r1, [r1, #0x4]
 *   @0xbe680 mov r3, #0
 *   @0xbe684 push {r4, lr}
 *   @0xbe688 cmp r1, r3
 *   @0xbe68c mov r4, r0
 *   @0xbe690 str r3, [r0]
 *   @0xbe694 strb r3, [r0, #0x4]
 *   @0xbe698 strb r3, [r0, #0x5]
 *   @0xbe69c str r3, [r0, #0x10]
 *   @0xbe6a0 str r3, [r0, #0x14]
 *   @0xbe6a4 str r3, [r0, #0x18]
 *   @0xbe6a8 str r3, [r0, #0x1c]
 *   @0xbe6ac str r3, [r0, #0x20]
 *   @0xbe6b0 str r3, [r0, #0x28]
 *   @0xbe6b4 str r3, [r0, #0x2c]
 *   @0xbe6b8 str r3, [r0, #0x30]
 *   @0xbe6bc beq 0xbe6c4 <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite+0x48>
 *   @0xbe6c0 bl 0xbe5dc <_ZN17CSkeletonInstance17SetupSkeletonDataEP14spSkeletonData>
 *   @0xbe6c4 mov r0, r4
 *   @0xbe6c8 pop {r4, pc}
 *
 * ══ §207/289 ShowMessage  0xc4b0c  size 80  20 条（0xc4b0c..0xc4b5c）
 * @func 0xc4b0c 0xc4b5c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4b0c push {r4, lr}
 *   @0xc4b10 mov r4, r0
 *   @0xc4b14 bl 0x290274 <getJNIEnv>
 *   @0xc4b18 mov r1, r4
 *   @0xc4b1c ldr r3, [r0]
 *   @0xc4b20 ldr r3, [r3, #0x29c]
 *   @0xc4b24 blx r3
 *   @0xc4b28 mov r4, r0
 *   @0xc4b2c bl 0x290274 <getJNIEnv>
 *   @0xc4b30 ldr r1, [pc, #0x1c]
 *   @0xc4b34 mov r3, r4
 *   @0xc4b38 ldr r2, [pc, #0x18]
 *   @0xc4b3c ldr r1, [pc, r1]
 *   @0xc4b40 ldr r2, [pc, r2]
 *   @0xc4b44 ldr r1, [r1]
 *   @0xc4b48 ldr r2, [r2]
 *   @0xc4b4c pop {r4, lr}
 *   @0xc4b50 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0xc4b54 eorseq r8, r2, r8, ror #28
 *   @0xc4b58 eorseq r8, r2, r8, ror #28
 *
 * ══ §208/289 WriteInt32  0x1595b4  size 80  20 条（0x1595b4..0x159604）
 * @func 0x1595b4 0x159604  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1 / 0x2×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1595b4 ldr r3, [r2]
 *   @0x1595b8 lsr r12, r0, #24
 *   @0x1595bc push {r4, r5}
 *   @0x1595c0 ubfx r5, r0, #0x8, #0x8
 *   @0x1595c4 strb r0, [r1, r3]
 *   @0x1595c8 ubfx r4, r0, #0x10, #0x8
 *   @0x1595cc ldr r3, [r2]
 *   @0x1595d0 add r3, r1, r3
 *   @0x1595d4 strb r5, [r3, #0x1]
 *   @0x1595d8 ldr r3, [r2]
 *   @0x1595dc add r3, r1, r3
 *   @0x1595e0 strb r4, [r3, #0x2]
 *   @0x1595e4 ldr r3, [r2]
 *   @0x1595e8 add r1, r1, r3
 *   @0x1595ec strb r12, [r1, #0x3]
 *   @0x1595f0 ldr r3, [r2]
 *   @0x1595f4 pop {r4, r5}
 *   @0x1595f8 add r3, r3, #4
 *   @0x1595fc str r3, [r2]
 *   @0x159600 bx lr
 *
 * ══ §209/289 GR_Surface_Get  0x170f48  size 80  20 条（0x170f48..0x170f98）
 * @func 0x170f48 0x170f98  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x44×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170f48 ldr r3, [pc, #0x44]
 *   @0x170f4c ldr r3, [pc, r3]
 *   @0x170f50 ldr r2, [r3, #0x4]
 *   @0x170f54 ldr r3, [r3]
 *   @0x170f58 and r2, r0, r2
 *   @0x170f5c ldr r3, [r3, r2, lsl #3]
 *   @0x170f60 cmp r3, #0
 *   @0x170f64 bne 0x170f78 <_Z14GR_Surface_Geti+0x30>
 *   @0x170f68 b 0x170f8c <_Z14GR_Surface_Geti+0x44>
 *   @0x170f6c ldr r3, [r3, #0x4]
 *   @0x170f70 cmp r3, #0
 *   @0x170f74 beq 0x170f8c <_Z14GR_Surface_Geti+0x44>
 *   @0x170f78 ldr r2, [r3, #0x8]
 *   @0x170f7c cmp r0, r2
 *   @0x170f80 bne 0x170f6c <_Z14GR_Surface_Geti+0x24>
 *   @0x170f84 ldr r0, [r3, #0xc]
 *   @0x170f88 bx lr
 *   @0x170f8c mov r0, r3
 *   @0x170f90 bx lr
 *   @0x170f94 eoreq r12, r7, r4, asr #23
 *
 * ══ §210/289 F_Shader_Reset  0x1e2110  size 80  20 条（0x1e2110..0x1e2160）
 * @func 0x1e2110 0x1e2160  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush() / Shader_Set(Shader*)
 * 字段偏移 top8: 0x28×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2110 push {r4, lr}
 *   @0x1e2114 subs r4, r3, #0
 *   @0x1e2118 bne 0x1e2144 <_Z14F_Shader_ResetR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1e211c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e2120 mov r0, r4
 *   @0x1e2124 bl 0x1e2024 <_Z10Shader_SetP6Shader>
 *   @0x1e2128 ldr r3, [pc, #0x28]
 *   @0x1e212c ldr r3, [pc, r3]
 *   @0x1e2130 ldrb r3, [r3]
 *   @0x1e2134 cmp r3, #0
 *   @0x1e2138 popeq {r4, pc}
 *   @0x1e213c pop {r4, lr}
 *   @0x1e2140 b 0x1e1520 <_Z11FlushShaderv>
 *   @0x1e2144 ldr r0, [pc, #0x10]
 *   @0x1e2148 mov r1, #0
 *   @0x1e214c pop {r4, lr}
 *   @0x1e2150 add r0, pc, r0
 *   @0x1e2154 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2158 eoreq lr, r0, r0, lsr #24
 *   @0x1e215c andseq pc, r6, r12, lsr #25
 *
 * ══ §211/289 CTimingSource::GetFPS  0x214808  size 80  20 条（0x214808..0x214858）
 * @func 0x214808 0x214858  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::GetFPS()+0x1c / CTimingSource::GetFPS()+0x14 / __floatdidf
 * 字段偏移 top8: 无
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214808 vldr d7, [r0, #24]
 *   @0x21480c vcmpe.f64 d7, #0
 *   @0x214810 push {r3, lr}
 *   @0x214814 vmrs APSR_nzcv, fpscr
 *   @0x214818 ble 0x214824 <_ZN13CTimingSource6GetFPSEv+0x1c>
 *   @0x21481c vmov r0, r1, d7
 *   @0x214820 pop {r3, pc}
 *   @0x214824 ldrd r0, r1, [r0, #32]
 *   @0x214828 cmp r0, #1
 *   @0x21482c sbcs r3, r1, #0
 *   @0x214830 vmovlt.f64 d7, #3.000000e+01
 *   @0x214834 blt 0x21481c <_ZN13CTimingSource6GetFPSEv+0x14>
 *   @0x214838 bl 0x319164 <__floatdidf>
 *   @0x21483c vldr d7, [pc, #12]
 *   @0x214840 vmov d6, r0, r1
 *   @0x214844 vdiv.f64 d7, d7, d6
 *   @0x214848 vmov r0, r1, d7
 *   @0x21484c pop {r3, pc}
 *   @0x214850 andeq r0, r0, r0
 *   @0x214854 smlawbmi lr, r0, r4, r8
 *
 * ══ §212/289 Sound_Prepare  0x21fb80  size 80  20 条（0x21fb80..0x21fbd0）
 * @func 0x21fb80 0x21fbd0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSound::Prepare() / Sound_Number() / Sound_Prepare()+0x14
 * 字段偏移 top8: 0x3c×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21fb80 push {r3, r4, r5, lr}
 *   @0x21fb84 mov r4, #0
 *   @0x21fb88 ldr r5, [pc, #0x3c]
 *   @0x21fb8c add r5, pc, r5
 *   @0x21fb90 b 0x21fbb8 <_Z13Sound_Preparev+0x38>
 *   @0x21fb94 ldr r3, [r5]
 *   @0x21fb98 cmp r4, r3
 *   @0x21fb9c bge 0x21fbb4 <_Z13Sound_Preparev+0x34>
 *   @0x21fba0 ldr r3, [r5, #0x4]
 *   @0x21fba4 ldr r0, [r3, r4, lsl #2]
 *   @0x21fba8 cmp r0, #0
 *   @0x21fbac beq 0x21fbb4 <_Z13Sound_Preparev+0x34>
 *   @0x21fbb0 bl 0x21568c <_ZN6CSound7PrepareEv>
 *   @0x21fbb4 add r4, r4, #1
 *   @0x21fbb8 bl 0x21fb6c <_Z12Sound_Numberv>
 *   @0x21fbbc cmp r4, r0
 *   @0x21fbc0 blt 0x21fb94 <_Z13Sound_Preparev+0x14>
 *   @0x21fbc4 mov r0, #1
 *   @0x21fbc8 pop {r3, r4, r5, pc}
 *   @0x21fbcc subseq r5, r3, r12, lsr #15
 *
 * ══ §213/289 ov_info  0x232e28  size 80  20 条（0x232e28..0x232e78）
 * @func 0x232e28 0x232e78  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_info+0x34 / ov_info+0x2c
 * 字段偏移 top8: 0x48×2 / 0x4×1 / 0x34×1 / 0x58×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x232e28 ldr r3, [r0, #0x4]
 *   @0x232e2c cmp r3, #0
 *   @0x232e30 beq 0x232e54 <ov_info+0x2c>
 *   @0x232e34 cmp r1, #0
 *   @0x232e38 blt 0x232e5c <ov_info+0x34>
 *   @0x232e3c ldr r3, [r0, #0x34]
 *   @0x232e40 cmp r1, r3
 *   @0x232e44 ldrlt r0, [r0, #0x48]
 *   @0x232e48 addlt r0, r0, r1, lsl #5
 *   @0x232e4c movge r0, #0
 *   @0x232e50 bx lr
 *   @0x232e54 ldr r0, [r0, #0x48]
 *   @0x232e58 bx lr
 *   @0x232e5c ldr r3, [r0, #0x58]
 *   @0x232e60 cmp r3, #2
 *   @0x232e64 ble 0x232e54 <ov_info+0x2c>
 *   @0x232e68 ldr r1, [r0, #0x60]
 *   @0x232e6c ldr r3, [r0, #0x48]
 *   @0x232e70 add r0, r3, r1, lsl #5
 *   @0x232e74 bx lr
 *
 * ══ §214/289 CPhysicsFixtureFactory::FindFixture  0x236404  size 80  20 条（0x236404..0x236454）
 * @func 0x236404 0x236454  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x44×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236404 ldr r3, [pc, #0x44]
 *   @0x236408 ldr r3, [pc, r3]
 *   @0x23640c ldr r2, [r3, #0x4]
 *   @0x236410 ldr r3, [r3]
 *   @0x236414 and r2, r0, r2
 *   @0x236418 ldr r3, [r3, r2, lsl #3]
 *   @0x23641c cmp r3, #0
 *   @0x236420 bne 0x236434 <_ZN22CPhysicsFixtureFactory11FindFixtureEj+0x30>
 *   @0x236424 b 0x236448 <_ZN22CPhysicsFixtureFactory11FindFixtureEj+0x44>
 *   @0x236428 ldr r3, [r3, #0x4]
 *   @0x23642c cmp r3, #0
 *   @0x236430 beq 0x236448 <_ZN22CPhysicsFixtureFactory11FindFixtureEj+0x44>
 *   @0x236434 ldr r2, [r3, #0x8]
 *   @0x236438 cmp r0, r2
 *   @0x23643c bne 0x236428 <_ZN22CPhysicsFixtureFactory11FindFixtureEj+0x24>
 *   @0x236440 ldr r0, [r3, #0xc]
 *   @0x236444 bx lr
 *   @0x236448 mov r0, r3
 *   @0x23644c bx lr
 *   @0x236450 mulseq r11, r12, r0
 *
 * ══ §215/289 CPhysicsFixture::SetCircleShape  0x236788  size 80  20 条（0x236788..0x2367d8）
 * @func 0x236788 0x2367d8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::DeleteShape() / operator new(unsigned int)
 * 字段偏移 top8: 0x20×1 / 0x28×1 / 0x8×1 / 0x4×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236788 push {r3, r4, r5, lr}
 *   @0x23678c mov r4, r1
 *   @0x236790 mov r5, r0
 *   @0x236794 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv>
 *   @0x236798 mov r0, #20
 *   @0x23679c bl 0x27c524 <_Znwj>
 *   @0x2367a0 ldr r1, [r5, #0x20]
 *   @0x2367a4 ldr r3, [pc, #0x28]
 *   @0x2367a8 mov r2, #0
 *   @0x2367ac mov r12, #0
 *   @0x2367b0 ldr r3, [pc, r3]
 *   @0x2367b4 add r3, r3, #8
 *   @0x2367b8 str r4, [r0, #0x8]
 *   @0x2367bc str r12, [r0, #0x4]
 *   @0x2367c0 str r2, [r0, #0xc]
 *   @0x2367c4 str r2, [r0, #0x10]
 *   @0x2367c8 str r3, [r0]
 *   @0x2367cc str r0, [r1]
 *   @0x2367d0 pop {r3, r4, r5, pc}
 *   @0x2367d4 ldrsheq r10, [r11], -r12
 *
 * ══ §216/289 CPhysicsJointFactory::FindJoint  0x23b374  size 80  20 条（0x23b374..0x23b3c4）
 * @func 0x23b374 0x23b3c4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x44×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23b374 ldr r3, [pc, #0x44]
 *   @0x23b378 ldr r3, [pc, r3]
 *   @0x23b37c ldr r2, [r3, #0x4]
 *   @0x23b380 ldr r3, [r3]
 *   @0x23b384 and r2, r0, r2
 *   @0x23b388 ldr r3, [r3, r2, lsl #3]
 *   @0x23b38c cmp r3, #0
 *   @0x23b390 bne 0x23b3a4 <_ZN20CPhysicsJointFactory9FindJointEj+0x30>
 *   @0x23b394 b 0x23b3b8 <_ZN20CPhysicsJointFactory9FindJointEj+0x44>
 *   @0x23b398 ldr r3, [r3, #0x4]
 *   @0x23b39c cmp r3, #0
 *   @0x23b3a0 beq 0x23b3b8 <_ZN20CPhysicsJointFactory9FindJointEj+0x44>
 *   @0x23b3a4 ldr r2, [r3, #0x8]
 *   @0x23b3a8 cmp r0, r2
 *   @0x23b3ac bne 0x23b398 <_ZN20CPhysicsJointFactory9FindJointEj+0x24>
 *   @0x23b3b0 ldr r0, [r3, #0xc]
 *   @0x23b3b4 bx lr
 *   @0x23b3b8 mov r0, r3
 *   @0x23b3bc bx lr
 *   @0x23b3c0 andseq r6, r11, r12, ror #2
 *
 * ══ §217/289 rv_alloc_D2A  0x23dcc4  size 80  20 条（0x23dcc4..0x23dd14）
 * @func 0x23dcc4 0x23dd14  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: rv_alloc_D2A+0x28 / rv_alloc_D2A+0x14 / Balloc_D2A
 * 字段偏移 top8: 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23dcc4 cmp r0, #19
 *   @0x23dcc8 push {r4, lr}
 *   @0x23dccc mov r4, #0
 *   @0x23dcd0 ble 0x23dcec <rv_alloc_D2A+0x28>
 *   @0x23dcd4 mov r3, #4
 *   @0x23dcd8 lsl r3, r3, #1
 *   @0x23dcdc add r4, r4, #1
 *   @0x23dce0 add r2, r3, #16
 *   @0x23dce4 cmp r2, r0
 *   @0x23dce8 ble 0x23dcd8 <rv_alloc_D2A+0x14>
 *   @0x23dcec mov r0, r4
 *   @0x23dcf0 bl 0x23d1f8 <Balloc_D2A>
 *   @0x23dcf4 ldr r2, [pc, #0x14]
 *   @0x23dcf8 ldr r2, [pc, r2]
 *   @0x23dcfc mov r3, r0
 *   @0x23dd00 str r4, [r3], #4
 *   @0x23dd04 mov r0, r3
 *   @0x23dd08 str r3, [r2]
 *   @0x23dd0c pop {r4, pc}
 *   @0x23dd10 andseq r3, r11, r0, lsl r8
 *
 * ══ §218/289 F_JSReferenceErrorCall  0x244094  size 80  20 条（0x244094..0x2440e4）
 * @func 0x244094 0x2440e4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244094 push {r4, r5, lr}
 *   @0x244098 sub sp, sp, #20
 *   @0x24409c ldr r12, [pc, #0x38]
 *   @0x2440a0 mov r4, r0
 *   @0x2440a4 ldr lr, [sp, #0x20]
 *   @0x2440a8 mov r5, r1
 *   @0x2440ac ldr r12, [pc, r12]
 *   @0x2440b0 ldr r0, [pc, #0x28]
 *   @0x2440b4 ldr r1, [r12]
 *   @0x2440b8 add r0, pc, r0
 *   @0x2440bc str r2, [sp]
 *   @0x2440c0 mov r2, r4
 *   @0x2440c4 str r3, [sp, #0x4]
 *   @0x2440c8 mov r3, r5
 *   @0x2440cc str lr, [sp, #0x8]
 *   @0x2440d0 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_>
 *   @0x2440d4 add sp, sp, #20
 *   @0x2440d8 pop {r4, r5, pc}
 *   @0x2440dc andseq sp, r10, r8, lsr #12
 *   @0x2440e0 mulseq r1, r8, r8
 *
 * ══ §219/289 F_JSTypeErrorCall  0x244134  size 80  20 条（0x244134..0x244184）
 * @func 0x244134 0x244184  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244134 push {r4, r5, lr}
 *   @0x244138 sub sp, sp, #20
 *   @0x24413c ldr r12, [pc, #0x38]
 *   @0x244140 mov r4, r0
 *   @0x244144 ldr lr, [sp, #0x20]
 *   @0x244148 mov r5, r1
 *   @0x24414c ldr r12, [pc, r12]
 *   @0x244150 ldr r0, [pc, #0x28]
 *   @0x244154 ldr r1, [r12]
 *   @0x244158 add r0, pc, r0
 *   @0x24415c str r2, [sp]
 *   @0x244160 mov r2, r4
 *   @0x244164 str r3, [sp, #0x4]
 *   @0x244168 mov r3, r5
 *   @0x24416c str lr, [sp, #0x8]
 *   @0x244170 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_>
 *   @0x244174 add sp, sp, #20
 *   @0x244178 pop {r4, r5, pc}
 *   @0x24417c mulseq r10, r0, r5
 *   @0x244180 andseq r1, r1, r4, lsl r8
 *
 * ══ §220/289 array_list_free  0x27e1b0  size 80  20 条（0x27e1b0..0x27e200）
 * @func 0x27e1b0 0x27e200  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: array_list_free+0x3c / 0xb655c
 * 字段偏移 top8: 0x2×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e1b0 push {r3, r4, r5, lr}
 *   @0x27e1b4 mov r5, r0
 *   @0x27e1b8 ldm r0, {r2, r3}
 *   @0x27e1bc cmp r3, #0
 *   @0x27e1c0 movgt r4, #0
 *   @0x27e1c4 ble 0x27e1ec <array_list_free+0x3c>
 *   @0x27e1c8 ldr r0, [r2, r4, lsl #2]
 *   @0x27e1cc add r4, r4, #1
 *   @0x27e1d0 cmp r0, #0
 *   @0x27e1d4 beq 0x27e1e4 <array_list_free+0x34>
 *   @0x27e1d8 ldr r3, [r5, #0xc]
 *   @0x27e1dc blx r3
 *   @0x27e1e0 ldm r5, {r2, r3}
 *   @0x27e1e4 cmp r3, r4
 *   @0x27e1e8 bgt 0x27e1c8 <array_list_free+0x18>
 *   @0x27e1ec mov r0, r2
 *   @0x27e1f0 bl 0xb655c <free@plt>
 *   @0x27e1f4 mov r0, r5
 *   @0x27e1f8 pop {r3, r4, r5, lr}
 *   @0x27e1fc b 0xb655c <free@plt>
 *
 * ══ §221/289 RelyAckSendToClient  0x29a2c8  size 80  20 条（0x29a2c8..0x29a318）
 * @func 0x29a2c8 0x29a318  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RelyAckNumPackets(SRelyAck*) / RelyAckBuildPacket(SRelyAck*) / RelySendAckPacket(int, char const*, int, int) / FreeIBuffer(int) / RelyAckClearPackets(SRelyAck*) / Timing_Time
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29a2c8 push {r3, r4, r5, lr}
 *   @0x29a2cc mov r4, r0
 *   @0x29a2d0 bl 0x299944 <_Z17RelyAckNumPacketsP8SRelyAck>
 *   @0x29a2d4 cmp r0, #0
 *   @0x29a2d8 pople {r3, r4, r5, pc}
 *   @0x29a2dc mov r0, r4
 *   @0x29a2e0 bl 0x29996c <_Z18RelyAckBuildPacketP8SRelyAck>
 *   @0x29a2e4 ldm r4, {r1, r2}
 *   @0x29a2e8 mov r3, r0
 *   @0x29a2ec mov r5, r0
 *   @0x29a2f0 ldr r0, [r4, #0x8]
 *   @0x29a2f4 bl 0x29a1a4 <_Z17RelySendAckPacketiPKcii>
 *   @0x29a2f8 mov r0, r5
 *   @0x29a2fc bl 0xc6a88 <_Z11FreeIBufferi>
 *   @0x29a300 mov r0, r4
 *   @0x29a304 bl 0x299960 <_Z19RelyAckClearPacketsP8SRelyAck>
 *   @0x29a308 bl 0x215148 <Timing_Time>
 *   @0x29a30c movw r3, #0x418
 *   @0x29a310 strd r0, r1, [r4, r3]
 *   @0x29a314 pop {r3, r4, r5, pc}
 *
 * ══ §222/289 CSkeletonInstance::SelectSkin  0xbe590  size 76  19 条（0xbe590..0xbe5dc）
 * @func 0xbe590 0xbe5dc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_setSkinByName×2
 * 字段偏移 top8: 0x1c×4 / 0x30×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe590 cmp r1, #0
 *   @0xbe594 push {r4, lr}
 *   @0xbe598 mov r4, r0
 *   @0xbe59c beq 0xbe5b4 <_ZN17CSkeletonInstance10SelectSkinEPKc+0x24>
 *   @0xbe5a0 ldr r0, [r0, #0x1c]
 *   @0xbe5a4 bl 0x28a2dc <spSkeleton_setSkinByName>
 *   @0xbe5a8 ldr r0, [r4, #0x1c]
 *   @0xbe5ac pop {r4, lr}
 *   @0xbe5b0 b 0x28a064 <spSkeleton_setSlotsToSetupPose>
 *   @0xbe5b4 ldr r3, [r0, #0x30]
 *   @0xbe5b8 ldr r3, [r3, #0x28]
 *   @0xbe5bc cmp r3, #0
 *   @0xbe5c0 beq 0xbe5a8 <_ZN17CSkeletonInstance10SelectSkinEPKc+0x18>
 *   @0xbe5c4 ldr r1, [r3]
 *   @0xbe5c8 ldr r0, [r0, #0x1c]
 *   @0xbe5cc bl 0x28a2dc <spSkeleton_setSkinByName>
 *   @0xbe5d0 ldr r0, [r4, #0x1c]
 *   @0xbe5d4 pop {r4, lr}
 *   @0xbe5d8 b 0x28a064 <spSkeleton_setSlotsToSetupPose>
 *
 * ══ §223/289 CEvent::Execute  0xf2e34  size 76  19 条（0xf2e34..0xf2e80）
 * @func 0xf2e34 0xf2e80  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Execute(CInstance*, CInstance*, CCode*, RValue*, int)
 * 字段偏移 top8: 0x38×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2e34 push {r4, r5, r6, lr}
 *   @0xf2e38 sub sp, sp, #24
 *   @0xf2e3c ldr r4, [pc, #0x38]
 *   @0xf2e40 mov lr, #0
 *   @0xf2e44 ldr r6, [r0, #0x4]
 *   @0xf2e48 mov r12, #1
 *   @0xf2e4c ldr r4, [pc, r4]
 *   @0xf2e50 mov r0, r1
 *   @0xf2e54 add r3, sp, #8
 *   @0xf2e58 mov r1, r2
 *   @0xf2e5c ldrb r5, [r4]
 *   @0xf2e60 mov r2, r6
 *   @0xf2e64 strb lr, [r4]
 *   @0xf2e68 str r12, [sp]
 *   @0xf2e6c bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei>
 *   @0xf2e70 strb r5, [r4]
 *   @0xf2e74 add sp, sp, #24
 *   @0xf2e78 pop {r4, r5, r6, pc}
 *   @0xf2e7c .word 0x002facf0
 *
 * ══ §224/289 CExtensionPackage::FunctionFindName  0xf5494  size 76  19 条（0xf5494..0xf54e0）
 * @func 0xf5494 0xf54e0  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionPackage::FunctionFindName(char const*)+0x44 / CExtensionFile::FunctionFindName(char const*)
 * 字段偏移 top8: 0x18×2 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5494 ldr r3, [r0, #0x18]
 *   @0xf5498 push {r4, r5, r6, lr}
 *   @0xf549c cmp r3, #0
 *   @0xf54a0 mov r5, r0
 *   @0xf54a4 mov r6, r1
 *   @0xf54a8 movgt r4, #0
 *   @0xf54ac ble 0xf54d8 <_ZN17CExtensionPackage16FunctionFindNameEPKc+0x44>
 *   @0xf54b0 ldr r3, [r5, #0x14]
 *   @0xf54b4 mov r1, r6
 *   @0xf54b8 ldr r0, [r3, r4, lsl #2]
 *   @0xf54bc add r4, r4, #1
 *   @0xf54c0 bl 0xf4e84 <_ZN14CExtensionFile16FunctionFindNameEPKc>
 *   @0xf54c4 cmp r0, #0
 *   @0xf54c8 popne {r4, r5, r6, pc}
 *   @0xf54cc ldr r3, [r5, #0x18]
 *   @0xf54d0 cmp r3, r4
 *   @0xf54d4 bgt 0xf54b0 <_ZN17CExtensionPackage16FunctionFindNameEPKc+0x1c>
 *   @0xf54d8 mov r0, #0
 *   @0xf54dc pop {r4, r5, r6, pc}
 *
 * ══ §225/289 Graphics::GetMatrix  0x17ead0  size 76  19 条（0x17ead0..0x17eb1c）
 * @func 0x17ead0 0x17eb1c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x-10×1 / 0x-c×1 / 0x-8×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17ead0 push {r4, r5, r6}
 *   @0x17ead4 mov r4, r1
 *   @0x17ead8 ldr r5, [pc, #0x38]
 *   @0x17eadc ldr r5, [pc, r5]
 *   @0x17eae0 add r5, r5, r0, lsl #6
 *   @0x17eae4 add r6, r5, #64
 *   @0x17eae8 mov r12, r5
 *   @0x17eaec add r4, r4, #16
 *   @0x17eaf0 ldm r12!, {r0, r1, r2, r3}
 *   @0x17eaf4 add r5, r5, #16
 *   @0x17eaf8 cmp r12, r6
 *   @0x17eafc str r0, [r4, #-0x10]
 *   @0x17eb00 str r1, [r4, #-0xc]
 *   @0x17eb04 str r2, [r4, #-0x8]
 *   @0x17eb08 str r3, [r4, #-0x4]
 *   @0x17eb0c bne 0x17eae8 <_ZN8Graphics9GetMatrixE7eMatrixPf+0x18>
 *   @0x17eb10 pop {r4, r5, r6}
 *   @0x17eb14 bx lr
 *   @0x17eb18 mlaeq r7, r8, r9, r1
 *
 * ══ §226/289 DeleteAllVirtualKeys  0x18c64c  size 76  19 条（0x18c64c..0x18c698）
 * @func 0x18c64c 0x18c698  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c64c ldr r3, [pc, #0x3c]
 *   @0x18c650 ldr r3, [pc, r3]
 *   @0x18c654 ldr r3, [r3]
 *   @0x18c658 cmp r3, #0
 *   @0x18c65c bxle lr
 *   @0x18c660 ldr r2, [pc, #0x2c]
 *   @0x18c664 mov r0, #44
 *   @0x18c668 mul r0, r0, r3
 *   @0x18c66c ldr r2, [pc, r2]
 *   @0x18c670 mov r3, #0
 *   @0x18c674 ldr r1, [r2]
 *   @0x18c678 mov r2, r3
 *   @0x18c67c strh r2, [r1, r3]
 *   @0x18c680 add r3, r3, #44
 *   @0x18c684 cmp r3, r0
 *   @0x18c688 bne 0x18c67c <_Z20DeleteAllVirtualKeysv+0x30>
 *   @0x18c68c bx lr
 *   @0x18c690 eoreq r3, r6, r0, lsl #10
 *   @0x18c694 eoreq r3, r6, r8, ror #9
 *
 * ══ §227/289 CalcVelocity  0x1d6854  size 76  19 条（0x1d6854..0x1d68a0）
 * @func 0x1d6854 0x1d68a0  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d6854 vldr s15, [sp]
 *   @0x1d6858 vcmp.f32 s15, #0
 *   @0x1d685c vmov s12, r0
 *   @0x1d6860 ldr r0, [sp, #0x8]
 *   @0x1d6864 vmov s14, r1
 *   @0x1d6868 ldr r1, [sp, #0x4]
 *   @0x1d686c vmov s11, r2
 *   @0x1d6870 mov r2, #0
 *   @0x1d6874 vmov s13, r3
 *   @0x1d6878 vmrs APSR_nzcv, fpscr
 *   @0x1d687c vsubne.f32 s12, s11, s12
 *   @0x1d6880 streq r2, [r1]
 *   @0x1d6884 streq r2, [r0]
 *   @0x1d6888 vsubne.f32 s14, s13, s14
 *   @0x1d688c vdivne.f32 s12, s12, s15
 *   @0x1d6890 vdivne.f32 s15, s14, s15
 *   @0x1d6894 vstrne s12, [r1]
 *   @0x1d6898 vstrne s15, [r0]
 *   @0x1d689c bx lr
 *
 * ══ §228/289 ConvertGestureEventToGMEvent  0x1d6b44  size 76  19 条（0x1d6b44..0x1d6b90）
 * @func 0x1d6b44 0x1d6b90  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertGestureEventToGMEvent(int, bool)+0x34
 * 字段偏移 top8: 0x1c×1 / 0x34×1 / 0xc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d6b44 cmp r1, #0
 *   @0x1d6b48 bne 0x1d6b5c <_Z28ConvertGestureEventToGMEventib+0x18>
 *   @0x1d6b4c cmp r0, #12
 *   @0x1d6b50 bls 0x1d6b78 <_Z28ConvertGestureEventToGMEventib+0x34>
 *   @0x1d6b54 mvn r0, #0
 *   @0x1d6b58 bx lr
 *   @0x1d6b5c cmp r0, #12
 *   @0x1d6b60 bhi 0x1d6b54 <_Z28ConvertGestureEventToGMEventib+0x10>
 *   @0x1d6b64 ldr r3, [pc, #0x1c]
 *   @0x1d6b68 add r3, pc, r3
 *   @0x1d6b6c add r0, r3, r0, lsl #2
 *   @0x1d6b70 ldr r0, [r0, #0x34]
 *   @0x1d6b74 bx lr
 *   @0x1d6b78 ldr r3, [pc, #0xc]
 *   @0x1d6b7c add r3, pc, r3
 *   @0x1d6b80 ldr r0, [r3, r0, lsl #2]
 *   @0x1d6b84 bx lr
 *   @0x1d6b88 andseq r7, r8, r8, lsr #5
 *   @0x1d6b8c mulseq r8, r4, r2
 *
 * ══ §229/289 DsQueueDequeue  0x20557c  size 76  19 条（0x20557c..0x2055c8）
 * @func 0x20557c 0x2055c8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DsQueueDequeue(int, RValue&)+0x44 / F_DsQueueDequeue(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20557c subs r3, r0, #0
 *   @0x205580 mov r0, r1
 *   @0x205584 push {r4, r5, lr}
 *   @0x205588 sub sp, sp, #28
 *   @0x20558c blt 0x2055c0 <_Z14DsQueueDequeueiR6RValue+0x44>
 *   @0x205590 vmov s13, r3
 *   @0x205594 add r12, sp, #24
 *   @0x205598 mov lr, #0
 *   @0x20559c mov r3, #1
 *   @0x2055a0 vcvt.f64.s32 d7, s13
 *   @0x2055a4 mov r1, lr
 *   @0x2055a8 mov r2, lr
 *   @0x2055ac str lr, [sp, #0x14]
 *   @0x2055b0 vmov r4, r5, d7
 *   @0x2055b4 strd r4, r5, [r12, #-16]!
 *   @0x2055b8 str r12, [sp]
 *   @0x2055bc bl 0x101d8c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_>
 *   @0x2055c0 add sp, sp, #28
 *   @0x2055c4 pop {r4, r5, pc}
 *
 * ══ §230/289 DsQueueClear  0x205620  size 76  19 条（0x205620..0x20566c）
 * @func 0x205620 0x20566c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DsQueueClear(int)+0x44 / F_DsQueueClear(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x24×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x205620 cmp r0, #0
 *   @0x205624 str lr, [sp, #-0x4]!
 *   @0x205628 sub sp, sp, #44
 *   @0x20562c blt 0x205664 <_Z12DsQueueCleari+0x44>
 *   @0x205630 vmov s13, r0
 *   @0x205634 mov r12, #0
 *   @0x205638 add r3, sp, #24
 *   @0x20563c mov r1, r12
 *   @0x205640 vcvt.f64.s32 d7, s13
 *   @0x205644 str r3, [sp]
 *   @0x205648 mov r2, r12
 *   @0x20564c add r0, sp, #8
 *   @0x205650 mov r3, #1
 *   @0x205654 str r12, [sp, #0x8]
 *   @0x205658 str r12, [sp, #0x24]
 *   @0x20565c vstr d7, [sp, #24]
 *   @0x205660 bl 0xfbe14 <_Z14F_DsQueueClearR6RValueP9CInstanceS2_iPS_>
 *   @0x205664 add sp, sp, #44
 *   @0x205668 ldr pc, [sp], #4
 *
 * ══ §231/289 CPhysicsFixture::DeleteShape  0x2365d0  size 76  19 条（0x2365d0..0x23661c）
 * @func 0x2365d0 0x23661c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x20×2 / 0x14×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2365d0 ldr r3, [r0, #0x20]
 *   @0x2365d4 push {r4, lr}
 *   @0x2365d8 mov r4, r0
 *   @0x2365dc ldr r0, [r3]
 *   @0x2365e0 cmp r0, #0
 *   @0x2365e4 beq 0x236600 <_ZN15CPhysicsFixture11DeleteShapeEv+0x30>
 *   @0x2365e8 ldr r3, [r0]
 *   @0x2365ec ldr r3, [r3, #0x4]
 *   @0x2365f0 blx r3
 *   @0x2365f4 ldr r3, [r4, #0x20]
 *   @0x2365f8 mov r2, #0
 *   @0x2365fc str r2, [r3]
 *   @0x236600 ldr r0, [r4, #0x14]
 *   @0x236604 cmp r0, #0
 *   @0x236608 popeq {r4, pc}
 *   @0x23660c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x236610 mov r3, #0
 *   @0x236614 str r3, [r4, #0x14]
 *   @0x236618 pop {r4, pc}
 *
 * ══ §232/289 isGlobalBuiltinVar  0x23f8f0  size 76  19 条（0x23f8f0..0x23f93c）
 * @func 0x23f8f0 0x23f93c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 0x38×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23f8f0 push {r4, r5, r6, lr}
 *   @0x23f8f4 mov r5, r0
 *   @0x23f8f8 ldr r6, [pc, #0x38]
 *   @0x23f8fc ldr r6, [pc, r6]
 *   @0x23f900 sub r4, r6, #4
 *   @0x23f904 add r6, r6, #512
 *   @0x23f908 b 0x23f914 <_Z18isGlobalBuiltinVarPKc+0x24>
 *   @0x23f90c cmp r4, r6
 *   @0x23f910 beq 0x23f930 <_Z18isGlobalBuiltinVarPKc+0x40>
 *   @0x23f914 ldr r0, [r4, #0x4]!
 *   @0x23f918 mov r1, r5
 *   @0x23f91c bl 0xb6574 <strcmp@plt>
 *   @0x23f920 cmp r0, #0
 *   @0x23f924 bne 0x23f90c <_Z18isGlobalBuiltinVarPKc+0x1c>
 *   @0x23f928 mov r0, #1
 *   @0x23f92c pop {r4, r5, r6, pc}
 *   @0x23f930 mov r0, #0
 *   @0x23f934 pop {r4, r5, r6, pc}
 *   @0x23f938 andseq r1, r11, r4, lsl r12
 *
 * ══ §233/289 JS_GetOwnProperty  0x241890  size 76  19 条（0x241890..0x2418dc）
 * @func 0x241890 0x2418dc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×2 / 0x18×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x241890 ldr r12, [r0, #0x4c]
 *   @0x241894 push {r3, lr}
 *   @0x241898 cmp r12, #0
 *   @0x24189c bne 0x2418c8 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x38>
 *   @0x2418a0 ldr r3, [r0, #0x18]
 *   @0x2418a4 cmp r3, #0
 *   @0x2418a8 bne 0x2418bc <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x2c>
 *   @0x2418ac b 0x2418d0 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x40>
 *   @0x2418b0 ldr r3, [r3, #0x18]
 *   @0x2418b4 cmp r3, #0
 *   @0x2418b8 beq 0x2418d0 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x40>
 *   @0x2418bc ldr r12, [r3, #0x4c]
 *   @0x2418c0 cmp r12, #0
 *   @0x2418c4 beq 0x2418b0 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x20>
 *   @0x2418c8 blx r12
 *   @0x2418cc pop {r3, pc}
 *   @0x2418d0 mvn r3, #-16777216
 *   @0x2418d4 str r3, [r1, #0xc]
 *   @0x2418d8 pop {r3, pc}
 *
 * ══ §234/289 json_object_new_array  0x27ed80  size 76  19 条（0x27ed80..0x27edcc）
 * @func 0x27ed80 0x27edcc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_27e408+0x31c / array_list_new
 * 字段偏移 top8: 0x24×3 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ed80 push {r4, lr}
 *   @0x27ed84 mov r0, #5
 *   @0x27ed88 bl 0x27e724 <mc_info+0x35c>
 *   @0x27ed8c subs r4, r0, #0
 *   @0x27ed90 beq 0x27edb8 <json_object_new_array+0x38>
 *   @0x27ed94 ldr r2, [pc, #0x24]
 *   @0x27ed98 ldr r3, [pc, #0x24]
 *   @0x27ed9c ldr r0, [pc, #0x24]
 *   @0x27eda0 add r2, pc, r2
 *   @0x27eda4 add r3, pc, r3
 *   @0x27eda8 stmib r4, {r2, r3}
 *   @0x27edac add r0, pc, r0
 *   @0x27edb0 bl 0x27e14c <array_list_new>
 *   @0x27edb4 str r0, [r4, #0x18]
 *   @0x27edb8 mov r0, r4
 *   @0x27edbc pop {r4, pc}
 *   @0x27edc0 .word 0xfffff9b8
 *   @0x27edc4 andeq r0, r0, r12, asr r0
 *   @0x27edc8 .word 0xfffffa5c
 *
 * ══ §235/289 _spAttachmentLoader_init  0x284cc8  size 76  19 条（0x284cc8..0x284d14）
 * @func 0x284cc8 0x284d14  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x8×2 / 0x38×1 / 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284cc8 push {r4, r5, r6, r7, r8, lr}
 *   @0x284ccc mov r6, r2
 *   @0x284cd0 ldr r2, [pc, #0x38]
 *   @0x284cd4 mov r8, r0
 *   @0x284cd8 mov r7, r1
 *   @0x284cdc mov r5, r3
 *   @0x284ce0 mov r0, #1
 *   @0x284ce4 mov r1, #16
 *   @0x284ce8 add r2, pc, r2
 *   @0x284cec mov r3, #51
 *   @0x284cf0 ldr r4, [sp, #0x18]
 *   @0x284cf4 bl 0x285c4c <_calloc>
 *   @0x284cf8 str r0, [r8, #0x8]
 *   @0x284cfc str r7, [r0, #0xc]
 *   @0x284d00 str r6, [r0]
 *   @0x284d04 str r5, [r0, #0x4]
 *   @0x284d08 str r4, [r0, #0x8]
 *   @0x284d0c pop {r4, r5, r6, r7, r8, pc}
 *   @0x284d10 andeq r2, sp, r4, lsr #19
 *
 * ══ §236/289 RelyRemovePacket  0x299b9c  size 76  19 条（0x299b9c..0x299be8）
 * @func 0x299b9c 0x299be8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×1 / 0x20×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299b9c ldr r3, [pc, #0x3c]
 *   @0x299ba0 ldr r1, [r0, #0x20]
 *   @0x299ba4 ldr r3, [pc, r3]
 *   @0x299ba8 ldr r2, [r0, #0x24]
 *   @0x299bac ldr r12, [r3]
 *   @0x299bb0 cmp r2, #0
 *   @0x299bb4 strne r1, [r2, #0x20]
 *   @0x299bb8 cmp r1, #0
 *   @0x299bbc strne r2, [r1, #0x24]
 *   @0x299bc0 cmp r0, r12
 *   @0x299bc4 streq r1, [r3]
 *   @0x299bc8 ldr r3, [pc, #0x14]
 *   @0x299bcc ldr r3, [pc, r3]
 *   @0x299bd0 ldr r1, [r3]
 *   @0x299bd4 cmp r0, r1
 *   @0x299bd8 streq r2, [r3]
 *   @0x299bdc bx lr
 *   @0x299be0 andseq r7, r5, r0, asr lr
 *   @0x299be4 andseq r7, r5, r12, lsr #28
 *
 * ══ §237/289 b2ParticleSystem::SolveWall  0x2d5e08  size 76  19 条（0x2d5e08..0x2d5e54）
 * @func 0x2d5e08 0x2d5e54  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolveWall(b2TimeStep const&)+0x44
 * 字段偏移 top8: 0x24×1 / 0x-4×1 / 0x30×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5e08 ldr r1, [r0, #0x24]
 *   @0x2d5e0c str r4, [sp, #-0x4]!
 *   @0x2d5e10 cmp r1, #0
 *   @0x2d5e14 ble 0x2d5e4c <_ZN16b2ParticleSystem9SolveWallERK10b2TimeStep+0x44>
 *   @0x2d5e18 ldr r12, [r0, #0x30]
 *   @0x2d5e1c lsl r1, r1, #2
 *   @0x2d5e20 mov r3, #0
 *   @0x2d5e24 mov r4, #0
 *   @0x2d5e28 ldr r2, [r12, r3]
 *   @0x2d5e2c tst r2, #4
 *   @0x2d5e30 ldrne r2, [r0, #0x40]
 *   @0x2d5e34 addne r2, r2, r3, lsl #1
 *   @0x2d5e38 add r3, r3, #4
 *   @0x2d5e3c strne r4, [r2]
 *   @0x2d5e40 strne r4, [r2, #0x4]
 *   @0x2d5e44 cmp r3, r1
 *   @0x2d5e48 bne 0x2d5e28 <_ZN16b2ParticleSystem9SolveWallERK10b2TimeStep+0x20>
 *   @0x2d5e4c ldr r4, [sp], #4
 *   @0x2d5e50 bx lr
 *
 * ══ §238/289 b2Island::~b2Island  0x2e11d8  size 76  19 条（0x2e11d8..0x2e1224）
 * @func 0x2e11d8 0x2e1224  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2StackAllocator::Free(void*)×5
 * 字段偏移 top8: 0x14×1 / 0x18×1 / 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e11d8 push {r4, lr}
 *   @0x2e11dc mov r4, r0
 *   @0x2e11e0 ldr r1, [r4, #0x14]
 *   @0x2e11e4 ldr r0, [r0]
 *   @0x2e11e8 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2e11ec ldr r0, [r4]
 *   @0x2e11f0 ldr r1, [r4, #0x18]
 *   @0x2e11f4 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2e11f8 ldr r0, [r4]
 *   @0x2e11fc ldr r1, [r4, #0x10]
 *   @0x2e1200 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2e1204 ldr r0, [r4]
 *   @0x2e1208 ldr r1, [r4, #0xc]
 *   @0x2e120c bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2e1210 ldr r0, [r4]
 *   @0x2e1214 ldr r1, [r4, #0x8]
 *   @0x2e1218 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2e121c mov r0, r4
 *   @0x2e1220 pop {r4, pc}
 *
 * ══ §239/289 Background_Exists  0xc3640  size 72  18 条（0xc3640..0xc3688）
 * @func 0xc3640 0xc3688  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Exists(int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3640 cmp r0, #0
 *   @0xc3644 blt 0xc3678 <_Z17Background_Existsi+0x38>
 *   @0xc3648 ldr r3, [pc, #0x30]
 *   @0xc364c ldr r3, [pc, r3]
 *   @0xc3650 ldr r3, [r3]
 *   @0xc3654 cmp r0, r3
 *   @0xc3658 bge 0xc3678 <_Z17Background_Existsi+0x38>
 *   @0xc365c ldr r3, [pc, #0x20]
 *   @0xc3660 add r3, pc, r3
 *   @0xc3664 ldr r3, [r3, #0x4]
 *   @0xc3668 ldr r0, [r3, r0, lsl #2]
 *   @0xc366c adds r0, r0, #0
 *   @0xc3670 movne r0, #1
 *   @0xc3674 bx lr
 *   @0xc3678 mov r0, #0
 *   @0xc367c bx lr
 *   @0xc3680 ldrshteq r10, [r2], -r12
 *   @0xc3684 eorseq r6, r11, r8, asr #12
 *
 * ══ §240/289 FreeIBuffer  0xc6a88  size 72  18 条（0xc6a88..0xc6ad0）
 * @func 0xc6a88 0xc6ad0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x34×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6a88 push {r3, r4, r5, lr}
 *   @0xc6a8c lsl r4, r0, #2
 *   @0xc6a90 ldr r5, [pc, #0x34]
 *   @0xc6a94 add r5, pc, r5
 *   @0xc6a98 ldr r3, [r5, #0x4]
 *   @0xc6a9c add r2, r3, r4
 *   @0xc6aa0 ldr r0, [r3, r0, lsl #2]
 *   @0xc6aa4 cmp r0, #0
 *   @0xc6aa8 beq 0xc6ac0 <_Z11FreeIBufferi+0x38>
 *   @0xc6aac ldr r3, [r0]
 *   @0xc6ab0 ldr r3, [r3, #0x4]
 *   @0xc6ab4 blx r3
 *   @0xc6ab8 ldr r2, [r5, #0x4]
 *   @0xc6abc add r2, r2, r4
 *   @0xc6ac0 mov r3, #0
 *   @0xc6ac4 str r3, [r2]
 *   @0xc6ac8 pop {r3, r4, r5, pc}
 *   @0xc6acc eorseq r3, r11, r0, lsl #13
 *
 * ══ §241/289 ARRAY_RefAlloc  0xced9c  size 72  18 条（0xced9c..0xcede4）
 * @func 0xced9c 0xcede4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0
 * 字段偏移 top8: 0x3c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xced9c ldr r1, [pc, #0x3c]
 *   @0xceda0 movw r2, #0x1e7
 *   @0xceda4 push {r3, r4, r5, lr}
 *   @0xceda8 add r1, pc, r1
 *   @0xcedac mov r5, r0
 *   @0xcedb0 mov r3, #1
 *   @0xcedb4 mov r0, #20
 *   @0xcedb8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcedbc mov r1, #0
 *   @0xcedc0 mov r2, #20
 *   @0xcedc4 mov r4, r0
 *   @0xcedc8 bl 0xb65b0 <memset@plt>
 *   @0xcedcc mov r3, #1
 *   @0xcedd0 str r5, [r4, #0x8]
 *   @0xcedd4 mov r0, r4
 *   @0xcedd8 str r3, [r4]
 *   @0xceddc pop {r3, r4, r5, pc}
 *   @0xcede0 eoreq r3, r6, r4, asr r4
 *
 * ══ §242/289 utf8_strlen  0x110648  size 72  18 条（0x110648..0x110690）
 * @func 0x110648 0x110690  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110648 push {r4, r5, lr}
 *   @0x11064c sub sp, sp, #12
 *   @0x110650 str r0, [sp, #0x4]
 *   @0x110654 ldrb r4, [r0]
 *   @0x110658 cmp r4, #0
 *   @0x11065c beq 0x110684 <utf8_strlen+0x3c>
 *   @0x110660 add r5, sp, #4
 *   @0x110664 mov r4, #0
 *   @0x110668 mov r0, r5
 *   @0x11066c add r4, r4, #1
 *   @0x110670 bl 0x10fb38 <utf8_extract_char>
 *   @0x110674 ldr r3, [sp, #0x4]
 *   @0x110678 ldrb r3, [r3]
 *   @0x11067c cmp r3, #0
 *   @0x110680 bne 0x110668 <utf8_strlen+0x20>
 *   @0x110684 mov r0, r4
 *   @0x110688 add sp, sp, #12
 *   @0x11068c pop {r4, r5, pc}
 *
 * ══ §243/289 DeSerializeMatrix  0x16e4b0  size 72  18 条（0x16e4b0..0x16e4f8）
 * @func 0x16e4b0 0x16e4f8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16e4b0 push {r3, r4, r5, r6, r7, lr}
 *   @0x16e4b4 add r6, r1, #44
 *   @0x16e4b8 mov r5, r1
 *   @0x16e4bc mov r7, r0
 *   @0x16e4c0 mov r4, #16
 *   @0x16e4c4 ldr r3, [r5]
 *   @0x16e4c8 mov r1, #8
 *   @0x16e4cc mov r2, r6
 *   @0x16e4d0 mov r0, r5
 *   @0x16e4d4 ldr r3, [r3, #0xc]
 *   @0x16e4d8 blx r3
 *   @0x16e4dc mov r0, r6
 *   @0x16e4e0 mov r1, #0
 *   @0x16e4e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16e4e8 subs r4, r4, #1
 *   @0x16e4ec str r0, [r7], #4
 *   @0x16e4f0 bne 0x16e4c4 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer+0x14>
 *   @0x16e4f4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §244/289 CCameraManager::CreateCamera  0x16edb4  size 72  18 条（0x16edb4..0x16edfc）
 * @func 0x16edb4 0x16edfc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / CCamera::CCamera() / CCameraManager::AddCameraToList(CCamera*, int)
 * 字段偏移 top8: 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16edb4 ldr r1, [pc, #0x3c]
 *   @0x16edb8 movw r2, #0x803
 *   @0x16edbc push {r3, r4, r5, lr}
 *   @0x16edc0 add r1, pc, r1
 *   @0x16edc4 mov r5, r0
 *   @0x16edc8 mov r3, #1
 *   @0x16edcc mov r0, #444
 *   @0x16edd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x16edd4 subs r4, r0, #0
 *   @0x16edd8 beq 0x16ede0 <_ZN14CCameraManager12CreateCameraEv+0x2c>
 *   @0x16eddc bl 0x16cfc0 <_ZN7CCameraC2Ev>
 *   @0x16ede0 mov r0, r5
 *   @0x16ede4 mov r1, r4
 *   @0x16ede8 mvn r2, #0
 *   @0x16edec bl 0x16ed1c <_ZN14CCameraManager15AddCameraToListEP7CCamerai>
 *   @0x16edf0 mov r0, r4
 *   @0x16edf4 pop {r3, r4, r5, pc}
 *   @0x16edf8 mulseq sp, r8, r10
 *
 * ══ §245/289 ParticleType_Exists  0x1a2e14  size 72  18 条（0x1a2e14..0x1a2e5c）
 * @func 0x1a2e14 0x1a2e5c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a2e14 cmp r0, #0
 *   @0x1a2e18 blt 0x1a2e4c <_Z19ParticleType_Existsi+0x38>
 *   @0x1a2e1c ldr r3, [pc, #0x30]
 *   @0x1a2e20 ldr r3, [pc, r3]
 *   @0x1a2e24 ldr r3, [r3]
 *   @0x1a2e28 cmp r0, r3
 *   @0x1a2e2c bge 0x1a2e4c <_Z19ParticleType_Existsi+0x38>
 *   @0x1a2e30 ldr r3, [pc, #0x20]
 *   @0x1a2e34 ldr r3, [pc, r3]
 *   @0x1a2e38 ldr r3, [r3, #0x4]
 *   @0x1a2e3c ldr r0, [r3, r0, lsl #2]
 *   @0x1a2e40 adds r0, r0, #0
 *   @0x1a2e44 movne r0, #1
 *   @0x1a2e48 bx lr
 *   @0x1a2e4c mov r0, #0
 *   @0x1a2e50 bx lr
 *   @0x1a2e54 mlaeq r4, r0, r9, sp
 *   @0x1a2e58 eoreq sp, r4, r8, ror r9
 *
 * ══ §246/289 ParticleSystem_Exists  0x1a3770  size 72  18 条（0x1a3770..0x1a37b8）
 * @func 0x1a3770 0x1a37b8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)+0x38
 * 字段偏移 top8: 0x30×1 / 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3770 cmp r0, #0
 *   @0x1a3774 blt 0x1a37a8 <_Z21ParticleSystem_Existsi+0x38>
 *   @0x1a3778 ldr r3, [pc, #0x30]
 *   @0x1a377c ldr r3, [pc, r3]
 *   @0x1a3780 ldr r3, [r3]
 *   @0x1a3784 cmp r0, r3
 *   @0x1a3788 bge 0x1a37a8 <_Z21ParticleSystem_Existsi+0x38>
 *   @0x1a378c ldr r3, [pc, #0x20]
 *   @0x1a3790 ldr r3, [pc, r3]
 *   @0x1a3794 ldr r3, [r3, #0x4]
 *   @0x1a3798 ldr r0, [r3, r0, lsl #2]
 *   @0x1a379c adds r0, r0, #0
 *   @0x1a37a0 movne r0, #1
 *   @0x1a37a4 bx lr
 *   @0x1a37a8 mov r0, #0
 *   @0x1a37ac bx lr
 *   @0x1a37b0 eoreq sp, r4, r8, lsr r0
 *   @0x1a37b4 eoreq sp, r4, r8, lsr #32
 *
 * ══ §247/289 SetLayerShader  0x1b1128  size 72  18 条（0x1b1128..0x1b1170）
 * @func 0x1b1128 0x1b1170  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_Shader_Set(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x14×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b1128 cmn r0, #1
 *   @0x1b112c str lr, [sp, #-0x4]!
 *   @0x1b1130 sub sp, sp, #44
 *   @0x1b1134 beq 0x1b1168 <_Z14SetLayerShaderi+0x40>
 *   @0x1b1138 vmov s13, r0
 *   @0x1b113c mov r12, #0
 *   @0x1b1140 add r3, sp, #8
 *   @0x1b1144 mov r1, r12
 *   @0x1b1148 vcvt.f64.s32 d7, s13
 *   @0x1b114c str r3, [sp]
 *   @0x1b1150 mov r2, r12
 *   @0x1b1154 add r0, sp, #24
 *   @0x1b1158 mov r3, #1
 *   @0x1b115c str r12, [sp, #0x14]
 *   @0x1b1160 vstr d7, [sp, #8]
 *   @0x1b1164 bl 0x1e207c <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_>
 *   @0x1b1168 add sp, sp, #44
 *   @0x1b116c ldr pc, [sp], #4
 *
 * ══ §248/289 CLayerManager::RemoveInstance  0x1b9e5c  size 72  18 条（0x1b9e5c..0x1b9ea4）
 * @func 0x1b9e5c 0x1b9ea4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetLayerFromID(CRoom*, int)
 * 字段偏移 top8: 0x174×1 / 0x170×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b9e5c push {r3, r4, r5, lr}
 *   @0x1b9e60 subs r4, r1, #0
 *   @0x1b9e64 mov r5, r0
 *   @0x1b9e68 popeq {r3, r4, r5, pc}
 *   @0x1b9e6c ldrb r3, [r4, #0x174]
 *   @0x1b9e70 cmp r3, #0
 *   @0x1b9e74 popeq {r3, r4, r5, pc}
 *   @0x1b9e78 ldr r1, [r4, #0x170]
 *   @0x1b9e7c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1b9e80 subs r1, r0, #0
 *   @0x1b9e84 strbeq r1, [r4, #0x174]
 *   @0x1b9e88 mvneq r3, #0
 *   @0x1b9e8c streq r3, [r4, #0x170]
 *   @0x1b9e90 popeq {r3, r4, r5, pc}
 *   @0x1b9e94 mov r0, r5
 *   @0x1b9e98 mov r2, r4
 *   @0x1b9e9c pop {r3, r4, r5, lr}
 *   @0x1b9ea0 b 0x1b991c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance>
 *
 * ══ §249/289 ChangeInstanceTypes  0x1d2ea0  size 72  18 条（0x1d2ea0..0x1d2ee8）
 * @func 0x1d2ea0 0x1d2ee8  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ChangeInstanceTypes()+0x38 / CInstance::RelinkObjectTypes()
 * 字段偏移 top8: 0x8×3 / 0x38×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d2ea0 push {r3, r4, r5, lr}
 *   @0x1d2ea4 ldr r5, [pc, #0x38]
 *   @0x1d2ea8 ldr r5, [pc, r5]
 *   @0x1d2eac ldr r3, [r5, #0x8]
 *   @0x1d2eb0 cmp r3, #0
 *   @0x1d2eb4 movgt r4, #0
 *   @0x1d2eb8 ble 0x1d2ed8 <_Z19ChangeInstanceTypesv+0x38>
 *   @0x1d2ebc ldr r3, [r5]
 *   @0x1d2ec0 ldr r0, [r3, r4, lsl #2]
 *   @0x1d2ec4 add r4, r4, #1
 *   @0x1d2ec8 bl 0x192bc4 <_ZN9CInstance17RelinkObjectTypesEv>
 *   @0x1d2ecc ldr r3, [r5, #0x8]
 *   @0x1d2ed0 cmp r3, r4
 *   @0x1d2ed4 bgt 0x1d2ebc <_Z19ChangeInstanceTypesv+0x1c>
 *   @0x1d2ed8 mov r3, #0
 *   @0x1d2edc str r3, [r5, #0x8]
 *   @0x1d2ee0 pop {r3, r4, r5, pc}
 *   @0x1d2ee4 mlaeq r1, r8, sp, r10
 *
 * ══ §250/289 CDS_Stack::Mark4GC  0x202d50  size 72  18 条（0x202d50..0x202d98）
 * @func 0x202d50 0x202d98  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC(RValue const*, unsigned int*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202d50 push {r3, r4, r5, r6, r7, lr}
 *   @0x202d54 mov r5, r0
 *   @0x202d58 ldr r3, [r0, #0x4]
 *   @0x202d5c mov r6, r1
 *   @0x202d60 mov r7, r2
 *   @0x202d64 cmp r3, #0
 *   @0x202d68 pople {r3, r4, r5, r6, r7, pc}
 *   @0x202d6c mov r4, #0
 *   @0x202d70 ldr r0, [r5, #0xc]
 *   @0x202d74 mov r1, r6
 *   @0x202d78 mov r2, r7
 *   @0x202d7c add r0, r0, r4, lsl #4
 *   @0x202d80 add r4, r4, #1
 *   @0x202d84 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x202d88 ldr r3, [r5, #0x4]
 *   @0x202d8c cmp r3, r4
 *   @0x202d90 bgt 0x202d70 <_ZN9CDS_Stack7Mark4GCEPji+0x20>
 *   @0x202d94 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §251/289 CDS_Queue::Mark4GC  0x202ed8  size 72  18 条（0x202ed8..0x202f20）
 * @func 0x202ed8 0x202f20  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC(RValue const*, unsigned int*, int)
 * 字段偏移 top8: 0xc×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202ed8 push {r3, r4, r5, r6, r7, lr}
 *   @0x202edc mov r5, r0
 *   @0x202ee0 ldr r3, [r0, #0xc]
 *   @0x202ee4 mov r6, r1
 *   @0x202ee8 mov r7, r2
 *   @0x202eec cmp r3, #0
 *   @0x202ef0 pople {r3, r4, r5, r6, r7, pc}
 *   @0x202ef4 mov r4, #0
 *   @0x202ef8 ldr r0, [r5, #0x10]
 *   @0x202efc mov r1, r6
 *   @0x202f00 mov r2, r7
 *   @0x202f04 add r0, r0, r4, lsl #4
 *   @0x202f08 add r4, r4, #1
 *   @0x202f0c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x202f10 ldr r3, [r5, #0xc]
 *   @0x202f14 cmp r3, r4
 *   @0x202f18 bgt 0x202ef8 <_ZN9CDS_Queue7Mark4GCEPji+0x20>
 *   @0x202f1c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §252/289 CDS_List::Mark4GC  0x2030ac  size 72  18 条（0x2030ac..0x2030f4）
 * @func 0x2030ac 0x2030f4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC(RValue const*, unsigned int*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2030ac push {r3, r4, r5, r6, r7, lr}
 *   @0x2030b0 mov r5, r0
 *   @0x2030b4 ldr r3, [r0, #0x4]
 *   @0x2030b8 mov r6, r1
 *   @0x2030bc mov r7, r2
 *   @0x2030c0 cmp r3, #0
 *   @0x2030c4 pople {r3, r4, r5, r6, r7, pc}
 *   @0x2030c8 mov r4, #0
 *   @0x2030cc ldr r0, [r5, #0xc]
 *   @0x2030d0 mov r1, r6
 *   @0x2030d4 mov r2, r7
 *   @0x2030d8 add r0, r0, r4, lsl #4
 *   @0x2030dc add r4, r4, #1
 *   @0x2030e0 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x2030e4 ldr r3, [r5, #0x4]
 *   @0x2030e8 cmp r3, r4
 *   @0x2030ec bgt 0x2030cc <_ZN8CDS_List7Mark4GCEPji+0x20>
 *   @0x2030f0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §253/289 CTimingSource::Reset  0x214728  size 72  18 条（0x214728..0x214770）
 * @func 0x214728 0x214770  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::Reset()+0x30 / Timing_Time
 * 字段偏移 top8: 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214728 vldr d7, [r0, #24]
 *   @0x21472c vcmpe.f64 d7, #0
 *   @0x214730 push {r4, lr}
 *   @0x214734 mov r2, #0
 *   @0x214738 mov r3, #0
 *   @0x21473c mov r4, r0
 *   @0x214740 vmrs APSR_nzcv, fpscr
 *   @0x214744 strd r2, r3, [r0]
 *   @0x214748 strdle r2, r3, [r0, #8]
 *   @0x21474c ble 0x214758 <_ZN13CTimingSource5ResetEv+0x30>
 *   @0x214750 bl 0x215148 <Timing_Time>
 *   @0x214754 strd r0, r1, [r4, #8]
 *   @0x214758 mov r2, #0
 *   @0x21475c mov r3, #0
 *   @0x214760 mov r1, #0
 *   @0x214764 strd r2, r3, [r4, #32]
 *   @0x214768 strb r1, [r4, #0x10]
 *   @0x21476c pop {r4, pc}
 *
 * ══ §254/289 Audio_SetListenerPosition  0x2165c0  size 72  18 条（0x2165c0..0x216608）
 * @func 0x2165c0 0x216608  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2165c0 cmp r0, #0
 *   @0x2165c4 vmov d7, r2, r3
 *   @0x2165c8 bxne lr
 *   @0x2165cc ldr r3, [pc, #0x30]
 *   @0x2165d0 ldr r3, [pc, r3]
 *   @0x2165d4 ldr r3, [r3]
 *   @0x2165d8 cmp r3, #0
 *   @0x2165dc bxeq lr
 *   @0x2165e0 vcvt.f32.f64 s14, d7
 *   @0x2165e4 vldr d5, [sp]
 *   @0x2165e8 vcvt.f32.f64 s13, d5
 *   @0x2165ec vldr d5, [sp, #8]
 *   @0x2165f0 vstr s14, [r3]
 *   @0x2165f4 vcvt.f32.f64 s15, d5
 *   @0x2165f8 vstr s13, [r3, #4]
 *   @0x2165fc vstr s15, [r3, #8]
 *   @0x216600 bx lr
 *   @0x216604 andseq r10, sp, r12, lsl #28
 *
 * ══ §255/289 SOggChannel::~SOggChannel  0x2234d0  size 72  18 条（0x2234d0..0x223518）
 * @func 0x2234d0 0x223518  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6ae4 / 0xb655c / ov_clear
 * 字段偏移 top8: 0x2d4×2 / 0x29c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2234d0 ldrb r3, [r0, #0x2d4]
 *   @0x2234d4 push {r4, lr}
 *   @0x2234d8 cmp r3, #0
 *   @0x2234dc mov r4, r0
 *   @0x2234e0 beq 0x2234f8 <_ZN11SOggChannelD2Ev+0x28>
 *   @0x2234e4 mov r0, #2
 *   @0x2234e8 add r1, r4, #684
 *   @0x2234ec bl 0xb6ae4 <alDeleteBuffers@plt>
 *   @0x2234f0 mov r3, #0
 *   @0x2234f4 strb r3, [r4, #0x2d4]
 *   @0x2234f8 ldr r0, [r4, #0x29c]
 *   @0x2234fc bl 0xb655c <free@plt>
 *   @0x223500 mov r3, #0
 *   @0x223504 mov r0, r4
 *   @0x223508 str r3, [r4, #0x29c]
 *   @0x22350c bl 0x230ec4 <ov_clear>
 *   @0x223510 mov r0, r4
 *   @0x223514 pop {r4, pc}
 *
 * ══ §256/289 CPhysicsObject::SetPosition  0x236e00  size 72  18 条（0x236e00..0x236e48）
 * @func 0x236e00 0x236e48  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::SetTransform(b2Vec2 const&, float)
 * 字段偏移 top8: 0x4×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236e00 push {r4, lr}
 *   @0x236e04 mov r4, r0
 *   @0x236e08 ldr r0, [r0]
 *   @0x236e0c sub sp, sp, #8
 *   @0x236e10 str r1, [sp]
 *   @0x236e14 mov r1, sp
 *   @0x236e18 str r2, [sp, #0x4]
 *   @0x236e1c ldr r2, [r0, #0x48]
 *   @0x236e20 bl 0x2c71c4 <_ZN6b2Body12SetTransformERK6b2Vec2f>
 *   @0x236e24 ldr r3, [r4]
 *   @0x236e28 ldrh r2, [r3, #4]
 *   @0x236e2c tst r2, #2
 *   @0x236e30 orreq r2, r2, #2
 *   @0x236e34 strheq r2, [r3, #4]
 *   @0x236e38 moveq r1, #0
 *   @0x236e3c streq r1, [r3, #0xa0]
 *   @0x236e40 add sp, sp, #8
 *   @0x236e44 pop {r4, pc}
 *
 * ══ §257/289 CPhysicsWorld::DestroyJoints  0x237f48  size 72  18 条（0x237f48..0x237f90）
 * @func 0x237f48 0x237f90  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsJointFactory::FindJoint(b2Joint*) / CPhysicsJointFactory::DestroyJoint(CPhysicsWorld*, unsigned int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237f48 ldr r2, [r0, #0x10]
 *   @0x237f4c push {r3, r4, r5, lr}
 *   @0x237f50 movw r3, #0x922c
 *   @0x237f54 movt r3, #0x1
 *   @0x237f58 mov r5, r0
 *   @0x237f5c ldr r3, [r2, r3]
 *   @0x237f60 cmp r3, #0
 *   @0x237f64 popeq {r3, r4, r5, pc}
 *   @0x237f68 mov r0, r3
 *   @0x237f6c ldr r4, [r3, #0xc]
 *   @0x237f70 bl 0x23b47c <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint>
 *   @0x237f74 ldr r1, [r0, #0x8]
 *   @0x237f78 mov r0, r5
 *   @0x237f7c bl 0x23b3c4 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj>
 *   @0x237f80 cmp r4, #0
 *   @0x237f84 mov r3, r4
 *   @0x237f88 bne 0x237f68 <_ZN13CPhysicsWorld13DestroyJointsEv+0x20>
 *   @0x237f8c pop {r3, r4, r5, pc}
 *
 * ══ §258/289 JS_GetProperty  0x2418dc  size 72  18 条（0x2418dc..0x241924）
 * @func 0x2418dc 0x241924  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_GetOwnProperty(YYObjectBase*, RValue*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2418dc push {r3, r4, r5, r6, r7, lr}
 *   @0x2418e0 mov r4, r0
 *   @0x2418e4 mov r5, r1
 *   @0x2418e8 mov r7, r2
 *   @0x2418ec mvn r6, #-16777216
 *   @0x2418f0 mov r0, r4
 *   @0x2418f4 mov r1, r5
 *   @0x2418f8 mov r2, r7
 *   @0x2418fc bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241900 ldr r3, [r5, #0xc]
 *   @0x241904 bic r3, r3, #-16777216
 *   @0x241908 cmp r3, r6
 *   @0x24190c popne {r3, r4, r5, r6, r7, pc}
 *   @0x241910 ldr r4, [r4, #0x18]
 *   @0x241914 cmp r4, #0
 *   @0x241918 bne 0x2418f0 <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc+0x14>
 *   @0x24191c str r6, [r5, #0xc]
 *   @0x241920 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §259/289 JS_DefineOwnProperty  0x248394  size 72  18 条（0x248394..0x2483dc）
 * @func 0x248394 0x2483dc  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x248394 push {r4, lr}
 *   @0x248398 ldr r4, [r0, #0x54]
 *   @0x24839c cmp r4, #0
 *   @0x2483a0 bne 0x2483cc <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x38>
 *   @0x2483a4 ldr r12, [r0, #0x18]
 *   @0x2483a8 cmp r12, #0
 *   @0x2483ac bne 0x2483c0 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x2c>
 *   @0x2483b0 b 0x2483d4 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x40>
 *   @0x2483b4 ldr r12, [r12, #0x18]
 *   @0x2483b8 cmp r12, #0
 *   @0x2483bc beq 0x2483d4 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x40>
 *   @0x2483c0 ldr r4, [r12, #0x54]
 *   @0x2483c4 cmp r4, #0
 *   @0x2483c8 beq 0x2483b4 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x20>
 *   @0x2483cc blx r4
 *   @0x2483d0 pop {r4, pc}
 *   @0x2483d4 pop {r4, lr}
 *   @0x2483d8 b 0x247d44 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb>
 *
 * ══ §260/289 json_object_new_string  0x27ecc0  size 72  18 条（0x27ecc0..0x27ed08）
 * @func 0x27ecc0 0x27ed08  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_27e408+0x31c / 0xb6640
 * 字段偏移 top8: 0x20×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ecc0 push {r3, r4, r5, lr}
 *   @0x27ecc4 mov r5, r0
 *   @0x27ecc8 mov r0, #6
 *   @0x27eccc bl 0x27e724 <mc_info+0x35c>
 *   @0x27ecd0 subs r4, r0, #0
 *   @0x27ecd4 beq 0x27ecf8 <json_object_new_string+0x38>
 *   @0x27ecd8 ldr r2, [pc, #0x20]
 *   @0x27ecdc mov r0, r5
 *   @0x27ece0 ldr r3, [pc, #0x1c]
 *   @0x27ece4 add r2, pc, r2
 *   @0x27ece8 add r3, pc, r3
 *   @0x27ecec stmib r4, {r2, r3}
 *   @0x27ecf0 bl 0xb6640 <strdup@plt>
 *   @0x27ecf4 str r0, [r4, #0x18]
 *   @0x27ecf8 mov r0, r4
 *   @0x27ecfc pop {r3, r4, r5, pc}
 *   @0x27ed00 .word 0xfffffa14
 *   @0x27ed04 .word 0xfffff98c
 *
 * ══ §261/289 lh_table_free  0x28094c  size 72  18 条（0x28094c..0x280994）
 * @func 0x28094c 0x280994  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 0x20×1 / 0x2c×1 / 0x8×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28094c push {r3, r4, r5, lr}
 *   @0x280950 mov r5, r0
 *   @0x280954 ldr r4, [r0, #0x20]
 *   @0x280958 cmp r4, #0
 *   @0x28095c beq 0x280980 <lh_table_free+0x34>
 *   @0x280960 ldr r3, [r5, #0x2c]
 *   @0x280964 mov r0, r4
 *   @0x280968 cmp r3, #0
 *   @0x28096c beq 0x280974 <lh_table_free+0x28>
 *   @0x280970 blx r3
 *   @0x280974 ldr r4, [r4, #0x8]
 *   @0x280978 cmp r4, #0
 *   @0x28097c bne 0x280960 <lh_table_free+0x14>
 *   @0x280980 ldr r0, [r5, #0x28]
 *   @0x280984 bl 0xb655c <free@plt>
 *   @0x280988 mov r0, r5
 *   @0x28098c pop {r3, r4, r5, lr}
 *   @0x280990 b 0xb655c <free@plt>
 *
 * ══ §262/289 spBone_create  0x2853c8  size 72  18 条（0x2853c8..0x285410）
 * @func 0x2853c8 0x285410  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / spBone_setToSetupPose
 * 字段偏移 top8: 0x34×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2853c8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2853cc mov r5, r2
 *   @0x2853d0 ldr r2, [pc, #0x34]
 *   @0x2853d4 mov r7, r0
 *   @0x2853d8 mov r6, r1
 *   @0x2853dc mov r3, #46
 *   @0x2853e0 mov r1, #88
 *   @0x2853e4 add r2, pc, r2
 *   @0x2853e8 mov r0, #1
 *   @0x2853ec bl 0x285c4c <_calloc>
 *   @0x2853f0 mov r4, r0
 *   @0x2853f4 str r7, [r0]
 *   @0x2853f8 str r6, [r0, #0x4]
 *   @0x2853fc str r5, [r0, #0x8]
 *   @0x285400 bl 0x285388 <spBone_setToSetupPose>
 *   @0x285404 mov r0, r4
 *   @0x285408 pop {r3, r4, r5, r6, r7, pc}
 *   @0x28540c andeq r2, sp, r4, lsl #6
 *
 * ══ §263/289 spBone_localToWorld  0x2859fc  size 72  18 条（0x2859fc..0x285a44）
 * @func 0x2859fc 0x285a44  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2859fc vmov s15, r2
 *   @0x285a00 vldr s14, [r0, #56]
 *   @0x285a04 vmov s13, r1
 *   @0x285a08 vldr s11, [r0, #52]
 *   @0x285a0c vmul.f32 s14, s15, s14
 *   @0x285a10 vldr s12, [r0, #60]
 *   @0x285a14 ldr r2, [sp]
 *   @0x285a18 vmla.f32 s14, s13, s11
 *   @0x285a1c vadd.f32 s14, s14, s12
 *   @0x285a20 vstr s14, [r3]
 *   @0x285a24 vldr s14, [r0, #68]
 *   @0x285a28 vmul.f32 s15, s15, s14
 *   @0x285a2c vldr s12, [r0, #64]
 *   @0x285a30 vldr s14, [r0, #72]
 *   @0x285a34 vmla.f32 s15, s13, s12
 *   @0x285a38 vadd.f32 s15, s15, s14
 *   @0x285a3c vstr s15, [r2]
 *   @0x285a40 bx lr
 *
 * ══ §264/289 b2BlockAllocator::~b2BlockAllocator  0x2c6578  size 72  18 条（0x2c6578..0x2c65c0）
 * @func 0x2c6578 0x2c65c0  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Free(void*)×2 / b2BlockAllocator::~b2BlockAllocator()+0x38
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6578 push {r3, r4, r5, lr}
 *   @0x2c657c mov r5, r0
 *   @0x2c6580 ldr r3, [r0, #0x4]
 *   @0x2c6584 cmp r3, #0
 *   @0x2c6588 ble 0x2c65b0 <_ZN16b2BlockAllocatorD2Ev+0x38>
 *   @0x2c658c mov r4, #0
 *   @0x2c6590 ldr r3, [r5]
 *   @0x2c6594 add r3, r3, r4, lsl #3
 *   @0x2c6598 add r4, r4, #1
 *   @0x2c659c ldr r0, [r3, #0x4]
 *   @0x2c65a0 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c65a4 ldr r3, [r5, #0x4]
 *   @0x2c65a8 cmp r3, r4
 *   @0x2c65ac bgt 0x2c6590 <_ZN16b2BlockAllocatorD2Ev+0x18>
 *   @0x2c65b0 ldr r0, [r5]
 *   @0x2c65b4 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c65b8 mov r0, r5
 *   @0x2c65bc pop {r3, r4, r5, pc}
 *
 * ══ §265/289 b2BroadPhase::b2BroadPhase  0x2dc7ac  size 72  18 条（0x2dc7ac..0x2dc7f4）
 * @func 0x2dc7ac 0x2dc7f4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int)×2 / b2DynamicTree::b2DynamicTree()
 * 字段偏移 top8: 0x1c×1 / 0x34×1 / 0x30×1 / 0x24×1 / 0x28×1 / 0x2c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc7ac push {r4, r5, r6, lr}
 *   @0x2dc7b0 mov r4, r0
 *   @0x2dc7b4 bl 0x2de900 <_ZN13b2DynamicTreeC2Ev>
 *   @0x2dc7b8 mov r5, #0
 *   @0x2dc7bc mov r6, #16
 *   @0x2dc7c0 str r5, [r4, #0x1c]
 *   @0x2dc7c4 mov r0, #128
 *   @0x2dc7c8 str r5, [r4, #0x34]
 *   @0x2dc7cc str r6, [r4, #0x30]
 *   @0x2dc7d0 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2dc7d4 str r6, [r4, #0x24]
 *   @0x2dc7d8 str r5, [r4, #0x28]
 *   @0x2dc7dc str r0, [r4, #0x2c]
 *   @0x2dc7e0 mov r0, #64
 *   @0x2dc7e4 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2dc7e8 str r0, [r4, #0x20]
 *   @0x2dc7ec mov r0, r4
 *   @0x2dc7f0 pop {r4, r5, r6, pc}
 *
 * ══ §266/289 YYSetString  0xdc308  size 68  17 条（0xdc308..0xdc34c）
 * @func 0xdc308 0xdc34c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / 0xb6538 / YYStrDup(char const*)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdc308 push {r4, r5, r6, lr}
 *   @0xdc30c mov r6, r0
 *   @0xdc310 mov r0, #12
 *   @0xdc314 mov r5, r1
 *   @0xdc318 bl 0x27c524 <_Znwj>
 *   @0xdc31c mov r4, r0
 *   @0xdc320 subs r0, r5, #0
 *   @0xdc324 beq 0xdc32c <_Z11YYSetStringP6RValuePKc+0x24>
 *   @0xdc328 bl 0xb6538 <strlen@plt>
 *   @0xdc32c str r0, [r4, #0x8]
 *   @0xdc330 mov r0, r5
 *   @0xdc334 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xdc338 mov r3, #1
 *   @0xdc33c stm r4, {r0, r3}
 *   @0xdc340 str r3, [r6, #0xc]
 *   @0xdc344 str r4, [r6]
 *   @0xdc348 pop {r4, r5, r6, pc}
 *
 * ══ §267/289 GR_Surface_Get_Width  0x1714d4  size 68  17 条（0x1714d4..0x171518）
 * @func 0x1714d4 0x171518  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int)
 * 字段偏移 top8: 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1714d4 push {r3, lr}
 *   @0x1714d8 ldr r3, [pc, #0x30]
 *   @0x1714dc ldr r3, [pc, r3]
 *   @0x1714e0 ldr r3, [r3]
 *   @0x1714e4 cmp r0, r3
 *   @0x1714e8 beq 0x171500 <_Z20GR_Surface_Get_Widthi+0x2c>
 *   @0x1714ec bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x1714f0 cmp r0, #0
 *   @0x1714f4 ldrne r0, [r0, #0x8]
 *   @0x1714f8 mvneq r0, #0
 *   @0x1714fc pop {r3, pc}
 *   @0x171500 ldr r3, [pc, #0xc]
 *   @0x171504 ldr r3, [pc, r3]
 *   @0x171508 ldr r0, [r3]
 *   @0x17150c pop {r3, pc}
 *   @0x171510 .word 0x0027d0fc
 *   @0x171514 eoreq lr, r7, r4, lsl #13
 *
 * ══ §268/289 GR_Surface_Get_Height  0x171518  size 68  17 条（0x171518..0x17155c）
 * @func 0x171518 0x17155c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int)
 * 字段偏移 top8: 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171518 push {r3, lr}
 *   @0x17151c ldr r3, [pc, #0x30]
 *   @0x171520 ldr r3, [pc, r3]
 *   @0x171524 ldr r3, [r3]
 *   @0x171528 cmp r0, r3
 *   @0x17152c beq 0x171544 <_Z21GR_Surface_Get_Heighti+0x2c>
 *   @0x171530 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x171534 cmp r0, #0
 *   @0x171538 ldrne r0, [r0, #0xc]
 *   @0x17153c mvneq r0, #0
 *   @0x171540 pop {r3, pc}
 *   @0x171544 ldr r3, [pc, #0xc]
 *   @0x171548 ldr r3, [pc, r3]
 *   @0x17154c ldr r0, [r3]
 *   @0x171550 pop {r3, pc}
 *   @0x171554 strhteq sp, [r7], -r8
 *   @0x171558 eoreq lr, r7, r8, asr #12
 *
 * ══ §269/289 GR_Texture_Exists  0x173e2c  size 68  17 条（0x173e2c..0x173e70）
 * @func 0x173e2c 0x173e70  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)+0x34
 * 字段偏移 top8: 0x2c×1 / 0x1c×1 / 0x4×1 / 0x2×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173e2c cmp r0, #0
 *   @0x173e30 blt 0x173e60 <_Z17GR_Texture_Existsi+0x34>
 *   @0x173e34 ldr r3, [pc, #0x2c]
 *   @0x173e38 ldr r3, [pc, r3]
 *   @0x173e3c ldr r3, [r3]
 *   @0x173e40 cmp r0, r3
 *   @0x173e44 bge 0x173e60 <_Z17GR_Texture_Existsi+0x34>
 *   @0x173e48 ldr r3, [pc, #0x1c]
 *   @0x173e4c ldr r3, [pc, r3]
 *   @0x173e50 ldr r3, [r3, #0x4]
 *   @0x173e54 ldr r3, [r3, r0, lsl #2]
 *   @0x173e58 ldrb r0, [r3, #0x10]
 *   @0x173e5c bx lr
 *   @0x173e60 mov r0, #0
 *   @0x173e64 bx lr
 *   @0x173e68 eoreq r12, r7, r8, ror r4
 *   @0x173e6c .word 0x00279ad0
 *
 * ══ §270/289 popRenderBufferStack  0x1807a8  size 68  17 条（0x1807a8..0x1807ec）
 * @func 0x1807a8 0x1807ec  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: initRenderBufferStack()
 * 字段偏移 top8: 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1807a8 push {r3, lr}
 *   @0x1807ac ldr r3, [pc, #0x30]
 *   @0x1807b0 ldr r3, [pc, r3]
 *   @0x1807b4 ldrb r3, [r3]
 *   @0x1807b8 cmp r3, #0
 *   @0x1807bc beq 0x1807dc <_Z20popRenderBufferStackv+0x34>
 *   @0x1807c0 ldr r2, [pc, #0x20]
 *   @0x1807c4 add r2, pc, r2
 *   @0x1807c8 ldr r3, [r2]
 *   @0x1807cc subs r3, r3, #1
 *   @0x1807d0 movmi r3, #0
 *   @0x1807d4 str r3, [r2]
 *   @0x1807d8 pop {r3, pc}
 *   @0x1807dc bl 0x180650 <_Z21initRenderBufferStackv>
 *   @0x1807e0 b 0x1807c0 <_Z20popRenderBufferStackv+0x18>
 *   @0x1807e4 eoreq pc, r6, r4, lsl #27
 *   @0x1807e8 eorseq r1, r2, r8, lsr r12
 *
 * ══ §271/289 ParticleSystem_Destroy  0x1a454c  size 68  17 条（0x1a454c..0x1a4590）
 * @func 0x1a454c 0x1a4590  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int) / ParticleSystem_Clear(int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a454c push {r3, r4, r5, lr}
 *   @0x1a4550 mov r4, r0
 *   @0x1a4554 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a4558 cmp r0, #0
 *   @0x1a455c popeq {r3, r4, r5, pc}
 *   @0x1a4560 ldr r5, [pc, #0x24]
 *   @0x1a4564 mov r0, r4
 *   @0x1a4568 bl 0x1a4180 <_Z20ParticleSystem_Cleari>
 *   @0x1a456c ldr r5, [pc, r5]
 *   @0x1a4570 ldr r3, [r5, #0x4]
 *   @0x1a4574 ldr r0, [r3, r4, lsl #2]
 *   @0x1a4578 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a457c ldr r3, [r5, #0x4]
 *   @0x1a4580 mov r2, #0
 *   @0x1a4584 str r2, [r3, r4, lsl #2]
 *   @0x1a4588 pop {r3, r4, r5, pc}
 *   @0x1a458c eoreq r12, r4, r12, asr #4
 *
 * ══ §272/289 DestroyDsMap  0x205334  size 68  17 条（0x205334..0x205378）
 * @func 0x205334 0x205378  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsMapDestroy(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x24×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x205334 vmov s13, r0
 *   @0x205338 mov r12, #0
 *   @0x20533c str lr, [sp, #-0x4]!
 *   @0x205340 vcvt.f64.s32 d7, s13
 *   @0x205344 sub sp, sp, #44
 *   @0x205348 mov r1, r12
 *   @0x20534c add r3, sp, #24
 *   @0x205350 mov r2, r12
 *   @0x205354 str r3, [sp]
 *   @0x205358 add r0, sp, #8
 *   @0x20535c mov r3, #1
 *   @0x205360 str r12, [sp, #0x8]
 *   @0x205364 str r12, [sp, #0x24]
 *   @0x205368 vstr d7, [sp, #24]
 *   @0x20536c bl 0xfec90 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_>
 *   @0x205370 add sp, sp, #44
 *   @0x205374 ldr pc, [sp], #4
 *
 * ══ §273/289 vorbis_staticbook_destroy  0x22f554  size 68  17 条（0x22f554..0x22f598）
 * @func 0x22f554 0x22f598  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2 / 0xb65b0
 * 字段偏移 top8: 0x20×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22f554 push {r4, lr}
 *   @0x22f558 mov r4, r0
 *   @0x22f55c ldr r0, [r0, #0x20]
 *   @0x22f560 cmp r0, #0
 *   @0x22f564 beq 0x22f56c <vorbis_staticbook_destroy+0x18>
 *   @0x22f568 bl 0xb655c <free@plt>
 *   @0x22f56c ldr r0, [r4, #0x8]
 *   @0x22f570 cmp r0, #0
 *   @0x22f574 beq 0x22f57c <vorbis_staticbook_destroy+0x28>
 *   @0x22f578 bl 0xb655c <free@plt>
 *   @0x22f57c mov r0, r4
 *   @0x22f580 mov r1, #0
 *   @0x22f584 mov r2, #36
 *   @0x22f588 bl 0xb65b0 <memset@plt>
 *   @0x22f58c mov r0, r4
 *   @0x22f590 pop {r4, lr}
 *   @0x22f594 b 0xb655c <free@plt>
 *
 * ══ §274/289 CPhysicsFixture::AllocVertices  0x23658c  size 68  17 条（0x23658c..0x2365d0）
 * @func 0x23658c 0x2365d0  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x14×2 / 0x30×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23658c push {r4, lr}
 *   @0x236590 sub sp, sp, #8
 *   @0x236594 ldr r2, [pc, #0x30]
 *   @0x236598 mov r4, r0
 *   @0x23659c mov r3, r1
 *   @0x2365a0 ldr r0, [r0, #0x14]
 *   @0x2365a4 mov r12, #0
 *   @0x2365a8 str r3, [r4, #0x10]
 *   @0x2365ac lsl r1, r1, #3
 *   @0x2365b0 add r2, pc, r2
 *   @0x2365b4 mov r3, #105
 *   @0x2365b8 str r12, [sp]
 *   @0x2365bc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x2365c0 str r0, [r4, #0x14]
 *   @0x2365c4 add sp, sp, #8
 *   @0x2365c8 pop {r4, pc}
 *   @0x2365cc andseq lr, r1, r8, lsl #23
 *
 * ══ §275/289 CPhysicsWorld::StorePreviousPositions  0x238070  size 68  17 条（0x238070..0x2380b4）
 * @func 0x238070 0x2380b4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0xa4×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238070 ldr r2, [r0, #0x10]
 *   @0x238074 movw r3, #0x9228
 *   @0x238078 movt r3, #0x1
 *   @0x23807c ldr r3, [r2, r3]
 *   @0x238080 cmp r3, #0
 *   @0x238084 bxeq lr
 *   @0x238088 ldr r2, [r3, #0xa4]
 *   @0x23808c cmp r2, #0
 *   @0x238090 ldrne r0, [r3, #0xc]
 *   @0x238094 ldrne r1, [r3, #0x10]
 *   @0x238098 ldrne r2, [r2, #0x84]
 *   @0x23809c strne r0, [r2, #0xc]
 *   @0x2380a0 strne r1, [r2, #0x10]
 *   @0x2380a4 ldr r3, [r3, #0x70]
 *   @0x2380a8 cmp r3, #0
 *   @0x2380ac bne 0x238088 <_ZN13CPhysicsWorld22StorePreviousPositionsEv+0x18>
 *   @0x2380b0 bx lr
 *
 * ══ §276/289 freedtoa  0x23dd68  size 68  17 条（0x23dd68..0x23ddac）
 * @func 0x23dd68 0x23ddac  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Bfree_D2A
 * 字段偏移 top8: 0x-4×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23dd68 ldr r3, [r0, #-0x4]
 *   @0x23dd6c mov r2, #1
 *   @0x23dd70 push {r4, lr}
 *   @0x23dd74 mov r4, r0
 *   @0x23dd78 lsl r2, r2, r3
 *   @0x23dd7c str r3, [r4]
 *   @0x23dd80 str r2, [r4, #0x4]
 *   @0x23dd84 sub r0, r0, #4
 *   @0x23dd88 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23dd8c ldr r3, [pc, #0x14]
 *   @0x23dd90 ldr r3, [pc, r3]
 *   @0x23dd94 ldr r2, [r3]
 *   @0x23dd98 cmp r4, r2
 *   @0x23dd9c moveq r2, #0
 *   @0x23dda0 streq r2, [r3]
 *   @0x23dda4 pop {r4, pc}
 *   @0x23dda8 andseq r3, r11, r8, ror r7
 *
 * ══ §277/289 yySocket::HandleMessage  0x296dd8  size 68  17 条（0x296dd8..0x296e1c）
 * @func 0x296dd8 0x296e1c  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyServer::ProcessDataPacket(yySocket*, unsigned char*, int) / yySocket::SendDataToEvent(int, unsigned char*)
 * 字段偏移 top8: 0xc0×2 / 0x50×2 / 0xbc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296dd8 cmp r1, #0
 *   @0x296ddc ldr r3, [r0, #0xc0]
 *   @0x296de0 push {r4, lr}
 *   @0x296de4 mov r4, r0
 *   @0x296de8 beq 0x296e0c <_ZN8yySocket13HandleMessageEP8yyServer+0x34>
 *   @0x296dec mov r0, r1
 *   @0x296df0 ldr r2, [r4, #0x50]
 *   @0x296df4 mov r1, r4
 *   @0x296df8 bl 0x2975a4 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi>
 *   @0x296dfc mov r3, #0
 *   @0x296e00 str r3, [r4, #0xbc]
 *   @0x296e04 str r3, [r4, #0xc0]
 *   @0x296e08 pop {r4, pc}
 *   @0x296e0c mov r1, r3
 *   @0x296e10 ldr r2, [r0, #0x50]
 *   @0x296e14 bl 0x296b08 <_ZN8yySocket15SendDataToEventEiPh>
 *   @0x296e18 b 0x296dfc <_ZN8yySocket13HandleMessageEP8yyServer+0x24>
 *
 * ══ §278/289 b2ContactManager::b2ContactManager  0x2c7850  size 68  17 条（0x2c7850..0x2c7894）
 * @func 0x2c7850 0x2c7894  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BroadPhase::b2BroadPhase()
 * 字段偏移 top8: 0x28×1 / 0x24×1 / 0x3c×1 / 0x44×1 / 0x40×1 / 0x48×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7850 push {r4, lr}
 *   @0x2c7854 mov r4, r0
 *   @0x2c7858 bl 0x2dc7ac <_ZN12b2BroadPhaseC2Ev>
 *   @0x2c785c ldr r1, [pc, #0x28]
 *   @0x2c7860 mov r3, #0
 *   @0x2c7864 ldr r2, [pc, #0x24]
 *   @0x2c7868 mov r0, r4
 *   @0x2c786c ldr r1, [pc, r1]
 *   @0x2c7870 str r3, [r4, #0x3c]
 *   @0x2c7874 ldr r2, [pc, r2]
 *   @0x2c7878 str r1, [r4, #0x44]
 *   @0x2c787c str r3, [r4, #0x40]
 *   @0x2c7880 str r2, [r4, #0x48]
 *   @0x2c7884 str r3, [r4, #0x4c]
 *   @0x2c7888 pop {r4, pc}
 *   @0x2c788c andseq r10, r2, r8, ror r2
 *   @0x2c7890 andseq r10, r2, r4, ror r2
 *
 * ══ §279/289 b2World::QueryAABB  0x2cb89c  size 68  17 条（0x2cb89c..0x2cb8e0）
 * @func 0x2cb89c 0x2cb8e0  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: void b2DynamicTree::Query<b2WorldQueryWrapper>(b2WorldQueryWrapper*, b2AABB const&) const / b2ParticleSystem::QueryAABB(b2QueryCallback*, b2AABB const&) const
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb89c push {r4, r5, r6, lr}
 *   @0x2cb8a0 add r5, r0, #102400
 *   @0x2cb8a4 sub sp, sp, #8
 *   @0x2cb8a8 add r3, r5, #472
 *   @0x2cb8ac mov r4, r1
 *   @0x2cb8b0 mov r6, r2
 *   @0x2cb8b4 mov r0, r3
 *   @0x2cb8b8 mov r1, sp
 *   @0x2cb8bc str r3, [sp]
 *   @0x2cb8c0 str r4, [sp, #0x4]
 *   @0x2cb8c4 bl 0x2cb680 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB>
 *   @0x2cb8c8 add r0, r5, #628
 *   @0x2cb8cc mov r1, r4
 *   @0x2cb8d0 mov r2, r6
 *   @0x2cb8d4 bl 0x2d9a60 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB>
 *   @0x2cb8d8 add sp, sp, #8
 *   @0x2cb8dc pop {r4, r5, r6, pc}
 *
 * ══ §280/289 __fixdfdi  0x3194a0  size 68  17 条（0x3194a0..0x3194e4）
 * @func 0x3194a0 0x3194e4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_dcmplt / __fixunsdfdi
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3194a0 push {r3, r4, r5, lr}
 *   @0x3194a4 mov r2, #0
 *   @0x3194a8 mov r3, #0
 *   @0x3194ac mov r5, r0
 *   @0x3194b0 mov r4, r1
 *   @0x3194b4 bl 0x31b080 <__aeabi_dcmplt>
 *   @0x3194b8 cmp r0, #0
 *   @0x3194bc mov r0, r5
 *   @0x3194c0 beq 0x3194d8 <__fixdfdi+0x38>
 *   @0x3194c4 add r1, r4, #-2147483648
 *   @0x3194c8 bl 0x319550 <__fixunsdfdi>
 *   @0x3194cc rsbs r0, r0, #0
 *   @0x3194d0 rsc r1, r1, #0
 *   @0x3194d4 pop {r3, r4, r5, pc}
 *   @0x3194d8 mov r1, r4
 *   @0x3194dc pop {r3, r4, r5, lr}
 *   @0x3194e0 b 0x319550 <__fixunsdfdi>
 *
 * ══ §281/289 CSkeletonInstance::GetSkin  0xc0170  size 64  16 条（0xc0170..0xc01b0）
 * @func 0xc0170 0xc01b0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x38×1 / 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc0170 ldr r3, [r0, #0x1c]
 *   @0xc0174 cmp r3, #0
 *   @0xc0178 beq 0xc0190 <_ZNK17CSkeletonInstance7GetSkinEv+0x20>
 *   @0xc017c ldr r3, [r3, #0x38]
 *   @0xc0180 cmp r3, #0
 *   @0xc0184 beq 0xc019c <_ZNK17CSkeletonInstance7GetSkinEv+0x2c>
 *   @0xc0188 ldr r0, [r3]
 *   @0xc018c bx lr
 *   @0xc0190 ldr r0, [pc, #0x10]
 *   @0xc0194 add r0, pc, r0
 *   @0xc0198 bx lr
 *   @0xc019c ldr r0, [pc, #0x8]
 *   @0xc01a0 add r0, pc, r0
 *   @0xc01a4 bx lr
 *   @0xc01a8 eoreq lr, r6, r2, lsr #19
 *   @0xc01ac mlaeq r6, r6, r9, lr
 *
 * ══ §282/289 Background_Data  0xc3794  size 64  16 条（0xc3794..0xc37d4）
 * @func 0xc3794 0xc37d4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Data(int)+0x30
 * 字段偏移 top8: 0x28×1 / 0x18×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3794 cmp r0, #0
 *   @0xc3798 blt 0xc37c4 <_Z15Background_Datai+0x30>
 *   @0xc379c ldr r3, [pc, #0x28]
 *   @0xc37a0 ldr r3, [pc, r3]
 *   @0xc37a4 ldr r3, [r3]
 *   @0xc37a8 cmp r0, r3
 *   @0xc37ac bge 0xc37c4 <_Z15Background_Datai+0x30>
 *   @0xc37b0 ldr r3, [pc, #0x18]
 *   @0xc37b4 add r3, pc, r3
 *   @0xc37b8 ldr r3, [r3, #0x4]
 *   @0xc37bc ldr r0, [r3, r0, lsl #2]
 *   @0xc37c0 bx lr
 *   @0xc37c4 mov r0, #0
 *   @0xc37c8 bx lr
 *   @0xc37cc eorseq r10, r2, r8, lsr #3
 *   @0xc37d0 ldrshteq r6, [r11], -r4
 *
 * ══ §283/289 VM::GetBreakpoint  0xd82ec  size 64  16 条（0xd82ec..0xd832c）
 * @func 0xd82ec 0xd832c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd82ec ldr r12, [pc, #0x34]
 *   @0xd82f0 mov r3, #0
 *   @0xd82f4 ldr r12, [pc, r12]
 *   @0xd82f8 b 0xd8304 <_ZN2VM13GetBreakpointEPj+0x18>
 *   @0xd82fc cmp r3, #255
 *   @0xd8300 beq 0xd8320 <_ZN2VM13GetBreakpointEPj+0x34>
 *   @0xd8304 add r2, r12, r3, lsl #4
 *   @0xd8308 add r3, r3, #1
 *   @0xd830c ldr r1, [r2, #0x4]
 *   @0xd8310 cmp r1, r0
 *   @0xd8314 bne 0xd82fc <_ZN2VM13GetBreakpointEPj+0x10>
 *   @0xd8318 mov r0, r2
 *   @0xd831c bx lr
 *   @0xd8320 mov r0, #0
 *   @0xd8324 bx lr
 *   @0xd8328 ldrshteq r5, [r1], -r0
 *
 * ══ §284/289 GR_3D_Set_Mode  0x163170  size 64  16 条（0x163170..0x1631b0）
 * @func 0x163170 0x1631b0  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush() / GR_D3D_Set_Perspective(bool) / SetZBuffer(bool)
 * 字段偏移 top8: 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163170 push {r3, r4, r5, lr}
 *   @0x163174 mov r5, r0
 *   @0x163178 ldr r4, [pc, #0x2c]
 *   @0x16317c ldr r4, [pc, r4]
 *   @0x163180 ldrb r3, [r4]
 *   @0x163184 cmp r3, r0
 *   @0x163188 beq 0x1631a4 <_Z14GR_3D_Set_Modeb+0x34>
 *   @0x16318c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x163190 mov r0, r5
 *   @0x163194 strb r5, [r4]
 *   @0x163198 bl 0x1682f0 <_Z22GR_D3D_Set_Perspectiveb>
 *   @0x16319c ldrb r0, [r4]
 *   @0x1631a0 bl 0x16841c <_Z10SetZBufferb>
 *   @0x1631a4 mov r0, #1
 *   @0x1631a8 pop {r3, r4, r5, pc}
 *   @0x1631ac eoreq r10, r8, r8, lsl #23
 *
 * ══ §285/289 GraphicsPerf::Pop  0x17bb10  size 64  16 条（0x17bb10..0x17bb50）
 * @func 0x17bb10 0x17bb50  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time
 * 字段偏移 top8: 0x30×1 / 0x1c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17bb10 ldr r3, [pc, #0x30]
 *   @0x17bb14 push {r4, lr}
 *   @0x17bb18 ldr r3, [pc, r3]
 *   @0x17bb1c ldr r2, [r3]
 *   @0x17bb20 cmp r2, #0
 *   @0x17bb24 pople {r4, pc}
 *   @0x17bb28 ldr r1, [pc, #0x1c]
 *   @0x17bb2c sub r2, r2, #1
 *   @0x17bb30 str r2, [r3]
 *   @0x17bb34 ldr r1, [pc, r1]
 *   @0x17bb38 ldr r4, [r1, r2, lsl #2]
 *   @0x17bb3c bl 0x215148 <Timing_Time>
 *   @0x17bb40 strd r0, r1, [r4, #8]
 *   @0x17bb44 pop {r4, pc}
 *   @0x17bb48 eoreq r4, r7, r4, lsl r8
 *   @0x17bb4c eoreq r4, r7, r0, asr r8
 *
 * ══ §286/289 YYObjectBase::FindValue  0x196b84  size 64  16 条（0x196b84..0x196bc4）
 * @func 0x196b84 0x196bc4  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Variable_Find_Slot_From_Name(YYObjectBase*, char const*)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x196b84 push {r4, lr}
 *   @0x196b88 mov r4, r0
 *   @0x196b8c bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x196b90 cmn r0, #1
 *   @0x196b94 mov r1, r0
 *   @0x196b98 beq 0x196bbc <_ZN12YYObjectBase9FindValueEPKc+0x38>
 *   @0x196b9c ldr r3, [r4, #0x4]
 *   @0x196ba0 cmp r3, #0
 *   @0x196ba4 beq 0x196bb0 <_ZN12YYObjectBase9FindValueEPKc+0x2c>
 *   @0x196ba8 add r0, r3, r0, lsl #4
 *   @0x196bac pop {r4, pc}
 *   @0x196bb0 mov r0, r4
 *   @0x196bb4 pop {r4, lr}
 *   @0x196bb8 b 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x196bbc mov r0, #0
 *   @0x196bc0 pop {r4, pc}
 *
 * ══ §287/289 Path_Data  0x1a815c  size 64  16 条（0x1a815c..0x1a819c）
 * @func 0x1a815c 0x1a819c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Path_Data(int)+0x30
 * 字段偏移 top8: 0x28×1 / 0x18×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a815c cmp r0, #0
 *   @0x1a8160 blt 0x1a818c <_Z9Path_Datai+0x30>
 *   @0x1a8164 ldr r3, [pc, #0x28]
 *   @0x1a8168 ldr r3, [pc, r3]
 *   @0x1a816c ldr r3, [r3]
 *   @0x1a8170 cmp r0, r3
 *   @0x1a8174 bge 0x1a818c <_Z9Path_Datai+0x30>
 *   @0x1a8178 ldr r3, [pc, #0x18]
 *   @0x1a817c add r3, pc, r3
 *   @0x1a8180 ldr r3, [r3, #0x4]
 *   @0x1a8184 ldr r0, [r3, r0, lsl #2]
 *   @0x1a8188 bx lr
 *   @0x1a818c mov r0, #0
 *   @0x1a8190 bx lr
 *   @0x1a8194 eoreq r8, r4, r4, ror #12
 *   @0x1a8198 eorseq r10, r9, r12, lsr #7
 *
 * ══ §288/289 Script_Data  0x1e069c  size 64  16 条（0x1e069c..0x1e06dc）
 * @func 0x1e069c 0x1e06dc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Script_Data(int)+0x30
 * 字段偏移 top8: 0x28×1 / 0x18×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e069c cmp r0, #0
 *   @0x1e06a0 blt 0x1e06cc <_Z11Script_Datai+0x30>
 *   @0x1e06a4 ldr r3, [pc, #0x28]
 *   @0x1e06a8 ldr r3, [pc, r3]
 *   @0x1e06ac ldr r3, [r3]
 *   @0x1e06b0 cmp r0, r3
 *   @0x1e06b4 bge 0x1e06cc <_Z11Script_Datai+0x30>
 *   @0x1e06b8 ldr r3, [pc, #0x18]
 *   @0x1e06bc ldr r3, [pc, r3]
 *   @0x1e06c0 ldr r3, [r3, #0x4]
 *   @0x1e06c4 ldr r0, [r3, r0, lsl #2]
 *   @0x1e06c8 bx lr
 *   @0x1e06cc mov r0, #0
 *   @0x1e06d0 bx lr
 *   @0x1e06d4 eoreq r0, r1, r4, lsl #13
 *   @0x1e06d8 eoreq r0, r1, r12, ror #12
 *
 * ══ §289/289 CCamera::GetCamPos  0x16d3a0  size 28  7 条（0x16d3a0..0x16d3bc）
 * @func 0x16d3a0 0x16d3bc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x138×1 / 0x134×1 / 0x4×1 / 0x13c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d3a0 ldr r2, [r1, #0x138]
 *   @0x16d3a4 ldr r12, [r1, #0x134]
 *   @0x16d3a8 str r2, [r0, #0x4]
 *   @0x16d3ac ldr r2, [r1, #0x13c]
 *   @0x16d3b0 str r12, [r0]
 *   @0x16d3b4 str r2, [r0, #0x8]
 *   @0x16d3b8 bx lr
 */
