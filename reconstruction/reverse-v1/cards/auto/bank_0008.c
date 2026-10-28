/* libyoyo.so 覆盖卡组 0008
 * 函数 0xc9170..0xcacec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xc9170 · F_Vertex_End_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0xc9170 push {r3, lr} */
/* @0xc9174 mov r1, #0 */
/* @0xc9178 ldr r0, [sp, #0x8] */
/* @0xc917c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc9180 pop {r3, lr} */
/* @0xc9184 b 0xc9108 <_Z16YYGML_vertex_endi> */

/* ── FUNC 0xc9188 · Init_Vertex_Write(RValue&, int, RValue*, int) · size=280 · insn=70 */
/* @0xc9188 cmp r1, r3 */
/* @0xc918c push {r4, r5, lr} */
/* @0xc9190 mov r4, #0 */
/* @0xc9194 sub sp, sp, #12 */
/* @0xc9198 str r4, [r0, #0xc] */
/* @0xc919c str r4, [r0] */
/* @0xc91a0 str r4, [r0, #0x4] */
/* @0xc91a4 bne 0xc91f4 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x6c> */
/* @0xc91a8 mov r0, r2 */
/* @0xc91ac mov r1, r4 */
/* @0xc91b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc91b4 bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc91b8 subs r5, r0, #0 */
/* @0xc91bc beq 0xc9264 <_Z17Init_Vertex_WriteR6RValueiPS_i+0xdc> */
/* @0xc91c0 ldrb r4, [r5, #0x20] */
/* @0xc91c4 cmp r4, #0 */
/* @0xc91c8 bne 0xc9264 <_Z17Init_Vertex_WriteR6RValueiPS_i+0xdc> */
/* @0xc91cc ldr r0, [r5, #0x24] */
/* @0xc91d0 cmn r0, #1 */
/* @0xc91d4 beq 0xc927c <_Z17Init_Vertex_WriteR6RValueiPS_i+0xf4> */
/* @0xc91d8 ldr r4, [r5, #0x18] */
/* @0xc91dc cmp r4, #0 */
/* @0xc91e0 beq 0xc9210 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x88> */
/* @0xc91e4 mov r4, r5 */
/* @0xc91e8 mov r0, r4 */
/* @0xc91ec add sp, sp, #12 */
/* @0xc91f0 pop {r4, r5, pc} */
/* @0xc91f4 ldr r0, [pc, #0x94] */
/* @0xc91f8 mov r1, #1 */
/* @0xc91fc add r0, pc, r0 */
/* @0xc9200 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc9204 mov r0, r4 */
/* @0xc9208 add sp, sp, #12 */
/* @0xc920c pop {r4, r5, pc} */
/* @0xc9210 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc9214 cmp r0, #0 */
/* @0xc9218 beq 0xc91e4 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x5c> */
/* @0xc921c ldr r2, [r0, #0x14] */
/* @0xc9220 ldr r1, [r5, #0xc] */
/* @0xc9224 ldr r3, [r5, #0x4] */
/* @0xc9228 add r1, r2, r1 */
/* @0xc922c cmp r3, r1 */
/* @0xc9230 bhs 0xc91e4 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x5c> */
/* @0xc9234 add r2, r2, r3 */
/* @0xc9238 ldr r0, [r5] */
/* @0xc923c add r1, r2, r3, lsr #1 */
/* @0xc9240 ldr r2, [pc, #0x4c] */
/* @0xc9244 str r1, [r5, #0x4] */
/* @0xc9248 mov r3, #74 */
/* @0xc924c str r4, [sp] */
/* @0xc9250 add r2, pc, r2 */
/* @0xc9254 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc9258 mov r4, r5 */
/* @0xc925c str r0, [r5] */
/* @0xc9260 b 0xc91e8 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x60> */
/* @0xc9264 ldr r0, [pc, #0x2c] */
/* @0xc9268 mov r1, #1 */
/* @0xc926c mov r4, #0 */
/* @0xc9270 add r0, pc, r0 */
/* @0xc9274 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc9278 b 0xc91e8 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x60> */
/* @0xc927c ldr r0, [pc, #0x18] */
/* @0xc9280 mov r1, #1 */
/* @0xc9284 add r0, pc, r0 */
/* @0xc9288 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc928c b 0xc91e8 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x60> */
/* @0xc9290 eoreq r8, r6, r4, ror #22 */
/* @0xc9294 eoreq r7, r6, r0, ror #27 */
/* @0xc9298 eoreq r8, r6, r8, lsl r11 */
/* @0xc929c eoreq r8, r6, r8, lsr r11 */

/* ── FUNC 0xc92a0 · F_Vertex_Position_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0xc92a0 push {r3, r4, r5, lr} */
/* @0xc92a4 mov r1, r3 */
/* @0xc92a8 ldr r4, [sp, #0x10] */
/* @0xc92ac mov r3, #3 */
/* @0xc92b0 mov r2, r4 */
/* @0xc92b4 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc92b8 cmp r0, #0 */
/* @0xc92bc popeq {r3, r4, r5, pc} */
/* @0xc92c0 mov r1, #1 */
/* @0xc92c4 mov r2, #2 */
/* @0xc92c8 bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType> */
/* @0xc92cc subs r5, r0, #0 */
/* @0xc92d0 popeq {r3, r4, r5, pc} */
/* @0xc92d4 mov r1, #1 */
/* @0xc92d8 mov r0, r4 */
/* @0xc92dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc92e0 mov r1, #2 */
/* @0xc92e4 str r0, [r5] */
/* @0xc92e8 mov r0, r4 */
/* @0xc92ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc92f0 str r0, [r5, #0x4] */
/* @0xc92f4 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc92f8 · F_Vertex_Position_3d_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0xc92f8 push {r3, r4, r5, lr} */
/* @0xc92fc mov r1, r3 */
/* @0xc9300 ldr r4, [sp, #0x10] */
/* @0xc9304 mov r3, #4 */
/* @0xc9308 mov r2, r4 */
/* @0xc930c bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc9310 cmp r0, #0 */
/* @0xc9314 popeq {r3, r4, r5, pc} */
/* @0xc9318 mov r1, #1 */
/* @0xc931c mov r2, #3 */
/* @0xc9320 bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType> */
/* @0xc9324 subs r5, r0, #0 */
/* @0xc9328 popeq {r3, r4, r5, pc} */
/* @0xc932c mov r1, #1 */
/* @0xc9330 mov r0, r4 */
/* @0xc9334 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc9338 mov r1, #2 */
/* @0xc933c str r0, [r5] */
/* @0xc9340 mov r0, r4 */
/* @0xc9344 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc9348 mov r1, #3 */
/* @0xc934c str r0, [r5, #0x4] */
/* @0xc9350 mov r0, r4 */
/* @0xc9354 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc9358 str r0, [r5, #0x8] */
/* @0xc935c pop {r3, r4, r5, pc} */

/* ── FUNC 0xc9360 · F_Vertex_Colour_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0xc9360 push {r4, r5, r6, lr} */
/* @0xc9364 mov r1, r3 */
/* @0xc9368 ldr r4, [sp, #0x10] */
/* @0xc936c mov r3, #3 */
/* @0xc9370 mov r2, r4 */
/* @0xc9374 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc9378 cmp r0, #0 */
/* @0xc937c popeq {r4, r5, r6, pc} */
/* @0xc9380 mov r1, #2 */
/* @0xc9384 mov r2, #5 */
/* @0xc9388 bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType> */
/* @0xc938c subs r5, r0, #0 */
/* @0xc9390 popeq {r4, r5, r6, pc} */
/* @0xc9394 mov r1, #1 */
/* @0xc9398 mov r0, r4 */
/* @0xc939c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc93a0 mov r1, #2 */
/* @0xc93a4 mov r6, r0 */
/* @0xc93a8 mov r0, r4 */
/* @0xc93ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc93b0 vldr s15, [pc, #56] */
/* @0xc93b4 vmov s14, r0 */
/* @0xc93b8 vmul.f32 s15, s14, s15 */
/* @0xc93bc vcvt.s32.f32 s15, s15 */
/* @0xc93c0 vmov r3, s15 */
/* @0xc93c4 cmp r3, #255 */
/* @0xc93c8 movgt r3, #-16777216 */
/* @0xc93cc ble 0xc93e0 <_Z21F_Vertex_Colour_debugR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc93d0 bic r6, r6, #-16777216 */
/* @0xc93d4 orr r6, r3, r6 */
/* @0xc93d8 str r6, [r5] */
/* @0xc93dc pop {r4, r5, r6, pc} */
/* @0xc93e0 cmp r3, #0 */
/* @0xc93e4 lslge r3, r3, #24 */
/* @0xc93e8 movlt r3, #0 */
/* @0xc93ec b 0xc93d0 <_Z21F_Vertex_Colour_debugR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xc93f0 cmnmi pc, #0 */

/* ── FUNC 0xc93f4 · F_Vertex_ARGB_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0xc93f4 push {r3, r4, r5, lr} */
/* @0xc93f8 mov r1, r3 */
/* @0xc93fc ldr r4, [sp, #0x10] */
/* @0xc9400 mov r3, #2 */
/* @0xc9404 mov r2, r4 */
/* @0xc9408 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc940c cmp r0, #0 */
/* @0xc9410 popeq {r3, r4, r5, pc} */
/* @0xc9414 mov r1, #2 */
/* @0xc9418 mov r2, #5 */
/* @0xc941c bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType> */
/* @0xc9420 subs r5, r0, #0 */
/* @0xc9424 popeq {r3, r4, r5, pc} */
/* @0xc9428 mov r0, r4 */
/* @0xc942c mov r1, #1 */
/* @0xc9430 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc9434 bic r3, r0, #16711680 */
/* @0xc9438 ubfx r2, r0, #0x10, #0x8 */
/* @0xc943c bic r3, r3, #255 */
/* @0xc9440 uxtb r0, r0 */
/* @0xc9444 orr r3, r3, r2 */
/* @0xc9448 orr r3, r3, r0, lsl #16 */
/* @0xc944c str r3, [r5] */
/* @0xc9450 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc9454 · F_Vertex_TexCoord_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0xc9454 push {r3, r4, r5, lr} */
/* @0xc9458 mov r1, r3 */
/* @0xc945c ldr r4, [sp, #0x10] */
/* @0xc9460 mov r3, #3 */
/* @0xc9464 mov r2, r4 */
/* @0xc9468 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc946c cmp r0, #0 */
/* @0xc9470 popeq {r3, r4, r5, pc} */
/* @0xc9474 mov r1, #4 */
/* @0xc9478 mov r2, #2 */
/* @0xc947c bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType> */
/* @0xc9480 subs r5, r0, #0 */
/* @0xc9484 popeq {r3, r4, r5, pc} */
/* @0xc9488 mov r1, #1 */
/* @0xc948c mov r0, r4 */
/* @0xc9490 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc9494 mov r1, #2 */
/* @0xc9498 str r0, [r5] */
/* @0xc949c mov r0, r4 */
/* @0xc94a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc94a4 str r0, [r5, #0x4] */
/* @0xc94a8 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc94ac · F_Vertex_Normal_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0xc94ac push {r3, r4, r5, lr} */
/* @0xc94b0 mov r1, r3 */
/* @0xc94b4 ldr r4, [sp, #0x10] */
/* @0xc94b8 mov r3, #4 */
/* @0xc94bc mov r2, r4 */
/* @0xc94c0 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc94c4 cmp r0, #0 */
/* @0xc94c8 popeq {r3, r4, r5, pc} */
/* @0xc94cc mov r1, #3 */
/* @0xc94d0 mov r2, r1 */
/* @0xc94d4 bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType> */
/* @0xc94d8 subs r5, r0, #0 */
/* @0xc94dc popeq {r3, r4, r5, pc} */
/* @0xc94e0 mov r1, #1 */
/* @0xc94e4 mov r0, r4 */
/* @0xc94e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc94ec mov r1, #2 */
/* @0xc94f0 str r0, [r5] */
/* @0xc94f4 mov r0, r4 */
/* @0xc94f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc94fc mov r1, #3 */
/* @0xc9500 str r0, [r5, #0x4] */
/* @0xc9504 mov r0, r4 */
/* @0xc9508 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc950c str r0, [r5, #0x8] */
/* @0xc9510 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc9514 · F_Vertex_Float1_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0xc9514 push {r3, r4, r5, lr} */
/* @0xc9518 mov r1, r3 */
/* @0xc951c ldr r4, [sp, #0x10] */
/* @0xc9520 mov r3, #2 */
/* @0xc9524 mov r2, r4 */
/* @0xc9528 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc952c cmp r0, #0 */
/* @0xc9530 popeq {r3, r4, r5, pc} */
/* @0xc9534 mov r1, #1 */
/* @0xc9538 bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType> */
/* @0xc953c subs r5, r0, #0 */
/* @0xc9540 popeq {r3, r4, r5, pc} */
/* @0xc9544 mov r0, r4 */
/* @0xc9548 mov r1, #1 */
/* @0xc954c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc9550 str r0, [r5] */
/* @0xc9554 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc9558 · F_Vertex_Float2_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0xc9558 push {r3, r4, r5, lr} */
/* @0xc955c mov r1, r3 */
/* @0xc9560 ldr r4, [sp, #0x10] */
/* @0xc9564 mov r3, #3 */
/* @0xc9568 mov r2, r4 */
/* @0xc956c bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc9570 cmp r0, #0 */
/* @0xc9574 popeq {r3, r4, r5, pc} */
/* @0xc9578 mov r1, #2 */
/* @0xc957c bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType> */
/* @0xc9580 subs r5, r0, #0 */
/* @0xc9584 popeq {r3, r4, r5, pc} */
/* @0xc9588 mov r1, #1 */
/* @0xc958c mov r0, r4 */
/* @0xc9590 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc9594 mov r1, #2 */
/* @0xc9598 str r0, [r5] */
/* @0xc959c mov r0, r4 */
/* @0xc95a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc95a4 str r0, [r5, #0x4] */
/* @0xc95a8 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc95ac · F_Vertex_Float3_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0xc95ac push {r3, r4, r5, lr} */
/* @0xc95b0 mov r1, r3 */
/* @0xc95b4 ldr r4, [sp, #0x10] */
/* @0xc95b8 mov r3, #4 */
/* @0xc95bc mov r2, r4 */
/* @0xc95c0 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc95c4 cmp r0, #0 */
/* @0xc95c8 popeq {r3, r4, r5, pc} */
/* @0xc95cc mov r1, #3 */
/* @0xc95d0 bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType> */
/* @0xc95d4 subs r5, r0, #0 */
/* @0xc95d8 popeq {r3, r4, r5, pc} */
/* @0xc95dc mov r1, #1 */
/* @0xc95e0 mov r0, r4 */
/* @0xc95e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc95e8 mov r1, #2 */
/* @0xc95ec str r0, [r5] */
/* @0xc95f0 mov r0, r4 */
/* @0xc95f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc95f8 mov r1, #3 */
/* @0xc95fc str r0, [r5, #0x4] */
/* @0xc9600 mov r0, r4 */
/* @0xc9604 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc9608 str r0, [r5, #0x8] */
/* @0xc960c pop {r3, r4, r5, pc} */

