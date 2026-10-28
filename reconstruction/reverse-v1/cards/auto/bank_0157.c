/* libyoyo.so 覆盖卡组 0157
 * 函数 0x1d5244..0x1d55ec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1d5244 · anon_1d5244 · size=4 · insn=1 */
/* @0x1d5244 nop */

/* ── FUNC 0x1d5248 · F_GestureGetRotateAngle(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1d5248 ldr r3, [pc, #0x1c] */
/* @0x1d524c mov r2, #0 */
/* @0x1d5250 str r2, [r0, #0xc] */
/* @0x1d5254 ldr r3, [pc, r3] */
/* @0x1d5258 vldr s15, [r3] */
/* @0x1d525c vcvt.f64.f32 d6, s15 */
/* @0x1d5260 vmov r2, r3, d6 */
/* @0x1d5264 stm r0, {r2, r3} */
/* @0x1d5268 bx lr */
/* @0x1d526c mlaeq r1, r4, r9, r11 */

/* ── FUNC 0x1d5270 · F_GestureGetTapCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1d5270 ldr r3, [pc, #0x28] */
/* @0x1d5274 mov r2, #0 */
/* @0x1d5278 str r2, [r0, #0xc] */
/* @0x1d527c ldr r3, [pc, r3] */
/* @0x1d5280 ldrb r3, [r3] */
/* @0x1d5284 cmp r3, r2 */
/* @0x1d5288 movne r3, r2 */
/* @0x1d528c moveq r2, r3 */
/* @0x1d5290 movtne r2, #0x3ff0 */
/* @0x1d5294 str r3, [r0] */
/* @0x1d5298 str r2, [r0, #0x4] */
/* @0x1d529c bx lr */
/* @0x1d52a0 eoreq r11, r1, r0, ror r9 */

/* ── FUNC 0x1d52a4 · CGesture::~CGesture() · size=52 · insn=13 */
/* @0x1d52a4 push {r4, lr} */
/* @0x1d52a8 mov r4, r0 */
/* @0x1d52ac ldr r0, [r0, #0xc] */
/* @0x1d52b0 ldr r3, [pc, #0x1c] */
/* @0x1d52b4 cmp r0, #0 */
/* @0x1d52b8 ldr r3, [pc, r3] */
/* @0x1d52bc add r3, r3, #8 */
/* @0x1d52c0 str r3, [r4] */
/* @0x1d52c4 beq 0x1d52cc <_ZN8CGestureD2Ev+0x28> */
/* @0x1d52c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d52cc mov r0, r4 */
/* @0x1d52d0 pop {r4, pc} */
/* @0x1d52d4 eoreq r11, r1, r8, lsr r9 */

/* ── FUNC 0x1d52a4 · CGesture::~CGesture() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d52d8 · CGesture::~CGesture() · size=28 · insn=7 */
/* @0x1d52d8 push {r4, lr} */
/* @0x1d52dc mov r4, r0 */
/* @0x1d52e0 bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d52e4 mov r0, r4 */
/* @0x1d52e8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d52ec mov r0, r4 */
/* @0x1d52f0 pop {r4, pc} */

/* ── FUNC 0x1d52f4 · CSingleFingerGesture::~CSingleFingerGesture() · size=40 · insn=10 */
/* @0x1d52f4 ldr r3, [pc, #0x1c] */
/* @0x1d52f8 push {r4, lr} */
/* @0x1d52fc ldr r3, [pc, r3] */
/* @0x1d5300 mov r4, r0 */
/* @0x1d5304 add r3, r3, #8 */
/* @0x1d5308 str r3, [r0] */
/* @0x1d530c bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5310 mov r0, r4 */
/* @0x1d5314 pop {r4, pc} */
/* @0x1d5318 .word 0x0021b8f8 */

