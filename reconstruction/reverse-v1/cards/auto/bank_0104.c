/* libyoyo.so 覆盖卡组 0104
 * 函数 0x167ef4..0x1689f4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x167ef4 · RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int) · size=152 · insn=38 */
/* @0x167ef4 add r1, r1, r1, lsl #2 */
/* @0x167ef8 push {r4, r5, r6, r7, r8} */
/* @0x167efc add r2, r2, r1, lsl #1 */
/* @0x167f00 add r12, r0, r2, lsl #2 */
/* @0x167f04 ldr r1, [r12, #0x270] */
/* @0x167f08 cmp r1, r3 */
/* @0x167f0c beq 0x167f5c <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej+0x68> */
/* @0x167f10 ldr r1, [r12, #0xa0] */
/* @0x167f14 cmp r1, r3 */
/* @0x167f18 mov r1, #1 */
/* @0x167f1c beq 0x167f64 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej+0x70> */
/* @0x167f20 sub r6, r2, #32 */
/* @0x167f24 rsb r8, r2, #32 */
/* @0x167f28 lsl r5, r1, r6 */
/* @0x167f2c ldrd r6, r7, [r0, #8] */
/* @0x167f30 orr r5, r5, r1, lsr r8 */
/* @0x167f34 lsl r4, r1, r2 */
/* @0x167f38 orr r4, r4, r6 */
/* @0x167f3c orr r5, r5, r7 */
/* @0x167f40 strd r4, r5, [r0, #8] */
/* @0x167f44 str r3, [r12, #0x270] */
/* @0x167f48 mov r1, #944 */
/* @0x167f4c ldrd r2, r3, [r0] */
/* @0x167f50 orr r2, r2, r4 */
/* @0x167f54 orr r3, r3, r5 */
/* @0x167f58 strd r2, r3, [r0, r1] */
/* @0x167f5c pop {r4, r5, r6, r7, r8} */
/* @0x167f60 bx lr */
/* @0x167f64 sub r4, r2, #32 */
/* @0x167f68 rsb r8, r2, #32 */
/* @0x167f6c lsl r7, r1, r4 */
/* @0x167f70 ldrd r4, r5, [r0, #8] */
/* @0x167f74 orr r7, r7, r1, lsr r8 */
/* @0x167f78 lsl r6, r1, r2 */
/* @0x167f7c bic r4, r4, r6 */
/* @0x167f80 bic r5, r5, r7 */
/* @0x167f84 strd r4, r5, [r0, #8] */
/* @0x167f88 b 0x167f44 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej+0x50> */

/* ── FUNC 0x167f8c · RenderStateManager::GetRenderState(eRenderState) · size=20 · insn=5 */
/* @0x167f8c cmp r1, #35 */
/* @0x167f90 addls r1, r1, #120 */
/* @0x167f94 ldrls r0, [r0, r1, lsl #2] */
/* @0x167f98 movhi r0, #0 */
/* @0x167f9c bx lr */

/* ── FUNC 0x167fa0 · RenderStateManager::GetSamplerState(int, eSamplerState) · size=44 · insn=11 */
/* @0x167fa0 cmp r1, #7 */
/* @0x167fa4 bhi 0x167fc4 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState+0x24> */
/* @0x167fa8 cmp r2, #9 */
/* @0x167fac bhi 0x167fc4 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState+0x24> */
/* @0x167fb0 add r1, r1, r1, lsl #2 */
/* @0x167fb4 add r2, r2, r1, lsl #1 */
/* @0x167fb8 add r2, r2, #156 */
/* @0x167fbc ldr r0, [r0, r2, lsl #2] */
/* @0x167fc0 bx lr */
/* @0x167fc4 mov r0, #0 */
/* @0x167fc8 bx lr */

/* ── FUNC 0x167fcc · RenderStateManager::SaveStates() · size=132 · insn=33 */
/* @0x167fcc push {r4, r5, r6, lr} */
/* @0x167fd0 movw r5, #0x3db8 */
/* @0x167fd4 mov r4, r0 */
/* @0x167fd8 ldr r0, [r0, r5] */
/* @0x167fdc mov r6, #464 */
/* @0x167fe0 add r1, r4, #480 */
/* @0x167fe4 mov r2, #144 */
/* @0x167fe8 mla r0, r6, r0, r4 */
/* @0x167fec add r0, r0, #952 */
/* @0x167ff0 bl 0xb65bc <memcpy@plt> */
/* @0x167ff4 ldr r3, [r4, r5] */
/* @0x167ff8 add r1, r4, #624 */
/* @0x167ffc mov r2, #320 */
/* @0x168000 mla r0, r6, r3, r4 */
/* @0x168004 add r0, r0, #1088 */
/* @0x168008 add r0, r0, #8 */
/* @0x16800c bl 0xb65bc <memcpy@plt> */
/* @0x168010 ldr r3, [r4, r5] */
/* @0x168014 cmp r3, #31 */
/* @0x168018 addle r3, r3, #1 */
/* @0x16801c strle r3, [r4, r5] */
/* @0x168020 pople {r4, r5, r6, pc} */
/* @0x168024 ldr r3, [pc, #0x1c] */
/* @0x168028 ldr r1, [pc, #0x1c] */
/* @0x16802c ldr r3, [pc, r3] */
/* @0x168030 add r1, pc, r1 */
/* @0x168034 ldr r0, [r3] */
/* @0x168038 ldr r3, [r0] */
/* @0x16803c ldr r3, [r3, #0xc] */
/* @0x168040 blx r3 */
/* @0x168044 pop {r4, r5, r6, pc} */
/* @0x168048 eoreq r5, r8, r8, ror #13 */
/* @0x16804c andseq r2, lr, r12, lsr #14 */

