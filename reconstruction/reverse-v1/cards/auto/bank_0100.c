/* libyoyo.so 覆盖卡组 0100
 * 函数 0x162360..0x1637d4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x162360 · F_SteamUGC_QuerySetSearchText(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x162360 mov r2, #0 */
/* @0x162364 mov r3, r2 */
/* @0x162368 movt r2, #0xbff0 */
/* @0x16236c str r3, [r0, #0xc] */
/* @0x162370 str r2, [r0, #0x4] */
/* @0x162374 str r3, [r0] */
/* @0x162378 bx lr */

/* ── FUNC 0x16237c · F_SteamUGC_QuerySetRankedByTrendDays(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x16237c mov r2, #0 */
/* @0x162380 mov r3, r2 */
/* @0x162384 movt r2, #0xbff0 */
/* @0x162388 str r3, [r0, #0xc] */
/* @0x16238c str r2, [r0, #0x4] */
/* @0x162390 str r3, [r0] */
/* @0x162394 bx lr */

/* ── FUNC 0x162398 · F_SteamUGC_QueryAddRequiredTag(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x162398 mov r2, #0 */
/* @0x16239c mov r3, r2 */
/* @0x1623a0 movt r2, #0xbff0 */
/* @0x1623a4 str r3, [r0, #0xc] */
/* @0x1623a8 str r2, [r0, #0x4] */
/* @0x1623ac str r3, [r0] */
/* @0x1623b0 bx lr */

/* ── FUNC 0x1623b4 · F_SteamUGC_QueryAddExcludedTag(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x1623b4 mov r2, #0 */
/* @0x1623b8 mov r3, r2 */
/* @0x1623bc movt r2, #0xbff0 */
/* @0x1623c0 str r3, [r0, #0xc] */
/* @0x1623c4 str r2, [r0, #0x4] */
/* @0x1623c8 str r3, [r0] */
/* @0x1623cc bx lr */

/* ── FUNC 0x1623d0 · F_SteamUGC_SetReturnLongDesc(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x1623d0 mov r2, #0 */
/* @0x1623d4 mov r3, r2 */
/* @0x1623d8 movt r2, #0xbff0 */
/* @0x1623dc str r3, [r0, #0xc] */
/* @0x1623e0 str r2, [r0, #0x4] */
/* @0x1623e4 str r3, [r0] */
/* @0x1623e8 bx lr */

/* ── FUNC 0x1623ec · F_SteamUGC_QuerySetReturnTotalOnly(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x1623ec mov r2, #0 */
/* @0x1623f0 mov r3, r2 */
/* @0x1623f4 movt r2, #0xbff0 */
/* @0x1623f8 str r3, [r0, #0xc] */
/* @0x1623fc str r2, [r0, #0x4] */
/* @0x162400 str r3, [r0] */
/* @0x162404 bx lr */

/* ── FUNC 0x162408 · F_SteamUGC_QuerySetAllowCachedResponse(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x162408 mov r2, #0 */
/* @0x16240c mov r3, r2 */
/* @0x162410 movt r2, #0xbff0 */
/* @0x162414 str r3, [r0, #0xc] */
/* @0x162418 str r2, [r0, #0x4] */
/* @0x16241c str r3, [r0] */
/* @0x162420 bx lr */

/* ── FUNC 0x162424 · F_SteamUGC_SendQuery(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x162424 mov r2, #0 */
/* @0x162428 mov r3, r2 */
/* @0x16242c movt r2, #0xbff0 */
/* @0x162430 str r3, [r0, #0xc] */
/* @0x162434 str r2, [r0, #0x4] */
/* @0x162438 str r3, [r0] */
/* @0x16243c bx lr */

/* ── FUNC 0x162440 · F_Steam_ActivateOverlay(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x162440 push {r4, lr} */
/* @0x162444 mov r1, #0 */
/* @0x162448 mov r4, r0 */
/* @0x16244c ldr r0, [sp, #0x8] */
/* @0x162450 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x162454 mov r2, #0 */
/* @0x162458 mov r3, r2 */
/* @0x16245c movt r2, #0xbff0 */
/* @0x162460 str r3, [r4, #0xc] */
/* @0x162464 str r2, [r4, #0x4] */
/* @0x162468 str r3, [r4] */
/* @0x16246c pop {r4, pc} */

/* ── FUNC 0x162470 · F_Steam_GetPersonalName(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x162470 mov r1, #0 */
/* @0x162474 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x162478 · F_Steam_FileRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x162478 mov r1, #0 */
/* @0x16247c b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x162480 · F_SteamCurrentGameLanguage(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x162480 mov r1, #0 */
/* @0x162484 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x162488 · F_SteamAvailableGameLanguages(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x162488 mov r1, #0 */
/* @0x16248c b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x162490 · GetSteamHandle(RValue*, int) · size=4 · insn=1 */
/* @0x162490 b 0xcea30 <_Z10YYGetInt64PK6RValuei> */

/* ── FUNC 0x162494 · SetSteamHandle(RValue&, unsigned long long) · size=16 · insn=4 */
/* @0x162494 mov r1, #10 */
/* @0x162498 stm r0, {r2, r3} */
/* @0x16249c str r1, [r0, #0xc] */
/* @0x1624a0 bx lr */

/* ── FUNC 0x1624a4 · F_SteamUGC_CreateQueryUser(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x1624a4 mvn r2, #0 */
/* @0x1624a8 mvn r3, #0 */
/* @0x1624ac b 0x162494 <_Z14SetSteamHandleR6RValuey> */

/* ── FUNC 0x1624b0 · F_SteamUGC_CreateQueryUserEx(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x1624b0 mvn r2, #0 */
/* @0x1624b4 mvn r3, #0 */
/* @0x1624b8 b 0x162494 <_Z14SetSteamHandleR6RValuey> */

/* ── FUNC 0x1624bc · F_SteamUGC_CreateQueryAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x1624bc mvn r2, #0 */
/* @0x1624c0 mvn r3, #0 */
/* @0x1624c4 b 0x162494 <_Z14SetSteamHandleR6RValuey> */

/* ── FUNC 0x1624c8 · F_SteamUGC_CreateQueryAllEx(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x1624c8 mvn r2, #0 */
/* @0x1624cc mvn r3, #0 */
/* @0x1624d0 b 0x162494 <_Z14SetSteamHandleR6RValuey> */

/* ── FUNC 0x1624d4 · ValidateArgs(int, RValue*, int, ...) · size=184 · insn=46 */
/* @0x1624d4 push {r2, r3} */
/* @0x1624d8 push {r4, lr} */
/* @0x1624dc sub sp, sp, #8 */
/* @0x1624e0 ldr r3, [sp, #0x10] */
/* @0x1624e4 cmp r0, r3 */
/* @0x1624e8 bne 0x16253c <_Z12ValidateArgsiP6RValueiz+0x68> */
/* @0x1624ec cmp r0, #0 */
/* @0x1624f0 ble 0x162528 <_Z12ValidateArgsiP6RValueiz+0x54> */
/* @0x1624f4 add r3, sp, #24 */
/* @0x1624f8 mov r2, #0 */
/* @0x1624fc add r12, sp, #20 */
/* @0x162500 str r12, [sp, #0x4] */
/* @0x162504 ldr r4, [r1, #0xc] */
/* @0x162508 add r2, r2, #1 */
/* @0x16250c ldr r12, [r3, #-0x4] */
/* @0x162510 add r1, r1, #16 */
/* @0x162514 add r3, r3, #4 */
/* @0x162518 cmp r4, r12 */
/* @0x16251c bne 0x162560 <_Z12ValidateArgsiP6RValueiz+0x8c> */
/* @0x162520 cmp r2, r0 */
/* @0x162524 bne 0x162504 <_Z12ValidateArgsiP6RValueiz+0x30> */
/* @0x162528 mov r0, #1 */
/* @0x16252c add sp, sp, #8 */
/* @0x162530 pop {r4, lr} */
/* @0x162534 add sp, sp, #8 */
/* @0x162538 bx lr */
/* @0x16253c ldr r0, [pc, #0x40] */
/* @0x162540 mov r1, #0 */
/* @0x162544 add r0, pc, r0 */
/* @0x162548 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x16254c mov r0, #0 */
/* @0x162550 add sp, sp, #8 */
/* @0x162554 pop {r4, lr} */
/* @0x162558 add sp, sp, #8 */
/* @0x16255c bx lr */
/* @0x162560 ldr r0, [pc, #0x20] */
/* @0x162564 mov r1, #0 */
/* @0x162568 add r0, pc, r0 */
/* @0x16256c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x162570 mov r0, #0 */
/* @0x162574 add sp, sp, #8 */
/* @0x162578 pop {r4, lr} */
/* @0x16257c add sp, sp, #8 */
/* @0x162580 bx lr */
/* @0x162584 andseq r4, lr, r4, lsl #1 */
/* @0x162588 andseq r0, lr, r4, asr #8 */

