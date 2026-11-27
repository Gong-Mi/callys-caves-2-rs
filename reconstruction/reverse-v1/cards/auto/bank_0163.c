/* libyoyo.so 覆盖卡组 0163
 * 函数 0x1e11a8..0x1e2b08，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1e11a8 · F_Shader_Set_Texture(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x1e11a8 push {r4, r5, r6, lr} */
/* @0x1e11ac mov r1, #1 */
/* @0x1e11b0 ldr r6, [sp, #0x10] */
/* @0x1e11b4 mov r0, r6 */
/* @0x1e11b8 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x1e11bc mov r4, r0 */
/* @0x1e11c0 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e11c4 mov r0, r4 */
/* @0x1e11c8 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1e11cc cmp r0, #0 */
/* @0x1e11d0 bne 0x1e1240 <_Z20F_Shader_Set_TextureR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1e11d4 cmn r4, #1 */
/* @0x1e11d8 beq 0x1e11f0 <_Z20F_Shader_Set_TextureR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1e11dc ldr r5, [pc, #0x68] */
/* @0x1e11e0 ldr r5, [pc, r5] */
/* @0x1e11e4 ldr r3, [r5] */
/* @0x1e11e8 cmp r4, r3 */
/* @0x1e11ec bhs 0x1e1208 <_Z20F_Shader_Set_TextureR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x1e11f0 mov r0, r6 */
/* @0x1e11f4 mov r1, #0 */
/* @0x1e11f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e11fc mov r1, #0 */
/* @0x1e1200 pop {r4, r5, r6, lr} */
/* @0x1e1204 b 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x1e1208 ldrsh r4, [r4, #20] */
/* @0x1e120c mov r0, r4 */
/* @0x1e1210 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1e1214 cmp r0, #0 */
/* @0x1e1218 popeq {r4, r5, r6, pc} */
/* @0x1e121c ldr r3, [r5, #0x4] */
/* @0x1e1220 mov r0, r6 */
/* @0x1e1224 mov r1, #0 */
/* @0x1e1228 ldr r3, [r3, r4, lsl #2] */
/* @0x1e122c ldr r4, [r3] */
/* @0x1e1230 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e1234 mov r1, r4 */
/* @0x1e1238 pop {r4, r5, r6, lr} */
/* @0x1e123c b 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x1e1240 ldr r5, [pc, #0x8] */
/* @0x1e1244 ldr r5, [pc, r5] */
/* @0x1e1248 b 0x1e121c <_Z20F_Shader_Set_TextureR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1e124c eoreq r12, r0, r12, lsr r7 */
/* @0x1e1250 .word 0x0020c6d8 */

/* ── FUNC 0x1e1254 · GetShader(int) · size=64 · insn=16 */
/* @0x1e1254 cmp r0, #0 */
/* @0x1e1258 blt 0x1e1284 <_Z9GetShaderi+0x30> */
/* @0x1e125c ldr r3, [pc, #0x28] */
/* @0x1e1260 ldr r3, [pc, r3] */
/* @0x1e1264 ldr r3, [r3] */
/* @0x1e1268 cmp r0, r3 */
/* @0x1e126c bge 0x1e1284 <_Z9GetShaderi+0x30> */
/* @0x1e1270 ldr r3, [pc, #0x18] */
/* @0x1e1274 ldr r3, [pc, r3] */
/* @0x1e1278 ldr r3, [r3] */
/* @0x1e127c ldr r0, [r3, r0, lsl #2] */
/* @0x1e1280 bx lr */
/* @0x1e1284 mov r0, #0 */
/* @0x1e1288 bx lr */
/* @0x1e128c eoreq pc, r0, r4, ror #21 */
/* @0x1e1290 .word 0x0020fad4 */

/* ── FUNC 0x1e1294 · ShaderExists(int) · size=72 · insn=18 */
/* @0x1e1294 cmp r0, #0 */
/* @0x1e1298 blt 0x1e12cc <_Z12ShaderExistsi+0x38> */
/* @0x1e129c ldr r3, [pc, #0x30] */
/* @0x1e12a0 ldr r3, [pc, r3] */
/* @0x1e12a4 ldr r3, [r3] */
/* @0x1e12a8 cmp r0, r3 */
/* @0x1e12ac bge 0x1e12cc <_Z12ShaderExistsi+0x38> */
/* @0x1e12b0 ldr r3, [pc, #0x20] */
/* @0x1e12b4 ldr r3, [pc, r3] */
/* @0x1e12b8 ldr r3, [r3] */
/* @0x1e12bc ldr r0, [r3, r0, lsl #2] */
/* @0x1e12c0 adds r0, r0, #0 */
/* @0x1e12c4 movne r0, #1 */
/* @0x1e12c8 bx lr */
/* @0x1e12cc mov r0, #0 */
/* @0x1e12d0 bx lr */
/* @0x1e12d4 eoreq pc, r0, r4, lsr #21 */
/* @0x1e12d8 mlaeq r0, r4, r10, pc */

/* ── FUNC 0x1e12dc · Shader_Find(char const*) · size=116 · insn=29 */
/* @0x1e12dc push {r3, r4, r5, r6, r7, lr} */
/* @0x1e12e0 mov r7, r0 */
/* @0x1e12e4 ldr r3, [pc, #0x5c] */
/* @0x1e12e8 ldr r3, [pc, r3] */
/* @0x1e12ec ldr r6, [r3] */
/* @0x1e12f0 cmp r6, #0 */
/* @0x1e12f4 ble 0x1e1338 <_Z11Shader_FindPKc+0x5c> */
/* @0x1e12f8 ldr r3, [pc, #0x4c] */
/* @0x1e12fc mov r4, #0 */
/* @0x1e1300 ldr r3, [pc, r3] */
/* @0x1e1304 ldr r5, [r3] */
/* @0x1e1308 sub r5, r5, #4 */
/* @0x1e130c ldr r3, [r5, #0x4]! */
/* @0x1e1310 mov r1, r7 */
/* @0x1e1314 cmp r3, #0 */
/* @0x1e1318 beq 0x1e132c <_Z11Shader_FindPKc+0x50> */
/* @0x1e131c ldr r0, [r3, #0x4] */
/* @0x1e1320 bl 0xb6574 <strcmp@plt> */
/* @0x1e1324 cmp r0, #0 */
/* @0x1e1328 beq 0x1e1340 <_Z11Shader_FindPKc+0x64> */
/* @0x1e132c add r4, r4, #1 */
/* @0x1e1330 cmp r4, r6 */
/* @0x1e1334 bne 0x1e130c <_Z11Shader_FindPKc+0x30> */
/* @0x1e1338 mvn r0, #0 */
/* @0x1e133c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1e1340 mov r0, r4 */
/* @0x1e1344 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1e1348 eoreq pc, r0, r12, asr r10 */
/* @0x1e134c eoreq pc, r0, r8, asr #20 */

/* ── FUNC 0x1e1350 · AddShader(char*, int, char*, char*, char*, char*, char*, char*, char*, char*, char*, int, char*, int, char*, int, char*, int, char*, char*, int, unsigned int*) · size=464 · insn=116 */
/* @0x1e1350 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e1354 sub sp, sp, #20 */
/* @0x1e1358 ldr lr, [pc, #0x1b0] */
/* @0x1e135c mov r12, r2 */
/* @0x1e1360 ldr r5, [pc, #0x1ac] */
/* @0x1e1364 mov r7, #0 */
/* @0x1e1368 ldr lr, [pc, lr] */
/* @0x1e136c str r1, [sp, #0xc] */
/* @0x1e1370 ldr r5, [pc, r5] */
/* @0x1e1374 ldr r2, [pc, #0x19c] */
/* @0x1e1378 ldr r9, [lr] */
/* @0x1e137c mov r11, r3 */
/* @0x1e1380 add r2, pc, r2 */
/* @0x1e1384 mov r3, #74 */
/* @0x1e1388 add r1, r9, #1 */
/* @0x1e138c mov r10, r0 */
/* @0x1e1390 str r1, [lr] */
/* @0x1e1394 ldr r0, [r5] */
/* @0x1e1398 lsl r1, r1, #2 */
/* @0x1e139c str r7, [sp] */
/* @0x1e13a0 sub r6, r1, #4 */
/* @0x1e13a4 ldr r8, [sp, #0x78] */
/* @0x1e13a8 str r12, [sp, #0x8] */
/* @0x1e13ac ldr r4, [sp, #0x7c] */
/* @0x1e13b0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1e13b4 str r0, [r5] */
/* @0x1e13b8 mov r0, #132 */
/* @0x1e13bc bl 0x27c524 <_Znwj> */
/* @0x1e13c0 ldr r12, [sp, #0x8] */
/* @0x1e13c4 ldr r2, [r5] */
/* @0x1e13c8 mvn r3, #0 */
/* @0x1e13cc mov r1, #1 */
/* @0x1e13d0 cmp r8, #532676608 */
/* @0x1e13d4 str r12, [r0, #0xc] */
/* @0x1e13d8 ldr r12, [sp, #0x38] */
/* @0x1e13dc str r11, [r0, #0x10] */
/* @0x1e13e0 str r12, [r0, #0x14] */
/* @0x1e13e4 ldr r12, [sp, #0x3c] */
/* @0x1e13e8 str r12, [r0, #0x18] */
/* @0x1e13ec ldr r12, [sp, #0x40] */
/* @0x1e13f0 str r12, [r0, #0x1c] */
/* @0x1e13f4 ldr r12, [sp, #0x44] */
/* @0x1e13f8 str r12, [r0, #0x20] */
/* @0x1e13fc ldr r12, [sp, #0x48] */
/* @0x1e1400 str r12, [r0, #0x24] */
/* @0x1e1404 ldr r12, [sp, #0x4c] */
/* @0x1e1408 str r12, [r0, #0x28] */
/* @0x1e140c ldr r12, [sp, #0x50] */
/* @0x1e1410 str r12, [r0, #0x2c] */
/* @0x1e1414 ldr r12, [sp, #0x54] */
/* @0x1e1418 str r12, [r0, #0x44] */
/* @0x1e141c ldr r12, [sp, #0x58] */
/* @0x1e1420 str r12, [r0, #0x30] */
/* @0x1e1424 ldr r12, [sp, #0x5c] */
/* @0x1e1428 str r12, [r0, #0x48] */
/* @0x1e142c ldr r12, [sp, #0x60] */
/* @0x1e1430 str r12, [r0, #0x34] */
/* @0x1e1434 ldr r12, [sp, #0x64] */
/* @0x1e1438 str r12, [r0, #0x4c] */
/* @0x1e143c ldr r12, [sp, #0x68] */
/* @0x1e1440 str r12, [r0, #0x38] */
/* @0x1e1444 ldr r12, [sp, #0x6c] */
/* @0x1e1448 str r12, [r0, #0x50] */
/* @0x1e144c ldr r12, [sp, #0x70] */
/* @0x1e1450 str r12, [r0, #0x3c] */
/* @0x1e1454 ldr r12, [sp, #0x74] */
/* @0x1e1458 str r3, [r0, #0x64] */
/* @0x1e145c str r7, [r0, #0x4] */
/* @0x1e1460 str r12, [r0, #0x40] */
/* @0x1e1464 str r7, [r0, #0x54] */
/* @0x1e1468 str r7, [r0, #0x60] */
/* @0x1e146c str r7, [r0, #0x5c] */
/* @0x1e1470 str r3, [r0] */
/* @0x1e1474 str r1, [r0, #0x8] */
/* @0x1e1478 str r0, [r2, r6] */
/* @0x1e147c movhi r0, r3 */
/* @0x1e1480 ldr r2, [r5] */
/* @0x1e1484 lslls r0, r8, #2 */
/* @0x1e1488 ldr r7, [r2, r6] */
/* @0x1e148c str r8, [r7, #0x5c] */
/* @0x1e1490 bl 0x27d14c <_Znaj> */
/* @0x1e1494 ldr r3, [r5] */
/* @0x1e1498 cmp r8, #0 */
/* @0x1e149c add r2, r3, r6 */
/* @0x1e14a0 str r0, [r7, #0x60] */
/* @0x1e14a4 ldr r3, [r3, r6] */
/* @0x1e14a8 ldr r12, [r3, #0x60] */
/* @0x1e14ac ble 0x1e14f0 <_Z9AddShaderPciS_S_S_S_S_S_S_S_S_iS_iS_iS_iS_S_iPj+0x1a0> */
/* @0x1e14b0 lsl r8, r8, #2 */
/* @0x1e14b4 mov r3, #0 */
/* @0x1e14b8 ldr r2, [r4, r3] */
/* @0x1e14bc ldr r0, [pc, #0x58] */
/* @0x1e14c0 cmp r2, #0 */
/* @0x1e14c4 ldrne r0, [pc, r0] */
/* @0x1e14c8 mov r1, r2 */
/* @0x1e14cc ldrne r1, [r0] */
/* @0x1e14d0 addne r1, r1, r2 */
/* @0x1e14d4 str r1, [r12, r3] */
/* @0x1e14d8 add r3, r3, #4 */
/* @0x1e14dc cmp r3, r8 */
/* @0x1e14e0 bne 0x1e14b8 <_Z9AddShaderPciS_S_S_S_S_S_S_S_S_iS_iS_iS_iS_S_iPj+0x168> */
/* @0x1e14e4 ldr r3, [r5] */
/* @0x1e14e8 add r2, r3, r6 */
/* @0x1e14ec ldr r3, [r3, r6] */
/* @0x1e14f0 str r10, [r3, #0x4] */
/* @0x1e14f4 ldr r12, [sp, #0xc] */
/* @0x1e14f8 ldr r2, [r2] */
/* @0x1e14fc str r9, [r3] */
/* @0x1e1500 mov r0, r2 */
/* @0x1e1504 str r12, [r2, #0x8] */
/* @0x1e1508 add sp, sp, #20 */
/* @0x1e150c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e1510 .word 0x0020f9dc */
/* @0x1e1514 .word 0x0020f9d8 */
/* @0x1e1518 ldrheq pc, [r4], -r0 */
/* @0x1e151c eoreq r12, r0, r0, lsl #9 */

