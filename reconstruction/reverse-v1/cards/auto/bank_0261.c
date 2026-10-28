/* libyoyo.so 覆盖卡组 0261
 * 函数 0x2b1818..0x2b32c0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2b1818 · png_write_gAMA_fixed · size=52 · insn=26 */
/* @0x2b1818 ldr r3, [pc, #0x2c] */
/* @0x2b181a push {r4, r5, lr} */
/* @0x2b181c add r3, pc */
/* @0x2b181e mov r5, r0 */
/* @0x2b1820 sub sp, #0x14 */
/* @0x2b1822 ldr r0, [r3, #28]! */
/* @0x2b1824 .word 0xac010f1c */
/* @0x2b1826 add r4, sp, #0x4 */
/* @0x2b1828 ldrb r3, [r3, #0x4] */
/* @0x2b182a str r0, [sp, #0x8] */
/* @0x2b182c mov r0, r4 */
/* @0x2b182e strb.w r3, [sp, #0xc] */
/* @0x2b1830 .word 0xf7ff300c */
/* @0x2b1832 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1834 qsub16mi pc, r8, r7 */
/* @0x2b1836 mov r0, r5 */
/* @0x2b1838 add r1, sp, #0x8 */
/* @0x2b183a mov r2, r4 */
/* @0x2b183c movs r3, #0x4 */
/* @0x2b183e bl 0x2b12bc <png_write_chunk> */
/* @0x2b1840 andlt pc, r5, sp, lsr sp */
/* @0x2b1842 add sp, #0x14 */
/* @0x2b1844 pop {r4, r5, pc} */
/* @0x2b1846 nop */
/* @0x2b1848 b 0x2b12d4 <png_write_chunk+0x18> */
/* @0x2b184a movs r5, r1 */

/* ── FUNC 0x2b184c · png_write_sRGB · size=68 · insn=33 */
/* @0x2b184c ldr r3, [pc, #0x38] */
/* @0x2b184e cmp r1, #0x3 */
/* @0x2b1850 push {r4, r5, lr} */
/* @0x2b1852 add r3, pc */
/* @0x2b1854 mov r4, r0 */
/* @0x2b1856 sub sp, #0x14 */
/* @0x2b1858 ldr r0, [r3, #33]! */
/* @0x2b185c mov r5, r1 */
/* @0x2b185e ldrb r3, [r3, #0x4] */
/* @0x2b1860 str r0, [sp, #0x8] */
/* @0x2b1862 strb.w r3, [sp, #0xc] */
/* @0x2b1864 stcle p0, c3, [r4, #-48] */
/* @0x2b1866 ble 0x2b1872 <png_write_sRGB+0x26> */
/* @0x2b1868 ldr r1, [pc, #0x20] */
/* @0x2b186a mov r0, r4 */
/* @0x2b186c add r1, pc */
/* @0x2b186e bl 0x2a6474 <png_warning> */
/* @0x2b1870 strtmi pc, [r0], -r1, lsl #28 */
/* @0x2b1872 mov r0, r4 */
/* @0x2b1874 add r1, sp, #0x8 */
/* @0x2b1876 add r2, sp, #0x4 */
/* @0x2b1878 movs r3, #0x1 */
/* @0x2b187a strb.w r5, [sp, #0x4] */
/* @0x2b187c .word 0xf7ff5004 */
/* @0x2b187e bl 0x2b12bc <png_write_chunk> */
/* @0x2b1880 andlt pc, r5, sp, lsl sp */
/* @0x2b1882 add sp, #0x14 */
/* @0x2b1884 pop {r4, r5, pc} */
/* @0x2b1886 nop */
/* @0x2b1888 b 0x2b12a8 <png_write_chunk_end+0x12> */
/* @0x2b188a movs r5, r1 */
/* @0x2b188c ldm r3, {r0, r1, r3, r5} */
/* @0x2b188e movs r5, r1 */

/* ── FUNC 0x2b1890 · png_write_iCCP · size=252 · insn=114 */
/* @0x2b1890 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2b1894 mov r6, r3 */
/* @0x2b1896 ldr r3, [pc, #0xe0] */
/* @0x2b1898 mov r4, r0 */
/* @0x2b189a sub sp, #0x28 */
/* @0x2b189c mov r8, r2 */
/* @0x2b189e add r3, pc */
/* @0x2b18a0 add r2, sp, #0x8 */
/* @0x2b18a2 ldr r5, [sp, #0x40] */
/* @0x2b18a4 ldr r0, [r3, #38]! */
/* @0x2b18a8 ldrb r3, [r3, #0x4] */
/* @0x2b18aa str r0, [sp, #0xc] */
/* @0x2b18ac mov r0, r4 */
/* @0x2b18ae strb.w r3, [sp, #0x10] */
/* @0x2b18b0 movwhs r3, #0x10 */
/* @0x2b18b2 movs r3, #0x0 */
/* @0x2b18b4 str r3, [sp, #0x1c] */
/* @0x2b18b6 str r3, [sp, #0x20] */
/* @0x2b18b8 str r3, [sp, #0x24] */
/* @0x2b18ba str r3, [sp, #0x14] */
/* @0x2b18bc str r3, [sp, #0x18] */
/* @0x2b18be bl 0x2af5b0 <png_check_keyword> */
/* @0x2b18c0 .word 0x4607fe77 */
/* @0x2b18c2 mov r7, r0 */
/* @0x2b18c4 cmp r0, #0x0 */
/* @0x2b18c6 beq 0x2b1970 <png_write_iCCP+0xe0> */
/* @0x2b18c8 cmp.w r8, #0x0 */
/* @0x2b18cc beq 0x2b18d8 <png_write_iCCP+0x48> */
/* @0x2b18ce ldr r1, [pc, #0xac] */
/* @0x2b18d0 mov r0, r4 */
/* @0x2b18d2 add r1, pc */
/* @0x2b18d4 bl 0x2a6474 <png_warning> */
/* @0x2b18d8 cbz r6, 0x2b1902 <png_write_iCCP+0x72> */
/* @0x2b18da cmp r5, #0x3 */
/* @0x2b18dc ble 0x2b1904 <png_write_iCCP+0x74> */
/* @0x2b18de ldrb.w r8, [r6, #0x1] */
/* @0x2b18e0 ldmdavc r3!, {r0, pc} */
/* @0x2b18e2 ldrb r3, [r6] */
/* @0x2b18e4 lsl.w r8, r8, #0x10 */
/* @0x2b18e8 orr.w r8, r8, r3, lsl #24 */
/* @0x2b18ec ldrb r3, [r6, #0x3] */
/* @0x2b18ee orr.w r8, r8, r3 */
/* @0x2b18f0 ldmvc r3!, {r0, r1, r11} */
/* @0x2b18f2 ldrb r3, [r6, #0x2] */
/* @0x2b18f4 orrs.w r8, r8, r3, lsl #8 */
/* @0x2b18f8 bpl 0x2b1908 <png_write_iCCP+0x78> */
/* @0x2b18fa ldr r1, [pc, #0x84] */
/* @0x2b18fc mov r0, r4 */
/* @0x2b18fe add r1, pc */
/* @0x2b1900 b 0x2b1912 <png_write_iCCP+0x82> */
/* @0x2b1902 mov r5, r6 */
/* @0x2b1904 mov.w r8, #0x0 */
/* @0x2b1908 cmp r5, r8 */
/* @0x2b190a bge 0x2b1918 <png_write_iCCP+0x88> */
/* @0x2b190c ldr r1, [pc, #0x74] */
/* @0x2b190e mov r0, r4 */
/* @0x2b1910 add r1, pc */
/* @0x2b1912 bl 0x2a6474 <png_warning> */
/* @0x2b1914 eor pc, r7, pc, lsr #27 */
/* @0x2b1916 b 0x2b1968 <png_write_iCCP+0xd8> */
/* @0x2b1918 ble 0x2b1926 <png_write_iCCP+0x96> */
/* @0x2b191a ldr r1, [pc, #0x6c] */
/* @0x2b191c mov r0, r4 */
/* @0x2b191e mov r5, r8 */
/* @0x2b1920 add r1, pc */
/* @0x2b1922 bl 0x2a6474 <png_warning> */
/* @0x2b1924 smlaltblt pc, r5, r7, sp */
/* @0x2b1926 cbz r5, 0x2b193a <png_write_iCCP+0xaa> */
/* @0x2b1928 add r3, sp, #0x14 */
/* @0x2b192a mov r2, r5 */
/* @0x2b192c str r3, [sp] */
/* @0x2b192e mov r0, r4 */
/* @0x2b1930 mov r1, r6 */
/* @0x2b1932 movs r3, #0x0 */
/* @0x2b1934 bl 0x2b0f3c <png_do_write_intrapixel+0x86> */
/* @0x2b1938 mov r5, r0 */
/* @0x2b193a adds r6, r7, #0x2 */
/* @0x2b193c mov r0, r4 */
/* @0x2b193e add r1, sp, #0xc */
/* @0x2b1940 adds r2, r5, r6 */
/* @0x2b1942 bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b1944 blls 0x370a00 <_ZTS13C_UTF16String+0x7aac> */
/* @0x2b1946 ldr r3, [sp, #0x8] */
/* @0x2b1948 mov r0, r4 */
/* @0x2b194a mov r2, r6 */
/* @0x2b194c add r7, r3 */
/* @0x2b194e movs r3, #0x0 */
/* @0x2b1950 strb r3, [r7, #0x1] */
/* @0x2b1952 ldr r1, [sp, #0x8] */
/* @0x2b1954 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b1958 cbz r5, 0x2b1962 <png_write_iCCP+0xd2> */
/* @0x2b195a mov r0, r4 */
/* @0x2b195c add r1, sp, #0x14 */
/* @0x2b195e bl 0x2b1226 <png_write_chunk_data+0x22> */
/* @0x2b1960 strtmi pc, [r0], -r2, ror #24 */
/* @0x2b1962 mov r0, r4 */
/* @0x2b1964 bl 0x2b1296 <png_write_chunk_end> */
/* @0x2b1968 mov r0, r4 */
/* @0x2b196a ldr r1, [sp, #0x8] */
/* @0x2b196c bl 0x2a6cfc <png_free> */
/* @0x2b1970 add sp, #0x28 */
/* @0x2b1972 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2b1974 svclt #0x81f0 */
/* @0x2b1976 nop */
/* @0x2b1978 b 0x2b1300 <png_write_IHDR+0x1c> */
/* @0x2b197a movs r5, r1 */
/* @0x2b197c ldm r2, {r0, r2, r3, r5, r6, r7} */
/* @0x2b197e movs r5, r1 */
/* @0x2b1980 ldm r2!, {r3, r5, r6, r7} */
/* @0x2b1982 movs r5, r1 */
/* @0x2b1984 ldm r3, {r3} */
/* @0x2b1986 movs r5, r1 */
/* @0x2b1988 ldm r3, {r3, r5} */
/* @0x2b198a movs r5, r1 */

/* ── FUNC 0x2b198c · png_write_sPLT · size=288 · insn=125 */
/* @0x2b198c ldr r3, [pc, #0x114] */
/* @0x2b198e push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b1990 ldrbtmi r4, [r11], #-4080 */
/* @0x2b1992 add r3, pc */
/* @0x2b1994 ldr r3, [r3] */
/* @0x2b1996 sub sp, #0x24 */
/* @0x2b1998 mov r6, r0 */
/* @0x2b199a ldr r2, [r3] */
/* @0x2b199c mov r5, r1 */
/* @0x2b199e ldrb.w r8, [r1, #0x4] */
/* @0x2b19a0 ldrmi r8, [r9], r4 */
/* @0x2b19a2 mov r9, r3 */
/* @0x2b19a4 ldr r7, [r1, #0xc] */
/* @0x2b19a6 str r2, [sp, #0x1c] */
/* @0x2b19a8 cmp.w r8, #0x8 */
/* @0x2b19ac ite ne */
/* @0x2b19ae movne.w r8, #0xa */
/* @0x2b19b0 .word 0xf04f080a */
/* @0x2b19b2 moveq.w r8, #0x6 */
/* @0x2b19b4 bmi 0x11b39d4 <b2_toiTime+0xa5a530> */
/* @0x2b19b6 ldr r2, [pc, #0xf0] */
/* @0x2b19b8 ldr r1, [r1] */
/* @0x2b19ba add r2, pc */
/* @0x2b19bc ldr r0, [r2, #43]! */
/* @0x2b19c0 ldrb r2, [r2, #0x4] */
/* @0x2b19c2 str r0, [sp, #0x8] */
/* @0x2b19c4 mov r0, r6 */
/* @0x2b19c6 strb.w r2, [sp, #0xc] */
/* @0x2b19c8 bge 0x2f9a00 <ps_hints_apply+0x8600> */
/* @0x2b19ca add r2, sp, #0x4 */
/* @0x2b19cc bl 0x2af5b0 <png_check_keyword> */
/* @0x2b19d0 mov r4, r0 */
/* @0x2b19d2 cmp r0, #0x0 */
/* @0x2b19d4 beq 0x2b1a90 <png_write_sPLT+0x104> */
/* @0x2b19d6 adds r2, r0, #0x2 */
/* @0x2b19d8 add r1, sp, #0x8 */
/* @0x2b19da mov r0, r6 */
/* @0x2b19dc mov.w r10, #0xa */
/* @0x2b19e0 mla r2, r7, r8, r2 */
/* @0x2b19e4 bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b19e8 adds r2, r4, #0x1 */
/* @0x2b19ea mov r0, r6 */
/* @0x2b19ec ldr r1, [sp, #0x4] */
/* @0x2b19ee bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b19f0 ldrtmi pc, [r0], -r9, lsl #24 */
/* @0x2b19f2 mov r0, r6 */
/* @0x2b19f4 adds r1, r5, #0x4 */
/* @0x2b19f6 movs r2, #0x1 */
/* @0x2b19f8 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b19fc ldr r4, [r5, #0x8] */
/* @0x2b19fe add r7, sp, #0x10 */
/* @0x2b1a00 adds r4, #0xa */
/* @0x2b1a02 add.w r11, r7, #0x2 */
/* @0x2b1a04 stmvs r10!, {r1, r8, r9, r11} ^ */
/* @0x2b1a06 ldr r2, [r5, #0xc] */
/* @0x2b1a08 sub.w r1, r4, #0xa */
/* @0x2b1a0c ldr r3, [r5, #0x8] */
/* @0x2b1a0e mla r3, r10, r2, r3 */
/* @0x2b1a10 addsmi r3, r9, #134217728 */
/* @0x2b1a12 cmp r1, r3 */
/* @0x2b1a14 bhs 0x2b1a82 <png_write_sPLT+0xf6> */
/* @0x2b1a16 ldrb r3, [r5, #0x4] */
/* @0x2b1a18 cmp r3, #0x8 */
/* @0x2b1a1a bne 0x2b1a40 <png_write_sPLT+0xb4> */
/* @0x2b1a1c ldrh r3, [r4, #-10] */
/* @0x2b1a20 adds r0, r7, #0x4 */
/* @0x2b1a22 strb.w r3, [sp, #0x10] */
/* @0x2b1a24 rfeda r4! */
/* @0x2b1a26 ldrh r3, [r4, #-8] */
/* @0x2b1a28 .word 0xf88d3c08 */
/* @0x2b1a2a strb.w r3, [sp, #0x11] */
/* @0x2b1a2c rfeda r4! */
/* @0x2b1a2e ldrh r3, [r4, #-6] */
/* @0x2b1a30 .word 0xf88d3c06 */
/* @0x2b1a32 strb.w r3, [sp, #0x12] */
/* @0x2b1a34 rfeda r4! */
/* @0x2b1a36 ldrh r3, [r4, #-4] */
/* @0x2b1a38 .word 0xf88d3c04 */
/* @0x2b1a3a strb.w r3, [sp, #0x13] */
/* @0x2b1a3c ands r3, r5, r3, lsl r0 */
/* @0x2b1a3e b 0x2b1a6c <png_write_sPLT+0xe0> */
/* @0x2b1a40 mov r0, r7 */
/* @0x2b1a42 ldrh r1, [r4, #-10] */
/* @0x2b1a44 .word 0xf7ff1c0a */
/* @0x2b1a46 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1a48 usub16mi pc, r8, r7 */
/* @0x2b1a4a mov r0, r11 */
/* @0x2b1a4c ldrh r1, [r4, #-8] */
/* @0x2b1a50 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1a54 adds r0, r7, #0x4 */
/* @0x2b1a56 ldrh r1, [r4, #-6] */
/* @0x2b1a58 .word 0xf7ff1c06 */
/* @0x2b1a5a bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1a5c .word 0x1db8fb6d */
/* @0x2b1a5e adds r0, r7, #0x6 */
/* @0x2b1a60 ldrh r1, [r4, #-4] */
/* @0x2b1a64 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1a68 add.w r0, r7, #0x8 */
/* @0x2b1a6c ldrh r1, [r4, #-2] */
/* @0x2b1a70 adds r4, #0xa */
/* @0x2b1a72 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1a74 ldrtmi pc, [r0], -r1, ror #22 */
/* @0x2b1a76 mov r0, r6 */
/* @0x2b1a78 mov r1, r7 */
/* @0x2b1a7a mov r2, r8 */
/* @0x2b1a7c bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b1a80 b 0x2b1a06 <png_write_sPLT+0x7a> */
/* @0x2b1a82 mov r0, r6 */
/* @0x2b1a84 bl 0x2b1296 <png_write_chunk_end> */
/* @0x2b1a88 mov r0, r6 */
/* @0x2b1a8a ldr r1, [sp, #0x4] */
/* @0x2b1a8c bl 0x2a6cfc <png_free> */
/* @0x2b1a90 ldr r2, [sp, #0x1c] */
/* @0x2b1a92 ldr.w r3, [r9] */
/* @0x2b1a94 addsmi r3, r10, #0 */
/* @0x2b1a96 cmp r2, r3 */
/* @0x2b1a98 beq 0x2b1a9e <png_write_sPLT+0x112> */
/* @0x2b1a9a blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b1a9c mullt r9, r12, sp */
/* @0x2b1a9e add sp, #0x24 */
/* @0x2b1aa0 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b1aa4 ittt gt */
/* @0x2b1aa6 movs r3, r2 */
/* @0x2b1aa8 bgt 0x2b21f8 <png_write_oFFs+0x20> */
/* @0x2b1aaa movs r5, r1 */

/* ── FUNC 0x2b1aac · png_write_sBIT · size=160 · insn=72 */
/* @0x2b1aac push {r0, r1, r2, r3, r4, r5, r6, lr} */
/* @0x2b1aae mov r4, r0 */
/* @0x2b1ab0 ldr r3, [pc, #0x90] */
/* @0x2b1ab2 add r3, pc */
/* @0x2b1ab4 ldr r0, [r3, #48]! */
/* @0x2b1ab8 ldrb r3, [r3, #0x4] */
/* @0x2b1aba str r0, [sp, #0x8] */
/* @0x2b1abc lsls r0, r2, #0x1e */
/* @0x2b1abe strb.w r3, [sp, #0xc] */
/* @0x2b1ac0 strle r3, [r0, #-0xc]! */
/* @0x2b1ac2 bpl 0x2b1b06 <png_write_sBIT+0x5a> */
/* @0x2b1ac4 cmp r2, #0x3 */
/* @0x2b1ac6 ldrb r6, [r1] */
/* @0x2b1ac8 ite ne */
/* @0x2b1aca ldrbne.w r3, [r4, #0x1ec] */
/* @0x2b1acc movwhs r3, #0x81ec */
/* @0x2b1ace moveq r3, #0x8 */
/* @0x2b1ad0 cbnz r6, 0x2b1ade <png_write_sBIT+0x32> */
/* @0x2b1ad2 ldr r1, [pc, #0x74] */
/* @0x2b1ad4 mov r0, r4 */
/* @0x2b1ad6 add r1, pc */
/* @0x2b1ad8 bl 0x2a6474 <png_warning> */
/* @0x2b1adc b 0x2b1b40 <png_write_sBIT+0x94> */
/* @0x2b1ade cmp r6, r3 */
/* @0x2b1ae0 bhi 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1ae2 ldrb r5, [r1, #0x1] */
/* @0x2b1ae4 cmp r5, #0x0 */
/* @0x2b1ae6 beq 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1ae8 cmp r5, r3 */
/* @0x2b1aea bhi 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1aec ldrb r0, [r1, #0x2] */
/* @0x2b1aee cmp r0, #0x0 */
/* @0x2b1af0 beq 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1af2 cmp r0, r3 */
/* @0x2b1af4 bhi 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1af6 strb.w r6, [sp, #0x4] */
/* @0x2b1af8 movwhs r6, #0x3004 */
/* @0x2b1afa movs r3, #0x3 */
/* @0x2b1afc strb.w r5, [sp, #0x5] */
/* @0x2b1b00 strb.w r0, [sp, #0x6] */
/* @0x2b1b04 b 0x2b1b1a <png_write_sBIT+0x6e> */
/* @0x2b1b06 ldrb r3, [r1, #0x3] */
/* @0x2b1b08 cmp r3, #0x0 */
/* @0x2b1b0a beq 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1b0c ldrb.w r0, [r4, #0x1ec] */
/* @0x2b1b10 cmp r0, r3 */
/* @0x2b1b12 blo 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1b14 strb.w r3, [sp, #0x4] */
/* @0x2b1b18 movs r3, #0x1 */
/* @0x2b1b1a lsls r2, r2, #0x1d */
/* @0x2b1b1c bpl 0x2b1b36 <png_write_sBIT+0x8a> */
/* @0x2b1b1e ldrb r2, [r1, #0x4] */
/* @0x2b1b20 cmp r2, #0x0 */
/* @0x2b1b22 beq 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1b24 ldrb.w r1, [r4, #0x1ec] */
/* @0x2b1b28 cmp r1, r2 */
/* @0x2b1b2a blo 0x2b1ad2 <png_write_sBIT+0x26> */
/* @0x2b1b2c add r1, sp, #0x10 */
/* @0x2b1b2e add r1, r3 */
/* @0x2b1b30 adds r3, #0x1 */
/* @0x2b1b32 strb r2, [r1, #-12] */
/* @0x2b1b34 strtmi r2, [r0], -r12, lsl #24 */
/* @0x2b1b36 mov r0, r4 */
/* @0x2b1b38 add r1, sp, #0x8 */
/* @0x2b1b3a add r2, sp, #0x4 */
/* @0x2b1b3c bl 0x2b12bc <png_write_chunk> */
/* @0x2b1b40 add sp, #0x10 */
/* @0x2b1b42 pop {r4, r5, r6, pc} */
/* @0x2b1b44 b 0x2b20a4 <png_write_zTXt+0xa0> */
/* @0x2b1b46 movs r5, r1 */
/* @0x2b1b48 ldm r1!, {r2, r5, r7} */
/* @0x2b1b4a movs r5, r1 */

