/* libyoyo.so 覆盖卡组 0097
 * 函数 0x161210..0x161cb8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x161210 · Achievement_PlayerID() · size=16 · insn=4 */
/* @0x161210 ldr r0, [pc, #0x4] */
/* @0x161214 add r0, pc, r0 */
/* @0x161218 bx lr */
/* @0x16121c andseq r8, lr, r8, asr #17 */

/* ── FUNC 0x161220 · Os_Get_Info() · size=96 · insn=24 */
/* @0x161220 push {r4, r5, lr} */
/* @0x161224 sub sp, sp, #12 */
/* @0x161228 bl 0x290274 <getJNIEnv> */
/* @0x16122c ldr r2, [pc, #0x44] */
/* @0x161230 ldr r3, [pc, #0x44] */
/* @0x161234 add r5, sp, #4 */
/* @0x161238 ldr r2, [pc, r2] */
/* @0x16123c ldr r3, [pc, r3] */
/* @0x161240 ldr r1, [r2] */
/* @0x161244 ldr r2, [r3] */
/* @0x161248 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x16124c mov r4, r0 */
/* @0x161250 mov r0, r5 */
/* @0x161254 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x161258 mov r0, r4 */
/* @0x16125c bl 0x2052d4 <_Z8GetDsMapi> */
/* @0x161260 bl 0x17d284 <_Z15AddGraphicsInfoP7CDS_Map> */
/* @0x161264 mov r0, r5 */
/* @0x161268 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x16126c mov r0, r4 */
/* @0x161270 add sp, sp, #12 */
/* @0x161274 pop {r4, r5, pc} */
/* @0x161278 eoreq r12, r8, r12, ror #14 */
/* @0x16127c .word 0x0028ecd0 */

/* ── FUNC 0x161280 · Achievement_Show_Leaderboard() · size=48 · insn=12 */
/* @0x161280 push {r3, lr} */
/* @0x161284 bl 0x290274 <getJNIEnv> */
/* @0x161288 ldr r2, [pc, #0x18] */
/* @0x16128c ldr r3, [pc, #0x18] */
/* @0x161290 ldr r2, [pc, r2] */
/* @0x161294 ldr r3, [pc, r3] */
/* @0x161298 ldr r1, [r2] */
/* @0x16129c ldr r2, [r3] */
/* @0x1612a0 pop {r3, lr} */
/* @0x1612a4 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x1612a8 eoreq r12, r8, r4, lsl r7 */
/* @0x1612ac .word 0x0028ecb4 */

/* ── FUNC 0x1612b0 · Cloud_String_Save(char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*)) · size=224 · insn=56 */
/* @0x1612b0 ldr r12, [pc, #0xc8] */
/* @0x1612b4 mov r3, r0 */
/* @0x1612b8 push {r4, r5, r6, r7, lr} */
/* @0x1612bc ldr r12, [pc, r12] */
/* @0x1612c0 mov r4, r0 */
/* @0x1612c4 mov r5, r1 */
/* @0x1612c8 ldr r0, [r12] */
/* @0x1612cc mov r7, r2 */
/* @0x1612d0 mov r2, r1 */
/* @0x1612d4 ldr r1, [pc, #0xa8] */
/* @0x1612d8 sub sp, sp, #20 */
/* @0x1612dc ldr r12, [r0] */
/* @0x1612e0 add r1, pc, r1 */
/* @0x1612e4 ldr r12, [r12, #0xc] */
/* @0x1612e8 blx r12 */
/* @0x1612ec mov r0, #68 */
/* @0x1612f0 bl 0x27c524 <_Znwj> */
/* @0x1612f4 mov r12, #0 */
/* @0x1612f8 mov r2, r12 */
/* @0x1612fc str r12, [sp] */
/* @0x161300 str r12, [sp, #0x4] */
/* @0x161304 mov r3, r7 */
/* @0x161308 str r12, [sp, #0x8] */
/* @0x16130c mov r1, r4 */
/* @0x161310 mov r6, r0 */
/* @0x161314 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x161318 bl 0x290274 <getJNIEnv> */
/* @0x16131c mov r1, r4 */
/* @0x161320 ldr r3, [r0] */
/* @0x161324 ldr r3, [r3, #0x29c] */
/* @0x161328 blx r3 */
/* @0x16132c mov r7, r0 */
/* @0x161330 bl 0x290274 <getJNIEnv> */
/* @0x161334 mov r1, r5 */
/* @0x161338 ldr r3, [r0] */
/* @0x16133c ldr r3, [r3, #0x29c] */
/* @0x161340 blx r3 */
/* @0x161344 mov r4, r0 */
/* @0x161348 bl 0x290274 <getJNIEnv> */
/* @0x16134c ldr r1, [pc, #0x34] */
/* @0x161350 mov r3, r7 */
/* @0x161354 ldr r2, [pc, #0x30] */
/* @0x161358 ldr r1, [pc, r1] */
/* @0x16135c ldr r2, [pc, r2] */
/* @0x161360 ldr r1, [r1] */
/* @0x161364 ldr r2, [r2] */
/* @0x161368 str r4, [sp] */
/* @0x16136c ldr r12, [r6, #0x24] */
/* @0x161370 str r12, [sp, #0x4] */
/* @0x161374 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161378 add sp, sp, #20 */
/* @0x16137c pop {r4, r5, r6, r7, pc} */
/* @0x161380 eoreq r12, r8, r8, asr r4 */
/* @0x161384 andseq r8, lr, r4, lsl #16 */
/* @0x161388 eoreq r12, r8, r12, asr #12 */
/* @0x16138c .word 0x0028ebf0 */