/* ── FUNC 0x168050 · RenderStateManager::RestoreStates() · size=228 · insn=57 */
/* @0x168050 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x168054 movw r4, #0x3db8 */
/* @0x168058 ldr r3, [r0, r4] */
/* @0x16805c mov r5, r0 */
/* @0x168060 cmp r3, #0 */
/* @0x168064 ble 0x168104 <_ZN18RenderStateManager13RestoreStatesEv+0xb4> */
/* @0x168068 sub r3, r3, #1 */
/* @0x16806c str r3, [r0, r4] */
/* @0x168070 mov r4, #0 */
/* @0x168074 mov r6, #116 */
/* @0x168078 movw r7, #0x3db8 */
/* @0x16807c b 0x168084 <_ZN18RenderStateManager13RestoreStatesEv+0x34> */
/* @0x168080 ldr r3, [r5, r7] */
/* @0x168084 mla r3, r6, r3, r4 */
/* @0x168088 mov r1, r4 */
/* @0x16808c mov r0, r5 */
/* @0x168090 add r4, r4, #1 */
/* @0x168094 add r3, r3, #238 */
/* @0x168098 ldr r2, [r5, r3, lsl #2] */
/* @0x16809c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1680a0 cmp r4, #36 */
/* @0x1680a4 bne 0x168080 <_ZN18RenderStateManager13RestoreStatesEv+0x30> */
/* @0x1680a8 mov r7, #0 */
/* @0x1680ac movw r9, #0x3db8 */
/* @0x1680b0 mov r6, r7 */
/* @0x1680b4 mov r8, #116 */
/* @0x1680b8 mov r4, #0 */
/* @0x1680bc ldr r3, [r5, r9] */
/* @0x1680c0 mov r2, r4 */
/* @0x1680c4 mov r0, r5 */
/* @0x1680c8 mov r1, r6 */
/* @0x1680cc mla r3, r8, r3, r7 */
/* @0x1680d0 add r3, r3, r4 */
/* @0x1680d4 add r4, r4, #1 */
/* @0x1680d8 add r3, r3, #272 */
/* @0x1680dc add r3, r3, #2 */
/* @0x1680e0 ldr r3, [r5, r3, lsl #2] */
/* @0x1680e4 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1680e8 cmp r4, #10 */
/* @0x1680ec bne 0x1680bc <_ZN18RenderStateManager13RestoreStatesEv+0x6c> */
/* @0x1680f0 add r6, r6, #1 */
/* @0x1680f4 add r7, r7, #10 */
/* @0x1680f8 cmp r6, #8 */
/* @0x1680fc bne 0x1680b8 <_ZN18RenderStateManager13RestoreStatesEv+0x68> */
/* @0x168100 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x168104 ldr r3, [pc, #0x20] */
/* @0x168108 ldr r1, [pc, #0x20] */
/* @0x16810c ldr r3, [pc, r3] */
/* @0x168110 add r1, pc, r1 */
/* @0x168114 ldr r0, [r3] */
/* @0x168118 ldr r3, [r0] */
/* @0x16811c ldr r3, [r3, #0xc] */
/* @0x168120 blx r3 */
/* @0x168124 ldr r3, [r5, r4] */
/* @0x168128 b 0x168070 <_ZN18RenderStateManager13RestoreStatesEv+0x20> */
/* @0x16812c eoreq r5, r8, r8, lsl #12 */
/* @0x168130 andseq r2, lr, r4, ror r6 */