/* ── FUNC 0x16258c · InitSteamFunctions() · size=3044 · insn=761 */
/* @0x16258c push {r4, lr} */
/* @0x162590 mov r2, #1 */
/* @0x162594 ldr r4, [pc, #0x930] */
/* @0x162598 mov r3, #0 */
/* @0x16259c ldr r1, [pc, #0x92c] */
/* @0x1625a0 add r4, pc, r4 */
/* @0x1625a4 ldr r0, [pc, #0x928] */
/* @0x1625a8 ldr r1, [r4, r1] */
/* @0x1625ac add r0, pc, r0 */
/* @0x1625b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1625b4 ldr r1, [pc, #0x91c] */
/* @0x1625b8 ldr r0, [pc, #0x91c] */
/* @0x1625bc mov r2, #0 */
/* @0x1625c0 mov r3, r2 */
/* @0x1625c4 ldr r1, [r4, r1] */
/* @0x1625c8 add r0, pc, r0 */
/* @0x1625cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1625d0 ldr r1, [pc, #0x908] */
/* @0x1625d4 ldr r0, [pc, #0x908] */
/* @0x1625d8 mov r2, #0 */
/* @0x1625dc mov r3, r2 */
/* @0x1625e0 ldr r1, [r4, r1] */
/* @0x1625e4 add r0, pc, r0 */
/* @0x1625e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1625ec ldr r1, [pc, #0x8f4] */
/* @0x1625f0 ldr r0, [pc, #0x8f4] */
/* @0x1625f4 mov r2, #0 */
/* @0x1625f8 mov r3, r2 */
/* @0x1625fc ldr r1, [r4, r1] */
/* @0x162600 add r0, pc, r0 */
/* @0x162604 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162608 ldr r1, [pc, #0x8e0] */
/* @0x16260c ldr r0, [pc, #0x8e0] */
/* @0x162610 mov r2, #0 */
/* @0x162614 mov r3, r2 */
/* @0x162618 ldr r1, [r4, r1] */
/* @0x16261c add r0, pc, r0 */
/* @0x162620 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162624 ldr r1, [pc, #0x8cc] */
/* @0x162628 ldr r0, [pc, #0x8cc] */
/* @0x16262c mov r2, #0 */
/* @0x162630 mov r3, r2 */
/* @0x162634 ldr r1, [r4, r1] */
/* @0x162638 add r0, pc, r0 */
/* @0x16263c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162640 ldr r1, [pc, #0x8b8] */
/* @0x162644 ldr r0, [pc, #0x8b8] */
/* @0x162648 mov r2, #0 */
/* @0x16264c mov r3, r2 */
/* @0x162650 ldr r1, [r4, r1] */
/* @0x162654 add r0, pc, r0 */
/* @0x162658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16265c ldr r1, [pc, #0x8a4] */
/* @0x162660 ldr r0, [pc, #0x8a4] */
/* @0x162664 mov r2, #1 */
/* @0x162668 mov r3, #0 */
/* @0x16266c ldr r1, [r4, r1] */
/* @0x162670 add r0, pc, r0 */
/* @0x162674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162678 ldr r1, [pc, #0x890] */
/* @0x16267c ldr r0, [pc, #0x890] */
/* @0x162680 mov r2, #0 */
/* @0x162684 mov r3, r2 */
/* @0x162688 ldr r1, [r4, r1] */
/* @0x16268c add r0, pc, r0 */
/* @0x162690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162694 ldr r1, [pc, #0x87c] */
/* @0x162698 ldr r0, [pc, #0x87c] */
/* @0x16269c mov r2, #0 */
/* @0x1626a0 mov r3, r2 */
/* @0x1626a4 ldr r1, [r4, r1] */
/* @0x1626a8 add r0, pc, r0 */
/* @0x1626ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1626b0 ldr r1, [pc, #0x868] */
/* @0x1626b4 ldr r0, [pc, #0x868] */
/* @0x1626b8 mov r2, #3 */
/* @0x1626bc mov r3, #0 */
/* @0x1626c0 ldr r1, [r4, r1] */
/* @0x1626c4 add r0, pc, r0 */
/* @0x1626c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1626cc ldr r1, [pc, #0x854] */
/* @0x1626d0 ldr r0, [pc, #0x854] */
/* @0x1626d4 mov r2, #2 */
/* @0x1626d8 mov r3, #0 */
/* @0x1626dc ldr r1, [r4, r1] */
/* @0x1626e0 add r0, pc, r0 */
/* @0x1626e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1626e8 ldr r1, [pc, #0x840] */
/* @0x1626ec ldr r0, [pc, #0x840] */
/* @0x1626f0 mov r2, #1 */
/* @0x1626f4 mov r3, #0 */
/* @0x1626f8 ldr r1, [r4, r1] */
/* @0x1626fc add r0, pc, r0 */
/* @0x162700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162704 ldr r1, [pc, #0x82c] */
/* @0x162708 ldr r0, [pc, #0x82c] */
/* @0x16270c mov r2, #1 */
/* @0x162710 mov r3, #0 */
/* @0x162714 ldr r1, [r4, r1] */
/* @0x162718 add r0, pc, r0 */
/* @0x16271c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162720 ldr r1, [pc, #0x818] */
/* @0x162724 ldr r0, [pc, #0x818] */
/* @0x162728 mov r2, #1 */
/* @0x16272c mov r3, #0 */
/* @0x162730 ldr r1, [r4, r1] */
/* @0x162734 add r0, pc, r0 */
/* @0x162738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16273c ldr r1, [pc, #0x804] */
/* @0x162740 ldr r0, [pc, #0x804] */
/* @0x162744 mov r2, #1 */
/* @0x162748 mov r3, #0 */
/* @0x16274c ldr r1, [r4, r1] */
/* @0x162750 add r0, pc, r0 */
/* @0x162754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162758 ldr r1, [pc, #0x7f0] */
/* @0x16275c ldr r0, [pc, #0x7f0] */
/* @0x162760 mov r2, #1 */
/* @0x162764 mov r3, #0 */
/* @0x162768 ldr r1, [r4, r1] */
/* @0x16276c add r0, pc, r0 */
/* @0x162770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162774 ldr r1, [pc, #0x7dc] */
/* @0x162778 ldr r0, [pc, #0x7dc] */
/* @0x16277c mov r2, #4 */
/* @0x162780 mov r3, #0 */
/* @0x162784 ldr r1, [r4, r1] */
/* @0x162788 add r0, pc, r0 */
/* @0x16278c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162790 ldr r1, [pc, #0x7c8] */
/* @0x162794 ldr r0, [pc, #0x7c8] */
/* @0x162798 mov r2, #0 */
/* @0x16279c mov r3, r2 */
/* @0x1627a0 ldr r1, [r4, r1] */
/* @0x1627a4 add r0, pc, r0 */
/* @0x1627a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1627ac ldr r1, [pc, #0x7b4] */
/* @0x1627b0 ldr r0, [pc, #0x7b4] */
/* @0x1627b4 mov r2, #3 */
/* @0x1627b8 mov r3, #0 */
/* @0x1627bc ldr r1, [r4, r1] */
/* @0x1627c0 add r0, pc, r0 */
/* @0x1627c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1627c8 ldr r1, [pc, #0x7a0] */
/* @0x1627cc ldr r0, [pc, #0x7a0] */
/* @0x1627d0 mov r2, #0 */
/* @0x1627d4 mov r3, r2 */
/* @0x1627d8 ldr r1, [r4, r1] */
/* @0x1627dc add r0, pc, r0 */
/* @0x1627e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1627e4 ldr r1, [pc, #0x78c] */
/* @0x1627e8 ldr r0, [pc, #0x78c] */
/* @0x1627ec mov r2, #0 */
/* @0x1627f0 mov r3, r2 */
/* @0x1627f4 ldr r1, [r4, r1] */
/* @0x1627f8 add r0, pc, r0 */
/* @0x1627fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162800 ldr r1, [pc, #0x778] */
/* @0x162804 ldr r0, [pc, #0x778] */
/* @0x162808 mov r2, #1 */
/* @0x16280c mov r3, #0 */
/* @0x162810 ldr r1, [r4, r1] */
/* @0x162814 add r0, pc, r0 */
/* @0x162818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16281c ldr r1, [pc, #0x764] */
/* @0x162820 ldr r0, [pc, #0x764] */
/* @0x162824 mov r2, #1 */
/* @0x162828 mov r3, #0 */
/* @0x16282c ldr r1, [r4, r1] */
/* @0x162830 add r0, pc, r0 */
/* @0x162834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162838 ldr r1, [pc, #0x750] */
/* @0x16283c ldr r0, [pc, #0x750] */
/* @0x162840 mov r2, #1 */
/* @0x162844 mov r3, #0 */
/* @0x162848 ldr r1, [r4, r1] */
/* @0x16284c add r0, pc, r0 */
/* @0x162850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162854 ldr r1, [pc, #0x73c] */
/* @0x162858 ldr r0, [pc, #0x73c] */
/* @0x16285c mov r2, #1 */
/* @0x162860 mov r3, #0 */
/* @0x162864 ldr r1, [r4, r1] */
/* @0x162868 add r0, pc, r0 */
/* @0x16286c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162870 ldr r1, [pc, #0x728] */
/* @0x162874 ldr r0, [pc, #0x728] */
/* @0x162878 mov r2, #1 */
/* @0x16287c mov r3, #0 */
/* @0x162880 ldr r1, [r4, r1] */
/* @0x162884 add r0, pc, r0 */
/* @0x162888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16288c ldr r1, [pc, #0x714] */
/* @0x162890 ldr r0, [pc, #0x714] */
/* @0x162894 mov r2, #2 */
/* @0x162898 mov r3, #0 */
/* @0x16289c ldr r1, [r4, r1] */
/* @0x1628a0 add r0, pc, r0 */
/* @0x1628a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1628a8 ldr r1, [pc, #0x700] */
/* @0x1628ac ldr r0, [pc, #0x700] */
/* @0x1628b0 mov r2, #1 */
/* @0x1628b4 mov r3, #0 */
/* @0x1628b8 ldr r1, [r4, r1] */
/* @0x1628bc add r0, pc, r0 */
/* @0x1628c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1628c4 ldr r1, [pc, #0x6ec] */
/* @0x1628c8 ldr r0, [pc, #0x6ec] */
/* @0x1628cc mov r2, #1 */
/* @0x1628d0 mov r3, #0 */
/* @0x1628d4 ldr r1, [r4, r1] */
/* @0x1628d8 add r0, pc, r0 */
/* @0x1628dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1628e0 ldr r1, [pc, #0x6d8] */
/* @0x1628e4 ldr r0, [pc, #0x6d8] */
/* @0x1628e8 mov r2, #1 */
/* @0x1628ec mov r3, #0 */
/* @0x1628f0 ldr r1, [r4, r1] */
/* @0x1628f4 add r0, pc, r0 */
/* @0x1628f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1628fc ldr r1, [pc, #0x6c4] */
/* @0x162900 ldr r0, [pc, #0x6c4] */
/* @0x162904 mov r2, #1 */
/* @0x162908 mov r3, #0 */
/* @0x16290c ldr r1, [r4, r1] */
/* @0x162910 add r0, pc, r0 */
/* @0x162914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162918 ldr r1, [pc, #0x6b0] */
/* @0x16291c ldr r0, [pc, #0x6b0] */
/* @0x162920 mov r2, #1 */
/* @0x162924 mov r3, #0 */
/* @0x162928 ldr r1, [r4, r1] */
/* @0x16292c add r0, pc, r0 */
/* @0x162930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162934 ldr r1, [pc, #0x69c] */
/* @0x162938 ldr r0, [pc, #0x69c] */
/* @0x16293c mov r2, #2 */
/* @0x162940 mov r3, #0 */
/* @0x162944 ldr r1, [r4, r1] */
/* @0x162948 add r0, pc, r0 */
/* @0x16294c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162950 ldr r1, [pc, #0x688] */
/* @0x162954 ldr r0, [pc, #0x688] */
/* @0x162958 mov r2, #2 */
/* @0x16295c mov r3, #0 */
/* @0x162960 ldr r1, [r4, r1] */
/* @0x162964 add r0, pc, r0 */
/* @0x162968 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16296c ldr r1, [pc, #0x674] */
/* @0x162970 ldr r0, [pc, #0x674] */
/* @0x162974 mov r2, #3 */
/* @0x162978 mov r3, #0 */
/* @0x16297c ldr r1, [r4, r1] */
/* @0x162980 add r0, pc, r0 */
/* @0x162984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162988 ldr r1, [pc, #0x660] */
/* @0x16298c ldr r0, [pc, #0x660] */
/* @0x162990 mov r2, #1 */
/* @0x162994 mov r3, #0 */
/* @0x162998 ldr r1, [r4, r1] */
/* @0x16299c add r0, pc, r0 */
/* @0x1629a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1629a4 ldr r1, [pc, #0x64c] */
/* @0x1629a8 ldr r0, [pc, #0x64c] */
/* @0x1629ac mov r2, #1 */
/* @0x1629b0 mov r3, #0 */
/* @0x1629b4 ldr r1, [r4, r1] */
/* @0x1629b8 add r0, pc, r0 */
/* @0x1629bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1629c0 ldr r1, [pc, #0x638] */
/* @0x1629c4 ldr r0, [pc, #0x638] */
/* @0x1629c8 mov r2, #1 */
/* @0x1629cc mov r3, #0 */
/* @0x1629d0 ldr r1, [r4, r1] */
/* @0x1629d4 add r0, pc, r0 */
/* @0x1629d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1629dc ldr r1, [pc, #0x624] */
/* @0x1629e0 ldr r0, [pc, #0x624] */
/* @0x1629e4 mov r2, #0 */
/* @0x1629e8 mov r3, r2 */
/* @0x1629ec ldr r1, [r4, r1] */
/* @0x1629f0 add r0, pc, r0 */
/* @0x1629f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1629f8 ldr r1, [pc, #0x610] */
/* @0x1629fc ldr r0, [pc, #0x610] */
/* @0x162a00 mov r2, #0 */
/* @0x162a04 mov r3, r2 */
/* @0x162a08 ldr r1, [r4, r1] */
/* @0x162a0c add r0, pc, r0 */
/* @0x162a10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162a14 ldr r1, [pc, #0x5fc] */
/* @0x162a18 ldr r0, [pc, #0x5fc] */
/* @0x162a1c mov r2, #0 */
/* @0x162a20 mov r3, r2 */
/* @0x162a24 ldr r1, [r4, r1] */
/* @0x162a28 add r0, pc, r0 */
/* @0x162a2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162a30 ldr r1, [pc, #0x5e8] */
/* @0x162a34 ldr r0, [pc, #0x5e8] */
/* @0x162a38 mov r2, #3 */
/* @0x162a3c mov r3, #0 */
/* @0x162a40 ldr r1, [r4, r1] */
/* @0x162a44 add r0, pc, r0 */
/* @0x162a48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162a4c ldr r1, [pc, #0x5d4] */
/* @0x162a50 ldr r0, [pc, #0x5d4] */
/* @0x162a54 mov r2, #2 */
/* @0x162a58 mov r3, #0 */
/* @0x162a5c ldr r1, [r4, r1] */
/* @0x162a60 add r0, pc, r0 */
/* @0x162a64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162a68 ldr r1, [pc, #0x5c0] */
/* @0x162a6c ldr r0, [pc, #0x5c0] */
/* @0x162a70 mov r2, #3 */
/* @0x162a74 mov r3, #0 */
/* @0x162a78 ldr r1, [r4, r1] */
/* @0x162a7c add r0, pc, r0 */
/* @0x162a80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162a84 ldr r1, [pc, #0x5ac] */
/* @0x162a88 ldr r0, [pc, #0x5ac] */
/* @0x162a8c mov r2, #3 */
/* @0x162a90 mov r3, #0 */
/* @0x162a94 ldr r1, [r4, r1] */
/* @0x162a98 add r0, pc, r0 */
/* @0x162a9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162aa0 ldr r1, [pc, #0x598] */
/* @0x162aa4 ldr r0, [pc, #0x598] */
/* @0x162aa8 mov r2, #1 */
/* @0x162aac mov r3, #0 */
/* @0x162ab0 ldr r1, [r4, r1] */
/* @0x162ab4 add r0, pc, r0 */
/* @0x162ab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162abc ldr r1, [pc, #0x584] */
/* @0x162ac0 ldr r0, [pc, #0x584] */
/* @0x162ac4 mov r2, #3 */
/* @0x162ac8 mov r3, #0 */
/* @0x162acc ldr r1, [r4, r1] */
/* @0x162ad0 add r0, pc, r0 */
/* @0x162ad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162ad8 ldr r1, [pc, #0x570] */
/* @0x162adc ldr r0, [pc, #0x570] */
/* @0x162ae0 mov r2, #3 */
/* @0x162ae4 mov r3, #0 */
/* @0x162ae8 ldr r1, [r4, r1] */
/* @0x162aec add r0, pc, r0 */
/* @0x162af0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162af4 ldr r1, [pc, #0x55c] */
/* @0x162af8 ldr r0, [pc, #0x55c] */
/* @0x162afc mov r2, #4 */
/* @0x162b00 mov r3, #0 */
/* @0x162b04 ldr r1, [r4, r1] */
/* @0x162b08 add r0, pc, r0 */
/* @0x162b0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162b10 ldr r1, [pc, #0x548] */
/* @0x162b14 ldr r0, [pc, #0x548] */
/* @0x162b18 mov r2, #0 */
/* @0x162b1c mov r3, r2 */
/* @0x162b20 ldr r1, [r4, r1] */
/* @0x162b24 add r0, pc, r0 */
/* @0x162b28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162b2c ldr r1, [pc, #0x534] */
/* @0x162b30 ldr r0, [pc, #0x534] */
/* @0x162b34 mov r2, #0 */
/* @0x162b38 mov r3, r2 */
/* @0x162b3c ldr r1, [r4, r1] */
/* @0x162b40 add r0, pc, r0 */
/* @0x162b44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162b48 ldr r1, [pc, #0x520] */
/* @0x162b4c ldr r0, [pc, #0x520] */
/* @0x162b50 mov r2, #2 */
/* @0x162b54 mov r3, #0 */
/* @0x162b58 ldr r1, [r4, r1] */
/* @0x162b5c add r0, pc, r0 */
/* @0x162b60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162b64 ldr r1, [pc, #0x50c] */
/* @0x162b68 ldr r0, [pc, #0x50c] */
/* @0x162b6c mov r2, #2 */
/* @0x162b70 mov r3, #0 */
/* @0x162b74 ldr r1, [r4, r1] */
/* @0x162b78 add r0, pc, r0 */
/* @0x162b7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162b80 ldr r1, [pc, #0x4f8] */
/* @0x162b84 ldr r0, [pc, #0x4f8] */
/* @0x162b88 mov r2, #2 */
/* @0x162b8c mov r3, #0 */
/* @0x162b90 ldr r1, [r4, r1] */
/* @0x162b94 add r0, pc, r0 */
/* @0x162b98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162b9c ldr r1, [pc, #0x4e4] */
/* @0x162ba0 ldr r0, [pc, #0x4e4] */
/* @0x162ba4 mov r2, #2 */
/* @0x162ba8 mov r3, #0 */
/* @0x162bac ldr r1, [r4, r1] */
/* @0x162bb0 add r0, pc, r0 */
/* @0x162bb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162bb8 ldr r1, [pc, #0x4d0] */
/* @0x162bbc ldr r0, [pc, #0x4d0] */
/* @0x162bc0 mov r2, #2 */
/* @0x162bc4 mov r3, #0 */
/* @0x162bc8 ldr r1, [r4, r1] */
/* @0x162bcc add r0, pc, r0 */
/* @0x162bd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162bd4 ldr r1, [pc, #0x4bc] */
/* @0x162bd8 ldr r0, [pc, #0x4bc] */
/* @0x162bdc mov r2, #2 */
/* @0x162be0 mov r3, #0 */
/* @0x162be4 ldr r1, [r4, r1] */
/* @0x162be8 add r0, pc, r0 */
/* @0x162bec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162bf0 ldr r1, [pc, #0x4a8] */
/* @0x162bf4 ldr r0, [pc, #0x4a8] */
/* @0x162bf8 mov r2, #2 */
/* @0x162bfc mov r3, #0 */
/* @0x162c00 ldr r1, [r4, r1] */
/* @0x162c04 add r0, pc, r0 */
/* @0x162c08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162c0c ldr r1, [pc, #0x494] */
/* @0x162c10 ldr r0, [pc, #0x494] */
/* @0x162c14 mov r2, #2 */
/* @0x162c18 mov r3, #0 */
/* @0x162c1c ldr r1, [r4, r1] */
/* @0x162c20 add r0, pc, r0 */
/* @0x162c24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162c28 ldr r1, [pc, #0x480] */
/* @0x162c2c ldr r0, [pc, #0x480] */
/* @0x162c30 mov r2, #2 */
/* @0x162c34 mov r3, #0 */
/* @0x162c38 ldr r1, [r4, r1] */
/* @0x162c3c add r0, pc, r0 */
/* @0x162c40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162c44 ldr r1, [pc, #0x46c] */
/* @0x162c48 ldr r0, [pc, #0x46c] */
/* @0x162c4c mov r2, #2 */
/* @0x162c50 mov r3, #0 */
/* @0x162c54 ldr r1, [r4, r1] */
/* @0x162c58 add r0, pc, r0 */
/* @0x162c5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162c60 ldr r1, [pc, #0x458] */
/* @0x162c64 ldr r0, [pc, #0x458] */
/* @0x162c68 mov r2, #1 */
/* @0x162c6c mov r3, #0 */
/* @0x162c70 ldr r1, [r4, r1] */
/* @0x162c74 add r0, pc, r0 */
/* @0x162c78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162c7c ldr r1, [pc, #0x444] */
/* @0x162c80 ldr r0, [pc, #0x444] */
/* @0x162c84 mov r2, #1 */
/* @0x162c88 mov r3, #0 */
/* @0x162c8c ldr r1, [r4, r1] */
/* @0x162c90 add r0, pc, r0 */
/* @0x162c94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162c98 ldr r1, [pc, #0x430] */
/* @0x162c9c ldr r0, [pc, #0x430] */
/* @0x162ca0 mov r2, #1 */
/* @0x162ca4 mov r3, #0 */
/* @0x162ca8 ldr r1, [r4, r1] */
/* @0x162cac add r0, pc, r0 */
/* @0x162cb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162cb4 ldr r1, [pc, #0x41c] */
/* @0x162cb8 ldr r0, [pc, #0x41c] */
/* @0x162cbc mov r2, #0 */
/* @0x162cc0 mov r3, r2 */
/* @0x162cc4 ldr r1, [r4, r1] */
/* @0x162cc8 add r0, pc, r0 */
/* @0x162ccc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162cd0 ldr r1, [pc, #0x408] */
/* @0x162cd4 ldr r0, [pc, #0x408] */
/* @0x162cd8 mov r2, #1 */
/* @0x162cdc mov r3, #0 */
/* @0x162ce0 ldr r1, [r4, r1] */
/* @0x162ce4 add r0, pc, r0 */
/* @0x162ce8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162cec ldr r1, [pc, #0x3f4] */
/* @0x162cf0 ldr r0, [pc, #0x3f4] */
/* @0x162cf4 mov r2, #2 */
/* @0x162cf8 mov r3, #0 */
/* @0x162cfc ldr r1, [r4, r1] */
/* @0x162d00 add r0, pc, r0 */
/* @0x162d04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162d08 ldr r1, [pc, #0x3e0] */
/* @0x162d0c ldr r0, [pc, #0x3e0] */
/* @0x162d10 mov r2, #2 */
/* @0x162d14 mov r3, #0 */
/* @0x162d18 ldr r1, [r4, r1] */
/* @0x162d1c add r0, pc, r0 */
/* @0x162d20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162d24 ldr r1, [pc, #0x3cc] */
/* @0x162d28 ldr r0, [pc, #0x3cc] */
/* @0x162d2c mov r2, #2 */
/* @0x162d30 mov r3, #0 */
/* @0x162d34 ldr r1, [r4, r1] */
/* @0x162d38 add r0, pc, r0 */
/* @0x162d3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162d40 ldr r1, [pc, #0x3b8] */
/* @0x162d44 ldr r0, [pc, #0x3b8] */
/* @0x162d48 mov r2, #4 */
/* @0x162d4c mov r3, #0 */
/* @0x162d50 ldr r1, [r4, r1] */
/* @0x162d54 add r0, pc, r0 */
/* @0x162d58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162d5c ldr r1, [pc, #0x3a4] */
/* @0x162d60 ldr r0, [pc, #0x3a4] */
/* @0x162d64 mov r2, #7 */
/* @0x162d68 mov r3, #0 */
/* @0x162d6c ldr r1, [r4, r1] */
/* @0x162d70 add r0, pc, r0 */
/* @0x162d74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162d78 ldr r1, [pc, #0x390] */
/* @0x162d7c ldr r0, [pc, #0x390] */
/* @0x162d80 mov r2, #3 */
/* @0x162d84 mov r3, #0 */
/* @0x162d88 ldr r1, [r4, r1] */
/* @0x162d8c add r0, pc, r0 */
/* @0x162d90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162d94 ldr r1, [pc, #0x37c] */
/* @0x162d98 ldr r0, [pc, #0x37c] */
/* @0x162d9c mov r2, #5 */
/* @0x162da0 mov r3, #0 */
/* @0x162da4 ldr r1, [r4, r1] */
/* @0x162da8 add r0, pc, r0 */
/* @0x162dac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162db0 ldr r1, [pc, #0x368] */
/* @0x162db4 ldr r0, [pc, #0x368] */
/* @0x162db8 mov r2, #2 */
/* @0x162dbc mov r3, #0 */
/* @0x162dc0 ldr r1, [r4, r1] */
/* @0x162dc4 add r0, pc, r0 */
/* @0x162dc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162dcc ldr r1, [pc, #0x354] */
/* @0x162dd0 ldr r0, [pc, #0x354] */
/* @0x162dd4 mov r2, #2 */
/* @0x162dd8 mov r3, #0 */
/* @0x162ddc ldr r1, [r4, r1] */
/* @0x162de0 add r0, pc, r0 */
/* @0x162de4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162de8 ldr r1, [pc, #0x340] */
/* @0x162dec ldr r0, [pc, #0x340] */
/* @0x162df0 mov r2, #2 */
/* @0x162df4 mov r3, #0 */
/* @0x162df8 ldr r1, [r4, r1] */
/* @0x162dfc add r0, pc, r0 */
/* @0x162e00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162e04 ldr r1, [pc, #0x32c] */
/* @0x162e08 ldr r0, [pc, #0x32c] */
/* @0x162e0c mov r2, #2 */
/* @0x162e10 mov r3, #0 */
/* @0x162e14 ldr r1, [r4, r1] */
/* @0x162e18 add r0, pc, r0 */
/* @0x162e1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162e20 ldr r1, [pc, #0x318] */
/* @0x162e24 ldr r0, [pc, #0x318] */
/* @0x162e28 mov r2, #2 */
/* @0x162e2c mov r3, #0 */
/* @0x162e30 ldr r1, [r4, r1] */
/* @0x162e34 add r0, pc, r0 */
/* @0x162e38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162e3c ldr r1, [pc, #0x304] */
/* @0x162e40 ldr r0, [pc, #0x304] */
/* @0x162e44 mov r2, #2 */
/* @0x162e48 mov r3, #0 */
/* @0x162e4c ldr r1, [r4, r1] */
/* @0x162e50 add r0, pc, r0 */
/* @0x162e54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162e58 ldr r1, [pc, #0x2f0] */
/* @0x162e5c ldr r0, [pc, #0x2f0] */
/* @0x162e60 mov r2, #2 */
/* @0x162e64 mov r3, #0 */
/* @0x162e68 ldr r1, [r4, r1] */
/* @0x162e6c add r0, pc, r0 */
/* @0x162e70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162e74 ldr r1, [pc, #0x2dc] */
/* @0x162e78 ldr r0, [pc, #0x2dc] */
/* @0x162e7c mov r2, #2 */
/* @0x162e80 mov r3, #0 */
/* @0x162e84 ldr r1, [r4, r1] */
/* @0x162e88 add r0, pc, r0 */
/* @0x162e8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162e90 ldr r1, [pc, #0x2c8] */
/* @0x162e94 ldr r0, [pc, #0x2c8] */
/* @0x162e98 mov r2, #2 */
/* @0x162e9c mov r3, #0 */
/* @0x162ea0 ldr r1, [r4, r1] */
/* @0x162ea4 add r0, pc, r0 */
/* @0x162ea8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162eac ldr r1, [pc, #0x2b4] */
/* @0x162eb0 ldr r0, [pc, #0x2b4] */
/* @0x162eb4 mov r2, #1 */
/* @0x162eb8 mov r3, #0 */
/* @0x162ebc ldr r1, [r4, r1] */
/* @0x162ec0 add r0, pc, r0 */
/* @0x162ec4 pop {r4, lr} */
/* @0x162ec8 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x162ecc .word 0x0028f6b0 */
/* @0x162ed0 .word 0xffffe330 */
/* @0x162ed4 andseq r7, lr, r0, asr #12 */
/* @0x162ed8 .word 0xffffe334 */
/* @0x162edc andseq r7, lr, r12, lsr r6 */
/* @0x162ee0 .word 0xffffe338 */
/* @0x162ee4 andseq r7, lr, r12, lsr r6 */
/* @0x162ee8 .word 0xffffe33c */
/* @0x162eec andseq r7, lr, r12, lsr r6 */
/* @0x162ef0 .word 0xffffe340 */
/* @0x162ef4 andseq r7, lr, r8, lsr r6 */
/* @0x162ef8 .word 0xffffe344 */
/* @0x162efc andseq r7, lr, r0, lsr r6 */
/* @0x162f00 .word 0xffffe348 */
/* @0x162f04 andseq r7, lr, r4, lsr r6 */
/* @0x162f08 .word 0xffffe34c */
/* @0x162f0c andseq r7, lr, r12, lsr r6 */
/* @0x162f10 .word 0xffffe350 */
/* @0x162f14 andseq r7, lr, r8, lsr r6 */
/* @0x162f18 .word 0xffffe354 */
/* @0x162f1c andseq r7, lr, r4, lsr r6 */
/* @0x162f20 .word 0xffffe358 */
/* @0x162f24 andseq r7, lr, r0, lsr r6 */
/* @0x162f28 .word 0xffffe35c */
/* @0x162f2c andseq r7, lr, r8, lsr #12 */
/* @0x162f30 .word 0xffffe360 */
/* @0x162f34 andseq r7, lr, r4, lsr #12 */
/* @0x162f38 .word 0xffffe364 */
/* @0x162f3c andseq r7, lr, r8, lsl r6 */
/* @0x162f40 .word 0xffffe368 */
/* @0x162f44 andseq r7, lr, r0, lsl r6 */
/* @0x162f48 .word 0xffffe36c */
/* @0x162f4c andseq r7, lr, r8, lsl #12 */
/* @0x162f50 .word 0xffffe370 */
/* @0x162f54 ldrsheq r7, [lr], -r12 */
/* @0x162f58 .word 0xffffe374 */
/* @0x162f5c ldrsheq r7, [lr], -r4 */
/* @0x162f60 .word 0xffffe378 */
/* @0x162f64 ldrsheq r7, [lr], -r4 */
/* @0x162f68 .word 0xffffe37c */
/* @0x162f6c ldrsheq r7, [lr], -r8 */
/* @0x162f70 .word 0xffffe380 */
/* @0x162f74 ldrsheq r7, [lr], -r4 */
/* @0x162f78 .word 0xffffe384 */
/* @0x162f7c ldrsheq r7, [lr], -r0 */
/* @0x162f80 .word 0xffffe388 */
/* @0x162f84 andseq r7, lr, r12, ror #11 */
/* @0x162f88 .word 0xffffe38c */
/* @0x162f8c andseq r7, lr, r4, ror #11 */
/* @0x162f90 .word 0xffffe390 */
/* @0x162f94 andseq r7, lr, r4, ror #11 */
/* @0x162f98 .word 0xffffe394 */
/* @0x162f9c andseq r7, lr, r4, ror #11 */
/* @0x162fa0 .word 0xffffe398 */
/* @0x162fa4 andseq r7, lr, r4, ror #11 */
/* @0x162fa8 .word 0xffffe39c */
/* @0x162fac andseq r7, lr, r8, ror #11 */
/* @0x162fb0 .word 0xffffe3a0 */
/* @0x162fb4 andseq r7, lr, r8, ror #11 */
/* @0x162fb8 .word 0xffffe3a4 */
/* @0x162fbc andseq r7, lr, r12, ror #11 */
/* @0x162fc0 .word 0xffffe3a8 */
/* @0x162fc4 andseq r7, lr, r12, ror #11 */
/* @0x162fc8 .word 0xffffe3ac */
/* @0x162fcc andseq r7, lr, r8, ror #11 */
/* @0x162fd0 .word 0xffffe3b0 */
/* @0x162fd4 andseq r7, lr, r4, ror #11 */
/* @0x162fd8 .word 0xffffe3b4 */
/* @0x162fdc andseq r7, lr, r0, ror #11 */
/* @0x162fe0 .word 0xffffe3b8 */
/* @0x162fe4 ldrsbeq r7, [lr], -r8 */
/* @0x162fe8 .word 0xffffe3bc */
/* @0x162fec ldrsbeq r7, [lr], -r4 */
/* @0x162ff0 .word 0xffffe3c0 */
/* @0x162ff4 ldrsbeq r7, [lr], -r0 */
/* @0x162ff8 .word 0xffffe3c4 */
/* @0x162ffc andseq r7, lr, r8, asr #11 */
/* @0x163000 .word 0xffffe3c8 */
/* @0x163004 andseq r7, lr, r4, asr #11 */
/* @0x163008 .word 0xffffe3cc */
/* @0x16300c andseq r7, lr, r0, asr #11 */
/* @0x163010 .word 0xffffe3d0 */
/* @0x163014 ldrheq r7, [lr], -r12 */
/* @0x163018 .word 0xffffe3d4 */
/* @0x16301c andseq r7, lr, r4, asr #11 */
/* @0x163020 .word 0xffffe3d8 */
/* @0x163024 ldrheq r7, [lr], -r12 */
/* @0x163028 .word 0xffffe3dc */
/* @0x16302c ldrheq r7, [lr], -r12 */
/* @0x163030 .word 0xffffe3e0 */
/* @0x163034 ldrheq r7, [lr], -r4 */
/* @0x163038 .word 0xffffe3e4 */
/* @0x16303c ldrheq r7, [lr], -r12 */
/* @0x163040 .word 0xffffe3e8 */
/* @0x163044 ldrheq r7, [lr], -r8 */
/* @0x163048 .word 0xffffe3ec */
/* @0x16304c ldrheq r7, [lr], -r12 */
/* @0x163050 .word 0xffffe3f0 */
/* @0x163054 ldrheq r7, [lr], -r12 */
/* @0x163058 .word 0xffffe3f4 */
/* @0x16305c ldrheq r7, [lr], -r8 */
/* @0x163060 .word 0xffffe3f8 */
/* @0x163064 ldrheq r7, [lr], -r12 */
/* @0x163068 .word 0xffffe3fc */
/* @0x16306c ldrheq r7, [lr], -r4 */
/* @0x163070 .word 0xffffe400 */
/* @0x163074 ldrheq r7, [lr], -r4 */
/* @0x163078 .word 0xffffe404 */
/* @0x16307c andseq r7, lr, r12, lsr #11 */
/* @0x163080 .word 0xffffe408 */
/* @0x163084 andseq r7, lr, r8, lsr #11 */
/* @0x163088 .word 0xffffe40c */
/* @0x16308c andseq r7, lr, r8, lsr #11 */
/* @0x163090 .word 0xffffe410 */
/* @0x163094 andseq r7, lr, r8, lsr #11 */
/* @0x163098 .word 0xffffe414 */
/* @0x16309c andseq r7, lr, r12, lsr #11 */
/* @0x1630a0 .word 0xffffe418 */
/* @0x1630a4 ldrheq r7, [lr], -r0 */
/* @0x1630a8 .word 0xffffe41c */
/* @0x1630ac andseq r7, lr, r12, lsr #11 */
/* @0x1630b0 .word 0xffffe420 */
/* @0x1630b4 andseq r7, lr, r12, lsr #11 */
/* @0x1630b8 .word 0xffffe424 */
/* @0x1630bc andseq r7, lr, r12, lsr #11 */
/* @0x1630c0 .word 0xffffe428 */
/* @0x1630c4 ldrheq r7, [lr], -r0 */
/* @0x1630c8 .word 0xffffe42c */
/* @0x1630cc ldrheq r7, [lr], -r8 */
/* @0x1630d0 .word 0xffffe430 */
/* @0x1630d4 ldrheq r7, [lr], -r8 */
/* @0x1630d8 .word 0xffffe434 */
/* @0x1630dc ldrheq r7, [lr], -r8 */
/* @0x1630e0 .word 0xffffe438 */
/* @0x1630e4 ldrheq r7, [lr], -r12 */
/* @0x1630e8 .word 0xffffe43c */
/* @0x1630ec andseq r7, lr, r0, asr #11 */
/* @0x1630f0 .word 0xffffe440 */
/* @0x1630f4 andseq r7, lr, r4, asr #11 */
/* @0x1630f8 .word 0xffffe444 */
/* @0x1630fc andseq r7, lr, r8, asr #11 */
/* @0x163100 .word 0xffffe448 */
/* @0x163104 andseq r7, lr, r12, asr #11 */
/* @0x163108 .word 0xffffe44c */
/* @0x16310c andseq r7, lr, r12, asr #11 */
/* @0x163110 .word 0xffffe450 */
/* @0x163114 ldrsbeq r7, [lr], -r0 */
/* @0x163118 .word 0xffffe454 */
/* @0x16311c ldrsbeq r7, [lr], -r0 */
/* @0x163120 .word 0xffffe458 */
/* @0x163124 ldrsbeq r7, [lr], -r4 */
/* @0x163128 .word 0xffffe45c */
/* @0x16312c andseq r7, lr, r4, ror #11 */
/* @0x163130 .word 0xffffe460 */
/* @0x163134 andseq r7, lr, r12, ror #11 */
/* @0x163138 .word 0xffffe464 */
/* @0x16313c ldrsheq r7, [lr], -r0 */
/* @0x163140 .word 0xffffe468 */
/* @0x163144 andseq r7, lr, r0, lsl #12 */
/* @0x163148 .word 0xffffe46c */
/* @0x16314c andseq r7, lr, r8, lsl #12 */
/* @0x163150 .word 0xffffe470 */
/* @0x163154 andseq r7, lr, r0, lsl r6 */
/* @0x163158 .word 0xffffe474 */
/* @0x16315c andseq r7, lr, r0, lsr #12 */
/* @0x163160 .word 0xffffe478 */
/* @0x163164 andseq r7, lr, r12, lsr #12 */
/* @0x163168 .word 0xffffe47c */
/* @0x16316c andseq r7, lr, r12, lsr r6 */

