/* libyoyo.so 覆盖卡组 0057
 * 函数 0x129210..0x129bc0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x129210 · F_PartTypeSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x129210 push {r4, r5, r6, r7, r8, lr} */
/* @0x129214 mov r1, #0 */
/* @0x129218 ldr r4, [sp, #0x18] */
/* @0x12921c mov r0, r4 */
/* @0x129220 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129224 mov r1, #1 */
/* @0x129228 mov r5, r0 */
/* @0x12922c mov r0, r4 */
/* @0x129230 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129234 mov r1, #2 */
/* @0x129238 mov r8, r0 */
/* @0x12923c mov r0, r4 */
/* @0x129240 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129244 mov r1, #3 */
/* @0x129248 mov r7, r0 */
/* @0x12924c mov r0, r4 */
/* @0x129250 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129254 mov r1, #4 */
/* @0x129258 mov r6, r0 */
/* @0x12925c mov r0, r4 */
/* @0x129260 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129264 mov r1, r8 */
/* @0x129268 mov r2, r7 */
/* @0x12926c mov r3, r6 */
/* @0x129270 str r0, [sp, #0x18] */
/* @0x129274 mov r0, r5 */
/* @0x129278 pop {r4, r5, r6, r7, r8, lr} */
/* @0x12927c b 0x1a3368 <_Z18ParticleType_Speediffff> */

/* ── FUNC 0x129280 · F_PartTypeDirection(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x129280 push {r4, r5, r6, r7, r8, lr} */
/* @0x129284 mov r1, #0 */
/* @0x129288 ldr r4, [sp, #0x18] */
/* @0x12928c mov r0, r4 */
/* @0x129290 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129294 mov r1, #1 */
/* @0x129298 mov r5, r0 */
/* @0x12929c mov r0, r4 */
/* @0x1292a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1292a4 mov r1, #2 */
/* @0x1292a8 mov r8, r0 */
/* @0x1292ac mov r0, r4 */
/* @0x1292b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1292b4 mov r1, #3 */
/* @0x1292b8 mov r7, r0 */
/* @0x1292bc mov r0, r4 */
/* @0x1292c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1292c4 mov r1, #4 */
/* @0x1292c8 mov r6, r0 */
/* @0x1292cc mov r0, r4 */
/* @0x1292d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1292d4 mov r1, r8 */
/* @0x1292d8 mov r2, r7 */
/* @0x1292dc mov r3, r6 */
/* @0x1292e0 str r0, [sp, #0x18] */
/* @0x1292e4 mov r0, r5 */
/* @0x1292e8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1292ec b 0x1a33b4 <_Z22ParticleType_Directioniffff> */

/* ── FUNC 0x1292f0 · F_PartTypeOrientation(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1292f0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1292f4 sub sp, sp, #12 */
/* @0x1292f8 mov r1, #0 */
/* @0x1292fc ldr r4, [sp, #0x28] */
/* @0x129300 mov r0, r4 */
/* @0x129304 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129308 mov r1, #1 */
/* @0x12930c mov r5, r0 */
/* @0x129310 mov r0, r4 */
/* @0x129314 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129318 mov r1, #2 */
/* @0x12931c mov r8, r0 */
/* @0x129320 mov r0, r4 */
/* @0x129324 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129328 mov r1, #3 */
/* @0x12932c mov r7, r0 */
/* @0x129330 mov r0, r4 */
/* @0x129334 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129338 mov r1, #4 */
/* @0x12933c mov r6, r0 */
/* @0x129340 mov r0, r4 */
/* @0x129344 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129348 mov r1, #5 */
/* @0x12934c mov r9, r0 */
/* @0x129350 mov r0, r4 */
/* @0x129354 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129358 str r9, [sp] */
/* @0x12935c mov r1, r8 */
/* @0x129360 mov r2, r7 */
/* @0x129364 mov r3, r6 */
/* @0x129368 str r0, [sp, #0x4] */
/* @0x12936c mov r0, r5 */
/* @0x129370 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x129374 add sp, sp, #12 */
/* @0x129378 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x12937c · F_PartTypeGravity(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12937c push {r4, r5, r6, lr} */
/* @0x129380 mov r1, #0 */
/* @0x129384 ldr r4, [sp, #0x10] */
/* @0x129388 mov r0, r4 */
/* @0x12938c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129390 mov r1, #1 */
/* @0x129394 mov r6, r0 */
/* @0x129398 mov r0, r4 */
/* @0x12939c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1293a0 mov r1, #2 */
/* @0x1293a4 mov r5, r0 */
/* @0x1293a8 mov r0, r4 */
/* @0x1293ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1293b0 mov r1, r5 */
/* @0x1293b4 mov r2, r0 */
/* @0x1293b8 mov r0, r6 */
/* @0x1293bc pop {r4, r5, r6, lr} */
/* @0x1293c0 b 0x1a3454 <_Z20ParticleType_Gravityiff> */