/* ── FUNC 0x2b1b4c · anon_2b1b4c · size=0 · insn=1 */
/* @0x2b1b4c andeq r0, r0, r0 */

/* ── FUNC 0x2b1b50 · png_write_cHRM · size=368 · insn=147 */
/* @0x2b1b50 vmov.f64 d7, #5.000000e-01 */
/* @0x2b1b54 vldr d6, [pc, #344] */
/* @0x2b1b58 vmov d4, r2, r3 */
/* @0x2b1b5c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b1b60 vpush {d8, d9} */
/* @0x2b1b64 sub sp, #0x4c */
/* @0x2b1b66 ldr.w r8, [pc, #0x150] */
/* @0x2b1b68 pkhtbmi r8, r1, r0, asr #2 */
/* @0x2b1b6a mov r9, r0 */
/* @0x2b1b6c add r8, pc */
/* @0x2b1b6e ldr.w r8, [r8] */
/* @0x2b1b70 .word 0xf8d88000 */
/* @0x2b1b72 ldr.w r1, [r8] */
/* @0x2b1b74 strbmi r1, [r3], r0 */
/* @0x2b1b76 mov r11, r8 */
/* @0x2b1b78 vmov.f64 d5, d7 */
/* @0x2b1b7c str r1, [sp, #0x44] */
/* @0x2b1b7e ldr r1, [pc, #0x13c] */
/* @0x2b1b80 vmla.f64 d5, d4, d6 */
/* @0x2b1b84 add r1, pc */
/* @0x2b1b86 ldr r0, [r1, #53]! */
/* @0x2b1b88 stmdbvc r9, {r0, r2, r4, r5, r8, r9, r10, r11} */
/* @0x2b1b8a ldrb r1, [r1, #0x4] */
/* @0x2b1b8c str r0, [sp, #0x1c] */
/* @0x2b1b8e mov r0, r9 */
/* @0x2b1b90 strb.w r1, [sp, #0x20] */
/* @0x2b1b94 vcvt.u32.f64 s9, d5 */
/* @0x2b1b98 vldr d5, [sp, #128] */
/* @0x2b1b9c vmov r4, s9 */
/* @0x2b1ba0 vmov.f64 d4, d7 */
/* @0x2b1ba4 vmla.f64 d4, d5, d6 */
/* @0x2b1ba8 vldr d5, [sp, #136] */
/* @0x2b1bac mov r1, r4 */
/* @0x2b1bae vcvt.u32.f64 s9, d4 */
/* @0x2b1bb0 vnmla.f64 d4, d20, d4 */
/* @0x2b1bb2 vmov r5, s9 */
/* @0x2b1bb4 .word 0xeeb05a90 */
/* @0x2b1bb6 vmov.f64 d4, d7 */
/* @0x2b1bb8 vmls.f64 d4, d5, d7 */
/* @0x2b1bba vmla.f64 d4, d5, d6 */
/* @0x2b1bbc vldr d4, [sp, #24] */
/* @0x2b1bbe vldr d5, [sp, #144] */
/* @0x2b1bc0 strtmi r5, [r10], -r4, lsr #22 */
/* @0x2b1bc2 mov r2, r5 */
/* @0x2b1bc4 vcvt.u32.f64 s9, d4 */
/* @0x2b1bc8 vmov r6, s9 */
/* @0x2b1bcc vmov.f64 d4, d7 */
/* @0x2b1bd0 vmla.f64 d4, d5, d6 */
/* @0x2b1bd4 vldr d5, [sp, #152] */
/* @0x2b1bd8 mov r3, r6 */
/* @0x2b1bda vcvt.u32.f64 s9, d4 */
/* @0x2b1bdc vnmla.f64 d4, d20, d4 */
/* @0x2b1bde vmov r7, s9 */
/* @0x2b1be0 .word 0xeeb07a90 */
/* @0x2b1be2 vmov.f64 d4, d7 */
/* @0x2b1be4 vmls.f64 d4, d5, d7 */
/* @0x2b1be6 vmla.f64 d4, d5, d6 */
/* @0x2b1be8 vldr d4, [sp, #24] */
/* @0x2b1bea vldr d5, [sp, #160] */
/* @0x2b1bec .word 0xeefc5b28 */
/* @0x2b1bee vcvt.u32.f64 s9, d4 */
/* @0x2b1bf0 vnmla.f64 d4, d20, d4 */
/* @0x2b1bf2 vmov r10, s9 */
/* @0x2b1bf4 .word 0xeeb0aa90 */
/* @0x2b1bf6 vmov.f64 d4, d7 */
/* @0x2b1bf8 vmls.f64 d4, d5, d7 */
/* @0x2b1bfa vmla.f64 d4, d5, d6 */
/* @0x2b1bfc vldr d4, [sp, #24] */
/* @0x2b1bfe vldr d5, [sp, #168] */
/* @0x2b1c00 stm sp, {r1, r3, r5, r8, r9, r11, r12, lr} */
/* @0x2b1c02 stm.w sp, {r7, r10} */
/* @0x2b1c04 cdp p4, #0xb, c0, c12, c0, #0x4 */
/* @0x2b1c06 vcvt.u32.f64 s18, d4 */
/* @0x2b1c08 vabs.f64 d9, d4 */
/* @0x2b1c0a vmov.f64 d4, d7 */
/* @0x2b1c0c vstr d4, [sp, #284] */
/* @0x2b1c0e vstr s18, [sp, #8] */
/* @0x2b1c10 vmla.f32 s18, s10, s4 */
/* @0x2b1c12 vmla.f64 d4, d5, d6 */
/* @0x2b1c14 vldr d4, [sp, #24] */
/* @0x2b1c16 vldr d5, [sp, #176] */
/* @0x2b1c18 vmla.f64 d5, d5, d28 */
/* @0x2b1c1a vmla.f64 d7, d5, d6 */
/* @0x2b1c1c vmov.f64 d23, #-1.718750e-01 */
/* @0x2b1c1e vcvt.u32.f64 s17, d4 */
/* @0x2b1c20 vcvt.u32.f64 s16, d4 */
/* @0x2b1c22 vcvt.u32.f64 s16, d7 */
/* @0x2b1c24 vstr d24, [sp, #796] */
/* @0x2b1c26 vstr s17, [sp, #12] */
/* @0x2b1c28 vstr s16, [sp, #12] */
/* @0x2b1c2a vstr s16, [sp, #16] */
/* @0x2b1c2c .word 0xf7f48a04 */
/* @0x2b1c2e bl 0x2a6068 <png_check_cHRM_fixed> */
/* @0x2b1c30 orrlt pc, r8, #110592 */
/* @0x2b1c32 cbz r0, 0x2b1c98 <png_write_cHRM+0x148> */
/* @0x2b1c34 add.w r8, sp, #0x24 */
/* @0x2b1c38 mov r1, r4 */
/* @0x2b1c3a mov r0, r8 */
/* @0x2b1c3c bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1c40 add.w r0, r8, #0x4 */
/* @0x2b1c44 mov r1, r5 */
/* @0x2b1c46 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1c48 .word 0xf108fa6d */
/* @0x2b1c4a add.w r0, r8, #0x8 */
/* @0x2b1c4c ldrtmi r0, [r1], -r8 */
/* @0x2b1c4e mov r1, r6 */
/* @0x2b1c50 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1c54 add.w r0, r8, #0xc */
/* @0x2b1c58 mov r1, r7 */
/* @0x2b1c5a bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1c5c .word 0xf108fa63 */
/* @0x2b1c5e add.w r0, r8, #0x10 */
/* @0x2b1c60 uadd16mi r0, r1, r0 */
/* @0x2b1c62 mov r1, r10 */
/* @0x2b1c64 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1c68 add.w r0, r8, #0x14 */
/* @0x2b1c6c vmov r1, s18 */
/* @0x2b1c70 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1c74 add.w r0, r8, #0x18 */
/* @0x2b1c78 vmov r1, s17 */
/* @0x2b1c7c bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1c80 add.w r0, r8, #0x1c */
/* @0x2b1c84 vmov r1, s16 */
/* @0x2b1c88 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1c8c mov r0, r9 */
/* @0x2b1c8e add r1, sp, #0x1c */
/* @0x2b1c90 mov r2, r8 */
/* @0x2b1c92 movs r3, #0x20 */
/* @0x2b1c94 bl 0x2b12bc <png_write_chunk> */
/* @0x2b1c98 ldr r2, [sp, #0x44] */
/* @0x2b1c9a ldr.w r3, [r11] */
/* @0x2b1c9c addsmi r3, r10, #0 */
/* @0x2b1c9e cmp r2, r3 */
/* @0x2b1ca0 beq 0x2b1ca6 <png_write_cHRM+0x156> */
/* @0x2b1ca2 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b1ca4 mulslt r3, r8, r12 */
/* @0x2b1ca6 add sp, #0x4c */
/* @0x2b1ca8 vpop {d8, d9} */
/* @0x2b1cac pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b1cb0 movs r0, r0 */
/* @0x2b1cb2 movs r0, r0 */
/* @0x2b1cb4 ldr r0, [r0, #0x20] */
/* @0x2b1cb6 lsrs r0, r7 */
/* @0x2b1cb8 pop {r3, r5, r6, r7, pc} */
/* @0x2b1cba movs r3, r2 */
/* @0x2b1cbc b 0x2b2078 <png_write_zTXt+0x74> */
/* @0x2b1cbe movs r5, r1 */

/* ── FUNC 0x2b1cc0 · png_write_cHRM_fixed · size=192 · insn=82 */
/* @0x2b1cc0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b1cc4 mov r5, r0 */
/* @0x2b1cc6 ldr r4, [pc, #0xb0] */
/* @0x2b1cc8 sub sp, #0x4c */
/* @0x2b1cca ldr.w lr, [pc, #0xb0] */
/* @0x2b1ccc selmi lr, r8, r0 */
/* @0x2b1cce mov r8, r1 */
/* @0x2b1cd0 add r4, pc */
/* @0x2b1cd2 ldr r4, [r4] */
/* @0x2b1cd4 ldr r7, [sp, #0x74] */
/* @0x2b1cd6 add lr, pc */
/* @0x2b1cd8 ldr r6, [sp, #0x78] */
/* @0x2b1cda ldr r0, [r4] */
/* @0x2b1cdc mov r11, r2 */
/* @0x2b1cde mov r10, r3 */
/* @0x2b1ce0 mov r9, r4 */
/* @0x2b1ce2 str r6, [sp, #0x8] */
/* @0x2b1ce4 str r0, [sp, #0x44] */
/* @0x2b1ce6 ldr r0, [lr, #53]! */
/* @0x2b1ce8 andls r0, r7, r5, lsr pc */
/* @0x2b1cea str r0, [sp, #0x1c] */
/* @0x2b1cec ldrb.w r0, [lr, #0x4] */
/* @0x2b1cf0 strb.w r0, [sp, #0x20] */
/* @0x2b1cf4 ldr r0, [sp, #0x70] */
/* @0x2b1cf6 stm.w sp, {r0, r7} */
/* @0x2b1cf8 ldmdals pc, {r0, r7} */
/* @0x2b1cfa ldr r0, [sp, #0x7c] */
/* @0x2b1cfc str r0, [sp, #0xc] */
/* @0x2b1cfe ldr r0, [sp, #0x80] */
/* @0x2b1d00 str r0, [sp, #0x10] */
/* @0x2b1d02 mov r0, r5 */
/* @0x2b1d04 bl 0x2a6068 <png_check_cHRM_fixed> */
/* @0x2b1d08 cbz r0, 0x2b1d64 <png_write_cHRM_fixed+0xa4> */
/* @0x2b1d0a add r4, sp, #0x24 */
/* @0x2b1d0c mov r1, r8 */
/* @0x2b1d0e mov r0, r4 */
/* @0x2b1d10 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1d14 adds r0, r4, #0x4 */
/* @0x2b1d16 mov r1, r11 */
/* @0x2b1d18 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1d1c add.w r0, r4, #0x8 */
/* @0x2b1d20 mov r1, r10 */
/* @0x2b1d22 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1d24 .word 0xf104f9ff */
/* @0x2b1d26 add.w r0, r4, #0xc */
/* @0x2b1d28 ldmdbls r12, {r2, r3} */
/* @0x2b1d2a ldr r1, [sp, #0x70] */
/* @0x2b1d2c bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1d30 add.w r0, r4, #0x10 */
/* @0x2b1d34 mov r1, r7 */
/* @0x2b1d36 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1d38 .word 0xf104f9f5 */
/* @0x2b1d3a add.w r0, r4, #0x14 */
/* @0x2b1d3c shadd16mi r0, r1, r4 */
/* @0x2b1d3e mov r1, r6 */
/* @0x2b1d40 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1d44 add.w r0, r4, #0x18 */
/* @0x2b1d48 ldr r1, [sp, #0x7c] */
/* @0x2b1d4a bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1d4c .word 0xf104f9eb */
/* @0x2b1d4e add.w r0, r4, #0x1c */
/* @0x2b1d50 stmdbls r0!, {r2, r3, r4} */
/* @0x2b1d52 ldr r1, [sp, #0x80] */
/* @0x2b1d54 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b1d58 mov r0, r5 */
/* @0x2b1d5a add r1, sp, #0x1c */
/* @0x2b1d5c mov r2, r4 */
/* @0x2b1d5e movs r3, #0x20 */
/* @0x2b1d60 bl 0x2b12bc <png_write_chunk> */
/* @0x2b1d64 ldr r2, [sp, #0x44] */
/* @0x2b1d66 ldr.w r3, [r9] */
/* @0x2b1d68 addsmi r3, r10, #0 */
/* @0x2b1d6a cmp r2, r3 */
/* @0x2b1d6c beq 0x2b1d72 <png_write_cHRM_fixed+0xb2> */
/* @0x2b1d6e blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b1d70 andslt lr, r3, r2, lsr r12 */
/* @0x2b1d72 add sp, #0x4c */
/* @0x2b1d74 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b1d78 pop {r2, r7} */
/* @0x2b1d7a movs r3, r2 */
/* @0x2b1d7c b 0x2b1e94 <png_write_bKGD+0x40> */
/* @0x2b1d7e movs r5, r1 */

/* ── FUNC 0x2b1d80 · png_write_tRNS · size=212 · insn=95 */
/* @0x2b1d80 push {r4, r5, r6, r7, lr} */
/* @0x2b1d82 mov r6, r2 */
/* @0x2b1d84 ldr r2, [pc, #0xb8] */
/* @0x2b1d86 sub sp, #0x14 */
/* @0x2b1d88 mov r4, r0 */
/* @0x2b1d8a mov r12, r1 */
/* @0x2b1d8c add r2, pc */
/* @0x2b1d8e ldr r5, [sp, #0x28] */
/* @0x2b1d90 ldr r0, [r2, #58]! */
/* @0x2b1d94 cmp r5, #0x3 */
/* @0x2b1d96 ldrb r2, [r2, #0x4] */
/* @0x2b1d98 str r0, [sp] */
/* @0x2b1d9a strb.w r2, [sp, #0x4] */
/* @0x2b1d9c .word 0xd10c2004 */
/* @0x2b1d9e bne 0x2b1dba <png_write_tRNS+0x3a> */
/* @0x2b1da0 cmp r3, #0x0 */
/* @0x2b1da2 mov r0, r4 */
/* @0x2b1da4 ble 0x2b1dae <png_write_tRNS+0x2e> */
/* @0x2b1da6 ldrh.w r2, [r4, #0x1dc] */
/* @0x2b1da8 addsmi r2, r3, #220, #2 */
/* @0x2b1daa cmp r3, r2 */
/* @0x2b1dac ble 0x2b1db4 <png_write_tRNS+0x34> */
/* @0x2b1dae ldr r1, [pc, #0x94] */
/* @0x2b1db0 add r1, pc */
/* @0x2b1db2 b 0x2b1e38 <png_write_tRNS+0xb8> */
/* @0x2b1db4 mov r1, sp */
/* @0x2b1db6 mov r2, r12 */
/* @0x2b1db8 b 0x2b1e2c <png_write_tRNS+0xac> */
/* @0x2b1dba cbnz r5, 0x2b1de6 <png_write_tRNS+0x66> */
/* @0x2b1dbc ldrb.w r3, [r4, #0x1eb] */
/* @0x2b1dc0 movs r2, #0x1 */
/* @0x2b1dc2 ldrh r1, [r6, #0x8] */
/* @0x2b1dc4 lsl.w r3, r2, r3 */
/* @0x2b1dc8 cmp r1, r3 */
/* @0x2b1dca blt 0x2b1dd4 <png_write_tRNS+0x54> */
/* @0x2b1dcc ldr r1, [pc, #0x78] */
/* @0x2b1dce mov r0, r4 */
/* @0x2b1dd0 add r1, pc */
/* @0x2b1dd2 b 0x2b1e38 <png_write_tRNS+0xb8> */
/* @0x2b1dd4 add r5, sp, #0x8 */
/* @0x2b1dd6 mov r0, r5 */
/* @0x2b1dd8 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1ddc mov r0, r4 */
/* @0x2b1dde mov r1, sp */
/* @0x2b1de0 mov r2, r5 */
/* @0x2b1de2 movs r3, #0x2 */
/* @0x2b1de4 b 0x2b1e2c <png_write_tRNS+0xac> */
/* @0x2b1de6 cmp r5, #0x2 */
/* @0x2b1de8 bne 0x2b1e32 <png_write_tRNS+0xb2> */
/* @0x2b1dea add r5, sp, #0x8 */
/* @0x2b1dec ldrh r1, [r6, #0x2] */
/* @0x2b1dee mov r0, r5 */
/* @0x2b1df0 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1df4 adds r0, r5, #0x2 */
/* @0x2b1df6 ldrh r1, [r6, #0x4] */
/* @0x2b1df8 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1dfc adds r0, r5, #0x4 */
/* @0x2b1dfe ldrh r1, [r6, #0x6] */
/* @0x2b1e00 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1e04 ldrb.w r3, [r4, #0x1eb] */
/* @0x2b1e08 mov r0, r4 */
/* @0x2b1e0a cmp r3, #0x8 */
/* @0x2b1e0c bne 0x2b1e26 <png_write_tRNS+0xa6> */
/* @0x2b1e0e ldrb.w r3, [sp, #0x8] */
/* @0x2b1e10 .word 0xf89d3008 */
/* @0x2b1e12 ldrb.w r2, [sp, #0xa] */
/* @0x2b1e14 tstmi r10, #10 */
/* @0x2b1e16 orrs r2, r3 */
/* @0x2b1e18 ldrb.w r3, [sp, #0xc] */
/* @0x2b1e1c orrs r3, r2 */
/* @0x2b1e1e beq 0x2b1e26 <png_write_tRNS+0xa6> */
/* @0x2b1e20 ldr r1, [pc, #0x28] */
/* @0x2b1e22 add r1, pc */
/* @0x2b1e24 b 0x2b1e38 <png_write_tRNS+0xb8> */
/* @0x2b1e26 mov r1, sp */
/* @0x2b1e28 mov r2, r5 */
/* @0x2b1e2a movs r3, #0x6 */
/* @0x2b1e2c bl 0x2b12bc <png_write_chunk> */
/* @0x2b1e30 b 0x2b1e3c <png_write_tRNS+0xbc> */
/* @0x2b1e32 ldr r1, [pc, #0x1c] */
/* @0x2b1e34 mov r0, r4 */
/* @0x2b1e36 add r1, pc */
/* @0x2b1e38 bl 0x2a6474 <png_warning> */
/* @0x2b1e3c add sp, #0x14 */
/* @0x2b1e3e pop {r4, r5, r6, r7, pc} */
/* @0x2b1e40 svc #0xd4 */
/* @0x2b1e42 movs r5, r1 */
/* @0x2b1e44 stm r6!, {r0, r1, r2, r5, r6, r7} */
/* @0x2b1e46 movs r5, r1 */
/* @0x2b1e48 stm r6!, {r1, r2, r4, r5, r6, r7} */
/* @0x2b1e4a movs r5, r1 */
/* @0x2b1e4c stm r6!, {r2, r5, r6, r7} */
/* @0x2b1e4e movs r5, r1 */
/* @0x2b1e50 stm r7!, {r4} */
/* @0x2b1e52 movs r5, r1 */