/* ── FUNC 0x1d52f4 · CSingleFingerGesture::~CSingleFingerGesture() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d531c · CSingleFingerGesture::~CSingleFingerGesture() · size=48 · insn=12 */
/* @0x1d531c ldr r3, [pc, #0x24] */
/* @0x1d5320 push {r4, lr} */
/* @0x1d5324 ldr r3, [pc, r3] */
/* @0x1d5328 mov r4, r0 */
/* @0x1d532c add r3, r3, #8 */
/* @0x1d5330 str r3, [r0] */
/* @0x1d5334 bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5338 mov r0, r4 */
/* @0x1d533c bl 0x27d1d0 <_ZdlPv> */
/* @0x1d5340 mov r0, r4 */
/* @0x1d5344 pop {r4, pc} */
/* @0x1d5348 .word 0x0021b8d0 */

/* ── FUNC 0x1d534c · CGestureUnknown::~CGestureUnknown() · size=40 · insn=10 */
/* @0x1d534c ldr r3, [pc, #0x1c] */
/* @0x1d5350 push {r4, lr} */
/* @0x1d5354 ldr r3, [pc, r3] */
/* @0x1d5358 mov r4, r0 */
/* @0x1d535c add r3, r3, #8 */
/* @0x1d5360 str r3, [r0] */
/* @0x1d5364 bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5368 mov r0, r4 */
/* @0x1d536c pop {r4, pc} */
/* @0x1d5370 eoreq r11, r1, r0, lsr #17 */

/* ── FUNC 0x1d534c · CGestureUnknown::~CGestureUnknown() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d5374 · CGestureUnknown::~CGestureUnknown() · size=48 · insn=12 */
/* @0x1d5374 ldr r3, [pc, #0x24] */
/* @0x1d5378 push {r4, lr} */
/* @0x1d537c ldr r3, [pc, r3] */
/* @0x1d5380 mov r4, r0 */
/* @0x1d5384 add r3, r3, #8 */
/* @0x1d5388 str r3, [r0] */
/* @0x1d538c bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5390 mov r0, r4 */
/* @0x1d5394 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d5398 mov r0, r4 */
/* @0x1d539c pop {r4, pc} */
/* @0x1d53a0 eoreq r11, r1, r8, ror r8 */

/* ── FUNC 0x1d53a4 · CGestureTap::~CGestureTap() · size=40 · insn=10 */
/* @0x1d53a4 ldr r3, [pc, #0x1c] */
/* @0x1d53a8 push {r4, lr} */
/* @0x1d53ac ldr r3, [pc, r3] */
/* @0x1d53b0 mov r4, r0 */
/* @0x1d53b4 add r3, r3, #8 */
/* @0x1d53b8 str r3, [r0] */
/* @0x1d53bc bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d53c0 mov r0, r4 */
/* @0x1d53c4 pop {r4, pc} */
/* @0x1d53c8 eoreq r11, r1, r8, asr #16 */

/* ── FUNC 0x1d53a4 · CGestureTap::~CGestureTap() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d53cc · CGestureTap::~CGestureTap() · size=48 · insn=12 */
/* @0x1d53cc ldr r3, [pc, #0x24] */
/* @0x1d53d0 push {r4, lr} */
/* @0x1d53d4 ldr r3, [pc, r3] */
/* @0x1d53d8 mov r4, r0 */
/* @0x1d53dc add r3, r3, #8 */
/* @0x1d53e0 str r3, [r0] */
/* @0x1d53e4 bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d53e8 mov r0, r4 */
/* @0x1d53ec bl 0x27d1d0 <_ZdlPv> */
/* @0x1d53f0 mov r0, r4 */
/* @0x1d53f4 pop {r4, pc} */
/* @0x1d53f8 eoreq r11, r1, r0, lsr #16 */

/* ── FUNC 0x1d53fc · CGestureDoubleTap::~CGestureDoubleTap() · size=40 · insn=10 */
/* @0x1d53fc ldr r3, [pc, #0x1c] */
/* @0x1d5400 push {r4, lr} */
/* @0x1d5404 ldr r3, [pc, r3] */
/* @0x1d5408 mov r4, r0 */
/* @0x1d540c add r3, r3, #8 */
/* @0x1d5410 str r3, [r0] */
/* @0x1d5414 bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5418 mov r0, r4 */
/* @0x1d541c pop {r4, pc} */
/* @0x1d5420 .word 0x0021b7f0 */