/* ── FUNC 0x1293c4 · F_PartTypeColorMix(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1293c4 push {r4, r5, r6, lr} */
/* @0x1293c8 mov r1, #0 */
/* @0x1293cc ldr r4, [sp, #0x10] */
/* @0x1293d0 mov r0, r4 */
/* @0x1293d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1293d8 mov r1, #1 */
/* @0x1293dc mov r6, r0 */
/* @0x1293e0 mov r0, r4 */
/* @0x1293e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1293e8 mov r1, #2 */
/* @0x1293ec mov r5, r0 */
/* @0x1293f0 mov r0, r4 */
/* @0x1293f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1293f8 mov r1, r5 */
/* @0x1293fc mov r2, r0 */
/* @0x129400 mov r0, r6 */
/* @0x129404 pop {r4, r5, r6, lr} */
/* @0x129408 b 0x1a34f4 <_Z22ParticleType_Color_Mixijj> */

/* ── FUNC 0x12940c · F_PartTypeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x12940c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x129410 sub sp, sp, #16 */
/* @0x129414 mov r1, #0 */
/* @0x129418 ldr r4, [sp, #0x30] */
/* @0x12941c mov r0, r4 */
/* @0x129420 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129424 mov r1, #1 */
/* @0x129428 mov r5, r0 */
/* @0x12942c mov r0, r4 */
/* @0x129430 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129434 mov r1, #2 */
/* @0x129438 mov r8, r0 */
/* @0x12943c mov r0, r4 */
/* @0x129440 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129444 mov r1, #3 */
/* @0x129448 mov r7, r0 */
/* @0x12944c mov r0, r4 */
/* @0x129450 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129454 mov r1, #4 */
/* @0x129458 mov r6, r0 */
/* @0x12945c mov r0, r4 */
/* @0x129460 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129464 mov r1, #5 */
/* @0x129468 mov r10, r0 */
/* @0x12946c mov r0, r4 */
/* @0x129470 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129474 mov r1, #6 */
/* @0x129478 mov r9, r0 */
/* @0x12947c mov r0, r4 */
/* @0x129480 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129484 str r10, [sp] */
/* @0x129488 str r9, [sp, #0x4] */
/* @0x12948c mov r1, r8 */
/* @0x129490 mov r2, r7 */
/* @0x129494 mov r3, r6 */
/* @0x129498 str r0, [sp, #0x8] */
/* @0x12949c mov r0, r5 */
/* @0x1294a0 bl 0x1a3490 <_Z22ParticleType_Color_RGBiiiiiii> */
/* @0x1294a4 add sp, sp, #16 */
/* @0x1294a8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x1294ac · F_PartTypeColorHSV(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1294ac push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1294b0 sub sp, sp, #16 */
/* @0x1294b4 mov r1, #0 */
/* @0x1294b8 ldr r4, [sp, #0x30] */
/* @0x1294bc mov r0, r4 */
/* @0x1294c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1294c4 mov r1, #1 */
/* @0x1294c8 mov r5, r0 */
/* @0x1294cc mov r0, r4 */
/* @0x1294d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1294d4 mov r1, #2 */
/* @0x1294d8 mov r8, r0 */
/* @0x1294dc mov r0, r4 */
/* @0x1294e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1294e4 mov r1, #3 */
/* @0x1294e8 mov r7, r0 */
/* @0x1294ec mov r0, r4 */
/* @0x1294f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1294f4 mov r1, #4 */
/* @0x1294f8 mov r6, r0 */
/* @0x1294fc mov r0, r4 */
/* @0x129500 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129504 mov r1, #5 */
/* @0x129508 mov r10, r0 */
/* @0x12950c mov r0, r4 */
/* @0x129510 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129514 mov r1, #6 */
/* @0x129518 mov r9, r0 */
/* @0x12951c mov r0, r4 */
/* @0x129520 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129524 str r10, [sp] */
/* @0x129528 str r9, [sp, #0x4] */
/* @0x12952c mov r1, r8 */
/* @0x129530 mov r2, r7 */
/* @0x129534 mov r3, r6 */
/* @0x129538 str r0, [sp, #0x8] */
/* @0x12953c mov r0, r5 */
/* @0x129540 bl 0x1a3538 <_Z22ParticleType_Color_HSViiiiiii> */
/* @0x129544 add sp, sp, #16 */
/* @0x129548 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x12954c · F_PartTypeColor1(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12954c push {r3, r4, r5, lr} */
/* @0x129550 mov r1, #0 */
/* @0x129554 ldr r4, [sp, #0x10] */
/* @0x129558 mov r0, r4 */
/* @0x12955c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129560 mov r1, #1 */
/* @0x129564 mov r5, r0 */
/* @0x129568 mov r0, r4 */
/* @0x12956c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129570 mov r1, r0 */
/* @0x129574 mov r0, r5 */
/* @0x129578 pop {r3, r4, r5, lr} */
/* @0x12957c b 0x1a359c <_Z19ParticleType_Color1ij> */

