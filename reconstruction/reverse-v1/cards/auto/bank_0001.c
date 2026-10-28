/* libyoyo.so 覆盖卡组 0001
 * 函数 0xbe7f0..0xc0810，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xbe7f0 · CSkeletonInstance::ClearAnimation(int) · size=28 · insn=7 */
/* @0xbe7f0 subs r3, r1, #0 */
/* @0xbe7f4 bxlt lr */
/* @0xbe7f8 ldr r0, [r0, #0x28] */
/* @0xbe7fc ldr r2, [r0, #0xc] */
/* @0xbe800 cmp r3, r2 */
/* @0xbe804 bxge lr */
/* @0xbe808 b 0x283558 <spAnimationState_clearTrack> */

/* ── FUNC 0xbe80c · CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) · size=496 · insn=124 */
/* @0xbe80c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xbe810 vpush {d8, d9, d10} */
/* @0xbe814 mov r6, r1 */
/* @0xbe818 vldr s17, [sp, #56] */
/* @0xbe81c ldr r1, [r0, #0x1c] */
/* @0xbe820 mov r4, r0 */
/* @0xbe824 mov r10, r3 */
/* @0xbe828 vmov s18, r2 */
/* @0xbe82c cmp r1, #0 */
/* @0xbe830 vldr s16, [sp, #60] */
/* @0xbe834 vldr s19, [sp, #64] */
/* @0xbe838 ldr r8, [sp, #0x44] */
/* @0xbe83c beq 0xbe9f4 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x1e8> */
/* @0xbe840 vldr s20, [r0, #8] */
/* @0xbe844 vldr s21, [r0, #12] */
/* @0xbe848 vmul.f32 s20, s17, s20 */
/* @0xbe84c adds r9, r8, #0 */
/* @0xbe850 ldrb r3, [r0, #0x5] */
/* @0xbe854 movne r9, #1 */
/* @0xbe858 cmp r3, #0 */
/* @0xbe85c vmul.f32 s21, s16, s21 */
/* @0xbe860 vabs.f32 s20, s20 */
/* @0xbe864 vabs.f32 s21, s21 */
/* @0xbe868 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c> */
/* @0xbe86c ldr r3, [r0] */
/* @0xbe870 cmp r3, r6 */
/* @0xbe874 beq 0xbe994 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x188> */
/* @0xbe878 mov r0, r4 */
/* @0xbe87c mov r1, #0 */
/* @0xbe880 bl 0xbe220 <_ZN17CSkeletonInstance10FrameCountEi> */
/* @0xbe884 subs r5, r0, #0 */
/* @0xbe888 ble 0xbe8f4 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0xe8> */
/* @0xbe88c mov r0, r6 */
/* @0xbe890 mov r1, r5 */
/* @0xbe894 bl 0x318dec <__aeabi_idivmod> */
/* @0xbe898 ldr r0, [r4] */
/* @0xbe89c mov r7, r1 */
/* @0xbe8a0 mov r1, r5 */
/* @0xbe8a4 bl 0x318dec <__aeabi_idivmod> */
/* @0xbe8a8 sub r3, r5, #1 */
/* @0xbe8ac vmov s15, r5 */
/* @0xbe8b0 ldr r0, [r4, #0x28] */
/* @0xbe8b4 vcvt.f32.s32 s13, s15 */
/* @0xbe8b8 rsb r2, r7, r1 */
/* @0xbe8bc cmp r2, r3 */
/* @0xbe8c0 ldr r3, [r4, #0x24] */
/* @0xbe8c4 addge r7, r7, r5 */
/* @0xbe8c8 vldr s15, [r3, #4] */
/* @0xbe8cc rsb r1, r1, r7 */
/* @0xbe8d0 vmov s14, r1 */
/* @0xbe8d4 vcvt.f32.s32 s14, s14 */
/* @0xbe8d8 vdiv.f32 s14, s14, s13 */
/* @0xbe8dc vmul.f32 s15, s14, s15 */
/* @0xbe8e0 vmov r1, s15 */
/* @0xbe8e4 bl 0x2837fc <spAnimationState_update> */
/* @0xbe8e8 ldr r0, [r4, #0x28] */
/* @0xbe8ec ldr r1, [r4, #0x1c] */
/* @0xbe8f0 bl 0x283220 <spAnimationState_apply> */
/* @0xbe8f4 vldr s14, [r4, #8] */
/* @0xbe8f8 vmul.f32 s17, s17, s14 */
/* @0xbe8fc vldr s15, [r4, #12] */
/* @0xbe900 ldr r2, [r4, #0x1c] */
/* @0xbe904 str r6, [r4] */
/* @0xbe908 mov r1, #0 */
/* @0xbe90c vstr s18, [r2, #88] */
/* @0xbe910 str r10, [r2, #0x5c] */
/* @0xbe914 ldr r3, [r2, #0xc] */
/* @0xbe918 vmul.f32 s16, s16, s15 */
/* @0xbe91c vcmpe.f32 s17, #0 */
/* @0xbe920 vmrs APSR_nzcv, fpscr */
/* @0xbe924 vcmpe.f32 s16, #0 */
/* @0xbe928 movpl r0, #0 */
/* @0xbe92c movmi r0, #1 */
/* @0xbe930 str r0, [r2, #0x50] */
/* @0xbe934 vmrs APSR_nzcv, fpscr */
/* @0xbe938 movpl r0, #0 */
/* @0xbe93c movmi r0, #1 */
/* @0xbe940 cmp r9, r1 */
/* @0xbe944 str r0, [r2, #0x54] */
/* @0xbe948 vstr s20, [r3, #32] */
/* @0xbe94c vstr s21, [r3, #36] */
/* @0xbe950 vstr s19, [r3, #28] */
/* @0xbe954 strb r1, [r4, #0x5] */
/* @0xbe958 beq 0xbe974 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x168> */
/* @0xbe95c mov r2, #7 */
/* @0xbe960 mov r0, r8 */
/* @0xbe964 mov r1, r8 */
/* @0xbe968 mov r3, #58 */
/* @0xbe96c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0xbe970 ldr r2, [r4, #0x1c] */
/* @0xbe974 mov r0, r2 */
/* @0xbe978 bl 0x289ee4 <spSkeleton_updateWorldTransform> */
/* @0xbe97c vpop {d8, d9, d10} */
/* @0xbe980 mov r2, #1 */
/* @0xbe984 ldr r0, [r4, #0x20] */
/* @0xbe988 ldr r1, [r4, #0x1c] */
/* @0xbe98c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xbe990 b 0x28a8b4 <spSkeletonBounds_update> */
/* @0xbe994 vldr s15, [r1, #88] */
/* @0xbe998 vcmp.f32 s15, s18 */
/* @0xbe99c vmrs APSR_nzcv, fpscr */
/* @0xbe9a0 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c> */
/* @0xbe9a4 vmov s14, r10 */
/* @0xbe9a8 vldr s15, [r1, #92] */
/* @0xbe9ac vcmp.f32 s15, s14 */
/* @0xbe9b0 vmrs APSR_nzcv, fpscr */
/* @0xbe9b4 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c> */
/* @0xbe9b8 ldr r3, [r1, #0xc] */
/* @0xbe9bc vldr s15, [r3, #32] */
/* @0xbe9c0 vcmp.f32 s15, s20 */
/* @0xbe9c4 vmrs APSR_nzcv, fpscr */
/* @0xbe9c8 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c> */
/* @0xbe9cc vldr s15, [r3, #36] */
/* @0xbe9d0 vcmp.f32 s15, s21 */
/* @0xbe9d4 vmrs APSR_nzcv, fpscr */
/* @0xbe9d8 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c> */
/* @0xbe9dc vldr s15, [r3, #28] */
/* @0xbe9e0 vcmp.f32 s15, s19 */
/* @0xbe9e4 vmrs APSR_nzcv, fpscr */
/* @0xbe9e8 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c> */
/* @0xbe9ec cmp r9, #0 */
/* @0xbe9f0 bne 0xbe95c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x150> */
/* @0xbe9f4 vpop {d8, d9, d10} */
/* @0xbe9f8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0xbe9fc · CSkeletonSprite::DrawCollision(char const*, int, float, float, float, float, float, unsigned int) · size=164 · insn=41 */
/* @0xbe9fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbea00 vpush {d8} */
/* @0xbea04 sub sp, sp, #20 */
/* @0xbea08 vldr s16, [sp, #68] */
/* @0xbea0c mov r5, r0 */
/* @0xbea10 mov r0, #1 */
/* @0xbea14 mov r8, r2 */
/* @0xbea18 mov r9, r3 */
/* @0xbea1c mov r6, r1 */
/* @0xbea20 ldr r7, [sp, #0x40] */
/* @0xbea24 ldr r11, [sp, #0x48] */
/* @0xbea28 ldr r10, [sp, #0x4c] */
/* @0xbea2c bl 0x284ed8 <spBone_setYDown> */
/* @0xbea30 mov r0, #52 */
/* @0xbea34 bl 0x27c524 <_Znwj> */
/* @0xbea38 mov r1, r5 */
/* @0xbea3c mov r4, r0 */
/* @0xbea40 bl 0xbe67c <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite> */
/* @0xbea44 mov r0, r4 */
/* @0xbea48 mov r1, r6 */
/* @0xbea4c bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc> */
/* @0xbea50 mov r12, #0 */
/* @0xbea54 mov r2, r9 */
/* @0xbea58 mov r3, r7 */
/* @0xbea5c str r12, [sp, #0xc] */
/* @0xbea60 mov r1, r8 */
/* @0xbea64 mov r0, r4 */
/* @0xbea68 vstr s16, [sp] */
/* @0xbea6c str r11, [sp, #0x4] */
/* @0xbea70 str r10, [sp, #0x8] */
/* @0xbea74 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbea78 mov r0, r5 */
/* @0xbea7c ldr r1, [r4, #0x20] */
/* @0xbea80 bl 0xbdd30 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds> */
/* @0xbea84 mov r0, r4 */
/* @0xbea88 bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> */
/* @0xbea8c mov r0, r4 */
/* @0xbea90 add sp, sp, #20 */
/* @0xbea94 vpop {d8} */
/* @0xbea98 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbea9c b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0xbeaa0 · CSkeletonInstance::SetAnimationTransformTime(float, float, float, float, float, float) · size=132 · insn=33 */
/* @0xbeaa0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xbeaa4 vpush {d8} */
/* @0xbeaa8 sub sp, sp, #20 */
/* @0xbeaac vmov s16, r1 */
/* @0xbeab0 mov r1, #0 */
/* @0xbeab4 mov r4, r0 */
/* @0xbeab8 mov r5, r3 */
/* @0xbeabc mov r6, r2 */
/* @0xbeac0 ldr r9, [sp, #0x38] */
/* @0xbeac4 ldr r8, [sp, #0x3c] */
/* @0xbeac8 ldr r7, [sp, #0x40] */
/* @0xbeacc bl 0xbe220 <_ZN17CSkeletonInstance10FrameCountEi> */
/* @0xbead0 ldr r3, [r4, #0x24] */
/* @0xbead4 vldr s15, [r3, #4] */
/* @0xbead8 vdiv.f32 s16, s16, s15 */
/* @0xbeadc str r9, [sp] */
/* @0xbeae0 mov r2, r6 */
/* @0xbeae4 str r8, [sp, #0x4] */
/* @0xbeae8 mov r3, r5 */
/* @0xbeaec str r7, [sp, #0x8] */
/* @0xbeaf0 mov r1, #0 */
/* @0xbeaf4 str r1, [sp, #0xc] */
/* @0xbeaf8 vmov s13, r0 */
/* @0xbeafc mov r0, r4 */
/* @0xbeb00 vmov.f32 s15, #5.000000e-01 */
/* @0xbeb04 vcvt.f32.s32 s14, s13 */
/* @0xbeb08 vmla.f32 s15, s16, s14 */
/* @0xbeb0c vcvt.s32.f32 s15, s15 */
/* @0xbeb10 vmov r1, s15 */
/* @0xbeb14 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbeb18 add sp, sp, #20 */
/* @0xbeb1c vpop {d8} */
/* @0xbeb20 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0xbeb24 · CSkeletonSprite::DrawTime(char const*, char const*, float, float, float, float, float, float, unsigned int, float) · size=192 · insn=48 */
/* @0xbeb24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbeb28 vpush {d8, d9} */
/* @0xbeb2c sub sp, sp, #28 */
/* @0xbeb30 vldr s18, [sp, #88] */
/* @0xbeb34 mov r5, r0 */
/* @0xbeb38 mov r0, #1 */
/* @0xbeb3c mov r10, r2 */
/* @0xbeb40 str r3, [sp, #0x14] */
/* @0xbeb44 mov r8, r1 */
/* @0xbeb48 ldr r11, [sp, #0x50] */
/* @0xbeb4c ldr r9, [sp, #0x54] */
/* @0xbeb50 vldr s17, [sp, #92] */
/* @0xbeb54 vldr s16, [sp, #96] */
/* @0xbeb58 ldr r7, [sp, #0x64] */
/* @0xbeb5c ldr r6, [sp, #0x68] */
/* @0xbeb60 bl 0x284ed8 <spBone_setYDown> */
/* @0xbeb64 mov r0, #52 */
/* @0xbeb68 bl 0x27c524 <_Znwj> */
/* @0xbeb6c mov r1, r5 */
/* @0xbeb70 mov r4, r0 */
/* @0xbeb74 bl 0xbe67c <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite> */
/* @0xbeb78 mov r0, r4 */
/* @0xbeb7c mov r1, r8 */
/* @0xbeb80 bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc> */
/* @0xbeb84 mov r0, r4 */
/* @0xbeb88 mov r1, r10 */
/* @0xbeb8c bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc> */
/* @0xbeb90 ldr r3, [sp, #0x14] */
/* @0xbeb94 mov r0, r4 */
/* @0xbeb98 mov r2, r11 */
/* @0xbeb9c vstr s18, [sp] */
/* @0xbeba0 vstr s17, [sp, #4] */
/* @0xbeba4 mov r1, r3 */
/* @0xbeba8 vstr s16, [sp, #8] */
/* @0xbebac mov r3, r9 */
/* @0xbebb0 bl 0xbeaa0 <_ZN17CSkeletonInstance25SetAnimationTransformTimeEffffff> */
/* @0xbebb4 mov r0, r5 */
/* @0xbebb8 mov r2, r7 */
/* @0xbebbc mov r3, r6 */
/* @0xbebc0 ldr r1, [r4, #0x1c] */
/* @0xbebc4 bl 0xbe054 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf> */
/* @0xbebc8 mov r0, r4 */
/* @0xbebcc bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> */
/* @0xbebd0 mov r0, r4 */
/* @0xbebd4 add sp, sp, #28 */
/* @0xbebd8 vpop {d8, d9} */
/* @0xbebdc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbebe0 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0xbebe4 · CSkeletonInstance::EventCallback(int, spEventType, spEvent*, int) · size=444 · insn=111 */
/* @0xbebe4 cmp r2, #3 */
/* @0xbebe8 push {r4, r5, r6, r7, lr} */
/* @0xbebec sub sp, sp, #84 */
/* @0xbebf0 bne 0xbed5c <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x178> */
/* @0xbebf4 cmp r3, #0 */
/* @0xbebf8 beq 0xbed5c <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x178> */
/* @0xbebfc ldr r0, [r3] */
/* @0xbec00 cmp r0, #0 */
/* @0xbec04 beq 0xbed5c <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x178> */
/* @0xbec08 ldr r5, [pc, #0x168] */
/* @0xbec0c ldr r5, [pc, r5] */
/* @0xbec10 ldr r2, [r5] */
/* @0xbec14 cmp r2, #0 */
/* @0xbec18 beq 0xbed5c <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x178> */
/* @0xbec1c ldr r2, [r3, #0x10] */
/* @0xbec20 cmp r2, #0 */
/* @0xbec24 beq 0xbed70 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x18c> */
/* @0xbec28 ldr r0, [r0] */
/* @0xbec2c vmov s15, r1 */
/* @0xbec30 ldr r6, [pc, #0x144] */
/* @0xbec34 vldr s12, [r3, #8] */
/* @0xbec38 cmp r0, #0 */
/* @0xbec3c vldr s14, [r3, #12] */
/* @0xbec40 add r6, pc, r6 */
/* @0xbec44 vcvt.f64.s32 d5, s15 */
/* @0xbec48 movne r6, r0 */
/* @0xbec4c cmp r2, #0 */
/* @0xbec50 movne r1, r2 */
/* @0xbec54 vcvt.f64.s32 d6, s12 */
/* @0xbec58 vcvt.f64.f32 d7, s14 */
/* @0xbec5c beq 0xbed64 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x180> */
/* @0xbec60 str r1, [sp, #0x40] */
/* @0xbec64 mov r1, #0 */
/* @0xbec68 ldr r0, [pc, #0x110] */
/* @0xbec6c mov r2, #0 */
/* @0xbec70 str r1, [sp, #0x10] */
/* @0xbec74 mov r3, #0 */
/* @0xbec78 str r1, [sp, #0x20] */
/* @0xbec7c add r0, pc, r0 */
/* @0xbec80 str r1, [sp, #0x30] */
/* @0xbec84 vstr d5, [sp, #8] */
/* @0xbec88 ldr r4, [pc, #0xf4] */
/* @0xbec8c vstr d6, [sp, #24] */
/* @0xbec90 ldr lr, [pc, #0xf0] */
/* @0xbec94 vstr d7, [sp, #40] */
/* @0xbec98 ldr r12, [pc, #0xec] */
/* @0xbec9c add r4, pc, r4 */
/* @0xbeca0 ldr r1, [pc, #0xe8] */
/* @0xbeca4 add lr, pc, lr */
/* @0xbeca8 add r12, pc, r12 */
/* @0xbecac strd r2, r3, [sp, #56] */
/* @0xbecb0 str r0, [sp, #0x4] */
/* @0xbecb4 add r1, pc, r1 */
/* @0xbecb8 str r4, [sp, #0x14] */
/* @0xbecbc mov r0, #5 */
/* @0xbecc0 str lr, [sp, #0x24] */
/* @0xbecc4 str r12, [sp, #0x34] */
/* @0xbecc8 str r6, [sp] */
/* @0xbeccc bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0xbecd0 ldr r4, [pc, #0xbc] */
/* @0xbecd4 ldr r1, [r5] */
/* @0xbecd8 mov r3, #59 */
/* @0xbecdc ldr r4, [pc, r4] */
/* @0xbece0 mov r2, #7 */
/* @0xbece4 str r0, [r4] */
/* @0xbece8 mov r0, r1 */
/* @0xbecec bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0xbecf0 ldr r3, [r4] */
/* @0xbecf4 cmp r3, #0 */
/* @0xbecf8 blt 0xbed54 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x170> */
/* @0xbecfc add r7, sp, #76 */
/* @0xbed00 ldr r5, [pc, #0x90] */
/* @0xbed04 mov r0, r7 */
/* @0xbed08 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xbed0c ldr r5, [pc, r5] */
/* @0xbed10 ldr r2, [r4] */
/* @0xbed14 ldr r3, [r5, #0x4] */
/* @0xbed18 add r1, r3, r2, lsl #2 */
/* @0xbed1c ldr r6, [r3, r2, lsl #2] */
/* @0xbed20 cmp r6, #0 */
/* @0xbed24 beq 0xbed44 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x160> */
/* @0xbed28 mov r0, r6 */
/* @0xbed2c bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0xbed30 mov r0, r6 */
/* @0xbed34 bl 0x27d1d0 <_ZdlPv> */
/* @0xbed38 ldr r1, [r4] */
/* @0xbed3c ldr r3, [r5, #0x4] */
/* @0xbed40 add r1, r3, r1, lsl #2 */
/* @0xbed44 mov r3, #0 */
/* @0xbed48 mov r0, r7 */
/* @0xbed4c str r3, [r1] */
/* @0xbed50 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xbed54 mvn r3, #0 */
/* @0xbed58 str r3, [r4] */
/* @0xbed5c add sp, sp, #84 */
/* @0xbed60 pop {r4, r5, r6, r7, pc} */
/* @0xbed64 ldr r1, [pc, #0x30] */
/* @0xbed68 add r1, pc, r1 */
/* @0xbed6c b 0xbec60 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x7c> */
/* @0xbed70 ldr r2, [r0, #0xc] */
/* @0xbed74 b 0xbec28 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi+0x44> */
/* @0xbed78 eorseq lr, r2, r8, lsr #26 */
/* @0xbed7c .word 0x0026fef6 */
/* @0xbed80 mlaeq r7, r4, r11, r1 */
/* @0xbed84 eoreq r1, r7, r12, ror r11 */
/* @0xbed88 eoreq r1, r7, r12, ror r11 */
/* @0xbed8c eoreq r1, r7, r0, lsl #23 */
/* @0xbed90 eoreq r1, r7, r4, asr r11 */
/* @0xbed94 eorseq lr, r2, r12, asr r12 */
/* @0xbed98 eorseq lr, r2, r0, lsr r12 */
/* @0xbed9c eoreq pc, r6, lr, asr #27 */