/* ── FUNC 0x1e1520 · FlushShader() · size=540 · insn=135 */
/* @0x1e1520 push {r4, r5, lr} */
/* @0x1e1524 sub sp, sp, #172 */
/* @0x1e1528 ldr r4, [pc, #0x1dc] */
/* @0x1e152c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e1530 ldr r1, [pc, #0x1d8] */
/* @0x1e1534 mov r0, #0 */
/* @0x1e1538 add r4, pc, r4 */
/* @0x1e153c ldr r3, [pc, #0x1d0] */
/* @0x1e1540 ldr r2, [pc, #0x1d0] */
/* @0x1e1544 ldr r1, [r4, r1] */
/* @0x1e1548 strb r0, [r1] */
/* @0x1e154c ldr r3, [r4, r3] */
/* @0x1e1550 ldr r5, [r4, r2] */
/* @0x1e1554 ldr r3, [r3] */
/* @0x1e1558 mov r0, r3 */
/* @0x1e155c str r3, [r5] */
/* @0x1e1560 bl 0x188650 <_Z9SetShaderP6Shader> */
/* @0x1e1564 ldr r3, [r5] */
/* @0x1e1568 cmp r3, #0 */
/* @0x1e156c beq 0x1e16f4 <_Z11FlushShaderv+0x1d4> */
/* @0x1e1570 ldr r2, [pc, #0x1a4] */
/* @0x1e1574 mov r1, #5 */
/* @0x1e1578 ldr r0, [r3, #0x6c] */
/* @0x1e157c ldr r2, [r4, r2] */
/* @0x1e1580 bl 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf> */
/* @0x1e1584 ldr r3, [pc, #0x194] */
/* @0x1e1588 ldr r12, [r5] */
/* @0x1e158c add r2, sp, #52 */
/* @0x1e1590 ldr r1, [pc, #0x18c] */
/* @0x1e1594 ldr r0, [r4, r3] */
/* @0x1e1598 ldr lr, [r12, #0x68] */
/* @0x1e159c ldr r3, [pc, #0x184] */
/* @0x1e15a0 str lr, [r0] */
/* @0x1e15a4 ldr r1, [r4, r1] */
/* @0x1e15a8 ldr r3, [r4, r3] */
/* @0x1e15ac add r0, r1, #32 */
/* @0x1e15b0 add r3, r3, #12 */
/* @0x1e15b4 vldmia r1!, {s15} */
/* @0x1e15b8 mov lr, r3 */
/* @0x1e15bc vldr s11, [r3, #-12] */
/* @0x1e15c0 vldr s12, [r3, #-8] */
/* @0x1e15c4 vldr s14, [r3, #-4] */
/* @0x1e15c8 vldr s13, [lr] */
/* @0x1e15cc vmul.f32 s11, s11, s15 */
/* @0x1e15d0 cmp r1, r0 */
/* @0x1e15d4 add r3, r3, #16 */
/* @0x1e15d8 vmul.f32 s12, s12, s15 */
/* @0x1e15dc vstr s11, [r2, #-12] */
/* @0x1e15e0 vmul.f32 s14, s14, s15 */
/* @0x1e15e4 vstr s12, [r2, #-8] */
/* @0x1e15e8 vmul.f32 s15, s13, s15 */
/* @0x1e15ec vstr s14, [r2, #-4] */
/* @0x1e15f0 vmov lr, s15 */
/* @0x1e15f4 str lr, [r2], #16 */
/* @0x1e15f8 bne 0x1e15b4 <_Z11FlushShaderv+0x94> */
/* @0x1e15fc ldr r3, [pc, #0x128] */
/* @0x1e1600 vldr s15, [pc, #256] */
/* @0x1e1604 ldr r0, [r12, #0x7c] */
/* @0x1e1608 add r2, sp, #24 */
/* @0x1e160c mov r1, #4 */
/* @0x1e1610 ldr r3, [r4, r3] */
/* @0x1e1614 ldr r3, [r3] */
/* @0x1e1618 ubfx r12, r3, #0x8, #0x8 */
/* @0x1e161c ubfx lr, r3, #0x10, #0x8 */
/* @0x1e1620 vmov s12, r12 */
/* @0x1e1624 uxtb r12, r3 */
/* @0x1e1628 lsr r3, r3, #24 */
/* @0x1e162c vmov s14, lr */
/* @0x1e1630 vmov s11, r12 */
/* @0x1e1634 vmov s10, r3 */
/* @0x1e1638 vcvt.f32.s32 s12, s12 */
/* @0x1e163c vcvt.f32.u32 s13, s10 */
/* @0x1e1640 vcvt.f32.s32 s11, s11 */
/* @0x1e1644 vcvt.f32.s32 s14, s14 */
/* @0x1e1648 vdiv.f32 s11, s11, s15 */
/* @0x1e164c vdiv.f32 s12, s12, s15 */
/* @0x1e1650 vstr s11, [sp, #24] */
/* @0x1e1654 vdiv.f32 s14, s14, s15 */
/* @0x1e1658 vstr s12, [sp, #28] */
/* @0x1e165c vdiv.f32 s15, s13, s15 */
/* @0x1e1660 vstr s14, [sp, #32] */
/* @0x1e1664 vstr s15, [sp, #36] */
/* @0x1e1668 bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf> */
/* @0x1e166c ldr r3, [r5] */
/* @0x1e1670 mov r1, #32 */
/* @0x1e1674 ldr r2, [pc, #0xb4] */
/* @0x1e1678 ldr r0, [r3, #0x70] */
/* @0x1e167c ldr r2, [r4, r2] */
/* @0x1e1680 bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf> */
/* @0x1e1684 ldr r3, [r5] */
/* @0x1e1688 add r2, sp, #40 */
/* @0x1e168c mov r1, #32 */
/* @0x1e1690 ldr r0, [r3, #0x78] */
/* @0x1e1694 bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf> */
/* @0x1e1698 ldr r3, [r5] */
/* @0x1e169c ldr r2, [pc, #0x90] */
/* @0x1e16a0 mov r1, #32 */
/* @0x1e16a4 ldr r0, [r3, #0x74] */
/* @0x1e16a8 ldr r2, [r4, r2] */
/* @0x1e16ac bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf> */
/* @0x1e16b0 ldr r12, [pc, #0x80] */
/* @0x1e16b4 ldr r0, [r5] */
/* @0x1e16b8 mov r2, #0 */
/* @0x1e16bc mov r3, #0 */
/* @0x1e16c0 mov r1, #1 */
/* @0x1e16c4 ldr r12, [r4, r12] */
/* @0x1e16c8 ldr r0, [r0, #0x80] */
/* @0x1e16cc strd r2, r3, [sp] */
/* @0x1e16d0 strd r2, r3, [sp, #8] */
/* @0x1e16d4 strd r2, r3, [sp, #16] */
/* @0x1e16d8 ldrb r2, [r12] */
/* @0x1e16dc vmov s15, r2 */
/* @0x1e16e0 vcvt.f64.u32 d7, s15 */
/* @0x1e16e4 vmov r2, r3, d7 */
/* @0x1e16e8 bl 0x188b90 <_Z20Shader_Set_Uniform_Biidddd> */
/* @0x1e16ec add sp, sp, #172 */
/* @0x1e16f0 pop {r4, r5, pc} */
/* @0x1e16f4 ldr r2, [pc, #0x24] */
/* @0x1e16f8 ldr r2, [r4, r2] */
/* @0x1e16fc str r3, [r2] */
/* @0x1e1700 add sp, sp, #172 */
/* @0x1e1704 pop {r4, r5, pc} */
/* @0x1e1708 cmnmi pc, #0 */
/* @0x1e170c eoreq r0, r1, r8, lsl r7 */
/* @0x1e1710 .word 0xfffff0fc */
/* @0x1e1714 .word 0xfffff0f0 */
/* @0x1e1718 .word 0xffffe828 */
/* @0x1e171c .word 0xffffe824 */
/* @0x1e1720 .word 0xffffe4d4 */
/* @0x1e1724 .word 0xffffd9d4 */
/* @0x1e1728 .word 0xffffd9d8 */
/* @0x1e172c .word 0xffffd9bc */
/* @0x1e1730 .word 0xffffd9dc */
/* @0x1e1734 .word 0xffffd9d0 */
/* @0x1e1738 .word 0xffffd9c0 */

/* ── FUNC 0x1e173c · anon_1e173c · size=0 · insn=1 */
/* @0x1e173c andeq r0, r0, r0 */

/* ── FUNC 0x1e1740 · F_Shader_Set_Uniform_I(RValue&, CInstance*, CInstance*, int, RValue*) · size=260 · insn=63 */
/* @0x1e1740 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e1744 sub sp, sp, #36 */
/* @0x1e1748 mov r10, r3 */
/* @0x1e174c ldr r11, [sp, #0x48] */
/* @0x1e1750 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e1754 ldr r3, [pc, #0xe4] */
/* @0x1e1758 ldr r3, [pc, r3] */
/* @0x1e175c ldrb r3, [r3] */
/* @0x1e1760 cmp r3, #0 */
/* @0x1e1764 bne 0x1e182c <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1e1768 cmp r10, #1 */
/* @0x1e176c ble 0x1e17e0 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1e1770 mov r0, r11 */
/* @0x1e1774 mov r1, #1 */
/* @0x1e1778 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1e177c cmp r10, #2 */
/* @0x1e1780 strd r0, r1, [sp, #24] */
/* @0x1e1784 beq 0x1e17e8 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1e1788 mov r0, r11 */
/* @0x1e178c mov r1, #2 */
/* @0x1e1790 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1e1794 cmp r10, #3 */
/* @0x1e1798 mov r8, r0 */
/* @0x1e179c mov r9, r1 */
/* @0x1e17a0 beq 0x1e17f0 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x1e17a4 mov r0, r11 */
/* @0x1e17a8 mov r1, #3 */
/* @0x1e17ac bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1e17b0 cmp r10, #4 */
/* @0x1e17b4 moveq r6, #0 */
/* @0x1e17b8 moveq r7, #0 */
/* @0x1e17bc mov r4, r0 */
/* @0x1e17c0 mov r5, r1 */
/* @0x1e17c4 beq 0x1e1800 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1e17c8 mov r0, r11 */
/* @0x1e17cc mov r1, #4 */
/* @0x1e17d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1e17d4 mov r6, r0 */
/* @0x1e17d8 mov r7, r1 */
/* @0x1e17dc b 0x1e1800 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1e17e0 vldr d7, [pc, #80] */
/* @0x1e17e4 vstr d7, [sp, #24] */
/* @0x1e17e8 mov r8, #0 */
/* @0x1e17ec mov r9, #0 */
/* @0x1e17f0 mov r4, #0 */
/* @0x1e17f4 mov r5, #0 */
/* @0x1e17f8 mov r6, r4 */
/* @0x1e17fc mov r7, r5 */
/* @0x1e1800 mov r0, r11 */
/* @0x1e1804 mov r1, #0 */
/* @0x1e1808 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e180c strd r8, r9, [sp] */
/* @0x1e1810 strd r4, r5, [sp, #8] */
/* @0x1e1814 sub r1, r10, #1 */
/* @0x1e1818 strd r6, r7, [sp, #16] */
/* @0x1e181c ldrd r2, r3, [sp, #24] */
/* @0x1e1820 bl 0x188680 <_Z20Shader_Set_Uniform_Iiidddd> */
/* @0x1e1824 add sp, sp, #36 */
/* @0x1e1828 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e182c bl 0x1e1520 <_Z11FlushShaderv> */
/* @0x1e1830 b 0x1e1768 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1e1834 nop */
/* @0x1e1840 .word 0x0020f5f4 */

