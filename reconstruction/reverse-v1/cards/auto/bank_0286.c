/* libyoyo.so 覆盖卡组 0286
 * 函数 0x2e11d8..0x2e2370，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e11d8 · b2Island::~b2Island() · size=76 · insn=19 */
/* @0x2e11d8 push {r4, lr} */
/* @0x2e11dc mov r4, r0 */
/* @0x2e11e0 ldr r1, [r4, #0x14] */
/* @0x2e11e4 ldr r0, [r0] */
/* @0x2e11e8 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e11ec ldr r0, [r4] */
/* @0x2e11f0 ldr r1, [r4, #0x18] */
/* @0x2e11f4 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e11f8 ldr r0, [r4] */
/* @0x2e11fc ldr r1, [r4, #0x10] */
/* @0x2e1200 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e1204 ldr r0, [r4] */
/* @0x2e1208 ldr r1, [r4, #0xc] */
/* @0x2e120c bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e1210 ldr r0, [r4] */
/* @0x2e1214 ldr r1, [r4, #0x8] */
/* @0x2e1218 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e121c mov r0, r4 */
/* @0x2e1220 pop {r4, pc} */

/* ── FUNC 0x2e11d8 · b2Island::~b2Island() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e1224 · b2Island::Report(b2ContactVelocityConstraint const*) · size=160 · insn=40 */
/* @0x2e1224 push {r4, r5, r6, r7, lr} */
/* @0x2e1228 mov r6, r0 */
/* @0x2e122c ldr r0, [r0, #0x4] */
/* @0x2e1230 sub sp, sp, #28 */
/* @0x2e1234 cmp r0, #0 */
/* @0x2e1238 beq 0x2e12bc <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x98> */
/* @0x2e123c ldr r3, [r6, #0x24] */
/* @0x2e1240 cmp r3, #0 */
/* @0x2e1244 ble 0x2e12bc <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x98> */
/* @0x2e1248 add r4, r1, #148 */
/* @0x2e124c add r7, sp, #4 */
/* @0x2e1250 mov r5, #0 */
/* @0x2e1254 b 0x2e125c <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x38> */
/* @0x2e1258 ldr r0, [r6, #0x4] */
/* @0x2e125c ldr r3, [r4] */
/* @0x2e1260 ldr r2, [r6, #0xc] */
/* @0x2e1264 cmp r3, #0 */
/* @0x2e1268 ldr r1, [r2, r5, lsl #2] */
/* @0x2e126c str r3, [sp, #0x14] */
/* @0x2e1270 ble 0x2e1298 <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x74> */
/* @0x2e1274 cmp r3, #1 */
/* @0x2e1278 ldr r2, [r4, #-0x84] */
/* @0x2e127c ldr r3, [r4, #-0x80] */
/* @0x2e1280 str r2, [sp, #0x4] */
/* @0x2e1284 str r3, [sp, #0xc] */
/* @0x2e1288 ldrne r2, [r4, #-0x60] */
/* @0x2e128c ldrne r3, [r4, #-0x5c] */
/* @0x2e1290 strne r2, [sp, #0x8] */
/* @0x2e1294 strne r3, [sp, #0x10] */
/* @0x2e1298 ldr r3, [r0] */
/* @0x2e129c mov r2, r7 */
/* @0x2e12a0 add r5, r5, #1 */
/* @0x2e12a4 add r4, r4, #156 */
/* @0x2e12a8 ldr r3, [r3, #0x14] */
/* @0x2e12ac blx r3 */
/* @0x2e12b0 ldr r3, [r6, #0x24] */
/* @0x2e12b4 cmp r3, r5 */
/* @0x2e12b8 bgt 0x2e1258 <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x34> */
/* @0x2e12bc add sp, sp, #28 */
/* @0x2e12c0 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e12c4 · b2Island::SolveTOI(b2TimeStep const&, int, int) · size=804 · insn=201 */
/* @0x2e12c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e12c8 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2e12cc mov r6, r0 */
/* @0x2e12d0 ldr r5, [r0, #0x1c] */
/* @0x2e12d4 sub sp, sp, #100 */
/* @0x2e12d8 mov r4, r1 */
/* @0x2e12dc mov r7, r2 */
/* @0x2e12e0 cmp r5, #0 */
/* @0x2e12e4 mov r8, r3 */
/* @0x2e12e8 ldr r10, [r0, #0x14] */
/* @0x2e12ec ldr r9, [r0, #0x18] */
/* @0x2e12f0 ble 0x2e133c <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x78> */
/* @0x2e12f4 ldr r3, [r0, #0x8] */
/* @0x2e12f8 add lr, r10, #8 */
/* @0x2e12fc add r12, r9, #8 */
/* @0x2e1300 add r5, r3, r5, lsl #2 */
/* @0x2e1304 ldr r2, [r3], #4 */
/* @0x2e1308 vldr s15, [r2, #72] */
/* @0x2e130c add r1, r2, #60 */
/* @0x2e1310 add r2, r2, #80 */
/* @0x2e1314 ldr r11, [r2, #0x8] */
/* @0x2e1318 cmp r3, r5 */
/* @0x2e131c ldm r1, {r0, r1} */
/* @0x2e1320 stmdb lr, {r0, r1} */
/* @0x2e1324 ldm r2, {r0, r1} */
/* @0x2e1328 vmov r2, s15 */
/* @0x2e132c str r2, [lr], #12 */
/* @0x2e1330 stmdb r12, {r0, r1} */
/* @0x2e1334 str r11, [r12], #12 */
/* @0x2e1338 bne 0x2e1304 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x40> */
/* @0x2e133c mov lr, r4 */
/* @0x2e1340 mov r12, sp */
/* @0x2e1344 ldm lr!, {r0, r1, r2, r3} */
/* @0x2e1348 add r5, sp, #44 */
/* @0x2e134c ldr r11, [r6, #0xc] */
/* @0x2e1350 str r9, [sp, #0x24] */
/* @0x2e1354 str r10, [sp, #0x20] */
/* @0x2e1358 stm r12!, {r0, r1, r2, r3} */
/* @0x2e135c ldm lr, {r0, r1} */
/* @0x2e1360 ldr r3, [r6] */
/* @0x2e1364 ldr r2, [r6, #0x24] */
/* @0x2e1368 stm r12, {r0, r1} */
/* @0x2e136c mov r0, r5 */
/* @0x2e1370 mov r1, sp */
/* @0x2e1374 str r3, [sp, #0x28] */
/* @0x2e1378 str r11, [sp, #0x18] */
/* @0x2e137c str r2, [sp, #0x1c] */
/* @0x2e1380 bl 0x2e2090 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef> */
/* @0x2e1384 ldr r3, [r4, #0x10] */
/* @0x2e1388 cmp r3, #0 */
/* @0x2e138c movgt r9, #0 */
/* @0x2e1390 bgt 0x2e13a4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0xe0> */
/* @0x2e1394 b 0x2e13c0 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0xfc> */
/* @0x2e1398 ldr r3, [r4, #0x10] */
/* @0x2e139c cmp r3, r9 */
/* @0x2e13a0 ble 0x2e13c0 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0xfc> */
/* @0x2e13a4 mov r0, r5 */
/* @0x2e13a8 mov r1, r7 */
/* @0x2e13ac mov r2, r8 */
/* @0x2e13b0 add r9, r9, #1 */
/* @0x2e13b4 bl 0x2e33d8 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii> */
/* @0x2e13b8 cmp r0, #0 */
/* @0x2e13bc beq 0x2e1398 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0xd4> */
/* @0x2e13c0 ldr r1, [r6, #0x8] */
/* @0x2e13c4 add r2, r7, r7, lsl #1 */
/* @0x2e13c8 ldr r3, [r6, #0x14] */
/* @0x2e13cc add r0, r8, r8, lsl #1 */
/* @0x2e13d0 add r2, r3, r2, lsl #2 */
/* @0x2e13d4 ldr r7, [r1, r7, lsl #2] */
/* @0x2e13d8 ldr r12, [r1, r8, lsl #2] */
/* @0x2e13dc add r3, r3, r0, lsl #2 */
/* @0x2e13e0 ldm r2, {r0, r1} */
/* @0x2e13e4 add r8, r7, #52 */
/* @0x2e13e8 ldr r9, [r2, #0x8] */
/* @0x2e13ec add lr, r12, #52 */
/* @0x2e13f0 ldr r2, [r3, #0x8] */
/* @0x2e13f4 stm r8, {r0, r1} */
/* @0x2e13f8 ldm r3, {r0, r1} */
/* @0x2e13fc str r9, [r7, #0x44] */
/* @0x2e1400 stm lr, {r0, r1} */
/* @0x2e1404 mov r0, r5 */
/* @0x2e1408 str r2, [r12, #0x44] */
/* @0x2e140c bl 0x2e2398 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv> */
/* @0x2e1410 ldr r3, [r4, #0xc] */
/* @0x2e1414 cmp r3, #0 */
/* @0x2e1418 movgt r7, #0 */
/* @0x2e141c ble 0x2e1438 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x174> */
/* @0x2e1420 mov r0, r5 */
/* @0x2e1424 add r7, r7, #1 */
/* @0x2e1428 bl 0x2e28f4 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv> */
/* @0x2e142c ldr r3, [r4, #0xc] */
/* @0x2e1430 cmp r3, r7 */
/* @0x2e1434 bgt 0x2e1420 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x15c> */
/* @0x2e1438 ldr r9, [r6, #0x1c] */
/* @0x2e143c vldr s20, [r4] */
/* @0x2e1440 cmp r9, #0 */
/* @0x2e1444 ble 0x2e15a4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x2e0> */
/* @0x2e1448 mov r10, #0 */
/* @0x2e144c vmov.f32 s24, #4.000000e+00 */
/* @0x2e1450 ldr r8, [r6, #0x14] */
/* @0x2e1454 mov r11, r10 */
/* @0x2e1458 ldr r7, [r6, #0x18] */
/* @0x2e145c vldr s23, [pc, #380] */
/* @0x2e1460 vldr s25, [pc, #380] */
/* @0x2e1464 vmov.f32 s26, #2.000000e+00 */
/* @0x2e1468 b 0x2e1534 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x270> */
/* @0x2e146c vmul.f32 s17, s20, s16 */
/* @0x2e1470 vmul.f32 s15, s17, s17 */
/* @0x2e1474 vcmpe.f32 s15, s23 */
/* @0x2e1478 vmrs APSR_nzcv, fpscr */
/* @0x2e147c ble 0x2e1498 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x1d4> */
/* @0x2e1480 vcmpe.f32 s17, #0 */
/* @0x2e1484 vmrs APSR_nzcv, fpscr */
/* @0x2e1488 vnegle.f32 s17, s17 */
/* @0x2e148c vdiv.f32 s17, s25, s17 */
/* @0x2e1490 vmul.f32 s16, s16, s17 */
/* @0x2e1494 vmul.f32 s17, s20, s16 */
/* @0x2e1498 ldr r1, [r6, #0x8] */
/* @0x2e149c add r11, r11, #1 */
/* @0x2e14a0 ldr r4, [r1, r10] */
/* @0x2e14a4 add r10, r10, #4 */
/* @0x2e14a8 vadd.f32 s22, s22, s13 */
/* @0x2e14ac vadd.f32 s21, s21, s14 */
/* @0x2e14b0 vstr s22, [r2] */
/* @0x2e14b4 vadd.f32 s17, s27, s17 */
/* @0x2e14b8 vstr s21, [r2, #4] */
/* @0x2e14bc vstr s17, [r2, #8] */
/* @0x2e14c0 vmov r0, s17 */
/* @0x2e14c4 vstr s16, [r3, #8] */
/* @0x2e14c8 vstr s19, [r3] */
/* @0x2e14cc vstr s18, [r3, #4] */
/* @0x2e14d0 vstr s16, [r4, #88] */
/* @0x2e14d4 vstr s22, [r4, #60] */
/* @0x2e14d8 vstr s21, [r4, #64] */
/* @0x2e14dc vstr s17, [r4, #72] */
/* @0x2e14e0 vstr s19, [r4, #80] */
/* @0x2e14e4 vstr s18, [r4, #84] */
/* @0x2e14e8 bl 0xb6580 <sinf@plt> */
/* @0x2e14ec vmov s16, r0 */
/* @0x2e14f0 vstr s16, [r4, #20] */
/* @0x2e14f4 vmov r0, s17 */
/* @0x2e14f8 bl 0xb658c <cosf@plt> */
/* @0x2e14fc vldr s14, [r4, #48] */
/* @0x2e1500 vmul.f32 s13, s14, s16 */
/* @0x2e1504 vldr s12, [r4, #44] */
/* @0x2e1508 cmp r9, r11 */
/* @0x2e150c vmov s15, r0 */
/* @0x2e1510 str r0, [r4, #0x18] */
/* @0x2e1514 vmul.f32 s14, s14, s15 */
/* @0x2e1518 vnmls.f32 s13, s12, s15 */
/* @0x2e151c vmla.f32 s14, s12, s16 */
/* @0x2e1520 vsub.f32 s13, s22, s13 */
/* @0x2e1524 vsub.f32 s14, s21, s14 */
/* @0x2e1528 vstr s13, [r4, #12] */
/* @0x2e152c vstr s14, [r4, #16] */
/* @0x2e1530 ble 0x2e15a4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x2e0> */
/* @0x2e1534 add r4, r10, r10, lsl #1 */
/* @0x2e1538 add r3, r7, r4 */
/* @0x2e153c vldr s18, [r3, #4] */
/* @0x2e1540 vmul.f32 s14, s20, s18 */
/* @0x2e1544 vldr s19, [r3] */
/* @0x2e1548 add r2, r8, r4 */
/* @0x2e154c vldr s16, [r3, #8] */
/* @0x2e1550 vldr s22, [r2] */
/* @0x2e1554 vldr s21, [r2, #4] */
/* @0x2e1558 vldr s27, [r2, #8] */
/* @0x2e155c vmul.f32 s13, s20, s19 */
/* @0x2e1560 vmul.f32 s15, s14, s14 */
/* @0x2e1564 vmla.f32 s15, s13, s13 */
/* @0x2e1568 vcmpe.f32 s15, s24 */
/* @0x2e156c vmrs APSR_nzcv, fpscr */
/* @0x2e1570 ble 0x2e146c <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x1a8> */
/* @0x2e1574 vsqrt.f32 s14, s15 */
/* @0x2e1578 vcmp.f32 s14, s14 */
/* @0x2e157c vmrs APSR_nzcv, fpscr */
/* @0x2e1580 bne 0x2e15c4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x300> */
/* @0x2e1584 vdiv.f32 s14, s26, s14 */
/* @0x2e1588 add r2, r8, r4 */
/* @0x2e158c add r3, r7, r4 */
/* @0x2e1590 vmul.f32 s19, s19, s14 */
/* @0x2e1594 vmul.f32 s18, s18, s14 */
/* @0x2e1598 vmul.f32 s13, s20, s19 */
/* @0x2e159c vmul.f32 s14, s20, s18 */
/* @0x2e15a0 b 0x2e146c <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x1a8> */
/* @0x2e15a4 mov r0, r6 */
/* @0x2e15a8 ldr r1, [sp, #0x54] */
/* @0x2e15ac bl 0x2e1224 <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint> */
/* @0x2e15b0 mov r0, r5 */
/* @0x2e15b4 bl 0x2e2370 <_ZN15b2ContactSolverD2Ev> */
/* @0x2e15b8 add sp, sp, #100 */
/* @0x2e15bc vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2e15c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e15c4 vmov r0, s15 */
/* @0x2e15c8 bl 0xb6700 <sqrtf@plt> */
/* @0x2e15cc ldr r9, [r6, #0x1c] */
/* @0x2e15d0 ldr r8, [r6, #0x14] */
/* @0x2e15d4 ldr r7, [r6, #0x18] */
/* @0x2e15d8 vmov s14, r0 */
/* @0x2e15dc b 0x2e1584 <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x2c0> */
/* @0x2e15e0 andsmi lr, sp, r7, ror #19 */
/* @0x2e15e4 svclo #0xc90fdb */

