/* cally 逆向卡：残段归属修正批 3 —— 按 census 的函数归属重新归组
 * ⚠ 更正：原来的 Residue_01-03 说这些地址「不属于任何函数跨度」是**错的**。
 *   真实原因：生成器用 range(start,end,4) 取指令，而这些函数是 **Thumb-2**，指令落在 2 字节栅格上，
 *   半字地址被漏掉，于是被误标成跨度外残段。census 的 f 字段给出了它们真正的函数归属。
 * 本卡：每节 = 一个真实函数（名字取自 asm/functions.tsv），只收它落在 4 字节栅格之外的那部分指令。
 * 级别: 骨架（地址 + 归属 + 入度；这些函数的其余部分在 All_*/Reach_* 卡里，语义仍 open）
 * 节: 55 个函数｜锚点 3020 条
 *
 * ══ ps_hints_apply  0x2f1400  size 2534  本节 520 条（Thumb-2 半字段）｜入度 92
 * @func 0x2f1406 0x2f1de6  size 2528  520 条
 * 部分覆盖: 本节 520/1152 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f1406 ldrh r4, [r1, #0x2]
 *   @0x2f140a str r0, [sp, #0x2c]
 *   @0x2f140e str r3, [sp, #0x28]
 *   @0x2f1412 beq.w 0x2f1dd8 <ps_hints_apply+0x9d8>
 *   @0x2f1416 ldrsh.w r3, [r1]
 *   @0x2f141a cmp r3, #0x0
 *   @0x2f1422 movs r1, #0x0
 *   @0x2f1426 str r7, [sp, #0x30]
 *   @0x2f142a blx 0xb65b0 <memset@plt>
 *   @0x2f142e ldr r7, [sp, #0x24]
 *   @0x2f1432 movs r1, #0x28
 *   @0x2f1436 ldr r7, [r7]
 *   @0x2f143a str r7, [sp, #0x20]
 *   @0x2f143e add r7, sp, #0x50
 *   @0x2f1442 str r7, [sp, #0x4]
 *   @0x2f1446 bl 0x2e808e <ft_mem_realloc>
 *   @0x2f144a ldr r2, [sp, #0x50]
 *   @0x2f144e cmp r2, #0x0
 *   @0x2f145a str r2, [sp]
 *   @0x2f145e str r0, [sp, #0x4]
 *   @0x2f1462 bl 0x2e808e <ft_mem_realloc>
 *   @0x2f1466 ldr r2, [sp, #0x50]
 *   @0x2f146a cmp r2, #0x0
 *   @0x2f1476 ldr r6, [sp, #0x98]
 *   @0x2f147a movs r7, #0x28
 *   @0x2f147e ldrsh.w r3, [r5]
 *   @0x2f1482 str r3, [sp, #0x94]
 *   @0x2f1486 sub.w r9, r0, #0x8
 *   @0x2f148a cmp r2, r3
 *   @0x2f148e ldr r3, [r5, #0xc]
 *   @0x2f149e adds r3, r6, r1
 *   @0x2f14a6 mla r12, r7, lr, r6
 *   @0x2f14aa add.w r10, r3, #0x28
 *   @0x2f14ae mov r8, r3
 *   @0x2f14ba str.w r9, [r3, #0x8]
 *   @0x2f14be cmp.w r12, #0x1
 *   @0x2f14c2 beq 0x2f14e2 <ps_hints_apply+0xe2>
 *   @0x2f14d2 str r1, [r1, #-36]
 *   @0x2f14d6 str r8, [r11, #-40]
 *   @0x2f14da mov r8, r1
 *   @0x2f14e2 mla r4, r7, r4, r3
 *   @0x2f14e6 str r3, [r4, #-36]
 *   @0x2f14ea adds r2, #0x1
 *   @0x2f14ee mov r1, lr
 *   @0x2f14f2 ldr.w r9, [sp, #0x98]
 *   @0x2f14f6 mov.w r8, #0x0
 *   @0x2f14fa ldr r7, [r5, #0x4]
 *   @0x2f1502 ldr r3, [sp, #0x90]
 *   @0x2f1506 bhs 0x2f15d2 <ps_hints_apply+0x1d2>
 *   @0x2f1516 rsb r11, r9, r2
 *   @0x2f151a ldr r2, [r5, #0x8]
 *   @0x2f151e asr.w r11, r11, #0x3
 *   @0x2f1522 muls r3, r1, r3
 *   @0x2f152e itt pl
 *   @0x2f1532 strpl r2, [r4, #-28]
 *   @0x2f1536 add.w r2, r7, r3, lsl #3
 *   @0x2f153a ldr r1, [r6]
 *   @0x2f1542 rsb r12, r3, r1
 *   @0x2f1546 ldr r3, [r6, #0x4]
 *   @0x2f154e mov r0, r12
 *   @0x2f1552 mov r1, r3
 *   @0x2f156a subs r2, r0, r2
 *   @0x2f156e ldr r1, [r6, #0x4]
 *   @0x2f1572 rsb r11, r1, r0
 *   @0x2f1576 mov r0, r2
 *   @0x2f157a bl 0x2f01f0 <FT_Done_Memory+0x657c>
 *   @0x2f157e ldr r1, [r4, #-28]
 *   @0x2f1582 tst.w r1, #0x1
 *   @0x2f1586 uxtb r0, r0
 *   @0x2f158e ldr r3, [sp, #0x1c]
 *   @0x2f1596 orr r1, r1, #0x2
 *   @0x2f159a str r1, [r4, #-28]
 *   @0x2f159e b 0x2f15c8 <ps_hints_apply+0x1c8>
 *   @0x2f15a2 sxtb.w r1, r10
 *   @0x2f15a6 bne 0x2f15c8 <ps_hints_apply+0x1c8>
 *   @0x2f15aa beq 0x2f15ba <ps_hints_apply+0x1ba>
 *   @0x2f15ba mov r1, r3
 *   @0x2f15be mov r3, r11
 *   @0x2f15c6 bne 0x2f15ac <ps_hints_apply+0x1ac>
 *   @0x2f15ce adds r6, #0x8
 *   @0x2f15d2 ldr r7, [sp, #0x24]
 *   @0x2f15d6 movs r1, #0x0
 *   @0x2f15da str r7, [sp, #0xa8]
 *   @0x2f15e2 ldr r3, [sp, #0x94]
 *   @0x2f15e6 bhs 0x2f16da <ps_hints_apply+0x2da>
 *   @0x2f15ea add.w r2, r3, r7, lsl #3
 *   @0x2f15ee ldr r2, [r2, #0x4]
 *   @0x2f15f2 bls 0x2f16d6 <ps_hints_apply+0x2d6>
 *   @0x2f15fa ldr r4, [r4, #0x4]
 *   @0x2f15fe beq 0x2f16d6 <ps_hints_apply+0x2d6>
 *   @0x2f1602 ldr r3, [r6, #0x1c]
 *   @0x2f1606 ldr r1, [r6, #0x20]
 *   @0x2f1612 mov r5, r6
 *   @0x2f1616 cmp.w r11, #0x0
 *   @0x2f161a beq 0x2f15fa <ps_hints_apply+0x1fa>
 *   @0x2f161e ldr r2, [r5, #0x1c]
 *   @0x2f1626 ldr.w r1, [r9, #0x20]
 *   @0x2f162a subs.w r10, r2, r3
 *   @0x2f162e rsb r8, r1, r0
 *   @0x2f1632 bne 0x2f1646 <ps_hints_apply+0x246>
 *   @0x2f163a mov r5, r9
 *   @0x2f1642 bne 0x2f161e <ps_hints_apply+0x21e>
 *   @0x2f1646 mov r0, r12
 *   @0x2f164a mov r2, r10
 *   @0x2f164e str.w r12, [sp, #0x18]
 *   @0x2f1652 bl 0x2e51c4 <ft_corner_orientation>
 *   @0x2f1656 ldr.w r12, [sp, #0x18]
 *   @0x2f165a str r0, [sp, #0x34]
 *   @0x2f165e beq 0x2f163a <ps_hints_apply+0x23a>
 *   @0x2f1662 mov r6, r4
 *   @0x2f166a ldr r0, [sp, #0x3c]
 *   @0x2f166e ldr r2, [r4, #0x1c]
 *   @0x2f1672 it eq
 *   @0x2f167a ldr r0, [r4, #0x20]
 *   @0x2f1686 cmp.w r9, #0x0
 *   @0x2f168a bne 0x2f1690 <ps_hints_apply+0x290>
 *   @0x2f168e b 0x2f1668 <ps_hints_apply+0x268>
 *   @0x2f1692 mov r1, r8
 *   @0x2f1696 mov r3, r9
 *   @0x2f16a6 beq 0x2f168c <ps_hints_apply+0x28c>
 *   @0x2f16aa teq.w r0, r1
 *   @0x2f16ae bpl 0x2f16c6 <ps_hints_apply+0x2c6>
 *   @0x2f16b2 orr r3, r3, #0x4
 *   @0x2f16b6 str r3, [r5, #0xc]
 *   @0x2f16ba cmp r5, r6
 *   @0x2f16be ldr r3, [r6, #0xc]
 *   @0x2f16c6 cmp.w r12, #0x0
 *   @0x2f16ca bne 0x2f16d6 <ps_hints_apply+0x2d6>
 *   @0x2f16ce mov r8, r9
 *   @0x2f16d2 mov r5, r6
 *   @0x2f16d6 adds r7, #0x1
 *   @0x2f16da ldr r7, [sp, #0x2c]
 *   @0x2f16de ldr r3, [sp, #0x20]
 *   @0x2f16ee cbnz r0, 0x2f1702 <ps_hints_apply+0x302>
 *   @0x2f16f2 add.w r1, r7, #0x34
 *   @0x2f16f6 add.w r2, r7, #0x40
 *   @0x2f16fa ldr r3, [sp, #0x20]
 *   @0x2f1702 ldr r7, [sp, #0x50]
 *   @0x2f1706 cbz r7, 0x2f1730 <ps_hints_apply+0x330>
 *   @0x2f170a add r0, sp, #0xd4
 *   @0x2f170e bl 0x2f08c6 <FT_Done_Memory+0x6c52>
 *   @0x2f1712 add r0, sp, #0xac
 *   @0x2f1716 bl 0x2f08c6 <FT_Done_Memory+0x6c52>
 *   @0x2f171a mov r0, r4
 *   @0x2f171e bl 0x2e7336 <ft_mem_free>
 *   @0x2f1722 mov r0, r4
 *   @0x2f1726 movs r3, #0x0
 *   @0x2f172a bl 0x2e7336 <ft_mem_free>
 *   @0x2f172e b 0x2f1dde <ps_hints_apply+0x9de>
 *   @0x2f1732 ldr.w r7, [r3, #0xc8]
 *   @0x2f1736 ldr.w r3, [r3, #0x194]
 *   @0x2f173a str r7, [sp, #0x34]
 *   @0x2f173e mov r1, r3
 *   @0x2f1742 ldr.w r0, [r7, #0x1a0]
 *   @0x2f1746 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f174a add.w r5, r0, #0x20
 *   @0x2f174e mov r4, r0
 *   @0x2f1756 cmp r0, r5
 *   @0x2f175a ldr r0, [sp, #0x3c]
 *   @0x2f175e mov r2, r4
 *   @0x2f1766 mov r6, r0
 *   @0x2f176a mvn r1, #0x31
 *   @0x2f176e ldr r0, [sp, #0x34]
 *   @0x2f1776 add r1, r0
 *   @0x2f177a ldr r1, [sp, #0x34]
 *   @0x2f177e ldr r0, [sp, #0xa8]
 *   @0x2f1782 mov r2, r6
 *   @0x2f178a b 0x2f1792 <ps_hints_apply+0x392>
 *   @0x2f178e ldm r4!, {r2, r3, r6, r7}
 *   @0x2f1792 str r7, [sp, #0x44]
 *   @0x2f1796 ldr r7, [sp, #0x28]
 *   @0x2f179e strb.w r3, [sp, #0x109]
 *   @0x2f17a2 cmp r2, r3
 *   @0x2f17a6 movhi r2, #0x0
 *   @0x2f17aa cmp r7, #0x2
 *   @0x2f17b2 subs r0, r7, #0x4
 *   @0x2f17b6 adcs r3, r0
 *   @0x2f17ba mov.w r10, #0x0
 *   @0x2f17be strb.w r3, [sp, #0x10b]
 *   @0x2f17c2 adds.w r3, r7, #0xffffffff
 *   @0x2f17c6 add r7, sp, #0xac
 *   @0x2f17ca it ne
 *   @0x2f17ce strb.w r3, [sp, #0x10c]
 *   @0x2f17d2 add r0, sp, #0x90
 *   @0x2f17d6 bl 0x2f022e <FT_Done_Memory+0x65ba>
 *   @0x2f17da ldr r5, [sp, #0x94]
 *   @0x2f17de movs r3, #0x0
 *   @0x2f17e2 beq 0x2f183e <ps_hints_apply+0x43e>
 *   @0x2f17ee cbz r2, 0x2f183a <ps_hints_apply+0x43a>
 *   @0x2f17f2 ldr r0, [r0]
 *   @0x2f17f6 beq 0x2f185c <ps_hints_apply+0x45c>
 *   @0x2f17fa ldr r2, [r6, #0x1c]
 *   @0x2f17fe beq 0x2f17f2 <ps_hints_apply+0x3f2>
 *   @0x2f1802 mov r2, r7
 *   @0x2f1806 ldr r1, [r1, #0x4]
 *   @0x2f180a beq 0x2f183a <ps_hints_apply+0x43a>
 *   @0x2f1812 cmp lr, r6
 *   @0x2f1816 ldr r0, [r0, #0x1c]
 *   @0x2f181a bge 0x2f1822 <ps_hints_apply+0x422>
 *   @0x2f181e blt 0x2f1826 <ps_hints_apply+0x426>
 *   @0x2f1822 cmp lr, r6
 *   @0x2f1826 ldr r0, [r2, #0x10]
 *   @0x2f182e ldr r2, [r2, #0x4]
 *   @0x2f1832 bne 0x2f1826 <ps_hints_apply+0x426>
 *   @0x2f1836 mov r2, r1
 *   @0x2f183a adds r3, #0x1
 *   @0x2f183e movs r3, #0x0
 *   @0x2f1842 cmp r3, r2
 *   @0x2f1846 ldr r2, [sp, #0x98]
 *   @0x2f184a mla r2, r1, r3, r2
 *   @0x2f184e ldr r4, [r2, #0x10]
 *   @0x2f1852 bpl 0x2f1878 <ps_hints_apply+0x478>
 *   @0x2f1856 ldr r1, [r1]
 *   @0x2f185a bne 0x2f1860 <ps_hints_apply+0x460>
 *   @0x2f185e b 0x2f1840 <ps_hints_apply+0x440>
 *   @0x2f1862 ldr r0, [r1, #0x20]
 *   @0x2f1866 beq 0x2f1856 <ps_hints_apply+0x456>
 *   @0x2f186a ldr r6, [r6, #0x4]
 *   @0x2f186e beq 0x2f185c <ps_hints_apply+0x45c>
 *   @0x2f1872 cmp r0, r5
 *   @0x2f1876 b 0x2f187c <ps_hints_apply+0x47c>
 *   @0x2f187a mov r1, r2
 *   @0x2f187e ldr r1, [r2, #0x20]
 *   @0x2f1882 bge 0x2f1890 <ps_hints_apply+0x490>
 *   @0x2f1886 cmp r0, r1
 *   @0x2f188a orr r4, r4, #0x80
 *   @0x2f188e b 0x2f189c <ps_hints_apply+0x49c>
 *   @0x2f1892 ldr r0, [r6, #0x20]
 *   @0x2f1896 bge 0x2f185c <ps_hints_apply+0x45c>
 *   @0x2f189e b 0x2f185c <ps_hints_apply+0x45c>
 *   @0x2f18a2 ldr r5, [sp, #0xa8]
 *   @0x2f18a6 ldr r4, [r7]
 *   @0x2f18aa mov r0, r6
 *   @0x2f18ae mov r2, r10
 *   @0x2f18b2 bl 0x2f1142 <FT_Done_Memory+0x74ce>
 *   @0x2f18b6 subs r4, #0x1
 *   @0x2f18ba b 0x2f18a8 <ps_hints_apply+0x4a8>
 *   @0x2f18be movs r2, #0xcc
 *   @0x2f18c2 cmp.w r10, #0x0
 *   @0x2f18c6 ite ne
 *   @0x2f18d2 ldr r4, [r3]
 *   @0x2f18d6 ldr r3, [sp, #0xa8]
 *   @0x2f18e6 ite lt
 *   @0x2f18ea movge r7, #0x1e
 *   @0x2f18ee bls 0x2f1960 <ps_hints_apply+0x560>
 *   @0x2f18f2 cmp r3, #0x0
 *   @0x2f18f6 ldr r2, [r5, #0xc]
 *   @0x2f18fa mov.w r9, #0x28
 *   @0x2f18fe cmp r3, r2
 *   @0x2f1902 movhs r3, r2
 *   @0x2f1906 ldr r2, [sp, #0x90]
 *   @0x2f190a it hs
 *   @0x2f190e cmp r6, r3
 *   @0x2f1912 ldr r1, [sp, #0x98]
 *   @0x2f1916 ldr r0, [sp, #0x20]
 *   @0x2f191a mla r11, r9, r3, r1
 *   @0x2f191e mov r1, r5
 *   @0x2f192a mov r3, r7
 *   @0x2f192e mov r1, r11
 *   @0x2f1936 adds r5, #0x10
 *   @0x2f193a bne 0x2f195c <ps_hints_apply+0x55c>
 *   @0x2f193e ldr r4, [sp, #0x90]
 *   @0x2f1942 ldr r3, [r0, #0x20]
 *   @0x2f1946 bl 0x2f0154 <FT_Done_Memory+0x64e0>
 *   @0x2f194a str.w r8, [sp]
 *   @0x2f194e ldr r0, [sp, #0x20]
 *   @0x2f1952 mov r2, r4
 *   @0x2f1956 bl 0x2f0266 <FT_Done_Memory+0x65f2>
 *   @0x2f195a b 0x2f1962 <ps_hints_apply+0x562>
 *   @0x2f195e b 0x2f1904 <ps_hints_apply+0x504>
 *   @0x2f1962 ldr r5, [sp, #0x90]
 *   @0x2f1966 mov r2, r5
 *   @0x2f196a cbz r2, 0x2f1982 <ps_hints_apply+0x582>
 *   @0x2f196e cbz r1, 0x2f197c <ps_hints_apply+0x57c>
 *   @0x2f1972 lsls r7, r1, #0x1b
 *   @0x2f1976 orrpl r1, r1, #0x10
 *   @0x2f197a strpl r1, [r3, #0x10]
 *   @0x2f197e adds r3, #0x28
 *   @0x2f1982 cmp.w r10, #0x1
 *   @0x2f1986 beq 0x2f1996 <ps_hints_apply+0x596>
 *   @0x2f198a movs r2, #0xcc
 *   @0x2f1996 ldr r7, [sp, #0x24]
 *   @0x2f199a mov r1, r5
 *   @0x2f19a2 beq 0x2f1988 <ps_hints_apply+0x588>
 *   @0x2f19aa beq 0x2f19bc <ps_hints_apply+0x5bc>
 *   @0x2f19ae beq 0x2f19bc <ps_hints_apply+0x5bc>
 *   @0x2f19b6 beq 0x2f19bc <ps_hints_apply+0x5bc>
 *   @0x2f19ba bne 0x2f1a64 <ps_hints_apply+0x664>
 *   @0x2f19be lsls r6, r3, #0x1b
 *   @0x2f19c2 ldr r0, [sp, #0x24]
 *   @0x2f19c6 add.w r6, r0, #0x1a0
 *   @0x2f19ca ldr.w r7, [r0, #0x19c]
 *   @0x2f19ce cbz r7, 0x2f1a12 <ps_hints_apply+0x612>
 *   @0x2f19d2 rsb r12, r0, r3
 *   @0x2f19d6 ldr r0, [sp, #0x24]
 *   @0x2f19e2 blt 0x2f1a12 <ps_hints_apply+0x612>
 *   @0x2f19e6 add r0, r8
 *   @0x2f19ea bgt 0x2f1a0c <ps_hints_apply+0x60c>
 *   @0x2f19ee ldrb.w r8, [r0, #0x9bc]
 *   @0x2f19f2 cmp.w r8, #0x0
 *   @0x2f19f6 bne 0x2f1a00 <ps_hints_apply+0x600>
 *   @0x2f19fe bgt 0x2f1a0c <ps_hints_apply+0x60c>
 *   @0x2f1a02 str r0, [r2, #0x24]
 *   @0x2f1a06 orr r0, r0, #0x30
 *   @0x2f1a0a str r0, [r2, #0x10]
 *   @0x2f1a0e adds r6, #0x20
 *   @0x2f1a12 ldr r0, [sp, #0x24]
 *   @0x2f1a1e cbz r7, 0x2f1a64 <ps_hints_apply+0x664>
 *   @0x2f1a22 rsb r12, r3, r0
 *   @0x2f1a26 ldr r0, [sp, #0x24]
 *   @0x2f1a32 blt 0x2f1a64 <ps_hints_apply+0x664>
 *   @0x2f1a36 rsb r0, r8, r0
 *   @0x2f1a3a cmp r3, r0
 *   @0x2f1a3e ldr r0, [sp, #0x24]
 *   @0x2f1a4a ldr.w r0, [r0, #0x9b4]
 *   @0x2f1a4e cmp r12, r0
 *   @0x2f1a52 ldr r0, [r6, #0x1c]
 *   @0x2f1a56 ldr r0, [r2, #0x10]
 *   @0x2f1a5e subs r7, #0x1
 *   @0x2f1a62 b 0x2f1a1e <ps_hints_apply+0x61e>
 *   @0x2f1a66 adds r2, #0x28
 *   @0x2f1a6a ldr r3, [r4, #0x18]
 *   @0x2f1a6e subs r5, #0x1
 *   @0x2f1a72 cmp r5, #0x0
 *   @0x2f1a76 b 0x2f1ac0 <ps_hints_apply+0x6c0>
 *   @0x2f1a7a ldr r7, [r3, #0x8]
 *   @0x2f1a82 lsls r0, r2, #0x15
 *   @0x2f1a86 ldr r3, [r3, #0xc]
 *   @0x2f1a8a str r7, [r4, #0x24]
 *   @0x2f1a8e ldr r0, [r4, #0x1c]
 *   @0x2f1a92 subs r0, r0, r2
 *   @0x2f1a96 ble 0x2f1aa4 <ps_hints_apply+0x6a4>
 *   @0x2f1a9a cmp r0, r2
 *   @0x2f1a9e ldr r3, [r3, #0xc]
 *   @0x2f1aa2 add r7, r3
 *   @0x2f1aa6 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f1aaa b 0x2f1ab2 <ps_hints_apply+0x6b2>
 *   @0x2f1aae bl 0x2e4d3c <FT_MulDiv>
 *   @0x2f1ab2 add r0, r7
 *   @0x2f1ab6 ldr r3, [r4, #0x10]
 *   @0x2f1abe b 0x2f1a6e <ps_hints_apply+0x66e>
 *   @0x2f1ac2 movs r2, #0xcc
 *   @0x2f1ac6 movs r6, #0x28
 *   @0x2f1aca mla r3, r2, r10, r3
 *   @0x2f1ace mov r2, r4
 *   @0x2f1ad2 ldr.w r8, [r3, #0xc8]
 *   @0x2f1ad6 ldr r3, [sp, #0x90]
 *   @0x2f1ade cmp r2, r6
 *   @0x2f1ae2 ldr r1, [r2, #0x10]
 *   @0x2f1ae6 lsls r1, r1, #0x1b
 *   @0x2f1aea addmi r3, #0x1
 *   @0x2f1aee cmp r3, #0x0
 *   @0x2f1af6 bls 0x2f1b16 <ps_hints_apply+0x716>
 *   @0x2f1afa add r1, sp, #0x50
 *   @0x2f1afe movs r2, #0x0
 *   @0x2f1b02 movs r1, #0x4
 *   @0x2f1b06 bl 0x2e808e <ft_mem_realloc>
 *   @0x2f1b0a ldr r3, [sp, #0x50]
 *   @0x2f1b0e cmp r3, #0x0
 *   @0x2f1b16 add r5, sp, #0x50
 *   @0x2f1b1a mov.w r9, #0x0
 *   @0x2f1b1e cmp r3, r6
 *   @0x2f1b22 ldr r2, [r3, #0x10]
 *   @0x2f1b26 bpl 0x2f1b4a <ps_hints_apply+0x74a>
 *   @0x2f1b2e bls 0x2f1b3c <ps_hints_apply+0x73c>
 *   @0x2f1b36 ldr r7, [r2, #0x1c]
 *   @0x2f1b3a bgt 0x2f1b44 <ps_hints_apply+0x744>
 *   @0x2f1b3e add.w r9, r9, #0x1
 *   @0x2f1b42 b 0x2f1b4a <ps_hints_apply+0x74a>
 *   @0x2f1b4a adds r3, #0x28
 *   @0x2f1b4e add.w r11, r9, #0x40000000
 *   @0x2f1b52 add.w r11, r11, #0xffffffff
 *   @0x2f1b56 lsl.w r11, r11, #0x2
 *   @0x2f1b5a add.w r3, r5, r11
 *   @0x2f1b5e add.w r11, r11, #0x4
 *   @0x2f1b62 add r11, r5
 *   @0x2f1b66 cmp r4, r6
 *   @0x2f1b6a ldr r2, [r4, #0x10]
 *   @0x2f1b6e bmi 0x2f1c42 <ps_hints_apply+0x842>
 *   @0x2f1b72 lsls r1, r3, #0x1e
 *   @0x2f1b76 ldrsb.w r1, [r4, #0x14]
 *   @0x2f1b7a cmp r1, #0x4
 *   @0x2f1b7e ldrsb.w r0, [r4, #0x15]
 *   @0x2f1b82 cmp r0, r1
 *   @0x2f1b86 lsls r2, r2, #0x19
 *   @0x2f1b8a lsls r7, r3, #0x1d
 *   @0x2f1b8e bic r3, r3, #0x2
 *   @0x2f1b92 str r3, [r4, #0xc]
 *   @0x2f1b96 cmp r3, r9
 *   @0x2f1b9a ldr.w r2, [r5, r3, lsl #2]
 *   @0x2f1b9e ldr r1, [r2, #0x1c]
 *   @0x2f1ba2 cmp r1, r2
 *   @0x2f1ba6 cbnz r3, 0x2f1bc0 <ps_hints_apply+0x7c0>
 *   @0x2f1baa mov r1, r8
 *   @0x2f1bae ldr r0, [r3, #0x1c]
 *   @0x2f1bb2 subs r0, r2, r0
 *   @0x2f1bba b 0x2f1c38 <ps_hints_apply+0x838>
 *   @0x2f1bbe b 0x2f1b96 <ps_hints_apply+0x796>
 *   @0x2f1bc6 subs r3, #0x1
 *   @0x2f1bce cbz r3, 0x2f1be0 <ps_hints_apply+0x7e0>
 *   @0x2f1bd6 ldr r2, [r4, #0x1c]
 *   @0x2f1bda blt 0x2f1be0 <ps_hints_apply+0x7e0>
 *   @0x2f1bde b 0x2f1bce <ps_hints_apply+0x7ce>
 *   @0x2f1be2 ldr r0, [r4, #0x1c]
 *   @0x2f1be6 ldr r7, [sp, #0x40]
 *   @0x2f1bea ldr r3, [r7]
 *   @0x2f1bee ldr r3, [r3, #0x1c]
 *   @0x2f1bf2 str r2, [sp, #0x14]
 *   @0x2f1bfa add r0, r2
 *   @0x2f1bfe ldr.w r1, [r5, r3, lsl #2]
 *   @0x2f1c02 ldr.w r3, [lr, #0x1c]
 *   @0x2f1c06 cmp r0, r3
 *   @0x2f1c0a ldr.w r3, [lr, #0x24]
 *   @0x2f1c0e str r3, [r4, #0x24]
 *   @0x2f1c12 ldr r2, [r1, #0x1c]
 *   @0x2f1c16 cmp r0, r2
 *   @0x2f1c1a str r1, [r4, #0x24]
 *   @0x2f1c1e ldr.w r12, [lr, #0x24]
 *   @0x2f1c22 subs r0, r0, r3
 *   @0x2f1c26 rsb r1, r12, r1
 *   @0x2f1c2a str.w r12, [sp, #0x18]
 *   @0x2f1c2e bl 0x2e4d3c <FT_MulDiv>
 *   @0x2f1c32 ldr.w r12, [sp, #0x18]
 *   @0x2f1c36 add r0, r12
 *   @0x2f1c3a ldr r3, [r4, #0x10]
 *   @0x2f1c42 adds r4, #0x28
 *   @0x2f1c46 ldr r7, [sp, #0x38]
 *   @0x2f1c4a beq 0x2f1c54 <ps_hints_apply+0x854>
 *   @0x2f1c4e mov r1, r5
 *   @0x2f1c56 movs r2, #0xcc
 *   @0x2f1c5e adds r3, #0x4
 *   @0x2f1c62 ldr.w r8, [r3, #0xc4]
 *   @0x2f1c66 ldr.w r3, [r3, #0xc8]
 *   @0x2f1c6a str r3, [sp, #0x48]
 *   @0x2f1c6e add.w r9, r3, #0x8
 *   @0x2f1c72 ldr r7, [sp, #0x28]
 *   @0x2f1c76 beq 0x2f1d70 <ps_hints_apply+0x970>
 *   @0x2f1c7e ldr r4, [r9, #-4]
 *   @0x2f1c82 movs r0, #0x0
 *   @0x2f1c86 mov r2, r6
 *   @0x2f1c8e bhs 0x2f1ca2 <ps_hints_apply+0x8a2>
 *   @0x2f1c92 lsls r5, r1, #0x1a
 *   @0x2f1c96 cmp r7, #0x0
 *   @0x2f1c9a moveq r7, r2
 *   @0x2f1c9e adds r2, #0x28
 *   @0x2f1ca2 cmp r0, #0x1
 *   @0x2f1ca6 bhi 0x2f1cda <ps_hints_apply+0x8da>
 *   @0x2f1caa ldr r0, [r7, #0x1c]
 *   @0x2f1cae ldr r5, [r7, #0x24]
 *   @0x2f1cb6 str r5, [sp, #0x48]
 *   @0x2f1cba cmp r6, r7
 *   @0x2f1cbe ldr r0, [r6, #0x1c]
 *   @0x2f1cc2 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f1cc6 ldr r2, [sp, #0x48]
 *   @0x2f1cca str r0, [r6, #0x24]
 *   @0x2f1cce cmp r6, r4
 *   @0x2f1cd2 b 0x2f1d64 <ps_hints_apply+0x964>
 *   @0x2f1cd6 lsls r4, r1, #0x1a
 *   @0x2f1cda mov r2, r7
 *   @0x2f1cde ldr r7, [r7, #0x4]
 *   @0x2f1ce2 bne 0x2f1cd4 <ps_hints_apply+0x8d4>
 *   @0x2f1ce6 ldr r7, [r7, #0x4]
 *   @0x2f1cea lsls r0, r1, #0x1a
 *   @0x2f1cee ldr r5, [r2, #0x1c]
 *   @0x2f1cf2 ldr r0, [r2, #0x24]
 *   @0x2f1cf6 ldr r3, [r7, #0x24]
 *   @0x2f1cfa mov r4, r0
 *   @0x2f1cfe rsb r11, r0, r3
 *   @0x2f1d02 b 0x2f1d0e <ps_hints_apply+0x90e>
 *   @0x2f1d0a mov r4, r3
 *   @0x2f1d0e cmp r6, #0x0
 *   @0x2f1d12 mov r0, r11
 *   @0x2f1d16 str r2, [sp, #0x14]
 *   @0x2f1d1e str r0, [sp, #0x40]
 *   @0x2f1d22 mov.w r3, #0x10000
 *   @0x2f1d26 str r3, [sp, #0x40]
 *   @0x2f1d2a add r11, r4
 *   @0x2f1d2e subs r0, r0, r5
 *   @0x2f1d32 bgt 0x2f1d38 <ps_hints_apply+0x938>
 *   @0x2f1d36 b 0x2f1d4c <ps_hints_apply+0x94c>
 *   @0x2f1d3a blt 0x2f1d4a <ps_hints_apply+0x94a>
 *   @0x2f1d3e mov r1, r8
 *   @0x2f1d42 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f1d46 add r0, r11
 *   @0x2f1d4a ldr r1, [sp, #0x40]
 *   @0x2f1d4e bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f1d52 add r0, r4
 *   @0x2f1d56 str r0, [r2, #0x24]
 *   @0x2f1d5a cmp r2, r7
 *   @0x2f1d5e ldr r2, [sp, #0x4c]
 *   @0x2f1d62 bne 0x2f1cda <ps_hints_apply+0x8da>
 *   @0x2f1d66 add.w r9, r9, #0x8
 *   @0x2f1d6a subs r3, #0x1
 *   @0x2f1d6e b 0x2f1c72 <ps_hints_apply+0x872>
 *   @0x2f1d72 ldr r3, [sp, #0x98]
 *   @0x2f1d76 ldr r0, [r1, #0x8]
 *   @0x2f1d7a cmp r7, r1
 *   @0x2f1d7e ldr r1, [r3, #0x24]
 *   @0x2f1d82 cmp.w r10, #0x0
 *   @0x2f1d86 bne 0x2f1d8e <ps_hints_apply+0x98e>
 *   @0x2f1d8e add r4, r2
 *   @0x2f1d92 ldr r1, [r3, #0x10]
 *   @0x2f1d96 bpl 0x2f1da8 <ps_hints_apply+0x9a8>
 *   @0x2f1d9a cmp.w r10, #0x0
 *   @0x2f1d9e ite ne
 *   @0x2f1da2 moveq r4, #0x20
 *   @0x2f1da6 strb r1, [r0, r7]
 *   @0x2f1daa adds r7, #0x1
 *   @0x2f1dae ldr r7, [sp, #0x44]
 *   @0x2f1db2 movs r0, #0x0
 *   @0x2f1db6 str r0, [sp]
 *   @0x2f1dba ldr r0, [sp, #0xa8]
 *   @0x2f1dbe bl 0x2f0444 <FT_Done_Memory+0x67d0>
 *   @0x2f1dc2 add.w r10, r10, #0x1
 *   @0x2f1dc6 ldr r7, [sp, #0x20]
 *   @0x2f1dd2 beq.w 0x2f1708 <ps_hints_apply+0x308>
 *   @0x2f1dd6 b 0x2f17d2 <ps_hints_apply+0x3d2>
 *   @0x2f1dda b 0x2f1dde <ps_hints_apply+0x9de>
 *   @0x2f1dde ldr r0, [sp, #0x2c]
 *   @0x2f1de2 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ anon_2f1de8  0x2f1de8  size 28704  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2f8e08 0x2f8e18  size 16  4 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f8e08 blx 0xfe3682f2 <b2_toiTime+0xfffffffffdc0ee4e>
 *
 * ══ anonT_2f8e0a  0x2f8e0a  size 1170  本节 54 条（Thumb-2 半字段）｜入度 0
 * @func 0x2f8e0c 0x2f9230  size 1060  54 条
 * 部分覆盖: 本节 54/454 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f8e0c b 0x16c5614 <b2_toiTime+0xf6c170>
 *   @0x2f8e10 .word 0xf50070e2
 *   @0x2f8e14 ldmdane r11, {lr}
 *   @0x2f8e2c ldrmi r1, [lr], -r4, lsr #2
 *   @0x2f8e64 bne 0xfe9851dc <b2_toiTime+0xfffffffffe22bd38>
 *   @0x2f8e6c rfeia r0!
 *   @0x2f8e70 andslt r3, r9, #222
 *   @0x2f8ecc .word 0xf8c43008
 *   @0x2f8ed0 .word 0x63a300b0
 *   @0x2f8edc andlt r2, r5, r0, asr #32
 *   @0x2f8f04 andlt r2, r9, #4, #2
 *   @0x2f8f10 andlt r2, r9, #4, #2
 *   @0x2f8f1c andlt r2, r9, #4, #2
 *   @0x2f8f28 b 0x13c1240 <b2_toiTime+0xc67d9c>
 *   @0x2f8f2c andslt r2, r11, #67108864
 *   @0x2f8f48 swpblt r2, r12, [r10]
 *   @0x2f8f64 bvs 0x13f9b68 <b2_toiTime+0xca06c4>
 *   @0x2f8f70 blvs 0xfe3b9f88 <b2_toiTime+0xfffffffffdc60ae4>
 *   @0x2f8f98 ldrhlt r1, [r2, -r8]
 *   @0x2f8fa4 .word 0xf8c030b0
 *   @0x2f8fa8 bne 0xff5412a0 <b2_toiTime+0xfffffffffede7dfc>
 *   @0x2f8fc4 stmdale r0!, {r0, r1, r2, r3, r5, r6, r7, pc}
 *   @0x2f8fd8 vhadd.s8 d8, d16, d30
 *   @0x2f8fdc blmi 0xfe8d92b0 <b2_toiTime+0xfffffffffe17fe0c>
 *   @0x2f8fe4 .word 0xf5008125
 *   @0x2f8fe8 ldrbmi r7, [r0, -r7, ror #1]!
 *   @0x2f9010 ldmdale r0, {r2, r5, r6, r7, pc}
 *   @0x2f903c stmdale r6, {r0, r4, r6, r7, pc}
 *   @0x2f9048 .word 0x30ee80f3
 *   @0x2f9054 blmi 0xfe359378 <b2_toiTime+0xfffffffffdbffed4>
 *   @0x2f905c .word 0xf50080e9
 *   @0x2f9060 .word 0x477070de
 *   @0x2f9074 ldmdale r6, {r1, r6, r7, pc}
 *   @0x2f9088 .word 0xf50080d3
 *   @0x2f908c ldrbmi r7, [r0, -r1, asr #1]!
 *   @0x2f90ac stmdale r6, {r0, r3, r5, r7, pc}
 *   @0x2f90c4 blmi 0x1e1934c <b2_toiTime+0x16bfea8>
 *   @0x2f90cc .word 0xf50080b1
 *   @0x2f90d0 ldrbmi r7, [r0, -r8, asr #1]!
 *   @0x2f90e4 stmdale r6, {r1, r2, r4, r7, pc}
 *   @0x2f90fc blmi 0x1b99338 <b2_toiTime+0x143fe94>
 *   @0x2f9104 .word 0xf5008095
 *   @0x2f9108 .word 0x4770709f
 *   @0x2f911c .word 0xf5008089
 *   @0x2f9120 .word 0x4770709d
 *   @0x2f9138 blhs 0x3459f8
 *   @0x2f9140 .word 0x47700230
 *   @0x2f91dc ldrbmi r7, [r0, -r1, ror #1]!
 *   @0x2f91f0 .word 0x477070bf
 *   @0x2f91fc ldrbmi r7, [r0, -r5, asr #1]!
 *   @0x2f9208 ldrbmi r7, [r0, -r4, asr #1]!
 *   @0x2f9214 .word 0x477070f3
 *   @0x2f9220 .word 0x4770709e
 *   @0x2f922c .word 0x47707098
 *
 * ══ anon_2f929c  0x2f929c  size 2072  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2f9ab4 0x2f9abc  size 8  2 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f9ab4 push {r4, r5, r6, r7, r8, pc}
 *
 * ══ anonT_2f9ab6  0x2f9ab6  size 1112  本节 77 条（Thumb-2 半字段）｜入度 0
 * @func 0x2f9ab8 0x2f9f10  size 1112  77 条
 * 部分覆盖: 本节 77/500 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f9ab8 .word 0x460447f0
 *   @0x2f9ac8 .word 0xf04f0624
 *   @0x2f9acc .word 0xf04f0a01
 *   @0x2f9ad0 strmi r0, [r0], r6, lsl #19
 *   @0x2f9ae0 .word 0xb10b3235
 *   @0x2f9af8 bl 0x341b8c
 *   @0x2f9afc stchi p3, c0, [r1, #524]!
 *   @0x2f9b20 strmi r1, [sp], #-336
 *   @0x2f9b38 addmi r0, r11, r6, lsl #2
 *   @0x2f9b48 cmnlt r9, r7, ror #4
 *   @0x2f9b54 stmiblt r1!, {r0, r3, r5, r6, r9, r12}
 *   @0x2f9b60 ldmdblt r9, {r4, r5, r8, r12}
 *   @0x2f9b80 .word 0xf10a900c
 *   @0x2f9b84 str r0, [r5, r1, lsl #20]!
 *   @0x2f9b94 .word 0xf8c032ff
 *   @0x2f9b98 .word 0xf8c02130
 *   @0x2f9b9c andhs r2, r0, r4, lsr r1
 *   @0x2f9ba4 .word 0x47700070
 *   @0x2f9bc8 .word 0xf8140581
 *   @0x2f9bcc bl 0x415c58 <g_RomDisk+0x1e438>
 *   @0x2f9bd0 stmdavc r11!, {r1, r2, r7, r10} ^
 *   @0x2f9bd8 stmvc pc!, {r0, r1, r2, r8, r9, sp, lr} ^
 *   @0x2f9bf4 stmibvc pc!, {r0, r1, r2, r10, sp, lr} ^
 *   @0x2f9c04 .word 0xf8140541
 *   @0x2f9c08 bl 0x415c54 <g_RomDisk+0x1e434>
 *   @0x2f9c0c stmdavc r11!, {r1, r2, r6, r10} ^
 *   @0x2f9c28 rsbeq r2, r4, r7, lsl #8
 *   @0x2f9c38 addmi r0, r3, #172, #4
 *   @0x2f9c70 blhs 0x306748 <TT_New_Context+0x6540>
 *   @0x2f9c78 .word 0xf880070c
 *   @0x2f9c7c .word 0xf1003070
 *   @0x2f9c80 svcgt #0xf0630
 *   @0x2f9c88 stm r6, {r0, r1, r2}
 *   @0x2f9c8c strtmi r0, [r6], -r7
 *   @0x2f9ca0 .word 0x071a30b0
 *   @0x2f9cbc .word 0xf7ff0048
 *   @0x2f9cc0 blvs 0xfeb77f58 <b2_toiTime+0xfffffffffe41eab4>
 *   @0x2f9cc8 strtvs r0, [r0], #-63
 *   @0x2f9cd8 strbtvs r0, [r0], #-63
 *   @0x2f9ce0 .word 0xf1b83070
 *   @0x2f9ce4 teqle r11, r0, lsl #30
 *   @0x2f9cf4 orreq r1, r0, r4, asr #32
 *   @0x2f9d08 blvs 0x1b78068 <b2_toiTime+0x141ebc4>
 *   @0x2f9d10 .word 0xf7ff004c
 *   @0x2f9d14 eorlo pc, r0, r10, ror r8
 *   @0x2f9d2c strbvs r1, [r2, #0x54]!
 *   @0x2f9d38 strvs pc, [r0, #-0x8be]!
 *   @0x2f9d44 ssaxmi r3, r9, r4
 *   @0x2f9d4c .word 0xf44ff8b4
 *   @0x2f9d50 strvs r3, [r3, #-0x380]!
 *   @0x2f9d58 rscvs r3, r6, #-67108861
 *   @0x2f9d64 ldrshhs r8, [r7], r0
 *   @0x2f9d7c .word 0x4620fbd3
 *   @0x2f9d84 andhs pc, r0, pc, ror #30
 *   @0x2f9d8c .word 0xf104321c
 *   @0x2f9d90 cdpvs p2, #0xd, c0, c11, c12, #0x0
 *   @0x2f9da8 andhs pc, r0, sp, asr pc
 *   @0x2f9dc0 bge 0x346638
 *   @0x2f9de4 stmdavs r3!, {r0, r4, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f9df4 stmiblt r8, {r0, r1, r2, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f9e38 strmi r1, [r4], -lr, lsr #2
 *   @0x2f9e44 ldrmi r8, [r8], -r12
 *   @0x2f9e58 rfeib r4!
 *   @0x2f9e5c cmplt r1, r0, lsr r1
 *   @0x2f9e70 ldrtmi pc, [r0], #-3941
 *   @0x2f9e78 push {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2f9e7c .word 0x460e43f8
 *   @0x2f9e98 ldmdblt r3!, {r0, r1, r2, r5, r6, r9, r12, sp} ^
 *   @0x2f9ea4 shadd16mi r8, r8, r0
 *   @0x2f9eb8 ldmibvs r3!, {r0, r2, r4, r5}
 *   @0x2f9ec0 ldrbpl r0, [r10, #-0x208]
 *   @0x2f9edc tstlt r3, r8, ror #4
 *   @0x2f9eec bl 0x3c27d4 <error_g0017+0x1b478>
 *   @0x2f9ef0 .word 0xf8d808c5
 *   @0x2f9ef4 .word 0xf7ea9004
 *   @0x2f9ef8 strbmi pc, [r8], #-3873
 *   @0x2f9f0c push {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ anon_2f9f10  0x2f9f10  size 344  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2fa068 0x2fa06c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2fa068 ldclt p0, c11, [r0, #-60]!
 *
 * ══ anon_2fa330  0x2fa330  size 4952  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2fb688 0x2fb68c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2fb688 ldclt p2, c4, [r8, #-384]!
 *
 * ══ anon_2fc4e8  0x2fc4e8  size 2312  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2fcdf0 0x2fcdf4  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2fcdf0 andeq r1, r9, r5, lsl lr
 *
 * ══ TT_RunIns  0x2fcdf4  size 7804  本节 1418 条（Thumb-2 半字段）｜入度 110
 * @func 0x2fcdfa 0x2fec72  size 7800  1418 条
 * 部分覆盖: 本节 1418/3368 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2fcdfa ldr r5, [r0]
 *   @0x2fcdfe ldr r3, [r5, #0x60]
 *   @0x2fce02 cmp r3, #0x28
 *   @0x2fce06 ldr r3, [r5, #0x8]
 *   @0x2fce0a bmi 0x2fce1a <TT_RunIns+0x26>
 *   @0x2fce1a movs r3, #0x0
 *   @0x2fce22 ldr.w r0, [r4, #0x180]
 *   @0x2fce26 strb.w r3, [r4, #0x267]
 *   @0x2fce2a adds r3, r6, r0
 *   @0x2fce36 strb.w r2, [r4, #0x269]
 *   @0x2fce3a cmp r3, #0x1e
 *   @0x2fce3e movlo r3, #0x1e
 *   @0x2fce46 str.w r2, [r4, #0x274]
 *   @0x2fce4a it hi
 *   @0x2fce52 cbz r6, 0x2fce72 <TT_RunIns+0x7e>
 *   @0x2fce56 cmp r6, #0x32
 *   @0x2fce5a movlt r6, #0x32
 *   @0x2fce62 blx 0x318c48 <__udivsi3>
 *   @0x2fce66 b 0x2fce6a <TT_RunIns+0x76>
 *   @0x2fce6a add r6, r0
 *   @0x2fce72 muls r1, r0, r1
 *   @0x2fce76 it lo
 *   @0x2fce7a str.w r1, [r4, #0x270]
 *   @0x2fce7e ldr r3, [r5, #0x10]
 *   @0x2fce82 muls r3, r2, r3
 *   @0x2fce8a ldrh.w r2, [r4, #0xdc]
 *   @0x2fce8e it hi
 *   @0x2fce9e str.w r3, [r4, #0x104]
 *   @0x2fcea2 ldrh.w r3, [r4, #0xde]
 *   @0x2fcea6 cmp r2, r3
 *   @0x2fceaa ldr.w r3, [pc, #0xbc4]
 *   @0x2fceae add r3, pc
 *   @0x2fceba str.w r3, [r4, #0x258]
 *   @0x2fcebe ldr.w r3, [pc, #0xbb8]
 *   @0x2fcec2 add r3, pc
 *   @0x2fcece b 0x2fcef4 <TT_RunIns+0x100>
 *   @0x2fced6 str.w r3, [r4, #0x254]
 *   @0x2fceda ldr.w r3, [pc, #0xba8]
 *   @0x2fcede add r3, pc
 *   @0x2fceea str.w r3, [r4, #0x25c]
 *   @0x2fceee ldr.w r3, [pc, #0xb9c]
 *   @0x2fcef2 add r3, pc
 *   @0x2fcefa bl 0x2f9460 <ps_hints_apply+0x8060>
 *   @0x2fcefe ldrb.w r3, [r4, #0x13c]
 *   @0x2fcf02 cmp r3, #0x7
 *   @0x2fcf06 tbb [pc, r3]
 *   @0x2fcf0a lsrs r4, r2, #0x20
 *   @0x2fcf0e lsls r4, r1, #0x10
 *   @0x2fcf12 ldr.w r3, [pc, #0xb7c]
 *   @0x2fcf16 add r3, pc
 *   @0x2fcf1a ldr.w r3, [pc, #0xb78]
 *   @0x2fcf1e add r3, pc
 *   @0x2fcf22 ldr.w r3, [pc, #0xb74]
 *   @0x2fcf26 add r3, pc
 *   @0x2fcf2a ldr.w r3, [pc, #0xb70]
 *   @0x2fcf2e add r3, pc
 *   @0x2fcf32 ldr.w r3, [pc, #0xb6c]
 *   @0x2fcf36 add r3, pc
 *   @0x2fcf3a ldr.w r3, [pc, #0xb68]
 *   @0x2fcf3e add r3, pc
 *   @0x2fcf42 ldr.w r3, [pc, #0xb64]
 *   @0x2fcf46 add r3, pc
 *   @0x2fcf4a ldr.w r3, [pc, #0xb60]
 *   @0x2fcf4e add r3, pc
 *   @0x2fcf5a ldr.w r7, [pc, #0xb58]
 *   @0x2fcf5e add r6, pc
 *   @0x2fcf62 add r7, pc
 *   @0x2fcf66 str r7, [sp, #0x3c]
 *   @0x2fcf7a ldrsb.w r1, [r8, r2]
 *   @0x2fcf7e strb.w r2, [r4, #0x174]
 *   @0x2fcf82 cmp r1, #0x0
 *   @0x2fcf8a adds r6, r3, #0x1
 *   @0x2fcf8e bge.w 0x2fec56 <TT_RunIns+0x1e62>
 *   @0x2fcf92 add r5, r3
 *   @0x2fcf96 smulbb r1, r1, r5
 *   @0x2fcf9a rsb.w r1, r1, #0x2
 *   @0x2fcf9e str.w r1, [r4, #0x178]
 *   @0x2fcfa2 ldr.w r1, [r4, #0x178]
 *   @0x2fcfa6 add r3, r1
 *   @0x2fcfaa bgt.w 0x2fec56 <TT_RunIns+0x1e62>
 *   @0x2fcfae ldr.w r3, [pc, #0xb08]
 *   @0x2fcfb2 add r3, pc
 *   @0x2fcfb6 ldr r3, [r4, #0x10]
 *   @0x2fcfc2 cmp r3, #0x0
 *   @0x2fcfc6 ldrb.w r3, [r4, #0x235]
 *   @0x2fcfca cbnz r3, 0x2fcfd0 <TT_RunIns+0x1dc>
 *   @0x2fcfce b 0x2fcfd6 <TT_RunIns+0x1e2>
 *   @0x2fcfd2 b.w 0x2fec58 <TT_RunIns+0x1e64>
 *   @0x2fcfd6 ldrb.w r2, [r4, #0x174]
 *   @0x2fcfda ldr.w r12, [sp, #0x3c]
 *   @0x2fcfde add r2, r12
 *   @0x2fcfea ldr r2, [r4, #0x18]
 *   @0x2fcff2 uxth r3, r3
 *   @0x2fcff6 movs r3, #0x0
 *   @0x2fcffa ldrb.w r3, [r4, #0x174]
 *   @0x2fcffe cmp r3, #0x91
 *   @0x2fd002 ldr r2, [r4]
 *   @0x2fd00a ldr r2, [r2]
 *   @0x2fd00e add r1, r2
 *   @0x2fd012 b 0x2fd02a <TT_RunIns+0x236>
 *   @0x2fd01a add r2, r3
 *   @0x2fd022 and r1, r1, #0xf
 *   @0x2fd026 add r2, r1
 *   @0x2fd02a ldr r2, [r4, #0x14]
 *   @0x2fd02e cmp r1, r2
 *   @0x2fd032 movs r3, #0x82
 *   @0x2fd03a movs r0, #0x1
 *   @0x2fd03e movs r1, #0x0
 *   @0x2fd046 add.w r7, r5, r6, lsl #2
 *   @0x2fd04a cmp r3, #0x92
 *   @0x2fd056 lsls r3, r2, #0x2
 *   @0x2fd05a lsls r3, r2, #0x2
 *   @0x2fd05e lsls r3, r2, #0x2
 *   @0x2fd062 lsls r1, r6, #0x2
 *   @0x2fd066 lsls r6, r0, #0x3
 *   @0x2fd06a lsls r4, r4, #0x3
 *   @0x2fd06e lsls r2, r7, #0x3
 *   @0x2fd072 lsls r4, r1, #0x4
 *   @0x2fd076 lsls r1, r0, #0x8
 *   @0x2fd07a lsls r5, r1, #0x8
 *   @0x2fd07e lsls r1, r1, #0x9
 *   @0x2fd082 lsls r1, r5, #0xa
 *   @0x2fd086 lsls r4, r7, #0xa
 *   @0x2fd08a lsls r3, r1, #0xb
 *   @0x2fd08e lsls r5, r4, #0xb
 *   @0x2fd092 lsls r1, r6, #0xb
 *   @0x2fd096 lsrs r2, r5, #0x16
 *   @0x2fd09a lsls r3, r0, #0xc
 *   @0x2fd09e lsls r0, r2, #0xc
 *   @0x2fd0a2 lsls r3, r0, #0xd
 *   @0x2fd0a6 lsls r4, r7, #0xd
 *   @0x2fd0aa lsls r1, r3, #0xe
 *   @0x2fd0ae lsls r5, r5, #0xf
 *   @0x2fd0b2 lsls r7, r2, #0x10
 *   @0x2fd0b6 lsls r0, r0, #0x11
 *   @0x2fd0ba lsls r4, r6, #0x13
 *   @0x2fd0be lsls r1, r7, #0x13
 *   @0x2fd0c2 lsls r6, r7, #0x15
 *   @0x2fd0c6 lsls r3, r1, #0x17
 *   @0x2fd0ca lsls r0, r1, #0x1b
 *   @0x2fd0ce lsls r2, r6, #0x1d
 *   @0x2fd0d2 lsls r4, r7, #0x1d
 *   @0x2fd0d6 lsrs r2, r0, #0x20
 *   @0x2fd0da lsrs r2, r6, #0x20
 *   @0x2fd0de lsrs r7, r2, #0x1
 *   @0x2fd0e2 lsrs r6, r5, #0x1
 *   @0x2fd0e6 lsrs r0, r3, #0x2
 *   @0x2fd0ea lsrs r6, r3, #0x2
 *   @0x2fd0ee lsrs r1, r7, #0x2
 *   @0x2fd0f2 lsrs r1, r0, #0x3
 *   @0x2fd0f6 lsrs r0, r2, #0x3
 *   @0x2fd0fa lsrs r6, r4, #0x3
 *   @0x2fd0fe lsrs r6, r7, #0x3
 *   @0x2fd102 lsrs r3, r3, #0x4
 *   @0x2fd106 lsrs r2, r5, #0x16
 *   @0x2fd10a lsrs r3, r3, #0x5
 *   @0x2fd10e lsrs r2, r6, #0x5
 *   @0x2fd112 lsrs r6, r7, #0x5
 *   @0x2fd116 lsrs r0, r2, #0x6
 *   @0x2fd11a lsrs r7, r4, #0x6
 *   @0x2fd11e lsrs r0, r7, #0x6
 *   @0x2fd122 lsrs r5, r0, #0x7
 *   @0x2fd126 lsrs r5, r1, #0x7
 *   @0x2fd12a lsrs r5, r1, #0x7
 *   @0x2fd12e lsrs r2, r3, #0x7
 *   @0x2fd132 lsrs r2, r3, #0x7
 *   @0x2fd136 lsrs r7, r6, #0x7
 *   @0x2fd13a lsrs r4, r7, #0x7
 *   @0x2fd13e lsrs r4, r7, #0x7
 *   @0x2fd142 lsrs r3, r3, #0x9
 *   @0x2fd146 lsrs r4, r6, #0x9
 *   @0x2fd14a lsrs r6, r0, #0xa
 *   @0x2fd14e lsrs r3, r2, #0xa
 *   @0x2fd152 lsrs r2, r5, #0x16
 *   @0x2fd156 lsrs r0, r4, #0xa
 *   @0x2fd15a lsrs r4, r6, #0xb
 *   @0x2fd15e lsrs r0, r7, #0xb
 *   @0x2fd162 lsrs r5, r7, #0xb
 *   @0x2fd166 lsrs r7, r0, #0xd
 *   @0x2fd16a lsrs r5, r2, #0xd
 *   @0x2fd16e lsrs r7, r4, #0xd
 *   @0x2fd172 lsrs r5, r2, #0xe
 *   @0x2fd176 lsrs r1, r3, #0xe
 *   @0x2fd17a and r2, r3, #0x1
 *   @0x2fd17e lsls r2, r2, #0xe
 *   @0x2fd182 cmp r2, #0x0
 *   @0x2fd186 moveq.w r1, #0x4000
 *   @0x2fd18a movne r1, #0x0
 *   @0x2fd18e bhi 0x2fd1a0 <TT_RunIns+0x3ac>
 *   @0x2fd1a2 itt pl
 *   @0x2fd1ae bl 0x2f9460 <ps_hints_apply+0x8060>
 *   @0x2fd1b2 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd1b6 add.w r8, r4, #0x12a
 *   @0x2fd1ba mov r0, r4
 *   @0x2fd1be ldrh.w r2, [r5, r6, lsl #2]
 *   @0x2fd1c2 mov r3, r8
 *   @0x2fd1ca bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd1ce ldr.w r3, [r4, #0x12a]
 *   @0x2fd1d2 mov r0, r4
 *   @0x2fd1e2 ldrh r1, [r7, #0x4]
 *   @0x2fd1f2 bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd1f6 b 0x2fd1ac <TT_RunIns+0x3b8>
 *   @0x2fd206 mov r2, r3
 *   @0x2fd20e mov r0, r4
 *   @0x2fd22e bl 0x2f9460 <ps_hints_apply+0x8060>
 *   @0x2fd232 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd236 ldrsh.w r3, [r4, #0x12a]
 *   @0x2fd23a str.w r3, [r5, r6, lsl #2]
 *   @0x2fd23e ldrsh.w r3, [r4, #0x12c]
 *   @0x2fd242 str r3, [r7, #0x4]
 *   @0x2fd256 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd25a ldr.w r3, [r4, #0x12a]
 *   @0x2fd25e mov r0, r4
 *   @0x2fd272 ldr r5, [r7, #0x4]
 *   @0x2fd276 ldrh r3, [r4, #0x2c]
 *   @0x2fd27a ldrh r7, [r7, #0xc]
 *   @0x2fd27e str r7, [sp, #0xc]
 *   @0x2fd282 uxth.w r11, r2
 *   @0x2fd286 cmp r11, r3
 *   @0x2fd28a ldrh.w r3, [r4, #0x50]
 *   @0x2fd28e uxth r5, r5
 *   @0x2fd292 bhs 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd296 cmp r6, r3
 *   @0x2fd29a ldr r7, [sp, #0x1c]
 *   @0x2fd2a6 bhi 0x2fd2ba <TT_RunIns+0x4c6>
 *   @0x2fd2ae beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd2b2 movs r3, #0x86
 *   @0x2fd2b6 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd2ba lsl.w r8, r11, #0x3
 *   @0x2fd2be ldr.w r12, [sp, #0xc]
 *   @0x2fd2c2 ldr r3, [r4, #0x34]
 *   @0x2fd2ca ldr.w r8, [sp, #0xc]
 *   @0x2fd2ce lsl.w r12, r12, #0x3
 *   @0x2fd2d2 add r2, r3
 *   @0x2fd2da ldr.w r12, [r4, #0x58]
 *   @0x2fd2de ldr.w r7, [r3, r8, lsl #3]
 *   @0x2fd2e2 lsl.w r8, r6, #0x3
 *   @0x2fd2e6 add r1, r3
 *   @0x2fd2f2 lsl.w r8, r5, #0x3
 *   @0x2fd2f6 ldr r1, [r1, #0x4]
 *   @0x2fd2fa str r3, [sp, #0x10]
 *   @0x2fd2fe add lr, r12
 *   @0x2fd306 ldr.w r9, [r12, r6, lsl #3]
 *   @0x2fd30a add r2, r12
 *   @0x2fd30e str.w r8, [sp, #0x14]
 *   @0x2fd312 rsb.w r12, r3, #0x0
 *   @0x2fd316 ldr.w r8, [lr, #0x4]
 *   @0x2fd31a ldr r2, [r2, #0x4]
 *   @0x2fd322 str r0, [sp, #0x30]
 *   @0x2fd32a subs r2, r1, r2
 *   @0x2fd32e str r2, [sp, #0x34]
 *   @0x2fd332 str.w r12, [sp, #0x2c]
 *   @0x2fd336 str r3, [sp, #0x8]
 *   @0x2fd33e movs r2, #0x40
 *   @0x2fd342 mov r0, r8
 *   @0x2fd34a movs r2, #0x40
 *   @0x2fd34e mov r0, r9
 *   @0x2fd356 movs r2, #0x40
 *   @0x2fd35a mov r12, r0
 *   @0x2fd35e str.w r12, [sp, #0x8]
 *   @0x2fd362 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fd366 eor.w r3, r7, r7, asr #31
 *   @0x2fd36a sub.w r3, r3, r7, asr #31
 *   @0x2fd36e movs r2, #0x13
 *   @0x2fd376 add r0, r12
 *   @0x2fd382 lsl.w r3, r10, #0x3
 *   @0x2fd386 ble 0x2fd3da <TT_RunIns+0x5e6>
 *   @0x2fd38a movs r2, #0x40
 *   @0x2fd38e str r3, [sp, #0x8]
 *   @0x2fd396 movs r2, #0x40
 *   @0x2fd39a ldr r0, [sp, #0x34]
 *   @0x2fd3a2 mov r2, r7
 *   @0x2fd3a6 mov r0, r6
 *   @0x2fd3ae mov r2, r7
 *   @0x2fd3b2 mov r0, r6
 *   @0x2fd3ba ldr r2, [r4, #0x7c]
 *   @0x2fd3c2 add r1, r9
 *   @0x2fd3ca ldr r2, [r4, #0x7c]
 *   @0x2fd3ce ldr r2, [r4, #0x58]
 *   @0x2fd3d2 ldr r2, [r2, #0x4]
 *   @0x2fd3d6 str r0, [r3, #0x4]
 *   @0x2fd3da ldr r1, [r4, #0x58]
 *   @0x2fd3de ldr r0, [r4, #0x7c]
 *   @0x2fd3ea add r5, r1
 *   @0x2fd3ee ldr.w r8, [sp, #0x20]
 *   @0x2fd3f2 ldr.w r1, [r2, r6, lsl #3]
 *   @0x2fd3f6 add r5, r1
 *   @0x2fd3fe it mi
 *   @0x2fd402 asrs r1, r1, #0x2
 *   @0x2fd40a ldr r2, [r4, #0x58]
 *   @0x2fd40e ldr r0, [sp, #0x14]
 *   @0x2fd412 add r0, r2
 *   @0x2fd416 ldr r0, [r0, #0x4]
 *   @0x2fd41a add r2, r0
 *   @0x2fd41e add r0, r1
 *   @0x2fd422 ldr r0, [r0, #0x4]
 *   @0x2fd426 add r2, r0
 *   @0x2fd42a it mi
 *   @0x2fd42e asrs r2, r2, #0x2
 *   @0x2fd432 ldr.w r12, [sp, #0x1c]
 *   @0x2fd436 ldr.w r2, [r4, #0x84]
 *   @0x2fd43a uxth.w r3, r12
 *   @0x2fd43e ldrb r1, [r2, r3]
 *   @0x2fd446 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd44a ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd44e strh.w r3, [r4, #0x120]
 *   @0x2fd452 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd456 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd45a strh.w r3, [r4, #0x122]
 *   @0x2fd45e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd462 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd466 strh.w r3, [r4, #0x124]
 *   @0x2fd46a b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd46e ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd472 cbz r3, 0x2fd484 <TT_RunIns+0x690>
 *   @0x2fd476 bne.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd47a add.w r7, r4, #0x24
 *   @0x2fd47e add.w r12, r4, #0x90
 *   @0x2fd482 b 0x2fd48c <TT_RunIns+0x698>
 *   @0x2fd492 ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd496 stm r7!, {r0, r1, r2, r3}
 *   @0x2fd49e ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd4a2 strh.w r3, [r4, #0x15c]
 *   @0x2fd4a6 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd4aa ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd4ae cbz r3, 0x2fd4c0 <TT_RunIns+0x6cc>
 *   @0x2fd4b2 bne.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd4b6 add.w r7, r4, #0x48
 *   @0x2fd4ba add.w r12, r4, #0x90
 *   @0x2fd4be b 0x2fd4c8 <TT_RunIns+0x6d4>
 *   @0x2fd4ce ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd4d2 stm r7!, {r0, r1, r2, r3}
 *   @0x2fd4da ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd4de strh.w r3, [r4, #0x15e]
 *   @0x2fd4e2 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd4e6 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd4ea cbz r3, 0x2fd4fc <TT_RunIns+0x708>
 *   @0x2fd4ee bne.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd4f2 add.w r7, r4, #0x6c
 *   @0x2fd4f6 add.w r12, r4, #0x90
 *   @0x2fd4fa b 0x2fd504 <TT_RunIns+0x710>
 *   @0x2fd50a ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd50e stm r7!, {r0, r1, r2, r3}
 *   @0x2fd516 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd51a strh.w r3, [r4, #0x160]
 *   @0x2fd51e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd522 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd526 cbz r3, 0x2fd538 <TT_RunIns+0x744>
 *   @0x2fd52a bne.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd52e add.w r7, r4, #0x24
 *   @0x2fd532 add.w r12, r4, #0x90
 *   @0x2fd536 b 0x2fd540 <TT_RunIns+0x74c>
 *   @0x2fd54a ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd54e stm r7!, {r0, r1, r2, r3}
 *   @0x2fd55a add.w r7, r4, #0x24
 *   @0x2fd55e ldm r7!, {r0, r1, r2, r3}
 *   @0x2fd566 stm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd56a ldr r3, [r7]
 *   @0x2fd586 str.w r3, [r12]
 *   @0x2fd58a ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd58e strh.w r3, [r4, #0x15c]
 *   @0x2fd592 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd596 strh.w r3, [r4, #0x15e]
 *   @0x2fd59a ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd59e strh.w r3, [r4, #0x160]
 *   @0x2fd5a2 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd5a6 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd5aa cmp r3, #0x0
 *   @0x2fd5ae strge.w r3, [r4, #0x134]
 *   @0x2fd5b2 movlt r3, #0x84
 *   @0x2fd5b6 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd5ba ldr.w r3, [pc, #0x504]
 *   @0x2fd5be str.w r0, [r4, #0x13c]
 *   @0x2fd5c2 add r3, pc
 *   @0x2fd5d6 str.w r3, [r4, #0x23c]
 *   @0x2fd5da b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd5de ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd5e2 str.w r3, [r4, #0x138]
 *   @0x2fd5e6 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd5ea movs r5, #0x1
 *   @0x2fd5ee bl 0x2f9580 <ps_hints_apply+0x8180>
 *   @0x2fd5f2 cmp r0, #0x1
 *   @0x2fd5fe beq 0x2fd608 <TT_RunIns+0x814>
 *   @0x2fd602 bne 0x2fd60a <TT_RunIns+0x816>
 *   @0x2fd606 b 0x2fd60a <TT_RunIns+0x816>
 *   @0x2fd60a cmp r5, #0x0
 *   @0x2fd60e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd612 mov r0, r4
 *   @0x2fd616 bl 0x2fb68c <ps_hints_apply+0xa28c>
 *   @0x2fd61a b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd61e ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd622 str.w r3, [r4, #0x144]
 *   @0x2fd626 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd62a ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd62e str.w r3, [r4, #0x148]
 *   @0x2fd632 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd636 ldr.w r0, [r5, r6, lsl #2]
 *   @0x2fd63a ldr.w r1, [r4, #0x108]
 *   @0x2fd63e bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fd642 str.w r0, [r4, #0x14c]
 *   @0x2fd646 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd64a ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd64e str r3, [r7, #0x4]
 *   @0x2fd656 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd65a ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fd65e ldr r3, [r7, #0x4]
 *   @0x2fd666 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd66a ldr r3, [r4, #0x10]
 *   @0x2fd67a ble 0x2fd680 <TT_RunIns+0x88c>
 *   @0x2fd67e ble 0x2fd694 <TT_RunIns+0x8a0>
 *   @0x2fd686 movs r3, #0x86
 *   @0x2fd68a movs r3, #0x0
 *   @0x2fd696 ldr.w r3, [r5, r3, lsl #2]
 *   @0x2fd69a str.w r3, [r5, r6, lsl #2]
 *   @0x2fd69e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd6a2 ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fd6a6 cmp r2, #0x0
 *   @0x2fd6ae bgt.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd6b2 subs r6, r6, r2
 *   @0x2fd6b6 lsls r0, r6, #0x2
 *   @0x2fd6ba adds r1, r0, #0x4
 *   @0x2fd6be add r1, r5
 *   @0x2fd6ca ldr r2, [r4, #0x18]
 *   @0x2fd6d2 str.w r6, [r2, r3, lsl #2]
 *   @0x2fd6d6 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd6da ldrh.w r8, [r5, r6, lsl #2]
 *   @0x2fd6de ldrh.w r3, [r4, #0x50]
 *   @0x2fd6e2 ldr r6, [r7, #0x4]
 *   @0x2fd6e6 bls.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd6ea ldrh r3, [r4, #0x2c]
 *   @0x2fd6ee cmp r3, r6
 *   @0x2fd6f6 ldr r3, [r4, #0x58]
 *   @0x2fd70a ldr r2, [r0, #0x4]
 *   @0x2fd70e ldr.w r3, [r4, #0x240]
 *   @0x2fd712 mov r0, r4
 *   @0x2fd716 blx r3
 *   @0x2fd722 add.w r0, r0, r0, lsr #31
 *   @0x2fd726 asrs r7, r0, #0x1
 *   @0x2fd72a mov r3, r7
 *   @0x2fd72e ldr.w r5, [r4, #0x24c]
 *   @0x2fd732 mov r0, r4
 *   @0x2fd73a rsbs r3, r7, #0
 *   @0x2fd73e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd742 mov r0, r4
 *   @0x2fd74e ldrh.w r3, [r5, r6, lsl #2]
 *   @0x2fd752 cmp r2, r3
 *   @0x2fd762 ite ne
 *   @0x2fd766 moveq r2, #0xff
 *   @0x2fd76a and r2, r2, #0xef
 *   @0x2fd76e ldr r1, [r4, #0x3c]
 *   @0x2fd772 ands r2, r0
 *   @0x2fd776 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd77a mov r0, r4
 *   @0x2fd77e bl 0x2fb438 <ps_hints_apply+0xa038>
 *   @0x2fd782 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd786 ldr.w r3, [r4, #0x1a8]
 *   @0x2fd78a ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fd78e adds r3, #0x1
 *   @0x2fd792 bhs 0x2fd81a <TT_RunIns+0xa26>
 *   @0x2fd79e bne 0x2fd7ac <TT_RunIns+0x9b8>
 *   @0x2fd7a2 mla r3, r3, r2, r1
 *   @0x2fd7a6 ldr r5, [r3, #0xc]
 *   @0x2fd7aa beq 0x2fd7c8 <TT_RunIns+0x9d4>
 *   @0x2fd7ae mla r0, r3, r0, r1
 *   @0x2fd7b2 mov r3, r1
 *   @0x2fd7b6 blo 0x2fd7be <TT_RunIns+0x9ca>
 *   @0x2fd7ba bne 0x2fd7c8 <TT_RunIns+0x9d4>
 *   @0x2fd7be ldr r1, [r3, #0xc]
 *   @0x2fd7c2 beq 0x2fd7b8 <TT_RunIns+0x9c4>
 *   @0x2fd7c6 b 0x2fd7b4 <TT_RunIns+0x9c0>
 *   @0x2fd7ca cbz r2, 0x2fd81a <TT_RunIns+0xa26>
 *   @0x2fd7d6 blt 0x2fd7e0 <TT_RunIns+0x9ec>
 *   @0x2fd7da str r3, [r4, #0xc]
 *   @0x2fd7e6 ldr.w r0, [r4, #0x164]
 *   @0x2fd7ea adds r2, r5, r1
 *   @0x2fd7ee mov r0, r4
 *   @0x2fd7f6 adds r1, #0x1
 *   @0x2fd7fa movs r1, #0x1
 *   @0x2fd7fe ldr.w r2, [r4, #0x1b0]
 *   @0x2fd802 add r2, r1
 *   @0x2fd812 strb.w r3, [r4, #0x17c]
 *   @0x2fd816 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd81a movs r3, #0x86
 *   @0x2fd81e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd822 mov r0, r4
 *   @0x2fd826 bl 0x2f95e0 <ps_hints_apply+0x81e0>
 *   @0x2fd82a b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd82e ldr.w r2, [r4, #0x1b0]
 *   @0x2fd832 cmp r2, #0x0
 *   @0x2fd836 movs r3, #0x88
 *   @0x2fd83a b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd83e subs r2, #0x1
 *   @0x2fd84a adds r3, r1, r2
 *   @0x2fd84e subs r0, #0x1
 *   @0x2fd852 movs r0, #0x0
 *   @0x2fd85a cmp r0, #0x0
 *   @0x2fd85e ldr.w r2, [r4, #0x1b0]
 *   @0x2fd862 adds r2, #0x1
 *   @0x2fd86a ldr r3, [r3, #0x4]
 *   @0x2fd876 mov r0, r4
 *   @0x2fd87a bl 0x2fb3f6 <ps_hints_apply+0x9ff6>
 *   @0x2fd87e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd882 ldrh.w r6, [r5, r6, lsl #2]
 *   @0x2fd886 ldrh r2, [r4, #0x2c]
 *   @0x2fd88a bls.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd88e ands r3, r3, #0x1
 *   @0x2fd892 beq 0x2fd8ba <TT_RunIns+0xac6>
 *   @0x2fd896 mov r0, r4
 *   @0x2fd8a6 blx r3
 *   @0x2fd8b2 mov r0, r4
 *   @0x2fd8b6 blx r5
 *   @0x2fd8ba ldr.w r5, [r4, #0x24c]
 *   @0x2fd8be mov r0, r4
 *   @0x2fd8c6 blx r5
 *   @0x2fd8d6 ldr r2, [r2, #0x60]
 *   @0x2fd8da cmp r2, #0x28
 *   @0x2fd8de ldrb.w r2, [r4, #0x267]
 *   @0x2fd8e2 cbz r2, 0x2fd906 <TT_RunIns+0xb12>
 *   @0x2fd8ea ldrb.w r2, [r4, #0x269]
 *   @0x2fd8ee cmp r2, #0x0
 *   @0x2fd8fe strbne.w r2, [r4, #0x268]
 *   @0x2fd902 strbeq.w r2, [r4, #0x269]
 *   @0x2fd906 ldrsh.w r2, [r4, #0x9a]
 *   @0x2fd90a cmp r2, #0x0
 *   @0x2fd91a beq 0x2fd928 <TT_RunIns+0xb34>
 *   @0x2fd91e str r1, [sp, #0x4c]
 *   @0x2fd922 str r3, [sp, #0x54]
 *   @0x2fd926 b 0x2fd938 <TT_RunIns+0xb44>
 *   @0x2fd92a adds r2, #0x4
 *   @0x2fd92e movs r6, #0x10
 *   @0x2fd932 str r2, [sp, #0x50]
 *   @0x2fd936 str r6, [sp, #0xc]
 *   @0x2fd946 str r3, [sp, #0x58]
 *   @0x2fd952 ldrh.w r9, [r3, r2, lsl #1]
 *   @0x2fd956 ldrh.w r3, [r4, #0xb0]
 *   @0x2fd95a rsb r9, r3, r9
 *   @0x2fd95e ldrh.w r3, [r4, #0x98]
 *   @0x2fd962 cmp r9, r3
 *   @0x2fd966 addhs.w r9, r3, #0xffffffff
 *   @0x2fd96a cmp r5, r9
 *   @0x2fd96e ldr.w r3, [r4, #0xa8]
 *   @0x2fd972 ldr.w r8, [sp, #0xc]
 *   @0x2fd976 ldrb r3, [r3, r5]
 *   @0x2fd982 mov r5, r3
 *   @0x2fd986 mov r8, r5
 *   @0x2fd98a mov r5, r3
 *   @0x2fd98e bhi 0x2fd9b4 <TT_RunIns+0xbc0>
 *   @0x2fd99a tst.w r12, r3
 *   @0x2fd99e beq 0x2fd9b0 <TT_RunIns+0xbbc>
 *   @0x2fd9a2 mov r3, r6
 *   @0x2fd9a6 mov r0, r11
 *   @0x2fd9aa mov r6, r5
 *   @0x2fd9b2 b 0x2fd98c <TT_RunIns+0xb98>
 *   @0x2fd9b6 bne 0x2fd9f8 <TT_RunIns+0xc04>
 *   @0x2fd9ba lsl.w r8, r6, #0x3
 *   @0x2fd9be ldr.w r2, [r3, r6, lsl #3]
 *   @0x2fd9c2 ldr r3, [sp, #0x4c]
 *   @0x2fd9ca beq 0x2fda22 <TT_RunIns+0xc2e>
 *   @0x2fd9ce cmp r7, r6
 *   @0x2fd9d2 ldr r1, [sp, #0x50]
 *   @0x2fd9d6 ldr r0, [r1, r3]
 *   @0x2fd9da str r0, [r1, r3]
 *   @0x2fd9de b 0x2fd9ce <TT_RunIns+0xbda>
 *   @0x2fd9e2 add.w r8, r8, #0x8
 *   @0x2fd9e6 cmp r6, r9
 *   @0x2fd9ea ldr r1, [sp, #0x50]
 *   @0x2fd9f2 str.w r3, [r1, r8]
 *   @0x2fd9f6 b 0x2fd9e0 <TT_RunIns+0xbec>
 *   @0x2fd9fa str.w r8, [sp]
 *   @0x2fd9fe mov r0, r11
 *   @0x2fda02 uxth r1, r1
 *   @0x2fda06 bl 0x2fb894 <ps_hints_apply+0xa494>
 *   @0x2fda0a cmp.w r8, #0x0
 *   @0x2fda0e beq 0x2fda22 <TT_RunIns+0xc2e>
 *   @0x2fda16 mov r1, r7
 *   @0x2fda1e bl 0x2fb894 <ps_hints_apply+0xa494>
 *   @0x2fda22 add.w r12, r10, #0x1
 *   @0x2fda26 ldrsh.w r2, [r4, #0x9a]
 *   @0x2fda2a uxth.w r10, r12
 *   @0x2fda2e sxth.w r3, r10
 *   @0x2fda32 cmp r2, r3
 *   @0x2fda3a b 0x2fd948 <TT_RunIns+0xb54>
 *   @0x2fda3e bl 0x2f9fee <ps_hints_apply+0x8bee>
 *   @0x2fda42 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fda46 ldrh.w r3, [r4, #0x160]
 *   @0x2fda4a ldr.w r6, [r5, r6, lsl #2]
 *   @0x2fda4e cbz r3, 0x2fda56 <TT_RunIns+0xc62>
 *   @0x2fda56 movs r3, #0x1
 *   @0x2fda5a cmp r6, r3
 *   @0x2fda5e ldrb.w r3, [r4, #0x235]
 *   @0x2fda62 cmp r3, #0x0
 *   @0x2fda6a str r3, [r4, #0xc]
 *   @0x2fda72 vqshl.u64 d29, d21, #0x3f
 *   @0x2fda76 .word 0xffff d78f
 *   @0x2fda7a .word 0xffff d763
 *   @0x2fda7e .word 0xffff c3e1
 *   @0x2fda82 .word 0xffff c3dd
 *   @0x2fda86 .word 0xffff c3dd
 *   @0x2fda8a .word 0xffff c3dd
 *   @0x2fda8e .word 0xffff c46b
 *   @0x2fda92 vqshlu.s32 d30, d29, #0x1f
 *   @0x2fda96 vqshlu.s64 d30, d13, #0x3f
 *   @0x2fda9a .word 0xffff e677
 *   @0x2fda9e .word 0xffff e647
 *   @0x2fdaa2 .word 0xffff e6a7
 *   @0x2fdaa6 .word 0xffff e6c1
 *   @0x2fdaaa .word 0xffff e6f5
 *   @0x2fdaae .word 0xffff 2fa6
 *   @0x2fdab2 movs r2, r1
 *   @0x2fdab6 movs r2, r1
 *   @0x2fdaba movs r2, r1
 *   @0x2fdabe movs r2, r1
 *   @0x2fdac2 .word 0xffff dfa9
 *   @0x2fdac6 .word 0xffff f10d
 *   @0x2fdaca lsls r2, r0, #0xd
 *   @0x2fdace str r3, [sp]
 *   @0x2fdad2 add r2, sp, #0x48
 *   @0x2fdad6 bl 0x2f9f0e <ps_hints_apply+0x8b0e>
 *   @0x2fdada cmp r0, #0x0
 *   @0x2fdae2 sxth r3, r6
 *   @0x2fdaf2 rsb.w r5, r5, #0x1
 *   @0x2fdaf6 ldrh.w r3, [r2, r3, lsl #1]
 *   @0x2fdafa add r5, r3
 *   @0x2fdafe b 0x2fdb02 <TT_RunIns+0xd0e>
 *   @0x2fdb02 ldrh.w r3, [r4, #0x160]
 *   @0x2fdb06 cbnz r3, 0x2fdb0e <TT_RunIns+0xd1a>
 *   @0x2fdb0e ldr.w r3, [r4, #0x88]
 *   @0x2fdb12 sxth r6, r6
 *   @0x2fdb22 uxth r6, r6
 *   @0x2fdb26 cmp r5, r6
 *   @0x2fdb2e ldr r2, [sp, #0x5c]
 *   @0x2fdb32 bne 0x2fdb3c <TT_RunIns+0xd48>
 *   @0x2fdb3a beq 0x2fdb4a <TT_RunIns+0xd56>
 *   @0x2fdb3e mov r0, r4
 *   @0x2fdb42 ldr r2, [sp, #0x44]
 *   @0x2fdb46 bl 0x2f995e <ps_hints_apply+0x855e>
 *   @0x2fdb4a adds r5, #0x1
 *   @0x2fdb4e b 0x2fdb26 <TT_RunIns+0xd32>
 *   @0x2fdb56 bls 0x2fdb6a <TT_RunIns+0xd76>
 *   @0x2fdb5e beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdb62 movs r3, #0x86
 *   @0x2fdb66 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdb6a add.w r3, sp, #0x42
 *   @0x2fdb6e mov r0, r4
 *   @0x2fdb72 add r1, sp, #0x44
 *   @0x2fdb76 add r3, sp, #0x4c
 *   @0x2fdb7e bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdb82 ldrh.w r3, [r4, #0x160]
 *   @0x2fdb86 cbnz r3, 0x2fdb8e <TT_RunIns+0xd9a>
 *   @0x2fdb8e cmp r3, #0x1
 *   @0x2fdb92 ldrsh.w r3, [r4, #0x76]
 *   @0x2fdb96 cmp r3, #0x0
 *   @0x2fdb9a add.w r3, r3, #0x80000000
 *   @0x2fdb9e ldr.w r2, [r4, #0x88]
 *   @0x2fdba2 subs r3, #0x1
 *   @0x2fdbaa uxth r6, r6
 *   @0x2fdbae mov r6, r0
 *   @0x2fdbb2 mov r7, r5
 *   @0x2fdbb6 beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdbba ldr r3, [r4, #0x7c]
 *   @0x2fdbbe cmp r2, r3
 *   @0x2fdbc2 ldrh.w r3, [sp, #0x42]
 *   @0x2fdbc6 cmp r3, r5
 *   @0x2fdbca str r7, [sp]
 *   @0x2fdbce mov r1, r5
 *   @0x2fdbd2 ldr r3, [sp, #0x48]
 *   @0x2fdbda uxth r5, r5
 *   @0x2fdbde mov r0, r4
 *   @0x2fdbe2 bl 0x2f99d2 <ps_hints_apply+0x85d2>
 *   @0x2fdbe6 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdbea ldr r2, [r4, #0x10]
 *   @0x2fdbf2 bge 0x2fdc04 <TT_RunIns+0xe10>
 *   @0x2fdbfa beq.w 0x2fddd6 <TT_RunIns+0xfe2>
 *   @0x2fdbfe movs r3, #0x86
 *   @0x2fdc02 b 0x2fddd6 <TT_RunIns+0xfe2>
 *   @0x2fdc0a ldrh.w r3, [r4, #0x15e]
 *   @0x2fdc0e cbz r3, 0x2fdc20 <TT_RunIns+0xe2c>
 *   @0x2fdc1a movlo.w r8, #0x0
 *   @0x2fdc1e b 0x2fdc24 <TT_RunIns+0xe30>
 *   @0x2fdc2a cmp r3, r6
 *   @0x2fdc2e lsl.w r10, r6, #0x3
 *   @0x2fdc32 cmp.w r8, #0x0
 *   @0x2fdc36 beq 0x2fdc3c <TT_RunIns+0xe48>
 *   @0x2fdc3a b 0x2fdc3e <TT_RunIns+0xe4a>
 *   @0x2fdc3e ldrh.w r3, [r4, #0x124]
 *   @0x2fdc42 add r5, r10
 *   @0x2fdc4a cmp r2, r3
 *   @0x2fdc4e bls 0x2fdce2 <TT_RunIns+0xeee>
 *   @0x2fdc5a ldr r2, [r4, #0x54]
 *   @0x2fdc5e ldr.w r2, [r4, #0xe4]
 *   @0x2fdc62 ldr.w r1, [r4, #0xe0]
 *   @0x2fdc66 cmp r1, r2
 *   @0x2fdc6a bne 0x2fdc86 <TT_RunIns+0xe92>
 *   @0x2fdc76 ldr r3, [r0, #0x4]
 *   @0x2fdc7e subs r2, r3, r2
 *   @0x2fdc86 ldr.w r0, [r2, r3, lsl #3]
 *   @0x2fdc8a rsb r0, lr, r0
 *   @0x2fdc8e bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fdc92 ldrh.w r2, [r4, #0x124]
 *   @0x2fdc96 ldr r3, [r4, #0x5c]
 *   @0x2fdca2 ldr r0, [r3, #0x4]
 *   @0x2fdca6 subs r0, r0, r3
 *   @0x2fdcb2 mov r2, r0
 *   @0x2fdcb6 blx r3
 *   @0x2fdcbe ldr.w r7, [r7, r6, lsl #3]
 *   @0x2fdcc2 ldr.w r1, [r3, r2, lsl #3]
 *   @0x2fdcc6 subs r1, r1, r7
 *   @0x2fdcca add.w r0, r3, r2, lsl #3
 *   @0x2fdcce ldr.w r2, [r10, #0x4]
 *   @0x2fdcd2 ldr r6, [r0, #0x4]
 *   @0x2fdcd6 ldr.w r3, [r4, #0x240]
 *   @0x2fdcda subs r2, r6, r2
 *   @0x2fdcde str r0, [sp, #0xc]
 *   @0x2fdce2 movs r6, #0x0
 *   @0x2fdce6 mov r9, r6
 *   @0x2fdcee ldr.w r3, [r4, #0x134]
 *   @0x2fdcf2 cmp r3, #0x0
 *   @0x2fdcf6 ldr r3, [r4, #0x1c]
 *   @0x2fdcfa subs r3, #0x1
 *   @0x2fdcfe ldr.w r6, [r2, r3, lsl #2]
 *   @0x2fdd02 ldrh.w r3, [r4, #0x74]
 *   @0x2fdd06 cmp r6, r3
 *   @0x2fdd0a ldrb.w r3, [r4, #0x235]
 *   @0x2fdd0e cmp r3, #0x0
 *   @0x2fdd12 movs r3, #0x86
 *   @0x2fdd16 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdd1a ldr.w lr, [r5]
 *   @0x2fdd1e lsls r7, r6, #0x3
 *   @0x2fdd26 ldr r3, [r4, #0x78]
 *   @0x2fdd2a ldr.w r3, [r4, #0xe4]
 *   @0x2fdd2e ldr.w r1, [r4, #0xe0]
 *   @0x2fdd32 cmp r1, r3
 *   @0x2fdd3a adds r2, r3, r7
 *   @0x2fdd42 ldr r3, [r2, #0x4]
 *   @0x2fdd4a subs r2, r3, r2
 *   @0x2fdd52 ldr.w r0, [r3, r6, lsl #3]
 *   @0x2fdd56 rsb r0, lr, r0
 *   @0x2fdd5a bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fdd5e ldr.w r3, [r4, #0x80]
 *   @0x2fdd62 ldr.w r1, [r4, #0xe4]
 *   @0x2fdd66 add r3, r7
 *   @0x2fdd6a ldr r0, [r3, #0x4]
 *   @0x2fdd6e subs r0, r0, r3
 *   @0x2fdd7a mov r2, r0
 *   @0x2fdd7e blx r3
 *   @0x2fdd82 add r7, r3
 *   @0x2fdd8a ldr.w r3, [r10, #0x4]
 *   @0x2fdd8e ldr.w r7, [r10]
 *   @0x2fdd92 subs r2, r2, r3
 *   @0x2fdd9a mov r11, r0
 *   @0x2fdd9e blx r3
 *   @0x2fdda2 cmp.w r11, #0x0
 *   @0x2fdda6 beq 0x2fddba <TT_RunIns+0xfc6>
 *   @0x2fddae mov r0, r11
 *   @0x2fddb2 mov r2, r9
 *   @0x2fddba uxth r2, r6
 *   @0x2fddbe ldr r1, [sp, #0x14]
 *   @0x2fddca ldr.w r3, [r4, #0x134]
 *   @0x2fddce subs r3, #0x1
 *   @0x2fddd6 movs r3, #0x1
 *   @0x2fddde str r3, [r4, #0x20]
 *   @0x2fddee bls.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fddf2 ldrh.w r2, [r4, #0x120]
 *   @0x2fddf6 ldrh r3, [r4, #0x2c]
 *   @0x2fddfa bls.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fddfe ldrh.w r3, [r4, #0x15e]
 *   @0x2fde02 add.w r6, r4, #0x48
 *   @0x2fde06 cbnz r3, 0x2fde3c <TT_RunIns+0x1048>
 *   @0x2fde0a lsl.w r9, r8, #0x3
 *   @0x2fde0e ldr r3, [r4, #0x54]
 *   @0x2fde16 ldm.w r2, {r0, r1}
 *   @0x2fde1a mov r2, r8
 *   @0x2fde22 mov r1, r6
 *   @0x2fde26 ldr.w r5, [r4, #0x250]
 *   @0x2fde2a blx r5
 *   @0x2fde2e ldr r2, [r4, #0x54]
 *   @0x2fde32 add r9, r2
 *   @0x2fde42 ldr r3, [r4, #0x34]
 *   @0x2fde56 ldr r2, [r0, #0x4]
 *   @0x2fde5a mov r0, r4
 *   @0x2fde62 blx r3
 *   @0x2fde66 mov r2, r8
 *   @0x2fde6e subs r3, r3, r0
 *   @0x2fde72 blx r5
 *   @0x2fde86 bpl.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fde8a strh.w r8, [r4, #0x120]
 *   @0x2fde8e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fde92 ldr r2, [r4, #0x10]
 *   @0x2fde9a blt 0x2fdeac <TT_RunIns+0x10b8>
 *   @0x2fdea2 cmp r2, r3
 *   @0x2fdea6 add.w r7, r4, #0x48
 *   @0x2fdeaa b 0x2fdf10 <TT_RunIns+0x111c>
 *   @0x2fdeb2 beq 0x2fdf2a <TT_RunIns+0x1136>
 *   @0x2fdeb6 str r3, [r4, #0xc]
 *   @0x2fdeba ldr r3, [r4, #0x1c]
 *   @0x2fdebe subs r3, #0x1
 *   @0x2fdec2 ldrh.w r6, [r2, r3, lsl #2]
 *   @0x2fdec6 ldrh.w r3, [r4, #0x50]
 *   @0x2fdeca cmp r3, r6
 *   @0x2fdece ldrh.w r2, [r4, #0x120]
 *   @0x2fded2 ldr r1, [r4, #0x58]
 *   @0x2fded6 add.w r5, r1, r6, lsl #3
 *   @0x2fdeda add.w r0, r3, r2, lsl #3
 *   @0x2fdede ldr.w lr, [r1, r6, lsl #3]
 *   @0x2fdee2 ldr r5, [r5, #0x4]
 *   @0x2fdeea mov r0, r4
 *   @0x2fdef6 blx r3
 *   @0x2fdefe mov r2, r6
 *   @0x2fdf02 mov r0, r4
 *   @0x2fdf06 ldr.w r3, [r4, #0x134]
 *   @0x2fdf0a subs r3, #0x1
 *   @0x2fdf16 bgt 0x2fdeba <TT_RunIns+0x10c6>
 *   @0x2fdf1a ldrb.w r3, [r4, #0x235]
 *   @0x2fdf1e cmp r3, #0x0
 *   @0x2fdf22 movs r3, #0x86
 *   @0x2fdf26 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdf2a movs r3, #0x1
 *   @0x2fdf32 str r3, [r4, #0x20]
 *   @0x2fdf3a str.w r3, [r4, #0x13c]
 *   @0x2fdf3e ldr.w r3, [pc, #0xc20]
 *   @0x2fdf42 add r3, pc
 *   @0x2fdf52 ldr.w r8, [r4, #0x144]
 *   @0x2fdf56 cmp r3, r6
 *   @0x2fdf5a bls 0x2fdf64 <TT_RunIns+0x1170>
 *   @0x2fdf62 blo 0x2fdf72 <TT_RunIns+0x117e>
 *   @0x2fdf6a beq 0x2fe006 <TT_RunIns+0x1212>
 *   @0x2fdf6e str r3, [r4, #0xc]
 *   @0x2fdf72 ldr.w r3, [r4, #0x258]
 *   @0x2fdf76 mov r0, r4
 *   @0x2fdf7a ldrh.w r3, [r4, #0x15c]
 *   @0x2fdf7e mov r7, r0
 *   @0x2fdf82 ldrsh.w r1, [r4, #0x12e]
 *   @0x2fdf86 lsl.w r9, r6, #0x3
 *   @0x2fdf8a ldr r5, [r4, #0x30]
 *   @0x2fdf96 ldr r3, [r4, #0x30]
 *   @0x2fdf9a ldrsh.w r1, [r4, #0x130]
 *   @0x2fdf9e add r9, r3
 *   @0x2fdfaa ldr r2, [r4, #0x30]
 *   @0x2fdfae add r5, r2
 *   @0x2fdfba mov r0, r4
 *   @0x2fdfca blx r5
 *   @0x2fdfd2 mov r9, r0
 *   @0x2fdfd6 subs r1, r7, r0
 *   @0x2fdfde it lt
 *   @0x2fdfe2 mov r0, r4
 *   @0x2fdfe6 ite le
 *   @0x2fdfea movgt r1, r9
 *   @0x2fdff2 mov r7, r0
 *   @0x2fdffa add.w r1, r4, #0x24
 *   @0x2fdffe mov r2, r6
 *   @0x2fe006 strh.w r6, [r4, #0x120]
 *   @0x2fe00a strh.w r6, [r4, #0x122]
 *   @0x2fe00e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe012 ldr.w r1, [r4, #0x168]
 *   @0x2fe016 adds r2, #0x1
 *   @0x2fe01e ldrb r1, [r3, #0x1]
 *   @0x2fe022 subs r3, r2, r3
 *   @0x2fe026 bhs.w 0x2fd7d8 <TT_RunIns+0x9e4>
 *   @0x2fe02a movs r3, #0x1
 *   @0x2fe02e bhi 0x2fe04e <TT_RunIns+0x125a>
 *   @0x2fe03e add r0, r3
 *   @0x2fe042 add r2, r0
 *   @0x2fe046 ldrb r2, [r2, #0x1]
 *   @0x2fe04e ldr r3, [r4, #0x20]
 *   @0x2fe052 str r1, [r4, #0x20]
 *   @0x2fe05e ldr.w r1, [r4, #0x168]
 *   @0x2fe062 add r1, r3
 *   @0x2fe066 ldr r1, [r4, #0x10]
 *   @0x2fe06a cmp r6, r1
 *   @0x2fe072 adds r3, #0x2
 *   @0x2fe07a cmp r3, r6
 *   @0x2fe07e mov r0, r4
 *   @0x2fe08a b 0x2fe078 <TT_RunIns+0x1284>
 *   @0x2fe08e strb.w r3, [r4, #0x17c]
 *   @0x2fe092 ldr r3, [r4, #0x20]
 *   @0x2fe096 str r6, [r4, #0x20]
 *   @0x2fe0a6 bhs.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe0aa ldr r1, [r7, #0x4]
 *   @0x2fe0c2 blo 0x2fe0d6 <TT_RunIns+0x12e2>
 *   @0x2fe0ca bne.w 0x2fd2b2 <TT_RunIns+0x4be>
 *   @0x2fe0ce str.w r3, [r5, r6, lsl #2]
 *   @0x2fe0d2 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe0d6 ldr.w r2, [r4, #0x1dc]
 *   @0x2fe0da ldr.w r3, [r2, r3, lsl #2]
 *   @0x2fe0de str.w r3, [r5, r6, lsl #2]
 *   @0x2fe0e2 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe0e6 ldr.w r1, [r5, r6, lsl #2]
 *   @0x2fe0ea ldr.w r3, [r4, #0x180]
 *   @0x2fe0ee cmp r1, r3
 *   @0x2fe0fa ldr r2, [r7, #0x4]
 *   @0x2fe0fe b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe102 ldr.w r1, [r5, r6, lsl #2]
 *   @0x2fe106 ldr.w r3, [r4, #0x180]
 *   @0x2fe10a cmp r1, r3
 *   @0x2fe10e ldrb.w r3, [r4, #0x235]
 *   @0x2fe112 cmp r3, #0x0
 *   @0x2fe126 blx r3
 *   @0x2fe13a blo 0x2fe14a <TT_RunIns+0x1356>
 *   @0x2fe142 movs r3, #0x86
 *   @0x2fe146 str r3, [r4, #0xc]
 *   @0x2fe14a tst.w r3, #0x1
 *   @0x2fe14e lsl.w r3, r2, #0x3
 *   @0x2fe152 beq 0x2fe15e <TT_RunIns+0x136a>
 *   @0x2fe156 adds r7, r1, r3
 *   @0x2fe15e ldr r1, [r4, #0x7c]
 *   @0x2fe162 ldr.w r3, [r4, #0x240]
 *   @0x2fe166 ldr.w r1, [r1, r2, lsl #3]
 *   @0x2fe16a mov r0, r4
 *   @0x2fe16e blx r3
 *   @0x2fe17a mov r1, r7
 *   @0x2fe186 mov r1, r7
 *   @0x2fe196 blx r3
 *   @0x2fe1a2 ldr r3, [r3, #0x60]
 *   @0x2fe1a6 cmp r3, #0x23
 *   @0x2fe1aa ldr.w r3, [r4, #0x254]
 *   @0x2fe1ae mov r0, r4
 *   @0x2fe1b2 str.w r0, [r5, r6, lsl #2]
 *   @0x2fe1b6 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe1ba ldr.w r3, [r4, #0xd8]
 *   @0x2fe1be str.w r3, [r5, r6, lsl #2]
 *   @0x2fe1c2 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe1c6 strb.w r0, [r4, #0x140]
 *   @0x2fe1ca b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe1ce strb.w r1, [r4, #0x140]
 *   @0x2fe1d2 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe1d6 movs r3, #0x87
 *   @0x2fe1da b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe1de ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe1e2 ldr r2, [r7, #0x4]
 *   @0x2fe1e6 ite ge
 *   @0x2fe1ea movlt r3, #0x1
 *   @0x2fe1fa cmp r3, r2
 *   @0x2fe1fe movgt r3, #0x0
 *   @0x2fe202 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe206 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe20a ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe20e ldr r2, [r7, #0x4]
 *   @0x2fe212 ite le
 *   @0x2fe216 movgt r3, #0x1
 *   @0x2fe226 cmp r3, r2
 *   @0x2fe22a movlt r3, #0x0
 *   @0x2fe22e str.w r3, [r5, r6, lsl #2]
 *   @0x2fe232 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe236 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe23a ldr r2, [r7, #0x4]
 *   @0x2fe256 subs r3, r3, r2
 *   @0x2fe25a movne r3, #0x1
 *   @0x2fe26a ldr.w r1, [r5, r6, lsl #2]
 *   @0x2fe26e movs r2, #0x0
 *   @0x2fe272 and r0, r0, #0x7f
 *   @0x2fe276 subs.w r8, r0, #0x40
 *   @0x2fe27a rsbs.w r0, r8, #0x0
 *   @0x2fe27e adcs.w r0, r0, r8
 *   @0x2fe282 str.w r0, [r5, r6, lsl #2]
 *   @0x2fe286 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe28a ldr.w r3, [r4, #0x23c]
 *   @0x2fe28e mov r0, r4
 *   @0x2fe296 blx r3
 *   @0x2fe29e movne r3, #0x0
 *   @0x2fe2a2 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe2a6 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe2aa ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe2ae cmp r3, #0x0
 *   @0x2fe2b6 mov r0, r4
 *   @0x2fe2be beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe2c2 ldrb.w r3, [r4, #0x174]
 *   @0x2fe2c6 cmp r3, #0x58
 *   @0x2fe2ca cmp r3, #0x59
 *   @0x2fe2ce cmp r3, #0x1b
 *   @0x2fe2d2 subs.w r12, r5, #0x1
 *   @0x2fe2d6 rsbs.w r3, r12, #0x0
 *   @0x2fe2da adcs.w r3, r3, r12
 *   @0x2fe2de b 0x2fe2ec <TT_RunIns+0x14f8>
 *   @0x2fe2e2 b 0x2fe2b6 <TT_RunIns+0x14c2>
 *   @0x2fe2e6 ite ne
 *   @0x2fe2ea moveq r3, #0x1
 *   @0x2fe2ee beq 0x2fe2b6 <TT_RunIns+0x14c2>
 *   @0x2fe2fa ldr r3, [r7, #0x4]
 *   @0x2fe2fe it ne
 *   @0x2fe302 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe306 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe30a ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe30e cbnz r3, 0x2fe31a <TT_RunIns+0x1526>
 *   @0x2fe312 adds r3, #0x0
 *   @0x2fe316 movne r3, #0x1
 *   @0x2fe31a movs r3, #0x1
 *   @0x2fe32e movlo r3, #0x0
 *   @0x2fe33a mov r1, r7
 *   @0x2fe356 itee ls
 *   @0x2fe35e strhi r3, [r4, #0xc]
 *   @0x2fe36a add r3, r2
 *   @0x2fe37a subs r3, r3, r2
 *   @0x2fe386 cbnz r2, 0x2fe390 <TT_RunIns+0x159c>
 *   @0x2fe38a str r3, [r4, #0xc]
 *   @0x2fe396 bl 0x2e4dec <FT_MulDiv_No_Round>
 *   @0x2fe39a str.w r0, [r5, r6, lsl #2]
 *   @0x2fe39e b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe3a2 ldr.w r0, [r5, r6, lsl #2]
 *   @0x2fe3a6 movs r2, #0x40
 *   @0x2fe3aa bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fe3ae str.w r0, [r5, r6, lsl #2]
 *   @0x2fe3b2 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe3ba it lt
 *   @0x2fe3be str.w r3, [r5, r6, lsl #2]
 *   @0x2fe3c2 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe3ca str.w r3, [r5, r6, lsl #2]
 *   @0x2fe3ce b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe3de ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe3e2 adds r3, #0x3f
 *   @0x2fe3ee add.w r3, r4, r3, lsl #2
 *   @0x2fe3f2 ldr.w r7, [r4, #0x23c]
 *   @0x2fe3f6 mov r0, r4
 *   @0x2fe402 str.w r0, [r5, r6, lsl #2]
 *   @0x2fe406 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe412 ldr r2, [r3, #-164]
 *   @0x2fe416 bl 0x2f9384 <ps_hints_apply+0x7f84>
 *   @0x2fe41a str.w r0, [r5, r6, lsl #2]
 *   @0x2fe41e b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe42a bhs.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe42e ldr r0, [r7, #0x4]
 *   @0x2fe442 mov r0, r4
 *   @0x2fe446 bl 0x2f9ab6 <ps_hints_apply+0x86b6>
 *   @0x2fe44a b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe452 blx r3
 *   @0x2fe45a mov r7, r0
 *   @0x2fe45e bhi 0x2fe4e4 <TT_RunIns+0x16f0>
 *   @0x2fe462 cmp r3, #0x1
 *   @0x2fe466 ldrb.w r3, [r4, #0x235]
 *   @0x2fe46a cbz r3, 0x2fe470 <TT_RunIns+0x167c>
 *   @0x2fe46e str r3, [r4, #0xc]
 *   @0x2fe472 str r3, [r4, #0x1c]
 *   @0x2fe476 subs r2, r3, #0x2
 *   @0x2fe47a ldr r2, [r4, #0x18]
 *   @0x2fe47e ldr.w r1, [r2, r3, lsl #2]
 *   @0x2fe482 add.w r3, r2, r3, lsl #2
 *   @0x2fe486 ldr r2, [r3, #-4]
 *   @0x2fe48a ldr.w r3, [r4, #0x180]
 *   @0x2fe48e cmp r1, r3
 *   @0x2fe492 ldrb.w r3, [r4, #0x235]
 *   @0x2fe496 cbz r3, 0x2fe4e0 <TT_RunIns+0x16ec>
 *   @0x2fe49a str r3, [r4, #0xc]
 *   @0x2fe49e ldrb.w r0, [r4, #0x174]
 *   @0x2fe4a2 ubfx r3, r2, #0x4, #0x4
 *   @0x2fe4a6 cmp r0, #0x74
 *   @0x2fe4aa cmp r0, #0x75
 *   @0x2fe4ae adds r3, #0x20
 *   @0x2fe4b2 adds r3, #0x10
 *   @0x2fe4ba cmp r7, r3
 *   @0x2fe4be and lr, r2, #0xf
 *   @0x2fe4c2 ldrh.w r2, [r4, #0x152]
 *   @0x2fe4c6 subs.w lr, lr, #0x8
 *   @0x2fe4ca ldr.w r3, [r4, #0x260]
 *   @0x2fe4ce it pl
 *   @0x2fe4da lsl.w r2, lr, r2
 *   @0x2fe4de blx r3
 *   @0x2fe4e2 b 0x2fe45c <TT_RunIns+0x1668>
 *   @0x2fe4e6 str r3, [r4, #0x20]
 *   @0x2fe4ea mov r0, r4
 *   @0x2fe4fa str.w r3, [r4, #0x13c]
 *   @0x2fe4fe ldr.w r3, [pc, #0x664]
 *   @0x2fe502 add r3, pc
 *   @0x2fe50a mov r0, r4
 *   @0x2fe51a str.w r3, [r4, #0x13c]
 *   @0x2fe51e ldr.w r3, [pc, #0x648]
 *   @0x2fe522 add r3, pc
 *   @0x2fe52a ldr r3, [r7, #0x4]
 *   @0x2fe52e beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe532 mov r0, r4
 *   @0x2fe536 bl 0x2fb68c <ps_hints_apply+0xa28c>
 *   @0x2fe53a b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe53e cmp r3, #0x0
 *   @0x2fe546 mov r1, r7
 *   @0x2fe54e movs r3, #0x5
 *   @0x2fe55a str.w r3, [r4, #0x23c]
 *   @0x2fe55e b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe562 bl 0x2fb4ec <ps_hints_apply+0xa0ec>
 *   @0x2fe566 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe56a str.w r3, [r4, #0x13c]
 *   @0x2fe56e ldr.w r3, [pc, #0x600]
 *   @0x2fe572 add r3, pc
 *   @0x2fe57a movs r3, #0x3
 *   @0x2fe586 str.w r3, [r4, #0x23c]
 *   @0x2fe58a b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe58e bl 0x2f98de <ps_hints_apply+0x84de>
 *   @0x2fe592 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe596 ldr r3, [r3, #0x60]
 *   @0x2fe59a cmp r3, #0x28
 *   @0x2fe59e ldrb.w r3, [r4, #0x267]
 *   @0x2fe5a2 cbz r3, 0x2fe5b4 <TT_RunIns+0x17c0>
 *   @0x2fe5aa ldrb.w r3, [r4, #0x269]
 *   @0x2fe5ae cmp r3, #0x0
 *   @0x2fe5b6 ldrh.w r3, [r4, #0x98]
 *   @0x2fe5ba ldr.w r0, [r5, r6, lsl #2]
 *   @0x2fe5be cmp r1, r3
 *   @0x2fe5c6 cmp r0, r3
 *   @0x2fe5ce adds r3, r0, r2
 *   @0x2fe5d2 cmp r3, r1
 *   @0x2fe5de ldrb r6, [r5, r3]
 *   @0x2fe5e6 b 0x2fe5ce <TT_RunIns+0x17da>
 *   @0x2fe5ea ldr r3, [r3, #0x60]
 *   @0x2fe5ee cmp r3, #0x28
 *   @0x2fe5f2 ldrb.w r3, [r4, #0x267]
 *   @0x2fe5f6 cbz r3, 0x2fe608 <TT_RunIns+0x1814>
 *   @0x2fe5fe ldrb.w r3, [r4, #0x269]
 *   @0x2fe602 cmp r3, #0x0
 *   @0x2fe60a ldrh.w r3, [r4, #0x98]
 *   @0x2fe60e ldr.w r0, [r5, r6, lsl #2]
 *   @0x2fe612 cmp r1, r3
 *   @0x2fe61a cmp r0, r3
 *   @0x2fe622 adds r3, r0, r2
 *   @0x2fe626 cmp r3, r1
 *   @0x2fe632 ldrb r6, [r5, r3]
 *   @0x2fe63a b 0x2fe622 <TT_RunIns+0x182e>
 *   @0x2fe63e bl 0x2fb4ec <ps_hints_apply+0xa0ec>
 *   @0x2fe642 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe646 mov r1, r7
 *   @0x2fe64e mov r0, r4
 *   @0x2fe652 bl 0x2fb2ec <ps_hints_apply+0x9eec>
 *   @0x2fe656 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe65a ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fe65e ldr r3, [r0, #0x60]
 *   @0x2fe666 ite ne
 *   @0x2fe66a moveq r3, #0x0
 *   @0x2fe66e bpl 0x2fe67a <TT_RunIns+0x1886>
 *   @0x2fe676 orr r3, r3, #0x100
 *   @0x2fe67a lsls r7, r2, #0x1d
 *   @0x2fe67e ldrb.w r7, [r4, #0x11e]
 *   @0x2fe682 cbz r7, 0x2fe688 <TT_RunIns+0x1894>
 *   @0x2fe68a bpl 0x2fe696 <TT_RunIns+0x18a2>
 *   @0x2fe692 orr r3, r3, #0x400
 *   @0x2fe696 lsls r0, r2, #0x1a
 *   @0x2fe69a ldrb.w r0, [r4, #0x264]
 *   @0x2fe69e cbz r0, 0x2fe6a4 <TT_RunIns+0x18b0>
 *   @0x2fe6a6 bne 0x2fe6dc <TT_RunIns+0x18e8>
 *   @0x2fe6aa it mi
 *   @0x2fe6b2 bpl 0x2fe6be <TT_RunIns+0x18ca>
 *   @0x2fe6ba orr r3, r3, #0x8000
 *   @0x2fe6be lsls r0, r2, #0x15
 *   @0x2fe6c2 orrmi r3, r3, #0x20000
 *   @0x2fe6c6 lsls r1, r2, #0x14
 *   @0x2fe6ca orrmi r3, r3, #0x40000
 *   @0x2fe6ce lsls r7, r2, #0x13
 *   @0x2fe6d2 ldrb.w r2, [r4, #0x26a]
 *   @0x2fe6d6 cbz r2, 0x2fe6dc <TT_RunIns+0x18e8>
 *   @0x2fe6e2 mov r0, r4
 *   @0x2fe6e6 bl 0x2f9678 <ps_hints_apply+0x8278>
 *   @0x2fe6ea b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe6ee ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe6f2 ldr r2, [r7, #0x4]
 *   @0x2fe6f6 str r3, [r7, #0x8]
 *   @0x2fe6fe ldr r3, [r7, #0x4]
 *   @0x2fe706 ble.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe70a str.w r3, [r5, r6, lsl #2]
 *   @0x2fe70e b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe712 ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fe716 cmp r3, r2
 *   @0x2fe722 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe726 cmp r3, #0x0
 *   @0x2fe72e str.w r3, [r4, #0x158]
 *   @0x2fe732 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe736 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe73a subs r1, r2, #0x1
 *   @0x2fe73e bhi.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe742 movs r0, #0x1
 *   @0x2fe74a cmp r3, r1
 *   @0x2fe756 bic.w r1, r0, r1
 *   @0x2fe75a orr.w r1, r1, r3
 *   @0x2fe75e strb.w r1, [r4, #0x154]
 *   @0x2fe762 bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe766 ldr r2, [r4]
 *   @0x2fe76a ldr r2, [r2, #0x40]
 *   @0x2fe76e bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe772 subs r3, #0x4
 *   @0x2fe776 movne r3, #0x1
 *   @0x2fe77e mov r0, r4
 *   @0x2fe786 ldr r3, [r4]
 *   @0x2fe78e ldr r1, [r3]
 *   @0x2fe792 ldr r0, [r3, #0x8]
 *   @0x2fe796 subs r3, r2, r3
 *   @0x2fe79a bhs 0x2fe7a2 <TT_RunIns+0x19ae>
 *   @0x2fe79e movs r3, #0x0
 *   @0x2fe7a2 movs r3, #0x82
 *   @0x2fe7a6 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe7aa beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe7ae ldr r2, [r0, r3]
 *   @0x2fe7b2 str r2, [r7, r3]
 *   @0x2fe7b6 b 0x2fe7a8 <TT_RunIns+0x19b4>
 *   @0x2fe7ba bhi 0x2fe7e8 <TT_RunIns+0x19f4>
 *   @0x2fe7be bhi.w 0x2fe9a4 <TT_RunIns+0x1bb0>
 *   @0x2fe7c2 cmp r3, #0xb7
 *   @0x2fe7ca bhi.w 0x2feb78 <TT_RunIns+0x1d84>
 *   @0x2fe7ce mov r0, r4
 *   @0x2fe7d6 ldr r3, [r4]
 *   @0x2fe7de beq 0x2fe7ce <TT_RunIns+0x19da>
 *   @0x2fe7e2 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe7e6 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe7f6 ldr.w r9, [r4, #0x144]
 *   @0x2fe7fa ldr r1, [r7, #0x4]
 *   @0x2fe7fe ldr.w r3, [r4, #0x180]
 *   @0x2fe802 adds r0, r1, #0x1
 *   @0x2fe806 cmp r0, r3
 *   @0x2fe80a ldrh.w r2, [r4, #0x120]
 *   @0x2fe80e ldrh r3, [r4, #0x2c]
 *   @0x2fe812 blo 0x2fe824 <TT_RunIns+0x1a30>
 *   @0x2fe81a beq.w 0x2fe98a <TT_RunIns+0x1b96>
 *   @0x2fe81e movs r3, #0x86
 *   @0x2fe822 b 0x2fe98a <TT_RunIns+0x1b96>
 *   @0x2fe826 ldr.w r3, [r4, #0x258]
 *   @0x2fe82a mov r0, r4
 *   @0x2fe82e ldr.w r5, [r4, #0x14c]
 *   @0x2fe832 ldr.w r3, [r4, #0x148]
 *   @0x2fe836 subs r2, r0, r5
 *   @0x2fe83a it lt
 *   @0x2fe83e cmp r2, r3
 *   @0x2fe842 cmp r0, #0x0
 *   @0x2fe846 rsbs r5, r5, #0
 *   @0x2fe84a mov r5, r0
 *   @0x2fe852 ldrh.w r2, [r4, #0x120]
 *   @0x2fe856 mov r0, r5
 *   @0x2fe85a lsl.w r11, r6, #0x3
 *   @0x2fe85e ldrsh.w r1, [r4, #0x12e]
 *   @0x2fe862 ldr r7, [r4, #0x54]
 *   @0x2fe86e str.w r0, [r7, r6, lsl #3]
 *   @0x2fe872 ldrh.w r2, [r4, #0x120]
 *   @0x2fe876 mov r0, r5
 *   @0x2fe87a ldrsh.w r1, [r4, #0x130]
 *   @0x2fe87e add.w r3, r3, r2, lsl #3
 *   @0x2fe882 ldr r7, [r4, #0x54]
 *   @0x2fe88e add r0, r10
 *   @0x2fe892 ldr r3, [r4, #0x58]
 *   @0x2fe896 add r3, r11
 *   @0x2fe89a ldm.w r11, {r0, r1}
 *   @0x2fe89e stm.w r3, {r0, r1}
 *   @0x2fe8a2 ldrh.w r1, [r4, #0x120]
 *   @0x2fe8a6 lsl.w r10, r6, #0x3
 *   @0x2fe8aa ldr r7, [r4, #0x54]
 *   @0x2fe8ae add.w r0, r7, r10
 *   @0x2fe8b2 add.w r2, r3, r1, lsl #3
 *   @0x2fe8b6 ldr.w lr, [r7, r6, lsl #3]
 *   @0x2fe8ba ldr.w r1, [r3, r1, lsl #3]
 *   @0x2fe8be ldr r7, [r0, #0x4]
 *   @0x2fe8c2 ldr r2, [r2, #0x4]
 *   @0x2fe8ce blx r3
 *   @0x2fe8d6 ldr r1, [r4, #0x58]
 *   @0x2fe8da ldr.w r12, [r3, r2, lsl #3]
 *   @0x2fe8de ldr.w r1, [r1, r6, lsl #3]
 *   @0x2fe8e2 rsb r1, r12, r1
 *   @0x2fe8e6 mov r7, r0
 *   @0x2fe8f2 mov r0, r4
 *   @0x2fe8f6 ldr.w r3, [r4, #0x240]
 *   @0x2fe8fa blx r3
 *   @0x2fe902 cbz r3, 0x2fe90c <TT_RunIns+0x1b18>
 *   @0x2fe90a rsbmi r5, r5, #0
 *   @0x2fe91a ldrh.w r1, [r4, #0x15c]
 *   @0x2fe91e ldrh.w r2, [r4, #0x15e]
 *   @0x2fe922 cmp r1, r2
 *   @0x2fe926 subs r2, r5, r7
 *   @0x2fe92a it lt
 *   @0x2fe92e cmp r2, r9
 *   @0x2fe932 movgt r5, r7
 *   @0x2fe93a mov r0, r4
 *   @0x2fe946 b 0x2fe958 <TT_RunIns+0x1b64>
 *   @0x2fe94e mov r1, r5
 *   @0x2fe95e lsls r0, r2, #0x1c
 *   @0x2fe962 cmp r7, #0x0
 *   @0x2fe966 cmp r3, r8
 *   @0x2fe96a movlt r3, r8
 *   @0x2fe96e rsb.w r8, r8, #0x0
 *   @0x2fe972 cmp r3, r8
 *   @0x2fe976 movge r3, r8
 *   @0x2fe97e add.w r1, r4, #0x48
 *   @0x2fe982 mov r2, r6
 *   @0x2fe98a ldrh.w r3, [r4, #0x120]
 *   @0x2fe98e strh.w r6, [r4, #0x124]
 *   @0x2fe992 strh.w r3, [r4, #0x122]
 *   @0x2fe996 ldrb.w r3, [r4, #0x174]
 *   @0x2fe99a lsls r1, r3, #0x1b
 *   @0x2fe99e strhmi.w r6, [r4, #0x120]
 *   @0x2fe9a2 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe9b2 bls 0x2fe9be <TT_RunIns+0x1bca>
 *   @0x2fe9ba cmp r2, r3
 *   @0x2fe9be ldrb.w r3, [r4, #0x235]
 *   @0x2fe9c2 cmp r3, #0x0
 *   @0x2fe9ca str r3, [r4, #0xc]
 *   @0x2fe9ce ldrh.w r2, [r4, #0x15c]
 *   @0x2fe9d2 lsls r5, r3, #0x3
 *   @0x2fe9d6 ldrh.w r2, [r4, #0x15e]
 *   @0x2fe9da cbnz r2, 0x2fea02 <TT_RunIns+0x1c0e>
 *   @0x2fe9de ldr r2, [r4, #0x30]
 *   @0x2fe9e6 ldr.w lr, [r1, r6, lsl #3]
 *   @0x2fe9ea ldr.w r5, [r12, #0x4]
 *   @0x2fe9ee ldr.w r1, [r2, r3, lsl #3]
 *   @0x2fe9f2 ldr r2, [r0, #0x4]
 *   @0x2fe9f6 ldr.w r3, [r4, #0x244]
 *   @0x2fe9fa rsb r1, r1, lr
 *   @0x2fe9fe subs r2, r5, r2
 *   @0x2fea02 ldr.w r2, [r4, #0xe4]
 *   @0x2fea06 ldr.w r1, [r4, #0xe0]
 *   @0x2fea0a ldr.w lr, [r4, #0x5c]
 *   @0x2fea0e ldr r0, [r4, #0x38]
 *   @0x2fea12 add.w r8, lr, r6, lsl #3
 *   @0x2fea16 add r5, r0
 *   @0x2fea22 ldr.w r3, [r8, #0x4]
 *   @0x2fea26 rsb r1, r2, lr
 *   @0x2fea2a ldr r5, [r5, #0x4]
 *   @0x2fea2e subs r2, r3, r5
 *   @0x2fea36 ldr.w r1, [r4, #0xe0]
 *   @0x2fea3a bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fea3e b 0x2fea66 <TT_RunIns+0x1c72>
 *   @0x2fea4a ldr.w r1, [r4, #0xe4]
 *   @0x2fea4e mov r9, r0
 *   @0x2fea56 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fea5a ldr.w r3, [r4, #0x244]
 *   @0x2fea5e mov r1, r9
 *   @0x2fea62 mov r0, r4
 *   @0x2fea66 ldr.w r5, [r4, #0x14c]
 *   @0x2fea6a ldr.w r3, [r4, #0x148]
 *   @0x2fea6e subs r2, r0, r5
 *   @0x2fea72 it lt
 *   @0x2fea76 cmp r2, r3
 *   @0x2fea7a cmp r0, #0x0
 *   @0x2fea7e rsbs r5, r5, #0
 *   @0x2fea82 mov r5, r0
 *   @0x2fea92 add.w r2, r4, r3, lsl #2
 *   @0x2fea96 mov r0, r4
 *   @0x2fea9e ldr.w r2, [r2, #0x10c]
 *   @0x2feaa2 blx r3
 *   @0x2feaa6 add.w r3, r4, r3, lsl #2
 *   @0x2feaaa mov r0, r4
 *   @0x2feaae ldr.w r2, [r3, #0x10c]
 *   @0x2feab2 bl 0x2f9384 <ps_hints_apply+0x7f84>
 *   @0x2feab6 ldrb.w r3, [r4, #0x174]
 *   @0x2feaba mov r8, r0
 *   @0x2feabe bpl 0x2fead4 <TT_RunIns+0x1ce0>
 *   @0x2feac2 blt 0x2feacc <TT_RunIns+0x1cd8>
 *   @0x2feac6 it lt
 *   @0x2feaca b 0x2fead4 <TT_RunIns+0x1ce0>
 *   @0x2feace cmp r8, r7
 *   @0x2fead2 movge r8, r7
 *   @0x2feada ldr r3, [r4, #0x34]
 *   @0x2feaee mov r0, r4
 *   @0x2feaf2 subs r1, r7, r1
 *   @0x2feafa blx r5
 *   @0x2feb06 rsb r3, r0, r8
 *   @0x2feb0a mov r0, r4
 *   @0x2feb0e ldrh.w r3, [r4, #0x120]
 *   @0x2feb12 strh.w r6, [r4, #0x124]
 *   @0x2feb16 strh.w r3, [r4, #0x122]
 *   @0x2feb1a ldrb.w r3, [r4, #0x174]
 *   @0x2feb1e lsls r3, r3, #0x1b
 *   @0x2feb22 strh.w r6, [r4, #0x120]
 *   @0x2feb26 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2feb2a adds r2, #0x1
 *   @0x2feb2e ldr r3, [r4, #0x10]
 *   @0x2feb32 cmp r6, r3
 *   @0x2feb3e adds r3, #0x1
 *   @0x2feb46 bl 0x2f92e2 <ps_hints_apply+0x7ee2>
 *   @0x2feb4a str.w r0, [r7, r5, lsl #2]
 *   @0x2feb4e adds r5, #0x1
 *   @0x2feb52 cmp r3, r6
 *   @0x2feb56 movs r3, #0x0
 *   @0x2feb5e nop
 *   @0x2feb62 .word 0xffff d105
 *   @0x2feb66 .word 0xffff d121
 *   @0x2feb6a .word 0xffff ae29
 *   @0x2feb6e .word 0xffff d051
 *   @0x2feb72 .word 0xffff d021
 *   @0x2feb76 vtbl.8 d19, {d31, fpinst2, mvfr0, mvfr1}, d31
 *   @0x2feb7a ldr r1, [r4, #0x10]
 *   @0x2feb7e uxth r3, r3
 *   @0x2feb82 cmp r3, r1
 *   @0x2feb8a ldr.w r5, [r4, #0x168]
 *   @0x2feb8e add.w r1, r2, #0x40000000
 *   @0x2feb92 ldr.w r0, [r4, #0x16c]
 *   @0x2feb96 subs r1, #0x1
 *   @0x2feb9a ldrb r0, [r0, r2]
 *   @0x2feb9e uxth r2, r2
 *   @0x2feba2 str.w r0, [r7, r1, lsl #2]
 *   @0x2feba6 bls 0x2feb8a <TT_RunIns+0x1d96>
 *   @0x2febaa cbz r3, 0x2fec10 <TT_RunIns+0x1e1c>
 *   @0x2febae bne 0x2fec5a <TT_RunIns+0x1e66>
 *   @0x2febb6 ldr.w r2, [r4, #0x19c]
 *   @0x2febba mla r2, r1, r2, r3
 *   @0x2febbe cmp r3, r2
 *   @0x2febc2 ldrb r1, [r3, #0x10]
 *   @0x2febc6 ldrb.w r0, [r4, #0x174]
 *   @0x2febca ldrb r1, [r3, #0xc]
 *   @0x2febce bne 0x2fec0c <TT_RunIns+0x1e18>
 *   @0x2febda blt 0x2febe0 <TT_RunIns+0x1dec>
 *   @0x2febde b 0x2fec58 <TT_RunIns+0x1e64>
 *   @0x2febe6 ldr.w r0, [r4, #0x164]
 *   @0x2febea adds r2, r5, r1
 *   @0x2febee mov r0, r4
 *   @0x2febf6 adds r1, #0x1
 *   @0x2febfa movs r1, #0x1
 *   @0x2febfe ldm.w r3, {r1, r2}
 *   @0x2fec02 bl 0x2fb3f6 <ps_hints_apply+0x9ff6>
 *   @0x2fec06 cmp r0, #0x1
 *   @0x2fec0a b 0x2fec5a <TT_RunIns+0x1e66>
 *   @0x2fec0e b 0x2febbe <TT_RunIns+0x1dca>
 *   @0x2fec12 str r3, [r4, #0x10]
 *   @0x2fec1a ldr.w r2, [r4, #0x16c]
 *   @0x2fec1e ldr.w r3, [r4, #0x178]
 *   @0x2fec22 add r3, r2
 *   @0x2fec2a ldr r3, [pc, #0x40]
 *   @0x2fec2e str r5, [sp, #0x18]
 *   @0x2fec32 bhi 0x2fec5e <TT_RunIns+0x1e6a>
 *   @0x2fec3e blt 0x2fec4a <TT_RunIns+0x1e56>
 *   @0x2fec46 bgt 0x2fec56 <TT_RunIns+0x1e62>
 *   @0x2fec4a ldrb.w r3, [r4, #0x1ec]
 *   @0x2fec4e cmp r3, #0x0
 *   @0x2fec56 movs r3, #0x83
 *   @0x2fec5a ldr r0, [r4, #0xc]
 *   @0x2fec5e movs r0, #0x8b
 *   @0x2fec62 movs r0, #0x0
 *   @0x2fec66 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2fec6a nop
 *   @0x2fec6e movs r7, r1
 *
 * ══ anon_300004  0x300004  size 512  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x300204 0x300208  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x300204 svchi #0xf0e8bd
 *
 * ══ TT_New_Context  0x300208  size 106  本节 23 条（Thumb-2 半字段）｜入度 3
 * @func 0x30020a 0x300272  size 104  23 条
 * 部分覆盖: 本节 23/49 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x30020a sub sp, #0x14
 *   @0x30020e movs r0, #0x0
 *   @0x300212 ldr r5, [r0, #0x8]
 *   @0x300216 mov.w r1, #0x27c
 *   @0x30021a mov r0, r5
 *   @0x300222 mov r4, r0
 *   @0x300226 bne 0x30020e <TT_New_Context+0x6>
 *   @0x30022a movs r3, #0x20
 *   @0x30022e str.w r3, [r0, #0x1b4]
 *   @0x300232 str r1, [sp, #0x4]
 *   @0x300236 str r2, [sp]
 *   @0x30023a bl 0x2e808e <ft_mem_realloc>
 *   @0x30023e ldr r3, [sp, #0xc]
 *   @0x300246 strh.w r3, [r4, #0x1bc]
 *   @0x30024a strh.w r3, [r4, #0x1be]
 *   @0x30024e str r3, [r4, #0x14]
 *   @0x300256 str.w r3, [r4, #0x18c]
 *   @0x30025a str r3, [r4]
 *   @0x30025e b 0x30026c <TT_New_Context+0x64>
 *   @0x300262 bl 0x2fa06c <ps_hints_apply+0x8c6c>
 *   @0x300266 ldr r3, [sp, #0xc]
 *   @0x30026a bne 0x30020e <TT_New_Context+0x6>
 *   @0x30026e add sp, #0x14
 *
 * ══ anon_300274  0x300274  size 39052  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x309b00 0x309b04  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x309b00 stcllt p7, c15, [r0, #1020]
 *
 * ══ af_shaper_get_coverage  0x309b04  size 4  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x309b06 0x309b0a  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x309b06 bx lr
 *
 * ══ anon_30a6bc  0x30a6bc  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x30a6bc 0x30a6c0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x30a6bc andeq r4, r8, r11, lsr r9
 *
 * ══ af_shaper_buf_create  0x30a6c0  size 20  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x30a6c2 0x30a6d2  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x30a6c2 movs r1, #0x4
 *   @0x30a6c6 add.w r2, sp, r1
 *   @0x30a6ca bl 0x2e7126 <ft_mem_alloc>
 *   @0x30a6ce add sp, #0xc
 *
 * ══ af_shaper_buf_destroy  0x30a6d4  size 6  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x30a6d6 0x30a6da  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x30a6d6 b.w 0x2e7336 <ft_mem_free>
 *
 * ══ af_shaper_get_cluster  0x30a6da  size 184  本节 37 条（Thumb-2 半字段）｜入度 7
 * @func 0x30a6e0 0x30a790  size 176  37 条
 * 部分覆盖: 本节 37/81 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x30a6e0 ldr r3, [r1, #0x24]
 *   @0x30a6e4 ldr r3, [r3]
 *   @0x30a6e8 ldrb r1, [r0], #1
 *   @0x30a6ec cmp r1, #0x20
 *   @0x30a6f0 cmp r1, #0x7f
 *   @0x30a6f4 bls 0x30a728 <af_shaper_get_cluster+0x4e>
 *   @0x30a6f8 bhi 0x30a704 <af_shaper_get_cluster+0x2a>
 *   @0x30a700 adds r2, r4, r5
 *   @0x30a704 cmp r1, #0xef
 *   @0x30a708 andls r1, r1, #0xf
 *   @0x30a70c andhi r1, r1, #0x7
 *   @0x30a710 movls r5, #0x2
 *   @0x30a714 b 0x30a700 <af_shaper_get_cluster+0x26>
 *   @0x30a71c and r6, r6, #0x3f
 *   @0x30a720 orr.w r1, r6, r1, lsl #6
 *   @0x30a724 bne 0x30a716 <af_shaper_get_cluster+0x3c>
 *   @0x30a728 movs r4, #0x0
 *   @0x30a72c mov r6, r5
 *   @0x30a730 ands r2, r7, #0xdf
 *   @0x30a734 beq 0x30a770 <af_shaper_get_cluster+0x96>
 *   @0x30a738 mov r2, r5
 *   @0x30a73c bls 0x30a72a <af_shaper_get_cluster+0x50>
 *   @0x30a740 bhi 0x30a74c <af_shaper_get_cluster+0x72>
 *   @0x30a748 add r5, r0
 *   @0x30a74c cmp r7, #0xef
 *   @0x30a750 andls r4, r7, #0xf
 *   @0x30a754 andhi r4, r4, #0x7
 *   @0x30a758 movls r0, #0x2
 *   @0x30a75c b 0x30a748 <af_shaper_get_cluster+0x6e>
 *   @0x30a764 and r0, r0, #0x3f
 *   @0x30a768 orr.w r4, r0, r4, lsl #6
 *   @0x30a76c bne 0x30a75e <af_shaper_get_cluster+0x84>
 *   @0x30a770 cbz r4, 0x30a77c <af_shaper_get_cluster+0xa2>
 *   @0x30a77c mov r0, r3
 *   @0x30a784 str.w r0, [r8]
 *   @0x30a788 str.w r3, [r9]
 *   @0x30a78c mov r0, r6
 *
 * ══ af_shaper_get_elem  0x30a792  size 32  本节 8 条（Thumb-2 半字段）｜入度 0
 * @func 0x30a794 0x30a7b4  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x30a794 ldr r2, [r0, #0x24]
 *   @0x30a798 ldr r5, [r1]
 *   @0x30a79c cbz r3, 0x30a7a8 <af_shaper_get_elem+0x16>
 *   @0x30a7a0 movw r2, #0x803
 *   @0x30a7a4 bl 0x2e7950 <FT_Get_Advance>
 *   @0x30a7a8 cbz r4, 0x30a7ae <af_shaper_get_elem+0x1c>
 *   @0x30a7ac str r3, [r4]
 *   @0x30a7b0 pop {r3, r4, r5, pc}
 *
 * ══ anon_30a7b2  0x30a7b2  size 41480  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x3149ba 0x3149c6  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x3149ba strlt r8, [r8, #-0x7f0]
 *
 * ══ FT_Bitmap_Init  0x3149bc  size 14  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x3149be 0x3149c6  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x3149be cbz r0, 0x3149c8 <FT_Bitmap_Init+0xc>
 *   @0x3149c2 movs r2, #0x18
 *
 * ══ FT_Bitmap_New  0x3149ca  size 14  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x3149cc 0x3149d4  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x3149cc cbz r0, 0x3149d6 <FT_Bitmap_New+0xc>
 *   @0x3149d0 movs r2, #0x18
 *
 * ══ FT_Bitmap_Copy  0x3149d8  size 248  本节 54 条（Thumb-2 半字段）｜入度 9
 * @func 0x3149de 0x314ace  size 240  54 条
 * 部分覆盖: 本节 54/114 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x3149de movs r3, #0x0
 *   @0x3149e2 mov r4, r2
 *   @0x3149e6 cmp r0, #0x0
 *   @0x3149ea cmp r1, #0x0
 *   @0x3149ee cmp r2, #0x0
 *   @0x3149f2 cmp r1, r2
 *   @0x3149f6 movs r0, #0x0
 *   @0x3149fa ldr r7, [r1, #0x8]
 *   @0x3149fe ldr.w r12, [r1, #0xc]
 *   @0x314a02 cmp r7, #0x0
 *   @0x314a06 movge.w r9, #0x1
 *   @0x314a0a movlt.w r9, #0xffffffff
 *   @0x314a0e cmp r2, #0x0
 *   @0x314a12 movge.w r8, #0x1
 *   @0x314a16 movlt.w r8, #0xffffffff
 *   @0x314a1a cmp.w r12, #0x0
 *   @0x314a1e bne 0x314a38 <FT_Bitmap_Copy+0x60>
 *   @0x314a22 mov r6, r4
 *   @0x314a26 stm r6!, {r0, r1, r2, r3}
 *   @0x314a32 rsbs r7, r7, #0
 *   @0x314a36 b 0x3149f6 <FT_Bitmap_Copy+0x1e>
 *   @0x314a3a eor.w r10, r7, r7, asr #31
 *   @0x314a3e sub.w r10, r10, r7, asr #31
 *   @0x314a42 ldr r0, [r0]
 *   @0x314a4a cbz r3, 0x314a6a <FT_Bitmap_Copy+0x92>
 *   @0x314a4e cmp r2, #0x0
 *   @0x314a52 rsblt r2, r2, #0
 *   @0x314a56 cmp r2, r11
 *   @0x314a5a str r3, [sp]
 *   @0x314a5e add r3, sp, #0xc
 *   @0x314a62 mov r3, r11
 *   @0x314a6a mov r1, r11
 *   @0x314a6e bl 0x2e7100 <ft_mem_qalloc>
 *   @0x314a72 str r0, [r4, #0xc]
 *   @0x314a76 cbnz r3, 0x314ac0 <FT_Bitmap_Copy+0xe8>
 *   @0x314a7a mov r6, r4
 *   @0x314a7e cmp r9, r8
 *   @0x314a86 ldm.w r7, {r0, r1}
 *   @0x314a8a stm.w r6, {r0, r1}
 *   @0x314a8e str.w r12, [r4, #0xc]
 *   @0x314a92 ldr r1, [r5, #0xc]
 *   @0x314a96 mov r0, r12
 *   @0x314a9a blx 0xb65bc <memcpy@plt>
 *   @0x314a9e b 0x314ac0 <FT_Bitmap_Copy+0xe8>
 *   @0x314aa2 mov r5, r1
 *   @0x314aa6 mla r12, r3, r10, r12
 *   @0x314aaa cbz r4, 0x314ac0 <FT_Bitmap_Copy+0xe8>
 *   @0x314aae mov r1, r5
 *   @0x314ab2 add r5, r10
 *   @0x314aba rsb r12, r10, r0
 *   @0x314abe b 0x314aaa <FT_Bitmap_Copy+0xd2>
 *   @0x314ac2 b 0x314aca <FT_Bitmap_Copy+0xf2>
 *   @0x314ac6 b 0x314aca <FT_Bitmap_Copy+0xf2>
 *   @0x314aca add sp, #0x14
 *
 * ══ FT_Bitmap_Convert  0x314ad0  size 752  本节 146 条（Thumb-2 半字段）｜入度 17
 * @func 0x314ad6 0x314dbe  size 744  146 条
 * 部分覆盖: 本节 146/332 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x314ad6 mov r4, r1
 *   @0x314ada movs r1, #0x0
 *   @0x314ade str r1, [sp, #0x1c]
 *   @0x314ae2 beq.w 0x314db8 <FT_Bitmap_Convert+0x2e8>
 *   @0x314ae6 cbnz r4, 0x314aec <FT_Bitmap_Convert+0x1c>
 *   @0x314aea b 0x314dba <FT_Bitmap_Convert+0x2ea>
 *   @0x314aee beq 0x314ae8 <FT_Bitmap_Convert+0x18>
 *   @0x314af2 ldr.w r8, [r0]
 *   @0x314af6 subs r3, #0x1
 *   @0x314afa bhi 0x314b78 <FT_Bitmap_Convert+0xa8>
 *   @0x314afe strb r3, [r2, #0x12]
 *   @0x314b02 cmp.w r11, #0x0
 *   @0x314b06 ldr.w r9, [r2]
 *   @0x314b0a ldr.w r10, [r2, #0x8]
 *   @0x314b0e str r7, [r2]
 *   @0x314b12 str r3, [r2, #0x4]
 *   @0x314b16 ble 0x314b26 <FT_Bitmap_Convert+0x56>
 *   @0x314b1a mov r1, r11
 *   @0x314b22 rsb r1, r1, r11
 *   @0x314b26 add r6, r1
 *   @0x314b2a ble 0x314b3a <FT_Bitmap_Convert+0x6a>
 *   @0x314b32 blx 0x318c48 <__udivsi3>
 *   @0x314b36 cmp r7, r0
 *   @0x314b3a cmp.w r10, #0x0
 *   @0x314b3e it lt
 *   @0x314b4e bhi 0x314b5a <FT_Bitmap_Convert+0x8a>
 *   @0x314b52 cmp r3, #0x0
 *   @0x314b56 rsbs r6, r6, #0
 *   @0x314b5a ldr r1, [r5, #0xc]
 *   @0x314b5e str r1, [sp]
 *   @0x314b62 str r1, [sp, #0x4]
 *   @0x314b66 bl 0x2e8010 <ft_mem_qrealloc>
 *   @0x314b6a str r0, [r5, #0xc]
 *   @0x314b6e cmp r0, #0x0
 *   @0x314b72 b 0x314dba <FT_Bitmap_Convert+0x2ea>
 *   @0x314b76 b 0x314b7c <FT_Bitmap_Convert+0xac>
 *   @0x314b7a str r3, [sp, #0x1c]
 *   @0x314b7e ldr r7, [r4, #0xc]
 *   @0x314b82 ldr r6, [r5, #0xc]
 *   @0x314b86 ldr r2, [r4]
 *   @0x314b8a mls r7, r2, r3, r7
 *   @0x314b8e ldr r3, [r5, #0x8]
 *   @0x314b92 bge 0x314b9c <FT_Bitmap_Convert+0xcc>
 *   @0x314b96 subs r2, #0x1
 *   @0x314b9e subs r3, #0x1
 *   @0x314ba2 bhi.w 0x314db4 <FT_Bitmap_Convert+0x2e4>
 *   @0x314ba6 tbb [pc, r3]
 *   @0x314baa ldr r4, [pc, #0x10]
 *   @0x314bae ldr r4, [pc, #0x130]
 *   @0x314bb2 movs r3, #0x2
 *   @0x314bb6 ldr r0, [r4]
 *   @0x314bba beq.w 0x314db4 <FT_Bitmap_Convert+0x2e4>
 *   @0x314bbe ldr r3, [r4, #0x4]
 *   @0x314bc2 lsr.w r12, r3, #0x3
 *   @0x314bc6 mov r3, r6
 *   @0x314bca beq 0x314c14 <FT_Bitmap_Convert+0x144>
 *   @0x314bce adds r3, #0x8
 *   @0x314bd2 lsr.w r8, r2, #0x7
 *   @0x314bd6 strb r8, [r3, #-8]
 *   @0x314bda ubfx r8, r2, #0x6, #0x1
 *   @0x314bde strb r8, [r3, #-7]
 *   @0x314be2 ubfx r8, r2, #0x5, #0x1
 *   @0x314be6 strb r8, [r3, #-6]
 *   @0x314bea ubfx r8, r2, #0x4, #0x1
 *   @0x314bee strb r8, [r3, #-5]
 *   @0x314bf2 ubfx r8, r2, #0x3, #0x1
 *   @0x314bf6 strb r8, [r3, #-4]
 *   @0x314bfa ubfx r8, r2, #0x2, #0x1
 *   @0x314bfe strb r8, [r3, #-3]
 *   @0x314c02 ubfx r8, r2, #0x1, #0x1
 *   @0x314c06 and r2, r2, #0x1
 *   @0x314c0a strb r8, [r3, #-2]
 *   @0x314c0e strb r2, [r3, #-1]
 *   @0x314c12 b 0x314bc8 <FT_Bitmap_Convert+0xf8>
 *   @0x314c16 add.w r3, r6, r1, lsl #3
 *   @0x314c1a ands r12, r2, #0x7
 *   @0x314c1e beq 0x314c36 <FT_Bitmap_Convert+0x166>
 *   @0x314c22 add.w r1, r3, r12
 *   @0x314c26 ubfx r12, r2, #0x7, #0x1
 *   @0x314c2a strb r12, [r3], #1
 *   @0x314c2e cmp r3, r1
 *   @0x314c36 ldr r3, [r4, #0x8]
 *   @0x314c3a add r7, r3
 *   @0x314c3e add r6, r3
 *   @0x314c42 ldr.w r9, [r4, #0x4]
 *   @0x314c46 mov.w r3, #0x100
 *   @0x314c4a strh r3, [r5, #0x10]
 *   @0x314c5a mov r1, r7
 *   @0x314c5e add.w r8, r8, #0xffffffff
 *   @0x314c62 blx 0xb65bc <memcpy@plt>
 *   @0x314c66 ldr r3, [r4, #0x8]
 *   @0x314c6a ldr r3, [r5, #0x8]
 *   @0x314c6e b 0x314c50 <FT_Bitmap_Convert+0x180>
 *   @0x314c72 strh r3, [r5, #0x10]
 *   @0x314c76 cmp r0, #0x0
 *   @0x314c7e mov r2, r6
 *   @0x314c86 cmp r3, r12
 *   @0x314c8a ldrb r1, [r7, r3]
 *   @0x314c8e adds r3, #0x1
 *   @0x314cb2 ldr r1, [r4, #0x4]
 *   @0x314cbe ldrb r3, [r7, r3]
 *   @0x314cc2 ubfx r12, r3, #0x6, #0x2
 *   @0x314cc6 strb r12, [r2], #1
 *   @0x314cca cmp r2, r1
 *   @0x314cd2 ldr r3, [r4, #0x8]
 *   @0x314cd6 add r7, r3
 *   @0x314cda add r6, r3
 *   @0x314cde movs r3, #0x10
 *   @0x314ce2 ldr r1, [r4]
 *   @0x314ce6 beq 0x314db4 <FT_Bitmap_Convert+0x2e4>
 *   @0x314cea mov r2, r6
 *   @0x314cf2 cmp r3, r12
 *   @0x314cfa ldrb r0, [r7, r3]
 *   @0x314cfe lsr.w r8, r0, #0x4
 *   @0x314d02 and r0, r0, #0xf
 *   @0x314d06 strb r8, [r2, #-2]
 *   @0x314d0a strb r0, [r2, #-1]
 *   @0x314d0e b 0x314cf2 <FT_Bitmap_Convert+0x222>
 *   @0x314d12 lsls r2, r2, #0x1f
 *   @0x314d16 ldrb r2, [r7, r3]
 *   @0x314d1a strb.w r2, [r6, r3, lsl #1]
 *   @0x314d1e ldr r3, [r4, #0x8]
 *   @0x314d22 add r7, r3
 *   @0x314d26 add r6, r3
 *   @0x314d2a mov.w r3, #0x100
 *   @0x314d2e strh r3, [r5, #0x10]
 *   @0x314d3e ldr r1, [r4, #0x4]
 *   @0x314d42 mov r8, r7
 *   @0x314d4a beq 0x314da6 <FT_Bitmap_Convert+0x2d6>
 *   @0x314d56 ldrb.w r0, [r8]
 *   @0x314d5a movw r3, #0x127c
 *   @0x314d5e ldrb.w lr, [r8, #0x1]
 *   @0x314d62 ldrb.w r1, [r8, #0x2]
 *   @0x314d66 smulbb r0, r0, r0
 *   @0x314d6a str r2, [sp, #0x10]
 *   @0x314d7a movw r3, #0xb717
 *   @0x314d7e mla lr, r3, lr, r0
 *   @0x314d82 mla r0, r2, r1, lr
 *   @0x314d86 mov r1, r9
 *   @0x314d8a blx 0x318c48 <__udivsi3>
 *   @0x314d8e ldr r2, [sp, #0x10]
 *   @0x314da6 ldr r1, [r4, #0x8]
 *   @0x314dae ldr r1, [r5, #0x8]
 *   @0x314db2 b 0x314d38 <FT_Bitmap_Convert+0x268>
 *   @0x314db6 b 0x314dba <FT_Bitmap_Convert+0x2ea>
 *   @0x314dba add sp, #0x24
 *
 * ══ FT_GlyphSlot_Own_Bitmap  0x314dc0  size 92  本节 18 条（Thumb-2 半字段）｜入度 3
 * @func 0x314dc2 0x314e2a  size 104  21 条
 * 部分覆盖: 本节 21/47 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 20/45 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 19/43 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 18/41 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x314dc2 mov r6, r0
 *   @0x314dc6 cbz r0, 0x314e10 <FT_GlyphSlot_Own_Bitmap+0x50>
 *   @0x314dca ldr r2, [pc, #0x4c]
 *   @0x314dce bne 0x314e12 <FT_GlyphSlot_Own_Bitmap+0x52>
 *   @0x314dd6 lsls r3, r3, #0x1f
 *   @0x314dda add.w r4, r6, #0x4c
 *   @0x314dde mov r0, sp
 *   @0x314de6 mov r1, r4
 *   @0x314dea bl 0x3149d8 <FT_Bitmap_Copy>
 *   @0x314dee mov r7, r0
 *   @0x314df2 mov r5, sp
 *   @0x314df6 stm r4!, {r0, r1, r2, r3}
 *   @0x314e06 orr r2, r2, #0x1
 *   @0x314e0a str r2, [r3, #0x4]
 *   @0x314e0e b 0x314e14 <FT_GlyphSlot_Own_Bitmap+0x54>
 *   @0x314e12 movs r0, #0x0
 *   @0x314e16 pop {r4, r5, r6, r7, pc}
 *   @0x314e1a str r1, [r5, #0x24]
 *
 * ══ FT_Bitmap_Done  0x314e1c  size 42  本节 10 条（Thumb-2 半字段）｜入度 0
 * @func 0x314e1e 0x314e46  size 40  10 条
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x314e1e mov r4, r1
 *   @0x314e22 cbz r1, 0x314e42 <FT_Bitmap_Done+0x26>
 *   @0x314e26 ldr r0, [r0]
 *   @0x314e2a bl 0x2e7336 <ft_mem_free>
 *   @0x314e2e str r5, [r4, #0xc]
 *   @0x314e32 mov r1, r5
 *   @0x314e36 blx 0xb65b0 <memset@plt>
 *   @0x314e3a mov r0, r5
 *   @0x314e3e movs r0, #0x21
 *   @0x314e42 movs r0, #0x6
 *
 * ══ FT_Bitmap_Embolden  0x314e46  size 838  本节 162 条（Thumb-2 半字段）｜入度 37
 * @func 0x314e4c 0x31518c  size 832  162 条
 * 部分覆盖: 本节 162/370 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x314e4c sub sp, #0x3c
 *   @0x314e50 cmp r0, #0x0
 *   @0x314e58 beq.w 0x315180 <FT_Bitmap_Embolden+0x33a>
 *   @0x314e5c ldr r1, [r1, #0xc]
 *   @0x314e60 beq.w 0x315180 <FT_Bitmap_Embolden+0x33a>
 *   @0x314e64 add.w r5, r2, #0x20
 *   @0x314e68 adds r3, #0x20
 *   @0x314e6c asr.w r11, r3, #0x6
 *   @0x314e70 cmp r5, #0x0
 *   @0x314e74 cmp.w r11, #0x0
 *   @0x314e78 bne 0x314e80 <FT_Bitmap_Embolden+0x3a>
 *   @0x314e7c blt.w 0x315180 <FT_Bitmap_Embolden+0x33a>
 *   @0x314e80 cmp.w r11, #0x0
 *   @0x314e84 blt.w 0x315180 <FT_Bitmap_Embolden+0x33a>
 *   @0x314e88 ldrb r3, [r4, #0x12]
 *   @0x314e8c cmp r3, #0x6
 *   @0x314e90 tbh [pc, r3, lsl #1]
 *   @0x314e94 movs r0, r4
 *   @0x314e98 movs r7, r0
 *   @0x314e9c movs r4, r4
 *   @0x314ea0 lsls r0, r7, #0x5
 *   @0x314ea4 mov r0, r7
 *   @0x314eac mov r1, r4
 *   @0x314eb0 movs r3, #0x1
 *   @0x314eb8 bne.w 0x315186 <FT_Bitmap_Embolden+0x340>
 *   @0x314ebc mov r1, r4
 *   @0x314ec0 bl 0x314e1c <FT_Bitmap_Done>
 *   @0x314ec4 ldm r7!, {r0, r1, r2, r3}
 *   @0x314ec8 stm r6!, {r0, r1, r2, r3}
 *   @0x314ed4 cmp r5, #0x8
 *   @0x314ed8 movge r5, #0x8
 *   @0x314edc movs r3, #0x3
 *   @0x314ee0 b 0x314ee8 <FT_Bitmap_Embolden+0xa2>
 *   @0x314ee4 mul r11, r3, r11
 *   @0x314ee8 ldr.w r6, [r9]
 *   @0x314eec ldrb r3, [r4, #0x12]
 *   @0x314ef0 subs r3, #0x1
 *   @0x314ef4 ldm.w r4, {r9, r10}
 *   @0x314ef8 cmp r7, #0x0
 *   @0x314efc rsblt r7, r7, #0
 *   @0x314f00 bhi.w 0x315078 <FT_Bitmap_Embolden+0x232>
 *   @0x314f04 tbb [pc, r3]
 *   @0x314f08 adds r3, r0, r0
 *   @0x314f0c adds r0, r3, r0
 *   @0x314f18 lsrs r6, r6, #0x3
 *   @0x314f1c add.w r6, r10, #0x3
 *   @0x314f20 mov.w r8, #0x2
 *   @0x314f24 add r6, r5
 *   @0x314f28 b 0x314f40 <FT_Bitmap_Embolden+0xfa>
 *   @0x314f34 lsrs r6, r6, #0x1
 *   @0x314f38 add.w r6, r5, r10
 *   @0x314f3c mov.w r8, #0x8
 *   @0x314f40 cmp.w r11, #0x0
 *   @0x314f44 bne 0x314fae <FT_Bitmap_Embolden+0x168>
 *   @0x314f48 bgt 0x314fae <FT_Bitmap_Embolden+0x168>
 *   @0x314f5c and r10, r6, #0x7
 *   @0x314f60 mov.w r8, #0xff00
 *   @0x314f64 add.w r6, r3, r6, lsr #3
 *   @0x314f68 add.w r12, r3, r7
 *   @0x314f6c lsr.w r8, r8, r10
 *   @0x314f70 adds r6, #0x1
 *   @0x314f74 cmp.w r9, #0x0
 *   @0x314f78 beq 0x315068 <FT_Bitmap_Embolden+0x222>
 *   @0x314f80 ldrb r3, [r6, #-1]
 *   @0x314f84 mov r0, r6
 *   @0x314f90 bhs 0x314fa4 <FT_Bitmap_Embolden+0x15e>
 *   @0x314f98 str.w r12, [sp, #0x10]
 *   @0x314f9c blx 0xb65b0 <memset@plt>
 *   @0x314fa0 ldr.w r12, [sp, #0x10]
 *   @0x314fa4 add.w r9, r9, #0xffffffff
 *   @0x314fa8 add r12, r7
 *   @0x314fac b 0x314f72 <FT_Bitmap_Embolden+0x12c>
 *   @0x314fb0 add r3, sp, #0x20
 *   @0x314fb8 str r2, [sp]
 *   @0x314fbc ldr r0, [sp, #0x18]
 *   @0x314fc4 ldr r0, [sp, #0x20]
 *   @0x314fc8 bne.w 0x315186 <FT_Bitmap_Embolden+0x340>
 *   @0x314fcc ldr r3, [r4, #0x8]
 *   @0x314fd4 add.w r10, r10, #0x7
 *   @0x314fd8 ble 0x315032 <FT_Bitmap_Embolden+0x1ec>
 *   @0x314fe4 str.w r10, [sp, #0x1c]
 *   @0x314fe8 mla r12, r11, r6, r12
 *   @0x314fec mov r2, r0
 *   @0x314ff0 ldr r1, [r4]
 *   @0x314ff4 add r8, r6
 *   @0x314ff8 bhs 0x31501c <FT_Bitmap_Embolden+0x1d6>
 *   @0x314ffc add.w r0, r12, r8
 *   @0x315000 str r3, [sp, #0x14]
 *   @0x315008 ldr r2, [sp, #0x1c]
 *   @0x315014 ldr.w r12, [sp, #0x10]
 *   @0x315018 mov r2, r3
 *   @0x31501c ldr r0, [sp, #0x18]
 *   @0x315020 bl 0x2e7336 <ft_mem_free>
 *   @0x315024 ldr r3, [r4, #0x8]
 *   @0x31502c bge 0x315066 <FT_Bitmap_Embolden+0x220>
 *   @0x315030 b 0x315066 <FT_Bitmap_Embolden+0x220>
 *   @0x315038 mov r2, r0
 *   @0x31503c ldr r1, [r4]
 *   @0x315044 bhs 0x31501c <FT_Bitmap_Embolden+0x1d6>
 *   @0x315048 mov r0, r3
 *   @0x315054 mov r2, r12
 *   @0x31505c ldr.w r12, [sp, #0x10]
 *   @0x315060 mov r3, r0
 *   @0x315064 b 0x31503c <FT_Bitmap_Embolden+0x1f6>
 *   @0x315068 ldr r2, [r4, #0x8]
 *   @0x31506c ldr r1, [r4, #0xc]
 *   @0x315070 ble 0x31507c <FT_Bitmap_Embolden+0x236>
 *   @0x315078 movs r0, #0x12
 *   @0x31507c ldr r3, [r4]
 *   @0x315080 subs r3, #0x1
 *   @0x31508c cmp r12, r3
 *   @0x315090 subs r7, r2, #0x1
 *   @0x315094 adds r6, r7, #0x1
 *   @0x315098 ldrb r6, [r3, #-1]
 *   @0x31509c add.w r8, r1, r7
 *   @0x3150a0 str.w r8, [sp, #0x1c]
 *   @0x3150a4 str r6, [sp, #0x18]
 *   @0x3150a8 cmp r6, r5
 *   @0x3150ac ldrb.w r8, [r4, #0x12]
 *   @0x3150b0 cmp.w r8, #0x1
 *   @0x3150b4 bne 0x3150e6 <FT_Bitmap_Embolden+0x2a0>
 *   @0x3150d0 ldrb r10, [r3, #-2]
 *   @0x3150d4 rsb.w r9, r6, #0x8
 *   @0x3150d8 lsl.w r9, r10, r9
 *   @0x3150dc orr.w r9, r8, r9
 *   @0x3150e0 strb r9, [r3, #-1]
 *   @0x3150e4 b 0x315130 <FT_Bitmap_Embolden+0x2ea>
 *   @0x3150f0 ldrb r10, [r3, #-1]
 *   @0x3150f4 rsb.w r9, r6, #0x0
 *   @0x3150f8 ldrh.w r8, [r4, #0x10]
 *   @0x3150fc str.w r10, [sp, #0xc]
 *   @0x315100 ldr.w r10, [sp, #0x1c]
 *   @0x315104 ldrb.w r9, [r10, r9]
 *   @0x315108 ldr.w r10, [sp, #0xc]
 *   @0x31510c add r9, r10
 *   @0x315110 bgt 0x31511c <FT_Bitmap_Embolden+0x2d6>
 *   @0x31511c uxtb.w r9, r9
 *   @0x315120 strb r9, [r3, #-1]
 *   @0x315124 ldrh.w r8, [r4, #0x10]
 *   @0x315128 add.w r8, r8, #0xffffffff
 *   @0x31512c cmp r9, r8
 *   @0x315130 adds r6, #0x1
 *   @0x315134 subs r7, #0x1
 *   @0x315138 b 0x315094 <FT_Bitmap_Embolden+0x24e>
 *   @0x31513c cmp r6, r11
 *   @0x315140 bgt 0x315164 <FT_Bitmap_Embolden+0x31e>
 *   @0x315148 cmp r3, r2
 *   @0x31514c ldrb.w r9, [r1, r3]
 *   @0x315150 ldrb.w r8, [r7, r3]
 *   @0x315154 orr.w r8, r9, r8
 *   @0x315158 strb.w r8, [r7, r3]
 *   @0x31515c adds r3, #0x1
 *   @0x315160 adds r6, #0x1
 *   @0x315164 add r1, r3
 *   @0x31516c ldr r2, [r4, #0x4]
 *   @0x315170 str r3, [r4]
 *   @0x315174 str r5, [r4, #0x4]
 *   @0x315178 movs r0, #0x21
 *   @0x31517c mov r0, r11
 *   @0x315180 movs r0, #0x6
 *   @0x315184 movs r0, #0x0
 *   @0x315188 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ anon_31518e  0x31518e  size 6448  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x316abe 0x316ac2  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316abe push {r0, r2, r3, r4, r7, r8, r9, r10, r11, r12, sp, pc}
 *
 * ══ FT_Stream_OpenGzip  0x316ac0  size 408  本节 81 条（Thumb-2 半字段）｜入度 4
 * @func 0x316ac6 0x316c42  size 380  81 条
 * 部分覆盖: 本节 81/176 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316ac6 mov r5, r0
 *   @0x316aca cbnz r1, 0x316ad2 <FT_Stream_OpenGzip+0x12>
 *   @0x316ace str r3, [sp]
 *   @0x316ad2 mov r0, r1
 *   @0x316ade str r0, [sp]
 *   @0x316ae2 bne.w 0x316c3c <FT_Stream_OpenGzip+0x17c>
 *   @0x316ae6 movs r2, #0x28
 *   @0x316aea blx 0xb65b0 <memset@plt>
 *   @0x316aee mov r2, sp
 *   @0x316af6 movw r1, #0x2054
 *   @0x316afa bl 0x2e7100 <ft_mem_qalloc>
 *   @0x316afe ldr r2, [sp]
 *   @0x316b02 cmp r2, #0x0
 *   @0x316b06 str r5, [r0, #0x4]
 *   @0x316b0a ldr r3, [r5, #0x1c]
 *   @0x316b0e add.w r3, r0, #0x2040
 *   @0x316b12 add.w r1, r3, #0x8
 *   @0x316b16 mov r0, r6
 *   @0x316b1a str r1, [r3, #0xc]
 *   @0x316b1e bl 0x3155b0 <FT_Bitmap_Embolden+0x76a>
 *   @0x316b22 mov r7, r0
 *   @0x316b26 mov r0, r6
 *   @0x316b2e mvn r1, #0xe
 *   @0x316b32 add r3, pc
 *   @0x316b36 ldr r3, [pc, #0x110]
 *   @0x316b3a str r3, [r4, #0x30]
 *   @0x316b3e mov r0, r4
 *   @0x316b42 str r7, [r4, #0x10]
 *   @0x316b46 add.w r3, r4, #0x1040
 *   @0x316b4a adds r3, #0x8
 *   @0x316b56 ldr r7, [r4, #0xc]
 *   @0x316b5a ite eq
 *   @0x316b5e movne r7, #0x0
 *   @0x316b62 movs r7, #0x3
 *   @0x316b66 cbz r7, 0x316b72 <FT_Stream_OpenGzip+0xb2>
 *   @0x316b6a mov r1, r4
 *   @0x316b72 str r4, [r5, #0xc]
 *   @0x316b76 mov r0, r6
 *   @0x316b7e bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x316b82 cbnz r0, 0x316ba0 <FT_Stream_OpenGzip+0xe0>
 *   @0x316b86 mov r0, r6
 *   @0x316b8e mov r1, r10
 *   @0x316b92 ite eq
 *   @0x316b96 movne r7, #0x0
 *   @0x316b9a bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x316b9e b 0x316ba2 <FT_Stream_OpenGzip+0xe2>
 *   @0x316ba2 subs r2, r7, #0x1
 *   @0x316baa bhi 0x316c1e <FT_Stream_OpenGzip+0x15e>
 *   @0x316bae mov r1, r7
 *   @0x316bb2 bl 0x2e7126 <ft_mem_alloc>
 *   @0x316bb6 ldr r6, [sp]
 *   @0x316bba cmp r6, #0x0
 *   @0x316bbe mov r0, r4
 *   @0x316bc2 mov r2, r9
 *   @0x316bc6 bl 0x3169fa <FT_Bitmap_Embolden+0x1bb4>
 *   @0x316bca cmp r0, r7
 *   @0x316bce add.w r0, r4, #0xc
 *   @0x316bd2 bl 0x315770 <FT_Bitmap_Embolden+0x92a>
 *   @0x316bd6 str r6, [r4, #0x2c]
 *   @0x316bda mov r0, r8
 *   @0x316bde mov r1, r4
 *   @0x316be2 str r6, [r4, #0x18]
 *   @0x316be6 str r6, [r4, #0x1c]
 *   @0x316bea str r6, [r4]
 *   @0x316bee bl 0x2e7336 <ft_mem_free>
 *   @0x316bf2 ldr r3, [pc, #0x58]
 *   @0x316bf6 str r7, [r5, #0x4]
 *   @0x316bfa str r6, [r5, #0x8]
 *   @0x316c02 b 0x316c3a <FT_Stream_OpenGzip+0x17a>
 *   @0x316c06 mov r0, r4
 *   @0x316c0a mov r3, r6
 *   @0x316c12 mov r1, r9
 *   @0x316c1a str r3, [sp]
 *   @0x316c1e cbz r7, 0x316c24 <FT_Stream_OpenGzip+0x164>
 *   @0x316c22 b 0x316c2a <FT_Stream_OpenGzip+0x16a>
 *   @0x316c2a movs r3, #0x0
 *   @0x316c2e str r3, [r5]
 *   @0x316c32 add r3, pc
 *   @0x316c36 ldr r3, [pc, #0x1c]
 *   @0x316c3a str r3, [r5, #0x18]
 *   @0x316c3e add sp, #0x8
 *
 * ══ FT_Gzip_Uncompress  0x316c58  size 132  本节 30 条（Thumb-2 半字段）｜入度 3
 * @func 0x316c5a 0x316cd6  size 124  30 条
 * 部分覆盖: 本节 30/61 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316c5a mov r6, r2
 *   @0x316c5e cbnz r0, 0x316c64 <FT_Gzip_Uncompress+0xc>
 *   @0x316c62 b 0x316cce <FT_Gzip_Uncompress+0x76>
 *   @0x316c66 beq 0x316c60 <FT_Gzip_Uncompress+0x8>
 *   @0x316c6a beq 0x316c60 <FT_Gzip_Uncompress+0x8>
 *   @0x316c6e ldr r3, [sp, #0x48]
 *   @0x316c72 movs r1, #0xf
 *   @0x316c76 mov r0, sp
 *   @0x316c7a ldr r3, [r2]
 *   @0x316c7e ldr r3, [pc, #0x54]
 *   @0x316c82 str r3, [sp, #0x20]
 *   @0x316c86 add r3, pc
 *   @0x316c8a bl 0x31582c <FT_Bitmap_Embolden+0x9e6>
 *   @0x316c8e cmp r0, #0x0
 *   @0x316c92 mov r0, sp
 *   @0x316c96 bl 0x31593c <FT_Bitmap_Embolden+0xaf6>
 *   @0x316c9a cmp r0, #0x1
 *   @0x316c9e beq 0x316cac <FT_Gzip_Uncompress+0x54>
 *   @0x316ca2 bl 0x315770 <FT_Bitmap_Embolden+0x92a>
 *   @0x316ca6 cbnz r4, 0x316cb8 <FT_Gzip_Uncompress+0x60>
 *   @0x316caa b 0x316cce <FT_Gzip_Uncompress+0x76>
 *   @0x316cae mov r0, sp
 *   @0x316cb2 bl 0x315770 <FT_Bitmap_Embolden+0x92a>
 *   @0x316cb6 mov r4, r0
 *   @0x316cba beq 0x316ccc <FT_Gzip_Uncompress+0x74>
 *   @0x316cbe beq 0x316ca8 <FT_Gzip_Uncompress+0x50>
 *   @0x316cc6 moveq r0, #0x8
 *   @0x316cca b 0x316cce <FT_Gzip_Uncompress+0x76>
 *   @0x316cce add sp, #0x38
 *   @0x316cd2 nop
 *
 * ══ anon_316cdc  0x316cdc  size 356  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x316e40 0x316e50  size 16  4 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316e40 movwhs pc, #0xb04
 *
 * ══ ft_lzwstate_reset  0x316e42  size 24  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x316e44 0x316e68  size 36  9 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316e44 movs r2, #0x9
 *   @0x316e48 str r3, [r0, #0x18]
 *   @0x316e4c strb.w r3, [r0, #0x20]
 *   @0x316e50 str r3, [r0, #0x24]
 *   @0x316e54 str r2, [r0, #0x34]
 *   @0x316e58 bx lr
 *
 * ══ ft_lzwstate_init  0x316e5a  size 52  本节 11 条（Thumb-2 半字段）｜入度 0
 * @func 0x316e5c 0x316e92  size 54  12 条
 * 部分覆盖: 本节 12/25 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316e5c movs r2, #0xac
 *   @0x316e60 mov r5, r1
 *   @0x316e64 blx 0xb65b0 <memset@plt>
 *   @0x316e68 str.w r5, [r4, #0xa4]
 *   @0x316e6c ldr r3, [r5, #0x1c]
 *   @0x316e70 str.w r3, [r4, #0xa8]
 *   @0x316e74 movs r3, #0x0
 *   @0x316e78 str r3, [r4, #0x50]
 *   @0x316e7c add.w r3, r4, #0x64
 *   @0x316e80 str r3, [r4, #0x58]
 *   @0x316e84 str r3, [r4, #0x60]
 *
 * ══ anon_316e8e  0x316e8e  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x316e8e 0x316e92  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316e8e .word 0xe92d0000
 *
 * ══ FT_Stream_OpenLZW  0x316e90  size 196  本节 42 条（Thumb-2 半字段）｜入度 3
 * @func 0x316e96 0x316f5a  size 196  43 条
 * 部分覆盖: 本节 43/92 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 42/90 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316e96 mov r4, r0
 *   @0x316e9a cbnz r1, 0x316ea2 <FT_Stream_OpenLZW+0x12>
 *   @0x316e9e str r3, [sp, #0x4]
 *   @0x316ea2 ldr.w r8, [r1, #0x1c]
 *   @0x316ea6 mov r0, r1
 *   @0x316eaa bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x316eae mov r7, r0
 *   @0x316eb2 mov r0, r5
 *   @0x316eba str r7, [sp, #0x4]
 *   @0x316ebe bne 0x316f42 <FT_Stream_OpenLZW+0xb2>
 *   @0x316ec2 movs r2, #0x28
 *   @0x316ec6 blx 0xb65b0 <memset@plt>
 *   @0x316eca str.w r8, [r4, #0x1c]
 *   @0x316ece mov r0, r8
 *   @0x316ed6 bl 0x2e7126 <ft_mem_alloc>
 *   @0x316eda ldr r3, [sp, #0x4]
 *   @0x316ede cbnz r3, 0x316f2a <FT_Stream_OpenLZW+0x9a>
 *   @0x316ee2 add.w r1, r0, #0x10c0
 *   @0x316ee6 str r5, [r0]
 *   @0x316eea str r3, [r0, #0x8]
 *   @0x316ef6 str r2, [r1]
 *   @0x316efa str r7, [r3, #0x18]
 *   @0x316efe bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x316f02 mov r7, r0
 *   @0x316f06 mov r0, r5
 *   @0x316f0e cbnz r0, 0x316f1a <FT_Stream_OpenLZW+0x8a>
 *   @0x316f16 bl 0x316e5a <ft_lzwstate_init>
 *   @0x316f1a str r7, [sp, #0x4]
 *   @0x316f1e mov r0, r8
 *   @0x316f22 bl 0x2e7336 <ft_mem_free>
 *   @0x316f26 b 0x316f42 <FT_Stream_OpenLZW+0xb2>
 *   @0x316f2a mvn r3, #0x80000000
 *   @0x316f2e str r3, [r4, #0x4]
 *   @0x316f32 str r3, [r4, #0x8]
 *   @0x316f36 ldr r3, [pc, #0x14]
 *   @0x316f3a str r3, [r4, #0x14]
 *   @0x316f3e add r3, pc
 *   @0x316f42 ldr r0, [sp, #0x4]
 *   @0x316f46 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x316f4a nop
 *   @0x316f4e movs r0, r0
 *   @0x316f52 movs r0, r0
 *
 * ══ ft_lzwstate_done  0x316f54  size 58  本节 10 条（Thumb-2 半字段）｜入度 0
 * @func 0x316f56 0x316f8e  size 56  10 条
 * 部分覆盖: 本节 10/24 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316f56 mov r4, r0
 *   @0x316f62 add.w r3, r4, #0x64
 *   @0x316f66 cmp r1, r3
 *   @0x316f6a mov r0, r5
 *   @0x316f72 str r3, [r4, #0x58]
 *   @0x316f76 ldr r1, [r4, #0x4c]
 *   @0x316f7e mov r0, r4
 *   @0x316f82 str r1, [r4, #0x50]
 *   @0x316f86 pop.w {r3, r4, r5, lr}
 *   @0x316f8a b.w 0x31bacc <__udivdi3+0x434>
 *
 * ══ anon_316f90  0x316f90  size 32  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x316fb0 0x316fb4  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316fb0 ldcllt p0, c6, [r8, #980]!
 *
 * ══ ft_lzwstate_io  0x316fb4  size 602  本节 123 条（Thumb-2 半字段）｜入度 35
 * @func 0x316fba 0x31720e  size 596  123 条
 * 部分覆盖: 本节 123/272 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x316fba sub sp, #0x1c
 *   @0x316fbe ldr r6, [r0, #0x44]
 *   @0x316fc2 ldr r7, [r0, #0x40]
 *   @0x316fca beq.w 0x3171f0 <ft_lzwstate_io+0x23c>
 *   @0x316fce ldr r3, [r0]
 *   @0x316fd2 beq.w 0x317162 <ft_lzwstate_io+0x1ae>
 *   @0x316fd6 blo 0x316fe2 <ft_lzwstate_io+0x2e>
 *   @0x316fda bne.w 0x3171f4 <ft_lzwstate_io+0x240>
 *   @0x316fde movs r5, #0x0
 *   @0x316fe2 ldr.w r0, [r0, #0xa4]
 *   @0x316fe6 movs r1, #0x2
 *   @0x316fee bne 0x31706a <ft_lzwstate_io+0xb6>
 *   @0x316ff6 movs r2, #0x1
 *   @0x316ffe bne 0x31706a <ft_lzwstate_io+0xb6>
 *   @0x31700e lsl.w r0, r0, r3
 *   @0x317012 uxtb r2, r2
 *   @0x31701a str r2, [r4, #0x2c]
 *   @0x31701e bhi 0x31706a <ft_lzwstate_io+0xb6>
 *   @0x317022 mov.w r1, #0x9
 *   @0x317026 str r1, [r4, #0x34]
 *   @0x31702a movne r2, #0x1
 *   @0x31702e it ls
 *   @0x317032 str r2, [r4, #0x38]
 *   @0x317036 movhi.w r0, #0x100
 *   @0x31703a str r0, [r4, #0x3c]
 *   @0x31703e bl 0x316cdc <FT_Gzip_Uncompress+0x84>
 *   @0x317042 cmp r0, #0xff
 *   @0x317046 cmp.w r11, #0x0
 *   @0x31704a beq 0x317050 <ft_lzwstate_io+0x9c>
 *   @0x31705a str r5, [r4]
 *   @0x31705e mov r6, r0
 *   @0x317066 mov.w r8, #0x0
 *   @0x31706a movs r5, #0x0
 *   @0x31706e mov r7, r0
 *   @0x317072 mov.w r8, #0x0
 *   @0x317076 b 0x3171fe <ft_lzwstate_io+0x24a>
 *   @0x31707a cmp r3, #0x0
 *   @0x31707e movs r6, #0x0
 *   @0x317082 mov r7, r6
 *   @0x317086 strb.w r3, [r4, #0x20]
 *   @0x31708a mov r0, r4
 *   @0x31708e bl 0x316cdc <FT_Gzip_Uncompress+0x84>
 *   @0x317092 ldr r2, [sp, #0xc]
 *   @0x317096 blt.w 0x3171f8 <ft_lzwstate_io+0x244>
 *   @0x31709a cmp.w r0, #0x100
 *   @0x31709e mov r8, r0
 *   @0x3170a2 cmp r0, #0xff
 *   @0x3170a6 movls r6, r0
 *   @0x3170aa ldr r2, [r4, #0x5c]
 *   @0x3170ae cmp r2, r3
 *   @0x3170b6 ldr r2, [r4, #0x58]
 *   @0x3170ba str r1, [r4, #0x5c]
 *   @0x3170be movs r3, #0x2
 *   @0x3170c2 ldr r3, [r4, #0x5c]
 *   @0x3170c6 subs r3, #0x1
 *   @0x3170ca cmp.w r11, #0x0
 *   @0x3170ce beq 0x3170d8 <ft_lzwstate_io+0x124>
 *   @0x3170d2 ldrb r3, [r2, r3]
 *   @0x3170da cmp r5, r10
 *   @0x3170de b 0x3171fe <ft_lzwstate_io+0x24a>
 *   @0x3170e2 ldr r2, [r4, #0x30]
 *   @0x3170e6 bhs 0x317158 <ft_lzwstate_io+0x1a4>
 *   @0x3170ee bhs 0x317106 <ft_lzwstate_io+0x152>
 *   @0x3170f2 ldr r3, [r4, #0x4c]
 *   @0x3170fa ldr r2, [r4, #0x50]
 *   @0x3170fe ldr r3, [r4, #0x38]
 *   @0x317102 str r3, [r4, #0x38]
 *   @0x317106 ldr.w r0, [r4, #0xa8]
 *   @0x31710a cmp.w r9, #0x0
 *   @0x31710e beq 0x317116 <ft_lzwstate_io+0x162>
 *   @0x317116 mov.w r12, #0x200
 *   @0x31711a ldr r3, [r4, #0x4c]
 *   @0x31711e mov r2, r9
 *   @0x317126 add r3, sp, #0x14
 *   @0x31712a mov r3, r12
 *   @0x317132 ldr.w r12, [sp, #0xc]
 *   @0x317136 mov r1, r0
 *   @0x31713a cmp r3, #0x0
 *   @0x31713e add.w r0, r0, r12, lsl #1
 *   @0x317142 add.w r1, r1, r9, lsl #1
 *   @0x317146 str r0, [r4, #0x50]
 *   @0x31714a blx 0xb6694 <memmove@plt>
 *   @0x31714e ldr.w r12, [sp, #0xc]
 *   @0x317152 str.w r12, [r4, #0x54]
 *   @0x317156 b 0x3170f0 <ft_lzwstate_io+0x13c>
 *   @0x31715a mov r9, r8
 *   @0x31715e mov r7, r8
 *   @0x317162 mov r9, r8
 *   @0x317166 movs r2, #0x0
 *   @0x31716a ldr r3, [r4, #0x38]
 *   @0x317172 blo 0x317198 <ft_lzwstate_io+0x1e4>
 *   @0x317176 ldr r2, [r4, #0x5c]
 *   @0x31717a cmp r2, r3
 *   @0x31717e ldr r3, [r4, #0x5c]
 *   @0x317182 ldr r2, [r4, #0x58]
 *   @0x317186 str r1, [r4, #0x5c]
 *   @0x31718a b 0x3171ca <ft_lzwstate_io+0x216>
 *   @0x31718e bl 0x316dbc <FT_Gzip_Uncompress+0x164>
 *   @0x317192 cmp r0, #0x0
 *   @0x317196 b 0x3171fa <ft_lzwstate_io+0x246>
 *   @0x31719a b 0x3171ca <ft_lzwstate_io+0x216>
 *   @0x31719e cbz r3, 0x3171fa <ft_lzwstate_io+0x246>
 *   @0x3171a2 ldr r3, [r4, #0x60]
 *   @0x3171a6 bhs 0x3171d2 <ft_lzwstate_io+0x21e>
 *   @0x3171aa ldr r2, [r4, #0x58]
 *   @0x3171ae str r1, [r4, #0x5c]
 *   @0x3171b2 add r1, r9
 *   @0x3171c2 strb r1, [r2, r3]
 *   @0x3171c6 ldrh.w r9, [r3, r9, lsl #1]
 *   @0x3171ca cmp.w r9, #0xff
 *   @0x3171ce bhi 0x31719c <ft_lzwstate_io+0x1e8>
 *   @0x3171d2 mov r0, r4
 *   @0x3171da bge 0x3171a8 <ft_lzwstate_io+0x1f4>
 *   @0x3171de mov r6, r9
 *   @0x3171e2 mov r0, r4
 *   @0x3171ea bge.w 0x3170b4 <ft_lzwstate_io+0x100>
 *   @0x3171ee b 0x3171fa <ft_lzwstate_io+0x246>
 *   @0x3171f2 b 0x3171fe <ft_lzwstate_io+0x24a>
 *   @0x3171f6 b 0x3171fe <ft_lzwstate_io+0x24a>
 *   @0x3171fa movs r3, #0x3
 *   @0x3171fe mov r0, r5
 *   @0x317202 str r6, [r4, #0x44]
 *   @0x31720a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ anon_317210  0x317210  size 1412  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x317794 0x317798  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x317794 andhi pc, r0, pc, lsr #7
 *
 * ══ anon_317a44  0x317a44  size 352  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x317ba4 0x317ba8  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x317ba4 .word 0xffc8f7ff
 *
 * ══ anon_317e5c  0x317e5c  size 288  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x317f7c 0x317f80  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x317f7c svclt #0xbdf0
 *
 * ══ __gxx_personality_v0  0x317f80  size 360  本节 74 条（Thumb-2 半字段）｜入度 6
 * @func 0x317f86 0x3180ea  size 356  74 条
 * 部分覆盖: 本节 74/163 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x317f86 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x317f8a mov r4, r1
 *   @0x317f8e mov r6, r2
 *   @0x317f96 bhs 0x318016 <__gxx_personality_v0+0x96>
 *   @0x317f9a movs r5, #0x1
 *   @0x317f9e mov r0, r6
 *   @0x317fa2 str r4, [sp, #0xc]
 *   @0x317fa6 str r7, [sp]
 *   @0x317fae beq 0x318040 <__gxx_personality_v0+0xc0>
 *   @0x317fb2 ldrd r2, r3, [r3]
 *   @0x317fb6 eor.w r2, r2, r8
 *   @0x317fba eor.w r3, r3, r9
 *   @0x317fbe orrs.w r1, r2, r3
 *   @0x317fc2 ite ne
 *   @0x317fc6 moveq r7, #0x1
 *   @0x317fca bmi 0x318022 <__gxx_personality_v0+0xa2>
 *   @0x317fce bpl 0x318040 <__gxx_personality_v0+0xc0>
 *   @0x317fd2 bpl 0x318094 <__gxx_personality_v0+0x114>
 *   @0x317fd6 beq 0x3180bc <__gxx_personality_v0+0x13c>
 *   @0x317fea mov r0, r4
 *   @0x317fee mov r1, r8
 *   @0x317ff2 str r3, [sp, #0x10]
 *   @0x317ff6 str r5, [sp, #0x18]
 *   @0x317ffa bl 0x317ef4 <ft_lzwstate_io+0xf40>
 *   @0x317ffe mov r0, r4
 *   @0x318002 mov r2, r8
 *   @0x31800a mov r1, r6
 *   @0x31800e bl 0x317f10 <ft_lzwstate_io+0xf5c>
 *   @0x318012 movs r0, #0x7
 *   @0x318016 cmp r0, #0x2
 *   @0x31801a movs r0, #0x9
 *   @0x31801e pop.w {r4, r5, r6, r7, r8, r9, pc}
 *   @0x318022 mov r1, r5
 *   @0x318026 mov r3, r4
 *   @0x31802a str r6, [sp]
 *   @0x318032 cmp r5, #0x6
 *   @0x318036 mov r0, r4
 *   @0x31803a bl 0x317eb8 <ft_lzwstate_io+0xf04>
 *   @0x31803e b 0x31801c <__gxx_personality_v0+0x9c>
 *   @0x318042 b 0x31801c <__gxx_personality_v0+0x9c>
 *   @0x318046 mov r0, r2
 *   @0x31804a ldr r5, [r4, #0x20]
 *   @0x31804e add r7, sp, #0xc
 *   @0x318052 blx 0x319be4 <_Unwind_VRS_Get>
 *   @0x318056 ldr r3, [sp, #0xc]
 *   @0x31805a ite eq
 *   @0x31805e movne r5, #0x2
 *   @0x318062 mov r0, r5
 *   @0x318066 beq 0x31801c <__gxx_personality_v0+0x9c>
 *   @0x31806a mov r0, r4
 *   @0x31806e add r2, sp, #0x10
 *   @0x318076 str r3, [r4, #-16]
 *   @0x31807a ldr r3, [sp, #0x1c]
 *   @0x318082 str r3, [r4, #-8]
 *   @0x318086 ldr r3, [sp, #0x24]
 *   @0x318092 b 0x31801c <__gxx_personality_v0+0x9c>
 *   @0x318096 mov r1, r5
 *   @0x31809a add r0, sp, #0x10
 *   @0x31809e bl 0x317ba8 <ft_lzwstate_io+0xbf4>
 *   @0x3180a2 ldr r3, [sp, #0x28]
 *   @0x3180a6 bne 0x318036 <__gxx_personality_v0+0xb6>
 *   @0x3180aa add r2, sp, #0x10
 *   @0x3180ae bl 0x317e5c <ft_lzwstate_io+0xea8>
 *   @0x3180b2 mov r0, r4
 *   @0x3180ba b 0x31801c <__gxx_personality_v0+0x9c>
 *   @0x3180c2 mov r1, r5
 *   @0x3180c6 mov r0, r8
 *   @0x3180ca bl 0x317ba8 <ft_lzwstate_io+0xbf4>
 *   @0x3180ce ldr r3, [sp, #0x28]
 *   @0x3180d2 beq 0x317ffe <__gxx_personality_v0+0x7e>
 *   @0x3180d6 bl 0x317b38 <ft_lzwstate_io+0xb84>
 *   @0x3180da nop
 *   @0x3180e2 orrs r3, r5
 *   @0x3180e6 bx r9
 *
 * ══ anon_3180e8  0x3180e8  size 1224  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x3185b0 0x3185b4  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x3185b0 bl 0x1dd5c30 <b2_toiTime+0x167c78c>
 *
 * ══ __cxa_type_match  0x3185b4  size 116  本节 24 条（Thumb-2 半字段）｜入度 1
 * @func 0x3185b6 0x31862e  size 120  25 条
 * 部分覆盖: 本节 25/55 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 24/53 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x3185b6 sub sp, #0xc
 *   @0x3185c2 mov r6, r1
 *   @0x3185c6 str r2, [sp, #0x4]
 *   @0x3185ca beq 0x318616 <__cxa_type_match+0x62>
 *   @0x3185ce mov r0, r4
 *   @0x3185d2 movs r3, #0x0
 *   @0x3185d6 ldr r1, [r1]
 *   @0x3185da ldr r2, [r2]
 *   @0x3185e2 ldr r3, [r5, #0x58]
 *   @0x3185e6 str r3, [sp, #0x4]
 *   @0x3185ee movlo r3, #0x0
 *   @0x3185f2 it eq
 *   @0x3185fa movs r5, #0x0
 *   @0x3185fe add sp, #0xc
 *   @0x318602 ldr r3, [r6]
 *   @0x318606 mov r1, r4
 *   @0x31860a ldr r3, [r3, #0x8]
 *   @0x31860e cbz r0, 0x31861a <__cxa_type_match+0x66>
 *   @0x318612 str r3, [r7]
 *   @0x318616 movs r5, #0x1
 *   @0x31861a mov r5, r0
 *   @0x31861e nop
 *   @0x318622 movs r5, r1
 *   @0x318626 movs r5, r1
 *
 * ══ __cxa_begin_cleanup  0x318628  size 80  本节 14 条（Thumb-2 半字段）｜入度 0
 * @func 0x31862a 0x31867a  size 80  14 条
 * 部分覆盖: 本节 14/34 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x31862a mov r6, r0
 *   @0x31863a ldrd r2, r3, [r3]
 *   @0x31863e eors r2, r4
 *   @0x318642 orrs.w r4, r2, r3
 *   @0x318646 it ne
 *   @0x31864a beq 0x318650 <__cxa_begin_cleanup+0x28>
 *   @0x31864e pop {r4, r5, r6, pc}
 *   @0x318656 str r3, [r6, #-24]
 *   @0x31865a cmp r3, #0x1
 *   @0x31865e ldreq r3, [r0, #0x8]
 *   @0x318666 movs r0, #0x1
 *   @0x31866a nop
 *   @0x318672 orrs r3, r5
 *   @0x318676 bx r9
 *
 * ══ anon_318678  0x318678  size 76  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x3186c4 0x3186c8  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x3186c4 strbmi r5, [lr, -r3, asr #10]
 *
 * ══ __cxa_call_unexpected  0x3186c8  size 260  本节 41 条（Thumb-2 半字段）｜入度 2
 * @func 0x3186ce 0x3187c6  size 248  41 条
 * 部分覆盖: 本节 41/103 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x3186ce adr r3, #232 <__cxa_call_unexpected+0x44>
 *   @0x3186d6 ldrd r0, r1, [r0]
 *   @0x3186da ldr r6, [pc, #0xe4]
 *   @0x3186de eors r3, r1
 *   @0x3186e6 mov r0, r4
 *   @0x3186ea bl 0x317720 <ft_lzwstate_io+0x76c>
 *   @0x3186ee bl 0x3182c0 <__gxx_personality_v0+0x340>
 *   @0x3186f2 ldr.w r8, [r4, #0x28]
 *   @0x3186f6 ldr r5, [r4, #0x30]
 *   @0x3186fa bl 0x317720 <ft_lzwstate_io+0x76c>
 *   @0x3186fe ldr r3, [r4, #-44]
 *   @0x318702 blx r3
 *   @0x31871e cmp r9, r8
 *   @0x318722 mov r0, r7
 *   @0x31872a bl 0x3174e0 <ft_lzwstate_io+0x52c>
 *   @0x31872e mov r1, r5
 *   @0x318732 ldr r3, [r0]
 *   @0x31873a str r3, [sp]
 *   @0x31873e bl 0x3185b4 <__cxa_type_match>
 *   @0x318742 cbnz r0, 0x31876c <__cxa_call_unexpected+0xa4>
 *   @0x318746 ldr r3, [r5]
 *   @0x31874a mov r0, r5
 *   @0x31874e add r2, sp, #0x4
 *   @0x318752 blx r3
 *   @0x31875a it ne
 *   @0x318762 b 0x31871e <__cxa_call_unexpected+0x56>
 *   @0x31877e bl 0x317798 <ft_lzwstate_io+0x7e4>
 *   @0x318782 bl 0x317798 <ft_lzwstate_io+0x7e4>
 *   @0x318786 movs r0, #0x4
 *   @0x31878e bl 0x318a48 <__cxa_call_unexpected+0x380>
 *   @0x318792 ldr r3, [pc, #0x30]
 *   @0x318796 ldr r1, [r6, r3]
 *   @0x31879a ldr r2, [r6, r3]
 *   @0x3187a6 blx 0xb6c88 <abort@plt>
 *   @0x3187aa bl 0x317720 <ft_lzwstate_io+0x76c>
 *   @0x3187ae blx 0xb6c88 <abort@plt>
 *   @0x3187b2 bl 0x317798 <ft_lzwstate_io+0x7e4>
 *   @0x3187b6 b 0x318770 <__cxa_call_unexpected+0xa8>
 *   @0x3187ba orrs r3, r5
 *   @0x3187be bx r9
 *   @0x3187c2 movs r5, r1
 *
 * ══ anon_3187cc  0x3187cc  size 1144  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x318c44 0x318c48  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x318c44 strdeq r8, r9, [sp], -r12
 *
 * ══ anon_318e0c  0x318e0c  size 4  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x318e10 0x318e14  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x318e10 b 0x318e18 <__aeabi_dadd>
 *
 * ══ anon_319630  0x319630  size 1072  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x319a60 0x319a64  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x319a60 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ anon_319c40  0x319c40  size 36  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x319c64 0x319c68  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x319c64 ldr pc, [sp], #4
 *
 * ══ anon_319cc4  0x319cc4  size 40  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x319cec 0x319cf0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x319cec ldr pc, [sp], #4
 *
 * ══ anon_319db4  0x319db4  size 1004  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x31a1a0 0x31a1a4  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x31a1a0 andeq r7, sp, r0, asr #21
 *
 * ══ anon_31a51c  0x31a51c  size 220  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x31a5f8 0x31a5fc  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x31a5f8 bx lr
 *
 * ══ anon_31a6b0  0x31a6b0  size 136  本节 1 条（Thumb-2 半字段）｜入度 2
 * @func 0x31a738 0x31a73c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x31a738 b 0x31a710 <___Unwind_Backtrace+0x84>
 *
 * ══ anon_31ba7c  0x31ba7c  size 252  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x31bb78 0x31bb7c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x31bb78 .word 0xffd9aa7c
 */
