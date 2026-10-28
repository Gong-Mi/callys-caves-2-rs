/* libyoyo.so 覆盖卡组 0012
 * 函数 0xd13bc..0xd3464，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xd13bc · GET_RValue(RValue*, RValue*, int) · size=1840 · insn=460 */
/* @0xd13bc ldr r3, [r1, #0xc] */
/* @0xd13c0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xd13c4 mov r5, r1 */
/* @0xd13c8 bic r1, r3, #-16777216 */
/* @0xd13cc ldr r6, [pc, #0x6fc] */
/* @0xd13d0 cmp r1, #2 */
/* @0xd13d4 sub sp, sp, #12 */
/* @0xd13d8 add r6, pc, r6 */
/* @0xd13dc mov r4, r0 */
/* @0xd13e0 beq 0xd1594 <_Z10GET_RValueP6RValueS0_i+0x1d8> */
/* @0xd13e4 cmp r2, #-2147483648 */
/* @0xd13e8 beq 0xd13f8 <_Z10GET_RValueP6RValueS0_i+0x3c> */
/* @0xd13ec ldr r0, [pc, #0x6e0] */
/* @0xd13f0 add r0, pc, r0 */
/* @0xd13f4 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd13f8 ldr r2, [r4, #0xc] */
/* @0xd13fc bic r3, r2, #-16777216 */
/* @0xd1400 cmp r3, #1 */
/* @0xd1404 beq 0xd149c <_Z10GET_RValueP6RValueS0_i+0xe0> */
/* @0xd1408 cmp r3, #2 */
/* @0xd140c bne 0xd1434 <_Z10GET_RValueP6RValueS0_i+0x78> */
/* @0xd1410 sub r2, r2, #1 */
/* @0xd1414 bic r2, r2, #-16777216 */
/* @0xd1418 bic r2, r2, #3 */
/* @0xd141c cmp r2, #0 */
/* @0xd1420 beq 0xd1588 <_Z10GET_RValueP6RValueS0_i+0x1cc> */
/* @0xd1424 mov r2, #0 */
/* @0xd1428 mov r3, #5 */
/* @0xd142c str r2, [r4, #0x8] */
/* @0xd1430 str r3, [r4, #0xc] */
/* @0xd1434 ldr r3, [r5, #0xc] */
/* @0xd1438 mov r1, #0 */
/* @0xd143c ldr r2, [r5, #0x8] */
/* @0xd1440 str r1, [r4] */
/* @0xd1444 str r3, [r4, #0xc] */
/* @0xd1448 ldr r3, [r5, #0xc] */
/* @0xd144c str r2, [r4, #0x8] */
/* @0xd1450 bic r3, r3, #-16777216 */
/* @0xd1454 cmp r3, #14 */
/* @0xd1458 addls pc, pc, r3, lsl #2 */
/* @0xd145c b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1460 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128> */
/* @0xd1464 b 0xd1524 <_Z10GET_RValueP6RValueS0_i+0x168> */
/* @0xd1468 b 0xd154c <_Z10GET_RValueP6RValueS0_i+0x190> */
/* @0xd146c b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114> */
/* @0xd1470 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1474 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1478 b 0xd14fc <_Z10GET_RValueP6RValueS0_i+0x140> */
/* @0xd147c b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114> */
/* @0xd1480 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1484 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1488 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128> */
/* @0xd148c b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1490 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1494 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128> */
/* @0xd1498 b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114> */
/* @0xd149c ldr r6, [r4] */
/* @0xd14a0 cmp r6, #0 */
/* @0xd14a4 beq 0xd14c4 <_Z10GET_RValueP6RValueS0_i+0x108> */
/* @0xd14a8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd14ac ldr r7, [r6, #0x4] */
/* @0xd14b0 sub r7, r7, #1 */
/* @0xd14b4 str r7, [r6, #0x4] */
/* @0xd14b8 cmp r7, #0 */
/* @0xd14bc beq 0xd162c <_Z10GET_RValueP6RValueS0_i+0x270> */
/* @0xd14c0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd14c4 mov r3, #0 */
/* @0xd14c8 str r3, [r4] */
/* @0xd14cc b 0xd1434 <_Z10GET_RValueP6RValueS0_i+0x78> */
/* @0xd14d0 ldr r3, [r5] */
/* @0xd14d4 mov r0, #1 */
/* @0xd14d8 str r3, [r4] */
/* @0xd14dc add sp, sp, #12 */
/* @0xd14e0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd14e4 ldr r2, [r5] */
/* @0xd14e8 mov r0, #1 */
/* @0xd14ec ldr r3, [r5, #0x4] */
/* @0xd14f0 stm r4, {r2, r3} */
/* @0xd14f4 add sp, sp, #12 */
/* @0xd14f8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd14fc ldr r3, [r5] */
/* @0xd1500 str r3, [r4] */
/* @0xd1504 ldr r3, [r5] */
/* @0xd1508 cmp r3, #0 */
/* @0xd150c beq 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1510 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd1514 ldr r1, [r5] */
/* @0xd1518 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd151c mov r0, #1 */
/* @0xd1520 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120> */
/* @0xd1524 ldr r3, [r5] */
/* @0xd1528 cmp r3, #0 */
/* @0xd152c beq 0xd153c <_Z10GET_RValueP6RValueS0_i+0x180> */
/* @0xd1530 ldr r2, [r3, #0x4] */
/* @0xd1534 add r2, r2, #1 */
/* @0xd1538 str r2, [r3, #0x4] */
/* @0xd153c mov r0, #1 */
/* @0xd1540 str r3, [r4] */
/* @0xd1544 add sp, sp, #12 */
/* @0xd1548 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd154c ldr r3, [r5] */
/* @0xd1550 cmp r3, #0 */
/* @0xd1554 str r3, [r4] */
/* @0xd1558 beq 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd155c ldr r1, [r3, #0x8] */
/* @0xd1560 ldr r2, [r3] */
/* @0xd1564 cmp r1, #0 */
/* @0xd1568 streq r4, [r3, #0x8] */
/* @0xd156c add r2, r2, #1 */
/* @0xd1570 str r2, [r3] */
/* @0xd1574 moveq r0, #1 */
/* @0xd1578 beq 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120> */
/* @0xd157c mov r0, #1 */
/* @0xd1580 add sp, sp, #12 */
/* @0xd1584 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd1588 mov r0, r4 */
/* @0xd158c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xd1590 b 0xd1424 <_Z10GET_RValueP6RValueS0_i+0x68> */
/* @0xd1594 cmp r2, #-2147483648 */
/* @0xd1598 beq 0xd185c <_Z10GET_RValueP6RValueS0_i+0x4a0> */
/* @0xd159c mov r1, r2 */
/* @0xd15a0 mov r0, sp */
/* @0xd15a4 mov r2, #32000 */
/* @0xd15a8 bl 0xb664c <ldiv@plt> */
/* @0xd15ac ldr r3, [r5, #0xc] */
/* @0xd15b0 ldr r2, [sp] */
/* @0xd15b4 bic r3, r3, #-16777216 */
/* @0xd15b8 ldr r7, [sp, #0x4] */
/* @0xd15bc cmp r3, #2 */
/* @0xd15c0 beq 0xd16c8 <_Z10GET_RValueP6RValueS0_i+0x30c> */
/* @0xd15c4 ldr r0, [pc, #0x50c] */
/* @0xd15c8 mov r12, #1 */
/* @0xd15cc ldr r1, [pc, #0x508] */
/* @0xd15d0 cmp r3, #2 */
/* @0xd15d4 ldr r3, [pc, #0x504] */
/* @0xd15d8 ldr r0, [r6, r0] */
/* @0xd15dc strb r12, [r0] */
/* @0xd15e0 ldr r1, [r6, r1] */
/* @0xd15e4 str r2, [r1] */
/* @0xd15e8 ldr r3, [r6, r3] */
/* @0xd15ec str r7, [r3] */
/* @0xd15f0 beq 0xd169c <_Z10GET_RValueP6RValueS0_i+0x2e0> */
/* @0xd15f4 ldr r3, [pc, #0x4e8] */
/* @0xd15f8 mvn r1, #0 */
/* @0xd15fc mov r2, #0 */
/* @0xd1600 ldr r3, [r6, r3] */
/* @0xd1604 str r2, [r3] */
/* @0xd1608 ldr r2, [pc, #0x4d8] */
/* @0xd160c mov r3, #0 */
/* @0xd1610 mov r0, r3 */
/* @0xd1614 ldr r2, [r6, r2] */
/* @0xd1618 str r3, [r4, #0xc] */
/* @0xd161c str r3, [r4, #0x4] */
/* @0xd1620 str r1, [r2] */
/* @0xd1624 str r3, [r4] */
/* @0xd1628 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120> */
/* @0xd162c ldr r0, [r6] */
/* @0xd1630 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd1634 str r7, [r6] */
/* @0xd1638 str r7, [r6, #0x8] */
/* @0xd163c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd1640 ldr r7, [r6, #0x4] */
/* @0xd1644 sub r7, r7, #1 */
/* @0xd1648 str r7, [r6, #0x4] */
/* @0xd164c cmp r7, #0 */
/* @0xd1650 beq 0xd1664 <_Z10GET_RValueP6RValueS0_i+0x2a8> */
/* @0xd1654 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd1658 mov r0, r6 */
/* @0xd165c bl 0x27d1d0 <_ZdlPv> */
/* @0xd1660 b 0xd14c0 <_Z10GET_RValueP6RValueS0_i+0x104> */
/* @0xd1664 ldr r0, [r6] */
/* @0xd1668 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd166c str r7, [r6] */
/* @0xd1670 str r7, [r6, #0x8] */
/* @0xd1674 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd1678 ldr r7, [r6, #0x4] */
/* @0xd167c sub r7, r7, #1 */
/* @0xd1680 str r7, [r6, #0x4] */
/* @0xd1684 cmp r7, #0 */
/* @0xd1688 beq 0xd19e4 <_Z10GET_RValueP6RValueS0_i+0x628> */
/* @0xd168c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd1690 mov r0, r6 */
/* @0xd1694 bl 0x27d1d0 <_ZdlPv> */
/* @0xd1698 b 0xd1654 <_Z10GET_RValueP6RValueS0_i+0x298> */
/* @0xd169c mov r3, #0 */
/* @0xd16a0 ldr r2, [r5] */
/* @0xd16a4 ldr r1, [pc, #0x438] */
/* @0xd16a8 cmp r2, #0 */
/* @0xd16ac ldr r1, [r6, r1] */
/* @0xd16b0 ldrne r2, [r2, #0x10] */
/* @0xd16b4 cmp r3, #0 */
/* @0xd16b8 str r2, [r1] */
/* @0xd16bc mvneq r1, #0 */
/* @0xd16c0 ldrne r1, [r3] */
/* @0xd16c4 b 0xd1608 <_Z10GET_RValueP6RValueS0_i+0x24c> */
/* @0xd16c8 ldr r1, [r5] */
/* @0xd16cc ldr r0, [r1, #0x8] */
/* @0xd16d0 cmp r0, #0 */
/* @0xd16d4 streq r5, [r1, #0x8] */
/* @0xd16d8 cmp r2, #0 */
/* @0xd16dc blt 0xd15c4 <_Z10GET_RValueP6RValueS0_i+0x208> */
/* @0xd16e0 ldr r0, [r1, #0x10] */
/* @0xd16e4 cmp r0, r2 */
/* @0xd16e8 ble 0xd15c4 <_Z10GET_RValueP6RValueS0_i+0x208> */
/* @0xd16ec ldr r1, [r1, #0x4] */
/* @0xd16f0 cmp r7, #0 */
/* @0xd16f4 add r3, r1, r2, lsl #3 */
/* @0xd16f8 blt 0xd1a48 <_Z10GET_RValueP6RValueS0_i+0x68c> */
/* @0xd16fc ldr r1, [r1, r2, lsl #3] */
/* @0xd1700 cmp r7, r1 */
/* @0xd1704 bge 0xd1a48 <_Z10GET_RValueP6RValueS0_i+0x68c> */
/* @0xd1708 ldr r9, [r3, #0x4] */
/* @0xd170c adds r8, r9, r7, lsl #4 */
/* @0xd1710 beq 0xd1a48 <_Z10GET_RValueP6RValueS0_i+0x68c> */
/* @0xd1714 ldr r2, [r4, #0xc] */
/* @0xd1718 bic r3, r2, #-16777216 */
/* @0xd171c cmp r3, #1 */
/* @0xd1720 beq 0xd1828 <_Z10GET_RValueP6RValueS0_i+0x46c> */
/* @0xd1724 cmp r3, #2 */
/* @0xd1728 bne 0xd1750 <_Z10GET_RValueP6RValueS0_i+0x394> */
/* @0xd172c sub r3, r2, #1 */
/* @0xd1730 bic r3, r3, #-16777216 */
/* @0xd1734 bic r3, r3, #3 */
/* @0xd1738 cmp r3, #0 */
/* @0xd173c beq 0xd1a3c <_Z10GET_RValueP6RValueS0_i+0x680> */
/* @0xd1740 mov r2, #0 */
/* @0xd1744 mov r3, #5 */
/* @0xd1748 str r2, [r4, #0x8] */
/* @0xd174c str r3, [r4, #0xc] */
/* @0xd1750 ldr r3, [r8, #0xc] */
/* @0xd1754 mov r1, #0 */
/* @0xd1758 ldr r2, [r8, #0x8] */
/* @0xd175c str r1, [r4] */
/* @0xd1760 str r3, [r4, #0xc] */
/* @0xd1764 ldr r3, [r8, #0xc] */
/* @0xd1768 str r2, [r4, #0x8] */
/* @0xd176c bic r3, r3, #-16777216 */
/* @0xd1770 cmp r3, #14 */
/* @0xd1774 addls pc, pc, r3, lsl #2 */
/* @0xd1778 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd177c b 0xd17c8 <_Z10GET_RValueP6RValueS0_i+0x40c> */
/* @0xd1780 b 0xd1818 <_Z10GET_RValueP6RValueS0_i+0x45c> */
/* @0xd1784 b 0xd1804 <_Z10GET_RValueP6RValueS0_i+0x448> */
/* @0xd1788 b 0xd17b8 <_Z10GET_RValueP6RValueS0_i+0x3fc> */
/* @0xd178c b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1790 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1794 b 0xd17dc <_Z10GET_RValueP6RValueS0_i+0x420> */
/* @0xd1798 b 0xd17b8 <_Z10GET_RValueP6RValueS0_i+0x3fc> */
/* @0xd179c b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd17a0 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd17a4 b 0xd17c8 <_Z10GET_RValueP6RValueS0_i+0x40c> */
/* @0xd17a8 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd17ac b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd17b0 b 0xd17c8 <_Z10GET_RValueP6RValueS0_i+0x40c> */
/* @0xd17b4 b 0xd17b8 <_Z10GET_RValueP6RValueS0_i+0x3fc> */
/* @0xd17b8 ldr r3, [r9, r7, lsl #4] */
/* @0xd17bc mov r0, #1 */
/* @0xd17c0 str r3, [r4] */
/* @0xd17c4 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120> */
/* @0xd17c8 ldr r2, [r9, r7, lsl #4] */
/* @0xd17cc mov r0, #1 */
/* @0xd17d0 ldr r3, [r8, #0x4] */
/* @0xd17d4 stm r4, {r2, r3} */
/* @0xd17d8 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120> */
/* @0xd17dc ldr r3, [r9, r7, lsl #4] */
/* @0xd17e0 str r3, [r4] */
/* @0xd17e4 ldr r3, [r9, r7, lsl #4] */
/* @0xd17e8 cmp r3, #0 */
/* @0xd17ec beq 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd17f0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd17f4 ldr r1, [r9, r7, lsl #4] */
/* @0xd17f8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd17fc mov r0, #1 */
/* @0xd1800 b 0xd14dc <_Z10GET_RValueP6RValueS0_i+0x120> */
/* @0xd1804 ldr r3, [r9, r7, lsl #4] */
/* @0xd1808 cmp r3, #0 */
/* @0xd180c str r3, [r4] */
/* @0xd1810 bne 0xd155c <_Z10GET_RValueP6RValueS0_i+0x1a0> */
/* @0xd1814 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1818 ldr r3, [r9, r7, lsl #4] */
/* @0xd181c cmp r3, #0 */
/* @0xd1820 bne 0xd1530 <_Z10GET_RValueP6RValueS0_i+0x174> */
/* @0xd1824 b 0xd153c <_Z10GET_RValueP6RValueS0_i+0x180> */
/* @0xd1828 ldr r5, [r4] */
/* @0xd182c cmp r5, #0 */
/* @0xd1830 beq 0xd1850 <_Z10GET_RValueP6RValueS0_i+0x494> */
/* @0xd1834 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd1838 ldr r6, [r5, #0x4] */
/* @0xd183c sub r6, r6, #1 */
/* @0xd1840 str r6, [r5, #0x4] */
/* @0xd1844 cmp r6, #0 */
/* @0xd1848 beq 0xd19ac <_Z10GET_RValueP6RValueS0_i+0x5f0> */
/* @0xd184c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd1850 mov r3, #0 */
/* @0xd1854 str r3, [r4] */
/* @0xd1858 b 0xd1750 <_Z10GET_RValueP6RValueS0_i+0x394> */
/* @0xd185c ldr r2, [r5] */
/* @0xd1860 ldr r1, [r2, #0x8] */
/* @0xd1864 cmp r1, #0 */
/* @0xd1868 streq r5, [r2, #0x8] */
/* @0xd186c ldr r1, [r4, #0xc] */
/* @0xd1870 bic r2, r1, #-16777216 */
/* @0xd1874 cmp r2, #1 */
/* @0xd1878 beq 0xd1910 <_Z10GET_RValueP6RValueS0_i+0x554> */
/* @0xd187c cmp r2, #2 */
/* @0xd1880 bne 0xd18ac <_Z10GET_RValueP6RValueS0_i+0x4f0> */
/* @0xd1884 sub r1, r1, #1 */
/* @0xd1888 bic r1, r1, #-16777216 */
/* @0xd188c bic r1, r1, #3 */
/* @0xd1890 cmp r1, #0 */
/* @0xd1894 beq 0xd19a0 <_Z10GET_RValueP6RValueS0_i+0x5e4> */
/* @0xd1898 mov r3, #0 */
/* @0xd189c mov r2, #5 */
/* @0xd18a0 str r3, [r4, #0x8] */
/* @0xd18a4 str r2, [r4, #0xc] */
/* @0xd18a8 ldr r3, [r5, #0xc] */
/* @0xd18ac ldr r2, [r5, #0x8] */
/* @0xd18b0 mov r1, #0 */
/* @0xd18b4 str r3, [r4, #0xc] */
/* @0xd18b8 ldr r3, [r5, #0xc] */
/* @0xd18bc str r1, [r4] */
/* @0xd18c0 bic r3, r3, #-16777216 */
/* @0xd18c4 str r2, [r4, #0x8] */
/* @0xd18c8 cmp r3, #14 */
/* @0xd18cc addls pc, pc, r3, lsl #2 */
/* @0xd18d0 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd18d4 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128> */
/* @0xd18d8 b 0xd1524 <_Z10GET_RValueP6RValueS0_i+0x168> */
/* @0xd18dc b 0xd154c <_Z10GET_RValueP6RValueS0_i+0x190> */
/* @0xd18e0 b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114> */
/* @0xd18e4 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd18e8 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd18ec b 0xd14fc <_Z10GET_RValueP6RValueS0_i+0x140> */
/* @0xd18f0 b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114> */
/* @0xd18f4 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd18f8 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd18fc b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128> */
/* @0xd1900 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1904 b 0xd157c <_Z10GET_RValueP6RValueS0_i+0x1c0> */
/* @0xd1908 b 0xd14e4 <_Z10GET_RValueP6RValueS0_i+0x128> */
/* @0xd190c b 0xd14d0 <_Z10GET_RValueP6RValueS0_i+0x114> */
/* @0xd1910 ldr r6, [r4] */
/* @0xd1914 cmp r6, #0 */
/* @0xd1918 beq 0xd193c <_Z10GET_RValueP6RValueS0_i+0x580> */
/* @0xd191c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd1920 ldr r7, [r6, #0x4] */
/* @0xd1924 sub r7, r7, #1 */
/* @0xd1928 str r7, [r6, #0x4] */
/* @0xd192c cmp r7, #0 */
/* @0xd1930 beq 0xd1948 <_Z10GET_RValueP6RValueS0_i+0x58c> */
/* @0xd1934 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd1938 ldr r3, [r5, #0xc] */
/* @0xd193c mov r2, #0 */
/* @0xd1940 str r2, [r4] */
/* @0xd1944 b 0xd18ac <_Z10GET_RValueP6RValueS0_i+0x4f0> */
/* @0xd1948 ldr r0, [r6] */
/* @0xd194c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd1950 str r7, [r6] */
/* @0xd1954 str r7, [r6, #0x8] */
/* @0xd1958 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd195c ldr r7, [r6, #0x4] */
/* @0xd1960 sub r7, r7, #1 */
/* @0xd1964 str r7, [r6, #0x4] */
/* @0xd1968 cmp r7, #0 */
/* @0xd196c bne 0xd1990 <_Z10GET_RValueP6RValueS0_i+0x5d4> */
/* @0xd1970 ldr r0, [r6] */
/* @0xd1974 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd1978 mov r0, r6 */
/* @0xd197c str r7, [r6] */
/* @0xd1980 str r7, [r6, #0x8] */
/* @0xd1984 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xd1988 mov r0, r6 */
/* @0xd198c bl 0x27d1d0 <_ZdlPv> */
/* @0xd1990 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd1994 mov r0, r6 */
/* @0xd1998 bl 0x27d1d0 <_ZdlPv> */
/* @0xd199c b 0xd1934 <_Z10GET_RValueP6RValueS0_i+0x578> */
/* @0xd19a0 mov r0, r4 */
/* @0xd19a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xd19a8 b 0xd1898 <_Z10GET_RValueP6RValueS0_i+0x4dc> */
/* @0xd19ac ldr r0, [r5] */
/* @0xd19b0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd19b4 str r6, [r5] */
/* @0xd19b8 str r6, [r5, #0x8] */
/* @0xd19bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd19c0 ldr r6, [r5, #0x4] */
/* @0xd19c4 sub r6, r6, #1 */
/* @0xd19c8 str r6, [r5, #0x4] */
/* @0xd19cc cmp r6, #0 */
/* @0xd19d0 beq 0xd1a74 <_Z10GET_RValueP6RValueS0_i+0x6b8> */
/* @0xd19d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd19d8 mov r0, r5 */
/* @0xd19dc bl 0x27d1d0 <_ZdlPv> */
/* @0xd19e0 b 0xd184c <_Z10GET_RValueP6RValueS0_i+0x490> */
/* @0xd19e4 ldr r0, [r6] */
/* @0xd19e8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd19ec str r7, [r6] */
/* @0xd19f0 str r7, [r6, #0x8] */
/* @0xd19f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd19f8 ldr r7, [r6, #0x4] */
/* @0xd19fc sub r7, r7, #1 */
/* @0xd1a00 str r7, [r6, #0x4] */
/* @0xd1a04 cmp r7, #0 */
/* @0xd1a08 bne 0xd1a2c <_Z10GET_RValueP6RValueS0_i+0x670> */
/* @0xd1a0c ldr r0, [r6] */
/* @0xd1a10 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd1a14 mov r0, r6 */
/* @0xd1a18 str r7, [r6] */
/* @0xd1a1c str r7, [r6, #0x8] */
/* @0xd1a20 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xd1a24 mov r0, r6 */
/* @0xd1a28 bl 0x27d1d0 <_ZdlPv> */
/* @0xd1a2c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd1a30 mov r0, r6 */
/* @0xd1a34 bl 0x27d1d0 <_ZdlPv> */
/* @0xd1a38 b 0xd168c <_Z10GET_RValueP6RValueS0_i+0x2d0> */
/* @0xd1a3c mov r0, r4 */
/* @0xd1a40 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xd1a44 b 0xd1740 <_Z10GET_RValueP6RValueS0_i+0x384> */
/* @0xd1a48 ldr r12, [pc, #0x88] */
/* @0xd1a4c mov r8, #1 */
/* @0xd1a50 ldr r0, [pc, #0x84] */
/* @0xd1a54 ldr r1, [pc, #0x84] */
/* @0xd1a58 ldr r12, [r6, r12] */
/* @0xd1a5c strb r8, [r12] */
/* @0xd1a60 ldr r0, [r6, r0] */
/* @0xd1a64 str r2, [r0] */
/* @0xd1a68 ldr r2, [r6, r1] */
/* @0xd1a6c str r7, [r2] */
/* @0xd1a70 b 0xd16a0 <_Z10GET_RValueP6RValueS0_i+0x2e4> */
/* @0xd1a74 ldr r0, [r5] */
/* @0xd1a78 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd1a7c str r6, [r5] */
/* @0xd1a80 str r6, [r5, #0x8] */
/* @0xd1a84 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xd1a88 ldr r3, [r5, #0x4] */
/* @0xd1a8c sub r3, r3, #1 */
/* @0xd1a90 str r3, [r5, #0x4] */
/* @0xd1a94 cmp r3, #0 */
/* @0xd1a98 bne 0xd1ac0 <_Z10GET_RValueP6RValueS0_i+0x704> */
/* @0xd1a9c ldr r0, [r5] */
/* @0xd1aa0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd1aa4 mov r3, #0 */
/* @0xd1aa8 mov r0, r5 */
/* @0xd1aac str r3, [r5] */
/* @0xd1ab0 str r3, [r5, #0x8] */
/* @0xd1ab4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xd1ab8 mov r0, r5 */
/* @0xd1abc bl 0x27d1d0 <_ZdlPv> */
/* @0xd1ac0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xd1ac4 mov r0, r5 */
/* @0xd1ac8 bl 0x27d1d0 <_ZdlPv> */
/* @0xd1acc b 0xd19d4 <_Z10GET_RValueP6RValueS0_i+0x618> */
/* @0xd1ad0 eorseq r0, r2, r8, ror r8 */
/* @0xd1ad4 .word 0x002612bc */
/* @0xd1ad8 .word 0xffffbf24 */
/* @0xd1adc .word 0xffffbf28 */
/* @0xd1ae0 .word 0xffffbf2c */
/* @0xd1ae4 .word 0xffffbf30 */
/* @0xd1ae8 .word 0xffffbf34 */

