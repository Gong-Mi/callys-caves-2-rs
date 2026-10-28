/* libyoyo.so 覆盖卡组 0266
 * 函数 0x2c139c..0x2c3664，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2c139c · jpeg_mem_available · size=16 · insn=4 */
/* @0x2c139c ldr r2, [r0, #0x4] */
/* @0x2c13a0 ldr r0, [r2, #0x2c] */
/* @0x2c13a4 rsb r0, r3, r0 */
/* @0x2c13a8 bx lr */

/* ── FUNC 0x2c13ac · jpeg_open_backing_store · size=128 · insn=32 */
/* @0x2c13ac push {r3, r4, r5, lr} */
/* @0x2c13b0 mov r4, r1 */
/* @0x2c13b4 mov r5, r0 */
/* @0x2c13b8 bl 0xb6f64 <tmpfile@plt> */
/* @0x2c13bc cmp r0, #0 */
/* @0x2c13c0 str r0, [r4, #0xc] */
/* @0x2c13c4 beq 0x2c13e8 <jpeg_open_backing_store+0x3c> */
/* @0x2c13c8 ldr r1, [pc, #0x4c] */
/* @0x2c13cc ldr r2, [pc, #0x4c] */
/* @0x2c13d0 ldr r3, [pc, #0x4c] */
/* @0x2c13d4 add r1, pc, r1 */
/* @0x2c13d8 add r2, pc, r2 */
/* @0x2c13dc add r3, pc, r3 */
/* @0x2c13e0 stm r4, {r1, r2, r3} */
/* @0x2c13e4 pop {r3, r4, r5, pc} */
/* @0x2c13e8 ldr r3, [r5] */
/* @0x2c13ec mov r12, #63 */
/* @0x2c13f0 ldr r1, [pc, #0x30] */
/* @0x2c13f4 mov r2, #80 */
/* @0x2c13f8 add r0, r3, #24 */
/* @0x2c13fc str r12, [r3, #0x14] */
/* @0x2c1400 add r1, pc, r1 */
/* @0x2c1404 bl 0xb6568 <strncpy@plt> */
/* @0x2c1408 ldr r3, [r5] */
/* @0x2c140c mov r0, r5 */
/* @0x2c1410 ldr r3, [r3] */
/* @0x2c1414 blx r3 */
/* @0x2c1418 b 0x2c13c8 <jpeg_open_backing_store+0x1c> */
/* @0x2c141c .word 0xffffff20 */
/* @0x2c1420 .word 0xfffffe9c */
/* @0x2c1424 .word 0xfffffe90 */
/* @0x2c1428 andeq sp, r6, r6, lsr r7 */

/* ── FUNC 0x2c142c · jpeg_mem_init · size=12 · insn=3 */
/* @0x2c142c movw r0, #0x4240 */
/* @0x2c1430 movt r0, #0xf */
/* @0x2c1434 bx lr */

/* ── FUNC 0x2c1438 · jpeg_mem_term · size=4 · insn=1 */
/* @0x2c1438 bx lr */

/* ── FUNC 0x2c143c · anon_2c143c · size=1524 · insn=381 */
/* @0x2c143c ldr r2, [r0, #0x48] */
/* @0x2c1440 push {r4, r5, lr} */
/* @0x2c1444 mov r4, r0 */
/* @0x2c1448 ldr r3, [r2, #0x3c] */
/* @0x2c144c sub sp, sp, #12 */
/* @0x2c1450 mov r5, r1 */
/* @0x2c1454 cmp r3, #0 */
/* @0x2c1458 beq 0x2c149c <jpeg_mem_term+0x64> */
/* @0x2c145c add r1, sp, #4 */
/* @0x2c1460 mov r2, #2 */
/* @0x2c1464 blx r3 */
/* @0x2c1468 subs r0, r0, #2 */
/* @0x2c146c movne r0, #1 */
/* @0x2c1470 cmp r0, #0 */
/* @0x2c1474 ldrbeq r3, [sp, #0x4] */
/* @0x2c1478 movne r3, #102 */
/* @0x2c147c ldrbeq r2, [sp, #0x5] */
/* @0x2c1480 movne r0, #0 */
/* @0x2c1484 moveq r0, #1 */
/* @0x2c1488 strne r3, [r4, #0x40] */
/* @0x2c148c orreq r3, r3, r2, lsl #8 */
/* @0x2c1490 streq r3, [r5] */
/* @0x2c1494 add sp, sp, #12 */
/* @0x2c1498 pop {r4, r5, pc} */
/* @0x2c149c ldr r3, [r2, #0x38] */
/* @0x2c14a0 add r0, sp, #4 */
/* @0x2c14a4 mov r1, #1 */
/* @0x2c14a8 mov r2, #2 */
/* @0x2c14ac bl 0xb68c8 <fread@plt> */
/* @0x2c14b0 subs r0, r0, #2 */
/* @0x2c14b4 movne r0, #1 */
/* @0x2c14b8 b 0x2c1470 <jpeg_mem_term+0x38> */
/* @0x2c14bc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c14c0 mov r8, r1 */
/* @0x2c14c4 ldr r4, [r0, #0x48] */
/* @0x2c14c8 mov r5, r0 */
/* @0x2c14cc ldr r1, [r4, #0x18] */
/* @0x2c14d0 cmp r1, #12 */
/* @0x2c14d4 bgt 0x2c164c <jpeg_mem_term+0x214> */
/* @0x2c14d8 ldr r3, [r4, #0x2c] */
/* @0x2c14dc cmp r1, r3 */
/* @0x2c14e0 addgt r9, r4, #68 */
/* @0x2c14e4 addgt r6, r4, #69 */
/* @0x2c14e8 movgt r7, #2 */
/* @0x2c14ec ble 0x2c1678 <jpeg_mem_term+0x240> */
/* @0x2c14f0 ldrb r2, [r4, #0x44] */
/* @0x2c14f4 cmp r2, #0 */
/* @0x2c14f8 bne 0x2c1570 <jpeg_mem_term+0x138> */
/* @0x2c14fc ldr r2, [r5, #0x48] */
/* @0x2c1500 ldr r3, [r2, #0x3c] */
/* @0x2c1504 cmp r3, #0 */
/* @0x2c1508 beq 0x2c162c <jpeg_mem_term+0x1f4> */
/* @0x2c150c mov r0, r5 */
/* @0x2c1510 mov r1, r9 */
/* @0x2c1514 mov r2, #1 */
/* @0x2c1518 blx r3 */
/* @0x2c151c subs r0, r0, #1 */
/* @0x2c1520 movne r0, #1 */
/* @0x2c1524 cmp r0, #0 */
/* @0x2c1528 bne 0x2c1560 <jpeg_mem_term+0x128> */
/* @0x2c152c ldrb r2, [r4, #0x44] */
/* @0x2c1530 cmp r2, #0 */
/* @0x2c1534 beq 0x2c1614 <jpeg_mem_term+0x1dc> */
/* @0x2c1538 ldr r1, [r5, #0x48] */
/* @0x2c153c ldr r3, [r1, #0x3c] */
/* @0x2c1540 cmp r3, #0 */
/* @0x2c1544 beq 0x2c1680 <jpeg_mem_term+0x248> */
/* @0x2c1548 mov r0, r5 */
/* @0x2c154c mov r1, r6 */
/* @0x2c1550 blx r3 */
/* @0x2c1554 ldrb r3, [r4, #0x44] */
/* @0x2c1558 cmp r3, r0 */
/* @0x2c155c beq 0x2c165c <jpeg_mem_term+0x224> */
/* @0x2c1560 mov r3, #102 */
/* @0x2c1564 mov r0, #0 */
/* @0x2c1568 str r3, [r5, #0x40] */
/* @0x2c156c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c1570 ldrb r12, [r4, #0x45] */
/* @0x2c1574 sub r2, r2, #1 */
/* @0x2c1578 add r0, r12, #1 */
/* @0x2c157c strb r0, [r4, #0x45] */
/* @0x2c1580 ldrb r12, [r9, r12] */
/* @0x2c1584 strb r2, [r4, #0x44] */
/* @0x2c1588 ldr r2, [r4, #0x30] */
/* @0x2c158c orr r2, r2, r12, lsl r3 */
/* @0x2c1590 add r3, r3, #8 */
/* @0x2c1594 cmp r1, r3 */
/* @0x2c1598 str r2, [r4, #0x30] */
/* @0x2c159c str r3, [r4, #0x2c] */
/* @0x2c15a0 bgt 0x2c14f0 <jpeg_mem_term+0xb8> */
/* @0x2c15a4 ldr r3, [pc, #0xe8] */
/* @0x2c15a8 lsl r1, r1, #1 */
/* @0x2c15ac add r3, pc, r3 */
/* @0x2c15b0 ldrh r3, [r3, r1] */
/* @0x2c15b4 and r3, r3, r2 */
/* @0x2c15b8 str r3, [r8] */
/* @0x2c15bc ldr r1, [r4, #0x14] */
/* @0x2c15c0 ldr r3, [r4, #0x18] */
/* @0x2c15c4 ldr r0, [r4, #0x2c] */
/* @0x2c15c8 cmp r1, #4096 */
/* @0x2c15cc lsr r2, r2, r3 */
/* @0x2c15d0 str r2, [r4, #0x30] */
/* @0x2c15d4 rsb r2, r3, r0 */
/* @0x2c15d8 str r2, [r4, #0x2c] */
/* @0x2c15dc bgt 0x2c1624 <jpeg_mem_term+0x1ec> */
/* @0x2c15e0 ldr r2, [r4, #0x1c] */
/* @0x2c15e4 add r1, r1, #1 */
/* @0x2c15e8 str r1, [r4, #0x14] */
/* @0x2c15ec cmp r1, r2 */
/* @0x2c15f0 ble 0x2c1624 <jpeg_mem_term+0x1ec> */
/* @0x2c15f4 cmp r3, #11 */
/* @0x2c15f8 bgt 0x2c1624 <jpeg_mem_term+0x1ec> */
/* @0x2c15fc lsl r2, r2, #1 */
/* @0x2c1600 add r3, r3, #1 */
/* @0x2c1604 str r2, [r4, #0x1c] */
/* @0x2c1608 mov r0, #1 */
/* @0x2c160c str r3, [r4, #0x18] */
/* @0x2c1610 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c1614 mov r3, #112 */
/* @0x2c1618 mov r0, #0 */
/* @0x2c161c str r3, [r5, #0x40] */
/* @0x2c1620 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c1624 mov r0, #1 */
/* @0x2c1628 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c162c mov r1, #1 */
/* @0x2c1630 ldr r3, [r2, #0x38] */
/* @0x2c1634 mov r0, r9 */
/* @0x2c1638 mov r2, r1 */
/* @0x2c163c bl 0xb68c8 <fread@plt> */
/* @0x2c1640 subs r0, r0, #1 */
/* @0x2c1644 movne r0, #1 */
/* @0x2c1648 b 0x2c1524 <jpeg_mem_term+0xec> */
/* @0x2c164c mov r3, #112 */
/* @0x2c1650 mov r0, #0 */
/* @0x2c1654 str r3, [r5, #0x40] */
/* @0x2c1658 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c165c sub r0, r0, #1 */
/* @0x2c1660 ldrb r12, [r4, #0x45] */
/* @0x2c1664 strb r0, [r4, #0x44] */
/* @0x2c1668 strb r7, [r4, #0x45] */
/* @0x2c166c ldr r1, [r4, #0x18] */
/* @0x2c1670 ldr r3, [r4, #0x2c] */
/* @0x2c1674 b 0x2c1588 <jpeg_mem_term+0x150> */
/* @0x2c1678 ldr r2, [r4, #0x30] */
/* @0x2c167c b 0x2c15a4 <jpeg_mem_term+0x16c> */
/* @0x2c1680 ldr r3, [r1, #0x38] */
/* @0x2c1684 mov r0, r6 */
/* @0x2c1688 mov r1, #1 */
/* @0x2c168c bl 0xb68c8 <fread@plt> */
/* @0x2c1690 b 0x2c1554 <jpeg_mem_term+0x11c> */
/* @0x2c1694 strheq lr, [r12], -r4 */
/* @0x2c1698 ldr r12, [r0, #0x48] */
/* @0x2c169c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c16a0 mov r9, r2 */
/* @0x2c16a4 ldr r6, [r12, #0x28] */
/* @0x2c16a8 sub sp, sp, #44 */
/* @0x2c16ac ldr r2, [r12, #0x10] */
/* @0x2c16b0 cmp r6, #4096 */
/* @0x2c16b4 str r0, [sp, #0x8] */
/* @0x2c16b8 str r1, [sp, #0x14] */
/* @0x2c16bc str r2, [sp, #0xc] */
/* @0x2c16c0 ldr r8, [r12, #0xc] */
/* @0x2c16c4 ldr r11, [r12, #0x20] */
/* @0x2c16c8 bge 0x2c181c <jpeg_mem_term+0x3e4> */
/* @0x2c16cc cmp r6, #0 */
/* @0x2c16d0 add r10, r12, #324 */
/* @0x2c16d4 bne 0x2c1828 <jpeg_mem_term+0x3f0> */
/* @0x2c16d8 mov r7, r6 */
/* @0x2c16dc cmp r9, r7 */
/* @0x2c16e0 ble 0x2c18bc <jpeg_mem_term+0x484> */
/* @0x2c16e4 add r3, r12, #4416 */
/* @0x2c16e8 add r4, r12, #8512 */
/* @0x2c16ec add r3, r3, #3 */
/* @0x2c16f0 add r2, sp, #36 */
/* @0x2c16f4 add r4, r4, #4 */
/* @0x2c16f8 str r2, [sp, #0x10] */
/* @0x2c16fc movw r5, #0x1002 */
/* @0x2c1700 mov r2, r11 */
/* @0x2c1704 mov r11, r3 */
/* @0x2c1708 b 0x2c1740 <jpeg_mem_term+0x308> */
/* @0x2c170c ldr r0, [sp, #0x14] */
/* @0x2c1710 strb r3, [r0, r7] */
/* @0x2c1714 add r7, r7, #1 */
/* @0x2c1718 cmp r2, r5 */
/* @0x2c171c beq 0x2c1734 <jpeg_mem_term+0x2fc> */
/* @0x2c1720 ldr r3, [r12, #0x14] */
/* @0x2c1724 sub r3, r3, #-1073741822 */
/* @0x2c1728 ldr r1, [r4, r3, lsl #2] */
/* @0x2c172c cmp r1, r5 */
/* @0x2c1730 beq 0x2c18d0 <jpeg_mem_term+0x498> */
/* @0x2c1734 cmp r9, r7 */
/* @0x2c1738 ldr r2, [sp, #0x24] */
/* @0x2c173c ble 0x2c18b8 <jpeg_mem_term+0x480> */
/* @0x2c1740 ldr r0, [sp, #0x8] */
/* @0x2c1744 add r1, sp, #36 */
/* @0x2c1748 stm sp, {r2, r12} */
/* @0x2c174c bl 0x2c14bc <jpeg_mem_term+0x84> */
/* @0x2c1750 ldm sp, {r2, r12} */
/* @0x2c1754 cmp r0, #0 */
/* @0x2c1758 beq 0x2c181c <jpeg_mem_term+0x3e4> */
/* @0x2c175c ldr r3, [sp, #0x24] */
/* @0x2c1760 ldr r0, [sp, #0xc] */
/* @0x2c1764 cmp r3, r0 */
/* @0x2c1768 beq 0x2c19f0 <jpeg_mem_term+0x5b8> */
/* @0x2c176c cmp r8, r3 */
/* @0x2c1770 beq 0x2c1870 <jpeg_mem_term+0x438> */
/* @0x2c1774 bgt 0x2c170c <jpeg_mem_term+0x2d4> */
/* @0x2c1778 ldr r1, [r4, r3, lsl #2] */
/* @0x2c177c cmp r1, r5 */
/* @0x2c1780 beq 0x2c192c <jpeg_mem_term+0x4f4> */
/* @0x2c1784 movw r1, #0xffe */
/* @0x2c1788 cmp r6, r1 */
/* @0x2c178c cmple r8, r3 */
/* @0x2c1790 bge 0x2c17cc <jpeg_mem_term+0x394> */
/* @0x2c1794 cmp r3, #4096 */
/* @0x2c1798 bge 0x2c1a08 <jpeg_mem_term+0x5d0> */
/* @0x2c179c add r1, r10, r6 */
/* @0x2c17a0 b 0x2c17ac <jpeg_mem_term+0x374> */
/* @0x2c17a4 cmp r3, #4096 */
/* @0x2c17a8 bge 0x2c1a08 <jpeg_mem_term+0x5d0> */
/* @0x2c17ac ldrb r0, [r11, r3] */
/* @0x2c17b0 add r6, r6, #1 */
/* @0x2c17b4 strb r0, [r1], #1 */
/* @0x2c17b8 movw r0, #0xffe */
/* @0x2c17bc ldr r3, [r4, r3, lsl #2] */
/* @0x2c17c0 cmp r6, r0 */
/* @0x2c17c4 cmple r8, r3 */
/* @0x2c17c8 blt 0x2c17a4 <jpeg_mem_term+0x36c> */
/* @0x2c17cc movw r1, #0xfff */
/* @0x2c17d0 movw r0, #0xffe */
/* @0x2c17d4 cmp r6, r0 */
/* @0x2c17d8 cmple r3, r1 */
/* @0x2c17dc bgt 0x2c1a08 <jpeg_mem_term+0x5d0> */
/* @0x2c17e0 cmn r6, #1 */
/* @0x2c17e4 cmpne r9, r7 */
/* @0x2c17e8 strb r3, [r10, r6] */
/* @0x2c17ec add r6, r6, #1 */
/* @0x2c17f0 ble 0x2c1718 <jpeg_mem_term+0x2e0> */
/* @0x2c17f4 ldr r0, [sp, #0x14] */
/* @0x2c17f8 add r3, r0, r7 */
/* @0x2c17fc sub r6, r6, #1 */
/* @0x2c1800 add r7, r7, #1 */
/* @0x2c1804 cmp r6, #0 */
/* @0x2c1808 cmpne r9, r7 */
/* @0x2c180c ldrb r1, [r10, r6] */
/* @0x2c1810 strb r1, [r3], #1 */
/* @0x2c1814 bgt 0x2c17fc <jpeg_mem_term+0x3c4> */
/* @0x2c1818 b 0x2c1718 <jpeg_mem_term+0x2e0> */
/* @0x2c181c mov r0, #0 */
/* @0x2c1820 add sp, sp, #44 */
/* @0x2c1824 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c1828 cmp r9, #0 */
/* @0x2c182c ble 0x2c18bc <jpeg_mem_term+0x484> */
/* @0x2c1830 ldr r0, [sp, #0x14] */
/* @0x2c1834 add r2, r10, r6 */
/* @0x2c1838 mov r7, #0 */
/* @0x2c183c sub r3, r0, #1 */
/* @0x2c1840 subs r6, r6, #1 */
/* @0x2c1844 add r7, r7, #1 */
/* @0x2c1848 ldrb r1, [r2, #-0x1]! */
/* @0x2c184c moveq r0, #0 */
/* @0x2c1850 movne r0, #1 */
/* @0x2c1854 cmp r9, r7 */
/* @0x2c1858 movle r0, #0 */
/* @0x2c185c andgt r0, r0, #1 */
/* @0x2c1860 cmp r0, #0 */
/* @0x2c1864 strb r1, [r3, #0x1]! */
/* @0x2c1868 bne 0x2c1840 <jpeg_mem_term+0x408> */
/* @0x2c186c b 0x2c16dc <jpeg_mem_term+0x2a4> */
/* @0x2c1870 mov r3, #0 */
/* @0x2c1874 str r5, [r4, r3] */
/* @0x2c1878 add r3, r3, #4 */
/* @0x2c187c cmp r3, #16384 */
/* @0x2c1880 movw r2, #0x1002 */
/* @0x2c1884 bne 0x2c1874 <jpeg_mem_term+0x43c> */
/* @0x2c1888 ldr r3, [r12, #0x8] */
/* @0x2c188c cmp r9, r7 */
/* @0x2c1890 ldr r0, [r12, #0x10] */
/* @0x2c1894 mov r1, #1 */
/* @0x2c1898 add r3, r3, r1 */
/* @0x2c189c str r2, [r12, #0x20] */
/* @0x2c18a0 str r3, [r12, #0x18] */
/* @0x2c18a4 add r0, r0, r1 */
/* @0x2c18a8 lsl r3, r1, r3 */
/* @0x2c18ac str r0, [r12, #0x14] */
/* @0x2c18b0 str r3, [r12, #0x1c] */
/* @0x2c18b4 bgt 0x2c1740 <jpeg_mem_term+0x308> */
/* @0x2c18b8 mov r11, r2 */
/* @0x2c18bc mov r0, #1 */
/* @0x2c18c0 str r11, [r12, #0x20] */
/* @0x2c18c4 str r6, [r12, #0x28] */
/* @0x2c18c8 add sp, sp, #44 */
/* @0x2c18cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c18d0 str r2, [r4, r3, lsl #2] */
/* @0x2c18d4 ldr r1, [r12, #0x14] */
/* @0x2c18d8 ldr r3, [sp, #0x24] */
/* @0x2c18dc sub r1, r1, #2 */
/* @0x2c18e0 cmp r1, r3 */
/* @0x2c18e4 beq 0x2c19ac <jpeg_mem_term+0x574> */
/* @0x2c18e8 cmp r8, r3 */
/* @0x2c18ec bge 0x2c1920 <jpeg_mem_term+0x4e8> */
/* @0x2c18f0 cmp r3, #4096 */
/* @0x2c18f4 bge 0x2c1918 <jpeg_mem_term+0x4e0> */
/* @0x2c18f8 mov r2, #4096 */
/* @0x2c18fc ldr r3, [r4, r3, lsl #2] */
/* @0x2c1900 cmp r8, r3 */
/* @0x2c1904 bge 0x2c1920 <jpeg_mem_term+0x4e8> */
/* @0x2c1908 subs r2, r2, #1 */
/* @0x2c190c beq 0x2c1920 <jpeg_mem_term+0x4e8> */
/* @0x2c1910 cmp r3, #4096 */
/* @0x2c1914 blt 0x2c18fc <jpeg_mem_term+0x4c4> */
/* @0x2c1918 mov r3, #2 */
/* @0x2c191c b 0x2c1924 <jpeg_mem_term+0x4ec> */
/* @0x2c1920 uxtb r3, r3 */
/* @0x2c1924 strb r3, [r11, r1] */
/* @0x2c1928 b 0x2c1734 <jpeg_mem_term+0x2fc> */
/* @0x2c192c ldr r1, [r12, #0x14] */
/* @0x2c1930 sub r1, r1, #2 */
/* @0x2c1934 cmp r3, r1 */
/* @0x2c1938 bne 0x2c1a1c <jpeg_mem_term+0x5e4> */
/* @0x2c193c cmp r8, r2 */
/* @0x2c1940 add r1, r6, #1 */
/* @0x2c1944 add r3, r11, r3 */
/* @0x2c1948 str r1, [sp, #0x1c] */
/* @0x2c194c str r3, [sp, #0x18] */
/* @0x2c1950 add r0, r10, r6 */
/* @0x2c1954 uxtbge r1, r2 */
/* @0x2c1958 bge 0x2c1994 <jpeg_mem_term+0x55c> */
/* @0x2c195c cmp r2, #4096 */
/* @0x2c1960 bge 0x2c1988 <jpeg_mem_term+0x550> */
/* @0x2c1964 mov r3, r2 */
/* @0x2c1968 mov r1, #4096 */
/* @0x2c196c ldr r3, [r4, r3, lsl #2] */
/* @0x2c1970 cmp r8, r3 */
/* @0x2c1974 bge 0x2c1990 <jpeg_mem_term+0x558> */
/* @0x2c1978 subs r1, r1, #1 */
/* @0x2c197c beq 0x2c1990 <jpeg_mem_term+0x558> */
/* @0x2c1980 cmp r3, #4096 */
/* @0x2c1984 blt 0x2c196c <jpeg_mem_term+0x534> */
/* @0x2c1988 mov r1, #2 */
/* @0x2c198c b 0x2c1994 <jpeg_mem_term+0x55c> */
/* @0x2c1990 uxtb r1, r3 */
/* @0x2c1994 strb r1, [r0] */
/* @0x2c1998 mov r3, r2 */
/* @0x2c199c ldr r0, [sp, #0x18] */
/* @0x2c19a0 ldr r6, [sp, #0x1c] */
/* @0x2c19a4 strb r1, [r0] */
/* @0x2c19a8 b 0x2c1784 <jpeg_mem_term+0x34c> */
/* @0x2c19ac cmp r8, r2 */
/* @0x2c19b0 bge 0x2c19e4 <jpeg_mem_term+0x5ac> */
/* @0x2c19b4 cmp r2, #4096 */
/* @0x2c19b8 bge 0x2c19dc <jpeg_mem_term+0x5a4> */
/* @0x2c19bc mov r3, #4096 */
/* @0x2c19c0 ldr r2, [r4, r2, lsl #2] */
/* @0x2c19c4 cmp r8, r2 */
/* @0x2c19c8 bge 0x2c19e4 <jpeg_mem_term+0x5ac> */
/* @0x2c19cc subs r3, r3, #1 */
/* @0x2c19d0 beq 0x2c19e4 <jpeg_mem_term+0x5ac> */
/* @0x2c19d4 cmp r2, #4096 */
/* @0x2c19d8 blt 0x2c19c0 <jpeg_mem_term+0x588> */
/* @0x2c19dc mov r2, #2 */
/* @0x2c19e0 b 0x2c19e8 <jpeg_mem_term+0x5b0> */
/* @0x2c19e4 uxtb r2, r2 */
/* @0x2c19e8 strb r2, [r11, r1] */
/* @0x2c19ec b 0x2c1734 <jpeg_mem_term+0x2fc> */
/* @0x2c19f0 ldr r1, [sp, #0x8] */
/* @0x2c19f4 mov r3, #113 */
/* @0x2c19f8 mov r0, #0 */
/* @0x2c19fc str r3, [r1, #0x40] */
/* @0x2c1a00 add sp, sp, #44 */
/* @0x2c1a04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c1a08 ldr r1, [sp, #0x8] */
/* @0x2c1a0c mov r3, #112 */
/* @0x2c1a10 mov r0, #0 */
/* @0x2c1a14 str r3, [r1, #0x40] */
/* @0x2c1a18 b 0x2c1820 <jpeg_mem_term+0x3e8> */
/* @0x2c1a1c ldr r2, [sp, #0x8] */
/* @0x2c1a20 mov r3, #112 */
/* @0x2c1a24 mov r0, #0 */
/* @0x2c1a28 str r3, [r2, #0x40] */
/* @0x2c1a2c b 0x2c1820 <jpeg_mem_term+0x3e8> */

