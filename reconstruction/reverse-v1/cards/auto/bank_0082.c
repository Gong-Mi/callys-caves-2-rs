/* libyoyo.so 覆盖卡组 0082
 * 函数 0x149010..0x14bf14，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x149010 · F_GPUSetFog(RValue&, CInstance*, CInstance*, int, RValue*) · size=392 · insn=98 */
/* @0x149010 cmp r3, #1 */
/* @0x149014 cmpne r3, #4 */
/* @0x149018 mov r2, #0 */
/* @0x14901c push {r4, r5, r6, r7, r8, lr} */
/* @0x149020 mov r1, r2 */
/* @0x149024 moveq r12, #0 */
/* @0x149028 movne r12, #1 */
/* @0x14902c movt r2, #0xbff0 */
/* @0x149030 str r1, [r0, #0xc] */
/* @0x149034 stm r0, {r1, r2} */
/* @0x149038 ldr r4, [sp, #0x18] */
/* @0x14903c bne 0x14906c <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x149040 cmp r3, #4 */
/* @0x149044 beq 0x149148 <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x149048 ldr r5, [r4, #0xc] */
/* @0x14904c bic r5, r5, #-16777216 */
/* @0x149050 cmp r5, #2 */
/* @0x149054 beq 0x14907c <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x149058 ldr r0, [pc, #0x12c] */
/* @0x14905c mov r1, #0 */
/* @0x149060 pop {r4, r5, r6, r7, r8, lr} */
/* @0x149064 add r0, pc, r0 */
/* @0x149068 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14906c ldr r0, [pc, #0x11c] */
/* @0x149070 pop {r4, r5, r6, r7, r8, lr} */
/* @0x149074 add r0, pc, r0 */
/* @0x149078 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14907c ldr r3, [r4] */
/* @0x149080 ldr r3, [r3, #0x4] */
/* @0x149084 ldr r2, [r3] */
/* @0x149088 cmp r2, #4 */
/* @0x14908c bne 0x149058 <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x149090 mov r1, r12 */
/* @0x149094 ldr r0, [r3, #0x4] */
/* @0x149098 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14909c ldr r3, [r4] */
/* @0x1490a0 mov r1, #1 */
/* @0x1490a4 ldr r3, [r3, #0x4] */
/* @0x1490a8 mov r6, r0 */
/* @0x1490ac ldr r0, [r3, #0x4] */
/* @0x1490b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1490b4 ldr r3, [r4] */
/* @0x1490b8 mov r1, r5 */
/* @0x1490bc ldr r3, [r3, #0x4] */
/* @0x1490c0 mov r8, r0 */
/* @0x1490c4 ldr r0, [r3, #0x4] */
/* @0x1490c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1490cc ldr r3, [r4] */
/* @0x1490d0 mov r1, #3 */
/* @0x1490d4 ldr r3, [r3, #0x4] */
/* @0x1490d8 mov r7, r0 */
/* @0x1490dc ldr r0, [r3, #0x4] */
/* @0x1490e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1490e4 mov r5, r0 */
/* @0x1490e8 ldr r4, [pc, #0xa4] */
/* @0x1490ec mov r1, #13 */
/* @0x1490f0 mov r2, r6 */
/* @0x1490f4 ldr r4, [pc, r4] */
/* @0x1490f8 mov r0, r4 */
/* @0x1490fc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x149100 cmp r6, #0 */
/* @0x149104 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x149108 mov r0, r8 */
/* @0x14910c mov r1, #255 */
/* @0x149110 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x149114 mov r1, #15 */
/* @0x149118 mov r2, r0 */
/* @0x14911c mov r0, r4 */
/* @0x149120 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x149124 mov r0, r4 */
/* @0x149128 mov r2, r7 */
/* @0x14912c mov r1, #17 */
/* @0x149130 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x149134 mov r0, r4 */
/* @0x149138 mov r2, r5 */
/* @0x14913c mov r1, #18 */
/* @0x149140 pop {r4, r5, r6, r7, r8, lr} */
/* @0x149144 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x149148 mov r1, r12 */
/* @0x14914c mov r0, r4 */
/* @0x149150 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149154 mov r1, #1 */
/* @0x149158 mov r6, r0 */
/* @0x14915c mov r0, r4 */
/* @0x149160 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149164 mov r1, #2 */
/* @0x149168 mov r8, r0 */
/* @0x14916c mov r0, r4 */
/* @0x149170 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x149174 mov r1, #3 */
/* @0x149178 mov r7, r0 */
/* @0x14917c mov r0, r4 */
/* @0x149180 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x149184 mov r5, r0 */
/* @0x149188 b 0x1490e8 <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x14918c andseq r9, pc, r8, asr #13 */
/* @0x149190 andseq r9, pc, r0, ror #12 */
/* @0x149194 eoreq r4, r10, r4, lsl #24 */

/* ── FUNC 0x149198 · F_GPUSetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0x149198 sub r2, r3, #1 */
/* @0x14919c cmp r2, #1 */
/* @0x1491a0 mov r2, #0 */
/* @0x1491a4 push {r4, r5, r6, lr} */
/* @0x1491a8 mov r1, r2 */
/* @0x1491ac ldr r4, [sp, #0x10] */
/* @0x1491b0 movt r2, #0xbff0 */
/* @0x1491b4 str r1, [r0, #0xc] */
/* @0x1491b8 stm r0, {r1, r2} */
/* @0x1491bc bhi 0x1491ec <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1491c0 cmp r3, #2 */
/* @0x1491c4 beq 0x149290 <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x1491c8 ldr r3, [r4, #0xc] */
/* @0x1491cc bic r3, r3, #-16777216 */
/* @0x1491d0 cmp r3, #2 */
/* @0x1491d4 beq 0x1491fc <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x1491d8 ldr r0, [pc, #0xd0] */
/* @0x1491dc mov r1, #0 */
/* @0x1491e0 pop {r4, r5, r6, lr} */
/* @0x1491e4 add r0, pc, r0 */
/* @0x1491e8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1491ec ldr r0, [pc, #0xc0] */
/* @0x1491f0 pop {r4, r5, r6, lr} */
/* @0x1491f4 add r0, pc, r0 */
/* @0x1491f8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1491fc ldr r3, [r4] */
/* @0x149200 ldr r3, [r3, #0x4] */
/* @0x149204 ldr r2, [r3] */
/* @0x149208 cmp r2, #1 */
/* @0x14920c ble 0x1491d8 <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x149210 ldr r0, [r3, #0x4] */
/* @0x149214 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149218 ldr r3, [r4] */
/* @0x14921c mov r1, #1 */
/* @0x149220 ldr r3, [r3, #0x4] */
/* @0x149224 mov r6, r0 */
/* @0x149228 ldr r0, [r3, #0x4] */
/* @0x14922c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149230 mov r5, r0 */
/* @0x149234 ldr r4, [pc, #0x7c] */
/* @0x149238 mov r2, r6 */
/* @0x14923c mov r1, #6 */
/* @0x149240 ldr r4, [pc, r4] */
/* @0x149244 mov r0, r4 */
/* @0x149248 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x14924c mov r0, r4 */
/* @0x149250 mov r2, r5 */
/* @0x149254 mov r1, #7 */
/* @0x149258 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x14925c mov r0, r4 */
/* @0x149260 mov r2, r6 */
/* @0x149264 mov r1, #34 */
/* @0x149268 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x14926c mov r0, r4 */
/* @0x149270 mov r2, r5 */
/* @0x149274 mov r1, #35 */
/* @0x149278 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x14927c mov r0, r4 */
/* @0x149280 mov r1, #33 */
/* @0x149284 mov r2, #0 */
/* @0x149288 pop {r4, r5, r6, lr} */
/* @0x14928c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x149290 mov r0, r4 */
/* @0x149294 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149298 mov r1, #1 */
/* @0x14929c mov r6, r0 */
/* @0x1492a0 mov r0, r4 */
/* @0x1492a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1492a8 mov r5, r0 */
/* @0x1492ac b 0x149234 <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1492b0 ldrheq r9, [pc], -r8 */
/* @0x1492b4 andseq r9, pc, r12, ror #10 */
/* @0x1492b8 .word 0x002a4ab8 */

/* ── FUNC 0x1492bc · F_GPUSetBlendModeExtSepAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=388 · insn=97 */
/* @0x1492bc cmp r3, #1 */
/* @0x1492c0 cmpne r3, #4 */
/* @0x1492c4 mov r2, #0 */
/* @0x1492c8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1492cc mov r1, r2 */
/* @0x1492d0 moveq r12, #0 */
/* @0x1492d4 movne r12, #1 */
/* @0x1492d8 movt r2, #0xbff0 */
/* @0x1492dc str r1, [r0, #0xc] */
/* @0x1492e0 stm r0, {r1, r2} */
/* @0x1492e4 ldr r4, [sp, #0x18] */
/* @0x1492e8 bne 0x149318 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1492ec cmp r3, #4 */
/* @0x1492f0 beq 0x1493f0 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1492f4 ldr r5, [r4, #0xc] */
/* @0x1492f8 bic r5, r5, #-16777216 */
/* @0x1492fc cmp r5, #2 */
/* @0x149300 beq 0x149328 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x149304 ldr r0, [pc, #0x128] */
/* @0x149308 mov r1, #0 */
/* @0x14930c pop {r4, r5, r6, r7, r8, lr} */
/* @0x149310 add r0, pc, r0 */
/* @0x149314 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149318 ldr r0, [pc, #0x118] */
/* @0x14931c pop {r4, r5, r6, r7, r8, lr} */
/* @0x149320 add r0, pc, r0 */
/* @0x149324 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149328 ldr r3, [r4] */
/* @0x14932c ldr r3, [r3, #0x4] */
/* @0x149330 ldr r2, [r3] */
/* @0x149334 cmp r2, #4 */
/* @0x149338 bne 0x149304 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x14933c mov r1, r12 */
/* @0x149340 ldr r0, [r3, #0x4] */
/* @0x149344 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149348 ldr r3, [r4] */
/* @0x14934c mov r1, #1 */
/* @0x149350 ldr r3, [r3, #0x4] */
/* @0x149354 mov r8, r0 */
/* @0x149358 ldr r0, [r3, #0x4] */
/* @0x14935c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149360 ldr r3, [r4] */
/* @0x149364 mov r1, r5 */
/* @0x149368 ldr r3, [r3, #0x4] */
/* @0x14936c mov r7, r0 */
/* @0x149370 ldr r0, [r3, #0x4] */
/* @0x149374 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149378 ldr r3, [r4] */
/* @0x14937c mov r1, #3 */
/* @0x149380 ldr r3, [r3, #0x4] */
/* @0x149384 mov r6, r0 */
/* @0x149388 ldr r0, [r3, #0x4] */
/* @0x14938c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149390 mov r5, r0 */
/* @0x149394 ldr r4, [pc, #0xa0] */
/* @0x149398 mov r2, r8 */
/* @0x14939c mov r1, #6 */
/* @0x1493a0 ldr r4, [pc, r4] */
/* @0x1493a4 mov r0, r4 */
/* @0x1493a8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1493ac mov r0, r4 */
/* @0x1493b0 mov r2, r7 */
/* @0x1493b4 mov r1, #7 */
/* @0x1493b8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1493bc mov r0, r4 */
/* @0x1493c0 mov r2, r6 */
/* @0x1493c4 mov r1, #34 */
/* @0x1493c8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1493cc mov r0, r4 */
/* @0x1493d0 mov r2, r5 */
/* @0x1493d4 mov r1, #35 */
/* @0x1493d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1493dc mov r0, r4 */
/* @0x1493e0 mov r1, #33 */
/* @0x1493e4 mov r2, #1 */
/* @0x1493e8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1493ec b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1493f0 mov r1, r12 */
/* @0x1493f4 mov r0, r4 */
/* @0x1493f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1493fc mov r1, #1 */
/* @0x149400 mov r8, r0 */
/* @0x149404 mov r0, r4 */
/* @0x149408 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14940c mov r1, #2 */
/* @0x149410 mov r7, r0 */
/* @0x149414 mov r0, r4 */
/* @0x149418 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14941c mov r1, #3 */
/* @0x149420 mov r6, r0 */
/* @0x149424 mov r0, r4 */
/* @0x149428 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14942c mov r5, r0 */
/* @0x149430 b 0x149394 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x149434 andseq r9, pc, r12, lsl #10 */
/* @0x149438 ldrheq r9, [pc], -r8 */
/* @0x14943c eoreq r4, r10, r8, asr r9 */

/* ── FUNC 0x149440 · F_GPUSetColourWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=372 · insn=93 */
/* @0x149440 cmp r3, #1 */
/* @0x149444 cmpne r3, #4 */
/* @0x149448 mov r2, #0 */
/* @0x14944c push {r3, r4, r5, r6, r7, lr} */
/* @0x149450 mov r1, r2 */
/* @0x149454 moveq r12, #0 */
/* @0x149458 movne r12, #1 */
/* @0x14945c movt r2, #0xbff0 */
/* @0x149460 str r1, [r0, #0xc] */
/* @0x149464 stm r0, {r1, r2} */
/* @0x149468 ldr r4, [sp, #0x18] */
/* @0x14946c bne 0x14949c <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x149470 cmp r3, #4 */
/* @0x149474 beq 0x149564 <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x149478 ldr r5, [r4, #0xc] */
/* @0x14947c bic r5, r5, #-16777216 */
/* @0x149480 cmp r5, #2 */
/* @0x149484 beq 0x1494ac <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x149488 ldr r0, [pc, #0x118] */
/* @0x14948c mov r1, #0 */
/* @0x149490 pop {r3, r4, r5, r6, r7, lr} */
/* @0x149494 add r0, pc, r0 */
/* @0x149498 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14949c ldr r0, [pc, #0x108] */
/* @0x1494a0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1494a4 add r0, pc, r0 */
/* @0x1494a8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1494ac ldr r3, [r4] */
/* @0x1494b0 ldr r3, [r3, #0x4] */
/* @0x1494b4 ldr r2, [r3] */
/* @0x1494b8 cmp r2, #4 */
/* @0x1494bc bne 0x149488 <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1494c0 mov r1, r12 */
/* @0x1494c4 ldr r0, [r3, #0x4] */
/* @0x1494c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1494cc ldr r3, [r4] */
/* @0x1494d0 mov r1, #1 */
/* @0x1494d4 ldr r3, [r3, #0x4] */
/* @0x1494d8 mov r7, r0 */
/* @0x1494dc ldr r0, [r3, #0x4] */
/* @0x1494e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1494e4 ldr r3, [r4] */
/* @0x1494e8 mov r1, r5 */
/* @0x1494ec ldr r3, [r3, #0x4] */
/* @0x1494f0 mov r6, r0 */
/* @0x1494f4 ldr r0, [r3, #0x4] */
/* @0x1494f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1494fc ldr r3, [r4] */
/* @0x149500 mov r1, #3 */
/* @0x149504 ldr r3, [r3, #0x4] */
/* @0x149508 mov r5, r0 */
/* @0x14950c ldr r0, [r3, #0x4] */
/* @0x149510 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149514 mov r3, r0 */
/* @0x149518 cmp r6, #0 */
/* @0x14951c ldr r0, [pc, #0x8c] */
/* @0x149520 movne r12, #2 */
/* @0x149524 moveq r12, #0 */
/* @0x149528 cmp r5, #0 */
/* @0x14952c ldr r0, [pc, r0] */
/* @0x149530 movne r1, #4 */
/* @0x149534 moveq r1, #0 */
/* @0x149538 cmp r7, #0 */
/* @0x14953c moveq r2, r12 */
/* @0x149540 orrne r2, r12, #1 */
/* @0x149544 cmp r3, #0 */
/* @0x149548 orr r2, r2, r1 */
/* @0x14954c mov r1, #24 */
/* @0x149550 movne r3, #8 */
/* @0x149554 moveq r3, #0 */
/* @0x149558 orr r2, r2, r3 */
/* @0x14955c pop {r3, r4, r5, r6, r7, lr} */
/* @0x149560 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x149564 mov r1, r12 */
/* @0x149568 mov r0, r4 */
/* @0x14956c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149570 mov r1, #1 */
/* @0x149574 mov r7, r0 */
/* @0x149578 mov r0, r4 */
/* @0x14957c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149580 mov r1, #2 */
/* @0x149584 mov r6, r0 */
/* @0x149588 mov r0, r4 */
/* @0x14958c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149590 mov r1, #3 */
/* @0x149594 mov r5, r0 */
/* @0x149598 mov r0, r4 */
/* @0x14959c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1495a0 mov r3, r0 */
/* @0x1495a4 b 0x149518 <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1495a8 andseq r9, pc, r12, lsl #8 */
/* @0x1495ac ldrheq r9, [pc], -r12 */
/* @0x1495b0 eoreq r4, r10, r12, asr #15 */

/* ── FUNC 0x1495b4 · F_D3DMatrixStackSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x1495b4 cmp r3, #1 */
/* @0x1495b8 push {r4, r5, r6, r7, lr} */
/* @0x1495bc sub sp, sp, #68 */
/* @0x1495c0 beq 0x1495dc <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1495c4 ldr r0, [pc, #0xe8] */
/* @0x1495c8 mov r1, #0 */
/* @0x1495cc add r0, pc, r0 */
/* @0x1495d0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1495d4 add sp, sp, #68 */
/* @0x1495d8 pop {r4, r5, r6, r7, pc} */
/* @0x1495dc ldr r2, [sp, #0x58] */
/* @0x1495e0 ldr r3, [r2, #0xc] */
/* @0x1495e4 bic r3, r3, #-16777216 */
/* @0x1495e8 cmp r3, #2 */
/* @0x1495ec bne 0x1495c4 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x10> */
/* @0x1495f0 ldr r3, [r2] */
/* @0x1495f4 cmp r3, #0 */
/* @0x1495f8 beq 0x149614 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x1495fc ldr r3, [r3, #0x4] */
/* @0x149600 cmp r3, #0 */
/* @0x149604 beq 0x149614 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x149608 ldr r2, [r3] */
/* @0x14960c cmp r2, #16 */
/* @0x149610 beq 0x14962c <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x149614 ldr r0, [pc, #0x9c] */
/* @0x149618 mov r1, #1 */
/* @0x14961c add r0, pc, r0 */
/* @0x149620 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149624 add sp, sp, #68 */
/* @0x149628 pop {r4, r5, r6, r7, pc} */
/* @0x14962c ldr r4, [r3, #0x4] */
/* @0x149630 add r6, sp, #64 */
/* @0x149634 mov r5, sp */
/* @0x149638 b 0x149658 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x14963c ldm r4, {r0, r1} */
/* @0x149640 vmov d6, r0, r1 */
/* @0x149644 add r4, r4, #16 */
/* @0x149648 vcvt.f32.f64 s15, d6 */
/* @0x14964c vstmia r5!, {s15} */
/* @0x149650 cmp r5, r6 */
/* @0x149654 beq 0x149674 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x149658 ldr r3, [r4, #0xc] */
/* @0x14965c bic r3, r3, #-16777216 */
/* @0x149660 cmp r3, #0 */
/* @0x149664 beq 0x14963c <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x149668 mov r0, r4 */
/* @0x14966c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x149670 b 0x149640 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x149674 ldr r5, [pc, #0x40] */
/* @0x149678 mov r4, sp */
/* @0x14967c ldm r4!, {r0, r1, r2, r3} */
/* @0x149680 ldr r5, [pc, r5] */
/* @0x149684 ldr r12, [pc, #0x34] */
/* @0x149688 ldr r5, [r5] */
/* @0x14968c ldr r12, [pc, r12] */
/* @0x149690 add r12, r12, r5, lsl #6 */
/* @0x149694 stm r12!, {r0, r1, r2, r3} */
/* @0x149698 ldm r4!, {r0, r1, r2, r3} */
/* @0x14969c stm r12!, {r0, r1, r2, r3} */
/* @0x1496a0 ldm r4!, {r0, r1, r2, r3} */
/* @0x1496a4 stm r12!, {r0, r1, r2, r3} */
/* @0x1496a8 ldm r4, {r0, r1, r2, r3} */
/* @0x1496ac stm r12, {r0, r1, r2, r3} */
/* @0x1496b0 b 0x1495d4 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x1496b4 andseq r9, pc, r4, lsl r3 */
/* @0x1496b8 andseq r9, pc, r8, ror #5 */
/* @0x1496bc eoreq r5, r10, r4, lsl #31 */
/* @0x1496c0 eoreq r5, r10, r12, ror pc */