/* ── FUNC 0x1d53fc · CGestureDoubleTap::~CGestureDoubleTap() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d5424 · CGestureDoubleTap::~CGestureDoubleTap() · size=48 · insn=12 */
/* @0x1d5424 ldr r3, [pc, #0x24] */
/* @0x1d5428 push {r4, lr} */
/* @0x1d542c ldr r3, [pc, r3] */
/* @0x1d5430 mov r4, r0 */
/* @0x1d5434 add r3, r3, #8 */
/* @0x1d5438 str r3, [r0] */
/* @0x1d543c bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5440 mov r0, r4 */
/* @0x1d5444 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d5448 mov r0, r4 */
/* @0x1d544c pop {r4, pc} */
/* @0x1d5450 eoreq r11, r1, r8, asr #15 */

/* ── FUNC 0x1d5454 · CGestureDrag::~CGestureDrag() · size=40 · insn=10 */
/* @0x1d5454 ldr r3, [pc, #0x1c] */
/* @0x1d5458 push {r4, lr} */
/* @0x1d545c ldr r3, [pc, r3] */
/* @0x1d5460 mov r4, r0 */
/* @0x1d5464 add r3, r3, #8 */
/* @0x1d5468 str r3, [r0] */
/* @0x1d546c bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5470 mov r0, r4 */
/* @0x1d5474 pop {r4, pc} */
/* @0x1d5478 mlaeq r1, r8, r7, r11 */

/* ── FUNC 0x1d5454 · CGestureDrag::~CGestureDrag() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d547c · CGestureDrag::~CGestureDrag() · size=48 · insn=12 */
/* @0x1d547c ldr r3, [pc, #0x24] */
/* @0x1d5480 push {r4, lr} */
/* @0x1d5484 ldr r3, [pc, r3] */
/* @0x1d5488 mov r4, r0 */
/* @0x1d548c add r3, r3, #8 */
/* @0x1d5490 str r3, [r0] */
/* @0x1d5494 bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5498 mov r0, r4 */
/* @0x1d549c bl 0x27d1d0 <_ZdlPv> */
/* @0x1d54a0 mov r0, r4 */
/* @0x1d54a4 pop {r4, pc} */
/* @0x1d54a8 eoreq r11, r1, r0, ror r7 */

/* ── FUNC 0x1d54ac · CGesturePinch::~CGesturePinch() · size=40 · insn=10 */
/* @0x1d54ac ldr r3, [pc, #0x1c] */
/* @0x1d54b0 push {r4, lr} */
/* @0x1d54b4 ldr r3, [pc, r3] */
/* @0x1d54b8 mov r4, r0 */
/* @0x1d54bc add r3, r3, #8 */
/* @0x1d54c0 str r3, [r0] */
/* @0x1d54c4 bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d54c8 mov r0, r4 */
/* @0x1d54cc pop {r4, pc} */
/* @0x1d54d0 eoreq r11, r1, r4, asr #14 */

/* ── FUNC 0x1d54ac · CGesturePinch::~CGesturePinch() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d54d4 · CGesturePinch::~CGesturePinch() · size=48 · insn=12 */
/* @0x1d54d4 ldr r3, [pc, #0x24] */
/* @0x1d54d8 push {r4, lr} */
/* @0x1d54dc ldr r3, [pc, r3] */
/* @0x1d54e0 mov r4, r0 */
/* @0x1d54e4 add r3, r3, #8 */
/* @0x1d54e8 str r3, [r0] */
/* @0x1d54ec bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d54f0 mov r0, r4 */
/* @0x1d54f4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d54f8 mov r0, r4 */
/* @0x1d54fc pop {r4, pc} */
/* @0x1d5500 eoreq r11, r1, r12, lsl r7 */