/* ── FUNC 0xbeda0 · _spAnimationCallback(spAnimationState*, int, spEventType, spEvent*, int) · size=8 · insn=2 */
/* @0xbeda0 ldr r0, [r0, #0x14] */
/* @0xbeda4 b 0xbebe4 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi> */

/* ── FUNC 0xbeda8 · CSkeletonInstance::ComputeBoundingBox(tagYYRECT*, int, float, float, float, float, float) · size=184 · insn=46 */
/* @0xbeda8 ldr r12, [r0, #0x20] */
/* @0xbedac push {r4, r5, lr} */
/* @0xbedb0 cmp r12, #0 */
/* @0xbedb4 sub sp, sp, #20 */
/* @0xbedb8 mov r5, r0 */
/* @0xbedbc mov r4, r1 */
/* @0xbedc0 beq 0xbee54 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff+0xac> */
/* @0xbedc4 ldr r12, [r12] */
/* @0xbedc8 cmp r12, #0 */
/* @0xbedcc ble 0xbee54 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff+0xac> */
/* @0xbedd0 vldr s15, [sp, #36] */
/* @0xbedd4 mov r1, r2 */
/* @0xbedd8 vstr s15, [sp] */
/* @0xbeddc mov r2, r3 */
/* @0xbede0 vldr s15, [sp, #40] */
/* @0xbede4 mov r12, #0 */
/* @0xbede8 vstr s15, [sp, #4] */
/* @0xbedec ldr r3, [sp, #0x20] */
/* @0xbedf0 vldr s15, [sp, #44] */
/* @0xbedf4 str r12, [sp, #0xc] */
/* @0xbedf8 vstr s15, [sp, #8] */
/* @0xbedfc bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbee00 vmov.f32 s15, #5.000000e-01 */
/* @0xbee04 ldr r3, [r5, #0x20] */
/* @0xbee08 vldr s12, [r3, #12] */
/* @0xbee0c vldr s13, [r3, #20] */
/* @0xbee10 vldr s14, [r3, #16] */
/* @0xbee14 vldr s11, [r3, #24] */
/* @0xbee18 mov r0, #1 */
/* @0xbee1c vadd.f32 s12, s12, s15 */
/* @0xbee20 vadd.f32 s13, s13, s15 */
/* @0xbee24 vadd.f32 s14, s14, s15 */
/* @0xbee28 vadd.f32 s15, s11, s15 */
/* @0xbee2c vcvt.s32.f32 s12, s12 */
/* @0xbee30 vcvt.s32.f32 s13, s13 */
/* @0xbee34 vstr s12, [r4] */
/* @0xbee38 vcvt.s32.f32 s14, s14 */
/* @0xbee3c vstr s13, [r4, #8] */
/* @0xbee40 vcvt.s32.f32 s15, s15 */
/* @0xbee44 vstr s14, [r4, #4] */
/* @0xbee48 vstr s15, [r4, #12] */
/* @0xbee4c add sp, sp, #20 */
/* @0xbee50 pop {r4, r5, pc} */
/* @0xbee54 mov r0, #0 */
/* @0xbee58 add sp, sp, #20 */
/* @0xbee5c pop {r4, r5, pc} */

/* ── FUNC 0xbee60 · CSkeletonInstance::GetBoundingBox(float&, float&, float&, float&) · size=124 · insn=31 */
/* @0xbee60 push {r3, r4, r5, r6, r7, lr} */
/* @0xbee64 mov r4, r0 */
/* @0xbee68 ldr r0, [r0, #0x20] */
/* @0xbee6c mov r6, r1 */
/* @0xbee70 mov r5, r2 */
/* @0xbee74 mov r7, r3 */
/* @0xbee78 cmp r0, #0 */
/* @0xbee7c popeq {r3, r4, r5, r6, r7, pc} */
/* @0xbee80 ldr r0, [r0] */
/* @0xbee84 cmp r0, #0 */
/* @0xbee88 ble 0xbeed4 <_ZN17CSkeletonInstance14GetBoundingBoxERfS0_S0_S0_+0x74> */
/* @0xbee8c ldr r0, [r4, #0x1c] */
/* @0xbee90 bl 0x289ee4 <spSkeleton_updateWorldTransform> */
/* @0xbee94 ldr r0, [r4, #0x20] */
/* @0xbee98 ldr r1, [r4, #0x1c] */
/* @0xbee9c mov r2, #1 */
/* @0xbeea0 bl 0x28a8b4 <spSkeletonBounds_update> */
/* @0xbeea4 ldr r12, [r4, #0x20] */
/* @0xbeea8 ldr r2, [sp, #0x18] */
/* @0xbeeac mov r0, #1 */
/* @0xbeeb0 ldr r3, [r12, #0xc] */
/* @0xbeeb4 str r3, [r6] */
/* @0xbeeb8 ldr r3, [r12, #0x10] */
/* @0xbeebc str r3, [r5] */
/* @0xbeec0 ldr r3, [r12, #0x14] */
/* @0xbeec4 str r3, [r7] */
/* @0xbeec8 ldr r3, [r12, #0x18] */
/* @0xbeecc str r3, [r2] */
/* @0xbeed0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xbeed4 mov r0, #0 */
/* @0xbeed8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0xbeedc · CSkeletonInstance::GetNumBoundingBoxAttachments() · size=40 · insn=10 */
/* @0xbeedc push {r4, lr} */
/* @0xbeee0 mov r4, r0 */
/* @0xbeee4 mov r2, #1 */
/* @0xbeee8 ldr r0, [r0, #0x20] */
/* @0xbeeec ldr r1, [r4, #0x1c] */
/* @0xbeef0 bl 0x28a8b4 <spSkeletonBounds_update> */
/* @0xbeef4 ldr r0, [r4, #0x20] */
/* @0xbeef8 cmp r0, #0 */
/* @0xbeefc ldrne r0, [r0] */
/* @0xbef00 pop {r4, pc} */

/* ── FUNC 0xbef04 · CSkeletonInstance::GetBoundingBoxAttachment(int, char const**, int*, float*) · size=212 · insn=53 */
/* @0xbef04 push {r4, r5, r6, lr} */
/* @0xbef08 mov r4, r0 */
/* @0xbef0c ldr r0, [r0, #0x20] */
/* @0xbef10 mov r5, r3 */
/* @0xbef14 cmp r0, #0 */
/* @0xbef18 popeq {r4, r5, r6, pc} */
/* @0xbef1c cmp r1, #0 */
/* @0xbef20 blt 0xbefc8 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xc4> */
/* @0xbef24 ldr r3, [r0] */
/* @0xbef28 cmp r1, r3 */
/* @0xbef2c bge 0xbefc8 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xc4> */
/* @0xbef30 cmp r2, #0 */
/* @0xbef34 beq 0xbefd0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xcc> */
/* @0xbef38 ldr r3, [r0, #0x4] */
/* @0xbef3c cmp r3, #0 */
/* @0xbef40 beq 0xbefd0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xcc> */
/* @0xbef44 ldr r3, [r3, r1, lsl #2] */
/* @0xbef48 lsl r6, r1, #2 */
/* @0xbef4c ldr r3, [r3] */
/* @0xbef50 str r3, [r2] */
/* @0xbef54 ldr r0, [r4, #0x1c] */
/* @0xbef58 bl 0x289ee4 <spSkeleton_updateWorldTransform> */
/* @0xbef5c mov r2, #1 */
/* @0xbef60 ldr r0, [r4, #0x20] */
/* @0xbef64 ldr r1, [r4, #0x1c] */
/* @0xbef68 bl 0x28a8b4 <spSkeletonBounds_update> */
/* @0xbef6c ldr r3, [r4, #0x20] */
/* @0xbef70 cmp r5, #0 */
/* @0xbef74 ldr r3, [r3, #0x8] */
/* @0xbef78 ldr r3, [r3, r6] */
/* @0xbef7c ldrne r2, [r3, #0x4] */
/* @0xbef80 addne r2, r2, r2, lsr #31 */
/* @0xbef84 asrne r2, r2, #1 */
/* @0xbef88 strne r2, [r5] */
/* @0xbef8c ldr r2, [sp, #0x10] */
/* @0xbef90 cmp r2, #0 */
/* @0xbef94 beq 0xbefc0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xbc> */
/* @0xbef98 ldr r0, [r3, #0x4] */
/* @0xbef9c cmp r0, #0 */
/* @0xbefa0 ble 0xbefc0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xbc> */
/* @0xbefa4 ldr r3, [r3] */
/* @0xbefa8 ldr r2, [sp, #0x10] */
/* @0xbefac add r0, r3, r0, lsl #2 */
/* @0xbefb0 ldr r1, [r3], #4 */
/* @0xbefb4 cmp r3, r0 */
/* @0xbefb8 str r1, [r2], #4 */
/* @0xbefbc bne 0xbefb0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xac> */
/* @0xbefc0 mov r0, #1 */
/* @0xbefc4 pop {r4, r5, r6, pc} */
/* @0xbefc8 mov r0, #0 */
/* @0xbefcc pop {r4, r5, r6, pc} */
/* @0xbefd0 lsl r6, r1, #2 */
/* @0xbefd4 b 0xbef54 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0x50> */