/* ── FUNC 0x1e1844 · anon_1e1844 · size=0 · insn=1 */
/* @0x1e1844 nop */

/* ── FUNC 0x1e1848 · F_Shader_Set_Uniform_I_Array(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x1e1848 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e184c add r11, sp, #32 */
/* @0x1e1850 sub sp, sp, #12 */
/* @0x1e1854 ldr r6, [pc, #0xec] */
/* @0x1e1858 ldr r9, [r11, #0x4] */
/* @0x1e185c ldr r6, [pc, r6] */
/* @0x1e1860 ldr r3, [r6] */
/* @0x1e1864 ldr r2, [r9, #0x1c] */
/* @0x1e1868 cmp r2, #2 */
/* @0x1e186c str r3, [r11, #-0x28] */
/* @0x1e1870 beq 0x1e189c <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1e1874 ldr r0, [pc, #0xd0] */
/* @0x1e1878 mov r1, #0 */
/* @0x1e187c add r0, pc, r0 */
/* @0x1e1880 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e1884 ldr r2, [r11, #-0x28] */
/* @0x1e1888 ldr r3, [r6] */
/* @0x1e188c cmp r2, r3 */
/* @0x1e1890 bne 0x1e1944 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1e1894 sub sp, r11, #32 */
/* @0x1e1898 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e189c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e18a0 ldr r3, [pc, #0xa8] */
/* @0x1e18a4 ldr r3, [pc, r3] */
/* @0x1e18a8 ldrb r3, [r3] */
/* @0x1e18ac cmp r3, #0 */
/* @0x1e18b0 bne 0x1e193c <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1e18b4 ldr r3, [r9, #0x10] */
/* @0x1e18b8 ldr r3, [r3, #0x4] */
/* @0x1e18bc ldr r8, [r3] */
/* @0x1e18c0 cmp r8, #0 */
/* @0x1e18c4 beq 0x1e1928 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x1e18c8 lsl r2, r8, #2 */
/* @0x1e18cc ldr r4, [r3, #0x4] */
/* @0x1e18d0 add r3, r2, #14 */
/* @0x1e18d4 movgt r5, #0 */
/* @0x1e18d8 bic r3, r3, #7 */
/* @0x1e18dc sub sp, sp, r3 */
/* @0x1e18e0 subgt r7, sp, #4 */
/* @0x1e18e4 mov r10, sp */
/* @0x1e18e8 ble 0x1e190c <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x1e18ec mov r0, r4 */
/* @0x1e18f0 mov r1, #0 */
/* @0x1e18f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e18f8 add r5, r5, #1 */
/* @0x1e18fc cmp r5, r8 */
/* @0x1e1900 add r4, r4, #16 */
/* @0x1e1904 str r0, [r7, #0x4]! */
/* @0x1e1908 bne 0x1e18ec <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1e190c mov r0, r9 */
/* @0x1e1910 mov r1, #0 */
/* @0x1e1914 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e1918 mov r1, r8 */
/* @0x1e191c mov r2, r10 */
/* @0x1e1920 bl 0x188794 <_Z21Shader_Set_Uniform_IAiiPi> */
/* @0x1e1924 b 0x1e1884 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1e1928 ldr r0, [pc, #0x24] */
/* @0x1e192c mov r1, r8 */
/* @0x1e1930 add r0, pc, r0 */
/* @0x1e1934 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e1938 b 0x1e1884 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1e193c bl 0x1e1520 <_Z11FlushShaderv> */
/* @0x1e1940 b 0x1e18b4 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1e1944 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1e1948 .word 0x0020c0f4 */
/* @0x1e194c andseq r1, r6, r0, lsr r1 */
/* @0x1e1950 eoreq pc, r0, r8, lsr #9 */
/* @0x1e1954 andseq r0, r7, r12, asr r4 */

/* ── FUNC 0x1e1958 · F_Shader_Set_Uniform_F(RValue&, CInstance*, CInstance*, int, RValue*) · size=260 · insn=63 */
/* @0x1e1958 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e195c sub sp, sp, #36 */
/* @0x1e1960 mov r10, r3 */
/* @0x1e1964 ldr r11, [sp, #0x48] */
/* @0x1e1968 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e196c ldr r3, [pc, #0xe4] */
/* @0x1e1970 ldr r3, [pc, r3] */
/* @0x1e1974 ldrb r3, [r3] */
/* @0x1e1978 cmp r3, #0 */
/* @0x1e197c bne 0x1e1a44 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1e1980 cmp r10, #1 */
/* @0x1e1984 ble 0x1e19f8 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1e1988 mov r0, r11 */
/* @0x1e198c mov r1, #1 */
/* @0x1e1990 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1e1994 cmp r10, #2 */
/* @0x1e1998 strd r0, r1, [sp, #24] */
/* @0x1e199c beq 0x1e1a00 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1e19a0 mov r0, r11 */
/* @0x1e19a4 mov r1, #2 */
/* @0x1e19a8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1e19ac cmp r10, #3 */
/* @0x1e19b0 mov r8, r0 */
/* @0x1e19b4 mov r9, r1 */
/* @0x1e19b8 beq 0x1e1a08 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x1e19bc mov r0, r11 */
/* @0x1e19c0 mov r1, #3 */
/* @0x1e19c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1e19c8 cmp r10, #4 */
/* @0x1e19cc moveq r6, #0 */
/* @0x1e19d0 moveq r7, #0 */
/* @0x1e19d4 mov r4, r0 */
/* @0x1e19d8 mov r5, r1 */
/* @0x1e19dc beq 0x1e1a18 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1e19e0 mov r0, r11 */
/* @0x1e19e4 mov r1, #4 */
/* @0x1e19e8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1e19ec mov r6, r0 */
/* @0x1e19f0 mov r7, r1 */
/* @0x1e19f4 b 0x1e1a18 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1e19f8 vldr d7, [pc, #80] */
/* @0x1e19fc vstr d7, [sp, #24] */
/* @0x1e1a00 mov r8, #0 */
/* @0x1e1a04 mov r9, #0 */
/* @0x1e1a08 mov r4, #0 */
/* @0x1e1a0c mov r5, #0 */
/* @0x1e1a10 mov r6, r4 */
/* @0x1e1a14 mov r7, r5 */
/* @0x1e1a18 mov r0, r11 */
/* @0x1e1a1c mov r1, #0 */
/* @0x1e1a20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e1a24 strd r8, r9, [sp] */
/* @0x1e1a28 strd r4, r5, [sp, #8] */
/* @0x1e1a2c sub r1, r10, #1 */
/* @0x1e1a30 strd r6, r7, [sp, #16] */
/* @0x1e1a34 ldrd r2, r3, [sp, #24] */
/* @0x1e1a38 bl 0x1888f0 <_Z20Shader_Set_Uniform_Fiidddd> */
/* @0x1e1a3c add sp, sp, #36 */
/* @0x1e1a40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e1a44 bl 0x1e1520 <_Z11FlushShaderv> */
/* @0x1e1a48 b 0x1e1980 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1e1a4c nop */
/* @0x1e1a58 .word 0x0020f3dc */

/* ── FUNC 0x1e1a5c · anon_1e1a5c · size=0 · insn=1 */
/* @0x1e1a5c nop */

/* ── FUNC 0x1e1a60 · F_Shader_Set_Uniform_F_Array(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x1e1a60 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e1a64 add r11, sp, #32 */
/* @0x1e1a68 sub sp, sp, #12 */
/* @0x1e1a6c ldr r6, [pc, #0xec] */
/* @0x1e1a70 ldr r9, [r11, #0x4] */
/* @0x1e1a74 ldr r6, [pc, r6] */
/* @0x1e1a78 ldr r3, [r6] */
/* @0x1e1a7c ldr r2, [r9, #0x1c] */
/* @0x1e1a80 cmp r2, #2 */
/* @0x1e1a84 str r3, [r11, #-0x28] */
/* @0x1e1a88 beq 0x1e1ab4 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1e1a8c ldr r0, [pc, #0xd0] */
/* @0x1e1a90 mov r1, #0 */
/* @0x1e1a94 add r0, pc, r0 */
/* @0x1e1a98 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e1a9c ldr r2, [r11, #-0x28] */
/* @0x1e1aa0 ldr r3, [r6] */
/* @0x1e1aa4 cmp r2, r3 */
/* @0x1e1aa8 bne 0x1e1b5c <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1e1aac sub sp, r11, #32 */
/* @0x1e1ab0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e1ab4 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e1ab8 ldr r3, [pc, #0xa8] */
/* @0x1e1abc ldr r3, [pc, r3] */
/* @0x1e1ac0 ldrb r3, [r3] */
/* @0x1e1ac4 cmp r3, #0 */
/* @0x1e1ac8 bne 0x1e1b54 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1e1acc ldr r3, [r9, #0x10] */
/* @0x1e1ad0 ldr r3, [r3, #0x4] */
/* @0x1e1ad4 ldr r8, [r3] */
/* @0x1e1ad8 cmp r8, #0 */
/* @0x1e1adc beq 0x1e1b40 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x1e1ae0 lsl r2, r8, #2 */
/* @0x1e1ae4 ldr r4, [r3, #0x4] */
/* @0x1e1ae8 add r3, r2, #14 */
/* @0x1e1aec movgt r5, #0 */
/* @0x1e1af0 bic r3, r3, #7 */
/* @0x1e1af4 sub sp, sp, r3 */
/* @0x1e1af8 mov r10, sp */
/* @0x1e1afc movgt r7, sp */
/* @0x1e1b00 ble 0x1e1b24 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x1e1b04 mov r0, r4 */
/* @0x1e1b08 mov r1, #0 */
/* @0x1e1b0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1e1b10 add r5, r5, #1 */
/* @0x1e1b14 cmp r5, r8 */
/* @0x1e1b18 add r4, r4, #16 */
/* @0x1e1b1c str r0, [r7], #4 */
/* @0x1e1b20 bne 0x1e1b04 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1e1b24 mov r0, r9 */
/* @0x1e1b28 mov r1, #0 */
/* @0x1e1b2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e1b30 mov r1, r8 */
/* @0x1e1b34 mov r2, r10 */
/* @0x1e1b38 bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf> */
/* @0x1e1b3c b 0x1e1a9c <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1e1b40 ldr r0, [pc, #0x24] */
/* @0x1e1b44 mov r1, r8 */
/* @0x1e1b48 add r0, pc, r0 */
/* @0x1e1b4c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e1b50 b 0x1e1a9c <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1e1b54 bl 0x1e1520 <_Z11FlushShaderv> */
/* @0x1e1b58 b 0x1e1acc <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1e1b5c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1e1b60 .word 0x0020bedc */
/* @0x1e1b64 andseq r0, r6, r8, lsl pc */
/* @0x1e1b68 mlaeq r0, r0, r2, pc */
/* @0x1e1b6c andseq r0, r7, r4, asr #4 */

/* ── FUNC 0x1e1b70 · F_Shader_Set_Uniform_Matrix(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1e1b70 push {r4, r5, lr} */
/* @0x1e1b74 sub sp, sp, #68 */
/* @0x1e1b78 ldr r5, [sp, #0x50] */
/* @0x1e1b7c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e1b80 ldr r3, [pc, #0x3c] */
/* @0x1e1b84 ldr r3, [pc, r3] */
/* @0x1e1b88 ldrb r3, [r3] */
/* @0x1e1b8c cmp r3, #0 */
/* @0x1e1b90 beq 0x1e1b98 <_Z27F_Shader_Set_Uniform_MatrixR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1e1b94 bl 0x1e1520 <_Z11FlushShaderv> */
/* @0x1e1b98 mov r1, sp */
/* @0x1e1b9c mov r0, #2 */
/* @0x1e1ba0 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1e1ba4 mov r0, r5 */
/* @0x1e1ba8 mov r1, #0 */
/* @0x1e1bac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e1bb0 mov r2, sp */
/* @0x1e1bb4 mov r1, #1 */
/* @0x1e1bb8 bl 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf> */
/* @0x1e1bbc add sp, sp, #68 */
/* @0x1e1bc0 pop {r4, r5, pc} */
/* @0x1e1bc4 eoreq pc, r0, r8, asr #3 */