/* ── FUNC 0xc9610 · F_Vertex_Float4_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0xc9610 push {r3, r4, r5, lr} */
/* @0xc9614 mov r1, r3 */
/* @0xc9618 ldr r4, [sp, #0x10] */
/* @0xc961c mov r3, #5 */
/* @0xc9620 mov r2, r4 */
/* @0xc9624 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc9628 cmp r0, #0 */
/* @0xc962c popeq {r3, r4, r5, pc} */
/* @0xc9630 mov r1, #4 */
/* @0xc9634 bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType> */
/* @0xc9638 subs r5, r0, #0 */
/* @0xc963c popeq {r3, r4, r5, pc} */
/* @0xc9640 mov r1, #1 */
/* @0xc9644 mov r0, r4 */
/* @0xc9648 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc964c mov r1, #2 */
/* @0xc9650 str r0, [r5] */
/* @0xc9654 mov r0, r4 */
/* @0xc9658 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc965c mov r1, #3 */
/* @0xc9660 str r0, [r5, #0x4] */
/* @0xc9664 mov r0, r4 */
/* @0xc9668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc966c mov r1, #4 */
/* @0xc9670 str r0, [r5, #0x8] */
/* @0xc9674 mov r0, r4 */
/* @0xc9678 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xc967c str r0, [r5, #0xc] */
/* @0xc9680 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc9684 · F_Vertex_ubyte4_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0xc9684 push {r3, r4, r5, lr} */
/* @0xc9688 mov r1, r3 */
/* @0xc968c ldr r4, [sp, #0x10] */
/* @0xc9690 mov r3, #5 */
/* @0xc9694 mov r2, r4 */
/* @0xc9698 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i> */
/* @0xc969c cmp r0, #0 */
/* @0xc96a0 popeq {r3, r4, r5, pc} */
/* @0xc96a4 mov r1, #6 */
/* @0xc96a8 bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType> */
/* @0xc96ac subs r5, r0, #0 */
/* @0xc96b0 popeq {r3, r4, r5, pc} */
/* @0xc96b4 mov r1, #1 */
/* @0xc96b8 mov r0, r4 */
/* @0xc96bc bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc96c0 mov r1, #2 */
/* @0xc96c4 strb r0, [r5] */
/* @0xc96c8 mov r0, r4 */
/* @0xc96cc bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc96d0 mov r1, #3 */
/* @0xc96d4 strb r0, [r5, #0x1] */
/* @0xc96d8 mov r0, r4 */
/* @0xc96dc bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc96e0 mov r1, #4 */
/* @0xc96e4 strb r0, [r5, #0x2] */
/* @0xc96e8 mov r0, r4 */
/* @0xc96ec bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xc96f0 strb r0, [r5, #0x3] */
/* @0xc96f4 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc96f8 · YYGML_vertex_position(int, float, float) · size=236 · insn=59 */
/* @0xc96f8 cmp r0, #0 */
/* @0xc96fc push {r4, r5, r6, lr} */
/* @0xc9700 mov r6, r1 */
/* @0xc9704 sub sp, sp, #8 */
/* @0xc9708 mov r5, r2 */
/* @0xc970c blt 0xc97bc <_Z21YYGML_vertex_positioniff+0xc4> */
/* @0xc9710 ldr r3, [pc, #0xc0] */
/* @0xc9714 add r3, pc, r3 */
/* @0xc9718 ldr r3, [r3] */
/* @0xc971c ldr r4, [r3, r0, lsl #2] */
/* @0xc9720 ldr r2, [r4, #0x2c] */
/* @0xc9724 ldr r3, [r4, #0xc] */
/* @0xc9728 ldr r12, [r4, #0x4] */
/* @0xc972c ldr r0, [r2, #0x14] */
/* @0xc9730 add r2, r0, r3 */
/* @0xc9734 cmp r12, r2 */
/* @0xc9738 blo 0xc9784 <_Z21YYGML_vertex_positioniff+0x8c> */
/* @0xc973c ldr r2, [r4] */
/* @0xc9740 ldr r1, [r4, #0x10] */
/* @0xc9744 add r0, r2, r3 */
/* @0xc9748 ldr r2, [r4, #0x14] */
/* @0xc974c add r3, r3, #8 */
/* @0xc9750 add r1, r1, #1 */
/* @0xc9754 str r6, [r0] */
/* @0xc9758 cmp r1, r2 */
/* @0xc975c str r5, [r0, #0x4] */
/* @0xc9760 str r3, [r4, #0xc] */
/* @0xc9764 ldrhs r3, [r4, #0x1c] */
/* @0xc9768 movhs r2, #0 */
/* @0xc976c str r1, [r4, #0x10] */
/* @0xc9770 addhs r3, r3, #1 */
/* @0xc9774 strhs r2, [r4, #0x10] */
/* @0xc9778 strhs r3, [r4, #0x1c] */
/* @0xc977c add sp, sp, #8 */
/* @0xc9780 pop {r4, r5, r6, pc} */
/* @0xc9784 add r1, r0, r12 */
/* @0xc9788 mov r2, #0 */
/* @0xc978c ldr r0, [r4] */
/* @0xc9790 add r1, r1, r12, lsr #1 */
/* @0xc9794 str r1, [r4, #0x4] */
/* @0xc9798 mov r3, #74 */
/* @0xc979c str r2, [sp] */
/* @0xc97a0 ldr r2, [pc, #0x34] */
/* @0xc97a4 add r2, pc, r2 */
/* @0xc97a8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc97ac ldr r3, [r4, #0xc] */
/* @0xc97b0 mov r2, r0 */
/* @0xc97b4 str r0, [r4] */
/* @0xc97b8 b 0xc9740 <_Z21YYGML_vertex_positioniff+0x48> */
/* @0xc97bc ldr r3, [pc, #0x1c] */
/* @0xc97c0 add r3, pc, r3 */
/* @0xc97c4 ldr r3, [r3, #0x4] */
/* @0xc97c8 cmp r0, r3 */
/* @0xc97cc blt 0xc9710 <_Z21YYGML_vertex_positioniff+0x18> */
/* @0xc97d0 add sp, sp, #8 */
/* @0xc97d4 pop {r4, r5, r6, pc} */
/* @0xc97d8 eorseq r0, r11, r0, lsr #20 */
/* @0xc97dc eoreq r7, r6, r12, lsl #17 */
/* @0xc97e0 eorseq r0, r11, r4, ror r9 */

/* ── FUNC 0xc97e4 · YYGML_vertex_position_3d(int, float, float, float) · size=244 · insn=61 */
/* @0xc97e4 cmp r0, #0 */
/* @0xc97e8 push {r4, r5, r6, r7, r8, lr} */
/* @0xc97ec mov r8, r1 */
/* @0xc97f0 sub sp, sp, #8 */
/* @0xc97f4 mov r7, r2 */
/* @0xc97f8 mov r6, r3 */
/* @0xc97fc blt 0xc98b0 <_Z24YYGML_vertex_position_3difff+0xcc> */
/* @0xc9800 ldr r3, [pc, #0xc4] */
/* @0xc9804 add r3, pc, r3 */
/* @0xc9808 ldr r3, [r3] */
/* @0xc980c ldr r4, [r3, r0, lsl #2] */
/* @0xc9810 ldr r3, [r4, #0x2c] */
/* @0xc9814 ldr r12, [r4, #0xc] */
/* @0xc9818 ldr r5, [r4, #0x4] */
/* @0xc981c ldr r0, [r3, #0x14] */
/* @0xc9820 add r3, r0, r12 */
/* @0xc9824 cmp r5, r3 */
/* @0xc9828 blo 0xc9878 <_Z24YYGML_vertex_position_3difff+0x94> */
/* @0xc982c ldr r3, [r4] */
/* @0xc9830 ldr r1, [r4, #0x10] */
/* @0xc9834 add r0, r3, r12 */
/* @0xc9838 ldr r3, [r4, #0x14] */
/* @0xc983c add r12, r12, #12 */
/* @0xc9840 add r1, r1, #1 */
/* @0xc9844 str r8, [r0] */
/* @0xc9848 cmp r1, r3 */
/* @0xc984c str r7, [r0, #0x4] */
/* @0xc9850 str r6, [r0, #0x8] */
/* @0xc9854 ldrhs r3, [r4, #0x1c] */
/* @0xc9858 movhs r2, #0 */
/* @0xc985c str r1, [r4, #0x10] */
/* @0xc9860 addhs r3, r3, #1 */
/* @0xc9864 str r12, [r4, #0xc] */
/* @0xc9868 strhs r2, [r4, #0x10] */
/* @0xc986c strhs r3, [r4, #0x1c] */
/* @0xc9870 add sp, sp, #8 */
/* @0xc9874 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc9878 add r1, r0, r5 */
/* @0xc987c mov r2, #0 */
/* @0xc9880 ldr r0, [r4] */
/* @0xc9884 add r1, r1, r5, lsr #1 */
/* @0xc9888 str r1, [r4, #0x4] */
/* @0xc988c mov r3, #74 */
/* @0xc9890 str r2, [sp] */
/* @0xc9894 ldr r2, [pc, #0x34] */
/* @0xc9898 add r2, pc, r2 */
/* @0xc989c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc98a0 ldr r12, [r4, #0xc] */
/* @0xc98a4 mov r3, r0 */
/* @0xc98a8 str r0, [r4] */
/* @0xc98ac b 0xc9830 <_Z24YYGML_vertex_position_3difff+0x4c> */
/* @0xc98b0 ldr r3, [pc, #0x1c] */
/* @0xc98b4 add r3, pc, r3 */
/* @0xc98b8 ldr r3, [r3, #0x4] */
/* @0xc98bc cmp r0, r3 */
/* @0xc98c0 blt 0xc9800 <_Z24YYGML_vertex_position_3difff+0x1c> */
/* @0xc98c4 add sp, sp, #8 */
/* @0xc98c8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc98cc eorseq r0, r11, r0, lsr r9 */
/* @0xc98d0 mlaeq r6, r8, r7, r7 */
/* @0xc98d4 eorseq r0, r11, r0, lsl #17 */