/* ── FUNC 0x163170 · GR_3D_Set_Mode(bool) · size=64 · insn=16 */
/* @0x163170 push {r3, r4, r5, lr} */
/* @0x163174 mov r5, r0 */
/* @0x163178 ldr r4, [pc, #0x2c] */
/* @0x16317c ldr r4, [pc, r4] */
/* @0x163180 ldrb r3, [r4] */
/* @0x163184 cmp r3, r0 */
/* @0x163188 beq 0x1631a4 <_Z14GR_3D_Set_Modeb+0x34> */
/* @0x16318c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x163190 mov r0, r5 */
/* @0x163194 strb r5, [r4] */
/* @0x163198 bl 0x1682f0 <_Z22GR_D3D_Set_Perspectiveb> */
/* @0x16319c ldrb r0, [r4] */
/* @0x1631a0 bl 0x16841c <_Z10SetZBufferb> */
/* @0x1631a4 mov r0, #1 */
/* @0x1631a8 pop {r3, r4, r5, pc} */
/* @0x1631ac eoreq r10, r8, r8, lsl #23 */

/* ── FUNC 0x1631b0 · GR_3D_Clear_Z() · size=44 · insn=11 */
/* @0x1631b0 ldr r3, [pc, #0x20] */
/* @0x1631b4 ldr r3, [pc, r3] */
/* @0x1631b8 ldrb r3, [r3] */
/* @0x1631bc cmp r3, #0 */
/* @0x1631c0 bxeq lr */
/* @0x1631c4 mov r0, #0 */
/* @0x1631c8 mov r1, #1065353216 */
/* @0x1631cc mov r2, r0 */
/* @0x1631d0 mov r3, #6 */
/* @0x1631d4 b 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags> */
/* @0x1631d8 eoreq r10, r8, r0, asr r11 */