/* ── FUNC 0x2e15e8 · b2Island::Solve(b2Profile*, b2TimeStep const&, b2Vec2 const&, bool) · size=1664 · insn=416 */
/* @0x2e15e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e15ec vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2e15f0 sub sp, sp, #156 */
/* @0x2e15f4 add r12, sp, #16 */
/* @0x2e15f8 mov r4, r0 */
/* @0x2e15fc str r12, [sp] */
/* @0x2e1600 mov r6, r2 */
/* @0x2e1604 mov r0, r12 */
/* @0x2e1608 ldrb r12, [sp, #0xf0] */
/* @0x2e160c mov r10, r3 */
/* @0x2e1610 str r1, [sp, #0x4] */
/* @0x2e1614 str r12, [sp, #0x8] */
/* @0x2e1618 bl 0x2e10b8 <_ZN7b2TimerC2Ev> */
/* @0x2e161c ldr r3, [r4, #0x1c] */
/* @0x2e1620 vldr s16, [r6] */
/* @0x2e1624 cmp r3, #0 */
/* @0x2e1628 ble 0x2e1734 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x14c> */
/* @0x2e162c ldr r5, [r4, #0x8] */
/* @0x2e1630 vmov.f32 s10, #1.000000e+00 */
/* @0x2e1634 ldr lr, [r4, #0x14] */
/* @0x2e1638 ldr r12, [r4, #0x18] */
/* @0x2e163c add r3, r5, r3, lsl #2 */
/* @0x2e1640 b 0x2e166c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x84> */
/* @0x2e1644 cmp r5, r3 */
/* @0x2e1648 vstr s12, [lr] */
/* @0x2e164c str r11, [lr, #0x4] */
/* @0x2e1650 add r12, r12, #12 */
/* @0x2e1654 str r8, [lr, #0x8] */
/* @0x2e1658 vstr s13, [r12, #-12] */
/* @0x2e165c vstr s14, [r12, #-8] */
/* @0x2e1660 vstr s15, [r12, #-4] */
/* @0x2e1664 add lr, lr, #12 */
/* @0x2e1668 beq 0x2e1734 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x14c> */
/* @0x2e166c ldr r2, [r5], #4 */
/* @0x2e1670 vldr s12, [r2, #60] */
/* @0x2e1674 vldr s13, [r2, #80] */
/* @0x2e1678 vldr s14, [r2, #84] */
/* @0x2e167c add r1, r2, #60 */
/* @0x2e1680 add r7, r2, #52 */
/* @0x2e1684 ldr r9, [r2] */
/* @0x2e1688 vldr s15, [r2, #88] */
/* @0x2e168c ldr r8, [r2, #0x48] */
/* @0x2e1690 ldm r1, {r0, r1} */
/* @0x2e1694 cmp r9, #2 */
/* @0x2e1698 ldr r11, [r2, #0x40] */
/* @0x2e169c stm r7, {r0, r1} */
/* @0x2e16a0 str r8, [r2, #0x44] */
/* @0x2e16a4 bne 0x2e1644 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5c> */
/* @0x2e16a8 vldr s9, [r2, #136] */
/* @0x2e16ac vldr s8, [r2, #92] */
/* @0x2e16b0 vldr s1, [r2, #96] */
/* @0x2e16b4 vmul.f32 s8, s9, s8 */
/* @0x2e16b8 vldr s6, [r2, #148] */
/* @0x2e16bc vldr s7, [r2, #156] */
/* @0x2e16c0 vldr s2, [r10] */
/* @0x2e16c4 vldr s3, [r10, #4] */
/* @0x2e16c8 vldr s4, [r2, #144] */
/* @0x2e16cc vldr s5, [r2, #100] */
/* @0x2e16d0 vmul.f32 s9, s9, s1 */
/* @0x2e16d4 vmov.f32 s11, s10 */
/* @0x2e16d8 vmls.f32 s11, s16, s6 */
/* @0x2e16dc vmla.f32 s9, s7, s3 */
/* @0x2e16e0 vmla.f32 s8, s7, s2 */
/* @0x2e16e4 vmul.f32 s7, s16, s4 */
/* @0x2e16e8 vcmpe.f32 s11, s10 */
/* @0x2e16ec vmla.f32 s14, s16, s9 */
/* @0x2e16f0 vmrs APSR_nzcv, fpscr */
/* @0x2e16f4 vmla.f32 s13, s16, s8 */
/* @0x2e16f8 vmla.f32 s15, s7, s5 */
/* @0x2e16fc vmovpl.f32 s9, #1.000000e+00 */
/* @0x2e1700 bmi 0x2e1bfc <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x614> */
/* @0x2e1704 vldr s8, [r2, #152] */
/* @0x2e1708 vmov.f32 s11, s10 */
/* @0x2e170c vmls.f32 s11, s16, s8 */
/* @0x2e1710 vcmpe.f32 s11, s10 */
/* @0x2e1714 vmov.f32 s8, s11 */
/* @0x2e1718 vmrs APSR_nzcv, fpscr */
/* @0x2e171c vmul.f32 s13, s13, s9 */
/* @0x2e1720 vmul.f32 s14, s14, s9 */
/* @0x2e1724 vmovpl.f32 s8, #1.000000e+00 */
/* @0x2e1728 bmi 0x2e1bec <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x604> */
/* @0x2e172c vmul.f32 s15, s15, s8 */
/* @0x2e1730 b 0x2e1644 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5c> */
/* @0x2e1734 add r0, sp, #16 */
/* @0x2e1738 add r5, sp, #24 */
/* @0x2e173c bl 0x2e1090 <_ZN7b2Timer5ResetEv> */
/* @0x2e1740 mov r12, r6 */
/* @0x2e1744 ldm r12!, {r0, r1, r2, r3} */
/* @0x2e1748 mov r8, r5 */
/* @0x2e174c mov r10, r6 */
/* @0x2e1750 add lr, sp, #56 */
/* @0x2e1754 ldr r11, [r4, #0x14] */
/* @0x2e1758 add r7, sp, #100 */
/* @0x2e175c stm r8!, {r0, r1, r2, r3} */
/* @0x2e1760 ldm r12, {r0, r1} */
/* @0x2e1764 str r11, [sp, #0x30] */
/* @0x2e1768 str r11, [sp, #0x58] */
/* @0x2e176c stm r8, {r0, r1} */
/* @0x2e1770 ldm r10!, {r0, r1, r2, r3} */
/* @0x2e1774 ldr r8, [r4, #0x18] */
/* @0x2e1778 ldr r10, [r4, #0xc] */
/* @0x2e177c stm lr!, {r0, r1, r2, r3} */
/* @0x2e1780 ldm r12, {r0, r1} */
/* @0x2e1784 ldr r3, [r4, #0x24] */
/* @0x2e1788 str r8, [sp, #0x34] */
/* @0x2e178c stm lr, {r0, r1} */
/* @0x2e1790 add r1, sp, #56 */
/* @0x2e1794 str r3, [sp, #0x54] */
/* @0x2e1798 mov r0, r7 */
/* @0x2e179c str r10, [sp, #0x50] */
/* @0x2e17a0 str r8, [sp, #0x5c] */
/* @0x2e17a4 ldr r3, [r4] */
/* @0x2e17a8 str r3, [sp, #0x60] */
/* @0x2e17ac bl 0x2e2090 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef> */
/* @0x2e17b0 mov r0, r7 */
/* @0x2e17b4 bl 0x2e2398 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv> */
/* @0x2e17b8 ldrb r3, [r6, #0x14] */
/* @0x2e17bc cmp r3, #0 */
/* @0x2e17c0 bne 0x2e1c2c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x644> */
/* @0x2e17c4 ldr r3, [r4, #0x20] */
/* @0x2e17c8 cmp r3, #0 */
/* @0x2e17cc movgt r8, #0 */
/* @0x2e17d0 ble 0x2e17fc <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x214> */
/* @0x2e17d4 ldr r3, [r4, #0x10] */
/* @0x2e17d8 mov r1, r5 */
/* @0x2e17dc ldr r0, [r3, r8, lsl #2] */
/* @0x2e17e0 add r8, r8, #1 */
/* @0x2e17e4 ldr r3, [r0] */
/* @0x2e17e8 ldr r3, [r3, #0x20] */
/* @0x2e17ec blx r3 */
/* @0x2e17f0 ldr r3, [r4, #0x20] */
/* @0x2e17f4 cmp r3, r8 */
/* @0x2e17f8 bgt 0x2e17d4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x1ec> */
/* @0x2e17fc add r0, sp, #16 */
/* @0x2e1800 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2e1804 ldr r12, [sp, #0x4] */
/* @0x2e1808 str r0, [r12, #0xc] */
/* @0x2e180c add r0, sp, #16 */
/* @0x2e1810 bl 0x2e1090 <_ZN7b2Timer5ResetEv> */
/* @0x2e1814 ldr r3, [r6, #0xc] */
/* @0x2e1818 cmp r3, #0 */
/* @0x2e181c movgt r8, #0 */
/* @0x2e1820 ble 0x2e1874 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x28c> */
/* @0x2e1824 ldr r3, [r4, #0x20] */
/* @0x2e1828 cmp r3, #0 */
/* @0x2e182c ble 0x2e185c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x274> */
/* @0x2e1830 mov r9, #0 */
/* @0x2e1834 ldr r3, [r4, #0x10] */
/* @0x2e1838 mov r1, r5 */
/* @0x2e183c ldr r0, [r3, r9, lsl #2] */
/* @0x2e1840 add r9, r9, #1 */
/* @0x2e1844 ldr r3, [r0] */
/* @0x2e1848 ldr r3, [r3, #0x24] */
/* @0x2e184c blx r3 */
/* @0x2e1850 ldr r3, [r4, #0x20] */
/* @0x2e1854 cmp r3, r9 */
/* @0x2e1858 bgt 0x2e1834 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x24c> */
/* @0x2e185c mov r0, r7 */
/* @0x2e1860 add r8, r8, #1 */
/* @0x2e1864 bl 0x2e28f4 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv> */
/* @0x2e1868 ldr r3, [r6, #0xc] */
/* @0x2e186c cmp r3, r8 */
/* @0x2e1870 bgt 0x2e1824 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x23c> */
/* @0x2e1874 mov r0, r7 */
/* @0x2e1878 bl 0x2e2ee8 <_ZN15b2ContactSolver13StoreImpulsesEv> */
/* @0x2e187c add r0, sp, #16 */
/* @0x2e1880 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2e1884 ldr r12, [r4, #0x1c] */
/* @0x2e1888 ldr r3, [sp, #0x4] */
/* @0x2e188c cmp r12, #0 */
/* @0x2e1890 str r0, [r3, #0x10] */
/* @0x2e1894 ble 0x2e1988 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x3a0> */
/* @0x2e1898 mov r8, #0 */
/* @0x2e189c vmov.f32 s24, #4.000000e+00 */
/* @0x2e18a0 ldr r0, [r4, #0x14] */
/* @0x2e18a4 mov r10, r8 */
/* @0x2e18a8 ldr r1, [r4, #0x18] */
/* @0x2e18ac vldr s23, [pc, #924] */
/* @0x2e18b0 vldr s25, [pc, #924] */
/* @0x2e18b4 vmov.f32 s26, #2.000000e+00 */
/* @0x2e18b8 b 0x2e191c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x334> */
/* @0x2e18bc vmul.f32 s15, s16, s17 */
/* @0x2e18c0 vmul.f32 s14, s15, s15 */
/* @0x2e18c4 vcmpe.f32 s14, s23 */
/* @0x2e18c8 vmrs APSR_nzcv, fpscr */
/* @0x2e18cc ble 0x2e18e8 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x300> */
/* @0x2e18d0 vcmpe.f32 s15, #0 */
/* @0x2e18d4 vmrs APSR_nzcv, fpscr */
/* @0x2e18d8 vnegle.f32 s15, s15 */
/* @0x2e18dc vdiv.f32 s15, s25, s15 */
/* @0x2e18e0 vmul.f32 s17, s17, s15 */
/* @0x2e18e4 vmul.f32 s15, s16, s17 */
/* @0x2e18e8 add r10, r10, #1 */
/* @0x2e18ec add r8, r8, #12 */
/* @0x2e18f0 cmp r12, r10 */
/* @0x2e18f4 vadd.f32 s12, s22, s12 */
/* @0x2e18f8 vadd.f32 s13, s21, s13 */
/* @0x2e18fc vstr s12, [r2] */
/* @0x2e1900 vadd.f32 s20, s20, s15 */
/* @0x2e1904 vstr s13, [r2, #4] */
/* @0x2e1908 vstr s20, [r2, #8] */
/* @0x2e190c vstr s19, [r3] */
/* @0x2e1910 vstr s18, [r3, #4] */
/* @0x2e1914 vstr s17, [r3, #8] */
/* @0x2e1918 ble 0x2e1988 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x3a0> */
/* @0x2e191c add r3, r1, r8 */
/* @0x2e1920 vldr s18, [r3, #4] */
/* @0x2e1924 vmul.f32 s13, s16, s18 */
/* @0x2e1928 vldr s19, [r3] */
/* @0x2e192c add r2, r0, r8 */
/* @0x2e1930 vldr s17, [r3, #8] */
/* @0x2e1934 vldr s22, [r2] */
/* @0x2e1938 vldr s21, [r2, #4] */
/* @0x2e193c vldr s20, [r2, #8] */
/* @0x2e1940 vmul.f32 s12, s16, s19 */
/* @0x2e1944 vmul.f32 s14, s13, s13 */
/* @0x2e1948 vmla.f32 s14, s12, s12 */
/* @0x2e194c vcmpe.f32 s14, s24 */
/* @0x2e1950 vmrs APSR_nzcv, fpscr */
/* @0x2e1954 ble 0x2e18bc <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x2d4> */
/* @0x2e1958 vsqrt.f32 s15, s14 */
/* @0x2e195c vcmp.f32 s15, s15 */
/* @0x2e1960 vmrs APSR_nzcv, fpscr */
/* @0x2e1964 bne 0x2e1c38 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x650> */
/* @0x2e1968 vdiv.f32 s15, s26, s15 */
/* @0x2e196c add r2, r0, r8 */
/* @0x2e1970 add r3, r1, r8 */
/* @0x2e1974 vmul.f32 s19, s19, s15 */
/* @0x2e1978 vmul.f32 s18, s18, s15 */
/* @0x2e197c vmul.f32 s12, s16, s19 */
/* @0x2e1980 vmul.f32 s13, s16, s18 */
/* @0x2e1984 b 0x2e18bc <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x2d4> */
/* @0x2e1988 add r0, sp, #16 */
/* @0x2e198c bl 0x2e1090 <_ZN7b2Timer5ResetEv> */
/* @0x2e1990 ldr r3, [r6, #0x10] */
/* @0x2e1994 cmp r3, #0 */
/* @0x2e1998 movgt r8, #0 */
/* @0x2e199c ble 0x2e1a04 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x41c> */
/* @0x2e19a0 mov r0, r7 */
/* @0x2e19a4 bl 0x2e2f4c <_ZN15b2ContactSolver24SolvePositionConstraintsEv> */
/* @0x2e19a8 ldr r3, [r4, #0x20] */
/* @0x2e19ac cmp r3, #0 */
/* @0x2e19b0 mov r11, r0 */
/* @0x2e19b4 ble 0x2e1bd4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5ec> */
/* @0x2e19b8 mov r9, #0 */
/* @0x2e19bc mov r10, #1 */
/* @0x2e19c0 ldr r3, [r4, #0x10] */
/* @0x2e19c4 mov r1, r5 */
/* @0x2e19c8 ldr r0, [r3, r9, lsl #2] */
/* @0x2e19cc add r9, r9, #1 */
/* @0x2e19d0 ldr r3, [r0] */
/* @0x2e19d4 ldr r3, [r3, #0x28] */
/* @0x2e19d8 blx r3 */
/* @0x2e19dc ldr r3, [r4, #0x20] */
/* @0x2e19e0 cmp r3, r9 */
/* @0x2e19e4 and r10, r10, r0 */
/* @0x2e19e8 bgt 0x2e19c0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x3d8> */
/* @0x2e19ec tst r10, r11 */
/* @0x2e19f0 bne 0x2e1be0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5f8> */
/* @0x2e19f4 ldr r3, [r6, #0x10] */
/* @0x2e19f8 add r8, r8, #1 */
/* @0x2e19fc cmp r3, r8 */
/* @0x2e1a00 bgt 0x2e19a0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x3b8> */
/* @0x2e1a04 mov r12, #0 */
/* @0x2e1a08 str r12, [sp, #0xc] */
/* @0x2e1a0c ldr r10, [r4, #0x1c] */
/* @0x2e1a10 cmp r10, #0 */
/* @0x2e1a14 ble 0x2e1ab4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x4cc> */
/* @0x2e1a18 ldr r9, [r4, #0x8] */
/* @0x2e1a1c ldr r8, [r4, #0x14] */
/* @0x2e1a20 ldr r6, [r4, #0x18] */
/* @0x2e1a24 add r10, r9, r10, lsl #2 */
/* @0x2e1a28 add r8, r8, #8 */
/* @0x2e1a2c add r6, r6, #8 */
/* @0x2e1a30 ldr r5, [r9], #4 */
/* @0x2e1a34 ldmdb r8, {r0, r1} */
/* @0x2e1a38 add r2, r5, #60 */
/* @0x2e1a3c ldr r11, [r8], #12 */
/* @0x2e1a40 add r3, r5, #80 */
/* @0x2e1a44 stm r2, {r0, r1} */
/* @0x2e1a48 ldmdb r6, {r0, r1} */
/* @0x2e1a4c ldr r2, [r6], #12 */
/* @0x2e1a50 str r11, [r5, #0x48] */
/* @0x2e1a54 stm r3, {r0, r1} */
/* @0x2e1a58 mov r0, r11 */
/* @0x2e1a5c str r2, [r5, #0x58] */
/* @0x2e1a60 bl 0xb6580 <sinf@plt> */
/* @0x2e1a64 vmov s17, r0 */
/* @0x2e1a68 mov r0, r11 */
/* @0x2e1a6c vstr s17, [r5, #20] */
/* @0x2e1a70 bl 0xb658c <cosf@plt> */
/* @0x2e1a74 vldr s15, [r5, #48] */
/* @0x2e1a78 vmul.f32 s14, s15, s17 */
/* @0x2e1a7c vldr s12, [r5, #44] */
/* @0x2e1a80 vldr s10, [r5, #60] */
/* @0x2e1a84 vldr s11, [r5, #64] */
/* @0x2e1a88 cmp r9, r10 */
/* @0x2e1a8c vmov s13, r0 */
/* @0x2e1a90 str r0, [r5, #0x18] */
/* @0x2e1a94 vmul.f32 s15, s15, s13 */
/* @0x2e1a98 vnmls.f32 s14, s12, s13 */
/* @0x2e1a9c vmla.f32 s15, s12, s17 */
/* @0x2e1aa0 vsub.f32 s14, s10, s14 */
/* @0x2e1aa4 vsub.f32 s15, s11, s15 */
/* @0x2e1aa8 vstr s14, [r5, #12] */
/* @0x2e1aac vstr s15, [r5, #16] */
/* @0x2e1ab0 bne 0x2e1a30 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x448> */
/* @0x2e1ab4 add r0, sp, #16 */
/* @0x2e1ab8 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2e1abc ldr r12, [sp, #0x4] */
/* @0x2e1ac0 ldr r1, [sp, #0x8c] */
/* @0x2e1ac4 str r0, [r12, #0x14] */
/* @0x2e1ac8 mov r0, r4 */
/* @0x2e1acc bl 0x2e1224 <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint> */
/* @0x2e1ad0 ldr r12, [sp, #0x8] */
/* @0x2e1ad4 cmp r12, #0 */
/* @0x2e1ad8 beq 0x2e1bc0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5d8> */
/* @0x2e1adc ldr r3, [r4, #0x1c] */
/* @0x2e1ae0 cmp r3, #0 */
/* @0x2e1ae4 ble 0x2e1bc0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5d8> */
/* @0x2e1ae8 ldr r4, [r4, #0x8] */
/* @0x2e1aec lsl r5, r3, #2 */
/* @0x2e1af0 mov lr, #0 */
/* @0x2e1af4 vldr s15, [pc, #348] */
/* @0x2e1af8 add r0, r4, r5 */
/* @0x2e1afc vldr s12, [pc, #344] */
/* @0x2e1b00 mov r2, r4 */
/* @0x2e1b04 vldr s11, [pc, #340] */
/* @0x2e1b08 ldr r3, [r2], #4 */
/* @0x2e1b0c ldr r1, [r3] */
/* @0x2e1b10 cmp r1, #0 */
/* @0x2e1b14 beq 0x2e1b5c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x574> */
/* @0x2e1b18 ldrh r1, [r3, #4] */
/* @0x2e1b1c tst r1, #4 */
/* @0x2e1b20 beq 0x2e1b54 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x56c> */
/* @0x2e1b24 vldr s14, [r3, #88] */
/* @0x2e1b28 vmul.f32 s14, s14, s14 */
/* @0x2e1b2c vcmpe.f32 s14, s12 */
/* @0x2e1b30 vmrs APSR_nzcv, fpscr */
/* @0x2e1b34 bgt 0x2e1b54 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x56c> */
/* @0x2e1b38 vldr s14, [r3, #84] */
/* @0x2e1b3c vmul.f32 s14, s14, s14 */
/* @0x2e1b40 vldr s13, [r3, #80] */
/* @0x2e1b44 vmla.f32 s14, s13, s13 */
/* @0x2e1b48 vcmpe.f32 s14, s11 */
/* @0x2e1b4c vmrs APSR_nzcv, fpscr */
/* @0x2e1b50 ble 0x2e1c10 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x628> */
/* @0x2e1b54 str lr, [r3, #0xa0] */
/* @0x2e1b58 vldr s15, [pc, #260] */
/* @0x2e1b5c cmp r2, r0 */
/* @0x2e1b60 bne 0x2e1b08 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x520> */
/* @0x2e1b64 vmov.f32 s14, #5.000000e-01 */
/* @0x2e1b68 vcmpe.f32 s15, s14 */
/* @0x2e1b6c vmrs APSR_nzcv, fpscr */
/* @0x2e1b70 blt 0x2e1bc0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5d8> */
/* @0x2e1b74 ldr r3, [sp, #0xc] */
/* @0x2e1b78 cmp r3, #0 */
/* @0x2e1b7c beq 0x2e1bc0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5d8> */
/* @0x2e1b80 add r12, r4, r5 */
/* @0x2e1b84 mov r1, r4 */
/* @0x2e1b88 mov r2, #0 */
/* @0x2e1b8c ldr r3, [r1], #4 */
/* @0x2e1b90 cmp r1, r12 */
/* @0x2e1b94 ldrh r0, [r3, #4] */
/* @0x2e1b98 str r2, [r3, #0xa0] */
/* @0x2e1b9c bic r0, r0, #2 */
/* @0x2e1ba0 str r2, [r3, #0x50] */
/* @0x2e1ba4 str r2, [r3, #0x54] */
/* @0x2e1ba8 str r2, [r3, #0x58] */
/* @0x2e1bac str r2, [r3, #0x5c] */
/* @0x2e1bb0 str r2, [r3, #0x60] */
/* @0x2e1bb4 str r2, [r3, #0x64] */
/* @0x2e1bb8 strh r0, [r3, #4] */
/* @0x2e1bbc bne 0x2e1b8c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5a4> */
/* @0x2e1bc0 mov r0, r7 */
/* @0x2e1bc4 bl 0x2e2370 <_ZN15b2ContactSolverD2Ev> */
/* @0x2e1bc8 add sp, sp, #156 */
/* @0x2e1bcc vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2e1bd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e1bd4 mov r10, #1 */
/* @0x2e1bd8 tst r10, r11 */
/* @0x2e1bdc beq 0x2e19f4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x40c> */
/* @0x2e1be0 mov r3, #1 */
/* @0x2e1be4 str r3, [sp, #0xc] */
/* @0x2e1be8 b 0x2e1a0c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x424> */
/* @0x2e1bec vcmpe.f32 s8, #0 */
/* @0x2e1bf0 vmrs APSR_nzcv, fpscr */
/* @0x2e1bf4 vldrmi s8, [pc, #104] */
/* @0x2e1bf8 b 0x2e172c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x144> */
/* @0x2e1bfc vcmpe.f32 s11, #0 */
/* @0x2e1c00 vmrs APSR_nzcv, fpscr */
/* @0x2e1c04 vmovpl.f32 s9, s11 */
/* @0x2e1c08 vldrmi s9, [pc, #84] */
/* @0x2e1c0c b 0x2e1704 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x11c> */
/* @0x2e1c10 vldr s14, [r3, #160] */
/* @0x2e1c14 vadd.f32 s14, s16, s14 */
/* @0x2e1c18 vcmpe.f32 s14, s15 */
/* @0x2e1c1c vstr s14, [r3, #160] */
/* @0x2e1c20 vmrs APSR_nzcv, fpscr */
/* @0x2e1c24 vmovle.f32 s15, s14 */
/* @0x2e1c28 b 0x2e1b5c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x574> */
/* @0x2e1c2c mov r0, r7 */
/* @0x2e1c30 bl 0x2e27d0 <_ZN15b2ContactSolver9WarmStartEv> */
/* @0x2e1c34 b 0x2e17c4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x1dc> */
/* @0x2e1c38 vmov r0, s14 */
/* @0x2e1c3c bl 0xb6700 <sqrtf@plt> */
/* @0x2e1c40 vmov s15, r0 */
/* @0x2e1c44 add r0, r4, #20 */
/* @0x2e1c48 ldm r0, {r0, r1, r12} */
/* @0x2e1c4c b 0x2e1968 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x380> */
/* @0x2e1c50 andsmi lr, sp, r7, ror #19 */
/* @0x2e1c54 svclo #0xc90fdb */
/* @0x2e1c58 svcvc #0x7fffff */
/* @0x2e1c5c blo 0xfeacf0a8 <b2_toiTime+0xfffffffffe375c04> */
/* @0x2e1c60 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x2e1c64 andeq r0, r0, r0 */