/* ── FUNC 0x2b1e54 · png_write_bKGD · size=212 · insn=97 */
/* @0x2b1e54 ldr r3, [pc, #0xc0] */
/* @0x2b1e56 cmp r2, #0x3 */
/* @0x2b1e58 push {r4, r5, r6, r7, lr} */
/* @0x2b1e5a add r3, pc */
/* @0x2b1e5c mov r4, r0 */
/* @0x2b1e5e sub sp, #0x14 */
/* @0x2b1e60 ldr r0, [r3, #63]! */
/* @0x2b1e64 mov r5, r1 */
/* @0x2b1e66 ldrb r3, [r3, #0x4] */
/* @0x2b1e68 str r0, [sp] */
/* @0x2b1e6a strb.w r3, [sp, #0x4] */
/* @0x2b1e6c tstle r4, r4 */
/* @0x2b1e6e bne 0x2b1e9a <png_write_bKGD+0x46> */
/* @0x2b1e70 ldrh.w r2, [r4, #0x1dc] */
/* @0x2b1e74 ldrb r3, [r1] */
/* @0x2b1e76 cbnz r2, 0x2b1e80 <png_write_bKGD+0x2c> */
/* @0x2b1e78 ldr.w r1, [r4, #0x2dc] */
/* @0x2b1e7c lsls r1, r1, #0x1f */
/* @0x2b1e7e bmi 0x2b1e8c <png_write_bKGD+0x38> */
/* @0x2b1e80 cmp r3, r2 */
/* @0x2b1e82 blo 0x2b1e8c <png_write_bKGD+0x38> */
/* @0x2b1e84 ldr r1, [pc, #0x94] */
/* @0x2b1e86 mov r0, r4 */
/* @0x2b1e88 add r1, pc */
/* @0x2b1e8a b 0x2b1ef8 <png_write_bKGD+0xa4> */
/* @0x2b1e8c add r2, sp, #0x10 */
/* @0x2b1e8e mov r0, r4 */
/* @0x2b1e90 mov r1, sp */
/* @0x2b1e92 strb r3, [r2, #-8]! */
/* @0x2b1e94 movwhs r3, #0x1d08 */
/* @0x2b1e96 movs r3, #0x1 */
/* @0x2b1e98 b 0x2b1f0e <png_write_bKGD+0xba> */
/* @0x2b1e9a lsls r3, r2, #0x1e */
/* @0x2b1e9c bpl 0x2b1ee2 <png_write_bKGD+0x8e> */
/* @0x2b1e9e add r6, sp, #0x8 */
/* @0x2b1ea0 ldrh r1, [r1, #0x2] */
/* @0x2b1ea2 mov r0, r6 */
/* @0x2b1ea4 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1ea8 adds r0, r6, #0x2 */
/* @0x2b1eaa ldrh r1, [r5, #0x4] */
/* @0x2b1eac bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1eb0 adds r0, r6, #0x4 */
/* @0x2b1eb2 ldrh r1, [r5, #0x6] */
/* @0x2b1eb4 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1eb8 ldrb.w r3, [r4, #0x1eb] */
/* @0x2b1ebc mov r0, r4 */
/* @0x2b1ebe cmp r3, #0x8 */
/* @0x2b1ec0 bne 0x2b1eda <png_write_bKGD+0x86> */
/* @0x2b1ec2 ldrb.w r3, [sp, #0x8] */
/* @0x2b1ec4 .word 0xf89d3008 */
/* @0x2b1ec6 ldrb.w r2, [sp, #0xa] */
/* @0x2b1ec8 tstmi r10, #10 */
/* @0x2b1eca orrs r2, r3 */
/* @0x2b1ecc ldrb.w r3, [sp, #0xc] */
/* @0x2b1ed0 orrs r3, r2 */
/* @0x2b1ed2 beq 0x2b1eda <png_write_bKGD+0x86> */
/* @0x2b1ed4 ldr r1, [pc, #0x48] */
/* @0x2b1ed6 add r1, pc */
/* @0x2b1ed8 b 0x2b1ef8 <png_write_bKGD+0xa4> */
/* @0x2b1eda mov r1, sp */
/* @0x2b1edc mov r2, r6 */
/* @0x2b1ede movs r3, #0x6 */
/* @0x2b1ee0 b 0x2b1f0e <png_write_bKGD+0xba> */
/* @0x2b1ee2 ldrb.w r3, [r4, #0x1eb] */
/* @0x2b1ee4 andhs r3, r1, #-1073741766 */
/* @0x2b1ee6 movs r2, #0x1 */
/* @0x2b1ee8 ldrh r1, [r1, #0x8] */
/* @0x2b1eea lsl.w r3, r2, r3 */
/* @0x2b1eec addsmi pc, r9, #201326592 */
/* @0x2b1eee cmp r1, r3 */
/* @0x2b1ef0 blt 0x2b1efe <png_write_bKGD+0xaa> */
/* @0x2b1ef2 ldr r1, [pc, #0x30] */
/* @0x2b1ef4 mov r0, r4 */
/* @0x2b1ef6 add r1, pc */
/* @0x2b1ef8 bl 0x2a6474 <png_warning> */
/* @0x2b1efc b 0x2b1f12 <png_write_bKGD+0xbe> */
/* @0x2b1efe add r5, sp, #0x8 */
/* @0x2b1f00 mov r0, r5 */
/* @0x2b1f02 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1f04 qadd16mi pc, r0, r9 */
/* @0x2b1f06 mov r0, r4 */
/* @0x2b1f08 mov r1, sp */
/* @0x2b1f0a mov r2, r5 */
/* @0x2b1f0c movs r3, #0x2 */
/* @0x2b1f0e bl 0x2b12bc <png_write_chunk> */
/* @0x2b1f10 .word 0xb005f9d5 */
/* @0x2b1f12 add sp, #0x14 */
/* @0x2b1f14 pop {r4, r5, r6, r7, pc} */
/* @0x2b1f16 nop */
/* @0x2b1f18 svc #0x6 */
/* @0x2b1f1a movs r5, r1 */
/* @0x2b1f1c stm r6!, {r0, r2, r5, r6, r7} */
/* @0x2b1f1e movs r5, r1 */
/* @0x2b1f20 stm r6!, {r3, r4, r5, r7} */
/* @0x2b1f22 movs r5, r1 */
/* @0x2b1f24 stm r6!, {r3, r4, r6, r7} */
/* @0x2b1f26 movs r5, r1 */

/* ── FUNC 0x2b1f28 · png_write_hIST · size=108 · insn=48 */
/* @0x2b1f28 push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr} */
/* @0x2b1f2c mov r4, r0 */
/* @0x2b1f2e ldr r3, [pc, #0x5c] */
/* @0x2b1f30 mov r8, r1 */
/* @0x2b1f32 mov r6, r2 */
/* @0x2b1f34 add r3, pc */
/* @0x2b1f36 ldr r0, [r3, #68]! */
/* @0x2b1f38 ldmdbvc r11, {r2, r6, r8, r9, r10, r11} */
/* @0x2b1f3a ldrb r3, [r3, #0x4] */
/* @0x2b1f3c str r0, [sp, #0x8] */
/* @0x2b1f3e mov r0, r4 */
/* @0x2b1f40 strb.w r3, [sp, #0xc] */
/* @0x2b1f44 ldrh.w r3, [r4, #0x1dc] */
/* @0x2b1f48 cmp r2, r3 */
/* @0x2b1f4a ble 0x2b1f56 <png_write_hIST+0x2e> */
/* @0x2b1f4c ldr r1, [pc, #0x40] */
/* @0x2b1f4e add r1, pc */
/* @0x2b1f50 bl 0x2a6474 <png_warning> */
/* @0x2b1f54 b 0x2b1f84 <png_write_hIST+0x5c> */
/* @0x2b1f56 add r1, sp, #0x8 */
/* @0x2b1f58 lsls r2, r2, #0x1 */
/* @0x2b1f5a bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b1f5c svcge #0x1f921 */
/* @0x2b1f5e add r7, sp, #0x4 */
/* @0x2b1f60 movs r5, #0x0 */
/* @0x2b1f62 cmp r5, r6 */
/* @0x2b1f64 bge 0x2b1f7e <png_write_hIST+0x56> */
/* @0x2b1f66 ldrh.w r1, [r8, r5, lsl #1] */
/* @0x2b1f68 shadd16mi r1, r8, r5 */
/* @0x2b1f6a mov r0, r7 */
/* @0x2b1f6c bl 0x2b1138 <png_save_uint_16> */
/* @0x2b1f70 mov r0, r4 */
/* @0x2b1f72 mov r1, r7 */
/* @0x2b1f74 movs r2, #0x2 */
/* @0x2b1f76 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b1f78 strlo pc, [r1, #-0x945] */
/* @0x2b1f7a adds r5, #0x1 */
/* @0x2b1f7c b 0x2b1f62 <png_write_hIST+0x3a> */
/* @0x2b1f7e mov r0, r4 */
/* @0x2b1f80 bl 0x2b1296 <png_write_chunk_end> */
/* @0x2b1f84 add sp, #0x10 */
/* @0x2b1f86 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2b1f88 svclt #0x81f0 */
/* @0x2b1f8a nop */
/* @0x2b1f8c udf #0x2c */
/* @0x2b1f8e movs r5, r1 */
/* @0x2b1f90 stm r6!, {r6, r7} */
/* @0x2b1f92 movs r5, r1 */

/* ── FUNC 0x2b1f94 · png_write_tEXt · size=112 · insn=51 */
/* @0x2b1f94 ldr r3, [pc, #0x68] */
/* @0x2b1f96 push {r4, r5, r6, r7, lr} */
/* @0x2b1f98 add r3, pc */
/* @0x2b1f9a mov r4, r0 */
/* @0x2b1f9c sub sp, #0x14 */
/* @0x2b1f9e ldr r0, [r3, #73]! */
/* @0x2b1fa0 ldrmi r0, [r5], -r9, asr #30 */
/* @0x2b1fa2 mov r5, r2 */
/* @0x2b1fa4 add r2, sp, #0x4 */
/* @0x2b1fa6 ldrb r3, [r3, #0x4] */
/* @0x2b1fa8 str r0, [sp, #0x8] */
/* @0x2b1faa mov r0, r4 */
/* @0x2b1fac strb.w r3, [sp, #0xc] */
/* @0x2b1fb0 bl 0x2af5b0 <png_check_keyword> */
/* @0x2b1fb4 mov r7, r0 */
/* @0x2b1fb6 cbz r0, 0x2b1ffa <png_write_tEXt+0x66> */
/* @0x2b1fb8 cbz r5, 0x2b1fc8 <png_write_tEXt+0x34> */
/* @0x2b1fba ldrb r6, [r5] */
/* @0x2b1fbc cbz r6, 0x2b1fca <png_write_tEXt+0x36> */
/* @0x2b1fbe mov r0, r5 */
/* @0x2b1fc0 blx 0xb6538 <strlen@plt> */
/* @0x2b1fc4 mov r6, r0 */
/* @0x2b1fc6 b 0x2b1fca <png_write_tEXt+0x36> */
/* @0x2b1fc8 mov r6, r5 */
/* @0x2b1fca adds r7, #0x1 */
/* @0x2b1fcc mov r0, r4 */
/* @0x2b1fce add r1, sp, #0x8 */
/* @0x2b1fd0 adds r2, r6, r7 */
/* @0x2b1fd2 bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b1fd4 strtmi pc, [r0], -r5, ror #17 */
/* @0x2b1fd6 mov r0, r4 */
/* @0x2b1fd8 ldr r1, [sp, #0x4] */
/* @0x2b1fda mov r2, r7 */
/* @0x2b1fdc bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b1fe0 cbz r6, 0x2b1fec <png_write_tEXt+0x58> */
/* @0x2b1fe2 mov r0, r4 */
/* @0x2b1fe4 mov r1, r5 */
/* @0x2b1fe6 mov r2, r6 */
/* @0x2b1fe8 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b1fec mov r0, r4 */
/* @0x2b1fee bl 0x2b1296 <png_write_chunk_end> */
/* @0x2b1ff0 qsaxmi pc, r0, r2 */
/* @0x2b1ff2 mov r0, r4 */
/* @0x2b1ff4 ldr r1, [sp, #0x4] */
/* @0x2b1ff6 bl 0x2a6cfc <png_free> */
/* @0x2b1ff8 andlt pc, r5, r1, lsl #29 */
/* @0x2b1ffa add sp, #0x14 */
/* @0x2b1ffc pop {r4, r5, r6, r7, pc} */
/* @0x2b1ffe nop */
/* @0x2b2000 ble 0x2b1f94 <png_write_tEXt> */
/* @0x2b2002 movs r5, r1 */

/* ── FUNC 0x2b2004 · png_write_zTXt · size=180 · insn=84 */
/* @0x2b2004 ldr r3, [pc, #0xac] */
/* @0x2b2006 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2b2008 ldrbtmi r4, [r11], #-496 */
/* @0x2b200a add r3, pc */
/* @0x2b200c mov r4, r0 */
/* @0x2b200e sub sp, #0x30 */
/* @0x2b2010 ldr r0, [r3, #78]! */
/* @0x2b2014 mov r5, r2 */
/* @0x2b2016 movs r2, #0x0 */
/* @0x2b2018 str r2, [sp, #0x24] */
/* @0x2b201a str r2, [sp, #0x28] */
/* @0x2b201c ldrb r3, [r3, #0x4] */
/* @0x2b201e str r0, [sp, #0x14] */
/* @0x2b2020 mov r0, r4 */
/* @0x2b2022 str r2, [sp, #0x2c] */
/* @0x2b2024 str r2, [sp, #0x1c] */
/* @0x2b2026 str r2, [sp, #0x20] */
/* @0x2b2028 add r2, sp, #0x10 */
/* @0x2b202a ldr r6, [sp, #0x48] */
/* @0x2b202c strb.w r3, [sp, #0x18] */
/* @0x2b2030 bl 0x2af5b0 <png_check_keyword> */
/* @0x2b2034 mov r7, r0 */
/* @0x2b2036 cbz r0, 0x2b204e <png_write_zTXt+0x4a> */
/* @0x2b2038 cbz r5, 0x2b2042 <png_write_zTXt+0x3e> */
/* @0x2b203a ldrb r3, [r5] */
/* @0x2b203c cbz r3, 0x2b2042 <png_write_zTXt+0x3e> */
/* @0x2b203e adds r3, r6, #0x1 */
/* @0x2b2040 bne 0x2b2058 <png_write_zTXt+0x54> */
/* @0x2b2042 mov r0, r4 */
/* @0x2b2044 ldr r1, [sp, #0x10] */
/* @0x2b2046 mov r2, r5 */
/* @0x2b2048 movs r3, #0x0 */
/* @0x2b204a bl 0x2b1f94 <png_write_tEXt> */
/* @0x2b204c strtmi pc, [r0], -r3, lsr #31 */
/* @0x2b204e mov r0, r4 */
/* @0x2b2050 ldr r1, [sp, #0x10] */
/* @0x2b2052 bl 0x2a6cfc <png_free> */
/* @0x2b2054 eor pc, r9, r3, asr lr */
/* @0x2b2056 b 0x2b20ac <png_write_zTXt+0xa8> */
/* @0x2b2058 mov r0, r5 */
/* @0x2b205a add.w r8, sp, #0x1c */
/* @0x2b205c .word 0xf604081c */
/* @0x2b205e blx 0xb6538 <strlen@plt> */
/* @0x2b2060 ldrtmi lr, [r3], -r12, ror #20 */
/* @0x2b2062 mov r3, r6 */
/* @0x2b2064 mov r1, r5 */
/* @0x2b2066 str.w r8, [sp] */
/* @0x2b2068 strmi r8, [r2], -r0 */
/* @0x2b206a mov r2, r0 */
/* @0x2b206c mov r0, r4 */
/* @0x2b206e bl 0x2b0f3c <png_do_write_intrapixel+0x86> */
/* @0x2b2070 ldcne p15, c15, [r10], #404 */
/* @0x2b2072 adds r2, r7, #0x2 */
/* @0x2b2074 add r1, sp, #0x14 */
/* @0x2b2076 add r2, r0 */
/* @0x2b2078 mov r0, r4 */
/* @0x2b207a bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b207c ldclne p8, c15, [r10], #-580 */
/* @0x2b207e adds r2, r7, #0x1 */
/* @0x2b2080 mov r0, r4 */
/* @0x2b2082 ldr r1, [sp, #0x10] */
/* @0x2b2084 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b2088 mov r0, r4 */
/* @0x2b208a ldr r1, [sp, #0x10] */
/* @0x2b208c bl 0x2a6cfc <png_free> */
/* @0x2b2090 add r1, sp, #0x30 */
/* @0x2b2092 mov r0, r4 */
/* @0x2b2094 movs r2, #0x1 */
/* @0x2b2096 strb r6, [r1, #-36]! */
/* @0x2b2098 .word 0xf7ff6d24 */
/* @0x2b209a bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b209c .word 0x4620f8b3 */
/* @0x2b209e mov r0, r4 */
/* @0x2b20a0 mov r1, r8 */
/* @0x2b20a2 bl 0x2b1226 <png_write_chunk_data+0x22> */
/* @0x2b20a4 strtmi pc, [r0], -r0, asr #17 */
/* @0x2b20a6 mov r0, r4 */
/* @0x2b20a8 bl 0x2b1296 <png_write_chunk_end> */
/* @0x2b20ac add sp, #0x30 */
/* @0x2b20ae pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2b20b0 svclt #0x81f0 */
/* @0x2b20b2 nop */
/* @0x2b20b4 ble 0x2b2164 <png_write_iTXt+0xac> */
/* @0x2b20b6 movs r5, r1 */

/* ── FUNC 0x2b20b8 · png_write_iTXt · size=288 · insn=131 */
/* @0x2b20b8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b20bc mov r4, r0 */
/* @0x2b20be ldr r6, [pc, #0x110] */
/* @0x2b20c0 sub sp, #0x34 */
/* @0x2b20c2 mov r8, r3 */
/* @0x2b20c4 mov r9, r1 */
/* @0x2b20c6 add r6, pc */
/* @0x2b20c8 mov r1, r2 */
/* @0x2b20ca add r2, sp, #0x10 */
/* @0x2b20cc ldr r5, [sp, #0x58] */
/* @0x2b20ce ldr r0, [r6, #83]! */
/* @0x2b20d0 svcls #0x170f53 */
/* @0x2b20d2 ldr r7, [sp, #0x5c] */
/* @0x2b20d4 ldrb r3, [r6, #0x4] */
/* @0x2b20d6 movs r6, #0x0 */
/* @0x2b20d8 str r0, [sp, #0x14] */
/* @0x2b20da mov r0, r4 */
/* @0x2b20dc str r6, [sp, #0x10] */
/* @0x2b20de strb.w r3, [sp, #0x18] */
/* @0x2b20e0 .word 0x96093018 */
/* @0x2b20e2 str r6, [sp, #0x24] */
/* @0x2b20e4 str r6, [sp, #0x28] */
/* @0x2b20e6 str r6, [sp, #0x2c] */
/* @0x2b20e8 str r6, [sp, #0x1c] */
/* @0x2b20ea bl 0x2af5b0 <png_check_keyword> */
/* @0x2b20ec strmi pc, [r2], r1, ror #20 */
/* @0x2b20ee mov r10, r0 */
/* @0x2b20f0 cmp r0, #0x0 */
/* @0x2b20f2 beq 0x2b21ca <png_write_iTXt+0x112> */
/* @0x2b20f4 mov r0, r4 */
/* @0x2b20f6 mov r1, r8 */
/* @0x2b20f8 add r2, sp, #0xc */
/* @0x2b20fa bl 0x2af5b0 <png_check_keyword> */
/* @0x2b20fc .word 0x4606fa59 */
/* @0x2b20fe mov r6, r0 */
/* @0x2b2100 cbnz r0, 0x2b210e <png_write_iTXt+0x56> */
/* @0x2b2102 ldr r1, [pc, #0xd0] */
/* @0x2b2104 mov r0, r4 */
/* @0x2b2106 add r1, pc */
/* @0x2b2108 bl 0x2a6474 <png_warning> */
/* @0x2b210c str r6, [sp, #0xc] */
/* @0x2b210e cbz r5, 0x2b211a <png_write_iTXt+0x62> */
/* @0x2b2110 mov r0, r5 */
/* @0x2b2112 blx 0xb6538 <strlen@plt> */
/* @0x2b2114 pkhbtmi lr, r0, r2, lsl #20 */
/* @0x2b2116 mov r8, r0 */
/* @0x2b2118 b 0x2b211c <png_write_iTXt+0x64> */
/* @0x2b211a mov r8, r5 */
/* @0x2b211c cbz r7, 0x2b2128 <png_write_iTXt+0x70> */
/* @0x2b211e mov r0, r7 */
/* @0x2b2120 blx 0xb6538 <strlen@plt> */
/* @0x2b2124 mov r2, r0 */
/* @0x2b2126 b 0x2b212a <png_write_iTXt+0x72> */
/* @0x2b2128 mov r2, r7 */
/* @0x2b212a sub.w r3, r9, #0x2 */
/* @0x2b212c ldrtmi r0, [r9], -r2, lsl #6 */
/* @0x2b212e mov r1, r7 */
/* @0x2b2130 add.w r11, sp, #0x1c */
/* @0x2b2134 mov r0, r4 */
/* @0x2b2136 str.w r11, [sp] */
/* @0x2b2138 .word 0xf7feb000 */
/* @0x2b213a bl 0x2b0f3c <png_do_write_intrapixel+0x86> */
/* @0x2b213c .word 0xf10afeff */
/* @0x2b213e add.w r2, r10, #0x5 */
/* @0x2b2140 ldrtmi r0, [r2], #-517 */
/* @0x2b2142 add r2, r6 */
/* @0x2b2144 add r1, sp, #0x14 */
/* @0x2b2146 add r2, r8 */
/* @0x2b2148 add r2, r0 */
/* @0x2b214a mov r0, r4 */
/* @0x2b214c bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b2150 mov r0, r4 */
/* @0x2b2152 ldr r1, [sp, #0x10] */
/* @0x2b2154 add.w r2, r10, #0x1 */
/* @0x2b2158 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b215c cmp.w r9, #0x1 */
/* @0x2b2160 beq 0x2b2168 <png_write_iTXt+0xb0> */
/* @0x2b2162 cmp.w r9, #0xffffffff */
/* @0x2b2164 strdle r3, r4, [r1, -pc] */
/* @0x2b2166 bne 0x2b216c <png_write_iTXt+0xb4> */
/* @0x2b2168 movs r3, #0x0 */
/* @0x2b216a b 0x2b216e <png_write_iTXt+0xb6> */
/* @0x2b216c movs r3, #0x1 */
/* @0x2b216e add r7, sp, #0x8 */
/* @0x2b2170 mov r0, r4 */
/* @0x2b2172 movs r2, #0x2 */
/* @0x2b2174 strb.w r3, [sp, #0x8] */
/* @0x2b2178 mov r1, r7 */
/* @0x2b217a mov.w r9, #0x0 */
/* @0x2b217c .word 0xf88d0900 */
/* @0x2b217e strb.w r9, [sp, #0x9] */
/* @0x2b2180 .word 0xf7ff9009 */
/* @0x2b2182 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b2184 stmdbls r3, {r0, r1, r2, r3, r4, r5, r11, r12, sp, lr, pc} */
/* @0x2b2186 ldr r1, [sp, #0xc] */
/* @0x2b2188 mov r0, r4 */
/* @0x2b218a adds r2, r6, #0x1 */
/* @0x2b218c strb.w r9, [sp, #0x8] */
/* @0x2b2190 cmp r1, r9 */
/* @0x2b2192 it eq */
/* @0x2b2194 moveq r1, r7 */
/* @0x2b2196 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b2198 .word 0xf108f835 */
/* @0x2b219a add.w r2, r8, #0x1 */
/* @0x2b219c strtmi r0, [r0], -r1, lsl #4 */
/* @0x2b219e mov r0, r4 */
/* @0x2b21a0 cmp r5, r9 */
/* @0x2b21a2 ite ne */
/* @0x2b21a4 movne r1, r5 */
/* @0x2b21a6 moveq r1, r7 */
/* @0x2b21a8 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b21ac mov r1, r11 */
/* @0x2b21ae mov r0, r4 */
/* @0x2b21b0 bl 0x2b1226 <png_write_chunk_data+0x22> */
/* @0x2b21b4 mov r0, r4 */
/* @0x2b21b6 bl 0x2b1296 <png_write_chunk_end> */
/* @0x2b21b8 strtmi pc, [r0], -lr, ror #16 */
/* @0x2b21ba mov r0, r4 */
/* @0x2b21bc ldr r1, [sp, #0x10] */
/* @0x2b21be bl 0x2a6cfc <png_free> */
/* @0x2b21c0 qadd8mi pc, r0, sp */
/* @0x2b21c2 mov r0, r4 */
/* @0x2b21c4 ldr r1, [sp, #0xc] */
/* @0x2b21c6 bl 0x2a6cfc <png_free> */
/* @0x2b21c8 mullt sp, r9, sp */
/* @0x2b21ca add sp, #0x34 */
/* @0x2b21cc pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b21d0 bgt 0x2b2108 <png_write_iTXt+0x50> */
/* @0x2b21d2 movs r5, r1 */
/* @0x2b21d4 stm r5!, {r1, r2, r4, r5} */
/* @0x2b21d6 movs r5, r1 */