/* ── FUNC 0x1631dc · GR_3D_Set_Depth(float) · size=164 · insn=41 */
/* @0x1631dc ldr r3, [pc, #0x8c] */
/* @0x1631e0 vmov s15, r0 */
/* @0x1631e4 ldr r2, [pc, #0x88] */
/* @0x1631e8 add r3, pc, r3 */
/* @0x1631ec ldr r2, [r3, r2] */
/* @0x1631f0 ldrb r2, [r2] */
/* @0x1631f4 cmp r2, #0 */
/* @0x1631f8 bne 0x163210 <_Z15GR_3D_Set_Depthf+0x34> */
/* @0x1631fc ldr r2, [pc, #0x74] */
/* @0x163200 ldr r2, [r3, r2] */
/* @0x163204 ldrb r2, [r2] */
/* @0x163208 cmp r2, #0 */
/* @0x16320c beq 0x163254 <_Z15GR_3D_Set_Depthf+0x78> */
/* @0x163210 vldr s14, [pc, #80] */
/* @0x163214 vcmpe.f32 s15, s14 */
/* @0x163218 vmrs APSR_nzcv, fpscr */
/* @0x16321c bpl 0x163230 <_Z15GR_3D_Set_Depthf+0x54> */
/* @0x163220 ldr r2, [pc, #0x54] */
/* @0x163224 ldr r3, [r3, r2] */
/* @0x163228 vstr s14, [r3] */
/* @0x16322c bx lr */
/* @0x163230 vldr s13, [pc, #52] */
/* @0x163234 vcmpe.f32 s15, s13 */
/* @0x163238 vmrs APSR_nzcv, fpscr */
/* @0x16323c vmovgt.f32 s14, s13 */
/* @0x163240 bgt 0x163220 <_Z15GR_3D_Set_Depthf+0x44> */
/* @0x163244 vcmpe.f32 s15, s14 */
/* @0x163248 vmrs APSR_nzcv, fpscr */
/* @0x16324c vmovpl.f32 s14, s15 */
/* @0x163250 b 0x163220 <_Z15GR_3D_Set_Depthf+0x44> */
/* @0x163254 ldr r2, [pc, #0x20] */
/* @0x163258 mov r1, #0 */
/* @0x16325c ldr r3, [r3, r2] */
/* @0x163260 str r1, [r3] */
/* @0x163264 bx lr */
/* @0x163268 ldrbtgt r0, [r10], -r0 */
/* @0x16326c ldrbtmi r0, [r10], -r0 */
/* @0x163270 eoreq lr, r8, r8, ror #20 */
/* @0x163274 .word 0xffffbcd4 */
/* @0x163278 .word 0xffffc0b4 */
/* @0x16327c .word 0xffffbcd0 */