/* ── FUNC 0x129580 · F_PartTypeColor2(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x129580 push {r4, r5, r6, lr} */
/* @0x129584 mov r1, #0 */
/* @0x129588 ldr r4, [sp, #0x10] */
/* @0x12958c mov r0, r4 */
/* @0x129590 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129594 mov r1, #1 */
/* @0x129598 mov r6, r0 */
/* @0x12959c mov r0, r4 */
/* @0x1295a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1295a4 mov r1, #2 */
/* @0x1295a8 mov r5, r0 */
/* @0x1295ac mov r0, r4 */
/* @0x1295b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1295b4 mov r1, r5 */
/* @0x1295b8 mov r2, r0 */
/* @0x1295bc mov r0, r6 */
/* @0x1295c0 pop {r4, r5, r6, lr} */
/* @0x1295c4 b 0x1a35d8 <_Z19ParticleType_Color2ijj> */

/* ── FUNC 0x1295c8 · F_PartTypeColor3(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1295c8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1295cc mov r1, #0 */
/* @0x1295d0 ldr r4, [sp, #0x18] */
/* @0x1295d4 mov r0, r4 */
/* @0x1295d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1295dc mov r1, #1 */
/* @0x1295e0 mov r7, r0 */
/* @0x1295e4 mov r0, r4 */
/* @0x1295e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1295ec mov r1, #2 */
/* @0x1295f0 mov r6, r0 */
/* @0x1295f4 mov r0, r4 */
/* @0x1295f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1295fc mov r1, #3 */
/* @0x129600 mov r5, r0 */
/* @0x129604 mov r0, r4 */
/* @0x129608 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12960c mov r1, r6 */
/* @0x129610 mov r2, r5 */
/* @0x129614 mov r3, r0 */
/* @0x129618 mov r0, r7 */
/* @0x12961c pop {r4, r5, r6, r7, r8, lr} */
/* @0x129620 b 0x1a361c <_Z19ParticleType_Color3ijjj> */