/* ── FUNC 0xd1aec · cARRAY_OF_POINTERS::~cARRAY_OF_POINTERS() · size=80 · insn=20 */
/* @0xd1aec push {r3, r4, r5, lr} */
/* @0xd1af0 mov r4, r0 */
/* @0xd1af4 ldr r3, [r0] */
/* @0xd1af8 cmp r3, #0 */
/* @0xd1afc beq 0xd1b24 <_ZN18cARRAY_OF_POINTERSD2Ev+0x38> */
/* @0xd1b00 ldr r5, [r0, #0xc] */
/* @0xd1b04 subs r0, r5, #0 */
/* @0xd1b08 beq 0xd1b2c <_ZN18cARRAY_OF_POINTERSD2Ev+0x40> */
/* @0xd1b0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1b10 mov r3, #0 */
/* @0xd1b14 str r3, [r4, #0xc] */
/* @0xd1b18 str r3, [r4, #0x4] */
/* @0xd1b1c mov r3, #0 */
/* @0xd1b20 str r3, [r4] */
/* @0xd1b24 mov r0, r4 */
/* @0xd1b28 pop {r3, r4, r5, pc} */
/* @0xd1b2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1b30 str r5, [r4, #0xc] */
/* @0xd1b34 str r5, [r4, #0x4] */
/* @0xd1b38 b 0xd1b1c <_ZN18cARRAY_OF_POINTERSD2Ev+0x30> */

/* ── FUNC 0xd1aec · cARRAY_OF_POINTERS::~cARRAY_OF_POINTERS() · alias of the symbol above · insn=0 */

/* ── FUNC 0xd1b3c · cARRAY_OF_POINTERS::setLength(int) · size=136 · insn=34 */
/* @0xd1b3c ldr r3, [r0] */
/* @0xd1b40 push {r4, r5, lr} */
/* @0xd1b44 cmp r3, r1 */
/* @0xd1b48 sub sp, sp, #12 */
/* @0xd1b4c mov r5, r0 */
/* @0xd1b50 mov r4, r1 */
/* @0xd1b54 beq 0xd1b8c <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x50> */
/* @0xd1b58 cmp r1, #0 */
/* @0xd1b5c ldr r0, [r0, #0xc] */
/* @0xd1b60 beq 0xd1b94 <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x58> */
/* @0xd1b64 lsls r1, r1, #2 */
/* @0xd1b68 beq 0xd1bac <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x70> */
/* @0xd1b6c ldr r2, [pc, #0x4c] */
/* @0xd1b70 mov r3, #0 */
/* @0xd1b74 str r3, [sp] */
/* @0xd1b78 movw r3, #0x11b */
/* @0xd1b7c add r2, pc, r2 */
/* @0xd1b80 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd1b84 str r0, [r5, #0xc] */
/* @0xd1b88 str r4, [r5] */
/* @0xd1b8c add sp, sp, #12 */
/* @0xd1b90 pop {r4, r5, pc} */
/* @0xd1b94 cmp r0, #0 */
/* @0xd1b98 beq 0xd1bac <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x70> */
/* @0xd1b9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1ba0 str r4, [r5, #0xc] */
/* @0xd1ba4 str r4, [r5, #0x4] */
/* @0xd1ba8 b 0xd1b88 <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x4c> */
/* @0xd1bac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1bb0 mov r3, #0 */
/* @0xd1bb4 str r3, [r5, #0xc] */
/* @0xd1bb8 str r3, [r5, #0x4] */
/* @0xd1bbc b 0xd1b88 <_ZN18cARRAY_OF_POINTERS9setLengthEi+0x4c> */
/* @0xd1bc0 eoreq r0, r6, r4, ror #22 */

/* ── FUNC 0xd1bc4 · Variable_FindName(char const*) · size=208 · insn=52 */
/* @0xd1bc4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xd1bc8 mov r7, r0 */
/* @0xd1bcc ldr r3, [pc, #0xb0] */
/* @0xd1bd0 ldr r2, [pc, #0xb0] */
/* @0xd1bd4 add r3, pc, r3 */
/* @0xd1bd8 ldr r8, [r3, r2] */
/* @0xd1bdc ldr r2, [pc, #0xa8] */
/* @0xd1be0 ldr r6, [r8] */
/* @0xd1be4 cmp r6, #0 */
/* @0xd1be8 ldrle r9, [r3, r2] */
/* @0xd1bec ble 0xd1c34 <_Z17Variable_FindNamePKc+0x70> */
/* @0xd1bf0 ldr r9, [r3, r2] */
/* @0xd1bf4 mov r4, #0 */
/* @0xd1bf8 ldr r5, [r9] */
/* @0xd1bfc sub r5, r5, #4 */
/* @0xd1c00 b 0xd1c10 <_Z17Variable_FindNamePKc+0x4c> */
/* @0xd1c04 add r4, r4, #1 */
/* @0xd1c08 cmp r4, r6 */
/* @0xd1c0c beq 0xd1c34 <_Z17Variable_FindNamePKc+0x70> */
/* @0xd1c10 ldr r0, [r5, #0x4]! */
/* @0xd1c14 mov r1, r7 */
/* @0xd1c18 bl 0xb6574 <strcmp@plt> */
/* @0xd1c1c cmp r0, #0 */
/* @0xd1c20 bne 0xd1c04 <_Z17Variable_FindNamePKc+0x40> */
/* @0xd1c24 add r4, r4, #99328 */
/* @0xd1c28 add r4, r4, #672 */
/* @0xd1c2c mov r0, r4 */
/* @0xd1c30 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd1c34 add r6, r6, #1 */
/* @0xd1c38 ldr r2, [pc, #0x50] */
/* @0xd1c3c mov r0, r9 */
/* @0xd1c40 mov r3, #76 */
/* @0xd1c44 lsl r1, r6, #2 */
/* @0xd1c48 add r2, pc, r2 */
/* @0xd1c4c str r6, [r8] */
/* @0xd1c50 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xd1c54 mov r0, r7 */
/* @0xd1c58 ldr r6, [r8] */
/* @0xd1c5c ldr r5, [r9] */
/* @0xd1c60 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xd1c64 ldr r3, [r8] */
/* @0xd1c68 movw r4, #0x869f */
/* @0xd1c6c movt r4, #0x1 */
/* @0xd1c70 sub r6, r6, #-1073741823 */
/* @0xd1c74 add r4, r3, r4 */
/* @0xd1c78 str r0, [r5, r6, lsl #2] */
/* @0xd1c7c mov r0, r4 */
/* @0xd1c80 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd1c84 eorseq r0, r2, r12, ror r0 */
/* @0xd1c88 .word 0xffffbf44 */
/* @0xd1c8c .word 0xffffbf48 */
/* @0xd1c90 .word 0x00260ad8 */