/* ── FUNC 0x161390 · Cloud_Synchronise(int (*)(HTTP_REQ_CONTEXT*, void*, int*)) · size=108 · insn=27 */
/* @0x161390 push {r4, r5, lr} */
/* @0x161394 mov r5, r0 */
/* @0x161398 sub sp, sp, #20 */
/* @0x16139c mov r0, #68 */
/* @0x1613a0 bl 0x27c524 <_Znwj> */
/* @0x1613a4 mov r12, #0 */
/* @0x1613a8 mov r3, r5 */
/* @0x1613ac mov r1, r12 */
/* @0x1613b0 mov r2, r12 */
/* @0x1613b4 str r12, [sp] */
/* @0x1613b8 str r12, [sp, #0x4] */
/* @0x1613bc str r12, [sp, #0x8] */
/* @0x1613c0 mov r4, r0 */
/* @0x1613c4 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x1613c8 bl 0x290274 <getJNIEnv> */
/* @0x1613cc ldr r1, [pc, #0x20] */
/* @0x1613d0 ldr r2, [pc, #0x20] */
/* @0x1613d4 ldr r1, [pc, r1] */
/* @0x1613d8 ldr r3, [r4, #0x24] */
/* @0x1613dc ldr r2, [pc, r2] */
/* @0x1613e0 ldr r1, [r1] */
/* @0x1613e4 ldr r2, [r2] */
/* @0x1613e8 add sp, sp, #20 */
/* @0x1613ec pop {r4, r5, lr} */
/* @0x1613f0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x1613f4 .word 0x0028c5d0 */
/* @0x1613f8 eoreq lr, r8, r4, ror r11 */

/* ── FUNC 0x1613fc · Achievement_PostHiScore(eCacheType, char const*, int) · size=184 · insn=46 */
/* @0x1613fc ldr r3, [pc, #0xa0] */
/* @0x161400 push {r4, r5, r6, lr} */
/* @0x161404 ldr r3, [pc, r3] */
/* @0x161408 mov r4, r0 */
/* @0x16140c mov r5, r1 */
/* @0x161410 ldr r0, [r3] */
/* @0x161414 mov r6, r2 */
/* @0x161418 mov r2, r1 */
/* @0x16141c ldr r1, [pc, #0x84] */
/* @0x161420 sub sp, sp, #8 */
/* @0x161424 ldr r12, [r0] */
/* @0x161428 add r1, pc, r1 */
/* @0x16142c ldr r3, [r12, #0xc] */
/* @0x161430 blx r3 */
/* @0x161434 cmp r4, #1 */
/* @0x161438 beq 0x161450 <_Z23Achievement_PostHiScore10eCacheTypePKci+0x54> */
/* @0x16143c mov r0, #3 */
/* @0x161440 bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState> */
/* @0x161444 mov r0, #0 */
/* @0x161448 add sp, sp, #8 */
/* @0x16144c pop {r4, r5, r6, pc} */
/* @0x161450 bl 0x290274 <getJNIEnv> */
/* @0x161454 mov r1, r5 */
/* @0x161458 ldr r3, [r0] */
/* @0x16145c ldr r3, [r3, #0x29c] */
/* @0x161460 blx r3 */
/* @0x161464 mov r5, r0 */
/* @0x161468 bl 0x290274 <getJNIEnv> */
/* @0x16146c ldr r2, [pc, #0x38] */
/* @0x161470 mov r3, r5 */
/* @0x161474 ldr r12, [pc, #0x34] */
/* @0x161478 ldr r2, [pc, r2] */
/* @0x16147c ldr r12, [pc, r12] */
/* @0x161480 ldr r1, [r2] */
/* @0x161484 ldr r2, [r12] */
/* @0x161488 str r6, [sp] */
/* @0x16148c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161490 mov r0, #2 */
/* @0x161494 bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState> */
/* @0x161498 mov r0, r4 */
/* @0x16149c add sp, sp, #8 */
/* @0x1614a0 pop {r4, r5, r6, pc} */
/* @0x1614a4 eoreq r12, r8, r0, lsl r3 */
/* @0x1614a8 ldrsbeq r8, [lr], -r8 */
/* @0x1614ac eoreq r12, r8, r12, lsr #10 */
/* @0x1614b0 .word 0x0028ead8 */