/* ── FUNC 0x163280 · GR_3D_Projection_LookAt(float, float, float, float, float, float, float, float, float) · size=112 · insn=28 */
/* @0x163280 push {r4, r5, r6, r7, lr} */
/* @0x163284 sub sp, sp, #108 */
/* @0x163288 add r4, sp, #40 */
/* @0x16328c ldr lr, [sp, #0x8c] */
/* @0x163290 ldr r12, [sp, #0x90] */
/* @0x163294 ldr r7, [sp, #0x80] */
/* @0x163298 ldr r6, [sp, #0x84] */
/* @0x16329c ldr r5, [sp, #0x88] */
/* @0x1632a0 str r0, [sp, #0x4] */
/* @0x1632a4 mov r0, r4 */
/* @0x1632a8 str r1, [sp, #0x8] */
/* @0x1632ac add r1, sp, #4 */
/* @0x1632b0 str r2, [sp, #0xc] */
/* @0x1632b4 add r2, sp, #16 */
/* @0x1632b8 str r3, [sp, #0x10] */
/* @0x1632bc add r3, sp, #28 */
/* @0x1632c0 str lr, [sp, #0x20] */
/* @0x1632c4 str r12, [sp, #0x24] */
/* @0x1632c8 str r7, [sp, #0x14] */
/* @0x1632cc str r6, [sp, #0x18] */
/* @0x1632d0 str r5, [sp, #0x1c] */
/* @0x1632d4 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x1632d8 mov r1, r4 */
/* @0x1632dc mov r0, #0 */
/* @0x1632e0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1632e4 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1632e8 add sp, sp, #108 */
/* @0x1632ec pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x1632f0 · GR_3D_Projection_LookAt_Ext(float, float, float, float, float, float, float, float, float, float, float, float, float) · size=248 · insn=62 */
/* @0x1632f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1632f4 vpush {d8} */
/* @0x1632f8 sub sp, sp, #88 */
/* @0x1632fc vldr s17, [sp, #140] */
/* @0x163300 ldr r4, [pc, #0xc8] */
/* @0x163304 vldr s16, [sp, #144] */
/* @0x163308 ldr r12, [sp, #0x78] */
/* @0x16330c mov r5, #0 */
/* @0x163310 ldr r6, [sp, #0x94] */
/* @0x163314 add r4, pc, r4 */
/* @0x163318 ldr r8, [sp, #0x98] */
/* @0x16331c add r7, sp, #24 */
/* @0x163320 str r12, [sp] */
/* @0x163324 ldr r12, [sp, #0x7c] */
/* @0x163328 str r12, [sp, #0x4] */
/* @0x16332c ldr r12, [sp, #0x80] */
/* @0x163330 str r12, [sp, #0x8] */
/* @0x163334 ldr r12, [sp, #0x84] */
/* @0x163338 str r12, [sp, #0xc] */
/* @0x16333c ldr r12, [sp, #0x88] */
/* @0x163340 str r12, [sp, #0x10] */
/* @0x163344 bl 0x163280 <_Z23GR_3D_Projection_LookAtfffffffff> */
/* @0x163348 ldr r3, [pc, #0x84] */
/* @0x16334c ldr r12, [pc, #0x84] */
/* @0x163350 vldr s15, [pc, #116] */
/* @0x163354 ldr r1, [pc, #0x80] */
/* @0x163358 vmul.f32 s17, s17, s15 */
/* @0x16335c ldr lr, [r4, r3] */
/* @0x163360 mov r0, r7 */
/* @0x163364 ldr r2, [pc, #0x74] */
/* @0x163368 mov r3, r6 */
/* @0x16336c strb r5, [lr] */
/* @0x163370 ldr r12, [r4, r12] */
/* @0x163374 str r6, [r12] */
/* @0x163378 ldr r1, [r4, r1] */
/* @0x16337c str r8, [r1] */
/* @0x163380 ldr r2, [r4, r2] */
/* @0x163384 str r8, [sp] */
/* @0x163388 vldr s15, [r2] */
/* @0x16338c vcvt.f32.s32 s15, s15 */
/* @0x163390 vmul.f32 s17, s17, s15 */
/* @0x163394 vmul.f32 s16, s15, s16 */
/* @0x163398 vmov r1, s17 */
/* @0x16339c vmov r2, s16 */
/* @0x1633a0 bl 0x27b068 <_ZN8yyMatrix16PerspectiveFovLHEPS_ffff> */
/* @0x1633a4 mov r1, r7 */
/* @0x1633a8 mov r0, #1 */
/* @0x1633ac bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1633b0 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1633b4 ldr r3, [pc, #0x28] */
/* @0x1633b8 ldr r3, [r4, r3] */
/* @0x1633bc strb r5, [r3] */
/* @0x1633c0 add sp, sp, #88 */
/* @0x1633c4 vpop {d8} */
/* @0x1633c8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1633cc vstmialo lr, {s30, s31} */
/* @0x1633d0 eoreq lr, r8, r12, lsr r9 */
/* @0x1633d4 .word 0xffffe480 */
/* @0x1633d8 .word 0xffffe484 */
/* @0x1633dc .word 0xffffe488 */
/* @0x1633e0 .word 0xffffe48c */
/* @0x1633e4 .word 0xffffe490 */

