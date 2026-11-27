/* libyoyo.so 覆盖卡组 0133
 * 函数 0x19c8a8..0x19e884，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x19c8a8 · Motion_Linear_Step(CInstance*, float, float, float, int, bool) · size=292 · insn=73 */
/* @0x19c8a8 push {r4, r5, r6, lr} */
/* @0x19c8ac vpush {d8, d9} */
/* @0x19c8b0 vmov s16, r1 */
/* @0x19c8b4 vldr s13, [r0, #180] */
/* @0x19c8b8 sub sp, sp, #8 */
/* @0x19c8bc mov r4, r0 */
/* @0x19c8c0 vcmp.f32 s13, s16 */
/* @0x19c8c4 vldr s14, [r0, #184] */
/* @0x19c8c8 ldrb r5, [sp, #0x2c] */
/* @0x19c8cc vmov s17, r2 */
/* @0x19c8d0 vmov s18, r3 */
/* @0x19c8d4 vmrs APSR_nzcv, fpscr */
/* @0x19c8d8 bne 0x19c8ec <_Z18Motion_Linear_StepP9CInstancefffib+0x44> */
/* @0x19c8dc vcmp.f32 s14, s17 */
/* @0x19c8e0 vmrs APSR_nzcv, fpscr */
/* @0x19c8e4 moveq r0, #1 */
/* @0x19c8e8 beq 0x19c940 <_Z18Motion_Linear_StepP9CInstancefffib+0x98> */
/* @0x19c8ec vsub.f32 s14, s14, s17 */
/* @0x19c8f0 vmul.f32 s14, s14, s14 */
/* @0x19c8f4 vsub.f32 s13, s13, s16 */
/* @0x19c8f8 vmla.f32 s14, s13, s13 */
/* @0x19c8fc vsqrt.f32 s15, s14 */
/* @0x19c900 vcmp.f32 s15, s15 */
/* @0x19c904 vmrs APSR_nzcv, fpscr */
/* @0x19c908 bne 0x19c9bc <_Z18Motion_Linear_StepP9CInstancefffib+0x114> */
/* @0x19c90c vcmpe.f32 s15, s18 */
/* @0x19c910 vmrs APSR_nzcv, fpscr */
/* @0x19c914 movls r6, #1 */
/* @0x19c918 bhi 0x19c94c <_Z18Motion_Linear_StepP9CInstancefffib+0xa4> */
/* @0x19c91c str r5, [sp] */
/* @0x19c920 mov r0, r4 */
/* @0x19c924 vmov r1, s16 */
/* @0x19c928 ldr r3, [sp, #0x28] */
/* @0x19c92c vmov r2, s17 */
/* @0x19c930 bl 0x19c6f4 <_Z8TestFreeP9CInstanceffib> */
/* @0x19c934 cmp r0, #0 */
/* @0x19c938 moveq r0, r6 */
/* @0x19c93c bne 0x19c97c <_Z18Motion_Linear_StepP9CInstancefffib+0xd4> */
/* @0x19c940 add sp, sp, #8 */
/* @0x19c944 vpop {d8, d9} */
/* @0x19c948 pop {r4, r5, r6, pc} */
/* @0x19c94c vldr s13, [r4, #180] */
/* @0x19c950 vldr s14, [r4, #184] */
/* @0x19c954 vsub.f32 s16, s16, s13 */
/* @0x19c958 mov r6, #0 */
/* @0x19c95c vsub.f32 s17, s17, s14 */
/* @0x19c960 vmul.f32 s16, s16, s18 */
/* @0x19c964 vmul.f32 s18, s17, s18 */
/* @0x19c968 vdiv.f32 s16, s16, s15 */
/* @0x19c96c vdiv.f32 s15, s18, s15 */
/* @0x19c970 vadd.f32 s16, s13, s16 */
/* @0x19c974 vadd.f32 s17, s14, s15 */
/* @0x19c978 b 0x19c91c <_Z18Motion_Linear_StepP9CInstancefffib+0x74> */
/* @0x19c97c vmov r2, s16 */
/* @0x19c980 vmov r3, s17 */
/* @0x19c984 ldr r1, [r4, #0xb8] */
/* @0x19c988 ldr r0, [r4, #0xb4] */
/* @0x19c98c bl 0x19c740 <_Z10ComputeDirffff> */
/* @0x19c990 mov r1, r0 */
/* @0x19c994 mov r0, r4 */
/* @0x19c998 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x19c99c mov r0, r4 */
/* @0x19c9a0 vmov r1, s16 */
/* @0x19c9a4 vmov r2, s17 */
/* @0x19c9a8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x19c9ac mov r0, r6 */
/* @0x19c9b0 add sp, sp, #8 */
/* @0x19c9b4 vpop {d8, d9} */
/* @0x19c9b8 pop {r4, r5, r6, pc} */
/* @0x19c9bc vmov r0, s14 */
/* @0x19c9c0 bl 0xb6700 <sqrtf@plt> */
/* @0x19c9c4 vmov s15, r0 */
/* @0x19c9c8 b 0x19c90c <_Z18Motion_Linear_StepP9CInstancefffib+0x64> */

/* ── FUNC 0x19c9cc · Motion_Linear_Path(CInstance*, CPath*, float, float, float, int, bool) · size=332 · insn=83 */
/* @0x19c9cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19c9d0 vpush {d8, d9} */
/* @0x19c9d4 subs r4, r1, #0 */
/* @0x19c9d8 sub sp, sp, #20 */
/* @0x19c9dc mov r9, r0 */
/* @0x19c9e0 mov r6, r2 */
/* @0x19c9e4 vldr s18, [sp, #72] */
/* @0x19c9e8 mov r5, r3 */
/* @0x19c9ec ldr r7, [sp, #0x4c] */
/* @0x19c9f0 ldrb r8, [sp, #0x50] */
/* @0x19c9f4 beq 0x19cb08 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x13c> */
/* @0x19c9f8 vcmpe.f32 s18, #0 */
/* @0x19c9fc vmrs APSR_nzcv, fpscr */
/* @0x19ca00 movls r0, #0 */
/* @0x19ca04 bls 0x19caf4 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x128> */
/* @0x19ca08 ldr r3, [r9, #0xb4] */
/* @0x19ca0c mov r0, r4 */
/* @0x19ca10 ldr r10, [r9, #0xb8] */
/* @0x19ca14 ldr r11, [r9, #0xcc] */
/* @0x19ca18 str r3, [sp, #0xc] */
/* @0x19ca1c bl 0x1a6f98 <_ZN5CPath5ClearEv> */
/* @0x19ca20 mov r0, r4 */
/* @0x19ca24 mov r1, #0 */
/* @0x19ca28 bl 0x1a6e64 <_ZN5CPath7SetKindEi> */
/* @0x19ca2c mov r0, r4 */
/* @0x19ca30 mov r1, #0 */
/* @0x19ca34 bl 0x1a6e78 <_ZN5CPath9SetClosedEb> */
/* @0x19ca38 mov r0, r4 */
/* @0x19ca3c ldr r1, [r9, #0xb4] */
/* @0x19ca40 mov r3, #0 */
/* @0x19ca44 ldr r2, [r9, #0xb8] */
/* @0x19ca48 movt r3, #0x42c8 */
/* @0x19ca4c bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19ca50 b 0x19ca80 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0xb4> */
/* @0x19ca54 vldr s15, [r9, #180] */
/* @0x19ca58 vcmp.f32 s16, s15 */
/* @0x19ca5c vmov r1, s15 */
/* @0x19ca60 vldr s15, [r9, #184] */
/* @0x19ca64 vmrs APSR_nzcv, fpscr */
/* @0x19ca68 bne 0x19ca78 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0xac> */
/* @0x19ca6c vcmp.f32 s17, s15 */
/* @0x19ca70 vmrs APSR_nzcv, fpscr */
/* @0x19ca74 beq 0x19cb00 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x134> */
/* @0x19ca78 vmov r2, s15 */
/* @0x19ca7c bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19ca80 str r7, [sp] */
/* @0x19ca84 mov r2, r5 */
/* @0x19ca88 str r8, [sp, #0x4] */
/* @0x19ca8c mov r0, r9 */
/* @0x19ca90 vmov r3, s18 */
/* @0x19ca94 mov r1, r6 */
/* @0x19ca98 vldr s16, [r9, #180] */
/* @0x19ca9c vldr s17, [r9, #184] */
/* @0x19caa0 bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib> */
/* @0x19caa4 mov r3, #0 */
/* @0x19caa8 movt r3, #0x42c8 */
/* @0x19caac subs r2, r0, #0 */
/* @0x19cab0 mov r0, r4 */
/* @0x19cab4 beq 0x19ca54 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x88> */
/* @0x19cab8 mov r0, r4 */
/* @0x19cabc mov r3, #0 */
/* @0x19cac0 mov r1, r6 */
/* @0x19cac4 mov r2, r5 */
/* @0x19cac8 movt r3, #0x42c8 */
/* @0x19cacc mov r4, #1 */
/* @0x19cad0 bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19cad4 ldr r1, [sp, #0xc] */
/* @0x19cad8 mov r0, r9 */
/* @0x19cadc mov r2, r10 */
/* @0x19cae0 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x19cae4 mov r0, r9 */
/* @0x19cae8 mov r1, r11 */
/* @0x19caec bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x19caf0 mov r0, r4 */
/* @0x19caf4 add sp, sp, #20 */
/* @0x19caf8 vpop {d8, d9} */
/* @0x19cafc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19cb00 mov r4, r2 */
/* @0x19cb04 b 0x19cad4 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x108> */
/* @0x19cb08 mov r0, r4 */
/* @0x19cb0c add sp, sp, #20 */
/* @0x19cb10 vpop {d8, d9} */
/* @0x19cb14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x19cb18 · Motion_Potential_Settings(float, float, float, bool) · size=144 · insn=36 */
/* @0x19cb18 vmov.f32 s15, #1.000000e+00 */
/* @0x19cb1c ldr r12, [pc, #0x70] */
/* @0x19cb20 vmov s12, r0 */
/* @0x19cb24 ldr r0, [pc, #0x6c] */
/* @0x19cb28 vmov s13, r1 */
/* @0x19cb2c ldr r1, [pc, #0x68] */
/* @0x19cb30 vmov s14, r2 */
/* @0x19cb34 add r12, pc, r12 */
/* @0x19cb38 push {r4, r5} */
/* @0x19cb3c mov r2, r12 */
/* @0x19cb40 ldr r5, [pc, #0x58] */
/* @0x19cb44 ldr r4, [pc, #0x58] */
/* @0x19cb48 ldr r0, [r12, r0] */
/* @0x19cb4c vcmpe.f32 s12, s15 */
/* @0x19cb50 vmrs APSR_nzcv, fpscr */
/* @0x19cb54 vcmpe.f32 s13, s15 */
/* @0x19cb58 vmovmi.f32 s12, s15 */
/* @0x19cb5c vmrs APSR_nzcv, fpscr */
/* @0x19cb60 vstr s12, [r0] */
/* @0x19cb64 ldr r1, [r12, r1] */
/* @0x19cb68 vcmpe.f32 s14, s15 */
/* @0x19cb6c vmovmi.f32 s13, s15 */
/* @0x19cb70 vmrs APSR_nzcv, fpscr */
/* @0x19cb74 vstr s13, [r1] */
/* @0x19cb78 ldr r1, [r12, r5] */
/* @0x19cb7c vmovpl.f32 s15, s14 */
/* @0x19cb80 vstr s15, [r1] */
/* @0x19cb84 ldr r2, [r12, r4] */
/* @0x19cb88 pop {r4, r5} */
/* @0x19cb8c strb r3, [r2] */
/* @0x19cb90 bx lr */
/* @0x19cb94 eoreq r5, r5, r12, lsl r1 */
/* @0x19cb98 .word 0xffffea78 */
/* @0x19cb9c .word 0xffffea7c */
/* @0x19cba0 .word 0xffffea80 */
/* @0x19cba4 .word 0xffffea84 */

/* ── FUNC 0x19cba8 · TryDir(float, CInstance*, float, int, bool) · size=288 · insn=72 */
/* @0x19cba8 push {r4, r5, r6, lr} */
/* @0x19cbac vpush {d8, d9, d10} */
/* @0x19cbb0 sub sp, sp, #8 */
/* @0x19cbb4 mov r4, r1 */
/* @0x19cbb8 ldr r1, [r1, #0xcc] */
/* @0x19cbbc vmov s16, r2 */
/* @0x19cbc0 mov r5, r3 */
/* @0x19cbc4 vmov s17, r0 */
/* @0x19cbc8 ldrb r6, [sp, #0x30] */
/* @0x19cbcc bl 0x19c7ec <_Z7DiffDirff> */
/* @0x19cbd0 ldr r2, [pc, #0xe8] */
/* @0x19cbd4 ldr r2, [pc, r2] */
/* @0x19cbd8 vldr s15, [r2] */
/* @0x19cbdc vmov s14, r0 */
/* @0x19cbe0 vcmpe.f32 s14, s15 */
/* @0x19cbe4 vmrs APSR_nzcv, fpscr */
/* @0x19cbe8 ble 0x19cc00 <_Z6TryDirfP9CInstancefib+0x58> */
/* @0x19cbec mov r5, #0 */
/* @0x19cbf0 mov r0, r5 */
/* @0x19cbf4 add sp, sp, #8 */
/* @0x19cbf8 vpop {d8, d9, d10} */
/* @0x19cbfc pop {r4, r5, r6, pc} */
/* @0x19cc00 vldr s19, [pc, #176] */
/* @0x19cc04 vmul.f32 s19, s17, s19 */
/* @0x19cc08 vldr s15, [pc, #172] */
/* @0x19cc0c ldr r2, [pc, #0xb0] */
/* @0x19cc10 ldr r2, [pc, r2] */
/* @0x19cc14 vldr s18, [r2] */
/* @0x19cc18 vdiv.f32 s19, s19, s15 */
/* @0x19cc1c vmov r0, s19 */
/* @0x19cc20 bl 0xb658c <cosf@plt> */
/* @0x19cc24 vmul.f32 s18, s16, s18 */
/* @0x19cc28 vmov s20, r0 */
/* @0x19cc2c vmov r0, s19 */
/* @0x19cc30 bl 0xb6580 <sinf@plt> */
/* @0x19cc34 str r6, [sp] */
/* @0x19cc38 vldr s14, [r4, #180] */
/* @0x19cc3c vldr s15, [r4, #184] */
/* @0x19cc40 vmla.f32 s14, s18, s20 */
/* @0x19cc44 mov r3, r5 */
/* @0x19cc48 vmov r1, s14 */
/* @0x19cc4c vmov s19, r0 */
/* @0x19cc50 mov r0, r4 */
/* @0x19cc54 vmls.f32 s15, s18, s19 */
/* @0x19cc58 vmov r2, s15 */
/* @0x19cc5c bl 0x19c6f4 <_Z8TestFreeP9CInstanceffib> */
/* @0x19cc60 cmp r0, #0 */
/* @0x19cc64 beq 0x19cbec <_Z6TryDirfP9CInstancefib+0x44> */
/* @0x19cc68 vldr s21, [r4, #180] */
/* @0x19cc6c vldr s18, [r4, #184] */
/* @0x19cc70 vmla.f32 s21, s16, s20 */
/* @0x19cc74 mov r3, r5 */
/* @0x19cc78 str r6, [sp] */
/* @0x19cc7c mov r0, r4 */
/* @0x19cc80 vmls.f32 s18, s16, s19 */
/* @0x19cc84 vmov r1, s21 */
/* @0x19cc88 vmov r2, s18 */
/* @0x19cc8c bl 0x19c6f4 <_Z8TestFreeP9CInstanceffib> */
/* @0x19cc90 subs r5, r0, #0 */
/* @0x19cc94 beq 0x19cbec <_Z6TryDirfP9CInstancefib+0x44> */
/* @0x19cc98 mov r0, r4 */
/* @0x19cc9c vmov r1, s17 */
/* @0x19cca0 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x19cca4 mov r0, r4 */
/* @0x19cca8 vmov r1, s21 */
/* @0x19ccac vmov r2, s18 */
/* @0x19ccb0 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x19ccb4 b 0x19cbf0 <_Z6TryDirfP9CInstancefib+0x48> */
/* @0x19ccb8 ldrdmi r0, r1, [r9], #-251 */
/* @0x19ccbc teqmi r4, #0 */
/* @0x19ccc0 .word 0x00253af4 */
/* @0x19ccc4 eoreq r3, r5, r0, asr #21 */