/* ── FUNC 0x1614b4 · Achievement_PostAchievement(eCacheType, char const*, float) · size=316 · insn=79 */
/* @0x1614b4 push {r4, r5, r6, lr} */
/* @0x1614b8 vpush {d8} */
/* @0x1614bc mov r5, r0 */
/* @0x1614c0 ldr r4, [pc, #0x110] */
/* @0x1614c4 mov r6, r1 */
/* @0x1614c8 ldr r3, [pc, #0x10c] */
/* @0x1614cc sub sp, sp, #8 */
/* @0x1614d0 add r4, pc, r4 */
/* @0x1614d4 ldr r1, [pc, #0x104] */
/* @0x1614d8 vmov s16, r2 */
/* @0x1614dc mov r2, r6 */
/* @0x1614e0 ldr r3, [r4, r3] */
/* @0x1614e4 add r1, pc, r1 */
/* @0x1614e8 ldr r0, [r3] */
/* @0x1614ec ldr r12, [r0] */
/* @0x1614f0 ldr r3, [r12, #0xc] */
/* @0x1614f4 blx r3 */
/* @0x1614f8 cmp r5, #2 */
/* @0x1614fc beq 0x16157c <_Z27Achievement_PostAchievement10eCacheTypePKcf+0xc8> */
/* @0x161500 cmp r5, #3 */
/* @0x161504 beq 0x161520 <_Z27Achievement_PostAchievement10eCacheTypePKcf+0x6c> */
/* @0x161508 mov r0, #3 */
/* @0x16150c bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState> */
/* @0x161510 mov r0, #0 */
/* @0x161514 add sp, sp, #8 */
/* @0x161518 vpop {d8} */
/* @0x16151c pop {r4, r5, r6, pc} */
/* @0x161520 bl 0x290274 <getJNIEnv> */
/* @0x161524 mov r1, r6 */
/* @0x161528 ldr r3, [r0] */
/* @0x16152c ldr r3, [r3, #0x29c] */
/* @0x161530 blx r3 */
/* @0x161534 mov r5, r0 */
/* @0x161538 bl 0x290274 <getJNIEnv> */
/* @0x16153c vcvt.f64.f32 d7, s16 */
/* @0x161540 ldr r1, [pc, #0x9c] */
/* @0x161544 ldr r2, [pc, #0x9c] */
/* @0x161548 mov r3, r5 */
/* @0x16154c ldr r1, [r4, r1] */
/* @0x161550 ldr r2, [r4, r2] */
/* @0x161554 ldr r1, [r1] */
/* @0x161558 ldr r2, [r2] */
/* @0x16155c vstr d7, [sp] */
/* @0x161560 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161564 mov r0, #2 */
/* @0x161568 bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState> */
/* @0x16156c mov r0, #1 */
/* @0x161570 add sp, sp, #8 */
/* @0x161574 vpop {d8} */
/* @0x161578 pop {r4, r5, r6, pc} */
/* @0x16157c bl 0x290274 <getJNIEnv> */
/* @0x161580 mov r1, r6 */
/* @0x161584 ldr r3, [r0] */
/* @0x161588 ldr r3, [r3, #0x29c] */
/* @0x16158c blx r3 */
/* @0x161590 mov r6, r0 */
/* @0x161594 bl 0x290274 <getJNIEnv> */
/* @0x161598 vcvt.f64.f32 d7, s16 */
/* @0x16159c ldr r1, [pc, #0x40] */
/* @0x1615a0 ldr r2, [pc, #0x44] */
/* @0x1615a4 mov r3, r6 */
/* @0x1615a8 ldr r1, [r4, r1] */
/* @0x1615ac ldr r2, [r4, r2] */
/* @0x1615b0 ldr r1, [r1] */
/* @0x1615b4 ldr r2, [r2] */
/* @0x1615b8 vstr d7, [sp] */
/* @0x1615bc bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x1615c0 mov r0, r5 */
/* @0x1615c4 bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState> */
/* @0x1615c8 mov r0, #1 */
/* @0x1615cc add sp, sp, #8 */
/* @0x1615d0 vpop {d8} */
/* @0x1615d4 pop {r4, r5, r6, pc} */
/* @0x1615d8 eoreq r0, r9, r0, lsl #15 */
/* @0x1615dc .word 0xffffbac4 */
/* @0x1615e0 andseq r8, lr, r0, lsr r6 */
/* @0x1615e4 .word 0xffffbd54 */
/* @0x1615e8 .word 0xffffe308 */
/* @0x1615ec .word 0xffffe30c */

/* ── FUNC 0x1615f0 · YoYo_IncrementAchievement(char const*, unsigned int*) · size=76 · insn=19 */
/* @0x1615f0 push {r3, r4, r5, lr} */
/* @0x1615f4 mov r2, r0 */
/* @0x1615f8 ldr r3, [pc, #0x34] */
/* @0x1615fc mov r4, r0 */
/* @0x161600 mov r5, r1 */
/* @0x161604 ldr r1, [pc, #0x2c] */
/* @0x161608 ldr r3, [pc, r3] */
/* @0x16160c add r1, pc, r1 */
/* @0x161610 ldr r0, [r3] */
/* @0x161614 ldr r3, [r0] */
/* @0x161618 ldr r3, [r3, #0xc] */
/* @0x16161c blx r3 */
/* @0x161620 mov r1, r4 */
/* @0x161624 mov r2, r5 */
/* @0x161628 mov r0, #3 */
/* @0x16162c pop {r3, r4, r5, lr} */
/* @0x161630 b 0x159cc0 <_Z16CacheAchievement10eCacheTypePKcPj> */
/* @0x161634 eoreq r12, r8, r12, lsl #2 */
/* @0x161638 andseq r8, lr, r0, lsr #10 */