/* ── FUNC 0xbefd8 · CSkeletonInstance::SkeletonCollision(int, float, float, float, float, float, CSkeletonInstance*, int, float, float, float, float, float) · size=292 · insn=73 */
/* @0xbefd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbefdc vpush {d8} */
/* @0xbefe0 sub sp, sp, #20 */
/* @0xbefe4 vldr s16, [sp, #92] */
/* @0xbefe8 mov r9, #0 */
/* @0xbefec mov r8, r0 */
/* @0xbeff0 ldr r12, [sp, #0x40] */
/* @0xbeff4 ldr r10, [sp, #0x4c] */
/* @0xbeff8 ldr r6, [sp, #0x50] */
/* @0xbeffc str r12, [sp] */
/* @0xbf000 ldr r12, [sp, #0x44] */
/* @0xbf004 ldr r5, [sp, #0x54] */
/* @0xbf008 ldr r4, [sp, #0x58] */
/* @0xbf00c str r12, [sp, #0x4] */
/* @0xbf010 ldr r12, [sp, #0x48] */
/* @0xbf014 ldr r11, [sp, #0x60] */
/* @0xbf018 ldr r7, [sp, #0x64] */
/* @0xbf01c str r12, [sp, #0x8] */
/* @0xbf020 str r9, [sp, #0xc] */
/* @0xbf024 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbf028 mov r2, r5 */
/* @0xbf02c mov r3, r4 */
/* @0xbf030 vstr s16, [sp] */
/* @0xbf034 str r11, [sp, #0x4] */
/* @0xbf038 mov r1, r6 */
/* @0xbf03c str r7, [sp, #0x8] */
/* @0xbf040 mov r0, r10 */
/* @0xbf044 str r9, [sp, #0xc] */
/* @0xbf048 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbf04c ldr r3, [r10, #0x20] */
/* @0xbf050 ldr r2, [r3] */
/* @0xbf054 cmp r2, r9 */
/* @0xbf058 ble 0xbf0f4 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0x11c> */
/* @0xbf05c ldr r2, [r3, #0x8] */
/* @0xbf060 ldr r6, [r2, r9, lsl #2] */
/* @0xbf064 ldr r5, [r6, #0x4] */
/* @0xbf068 asr r5, r5, #1 */
/* @0xbf06c cmp r5, #0 */
/* @0xbf070 subgt r7, r5, #1 */
/* @0xbf074 movgt r11, #4 */
/* @0xbf078 movgt r4, #0 */
/* @0xbf07c bgt 0xbf08c <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0xb4> */
/* @0xbf080 b 0xbf0e4 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0x10c> */
/* @0xbf084 cmp r4, r5 */
/* @0xbf088 beq 0xbf0e0 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0x108> */
/* @0xbf08c ldr r0, [r6] */
/* @0xbf090 cmp r4, r7 */
/* @0xbf094 add r3, r0, r4, lsl #3 */
/* @0xbf098 add r12, r0, r11 */
/* @0xbf09c add r4, r4, #1 */
/* @0xbf0a0 add r11, r11, #8 */
/* @0xbf0a4 ldr r1, [r3] */
/* @0xbf0a8 ldrne r0, [r12, #0x8] */
/* @0xbf0ac ldreq r3, [r0] */
/* @0xbf0b0 ldreq r0, [r0, #0x4] */
/* @0xbf0b4 ldrne r3, [r12, #0x4] */
/* @0xbf0b8 ldr r2, [r12] */
/* @0xbf0bc str r0, [sp] */
/* @0xbf0c0 ldr r0, [r8, #0x20] */
/* @0xbf0c4 bl 0x28acf4 <spSkeletonBounds_intersectsSegment> */
/* @0xbf0c8 cmp r0, #0 */
/* @0xbf0cc beq 0xbf084 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0xac> */
/* @0xbf0d0 mov r0, #1 */
/* @0xbf0d4 add sp, sp, #20 */
/* @0xbf0d8 vpop {d8} */
/* @0xbf0dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xbf0e0 ldr r3, [r10, #0x20] */
/* @0xbf0e4 ldr r2, [r3] */
/* @0xbf0e8 add r9, r9, #1 */
/* @0xbf0ec cmp r2, r9 */
/* @0xbf0f0 bgt 0xbf05c <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0x84> */
/* @0xbf0f4 mov r0, #0 */
/* @0xbf0f8 b 0xbf0d4 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0xfc> */

/* ── FUNC 0xbf0fc · CSkeletonInstance::SpriteCollision(int, float, float, float, float, float, CSprite*, tagYYRECT*, int, float, float, float, float, float) · size=632 · insn=158 */
/* @0xbf0fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbf100 vpush {d8, d9, d10, d11, d12} */
/* @0xbf104 sub sp, sp, #28 */
/* @0xbf108 vldr s24, [sp, #128] */
/* @0xbf10c mov r12, #0 */
/* @0xbf110 mov r8, r0 */
/* @0xbf114 ldr lr, [sp, #0x68] */
/* @0xbf118 vldr s18, [sp, #132] */
/* @0xbf11c ldr r5, [sp, #0x74] */
/* @0xbf120 vldr s17, [sp, #144] */
/* @0xbf124 str r12, [sp, #0xc] */
/* @0xbf128 str lr, [sp] */
/* @0xbf12c ldr lr, [sp, #0x6c] */
/* @0xbf130 ldr r4, [sp, #0x78] */
/* @0xbf134 ldr r9, [sp, #0x7c] */
/* @0xbf138 str lr, [sp, #0x4] */
/* @0xbf13c ldr lr, [sp, #0x70] */
/* @0xbf140 str lr, [sp, #0x8] */
/* @0xbf144 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbf148 cmp r5, #0 */
/* @0xbf14c beq 0xbf350 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x254> */
/* @0xbf150 ldr r1, [r5, #0x18] */
/* @0xbf154 cmp r1, #0 */
/* @0xbf158 ble 0xbf350 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x254> */
/* @0xbf15c mov r0, r5 */
/* @0xbf160 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* @0xbf164 ldr r6, [r5, #0x3c] */
/* @0xbf168 cmp r6, #0 */
/* @0xbf16c ble 0xbf180 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x84> */
/* @0xbf170 mov r0, r9 */
/* @0xbf174 mov r1, r6 */
/* @0xbf178 bl 0x318dec <__aeabi_idivmod> */
/* @0xbf17c mov r9, r1 */
/* @0xbf180 vldr s11, [r4] */
/* @0xbf184 vcvt.f32.s32 s15, s11 */
/* @0xbf188 ldr r3, [r8, #0x20] */
/* @0xbf18c vldr s14, [r3, #12] */
/* @0xbf190 cmp r9, #0 */
/* @0xbf194 vldr s11, [r4, #8] */
/* @0xbf198 addlt r9, r9, r6 */
/* @0xbf19c vldr s12, [sp, #136] */
/* @0xbf1a0 vldr s13, [sp, #140] */
/* @0xbf1a4 vldr s20, [pc, #452] */
/* @0xbf1a8 vcmpe.f32 s14, s15 */
/* @0xbf1ac vmrs APSR_nzcv, fpscr */
/* @0xbf1b0 vcvtle.s32.f32 s15, s15 */
/* @0xbf1b4 vcvtgt.s32.f32 s14, s14 */
/* @0xbf1b8 vmovle r6, s15 */
/* @0xbf1bc vcvt.f32.s32 s15, s11 */
/* @0xbf1c0 vmovgt r6, s14 */
/* @0xbf1c4 vldr s14, [r3, #20] */
/* @0xbf1c8 vcmpe.f32 s14, s15 */
/* @0xbf1cc vmov.f32 s22, #1.000000e+00 */
/* @0xbf1d0 vmrs APSR_nzcv, fpscr */
/* @0xbf1d4 vcvtpl.s32.f32 s15, s15 */
/* @0xbf1d8 vcvtmi.s32.f32 s14, s14 */
/* @0xbf1dc vstrpl s15, [sp, #20] */
/* @0xbf1e0 vdiv.f32 s19, s22, s12 */
/* @0xbf1e4 vldr s12, [r4, #4] */
/* @0xbf1e8 vstrmi s14, [sp, #20] */
/* @0xbf1ec vldr s14, [r3, #16] */
/* @0xbf1f0 vcvt.f32.s32 s15, s12 */
/* @0xbf1f4 vcmpe.f32 s14, s15 */
/* @0xbf1f8 vmrs APSR_nzcv, fpscr */
/* @0xbf1fc vcvtle.s32.f32 s15, s15 */
/* @0xbf200 vcvtgt.s32.f32 s14, s14 */
/* @0xbf204 vmovle r7, s15 */
/* @0xbf208 vldr s15, [r4, #12] */
/* @0xbf20c vcvt.f32.s32 s15, s15 */
/* @0xbf210 vmovgt r7, s14 */
/* @0xbf214 vldr s14, [r3, #24] */
/* @0xbf218 vdiv.f32 s22, s22, s13 */
/* @0xbf21c vnmul.f32 s13, s17, s20 */
/* @0xbf220 vcmpe.f32 s14, s15 */
/* @0xbf224 vmov r0, s13 */
/* @0xbf228 vmrs APSR_nzcv, fpscr */
/* @0xbf22c vcvtmi.s32.f32 s14, s14 */
/* @0xbf230 vcvtpl.s32.f32 s15, s15 */
/* @0xbf234 vmovmi r11, s14 */
/* @0xbf238 vmovpl r11, s15 */
/* @0xbf23c bl 0xb6580 <sinf@plt> */
/* @0xbf240 vmul.f32 s20, s17, s20 */
/* @0xbf244 vmov s16, r0 */
/* @0xbf248 vmov r0, s20 */
/* @0xbf24c bl 0xb658c <cosf@plt> */
/* @0xbf250 ldr r3, [sp, #0x14] */
/* @0xbf254 cmp r6, r3 */
/* @0xbf258 vmov s20, r0 */
/* @0xbf25c bgt 0xbf350 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x254> */
/* @0xbf260 lsl r9, r9, #3 */
/* @0xbf264 cmp r7, r11 */
/* @0xbf268 bgt 0xbf340 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x244> */
/* @0xbf26c vmov s11, r6 */
/* @0xbf270 mov r4, r7 */
/* @0xbf274 vcvt.f32.s32 s23, s11 */
/* @0xbf278 vsub.f32 s21, s23, s24 */
/* @0xbf27c vmul.f32 s17, s20, s21 */
/* @0xbf280 vmul.f32 s21, s16, s21 */
/* @0xbf284 vmov s11, r4 */
/* @0xbf288 ldr r2, [r5, #0x28] */
/* @0xbf28c add r4, r4, #1 */
/* @0xbf290 vcvt.f32.s32 s13, s11 */
/* @0xbf294 vldr s11, [r5, #36] */
/* @0xbf298 vsub.f32 s14, s13, s18 */
/* @0xbf29c vmov.f32 s12, s17 */
/* @0xbf2a0 vmla.f32 s12, s14, s16 */
/* @0xbf2a4 vcvt.f32.s32 s15, s11 */
/* @0xbf2a8 vmla.f32 s15, s12, s19 */
/* @0xbf2ac vcvt.s32.f32 s15, s15 */
/* @0xbf2b0 vmov r3, s15 */
/* @0xbf2b4 cmp r3, #0 */
/* @0xbf2b8 blt 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c> */
/* @0xbf2bc ldr r0, [r5, #0x1c] */
/* @0xbf2c0 cmp r3, r0 */
/* @0xbf2c4 bge 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c> */
/* @0xbf2c8 vmov.f32 s12, s21 */
/* @0xbf2cc vmov s11, r2 */
/* @0xbf2d0 vnmls.f32 s12, s20, s14 */
/* @0xbf2d4 vcvt.f32.s32 s15, s11 */
/* @0xbf2d8 vmla.f32 s15, s12, s22 */
/* @0xbf2dc vcvt.s32.f32 s15, s15 */
/* @0xbf2e0 vmov r12, s15 */
/* @0xbf2e4 cmp r12, #0 */
/* @0xbf2e8 blt 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c> */
/* @0xbf2ec ldr r2, [r5, #0x20] */
/* @0xbf2f0 cmp r12, r2 */
/* @0xbf2f4 bge 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c> */
/* @0xbf2f8 ldrb r10, [r5, #0x31] */
/* @0xbf2fc vmov r1, s23 */
/* @0xbf300 cmp r10, #0 */
/* @0xbf304 vmov r2, s13 */
/* @0xbf308 beq 0xbf328 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x22c> */
/* @0xbf30c ldr r10, [r5, #0x40] */
/* @0xbf310 add r10, r10, r9 */
/* @0xbf314 ldr r10, [r10, #0x4] */
/* @0xbf318 mla r0, r0, r12, r10 */
/* @0xbf31c ldrb r3, [r0, r3] */
/* @0xbf320 cmp r3, #0 */
/* @0xbf324 beq 0xbf338 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x23c> */
/* @0xbf328 ldr r0, [r8, #0x20] */
/* @0xbf32c bl 0x28ac8c <spSkeletonBounds_containsPoint> */
/* @0xbf330 cmp r0, #0 */
/* @0xbf334 bne 0xbf360 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x264> */
/* @0xbf338 cmp r11, r4 */
/* @0xbf33c bge 0xbf284 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x188> */
/* @0xbf340 ldr r3, [sp, #0x14] */
/* @0xbf344 add r6, r6, #1 */
/* @0xbf348 cmp r3, r6 */
/* @0xbf34c bge 0xbf264 <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff+0x168> */
/* @0xbf350 mov r0, #0 */
/* @0xbf354 add sp, sp, #28 */
/* @0xbf358 vpop {d8, d9, d10, d11, d12} */
/* @0xbf35c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xbf360 mov r0, #1 */
/* @0xbf364 add sp, sp, #28 */
/* @0xbf368 vpop {d8, d9, d10, d11, d12} */
/* @0xbf36c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xbf370 vstmialo lr, {s30, s31} */

/* ── FUNC 0xbf374 · CSkeletonInstance::PointCollision(int, float, float, float, float, float, float, float) · size=88 · insn=22 */
/* @0xbf374 push {r4, r5, r6, lr} */
/* @0xbf378 sub sp, sp, #16 */
/* @0xbf37c mov r12, #0 */
/* @0xbf380 mov r6, r0 */
/* @0xbf384 ldr lr, [sp, #0x20] */
/* @0xbf388 ldr r5, [sp, #0x2c] */
/* @0xbf38c ldr r4, [sp, #0x30] */
/* @0xbf390 str lr, [sp] */
/* @0xbf394 ldr lr, [sp, #0x24] */
/* @0xbf398 str r12, [sp, #0xc] */
/* @0xbf39c str lr, [sp, #0x4] */
/* @0xbf3a0 ldr lr, [sp, #0x28] */
/* @0xbf3a4 str lr, [sp, #0x8] */
/* @0xbf3a8 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbf3ac ldr r0, [r6, #0x20] */
/* @0xbf3b0 mov r1, r5 */
/* @0xbf3b4 mov r2, r4 */
/* @0xbf3b8 bl 0x28ac8c <spSkeletonBounds_containsPoint> */
/* @0xbf3bc adds r0, r0, #0 */
/* @0xbf3c0 movne r0, #1 */
/* @0xbf3c4 add sp, sp, #16 */
/* @0xbf3c8 pop {r4, r5, r6, pc} */