/* ── FUNC 0x19ccc8 · Motion_Potential_Step(CInstance*, float, float, float, int, bool) · size=460 · insn=115 */
/* @0x19ccc8 push {r4, r5, r6, r7, lr} */
/* @0x19cccc vpush {d8, d9, d10} */
/* @0x19ccd0 vmov s18, r1 */
/* @0x19ccd4 vldr s15, [r0, #180] */
/* @0x19ccd8 sub sp, sp, #12 */
/* @0x19ccdc mov r4, r0 */
/* @0x19cce0 vcmp.f32 s15, s18 */
/* @0x19cce4 vldr s14, [r0, #184] */
/* @0x19cce8 vmov s19, r2 */
/* @0x19ccec ldr r5, [sp, #0x38] */
/* @0x19ccf0 vmov s17, r3 */
/* @0x19ccf4 ldrb r6, [sp, #0x3c] */
/* @0x19ccf8 vmrs APSR_nzcv, fpscr */
/* @0x19ccfc bne 0x19cd1c <_Z21Motion_Potential_StepP9CInstancefffib+0x54> */
/* @0x19cd00 vcmp.f32 s14, s19 */
/* @0x19cd04 vmrs APSR_nzcv, fpscr */
/* @0x19cd08 bne 0x19cd1c <_Z21Motion_Potential_StepP9CInstancefffib+0x54> */
/* @0x19cd0c mov r0, #1 */
/* @0x19cd10 add sp, sp, #12 */
/* @0x19cd14 vpop {d8, d9, d10} */
/* @0x19cd18 pop {r4, r5, r6, r7, pc} */
/* @0x19cd1c vsub.f32 s14, s14, s19 */
/* @0x19cd20 vmul.f32 s14, s14, s14 */
/* @0x19cd24 vsub.f32 s15, s15, s18 */
/* @0x19cd28 vmla.f32 s14, s15, s15 */
/* @0x19cd2c vsqrt.f32 s15, s14 */
/* @0x19cd30 vcmp.f32 s15, s15 */
/* @0x19cd34 vmrs APSR_nzcv, fpscr */
/* @0x19cd38 bne 0x19ce70 <_Z21Motion_Potential_StepP9CInstancefffib+0x1a8> */
/* @0x19cd3c vcmpe.f32 s15, s17 */
/* @0x19cd40 vmrs APSR_nzcv, fpscr */
/* @0x19cd44 bls 0x19cde0 <_Z21Motion_Potential_StepP9CInstancefffib+0x118> */
/* @0x19cd48 vmov r2, s18 */
/* @0x19cd4c vldr s16, [pc, #300] */
/* @0x19cd50 ldr r0, [r4, #0xb4] */
/* @0x19cd54 vldr s20, [pc, #296] */
/* @0x19cd58 ldr r1, [r4, #0xb8] */
/* @0x19cd5c vmov r3, s19 */
/* @0x19cd60 bl 0x19c740 <_Z10ComputeDirffff> */
/* @0x19cd64 vmov s18, r0 */
/* @0x19cd68 b 0x19cda0 <_Z21Motion_Potential_StepP9CInstancefffib+0xd8> */
/* @0x19cd6c vadd.f32 s15, s18, s16 */
/* @0x19cd70 str r6, [sp] */
/* @0x19cd74 vmov r0, s15 */
/* @0x19cd78 bl 0x19cba8 <_Z6TryDirfP9CInstancefib> */
/* @0x19cd7c ldr r2, [pc, #0x104] */
/* @0x19cd80 subs r7, r0, #0 */
/* @0x19cd84 bne 0x19cdd0 <_Z21Motion_Potential_StepP9CInstancefffib+0x108> */
/* @0x19cd88 ldr r2, [pc, r2] */
/* @0x19cd8c vldr s15, [r2] */
/* @0x19cd90 vadd.f32 s16, s16, s15 */
/* @0x19cd94 vcmpe.f32 s16, s20 */
/* @0x19cd98 vmrs APSR_nzcv, fpscr */
/* @0x19cd9c bpl 0x19ce34 <_Z21Motion_Potential_StepP9CInstancefffib+0x16c> */
/* @0x19cda0 vsub.f32 s15, s18, s16 */
/* @0x19cda4 mov r1, r4 */
/* @0x19cda8 vmov r2, s17 */
/* @0x19cdac mov r3, r5 */
/* @0x19cdb0 str r6, [sp] */
/* @0x19cdb4 vmov r0, s15 */
/* @0x19cdb8 bl 0x19cba8 <_Z6TryDirfP9CInstancefib> */
/* @0x19cdbc mov r1, r4 */
/* @0x19cdc0 vmov r2, s17 */
/* @0x19cdc4 mov r3, r5 */
/* @0x19cdc8 cmp r0, #0 */
/* @0x19cdcc beq 0x19cd6c <_Z21Motion_Potential_StepP9CInstancefffib+0xa4> */
/* @0x19cdd0 mov r0, #0 */
/* @0x19cdd4 add sp, sp, #12 */
/* @0x19cdd8 vpop {d8, d9, d10} */
/* @0x19cddc pop {r4, r5, r6, r7, pc} */
/* @0x19cde0 str r6, [sp] */
/* @0x19cde4 mov r3, r5 */
/* @0x19cde8 mov r0, r4 */
/* @0x19cdec vmov r1, s18 */
/* @0x19cdf0 vmov r2, s19 */
/* @0x19cdf4 bl 0x19c6f4 <_Z8TestFreeP9CInstanceffib> */
/* @0x19cdf8 cmp r0, #0 */
/* @0x19cdfc beq 0x19cd0c <_Z21Motion_Potential_StepP9CInstancefffib+0x44> */
/* @0x19ce00 vmov r2, s18 */
/* @0x19ce04 ldr r1, [r4, #0xb8] */
/* @0x19ce08 vmov r3, s19 */
/* @0x19ce0c ldr r0, [r4, #0xb4] */
/* @0x19ce10 bl 0x19c740 <_Z10ComputeDirffff> */
/* @0x19ce14 mov r1, r0 */
/* @0x19ce18 mov r0, r4 */
/* @0x19ce1c bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x19ce20 mov r0, r4 */
/* @0x19ce24 vmov r1, s18 */
/* @0x19ce28 vmov r2, s19 */
/* @0x19ce2c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x19ce30 b 0x19cd0c <_Z21Motion_Potential_StepP9CInstancefffib+0x44> */
/* @0x19ce34 ldr r3, [pc, #0x50] */
/* @0x19ce38 ldr r3, [pc, r3] */
/* @0x19ce3c ldrb r3, [r3] */
/* @0x19ce40 cmp r3, #0 */
/* @0x19ce44 beq 0x19cdd0 <_Z21Motion_Potential_StepP9CInstancefffib+0x108> */
/* @0x19ce48 ldr r3, [pc, #0x40] */
/* @0x19ce4c vldr s14, [r4, #204] */
/* @0x19ce50 mov r0, r4 */
/* @0x19ce54 ldr r3, [pc, r3] */
/* @0x19ce58 vldr s15, [r3] */
/* @0x19ce5c vadd.f32 s15, s14, s15 */
/* @0x19ce60 vmov r1, s15 */
/* @0x19ce64 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x19ce68 mov r0, r7 */
/* @0x19ce6c b 0x19cd10 <_Z21Motion_Potential_StepP9CInstancefffib+0x48> */
/* @0x19ce70 vmov r0, s14 */
/* @0x19ce74 bl 0xb6700 <sqrtf@plt> */
/* @0x19ce78 vmov s15, r0 */
/* @0x19ce7c b 0x19cd3c <_Z21Motion_Potential_StepP9CInstancefffib+0x74> */
/* @0x19ce80 andeq r0, r0, r0 */
/* @0x19ce84 teqmi r4, #0 */
/* @0x19ce88 eoreq r3, r5, r4, asr #18 */
/* @0x19ce8c mlaeq r5, r12, r8, r3 */
/* @0x19ce90 eoreq r3, r5, r4, ror r8 */

/* ── FUNC 0x19ce94 · Motion_Potential_Path(CInstance*, CPath*, float, float, float, float, int, bool) · size=460 · insn=115 */
/* @0x19ce94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19ce98 vpush {d8, d9} */
/* @0x19ce9c subs r6, r1, #0 */
/* @0x19cea0 sub sp, sp, #20 */
/* @0x19cea4 mov r4, r0 */
/* @0x19cea8 mov r10, r2 */
/* @0x19ceac mov r9, r3 */
/* @0x19ceb0 ldr r8, [sp, #0x48] */
/* @0x19ceb4 vldr s16, [sp, #76] */
/* @0x19ceb8 ldrb r11, [sp, #0x54] */
/* @0x19cebc beq 0x19d034 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x1a0> */
/* @0x19cec0 vmov.f32 s15, #1.000000e+00 */
/* @0x19cec4 vcmpe.f32 s16, s15 */
/* @0x19cec8 vmrs APSR_nzcv, fpscr */
/* @0x19cecc bmi 0x19cffc <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x168> */
/* @0x19ced0 vmov s13, r8 */
/* @0x19ced4 vcmpe.f32 s13, #0 */
/* @0x19ced8 vmrs APSR_nzcv, fpscr */
/* @0x19cedc bls 0x19cffc <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x168> */
/* @0x19cee0 vmov s14, r3 */
/* @0x19cee4 vldr s18, [r0, #184] */
/* @0x19cee8 vmov s13, r2 */
/* @0x19ceec vldr s19, [r0, #180] */
/* @0x19cef0 vsub.f32 s15, s14, s18 */
/* @0x19cef4 vmul.f32 s15, s15, s15 */
/* @0x19cef8 vsub.f32 s14, s13, s19 */
/* @0x19cefc vmla.f32 s15, s14, s14 */
/* @0x19cf00 vsqrt.f32 s17, s15 */
/* @0x19cf04 vcmp.f32 s17, s17 */
/* @0x19cf08 vmrs APSR_nzcv, fpscr */
/* @0x19cf0c bne 0x19d044 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x1b0> */
/* @0x19cf10 ldr r3, [r4, #0xcc] */
/* @0x19cf14 mov r0, r6 */
/* @0x19cf18 vmul.f32 s17, s17, s16 */
/* @0x19cf1c vldr s16, [pc, #312] */
/* @0x19cf20 str r3, [sp, #0xc] */
/* @0x19cf24 bl 0x1a6f98 <_ZN5CPath5ClearEv> */
/* @0x19cf28 mov r1, #0 */
/* @0x19cf2c mov r0, r6 */
/* @0x19cf30 mov r5, r1 */
/* @0x19cf34 bl 0x1a6e64 <_ZN5CPath7SetKindEi> */
/* @0x19cf38 mov r0, r6 */
/* @0x19cf3c mov r1, r5 */
/* @0x19cf40 bl 0x1a6e78 <_ZN5CPath9SetClosedEb> */
/* @0x19cf44 mov r3, #0 */
/* @0x19cf48 mov r0, r6 */
/* @0x19cf4c ldr r1, [r4, #0xb4] */
/* @0x19cf50 ldr r2, [r4, #0xb8] */
/* @0x19cf54 movt r3, #0x42c8 */
/* @0x19cf58 bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19cf5c ldr r3, [sp, #0x50] */
/* @0x19cf60 mov r0, r4 */
/* @0x19cf64 str r11, [sp, #0x4] */
/* @0x19cf68 mov r1, r10 */
/* @0x19cf6c mov r2, r9 */
/* @0x19cf70 add r5, r5, #1 */
/* @0x19cf74 str r3, [sp] */
/* @0x19cf78 mov r3, r8 */
/* @0x19cf7c bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib> */
/* @0x19cf80 mov r3, #0 */
/* @0x19cf84 movt r3, #0x42c8 */
/* @0x19cf88 subs r7, r0, #0 */
/* @0x19cf8c mov r0, r6 */
/* @0x19cf90 bne 0x19d014 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x180> */
/* @0x19cf94 ldr r1, [r4, #0xb4] */
/* @0x19cf98 ldr r2, [r4, #0xb8] */
/* @0x19cf9c bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19cfa0 mov r0, r6 */
/* @0x19cfa4 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv> */
/* @0x19cfa8 vmov s15, r0 */
/* @0x19cfac vcmpe.f32 s17, s15 */
/* @0x19cfb0 vmrs APSR_nzcv, fpscr */
/* @0x19cfb4 bmi 0x19cfd0 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x13c> */
/* @0x19cfb8 vcmp.f32 s16, s15 */
/* @0x19cfbc vmov s16, r0 */
/* @0x19cfc0 vmrs APSR_nzcv, fpscr */
/* @0x19cfc4 bne 0x19d00c <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x178> */
/* @0x19cfc8 cmp r5, #100 */
/* @0x19cfcc ble 0x19cf5c <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0xc8> */
/* @0x19cfd0 mov r0, r4 */
/* @0x19cfd4 vmov r1, s19 */
/* @0x19cfd8 vmov r2, s18 */
/* @0x19cfdc bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x19cfe0 mov r0, r4 */
/* @0x19cfe4 ldr r1, [sp, #0xc] */
/* @0x19cfe8 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x19cfec mov r0, r7 */
/* @0x19cff0 add sp, sp, #20 */
/* @0x19cff4 vpop {d8, d9} */
/* @0x19cff8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19cffc mov r0, #0 */
/* @0x19d000 add sp, sp, #20 */
/* @0x19d004 vpop {d8, d9} */
/* @0x19d008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19d00c mov r5, r7 */
/* @0x19d010 b 0x19cf5c <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0xc8> */
/* @0x19d014 mov r0, r6 */
/* @0x19d018 mov r1, r10 */
/* @0x19d01c mov r2, r9 */
/* @0x19d020 mov r3, #0 */
/* @0x19d024 movt r3, #0x42c8 */
/* @0x19d028 mov r7, #1 */
/* @0x19d02c bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19d030 b 0x19cfd0 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x13c> */
/* @0x19d034 mov r0, r6 */
/* @0x19d038 add sp, sp, #20 */
/* @0x19d03c vpop {d8, d9} */
/* @0x19d040 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19d044 vmov r0, s15 */
/* @0x19d048 bl 0xb6700 <sqrtf@plt> */
/* @0x19d04c vldr s19, [r4, #180] */
/* @0x19d050 vldr s18, [r4, #184] */
/* @0x19d054 vmov s17, r0 */
/* @0x19d058 b 0x19cf10 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x7c> */
/* @0x19d05c andeq r0, r0, r0 */

