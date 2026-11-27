/* libyoyo.so 覆盖卡组 0090
 * 函数 0x157094..0x157958，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x157094 · F_YoYo_OF_StartDashboard(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x157094 b 0x1616d4 <_Z22YoYo_OF_StartDashboardv> */

/* ── FUNC 0x157098 · F_YoYo_OF_AddAchievement(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x157098 push {r3, r4, r5, lr} */
/* @0x15709c mov r1, #0 */
/* @0x1570a0 ldr r4, [sp, #0x10] */
/* @0x1570a4 mov r0, r4 */
/* @0x1570a8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1570ac mov r1, #1 */
/* @0x1570b0 mov r5, r0 */
/* @0x1570b4 mov r0, r4 */
/* @0x1570b8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1570bc mov r1, r0 */
/* @0x1570c0 mov r0, r5 */
/* @0x1570c4 pop {r3, r4, r5, lr} */
/* @0x1570c8 b 0x1616d8 <_Z22YoYo_OF_AddAchievementPKcS0_> */

/* ── FUNC 0x1570cc · F_YoYo_OF_SendChallenge(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1570cc push {r4, r5, r6, lr} */
/* @0x1570d0 mov r1, #0 */
/* @0x1570d4 ldr r4, [sp, #0x10] */
/* @0x1570d8 mov r0, r4 */
/* @0x1570dc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1570e0 mov r1, #1 */
/* @0x1570e4 mov r6, r0 */
/* @0x1570e8 mov r0, r4 */
/* @0x1570ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1570f0 mov r1, #2 */
/* @0x1570f4 mov r5, r0 */
/* @0x1570f8 mov r0, r4 */
/* @0x1570fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157100 mov r1, r5 */
/* @0x157104 mov r2, r0 */
/* @0x157108 mov r0, r6 */
/* @0x15710c pop {r4, r5, r6, lr} */
/* @0x157110 b 0x1616e0 <_Z21YoYo_OF_SendChallengePKcS0_S0_> */

/* ── FUNC 0x157114 · F_YoYo_OF_SendInvite(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x157114 push {r3, lr} */
/* @0x157118 mov r1, #0 */
/* @0x15711c ldr r0, [sp, #0x8] */
/* @0x157120 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157124 pop {r3, lr} */
/* @0x157128 b 0x1616e4 <_Z18YoYo_OF_SendInvitePKc> */

/* ── FUNC 0x15712c · F_YoYo_OF_SendSocial(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x15712c push {r4, r5, r6, lr} */
/* @0x157130 mov r1, #0 */
/* @0x157134 ldr r4, [sp, #0x10] */
/* @0x157138 mov r0, r4 */
/* @0x15713c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157140 mov r1, #1 */
/* @0x157144 mov r6, r0 */
/* @0x157148 mov r0, r4 */
/* @0x15714c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157150 mov r1, #2 */
/* @0x157154 mov r5, r0 */
/* @0x157158 mov r0, r4 */
/* @0x15715c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157160 mov r1, r5 */
/* @0x157164 mov r2, r0 */
/* @0x157168 mov r0, r6 */
/* @0x15716c pop {r4, r5, r6, lr} */
/* @0x157170 b 0x1616e8 <_Z18YoYo_OF_SendSocialPKcS0_S0_> */

/* ── FUNC 0x157174 · F_YoYo_OF_SetURL(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x157174 push {r3, lr} */
/* @0x157178 mov r1, #0 */
/* @0x15717c ldr r0, [sp, #0x8] */
/* @0x157180 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157184 pop {r3, lr} */
/* @0x157188 b 0x1616ec <_Z14YoYo_OF_SetURLPKc> */