/* ── FUNC 0x2e1c68 · b2ChainAndCircleContact::~b2ChainAndCircleContact() · size=24 · insn=6 */
/* @0x2e1c68 ldr r3, [pc, #0xc] */
/* @0x2e1c6c ldr r3, [pc, r3] */
/* @0x2e1c70 add r3, r3, #8 */
/* @0x2e1c74 str r3, [r0] */
/* @0x2e1c78 bx lr */
/* @0x2e1c7c mulseq r0, r4, lr */

/* ── FUNC 0x2e1c68 · b2ChainAndCircleContact::~b2ChainAndCircleContact() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e1c80 · b2ChainAndCircleContact::~b2ChainAndCircleContact() · size=40 · insn=10 */
/* @0x2e1c80 ldr r3, [pc, #0x1c] */
/* @0x2e1c84 push {r4, lr} */
/* @0x2e1c88 ldr r3, [pc, r3] */
/* @0x2e1c8c mov r4, r0 */
/* @0x2e1c90 add r3, r3, #8 */
/* @0x2e1c94 str r3, [r0] */
/* @0x2e1c98 bl 0x27d1d0 <_ZdlPv> */
/* @0x2e1c9c mov r0, r4 */
/* @0x2e1ca0 pop {r4, pc} */
/* @0x2e1ca4 andseq pc, r0, r8, ror lr */