/* ── FUNC 0x16163c · YoYo_CacheAchievement(char const*, unsigned int*) · size=76 · insn=19 */
/* @0x16163c push {r3, r4, r5, lr} */
/* @0x161640 mov r2, r0 */
/* @0x161644 ldr r3, [pc, #0x34] */
/* @0x161648 mov r4, r0 */
/* @0x16164c mov r5, r1 */
/* @0x161650 ldr r1, [pc, #0x2c] */
/* @0x161654 ldr r3, [pc, r3] */
/* @0x161658 add r1, pc, r1 */
/* @0x16165c ldr r0, [r3] */
/* @0x161660 ldr r3, [r0] */
/* @0x161664 ldr r3, [r3, #0xc] */
/* @0x161668 blx r3 */
/* @0x16166c mov r1, r4 */
/* @0x161670 mov r2, r5 */
/* @0x161674 mov r0, #2 */
/* @0x161678 pop {r3, r4, r5, lr} */
/* @0x16167c b 0x159cc0 <_Z16CacheAchievement10eCacheTypePKcPj> */
/* @0x161680 eoreq r12, r8, r0, asr #1 */
/* @0x161684 ldrsheq r8, [lr], -r4 */

/* ── FUNC 0x161688 · YoYo_ScoreAchievement(char const*, unsigned int*) · size=76 · insn=19 */
/* @0x161688 push {r3, r4, r5, lr} */
/* @0x16168c mov r2, r0 */
/* @0x161690 ldr r3, [pc, #0x34] */
/* @0x161694 mov r4, r0 */
/* @0x161698 mov r5, r1 */
/* @0x16169c ldr r1, [pc, #0x2c] */
/* @0x1616a0 ldr r3, [pc, r3] */
/* @0x1616a4 add r1, pc, r1 */
/* @0x1616a8 ldr r0, [r3] */
/* @0x1616ac ldr r3, [r0] */
/* @0x1616b0 ldr r3, [r3, #0xc] */
/* @0x1616b4 blx r3 */
/* @0x1616b8 mov r1, r4 */
/* @0x1616bc mov r2, r5 */
/* @0x1616c0 mov r0, #1 */
/* @0x1616c4 pop {r3, r4, r5, lr} */
/* @0x1616c8 b 0x159cc0 <_Z16CacheAchievement10eCacheTypePKcPj> */
/* @0x1616cc eoreq r12, r8, r4, ror r0 */
/* @0x1616d0 andseq r8, lr, r0, asr #9 */

/* ── FUNC 0x1616d4 · YoYo_OF_StartDashboard() · size=4 · insn=1 */
/* @0x1616d4 bx lr */

/* ── FUNC 0x1616d8 · YoYo_OF_AddAchievement(char const*, char const*) · size=4 · insn=1 */
/* @0x1616d8 bx lr */

/* ── FUNC 0x1616dc · YoYo_OF_AddLeaderboard(char const*, char const*, eLeaderboardType) · size=4 · insn=1 */
/* @0x1616dc bx lr */

/* ── FUNC 0x1616e0 · YoYo_OF_SendChallenge(char const*, char const*, char const*) · size=4 · insn=1 */
/* @0x1616e0 bx lr */

/* ── FUNC 0x1616e4 · YoYo_OF_SendInvite(char const*) · size=4 · insn=1 */
/* @0x1616e4 bx lr */

/* ── FUNC 0x1616e8 · YoYo_OF_SendSocial(char const*, char const*, char const*) · size=4 · insn=1 */
/* @0x1616e8 bx lr */

/* ── FUNC 0x1616ec · YoYo_OF_SetURL(char const*) · size=4 · insn=1 */
/* @0x1616ec bx lr */

/* ── FUNC 0x1616f0 · YoYo_OF_AcceptChallenge() · size=16 · insn=4 */
/* @0x1616f0 ldr r0, [pc, #0x4] */
/* @0x1616f4 add r0, pc, r0 */
/* @0x1616f8 b 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1616fc andseq sp, r12, r2, asr #8 */

/* ── FUNC 0x161700 · YoYo_OF_SendChallengeResult(eChallengeResult, char const*) · size=4 · insn=1 */
/* @0x161700 bx lr */

/* ── FUNC 0x161704 · _JNIEnv::CallStaticLongMethod(_jclass*, _jmethodID*, ...) · size=56 · insn=14 */
/* @0x161704 push {r2, r3} */
/* @0x161708 str lr, [sp, #-0x4]! */
/* @0x16170c sub sp, sp, #12 */
/* @0x161710 ldr lr, [r0] */
/* @0x161714 add r12, sp, #20 */
/* @0x161718 ldr r2, [sp, #0x10] */
/* @0x16171c mov r3, r12 */
/* @0x161720 str r12, [sp, #0x4] */
/* @0x161724 ldr r12, [lr, #0x214] */
/* @0x161728 blx r12 */
/* @0x16172c add sp, sp, #12 */
/* @0x161730 ldr lr, [sp], #4 */
/* @0x161734 add sp, sp, #8 */
/* @0x161738 bx lr */