/* ── FUNC 0x19d060 · WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) · size=360 · insn=90 */
/* @0x19d060 str r4, [sp, #-0x4]! */
/* @0x19d064 cmn r1, #1 */
/* @0x19d068 ldrb r12, [sp, #0x4] */
/* @0x19d06c mvn r4, #0 */
/* @0x19d070 str r1, [r0, #0x14] */
/* @0x19d074 str r4, [r0, #0x18] */
/* @0x19d078 strb r12, [r0, #0x20] */
/* @0x19d07c mov r12, #0 */
/* @0x19d080 streq r2, [r0, #0x10] */
/* @0x19d084 str r12, [r0] */
/* @0x19d088 str r12, [r0, #0x4] */
/* @0x19d08c str r12, [r0, #0x8] */
/* @0x19d090 str r12, [r0, #0x1c] */
/* @0x19d094 beq 0x19d128 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xc8> */
/* @0x19d098 cmn r1, #2 */
/* @0x19d09c beq 0x19d170 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x110> */
/* @0x19d0a0 cmn r1, #3 */
/* @0x19d0a4 beq 0x19d18c <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x12c> */
/* @0x19d0a8 movw r3, #0x869f */
/* @0x19d0ac movt r3, #0x1 */
/* @0x19d0b0 cmp r1, r3 */
/* @0x19d0b4 bgt 0x19d130 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xd0> */
/* @0x19d0b8 ldr r3, [pc, #0xfc] */
/* @0x19d0bc str r12, [r0, #0x18] */
/* @0x19d0c0 ldr r3, [pc, r3] */
/* @0x19d0c4 ldr r3, [r3] */
/* @0x19d0c8 ldr r2, [r3, #0x4] */
/* @0x19d0cc ldr r3, [r3] */
/* @0x19d0d0 and r2, r1, r2 */
/* @0x19d0d4 ldr r3, [r3, r2, lsl #3] */
/* @0x19d0d8 cmp r3, #0 */
/* @0x19d0dc bne 0x19d0f0 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x90> */
/* @0x19d0e0 b 0x19d17c <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x11c> */
/* @0x19d0e4 ldr r3, [r3, #0x4] */
/* @0x19d0e8 cmp r3, #0 */
/* @0x19d0ec beq 0x19d17c <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x11c> */
/* @0x19d0f0 ldr r2, [r3, #0x8] */
/* @0x19d0f4 cmp r1, r2 */
/* @0x19d0f8 bne 0x19d0e4 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x84> */
/* @0x19d0fc ldr r3, [r3, #0xc] */
/* @0x19d100 cmp r3, #0 */
/* @0x19d104 str r3, [r0, #0xc] */
/* @0x19d108 beq 0x19d128 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xc8> */
/* @0x19d10c ldr r3, [r3, #0xd0] */
/* @0x19d110 cmp r3, #0 */
/* @0x19d114 str r3, [r0] */
/* @0x19d118 beq 0x19d1b0 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x150> */
/* @0x19d11c ldr r3, [r3, #0x8] */
/* @0x19d120 cmp r3, #0 */
/* @0x19d124 beq 0x19d1b0 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x150> */
/* @0x19d128 ldr r4, [sp], #4 */
/* @0x19d12c bx lr */
/* @0x19d130 ldr r3, [pc, #0x88] */
/* @0x19d134 ldr r3, [pc, r3] */
/* @0x19d138 ldr r2, [r3, #0x4] */
/* @0x19d13c ldr r3, [r3] */
/* @0x19d140 and r2, r1, r2 */
/* @0x19d144 ldr r3, [r3, r2, lsl #3] */
/* @0x19d148 cmp r3, #0 */
/* @0x19d14c bne 0x19d160 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x100> */
/* @0x19d150 b 0x19d170 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x110> */
/* @0x19d154 ldr r3, [r3, #0x4] */
/* @0x19d158 cmp r3, #0 */
/* @0x19d15c beq 0x19d170 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x110> */
/* @0x19d160 ldr r2, [r3, #0x8] */
/* @0x19d164 cmp r1, r2 */
/* @0x19d168 bne 0x19d154 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xf4> */
/* @0x19d16c ldr r3, [r3, #0xc] */
/* @0x19d170 str r3, [r0, #0x10] */
/* @0x19d174 ldr r4, [sp], #4 */
/* @0x19d178 bx lr */
/* @0x19d17c mov r3, #0 */
/* @0x19d180 str r3, [r0, #0xc] */
/* @0x19d184 ldr r4, [sp], #4 */
/* @0x19d188 bx lr */
/* @0x19d18c ldr r3, [pc, #0x30] */
/* @0x19d190 mvn r2, #1 */
/* @0x19d194 ldr r4, [sp], #4 */
/* @0x19d198 ldr r3, [pc, r3] */
/* @0x19d19c ldr r3, [r3] */
/* @0x19d1a0 ldr r3, [r3, #0x80] */
/* @0x19d1a4 str r2, [r0, #0x18] */
/* @0x19d1a8 str r3, [r0, #0x4] */
/* @0x19d1ac bx lr */
/* @0x19d1b0 mov r3, #1 */
/* @0x19d1b4 str r3, [r0, #0x18] */
/* @0x19d1b8 b 0x19d128 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xc8> */
/* @0x19d1bc eoreq r0, r5, r12, ror r11 */
/* @0x19d1c0 eoreq r0, r5, r0, lsl r11 */
/* @0x19d1c4 mlaeq r5, r0, r7, r0 */

/* ── FUNC 0x19d060 · WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x19d1c8 · WithObjIterator::Next() · size=268 · insn=67 */
/* @0x19d1c8 ldr r3, [r0, #0x18] */
/* @0x19d1cc add r3, r3, #2 */
/* @0x19d1d0 cmp r3, #5 */
/* @0x19d1d4 addls pc, pc, r3, lsl #2 */
/* @0x19d1d8 b 0x19d208 <_ZN15WithObjIterator4NextEv+0x40> */
/* @0x19d1dc b 0x19d20c <_ZN15WithObjIterator4NextEv+0x44> */
/* @0x19d1e0 b 0x19d220 <_ZN15WithObjIterator4NextEv+0x58> */
/* @0x19d1e4 b 0x19d22c <_ZN15WithObjIterator4NextEv+0x64> */
/* @0x19d1e8 b 0x19d268 <_ZN15WithObjIterator4NextEv+0xa0> */
/* @0x19d1ec b 0x19d294 <_ZN15WithObjIterator4NextEv+0xcc> */
/* @0x19d1f0 b 0x19d1f4 <_ZN15WithObjIterator4NextEv+0x2c> */
/* @0x19d1f4 ldr r3, [r0, #0x8] */
/* @0x19d1f8 cmp r3, #0 */
/* @0x19d1fc bxeq lr */
/* @0x19d200 ldr r3, [r3, #0x178] */
/* @0x19d204 str r3, [r0, #0x8] */
/* @0x19d208 bx lr */
/* @0x19d20c ldr r3, [r0, #0x4] */
/* @0x19d210 cmp r3, #0 */
/* @0x19d214 ldrne r3, [r3, #0x178] */
/* @0x19d218 strne r3, [r0, #0x4] */
/* @0x19d21c bx lr */
/* @0x19d220 mov r3, #0 */
/* @0x19d224 str r3, [r0, #0x10] */
/* @0x19d228 bx lr */
/* @0x19d22c ldr r3, [r0] */
/* @0x19d230 cmp r3, #0 */
/* @0x19d234 beq 0x19d254 <_ZN15WithObjIterator4NextEv+0x8c> */
/* @0x19d238 ldr r3, [r3] */
/* @0x19d23c cmp r3, #0 */
/* @0x19d240 str r3, [r0] */
/* @0x19d244 beq 0x19d254 <_ZN15WithObjIterator4NextEv+0x8c> */
/* @0x19d248 ldr r3, [r3, #0x8] */
/* @0x19d24c cmp r3, #0 */
/* @0x19d250 bxne lr */
/* @0x19d254 mov r2, #1 */
/* @0x19d258 mov r3, #0 */
/* @0x19d25c str r2, [r0, #0x18] */
/* @0x19d260 str r3, [r0, #0x1c] */
/* @0x19d264 bx lr */
/* @0x19d268 ldr r3, [pc, #0x5c] */
/* @0x19d26c ldr r2, [r0, #0x1c] */
/* @0x19d270 ldr r3, [pc, r3] */
/* @0x19d274 ldr r3, [r3, #0x8] */
/* @0x19d278 cmp r2, r3 */
/* @0x19d27c blt 0x19d2c0 <_ZN15WithObjIterator4NextEv+0xf8> */
/* @0x19d280 mov r2, #2 */
/* @0x19d284 mov r3, #0 */
/* @0x19d288 str r2, [r0, #0x18] */
/* @0x19d28c str r3, [r0, #0x1c] */
/* @0x19d290 bx lr */
/* @0x19d294 ldr r3, [pc, #0x34] */
/* @0x19d298 ldr r2, [r0, #0x1c] */
/* @0x19d29c ldr r3, [pc, r3] */
/* @0x19d2a0 ldr r3, [r3, #0x8] */
/* @0x19d2a4 cmp r2, r3 */
/* @0x19d2a8 blt 0x19d2c0 <_ZN15WithObjIterator4NextEv+0xf8> */
/* @0x19d2ac mov r2, #3 */
/* @0x19d2b0 mov r3, #0 */
/* @0x19d2b4 str r2, [r0, #0x18] */
/* @0x19d2b8 str r3, [r0, #0x1c] */
/* @0x19d2bc bx lr */
/* @0x19d2c0 add r2, r2, #1 */
/* @0x19d2c4 str r2, [r0, #0x1c] */
/* @0x19d2c8 bx lr */
/* @0x19d2cc .word 0x002509d0 */
/* @0x19d2d0 eoreq r0, r5, r12, lsr #19 */

/* ── FUNC 0x19d2d4 · CObjectGM::SetName(char*) · size=116 · insn=29 */
/* @0x19d2d4 push {r4, r5, r6, lr} */
/* @0x19d2d8 mov r5, r0 */
/* @0x19d2dc ldr r0, [r0, #0x14] */
/* @0x19d2e0 mov r4, r1 */
/* @0x19d2e4 cmp r0, #0 */
/* @0x19d2e8 beq 0x19d2f8 <_ZN9CObjectGM7SetNameEPc+0x24> */
/* @0x19d2ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d2f0 mov r3, #0 */
/* @0x19d2f4 str r3, [r5, #0x14] */
/* @0x19d2f8 cmp r4, #0 */
/* @0x19d2fc popeq {r4, r5, r6, pc} */
/* @0x19d300 ldrb r3, [r4] */
/* @0x19d304 cmp r3, #0 */
/* @0x19d308 popeq {r4, r5, r6, pc} */
/* @0x19d30c mov r0, r4 */
/* @0x19d310 bl 0xb6538 <strlen@plt> */
/* @0x19d314 mov r3, #1 */
/* @0x19d318 ldr r1, [pc, #0x24] */
/* @0x19d31c mov r2, #248 */
/* @0x19d320 add r1, pc, r1 */
/* @0x19d324 add r6, r0, r3 */
/* @0x19d328 mov r0, r6 */
/* @0x19d32c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19d330 mov r2, r6 */
/* @0x19d334 mov r1, r4 */
/* @0x19d338 str r0, [r5, #0x14] */
/* @0x19d33c pop {r4, r5, r6, lr} */
/* @0x19d340 b 0xb65bc <memcpy@plt> */
/* @0x19d344 andseq pc, r10, r0, asr #21 */

/* ── FUNC 0x19d348 · CObjectGM::SetNameRef(char*) · size=36 · insn=9 */
/* @0x19d348 push {r3, r4, r5, lr} */
/* @0x19d34c mov r4, r0 */
/* @0x19d350 ldr r0, [r0, #0x14] */
/* @0x19d354 mov r5, r1 */
/* @0x19d358 cmp r0, #0 */
/* @0x19d35c beq 0x19d364 <_ZN9CObjectGM10SetNameRefEPc+0x1c> */
/* @0x19d360 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d364 str r5, [r4, #0x14] */
/* @0x19d368 pop {r3, r4, r5, pc} */

/* ── FUNC 0x19d36c · CObjectGM::ClearInstanceInfo() · size=108 · insn=27 */
/* @0x19d36c push {r3, r4, r5, lr} */
/* @0x19d370 mov r5, r0 */
/* @0x19d374 ldr r0, [r0, #0xc4] */
/* @0x19d378 cmp r0, #0 */
/* @0x19d37c beq 0x19d394 <_ZN9CObjectGM17ClearInstanceInfoEv+0x28> */
/* @0x19d380 ldr r4, [r0] */
/* @0x19d384 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d388 cmp r4, #0 */
/* @0x19d38c mov r0, r4 */
/* @0x19d390 bne 0x19d380 <_ZN9CObjectGM17ClearInstanceInfoEv+0x14> */
/* @0x19d394 ldr r0, [r5, #0xd0] */
/* @0x19d398 mov r3, #0 */
/* @0x19d39c str r3, [r5, #0xcc] */
/* @0x19d3a0 cmp r0, r3 */
/* @0x19d3a4 str r3, [r5, #0xc8] */
/* @0x19d3a8 str r3, [r5, #0xc4] */
/* @0x19d3ac beq 0x19d3c4 <_ZN9CObjectGM17ClearInstanceInfoEv+0x58> */
/* @0x19d3b0 ldr r4, [r0] */
/* @0x19d3b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d3b8 cmp r4, #0 */
/* @0x19d3bc mov r0, r4 */
/* @0x19d3c0 bne 0x19d3b0 <_ZN9CObjectGM17ClearInstanceInfoEv+0x44> */
/* @0x19d3c4 mov r3, #0 */
/* @0x19d3c8 str r3, [r5, #0xd8] */
/* @0x19d3cc str r3, [r5, #0xd4] */
/* @0x19d3d0 str r3, [r5, #0xd0] */
/* @0x19d3d4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x19d3d8 · CObjectGM::Clear() · size=284 · insn=71 */
/* @0x19d3d8 push {r4, r5, r6, r7, r8, lr} */
/* @0x19d3dc mov r8, r0 */
/* @0x19d3e0 ldr r0, [r0, #0x14] */
/* @0x19d3e4 mov r4, #0 */
/* @0x19d3e8 mvn r3, #0 */
/* @0x19d3ec mov r2, #18 */
/* @0x19d3f0 cmp r0, r4 */
/* @0x19d3f4 str r2, [r8] */
/* @0x19d3f8 str r3, [r8, #0x4] */
/* @0x19d3fc str r3, [r8, #0xc] */
/* @0x19d400 str r3, [r8, #0x10] */
/* @0x19d404 str r4, [r8, #0x8] */
/* @0x19d408 str r4, [r8, #0x48] */
/* @0x19d40c beq 0x19d418 <_ZN9CObjectGM5ClearEv+0x40> */
/* @0x19d410 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d414 str r4, [r8, #0x14] */
/* @0x19d418 mov r7, #0 */
/* @0x19d41c mov r5, r8 */
/* @0x19d420 mov r6, r7 */
/* @0x19d424 ldr r2, [r5, #0x4c] */
/* @0x19d428 ldr r1, [r5, #0x50] */
/* @0x19d42c cmp r2, #0 */
/* @0x19d430 movgt r4, #0 */
/* @0x19d434 ble 0x19d470 <_ZN9CObjectGM5ClearEv+0x98> */
/* @0x19d438 ldr r3, [r1, r4, lsl #2] */
/* @0x19d43c cmp r3, #0 */
/* @0x19d440 mov r0, r3 */
/* @0x19d444 beq 0x19d464 <_ZN9CObjectGM5ClearEv+0x8c> */
/* @0x19d448 ldr r3, [r3] */
/* @0x19d44c ldr r3, [r3, #0x4] */
/* @0x19d450 blx r3 */
/* @0x19d454 ldr r3, [r5, #0x50] */
/* @0x19d458 str r6, [r3, r4, lsl #2] */
/* @0x19d45c ldr r1, [r5, #0x50] */
/* @0x19d460 ldr r2, [r5, #0x4c] */
/* @0x19d464 add r4, r4, #1 */
/* @0x19d468 cmp r2, r4 */
/* @0x19d46c bgt 0x19d438 <_ZN9CObjectGM5ClearEv+0x60> */
/* @0x19d470 mov r0, r1 */
/* @0x19d474 add r7, r7, #1 */
/* @0x19d478 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d47c cmp r7, #15 */
/* @0x19d480 str r6, [r5, #0x50] */
/* @0x19d484 add r5, r5, #8 */
/* @0x19d488 str r6, [r5, #0x44] */
/* @0x19d48c bne 0x19d424 <_ZN9CObjectGM5ClearEv+0x4c> */
/* @0x19d490 ldr r0, [r8, #0xc4] */
/* @0x19d494 cmp r0, #0 */
/* @0x19d498 beq 0x19d4b0 <_ZN9CObjectGM5ClearEv+0xd8> */
/* @0x19d49c ldr r4, [r0] */
/* @0x19d4a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d4a4 cmp r4, #0 */
/* @0x19d4a8 mov r0, r4 */
/* @0x19d4ac bne 0x19d49c <_ZN9CObjectGM5ClearEv+0xc4> */
/* @0x19d4b0 ldr r0, [r8, #0xd0] */
/* @0x19d4b4 mov r3, #0 */
/* @0x19d4b8 str r3, [r8, #0xcc] */
/* @0x19d4bc cmp r0, r3 */
/* @0x19d4c0 str r3, [r8, #0xc8] */
/* @0x19d4c4 str r3, [r8, #0xc4] */
/* @0x19d4c8 beq 0x19d4e0 <_ZN9CObjectGM5ClearEv+0x108> */
/* @0x19d4cc ldr r4, [r0] */
/* @0x19d4d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d4d4 cmp r4, #0 */
/* @0x19d4d8 mov r0, r4 */
/* @0x19d4dc bne 0x19d4cc <_ZN9CObjectGM5ClearEv+0xf4> */
/* @0x19d4e0 mov r3, #0 */
/* @0x19d4e4 str r3, [r8, #0xd8] */
/* @0x19d4e8 str r3, [r8, #0xd4] */
/* @0x19d4ec str r3, [r8, #0xd0] */
/* @0x19d4f0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x19d4f4 · CObjectGM::CObjectGM(int) · size=100 · insn=25 */
/* @0x19d4f4 push {r4, r5, r6, lr} */
/* @0x19d4f8 mov r5, r0 */
/* @0x19d4fc mov r0, #0 */
/* @0x19d500 mov r6, r1 */
/* @0x19d504 mov r3, r5 */
/* @0x19d508 mov r2, r0 */
/* @0x19d50c mov r4, #15 */
/* @0x19d510 str r0, [r5, #0xc8] */
/* @0x19d514 str r0, [r5, #0xc4] */
/* @0x19d518 str r0, [r5, #0xcc] */
/* @0x19d51c str r0, [r5, #0xd4] */
/* @0x19d520 str r0, [r5, #0xd0] */
/* @0x19d524 str r0, [r5, #0xd8] */
/* @0x19d528 str r0, [r5, #0x14] */
/* @0x19d52c subs r4, r4, #1 */
/* @0x19d530 str r2, [r3, #0x50] */
/* @0x19d534 str r2, [r3, #0x4c] */
/* @0x19d538 add r3, r3, #8 */
/* @0x19d53c bne 0x19d52c <_ZN9CObjectGMC2Ei+0x38> */
/* @0x19d540 mov r0, r5 */
/* @0x19d544 bl 0x19d3d8 <_ZN9CObjectGM5ClearEv> */
/* @0x19d548 str r6, [r5, #0x18] */
/* @0x19d54c str r4, [r5, #0x48] */
/* @0x19d550 mov r0, r5 */
/* @0x19d554 pop {r4, r5, r6, pc} */