/* ── FUNC 0xd1c94 · Variable_FindNameNoAlloc(char const*) · size=112 · insn=28 */
/* @0xd1c94 push {r3, r4, r5, r6, r7, lr} */
/* @0xd1c98 mov r7, r0 */
/* @0xd1c9c ldr r3, [pc, #0x58] */
/* @0xd1ca0 ldr r3, [pc, r3] */
/* @0xd1ca4 ldr r6, [r3] */
/* @0xd1ca8 cmp r6, #0 */
/* @0xd1cac ble 0xd1cf4 <_Z24Variable_FindNameNoAllocPKc+0x60> */
/* @0xd1cb0 ldr r3, [pc, #0x48] */
/* @0xd1cb4 mov r4, #0 */
/* @0xd1cb8 ldr r3, [pc, r3] */
/* @0xd1cbc ldr r5, [r3] */
/* @0xd1cc0 sub r5, r5, #4 */
/* @0xd1cc4 b 0xd1cd4 <_Z24Variable_FindNameNoAllocPKc+0x40> */
/* @0xd1cc8 add r4, r4, #1 */
/* @0xd1ccc cmp r4, r6 */
/* @0xd1cd0 beq 0xd1cf4 <_Z24Variable_FindNameNoAllocPKc+0x60> */
/* @0xd1cd4 ldr r0, [r5, #0x4]! */
/* @0xd1cd8 mov r1, r7 */
/* @0xd1cdc bl 0xb6574 <strcmp@plt> */
/* @0xd1ce0 cmp r0, #0 */
/* @0xd1ce4 bne 0xd1cc8 <_Z24Variable_FindNameNoAllocPKc+0x34> */
/* @0xd1ce8 add r0, r4, #99328 */
/* @0xd1cec add r0, r0, #672 */
/* @0xd1cf0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xd1cf4 mvn r0, #0 */
/* @0xd1cf8 pop {r3, r4, r5, r6, r7, pc} */
/* @0xd1cfc ldrshteq r11, [r1], -r4 */
/* @0xd1d00 eorseq r11, r1, r0, ror #29 */

/* ── FUNC 0xd1d04 · Variable_GetName(int) · size=92 · insn=23 */
/* @0xd1d04 sub r0, r0, #99328 */
/* @0xd1d08 subs r0, r0, #672 */
/* @0xd1d0c bmi 0xd1d44 <_Z16Variable_GetNamei+0x40> */
/* @0xd1d10 ldr r3, [pc, #0x38] */
/* @0xd1d14 ldr r3, [pc, r3] */
/* @0xd1d18 ldr r3, [r3] */
/* @0xd1d1c cmp r0, r3 */
/* @0xd1d20 bge 0xd1d38 <_Z16Variable_GetNamei+0x34> */
/* @0xd1d24 ldr r3, [pc, #0x28] */
/* @0xd1d28 ldr r3, [pc, r3] */
/* @0xd1d2c ldr r3, [r3] */
/* @0xd1d30 ldr r0, [r3, r0, lsl #2] */
/* @0xd1d34 bx lr */
/* @0xd1d38 ldr r0, [pc, #0x18] */
/* @0xd1d3c add r0, pc, r0 */
/* @0xd1d40 bx lr */
/* @0xd1d44 ldr r0, [pc, #0x10] */
/* @0xd1d48 add r0, pc, r0 */
/* @0xd1d4c bx lr */
/* @0xd1d50 eorseq r11, r1, r0, lsl #29 */
/* @0xd1d54 eorseq r11, r1, r0, ror lr */
/* @0xd1d58 eoreq r0, r6, r12, lsl r10 */
/* @0xd1d5c eoreq r0, r6, r0, lsl r10 */

/* ── FUNC 0xd1d60 · Code_Variable_Find(char const*) · size=32 · insn=8 */
/* @0xd1d60 push {r4, lr} */
/* @0xd1d64 mov r4, r0 */
/* @0xd1d68 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0xd1d6c cmp r0, #0 */
/* @0xd1d70 popge {r4, pc} */
/* @0xd1d74 mov r0, r4 */
/* @0xd1d78 pop {r4, lr} */
/* @0xd1d7c b 0xd1bc4 <_Z17Variable_FindNamePKc> */

/* ── FUNC 0xd1d80 · Code_Variable_Init(int, int, int) · size=500 · insn=125 */
/* @0xd1d80 push {r4, r5, r6, r7, lr} */
/* @0xd1d84 mov r6, r0 */
/* @0xd1d88 ldr r4, [pc, #0x1cc] */
/* @0xd1d8c sub sp, sp, #12 */
/* @0xd1d90 mov r5, r1 */
/* @0xd1d94 ldr r4, [pc, r4] */
/* @0xd1d98 ldr r3, [r4] */
/* @0xd1d9c cmp r3, #0 */
/* @0xd1da0 beq 0xd1dc8 <_Z18Code_Variable_Initiii+0x48> */
/* @0xd1da4 ldr r7, [r4, #0xc] */
/* @0xd1da8 subs r0, r7, #0 */
/* @0xd1dac beq 0xd1f28 <_Z18Code_Variable_Initiii+0x1a8> */
/* @0xd1db0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1db4 mov r3, #0 */
/* @0xd1db8 str r3, [r4, #0xc] */
/* @0xd1dbc str r3, [r4, #0x4] */
/* @0xd1dc0 mov r3, #0 */
/* @0xd1dc4 str r3, [r4] */
/* @0xd1dc8 cmp r6, #0 */
/* @0xd1dcc beq 0xd1e00 <_Z18Code_Variable_Initiii+0x80> */
/* @0xd1dd0 lsls r7, r6, #2 */
/* @0xd1dd4 ldr r0, [r4, #0xc] */
/* @0xd1dd8 beq 0xd1f48 <_Z18Code_Variable_Initiii+0x1c8> */
/* @0xd1ddc ldr r2, [pc, #0x17c] */
/* @0xd1de0 mov r3, #0 */
/* @0xd1de4 mov r1, r7 */
/* @0xd1de8 str r3, [sp] */
/* @0xd1dec add r2, pc, r2 */
/* @0xd1df0 movw r3, #0x11b */
/* @0xd1df4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd1df8 str r0, [r4, #0xc] */
/* @0xd1dfc str r6, [r4] */
/* @0xd1e00 ldr r4, [pc, #0x15c] */
/* @0xd1e04 ldr r4, [pc, r4] */
/* @0xd1e08 ldr r3, [r4] */
/* @0xd1e0c cmp r3, #0 */
/* @0xd1e10 beq 0xd1e38 <_Z18Code_Variable_Initiii+0xb8> */
/* @0xd1e14 ldr r6, [r4, #0xc] */
/* @0xd1e18 subs r0, r6, #0 */
/* @0xd1e1c beq 0xd1f18 <_Z18Code_Variable_Initiii+0x198> */
/* @0xd1e20 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1e24 mov r3, #0 */
/* @0xd1e28 str r3, [r4, #0xc] */
/* @0xd1e2c str r3, [r4, #0x4] */
/* @0xd1e30 mov r3, #0 */
/* @0xd1e34 str r3, [r4] */
/* @0xd1e38 cmp r5, #0 */
/* @0xd1e3c beq 0xd1e70 <_Z18Code_Variable_Initiii+0xf0> */
/* @0xd1e40 lsls r6, r5, #2 */
/* @0xd1e44 ldr r0, [r4, #0xc] */
/* @0xd1e48 beq 0xd1f38 <_Z18Code_Variable_Initiii+0x1b8> */
/* @0xd1e4c ldr r2, [pc, #0x114] */
/* @0xd1e50 mov r3, #0 */
/* @0xd1e54 mov r1, r6 */
/* @0xd1e58 str r3, [sp] */
/* @0xd1e5c add r2, pc, r2 */
/* @0xd1e60 movw r3, #0x11b */
/* @0xd1e64 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd1e68 str r0, [r4, #0xc] */
/* @0xd1e6c str r5, [r4] */
/* @0xd1e70 mov r0, #20 */
/* @0xd1e74 mov r5, #0 */
/* @0xd1e78 bl 0x27c524 <_Znwj> */
/* @0xd1e7c ldr r1, [pc, #0xe8] */
/* @0xd1e80 mov r2, #128 */
/* @0xd1e84 mov r3, #127 */
/* @0xd1e88 add r1, pc, r1 */
/* @0xd1e8c mov r4, r0 */
/* @0xd1e90 str r2, [r0] */
/* @0xd1e94 str r3, [r4, #0x8] */
/* @0xd1e98 mov r2, #70 */
/* @0xd1e9c mov r3, #1 */
/* @0xd1ea0 mov r0, #1536 */
/* @0xd1ea4 str r5, [r4, #0x10] */
/* @0xd1ea8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd1eac mov r2, #1536 */
/* @0xd1eb0 mov r1, r5 */
/* @0xd1eb4 str r0, [r4, #0x10] */
/* @0xd1eb8 bl 0xb65b0 <memset@plt> */
/* @0xd1ebc ldr r2, [r4] */
/* @0xd1ec0 vldr s15, [pc, #144] */
/* @0xd1ec4 str r5, [r4, #0x4] */
/* @0xd1ec8 cmp r2, r5 */
/* @0xd1ecc vmov s13, r2 */
/* @0xd1ed0 vcvt.f32.s32 s14, s13 */
/* @0xd1ed4 vmul.f32 s15, s14, s15 */
/* @0xd1ed8 vcvt.s32.f32 s15, s15 */
/* @0xd1edc vstr s15, [r4, #12] */
/* @0xd1ee0 ble 0xd1f04 <_Z18Code_Variable_Initiii+0x184> */
/* @0xd1ee4 add r2, r2, r2, lsl #1 */
/* @0xd1ee8 ldr r3, [r4, #0x10] */
/* @0xd1eec mov r1, r5 */
/* @0xd1ef0 add r2, r3, r2, lsl #2 */
/* @0xd1ef4 str r1, [r3, #0x8] */
/* @0xd1ef8 add r3, r3, #12 */
/* @0xd1efc cmp r3, r2 */
/* @0xd1f00 bne 0xd1ef4 <_Z18Code_Variable_Initiii+0x174> */
/* @0xd1f04 ldr r3, [pc, #0x64] */
/* @0xd1f08 ldr r3, [pc, r3] */
/* @0xd1f0c str r4, [r3] */
/* @0xd1f10 add sp, sp, #12 */
/* @0xd1f14 pop {r4, r5, r6, r7, pc} */
/* @0xd1f18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1f1c str r6, [r4, #0xc] */
/* @0xd1f20 str r6, [r4, #0x4] */
/* @0xd1f24 b 0xd1e30 <_Z18Code_Variable_Initiii+0xb0> */
/* @0xd1f28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1f2c str r7, [r4, #0xc] */
/* @0xd1f30 str r7, [r4, #0x4] */
/* @0xd1f34 b 0xd1dc0 <_Z18Code_Variable_Initiii+0x40> */
/* @0xd1f38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1f3c str r6, [r4, #0xc] */
/* @0xd1f40 str r6, [r4, #0x4] */
/* @0xd1f44 b 0xd1e6c <_Z18Code_Variable_Initiii+0xec> */
/* @0xd1f48 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd1f4c str r7, [r4, #0xc] */
/* @0xd1f50 str r7, [r4, #0x4] */
/* @0xd1f54 b 0xd1dfc <_Z18Code_Variable_Initiii+0x7c> */
/* @0xd1f58 svclo #0x19999a */
/* @0xd1f5c eorseq r11, r1, r8, lsl #28 */
/* @0xd1f60 .word 0x002608f4 */
/* @0xd1f64 mlaseq r1, r12, sp, r11 */
/* @0xd1f68 eoreq r0, r6, r4, lsl #17 */
/* @0xd1f6c eoreq pc, r5, r8, lsr #3 */
/* @0xd1f70 mlaseq r1, r12, r12, r11 */

/* ── FUNC 0xd1f74 · Code_Variable_Find_Slot_From_Local_Name(char const*) · size=224 · insn=56 */
/* @0xd1f74 ldr r3, [pc, #0xd4] */
/* @0xd1f78 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xd1f7c ldr r3, [pc, r3] */
/* @0xd1f80 mov r9, r0 */
/* @0xd1f84 ldr r7, [r3] */
/* @0xd1f88 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0xd1f8c ldr r3, [r7, #0x8] */
/* @0xd1f90 ldr r2, [r7, #0x10] */
/* @0xd1f94 bic r10, r0, #-2147483648 */
/* @0xd1f98 and r4, r10, r3 */
/* @0xd1f9c lsl r8, r4, #1 */
/* @0xd1fa0 add r1, r8, r4 */
/* @0xd1fa4 add r2, r2, r1, lsl #2 */
/* @0xd1fa8 ldr r5, [r2, #0x8] */
/* @0xd1fac cmp r5, #0 */
/* @0xd1fb0 beq 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0> */
/* @0xd1fb4 mov r6, #0 */
/* @0xd1fb8 b 0xd2000 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0x8c> */
/* @0xd1fbc ldr r2, [r7] */
/* @0xd1fc0 and r5, r5, r3 */
/* @0xd1fc4 add r1, r4, #1 */
/* @0xd1fc8 add r2, r4, r2 */
/* @0xd1fcc and r4, r1, r3 */
/* @0xd1fd0 rsb r5, r5, r2 */
/* @0xd1fd4 and r5, r5, r3 */
/* @0xd1fd8 lsl r8, r4, #1 */
/* @0xd1fdc cmp r5, r6 */
/* @0xd1fe0 add r2, r8, r4 */
/* @0xd1fe4 add r6, r6, #1 */
/* @0xd1fe8 blt 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0> */
/* @0xd1fec ldr r1, [r7, #0x10] */
/* @0xd1ff0 add r2, r1, r2, lsl #2 */
/* @0xd1ff4 ldr r5, [r2, #0x8] */
/* @0xd1ff8 cmp r5, #0 */
/* @0xd1ffc beq 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0> */
/* @0xd2000 cmp r10, r5 */
/* @0xd2004 bne 0xd1fbc <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0x48> */
/* @0xd2008 ldr r0, [r2] */
/* @0xd200c mov r1, r9 */
/* @0xd2010 bl 0x1eeba8 <_Z19CHashMapCompareKeysIPKcEbT_S2_> */
/* @0xd2014 cmp r0, #0 */
/* @0xd2018 bne 0xd202c <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb8> */
/* @0xd201c ldr r3, [r7, #0x8] */
/* @0xd2020 b 0xd1fbc <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0x48> */
/* @0xd2024 mvn r0, #0 */
/* @0xd2028 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xd202c cmn r4, #1 */
/* @0xd2030 beq 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0> */
/* @0xd2034 add r4, r8, r4 */
/* @0xd2038 ldr r3, [r7, #0x10] */
/* @0xd203c add r4, r3, r4, lsl #2 */
/* @0xd2040 cmn r4, #4 */
/* @0xd2044 beq 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0> */
/* @0xd2048 ldr r0, [r4, #0x4] */
/* @0xd204c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xd2050 eorseq r11, r1, r8, lsr #24 */