/* ── FUNC 0x16173c · IAP_ActivateM() · size=304 · insn=76 */
/* @0x16173c push {r3, r4, r5, r6, r7, lr} */
/* @0x161740 bl 0x290274 <getJNIEnv> */
/* @0x161744 ldr r6, [pc, #0x10c] */
/* @0x161748 ldr r6, [pc, r6] */
/* @0x16174c ldr r7, [r6] */
/* @0x161750 mov r4, r0 */
/* @0x161754 bl 0x290274 <getJNIEnv> */
/* @0x161758 ldr r1, [pc, #0xfc] */
/* @0x16175c add r1, pc, r1 */
/* @0x161760 ldr r3, [r0] */
/* @0x161764 ldr r3, [r3, #0x18] */
/* @0x161768 blx r3 */
/* @0x16176c mov r5, r0 */
/* @0x161770 bl 0x290274 <getJNIEnv> */
/* @0x161774 ldr r1, [pc, #0xe4] */
/* @0x161778 add r1, pc, r1 */
/* @0x16177c ldr r3, [r0] */
/* @0x161780 ldr r3, [r3, #0x29c] */
/* @0x161784 blx r3 */
/* @0x161788 ldr r12, [r4] */
/* @0x16178c mov r1, r7 */
/* @0x161790 mov r2, r5 */
/* @0x161794 ldr r12, [r12, #0x2b0] */
/* @0x161798 mov r3, r0 */
/* @0x16179c mov r0, r4 */
/* @0x1617a0 blx r12 */
/* @0x1617a4 ldr r3, [r6] */
/* @0x1617a8 cmp r3, #0 */
/* @0x1617ac mov r7, r0 */
/* @0x1617b0 ble 0x161818 <_Z13IAP_ActivateMv+0xdc> */
/* @0x1617b4 mov r4, #0 */
/* @0x1617b8 bl 0x290274 <getJNIEnv> */
/* @0x1617bc ldr r3, [r6, #0x4] */
/* @0x1617c0 ldr r3, [r3, r4, lsl #2] */
/* @0x1617c4 ldr r1, [r3] */
/* @0x1617c8 ldr r3, [r0] */
/* @0x1617cc ldr r2, [r3, #0x29c] */
/* @0x1617d0 blx r2 */
/* @0x1617d4 mov r5, r0 */
/* @0x1617d8 bl 0x290274 <getJNIEnv> */
/* @0x1617dc mov r2, r4 */
/* @0x1617e0 mov r3, r5 */
/* @0x1617e4 mov r1, r7 */
/* @0x1617e8 add r4, r4, #1 */
/* @0x1617ec ldr r12, [r0] */
/* @0x1617f0 ldr r12, [r12, #0x2b8] */
/* @0x1617f4 blx r12 */
/* @0x1617f8 bl 0x290274 <getJNIEnv> */
/* @0x1617fc mov r1, r5 */
/* @0x161800 ldr r3, [r0] */
/* @0x161804 ldr r2, [r3, #0x5c] */
/* @0x161808 blx r2 */
/* @0x16180c ldr r3, [r6] */
/* @0x161810 cmp r3, r4 */
/* @0x161814 bgt 0x1617b8 <_Z13IAP_ActivateMv+0x7c> */
/* @0x161818 bl 0x290274 <getJNIEnv> */
/* @0x16181c ldr r1, [pc, #0x40] */
/* @0x161820 ldr r2, [pc, #0x40] */
/* @0x161824 mov r3, r7 */
/* @0x161828 ldr r1, [pc, r1] */
/* @0x16182c ldr r2, [pc, r2] */
/* @0x161830 ldr r1, [r1] */
/* @0x161834 ldr r2, [r2] */
/* @0x161838 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x16183c bl 0x290274 <getJNIEnv> */
/* @0x161840 mov r1, r7 */
/* @0x161844 ldr r3, [r0] */
/* @0x161848 ldr r3, [r3, #0x5c] */
/* @0x16184c blx r3 */
/* @0x161850 mov r0, #1 */
/* @0x161854 pop {r3, r4, r5, r6, r7, pc} */
/* @0x161858 eoreq lr, r8, r12, lsl #7 */
/* @0x16185c andseq r8, lr, r4 */
/* @0x161860 ldrheq sp, [r12], -lr */
/* @0x161864 eoreq r12, r8, r12, ror r1 */
/* @0x161868 eoreq lr, r8, r4, lsr r7 */

/* ── FUNC 0x16186c · IAP_RestoreM() · size=48 · insn=12 */
/* @0x16186c push {r3, lr} */
/* @0x161870 bl 0x290274 <getJNIEnv> */
/* @0x161874 ldr r2, [pc, #0x18] */
/* @0x161878 ldr r3, [pc, #0x18] */
/* @0x16187c ldr r2, [pc, r2] */
/* @0x161880 ldr r3, [pc, r3] */
/* @0x161884 ldr r1, [r2] */
/* @0x161888 ldr r2, [r3] */
/* @0x16188c pop {r3, lr} */
/* @0x161890 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161894 eoreq r12, r8, r8, lsr #2 */
/* @0x161898 eoreq lr, r8, r4, ror #13 */