/* ── FUNC 0x2c1a30 · DGifGetScreenDesc(GifFileType*) · size=544 · insn=136 */
/* @0x2c1a30 ldr r3, [r0, #0x48] */
/* @0x2c1a34 push {r4, r5, r6, r7, lr} */
/* @0x2c1a38 mov r4, r0 */
/* @0x2c1a3c ldr r3, [r3] */
/* @0x2c1a40 sub sp, sp, #12 */
/* @0x2c1a44 ands r3, r3, #8 */
/* @0x2c1a48 moveq r2, #111 */
/* @0x2c1a4c streq r2, [r0, #0x40] */
/* @0x2c1a50 bne 0x2c1a60 <_Z17DGifGetScreenDescP11GifFileType+0x30> */
/* @0x2c1a54 mov r0, r3 */
/* @0x2c1a58 add sp, sp, #12 */
/* @0x2c1a5c pop {r4, r5, r6, r7, pc} */
/* @0x2c1a60 mov r1, r0 */
/* @0x2c1a64 bl 0x2c143c <jpeg_mem_term+0x4> */
/* @0x2c1a68 cmp r0, #0 */
/* @0x2c1a6c bne 0x2c1a80 <_Z17DGifGetScreenDescP11GifFileType+0x50> */
/* @0x2c1a70 mov r3, #0 */
/* @0x2c1a74 mov r0, r3 */
/* @0x2c1a78 add sp, sp, #12 */
/* @0x2c1a7c pop {r4, r5, r6, r7, pc} */
/* @0x2c1a80 mov r0, r4 */
/* @0x2c1a84 add r1, r4, #4 */
/* @0x2c1a88 bl 0x2c143c <jpeg_mem_term+0x4> */
/* @0x2c1a8c cmp r0, #0 */
/* @0x2c1a90 beq 0x2c1a70 <_Z17DGifGetScreenDescP11GifFileType+0x40> */
/* @0x2c1a94 ldr r2, [r4, #0x48] */
/* @0x2c1a98 ldr r3, [r2, #0x3c] */
/* @0x2c1a9c cmp r3, #0 */
/* @0x2c1aa0 beq 0x2c1b04 <_Z17DGifGetScreenDescP11GifFileType+0xd4> */
/* @0x2c1aa4 add r6, sp, #4 */
/* @0x2c1aa8 mov r0, r4 */
/* @0x2c1aac mov r2, #3 */
/* @0x2c1ab0 mov r1, r6 */
/* @0x2c1ab4 blx r3 */
/* @0x2c1ab8 subs r5, r0, #3 */
/* @0x2c1abc movne r5, #1 */
/* @0x2c1ac0 cmp r5, #0 */
/* @0x2c1ac4 bne 0x2c1b28 <_Z17DGifGetScreenDescP11GifFileType+0xf8> */
/* @0x2c1ac8 ldrb r7, [sp, #0x4] */
/* @0x2c1acc ldrb r1, [sp, #0x5] */
/* @0x2c1ad0 ldrb r3, [sp, #0x6] */
/* @0x2c1ad4 tst r7, #128 */
/* @0x2c1ad8 ubfx r2, r7, #0x4, #0x3 */
/* @0x2c1adc streq r5, [r4, #0x14] */
/* @0x2c1ae0 add r2, r2, #1 */
/* @0x2c1ae4 str r1, [r4, #0xc] */
/* @0x2c1ae8 str r2, [r4, #0x8] */
/* @0x2c1aec strb r3, [r4, #0x10] */
/* @0x2c1af0 bne 0x2c1b48 <_Z17DGifGetScreenDescP11GifFileType+0x118> */
/* @0x2c1af4 mov r3, #1 */
/* @0x2c1af8 mov r0, r3 */
/* @0x2c1afc add sp, sp, #12 */
/* @0x2c1b00 pop {r4, r5, r6, r7, pc} */
/* @0x2c1b04 add r6, sp, #4 */
/* @0x2c1b08 ldr r3, [r2, #0x38] */
/* @0x2c1b0c mov r1, #1 */
/* @0x2c1b10 mov r2, #3 */
/* @0x2c1b14 mov r0, r6 */
/* @0x2c1b18 bl 0xb68c8 <fread@plt> */
/* @0x2c1b1c subs r5, r0, #3 */
/* @0x2c1b20 movne r5, #1 */
/* @0x2c1b24 b 0x2c1ac0 <_Z17DGifGetScreenDescP11GifFileType+0x90> */
/* @0x2c1b28 mov r3, #102 */
/* @0x2c1b2c ldr r0, [r4, #0x14] */
/* @0x2c1b30 str r3, [r4, #0x40] */
/* @0x2c1b34 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c1b38 mov r2, #0 */
/* @0x2c1b3c mov r3, r2 */
/* @0x2c1b40 str r2, [r4, #0x14] */
/* @0x2c1b44 b 0x2c1a54 <_Z17DGifGetScreenDescP11GifFileType+0x24> */
/* @0x2c1b48 and r3, r7, #7 */
/* @0x2c1b4c mov r0, #1 */
/* @0x2c1b50 add r3, r3, r0 */
/* @0x2c1b54 mov r1, r5 */
/* @0x2c1b58 lsl r0, r0, r3 */
/* @0x2c1b5c bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType> */
/* @0x2c1b60 cmp r0, #0 */
/* @0x2c1b64 str r0, [r4, #0x14] */
/* @0x2c1b68 moveq r2, #109 */
/* @0x2c1b6c moveq r3, r5 */
/* @0x2c1b70 streq r2, [r4, #0x40] */
/* @0x2c1b74 beq 0x2c1a54 <_Z17DGifGetScreenDescP11GifFileType+0x24> */
/* @0x2c1b78 ldr r3, [r0] */
/* @0x2c1b7c ubfx r7, r7, #0x3, #0x1 */
/* @0x2c1b80 strb r7, [r0, #0x8] */
/* @0x2c1b84 cmp r3, #0 */
/* @0x2c1b88 bgt 0x2c1bf4 <_Z17DGifGetScreenDescP11GifFileType+0x1c4> */
/* @0x2c1b8c b 0x2c1af4 <_Z17DGifGetScreenDescP11GifFileType+0xc4> */
/* @0x2c1b90 blx r3 */
/* @0x2c1b94 subs r0, r0, #3 */
/* @0x2c1b98 movne r0, #1 */
/* @0x2c1b9c cmp r0, #0 */
/* @0x2c1ba0 add r3, r5, r5, lsl #1 */
/* @0x2c1ba4 add r5, r5, #1 */
/* @0x2c1ba8 bne 0x2c1c30 <_Z17DGifGetScreenDescP11GifFileType+0x200> */
/* @0x2c1bac ldr r2, [r4, #0x14] */
/* @0x2c1bb0 ldrb r1, [sp, #0x4] */
/* @0x2c1bb4 ldr r2, [r2, #0xc] */
/* @0x2c1bb8 strb r1, [r2, r3] */
/* @0x2c1bbc ldr r2, [r4, #0x14] */
/* @0x2c1bc0 ldrb r1, [sp, #0x5] */
/* @0x2c1bc4 ldr r2, [r2, #0xc] */
/* @0x2c1bc8 add r2, r2, r3 */
/* @0x2c1bcc strb r1, [r2, #0x1] */
/* @0x2c1bd0 ldr r1, [r4, #0x14] */
/* @0x2c1bd4 ldrb r2, [sp, #0x6] */
/* @0x2c1bd8 ldr r1, [r1, #0xc] */
/* @0x2c1bdc add r3, r1, r3 */
/* @0x2c1be0 strb r2, [r3, #0x2] */
/* @0x2c1be4 ldr r3, [r4, #0x14] */
/* @0x2c1be8 ldr r3, [r3] */
/* @0x2c1bec cmp r3, r5 */
/* @0x2c1bf0 ble 0x2c1af4 <_Z17DGifGetScreenDescP11GifFileType+0xc4> */
/* @0x2c1bf4 ldr r12, [r4, #0x48] */
/* @0x2c1bf8 mov r0, r4 */
/* @0x2c1bfc mov r1, r6 */
/* @0x2c1c00 mov r2, #3 */
/* @0x2c1c04 ldr r3, [r12, #0x3c] */
/* @0x2c1c08 cmp r3, #0 */
/* @0x2c1c0c bne 0x2c1b90 <_Z17DGifGetScreenDescP11GifFileType+0x160> */
/* @0x2c1c10 ldr r3, [r12, #0x38] */
/* @0x2c1c14 mov r0, r6 */
/* @0x2c1c18 mov r1, #1 */
/* @0x2c1c1c mov r2, #3 */
/* @0x2c1c20 bl 0xb68c8 <fread@plt> */
/* @0x2c1c24 subs r0, r0, #3 */
/* @0x2c1c28 movne r0, #1 */
/* @0x2c1c2c b 0x2c1b9c <_Z17DGifGetScreenDescP11GifFileType+0x16c> */
/* @0x2c1c30 ldr r0, [r4, #0x14] */
/* @0x2c1c34 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c1c38 mov r2, #0 */
/* @0x2c1c3c mov r3, r2 */
/* @0x2c1c40 str r2, [r4, #0x14] */
/* @0x2c1c44 mov r2, #102 */
/* @0x2c1c48 str r2, [r4, #0x40] */
/* @0x2c1c4c b 0x2c1a54 <_Z17DGifGetScreenDescP11GifFileType+0x24> */