/* ── FUNC 0x1e1bc8 · F_Shader_Set_Uniform_Matrix_Array(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x1e1bc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e1bcc add r11, sp, #32 */
/* @0x1e1bd0 sub sp, sp, #12 */
/* @0x1e1bd4 ldr r6, [pc, #0xec] */
/* @0x1e1bd8 ldr r9, [r11, #0x4] */
/* @0x1e1bdc ldr r6, [pc, r6] */
/* @0x1e1be0 ldr r3, [r6] */
/* @0x1e1be4 ldr r2, [r9, #0x1c] */
/* @0x1e1be8 cmp r2, #2 */
/* @0x1e1bec str r3, [r11, #-0x28] */
/* @0x1e1bf0 beq 0x1e1c1c <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1e1bf4 ldr r0, [pc, #0xd0] */
/* @0x1e1bf8 mov r1, #0 */
/* @0x1e1bfc add r0, pc, r0 */
/* @0x1e1c00 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e1c04 ldr r2, [r11, #-0x28] */
/* @0x1e1c08 ldr r3, [r6] */
/* @0x1e1c0c cmp r2, r3 */
/* @0x1e1c10 bne 0x1e1cc4 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1e1c14 sub sp, r11, #32 */
/* @0x1e1c18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e1c1c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e1c20 ldr r3, [pc, #0xa8] */
/* @0x1e1c24 ldr r3, [pc, r3] */
/* @0x1e1c28 ldrb r3, [r3] */
/* @0x1e1c2c cmp r3, #0 */
/* @0x1e1c30 bne 0x1e1cbc <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1e1c34 ldr r3, [r9, #0x10] */
/* @0x1e1c38 ldr r3, [r3, #0x4] */
/* @0x1e1c3c ldr r8, [r3] */
/* @0x1e1c40 bic r8, r8, #15 */
/* @0x1e1c44 cmp r8, #0 */
/* @0x1e1c48 beq 0x1e1ca8 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x1e1c4c lsl r2, r8, #2 */
/* @0x1e1c50 ldr r4, [r3, #0x4] */
/* @0x1e1c54 add r3, r2, #8 */
/* @0x1e1c58 movgt r5, #0 */
/* @0x1e1c5c sub sp, sp, r3 */
/* @0x1e1c60 mov r10, sp */
/* @0x1e1c64 movgt r7, sp */
/* @0x1e1c68 ble 0x1e1c8c <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x1e1c6c mov r0, r4 */
/* @0x1e1c70 mov r1, #0 */
/* @0x1e1c74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1e1c78 add r5, r5, #1 */
/* @0x1e1c7c cmp r5, r8 */
/* @0x1e1c80 add r4, r4, #16 */
/* @0x1e1c84 str r0, [r7], #4 */
/* @0x1e1c88 bne 0x1e1c6c <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1e1c8c mov r0, r9 */
/* @0x1e1c90 mov r1, #0 */
/* @0x1e1c94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e1c98 asr r1, r8, #4 */
/* @0x1e1c9c mov r2, r10 */
/* @0x1e1ca0 bl 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf> */
/* @0x1e1ca4 b 0x1e1c04 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1e1ca8 ldr r0, [pc, #0x24] */
/* @0x1e1cac mov r1, r8 */
/* @0x1e1cb0 add r0, pc, r0 */
/* @0x1e1cb4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e1cb8 b 0x1e1c04 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1e1cbc bl 0x1e1520 <_Z11FlushShaderv> */
/* @0x1e1cc0 b 0x1e1c34 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1e1cc4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1e1cc8 eoreq r11, r0, r4, ror sp */
/* @0x1e1ccc ldrheq r0, [r6], -r0 */
/* @0x1e1cd0 eoreq pc, r0, r8, lsr #2 */
/* @0x1e1cd4 ldrsbeq r0, [r7], -r12 */

/* ── FUNC 0x1e1cd8 · Shader_Load(unsigned char*, unsigned int, unsigned char*) · size=844 · insn=211 */
/* @0x1e1cd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e1cdc sub sp, sp, #140 */
/* @0x1e1ce0 ldr r6, [pc, #0x320] */
/* @0x1e1ce4 mov r7, r0 */
/* @0x1e1ce8 ldr r3, [pc, #0x31c] */
/* @0x1e1cec ldr r12, [r0] */
/* @0x1e1cf0 add r6, pc, r6 */
/* @0x1e1cf4 str r6, [sp, #0x7c] */
/* @0x1e1cf8 str r12, [sp, #0x78] */
/* @0x1e1cfc ldr r8, [r6, r3] */
/* @0x1e1d00 ldr r3, [r8] */
/* @0x1e1d04 cmp r3, #0 */
/* @0x1e1d08 ble 0x1e1d74 <_Z11Shader_LoadPhjS_+0x9c> */
/* @0x1e1d0c ldr r3, [pc, #0x2fc] */
/* @0x1e1d10 mov r4, #0 */
/* @0x1e1d14 ldr r12, [sp, #0x7c] */
/* @0x1e1d18 mov r6, r4 */
/* @0x1e1d1c ldr r9, [r12, r3] */
/* @0x1e1d20 ldr r3, [r9] */
/* @0x1e1d24 lsl r5, r4, #2 */
/* @0x1e1d28 ldr r3, [r3, r4, lsl #2] */
/* @0x1e1d2c add r4, r4, #1 */
/* @0x1e1d30 cmp r3, #0 */
/* @0x1e1d34 beq 0x1e1d68 <_Z11Shader_LoadPhjS_+0x90> */
/* @0x1e1d38 ldr r0, [r3, #0x60] */
/* @0x1e1d3c cmp r0, #0 */
/* @0x1e1d40 beq 0x1e1d58 <_Z11Shader_LoadPhjS_+0x80> */
/* @0x1e1d44 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e1d48 ldr r3, [r9] */
/* @0x1e1d4c ldr r2, [r3, r5] */
/* @0x1e1d50 str r6, [r2, #0x60] */
/* @0x1e1d54 ldr r3, [r3, r5] */
/* @0x1e1d58 mov r0, r3 */
/* @0x1e1d5c bl 0x27d1d0 <_ZdlPv> */
/* @0x1e1d60 ldr r3, [r9] */
/* @0x1e1d64 str r6, [r3, r5] */
/* @0x1e1d68 ldr r3, [r8] */
/* @0x1e1d6c cmp r3, r4 */
/* @0x1e1d70 bgt 0x1e1d20 <_Z11Shader_LoadPhjS_+0x48> */
/* @0x1e1d74 ldr r6, [sp, #0x78] */
/* @0x1e1d78 mov r3, #0 */
/* @0x1e1d7c str r3, [r8] */
/* @0x1e1d80 cmp r6, #0 */
/* @0x1e1d84 beq 0x1e1fcc <_Z11Shader_LoadPhjS_+0x2f4> */
/* @0x1e1d88 ldr r6, [pc, #0x284] */
/* @0x1e1d8c mov r5, r3 */
/* @0x1e1d90 ldr r12, [pc, #0x280] */
/* @0x1e1d94 add r6, pc, r6 */
/* @0x1e1d98 str r7, [sp, #0x54] */
/* @0x1e1d9c add r12, pc, r12 */
/* @0x1e1da0 str r6, [sp, #0x80] */
/* @0x1e1da4 str r12, [sp, #0x84] */
/* @0x1e1da8 b 0x1e1ee4 <_Z11Shader_LoadPhjS_+0x20c> */
/* @0x1e1dac mov lr, #0 */
/* @0x1e1db0 str lr, [sp, #0x74] */
/* @0x1e1db4 mov r11, lr */
/* @0x1e1db8 str lr, [sp, #0x70] */
/* @0x1e1dbc str lr, [sp, #0x6c] */
/* @0x1e1dc0 str lr, [sp, #0x58] */
/* @0x1e1dc4 str lr, [sp, #0x68] */
/* @0x1e1dc8 str lr, [sp, #0x64] */
/* @0x1e1dcc str lr, [sp, #0x60] */
/* @0x1e1dd0 str lr, [sp, #0x5c] */
/* @0x1e1dd4 ldr r0, [r3, r4] */
/* @0x1e1dd8 ldr r2, [r12, #0x8] */
/* @0x1e1ddc ldr r3, [r12, #0xc] */
/* @0x1e1de0 cmp r0, #0 */
/* @0x1e1de4 ldr r10, [r12, #0x10] */
/* @0x1e1de8 addne r0, r4, r0 */
/* @0x1e1dec cmp r2, #0 */
/* @0x1e1df0 ldr r9, [r12, #0x14] */
/* @0x1e1df4 addne r2, r4, r2 */
/* @0x1e1df8 cmp r3, #0 */
/* @0x1e1dfc ldr r8, [r12, #0x18] */
/* @0x1e1e00 addne r3, r4, r3 */
/* @0x1e1e04 cmp r10, #0 */
/* @0x1e1e08 ldr r7, [r12, #0x1c] */
/* @0x1e1e0c addne r10, r4, r10 */
/* @0x1e1e10 cmp r9, #0 */
/* @0x1e1e14 ldr r6, [r12, #0x20] */
/* @0x1e1e18 addne r9, r4, r9 */
/* @0x1e1e1c cmp r8, #0 */
/* @0x1e1e20 ldr r12, [r12, #0x24] */
/* @0x1e1e24 addne r8, r4, r8 */
/* @0x1e1e28 cmp r7, #0 */
/* @0x1e1e2c addne r7, r4, r7 */
/* @0x1e1e30 cmp r6, #0 */
/* @0x1e1e34 addne r6, r4, r6 */
/* @0x1e1e38 cmp r12, #0 */
/* @0x1e1e3c addne r4, r4, r12 */
/* @0x1e1e40 str r6, [sp, #0x10] */
/* @0x1e1e44 moveq r4, r12 */
/* @0x1e1e48 ldr r6, [sp, #0x6c] */
/* @0x1e1e4c ldr r12, [sp, #0x5c] */
/* @0x1e1e50 str lr, [sp, #0x34] */
/* @0x1e1e54 str r6, [sp, #0x1c] */
/* @0x1e1e58 str r12, [sp, #0x18] */
/* @0x1e1e5c ldr r6, [sp, #0x70] */
/* @0x1e1e60 ldr r12, [sp, #0x60] */
/* @0x1e1e64 ldr lr, [sp, #0x58] */
/* @0x1e1e68 str r6, [sp, #0x24] */
/* @0x1e1e6c str r12, [sp, #0x20] */
/* @0x1e1e70 ldr r6, [sp, #0x74] */
/* @0x1e1e74 ldr r12, [sp, #0x64] */
/* @0x1e1e78 str lr, [sp, #0x38] */
/* @0x1e1e7c str r6, [sp, #0x2c] */
/* @0x1e1e80 str r12, [sp, #0x28] */
/* @0x1e1e84 ldr r6, [sp, #0x4c] */
/* @0x1e1e88 ldr r12, [sp, #0x68] */
/* @0x1e1e8c str r4, [sp, #0x14] */
/* @0x1e1e90 str r10, [sp] */
/* @0x1e1e94 str r12, [sp, #0x30] */
/* @0x1e1e98 str r9, [sp, #0x4] */
/* @0x1e1e9c str r8, [sp, #0x8] */
/* @0x1e1ea0 str r7, [sp, #0xc] */
/* @0x1e1ea4 str r11, [sp, #0x3c] */
/* @0x1e1ea8 str r6, [sp, #0x40] */
/* @0x1e1eac ldr r12, [sp, #0x50] */
/* @0x1e1eb0 str r12, [sp, #0x44] */
/* @0x1e1eb4 bl 0x1e1350 <_Z9AddShaderPciS_S_S_S_S_S_S_S_S_iS_iS_iS_iS_S_iPj> */
/* @0x1e1eb8 mov r4, r0 */
/* @0x1e1ebc bl 0x1884f4 <_Z11Shader_LoadP6Shader> */
/* @0x1e1ec0 cmp r0, #0 */
/* @0x1e1ec4 bne 0x1e1ed4 <_Z11Shader_LoadPhjS_+0x1fc> */
/* @0x1e1ec8 ldr r3, [r4, #0x54] */
/* @0x1e1ecc cmp r3, #0 */
/* @0x1e1ed0 beq 0x1e1fd8 <_Z11Shader_LoadPhjS_+0x300> */
/* @0x1e1ed4 ldr r6, [sp, #0x78] */
/* @0x1e1ed8 add r5, r5, #1 */
/* @0x1e1edc cmp r5, r6 */
/* @0x1e1ee0 beq 0x1e1fcc <_Z11Shader_LoadPhjS_+0x2f4> */
/* @0x1e1ee4 ldr r6, [sp, #0x54] */
/* @0x1e1ee8 ldr r3, [r6, #0x4]! */
/* @0x1e1eec cmp r3, #0 */
/* @0x1e1ef0 str r6, [sp, #0x54] */
/* @0x1e1ef4 beq 0x1e1ed4 <_Z11Shader_LoadPhjS_+0x1fc> */
/* @0x1e1ef8 ldr r12, [sp, #0x7c] */
/* @0x1e1efc ldr r2, [pc, #0x118] */
/* @0x1e1f00 ldr r2, [r12, r2] */
/* @0x1e1f04 ldr r4, [r2] */
/* @0x1e1f08 adds r12, r3, r4 */
/* @0x1e1f0c beq 0x1e1ed4 <_Z11Shader_LoadPhjS_+0x1fc> */
/* @0x1e1f10 ldr r1, [r12, #0x4] */
/* @0x1e1f14 add lr, r12, #44 */
/* @0x1e1f18 ldr r6, [r12, #0x28] */
/* @0x1e1f1c cmp r1, #0 */
/* @0x1e1f20 str lr, [sp, #0x50] */
/* @0x1e1f24 str r6, [sp, #0x4c] */
/* @0x1e1f28 bge 0x1e1dac <_Z11Shader_LoadPhjS_+0xd4> */
/* @0x1e1f2c ldr r0, [lr, r6, lsl #2] */
/* @0x1e1f30 bic r1, r1, #-2147483648 */
/* @0x1e1f34 add r2, lr, r6, lsl #2 */
/* @0x1e1f38 cmp r0, #0 */
/* @0x1e1f3c ble 0x1e1dac <_Z11Shader_LoadPhjS_+0xd4> */
/* @0x1e1f40 ldr lr, [r2, #0x4] */
/* @0x1e1f44 ldr r6, [r2, #0x8] */
/* @0x1e1f48 cmp lr, #0 */
/* @0x1e1f4c addne lr, r4, lr */
/* @0x1e1f50 str lr, [sp, #0x5c] */
/* @0x1e1f54 ldr lr, [r2, #0xc] */
/* @0x1e1f58 str r6, [sp, #0x6c] */
/* @0x1e1f5c cmp lr, #0 */
/* @0x1e1f60 ldr r6, [r2, #0x10] */
/* @0x1e1f64 addne lr, r4, lr */
/* @0x1e1f68 str lr, [sp, #0x60] */
/* @0x1e1f6c ldr lr, [r2, #0x14] */
/* @0x1e1f70 str r6, [sp, #0x70] */
/* @0x1e1f74 cmp lr, #0 */
/* @0x1e1f78 ldr r6, [r2, #0x18] */
/* @0x1e1f7c addne lr, r4, lr */
/* @0x1e1f80 str lr, [sp, #0x64] */
/* @0x1e1f84 ldr lr, [r2, #0x1c] */
/* @0x1e1f88 str r6, [sp, #0x74] */
/* @0x1e1f8c cmp lr, #0 */
/* @0x1e1f90 addne lr, r4, lr */
/* @0x1e1f94 cmp r0, #1 */
/* @0x1e1f98 str lr, [sp, #0x68] */
/* @0x1e1f9c moveq r11, #0 */
/* @0x1e1fa0 ldr lr, [r2, #0x20] */
/* @0x1e1fa4 streq r11, [sp, #0x58] */
/* @0x1e1fa8 beq 0x1e1dd4 <_Z11Shader_LoadPhjS_+0xfc> */
/* @0x1e1fac ldr r0, [r2, #0x24] */
/* @0x1e1fb0 ldr r11, [r2, #0x2c] */
/* @0x1e1fb4 cmp r0, #0 */
/* @0x1e1fb8 addne r0, r4, r0 */
/* @0x1e1fbc cmp r11, #0 */
/* @0x1e1fc0 str r0, [sp, #0x58] */
/* @0x1e1fc4 addne r11, r4, r11 */
/* @0x1e1fc8 b 0x1e1dd4 <_Z11Shader_LoadPhjS_+0xfc> */
/* @0x1e1fcc mov r0, #1 */
/* @0x1e1fd0 add sp, sp, #140 */
/* @0x1e1fd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e1fd8 ldr r6, [sp, #0x7c] */
/* @0x1e1fdc ldr r3, [pc, #0x3c] */
/* @0x1e1fe0 ldr r1, [sp, #0x80] */
/* @0x1e1fe4 ldr r2, [r4, #0x4] */
/* @0x1e1fe8 ldr r3, [r6, r3] */
/* @0x1e1fec ldr r0, [r3] */
/* @0x1e1ff0 ldr r3, [r0] */
/* @0x1e1ff4 ldr r3, [r3, #0xc] */
/* @0x1e1ff8 blx r3 */
/* @0x1e1ffc ldr r12, [sp, #0x84] */
/* @0x1e2000 str r12, [r4, #0x54] */
/* @0x1e2004 b 0x1e1ed4 <_Z11Shader_LoadPhjS_+0x1fc> */
/* @0x1e2008 eoreq pc, r0, r0, ror #30 */
/* @0x1e200c .word 0xfffff0f4 */
/* @0x1e2010 .word 0xfffff0f8 */
/* @0x1e2014 andseq r0, r7, r12 */
/* @0x1e2018 andseq r0, r7, r0, asr r0 */
/* @0x1e201c .word 0xffffbcf4 */
/* @0x1e2020 .word 0xffffbac4 */