/* ── FUNC 0x19d4f4 · CObjectGM::CObjectGM(int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x19d558 · CObjectGM::~CObjectGM() · size=180 · insn=45 */
/* @0x19d558 push {r4, r5, r6, lr} */
/* @0x19d55c mov r6, r0 */
/* @0x19d560 bl 0x19d3d8 <_ZN9CObjectGM5ClearEv> */
/* @0x19d564 ldr r4, [r6, #0xd0] */
/* @0x19d568 cmp r4, #0 */
/* @0x19d56c beq 0x19d5a4 <_ZN9CObjectGMD2Ev+0x4c> */
/* @0x19d570 ldr r3, [r4, #0x8] */
/* @0x19d574 ldr r5, [r4] */
/* @0x19d578 cmp r3, #0 */
/* @0x19d57c mov r0, r3 */
/* @0x19d580 beq 0x19d590 <_ZN9CObjectGMD2Ev+0x38> */
/* @0x19d584 ldr r3, [r3] */
/* @0x19d588 ldr r3, [r3, #0x4] */
/* @0x19d58c blx r3 */
/* @0x19d590 mov r0, r4 */
/* @0x19d594 mov r4, r5 */
/* @0x19d598 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d59c cmp r5, #0 */
/* @0x19d5a0 bne 0x19d570 <_ZN9CObjectGMD2Ev+0x18> */
/* @0x19d5a4 ldr r4, [r6, #0xc4] */
/* @0x19d5a8 mov r3, #0 */
/* @0x19d5ac str r3, [r6, #0xd8] */
/* @0x19d5b0 cmp r4, r3 */
/* @0x19d5b4 str r3, [r6, #0xd4] */
/* @0x19d5b8 str r3, [r6, #0xd0] */
/* @0x19d5bc beq 0x19d5f4 <_ZN9CObjectGMD2Ev+0x9c> */
/* @0x19d5c0 ldr r3, [r4, #0x8] */
/* @0x19d5c4 ldr r5, [r4] */
/* @0x19d5c8 cmp r3, #0 */
/* @0x19d5cc mov r0, r3 */
/* @0x19d5d0 beq 0x19d5e0 <_ZN9CObjectGMD2Ev+0x88> */
/* @0x19d5d4 ldr r3, [r3] */
/* @0x19d5d8 ldr r3, [r3, #0x4] */
/* @0x19d5dc blx r3 */
/* @0x19d5e0 mov r0, r4 */
/* @0x19d5e4 mov r4, r5 */
/* @0x19d5e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19d5ec cmp r5, #0 */
/* @0x19d5f0 bne 0x19d5c0 <_ZN9CObjectGMD2Ev+0x68> */
/* @0x19d5f4 mov r3, #0 */
/* @0x19d5f8 mov r0, r6 */
/* @0x19d5fc str r3, [r6, #0xcc] */
/* @0x19d600 str r3, [r6, #0xc8] */
/* @0x19d604 str r3, [r6, #0xc4] */
/* @0x19d608 pop {r4, r5, r6, pc} */

/* ── FUNC 0x19d558 · CObjectGM::~CObjectGM() · alias of the symbol above · insn=0 */

/* ── FUNC 0x19d60c · CObjectGM::YYCreateEvent(int, int) · size=124 · insn=31 */
/* @0x19d60c push {r4, r5, r6, r7, r8, lr} */
/* @0x19d610 add r8, r0, r1, lsl #3 */
/* @0x19d614 mov r7, r2 */
/* @0x19d618 ldr r4, [r8, #0x4c] */
/* @0x19d61c cmp r4, r2 */
/* @0x19d620 ble 0x19d630 <_ZN9CObjectGM13YYCreateEventEii+0x24> */
/* @0x19d624 ldr r3, [r8, #0x50] */
/* @0x19d628 ldr r0, [r3, r7, lsl #2] */
/* @0x19d62c pop {r4, r5, r6, r7, r8, pc} */
/* @0x19d630 add r6, r2, #1 */
/* @0x19d634 ldr r2, [pc, #0x48] */
/* @0x19d638 add r0, r0, r1, lsl #3 */
/* @0x19d63c lsl r5, r4, #2 */
/* @0x19d640 add r0, r0, #80 */
/* @0x19d644 lsl r1, r6, #2 */
/* @0x19d648 add r2, pc, r2 */
/* @0x19d64c movw r3, #0x152 */
/* @0x19d650 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19d654 str r6, [r8, #0x4c] */
/* @0x19d658 mov r0, #12 */
/* @0x19d65c add r4, r4, #1 */
/* @0x19d660 bl 0x27c524 <_Znwj> */
/* @0x19d664 mov r6, r0 */
/* @0x19d668 bl 0xf2d0c <_ZN6CEventC2Ev> */
/* @0x19d66c ldr r3, [r8, #0x50] */
/* @0x19d670 cmp r7, r4 */
/* @0x19d674 str r6, [r3, r5] */
/* @0x19d678 add r5, r5, #4 */
/* @0x19d67c bge 0x19d658 <_ZN9CObjectGM13YYCreateEventEii+0x4c> */
/* @0x19d680 b 0x19d624 <_ZN9CObjectGM13YYCreateEventEii+0x18> */
/* @0x19d684 mulseq r10, r8, r7 */

/* ── FUNC 0x19d688 · CObjectGM::LoadFromChunk(YYObject*, unsigned char*) · size=876 · insn=219 */
/* @0x19d688 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19d68c sub sp, sp, #28 */
/* @0x19d690 mov r4, r1 */
/* @0x19d694 mov r5, r0 */
/* @0x19d698 str r2, [sp, #0x4] */
/* @0x19d69c bl 0x19d3d8 <_ZN9CObjectGM5ClearEv> */
/* @0x19d6a0 ldr r3, [r4, #0x4] */
/* @0x19d6a4 ldr r11, [pc, #0x334] */
/* @0x19d6a8 tst r3, #1879048192 */
/* @0x19d6ac add r11, pc, r11 */
/* @0x19d6b0 strne r3, [r5, #0x4] */
/* @0x19d6b4 bne 0x19d6d8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x50> */
/* @0x19d6b8 ldr r2, [pc, #0x324] */
/* @0x19d6bc and r1, r3, #-2147483648 */
/* @0x19d6c0 bic r3, r3, #-2147483648 */
/* @0x19d6c4 ldr r2, [r11, r2] */
/* @0x19d6c8 str r3, [r5, #0x4] */
/* @0x19d6cc ldr r3, [r2] */
/* @0x19d6d0 orr r3, r1, r3 */
/* @0x19d6d4 str r3, [r2] */
/* @0x19d6d8 ldr r3, [r4, #0xc] */
/* @0x19d6dc ldr r2, [r5] */
/* @0x19d6e0 cmp r3, #0 */
/* @0x19d6e4 orrne r2, r2, #1 */
/* @0x19d6e8 biceq r2, r2, #1 */
/* @0x19d6ec str r2, [r5] */
/* @0x19d6f0 ldr r3, [r4, #0x8] */
/* @0x19d6f4 cmp r3, #0 */
/* @0x19d6f8 orrne r2, r2, #2 */
/* @0x19d6fc biceq r2, r2, #2 */
/* @0x19d700 str r2, [r5] */
/* @0x19d704 mov r1, r2 */
/* @0x19d708 ldr r2, [r4, #0x14] */
/* @0x19d70c ldr r3, [r4, #0x10] */
/* @0x19d710 cmp r2, #0 */
/* @0x19d714 ldr r2, [pc, #0x2cc] */
/* @0x19d718 orrne r1, r1, #4 */
/* @0x19d71c biceq r1, r1, #4 */
/* @0x19d720 str r1, [r5] */
/* @0x19d724 ldr r0, [r4, #0x18] */
/* @0x19d728 ldr r1, [r4, #0x1c] */
/* @0x19d72c str r3, [r5, #0x8] */
/* @0x19d730 mov r3, #0 */
/* @0x19d734 str r0, [r5, #0xc] */
/* @0x19d738 str r1, [r5, #0x10] */
/* @0x19d73c strb r3, [r5, #0x1c] */
/* @0x19d740 str r3, [r5, #0x44] */
/* @0x19d744 str r3, [r5, #0x40] */
/* @0x19d748 ldr r2, [r11, r2] */
/* @0x19d74c ldr r2, [r2] */
/* @0x19d750 cmp r2, #5 */
/* @0x19d754 addle r4, r4, #32 */
/* @0x19d758 strle r4, [sp, #0x14] */
/* @0x19d75c ble 0x19d830 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1a8> */
/* @0x19d760 ldr lr, [r4, #0x20] */
/* @0x19d764 ldr r12, [r4, #0x24] */
/* @0x19d768 adds lr, lr, #0 */
/* @0x19d76c ldr r8, [r4, #0x2c] */
/* @0x19d770 ldr r7, [r4, #0x30] */
/* @0x19d774 movne lr, #1 */
/* @0x19d778 adds r12, r12, #0 */
/* @0x19d77c ldr r0, [r4, #0x28] */
/* @0x19d780 movne r12, #1 */
/* @0x19d784 cmp r2, #8 */
/* @0x19d788 ldr r2, [r4, #0x38] */
/* @0x19d78c ldr r1, [r4, #0x34] */
/* @0x19d790 ldr r6, [r4, #0x40] */
/* @0x19d794 str r2, [r5, #0x30] */
/* @0x19d798 ldr r2, [r4, #0x3c] */
/* @0x19d79c strb lr, [r5, #0x1c] */
/* @0x19d7a0 str r8, [r5, #0x28] */
/* @0x19d7a4 strb r12, [r5, #0x1d] */
/* @0x19d7a8 str r7, [r5, #0x2c] */
/* @0x19d7ac str r0, [r5, #0x20] */
/* @0x19d7b0 str r1, [r5, #0x24] */
/* @0x19d7b4 str r6, [r5, #0x40] */
/* @0x19d7b8 str r2, [r5, #0x34] */
/* @0x19d7bc bgt 0x19d9ac <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x324> */
/* @0x19d7c0 add r4, r4, #68 */
/* @0x19d7c4 strb r3, [r5, #0x3d] */
/* @0x19d7c8 movw r2, #0xcccd */
/* @0x19d7cc mov r3, #1 */
/* @0x19d7d0 movt r2, #0x3e4c */
/* @0x19d7d4 str r4, [sp, #0x14] */
/* @0x19d7d8 str r2, [r5, #0x38] */
/* @0x19d7dc strb r3, [r5, #0x3c] */
/* @0x19d7e0 lsl r4, r6, #3 */
/* @0x19d7e4 mov r0, r4 */
/* @0x19d7e8 bl 0xb6544 <malloc@plt> */
/* @0x19d7ec cmp r6, #0 */
/* @0x19d7f0 str r0, [r5, #0x44] */
/* @0x19d7f4 ble 0x19d830 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1a8> */
/* @0x19d7f8 ldr r2, [sp, #0x14] */
/* @0x19d7fc mov r1, #0 */
/* @0x19d800 ldr r3, [r2] */
/* @0x19d804 add r1, r1, #1 */
/* @0x19d808 cmp r1, r6 */
/* @0x19d80c add r2, r2, #8 */
/* @0x19d810 add r0, r0, #8 */
/* @0x19d814 str r3, [r0, #-0x8] */
/* @0x19d818 ldr r3, [r2, #-0x4] */
/* @0x19d81c str r3, [r0, #-0x4] */
/* @0x19d820 bne 0x19d800 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x178> */
/* @0x19d824 ldr r2, [sp, #0x14] */
/* @0x19d828 add r2, r2, r4 */
/* @0x19d82c str r2, [sp, #0x14] */
/* @0x19d830 ldr r2, [sp, #0x14] */
/* @0x19d834 ldr r3, [r2] */
/* @0x19d838 cmp r3, #0 */
/* @0x19d83c ble 0x19d9a0 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x318> */
/* @0x19d840 ldr r2, [pc, #0x1a4] */
/* @0x19d844 add r5, r5, #80 */
/* @0x19d848 mov r10, #0 */
/* @0x19d84c add r2, pc, r2 */
/* @0x19d850 str r2, [sp, #0xc] */
/* @0x19d854 mov r2, #0 */
/* @0x19d858 str r2, [sp, #0x8] */
/* @0x19d85c ldr r2, [sp, #0x14] */
/* @0x19d860 str r2, [sp, #0x10] */
/* @0x19d864 ldr r2, [sp, #0x10] */
/* @0x19d868 ldr r8, [r2, #0x4]! */
/* @0x19d86c cmp r8, #0 */
/* @0x19d870 str r2, [sp, #0x10] */
/* @0x19d874 moveq r7, #4 */
/* @0x19d878 beq 0x19d890 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x208> */
/* @0x19d87c ldr r2, [pc, #0x16c] */
/* @0x19d880 ldr r2, [r11, r2] */
/* @0x19d884 ldr r2, [r2] */
/* @0x19d888 add r8, r2, r8 */
/* @0x19d88c add r7, r8, #4 */
/* @0x19d890 ldr r2, [r8] */
/* @0x19d894 cmp r2, #0 */
/* @0x19d898 subgt r7, r7, #4 */
/* @0x19d89c movgt r9, #0 */
/* @0x19d8a0 bgt 0x19d8d4 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x24c> */
/* @0x19d8a4 b 0x19d988 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x300> */
/* @0x19d8a8 ldr r3, [r5] */
/* @0x19d8ac ldr r0, [r3, r1, lsl #2] */
/* @0x19d8b0 cmp r0, #0 */
/* @0x19d8b4 beq 0x19d958 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2d0> */
/* @0x19d8b8 add r1, r6, #4 */
/* @0x19d8bc ldr r2, [sp, #0x4] */
/* @0x19d8c0 bl 0xf2d84 <_ZN6CEvent13LoadFromChunkEP7YYEventPh> */
/* @0x19d8c4 ldr r3, [r8] */
/* @0x19d8c8 add r9, r9, #1 */
/* @0x19d8cc cmp r3, r9 */
/* @0x19d8d0 ble 0x19d980 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2f8> */
/* @0x19d8d4 ldr r6, [r7, #0x4]! */
/* @0x19d8d8 cmp r6, #0 */
/* @0x19d8dc ldrne r3, [pc, #0x10c] */
/* @0x19d8e0 ldrne r3, [r11, r3] */
/* @0x19d8e4 ldrne r3, [r3] */
/* @0x19d8e8 addne r6, r3, r6 */
/* @0x19d8ec ldr r1, [r6] */
/* @0x19d8f0 ldr r4, [r5, #-0x4] */
/* @0x19d8f4 cmp r1, r4 */
/* @0x19d8f8 blt 0x19d8a8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x220> */
/* @0x19d8fc add r1, r1, #1 */
/* @0x19d900 movw r3, #0x1b6 */
/* @0x19d904 mov r0, r5 */
/* @0x19d908 ldr r2, [sp, #0xc] */
/* @0x19d90c lsl r1, r1, #2 */
/* @0x19d910 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19d914 ldr r1, [r6] */
/* @0x19d918 cmp r4, r1 */
/* @0x19d91c add r3, r1, #1 */
/* @0x19d920 str r3, [r5, #-0x4] */
/* @0x19d924 bge 0x19d8a8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x220> */
/* @0x19d928 lsl r3, r4, #2 */
/* @0x19d92c add r4, r4, #1 */
/* @0x19d930 ldr r2, [r5] */
/* @0x19d934 cmp r4, r1 */
/* @0x19d938 str r10, [r2, r3] */
/* @0x19d93c add r3, r3, #4 */
/* @0x19d940 bne 0x19d92c <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2a4> */
/* @0x19d944 ldr r3, [r5] */
/* @0x19d948 mov r1, r4 */
/* @0x19d94c ldr r0, [r3, r1, lsl #2] */
/* @0x19d950 cmp r0, #0 */
/* @0x19d954 bne 0x19d8b8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x230> */
/* @0x19d958 mov r0, #12 */
/* @0x19d95c bl 0x27c524 <_Znwj> */
/* @0x19d960 mov r4, r0 */
/* @0x19d964 bl 0xf2d0c <_ZN6CEventC2Ev> */
/* @0x19d968 ldr r3, [r6] */
/* @0x19d96c ldr r2, [r5] */
/* @0x19d970 str r4, [r2, r3, lsl #2] */
/* @0x19d974 ldr r2, [r5] */
/* @0x19d978 ldr r0, [r2, r3, lsl #2] */
/* @0x19d97c b 0x19d8b8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x230> */
/* @0x19d980 ldr r2, [sp, #0x14] */
/* @0x19d984 ldr r3, [r2] */
/* @0x19d988 ldr r2, [sp, #0x8] */
/* @0x19d98c add r5, r5, #8 */
/* @0x19d990 add r2, r2, #1 */
/* @0x19d994 str r2, [sp, #0x8] */
/* @0x19d998 cmp r3, r2 */
/* @0x19d99c bgt 0x19d864 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1dc> */
/* @0x19d9a0 mov r0, #1 */
/* @0x19d9a4 add sp, sp, #28 */
/* @0x19d9a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19d9ac ldr r2, [r4, #0x48] */
/* @0x19d9b0 add r4, r4, #80 */
/* @0x19d9b4 ldr r3, [r4, #-0x4] */
/* @0x19d9b8 adds r2, r2, #0 */
/* @0x19d9bc ldr r1, [r4, #-0xc] */
/* @0x19d9c0 str r4, [sp, #0x14] */
/* @0x19d9c4 movne r2, #1 */
/* @0x19d9c8 adds r3, r3, #0 */
/* @0x19d9cc str r1, [r5, #0x38] */
/* @0x19d9d0 movne r3, #1 */
/* @0x19d9d4 strb r2, [r5, #0x3c] */
/* @0x19d9d8 strb r3, [r5, #0x3d] */
/* @0x19d9dc b 0x19d7e0 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x158> */
/* @0x19d9e0 eoreq r4, r5, r4, lsr #11 */
/* @0x19d9e4 .word 0xffffe798 */
/* @0x19d9e8 .word 0xffffea88 */
/* @0x19d9ec mulseq r10, r4, r5 */
/* @0x19d9f0 .word 0xffffbcf4 */