/* ── FUNC 0x16189c · IAP_AcquireM(char const*, char const*, int) · size=164 · insn=41 */
/* @0x16189c push {r4, r5, r6, lr} */
/* @0x1618a0 sub sp, sp, #8 */
/* @0x1618a4 mov r6, r2 */
/* @0x1618a8 mov r4, r1 */
/* @0x1618ac mov r5, r0 */
/* @0x1618b0 bl 0x290274 <getJNIEnv> */
/* @0x1618b4 mov r1, r5 */
/* @0x1618b8 ldr r3, [r0] */
/* @0x1618bc ldr r3, [r3, #0x29c] */
/* @0x1618c0 blx r3 */
/* @0x1618c4 mov r5, r0 */
/* @0x1618c8 bl 0x290274 <getJNIEnv> */
/* @0x1618cc mov r1, r4 */
/* @0x1618d0 ldr r3, [r0] */
/* @0x1618d4 ldr r3, [r3, #0x29c] */
/* @0x1618d8 blx r3 */
/* @0x1618dc mov r4, r0 */
/* @0x1618e0 bl 0x290274 <getJNIEnv> */
/* @0x1618e4 ldr lr, [pc, #0x4c] */
/* @0x1618e8 mov r3, r5 */
/* @0x1618ec ldr r12, [pc, #0x48] */
/* @0x1618f0 ldr lr, [pc, lr] */
/* @0x1618f4 ldr r12, [pc, r12] */
/* @0x1618f8 ldr r1, [lr] */
/* @0x1618fc ldr r2, [r12] */
/* @0x161900 stm sp, {r4, r6} */
/* @0x161904 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161908 bl 0x290274 <getJNIEnv> */
/* @0x16190c mov r1, r5 */
/* @0x161910 ldr r3, [r0] */
/* @0x161914 ldr r3, [r3, #0x5c] */
/* @0x161918 blx r3 */
/* @0x16191c bl 0x290274 <getJNIEnv> */
/* @0x161920 mov r1, r4 */
/* @0x161924 ldr r3, [r0] */
/* @0x161928 ldr r3, [r3, #0x5c] */
/* @0x16192c blx r3 */
/* @0x161930 add sp, sp, #8 */
/* @0x161934 pop {r4, r5, r6, pc} */
/* @0x161938 strhteq r12, [r8], -r4 */
/* @0x16193c eoreq lr, r8, r4, ror r6 */

/* ── FUNC 0x161940 · IAP_ConsumeM(char const*) · size=424 · insn=106 */
/* @0x161940 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x161944 sub sp, sp, #540 */
/* @0x161948 ldr r9, [pc, #0x174] */
/* @0x16194c mov r8, r0 */
/* @0x161950 ldr r2, [pc, #0x170] */
/* @0x161954 add r9, pc, r9 */
/* @0x161958 ldr r3, [pc, #0x16c] */
/* @0x16195c ldr r10, [r9, r2] */
/* @0x161960 ldr r2, [r10] */
/* @0x161964 str r2, [sp, #0x214] */
/* @0x161968 ldr r3, [r9, r3] */
/* @0x16196c ldr r6, [r3] */
/* @0x161970 cmp r6, #0 */
/* @0x161974 ble 0x1619d4 <_Z12IAP_ConsumeMPKc+0x94> */
/* @0x161978 ldr r2, [pc, #0x150] */
/* @0x16197c mov r5, #0 */
/* @0x161980 mov r11, r5 */
/* @0x161984 ldr r2, [r9, r2] */
/* @0x161988 ldr r7, [r2, #0x4] */
/* @0x16198c str r2, [sp, #0xc] */
/* @0x161990 ldr r4, [r7, r5] */
/* @0x161994 cmp r4, #0 */
/* @0x161998 beq 0x1619c4 <_Z12IAP_ConsumeMPKc+0x84> */
/* @0x16199c ldr r0, [r4, #0x4] */
/* @0x1619a0 cmp r0, #0 */
/* @0x1619a4 beq 0x1619c4 <_Z12IAP_ConsumeMPKc+0x84> */
/* @0x1619a8 mov r1, r8 */
/* @0x1619ac bl 0xb6574 <strcmp@plt> */
/* @0x1619b0 cmp r0, #0 */
/* @0x1619b4 bne 0x1619c4 <_Z12IAP_ConsumeMPKc+0x84> */
/* @0x1619b8 ldr r2, [r4, #0xc] */
/* @0x1619bc cmp r2, #0 */
/* @0x1619c0 bne 0x161a30 <_Z12IAP_ConsumeMPKc+0xf0> */
/* @0x1619c4 add r11, r11, #1 */
/* @0x1619c8 add r5, r5, #4 */
/* @0x1619cc cmp r11, r6 */
/* @0x1619d0 bne 0x161990 <_Z12IAP_ConsumeMPKc+0x50> */
/* @0x1619d4 ldr r3, [pc, #0xf8] */
/* @0x1619d8 add r4, sp, #20 */
/* @0x1619dc ldr r1, [pc, #0xf4] */
/* @0x1619e0 ldr r3, [r9, r3] */
/* @0x1619e4 add r1, pc, r1 */
/* @0x1619e8 ldr r0, [r3] */
/* @0x1619ec ldr r3, [r0] */
/* @0x1619f0 ldr r3, [r3, #0xc] */
/* @0x1619f4 blx r3 */
/* @0x1619f8 ldr r1, [pc, #0xdc] */
/* @0x1619fc mov r2, r8 */
/* @0x161a00 mov r0, r4 */
/* @0x161a04 add r1, pc, r1 */
/* @0x161a08 mov r3, #6 */
/* @0x161a0c bl 0xb6550 <sprintf@plt> */
/* @0x161a10 mov r0, r4 */
/* @0x161a14 bl 0x15556c <_Z17YYIAPConsumeEventPKc> */
/* @0x161a18 ldr r2, [sp, #0x214] */
/* @0x161a1c ldr r3, [r10] */
/* @0x161a20 cmp r2, r3 */
/* @0x161a24 bne 0x161ac0 <_Z12IAP_ConsumeMPKc+0x180> */
/* @0x161a28 add sp, sp, #540 */
/* @0x161a2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x161a30 bl 0x290274 <getJNIEnv> */
/* @0x161a34 mov r1, r8 */
/* @0x161a38 ldr r3, [r0] */
/* @0x161a3c ldr r3, [r3, #0x29c] */
/* @0x161a40 blx r3 */
/* @0x161a44 mov r4, r0 */
/* @0x161a48 bl 0x290274 <getJNIEnv> */
/* @0x161a4c ldr r2, [sp, #0xc] */
/* @0x161a50 ldr r3, [r2, #0x4] */
/* @0x161a54 ldr r3, [r3, r5] */
/* @0x161a58 ldr r1, [r3, #0xc] */
/* @0x161a5c ldr r3, [r0] */
/* @0x161a60 ldr r3, [r3, #0x29c] */
/* @0x161a64 blx r3 */
/* @0x161a68 mov r5, r0 */
/* @0x161a6c bl 0x290274 <getJNIEnv> */
/* @0x161a70 ldr r1, [pc, #0x68] */
/* @0x161a74 mov r3, r4 */
/* @0x161a78 ldr r2, [pc, #0x64] */
/* @0x161a7c ldr r1, [r9, r1] */
/* @0x161a80 ldr r2, [r9, r2] */
/* @0x161a84 str r5, [sp] */
/* @0x161a88 ldr r1, [r1] */
/* @0x161a8c ldr r2, [r2] */
/* @0x161a90 bl 0x161704 <_ZN7_JNIEnv20CallStaticLongMethodEP7_jclassP10_jmethodIDz> */
/* @0x161a94 bl 0x290274 <getJNIEnv> */
/* @0x161a98 mov r1, r5 */
/* @0x161a9c ldr r3, [r0] */
/* @0x161aa0 ldr r3, [r3, #0x5c] */
/* @0x161aa4 blx r3 */
/* @0x161aa8 bl 0x290274 <getJNIEnv> */
/* @0x161aac mov r1, r4 */
/* @0x161ab0 ldr r3, [r0] */
/* @0x161ab4 ldr r3, [r3, #0x5c] */
/* @0x161ab8 blx r3 */
/* @0x161abc b 0x161a18 <_Z12IAP_ConsumeMPKc+0xd8> */
/* @0x161ac0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x161ac4 .word 0x002902fc */
/* @0x161ac8 .word 0xffffbd00 */
/* @0x161acc .word 0xffffde78 */
/* @0x161ad0 .word 0xffffde7c */
/* @0x161ad4 .word 0xffffbcf0 */
/* @0x161ad8 mulseq lr, r8, r1 */
/* @0x161adc ldrheq r8, [lr], -r0 */
/* @0x161ae0 .word 0xffffbd54 */
/* @0x161ae4 .word 0xffffe31c */