/* ── FUNC 0x129624 · F_PartTypeAlpha1(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x129624 push {r3, r4, r5, lr} */
/* @0x129628 mov r1, #0 */
/* @0x12962c ldr r4, [sp, #0x10] */
/* @0x129630 mov r0, r4 */
/* @0x129634 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129638 mov r1, #1 */
/* @0x12963c mov r5, r0 */
/* @0x129640 mov r0, r4 */
/* @0x129644 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129648 mov r1, r0 */
/* @0x12964c mov r0, r5 */
/* @0x129650 pop {r3, r4, r5, lr} */
/* @0x129654 b 0x1a3668 <_Z19ParticleType_Alpha1if> */

/* ── FUNC 0x129658 · F_PartTypeAlpha2(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x129658 push {r4, r5, r6, lr} */
/* @0x12965c mov r1, #0 */
/* @0x129660 ldr r4, [sp, #0x10] */
/* @0x129664 mov r0, r4 */
/* @0x129668 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12966c mov r1, #1 */
/* @0x129670 mov r6, r0 */
/* @0x129674 mov r0, r4 */
/* @0x129678 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12967c mov r1, #2 */
/* @0x129680 mov r5, r0 */
/* @0x129684 mov r0, r4 */
/* @0x129688 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12968c mov r1, r5 */
/* @0x129690 mov r2, r0 */
/* @0x129694 mov r0, r6 */
/* @0x129698 pop {r4, r5, r6, lr} */
/* @0x12969c b 0x1a36a4 <_Z19ParticleType_Alpha2iff> */

/* ── FUNC 0x1296a0 · F_PartTypeAlpha3(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1296a0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1296a4 mov r1, #0 */
/* @0x1296a8 ldr r4, [sp, #0x18] */
/* @0x1296ac mov r0, r4 */
/* @0x1296b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1296b4 mov r1, #1 */
/* @0x1296b8 mov r7, r0 */
/* @0x1296bc mov r0, r4 */
/* @0x1296c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1296c4 mov r1, #2 */
/* @0x1296c8 mov r6, r0 */
/* @0x1296cc mov r0, r4 */
/* @0x1296d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1296d4 mov r1, #3 */
/* @0x1296d8 mov r5, r0 */
/* @0x1296dc mov r0, r4 */
/* @0x1296e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1296e4 mov r1, r6 */
/* @0x1296e8 mov r2, r5 */
/* @0x1296ec mov r3, r0 */
/* @0x1296f0 mov r0, r7 */
/* @0x1296f4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1296f8 b 0x1a36f8 <_Z19ParticleType_Alpha3ifff> */

/* ── FUNC 0x1296fc · F_PartTypeBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1296fc push {r3, r4, r5, lr} */
/* @0x129700 mov r1, #0 */
/* @0x129704 ldr r4, [sp, #0x10] */
/* @0x129708 mov r0, r4 */
/* @0x12970c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129710 mov r1, #1 */
/* @0x129714 mov r5, r0 */
/* @0x129718 mov r0, r4 */
/* @0x12971c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129720 mov r1, r0 */
/* @0x129724 mov r0, r5 */
/* @0x129728 pop {r3, r4, r5, lr} */
/* @0x12972c b 0x1a373c <_Z18ParticleType_Blendib> */