/* ── FUNC 0x19d9f4 · CObjectGM::Compile() · size=128 · insn=32 */
/* @0x19d9f4 push {r4, r5, r6, r7, r8, lr} */
/* @0x19d9f8 mov r5, r0 */
/* @0x19d9fc ldr r8, [pc, #0x68] */
/* @0x19da00 mov r7, #0 */
/* @0x19da04 ldr r8, [pc, r8] */
/* @0x19da08 ldr r2, [r5, #0x4c] */
/* @0x19da0c str r7, [r8] */
/* @0x19da10 cmp r2, #0 */
/* @0x19da14 ble 0x19da54 <_ZN9CObjectGM7CompileEv+0x60> */
/* @0x19da18 ldr r6, [pc, #0x50] */
/* @0x19da1c mov r4, #0 */
/* @0x19da20 ldr r6, [pc, r6] */
/* @0x19da24 ldr r3, [r5, #0x50] */
/* @0x19da28 str r4, [r6] */
/* @0x19da2c ldr r0, [r3, r4, lsl #2] */
/* @0x19da30 cmp r0, #0 */
/* @0x19da34 beq 0x19da48 <_ZN9CObjectGM7CompileEv+0x54> */
/* @0x19da38 bl 0xf2e10 <_ZN6CEvent7CompileEv> */
/* @0x19da3c cmp r0, #0 */
/* @0x19da40 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x19da44 ldr r2, [r5, #0x4c] */
/* @0x19da48 add r4, r4, #1 */
/* @0x19da4c cmp r2, r4 */
/* @0x19da50 bgt 0x19da24 <_ZN9CObjectGM7CompileEv+0x30> */
/* @0x19da54 add r7, r7, #1 */
/* @0x19da58 add r5, r5, #8 */
/* @0x19da5c cmp r7, #15 */
/* @0x19da60 bne 0x19da08 <_ZN9CObjectGM7CompileEv+0x14> */
/* @0x19da64 mov r0, #1 */
/* @0x19da68 pop {r4, r5, r6, r7, r8, pc} */
/* @0x19da6c eoreq r0, r5, r12, lsr #7 */
/* @0x19da70 mlaeq r5, r4, r3, r0 */

/* ── FUNC 0x19da74 · CObjectGM::GetEventDirect(int, int) · size=128 · insn=32 */
/* @0x19da74 cmp r1, #14 */
/* @0x19da78 push {r4, r5, r6, lr} */
/* @0x19da7c movls r3, #0 */
/* @0x19da80 movhi r3, #1 */
/* @0x19da84 mov r5, r1 */
/* @0x19da88 orrs r3, r3, r2, lsr #31 */
/* @0x19da8c mov r4, r2 */
/* @0x19da90 mov r6, r0 */
/* @0x19da94 bne 0x19dac8 <_ZN9CObjectGM14GetEventDirectEii+0x54> */
/* @0x19da98 add r5, r6, r5, lsl #3 */
/* @0x19da9c ldr r3, [r5, #0x4c] */
/* @0x19daa0 cmp r4, r3 */
/* @0x19daa4 bge 0x19dae8 <_ZN9CObjectGM14GetEventDirectEii+0x74> */
/* @0x19daa8 ldr r3, [r5, #0x50] */
/* @0x19daac ldr r0, [r3, r4, lsl #2] */
/* @0x19dab0 cmp r0, #0 */
/* @0x19dab4 popeq {r4, r5, r6, pc} */
/* @0x19dab8 ldr r3, [r0, #0x8] */
/* @0x19dabc cmp r3, #0 */
/* @0x19dac0 moveq r0, #0 */
/* @0x19dac4 pop {r4, r5, r6, pc} */
/* @0x19dac8 ldr r0, [pc, #0x20] */
/* @0x19dacc add r5, r6, r5, lsl #3 */
/* @0x19dad0 mov r1, #1 */
/* @0x19dad4 add r0, pc, r0 */
/* @0x19dad8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x19dadc ldr r3, [r5, #0x4c] */
/* @0x19dae0 cmp r4, r3 */
/* @0x19dae4 blt 0x19daa8 <_ZN9CObjectGM14GetEventDirectEii+0x34> */
/* @0x19dae8 mov r0, #0 */
/* @0x19daec pop {r4, r5, r6, pc} */
/* @0x19daf0 andseq pc, r10, r4, asr #6 */

/* ── FUNC 0x19daf4 · CObjectGM::GetEventRecursive(int, int) · size=488 · insn=122 */
/* @0x19daf4 push {r3, r4, r5, r6, r7, lr} */
/* @0x19daf8 subs r5, r0, #0 */
/* @0x19dafc mov r7, r1 */
/* @0x19db00 mov r6, r2 */
/* @0x19db04 beq 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48> */
/* @0x19db08 mov r4, r5 */
/* @0x19db0c mov r0, r4 */
/* @0x19db10 mov r1, r7 */
/* @0x19db14 mov r2, r6 */
/* @0x19db18 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii> */
/* @0x19db1c cmp r0, #0 */
/* @0x19db20 popne {r3, r4, r5, r6, r7, pc} */
/* @0x19db24 ldr r0, [r4, #0xc] */
/* @0x19db28 cmp r0, #0 */
/* @0x19db2c blt 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48> */
/* @0x19db30 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19db34 cmp r0, #0 */
/* @0x19db38 bne 0x19db4c <_ZN9CObjectGM17GetEventRecursiveEii+0x58> */
/* @0x19db3c cmp r7, #4 */
/* @0x19db40 beq 0x19dba8 <_ZN9CObjectGM17GetEventRecursiveEii+0xb4> */
/* @0x19db44 mov r0, #0 */
/* @0x19db48 pop {r3, r4, r5, r6, r7, pc} */
/* @0x19db4c ldr r3, [pc, #0x180] */
/* @0x19db50 ldr r4, [r4, #0xc] */
/* @0x19db54 ldr r3, [pc, r3] */
/* @0x19db58 ldr r3, [r3] */
/* @0x19db5c ldr r2, [r3, #0x4] */
/* @0x19db60 ldr r3, [r3] */
/* @0x19db64 and r2, r4, r2 */
/* @0x19db68 ldr r3, [r3, r2, lsl #3] */
/* @0x19db6c cmp r3, #0 */
/* @0x19db70 beq 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48> */
/* @0x19db74 ldr r2, [r3, #0x8] */
/* @0x19db78 cmp r4, r2 */
/* @0x19db7c beq 0x19db98 <_ZN9CObjectGM17GetEventRecursiveEii+0xa4> */
/* @0x19db80 ldr r3, [r3, #0x4] */
/* @0x19db84 cmp r3, #0 */
/* @0x19db88 beq 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48> */
/* @0x19db8c ldr r12, [r3, #0x8] */
/* @0x19db90 cmp r4, r12 */
/* @0x19db94 bne 0x19db80 <_ZN9CObjectGM17GetEventRecursiveEii+0x8c> */
/* @0x19db98 ldr r4, [r3, #0xc] */
/* @0x19db9c cmp r4, #0 */
/* @0x19dba0 bne 0x19db0c <_ZN9CObjectGM17GetEventRecursiveEii+0x18> */
/* @0x19dba4 b 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48> */
/* @0x19dba8 mov r0, r6 */
/* @0x19dbac bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19dbb0 cmp r0, #0 */
/* @0x19dbb4 beq 0x19db44 <_ZN9CObjectGM17GetEventRecursiveEii+0x50> */
/* @0x19dbb8 ldr r7, [pc, #0x118] */
/* @0x19dbbc ldr r7, [pc, r7] */
/* @0x19dbc0 ldr r3, [r7] */
/* @0x19dbc4 ldr r2, [r3, #0x4] */
/* @0x19dbc8 ldr r3, [r3] */
/* @0x19dbcc and r2, r6, r2 */
/* @0x19dbd0 ldr r3, [r3, r2, lsl #3] */
/* @0x19dbd4 cmp r3, #0 */
/* @0x19dbd8 bne 0x19dbec <_ZN9CObjectGM17GetEventRecursiveEii+0xf8> */
/* @0x19dbdc b 0x19dbfc <_ZN9CObjectGM17GetEventRecursiveEii+0x108> */
/* @0x19dbe0 ldr r3, [r3, #0x4] */
/* @0x19dbe4 cmp r3, #0 */
/* @0x19dbe8 beq 0x19dbfc <_ZN9CObjectGM17GetEventRecursiveEii+0x108> */
/* @0x19dbec ldr r2, [r3, #0x8] */
/* @0x19dbf0 cmp r6, r2 */
/* @0x19dbf4 bne 0x19dbe0 <_ZN9CObjectGM17GetEventRecursiveEii+0xec> */
/* @0x19dbf8 ldr r3, [r3, #0xc] */
/* @0x19dbfc ldr r6, [r3, #0xc] */
/* @0x19dc00 cmp r6, #0 */
/* @0x19dc04 blt 0x19db44 <_ZN9CObjectGM17GetEventRecursiveEii+0x50> */
/* @0x19dc08 mov r0, r6 */
/* @0x19dc0c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19dc10 cmp r0, #0 */
/* @0x19dc14 beq 0x19db44 <_ZN9CObjectGM17GetEventRecursiveEii+0x50> */
/* @0x19dc18 cmp r5, #0 */
/* @0x19dc1c movne r4, r5 */
/* @0x19dc20 beq 0x19dc9c <_ZN9CObjectGM17GetEventRecursiveEii+0x1a8> */
/* @0x19dc24 mov r0, r4 */
/* @0x19dc28 mov r1, #4 */
/* @0x19dc2c mov r2, r6 */
/* @0x19dc30 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii> */
/* @0x19dc34 cmp r0, #0 */
/* @0x19dc38 popne {r3, r4, r5, r6, r7, pc} */
/* @0x19dc3c ldr r0, [r4, #0xc] */
/* @0x19dc40 cmp r0, #0 */
/* @0x19dc44 blt 0x19dc9c <_ZN9CObjectGM17GetEventRecursiveEii+0x1a8> */
/* @0x19dc48 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19dc4c cmp r0, #0 */
/* @0x19dc50 beq 0x19dc9c <_ZN9CObjectGM17GetEventRecursiveEii+0x1a8> */
/* @0x19dc54 ldr r3, [r7] */
/* @0x19dc58 ldr r12, [r4, #0xc] */
/* @0x19dc5c ldm r3, {r0, r2} */
/* @0x19dc60 and r3, r2, r12 */
/* @0x19dc64 ldr r3, [r0, r3, lsl #3] */
/* @0x19dc68 cmp r3, #0 */
/* @0x19dc6c bne 0x19dc80 <_ZN9CObjectGM17GetEventRecursiveEii+0x18c> */
/* @0x19dc70 b 0x19dca4 <_ZN9CObjectGM17GetEventRecursiveEii+0x1b0> */
/* @0x19dc74 ldr r3, [r3, #0x4] */
/* @0x19dc78 cmp r3, #0 */
/* @0x19dc7c beq 0x19dca4 <_ZN9CObjectGM17GetEventRecursiveEii+0x1b0> */
/* @0x19dc80 ldr r1, [r3, #0x8] */
/* @0x19dc84 cmp r12, r1 */
/* @0x19dc88 bne 0x19dc74 <_ZN9CObjectGM17GetEventRecursiveEii+0x180> */
/* @0x19dc8c ldr r4, [r3, #0xc] */
/* @0x19dc90 cmp r4, #0 */
/* @0x19dc94 bne 0x19dc24 <_ZN9CObjectGM17GetEventRecursiveEii+0x130> */
/* @0x19dc98 b 0x19dca4 <_ZN9CObjectGM17GetEventRecursiveEii+0x1b0> */
/* @0x19dc9c ldr r3, [r7] */
/* @0x19dca0 ldm r3, {r0, r2} */
/* @0x19dca4 and r2, r2, r6 */
/* @0x19dca8 ldr r3, [r0, r2, lsl #3] */
/* @0x19dcac cmp r3, #0 */
/* @0x19dcb0 bne 0x19dcc4 <_ZN9CObjectGM17GetEventRecursiveEii+0x1d0> */
/* @0x19dcb4 b 0x19dbfc <_ZN9CObjectGM17GetEventRecursiveEii+0x108> */
/* @0x19dcb8 ldr r3, [r3, #0x4] */
/* @0x19dcbc cmp r3, #0 */
/* @0x19dcc0 beq 0x19dbfc <_ZN9CObjectGM17GetEventRecursiveEii+0x108> */
/* @0x19dcc4 ldr r2, [r3, #0x8] */
/* @0x19dcc8 cmp r6, r2 */
/* @0x19dccc bne 0x19dcb8 <_ZN9CObjectGM17GetEventRecursiveEii+0x1c4> */
/* @0x19dcd0 b 0x19dbf8 <_ZN9CObjectGM17GetEventRecursiveEii+0x104> */
/* @0x19dcd4 eoreq r0, r5, r8, ror #1 */
/* @0x19dcd8 eoreq r0, r5, r0, lsl #1 */