/* ── FUNC 0x2b21d8 · png_write_oFFs · size=120 · insn=53 */
/* @0x2b21d8 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b21dc mov r7, r3 */
/* @0x2b21de ldr r4, [pc, #0x64] */
/* @0x2b21e0 mov r6, r0 */
/* @0x2b21e2 ldr r5, [pc, #0x64] */
/* @0x2b21e4 sub sp, #0x1c */
/* @0x2b21e6 add r4, pc */
/* @0x2b21e8 ldr r4, [r4] */
/* @0x2b21ea cmp r7, #0x1 */
/* @0x2b21ec add r5, pc */
/* @0x2b21ee mov r9, r1 */
/* @0x2b21f0 ldr r3, [r4] */
/* @0x2b21f2 mov r8, r2 */
/* @0x2b21f4 ldr r0, [r5, #88]! */
/* @0x2b21f8 str r3, [sp, #0x14] */
/* @0x2b21fa ldrb r3, [r5, #0x4] */
/* @0x2b21fc str r0, [sp] */
/* @0x2b21fe strb.w r3, [sp, #0x4] */
/* @0x2b2200 stcle p0, c3, [r4, #-16] */
/* @0x2b2202 ble 0x2b220e <png_write_oFFs+0x36> */
/* @0x2b2204 ldr r1, [pc, #0x44] */
/* @0x2b2206 mov r0, r6 */
/* @0x2b2208 add r1, pc */
/* @0x2b220a bl 0x2a6474 <png_warning> */
/* @0x2b220c stcge p9, c15, [r2, #-204] */
/* @0x2b220e add r5, sp, #0x8 */
/* @0x2b2210 mov r1, r9 */
/* @0x2b2212 mov r0, r5 */
/* @0x2b2214 bl 0x2b1134 <png_save_int_32> */
/* @0x2b2218 adds r0, r5, #0x4 */
/* @0x2b221a mov r1, r8 */
/* @0x2b221c bl 0x2b1134 <png_save_int_32> */
/* @0x2b2220 mov r2, r5 */
/* @0x2b2222 movs r3, #0x9 */
/* @0x2b2224 mov r0, r6 */
/* @0x2b2226 mov r1, sp */
/* @0x2b2228 strb.w r7, [sp, #0x10] */
/* @0x2b222c bl 0x2b12bc <png_write_chunk> */
/* @0x2b2230 ldr r2, [sp, #0x14] */
/* @0x2b2232 ldr r3, [r4] */
/* @0x2b2234 cmp r2, r3 */
/* @0x2b2236 beq 0x2b223c <png_write_oFFs+0x64> */
/* @0x2b2238 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b223c add sp, #0x1c */
/* @0x2b223e pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b2240 svclt #0x83f0 */
/* @0x2b2242 nop */
/* @0x2b2244 .word 0xb76e */
/* @0x2b2246 movs r3, r2 */
/* @0x2b2248 blt 0x2b2334 <png_write_pCAL+0xe4> */
/* @0x2b224a movs r5, r1 */
/* @0x2b224c stm r4!, {r0, r1, r2, r4, r6} */
/* @0x2b224e movs r5, r1 */

/* ── FUNC 0x2b2250 · png_write_pCAL · size=308 · insn=135 */
/* @0x2b2250 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b2254 sub sp, #0x3c */
/* @0x2b2256 mov r4, r0 */
/* @0x2b2258 mov r6, r1 */
/* @0x2b225a str r3, [sp, #0x10] */
/* @0x2b225c ldr r3, [pc, #0x118] */
/* @0x2b225e str r2, [sp, #0xc] */
/* @0x2b2260 add r3, pc */
/* @0x2b2262 ldr r3, [r3] */
/* @0x2b2264 ldr r1, [sp, #0x60] */
/* @0x2b2266 ldr r5, [sp, #0x64] */
/* @0x2b2268 ldr r2, [r3] */
/* @0x2b226a cmp r1, #0x3 */
/* @0x2b226c ldr.w r9, [sp, #0x68] */
/* @0x2b2270 ldr r7, [sp, #0x6c] */
/* @0x2b2272 str r2, [sp, #0x34] */
/* @0x2b2274 ldr r2, [pc, #0x104] */
/* @0x2b2276 str r3, [sp, #0x14] */
/* @0x2b2278 add r2, pc */
/* @0x2b227a ldr r0, [r2, #93]! */
/* @0x2b227c ldmdbvc r2, {r0, r2, r3, r4, r6, r8, r9, r10, r11} */
/* @0x2b227e ldrb r2, [r2, #0x4] */
/* @0x2b2280 str r0, [sp, #0x20] */
/* @0x2b2282 strb.w r2, [sp, #0x24] */
/* @0x2b2284 stcle p0, c2, [r4, #-144] */
/* @0x2b2286 ble 0x2b2292 <png_write_pCAL+0x42> */
/* @0x2b2288 ldr r1, [pc, #0xf4] */
/* @0x2b228a mov r0, r4 */
/* @0x2b228c add r1, pc */
/* @0x2b228e bl 0x2a6474 <png_warning> */
/* @0x2b2290 shsub8mi pc, r1, r1 */
/* @0x2b2292 mov r1, r6 */
/* @0x2b2294 add r2, sp, #0x1c */
/* @0x2b2296 mov r0, r4 */
/* @0x2b2298 bl 0x2af5b0 <png_check_keyword> */
/* @0x2b229c add.w r10, r0, #0x1 */
/* @0x2b22a0 mov r0, r9 */
/* @0x2b22a2 blx 0xb6538 <strlen@plt> */
/* @0x2b22a4 adceq lr, r9, r10, asr #18 */
/* @0x2b22a6 lsls r1, r5, #0x2 */
/* @0x2b22a8 cmp r5, #0x0 */
/* @0x2b22aa ite eq */
/* @0x2b22ac moveq r8, r0 */
/* @0x2b22ae addne.w r8, r0, #0x1 */
/* @0x2b22b0 strtmi r0, [r0], -r1, lsl #16 */
/* @0x2b22b2 mov r0, r4 */
/* @0x2b22b4 add.w r2, r10, r8 */
/* @0x2b22b8 add.w r11, r2, #0xa */
/* @0x2b22bc bl 0x2a6ca0 <png_malloc> */
/* @0x2b22c0 subs r1, r5, #0x1 */
/* @0x2b22c2 movs r3, #0x0 */
/* @0x2b22c4 mov r6, r0 */
/* @0x2b22c6 cmp r3, r5 */
/* @0x2b22c8 bge 0x2b22ea <png_write_pCAL+0x9a> */
/* @0x2b22ca ldr.w r0, [r7, r3, lsl #2] */
/* @0x2b22cc .word 0x91010023 */
/* @0x2b22ce str r1, [sp, #0x4] */
/* @0x2b22d0 str r3, [sp, #0x8] */
/* @0x2b22d2 blx 0xb6538 <strlen@plt> */
/* @0x2b22d4 blls 0x36c7a4 <_ZTS13C_UTF16String+0x3850> */
/* @0x2b22d6 ldr r3, [sp, #0x8] */
/* @0x2b22d8 ldr r1, [sp, #0x4] */
/* @0x2b22da cmp r3, r1 */
/* @0x2b22dc it ne */
/* @0x2b22de addne r0, #0x1 */
/* @0x2b22e0 str.w r0, [r6, r3, lsl #2] */
/* @0x2b22e4 add r11, r0 */
/* @0x2b22e6 adds r3, #0x1 */
/* @0x2b22e8 b 0x2b22c6 <png_write_pCAL+0x76> */
/* @0x2b22ea mov r0, r4 */
/* @0x2b22ec add r1, sp, #0x20 */
/* @0x2b22ee mov r2, r11 */
/* @0x2b22f0 bl 0x2b11a0 <png_write_chunk_start> */
/* @0x2b22f4 mov r2, r10 */
/* @0x2b22f6 add.w r10, sp, #0x28 */
/* @0x2b22f8 strtmi r0, [r0], -r8, lsr #20 */
/* @0x2b22fa mov r0, r4 */
/* @0x2b22fc ldr r1, [sp, #0x1c] */
/* @0x2b22fe bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b2300 ldrbmi pc, [r0], -r1, lsl #31 */
/* @0x2b2302 mov r0, r10 */
/* @0x2b2304 ldr r1, [sp, #0xc] */
/* @0x2b2306 bl 0x2b1134 <png_save_int_32> */
/* @0x2b2308 .word 0xf10aff15 */
/* @0x2b230a add.w r0, r10, #0x4 */
/* @0x2b230c stmdbls r4, {r2} */
/* @0x2b230e ldr r1, [sp, #0x10] */
/* @0x2b2310 bl 0x2b1134 <png_save_int_32> */
/* @0x2b2314 ldr r3, [sp, #0x60] */
/* @0x2b2316 mov r0, r4 */
/* @0x2b2318 mov r1, r10 */
/* @0x2b231a movs r2, #0xa */
/* @0x2b231c strb.w r5, [sp, #0x31] */
/* @0x2b2320 strb.w r3, [sp, #0x30] */
/* @0x2b2324 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b2328 mov r2, r8 */
/* @0x2b232a mov r0, r4 */
/* @0x2b232c mov r1, r9 */
/* @0x2b232e mov.w r8, #0x0 */
/* @0x2b2330 .word 0xf7fe0800 */
/* @0x2b2332 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b2334 strtmi pc, [r0], -r7, ror #30 */
/* @0x2b2336 mov r0, r4 */
/* @0x2b2338 ldr r1, [sp, #0x1c] */
/* @0x2b233a bl 0x2a6cfc <png_free> */
/* @0x2b233c strmi pc, [r8, #0xcdf]! */
/* @0x2b233e cmp r8, r5 */
/* @0x2b2340 mov r0, r4 */
/* @0x2b2342 bge 0x2b2356 <png_write_pCAL+0x106> */
/* @0x2b2344 ldr.w r1, [r7, r8, lsl #2] */
/* @0x2b2348 ldr.w r2, [r6, r8, lsl #2] */
/* @0x2b234c add.w r8, r8, #0x1 */
/* @0x2b2350 bl 0x2b1204 <png_write_chunk_data> */
/* @0x2b2354 b 0x2b233e <png_write_pCAL+0xee> */
/* @0x2b2356 mov r1, r6 */
/* @0x2b2358 bl 0x2a6cfc <png_free> */
/* @0x2b235c mov r0, r4 */
/* @0x2b235e bl 0x2b1296 <png_write_chunk_end> */
/* @0x2b2360 stmdbls r5, {r1, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b2362 ldr r1, [sp, #0x14] */
/* @0x2b2364 ldr r2, [sp, #0x34] */
/* @0x2b2366 ldr r3, [r1] */
/* @0x2b2368 cmp r2, r3 */
/* @0x2b236a beq 0x2b2370 <png_write_pCAL+0x120> */
/* @0x2b236c blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b2370 add sp, #0x3c */
/* @0x2b2372 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b2374 svclt #0x8ff0 */
/* @0x2b2376 nop */
/* @0x2b2378 .word 0xb6f4 */
/* @0x2b237a movs r3, r2 */
/* @0x2b237c bge 0x2b2350 <png_write_pCAL+0x100> */
/* @0x2b237e movs r5, r1 */
/* @0x2b2380 cbz r2, 0x2b23ca <png_write_sCAL+0x46> */
/* @0x2b2382 movs r5, r1 */

/* ── FUNC 0x2b2384 · png_write_sCAL · size=148 · insn=63 */
/* @0x2b2384 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b2388 mov r10, r0 */
/* @0x2b238a ldr r7, [pc, #0x80] */
/* @0x2b238c sub sp, #0x5c */
/* @0x2b238e ldr r4, [pc, #0x80] */
/* @0x2b2390 add r6, sp, #0x58 */
/* @0x2b2392 add r7, pc */
/* @0x2b2394 ldr r7, [r7] */
/* @0x2b2396 ldr.w r11, [pc, #0x7c] */
/* @0x2b2398 ldrbtmi r11, [r12], #-124 */
/* @0x2b239a add r4, pc */
/* @0x2b239c strb r1, [r6, #-68]! */
/* @0x2b23a0 ldr r0, [r7] */
/* @0x2b23a2 add r11, pc */
/* @0x2b23a4 strd r2, r3, [sp] */
/* @0x2b23a8 movs r1, #0x3f */
/* @0x2b23aa mov r2, r11 */
/* @0x2b23ac str r0, [sp, #0x54] */
/* @0x2b23ae ldr r0, [r4, #98]! */
/* @0x2b23b0 andls r0, r3, r2, ror #30 */
/* @0x2b23b2 str r0, [sp, #0xc] */
/* @0x2b23b4 ldrb r0, [r4, #0x4] */
/* @0x2b23b6 adds r4, r6, #0x1 */
/* @0x2b23b8 strb.w r0, [sp, #0x10] */
/* @0x2b23bc mov r0, r4 */
/* @0x2b23be blx 0xb65c8 <snprintf@plt> */
/* @0x2b23c0 strtmi lr, [r0], -r4, lsl #18 */
/* @0x2b23c2 mov r0, r4 */
/* @0x2b23c4 blx 0xb6538 <strlen@plt> */
/* @0x2b23c8 ldrd r4, r5, [sp, #128] */
/* @0x2b23cc mov r2, r11 */
/* @0x2b23ce strd r4, r5, [sp] */
/* @0x2b23d0 .word 0xf1004500 */
/* @0x2b23d2 add.w r8, r0, #0x2 */
/* @0x2b23d4 strmi r0, [r1], -r2, lsl #16 */
/* @0x2b23d6 mov r1, r0 */
/* @0x2b23d8 add.w r9, r6, r8 */
/* @0x2b23dc rsb.w r1, r1, #0x3e */
/* @0x2b23e0 mov r0, r9 */
/* @0x2b23e2 blx 0xb65c8 <snprintf@plt> */
/* @0x2b23e4 .word 0x4648e8f2 */
/* @0x2b23e6 mov r0, r9 */
/* @0x2b23e8 blx 0xb6538 <strlen@plt> */
/* @0x2b23ec mov r2, r6 */
/* @0x2b23ee add r1, sp, #0xc */
/* @0x2b23f0 add.w r3, r8, r0 */
/* @0x2b23f4 mov r0, r10 */
/* @0x2b23f6 bl 0x2b12bc <png_write_chunk> */
/* @0x2b23f8 bls 0x832184 <b2_toiTime+0xd8ce0> */
/* @0x2b23fa ldr r2, [sp, #0x54] */
/* @0x2b23fc ldr r3, [r7] */
/* @0x2b23fe cmp r2, r3 */
/* @0x2b2400 beq 0x2b2406 <png_write_sCAL+0x82> */
/* @0x2b2402 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b2404 andslt lr, r7, r8, ror #17 */
/* @0x2b2406 add sp, #0x5c */
/* @0x2b2408 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b240c push {r1, r6, r7, lr} */
/* @0x2b240e movs r3, r2 */
/* @0x2b2410 bls 0x2b23a0 <png_write_sCAL+0x1c> */
/* @0x2b2412 movs r5, r1 */
/* @0x2b2414 stm r2!, {r0, r1, r5, r6, r7} */
/* @0x2b2416 movs r5, r1 */

/* ── FUNC 0x2b2418 · png_write_pHYs · size=120 · insn=53 */
/* @0x2b2418 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b241c mov r7, r3 */
/* @0x2b241e ldr r4, [pc, #0x64] */
/* @0x2b2420 mov r6, r0 */
/* @0x2b2422 ldr r5, [pc, #0x64] */
/* @0x2b2424 sub sp, #0x1c */
/* @0x2b2426 add r4, pc */
/* @0x2b2428 ldr r4, [r4] */
/* @0x2b242a cmp r7, #0x1 */
/* @0x2b242c add r5, pc */
/* @0x2b242e mov r9, r1 */
/* @0x2b2430 ldr r3, [r4] */
/* @0x2b2432 mov r8, r2 */
/* @0x2b2434 ldr r0, [r5, #103]! */
/* @0x2b2438 str r3, [sp, #0x14] */
/* @0x2b243a ldrb r3, [r5, #0x4] */
/* @0x2b243c str r0, [sp] */
/* @0x2b243e strb.w r3, [sp, #0x4] */
/* @0x2b2440 stcle p0, c3, [r4, #-16] */
/* @0x2b2442 ble 0x2b244e <png_write_pHYs+0x36> */
/* @0x2b2444 ldr r1, [pc, #0x44] */
/* @0x2b2446 mov r0, r6 */
/* @0x2b2448 add r1, pc */
/* @0x2b244a bl 0x2a6474 <png_warning> */
/* @0x2b244c stcge p8, c15, [r2, #-76] */
/* @0x2b244e add r5, sp, #0x8 */
/* @0x2b2450 mov r1, r9 */
/* @0x2b2452 mov r0, r5 */
/* @0x2b2454 bl 0x2b1124 <png_save_uint_32> */
/* @0x2b2458 adds r0, r5, #0x4 */
/* @0x2b245a mov r1, r8 */
/* @0x2b245c bl 0x2b1124 <png_save_uint_32> */
/* @0x2b2460 mov r2, r5 */
/* @0x2b2462 movs r3, #0x9 */
/* @0x2b2464 mov r0, r6 */
/* @0x2b2466 mov r1, sp */
/* @0x2b2468 strb.w r7, [sp, #0x10] */
/* @0x2b246c bl 0x2b12bc <png_write_chunk> */
/* @0x2b2470 ldr r2, [sp, #0x14] */
/* @0x2b2472 ldr r3, [r4] */
/* @0x2b2474 cmp r2, r3 */
/* @0x2b2476 beq 0x2b247c <png_write_pHYs+0x64> */
/* @0x2b2478 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b247c add sp, #0x1c */
/* @0x2b247e pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b2480 svclt #0x83f0 */
/* @0x2b2482 nop */
/* @0x2b2484 push {r1, r2, r3, r5, lr} */
/* @0x2b2486 movs r3, r2 */
/* @0x2b2488 bls 0x2b24f4 <png_write_tIME+0x64> */
/* @0x2b248a movs r5, r1 */
/* @0x2b248c stm r2!, {r0, r2, r6} */
/* @0x2b248e movs r5, r1 */

/* ── FUNC 0x2b2490 · png_write_tIME · size=128 · insn=59 */
/* @0x2b2490 push {r0, r1, r2, r3, r4, r5, r6, lr} */
/* @0x2b2492 mov r6, r0 */
/* @0x2b2494 ldr r3, [pc, #0x70] */
/* @0x2b2496 mov r4, r1 */
/* @0x2b2498 add r3, pc */
/* @0x2b249a ldr r0, [r3, #108]! */
/* @0x2b249c ldmdbvc r11, {r2, r3, r5, r6, r8, r9, r10, r11} */
/* @0x2b249e ldrb r3, [r3, #0x4] */
/* @0x2b24a0 str r0, [sp] */
/* @0x2b24a2 strb.w r3, [sp, #0x4] */
/* @0x2b24a4 stmvc r11, {r2, r12, sp} */
/* @0x2b24a6 ldrb r3, [r1, #0x2] */
/* @0x2b24a8 subs r3, #0x1 */
/* @0x2b24aa cmp r3, #0xb */
/* @0x2b24ac bhi 0x2b24c2 <png_write_tIME+0x32> */
/* @0x2b24ae ldrb r3, [r1, #0x3] */
/* @0x2b24b0 subs r3, #0x1 */
/* @0x2b24b2 cmp r3, #0x1e */
/* @0x2b24b4 bhi 0x2b24c2 <png_write_tIME+0x32> */
/* @0x2b24b6 ldrb r3, [r1, #0x4] */
/* @0x2b24b8 cmp r3, #0x17 */
/* @0x2b24ba bhi 0x2b24c2 <png_write_tIME+0x32> */
/* @0x2b24bc ldrb r3, [r1, #0x6] */
/* @0x2b24be cmp r3, #0x3c */
/* @0x2b24c0 bls 0x2b24ce <png_write_tIME+0x3e> */
/* @0x2b24c2 ldr r1, [pc, #0x48] */
/* @0x2b24c4 mov r0, r6 */
/* @0x2b24c6 add r1, pc */
/* @0x2b24c8 bl 0x2a6474 <png_warning> */
/* @0x2b24cc b 0x2b2502 <png_write_tIME+0x72> */
/* @0x2b24ce add r5, sp, #0x8 */
/* @0x2b24d0 ldrh r1, [r1] */
/* @0x2b24d2 mov r0, r5 */
/* @0x2b24d4 bl 0x2b1138 <png_save_uint_16> */
/* @0x2b24d8 ldrb r3, [r4, #0x2] */
/* @0x2b24da mov r0, r6 */
/* @0x2b24dc mov r1, sp */
/* @0x2b24de mov r2, r5 */
/* @0x2b24e0 strb.w r3, [sp, #0xa] */
/* @0x2b24e4 ldrb r3, [r4, #0x3] */
/* @0x2b24e6 strb.w r3, [sp, #0xb] */
/* @0x2b24e8 stmdbvc r3!, {r0, r1, r3, r12, sp} */
/* @0x2b24ea ldrb r3, [r4, #0x4] */
/* @0x2b24ec strb.w r3, [sp, #0xc] */
/* @0x2b24f0 ldrb r3, [r4, #0x5] */
/* @0x2b24f2 strb.w r3, [sp, #0xd] */
/* @0x2b24f4 stmibvc r3!, {r0, r2, r3, r12, sp} */
/* @0x2b24f6 ldrb r3, [r4, #0x6] */
/* @0x2b24f8 strb.w r3, [sp, #0xe] */
/* @0x2b24fc movs r3, #0x7 */
/* @0x2b24fe bl 0x2b12bc <png_write_chunk> */
/* @0x2b2500 .word 0xb004fedd */
/* @0x2b2502 add sp, #0x10 */
/* @0x2b2504 pop {r4, r5, r6, pc} */
/* @0x2b2506 nop */
/* @0x2b2508 bhi 0x2b249c <png_write_tIME+0xc> */
/* @0x2b250a movs r5, r1 */
/* @0x2b250c stm r1!, {r0, r2, r3, r5, r6, r7} */
/* @0x2b250e movs r5, r1 */