/* ── FUNC 0x15718c · F_YoYo_OF_AcceptChallenge(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x15718c push {r4, lr} */
/* @0x157190 mov r4, r0 */
/* @0x157194 bl 0x1616f0 <_Z23YoYo_OF_AcceptChallengev> */
/* @0x157198 mov r1, r0 */
/* @0x15719c mov r0, r4 */
/* @0x1571a0 pop {r4, lr} */
/* @0x1571a4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x1571a8 · F_YoYo_Achievement_IsOnline(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1571a8 push {r4, lr} */
/* @0x1571ac mov r3, #0 */
/* @0x1571b0 str r3, [r0, #0xc] */
/* @0x1571b4 mov r4, r0 */
/* @0x1571b8 bl 0x160f4c <_Z23Achievement_LoginStatusv> */
/* @0x1571bc vmov s15, r0 */
/* @0x1571c0 vcvt.f64.s32 d7, s15 */
/* @0x1571c4 vmov r0, r1, d7 */
/* @0x1571c8 vmov r2, s14 */
/* @0x1571cc mov r3, r1 */
/* @0x1571d0 stm r4, {r2, r3} */
/* @0x1571d4 pop {r4, pc} */

/* ── FUNC 0x1571d8 · F_YoYo_OF_SendChallengeResult(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1571d8 push {r3, r4, r5, lr} */
/* @0x1571dc mov r1, #0 */
/* @0x1571e0 ldr r4, [sp, #0x10] */
/* @0x1571e4 mov r0, r4 */
/* @0x1571e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1571ec mov r1, #1 */
/* @0x1571f0 mov r5, r0 */
/* @0x1571f4 mov r0, r4 */
/* @0x1571f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1571fc mov r1, r0 */
/* @0x157200 mov r0, r5 */
/* @0x157204 pop {r3, r4, r5, lr} */
/* @0x157208 b 0x161700 <_Z27YoYo_OF_SendChallengeResult16eChallengeResultPKc> */

/* ── FUNC 0x15720c · F_YoYo_FacebookInit(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x15720c push {r4, lr} */
/* @0x157210 mov r3, #0 */
/* @0x157214 str r3, [r0, #0xc] */
/* @0x157218 mov r4, r0 */
/* @0x15721c bl 0x15e7ec <_Z13FacebookInitMv> */
/* @0x157220 vmov s15, r0 */
/* @0x157224 vcvt.f64.s32 d7, s15 */
/* @0x157228 vmov r0, r1, d7 */
/* @0x15722c vmov r2, s14 */
/* @0x157230 mov r3, r1 */
/* @0x157234 stm r4, {r2, r3} */
/* @0x157238 pop {r4, pc} */

/* ── FUNC 0x15723c · F_YoYo_FacebookLogin(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x15723c push {r4, r5, r6, lr} */
/* @0x157240 mov r1, #0 */
/* @0x157244 ldr r5, [sp, #0x10] */
/* @0x157248 mov r4, r0 */
/* @0x15724c str r1, [r0, #0xc] */
/* @0x157250 mov r0, r5 */
/* @0x157254 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x157258 mov r1, #1 */
/* @0x15725c mov r6, r0 */
/* @0x157260 mov r0, r5 */
/* @0x157264 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x157268 mov r1, r0 */
/* @0x15726c mov r0, r6 */
/* @0x157270 bl 0x15f67c <_Z14FacebookLoginMii> */
/* @0x157274 vmov s15, r0 */
/* @0x157278 vcvt.f64.s32 d7, s15 */
/* @0x15727c vmov r0, r1, d7 */
/* @0x157280 vmov r2, s14 */
/* @0x157284 mov r3, r1 */
/* @0x157288 stm r4, {r2, r3} */
/* @0x15728c pop {r4, r5, r6, pc} */