/* ── FUNC 0x19dcdc · CObjectGM::HasEventRecursive(int, int) · size=212 · insn=53 */
/* @0x19dcdc push {r3, r4, r5, r6, r7, lr} */
/* @0x19dce0 lsl r6, r1, #3 */
/* @0x19dce4 lsl r7, r2, #2 */
/* @0x19dce8 mov r5, r2 */
/* @0x19dcec mov r4, r0 */
/* @0x19dcf0 add r3, r4, r6 */
/* @0x19dcf4 ldr r2, [r3, #0x4c] */
/* @0x19dcf8 cmp r2, r5 */
/* @0x19dcfc ble 0x19dd24 <_ZN9CObjectGM17HasEventRecursiveEii+0x48> */
/* @0x19dd00 ldr r3, [r3, #0x50] */
/* @0x19dd04 cmp r3, #0 */
/* @0x19dd08 beq 0x19dd24 <_ZN9CObjectGM17HasEventRecursiveEii+0x48> */
/* @0x19dd0c ldr r3, [r3, r7] */
/* @0x19dd10 cmp r3, #0 */
/* @0x19dd14 beq 0x19dd24 <_ZN9CObjectGM17HasEventRecursiveEii+0x48> */
/* @0x19dd18 ldr r3, [r3, #0x8] */
/* @0x19dd1c cmp r3, #0 */
/* @0x19dd20 bne 0x19dda4 <_ZN9CObjectGM17HasEventRecursiveEii+0xc8> */
/* @0x19dd24 ldr r0, [r4, #0xc] */
/* @0x19dd28 cmp r0, #0 */
/* @0x19dd2c blt 0x19dd9c <_ZN9CObjectGM17HasEventRecursiveEii+0xc0> */
/* @0x19dd30 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19dd34 cmp r0, #0 */
/* @0x19dd38 beq 0x19dd9c <_ZN9CObjectGM17HasEventRecursiveEii+0xc0> */
/* @0x19dd3c ldr r3, [pc, #0x68] */
/* @0x19dd40 ldr r12, [r4, #0xc] */
/* @0x19dd44 ldr r3, [pc, r3] */
/* @0x19dd48 ldr r3, [r3] */
/* @0x19dd4c ldr r2, [r3, #0x4] */
/* @0x19dd50 ldr r3, [r3] */
/* @0x19dd54 and r2, r12, r2 */
/* @0x19dd58 ldr r3, [r3, r2, lsl #3] */
/* @0x19dd5c cmp r3, #0 */
/* @0x19dd60 beq 0x19dd8c <_ZN9CObjectGM17HasEventRecursiveEii+0xb0> */
/* @0x19dd64 ldr r2, [r3, #0x8] */
/* @0x19dd68 cmp r12, r2 */
/* @0x19dd6c bne 0x19dd80 <_ZN9CObjectGM17HasEventRecursiveEii+0xa4> */
/* @0x19dd70 b 0x19dd94 <_ZN9CObjectGM17HasEventRecursiveEii+0xb8> */
/* @0x19dd74 ldr r0, [r3, #0x8] */
/* @0x19dd78 cmp r12, r0 */
/* @0x19dd7c beq 0x19dd94 <_ZN9CObjectGM17HasEventRecursiveEii+0xb8> */
/* @0x19dd80 ldr r3, [r3, #0x4] */
/* @0x19dd84 cmp r3, #0 */
/* @0x19dd88 bne 0x19dd74 <_ZN9CObjectGM17HasEventRecursiveEii+0x98> */
/* @0x19dd8c mov r4, r3 */
/* @0x19dd90 b 0x19dcf0 <_ZN9CObjectGM17HasEventRecursiveEii+0x14> */
/* @0x19dd94 ldr r4, [r3, #0xc] */
/* @0x19dd98 b 0x19dcf0 <_ZN9CObjectGM17HasEventRecursiveEii+0x14> */
/* @0x19dd9c mov r0, #0 */
/* @0x19dda0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x19dda4 mov r0, #1 */
/* @0x19dda8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x19ddac .word 0x0024fef8 */

/* ── FUNC 0x19ddb0 · CObjectGM::IsDecendentOf(int) · size=156 · insn=39 */
/* @0x19ddb0 push {r3, r4, r5, lr} */
/* @0x19ddb4 mov r4, r0 */
/* @0x19ddb8 mov r5, r1 */
/* @0x19ddbc ldr r0, [r4, #0xc] */
/* @0x19ddc0 cmp r0, #0 */
/* @0x19ddc4 blt 0x19de30 <_ZN9CObjectGM13IsDecendentOfEi+0x80> */
/* @0x19ddc8 cmp r0, r5 */
/* @0x19ddcc beq 0x19de40 <_ZN9CObjectGM13IsDecendentOfEi+0x90> */
/* @0x19ddd0 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19ddd4 cmp r0, #0 */
/* @0x19ddd8 beq 0x19de30 <_ZN9CObjectGM13IsDecendentOfEi+0x80> */
/* @0x19dddc ldr r3, [pc, #0x64] */
/* @0x19dde0 ldr r2, [r4, #0xc] */
/* @0x19dde4 ldr r3, [pc, r3] */
/* @0x19dde8 ldr r3, [r3] */
/* @0x19ddec ldr r1, [r3, #0x4] */
/* @0x19ddf0 ldr r3, [r3] */
/* @0x19ddf4 and r1, r2, r1 */
/* @0x19ddf8 ldr r0, [r3, r1, lsl #3] */
/* @0x19ddfc cmp r0, #0 */
/* @0x19de00 bne 0x19de14 <_ZN9CObjectGM13IsDecendentOfEi+0x64> */
/* @0x19de04 b 0x19de38 <_ZN9CObjectGM13IsDecendentOfEi+0x88> */
/* @0x19de08 ldr r0, [r0, #0x4] */
/* @0x19de0c cmp r0, #0 */
/* @0x19de10 beq 0x19de38 <_ZN9CObjectGM13IsDecendentOfEi+0x88> */
/* @0x19de14 ldr r3, [r0, #0x8] */
/* @0x19de18 cmp r2, r3 */
/* @0x19de1c bne 0x19de08 <_ZN9CObjectGM13IsDecendentOfEi+0x58> */
/* @0x19de20 ldr r4, [r0, #0xc] */
/* @0x19de24 ldr r0, [r4, #0xc] */
/* @0x19de28 cmp r0, #0 */
/* @0x19de2c bge 0x19ddc8 <_ZN9CObjectGM13IsDecendentOfEi+0x18> */
/* @0x19de30 mov r0, #0 */
/* @0x19de34 pop {r3, r4, r5, pc} */
/* @0x19de38 mov r4, r0 */
/* @0x19de3c b 0x19ddbc <_ZN9CObjectGM13IsDecendentOfEi+0xc> */
/* @0x19de40 mov r0, #1 */
/* @0x19de44 pop {r3, r4, r5, pc} */
/* @0x19de48 eoreq pc, r4, r8, asr lr */

/* ── FUNC 0x19de4c · WithObjIterator::operator*() · size=480 · insn=120 */
/* @0x19de4c push {r3, r4, r5, lr} */
/* @0x19de50 mov r4, r0 */
/* @0x19de54 ldr r3, [r0, #0x18] */
/* @0x19de58 add r3, r3, #2 */
/* @0x19de5c cmp r3, #5 */
/* @0x19de60 addls pc, pc, r3, lsl #2 */
/* @0x19de64 b 0x19ded0 <_ZN15WithObjIteratordeEv+0x84> */
/* @0x19de68 b 0x19dea8 <_ZN15WithObjIteratordeEv+0x5c> */
/* @0x19de6c b 0x19deb4 <_ZN15WithObjIteratordeEv+0x68> */
/* @0x19de70 b 0x19dec0 <_ZN15WithObjIteratordeEv+0x74> */
/* @0x19de74 b 0x19dedc <_ZN15WithObjIteratordeEv+0x90> */
/* @0x19de78 b 0x19df58 <_ZN15WithObjIteratordeEv+0x10c> */
/* @0x19de7c b 0x19de80 <_ZN15WithObjIteratordeEv+0x34> */
/* @0x19de80 ldr r5, [r0, #0x8] */
/* @0x19de84 cmp r5, #0 */
/* @0x19de88 beq 0x19ded0 <_ZN15WithObjIteratordeEv+0x84> */
/* @0x19de8c ldr r3, [r4, #0x14] */
/* @0x19de90 ldr r2, [r5, #0x7c] */
/* @0x19de94 cmp r2, r3 */
/* @0x19de98 mov r1, r3 */
/* @0x19de9c bne 0x19dff4 <_ZN15WithObjIteratordeEv+0x1a8> */
/* @0x19dea0 mov r0, r5 */
/* @0x19dea4 pop {r3, r4, r5, pc} */
/* @0x19dea8 ldr r5, [r0, #0x4] */
/* @0x19deac mov r0, r5 */
/* @0x19deb0 pop {r3, r4, r5, pc} */
/* @0x19deb4 ldr r5, [r0, #0x10] */
/* @0x19deb8 mov r0, r5 */
/* @0x19debc pop {r3, r4, r5, pc} */
/* @0x19dec0 ldr r3, [r0] */
/* @0x19dec4 cmp r3, #0 */
/* @0x19dec8 ldrne r5, [r3, #0x8] */
/* @0x19decc bne 0x19dea0 <_ZN15WithObjIteratordeEv+0x54> */
/* @0x19ded0 mov r5, #0 */
/* @0x19ded4 mov r0, r5 */
/* @0x19ded8 pop {r3, r4, r5, pc} */
/* @0x19dedc ldr r2, [pc, #0x13c] */
/* @0x19dee0 ldr r0, [r0, #0x1c] */
/* @0x19dee4 ldr r2, [pc, r2] */
/* @0x19dee8 ldr r1, [r2, #0x8] */
/* @0x19deec mov r3, r0 */
/* @0x19def0 cmp r0, r1 */
/* @0x19def4 movge r3, #2 */
/* @0x19def8 strge r3, [r4, #0x18] */
/* @0x19defc bge 0x19df5c <_ZN15WithObjIteratordeEv+0x110> */
/* @0x19df00 cmp r3, #0 */
/* @0x19df04 ldr r12, [r2] */
/* @0x19df08 ldrge r0, [r2] */
/* @0x19df0c movlt r5, #0 */
/* @0x19df10 ldrge r5, [r0, r3, lsl #2] */
/* @0x19df14 ldr r0, [r4, #0x14] */
/* @0x19df18 b 0x19df28 <_ZN15WithObjIteratordeEv+0xdc> */
/* @0x19df1c cmp r3, #0 */
/* @0x19df20 ldrge r5, [r12, r3, lsl #2] */
/* @0x19df24 movlt r5, #0 */
/* @0x19df28 ldr r2, [r5, #0x7c] */
/* @0x19df2c add r3, r3, #1 */
/* @0x19df30 cmp r0, r2 */
/* @0x19df34 beq 0x19dea0 <_ZN15WithObjIteratordeEv+0x54> */
/* @0x19df38 cmp r1, r3 */
/* @0x19df3c str r3, [r4, #0x1c] */
/* @0x19df40 bgt 0x19df1c <_ZN15WithObjIteratordeEv+0xd0> */
/* @0x19df44 mov r0, #0 */
/* @0x19df48 mov r3, #2 */
/* @0x19df4c str r0, [r4, #0x1c] */
/* @0x19df50 str r3, [r4, #0x18] */
/* @0x19df54 b 0x19df5c <_ZN15WithObjIteratordeEv+0x110> */
/* @0x19df58 ldr r0, [r0, #0x1c] */
/* @0x19df5c ldr r3, [pc, #0xc0] */
/* @0x19df60 ldr r3, [pc, r3] */
/* @0x19df64 ldr r2, [r3, #0x8] */
/* @0x19df68 cmp r2, r0 */
/* @0x19df6c movle r3, #3 */
/* @0x19df70 strle r3, [r4, #0x18] */
/* @0x19df74 ble 0x19dfd0 <_ZN15WithObjIteratordeEv+0x184> */
/* @0x19df78 cmp r0, #0 */
/* @0x19df7c ldrge r1, [r3] */
/* @0x19df80 movlt r5, #0 */
/* @0x19df84 ldrge r5, [r1, r0, lsl #2] */
/* @0x19df88 ldr r0, [r3] */
/* @0x19df8c ldr r1, [r4, #0x14] */
/* @0x19df90 b 0x19dfa0 <_ZN15WithObjIteratordeEv+0x154> */
/* @0x19df94 cmp r3, #0 */
/* @0x19df98 ldrge r5, [r0, r3, lsl #2] */
/* @0x19df9c movlt r5, #0 */
/* @0x19dfa0 ldr r3, [r5, #0x7c] */
/* @0x19dfa4 cmp r3, r1 */
/* @0x19dfa8 beq 0x19dea0 <_ZN15WithObjIteratordeEv+0x54> */
/* @0x19dfac ldr r3, [r4, #0x1c] */
/* @0x19dfb0 add r3, r3, #1 */
/* @0x19dfb4 str r3, [r4, #0x1c] */
/* @0x19dfb8 cmp r2, r3 */
/* @0x19dfbc bgt 0x19df94 <_ZN15WithObjIteratordeEv+0x148> */
/* @0x19dfc0 mov r2, #3 */
/* @0x19dfc4 mov r3, #0 */
/* @0x19dfc8 str r2, [r4, #0x18] */
/* @0x19dfcc str r3, [r4, #0x1c] */
/* @0x19dfd0 ldrb r3, [r4, #0x20] */
/* @0x19dfd4 cmp r3, #0 */
/* @0x19dfd8 beq 0x19ded0 <_ZN15WithObjIteratordeEv+0x84> */
/* @0x19dfdc ldr r3, [pc, #0x44] */
/* @0x19dfe0 ldr r3, [pc, r3] */
/* @0x19dfe4 ldr r3, [r3] */
/* @0x19dfe8 ldr r5, [r3, #0x8c] */
/* @0x19dfec str r5, [r4, #0x8] */
/* @0x19dff0 b 0x19de84 <_ZN15WithObjIteratordeEv+0x38> */
/* @0x19dff4 ldr r0, [r4, #0xc] */
/* @0x19dff8 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x19dffc cmp r0, #0 */
/* @0x19e000 bne 0x19dea0 <_ZN15WithObjIteratordeEv+0x54> */
/* @0x19e004 ldr r3, [r4, #0x8] */
/* @0x19e008 cmp r3, #0 */
/* @0x19e00c beq 0x19ded0 <_ZN15WithObjIteratordeEv+0x84> */
/* @0x19e010 ldr r3, [r3, #0x178] */
/* @0x19e014 mov r5, r3 */
/* @0x19e018 str r3, [r4, #0x8] */
/* @0x19e01c b 0x19de84 <_ZN15WithObjIteratordeEv+0x38> */
/* @0x19e020 eoreq pc, r4, r12, asr sp */
/* @0x19e024 eoreq pc, r4, r8, ror #25 */
/* @0x19e028 eoreq pc, r4, r8, asr #18 */

/* ── FUNC 0x19e02c · CObjectGM::AddInstance(CInstance*) · size=208 · insn=52 */
/* @0x19e02c push {r3, r4, r5, r6, r7, lr} */
/* @0x19e030 mov r5, r1 */
/* @0x19e034 ldr r12, [r0, #0xcc] */
/* @0x19e038 mov r4, r0 */
/* @0x19e03c ldr r1, [pc, #0xb0] */
/* @0x19e040 mov r2, #143 */
/* @0x19e044 add r12, r12, #1 */
/* @0x19e048 mov r3, #1 */
/* @0x19e04c mov r0, #12 */
/* @0x19e050 add r1, pc, r1 */
/* @0x19e054 str r12, [r4, #0xcc] */
/* @0x19e058 mov r7, #0 */
/* @0x19e05c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19e060 ldr r6, [pc, #0x90] */
/* @0x19e064 ldr r3, [r4, #0xc8] */
/* @0x19e068 add r6, pc, r6 */
/* @0x19e06c cmp r3, #0 */
/* @0x19e070 movne r2, #0 */
/* @0x19e074 str r5, [r0, #0x8] */
/* @0x19e078 strne r0, [r3] */
/* @0x19e07c streq r0, [r4, #0xc8] */
/* @0x19e080 streq r0, [r4, #0xc4] */
/* @0x19e084 strne r3, [r0, #0x4] */
/* @0x19e088 streq r3, [r0, #0x4] */
/* @0x19e08c strne r0, [r4, #0xc8] */
/* @0x19e090 streq r3, [r0] */
/* @0x19e094 strne r2, [r0] */
/* @0x19e098 ldr r12, [r4, #0xd8] */
/* @0x19e09c mov r3, #1 */
/* @0x19e0a0 mov r0, #12 */
/* @0x19e0a4 mov r1, r6 */
/* @0x19e0a8 add r12, r12, #1 */
/* @0x19e0ac mov r2, #143 */
/* @0x19e0b0 str r12, [r4, #0xd8] */
/* @0x19e0b4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19e0b8 ldr r3, [r4, #0xd4] */
/* @0x19e0bc cmp r3, #0 */
/* @0x19e0c0 str r5, [r0, #0x8] */
/* @0x19e0c4 streq r0, [r4, #0xd4] */
/* @0x19e0c8 streq r0, [r4, #0xd0] */
/* @0x19e0cc strne r0, [r3] */
/* @0x19e0d0 strne r3, [r0, #0x4] */
/* @0x19e0d4 strne r0, [r4, #0xd4] */
/* @0x19e0d8 ldr r4, [r4, #0x48] */
/* @0x19e0dc streq r3, [r0, #0x4] */
/* @0x19e0e0 streq r3, [r0] */
/* @0x19e0e4 strne r7, [r0] */
/* @0x19e0e8 cmp r4, #0 */
/* @0x19e0ec bne 0x19e098 <_ZN9CObjectGM11AddInstanceEP9CInstance+0x6c> */
/* @0x19e0f0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x19e0f4 andseq lr, r10, r0, ror #27 */
/* @0x19e0f8 andseq lr, r10, r8, asr #27 */