/* ── FUNC 0xd2054 · Code_Variable_Find_Slot_From_Global_Name(char const*) · size=108 · insn=27 */
/* @0xd2054 ldr r3, [pc, #0x60] */
/* @0xd2058 push {r4, r5, r6, r7, r8, lr} */
/* @0xd205c ldr r3, [pc, r3] */
/* @0xd2060 mov r6, r0 */
/* @0xd2064 ldr r5, [r3, #0x4] */
/* @0xd2068 cmp r5, #0 */
/* @0xd206c ble 0xd20ac <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x58> */
/* @0xd2070 ldr r7, [r3] */
/* @0xd2074 mov r4, #0 */
/* @0xd2078 ldr r8, [r3, #0xc] */
/* @0xd207c cmp r4, r7 */
/* @0xd2080 mov r0, r6 */
/* @0xd2084 bge 0xd20a0 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x4c> */
/* @0xd2088 ldr r1, [r8, r4, lsl #2] */
/* @0xd208c cmp r1, #0 */
/* @0xd2090 beq 0xd20a0 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x4c> */
/* @0xd2094 bl 0xb6574 <strcmp@plt> */
/* @0xd2098 cmp r0, #0 */
/* @0xd209c beq 0xd20b4 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x60> */
/* @0xd20a0 add r4, r4, #1 */
/* @0xd20a4 cmp r4, r5 */
/* @0xd20a8 bne 0xd207c <_Z40Code_Variable_Find_Slot_From_Global_NamePKc+0x28> */
/* @0xd20ac mvn r0, #0 */
/* @0xd20b0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xd20b4 mov r0, r4 */
/* @0xd20b8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xd20bc eorseq r11, r1, r0, asr #22 */

/* ── FUNC 0xd20c0 · New_Code_Variable_Find(char const*, EVariableType) · size=300 · insn=75 */
/* @0xd20c0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xd20c4 mov r5, r1 */
/* @0xd20c8 mov r6, r0 */
/* @0xd20cc bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0xd20d0 subs r4, r0, #0 */
/* @0xd20d4 blt 0xd20e0 <_Z22New_Code_Variable_FindPKc13EVariableType+0x20> */
/* @0xd20d8 mov r0, r4 */
/* @0xd20dc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd20e0 bic r3, r5, #2 */
/* @0xd20e4 cmp r3, #1 */
/* @0xd20e8 beq 0xd21b0 <_Z22New_Code_Variable_FindPKc13EVariableType+0xf0> */
/* @0xd20ec cmp r5, #3 */
/* @0xd20f0 cmpne r5, #0 */
/* @0xd20f4 beq 0xd21cc <_Z22New_Code_Variable_FindPKc13EVariableType+0x10c> */
/* @0xd20f8 ldr r3, [pc, #0xe0] */
/* @0xd20fc ldr r3, [pc, r3] */
/* @0xd2100 ldr r3, [r3] */
/* @0xd2104 cmp r3, #0 */
/* @0xd2108 beq 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18> */
/* @0xd210c sub r5, r5, #2 */
/* @0xd2110 cmp r5, #1 */
/* @0xd2114 bhi 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18> */
/* @0xd2118 ldr r1, [pc, #0xc4] */
/* @0xd211c ldr r2, [pc, #0xc4] */
/* @0xd2120 ldr r1, [pc, r1] */
/* @0xd2124 ldr r2, [pc, r2] */
/* @0xd2128 ldr r8, [r1] */
/* @0xd212c ldr r5, [r2] */
/* @0xd2130 cmp r8, #0 */
/* @0xd2134 ble 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18> */
/* @0xd2138 ldr r9, [r3, #0x34] */
/* @0xd213c mov r7, #0 */
/* @0xd2140 b 0xd2150 <_Z22New_Code_Variable_FindPKc13EVariableType+0x90> */
/* @0xd2144 cmp r7, r8 */
/* @0xd2148 add r5, r5, #12 */
/* @0xd214c beq 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18> */
/* @0xd2150 ldr r0, [r5] */
/* @0xd2154 mov r1, r9 */
/* @0xd2158 bl 0xb6574 <strcmp@plt> */
/* @0xd215c add r7, r7, #1 */
/* @0xd2160 cmp r0, #0 */
/* @0xd2164 bne 0xd2144 <_Z22New_Code_Variable_FindPKc13EVariableType+0x84> */
/* @0xd2168 ldr r8, [r5, #0x4] */
/* @0xd216c ldr r7, [r5, #0x8] */
/* @0xd2170 cmp r8, #0 */
/* @0xd2174 ble 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18> */
/* @0xd2178 sub r7, r7, #4 */
/* @0xd217c mov r5, r0 */
/* @0xd2180 b 0xd2190 <_Z22New_Code_Variable_FindPKc13EVariableType+0xd0> */
/* @0xd2184 add r5, r5, #1 */
/* @0xd2188 cmp r5, r8 */
/* @0xd218c beq 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18> */
/* @0xd2190 ldr r0, [r7, #0x4]! */
/* @0xd2194 mov r1, r6 */
/* @0xd2198 bl 0xb6574 <strcmp@plt> */
/* @0xd219c cmp r0, #0 */
/* @0xd21a0 bne 0xd2184 <_Z22New_Code_Variable_FindPKc13EVariableType+0xc4> */
/* @0xd21a4 add r0, r5, #99328 */
/* @0xd21a8 add r0, r0, #672 */
/* @0xd21ac pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd21b0 mov r0, r6 */
/* @0xd21b4 bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc> */
/* @0xd21b8 subs r4, r0, #0 */
/* @0xd21bc blt 0xd20ec <_Z22New_Code_Variable_FindPKc13EVariableType+0x2c> */
/* @0xd21c0 add r4, r4, #99328 */
/* @0xd21c4 add r0, r4, #672 */
/* @0xd21c8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd21cc mov r0, r6 */
/* @0xd21d0 bl 0xd2054 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc> */
/* @0xd21d4 subs r4, r0, #0 */
/* @0xd21d8 bge 0xd21c0 <_Z22New_Code_Variable_FindPKc13EVariableType+0x100> */
/* @0xd21dc b 0xd20f8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x38> */
/* @0xd21e0 eorseq r11, r1, r12, lsr #21 */
/* @0xd21e4 eorseq r11, r1, r12, lsl #21 */
/* @0xd21e8 eorseq r11, r1, r12, lsl #21 */

/* ── FUNC 0xd21ec · Code_Variable_Find_Slot_From_Name(YYObjectBase*, char const*) · size=60 · insn=15 */
/* @0xd21ec ldr r3, [pc, #0x2c] */
/* @0xd21f0 ldr r3, [pc, r3] */
/* @0xd21f4 ldr r3, [r3] */
/* @0xd21f8 cmp r3, r0 */
/* @0xd21fc mov r0, r1 */
/* @0xd2200 beq 0xd2208 <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc+0x1c> */
/* @0xd2204 b 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc> */
/* @0xd2208 ldr r3, [pc, #0x14] */
/* @0xd220c ldr r3, [pc, r3] */
/* @0xd2210 ldrb r3, [r3] */
/* @0xd2214 cmp r3, #0 */
/* @0xd2218 bne 0xd2204 <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc+0x18> */
/* @0xd221c b 0xd2054 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc> */
/* @0xd2220 eorseq r11, r1, r4, asr #19 */
/* @0xd2224 eorseq r11, r1, r12, lsr #19 */

/* ── FUNC 0xd2228 · Variable_GetName_Scope(char const*, int, int) · size=684 · insn=171 */
/* @0xd2228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd222c sub sp, sp, #4096 */
/* @0xd2230 ldr r8, [pc, #0x268] */
/* @0xd2234 sub sp, sp, #12 */
/* @0xd2238 ldr r3, [pc, #0x264] */
/* @0xd223c mov r9, r0 */
/* @0xd2240 add r8, pc, r8 */
/* @0xd2244 ldr r12, [pc, #0x25c] */
/* @0xd2248 add r0, sp, #8192 */
/* @0xd224c ldr r6, [r8, r3] */
/* @0xd2250 ldr r3, [r6] */
/* @0xd2254 str r3, [r0, #-0xffc] */
/* @0xd2258 ldr r3, [r8, r12] */
/* @0xd225c ldrb r3, [r3] */
/* @0xd2260 cmp r3, #0 */
/* @0xd2264 beq 0xd239c <_Z22Variable_GetName_ScopePKcii+0x174> */
/* @0xd2268 sub r7, r2, #99328 */
/* @0xd226c subs r7, r7, #672 */
/* @0xd2270 bmi 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */
/* @0xd2274 cmn r1, #5 */
/* @0xd2278 beq 0xd23a8 <_Z22Variable_GetName_ScopePKcii+0x180> */
/* @0xd227c cmn r1, #12 */
/* @0xd2280 cmnne r1, #7 */
/* @0xd2284 bne 0xd231c <_Z22Variable_GetName_ScopePKcii+0xf4> */
/* @0xd2288 ldr r3, [pc, #0x21c] */
/* @0xd228c ldr r11, [r8, r3] */
/* @0xd2290 ldr r10, [r11] */
/* @0xd2294 cmp r10, #0 */
/* @0xd2298 ble 0xd22e0 <_Z22Variable_GetName_ScopePKcii+0xb8> */
/* @0xd229c ldr r3, [pc, #0x20c] */
/* @0xd22a0 mov r5, #0 */
/* @0xd22a4 ldr r3, [r8, r3] */
/* @0xd22a8 ldr r4, [r3] */
/* @0xd22ac b 0xd22c0 <_Z22Variable_GetName_ScopePKcii+0x98> */
/* @0xd22b0 add r5, r5, #1 */
/* @0xd22b4 add r4, r4, #12 */
/* @0xd22b8 cmp r5, r10 */
/* @0xd22bc beq 0xd22e0 <_Z22Variable_GetName_ScopePKcii+0xb8> */
/* @0xd22c0 ldr r0, [r4] */
/* @0xd22c4 mov r1, r9 */
/* @0xd22c8 bl 0xb6574 <strcmp@plt> */
/* @0xd22cc cmp r0, #0 */
/* @0xd22d0 bne 0xd22b0 <_Z22Variable_GetName_ScopePKcii+0x88> */
/* @0xd22d4 ldr r3, [r4, #0x8] */
/* @0xd22d8 ldr r0, [r3, r7, lsl #2] */
/* @0xd22dc b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */
/* @0xd22e0 ldr r3, [pc, #0x1cc] */
/* @0xd22e4 ldr r3, [r8, r3] */
/* @0xd22e8 ldrb r3, [r3] */
/* @0xd22ec cmp r3, #0 */
/* @0xd22f0 bne 0xd2404 <_Z22Variable_GetName_ScopePKcii+0x1dc> */
/* @0xd22f4 ldr r0, [pc, #0x1bc] */
/* @0xd22f8 add r0, pc, r0 */
/* @0xd22fc add r3, sp, #8192 */
/* @0xd2300 ldr r2, [r3, #-0xffc] */
/* @0xd2304 ldr r3, [r6] */
/* @0xd2308 cmp r2, r3 */
/* @0xd230c bne 0xd2490 <_Z22Variable_GetName_ScopePKcii+0x268> */
/* @0xd2310 add sp, sp, #4096 */
/* @0xd2314 add sp, sp, #12 */
/* @0xd2318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd231c cmn r1, #1 */
/* @0xd2320 bne 0xd23d4 <_Z22Variable_GetName_ScopePKcii+0x1ac> */
/* @0xd2324 ldr r3, [pc, #0x190] */
/* @0xd2328 ldr r3, [r8, r3] */
/* @0xd232c ldr r2, [r3, #0x4] */
/* @0xd2330 cmp r7, r2 */
/* @0xd2334 blt 0xd23bc <_Z22Variable_GetName_ScopePKcii+0x194> */
/* @0xd2338 ldr r3, [pc, #0x180] */
/* @0xd233c ldr r3, [r8, r3] */
/* @0xd2340 ldr r5, [r3] */
/* @0xd2344 ldr r4, [r5, #0x4] */
/* @0xd2348 subs r12, r4, #1 */
/* @0xd234c bmi 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */
/* @0xd2350 cmp r4, r12 */
/* @0xd2354 blt 0xd2494 <_Z22Variable_GetName_ScopePKcii+0x26c> */
/* @0xd2358 ldr r3, [r5, #0x10] */
/* @0xd235c mov r2, #0 */
/* @0xd2360 b 0xd236c <_Z22Variable_GetName_ScopePKcii+0x144> */
/* @0xd2364 add r2, r2, #1 */
/* @0xd2368 add r3, r3, #12 */
/* @0xd236c ldr r1, [r3, #0x8] */
/* @0xd2370 cmp r1, #0 */
/* @0xd2374 ble 0xd2368 <_Z22Variable_GetName_ScopePKcii+0x140> */
/* @0xd2378 cmp r12, r2 */
/* @0xd237c bne 0xd2364 <_Z22Variable_GetName_ScopePKcii+0x13c> */
/* @0xd2380 ldr r0, [r3], #4 */
/* @0xd2384 ldr r3, [r3] */
/* @0xd2388 cmp r3, r7 */
/* @0xd238c beq 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */
/* @0xd2390 subs r12, r12, #1 */
/* @0xd2394 bhs 0xd2350 <_Z22Variable_GetName_ScopePKcii+0x128> */
/* @0xd2398 b 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */
/* @0xd239c mov r0, r2 */
/* @0xd23a0 bl 0xd1d04 <_Z16Variable_GetNamei> */
/* @0xd23a4 b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */
/* @0xd23a8 ldr r3, [pc, #0x114] */
/* @0xd23ac ldr r3, [r8, r3] */
/* @0xd23b0 ldr r2, [r3, #0x4] */
/* @0xd23b4 cmp r7, r2 */
/* @0xd23b8 bge 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */
/* @0xd23bc ldr r2, [r3] */
/* @0xd23c0 cmp r7, r2 */
/* @0xd23c4 ldrlt r3, [r3, #0xc] */
/* @0xd23c8 movge r0, #0 */
/* @0xd23cc ldrlt r0, [r3, r7, lsl #2] */
/* @0xd23d0 b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */
/* @0xd23d4 bic r2, r1, #2 */
/* @0xd23d8 movw r3, #0x86a0 */
/* @0xd23dc cmn r2, #11 */
/* @0xd23e0 movt r3, #0x1 */
/* @0xd23e4 movne r2, #0 */
/* @0xd23e8 moveq r2, #1 */
/* @0xd23ec cmp r1, r3 */
/* @0xd23f0 movle r3, r2 */
/* @0xd23f4 orrgt r3, r2, #1 */
/* @0xd23f8 cmp r3, #0 */
/* @0xd23fc beq 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */
/* @0xd2400 b 0xd2324 <_Z22Variable_GetName_ScopePKcii+0xfc> */
/* @0xd2404 mov r0, r9 */
/* @0xd2408 bl 0x1e06dc <_Z18Script_Find_ParentPKc> */
/* @0xd240c cmp r0, #0 */
/* @0xd2410 beq 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */
/* @0xd2414 add r9, sp, #4 */
/* @0xd2418 ldr r2, [pc, #0xa8] */
/* @0xd241c ldr r3, [r0, #0x14] */
/* @0xd2420 mov r1, #4096 */
/* @0xd2424 add r2, pc, r2 */
/* @0xd2428 mov r0, r9 */
/* @0xd242c bl 0xb65c8 <snprintf@plt> */
/* @0xd2430 ldr r10, [r11] */
/* @0xd2434 cmp r10, #0 */
/* @0xd2438 ble 0xd2484 <_Z22Variable_GetName_ScopePKcii+0x25c> */
/* @0xd243c ldr r3, [pc, #0x6c] */
/* @0xd2440 mov r5, #0 */
/* @0xd2444 ldr r3, [r8, r3] */
/* @0xd2448 ldr r4, [r3] */
/* @0xd244c b 0xd2460 <_Z22Variable_GetName_ScopePKcii+0x238> */
/* @0xd2450 add r5, r5, #1 */
/* @0xd2454 add r4, r4, #12 */
/* @0xd2458 cmp r5, r10 */
/* @0xd245c beq 0xd2478 <_Z22Variable_GetName_ScopePKcii+0x250> */
/* @0xd2460 ldr r0, [r4] */
/* @0xd2464 mov r1, r9 */
/* @0xd2468 bl 0xb6574 <strcmp@plt> */
/* @0xd246c cmp r0, #0 */
/* @0xd2470 bne 0xd2450 <_Z22Variable_GetName_ScopePKcii+0x228> */
/* @0xd2474 b 0xd22d4 <_Z22Variable_GetName_ScopePKcii+0xac> */
/* @0xd2478 ldr r0, [pc, #0x4c] */
/* @0xd247c add r0, pc, r0 */
/* @0xd2480 b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */
/* @0xd2484 ldr r0, [pc, #0x44] */
/* @0xd2488 add r0, pc, r0 */
/* @0xd248c b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */
/* @0xd2490 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xd2494 mov r0, #0 */
/* @0xd2498 mov r3, r0 */
/* @0xd249c b 0xd2384 <_Z22Variable_GetName_ScopePKcii+0x15c> */
/* @0xd24a0 eorseq pc, r1, r0, lsl r10 */
/* @0xd24a4 .word 0xffffbd00 */
/* @0xd24a8 .word 0xffffbf04 */
/* @0xd24ac .word 0xffffbf5c */
/* @0xd24b0 .word 0xffffbf60 */
/* @0xd24b4 .word 0xffffbf68 */
/* @0xd24b8 eoreq r0, r6, r0, ror #8 */
/* @0xd24bc .word 0xffffbf50 */
/* @0xd24c0 .word 0xffffbf54 */
/* @0xd24c4 .word 0xffffbf4c */
/* @0xd24c8 eoreq r0, r6, r8, asr #6 */
/* @0xd24cc .word 0x002602dc */
/* @0xd24d0 .word 0x002602d0 */