/* ── FUNC 0x1e2024 · Shader_Set(Shader*) · size=88 · insn=22 */
/* @0x1e2024 ldr r3, [pc, #0x40] */
/* @0x1e2028 ldr r2, [pc, #0x40] */
/* @0x1e202c add r3, pc, r3 */
/* @0x1e2030 ldr r2, [r3, r2] */
/* @0x1e2034 ldr r1, [r2] */
/* @0x1e2038 cmp r1, r0 */
/* @0x1e203c bxeq lr */
/* @0x1e2040 ldr r1, [pc, #0x2c] */
/* @0x1e2044 ldr r12, [pc, #0x2c] */
/* @0x1e2048 ldr r1, [r3, r1] */
/* @0x1e204c ldr r3, [r3, r12] */
/* @0x1e2050 str r0, [r2] */
/* @0x1e2054 ldr r1, [r1] */
/* @0x1e2058 cmp r1, r0 */
/* @0x1e205c moveq r1, #0 */
/* @0x1e2060 movne r1, #1 */
/* @0x1e2064 strb r1, [r3] */
/* @0x1e2068 bx lr */
/* @0x1e206c eoreq pc, r0, r4, lsr #24 */
/* @0x1e2070 .word 0xfffff0f0 */
/* @0x1e2074 .word 0xffffe828 */
/* @0x1e2078 .word 0xfffff0fc */

/* ── FUNC 0x1e207c · F_Shader_Set(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1e207c push {r3, lr} */
/* @0x1e2080 mov r1, #0 */
/* @0x1e2084 ldr r0, [sp, #0x8] */
/* @0x1e2088 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e208c cmn r0, #1 */
/* @0x1e2090 beq 0x1e20f4 <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1e2094 cmp r0, #0 */
/* @0x1e2098 blt 0x1e20b0 <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1e209c ldr r3, [pc, #0x5c] */
/* @0x1e20a0 ldr r3, [pc, r3] */
/* @0x1e20a4 ldr r3, [r3] */
/* @0x1e20a8 cmp r0, r3 */
/* @0x1e20ac blt 0x1e20c4 <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1e20b0 ldr r0, [pc, #0x4c] */
/* @0x1e20b4 mov r1, #0 */
/* @0x1e20b8 pop {r3, lr} */
/* @0x1e20bc add r0, pc, r0 */
/* @0x1e20c0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e20c4 ldr r3, [pc, #0x3c] */
/* @0x1e20c8 ldr r3, [pc, r3] */
/* @0x1e20cc ldr r3, [r3] */
/* @0x1e20d0 ldr r0, [r3, r0, lsl #2] */
/* @0x1e20d4 bl 0x1e2024 <_Z10Shader_SetP6Shader> */
/* @0x1e20d8 ldr r3, [pc, #0x2c] */
/* @0x1e20dc ldr r3, [pc, r3] */
/* @0x1e20e0 ldrb r3, [r3] */
/* @0x1e20e4 cmp r3, #0 */
/* @0x1e20e8 popeq {r3, pc} */
/* @0x1e20ec pop {r3, lr} */
/* @0x1e20f0 b 0x1e1520 <_Z11FlushShaderv> */
/* @0x1e20f4 mov r0, #0 */
/* @0x1e20f8 bl 0x1e2024 <_Z10Shader_SetP6Shader> */
/* @0x1e20fc b 0x1e20d8 <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1e2100 eoreq lr, r0, r4, lsr #25 */
/* @0x1e2104 ldrheq pc, [r6], -r8 */
/* @0x1e2108 eoreq lr, r0, r0, lsl #25 */
/* @0x1e210c eoreq lr, r0, r0, ror r12 */

/* ── FUNC 0x1e2110 · F_Shader_Reset(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1e2110 push {r4, lr} */
/* @0x1e2114 subs r4, r3, #0 */
/* @0x1e2118 bne 0x1e2144 <_Z14F_Shader_ResetR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1e211c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e2120 mov r0, r4 */
/* @0x1e2124 bl 0x1e2024 <_Z10Shader_SetP6Shader> */
/* @0x1e2128 ldr r3, [pc, #0x28] */
/* @0x1e212c ldr r3, [pc, r3] */
/* @0x1e2130 ldrb r3, [r3] */
/* @0x1e2134 cmp r3, #0 */
/* @0x1e2138 popeq {r4, pc} */
/* @0x1e213c pop {r4, lr} */
/* @0x1e2140 b 0x1e1520 <_Z11FlushShaderv> */
/* @0x1e2144 ldr r0, [pc, #0x10] */
/* @0x1e2148 mov r1, #0 */
/* @0x1e214c pop {r4, lr} */
/* @0x1e2150 add r0, pc, r0 */
/* @0x1e2154 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2158 eoreq lr, r0, r0, lsr #24 */
/* @0x1e215c andseq pc, r6, r12, lsr #25 */

/* ── FUNC 0x1e2160 · F_Function_Not_Supported(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1e2160 mov r1, #0 */
/* @0x1e2164 str r1, [r0, #0xc] */
/* @0x1e2168 mov r3, r1 */
/* @0x1e216c movt r3, #0xbff0 */
/* @0x1e2170 stm r0, {r1, r3} */
/* @0x1e2174 ldr r0, [pc, #0x4] */
/* @0x1e2178 add r0, pc, r0 */
/* @0x1e217c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2180 andseq pc, r6, r8, lsr #25 */