/* ── FUNC 0x129730 · F_PartSystemCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x129730 push {r4, lr} */
/* @0x129734 mov r4, r0 */
/* @0x129738 mov r3, #0 */
/* @0x12973c mov r1, #1 */
/* @0x129740 str r3, [r4, #0xc] */
/* @0x129744 mvn r0, #0 */
/* @0x129748 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x12974c vmov s15, r0 */
/* @0x129750 vcvt.f64.s32 d7, s15 */
/* @0x129754 vmov r0, r1, d7 */
/* @0x129758 vmov r2, s14 */
/* @0x12975c mov r3, r1 */
/* @0x129760 stm r4, {r2, r3} */
/* @0x129764 pop {r4, pc} */

/* ── FUNC 0x129768 · F_PartSystemCreateLayer(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x129768 push {r4, r5, r6, r7, r8, lr} */
/* @0x12976c mov r6, #0 */
/* @0x129770 str r6, [r0, #0xc] */
/* @0x129774 mov r4, r0 */
/* @0x129778 ldr r5, [sp, #0x18] */
/* @0x12977c mov r8, r3 */
/* @0x129780 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x129784 mov r1, r6 */
/* @0x129788 ldr r2, [r5, #0xc] */
/* @0x12978c bic r2, r2, #-16777216 */
/* @0x129790 cmp r2, #1 */
/* @0x129794 mov r7, r0 */
/* @0x129798 mov r0, r5 */
/* @0x12979c beq 0x1297fc <_Z23F_PartSystemCreateLayerR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1297a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1297a4 mov r1, r0 */
/* @0x1297a8 mov r0, r7 */
/* @0x1297ac bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1297b0 cmp r0, #0 */
/* @0x1297b4 beq 0x129814 <_Z23F_PartSystemCreateLayerR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x1297b8 cmp r8, #1 */
/* @0x1297bc ldr r6, [r0] */
/* @0x1297c0 movle r1, #0 */
/* @0x1297c4 ble 0x1297d8 <_Z23F_PartSystemCreateLayerR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1297c8 mov r1, #1 */
/* @0x1297cc mov r0, r5 */
/* @0x1297d0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1297d4 mov r1, r0 */
/* @0x1297d8 mov r0, r6 */
/* @0x1297dc bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x1297e0 vmov s15, r0 */
/* @0x1297e4 vcvt.f64.s32 d7, s15 */
/* @0x1297e8 vmov r0, r1, d7 */
/* @0x1297ec vmov r2, s14 */
/* @0x1297f0 mov r3, r1 */
/* @0x1297f4 stm r4, {r2, r3} */
/* @0x1297f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1297fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x129800 mov r1, r0 */
/* @0x129804 mov r0, r7 */
/* @0x129808 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x12980c cmp r0, #0 */
/* @0x129810 bne 0x1297b8 <_Z23F_PartSystemCreateLayerR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x129814 mov r3, #0 */
/* @0x129818 str r0, [r4] */
/* @0x12981c movt r3, #0xbff0 */
/* @0x129820 str r3, [r4, #0x4] */
/* @0x129824 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x129828 · F_PartSystemGetLayer(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x129828 push {r4, lr} */
/* @0x12982c mov r3, #0 */
/* @0x129830 mov r1, r3 */
/* @0x129834 str r3, [r0, #0xc] */
/* @0x129838 mov r4, r0 */
/* @0x12983c ldr r0, [sp, #0x8] */
/* @0x129840 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129844 bl 0x1a4628 <_Z23ParticleSystem_GetLayeri> */
/* @0x129848 vmov s15, r0 */
/* @0x12984c vcvt.f64.s32 d7, s15 */
/* @0x129850 vmov r0, r1, d7 */
/* @0x129854 vmov r2, s14 */
/* @0x129858 mov r3, r1 */
/* @0x12985c stm r4, {r2, r3} */
/* @0x129860 pop {r4, pc} */