/* ── FUNC 0x2c1c50 · DGifOpen(void*, int (*)(GifFileType*, unsigned char*, int), int*) · size=360 · insn=90 */
/* @0x2c1c50 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c1c54 mov r9, r0 */
/* @0x2c1c58 sub sp, sp, #12 */
/* @0x2c1c5c mov r0, #76 */
/* @0x2c1c60 mov r7, r1 */
/* @0x2c1c64 mov r8, r2 */
/* @0x2c1c68 bl 0xb6544 <malloc@plt> */
/* @0x2c1c6c subs r4, r0, #0 */
/* @0x2c1c70 beq 0x2c1d34 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0xe4> */
/* @0x2c1c74 mov r1, #0 */
/* @0x2c1c78 mov r2, #76 */
/* @0x2c1c7c bl 0xb65b0 <memset@plt> */
/* @0x2c1c80 mov r6, #0 */
/* @0x2c1c84 movw r0, #0x614c */
/* @0x2c1c88 str r6, [r4, #0x34] */
/* @0x2c1c8c str r6, [r4, #0x14] */
/* @0x2c1c90 bl 0xb6544 <malloc@plt> */
/* @0x2c1c94 subs r5, r0, #0 */
/* @0x2c1c98 beq 0x2c1da4 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x154> */
/* @0x2c1c9c cmp r7, #0 */
/* @0x2c1ca0 mov r3, #8 */
/* @0x2c1ca4 str r5, [r4, #0x48] */
/* @0x2c1ca8 str r6, [r5, #0x4] */
/* @0x2c1cac str r6, [r5, #0x38] */
/* @0x2c1cb0 str r7, [r5, #0x3c] */
/* @0x2c1cb4 str r9, [r4, #0x44] */
/* @0x2c1cb8 str r3, [r5] */
/* @0x2c1cbc beq 0x2c1d8c <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x13c> */
/* @0x2c1cc0 mov r0, r4 */
/* @0x2c1cc4 mov r2, #6 */
/* @0x2c1cc8 mov r1, sp */
/* @0x2c1ccc blx r7 */
/* @0x2c1cd0 cmp r0, #6 */
/* @0x2c1cd4 bne 0x2c1d7c <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x12c> */
/* @0x2c1cd8 ldr r0, [pc, #0xd4] */
/* @0x2c1cdc mov r1, sp */
/* @0x2c1ce0 mov r2, #3 */
/* @0x2c1ce4 mov r3, #0 */
/* @0x2c1ce8 add r0, pc, r0 */
/* @0x2c1cec strb r3, [sp, #0x6] */
/* @0x2c1cf0 bl 0xb65e0 <strncmp@plt> */
/* @0x2c1cf4 subs r6, r0, #0 */
/* @0x2c1cf8 bne 0x2c1d54 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x104> */
/* @0x2c1cfc mov r0, r4 */
/* @0x2c1d00 bl 0x2c1a30 <_Z17DGifGetScreenDescP11GifFileType> */
/* @0x2c1d04 subs r7, r0, #0 */
/* @0x2c1d08 beq 0x2c1d60 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x110> */
/* @0x2c1d0c ldrb r2, [sp, #0x3] */
/* @0x2c1d10 movw r3, #0x6148 */
/* @0x2c1d14 mov r0, r4 */
/* @0x2c1d18 str r6, [r4, #0x40] */
/* @0x2c1d1c subs r1, r2, #57 */
/* @0x2c1d20 rsbs r2, r1, #0 */
/* @0x2c1d24 adcs r2, r2, r1 */
/* @0x2c1d28 strb r2, [r5, r3] */
/* @0x2c1d2c add sp, sp, #12 */
/* @0x2c1d30 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c1d34 cmp r8, #0 */
/* @0x2c1d38 moveq r0, r8 */
/* @0x2c1d3c beq 0x2c1d2c <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0xdc> */
/* @0x2c1d40 mov r0, r4 */
/* @0x2c1d44 mov r3, #109 */
/* @0x2c1d48 str r3, [r8] */
/* @0x2c1d4c add sp, sp, #12 */
/* @0x2c1d50 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c1d54 cmp r8, #0 */
/* @0x2c1d58 movne r3, #103 */
/* @0x2c1d5c strne r3, [r8] */
/* @0x2c1d60 mov r0, r5 */
/* @0x2c1d64 bl 0xb655c <free@plt> */
/* @0x2c1d68 mov r0, r4 */
/* @0x2c1d6c bl 0xb655c <free@plt> */
/* @0x2c1d70 mov r0, #0 */
/* @0x2c1d74 add sp, sp, #12 */
/* @0x2c1d78 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c1d7c cmp r8, #0 */
/* @0x2c1d80 movne r3, #102 */
/* @0x2c1d84 strne r3, [r8] */
/* @0x2c1d88 b 0x2c1d60 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x110> */
/* @0x2c1d8c mov r3, r7 */
/* @0x2c1d90 mov r1, #1 */
/* @0x2c1d94 mov r2, #6 */
/* @0x2c1d98 mov r0, sp */
/* @0x2c1d9c bl 0xb68c8 <fread@plt> */
/* @0x2c1da0 b 0x2c1cd0 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x80> */
/* @0x2c1da4 cmp r8, r6 */
/* @0x2c1da8 movne r3, #109 */
/* @0x2c1dac strne r3, [r8] */
/* @0x2c1db0 b 0x2c1d68 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x118> */
/* @0x2c1db4 andeq r9, r9, r0, asr r10 */

/* ── FUNC 0x2c1db8 · DGifGetRecordType(GifFileType*, GifRecordType*) · size=240 · insn=60 */
/* @0x2c1db8 ldr r2, [r0, #0x48] */
/* @0x2c1dbc push {r4, r5, lr} */
/* @0x2c1dc0 mov r4, r0 */
/* @0x2c1dc4 ldr r3, [r2] */
/* @0x2c1dc8 sub sp, sp, #12 */
/* @0x2c1dcc mov r5, r1 */
/* @0x2c1dd0 ands r3, r3, #8 */
/* @0x2c1dd4 moveq r2, #111 */
/* @0x2c1dd8 streq r2, [r0, #0x40] */
/* @0x2c1ddc beq 0x2c1e34 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x7c> */
/* @0x2c1de0 ldr r3, [r2, #0x3c] */
/* @0x2c1de4 cmp r3, #0 */
/* @0x2c1de8 beq 0x2c1e88 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0xd0> */
/* @0x2c1dec add r1, sp, #7 */
/* @0x2c1df0 mov r2, #1 */
/* @0x2c1df4 blx r3 */
/* @0x2c1df8 subs r0, r0, #1 */
/* @0x2c1dfc movne r0, #1 */
/* @0x2c1e00 cmp r0, #0 */
/* @0x2c1e04 bne 0x2c1e40 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x88> */
/* @0x2c1e08 ldrb r3, [sp, #0x7] */
/* @0x2c1e0c cmp r3, #44 */
/* @0x2c1e10 beq 0x2c1e78 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0xc0> */
/* @0x2c1e14 cmp r3, #59 */
/* @0x2c1e18 beq 0x2c1e58 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0xa0> */
/* @0x2c1e1c cmp r3, #33 */
/* @0x2c1e20 beq 0x2c1e68 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0xb0> */
/* @0x2c1e24 mov r3, r0 */
/* @0x2c1e28 str r0, [r5] */
/* @0x2c1e2c mov r2, #107 */
/* @0x2c1e30 str r2, [r4, #0x40] */
/* @0x2c1e34 mov r0, r3 */
/* @0x2c1e38 add sp, sp, #12 */
/* @0x2c1e3c pop {r4, r5, pc} */
/* @0x2c1e40 mov r3, #0 */
/* @0x2c1e44 mov r2, #102 */
/* @0x2c1e48 mov r0, r3 */
/* @0x2c1e4c str r2, [r4, #0x40] */
/* @0x2c1e50 add sp, sp, #12 */
/* @0x2c1e54 pop {r4, r5, pc} */
/* @0x2c1e58 mov r2, #4 */
/* @0x2c1e5c mov r3, #1 */
/* @0x2c1e60 str r2, [r5] */
/* @0x2c1e64 b 0x2c1e34 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x7c> */
/* @0x2c1e68 mov r2, #3 */
/* @0x2c1e6c mov r3, #1 */
/* @0x2c1e70 str r2, [r5] */
/* @0x2c1e74 b 0x2c1e34 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x7c> */
/* @0x2c1e78 mov r2, #2 */
/* @0x2c1e7c mov r3, #1 */
/* @0x2c1e80 str r2, [r5] */
/* @0x2c1e84 b 0x2c1e34 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x7c> */
/* @0x2c1e88 mov r1, #1 */
/* @0x2c1e8c ldr r3, [r2, #0x38] */
/* @0x2c1e90 add r0, sp, #7 */
/* @0x2c1e94 mov r2, r1 */
/* @0x2c1e98 bl 0xb68c8 <fread@plt> */
/* @0x2c1e9c subs r0, r0, #1 */
/* @0x2c1ea0 movne r0, #1 */
/* @0x2c1ea4 b 0x2c1e00 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x48> */

/* ── FUNC 0x2c1ea8 · DGifGetImageDesc(GifFileType*) · size=968 · insn=242 */
/* @0x2c1ea8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c1eac mov r4, r0 */
/* @0x2c1eb0 ldr r5, [r0, #0x48] */
/* @0x2c1eb4 sub sp, sp, #12 */
/* @0x2c1eb8 ldr r3, [r5] */
/* @0x2c1ebc ands r3, r3, #8 */
/* @0x2c1ec0 moveq r2, #111 */
/* @0x2c1ec4 streq r2, [r0, #0x40] */
/* @0x2c1ec8 bne 0x2c1ed8 <_Z16DGifGetImageDescP11GifFileType+0x30> */
/* @0x2c1ecc mov r0, r3 */
/* @0x2c1ed0 add sp, sp, #12 */
/* @0x2c1ed4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c1ed8 add r6, r0, #28 */
/* @0x2c1edc mov r1, r6 */
/* @0x2c1ee0 bl 0x2c143c <jpeg_mem_term+0x4> */
/* @0x2c1ee4 cmp r0, #0 */
/* @0x2c1ee8 bne 0x2c1efc <_Z16DGifGetImageDescP11GifFileType+0x54> */
/* @0x2c1eec mov r3, #0 */
/* @0x2c1ef0 mov r0, r3 */
/* @0x2c1ef4 add sp, sp, #12 */
/* @0x2c1ef8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c1efc mov r0, r4 */
/* @0x2c1f00 add r1, r4, #32 */
/* @0x2c1f04 bl 0x2c143c <jpeg_mem_term+0x4> */
/* @0x2c1f08 cmp r0, #0 */
/* @0x2c1f0c beq 0x2c1eec <_Z16DGifGetImageDescP11GifFileType+0x44> */
/* @0x2c1f10 mov r0, r4 */
/* @0x2c1f14 add r1, r4, #36 */
/* @0x2c1f18 bl 0x2c143c <jpeg_mem_term+0x4> */
/* @0x2c1f1c cmp r0, #0 */
/* @0x2c1f20 beq 0x2c1eec <_Z16DGifGetImageDescP11GifFileType+0x44> */
/* @0x2c1f24 mov r0, r4 */
/* @0x2c1f28 add r1, r4, #40 */
/* @0x2c1f2c bl 0x2c143c <jpeg_mem_term+0x4> */
/* @0x2c1f30 cmp r0, #0 */
/* @0x2c1f34 beq 0x2c1eec <_Z16DGifGetImageDescP11GifFileType+0x44> */
/* @0x2c1f38 ldr r2, [r4, #0x48] */
/* @0x2c1f3c ldr r3, [r2, #0x3c] */
/* @0x2c1f40 cmp r3, #0 */
/* @0x2c1f44 beq 0x2c2118 <_Z16DGifGetImageDescP11GifFileType+0x270> */
/* @0x2c1f48 add r8, sp, #4 */
/* @0x2c1f4c mov r0, r4 */
/* @0x2c1f50 mov r2, #1 */
/* @0x2c1f54 mov r1, r8 */
/* @0x2c1f58 blx r3 */
/* @0x2c1f5c subs r7, r0, #1 */
/* @0x2c1f60 movne r7, #1 */
/* @0x2c1f64 cmp r7, #0 */
/* @0x2c1f68 bne 0x2c20f8 <_Z16DGifGetImageDescP11GifFileType+0x250> */
/* @0x2c1f6c ldr r0, [r4, #0x30] */
/* @0x2c1f70 ldrb r9, [sp, #0x4] */
/* @0x2c1f74 cmp r0, #0 */
/* @0x2c1f78 ubfx r3, r9, #0x6, #0x1 */
/* @0x2c1f7c strb r3, [r4, #0x2c] */
/* @0x2c1f80 moveq r3, r9 */
/* @0x2c1f84 beq 0x2c1f94 <_Z16DGifGetImageDescP11GifFileType+0xec> */
/* @0x2c1f88 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c1f8c ldrb r3, [sp, #0x4] */
/* @0x2c1f90 str r7, [r4, #0x30] */
/* @0x2c1f94 tst r3, #128 */
/* @0x2c1f98 bne 0x2c2160 <_Z16DGifGetImageDescP11GifFileType+0x2b8> */
/* @0x2c1f9c ldr r0, [r4, #0x34] */
/* @0x2c1fa0 cmp r0, #0 */
/* @0x2c1fa4 beq 0x2c213c <_Z16DGifGetImageDescP11GifFileType+0x294> */
/* @0x2c1fa8 ldr r3, [r4, #0x18] */
/* @0x2c1fac add r3, r3, #1 */
/* @0x2c1fb0 add r1, r3, r3, lsl #3 */
/* @0x2c1fb4 lsl r1, r1, #2 */
/* @0x2c1fb8 bl 0xb6c28 <realloc@plt> */
/* @0x2c1fbc cmp r0, #0 */
/* @0x2c1fc0 str r0, [r4, #0x34] */
/* @0x2c1fc4 beq 0x2c2150 <_Z16DGifGetImageDescP11GifFileType+0x2a8> */
/* @0x2c1fc8 ldr r12, [r4, #0x18] */
/* @0x2c1fcc ldr r1, [r6] */
/* @0x2c1fd0 ldr r2, [r6, #0x4] */
/* @0x2c1fd4 add r12, r12, r12, lsl #3 */
/* @0x2c1fd8 ldr r3, [r6, #0xc] */
/* @0x2c1fdc ldr lr, [r6, #0x8] */
/* @0x2c1fe0 lsl r12, r12, #2 */
/* @0x2c1fe4 add r7, r0, r12 */
/* @0x2c1fe8 str r1, [r0, r12] */
/* @0x2c1fec str r2, [r7, #0x4] */
/* @0x2c1ff0 str lr, [r7, #0x8] */
/* @0x2c1ff4 str r3, [r7, #0xc] */
/* @0x2c1ff8 ldr r1, [r6, #0x10] */
/* @0x2c1ffc ldr r2, [r6, #0x14] */
/* @0x2c2000 str r1, [r7, #0x10] */
/* @0x2c2004 str r2, [r7, #0x14] */
/* @0x2c2008 ldr r3, [r4, #0x30] */
/* @0x2c200c cmp r3, #0 */
/* @0x2c2010 beq 0x2c202c <_Z16DGifGetImageDescP11GifFileType+0x184> */
/* @0x2c2014 ldr r0, [r3] */
/* @0x2c2018 ldr r1, [r3, #0xc] */
/* @0x2c201c bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType> */
/* @0x2c2020 cmp r0, #0 */
/* @0x2c2024 str r0, [r7, #0x14] */
/* @0x2c2028 beq 0x2c2150 <_Z16DGifGetImageDescP11GifFileType+0x2a8> */
/* @0x2c202c ldr r2, [r4, #0x24] */
/* @0x2c2030 mov r3, #0 */
/* @0x2c2034 ldr r0, [r4, #0x28] */
/* @0x2c2038 ldr r6, [r4, #0x48] */
/* @0x2c203c ldr r1, [r4, #0x18] */
/* @0x2c2040 mul r2, r0, r2 */
/* @0x2c2044 ldr r12, [r6, #0x3c] */
/* @0x2c2048 add r1, r1, #1 */
/* @0x2c204c str r3, [r7, #0x18] */
/* @0x2c2050 cmp r12, r3 */
/* @0x2c2054 str r3, [r7, #0x1c] */
/* @0x2c2058 str r3, [r7, #0x20] */
/* @0x2c205c str r1, [r4, #0x18] */
/* @0x2c2060 str r2, [r5, #0x34] */
/* @0x2c2064 beq 0x2c2238 <_Z16DGifGetImageDescP11GifFileType+0x390> */
/* @0x2c2068 mov r0, r4 */
/* @0x2c206c add r1, sp, #3 */
/* @0x2c2070 mov r2, #1 */
/* @0x2c2074 blx r12 */
/* @0x2c2078 ldrb r4, [sp, #0x3] */
/* @0x2c207c add r2, r6, #8512 */
/* @0x2c2080 mov r0, #0 */
/* @0x2c2084 mov r8, #1 */
/* @0x2c2088 movw r5, #0x1002 */
/* @0x2c208c add r2, r2, #4 */
/* @0x2c2090 lsl r12, r8, r4 */
/* @0x2c2094 add r7, r4, r8 */
/* @0x2c2098 mov r3, r0 */
/* @0x2c209c mov r1, r5 */
/* @0x2c20a0 str r4, [r6, #0x8] */
/* @0x2c20a4 lsl r8, r8, r7 */
/* @0x2c20a8 add r4, r12, #1 */
/* @0x2c20ac str r12, [r6, #0xc] */
/* @0x2c20b0 str r8, [r6, #0x1c] */
/* @0x2c20b4 add r12, r12, #2 */
/* @0x2c20b8 str r7, [r6, #0x18] */
/* @0x2c20bc str r4, [r6, #0x10] */
/* @0x2c20c0 str r12, [r6, #0x14] */
/* @0x2c20c4 strb r0, [r6, #0x44] */
/* @0x2c20c8 str r0, [r6, #0x28] */
/* @0x2c20cc str r0, [r6, #0x2c] */
/* @0x2c20d0 str r0, [r6, #0x30] */
/* @0x2c20d4 str r5, [r6, #0x20] */
/* @0x2c20d8 str r1, [r2, r3] */
/* @0x2c20dc add r3, r3, #4 */
/* @0x2c20e0 cmp r3, #16384 */
/* @0x2c20e4 bne 0x2c20d8 <_Z16DGifGetImageDescP11GifFileType+0x230> */
/* @0x2c20e8 mov r3, #1 */
/* @0x2c20ec mov r0, r3 */
/* @0x2c20f0 add sp, sp, #12 */
/* @0x2c20f4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c20f8 mov r3, #102 */
/* @0x2c20fc ldr r0, [r4, #0x30] */
/* @0x2c2100 str r3, [r4, #0x40] */
/* @0x2c2104 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c2108 mov r2, #0 */
/* @0x2c210c mov r3, r2 */
/* @0x2c2110 str r2, [r4, #0x30] */
/* @0x2c2114 b 0x2c1ecc <_Z16DGifGetImageDescP11GifFileType+0x24> */
/* @0x2c2118 add r8, sp, #4 */
/* @0x2c211c mov r1, #1 */
/* @0x2c2120 ldr r3, [r2, #0x38] */
/* @0x2c2124 mov r2, r1 */
/* @0x2c2128 mov r0, r8 */
/* @0x2c212c bl 0xb68c8 <fread@plt> */
/* @0x2c2130 subs r7, r0, #1 */
/* @0x2c2134 movne r7, #1 */
/* @0x2c2138 b 0x2c1f64 <_Z16DGifGetImageDescP11GifFileType+0xbc> */
/* @0x2c213c mov r0, #36 */
/* @0x2c2140 bl 0xb6544 <malloc@plt> */
/* @0x2c2144 cmp r0, #0 */
/* @0x2c2148 str r0, [r4, #0x34] */
/* @0x2c214c bne 0x2c1fc8 <_Z16DGifGetImageDescP11GifFileType+0x120> */
/* @0x2c2150 mov r2, #109 */
/* @0x2c2154 mov r3, r0 */
/* @0x2c2158 str r2, [r4, #0x40] */
/* @0x2c215c b 0x2c1ecc <_Z16DGifGetImageDescP11GifFileType+0x24> */
/* @0x2c2160 and r3, r9, #7 */
/* @0x2c2164 mov r0, #1 */
/* @0x2c2168 add r3, r3, r0 */
/* @0x2c216c mov r1, #0 */
/* @0x2c2170 lsl r0, r0, r3 */
/* @0x2c2174 bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType> */
/* @0x2c2178 cmp r0, #0 */
/* @0x2c217c str r0, [r4, #0x30] */
/* @0x2c2180 beq 0x2c2150 <_Z16DGifGetImageDescP11GifFileType+0x2a8> */
/* @0x2c2184 ldr r3, [r0] */
/* @0x2c2188 cmp r3, #0 */
/* @0x2c218c movgt r7, #0 */
/* @0x2c2190 bgt 0x2c21fc <_Z16DGifGetImageDescP11GifFileType+0x354> */
/* @0x2c2194 b 0x2c1f9c <_Z16DGifGetImageDescP11GifFileType+0xf4> */
/* @0x2c2198 blx r3 */
/* @0x2c219c subs r0, r0, #3 */
/* @0x2c21a0 movne r0, #1 */
/* @0x2c21a4 cmp r0, #0 */
/* @0x2c21a8 add r3, r7, r7, lsl #1 */
/* @0x2c21ac add r7, r7, #1 */
/* @0x2c21b0 bne 0x2c2250 <_Z16DGifGetImageDescP11GifFileType+0x3a8> */
/* @0x2c21b4 ldr r2, [r4, #0x30] */
/* @0x2c21b8 ldrb r1, [sp, #0x4] */
/* @0x2c21bc ldr r2, [r2, #0xc] */
/* @0x2c21c0 strb r1, [r2, r3] */
/* @0x2c21c4 ldr r2, [r4, #0x30] */
/* @0x2c21c8 ldrb r1, [sp, #0x5] */
/* @0x2c21cc ldr r2, [r2, #0xc] */
/* @0x2c21d0 add r2, r2, r3 */
/* @0x2c21d4 strb r1, [r2, #0x1] */
/* @0x2c21d8 ldr r1, [r4, #0x30] */
/* @0x2c21dc ldrb r2, [sp, #0x6] */
/* @0x2c21e0 ldr r1, [r1, #0xc] */
/* @0x2c21e4 add r3, r1, r3 */
/* @0x2c21e8 strb r2, [r3, #0x2] */
/* @0x2c21ec ldr r3, [r4, #0x30] */
/* @0x2c21f0 ldr r3, [r3] */
/* @0x2c21f4 cmp r3, r7 */
/* @0x2c21f8 ble 0x2c1f9c <_Z16DGifGetImageDescP11GifFileType+0xf4> */
/* @0x2c21fc ldr r12, [r4, #0x48] */
/* @0x2c2200 mov r0, r4 */
/* @0x2c2204 mov r1, r8 */
/* @0x2c2208 mov r2, #3 */
/* @0x2c220c ldr r3, [r12, #0x3c] */
/* @0x2c2210 cmp r3, #0 */
/* @0x2c2214 bne 0x2c2198 <_Z16DGifGetImageDescP11GifFileType+0x2f0> */
/* @0x2c2218 ldr r3, [r12, #0x38] */
/* @0x2c221c mov r0, r8 */
/* @0x2c2220 mov r1, #1 */
/* @0x2c2224 mov r2, #3 */
/* @0x2c2228 bl 0xb68c8 <fread@plt> */
/* @0x2c222c subs r0, r0, #3 */
/* @0x2c2230 movne r0, #1 */
/* @0x2c2234 b 0x2c21a4 <_Z16DGifGetImageDescP11GifFileType+0x2fc> */
/* @0x2c2238 mov r1, #1 */
/* @0x2c223c add r0, sp, #3 */
/* @0x2c2240 mov r2, r1 */
/* @0x2c2244 ldr r3, [r6, #0x38] */
/* @0x2c2248 bl 0xb68c8 <fread@plt> */
/* @0x2c224c b 0x2c2078 <_Z16DGifGetImageDescP11GifFileType+0x1d0> */
/* @0x2c2250 ldr r0, [r4, #0x30] */
/* @0x2c2254 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c2258 mov r2, #0 */
/* @0x2c225c mov r3, r2 */
/* @0x2c2260 str r2, [r4, #0x30] */
/* @0x2c2264 mov r2, #102 */
/* @0x2c2268 str r2, [r4, #0x40] */
/* @0x2c226c b 0x2c1ecc <_Z16DGifGetImageDescP11GifFileType+0x24> */