/* ── FUNC 0xd24d4 · Code_Variable_Read_Local_Names(unsigned char*) · size=296 · insn=74 */
/* @0xd24d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd24d8 mov r8, r0 */
/* @0xd24dc ldr r2, [r8], #4 */
/* @0xd24e0 sub sp, sp, #12 */
/* @0xd24e4 ldr r9, [pc, #0x100] */
/* @0xd24e8 add r0, r2, r2, lsl #1 */
/* @0xd24ec str r2, [sp, #0x4] */
/* @0xd24f0 add r9, pc, r9 */
/* @0xd24f4 lsl r0, r0, #2 */
/* @0xd24f8 bl 0xcef4c <_Z7YYAlloci> */
/* @0xd24fc ldr r2, [pc, #0xec] */
/* @0xd2500 ldr r3, [sp, #0x4] */
/* @0xd2504 ldr r7, [r9, r2] */
/* @0xd2508 cmp r3, #0 */
/* @0xd250c ldr r3, [pc, #0xe0] */
/* @0xd2510 ldr r2, [sp, #0x4] */
/* @0xd2514 str r0, [r7] */
/* @0xd2518 ldr r3, [r9, r3] */
/* @0xd251c str r2, [r3] */
/* @0xd2520 ble 0xd25e4 <_Z30Code_Variable_Read_Local_NamesPh+0x110> */
/* @0xd2524 mov r4, r0 */
/* @0xd2528 mov r5, #0 */
/* @0xd252c str r5, [sp] */
/* @0xd2530 ldr r0, [r8, #0x4] */
/* @0xd2534 ldr r6, [r8] */
/* @0xd2538 cmp r0, #0 */
/* @0xd253c ldrne r3, [pc, #0xb4] */
/* @0xd2540 ldrne r3, [r9, r3] */
/* @0xd2544 ldrne r3, [r3] */
/* @0xd2548 addne r0, r3, r0 */
/* @0xd254c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xd2550 ldr r3, [r7] */
/* @0xd2554 add r8, r8, #8 */
/* @0xd2558 add r11, r3, r5 */
/* @0xd255c str r0, [r4, r5] */
/* @0xd2560 lsl r0, r6, #2 */
/* @0xd2564 str r6, [r11, #0x4] */
/* @0xd2568 bl 0xcef4c <_Z7YYAlloci> */
/* @0xd256c cmp r6, #0 */
/* @0xd2570 str r0, [r11, #0x8] */
/* @0xd2574 ble 0xd25c4 <_Z30Code_Variable_Read_Local_NamesPh+0xf0> */
/* @0xd2578 mov r11, r8 */
/* @0xd257c mov r4, #0 */
/* @0xd2580 ldr r3, [r11, #0x4] */
/* @0xd2584 add r11, r11, #8 */
/* @0xd2588 ldr r1, [pc, #0x68] */
/* @0xd258c cmp r3, #0 */
/* @0xd2590 mov r0, r3 */
/* @0xd2594 ldrne r1, [r9, r1] */
/* @0xd2598 ldrne r0, [r1] */
/* @0xd259c addne r0, r0, r3 */
/* @0xd25a0 ldr r3, [r7] */
/* @0xd25a4 add r3, r3, r5 */
/* @0xd25a8 ldr r10, [r3, #0x8] */
/* @0xd25ac bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xd25b0 str r0, [r10, r4, lsl #2] */
/* @0xd25b4 add r4, r4, #1 */
/* @0xd25b8 cmp r4, r6 */
/* @0xd25bc bne 0xd2580 <_Z30Code_Variable_Read_Local_NamesPh+0xac> */
/* @0xd25c0 add r8, r8, r4, lsl #3 */
/* @0xd25c4 ldr r3, [sp] */
/* @0xd25c8 add r5, r5, #12 */
/* @0xd25cc ldr r2, [sp, #0x4] */
/* @0xd25d0 add r3, r3, #1 */
/* @0xd25d4 str r3, [sp] */
/* @0xd25d8 cmp r3, r2 */
/* @0xd25dc ldrne r4, [r7] */
/* @0xd25e0 bne 0xd2530 <_Z30Code_Variable_Read_Local_NamesPh+0x5c> */
/* @0xd25e4 add sp, sp, #12 */
/* @0xd25e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd25ec eorseq pc, r1, r0, ror #14 */
/* @0xd25f0 .word 0xffffbf60 */
/* @0xd25f4 .word 0xffffbf5c */
/* @0xd25f8 .word 0xffffbcf4 */

/* ── FUNC 0xd25fc · Code_Variable_Find_Name(char const*, int, int) · size=28 · insn=7 */
/* @0xd25fc movw r3, #0x869f */
/* @0xd2600 movt r3, #0x1 */
/* @0xd2604 cmp r2, r3 */
/* @0xd2608 bgt 0xd2614 <_Z23Code_Variable_Find_NamePKcii+0x18> */
/* @0xd260c mov r0, r2 */
/* @0xd2610 b 0x1f3b38 <_Z26Variable_BuiltIn_Find_Namei> */
/* @0xd2614 b 0xd2228 <_Z22Variable_GetName_ScopePKcii> */

/* ── FUNC 0xd2618 · FINALIZE_Code_Variable() · size=4 · insn=1 */
/* @0xd2618 bx lr */