/* ── FUNC 0x161ae8 · IAP_GetProductDetailM(char const*) · size=100 · insn=25 */
/* @0x161ae8 push {r4, lr} */
/* @0x161aec mov r4, r0 */
/* @0x161af0 bl 0x290274 <getJNIEnv> */
/* @0x161af4 mov r1, r4 */
/* @0x161af8 ldr r3, [r0] */
/* @0x161afc ldr r3, [r3, #0x29c] */
/* @0x161b00 blx r3 */
/* @0x161b04 mov r4, r0 */
/* @0x161b08 bl 0x290274 <getJNIEnv> */
/* @0x161b0c ldr r12, [pc, #0x30] */
/* @0x161b10 mov r3, r4 */
/* @0x161b14 ldr r2, [pc, #0x2c] */
/* @0x161b18 ldr r12, [pc, r12] */
/* @0x161b1c ldr r2, [pc, r2] */
/* @0x161b20 ldr r1, [r12] */
/* @0x161b24 ldr r2, [r2] */
/* @0x161b28 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161b2c bl 0x290274 <getJNIEnv> */
/* @0x161b30 mov r1, r4 */
/* @0x161b34 ldr r3, [r0] */
/* @0x161b38 ldr r3, [r3, #0x5c] */
/* @0x161b3c blx r3 */
/* @0x161b40 pop {r4, pc} */
/* @0x161b44 eoreq r11, r8, r12, lsl #29 */
/* @0x161b48 eoreq lr, r8, r4, asr r4 */