/* ── FUNC 0xbf3cc · CSkeletonInstance::LineCollision(int, float, float, float, float, float, float, float, float, float) · size=104 · insn=26 */
/* @0xbf3cc push {r4, r5, r6, r7, r8, lr} */
/* @0xbf3d0 sub sp, sp, #16 */
/* @0xbf3d4 mov r12, #0 */
/* @0xbf3d8 mov r7, r0 */
/* @0xbf3dc ldr lr, [sp, #0x28] */
/* @0xbf3e0 ldr r4, [sp, #0x2c] */
/* @0xbf3e4 ldr r6, [sp, #0x34] */
/* @0xbf3e8 str lr, [sp] */
/* @0xbf3ec ldr lr, [sp, #0x30] */
/* @0xbf3f0 str r4, [sp, #0x4] */
/* @0xbf3f4 ldr r5, [sp, #0x38] */
/* @0xbf3f8 ldr r4, [sp, #0x3c] */
/* @0xbf3fc ldr r8, [sp, #0x40] */
/* @0xbf400 str lr, [sp, #0x8] */
/* @0xbf404 str r12, [sp, #0xc] */
/* @0xbf408 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbf40c ldr r0, [r7, #0x20] */
/* @0xbf410 mov r1, r6 */
/* @0xbf414 str r8, [sp] */
/* @0xbf418 mov r2, r5 */
/* @0xbf41c mov r3, r4 */
/* @0xbf420 bl 0x28acf4 <spSkeletonBounds_intersectsSegment> */
/* @0xbf424 adds r0, r0, #0 */
/* @0xbf428 movne r0, #1 */
/* @0xbf42c add sp, sp, #16 */
/* @0xbf430 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0xbf434 · CSkeletonInstance::RectangleCollision(int, float, float, float, float, float, float, float, float, float) · size=240 · insn=60 */
/* @0xbf434 push {r4, r5, r6, r7, r8, lr} */
/* @0xbf438 sub sp, sp, #16 */
/* @0xbf43c mov r12, #0 */
/* @0xbf440 mov r6, r0 */
/* @0xbf444 ldr lr, [sp, #0x28] */
/* @0xbf448 ldr r4, [sp, #0x2c] */
/* @0xbf44c ldr r7, [sp, #0x34] */
/* @0xbf450 str lr, [sp] */
/* @0xbf454 ldr lr, [sp, #0x30] */
/* @0xbf458 str r4, [sp, #0x4] */
/* @0xbf45c ldr r5, [sp, #0x3c] */
/* @0xbf460 ldr r4, [sp, #0x38] */
/* @0xbf464 ldr r8, [sp, #0x40] */
/* @0xbf468 str lr, [sp, #0x8] */
/* @0xbf46c str r12, [sp, #0xc] */
/* @0xbf470 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbf474 ldr r0, [r6, #0x20] */
/* @0xbf478 mov r1, r7 */
/* @0xbf47c str r8, [sp] */
/* @0xbf480 mov r2, r4 */
/* @0xbf484 mov r3, r5 */
/* @0xbf488 bl 0x28acf4 <spSkeletonBounds_intersectsSegment> */
/* @0xbf48c cmp r0, #0 */
/* @0xbf490 beq 0xbf4a0 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x6c> */
/* @0xbf494 mov r0, #1 */
/* @0xbf498 add sp, sp, #16 */
/* @0xbf49c pop {r4, r5, r6, r7, r8, pc} */
/* @0xbf4a0 ldr r0, [r6, #0x20] */
/* @0xbf4a4 mov r1, r7 */
/* @0xbf4a8 str r4, [sp] */
/* @0xbf4ac mov r2, r4 */
/* @0xbf4b0 mov r3, r5 */
/* @0xbf4b4 bl 0x28acf4 <spSkeletonBounds_intersectsSegment> */
/* @0xbf4b8 cmp r0, #0 */
/* @0xbf4bc bne 0xbf494 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x60> */
/* @0xbf4c0 ldr r0, [r6, #0x20] */
/* @0xbf4c4 mov r1, r5 */
/* @0xbf4c8 str r8, [sp] */
/* @0xbf4cc mov r2, r4 */
/* @0xbf4d0 mov r3, r5 */
/* @0xbf4d4 bl 0x28acf4 <spSkeletonBounds_intersectsSegment> */
/* @0xbf4d8 cmp r0, #0 */
/* @0xbf4dc bne 0xbf494 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x60> */
/* @0xbf4e0 ldr r0, [r6, #0x20] */
/* @0xbf4e4 mov r1, r5 */
/* @0xbf4e8 str r8, [sp] */
/* @0xbf4ec mov r2, r8 */
/* @0xbf4f0 mov r3, r7 */
/* @0xbf4f4 bl 0x28acf4 <spSkeletonBounds_intersectsSegment> */
/* @0xbf4f8 cmp r0, #0 */
/* @0xbf4fc bne 0xbf494 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x60> */
/* @0xbf500 str r4, [sp] */
/* @0xbf504 mov r1, r7 */
/* @0xbf508 ldr r0, [r6, #0x20] */
/* @0xbf50c mov r2, r8 */
/* @0xbf510 mov r3, r7 */
/* @0xbf514 bl 0x28acf4 <spSkeletonBounds_intersectsSegment> */
/* @0xbf518 adds r0, r0, #0 */
/* @0xbf51c movne r0, #1 */
/* @0xbf520 b 0xbf498 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x64> */

/* ── FUNC 0xbf524 · CSkeletonInstance::EllipseCollision(int, float, float, float, float, float, tagYYRECT*) · size=1032 · insn=258 */
/* @0xbf524 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xbf528 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0xbf52c sub sp, sp, #36 */
/* @0xbf530 vldr s30, [sp, #128] */
/* @0xbf534 mov r12, #0 */
/* @0xbf538 vldr s31, [sp, #132] */
/* @0xbf53c ldr r4, [sp, #0x8c] */
/* @0xbf540 vldr s16, [sp, #136] */
/* @0xbf544 str r12, [sp, #0xc] */
/* @0xbf548 vstr s30, [sp] */
/* @0xbf54c vstr s31, [sp, #4] */
/* @0xbf550 vstr s16, [sp, #8] */
/* @0xbf554 mov r9, r0 */
/* @0xbf558 vmov s27, r2 */
/* @0xbf55c vmov s29, r3 */
/* @0xbf560 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xbf564 ldr r0, [r4] */
/* @0xbf568 vmov.f32 s19, #1.000000e+00 */
/* @0xbf56c ldr r3, [r9, #0x20] */
/* @0xbf570 vldr s14, [r3, #12] */
/* @0xbf574 ldr r12, [r4, #0x8] */
/* @0xbf578 vldr s12, [r3, #20] */
/* @0xbf57c vmov s10, r0 */
/* @0xbf580 ldr r2, [r4, #0x4] */
/* @0xbf584 ldr r1, [r4, #0xc] */
/* @0xbf588 add r4, r0, r12 */
/* @0xbf58c vmov s13, r12 */
/* @0xbf590 rsb r0, r0, r12 */
/* @0xbf594 add r4, r4, r4, lsr #31 */
/* @0xbf598 add r0, r0, r0, lsr #31 */
/* @0xbf59c asr r4, r4, #1 */
/* @0xbf5a0 asr r0, r0, #1 */
/* @0xbf5a4 vcvt.f32.s32 s15, s10 */
/* @0xbf5a8 vmov s10, r2 */
/* @0xbf5ac vcmpe.f32 s14, s15 */
/* @0xbf5b0 vmrs APSR_nzcv, fpscr */
/* @0xbf5b4 vcvtle.s32.f32 s15, s15 */
/* @0xbf5b8 vmovle r6, s15 */
/* @0xbf5bc vcvt.f32.s32 s15, s13 */
/* @0xbf5c0 vcvtgt.s32.f32 s11, s14 */
/* @0xbf5c4 vcmpe.f32 s12, s15 */
/* @0xbf5c8 vmovgt r6, s11 */
/* @0xbf5cc vcvt.f32.s32 s13, s10 */
/* @0xbf5d0 vmrs APSR_nzcv, fpscr */
/* @0xbf5d4 vmov s10, r1 */
/* @0xbf5d8 vcvtmi.s32.f32 s15, s12 */
/* @0xbf5dc vcvtpl.s32.f32 s15, s15 */
/* @0xbf5e0 vmov r8, s15 */
/* @0xbf5e4 vldr s15, [r3, #16] */
/* @0xbf5e8 vcmpe.f32 s15, s13 */
/* @0xbf5ec vmrs APSR_nzcv, fpscr */
/* @0xbf5f0 vcvtgt.s32.f32 s11, s15 */
/* @0xbf5f4 vcvtle.s32.f32 s13, s13 */
/* @0xbf5f8 vmovgt r7, s11 */
/* @0xbf5fc vcvt.f32.s32 s11, s10 */
/* @0xbf600 vmovle r7, s13 */
/* @0xbf604 vldr s13, [r3, #24] */
/* @0xbf608 add r3, r2, r1 */
/* @0xbf60c rsb r2, r2, r1 */
/* @0xbf610 add r3, r3, r3, lsr #31 */
/* @0xbf614 add r2, r2, r2, lsr #31 */
/* @0xbf618 asr r3, r3, #1 */
/* @0xbf61c asr r2, r2, #1 */
/* @0xbf620 vcmpe.f32 s13, s11 */
/* @0xbf624 vmov s17, r3 */
/* @0xbf628 ldr r3, [r9, #0x1c] */
/* @0xbf62c vmov s10, r2 */
/* @0xbf630 vldr s26, [r3, #88] */
/* @0xbf634 vldr s28, [r3, #92] */
/* @0xbf638 vmrs APSR_nzcv, fpscr */
/* @0xbf63c vsub.f32 s12, s12, s14 */
/* @0xbf640 vcvtmi.s32.f32 s11, s13 */
/* @0xbf644 vstr s12, [sp, #16] */
/* @0xbf648 vmov s12, r4 */
/* @0xbf64c vsub.f32 s13, s13, s15 */
/* @0xbf650 vcmp.f32 s30, s19 */
/* @0xbf654 vstr s13, [sp, #20] */
/* @0xbf658 vmov s13, r0 */
/* @0xbf65c vcvtpl.s32.f32 s11, s11 */
/* @0xbf660 vmrs APSR_nzcv, fpscr */
/* @0xbf664 movne r1, #0 */
/* @0xbf668 moveq r1, #1 */
/* @0xbf66c vcvt.f32.s32 s12, s12 */
/* @0xbf670 vmov r5, s11 */
/* @0xbf674 vcvt.f32.s32 s13, s13 */
/* @0xbf678 vstr s12, [sp, #24] */
/* @0xbf67c vcmp.f32 s31, s19 */
/* @0xbf680 vstr s13, [sp, #28] */
/* @0xbf684 vmrs APSR_nzcv, fpscr */
/* @0xbf688 movne r1, #0 */
/* @0xbf68c andeq r1, r1, #1 */
/* @0xbf690 cmp r1, #0 */
/* @0xbf694 vcvt.f32.s32 s17, s17 */
/* @0xbf698 vcvt.f32.s32 s18, s10 */
/* @0xbf69c vsub.f32 s26, s26, s14 */
/* @0xbf6a0 vsub.f32 s28, s28, s15 */
/* @0xbf6a4 beq 0xbf7ac <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x288> */
/* @0xbf6a8 vldr s15, [pc, #624] */
/* @0xbf6ac vabs.f32 s14, s16 */
/* @0xbf6b0 vcmpe.f32 s14, s15 */
/* @0xbf6b4 vmrs APSR_nzcv, fpscr */
/* @0xbf6b8 bpl 0xbf7ac <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x288> */
/* @0xbf6bc cmp r6, r8 */
/* @0xbf6c0 bgt 0xbf900 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3dc> */
/* @0xbf6c4 vmov.f32 s20, #5.000000e-01 */
/* @0xbf6c8 cmp r7, r5 */
/* @0xbf6cc bgt 0xbf910 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3ec> */
/* @0xbf6d0 vmov s13, r6 */
/* @0xbf6d4 vldr s14, [sp, #24] */
/* @0xbf6d8 vldr s15, [sp, #28] */
/* @0xbf6dc mov r4, r7 */
/* @0xbf6e0 vcvt.f32.s32 s21, s13 */
/* @0xbf6e4 vsub.f32 s16, s21, s14 */
/* @0xbf6e8 vdiv.f32 s16, s16, s15 */
/* @0xbf6ec vmul.f32 s16, s16, s16 */
/* @0xbf6f0 b 0xbf700 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1dc> */
/* @0xbf6f4 add r4, r4, #1 */
/* @0xbf6f8 cmp r5, r4 */
/* @0xbf6fc blt 0xbf910 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3ec> */
/* @0xbf700 vmov s11, r4 */
/* @0xbf704 vmov.f32 s12, s16 */
/* @0xbf708 vcvt.f32.s32 s14, s11 */
/* @0xbf70c vsub.f32 s15, s14, s17 */
/* @0xbf710 vdiv.f32 s15, s15, s18 */
/* @0xbf714 vmla.f32 s12, s15, s15 */
/* @0xbf718 vcmpe.f32 s12, s19 */
/* @0xbf71c vmrs APSR_nzcv, fpscr */
/* @0xbf720 bgt 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0> */
/* @0xbf724 vsub.f32 s15, s27, s26 */
/* @0xbf728 vsub.f32 s15, s15, s20 */
/* @0xbf72c vcvt.s32.f32 s15, s15 */
/* @0xbf730 vmov r3, s15 */
/* @0xbf734 subs r3, r6, r3 */
/* @0xbf738 bmi 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0> */
/* @0xbf73c vmov s13, r3 */
/* @0xbf740 vldr s10, [sp, #16] */
/* @0xbf744 vcvt.f32.s32 s15, s13 */
/* @0xbf748 vcmpe.f32 s10, s15 */
/* @0xbf74c vmrs APSR_nzcv, fpscr */
/* @0xbf750 bls 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0> */
/* @0xbf754 vsub.f32 s15, s29, s28 */
/* @0xbf758 vsub.f32 s15, s15, s20 */
/* @0xbf75c vcvt.s32.f32 s15, s15 */
/* @0xbf760 vmov r3, s15 */
/* @0xbf764 subs r3, r4, r3 */
/* @0xbf768 bmi 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0> */
/* @0xbf76c vmov s11, r3 */
/* @0xbf770 vldr s12, [sp, #20] */
/* @0xbf774 vcvt.f32.s32 s15, s11 */
/* @0xbf778 vcmpe.f32 s12, s15 */
/* @0xbf77c vmrs APSR_nzcv, fpscr */
/* @0xbf780 bls 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0> */
/* @0xbf784 ldr r0, [r9, #0x20] */
/* @0xbf788 vmov r1, s21 */
/* @0xbf78c vmov r2, s14 */
/* @0xbf790 bl 0x28ac8c <spSkeletonBounds_containsPoint> */
/* @0xbf794 cmp r0, #0 */
/* @0xbf798 beq 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0> */
/* @0xbf79c mov r0, #1 */
/* @0xbf7a0 add sp, sp, #36 */
/* @0xbf7a4 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0xbf7a8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xbf7ac vldr s20, [pc, #368] */
/* @0xbf7b0 vnmul.f32 s15, s16, s20 */
/* @0xbf7b4 vldr s19, [pc, #364] */
/* @0xbf7b8 vdiv.f32 s15, s15, s19 */
/* @0xbf7bc vmul.f32 s16, s16, s20 */
/* @0xbf7c0 vmov r0, s15 */
/* @0xbf7c4 bl 0xb6580 <sinf@plt> */
/* @0xbf7c8 vdiv.f32 s16, s16, s19 */
/* @0xbf7cc vmov s23, r0 */
/* @0xbf7d0 vmov r0, s16 */
/* @0xbf7d4 bl 0xb658c <cosf@plt> */
/* @0xbf7d8 cmp r6, r8 */
/* @0xbf7dc vmov s24, r0 */
/* @0xbf7e0 bgt 0xbf900 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3dc> */
/* @0xbf7e4 vmov.f32 s20, #1.000000e+00 */
/* @0xbf7e8 cmp r7, r5 */
/* @0xbf7ec bgt 0xbf8f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3d0> */
/* @0xbf7f0 vmov s11, r6 */
/* @0xbf7f4 vldr s12, [sp, #24] */
/* @0xbf7f8 vldr s13, [sp, #28] */
/* @0xbf7fc mov r4, r7 */
/* @0xbf800 vcvt.f32.s32 s25, s11 */
/* @0xbf804 vsub.f32 s19, s25, s12 */
/* @0xbf808 vdiv.f32 s19, s19, s13 */
/* @0xbf80c vmul.f32 s19, s19, s19 */
/* @0xbf810 b 0xbf81c <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f8> */
/* @0xbf814 cmp r5, r4 */
/* @0xbf818 blt 0xbf8f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3d0> */
/* @0xbf81c vmov s10, r4 */
/* @0xbf820 add r4, r4, #1 */
/* @0xbf824 vmov.f32 s11, s19 */
/* @0xbf828 vcvt.f32.s32 s16, s10 */
/* @0xbf82c vsub.f32 s15, s16, s17 */
/* @0xbf830 vdiv.f32 s15, s15, s18 */
/* @0xbf834 vmla.f32 s11, s15, s15 */
/* @0xbf838 vcmpe.f32 s11, s20 */
/* @0xbf83c vmrs APSR_nzcv, fpscr */
/* @0xbf840 bgt 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0> */
/* @0xbf844 vsub.f32 s21, s16, s29 */
/* @0xbf848 vmul.f32 s15, s21, s23 */
/* @0xbf84c vsub.f32 s22, s25, s27 */
/* @0xbf850 vmla.f32 s15, s22, s24 */
/* @0xbf854 vdiv.f32 s15, s15, s30 */
/* @0xbf858 vmul.f32 s22, s23, s22 */
/* @0xbf85c vnmls.f32 s22, s24, s21 */
/* @0xbf860 vdiv.f32 s22, s22, s31 */
/* @0xbf864 vadd.f32 s15, s15, s26 */
/* @0xbf868 vcvt.f64.f32 d6, s15 */
/* @0xbf86c vmov r0, r1, d6 */
/* @0xbf870 bl 0xb6598 <floor@plt> */
/* @0xbf874 vadd.f32 s22, s22, s28 */
/* @0xbf878 vcvt.f64.f32 d5, s22 */
/* @0xbf87c vmov d7, r0, r1 */
/* @0xbf880 vmov r0, r1, d5 */
/* @0xbf884 vcvt.s32.f64 s21, d7 */
/* @0xbf888 bl 0xb6598 <floor@plt> */
/* @0xbf88c vmov r3, s21 */
/* @0xbf890 cmp r3, #0 */
/* @0xbf894 vmov d7, r0, r1 */
/* @0xbf898 blt 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0> */
/* @0xbf89c vcvt.f32.s32 s21, s21 */
/* @0xbf8a0 vldr s10, [sp, #16] */
/* @0xbf8a4 vcmpe.f32 s10, s21 */
/* @0xbf8a8 vmrs APSR_nzcv, fpscr */
/* @0xbf8ac bls 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0> */
/* @0xbf8b0 vcvt.s32.f64 s14, d7 */
/* @0xbf8b4 vmov r3, s14 */
/* @0xbf8b8 cmp r3, #0 */
/* @0xbf8bc blt 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0> */
/* @0xbf8c0 vcvt.f32.s32 s14, s14 */
/* @0xbf8c4 vldr s10, [sp, #20] */
/* @0xbf8c8 vcmpe.f32 s10, s14 */
/* @0xbf8cc vmrs APSR_nzcv, fpscr */
/* @0xbf8d0 bls 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0> */
/* @0xbf8d4 ldr r0, [r9, #0x20] */
/* @0xbf8d8 vmov r1, s25 */
/* @0xbf8dc vmov r2, s16 */
/* @0xbf8e0 bl 0x28ac8c <spSkeletonBounds_containsPoint> */
/* @0xbf8e4 cmp r0, #0 */
/* @0xbf8e8 bne 0xbf79c <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x278> */
/* @0xbf8ec cmp r5, r4 */
/* @0xbf8f0 bge 0xbf81c <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f8> */
/* @0xbf8f4 add r6, r6, #1 */
/* @0xbf8f8 cmp r8, r6 */
/* @0xbf8fc bge 0xbf7e8 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2c4> */
/* @0xbf900 mov r0, #0 */
/* @0xbf904 add sp, sp, #36 */
/* @0xbf908 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0xbf90c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xbf910 add r6, r6, #1 */
/* @0xbf914 cmp r8, r6 */
/* @0xbf918 bge 0xbf6c8 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1a4> */
/* @0xbf91c b 0xbf900 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3dc> */
/* @0xbf920 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0xbf924 ldrdmi r0, r1, [r9], #-251 */
/* @0xbf928 teqmi r4, #0 */