/* ── FUNC 0x2e1ca8 · b2ChainAndCircleContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&) · size=156 · insn=39 */
/* @0x2e1ca8 push {r4, r5, r6, r7, r8, lr} */
/* @0x2e1cac mov r4, r0 */
/* @0x2e1cb0 sub sp, sp, #56 */
/* @0x2e1cb4 ldr r0, [r0, #0x30] */
/* @0x2e1cb8 add r5, sp, #8 */
/* @0x2e1cbc ldr r12, [pc, #0x7c] */
/* @0x2e1cc0 mov r7, r1 */
/* @0x2e1cc4 mov r6, r2 */
/* @0x2e1cc8 ldr r0, [r0, #0xc] */
/* @0x2e1ccc mov r1, r5 */
/* @0x2e1cd0 ldr r2, [r4, #0x38] */
/* @0x2e1cd4 ldr r12, [pc, r12] */
/* @0x2e1cd8 mov lr, #0 */
/* @0x2e1cdc mov r8, r3 */
/* @0x2e1ce0 strb lr, [sp, #0x34] */
/* @0x2e1ce4 add r12, r12, #8 */
/* @0x2e1ce8 strb lr, [sp, #0x35] */
/* @0x2e1cec mov r3, #1 */
/* @0x2e1cf0 str r12, [sp, #0x8] */
/* @0x2e1cf4 mov r12, #0 */
/* @0x2e1cf8 str r3, [sp, #0xc] */
/* @0x2e1cfc movw r3, #0xd70a */
/* @0x2e1d00 str r12, [sp, #0x24] */
/* @0x2e1d04 movt r3, #0x3c23 */
/* @0x2e1d08 str r12, [sp, #0x28] */
/* @0x2e1d0c str r3, [sp, #0x10] */
/* @0x2e1d10 str r12, [sp, #0x2c] */
/* @0x2e1d14 str r12, [sp, #0x30] */
/* @0x2e1d18 bl 0x2c4bf4 <_ZNK12b2ChainShape12GetChildEdgeEP11b2EdgeShapei> */
/* @0x2e1d1c ldr r3, [r4, #0x34] */
/* @0x2e1d20 mov r0, r7 */
/* @0x2e1d24 mov r1, r5 */
/* @0x2e1d28 mov r2, r6 */
/* @0x2e1d2c ldr r3, [r3, #0xc] */
/* @0x2e1d30 str r8, [sp] */
/* @0x2e1d34 bl 0x2dceb0 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_> */
/* @0x2e1d38 add sp, sp, #56 */
/* @0x2e1d3c pop {r4, r5, r6, r7, r8, pc} */
/* @0x2e1d40 andseq pc, r0, r0, ror #15 */