/* ── FUNC 0x2c2270 · DGifGetExtensionNext(GifFileType*, unsigned char**) · size=216 · insn=54 */
/* @0x2c2270 push {r4, r5, r6, lr} */
/* @0x2c2274 mov r4, r0 */
/* @0x2c2278 ldr r5, [r0, #0x48] */
/* @0x2c227c sub sp, sp, #8 */
/* @0x2c2280 mov r6, r1 */
/* @0x2c2284 ldr r3, [r5, #0x3c] */
/* @0x2c2288 cmp r3, #0 */
/* @0x2c228c beq 0x2c2310 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0xa0> */
/* @0x2c2290 add r1, sp, #7 */
/* @0x2c2294 mov r2, #1 */
/* @0x2c2298 blx r3 */
/* @0x2c229c subs r0, r0, #1 */
/* @0x2c22a0 movne r0, #1 */
/* @0x2c22a4 cmp r0, #0 */
/* @0x2c22a8 bne 0x2c22fc <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x8c> */
/* @0x2c22ac ldrb r2, [sp, #0x7] */
/* @0x2c22b0 cmp r2, #0 */
/* @0x2c22b4 streq r0, [r6] */
/* @0x2c22b8 moveq r0, #1 */
/* @0x2c22bc beq 0x2c2308 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x98> */
/* @0x2c22c0 add r3, r5, #68 */
/* @0x2c22c4 str r3, [r6] */
/* @0x2c22c8 strb r2, [r5, #0x44] */
/* @0x2c22cc ldr r1, [r4, #0x48] */
/* @0x2c22d0 ldr r3, [r1, #0x3c] */
/* @0x2c22d4 cmp r3, #0 */
/* @0x2c22d8 beq 0x2c2330 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0xc0> */
/* @0x2c22dc ldr r1, [r6] */
/* @0x2c22e0 mov r0, r4 */
/* @0x2c22e4 add r1, r1, #1 */
/* @0x2c22e8 blx r3 */
/* @0x2c22ec ldrb r3, [sp, #0x7] */
/* @0x2c22f0 cmp r0, r3 */
/* @0x2c22f4 moveq r0, #1 */
/* @0x2c22f8 beq 0x2c2308 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x98> */
/* @0x2c22fc mov r0, #0 */
/* @0x2c2300 mov r3, #102 */
/* @0x2c2304 str r3, [r4, #0x40] */
/* @0x2c2308 add sp, sp, #8 */
/* @0x2c230c pop {r4, r5, r6, pc} */
/* @0x2c2310 mov r1, #1 */
/* @0x2c2314 add r0, sp, #7 */
/* @0x2c2318 mov r2, r1 */
/* @0x2c231c ldr r3, [r5, #0x38] */
/* @0x2c2320 bl 0xb68c8 <fread@plt> */
/* @0x2c2324 subs r0, r0, #1 */
/* @0x2c2328 movne r0, #1 */
/* @0x2c232c b 0x2c22a4 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x34> */
/* @0x2c2330 ldr r0, [r6] */
/* @0x2c2334 ldr r3, [r1, #0x38] */
/* @0x2c2338 mov r1, #1 */
/* @0x2c233c add r0, r0, r1 */
/* @0x2c2340 bl 0xb68c8 <fread@plt> */
/* @0x2c2344 b 0x2c22ec <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x7c> */

/* ── FUNC 0x2c2348 · DGifGetExtension(GifFileType*, int*, unsigned char**) · size=176 · insn=44 */
/* @0x2c2348 ldr r12, [r0, #0x48] */
/* @0x2c234c push {r4, r5, r6, lr} */
/* @0x2c2350 mov r6, r2 */
/* @0x2c2354 ldr r3, [r12] */
/* @0x2c2358 sub sp, sp, #8 */
/* @0x2c235c mov r4, r0 */
/* @0x2c2360 mov r5, r1 */
/* @0x2c2364 ands r3, r3, #8 */
/* @0x2c2368 moveq r2, #111 */
/* @0x2c236c streq r2, [r0, #0x40] */
/* @0x2c2370 beq 0x2c23a8 <_Z16DGifGetExtensionP11GifFileTypePiPPh+0x60> */
/* @0x2c2374 ldr r3, [r12, #0x3c] */
/* @0x2c2378 cmp r3, #0 */
/* @0x2c237c beq 0x2c23d8 <_Z16DGifGetExtensionP11GifFileTypePiPPh+0x90> */
/* @0x2c2380 add r1, sp, #7 */
/* @0x2c2384 mov r2, #1 */
/* @0x2c2388 blx r3 */
/* @0x2c238c subs r0, r0, #1 */
/* @0x2c2390 movne r0, #1 */
/* @0x2c2394 cmp r0, #0 */
/* @0x2c2398 beq 0x2c23b4 <_Z16DGifGetExtensionP11GifFileTypePiPPh+0x6c> */
/* @0x2c239c mov r3, #0 */
/* @0x2c23a0 mov r2, #102 */
/* @0x2c23a4 str r2, [r4, #0x40] */
/* @0x2c23a8 mov r0, r3 */
/* @0x2c23ac add sp, sp, #8 */
/* @0x2c23b0 pop {r4, r5, r6, pc} */
/* @0x2c23b4 ldrb r3, [sp, #0x7] */
/* @0x2c23b8 mov r0, r4 */
/* @0x2c23bc mov r1, r6 */
/* @0x2c23c0 str r3, [r5] */
/* @0x2c23c4 bl 0x2c2270 <_Z20DGifGetExtensionNextP11GifFileTypePPh> */
/* @0x2c23c8 mov r3, r0 */
/* @0x2c23cc mov r0, r3 */
/* @0x2c23d0 add sp, sp, #8 */
/* @0x2c23d4 pop {r4, r5, r6, pc} */
/* @0x2c23d8 mov r1, #1 */
/* @0x2c23dc ldr r3, [r12, #0x38] */
/* @0x2c23e0 mov r2, r1 */
/* @0x2c23e4 add r0, sp, #7 */
/* @0x2c23e8 bl 0xb68c8 <fread@plt> */
/* @0x2c23ec subs r0, r0, #1 */
/* @0x2c23f0 movne r0, #1 */
/* @0x2c23f4 b 0x2c2394 <_Z16DGifGetExtensionP11GifFileTypePiPPh+0x4c> */

/* ── FUNC 0x2c23f8 · DGifExtensionToGCB(unsigned int, unsigned char const*, GraphicsControlBlock*) · size=84 · insn=21 */
/* @0x2c23f8 cmp r0, #4 */
/* @0x2c23fc beq 0x2c2408 <_Z18DGifExtensionToGCBjPKhP20GraphicsControlBlock+0x10> */
/* @0x2c2400 mov r0, #0 */
/* @0x2c2404 bx lr */
/* @0x2c2408 ldrb r3, [r1] */
/* @0x2c240c ubfx r3, r3, #0x2, #0x3 */
/* @0x2c2410 str r3, [r2] */
/* @0x2c2414 ldrb r3, [r1] */
/* @0x2c2418 ubfx r3, r3, #0x1, #0x1 */
/* @0x2c241c strb r3, [r2, #0x4] */
/* @0x2c2420 ldrb r0, [r1, #0x2] */
/* @0x2c2424 ldrb r3, [r1, #0x1] */
/* @0x2c2428 orr r3, r3, r0, lsl #8 */
/* @0x2c242c str r3, [r2, #0x8] */
/* @0x2c2430 ldrb r3, [r1] */
/* @0x2c2434 mov r0, #1 */
/* @0x2c2438 tst r3, #1 */
/* @0x2c243c ldrbne r3, [r1, #0x3] */
/* @0x2c2440 mvneq r3, #0 */
/* @0x2c2444 str r3, [r2, #0xc] */
/* @0x2c2448 bx lr */

/* ── FUNC 0x2c244c · DGifSavedExtensionToGCB(GifFileType*, int, GraphicsControlBlock*) · size=152 · insn=38 */
/* @0x2c244c cmp r1, #0 */
/* @0x2c2450 str r4, [sp, #-0x4]! */
/* @0x2c2454 blt 0x2c24cc <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x80> */
/* @0x2c2458 ldr r3, [r0, #0x18] */
/* @0x2c245c cmp r1, r3 */
/* @0x2c2460 bge 0x2c24cc <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x80> */
/* @0x2c2464 ldr r3, [r0, #0x34] */
/* @0x2c2468 add r12, r1, r1, lsl #3 */
/* @0x2c246c mov r1, #0 */
/* @0x2c2470 mvn r0, #0 */
/* @0x2c2474 add r3, r3, r12, lsl #2 */
/* @0x2c2478 str r1, [r2] */
/* @0x2c247c strb r1, [r2, #0x4] */
/* @0x2c2480 ldr r4, [r3, #0x1c] */
/* @0x2c2484 str r1, [r2, #0x8] */
/* @0x2c2488 cmp r4, r1 */
/* @0x2c248c str r0, [r2, #0xc] */
/* @0x2c2490 ble 0x2c24cc <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x80> */
/* @0x2c2494 ldr r12, [r3, #0x20] */
/* @0x2c2498 ldr r3, [r12, #0x8] */
/* @0x2c249c cmp r3, #249 */
/* @0x2c24a0 addne r3, r12, #12 */
/* @0x2c24a4 bne 0x2c24b8 <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x6c> */
/* @0x2c24a8 b 0x2c24d8 <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x8c> */
/* @0x2c24ac ldr r0, [r3, #-0x4] */
/* @0x2c24b0 cmp r0, #249 */
/* @0x2c24b4 beq 0x2c24d8 <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x8c> */
/* @0x2c24b8 add r1, r1, #1 */
/* @0x2c24bc mov r12, r3 */
/* @0x2c24c0 cmp r1, r4 */
/* @0x2c24c4 add r3, r3, #12 */
/* @0x2c24c8 bne 0x2c24ac <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x60> */
/* @0x2c24cc mov r0, #0 */
/* @0x2c24d0 ldr r4, [sp], #4 */
/* @0x2c24d4 bx lr */
/* @0x2c24d8 ldm r12, {r0, r1} */
/* @0x2c24dc ldr r4, [sp], #4 */
/* @0x2c24e0 b 0x2c23f8 <_Z18DGifExtensionToGCBjPKhP20GraphicsControlBlock> */

/* ── FUNC 0x2c24e4 · DGifCloseFile(GifFileType*) · size=220 · insn=55 */
/* @0x2c24e4 push {r4, lr} */
/* @0x2c24e8 subs r4, r0, #0 */
/* @0x2c24ec beq 0x2c25b8 <_Z13DGifCloseFileP11GifFileType+0xd4> */
/* @0x2c24f0 ldr r0, [r4, #0x48] */
/* @0x2c24f4 cmp r0, #0 */
/* @0x2c24f8 popeq {r4, pc} */
/* @0x2c24fc ldr r0, [r4, #0x30] */
/* @0x2c2500 cmp r0, #0 */
/* @0x2c2504 beq 0x2c2514 <_Z13DGifCloseFileP11GifFileType+0x30> */
/* @0x2c2508 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c250c mov r3, #0 */
/* @0x2c2510 str r3, [r4, #0x30] */
/* @0x2c2514 ldr r0, [r4, #0x14] */
/* @0x2c2518 cmp r0, #0 */
/* @0x2c251c beq 0x2c252c <_Z13DGifCloseFileP11GifFileType+0x48> */
/* @0x2c2520 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c2524 mov r3, #0 */
/* @0x2c2528 str r3, [r4, #0x14] */
/* @0x2c252c ldr r3, [r4, #0x34] */
/* @0x2c2530 cmp r3, #0 */
/* @0x2c2534 beq 0x2c2548 <_Z13DGifCloseFileP11GifFileType+0x64> */
/* @0x2c2538 mov r0, r4 */
/* @0x2c253c bl 0x2c3234 <_Z18GifFreeSavedImagesP11GifFileType> */
/* @0x2c2540 mov r3, #0 */
/* @0x2c2544 str r3, [r4, #0x34] */
/* @0x2c2548 add r0, r4, #56 */
/* @0x2c254c add r1, r4, #60 */
/* @0x2c2550 bl 0x2c2ff8 <_Z17GifFreeExtensionsPiPP14ExtensionBlock> */
/* @0x2c2554 ldr r3, [r4, #0x48] */
/* @0x2c2558 ldr r0, [r3] */
/* @0x2c255c ands r0, r0, #8 */
/* @0x2c2560 beq 0x2c2594 <_Z13DGifCloseFileP11GifFileType+0xb0> */
/* @0x2c2564 ldr r0, [r3, #0x38] */
/* @0x2c2568 cmp r0, #0 */
/* @0x2c256c beq 0x2c25b0 <_Z13DGifCloseFileP11GifFileType+0xcc> */
/* @0x2c2570 bl 0xb6850 <fclose@plt> */
/* @0x2c2574 cmp r0, #0 */
/* @0x2c2578 bne 0x2c25a0 <_Z13DGifCloseFileP11GifFileType+0xbc> */
/* @0x2c257c ldr r0, [r4, #0x48] */
/* @0x2c2580 bl 0xb655c <free@plt> */
/* @0x2c2584 mov r0, r4 */
/* @0x2c2588 bl 0xb655c <free@plt> */
/* @0x2c258c mov r0, #1 */
/* @0x2c2590 pop {r4, pc} */
/* @0x2c2594 mov r3, #111 */
/* @0x2c2598 str r3, [r4, #0x40] */
/* @0x2c259c pop {r4, pc} */
/* @0x2c25a0 mov r3, #110 */
/* @0x2c25a4 mov r0, #0 */
/* @0x2c25a8 str r3, [r4, #0x40] */
/* @0x2c25ac pop {r4, pc} */
/* @0x2c25b0 mov r0, r3 */
/* @0x2c25b4 b 0x2c2580 <_Z13DGifCloseFileP11GifFileType+0x9c> */
/* @0x2c25b8 mov r0, r4 */
/* @0x2c25bc pop {r4, pc} */