/* ── FUNC 0x129864 · F_PartSystemLayer(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x129864 mov r1, #0 */
/* @0x129868 push {r3, r4, r5, lr} */
/* @0x12986c mov r2, r1 */
/* @0x129870 movt r1, #0xbff0 */
/* @0x129874 str r2, [r0, #0xc] */
/* @0x129878 str r1, [r0, #0x4] */
/* @0x12987c str r2, [r0] */
/* @0x129880 ldr r4, [sp, #0x10] */
/* @0x129884 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x129888 ldr r1, [r4, #0x1c] */
/* @0x12988c bic r1, r1, #-16777216 */
/* @0x129890 cmp r1, #1 */
/* @0x129894 mov r5, r0 */
/* @0x129898 mov r0, r4 */
/* @0x12989c beq 0x1298d8 <_Z17F_PartSystemLayerR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1298a0 mov r1, #1 */
/* @0x1298a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1298a8 mov r1, r0 */
/* @0x1298ac mov r0, r5 */
/* @0x1298b0 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1298b4 mov r5, r0 */
/* @0x1298b8 cmp r5, #0 */
/* @0x1298bc popeq {r3, r4, r5, pc} */
/* @0x1298c0 mov r0, r4 */
/* @0x1298c4 mov r1, #0 */
/* @0x1298c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1298cc ldr r1, [r5] */
/* @0x1298d0 pop {r3, r4, r5, lr} */
/* @0x1298d4 b 0x1a4660 <_Z20ParticleSystem_Layerii> */
/* @0x1298d8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1298dc mov r1, r0 */
/* @0x1298e0 mov r0, r5 */
/* @0x1298e4 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1298e8 mov r5, r0 */
/* @0x1298ec cmp r5, #0 */
/* @0x1298f0 bne 0x1298c0 <_Z17F_PartSystemLayerR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1298f4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1298f8 · F_PartSystemDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1298f8 push {r3, lr} */
/* @0x1298fc mov r1, #0 */
/* @0x129900 ldr r0, [sp, #0x8] */
/* @0x129904 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129908 pop {r3, lr} */
/* @0x12990c b 0x1a454c <_Z22ParticleSystem_Destroyi> */

/* ── FUNC 0x129910 · F_PartSystemExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x129910 push {r4, lr} */
/* @0x129914 mov r3, #0 */
/* @0x129918 mov r1, r3 */
/* @0x12991c str r3, [r0, #0xc] */
/* @0x129920 mov r4, r0 */
/* @0x129924 ldr r0, [sp, #0x8] */
/* @0x129928 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12992c bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x129930 vmov s15, r0 */
/* @0x129934 vcvt.f64.u32 d7, s15 */
/* @0x129938 vmov r0, r1, d7 */
/* @0x12993c vmov r2, s14 */
/* @0x129940 mov r3, r1 */
/* @0x129944 stm r4, {r2, r3} */
/* @0x129948 pop {r4, pc} */

/* ── FUNC 0x12994c · F_PartSystemClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x12994c push {r3, lr} */
/* @0x129950 mov r1, #0 */
/* @0x129954 ldr r0, [sp, #0x8] */
/* @0x129958 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12995c pop {r3, lr} */
/* @0x129960 b 0x1a4180 <_Z20ParticleSystem_Cleari> */

/* ── FUNC 0x129964 · F_PartSystemDrawOrder(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x129964 push {r3, r4, r5, lr} */
/* @0x129968 mov r1, #0 */
/* @0x12996c ldr r4, [sp, #0x10] */
/* @0x129970 mov r0, r4 */
/* @0x129974 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129978 mov r1, #1 */
/* @0x12997c mov r5, r0 */
/* @0x129980 mov r0, r4 */
/* @0x129984 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129988 mov r1, r0 */
/* @0x12998c mov r0, r5 */
/* @0x129990 pop {r3, r4, r5, lr} */
/* @0x129994 b 0x1a47a0 <_Z24ParticleSystem_DrawOrderib> */