/* ── FUNC 0x1e2184 · InitShaderFunctions() · size=596 · insn=149 */
/* @0x1e2184 push {r4, lr} */
/* @0x1e2188 mov r2, #1 */
/* @0x1e218c ldr r4, [pc, #0x1c0] */
/* @0x1e2190 mov r3, #0 */
/* @0x1e2194 ldr r1, [pc, #0x1bc] */
/* @0x1e2198 add r4, pc, r4 */
/* @0x1e219c ldr r0, [pc, #0x1b8] */
/* @0x1e21a0 ldr r1, [r4, r1] */
/* @0x1e21a4 add r0, pc, r0 */
/* @0x1e21a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e21ac ldr r1, [pc, #0x1ac] */
/* @0x1e21b0 ldr r0, [pc, #0x1ac] */
/* @0x1e21b4 mov r2, #1 */
/* @0x1e21b8 mov r3, #0 */
/* @0x1e21bc ldr r1, [r4, r1] */
/* @0x1e21c0 add r0, pc, r0 */
/* @0x1e21c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e21c8 ldr r1, [pc, #0x198] */
/* @0x1e21cc ldr r0, [pc, #0x198] */
/* @0x1e21d0 mov r2, #0 */
/* @0x1e21d4 mov r3, r2 */
/* @0x1e21d8 ldr r1, [r4, r1] */
/* @0x1e21dc add r0, pc, r0 */
/* @0x1e21e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e21e4 ldr r1, [pc, #0x184] */
/* @0x1e21e8 ldr r0, [pc, #0x184] */
/* @0x1e21ec mov r2, #2 */
/* @0x1e21f0 mov r3, #0 */
/* @0x1e21f4 ldr r1, [r4, r1] */
/* @0x1e21f8 add r0, pc, r0 */
/* @0x1e21fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e2200 ldr r1, [pc, #0x170] */
/* @0x1e2204 ldr r0, [pc, #0x170] */
/* @0x1e2208 mov r2, #2 */
/* @0x1e220c mov r3, #0 */
/* @0x1e2210 ldr r1, [r4, r1] */
/* @0x1e2214 add r0, pc, r0 */
/* @0x1e2218 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e221c ldr r1, [pc, #0x15c] */
/* @0x1e2220 ldr r0, [pc, #0x15c] */
/* @0x1e2224 mvn r2, #0 */
/* @0x1e2228 mov r3, #0 */
/* @0x1e222c ldr r1, [r4, r1] */
/* @0x1e2230 add r0, pc, r0 */
/* @0x1e2234 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e2238 ldr r1, [pc, #0x148] */
/* @0x1e223c ldr r0, [pc, #0x148] */
/* @0x1e2240 mov r2, #2 */
/* @0x1e2244 mov r3, #0 */
/* @0x1e2248 ldr r1, [r4, r1] */
/* @0x1e224c add r0, pc, r0 */
/* @0x1e2250 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e2254 ldr r1, [pc, #0x134] */
/* @0x1e2258 ldr r0, [pc, #0x134] */
/* @0x1e225c mvn r2, #0 */
/* @0x1e2260 mov r3, #0 */
/* @0x1e2264 ldr r1, [r4, r1] */
/* @0x1e2268 add r0, pc, r0 */
/* @0x1e226c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e2270 ldr r1, [pc, #0x120] */
/* @0x1e2274 ldr r0, [pc, #0x120] */
/* @0x1e2278 mov r2, #2 */
/* @0x1e227c mov r3, #0 */
/* @0x1e2280 ldr r1, [r4, r1] */
/* @0x1e2284 add r0, pc, r0 */
/* @0x1e2288 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e228c ldr r1, [pc, #0x10c] */
/* @0x1e2290 ldr r0, [pc, #0x10c] */
/* @0x1e2294 mov r2, #1 */
/* @0x1e2298 mov r3, #0 */
/* @0x1e229c ldr r1, [r4, r1] */
/* @0x1e22a0 add r0, pc, r0 */
/* @0x1e22a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e22a8 ldr r1, [pc, #0xf8] */
/* @0x1e22ac ldr r0, [pc, #0xf8] */
/* @0x1e22b0 mov r2, #2 */
/* @0x1e22b4 mov r3, #0 */
/* @0x1e22b8 ldr r1, [r4, r1] */
/* @0x1e22bc add r0, pc, r0 */
/* @0x1e22c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e22c4 ldr r1, [pc, #0xe4] */
/* @0x1e22c8 ldr r0, [pc, #0xe4] */
/* @0x1e22cc mov r2, #1 */
/* @0x1e22d0 mov r3, #0 */
/* @0x1e22d4 ldr r1, [r4, r1] */
/* @0x1e22d8 add r0, pc, r0 */
/* @0x1e22dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e22e0 ldr r1, [pc, #0xd0] */
/* @0x1e22e4 ldr r0, [pc, #0xd0] */
/* @0x1e22e8 mov r2, #0 */
/* @0x1e22ec mov r3, r2 */
/* @0x1e22f0 ldr r1, [r4, r1] */
/* @0x1e22f4 add r0, pc, r0 */
/* @0x1e22f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e22fc ldr r1, [pc, #0xbc] */
/* @0x1e2300 ldr r0, [pc, #0xbc] */
/* @0x1e2304 mov r2, #2 */
/* @0x1e2308 mov r3, #0 */
/* @0x1e230c ldr r1, [r4, r1] */
/* @0x1e2310 add r0, pc, r0 */
/* @0x1e2314 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e2318 ldr r1, [pc, #0xa8] */
/* @0x1e231c ldr r0, [pc, #0xa8] */
/* @0x1e2320 mov r2, #1 */
/* @0x1e2324 mov r3, #0 */
/* @0x1e2328 ldr r1, [r4, r1] */
/* @0x1e232c add r0, pc, r0 */
/* @0x1e2330 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e2334 ldr r1, [pc, #0x94] */
/* @0x1e2338 ldr r0, [pc, #0x94] */
/* @0x1e233c mov r2, #1 */
/* @0x1e2340 mov r3, #0 */
/* @0x1e2344 ldr r1, [r4, r1] */
/* @0x1e2348 add r0, pc, r0 */
/* @0x1e234c pop {r4, lr} */
/* @0x1e2350 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e2354 .word 0x0020fab8 */
/* @0x1e2358 .word 0xfffff100 */
/* @0x1e235c andseq pc, r6, r4, lsr #25 */
/* @0x1e2360 .word 0xfffff104 */
/* @0x1e2364 mulseq r6, r4, r12 */
/* @0x1e2368 .word 0xfffff108 */
/* @0x1e236c andseq pc, r6, r8, lsl #25 */
/* @0x1e2370 .word 0xfffff10c */
/* @0x1e2374 andseq pc, r6, r12, ror r12 */
/* @0x1e2378 .word 0xfffff110 */
/* @0x1e237c andseq pc, r6, r4, ror r12 */
/* @0x1e2380 .word 0xfffff114 */
/* @0x1e2384 andseq pc, r6, r4, ror r12 */
/* @0x1e2388 .word 0xfffff118 */
/* @0x1e238c andseq pc, r6, r0, ror r12 */
/* @0x1e2390 .word 0xfffff11c */
/* @0x1e2394 andseq pc, r6, r0, ror r12 */
/* @0x1e2398 .word 0xfffff120 */
/* @0x1e239c andseq pc, r6, r12, ror #24 */
/* @0x1e23a0 .word 0xfffff124 */
/* @0x1e23a4 andseq pc, r6, r12, ror #24 */
/* @0x1e23a8 .word 0xfffff128 */
/* @0x1e23ac andseq pc, r6, r12, ror #24 */
/* @0x1e23b0 .word 0xfffff12c */
/* @0x1e23b4 andseq pc, r6, r0, ror r12 */
/* @0x1e23b8 .word 0xfffff130 */
/* @0x1e23bc andseq pc, r6, r8, ror #24 */
/* @0x1e23c0 .word 0xfffff134 */
/* @0x1e23c4 andseq pc, r6, r4, ror #24 */
/* @0x1e23c8 .word 0xfffff138 */
/* @0x1e23cc andseq pc, r6, r12, asr r12 */
/* @0x1e23d0 .word 0xfffff13c */
/* @0x1e23d4 andseq pc, r6, r8, asr r12 */

/* ── FUNC 0x1e23d8 · VertexFormat::GetTypeSize(yyVertexType) · size=40 · insn=10 */
/* @0x1e23d8 sub r0, r0, #1 */
/* @0x1e23dc cmp r0, #5 */
/* @0x1e23e0 bhi 0x1e23f4 <_ZN12VertexFormat11GetTypeSizeE12yyVertexType+0x1c> */
/* @0x1e23e4 ldr r3, [pc, #0x10] */
/* @0x1e23e8 add r3, pc, r3 */
/* @0x1e23ec ldr r0, [r3, r0, lsl #2] */
/* @0x1e23f0 bx lr */
/* @0x1e23f4 mov r0, #0 */
/* @0x1e23f8 bx lr */
/* @0x1e23fc andseq r11, r7, r12, lsr #22 */

/* ── FUNC 0x1e2400 · VertexFormat::GetNumElementsInType(yyVertexType) · size=44 · insn=11 */
/* @0x1e2400 sub r0, r0, #1 */
/* @0x1e2404 cmp r0, #5 */
/* @0x1e2408 bhi 0x1e2420 <_ZN12VertexFormat20GetNumElementsInTypeE12yyVertexType+0x20> */
/* @0x1e240c ldr r3, [pc, #0x14] */
/* @0x1e2410 add r3, pc, r3 */
/* @0x1e2414 add r0, r3, r0, lsl #2 */
/* @0x1e2418 ldr r0, [r0, #0x18] */
/* @0x1e241c bx lr */
/* @0x1e2420 mov r0, #0 */
/* @0x1e2424 bx lr */
/* @0x1e2428 andseq r11, r7, r4, lsl #22 */

/* ── FUNC 0x1e242c · VertexFormat::GetElementSizeInType(yyVertexType) · size=20 · insn=5 */
/* @0x1e242c sub r0, r0, #1 */
/* @0x1e2430 cmp r0, #5 */
/* @0x1e2434 movls r0, #4 */
/* @0x1e2438 movhi r0, #0 */
/* @0x1e243c bx lr */

/* ── FUNC 0x1e2440 · VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int) · size=220 · insn=55 */
/* @0x1e2440 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e2444 mov r6, r0 */
/* @0x1e2448 ldr r7, [r0, #0x4] */
/* @0x1e244c sub sp, sp, #12 */
/* @0x1e2450 ldr r0, [r0, #0x8] */
/* @0x1e2454 mov r8, r2 */
/* @0x1e2458 add r11, r7, #1 */
/* @0x1e245c ldr r2, [pc, #0xb4] */
/* @0x1e2460 str r11, [r6, #0x4] */
/* @0x1e2464 mov r4, #0 */
/* @0x1e2468 lsl r11, r11, #4 */
/* @0x1e246c mov r10, r1 */
/* @0x1e2470 mov r9, r3 */
/* @0x1e2474 str r4, [sp] */
/* @0x1e2478 mov r3, #74 */
/* @0x1e247c mov r1, r11 */
/* @0x1e2480 add r2, pc, r2 */
/* @0x1e2484 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1e2488 cmp r7, r4 */
/* @0x1e248c str r0, [r6, #0x8] */
/* @0x1e2490 ble 0x1e250c <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej+0xcc> */
/* @0x1e2494 mov r5, r4 */
/* @0x1e2498 b 0x1e24a0 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej+0x60> */
/* @0x1e249c ldr r0, [r6, #0x8] */
/* @0x1e24a0 add r0, r0, r4, lsl #4 */
/* @0x1e24a4 add r4, r4, #1 */
/* @0x1e24a8 ldr r0, [r0, #0x4] */
/* @0x1e24ac bl 0x1e23d8 <_ZN12VertexFormat11GetTypeSizeE12yyVertexType> */
/* @0x1e24b0 cmp r4, r7 */
/* @0x1e24b4 add r5, r5, r0 */
/* @0x1e24b8 bne 0x1e249c <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej+0x5c> */
/* @0x1e24bc ldr r2, [r6, #0x8] */
/* @0x1e24c0 sub r11, r11, #16 */
/* @0x1e24c4 ldr r1, [r6, #0x10] */
/* @0x1e24c8 add r3, r2, r11 */
/* @0x1e24cc mov r0, r10 */
/* @0x1e24d0 str r5, [r2, r11] */
/* @0x1e24d4 orr r2, r1, r9 */
/* @0x1e24d8 str r10, [r3, #0x4] */
/* @0x1e24dc str r8, [r3, #0x8] */
/* @0x1e24e0 str r9, [r3, #0xc] */
/* @0x1e24e4 str r2, [r6, #0x10] */
/* @0x1e24e8 bl 0x1e23d8 <_ZN12VertexFormat11GetTypeSizeE12yyVertexType> */
/* @0x1e24ec ldr r3, [r6, #0x18] */
/* @0x1e24f0 mov r2, #1 */
/* @0x1e24f4 orr r8, r3, r2, lsl r8 */
/* @0x1e24f8 str r8, [r6, #0x18] */
/* @0x1e24fc add r0, r0, r5 */
/* @0x1e2500 str r0, [r6, #0x14] */
/* @0x1e2504 add sp, sp, #12 */
/* @0x1e2508 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e250c mov r2, r0 */
/* @0x1e2510 mov r5, r4 */
/* @0x1e2514 b 0x1e24c0 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej+0x80> */
/* @0x1e2518 ldrheq lr, [r4], -r0 */