/* ── FUNC 0xc98d8 · YYGML_vertex_colour(int, int, float) · size=300 · insn=75 */
/* @0xc98d8 cmp r0, #0 */
/* @0xc98dc push {r4, r5, lr} */
/* @0xc98e0 vpush {d8} */
/* @0xc98e4 mov r5, r1 */
/* @0xc98e8 sub sp, sp, #12 */
/* @0xc98ec vmov s16, r2 */
/* @0xc98f0 blt 0xc99d4 <_Z19YYGML_vertex_colouriif+0xfc> */
/* @0xc98f4 ldr r3, [pc, #0xfc] */
/* @0xc98f8 add r3, pc, r3 */
/* @0xc98fc ldr r3, [r3] */
/* @0xc9900 ldr r4, [r3, r0, lsl #2] */
/* @0xc9904 ldr r2, [r4, #0x2c] */
/* @0xc9908 ldr r3, [r4, #0xc] */
/* @0xc990c ldr r12, [r4, #0x4] */
/* @0xc9910 ldr r0, [r2, #0x14] */
/* @0xc9914 add r2, r0, r3 */
/* @0xc9918 cmp r12, r2 */
/* @0xc991c blo 0xc999c <_Z19YYGML_vertex_colouriif+0xc4> */
/* @0xc9920 ldr r2, [r4] */
/* @0xc9924 vldr s15, [pc, #200] */
/* @0xc9928 vmul.f32 s16, s16, s15 */
/* @0xc992c add r3, r2, r3 */
/* @0xc9930 vcvt.s32.f32 s16, s16 */
/* @0xc9934 vmov r2, s16 */
/* @0xc9938 cmp r2, #255 */
/* @0xc993c movgt r2, #-16777216 */
/* @0xc9940 bgt 0xc9950 <_Z19YYGML_vertex_colouriif+0x78> */
/* @0xc9944 cmp r2, #0 */
/* @0xc9948 lslge r2, r2, #24 */
/* @0xc994c movlt r2, #0 */
/* @0xc9950 bic r5, r5, #-16777216 */
/* @0xc9954 orr r5, r2, r5 */
/* @0xc9958 str r5, [r3] */
/* @0xc995c ldr r3, [r4, #0x10] */
/* @0xc9960 ldr r1, [r4, #0x14] */
/* @0xc9964 add r3, r3, #1 */
/* @0xc9968 ldr r2, [r4, #0xc] */
/* @0xc996c cmp r3, r1 */
/* @0xc9970 str r3, [r4, #0x10] */
/* @0xc9974 add r3, r2, #4 */
/* @0xc9978 str r3, [r4, #0xc] */
/* @0xc997c ldrhs r3, [r4, #0x1c] */
/* @0xc9980 movhs r2, #0 */
/* @0xc9984 strhs r2, [r4, #0x10] */
/* @0xc9988 addhs r3, r3, #1 */
/* @0xc998c strhs r3, [r4, #0x1c] */
/* @0xc9990 add sp, sp, #12 */
/* @0xc9994 vpop {d8} */
/* @0xc9998 pop {r4, r5, pc} */
/* @0xc999c add r1, r0, r12 */
/* @0xc99a0 mov r2, #0 */
/* @0xc99a4 ldr r0, [r4] */
/* @0xc99a8 add r1, r1, r12, lsr #1 */
/* @0xc99ac str r1, [r4, #0x4] */
/* @0xc99b0 mov r3, #74 */
/* @0xc99b4 str r2, [sp] */
/* @0xc99b8 ldr r2, [pc, #0x3c] */
/* @0xc99bc add r2, pc, r2 */
/* @0xc99c0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc99c4 ldr r3, [r4, #0xc] */
/* @0xc99c8 mov r2, r0 */
/* @0xc99cc str r0, [r4] */
/* @0xc99d0 b 0xc9924 <_Z19YYGML_vertex_colouriif+0x4c> */
/* @0xc99d4 ldr r3, [pc, #0x24] */
/* @0xc99d8 add r3, pc, r3 */
/* @0xc99dc ldr r3, [r3, #0x4] */
/* @0xc99e0 cmp r0, r3 */
/* @0xc99e4 blt 0xc98f4 <_Z19YYGML_vertex_colouriif+0x1c> */
/* @0xc99e8 add sp, sp, #12 */
/* @0xc99ec vpop {d8} */
/* @0xc99f0 pop {r4, r5, pc} */
/* @0xc99f4 cmnmi pc, #0 */
/* @0xc99f8 eorseq r0, r11, r12, lsr r8 */
/* @0xc99fc eoreq r7, r6, r4, ror r6 */
/* @0xc9a00 eorseq r0, r11, r12, asr r7 */

/* ── FUNC 0xc9a04 · YYGML_vertex_argb(int, unsigned int) · size=252 · insn=63 */
/* @0xc9a04 cmp r0, #0 */
/* @0xc9a08 push {r4, r5, lr} */
/* @0xc9a0c mov r5, r1 */
/* @0xc9a10 sub sp, sp, #12 */
/* @0xc9a14 blt 0xc9ad8 <_Z17YYGML_vertex_argbij+0xd4> */
/* @0xc9a18 ldr r3, [pc, #0xd4] */
/* @0xc9a1c add r3, pc, r3 */
/* @0xc9a20 ldr r3, [r3] */
/* @0xc9a24 ldr r4, [r3, r0, lsl #2] */
/* @0xc9a28 ldr r1, [r4, #0x2c] */
/* @0xc9a2c ldr r2, [r4, #0xc] */
/* @0xc9a30 ldr r3, [r4, #0x4] */
/* @0xc9a34 ldr r1, [r1, #0x14] */
/* @0xc9a38 add r0, r1, r2 */
/* @0xc9a3c cmp r3, r0 */
/* @0xc9a40 blo 0xc9aa0 <_Z17YYGML_vertex_argbij+0x9c> */
/* @0xc9a44 ldr r1, [r4] */
/* @0xc9a48 bic r3, r5, #16711680 */
/* @0xc9a4c ubfx r0, r5, #0x10, #0x8 */
/* @0xc9a50 bic r3, r3, #255 */
/* @0xc9a54 uxtb r5, r5 */
/* @0xc9a58 orr r3, r3, r0 */
/* @0xc9a5c orr r3, r3, r5, lsl #16 */
/* @0xc9a60 str r3, [r1, r2] */
/* @0xc9a64 ldr r3, [r4, #0x10] */
/* @0xc9a68 ldr r1, [r4, #0x14] */
/* @0xc9a6c add r3, r3, #1 */
/* @0xc9a70 ldr r2, [r4, #0xc] */
/* @0xc9a74 cmp r3, r1 */
/* @0xc9a78 str r3, [r4, #0x10] */
/* @0xc9a7c add r3, r2, #4 */
/* @0xc9a80 str r3, [r4, #0xc] */
/* @0xc9a84 ldrhs r3, [r4, #0x1c] */
/* @0xc9a88 movhs r2, #0 */
/* @0xc9a8c strhs r2, [r4, #0x10] */
/* @0xc9a90 addhs r3, r3, #1 */
/* @0xc9a94 strhs r3, [r4, #0x1c] */
/* @0xc9a98 add sp, sp, #12 */
/* @0xc9a9c pop {r4, r5, pc} */
/* @0xc9aa0 add r1, r1, r3 */
/* @0xc9aa4 ldr r0, [r4] */
/* @0xc9aa8 add r1, r1, r3, lsr #1 */
/* @0xc9aac mov r2, #0 */
/* @0xc9ab0 str r1, [r4, #0x4] */
/* @0xc9ab4 mov r3, #74 */
/* @0xc9ab8 str r2, [sp] */
/* @0xc9abc ldr r2, [pc, #0x34] */
/* @0xc9ac0 add r2, pc, r2 */
/* @0xc9ac4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc9ac8 ldr r2, [r4, #0xc] */
/* @0xc9acc mov r1, r0 */
/* @0xc9ad0 str r0, [r4] */
/* @0xc9ad4 b 0xc9a48 <_Z17YYGML_vertex_argbij+0x44> */
/* @0xc9ad8 ldr r3, [pc, #0x1c] */
/* @0xc9adc add r3, pc, r3 */
/* @0xc9ae0 ldr r3, [r3, #0x4] */
/* @0xc9ae4 cmp r0, r3 */
/* @0xc9ae8 blt 0xc9a18 <_Z17YYGML_vertex_argbij+0x14> */
/* @0xc9aec add sp, sp, #12 */
/* @0xc9af0 pop {r4, r5, pc} */
/* @0xc9af4 eorseq r0, r11, r8, lsl r7 */
/* @0xc9af8 eoreq r7, r6, r0, ror r5 */
/* @0xc9afc eorseq r0, r11, r8, asr r6 */

/* ── FUNC 0xc9b00 · YYGML_vertex_texcoord(int, float, float) · size=236 · insn=59 */
/* @0xc9b00 cmp r0, #0 */
/* @0xc9b04 push {r4, r5, r6, lr} */
/* @0xc9b08 mov r6, r1 */
/* @0xc9b0c sub sp, sp, #8 */
/* @0xc9b10 mov r5, r2 */
/* @0xc9b14 blt 0xc9bc4 <_Z21YYGML_vertex_texcoordiff+0xc4> */
/* @0xc9b18 ldr r3, [pc, #0xc0] */
/* @0xc9b1c add r3, pc, r3 */
/* @0xc9b20 ldr r3, [r3] */
/* @0xc9b24 ldr r4, [r3, r0, lsl #2] */
/* @0xc9b28 ldr r2, [r4, #0x2c] */
/* @0xc9b2c ldr r3, [r4, #0xc] */
/* @0xc9b30 ldr r12, [r4, #0x4] */
/* @0xc9b34 ldr r0, [r2, #0x14] */
/* @0xc9b38 add r2, r0, r3 */
/* @0xc9b3c cmp r12, r2 */
/* @0xc9b40 blo 0xc9b8c <_Z21YYGML_vertex_texcoordiff+0x8c> */
/* @0xc9b44 ldr r2, [r4] */
/* @0xc9b48 ldr r1, [r4, #0x10] */
/* @0xc9b4c add r0, r2, r3 */
/* @0xc9b50 ldr r2, [r4, #0x14] */
/* @0xc9b54 add r3, r3, #8 */
/* @0xc9b58 add r1, r1, #1 */
/* @0xc9b5c str r6, [r0] */
/* @0xc9b60 cmp r1, r2 */
/* @0xc9b64 str r5, [r0, #0x4] */
/* @0xc9b68 str r3, [r4, #0xc] */
/* @0xc9b6c ldrhs r3, [r4, #0x1c] */
/* @0xc9b70 movhs r2, #0 */
/* @0xc9b74 str r1, [r4, #0x10] */
/* @0xc9b78 addhs r3, r3, #1 */
/* @0xc9b7c strhs r2, [r4, #0x10] */
/* @0xc9b80 strhs r3, [r4, #0x1c] */
/* @0xc9b84 add sp, sp, #8 */
/* @0xc9b88 pop {r4, r5, r6, pc} */
/* @0xc9b8c add r1, r0, r12 */
/* @0xc9b90 mov r2, #0 */
/* @0xc9b94 ldr r0, [r4] */
/* @0xc9b98 add r1, r1, r12, lsr #1 */
/* @0xc9b9c str r1, [r4, #0x4] */
/* @0xc9ba0 mov r3, #74 */
/* @0xc9ba4 str r2, [sp] */
/* @0xc9ba8 ldr r2, [pc, #0x34] */
/* @0xc9bac add r2, pc, r2 */
/* @0xc9bb0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc9bb4 ldr r3, [r4, #0xc] */
/* @0xc9bb8 mov r2, r0 */
/* @0xc9bbc str r0, [r4] */
/* @0xc9bc0 b 0xc9b48 <_Z21YYGML_vertex_texcoordiff+0x48> */
/* @0xc9bc4 ldr r3, [pc, #0x1c] */
/* @0xc9bc8 add r3, pc, r3 */
/* @0xc9bcc ldr r3, [r3, #0x4] */
/* @0xc9bd0 cmp r0, r3 */
/* @0xc9bd4 blt 0xc9b18 <_Z21YYGML_vertex_texcoordiff+0x18> */
/* @0xc9bd8 add sp, sp, #8 */
/* @0xc9bdc pop {r4, r5, r6, pc} */
/* @0xc9be0 eorseq r0, r11, r8, lsl r6 */
/* @0xc9be4 eoreq r7, r6, r4, lsl #9 */
/* @0xc9be8 eorseq r0, r11, r12, ror #10 */