/* ── FUNC 0x157290 · F_YoYo_FacebookLoginStatus(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x157290 push {r4, lr} */
/* @0x157294 mov r4, r0 */
/* @0x157298 bl 0x15f0dc <_Z20FacebookLoginStatusMv> */
/* @0x15729c mov r1, r0 */
/* @0x1572a0 mov r0, r4 */
/* @0x1572a4 pop {r4, lr} */
/* @0x1572a8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x1572ac · F_YoYo_FacebookGraphRequest(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1572ac push {r4, r5, r6, r7, r8, lr} */
/* @0x1572b0 mov r1, #0 */
/* @0x1572b4 ldr r4, [sp, #0x18] */
/* @0x1572b8 mov r5, r0 */
/* @0x1572bc str r1, [r0, #0xc] */
/* @0x1572c0 mov r0, r4 */
/* @0x1572c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1572c8 mov r1, #1 */
/* @0x1572cc mov r8, r0 */
/* @0x1572d0 mov r0, r4 */
/* @0x1572d4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1572d8 mov r1, #2 */
/* @0x1572dc mov r7, r0 */
/* @0x1572e0 mov r0, r4 */
/* @0x1572e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1572e8 mov r1, #3 */
/* @0x1572ec mov r6, r0 */
/* @0x1572f0 mov r0, r4 */
/* @0x1572f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1572f8 mov r1, r7 */
/* @0x1572fc mov r2, r6 */
/* @0x157300 mov r3, r0 */
/* @0x157304 mov r0, r8 */
/* @0x157308 bl 0x15fe9c <_Z21FacebookGraphRequestMPcS_ii> */
/* @0x15730c vmov s15, r0 */
/* @0x157310 vcvt.f64.s32 d7, s15 */
/* @0x157314 vmov r0, r1, d7 */
/* @0x157318 vmov r2, s14 */
/* @0x15731c mov r3, r1 */
/* @0x157320 stm r5, {r2, r3} */
/* @0x157324 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x157328 · F_YoYo_FacebookDialog(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x157328 push {r3, r4, r5, r6, r7, lr} */
/* @0x15732c mov r1, #0 */
/* @0x157330 ldr r4, [sp, #0x18] */
/* @0x157334 mov r5, r0 */
/* @0x157338 str r1, [r0, #0xc] */
/* @0x15733c mov r0, r4 */
/* @0x157340 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157344 mov r1, #1 */
/* @0x157348 mov r7, r0 */
/* @0x15734c mov r0, r4 */
/* @0x157350 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x157354 mov r1, #2 */
/* @0x157358 mov r6, r0 */
/* @0x15735c mov r0, r4 */
/* @0x157360 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x157364 mov r1, r6 */
/* @0x157368 mov r2, r0 */
/* @0x15736c mov r0, r7 */
/* @0x157370 bl 0x15ff70 <_Z15FacebookDialogMPcii> */
/* @0x157374 vmov s15, r0 */
/* @0x157378 vcvt.f64.s32 d7, s15 */
/* @0x15737c vmov r0, r1, d7 */
/* @0x157380 vmov r2, s14 */
/* @0x157384 mov r3, r1 */
/* @0x157388 stm r5, {r2, r3} */
/* @0x15738c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x157390 · F_YoYo_FacebookPostMessage(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x157390 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x157394 sub sp, sp, #20 */
/* @0x157398 mov r5, r0 */
/* @0x15739c mov r1, #0 */
/* @0x1573a0 ldr r4, [sp, #0x38] */
/* @0x1573a4 str r1, [r0, #0xc] */
/* @0x1573a8 mov r0, r4 */
/* @0x1573ac bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1573b0 mov r1, #1 */
/* @0x1573b4 mov r6, r0 */
/* @0x1573b8 mov r0, r4 */
/* @0x1573bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1573c0 mov r1, #2 */
/* @0x1573c4 mov r9, r0 */
/* @0x1573c8 mov r0, r4 */
/* @0x1573cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1573d0 mov r1, #3 */
/* @0x1573d4 mov r8, r0 */
/* @0x1573d8 mov r0, r4 */
/* @0x1573dc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1573e0 mov r1, #4 */
/* @0x1573e4 mov r7, r0 */
/* @0x1573e8 mov r0, r4 */
/* @0x1573ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1573f0 mov r1, #5 */
/* @0x1573f4 mov r11, r0 */
/* @0x1573f8 mov r0, r4 */
/* @0x1573fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157400 mov r1, #6 */
/* @0x157404 mov r10, r0 */
/* @0x157408 mov r0, r4 */
/* @0x15740c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157410 mov r1, r9 */
/* @0x157414 mov r2, r8 */
/* @0x157418 mov r3, r7 */
/* @0x15741c str r11, [sp] */
/* @0x157420 str r10, [sp, #0x4] */
/* @0x157424 str r0, [sp, #0x8] */
/* @0x157428 mov r0, r6 */
/* @0x15742c bl 0x15e8a0 <_Z20FacebookPostMessageMPcS_S_S_S_S_S_> */
/* @0x157430 vmov s15, r0 */
/* @0x157434 vcvt.f64.s32 d7, s15 */
/* @0x157438 vmov r0, r1, d7 */
/* @0x15743c vmov r2, s14 */
/* @0x157440 mov r3, r1 */
/* @0x157444 stm r5, {r2, r3} */
/* @0x157448 add sp, sp, #20 */
/* @0x15744c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x157450 · F_YoYo_FacebookSendInvite(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x157450 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x157454 sub sp, sp, #12 */
/* @0x157458 mov r5, r0 */
/* @0x15745c mov r1, #0 */
/* @0x157460 ldr r4, [sp, #0x28] */
/* @0x157464 str r1, [r0, #0xc] */
/* @0x157468 mov r0, r4 */
/* @0x15746c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157470 mov r1, #1 */
/* @0x157474 mov r6, r0 */
/* @0x157478 mov r0, r4 */
/* @0x15747c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157480 mov r1, #2 */
/* @0x157484 mov r9, r0 */
/* @0x157488 mov r0, r4 */
/* @0x15748c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157490 mov r1, #3 */
/* @0x157494 mov r8, r0 */
/* @0x157498 mov r0, r4 */
/* @0x15749c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1574a0 mov r1, #4 */
/* @0x1574a4 mov r7, r0 */
/* @0x1574a8 mov r0, r4 */
/* @0x1574ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1574b0 mov r1, r9 */
/* @0x1574b4 mov r2, r8 */
/* @0x1574b8 mov r3, r7 */
/* @0x1574bc str r0, [sp] */
/* @0x1574c0 mov r0, r6 */
/* @0x1574c4 bl 0x15ece4 <_Z19FacebookSendInviteMPcS_S_S_i> */
/* @0x1574c8 vmov s15, r0 */
/* @0x1574cc vcvt.f64.s32 d7, s15 */
/* @0x1574d0 vmov r0, r1, d7 */
/* @0x1574d4 vmov r2, s14 */
/* @0x1574d8 mov r3, r1 */
/* @0x1574dc stm r5, {r2, r3} */
/* @0x1574e0 add sp, sp, #12 */
/* @0x1574e4 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1574e8 · F_YoYo_FacebookUserId(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x1574e8 push {r4, lr} */
/* @0x1574ec mov r4, r0 */
/* @0x1574f0 bl 0x15ef7c <_Z15FacebookUserIdMv> */
/* @0x1574f4 mov r1, r0 */
/* @0x1574f8 mov r0, r4 */
/* @0x1574fc pop {r4, lr} */
/* @0x157500 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x157504 · F_YoYo_FacebookAccessToken(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x157504 push {r4, lr} */
/* @0x157508 mov r4, r0 */
/* @0x15750c bl 0x15f028 <_Z20FacebookAccessTokenMv> */
/* @0x157510 mov r1, r0 */
/* @0x157514 mov r0, r4 */
/* @0x157518 pop {r4, lr} */
/* @0x15751c b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x157520 · F_YoYo_FacebookLogout(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x157520 push {r4, lr} */
/* @0x157524 mov r3, #0 */
/* @0x157528 str r3, [r0, #0xc] */
/* @0x15752c mov r4, r0 */
/* @0x157530 bl 0x15ef48 <_Z15FacebookLogoutMv> */
/* @0x157534 vmov s15, r0 */
/* @0x157538 vcvt.f64.s32 d7, s15 */
/* @0x15753c vmov r0, r1, d7 */
/* @0x157540 vmov r2, s14 */
/* @0x157544 mov r3, r1 */
/* @0x157548 stm r4, {r2, r3} */
/* @0x15754c pop {r4, pc} */