/* ── FUNC 0x168134 · RenderStateManager::Flush() · size=352 · insn=88 */
/* @0x168134 ldrd r2, r3, [r0] */
/* @0x168138 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16813c orrs r1, r2, r3 */
/* @0x168140 sub sp, sp, #12 */
/* @0x168144 mov r8, r0 */
/* @0x168148 beq 0x1681d4 <_ZN18RenderStateManager5FlushEv+0xa0> */
/* @0x16814c mov r10, #1 */
/* @0x168150 mov r11, #0 */
/* @0x168154 mov r9, r0 */
/* @0x168158 mov r12, #0 */
/* @0x16815c b 0x168174 <_ZN18RenderStateManager5FlushEv+0x40> */
/* @0x168160 add r12, r12, #1 */
/* @0x168164 add r9, r9, #4 */
/* @0x168168 cmp r12, #36 */
/* @0x16816c beq 0x1681c8 <_ZN18RenderStateManager5FlushEv+0x94> */
/* @0x168170 ldm r8, {r2, r3} */
/* @0x168174 lsr r6, r2, r12 */
/* @0x168178 rsb r2, r12, #32 */
/* @0x16817c orr r6, r6, r3, lsl r2 */
/* @0x168180 sub r2, r12, #32 */
/* @0x168184 orr r6, r6, r3, lsr r2 */
/* @0x168188 lsr r7, r3, r12 */
/* @0x16818c and r2, r6, r10 */
/* @0x168190 and r3, r7, r11 */
/* @0x168194 orrs r1, r2, r3 */
/* @0x168198 beq 0x168160 <_ZN18RenderStateManager5FlushEv+0x2c> */
/* @0x16819c ldr r1, [r9, #0x1e0] */
/* @0x1681a0 mov r0, r12 */
/* @0x1681a4 str r12, [sp, #0x4] */
/* @0x1681a8 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x1681ac ldr r12, [sp, #0x4] */
/* @0x1681b0 add r9, r9, #4 */
/* @0x1681b4 ldr r3, [r9, #0x1dc] */
/* @0x1681b8 add r12, r12, #1 */
/* @0x1681bc cmp r12, #36 */
/* @0x1681c0 str r3, [r9, #0xc] */
/* @0x1681c4 bne 0x168170 <_ZN18RenderStateManager5FlushEv+0x3c> */
/* @0x1681c8 mov r2, #0 */
/* @0x1681cc mov r3, #0 */
/* @0x1681d0 strd r2, r3, [r8] */
/* @0x1681d4 ldrd r2, r3, [r8, #8] */
/* @0x1681d8 orrs r1, r2, r3 */
/* @0x1681dc beq 0x16827c <_ZN18RenderStateManager5FlushEv+0x148> */
/* @0x1681e0 movw r9, #0x6667 */
/* @0x1681e4 mov r6, #1 */
/* @0x1681e8 mov r7, #0 */
/* @0x1681ec movt r9, #0x6666 */
/* @0x1681f0 mov r10, r8 */
/* @0x1681f4 mov r11, #0 */
/* @0x1681f8 b 0x168214 <_ZN18RenderStateManager5FlushEv+0xe0> */
/* @0x1681fc add r11, r11, #1 */
/* @0x168200 add r10, r10, #4 */
/* @0x168204 cmp r11, #80 */
/* @0x168208 beq 0x168270 <_ZN18RenderStateManager5FlushEv+0x13c> */
/* @0x16820c ldr r2, [r8, #0x8] */
/* @0x168210 ldr r3, [r8, #0xc] */
/* @0x168214 lsr r4, r2, r11 */
/* @0x168218 rsb r2, r11, #32 */
/* @0x16821c orr r4, r4, r3, lsl r2 */
/* @0x168220 sub r2, r11, #32 */
/* @0x168224 orr r4, r4, r3, lsr r2 */
/* @0x168228 lsr r5, r3, r11 */
/* @0x16822c and r2, r4, r6 */
/* @0x168230 and r3, r5, r7 */
/* @0x168234 orrs r1, r2, r3 */
/* @0x168238 beq 0x1681fc <_ZN18RenderStateManager5FlushEv+0xc8> */
/* @0x16823c smull r3, r1, r9, r11 */
/* @0x168240 asr r3, r11, #31 */
/* @0x168244 ldr r2, [r10, #0x270] */
/* @0x168248 add r10, r10, #4 */
/* @0x16824c rsb r0, r3, r1, asr #2 */
/* @0x168250 add r1, r0, r0, lsl #2 */
/* @0x168254 sub r1, r11, r1, lsl #1 */
/* @0x168258 add r11, r11, #1 */
/* @0x16825c bl 0x1804b0 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej> */
/* @0x168260 ldr r3, [r10, #0x26c] */
/* @0x168264 cmp r11, #80 */
/* @0x168268 str r3, [r10, #0x9c] */
/* @0x16826c bne 0x16820c <_ZN18RenderStateManager5FlushEv+0xd8> */
/* @0x168270 mov r2, #0 */
/* @0x168274 mov r3, #0 */
/* @0x168278 strd r2, r3, [r8, #8] */
/* @0x16827c mov r1, #944 */
/* @0x168280 mov r2, #0 */
/* @0x168284 mov r3, #0 */
/* @0x168288 strd r2, r3, [r8, r1] */
/* @0x16828c add sp, sp, #12 */
/* @0x168290 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x168294 · RenderStateManager::Force() · size=56 · insn=14 */
/* @0x168294 push {r4, r5, r6, r7} */
/* @0x168298 mov r12, #944 */
/* @0x16829c ldrd r4, r5, [r0, #8] */
/* @0x1682a0 movw r6, #0x3ff */
/* @0x1682a4 mov r7, #0 */
/* @0x1682a8 mvn r2, #0 */
/* @0x1682ac mvn r3, #0 */
/* @0x1682b0 orr r4, r4, r6 */
/* @0x1682b4 strd r2, r3, [r0, r12] */
/* @0x1682b8 orr r5, r5, r7 */
/* @0x1682bc strd r2, r3, [r0] */
/* @0x1682c0 strd r4, r5, [r0, #8] */
/* @0x1682c4 pop {r4, r5, r6, r7} */
/* @0x1682c8 b 0x168134 <_ZN18RenderStateManager5FlushEv> */

/* ── FUNC 0x1682cc · RenderStateManager::WriteStatesToBuffer(Buffer_Standard*) · size=36 · insn=9 */
/* @0x1682cc add r12, r0, #484 */
/* @0x1682d0 mov r2, #4 */
/* @0x1682d4 push {r3, lr} */
/* @0x1682d8 mov r0, r1 */
/* @0x1682dc mov r3, #35 */
/* @0x1682e0 mov r1, r12 */
/* @0x1682e4 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x1682e8 mov r0, #35 */
/* @0x1682ec pop {r3, pc} */