/* ── FUNC 0x1e251c · VertexFormat::EndianSwapBuffer(unsigned char*, int, int, int, bool) · size=876 · insn=219 */
/* @0x1e251c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e2520 subs r11, r1, #0 */
/* @0x1e2524 sub sp, sp, #44 */
/* @0x1e2528 mov r4, r3 */
/* @0x1e252c str r0, [sp, #0xc] */
/* @0x1e2530 str r2, [sp, #0x1c] */
/* @0x1e2534 ldr r10, [sp, #0x50] */
/* @0x1e2538 ldrb r3, [sp, #0x54] */
/* @0x1e253c beq 0x1e26bc <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a0> */
/* @0x1e2540 ands r1, r3, r10, lsr #31 */
/* @0x1e2544 bne 0x1e26bc <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a0> */
/* @0x1e2548 cmp r10, #0 */
/* @0x1e254c blt 0x1e26e4 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1c8> */
/* @0x1e2550 cmp r3, #0 */
/* @0x1e2554 beq 0x1e26c4 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a8> */
/* @0x1e2558 ldr r2, [sp, #0xc] */
/* @0x1e255c ldr r5, [r2, #0x14] */
/* @0x1e2560 ldr r2, [sp, #0x1c] */
/* @0x1e2564 mul r3, r2, r5 */
/* @0x1e2568 cmp r10, r3 */
/* @0x1e256c bge 0x1e2584 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x68> */
/* @0x1e2570 mov r0, r10 */
/* @0x1e2574 mov r1, r5 */
/* @0x1e2578 bl 0x318c48 <__udivsi3> */
/* @0x1e257c mul r3, r0, r5 */
/* @0x1e2580 str r0, [sp, #0x1c] */
/* @0x1e2584 add r3, r4, r3 */
/* @0x1e2588 cmp r10, r3 */
/* @0x1e258c blt 0x1e26ec <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1d0> */
/* @0x1e2590 ldr r2, [sp, #0x1c] */
/* @0x1e2594 add r4, r11, r4 */
/* @0x1e2598 str r4, [sp, #0x4] */
/* @0x1e259c cmp r2, #0 */
/* @0x1e25a0 ble 0x1e26bc <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a0> */
/* @0x1e25a4 ldr r1, [sp, #0xc] */
/* @0x1e25a8 mov r3, #0 */
/* @0x1e25ac str r3, [sp, #0x8] */
/* @0x1e25b0 ldr r4, [r1, #0x4] */
/* @0x1e25b4 cmp r4, #0 */
/* @0x1e25b8 ble 0x1e2690 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x174> */
/* @0x1e25bc mov r9, #0 */
/* @0x1e25c0 ldr r2, [sp, #0xc] */
/* @0x1e25c4 lsl r5, r9, #4 */
/* @0x1e25c8 ldr r1, [sp, #0x4] */
/* @0x1e25cc ldr r3, [r2, #0x8] */
/* @0x1e25d0 add r2, r3, r5 */
/* @0x1e25d4 ldr r3, [r3, r9, lsl #4] */
/* @0x1e25d8 ldr r0, [r2, #0x4] */
/* @0x1e25dc add r4, r1, r3 */
/* @0x1e25e0 bl 0x1e2400 <_ZN12VertexFormat20GetNumElementsInTypeE12yyVertexType> */
/* @0x1e25e4 ldr r2, [sp, #0xc] */
/* @0x1e25e8 ldr r3, [r2, #0x8] */
/* @0x1e25ec add r5, r3, r5 */
/* @0x1e25f0 mov r7, r0 */
/* @0x1e25f4 ldr r0, [r5, #0x4] */
/* @0x1e25f8 bl 0x1e242c <_ZN12VertexFormat20GetElementSizeInTypeE12yyVertexType> */
/* @0x1e25fc cmp r7, #0 */
/* @0x1e2600 ble 0x1e267c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x160> */
/* @0x1e2604 add r4, r4, #1 */
/* @0x1e2608 and r8, r0, #1 */
/* @0x1e260c asr r6, r0, #1 */
/* @0x1e2610 sub r10, r0, #3 */
/* @0x1e2614 mov r5, #0 */
/* @0x1e2618 cmp r8, #0 */
/* @0x1e261c bne 0x1e266c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x150> */
/* @0x1e2620 cmp r6, #0 */
/* @0x1e2624 ble 0x1e266c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x150> */
/* @0x1e2628 add r12, r6, r4 */
/* @0x1e262c add r2, r10, r4 */
/* @0x1e2630 mov r3, r4 */
/* @0x1e2634 ldrb r11, [r2, #0x1] */
/* @0x1e2638 add r3, r3, #1 */
/* @0x1e263c ldrb r1, [r3, #-0x2] */
/* @0x1e2640 sub r2, r2, #1 */
/* @0x1e2644 eor r1, r11, r1 */
/* @0x1e2648 strb r1, [r3, #-0x2] */
/* @0x1e264c ldrb r11, [r2, #0x2] */
/* @0x1e2650 eor r1, r1, r11 */
/* @0x1e2654 strb r1, [r2, #0x2] */
/* @0x1e2658 ldrb r11, [r3, #-0x2] */
/* @0x1e265c eor r1, r1, r11 */
/* @0x1e2660 strb r1, [r3, #-0x2] */
/* @0x1e2664 cmp r3, r12 */
/* @0x1e2668 bne 0x1e2634 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x118> */
/* @0x1e266c add r5, r5, #1 */
/* @0x1e2670 add r4, r4, r0 */
/* @0x1e2674 cmp r5, r7 */
/* @0x1e2678 bne 0x1e2618 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0xfc> */
/* @0x1e267c ldr r3, [sp, #0xc] */
/* @0x1e2680 add r9, r9, #1 */
/* @0x1e2684 ldr r4, [r3, #0x4] */
/* @0x1e2688 cmp r4, r9 */
/* @0x1e268c bgt 0x1e25c0 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0xa4> */
/* @0x1e2690 ldr r2, [sp, #0xc] */
/* @0x1e2694 ldr r1, [sp, #0x8] */
/* @0x1e2698 ldr r3, [r2, #0x14] */
/* @0x1e269c add r1, r1, #1 */
/* @0x1e26a0 ldr r2, [sp, #0x1c] */
/* @0x1e26a4 str r1, [sp, #0x8] */
/* @0x1e26a8 cmp r1, r2 */
/* @0x1e26ac ldr r1, [sp, #0x4] */
/* @0x1e26b0 add r1, r1, r3 */
/* @0x1e26b4 str r1, [sp, #0x4] */
/* @0x1e26b8 bne 0x1e25b4 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x98> */
/* @0x1e26bc add sp, sp, #44 */
/* @0x1e26c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e26c4 ldr r1, [r0, #0x14] */
/* @0x1e26c8 mla r3, r2, r1, r4 */
/* @0x1e26cc cmp r10, r3 */
/* @0x1e26d0 bge 0x1e2590 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x74> */
/* @0x1e26d4 rsb r0, r4, r10 */
/* @0x1e26d8 bl 0x318c48 <__udivsi3> */
/* @0x1e26dc str r0, [sp, #0x1c] */
/* @0x1e26e0 b 0x1e2590 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x74> */
/* @0x1e26e4 cmp r3, #0 */
/* @0x1e26e8 beq 0x1e2590 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x74> */
/* @0x1e26ec mov r0, r4 */
/* @0x1e26f0 mov r1, r10 */
/* @0x1e26f4 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e26f8 ldr r2, [sp, #0x1c] */
/* @0x1e26fc cmp r2, #0 */
/* @0x1e2700 str r1, [sp, #0x20] */
/* @0x1e2704 ble 0x1e26bc <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a0> */
/* @0x1e2708 ldr r1, [sp, #0xc] */
/* @0x1e270c mov r3, #0 */
/* @0x1e2710 str r3, [sp, #0x24] */
/* @0x1e2714 ldr r4, [r1, #0x4] */
/* @0x1e2718 cmp r4, #0 */
/* @0x1e271c ble 0x1e2848 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x32c> */
/* @0x1e2720 mov r2, #0 */
/* @0x1e2724 str r2, [sp, #0x18] */
/* @0x1e2728 ldr r3, [sp, #0xc] */
/* @0x1e272c ldr r2, [r3, #0x8] */
/* @0x1e2730 ldr r3, [sp, #0x18] */
/* @0x1e2734 lsl r5, r3, #4 */
/* @0x1e2738 ldr r4, [r2, r3, lsl #4] */
/* @0x1e273c add r1, r2, r5 */
/* @0x1e2740 ldr r0, [r1, #0x4] */
/* @0x1e2744 bl 0x1e2400 <_ZN12VertexFormat20GetNumElementsInTypeE12yyVertexType> */
/* @0x1e2748 ldr r1, [sp, #0xc] */
/* @0x1e274c ldr r2, [r1, #0x8] */
/* @0x1e2750 add r5, r2, r5 */
/* @0x1e2754 str r0, [sp, #0x8] */
/* @0x1e2758 ldr r0, [r5, #0x4] */
/* @0x1e275c bl 0x1e242c <_ZN12VertexFormat20GetElementSizeInTypeE12yyVertexType> */
/* @0x1e2760 ands r7, r0, #1 */
/* @0x1e2764 str r0, [sp, #0x4] */
/* @0x1e2768 bne 0x1e282c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x310> */
/* @0x1e276c ldr r2, [sp, #0x8] */
/* @0x1e2770 cmp r2, #0 */
/* @0x1e2774 ble 0x1e282c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x310> */
/* @0x1e2778 ldr r2, [sp, #0x20] */
/* @0x1e277c ldr r3, [sp, #0x4] */
/* @0x1e2780 add r9, r2, r4 */
/* @0x1e2784 ldr r2, [sp, #0x4] */
/* @0x1e2788 asr r3, r3, #1 */
/* @0x1e278c mov r8, r9 */
/* @0x1e2790 mov r9, r11 */
/* @0x1e2794 str r3, [sp, #0x10] */
/* @0x1e2798 rsb r3, r2, r3 */
/* @0x1e279c str r3, [sp, #0x14] */
/* @0x1e27a0 ldr r3, [sp, #0x10] */
/* @0x1e27a4 ldr r2, [sp, #0x4] */
/* @0x1e27a8 cmp r3, #0 */
/* @0x1e27ac add r6, r8, r2 */
/* @0x1e27b0 ldrgt r2, [sp, #0x14] */
/* @0x1e27b4 sub r4, r6, #1 */
/* @0x1e27b8 addgt r5, r2, r6 */
/* @0x1e27bc ble 0x1e2814 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x2f8> */
/* @0x1e27c0 mov r0, r8 */
/* @0x1e27c4 mov r1, r10 */
/* @0x1e27c8 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x1e27cc mov r0, r4 */
/* @0x1e27d0 add r8, r8, #1 */
/* @0x1e27d4 sub r4, r4, #1 */
/* @0x1e27d8 mov r11, r1 */
/* @0x1e27dc mov r1, r10 */
/* @0x1e27e0 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x1e27e4 ldrb r3, [r9, r11] */
/* @0x1e27e8 cmp r8, r5 */
/* @0x1e27ec ldrb r2, [r9, r1] */
/* @0x1e27f0 eor r3, r2, r3 */
/* @0x1e27f4 strb r3, [r9, r11] */
/* @0x1e27f8 ldrb r2, [r9, r1] */
/* @0x1e27fc eor r3, r3, r2 */
/* @0x1e2800 strb r3, [r9, r1] */
/* @0x1e2804 ldrb r2, [r9, r11] */
/* @0x1e2808 eor r3, r3, r2 */
/* @0x1e280c strb r3, [r9, r11] */
/* @0x1e2810 bne 0x1e27c0 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x2a4> */
/* @0x1e2814 ldr r3, [sp, #0x8] */
/* @0x1e2818 add r7, r7, #1 */
/* @0x1e281c cmp r7, r3 */
/* @0x1e2820 movne r8, r6 */
/* @0x1e2824 bne 0x1e27a0 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x284> */
/* @0x1e2828 mov r11, r9 */
/* @0x1e282c ldr r2, [sp, #0xc] */
/* @0x1e2830 ldr r3, [sp, #0x18] */
/* @0x1e2834 ldr r4, [r2, #0x4] */
/* @0x1e2838 add r3, r3, #1 */
/* @0x1e283c str r3, [sp, #0x18] */
/* @0x1e2840 cmp r4, r3 */
/* @0x1e2844 bgt 0x1e2728 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x20c> */
/* @0x1e2848 ldr r3, [sp, #0xc] */
/* @0x1e284c mov r1, r10 */
/* @0x1e2850 ldr r2, [sp, #0x24] */
/* @0x1e2854 ldr r0, [r3, #0x14] */
/* @0x1e2858 add r2, r2, #1 */
/* @0x1e285c ldr r3, [sp, #0x20] */
/* @0x1e2860 str r2, [sp, #0x24] */
/* @0x1e2864 add r0, r3, r0 */
/* @0x1e2868 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x1e286c ldr r2, [sp, #0x24] */
/* @0x1e2870 ldr r3, [sp, #0x1c] */
/* @0x1e2874 cmp r2, r3 */
/* @0x1e2878 str r1, [sp, #0x20] */
/* @0x1e287c bne 0x1e2718 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1fc> */
/* @0x1e2880 add sp, sp, #44 */
/* @0x1e2884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1e2888 · F_VertexFormat_Add_Position(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x1e2888 ldr r3, [pc, #0x68] */
/* @0x1e288c push {r4, lr} */
/* @0x1e2890 ldr r3, [pc, r3] */
/* @0x1e2894 ldr r0, [r3] */
/* @0x1e2898 cmp r0, #0 */
/* @0x1e289c beq 0x1e28e4 <_Z27F_VertexFormat_Add_PositionR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1e28a0 ldr r4, [pc, #0x54] */
/* @0x1e28a4 ldr r4, [pc, r4] */
/* @0x1e28a8 ldr r3, [r4] */
/* @0x1e28ac cmp r3, #0 */
/* @0x1e28b0 beq 0x1e28d0 <_Z27F_VertexFormat_Add_PositionR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1e28b4 mov r1, #2 */
/* @0x1e28b8 mov r2, #1 */
/* @0x1e28bc bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej> */
/* @0x1e28c0 ldr r3, [r4] */
/* @0x1e28c4 lsl r3, r3, #1 */
/* @0x1e28c8 str r3, [r4] */
/* @0x1e28cc pop {r4, pc} */
/* @0x1e28d0 ldr r0, [pc, #0x28] */
/* @0x1e28d4 mov r1, r3 */
/* @0x1e28d8 pop {r4, lr} */
/* @0x1e28dc add r0, pc, r0 */
/* @0x1e28e0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e28e4 mov r1, r0 */
/* @0x1e28e8 ldr r0, [pc, #0x14] */
/* @0x1e28ec pop {r4, lr} */
/* @0x1e28f0 add r0, pc, r0 */
/* @0x1e28f4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e28f8 eoreq lr, r0, r0, lsl #10 */
/* @0x1e28fc .word 0x0020e4f0 */
/* @0x1e2900 andseq pc, r6, r12, lsl r7 */
/* @0x1e2904 andseq pc, r6, r12, asr #13 */