/* ── FUNC 0x157550 · F_YoYo_FacebookCheckPermission(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x157550 push {r3, r4, r5, lr} */
/* @0x157554 mov r5, #0 */
/* @0x157558 mov r4, r0 */
/* @0x15755c mov r1, r5 */
/* @0x157560 str r5, [r0, #0xc] */
/* @0x157564 ldr r0, [sp, #0x10] */
/* @0x157568 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x15756c bl 0x15e848 <_Z24FacebookCheckPermissionMPc> */
/* @0x157570 cmp r0, #0 */
/* @0x157574 moveq r5, r0 */
/* @0x157578 movne r3, r5 */
/* @0x15757c moveq r3, r5 */
/* @0x157580 movtne r3, #0x3ff0 */
/* @0x157584 str r5, [r4] */
/* @0x157588 str r3, [r4, #0x4] */
/* @0x15758c pop {r3, r4, r5, pc} */

/* ── FUNC 0x157590 · F_YoYo_FacebookRequestReadPermissions(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x157590 push {r3, r4, r5, lr} */
/* @0x157594 mov r5, #0 */
/* @0x157598 mov r4, r0 */
/* @0x15759c mov r1, r5 */
/* @0x1575a0 str r5, [r0, #0xc] */
/* @0x1575a4 ldr r0, [sp, #0x10] */
/* @0x1575a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1575ac mov r1, r5 */
/* @0x1575b0 bl 0x15f8b8 <_Z27FacebookRequestPermissionsMib> */
/* @0x1575b4 vmov s15, r0 */
/* @0x1575b8 vcvt.f64.s32 d7, s15 */
/* @0x1575bc vmov r0, r1, d7 */
/* @0x1575c0 vmov r2, s14 */
/* @0x1575c4 mov r3, r1 */
/* @0x1575c8 stm r4, {r2, r3} */
/* @0x1575cc pop {r3, r4, r5, pc} */