/* ── FUNC 0x1496c4 · F_D3DMatrixMultiply(RValue&, CInstance*, CInstance*, int, RValue*) · size=544 · insn=136 */
/* @0x1496c4 cmp r3, #2 */
/* @0x1496c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1496cc vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1496d0 mov r6, r0 */
/* @0x1496d4 sub sp, sp, #316 */
/* @0x1496d8 beq 0x1496f8 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1496dc ldr r0, [pc, #0x1f4] */
/* @0x1496e0 mov r1, r3 */
/* @0x1496e4 add r0, pc, r0 */
/* @0x1496e8 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1496ec add sp, sp, #316 */
/* @0x1496f0 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1496f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1496f8 ldr r1, [sp, #0x198] */
/* @0x1496fc ldr r3, [r1, #0xc] */
/* @0x149700 cmp r3, #2 */
/* @0x149704 bne 0x149714 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x149708 ldr r3, [r1, #0x1c] */
/* @0x14970c cmp r3, #2 */
/* @0x149710 beq 0x14972c <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x149714 ldr r0, [pc, #0x1c0] */
/* @0x149718 add r0, pc, r0 */
/* @0x14971c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x149720 add sp, sp, #316 */
/* @0x149724 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x149728 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14972c ldr r2, [sp, #0x198] */
/* @0x149730 ldr r3, [r2] */
/* @0x149734 ldr r3, [r3, #0x4] */
/* @0x149738 ldr r2, [r3] */
/* @0x14973c cmp r2, #16 */
/* @0x149740 beq 0x149758 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x149744 ldr r0, [pc, #0x194] */
/* @0x149748 mov r1, #1 */
/* @0x14974c add r0, pc, r0 */
/* @0x149750 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x149754 b 0x1496ec <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x149758 ldr r1, [sp, #0x198] */
/* @0x14975c ldr r2, [r1, #0x10] */
/* @0x149760 ldr r2, [r2, #0x4] */
/* @0x149764 ldr r1, [r2] */
/* @0x149768 cmp r1, #16 */
/* @0x14976c bne 0x149744 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x149770 add r4, sp, #184 */
/* @0x149774 add r5, sp, #120 */
/* @0x149778 ldr r8, [r3, #0x4] */
/* @0x14977c add r9, sp, #248 */
/* @0x149780 ldr r7, [r2, #0x4] */
/* @0x149784 mov r10, r4 */
/* @0x149788 mov r11, r5 */
/* @0x14978c b 0x1497d0 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x149790 ldm r8, {r0, r1} */
/* @0x149794 vmov d6, r0, r1 */
/* @0x149798 ldr r1, [r7, #0xc] */
/* @0x14979c vcvt.f32.f64 s15, d6 */
/* @0x1497a0 bic r1, r1, #-16777216 */
/* @0x1497a4 cmp r1, #0 */
/* @0x1497a8 vstmia r11!, {s15} */
/* @0x1497ac bne 0x1497ec <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x1497b0 ldm r7, {r0, r1} */
/* @0x1497b4 vmov d6, r0, r1 */
/* @0x1497b8 add r8, r8, #16 */
/* @0x1497bc add r7, r7, #16 */
/* @0x1497c0 vcvt.f32.f64 s15, d6 */
/* @0x1497c4 vstmia r10!, {s15} */
/* @0x1497c8 cmp r10, r9 */
/* @0x1497cc beq 0x1497f8 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1497d0 ldr r1, [r8, #0xc] */
/* @0x1497d4 bic r1, r1, #-16777216 */
/* @0x1497d8 cmp r1, #0 */
/* @0x1497dc beq 0x149790 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x1497e0 mov r0, r8 */
/* @0x1497e4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1497e8 b 0x149794 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x1497ec mov r0, r7 */
/* @0x1497f0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1497f4 b 0x1497b4 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x1497f8 mov r0, r10 */
/* @0x1497fc mov r1, r5 */
/* @0x149800 mov r2, r4 */
/* @0x149804 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x149808 vldr s14, [sp, #252] */
/* @0x14980c vcvt.f64.f32 d7, s14 */
/* @0x149810 vldr s26, [sp, #256] */
/* @0x149814 vldr s24, [sp, #260] */
/* @0x149818 vldr s22, [sp, #264] */
/* @0x14981c vldr s20, [sp, #268] */
/* @0x149820 vldr s18, [sp, #272] */
/* @0x149824 vldr s16, [sp, #276] */
/* @0x149828 vldr s0, [sp, #280] */
/* @0x14982c vldr s2, [sp, #284] */
/* @0x149830 vldr s4, [sp, #288] */
/* @0x149834 vldr s6, [sp, #292] */
/* @0x149838 vldr s8, [sp, #296] */
/* @0x14983c vldr s10, [sp, #300] */
/* @0x149840 vldr s12, [sp, #304] */
/* @0x149844 vstr d7, [sp] */
/* @0x149848 vldr s14, [sp, #308] */
/* @0x14984c vcvt.f64.f32 d7, s14 */
/* @0x149850 vldr s28, [sp, #248] */
/* @0x149854 mov r0, r6 */
/* @0x149858 mov r1, #16 */
/* @0x14985c vcvt.f64.f32 d13, s26 */
/* @0x149860 vstr d7, [sp, #112] */
/* @0x149864 vcvt.f64.f32 d12, s24 */
/* @0x149868 vstr d13, [sp, #8] */
/* @0x14986c vcvt.f64.f32 d11, s22 */
/* @0x149870 vstr d12, [sp, #16] */
/* @0x149874 vcvt.f64.f32 d10, s20 */
/* @0x149878 vstr d11, [sp, #24] */
/* @0x14987c vcvt.f64.f32 d9, s18 */
/* @0x149880 vstr d10, [sp, #32] */
/* @0x149884 vcvt.f64.f32 d8, s16 */
/* @0x149888 vstr d9, [sp, #40] */
/* @0x14988c vcvt.f64.f32 d0, s0 */
/* @0x149890 vstr d8, [sp, #48] */
/* @0x149894 vcvt.f64.f32 d1, s2 */
/* @0x149898 vstr d0, [sp, #56] */
/* @0x14989c vcvt.f64.f32 d2, s4 */
/* @0x1498a0 vstr d1, [sp, #64] */
/* @0x1498a4 vcvt.f64.f32 d3, s6 */
/* @0x1498a8 vstr d2, [sp, #72] */
/* @0x1498ac vcvt.f64.f32 d4, s8 */
/* @0x1498b0 vstr d3, [sp, #80] */
/* @0x1498b4 vcvt.f64.f32 d5, s10 */
/* @0x1498b8 vstr d4, [sp, #88] */
/* @0x1498bc vcvt.f64.f32 d6, s12 */
/* @0x1498c0 vstr d5, [sp, #96] */
/* @0x1498c4 vcvt.f64.f32 d7, s28 */
/* @0x1498c8 vstr d6, [sp, #104] */
/* @0x1498cc vmov r2, r3, d7 */
/* @0x1498d0 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x1498d4 b 0x1496ec <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1498d8 andseq r9, pc, r4, asr #4 */
/* @0x1498dc andseq r9, pc, r12, lsr r2 */
/* @0x1498e0 andseq r9, pc, r0, lsr r2 */

/* ── FUNC 0x1498e4 · F_D3DMatrixTransformVertex(RValue&, CInstance*, CInstance*, int, RValue*) · size=336 · insn=84 */
/* @0x1498e4 push {r4, r5, r6, r7, lr} */
/* @0x1498e8 vpush {d8, d9} */
/* @0x1498ec sub sp, sp, #84 */
/* @0x1498f0 mov r7, r0 */
/* @0x1498f4 ldr r4, [sp, #0x78] */
/* @0x1498f8 ldr r5, [r4, #0xc] */
/* @0x1498fc cmp r5, #2 */
/* @0x149900 beq 0x149920 <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x149904 ldr r0, [pc, #0x124] */
/* @0x149908 mov r1, #1 */
/* @0x14990c add r0, pc, r0 */
/* @0x149910 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149914 add sp, sp, #84 */
/* @0x149918 vpop {d8, d9} */
/* @0x14991c pop {r4, r5, r6, r7, pc} */
/* @0x149920 mov r0, r4 */
/* @0x149924 mov r1, #1 */
/* @0x149928 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14992c mov r1, r5 */
/* @0x149930 add r6, sp, #80 */
/* @0x149934 add r5, sp, #16 */
/* @0x149938 vmov s17, r0 */
/* @0x14993c mov r0, r4 */
/* @0x149940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x149944 mov r1, #3 */
/* @0x149948 vmov s18, r0 */
/* @0x14994c mov r0, r4 */
/* @0x149950 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x149954 ldr r3, [r4] */
/* @0x149958 ldr r3, [r3, #0x4] */
/* @0x14995c ldr r4, [r3, #0x4] */
/* @0x149960 vmov s16, r0 */
/* @0x149964 b 0x149984 <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x149968 ldm r4, {r0, r1} */
/* @0x14996c vmov d6, r0, r1 */
/* @0x149970 add r4, r4, #16 */
/* @0x149974 vcvt.f32.f64 s15, d6 */
/* @0x149978 vstmia r5!, {s15} */
/* @0x14997c cmp r5, r6 */
/* @0x149980 beq 0x1499a0 <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x149984 ldr r3, [r4, #0xc] */
/* @0x149988 bic r3, r3, #-16777216 */
/* @0x14998c cmp r3, #0 */
/* @0x149990 beq 0x149968 <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x149994 mov r0, r4 */
/* @0x149998 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x14999c b 0x14996c <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1499a0 vldr s14, [sp, #40] */
/* @0x1499a4 vmul.f32 s14, s18, s14 */
/* @0x1499a8 vldr s13, [sp, #36] */
/* @0x1499ac vldr s15, [sp, #32] */
/* @0x1499b0 vldr s5, [sp, #24] */
/* @0x1499b4 vldr s4, [sp, #20] */
/* @0x1499b8 vldr s6, [sp, #16] */
/* @0x1499bc vldr s8, [sp, #56] */
/* @0x1499c0 vldr s7, [sp, #52] */
/* @0x1499c4 vldr s9, [sp, #48] */
/* @0x1499c8 vldr s10, [sp, #72] */
/* @0x1499cc vldr s12, [sp, #68] */
/* @0x1499d0 vldr s11, [sp, #64] */
/* @0x1499d4 mov r0, r7 */
/* @0x1499d8 mov r1, #3 */
/* @0x1499dc vmul.f32 s13, s18, s13 */
/* @0x1499e0 vmul.f32 s15, s18, s15 */
/* @0x1499e4 vmla.f32 s14, s17, s5 */
/* @0x1499e8 vmla.f32 s13, s17, s4 */
/* @0x1499ec vmla.f32 s15, s17, s6 */
/* @0x1499f0 vmla.f32 s14, s16, s8 */
/* @0x1499f4 vmla.f32 s15, s16, s9 */
/* @0x1499f8 vmla.f32 s13, s16, s7 */
/* @0x1499fc vadd.f32 s14, s14, s10 */
/* @0x149a00 vadd.f32 s11, s15, s11 */
/* @0x149a04 vadd.f32 s13, s13, s12 */
/* @0x149a08 vcvt.f64.f32 d7, s14 */
/* @0x149a0c vcvt.f64.f32 d6, s13 */
/* @0x149a10 vstr d7, [sp, #8] */
/* @0x149a14 vcvt.f64.f32 d7, s11 */
/* @0x149a18 vstr d6, [sp] */
/* @0x149a1c vmov r2, r3, d7 */
/* @0x149a20 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x149a24 add sp, sp, #84 */
/* @0x149a28 vpop {d8, d9} */
/* @0x149a2c pop {r4, r5, r6, r7, pc} */
/* @0x149a30 andseq r9, pc, r0, lsr #1 */

/* ── FUNC 0x149a34 · F_D3DSetMatrix(RValue&, CInstance*, CInstance*, int, RValue*) · size=268 · insn=67 */
/* @0x149a34 push {r4, r5, r6, r7, r8, lr} */
/* @0x149a38 sub sp, sp, #64 */
/* @0x149a3c mov r1, #0 */
/* @0x149a40 mov r5, r3 */
/* @0x149a44 ldr r4, [sp, #0x58] */
/* @0x149a48 mov r0, r4 */
/* @0x149a4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149a50 cmp r0, #2 */
/* @0x149a54 mov r6, r0 */
/* @0x149a58 bhi 0x149ad0 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x149a5c cmp r5, #2 */
/* @0x149a60 beq 0x149afc <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x149a64 ldr r3, [r4, #0x10] */
/* @0x149a68 ldr r3, [r3, #0x4] */
/* @0x149a6c ldr r4, [r3, #0x4] */
/* @0x149a70 add r8, sp, #64 */
/* @0x149a74 mov r5, sp */
/* @0x149a78 b 0x149a98 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x149a7c ldm r4, {r0, r1} */
/* @0x149a80 vmov d6, r0, r1 */
/* @0x149a84 add r4, r4, #16 */
/* @0x149a88 vcvt.f32.f64 s15, d6 */
/* @0x149a8c vstmia r5!, {s15} */
/* @0x149a90 cmp r5, r8 */
/* @0x149a94 beq 0x149ab4 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x149a98 ldr r3, [r4, #0xc] */
/* @0x149a9c bic r3, r3, #-16777216 */
/* @0x149aa0 cmp r3, #0 */
/* @0x149aa4 beq 0x149a7c <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x149aa8 mov r0, r4 */
/* @0x149aac bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x149ab0 b 0x149a80 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x149ab4 cmp r6, #2 */
/* @0x149ab8 beq 0x149ae8 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x149abc mov r0, r6 */
/* @0x149ac0 mov r1, sp */
/* @0x149ac4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x149ac8 add sp, sp, #64 */
/* @0x149acc pop {r4, r5, r6, r7, r8, pc} */
/* @0x149ad0 ldr r0, [pc, #0x5c] */
/* @0x149ad4 mov r1, #1 */
/* @0x149ad8 add r0, pc, r0 */
/* @0x149adc bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149ae0 add sp, sp, #64 */
/* @0x149ae4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x149ae8 ldr r3, [pc, #0x48] */
/* @0x149aec mov r2, #1 */
/* @0x149af0 ldr r3, [pc, r3] */
/* @0x149af4 strb r2, [r3] */
/* @0x149af8 b 0x149abc <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x149afc ldr r3, [r4, #0x1c] */
/* @0x149b00 bic r3, r3, #-16777216 */
/* @0x149b04 cmp r3, #2 */
/* @0x149b08 bne 0x149a64 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x149b0c ldr r3, [r4, #0x10] */
/* @0x149b10 ldr r3, [r3, #0x4] */
/* @0x149b14 ldr r2, [r3] */
/* @0x149b18 cmp r2, #16 */
/* @0x149b1c beq 0x149a6c <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x149b20 ldr r0, [pc, #0x14] */
/* @0x149b24 mov r1, #1 */
/* @0x149b28 add r0, pc, r0 */
/* @0x149b2c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149b30 b 0x149ac8 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x149b34 andseq r7, pc, r4, lsl #28 */
/* @0x149b38 eoreq r5, r10, r0, asr #22 */
/* @0x149b3c mulseq pc, r12, lr */

/* ── FUNC 0x149b40 · BuildFrustum(yyMatrix*) · size=388 · insn=97 */
/* @0x149b40 push {r3, r4, r5, lr} */
/* @0x149b44 vpush {d8} */
/* @0x149b48 vldr s7, [r0, #16] */
/* @0x149b4c vldr s13, [r0, #28] */
/* @0x149b50 vadd.f32 s6, s13, s7 */
/* @0x149b54 ldr r3, [pc, #0x164] */
/* @0x149b58 vldr s10, [r0] */
/* @0x149b5c vldr s12, [r0, #12] */
/* @0x149b60 ldr r3, [pc, r3] */
/* @0x149b64 vldr s14, [r0, #44] */
/* @0x149b68 vldr s8, [r0, #32] */
/* @0x149b6c vldr s15, [r0, #60] */
/* @0x149b70 vldr s9, [r0, #48] */
/* @0x149b74 vldr s11, [r0, #52] */
/* @0x149b78 add r4, r3, #8 */
/* @0x149b7c add r5, r3, #104 */
/* @0x149b80 vsub.f32 s7, s13, s7 */
/* @0x149b84 vstr s6, [r3, #4] */
/* @0x149b88 vstr s7, [r3, #20] */
/* @0x149b8c vadd.f32 s6, s14, s8 */
/* @0x149b90 vadd.f32 s7, s15, s9 */
/* @0x149b94 vstr s6, [r3, #8] */
/* @0x149b98 vsub.f32 s5, s12, s10 */
/* @0x149b9c vstr s7, [r3, #12] */
/* @0x149ba0 vsub.f32 s8, s14, s8 */
/* @0x149ba4 vstr s5, [r3, #16] */
/* @0x149ba8 vsub.f32 s9, s15, s9 */
/* @0x149bac vstr s8, [r3, #24] */
/* @0x149bb0 vstr s9, [r3, #28] */
/* @0x149bb4 vldr s8, [r0, #4] */
/* @0x149bb8 vsub.f32 s9, s12, s8 */
/* @0x149bbc vadd.f32 s8, s12, s8 */
/* @0x149bc0 vstr s9, [r3, #32] */
/* @0x149bc4 vldr s9, [r0, #20] */
/* @0x149bc8 vsub.f32 s6, s13, s9 */
/* @0x149bcc vadd.f32 s9, s13, s9 */
/* @0x149bd0 vstr s6, [r3, #36] */
/* @0x149bd4 vadd.f32 s7, s12, s10 */
/* @0x149bd8 vldr s10, [r0, #36] */
/* @0x149bdc vstr s8, [r3, #48] */
/* @0x149be0 vstr s9, [r3, #52] */
/* @0x149be4 vsub.f32 s8, s14, s10 */
/* @0x149be8 vstr s7, [r3] */
/* @0x149bec vsub.f32 s9, s15, s11 */
/* @0x149bf0 vstr s8, [r3, #40] */
/* @0x149bf4 vadd.f32 s10, s14, s10 */
/* @0x149bf8 vstr s9, [r3, #44] */
/* @0x149bfc vadd.f32 s11, s15, s11 */
/* @0x149c00 vstr s10, [r3, #56] */
/* @0x149c04 vstr s11, [r3, #60] */
/* @0x149c08 vmov.f32 s16, #1.000000e+00 */
/* @0x149c0c vldr s8, [r0, #8] */
/* @0x149c10 vstr s8, [r3, #64] */
/* @0x149c14 vldr s9, [r0, #24] */
/* @0x149c18 vstr s9, [r3, #68] */
/* @0x149c1c vldr s10, [r0, #40] */
/* @0x149c20 vstr s10, [r3, #72] */
/* @0x149c24 vldr s11, [r0, #56] */
/* @0x149c28 vstr s11, [r3, #76] */
/* @0x149c2c vsub.f32 s12, s12, s8 */
/* @0x149c30 vsub.f32 s13, s13, s9 */
/* @0x149c34 vstr s12, [r3, #80] */
/* @0x149c38 vsub.f32 s14, s14, s10 */
/* @0x149c3c vstr s13, [r3, #84] */
/* @0x149c40 vsub.f32 s15, s15, s11 */
/* @0x149c44 vstr s14, [r3, #88] */
/* @0x149c48 vstr s15, [r3, #92] */
/* @0x149c4c vldr s13, [r4, #-4] */
/* @0x149c50 vmul.f32 s15, s13, s13 */
/* @0x149c54 vldr s12, [r4, #-8] */
/* @0x149c58 vldr s14, [r4] */
/* @0x149c5c vmla.f32 s15, s12, s12 */
/* @0x149c60 vmla.f32 s15, s14, s14 */
/* @0x149c64 vsqrt.f32 s11, s15 */
/* @0x149c68 vcmp.f32 s11, s11 */
/* @0x149c6c vmrs APSR_nzcv, fpscr */
/* @0x149c70 bne 0x149ca4 <_Z12BuildFrustumP8yyMatrix+0x164> */
/* @0x149c74 vdiv.f32 s11, s16, s11 */
/* @0x149c78 vmul.f32 s12, s12, s11 */
/* @0x149c7c vmul.f32 s13, s13, s11 */
/* @0x149c80 vstr s12, [r4, #-8] */
/* @0x149c84 vmul.f32 s11, s14, s11 */
/* @0x149c88 vstr s13, [r4, #-4] */
/* @0x149c8c vmov r3, s11 */
/* @0x149c90 str r3, [r4], #16 */
/* @0x149c94 cmp r4, r5 */
/* @0x149c98 bne 0x149c4c <_Z12BuildFrustumP8yyMatrix+0x10c> */
/* @0x149c9c vpop {d8} */
/* @0x149ca0 pop {r3, r4, r5, pc} */
/* @0x149ca4 vmov r0, s15 */
/* @0x149ca8 bl 0xb6700 <sqrtf@plt> */
/* @0x149cac vldr s12, [r4, #-8] */
/* @0x149cb0 vldr s13, [r4, #-4] */
/* @0x149cb4 vldr s14, [r4] */
/* @0x149cb8 vmov s11, r0 */
/* @0x149cbc b 0x149c74 <_Z12BuildFrustumP8yyMatrix+0x134> */
/* @0x149cc0 .word 0x002a5ad4 */