/* ── FUNC 0x161b4c · Push_SendLocalNotification(double, char const*, char const*, char const*) · size=176 · insn=44 */
/* @0x161b4c push {r4, r5, r6, r7, lr} */
/* @0x161b50 vpush {d8} */
/* @0x161b54 sub sp, sp, #28 */
/* @0x161b58 mov r5, r2 */
/* @0x161b5c mov r7, r3 */
/* @0x161b60 vmov d8, r0, r1 */
/* @0x161b64 ldr r4, [sp, #0x38] */
/* @0x161b68 bl 0x290274 <getJNIEnv> */
/* @0x161b6c mov r1, r5 */
/* @0x161b70 ldr r3, [r0] */
/* @0x161b74 ldr r3, [r3, #0x29c] */
/* @0x161b78 blx r3 */
/* @0x161b7c mov r6, r0 */
/* @0x161b80 bl 0x290274 <getJNIEnv> */
/* @0x161b84 mov r1, r7 */
/* @0x161b88 ldr r3, [r0] */
/* @0x161b8c ldr r3, [r3, #0x29c] */
/* @0x161b90 blx r3 */
/* @0x161b94 mov r5, r0 */
/* @0x161b98 bl 0x290274 <getJNIEnv> */
/* @0x161b9c mov r1, r4 */
/* @0x161ba0 ldr r3, [r0] */
/* @0x161ba4 ldr r3, [r3, #0x29c] */
/* @0x161ba8 blx r3 */
/* @0x161bac mov r4, r0 */
/* @0x161bb0 bl 0x290274 <getJNIEnv> */
/* @0x161bb4 vcvt.f32.f64 s16, d8 */
/* @0x161bb8 ldr r2, [pc, #0x34] */
/* @0x161bbc ldr r3, [pc, #0x34] */
/* @0x161bc0 ldr r2, [pc, r2] */
/* @0x161bc4 ldr r3, [pc, r3] */
/* @0x161bc8 ldr r1, [r2] */
/* @0x161bcc ldr r2, [r3] */
/* @0x161bd0 str r6, [sp, #0x8] */
/* @0x161bd4 vcvt.f64.f32 d8, s16 */
/* @0x161bd8 str r5, [sp, #0xc] */
/* @0x161bdc str r4, [sp, #0x10] */
/* @0x161be0 vstr d8, [sp] */
/* @0x161be4 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161be8 add sp, sp, #28 */
/* @0x161bec vpop {d8} */
/* @0x161bf0 pop {r4, r5, r6, r7, pc} */
/* @0x161bf4 eoreq r11, r8, r4, ror #27 */
/* @0x161bf8 .word 0x0028e3b0 */

/* ── FUNC 0x161bfc · Push_ClearNotifications() · size=4 · insn=1 */
/* @0x161bfc bx lr */

/* ── FUNC 0x161c00 · Push_GetLocalNotification(int, int) · size=72 · insn=18 */
/* @0x161c00 push {r4, r5, lr} */
/* @0x161c04 sub sp, sp, #12 */
/* @0x161c08 mov r4, r1 */
/* @0x161c0c mov r5, r0 */
/* @0x161c10 bl 0x290274 <getJNIEnv> */
/* @0x161c14 ldr r12, [pc, #0x24] */
/* @0x161c18 ldr r2, [pc, #0x24] */
/* @0x161c1c mov r3, r5 */
/* @0x161c20 ldr r12, [pc, r12] */
/* @0x161c24 ldr r2, [pc, r2] */
/* @0x161c28 ldr r1, [r12] */
/* @0x161c2c ldr r2, [r2] */
/* @0x161c30 str r4, [sp] */
/* @0x161c34 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x161c38 add sp, sp, #12 */
/* @0x161c3c pop {r4, r5, pc} */
/* @0x161c40 eoreq r11, r8, r4, lsl #27 */
/* @0x161c44 eoreq lr, r8, r4, asr r3 */

/* ── FUNC 0x161c48 · Push_CancelLocalNotification(int) · size=56 · insn=14 */
/* @0x161c48 push {r4, lr} */
/* @0x161c4c mov r4, r0 */
/* @0x161c50 bl 0x290274 <getJNIEnv> */
/* @0x161c54 ldr r1, [pc, #0x1c] */
/* @0x161c58 mov r3, r4 */
/* @0x161c5c ldr r2, [pc, #0x18] */
/* @0x161c60 ldr r1, [pc, r1] */
/* @0x161c64 ldr r2, [pc, r2] */
/* @0x161c68 ldr r1, [r1] */
/* @0x161c6c ldr r2, [r2] */
/* @0x161c70 pop {r4, lr} */
/* @0x161c74 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x161c78 eoreq r11, r8, r4, asr #26 */
/* @0x161c7c eoreq lr, r8, r8, lsl r3 */

/* ── FUNC 0x161c80 · F_Steam_OverlayEnabled(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x161c80 mov r2, #0 */
/* @0x161c84 mov r3, r2 */
/* @0x161c88 movt r2, #0xbff0 */
/* @0x161c8c str r3, [r0, #0xc] */
/* @0x161c90 str r2, [r0, #0x4] */
/* @0x161c94 str r3, [r0] */
/* @0x161c98 bx lr */

/* ── FUNC 0x161c9c · F_Steam_OverlayActive(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x161c9c mov r2, #0 */
/* @0x161ca0 mov r3, r2 */
/* @0x161ca4 movt r2, #0xbff0 */
/* @0x161ca8 str r3, [r0, #0xc] */
/* @0x161cac str r2, [r0, #0x4] */
/* @0x161cb0 str r3, [r0] */
/* @0x161cb4 bx lr */

/* ── FUNC 0x161cb8 · F_Steam_ActivateOverlayBrowser(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x161cb8 mov r3, #0 */
/* @0x161cbc str r3, [r0, #0xc] */
/* @0x161cc0 str r3, [r0] */
/* @0x161cc4 str r3, [r0, #0x4] */
/* @0x161cc8 bx lr */