/* ── FUNC 0x2c25c0 · DGifGetCodeNext(GifFileType*, unsigned char**) · size=232 · insn=58 */
/* @0x2c25c0 push {r4, r5, r6, lr} */
/* @0x2c25c4 mov r5, r0 */
/* @0x2c25c8 ldr r4, [r0, #0x48] */
/* @0x2c25cc sub sp, sp, #8 */
/* @0x2c25d0 mov r6, r1 */
/* @0x2c25d4 ldr r3, [r4, #0x3c] */
/* @0x2c25d8 cmp r3, #0 */
/* @0x2c25dc beq 0x2c2670 <_Z15DGifGetCodeNextP11GifFileTypePPh+0xb0> */
/* @0x2c25e0 add r1, sp, #7 */
/* @0x2c25e4 mov r2, #1 */
/* @0x2c25e8 blx r3 */
/* @0x2c25ec subs r3, r0, #1 */
/* @0x2c25f0 movne r3, #1 */
/* @0x2c25f4 cmp r3, #0 */
/* @0x2c25f8 bne 0x2c2644 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x84> */
/* @0x2c25fc ldrb r2, [sp, #0x7] */
/* @0x2c2600 cmp r2, #0 */
/* @0x2c2604 beq 0x2c2658 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x98> */
/* @0x2c2608 add r3, r4, #68 */
/* @0x2c260c str r3, [r6] */
/* @0x2c2610 strb r2, [r4, #0x44] */
/* @0x2c2614 ldr r1, [r5, #0x48] */
/* @0x2c2618 ldr r3, [r1, #0x3c] */
/* @0x2c261c cmp r3, #0 */
/* @0x2c2620 beq 0x2c2690 <_Z15DGifGetCodeNextP11GifFileTypePPh+0xd0> */
/* @0x2c2624 ldr r1, [r6] */
/* @0x2c2628 mov r0, r5 */
/* @0x2c262c add r1, r1, #1 */
/* @0x2c2630 blx r3 */
/* @0x2c2634 ldrb r3, [sp, #0x7] */
/* @0x2c2638 cmp r0, r3 */
/* @0x2c263c moveq r0, #1 */
/* @0x2c2640 beq 0x2c2650 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x90> */
/* @0x2c2644 mov r0, #0 */
/* @0x2c2648 mov r3, #102 */
/* @0x2c264c str r3, [r5, #0x40] */
/* @0x2c2650 add sp, sp, #8 */
/* @0x2c2654 pop {r4, r5, r6, pc} */
/* @0x2c2658 str r3, [r6] */
/* @0x2c265c mov r0, #1 */
/* @0x2c2660 strb r3, [r4, #0x44] */
/* @0x2c2664 str r3, [r4, #0x34] */
/* @0x2c2668 add sp, sp, #8 */
/* @0x2c266c pop {r4, r5, r6, pc} */
/* @0x2c2670 mov r1, #1 */
/* @0x2c2674 ldr r3, [r4, #0x38] */
/* @0x2c2678 add r0, sp, #7 */
/* @0x2c267c mov r2, r1 */
/* @0x2c2680 bl 0xb68c8 <fread@plt> */
/* @0x2c2684 subs r3, r0, #1 */
/* @0x2c2688 movne r3, #1 */
/* @0x2c268c b 0x2c25f4 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x34> */
/* @0x2c2690 ldr r0, [r6] */
/* @0x2c2694 ldr r3, [r1, #0x38] */
/* @0x2c2698 mov r1, #1 */
/* @0x2c269c add r0, r0, r1 */
/* @0x2c26a0 bl 0xb68c8 <fread@plt> */
/* @0x2c26a4 b 0x2c2634 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x74> */

/* ── FUNC 0x2c26a8 · DGifGetLine(GifFileType*, unsigned char*, int) · size=168 · insn=42 */
/* @0x2c26a8 push {r4, r5, lr} */
/* @0x2c26ac mov r4, r0 */
/* @0x2c26b0 ldr r5, [r0, #0x48] */
/* @0x2c26b4 sub sp, sp, #12 */
/* @0x2c26b8 ldr r0, [r5] */
/* @0x2c26bc ands r0, r0, #8 */
/* @0x2c26c0 moveq r3, #111 */
/* @0x2c26c4 streq r3, [r4, #0x40] */
/* @0x2c26c8 beq 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c> */
/* @0x2c26cc cmp r2, #0 */
/* @0x2c26d0 ldr r3, [r5, #0x34] */
/* @0x2c26d4 ldreq r2, [r4, #0x24] */
/* @0x2c26d8 rsb r3, r2, r3 */
/* @0x2c26dc str r3, [r5, #0x34] */
/* @0x2c26e0 cmn r3, #65536 */
/* @0x2c26e4 bls 0x2c26fc <_Z11DGifGetLineP11GifFileTypePhi+0x54> */
/* @0x2c26e8 mov r0, #0 */
/* @0x2c26ec mov r3, #108 */
/* @0x2c26f0 str r3, [r4, #0x40] */
/* @0x2c26f4 add sp, sp, #12 */
/* @0x2c26f8 pop {r4, r5, pc} */
/* @0x2c26fc mov r0, r4 */
/* @0x2c2700 bl 0x2c1698 <jpeg_mem_term+0x260> */
/* @0x2c2704 cmp r0, #1 */
/* @0x2c2708 movne r0, #0 */
/* @0x2c270c bne 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c> */
/* @0x2c2710 ldr r3, [r5, #0x34] */
/* @0x2c2714 cmp r3, #0 */
/* @0x2c2718 bne 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c> */
/* @0x2c271c add r5, sp, #4 */
/* @0x2c2720 b 0x2c2730 <_Z11DGifGetLineP11GifFileTypePhi+0x88> */
/* @0x2c2724 ldr r3, [sp, #0x4] */
/* @0x2c2728 cmp r3, #0 */
/* @0x2c272c beq 0x2c2748 <_Z11DGifGetLineP11GifFileTypePhi+0xa0> */
/* @0x2c2730 mov r0, r4 */
/* @0x2c2734 mov r1, r5 */
/* @0x2c2738 bl 0x2c25c0 <_Z15DGifGetCodeNextP11GifFileTypePPh> */
/* @0x2c273c cmp r0, #0 */
/* @0x2c2740 bne 0x2c2724 <_Z11DGifGetLineP11GifFileTypePhi+0x7c> */
/* @0x2c2744 b 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c> */
/* @0x2c2748 mov r0, #1 */
/* @0x2c274c b 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c> */

/* ── FUNC 0x2c2750 · DGifGetPixel(GifFileType*, unsigned char) · size=180 · insn=45 */
/* @0x2c2750 push {r4, r5, r6, lr} */
/* @0x2c2754 sub sp, sp, #16 */
/* @0x2c2758 ldr r5, [r0, #0x48] */
/* @0x2c275c mov r4, r0 */
/* @0x2c2760 strb r1, [sp, #0x7] */
/* @0x2c2764 ldr r6, [r5] */
/* @0x2c2768 ands r6, r6, #8 */
/* @0x2c276c moveq r3, #111 */
/* @0x2c2770 streq r3, [r0, #0x40] */
/* @0x2c2774 beq 0x2c2798 <_Z12DGifGetPixelP11GifFileTypeh+0x48> */
/* @0x2c2778 ldr r3, [r5, #0x34] */
/* @0x2c277c sub r3, r3, #1 */
/* @0x2c2780 str r3, [r5, #0x34] */
/* @0x2c2784 cmn r3, #65536 */
/* @0x2c2788 bls 0x2c27a4 <_Z12DGifGetPixelP11GifFileTypeh+0x54> */
/* @0x2c278c mov r6, #0 */
/* @0x2c2790 mov r3, #108 */
/* @0x2c2794 str r3, [r0, #0x40] */
/* @0x2c2798 mov r0, r6 */
/* @0x2c279c add sp, sp, #16 */
/* @0x2c27a0 pop {r4, r5, r6, pc} */
/* @0x2c27a4 add r1, sp, #7 */
/* @0x2c27a8 mov r2, #1 */
/* @0x2c27ac bl 0x2c1698 <jpeg_mem_term+0x260> */
/* @0x2c27b0 cmp r0, #1 */
/* @0x2c27b4 mov r6, r0 */
/* @0x2c27b8 beq 0x2c27cc <_Z12DGifGetPixelP11GifFileTypeh+0x7c> */
/* @0x2c27bc mov r6, #0 */
/* @0x2c27c0 mov r0, r6 */
/* @0x2c27c4 add sp, sp, #16 */
/* @0x2c27c8 pop {r4, r5, r6, pc} */
/* @0x2c27cc ldr r3, [r5, #0x34] */
/* @0x2c27d0 cmp r3, #0 */
/* @0x2c27d4 bne 0x2c2798 <_Z12DGifGetPixelP11GifFileTypeh+0x48> */
/* @0x2c27d8 add r5, sp, #12 */
/* @0x2c27dc b 0x2c27ec <_Z12DGifGetPixelP11GifFileTypeh+0x9c> */
/* @0x2c27e0 ldr r3, [sp, #0xc] */
/* @0x2c27e4 cmp r3, #0 */
/* @0x2c27e8 beq 0x2c2798 <_Z12DGifGetPixelP11GifFileTypeh+0x48> */
/* @0x2c27ec mov r0, r4 */
/* @0x2c27f0 mov r1, r5 */
/* @0x2c27f4 bl 0x2c25c0 <_Z15DGifGetCodeNextP11GifFileTypePPh> */
/* @0x2c27f8 cmp r0, #0 */
/* @0x2c27fc bne 0x2c27e0 <_Z12DGifGetPixelP11GifFileTypeh+0x90> */
/* @0x2c2800 b 0x2c27bc <_Z12DGifGetPixelP11GifFileTypeh+0x6c> */

/* ── FUNC 0x2c2804 · DGifGetCode(GifFileType*, int*, unsigned char**) · size=64 · insn=16 */
/* @0x2c2804 push {r4, r5} */
/* @0x2c2808 mov r5, r1 */
/* @0x2c280c ldr r4, [r0, #0x48] */
/* @0x2c2810 ldr r3, [r4] */
/* @0x2c2814 ands r3, r3, #8 */
/* @0x2c2818 bne 0x2c2830 <_Z11DGifGetCodeP11GifFileTypePiPPh+0x2c> */
/* @0x2c281c mov r2, #111 */
/* @0x2c2820 str r2, [r0, #0x40] */
/* @0x2c2824 pop {r4, r5} */
/* @0x2c2828 mov r0, r3 */
/* @0x2c282c bx lr */
/* @0x2c2830 ldr r3, [r4, #0x8] */
/* @0x2c2834 mov r1, r2 */
/* @0x2c2838 str r3, [r5] */
/* @0x2c283c pop {r4, r5} */
/* @0x2c2840 b 0x2c25c0 <_Z15DGifGetCodeNextP11GifFileTypePPh> */

/* ── FUNC 0x2c2844 · DGifGetLZCodes(GifFileType*, int*) · size=212 · insn=53 */
/* @0x2c2844 push {r4, r5, r6, lr} */
/* @0x2c2848 mov r4, r0 */
/* @0x2c284c ldr r5, [r0, #0x48] */
/* @0x2c2850 sub sp, sp, #8 */
/* @0x2c2854 mov r6, r1 */
/* @0x2c2858 ldr r3, [r5] */
/* @0x2c285c ands r3, r3, #8 */
/* @0x2c2860 moveq r2, #111 */
/* @0x2c2864 streq r2, [r0, #0x40] */
/* @0x2c2868 bne 0x2c2878 <_Z14DGifGetLZCodesP11GifFileTypePi+0x34> */
/* @0x2c286c mov r0, r3 */
/* @0x2c2870 add sp, sp, #8 */
/* @0x2c2874 pop {r4, r5, r6, pc} */
/* @0x2c2878 bl 0x2c14bc <jpeg_mem_term+0x84> */
/* @0x2c287c cmp r0, #0 */
/* @0x2c2880 beq 0x2c28f8 <_Z14DGifGetLZCodesP11GifFileTypePi+0xb4> */
/* @0x2c2884 ldr r3, [r6] */
/* @0x2c2888 ldr r2, [r5, #0x10] */
/* @0x2c288c cmp r3, r2 */
/* @0x2c2890 beq 0x2c28d0 <_Z14DGifGetLZCodesP11GifFileTypePi+0x8c> */
/* @0x2c2894 ldr r1, [r5, #0xc] */
/* @0x2c2898 cmp r3, r1 */
/* @0x2c289c ldreq r1, [r5, #0x8] */
/* @0x2c28a0 moveq r0, #1 */
/* @0x2c28a4 moveq r3, r0 */
/* @0x2c28a8 movne r3, #1 */
/* @0x2c28ac addeq r1, r1, r0 */
/* @0x2c28b0 addeq r2, r2, r0 */
/* @0x2c28b4 streq r1, [r5, #0x18] */
/* @0x2c28b8 lsleq r1, r0, r1 */
/* @0x2c28bc streq r2, [r5, #0x14] */
/* @0x2c28c0 mov r0, r3 */
/* @0x2c28c4 streq r1, [r5, #0x1c] */
/* @0x2c28c8 add sp, sp, #8 */
/* @0x2c28cc pop {r4, r5, r6, pc} */
/* @0x2c28d0 add r5, sp, #4 */
/* @0x2c28d4 b 0x2c28e4 <_Z14DGifGetLZCodesP11GifFileTypePi+0xa0> */
/* @0x2c28d8 ldr r3, [sp, #0x4] */
/* @0x2c28dc cmp r3, #0 */
/* @0x2c28e0 beq 0x2c2908 <_Z14DGifGetLZCodesP11GifFileTypePi+0xc4> */
/* @0x2c28e4 mov r0, r4 */
/* @0x2c28e8 mov r1, r5 */
/* @0x2c28ec bl 0x2c25c0 <_Z15DGifGetCodeNextP11GifFileTypePPh> */
/* @0x2c28f0 cmp r0, #0 */
/* @0x2c28f4 bne 0x2c28d8 <_Z14DGifGetLZCodesP11GifFileTypePi+0x94> */
/* @0x2c28f8 mov r3, #0 */
/* @0x2c28fc mov r0, r3 */
/* @0x2c2900 add sp, sp, #8 */
/* @0x2c2904 pop {r4, r5, r6, pc} */
/* @0x2c2908 mvn r2, #0 */
/* @0x2c290c mov r3, #1 */
/* @0x2c2910 str r2, [r6] */
/* @0x2c2914 b 0x2c286c <_Z14DGifGetLZCodesP11GifFileTypePi+0x28> */