/* ── FUNC 0x1575d0 · F_YoYo_FacebookRequestPublishPermissions(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1575d0 push {r4, lr} */
/* @0x1575d4 mov r3, #0 */
/* @0x1575d8 mov r1, r3 */
/* @0x1575dc str r3, [r0, #0xc] */
/* @0x1575e0 mov r4, r0 */
/* @0x1575e4 ldr r0, [sp, #0x8] */
/* @0x1575e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1575ec mov r1, #1 */
/* @0x1575f0 bl 0x15f8b8 <_Z27FacebookRequestPermissionsMib> */
/* @0x1575f4 vmov s15, r0 */
/* @0x1575f8 vcvt.f64.s32 d7, s15 */
/* @0x1575fc vmov r0, r1, d7 */
/* @0x157600 vmov r2, s14 */
/* @0x157604 mov r3, r1 */
/* @0x157608 stm r4, {r2, r3} */
/* @0x15760c pop {r4, pc} */

/* ── FUNC 0x157610 · F_YoYo_GetLanguage(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x157610 push {r4, lr} */
/* @0x157614 mov r4, r0 */
/* @0x157618 bl 0x15f21c <_Z17GetLanguageStringv> */
/* @0x15761c mov r1, r0 */
/* @0x157620 mov r0, r4 */
/* @0x157624 pop {r4, lr} */
/* @0x157628 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x15762c · F_YoYo_GetRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x15762c push {r4, lr} */
/* @0x157630 mov r4, r0 */
/* @0x157634 bl 0x15f230 <_Z15GetRegionStringv> */
/* @0x157638 mov r1, r0 */
/* @0x15763c mov r0, r4 */
/* @0x157640 pop {r4, lr} */
/* @0x157644 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x157648 · F_YoYo_RequestPermission(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x157648 push {r3, lr} */
/* @0x15764c mov r3, #0 */
/* @0x157650 ldr r12, [sp, #0x8] */
/* @0x157654 mov r1, r3 */
/* @0x157658 str r3, [r0, #0xc] */
/* @0x15765c str r3, [r0] */
/* @0x157660 str r3, [r0, #0x4] */
/* @0x157664 mov r0, r12 */
/* @0x157668 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x15766c pop {r3, lr} */
/* @0x157670 b 0x15f32c <_Z19YYRequestPermissionPKc> */