/* ── FUNC 0xbf92c · CSkeletonInstance::StoreAttachment(spAttachment*, spAtlas*) · size=116 · insn=29 */
/* @0xbf92c push {r3, r4, r5, r6, r7, lr} */
/* @0xbf930 mov r7, r1 */
/* @0xbf934 ldr r3, [r0, #0x10] */
/* @0xbf938 mov r4, r0 */
/* @0xbf93c ldr r5, [pc, #0x58] */
/* @0xbf940 mov r6, r2 */
/* @0xbf944 add r1, r3, #1 */
/* @0xbf948 add r0, r0, #20 */
/* @0xbf94c add r5, pc, r5 */
/* @0xbf950 movw r3, #0x6d9 */
/* @0xbf954 lsl r1, r1, #2 */
/* @0xbf958 mov r2, r5 */
/* @0xbf95c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xbf960 ldr r1, [r4, #0x10] */
/* @0xbf964 mov r2, r5 */
/* @0xbf968 movw r3, #0x6da */
/* @0xbf96c add r1, r1, #1 */
/* @0xbf970 add r0, r4, #24 */
/* @0xbf974 lsl r1, r1, #2 */
/* @0xbf978 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xbf97c ldr r3, [r4, #0x10] */
/* @0xbf980 ldr r1, [r4, #0x14] */
/* @0xbf984 add r2, r3, #1 */
/* @0xbf988 str r7, [r1, r3, lsl #2] */
/* @0xbf98c ldr r1, [r4, #0x18] */
/* @0xbf990 str r6, [r1, r3, lsl #2] */
/* @0xbf994 str r2, [r4, #0x10] */
/* @0xbf998 pop {r3, r4, r5, r6, r7, pc} */
/* @0xbf99c eoreq r0, r7, r4, ror lr */

/* ── FUNC 0xbf9a0 · CSkeletonInstance::CreateAttachment(char const*, char const*, short, int, int, float, float, float, float, float, float, float, float, float) · size=420 · insn=105 */
/* @0xbf9a0 ldr r12, [pc, #0x194] */
/* @0xbf9a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbf9a8 vpush {d8, d9, d10, d11, d12} */
/* @0xbf9ac ldr r12, [pc, r12] */
/* @0xbf9b0 mov r4, r3 */
/* @0xbf9b4 sub sp, sp, #28 */
/* @0xbf9b8 ldr r3, [r12, #0x4] */
/* @0xbf9bc mov r7, r1 */
/* @0xbf9c0 mov r9, r0 */
/* @0xbf9c4 mov r1, r2 */
/* @0xbf9c8 add r0, sp, #12 */
/* @0xbf9cc ldr r8, [sp, #0x6c] */
/* @0xbf9d0 ldr r11, [r3, r4, lsl #2] */
/* @0xbf9d4 vldr s24, [sp, #112] */
/* @0xbf9d8 ldr r10, [sp, #0x68] */
/* @0xbf9dc vldr s23, [sp, #116] */
/* @0xbf9e0 vldr s22, [sp, #120] */
/* @0xbf9e4 vldr s21, [sp, #124] */
/* @0xbf9e8 vldr s18, [sp, #128] */
/* @0xbf9ec vldr s17, [sp, #132] */
/* @0xbf9f0 vldr s20, [sp, #136] */
/* @0xbf9f4 vldr s19, [sp, #140] */
/* @0xbf9f8 vldr s16, [sp, #144] */
/* @0xbf9fc bl 0x284058 <spAtlasPage_create> */
/* @0xbfa00 ldrsh r3, [r11, #6] */
/* @0xbfa04 mov r5, #0 */
/* @0xbfa08 ldrsh r2, [r11, #4] */
/* @0xbfa0c ldr r11, [pc, #0x12c] */
/* @0xbfa10 add r11, pc, r11 */
/* @0xbfa14 str r3, [r0, #0x24] */
/* @0xbfa18 mov r6, r0 */
/* @0xbfa1c str r2, [r0, #0x20] */
/* @0xbfa20 str r4, [r0, #0x1c] */
/* @0xbfa24 str r5, [r0, #0x28] */
/* @0xbfa28 bl 0x2840d8 <spAtlasRegion_create> */
/* @0xbfa2c mov r4, r0 */
/* @0xbfa30 mov r0, r7 */
/* @0xbfa34 bl 0xb6538 <strlen@plt> */
/* @0xbfa38 movw r2, #0x494 */
/* @0xbfa3c mov r1, r11 */
/* @0xbfa40 add r0, r0, #1 */
/* @0xbfa44 bl 0x285c10 <_malloc> */
/* @0xbfa48 mov r1, r7 */
/* @0xbfa4c str r0, [r4] */
/* @0xbfa50 bl 0xb65a4 <strcpy@plt> */
/* @0xbfa54 mov r2, r11 */
/* @0xbfa58 str r5, [r4, #0x4] */
/* @0xbfa5c mov r1, #12 */
/* @0xbfa60 str r5, [r4, #0x8] */
/* @0xbfa64 movw r3, #0x4a9 */
/* @0xbfa68 str r8, [r4, #0x10] */
/* @0xbfa6c vstr s24, [r4, #20] */
/* @0xbfa70 str r5, [r4, #0x24] */
/* @0xbfa74 vstr s23, [r4, #24] */
/* @0xbfa78 str r5, [r4, #0x28] */
/* @0xbfa7c vstr s22, [r4, #28] */
/* @0xbfa80 str r8, [r4, #0x30] */
/* @0xbfa84 vstr s21, [r4, #32] */
/* @0xbfa88 str r5, [r4, #0x34] */
/* @0xbfa8c mov r0, #1 */
/* @0xbfa90 str r5, [r4, #0x38] */
/* @0xbfa94 str r5, [r4, #0x3c] */
/* @0xbfa98 str r5, [r4, #0x40] */
/* @0xbfa9c str r5, [r4, #0x44] */
/* @0xbfaa0 str r6, [r4, #0x48] */
/* @0xbfaa4 str r5, [r4, #0x4c] */
/* @0xbfaa8 str r10, [r4, #0xc] */
/* @0xbfaac str r10, [r4, #0x2c] */
/* @0xbfab0 bl 0x285c4c <_calloc> */
/* @0xbfab4 str r6, [r0] */
/* @0xbfab8 mov r8, r0 */
/* @0xbfabc str r4, [r0, #0x4] */
/* @0xbfac0 bl 0x284bb4 <spAtlasAttachmentLoader_create> */
/* @0xbfac4 ldr r1, [r9, #0x30] */
/* @0xbfac8 mov r3, r7 */
/* @0xbfacc mov r2, r5 */
/* @0xbfad0 ldr r1, [r1, #0x24] */
/* @0xbfad4 ldr r1, [r1] */
/* @0xbfad8 str r7, [sp] */
/* @0xbfadc mov r6, r0 */
/* @0xbfae0 bl 0x284d58 <spAttachmentLoader_createAttachment> */
/* @0xbfae4 vldr s14, [r4, #12] */
/* @0xbfae8 vldr s15, [r4, #16] */
/* @0xbfaec vcvt.f32.s32 s14, s14 */
/* @0xbfaf0 vcvt.f32.s32 s15, s15 */
/* @0xbfaf4 vstr s14, [r0, #40] */
/* @0xbfaf8 vstr s15, [r0, #44] */
/* @0xbfafc mov r5, r0 */
/* @0xbfb00 vstr s20, [r0, #28] */
/* @0xbfb04 vstr s19, [r0, #32] */
/* @0xbfb08 vstr s18, [r0, #20] */
/* @0xbfb0c vstr s17, [r0, #24] */
/* @0xbfb10 vstr s16, [r0, #36] */
/* @0xbfb14 bl 0x289040 <spRegionAttachment_updateOffset> */
/* @0xbfb18 mov r0, r9 */
/* @0xbfb1c mov r1, r5 */
/* @0xbfb20 mov r2, r8 */
/* @0xbfb24 bl 0xbf92c <_ZN17CSkeletonInstance15StoreAttachmentEP12spAttachmentP7spAtlas> */
/* @0xbfb28 mov r0, r6 */
/* @0xbfb2c bl 0x284d38 <spAttachmentLoader_dispose> */
/* @0xbfb30 add sp, sp, #28 */
/* @0xbfb34 vpop {d8, d9, d10, d11, d12} */
/* @0xbfb38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xbfb3c eorseq sp, r2, r0, ror pc */
/* @0xbfb40 .word 0x00270db0 */

/* ── FUNC 0xbfb44 · CSkeletonInstance::CreateAttachment(char const*, CSprite*, int, float, float, float, float, float) · size=328 · insn=82 */
/* @0xbfb44 push {r4, r5, r6, r7, lr} */
/* @0xbfb48 mov r4, r2 */
/* @0xbfb4c ldr r5, [r2, #0x54] */
/* @0xbfb50 sub sp, sp, #52 */
/* @0xbfb54 mov r7, r0 */
/* @0xbfb58 mov r6, r1 */
/* @0xbfb5c cmp r5, #0 */
/* @0xbfb60 beq 0xbfc54 <_ZN17CSkeletonInstance16CreateAttachmentEPKcP7CSpriteifffff+0x110> */
/* @0xbfb64 ldr r1, [r2, #0x18] */
/* @0xbfb68 mov r0, r3 */
/* @0xbfb6c bl 0x318dec <__aeabi_idivmod> */
/* @0xbfb70 ldr r3, [pc, #0x108] */
/* @0xbfb74 mov r0, r7 */
/* @0xbfb78 ldr r2, [r4, #0x5c] */
/* @0xbfb7c ldr r3, [pc, r3] */
/* @0xbfb80 ldr r7, [r3, #0x4] */
/* @0xbfb84 ldr r12, [r5, r1, lsl #2] */
/* @0xbfb88 mov r1, r6 */
/* @0xbfb8c ldrh r3, [r12] */
/* @0xbfb90 ldrsh r4, [r12, #4] */
/* @0xbfb94 ldrh r6, [r12, #2] */
/* @0xbfb98 sxth r3, r3 */
/* @0xbfb9c ldrsh lr, [r12, #6] */
/* @0xbfba0 add r5, r3, r4 */
/* @0xbfba4 sxth r6, r6 */
/* @0xbfba8 vmov s9, r3 */
/* @0xbfbac vmov s11, r5 */
/* @0xbfbb0 add r5, r6, lr */
/* @0xbfbb4 vcvt.f32.s32 s10, s9 */
/* @0xbfbb8 ldrsh r3, [r12, #20] */
/* @0xbfbbc vmov s9, r6 */
/* @0xbfbc0 vmov s12, r5 */
/* @0xbfbc4 ldr r5, [r7, r3, lsl #2] */
/* @0xbfbc8 vldr s14, [r5, #8] */
/* @0xbfbcc vldr s15, [r5, #12] */
/* @0xbfbd0 stm sp, {r4, lr} */
/* @0xbfbd4 vcvt.f32.s32 s12, s12 */
/* @0xbfbd8 vcvt.f32.s32 s13, s9 */
/* @0xbfbdc vldr s9, [sp, #72] */
/* @0xbfbe0 vcvt.f32.s32 s11, s11 */
/* @0xbfbe4 vmul.f32 s13, s13, s15 */
/* @0xbfbe8 vmul.f32 s11, s14, s11 */
/* @0xbfbec vstr s13, [sp, #12] */
/* @0xbfbf0 vmul.f32 s14, s10, s14 */
/* @0xbfbf4 vstr s11, [sp, #16] */
/* @0xbfbf8 vmul.f32 s15, s15, s12 */
/* @0xbfbfc vstr s14, [sp, #8] */
/* @0xbfc00 vldr s14, [sp, #80] */
/* @0xbfc04 vstr s15, [sp, #20] */
/* @0xbfc08 ldrsh r5, [r12, #8] */
/* @0xbfc0c vmov s15, r5 */
/* @0xbfc10 vcvt.f32.s32 s15, s15 */
/* @0xbfc14 vsub.f32 s15, s9, s15 */
/* @0xbfc18 vldr s9, [sp, #84] */
/* @0xbfc1c vstr s15, [sp, #24] */
/* @0xbfc20 ldrsh r12, [r12, #10] */
/* @0xbfc24 vstr s9, [sp, #36] */
/* @0xbfc28 vldr s9, [sp, #76] */
/* @0xbfc2c vstr s14, [sp, #32] */
/* @0xbfc30 vldr s14, [sp, #88] */
/* @0xbfc34 vmov s15, r12 */
/* @0xbfc38 vstr s14, [sp, #40] */
/* @0xbfc3c vcvt.f32.s32 s15, s15 */
/* @0xbfc40 vsub.f32 s15, s9, s15 */
/* @0xbfc44 vstr s15, [sp, #28] */
/* @0xbfc48 bl 0xbf9a0 <_ZN17CSkeletonInstance16CreateAttachmentEPKcS1_siifffffffff> */
/* @0xbfc4c add sp, sp, #52 */
/* @0xbfc50 pop {r4, r5, r6, r7, pc} */
/* @0xbfc54 ldr r3, [pc, #0x28] */
/* @0xbfc58 ldr r1, [pc, #0x28] */
/* @0xbfc5c ldr r3, [pc, r3] */
/* @0xbfc60 ldr r2, [r2, #0x5c] */
/* @0xbfc64 add r1, pc, r1 */
/* @0xbfc68 ldr r0, [r3] */
/* @0xbfc6c ldr r3, [r0] */
/* @0xbfc70 ldr r3, [r3, #0xc] */
/* @0xbfc74 blx r3 */
/* @0xbfc78 add sp, sp, #52 */
/* @0xbfc7c pop {r4, r5, r6, r7, pc} */
/* @0xbfc80 eorseq sp, r2, r0, lsr #27 */
/* @0xbfc84 eorseq sp, r2, r4, ror #25 */
/* @0xbfc88 eoreq r0, r7, r12, asr #23 */