/* ── FUNC 0x2e1d44 · b2ChainAndCircleContact::Destroy(b2Contact*, b2BlockAllocator*) · size=44 · insn=11 */
/* @0x2e1d44 push {r3, r4, r5, lr} */
/* @0x2e1d48 mov r5, r1 */
/* @0x2e1d4c ldr r3, [r0] */
/* @0x2e1d50 mov r4, r0 */
/* @0x2e1d54 ldr r3, [r3, #0x4] */
/* @0x2e1d58 blx r3 */
/* @0x2e1d5c mov r0, r5 */
/* @0x2e1d60 mov r1, r4 */
/* @0x2e1d64 mov r2, #148 */
/* @0x2e1d68 pop {r3, r4, r5, lr} */
/* @0x2e1d6c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */

/* ── FUNC 0x2e1d70 · b2ChainAndCircleContact::b2ChainAndCircleContact(b2Fixture*, int, b2Fixture*, int) · size=56 · insn=14 */
/* @0x2e1d70 push {r4, lr} */
/* @0x2e1d74 sub sp, sp, #8 */
/* @0x2e1d78 mov r4, r0 */
/* @0x2e1d7c ldr r12, [sp, #0x10] */
/* @0x2e1d80 str r12, [sp] */
/* @0x2e1d84 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i> */
/* @0x2e1d88 ldr r3, [pc, #0x14] */
/* @0x2e1d8c mov r0, r4 */
/* @0x2e1d90 ldr r3, [pc, r3] */
/* @0x2e1d94 add r3, r3, #8 */
/* @0x2e1d98 str r3, [r4] */
/* @0x2e1d9c add sp, sp, #8 */
/* @0x2e1da0 pop {r4, pc} */
/* @0x2e1da4 andseq pc, r0, r0, lsl lr */