/* ── FUNC 0x1682f0 · GR_D3D_Set_Perspective(bool) · size=20 · insn=5 */
/* @0x1682f0 ldr r3, [pc, #0x8] */
/* @0x1682f4 ldr r3, [pc, r3] */
/* @0x1682f8 strb r0, [r3] */
/* @0x1682fc bx lr */
/* @0x168300 eoreq r7, r8, r12, lsl #28 */

/* ── FUNC 0x168304 · GR_D3D_Set_Blend_Ext(int, int) · size=92 · insn=23 */
/* @0x168304 push {r4, r5, r6, lr} */
/* @0x168308 mov r2, r0 */
/* @0x16830c ldr r4, [pc, #0x48] */
/* @0x168310 mov r5, r1 */
/* @0x168314 mov r6, r0 */
/* @0x168318 mov r1, #6 */
/* @0x16831c ldr r4, [pc, r4] */
/* @0x168320 mov r0, r4 */
/* @0x168324 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168328 mov r0, r4 */
/* @0x16832c mov r2, r5 */
/* @0x168330 mov r1, #7 */
/* @0x168334 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168338 mov r0, r4 */
/* @0x16833c mov r2, r6 */
/* @0x168340 mov r1, #34 */
/* @0x168344 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168348 mov r0, r4 */
/* @0x16834c mov r2, r5 */
/* @0x168350 mov r1, #35 */
/* @0x168354 pop {r4, r5, r6, lr} */
/* @0x168358 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x16835c .word 0x002859dc */

/* ── FUNC 0x168360 · GR_D3D_Set_Blend(int) · size=68 · insn=17 */
/* @0x168360 cmp r0, #2 */
/* @0x168364 beq 0x168398 <_Z16GR_D3D_Set_Blendi+0x38> */
/* @0x168368 cmp r0, #3 */
/* @0x16836c beq 0x16838c <_Z16GR_D3D_Set_Blendi+0x2c> */
/* @0x168370 cmp r0, #1 */
/* @0x168374 mov r0, #5 */
/* @0x168378 beq 0x168384 <_Z16GR_D3D_Set_Blendi+0x24> */
/* @0x16837c mov r1, #6 */
/* @0x168380 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii> */
/* @0x168384 mov r1, #2 */
/* @0x168388 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii> */
/* @0x16838c mov r0, #1 */
/* @0x168390 mov r1, #4 */
/* @0x168394 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii> */
/* @0x168398 mov r0, #5 */
/* @0x16839c mov r1, #4 */
/* @0x1683a0 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii> */

/* ── FUNC 0x1683a4 · GR_D3D_Set_Colour_Write_Enable(bool, bool, bool, bool) · size=68 · insn=17 */
/* @0x1683a4 cmp r1, #0 */
/* @0x1683a8 ldr r12, [pc, #0x34] */
/* @0x1683ac movne r1, #2 */
/* @0x1683b0 moveq r1, #0 */
/* @0x1683b4 cmp r2, #0 */
/* @0x1683b8 orr r0, r1, r0 */
/* @0x1683bc mov r1, #24 */
/* @0x1683c0 movne r2, #4 */
/* @0x1683c4 moveq r2, #0 */
/* @0x1683c8 cmp r3, #0 */
/* @0x1683cc orr r2, r0, r2 */
/* @0x1683d0 ldr r0, [pc, r12] */
/* @0x1683d4 movne r3, #8 */
/* @0x1683d8 moveq r3, #0 */
/* @0x1683dc orr r2, r2, r3 */
/* @0x1683e0 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1683e4 eoreq r5, r8, r8, lsr #18 */

/* ── FUNC 0x1683e8 · GR_D3D_Set_Culling(bool) · size=52 · insn=13 */
/* @0x1683e8 subs r2, r0, #0 */
/* @0x1683ec bne 0x168400 <_Z18GR_D3D_Set_Cullingb+0x18> */
/* @0x1683f0 ldr r0, [pc, #0x1c] */
/* @0x1683f4 mov r1, #8 */
/* @0x1683f8 ldr r0, [pc, r0] */
/* @0x1683fc b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168400 ldr r0, [pc, #0x10] */
/* @0x168404 mov r1, #8 */
/* @0x168408 mov r2, #2 */
/* @0x16840c ldr r0, [pc, r0] */
/* @0x168410 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168414 eoreq r5, r8, r0, lsl #18 */
/* @0x168418 eoreq r5, r8, r12, ror #17 */

/* ── FUNC 0x16841c · SetZBuffer(bool) · size=104 · insn=26 */
/* @0x16841c ldr r3, [pc, #0x50] */
/* @0x168420 ldr r1, [pc, #0x50] */
/* @0x168424 add r3, pc, r3 */
/* @0x168428 ldr r2, [pc, #0x4c] */
/* @0x16842c ldr r1, [r3, r1] */
/* @0x168430 strb r0, [r1] */
/* @0x168434 ldr r2, [r3, r2] */
/* @0x168438 ldrb r2, [r2] */
/* @0x16843c cmp r2, #0 */
/* @0x168440 beq 0x16844c <_Z10SetZBufferb+0x30> */
/* @0x168444 cmp r0, #0 */
/* @0x168448 bne 0x168460 <_Z10SetZBufferb+0x44> */
/* @0x16844c ldr r0, [pc, #0x2c] */
/* @0x168450 mov r1, #1 */
/* @0x168454 mov r2, #0 */
/* @0x168458 ldr r0, [r3, r0] */
/* @0x16845c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168460 ldr r0, [pc, #0x18] */
/* @0x168464 mov r1, #1 */
/* @0x168468 mov r2, r1 */
/* @0x16846c ldr r0, [r3, r0] */
/* @0x168470 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168474 eoreq r9, r8, r12, lsr #16 */
/* @0x168478 .word 0xffffe4b4 */
/* @0x16847c .word 0xffffc0b4 */
/* @0x168480 .word 0xffffc0a8 */