/* ── FUNC 0xbfc8c · CSkeletonInstance::CloneAttachment(spAttachment*, spAtlas*) · size=140 · insn=35 */
/* @0xbfc8c ldr r3, [r1, #0x4] */
/* @0xbfc90 push {r4, r5, r6, r7, r8, lr} */
/* @0xbfc94 cmp r3, #0 */
/* @0xbfc98 sub sp, sp, #48 */
/* @0xbfc9c bne 0xbfd10 <_ZN17CSkeletonInstance15CloneAttachmentEP12spAttachmentP7spAtlas+0x84> */
/* @0xbfca0 ldr r12, [r2, #0x4] */
/* @0xbfca4 ldr r8, [r1, #0x14] */
/* @0xbfca8 ldr r7, [r1, #0x18] */
/* @0xbfcac ldr r3, [r12, #0x48] */
/* @0xbfcb0 ldr lr, [r12, #0xc] */
/* @0xbfcb4 ldr r6, [r1, #0x1c] */
/* @0xbfcb8 ldr r5, [r1, #0x20] */
/* @0xbfcbc ldr r4, [r1, #0x24] */
/* @0xbfcc0 ldr r2, [r3, #0x4] */
/* @0xbfcc4 ldr r1, [r12] */
/* @0xbfcc8 ldrsh r3, [r3, #28] */
/* @0xbfccc str lr, [sp] */
/* @0xbfcd0 ldr lr, [r12, #0x10] */
/* @0xbfcd4 str lr, [sp, #0x4] */
/* @0xbfcd8 ldr lr, [r12, #0x14] */
/* @0xbfcdc str lr, [sp, #0x8] */
/* @0xbfce0 ldr lr, [r12, #0x18] */
/* @0xbfce4 str lr, [sp, #0xc] */
/* @0xbfce8 ldr lr, [r12, #0x1c] */
/* @0xbfcec str lr, [sp, #0x10] */
/* @0xbfcf0 ldr r12, [r12, #0x20] */
/* @0xbfcf4 str r8, [sp, #0x18] */
/* @0xbfcf8 str r7, [sp, #0x1c] */
/* @0xbfcfc str r12, [sp, #0x14] */
/* @0xbfd00 str r6, [sp, #0x20] */
/* @0xbfd04 str r5, [sp, #0x24] */
/* @0xbfd08 str r4, [sp, #0x28] */
/* @0xbfd0c bl 0xbf9a0 <_ZN17CSkeletonInstance16CreateAttachmentEPKcS1_siifffffffff> */
/* @0xbfd10 add sp, sp, #48 */
/* @0xbfd14 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0xbfd18 · CSkeletonInstance::GetBoneData(char const*, int) · size=400 · insn=100 */
/* @0xbfd18 push {r4, r5, r6, r7, lr} */
/* @0xbfd1c sub sp, sp, #20 */
/* @0xbfd20 ldr r0, [r0, #0x1c] */
/* @0xbfd24 mov r4, r2 */
/* @0xbfd28 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0xbfd2c subs r5, r0, #0 */
/* @0xbfd30 moveq r0, r5 */
/* @0xbfd34 beq 0xbfe6c <_ZN17CSkeletonInstance11GetBoneDataEPKci+0x154> */
/* @0xbfd38 add r7, sp, #12 */
/* @0xbfd3c mov r0, r7 */
/* @0xbfd40 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xbfd44 ldr r3, [pc, #0x13c] */
/* @0xbfd48 ldr r3, [pc, r3] */
/* @0xbfd4c ldr r3, [r3, #0x4] */
/* @0xbfd50 ldr r4, [r3, r4, lsl #2] */
/* @0xbfd54 cmp r4, #0 */
/* @0xbfd58 beq 0xbfe74 <_ZN17CSkeletonInstance11GetBoneDataEPKci+0x15c> */
/* @0xbfd5c ldr r3, [r5] */
/* @0xbfd60 vldr s15, [r3, #12] */
/* @0xbfd64 vcvt.f64.f32 d6, s15 */
/* @0xbfd68 ldr r1, [pc, #0x11c] */
/* @0xbfd6c mov r6, #0 */
/* @0xbfd70 mov r0, r4 */
/* @0xbfd74 add r1, pc, r1 */
/* @0xbfd78 str r6, [sp] */
/* @0xbfd7c vmov r2, r3, d6 */
/* @0xbfd80 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbfd84 ldr r3, [r5] */
/* @0xbfd88 vldr s15, [r3, #16] */
/* @0xbfd8c vcvt.f64.f32 d6, s15 */
/* @0xbfd90 ldr r1, [pc, #0xf8] */
/* @0xbfd94 mov r0, r4 */
/* @0xbfd98 str r6, [sp] */
/* @0xbfd9c add r1, pc, r1 */
/* @0xbfda0 vmov r2, r3, d6 */
/* @0xbfda4 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbfda8 ldr r3, [r5] */
/* @0xbfdac vldr s15, [r3, #20] */
/* @0xbfdb0 vcvt.f64.f32 d6, s15 */
/* @0xbfdb4 ldr r1, [pc, #0xd8] */
/* @0xbfdb8 mov r0, r4 */
/* @0xbfdbc str r6, [sp] */
/* @0xbfdc0 add r1, pc, r1 */
/* @0xbfdc4 vmov r2, r3, d6 */
/* @0xbfdc8 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbfdcc ldr r3, [r5] */
/* @0xbfdd0 vldr s15, [r3, #24] */
/* @0xbfdd4 vcvt.f64.f32 d6, s15 */
/* @0xbfdd8 ldr r1, [pc, #0xb8] */
/* @0xbfddc mov r0, r4 */
/* @0xbfde0 str r6, [sp] */
/* @0xbfde4 add r1, pc, r1 */
/* @0xbfde8 vmov r2, r3, d6 */
/* @0xbfdec bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbfdf0 ldr r3, [r5] */
/* @0xbfdf4 vldr s15, [r3, #28] */
/* @0xbfdf8 vcvt.f64.f32 d6, s15 */
/* @0xbfdfc ldr r1, [pc, #0x98] */
/* @0xbfe00 mov r0, r4 */
/* @0xbfe04 str r6, [sp] */
/* @0xbfe08 add r1, pc, r1 */
/* @0xbfe0c vmov r2, r3, d6 */
/* @0xbfe10 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbfe14 ldr r3, [r5] */
/* @0xbfe18 vldr s15, [r3, #32] */
/* @0xbfe1c vcvt.f64.f32 d6, s15 */
/* @0xbfe20 ldr r1, [pc, #0x78] */
/* @0xbfe24 mov r0, r4 */
/* @0xbfe28 str r6, [sp] */
/* @0xbfe2c add r1, pc, r1 */
/* @0xbfe30 vmov r2, r3, d6 */
/* @0xbfe34 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbfe38 ldr r12, [r5] */
/* @0xbfe3c ldr r1, [pc, #0x60] */
/* @0xbfe40 mov r2, #0 */
/* @0xbfe44 mov r3, #0 */
/* @0xbfe48 mov r0, r4 */
/* @0xbfe4c ldr r12, [r12, #0x8] */
/* @0xbfe50 add r1, pc, r1 */
/* @0xbfe54 ldr r12, [r12, #0x4] */
/* @0xbfe58 str r12, [sp] */
/* @0xbfe5c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbfe60 mov r0, r7 */
/* @0xbfe64 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xbfe68 mov r0, #1 */
/* @0xbfe6c add sp, sp, #20 */
/* @0xbfe70 pop {r4, r5, r6, r7, pc} */
/* @0xbfe74 mov r0, r7 */
/* @0xbfe78 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xbfe7c mov r0, r4 */
/* @0xbfe80 add sp, sp, #20 */
/* @0xbfe84 pop {r4, r5, r6, r7, pc} */
/* @0xbfe88 ldrshteq sp, [r2], -r4 */
/* @0xbfe8c .word 0x00270af8 */
/* @0xbfe90 .word 0x00270ad8 */
/* @0xbfe94 .word 0x00270ab8 */
/* @0xbfe98 mlaeq r7, r8, r10, r0 */
/* @0xbfe9c eoreq r0, r7, r12, ror r10 */
/* @0xbfea0 eoreq r0, r7, r0, ror #20 */
/* @0xbfea4 eoreq r0, r7, r4, asr #20 */

/* ── FUNC 0xbfea8 · CSkeletonInstance::GetBoneState(char const*, int) · size=712 · insn=178 */
/* @0xbfea8 push {r4, r5, r6, r7, lr} */
/* @0xbfeac sub sp, sp, #20 */
/* @0xbfeb0 ldr r0, [r0, #0x1c] */
/* @0xbfeb4 mov r4, r2 */
/* @0xbfeb8 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0xbfebc subs r5, r0, #0 */
/* @0xbfec0 moveq r0, r5 */
/* @0xbfec4 beq 0xc0114 <_ZN17CSkeletonInstance12GetBoneStateEPKci+0x26c> */
/* @0xbfec8 add r7, sp, #12 */
/* @0xbfecc mov r0, r7 */
/* @0xbfed0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xbfed4 ldr r3, [pc, #0x254] */
/* @0xbfed8 ldr r3, [pc, r3] */
/* @0xbfedc ldr r3, [r3, #0x4] */
/* @0xbfee0 ldr r4, [r3, r4, lsl #2] */
/* @0xbfee4 cmp r4, #0 */
/* @0xbfee8 beq 0xc011c <_ZN17CSkeletonInstance12GetBoneStateEPKci+0x274> */
/* @0xbfeec vldr s15, [r5, #20] */
/* @0xbfef0 vcvt.f64.f32 d6, s15 */
/* @0xbfef4 ldr r1, [pc, #0x238] */
/* @0xbfef8 mov r6, #0 */
/* @0xbfefc mov r0, r4 */
/* @0xbff00 str r6, [sp] */
/* @0xbff04 add r1, pc, r1 */
/* @0xbff08 vmov r2, r3, d6 */
/* @0xbff0c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbff10 vldr s15, [r5, #24] */
/* @0xbff14 vcvt.f64.f32 d6, s15 */
/* @0xbff18 ldr r1, [pc, #0x218] */
/* @0xbff1c mov r0, r4 */
/* @0xbff20 str r6, [sp] */
/* @0xbff24 add r1, pc, r1 */
/* @0xbff28 vmov r2, r3, d6 */
/* @0xbff2c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbff30 vldr s15, [r5, #28] */
/* @0xbff34 vcvt.f64.f32 d6, s15 */
/* @0xbff38 ldr r1, [pc, #0x1fc] */
/* @0xbff3c mov r0, r4 */
/* @0xbff40 str r6, [sp] */
/* @0xbff44 add r1, pc, r1 */
/* @0xbff48 vmov r2, r3, d6 */
/* @0xbff4c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbff50 vldr s15, [r5, #32] */
/* @0xbff54 vcvt.f64.f32 d6, s15 */
/* @0xbff58 ldr r1, [pc, #0x1e0] */
/* @0xbff5c mov r0, r4 */
/* @0xbff60 str r6, [sp] */
/* @0xbff64 add r1, pc, r1 */
/* @0xbff68 vmov r2, r3, d6 */
/* @0xbff6c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbff70 vldr s15, [r5, #36] */
/* @0xbff74 vcvt.f64.f32 d6, s15 */
/* @0xbff78 ldr r1, [pc, #0x1c4] */
/* @0xbff7c mov r0, r4 */
/* @0xbff80 str r6, [sp] */
/* @0xbff84 add r1, pc, r1 */
/* @0xbff88 vmov r2, r3, d6 */
/* @0xbff8c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbff90 vldr s15, [r5, #60] */
/* @0xbff94 vcvt.f64.f32 d6, s15 */
/* @0xbff98 ldr r1, [pc, #0x1a8] */
/* @0xbff9c mov r0, r4 */
/* @0xbffa0 str r6, [sp] */
/* @0xbffa4 add r1, pc, r1 */
/* @0xbffa8 vmov r2, r3, d6 */
/* @0xbffac bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbffb0 vldr s15, [r5, #72] */
/* @0xbffb4 vcvt.f64.f32 d6, s15 */
/* @0xbffb8 ldr r1, [pc, #0x18c] */
/* @0xbffbc mov r0, r4 */
/* @0xbffc0 str r6, [sp] */
/* @0xbffc4 add r1, pc, r1 */
/* @0xbffc8 vmov r2, r3, d6 */
/* @0xbffcc bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbffd0 mov r0, r5 */
/* @0xbffd4 bl 0x285410 <spBone_getWorldRotationX> */
/* @0xbffd8 ldr r1, [pc, #0x170] */
/* @0xbffdc str r6, [sp] */
/* @0xbffe0 add r1, pc, r1 */
/* @0xbffe4 vmov s13, r0 */
/* @0xbffe8 mov r0, r4 */
/* @0xbffec vcvt.f64.f32 d7, s13 */
/* @0xbfff0 vmov r2, r3, d7 */
/* @0xbfff4 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xbfff8 mov r0, r5 */
/* @0xbfffc bl 0x28544c <spBone_getWorldRotationY> */
/* @0xc0000 ldr r1, [pc, #0x14c] */
/* @0xc0004 str r6, [sp] */
/* @0xc0008 add r1, pc, r1 */
/* @0xc000c vmov s12, r0 */
/* @0xc0010 mov r0, r4 */
/* @0xc0014 vcvt.f64.f32 d7, s12 */
/* @0xc0018 vmov r2, r3, d7 */
/* @0xc001c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xc0020 mov r0, r5 */
/* @0xc0024 bl 0x285488 <spBone_getWorldScaleX> */
/* @0xc0028 ldr r1, [pc, #0x128] */
/* @0xc002c str r6, [sp] */
/* @0xc0030 add r1, pc, r1 */
/* @0xc0034 vmov s13, r0 */
/* @0xc0038 mov r0, r4 */
/* @0xc003c vcvt.f64.f32 d7, s13 */
/* @0xc0040 vmov r2, r3, d7 */
/* @0xc0044 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xc0048 mov r0, r5 */
/* @0xc004c bl 0x2854d8 <spBone_getWorldScaleY> */
/* @0xc0050 ldr r1, [pc, #0x104] */
/* @0xc0054 str r6, [sp] */
/* @0xc0058 add r1, pc, r1 */
/* @0xc005c vmov s12, r0 */
/* @0xc0060 mov r0, r4 */
/* @0xc0064 vcvt.f64.f32 d7, s12 */
/* @0xc0068 vmov r2, r3, d7 */
/* @0xc006c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xc0070 vldr s15, [r5, #48] */
/* @0xc0074 vcvt.f64.f32 d6, s15 */
/* @0xc0078 ldr r1, [pc, #0xe0] */
/* @0xc007c mov r0, r4 */
/* @0xc0080 str r6, [sp] */
/* @0xc0084 add r1, pc, r1 */
/* @0xc0088 vmov r2, r3, d6 */
/* @0xc008c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xc0090 vldr s15, [r5, #76] */
/* @0xc0094 vcvt.f64.f32 d6, s15 */
/* @0xc0098 ldr r1, [pc, #0xc4] */
/* @0xc009c mov r0, r4 */
/* @0xc00a0 str r6, [sp] */
/* @0xc00a4 add r1, pc, r1 */
/* @0xc00a8 vmov r2, r3, d6 */
/* @0xc00ac bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xc00b0 vldr s15, [r5, #80] */
/* @0xc00b4 vcvt.f64.f32 d6, s15 */
/* @0xc00b8 ldr r1, [pc, #0xa8] */
/* @0xc00bc mov r0, r4 */
/* @0xc00c0 str r6, [sp] */
/* @0xc00c4 add r1, pc, r1 */
/* @0xc00c8 vmov r2, r3, d6 */
/* @0xc00cc bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xc00d0 ldr r3, [r5, #0x8] */
/* @0xc00d4 cmp r3, r6 */
/* @0xc00d8 beq 0xc0108 <_ZN17CSkeletonInstance12GetBoneStateEPKci+0x260> */
/* @0xc00dc ldr r3, [r3] */
/* @0xc00e0 cmp r3, r6 */
/* @0xc00e4 beq 0xc0108 <_ZN17CSkeletonInstance12GetBoneStateEPKci+0x260> */
/* @0xc00e8 ldr r12, [r3, #0x4] */
/* @0xc00ec mov r0, r4 */
/* @0xc00f0 ldr r1, [pc, #0x74] */
/* @0xc00f4 mov r2, #0 */
/* @0xc00f8 mov r3, #0 */
/* @0xc00fc add r1, pc, r1 */
/* @0xc0100 str r12, [sp] */
/* @0xc0104 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0xc0108 mov r0, r7 */
/* @0xc010c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xc0110 mov r0, #1 */
/* @0xc0114 add sp, sp, #20 */
/* @0xc0118 pop {r4, r5, r6, r7, pc} */
/* @0xc011c mov r0, r7 */
/* @0xc0120 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xc0124 mov r0, r4 */
/* @0xc0128 add sp, sp, #20 */
/* @0xc012c pop {r4, r5, r6, r7, pc} */
/* @0xc0130 eorseq sp, r2, r4, ror #20 */
/* @0xc0134 eoreq r0, r7, r0, ror r9 */
/* @0xc0138 eoreq r0, r7, r4, asr r9 */
/* @0xc013c eoreq r0, r7, r8, lsr r9 */
/* @0xc0140 eoreq r0, r7, r0, lsr #18 */
/* @0xc0144 eoreq r0, r7, r8, lsl #18 */
/* @0xc0148 .word 0x002708f8 */
/* @0xc014c eoreq r0, r7, r0, ror #17 */
/* @0xc0150 eoreq r0, r7, r12, asr #17 */
/* @0xc0154 .word 0x002708b0 */
/* @0xc0158 mlaeq r7, r4, r8, r0 */
/* @0xc015c eoreq r0, r7, r8, ror r8 */
/* @0xc0160 eoreq r0, r7, r8, asr r8 */
/* @0xc0164 eoreq r0, r7, r8, asr #16 */
/* @0xc0168 eoreq r0, r7, r4, lsr r8 */
/* @0xc016c mlaeq r7, r8, r7, r0 */