/* ── FUNC 0xd261c · CHashMap<char const*, int, 7>::Insert(char const*, int) · size=1640 · insn=410 */
/* @0xd261c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd2620 vpush {d8} */
/* @0xd2624 sub sp, sp, #60 */
/* @0xd2628 ldr r3, [r0, #0x4] */
/* @0xd262c mov r11, r0 */
/* @0xd2630 str r2, [sp, #0x24] */
/* @0xd2634 ldr r2, [r0, #0xc] */
/* @0xd2638 str r1, [sp, #0x1c] */
/* @0xd263c cmp r3, r2 */
/* @0xd2640 bgt 0xd2750 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x134> */
/* @0xd2644 add r3, r3, #1 */
/* @0xd2648 ldr r0, [sp, #0x1c] */
/* @0xd264c str r3, [r11, #0x4] */
/* @0xd2650 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0xd2654 ldr r4, [r11, #0x8] */
/* @0xd2658 ldr r6, [r11, #0x10] */
/* @0xd265c bic r0, r0, #-2147483648 */
/* @0xd2660 and r3, r0, r4 */
/* @0xd2664 add r2, r3, r3, lsl #1 */
/* @0xd2668 add r2, r6, r2, lsl #2 */
/* @0xd266c ldr r12, [r2, #0x8] */
/* @0xd2670 cmp r12, #0 */
/* @0xd2674 beq 0xd2730 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x114> */
/* @0xd2678 ldr r7, [r11] */
/* @0xd267c mov r1, #0 */
/* @0xd2680 ldr r8, [sp, #0x1c] */
/* @0xd2684 ldr r9, [sp, #0x24] */
/* @0xd2688 b 0xd26d0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0xb4> */
/* @0xd268c ldr r10, [r2] */
/* @0xd2690 mov r1, r5 */
/* @0xd2694 ldr r5, [r2, #0x4] */
/* @0xd2698 str r0, [r2, #0x8] */
/* @0xd269c mov r0, r12 */
/* @0xd26a0 str r8, [r2] */
/* @0xd26a4 mov r8, r10 */
/* @0xd26a8 str r9, [r2, #0x4] */
/* @0xd26ac mov r9, r5 */
/* @0xd26b0 add r3, r3, #1 */
/* @0xd26b4 add r1, r1, #1 */
/* @0xd26b8 and r3, r3, r4 */
/* @0xd26bc add r2, r3, r3, lsl #1 */
/* @0xd26c0 add r2, r6, r2, lsl #2 */
/* @0xd26c4 ldr r12, [r2, #0x8] */
/* @0xd26c8 cmp r12, #0 */
/* @0xd26cc beq 0xd2728 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x10c> */
/* @0xd26d0 add r5, r7, r3 */
/* @0xd26d4 and r10, r12, r4 */
/* @0xd26d8 rsb r5, r10, r5 */
/* @0xd26dc and r5, r5, r4 */
/* @0xd26e0 cmp r5, r1 */
/* @0xd26e4 blt 0xd268c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x70> */
/* @0xd26e8 cmp r1, r5 */
/* @0xd26ec bne 0xd26b0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x94> */
/* @0xd26f0 cmp r0, r12 */
/* @0xd26f4 bne 0xd26b0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x94> */
/* @0xd26f8 ldr r12, [r2] */
/* @0xd26fc cmp r8, r12 */
/* @0xd2700 bne 0xd26b0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x94> */
/* @0xd2704 ldr r3, [r11, #0x4] */
/* @0xd2708 str r8, [sp, #0x1c] */
/* @0xd270c str r8, [r2] */
/* @0xd2710 sub r3, r3, #1 */
/* @0xd2714 str r9, [r2, #0x4] */
/* @0xd2718 str r0, [r2, #0x8] */
/* @0xd271c str r9, [sp, #0x24] */
/* @0xd2720 str r3, [r11, #0x4] */
/* @0xd2724 b 0xd2744 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x128> */
/* @0xd2728 str r8, [sp, #0x1c] */
/* @0xd272c str r9, [sp, #0x24] */
/* @0xd2730 ldr r12, [sp, #0x1c] */
/* @0xd2734 str r0, [r2, #0x8] */
/* @0xd2738 str r12, [r2] */
/* @0xd273c ldr r12, [sp, #0x24] */
/* @0xd2740 str r12, [r2, #0x4] */
/* @0xd2744 add sp, sp, #60 */
/* @0xd2748 vpop {d8} */
/* @0xd274c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd2750 ldr r12, [r0] */
/* @0xd2754 mov r3, #1 */
/* @0xd2758 ldr r1, [pc, #0x430] */
/* @0xd275c mov r2, #70 */
/* @0xd2760 str r12, [sp, #0x20] */
/* @0xd2764 add r1, pc, r1 */
/* @0xd2768 ldr r12, [r0, #0x10] */
/* @0xd276c str r12, [sp, #0x30] */
/* @0xd2770 ldr r12, [sp, #0x20] */
/* @0xd2774 lsl r0, r12, r3 */
/* @0xd2778 str r0, [r11] */
/* @0xd277c add r4, r0, r12, lsl #2 */
/* @0xd2780 sub r0, r0, #1 */
/* @0xd2784 str r0, [r11, #0x8] */
/* @0xd2788 lsl r4, r4, #2 */
/* @0xd278c mov r0, r4 */
/* @0xd2790 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd2794 mov r2, r4 */
/* @0xd2798 mov r1, #0 */
/* @0xd279c str r0, [r11, #0x10] */
/* @0xd27a0 bl 0xb65b0 <memset@plt> */
/* @0xd27a4 ldr r2, [r11] */
/* @0xd27a8 vldr s15, [pc, #988] */
/* @0xd27ac mov r1, #0 */
/* @0xd27b0 cmp r2, r1 */
/* @0xd27b4 str r1, [r11, #0x4] */
/* @0xd27b8 vmov s13, r2 */
/* @0xd27bc vcvt.f32.s32 s14, s13 */
/* @0xd27c0 vmul.f32 s15, s14, s15 */
/* @0xd27c4 vcvt.s32.f32 s15, s15 */
/* @0xd27c8 vstr s15, [r11, #12] */
/* @0xd27cc ble 0xd27ec <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x1d0> */
/* @0xd27d0 add r2, r2, r2, lsl #1 */
/* @0xd27d4 ldr r3, [r11, #0x10] */
/* @0xd27d8 add r2, r3, r2, lsl #2 */
/* @0xd27dc str r1, [r3, #0x8] */
/* @0xd27e0 add r3, r3, #12 */
/* @0xd27e4 cmp r3, r2 */
/* @0xd27e8 bne 0xd27dc <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x1c0> */
/* @0xd27ec ldr r12, [sp, #0x20] */
/* @0xd27f0 cmp r12, #0 */
/* @0xd27f4 ble 0xd295c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x340> */
/* @0xd27f8 ldr r12, [pc, #0x394] */
/* @0xd27fc vldr s16, [pc, #904] */
/* @0xd2800 add r12, pc, r12 */
/* @0xd2804 str r12, [sp, #0x34] */
/* @0xd2808 mov r12, #0 */
/* @0xd280c str r12, [sp, #0xc] */
/* @0xd2810 ldr r12, [pc, #0x380] */
/* @0xd2814 add r12, pc, r12 */
/* @0xd2818 str r12, [sp, #0x2c] */
/* @0xd281c ldr r12, [sp, #0x30] */
/* @0xd2820 str r12, [sp, #0x8] */
/* @0xd2824 ldr r12, [sp, #0x8] */
/* @0xd2828 ldr r3, [r12, #0x8] */
/* @0xd282c cmp r3, #0 */
/* @0xd2830 ble 0xd2934 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x318> */
/* @0xd2834 ldr r12, [r12] */
/* @0xd2838 ldr r3, [r11, #0x4] */
/* @0xd283c ldr r2, [r11, #0xc] */
/* @0xd2840 str r12, [sp, #0x10] */
/* @0xd2844 ldr r12, [sp, #0x8] */
/* @0xd2848 cmp r3, r2 */
/* @0xd284c ldr r12, [r12, #0x4] */
/* @0xd2850 str r12, [sp, #0x18] */
/* @0xd2854 bgt 0xd29a4 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x388> */
/* @0xd2858 add r3, r3, #1 */
/* @0xd285c ldr r0, [sp, #0x10] */
/* @0xd2860 str r3, [r11, #0x4] */
/* @0xd2864 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0xd2868 ldr lr, [r11, #0x8] */
/* @0xd286c ldr r6, [r11, #0x10] */
/* @0xd2870 bic r0, r0, #-2147483648 */
/* @0xd2874 and r3, r0, lr */
/* @0xd2878 add r2, r3, r3, lsl #1 */
/* @0xd287c add r2, r6, r2, lsl #2 */
/* @0xd2880 ldr r1, [r2, #0x8] */
/* @0xd2884 cmp r1, #0 */
/* @0xd2888 beq 0xd298c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x370> */
/* @0xd288c ldr r7, [r11] */
/* @0xd2890 mov r4, #0 */
/* @0xd2894 ldr r8, [sp, #0x10] */
/* @0xd2898 ldr r9, [sp, #0x18] */
/* @0xd289c b 0xd28e0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x2c4> */
/* @0xd28a0 ldr r5, [r2] */
/* @0xd28a4 ldr r4, [r2, #0x4] */
/* @0xd28a8 str r0, [r2, #0x8] */
/* @0xd28ac mov r0, r1 */
/* @0xd28b0 str r8, [r2] */
/* @0xd28b4 mov r8, r5 */
/* @0xd28b8 str r9, [r2, #0x4] */
/* @0xd28bc mov r9, r4 */
/* @0xd28c0 add r3, r3, #1 */
/* @0xd28c4 add r4, r12, #1 */
/* @0xd28c8 and r3, r3, lr */
/* @0xd28cc add r2, r3, r3, lsl #1 */
/* @0xd28d0 add r2, r6, r2, lsl #2 */
/* @0xd28d4 ldr r1, [r2, #0x8] */
/* @0xd28d8 cmp r1, #0 */
/* @0xd28dc beq 0xd2984 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x368> */
/* @0xd28e0 add r12, r7, r3 */
/* @0xd28e4 and r5, r1, lr */
/* @0xd28e8 rsb r12, r5, r12 */
/* @0xd28ec and r12, r12, lr */
/* @0xd28f0 cmp r12, r4 */
/* @0xd28f4 blt 0xd28a0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x284> */
/* @0xd28f8 movne r12, r4 */
/* @0xd28fc bne 0xd28c0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x2a4> */
/* @0xd2900 cmp r1, r0 */
/* @0xd2904 bne 0xd28c0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x2a4> */
/* @0xd2908 ldr r4, [r2] */
/* @0xd290c cmp r8, r4 */
/* @0xd2910 bne 0xd28c0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x2a4> */
/* @0xd2914 ldr r3, [r11, #0x4] */
/* @0xd2918 str r8, [sp, #0x10] */
/* @0xd291c str r8, [r2] */
/* @0xd2920 sub r3, r3, #1 */
/* @0xd2924 str r9, [r2, #0x4] */
/* @0xd2928 str r1, [r2, #0x8] */
/* @0xd292c str r9, [sp, #0x18] */
/* @0xd2930 str r3, [r11, #0x4] */
/* @0xd2934 ldr r12, [sp, #0xc] */
/* @0xd2938 ldr r0, [sp, #0x20] */
/* @0xd293c add r12, r12, #1 */
/* @0xd2940 str r12, [sp, #0xc] */
/* @0xd2944 ldr r12, [sp, #0x8] */
/* @0xd2948 add r12, r12, #12 */
/* @0xd294c str r12, [sp, #0x8] */
/* @0xd2950 ldr r12, [sp, #0xc] */
/* @0xd2954 cmp r12, r0 */
/* @0xd2958 bne 0xd2824 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x208> */
/* @0xd295c ldr r0, [sp, #0x30] */
/* @0xd2960 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd2964 vldr s13, [r11] */
/* @0xd2968 vcvt.f32.s32 s14, s13 */
/* @0xd296c vldr s15, [pc, #536] */
/* @0xd2970 ldr r3, [r11, #0x4] */
/* @0xd2974 vmul.f32 s15, s14, s15 */
/* @0xd2978 vcvt.s32.f32 s15, s15 */
/* @0xd297c vstr s15, [r11, #12] */
/* @0xd2980 b 0xd2644 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x28> */
/* @0xd2984 str r8, [sp, #0x10] */
/* @0xd2988 str r9, [sp, #0x18] */
/* @0xd298c ldr r12, [sp, #0x10] */
/* @0xd2990 str r0, [r2, #0x8] */
/* @0xd2994 str r12, [r2] */
/* @0xd2998 ldr r12, [sp, #0x18] */
/* @0xd299c str r12, [r2, #0x4] */
/* @0xd29a0 b 0xd2934 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x318> */
/* @0xd29a4 ldr r12, [r11] */
/* @0xd29a8 mov r3, #1 */
/* @0xd29ac ldr r1, [sp, #0x34] */
/* @0xd29b0 mov r2, #70 */
/* @0xd29b4 str r12, [sp, #0x14] */
/* @0xd29b8 ldr r12, [r11, #0x10] */
/* @0xd29bc str r12, [sp, #0x28] */
/* @0xd29c0 ldr r12, [sp, #0x14] */
/* @0xd29c4 lsl r0, r12, r3 */
/* @0xd29c8 str r0, [r11] */
/* @0xd29cc add r4, r0, r12, lsl #2 */
/* @0xd29d0 sub r0, r0, #1 */
/* @0xd29d4 str r0, [r11, #0x8] */
/* @0xd29d8 lsl r4, r4, #2 */
/* @0xd29dc mov r0, r4 */
/* @0xd29e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd29e4 mov r2, r4 */
/* @0xd29e8 mov r1, #0 */
/* @0xd29ec str r0, [r11, #0x10] */
/* @0xd29f0 bl 0xb65b0 <memset@plt> */
/* @0xd29f4 ldr r2, [r11] */
/* @0xd29f8 mov r0, #0 */
/* @0xd29fc str r0, [r11, #0x4] */
/* @0xd2a00 cmp r2, r0 */
/* @0xd2a04 vmov s13, r2 */
/* @0xd2a08 vcvt.f32.s32 s15, s13 */
/* @0xd2a0c vmul.f32 s15, s15, s16 */
/* @0xd2a10 vcvt.s32.f32 s15, s15 */
/* @0xd2a14 vstr s15, [r11, #12] */
/* @0xd2a18 ble 0xd2a3c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x420> */
/* @0xd2a1c add r2, r2, r2, lsl #1 */
/* @0xd2a20 ldr r3, [r11, #0x10] */
/* @0xd2a24 add r2, r3, r2, lsl #2 */
/* @0xd2a28 mov r0, #0 */
/* @0xd2a2c add r3, r3, #12 */
/* @0xd2a30 str r0, [r3, #-0x4] */
/* @0xd2a34 cmp r3, r2 */
/* @0xd2a38 bne 0xd2a28 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x40c> */
/* @0xd2a3c ldr r12, [sp, #0x14] */
/* @0xd2a40 cmp r12, #0 */
/* @0xd2a44 ble 0xd2b5c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x540> */
/* @0xd2a48 ldr r6, [sp, #0x28] */
/* @0xd2a4c mov r12, #0 */
/* @0xd2a50 str r12, [sp, #0x4] */
/* @0xd2a54 ldr r3, [r6, #0x8] */
/* @0xd2a58 cmp r3, #0 */
/* @0xd2a5c ble 0xd2b40 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x524> */
/* @0xd2a60 ldr r3, [r11, #0x4] */
/* @0xd2a64 ldr r2, [r11, #0xc] */
/* @0xd2a68 ldr r4, [r6] */
/* @0xd2a6c cmp r3, r2 */
/* @0xd2a70 ldr r5, [r6, #0x4] */
/* @0xd2a74 bgt 0xd2b9c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x580> */
/* @0xd2a78 add r3, r3, #1 */
/* @0xd2a7c mov r0, r4 */
/* @0xd2a80 str r3, [r11, #0x4] */
/* @0xd2a84 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0xd2a88 ldr lr, [r11, #0x8] */
/* @0xd2a8c ldr r9, [r11, #0x10] */
/* @0xd2a90 bic r0, r0, #-2147483648 */
/* @0xd2a94 and r3, r0, lr */
/* @0xd2a98 add r2, r3, r3, lsl #1 */
/* @0xd2a9c add r2, r9, r2, lsl #2 */
/* @0xd2aa0 ldr r1, [r2, #0x8] */
/* @0xd2aa4 cmp r1, #0 */
/* @0xd2aa8 ldrne r10, [r11] */
/* @0xd2aac movne r7, #0 */
/* @0xd2ab0 bne 0xd2af8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x4dc> */
/* @0xd2ab4 b 0xd2b80 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x564> */
/* @0xd2ab8 ldr r8, [r2] */
/* @0xd2abc ldr r7, [r2, #0x4] */
/* @0xd2ac0 str r0, [r2, #0x8] */
/* @0xd2ac4 mov r0, r1 */
/* @0xd2ac8 str r4, [r2] */
/* @0xd2acc mov r4, r8 */
/* @0xd2ad0 str r5, [r2, #0x4] */
/* @0xd2ad4 mov r5, r7 */
/* @0xd2ad8 add r3, r3, #1 */
/* @0xd2adc add r7, r12, #1 */
/* @0xd2ae0 and r3, r3, lr */
/* @0xd2ae4 add r2, r3, r3, lsl #1 */
/* @0xd2ae8 add r2, r9, r2, lsl #2 */
/* @0xd2aec ldr r1, [r2, #0x8] */
/* @0xd2af0 cmp r1, #0 */
/* @0xd2af4 beq 0xd2b80 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x564> */
/* @0xd2af8 add r12, r3, r10 */
/* @0xd2afc and r8, r1, lr */
/* @0xd2b00 rsb r12, r8, r12 */
/* @0xd2b04 and r12, r12, lr */
/* @0xd2b08 cmp r12, r7 */
/* @0xd2b0c blt 0xd2ab8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x49c> */
/* @0xd2b10 movne r12, r7 */
/* @0xd2b14 bne 0xd2ad8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x4bc> */
/* @0xd2b18 cmp r1, r0 */
/* @0xd2b1c bne 0xd2ad8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x4bc> */
/* @0xd2b20 ldr r7, [r2] */
/* @0xd2b24 cmp r4, r7 */
/* @0xd2b28 bne 0xd2ad8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x4bc> */
/* @0xd2b2c ldr r3, [r11, #0x4] */
/* @0xd2b30 stm r2, {r4, r5} */
/* @0xd2b34 sub r3, r3, #1 */
/* @0xd2b38 str r1, [r2, #0x8] */
/* @0xd2b3c str r3, [r11, #0x4] */
/* @0xd2b40 ldr r12, [sp, #0x4] */
/* @0xd2b44 add r6, r6, #12 */
/* @0xd2b48 ldr r0, [sp, #0x14] */
/* @0xd2b4c add r12, r12, #1 */
/* @0xd2b50 str r12, [sp, #0x4] */
/* @0xd2b54 cmp r12, r0 */
/* @0xd2b58 bne 0xd2a54 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x438> */
/* @0xd2b5c ldr r0, [sp, #0x28] */
/* @0xd2b60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd2b64 vldr s13, [r11] */
/* @0xd2b68 vcvt.f32.s32 s15, s13 */
/* @0xd2b6c ldr r3, [r11, #0x4] */
/* @0xd2b70 vmul.f32 s15, s15, s16 */
/* @0xd2b74 vcvt.s32.f32 s15, s15 */
/* @0xd2b78 vstr s15, [r11, #12] */
/* @0xd2b7c b 0xd2858 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x23c> */
/* @0xd2b80 stm r2, {r4, r5} */
/* @0xd2b84 str r0, [r2, #0x8] */
/* @0xd2b88 b 0xd2b40 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x524> */
/* @0xd2b8c svclo #0x19999a */
/* @0xd2b90 eoreq lr, r5, r12, asr #17 */
/* @0xd2b94 eoreq lr, r5, r0, lsr r8 */
/* @0xd2b98 eoreq lr, r5, r12, lsl r8 */
/* @0xd2b9c ldr r8, [r11] */
/* @0xd2ba0 mov r3, #1 */
/* @0xd2ba4 ldr r1, [sp, #0x2c] */
/* @0xd2ba8 mov r2, #70 */
/* @0xd2bac ldr r7, [r11, #0x10] */
/* @0xd2bb0 lsl r0, r8, r3 */
/* @0xd2bb4 str r0, [r11] */
/* @0xd2bb8 add r9, r0, r8, lsl #2 */
/* @0xd2bbc sub r0, r0, #1 */
/* @0xd2bc0 str r0, [r11, #0x8] */
/* @0xd2bc4 lsl r9, r9, #2 */
/* @0xd2bc8 mov r0, r9 */
/* @0xd2bcc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd2bd0 mov r2, r9 */
/* @0xd2bd4 mov r1, #0 */
/* @0xd2bd8 str r0, [r11, #0x10] */
/* @0xd2bdc bl 0xb65b0 <memset@plt> */
/* @0xd2be0 ldr r2, [r11] */
/* @0xd2be4 mov r0, #0 */
/* @0xd2be8 str r0, [r11, #0x4] */
/* @0xd2bec cmp r2, r0 */
/* @0xd2bf0 vmov s13, r2 */
/* @0xd2bf4 vcvt.f32.s32 s15, s13 */
/* @0xd2bf8 vmul.f32 s15, s15, s16 */
/* @0xd2bfc vcvt.s32.f32 s15, s15 */
/* @0xd2c00 vstr s15, [r11, #12] */
/* @0xd2c04 ble 0xd2c28 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x60c> */
/* @0xd2c08 add r2, r2, r2, lsl #1 */
/* @0xd2c0c ldr r3, [r11, #0x10] */
/* @0xd2c10 add r2, r3, r2, lsl #2 */
/* @0xd2c14 mov r0, #0 */
/* @0xd2c18 add r3, r3, #12 */
/* @0xd2c1c str r0, [r3, #-0x4] */
/* @0xd2c20 cmp r3, r2 */
/* @0xd2c24 bne 0xd2c14 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x5f8> */
/* @0xd2c28 cmp r8, #0 */
/* @0xd2c2c movgt r9, r7 */
/* @0xd2c30 movgt r10, #0 */
/* @0xd2c34 ble 0xd2c60 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x644> */
/* @0xd2c38 ldr r3, [r9, #0x8] */
/* @0xd2c3c mov r0, r11 */
/* @0xd2c40 add r10, r10, #1 */
/* @0xd2c44 cmp r3, #0 */
/* @0xd2c48 ble 0xd2c54 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x638> */
/* @0xd2c4c ldm r9, {r1, r2} */
/* @0xd2c50 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0xd2c54 cmp r10, r8 */
/* @0xd2c58 add r9, r9, #12 */
/* @0xd2c5c bne 0xd2c38 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x61c> */
/* @0xd2c60 mov r0, r7 */
/* @0xd2c64 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd2c68 vldr s13, [r11] */
/* @0xd2c6c vcvt.f32.s32 s15, s13 */
/* @0xd2c70 ldr r3, [r11, #0x4] */
/* @0xd2c74 vmul.f32 s15, s15, s16 */
/* @0xd2c78 vcvt.s32.f32 s15, s15 */
/* @0xd2c7c vstr s15, [r11, #12] */
/* @0xd2c80 b 0xd2a78 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x45c> */