/* ── FUNC 0xc9bec · YYGML_vertex_normal(int, float, float, float) · size=244 · insn=61 */
/* @0xc9bec cmp r0, #0 */
/* @0xc9bf0 push {r4, r5, r6, r7, r8, lr} */
/* @0xc9bf4 mov r8, r1 */
/* @0xc9bf8 sub sp, sp, #8 */
/* @0xc9bfc mov r7, r2 */
/* @0xc9c00 mov r6, r3 */
/* @0xc9c04 blt 0xc9cb8 <_Z19YYGML_vertex_normalifff+0xcc> */
/* @0xc9c08 ldr r3, [pc, #0xc4] */
/* @0xc9c0c add r3, pc, r3 */
/* @0xc9c10 ldr r3, [r3] */
/* @0xc9c14 ldr r4, [r3, r0, lsl #2] */
/* @0xc9c18 ldr r3, [r4, #0x2c] */
/* @0xc9c1c ldr r12, [r4, #0xc] */
/* @0xc9c20 ldr r5, [r4, #0x4] */
/* @0xc9c24 ldr r0, [r3, #0x14] */
/* @0xc9c28 add r3, r0, r12 */
/* @0xc9c2c cmp r5, r3 */
/* @0xc9c30 blo 0xc9c80 <_Z19YYGML_vertex_normalifff+0x94> */
/* @0xc9c34 ldr r3, [r4] */
/* @0xc9c38 ldr r1, [r4, #0x10] */
/* @0xc9c3c add r0, r3, r12 */
/* @0xc9c40 ldr r3, [r4, #0x14] */
/* @0xc9c44 add r12, r12, #12 */
/* @0xc9c48 add r1, r1, #1 */
/* @0xc9c4c str r8, [r0] */
/* @0xc9c50 cmp r1, r3 */
/* @0xc9c54 str r7, [r0, #0x4] */
/* @0xc9c58 str r6, [r0, #0x8] */
/* @0xc9c5c ldrhs r3, [r4, #0x1c] */
/* @0xc9c60 movhs r2, #0 */
/* @0xc9c64 str r1, [r4, #0x10] */
/* @0xc9c68 addhs r3, r3, #1 */
/* @0xc9c6c str r12, [r4, #0xc] */
/* @0xc9c70 strhs r2, [r4, #0x10] */
/* @0xc9c74 strhs r3, [r4, #0x1c] */
/* @0xc9c78 add sp, sp, #8 */
/* @0xc9c7c pop {r4, r5, r6, r7, r8, pc} */
/* @0xc9c80 add r1, r0, r5 */
/* @0xc9c84 mov r2, #0 */
/* @0xc9c88 ldr r0, [r4] */
/* @0xc9c8c add r1, r1, r5, lsr #1 */
/* @0xc9c90 str r1, [r4, #0x4] */
/* @0xc9c94 mov r3, #74 */
/* @0xc9c98 str r2, [sp] */
/* @0xc9c9c ldr r2, [pc, #0x34] */
/* @0xc9ca0 add r2, pc, r2 */
/* @0xc9ca4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc9ca8 ldr r12, [r4, #0xc] */
/* @0xc9cac mov r3, r0 */
/* @0xc9cb0 str r0, [r4] */
/* @0xc9cb4 b 0xc9c38 <_Z19YYGML_vertex_normalifff+0x4c> */
/* @0xc9cb8 ldr r3, [pc, #0x1c] */
/* @0xc9cbc add r3, pc, r3 */
/* @0xc9cc0 ldr r3, [r3, #0x4] */
/* @0xc9cc4 cmp r0, r3 */
/* @0xc9cc8 blt 0xc9c08 <_Z19YYGML_vertex_normalifff+0x1c> */
/* @0xc9ccc add sp, sp, #8 */
/* @0xc9cd0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc9cd4 eorseq r0, r11, r8, lsr #10 */
/* @0xc9cd8 mlaeq r6, r0, r3, r7 */
/* @0xc9cdc eorseq r0, r11, r8, ror r4 */

/* ── FUNC 0xc9ce0 · YYGML_vertex_float1(int, float) · size=228 · insn=57 */
/* @0xc9ce0 cmp r0, #0 */
/* @0xc9ce4 push {r4, r5, lr} */
/* @0xc9ce8 mov r5, r1 */
/* @0xc9cec sub sp, sp, #12 */
/* @0xc9cf0 blt 0xc9d9c <_Z19YYGML_vertex_float1if+0xbc> */
/* @0xc9cf4 ldr r3, [pc, #0xbc] */
/* @0xc9cf8 add r3, pc, r3 */
/* @0xc9cfc ldr r3, [r3] */
/* @0xc9d00 ldr r4, [r3, r0, lsl #2] */
/* @0xc9d04 ldr r1, [r4, #0x2c] */
/* @0xc9d08 ldr r3, [r4, #0xc] */
/* @0xc9d0c ldr r2, [r4, #0x4] */
/* @0xc9d10 ldr r0, [r1, #0x14] */
/* @0xc9d14 add r1, r0, r3 */
/* @0xc9d18 cmp r2, r1 */
/* @0xc9d1c blo 0xc9d64 <_Z19YYGML_vertex_float1if+0x84> */
/* @0xc9d20 ldr r1, [r4] */
/* @0xc9d24 ldr r2, [r4, #0x10] */
/* @0xc9d28 add r0, r1, r3 */
/* @0xc9d2c ldr r1, [r4, #0x14] */
/* @0xc9d30 add r3, r3, #4 */
/* @0xc9d34 add r2, r2, #1 */
/* @0xc9d38 str r5, [r0] */
/* @0xc9d3c cmp r2, r1 */
/* @0xc9d40 str r3, [r4, #0xc] */
/* @0xc9d44 str r2, [r4, #0x10] */
/* @0xc9d48 ldrhs r3, [r4, #0x1c] */
/* @0xc9d4c movhs r2, #0 */
/* @0xc9d50 strhs r2, [r4, #0x10] */
/* @0xc9d54 addhs r3, r3, #1 */
/* @0xc9d58 strhs r3, [r4, #0x1c] */
/* @0xc9d5c add sp, sp, #12 */
/* @0xc9d60 pop {r4, r5, pc} */
/* @0xc9d64 add r1, r0, r2 */
/* @0xc9d68 ldr r0, [r4] */
/* @0xc9d6c add r1, r1, r2, lsr #1 */
/* @0xc9d70 mov r2, #0 */
/* @0xc9d74 str r1, [r4, #0x4] */
/* @0xc9d78 mov r3, #74 */
/* @0xc9d7c str r2, [sp] */
/* @0xc9d80 ldr r2, [pc, #0x34] */
/* @0xc9d84 add r2, pc, r2 */
/* @0xc9d88 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc9d8c ldr r3, [r4, #0xc] */
/* @0xc9d90 mov r1, r0 */
/* @0xc9d94 str r0, [r4] */
/* @0xc9d98 b 0xc9d24 <_Z19YYGML_vertex_float1if+0x44> */
/* @0xc9d9c ldr r3, [pc, #0x1c] */
/* @0xc9da0 add r3, pc, r3 */
/* @0xc9da4 ldr r3, [r3, #0x4] */
/* @0xc9da8 cmp r0, r3 */
/* @0xc9dac blt 0xc9cf4 <_Z19YYGML_vertex_float1if+0x14> */
/* @0xc9db0 add sp, sp, #12 */
/* @0xc9db4 pop {r4, r5, pc} */
/* @0xc9db8 eorseq r0, r11, r12, lsr r4 */
/* @0xc9dbc eoreq r7, r6, r12, lsr #5 */
/* @0xc9dc0 mlaseq r11, r4, r3, r0 */

/* ── FUNC 0xc9dc4 · YYGML_vertex_float2(int, float, float) · size=236 · insn=59 */
/* @0xc9dc4 cmp r0, #0 */
/* @0xc9dc8 push {r4, r5, r6, lr} */
/* @0xc9dcc mov r6, r1 */
/* @0xc9dd0 sub sp, sp, #8 */
/* @0xc9dd4 mov r5, r2 */
/* @0xc9dd8 blt 0xc9e88 <_Z19YYGML_vertex_float2iff+0xc4> */
/* @0xc9ddc ldr r3, [pc, #0xc0] */
/* @0xc9de0 add r3, pc, r3 */
/* @0xc9de4 ldr r3, [r3] */
/* @0xc9de8 ldr r4, [r3, r0, lsl #2] */
/* @0xc9dec ldr r2, [r4, #0x2c] */
/* @0xc9df0 ldr r3, [r4, #0xc] */
/* @0xc9df4 ldr r12, [r4, #0x4] */
/* @0xc9df8 ldr r0, [r2, #0x14] */
/* @0xc9dfc add r2, r0, r3 */
/* @0xc9e00 cmp r12, r2 */
/* @0xc9e04 blo 0xc9e50 <_Z19YYGML_vertex_float2iff+0x8c> */
/* @0xc9e08 ldr r2, [r4] */
/* @0xc9e0c ldr r1, [r4, #0x10] */
/* @0xc9e10 add r0, r2, r3 */
/* @0xc9e14 ldr r2, [r4, #0x14] */
/* @0xc9e18 add r3, r3, #8 */
/* @0xc9e1c add r1, r1, #1 */
/* @0xc9e20 str r6, [r0] */
/* @0xc9e24 cmp r1, r2 */
/* @0xc9e28 str r5, [r0, #0x4] */
/* @0xc9e2c str r3, [r4, #0xc] */
/* @0xc9e30 ldrhs r3, [r4, #0x1c] */
/* @0xc9e34 movhs r2, #0 */
/* @0xc9e38 str r1, [r4, #0x10] */
/* @0xc9e3c addhs r3, r3, #1 */
/* @0xc9e40 strhs r2, [r4, #0x10] */
/* @0xc9e44 strhs r3, [r4, #0x1c] */
/* @0xc9e48 add sp, sp, #8 */
/* @0xc9e4c pop {r4, r5, r6, pc} */
/* @0xc9e50 add r1, r0, r12 */
/* @0xc9e54 mov r2, #0 */
/* @0xc9e58 ldr r0, [r4] */
/* @0xc9e5c add r1, r1, r12, lsr #1 */
/* @0xc9e60 str r1, [r4, #0x4] */
/* @0xc9e64 mov r3, #74 */
/* @0xc9e68 str r2, [sp] */
/* @0xc9e6c ldr r2, [pc, #0x34] */
/* @0xc9e70 add r2, pc, r2 */
/* @0xc9e74 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc9e78 ldr r3, [r4, #0xc] */
/* @0xc9e7c mov r2, r0 */
/* @0xc9e80 str r0, [r4] */
/* @0xc9e84 b 0xc9e0c <_Z19YYGML_vertex_float2iff+0x48> */
/* @0xc9e88 ldr r3, [pc, #0x1c] */
/* @0xc9e8c add r3, pc, r3 */
/* @0xc9e90 ldr r3, [r3, #0x4] */
/* @0xc9e94 cmp r0, r3 */
/* @0xc9e98 blt 0xc9ddc <_Z19YYGML_vertex_float2iff+0x18> */
/* @0xc9e9c add sp, sp, #8 */
/* @0xc9ea0 pop {r4, r5, r6, pc} */
/* @0xc9ea4 eorseq r0, r11, r4, asr r3 */
/* @0xc9ea8 eoreq r7, r6, r0, asr #3 */
/* @0xc9eac eorseq r0, r11, r8, lsr #5 */