/* ── FUNC 0x157674 · F_YoYo_CheckPermission(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x157674 push {r4, lr} */
/* @0x157678 mov r3, #0 */
/* @0x15767c mov r1, r3 */
/* @0x157680 str r3, [r0, #0xc] */
/* @0x157684 str r3, [r0] */
/* @0x157688 mov r4, r0 */
/* @0x15768c str r3, [r0, #0x4] */
/* @0x157690 ldr r0, [sp, #0x8] */
/* @0x157694 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157698 bl 0x15f2dc <_Z17YYCheckPermissionPKc> */
/* @0x15769c vmov s15, r0 */
/* @0x1576a0 vcvt.f64.s32 d7, s15 */
/* @0x1576a4 vmov r0, r1, d7 */
/* @0x1576a8 vmov r2, s14 */
/* @0x1576ac mov r3, r1 */
/* @0x1576b0 stm r4, {r2, r3} */
/* @0x1576b4 pop {r4, pc} */

/* ── FUNC 0x1576b8 · F_YoYo_GetDPIX(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1576b8 push {r4, lr} */
/* @0x1576bc mov r3, #0 */
/* @0x1576c0 str r3, [r0, #0xc] */
/* @0x1576c4 mov r4, r0 */
/* @0x1576c8 bl 0x15f244 <_Z7GetDPIXv> */
/* @0x1576cc vmov s15, r0 */
/* @0x1576d0 vcvt.f64.f32 d7, s15 */
/* @0x1576d4 vmov r0, r1, d7 */
/* @0x1576d8 vmov r2, s14 */
/* @0x1576dc mov r3, r1 */
/* @0x1576e0 stm r4, {r2, r3} */
/* @0x1576e4 pop {r4, pc} */

/* ── FUNC 0x1576e8 · F_YoYo_GetDPIY(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1576e8 push {r4, lr} */
/* @0x1576ec mov r3, #0 */
/* @0x1576f0 str r3, [r0, #0xc] */
/* @0x1576f4 mov r4, r0 */
/* @0x1576f8 bl 0x15f258 <_Z7GetDPIYv> */
/* @0x1576fc vmov s15, r0 */
/* @0x157700 vcvt.f64.f32 d7, s15 */
/* @0x157704 vmov r0, r1, d7 */
/* @0x157708 vmov r2, s14 */
/* @0x15770c mov r3, r1 */
/* @0x157710 stm r4, {r2, r3} */
/* @0x157714 pop {r4, pc} */