/* ── FUNC 0x149cc4 · F_D3DBuildFrustum(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x149cc4 push {r4, r5, r6, lr} */
/* @0x149cc8 sub sp, sp, #192 */
/* @0x149ccc add r5, sp, #64 */
/* @0x149cd0 mov r4, r0 */
/* @0x149cd4 mov r1, sp */
/* @0x149cd8 mov r0, #0 */
/* @0x149cdc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x149ce0 mov r1, r5 */
/* @0x149ce4 mov r0, #1 */
/* @0x149ce8 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x149cec mov r2, r5 */
/* @0x149cf0 add r5, sp, #128 */
/* @0x149cf4 mov r1, sp */
/* @0x149cf8 mov r0, r5 */
/* @0x149cfc bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x149d00 mov r0, r5 */
/* @0x149d04 bl 0x149b40 <_Z12BuildFrustumP8yyMatrix> */
/* @0x149d08 mov r3, #0 */
/* @0x149d0c str r3, [r4] */
/* @0x149d10 str r3, [r4, #0x4] */
/* @0x149d14 str r3, [r4, #0xc] */
/* @0x149d18 add sp, sp, #192 */
/* @0x149d1c pop {r4, r5, r6, pc} */

/* ── FUNC 0x149d20 · Frustum_TestSphere(float, float, float, float) · size=112 · insn=28 */
/* @0x149d20 ldr r12, [pc, #0x64] */
/* @0x149d24 vmov s9, r1 */
/* @0x149d28 vmov s10, r2 */
/* @0x149d2c ldr r12, [pc, r12] */
/* @0x149d30 vmov s8, r0 */
/* @0x149d34 add r2, r12, #8 */
/* @0x149d38 add r1, r12, #104 */
/* @0x149d3c vmov s11, r3 */
/* @0x149d40 vldr s15, [r2, #-4] */
/* @0x149d44 vmul.f32 s15, s9, s15 */
/* @0x149d48 vldr s12, [r2, #-8] */
/* @0x149d4c vldr s13, [r2] */
/* @0x149d50 vldr s14, [r2, #4] */
/* @0x149d54 add r2, r2, #16 */
/* @0x149d58 vmla.f32 s15, s8, s12 */
/* @0x149d5c vmla.f32 s15, s10, s13 */
/* @0x149d60 vadd.f32 s15, s15, s14 */
/* @0x149d64 vadd.f32 s15, s11, s15 */
/* @0x149d68 vcmpe.f32 s15, #0 */
/* @0x149d6c vmrs APSR_nzcv, fpscr */
/* @0x149d70 bmi 0x149d84 <_Z18Frustum_TestSphereffff+0x64> */
/* @0x149d74 cmp r2, r1 */
/* @0x149d78 bne 0x149d40 <_Z18Frustum_TestSphereffff+0x20> */
/* @0x149d7c mov r0, #1065353216 */
/* @0x149d80 bx lr */
/* @0x149d84 mov r0, #0 */
/* @0x149d88 bx lr */
/* @0x149d8c eoreq r5, r10, r8, lsl #18 */

/* ── FUNC 0x149d90 · F_D3DFrustumTestSphere(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x149d90 push {r4, r5, r6, r7, r8, lr} */
/* @0x149d94 mov r1, #0 */
/* @0x149d98 ldr r4, [sp, #0x18] */
/* @0x149d9c mov r5, r0 */
/* @0x149da0 mov r0, r4 */
/* @0x149da4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x149da8 mov r1, #1 */
/* @0x149dac mov r6, r0 */
/* @0x149db0 mov r0, r4 */
/* @0x149db4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x149db8 mov r1, #2 */
/* @0x149dbc mov r8, r0 */
/* @0x149dc0 mov r0, r4 */
/* @0x149dc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x149dc8 mov r1, #3 */
/* @0x149dcc mov r7, r0 */
/* @0x149dd0 mov r0, r4 */
/* @0x149dd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x149dd8 mov r1, r8 */
/* @0x149ddc mov r12, #0 */
/* @0x149de0 mov r2, r7 */
/* @0x149de4 str r12, [r5, #0xc] */
/* @0x149de8 mov r3, r0 */
/* @0x149dec mov r0, r6 */
/* @0x149df0 bl 0x149d20 <_Z18Frustum_TestSphereffff> */
/* @0x149df4 vmov s15, r0 */
/* @0x149df8 vcvt.f64.f32 d7, s15 */
/* @0x149dfc vmov r0, r1, d7 */
/* @0x149e00 vmov r2, s14 */
/* @0x149e04 mov r3, r1 */
/* @0x149e08 stm r5, {r2, r3} */
/* @0x149e0c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x149e10 · F_GPUSetLightingEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x149e10 cmp r3, #1 */
/* @0x149e14 push {r3, lr} */
/* @0x149e18 mov r3, #0 */
/* @0x149e1c mov r1, r3 */
/* @0x149e20 movt r3, #0xbff0 */
/* @0x149e24 str r1, [r0, #0xc] */
/* @0x149e28 stm r0, {r1, r3} */
/* @0x149e2c ldr r0, [sp, #0x8] */
/* @0x149e30 beq 0x149e44 <_Z22F_GPUSetLightingEnableR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x149e34 ldr r0, [pc, #0x24] */
/* @0x149e38 pop {r3, lr} */
/* @0x149e3c add r0, pc, r0 */
/* @0x149e40 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149e44 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x149e48 ldr r3, [pc, #0x14] */
/* @0x149e4c mov r1, #21 */
/* @0x149e50 mov r2, r0 */
/* @0x149e54 ldr r0, [pc, r3] */
/* @0x149e58 pop {r3, lr} */
/* @0x149e5c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x149e60 mulseq pc, r8, r11 */
/* @0x149e64 eoreq r3, r10, r4, lsr #29 */

/* ── FUNC 0x149e68 · F_GPUSetTexMipEnableExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x149e68 cmp r3, #2 */
/* @0x149e6c mov r3, #0 */
/* @0x149e70 push {r4, r5, r6, lr} */
/* @0x149e74 mov r1, r3 */
/* @0x149e78 ldr r4, [sp, #0x10] */
/* @0x149e7c movt r3, #0xbff0 */
/* @0x149e80 str r1, [r0, #0xc] */
/* @0x149e84 stm r0, {r1, r3} */
/* @0x149e88 beq 0x149e9c <_Z23F_GPUSetTexMipEnableExtR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x149e8c ldr r0, [pc, #0x44] */
/* @0x149e90 pop {r4, r5, r6, lr} */
/* @0x149e94 add r0, pc, r0 */
/* @0x149e98 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149e9c mov r0, r4 */
/* @0x149ea0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149ea4 mov r1, #1 */
/* @0x149ea8 mov r5, r0 */
/* @0x149eac mov r0, r4 */
/* @0x149eb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x149eb4 cmp r5, #7 */
/* @0x149eb8 pophi {r4, r5, r6, pc} */
/* @0x149ebc ldr r12, [pc, #0x18] */
/* @0x149ec0 mov r1, r5 */
/* @0x149ec4 mov r3, r0 */
/* @0x149ec8 mov r2, #9 */
/* @0x149ecc ldr r0, [pc, r12] */
/* @0x149ed0 pop {r4, r5, r6, lr} */
/* @0x149ed4 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x149ed8 mulseq pc, r12, r11 */
/* @0x149edc eoreq r3, r10, r12, lsr #28 */

/* ── FUNC 0x149ee0 · F_GPUGetLightingEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x149ee0 push {r3, r4, r5, lr} */
/* @0x149ee4 subs r5, r3, #0 */
/* @0x149ee8 mov r1, #0 */
/* @0x149eec mov r4, r0 */
/* @0x149ef0 str r1, [r0, #0xc] */
/* @0x149ef4 str r1, [r0] */
/* @0x149ef8 str r1, [r0, #0x4] */
/* @0x149efc bne 0x149f34 <_Z22F_GPUGetLightingEnableR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x149f00 ldr r0, [pc, #0x3c] */
/* @0x149f04 mov r1, #21 */
/* @0x149f08 ldr r0, [pc, r0] */
/* @0x149f0c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x149f10 cmp r0, #0 */
/* @0x149f14 moveq r3, r0 */
/* @0x149f18 movne r2, #0 */
/* @0x149f1c movne r3, r5 */
/* @0x149f20 movtne r2, #0x3ff0 */
/* @0x149f24 moveq r2, r3 */
/* @0x149f28 str r3, [r4] */
/* @0x149f2c str r2, [r4, #0x4] */
/* @0x149f30 pop {r3, r4, r5, pc} */
/* @0x149f34 ldr r0, [pc, #0xc] */
/* @0x149f38 pop {r3, r4, r5, lr} */
/* @0x149f3c add r0, pc, r0 */
/* @0x149f40 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x149f44 .word 0x002a3df0 */
/* @0x149f48 andseq r8, pc, r0, asr r11 */