/* ── FUNC 0xc9eb0 · YYGML_vertex_float3(int, float, float, float) · size=244 · insn=61 */
/* @0xc9eb0 cmp r0, #0 */
/* @0xc9eb4 push {r4, r5, r6, r7, r8, lr} */
/* @0xc9eb8 mov r8, r1 */
/* @0xc9ebc sub sp, sp, #8 */
/* @0xc9ec0 mov r7, r2 */
/* @0xc9ec4 mov r6, r3 */
/* @0xc9ec8 blt 0xc9f7c <_Z19YYGML_vertex_float3ifff+0xcc> */
/* @0xc9ecc ldr r3, [pc, #0xc4] */
/* @0xc9ed0 add r3, pc, r3 */
/* @0xc9ed4 ldr r3, [r3] */
/* @0xc9ed8 ldr r4, [r3, r0, lsl #2] */
/* @0xc9edc ldr r3, [r4, #0x2c] */
/* @0xc9ee0 ldr r12, [r4, #0xc] */
/* @0xc9ee4 ldr r5, [r4, #0x4] */
/* @0xc9ee8 ldr r0, [r3, #0x14] */
/* @0xc9eec add r3, r0, r12 */
/* @0xc9ef0 cmp r5, r3 */
/* @0xc9ef4 blo 0xc9f44 <_Z19YYGML_vertex_float3ifff+0x94> */
/* @0xc9ef8 ldr r3, [r4] */
/* @0xc9efc ldr r1, [r4, #0x10] */
/* @0xc9f00 add r0, r3, r12 */
/* @0xc9f04 ldr r3, [r4, #0x14] */
/* @0xc9f08 add r12, r12, #12 */
/* @0xc9f0c add r1, r1, #1 */
/* @0xc9f10 str r8, [r0] */
/* @0xc9f14 cmp r1, r3 */
/* @0xc9f18 str r7, [r0, #0x4] */
/* @0xc9f1c str r6, [r0, #0x8] */
/* @0xc9f20 ldrhs r3, [r4, #0x1c] */
/* @0xc9f24 movhs r2, #0 */
/* @0xc9f28 str r1, [r4, #0x10] */
/* @0xc9f2c addhs r3, r3, #1 */
/* @0xc9f30 str r12, [r4, #0xc] */
/* @0xc9f34 strhs r2, [r4, #0x10] */
/* @0xc9f38 strhs r3, [r4, #0x1c] */
/* @0xc9f3c add sp, sp, #8 */
/* @0xc9f40 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc9f44 add r1, r0, r5 */
/* @0xc9f48 mov r2, #0 */
/* @0xc9f4c ldr r0, [r4] */
/* @0xc9f50 add r1, r1, r5, lsr #1 */
/* @0xc9f54 str r1, [r4, #0x4] */
/* @0xc9f58 mov r3, #74 */
/* @0xc9f5c str r2, [sp] */
/* @0xc9f60 ldr r2, [pc, #0x34] */
/* @0xc9f64 add r2, pc, r2 */
/* @0xc9f68 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc9f6c ldr r12, [r4, #0xc] */
/* @0xc9f70 mov r3, r0 */
/* @0xc9f74 str r0, [r4] */
/* @0xc9f78 b 0xc9efc <_Z19YYGML_vertex_float3ifff+0x4c> */
/* @0xc9f7c ldr r3, [pc, #0x1c] */
/* @0xc9f80 add r3, pc, r3 */
/* @0xc9f84 ldr r3, [r3, #0x4] */
/* @0xc9f88 cmp r0, r3 */
/* @0xc9f8c blt 0xc9ecc <_Z19YYGML_vertex_float3ifff+0x1c> */
/* @0xc9f90 add sp, sp, #8 */
/* @0xc9f94 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc9f98 eorseq r0, r11, r4, ror #4 */
/* @0xc9f9c eoreq r7, r6, r12, asr #1 */
/* @0xc9fa0 ldrhteq r0, [r11], -r4 */

/* ── FUNC 0xc9fa4 · YYGML_vertex_float4(int, float, float, float, float) · size=252 · insn=63 */
/* @0xc9fa4 cmp r0, #0 */
/* @0xc9fa8 push {r4, r5, r6, r7, r8, lr} */
/* @0xc9fac mov r8, r1 */
/* @0xc9fb0 sub sp, sp, #8 */
/* @0xc9fb4 mov r7, r2 */
/* @0xc9fb8 mov r6, r3 */
/* @0xc9fbc blt 0xca078 <_Z19YYGML_vertex_float4iffff+0xd4> */
/* @0xc9fc0 ldr r3, [pc, #0xcc] */
/* @0xc9fc4 add r3, pc, r3 */
/* @0xc9fc8 ldr r3, [r3] */
/* @0xc9fcc ldr r4, [r3, r0, lsl #2] */
/* @0xc9fd0 ldr r3, [r4, #0x2c] */
/* @0xc9fd4 ldr r12, [r4, #0xc] */
/* @0xc9fd8 ldr r5, [r4, #0x4] */
/* @0xc9fdc ldr r0, [r3, #0x14] */
/* @0xc9fe0 add r3, r0, r12 */
/* @0xc9fe4 cmp r5, r3 */
/* @0xc9fe8 blo 0xca040 <_Z19YYGML_vertex_float4iffff+0x9c> */
/* @0xc9fec ldr r3, [r4] */
/* @0xc9ff0 ldr r1, [r4, #0x10] */
/* @0xc9ff4 add r0, r3, r12 */
/* @0xc9ff8 ldr r3, [r4, #0x14] */
/* @0xc9ffc vldr s15, [sp, #32] */
/* @0xca000 add r1, r1, #1 */
/* @0xca004 str r8, [r0] */
/* @0xca008 cmp r1, r3 */
/* @0xca00c str r7, [r0, #0x4] */
/* @0xca010 str r6, [r0, #0x8] */
/* @0xca014 vstr s15, [r0, #12] */
/* @0xca018 ldrhs r3, [r4, #0x1c] */
/* @0xca01c add r12, r12, #16 */
/* @0xca020 str r1, [r4, #0x10] */
/* @0xca024 movhs r2, #0 */
/* @0xca028 addhs r3, r3, #1 */
/* @0xca02c str r12, [r4, #0xc] */
/* @0xca030 strhs r2, [r4, #0x10] */
/* @0xca034 strhs r3, [r4, #0x1c] */
/* @0xca038 add sp, sp, #8 */
/* @0xca03c pop {r4, r5, r6, r7, r8, pc} */
/* @0xca040 add r1, r0, r5 */
/* @0xca044 mov r2, #0 */
/* @0xca048 ldr r0, [r4] */
/* @0xca04c add r1, r1, r5, lsr #1 */
/* @0xca050 str r1, [r4, #0x4] */
/* @0xca054 mov r3, #74 */
/* @0xca058 str r2, [sp] */
/* @0xca05c ldr r2, [pc, #0x34] */
/* @0xca060 add r2, pc, r2 */
/* @0xca064 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xca068 ldr r12, [r4, #0xc] */
/* @0xca06c mov r3, r0 */
/* @0xca070 str r0, [r4] */
/* @0xca074 b 0xc9ff0 <_Z19YYGML_vertex_float4iffff+0x4c> */
/* @0xca078 ldr r3, [pc, #0x1c] */
/* @0xca07c add r3, pc, r3 */
/* @0xca080 ldr r3, [r3, #0x4] */
/* @0xca084 cmp r0, r3 */
/* @0xca088 blt 0xc9fc0 <_Z19YYGML_vertex_float4iffff+0x1c> */
/* @0xca08c add sp, sp, #8 */
/* @0xca090 pop {r4, r5, r6, r7, r8, pc} */
/* @0xca094 eorseq r0, r11, r0, ror r1 */
/* @0xca098 .word 0x00266fd0 */
/* @0xca09c ldrhteq r0, [r11], -r8 */

/* ── FUNC 0xca0a0 · YYGML_vertex_ubyte4(int, int, int, int, int) · size=256 · insn=64 */
/* @0xca0a0 cmp r0, #0 */
/* @0xca0a4 push {r4, r5, r6, r7, r8, lr} */
/* @0xca0a8 mov r8, r1 */
/* @0xca0ac sub sp, sp, #8 */
/* @0xca0b0 mov r7, r2 */
/* @0xca0b4 mov r6, r3 */
/* @0xca0b8 blt 0xca178 <_Z19YYGML_vertex_ubyte4iiiii+0xd8> */
/* @0xca0bc ldr r3, [pc, #0xd0] */
/* @0xca0c0 add r3, pc, r3 */
/* @0xca0c4 ldr r3, [r3] */
/* @0xca0c8 ldr r4, [r3, r0, lsl #2] */
/* @0xca0cc ldr r3, [r4, #0x2c] */
/* @0xca0d0 ldr r12, [r4, #0xc] */
/* @0xca0d4 ldr r5, [r4, #0x4] */
/* @0xca0d8 ldr r3, [r3, #0x14] */
/* @0xca0dc add r2, r3, r12 */
/* @0xca0e0 cmp r5, r2 */
/* @0xca0e4 blo 0xca140 <_Z19YYGML_vertex_ubyte4iiiii+0xa0> */
/* @0xca0e8 ldr r5, [r4] */
/* @0xca0ec ldr r3, [sp, #0x20] */
/* @0xca0f0 add r0, r5, r12 */
/* @0xca0f4 strb r8, [r5, r12] */
/* @0xca0f8 strb r7, [r0, #0x1] */
/* @0xca0fc strb r6, [r0, #0x2] */
/* @0xca100 strb r3, [r0, #0x3] */
/* @0xca104 ldr r3, [r4, #0x10] */
/* @0xca108 ldr r1, [r4, #0x14] */
/* @0xca10c add r3, r3, #1 */
/* @0xca110 ldr r2, [r4, #0xc] */
/* @0xca114 cmp r3, r1 */
/* @0xca118 str r3, [r4, #0x10] */
/* @0xca11c add r3, r2, #4 */
/* @0xca120 str r3, [r4, #0xc] */
/* @0xca124 ldrhs r3, [r4, #0x1c] */
/* @0xca128 movhs r2, #0 */
/* @0xca12c strhs r2, [r4, #0x10] */
/* @0xca130 addhs r3, r3, #1 */
/* @0xca134 strhs r3, [r4, #0x1c] */
/* @0xca138 add sp, sp, #8 */
/* @0xca13c pop {r4, r5, r6, r7, r8, pc} */
/* @0xca140 add r3, r3, r5 */
/* @0xca144 ldr r0, [r4] */
/* @0xca148 add r1, r3, r5, lsr #1 */
/* @0xca14c mov r2, #0 */
/* @0xca150 str r1, [r4, #0x4] */
/* @0xca154 mov r3, #74 */
/* @0xca158 str r2, [sp] */
/* @0xca15c ldr r2, [pc, #0x34] */
/* @0xca160 add r2, pc, r2 */
/* @0xca164 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xca168 ldr r12, [r4, #0xc] */
/* @0xca16c mov r5, r0 */
/* @0xca170 str r0, [r4] */
/* @0xca174 b 0xca0ec <_Z19YYGML_vertex_ubyte4iiiii+0x4c> */
/* @0xca178 ldr r3, [pc, #0x1c] */
/* @0xca17c add r3, pc, r3 */
/* @0xca180 ldr r3, [r3, #0x4] */
/* @0xca184 cmp r0, r3 */
/* @0xca188 blt 0xca0bc <_Z19YYGML_vertex_ubyte4iiiii+0x1c> */
/* @0xca18c add sp, sp, #8 */
/* @0xca190 pop {r4, r5, r6, r7, r8, pc} */
/* @0xca194 eorseq r0, r11, r4, ror r0 */
/* @0xca198 .word 0x00266ed0 */
/* @0xca19c ldrhteq pc, [r10], -r8 */

/* ── FUNC 0xca1a0 · _FreezeBuffer(Buffer_Vertex*) · size=172 · insn=43 */
/* @0xca1a0 push {r4, r5, r6, lr} */
/* @0xca1a4 mov r6, r0 */
/* @0xca1a8 mov r0, #64 */
/* @0xca1ac mov r4, #0 */
/* @0xca1b0 bl 0x27c524 <_Znwj> */
/* @0xca1b4 mov r1, #0 */
/* @0xca1b8 mov r3, r1 */
/* @0xca1bc mov r5, #0 */
/* @0xca1c0 ldr r2, [r6, #0x1c] */
/* @0xca1c4 str r1, [r0] */
/* @0xca1c8 str r1, [r0, #0x4] */
/* @0xca1cc str r1, [r0, #0xc] */
/* @0xca1d0 str r1, [r0, #0x20] */
/* @0xca1d4 str r1, [r0, #0x24] */
/* @0xca1d8 str r1, [r0, #0x2c] */
/* @0xca1dc str r1, [r0, #0x30] */
/* @0xca1e0 str r1, [r0, #0x28] */
/* @0xca1e4 str r1, [r0, #0x34] */
/* @0xca1e8 str r1, [r0, #0x8] */
/* @0xca1ec strd r4, r5, [r0, #56] */
/* @0xca1f0 ldr r1, [r6, #0x28] */
/* @0xca1f4 str r0, [r6, #0x30] */
/* @0xca1f8 bl 0x18378c <_ZN12VertexBuffer4InitEiii> */
/* @0xca1fc cmp r0, #0 */
/* @0xca200 bne 0xca230 <_Z13_FreezeBufferP13Buffer_Vertex+0x90> */
/* @0xca204 ldr r4, [r6, #0x30] */
/* @0xca208 cmp r4, #0 */
/* @0xca20c beq 0xca220 <_Z13_FreezeBufferP13Buffer_Vertex+0x80> */
/* @0xca210 mov r0, r4 */
/* @0xca214 bl 0x18373c <_ZN12VertexBufferD2Ev> */
/* @0xca218 mov r0, r4 */
/* @0xca21c bl 0x27d1d0 <_ZdlPv> */
/* @0xca220 mov r3, #0 */
/* @0xca224 str r3, [r6, #0x30] */
/* @0xca228 strb r3, [r6, #0x20] */
/* @0xca22c pop {r4, r5, r6, pc} */
/* @0xca230 ldr r0, [r6, #0x30] */
/* @0xca234 ldr r1, [r6] */
/* @0xca238 ldr r2, [r6, #0xc] */
/* @0xca23c bl 0x1838c0 <_ZN12VertexBuffer16UpdateFromBufferEPvi> */
/* @0xca240 mov r3, #1 */
/* @0xca244 strb r3, [r6, #0x20] */
/* @0xca248 pop {r4, r5, r6, pc} */