/* ── FUNC 0xc0170 · CSkeletonInstance::GetSkin() const · size=64 · insn=16 */
/* @0xc0170 ldr r3, [r0, #0x1c] */
/* @0xc0174 cmp r3, #0 */
/* @0xc0178 beq 0xc0190 <_ZNK17CSkeletonInstance7GetSkinEv+0x20> */
/* @0xc017c ldr r3, [r3, #0x38] */
/* @0xc0180 cmp r3, #0 */
/* @0xc0184 beq 0xc019c <_ZNK17CSkeletonInstance7GetSkinEv+0x2c> */
/* @0xc0188 ldr r0, [r3] */
/* @0xc018c bx lr */
/* @0xc0190 ldr r0, [pc, #0x10] */
/* @0xc0194 add r0, pc, r0 */
/* @0xc0198 bx lr */
/* @0xc019c ldr r0, [pc, #0x8] */
/* @0xc01a0 add r0, pc, r0 */
/* @0xc01a4 bx lr */
/* @0xc01a8 eoreq lr, r6, r2, lsr #19 */
/* @0xc01ac mlaeq r6, r6, r9, lr */

/* ── FUNC 0xc01b0 · CSkeletonInstance::GetAnimation(int) const · size=148 · insn=37 */
/* @0xc01b0 cmp r1, #0 */
/* @0xc01b4 blt 0xc0200 <_ZNK17CSkeletonInstance12GetAnimationEi+0x50> */
/* @0xc01b8 ldr r3, [r0, #0x28] */
/* @0xc01bc cmp r3, #0 */
/* @0xc01c0 beq 0xc020c <_ZNK17CSkeletonInstance12GetAnimationEi+0x5c> */
/* @0xc01c4 ldr r2, [r3, #0xc] */
/* @0xc01c8 cmp r1, r2 */
/* @0xc01cc bge 0xc01f4 <_ZNK17CSkeletonInstance12GetAnimationEi+0x44> */
/* @0xc01d0 ldr r3, [r3, #0x10] */
/* @0xc01d4 ldr r3, [r3, r1, lsl #2] */
/* @0xc01d8 cmp r3, #0 */
/* @0xc01dc beq 0xc0218 <_ZNK17CSkeletonInstance12GetAnimationEi+0x68> */
/* @0xc01e0 ldr r3, [r3, #0xc] */
/* @0xc01e4 cmp r3, #0 */
/* @0xc01e8 beq 0xc0224 <_ZNK17CSkeletonInstance12GetAnimationEi+0x74> */
/* @0xc01ec ldr r0, [r3] */
/* @0xc01f0 bx lr */
/* @0xc01f4 ldr r0, [pc, #0x34] */
/* @0xc01f8 add r0, pc, r0 */
/* @0xc01fc bx lr */
/* @0xc0200 ldr r0, [pc, #0x2c] */
/* @0xc0204 add r0, pc, r0 */
/* @0xc0208 bx lr */
/* @0xc020c ldr r0, [pc, #0x24] */
/* @0xc0210 add r0, pc, r0 */
/* @0xc0214 bx lr */
/* @0xc0218 ldr r0, [pc, #0x1c] */
/* @0xc021c add r0, pc, r0 */
/* @0xc0220 bx lr */
/* @0xc0224 ldr r0, [pc, #0x14] */
/* @0xc0228 add r0, pc, r0 */
/* @0xc022c bx lr */
/* @0xc0230 eoreq lr, r6, lr, lsr r9 */
/* @0xc0234 eoreq lr, r6, r2, lsr r9 */
/* @0xc0238 eoreq lr, r6, r6, lsr #18 */
/* @0xc023c eoreq lr, r6, r10, lsl r9 */
/* @0xc0240 eoreq lr, r6, lr, lsl #18 */

/* ── FUNC 0xc0244 · CSkeletonSprite::Draw(char const*, char const*, int, float, float, float, float, float, unsigned int, float, CInstance*) · size=376 · insn=94 */
/* @0xc0244 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc0248 vpush {d8, d9} */
/* @0xc024c sub sp, sp, #28 */
/* @0xc0250 vldr s16, [sp, #88] */
/* @0xc0254 mov r8, r3 */
/* @0xc0258 mov r7, r0 */
/* @0xc025c ldr r3, [sp, #0x64] */
/* @0xc0260 mov r0, #1 */
/* @0xc0264 ldr r4, [sp, #0x6c] */
/* @0xc0268 mov r5, r1 */
/* @0xc026c mov r6, r2 */
/* @0xc0270 ldr r9, [sp, #0x50] */
/* @0xc0274 ldr r10, [sp, #0x54] */
/* @0xc0278 vldr s17, [sp, #92] */
/* @0xc027c vldr s18, [sp, #96] */
/* @0xc0280 str r3, [sp, #0x10] */
/* @0xc0284 ldr r11, [sp, #0x68] */
/* @0xc0288 bl 0x284ed8 <spBone_setYDown> */
/* @0xc028c cmp r4, #0 */
/* @0xc0290 beq 0xc0368 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x124> */
/* @0xc0294 mov r0, r4 */
/* @0xc0298 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0xc029c cmp r0, #0 */
/* @0xc02a0 beq 0xc0368 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x124> */
/* @0xc02a4 mov r0, r4 */
/* @0xc02a8 mov r3, #0 */
/* @0xc02ac str r3, [sp, #0x14] */
/* @0xc02b0 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0xc02b4 cmp r5, #0 */
/* @0xc02b8 mov r4, r0 */
/* @0xc02bc beq 0xc038c <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x148> */
/* @0xc02c0 mov r1, #0 */
/* @0xc02c4 mov r0, r4 */
/* @0xc02c8 bl 0xc01b0 <_ZNK17CSkeletonInstance12GetAnimationEi> */
/* @0xc02cc mov r1, r5 */
/* @0xc02d0 bl 0xb6574 <strcmp@plt> */
/* @0xc02d4 cmp r0, #0 */
/* @0xc02d8 bne 0xc038c <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x148> */
/* @0xc02dc cmp r6, #0 */
/* @0xc02e0 beq 0xc03a0 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x15c> */
/* @0xc02e4 mov r0, r4 */
/* @0xc02e8 bl 0xc0170 <_ZNK17CSkeletonInstance7GetSkinEv> */
/* @0xc02ec mov r1, r6 */
/* @0xc02f0 bl 0xb6574 <strcmp@plt> */
/* @0xc02f4 cmp r0, #0 */
/* @0xc02f8 bne 0xc03a0 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x15c> */
/* @0xc02fc mov r1, r8 */
/* @0xc0300 mov r12, #0 */
/* @0xc0304 vstr s16, [sp] */
/* @0xc0308 vstr s17, [sp, #4] */
/* @0xc030c vstr s18, [sp, #8] */
/* @0xc0310 mov r2, r9 */
/* @0xc0314 mov r3, r10 */
/* @0xc0318 mov r0, r4 */
/* @0xc031c str r12, [sp, #0xc] */
/* @0xc0320 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xc0324 ldr r1, [r4, #0x1c] */
/* @0xc0328 cmp r1, #0 */
/* @0xc032c beq 0xc0340 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0xfc> */
/* @0xc0330 mov r0, r7 */
/* @0xc0334 ldr r2, [sp, #0x10] */
/* @0xc0338 mov r3, r11 */
/* @0xc033c bl 0xbe054 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf> */
/* @0xc0340 ldr r3, [sp, #0x14] */
/* @0xc0344 cmp r3, #0 */
/* @0xc0348 beq 0xc03b0 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x16c> */
/* @0xc034c mov r0, r4 */
/* @0xc0350 bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> */
/* @0xc0354 mov r0, r4 */
/* @0xc0358 add sp, sp, #28 */
/* @0xc035c vpop {d8, d9} */
/* @0xc0360 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc0364 b 0x27d1d0 <_ZdlPv> */
/* @0xc0368 mov r0, #52 */
/* @0xc036c mov r3, #1 */
/* @0xc0370 str r3, [sp, #0x14] */
/* @0xc0374 bl 0x27c524 <_Znwj> */
/* @0xc0378 mov r1, r7 */
/* @0xc037c mov r4, r0 */
/* @0xc0380 bl 0xbe67c <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite> */
/* @0xc0384 cmp r5, #0 */
/* @0xc0388 bne 0xc02c0 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x7c> */
/* @0xc038c mov r1, r5 */
/* @0xc0390 mov r0, r4 */
/* @0xc0394 bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc> */
/* @0xc0398 cmp r6, #0 */
/* @0xc039c bne 0xc02e4 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0xa0> */
/* @0xc03a0 mov r1, r6 */
/* @0xc03a4 mov r0, r4 */
/* @0xc03a8 bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc> */
/* @0xc03ac b 0xc02fc <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0xb8> */
/* @0xc03b0 add sp, sp, #28 */
/* @0xc03b4 vpop {d8, d9} */
/* @0xc03b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xc03bc · CSkeletonSprite::Draw(int, float, float, float, float, float, unsigned int, float) · size=284 · insn=71 */
/* @0xc03bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc03c0 vpush {d8, d9} */
/* @0xc03c4 mov r5, r0 */
/* @0xc03c8 ldr r4, [pc, #0x104] */
/* @0xc03cc sub sp, sp, #36 */
/* @0xc03d0 mov r6, r1 */
/* @0xc03d4 mov r10, r2 */
/* @0xc03d8 ldr r4, [pc, r4] */
/* @0xc03dc mov r9, r3 */
/* @0xc03e0 vldr s18, [sp, #88] */
/* @0xc03e4 vldr s17, [sp, #92] */
/* @0xc03e8 ldr r0, [r4] */
/* @0xc03ec vldr s16, [sp, #96] */
/* @0xc03f0 ldr r8, [sp, #0x64] */
/* @0xc03f4 cmp r0, #0 */
/* @0xc03f8 ldr r7, [sp, #0x68] */
/* @0xc03fc beq 0xc047c <_ZN15CSkeletonSprite4DrawEifffffjf+0xc0> */
/* @0xc0400 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0xc0404 cmp r0, #0 */
/* @0xc0408 beq 0xc047c <_ZN15CSkeletonSprite4DrawEifffffjf+0xc0> */
/* @0xc040c mov r0, #1 */
/* @0xc0410 bl 0x284ed8 <spBone_setYDown> */
/* @0xc0414 ldr r0, [r4] */
/* @0xc0418 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0xc041c ldr r3, [r0, #0x1c] */
/* @0xc0420 mov r11, r0 */
/* @0xc0424 cmp r3, #0 */
/* @0xc0428 beq 0xc0470 <_ZN15CSkeletonSprite4DrawEifffffjf+0xb4> */
/* @0xc042c vstr s18, [sp] */
/* @0xc0430 vstr s17, [sp, #4] */
/* @0xc0434 vstr s16, [sp, #8] */
/* @0xc0438 ldr r12, [r4] */
/* @0xc043c mov r1, r6 */
/* @0xc0440 mov r2, r10 */
/* @0xc0444 mov r3, r9 */
/* @0xc0448 str r12, [sp, #0xc] */
/* @0xc044c bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xc0450 mov r3, r7 */
/* @0xc0454 mov r0, r5 */
/* @0xc0458 mov r2, r8 */
/* @0xc045c ldr r1, [r11, #0x1c] */
/* @0xc0460 bl 0xbe054 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf> */
/* @0xc0464 ldrb r3, [r11, #0x4] */
/* @0xc0468 cmp r3, #0 */
/* @0xc046c bne 0xc04bc <_ZN15CSkeletonSprite4DrawEifffffjf+0x100> */
/* @0xc0470 add sp, sp, #36 */
/* @0xc0474 vpop {d8, d9} */
/* @0xc0478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc047c mov r2, #0 */
/* @0xc0480 str r10, [sp] */
/* @0xc0484 mov r1, r2 */
/* @0xc0488 str r9, [sp, #0x4] */
/* @0xc048c vstr s18, [sp, #8] */
/* @0xc0490 vstr s17, [sp, #12] */
/* @0xc0494 vstr s16, [sp, #16] */
/* @0xc0498 str r8, [sp, #0x14] */
/* @0xc049c str r7, [sp, #0x18] */
/* @0xc04a0 mov r0, r5 */
/* @0xc04a4 mov r3, r6 */
/* @0xc04a8 str r2, [sp, #0x1c] */
/* @0xc04ac bl 0xc0244 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance> */
/* @0xc04b0 add sp, sp, #36 */
/* @0xc04b4 vpop {d8, d9} */
/* @0xc04b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc04bc mov r0, r5 */
/* @0xc04c0 ldr r1, [r11, #0x20] */
/* @0xc04c4 add sp, sp, #36 */
/* @0xc04c8 vpop {d8, d9} */
/* @0xc04cc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc04d0 b 0xbdd30 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds> */
/* @0xc04d4 eorseq sp, r2, r12, asr r5 */