/* ── FUNC 0x2e1d70 · b2ChainAndCircleContact::b2ChainAndCircleContact(b2Fixture*, int, b2Fixture*, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e1da8 · b2ChainAndCircleContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*) · size=76 · insn=19 */
/* @0x2e1da8 push {r4, r5, r6, r7, r8, lr} */
/* @0x2e1dac sub sp, sp, #8 */
/* @0x2e1db0 mov r7, r0 */
/* @0x2e1db4 mov r6, r1 */
/* @0x2e1db8 ldr r0, [sp, #0x20] */
/* @0x2e1dbc mov r1, #148 */
/* @0x2e1dc0 mov r5, r2 */
/* @0x2e1dc4 mov r8, r3 */
/* @0x2e1dc8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2e1dcc subs r4, r0, #0 */
/* @0x2e1dd0 beq 0x2e1de8 <_ZN23b2ChainAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x40> */
/* @0x2e1dd4 str r8, [sp] */
/* @0x2e1dd8 mov r1, r7 */
/* @0x2e1ddc mov r2, r6 */
/* @0x2e1de0 mov r3, r5 */
/* @0x2e1de4 bl 0x2e1d70 <_ZN23b2ChainAndCircleContactC2EP9b2FixtureiS1_i> */
/* @0x2e1de8 mov r0, r4 */
/* @0x2e1dec add sp, sp, #8 */
/* @0x2e1df0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e1df4 · b2ChainAndPolygonContact::~b2ChainAndPolygonContact() · size=24 · insn=6 */
/* @0x2e1df4 ldr r3, [pc, #0xc] */
/* @0x2e1df8 ldr r3, [pc, r3] */
/* @0x2e1dfc add r3, r3, #8 */
/* @0x2e1e00 str r3, [r0] */
/* @0x2e1e04 bx lr */
/* @0x2e1e08 andseq pc, r0, r8, lsl #26 */

/* ── FUNC 0x2e1df4 · b2ChainAndPolygonContact::~b2ChainAndPolygonContact() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e1e0c · b2ChainAndPolygonContact::~b2ChainAndPolygonContact() · size=40 · insn=10 */
/* @0x2e1e0c ldr r3, [pc, #0x1c] */
/* @0x2e1e10 push {r4, lr} */
/* @0x2e1e14 ldr r3, [pc, r3] */
/* @0x2e1e18 mov r4, r0 */
/* @0x2e1e1c add r3, r3, #8 */
/* @0x2e1e20 str r3, [r0] */
/* @0x2e1e24 bl 0x27d1d0 <_ZdlPv> */
/* @0x2e1e28 mov r0, r4 */
/* @0x2e1e2c pop {r4, pc} */
/* @0x2e1e30 andseq pc, r0, r12, ror #25 */

/* ── FUNC 0x2e1e34 · b2ChainAndPolygonContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&) · size=156 · insn=39 */
/* @0x2e1e34 push {r4, r5, r6, r7, r8, lr} */
/* @0x2e1e38 mov r4, r0 */
/* @0x2e1e3c sub sp, sp, #56 */
/* @0x2e1e40 ldr r0, [r0, #0x30] */
/* @0x2e1e44 add r5, sp, #8 */
/* @0x2e1e48 ldr r12, [pc, #0x7c] */
/* @0x2e1e4c mov r7, r1 */
/* @0x2e1e50 mov r6, r2 */
/* @0x2e1e54 ldr r0, [r0, #0xc] */
/* @0x2e1e58 mov r1, r5 */
/* @0x2e1e5c ldr r2, [r4, #0x38] */
/* @0x2e1e60 ldr r12, [pc, r12] */
/* @0x2e1e64 mov lr, #0 */
/* @0x2e1e68 mov r8, r3 */
/* @0x2e1e6c strb lr, [sp, #0x34] */
/* @0x2e1e70 add r12, r12, #8 */
/* @0x2e1e74 strb lr, [sp, #0x35] */
/* @0x2e1e78 mov r3, #1 */
/* @0x2e1e7c str r12, [sp, #0x8] */
/* @0x2e1e80 mov r12, #0 */
/* @0x2e1e84 str r3, [sp, #0xc] */
/* @0x2e1e88 movw r3, #0xd70a */
/* @0x2e1e8c str r12, [sp, #0x24] */
/* @0x2e1e90 movt r3, #0x3c23 */
/* @0x2e1e94 str r12, [sp, #0x28] */
/* @0x2e1e98 str r3, [sp, #0x10] */
/* @0x2e1e9c str r12, [sp, #0x2c] */
/* @0x2e1ea0 str r12, [sp, #0x30] */
/* @0x2e1ea4 bl 0x2c4bf4 <_ZNK12b2ChainShape12GetChildEdgeEP11b2EdgeShapei> */
/* @0x2e1ea8 ldr r3, [r4, #0x34] */
/* @0x2e1eac mov r0, r7 */
/* @0x2e1eb0 mov r1, r5 */
/* @0x2e1eb4 mov r2, r6 */
/* @0x2e1eb8 ldr r3, [r3, #0xc] */
/* @0x2e1ebc str r8, [sp] */
/* @0x2e1ec0 bl 0x2de0bc <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_> */
/* @0x2e1ec4 add sp, sp, #56 */
/* @0x2e1ec8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2e1ecc andseq pc, r0, r4, asr r6 */

/* ── FUNC 0x2e1ed0 · b2ChainAndPolygonContact::Destroy(b2Contact*, b2BlockAllocator*) · size=44 · insn=11 */
/* @0x2e1ed0 push {r3, r4, r5, lr} */
/* @0x2e1ed4 mov r5, r1 */
/* @0x2e1ed8 ldr r3, [r0] */
/* @0x2e1edc mov r4, r0 */
/* @0x2e1ee0 ldr r3, [r3, #0x4] */
/* @0x2e1ee4 blx r3 */
/* @0x2e1ee8 mov r0, r5 */
/* @0x2e1eec mov r1, r4 */
/* @0x2e1ef0 mov r2, #148 */
/* @0x2e1ef4 pop {r3, r4, r5, lr} */
/* @0x2e1ef8 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */

/* ── FUNC 0x2e1efc · b2ChainAndPolygonContact::b2ChainAndPolygonContact(b2Fixture*, int, b2Fixture*, int) · size=56 · insn=14 */
/* @0x2e1efc push {r4, lr} */
/* @0x2e1f00 sub sp, sp, #8 */
/* @0x2e1f04 mov r4, r0 */
/* @0x2e1f08 ldr r12, [sp, #0x10] */
/* @0x2e1f0c str r12, [sp] */
/* @0x2e1f10 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i> */
/* @0x2e1f14 ldr r3, [pc, #0x14] */
/* @0x2e1f18 mov r0, r4 */
/* @0x2e1f1c ldr r3, [pc, r3] */
/* @0x2e1f20 add r3, r3, #8 */
/* @0x2e1f24 str r3, [r4] */
/* @0x2e1f28 add sp, sp, #8 */
/* @0x2e1f2c pop {r4, pc} */
/* @0x2e1f30 andseq pc, r0, r8, lsl #25 */