/* ── FUNC 0xca24c · F_Vertex_Submit_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=608 · insn=152 */
/* @0xca24c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xca250 sub sp, sp, #12 */
/* @0xca254 ldr r2, [pc, #0x23c] */
/* @0xca258 mov r1, #0 */
/* @0xca25c ldr r5, [sp, #0x30] */
/* @0xca260 mov r3, r1 */
/* @0xca264 add r2, pc, r2 */
/* @0xca268 movt r3, #0xbff0 */
/* @0xca26c str r1, [r0, #0xc] */
/* @0xca270 stm r0, {r1, r3} */
/* @0xca274 mov r0, r5 */
/* @0xca278 ldr r4, [r2] */
/* @0xca27c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xca280 mov r1, #1 */
/* @0xca284 ldr r4, [r4, r0, lsl #2] */
/* @0xca288 mov r0, r5 */
/* @0xca28c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xca290 mov r1, #2 */
/* @0xca294 mov r8, r0 */
/* @0xca298 mov r0, r5 */
/* @0xca29c bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0xca2a0 mov r5, r0 */
/* @0xca2a4 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0xca2a8 cmp r0, #0 */
/* @0xca2ac bne 0xca3c8 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0xca2b0 cmn r5, #1 */
/* @0xca2b4 moveq r10, r0 */
/* @0xca2b8 beq 0xca2d4 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xca2bc ldr r3, [pc, #0x1d8] */
/* @0xca2c0 ldrsh r2, [r5, #20] */
/* @0xca2c4 ldr r3, [pc, r3] */
/* @0xca2c8 ldr r3, [r3, #0x4] */
/* @0xca2cc ldr r3, [r3, r2, lsl #2] */
/* @0xca2d0 ldr r10, [r3] */
/* @0xca2d4 ldrb r3, [r4, #0x20] */
/* @0xca2d8 cmp r3, #0 */
/* @0xca2dc bne 0xca3e8 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0xca2e0 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0xca2e4 mov r6, r0 */
/* @0xca2e8 bl 0x185624 <_ZN8Graphics24GetMaxDynamicVertexSpaceEv> */
/* @0xca2ec mov r5, r0 */
/* @0xca2f0 ldr r0, [r4, #0x28] */
/* @0xca2f4 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xca2f8 cmp r0, #0 */
/* @0xca2fc beq 0xca480 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0xca300 ldr r2, [r0, #0x14] */
/* @0xca304 ldr r3, [r4, #0x1c] */
/* @0xca308 mul r2, r2, r3 */
/* @0xca30c cmp r5, r2 */
/* @0xca310 ble 0xca31c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0xca314 cmp r6, r3 */
/* @0xca318 bgt 0xca45c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0xca31c sub r3, r8, #1 */
/* @0xca320 cmp r3, #3 */
/* @0xca324 bhi 0xca3c0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0xca328 ldr r2, [pc, #0x170] */
/* @0xca32c add r2, pc, r2 */
/* @0xca330 ldr r11, [r2, r3, lsl #2] */
/* @0xca334 cmn r11, #1 */
/* @0xca338 beq 0xca3c0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0xca33c ldr r0, [r4, #0x28] */
/* @0xca340 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xca344 subs r9, r0, #0 */
/* @0xca348 beq 0xca480 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0xca34c ldr r1, [r9, #0x14] */
/* @0xca350 mov r0, r5 */
/* @0xca354 bl 0x318c48 <__udivsi3> */
/* @0xca358 mov r1, r11 */
/* @0xca35c cmp r0, r6 */
/* @0xca360 movge r0, r6 */
/* @0xca364 bl 0x318d10 <__divsi3> */
/* @0xca368 ldr r6, [r4, #0x1c] */
/* @0xca36c ldr r7, [r4] */
/* @0xca370 cmp r6, #0 */
/* @0xca374 mul r11, r11, r0 */
/* @0xca378 ble 0xca3c0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0xca37c cmp r6, r11 */
/* @0xca380 movlt r5, r6 */
/* @0xca384 movge r5, r11 */
/* @0xca388 mov r1, r10 */
/* @0xca38c ldr r2, [r4, #0x28] */
/* @0xca390 mov r0, r8 */
/* @0xca394 mov r3, r5 */
/* @0xca398 rsb r6, r5, r6 */
/* @0xca39c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0xca3a0 ldr r2, [r9, #0x14] */
/* @0xca3a4 mov r1, r7 */
/* @0xca3a8 mul r2, r2, r5 */
/* @0xca3ac bl 0xb65bc <memcpy@plt> */
/* @0xca3b0 ldr r3, [r9, #0x14] */
/* @0xca3b4 cmp r6, #0 */
/* @0xca3b8 mla r7, r3, r5, r7 */
/* @0xca3bc bgt 0xca37c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0xca3c0 add sp, sp, #12 */
/* @0xca3c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xca3c8 ldr r3, [pc, #0xd4] */
/* @0xca3cc ldr r3, [pc, r3] */
/* @0xca3d0 ldr r3, [r3, #0x4] */
/* @0xca3d4 ldr r3, [r3, r5, lsl #2] */
/* @0xca3d8 ldr r10, [r3] */
/* @0xca3dc ldrb r3, [r4, #0x20] */
/* @0xca3e0 cmp r3, #0 */
/* @0xca3e4 beq 0xca2e0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xca3e8 mov r0, r8 */
/* @0xca3ec bl 0x185638 <_ZN8Graphics25IsSupportedNativePrimtypeE9ePrimType> */
/* @0xca3f0 cmp r0, #0 */
/* @0xca3f4 beq 0xca2e0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xca3f8 ldr r0, [r4, #0x30] */
/* @0xca3fc cmp r0, #0 */
/* @0xca400 beq 0xca42c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0xca404 bl 0x183958 <_ZN12VertexBuffer7IsValidEv> */
/* @0xca408 cmp r0, #0 */
/* @0xca40c bne 0xca434 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0xca410 ldr r5, [r4, #0x30] */
/* @0xca414 cmp r5, #0 */
/* @0xca418 beq 0xca42c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0xca41c mov r0, r5 */
/* @0xca420 bl 0x18373c <_ZN12VertexBufferD2Ev> */
/* @0xca424 mov r0, r5 */
/* @0xca428 bl 0x27d1d0 <_ZdlPv> */
/* @0xca42c mov r0, r4 */
/* @0xca430 bl 0xca1a0 <_Z13_FreezeBufferP13Buffer_Vertex> */
/* @0xca434 ldr r1, [r4, #0x1c] */
/* @0xca438 mov r0, r8 */
/* @0xca43c ldr r3, [r4, #0x28] */
/* @0xca440 mov r2, #0 */
/* @0xca444 str r10, [sp] */
/* @0xca448 ldr r12, [r4, #0x30] */
/* @0xca44c str r12, [sp, #0x4] */
/* @0xca450 bl 0x185730 <_ZN8Graphics15DrawArrayFromVBE9ePrimTypeiiiPvP12VertexBuffer> */
/* @0xca454 add sp, sp, #12 */
/* @0xca458 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xca45c mov r1, r10 */
/* @0xca460 ldr r2, [r4, #0x28] */
/* @0xca464 mov r0, r8 */
/* @0xca468 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0xca46c ldr r1, [r4] */
/* @0xca470 ldr r2, [r4, #0xc] */
/* @0xca474 add sp, sp, #12 */
/* @0xca478 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xca47c b 0xb65bc <memcpy@plt> */
/* @0xca480 ldr r0, [pc, #0x20] */
/* @0xca484 mov r1, #1 */
/* @0xca488 add r0, pc, r0 */
/* @0xca48c add sp, sp, #12 */
/* @0xca490 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xca494 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xca498 ldrsbteq pc, [r10], -r0 */
/* @0xca49c eorseq r3, r2, r8, asr r6 */
/* @0xca4a0 eoreq r2, r9, r12, lsl #9 */
/* @0xca4a4 eorseq r3, r2, r0, asr r5 */
/* @0xca4a8 eoreq r7, r6, r8, ror r9 */

/* ── FUNC 0xca4ac · F_Vertex_Submit_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0xca4ac cmp r3, #3 */
/* @0xca4b0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xca4b4 mov r4, r0 */
/* @0xca4b8 mov r0, #0 */
/* @0xca4bc mov r7, r1 */
/* @0xca4c0 mov r5, r3 */
/* @0xca4c4 mov r1, r0 */
/* @0xca4c8 mov r8, r2 */
/* @0xca4cc movt r0, #0xbff0 */
/* @0xca4d0 str r1, [r4, #0xc] */
/* @0xca4d4 str r0, [r4, #0x4] */
/* @0xca4d8 str r1, [r4] */
/* @0xca4dc ldr r6, [sp, #0x20] */
/* @0xca4e0 beq 0xca4f8 <_Z21F_Vertex_Submit_debugR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xca4e4 ldr r0, [pc, #0xac] */
/* @0xca4e8 mov r1, #1 */
/* @0xca4ec pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xca4f0 add r0, pc, r0 */
/* @0xca4f4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xca4f8 mov r0, r6 */
/* @0xca4fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xca500 bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xca504 subs r9, r0, #0 */
/* @0xca508 beq 0xca584 <_Z21F_Vertex_Submit_debugR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0xca50c ldr r3, [r9, #0x28] */
/* @0xca510 cmn r3, #1 */
/* @0xca514 beq 0xca570 <_Z21F_Vertex_Submit_debugR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0xca518 mov r0, r6 */
/* @0xca51c mov r1, #1 */
/* @0xca520 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xca524 ldrb r3, [r9, #0x20] */
/* @0xca528 cmp r3, #0 */
/* @0xca52c moveq r3, #7 */
/* @0xca530 movne r3, #6 */
/* @0xca534 cmp r0, #0 */
/* @0xca538 cmpgt r3, r0 */
/* @0xca53c ble 0xca55c <_Z21F_Vertex_Submit_debugR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xca540 str r6, [sp, #0x20] */
/* @0xca544 mov r0, r4 */
/* @0xca548 mov r1, r7 */
/* @0xca54c mov r2, r8 */
/* @0xca550 mov r3, r5 */
/* @0xca554 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xca558 b 0xca24c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_> */
/* @0xca55c ldr r0, [pc, #0x38] */
/* @0xca560 mov r1, #1 */
/* @0xca564 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xca568 add r0, pc, r0 */
/* @0xca56c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xca570 ldr r0, [pc, #0x28] */
/* @0xca574 mov r1, #1 */
/* @0xca578 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xca57c add r0, pc, r0 */
/* @0xca580 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xca584 ldr r0, [pc, #0x18] */
/* @0xca588 mov r1, #1 */
/* @0xca58c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xca590 add r0, pc, r0 */
/* @0xca594 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xca598 eoreq r7, r6, r8, lsr r9 */
/* @0xca59c eoreq r7, r6, r8, asr r9 */
/* @0xca5a0 eoreq r7, r6, r4, lsl #18 */
/* @0xca5a4 eoreq r7, r6, r0, asr #17 */

/* ── FUNC 0xca5a8 · F_Vertex_Freeze_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0xca5a8 push {r3, lr} */
/* @0xca5ac mov r1, #0 */
/* @0xca5b0 ldr r12, [sp, #0x8] */
/* @0xca5b4 mov r2, r1 */
/* @0xca5b8 str r1, [r0, #0xc] */
/* @0xca5bc movt r2, #0xbff0 */
/* @0xca5c0 stm r0, {r1, r2} */
/* @0xca5c4 mov r0, r12 */
/* @0xca5c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xca5cc bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xca5d0 pop {r3, lr} */
/* @0xca5d4 b 0xca1a0 <_Z13_FreezeBufferP13Buffer_Vertex> */