/* ── FUNC 0xd2c84 · Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*) · size=668 · insn=167 */
/* @0xd2c84 push {r4, r5, r6, r7, r8, lr} */
/* @0xd2c88 mov r6, r1 */
/* @0xd2c8c ldr r5, [pc, #0x270] */
/* @0xd2c90 sub sp, sp, #8 */
/* @0xd2c94 ldr r3, [pc, #0x26c] */
/* @0xd2c98 add r5, pc, r5 */
/* @0xd2c9c ldr r3, [r5, r3] */
/* @0xd2ca0 ldr r3, [r3] */
/* @0xd2ca4 cmp r3, r0 */
/* @0xd2ca8 mov r0, r1 */
/* @0xd2cac beq 0xd2cc8 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x44> */
/* @0xd2cb0 bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc> */
/* @0xd2cb4 subs r4, r0, #0 */
/* @0xd2cb8 blt 0xd2d60 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xdc> */
/* @0xd2cbc mov r0, r4 */
/* @0xd2cc0 add sp, sp, #8 */
/* @0xd2cc4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xd2cc8 ldr r3, [pc, #0x23c] */
/* @0xd2ccc ldr r3, [r5, r3] */
/* @0xd2cd0 ldrb r7, [r3] */
/* @0xd2cd4 cmp r7, #0 */
/* @0xd2cd8 bne 0xd2cb0 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x2c> */
/* @0xd2cdc bl 0xd2054 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc> */
/* @0xd2ce0 subs r4, r0, #0 */
/* @0xd2ce4 bge 0xd2cbc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x38> */
/* @0xd2ce8 mov r0, r6 */
/* @0xd2cec bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xd2cf0 ldr r3, [pc, #0x218] */
/* @0xd2cf4 ldr r5, [r5, r3] */
/* @0xd2cf8 ldr r1, [r5, #0x4] */
/* @0xd2cfc ldr r12, [r5] */
/* @0xd2d00 cmp r1, #0 */
/* @0xd2d04 mov r8, r0 */
/* @0xd2d08 ble 0xd2e68 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1e4> */
/* @0xd2d0c cmp r12, #0 */
/* @0xd2d10 ldr r6, [r5, #0xc] */
/* @0xd2d14 ble 0xd2edc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x258> */
/* @0xd2d18 ldr r3, [r6] */
/* @0xd2d1c cmp r3, #0 */
/* @0xd2d20 movne r4, r7 */
/* @0xd2d24 movne r3, r6 */
/* @0xd2d28 bne 0xd2d3c <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xb8> */
/* @0xd2d2c b 0xd2ed8 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x254> */
/* @0xd2d30 ldr r2, [r3, #0x4]! */
/* @0xd2d34 cmp r2, #0 */
/* @0xd2d38 beq 0xd2d58 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xd4> */
/* @0xd2d3c add r4, r4, #1 */
/* @0xd2d40 cmp r4, r1 */
/* @0xd2d44 lsl r7, r4, #2 */
/* @0xd2d48 beq 0xd2e68 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1e4> */
/* @0xd2d4c cmp r4, r12 */
/* @0xd2d50 bne 0xd2d30 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xac> */
/* @0xd2d54 lsl r7, r4, #2 */
/* @0xd2d58 str r8, [r6, r7] */
/* @0xd2d5c b 0xd2cbc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x38> */
/* @0xd2d60 mov r0, r6 */
/* @0xd2d64 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xd2d68 ldr r3, [pc, #0x1a4] */
/* @0xd2d6c ldr r7, [r5, r3] */
/* @0xd2d70 ldr r12, [r7, #0x4] */
/* @0xd2d74 ldr lr, [r7] */
/* @0xd2d78 cmp r12, #0 */
/* @0xd2d7c mov r8, r0 */
/* @0xd2d80 ldrle r0, [r7, #0xc] */
/* @0xd2d84 ble 0xd2dfc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x178> */
/* @0xd2d88 cmp lr, #0 */
/* @0xd2d8c ble 0xd2e1c <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x198> */
/* @0xd2d90 ldr r0, [r7, #0xc] */
/* @0xd2d94 ldr r6, [r0] */
/* @0xd2d98 cmp r6, #0 */
/* @0xd2d9c movne r3, r0 */
/* @0xd2da0 movne r4, #0 */
/* @0xd2da4 bne 0xd2db8 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x134> */
/* @0xd2da8 b 0xd2efc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x278> */
/* @0xd2dac ldr r2, [r3, #0x4]! */
/* @0xd2db0 cmp r2, #0 */
/* @0xd2db4 beq 0xd2dd4 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x150> */
/* @0xd2db8 add r4, r4, #1 */
/* @0xd2dbc cmp r4, r12 */
/* @0xd2dc0 lsl r6, r4, #2 */
/* @0xd2dc4 beq 0xd2dfc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x178> */
/* @0xd2dc8 cmp r4, lr */
/* @0xd2dcc bne 0xd2dac <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x128> */
/* @0xd2dd0 lsl r6, r4, #2 */
/* @0xd2dd4 str r8, [r0, r6] */
/* @0xd2dd8 ldr r3, [pc, #0x138] */
/* @0xd2ddc mov r1, r8 */
/* @0xd2de0 mov r2, r4 */
/* @0xd2de4 ldr r3, [r5, r3] */
/* @0xd2de8 ldr r0, [r3] */
/* @0xd2dec bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0xd2df0 mov r0, r4 */
/* @0xd2df4 add sp, sp, #8 */
/* @0xd2df8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xd2dfc cmp r12, lr */
/* @0xd2e00 beq 0xd2e2c <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1a8> */
/* @0xd2e04 add r0, r0, r12, lsl #2 */
/* @0xd2e08 add r3, r12, #1 */
/* @0xd2e0c mov r4, r12 */
/* @0xd2e10 str r8, [r0] */
/* @0xd2e14 str r3, [r7, #0x4] */
/* @0xd2e18 b 0xd2dd8 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x154> */
/* @0xd2e1c mov r6, #0 */
/* @0xd2e20 ldr r0, [r7, #0xc] */
/* @0xd2e24 mov r4, r6 */
/* @0xd2e28 b 0xd2dd4 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x150> */
/* @0xd2e2c ldr r6, [r7, #0x8] */
/* @0xd2e30 add r6, r12, r6 */
/* @0xd2e34 cmp r12, r6 */
/* @0xd2e38 beq 0xd2e04 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x180> */
/* @0xd2e3c cmp r6, #0 */
/* @0xd2e40 bne 0xd2e88 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x204> */
/* @0xd2e44 cmp r0, #0 */
/* @0xd2e48 beq 0xd2ebc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x238> */
/* @0xd2e4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd2e50 mov r4, r6 */
/* @0xd2e54 mov r3, #1 */
/* @0xd2e58 mov r0, r6 */
/* @0xd2e5c str r6, [r7, #0xc] */
/* @0xd2e60 str r6, [r7] */
/* @0xd2e64 b 0xd2e10 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x18c> */
/* @0xd2e68 cmp r1, r12 */
/* @0xd2e6c movne r4, r1 */
/* @0xd2e70 beq 0xd2ee4 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x260> */
/* @0xd2e74 ldr r2, [r5, #0xc] */
/* @0xd2e78 add r3, r4, #1 */
/* @0xd2e7c str r8, [r2, r4, lsl #2] */
/* @0xd2e80 str r3, [r5, #0x4] */
/* @0xd2e84 b 0xd2cbc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x38> */
/* @0xd2e88 lsls r1, r6, #2 */
/* @0xd2e8c beq 0xd2ebc <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x238> */
/* @0xd2e90 ldr r2, [pc, #0x84] */
/* @0xd2e94 mov r3, #0 */
/* @0xd2e98 str r3, [sp] */
/* @0xd2e9c movw r3, #0x11b */
/* @0xd2ea0 add r2, pc, r2 */
/* @0xd2ea4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd2ea8 ldr r4, [r7, #0x4] */
/* @0xd2eac add r3, r4, #1 */
/* @0xd2eb0 str r0, [r7, #0xc] */
/* @0xd2eb4 add r0, r0, r4, lsl #2 */
/* @0xd2eb8 b 0xd2e60 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1dc> */
/* @0xd2ebc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd2ec0 mov r3, #0 */
/* @0xd2ec4 mov r0, r3 */
/* @0xd2ec8 str r3, [r7, #0xc] */
/* @0xd2ecc mov r4, r3 */
/* @0xd2ed0 mov r3, #1 */
/* @0xd2ed4 b 0xd2e60 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1dc> */
/* @0xd2ed8 mov r7, r3 */
/* @0xd2edc mov r4, r7 */
/* @0xd2ee0 b 0xd2d58 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0xd4> */
/* @0xd2ee4 ldr r3, [r5, #0x8] */
/* @0xd2ee8 mov r0, r5 */
/* @0xd2eec add r1, r1, r3 */
/* @0xd2ef0 bl 0xd1b3c <_ZN18cARRAY_OF_POINTERS9setLengthEi> */
/* @0xd2ef4 ldr r4, [r5, #0x4] */
/* @0xd2ef8 b 0xd2e74 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x1f0> */
/* @0xd2efc mov r4, r6 */
/* @0xd2f00 b 0xd2dd4 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc+0x150> */
/* @0xd2f04 ldrhteq lr, [r1], -r8 */
/* @0xd2f08 .word 0xffffbf64 */
/* @0xd2f0c .word 0xffffbf68 */
/* @0xd2f10 .word 0xffffbf4c */
/* @0xd2f14 .word 0xffffbf50 */
/* @0xd2f18 .word 0xffffbf54 */
/* @0xd2f1c eoreq pc, r5, r0, asr #16 */

/* ── FUNC 0xd2f20 · Code_Variable_Find_Set(char const*, int, int) · size=796 · insn=199 */
/* @0xd2f20 cmn r1, #6 */
/* @0xd2f24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd2f28 mov r9, r2 */
/* @0xd2f2c sub sp, sp, #12 */
/* @0xd2f30 mov r4, r0 */
/* @0xd2f34 beq 0xd3080 <_Z22Code_Variable_Find_SetPKcii+0x160> */
/* @0xd2f38 cmn r1, #5 */
/* @0xd2f3c beq 0xd309c <_Z22Code_Variable_Find_SetPKcii+0x17c> */
/* @0xd2f40 cmn r1, #1 */
/* @0xd2f44 beq 0xd2f58 <_Z22Code_Variable_Find_SetPKcii+0x38> */
/* @0xd2f48 add r9, r9, #99328 */
/* @0xd2f4c add r0, r9, #672 */
/* @0xd2f50 add sp, sp, #12 */
/* @0xd2f54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd2f58 ldr r5, [pc, #0x2cc] */
/* @0xd2f5c ldr r5, [pc, r5] */
/* @0xd2f60 ldr r3, [r5] */
/* @0xd2f64 cmp r2, r3 */
/* @0xd2f68 blt 0xd31e8 <_Z22Code_Variable_Find_SetPKcii+0x2c8> */
/* @0xd2f6c mov r0, r4 */
/* @0xd2f70 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xd2f74 ldr r3, [pc, #0x2b4] */
/* @0xd2f78 ldr r3, [pc, r3] */
/* @0xd2f7c ldr r3, [r3] */
/* @0xd2f80 str r3, [sp, #0x4] */
/* @0xd2f84 ldr r12, [sp, #0x4] */
/* @0xd2f88 ldr r3, [r3, #0x4] */
/* @0xd2f8c ldr r2, [r12, #0xc] */
/* @0xd2f90 cmp r3, r2 */
/* @0xd2f94 mov r8, r0 */
/* @0xd2f98 bgt 0xd30d8 <_Z22Code_Variable_Find_SetPKcii+0x1b8> */
/* @0xd2f9c ldr r12, [sp, #0x4] */
/* @0xd2fa0 add r3, r3, #1 */
/* @0xd2fa4 mov r0, r8 */
/* @0xd2fa8 str r3, [r12, #0x4] */
/* @0xd2fac bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0xd2fb0 ldr r12, [sp, #0x4] */
/* @0xd2fb4 ldr r5, [r12, #0x8] */
/* @0xd2fb8 ldr r10, [r12, #0x10] */
/* @0xd2fbc bic r0, r0, #-2147483648 */
/* @0xd2fc0 and r3, r0, r5 */
/* @0xd2fc4 add r1, r3, r3, lsl #1 */
/* @0xd2fc8 add r1, r10, r1, lsl #2 */
/* @0xd2fcc ldr r12, [r1, #0x8] */
/* @0xd2fd0 cmp r12, #0 */
/* @0xd2fd4 beq 0xd30c4 <_Z22Code_Variable_Find_SetPKcii+0x1a4> */
/* @0xd2fd8 ldr r2, [sp, #0x4] */
/* @0xd2fdc mov r6, #0 */
/* @0xd2fe0 ldr r11, [r2] */
/* @0xd2fe4 mov r2, r9 */
/* @0xd2fe8 b 0xd302c <_Z22Code_Variable_Find_SetPKcii+0x10c> */
/* @0xd2fec ldr r7, [r1] */
/* @0xd2ff0 ldr r6, [r1, #0x4] */
/* @0xd2ff4 str r0, [r1, #0x8] */
/* @0xd2ff8 mov r0, r12 */
/* @0xd2ffc str r8, [r1] */
/* @0xd3000 mov r8, r7 */
/* @0xd3004 str r2, [r1, #0x4] */
/* @0xd3008 mov r2, r6 */
/* @0xd300c add r3, r3, #1 */
/* @0xd3010 add r6, r4, #1 */
/* @0xd3014 and r3, r3, r5 */
/* @0xd3018 add r1, r3, r3, lsl #1 */
/* @0xd301c add r1, r10, r1, lsl #2 */
/* @0xd3020 ldr r12, [r1, #0x8] */
/* @0xd3024 cmp r12, #0 */
/* @0xd3028 beq 0xd30c8 <_Z22Code_Variable_Find_SetPKcii+0x1a8> */
/* @0xd302c add r4, r11, r3 */
/* @0xd3030 and r7, r12, r5 */
/* @0xd3034 rsb r4, r7, r4 */
/* @0xd3038 and r4, r4, r5 */
/* @0xd303c cmp r4, r6 */
/* @0xd3040 blt 0xd2fec <_Z22Code_Variable_Find_SetPKcii+0xcc> */
/* @0xd3044 movne r4, r6 */
/* @0xd3048 bne 0xd300c <_Z22Code_Variable_Find_SetPKcii+0xec> */
/* @0xd304c cmp r12, r0 */
/* @0xd3050 bne 0xd300c <_Z22Code_Variable_Find_SetPKcii+0xec> */
/* @0xd3054 ldr r6, [r1] */
/* @0xd3058 cmp r8, r6 */
/* @0xd305c bne 0xd300c <_Z22Code_Variable_Find_SetPKcii+0xec> */
/* @0xd3060 ldr r0, [sp, #0x4] */
/* @0xd3064 ldr r3, [r0, #0x4] */
/* @0xd3068 str r8, [r1] */
/* @0xd306c str r2, [r1, #0x4] */
/* @0xd3070 sub r3, r3, #1 */
/* @0xd3074 str r12, [r1, #0x8] */
/* @0xd3078 str r3, [r0, #0x4] */
/* @0xd307c b 0xd2f48 <_Z22Code_Variable_Find_SetPKcii+0x28> */
/* @0xd3080 bl 0xd2054 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc> */
/* @0xd3084 cmp r0, #0 */
/* @0xd3088 blt 0xd3208 <_Z22Code_Variable_Find_SetPKcii+0x2e8> */
/* @0xd308c add r0, r0, #99328 */
/* @0xd3090 add r0, r0, #672 */
/* @0xd3094 add sp, sp, #12 */
/* @0xd3098 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd309c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xd30a0 ldr r3, [pc, #0x18c] */
/* @0xd30a4 ldr r3, [pc, r3] */
/* @0xd30a8 ldr r2, [r3, #0x4] */
/* @0xd30ac ldr r1, [r3, #0xc] */
/* @0xd30b0 cmp r9, r2 */
/* @0xd30b4 addge r2, r9, #1 */
/* @0xd30b8 str r0, [r1, r9, lsl #2] */
/* @0xd30bc str r2, [r3, #0x4] */
/* @0xd30c0 b 0xd2f48 <_Z22Code_Variable_Find_SetPKcii+0x28> */
/* @0xd30c4 mov r2, r9 */
/* @0xd30c8 str r8, [r1] */
/* @0xd30cc str r2, [r1, #0x4] */
/* @0xd30d0 str r0, [r1, #0x8] */
/* @0xd30d4 b 0xd2f48 <_Z22Code_Variable_Find_SetPKcii+0x28> */
/* @0xd30d8 ldr r7, [r12] */
/* @0xd30dc mov r3, #1 */
/* @0xd30e0 ldr r1, [pc, #0x150] */
/* @0xd30e4 mov r2, #70 */
/* @0xd30e8 ldr r6, [r12, #0x10] */
/* @0xd30ec lsl r0, r7, r3 */
/* @0xd30f0 add r1, pc, r1 */
/* @0xd30f4 add r4, r0, r7, lsl #2 */
/* @0xd30f8 str r0, [r12] */
/* @0xd30fc sub r0, r0, #1 */
/* @0xd3100 str r0, [r12, #0x8] */
/* @0xd3104 lsl r4, r4, #2 */
/* @0xd3108 mov r0, r4 */
/* @0xd310c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd3110 ldr r12, [sp, #0x4] */
/* @0xd3114 mov r2, r4 */
/* @0xd3118 mov r1, #0 */
/* @0xd311c str r0, [r12, #0x10] */
/* @0xd3120 bl 0xb65b0 <memset@plt> */
/* @0xd3124 ldr r12, [sp, #0x4] */
/* @0xd3128 vldr s15, [pc, #248] */
/* @0xd312c mov r1, #0 */
/* @0xd3130 ldr r2, [r12] */
/* @0xd3134 str r1, [r12, #0x4] */
/* @0xd3138 cmp r2, r1 */
/* @0xd313c vmov s13, r2 */
/* @0xd3140 vcvt.f32.s32 s14, s13 */
/* @0xd3144 vmul.f32 s15, s14, s15 */
/* @0xd3148 vcvt.s32.f32 s15, s15 */
/* @0xd314c vstr s15, [r12, #12] */
/* @0xd3150 ble 0xd3174 <_Z22Code_Variable_Find_SetPKcii+0x254> */
/* @0xd3154 ldr r12, [sp, #0x4] */
/* @0xd3158 add r2, r2, r2, lsl #1 */
/* @0xd315c ldr r3, [r12, #0x10] */
/* @0xd3160 add r2, r3, r2, lsl #2 */
/* @0xd3164 str r1, [r3, #0x8] */
/* @0xd3168 add r3, r3, #12 */
/* @0xd316c cmp r3, r2 */
/* @0xd3170 bne 0xd3164 <_Z22Code_Variable_Find_SetPKcii+0x244> */
/* @0xd3174 cmp r7, #0 */
/* @0xd3178 ble 0xd31b0 <_Z22Code_Variable_Find_SetPKcii+0x290> */
/* @0xd317c ldr r10, [sp, #0x4] */
/* @0xd3180 mov r4, r6 */
/* @0xd3184 mov r5, #0 */
/* @0xd3188 ldr r3, [r4, #0x8] */
/* @0xd318c mov r0, r10 */
/* @0xd3190 add r5, r5, #1 */
/* @0xd3194 cmp r3, #0 */
/* @0xd3198 ble 0xd31a4 <_Z22Code_Variable_Find_SetPKcii+0x284> */
/* @0xd319c ldm r4, {r1, r2} */
/* @0xd31a0 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0xd31a4 cmp r5, r7 */
/* @0xd31a8 add r4, r4, #12 */
/* @0xd31ac bne 0xd3188 <_Z22Code_Variable_Find_SetPKcii+0x268> */
/* @0xd31b0 mov r0, r6 */
/* @0xd31b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd31b8 ldr r12, [sp, #0x4] */
/* @0xd31bc vldr s15, [pc, #100] */
/* @0xd31c0 ldr r12, [r12] */
/* @0xd31c4 str r12, [sp] */
/* @0xd31c8 vldr s13, [sp] */
/* @0xd31cc vcvt.f32.s32 s14, s13 */
/* @0xd31d0 ldr r12, [sp, #0x4] */
/* @0xd31d4 ldr r3, [r12, #0x4] */
/* @0xd31d8 vmul.f32 s15, s14, s15 */
/* @0xd31dc vcvt.s32.f32 s15, s15 */
/* @0xd31e0 vstr s15, [r12, #12] */
/* @0xd31e4 b 0xd2f9c <_Z22Code_Variable_Find_SetPKcii+0x7c> */
/* @0xd31e8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xd31ec ldr r3, [r5, #0x4] */
/* @0xd31f0 ldr r2, [r5, #0xc] */
/* @0xd31f4 cmp r9, r3 */
/* @0xd31f8 addge r3, r9, #1 */
/* @0xd31fc str r0, [r2, r9, lsl #2] */
/* @0xd3200 str r3, [r5, #0x4] */
/* @0xd3204 b 0xd2f6c <_Z22Code_Variable_Find_SetPKcii+0x4c> */
/* @0xd3208 mov r0, r4 */
/* @0xd320c bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc> */
/* @0xd3210 cmp r0, #0 */
/* @0xd3214 bge 0xd308c <_Z22Code_Variable_Find_SetPKcii+0x16c> */
/* @0xd3218 mov r0, r4 */
/* @0xd321c add sp, sp, #12 */
/* @0xd3220 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd3224 b 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0xd3228 svclo #0x19999a */
/* @0xd322c eorseq r10, r1, r4, asr #24 */
/* @0xd3230 eorseq r10, r1, r12, lsr #24 */
/* @0xd3234 ldrshteq r10, [r1], -r8 */
/* @0xd3238 eoreq sp, r5, r0, asr #30 */