/* ── FUNC 0x149f4c · Init3DFunctions() · size=7012 · insn=1753 */
/* @0x149f4c push {r4, r5, r6, r7, r8, lr} */
/* @0x149f50 ldr r4, [pc, #0xbe4] */
/* @0x149f54 ldr r3, [pc, #0xbe4] */
/* @0x149f58 add r4, pc, r4 */
/* @0x149f5c ldr r6, [r4, r3] */
/* @0x149f60 ldrb r5, [r6] */
/* @0x149f64 cmp r5, #0 */
/* @0x149f68 beq 0x14b0f0 <_Z15Init3DFunctionsv+0x11a4> */
/* @0x149f6c ldr r1, [pc, #0xbd0] */
/* @0x149f70 mov r2, #1 */
/* @0x149f74 ldr r0, [pc, #0xbcc] */
/* @0x149f78 mov r3, r2 */
/* @0x149f7c add r0, pc, r0 */
/* @0x149f80 ldr r1, [r4, r1] */
/* @0x149f84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x149f88 ldr r1, [pc, #0xbbc] */
/* @0x149f8c ldr r0, [pc, #0xbbc] */
/* @0x149f90 mov r2, #2 */
/* @0x149f94 mov r3, #1 */
/* @0x149f98 add r0, pc, r0 */
/* @0x149f9c ldr r1, [r4, r1] */
/* @0x149fa0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x149fa4 ldr r1, [pc, #0xba8] */
/* @0x149fa8 ldr r0, [pc, #0xba8] */
/* @0x149fac mov r2, #0 */
/* @0x149fb0 mov r3, #1 */
/* @0x149fb4 add r0, pc, r0 */
/* @0x149fb8 ldr r1, [r4, r1] */
/* @0x149fbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x149fc0 ldr r1, [pc, #0xb94] */
/* @0x149fc4 ldr r0, [pc, #0xb94] */
/* @0x149fc8 mov r2, #9 */
/* @0x149fcc mov r3, #1 */
/* @0x149fd0 add r0, pc, r0 */
/* @0x149fd4 ldr r1, [r4, r1] */
/* @0x149fd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x149fdc ldr r1, [pc, #0xb80] */
/* @0x149fe0 ldr r0, [pc, #0xb80] */
/* @0x149fe4 mov r2, #9 */
/* @0x149fe8 mov r3, #1 */
/* @0x149fec add r0, pc, r0 */
/* @0x149ff0 ldr r1, [r4, r1] */
/* @0x149ff4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x149ff8 ldr r1, [pc, #0xb6c] */
/* @0x149ffc ldr r0, [pc, #0xb6c] */
/* @0x14a000 mov r2, #4 */
/* @0x14a004 mov r3, #1 */
/* @0x14a008 add r0, pc, r0 */
/* @0x14a00c ldr r1, [r4, r1] */
/* @0x14a010 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a014 ldr r1, [pc, #0xb58] */
/* @0x14a018 ldr r0, [pc, #0xb58] */
/* @0x14a01c mov r2, #4 */
/* @0x14a020 mov r3, #1 */
/* @0x14a024 add r0, pc, r0 */
/* @0x14a028 ldr r1, [r4, r1] */
/* @0x14a02c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a030 ldr r1, [pc, #0xb44] */
/* @0x14a034 ldr r0, [pc, #0xb44] */
/* @0x14a038 mov r2, #4 */
/* @0x14a03c mov r3, #1 */
/* @0x14a040 add r0, pc, r0 */
/* @0x14a044 ldr r1, [r4, r1] */
/* @0x14a048 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a04c ldr r1, [pc, #0xb30] */
/* @0x14a050 ldr r0, [pc, #0xb30] */
/* @0x14a054 mov r2, #2 */
/* @0x14a058 mov r3, #1 */
/* @0x14a05c add r0, pc, r0 */
/* @0x14a060 ldr r1, [r4, r1] */
/* @0x14a064 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a068 ldr r1, [pc, #0xb1c] */
/* @0x14a06c ldr r0, [pc, #0xb1c] */
/* @0x14a070 mov r2, #4 */
/* @0x14a074 mov r3, #1 */
/* @0x14a078 add r0, pc, r0 */
/* @0x14a07c ldr r1, [r4, r1] */
/* @0x14a080 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a084 ldr r1, [pc, #0xb08] */
/* @0x14a088 ldr r0, [pc, #0xb08] */
/* @0x14a08c mov r2, #0 */
/* @0x14a090 mov r3, #1 */
/* @0x14a094 add r0, pc, r0 */
/* @0x14a098 ldr r1, [r4, r1] */
/* @0x14a09c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a0a0 ldr r1, [pc, #0xaf4] */
/* @0x14a0a4 ldr r0, [pc, #0xaf4] */
/* @0x14a0a8 mov r2, #4 */
/* @0x14a0ac mov r3, #1 */
/* @0x14a0b0 add r0, pc, r0 */
/* @0x14a0b4 ldr r1, [r4, r1] */
/* @0x14a0b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a0bc ldr r1, [pc, #0xae0] */
/* @0x14a0c0 ldr r0, [pc, #0xae0] */
/* @0x14a0c4 mov r2, #0 */
/* @0x14a0c8 mov r3, r2 */
/* @0x14a0cc add r0, pc, r0 */
/* @0x14a0d0 ldr r1, [r4, r1] */
/* @0x14a0d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a0d8 ldr r1, [pc, #0xacc] */
/* @0x14a0dc ldr r0, [pc, #0xacc] */
/* @0x14a0e0 mov r2, #0 */
/* @0x14a0e4 mov r3, r2 */
/* @0x14a0e8 add r0, pc, r0 */
/* @0x14a0ec ldr r1, [r4, r1] */
/* @0x14a0f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a0f4 ldrb r3, [r6] */
/* @0x14a0f8 cmp r3, #0 */
/* @0x14a0fc popeq {r4, r5, r6, r7, r8, pc} */
/* @0x14a100 ldr r12, [pc, #0xaac] */
/* @0x14a104 mvn r5, #0 */
/* @0x14a108 ldr r1, [pc, #0xaa8] */
/* @0x14a10c mov r2, #0 */
/* @0x14a110 ldr r0, [pc, #0xaa4] */
/* @0x14a114 mov r3, #1 */
/* @0x14a118 ldr r12, [r4, r12] */
/* @0x14a11c add r0, pc, r0 */
/* @0x14a120 str r5, [r12] */
/* @0x14a124 ldr r1, [r4, r1] */
/* @0x14a128 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a12c ldr r1, [pc, #0xa8c] */
/* @0x14a130 ldr r0, [pc, #0xa8c] */
/* @0x14a134 mov r2, #0 */
/* @0x14a138 mov r3, #1 */
/* @0x14a13c add r0, pc, r0 */
/* @0x14a140 ldr r1, [r4, r1] */
/* @0x14a144 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a148 ldr r1, [pc, #0xa78] */
/* @0x14a14c ldr r0, [pc, #0xa78] */
/* @0x14a150 mov r2, #1 */
/* @0x14a154 mov r3, r2 */
/* @0x14a158 add r0, pc, r0 */
/* @0x14a15c ldr r1, [r4, r1] */
/* @0x14a160 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a164 ldr r1, [pc, #0xa64] */
/* @0x14a168 ldr r0, [pc, #0xa64] */
/* @0x14a16c mov r2, #0 */
/* @0x14a170 mov r3, #1 */
/* @0x14a174 add r0, pc, r0 */
/* @0x14a178 ldr r1, [r4, r1] */
/* @0x14a17c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a180 ldr r1, [pc, #0xa50] */
/* @0x14a184 ldr r0, [pc, #0xa50] */
/* @0x14a188 mov r2, #0 */
/* @0x14a18c mov r3, #1 */
/* @0x14a190 add r0, pc, r0 */
/* @0x14a194 ldr r1, [r4, r1] */
/* @0x14a198 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a19c ldr r1, [pc, #0xa3c] */
/* @0x14a1a0 ldr r0, [pc, #0xa3c] */
/* @0x14a1a4 mov r2, #0 */
/* @0x14a1a8 mov r3, #1 */
/* @0x14a1ac add r0, pc, r0 */
/* @0x14a1b0 ldr r1, [r4, r1] */
/* @0x14a1b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a1b8 ldr r1, [pc, #0xa28] */
/* @0x14a1bc ldr r0, [pc, #0xa28] */
/* @0x14a1c0 mov r2, #1 */
/* @0x14a1c4 mov r3, r2 */
/* @0x14a1c8 add r0, pc, r0 */
/* @0x14a1cc ldr r1, [r4, r1] */
/* @0x14a1d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a1d4 ldr r1, [pc, #0xa14] */
/* @0x14a1d8 ldr r0, [pc, #0xa14] */
/* @0x14a1dc mov r2, #1 */
/* @0x14a1e0 mov r3, r2 */
/* @0x14a1e4 add r0, pc, r0 */
/* @0x14a1e8 ldr r1, [r4, r1] */
/* @0x14a1ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a1f0 ldr r1, [pc, #0xa00] */
/* @0x14a1f4 ldr r0, [pc, #0xa00] */
/* @0x14a1f8 mov r2, #1 */
/* @0x14a1fc mov r3, r2 */
/* @0x14a200 add r0, pc, r0 */
/* @0x14a204 ldr r1, [r4, r1] */
/* @0x14a208 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a20c ldr r1, [pc, #0x9ec] */
/* @0x14a210 ldr r0, [pc, #0x9ec] */
/* @0x14a214 mov r2, #1 */
/* @0x14a218 mov r3, r2 */
/* @0x14a21c add r0, pc, r0 */
/* @0x14a220 ldr r1, [r4, r1] */
/* @0x14a224 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a228 ldr r1, [pc, #0x9d8] */
/* @0x14a22c ldr r0, [pc, #0x9d8] */
/* @0x14a230 mov r2, r5 */
/* @0x14a234 mov r3, #1 */
/* @0x14a238 add r0, pc, r0 */
/* @0x14a23c ldr r1, [r4, r1] */
/* @0x14a240 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a244 ldr r1, [pc, #0x9c4] */
/* @0x14a248 ldr r0, [pc, #0x9c4] */
/* @0x14a24c mov r2, #1 */
/* @0x14a250 mov r3, r2 */
/* @0x14a254 add r0, pc, r0 */
/* @0x14a258 ldr r1, [r4, r1] */
/* @0x14a25c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a260 ldr r1, [pc, #0x9b0] */
/* @0x14a264 ldr r0, [pc, #0x9b0] */
/* @0x14a268 mov r2, #1 */
/* @0x14a26c mov r3, r2 */
/* @0x14a270 add r0, pc, r0 */
/* @0x14a274 ldr r1, [r4, r1] */
/* @0x14a278 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a27c ldr r1, [pc, #0x99c] */
/* @0x14a280 ldr r0, [pc, #0x99c] */
/* @0x14a284 mov r2, r5 */
/* @0x14a288 mov r3, #1 */
/* @0x14a28c add r0, pc, r0 */
/* @0x14a290 ldr r1, [r4, r1] */
/* @0x14a294 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a298 ldr r1, [pc, #0x988] */
/* @0x14a29c ldr r0, [pc, #0x988] */
/* @0x14a2a0 mov r2, r5 */
/* @0x14a2a4 mov r3, #1 */
/* @0x14a2a8 add r0, pc, r0 */
/* @0x14a2ac ldr r1, [r4, r1] */
/* @0x14a2b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a2b4 ldr r1, [pc, #0x974] */
/* @0x14a2b8 ldr r0, [pc, #0x974] */
/* @0x14a2bc mov r2, r5 */
/* @0x14a2c0 mov r3, #1 */
/* @0x14a2c4 ldr r6, [r4, r1] */
/* @0x14a2c8 add r0, pc, r0 */
/* @0x14a2cc mov r1, r6 */
/* @0x14a2d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a2d4 ldr r0, [pc, #0x95c] */
/* @0x14a2d8 mov r1, r6 */
/* @0x14a2dc mov r2, r5 */
/* @0x14a2e0 add r0, pc, r0 */
/* @0x14a2e4 mov r3, #1 */
/* @0x14a2e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a2ec ldr r1, [pc, #0x948] */
/* @0x14a2f0 ldr r0, [pc, #0x948] */
/* @0x14a2f4 mov r2, #1 */
/* @0x14a2f8 mov r3, r2 */
/* @0x14a2fc add r0, pc, r0 */
/* @0x14a300 ldr r1, [r4, r1] */
/* @0x14a304 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a308 ldr r1, [pc, #0x934] */
/* @0x14a30c ldr r0, [pc, #0x934] */
/* @0x14a310 mov r2, #1 */
/* @0x14a314 mov r3, r2 */
/* @0x14a318 add r0, pc, r0 */
/* @0x14a31c ldr r1, [r4, r1] */
/* @0x14a320 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a324 ldr r1, [pc, #0x920] */
/* @0x14a328 ldr r0, [pc, #0x920] */
/* @0x14a32c mov r2, #1 */
/* @0x14a330 mov r3, r2 */
/* @0x14a334 add r0, pc, r0 */
/* @0x14a338 ldr r1, [r4, r1] */
/* @0x14a33c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a340 ldr r1, [pc, #0x90c] */
/* @0x14a344 ldr r0, [pc, #0x90c] */
/* @0x14a348 mov r2, #1 */
/* @0x14a34c mov r3, r2 */
/* @0x14a350 ldr r8, [r4, r1] */
/* @0x14a354 add r0, pc, r0 */
/* @0x14a358 mov r1, r8 */
/* @0x14a35c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a360 ldr r1, [pc, #0x8f4] */
/* @0x14a364 ldr r0, [pc, #0x8f4] */
/* @0x14a368 mov r2, #2 */
/* @0x14a36c mov r3, #1 */
/* @0x14a370 ldr r7, [r4, r1] */
/* @0x14a374 add r0, pc, r0 */
/* @0x14a378 mov r1, r7 */
/* @0x14a37c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a380 ldr r1, [pc, #0x8dc] */
/* @0x14a384 ldr r0, [pc, #0x8dc] */
/* @0x14a388 mov r2, #1 */
/* @0x14a38c mov r3, r2 */
/* @0x14a390 ldr r6, [r4, r1] */
/* @0x14a394 add r0, pc, r0 */
/* @0x14a398 mov r1, r6 */
/* @0x14a39c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a3a0 ldr r1, [pc, #0x8c4] */
/* @0x14a3a4 ldr r0, [pc, #0x8c4] */
/* @0x14a3a8 mov r2, #2 */
/* @0x14a3ac mov r3, #1 */
/* @0x14a3b0 ldr r5, [r4, r1] */
/* @0x14a3b4 add r0, pc, r0 */
/* @0x14a3b8 mov r1, r5 */
/* @0x14a3bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a3c0 ldr r0, [pc, #0x8ac] */
/* @0x14a3c4 mov r2, #1 */
/* @0x14a3c8 mov r1, r8 */
/* @0x14a3cc mov r3, r2 */
/* @0x14a3d0 add r0, pc, r0 */
/* @0x14a3d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a3d8 ldr r0, [pc, #0x898] */
/* @0x14a3dc mov r1, r7 */
/* @0x14a3e0 mov r2, #2 */
/* @0x14a3e4 add r0, pc, r0 */
/* @0x14a3e8 mov r3, #1 */
/* @0x14a3ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a3f0 ldr r0, [pc, #0x884] */
/* @0x14a3f4 mov r2, #1 */
/* @0x14a3f8 mov r1, r6 */
/* @0x14a3fc mov r3, r2 */
/* @0x14a400 add r0, pc, r0 */
/* @0x14a404 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a408 ldr r0, [pc, #0x870] */
/* @0x14a40c mov r1, r5 */
/* @0x14a410 mov r2, #2 */
/* @0x14a414 add r0, pc, r0 */
/* @0x14a418 mov r3, #1 */
/* @0x14a41c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a420 ldr r1, [pc, #0x85c] */
/* @0x14a424 ldr r0, [pc, #0x85c] */
/* @0x14a428 mov r2, #1 */
/* @0x14a42c mov r3, r2 */
/* @0x14a430 add r0, pc, r0 */
/* @0x14a434 ldr r1, [r4, r1] */
/* @0x14a438 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a43c ldr r1, [pc, #0x848] */
/* @0x14a440 ldr r0, [pc, #0x848] */
/* @0x14a444 mov r2, #2 */
/* @0x14a448 mov r3, #1 */
/* @0x14a44c add r0, pc, r0 */
/* @0x14a450 ldr r1, [r4, r1] */
/* @0x14a454 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a458 ldr r1, [pc, #0x834] */
/* @0x14a45c ldr r0, [pc, #0x834] */
/* @0x14a460 mov r2, #1 */
/* @0x14a464 mov r3, r2 */
/* @0x14a468 add r0, pc, r0 */
/* @0x14a46c ldr r1, [r4, r1] */
/* @0x14a470 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a474 ldr r1, [pc, #0x820] */
/* @0x14a478 ldr r0, [pc, #0x820] */
/* @0x14a47c mov r2, #2 */
/* @0x14a480 mov r3, #1 */
/* @0x14a484 add r0, pc, r0 */
/* @0x14a488 ldr r1, [r4, r1] */
/* @0x14a48c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a490 ldr r1, [pc, #0x80c] */
/* @0x14a494 ldr r0, [pc, #0x80c] */
/* @0x14a498 mov r2, #1 */
/* @0x14a49c mov r3, r2 */
/* @0x14a4a0 add r0, pc, r0 */
/* @0x14a4a4 ldr r1, [r4, r1] */
/* @0x14a4a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a4ac ldr r1, [pc, #0x7f8] */
/* @0x14a4b0 ldr r0, [pc, #0x7f8] */
/* @0x14a4b4 mov r2, #2 */
/* @0x14a4b8 mov r3, #1 */
/* @0x14a4bc add r0, pc, r0 */
/* @0x14a4c0 ldr r1, [r4, r1] */
/* @0x14a4c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a4c8 ldr r1, [pc, #0x7e4] */
/* @0x14a4cc ldr r0, [pc, #0x7e4] */
/* @0x14a4d0 mov r2, #1 */
/* @0x14a4d4 mov r3, r2 */
/* @0x14a4d8 add r0, pc, r0 */
/* @0x14a4dc ldr r1, [r4, r1] */
/* @0x14a4e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a4e4 ldr r1, [pc, #0x7d0] */
/* @0x14a4e8 ldr r0, [pc, #0x7d0] */
/* @0x14a4ec mov r2, #2 */
/* @0x14a4f0 mov r3, #1 */
/* @0x14a4f4 add r0, pc, r0 */
/* @0x14a4f8 ldr r1, [r4, r1] */
/* @0x14a4fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a500 ldr r1, [pc, #0x7bc] */
/* @0x14a504 ldr r0, [pc, #0x7bc] */
/* @0x14a508 mov r2, #1 */
/* @0x14a50c mov r3, r2 */
/* @0x14a510 add r0, pc, r0 */
/* @0x14a514 ldr r1, [r4, r1] */
/* @0x14a518 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a51c ldr r1, [pc, #0x7a8] */
/* @0x14a520 ldr r0, [pc, #0x7a8] */
/* @0x14a524 mov r2, #2 */
/* @0x14a528 mov r3, #1 */
/* @0x14a52c add r0, pc, r0 */
/* @0x14a530 ldr r1, [r4, r1] */
/* @0x14a534 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a538 ldr r1, [pc, #0x794] */
/* @0x14a53c ldr r0, [pc, #0x794] */
/* @0x14a540 mov r2, #1 */
/* @0x14a544 mov r3, r2 */
/* @0x14a548 ldr r5, [r4, r1] */
/* @0x14a54c add r0, pc, r0 */
/* @0x14a550 mov r1, r5 */
/* @0x14a554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a558 ldr r0, [pc, #0x77c] */
/* @0x14a55c mov r1, r5 */
/* @0x14a560 mov r2, #2 */
/* @0x14a564 add r0, pc, r0 */
/* @0x14a568 mov r3, #1 */
/* @0x14a56c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a570 ldr r1, [pc, #0x768] */
/* @0x14a574 ldr r0, [pc, #0x768] */
/* @0x14a578 mov r2, #0 */
/* @0x14a57c mov r3, #1 */
/* @0x14a580 add r0, pc, r0 */
/* @0x14a584 ldr r1, [r4, r1] */
/* @0x14a588 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a58c ldr r1, [pc, #0x754] */
/* @0x14a590 ldr r0, [pc, #0x754] */
/* @0x14a594 mov r2, #0 */
/* @0x14a598 mov r3, #1 */
/* @0x14a59c add r0, pc, r0 */
/* @0x14a5a0 ldr r1, [r4, r1] */
/* @0x14a5a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a5a8 ldr r1, [pc, #0x740] */
/* @0x14a5ac ldr r0, [pc, #0x740] */
/* @0x14a5b0 mov r2, #0 */
/* @0x14a5b4 mov r3, #1 */
/* @0x14a5b8 add r0, pc, r0 */
/* @0x14a5bc ldr r1, [r4, r1] */
/* @0x14a5c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a5c4 ldr r1, [pc, #0x72c] */
/* @0x14a5c8 ldr r0, [pc, #0x72c] */
/* @0x14a5cc mov r2, #0 */
/* @0x14a5d0 mov r3, #1 */
/* @0x14a5d4 add r0, pc, r0 */
/* @0x14a5d8 ldr r1, [r4, r1] */
/* @0x14a5dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a5e0 ldr r1, [pc, #0x718] */
/* @0x14a5e4 ldr r0, [pc, #0x718] */
/* @0x14a5e8 mov r2, #0 */
/* @0x14a5ec mov r3, #1 */
/* @0x14a5f0 add r0, pc, r0 */
/* @0x14a5f4 ldr r1, [r4, r1] */
/* @0x14a5f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a5fc ldr r1, [pc, #0x704] */
/* @0x14a600 ldr r0, [pc, #0x704] */
/* @0x14a604 mov r2, #0 */
/* @0x14a608 mov r3, #1 */
/* @0x14a60c add r0, pc, r0 */
/* @0x14a610 ldr r1, [r4, r1] */
/* @0x14a614 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a618 ldr r1, [pc, #0x6f0] */
/* @0x14a61c ldr r0, [pc, #0x6f0] */
/* @0x14a620 mov r2, #0 */
/* @0x14a624 mov r3, #1 */
/* @0x14a628 add r0, pc, r0 */
/* @0x14a62c ldr r1, [r4, r1] */
/* @0x14a630 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a634 ldr r1, [pc, #0x6dc] */
/* @0x14a638 ldr r0, [pc, #0x6dc] */
/* @0x14a63c mov r2, #0 */
/* @0x14a640 mov r3, #1 */
/* @0x14a644 add r0, pc, r0 */
/* @0x14a648 ldr r1, [r4, r1] */
/* @0x14a64c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a650 ldr r1, [pc, #0x6c8] */
/* @0x14a654 ldr r0, [pc, #0x6c8] */
/* @0x14a658 mov r2, #0 */
/* @0x14a65c mov r3, #1 */
/* @0x14a660 add r0, pc, r0 */
/* @0x14a664 ldr r1, [r4, r1] */
/* @0x14a668 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a66c ldr r1, [pc, #0x6b4] */
/* @0x14a670 ldr r0, [pc, #0x6b4] */
/* @0x14a674 mov r2, #0 */
/* @0x14a678 mov r3, #1 */
/* @0x14a67c add r0, pc, r0 */
/* @0x14a680 ldr r1, [r4, r1] */
/* @0x14a684 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a688 ldr r1, [pc, #0x6a0] */
/* @0x14a68c ldr r0, [pc, #0x6a0] */
/* @0x14a690 mov r2, #0 */
/* @0x14a694 mov r3, #1 */
/* @0x14a698 add r0, pc, r0 */
/* @0x14a69c ldr r1, [r4, r1] */
/* @0x14a6a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a6a4 ldr r1, [pc, #0x68c] */
/* @0x14a6a8 ldr r0, [pc, #0x68c] */
/* @0x14a6ac mov r2, #0 */
/* @0x14a6b0 mov r3, #1 */
/* @0x14a6b4 add r0, pc, r0 */
/* @0x14a6b8 ldr r1, [r4, r1] */
/* @0x14a6bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a6c0 ldr r1, [pc, #0x678] */
/* @0x14a6c4 ldr r0, [pc, #0x678] */
/* @0x14a6c8 mov r2, #0 */
/* @0x14a6cc mov r3, #1 */
/* @0x14a6d0 add r0, pc, r0 */
/* @0x14a6d4 ldr r1, [r4, r1] */
/* @0x14a6d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a6dc ldr r1, [pc, #0x664] */
/* @0x14a6e0 ldr r0, [pc, #0x664] */
/* @0x14a6e4 mov r2, #0 */
/* @0x14a6e8 mov r3, #1 */
/* @0x14a6ec ldr r5, [r4, r1] */
/* @0x14a6f0 add r0, pc, r0 */
/* @0x14a6f4 mov r1, r5 */
/* @0x14a6f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a6fc ldr r0, [pc, #0x64c] */
/* @0x14a700 mov r1, r5 */
/* @0x14a704 mov r2, #0 */
/* @0x14a708 add r0, pc, r0 */
/* @0x14a70c mov r3, #1 */
/* @0x14a710 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a714 ldr r1, [pc, #0x638] */
/* @0x14a718 ldr r0, [pc, #0x638] */
/* @0x14a71c mov r2, #0 */
/* @0x14a720 mov r3, #1 */
/* @0x14a724 add r0, pc, r0 */
/* @0x14a728 ldr r1, [r4, r1] */
/* @0x14a72c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a730 ldr r1, [pc, #0x624] */
/* @0x14a734 ldr r0, [pc, #0x624] */
/* @0x14a738 mov r2, #0 */
/* @0x14a73c mov r3, #1 */
/* @0x14a740 add r0, pc, r0 */
/* @0x14a744 ldr r1, [r4, r1] */
/* @0x14a748 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a74c ldr r1, [pc, #0x610] */
/* @0x14a750 ldr r0, [pc, #0x610] */
/* @0x14a754 mov r2, #0 */
/* @0x14a758 mov r3, #1 */
/* @0x14a75c add r0, pc, r0 */
/* @0x14a760 ldr r1, [r4, r1] */
/* @0x14a764 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a768 ldr r1, [pc, #0x5fc] */
/* @0x14a76c ldr r0, [pc, #0x5fc] */
/* @0x14a770 mov r2, #0 */
/* @0x14a774 mov r3, #1 */
/* @0x14a778 ldr r8, [r4, r1] */
/* @0x14a77c add r0, pc, r0 */
/* @0x14a780 mov r1, r8 */
/* @0x14a784 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a788 ldr r1, [pc, #0x5e4] */
/* @0x14a78c ldr r0, [pc, #0x5e4] */
/* @0x14a790 mov r2, #1 */
/* @0x14a794 mov r3, r2 */
/* @0x14a798 ldr r7, [r4, r1] */
/* @0x14a79c add r0, pc, r0 */
/* @0x14a7a0 mov r1, r7 */
/* @0x14a7a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a7a8 ldr r1, [pc, #0x5cc] */
/* @0x14a7ac ldr r0, [pc, #0x5cc] */
/* @0x14a7b0 mov r2, #0 */
/* @0x14a7b4 mov r3, #1 */
/* @0x14a7b8 ldr r6, [r4, r1] */
/* @0x14a7bc add r0, pc, r0 */
/* @0x14a7c0 mov r1, r6 */
/* @0x14a7c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a7c8 ldr r1, [pc, #0x5b4] */
/* @0x14a7cc ldr r0, [pc, #0x5b4] */
/* @0x14a7d0 mov r2, #1 */
/* @0x14a7d4 mov r3, r2 */
/* @0x14a7d8 ldr r5, [r4, r1] */
/* @0x14a7dc add r0, pc, r0 */
/* @0x14a7e0 mov r1, r5 */
/* @0x14a7e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a7e8 ldr r0, [pc, #0x59c] */
/* @0x14a7ec mov r1, r8 */
/* @0x14a7f0 mov r2, #0 */
/* @0x14a7f4 add r0, pc, r0 */
/* @0x14a7f8 mov r3, #1 */
/* @0x14a7fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a800 ldr r0, [pc, #0x588] */
/* @0x14a804 mov r2, #1 */
/* @0x14a808 mov r1, r7 */
/* @0x14a80c mov r3, r2 */
/* @0x14a810 add r0, pc, r0 */
/* @0x14a814 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a818 ldr r0, [pc, #0x574] */
/* @0x14a81c mov r1, r6 */
/* @0x14a820 mov r2, #0 */
/* @0x14a824 add r0, pc, r0 */
/* @0x14a828 mov r3, #1 */
/* @0x14a82c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a830 ldr r0, [pc, #0x560] */
/* @0x14a834 mov r2, #1 */
/* @0x14a838 mov r1, r5 */
/* @0x14a83c mov r3, r2 */
/* @0x14a840 add r0, pc, r0 */
/* @0x14a844 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a848 ldr r1, [pc, #0x54c] */
/* @0x14a84c ldr r0, [pc, #0x54c] */
/* @0x14a850 mov r2, #0 */
/* @0x14a854 mov r3, #1 */
/* @0x14a858 add r0, pc, r0 */
/* @0x14a85c ldr r1, [r4, r1] */
/* @0x14a860 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a864 ldr r1, [pc, #0x538] */
/* @0x14a868 ldr r0, [pc, #0x538] */
/* @0x14a86c mov r2, #1 */
/* @0x14a870 mov r3, r2 */
/* @0x14a874 add r0, pc, r0 */
/* @0x14a878 ldr r1, [r4, r1] */
/* @0x14a87c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a880 ldr r1, [pc, #0x524] */
/* @0x14a884 ldr r0, [pc, #0x524] */
/* @0x14a888 mov r2, #0 */
/* @0x14a88c mov r3, #1 */
/* @0x14a890 add r0, pc, r0 */
/* @0x14a894 ldr r1, [r4, r1] */
/* @0x14a898 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a89c ldr r1, [pc, #0x510] */
/* @0x14a8a0 ldr r0, [pc, #0x510] */
/* @0x14a8a4 mov r2, #1 */
/* @0x14a8a8 mov r3, r2 */
/* @0x14a8ac add r0, pc, r0 */
/* @0x14a8b0 ldr r1, [r4, r1] */
/* @0x14a8b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a8b8 ldr r1, [pc, #0x4fc] */
/* @0x14a8bc ldr r0, [pc, #0x4fc] */
/* @0x14a8c0 mov r2, #0 */
/* @0x14a8c4 mov r3, #1 */
/* @0x14a8c8 add r0, pc, r0 */
/* @0x14a8cc ldr r1, [r4, r1] */
/* @0x14a8d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a8d4 ldr r1, [pc, #0x4e8] */
/* @0x14a8d8 ldr r0, [pc, #0x4e8] */
/* @0x14a8dc mov r2, #1 */
/* @0x14a8e0 mov r3, r2 */
/* @0x14a8e4 add r0, pc, r0 */
/* @0x14a8e8 ldr r1, [r4, r1] */
/* @0x14a8ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a8f0 ldr r1, [pc, #0x4d4] */
/* @0x14a8f4 ldr r0, [pc, #0x4d4] */
/* @0x14a8f8 mov r2, #0 */
/* @0x14a8fc mov r3, #1 */
/* @0x14a900 add r0, pc, r0 */
/* @0x14a904 ldr r1, [r4, r1] */
/* @0x14a908 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a90c ldr r1, [pc, #0x4c0] */
/* @0x14a910 ldr r0, [pc, #0x4c0] */
/* @0x14a914 mov r2, #1 */
/* @0x14a918 mov r3, r2 */
/* @0x14a91c add r0, pc, r0 */
/* @0x14a920 ldr r1, [r4, r1] */
/* @0x14a924 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a928 ldr r1, [pc, #0x4ac] */
/* @0x14a92c ldr r0, [pc, #0x4ac] */
/* @0x14a930 mov r2, #1 */
/* @0x14a934 mov r3, r2 */
/* @0x14a938 add r0, pc, r0 */
/* @0x14a93c ldr r1, [r4, r1] */
/* @0x14a940 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a944 ldr r1, [pc, #0x498] */
/* @0x14a948 ldr r0, [pc, #0x498] */
/* @0x14a94c mov r2, #2 */
/* @0x14a950 mov r3, #1 */
/* @0x14a954 add r0, pc, r0 */
/* @0x14a958 ldr r1, [r4, r1] */
/* @0x14a95c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a960 ldr r1, [pc, #0x484] */
/* @0x14a964 ldr r0, [pc, #0x484] */
/* @0x14a968 mov r2, #0 */
/* @0x14a96c mov r3, #1 */
/* @0x14a970 add r0, pc, r0 */
/* @0x14a974 ldr r1, [r4, r1] */
/* @0x14a978 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a97c ldr r1, [pc, #0x470] */
/* @0x14a980 ldr r0, [pc, #0x470] */
/* @0x14a984 mov r2, #1 */
/* @0x14a988 mov r3, r2 */
/* @0x14a98c add r0, pc, r0 */
/* @0x14a990 ldr r1, [r4, r1] */
/* @0x14a994 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a998 ldr r1, [pc, #0x45c] */
/* @0x14a99c ldr r0, [pc, #0x45c] */
/* @0x14a9a0 mov r2, #0 */
/* @0x14a9a4 mov r3, #1 */
/* @0x14a9a8 add r0, pc, r0 */
/* @0x14a9ac ldr r1, [r4, r1] */
/* @0x14a9b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a9b4 ldr r1, [pc, #0x448] */
/* @0x14a9b8 ldr r0, [pc, #0x448] */
/* @0x14a9bc mov r2, #0 */
/* @0x14a9c0 mov r3, #1 */
/* @0x14a9c4 add r0, pc, r0 */
/* @0x14a9c8 ldr r1, [r4, r1] */
/* @0x14a9cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a9d0 ldr r1, [pc, #0x434] */
/* @0x14a9d4 ldr r0, [pc, #0x434] */
/* @0x14a9d8 mov r2, #0 */
/* @0x14a9dc mov r3, #1 */
/* @0x14a9e0 add r0, pc, r0 */
/* @0x14a9e4 ldr r1, [r4, r1] */
/* @0x14a9e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14a9ec ldr r1, [pc, #0x420] */
/* @0x14a9f0 ldr r0, [pc, #0x420] */
/* @0x14a9f4 mov r2, #1 */
/* @0x14a9f8 mov r3, r2 */
/* @0x14a9fc add r0, pc, r0 */
/* @0x14aa00 ldr r1, [r4, r1] */
/* @0x14aa04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aa08 ldr r1, [pc, #0x6ac] */
/* @0x14aa0c ldr r0, [pc, #0x408] */
/* @0x14aa10 mov r2, #1 */
/* @0x14aa14 mov r3, r2 */
/* @0x14aa18 add r0, pc, r0 */
/* @0x14aa1c ldr r1, [r4, r1] */
/* @0x14aa20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aa24 ldr r1, [pc, #0x698] */
/* @0x14aa28 ldr r0, [pc, #0x3f0] */
/* @0x14aa2c mov r2, #5 */
/* @0x14aa30 mov r3, #1 */
/* @0x14aa34 add r0, pc, r0 */
/* @0x14aa38 ldr r1, [r4, r1] */
/* @0x14aa3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aa40 ldr r1, [pc, #0x684] */
/* @0x14aa44 ldr r0, [pc, #0x3d8] */
/* @0x14aa48 mov r2, #6 */
/* @0x14aa4c mov r3, #1 */
/* @0x14aa50 add r0, pc, r0 */
/* @0x14aa54 ldr r1, [r4, r1] */
/* @0x14aa58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aa5c ldr r1, [pc, #0x670] */
/* @0x14aa60 ldr r0, [pc, #0x3c0] */
/* @0x14aa64 mov r2, #2 */
/* @0x14aa68 mov r3, #1 */
/* @0x14aa6c add r0, pc, r0 */
/* @0x14aa70 ldr r1, [r4, r1] */
/* @0x14aa74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aa78 ldr r1, [pc, #0x65c] */
/* @0x14aa7c ldr r0, [pc, #0x3a8] */
/* @0x14aa80 mov r2, #1 */
/* @0x14aa84 mov r3, r2 */
/* @0x14aa88 add r0, pc, r0 */
/* @0x14aa8c ldr r1, [r4, r1] */
/* @0x14aa90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aa94 ldr r1, [pc, #0x394] */
/* @0x14aa98 ldr r0, [pc, #0x394] */
/* @0x14aa9c mov r2, #0 */
/* @0x14aaa0 mov r3, #1 */
/* @0x14aaa4 add r0, pc, r0 */
/* @0x14aaa8 ldr r1, [r4, r1] */
/* @0x14aaac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aab0 ldr r1, [pc, #0x380] */
/* @0x14aab4 ldr r0, [pc, #0x380] */
/* @0x14aab8 mov r2, #1 */
/* @0x14aabc mov r3, r2 */
/* @0x14aac0 add r0, pc, r0 */
/* @0x14aac4 ldr r1, [r4, r1] */
/* @0x14aac8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aacc ldr r1, [pc, #0x36c] */
/* @0x14aad0 ldr r0, [pc, #0x36c] */
/* @0x14aad4 mov r2, #0 */
/* @0x14aad8 mov r3, #1 */
/* @0x14aadc ldr r1, [r4, r1] */
/* @0x14aae0 add r0, pc, r0 */
/* @0x14aae4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14aae8 ldr r3, [pc, #0x358] */
/* @0x14aaec mov r2, #0 */
/* @0x14aaf0 mov r1, #1065353216 */
/* @0x14aaf4 ldr r3, [r4, r3] */
/* @0x14aaf8 str r2, [r3, #0x38] */
/* @0x14aafc str r2, [r3, #0x34] */
/* @0x14ab00 str r2, [r3, #0x30] */
/* @0x14ab04 str r2, [r3, #0x2c] */
/* @0x14ab08 str r2, [r3, #0x24] */
/* @0x14ab0c str r2, [r3, #0x20] */
/* @0x14ab10 str r2, [r3, #0x1c] */
/* @0x14ab14 str r2, [r3, #0x18] */
/* @0x14ab18 str r2, [r3, #0x10] */
/* @0x14ab1c str r2, [r3, #0xc] */
/* @0x14ab20 str r2, [r3, #0x8] */
/* @0x14ab24 str r1, [r3, #0x3c] */
/* @0x14ab28 str r1, [r3, #0x28] */
/* @0x14ab2c str r1, [r3, #0x14] */
/* @0x14ab30 str r1, [r3] */
/* @0x14ab34 str r2, [r3, #0x4] */
/* @0x14ab38 pop {r4, r5, r6, r7, r8, pc} */
/* @0x14ab3c .word 0x002a7cf8 */
/* @0x14ab40 .word 0xffffbcd4 */
/* @0x14ab44 .word 0xffffd9e8 */
/* @0x14ab48 andseq r9, pc, r0, lsr #7 */
/* @0x14ab4c .word 0xffffd9ec */
/* @0x14ab50 mulseq pc, r0, r3 */
/* @0x14ab54 .word 0xffffd9f0 */
/* @0x14ab58 andseq r9, pc, r0, lsl #7 */
/* @0x14ab5c .word 0xffffd9f4 */
/* @0x14ab60 andseq r9, pc, r12, ror r3 */
/* @0x14ab64 .word 0xffffd9f8 */
/* @0x14ab68 andseq r9, pc, r0, ror r3 */
/* @0x14ab6c .word 0xffffd9fc */
/* @0x14ab70 andseq r9, pc, r8, ror #6 */
/* @0x14ab74 .word 0xffffda00 */
/* @0x14ab78 andseq r9, pc, r12, ror #6 */
/* @0x14ab7c .word 0xffffda04 */
/* @0x14ab80 andseq r9, pc, r4, ror r3 */
/* @0x14ab84 .word 0xffffda08 */
/* @0x14ab88 andseq r9, pc, r0, lsl #7 */
/* @0x14ab8c .word 0xffffda0c */
/* @0x14ab90 andseq r9, pc, r4, ror r3 */
/* @0x14ab94 .word 0xffffda10 */
/* @0x14ab98 andseq r9, pc, r0, ror r3 */
/* @0x14ab9c .word 0xffffda14 */
/* @0x14aba0 andseq r9, pc, r4, ror #6 */
/* @0x14aba4 .word 0xffffda18 */
/* @0x14aba8 andseq r9, pc, r12, asr r3 */
/* @0x14abac .word 0xffffda1c */
/* @0x14abb0 andseq r9, pc, r4, asr r3 */
/* @0x14abb4 .word 0xffffc0ac */
/* @0x14abb8 .word 0xffffda20 */
/* @0x14abbc andseq r9, pc, r12, lsr #6 */
/* @0x14abc0 .word 0xffffda24 */
/* @0x14abc4 andseq r9, pc, r0, lsr #6 */
/* @0x14abc8 .word 0xffffda28 */
/* @0x14abcc andseq r9, pc, r8, lsl r3 */
/* @0x14abd0 .word 0xffffda2c */
/* @0x14abd4 andseq r9, pc, r0, lsl r3 */
/* @0x14abd8 .word 0xffffda30 */
/* @0x14abdc andseq r9, pc, r8, lsl #6 */
/* @0x14abe0 .word 0xffffda34 */
/* @0x14abe4 andseq r9, pc, r0, lsl #6 */
/* @0x14abe8 .word 0xffffda38 */
/* @0x14abec ldrsheq r9, [pc], -r12 */
/* @0x14abf0 .word 0xffffda3c */
/* @0x14abf4 ldrsheq r9, [pc], -r4 */
/* @0x14abf8 .word 0xffffda40 */
/* @0x14abfc andseq r9, pc, r12, ror #5 */
/* @0x14ac00 .word 0xffffda44 */
/* @0x14ac04 andseq r9, pc, r0, ror #5 */
/* @0x14ac08 .word 0xffffda48 */
/* @0x14ac0c ldrsbeq r9, [pc], -r12 */
/* @0x14ac10 .word 0xffffda4c */
/* @0x14ac14 andseq r9, pc, r12, asr #5 */
/* @0x14ac18 .word 0xffffda50 */
/* @0x14ac1c andseq r9, pc, r4, asr #5 */
/* @0x14ac20 .word 0xffffda54 */
/* @0x14ac24 ldrheq r9, [pc], -r12 */
/* @0x14ac28 .word 0xffffda58 */
/* @0x14ac2c ldrheq r9, [pc], -r8 */
/* @0x14ac30 .word 0xffffda5c */
/* @0x14ac34 ldrheq r9, [pc], -r8 */
/* @0x14ac38 ldrheq r9, [pc], -r12 */
/* @0x14ac3c .word 0xffffda60 */
/* @0x14ac40 ldrheq r9, [pc], -r12 */
/* @0x14ac44 .word 0xffffda64 */
/* @0x14ac48 ldrheq r9, [pc], -r8 */
/* @0x14ac4c .word 0xffffda68 */
/* @0x14ac50 ldrheq r9, [pc], -r4 */
/* @0x14ac54 .word 0xffffda6c */
/* @0x14ac58 andseq r9, pc, r12, lsr #5 */
/* @0x14ac5c .word 0xffffda70 */
/* @0x14ac60 andseq r9, pc, r0, lsr #5 */
/* @0x14ac64 .word 0xffffda74 */
/* @0x14ac68 mulseq pc, r8, r2 */
/* @0x14ac6c .word 0xffffda78 */
/* @0x14ac70 andseq r9, pc, r12, lsl #5 */
/* @0x14ac74 andseq r9, pc, r8, lsl #5 */
/* @0x14ac78 andseq r9, pc, r8, lsl #5 */
/* @0x14ac7c andseq r9, pc, r4, lsl #5 */
/* @0x14ac80 andseq r9, pc, r4, lsl #5 */
/* @0x14ac84 .word 0xffffda7c */
/* @0x14ac88 andseq r9, pc, r0, lsl #5 */
/* @0x14ac8c .word 0xffffda80 */
/* @0x14ac90 andseq r9, pc, r12, ror r2 */
/* @0x14ac94 .word 0xffffda84 */
/* @0x14ac98 andseq r9, pc, r12, ror r2 */
/* @0x14ac9c .word 0xffffda88 */
/* @0x14aca0 andseq r9, pc, r8, ror r2 */
/* @0x14aca4 .word 0xffffda8c */
/* @0x14aca8 andseq r9, pc, r8, ror r2 */
/* @0x14acac .word 0xffffda90 */
/* @0x14acb0 andseq r9, pc, r0, ror r2 */
/* @0x14acb4 .word 0xffffda94 */
/* @0x14acb8 andseq r9, pc, r12, ror #4 */
/* @0x14acbc .word 0xffffda98 */
/* @0x14acc0 andseq r9, pc, r4, ror #4 */
/* @0x14acc4 .word 0xffffda9c */
/* @0x14acc8 andseq r9, pc, r0, ror #4 */
/* @0x14accc .word 0xffffdaa0 */
/* @0x14acd0 andseq r9, pc, r12, asr r2 */
/* @0x14acd4 .word 0xffffdaa4 */
/* @0x14acd8 andseq r9, pc, r8, asr r2 */
/* @0x14acdc andseq r9, pc, r8, asr r2 */
/* @0x14ace0 .word 0xffffdaa8 */
/* @0x14ace4 andseq r9, pc, r8, asr r2 */
/* @0x14ace8 .word 0xffffdaac */
/* @0x14acec andseq r9, pc, r0, asr r2 */
/* @0x14acf0 .word 0xffffdab0 */
/* @0x14acf4 andseq r9, pc, r8, asr #4 */
/* @0x14acf8 .word 0xffffdab4 */
/* @0x14acfc andseq r9, pc, r12, lsr r2 */
/* @0x14ad00 .word 0xffffdab8 */
/* @0x14ad04 andseq r9, pc, r8, lsr r2 */
/* @0x14ad08 .word 0xffffdabc */
/* @0x14ad0c andseq r9, pc, r8, lsr #4 */
/* @0x14ad10 .word 0xffffdac0 */
/* @0x14ad14 andseq r9, pc, r0, lsr #4 */
/* @0x14ad18 .word 0xffffdac4 */
/* @0x14ad1c andseq r9, pc, r8, lsl r2 */
/* @0x14ad20 .word 0xffffdac8 */
/* @0x14ad24 andseq r9, pc, r4, lsl r2 */
/* @0x14ad28 .word 0xffffdacc */
/* @0x14ad2c andseq r9, pc, r8, lsl r2 */
/* @0x14ad30 .word 0xffffdad0 */
/* @0x14ad34 andseq r9, pc, r4, lsl r2 */
/* @0x14ad38 .word 0xffffdad4 */
/* @0x14ad3c andseq r9, pc, r0, lsl r2 */
/* @0x14ad40 .word 0xffffdad8 */
/* @0x14ad44 andseq r9, pc, r0, lsl r2 */
/* @0x14ad48 .word 0xffffdadc */
/* @0x14ad4c andseq r9, pc, r12, lsl #4 */
/* @0x14ad50 andseq r9, pc, r0, lsl r2 */
/* @0x14ad54 .word 0xffffdae0 */
/* @0x14ad58 andseq r9, pc, r0, lsl r2 */
/* @0x14ad5c .word 0xffffdae4 */
/* @0x14ad60 andseq r9, pc, r12, lsl #4 */
/* @0x14ad64 .word 0xffffdae8 */
/* @0x14ad68 andseq r9, pc, r8, lsl #4 */
/* @0x14ad6c .word 0xffffdaec */
/* @0x14ad70 andseq r9, pc, r0, lsl #4 */
/* @0x14ad74 .word 0xffffdaf0 */
/* @0x14ad78 ldrsheq r9, [pc], -r4 */
/* @0x14ad7c .word 0xffffdaf4 */
/* @0x14ad80 andseq r9, pc, r12, ror #3 */
/* @0x14ad84 .word 0xffffdaf8 */
/* @0x14ad88 andseq r9, pc, r0, ror #3 */
/* @0x14ad8c andseq r9, pc, r0, ror #3 */
/* @0x14ad90 ldrsbeq r9, [pc], -r8 */
/* @0x14ad94 ldrsbeq r9, [pc], -r12 */
/* @0x14ad98 ldrsbeq r9, [pc], -r4 */
/* @0x14ad9c .word 0xffffdafc */
/* @0x14ada0 ldrsbeq r9, [pc], -r4 */
/* @0x14ada4 .word 0xffffdb00 */
/* @0x14ada8 ldrsbeq r9, [pc], -r0 */
/* @0x14adac .word 0xffffdb04 */
/* @0x14adb0 ldrsbeq r9, [pc], -r0 */
/* @0x14adb4 .word 0xffffdb08 */
/* @0x14adb8 andseq r9, pc, r12, asr #3 */
/* @0x14adbc .word 0xffffdb0c */
/* @0x14adc0 andseq r9, pc, r12, asr #3 */
/* @0x14adc4 .word 0xffffdb10 */
/* @0x14adc8 andseq r9, pc, r4, asr #3 */
/* @0x14adcc .word 0xffffdb14 */
/* @0x14add0 andseq r9, pc, r0, asr #3 */
/* @0x14add4 .word 0xffffdb18 */
/* @0x14add8 ldrheq r9, [pc], -r8 */
/* @0x14addc .word 0xffffdb1c */
/* @0x14ade0 ldrheq r9, [pc], -r4 */
/* @0x14ade4 .word 0xffffdb20 */
/* @0x14ade8 ldrheq r9, [pc], -r0 */
/* @0x14adec .word 0xffffdb24 */
/* @0x14adf0 ldrheq r9, [pc], -r0 */
/* @0x14adf4 .word 0xffffdb28 */
/* @0x14adf8 andseq r9, pc, r12, lsr #3 */
/* @0x14adfc .word 0xffffdb2c */
/* @0x14ae00 andseq r9, pc, r12, lsr #3 */
/* @0x14ae04 .word 0xffffdb30 */
/* @0x14ae08 andseq r9, pc, r0, lsr #3 */
/* @0x14ae0c .word 0xffffdb34 */
/* @0x14ae10 mulseq pc, r4, r1 */
/* @0x14ae14 .word 0xffffdb38 */
/* @0x14ae18 andseq r9, pc, r8, lsl #3 */
/* @0x14ae1c andseq r9, pc, r12, ror r1 */
/* @0x14ae20 andseq r9, pc, r12, ror r1 */
/* @0x14ae24 andseq r9, pc, r12, ror r1 */
/* @0x14ae28 andseq r9, pc, r8, ror r1 */
/* @0x14ae2c andseq r9, pc, r0, ror r1 */
/* @0x14ae30 .word 0xffffdb3c */
/* @0x14ae34 andseq r9, pc, r8, ror #2 */
/* @0x14ae38 .word 0xffffdb40 */
/* @0x14ae3c andseq r9, pc, r4, ror #2 */
/* @0x14ae40 .word 0xffffdb44 */
/* @0x14ae44 andseq r9, pc, r4, asr r1 */
/* @0x14ae48 .word 0xffffd9b8 */
/* @0x14ae4c .word 0xffffdb48 */
/* @0x14ae50 andseq r7, pc, r0, asr #19 */
/* @0x14ae54 .word 0xffffdb4c */
/* @0x14ae58 ldrheq r7, [pc], -r0 */
/* @0x14ae5c .word 0xffffdb50 */
/* @0x14ae60 mulseq pc, r12, r9 */
/* @0x14ae64 .word 0xffffdb54 */
/* @0x14ae68 mulseq pc, r4, r9 */
/* @0x14ae6c .word 0xffffdb58 */
/* @0x14ae70 andseq r7, pc, r8, lsl #19 */
/* @0x14ae74 .word 0xffffdb5c */
/* @0x14ae78 andseq r7, pc, r12, ror r9 */
/* @0x14ae7c .word 0xffffdb60 */
/* @0x14ae80 andseq r7, pc, r0, ror r9 */
/* @0x14ae84 .word 0xffffdb64 */
/* @0x14ae88 andseq r7, pc, r0, ror #18 */
/* @0x14ae8c .word 0xffffdb68 */
/* @0x14ae90 andseq r7, pc, r4, asr r9 */
/* @0x14ae94 .word 0xffffdb6c */
/* @0x14ae98 andseq r7, pc, r0, asr r9 */
/* @0x14ae9c .word 0xffffdb70 */
/* @0x14aea0 andseq r7, pc, r8, asr #18 */
/* @0x14aea4 .word 0xffffdb74 */
/* @0x14aea8 andseq r7, pc, r8, asr #18 */
/* @0x14aeac .word 0xffffdb78 */
/* @0x14aeb0 andseq r7, pc, r0, asr #18 */
/* @0x14aeb4 .word 0xffffdb7c */
/* @0x14aeb8 andseq r7, pc, r0, lsr r9 */
/* @0x14aebc andseq r7, pc, r12, lsr #18 */
/* @0x14aec0 .word 0xffffdb80 */
/* @0x14aec4 andseq r7, pc, r0, lsr #18 */
/* @0x14aec8 .word 0xffffdb84 */
/* @0x14aecc andseq r7, pc, r8, lsl r9 */
/* @0x14aed0 andseq r7, pc, r12, lsl r9 */
/* @0x14aed4 .word 0xffffdb88 */
/* @0x14aed8 andseq r7, pc, r8, lsl r9 */
/* @0x14aedc .word 0xffffdb8c */
/* @0x14aee0 andseq r7, pc, r0, lsl r9 */
/* @0x14aee4 andseq r7, pc, r0, lsl r9 */
/* @0x14aee8 .word 0xffffdb90 */
/* @0x14aeec andseq r7, pc, r12, lsl #18 */
/* @0x14aef0 .word 0xffffdb94 */
/* @0x14aef4 andseq r7, pc, r12, lsl #18 */
/* @0x14aef8 andseq r7, pc, r4, lsl r9 */
/* @0x14aefc .word 0xffffdb98 */
/* @0x14af00 andseq r7, pc, r8, lsl r9 */
/* @0x14af04 .word 0xffffdb9c */
/* @0x14af08 andseq r7, pc, r12, lsl #18 */
/* @0x14af0c .word 0xffffdba0 */
/* @0x14af10 andseq r7, pc, r4, lsl #18 */
/* @0x14af14 .word 0xffffdba4 */
/* @0x14af18 ldrsheq r7, [pc], -r8 */
/* @0x14af1c .word 0xffffdba8 */
/* @0x14af20 ldrsheq r7, [pc], -r0 */
/* @0x14af24 .word 0xffffdbac */
/* @0x14af28 andseq r7, pc, r4, ror #17 */
/* @0x14af2c .word 0xffffdbb0 */
/* @0x14af30 ldrsbeq r7, [pc], -r8 */
/* @0x14af34 .word 0xffffdbb4 */
/* @0x14af38 ldrsbeq r7, [pc], -r0 */
/* @0x14af3c .word 0xffffdbb8 */
/* @0x14af40 andseq r7, pc, r12, asr #17 */
/* @0x14af44 .word 0xffffdbbc */
/* @0x14af48 andseq r7, pc, r12, asr #17 */
/* @0x14af4c .word 0xffffdbc0 */
/* @0x14af50 ldrsbeq r7, [pc], -r0 */
/* @0x14af54 .word 0xffffdbc4 */
/* @0x14af58 ldrsbeq r7, [pc], -r0 */
/* @0x14af5c .word 0xffffdbc8 */
/* @0x14af60 ldrsbeq r7, [pc], -r4 */
/* @0x14af64 .word 0xffffdbcc */
/* @0x14af68 ldrsbeq r7, [pc], -r4 */
/* @0x14af6c .word 0xffffdbd0 */
/* @0x14af70 ldrsbeq r7, [pc], -r8 */
/* @0x14af74 .word 0xffffdbd4 */
/* @0x14af78 ldrsbeq r7, [pc], -r12 */
/* @0x14af7c .word 0xffffdbd8 */
/* @0x14af80 andseq r7, pc, r0, ror #17 */
/* @0x14af84 .word 0xffffdbdc */
/* @0x14af88 andseq r7, pc, r4, ror #17 */
/* @0x14af8c .word 0xffffdbe0 */
/* @0x14af90 andseq r7, pc, r8, ror #17 */
/* @0x14af94 .word 0xffffdbe4 */
/* @0x14af98 andseq r7, pc, r8, ror #17 */
/* @0x14af9c .word 0xffffdbe8 */
/* @0x14afa0 andseq r7, pc, r12, ror #17 */
/* @0x14afa4 .word 0xffffdbec */
/* @0x14afa8 ldrsheq r7, [pc], -r0 */
/* @0x14afac .word 0xffffdbf0 */
/* @0x14afb0 ldrsheq r7, [pc], -r4 */
/* @0x14afb4 .word 0xffffdbf4 */
/* @0x14afb8 ldrsheq r7, [pc], -r8 */
/* @0x14afbc .word 0xffffdbf8 */
/* @0x14afc0 ldrsheq r7, [pc], -r8 */
/* @0x14afc4 .word 0xffffdbfc */
/* @0x14afc8 ldrsheq r7, [pc], -r8 */
/* @0x14afcc .word 0xffffdc00 */
/* @0x14afd0 ldrsheq r7, [pc], -r8 */
/* @0x14afd4 .word 0xffffdc04 */
/* @0x14afd8 ldrsheq r7, [pc], -r4 */
/* @0x14afdc .word 0xffffdc08 */
/* @0x14afe0 ldrsheq r7, [pc], -r0 */
/* @0x14afe4 .word 0xffffdc0c */
/* @0x14afe8 ldrsheq r7, [pc], -r0 */
/* @0x14afec .word 0xffffdc10 */
/* @0x14aff0 andseq r7, pc, r12, ror #17 */
/* @0x14aff4 .word 0xffffdc14 */
/* @0x14aff8 andseq r7, pc, r4, ror #17 */
/* @0x14affc .word 0xffffdc18 */
/* @0x14b000 ldrsbeq r7, [pc], -r12 */
/* @0x14b004 .word 0xffffdc1c */
/* @0x14b008 ldrsbeq r7, [pc], -r0 */
/* @0x14b00c .word 0xffffdc20 */
/* @0x14b010 andseq r7, pc, r4, asr #17 */
/* @0x14b014 .word 0xffffdc24 */
/* @0x14b018 ldrheq r7, [pc], -r8 */
/* @0x14b01c .word 0xffffdc28 */
/* @0x14b020 ldrheq r7, [pc], -r4 */
/* @0x14b024 .word 0xffffdc2c */
/* @0x14b028 ldrheq r7, [pc], -r0 */
/* @0x14b02c .word 0xffffdc30 */
/* @0x14b030 andseq r7, pc, r4, lsr #17 */
/* @0x14b034 .word 0xffffdc34 */
/* @0x14b038 andseq r7, pc, r4, lsr #17 */
/* @0x14b03c .word 0xffffdc38 */
/* @0x14b040 andseq r7, pc, r0, lsr #17 */
/* @0x14b044 .word 0xffffdc3c */
/* @0x14b048 mulseq pc, r8, r8 */
/* @0x14b04c mulseq pc, r8, r8 */
/* @0x14b050 .word 0xffffdc40 */
/* @0x14b054 mulseq pc, r0, r8 */
/* @0x14b058 .word 0xffffdc44 */
/* @0x14b05c mulseq pc, r0, r8 */
/* @0x14b060 mulseq pc, r8, r8 */
/* @0x14b064 .word 0xffffdc48 */
/* @0x14b068 mulseq pc, r8, r8 */
/* @0x14b06c .word 0xffffdc4c */
/* @0x14b070 mulseq pc, r4, r8 */
/* @0x14b074 mulseq pc, r12, r8 */
/* @0x14b078 .word 0xffffdc50 */
/* @0x14b07c mulseq pc, r12, r8 */
/* @0x14b080 .word 0xffffdc54 */
/* @0x14b084 andseq r7, pc, r0, lsr #17 */
/* @0x14b088 ldrheq r7, [pc], -r0 */
/* @0x14b08c .word 0xffffdc58 */
/* @0x14b090 ldrheq r7, [pc], -r8 */
/* @0x14b094 .word 0xffffdc5c */
/* @0x14b098 andseq r7, pc, r12, lsr #17 */
/* @0x14b09c .word 0xffffdc60 */
/* @0x14b0a0 andseq r7, pc, r4, lsr #17 */
/* @0x14b0a4 .word 0xffffdc64 */
/* @0x14b0a8 mulseq pc, r8, r8 */
/* @0x14b0ac .word 0xffffdc68 */
/* @0x14b0b0 mulseq pc, r0, r8 */
/* @0x14b0b4 .word 0xffffdc6c */
/* @0x14b0b8 andseq r7, pc, r4, lsl #17 */
/* @0x14b0bc .word 0xffffdc70 */
/* @0x14b0c0 andseq r7, pc, r8, ror r8 */
/* @0x14b0c4 .word 0xffffdc74 */
/* @0x14b0c8 andseq r7, pc, r8, ror r8 */
/* @0x14b0cc .word 0xffffdc78 */
/* @0x14b0d0 andseq r7, pc, r8, ror r8 */
/* @0x14b0d4 .word 0xffffdc7c */
/* @0x14b0d8 andseq r7, pc, r4, ror r8 */
/* @0x14b0dc .word 0xffffdc80 */
/* @0x14b0e0 andseq r7, pc, r12, ror #16 */
/* @0x14b0e4 .word 0xffffdc84 */
/* @0x14b0e8 andseq r7, pc, r4, ror #16 */
/* @0x14b0ec andseq r7, pc, r4, ror #16 */
/* @0x14b0f0 ldr r1, [pc, #-0x2ac] */
/* @0x14b0f4 mov r2, r5 */
/* @0x14b0f8 ldr r0, [pc, #-0x2b0] */
/* @0x14b0fc mov r3, #1 */
/* @0x14b100 ldr r1, [r4, r1] */
/* @0x14b104 add r0, pc, r0 */
/* @0x14b108 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b10c ldr r1, [pc, #-0x2c0] */
/* @0x14b110 ldr r0, [pc, #-0x2c0] */
/* @0x14b114 mov r2, r5 */
/* @0x14b118 mov r3, #1 */
/* @0x14b11c ldr r1, [r4, r1] */
/* @0x14b120 add r0, pc, r0 */
/* @0x14b124 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b128 ldr r1, [pc, #-0x2d4] */
/* @0x14b12c ldr r0, [pc, #-0x2d4] */
/* @0x14b130 mov r2, #1 */
/* @0x14b134 mov r3, r2 */
/* @0x14b138 ldr r1, [r4, r1] */
/* @0x14b13c add r0, pc, r0 */
/* @0x14b140 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b144 ldr r1, [pc, #-0x2e8] */
/* @0x14b148 ldr r0, [pc, #-0x2e8] */
/* @0x14b14c mov r2, #1 */
/* @0x14b150 mov r3, r2 */
/* @0x14b154 ldr r1, [r4, r1] */
/* @0x14b158 add r0, pc, r0 */
/* @0x14b15c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b160 ldr r1, [pc, #-0x2fc] */
/* @0x14b164 ldr r0, [pc, #-0x2fc] */
/* @0x14b168 mov r2, #1 */
/* @0x14b16c mov r3, r2 */
/* @0x14b170 ldr r1, [r4, r1] */
/* @0x14b174 add r0, pc, r0 */
/* @0x14b178 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b17c ldr r1, [pc, #-0x310] */
/* @0x14b180 ldr r0, [pc, #-0x310] */
/* @0x14b184 mov r2, #1 */
/* @0x14b188 mov r3, r2 */
/* @0x14b18c ldr r1, [r4, r1] */
/* @0x14b190 add r0, pc, r0 */
/* @0x14b194 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b198 ldr r1, [pc, #-0x324] */
/* @0x14b19c ldr r0, [pc, #-0x324] */
/* @0x14b1a0 mov r2, #4 */
/* @0x14b1a4 mov r3, #1 */
/* @0x14b1a8 ldr r1, [r4, r1] */
/* @0x14b1ac add r0, pc, r0 */
/* @0x14b1b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b1b4 ldr r1, [pc, #-0x338] */
/* @0x14b1b8 ldr r0, [pc, #-0x338] */
/* @0x14b1bc mov r2, #1 */
/* @0x14b1c0 mov r3, r2 */
/* @0x14b1c4 ldr r1, [r4, r1] */
/* @0x14b1c8 add r0, pc, r0 */
/* @0x14b1cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b1d0 ldr r1, [pc, #-0x34c] */
/* @0x14b1d4 ldr r0, [pc, #-0x34c] */
/* @0x14b1d8 mov r2, #1 */
/* @0x14b1dc mov r3, r2 */
/* @0x14b1e0 ldr r1, [r4, r1] */
/* @0x14b1e4 add r0, pc, r0 */
/* @0x14b1e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b1ec ldr r1, [pc, #-0x360] */
/* @0x14b1f0 ldr r0, [pc, #-0x360] */
/* @0x14b1f4 mov r2, #1 */
/* @0x14b1f8 mov r3, r2 */
/* @0x14b1fc ldr r1, [r4, r1] */
/* @0x14b200 add r0, pc, r0 */
/* @0x14b204 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b208 ldr r1, [pc, #-0x374] */
/* @0x14b20c ldr r0, [pc, #-0x374] */
/* @0x14b210 mov r2, #2 */
/* @0x14b214 mov r3, #1 */
/* @0x14b218 ldr r1, [r4, r1] */
/* @0x14b21c add r0, pc, r0 */
/* @0x14b220 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b224 ldr r1, [pc, #-0x388] */
/* @0x14b228 ldr r0, [pc, #-0x388] */
/* @0x14b22c mov r2, r5 */
/* @0x14b230 mov r3, #1 */
/* @0x14b234 ldr r1, [r4, r1] */
/* @0x14b238 add r0, pc, r0 */
/* @0x14b23c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b240 ldr r1, [pc, #-0x39c] */
/* @0x14b244 ldr r0, [pc, #-0x39c] */
/* @0x14b248 mov r2, #3 */
/* @0x14b24c mov r3, #1 */
/* @0x14b250 ldr r1, [r4, r1] */
/* @0x14b254 add r0, pc, r0 */
/* @0x14b258 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b25c ldr r1, [pc, #-0x3b0] */
/* @0x14b260 ldr r0, [pc, #-0x3b0] */
/* @0x14b264 mov r2, #5 */
/* @0x14b268 mov r3, #1 */
/* @0x14b26c ldr r7, [r4, r1] */
/* @0x14b270 add r0, pc, r0 */
/* @0x14b274 mov r1, r7 */
/* @0x14b278 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b27c ldr r0, [pc, #-0x3c8] */
/* @0x14b280 mov r1, r7 */
/* @0x14b284 mov r2, #5 */
/* @0x14b288 add r0, pc, r0 */
/* @0x14b28c mov r3, #1 */
/* @0x14b290 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b294 ldr r1, [pc, #-0x3dc] */
/* @0x14b298 ldr r0, [pc, #-0x3dc] */
/* @0x14b29c mov r2, #5 */
/* @0x14b2a0 mov r3, #1 */
/* @0x14b2a4 ldr r1, [r4, r1] */
/* @0x14b2a8 add r0, pc, r0 */
/* @0x14b2ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b2b0 ldr r1, [pc, #-0x3f0] */
/* @0x14b2b4 ldr r0, [pc, #-0x3f0] */
/* @0x14b2b8 mov r2, #7 */
/* @0x14b2bc mov r3, #1 */
/* @0x14b2c0 ldr r7, [r4, r1] */
/* @0x14b2c4 add r0, pc, r0 */
/* @0x14b2c8 mov r1, r7 */
/* @0x14b2cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b2d0 ldr r0, [pc, #-0x408] */
/* @0x14b2d4 mov r1, r7 */
/* @0x14b2d8 mov r2, #7 */
/* @0x14b2dc add r0, pc, r0 */
/* @0x14b2e0 mov r3, #1 */
/* @0x14b2e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b2e8 ldr r1, [pc, #-0x41c] */
/* @0x14b2ec ldr r0, [pc, #-0x41c] */
/* @0x14b2f0 mov r2, #6 */
/* @0x14b2f4 mov r3, #1 */
/* @0x14b2f8 ldr r1, [r4, r1] */
/* @0x14b2fc add r0, pc, r0 */
/* @0x14b300 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b304 ldr r1, [pc, #-0x430] */
/* @0x14b308 ldr r0, [pc, #-0x430] */
/* @0x14b30c mov r2, #8 */
/* @0x14b310 mov r3, #1 */
/* @0x14b314 ldr r7, [r4, r1] */
/* @0x14b318 add r0, pc, r0 */
/* @0x14b31c mov r1, r7 */
/* @0x14b320 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b324 ldr r0, [pc, #-0x448] */
/* @0x14b328 mov r1, r7 */
/* @0x14b32c mov r2, #8 */
/* @0x14b330 add r0, pc, r0 */
/* @0x14b334 mov r3, #1 */
/* @0x14b338 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b33c ldr r1, [pc, #-0x45c] */
/* @0x14b340 ldr r0, [pc, #-0x45c] */
/* @0x14b344 mov r2, #8 */
/* @0x14b348 mov r3, #1 */
/* @0x14b34c ldr r1, [r4, r1] */
/* @0x14b350 add r0, pc, r0 */
/* @0x14b354 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b358 ldr r1, [pc, #-0x470] */
/* @0x14b35c ldr r0, [pc, #-0x470] */
/* @0x14b360 mov r2, #10 */
/* @0x14b364 mov r3, #1 */
/* @0x14b368 ldr r7, [r4, r1] */
/* @0x14b36c add r0, pc, r0 */
/* @0x14b370 mov r1, r7 */
/* @0x14b374 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b378 ldr r0, [pc, #-0x488] */
/* @0x14b37c mov r1, r7 */
/* @0x14b380 mov r2, #10 */
/* @0x14b384 add r0, pc, r0 */
/* @0x14b388 mov r3, #1 */
/* @0x14b38c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b390 ldr r1, [pc, #-0x49c] */
/* @0x14b394 ldr r0, [pc, #-0x49c] */
/* @0x14b398 mov r2, #9 */
/* @0x14b39c mov r3, #1 */
/* @0x14b3a0 ldr r1, [r4, r1] */
/* @0x14b3a4 add r0, pc, r0 */
/* @0x14b3a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b3ac ldr r1, [pc, #-0x4b0] */
/* @0x14b3b0 ldr r0, [pc, #-0x4b0] */
/* @0x14b3b4 mov r2, #11 */
/* @0x14b3b8 mov r3, #1 */
/* @0x14b3bc ldr r1, [r4, r1] */
/* @0x14b3c0 add r0, pc, r0 */
/* @0x14b3c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b3c8 ldr r1, [pc, #-0x4c4] */
/* @0x14b3cc ldr r0, [pc, #-0x4c4] */
/* @0x14b3d0 mov r2, #11 */
/* @0x14b3d4 mov r3, #1 */
/* @0x14b3d8 ldr r1, [r4, r1] */
/* @0x14b3dc add r0, pc, r0 */
/* @0x14b3e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b3e4 ldr r1, [pc, #-0x4d8] */
/* @0x14b3e8 ldr r0, [pc, #-0x4d8] */
/* @0x14b3ec mov r2, #10 */
/* @0x14b3f0 mov r3, #1 */
/* @0x14b3f4 ldr r1, [r4, r1] */
/* @0x14b3f8 add r0, pc, r0 */
/* @0x14b3fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b400 ldr r1, [pc, #-0x4ec] */
/* @0x14b404 ldr r0, [pc, #-0x4ec] */
/* @0x14b408 mov r2, #9 */
/* @0x14b40c mov r3, #1 */
/* @0x14b410 ldr r1, [r4, r1] */
/* @0x14b414 add r0, pc, r0 */
/* @0x14b418 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b41c ldr r1, [pc, #-0x500] */
/* @0x14b420 ldr r0, [pc, #-0x500] */
/* @0x14b424 mov r2, #9 */
/* @0x14b428 mov r3, #1 */
/* @0x14b42c ldr r1, [r4, r1] */
/* @0x14b430 add r0, pc, r0 */
/* @0x14b434 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b438 ldr r1, [pc, #-0x514] */
/* @0x14b43c ldr r0, [pc, #-0x514] */
/* @0x14b440 mov r2, #9 */
/* @0x14b444 mov r3, #1 */
/* @0x14b448 ldr r1, [r4, r1] */
/* @0x14b44c add r0, pc, r0 */
/* @0x14b450 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b454 ldr r1, [pc, #-0x528] */
/* @0x14b458 ldr r0, [pc, #-0x528] */
/* @0x14b45c mov r2, #13 */
/* @0x14b460 mov r3, #1 */
/* @0x14b464 ldr r1, [r4, r1] */
/* @0x14b468 add r0, pc, r0 */
/* @0x14b46c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b470 ldr r1, [pc, #-0x53c] */
/* @0x14b474 ldr r0, [pc, #-0x53c] */
/* @0x14b478 mov r2, #5 */
/* @0x14b47c mov r3, #1 */
/* @0x14b480 ldr r1, [r4, r1] */
/* @0x14b484 add r0, pc, r0 */
/* @0x14b488 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b48c ldr r1, [pc, #-0x550] */
/* @0x14b490 ldr r0, [pc, #-0x550] */
/* @0x14b494 mov r2, #5 */
/* @0x14b498 mov r3, #1 */
/* @0x14b49c ldr r1, [r4, r1] */
/* @0x14b4a0 add r0, pc, r0 */
/* @0x14b4a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b4a8 ldr r1, [pc, #-0x564] */
/* @0x14b4ac ldr r0, [pc, #-0x564] */
/* @0x14b4b0 mov r2, r5 */
/* @0x14b4b4 mov r3, #1 */
/* @0x14b4b8 ldr r1, [r4, r1] */
/* @0x14b4bc add r0, pc, r0 */
/* @0x14b4c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b4c4 ldr r1, [pc, #-0x578] */
/* @0x14b4c8 ldr r0, [pc, #-0x578] */
/* @0x14b4cc mov r2, #3 */
/* @0x14b4d0 mov r3, #1 */
/* @0x14b4d4 ldr r1, [r4, r1] */
/* @0x14b4d8 add r0, pc, r0 */
/* @0x14b4dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b4e0 ldr r1, [pc, #-0x58c] */
/* @0x14b4e4 ldr r0, [pc, #-0x58c] */
/* @0x14b4e8 mov r2, #3 */
/* @0x14b4ec mov r3, #1 */
/* @0x14b4f0 ldr r1, [r4, r1] */
/* @0x14b4f4 add r0, pc, r0 */
/* @0x14b4f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b4fc ldr r1, [pc, #-0x5a0] */
/* @0x14b500 ldr r0, [pc, #-0x5a0] */
/* @0x14b504 mov r2, #1 */
/* @0x14b508 mov r3, r2 */
/* @0x14b50c ldr r1, [r4, r1] */
/* @0x14b510 add r0, pc, r0 */
/* @0x14b514 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b518 ldr r1, [pc, #-0x5b4] */
/* @0x14b51c ldr r0, [pc, #-0x5b4] */
/* @0x14b520 mov r2, #1 */
/* @0x14b524 mov r3, r2 */
/* @0x14b528 ldr r1, [r4, r1] */
/* @0x14b52c add r0, pc, r0 */
/* @0x14b530 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b534 ldr r1, [pc, #-0x5c8] */
/* @0x14b538 ldr r0, [pc, #-0x5c8] */
/* @0x14b53c mov r2, #1 */
/* @0x14b540 mov r3, r2 */
/* @0x14b544 ldr r1, [r4, r1] */
/* @0x14b548 add r0, pc, r0 */
/* @0x14b54c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b550 ldr r1, [pc, #-0x5dc] */
/* @0x14b554 ldr r0, [pc, #-0x5dc] */
/* @0x14b558 mov r2, #4 */
/* @0x14b55c mov r3, #1 */
/* @0x14b560 ldr r1, [r4, r1] */
/* @0x14b564 add r0, pc, r0 */
/* @0x14b568 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b56c ldr r1, [pc, #-0x5f0] */
/* @0x14b570 ldr r0, [pc, #-0x5f0] */
/* @0x14b574 mov r2, #3 */
/* @0x14b578 mov r3, #1 */
/* @0x14b57c ldr r1, [r4, r1] */
/* @0x14b580 add r0, pc, r0 */
/* @0x14b584 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b588 ldr r1, [pc, #-0x604] */
/* @0x14b58c ldr r0, [pc, #-0x604] */
/* @0x14b590 mov r2, #3 */
/* @0x14b594 mov r3, #1 */
/* @0x14b598 ldr r1, [r4, r1] */
/* @0x14b59c add r0, pc, r0 */
/* @0x14b5a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b5a4 ldr r1, [pc, #-0x618] */
/* @0x14b5a8 ldr r0, [pc, #-0x618] */
/* @0x14b5ac mov r2, #1 */
/* @0x14b5b0 mov r3, r2 */
/* @0x14b5b4 ldr r1, [r4, r1] */
/* @0x14b5b8 add r0, pc, r0 */
/* @0x14b5bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b5c0 ldr r1, [pc, #-0x62c] */
/* @0x14b5c4 ldr r0, [pc, #-0x62c] */
/* @0x14b5c8 mov r2, #1 */
/* @0x14b5cc mov r3, r2 */
/* @0x14b5d0 ldr r1, [r4, r1] */
/* @0x14b5d4 add r0, pc, r0 */
/* @0x14b5d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b5dc ldr r1, [pc, #-0x640] */
/* @0x14b5e0 ldr r0, [pc, #-0x640] */
/* @0x14b5e4 mov r2, #1 */
/* @0x14b5e8 mov r3, r2 */
/* @0x14b5ec ldr r1, [r4, r1] */
/* @0x14b5f0 add r0, pc, r0 */
/* @0x14b5f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b5f8 ldr r1, [pc, #-0x654] */
/* @0x14b5fc ldr r0, [pc, #-0x654] */
/* @0x14b600 mov r2, #4 */
/* @0x14b604 mov r3, #1 */
/* @0x14b608 ldr r1, [r4, r1] */
/* @0x14b60c add r0, pc, r0 */
/* @0x14b610 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b614 ldr r1, [pc, #-0x668] */
/* @0x14b618 ldr r0, [pc, #-0x668] */
/* @0x14b61c mov r2, r5 */
/* @0x14b620 mov r3, #1 */
/* @0x14b624 ldr r1, [r4, r1] */
/* @0x14b628 add r0, pc, r0 */
/* @0x14b62c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b630 ldr r1, [pc, #-0x67c] */
/* @0x14b634 ldr r0, [pc, #-0x67c] */
/* @0x14b638 mov r2, r5 */
/* @0x14b63c mov r3, #1 */
/* @0x14b640 ldr r1, [r4, r1] */
/* @0x14b644 add r0, pc, r0 */
/* @0x14b648 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b64c ldr r1, [pc, #-0x690] */
/* @0x14b650 ldr r0, [pc, #-0x690] */
/* @0x14b654 mov r2, r5 */
/* @0x14b658 mov r3, #1 */
/* @0x14b65c ldr r1, [r4, r1] */
/* @0x14b660 add r0, pc, r0 */
/* @0x14b664 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b668 ldr r1, [pc, #-0x6a4] */
/* @0x14b66c ldr r0, [pc, #-0x6a4] */
/* @0x14b670 mov r2, r5 */
/* @0x14b674 mov r3, #1 */
/* @0x14b678 ldr r1, [r4, r1] */
/* @0x14b67c add r0, pc, r0 */
/* @0x14b680 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b684 ldr r1, [pc, #-0x6b8] */
/* @0x14b688 ldr r0, [pc, #-0x6b8] */
/* @0x14b68c mov r2, r5 */
/* @0x14b690 mov r3, #1 */
/* @0x14b694 ldr r1, [r4, r1] */
/* @0x14b698 add r0, pc, r0 */
/* @0x14b69c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b6a0 ldr r1, [pc, #-0x6cc] */
/* @0x14b6a4 ldr r0, [pc, #-0x6cc] */
/* @0x14b6a8 mov r2, r5 */
/* @0x14b6ac mov r3, #1 */
/* @0x14b6b0 ldr r1, [r4, r1] */
/* @0x14b6b4 add r0, pc, r0 */
/* @0x14b6b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b6bc ldr r1, [pc, #-0x6e0] */
/* @0x14b6c0 ldr r0, [pc, #-0x6e0] */
/* @0x14b6c4 mov r2, #3 */
/* @0x14b6c8 mov r3, #1 */
/* @0x14b6cc ldr r1, [r4, r1] */
/* @0x14b6d0 add r0, pc, r0 */
/* @0x14b6d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b6d8 ldr r1, [pc, #-0x6f4] */
/* @0x14b6dc ldr r0, [pc, #-0x6f4] */
/* @0x14b6e0 mov r2, r5 */
/* @0x14b6e4 mov r3, #1 */
/* @0x14b6e8 ldr r1, [r4, r1] */
/* @0x14b6ec add r0, pc, r0 */
/* @0x14b6f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b6f4 ldr r1, [pc, #-0x708] */
/* @0x14b6f8 ldr r0, [pc, #-0x708] */
/* @0x14b6fc mov r2, #1 */
/* @0x14b700 mov r3, r2 */
/* @0x14b704 ldr r1, [r4, r1] */
/* @0x14b708 add r0, pc, r0 */
/* @0x14b70c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b710 ldr r1, [pc, #-0x71c] */
/* @0x14b714 ldr r0, [pc, #-0x71c] */
/* @0x14b718 mov r2, #1 */
/* @0x14b71c mov r3, r2 */
/* @0x14b720 ldr r1, [r4, r1] */
/* @0x14b724 add r0, pc, r0 */
/* @0x14b728 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b72c ldr r1, [pc, #-0x730] */
/* @0x14b730 ldr r0, [pc, #-0x730] */
/* @0x14b734 mov r2, #2 */
/* @0x14b738 mov r3, #1 */
/* @0x14b73c ldr r1, [r4, r1] */
/* @0x14b740 add r0, pc, r0 */
/* @0x14b744 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b748 ldr r1, [pc, #-0x744] */
/* @0x14b74c ldr r0, [pc, #-0x744] */
/* @0x14b750 mov r2, #2 */
/* @0x14b754 mov r3, #1 */
/* @0x14b758 ldr r1, [r4, r1] */
/* @0x14b75c add r0, pc, r0 */
/* @0x14b760 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b764 ldr r1, [pc, #-0x758] */
/* @0x14b768 ldr r0, [pc, #-0x758] */
/* @0x14b76c mov r2, #2 */
/* @0x14b770 mov r3, #1 */
/* @0x14b774 ldr r1, [r4, r1] */
/* @0x14b778 add r0, pc, r0 */
/* @0x14b77c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b780 ldr r1, [pc, #-0x76c] */
/* @0x14b784 ldr r0, [pc, #-0x76c] */
/* @0x14b788 mov r2, #2 */
/* @0x14b78c mov r3, #1 */
/* @0x14b790 ldr r1, [r4, r1] */
/* @0x14b794 add r0, pc, r0 */
/* @0x14b798 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b79c ldr r1, [pc, #-0x780] */
/* @0x14b7a0 ldr r0, [pc, #-0x780] */
/* @0x14b7a4 mov r2, #5 */
/* @0x14b7a8 mov r3, #1 */
/* @0x14b7ac ldr r1, [r4, r1] */
/* @0x14b7b0 add r0, pc, r0 */
/* @0x14b7b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b7b8 ldr r1, [pc, #-0x794] */
/* @0x14b7bc ldr r0, [pc, #-0x794] */
/* @0x14b7c0 mov r2, #2 */
/* @0x14b7c4 mov r3, #1 */
/* @0x14b7c8 ldr r1, [r4, r1] */
/* @0x14b7cc add r0, pc, r0 */
/* @0x14b7d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b7d4 ldr r1, [pc, #-0x7a8] */
/* @0x14b7d8 ldr r0, [pc, #-0x7a8] */
/* @0x14b7dc mov r2, #1 */
/* @0x14b7e0 mov r3, r2 */
/* @0x14b7e4 ldr r1, [r4, r1] */
/* @0x14b7e8 add r0, pc, r0 */
/* @0x14b7ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b7f0 ldr r1, [pc, #-0x7bc] */
/* @0x14b7f4 ldr r0, [pc, #-0x7bc] */
/* @0x14b7f8 mov r2, #4 */
/* @0x14b7fc mov r3, #1 */
/* @0x14b800 ldr r1, [r4, r1] */
/* @0x14b804 add r0, pc, r0 */
/* @0x14b808 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b80c ldr r1, [pc, #-0x7d0] */
/* @0x14b810 ldr r0, [pc, #-0x7d0] */
/* @0x14b814 mov r2, #6 */
/* @0x14b818 mov r3, #1 */
/* @0x14b81c ldr r7, [r4, r1] */
/* @0x14b820 add r0, pc, r0 */
/* @0x14b824 mov r1, r7 */
/* @0x14b828 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b82c ldr r0, [pc, #-0x7e8] */
/* @0x14b830 mov r1, r7 */
/* @0x14b834 mov r2, #6 */
/* @0x14b838 add r0, pc, r0 */
/* @0x14b83c mov r3, #1 */
/* @0x14b840 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b844 ldr r1, [pc, #-0x7fc] */
/* @0x14b848 ldr r0, [pc, #-0x7fc] */
/* @0x14b84c mov r2, #6 */
/* @0x14b850 mov r3, #1 */
/* @0x14b854 ldr r1, [r4, r1] */
/* @0x14b858 add r0, pc, r0 */
/* @0x14b85c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b860 ldr r1, [pc, #-0x810] */
/* @0x14b864 ldr r0, [pc, #-0x810] */
/* @0x14b868 mov r2, #8 */
/* @0x14b86c mov r3, #1 */
/* @0x14b870 ldr r7, [r4, r1] */
/* @0x14b874 add r0, pc, r0 */
/* @0x14b878 mov r1, r7 */
/* @0x14b87c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b880 ldr r0, [pc, #-0x828] */
/* @0x14b884 mov r1, r7 */
/* @0x14b888 mov r2, #8 */
/* @0x14b88c add r0, pc, r0 */
/* @0x14b890 mov r3, #1 */
/* @0x14b894 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b898 ldr r1, [pc, #-0x83c] */
/* @0x14b89c ldr r0, [pc, #-0x83c] */
/* @0x14b8a0 mov r2, #7 */
/* @0x14b8a4 mov r3, #1 */
/* @0x14b8a8 ldr r1, [r4, r1] */
/* @0x14b8ac add r0, pc, r0 */
/* @0x14b8b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b8b4 ldr r1, [pc, #-0x850] */
/* @0x14b8b8 ldr r0, [pc, #-0x850] */
/* @0x14b8bc mov r2, #9 */
/* @0x14b8c0 mov r3, #1 */
/* @0x14b8c4 ldr r7, [r4, r1] */
/* @0x14b8c8 add r0, pc, r0 */
/* @0x14b8cc mov r1, r7 */
/* @0x14b8d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b8d4 ldr r0, [pc, #-0x868] */
/* @0x14b8d8 mov r1, r7 */
/* @0x14b8dc mov r2, #9 */
/* @0x14b8e0 add r0, pc, r0 */
/* @0x14b8e4 mov r3, #1 */
/* @0x14b8e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b8ec ldr r1, [pc, #-0x87c] */
/* @0x14b8f0 ldr r0, [pc, #-0x87c] */
/* @0x14b8f4 mov r2, #9 */
/* @0x14b8f8 mov r3, #1 */
/* @0x14b8fc ldr r1, [r4, r1] */
/* @0x14b900 add r0, pc, r0 */
/* @0x14b904 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b908 ldr r1, [pc, #-0x890] */
/* @0x14b90c ldr r0, [pc, #-0x890] */
/* @0x14b910 mov r2, #11 */
/* @0x14b914 mov r3, #1 */
/* @0x14b918 ldr r7, [r4, r1] */
/* @0x14b91c add r0, pc, r0 */
/* @0x14b920 mov r1, r7 */
/* @0x14b924 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b928 ldr r0, [pc, #-0x8a8] */
/* @0x14b92c mov r1, r7 */
/* @0x14b930 mov r2, #11 */
/* @0x14b934 add r0, pc, r0 */
/* @0x14b938 mov r3, #1 */
/* @0x14b93c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b940 ldr r1, [pc, #-0x8bc] */
/* @0x14b944 ldr r0, [pc, #-0x8bc] */
/* @0x14b948 mov r2, #9 */
/* @0x14b94c mov r3, #1 */
/* @0x14b950 ldr r1, [r4, r1] */
/* @0x14b954 add r0, pc, r0 */
/* @0x14b958 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b95c ldr r1, [pc, #-0x8d0] */
/* @0x14b960 ldr r0, [pc, #-0x8d0] */
/* @0x14b964 mov r2, #11 */
/* @0x14b968 mov r3, #1 */
/* @0x14b96c ldr r1, [r4, r1] */
/* @0x14b970 add r0, pc, r0 */
/* @0x14b974 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b978 ldr r1, [pc, #-0x8e4] */
/* @0x14b97c ldr r0, [pc, #-0x8e4] */
/* @0x14b980 mov r2, #11 */
/* @0x14b984 mov r3, #1 */
/* @0x14b988 ldr r1, [r4, r1] */
/* @0x14b98c add r0, pc, r0 */
/* @0x14b990 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b994 ldr r1, [pc, #-0x8f8] */
/* @0x14b998 ldr r0, [pc, #-0x8f8] */
/* @0x14b99c mov r2, #10 */
/* @0x14b9a0 mov r3, #1 */
/* @0x14b9a4 ldr r1, [r4, r1] */
/* @0x14b9a8 add r0, pc, r0 */
/* @0x14b9ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b9b0 ldr r1, [pc, #-0x90c] */
/* @0x14b9b4 ldr r0, [pc, #-0x90c] */
/* @0x14b9b8 mov r2, #9 */
/* @0x14b9bc mov r3, #1 */
/* @0x14b9c0 ldr r1, [r4, r1] */
/* @0x14b9c4 add r0, pc, r0 */
/* @0x14b9c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b9cc ldr r1, [pc, #-0x920] */
/* @0x14b9d0 ldr r0, [pc, #-0x920] */
/* @0x14b9d4 mov r2, #9 */
/* @0x14b9d8 mov r3, #1 */
/* @0x14b9dc ldr r1, [r4, r1] */
/* @0x14b9e0 add r0, pc, r0 */
/* @0x14b9e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14b9e8 ldr r1, [pc, #-0x934] */
/* @0x14b9ec ldr r0, [pc, #-0x934] */
/* @0x14b9f0 mov r2, #1 */
/* @0x14b9f4 mov r3, r2 */
/* @0x14b9f8 ldr r1, [r4, r1] */
/* @0x14b9fc add r0, pc, r0 */
/* @0x14ba00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14ba04 ldr r1, [pc, #-0x948] */
/* @0x14ba08 ldr r0, [pc, #-0x948] */
/* @0x14ba0c mov r2, #5 */
/* @0x14ba10 mov r3, #1 */
/* @0x14ba14 ldr r1, [r4, r1] */
/* @0x14ba18 add r0, pc, r0 */
/* @0x14ba1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14ba20 ldr r1, [pc, #-0x95c] */
/* @0x14ba24 ldr r0, [pc, #-0x95c] */
/* @0x14ba28 mov r2, #6 */
/* @0x14ba2c mov r3, #1 */
/* @0x14ba30 ldr r1, [r4, r1] */
/* @0x14ba34 add r0, pc, r0 */
/* @0x14ba38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14ba3c ldr r1, [pc, #-0x970] */
/* @0x14ba40 ldr r0, [pc, #-0x970] */
/* @0x14ba44 mov r2, #2 */
/* @0x14ba48 mov r3, #1 */
/* @0x14ba4c ldr r1, [r4, r1] */
/* @0x14ba50 add r0, pc, r0 */
/* @0x14ba54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14ba58 ldr r1, [pc, #-0x984] */
/* @0x14ba5c ldr r0, [pc, #-0x984] */
/* @0x14ba60 mov r2, #1 */
/* @0x14ba64 mov r3, r2 */
/* @0x14ba68 ldr r1, [r4, r1] */
/* @0x14ba6c add r0, pc, r0 */
/* @0x14ba70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14ba74 ldr r1, [pc, #-0x998] */
/* @0x14ba78 ldr r0, [pc, #-0x998] */
/* @0x14ba7c mov r3, r5 */
/* @0x14ba80 mov r2, #1 */
/* @0x14ba84 ldr r7, [r4, r1] */
/* @0x14ba88 add r0, pc, r0 */
/* @0x14ba8c mov r1, r7 */
/* @0x14ba90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14ba94 ldr r0, [pc, #-0x9b0] */
/* @0x14ba98 mov r1, r7 */
/* @0x14ba9c mov r3, r5 */
/* @0x14baa0 add r0, pc, r0 */
/* @0x14baa4 mov r2, #1 */
/* @0x14baa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14baac b 0x149f6c <_Z15Init3DFunctionsv+0x20> */