/* ── FUNC 0x2c2918 · DGifSlurp(GifFileType*) · size=628 · insn=157 */
/* @0x2c2918 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c291c sub sp, sp, #76 */
/* @0x2c2920 ldr r2, [pc, #0x260] */
/* @0x2c2924 add r10, sp, #28 */
/* @0x2c2928 add r9, sp, #32 */
/* @0x2c292c mov r8, r0 */
/* @0x2c2930 mov r5, r0 */
/* @0x2c2934 add r2, pc, r2 */
/* @0x2c2938 mov r3, #0 */
/* @0x2c293c str r2, [sp, #0x10] */
/* @0x2c2940 str r3, [r0, #0x3c] */
/* @0x2c2944 add r2, sp, #36 */
/* @0x2c2948 str r3, [r8, #0x38]! */
/* @0x2c294c str r2, [sp, #0x14] */
/* @0x2c2950 str r8, [sp, #0xc] */
/* @0x2c2954 mov r0, r5 */
/* @0x2c2958 mov r1, r10 */
/* @0x2c295c bl 0x2c1db8 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType> */
/* @0x2c2960 cmp r0, #0 */
/* @0x2c2964 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4> */
/* @0x2c2968 ldr r3, [sp, #0x1c] */
/* @0x2c296c cmp r3, #2 */
/* @0x2c2970 beq 0x2c2a00 <_Z9DGifSlurpP11GifFileType+0xe8> */
/* @0x2c2974 cmp r3, #3 */
/* @0x2c2978 bne 0x2c29ec <_Z9DGifSlurpP11GifFileType+0xd4> */
/* @0x2c297c mov r0, r5 */
/* @0x2c2980 add r1, sp, #36 */
/* @0x2c2984 mov r2, r9 */
/* @0x2c2988 bl 0x2c2348 <_Z16DGifGetExtensionP11GifFileTypePiPPh> */
/* @0x2c298c cmp r0, #0 */
/* @0x2c2990 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4> */
/* @0x2c2994 ldr r12, [sp, #0x20] */
/* @0x2c2998 add r4, r5, #60 */
/* @0x2c299c ldr r2, [sp, #0x24] */
/* @0x2c29a0 ldr r0, [sp, #0xc] */
/* @0x2c29a4 mov r1, r4 */
/* @0x2c29a8 ldrb r3, [r12], #1 */
/* @0x2c29ac str r12, [sp] */
/* @0x2c29b0 bl 0x2c2f3c <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh> */
/* @0x2c29b4 cmp r0, #0 */
/* @0x2c29b8 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4> */
/* @0x2c29bc ldr r3, [sp, #0x20] */
/* @0x2c29c0 mov r1, r9 */
/* @0x2c29c4 mov r0, r5 */
/* @0x2c29c8 cmp r3, #0 */
/* @0x2c29cc beq 0x2c29e8 <_Z9DGifSlurpP11GifFileType+0xd0> */
/* @0x2c29d0 bl 0x2c2270 <_Z20DGifGetExtensionNextP11GifFileTypePPh> */
/* @0x2c29d4 cmp r0, #0 */
/* @0x2c29d8 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4> */
/* @0x2c29dc ldr r3, [sp, #0x20] */
/* @0x2c29e0 cmp r3, #0 */
/* @0x2c29e4 bne 0x2c2ad8 <_Z9DGifSlurpP11GifFileType+0x1c0> */
/* @0x2c29e8 ldr r3, [sp, #0x1c] */
/* @0x2c29ec cmp r3, #4 */
/* @0x2c29f0 bne 0x2c2954 <_Z9DGifSlurpP11GifFileType+0x3c> */
/* @0x2c29f4 mov r0, #1 */
/* @0x2c29f8 add sp, sp, #76 */
/* @0x2c29fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c2a00 mov r0, r5 */
/* @0x2c2a04 bl 0x2c1ea8 <_Z16DGifGetImageDescP11GifFileType> */
/* @0x2c2a08 cmp r0, #0 */
/* @0x2c2a0c beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4> */
/* @0x2c2a10 ldr r3, [r5, #0x18] */
/* @0x2c2a14 ldr r4, [r5, #0x34] */
/* @0x2c2a18 add r3, r3, r3, lsl #3 */
/* @0x2c2a1c lsl r3, r3, #2 */
/* @0x2c2a20 sub r3, r3, #36 */
/* @0x2c2a24 add r4, r4, r3 */
/* @0x2c2a28 ldr r6, [r4, #0x8] */
/* @0x2c2a2c ldr r11, [r4, #0xc] */
/* @0x2c2a30 cmp r6, #0 */
/* @0x2c2a34 blt 0x2c2b08 <_Z9DGifSlurpP11GifFileType+0x1f0> */
/* @0x2c2a38 mul r6, r11, r6 */
/* @0x2c2a3c mov r0, r6 */
/* @0x2c2a40 bl 0xb6544 <malloc@plt> */
/* @0x2c2a44 cmp r0, #0 */
/* @0x2c2a48 str r0, [r4, #0x18] */
/* @0x2c2a4c beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4> */
/* @0x2c2a50 ldrb r3, [r4, #0x10] */
/* @0x2c2a54 cmp r3, #0 */
/* @0x2c2a58 beq 0x2c2b3c <_Z9DGifSlurpP11GifFileType+0x224> */
/* @0x2c2a5c ldr r2, [sp, #0x10] */
/* @0x2c2a60 add r8, sp, #40 */
/* @0x2c2a64 add r6, sp, #56 */
/* @0x2c2a68 mov r7, #0 */
/* @0x2c2a6c add r3, r2, #28 */
/* @0x2c2a70 add r12, r2, #44 */
/* @0x2c2a74 ldm r3, {r0, r1, r2, r3} */
/* @0x2c2a78 stm r8, {r0, r1, r2, r3} */
/* @0x2c2a7c ldm r12, {r0, r1, r2, r3} */
/* @0x2c2a80 stm r6, {r0, r1, r2, r3} */
/* @0x2c2a84 mov r3, r11 */
/* @0x2c2a88 mov r11, r7 */
/* @0x2c2a8c mov r7, r8 */
/* @0x2c2a90 ldr r8, [r7, r11] */
/* @0x2c2a94 cmp r8, r3 */
/* @0x2c2a98 blt 0x2c2ab4 <_Z9DGifSlurpP11GifFileType+0x19c> */
/* @0x2c2a9c b 0x2c2b28 <_Z9DGifSlurpP11GifFileType+0x210> */
/* @0x2c2aa0 ldr r2, [r6, r11] */
/* @0x2c2aa4 ldr r3, [r4, #0xc] */
/* @0x2c2aa8 add r8, r8, r2 */
/* @0x2c2aac cmp r3, r8 */
/* @0x2c2ab0 ble 0x2c2b28 <_Z9DGifSlurpP11GifFileType+0x210> */
/* @0x2c2ab4 ldr r3, [r4, #0x8] */
/* @0x2c2ab8 mov r0, r5 */
/* @0x2c2abc ldr r1, [r4, #0x18] */
/* @0x2c2ac0 mov r2, r3 */
/* @0x2c2ac4 mla r1, r8, r3, r1 */
/* @0x2c2ac8 bl 0x2c26a8 <_Z11DGifGetLineP11GifFileTypePhi> */
/* @0x2c2acc cmp r0, #0 */
/* @0x2c2ad0 bne 0x2c2aa0 <_Z9DGifSlurpP11GifFileType+0x188> */
/* @0x2c2ad4 b 0x2c29f8 <_Z9DGifSlurpP11GifFileType+0xe0> */
/* @0x2c2ad8 mov r12, r3 */
/* @0x2c2adc ldr r0, [sp, #0xc] */
/* @0x2c2ae0 ldrb r3, [r12], #1 */
/* @0x2c2ae4 mov r1, r4 */
/* @0x2c2ae8 mov r2, #0 */
/* @0x2c2aec str r12, [sp] */
/* @0x2c2af0 bl 0x2c2f3c <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh> */
/* @0x2c2af4 cmp r0, #0 */
/* @0x2c2af8 bne 0x2c29bc <_Z9DGifSlurpP11GifFileType+0xa4> */
/* @0x2c2afc mov r0, #0 */
/* @0x2c2b00 add sp, sp, #76 */
/* @0x2c2b04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c2b08 cmp r11, #0 */
/* @0x2c2b0c bge 0x2c2a38 <_Z9DGifSlurpP11GifFileType+0x120> */
/* @0x2c2b10 mvn r0, #-2147483648 */
/* @0x2c2b14 mov r1, r11 */
/* @0x2c2b18 bl 0x318d10 <__divsi3> */
/* @0x2c2b1c cmp r6, r0 */
/* @0x2c2b20 ble 0x2c2a38 <_Z9DGifSlurpP11GifFileType+0x120> */
/* @0x2c2b24 b 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4> */
/* @0x2c2b28 add r11, r11, #4 */
/* @0x2c2b2c cmp r11, #16 */
/* @0x2c2b30 beq 0x2c2b54 <_Z9DGifSlurpP11GifFileType+0x23c> */
/* @0x2c2b34 ldr r3, [r4, #0xc] */
/* @0x2c2b38 b 0x2c2a90 <_Z9DGifSlurpP11GifFileType+0x178> */
/* @0x2c2b3c mov r1, r0 */
/* @0x2c2b40 mov r2, r6 */
/* @0x2c2b44 mov r0, r5 */
/* @0x2c2b48 bl 0x2c26a8 <_Z11DGifGetLineP11GifFileTypePhi> */
/* @0x2c2b4c cmp r0, #0 */
/* @0x2c2b50 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4> */
/* @0x2c2b54 ldr r3, [r5, #0x3c] */
/* @0x2c2b58 cmp r3, #0 */
/* @0x2c2b5c beq 0x2c29e8 <_Z9DGifSlurpP11GifFileType+0xd0> */
/* @0x2c2b60 ldr r2, [r5, #0x38] */
/* @0x2c2b64 str r3, [r4, #0x20] */
/* @0x2c2b68 ldr r3, [sp, #0x1c] */
/* @0x2c2b6c str r2, [r4, #0x1c] */
/* @0x2c2b70 mov r2, #0 */
/* @0x2c2b74 cmp r3, #4 */
/* @0x2c2b78 str r2, [r5, #0x3c] */
/* @0x2c2b7c str r2, [r5, #0x38] */
/* @0x2c2b80 bne 0x2c2954 <_Z9DGifSlurpP11GifFileType+0x3c> */
/* @0x2c2b84 b 0x2c29f4 <_Z9DGifSlurpP11GifFileType+0xdc> */
/* @0x2c2b88 andeq sp, r12, r12, lsr #18 */

/* ── FUNC 0x2c2b8c · GifBitSize(int) · size=36 · insn=9 */
/* @0x2c2b8c mov r3, #1 */
/* @0x2c2b90 mov r2, r3 */
/* @0x2c2b94 cmp r0, r2, lsl r3 */
/* @0x2c2b98 ble 0x2c2ba8 <_Z10GifBitSizei+0x1c> */
/* @0x2c2b9c add r3, r3, #1 */
/* @0x2c2ba0 cmp r3, #9 */
/* @0x2c2ba4 bne 0x2c2b94 <_Z10GifBitSizei+0x8> */
/* @0x2c2ba8 mov r0, r3 */
/* @0x2c2bac bx lr */

/* ── FUNC 0x2c2bb0 · GifMakeMapObject(int, GifColorType const*) · size=152 · insn=38 */
/* @0x2c2bb0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2c2bb4 mov r4, r0 */
/* @0x2c2bb8 mov r6, r1 */
/* @0x2c2bbc bl 0x2c2b8c <_Z10GifBitSizei> */
/* @0x2c2bc0 mov r3, #1 */
/* @0x2c2bc4 cmp r4, r3, lsl r0 */
/* @0x2c2bc8 bne 0x2c2c28 <_Z16GifMakeMapObjectiPK12GifColorType+0x78> */
/* @0x2c2bcc mov r0, #16 */
/* @0x2c2bd0 bl 0xb6544 <malloc@plt> */
/* @0x2c2bd4 subs r5, r0, #0 */
/* @0x2c2bd8 beq 0x2c2c30 <_Z16GifMakeMapObjectiPK12GifColorType+0x80> */
/* @0x2c2bdc mov r0, r4 */
/* @0x2c2be0 mov r1, #3 */
/* @0x2c2be4 bl 0xb6c34 <calloc@plt> */
/* @0x2c2be8 cmp r0, #0 */
/* @0x2c2bec mov r7, r0 */
/* @0x2c2bf0 str r0, [r5, #0xc] */
/* @0x2c2bf4 beq 0x2c2c38 <_Z16GifMakeMapObjectiPK12GifColorType+0x88> */
/* @0x2c2bf8 str r4, [r5] */
/* @0x2c2bfc mov r0, r4 */
/* @0x2c2c00 bl 0x2c2b8c <_Z10GifBitSizei> */
/* @0x2c2c04 cmp r6, #0 */
/* @0x2c2c08 str r0, [r5, #0x4] */
/* @0x2c2c0c beq 0x2c2c30 <_Z16GifMakeMapObjectiPK12GifColorType+0x80> */
/* @0x2c2c10 mov r1, r6 */
/* @0x2c2c14 add r2, r4, r4, lsl #1 */
/* @0x2c2c18 ldr r0, [r5, #0xc] */
/* @0x2c2c1c bl 0xb65bc <memcpy@plt> */
/* @0x2c2c20 mov r0, r5 */
/* @0x2c2c24 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2c2c28 mov r0, #0 */
/* @0x2c2c2c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2c2c30 mov r0, r5 */
/* @0x2c2c34 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2c2c38 mov r0, r5 */
/* @0x2c2c3c bl 0xb655c <free@plt> */
/* @0x2c2c40 mov r0, r7 */
/* @0x2c2c44 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2c2c48 · GifFreeMapObject(ColorMapObject*) · size=32 · insn=8 */
/* @0x2c2c48 push {r4, lr} */
/* @0x2c2c4c subs r4, r0, #0 */
/* @0x2c2c50 popeq {r4, pc} */
/* @0x2c2c54 ldr r0, [r4, #0xc] */
/* @0x2c2c58 bl 0xb655c <free@plt> */
/* @0x2c2c5c mov r0, r4 */
/* @0x2c2c60 pop {r4, lr} */
/* @0x2c2c64 b 0xb655c <free@plt> */

/* ── FUNC 0x2c2c68 · GifUnionColorMap(ColorMapObject const*, ColorMapObject const*, unsigned char*) · size=660 · insn=165 */
/* @0x2c2c68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c2c6c sub sp, sp, #20 */
/* @0x2c2c70 ldr r3, [r0] */
/* @0x2c2c74 mov r7, r0 */
/* @0x2c2c78 str r2, [sp, #0xc] */
/* @0x2c2c7c mov r10, r1 */
/* @0x2c2c80 ldr r2, [r1] */
/* @0x2c2c84 mov r1, #0 */
/* @0x2c2c88 cmp r3, r2 */
/* @0x2c2c8c lslgt r0, r3, #1 */
/* @0x2c2c90 lslle r0, r2, #1 */
/* @0x2c2c94 bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType> */
/* @0x2c2c98 cmp r0, #0 */
/* @0x2c2c9c str r0, [sp, #0x8] */
/* @0x2c2ca0 beq 0x2c2edc <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x274> */
/* @0x2c2ca4 ldr r4, [r7] */
/* @0x2c2ca8 cmp r4, #0 */
/* @0x2c2cac mov r6, r4 */
/* @0x2c2cb0 ble 0x2c2cf4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x8c> */
/* @0x2c2cb4 mov r3, #0 */
/* @0x2c2cb8 mov r5, r0 */
/* @0x2c2cbc ldr r0, [r7, #0xc] */
/* @0x2c2cc0 add r2, r3, r3, lsl #1 */
/* @0x2c2cc4 ldr r1, [r5, #0xc] */
/* @0x2c2cc8 add r3, r3, #1 */
/* @0x2c2ccc add r0, r0, r2 */
/* @0x2c2cd0 add r12, r1, r2 */
/* @0x2c2cd4 ldrh lr, [r0] */
/* @0x2c2cd8 ldrb r0, [r0, #0x2] */
/* @0x2c2cdc strh lr, [r1, r2] */
/* @0x2c2ce0 strb r0, [r12, #0x2] */
/* @0x2c2ce4 ldr r4, [r7] */
/* @0x2c2ce8 cmp r4, r3 */
/* @0x2c2cec mov r6, r4 */
/* @0x2c2cf0 bgt 0x2c2cbc <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x54> */
/* @0x2c2cf4 ldr r3, [r7, #0xc] */
/* @0x2c2cf8 add r0, r4, r4, lsl #1 */
/* @0x2c2cfc sub r1, r0, #3 */
/* @0x2c2d00 add r2, r3, r1 */
/* @0x2c2d04 ldrb r1, [r3, r1] */
/* @0x2c2d08 cmp r1, #0 */
/* @0x2c2d0c bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4> */
/* @0x2c2d10 ldrb r1, [r2, #0x1] */
/* @0x2c2d14 cmp r1, #0 */
/* @0x2c2d18 bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4> */
/* @0x2c2d1c ldrb r2, [r2, #0x2] */
/* @0x2c2d20 cmp r2, #0 */
/* @0x2c2d24 bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4> */
/* @0x2c2d28 add r3, r3, r0 */
/* @0x2c2d2c b 0x2c2d4c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xe4> */
/* @0x2c2d30 ldrb r2, [r3, #-0x5] */
/* @0x2c2d34 sub r3, r3, #3 */
/* @0x2c2d38 cmp r2, #0 */
/* @0x2c2d3c bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4> */
/* @0x2c2d40 ldrb r2, [r3, #-0x1] */
/* @0x2c2d44 cmp r2, #0 */
/* @0x2c2d48 bne 0x2c2d5c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xf4> */
/* @0x2c2d4c ldrb r2, [r3, #-0x6] */
/* @0x2c2d50 sub r6, r6, #1 */
/* @0x2c2d54 cmp r2, #0 */
/* @0x2c2d58 beq 0x2c2d30 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0xc8> */
/* @0x2c2d5c ldr r3, [r10] */
/* @0x2c2d60 cmp r3, #0 */
/* @0x2c2d64 ble 0x2c2e40 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x1d8> */
/* @0x2c2d68 cmp r6, #256 */
/* @0x2c2d6c strle r7, [sp, #0x4] */
/* @0x2c2d70 movle r9, #0 */
/* @0x2c2d74 movle r8, r9 */
/* @0x2c2d78 bgt 0x2c2ed4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x26c> */
/* @0x2c2d7c ldr r5, [r10, #0xc] */
/* @0x2c2d80 cmp r4, #0 */
/* @0x2c2d84 addle r5, r5, r9 */
/* @0x2c2d88 ble 0x2c2e04 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x19c> */
/* @0x2c2d8c ldr r3, [sp, #0x4] */
/* @0x2c2d90 mov r11, #0 */
/* @0x2c2d94 add r5, r5, r9 */
/* @0x2c2d98 ldr r7, [r3, #0xc] */
/* @0x2c2d9c b 0x2c2dac <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x144> */
/* @0x2c2da0 add r11, r11, #1 */
/* @0x2c2da4 cmp r11, r4 */
/* @0x2c2da8 beq 0x2c2e04 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x19c> */
/* @0x2c2dac mov r0, r7 */
/* @0x2c2db0 mov r2, #3 */
/* @0x2c2db4 mov r1, r5 */
/* @0x2c2db8 add r7, r7, r2 */
/* @0x2c2dbc bl 0xb6c40 <memcmp@plt> */
/* @0x2c2dc0 cmp r0, #0 */
/* @0x2c2dc4 bne 0x2c2da0 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x138> */
/* @0x2c2dc8 ldr r3, [sp, #0xc] */
/* @0x2c2dcc strb r11, [r3, r8] */
/* @0x2c2dd0 add r8, r8, #1 */
/* @0x2c2dd4 ldr r3, [r10] */
/* @0x2c2dd8 cmp r3, r8 */
/* @0x2c2ddc ble 0x2c2e40 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x1d8> */
/* @0x2c2de0 cmp r6, #256 */
/* @0x2c2de4 add r9, r9, #3 */
/* @0x2c2de8 bgt 0x2c2ed4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x26c> */
/* @0x2c2dec ldr r3, [sp, #0x4] */
/* @0x2c2df0 ldr r5, [r10, #0xc] */
/* @0x2c2df4 ldr r4, [r3] */
/* @0x2c2df8 cmp r4, #0 */
/* @0x2c2dfc addle r5, r5, r9 */
/* @0x2c2e00 bgt 0x2c2d8c <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x124> */
/* @0x2c2e04 ldr r3, [sp, #0x8] */
/* @0x2c2e08 ldrh r12, [r5] */
/* @0x2c2e0c ldrb r0, [r5, #0x2] */
/* @0x2c2e10 ldr r2, [r3, #0xc] */
/* @0x2c2e14 add r3, r6, r6, lsl #1 */
/* @0x2c2e18 add r1, r2, r3 */
/* @0x2c2e1c strh r12, [r2, r3] */
/* @0x2c2e20 ldr r3, [sp, #0xc] */
/* @0x2c2e24 strb r0, [r1, #0x2] */
/* @0x2c2e28 strb r6, [r3, r8] */
/* @0x2c2e2c add r8, r8, #1 */
/* @0x2c2e30 ldr r3, [r10] */
/* @0x2c2e34 add r6, r6, #1 */
/* @0x2c2e38 cmp r3, r8 */
/* @0x2c2e3c bgt 0x2c2de0 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x178> */
/* @0x2c2e40 cmp r6, #256 */
/* @0x2c2e44 bgt 0x2c2ed4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x26c> */
/* @0x2c2e48 mov r0, r6 */
/* @0x2c2e4c mov r5, #1 */
/* @0x2c2e50 bl 0x2c2b8c <_Z10GifBitSizei> */
/* @0x2c2e54 ldr r2, [sp, #0x8] */
/* @0x2c2e58 ldr r3, [r2] */
/* @0x2c2e5c lsl r5, r5, r0 */
/* @0x2c2e60 mov r7, r0 */
/* @0x2c2e64 cmp r3, r5 */
/* @0x2c2e68 beq 0x2c2ebc <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x254> */
/* @0x2c2e6c cmp r5, r6 */
/* @0x2c2e70 ldr r0, [r2, #0xc] */
/* @0x2c2e74 ble 0x2c2eb4 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x24c> */
/* @0x2c2e78 rsb r4, r6, r5 */
/* @0x2c2e7c add r6, r6, r6, lsl #1 */
/* @0x2c2e80 mov r3, #0 */
/* @0x2c2e84 add r12, r0, r6 */
/* @0x2c2e88 add r4, r4, r4, lsl #1 */
/* @0x2c2e8c mov r2, r3 */
/* @0x2c2e90 add r1, r12, r3 */
/* @0x2c2e94 strb r2, [r1, #0x2] */
/* @0x2c2e98 strb r2, [r1, #0x1] */
/* @0x2c2e9c strb r2, [r12, r3] */
/* @0x2c2ea0 add r3, r3, #3 */
/* @0x2c2ea4 cmp r3, r4 */
/* @0x2c2ea8 bne 0x2c2e90 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x228> */
/* @0x2c2eac ldr r2, [sp, #0x8] */
/* @0x2c2eb0 ldr r3, [r2] */
/* @0x2c2eb4 cmp r5, r3 */
/* @0x2c2eb8 blt 0x2c2ee8 <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x280> */
/* @0x2c2ebc ldr r3, [sp, #0x8] */
/* @0x2c2ec0 mov r0, r3 */
/* @0x2c2ec4 str r5, [r3] */
/* @0x2c2ec8 str r7, [r3, #0x4] */
/* @0x2c2ecc add sp, sp, #20 */
/* @0x2c2ed0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c2ed4 ldr r0, [sp, #0x8] */
/* @0x2c2ed8 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c2edc mov r0, #0 */
/* @0x2c2ee0 add sp, sp, #20 */
/* @0x2c2ee4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c2ee8 add r1, r5, r5, lsl #1 */
/* @0x2c2eec bl 0xb6c28 <realloc@plt> */
/* @0x2c2ef0 ldr r3, [sp, #0x8] */
/* @0x2c2ef4 str r0, [r3, #0xc] */
/* @0x2c2ef8 b 0x2c2ebc <_Z16GifUnionColorMapPK14ColorMapObjectS1_Ph+0x254> */