/* ── FUNC 0x157718 · F_YoYo_SetGUISize(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x157718 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15771c mov r1, #0 */
/* @0x157720 ldr r6, [sp, #0x28] */
/* @0x157724 mov r5, r0 */
/* @0x157728 ldr r4, [pc, #0xa0] */
/* @0x15772c mov r9, #0 */
/* @0x157730 ldr r10, [pc, #0x9c] */
/* @0x157734 mov r0, r6 */
/* @0x157738 add r4, pc, r4 */
/* @0x15773c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x157740 ldr r3, [pc, #0x90] */
/* @0x157744 mov r1, #1 */
/* @0x157748 ldr r8, [pc, #0x8c] */
/* @0x15774c ldr r7, [pc, #0x8c] */
/* @0x157750 ldr r3, [r4, r3] */
/* @0x157754 str r0, [r3] */
/* @0x157758 mov r0, r6 */
/* @0x15775c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x157760 ldr r1, [pc, #0x7c] */
/* @0x157764 mov r2, #1325400064 */
/* @0x157768 ldr r6, [pc, #0x78] */
/* @0x15776c ldr r12, [pc, #0x78] */
/* @0x157770 mov r3, #1065353216 */
/* @0x157774 ldr r11, [r4, r1] */
/* @0x157778 ldr r1, [pc, #0x70] */
/* @0x15777c str r0, [r11] */
/* @0x157780 ldr r0, [r4, r10] */
/* @0x157784 strb r9, [r0] */
/* @0x157788 ldr r0, [r4, r8] */
/* @0x15778c str r2, [r0] */
/* @0x157790 ldr r0, [r4, r7] */
/* @0x157794 str r2, [r0] */
/* @0x157798 ldr r2, [r4, r6] */
/* @0x15779c str r3, [r2] */
/* @0x1577a0 ldr r2, [r4, r12] */
/* @0x1577a4 str r3, [r2] */
/* @0x1577a8 ldr r3, [r4, r1] */
/* @0x1577ac ldrb r3, [r3] */
/* @0x1577b0 cmp r3, r9 */
/* @0x1577b4 beq 0x1577bc <_Z17F_YoYo_SetGUISizeR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1577b8 bl 0x1b3204 <_Z14Calc_GUI_Scalev> */
/* @0x1577bc mov r3, #0 */
/* @0x1577c0 str r3, [r5, #0xc] */
/* @0x1577c4 str r3, [r5] */
/* @0x1577c8 str r3, [r5, #0x4] */
/* @0x1577cc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1577d0 eoreq r10, r9, r8, lsl r5 */
/* @0x1577d4 .word 0xffffdf14 */
/* @0x1577d8 .word 0xffffdf18 */
/* @0x1577dc .word 0xffffdf1c */
/* @0x1577e0 .word 0xffffdf20 */
/* @0x1577e4 .word 0xffffdf24 */
/* @0x1577e8 .word 0xffffdf28 */
/* @0x1577ec .word 0xffffdf2c */
/* @0x1577f0 .word 0xffffdf30 */