/* ── FUNC 0x2b2510 · png_write_start_row · size=252 · insn=110 */
/* @0x2b2510 push {r3, r4, r5, lr} */
/* @0x2b2512 mov r4, r0 */
/* @0x2b2514 ldrb.w r5, [r0, #0x1ef] */
/* @0x2b2518 ldrb.w r3, [r0, #0x1ec] */
/* @0x2b251c ldr.w r2, [r0, #0x18c] */
/* @0x2b2520 smulbb r3, r5, r3 */
/* @0x2b2524 cmp r3, #0x7 */
/* @0x2b2526 ble 0x2b252e <png_write_start_row+0x1e> */
/* @0x2b2528 lsrs r5, r3, #0x3 */
/* @0x2b252a muls r5, r2, r5 */
/* @0x2b252c b 0x2b2536 <png_write_start_row+0x26> */
/* @0x2b252e mul r5, r2, r3 */
/* @0x2b2530 strlo pc, [r7, #-0x503] */
/* @0x2b2532 adds r5, #0x7 */
/* @0x2b2534 lsrs r5, r5, #0x3 */
/* @0x2b2536 adds r5, #0x1 */
/* @0x2b2538 mov r0, r4 */
/* @0x2b253a mov r1, r5 */
/* @0x2b253c bl 0x2a6ca0 <png_malloc> */
/* @0x2b2540 movs r3, #0x0 */
/* @0x2b2542 str.w r0, [r4, #0x1b0] */
/* @0x2b2544 strhvc r0, [r3], -r0 */
/* @0x2b2546 strb r3, [r0] */
/* @0x2b2548 ldrb.w r3, [r4, #0x1e9] */
/* @0x2b254c lsls r3, r3, #0x1b */
/* @0x2b254e bpl 0x2b2564 <png_write_start_row+0x54> */
/* @0x2b2550 ldr.w r1, [r4, #0x19c] */
/* @0x2b2554 mov r0, r4 */
/* @0x2b2556 adds r1, #0x1 */
/* @0x2b2558 bl 0x2a6ca0 <png_malloc> */
/* @0x2b255c movs r3, #0x1 */
/* @0x2b255e str.w r0, [r4, #0x1b4] */
/* @0x2b2560 strhvc r0, [r3], -r4 */
/* @0x2b2562 strb r3, [r0] */
/* @0x2b2564 ldrb.w r3, [r4, #0x1e9] */
/* @0x2b2568 tst.w r3, #0xe0 */
/* @0x2b256c beq 0x2b25ce <png_write_start_row+0xbe> */
/* @0x2b256e mov r1, r5 */
/* @0x2b2570 mov r0, r4 */
/* @0x2b2572 bl 0x2a6cd8 <png_calloc> */
/* @0x2b2574 .word 0xf894fbb1 */
/* @0x2b2576 ldrb.w r3, [r4, #0x1e9] */
/* @0x2b2578 ldreq r3, [sp], r9, ror #3 */
/* @0x2b257a lsls r5, r3, #0x1a */
/* @0x2b257c str.w r0, [r4, #0x1ac] */
/* @0x2b2580 bpl 0x2b2596 <png_write_start_row+0x86> */
/* @0x2b2582 ldr.w r1, [r4, #0x19c] */
/* @0x2b2584 qadd8mi r1, r0, r12 */
/* @0x2b2586 mov r0, r4 */
/* @0x2b2588 adds r1, #0x1 */
/* @0x2b258a bl 0x2a6ca0 <png_malloc> */
/* @0x2b258c movwhs pc, #0x2b89 */
/* @0x2b258e movs r3, #0x2 */
/* @0x2b2590 str.w r0, [r4, #0x1b8] */
/* @0x2b2594 strb r3, [r0] */
/* @0x2b2596 ldrb.w r3, [r4, #0x1e9] */
/* @0x2b2598 ldrbeq r3, [r8], -r9, ror #3 */
/* @0x2b259a lsls r0, r3, #0x19 */
/* @0x2b259c bpl 0x2b25b2 <png_write_start_row+0xa2> */
/* @0x2b259e ldr.w r1, [r4, #0x19c] */
/* @0x2b25a0 qadd8mi r1, r0, r12 */
/* @0x2b25a2 mov r0, r4 */
/* @0x2b25a4 adds r1, #0x1 */
/* @0x2b25a6 bl 0x2a6ca0 <png_malloc> */
/* @0x2b25a8 movwhs pc, #0x3b7b */
/* @0x2b25aa movs r3, #0x3 */
/* @0x2b25ac str.w r0, [r4, #0x1bc] */
/* @0x2b25b0 strb r3, [r0] */
/* @0x2b25b2 ldrsb.w r3, [r4, #0x1e9] */
/* @0x2b25b4 blhs 0x2bed60 <jpeg_huff_decode+0x1d4> */
/* @0x2b25b6 cmp r3, #0x0 */
/* @0x2b25b8 bge 0x2b25ce <png_write_start_row+0xbe> */
/* @0x2b25ba ldr.w r1, [r4, #0x19c] */
/* @0x2b25bc qadd8mi r1, r0, r12 */
/* @0x2b25be mov r0, r4 */
/* @0x2b25c0 adds r1, #0x1 */
/* @0x2b25c2 bl 0x2a6ca0 <png_malloc> */
/* @0x2b25c4 movwhs pc, #0x4b6d */
/* @0x2b25c6 movs r3, #0x4 */
/* @0x2b25c8 str.w r0, [r4, #0x1c0] */
/* @0x2b25cc strb r3, [r0] */
/* @0x2b25ce ldrb.w r1, [r4, #0x1e7] */
/* @0x2b25d0 .word 0xf8d411e7 */
/* @0x2b25d2 ldr.w r3, [r4, #0x18c] */
/* @0x2b25d4 .word 0xf8d4318c */
/* @0x2b25d6 ldr.w r2, [r4, #0x190] */
/* @0x2b25d8 .word 0xb1512190 */
/* @0x2b25da cbz r1, 0x2b25f2 <png_write_start_row+0xe2> */
/* @0x2b25dc ldr.w r1, [r4, #0x134] */
/* @0x2b25e0 lsls r1, r1, #0x1e */
/* @0x2b25e2 bmi 0x2b25f2 <png_write_start_row+0xe2> */
/* @0x2b25e4 adds r2, #0x7 */
/* @0x2b25e6 adds r3, #0x7 */
/* @0x2b25e8 lsrs r2, r2, #0x3 */
/* @0x2b25ea lsrs r3, r3, #0x3 */
/* @0x2b25ec str.w r2, [r4, #0x194] */
/* @0x2b25f0 b 0x2b25f6 <png_write_start_row+0xe6> */
/* @0x2b25f2 str.w r2, [r4, #0x194] */
/* @0x2b25f4 .word 0xf8c42194 */
/* @0x2b25f6 str.w r3, [r4, #0x198] */
/* @0x2b25f8 .word 0xf8d43198 */
/* @0x2b25fa ldr.w r3, [r4, #0x174] */
/* @0x2b25fc .word 0xf8c43174 */
/* @0x2b25fe str.w r3, [r4, #0x148] */
/* @0x2b2600 .word 0xf8d43148 */
/* @0x2b2602 ldr.w r3, [r4, #0x170] */
/* @0x2b2604 .word 0xf8c43170 */
/* @0x2b2606 str.w r3, [r4, #0x144] */
/* @0x2b2608 ldclt p1, c3, [r8, #-272]! */
/* @0x2b260a pop {r3, r4, r5, pc} */

/* ── FUNC 0x2b260c · png_write_finish_row · size=400 · insn=172 */
/* @0x2b260c push {r4, r5, r6, r7, lr} */
/* @0x2b260e mov r4, r0 */
/* @0x2b2610 ldr r6, [pc, #0x180] */
/* @0x2b2612 sub sp, #0x74 */
/* @0x2b2614 add r6, pc */
/* @0x2b2616 mov r5, sp */
/* @0x2b2618 add.w r7, r6, #0x74 */
/* @0x2b261c ldm r7!, {r0, r1, r2, r3} */
/* @0x2b261e stm r5!, {r0, r1, r2, r3} */
/* @0x2b2620 ldm.w r7, {r0, r1, r2} */
/* @0x2b2624 add.w r7, r6, #0x90 */
/* @0x2b2628 stm.w r5, {r0, r1, r2} */
/* @0x2b262c add r5, sp, #0x1c */
/* @0x2b262e ldm r7!, {r0, r1, r2, r3} */
/* @0x2b2630 stm r5!, {r0, r1, r2, r3} */
/* @0x2b2632 ldm.w r7, {r0, r1, r2} */
/* @0x2b2634 .word 0xf1060007 */
/* @0x2b2636 add.w r7, r6, #0xac */
/* @0x2b2638 strblo r0, [r8], r12, lsr #15 */
/* @0x2b263a adds r6, #0xc8 */
/* @0x2b263c stm.w r5, {r0, r1, r2} */
/* @0x2b2640 add r5, sp, #0x38 */
/* @0x2b2642 ldm r7!, {r0, r1, r2, r3} */
/* @0x2b2644 stm r5!, {r0, r1, r2, r3} */
/* @0x2b2646 ldm.w r7, {r0, r1, r2} */
/* @0x2b2648 stm r5, {r0, r1, r2} */
/* @0x2b264a stm.w r5, {r0, r1, r2} */
/* @0x2b264c ldcge p0, c0, [r5, #-28] */
/* @0x2b264e add r5, sp, #0x54 */
/* @0x2b2650 ldm r6!, {r0, r1, r2, r3} */
/* @0x2b2652 stm r5!, {r0, r1, r2, r3} */
/* @0x2b2654 ldm.w r6, {r0, r1, r2} */
/* @0x2b2658 ldr.w r3, [r4, #0x1a8] */
/* @0x2b265c adds r3, #0x1 */
/* @0x2b265e str.w r3, [r4, #0x1a8] */
/* @0x2b2660 stm r5, {r3, r5, r7, r8, r12, sp} */
/* @0x2b2662 stm.w r5, {r0, r1, r2} */
/* @0x2b2664 .word 0xf8d40007 */
/* @0x2b2666 ldr.w r2, [r4, #0x194] */
/* @0x2b2668 addsmi r2, r3, #148, #2 */
/* @0x2b266a cmp r3, r2 */
/* @0x2b266c blo.w 0x2b2790 <png_write_finish_row+0x184> */
/* @0x2b2670 ldrb.w r3, [r4, #0x1e7] */
/* @0x2b2674 cmp r3, #0x0 */
/* @0x2b2676 beq 0x2b271e <png_write_finish_row+0x112> */
/* @0x2b2678 movs r3, #0x0 */
/* @0x2b267a str.w r3, [r4, #0x1a8] */
/* @0x2b267c .word 0xf8d431a8 */
/* @0x2b267e ldr.w r3, [r4, #0x134] */
/* @0x2b2680 .word 0xf8943134 */
/* @0x2b2682 ldrb.w r5, [r4, #0x1e8] */
/* @0x2b2684 .word 0xf01351e8 */
/* @0x2b2686 tst.w r3, #0x2 */
/* @0x2b2688 eorle r0, r0, r2, lsl #30 */
/* @0x2b268a beq 0x2b26ce <png_write_finish_row+0xc2> */
/* @0x2b268c adds r5, #0x1 */
/* @0x2b268e b 0x2b26dc <png_write_finish_row+0xd0> */
/* @0x2b2690 add r3, sp, #0x70 */
/* @0x2b2692 add.w r6, r3, r5, lsl #2 */
/* @0x2b2694 .word 0xf8d40685 */
/* @0x2b2696 ldr.w r3, [r4, #0x18c] */
/* @0x2b2698 .word 0xf856318c */
/* @0x2b269a ldr r1, [r6, #-84] */
/* @0x2b269c bllo 0x2f97f4 <ps_hints_apply+0x83f4> */
/* @0x2b269e subs r3, #0x1 */
/* @0x2b26a0 adds r0, r3, r1 */
/* @0x2b26a2 ldr r3, [r6, #-112] */
/* @0x2b26a4 bne 0xff2c186c <b2_toiTime+0xfffffffffeb683c8> */
/* @0x2b26a6 subs r0, r0, r3 */
/* @0x2b26a8 blx 0x318c48 <__udivsi3> */
/* @0x2b26ac ldr.w r3, [r4, #0x190] */
/* @0x2b26b0 ldr r1, [r6, #-28] */
/* @0x2b26b4 subs r3, #0x1 */
/* @0x2b26b6 ldr r2, [r6, #-56] */
/* @0x2b26b8 .word 0xf8c42c38 */
/* @0x2b26ba str.w r0, [r4, #0x198] */
/* @0x2b26bc .word 0x46070198 */
/* @0x2b26be mov r7, r0 */
/* @0x2b26c0 adds r0, r3, r1 */
/* @0x2b26c2 subs r0, r0, r2 */
/* @0x2b26c4 blx 0x318c48 <__udivsi3> */
/* @0x2b26c8 str.w r0, [r4, #0x194] */
/* @0x2b26cc cbnz r7, 0x2b26d8 <png_write_finish_row+0xcc> */
/* @0x2b26ce adds r5, #0x1 */
/* @0x2b26d0 uxtb r5, r5 */
/* @0x2b26d2 cmp r5, #0x6 */
/* @0x2b26d4 bls 0x2b2690 <png_write_finish_row+0x84> */
/* @0x2b26d6 b 0x2b26dc <png_write_finish_row+0xd0> */
/* @0x2b26d8 cmp r0, #0x0 */
/* @0x2b26da beq 0x2b26ce <png_write_finish_row+0xc2> */
/* @0x2b26dc strb.w r5, [r4, #0x1e8] */
/* @0x2b26e0 ldrb.w r3, [r4, #0x1e8] */
/* @0x2b26e4 cmp r3, #0x6 */
/* @0x2b26e6 bhi 0x2b271e <png_write_finish_row+0x112> */
/* @0x2b26e8 ldr.w r0, [r4, #0x1ac] */
/* @0x2b26ec cmp r0, #0x0 */
/* @0x2b26ee beq 0x2b2790 <png_write_finish_row+0x184> */
/* @0x2b26f0 ldrb.w r2, [r4, #0x1ef] */
/* @0x2b26f4 ldrb.w r3, [r4, #0x1ec] */
/* @0x2b26f8 smulbb r3, r2, r3 */
/* @0x2b26fc ldr.w r2, [r4, #0x18c] */
/* @0x2b2700 cmp r3, #0x7 */
/* @0x2b2702 ble 0x2b270a <png_write_finish_row+0xfe> */
/* @0x2b2704 lsrs r3, r3, #0x3 */
/* @0x2b2706 muls r2, r3, r2 */
/* @0x2b2708 b 0x2b2710 <png_write_finish_row+0x104> */
/* @0x2b270a muls r2, r3, r2 */
/* @0x2b270c adds r2, #0x7 */
/* @0x2b270e lsrs r2, r2, #0x3 */
/* @0x2b2710 adds r2, #0x1 */
/* @0x2b2712 movs r1, #0x0 */
/* @0x2b2714 add sp, #0x74 */
/* @0x2b2716 pop.w {r4, r5, r6, r7, lr} */
/* @0x2b2718 .word 0xf06940f0 */
/* @0x2b271a b.w 0x31bacc <__udivdi3+0x434> */
/* @0x2b271c mrcmi p9, #0x0, r11, c14, c7, #0x6 */
/* @0x2b271e ldr r6, [pc, #0x78] */
/* @0x2b2720 add.w r5, r4, #0x138 */
/* @0x2b2724 add r6, pc */
/* @0x2b2726 mov r0, r5 */
/* @0x2b2728 movs r1, #0x4 */
/* @0x2b272a blx 0xb69ac <deflate@plt> */
/* @0x2b272c ldmiblt r8, {r6, r8, r11, sp, lr, pc} */
/* @0x2b272e cbnz r0, 0x2b2758 <png_write_finish_row+0x14c> */
/* @0x2b2730 ldr.w r3, [r4, #0x148] */
/* @0x2b2734 cmp r3, #0x0 */
/* @0x2b2736 bne 0x2b2726 <png_write_finish_row+0x11a> */
/* @0x2b2738 mov r0, r4 */
/* @0x2b273a ldr.w r1, [r4, #0x170] */
/* @0x2b273c .word 0xf8d41170 */
/* @0x2b273e ldr.w r2, [r4, #0x174] */
/* @0x2b2740 .word 0xf7fe2174 */
/* @0x2b2742 bl 0x2b16a0 <png_write_IDAT> */
/* @0x2b2744 .word 0xf8d4ffad */
/* @0x2b2746 ldr.w r3, [r4, #0x170] */
/* @0x2b2748 .word 0xf8c43170 */
/* @0x2b274a str.w r3, [r4, #0x144] */
/* @0x2b274c .word 0xf8d43144 */
/* @0x2b274e ldr.w r3, [r4, #0x174] */
/* @0x2b2750 .word 0xf8c43174 */
/* @0x2b2752 str.w r3, [r4, #0x148] */
/* @0x2b2754 strb r3, [r6, r8, asr #2]! */
/* @0x2b2756 b 0x2b2726 <png_write_finish_row+0x11a> */
/* @0x2b2758 cmp r0, #0x1 */
/* @0x2b275a beq 0x2b276c <png_write_finish_row+0x160> */
/* @0x2b275c ldr.w r1, [r4, #0x150] */
/* @0x2b2760 mov r0, r4 */
/* @0x2b2762 cbnz r1, 0x2b2766 <png_write_finish_row+0x15a> */
/* @0x2b2764 mov r1, r6 */
/* @0x2b2766 bl 0x2a642c <png_error> */
/* @0x2b2768 ldrb pc, [r12, r1, ror #28] */
/* @0x2b276a b 0x2b2726 <png_write_finish_row+0x11a> */
/* @0x2b276c ldr.w r3, [r4, #0x148] */
/* @0x2b2770 ldr.w r2, [r4, #0x174] */
/* @0x2b2774 cmp r3, r2 */
/* @0x2b2776 bhs 0x2b2784 <png_write_finish_row+0x178> */
/* @0x2b2778 mov r0, r4 */
/* @0x2b277a ldr.w r1, [r4, #0x170] */
/* @0x2b277c bne 0xff736d44 <b2_toiTime+0xfffffffffefdd8a0> */
/* @0x2b277e subs r2, r2, r3 */
/* @0x2b2780 bl 0x2b16a0 <png_write_IDAT> */
/* @0x2b2784 mov r0, r5 */
/* @0x2b2786 blx 0xb6f58 <deflateReset@plt> */
/* @0x2b2788 movwhs lr, #0xbe8 */
/* @0x2b278a movs r3, #0x0 */
/* @0x2b278c str.w r3, [r4, #0x164] */
/* @0x2b2790 add sp, #0x74 */
/* @0x2b2792 pop {r4, r5, r6, r7, pc} */
/* @0x2b2794 bvc 0x2b2830 <png_do_write_interlace+0x94> */
/* @0x2b2796 movs r5, r1 */
/* @0x2b2798 .word 0xb859 */
/* @0x2b279a movs r5, r1 */