/* ── FUNC 0x19e0fc · CObjectGM::RemoveInstance(CInstance*) · size=204 · insn=51 */
/* @0x19e0fc push {r3, r4, r5, lr} */
/* @0x19e100 mov r5, r0 */
/* @0x19e104 ldr r0, [r0, #0xc4] */
/* @0x19e108 mov r4, r1 */
/* @0x19e10c cmp r0, #0 */
/* @0x19e110 bne 0x19e124 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x28> */
/* @0x19e114 b 0x19e160 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x64> */
/* @0x19e118 ldr r0, [r0] */
/* @0x19e11c cmp r0, #0 */
/* @0x19e120 beq 0x19e160 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x64> */
/* @0x19e124 ldr r2, [r0, #0x8] */
/* @0x19e128 cmp r4, r2 */
/* @0x19e12c bne 0x19e118 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x1c> */
/* @0x19e130 ldm r0, {r1, r2} */
/* @0x19e134 cmp r2, #0 */
/* @0x19e138 strne r1, [r2] */
/* @0x19e13c ldrne r1, [r0] */
/* @0x19e140 streq r1, [r5, #0xc4] */
/* @0x19e144 cmp r1, #0 */
/* @0x19e148 streq r2, [r5, #0xc8] */
/* @0x19e14c strne r2, [r1, #0x4] */
/* @0x19e150 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19e154 ldr r3, [r5, #0xcc] */
/* @0x19e158 sub r3, r3, #1 */
/* @0x19e15c str r3, [r5, #0xcc] */
/* @0x19e160 ldr r0, [r5, #0xd0] */
/* @0x19e164 cmp r0, #0 */
/* @0x19e168 bne 0x19e17c <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x80> */
/* @0x19e16c b 0x19e1b8 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0xbc> */
/* @0x19e170 ldr r0, [r0] */
/* @0x19e174 cmp r0, #0 */
/* @0x19e178 beq 0x19e1b8 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0xbc> */
/* @0x19e17c ldr r3, [r0, #0x8] */
/* @0x19e180 cmp r4, r3 */
/* @0x19e184 bne 0x19e170 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x74> */
/* @0x19e188 ldm r0, {r2, r3} */
/* @0x19e18c cmp r3, #0 */
/* @0x19e190 strne r2, [r3] */
/* @0x19e194 ldrne r2, [r0] */
/* @0x19e198 streq r2, [r5, #0xd0] */
/* @0x19e19c cmp r2, #0 */
/* @0x19e1a0 streq r3, [r5, #0xd4] */
/* @0x19e1a4 strne r3, [r2, #0x4] */
/* @0x19e1a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19e1ac ldr r3, [r5, #0xd8] */
/* @0x19e1b0 sub r3, r3, #1 */
/* @0x19e1b4 str r3, [r5, #0xd8] */
/* @0x19e1b8 ldr r5, [r5, #0x48] */
/* @0x19e1bc cmp r5, #0 */
/* @0x19e1c0 bne 0x19e160 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x64> */
/* @0x19e1c4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x19e1c8 · FINALIZE_Object_Class() · size=4 · insn=1 */
/* @0x19e1c8 bx lr */

/* ── FUNC 0x19e1cc · CreateColPairs() · size=1156 · insn=289 */
/* @0x19e1cc ldr r0, [pc, #0x460] */
/* @0x19e1d0 ldr r1, [pc, #0x460] */
/* @0x19e1d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19e1d8 add r0, pc, r0 */
/* @0x19e1dc sub sp, sp, #20 */
/* @0x19e1e0 ldr r2, [pc, #0x454] */
/* @0x19e1e4 mov r7, #0 */
/* @0x19e1e8 ldr r3, [pc, #0x450] */
/* @0x19e1ec str r0, [sp, #0x4] */
/* @0x19e1f0 ldr r8, [r0, r1] */
/* @0x19e1f4 str r7, [r8] */
/* @0x19e1f8 ldr r5, [r0, r2] */
/* @0x19e1fc str r7, [r5] */
/* @0x19e200 str r7, [r5, #0x4] */
/* @0x19e204 ldr r3, [r0, r3] */
/* @0x19e208 ldr r6, [r3] */
/* @0x19e20c cmp r6, r7 */
/* @0x19e210 ble 0x19e388 <_Z14CreateColPairsv+0x1bc> */
/* @0x19e214 mov r9, r0 */
/* @0x19e218 mov r0, r7 */
/* @0x19e21c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19e220 cmp r0, #0 */
/* @0x19e224 beq 0x19e278 <_Z14CreateColPairsv+0xac> */
/* @0x19e228 ldr r3, [pc, #0x414] */
/* @0x19e22c ldr r4, [r9, r3] */
/* @0x19e230 ldr r3, [r4] */
/* @0x19e234 ldr r2, [r3, #0x4] */
/* @0x19e238 ldr r3, [r3] */
/* @0x19e23c and r2, r7, r2 */
/* @0x19e240 ldr r3, [r3, r2, lsl #3] */
/* @0x19e244 cmp r3, #0 */
/* @0x19e248 bne 0x19e25c <_Z14CreateColPairsv+0x90> */
/* @0x19e24c b 0x19e26c <_Z14CreateColPairsv+0xa0> */
/* @0x19e250 ldr r3, [r3, #0x4] */
/* @0x19e254 cmp r3, #0 */
/* @0x19e258 beq 0x19e26c <_Z14CreateColPairsv+0xa0> */
/* @0x19e25c ldr r2, [r3, #0x8] */
/* @0x19e260 cmp r7, r2 */
/* @0x19e264 bne 0x19e250 <_Z14CreateColPairsv+0x84> */
/* @0x19e268 ldr r3, [r3, #0xc] */
/* @0x19e26c ldrb r2, [r3, #0x1c] */
/* @0x19e270 cmp r2, #0 */
/* @0x19e274 beq 0x19e4f4 <_Z14CreateColPairsv+0x328> */
/* @0x19e278 add r7, r7, #1 */
/* @0x19e27c cmp r7, r6 */
/* @0x19e280 bne 0x19e218 <_Z14CreateColPairsv+0x4c> */
/* @0x19e284 ldr r2, [pc, #0x3bc] */
/* @0x19e288 mov r9, #0 */
/* @0x19e28c add r1, r5, #4 */
/* @0x19e290 str r1, [sp, #0x8] */
/* @0x19e294 add r2, pc, r2 */
/* @0x19e298 str r2, [sp, #0xc] */
/* @0x19e29c mov r0, r9 */
/* @0x19e2a0 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19e2a4 cmp r0, #0 */
/* @0x19e2a8 beq 0x19e37c <_Z14CreateColPairsv+0x1b0> */
/* @0x19e2ac ldr r3, [pc, #0x390] */
/* @0x19e2b0 ldr r1, [sp, #0x4] */
/* @0x19e2b4 ldr r3, [r1, r3] */
/* @0x19e2b8 str r3, [sp] */
/* @0x19e2bc ldr r3, [r3] */
/* @0x19e2c0 ldr r2, [r3, #0x4] */
/* @0x19e2c4 ldr r3, [r3] */
/* @0x19e2c8 and r2, r9, r2 */
/* @0x19e2cc ldr r7, [r3, r2, lsl #3] */
/* @0x19e2d0 cmp r7, #0 */
/* @0x19e2d4 bne 0x19e2e8 <_Z14CreateColPairsv+0x11c> */
/* @0x19e2d8 b 0x19e2f8 <_Z14CreateColPairsv+0x12c> */
/* @0x19e2dc ldr r7, [r7, #0x4] */
/* @0x19e2e0 cmp r7, #0 */
/* @0x19e2e4 beq 0x19e2f8 <_Z14CreateColPairsv+0x12c> */
/* @0x19e2e8 ldr r3, [r7, #0x8] */
/* @0x19e2ec cmp r9, r3 */
/* @0x19e2f0 bne 0x19e2dc <_Z14CreateColPairsv+0x110> */
/* @0x19e2f4 ldr r7, [r7, #0xc] */
/* @0x19e2f8 mov r4, #0 */
/* @0x19e2fc mov r0, r7 */
/* @0x19e300 mov r1, #4 */
/* @0x19e304 mov r2, r4 */
/* @0x19e308 bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii> */
/* @0x19e30c cmp r0, #0 */
/* @0x19e310 beq 0x19e370 <_Z14CreateColPairsv+0x1a4> */
/* @0x19e314 cmp r4, r9 */
/* @0x19e318 ldr r0, [r5] */
/* @0x19e31c movgt r11, r4 */
/* @0x19e320 movgt r10, r9 */
/* @0x19e324 movle r11, r9 */
/* @0x19e328 movle r10, r4 */
/* @0x19e32c cmp r0, #0 */
/* @0x19e330 ble 0x19e390 <_Z14CreateColPairsv+0x1c4> */
/* @0x19e334 mov r3, #0 */
/* @0x19e338 ldr r2, [r5, #0x4] */
/* @0x19e33c mov r1, r3 */
/* @0x19e340 b 0x19e350 <_Z14CreateColPairsv+0x184> */
/* @0x19e344 cmp r1, r0 */
/* @0x19e348 add r3, r3, #20 */
/* @0x19e34c beq 0x19e390 <_Z14CreateColPairsv+0x1c4> */
/* @0x19e350 ldr r12, [r2, r3] */
/* @0x19e354 add r1, r1, #1 */
/* @0x19e358 cmp r12, r10 */
/* @0x19e35c bne 0x19e344 <_Z14CreateColPairsv+0x178> */
/* @0x19e360 add r12, r2, r3 */
/* @0x19e364 ldr r12, [r12, #0x4] */
/* @0x19e368 cmp r12, r11 */
/* @0x19e36c bne 0x19e344 <_Z14CreateColPairsv+0x178> */
/* @0x19e370 add r4, r4, #1 */
/* @0x19e374 cmp r4, r6 */
/* @0x19e378 bne 0x19e2fc <_Z14CreateColPairsv+0x130> */
/* @0x19e37c add r9, r9, #1 */
/* @0x19e380 cmp r9, r6 */
/* @0x19e384 bne 0x19e29c <_Z14CreateColPairsv+0xd0> */
/* @0x19e388 add sp, sp, #20 */
/* @0x19e38c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19e390 ldr r3, [r8] */
/* @0x19e394 cmp r0, r3 */
/* @0x19e398 ble 0x19e4d0 <_Z14CreateColPairsv+0x304> */
/* @0x19e39c ldr r2, [sp] */
/* @0x19e3a0 ldr r1, [r2] */
/* @0x19e3a4 ldr r2, [r1, #0x4] */
/* @0x19e3a8 ldr r3, [r1] */
/* @0x19e3ac and r2, r9, r2 */
/* @0x19e3b0 ldr r3, [r3, r2, lsl #3] */
/* @0x19e3b4 cmp r3, #0 */
/* @0x19e3b8 bne 0x19e3cc <_Z14CreateColPairsv+0x200> */
/* @0x19e3bc b 0x19e3dc <_Z14CreateColPairsv+0x210> */
/* @0x19e3c0 ldr r3, [r3, #0x4] */
/* @0x19e3c4 cmp r3, #0 */
/* @0x19e3c8 beq 0x19e3dc <_Z14CreateColPairsv+0x210> */
/* @0x19e3cc ldr r2, [r3, #0x8] */
/* @0x19e3d0 cmp r9, r2 */
/* @0x19e3d4 bne 0x19e3c0 <_Z14CreateColPairsv+0x1f4> */
/* @0x19e3d8 ldr r3, [r3, #0xc] */
/* @0x19e3dc ldr r2, [r3] */
/* @0x19e3e0 orr r2, r2, #8 */
/* @0x19e3e4 str r2, [r3] */
/* @0x19e3e8 ldr r2, [r1, #0x4] */
/* @0x19e3ec ldr r3, [r1] */
/* @0x19e3f0 and r2, r4, r2 */
/* @0x19e3f4 ldr r3, [r3, r2, lsl #3] */
/* @0x19e3f8 cmp r3, #0 */
/* @0x19e3fc bne 0x19e410 <_Z14CreateColPairsv+0x244> */
/* @0x19e400 b 0x19e420 <_Z14CreateColPairsv+0x254> */
/* @0x19e404 ldr r3, [r3, #0x4] */
/* @0x19e408 cmp r3, #0 */
/* @0x19e40c beq 0x19e420 <_Z14CreateColPairsv+0x254> */
/* @0x19e410 ldr r2, [r3, #0x8] */
/* @0x19e414 cmp r4, r2 */
/* @0x19e418 bne 0x19e404 <_Z14CreateColPairsv+0x238> */
/* @0x19e41c ldr r3, [r3, #0xc] */
/* @0x19e420 ldr r2, [r3] */
/* @0x19e424 ldr r10, [r5, #0x4] */
/* @0x19e428 orr r2, r2, #8 */
/* @0x19e42c str r2, [r3] */
/* @0x19e430 ldm r1, {r0, r12} */
/* @0x19e434 ldr r1, [r8] */
/* @0x19e438 and r3, r9, r12 */
/* @0x19e43c add r11, r1, r1, lsl #2 */
/* @0x19e440 ldr r3, [r0, r3, lsl #3] */
/* @0x19e444 add r2, r10, r11, lsl #2 */
/* @0x19e448 cmp r3, #0 */
/* @0x19e44c str r9, [r10, r11, lsl #2] */
/* @0x19e450 str r4, [r2, #0x4] */
/* @0x19e454 bne 0x19e468 <_Z14CreateColPairsv+0x29c> */
/* @0x19e458 b 0x19e478 <_Z14CreateColPairsv+0x2ac> */
/* @0x19e45c ldr r3, [r3, #0x4] */
/* @0x19e460 cmp r3, #0 */
/* @0x19e464 beq 0x19e478 <_Z14CreateColPairsv+0x2ac> */
/* @0x19e468 ldr r10, [r3, #0x8] */
/* @0x19e46c cmp r9, r10 */
/* @0x19e470 bne 0x19e45c <_Z14CreateColPairsv+0x290> */
/* @0x19e474 ldr r3, [r3, #0xc] */
/* @0x19e478 and r12, r4, r12 */
/* @0x19e47c str r3, [r2, #0x8] */
/* @0x19e480 ldr r3, [r0, r12, lsl #3] */
/* @0x19e484 cmp r3, #0 */
/* @0x19e488 bne 0x19e49c <_Z14CreateColPairsv+0x2d0> */
/* @0x19e48c b 0x19e4ac <_Z14CreateColPairsv+0x2e0> */
/* @0x19e490 ldr r3, [r3, #0x4] */
/* @0x19e494 cmp r3, #0 */
/* @0x19e498 beq 0x19e4ac <_Z14CreateColPairsv+0x2e0> */
/* @0x19e49c ldr r0, [r3, #0x8] */
/* @0x19e4a0 cmp r4, r0 */
/* @0x19e4a4 bne 0x19e490 <_Z14CreateColPairsv+0x2c4> */
/* @0x19e4a8 ldr r3, [r3, #0xc] */
/* @0x19e4ac add r4, r4, #1 */
/* @0x19e4b0 add r1, r1, #1 */
/* @0x19e4b4 cmp r4, r6 */
/* @0x19e4b8 str r3, [r2, #0xc] */
/* @0x19e4bc str r1, [r8] */
/* @0x19e4c0 mov r3, #1 */
/* @0x19e4c4 strb r3, [r2, #0x10] */
/* @0x19e4c8 bne 0x19e2fc <_Z14CreateColPairsv+0x130> */
/* @0x19e4cc b 0x19e37c <_Z14CreateColPairsv+0x1b0> */
/* @0x19e4d0 add r12, r3, #5 */
/* @0x19e4d4 ldr r0, [sp, #0x8] */
/* @0x19e4d8 ldr r2, [sp, #0xc] */
/* @0x19e4dc mov r3, #90 */
/* @0x19e4e0 add r1, r12, r12, lsl #2 */
/* @0x19e4e4 str r12, [r5] */
/* @0x19e4e8 lsl r1, r1, #2 */
/* @0x19e4ec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19e4f0 b 0x19e39c <_Z14CreateColPairsv+0x1d0> */
/* @0x19e4f4 ldr r3, [pc, #0x150] */
/* @0x19e4f8 ldr r0, [sp, #0x4] */
/* @0x19e4fc ldr r3, [r0, r3] */
/* @0x19e500 ldrb r3, [r3] */
/* @0x19e504 cmp r3, #0 */
/* @0x19e508 movne r8, r2 */
/* @0x19e50c beq 0x19e284 <_Z14CreateColPairsv+0xb8> */
/* @0x19e510 mov r0, r8 */
/* @0x19e514 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x19e518 cmp r0, #0 */
/* @0x19e51c beq 0x19e618 <_Z14CreateColPairsv+0x44c> */
/* @0x19e520 ldr r3, [r4] */
/* @0x19e524 ldr r2, [r3, #0x4] */
/* @0x19e528 ldr r3, [r3] */
/* @0x19e52c and r2, r8, r2 */
/* @0x19e530 ldr r7, [r3, r2, lsl #3] */
/* @0x19e534 cmp r7, #0 */
/* @0x19e538 bne 0x19e54c <_Z14CreateColPairsv+0x380> */
/* @0x19e53c b 0x19e55c <_Z14CreateColPairsv+0x390> */
/* @0x19e540 ldr r7, [r7, #0x4] */
/* @0x19e544 cmp r7, #0 */
/* @0x19e548 beq 0x19e55c <_Z14CreateColPairsv+0x390> */
/* @0x19e54c ldr r3, [r7, #0x8] */
/* @0x19e550 cmp r8, r3 */
/* @0x19e554 bne 0x19e540 <_Z14CreateColPairsv+0x374> */
/* @0x19e558 ldr r7, [r7, #0xc] */
/* @0x19e55c mov r5, #0 */
/* @0x19e560 mov r0, r7 */
/* @0x19e564 mov r1, #4 */
/* @0x19e568 mov r2, r5 */
/* @0x19e56c bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii> */
/* @0x19e570 cmp r0, #0 */
/* @0x19e574 beq 0x19e60c <_Z14CreateColPairsv+0x440> */
/* @0x19e578 ldr r2, [r4] */
/* @0x19e57c ldr r1, [r2, #0x4] */
/* @0x19e580 ldr r3, [r2] */
/* @0x19e584 and r1, r8, r1 */
/* @0x19e588 ldr r3, [r3, r1, lsl #3] */
/* @0x19e58c cmp r3, #0 */
/* @0x19e590 bne 0x19e5a4 <_Z14CreateColPairsv+0x3d8> */
/* @0x19e594 b 0x19e5b4 <_Z14CreateColPairsv+0x3e8> */
/* @0x19e598 ldr r3, [r3, #0x4] */
/* @0x19e59c cmp r3, #0 */
/* @0x19e5a0 beq 0x19e5b4 <_Z14CreateColPairsv+0x3e8> */
/* @0x19e5a4 ldr r1, [r3, #0x8] */
/* @0x19e5a8 cmp r8, r1 */
/* @0x19e5ac bne 0x19e598 <_Z14CreateColPairsv+0x3cc> */
/* @0x19e5b0 ldr r3, [r3, #0xc] */
/* @0x19e5b4 ldr r1, [r3] */
/* @0x19e5b8 orr r1, r1, #8 */
/* @0x19e5bc str r1, [r3] */
/* @0x19e5c0 ldr r1, [r2, #0x4] */
/* @0x19e5c4 ldr r3, [r2] */
/* @0x19e5c8 and r2, r5, r1 */
/* @0x19e5cc ldr r3, [r3, r2, lsl #3] */
/* @0x19e5d0 cmp r3, #0 */
/* @0x19e5d4 beq 0x19e600 <_Z14CreateColPairsv+0x434> */
/* @0x19e5d8 ldr r2, [r3, #0x8] */
/* @0x19e5dc cmp r5, r2 */
/* @0x19e5e0 bne 0x19e5f4 <_Z14CreateColPairsv+0x428> */
/* @0x19e5e4 b 0x19e62c <_Z14CreateColPairsv+0x460> */
/* @0x19e5e8 ldr r1, [r3, #0x8] */
/* @0x19e5ec cmp r5, r1 */
/* @0x19e5f0 beq 0x19e62c <_Z14CreateColPairsv+0x460> */
/* @0x19e5f4 ldr r3, [r3, #0x4] */
/* @0x19e5f8 cmp r3, #0 */
/* @0x19e5fc bne 0x19e5e8 <_Z14CreateColPairsv+0x41c> */
/* @0x19e600 ldr r2, [r3] */
/* @0x19e604 orr r2, r2, #8 */
/* @0x19e608 str r2, [r3] */
/* @0x19e60c add r5, r5, #1 */
/* @0x19e610 cmp r5, r6 */
/* @0x19e614 bne 0x19e560 <_Z14CreateColPairsv+0x394> */
/* @0x19e618 add r8, r8, #1 */
/* @0x19e61c cmp r8, r6 */
/* @0x19e620 bne 0x19e510 <_Z14CreateColPairsv+0x344> */
/* @0x19e624 add sp, sp, #20 */
/* @0x19e628 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19e62c ldr r3, [r3, #0xc] */
/* @0x19e630 b 0x19e600 <_Z14CreateColPairsv+0x434> */
/* @0x19e634 eoreq r3, r5, r8, ror r10 */
/* @0x19e638 .word 0xffffea8c */
/* @0x19e63c .word 0xffffea90 */
/* @0x19e640 .word 0xffffea94 */
/* @0x19e644 .word 0xffffbfec */
/* @0x19e648 andseq lr, r10, r12, asr #23 */
/* @0x19e64c .word 0xffffea30 */