/* ── FUNC 0x168484 · GR_D3D_Set_Lighting(bool) · size=24 · insn=6 */
/* @0x168484 ldr r3, [pc, #0xc] */
/* @0x168488 mov r2, r0 */
/* @0x16848c mov r1, #21 */
/* @0x168490 ldr r0, [pc, r3] */
/* @0x168494 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168498 eoreq r5, r8, r8, ror #16 */

/* ── FUNC 0x16849c · GR_D3D_Set_Shading(bool) · size=56 · insn=14 */
/* @0x16849c cmp r0, #0 */
/* @0x1684a0 bne 0x1684b8 <_Z18GR_D3D_Set_Shadingb+0x1c> */
/* @0x1684a4 ldr r0, [pc, #0x20] */
/* @0x1684a8 mov r1, #3 */
/* @0x1684ac mov r2, #1 */
/* @0x1684b0 ldr r0, [pc, r0] */
/* @0x1684b4 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1684b8 ldr r0, [pc, #0x10] */
/* @0x1684bc mov r1, #3 */
/* @0x1684c0 mov r2, #2 */
/* @0x1684c4 ldr r0, [pc, r0] */
/* @0x1684c8 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1684cc eoreq r5, r8, r8, asr #16 */
/* @0x1684d0 eoreq r5, r8, r4, lsr r8 */

/* ── FUNC 0x1684d4 · _SetFogDistances() · size=76 · insn=19 */
/* @0x1684d4 push {r4, lr} */
/* @0x1684d8 mov r1, #17 */
/* @0x1684dc ldr r4, [pc, #0x30] */
/* @0x1684e0 ldr r3, [pc, #0x30] */
/* @0x1684e4 ldr r4, [pc, r4] */
/* @0x1684e8 ldr r3, [pc, r3] */
/* @0x1684ec mov r0, r4 */
/* @0x1684f0 ldr r2, [r3] */
/* @0x1684f4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1684f8 ldr r3, [pc, #0x1c] */
/* @0x1684fc mov r0, r4 */
/* @0x168500 mov r1, #18 */
/* @0x168504 ldr r3, [pc, r3] */
/* @0x168508 pop {r4, lr} */
/* @0x16850c ldr r2, [r3] */
/* @0x168510 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168514 eoreq r5, r8, r4, lsl r8 */
/* @0x168518 eoreq r7, r8, r0, lsr r12 */
/* @0x16851c eoreq r7, r8, r8, lsl r12 */

/* ── FUNC 0x168520 · GR_D3D_Set_Fog(bool, unsigned int, short, short) · size=300 · insn=75 */
/* @0x168520 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x168524 vpush {d8} */
/* @0x168528 vmov s15, r2 */
/* @0x16852c ldr lr, [pc, #0x100] */
/* @0x168530 mov r2, r0 */
/* @0x168534 ldr r6, [pc, #0xfc] */
/* @0x168538 mov r10, r1 */
/* @0x16853c add lr, pc, lr */
/* @0x168540 ldr r12, [pc, #0xf4] */
/* @0x168544 ldr r0, [pc, #0xf4] */
/* @0x168548 vcvt.f32.s32 s17, s15 */
/* @0x16854c mov r1, lr */
/* @0x168550 ldr r4, [pc, #0xec] */
/* @0x168554 ldr lr, [pc, #0xec] */
/* @0x168558 vmov s15, r3 */
/* @0x16855c ldr r9, [r1, r6] */
/* @0x168560 ldr r5, [r1, r12] */
/* @0x168564 ldr r7, [r1, r0] */
/* @0x168568 ldr r8, [r1, r4] */
/* @0x16856c vcvt.f32.s32 s16, s15 */
/* @0x168570 ldr r6, [r1, lr] */
/* @0x168574 b 0x168590 <_Z14GR_D3D_Set_Fogbjss+0x70> */
/* @0x168578 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x16857c cmp r4, #1 */
/* @0x168580 mov r2, #0 */
/* @0x168584 beq 0x1685e4 <_Z14GR_D3D_Set_Fogbjss+0xc4> */
/* @0x168588 cmp r4, #2 */
/* @0x16858c beq 0x168610 <_Z14GR_D3D_Set_Fogbjss+0xf0> */
/* @0x168590 mov r1, #255 */
/* @0x168594 mov r0, r10 */
/* @0x168598 strb r2, [r5] */
/* @0x16859c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x1685a0 vstr s17, [r9] */
/* @0x1685a4 vstr s16, [r8] */
/* @0x1685a8 str r0, [r7] */
/* @0x1685ac bl 0x17f360 <_ZN8Graphics7FogTypeEv> */
/* @0x1685b0 ldrb r3, [r5] */
/* @0x1685b4 mov r1, #13 */
/* @0x1685b8 mov r2, #1 */
/* @0x1685bc cmp r3, #0 */
/* @0x1685c0 mov r4, r0 */
/* @0x1685c4 mov r0, r6 */
/* @0x1685c8 bne 0x168578 <_Z14GR_D3D_Set_Fogbjss+0x58> */
/* @0x1685cc vpop {d8} */
/* @0x1685d0 mov r0, r6 */
/* @0x1685d4 mov r2, r3 */
/* @0x1685d8 mov r1, #13 */
/* @0x1685dc pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1685e0 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1685e4 mov r0, r6 */
/* @0x1685e8 mov r1, #16 */
/* @0x1685ec mov r2, #3 */
/* @0x1685f0 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1685f4 mov r0, r6 */
/* @0x1685f8 ldr r2, [r7] */
/* @0x1685fc mov r1, #15 */
/* @0x168600 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168604 vpop {d8} */
/* @0x168608 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x16860c b 0x1684d4 <_Z16_SetFogDistancesv> */
/* @0x168610 mov r0, r6 */
/* @0x168614 mov r1, #23 */
/* @0x168618 mov r2, #3 */
/* @0x16861c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168620 mov r0, r6 */
/* @0x168624 mov r1, #20 */
/* @0x168628 mov r2, #1 */
/* @0x16862c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168630 b 0x1685f4 <_Z14GR_D3D_Set_Fogbjss+0xd4> */
/* @0x168634 eoreq r9, r8, r4, lsl r7 */
/* @0x168638 .word 0xffffe4c8 */
/* @0x16863c .word 0xffffe4c0 */
/* @0x168640 .word 0xffffe4c4 */
/* @0x168644 .word 0xffffe4cc */
/* @0x168648 .word 0xffffc0a8 */