/* ── FUNC 0x2b279c · png_do_write_interlace · size=416 · insn=184 */
/* @0x2b279c push.w {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b27a0 mov r12, r2 */
/* @0x2b27a2 ldr r5, [pc, #0x194] */
/* @0x2b27a4 mov r8, r0 */
/* @0x2b27a6 mov r7, r1 */
/* @0x2b27a8 sub sp, #0x38 */
/* @0x2b27aa add r5, pc */
/* @0x2b27ac cmp.w r12, #0x5 */
/* @0x2b27b0 add.w r6, r5, #0x74 */
/* @0x2b27b4 mov r4, sp */
/* @0x2b27b6 add.w r5, r5, #0x90 */
/* @0x2b27b8 mcrgt p5, #0x0, r0, c15, c0, #0x4 */
/* @0x2b27ba ldm r6!, {r0, r1, r2, r3} */
/* @0x2b27bc stm r4!, {r0, r1, r2, r3} */
/* @0x2b27be ldm.w r6, {r0, r1, r2} */
/* @0x2b27c0 stm r4, {r0, r1, r2} */
/* @0x2b27c2 stm.w r4, {r0, r1, r2} */
/* @0x2b27c4 .word 0xac070007 */
/* @0x2b27c6 add r4, sp, #0x1c */
/* @0x2b27c8 ldm r5!, {r0, r1, r2, r3} */
/* @0x2b27ca stm r4!, {r0, r1, r2, r3} */
/* @0x2b27cc ldm.w r5, {r0, r1, r2} */
/* @0x2b27d0 stm.w r4, {r0, r1, r2} */
/* @0x2b27d4 bgt.w 0x2b2930 <png_do_write_interlace+0x194> */
/* @0x2b27d8 ldrb.w r3, [r8, #0xb] */
/* @0x2b27dc lsl.w r4, r12, #0x2 */
/* @0x2b27e0 ldr.w r5, [r8] */
/* @0x2b27e4 cmp r3, #0x2 */
/* @0x2b27e6 beq 0x2b2836 <png_do_write_interlace+0x9a> */
/* @0x2b27e8 cmp r3, #0x4 */
/* @0x2b27ea beq 0x2b287e <png_do_write_interlace+0xe2> */
/* @0x2b27ec cmp r3, #0x1 */
/* @0x2b27ee bne 0x2b28ca <png_do_write_interlace+0x12e> */
/* @0x2b27f0 add r0, sp, #0x38 */
/* @0x2b27f2 mov r6, r7 */
/* @0x2b27f4 add r0, r4 */
/* @0x2b27f6 movs r2, #0x0 */
/* @0x2b27f8 movs r3, #0x7 */
/* @0x2b27fa ldr r1, [r0, #-56] */
/* @0x2b27fc .word 0x46861c38 */
/* @0x2b27fe mov lr, r0 */
/* @0x2b2800 cmp r1, r5 */
/* @0x2b2802 bhs 0x2b2832 <png_do_write_interlace+0x96> */
/* @0x2b2804 lsrs r0, r1, #0x3 */
/* @0x2b2806 ldrb.w r12, [r7, r0] */
/* @0x2b2808 bicmi r12, r8, #0 */
/* @0x2b280a mvns r0, r1 */
/* @0x2b280c and r0, r0, #0x7 */
/* @0x2b2810 asr.w r0, r12, r0 */
/* @0x2b2814 and r0, r0, #0x1 */
/* @0x2b2818 lsls r0, r3 */
/* @0x2b281a orrs r2, r0 */
/* @0x2b281c cbnz r3, 0x2b2828 <png_do_write_interlace+0x8c> */
/* @0x2b281e strb r2, [r6] */
/* @0x2b2820 mov r2, r3 */
/* @0x2b2822 adds r6, #0x1 */
/* @0x2b2824 movs r3, #0x7 */
/* @0x2b2826 b 0x2b282a <png_do_write_interlace+0x8e> */
/* @0x2b2828 subs r3, #0x1 */
/* @0x2b282a ldr r0, [lr, #-28] */
/* @0x2b282c strmi r0, [r1], #-3100 */
/* @0x2b282e add r1, r0 */
/* @0x2b2830 b 0x2b2800 <png_do_write_interlace+0x64> */
/* @0x2b2832 cmp r3, #0x7 */
/* @0x2b2834 b 0x2b28c4 <png_do_write_interlace+0x128> */
/* @0x2b2836 add r0, sp, #0x38 */
/* @0x2b2838 mov r6, r7 */
/* @0x2b283a add r0, r4 */
/* @0x2b283c movs r2, #0x0 */
/* @0x2b283e movs r3, #0x6 */
/* @0x2b2840 ldr r1, [r0, #-56] */
/* @0x2b2844 mov lr, r0 */
/* @0x2b2846 cmp r1, r5 */
/* @0x2b2848 bhs 0x2b287a <png_do_write_interlace+0xde> */
/* @0x2b284a lsrs r0, r1, #0x2 */
/* @0x2b284c ldrb.w r12, [r7, r0] */
/* @0x2b2850 mvns r0, r1 */
/* @0x2b2852 and r0, r0, #0x3 */
/* @0x2b2854 subeq r0, r0, r3 */
/* @0x2b2856 lsls r0, r0, #0x1 */
/* @0x2b2858 asr.w r0, r12, r0 */
/* @0x2b285c and r0, r0, #0x3 */
/* @0x2b2860 lsls r0, r3 */
/* @0x2b2862 orrs r2, r0 */
/* @0x2b2864 cbnz r3, 0x2b2870 <png_do_write_interlace+0xd4> */
/* @0x2b2866 strb r2, [r6] */
/* @0x2b2868 mov r2, r3 */
/* @0x2b286a adds r6, #0x1 */
/* @0x2b286c movs r3, #0x6 */
/* @0x2b286e b 0x2b2872 <png_do_write_interlace+0xd6> */
/* @0x2b2870 subs r3, #0x2 */
/* @0x2b2872 ldr r0, [lr, #-28] */
/* @0x2b2874 strmi r0, [r1], #-3100 */
/* @0x2b2876 add r1, r0 */
/* @0x2b2878 b 0x2b2846 <png_do_write_interlace+0xaa> */
/* @0x2b287a cmp r3, #0x6 */
/* @0x2b287c b 0x2b28c4 <png_do_write_interlace+0x128> */
/* @0x2b287e add r0, sp, #0x38 */
/* @0x2b2880 mov r6, r7 */
/* @0x2b2882 add r0, r4 */
/* @0x2b2884 movs r2, #0x0 */
/* @0x2b2886 ldr r1, [r0, #-56] */
/* @0x2b2888 .word 0x46861c38 */
/* @0x2b288a mov lr, r0 */
/* @0x2b288c cmp r1, r5 */
/* @0x2b288e bhs 0x2b28c2 <png_do_write_interlace+0x126> */
/* @0x2b2890 lsrs r0, r1, #0x1 */
/* @0x2b2892 tst.w r1, #0x1 */
/* @0x2b2894 .word 0xf8170f01 */
/* @0x2b2896 ldrb.w r12, [r7, r0] */
/* @0x2b2898 svclt #0x14c000 */
/* @0x2b289a ite ne */
/* @0x2b289c movne r0, #0x0 */
/* @0x2b289e moveq r0, #0x4 */
/* @0x2b28a0 asr.w r0, r12, r0 */
/* @0x2b28a4 and r0, r0, #0xf */
/* @0x2b28a8 lsls r0, r3 */
/* @0x2b28aa orrs r2, r0 */
/* @0x2b28ac cbnz r3, 0x2b28b8 <png_do_write_interlace+0x11c> */
/* @0x2b28ae strb r2, [r6] */
/* @0x2b28b0 mov r2, r3 */
/* @0x2b28b2 adds r6, #0x1 */
/* @0x2b28b4 movs r3, #0x4 */
/* @0x2b28b6 b 0x2b28ba <png_do_write_interlace+0x11e> */
/* @0x2b28b8 subs r3, #0x4 */
/* @0x2b28ba ldr r0, [lr, #-28] */
/* @0x2b28bc strmi r0, [r1], #-3100 */
/* @0x2b28be add r1, r0 */
/* @0x2b28c0 b 0x2b288c <png_do_write_interlace+0xf0> */
/* @0x2b28c2 cmp r3, #0x4 */
/* @0x2b28c4 beq 0x2b28fa <png_do_write_interlace+0x15e> */
/* @0x2b28c6 strb r2, [r6] */
/* @0x2b28c8 b 0x2b28fa <png_do_write_interlace+0x15e> */
/* @0x2b28ca lsr.w r9, r3, #0x3 */
/* @0x2b28cc blge 0x635020 <g_SWFaavertbuff+0x61f58> */
/* @0x2b28ce add r3, sp, #0x38 */
/* @0x2b28d0 add r3, r4 */
/* @0x2b28d2 mov r12, r7 */
/* @0x2b28d4 ldr r6, [r3, #-56] */
/* @0x2b28d8 mov r10, r3 */
/* @0x2b28da cmp r6, r5 */
/* @0x2b28dc bhs 0x2b28fa <png_do_write_interlace+0x15e> */
/* @0x2b28de mla r1, r9, r6, r7 */
/* @0x2b28e0 strmi r7, [r12, #0x106] */
/* @0x2b28e2 cmp r12, r1 */
/* @0x2b28e4 beq 0x2b28f0 <png_do_write_interlace+0x154> */
/* @0x2b28e6 mov r0, r12 */
/* @0x2b28e8 mov r2, r9 */
/* @0x2b28ea blx 0xb65bc <memcpy@plt> */
/* @0x2b28ec strmi lr, [r4], r8, ror #28 */
/* @0x2b28ee mov r12, r0 */
/* @0x2b28f0 ldr r2, [r10, #-28] */
/* @0x2b28f4 add r12, r9 */
/* @0x2b28f6 add r6, r2 */
/* @0x2b28f8 b 0x2b28da <png_do_write_interlace+0x13e> */
/* @0x2b28fa add r3, sp, #0x38 */
/* @0x2b28fc add r4, r3 */
/* @0x2b28fe ldr.w r3, [r8] */
/* @0x2b2900 .word 0xf8543000 */
/* @0x2b2902 ldr r1, [r4, #-28] */
/* @0x2b2904 bllo 0x2f997c <ps_hints_apply+0x857c> */
/* @0x2b2906 subs r3, #0x1 */
/* @0x2b2908 ldr r2, [r4, #-56] */
/* @0x2b290c adds r0, r3, r1 */
/* @0x2b290e subs r0, r0, r2 */
/* @0x2b2910 blx 0x318c48 <__udivsi3> */
/* @0x2b2914 ldrb.w r3, [r8, #0xb] */
/* @0x2b2918 cmp r3, #0x7 */
/* @0x2b291a str.w r0, [r8] */
/* @0x2b291c .word 0xd9020000 */
/* @0x2b291e bls 0x2b2926 <png_do_write_interlace+0x18a> */
/* @0x2b2920 lsrs r3, r3, #0x3 */
/* @0x2b2922 muls r0, r3, r0 */
/* @0x2b2924 b 0x2b292c <png_do_write_interlace+0x190> */
/* @0x2b2926 muls r0, r3, r0 */
/* @0x2b2928 adds r0, #0x7 */
/* @0x2b292a lsrs r0, r0, #0x3 */
/* @0x2b292c str.w r0, [r8, #0x4] */
/* @0x2b2930 add sp, #0x38 */
/* @0x2b2932 pop.w {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b2934 svclt #0x87f0 */
/* @0x2b2936 nop */
/* @0x2b2938 bpl 0x2b28a8 <png_do_write_interlace+0x10c> */
/* @0x2b293a movs r5, r1 */

/* ── FUNC 0x2b293c · png_write_filtered_row · size=156 · insn=70 */
/* @0x2b293c push {r4, r5, r6, lr} */
/* @0x2b293e add.w r5, r0, #0x138 */
/* @0x2b2940 mcrmi p5, #0x1, r7, c4, c12, #0x4 */
/* @0x2b2942 ldr r6, [pc, #0x90] */
/* @0x2b2944 mov r4, r0 */
/* @0x2b2946 ldr.w r3, [r0, #0x1c8] */
/* @0x2b2948 ldrbtmi r3, [lr], #-456 */
/* @0x2b294a add r6, pc */
/* @0x2b294c str.w r1, [r0, #0x138] */
/* @0x2b2950 adds r3, #0x1 */
/* @0x2b2952 str.w r3, [r0, #0x13c] */
/* @0x2b2954 qasxmi r3, r8, r12 */
/* @0x2b2956 mov r0, r5 */
/* @0x2b2958 movs r1, #0x0 */
/* @0x2b295a blx 0xb69ac <deflate@plt> */
/* @0x2b295c teqlt r0, r8, lsr #16 */
/* @0x2b295e cbz r0, 0x2b296e <png_write_filtered_row+0x32> */
/* @0x2b2960 ldr.w r1, [r4, #0x150] */
/* @0x2b2964 mov r0, r4 */
/* @0x2b2966 cbnz r1, 0x2b296a <png_write_filtered_row+0x2e> */
/* @0x2b2968 mov r1, r6 */
/* @0x2b296a bl 0x2a642c <png_error> */
/* @0x2b296c .word 0xf8d4fd5f */
/* @0x2b296e ldr.w r3, [r4, #0x148] */
/* @0x2b2970 ldmdblt r3!, {r3, r6, r8, r12, sp} ^ */
/* @0x2b2972 cbnz r3, 0x2b2992 <png_write_filtered_row+0x56> */
/* @0x2b2974 mov r0, r4 */
/* @0x2b2976 ldr.w r1, [r4, #0x170] */
/* @0x2b2978 .word 0xf8d41170 */
/* @0x2b297a ldr.w r2, [r4, #0x174] */
/* @0x2b297c .word 0xf7fe2174 */
/* @0x2b297e bl 0x2b16a0 <png_write_IDAT> */
/* @0x2b2980 .word 0xf8d4fe8f */
/* @0x2b2982 ldr.w r3, [r4, #0x170] */
/* @0x2b2984 .word 0xf8c43170 */
/* @0x2b2986 str.w r3, [r4, #0x144] */
/* @0x2b2988 .word 0xf8d43144 */
/* @0x2b298a ldr.w r3, [r4, #0x174] */
/* @0x2b298c .word 0xf8c43174 */
/* @0x2b298e str.w r3, [r4, #0x148] */
/* @0x2b2990 .word 0xf8d43148 */
/* @0x2b2992 ldr.w r3, [r4, #0x13c] */
/* @0x2b2994 blhs 0x2bee8c <jpeg_huff_decode+0x300> */
/* @0x2b2996 cmp r3, #0x0 */
/* @0x2b2998 bne 0x2b2956 <png_write_filtered_row+0x1a> */
/* @0x2b299a ldr.w r3, [r4, #0x1ac] */
/* @0x2b299c smulwblt r11, r12, r1 */
/* @0x2b299e cbz r3, 0x2b29ac <png_write_filtered_row+0x70> */
/* @0x2b29a0 ldr.w r2, [r4, #0x1b0] */
/* @0x2b29a4 str.w r3, [r4, #0x1b0] */
/* @0x2b29a8 str.w r2, [r4, #0x1ac] */
/* @0x2b29ac mov r0, r4 */
/* @0x2b29ae bl 0x2b260c <png_write_finish_row> */
/* @0x2b29b0 .word 0xf8d4fe2d */
/* @0x2b29b2 ldr.w r2, [r4, #0x218] */
/* @0x2b29b4 .word 0xf8d42218 */
/* @0x2b29b6 ldr.w r3, [r4, #0x214] */
/* @0x2b29b8 andlo r3, r1, #20, #4 */
/* @0x2b29ba adds r2, #0x1 */
/* @0x2b29bc str.w r2, [r4, #0x218] */
/* @0x2b29c0 cbz r3, 0x2b29d0 <png_write_filtered_row+0x94> */
/* @0x2b29c2 cmp r2, r3 */
/* @0x2b29c4 blo 0x2b29d0 <png_write_filtered_row+0x94> */
/* @0x2b29c6 mov r0, r4 */
/* @0x2b29c8 pop.w {r4, r5, r6, lr} */
/* @0x2b29cc b.w 0x2b0554 <png_write_flush> */
/* @0x2b29d0 pop {r4, r5, r6, pc} */
/* @0x2b29d2 nop */
/* @0x2b29d4 .word 0xb633 */
/* @0x2b29d6 movs r5, r1 */