/* ── FUNC 0x2c2efc · GifApplyTranslation(SavedImage*, unsigned char*) · size=64 · insn=16 */
/* @0x2c2efc str r4, [sp, #-0x4]! */
/* @0x2c2f00 ldr r3, [r0, #0xc] */
/* @0x2c2f04 ldr r4, [r0, #0x8] */
/* @0x2c2f08 mul r4, r4, r3 */
/* @0x2c2f0c cmp r4, #0 */
/* @0x2c2f10 ble 0x2c2f34 <_Z19GifApplyTranslationP10SavedImagePh+0x38> */
/* @0x2c2f14 mov r3, #0 */
/* @0x2c2f18 ldr r2, [r0, #0x18] */
/* @0x2c2f1c ldrb r12, [r2, r3] */
/* @0x2c2f20 ldrb r12, [r1, r12] */
/* @0x2c2f24 strb r12, [r2, r3] */
/* @0x2c2f28 add r3, r3, #1 */
/* @0x2c2f2c cmp r3, r4 */
/* @0x2c2f30 bne 0x2c2f18 <_Z19GifApplyTranslationP10SavedImagePh+0x1c> */
/* @0x2c2f34 ldr r4, [sp], #4 */
/* @0x2c2f38 bx lr */

/* ── FUNC 0x2c2f3c · GifAddExtensionBlock(int*, ExtensionBlock**, int, unsigned int, unsigned char*) · size=188 · insn=47 */
/* @0x2c2f3c push {r4, r5, r6, r7, r8, lr} */
/* @0x2c2f40 mov r4, r0 */
/* @0x2c2f44 ldr r0, [r1] */
/* @0x2c2f48 mov r6, r1 */
/* @0x2c2f4c mov r8, r2 */
/* @0x2c2f50 mov r5, r3 */
/* @0x2c2f54 cmp r0, #0 */
/* @0x2c2f58 ldr r7, [sp, #0x18] */
/* @0x2c2f5c beq 0x2c2fe4 <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0xa8> */
/* @0x2c2f60 ldr r1, [r4] */
/* @0x2c2f64 add r1, r1, #1 */
/* @0x2c2f68 add r1, r1, r1, lsl #1 */
/* @0x2c2f6c lsl r1, r1, #2 */
/* @0x2c2f70 bl 0xb6c28 <realloc@plt> */
/* @0x2c2f74 mov r12, r0 */
/* @0x2c2f78 str r0, [r6] */
/* @0x2c2f7c cmp r12, #0 */
/* @0x2c2f80 beq 0x2c2fd4 <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0x98> */
/* @0x2c2f84 ldr lr, [r4] */
/* @0x2c2f88 mov r0, r5 */
/* @0x2c2f8c add r3, lr, #1 */
/* @0x2c2f90 str r3, [r4] */
/* @0x2c2f94 add lr, lr, lr, lsl #1 */
/* @0x2c2f98 lsl lr, lr, #2 */
/* @0x2c2f9c add r4, r12, lr */
/* @0x2c2fa0 str r8, [r4, #0x8] */
/* @0x2c2fa4 str r5, [r12, lr] */
/* @0x2c2fa8 bl 0xb6544 <malloc@plt> */
/* @0x2c2fac cmp r0, #0 */
/* @0x2c2fb0 str r0, [r4, #0x4] */
/* @0x2c2fb4 beq 0x2c2fd4 <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0x98> */
/* @0x2c2fb8 cmp r7, #0 */
/* @0x2c2fbc beq 0x2c2fdc <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0xa0> */
/* @0x2c2fc0 mov r1, r7 */
/* @0x2c2fc4 mov r2, r5 */
/* @0x2c2fc8 bl 0xb65bc <memcpy@plt> */
/* @0x2c2fcc mov r0, #1 */
/* @0x2c2fd0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c2fd4 mov r0, #0 */
/* @0x2c2fd8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c2fdc mov r0, #1 */
/* @0x2c2fe0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c2fe4 mov r0, #12 */
/* @0x2c2fe8 bl 0xb6544 <malloc@plt> */
/* @0x2c2fec mov r12, r0 */
/* @0x2c2ff0 str r0, [r6] */
/* @0x2c2ff4 b 0x2c2f7c <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0x40> */

/* ── FUNC 0x2c2ff8 · GifFreeExtensions(int*, ExtensionBlock**) · size=116 · insn=29 */
/* @0x2c2ff8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2c2ffc mov r6, r1 */
/* @0x2c3000 ldr r4, [r1] */
/* @0x2c3004 mov r7, r0 */
/* @0x2c3008 cmp r4, #0 */
/* @0x2c300c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2c3010 ldr r3, [r0] */
/* @0x2c3014 add r3, r3, r3, lsl #1 */
/* @0x2c3018 add r3, r4, r3, lsl #2 */
/* @0x2c301c cmp r4, r3 */
/* @0x2c3020 bhs 0x2c3064 <_Z17GifFreeExtensionsPiPP14ExtensionBlock+0x6c> */
/* @0x2c3024 add r4, r4, #12 */
/* @0x2c3028 ldr r0, [r4, #-0x8] */
/* @0x2c302c mov r5, r4 */
/* @0x2c3030 bl 0xb655c <free@plt> */
/* @0x2c3034 ldr r3, [r7] */
/* @0x2c3038 ldr r0, [r6] */
/* @0x2c303c add r3, r3, r3, lsl #1 */
/* @0x2c3040 add r3, r0, r3, lsl #2 */
/* @0x2c3044 cmp r4, r3 */
/* @0x2c3048 add r4, r4, #12 */
/* @0x2c304c blo 0x2c3028 <_Z17GifFreeExtensionsPiPP14ExtensionBlock+0x30> */
/* @0x2c3050 bl 0xb655c <free@plt> */
/* @0x2c3054 mov r3, #0 */
/* @0x2c3058 str r3, [r6] */
/* @0x2c305c str r3, [r7] */
/* @0x2c3060 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2c3064 mov r0, r4 */
/* @0x2c3068 b 0x2c3050 <_Z17GifFreeExtensionsPiPP14ExtensionBlock+0x58> */

/* ── FUNC 0x2c306c · FreeLastSavedImage(GifFileType*) · size=100 · insn=25 */
/* @0x2c306c cmp r0, #0 */
/* @0x2c3070 push {r4, lr} */
/* @0x2c3074 popeq {r4, pc} */
/* @0x2c3078 ldr r2, [r0, #0x34] */
/* @0x2c307c cmp r2, #0 */
/* @0x2c3080 popeq {r4, pc} */
/* @0x2c3084 ldr r3, [r0, #0x18] */
/* @0x2c3088 sub r3, r3, #1 */
/* @0x2c308c str r3, [r0, #0x18] */
/* @0x2c3090 add r3, r3, r3, lsl #3 */
/* @0x2c3094 add r4, r2, r3, lsl #2 */
/* @0x2c3098 ldr r0, [r4, #0x14] */
/* @0x2c309c cmp r0, #0 */
/* @0x2c30a0 beq 0x2c30b0 <_Z18FreeLastSavedImageP11GifFileType+0x44> */
/* @0x2c30a4 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c30a8 mov r3, #0 */
/* @0x2c30ac str r3, [r4, #0x14] */
/* @0x2c30b0 ldr r0, [r4, #0x18] */
/* @0x2c30b4 cmp r0, #0 */
/* @0x2c30b8 beq 0x2c30c0 <_Z18FreeLastSavedImageP11GifFileType+0x54> */
/* @0x2c30bc bl 0xb655c <free@plt> */
/* @0x2c30c0 add r0, r4, #28 */
/* @0x2c30c4 add r1, r4, #32 */
/* @0x2c30c8 pop {r4, lr} */
/* @0x2c30cc b 0x2c2ff8 <_Z17GifFreeExtensionsPiPP14ExtensionBlock> */

/* ── FUNC 0x2c30d0 · GifMakeSavedImage(GifFileType*, SavedImage const*) · size=356 · insn=89 */
/* @0x2c30d0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2c30d4 mov r6, r0 */
/* @0x2c30d8 ldr r0, [r0, #0x34] */
/* @0x2c30dc mov r4, r1 */
/* @0x2c30e0 cmp r0, #0 */
/* @0x2c30e4 beq 0x2c3210 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x140> */
/* @0x2c30e8 ldr r1, [r6, #0x18] */
/* @0x2c30ec add r1, r1, #1 */
/* @0x2c30f0 add r1, r1, r1, lsl #3 */
/* @0x2c30f4 lsl r1, r1, #2 */
/* @0x2c30f8 bl 0xb6c28 <realloc@plt> */
/* @0x2c30fc mov r5, r0 */
/* @0x2c3100 str r0, [r6, #0x34] */
/* @0x2c3104 cmp r5, #0 */
/* @0x2c3108 beq 0x2c3208 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x138> */
/* @0x2c310c ldr r3, [r6, #0x18] */
/* @0x2c3110 mov r1, #0 */
/* @0x2c3114 mov r2, #36 */
/* @0x2c3118 add r0, r3, #1 */
/* @0x2c311c str r0, [r6, #0x18] */
/* @0x2c3120 add r3, r3, r3, lsl #3 */
/* @0x2c3124 add r5, r5, r3, lsl #2 */
/* @0x2c3128 mov r0, r5 */
/* @0x2c312c bl 0xb65b0 <memset@plt> */
/* @0x2c3130 cmp r4, #0 */
/* @0x2c3134 beq 0x2c3208 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x138> */
/* @0x2c3138 add r1, r4, #32 */
/* @0x2c313c mov r3, r4 */
/* @0x2c3140 mov r2, r5 */
/* @0x2c3144 ldr r7, [r3] */
/* @0x2c3148 add r3, r3, #16 */
/* @0x2c314c ldr lr, [r3, #-0xc] */
/* @0x2c3150 add r2, r2, #16 */
/* @0x2c3154 ldr r12, [r3, #-0x8] */
/* @0x2c3158 ldr r0, [r3, #-0x4] */
/* @0x2c315c cmp r3, r1 */
/* @0x2c3160 str r7, [r2, #-0x10] */
/* @0x2c3164 str lr, [r2, #-0xc] */
/* @0x2c3168 str r12, [r2, #-0x8] */
/* @0x2c316c str r0, [r2, #-0x4] */
/* @0x2c3170 bne 0x2c3144 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x74> */
/* @0x2c3174 ldr r3, [r3] */
/* @0x2c3178 str r3, [r2] */
/* @0x2c317c ldr r3, [r5, #0x14] */
/* @0x2c3180 cmp r3, #0 */
/* @0x2c3184 beq 0x2c31a4 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0xd4> */
/* @0x2c3188 ldr r3, [r4, #0x14] */
/* @0x2c318c ldr r0, [r3] */
/* @0x2c3190 ldr r1, [r3, #0xc] */
/* @0x2c3194 bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType> */
/* @0x2c3198 cmp r0, #0 */
/* @0x2c319c str r0, [r5, #0x14] */
/* @0x2c31a0 beq 0x2c3224 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x154> */
/* @0x2c31a4 ldr r3, [r4, #0x8] */
/* @0x2c31a8 ldr r7, [r4, #0xc] */
/* @0x2c31ac mul r7, r7, r3 */
/* @0x2c31b0 mov r0, r7 */
/* @0x2c31b4 bl 0xb6544 <malloc@plt> */
/* @0x2c31b8 cmp r0, #0 */
/* @0x2c31bc str r0, [r5, #0x18] */
/* @0x2c31c0 beq 0x2c3224 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x154> */
/* @0x2c31c4 mov r2, r7 */
/* @0x2c31c8 ldr r1, [r4, #0x18] */
/* @0x2c31cc bl 0xb65bc <memcpy@plt> */
/* @0x2c31d0 ldr r3, [r5, #0x20] */
/* @0x2c31d4 cmp r3, #0 */
/* @0x2c31d8 beq 0x2c3208 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x138> */
/* @0x2c31dc ldr r2, [r4, #0x1c] */
/* @0x2c31e0 add r2, r2, r2, lsl #1 */
/* @0x2c31e4 lsl r7, r2, #2 */
/* @0x2c31e8 mov r0, r7 */
/* @0x2c31ec bl 0xb6544 <malloc@plt> */
/* @0x2c31f0 cmp r0, #0 */
/* @0x2c31f4 str r0, [r5, #0x20] */
/* @0x2c31f8 beq 0x2c3224 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x154> */
/* @0x2c31fc ldr r1, [r4, #0x20] */
/* @0x2c3200 mov r2, r7 */
/* @0x2c3204 bl 0xb65bc <memcpy@plt> */
/* @0x2c3208 mov r0, r5 */
/* @0x2c320c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2c3210 mov r0, #36 */
/* @0x2c3214 bl 0xb6544 <malloc@plt> */
/* @0x2c3218 mov r5, r0 */
/* @0x2c321c str r0, [r6, #0x34] */
/* @0x2c3220 b 0x2c3104 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x34> */
/* @0x2c3224 mov r0, r6 */
/* @0x2c3228 mov r5, #0 */
/* @0x2c322c bl 0x2c306c <_Z18FreeLastSavedImageP11GifFileType> */
/* @0x2c3230 b 0x2c3208 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x138> */

/* ── FUNC 0x2c3234 · GifFreeSavedImages(GifFileType*) · size=148 · insn=37 */
/* @0x2c3234 push {r4, r5, r6, lr} */
/* @0x2c3238 subs r5, r0, #0 */
/* @0x2c323c popeq {r4, r5, r6, pc} */
/* @0x2c3240 ldr r4, [r5, #0x34] */
/* @0x2c3244 cmp r4, #0 */
/* @0x2c3248 popeq {r4, r5, r6, pc} */
/* @0x2c324c ldr r3, [r5, #0x18] */
/* @0x2c3250 add r3, r3, r3, lsl #3 */
/* @0x2c3254 add r3, r4, r3, lsl #2 */
/* @0x2c3258 cmp r4, r3 */
/* @0x2c325c bhs 0x2c32c0 <_Z18GifFreeSavedImagesP11GifFileType+0x8c> */
/* @0x2c3260 mov r6, #0 */
/* @0x2c3264 ldr r0, [r4, #0x14] */
/* @0x2c3268 cmp r0, #0 */
/* @0x2c326c beq 0x2c3278 <_Z18GifFreeSavedImagesP11GifFileType+0x44> */
/* @0x2c3270 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c3274 str r6, [r4, #0x14] */
/* @0x2c3278 ldr r0, [r4, #0x18] */
/* @0x2c327c cmp r0, #0 */
/* @0x2c3280 beq 0x2c3288 <_Z18GifFreeSavedImagesP11GifFileType+0x54> */
/* @0x2c3284 bl 0xb655c <free@plt> */
/* @0x2c3288 add r0, r4, #28 */
/* @0x2c328c add r1, r4, #32 */
/* @0x2c3290 bl 0x2c2ff8 <_Z17GifFreeExtensionsPiPP14ExtensionBlock> */
/* @0x2c3294 ldr r3, [r5, #0x18] */
/* @0x2c3298 ldr r0, [r5, #0x34] */
/* @0x2c329c add r4, r4, #36 */
/* @0x2c32a0 add r3, r3, r3, lsl #3 */
/* @0x2c32a4 add r3, r0, r3, lsl #2 */
/* @0x2c32a8 cmp r4, r3 */
/* @0x2c32ac blo 0x2c3264 <_Z18GifFreeSavedImagesP11GifFileType+0x30> */
/* @0x2c32b0 bl 0xb655c <free@plt> */
/* @0x2c32b4 mov r3, #0 */
/* @0x2c32b8 str r3, [r5, #0x34] */
/* @0x2c32bc pop {r4, r5, r6, pc} */
/* @0x2c32c0 mov r0, r4 */
/* @0x2c32c4 b 0x2c32b0 <_Z18GifFreeSavedImagesP11GifFileType+0x7c> */