/* ── FUNC 0x129998 · F_PartSystemDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x129998 push {r3, r4, r5, lr} */
/* @0x12999c mov r1, #0 */
/* @0x1299a0 ldr r4, [sp, #0x10] */
/* @0x1299a4 mov r0, r4 */
/* @0x1299a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1299ac mov r1, #1 */
/* @0x1299b0 mov r5, r0 */
/* @0x1299b4 mov r0, r4 */
/* @0x1299b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1299bc mov r1, r0 */
/* @0x1299c0 mov r0, r5 */
/* @0x1299c4 pop {r3, r4, r5, lr} */
/* @0x1299c8 b 0x1a47d4 <_Z20ParticleSystem_Depthif> */

/* ── FUNC 0x1299cc · F_PartSystemPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1299cc push {r4, r5, r6, lr} */
/* @0x1299d0 mov r1, #0 */
/* @0x1299d4 ldr r4, [sp, #0x10] */
/* @0x1299d8 mov r0, r4 */
/* @0x1299dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1299e0 mov r1, #1 */
/* @0x1299e4 mov r6, r0 */
/* @0x1299e8 mov r0, r4 */
/* @0x1299ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1299f0 mov r1, #2 */
/* @0x1299f4 mov r5, r0 */
/* @0x1299f8 mov r0, r4 */
/* @0x1299fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129a00 mov r1, r5 */
/* @0x129a04 mov r2, r0 */
/* @0x129a08 mov r0, r6 */
/* @0x129a0c pop {r4, r5, r6, lr} */
/* @0x129a10 b 0x1a4894 <_Z23ParticleSystem_Positioniff> */

/* ── FUNC 0x129a14 · F_PartSystemAutomaticUpdate(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x129a14 push {r3, r4, r5, lr} */
/* @0x129a18 mov r1, #0 */
/* @0x129a1c ldr r4, [sp, #0x10] */
/* @0x129a20 mov r0, r4 */
/* @0x129a24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129a28 mov r1, #1 */
/* @0x129a2c mov r5, r0 */
/* @0x129a30 mov r0, r4 */
/* @0x129a34 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129a38 mov r1, r0 */
/* @0x129a3c mov r0, r5 */
/* @0x129a40 pop {r3, r4, r5, lr} */
/* @0x129a44 b 0x1a48d0 <_Z30ParticleSystem_AutomaticUpdateib> */

/* ── FUNC 0x129a48 · F_PartSystemAutomaticDraw(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x129a48 push {r3, r4, r5, lr} */
/* @0x129a4c mov r1, #0 */
/* @0x129a50 ldr r4, [sp, #0x10] */
/* @0x129a54 mov r0, r4 */
/* @0x129a58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129a5c mov r1, #1 */
/* @0x129a60 mov r5, r0 */
/* @0x129a64 mov r0, r4 */
/* @0x129a68 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129a6c mov r1, r0 */
/* @0x129a70 mov r0, r5 */
/* @0x129a74 pop {r3, r4, r5, lr} */
/* @0x129a78 b 0x1a4904 <_Z28ParticleSystem_AutomaticDrawib> */

/* ── FUNC 0x129a7c · F_PartSystemUpdate(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x129a7c push {r3, lr} */
/* @0x129a80 mov r1, #0 */
/* @0x129a84 ldr r0, [sp, #0x8] */
/* @0x129a88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129a8c pop {r3, lr} */
/* @0x129a90 b 0x1a4f18 <_Z21ParticleSystem_Updatei> */

/* ── FUNC 0x129a94 · F_PartSystemDrawIt(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x129a94 push {r3, lr} */
/* @0x129a98 mov r1, #0 */
/* @0x129a9c ldr r0, [sp, #0x8] */
/* @0x129aa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129aa4 pop {r3, lr} */
/* @0x129aa8 b 0x1a56ac <_Z19ParticleSystem_Drawi> */