/* ── FUNC 0x2e1efc · b2ChainAndPolygonContact::b2ChainAndPolygonContact(b2Fixture*, int, b2Fixture*, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e1f34 · b2ChainAndPolygonContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*) · size=76 · insn=19 */
/* @0x2e1f34 push {r4, r5, r6, r7, r8, lr} */
/* @0x2e1f38 sub sp, sp, #8 */
/* @0x2e1f3c mov r7, r0 */
/* @0x2e1f40 mov r6, r1 */
/* @0x2e1f44 ldr r0, [sp, #0x20] */
/* @0x2e1f48 mov r1, #148 */
/* @0x2e1f4c mov r5, r2 */
/* @0x2e1f50 mov r8, r3 */
/* @0x2e1f54 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2e1f58 subs r4, r0, #0 */
/* @0x2e1f5c beq 0x2e1f74 <_ZN24b2ChainAndPolygonContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x40> */
/* @0x2e1f60 str r8, [sp] */
/* @0x2e1f64 mov r1, r7 */
/* @0x2e1f68 mov r2, r6 */
/* @0x2e1f6c mov r3, r5 */
/* @0x2e1f70 bl 0x2e1efc <_ZN24b2ChainAndPolygonContactC2EP9b2FixtureiS1_i> */
/* @0x2e1f74 mov r0, r4 */
/* @0x2e1f78 add sp, sp, #8 */
/* @0x2e1f7c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e1f80 · b2CircleContact::~b2CircleContact() · size=24 · insn=6 */
/* @0x2e1f80 ldr r3, [pc, #0xc] */
/* @0x2e1f84 ldr r3, [pc, r3] */
/* @0x2e1f88 add r3, r3, #8 */
/* @0x2e1f8c str r3, [r0] */
/* @0x2e1f90 bx lr */
/* @0x2e1f94 andseq pc, r0, r12, ror r11 */

/* ── FUNC 0x2e1f80 · b2CircleContact::~b2CircleContact() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e1f98 · b2CircleContact::~b2CircleContact() · size=40 · insn=10 */
/* @0x2e1f98 ldr r3, [pc, #0x1c] */
/* @0x2e1f9c push {r4, lr} */
/* @0x2e1fa0 ldr r3, [pc, r3] */
/* @0x2e1fa4 mov r4, r0 */
/* @0x2e1fa8 add r3, r3, #8 */
/* @0x2e1fac str r3, [r0] */
/* @0x2e1fb0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2e1fb4 mov r0, r4 */
/* @0x2e1fb8 pop {r4, pc} */
/* @0x2e1fbc andseq pc, r0, r0, ror #22 */

/* ── FUNC 0x2e1fc0 · b2CircleContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&) · size=52 · insn=13 */
/* @0x2e1fc0 mov r12, r0 */
/* @0x2e1fc4 mov r0, r1 */
/* @0x2e1fc8 ldr r1, [r12, #0x30] */
/* @0x2e1fcc ldr r12, [r12, #0x34] */
/* @0x2e1fd0 str lr, [sp, #-0x4]! */
/* @0x2e1fd4 sub sp, sp, #12 */
/* @0x2e1fd8 ldr r12, [r12, #0xc] */
/* @0x2e1fdc ldr r1, [r1, #0xc] */
/* @0x2e1fe0 str r3, [sp] */
/* @0x2e1fe4 mov r3, r12 */
/* @0x2e1fe8 bl 0x2dc9f0 <_Z16b2CollideCirclesP10b2ManifoldPK13b2CircleShapeRK11b2TransformS3_S6_> */
/* @0x2e1fec add sp, sp, #12 */
/* @0x2e1ff0 ldr pc, [sp], #4 */

/* ── FUNC 0x2e1ff4 · b2CircleContact::Destroy(b2Contact*, b2BlockAllocator*) · size=44 · insn=11 */
/* @0x2e1ff4 push {r3, r4, r5, lr} */
/* @0x2e1ff8 mov r5, r1 */
/* @0x2e1ffc ldr r3, [r0] */
/* @0x2e2000 mov r4, r0 */
/* @0x2e2004 ldr r3, [r3, #0x4] */
/* @0x2e2008 blx r3 */
/* @0x2e200c mov r0, r5 */
/* @0x2e2010 mov r1, r4 */
/* @0x2e2014 mov r2, #148 */
/* @0x2e2018 pop {r3, r4, r5, lr} */
/* @0x2e201c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */

/* ── FUNC 0x2e2020 · b2CircleContact::b2CircleContact(b2Fixture*, b2Fixture*) · size=60 · insn=15 */
/* @0x2e2020 push {r4, lr} */
/* @0x2e2024 sub sp, sp, #8 */
/* @0x2e2028 mov r3, r2 */
/* @0x2e202c mov r2, #0 */
/* @0x2e2030 str r2, [sp] */
/* @0x2e2034 mov r4, r0 */
/* @0x2e2038 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i> */
/* @0x2e203c ldr r3, [pc, #0x14] */
/* @0x2e2040 mov r0, r4 */
/* @0x2e2044 ldr r3, [pc, r3] */
/* @0x2e2048 add r3, r3, #8 */
/* @0x2e204c str r3, [r4] */
/* @0x2e2050 add sp, sp, #8 */
/* @0x2e2054 pop {r4, pc} */
/* @0x2e2058 andseq pc, r0, r4, ror #22 */