/* ── FUNC 0x1633e8 · GR_3D_Projection_Ortho(float, float, float, float, float) · size=352 · insn=88 */
/* @0x1633e8 vmov.f32 s15, #5.000000e-01 */
/* @0x1633ec push {r4, r5, r6, r7, r8, lr} */
/* @0x1633f0 vpush {d8, d9, d10} */
/* @0x1633f4 vmov s14, r0 */
/* @0x1633f8 vldr s19, [pc, #296] */
/* @0x1633fc vmov s17, r2 */
/* @0x163400 sub sp, sp, #176 */
/* @0x163404 vldr s20, [sp, #224] */
/* @0x163408 vldr s18, [pc, #284] */
/* @0x16340c vmov s16, r3 */
/* @0x163410 mov r6, #0 */
/* @0x163414 vmov s13, r1 */
/* @0x163418 str r6, [sp, #0x20] */
/* @0x16341c mov r3, #0 */
/* @0x163420 movt r3, #0xc67a */
/* @0x163424 str r3, [sp, #0x14] */
/* @0x163428 mov r5, #1 */
/* @0x16342c ldr r4, [pc, #0xfc] */
/* @0x163430 vmla.f32 s14, s17, s15 */
/* @0x163434 add r4, pc, r4 */
/* @0x163438 vstr s14, [sp, #12] */
/* @0x16343c vstr s14, [sp, #24] */
/* @0x163440 vnmul.f32 s14, s20, s19 */
/* @0x163444 vdiv.f32 s14, s14, s18 */
/* @0x163448 vmla.f32 s13, s16, s15 */
/* @0x16344c vmov r0, s14 */
/* @0x163450 vmul.f32 s19, s20, s19 */
/* @0x163454 vstr s13, [sp, #16] */
/* @0x163458 vstr s13, [sp, #28] */
/* @0x16345c bl 0xb6580 <sinf@plt> */
/* @0x163460 vdiv.f32 s19, s19, s18 */
/* @0x163464 mov r7, r0 */
/* @0x163468 vmov r0, s19 */
/* @0x16346c bl 0xb658c <cosf@plt> */
/* @0x163470 str r6, [sp, #0x2c] */
/* @0x163474 add r6, sp, #48 */
/* @0x163478 add r2, sp, #24 */
/* @0x16347c add r3, sp, #36 */
/* @0x163480 add r1, sp, #12 */
/* @0x163484 str r7, [sp, #0x24] */
/* @0x163488 ldr r7, [pc, #0xa4] */
/* @0x16348c str r0, [sp, #0x28] */
/* @0x163490 mov r0, r6 */
/* @0x163494 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x163498 mov r1, r6 */
/* @0x16349c mov r0, #0 */
/* @0x1634a0 add r6, sp, #112 */
/* @0x1634a4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1634a8 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1634ac ldr r1, [pc, #0x84] */
/* @0x1634b0 ldr lr, [pc, #0x84] */
/* @0x1634b4 mov r3, #1065353216 */
/* @0x1634b8 ldr r12, [pc, #0x80] */
/* @0x1634bc mov r2, #0 */
/* @0x1634c0 ldr r8, [r4, r1] */
/* @0x1634c4 movt r2, #0x46fa */
/* @0x1634c8 mov r0, r6 */
/* @0x1634cc vmov r1, s17 */
/* @0x1634d0 strb r5, [r8] */
/* @0x1634d4 ldr r7, [r4, r7] */
/* @0x1634d8 str r3, [r7] */
/* @0x1634dc ldr lr, [r4, lr] */
/* @0x1634e0 str r2, [lr] */
/* @0x1634e4 ldr r12, [r4, r12] */
/* @0x1634e8 str r2, [sp] */
/* @0x1634ec vldr s15, [r12] */
/* @0x1634f0 vcvt.f32.s32 s15, s15 */
/* @0x1634f4 vnmul.f32 s15, s16, s15 */
/* @0x1634f8 vmov r2, s15 */
/* @0x1634fc bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff> */
/* @0x163500 mov r0, r5 */
/* @0x163504 mov r1, r6 */
/* @0x163508 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x16350c bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163510 ldr r3, [pc, #0x2c] */
/* @0x163514 ldr r3, [r4, r3] */
/* @0x163518 strb r5, [r3] */
/* @0x16351c add sp, sp, #176 */
/* @0x163520 vpop {d8, d9, d10} */
/* @0x163524 pop {r4, r5, r6, r7, r8, pc} */
/* @0x163528 ldrdmi r0, r1, [r9], #-251 */
/* @0x16352c teqmi r4, #0 */
/* @0x163530 eoreq lr, r8, r12, lsl r8 */
/* @0x163534 .word 0xffffe484 */
/* @0x163538 .word 0xffffe480 */
/* @0x16353c .word 0xffffe488 */
/* @0x163540 .word 0xffffe48c */
/* @0x163544 .word 0xffffe490 */