/* ── FUNC 0xca5d8 · F_Vertex_Freeze_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0xca5d8 cmp r3, #1 */
/* @0xca5dc mov r2, #0 */
/* @0xca5e0 push {r4, lr} */
/* @0xca5e4 mov r1, r2 */
/* @0xca5e8 mov r4, r3 */
/* @0xca5ec movt r2, #0xbff0 */
/* @0xca5f0 str r1, [r0, #0xc] */
/* @0xca5f4 stm r0, {r1, r2} */
/* @0xca5f8 ldr r0, [sp, #0x8] */
/* @0xca5fc beq 0xca614 <_Z21F_Vertex_Freeze_debugR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0xca600 ldr r0, [pc, #0x64] */
/* @0xca604 mov r1, #1 */
/* @0xca608 pop {r4, lr} */
/* @0xca60c add r0, pc, r0 */
/* @0xca610 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xca614 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xca618 bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xca61c subs r3, r0, #0 */
/* @0xca620 beq 0xca658 <_Z21F_Vertex_Freeze_debugR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xca624 ldrb r2, [r3, #0x20] */
/* @0xca628 cmp r2, #0 */
/* @0xca62c bne 0xca658 <_Z21F_Vertex_Freeze_debugR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xca630 ldr r3, [r3, #0x24] */
/* @0xca634 cmn r3, #1 */
/* @0xca638 beq 0xca650 <_Z21F_Vertex_Freeze_debugR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xca63c ldr r0, [pc, #0x2c] */
/* @0xca640 mov r1, r4 */
/* @0xca644 pop {r4, lr} */
/* @0xca648 add r0, pc, r0 */
/* @0xca64c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xca650 pop {r4, lr} */
/* @0xca654 b 0xca1a0 <_Z13_FreezeBufferP13Buffer_Vertex> */
/* @0xca658 ldr r0, [pc, #0x14] */
/* @0xca65c mov r1, #1 */
/* @0xca660 pop {r4, lr} */
/* @0xca664 add r0, pc, r0 */
/* @0xca668 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xca66c .word 0x002678dc */
/* @0xca670 .word 0x002678f8 */
/* @0xca674 eoreq r7, r6, r12, lsr #17 */

/* ── FUNC 0xca678 · Setup_VertexBufferFunctions(bool) · size=808 · insn=202 */
/* @0xca678 push {r3, r4, r5, lr} */
/* @0xca67c cmp r0, #0 */
/* @0xca680 ldr r4, [pc, #0x23c] */
/* @0xca684 add r4, pc, r4 */
/* @0xca688 bne 0xca7a8 <_Z27Setup_VertexBufferFunctionsb+0x130> */
/* @0xca68c ldr r3, [pc, #0x234] */
/* @0xca690 ldr r0, [pc, #0x234] */
/* @0xca694 ldr r1, [r4, r3] */
/* @0xca698 add r0, pc, r0 */
/* @0xca69c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca6a0 ldr r3, [pc, #0x228] */
/* @0xca6a4 ldr r0, [pc, #0x228] */
/* @0xca6a8 ldr r1, [r4, r3] */
/* @0xca6ac add r0, pc, r0 */
/* @0xca6b0 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca6b4 ldr r3, [pc, #0x21c] */
/* @0xca6b8 ldr r0, [pc, #0x21c] */
/* @0xca6bc ldr r5, [r4, r3] */
/* @0xca6c0 add r0, pc, r0 */
/* @0xca6c4 mov r1, r5 */
/* @0xca6c8 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca6cc ldr r0, [pc, #0x20c] */
/* @0xca6d0 mov r1, r5 */
/* @0xca6d4 add r0, pc, r0 */
/* @0xca6d8 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca6dc ldr r3, [pc, #0x200] */
/* @0xca6e0 ldr r0, [pc, #0x200] */
/* @0xca6e4 ldr r1, [r4, r3] */
/* @0xca6e8 add r0, pc, r0 */
/* @0xca6ec bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca6f0 ldr r3, [pc, #0x1f4] */
/* @0xca6f4 ldr r0, [pc, #0x1f4] */
/* @0xca6f8 ldr r1, [r4, r3] */
/* @0xca6fc add r0, pc, r0 */
/* @0xca700 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca704 ldr r3, [pc, #0x1e8] */
/* @0xca708 ldr r0, [pc, #0x1e8] */
/* @0xca70c ldr r1, [r4, r3] */
/* @0xca710 add r0, pc, r0 */
/* @0xca714 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca718 ldr r3, [pc, #0x1dc] */
/* @0xca71c ldr r0, [pc, #0x1dc] */
/* @0xca720 ldr r1, [r4, r3] */
/* @0xca724 add r0, pc, r0 */
/* @0xca728 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca72c ldr r3, [pc, #0x1d0] */
/* @0xca730 ldr r0, [pc, #0x1d0] */
/* @0xca734 ldr r1, [r4, r3] */
/* @0xca738 add r0, pc, r0 */
/* @0xca73c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca740 ldr r3, [pc, #0x1c4] */
/* @0xca744 ldr r0, [pc, #0x1c4] */
/* @0xca748 ldr r1, [r4, r3] */
/* @0xca74c add r0, pc, r0 */
/* @0xca750 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca754 ldr r3, [pc, #0x1b8] */
/* @0xca758 ldr r0, [pc, #0x1b8] */
/* @0xca75c ldr r1, [r4, r3] */
/* @0xca760 add r0, pc, r0 */
/* @0xca764 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca768 ldr r3, [pc, #0x1ac] */
/* @0xca76c ldr r0, [pc, #0x1ac] */
/* @0xca770 ldr r1, [r4, r3] */
/* @0xca774 add r0, pc, r0 */
/* @0xca778 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca77c ldr r3, [pc, #0x1a0] */
/* @0xca780 ldr r0, [pc, #0x1a0] */
/* @0xca784 ldr r1, [r4, r3] */
/* @0xca788 add r0, pc, r0 */
/* @0xca78c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca790 ldr r3, [pc, #0x194] */
/* @0xca794 ldr r0, [pc, #0x194] */
/* @0xca798 ldr r1, [r4, r3] */
/* @0xca79c add r0, pc, r0 */
/* @0xca7a0 pop {r3, r4, r5, lr} */
/* @0xca7a4 b 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca7a8 ldr r3, [pc, #0x184] */
/* @0xca7ac ldr r0, [pc, #0x184] */
/* @0xca7b0 ldr r1, [r4, r3] */
/* @0xca7b4 add r0, pc, r0 */
/* @0xca7b8 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca7bc ldr r3, [pc, #0x178] */
/* @0xca7c0 ldr r0, [pc, #0x178] */
/* @0xca7c4 ldr r1, [r4, r3] */
/* @0xca7c8 add r0, pc, r0 */
/* @0xca7cc bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca7d0 ldr r3, [pc, #0x16c] */
/* @0xca7d4 ldr r0, [pc, #0x16c] */
/* @0xca7d8 ldr r5, [r4, r3] */
/* @0xca7dc add r0, pc, r0 */
/* @0xca7e0 mov r1, r5 */
/* @0xca7e4 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca7e8 ldr r0, [pc, #0x15c] */
/* @0xca7ec mov r1, r5 */
/* @0xca7f0 add r0, pc, r0 */
/* @0xca7f4 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca7f8 ldr r3, [pc, #0x150] */
/* @0xca7fc ldr r0, [pc, #0x150] */
/* @0xca800 ldr r1, [r4, r3] */
/* @0xca804 add r0, pc, r0 */
/* @0xca808 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca80c ldr r3, [pc, #0x144] */
/* @0xca810 ldr r0, [pc, #0x144] */
/* @0xca814 ldr r1, [r4, r3] */
/* @0xca818 add r0, pc, r0 */
/* @0xca81c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca820 ldr r3, [pc, #0x138] */
/* @0xca824 ldr r0, [pc, #0x138] */
/* @0xca828 ldr r1, [r4, r3] */
/* @0xca82c add r0, pc, r0 */
/* @0xca830 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca834 ldr r3, [pc, #0x12c] */
/* @0xca838 ldr r0, [pc, #0x12c] */
/* @0xca83c ldr r1, [r4, r3] */
/* @0xca840 add r0, pc, r0 */
/* @0xca844 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca848 ldr r3, [pc, #0x120] */
/* @0xca84c ldr r0, [pc, #0x120] */
/* @0xca850 ldr r1, [r4, r3] */
/* @0xca854 add r0, pc, r0 */
/* @0xca858 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca85c ldr r3, [pc, #0x114] */
/* @0xca860 ldr r0, [pc, #0x114] */
/* @0xca864 ldr r1, [r4, r3] */
/* @0xca868 add r0, pc, r0 */
/* @0xca86c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca870 ldr r3, [pc, #0x108] */
/* @0xca874 ldr r0, [pc, #0x108] */
/* @0xca878 ldr r1, [r4, r3] */
/* @0xca87c add r0, pc, r0 */
/* @0xca880 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca884 ldr r3, [pc, #0xfc] */
/* @0xca888 ldr r0, [pc, #0xfc] */
/* @0xca88c ldr r1, [r4, r3] */
/* @0xca890 add r0, pc, r0 */
/* @0xca894 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca898 ldr r3, [pc, #0xf0] */
/* @0xca89c ldr r0, [pc, #0xf0] */
/* @0xca8a0 ldr r1, [r4, r3] */
/* @0xca8a4 add r0, pc, r0 */
/* @0xca8a8 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca8ac ldr r3, [pc, #0xe4] */
/* @0xca8b0 ldr r0, [pc, #0xe4] */
/* @0xca8b4 ldr r1, [r4, r3] */
/* @0xca8b8 add r0, pc, r0 */
/* @0xca8bc pop {r3, r4, r5, lr} */
/* @0xca8c0 b 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0xca8c4 eorseq r7, r2, r12, asr #11 */
/* @0xca8c8 .word 0xffffbe2c */
/* @0xca8cc .word 0x002678dc */
/* @0xca8d0 .word 0xffffbe30 */
/* @0xca8d4 .word 0x002678d8 */
/* @0xca8d8 .word 0xffffbe34 */
/* @0xca8dc .word 0x002678d8 */
/* @0xca8e0 .word 0x002678d4 */
/* @0xca8e4 .word 0xffffbe38 */
/* @0xca8e8 .word 0x002678d0 */
/* @0xca8ec .word 0xffffbe3c */
/* @0xca8f0 eoreq r7, r6, r8, asr #17 */
/* @0xca8f4 .word 0xffffbe40 */
/* @0xca8f8 eoreq r7, r6, r4, asr #17 */
/* @0xca8fc .word 0xffffbe44 */
/* @0xca900 eoreq r7, r6, r0, asr #17 */
/* @0xca904 .word 0xffffbe48 */
/* @0xca908 .word 0x002678bc */
/* @0xca90c .word 0xffffbe4c */
/* @0xca910 .word 0x002678b8 */
/* @0xca914 .word 0xffffbe50 */
/* @0xca918 .word 0x002678b4 */
/* @0xca91c .word 0xffffbe54 */
/* @0xca920 .word 0x002678b0 */
/* @0xca924 .word 0xffffbe58 */
/* @0xca928 eoreq r7, r6, r12, lsr #17 */
/* @0xca92c .word 0xffffbe5c */
/* @0xca930 eoreq r7, r6, r8, lsr #17 */
/* @0xca934 .word 0xffffbe60 */
/* @0xca938 eoreq r7, r6, r0, asr #15 */
/* @0xca93c .word 0xffffbe64 */
/* @0xca940 .word 0x002677bc */
/* @0xca944 .word 0xffffbe68 */
/* @0xca948 .word 0x002677bc */
/* @0xca94c .word 0x002677b8 */
/* @0xca950 .word 0xffffbe6c */
/* @0xca954 .word 0x002677b4 */
/* @0xca958 .word 0xffffbe70 */
/* @0xca95c eoreq r7, r6, r12, lsr #15 */
/* @0xca960 .word 0xffffbe74 */
/* @0xca964 eoreq r7, r6, r8, lsr #15 */
/* @0xca968 .word 0xffffbe78 */
/* @0xca96c eoreq r7, r6, r4, lsr #15 */
/* @0xca970 .word 0xffffbe7c */
/* @0xca974 eoreq r7, r6, r0, lsr #15 */
/* @0xca978 .word 0xffffbe80 */
/* @0xca97c mlaeq r6, r12, r7, r7 */
/* @0xca980 .word 0xffffbe84 */
/* @0xca984 mlaeq r6, r8, r7, r7 */
/* @0xca988 .word 0xffffbe88 */
/* @0xca98c mlaeq r6, r4, r7, r7 */
/* @0xca990 .word 0xffffbe8c */
/* @0xca994 mlaeq r6, r0, r7, r7 */
/* @0xca998 .word 0xffffbe90 */
/* @0xca99c eoreq r7, r6, r12, lsl #15 */