/* ── FUNC 0x2e2020 · b2CircleContact::b2CircleContact(b2Fixture*, b2Fixture*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e205c · b2CircleContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*) · size=52 · insn=13 */
/* @0x2e205c push {r4, r5, r6, lr} */
/* @0x2e2060 mov r1, #148 */
/* @0x2e2064 mov r5, r0 */
/* @0x2e2068 ldr r0, [sp, #0x10] */
/* @0x2e206c mov r6, r2 */
/* @0x2e2070 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2e2074 subs r4, r0, #0 */
/* @0x2e2078 beq 0x2e2088 <_ZN15b2CircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c> */
/* @0x2e207c mov r1, r5 */
/* @0x2e2080 mov r2, r6 */
/* @0x2e2084 bl 0x2e2020 <_ZN15b2CircleContactC2EP9b2FixtureS1_> */
/* @0x2e2088 mov r0, r4 */
/* @0x2e208c pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e2090 · b2ContactSolver::b2ContactSolver(b2ContactSolverDef*) · size=736 · insn=184 */
/* @0x2e2090 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e2094 mov lr, r1 */
/* @0x2e2098 mov r4, r0 */
/* @0x2e209c mov r5, r1 */
/* @0x2e20a0 mov r12, r0 */
/* @0x2e20a4 ldr r7, [r5, #0x28] */
/* @0x2e20a8 ldm lr!, {r0, r1, r2, r3} */
/* @0x2e20ac mov r8, #88 */
/* @0x2e20b0 ldr r6, [r5, #0x1c] */
/* @0x2e20b4 sub sp, sp, #20 */
/* @0x2e20b8 stm r12!, {r0, r1, r2, r3} */
/* @0x2e20bc ldm lr, {r0, r1} */
/* @0x2e20c0 stm r12, {r0, r1} */
/* @0x2e20c4 mov r0, r7 */
/* @0x2e20c8 mul r1, r8, r6 */
/* @0x2e20cc str r7, [r4, #0x20] */
/* @0x2e20d0 str r6, [r4, #0x30] */
/* @0x2e20d4 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2e20d8 ldr r3, [r4, #0x30] */
/* @0x2e20dc mov r1, #156 */
/* @0x2e20e0 mul r1, r1, r3 */
/* @0x2e20e4 str r0, [r4, #0x24] */
/* @0x2e20e8 ldr r0, [r4, #0x20] */
/* @0x2e20ec bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2e20f0 ldr r2, [r4, #0x30] */
/* @0x2e20f4 ldr r1, [r5, #0x20] */
/* @0x2e20f8 ldr r3, [r5, #0x24] */
/* @0x2e20fc cmp r2, #0 */
/* @0x2e2100 str r2, [sp, #0x8] */
/* @0x2e2104 ldr r2, [r5, #0x18] */
/* @0x2e2108 str r1, [r4, #0x18] */
/* @0x2e210c str r3, [r4, #0x1c] */
/* @0x2e2110 str r2, [r4, #0x2c] */
/* @0x2e2114 str r0, [r4, #0x28] */
/* @0x2e2118 ble 0x2e2360 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x2d0> */
/* @0x2e211c ldr r3, [r4, #0x24] */
/* @0x2e2120 vldr s15, [pc, #580] */
/* @0x2e2124 str r3, [sp, #0xc] */
/* @0x2e2128 mov r3, #0 */
/* @0x2e212c str r3, [sp] */
/* @0x2e2130 mov r3, r0 */
/* @0x2e2134 mov r0, #0 */
/* @0x2e2138 str r0, [sp, #0x4] */
/* @0x2e213c mov r5, r0 */
/* @0x2e2140 ldr r12, [r2, r5, lsl #2] */
/* @0x2e2144 vldr s14, [r12, #140] */
/* @0x2e2148 ldr r2, [sp, #0x4] */
/* @0x2e214c vldr s9, [r12, #136] */
/* @0x2e2150 ldr r0, [sp, #0xc] */
/* @0x2e2154 ldr r8, [r12, #0x30] */
/* @0x2e2158 add r3, r3, r2 */
/* @0x2e215c ldr r10, [r12, #0x34] */
/* @0x2e2160 ldr r1, [sp] */
/* @0x2e2164 ldr r9, [r8, #0x8] */
/* @0x2e2168 vldr s12, [r9, #136] */
/* @0x2e216c add r2, r0, r1 */
/* @0x2e2170 ldr r11, [r12, #0x90] */
/* @0x2e2174 ldr r1, [r10, #0x8] */
/* @0x2e2178 vldr s13, [r9, #144] */
/* @0x2e217c ldr r6, [r12, #0x7c] */
/* @0x2e2180 add r0, r9, #44 */
/* @0x2e2184 ldr r8, [r8, #0xc] */
/* @0x2e2188 vldr s10, [r8, #8] */
/* @0x2e218c ldr r9, [r9, #0x8] */
/* @0x2e2190 add r7, r2, #48 */
/* @0x2e2194 ldr r8, [r1, #0x8] */
/* @0x2e2198 cmp r6, #0 */
/* @0x2e219c ldr r10, [r10, #0xc] */
/* @0x2e21a0 vldr s11, [r10, #8] */
/* @0x2e21a4 str r11, [r3, #0x90] */
/* @0x2e21a8 add r10, r1, #44 */
/* @0x2e21ac ldr r11, [r1, #0x88] */
/* @0x2e21b0 vstr s14, [r3, #140] */
/* @0x2e21b4 str r9, [r3, #0x70] */
/* @0x2e21b8 vldr s14, [r1, #144] */
/* @0x2e21bc str r8, [r3, #0x74] */
/* @0x2e21c0 vstr s9, [r3, #136] */
/* @0x2e21c4 str r11, [r3, #0x7c] */
/* @0x2e21c8 vstr s12, [r3, #120] */
/* @0x2e21cc vstr s13, [r3, #128] */
/* @0x2e21d0 vstr s14, [r3, #132] */
/* @0x2e21d4 str r6, [r3, #0x94] */
/* @0x2e21d8 str r5, [r3, #0x98] */
/* @0x2e21dc vstr s15, [r3, #96] */
/* @0x2e21e0 ldm r0, {r0, r1} */
/* @0x2e21e4 vstr s15, [r3, #104] */
/* @0x2e21e8 vstr s15, [r3, #100] */
/* @0x2e21ec vstr s15, [r3, #108] */
/* @0x2e21f0 vstr s15, [r3, #80] */
/* @0x2e21f4 vstr s15, [r3, #88] */
/* @0x2e21f8 vstr s15, [r3, #84] */
/* @0x2e21fc vstr s15, [r3, #92] */
/* @0x2e2200 str r9, [r2, #0x20] */
/* @0x2e2204 vstr s12, [r2, #40] */
/* @0x2e2208 str r8, [r2, #0x24] */
/* @0x2e220c add r9, r12, #104 */
/* @0x2e2210 str r11, [r2, #0x2c] */
/* @0x2e2214 add r8, r2, #16 */
/* @0x2e2218 stm r7, {r0, r1} */
/* @0x2e221c add r7, r12, #112 */
/* @0x2e2220 ldm r10, {r0, r1} */
/* @0x2e2224 add r10, r2, #56 */
/* @0x2e2228 ldr r11, [r12, #0x78] */
/* @0x2e222c stm r10, {r0, r1} */
/* @0x2e2230 vstr s13, [r2, #64] */
/* @0x2e2234 ldm r9, {r0, r1} */
/* @0x2e2238 vstr s14, [r2, #68] */
/* @0x2e223c add r9, r2, #24 */
/* @0x2e2240 stm r8, {r0, r1} */
/* @0x2e2244 ldm r7, {r0, r1} */
/* @0x2e2248 stm r9, {r0, r1} */
/* @0x2e224c vstr s10, [r2, #76] */
/* @0x2e2250 vstr s11, [r2, #80] */
/* @0x2e2254 str r6, [r2, #0x54] */
/* @0x2e2258 str r11, [r2, #0x48] */
/* @0x2e225c ble 0x2e22c8 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x238> */
/* @0x2e2260 ldrb r1, [r4, #0x14] */
/* @0x2e2264 add r8, r3, #8 */
/* @0x2e2268 lsl r6, r6, #3 */
/* @0x2e226c add r3, r3, #32 */
/* @0x2e2270 cmp r1, #0 */
/* @0x2e2274 mov r7, #0 */
/* @0x2e2278 bne 0x2e22fc <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x26c> */
/* @0x2e227c vmov r0, s15 */
/* @0x2e2280 add r1, r12, #64 */
/* @0x2e2284 vstr s15, [r3, #-16] */
/* @0x2e2288 vstr s15, [r3, #-12] */
/* @0x2e228c vstr s15, [r3, #-32] */
/* @0x2e2290 vstr s15, [r3, #-28] */
/* @0x2e2294 add r9, r2, r7 */
/* @0x2e2298 vstr s15, [r8] */
/* @0x2e229c vstr s15, [r8, #4] */
/* @0x2e22a0 add r7, r7, #8 */
/* @0x2e22a4 vstr s15, [r3, #-8] */
/* @0x2e22a8 vstr s15, [r3, #-4] */
/* @0x2e22ac cmp r7, r6 */
/* @0x2e22b0 add r8, r8, #36 */
/* @0x2e22b4 add r12, r12, #20 */
/* @0x2e22b8 str r0, [r3], #36 */
/* @0x2e22bc ldm r1, {r0, r1} */
/* @0x2e22c0 stm r9, {r0, r1} */
/* @0x2e22c4 bne 0x2e227c <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x1ec> */
/* @0x2e22c8 ldr r2, [sp, #0x4] */
/* @0x2e22cc add r5, r5, #1 */
/* @0x2e22d0 ldr r3, [sp, #0x8] */
/* @0x2e22d4 add r2, r2, #156 */
/* @0x2e22d8 str r2, [sp, #0x4] */
/* @0x2e22dc cmp r3, r5 */
/* @0x2e22e0 ldr r2, [sp] */
/* @0x2e22e4 add r2, r2, #88 */
/* @0x2e22e8 str r2, [sp] */
/* @0x2e22ec ble 0x2e2360 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x2d0> */
/* @0x2e22f0 ldr r2, [r4, #0x2c] */
/* @0x2e22f4 ldr r3, [r4, #0x28] */
/* @0x2e22f8 b 0x2e2140 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0xb0> */
/* @0x2e22fc vldr s13, [r4, #8] */
/* @0x2e2300 vldr s14, [r12, #72] */
/* @0x2e2304 vmul.f32 s14, s13, s14 */
/* @0x2e2308 add r1, r12, #64 */
/* @0x2e230c vmov r0, s15 */
/* @0x2e2310 add r9, r2, r7 */
/* @0x2e2314 add r7, r7, #8 */
/* @0x2e2318 add r12, r12, #20 */
/* @0x2e231c cmp r7, r6 */
/* @0x2e2320 add r8, r8, #36 */
/* @0x2e2324 vstr s14, [r3, #-16] */
/* @0x2e2328 vldr s14, [r12, #56] */
/* @0x2e232c vmul.f32 s14, s13, s14 */
/* @0x2e2330 vstr s15, [r3, #-32] */
/* @0x2e2334 vstr s15, [r3, #-28] */
/* @0x2e2338 vstr s14, [r3, #-12] */
/* @0x2e233c vstr s15, [r8, #-36] */
/* @0x2e2340 vstr s15, [r8, #-32] */
/* @0x2e2344 vstr s15, [r3, #-8] */
/* @0x2e2348 vstr s15, [r3, #-4] */
/* @0x2e234c str r0, [r3], #36 */
/* @0x2e2350 ldm r1, {r0, r1} */
/* @0x2e2354 stm r9, {r0, r1} */
/* @0x2e2358 bne 0x2e22fc <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x26c> */
/* @0x2e235c b 0x2e22c8 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x238> */
/* @0x2e2360 mov r0, r4 */
/* @0x2e2364 add sp, sp, #20 */
/* @0x2e2368 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e236c andeq r0, r0, r0 */

/* ── FUNC 0x2e2090 · b2ContactSolver::b2ContactSolver(b2ContactSolverDef*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e2370 · b2ContactSolver::~b2ContactSolver() · size=40 · insn=10 */
/* @0x2e2370 push {r4, lr} */
/* @0x2e2374 mov r4, r0 */
/* @0x2e2378 ldr r1, [r4, #0x28] */
/* @0x2e237c ldr r0, [r0, #0x20] */
/* @0x2e2380 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e2384 ldr r0, [r4, #0x20] */
/* @0x2e2388 ldr r1, [r4, #0x24] */
/* @0x2e238c bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2e2390 mov r0, r4 */
/* @0x2e2394 pop {r4, pc} */