/* ── FUNC 0x14bab0 · F_PhysicsCreateFixture(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x14bab0 push {r4, lr} */
/* @0x14bab4 mov r4, r0 */
/* @0x14bab8 bl 0x2364d4 <_ZN22CPhysicsFixtureFactory13CreateFixtureEv> */
/* @0x14babc mov r3, #0 */
/* @0x14bac0 str r3, [r4, #0xc] */
/* @0x14bac4 ldr r2, [r0, #0x1c] */
/* @0x14bac8 vmov s15, r2 */
/* @0x14bacc vcvt.f64.u32 d7, s15 */
/* @0x14bad0 vmov r2, r3, d7 */
/* @0x14bad4 stm r4, {r2, r3} */
/* @0x14bad8 pop {r4, pc} */

/* ── FUNC 0x14badc · F_PhysicsDeleteFixture(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x14badc push {r3, lr} */
/* @0x14bae0 mov r1, #0 */
/* @0x14bae4 ldr r0, [sp, #0x8] */
/* @0x14bae8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14baec pop {r3, lr} */
/* @0x14baf0 b 0x236648 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj> */

/* ── FUNC 0x14baf4 · F_PhysicsFixtureSetPolygonShape(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x14baf4 push {r3, lr} */
/* @0x14baf8 mov r1, #0 */
/* @0x14bafc ldr r0, [sp, #0x8] */
/* @0x14bb00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bb04 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14bb08 subs r1, r0, #0 */
/* @0x14bb0c beq 0x14bb18 <_Z31F_PhysicsFixtureSetPolygonShapeR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x14bb10 pop {r3, lr} */
/* @0x14bb14 b 0x2368f8 <_ZN15CPhysicsFixture15SetPolygonShapeEv> */
/* @0x14bb18 ldr r0, [pc, #0x8] */
/* @0x14bb1c pop {r3, lr} */
/* @0x14bb20 add r0, pc, r0 */
/* @0x14bb24 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bb28 andseq r8, pc, r8, lsl #5 */