/* ── FUNC 0x16864c · GR_D3D_Set_Z_Write_Enable(bool) · size=24 · insn=6 */
/* @0x16864c ldr r3, [pc, #0xc] */
/* @0x168650 mov r2, r0 */
/* @0x168654 mov r1, #4 */
/* @0x168658 ldr r0, [pc, r3] */
/* @0x16865c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168660 eoreq r5, r8, r0, lsr #13 */

/* ── FUNC 0x168664 · GR_D3D_Set_Alpha_Test_Enable(bool) · size=48 · insn=12 */
/* @0x168664 ldr r3, [pc, #0x20] */
/* @0x168668 ldr r3, [pc, r3] */
/* @0x16866c ldrb r3, [r3] */
/* @0x168670 cmp r3, #0 */
/* @0x168674 bxeq lr */
/* @0x168678 ldr r3, [pc, #0x10] */
/* @0x16867c mov r2, r0 */
/* @0x168680 mov r1, #5 */
/* @0x168684 ldr r0, [pc, r3] */
/* @0x168688 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x16868c .word 0x00287ab8 */
/* @0x168690 eoreq r5, r8, r4, ror r6 */

/* ── FUNC 0x168694 · GR_D3D_Get_Alpha_Test_Enable() · size=36 · insn=9 */
/* @0x168694 ldr r0, [pc, #0x18] */
/* @0x168698 mov r1, #5 */
/* @0x16869c push {r3, lr} */
/* @0x1686a0 ldr r0, [pc, r0] */
/* @0x1686a4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1686a8 adds r0, r0, #0 */
/* @0x1686ac movne r0, #1 */
/* @0x1686b0 pop {r3, pc} */
/* @0x1686b4 eoreq r5, r8, r8, asr r6 */

/* ── FUNC 0x1686b8 · GR_D3D_Set_Alpha_Test_Ref(unsigned int) · size=24 · insn=6 */
/* @0x1686b8 ldr r3, [pc, #0xc] */
/* @0x1686bc mov r2, r0 */
/* @0x1686c0 mov r1, #10 */
/* @0x1686c4 ldr r0, [pc, r3] */
/* @0x1686c8 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1686cc eoreq r5, r8, r4, lsr r6 */

/* ── FUNC 0x1686d0 · GR_D3D_Get_Alpha_Test_Ref() · size=20 · insn=5 */
/* @0x1686d0 ldr r0, [pc, #0x8] */
/* @0x1686d4 mov r1, #10 */
/* @0x1686d8 ldr r0, [pc, r0] */
/* @0x1686dc b 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1686e0 eoreq r5, r8, r0, lsr #12 */

/* ── FUNC 0x1686e4 · GR_D3D_Set_Alpha_Test_Func(unsigned int) · size=24 · insn=6 */
/* @0x1686e4 ldr r3, [pc, #0xc] */
/* @0x1686e8 mov r2, r0 */
/* @0x1686ec mov r1, #11 */
/* @0x1686f0 ldr r0, [pc, r3] */
/* @0x1686f4 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1686f8 eoreq r5, r8, r8, lsl #12 */

/* ── FUNC 0x1686fc · GR_D3D_Get_Alpha_Test_Func() · size=20 · insn=5 */
/* @0x1686fc ldr r0, [pc, #0x8] */
/* @0x168700 mov r1, #11 */
/* @0x168704 ldr r0, [pc, r0] */
/* @0x168708 b 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x16870c .word 0x002855f4 */