/* ── FUNC 0x2b29d8 · png_write_find_filter · size=1060 · insn=464 */
/* @0x2b29d8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b29dc mov r11, r0 */
/* @0x2b29de ldrb r3, [r1, #0xb] */
/* @0x2b29e0 sub sp, #0x1c */
/* @0x2b29e2 ldrb.w r0, [r0, #0x1e9] */
/* @0x2b29e4 stmdavs r10, {r0, r3, r5, r6, r7, r8} ^ */
/* @0x2b29e6 ldr r2, [r1, #0x4] */
/* @0x2b29e8 adds r3, #0x7 */
/* @0x2b29ea ldr.w r4, [r11, #0x1ac] */
/* @0x2b29ec streq r4, [r7, -r12, lsr #3] */
/* @0x2b29ee lsls r7, r0, #0x1c */
/* @0x2b29f0 asr.w r3, r3, #0x3 */
/* @0x2b29f4 str r2, [sp, #0xc] */
/* @0x2b29f6 str r4, [sp, #0x4] */
/* @0x2b29f8 ldr.w r2, [r11, #0x1b0] */
/* @0x2b29fc bpl 0x2b2a1e <png_write_find_filter+0x46> */
/* @0x2b29fe cmp r0, #0x8 */
/* @0x2b2a00 beq 0x2b2a74 <png_write_find_filter+0x9c> */
/* @0x2b2a02 ldr r6, [sp, #0xc] */
/* @0x2b2a04 mov r4, r2 */
/* @0x2b2a06 movs r1, #0x0 */
/* @0x2b2a08 add r6, r2 */
/* @0x2b2a0a cmp r4, r6 */
/* @0x2b2a0c beq 0x2b2a22 <png_write_find_filter+0x4a> */
/* @0x2b2a0e ldrb r5, [r4, #1]! */
/* @0x2b2a10 ldclhs p15, c5, [pc, #-4]! */
/* @0x2b2a12 cmp r5, #0x7f */
/* @0x2b2a14 it gt */
/* @0x2b2a16 rsbgt.w r5, r5, #0x100 */
/* @0x2b2a18 strtmi r7, [r9], #-1408 */
/* @0x2b2a1a add r1, r5 */
/* @0x2b2a1c b 0x2b2a0a <png_write_find_filter+0x32> */
/* @0x2b2a1e mvn r1, #0x80000000 */
/* @0x2b2a20 ldmdahs r0, {r8, lr} */
/* @0x2b2a22 cmp r0, #0x10 */
/* @0x2b2a24 bne 0x2b2a78 <png_write_find_filter+0xa0> */
/* @0x2b2a26 ldr.w r5, [r11, #0x1b4] */
/* @0x2b2a28 mrrcne p1, #0xb, r5, r6, c4 */
/* @0x2b2a2a adds r6, r2, #0x1 */
/* @0x2b2a2c movs r4, #0x0 */
/* @0x2b2a2e adds r7, r5, #0x1 */
/* @0x2b2a30 cmp r4, r3 */
/* @0x2b2a32 beq 0x2b2a48 <png_write_find_filter+0x70> */
/* @0x2b2a34 add.w r12, r2, r4 */
/* @0x2b2a38 ldrb.w r8, [r12, #0x1] */
/* @0x2b2a3c add.w r12, r5, r4 */
/* @0x2b2a40 adds r4, #0x1 */
/* @0x2b2a42 strb.w r8, [r12, #0x1] */
/* @0x2b2a44 ldrb r8, [r3, r1]! */
/* @0x2b2a46 b 0x2b2a30 <png_write_find_filter+0x58> */
/* @0x2b2a48 mov r9, r7 */
/* @0x2b2a4a subs r7, r2, r3 */
/* @0x2b2a4c mov r4, r3 */
/* @0x2b2a4e ldr r5, [sp, #0xc] */
/* @0x2b2a50 cmp r4, r5 */
/* @0x2b2a52 bhs 0x2b2a6c <png_write_find_filter+0x94> */
/* @0x2b2a54 add.w r12, r7, r4 */
/* @0x2b2a58 ldrb.w r8, [r6, r4] */
/* @0x2b2a5c ldrb.w r12, [r12, #0x1] */
/* @0x2b2a60 rsb r12, r12, r8 */
/* @0x2b2a64 strb.w r12, [r9, r4] */
/* @0x2b2a68 adds r4, #0x1 */
/* @0x2b2a6a b 0x2b2a4e <png_write_find_filter+0x76> */
/* @0x2b2a6c ldr.w r6, [r11, #0x1b4] */
/* @0x2b2a70 str r6, [sp, #0x8] */
/* @0x2b2a72 b 0x2b2b2e <png_write_find_filter+0x156> */
/* @0x2b2a74 mvn r1, #0x80000000 */
/* @0x2b2a78 lsls r6, r0, #0x1b */
/* @0x2b2a7a bpl 0x2b2afc <png_write_find_filter+0x124> */
/* @0x2b2a7c ldr.w r7, [r11, #0x1b4] */
/* @0x2b2a80 movs r5, #0x0 */
/* @0x2b2a82 add.w r8, r2, #0x1 */
/* @0x2b2a84 strtmi r0, [r12], -r1, lsl #16 */
/* @0x2b2a86 mov r4, r5 */
/* @0x2b2a88 add.w r12, r7, #0x1 */
/* @0x2b2a8c cmp r5, r3 */
/* @0x2b2a8e beq 0x2b2aaa <png_write_find_filter+0xd2> */
/* @0x2b2a90 adds r6, r2, r5 */
/* @0x2b2a92 add.w r9, r7, r5 */
/* @0x2b2a94 strlo r0, [r1, #-0x905] */
/* @0x2b2a96 adds r5, #0x1 */
/* @0x2b2a98 ldrb r6, [r6, #0x1] */
/* @0x2b2a9a cmp r6, #0x7f */
/* @0x2b2a9c strb.w r6, [r9, #0x1] */
/* @0x2b2aa0 it gt */
/* @0x2b2aa2 rsbgt.w r6, r6, #0x100 */
/* @0x2b2aa4 ldrtmi r7, [r4], #-1664 */
/* @0x2b2aa6 add r4, r6 */
/* @0x2b2aa8 b 0x2b2a8c <png_write_find_filter+0xb4> */
/* @0x2b2aaa add.w r9, r12, r3 */
/* @0x2b2aac .word 0xf1c30903 */
/* @0x2b2aae rsb.w r12, r3, #0x0 */
/* @0x2b2ab0 bl 0x335ab8 */
/* @0x2b2ab2 add.w r7, r2, r12 */
/* @0x2b2ab4 strbmi r0, [r12], #1804 */
/* @0x2b2ab6 add r12, r9 */
/* @0x2b2ab8 mov r5, r3 */
/* @0x2b2aba mov r10, r8 */
/* @0x2b2abc ldr r6, [sp, #0xc] */
/* @0x2b2abe cmp r5, r6 */
/* @0x2b2ac0 bhs 0x2b2aee <png_write_find_filter+0x116> */
/* @0x2b2ac2 add.w r8, r7, r5 */
/* @0x2b2ac4 .word 0xf81a0805 */
/* @0x2b2ac6 ldrb.w r9, [r10, r5] */
/* @0x2b2ac8 .word 0xf8989005 */
/* @0x2b2aca ldrb.w r8, [r8, #0x1] */
/* @0x2b2acc bl 0xff4d2ad8 <b2_toiTime+0xfffffffffed79634> */
/* @0x2b2ace rsb r8, r8, r9 */
/* @0x2b2ad0 blx 0x1a74afc <b2_toiTime+0x131b658> */
/* @0x2b2ad2 uxtb.w r8, r8 */
/* @0x2b2ad4 .word 0xf80cf888 */
/* @0x2b2ad6 strb.w r8, [r12, r5] */
/* @0x2b2ad8 .word 0xf1b88005 */
/* @0x2b2ada cmp.w r8, #0x7f */
/* @0x2b2adc svclt #0xc80f7f */
/* @0x2b2ade it gt */
/* @0x2b2ae0 rsbgt.w r8, r8, #0x100 */
/* @0x2b2ae4 add r4, r8 */
/* @0x2b2ae6 cmp r4, r1 */
/* @0x2b2ae8 bhi 0x2b2afc <png_write_find_filter+0x124> */
/* @0x2b2aea adds r5, #0x1 */
/* @0x2b2aec b 0x2b2abc <png_write_find_filter+0xe4> */
/* @0x2b2aee cmp r4, r1 */
/* @0x2b2af0 bhs 0x2b2afc <png_write_find_filter+0x124> */
/* @0x2b2af2 ldr.w r1, [r11, #0x1b4] */
/* @0x2b2af4 strhls r1, [r2, -r4] */
/* @0x2b2af6 str r1, [sp, #0x8] */
/* @0x2b2af8 mov r1, r4 */
/* @0x2b2afa b 0x2b2afe <png_write_find_filter+0x126> */
/* @0x2b2afc str r2, [sp, #0x8] */
/* @0x2b2afe cmp r0, #0x20 */
/* @0x2b2b00 bne 0x2b2b2e <png_write_find_filter+0x156> */
/* @0x2b2b02 ldr r4, [sp, #0xc] */
/* @0x2b2b04 ldr.w r6, [r11, #0x1b8] */
/* @0x2b2b08 adds r5, r4, #0x1 */
/* @0x2b2b0a movs r4, #0x0 */
/* @0x2b2b0c adds r4, #0x1 */
/* @0x2b2b0e cmp r4, r5 */
/* @0x2b2b10 beq 0x2b2b26 <png_write_find_filter+0x14e> */
/* @0x2b2b12 ldr.w r8, [sp, #0x4] */
/* @0x2b2b14 .word 0xf8128004 */
/* @0x2b2b16 ldrb.w r12, [r2, r4] */
/* @0x2b2b18 .word 0xf818c004 */
/* @0x2b2b1a ldrb.w r7, [r8, r4] */
/* @0x2b2b1c bl 0xff48eb34 <b2_toiTime+0xfffffffffed35690> */
/* @0x2b2b1e rsb r7, r7, r12 */
/* @0x2b2b20 ldrpl r0, [r7, #-0x70c]! */
/* @0x2b2b22 strb r7, [r6, r4] */
/* @0x2b2b24 b 0x2b2b0c <png_write_find_filter+0x134> */
/* @0x2b2b26 ldr.w r4, [r11, #0x1b8] */
/* @0x2b2b28 strls r4, [r2], #-440 */
/* @0x2b2b2a str r4, [sp, #0x8] */
/* @0x2b2b2c b 0x2b2be2 <png_write_find_filter+0x20a> */
/* @0x2b2b2e lsls r5, r0, #0x1a */
/* @0x2b2b30 bpl 0x2b2b7c <png_write_find_filter+0x1a4> */
/* @0x2b2b32 ldr r5, [sp, #0xc] */
/* @0x2b2b34 movs r4, #0x1 */
/* @0x2b2b36 ldr.w r7, [r11, #0x1b8] */
/* @0x2b2b38 stclne p1, c7, [lr], #-736 */
/* @0x2b2b3a adds r6, r5, #0x1 */
/* @0x2b2b3c movs r5, #0x0 */
/* @0x2b2b3e cmp r4, r6 */
/* @0x2b2b40 beq 0x2b2b70 <png_write_find_filter+0x198> */
/* @0x2b2b42 ldr.w r9, [sp, #0x4] */
/* @0x2b2b44 .word 0xf8129004 */
/* @0x2b2b46 ldrb.w r8, [r2, r4] */
/* @0x2b2b48 .word 0xf8198004 */
/* @0x2b2b4a ldrb.w r12, [r9, r4] */
/* @0x2b2b4c bl 0xff5e2b64 <b2_toiTime+0xfffffffffee896c0> */
/* @0x2b2b4e rsb r12, r12, r8 */
/* @0x2b2b50 blx 0x1a75b78 <b2_toiTime+0x131c6d4> */
/* @0x2b2b52 uxtb.w r12, r12 */
/* @0x2b2b54 .word 0xf807fc8c */
/* @0x2b2b56 strb.w r12, [r7, r4] */
/* @0x2b2b58 .word 0xf1bcc004 */
/* @0x2b2b5a cmp.w r12, #0x7f */
/* @0x2b2b5c .word 0xf1040f7f */
/* @0x2b2b5e add.w r4, r4, #0x1 */
/* @0x2b2b60 svclt #0xc80401 */
/* @0x2b2b62 it gt */
/* @0x2b2b64 rsbgt.w r12, r12, #0x100 */
/* @0x2b2b68 add r5, r12 */
/* @0x2b2b6a cmp r5, r1 */
/* @0x2b2b6c bls 0x2b2b3e <png_write_find_filter+0x166> */
/* @0x2b2b6e b 0x2b2b7c <png_write_find_filter+0x1a4> */
/* @0x2b2b70 cmp r5, r1 */
/* @0x2b2b72 bhs 0x2b2b7c <png_write_find_filter+0x1a4> */
/* @0x2b2b74 ldr.w r1, [r11, #0x1b8] */
/* @0x2b2b78 str r1, [sp, #0x8] */
/* @0x2b2b7a mov r1, r5 */
/* @0x2b2b7c cmp r0, #0x40 */
/* @0x2b2b7e bne 0x2b2be2 <png_write_find_filter+0x20a> */
/* @0x2b2b80 ldr.w r5, [r11, #0x1bc] */
/* @0x2b2b84 adds r7, r2, #0x1 */
/* @0x2b2b86 ldr r4, [sp, #0x4] */
/* @0x2b2b88 add.w r8, r3, #0x1 */
/* @0x2b2b8c add.w r12, r5, #0x1 */
/* @0x2b2b90 adds r6, r4, #0x1 */
/* @0x2b2b92 movs r4, #0x0 */
/* @0x2b2b94 adds r4, #0x1 */
/* @0x2b2b96 cmp r4, r8 */
/* @0x2b2b98 beq 0x2b2bb0 <png_write_find_filter+0x1d8> */
/* @0x2b2b9a ldr.w r10, [sp, #0x4] */
/* @0x2b2b9c .word 0xf81aa004 */
/* @0x2b2b9e ldrb.w r9, [r10, r4] */
/* @0x2b2ba0 .word 0xf8129004 */
/* @0x2b2ba2 ldrb.w r10, [r2, r4] */
/* @0x2b2ba4 bl 0xfed5abbc <b2_toiTime+0xfffffffffe601718> */
/* @0x2b2ba6 sub.w r9, r10, r9, lsr #1 */
/* @0x2b2ba8 .word 0xf8050959 */
/* @0x2b2baa strb.w r9, [r5, r4] */
/* @0x2b2bac ldrb r9, [r1, r4]! */
/* @0x2b2bae b 0x2b2b94 <png_write_find_filter+0x1bc> */
/* @0x2b2bb0 rsb r10, r3, r2 */
/* @0x2b2bb4 mov r4, r3 */
/* @0x2b2bb6 ldr r5, [sp, #0xc] */
/* @0x2b2bb8 cmp r4, r5 */
/* @0x2b2bba bhs 0x2b2bda <png_write_find_filter+0x202> */
/* @0x2b2bbc add.w r8, r10, r4 */
/* @0x2b2bc0 ldrb.w r9, [r6, r4] */
/* @0x2b2bc4 ldrb.w r8, [r8, #0x1] */
/* @0x2b2bc8 add r8, r9 */
/* @0x2b2bca ldrb.w r9, [r7, r4] */
/* @0x2b2bcc bl 0xfed16be4 <b2_toiTime+0xfffffffffe5bd740> */
/* @0x2b2bce sub.w r8, r9, r8, lsr #1 */
/* @0x2b2bd0 .word 0xf80c0858 */
/* @0x2b2bd2 strb.w r8, [r12, r4] */
/* @0x2b2bd4 strlo r8, [r1], #-4 */
/* @0x2b2bd6 adds r4, #0x1 */
/* @0x2b2bd8 b 0x2b2bb6 <png_write_find_filter+0x1de> */
/* @0x2b2bda ldr.w r6, [r11, #0x1bc] */
/* @0x2b2bdc .word 0x960261bc */
/* @0x2b2bde str r6, [sp, #0x8] */
/* @0x2b2be0 b 0x2b2d18 <png_write_find_filter+0x340> */
/* @0x2b2be2 lsls r4, r0, #0x19 */
/* @0x2b2be4 bpl 0x2b2c76 <png_write_find_filter+0x29e> */
/* @0x2b2be6 ldr.w r6, [r11, #0x1bc] */
/* @0x2b2be8 .word 0xf10261bc */
/* @0x2b2bea add.w r10, r2, #0x1 */
/* @0x2b2bec .word 0x9c010a01 */
/* @0x2b2bee ldr r4, [sp, #0x4] */
/* @0x2b2bf0 add.w r8, r3, #0x1 */
/* @0x2b2bf4 add.w r9, r6, #0x1 */
/* @0x2b2bf8 movs r5, #0x1 */
/* @0x2b2bfa adds r4, #0x1 */
/* @0x2b2bfc str r4, [sp, #0x10] */
/* @0x2b2bfe movs r4, #0x0 */
/* @0x2b2c00 cmp r5, r8 */
/* @0x2b2c02 beq 0x2b2c28 <png_write_find_filter+0x250> */
/* @0x2b2c04 ldr.w r12, [sp, #0x4] */
/* @0x2b2c08 ldrb.w r7, [r12, r5] */
/* @0x2b2c0c ldrb.w r12, [r2, r5] */
/* @0x2b2c10 sub.w r7, r12, r7, lsr #1 */
/* @0x2b2c14 uxtb r7, r7 */
/* @0x2b2c16 strb r7, [r6, r5] */
/* @0x2b2c18 cmp r7, #0x7f */
/* @0x2b2c1a add.w r5, r5, #0x1 */
/* @0x2b2c1c svclt #0xc80501 */
/* @0x2b2c1e it gt */
/* @0x2b2c20 rsbgt.w r7, r7, #0x100 */
/* @0x2b2c24 add r4, r7 */
/* @0x2b2c26 b 0x2b2c00 <png_write_find_filter+0x228> */
/* @0x2b2c28 rsbs r6, r3, #0 */
/* @0x2b2c2a add r9, r3 */
/* @0x2b2c2c ldr.w r8, [sp, #0x10] */
/* @0x2b2c30 add.w r12, r2, r6 */
/* @0x2b2c34 add r9, r6 */
/* @0x2b2c36 mov r5, r3 */
/* @0x2b2c38 ldr r6, [sp, #0xc] */
/* @0x2b2c3a cmp r5, r6 */
/* @0x2b2c3c bhs 0x2b2c6a <png_write_find_filter+0x292> */
/* @0x2b2c3e add.w r6, r12, r5 */
/* @0x2b2c40 .word 0xf8180605 */
/* @0x2b2c42 ldrb.w r7, [r8, r5] */
/* @0x2b2c44 ldmdavc r6!, {r0, r2, r12, sp, lr} ^ */
/* @0x2b2c46 ldrb r6, [r6, #0x1] */
/* @0x2b2c48 add r6, r7 */
/* @0x2b2c4a ldrb.w r7, [r10, r5] */
/* @0x2b2c4c bl 0xfec8ec68 <b2_toiTime+0xfffffffffe5357c4> */
/* @0x2b2c4e sub.w r6, r7, r6, lsr #1 */
/* @0x2b2c50 rscslt r0, r6, #90177536 */
/* @0x2b2c52 uxtb r6, r6 */
/* @0x2b2c54 strb.w r6, [r9, r5] */
/* @0x2b2c58 cmp r6, #0x7f */
/* @0x2b2c5a it gt */
/* @0x2b2c5c rsbgt.w r6, r6, #0x100 */
/* @0x2b2c60 add r4, r6 */
/* @0x2b2c62 cmp r4, r1 */
/* @0x2b2c64 bhi 0x2b2c76 <png_write_find_filter+0x29e> */
/* @0x2b2c66 adds r5, #0x1 */
/* @0x2b2c68 b 0x2b2c38 <png_write_find_filter+0x260> */
/* @0x2b2c6a cmp r4, r1 */
/* @0x2b2c6c bhs 0x2b2c76 <png_write_find_filter+0x29e> */
/* @0x2b2c6e ldr.w r1, [r11, #0x1bc] */
/* @0x2b2c70 strhls r1, [r2, -r12] */
/* @0x2b2c72 str r1, [sp, #0x8] */
/* @0x2b2c74 mov r1, r4 */
/* @0x2b2c76 cmp r0, #0x80 */
/* @0x2b2c78 bne 0x2b2d18 <png_write_find_filter+0x340> */
/* @0x2b2c7a ldr r5, [sp, #0x4] */
/* @0x2b2c7c adds r4, r2, #0x1 */
/* @0x2b2c7e ldr.w r0, [r11, #0x1c0] */
/* @0x2b2c80 smlabths r0, r0, r1, r0 */
/* @0x2b2c82 movs r1, #0x0 */
/* @0x2b2c84 add.w r12, r5, #0x1 */
/* @0x2b2c88 adds r5, r3, #0x1 */
/* @0x2b2c8a add.w r10, r0, #0x1 */
/* @0x2b2c8c .word 0x31010a01 */
/* @0x2b2c8e adds r1, #0x1 */
/* @0x2b2c90 cmp r1, r5 */
/* @0x2b2c92 beq 0x2b2ca4 <png_write_find_filter+0x2cc> */
/* @0x2b2c94 ldr.w r8, [sp, #0x4] */
/* @0x2b2c98 ldrb r7, [r2, r1] */
/* @0x2b2c9a ldrb.w r6, [r8, r1] */
/* @0x2b2c9c blne 0xff24aca8 <b2_toiTime+0xfffffffffeaf1804> */
/* @0x2b2c9e subs r6, r7, r6 */
/* @0x2b2ca0 strb r6, [r0, r1] */
/* @0x2b2ca2 b 0x2b2c8e <png_write_find_filter+0x2b6> */
/* @0x2b2ca4 ldr.w r8, [sp, #0x4] */
/* @0x2b2ca8 rsbs r1, r3, #0 */
/* @0x2b2caa adds r0, r4, r3 */
/* @0x2b2cac add r10, r3 */
/* @0x2b2cae add r12, r3 */
/* @0x2b2cb0 add r8, r1 */
/* @0x2b2cb2 add r12, r1 */
/* @0x2b2cb4 add.w r9, r2, r1 */
/* @0x2b2cb8 add r10, r1 */
/* @0x2b2cba adds r1, r0, r1 */
/* @0x2b2cbc str r1, [sp, #0x4] */
/* @0x2b2cbe ldr r1, [sp, #0xc] */
/* @0x2b2cc0 cmp r3, r1 */
/* @0x2b2cc2 bhs 0x2b2d10 <png_write_find_filter+0x338> */
/* @0x2b2cc4 add.w r2, r8, r3 */
/* @0x2b2cc8 add.w r1, r9, r3 */
/* @0x2b2ccc ldrb.w r0, [r12, r3] */
/* @0x2b2cd0 ldrb r2, [r2, #0x1] */
/* @0x2b2cd2 ldrb r1, [r1, #0x1] */
/* @0x2b2cd4 subs r7, r0, r2 */
/* @0x2b2cd6 subs r6, r1, r2 */
/* @0x2b2cd8 eor.w r5, r7, r7, asr #31 */
/* @0x2b2cdc sub.w r5, r5, r7, asr #31 */
/* @0x2b2ce0 eor.w r4, r6, r6, asr #31 */
/* @0x2b2ce4 sub.w r4, r4, r6, asr #31 */
/* @0x2b2ce8 add r6, r7 */
/* @0x2b2cea cmp r6, #0x0 */
/* @0x2b2cec it lt */
/* @0x2b2cee rsblt r6, r6, #0 */
/* @0x2b2cf0 cmp r5, r4 */
/* @0x2b2cf2 bgt 0x2b2cf8 <png_write_find_filter+0x320> */
/* @0x2b2cf4 cmp r5, r6 */
/* @0x2b2cf6 ble 0x2b2d00 <png_write_find_filter+0x328> */
/* @0x2b2cf8 cmp r4, r6 */
/* @0x2b2cfa it le */
/* @0x2b2cfc movle r2, r0 */
/* @0x2b2cfe b 0x2b2d02 <png_write_find_filter+0x32a> */
/* @0x2b2d00 mov r2, r1 */
/* @0x2b2d02 ldr r0, [sp, #0x4] */
/* @0x2b2d04 ldrb r1, [r0, r3] */
/* @0x2b2d06 subs r2, r1, r2 */
/* @0x2b2d08 strb.w r2, [r10, r3] */
/* @0x2b2d0c adds r3, #0x1 */
/* @0x2b2d0e b 0x2b2cbe <png_write_find_filter+0x2e6> */
/* @0x2b2d10 ldr.w r2, [r11, #0x1c0] */
/* @0x2b2d14 str r2, [sp, #0x8] */
/* @0x2b2d16 b 0x2b2dee <png_write_find_filter+0x416> */
/* @0x2b2d18 lsls r0, r0, #0x18 */
/* @0x2b2d1a bpl 0x2b2dee <png_write_find_filter+0x416> */
/* @0x2b2d1c ldr.w r5, [r11, #0x1c0] */
/* @0x2b2d20 add.w r9, r2, #0x1 */
/* @0x2b2d24 ldr r4, [sp, #0x4] */
/* @0x2b2d26 movs r0, #0x0 */
/* @0x2b2d28 add.w r10, r5, #0x1 */
/* @0x2b2d2c adds r6, r3, #0x1 */
/* @0x2b2d2e add.w r8, r4, #0x1 */
/* @0x2b2d30 strhs r0, [r1], #-2049 */
/* @0x2b2d32 movs r4, #0x1 */
/* @0x2b2d34 str r6, [sp, #0x10] */
/* @0x2b2d36 ldr.w r12, [sp, #0x10] */
/* @0x2b2d38 strbmi r12, [r4, #-0x10]! */
/* @0x2b2d3a cmp r4, r12 */
/* @0x2b2d3c beq 0x2b2d5e <png_write_find_filter+0x386> */
/* @0x2b2d3e ldr r6, [sp, #0x4] */
/* @0x2b2d40 ldrb.w r12, [r2, r4] */
/* @0x2b2d44 ldrb r7, [r6, r4] */
/* @0x2b2d46 rsb r7, r7, r12 */
/* @0x2b2d48 rscslt r0, pc, #12, #14 */
/* @0x2b2d4a uxtb r7, r7 */
/* @0x2b2d4c strb r7, [r5, r4] */
/* @0x2b2d4e cmp r7, #0x7f */
/* @0x2b2d50 add.w r4, r4, #0x1 */
/* @0x2b2d54 it gt */
/* @0x2b2d56 rsbgt.w r7, r7, #0x100 */
/* @0x2b2d58 ldrtmi r7, [r8], #-1920 */
/* @0x2b2d5a add r0, r7 */
/* @0x2b2d5c b 0x2b2d36 <png_write_find_filter+0x35e> */
/* @0x2b2d5e rsbs r4, r3, #0 */
/* @0x2b2d60 add r9, r3 */
/* @0x2b2d62 add r10, r3 */
/* @0x2b2d64 ldr r5, [sp, #0x4] */
/* @0x2b2d66 add r9, r4 */
/* @0x2b2d68 add r10, r4 */
/* @0x2b2d6a add r8, r3 */
/* @0x2b2d6c add r5, r4 */
/* @0x2b2d6e add r8, r4 */
/* @0x2b2d70 add r2, r4 */
/* @0x2b2d72 str.w r8, [sp, #0x10] */
/* @0x2b2d74 strls r8, [r1, #-0x10] */
/* @0x2b2d76 str r5, [sp, #0x4] */
/* @0x2b2d78 str r2, [sp, #0x14] */
/* @0x2b2d7a ldr r2, [sp, #0xc] */
/* @0x2b2d7c cmp r3, r2 */
/* @0x2b2d7e bhs 0x2b2de4 <png_write_find_filter+0x40c> */
/* @0x2b2d80 ldr r2, [sp, #0x4] */
/* @0x2b2d82 ldr r4, [sp, #0x14] */
/* @0x2b2d84 ldr r6, [sp, #0x10] */
/* @0x2b2d86 add r2, r3 */
/* @0x2b2d88 add r4, r3 */
/* @0x2b2d8a ldrb r2, [r2, #0x1] */
/* @0x2b2d8c ldrb r5, [r6, r3] */
/* @0x2b2d8e ldrb r4, [r4, #0x1] */
/* @0x2b2d90 rsb r8, r2, r5 */
/* @0x2b2d94 rsb r12, r2, r4 */
/* @0x2b2d98 eor.w r7, r8, r8, asr #31 */
/* @0x2b2d9c sub.w r7, r7, r8, asr #31 */
/* @0x2b2da0 eor.w r6, r12, r12, asr #31 */
/* @0x2b2da4 sub.w r6, r6, r12, asr #31 */
/* @0x2b2da8 add r12, r8 */
/* @0x2b2daa cmp.w r12, #0x0 */
/* @0x2b2dac svclt #0xb80f00 */
/* @0x2b2dae it lt */
/* @0x2b2db0 rsblt.w r12, r12, #0x0 */
/* @0x2b2db4 cmp r7, r6 */
/* @0x2b2db6 bgt 0x2b2dbc <png_write_find_filter+0x3e4> */
/* @0x2b2db8 cmp r7, r12 */
/* @0x2b2dba ble 0x2b2dc4 <png_write_find_filter+0x3ec> */
/* @0x2b2dbc cmp r6, r12 */
/* @0x2b2dbe it le */
/* @0x2b2dc0 movle r2, r5 */
/* @0x2b2dc2 b 0x2b2dc6 <png_write_find_filter+0x3ee> */
/* @0x2b2dc4 mov r2, r4 */
/* @0x2b2dc6 ldrb.w r4, [r9, r3] */
/* @0x2b2dc8 bne 0xfeb42ddc <b2_toiTime+0xfffffffffe3e9938> */
/* @0x2b2dca subs r2, r4, r2 */
/* @0x2b2dcc uxtb r2, r2 */
/* @0x2b2dce strb.w r2, [r10, r3] */
/* @0x2b2dd0 bhs 0x227ade4 <b2_toiTime+0x1b21940> */
/* @0x2b2dd2 cmp r2, #0x7f */
/* @0x2b2dd4 it gt */
/* @0x2b2dd6 rsbgt.w r2, r2, #0x100 */
/* @0x2b2dd8 ldrmi r7, [r0], #-640 */
/* @0x2b2dda add r0, r2 */
/* @0x2b2ddc cmp r0, r1 */
/* @0x2b2dde bhi 0x2b2dee <png_write_find_filter+0x416> */
/* @0x2b2de0 adds r3, #0x1 */
/* @0x2b2de2 b 0x2b2d7a <png_write_find_filter+0x3a2> */
/* @0x2b2de4 cmp r0, r1 */
/* @0x2b2de6 itt lo */
/* @0x2b2de8 ldrlo.w r3, [r11, #0x1c0] */
/* @0x2b2dec strlo r3, [sp, #0x8] */
/* @0x2b2dee mov r0, r11 */
/* @0x2b2df0 ldr r1, [sp, #0x8] */
/* @0x2b2df2 add sp, #0x1c */
/* @0x2b2df4 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b2df8 b.w 0x2b293c <png_write_filtered_row> */