/* ── FUNC 0x14bb2c · F_PhysicsFixtureSetChainShape(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x14bb2c push {r3, r4, r5, lr} */
/* @0x14bb30 mov r1, #0 */
/* @0x14bb34 ldr r4, [sp, #0x10] */
/* @0x14bb38 mov r0, r4 */
/* @0x14bb3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bb40 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14bb44 subs r5, r0, #0 */
/* @0x14bb48 beq 0x14bb68 <_Z29F_PhysicsFixtureSetChainShapeR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x14bb4c mov r0, r4 */
/* @0x14bb50 mov r1, #1 */
/* @0x14bb54 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14bb58 mov r1, r0 */
/* @0x14bb5c mov r0, r5 */
/* @0x14bb60 pop {r3, r4, r5, lr} */
/* @0x14bb64 b 0x236964 <_ZN15CPhysicsFixture13SetChainShapeEb> */
/* @0x14bb68 ldr r0, [pc, #0xc] */
/* @0x14bb6c mov r1, r5 */
/* @0x14bb70 pop {r3, r4, r5, lr} */
/* @0x14bb74 add r0, pc, r0 */
/* @0x14bb78 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bb7c andseq r8, pc, r4, lsr r2 */

/* ── FUNC 0x14bb80 · F_PhysicsJointEnableMotor(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x14bb80 push {r3, r4, r5, lr} */
/* @0x14bb84 mov r1, #0 */
/* @0x14bb88 ldr r4, [sp, #0x10] */
/* @0x14bb8c mov r0, r4 */
/* @0x14bb90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bb94 bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj> */
/* @0x14bb98 subs r5, r0, #0 */
/* @0x14bb9c beq 0x14bbbc <_Z25F_PhysicsJointEnableMotorR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x14bba0 mov r0, r4 */
/* @0x14bba4 mov r1, #1 */
/* @0x14bba8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14bbac mov r1, r0 */
/* @0x14bbb0 mov r0, r5 */
/* @0x14bbb4 pop {r3, r4, r5, lr} */
/* @0x14bbb8 b 0x23b534 <_ZN13CPhysicsJoint11EnableMotorEb> */
/* @0x14bbbc ldr r0, [pc, #0xc] */
/* @0x14bbc0 mov r1, r5 */
/* @0x14bbc4 pop {r3, r4, r5, lr} */
/* @0x14bbc8 add r0, pc, r0 */
/* @0x14bbcc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bbd0 andseq r8, pc, r4, lsl #4 */