/* ── FUNC 0x168710 · GR_D3D_Set_Texture_Interpolation(bool) · size=196 · insn=49 */
/* @0x168710 push {r3, r4, r5, r6, r7, lr} */
/* @0x168714 cmp r0, #0 */
/* @0x168718 ldr r3, [pc, #0xa8] */
/* @0x16871c ldr r1, [pc, #0xa8] */
/* @0x168720 add r3, pc, r3 */
/* @0x168724 beq 0x168778 <_Z32GR_D3D_Set_Texture_Interpolationb+0x68> */
/* @0x168728 ldr r2, [pc, #0xa0] */
/* @0x16872c mov r4, #0 */
/* @0x168730 ldr r6, [r3, r1] */
/* @0x168734 mov r7, #1 */
/* @0x168738 ldr r5, [r3, r2] */
/* @0x16873c mov r1, r4 */
/* @0x168740 strb r7, [r6, r4] */
/* @0x168744 mov r0, r5 */
/* @0x168748 mov r2, #0 */
/* @0x16874c mov r3, #1 */
/* @0x168750 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x168754 mov r2, #1 */
/* @0x168758 mov r1, r4 */
/* @0x16875c mov r0, r5 */
/* @0x168760 add r4, r4, #1 */
/* @0x168764 mov r3, r2 */
/* @0x168768 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x16876c cmp r4, #8 */
/* @0x168770 bne 0x16873c <_Z32GR_D3D_Set_Texture_Interpolationb+0x2c> */
/* @0x168774 pop {r3, r4, r5, r6, r7, pc} */
/* @0x168778 ldr r2, [pc, #0x50] */
/* @0x16877c mov r4, r0 */
/* @0x168780 ldr r6, [r3, r1] */
/* @0x168784 mov r7, r0 */
/* @0x168788 ldr r5, [r3, r2] */
/* @0x16878c mov r2, #0 */
/* @0x168790 mov r1, r4 */
/* @0x168794 mov r3, r2 */
/* @0x168798 strb r7, [r6, r4] */
/* @0x16879c mov r0, r5 */
/* @0x1687a0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1687a4 mov r1, r4 */
/* @0x1687a8 mov r0, r5 */
/* @0x1687ac add r4, r4, #1 */
/* @0x1687b0 mov r2, #1 */
/* @0x1687b4 mov r3, #0 */
/* @0x1687b8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1687bc cmp r4, #8 */
/* @0x1687c0 bne 0x16878c <_Z32GR_D3D_Set_Texture_Interpolationb+0x7c> */
/* @0x1687c4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1687c8 eoreq r9, r8, r0, lsr r5 */
/* @0x1687cc .word 0xffffe4b8 */
/* @0x1687d0 .word 0xffffc0a8 */

/* ── FUNC 0x1687d4 · GR_D3D_Set_Texture_Interpolation_Ext(int, bool) · size=156 · insn=39 */
/* @0x1687d4 push {r4, r5, r6, lr} */
/* @0x1687d8 cmp r0, #7 */
/* @0x1687dc mov r4, r0 */
/* @0x1687e0 ldr r0, [pc, #0x7c] */
/* @0x1687e4 mov r5, r1 */
/* @0x1687e8 add r0, pc, r0 */
/* @0x1687ec pophi {r4, r5, r6, pc} */
/* @0x1687f0 ldr r3, [pc, #0x70] */
/* @0x1687f4 cmp r5, #0 */
/* @0x1687f8 ldr r12, [pc, #0x6c] */
/* @0x1687fc mov r1, r4 */
/* @0x168800 ldr r3, [r0, r3] */
/* @0x168804 strb r5, [r3, r4] */
/* @0x168808 bne 0x168838 <_Z36GR_D3D_Set_Texture_Interpolation_Extib+0x64> */
/* @0x16880c ldr r6, [r0, r12] */
/* @0x168810 mov r2, r5 */
/* @0x168814 mov r3, r5 */
/* @0x168818 mov r0, r6 */
/* @0x16881c bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x168820 mov r0, r6 */
/* @0x168824 mov r1, r4 */
/* @0x168828 mov r3, r5 */
/* @0x16882c mov r2, #1 */
/* @0x168830 pop {r4, r5, r6, lr} */
/* @0x168834 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x168838 ldr r5, [r0, r12] */
/* @0x16883c mov r2, #0 */
/* @0x168840 mov r3, #1 */
/* @0x168844 mov r0, r5 */
/* @0x168848 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x16884c mov r2, #1 */
/* @0x168850 mov r0, r5 */
/* @0x168854 mov r1, r4 */
/* @0x168858 mov r3, r2 */
/* @0x16885c pop {r4, r5, r6, lr} */
/* @0x168860 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x168864 eoreq r9, r8, r8, ror #8 */
/* @0x168868 .word 0xffffe4b8 */
/* @0x16886c .word 0xffffc0a8 */