/* ── FUNC 0x2b2dfc · jpeg_CreateDecompress · size=260 · insn=65 */
/* @0x2b2dfc cmp r1, #62 */
/* @0x2b2e00 mov r3, #0 */
/* @0x2b2e04 push {r4, r5, r6, lr} */
/* @0x2b2e08 mov r4, r0 */
/* @0x2b2e0c mov r5, r2 */
/* @0x2b2e10 str r3, [r0, #0x4] */
/* @0x2b2e14 beq 0x2b2e40 <jpeg_CreateDecompress+0x44> */
/* @0x2b2e18 ldr r3, [r0] */
/* @0x2b2e1c mov r2, #62 */
/* @0x2b2e20 mov r12, #12 */
/* @0x2b2e24 str r2, [r3, #0x18] */
/* @0x2b2e28 ldr r2, [r0] */
/* @0x2b2e2c str r12, [r3, #0x14] */
/* @0x2b2e30 str r1, [r2, #0x1c] */
/* @0x2b2e34 ldr r3, [r0] */
/* @0x2b2e38 ldr r3, [r3] */
/* @0x2b2e3c blx r3 */
/* @0x2b2e40 cmp r5, #432 */
/* @0x2b2e44 beq 0x2b2e74 <jpeg_CreateDecompress+0x78> */
/* @0x2b2e48 ldr r3, [r4] */
/* @0x2b2e4c mov r2, #432 */
/* @0x2b2e50 mov r1, #21 */
/* @0x2b2e54 mov r0, r4 */
/* @0x2b2e58 str r2, [r3, #0x18] */
/* @0x2b2e5c ldr r2, [r4] */
/* @0x2b2e60 str r1, [r3, #0x14] */
/* @0x2b2e64 str r5, [r2, #0x1c] */
/* @0x2b2e68 ldr r3, [r4] */
/* @0x2b2e6c ldr r3, [r3] */
/* @0x2b2e70 blx r3 */
/* @0x2b2e74 ldr r6, [r4] */
/* @0x2b2e78 mov r1, #0 */
/* @0x2b2e7c ldr r5, [r4, #0xc] */
/* @0x2b2e80 mov r2, #432 */
/* @0x2b2e84 mov r0, r4 */
/* @0x2b2e88 bl 0xb65b0 <memset@plt> */
/* @0x2b2e8c mov r3, #1 */
/* @0x2b2e90 mov r0, r4 */
/* @0x2b2e94 strb r3, [r4, #0x10] */
/* @0x2b2e98 str r6, [r4] */
/* @0x2b2e9c str r5, [r4, #0xc] */
/* @0x2b2ea0 bl 0x2ba0b4 <jinit_memory_mgr> */
/* @0x2b2ea4 mov r3, #0 */
/* @0x2b2ea8 mov r0, r4 */
/* @0x2b2eac str r3, [r4, #0x8] */
/* @0x2b2eb0 str r3, [r4, #0x18] */
/* @0x2b2eb4 str r3, [r4, #0x90] */
/* @0x2b2eb8 str r3, [r4, #0x94] */
/* @0x2b2ebc str r3, [r4, #0x98] */
/* @0x2b2ec0 str r3, [r4, #0x9c] */
/* @0x2b2ec4 str r3, [r4, #0xa0] */
/* @0x2b2ec8 str r3, [r4, #0xb0] */
/* @0x2b2ecc str r3, [r4, #0xa4] */
/* @0x2b2ed0 str r3, [r4, #0xb4] */
/* @0x2b2ed4 str r3, [r4, #0xa8] */
/* @0x2b2ed8 str r3, [r4, #0xb8] */
/* @0x2b2edc str r3, [r4, #0xac] */
/* @0x2b2ee0 str r3, [r4, #0xbc] */
/* @0x2b2ee4 str r3, [r4, #0x10c] */
/* @0x2b2ee8 bl 0x2b5efc <jinit_marker_reader> */
/* @0x2b2eec mov r0, r4 */
/* @0x2b2ef0 bl 0x2b3ee0 <jinit_input_controller> */
/* @0x2b2ef4 mov r3, #200 */
/* @0x2b2ef8 str r3, [r4, #0x14] */
/* @0x2b2efc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2b2f00 · jpeg_destroy_decompress · size=4 · insn=1 */
/* @0x2b2f00 b 0x2bc8b8 <jpeg_destroy> */

/* ── FUNC 0x2b2f04 · jpeg_abort_decompress · size=4 · insn=1 */
/* @0x2b2f04 b 0x2bc874 <jpeg_abort> */

/* ── FUNC 0x2b2f08 · jpeg_consume_input · size=688 · insn=172 */
/* @0x2b2f08 ldr r2, [r0, #0x14] */
/* @0x2b2f0c push {r3, r4, r5, r6, r7, lr} */
/* @0x2b2f10 sub r3, r2, #200 */
/* @0x2b2f14 mov r4, r0 */
/* @0x2b2f18 cmp r3, #10 */
/* @0x2b2f1c addls pc, pc, r3, lsl #2 */
/* @0x2b2f20 b 0x2b2fbc <jpeg_consume_input+0xb4> */
/* @0x2b2f24 b 0x2b2f50 <jpeg_consume_input+0x48> */
/* @0x2b2f28 b 0x2b2f74 <jpeg_consume_input+0x6c> */
/* @0x2b2f2c b 0x2b2f98 <jpeg_consume_input+0x90> */
/* @0x2b2f30 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f34 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f38 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f3c b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f40 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f44 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f48 b 0x2b2fbc <jpeg_consume_input+0xb4> */
/* @0x2b2f4c b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f50 ldr r3, [r0, #0x190] */
/* @0x2b2f54 ldr r3, [r3, #0x4] */
/* @0x2b2f58 blx r3 */
/* @0x2b2f5c ldr r3, [r4, #0x18] */
/* @0x2b2f60 mov r0, r4 */
/* @0x2b2f64 ldr r3, [r3, #0x8] */
/* @0x2b2f68 blx r3 */
/* @0x2b2f6c mov r3, #201 */
/* @0x2b2f70 str r3, [r4, #0x14] */
/* @0x2b2f74 ldr r3, [r4, #0x190] */
/* @0x2b2f78 mov r0, r4 */
/* @0x2b2f7c ldr r3, [r3] */
/* @0x2b2f80 blx r3 */
/* @0x2b2f84 cmp r0, #1 */
/* @0x2b2f88 mov r5, r0 */
/* @0x2b2f8c beq 0x2b2fe4 <jpeg_consume_input+0xdc> */
/* @0x2b2f90 mov r0, r5 */
/* @0x2b2f94 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b2f98 mov r5, #1 */
/* @0x2b2f9c mov r0, r5 */
/* @0x2b2fa0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b2fa4 ldr r3, [r0, #0x190] */
/* @0x2b2fa8 ldr r3, [r3] */
/* @0x2b2fac blx r3 */
/* @0x2b2fb0 mov r5, r0 */
/* @0x2b2fb4 mov r0, r5 */
/* @0x2b2fb8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b2fbc ldr r3, [r0] */
/* @0x2b2fc0 mov r1, #20 */
/* @0x2b2fc4 mov r5, #0 */
/* @0x2b2fc8 str r2, [r3, #0x18] */
/* @0x2b2fcc ldr r2, [r4] */
/* @0x2b2fd0 str r1, [r3, #0x14] */
/* @0x2b2fd4 ldr r3, [r2] */
/* @0x2b2fd8 blx r3 */
/* @0x2b2fdc mov r0, r5 */
/* @0x2b2fe0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b2fe4 ldr r6, [r4, #0x24] */
/* @0x2b2fe8 cmp r6, #3 */
/* @0x2b2fec beq 0x2b3078 <jpeg_consume_input+0x170> */
/* @0x2b2ff0 cmp r6, #4 */
/* @0x2b2ff4 beq 0x2b30dc <jpeg_consume_input+0x1d4> */
/* @0x2b2ff8 cmp r6, #1 */
/* @0x2b2ffc streq r0, [r4, #0x28] */
/* @0x2b3000 streq r0, [r4, #0x2c] */
/* @0x2b3004 movne r3, #0 */
/* @0x2b3008 strne r3, [r4, #0x28] */
/* @0x2b300c strne r3, [r4, #0x2c] */
/* @0x2b3010 mov r1, #0 */
/* @0x2b3014 mov r0, #1 */
/* @0x2b3018 mov r2, #0 */
/* @0x2b301c mov r3, #0 */
/* @0x2b3020 mov r7, #2 */
/* @0x2b3024 movt r3, #0x3ff0 */
/* @0x2b3028 mov r6, #256 */
/* @0x2b302c mov r12, #202 */
/* @0x2b3030 str r0, [r4, #0x30] */
/* @0x2b3034 str r0, [r4, #0x34] */
/* @0x2b3038 strb r0, [r4, #0x48] */
/* @0x2b303c strb r0, [r4, #0x49] */
/* @0x2b3040 strb r0, [r4, #0x50] */
/* @0x2b3044 strb r1, [r4, #0x40] */
/* @0x2b3048 strb r1, [r4, #0x41] */
/* @0x2b304c str r1, [r4, #0x44] */
/* @0x2b3050 strb r1, [r4, #0x4a] */
/* @0x2b3054 strd r2, r3, [r4, #56] */
/* @0x2b3058 str r1, [r4, #0x74] */
/* @0x2b305c strb r1, [r4, #0x58] */
/* @0x2b3060 strb r1, [r4, #0x59] */
/* @0x2b3064 strb r1, [r4, #0x5a] */
/* @0x2b3068 str r7, [r4, #0x4c] */
/* @0x2b306c str r6, [r4, #0x54] */
/* @0x2b3070 str r12, [r4, #0x14] */
/* @0x2b3074 b 0x2b2f90 <jpeg_consume_input+0x88> */
/* @0x2b3078 ldrb r3, [r4, #0x100] */
/* @0x2b307c cmp r3, #0 */
/* @0x2b3080 bne 0x2b3198 <jpeg_consume_input+0x290> */
/* @0x2b3084 ldrb r3, [r4, #0x108] */
/* @0x2b3088 cmp r3, #0 */
/* @0x2b308c beq 0x2b3138 <jpeg_consume_input+0x230> */
/* @0x2b3090 ldrb r3, [r4, #0x109] */
/* @0x2b3094 cmp r3, #0 */
/* @0x2b3098 beq 0x2b31ac <jpeg_consume_input+0x2a4> */
/* @0x2b309c cmp r3, #1 */
/* @0x2b30a0 beq 0x2b30cc <jpeg_consume_input+0x1c4> */
/* @0x2b30a4 ldr r3, [r4] */
/* @0x2b30a8 mov r2, #114 */
/* @0x2b30ac mov r0, r4 */
/* @0x2b30b0 mvn r1, #0 */
/* @0x2b30b4 str r2, [r3, #0x14] */
/* @0x2b30b8 ldrb r2, [r4, #0x109] */
/* @0x2b30bc str r2, [r3, #0x18] */
/* @0x2b30c0 ldr r3, [r4] */
/* @0x2b30c4 ldr r3, [r3, #0x4] */
/* @0x2b30c8 blx r3 */
/* @0x2b30cc str r6, [r4, #0x28] */
/* @0x2b30d0 mov r3, #2 */
/* @0x2b30d4 str r3, [r4, #0x2c] */
/* @0x2b30d8 b 0x2b3010 <jpeg_consume_input+0x108> */
/* @0x2b30dc ldrb r3, [r4, #0x108] */
/* @0x2b30e0 cmp r3, #0 */
/* @0x2b30e4 beq 0x2b31a4 <jpeg_consume_input+0x29c> */
/* @0x2b30e8 ldrb r3, [r4, #0x109] */
/* @0x2b30ec cmp r3, #0 */
/* @0x2b30f0 beq 0x2b31a4 <jpeg_consume_input+0x29c> */
/* @0x2b30f4 cmp r3, #2 */
/* @0x2b30f8 beq 0x2b3124 <jpeg_consume_input+0x21c> */
/* @0x2b30fc ldr r3, [r4] */
/* @0x2b3100 mov r2, #114 */
/* @0x2b3104 mov r0, r4 */
/* @0x2b3108 mvn r1, #0 */
/* @0x2b310c str r2, [r3, #0x14] */
/* @0x2b3110 ldrb r2, [r4, #0x109] */
/* @0x2b3114 str r2, [r3, #0x18] */
/* @0x2b3118 ldr r3, [r4] */
/* @0x2b311c ldr r3, [r3, #0x4] */
/* @0x2b3120 blx r3 */
/* @0x2b3124 mov r3, #5 */
/* @0x2b3128 str r3, [r4, #0x28] */
/* @0x2b312c mov r3, #4 */
/* @0x2b3130 str r3, [r4, #0x2c] */
/* @0x2b3134 b 0x2b3010 <jpeg_consume_input+0x108> */
/* @0x2b3138 ldr r3, [r4, #0xc4] */
/* @0x2b313c ldr r12, [r3] */
/* @0x2b3140 ldr r2, [r3, #0x54] */
/* @0x2b3144 ldr r6, [r3, #0xa8] */
/* @0x2b3148 cmp r12, #1 */
/* @0x2b314c cmpeq r2, #2 */
/* @0x2b3150 bne 0x2b315c <jpeg_consume_input+0x254> */
/* @0x2b3154 cmp r6, #3 */
/* @0x2b3158 beq 0x2b3198 <jpeg_consume_input+0x290> */
/* @0x2b315c cmp r12, #82 */
/* @0x2b3160 cmpeq r2, #71 */
/* @0x2b3164 bne 0x2b3170 <jpeg_consume_input+0x268> */
/* @0x2b3168 cmp r6, #66 */
/* @0x2b316c beq 0x2b31ac <jpeg_consume_input+0x2a4> */
/* @0x2b3170 ldr r3, [r4] */
/* @0x2b3174 mov lr, #111 */
/* @0x2b3178 mov r0, r4 */
/* @0x2b317c mov r1, #1 */
/* @0x2b3180 str r12, [r3, #0x18] */
/* @0x2b3184 str r2, [r3, #0x1c] */
/* @0x2b3188 str r6, [r3, #0x20] */
/* @0x2b318c str lr, [r3, #0x14] */
/* @0x2b3190 ldr r3, [r3, #0x4] */
/* @0x2b3194 blx r3 */
/* @0x2b3198 mov r3, #3 */
/* @0x2b319c str r3, [r4, #0x28] */
/* @0x2b31a0 b 0x2b30d0 <jpeg_consume_input+0x1c8> */
/* @0x2b31a4 str r6, [r4, #0x28] */
/* @0x2b31a8 b 0x2b312c <jpeg_consume_input+0x224> */
/* @0x2b31ac mov r3, #2 */
/* @0x2b31b0 str r3, [r4, #0x28] */
/* @0x2b31b4 b 0x2b30d0 <jpeg_consume_input+0x1c8> */

/* ── FUNC 0x2b31b8 · jpeg_read_header · size=136 · insn=34 */
/* @0x2b31b8 ldr r3, [r0, #0x14] */
/* @0x2b31bc push {r4, r5, r6, lr} */
/* @0x2b31c0 sub r2, r3, #200 */
/* @0x2b31c4 cmp r2, #1 */
/* @0x2b31c8 mov r4, r0 */
/* @0x2b31cc mov r6, r1 */
/* @0x2b31d0 bls 0x2b31f0 <jpeg_read_header+0x38> */
/* @0x2b31d4 ldr r2, [r0] */
/* @0x2b31d8 mov r1, #20 */
/* @0x2b31dc str r3, [r2, #0x18] */
/* @0x2b31e0 ldr r3, [r0] */
/* @0x2b31e4 str r1, [r2, #0x14] */
/* @0x2b31e8 ldr r3, [r3] */
/* @0x2b31ec blx r3 */
/* @0x2b31f0 mov r0, r4 */
/* @0x2b31f4 bl 0x2b2f08 <jpeg_consume_input> */
/* @0x2b31f8 cmp r0, #2 */
/* @0x2b31fc mov r5, r0 */
/* @0x2b3200 beq 0x2b320c <jpeg_read_header+0x54> */
/* @0x2b3204 mov r0, r5 */
/* @0x2b3208 pop {r4, r5, r6, pc} */
/* @0x2b320c cmp r6, #0 */
/* @0x2b3210 bne 0x2b3224 <jpeg_read_header+0x6c> */
/* @0x2b3214 mov r0, r4 */
/* @0x2b3218 bl 0x2bc874 <jpeg_abort> */
/* @0x2b321c mov r0, r5 */
/* @0x2b3220 pop {r4, r5, r6, pc} */
/* @0x2b3224 ldr r3, [r4] */
/* @0x2b3228 mov r2, #51 */
/* @0x2b322c mov r0, r4 */
/* @0x2b3230 str r2, [r3, #0x14] */
/* @0x2b3234 ldr r3, [r3] */
/* @0x2b3238 blx r3 */
/* @0x2b323c b 0x2b3214 <jpeg_read_header+0x5c> */

/* ── FUNC 0x2b3240 · jpeg_input_complete · size=64 · insn=16 */
/* @0x2b3240 ldr r3, [r0, #0x14] */
/* @0x2b3244 push {r4, lr} */
/* @0x2b3248 sub r2, r3, #200 */
/* @0x2b324c cmp r2, #10 */
/* @0x2b3250 mov r4, r0 */
/* @0x2b3254 bls 0x2b3274 <jpeg_input_complete+0x34> */
/* @0x2b3258 ldr r2, [r0] */
/* @0x2b325c mov r1, #20 */
/* @0x2b3260 str r3, [r2, #0x18] */
/* @0x2b3264 ldr r3, [r0] */
/* @0x2b3268 str r1, [r2, #0x14] */
/* @0x2b326c ldr r3, [r3] */
/* @0x2b3270 blx r3 */
/* @0x2b3274 ldr r3, [r4, #0x190] */
/* @0x2b3278 ldrb r0, [r3, #0x11] */
/* @0x2b327c pop {r4, pc} */

/* ── FUNC 0x2b3280 · jpeg_has_multiple_scans · size=64 · insn=16 */
/* @0x2b3280 ldr r3, [r0, #0x14] */
/* @0x2b3284 push {r4, lr} */
/* @0x2b3288 sub r2, r3, #202 */
/* @0x2b328c cmp r2, #8 */
/* @0x2b3290 mov r4, r0 */
/* @0x2b3294 bls 0x2b32b4 <jpeg_has_multiple_scans+0x34> */
/* @0x2b3298 ldr r2, [r0] */
/* @0x2b329c mov r1, #20 */
/* @0x2b32a0 str r3, [r2, #0x18] */
/* @0x2b32a4 ldr r3, [r0] */
/* @0x2b32a8 str r1, [r2, #0x14] */
/* @0x2b32ac ldr r3, [r3] */
/* @0x2b32b0 blx r3 */
/* @0x2b32b4 ldr r3, [r4, #0x190] */
/* @0x2b32b8 ldrb r0, [r3, #0x10] */
/* @0x2b32bc pop {r4, pc} */

/* ── FUNC 0x2b32c0 · jpeg_finish_decompress · size=228 · insn=57 */
/* @0x2b32c0 ldr r3, [r0, #0x14] */
/* @0x2b32c4 push {r4, lr} */
/* @0x2b32c8 sub r2, r3, #205 */
/* @0x2b32cc cmp r2, #1 */
/* @0x2b32d0 mov r4, r0 */
/* @0x2b32d4 bls 0x2b3354 <jpeg_finish_decompress+0x94> */
/* @0x2b32d8 cmp r3, #207 */
/* @0x2b32dc moveq r3, #210 */
/* @0x2b32e0 streq r3, [r0, #0x14] */
/* @0x2b32e4 beq 0x2b3324 <jpeg_finish_decompress+0x64> */
/* @0x2b32e8 cmp r3, #210 */
/* @0x2b32ec beq 0x2b3324 <jpeg_finish_decompress+0x64> */
/* @0x2b32f0 ldr r2, [r4] */
/* @0x2b32f4 mov r1, #20 */
/* @0x2b32f8 mov r0, r4 */
/* @0x2b32fc str r3, [r2, #0x18] */
/* @0x2b3300 ldr r3, [r4] */
/* @0x2b3304 str r1, [r2, #0x14] */
/* @0x2b3308 ldr r3, [r3] */
/* @0x2b330c blx r3 */
/* @0x2b3310 b 0x2b3324 <jpeg_finish_decompress+0x64> */
/* @0x2b3314 ldr r3, [r3] */
/* @0x2b3318 blx r3 */
/* @0x2b331c cmp r0, #0 */
/* @0x2b3320 popeq {r4, pc} */
/* @0x2b3324 ldr r3, [r4, #0x190] */
/* @0x2b3328 mov r0, r4 */
/* @0x2b332c ldrb r2, [r3, #0x11] */
/* @0x2b3330 cmp r2, #0 */
/* @0x2b3334 beq 0x2b3314 <jpeg_finish_decompress+0x54> */
/* @0x2b3338 ldr r3, [r4, #0x18] */
/* @0x2b333c ldr r3, [r3, #0x18] */
/* @0x2b3340 blx r3 */
/* @0x2b3344 mov r0, r4 */
/* @0x2b3348 bl 0x2bc874 <jpeg_abort> */
/* @0x2b334c mov r0, #1 */
/* @0x2b3350 pop {r4, pc} */
/* @0x2b3354 ldrb r2, [r0, #0x40] */
/* @0x2b3358 cmp r2, #0 */
/* @0x2b335c bne 0x2b32f0 <jpeg_finish_decompress+0x30> */
/* @0x2b3360 ldr r2, [r0, #0x78] */
/* @0x2b3364 ldr r3, [r0, #0x60] */
/* @0x2b3368 cmp r2, r3 */
/* @0x2b336c blo 0x2b338c <jpeg_finish_decompress+0xcc> */
/* @0x2b3370 ldr r3, [r4, #0x180] */
/* @0x2b3374 mov r0, r4 */
/* @0x2b3378 ldr r3, [r3, #0x4] */
/* @0x2b337c blx r3 */
/* @0x2b3380 mov r3, #210 */
/* @0x2b3384 str r3, [r4, #0x14] */
/* @0x2b3388 b 0x2b3324 <jpeg_finish_decompress+0x64> */
/* @0x2b338c ldr r3, [r0] */
/* @0x2b3390 mov r1, #67 */
/* @0x2b3394 ldr r2, [r3] */
/* @0x2b3398 str r1, [r3, #0x14] */
/* @0x2b339c blx r2 */
/* @0x2b33a0 b 0x2b3370 <jpeg_finish_decompress+0xb0> */