/* ── FUNC 0x14bbd4 · F_PhysicsJointGetValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x14bbd4 push {r4, r5, r6, lr} */
/* @0x14bbd8 mov r1, #0 */
/* @0x14bbdc ldr r5, [sp, #0x10] */
/* @0x14bbe0 mov r4, r0 */
/* @0x14bbe4 str r1, [r0, #0xc] */
/* @0x14bbe8 mov r0, r5 */
/* @0x14bbec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bbf0 bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj> */
/* @0x14bbf4 subs r6, r0, #0 */
/* @0x14bbf8 beq 0x14bc30 <_Z22F_PhysicsJointGetValueR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x14bbfc mov r1, #1 */
/* @0x14bc00 mov r0, r5 */
/* @0x14bc04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bc08 mov r1, r0 */
/* @0x14bc0c mov r0, r6 */
/* @0x14bc10 bl 0x23b610 <_ZN13CPhysicsJoint8GetValueEi> */
/* @0x14bc14 vmov s15, r0 */
/* @0x14bc18 vcvt.f64.f32 d7, s15 */
/* @0x14bc1c vmov r0, r1, d7 */
/* @0x14bc20 vmov r2, s14 */
/* @0x14bc24 mov r3, r1 */
/* @0x14bc28 stm r4, {r2, r3} */
/* @0x14bc2c pop {r4, r5, r6, pc} */
/* @0x14bc30 ldr r0, [pc, #0xc] */
/* @0x14bc34 mov r1, r6 */
/* @0x14bc38 pop {r4, r5, r6, lr} */
/* @0x14bc3c add r0, pc, r0 */
/* @0x14bc40 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bc44 mulseq pc, r0, r1 */