/* ── FUNC 0x168870 · GR_D3D_Set_Texture_Repeat(bool) · size=196 · insn=49 */
/* @0x168870 push {r3, r4, r5, r6, r7, lr} */
/* @0x168874 cmp r0, #0 */
/* @0x168878 ldr r3, [pc, #0xa8] */
/* @0x16887c ldr r1, [pc, #0xa8] */
/* @0x168880 add r3, pc, r3 */
/* @0x168884 beq 0x1688d8 <_Z25GR_D3D_Set_Texture_Repeatb+0x68> */
/* @0x168888 ldr r2, [pc, #0xa0] */
/* @0x16888c mov r4, #0 */
/* @0x168890 ldr r6, [r3, r1] */
/* @0x168894 mov r7, #1 */
/* @0x168898 ldr r5, [r3, r2] */
/* @0x16889c mov r1, r4 */
/* @0x1688a0 strb r7, [r6, r4] */
/* @0x1688a4 mov r0, r5 */
/* @0x1688a8 mov r2, #2 */
/* @0x1688ac mov r3, #0 */
/* @0x1688b0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1688b4 mov r1, r4 */
/* @0x1688b8 mov r0, r5 */
/* @0x1688bc add r4, r4, #1 */
/* @0x1688c0 mov r2, #3 */
/* @0x1688c4 mov r3, #0 */
/* @0x1688c8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1688cc cmp r4, #8 */
/* @0x1688d0 bne 0x16889c <_Z25GR_D3D_Set_Texture_Repeatb+0x2c> */
/* @0x1688d4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1688d8 ldr r2, [pc, #0x50] */
/* @0x1688dc mov r4, r0 */
/* @0x1688e0 ldr r6, [r3, r1] */
/* @0x1688e4 mov r7, r0 */
/* @0x1688e8 ldr r5, [r3, r2] */
/* @0x1688ec mov r1, r4 */
/* @0x1688f0 strb r7, [r6, r4] */
/* @0x1688f4 mov r0, r5 */
/* @0x1688f8 mov r2, #2 */
/* @0x1688fc mov r3, #1 */
/* @0x168900 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x168904 mov r1, r4 */
/* @0x168908 mov r0, r5 */
/* @0x16890c add r4, r4, #1 */
/* @0x168910 mov r2, #3 */
/* @0x168914 mov r3, #1 */
/* @0x168918 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x16891c cmp r4, #8 */
/* @0x168920 bne 0x1688ec <_Z25GR_D3D_Set_Texture_Repeatb+0x7c> */
/* @0x168924 pop {r3, r4, r5, r6, r7, pc} */
/* @0x168928 .word 0x002893d0 */
/* @0x16892c .word 0xffffe4bc */
/* @0x168930 .word 0xffffc0a8 */

/* ── FUNC 0x168934 · GR_D3D_Set_Texture_Repeat_Ext(int, bool) · size=148 · insn=37 */
/* @0x168934 push {r4, r5, r6, lr} */
/* @0x168938 cmp r0, #7 */
/* @0x16893c mov r4, r0 */
/* @0x168940 ldr r0, [pc, #0x74] */
/* @0x168944 add r0, pc, r0 */
/* @0x168948 pophi {r4, r5, r6, pc} */
/* @0x16894c ldr r3, [pc, #0x6c] */
/* @0x168950 cmp r1, #0 */
/* @0x168954 ldr r12, [pc, #0x68] */
/* @0x168958 mov r2, #2 */
/* @0x16895c ldr r3, [r0, r3] */
/* @0x168960 strb r1, [r3, r4] */
/* @0x168964 mov r1, r4 */
/* @0x168968 bne 0x168994 <_Z29GR_D3D_Set_Texture_Repeat_Extib+0x60> */
/* @0x16896c ldr r5, [r0, r12] */
/* @0x168970 mov r3, #1 */
/* @0x168974 mov r0, r5 */
/* @0x168978 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x16897c mov r0, r5 */
/* @0x168980 mov r1, r4 */
/* @0x168984 mov r2, #3 */
/* @0x168988 mov r3, #1 */
/* @0x16898c pop {r4, r5, r6, lr} */
/* @0x168990 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x168994 ldr r5, [r0, r12] */
/* @0x168998 mov r3, #0 */
/* @0x16899c mov r0, r5 */
/* @0x1689a0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1689a4 mov r0, r5 */
/* @0x1689a8 mov r1, r4 */
/* @0x1689ac mov r2, #3 */
/* @0x1689b0 mov r3, #0 */
/* @0x1689b4 pop {r4, r5, r6, lr} */
/* @0x1689b8 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1689bc eoreq r9, r8, r12, lsl #6 */
/* @0x1689c0 .word 0xffffe4bc */
/* @0x1689c4 .word 0xffffc0a8 */

/* ── FUNC 0x1689c8 · GR_D3D_Set_Texture_Blending(bool) · size=24 · insn=6 */
/* @0x1689c8 push {r4, lr} */
/* @0x1689cc mov r4, r0 */
/* @0x1689d0 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1689d4 mov r0, r4 */
/* @0x1689d8 pop {r4, lr} */
/* @0x1689dc b 0x1836d8 <_ZN8Graphics18SetTextureBlendingEb> */

/* ── FUNC 0x1689e0 · GR_D3D_Get_Texture_Repeat() · size=20 · insn=5 */
/* @0x1689e0 ldr r3, [pc, #0x8] */
/* @0x1689e4 ldr r3, [pc, r3] */
/* @0x1689e8 ldrb r0, [r3] */
/* @0x1689ec bx lr */
/* @0x1689f0 eoreq r7, r8, r8, lsr #14 */

/* ── FUNC 0x1689f4 · GR_D3D_Get_Texture_Interpolation() · size=20 · insn=5 */
/* @0x1689f4 ldr r3, [pc, #0x8] */
/* @0x1689f8 ldr r3, [pc, r3] */
/* @0x1689fc ldrb r0, [r3] */
/* @0x168a00 bx lr */
/* @0x168a04 eoreq r7, r8, r0, lsl r7 */