/* ── FUNC 0x1e2908 · F_VertexFormat_Add_Position3D(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x1e2908 ldr r3, [pc, #0x68] */
/* @0x1e290c push {r4, lr} */
/* @0x1e2910 ldr r3, [pc, r3] */
/* @0x1e2914 ldr r0, [r3] */
/* @0x1e2918 cmp r0, #0 */
/* @0x1e291c beq 0x1e2964 <_Z29F_VertexFormat_Add_Position3DR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1e2920 ldr r4, [pc, #0x54] */
/* @0x1e2924 ldr r4, [pc, r4] */
/* @0x1e2928 ldr r3, [r4] */
/* @0x1e292c cmp r3, #0 */
/* @0x1e2930 beq 0x1e2950 <_Z29F_VertexFormat_Add_Position3DR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1e2934 mov r1, #3 */
/* @0x1e2938 mov r2, #1 */
/* @0x1e293c bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej> */
/* @0x1e2940 ldr r3, [r4] */
/* @0x1e2944 lsl r3, r3, #1 */
/* @0x1e2948 str r3, [r4] */
/* @0x1e294c pop {r4, pc} */
/* @0x1e2950 ldr r0, [pc, #0x28] */
/* @0x1e2954 mov r1, r3 */
/* @0x1e2958 pop {r4, lr} */
/* @0x1e295c add r0, pc, r0 */
/* @0x1e2960 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2964 mov r1, r0 */
/* @0x1e2968 ldr r0, [pc, #0x14] */
/* @0x1e296c pop {r4, lr} */
/* @0x1e2970 add r0, pc, r0 */
/* @0x1e2974 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2978 eoreq lr, r0, r0, lsl #9 */
/* @0x1e297c eoreq lr, r0, r0, ror r4 */
/* @0x1e2980 andseq pc, r6, r12, lsl #14 */
/* @0x1e2984 ldrheq pc, [r6], -r8 */

/* ── FUNC 0x1e2988 · F_VertexFormat_Add_Normal(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x1e2988 ldr r3, [pc, #0x68] */
/* @0x1e298c push {r4, lr} */
/* @0x1e2990 ldr r3, [pc, r3] */
/* @0x1e2994 ldr r0, [r3] */
/* @0x1e2998 cmp r0, #0 */
/* @0x1e299c beq 0x1e29e4 <_Z25F_VertexFormat_Add_NormalR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1e29a0 ldr r4, [pc, #0x54] */
/* @0x1e29a4 ldr r4, [pc, r4] */
/* @0x1e29a8 ldr r3, [r4] */
/* @0x1e29ac cmp r3, #0 */
/* @0x1e29b0 beq 0x1e29d0 <_Z25F_VertexFormat_Add_NormalR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1e29b4 mov r1, #3 */
/* @0x1e29b8 mov r2, r1 */
/* @0x1e29bc bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej> */
/* @0x1e29c0 ldr r3, [r4] */
/* @0x1e29c4 lsl r3, r3, #1 */
/* @0x1e29c8 str r3, [r4] */
/* @0x1e29cc pop {r4, pc} */
/* @0x1e29d0 ldr r0, [pc, #0x28] */
/* @0x1e29d4 mov r1, r3 */
/* @0x1e29d8 pop {r4, lr} */
/* @0x1e29dc add r0, pc, r0 */
/* @0x1e29e0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e29e4 mov r1, r0 */
/* @0x1e29e8 ldr r0, [pc, #0x14] */
/* @0x1e29ec pop {r4, lr} */
/* @0x1e29f0 add r0, pc, r0 */
/* @0x1e29f4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e29f8 eoreq lr, r0, r0, lsl #8 */
/* @0x1e29fc .word 0x0020e3f0 */
/* @0x1e2a00 ldrsheq pc, [r6], -r12 */
/* @0x1e2a04 andseq pc, r6, r12, lsr #13 */

/* ── FUNC 0x1e2a08 · F_VertexFormat_Add_Colour(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x1e2a08 ldr r3, [pc, #0x68] */
/* @0x1e2a0c push {r4, lr} */
/* @0x1e2a10 ldr r3, [pc, r3] */
/* @0x1e2a14 ldr r0, [r3] */
/* @0x1e2a18 cmp r0, #0 */
/* @0x1e2a1c beq 0x1e2a64 <_Z25F_VertexFormat_Add_ColourR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1e2a20 ldr r4, [pc, #0x54] */
/* @0x1e2a24 ldr r4, [pc, r4] */
/* @0x1e2a28 ldr r3, [r4] */
/* @0x1e2a2c cmp r3, #0 */
/* @0x1e2a30 beq 0x1e2a50 <_Z25F_VertexFormat_Add_ColourR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1e2a34 mov r1, #5 */
/* @0x1e2a38 mov r2, #2 */
/* @0x1e2a3c bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej> */
/* @0x1e2a40 ldr r3, [r4] */
/* @0x1e2a44 lsl r3, r3, #1 */
/* @0x1e2a48 str r3, [r4] */
/* @0x1e2a4c pop {r4, pc} */
/* @0x1e2a50 ldr r0, [pc, #0x28] */
/* @0x1e2a54 mov r1, r3 */
/* @0x1e2a58 pop {r4, lr} */
/* @0x1e2a5c add r0, pc, r0 */
/* @0x1e2a60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2a64 mov r1, r0 */
/* @0x1e2a68 ldr r0, [pc, #0x14] */
/* @0x1e2a6c pop {r4, lr} */
/* @0x1e2a70 add r0, pc, r0 */
/* @0x1e2a74 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2a78 eoreq lr, r0, r0, lsl #7 */
/* @0x1e2a7c eoreq lr, r0, r0, ror r3 */
/* @0x1e2a80 andseq pc, r6, r8, ror #13 */
/* @0x1e2a84 mulseq r6, r8, r6 */

/* ── FUNC 0x1e2a88 · F_VertexFormat_Add_TextCoord(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x1e2a88 ldr r3, [pc, #0x68] */
/* @0x1e2a8c push {r4, lr} */
/* @0x1e2a90 ldr r3, [pc, r3] */
/* @0x1e2a94 ldr r0, [r3] */
/* @0x1e2a98 cmp r0, #0 */
/* @0x1e2a9c beq 0x1e2ae4 <_Z28F_VertexFormat_Add_TextCoordR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1e2aa0 ldr r4, [pc, #0x54] */
/* @0x1e2aa4 ldr r4, [pc, r4] */
/* @0x1e2aa8 ldr r3, [r4] */
/* @0x1e2aac cmp r3, #0 */
/* @0x1e2ab0 beq 0x1e2ad0 <_Z28F_VertexFormat_Add_TextCoordR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1e2ab4 mov r1, #2 */
/* @0x1e2ab8 mov r2, #4 */
/* @0x1e2abc bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej> */
/* @0x1e2ac0 ldr r3, [r4] */
/* @0x1e2ac4 lsl r3, r3, #1 */
/* @0x1e2ac8 str r3, [r4] */
/* @0x1e2acc pop {r4, pc} */
/* @0x1e2ad0 ldr r0, [pc, #0x28] */
/* @0x1e2ad4 mov r1, r3 */
/* @0x1e2ad8 pop {r4, lr} */
/* @0x1e2adc add r0, pc, r0 */
/* @0x1e2ae0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2ae4 mov r1, r0 */
/* @0x1e2ae8 ldr r0, [pc, #0x14] */
/* @0x1e2aec pop {r4, lr} */
/* @0x1e2af0 add r0, pc, r0 */
/* @0x1e2af4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2af8 eoreq lr, r0, r0, lsl #6 */
/* @0x1e2afc .word 0x0020e2f0 */
/* @0x1e2b00 ldrsbeq pc, [r6], -r8 */
/* @0x1e2b04 andseq pc, r6, r4, lsl #13 */

/* ── FUNC 0x1e2b08 · F_VertexFormat_Add_Custom(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x1e2b08 push {r3, r4, r5, lr} */
/* @0x1e2b0c mov r1, #0 */
/* @0x1e2b10 ldr r4, [sp, #0x10] */
/* @0x1e2b14 mov r0, r4 */
/* @0x1e2b18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e2b1c sub r3, r0, #1 */
/* @0x1e2b20 mov r5, r0 */
/* @0x1e2b24 cmp r3, #5 */
/* @0x1e2b28 bhi 0x1e2b8c <_Z25F_VertexFormat_Add_CustomR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1e2b2c mov r0, r4 */
/* @0x1e2b30 mov r1, #1 */
/* @0x1e2b34 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e2b38 sub r3, r0, #1 */
/* @0x1e2b3c cmp r3, #13 */
/* @0x1e2b40 bhi 0x1e2b78 <_Z25F_VertexFormat_Add_CustomR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1e2b44 ldr r3, [pc, #0x54] */
/* @0x1e2b48 mov r2, r0 */
/* @0x1e2b4c ldr r4, [pc, #0x50] */
/* @0x1e2b50 mov r1, r5 */
/* @0x1e2b54 ldr r3, [pc, r3] */
/* @0x1e2b58 ldr r4, [pc, r4] */
/* @0x1e2b5c ldr r0, [r3] */
/* @0x1e2b60 ldr r3, [r4] */
/* @0x1e2b64 bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej> */
/* @0x1e2b68 ldr r3, [r4] */
/* @0x1e2b6c lsl r3, r3, #1 */
/* @0x1e2b70 str r3, [r4] */
/* @0x1e2b74 pop {r3, r4, r5, pc} */
/* @0x1e2b78 ldr r0, [pc, #0x28] */
/* @0x1e2b7c mov r1, #0 */
/* @0x1e2b80 pop {r3, r4, r5, lr} */
/* @0x1e2b84 add r0, pc, r0 */
/* @0x1e2b88 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2b8c ldr r0, [pc, #0x18] */
/* @0x1e2b90 mov r1, #0 */
/* @0x1e2b94 pop {r3, r4, r5, lr} */
/* @0x1e2b98 add r0, pc, r0 */
/* @0x1e2b9c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2ba0 eoreq lr, r0, r12, lsr r2 */
/* @0x1e2ba4 eoreq lr, r0, r12, lsr r2 */
/* @0x1e2ba8 mulseq r6, r0, r6 */
/* @0x1e2bac andseq pc, r6, r0, asr r6 */