/* ── FUNC 0x14bc48 · F_PhysicsJointSetValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x14bc48 push {r4, r5, r6, lr} */
/* @0x14bc4c mov r1, #0 */
/* @0x14bc50 ldr r4, [sp, #0x10] */
/* @0x14bc54 mov r0, r4 */
/* @0x14bc58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bc5c bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj> */
/* @0x14bc60 subs r5, r0, #0 */
/* @0x14bc64 beq 0x14bc98 <_Z22F_PhysicsJointSetValueR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x14bc68 mov r0, r4 */
/* @0x14bc6c mov r1, #1 */
/* @0x14bc70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bc74 mov r1, #2 */
/* @0x14bc78 mov r6, r0 */
/* @0x14bc7c mov r0, r4 */
/* @0x14bc80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14bc84 mov r1, r6 */
/* @0x14bc88 mov r2, r0 */
/* @0x14bc8c mov r0, r5 */
/* @0x14bc90 pop {r4, r5, r6, lr} */
/* @0x14bc94 b 0x23bb14 <_ZN13CPhysicsJoint8SetValueEif> */
/* @0x14bc98 ldr r0, [pc, #0xc] */
/* @0x14bc9c mov r1, r5 */
/* @0x14bca0 pop {r4, r5, r6, lr} */
/* @0x14bca4 add r0, pc, r0 */
/* @0x14bca8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bcac andseq r8, pc, r8, lsr #2 */

/* ── FUNC 0x14bcb0 · F_PhysicsFixtureSetCollisionGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x14bcb0 push {r3, r4, r5, lr} */
/* @0x14bcb4 mov r1, #0 */
/* @0x14bcb8 ldr r4, [sp, #0x10] */
/* @0x14bcbc mov r0, r4 */
/* @0x14bcc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bcc4 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14bcc8 subs r5, r0, #0 */
/* @0x14bccc beq 0x14bce8 <_Z33F_PhysicsFixtureSetCollisionGroupR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x14bcd0 mov r0, r4 */
/* @0x14bcd4 mov r1, #1 */
/* @0x14bcd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bcdc ldr r3, [r5, #0x20] */
/* @0x14bce0 strh r0, [r3, #32] */
/* @0x14bce4 pop {r3, r4, r5, pc} */
/* @0x14bce8 ldr r0, [pc, #0xc] */
/* @0x14bcec mov r1, r5 */
/* @0x14bcf0 pop {r3, r4, r5, lr} */
/* @0x14bcf4 add r0, pc, r0 */
/* @0x14bcf8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bcfc ldrheq r8, [pc], -r4 */

/* ── FUNC 0x14bd00 · F_PhysicsFixtureSetFriction(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x14bd00 push {r3, r4, r5, lr} */
/* @0x14bd04 mov r1, #0 */
/* @0x14bd08 ldr r4, [sp, #0x10] */
/* @0x14bd0c mov r0, r4 */
/* @0x14bd10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bd14 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14bd18 subs r5, r0, #0 */
/* @0x14bd1c beq 0x14bd38 <_Z27F_PhysicsFixtureSetFrictionR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x14bd20 mov r0, r4 */
/* @0x14bd24 mov r1, #1 */
/* @0x14bd28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14bd2c ldr r3, [r5, #0x20] */
/* @0x14bd30 str r0, [r3, #0x8] */
/* @0x14bd34 pop {r3, r4, r5, pc} */
/* @0x14bd38 ldr r0, [pc, #0xc] */
/* @0x14bd3c mov r1, r5 */
/* @0x14bd40 pop {r3, r4, r5, lr} */
/* @0x14bd44 add r0, pc, r0 */
/* @0x14bd48 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bd4c andseq r8, pc, r4, rrx */

/* ── FUNC 0x14bd50 · F_PhysicsFixtureSetRestitution(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x14bd50 push {r3, r4, r5, lr} */
/* @0x14bd54 mov r1, #0 */
/* @0x14bd58 ldr r4, [sp, #0x10] */
/* @0x14bd5c mov r0, r4 */
/* @0x14bd60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bd64 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14bd68 subs r5, r0, #0 */
/* @0x14bd6c beq 0x14bd88 <_Z30F_PhysicsFixtureSetRestitutionR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x14bd70 mov r0, r4 */
/* @0x14bd74 mov r1, #1 */
/* @0x14bd78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14bd7c ldr r3, [r5, #0x20] */
/* @0x14bd80 str r0, [r3, #0xc] */
/* @0x14bd84 pop {r3, r4, r5, pc} */
/* @0x14bd88 ldr r0, [pc, #0xc] */
/* @0x14bd8c mov r1, r5 */
/* @0x14bd90 pop {r3, r4, r5, lr} */
/* @0x14bd94 add r0, pc, r0 */
/* @0x14bd98 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bd9c andseq r8, pc, r4, lsl r0 */

/* ── FUNC 0x14bda0 · F_PhysicsFixtureSetDensity(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x14bda0 push {r3, r4, r5, lr} */
/* @0x14bda4 mov r1, #0 */
/* @0x14bda8 ldr r4, [sp, #0x10] */
/* @0x14bdac mov r0, r4 */
/* @0x14bdb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bdb4 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14bdb8 subs r5, r0, #0 */
/* @0x14bdbc beq 0x14bdd8 <_Z26F_PhysicsFixtureSetDensityR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x14bdc0 mov r0, r4 */
/* @0x14bdc4 mov r1, #1 */
/* @0x14bdc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14bdcc ldr r3, [r5, #0x20] */
/* @0x14bdd0 str r0, [r3, #0x10] */
/* @0x14bdd4 pop {r3, r4, r5, pc} */
/* @0x14bdd8 ldr r0, [pc, #0xc] */
/* @0x14bddc mov r1, r5 */
/* @0x14bde0 pop {r3, r4, r5, lr} */
/* @0x14bde4 add r0, pc, r0 */
/* @0x14bde8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bdec andseq r7, pc, r4, asr #31 */

/* ── FUNC 0x14bdf0 · F_PhysicsFixtureSetSensor(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x14bdf0 push {r3, r4, r5, lr} */
/* @0x14bdf4 mov r1, #0 */
/* @0x14bdf8 ldr r4, [sp, #0x10] */
/* @0x14bdfc mov r0, r4 */
/* @0x14be00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14be04 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14be08 subs r5, r0, #0 */
/* @0x14be0c beq 0x14be28 <_Z25F_PhysicsFixtureSetSensorR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x14be10 mov r0, r4 */
/* @0x14be14 mov r1, #1 */
/* @0x14be18 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14be1c ldr r3, [r5, #0x20] */
/* @0x14be20 strb r0, [r3, #0x14] */
/* @0x14be24 pop {r3, r4, r5, pc} */
/* @0x14be28 ldr r0, [pc, #0xc] */
/* @0x14be2c mov r1, r5 */
/* @0x14be30 pop {r3, r4, r5, lr} */
/* @0x14be34 add r0, pc, r0 */
/* @0x14be38 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14be3c andseq r7, pc, r4, ror pc */

/* ── FUNC 0x14be40 · F_PhysicsFixtureLinearDamping(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x14be40 push {r3, r4, r5, lr} */
/* @0x14be44 mov r1, #0 */
/* @0x14be48 ldr r4, [sp, #0x10] */
/* @0x14be4c mov r0, r4 */
/* @0x14be50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14be54 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14be58 subs r5, r0, #0 */
/* @0x14be5c beq 0x14be74 <_Z29F_PhysicsFixtureLinearDampingR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x14be60 mov r0, r4 */
/* @0x14be64 mov r1, #1 */
/* @0x14be68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14be6c str r0, [r5] */
/* @0x14be70 pop {r3, r4, r5, pc} */
/* @0x14be74 ldr r0, [pc, #0xc] */
/* @0x14be78 mov r1, r5 */
/* @0x14be7c pop {r3, r4, r5, lr} */
/* @0x14be80 add r0, pc, r0 */
/* @0x14be84 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14be88 andseq r7, pc, r8, lsr #30 */

/* ── FUNC 0x14be8c · F_PhysicsFixtureAngularDamping(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x14be8c push {r3, r4, r5, lr} */
/* @0x14be90 mov r1, #0 */
/* @0x14be94 ldr r4, [sp, #0x10] */
/* @0x14be98 mov r0, r4 */
/* @0x14be9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bea0 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14bea4 subs r5, r0, #0 */
/* @0x14bea8 beq 0x14bec0 <_Z30F_PhysicsFixtureAngularDampingR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x14beac mov r0, r4 */
/* @0x14beb0 mov r1, #1 */
/* @0x14beb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14beb8 str r0, [r5, #0x4] */
/* @0x14bebc pop {r3, r4, r5, pc} */
/* @0x14bec0 ldr r0, [pc, #0xc] */
/* @0x14bec4 mov r1, r5 */
/* @0x14bec8 pop {r3, r4, r5, lr} */
/* @0x14becc add r0, pc, r0 */
/* @0x14bed0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bed4 ldrsbeq r7, [pc], -r12 */

/* ── FUNC 0x14bed8 · F_PhysicsFixtureSetKinematic(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x14bed8 push {r3, lr} */
/* @0x14bedc mov r1, #0 */
/* @0x14bee0 ldr r0, [sp, #0x8] */
/* @0x14bee4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bee8 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14beec cmp r0, #0 */
/* @0x14bef0 movne r3, #1 */
/* @0x14bef4 strbne r3, [r0, #0x18] */
/* @0x14bef8 popne {r3, pc} */
/* @0x14befc mov r1, r0 */
/* @0x14bf00 ldr r0, [pc, #0x8] */
/* @0x14bf04 pop {r3, lr} */
/* @0x14bf08 add r0, pc, r0 */
/* @0x14bf0c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bf10 andseq r7, pc, r0, lsr #29 */

/* ── FUNC 0x14bf14 · F_PhysicsFixtureSetAwake(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x14bf14 push {r3, r4, r5, lr} */
/* @0x14bf18 mov r1, #0 */
/* @0x14bf1c ldr r4, [sp, #0x10] */
/* @0x14bf20 mov r0, r4 */
/* @0x14bf24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bf28 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14bf2c subs r5, r0, #0 */
/* @0x14bf30 beq 0x14bf48 <_Z24F_PhysicsFixtureSetAwakeR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x14bf34 mov r0, r4 */
/* @0x14bf38 mov r1, #1 */
/* @0x14bf3c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14bf40 strb r0, [r5, #0x8] */
/* @0x14bf44 pop {r3, r4, r5, pc} */
/* @0x14bf48 ldr r0, [pc, #0xc] */
/* @0x14bf4c mov r1, r5 */
/* @0x14bf50 pop {r3, r4, r5, lr} */
/* @0x14bf54 add r0, pc, r0 */
/* @0x14bf58 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bf5c andseq r7, pc, r4, asr lr */