/* ── FUNC 0x1577f4 · F_YoYo_SetGUIMaximise(RValue&, CInstance*, CInstance*, int, RValue*) · size=276 · insn=69 */
/* @0x1577f4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1577f8 mov r11, #1 */
/* @0x1577fc ldr r4, [pc, #0xe0] */
/* @0x157800 mov r1, #1325400064 */
/* @0x157804 ldr r5, [pc, #0xdc] */
/* @0x157808 mov r0, #1065353216 */
/* @0x15780c add r4, pc, r4 */
/* @0x157810 ldr r8, [pc, #0xd4] */
/* @0x157814 ldr r12, [pc, #0xd4] */
/* @0x157818 subs r7, r3, #0 */
/* @0x15781c ldr r9, [r4, r5] */
/* @0x157820 mvn r2, #0 */
/* @0x157824 ldr r6, [pc, #0xc8] */
/* @0x157828 ldr r5, [pc, #0xc8] */
/* @0x15782c strb r11, [r9] */
/* @0x157830 ldr r9, [r4, r8] */
/* @0x157834 ldr r10, [pc, #0xc0] */
/* @0x157838 ldr r3, [pc, #0xc0] */
/* @0x15783c str r1, [r9] */
/* @0x157840 ldr r8, [r4, r12] */
/* @0x157844 str r1, [r8] */
/* @0x157848 ldr r6, [r4, r6] */
/* @0x15784c str r0, [r6] */
/* @0x157850 ldr r5, [r4, r5] */
/* @0x157854 str r0, [r5] */
/* @0x157858 ldr r1, [r4, r10] */
/* @0x15785c ldr r10, [sp, #0x28] */
/* @0x157860 str r2, [r1] */
/* @0x157864 ldr r3, [r4, r3] */
/* @0x157868 str r2, [r3] */
/* @0x15786c ble 0x1578c8 <_Z21F_YoYo_SetGUIMaximiseR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x157870 mov r0, r10 */
/* @0x157874 mov r1, #0 */
/* @0x157878 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x15787c cmp r7, r11 */
/* @0x157880 str r0, [r6] */
/* @0x157884 beq 0x1578c8 <_Z21F_YoYo_SetGUIMaximiseR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x157888 mov r1, r11 */
/* @0x15788c mov r0, r10 */
/* @0x157890 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x157894 cmp r7, #2 */
/* @0x157898 str r0, [r5] */
/* @0x15789c beq 0x1578c8 <_Z21F_YoYo_SetGUIMaximiseR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1578a0 mov r0, r10 */
/* @0x1578a4 mov r1, #2 */
/* @0x1578a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1578ac cmp r7, #3 */
/* @0x1578b0 str r0, [r9] */
/* @0x1578b4 beq 0x1578c8 <_Z21F_YoYo_SetGUIMaximiseR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1578b8 mov r0, r10 */
/* @0x1578bc mov r1, #3 */
/* @0x1578c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1578c4 str r0, [r8] */
/* @0x1578c8 ldr r3, [pc, #0x34] */
/* @0x1578cc ldr r3, [r4, r3] */
/* @0x1578d0 ldrb r3, [r3] */
/* @0x1578d4 cmp r3, #0 */
/* @0x1578d8 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1578dc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1578e0 b 0x1b3204 <_Z14Calc_GUI_Scalev> */
/* @0x1578e4 eoreq r10, r9, r4, asr #8 */
/* @0x1578e8 .word 0xffffdf14 */
/* @0x1578ec .word 0xffffdf1c */
/* @0x1578f0 .word 0xffffdf20 */
/* @0x1578f4 .word 0xffffdf28 */
/* @0x1578f8 .word 0xffffdf2c */
/* @0x1578fc .word 0xffffdf18 */
/* @0x157900 .word 0xffffdf24 */
/* @0x157904 .word 0xffffdf30 */

/* ── FUNC 0x157908 · F_YoYo_GetGUIWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x157908 ldr r3, [pc, #0x44] */
/* @0x15790c push {r4, lr} */
/* @0x157910 ldr r3, [pc, r3] */
/* @0x157914 mov r4, r0 */
/* @0x157918 ldr r0, [r3] */
/* @0x15791c vmov s15, r0 */
/* @0x157920 vcvt.f64.s32 d7, s15 */
/* @0x157924 vcmpe.f64 d7, #0 */
/* @0x157928 vmov r0, r1, d7 */
/* @0x15792c vmrs APSR_nzcv, fpscr */
/* @0x157930 bmi 0x15794c <_Z18F_YoYo_GetGUIWidthR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x157934 mov r3, #0 */
/* @0x157938 mov r2, r0 */
/* @0x15793c str r3, [r4, #0xc] */
/* @0x157940 mov r3, r1 */
/* @0x157944 stm r4, {r2, r3} */
/* @0x157948 pop {r4, pc} */
/* @0x15794c bl 0x15e60c <_Z16GetBrowserWidthMv> */
/* @0x157950 b 0x157934 <_Z18F_YoYo_GetGUIWidthR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x157954 eoreq r8, r9, r8, asr r2 */

/* ── FUNC 0x157958 · GET_YoYo_GetBrowserWidth(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x157958 push {r4, lr} */
/* @0x15795c mov r3, #0 */
/* @0x157960 str r3, [r2, #0xc] */
/* @0x157964 mov r4, r2 */
/* @0x157968 bl 0x15e60c <_Z16GetBrowserWidthMv> */
/* @0x15796c str r0, [r4] */
/* @0x157970 mov r0, #1 */
/* @0x157974 str r1, [r4, #0x4] */
/* @0x157978 pop {r4, pc} */