/* ── FUNC 0x163548 · GR_3D_Projection_Perspective(float, float, float, float, float) · size=340 · insn=85 */
/* @0x163548 vmov.f32 s15, #5.000000e-01 */
/* @0x16354c push {r4, r5, r6, r7, lr} */
/* @0x163550 vpush {d8, d9} */
/* @0x163554 vmov s14, r0 */
/* @0x163558 vldr s18, [pc, #288] */
/* @0x16355c vmov s16, r2 */
/* @0x163560 sub sp, sp, #180 */
/* @0x163564 vmov s17, r3 */
/* @0x163568 vldr s19, [sp, #216] */
/* @0x16356c vmov s13, r1 */
/* @0x163570 mov r6, #0 */
/* @0x163574 str r6, [sp, #0x20] */
/* @0x163578 mov r5, #0 */
/* @0x16357c ldr r4, [pc, #0x100] */
/* @0x163580 add r4, pc, r4 */
/* @0x163584 vmla.f32 s14, s16, s15 */
/* @0x163588 vmla.f32 s13, s17, s15 */
/* @0x16358c vstr s14, [sp, #12] */
/* @0x163590 vstr s14, [sp, #24] */
/* @0x163594 vnmul.f32 s15, s19, s18 */
/* @0x163598 vstr s13, [sp, #16] */
/* @0x16359c vstr s13, [sp, #28] */
/* @0x1635a0 vneg.f32 s14, s16 */
/* @0x1635a4 vmov r0, s15 */
/* @0x1635a8 vstr s14, [sp, #20] */
/* @0x1635ac bl 0xb6580 <sinf@plt> */
/* @0x1635b0 vmul.f32 s18, s19, s18 */
/* @0x1635b4 mov r7, r0 */
/* @0x1635b8 vmov r0, s18 */
/* @0x1635bc bl 0xb658c <cosf@plt> */
/* @0x1635c0 str r6, [sp, #0x2c] */
/* @0x1635c4 add r6, sp, #48 */
/* @0x1635c8 add r2, sp, #24 */
/* @0x1635cc add r3, sp, #36 */
/* @0x1635d0 add r1, sp, #12 */
/* @0x1635d4 str r7, [sp, #0x24] */
/* @0x1635d8 str r0, [sp, #0x28] */
/* @0x1635dc mov r0, r6 */
/* @0x1635e0 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x1635e4 mov r1, r6 */
/* @0x1635e8 mov r0, r5 */
/* @0x1635ec add r6, sp, #112 */
/* @0x1635f0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1635f4 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1635f8 vdiv.f32 s17, s17, s16 */
/* @0x1635fc ldr r1, [pc, #0x84] */
/* @0x163600 mov r2, #0 */
/* @0x163604 ldr r3, [pc, #0x80] */
/* @0x163608 movt r2, #0x46fa */
/* @0x16360c ldr r12, [pc, #0x7c] */
/* @0x163610 mov r0, r6 */
/* @0x163614 ldr lr, [r4, r1] */
/* @0x163618 ldr r1, [pc, #0x74] */
/* @0x16361c strb r5, [lr] */
/* @0x163620 ldr lr, [r4, r3] */
/* @0x163624 mov r3, #1065353216 */
/* @0x163628 str r3, [lr] */
/* @0x16362c ldr r12, [r4, r12] */
/* @0x163630 str r2, [r12] */
/* @0x163634 ldr r12, [r4, r1] */
/* @0x163638 str r2, [sp] */
/* @0x16363c vldr s15, [r12] */
/* @0x163640 vdiv.f32 s16, s16, s16 */
/* @0x163644 vcvt.f32.s32 s15, s15 */
/* @0x163648 vmov r1, s16 */
/* @0x16364c vmul.f32 s15, s17, s15 */
/* @0x163650 vmov r2, s15 */
/* @0x163654 bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff> */
/* @0x163658 mov r1, r6 */
/* @0x16365c mov r0, #1 */
/* @0x163660 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163664 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163668 ldr r3, [pc, #0x28] */
/* @0x16366c ldr r3, [r4, r3] */
/* @0x163670 strb r5, [r3] */
/* @0x163674 add sp, sp, #180 */
/* @0x163678 vpop {d8, d9} */
/* @0x16367c pop {r4, r5, r6, r7, pc} */
/* @0x163680 vstmialo lr, {s30, s31} */
/* @0x163684 .word 0x0028e6d0 */
/* @0x163688 .word 0xffffe480 */
/* @0x16368c .word 0xffffe484 */
/* @0x163690 .word 0xffffe488 */
/* @0x163694 .word 0xffffe48c */
/* @0x163698 .word 0xffffe490 */