/* ── FUNC 0xd323c · TErrStreamConsole::Create(wchar_t const*, bool) · size=8 · insn=2 */
/* @0xd323c mov r0, #1 */
/* @0xd3240 bx lr */

/* ── FUNC 0xd3244 · DoPushImmediate(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=16 · insn=4 */
/* @0xd3244 sxth r0, r0 */
/* @0xd3248 str r0, [r1, #-0x4]! */
/* @0xd324c mov r0, r1 */
/* @0xd3250 bx lr */

/* ── FUNC 0xd3254 · DoBranch(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=56 · insn=14 */
/* @0xd3254 ldr r2, [r3, #0x44] */
/* @0xd3258 lsl r12, r0, #9 */
/* @0xd325c mov r0, r1 */
/* @0xd3260 ldr r1, [r3, #0x5c] */
/* @0xd3264 sub r2, r2, #4 */
/* @0xd3268 add r2, r2, r12, asr #7 */
/* @0xd326c str r2, [r3, #0x44] */
/* @0xd3270 add r12, r2, #3 */
/* @0xd3274 cmp r2, #0 */
/* @0xd3278 movlt r2, r12 */
/* @0xd327c asr r2, r2, #2 */
/* @0xd3280 ldr r2, [r1, r2, lsl #2] */
/* @0xd3284 str r2, [r3, #0x48] */
/* @0xd3288 bx lr */

/* ── FUNC 0xd328c · DoBranchTrue(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=68 · insn=17 */
/* @0xd328c ldr r12, [r1] */
/* @0xd3290 cmp r12, #0 */
/* @0xd3294 beq 0xd32c8 <_Z12DoBranchTruejPhPKhP6VMExec+0x3c> */
/* @0xd3298 ldr r2, [r3, #0x44] */
/* @0xd329c lsl r0, r0, #9 */
/* @0xd32a0 ldr r12, [r3, #0x5c] */
/* @0xd32a4 sub r2, r2, #4 */
/* @0xd32a8 add r2, r2, r0, asr #7 */
/* @0xd32ac str r2, [r3, #0x44] */
/* @0xd32b0 add r0, r2, #3 */
/* @0xd32b4 cmp r2, #0 */
/* @0xd32b8 movlt r2, r0 */
/* @0xd32bc asr r2, r2, #2 */
/* @0xd32c0 ldr r2, [r12, r2, lsl #2] */
/* @0xd32c4 str r2, [r3, #0x48] */
/* @0xd32c8 add r0, r1, #4 */
/* @0xd32cc bx lr */

/* ── FUNC 0xd32d0 · DoBranchFalse(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=68 · insn=17 */
/* @0xd32d0 ldr r12, [r1] */
/* @0xd32d4 cmp r12, #0 */
/* @0xd32d8 bne 0xd330c <_Z13DoBranchFalsejPhPKhP6VMExec+0x3c> */
/* @0xd32dc ldr r2, [r3, #0x44] */
/* @0xd32e0 lsl r0, r0, #9 */
/* @0xd32e4 ldr r12, [r3, #0x5c] */
/* @0xd32e8 sub r2, r2, #4 */
/* @0xd32ec add r2, r2, r0, asr #7 */
/* @0xd32f0 str r2, [r3, #0x44] */
/* @0xd32f4 add r0, r2, #3 */
/* @0xd32f8 cmp r2, #0 */
/* @0xd32fc movlt r2, r0 */
/* @0xd3300 asr r2, r2, #2 */
/* @0xd3304 ldr r2, [r12, r2, lsl #2] */
/* @0xd3308 str r2, [r3, #0x48] */
/* @0xd330c add r0, r1, #4 */
/* @0xd3310 bx lr */

/* ── FUNC 0xd3314 · CBucket<32768u, 1048576u, false>::Free(void const*) · size=120 · insn=30 */
/* @0xd3314 ldr r3, [r0, #0x4] */
/* @0xd3318 str r4, [sp, #-0x4]! */
/* @0xd331c cmp r3, #0 */
/* @0xd3320 mov r4, r0 */
/* @0xd3324 beq 0xd3350 <_ZN7CBucketILj32768ELj1048576ELb0EE4FreeEPKv+0x3c> */
/* @0xd3328 add r12, r3, #8 */
/* @0xd332c add r2, r3, #1048576 */
/* @0xd3330 cmp r1, r12 */
/* @0xd3334 add r2, r2, #8 */
/* @0xd3338 blo 0xd3344 <_ZN7CBucketILj32768ELj1048576ELb0EE4FreeEPKv+0x30> */
/* @0xd333c cmp r2, r1 */
/* @0xd3340 bhi 0xd335c <_ZN7CBucketILj32768ELj1048576ELb0EE4FreeEPKv+0x48> */
/* @0xd3344 ldr r3, [r3] */
/* @0xd3348 cmp r3, #0 */
/* @0xd334c bne 0xd3328 <_ZN7CBucketILj32768ELj1048576ELb0EE4FreeEPKv+0x14> */
/* @0xd3350 mov r0, r3 */
/* @0xd3354 ldr r4, [sp], #4 */
/* @0xd3358 bx lr */
/* @0xd335c ldr r12, [r4, #0x8] */
/* @0xd3360 mov r0, #1 */
/* @0xd3364 ldr r2, [r4, #0x10] */
/* @0xd3368 ldr r3, [r4, #0xc] */
/* @0xd336c add r2, r2, r0 */
/* @0xd3370 str r12, [r1] */
/* @0xd3374 sub r3, r3, #1 */
/* @0xd3378 str r1, [r4, #0x8] */
/* @0xd337c str r2, [r4, #0x10] */
/* @0xd3380 str r3, [r4, #0xc] */
/* @0xd3384 ldr r4, [sp], #4 */
/* @0xd3388 bx lr */

/* ── FUNC 0xd338c · CBucket<32768u, 1048576u, false>::Init() · size=20 · insn=5 */
/* @0xd338c mov r3, #0 */
/* @0xd3390 str r3, [r0, #0x4] */
/* @0xd3394 str r3, [r0, #0x8] */
/* @0xd3398 str r3, [r0, #0xc] */
/* @0xd339c bx lr */

/* ── FUNC 0xd33a0 · CBucket<32768u, 1048576u, false>::Check() · size=124 · insn=31 */
/* @0xd33a0 ldr r12, [r0, #0x8] */
/* @0xd33a4 push {r4, r5, r6} */
/* @0xd33a8 cmp r12, #0 */
/* @0xd33ac beq 0xd3410 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x70> */
/* @0xd33b0 ldr r4, [pc, #0x60] */
/* @0xd33b4 mov r6, #0 */
/* @0xd33b8 mov r5, #42 */
/* @0xd33bc ldr r4, [pc, r4] */
/* @0xd33c0 ldr r3, [r0, #0x4] */
/* @0xd33c4 cmp r3, #0 */
/* @0xd33c8 beq 0xd33f4 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x54> */
/* @0xd33cc add r1, r3, #8 */
/* @0xd33d0 add r2, r3, #1048576 */
/* @0xd33d4 cmp r12, r1 */
/* @0xd33d8 add r2, r2, #8 */
/* @0xd33dc blo 0xd33e8 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x48> */
/* @0xd33e0 cmp r2, r12 */
/* @0xd33e4 bhi 0xd33f8 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x58> */
/* @0xd33e8 ldr r3, [r3] */
/* @0xd33ec cmp r3, #0 */
/* @0xd33f0 bne 0xd33cc <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x2c> */
/* @0xd33f4 str r5, [r6] */
/* @0xd33f8 ldr r12, [r12] */
/* @0xd33fc ldr r3, [r4] */
/* @0xd3400 cmp r12, #0 */
/* @0xd3404 add r3, r3, #1 */
/* @0xd3408 str r3, [r4] */
/* @0xd340c bne 0xd33c0 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x20> */
/* @0xd3410 pop {r4, r5, r6} */
/* @0xd3414 bx lr */
/* @0xd3418 eorseq r10, r1, r8, lsl #16 */

/* ── FUNC 0xd341c · CBucket<32768u, 1048576u, false>::GetSize() · size=8 · insn=2 */
/* @0xd341c mov r0, #32768 */
/* @0xd3420 bx lr */

/* ── FUNC 0xd3424 · TErrStreamConsole::~TErrStreamConsole() · size=64 · insn=16 */
/* @0xd3424 ldr r3, [pc, #0x30] */
/* @0xd3428 push {r4, lr} */
/* @0xd342c ldr r3, [pc, r3] */
/* @0xd3430 mov r4, r0 */
/* @0xd3434 add r3, r3, #8 */
/* @0xd3438 ldr r0, [r0, #0x8] */
/* @0xd343c str r3, [r4] */
/* @0xd3440 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd3444 ldr r3, [pc, #0x14] */
/* @0xd3448 mov r0, r4 */
/* @0xd344c ldr r3, [pc, r3] */
/* @0xd3450 add r3, r3, #8 */
/* @0xd3454 str r3, [r4] */
/* @0xd3458 pop {r4, pc} */
/* @0xd345c mlaseq r1, r12, r7, r10 */
/* @0xd3460 eorseq r10, r1, r4, lsl r5 */

/* ── FUNC 0xd3424 · TErrStreamConsole::~TErrStreamConsole() · alias of the symbol above · insn=0 */

/* ── FUNC 0xd3464 · TErrStreamConsole::~TErrStreamConsole() · size=72 · insn=18 */
/* @0xd3464 ldr r3, [pc, #0x38] */
/* @0xd3468 push {r4, lr} */
/* @0xd346c ldr r3, [pc, r3] */
/* @0xd3470 mov r4, r0 */
/* @0xd3474 add r3, r3, #8 */
/* @0xd3478 ldr r0, [r0, #0x8] */
/* @0xd347c str r3, [r4] */
/* @0xd3480 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd3484 ldr r3, [pc, #0x1c] */
/* @0xd3488 mov r0, r4 */
/* @0xd348c ldr r3, [pc, r3] */
/* @0xd3490 add r3, r3, #8 */
/* @0xd3494 str r3, [r4] */
/* @0xd3498 bl 0x27d1d0 <_ZdlPv> */
/* @0xd349c mov r0, r4 */
/* @0xd34a0 pop {r4, pc} */
/* @0xd34a4 eorseq r10, r1, r12, asr r7 */
/* @0xd34a8 ldrsbteq r10, [r1], -r4 */