/* ── FUNC 0x129aac · F_PartParticlesCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x129aac push {r4, r5, r6, r7, r8, lr} */
/* @0x129ab0 mov r1, #0 */
/* @0x129ab4 ldr r4, [sp, #0x18] */
/* @0x129ab8 mov r0, r4 */
/* @0x129abc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129ac0 mov r1, #1 */
/* @0x129ac4 mov r5, r0 */
/* @0x129ac8 mov r0, r4 */
/* @0x129acc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129ad0 mov r1, #2 */
/* @0x129ad4 mov r8, r0 */
/* @0x129ad8 mov r0, r4 */
/* @0x129adc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129ae0 mov r1, #3 */
/* @0x129ae4 mov r7, r0 */
/* @0x129ae8 mov r0, r4 */
/* @0x129aec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129af0 mov r1, #4 */
/* @0x129af4 mov r6, r0 */
/* @0x129af8 mov r0, r4 */
/* @0x129afc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129b00 mov r1, r8 */
/* @0x129b04 mov r2, r7 */
/* @0x129b08 mov r3, r6 */
/* @0x129b0c str r0, [sp, #0x18] */
/* @0x129b10 mov r0, r5 */
/* @0x129b14 pop {r4, r5, r6, r7, r8, lr} */
/* @0x129b18 b 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii> */

/* ── FUNC 0x129b1c · F_PartParticlesCreateColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x129b1c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x129b20 sub sp, sp, #12 */
/* @0x129b24 mov r1, #0 */
/* @0x129b28 ldr r4, [sp, #0x28] */
/* @0x129b2c mov r0, r4 */
/* @0x129b30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129b34 mov r1, #1 */
/* @0x129b38 mov r5, r0 */
/* @0x129b3c mov r0, r4 */
/* @0x129b40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129b44 mov r1, #2 */
/* @0x129b48 mov r8, r0 */
/* @0x129b4c mov r0, r4 */
/* @0x129b50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129b54 mov r1, #3 */
/* @0x129b58 mov r6, r0 */
/* @0x129b5c mov r0, r4 */
/* @0x129b60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129b64 mov r1, #4 */
/* @0x129b68 mov r7, r0 */
/* @0x129b6c mov r0, r4 */
/* @0x129b70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129b74 mov r1, #5 */
/* @0x129b78 mov r9, r0 */
/* @0x129b7c mov r0, r4 */
/* @0x129b80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129b84 str r9, [sp] */
/* @0x129b88 mov r1, r8 */
/* @0x129b8c mov r3, r7 */
/* @0x129b90 mov r2, r6 */
/* @0x129b94 str r0, [sp, #0x4] */
/* @0x129b98 mov r0, r5 */
/* @0x129b9c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x129ba0 add sp, sp, #12 */
/* @0x129ba4 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x129ba8 · F_PartParticlesClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x129ba8 push {r3, lr} */
/* @0x129bac mov r1, #0 */
/* @0x129bb0 ldr r0, [sp, #0x8] */
/* @0x129bb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129bb8 pop {r3, lr} */
/* @0x129bbc b 0x1a40d4 <_Z30ParticleSystem_Particles_Cleari> */

/* ── FUNC 0x129bc0 · F_PartParticlesCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x129bc0 push {r4, lr} */
/* @0x129bc4 mov r3, #0 */
/* @0x129bc8 mov r1, r3 */
/* @0x129bcc str r3, [r0, #0xc] */
/* @0x129bd0 mov r4, r0 */
/* @0x129bd4 ldr r0, [sp, #0x8] */
/* @0x129bd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129bdc bl 0x1a4150 <_Z30ParticleSystem_Particles_Counti> */
/* @0x129be0 vmov s15, r0 */
/* @0x129be4 vcvt.f64.s32 d7, s15 */
/* @0x129be8 vmov r0, r1, d7 */
/* @0x129bec vmov r2, s14 */
/* @0x129bf0 mov r3, r1 */
/* @0x129bf4 stm r4, {r2, r3} */
/* @0x129bf8 pop {r4, pc} */