/* ── FUNC 0x16369c · GR_3D_Transform_Set_Identity() · size=104 · insn=26 */
/* @0x16369c str lr, [sp, #-0x4]! */
/* @0x1636a0 sub sp, sp, #68 */
/* @0x1636a4 mov r0, #2 */
/* @0x1636a8 mov r3, #0 */
/* @0x1636ac mov r1, sp */
/* @0x1636b0 mov r2, #1065353216 */
/* @0x1636b4 str r3, [sp, #0x38] */
/* @0x1636b8 str r3, [sp, #0x34] */
/* @0x1636bc str r3, [sp, #0x30] */
/* @0x1636c0 str r3, [sp, #0x2c] */
/* @0x1636c4 str r3, [sp, #0x24] */
/* @0x1636c8 str r3, [sp, #0x20] */
/* @0x1636cc str r3, [sp, #0x1c] */
/* @0x1636d0 str r3, [sp, #0x18] */
/* @0x1636d4 str r2, [sp, #0x3c] */
/* @0x1636d8 str r2, [sp, #0x28] */
/* @0x1636dc str r2, [sp, #0x14] */
/* @0x1636e0 str r2, [sp] */
/* @0x1636e4 str r3, [sp, #0x10] */
/* @0x1636e8 str r3, [sp, #0xc] */
/* @0x1636ec str r3, [sp, #0x8] */
/* @0x1636f0 str r3, [sp, #0x4] */
/* @0x1636f4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1636f8 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1636fc add sp, sp, #68 */
/* @0x163700 ldr pc, [sp], #4 */

/* ── FUNC 0x163704 · GR_3D_Transform_Set_Translation(float, float, float) · size=104 · insn=26 */
/* @0x163704 str lr, [sp, #-0x4]! */
/* @0x163708 sub sp, sp, #68 */
/* @0x16370c mov r3, #0 */
/* @0x163710 mov r12, #1065353216 */
/* @0x163714 str r0, [sp, #0x30] */
/* @0x163718 mov r0, #2 */
/* @0x16371c str r1, [sp, #0x34] */
/* @0x163720 mov r1, sp */
/* @0x163724 str r2, [sp, #0x38] */
/* @0x163728 str r3, [sp, #0x2c] */
/* @0x16372c str r3, [sp, #0x24] */
/* @0x163730 str r3, [sp, #0x20] */
/* @0x163734 str r3, [sp, #0x1c] */
/* @0x163738 str r3, [sp, #0x18] */
/* @0x16373c str r3, [sp, #0x10] */
/* @0x163740 str r3, [sp, #0xc] */
/* @0x163744 str r12, [sp, #0x3c] */
/* @0x163748 str r12, [sp, #0x28] */
/* @0x16374c str r12, [sp, #0x14] */
/* @0x163750 str r12, [sp] */
/* @0x163754 str r3, [sp, #0x8] */
/* @0x163758 str r3, [sp, #0x4] */
/* @0x16375c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163760 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163764 add sp, sp, #68 */
/* @0x163768 ldr pc, [sp], #4 */

/* ── FUNC 0x16376c · GR_3D_Transform_Set_Scaling(float, float, float) · size=104 · insn=26 */
/* @0x16376c str lr, [sp, #-0x4]! */
/* @0x163770 sub sp, sp, #68 */
/* @0x163774 mov r3, #0 */
/* @0x163778 mov r12, #1065353216 */
/* @0x16377c str r0, [sp] */
/* @0x163780 mov r0, #2 */
/* @0x163784 str r1, [sp, #0x14] */
/* @0x163788 mov r1, sp */
/* @0x16378c str r2, [sp, #0x28] */
/* @0x163790 str r3, [sp, #0x38] */
/* @0x163794 str r3, [sp, #0x34] */
/* @0x163798 str r3, [sp, #0x30] */
/* @0x16379c str r3, [sp, #0x2c] */
/* @0x1637a0 str r3, [sp, #0x24] */
/* @0x1637a4 str r3, [sp, #0x20] */
/* @0x1637a8 str r3, [sp, #0x1c] */
/* @0x1637ac str r12, [sp, #0x3c] */
/* @0x1637b0 str r3, [sp, #0x18] */
/* @0x1637b4 str r3, [sp, #0x10] */
/* @0x1637b8 str r3, [sp, #0xc] */
/* @0x1637bc str r3, [sp, #0x8] */
/* @0x1637c0 str r3, [sp, #0x4] */
/* @0x1637c4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1637c8 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1637cc add sp, sp, #68 */
/* @0x1637d0 ldr pc, [sp], #4 */

/* ── FUNC 0x1637d4 · GR_3D_Transform_Set_Rotation_X(float) · size=44 · insn=11 */
/* @0x1637d4 push {r4, lr} */
/* @0x1637d8 sub sp, sp, #64 */
/* @0x1637dc mov r1, r0 */
/* @0x1637e0 mov r0, sp */
/* @0x1637e4 bl 0x27afe4 <_ZN8yyMatrix12SetXRotationEPS_f> */
/* @0x1637e8 mov r1, sp */
/* @0x1637ec mov r0, #2 */
/* @0x1637f0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1637f4 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1637f8 add sp, sp, #64 */
/* @0x1637fc pop {r4, pc} */