/* ── FUNC 0x1d5504 · CGestureRotate::~CGestureRotate() · size=40 · insn=10 */
/* @0x1d5504 ldr r3, [pc, #0x1c] */
/* @0x1d5508 push {r4, lr} */
/* @0x1d550c ldr r3, [pc, r3] */
/* @0x1d5510 mov r4, r0 */
/* @0x1d5514 add r3, r3, #8 */
/* @0x1d5518 str r3, [r0] */
/* @0x1d551c bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5520 mov r0, r4 */
/* @0x1d5524 pop {r4, pc} */
/* @0x1d5528 .word 0x0021b6f0 */

/* ── FUNC 0x1d5504 · CGestureRotate::~CGestureRotate() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d552c · CGestureRotate::~CGestureRotate() · size=48 · insn=12 */
/* @0x1d552c ldr r3, [pc, #0x24] */
/* @0x1d5530 push {r4, lr} */
/* @0x1d5534 ldr r3, [pc, r3] */
/* @0x1d5538 mov r4, r0 */
/* @0x1d553c add r3, r3, #8 */
/* @0x1d5540 str r3, [r0] */
/* @0x1d5544 bl 0x1d52a4 <_ZN8CGestureD2Ev> */
/* @0x1d5548 mov r0, r4 */
/* @0x1d554c bl 0x27d1d0 <_ZdlPv> */
/* @0x1d5550 mov r0, r4 */
/* @0x1d5554 pop {r4, pc} */
/* @0x1d5558 eoreq r11, r1, r8, asr #13 */

/* ── FUNC 0x1d555c · anon_1d555c · size=4 · insn=1 */
/* @0x1d555c andeq r0, r0, r0 */

/* ── FUNC 0x1d5560 · F_GestureDragTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1d5560 push {r4, lr} */
/* @0x1d5564 mov r1, #0 */
/* @0x1d5568 ldr r0, [sp, #0x8] */
/* @0x1d556c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1d5570 vldr d7, [pc, #32] */
/* @0x1d5574 ldr r4, [pc, #0x24] */
/* @0x1d5578 ldr r4, [pc, r4] */
/* @0x1d557c vmov d6, r0, r1 */
/* @0x1d5580 vmul.f64 d6, d6, d7 */
/* @0x1d5584 vmov r0, r1, d6 */
/* @0x1d5588 bl 0x3194a0 <__fixdfdi> */
/* @0x1d558c strd r0, r1, [r4] */
/* @0x1d5590 pop {r4, pc} */
/* @0x1d5594 nop */
/* @0x1d5598 andeq r0, r0, r0 */
/* @0x1d559c smlawbmi lr, r0, r4, r8 */
/* @0x1d55a0 eoreq r11, r1, r12, asr #12 */

/* ── FUNC 0x1d55a4 · anon_1d55a4 · size=4 · insn=1 */
/* @0x1d55a4 nop */

/* ── FUNC 0x1d55a8 · F_GestureDoubleTapTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1d55a8 push {r4, lr} */
/* @0x1d55ac mov r1, #0 */
/* @0x1d55b0 ldr r0, [sp, #0x8] */
/* @0x1d55b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1d55b8 vldr d7, [pc, #32] */
/* @0x1d55bc ldr r4, [pc, #0x24] */
/* @0x1d55c0 ldr r4, [pc, r4] */
/* @0x1d55c4 vmov d6, r0, r1 */
/* @0x1d55c8 vmul.f64 d6, d6, d7 */
/* @0x1d55cc vmov r0, r1, d6 */
/* @0x1d55d0 bl 0x3194a0 <__fixdfdi> */
/* @0x1d55d4 strd r0, r1, [r4] */
/* @0x1d55d8 pop {r4, pc} */
/* @0x1d55dc nop */
/* @0x1d55e0 andeq r0, r0, r0 */
/* @0x1d55e4 ldrdmi r1, r2, [r3, #-32]! */
/* @0x1d55e8 eoreq r11, r1, r0, lsl r6 */

/* ── FUNC 0x1d55ec · anon_1d55ec · size=4 · insn=1 */
/* @0x1d55ec nop */