/* ── FUNC 0xca9a0 · InitBufferVertexFunctions() · size=844 · insn=211 */
/* @0xca9a0 push {r4, r5, r6, lr} */
/* @0xca9a4 mov r2, #0 */
/* @0xca9a8 ldr r4, [pc, #0x284] */
/* @0xca9ac mov r3, r2 */
/* @0xca9b0 ldr r1, [pc, #0x280] */
/* @0xca9b4 add r4, pc, r4 */
/* @0xca9b8 ldr r0, [pc, #0x27c] */
/* @0xca9bc ldr r1, [r4, r1] */
/* @0xca9c0 add r0, pc, r0 */
/* @0xca9c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xca9c8 ldr r1, [pc, #0x270] */
/* @0xca9cc ldr r0, [pc, #0x270] */
/* @0xca9d0 mov r2, #1 */
/* @0xca9d4 mov r3, #0 */
/* @0xca9d8 ldr r1, [r4, r1] */
/* @0xca9dc add r0, pc, r0 */
/* @0xca9e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xca9e4 ldr r1, [pc, #0x25c] */
/* @0xca9e8 ldr r0, [pc, #0x25c] */
/* @0xca9ec mov r2, #1 */
/* @0xca9f0 mov r3, #0 */
/* @0xca9f4 ldr r1, [r4, r1] */
/* @0xca9f8 add r0, pc, r0 */
/* @0xca9fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaa00 ldr r1, [pc, #0x248] */
/* @0xcaa04 ldr r0, [pc, #0x248] */
/* @0xcaa08 mov r2, #2 */
/* @0xcaa0c mov r3, #0 */
/* @0xcaa10 ldr r1, [r4, r1] */
/* @0xcaa14 add r0, pc, r0 */
/* @0xcaa18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaa1c ldr r1, [pc, #0x234] */
/* @0xcaa20 ldr r0, [pc, #0x234] */
/* @0xcaa24 mov r2, #1 */
/* @0xcaa28 mov r3, #0 */
/* @0xcaa2c ldr r1, [r4, r1] */
/* @0xcaa30 add r0, pc, r0 */
/* @0xcaa34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaa38 ldr r1, [pc, #0x220] */
/* @0xcaa3c ldr r0, [pc, #0x220] */
/* @0xcaa40 mov r2, #3 */
/* @0xcaa44 mov r3, #0 */
/* @0xcaa48 ldr r1, [r4, r1] */
/* @0xcaa4c add r0, pc, r0 */
/* @0xcaa50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaa54 ldr r1, [pc, #0x20c] */
/* @0xcaa58 ldr r0, [pc, #0x20c] */
/* @0xcaa5c mov r2, #4 */
/* @0xcaa60 mov r3, #0 */
/* @0xcaa64 ldr r1, [r4, r1] */
/* @0xcaa68 add r0, pc, r0 */
/* @0xcaa6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaa70 ldr r1, [pc, #0x1f8] */
/* @0xcaa74 ldr r0, [pc, #0x1f8] */
/* @0xcaa78 mov r2, #3 */
/* @0xcaa7c mov r3, #0 */
/* @0xcaa80 ldr r5, [r4, r1] */
/* @0xcaa84 add r0, pc, r0 */
/* @0xcaa88 mov r1, r5 */
/* @0xcaa8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaa90 ldr r0, [pc, #0x1e0] */
/* @0xcaa94 mov r1, r5 */
/* @0xcaa98 mov r2, #3 */
/* @0xcaa9c add r0, pc, r0 */
/* @0xcaaa0 mov r3, #0 */
/* @0xcaaa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaaa8 ldr r1, [pc, #0x1cc] */
/* @0xcaaac ldr r0, [pc, #0x1cc] */
/* @0xcaab0 mov r2, #2 */
/* @0xcaab4 mov r3, #0 */
/* @0xcaab8 ldr r1, [r4, r1] */
/* @0xcaabc add r0, pc, r0 */
/* @0xcaac0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaac4 ldr r1, [pc, #0x1b8] */
/* @0xcaac8 ldr r0, [pc, #0x1b8] */
/* @0xcaacc mov r2, #3 */
/* @0xcaad0 mov r3, #0 */
/* @0xcaad4 ldr r1, [r4, r1] */
/* @0xcaad8 add r0, pc, r0 */
/* @0xcaadc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaae0 ldr r1, [pc, #0x1a4] */
/* @0xcaae4 ldr r0, [pc, #0x1a4] */
/* @0xcaae8 mov r2, #4 */
/* @0xcaaec mov r3, #0 */
/* @0xcaaf0 ldr r1, [r4, r1] */
/* @0xcaaf4 add r0, pc, r0 */
/* @0xcaaf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaafc ldr r1, [pc, #0x190] */
/* @0xcab00 ldr r0, [pc, #0x190] */
/* @0xcab04 mov r2, #2 */
/* @0xcab08 mov r3, #0 */
/* @0xcab0c ldr r1, [r4, r1] */
/* @0xcab10 add r0, pc, r0 */
/* @0xcab14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcab18 ldr r1, [pc, #0x17c] */
/* @0xcab1c ldr r0, [pc, #0x17c] */
/* @0xcab20 mov r2, #3 */
/* @0xcab24 mov r3, #0 */
/* @0xcab28 ldr r1, [r4, r1] */
/* @0xcab2c add r0, pc, r0 */
/* @0xcab30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcab34 ldr r1, [pc, #0x168] */
/* @0xcab38 ldr r0, [pc, #0x168] */
/* @0xcab3c mov r2, #4 */
/* @0xcab40 mov r3, #0 */
/* @0xcab44 ldr r1, [r4, r1] */
/* @0xcab48 add r0, pc, r0 */
/* @0xcab4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcab50 ldr r1, [pc, #0x154] */
/* @0xcab54 ldr r0, [pc, #0x154] */
/* @0xcab58 mov r2, #5 */
/* @0xcab5c mov r3, #0 */
/* @0xcab60 ldr r1, [r4, r1] */
/* @0xcab64 add r0, pc, r0 */
/* @0xcab68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcab6c ldr r1, [pc, #0x140] */
/* @0xcab70 ldr r0, [pc, #0x140] */
/* @0xcab74 mov r2, #5 */
/* @0xcab78 mov r3, #0 */
/* @0xcab7c ldr r1, [r4, r1] */
/* @0xcab80 add r0, pc, r0 */
/* @0xcab84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcab88 ldr r1, [pc, #0x12c] */
/* @0xcab8c ldr r0, [pc, #0x12c] */
/* @0xcab90 mov r2, #3 */
/* @0xcab94 mov r3, #0 */
/* @0xcab98 ldr r1, [r4, r1] */
/* @0xcab9c add r0, pc, r0 */
/* @0xcaba0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcaba4 ldr r1, [pc, #0x118] */
/* @0xcaba8 ldr r0, [pc, #0x118] */
/* @0xcabac mov r2, #1 */
/* @0xcabb0 mov r3, #0 */
/* @0xcabb4 ldr r1, [r4, r1] */
/* @0xcabb8 add r0, pc, r0 */
/* @0xcabbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcabc0 ldr r1, [pc, #0x104] */
/* @0xcabc4 ldr r0, [pc, #0x104] */
/* @0xcabc8 mov r2, #1 */
/* @0xcabcc mov r3, #0 */
/* @0xcabd0 ldr r1, [r4, r1] */
/* @0xcabd4 add r0, pc, r0 */
/* @0xcabd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcabdc ldr r1, [pc, #0xf0] */
/* @0xcabe0 ldr r0, [pc, #0xf0] */
/* @0xcabe4 mov r2, #1 */
/* @0xcabe8 mov r3, #0 */
/* @0xcabec ldr r1, [r4, r1] */
/* @0xcabf0 add r0, pc, r0 */
/* @0xcabf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcabf8 ldr r1, [pc, #0xdc] */
/* @0xcabfc ldr r0, [pc, #0xdc] */
/* @0xcac00 mov r2, #2 */
/* @0xcac04 mov r3, #0 */
/* @0xcac08 ldr r1, [r4, r1] */
/* @0xcac0c add r0, pc, r0 */
/* @0xcac10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcac14 ldr r1, [pc, #0xc8] */
/* @0xcac18 ldr r0, [pc, #0xc8] */
/* @0xcac1c mov r2, #4 */
/* @0xcac20 mov r3, #0 */
/* @0xcac24 ldr r1, [r4, r1] */
/* @0xcac28 add r0, pc, r0 */
/* @0xcac2c pop {r4, r5, r6, lr} */
/* @0xcac30 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0xcac34 mlaseq r2, r12, r2, r7 */
/* @0xcac38 .word 0xffffbe94 */
/* @0xcac3c mlaeq r6, r4, r6, r7 */
/* @0xcac40 .word 0xffffbe98 */
/* @0xcac44 mlaeq r6, r0, r6, r7 */
/* @0xcac48 .word 0xffffbe9c */
/* @0xcac4c mlaeq r6, r0, r6, r7 */
/* @0xcac50 .word 0xffffbea0 */
/* @0xcac54 eoreq r7, r6, r12, lsl #13 */
/* @0xcac58 .word 0xffffbea4 */
/* @0xcac5c eoreq r7, r6, r0, lsl #13 */
/* @0xcac60 .word 0xffffbe60 */
/* @0xcac64 eoreq r7, r6, r8, lsr #10 */
/* @0xcac68 .word 0xffffbe64 */
/* @0xcac6c eoreq r7, r6, r12, lsl r5 */
/* @0xcac70 .word 0xffffbe68 */
/* @0xcac74 eoreq r7, r6, r4, lsl r5 */
/* @0xcac78 eoreq r7, r6, r12, lsl #10 */
/* @0xcac7c .word 0xffffbe6c */
/* @0xcac80 .word 0x002674fc */
/* @0xcac84 .word 0xffffbe70 */
/* @0xcac88 eoreq r7, r6, r12, ror #9 */
/* @0xcac8c .word 0xffffbe74 */
/* @0xcac90 eoreq r7, r6, r0, ror #9 */
/* @0xcac94 .word 0xffffbe78 */
/* @0xcac98 .word 0x002674d4 */
/* @0xcac9c .word 0xffffbe7c */
/* @0xcaca0 eoreq r7, r6, r8, asr #9 */
/* @0xcaca4 .word 0xffffbe80 */
/* @0xcaca8 .word 0x002674bc */
/* @0xcacac .word 0xffffbe84 */
/* @0xcacb0 .word 0x002674b0 */
/* @0xcacb4 .word 0xffffbe88 */
/* @0xcacb8 eoreq r7, r6, r4, lsr #9 */
/* @0xcacbc .word 0xffffbe8c */
/* @0xcacc0 mlaeq r6, r8, r4, r7 */
/* @0xcacc4 .word 0xffffbe90 */
/* @0xcacc8 eoreq r7, r6, r12, lsl #9 */
/* @0xcaccc .word 0xffffbea8 */
/* @0xcacd0 eoreq r7, r6, r8, ror #9 */
/* @0xcacd4 .word 0xffffbeac */
/* @0xcacd8 eoreq r7, r6, r0, ror #9 */
/* @0xcacdc .word 0xffffbeb0 */
/* @0xcace0 .word 0x002674dc */
/* @0xcace4 .word 0xffffbeb4 */
/* @0xcace8 eoreq r7, r6, r4, ror #9 */

/* ── FUNC 0xcacec · Buffer_Network::~Buffer_Network() · size=40 · insn=10 */
/* @0xcacec ldr r3, [pc, #0x1c] */
/* @0xcacf0 push {r4, lr} */
/* @0xcacf4 ldr r3, [pc, r3] */
/* @0xcacf8 mov r4, r0 */
/* @0xcacfc add r3, r3, #8 */
/* @0xcad00 str r3, [r0] */
/* @0xcad04 bl 0xcb818 <_ZN7IBufferD2Ev> */
/* @0xcad08 mov r0, r4 */
/* @0xcad0c pop {r4, pc} */
/* @0xcad10 eorseq r2, r2, r4, lsl lr */