/* ── FUNC 0x2c32c8 · b2WorldManifold::Initialize(b2Manifold const*, b2Transform const&, float, b2Transform const&, float) · size=924 · insn=231 */
/* @0x2c32c8 push {r4, lr} */
/* @0x2c32cc vpush {d8, d9, d10} */
/* @0x2c32d0 mov r4, r0 */
/* @0x2c32d4 vldr s17, [sp, #36] */
/* @0x2c32d8 ldr r0, [r1, #0x3c] */
/* @0x2c32dc vmov s16, r3 */
/* @0x2c32e0 ldr r12, [sp, #0x20] */
/* @0x2c32e4 cmp r0, #0 */
/* @0x2c32e8 beq 0x2c3308 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x40> */
/* @0x2c32ec ldr r3, [r1, #0x38] */
/* @0x2c32f0 cmp r3, #1 */
/* @0x2c32f4 beq 0x2c3310 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x48> */
/* @0x2c32f8 cmp r3, #2 */
/* @0x2c32fc beq 0x2c34dc <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x214> */
/* @0x2c3300 cmp r3, #0 */
/* @0x2c3304 beq 0x2c3410 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x148> */
/* @0x2c3308 vpop {d8, d9, d10} */
/* @0x2c330c pop {r4, pc} */
/* @0x2c3310 vldr s14, [r2, #12] */
/* @0x2c3314 vldr s15, [r2, #8] */
/* @0x2c3318 vldr s12, [r1, #44] */
/* @0x2c331c vmul.f32 s11, s14, s12 */
/* @0x2c3320 vldr s13, [r1, #40] */
/* @0x2c3324 vldr s6, [r2] */
/* @0x2c3328 vldr s9, [r2, #4] */
/* @0x2c332c cmp r0, #0 */
/* @0x2c3330 vmul.f32 s12, s15, s12 */
/* @0x2c3334 vmla.f32 s11, s13, s15 */
/* @0x2c3338 vnmls.f32 s12, s14, s13 */
/* @0x2c333c vstr s11, [r4, #4] */
/* @0x2c3340 vstr s12, [r4] */
/* @0x2c3344 vldr s5, [r1, #52] */
/* @0x2c3348 vmul.f32 s13, s15, s5 */
/* @0x2c334c vldr s10, [r1, #48] */
/* @0x2c3350 vmul.f32 s5, s14, s5 */
/* @0x2c3354 vnmls.f32 s13, s14, s10 */
/* @0x2c3358 vmla.f32 s5, s15, s10 */
/* @0x2c335c vadd.f32 s6, s13, s6 */
/* @0x2c3360 vadd.f32 s5, s5, s9 */
/* @0x2c3364 ble 0x2c3308 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x40> */
/* @0x2c3368 add r3, r4, #8 */
/* @0x2c336c mov r2, #0 */
/* @0x2c3370 vldr s8, [r12, #12] */
/* @0x2c3374 vldr s9, [r12, #8] */
/* @0x2c3378 vldr s3, [r12] */
/* @0x2c337c vldr s4, [r12, #4] */
/* @0x2c3380 vmov.f32 s10, #5.000000e-01 */
/* @0x2c3384 b 0x2c3390 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0xc8> */
/* @0x2c3388 vldr s12, [r4] */
/* @0x2c338c vldr s11, [r4, #4] */
/* @0x2c3390 vldr s14, [r1, #4] */
/* @0x2c3394 vmul.f32 s15, s14, s8 */
/* @0x2c3398 vldr s13, [r1] */
/* @0x2c339c add r2, r2, #1 */
/* @0x2c33a0 cmp r2, r0 */
/* @0x2c33a4 add r1, r1, #20 */
/* @0x2c33a8 add r3, r3, #8 */
/* @0x2c33ac vmla.f32 s15, s13, s9 */
/* @0x2c33b0 vmul.f32 s14, s14, s9 */
/* @0x2c33b4 vnmls.f32 s14, s13, s8 */
/* @0x2c33b8 vadd.f32 s15, s15, s4 */
/* @0x2c33bc vsub.f32 s13, s15, s5 */
/* @0x2c33c0 vadd.f32 s14, s14, s3 */
/* @0x2c33c4 vmul.f32 s13, s13, s11 */
/* @0x2c33c8 vsub.f32 s7, s14, s6 */
/* @0x2c33cc vmla.f32 s13, s7, s12 */
/* @0x2c33d0 vsub.f32 s13, s16, s13 */
/* @0x2c33d4 vmov.f32 s7, s14 */
/* @0x2c33d8 vmla.f32 s14, s13, s12 */
/* @0x2c33dc vmls.f32 s7, s17, s12 */
/* @0x2c33e0 vmov.f32 s12, s15 */
/* @0x2c33e4 vmls.f32 s15, s17, s11 */
/* @0x2c33e8 vmla.f32 s12, s13, s11 */
/* @0x2c33ec vadd.f32 s14, s14, s7 */
/* @0x2c33f0 vadd.f32 s15, s12, s15 */
/* @0x2c33f4 vmul.f32 s14, s14, s10 */
/* @0x2c33f8 vmul.f32 s15, s15, s10 */
/* @0x2c33fc vstr s14, [r3, #-8] */
/* @0x2c3400 vstr s15, [r3, #-4] */
/* @0x2c3404 bne 0x2c3388 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0xc0> */
/* @0x2c3408 vpop {d8, d9, d10} */
/* @0x2c340c pop {r4, pc} */
/* @0x2c3410 vldr s8, [r2, #12] */
/* @0x2c3414 vldr s10, [r12, #12] */
/* @0x2c3418 vldr s4, [pc, #568] */
/* @0x2c341c vstr s4, [r4, #4] */
/* @0x2c3420 vldr s13, [r1, #52] */
/* @0x2c3424 vldr s7, [r1, #4] */
/* @0x2c3428 vmul.f32 s12, s8, s13 */
/* @0x2c342c vldr s6, [r2, #8] */
/* @0x2c3430 vldr s14, [r12, #8] */
/* @0x2c3434 vldr s19, [r2, #4] */
/* @0x2c3438 vldr s18, [r12, #4] */
/* @0x2c343c vldr s3, [pc, #536] */
/* @0x2c3440 vmul.f32 s15, s10, s7 */
/* @0x2c3444 vmov.f32 s5, #1.000000e+00 */
/* @0x2c3448 vmul.f32 s13, s6, s13 */
/* @0x2c344c vstr s5, [r4] */
/* @0x2c3450 vldr s9, [r1, #48] */
/* @0x2c3454 vldr s11, [r1] */
/* @0x2c3458 vldr s21, [r2] */
/* @0x2c345c vldr s20, [r12] */
/* @0x2c3460 vmla.f32 s15, s11, s14 */
/* @0x2c3464 vmla.f32 s12, s9, s6 */
/* @0x2c3468 vmul.f32 s14, s14, s7 */
/* @0x2c346c vnmls.f32 s13, s8, s9 */
/* @0x2c3470 vnmls.f32 s14, s10, s11 */
/* @0x2c3474 vadd.f32 s19, s12, s19 */
/* @0x2c3478 vadd.f32 s18, s15, s18 */
/* @0x2c347c vsub.f32 s15, s19, s18 */
/* @0x2c3480 vadd.f32 s21, s13, s21 */
/* @0x2c3484 vadd.f32 s20, s14, s20 */
/* @0x2c3488 vmul.f32 s15, s15, s15 */
/* @0x2c348c vsub.f32 s14, s21, s20 */
/* @0x2c3490 vmla.f32 s15, s14, s14 */
/* @0x2c3494 vcmpe.f32 s15, s3 */
/* @0x2c3498 vmrs APSR_nzcv, fpscr */
/* @0x2c349c vmovle.f32 s15, s4 */
/* @0x2c34a0 vmovle.f32 s14, s5 */
/* @0x2c34a4 bgt 0x2c35e8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x320> */
/* @0x2c34a8 vmla.f32 s21, s16, s14 */
/* @0x2c34ac vmls.f32 s20, s17, s14 */
/* @0x2c34b0 vmla.f32 s19, s16, s15 */
/* @0x2c34b4 vmls.f32 s18, s17, s15 */
/* @0x2c34b8 vadd.f32 s20, s21, s20 */
/* @0x2c34bc vmov.f32 s11, #5.000000e-01 */
/* @0x2c34c0 vadd.f32 s18, s19, s18 */
/* @0x2c34c4 vmul.f32 s20, s20, s11 */
/* @0x2c34c8 vmul.f32 s11, s18, s11 */
/* @0x2c34cc vstr s20, [r4, #8] */
/* @0x2c34d0 vpop {d8, d9, d10} */
/* @0x2c34d4 vstr s11, [r4, #12] */
/* @0x2c34d8 pop {r4, pc} */
/* @0x2c34dc vldr s14, [r12, #12] */
/* @0x2c34e0 vldr s15, [r12, #8] */
/* @0x2c34e4 vldr s12, [r1, #44] */
/* @0x2c34e8 vmul.f32 s11, s14, s12 */
/* @0x2c34ec vldr s13, [r1, #40] */
/* @0x2c34f0 vldr s6, [r12] */
/* @0x2c34f4 vldr s9, [r12, #4] */
/* @0x2c34f8 cmp r0, #0 */
/* @0x2c34fc vmul.f32 s12, s15, s12 */
/* @0x2c3500 vmla.f32 s11, s13, s15 */
/* @0x2c3504 vnmls.f32 s12, s14, s13 */
/* @0x2c3508 vstr s11, [r4, #4] */
/* @0x2c350c vstr s12, [r4] */
/* @0x2c3510 vldr s5, [r1, #52] */
/* @0x2c3514 vmul.f32 s13, s15, s5 */
/* @0x2c3518 vldr s10, [r1, #48] */
/* @0x2c351c vmul.f32 s5, s14, s5 */
/* @0x2c3520 vnmls.f32 s13, s14, s10 */
/* @0x2c3524 vmla.f32 s5, s15, s10 */
/* @0x2c3528 vadd.f32 s6, s13, s6 */
/* @0x2c352c vadd.f32 s5, s5, s9 */
/* @0x2c3530 ble 0x2c35d0 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x308> */
/* @0x2c3534 add r3, r4, #8 */
/* @0x2c3538 mov r12, #0 */
/* @0x2c353c vldr s8, [r2, #12] */
/* @0x2c3540 vldr s9, [r2, #8] */
/* @0x2c3544 vldr s3, [r2] */
/* @0x2c3548 vldr s4, [r2, #4] */
/* @0x2c354c vmov.f32 s10, #5.000000e-01 */
/* @0x2c3550 vldr s14, [r1, #4] */
/* @0x2c3554 vldr s13, [r1] */
/* @0x2c3558 add r12, r12, #1 */
/* @0x2c355c add r1, r1, #20 */
/* @0x2c3560 cmp r12, r0 */
/* @0x2c3564 add r3, r3, #8 */
/* @0x2c3568 vmul.f32 s15, s14, s8 */
/* @0x2c356c vmul.f32 s14, s14, s9 */
/* @0x2c3570 vmla.f32 s15, s13, s9 */
/* @0x2c3574 vnmls.f32 s14, s13, s8 */
/* @0x2c3578 vadd.f32 s15, s15, s4 */
/* @0x2c357c vsub.f32 s13, s15, s5 */
/* @0x2c3580 vadd.f32 s14, s14, s3 */
/* @0x2c3584 vmul.f32 s13, s13, s11 */
/* @0x2c3588 vsub.f32 s7, s14, s6 */
/* @0x2c358c vmla.f32 s13, s7, s12 */
/* @0x2c3590 vsub.f32 s13, s17, s13 */
/* @0x2c3594 vmov.f32 s7, s14 */
/* @0x2c3598 vmla.f32 s14, s13, s12 */
/* @0x2c359c vmls.f32 s7, s16, s12 */
/* @0x2c35a0 vmov.f32 s12, s15 */
/* @0x2c35a4 vmls.f32 s15, s16, s11 */
/* @0x2c35a8 vmla.f32 s12, s13, s11 */
/* @0x2c35ac vadd.f32 s14, s14, s7 */
/* @0x2c35b0 vadd.f32 s15, s12, s15 */
/* @0x2c35b4 vmul.f32 s14, s14, s10 */
/* @0x2c35b8 vmul.f32 s15, s15, s10 */
/* @0x2c35bc vstr s14, [r3, #-8] */
/* @0x2c35c0 vstr s15, [r3, #-4] */
/* @0x2c35c4 vldr s12, [r4] */
/* @0x2c35c8 vldr s11, [r4, #4] */
/* @0x2c35cc bne 0x2c3550 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x288> */
/* @0x2c35d0 vpop {d8, d9, d10} */
/* @0x2c35d4 vneg.f32 s12, s12 */
/* @0x2c35d8 vneg.f32 s11, s11 */
/* @0x2c35dc vstr s12, [r4] */
/* @0x2c35e0 vstr s11, [r4, #4] */
/* @0x2c35e4 pop {r4, pc} */
/* @0x2c35e8 vsub.f32 s14, s18, s19 */
/* @0x2c35ec vmul.f32 s15, s14, s14 */
/* @0x2c35f0 vstr s14, [r4, #4] */
/* @0x2c35f4 vsub.f32 s14, s20, s21 */
/* @0x2c35f8 vmla.f32 s15, s14, s14 */
/* @0x2c35fc vstr s14, [r4] */
/* @0x2c3600 vsqrt.f32 s13, s15 */
/* @0x2c3604 vcmp.f32 s13, s13 */
/* @0x2c3608 vmrs APSR_nzcv, fpscr */
/* @0x2c360c bne 0x2c3648 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x380> */
/* @0x2c3610 vldr s15, [pc, #72] */
/* @0x2c3614 vcmpe.f32 s13, s15 */
/* @0x2c3618 vmrs APSR_nzcv, fpscr */
/* @0x2c361c vmovpl.f32 s12, #1.000000e+00 */
/* @0x2c3620 vldrpl s14, [r4] */
/* @0x2c3624 vldrpl s15, [r4, #4] */
/* @0x2c3628 vldrmi s14, [r4] */
/* @0x2c362c vldrmi s15, [r4, #4] */
/* @0x2c3630 vdivpl.f32 s13, s12, s13 */
/* @0x2c3634 vmulpl.f32 s14, s13, s14 */
/* @0x2c3638 vmulpl.f32 s15, s13, s15 */
/* @0x2c363c vstrpl s14, [r4] */
/* @0x2c3640 vstrpl s15, [r4, #4] */
/* @0x2c3644 b 0x2c34a8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x1e0> */
/* @0x2c3648 vmov r0, s15 */
/* @0x2c364c bl 0xb6700 <sqrtf@plt> */
/* @0x2c3650 vmov s13, r0 */
/* @0x2c3654 b 0x2c3610 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x348> */
/* @0x2c3658 andeq r0, r0, r0 */
/* @0x2c365c .word 0x28800000 */
/* @0x2c3660 strlo r0, [r0], #-0 */

/* ── FUNC 0x2c3664 · b2GetPointStates(b2PointState*, b2PointState*, b2Manifold const*, b2Manifold const*) · size=304 · insn=76 */
/* @0x2c3664 push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2c3668 mov r12, #0 */
/* @0x2c366c ldr r7, [r2, #0x3c] */
/* @0x2c3670 ldr r8, [r3, #0x3c] */
/* @0x2c3674 cmp r7, r12 */
/* @0x2c3678 str r12, [r0] */
/* @0x2c367c str r12, [r1] */
/* @0x2c3680 str r12, [r0, #0x4] */
/* @0x2c3684 str r12, [r1, #0x4] */
/* @0x2c3688 ble 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78> */
/* @0x2c368c cmp r8, #0 */
/* @0x2c3690 mov r6, r0 */
/* @0x2c3694 mov r4, r2 */
/* @0x2c3698 mov r9, #3 */
/* @0x2c369c mov r10, #2 */
/* @0x2c36a0 ble 0x2c374c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe8> */
/* @0x2c36a4 ldr r5, [r4, #0x10] */
/* @0x2c36a8 add r12, r12, #1 */
/* @0x2c36ac str r9, [r6], #4 */
/* @0x2c36b0 add r4, r4, #20 */
/* @0x2c36b4 ldr r0, [r3, #0x10] */
/* @0x2c36b8 cmp r0, r5 */
/* @0x2c36bc beq 0x2c373c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd8> */
/* @0x2c36c0 cmp r8, #1 */
/* @0x2c36c4 beq 0x2c36d4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x70> */
/* @0x2c36c8 ldr r0, [r3, #0x24] */
/* @0x2c36cc cmp r0, r5 */
/* @0x2c36d0 beq 0x2c373c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd8> */
/* @0x2c36d4 cmp r12, r7 */
/* @0x2c36d8 bne 0x2c36a4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x40> */
/* @0x2c36dc cmp r8, #0 */
/* @0x2c36e0 ble 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0> */
/* @0x2c36e4 cmp r7, #0 */
/* @0x2c36e8 mov r0, r3 */
/* @0x2c36ec mov r5, #1 */
/* @0x2c36f0 mov r3, #0 */
/* @0x2c36f4 mov r6, #2 */
/* @0x2c36f8 ble 0x2c3770 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x10c> */
/* @0x2c36fc ldr r12, [r0, #0x10] */
/* @0x2c3700 add r3, r3, #1 */
/* @0x2c3704 str r5, [r1], #4 */
/* @0x2c3708 add r0, r0, #20 */
/* @0x2c370c ldr r4, [r2, #0x10] */
/* @0x2c3710 cmp r12, r4 */
/* @0x2c3714 beq 0x2c3744 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe0> */
/* @0x2c3718 cmp r7, #1 */
/* @0x2c371c beq 0x2c372c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xc8> */
/* @0x2c3720 ldr r4, [r2, #0x24] */
/* @0x2c3724 cmp r12, r4 */
/* @0x2c3728 beq 0x2c3744 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe0> */
/* @0x2c372c cmp r3, r8 */
/* @0x2c3730 bne 0x2c36fc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x98> */
/* @0x2c3734 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2c3738 bx lr */
/* @0x2c373c str r10, [r6, #-0x4] */
/* @0x2c3740 b 0x2c36d4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x70> */
/* @0x2c3744 str r6, [r1, #-0x4] */
/* @0x2c3748 b 0x2c372c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xc8> */
/* @0x2c374c add r12, r12, #1 */
/* @0x2c3750 str r9, [r6], #4 */
/* @0x2c3754 cmp r12, r7 */
/* @0x2c3758 beq 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78> */
/* @0x2c375c add r12, r12, #1 */
/* @0x2c3760 str r9, [r6], #4 */
/* @0x2c3764 cmp r12, r7 */
/* @0x2c3768 bne 0x2c374c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe8> */
/* @0x2c376c b 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78> */
/* @0x2c3770 add r3, r3, #1 */
/* @0x2c3774 str r5, [r1], #4 */
/* @0x2c3778 cmp r3, r8 */
/* @0x2c377c beq 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0> */
/* @0x2c3780 add r3, r3, #1 */
/* @0x2c3784 str r5, [r1], #4 */
/* @0x2c3788 cmp r3, r8 */
/* @0x2c378c bne 0x2c3770 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x10c> */
/* @0x2c3790 b 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0> */