/* ── FUNC 0xc04d8 · CSkeletonInstance::CSkeletonInstance(CSkeletonInstance*) · size=452 · insn=113 */
/* @0xc04d8 push {r4, r5, r6, r7, lr} */
/* @0xc04dc mov r7, r1 */
/* @0xc04e0 sub sp, sp, #20 */
/* @0xc04e4 ldr r1, [r1, #0x30] */
/* @0xc04e8 mov r5, r0 */
/* @0xc04ec bl 0xbe5dc <_ZN17CSkeletonInstance17SetupSkeletonDataEP14spSkeletonData> */
/* @0xc04f0 ldr r3, [r7, #0x28] */
/* @0xc04f4 ldr r3, [r3, #0xc] */
/* @0xc04f8 cmp r3, #0 */
/* @0xc04fc movgt r4, #0 */
/* @0xc0500 ble 0xc0530 <_ZN17CSkeletonInstanceC2EPS_+0x58> */
/* @0xc0504 mov r1, #0 */
/* @0xc0508 mov r0, r7 */
/* @0xc050c bl 0xc01b0 <_ZNK17CSkeletonInstance12GetAnimationEi> */
/* @0xc0510 add r4, r4, #1 */
/* @0xc0514 mov r1, r0 */
/* @0xc0518 mov r0, r5 */
/* @0xc051c bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc> */
/* @0xc0520 ldr r3, [r7, #0x28] */
/* @0xc0524 ldr r3, [r3, #0xc] */
/* @0xc0528 cmp r3, r4 */
/* @0xc052c bgt 0xc0504 <_ZN17CSkeletonInstanceC2EPS_+0x2c> */
/* @0xc0530 mov r0, r7 */
/* @0xc0534 mov r4, #0 */
/* @0xc0538 bl 0xc0170 <_ZNK17CSkeletonInstance7GetSkinEv> */
/* @0xc053c mov r1, r0 */
/* @0xc0540 mov r0, r5 */
/* @0xc0544 bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc> */
/* @0xc0548 str r4, [r5, #0x10] */
/* @0xc054c ldr r3, [r7, #0x10] */
/* @0xc0550 str r4, [r5, #0x14] */
/* @0xc0554 cmp r3, r4 */
/* @0xc0558 str r4, [r5, #0x18] */
/* @0xc055c ble 0xc0588 <_ZN17CSkeletonInstanceC2EPS_+0xb0> */
/* @0xc0560 ldr r2, [r7, #0x14] */
/* @0xc0564 mov r0, r5 */
/* @0xc0568 ldr r3, [r7, #0x18] */
/* @0xc056c ldr r1, [r2, r4, lsl #2] */
/* @0xc0570 ldr r2, [r3, r4, lsl #2] */
/* @0xc0574 add r4, r4, #1 */
/* @0xc0578 bl 0xbfc8c <_ZN17CSkeletonInstance15CloneAttachmentEP12spAttachmentP7spAtlas> */
/* @0xc057c ldr r3, [r7, #0x10] */
/* @0xc0580 cmp r3, r4 */
/* @0xc0584 bgt 0xc0560 <_ZN17CSkeletonInstanceC2EPS_+0x88> */
/* @0xc0588 ldr r3, [r5, #0x30] */
/* @0xc058c ldr r3, [r3, #0x18] */
/* @0xc0590 cmp r3, #0 */
/* @0xc0594 movgt r4, #0 */
/* @0xc0598 ble 0xc05e8 <_ZN17CSkeletonInstanceC2EPS_+0x110> */
/* @0xc059c ldr r3, [r7, #0x30] */
/* @0xc05a0 ldr r0, [r7, #0x1c] */
/* @0xc05a4 ldr r3, [r3, #0x1c] */
/* @0xc05a8 ldr r6, [r3, r4, lsl #2] */
/* @0xc05ac add r4, r4, #1 */
/* @0xc05b0 ldr r1, [r6, #0x4] */
/* @0xc05b4 bl 0x28a18c <spSkeleton_findSlot> */
/* @0xc05b8 mov r3, #0 */
/* @0xc05bc ldr r2, [r0, #0x18] */
/* @0xc05c0 mov r0, r5 */
/* @0xc05c4 cmp r2, r3 */
/* @0xc05c8 beq 0xc05d8 <_ZN17CSkeletonInstanceC2EPS_+0x100> */
/* @0xc05cc ldr r1, [r6, #0x4] */
/* @0xc05d0 ldr r2, [r2] */
/* @0xc05d4 bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b> */
/* @0xc05d8 ldr r3, [r5, #0x30] */
/* @0xc05dc ldr r3, [r3, #0x18] */
/* @0xc05e0 cmp r3, r4 */
/* @0xc05e4 bgt 0xc059c <_ZN17CSkeletonInstanceC2EPS_+0xc4> */
/* @0xc05e8 ldr r3, [r5, #0x2c] */
/* @0xc05ec ldr r6, [r3, #0x8] */
/* @0xc05f0 cmp r6, #0 */
/* @0xc05f4 beq 0xc0638 <_ZN17CSkeletonInstanceC2EPS_+0x160> */
/* @0xc05f8 ldr r4, [r6, #0x4] */
/* @0xc05fc cmp r4, #0 */
/* @0xc0600 beq 0xc062c <_ZN17CSkeletonInstanceC2EPS_+0x154> */
/* @0xc0604 ldr r2, [r4] */
/* @0xc0608 mov r0, r5 */
/* @0xc060c ldr r12, [r6] */
/* @0xc0610 ldr r3, [r4, #0x4] */
/* @0xc0614 ldr r2, [r2] */
/* @0xc0618 ldr r1, [r12] */
/* @0xc061c bl 0xbe580 <_ZN17CSkeletonInstance15SetAnimationMixEPKcS1_f> */
/* @0xc0620 ldr r4, [r4, #0x8] */
/* @0xc0624 cmp r4, #0 */
/* @0xc0628 bne 0xc0604 <_ZN17CSkeletonInstanceC2EPS_+0x12c> */
/* @0xc062c ldr r6, [r6, #0x8] */
/* @0xc0630 cmp r6, #0 */
/* @0xc0634 bne 0xc05f8 <_ZN17CSkeletonInstanceC2EPS_+0x120> */
/* @0xc0638 ldr r2, [r7, #0x1c] */
/* @0xc063c vldr s15, [r2, #88] */
/* @0xc0640 vneg.f32 s15, s15 */
/* @0xc0644 ldrb r0, [r7, #0x4] */
/* @0xc0648 ldr r1, [r7] */
/* @0xc064c mov r4, #0 */
/* @0xc0650 ldr r3, [r2, #0x5c] */
/* @0xc0654 ldr r12, [r5, #0x1c] */
/* @0xc0658 strb r0, [r5, #0x4] */
/* @0xc065c vstr s15, [r12, #88] */
/* @0xc0660 ldr r12, [r2, #0xc] */
/* @0xc0664 mov r0, r5 */
/* @0xc0668 ldr r2, [r2, #0x58] */
/* @0xc066c ldr lr, [r12, #0x20] */
/* @0xc0670 str lr, [sp] */
/* @0xc0674 ldr lr, [r12, #0x24] */
/* @0xc0678 str lr, [sp, #0x4] */
/* @0xc067c ldr r12, [r12, #0x1c] */
/* @0xc0680 str r4, [sp, #0xc] */
/* @0xc0684 str r12, [sp, #0x8] */
/* @0xc0688 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xc068c mov r0, r5 */
/* @0xc0690 strb r4, [r5, #0x5] */
/* @0xc0694 add sp, sp, #20 */
/* @0xc0698 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0xc04d8 · CSkeletonInstance::CSkeletonInstance(CSkeletonInstance*) · alias of the symbol above · insn=0 */

/* ── FUNC 0xc069c · CSkeletonSprite::DrawFrame(CSkeletonInstance*, char const*, char const*, float, float, float, float, float, float, unsigned int, float) · size=300 · insn=75 */
/* @0xc069c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc06a0 vpush {d8, d9} */
/* @0xc06a4 sub sp, sp, #28 */
/* @0xc06a8 vldr s16, [sp, #80] */
/* @0xc06ac mov r11, r2 */
/* @0xc06b0 mov r7, r0 */
/* @0xc06b4 ldr r2, [sp, #0x54] */
/* @0xc06b8 mov r0, #1 */
/* @0xc06bc str r3, [sp, #0x14] */
/* @0xc06c0 mov r5, r1 */
/* @0xc06c4 ldr r10, [sp, #0x58] */
/* @0xc06c8 vldr s19, [sp, #92] */
/* @0xc06cc str r2, [sp, #0x10] */
/* @0xc06d0 vldr s18, [sp, #96] */
/* @0xc06d4 vldr s17, [sp, #100] */
/* @0xc06d8 ldr r8, [sp, #0x68] */
/* @0xc06dc ldr r9, [sp, #0x6c] */
/* @0xc06e0 bl 0x284ed8 <spBone_setYDown> */
/* @0xc06e4 mov r0, #52 */
/* @0xc06e8 mov r4, #0 */
/* @0xc06ec bl 0x27c524 <_Znwj> */
/* @0xc06f0 mov r1, r5 */
/* @0xc06f4 mov r6, r0 */
/* @0xc06f8 bl 0xc04d8 <_ZN17CSkeletonInstanceC2EPS_> */
/* @0xc06fc mov r0, r6 */
/* @0xc0700 mov r1, r11 */
/* @0xc0704 bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc> */
/* @0xc0708 ldr r3, [sp, #0x14] */
/* @0xc070c mov r0, r6 */
/* @0xc0710 mov r1, r3 */
/* @0xc0714 bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc> */
/* @0xc0718 vcvt.s32.f32 s16, s16 */
/* @0xc071c mov r3, r10 */
/* @0xc0720 vstr s19, [sp] */
/* @0xc0724 vstr s18, [sp, #4] */
/* @0xc0728 vstr s17, [sp, #8] */
/* @0xc072c ldr r2, [sp, #0x10] */
/* @0xc0730 mov r0, r6 */
/* @0xc0734 str r4, [sp, #0xc] */
/* @0xc0738 vmov r1, s16 */
/* @0xc073c bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance> */
/* @0xc0740 ldr r5, [r5, #0x1c] */
/* @0xc0744 ldr r3, [r5, #0x10] */
/* @0xc0748 cmp r3, r4 */
/* @0xc074c ble 0xc0798 <_ZN15CSkeletonSprite9DrawFrameEP17CSkeletonInstancePKcS3_ffffffjf+0xfc> */
/* @0xc0750 ldr r2, [r5, #0x14] */
/* @0xc0754 ldr r2, [r2, r4, lsl #2] */
/* @0xc0758 cmp r2, #0 */
/* @0xc075c beq 0xc078c <_ZN15CSkeletonSprite9DrawFrameEP17CSkeletonInstancePKcS3_ffffffjf+0xf0> */
/* @0xc0760 ldr r3, [r5] */
/* @0xc0764 mov r0, r6 */
/* @0xc0768 ldr r2, [r2, #0x18] */
/* @0xc076c ldr r3, [r3, #0x1c] */
/* @0xc0770 cmp r2, #0 */
/* @0xc0774 ldrne r2, [r2] */
/* @0xc0778 ldr r3, [r3, r4, lsl #2] */
/* @0xc077c ldr r1, [r3, #0x4] */
/* @0xc0780 mov r3, #1 */
/* @0xc0784 bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b> */
/* @0xc0788 ldr r3, [r5, #0x10] */
/* @0xc078c add r4, r4, #1 */
/* @0xc0790 cmp r3, r4 */
/* @0xc0794 bgt 0xc0750 <_ZN15CSkeletonSprite9DrawFrameEP17CSkeletonInstancePKcS3_ffffffjf+0xb4> */
/* @0xc0798 mov r0, r7 */
/* @0xc079c mov r2, r8 */
/* @0xc07a0 mov r3, r9 */
/* @0xc07a4 ldr r1, [r6, #0x1c] */
/* @0xc07a8 bl 0xbe054 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf> */
/* @0xc07ac mov r0, r6 */
/* @0xc07b0 bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> */
/* @0xc07b4 mov r0, r6 */
/* @0xc07b8 add sp, sp, #28 */
/* @0xc07bc vpop {d8, d9} */
/* @0xc07c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc07c4 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0xc07c8 · CSkeletonInstance::GetAttachment(char*) const · size=72 · insn=18 */
/* @0xc07c8 push {r3, lr} */
/* @0xc07cc ldr r0, [r0, #0x1c] */
/* @0xc07d0 bl 0x28a18c <spSkeleton_findSlot> */
/* @0xc07d4 cmp r0, #0 */
/* @0xc07d8 beq 0xc07f0 <_ZNK17CSkeletonInstance13GetAttachmentEPc+0x28> */
/* @0xc07dc ldr r3, [r0, #0x18] */
/* @0xc07e0 cmp r3, #0 */
/* @0xc07e4 beq 0xc07fc <_ZNK17CSkeletonInstance13GetAttachmentEPc+0x34> */
/* @0xc07e8 ldr r0, [r3] */
/* @0xc07ec pop {r3, pc} */
/* @0xc07f0 ldr r0, [pc, #0x10] */
/* @0xc07f4 add r0, pc, r0 */
/* @0xc07f8 pop {r3, pc} */
/* @0xc07fc ldr r0, [pc, #0x8] */
/* @0xc0800 add r0, pc, r0 */
/* @0xc0804 pop {r3, pc} */
/* @0xc0808 eoreq lr, r6, r2, asr #6 */
/* @0xc080c eoreq lr, r6, r6, lsr r3 */

/* ── FUNC 0xc0810 · CSkeletonInstance::FindAttachment(char const*, char const*) · size=184 · insn=46 */
/* @0xc0810 push {r3, r4, r5, r6, r7, lr} */
/* @0xc0814 mov r6, r0 */
/* @0xc0818 ldr r0, [r0, #0x1c] */
/* @0xc081c mov r5, r2 */
/* @0xc0820 bl 0x28a1f4 <spSkeleton_findSlotIndex> */
/* @0xc0824 ldr r3, [r6, #0x30] */
/* @0xc0828 ldr r2, [r3, #0x20] */
/* @0xc082c cmp r2, #0 */
/* @0xc0830 movgt r4, #0 */
/* @0xc0834 mov r7, r0 */
/* @0xc0838 bgt 0xc0850 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x40> */
/* @0xc083c b 0xc0880 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x70> */
/* @0xc0840 ldr r3, [r6, #0x30] */
/* @0xc0844 ldr r12, [r3, #0x20] */
/* @0xc0848 cmp r12, r4 */
/* @0xc084c ble 0xc0880 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x70> */
/* @0xc0850 ldr r3, [r3, #0x24] */
/* @0xc0854 mov r1, r7 */
/* @0xc0858 mov r2, r5 */
/* @0xc085c ldr r0, [r3, r4, lsl #2] */
/* @0xc0860 add r4, r4, #1 */
/* @0xc0864 bl 0x28ed00 <spSkin_getAttachment> */
/* @0xc0868 cmp r0, #0 */
/* @0xc086c beq 0xc0840 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x30> */
/* @0xc0870 cmp r5, #0 */
/* @0xc0874 beq 0xc0880 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x70> */
/* @0xc0878 mov r0, r5 */
/* @0xc087c pop {r3, r4, r5, r6, r7, pc} */
/* @0xc0880 ldr r7, [r6, #0x10] */
/* @0xc0884 cmp r7, #0 */
/* @0xc0888 ble 0xc08bc <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0xac> */
/* @0xc088c ldr r6, [r6, #0x14] */
/* @0xc0890 mov r4, #0 */
/* @0xc0894 sub r6, r6, #4 */
/* @0xc0898 ldr r3, [r6, #0x4]! */
/* @0xc089c mov r1, r5 */
/* @0xc08a0 add r4, r4, #1 */
/* @0xc08a4 ldr r0, [r3] */
/* @0xc08a8 bl 0xb6574 <strcmp@plt> */
/* @0xc08ac cmp r0, #0 */
/* @0xc08b0 beq 0xc0878 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x68> */
/* @0xc08b4 cmp r4, r7 */
/* @0xc08b8 bne 0xc0898 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x88> */
/* @0xc08bc mov r5, #0 */
/* @0xc08c0 mov r0, r5 */
/* @0xc08c4 pop {r3, r4, r5, r6, r7, pc} */