/* ── FUNC 0x19e650 · CreateList(int, int) · size=396 · insn=99 */
/* @0x19e650 ldr r12, [pc, #0x16c] */
/* @0x19e654 mov r3, #0 */
/* @0x19e658 ldr r2, [pc, #0x168] */
/* @0x19e65c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19e660 add r12, pc, r12 */
/* @0x19e664 sub sp, sp, #20 */
/* @0x19e668 mov r9, r0 */
/* @0x19e66c lsl r0, r0, #10 */
/* @0x19e670 str r12, [sp, #0x8] */
/* @0x19e674 str r1, [sp, #0xc] */
/* @0x19e678 mov r1, r3 */
/* @0x19e67c ldr r5, [r12, r2] */
/* @0x19e680 add r2, r5, r0 */
/* @0x19e684 str r1, [r2, r3] */
/* @0x19e688 add r3, r3, #4 */
/* @0x19e68c cmp r3, #1024 */
/* @0x19e690 bne 0x19e684 <_Z10CreateListii+0x34> */
/* @0x19e694 ldr r12, [sp, #0xc] */
/* @0x19e698 cmp r12, #0 */
/* @0x19e69c blt 0x19e790 <_Z10CreateListii+0x140> */
/* @0x19e6a0 ldr r12, [pc, #0x124] */
/* @0x19e6a4 add r5, r5, r0 */
/* @0x19e6a8 ldr r2, [pc, #0x120] */
/* @0x19e6ac mov r8, #0 */
/* @0x19e6b0 add r12, pc, r12 */
/* @0x19e6b4 str r12, [sp, #0x4] */
/* @0x19e6b8 ldr r12, [sp, #0x8] */
/* @0x19e6bc ldr r3, [pc, #0x110] */
/* @0x19e6c0 ldr r6, [r12, r2] */
/* @0x19e6c4 ldr r7, [r12, r3] */
/* @0x19e6c8 add r6, r6, r9, lsl #11 */
/* @0x19e6cc ldr r3, [r7] */
/* @0x19e6d0 cmp r3, #0 */
/* @0x19e6d4 ble 0x19e778 <_Z10CreateListii+0x128> */
/* @0x19e6d8 ldr r3, [pc, #0xf8] */
/* @0x19e6dc add r10, r6, #4 */
/* @0x19e6e0 ldr r12, [sp, #0x8] */
/* @0x19e6e4 mov r4, #0 */
/* @0x19e6e8 ldr r11, [r12, r3] */
/* @0x19e6ec ldr r3, [r11] */
/* @0x19e6f0 ldr r2, [r3, #0x4] */
/* @0x19e6f4 ldr r3, [r3] */
/* @0x19e6f8 and r2, r4, r2 */
/* @0x19e6fc ldr r3, [r3, r2, lsl #3] */
/* @0x19e700 cmp r3, #0 */
/* @0x19e704 bne 0x19e718 <_Z10CreateListii+0xc8> */
/* @0x19e708 b 0x19e768 <_Z10CreateListii+0x118> */
/* @0x19e70c ldr r3, [r3, #0x4] */
/* @0x19e710 cmp r3, #0 */
/* @0x19e714 beq 0x19e768 <_Z10CreateListii+0x118> */
/* @0x19e718 ldr r2, [r3, #0x8] */
/* @0x19e71c cmp r4, r2 */
/* @0x19e720 bne 0x19e70c <_Z10CreateListii+0xbc> */
/* @0x19e724 ldr r0, [r3, #0xc] */
/* @0x19e728 cmp r0, #0 */
/* @0x19e72c beq 0x19e768 <_Z10CreateListii+0x118> */
/* @0x19e730 mov r1, r9 */
/* @0x19e734 mov r2, r8 */
/* @0x19e738 bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii> */
/* @0x19e73c cmp r0, #0 */
/* @0x19e740 beq 0x19e768 <_Z10CreateListii+0x118> */
/* @0x19e744 ldr r3, [r5] */
/* @0x19e748 ldr r2, [r6] */
/* @0x19e74c cmp r3, r2 */
/* @0x19e750 bge 0x19e798 <_Z10CreateListii+0x148> */
/* @0x19e754 ldr r2, [r6, #0x4] */
/* @0x19e758 str r4, [r2, r3, lsl #2] */
/* @0x19e75c ldr r3, [r5] */
/* @0x19e760 add r3, r3, #1 */
/* @0x19e764 str r3, [r5] */
/* @0x19e768 ldr r3, [r7] */
/* @0x19e76c add r4, r4, #1 */
/* @0x19e770 cmp r4, r3 */
/* @0x19e774 blt 0x19e6ec <_Z10CreateListii+0x9c> */
/* @0x19e778 ldr r12, [sp, #0xc] */
/* @0x19e77c add r8, r8, #1 */
/* @0x19e780 add r5, r5, #4 */
/* @0x19e784 add r6, r6, #8 */
/* @0x19e788 cmp r12, r8 */
/* @0x19e78c bge 0x19e6cc <_Z10CreateListii+0x7c> */
/* @0x19e790 add sp, sp, #20 */
/* @0x19e794 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19e798 add r1, r3, #5 */
/* @0x19e79c ldr r2, [sp, #0x4] */
/* @0x19e7a0 mov r3, #156 */
/* @0x19e7a4 mov r0, r10 */
/* @0x19e7a8 lsl r1, r1, #2 */
/* @0x19e7ac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19e7b0 ldr r2, [r6] */
/* @0x19e7b4 ldr r3, [r5] */
/* @0x19e7b8 add r2, r2, #5 */
/* @0x19e7bc str r2, [r6] */
/* @0x19e7c0 b 0x19e754 <_Z10CreateListii+0x104> */
/* @0x19e7c4 .word 0x002535f0 */
/* @0x19e7c8 .word 0xffffdeb8 */
/* @0x19e7cc ldrheq lr, [r10], -r0 */
/* @0x19e7d0 .word 0xffffdebc */
/* @0x19e7d4 .word 0xffffea94 */
/* @0x19e7d8 .word 0xffffbfec */

/* ── FUNC 0x19e7dc · Create_Object_Lists() · size=168 · insn=42 */
/* @0x19e7dc mov r0, #0 */
/* @0x19e7e0 push {r3, lr} */
/* @0x19e7e4 mov r1, r0 */
/* @0x19e7e8 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e7ec mov r0, #1 */
/* @0x19e7f0 mov r1, #0 */
/* @0x19e7f4 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e7f8 mov r0, #2 */
/* @0x19e7fc mov r1, #12 */
/* @0x19e800 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e804 mov r0, #3 */
/* @0x19e808 mov r1, #16 */
/* @0x19e80c bl 0x19e650 <_Z10CreateListii> */
/* @0x19e810 mov r0, #4 */
/* @0x19e814 mvn r1, #0 */
/* @0x19e818 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e81c mov r0, #5 */
/* @0x19e820 mov r1, #128 */
/* @0x19e824 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e828 mov r0, #6 */
/* @0x19e82c mov r1, #128 */
/* @0x19e830 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e834 mov r0, #7 */
/* @0x19e838 mov r1, #128 */
/* @0x19e83c bl 0x19e650 <_Z10CreateListii> */
/* @0x19e840 mov r0, #8 */
/* @0x19e844 mov r1, #0 */
/* @0x19e848 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e84c mov r0, #9 */
/* @0x19e850 mov r1, #128 */
/* @0x19e854 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e858 mov r0, #10 */
/* @0x19e85c mov r1, #128 */
/* @0x19e860 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e864 mov r0, #13 */
/* @0x19e868 mov r1, #128 */
/* @0x19e86c bl 0x19e650 <_Z10CreateListii> */
/* @0x19e870 mov r0, #14 */
/* @0x19e874 mov r1, #0 */
/* @0x19e878 bl 0x19e650 <_Z10CreateListii> */
/* @0x19e87c pop {r3, lr} */
/* @0x19e880 b 0x19e1cc <_Z14CreateColPairsv> */

/* ── FUNC 0x19e884 · FINALIZE_Object_Lists() · size=132 · insn=33 */
/* @0x19e884 push {r4, r5, r6, r7, r8, lr} */
/* @0x19e888 mov r7, #0 */
/* @0x19e88c ldr r6, [pc, #0x6c] */
/* @0x19e890 ldr r6, [pc, r6] */
/* @0x19e894 add r8, r6, #30720 */
/* @0x19e898 mov r4, #0 */
/* @0x19e89c add r5, r6, r4 */
/* @0x19e8a0 ldr r0, [r5, #0x4] */
/* @0x19e8a4 cmp r0, #0 */
/* @0x19e8a8 beq 0x19e8c4 <_Z21FINALIZE_Object_Listsv+0x40> */
/* @0x19e8ac ldr r3, [r6, r4] */
/* @0x19e8b0 cmp r3, #0 */
/* @0x19e8b4 ble 0x19e8c4 <_Z21FINALIZE_Object_Listsv+0x40> */
/* @0x19e8b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19e8bc str r7, [r5, #0x4] */
/* @0x19e8c0 str r7, [r6, r4] */
/* @0x19e8c4 add r4, r4, #8 */
/* @0x19e8c8 cmp r4, #2048 */
/* @0x19e8cc bne 0x19e89c <_Z21FINALIZE_Object_Listsv+0x18> */
/* @0x19e8d0 add r6, r6, #2048 */
/* @0x19e8d4 cmp r6, r8 */
/* @0x19e8d8 bne 0x19e898 <_Z21FINALIZE_Object_Listsv+0x14> */
/* @0x19e8dc ldr r4, [pc, #0x20] */
/* @0x19e8e0 ldr r4, [pc, r4] */
/* @0x19e8e4 ldr r0, [r4, #0x4] */
/* @0x19e8e8 cmp r0, #0 */
/* @0x19e8ec popeq {r4, r5, r6, r7, r8, pc} */
/* @0x19e8f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19e8f4 mov r3, #0 */
/* @0x19e8f8 str r3, [r4, #0x4] */
/* @0x19e8fc pop {r4, r5, r6, r7, r8, pc} */
/* @0x19e900 eoreq r1, r5, r12, ror r2 */
/* @0x19e904 eoreq r1, r5, r0, lsl #28 */
