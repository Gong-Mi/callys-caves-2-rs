/* libyoyo.so 覆盖卡组 0131
 * 函数 0x194f28..0x199960，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x194f28 · CInstance::Collision_Line(float, float, float, float, bool) · size=876 · insn=219 */
/* @0x194f28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x194f2c vpush {d8, d9, d10, d11} */
/* @0x194f30 sub sp, sp, #36 */
/* @0x194f34 vldr s19, [sp, #104] */
/* @0x194f38 mov r4, r0 */
/* @0x194f3c vmov s17, r3 */
/* @0x194f40 vmov s16, r1 */
/* @0x194f44 ldrb r7, [sp, #0x6c] */
/* @0x194f48 vmov s18, r2 */
/* @0x194f4c bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x194f50 subs r8, r0, #0 */
/* @0x194f54 ldrbeq r3, [r4, #0x64] */
/* @0x194f58 beq 0x194fc4 <_ZN9CInstance14Collision_LineEffffb+0x9c> */
/* @0x194f5c vldr s15, [r4, #144] */
/* @0x194f60 vcvt.s32.f32 s15, s15 */
/* @0x194f64 ldr r5, [pc, #0x324] */
/* @0x194f68 ldr r1, [r4, #0xa0] */
/* @0x194f6c ldr r9, [r4, #0xb8] */
/* @0x194f70 ldr r5, [pc, r5] */
/* @0x194f74 ldr lr, [r4, #0x98] */
/* @0x194f78 ldr r12, [r4, #0x9c] */
/* @0x194f7c ldr r3, [r4, #0xb4] */
/* @0x194f80 ldr r6, [r5] */
/* @0x194f84 vmov r2, s15 */
/* @0x194f88 str r4, [r5] */
/* @0x194f8c str r1, [sp, #0xc] */
/* @0x194f90 add r1, r4, #232 */
/* @0x194f94 str r9, [sp] */
/* @0x194f98 str lr, [sp, #0x4] */
/* @0x194f9c str r12, [sp, #0x8] */
/* @0x194fa0 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff> */
/* @0x194fa4 str r6, [r5] */
/* @0x194fa8 cmp r0, #0 */
/* @0x194fac ldrbeq r3, [r4, #0x64] */
/* @0x194fb0 movne r2, #0 */
/* @0x194fb4 movne r3, r2 */
/* @0x194fb8 movne r1, #1 */
/* @0x194fbc strbne r2, [r4, #0x64] */
/* @0x194fc0 strbne r1, [r4, #0xb0] */
/* @0x194fc4 cmp r3, #0 */
/* @0x194fc8 bne 0x1951c4 <_ZN9CInstance14Collision_LineEffffb+0x29c> */
/* @0x194fcc ldr r3, [r4, #0xf0] */
/* @0x194fd0 vcmpe.f32 s16, s17 */
/* @0x194fd4 add r2, r3, #1 */
/* @0x194fd8 vmov s15, r2 */
/* @0x194fdc vmrs APSR_nzcv, fpscr */
/* @0x194fe0 vmovpl.f32 s14, s17 */
/* @0x194fe4 vmovmi.f32 s14, s16 */
/* @0x194fe8 vcvt.f32.s32 s15, s15 */
/* @0x194fec vcmpe.f32 s14, s15 */
/* @0x194ff0 vmrs APSR_nzcv, fpscr */
/* @0x194ff4 bge 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x194ff8 vcmpe.f32 s16, s17 */
/* @0x194ffc vldr s11, [r4, #232] */
/* @0x195000 vcvt.f32.s32 s14, s11 */
/* @0x195004 vmrs APSR_nzcv, fpscr */
/* @0x195008 vmovle.f32 s13, s17 */
/* @0x19500c vmovgt.f32 s13, s16 */
/* @0x195010 vcmpe.f32 s13, s14 */
/* @0x195014 vmrs APSR_nzcv, fpscr */
/* @0x195018 bmi 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x19501c ldr r2, [r4, #0xf4] */
/* @0x195020 vcmpe.f32 s18, s19 */
/* @0x195024 add r2, r2, #1 */
/* @0x195028 vmov s12, r2 */
/* @0x19502c vmrs APSR_nzcv, fpscr */
/* @0x195030 vcvt.f32.s32 s13, s12 */
/* @0x195034 vmovpl.f32 s12, s19 */
/* @0x195038 vmovmi.f32 s12, s18 */
/* @0x19503c vcmpe.f32 s12, s13 */
/* @0x195040 vmrs APSR_nzcv, fpscr */
/* @0x195044 bge 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x195048 vcmpe.f32 s18, s19 */
/* @0x19504c vldr s11, [r4, #236] */
/* @0x195050 vcvt.f32.s32 s12, s11 */
/* @0x195054 vmrs APSR_nzcv, fpscr */
/* @0x195058 vmovle.f32 s11, s19 */
/* @0x19505c vmovgt.f32 s11, s18 */
/* @0x195060 vcmpe.f32 s11, s12 */
/* @0x195064 vmrs APSR_nzcv, fpscr */
/* @0x195068 bmi 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x19506c ldrb r2, [r4, #0x68] */
/* @0x195070 cmp r2, #0 */
/* @0x195074 bne 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x195078 vcmpe.f32 s16, s17 */
/* @0x19507c vmrs APSR_nzcv, fpscr */
/* @0x195080 ble 0x19509c <_ZN9CInstance14Collision_LineEffffb+0x174> */
/* @0x195084 vmov.f32 s10, s18 */
/* @0x195088 vmov.f32 s11, s16 */
/* @0x19508c vmov.f32 s18, s19 */
/* @0x195090 vmov.f32 s16, s17 */
/* @0x195094 vmov.f32 s19, s10 */
/* @0x195098 vmov.f32 s17, s11 */
/* @0x19509c vcmpe.f32 s16, s14 */
/* @0x1950a0 vmrs APSR_nzcv, fpscr */
/* @0x1950a4 bpl 0x1950c4 <_ZN9CInstance14Collision_LineEffffb+0x19c> */
/* @0x1950a8 vsub.f32 s10, s14, s16 */
/* @0x1950ac vsub.f32 s11, s19, s18 */
/* @0x1950b0 vmul.f32 s10, s10, s11 */
/* @0x1950b4 vsub.f32 s11, s17, s16 */
/* @0x1950b8 vmov.f32 s16, s14 */
/* @0x1950bc vdiv.f32 s14, s10, s11 */
/* @0x1950c0 vadd.f32 s18, s18, s14 */
/* @0x1950c4 vcmpe.f32 s17, s15 */
/* @0x1950c8 vmrs APSR_nzcv, fpscr */
/* @0x1950cc ble 0x1950f8 <_ZN9CInstance14Collision_LineEffffb+0x1d0> */
/* @0x1950d0 vsub.f32 s15, s15, s17 */
/* @0x1950d4 vmov s11, r3 */
/* @0x1950d8 vsub.f32 s14, s19, s18 */
/* @0x1950dc vmul.f32 s14, s15, s14 */
/* @0x1950e0 vsub.f32 s17, s17, s16 */
/* @0x1950e4 vdiv.f32 s14, s14, s17 */
/* @0x1950e8 vmov.f32 s15, #1.000000e+00 */
/* @0x1950ec vcvt.f32.s32 s17, s11 */
/* @0x1950f0 vadd.f32 s19, s19, s14 */
/* @0x1950f4 vadd.f32 s17, s17, s15 */
/* @0x1950f8 vcmpe.f32 s18, s12 */
/* @0x1950fc vmrs APSR_nzcv, fpscr */
/* @0x195100 bpl 0x195110 <_ZN9CInstance14Collision_LineEffffb+0x1e8> */
/* @0x195104 vcmpe.f32 s19, s12 */
/* @0x195108 vmrs APSR_nzcv, fpscr */
/* @0x19510c bmi 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x195110 vcmpe.f32 s18, s13 */
/* @0x195114 vmrs APSR_nzcv, fpscr */
/* @0x195118 blt 0x195128 <_ZN9CInstance14Collision_LineEffffb+0x200> */
/* @0x19511c vcmpe.f32 s19, s13 */
/* @0x195120 vmrs APSR_nzcv, fpscr */
/* @0x195124 bge 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x195128 cmp r7, #0 */
/* @0x19512c beq 0x1951d4 <_ZN9CInstance14Collision_LineEffffb+0x2ac> */
/* @0x195130 ldrb r3, [r4, #0xb0] */
/* @0x195134 cmp r3, #0 */
/* @0x195138 beq 0x1951d4 <_ZN9CInstance14Collision_LineEffffb+0x2ac> */
/* @0x19513c ldr r0, [r4, #0xac] */
/* @0x195140 cmp r0, #0 */
/* @0x195144 ldrlt r0, [r4, #0x8c] */
/* @0x195148 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x19514c cmp r0, #0 */
/* @0x195150 mov r5, r0 */
/* @0x195154 beq 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x195158 ldr r3, [r0, #0x18] */
/* @0x19515c cmp r3, #0 */
/* @0x195160 beq 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c> */
/* @0x195164 cmp r8, #0 */
/* @0x195168 beq 0x1951dc <_ZN9CInstance14Collision_LineEffffb+0x2b4> */
/* @0x19516c vstr s16, [sp, #12] */
/* @0x195170 vstr s18, [sp, #16] */
/* @0x195174 vstr s17, [sp, #20] */
/* @0x195178 vstr s19, [sp, #24] */
/* @0x19517c vldr s15, [r4, #144] */
/* @0x195180 vcvt.s32.f32 s15, s15 */
/* @0x195184 ldr r12, [r4, #0x98] */
/* @0x195188 mov r0, r8 */
/* @0x19518c ldr r2, [r4, #0xb4] */
/* @0x195190 ldr r3, [r4, #0xb8] */
/* @0x195194 str r12, [sp] */
/* @0x195198 ldr lr, [r4, #0x9c] */
/* @0x19519c ldr r12, [r4, #0xa0] */
/* @0x1951a0 vmov r1, s15 */
/* @0x1951a4 str lr, [sp, #0x4] */
/* @0x1951a8 str r12, [sp, #0x8] */
/* @0x1951ac bl 0xbf3cc <_ZN17CSkeletonInstance13LineCollisionEifffffffff> */
/* @0x1951b0 b 0x1951b8 <_ZN9CInstance14Collision_LineEffffb+0x290> */
/* @0x1951b4 mov r0, #0 */
/* @0x1951b8 add sp, sp, #36 */
/* @0x1951bc vpop {d8, d9, d10, d11} */
/* @0x1951c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1951c4 mov r0, r4 */
/* @0x1951c8 mov r1, #1 */
/* @0x1951cc bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1951d0 b 0x194fcc <_ZN9CInstance14Collision_LineEffffb+0xa4> */
/* @0x1951d4 mov r0, #1 */
/* @0x1951d8 b 0x1951b8 <_ZN9CInstance14Collision_LineEffffb+0x290> */
/* @0x1951dc vldr s15, [r4, #180] */
/* @0x1951e0 vcvt.f64.f32 d6, s15 */
/* @0x1951e4 vldr s15, [r4, #144] */
/* @0x1951e8 vcvt.s32.f32 s15, s15 */
/* @0x1951ec vmov r0, r1, d6 */
/* @0x1951f0 vmov r11, s15 */
/* @0x1951f4 bl 0xb66e8 <lrint@plt> */
/* @0x1951f8 vldr s15, [r4, #184] */
/* @0x1951fc vcvt.f64.f32 d6, s15 */
/* @0x195200 mov r8, r0 */
/* @0x195204 vmov r0, r1, d6 */
/* @0x195208 bl 0xb66e8 <lrint@plt> */
/* @0x19520c vldr s22, [r4, #152] */
/* @0x195210 vcvt.f64.f32 d7, s16 */
/* @0x195214 vldr s21, [r4, #156] */
/* @0x195218 vldr s20, [r4, #160] */
/* @0x19521c mov r10, r0 */
/* @0x195220 vmov r0, r1, d7 */
/* @0x195224 bl 0xb66e8 <lrint@plt> */
/* @0x195228 vcvt.f64.f32 d6, s18 */
/* @0x19522c mov r9, r0 */
/* @0x195230 vmov r0, r1, d6 */
/* @0x195234 bl 0xb66e8 <lrint@plt> */
/* @0x195238 vcvt.f64.f32 d7, s17 */
/* @0x19523c mov r7, r0 */
/* @0x195240 vmov r0, r1, d7 */
/* @0x195244 bl 0xb66e8 <lrint@plt> */
/* @0x195248 vcvt.f64.f32 d6, s19 */
/* @0x19524c mov r6, r0 */
/* @0x195250 vmov r0, r1, d6 */
/* @0x195254 bl 0xb66e8 <lrint@plt> */
/* @0x195258 str r10, [sp] */
/* @0x19525c mov r1, r11 */
/* @0x195260 vstr s22, [sp, #4] */
/* @0x195264 vstr s21, [sp, #8] */
/* @0x195268 vstr s20, [sp, #12] */
/* @0x19526c str r9, [sp, #0x10] */
/* @0x195270 mov r3, r8 */
/* @0x195274 str r7, [sp, #0x14] */
/* @0x195278 add r2, r4, #232 */
/* @0x19527c str r6, [sp, #0x18] */
/* @0x195280 str r0, [sp, #0x1c] */
/* @0x195284 mov r0, r5 */
/* @0x195288 bl 0x1e52bc <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii> */
/* @0x19528c b 0x1951b8 <_ZN9CInstance14Collision_LineEffffb+0x290> */
/* @0x195290 eoreq r8, r5, r4, asr #19 */

/* ── FUNC 0x195294 · CInstance::Collision_Skeleton(CInstance*, bool) · size=708 · insn=177 */
/* @0x195294 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x195298 sub sp, sp, #48 */
/* @0x19529c mov r4, r0 */
/* @0x1952a0 mov r5, r1 */
/* @0x1952a4 mov r10, r2 */
/* @0x1952a8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x1952ac ldr r6, [pc, #0x2a0] */
/* @0x1952b0 mov r8, r0 */
/* @0x1952b4 mov r0, r5 */
/* @0x1952b8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x1952bc vldr s15, [r4, #144] */
/* @0x1952c0 vcvt.s32.f32 s15, s15 */
/* @0x1952c4 ldr r1, [r4, #0x98] */
/* @0x1952c8 ldr r6, [pc, r6] */
/* @0x1952cc ldr r3, [r4, #0xb4] */
/* @0x1952d0 ldr r9, [r6] */
/* @0x1952d4 str r4, [r6] */
/* @0x1952d8 vmov r2, s15 */
/* @0x1952dc mov r7, r0 */
/* @0x1952e0 ldr r0, [r4, #0xb8] */
/* @0x1952e4 str r1, [sp, #0x4] */
/* @0x1952e8 str r0, [sp] */
/* @0x1952ec ldr r0, [r4, #0x9c] */
/* @0x1952f0 ldr r1, [r4, #0xa0] */
/* @0x1952f4 str r0, [sp, #0x8] */
/* @0x1952f8 mov r0, r8 */
/* @0x1952fc str r1, [sp, #0xc] */
/* @0x195300 add r1, r4, #232 */
/* @0x195304 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff> */
/* @0x195308 str r5, [r6] */
/* @0x19530c cmp r0, #0 */
/* @0x195310 movne r2, #0 */
/* @0x195314 movne r3, #1 */
/* @0x195318 strbne r2, [r4, #0x64] */
/* @0x19531c strbne r3, [r4, #0xb0] */
/* @0x195320 cmp r7, #0 */
/* @0x195324 beq 0x195378 <_ZN9CInstance18Collision_SkeletonEPS_b+0xe4> */
/* @0x195328 ldr r1, [r5, #0xb8] */
/* @0x19532c vldr s15, [r5, #144] */
/* @0x195330 vcvt.s32.f32 s15, s15 */
/* @0x195334 ldr r3, [r5, #0xb4] */
/* @0x195338 str r1, [sp] */
/* @0x19533c ldr r0, [r5, #0x98] */
/* @0x195340 ldr r1, [r5, #0x9c] */
/* @0x195344 str r0, [sp, #0x4] */
/* @0x195348 mov r0, r7 */
/* @0x19534c str r1, [sp, #0x8] */
/* @0x195350 ldr r1, [r5, #0xa0] */
/* @0x195354 vmov r2, s15 */
/* @0x195358 str r1, [sp, #0xc] */
/* @0x19535c add r1, r5, #232 */
/* @0x195360 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff> */
/* @0x195364 cmp r0, #0 */
/* @0x195368 movne r2, #0 */
/* @0x19536c movne r3, #1 */
/* @0x195370 strbne r2, [r5, #0x64] */
/* @0x195374 strbne r3, [r5, #0xb0] */
/* @0x195378 ldrb r3, [r4, #0x64] */
/* @0x19537c str r9, [r6] */
/* @0x195380 cmp r3, #0 */
/* @0x195384 bne 0x195428 <_ZN9CInstance18Collision_SkeletonEPS_b+0x194> */
/* @0x195388 ldrb r3, [r5, #0x64] */
/* @0x19538c cmp r3, #0 */
/* @0x195390 bne 0x195418 <_ZN9CInstance18Collision_SkeletonEPS_b+0x184> */
/* @0x195394 ldr r2, [r4, #0xf0] */
/* @0x195398 ldr r3, [r5, #0xe8] */
/* @0x19539c cmp r2, r3 */
/* @0x1953a0 blt 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178> */
/* @0x1953a4 ldr r2, [r5, #0xf0] */
/* @0x1953a8 ldr r3, [r4, #0xe8] */
/* @0x1953ac cmp r2, r3 */
/* @0x1953b0 blt 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178> */
/* @0x1953b4 ldr r2, [r4, #0xf4] */
/* @0x1953b8 ldr r3, [r5, #0xec] */
/* @0x1953bc cmp r2, r3 */
/* @0x1953c0 blt 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178> */
/* @0x1953c4 ldr r2, [r5, #0xf4] */
/* @0x1953c8 ldr r3, [r4, #0xec] */
/* @0x1953cc cmp r2, r3 */
/* @0x1953d0 blt 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178> */
/* @0x1953d4 ldr r0, [r5, #0xac] */
/* @0x1953d8 cmp r0, #0 */
/* @0x1953dc ldrlt r0, [r5, #0x8c] */
/* @0x1953e0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1953e4 cmp r0, #0 */
/* @0x1953e8 mov r6, r0 */
/* @0x1953ec beq 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178> */
/* @0x1953f0 ldr r3, [r0, #0x18] */
/* @0x1953f4 cmp r3, #0 */
/* @0x1953f8 beq 0x19540c <_ZN9CInstance18Collision_SkeletonEPS_b+0x178> */
/* @0x1953fc cmp r10, #0 */
/* @0x195400 bne 0x195438 <_ZN9CInstance18Collision_SkeletonEPS_b+0x1a4> */
/* @0x195404 mov r0, #1 */
/* @0x195408 b 0x195410 <_ZN9CInstance18Collision_SkeletonEPS_b+0x17c> */
/* @0x19540c mov r0, #0 */
/* @0x195410 add sp, sp, #48 */
/* @0x195414 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x195418 mov r0, r5 */
/* @0x19541c mov r1, #1 */
/* @0x195420 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x195424 b 0x195394 <_ZN9CInstance18Collision_SkeletonEPS_b+0x100> */
/* @0x195428 mov r0, r4 */
/* @0x19542c mov r1, #1 */
/* @0x195430 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x195434 b 0x195388 <_ZN9CInstance18Collision_SkeletonEPS_b+0xf4> */
/* @0x195438 ldr r0, [r4, #0x8c] */
/* @0x19543c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x195440 ldrb r3, [r0, #0x30] */
/* @0x195444 cmp r3, #0 */
/* @0x195448 bne 0x195458 <_ZN9CInstance18Collision_SkeletonEPS_b+0x1c4> */
/* @0x19544c ldrb r3, [r6, #0x30] */
/* @0x195450 cmp r3, #0 */
/* @0x195454 beq 0x195404 <_ZN9CInstance18Collision_SkeletonEPS_b+0x170> */
/* @0x195458 cmp r7, #0 */
/* @0x19545c beq 0x1954d4 <_ZN9CInstance18Collision_SkeletonEPS_b+0x240> */
/* @0x195460 vldr s15, [r5, #144] */
/* @0x195464 vcvt.s32.f32 s15, s15 */
/* @0x195468 str r7, [sp, #0xc] */
/* @0x19546c mov r0, r8 */
/* @0x195470 ldr lr, [r4, #0x98] */
/* @0x195474 ldr r12, [r4, #0x9c] */
/* @0x195478 ldr r2, [r4, #0xb4] */
/* @0x19547c ldr r3, [r4, #0xb8] */
/* @0x195480 vmov r1, s15 */
/* @0x195484 vldr s15, [r4, #144] */
/* @0x195488 str lr, [sp] */
/* @0x19548c vcvt.s32.f32 s15, s15 */
/* @0x195490 str r12, [sp, #0x4] */
/* @0x195494 ldr r12, [r4, #0xa0] */
/* @0x195498 str r12, [sp, #0x8] */
/* @0x19549c str r1, [sp, #0x10] */
/* @0x1954a0 ldr lr, [r5, #0xb4] */
/* @0x1954a4 ldr r12, [r5, #0xb8] */
/* @0x1954a8 vmov r1, s15 */
/* @0x1954ac str lr, [sp, #0x14] */
/* @0x1954b0 str r12, [sp, #0x18] */
/* @0x1954b4 ldr r12, [r5, #0x9c] */
/* @0x1954b8 ldr lr, [r5, #0x98] */
/* @0x1954bc str r12, [sp, #0x20] */
/* @0x1954c0 str lr, [sp, #0x1c] */
/* @0x1954c4 ldr r12, [r5, #0xa0] */
/* @0x1954c8 str r12, [sp, #0x24] */
/* @0x1954cc bl 0xbefd8 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff> */
/* @0x1954d0 b 0x195410 <_ZN9CInstance18Collision_SkeletonEPS_b+0x17c> */
/* @0x1954d4 mov r0, r4 */
/* @0x1954d8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x1954dc vldr s15, [r5, #144] */
/* @0x1954e0 vcvt.s32.f32 s15, s15 */
/* @0x1954e4 str r6, [sp, #0xc] */
/* @0x1954e8 ldr lr, [r4, #0x98] */
/* @0x1954ec ldr r12, [r4, #0x9c] */
/* @0x1954f0 ldr r2, [r4, #0xb4] */
/* @0x1954f4 ldr r3, [r4, #0xb8] */
/* @0x1954f8 vmov r1, s15 */
/* @0x1954fc vldr s15, [r4, #144] */
/* @0x195500 str r12, [sp, #0x4] */
/* @0x195504 add r12, r5, #232 */
/* @0x195508 str lr, [sp] */
/* @0x19550c vcvt.s32.f32 s15, s15 */
/* @0x195510 ldr lr, [r4, #0xa0] */
/* @0x195514 str r12, [sp, #0x10] */
/* @0x195518 str lr, [sp, #0x8] */
/* @0x19551c str r1, [sp, #0x14] */
/* @0x195520 ldr lr, [r5, #0xb4] */
/* @0x195524 ldr r12, [r5, #0xb8] */
/* @0x195528 vmov r1, s15 */
/* @0x19552c str lr, [sp, #0x18] */
/* @0x195530 str r12, [sp, #0x1c] */
/* @0x195534 ldr r12, [r5, #0x9c] */
/* @0x195538 ldr lr, [r5, #0x98] */
/* @0x19553c str r12, [sp, #0x24] */
/* @0x195540 str lr, [sp, #0x20] */
/* @0x195544 ldr r12, [r5, #0xa0] */
/* @0x195548 str r12, [sp, #0x28] */
/* @0x19554c bl 0xbf0fc <_ZN17CSkeletonInstance15SpriteCollisionEifffffP7CSpriteP9tagYYRECTifffff> */
/* @0x195550 b 0x195410 <_ZN9CInstance18Collision_SkeletonEPS_b+0x17c> */
/* @0x195554 eoreq r8, r5, r12, ror #12 */

/* ── FUNC 0x195558 · CInstance::Collision_Instance(CInstance*, bool) · size=884 · insn=221 */
/* @0x195558 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19555c vpush {d8, d9, d10} */
/* @0x195560 mov r5, r0 */
/* @0x195564 ldr r4, [pc, #0x350] */
/* @0x195568 sub sp, sp, #60 */
/* @0x19556c ldr r3, [pc, #0x34c] */
/* @0x195570 mov r7, r1 */
/* @0x195574 add r4, pc, r4 */
/* @0x195578 mov r8, r2 */
/* @0x19557c ldr r6, [r4, r3] */
/* @0x195580 ldrb r3, [r6] */
/* @0x195584 cmp r3, #0 */
/* @0x195588 bne 0x195600 <_ZN9CInstance18Collision_InstanceEPS_b+0xa8> */
/* @0x19558c cmp r5, r7 */
/* @0x195590 beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195594 ldrb r3, [r5, #0x68] */
/* @0x195598 cmp r3, #0 */
/* @0x19559c beq 0x1955cc <_ZN9CInstance18Collision_InstanceEPS_b+0x74> */
/* @0x1955a0 mov r5, #0 */
/* @0x1955a4 ldrb r3, [r6] */
/* @0x1955a8 cmp r3, #0 */
/* @0x1955ac beq 0x1955bc <_ZN9CInstance18Collision_InstanceEPS_b+0x64> */
/* @0x1955b0 ldr r3, [pc, #0x30c] */
/* @0x1955b4 ldr r0, [r4, r3] */
/* @0x1955b8 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1955bc mov r0, r5 */
/* @0x1955c0 add sp, sp, #60 */
/* @0x1955c4 vpop {d8, d9, d10} */
/* @0x1955c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1955cc ldrb r3, [r7, #0x68] */
/* @0x1955d0 cmp r3, #0 */
/* @0x1955d4 bne 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1955d8 mov r0, r5 */
/* @0x1955dc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x1955e0 cmp r0, #0 */
/* @0x1955e4 beq 0x195618 <_ZN9CInstance18Collision_InstanceEPS_b+0xc0> */
/* @0x1955e8 mov r0, r5 */
/* @0x1955ec mov r1, r7 */
/* @0x1955f0 mov r2, r8 */
/* @0x1955f4 bl 0x195294 <_ZN9CInstance18Collision_SkeletonEPS_b> */
/* @0x1955f8 mov r5, r0 */
/* @0x1955fc b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x195600 ldr r3, [pc, #0x2bc] */
/* @0x195604 mov r1, #6 */
/* @0x195608 mov r2, #1 */
/* @0x19560c ldr r0, [r4, r3] */
/* @0x195610 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x195614 b 0x19558c <_ZN9CInstance18Collision_InstanceEPS_b+0x34> */
/* @0x195618 mov r0, r7 */
/* @0x19561c bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x195620 cmp r0, #0 */
/* @0x195624 beq 0x195640 <_ZN9CInstance18Collision_InstanceEPS_b+0xe8> */
/* @0x195628 mov r1, r5 */
/* @0x19562c mov r0, r7 */
/* @0x195630 mov r2, r8 */
/* @0x195634 bl 0x195294 <_ZN9CInstance18Collision_SkeletonEPS_b> */
/* @0x195638 mov r5, r0 */
/* @0x19563c b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x195640 ldrb r3, [r7, #0x64] */
/* @0x195644 cmp r3, #0 */
/* @0x195648 bne 0x1957c8 <_ZN9CInstance18Collision_InstanceEPS_b+0x270> */
/* @0x19564c ldrb r3, [r5, #0x64] */
/* @0x195650 cmp r3, #0 */
/* @0x195654 bne 0x1957b8 <_ZN9CInstance18Collision_InstanceEPS_b+0x260> */
/* @0x195658 ldr r2, [r5, #0xf0] */
/* @0x19565c ldr r3, [r7, #0xe8] */
/* @0x195660 cmp r2, r3 */
/* @0x195664 blt 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195668 ldr r2, [r7, #0xf0] */
/* @0x19566c ldr r3, [r5, #0xe8] */
/* @0x195670 cmp r2, r3 */
/* @0x195674 blt 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195678 ldr r2, [r5, #0xf4] */
/* @0x19567c ldr r3, [r7, #0xec] */
/* @0x195680 cmp r2, r3 */
/* @0x195684 blt 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195688 ldr r2, [r7, #0xf4] */
/* @0x19568c ldr r3, [r5, #0xec] */
/* @0x195690 cmp r2, r3 */
/* @0x195694 blt 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195698 ldr r0, [r5, #0xac] */
/* @0x19569c cmp r0, #0 */
/* @0x1956a0 ldrlt r0, [r5, #0x8c] */
/* @0x1956a4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1956a8 cmp r0, #0 */
/* @0x1956ac mov r9, r0 */
/* @0x1956b0 beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1956b4 ldr r3, [r0, #0x18] */
/* @0x1956b8 cmp r3, #0 */
/* @0x1956bc beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1956c0 ldr r0, [r7, #0xac] */
/* @0x1956c4 cmp r0, #0 */
/* @0x1956c8 blt 0x1958ac <_ZN9CInstance18Collision_InstanceEPS_b+0x354> */
/* @0x1956cc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1956d0 mov r10, r0 */
/* @0x1956d4 cmp r10, #0 */
/* @0x1956d8 beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1956dc ldr r3, [r10, #0x18] */
/* @0x1956e0 cmp r3, #0 */
/* @0x1956e4 beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1956e8 cmp r8, #0 */
/* @0x1956ec beq 0x1957d8 <_ZN9CInstance18Collision_InstanceEPS_b+0x280> */
/* @0x1956f0 ldrb r3, [r9, #0x30] */
/* @0x1956f4 cmp r3, #0 */
/* @0x1956f8 bne 0x195708 <_ZN9CInstance18Collision_InstanceEPS_b+0x1b0> */
/* @0x1956fc ldrb r3, [r10, #0x30] */
/* @0x195700 cmp r3, #0 */
/* @0x195704 beq 0x1957d8 <_ZN9CInstance18Collision_InstanceEPS_b+0x280> */
/* @0x195708 ldr r3, [pc, #0x1b8] */
/* @0x19570c ldr r3, [r4, r3] */
/* @0x195710 ldrb r3, [r3] */
/* @0x195714 cmp r3, #0 */
/* @0x195718 beq 0x1957e0 <_ZN9CInstance18Collision_InstanceEPS_b+0x288> */
/* @0x19571c vldr s15, [r5, #184] */
/* @0x195720 vcvt.s32.f32 s15, s15 */
/* @0x195724 vldr s11, [r7, #144] */
/* @0x195728 vldr s12, [r7, #180] */
/* @0x19572c vldr s13, [r7, #184] */
/* @0x195730 str r10, [sp, #0x10] */
/* @0x195734 ldr r1, [r5, #0x98] */
/* @0x195738 vldr s14, [r5, #144] */
/* @0x19573c ldr r2, [r5, #0x9c] */
/* @0x195740 mov r0, r9 */
/* @0x195744 vmov r3, s15 */
/* @0x195748 vldr s15, [r5, #180] */
/* @0x19574c str r2, [sp, #0x8] */
/* @0x195750 vcvt.s32.f32 s11, s11 */
/* @0x195754 str r1, [sp, #0x4] */
/* @0x195758 add r2, r5, #232 */
/* @0x19575c ldr r1, [r5, #0xa0] */
/* @0x195760 str r1, [sp, #0xc] */
/* @0x195764 vcvt.s32.f32 s12, s12 */
/* @0x195768 vcvt.s32.f32 s13, s13 */
/* @0x19576c str r3, [sp] */
/* @0x195770 add r3, r7, #232 */
/* @0x195774 ldr r1, [r7, #0x98] */
/* @0x195778 vcvt.s32.f32 s14, s14 */
/* @0x19577c str r3, [sp, #0x18] */
/* @0x195780 str r1, [sp, #0x24] */
/* @0x195784 ldr r1, [r7, #0x9c] */
/* @0x195788 ldr r3, [r7, #0xa0] */
/* @0x19578c vstr s11, [sp, #20] */
/* @0x195790 vstr s12, [sp, #28] */
/* @0x195794 vstr s13, [sp, #32] */
/* @0x195798 str r1, [sp, #0x28] */
/* @0x19579c vcvt.s32.f32 s15, s15 */
/* @0x1957a0 str r3, [sp, #0x2c] */
/* @0x1957a4 vmov r1, s14 */
/* @0x1957a8 vmov r3, s15 */
/* @0x1957ac bl 0x1e4298 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff> */
/* @0x1957b0 mov r5, r0 */
/* @0x1957b4 b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x1957b8 mov r0, r5 */
/* @0x1957bc mov r1, #1 */
/* @0x1957c0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1957c4 b 0x195658 <_ZN9CInstance18Collision_InstanceEPS_b+0x100> */
/* @0x1957c8 mov r0, r7 */
/* @0x1957cc mov r1, #1 */
/* @0x1957d0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1957d4 b 0x19564c <_ZN9CInstance18Collision_InstanceEPS_b+0xf4> */
/* @0x1957d8 mov r5, #1 */
/* @0x1957dc b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x1957e0 vldr s15, [r5, #180] */
/* @0x1957e4 vcvt.f64.f32 d6, s15 */
/* @0x1957e8 vldr s16, [r5, #144] */
/* @0x1957ec vmov r0, r1, d6 */
/* @0x1957f0 bl 0xb66e8 <lrint@plt> */
/* @0x1957f4 vldr s15, [r5, #184] */
/* @0x1957f8 vcvt.f64.f32 d6, s15 */
/* @0x1957fc vcvt.s32.f32 s16, s16 */
/* @0x195800 mov r8, r0 */
/* @0x195804 vmov r0, r1, d6 */
/* @0x195808 bl 0xb66e8 <lrint@plt> */
/* @0x19580c vldr s15, [r7, #180] */
/* @0x195810 vcvt.f64.f32 d6, s15 */
/* @0x195814 vldr s20, [r5, #152] */
/* @0x195818 vldr s19, [r5, #156] */
/* @0x19581c vldr s18, [r5, #160] */
/* @0x195820 vldr s17, [r7, #144] */
/* @0x195824 vcvt.s32.f32 s17, s17 */
/* @0x195828 mov r3, r0 */
/* @0x19582c vmov r0, r1, d6 */
/* @0x195830 str r3, [sp, #0x34] */
/* @0x195834 bl 0xb66e8 <lrint@plt> */
/* @0x195838 vldr s15, [r7, #184] */
/* @0x19583c vcvt.f64.f32 d6, s15 */
/* @0x195840 mov r11, r0 */
/* @0x195844 vmov r0, r1, d6 */
/* @0x195848 bl 0xb66e8 <lrint@plt> */
/* @0x19584c ldr r3, [sp, #0x34] */
/* @0x195850 vstr s17, [sp, #20] */
/* @0x195854 vstr s20, [sp, #4] */
/* @0x195858 vstr s19, [sp, #8] */
/* @0x19585c vstr s18, [sp, #12] */
/* @0x195860 str r3, [sp] */
/* @0x195864 add r12, r7, #232 */
/* @0x195868 str r11, [sp, #0x1c] */
/* @0x19586c add r2, r5, #232 */
/* @0x195870 str r10, [sp, #0x10] */
/* @0x195874 mov r3, r8 */
/* @0x195878 ldr lr, [r7, #0x98] */
/* @0x19587c str r12, [sp, #0x18] */
/* @0x195880 vmov r1, s16 */
/* @0x195884 str lr, [sp, #0x24] */
/* @0x195888 ldr lr, [r7, #0x9c] */
/* @0x19588c ldr r12, [r7, #0xa0] */
/* @0x195890 str lr, [sp, #0x28] */
/* @0x195894 str r12, [sp, #0x2c] */
/* @0x195898 str r0, [sp, #0x20] */
/* @0x19589c mov r0, r9 */
/* @0x1958a0 bl 0x1e4298 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff> */
/* @0x1958a4 mov r5, r0 */
/* @0x1958a8 b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x1958ac ldr r0, [r7, #0x8c] */
/* @0x1958b0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1958b4 mov r10, r0 */
/* @0x1958b8 b 0x1956d4 <_ZN9CInstance18Collision_InstanceEPS_b+0x17c> */
/* @0x1958bc .word 0x0025c6dc */
/* @0x1958c0 .word 0xffffbf18 */
/* @0x1958c4 .word 0xffffbf1c */
/* @0x1958c8 .word 0xffffea30 */

/* ── FUNC 0x1958cc · CInstance::SetID(int, bool) · size=296 · insn=74 */
/* @0x1958cc cmp r2, #0 */
/* @0x1958d0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1958d4 mov r5, r0 */
/* @0x1958d8 mov r6, r1 */
/* @0x1958dc streq r1, [r0, #0x78] */
/* @0x1958e0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1958e4 ldr r4, [pc, #0x100] */
/* @0x1958e8 ldr r12, [r0, #0x78] */
/* @0x1958ec ldr r4, [pc, r4] */
/* @0x1958f0 ldr r1, [r4, #0x4] */
/* @0x1958f4 ldr r7, [r4] */
/* @0x1958f8 and r2, r12, r1 */
/* @0x1958fc ldr r3, [r7, r2, lsl #3] */
/* @0x195900 add lr, r7, r2, lsl #3 */
/* @0x195904 cmp r3, #0 */
/* @0x195908 beq 0x195934 <_ZN9CInstance5SetIDEib+0x68> */
/* @0x19590c ldr r0, [r3, #0x8] */
/* @0x195910 cmp r12, r0 */
/* @0x195914 bne 0x195928 <_ZN9CInstance5SetIDEib+0x5c> */
/* @0x195918 b 0x195994 <_ZN9CInstance5SetIDEib+0xc8> */
/* @0x19591c ldr r2, [r3, #0x8] */
/* @0x195920 cmp r12, r2 */
/* @0x195924 beq 0x195994 <_ZN9CInstance5SetIDEib+0xc8> */
/* @0x195928 ldr r3, [r3, #0x4] */
/* @0x19592c cmp r3, #0 */
/* @0x195930 bne 0x19591c <_ZN9CInstance5SetIDEib+0x50> */
/* @0x195934 and r8, r1, r6 */
/* @0x195938 ldr r1, [pc, #0xb0] */
/* @0x19593c movw r2, #0x132 */
/* @0x195940 mov r3, #1 */
/* @0x195944 str r6, [r5, #0x78] */
/* @0x195948 mov r0, #16 */
/* @0x19594c add r1, pc, r1 */
/* @0x195950 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x195954 ldr r3, [r7, r8, lsl #3] */
/* @0x195958 add r2, r7, r8, lsl #3 */
/* @0x19595c cmp r3, #0 */
/* @0x195960 str r6, [r0, #0x8] */
/* @0x195964 str r5, [r0, #0xc] */
/* @0x195968 beq 0x1959d8 <_ZN9CInstance5SetIDEib+0x10c> */
/* @0x19596c ldr r3, [r2, #0x4] */
/* @0x195970 mov r1, #0 */
/* @0x195974 str r3, [r0] */
/* @0x195978 str r0, [r3, #0x4] */
/* @0x19597c str r0, [r2, #0x4] */
/* @0x195980 str r1, [r0, #0x4] */
/* @0x195984 ldr r3, [r4, #0x8] */
/* @0x195988 add r3, r3, #1 */
/* @0x19598c str r3, [r4, #0x8] */
/* @0x195990 pop {r4, r5, r6, r7, r8, pc} */
/* @0x195994 ldr r1, [r3] */
/* @0x195998 cmp r1, #0 */
/* @0x19599c ldrne r2, [r3, #0x4] */
/* @0x1959a0 ldreq r0, [r3, #0x4] */
/* @0x1959a4 strne r2, [r1, #0x4] */
/* @0x1959a8 ldrne r0, [r3, #0x4] */
/* @0x1959ac streq r0, [lr] */
/* @0x1959b0 cmp r0, #0 */
/* @0x1959b4 streq r1, [lr, #0x4] */
/* @0x1959b8 strne r1, [r0] */
/* @0x1959bc mov r0, r3 */
/* @0x1959c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1959c4 ldmib r4, {r1, r3} */
/* @0x1959c8 ldr r7, [r4] */
/* @0x1959cc sub r3, r3, #1 */
/* @0x1959d0 str r3, [r4, #0x8] */
/* @0x1959d4 b 0x195934 <_ZN9CInstance5SetIDEib+0x68> */
/* @0x1959d8 str r0, [r2, #0x4] */
/* @0x1959dc str r0, [r7, r8, lsl #3] */
/* @0x1959e0 str r3, [r0, #0x4] */
/* @0x1959e4 str r3, [r0] */
/* @0x1959e8 b 0x195984 <_ZN9CInstance5SetIDEib+0xb8> */
/* @0x1959ec eoreq r8, r5, r8, asr r3 */
/* @0x1959f0 andseq r7, r11, r0, ror #6 */

/* ── FUNC 0x1959f4 · FINALIZE_Instance_Class() · size=436 · insn=109 */
/* @0x1959f4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1959f8 mov r3, #0 */
/* @0x1959fc ldr r6, [pc, #0x1a0] */
/* @0x195a00 ldr r6, [pc, r6] */
/* @0x195a04 ldm r6, {r2, r7} */
/* @0x195a08 b 0x195a14 <_Z23FINALIZE_Instance_Classv+0x20> */
/* @0x195a0c cmp r3, r7 */
/* @0x195a10 bgt 0x195b9c <_Z23FINALIZE_Instance_Classv+0x1a8> */
/* @0x195a14 mov r8, r3 */
/* @0x195a18 add r3, r3, #1 */
/* @0x195a1c ldr r5, [r2, r8, lsl #3] */
/* @0x195a20 cmp r5, #0 */
/* @0x195a24 beq 0x195a0c <_Z23FINALIZE_Instance_Classv+0x18> */
/* @0x195a28 ldr r0, [r6] */
/* @0x195a2c cmp r5, #0 */
/* @0x195a30 beq 0x195b1c <_Z23FINALIZE_Instance_Classv+0x128> */
/* @0x195a34 ldr r1, [r5, #0xc] */
/* @0x195a38 cmp r1, #0 */
/* @0x195a3c beq 0x195b1c <_Z23FINALIZE_Instance_Classv+0x128> */
/* @0x195a40 ldr r5, [r5, #0x4] */
/* @0x195a44 cmp r5, #0 */
/* @0x195a48 beq 0x195ae4 <_Z23FINALIZE_Instance_Classv+0xf0> */
/* @0x195a4c ldr r2, [r1, #0x78] */
/* @0x195a50 and r3, r7, r2 */
/* @0x195a54 ldr r4, [r0, r3, lsl #3] */
/* @0x195a58 add r12, r0, r3, lsl #3 */
/* @0x195a5c cmp r4, #0 */
/* @0x195a60 beq 0x195a2c <_Z23FINALIZE_Instance_Classv+0x38> */
/* @0x195a64 ldr r1, [r4, #0x8] */
/* @0x195a68 cmp r2, r1 */
/* @0x195a6c beq 0x195a88 <_Z23FINALIZE_Instance_Classv+0x94> */
/* @0x195a70 ldr r4, [r4, #0x4] */
/* @0x195a74 cmp r4, #0 */
/* @0x195a78 beq 0x195a2c <_Z23FINALIZE_Instance_Classv+0x38> */
/* @0x195a7c ldr r3, [r4, #0x8] */
/* @0x195a80 cmp r2, r3 */
/* @0x195a84 bne 0x195a70 <_Z23FINALIZE_Instance_Classv+0x7c> */
/* @0x195a88 ldr r2, [r4] */
/* @0x195a8c ldr r0, [r4, #0xc] */
/* @0x195a90 cmp r2, #0 */
/* @0x195a94 ldrne r3, [r4, #0x4] */
/* @0x195a98 ldreq r1, [r4, #0x4] */
/* @0x195a9c strne r3, [r2, #0x4] */
/* @0x195aa0 ldrne r1, [r4, #0x4] */
/* @0x195aa4 streq r1, [r12] */
/* @0x195aa8 cmp r1, #0 */
/* @0x195aac streq r2, [r12, #0x4] */
/* @0x195ab0 strne r2, [r1] */
/* @0x195ab4 cmp r0, #0 */
/* @0x195ab8 beq 0x195ac8 <_Z23FINALIZE_Instance_Classv+0xd4> */
/* @0x195abc ldr r3, [r0] */
/* @0x195ac0 ldr r3, [r3, #0x4] */
/* @0x195ac4 blx r3 */
/* @0x195ac8 mov r0, r4 */
/* @0x195acc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x195ad0 ldr r3, [r6, #0x8] */
/* @0x195ad4 ldr r7, [r6, #0x4] */
/* @0x195ad8 sub r3, r3, #1 */
/* @0x195adc str r3, [r6, #0x8] */
/* @0x195ae0 b 0x195a28 <_Z23FINALIZE_Instance_Classv+0x34> */
/* @0x195ae4 add r2, r8, #1 */
/* @0x195ae8 cmp r2, r7 */
/* @0x195aec bgt 0x195b14 <_Z23FINALIZE_Instance_Classv+0x120> */
/* @0x195af0 add r3, r0, r8, lsl #3 */
/* @0x195af4 ldr r5, [r3, #0x8] */
/* @0x195af8 mov r8, r2 */
/* @0x195afc add r3, r3, #8 */
/* @0x195b00 add r2, r2, #1 */
/* @0x195b04 cmp r5, #0 */
/* @0x195b08 bne 0x195a4c <_Z23FINALIZE_Instance_Classv+0x58> */
/* @0x195b0c cmp r7, r2 */
/* @0x195b10 bge 0x195af4 <_Z23FINALIZE_Instance_Classv+0x100> */
/* @0x195b14 mvn r8, #0 */
/* @0x195b18 b 0x195a4c <_Z23FINALIZE_Instance_Classv+0x58> */
/* @0x195b1c cmp r7, #0 */
/* @0x195b20 poplt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x195b24 lsl r8, r7, #3 */
/* @0x195b28 mov r9, #0 */
/* @0x195b2c ldr r3, [r6] */
/* @0x195b30 add r2, r3, r8 */
/* @0x195b34 ldr r4, [r3, r8] */
/* @0x195b38 str r9, [r3, r8] */
/* @0x195b3c cmp r4, #0 */
/* @0x195b40 str r9, [r2, #0x4] */
/* @0x195b44 beq 0x195b88 <_Z23FINALIZE_Instance_Classv+0x194> */
/* @0x195b48 ldr r3, [r4, #0xc] */
/* @0x195b4c ldr r5, [r4, #0x4] */
/* @0x195b50 cmp r3, #0 */
/* @0x195b54 mov r0, r3 */
/* @0x195b58 beq 0x195b68 <_Z23FINALIZE_Instance_Classv+0x174> */
/* @0x195b5c ldr r3, [r3] */
/* @0x195b60 ldr r3, [r3, #0x4] */
/* @0x195b64 blx r3 */
/* @0x195b68 mov r0, r4 */
/* @0x195b6c mov r4, r5 */
/* @0x195b70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x195b74 ldr r3, [r6, #0x8] */
/* @0x195b78 cmp r5, #0 */
/* @0x195b7c sub r3, r3, #1 */
/* @0x195b80 str r3, [r6, #0x8] */
/* @0x195b84 bne 0x195b48 <_Z23FINALIZE_Instance_Classv+0x154> */
/* @0x195b88 sub r7, r7, #1 */
/* @0x195b8c sub r8, r8, #8 */
/* @0x195b90 cmn r7, #1 */
/* @0x195b94 bne 0x195b2c <_Z23FINALIZE_Instance_Classv+0x138> */
/* @0x195b98 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x195b9c mvn r8, #0 */
/* @0x195ba0 b 0x195a28 <_Z23FINALIZE_Instance_Classv+0x34> */
/* @0x195ba4 eoreq r8, r5, r4, asr #4 */

/* ── FUNC 0x195ba8 · CHashMap<YYObjectBase*, YYObjectBase*, 4>::Insert(YYObjectBase*, YYObjectBase*) · size=1640 · insn=410 */
/* @0x195ba8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x195bac vpush {d8} */
/* @0x195bb0 sub sp, sp, #60 */
/* @0x195bb4 ldr r3, [r0, #0x4] */
/* @0x195bb8 mov r11, r0 */
/* @0x195bbc str r2, [sp, #0x24] */
/* @0x195bc0 ldr r2, [r0, #0xc] */
/* @0x195bc4 str r1, [sp, #0x1c] */
/* @0x195bc8 cmp r3, r2 */
/* @0x195bcc bgt 0x195cdc <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x134> */
/* @0x195bd0 add r3, r3, #1 */
/* @0x195bd4 ldr r0, [sp, #0x1c] */
/* @0x195bd8 str r3, [r11, #0x4] */
/* @0x195bdc bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_> */
/* @0x195be0 ldr r4, [r11, #0x8] */
/* @0x195be4 ldr r6, [r11, #0x10] */
/* @0x195be8 bic r0, r0, #-2147483648 */
/* @0x195bec and r3, r0, r4 */
/* @0x195bf0 add r2, r3, r3, lsl #1 */
/* @0x195bf4 add r2, r6, r2, lsl #2 */
/* @0x195bf8 ldr r12, [r2, #0x8] */
/* @0x195bfc cmp r12, #0 */
/* @0x195c00 beq 0x195cbc <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x114> */
/* @0x195c04 ldr r7, [r11] */
/* @0x195c08 mov r1, #0 */
/* @0x195c0c ldr r8, [sp, #0x1c] */
/* @0x195c10 ldr r9, [sp, #0x24] */
/* @0x195c14 b 0x195c5c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0xb4> */
/* @0x195c18 ldr r10, [r2] */
/* @0x195c1c mov r1, r5 */
/* @0x195c20 ldr r5, [r2, #0x4] */
/* @0x195c24 str r0, [r2, #0x8] */
/* @0x195c28 mov r0, r12 */
/* @0x195c2c str r8, [r2] */
/* @0x195c30 mov r8, r10 */
/* @0x195c34 str r9, [r2, #0x4] */
/* @0x195c38 mov r9, r5 */
/* @0x195c3c add r3, r3, #1 */
/* @0x195c40 add r1, r1, #1 */
/* @0x195c44 and r3, r3, r4 */
/* @0x195c48 add r2, r3, r3, lsl #1 */
/* @0x195c4c add r2, r6, r2, lsl #2 */
/* @0x195c50 ldr r12, [r2, #0x8] */
/* @0x195c54 cmp r12, #0 */
/* @0x195c58 beq 0x195cb4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x10c> */
/* @0x195c5c add r5, r7, r3 */
/* @0x195c60 and r10, r12, r4 */
/* @0x195c64 rsb r5, r10, r5 */
/* @0x195c68 and r5, r5, r4 */
/* @0x195c6c cmp r5, r1 */
/* @0x195c70 blt 0x195c18 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x70> */
/* @0x195c74 cmp r1, r5 */
/* @0x195c78 bne 0x195c3c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x94> */
/* @0x195c7c cmp r0, r12 */
/* @0x195c80 bne 0x195c3c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x94> */
/* @0x195c84 ldr r12, [r2] */
/* @0x195c88 cmp r8, r12 */
/* @0x195c8c bne 0x195c3c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x94> */
/* @0x195c90 ldr r3, [r11, #0x4] */
/* @0x195c94 str r8, [sp, #0x1c] */
/* @0x195c98 str r8, [r2] */
/* @0x195c9c sub r3, r3, #1 */
/* @0x195ca0 str r9, [r2, #0x4] */
/* @0x195ca4 str r0, [r2, #0x8] */
/* @0x195ca8 str r9, [sp, #0x24] */
/* @0x195cac str r3, [r11, #0x4] */
/* @0x195cb0 b 0x195cd0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x128> */
/* @0x195cb4 str r8, [sp, #0x1c] */
/* @0x195cb8 str r9, [sp, #0x24] */
/* @0x195cbc ldr r12, [sp, #0x1c] */
/* @0x195cc0 str r0, [r2, #0x8] */
/* @0x195cc4 str r12, [r2] */
/* @0x195cc8 ldr r12, [sp, #0x24] */
/* @0x195ccc str r12, [r2, #0x4] */
/* @0x195cd0 add sp, sp, #60 */
/* @0x195cd4 vpop {d8} */
/* @0x195cd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x195cdc ldr r12, [r0] */
/* @0x195ce0 mov r3, #1 */
/* @0x195ce4 ldr r1, [pc, #0x430] */
/* @0x195ce8 mov r2, #70 */
/* @0x195cec str r12, [sp, #0x20] */
/* @0x195cf0 add r1, pc, r1 */
/* @0x195cf4 ldr r12, [r0, #0x10] */
/* @0x195cf8 str r12, [sp, #0x30] */
/* @0x195cfc ldr r12, [sp, #0x20] */
/* @0x195d00 lsl r0, r12, r3 */
/* @0x195d04 str r0, [r11] */
/* @0x195d08 add r4, r0, r12, lsl #2 */
/* @0x195d0c sub r0, r0, #1 */
/* @0x195d10 str r0, [r11, #0x8] */
/* @0x195d14 lsl r4, r4, #2 */
/* @0x195d18 mov r0, r4 */
/* @0x195d1c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x195d20 mov r2, r4 */
/* @0x195d24 mov r1, #0 */
/* @0x195d28 str r0, [r11, #0x10] */
/* @0x195d2c bl 0xb65b0 <memset@plt> */
/* @0x195d30 ldr r2, [r11] */
/* @0x195d34 vldr s15, [pc, #988] */
/* @0x195d38 mov r1, #0 */
/* @0x195d3c cmp r2, r1 */
/* @0x195d40 str r1, [r11, #0x4] */
/* @0x195d44 vmov s13, r2 */
/* @0x195d48 vcvt.f32.s32 s14, s13 */
/* @0x195d4c vmul.f32 s15, s14, s15 */
/* @0x195d50 vcvt.s32.f32 s15, s15 */
/* @0x195d54 vstr s15, [r11, #12] */
/* @0x195d58 ble 0x195d78 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x1d0> */
/* @0x195d5c add r2, r2, r2, lsl #1 */
/* @0x195d60 ldr r3, [r11, #0x10] */
/* @0x195d64 add r2, r3, r2, lsl #2 */
/* @0x195d68 str r1, [r3, #0x8] */
/* @0x195d6c add r3, r3, #12 */
/* @0x195d70 cmp r3, r2 */
/* @0x195d74 bne 0x195d68 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x1c0> */
/* @0x195d78 ldr r12, [sp, #0x20] */
/* @0x195d7c cmp r12, #0 */
/* @0x195d80 ble 0x195ee8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x340> */
/* @0x195d84 ldr r12, [pc, #0x394] */
/* @0x195d88 vldr s16, [pc, #904] */
/* @0x195d8c add r12, pc, r12 */
/* @0x195d90 str r12, [sp, #0x34] */
/* @0x195d94 mov r12, #0 */
/* @0x195d98 str r12, [sp, #0xc] */
/* @0x195d9c ldr r12, [pc, #0x380] */
/* @0x195da0 add r12, pc, r12 */
/* @0x195da4 str r12, [sp, #0x2c] */
/* @0x195da8 ldr r12, [sp, #0x30] */
/* @0x195dac str r12, [sp, #0x8] */
/* @0x195db0 ldr r12, [sp, #0x8] */
/* @0x195db4 ldr r3, [r12, #0x8] */
/* @0x195db8 cmp r3, #0 */
/* @0x195dbc ble 0x195ec0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x318> */
/* @0x195dc0 ldr r12, [r12] */
/* @0x195dc4 ldr r3, [r11, #0x4] */
/* @0x195dc8 ldr r2, [r11, #0xc] */
/* @0x195dcc str r12, [sp, #0x10] */
/* @0x195dd0 ldr r12, [sp, #0x8] */
/* @0x195dd4 cmp r3, r2 */
/* @0x195dd8 ldr r12, [r12, #0x4] */
/* @0x195ddc str r12, [sp, #0x18] */
/* @0x195de0 bgt 0x195f30 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x388> */
/* @0x195de4 add r3, r3, #1 */
/* @0x195de8 ldr r0, [sp, #0x10] */
/* @0x195dec str r3, [r11, #0x4] */
/* @0x195df0 bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_> */
/* @0x195df4 ldr lr, [r11, #0x8] */
/* @0x195df8 ldr r6, [r11, #0x10] */
/* @0x195dfc bic r0, r0, #-2147483648 */
/* @0x195e00 and r3, r0, lr */
/* @0x195e04 add r2, r3, r3, lsl #1 */
/* @0x195e08 add r2, r6, r2, lsl #2 */
/* @0x195e0c ldr r1, [r2, #0x8] */
/* @0x195e10 cmp r1, #0 */
/* @0x195e14 beq 0x195f18 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x370> */
/* @0x195e18 ldr r7, [r11] */
/* @0x195e1c mov r4, #0 */
/* @0x195e20 ldr r8, [sp, #0x10] */
/* @0x195e24 ldr r9, [sp, #0x18] */
/* @0x195e28 b 0x195e6c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x2c4> */
/* @0x195e2c ldr r5, [r2] */
/* @0x195e30 ldr r4, [r2, #0x4] */
/* @0x195e34 str r0, [r2, #0x8] */
/* @0x195e38 mov r0, r1 */
/* @0x195e3c str r8, [r2] */
/* @0x195e40 mov r8, r5 */
/* @0x195e44 str r9, [r2, #0x4] */
/* @0x195e48 mov r9, r4 */
/* @0x195e4c add r3, r3, #1 */
/* @0x195e50 add r4, r12, #1 */
/* @0x195e54 and r3, r3, lr */
/* @0x195e58 add r2, r3, r3, lsl #1 */
/* @0x195e5c add r2, r6, r2, lsl #2 */
/* @0x195e60 ldr r1, [r2, #0x8] */
/* @0x195e64 cmp r1, #0 */
/* @0x195e68 beq 0x195f10 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x368> */
/* @0x195e6c add r12, r7, r3 */
/* @0x195e70 and r5, r1, lr */
/* @0x195e74 rsb r12, r5, r12 */
/* @0x195e78 and r12, r12, lr */
/* @0x195e7c cmp r12, r4 */
/* @0x195e80 blt 0x195e2c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x284> */
/* @0x195e84 movne r12, r4 */
/* @0x195e88 bne 0x195e4c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x2a4> */
/* @0x195e8c cmp r1, r0 */
/* @0x195e90 bne 0x195e4c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x2a4> */
/* @0x195e94 ldr r4, [r2] */
/* @0x195e98 cmp r8, r4 */
/* @0x195e9c bne 0x195e4c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x2a4> */
/* @0x195ea0 ldr r3, [r11, #0x4] */
/* @0x195ea4 str r8, [sp, #0x10] */
/* @0x195ea8 str r8, [r2] */
/* @0x195eac sub r3, r3, #1 */
/* @0x195eb0 str r9, [r2, #0x4] */
/* @0x195eb4 str r1, [r2, #0x8] */
/* @0x195eb8 str r9, [sp, #0x18] */
/* @0x195ebc str r3, [r11, #0x4] */
/* @0x195ec0 ldr r12, [sp, #0xc] */
/* @0x195ec4 ldr r0, [sp, #0x20] */
/* @0x195ec8 add r12, r12, #1 */
/* @0x195ecc str r12, [sp, #0xc] */
/* @0x195ed0 ldr r12, [sp, #0x8] */
/* @0x195ed4 add r12, r12, #12 */
/* @0x195ed8 str r12, [sp, #0x8] */
/* @0x195edc ldr r12, [sp, #0xc] */
/* @0x195ee0 cmp r12, r0 */
/* @0x195ee4 bne 0x195db0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x208> */
/* @0x195ee8 ldr r0, [sp, #0x30] */
/* @0x195eec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x195ef0 vldr s13, [r11] */
/* @0x195ef4 vcvt.f32.s32 s14, s13 */
/* @0x195ef8 vldr s15, [pc, #536] */
/* @0x195efc ldr r3, [r11, #0x4] */
/* @0x195f00 vmul.f32 s15, s14, s15 */
/* @0x195f04 vcvt.s32.f32 s15, s15 */
/* @0x195f08 vstr s15, [r11, #12] */
/* @0x195f0c b 0x195bd0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x28> */
/* @0x195f10 str r8, [sp, #0x10] */
/* @0x195f14 str r9, [sp, #0x18] */
/* @0x195f18 ldr r12, [sp, #0x10] */
/* @0x195f1c str r0, [r2, #0x8] */
/* @0x195f20 str r12, [r2] */
/* @0x195f24 ldr r12, [sp, #0x18] */
/* @0x195f28 str r12, [r2, #0x4] */
/* @0x195f2c b 0x195ec0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x318> */
/* @0x195f30 ldr r12, [r11] */
/* @0x195f34 mov r3, #1 */
/* @0x195f38 ldr r1, [sp, #0x34] */
/* @0x195f3c mov r2, #70 */
/* @0x195f40 str r12, [sp, #0x14] */
/* @0x195f44 ldr r12, [r11, #0x10] */
/* @0x195f48 str r12, [sp, #0x28] */
/* @0x195f4c ldr r12, [sp, #0x14] */
/* @0x195f50 lsl r0, r12, r3 */
/* @0x195f54 str r0, [r11] */
/* @0x195f58 add r4, r0, r12, lsl #2 */
/* @0x195f5c sub r0, r0, #1 */
/* @0x195f60 str r0, [r11, #0x8] */
/* @0x195f64 lsl r4, r4, #2 */
/* @0x195f68 mov r0, r4 */
/* @0x195f6c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x195f70 mov r2, r4 */
/* @0x195f74 mov r1, #0 */
/* @0x195f78 str r0, [r11, #0x10] */
/* @0x195f7c bl 0xb65b0 <memset@plt> */
/* @0x195f80 ldr r2, [r11] */
/* @0x195f84 mov r0, #0 */
/* @0x195f88 str r0, [r11, #0x4] */
/* @0x195f8c cmp r2, r0 */
/* @0x195f90 vmov s13, r2 */
/* @0x195f94 vcvt.f32.s32 s15, s13 */
/* @0x195f98 vmul.f32 s15, s15, s16 */
/* @0x195f9c vcvt.s32.f32 s15, s15 */
/* @0x195fa0 vstr s15, [r11, #12] */
/* @0x195fa4 ble 0x195fc8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x420> */
/* @0x195fa8 add r2, r2, r2, lsl #1 */
/* @0x195fac ldr r3, [r11, #0x10] */
/* @0x195fb0 add r2, r3, r2, lsl #2 */
/* @0x195fb4 mov r0, #0 */
/* @0x195fb8 add r3, r3, #12 */
/* @0x195fbc str r0, [r3, #-0x4] */
/* @0x195fc0 cmp r3, r2 */
/* @0x195fc4 bne 0x195fb4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x40c> */
/* @0x195fc8 ldr r12, [sp, #0x14] */
/* @0x195fcc cmp r12, #0 */
/* @0x195fd0 ble 0x1960e8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x540> */
/* @0x195fd4 ldr r6, [sp, #0x28] */
/* @0x195fd8 mov r12, #0 */
/* @0x195fdc str r12, [sp, #0x4] */
/* @0x195fe0 ldr r3, [r6, #0x8] */
/* @0x195fe4 cmp r3, #0 */
/* @0x195fe8 ble 0x1960cc <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x524> */
/* @0x195fec ldr r3, [r11, #0x4] */
/* @0x195ff0 ldr r2, [r11, #0xc] */
/* @0x195ff4 ldr r4, [r6] */
/* @0x195ff8 cmp r3, r2 */
/* @0x195ffc ldr r5, [r6, #0x4] */
/* @0x196000 bgt 0x196128 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x580> */
/* @0x196004 add r3, r3, #1 */
/* @0x196008 mov r0, r4 */
/* @0x19600c str r3, [r11, #0x4] */
/* @0x196010 bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_> */
/* @0x196014 ldr lr, [r11, #0x8] */
/* @0x196018 ldr r9, [r11, #0x10] */
/* @0x19601c bic r0, r0, #-2147483648 */
/* @0x196020 and r3, r0, lr */
/* @0x196024 add r2, r3, r3, lsl #1 */
/* @0x196028 add r2, r9, r2, lsl #2 */
/* @0x19602c ldr r1, [r2, #0x8] */
/* @0x196030 cmp r1, #0 */
/* @0x196034 ldrne r10, [r11] */
/* @0x196038 movne r7, #0 */
/* @0x19603c bne 0x196084 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x4dc> */
/* @0x196040 b 0x19610c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x564> */
/* @0x196044 ldr r8, [r2] */
/* @0x196048 ldr r7, [r2, #0x4] */
/* @0x19604c str r0, [r2, #0x8] */
/* @0x196050 mov r0, r1 */
/* @0x196054 str r4, [r2] */
/* @0x196058 mov r4, r8 */
/* @0x19605c str r5, [r2, #0x4] */
/* @0x196060 mov r5, r7 */
/* @0x196064 add r3, r3, #1 */
/* @0x196068 add r7, r12, #1 */
/* @0x19606c and r3, r3, lr */
/* @0x196070 add r2, r3, r3, lsl #1 */
/* @0x196074 add r2, r9, r2, lsl #2 */
/* @0x196078 ldr r1, [r2, #0x8] */
/* @0x19607c cmp r1, #0 */
/* @0x196080 beq 0x19610c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x564> */
/* @0x196084 add r12, r3, r10 */
/* @0x196088 and r8, r1, lr */
/* @0x19608c rsb r12, r8, r12 */
/* @0x196090 and r12, r12, lr */
/* @0x196094 cmp r12, r7 */
/* @0x196098 blt 0x196044 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x49c> */
/* @0x19609c movne r12, r7 */
/* @0x1960a0 bne 0x196064 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x4bc> */
/* @0x1960a4 cmp r1, r0 */
/* @0x1960a8 bne 0x196064 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x4bc> */
/* @0x1960ac ldr r7, [r2] */
/* @0x1960b0 cmp r4, r7 */
/* @0x1960b4 bne 0x196064 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x4bc> */
/* @0x1960b8 ldr r3, [r11, #0x4] */
/* @0x1960bc stm r2, {r4, r5} */
/* @0x1960c0 sub r3, r3, #1 */
/* @0x1960c4 str r1, [r2, #0x8] */
/* @0x1960c8 str r3, [r11, #0x4] */
/* @0x1960cc ldr r12, [sp, #0x4] */
/* @0x1960d0 add r6, r6, #12 */
/* @0x1960d4 ldr r0, [sp, #0x14] */
/* @0x1960d8 add r12, r12, #1 */
/* @0x1960dc str r12, [sp, #0x4] */
/* @0x1960e0 cmp r12, r0 */
/* @0x1960e4 bne 0x195fe0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x438> */
/* @0x1960e8 ldr r0, [sp, #0x28] */
/* @0x1960ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1960f0 vldr s13, [r11] */
/* @0x1960f4 vcvt.f32.s32 s15, s13 */
/* @0x1960f8 ldr r3, [r11, #0x4] */
/* @0x1960fc vmul.f32 s15, s15, s16 */
/* @0x196100 vcvt.s32.f32 s15, s15 */
/* @0x196104 vstr s15, [r11, #12] */
/* @0x196108 b 0x195de4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x23c> */
/* @0x19610c stm r2, {r4, r5} */
/* @0x196110 str r0, [r2, #0x8] */
/* @0x196114 b 0x1960cc <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x524> */
/* @0x196118 svclo #0x19999a */
/* @0x19611c andseq r11, r9, r0, asr #6 */
/* @0x196120 andseq r11, r9, r4, lsr #5 */
/* @0x196124 mulseq r9, r0, r2 */
/* @0x196128 ldr r8, [r11] */
/* @0x19612c mov r3, #1 */
/* @0x196130 ldr r1, [sp, #0x2c] */
/* @0x196134 mov r2, #70 */
/* @0x196138 ldr r7, [r11, #0x10] */
/* @0x19613c lsl r0, r8, r3 */
/* @0x196140 str r0, [r11] */
/* @0x196144 add r9, r0, r8, lsl #2 */
/* @0x196148 sub r0, r0, #1 */
/* @0x19614c str r0, [r11, #0x8] */
/* @0x196150 lsl r9, r9, #2 */
/* @0x196154 mov r0, r9 */
/* @0x196158 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19615c mov r2, r9 */
/* @0x196160 mov r1, #0 */
/* @0x196164 str r0, [r11, #0x10] */
/* @0x196168 bl 0xb65b0 <memset@plt> */
/* @0x19616c ldr r2, [r11] */
/* @0x196170 mov r0, #0 */
/* @0x196174 str r0, [r11, #0x4] */
/* @0x196178 cmp r2, r0 */
/* @0x19617c vmov s13, r2 */
/* @0x196180 vcvt.f32.s32 s15, s13 */
/* @0x196184 vmul.f32 s15, s15, s16 */
/* @0x196188 vcvt.s32.f32 s15, s15 */
/* @0x19618c vstr s15, [r11, #12] */
/* @0x196190 ble 0x1961b4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x60c> */
/* @0x196194 add r2, r2, r2, lsl #1 */
/* @0x196198 ldr r3, [r11, #0x10] */
/* @0x19619c add r2, r3, r2, lsl #2 */
/* @0x1961a0 mov r0, #0 */
/* @0x1961a4 add r3, r3, #12 */
/* @0x1961a8 str r0, [r3, #-0x4] */
/* @0x1961ac cmp r3, r2 */
/* @0x1961b0 bne 0x1961a0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x5f8> */
/* @0x1961b4 cmp r8, #0 */
/* @0x1961b8 movgt r9, r7 */
/* @0x1961bc movgt r10, #0 */
/* @0x1961c0 ble 0x1961ec <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x644> */
/* @0x1961c4 ldr r3, [r9, #0x8] */
/* @0x1961c8 mov r0, r11 */
/* @0x1961cc add r10, r10, #1 */
/* @0x1961d0 cmp r3, #0 */
/* @0x1961d4 ble 0x1961e0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x638> */
/* @0x1961d8 ldm r9, {r1, r2} */
/* @0x1961dc bl 0x195ba8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_> */
/* @0x1961e0 cmp r10, r8 */
/* @0x1961e4 add r9, r9, #12 */
/* @0x1961e8 bne 0x1961c4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x61c> */
/* @0x1961ec mov r0, r7 */
/* @0x1961f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1961f4 vldr s13, [r11] */
/* @0x1961f8 vcvt.f32.s32 s15, s13 */
/* @0x1961fc ldr r3, [r11, #0x4] */
/* @0x196200 vmul.f32 s15, s15, s16 */
/* @0x196204 vcvt.s32.f32 s15, s15 */
/* @0x196208 vstr s15, [r11, #12] */
/* @0x19620c b 0x196004 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x45c> */

/* ── FUNC 0x196210 · CGCGeneration::AddRoot(YYObjectBase*) · size=504 · insn=126 */
/* @0x196210 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x196214 subs r7, r1, #0 */
/* @0x196218 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19621c ldr r8, [r0] */
/* @0x196220 ldr r3, [r8, #0x4] */
/* @0x196224 ldr r2, [r8, #0xc] */
/* @0x196228 cmp r3, r2 */
/* @0x19622c bgt 0x196310 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x100> */
/* @0x196230 add r3, r3, #1 */
/* @0x196234 mov r0, r7 */
/* @0x196238 str r3, [r8, #0x4] */
/* @0x19623c bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_> */
/* @0x196240 ldr r5, [r8, #0x8] */
/* @0x196244 ldr r9, [r8, #0x10] */
/* @0x196248 bic r0, r0, #-2147483648 */
/* @0x19624c and r3, r0, r5 */
/* @0x196250 add r2, r3, r3, lsl #1 */
/* @0x196254 add r2, r9, r2, lsl #2 */
/* @0x196258 ldr r12, [r2, #0x8] */
/* @0x19625c cmp r12, #0 */
/* @0x196260 beq 0x196300 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0xf0> */
/* @0x196264 ldr r10, [r8] */
/* @0x196268 mov r1, r7 */
/* @0x19626c mov r6, #0 */
/* @0x196270 b 0x1962b4 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0xa4> */
/* @0x196274 ldr r11, [r2] */
/* @0x196278 ldr r6, [r2, #0x4] */
/* @0x19627c str r0, [r2, #0x8] */
/* @0x196280 mov r0, r12 */
/* @0x196284 str r1, [r2] */
/* @0x196288 mov r1, r11 */
/* @0x19628c str r7, [r2, #0x4] */
/* @0x196290 mov r7, r6 */
/* @0x196294 add r3, r3, #1 */
/* @0x196298 add r6, r4, #1 */
/* @0x19629c and r3, r3, r5 */
/* @0x1962a0 add r2, r3, r3, lsl #1 */
/* @0x1962a4 add r2, r9, r2, lsl #2 */
/* @0x1962a8 ldr r12, [r2, #0x8] */
/* @0x1962ac cmp r12, #0 */
/* @0x1962b0 beq 0x196304 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0xf4> */
/* @0x1962b4 add r4, r10, r3 */
/* @0x1962b8 and r11, r12, r5 */
/* @0x1962bc rsb r4, r11, r4 */
/* @0x1962c0 and r4, r4, r5 */
/* @0x1962c4 cmp r4, r6 */
/* @0x1962c8 blt 0x196274 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x64> */
/* @0x1962cc movne r4, r6 */
/* @0x1962d0 bne 0x196294 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x84> */
/* @0x1962d4 cmp r12, r0 */
/* @0x1962d8 bne 0x196294 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x84> */
/* @0x1962dc ldr r6, [r2] */
/* @0x1962e0 cmp r1, r6 */
/* @0x1962e4 bne 0x196294 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x84> */
/* @0x1962e8 ldr r3, [r8, #0x4] */
/* @0x1962ec stm r2, {r1, r7} */
/* @0x1962f0 sub r3, r3, #1 */
/* @0x1962f4 str r12, [r2, #0x8] */
/* @0x1962f8 str r3, [r8, #0x4] */
/* @0x1962fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x196300 mov r1, r7 */
/* @0x196304 stm r2, {r1, r7} */
/* @0x196308 str r0, [r2, #0x8] */
/* @0x19630c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x196310 ldr r6, [r8] */
/* @0x196314 mov r3, #1 */
/* @0x196318 ldr r1, [pc, #0xe4] */
/* @0x19631c mov r2, #70 */
/* @0x196320 ldr r9, [r8, #0x10] */
/* @0x196324 lsl r0, r6, r3 */
/* @0x196328 add r1, pc, r1 */
/* @0x19632c add r4, r0, r6, lsl #2 */
/* @0x196330 str r0, [r8] */
/* @0x196334 sub r0, r0, #1 */
/* @0x196338 str r0, [r8, #0x8] */
/* @0x19633c lsl r4, r4, #2 */
/* @0x196340 mov r0, r4 */
/* @0x196344 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x196348 mov r2, r4 */
/* @0x19634c mov r1, #0 */
/* @0x196350 str r0, [r8, #0x10] */
/* @0x196354 bl 0xb65b0 <memset@plt> */
/* @0x196358 ldr r2, [r8] */
/* @0x19635c vldr s15, [pc, #156] */
/* @0x196360 mov r1, #0 */
/* @0x196364 cmp r2, r1 */
/* @0x196368 str r1, [r8, #0x4] */
/* @0x19636c vmov s13, r2 */
/* @0x196370 vcvt.f32.s32 s14, s13 */
/* @0x196374 vmul.f32 s15, s14, s15 */
/* @0x196378 vcvt.s32.f32 s15, s15 */
/* @0x19637c vstr s15, [r8, #12] */
/* @0x196380 ble 0x1963a0 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x190> */
/* @0x196384 add r2, r2, r2, lsl #1 */
/* @0x196388 ldr r3, [r8, #0x10] */
/* @0x19638c add r2, r3, r2, lsl #2 */
/* @0x196390 str r1, [r3, #0x8] */
/* @0x196394 add r3, r3, #12 */
/* @0x196398 cmp r3, r2 */
/* @0x19639c bne 0x196390 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x180> */
/* @0x1963a0 cmp r6, #0 */
/* @0x1963a4 movgt r4, r9 */
/* @0x1963a8 movgt r5, #0 */
/* @0x1963ac ble 0x1963d8 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x1c8> */
/* @0x1963b0 ldr r3, [r4, #0x8] */
/* @0x1963b4 mov r0, r8 */
/* @0x1963b8 add r5, r5, #1 */
/* @0x1963bc cmp r3, #0 */
/* @0x1963c0 ble 0x1963cc <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x1bc> */
/* @0x1963c4 ldm r4, {r1, r2} */
/* @0x1963c8 bl 0x195ba8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_> */
/* @0x1963cc cmp r5, r6 */
/* @0x1963d0 add r4, r4, #12 */
/* @0x1963d4 bne 0x1963b0 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x1a0> */
/* @0x1963d8 mov r0, r9 */
/* @0x1963dc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1963e0 vldr s13, [r8] */
/* @0x1963e4 vcvt.f32.s32 s14, s13 */
/* @0x1963e8 vldr s15, [pc, #16] */
/* @0x1963ec ldr r3, [r8, #0x4] */
/* @0x1963f0 vmul.f32 s15, s14, s15 */
/* @0x1963f4 vcvt.s32.f32 s15, s15 */
/* @0x1963f8 vstr s15, [r8, #12] */
/* @0x1963fc b 0x196230 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x20> */
/* @0x196400 svclo #0x19999a */
/* @0x196404 andseq r10, r9, r8, lsl #26 */

/* ── FUNC 0x196408 · CHashMap<int, RValue*, 3>::Insert(int, RValue*) · size=1640 · insn=410 */
/* @0x196408 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19640c vpush {d8} */
/* @0x196410 sub sp, sp, #60 */
/* @0x196414 ldr r3, [r0, #0x4] */
/* @0x196418 mov r11, r0 */
/* @0x19641c str r2, [sp, #0x24] */
/* @0x196420 ldr r2, [r0, #0xc] */
/* @0x196424 str r1, [sp, #0x1c] */
/* @0x196428 cmp r3, r2 */
/* @0x19642c bgt 0x19653c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x134> */
/* @0x196430 add r3, r3, #1 */
/* @0x196434 ldr r0, [sp, #0x1c] */
/* @0x196438 str r3, [r11, #0x4] */
/* @0x19643c bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x196440 ldr r4, [r11, #0x8] */
/* @0x196444 ldr r6, [r11, #0x10] */
/* @0x196448 bic r0, r0, #-2147483648 */
/* @0x19644c and r3, r0, r4 */
/* @0x196450 add r2, r3, r3, lsl #1 */
/* @0x196454 add r2, r6, r2, lsl #2 */
/* @0x196458 ldr r12, [r2, #0x8] */
/* @0x19645c cmp r12, #0 */
/* @0x196460 beq 0x19651c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x114> */
/* @0x196464 ldr r7, [r11] */
/* @0x196468 mov r1, #0 */
/* @0x19646c ldr r8, [sp, #0x1c] */
/* @0x196470 ldr r9, [sp, #0x24] */
/* @0x196474 b 0x1964bc <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0xb4> */
/* @0x196478 ldr r10, [r2] */
/* @0x19647c mov r1, r5 */
/* @0x196480 ldr r5, [r2, #0x4] */
/* @0x196484 str r0, [r2, #0x8] */
/* @0x196488 mov r0, r12 */
/* @0x19648c str r8, [r2] */
/* @0x196490 mov r8, r10 */
/* @0x196494 str r9, [r2, #0x4] */
/* @0x196498 mov r9, r5 */
/* @0x19649c add r3, r3, #1 */
/* @0x1964a0 add r1, r1, #1 */
/* @0x1964a4 and r3, r3, r4 */
/* @0x1964a8 add r2, r3, r3, lsl #1 */
/* @0x1964ac add r2, r6, r2, lsl #2 */
/* @0x1964b0 ldr r12, [r2, #0x8] */
/* @0x1964b4 cmp r12, #0 */
/* @0x1964b8 beq 0x196514 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x10c> */
/* @0x1964bc add r5, r7, r3 */
/* @0x1964c0 and r10, r12, r4 */
/* @0x1964c4 rsb r5, r10, r5 */
/* @0x1964c8 and r5, r5, r4 */
/* @0x1964cc cmp r5, r1 */
/* @0x1964d0 blt 0x196478 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x70> */
/* @0x1964d4 cmp r1, r5 */
/* @0x1964d8 bne 0x19649c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x94> */
/* @0x1964dc cmp r0, r12 */
/* @0x1964e0 bne 0x19649c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x94> */
/* @0x1964e4 ldr r12, [r2] */
/* @0x1964e8 cmp r8, r12 */
/* @0x1964ec bne 0x19649c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x94> */
/* @0x1964f0 ldr r3, [r11, #0x4] */
/* @0x1964f4 str r8, [sp, #0x1c] */
/* @0x1964f8 str r8, [r2] */
/* @0x1964fc sub r3, r3, #1 */
/* @0x196500 str r9, [r2, #0x4] */
/* @0x196504 str r0, [r2, #0x8] */
/* @0x196508 str r9, [sp, #0x24] */
/* @0x19650c str r3, [r11, #0x4] */
/* @0x196510 b 0x196530 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x128> */
/* @0x196514 str r8, [sp, #0x1c] */
/* @0x196518 str r9, [sp, #0x24] */
/* @0x19651c ldr r12, [sp, #0x1c] */
/* @0x196520 str r0, [r2, #0x8] */
/* @0x196524 str r12, [r2] */
/* @0x196528 ldr r12, [sp, #0x24] */
/* @0x19652c str r12, [r2, #0x4] */
/* @0x196530 add sp, sp, #60 */
/* @0x196534 vpop {d8} */
/* @0x196538 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19653c ldr r12, [r0] */
/* @0x196540 mov r3, #1 */
/* @0x196544 ldr r1, [pc, #0x430] */
/* @0x196548 mov r2, #70 */
/* @0x19654c str r12, [sp, #0x20] */
/* @0x196550 add r1, pc, r1 */
/* @0x196554 ldr r12, [r0, #0x10] */
/* @0x196558 str r12, [sp, #0x30] */
/* @0x19655c ldr r12, [sp, #0x20] */
/* @0x196560 lsl r0, r12, r3 */
/* @0x196564 str r0, [r11] */
/* @0x196568 add r4, r0, r12, lsl #2 */
/* @0x19656c sub r0, r0, #1 */
/* @0x196570 str r0, [r11, #0x8] */
/* @0x196574 lsl r4, r4, #2 */
/* @0x196578 mov r0, r4 */
/* @0x19657c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x196580 mov r2, r4 */
/* @0x196584 mov r1, #0 */
/* @0x196588 str r0, [r11, #0x10] */
/* @0x19658c bl 0xb65b0 <memset@plt> */
/* @0x196590 ldr r2, [r11] */
/* @0x196594 vldr s15, [pc, #988] */
/* @0x196598 mov r1, #0 */
/* @0x19659c cmp r2, r1 */
/* @0x1965a0 str r1, [r11, #0x4] */
/* @0x1965a4 vmov s13, r2 */
/* @0x1965a8 vcvt.f32.s32 s14, s13 */
/* @0x1965ac vmul.f32 s15, s14, s15 */
/* @0x1965b0 vcvt.s32.f32 s15, s15 */
/* @0x1965b4 vstr s15, [r11, #12] */
/* @0x1965b8 ble 0x1965d8 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x1d0> */
/* @0x1965bc add r2, r2, r2, lsl #1 */
/* @0x1965c0 ldr r3, [r11, #0x10] */
/* @0x1965c4 add r2, r3, r2, lsl #2 */
/* @0x1965c8 str r1, [r3, #0x8] */
/* @0x1965cc add r3, r3, #12 */
/* @0x1965d0 cmp r3, r2 */
/* @0x1965d4 bne 0x1965c8 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x1c0> */
/* @0x1965d8 ldr r12, [sp, #0x20] */
/* @0x1965dc cmp r12, #0 */
/* @0x1965e0 ble 0x196748 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x340> */
/* @0x1965e4 ldr r12, [pc, #0x394] */
/* @0x1965e8 vldr s16, [pc, #904] */
/* @0x1965ec add r12, pc, r12 */
/* @0x1965f0 str r12, [sp, #0x34] */
/* @0x1965f4 mov r12, #0 */
/* @0x1965f8 str r12, [sp, #0xc] */
/* @0x1965fc ldr r12, [pc, #0x380] */
/* @0x196600 add r12, pc, r12 */
/* @0x196604 str r12, [sp, #0x2c] */
/* @0x196608 ldr r12, [sp, #0x30] */
/* @0x19660c str r12, [sp, #0x8] */
/* @0x196610 ldr r12, [sp, #0x8] */
/* @0x196614 ldr r3, [r12, #0x8] */
/* @0x196618 cmp r3, #0 */
/* @0x19661c ble 0x196720 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x318> */
/* @0x196620 ldr r12, [r12] */
/* @0x196624 ldr r3, [r11, #0x4] */
/* @0x196628 ldr r2, [r11, #0xc] */
/* @0x19662c str r12, [sp, #0x10] */
/* @0x196630 ldr r12, [sp, #0x8] */
/* @0x196634 cmp r3, r2 */
/* @0x196638 ldr r12, [r12, #0x4] */
/* @0x19663c str r12, [sp, #0x18] */
/* @0x196640 bgt 0x196790 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x388> */
/* @0x196644 add r3, r3, #1 */
/* @0x196648 ldr r0, [sp, #0x10] */
/* @0x19664c str r3, [r11, #0x4] */
/* @0x196650 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x196654 ldr lr, [r11, #0x8] */
/* @0x196658 ldr r6, [r11, #0x10] */
/* @0x19665c bic r0, r0, #-2147483648 */
/* @0x196660 and r3, r0, lr */
/* @0x196664 add r2, r3, r3, lsl #1 */
/* @0x196668 add r2, r6, r2, lsl #2 */
/* @0x19666c ldr r1, [r2, #0x8] */
/* @0x196670 cmp r1, #0 */
/* @0x196674 beq 0x196778 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x370> */
/* @0x196678 ldr r7, [r11] */
/* @0x19667c mov r4, #0 */
/* @0x196680 ldr r8, [sp, #0x10] */
/* @0x196684 ldr r9, [sp, #0x18] */
/* @0x196688 b 0x1966cc <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x2c4> */
/* @0x19668c ldr r5, [r2] */
/* @0x196690 ldr r4, [r2, #0x4] */
/* @0x196694 str r0, [r2, #0x8] */
/* @0x196698 mov r0, r1 */
/* @0x19669c str r8, [r2] */
/* @0x1966a0 mov r8, r5 */
/* @0x1966a4 str r9, [r2, #0x4] */
/* @0x1966a8 mov r9, r4 */
/* @0x1966ac add r3, r3, #1 */
/* @0x1966b0 add r4, r12, #1 */
/* @0x1966b4 and r3, r3, lr */
/* @0x1966b8 add r2, r3, r3, lsl #1 */
/* @0x1966bc add r2, r6, r2, lsl #2 */
/* @0x1966c0 ldr r1, [r2, #0x8] */
/* @0x1966c4 cmp r1, #0 */
/* @0x1966c8 beq 0x196770 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x368> */
/* @0x1966cc add r12, r7, r3 */
/* @0x1966d0 and r5, r1, lr */
/* @0x1966d4 rsb r12, r5, r12 */
/* @0x1966d8 and r12, r12, lr */
/* @0x1966dc cmp r12, r4 */
/* @0x1966e0 blt 0x19668c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x284> */
/* @0x1966e4 movne r12, r4 */
/* @0x1966e8 bne 0x1966ac <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x2a4> */
/* @0x1966ec cmp r1, r0 */
/* @0x1966f0 bne 0x1966ac <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x2a4> */
/* @0x1966f4 ldr r4, [r2] */
/* @0x1966f8 cmp r8, r4 */
/* @0x1966fc bne 0x1966ac <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x2a4> */
/* @0x196700 ldr r3, [r11, #0x4] */
/* @0x196704 str r8, [sp, #0x10] */
/* @0x196708 str r8, [r2] */
/* @0x19670c sub r3, r3, #1 */
/* @0x196710 str r9, [r2, #0x4] */
/* @0x196714 str r1, [r2, #0x8] */
/* @0x196718 str r9, [sp, #0x18] */
/* @0x19671c str r3, [r11, #0x4] */
/* @0x196720 ldr r12, [sp, #0xc] */
/* @0x196724 ldr r0, [sp, #0x20] */
/* @0x196728 add r12, r12, #1 */
/* @0x19672c str r12, [sp, #0xc] */
/* @0x196730 ldr r12, [sp, #0x8] */
/* @0x196734 add r12, r12, #12 */
/* @0x196738 str r12, [sp, #0x8] */
/* @0x19673c ldr r12, [sp, #0xc] */
/* @0x196740 cmp r12, r0 */
/* @0x196744 bne 0x196610 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x208> */
/* @0x196748 ldr r0, [sp, #0x30] */
/* @0x19674c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x196750 vldr s13, [r11] */
/* @0x196754 vcvt.f32.s32 s14, s13 */
/* @0x196758 vldr s15, [pc, #536] */
/* @0x19675c ldr r3, [r11, #0x4] */
/* @0x196760 vmul.f32 s15, s14, s15 */
/* @0x196764 vcvt.s32.f32 s15, s15 */
/* @0x196768 vstr s15, [r11, #12] */
/* @0x19676c b 0x196430 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x28> */
/* @0x196770 str r8, [sp, #0x10] */
/* @0x196774 str r9, [sp, #0x18] */
/* @0x196778 ldr r12, [sp, #0x10] */
/* @0x19677c str r0, [r2, #0x8] */
/* @0x196780 str r12, [r2] */
/* @0x196784 ldr r12, [sp, #0x18] */
/* @0x196788 str r12, [r2, #0x4] */
/* @0x19678c b 0x196720 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x318> */
/* @0x196790 ldr r12, [r11] */
/* @0x196794 mov r3, #1 */
/* @0x196798 ldr r1, [sp, #0x34] */
/* @0x19679c mov r2, #70 */
/* @0x1967a0 str r12, [sp, #0x14] */
/* @0x1967a4 ldr r12, [r11, #0x10] */
/* @0x1967a8 str r12, [sp, #0x28] */
/* @0x1967ac ldr r12, [sp, #0x14] */
/* @0x1967b0 lsl r0, r12, r3 */
/* @0x1967b4 str r0, [r11] */
/* @0x1967b8 add r4, r0, r12, lsl #2 */
/* @0x1967bc sub r0, r0, #1 */
/* @0x1967c0 str r0, [r11, #0x8] */
/* @0x1967c4 lsl r4, r4, #2 */
/* @0x1967c8 mov r0, r4 */
/* @0x1967cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1967d0 mov r2, r4 */
/* @0x1967d4 mov r1, #0 */
/* @0x1967d8 str r0, [r11, #0x10] */
/* @0x1967dc bl 0xb65b0 <memset@plt> */
/* @0x1967e0 ldr r2, [r11] */
/* @0x1967e4 mov r0, #0 */
/* @0x1967e8 str r0, [r11, #0x4] */
/* @0x1967ec cmp r2, r0 */
/* @0x1967f0 vmov s13, r2 */
/* @0x1967f4 vcvt.f32.s32 s15, s13 */
/* @0x1967f8 vmul.f32 s15, s15, s16 */
/* @0x1967fc vcvt.s32.f32 s15, s15 */
/* @0x196800 vstr s15, [r11, #12] */
/* @0x196804 ble 0x196828 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x420> */
/* @0x196808 add r2, r2, r2, lsl #1 */
/* @0x19680c ldr r3, [r11, #0x10] */
/* @0x196810 add r2, r3, r2, lsl #2 */
/* @0x196814 mov r0, #0 */
/* @0x196818 add r3, r3, #12 */
/* @0x19681c str r0, [r3, #-0x4] */
/* @0x196820 cmp r3, r2 */
/* @0x196824 bne 0x196814 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x40c> */
/* @0x196828 ldr r12, [sp, #0x14] */
/* @0x19682c cmp r12, #0 */
/* @0x196830 ble 0x196948 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x540> */
/* @0x196834 ldr r6, [sp, #0x28] */
/* @0x196838 mov r12, #0 */
/* @0x19683c str r12, [sp, #0x4] */
/* @0x196840 ldr r3, [r6, #0x8] */
/* @0x196844 cmp r3, #0 */
/* @0x196848 ble 0x19692c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x524> */
/* @0x19684c ldr r3, [r11, #0x4] */
/* @0x196850 ldr r2, [r11, #0xc] */
/* @0x196854 ldr r4, [r6] */
/* @0x196858 cmp r3, r2 */
/* @0x19685c ldr r5, [r6, #0x4] */
/* @0x196860 bgt 0x196988 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x580> */
/* @0x196864 add r3, r3, #1 */
/* @0x196868 mov r0, r4 */
/* @0x19686c str r3, [r11, #0x4] */
/* @0x196870 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x196874 ldr lr, [r11, #0x8] */
/* @0x196878 ldr r9, [r11, #0x10] */
/* @0x19687c bic r0, r0, #-2147483648 */
/* @0x196880 and r3, r0, lr */
/* @0x196884 add r2, r3, r3, lsl #1 */
/* @0x196888 add r2, r9, r2, lsl #2 */
/* @0x19688c ldr r1, [r2, #0x8] */
/* @0x196890 cmp r1, #0 */
/* @0x196894 ldrne r10, [r11] */
/* @0x196898 movne r7, #0 */
/* @0x19689c bne 0x1968e4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x4dc> */
/* @0x1968a0 b 0x19696c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x564> */
/* @0x1968a4 ldr r8, [r2] */
/* @0x1968a8 ldr r7, [r2, #0x4] */
/* @0x1968ac str r0, [r2, #0x8] */
/* @0x1968b0 mov r0, r1 */
/* @0x1968b4 str r4, [r2] */
/* @0x1968b8 mov r4, r8 */
/* @0x1968bc str r5, [r2, #0x4] */
/* @0x1968c0 mov r5, r7 */
/* @0x1968c4 add r3, r3, #1 */
/* @0x1968c8 add r7, r12, #1 */
/* @0x1968cc and r3, r3, lr */
/* @0x1968d0 add r2, r3, r3, lsl #1 */
/* @0x1968d4 add r2, r9, r2, lsl #2 */
/* @0x1968d8 ldr r1, [r2, #0x8] */
/* @0x1968dc cmp r1, #0 */
/* @0x1968e0 beq 0x19696c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x564> */
/* @0x1968e4 add r12, r3, r10 */
/* @0x1968e8 and r8, r1, lr */
/* @0x1968ec rsb r12, r8, r12 */
/* @0x1968f0 and r12, r12, lr */
/* @0x1968f4 cmp r12, r7 */
/* @0x1968f8 blt 0x1968a4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x49c> */
/* @0x1968fc movne r12, r7 */
/* @0x196900 bne 0x1968c4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x4bc> */
/* @0x196904 cmp r1, r0 */
/* @0x196908 bne 0x1968c4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x4bc> */
/* @0x19690c ldr r7, [r2] */
/* @0x196910 cmp r4, r7 */
/* @0x196914 bne 0x1968c4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x4bc> */
/* @0x196918 ldr r3, [r11, #0x4] */
/* @0x19691c stm r2, {r4, r5} */
/* @0x196920 sub r3, r3, #1 */
/* @0x196924 str r1, [r2, #0x8] */
/* @0x196928 str r3, [r11, #0x4] */
/* @0x19692c ldr r12, [sp, #0x4] */
/* @0x196930 add r6, r6, #12 */
/* @0x196934 ldr r0, [sp, #0x14] */
/* @0x196938 add r12, r12, #1 */
/* @0x19693c str r12, [sp, #0x4] */
/* @0x196940 cmp r12, r0 */
/* @0x196944 bne 0x196840 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x438> */
/* @0x196948 ldr r0, [sp, #0x28] */
/* @0x19694c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x196950 vldr s13, [r11] */
/* @0x196954 vcvt.f32.s32 s15, s13 */
/* @0x196958 ldr r3, [r11, #0x4] */
/* @0x19695c vmul.f32 s15, s15, s16 */
/* @0x196960 vcvt.s32.f32 s15, s15 */
/* @0x196964 vstr s15, [r11, #12] */
/* @0x196968 b 0x196644 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x23c> */
/* @0x19696c stm r2, {r4, r5} */
/* @0x196970 str r0, [r2, #0x8] */
/* @0x196974 b 0x19692c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x524> */
/* @0x196978 svclo #0x19999a */
/* @0x19697c andseq r10, r9, r0, ror #21 */
/* @0x196980 andseq r10, r9, r4, asr #20 */
/* @0x196984 andseq r10, r9, r0, lsr r10 */
/* @0x196988 ldr r8, [r11] */
/* @0x19698c mov r3, #1 */
/* @0x196990 ldr r1, [sp, #0x2c] */
/* @0x196994 mov r2, #70 */
/* @0x196998 ldr r7, [r11, #0x10] */
/* @0x19699c lsl r0, r8, r3 */
/* @0x1969a0 str r0, [r11] */
/* @0x1969a4 add r9, r0, r8, lsl #2 */
/* @0x1969a8 sub r0, r0, #1 */
/* @0x1969ac str r0, [r11, #0x8] */
/* @0x1969b0 lsl r9, r9, #2 */
/* @0x1969b4 mov r0, r9 */
/* @0x1969b8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1969bc mov r2, r9 */
/* @0x1969c0 mov r1, #0 */
/* @0x1969c4 str r0, [r11, #0x10] */
/* @0x1969c8 bl 0xb65b0 <memset@plt> */
/* @0x1969cc ldr r2, [r11] */
/* @0x1969d0 mov r0, #0 */
/* @0x1969d4 str r0, [r11, #0x4] */
/* @0x1969d8 cmp r2, r0 */
/* @0x1969dc vmov s13, r2 */
/* @0x1969e0 vcvt.f32.s32 s15, s13 */
/* @0x1969e4 vmul.f32 s15, s15, s16 */
/* @0x1969e8 vcvt.s32.f32 s15, s15 */
/* @0x1969ec vstr s15, [r11, #12] */
/* @0x1969f0 ble 0x196a14 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x60c> */
/* @0x1969f4 add r2, r2, r2, lsl #1 */
/* @0x1969f8 ldr r3, [r11, #0x10] */
/* @0x1969fc add r2, r3, r2, lsl #2 */
/* @0x196a00 mov r0, #0 */
/* @0x196a04 add r3, r3, #12 */
/* @0x196a08 str r0, [r3, #-0x4] */
/* @0x196a0c cmp r3, r2 */
/* @0x196a10 bne 0x196a00 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x5f8> */
/* @0x196a14 cmp r8, #0 */
/* @0x196a18 movgt r9, r7 */
/* @0x196a1c movgt r10, #0 */
/* @0x196a20 ble 0x196a4c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x644> */
/* @0x196a24 ldr r3, [r9, #0x8] */
/* @0x196a28 mov r0, r11 */
/* @0x196a2c add r10, r10, #1 */
/* @0x196a30 cmp r3, #0 */
/* @0x196a34 ble 0x196a40 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x638> */
/* @0x196a38 ldm r9, {r1, r2} */
/* @0x196a3c bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_> */
/* @0x196a40 cmp r10, r8 */
/* @0x196a44 add r9, r9, #12 */
/* @0x196a48 bne 0x196a24 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x61c> */
/* @0x196a4c mov r0, r7 */
/* @0x196a50 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x196a54 vldr s13, [r11] */
/* @0x196a58 vcvt.f32.s32 s15, s13 */
/* @0x196a5c ldr r3, [r11, #0x4] */
/* @0x196a60 vmul.f32 s15, s15, s16 */
/* @0x196a64 vcvt.s32.f32 s15, s15 */
/* @0x196a68 vstr s15, [r11, #12] */
/* @0x196a6c b 0x196864 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x45c> */

/* ── FUNC 0x196a70 · YYObjectBase::InternalGetYYVar(int) · size=276 · insn=69 */
/* @0x196a70 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x196a74 mov r7, r0 */
/* @0x196a78 ldr r4, [r0, #0x60] */
/* @0x196a7c mov r8, r1 */
/* @0x196a80 cmp r4, #0 */
/* @0x196a84 beq 0x196b78 <_ZN12YYObjectBase16InternalGetYYVarEi+0x108> */
/* @0x196a88 mov r0, r8 */
/* @0x196a8c bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x196a90 ldr r12, [r4, #0x8] */
/* @0x196a94 ldr r9, [r4, #0x10] */
/* @0x196a98 bic r0, r0, #-2147483648 */
/* @0x196a9c and r3, r12, r0 */
/* @0x196aa0 lsl r5, r3, #1 */
/* @0x196aa4 add r2, r5, r3 */
/* @0x196aa8 add r2, r9, r2, lsl #2 */
/* @0x196aac ldr r2, [r2, #0x8] */
/* @0x196ab0 cmp r2, #0 */
/* @0x196ab4 beq 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* @0x196ab8 cmp r0, r2 */
/* @0x196abc beq 0x196b5c <_ZN12YYObjectBase16InternalGetYYVarEi+0xec> */
/* @0x196ac0 ldr r10, [r4] */
/* @0x196ac4 and r2, r12, r2 */
/* @0x196ac8 add r1, r3, r10 */
/* @0x196acc rsb r2, r2, r1 */
/* @0x196ad0 tst r2, r12 */
/* @0x196ad4 bmi 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* @0x196ad8 mov r4, #0 */
/* @0x196adc b 0x196af0 <_ZN12YYObjectBase16InternalGetYYVarEi+0x80> */
/* @0x196ae0 cmp r0, r2 */
/* @0x196ae4 beq 0x196b54 <_ZN12YYObjectBase16InternalGetYYVarEi+0xe4> */
/* @0x196ae8 cmp r6, r4 */
/* @0x196aec blt 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* @0x196af0 add r3, r3, #1 */
/* @0x196af4 add r4, r4, #1 */
/* @0x196af8 and r3, r12, r3 */
/* @0x196afc add r1, r3, r10 */
/* @0x196b00 lsl r5, r3, #1 */
/* @0x196b04 add r2, r5, r3 */
/* @0x196b08 add r2, r9, r2, lsl #2 */
/* @0x196b0c ldr r2, [r2, #0x8] */
/* @0x196b10 and r6, r12, r2 */
/* @0x196b14 cmp r2, #0 */
/* @0x196b18 rsb r6, r6, r1 */
/* @0x196b1c and r6, r6, r12 */
/* @0x196b20 bne 0x196ae0 <_ZN12YYObjectBase16InternalGetYYVarEi+0x70> */
/* @0x196b24 bl 0x190dc0 <_Z9GetRValuev> */
/* @0x196b28 mov r3, #0 */
/* @0x196b2c mov r1, r8 */
/* @0x196b30 mov r4, r0 */
/* @0x196b34 ldr r0, [r7, #0x58] */
/* @0x196b38 mov r2, r4 */
/* @0x196b3c str r3, [r4] */
/* @0x196b40 str r3, [r4, #0x4] */
/* @0x196b44 str r0, [r4, #0xc] */
/* @0x196b48 ldr r0, [r7, #0x60] */
/* @0x196b4c bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_> */
/* @0x196b50 b 0x196b70 <_ZN12YYObjectBase16InternalGetYYVarEi+0x100> */
/* @0x196b54 cmn r3, #1 */
/* @0x196b58 beq 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* @0x196b5c add r3, r5, r3 */
/* @0x196b60 add r9, r9, r3, lsl #2 */
/* @0x196b64 cmn r9, #4 */
/* @0x196b68 ldrne r4, [r9, #0x4] */
/* @0x196b6c beq 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* @0x196b70 mov r0, r4 */
/* @0x196b74 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x196b78 bl 0x1917dc <_ZN12YYObjectBase9AllocVarsEv> */
/* @0x196b7c ldr r4, [r7, #0x60] */
/* @0x196b80 b 0x196a88 <_ZN12YYObjectBase16InternalGetYYVarEi+0x18> */

/* ── FUNC 0x196b84 · YYObjectBase::FindValue(char const*) · size=64 · insn=16 */
/* @0x196b84 push {r4, lr} */
/* @0x196b88 mov r4, r0 */
/* @0x196b8c bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x196b90 cmn r0, #1 */
/* @0x196b94 mov r1, r0 */
/* @0x196b98 beq 0x196bbc <_ZN12YYObjectBase9FindValueEPKc+0x38> */
/* @0x196b9c ldr r3, [r4, #0x4] */
/* @0x196ba0 cmp r3, #0 */
/* @0x196ba4 beq 0x196bb0 <_ZN12YYObjectBase9FindValueEPKc+0x2c> */
/* @0x196ba8 add r0, r3, r0, lsl #4 */
/* @0x196bac pop {r4, pc} */
/* @0x196bb0 mov r0, r4 */
/* @0x196bb4 pop {r4, lr} */
/* @0x196bb8 b 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x196bbc mov r0, #0 */
/* @0x196bc0 pop {r4, pc} */

/* ── FUNC 0x196bc4 · YYObjectBase::FindOrAllocValue(char const*) · size=48 · insn=12 */
/* @0x196bc4 push {r4, lr} */
/* @0x196bc8 mov r4, r0 */
/* @0x196bcc bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc> */
/* @0x196bd0 ldr r3, [r4, #0x4] */
/* @0x196bd4 cmp r3, #0 */
/* @0x196bd8 mov r1, r0 */
/* @0x196bdc beq 0x196be8 <_ZN12YYObjectBase16FindOrAllocValueEPKc+0x24> */
/* @0x196be0 add r0, r3, r0, lsl #4 */
/* @0x196be4 pop {r4, pc} */
/* @0x196be8 mov r0, r4 */
/* @0x196bec pop {r4, lr} */
/* @0x196bf0 b 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */

/* ── FUNC 0x196bf4 · CInstance::Serialise(IBuffer*) · size=2680 · insn=670 */
/* @0x196bf4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x196bf8 mov r7, r0 */
/* @0x196bfc ldrb r3, [r0, #0x64] */
/* @0x196c00 mov r9, r1 */
/* @0x196c04 cmp r3, #0 */
/* @0x196c08 bne 0x19764c <_ZN9CInstance9SerialiseEP7IBuffer+0xa58> */
/* @0x196c0c vldr s14, [r7, #120] */
/* @0x196c10 vcvt.f64.s32 d7, s14 */
/* @0x196c14 ldr r3, [r9] */
/* @0x196c18 add r6, r9, #44 */
/* @0x196c1c mov r5, #0 */
/* @0x196c20 mov r1, #6 */
/* @0x196c24 mov r2, r6 */
/* @0x196c28 str r5, [r9, #0x38] */
/* @0x196c2c mov r0, r9 */
/* @0x196c30 mov r10, r5 */
/* @0x196c34 mov r11, r7 */
/* @0x196c38 mov r8, #12 */
/* @0x196c3c vstr s14, [r9, #44] */
/* @0x196c40 vstr s15, [r9, #48] */
/* @0x196c44 ldr r3, [r3, #0x8] */
/* @0x196c48 blx r3 */
/* @0x196c4c ldrb r3, [r7, #0x69] */
/* @0x196c50 mov r2, r6 */
/* @0x196c54 str r5, [r9, #0x38] */
/* @0x196c58 mov r1, #6 */
/* @0x196c5c mov r0, r9 */
/* @0x196c60 vmov s14, r3 */
/* @0x196c64 ldr r3, [r9] */
/* @0x196c68 vcvt.f64.u32 d7, s14 */
/* @0x196c6c vstr s14, [r9, #44] */
/* @0x196c70 vstr s15, [r9, #48] */
/* @0x196c74 ldr r3, [r3, #0x8] */
/* @0x196c78 blx r3 */
/* @0x196c7c vldr s14, [r7, #124] */
/* @0x196c80 vcvt.f64.s32 d7, s14 */
/* @0x196c84 ldr r3, [r9] */
/* @0x196c88 mov r2, r6 */
/* @0x196c8c str r5, [r9, #0x38] */
/* @0x196c90 mov r1, #6 */
/* @0x196c94 mov r0, r9 */
/* @0x196c98 vstr s14, [r9, #44] */
/* @0x196c9c vstr s15, [r9, #48] */
/* @0x196ca0 ldr r3, [r3, #0x8] */
/* @0x196ca4 blx r3 */
/* @0x196ca8 vldr s14, [r7, #140] */
/* @0x196cac vcvt.f64.s32 d7, s14 */
/* @0x196cb0 ldr r3, [r9] */
/* @0x196cb4 mov r2, r6 */
/* @0x196cb8 str r5, [r9, #0x38] */
/* @0x196cbc mov r1, #6 */
/* @0x196cc0 mov r0, r9 */
/* @0x196cc4 vstr s14, [r9, #44] */
/* @0x196cc8 vstr s15, [r9, #48] */
/* @0x196ccc ldr r3, [r3, #0x8] */
/* @0x196cd0 blx r3 */
/* @0x196cd4 vldr s14, [r7, #144] */
/* @0x196cd8 vcvt.f64.f32 d7, s14 */
/* @0x196cdc ldr r3, [r9] */
/* @0x196ce0 str r5, [r9, #0x38] */
/* @0x196ce4 mov r2, r6 */
/* @0x196ce8 mov r1, #8 */
/* @0x196cec mov r0, r9 */
/* @0x196cf0 vstr s14, [r9, #44] */
/* @0x196cf4 vstr s15, [r9, #48] */
/* @0x196cf8 ldr r3, [r3, #0x8] */
/* @0x196cfc blx r3 */
/* @0x196d00 vldr s14, [r7, #148] */
/* @0x196d04 vcvt.f64.f32 d7, s14 */
/* @0x196d08 ldr r3, [r9] */
/* @0x196d0c str r5, [r9, #0x38] */
/* @0x196d10 mov r2, r6 */
/* @0x196d14 mov r1, #8 */
/* @0x196d18 mov r0, r9 */
/* @0x196d1c vstr s14, [r9, #44] */
/* @0x196d20 vstr s15, [r9, #48] */
/* @0x196d24 ldr r3, [r3, #0x8] */
/* @0x196d28 blx r3 */
/* @0x196d2c vldr s14, [r7, #152] */
/* @0x196d30 vcvt.f64.f32 d7, s14 */
/* @0x196d34 ldr r3, [r9] */
/* @0x196d38 str r5, [r9, #0x38] */
/* @0x196d3c mov r2, r6 */
/* @0x196d40 mov r1, #8 */
/* @0x196d44 mov r0, r9 */
/* @0x196d48 vstr s14, [r9, #44] */
/* @0x196d4c vstr s15, [r9, #48] */
/* @0x196d50 ldr r3, [r3, #0x8] */
/* @0x196d54 blx r3 */
/* @0x196d58 vldr s14, [r7, #156] */
/* @0x196d5c vcvt.f64.f32 d7, s14 */
/* @0x196d60 ldr r3, [r9] */
/* @0x196d64 str r5, [r9, #0x38] */
/* @0x196d68 mov r2, r6 */
/* @0x196d6c mov r1, #8 */
/* @0x196d70 mov r0, r9 */
/* @0x196d74 vstr s14, [r9, #44] */
/* @0x196d78 vstr s15, [r9, #48] */
/* @0x196d7c ldr r3, [r3, #0x8] */
/* @0x196d80 blx r3 */
/* @0x196d84 vldr s14, [r7, #160] */
/* @0x196d88 vcvt.f64.f32 d7, s14 */
/* @0x196d8c ldr r3, [r9] */
/* @0x196d90 str r5, [r9, #0x38] */
/* @0x196d94 mov r2, r6 */
/* @0x196d98 mov r1, #8 */
/* @0x196d9c mov r0, r9 */
/* @0x196da0 vstr s14, [r9, #44] */
/* @0x196da4 vstr s15, [r9, #48] */
/* @0x196da8 ldr r3, [r3, #0x8] */
/* @0x196dac blx r3 */
/* @0x196db0 vldr s14, [r7, #164] */
/* @0x196db4 vcvt.f64.f32 d7, s14 */
/* @0x196db8 ldr r3, [r9] */
/* @0x196dbc str r5, [r9, #0x38] */
/* @0x196dc0 mov r2, r6 */
/* @0x196dc4 mov r1, #8 */
/* @0x196dc8 mov r0, r9 */
/* @0x196dcc vstr s14, [r9, #44] */
/* @0x196dd0 vstr s15, [r9, #48] */
/* @0x196dd4 ldr r3, [r3, #0x8] */
/* @0x196dd8 blx r3 */
/* @0x196ddc vldr s14, [r7, #168] */
/* @0x196de0 vcvt.f64.u32 d7, s14 */
/* @0x196de4 ldr r3, [r9] */
/* @0x196de8 mov r2, r6 */
/* @0x196dec str r5, [r9, #0x38] */
/* @0x196df0 mov r1, #5 */
/* @0x196df4 mov r0, r9 */
/* @0x196df8 vstr s14, [r9, #44] */
/* @0x196dfc vstr s15, [r9, #48] */
/* @0x196e00 ldr r3, [r3, #0x8] */
/* @0x196e04 blx r3 */
/* @0x196e08 vldr s14, [r7, #172] */
/* @0x196e0c vcvt.f64.s32 d7, s14 */
/* @0x196e10 ldr r3, [r9] */
/* @0x196e14 mov r2, r6 */
/* @0x196e18 str r5, [r9, #0x38] */
/* @0x196e1c mov r1, #6 */
/* @0x196e20 mov r0, r9 */
/* @0x196e24 vstr s14, [r9, #44] */
/* @0x196e28 vstr s15, [r9, #48] */
/* @0x196e2c ldr r3, [r3, #0x8] */
/* @0x196e30 blx r3 */
/* @0x196e34 vldr s14, [r7, #384] */
/* @0x196e38 vcvt.f64.f32 d7, s14 */
/* @0x196e3c ldr r3, [r9] */
/* @0x196e40 str r5, [r9, #0x38] */
/* @0x196e44 mov r2, r6 */
/* @0x196e48 mov r1, #8 */
/* @0x196e4c mov r0, r9 */
/* @0x196e50 vstr s14, [r9, #44] */
/* @0x196e54 vstr s15, [r9, #48] */
/* @0x196e58 ldr r3, [r3, #0x8] */
/* @0x196e5c blx r3 */
/* @0x196e60 ldrb r12, [r7, #0xb0] */
/* @0x196e64 ldr r3, [r9] */
/* @0x196e68 mov r2, r6 */
/* @0x196e6c str r5, [r9, #0x38] */
/* @0x196e70 mov r1, #6 */
/* @0x196e74 vmov s14, r12 */
/* @0x196e78 mov r0, r9 */
/* @0x196e7c vcvt.f64.u32 d7, s14 */
/* @0x196e80 vstr s14, [r9, #44] */
/* @0x196e84 vstr s15, [r9, #48] */
/* @0x196e88 ldr r3, [r3, #0x8] */
/* @0x196e8c blx r3 */
/* @0x196e90 vldr s14, [r7, #180] */
/* @0x196e94 vcvt.f64.f32 d7, s14 */
/* @0x196e98 ldr r3, [r9] */
/* @0x196e9c str r5, [r9, #0x38] */
/* @0x196ea0 mov r2, r6 */
/* @0x196ea4 mov r1, #8 */
/* @0x196ea8 mov r0, r9 */
/* @0x196eac vstr s14, [r9, #44] */
/* @0x196eb0 vstr s15, [r9, #48] */
/* @0x196eb4 ldr r3, [r3, #0x8] */
/* @0x196eb8 blx r3 */
/* @0x196ebc vldr s14, [r7, #184] */
/* @0x196ec0 vcvt.f64.f32 d7, s14 */
/* @0x196ec4 ldr r3, [r9] */
/* @0x196ec8 str r5, [r9, #0x38] */
/* @0x196ecc mov r2, r6 */
/* @0x196ed0 mov r1, #8 */
/* @0x196ed4 mov r0, r9 */
/* @0x196ed8 vstr s14, [r9, #44] */
/* @0x196edc vstr s15, [r9, #48] */
/* @0x196ee0 ldr r3, [r3, #0x8] */
/* @0x196ee4 blx r3 */
/* @0x196ee8 vldr s14, [r7, #188] */
/* @0x196eec vcvt.f64.f32 d7, s14 */
/* @0x196ef0 ldr r3, [r9] */
/* @0x196ef4 str r5, [r9, #0x38] */
/* @0x196ef8 mov r2, r6 */
/* @0x196efc mov r1, #8 */
/* @0x196f00 mov r0, r9 */
/* @0x196f04 vstr s14, [r9, #44] */
/* @0x196f08 vstr s15, [r9, #48] */
/* @0x196f0c ldr r3, [r3, #0x8] */
/* @0x196f10 blx r3 */
/* @0x196f14 vldr s14, [r7, #192] */
/* @0x196f18 vcvt.f64.f32 d7, s14 */
/* @0x196f1c ldr r3, [r9] */
/* @0x196f20 str r5, [r9, #0x38] */
/* @0x196f24 mov r2, r6 */
/* @0x196f28 mov r1, #8 */
/* @0x196f2c mov r0, r9 */
/* @0x196f30 vstr s14, [r9, #44] */
/* @0x196f34 vstr s15, [r9, #48] */
/* @0x196f38 ldr r3, [r3, #0x8] */
/* @0x196f3c blx r3 */
/* @0x196f40 vldr s14, [r7, #196] */
/* @0x196f44 vcvt.f64.f32 d7, s14 */
/* @0x196f48 ldr r3, [r9] */
/* @0x196f4c str r5, [r9, #0x38] */
/* @0x196f50 mov r2, r6 */
/* @0x196f54 mov r1, #8 */
/* @0x196f58 mov r0, r9 */
/* @0x196f5c vstr s14, [r9, #44] */
/* @0x196f60 vstr s15, [r9, #48] */
/* @0x196f64 ldr r3, [r3, #0x8] */
/* @0x196f68 blx r3 */
/* @0x196f6c vldr s14, [r7, #200] */
/* @0x196f70 vcvt.f64.f32 d7, s14 */
/* @0x196f74 ldr r3, [r9] */
/* @0x196f78 str r5, [r9, #0x38] */
/* @0x196f7c mov r2, r6 */
/* @0x196f80 mov r1, #8 */
/* @0x196f84 mov r0, r9 */
/* @0x196f88 vstr s14, [r9, #44] */
/* @0x196f8c vstr s15, [r9, #48] */
/* @0x196f90 ldr r3, [r3, #0x8] */
/* @0x196f94 blx r3 */
/* @0x196f98 vldr s14, [r7, #204] */
/* @0x196f9c vcvt.f64.f32 d7, s14 */
/* @0x196fa0 ldr r3, [r9] */
/* @0x196fa4 str r5, [r9, #0x38] */
/* @0x196fa8 mov r2, r6 */
/* @0x196fac mov r1, #8 */
/* @0x196fb0 mov r0, r9 */
/* @0x196fb4 vstr s14, [r9, #44] */
/* @0x196fb8 vstr s15, [r9, #48] */
/* @0x196fbc ldr r3, [r3, #0x8] */
/* @0x196fc0 blx r3 */
/* @0x196fc4 vldr s14, [r7, #208] */
/* @0x196fc8 vcvt.f64.f32 d7, s14 */
/* @0x196fcc ldr r3, [r9] */
/* @0x196fd0 str r5, [r9, #0x38] */
/* @0x196fd4 mov r2, r6 */
/* @0x196fd8 mov r1, #8 */
/* @0x196fdc mov r0, r9 */
/* @0x196fe0 vstr s14, [r9, #44] */
/* @0x196fe4 vstr s15, [r9, #48] */
/* @0x196fe8 ldr r3, [r3, #0x8] */
/* @0x196fec blx r3 */
/* @0x196ff0 vldr s14, [r7, #212] */
/* @0x196ff4 vcvt.f64.f32 d7, s14 */
/* @0x196ff8 ldr r3, [r9] */
/* @0x196ffc str r5, [r9, #0x38] */
/* @0x197000 mov r2, r6 */
/* @0x197004 mov r1, #8 */
/* @0x197008 mov r0, r9 */
/* @0x19700c vstr s14, [r9, #44] */
/* @0x197010 vstr s15, [r9, #48] */
/* @0x197014 ldr r3, [r3, #0x8] */
/* @0x197018 blx r3 */
/* @0x19701c vldr s14, [r7, #216] */
/* @0x197020 vcvt.f64.f32 d7, s14 */
/* @0x197024 ldr r3, [r9] */
/* @0x197028 str r5, [r9, #0x38] */
/* @0x19702c mov r2, r6 */
/* @0x197030 mov r1, #8 */
/* @0x197034 mov r0, r9 */
/* @0x197038 vstr s14, [r9, #44] */
/* @0x19703c vstr s15, [r9, #48] */
/* @0x197040 ldr r3, [r3, #0x8] */
/* @0x197044 blx r3 */
/* @0x197048 vldr s14, [r7, #220] */
/* @0x19704c vcvt.f64.f32 d7, s14 */
/* @0x197050 ldr r3, [r9] */
/* @0x197054 str r5, [r9, #0x38] */
/* @0x197058 mov r2, r6 */
/* @0x19705c mov r1, #8 */
/* @0x197060 mov r0, r9 */
/* @0x197064 vstr s14, [r9, #44] */
/* @0x197068 vstr s15, [r9, #48] */
/* @0x19706c ldr r3, [r3, #0x8] */
/* @0x197070 blx r3 */
/* @0x197074 vldr s14, [r7, #224] */
/* @0x197078 vcvt.f64.f32 d7, s14 */
/* @0x19707c ldr r3, [r9] */
/* @0x197080 str r5, [r9, #0x38] */
/* @0x197084 mov r2, r6 */
/* @0x197088 mov r1, #8 */
/* @0x19708c mov r0, r9 */
/* @0x197090 vstr s14, [r9, #44] */
/* @0x197094 vstr s15, [r9, #48] */
/* @0x197098 ldr r3, [r3, #0x8] */
/* @0x19709c blx r3 */
/* @0x1970a0 vldr s14, [r7, #228] */
/* @0x1970a4 vcvt.f64.f32 d7, s14 */
/* @0x1970a8 ldr r3, [r9] */
/* @0x1970ac str r5, [r9, #0x38] */
/* @0x1970b0 mov r2, r6 */
/* @0x1970b4 mov r1, #8 */
/* @0x1970b8 mov r0, r9 */
/* @0x1970bc vstr s14, [r9, #44] */
/* @0x1970c0 vstr s15, [r9, #48] */
/* @0x1970c4 ldr r3, [r3, #0x8] */
/* @0x1970c8 blx r3 */
/* @0x1970cc vldr s14, [r7, #232] */
/* @0x1970d0 vcvt.f64.s32 d7, s14 */
/* @0x1970d4 ldr r3, [r9] */
/* @0x1970d8 mov r2, r6 */
/* @0x1970dc str r5, [r9, #0x38] */
/* @0x1970e0 mov r1, #6 */
/* @0x1970e4 mov r0, r9 */
/* @0x1970e8 vstr s14, [r9, #44] */
/* @0x1970ec vstr s15, [r9, #48] */
/* @0x1970f0 ldr r3, [r3, #0x8] */
/* @0x1970f4 blx r3 */
/* @0x1970f8 vldr s14, [r7, #240] */
/* @0x1970fc vcvt.f64.s32 d7, s14 */
/* @0x197100 ldr r3, [r9] */
/* @0x197104 mov r2, r6 */
/* @0x197108 str r5, [r9, #0x38] */
/* @0x19710c mov r1, #6 */
/* @0x197110 mov r0, r9 */
/* @0x197114 vstr s14, [r9, #44] */
/* @0x197118 vstr s15, [r9, #48] */
/* @0x19711c ldr r3, [r3, #0x8] */
/* @0x197120 blx r3 */
/* @0x197124 vldr s14, [r7, #236] */
/* @0x197128 vcvt.f64.s32 d7, s14 */
/* @0x19712c ldr r3, [r9] */
/* @0x197130 mov r2, r6 */
/* @0x197134 str r5, [r9, #0x38] */
/* @0x197138 mov r1, #6 */
/* @0x19713c mov r0, r9 */
/* @0x197140 vstr s14, [r9, #44] */
/* @0x197144 vstr s15, [r9, #48] */
/* @0x197148 ldr r3, [r3, #0x8] */
/* @0x19714c blx r3 */
/* @0x197150 vldr s14, [r7, #244] */
/* @0x197154 vcvt.f64.s32 d7, s14 */
/* @0x197158 ldr r3, [r9] */
/* @0x19715c mov r2, r6 */
/* @0x197160 str r5, [r9, #0x38] */
/* @0x197164 mov r1, #6 */
/* @0x197168 mov r0, r9 */
/* @0x19716c vstr s14, [r9, #44] */
/* @0x197170 vstr s15, [r9, #48] */
/* @0x197174 ldr r3, [r3, #0x8] */
/* @0x197178 blx r3 */
/* @0x19717c ldrb r3, [r7, #0x65] */
/* @0x197180 mov r2, r6 */
/* @0x197184 str r5, [r9, #0x38] */
/* @0x197188 mov r1, #6 */
/* @0x19718c mov r0, r9 */
/* @0x197190 vmov s14, r3 */
/* @0x197194 ldr r3, [r9] */
/* @0x197198 vcvt.f64.u32 d7, s14 */
/* @0x19719c vstr s14, [r9, #44] */
/* @0x1971a0 vstr s15, [r9, #48] */
/* @0x1971a4 ldr r3, [r3, #0x8] */
/* @0x1971a8 blx r3 */
/* @0x1971ac ldrb r12, [r7, #0x66] */
/* @0x1971b0 ldr r3, [r9] */
/* @0x1971b4 mov r2, r6 */
/* @0x1971b8 str r5, [r9, #0x38] */
/* @0x1971bc mov r1, #6 */
/* @0x1971c0 vmov s14, r12 */
/* @0x1971c4 mov r0, r9 */
/* @0x1971c8 vcvt.f64.u32 d7, s14 */
/* @0x1971cc vstr s14, [r9, #44] */
/* @0x1971d0 vstr s15, [r9, #48] */
/* @0x1971d4 ldr r3, [r3, #0x8] */
/* @0x1971d8 blx r3 */
/* @0x1971dc ldrb r4, [r7, #0x67] */
/* @0x1971e0 str r5, [r9, #0x38] */
/* @0x1971e4 mov r2, r6 */
/* @0x1971e8 ldr r3, [r9] */
/* @0x1971ec mov r0, r9 */
/* @0x1971f0 vmov s13, r4 */
/* @0x1971f4 mov r1, #6 */
/* @0x1971f8 vcvt.f64.u32 d6, s13 */
/* @0x1971fc vmov r4, r5, d6 */
/* @0x197200 vstr s12, [r9, #44] */
/* @0x197204 str r5, [r9, #0x30] */
/* @0x197208 ldr r3, [r3, #0x8] */
/* @0x19720c blx r3 */
/* @0x197210 ldr r4, [r11, #0xf8] */
/* @0x197214 mov r0, r9 */
/* @0x197218 ldr r3, [r9] */
/* @0x19721c mov r1, #6 */
/* @0x197220 str r10, [r9, #0x38] */
/* @0x197224 mov r2, r6 */
/* @0x197228 vmov s15, r4 */
/* @0x19722c add r11, r11, #4 */
/* @0x197230 vcvt.f64.s32 d7, s15 */
/* @0x197234 vmov r4, r5, d7 */
/* @0x197238 vstr s14, [r9, #44] */
/* @0x19723c str r5, [r9, #0x30] */
/* @0x197240 ldr r3, [r3, #0x8] */
/* @0x197244 blx r3 */
/* @0x197248 subs r8, r8, #1 */
/* @0x19724c bne 0x197210 <_ZN9CInstance9SerialiseEP7IBuffer+0x61c> */
/* @0x197250 ldrb r4, [r7, #0x68] */
/* @0x197254 mov r1, #6 */
/* @0x197258 ldr r3, [r9] */
/* @0x19725c mov r2, r6 */
/* @0x197260 mov r0, r9 */
/* @0x197264 str r8, [r9, #0x38] */
/* @0x197268 vmov s13, r4 */
/* @0x19726c vcvt.f64.u32 d6, s13 */
/* @0x197270 vmov r4, r5, d6 */
/* @0x197274 vstr s12, [r9, #44] */
/* @0x197278 str r5, [r9, #0x30] */
/* @0x19727c ldr r3, [r3, #0x8] */
/* @0x197280 blx r3 */
/* @0x197284 ldr r4, [r7, #0x128] */
/* @0x197288 ldr r3, [r9] */
/* @0x19728c mov r1, #6 */
/* @0x197290 mov r2, r6 */
/* @0x197294 mov r0, r9 */
/* @0x197298 vmov s15, r4 */
/* @0x19729c str r8, [r9, #0x38] */
/* @0x1972a0 vcvt.f64.s32 d7, s15 */
/* @0x1972a4 vmov r4, r5, d7 */
/* @0x1972a8 vstr s14, [r9, #44] */
/* @0x1972ac str r5, [r9, #0x30] */
/* @0x1972b0 ldr r3, [r3, #0x8] */
/* @0x1972b4 blx r3 */
/* @0x1972b8 vldr s15, [r7, #300] */
/* @0x1972bc vcvt.f64.f32 d6, s15 */
/* @0x1972c0 ldr r3, [r9] */
/* @0x1972c4 mov r1, #8 */
/* @0x1972c8 mov r2, r6 */
/* @0x1972cc str r8, [r9, #0x38] */
/* @0x1972d0 mov r0, r9 */
/* @0x1972d4 vmov r4, r5, d6 */
/* @0x1972d8 vstr s12, [r9, #44] */
/* @0x1972dc str r5, [r9, #0x30] */
/* @0x1972e0 ldr r3, [r3, #0x8] */
/* @0x1972e4 blx r3 */
/* @0x1972e8 vldr s15, [r7, #304] */
/* @0x1972ec vcvt.f64.f32 d6, s15 */
/* @0x1972f0 ldr r3, [r9] */
/* @0x1972f4 mov r1, #8 */
/* @0x1972f8 mov r2, r6 */
/* @0x1972fc str r8, [r9, #0x38] */
/* @0x197300 mov r0, r9 */
/* @0x197304 vmov r4, r5, d6 */
/* @0x197308 vstr s12, [r9, #44] */
/* @0x19730c str r5, [r9, #0x30] */
/* @0x197310 ldr r3, [r3, #0x8] */
/* @0x197314 blx r3 */
/* @0x197318 vldr s15, [r7, #308] */
/* @0x19731c vcvt.f64.f32 d6, s15 */
/* @0x197320 ldr r3, [r9] */
/* @0x197324 mov r1, #8 */
/* @0x197328 mov r2, r6 */
/* @0x19732c str r8, [r9, #0x38] */
/* @0x197330 mov r0, r9 */
/* @0x197334 vmov r4, r5, d6 */
/* @0x197338 vstr s12, [r9, #44] */
/* @0x19733c str r5, [r9, #0x30] */
/* @0x197340 ldr r3, [r3, #0x8] */
/* @0x197344 blx r3 */
/* @0x197348 vldr s15, [r7, #312] */
/* @0x19734c vcvt.f64.f32 d6, s15 */
/* @0x197350 ldr r3, [r9] */
/* @0x197354 mov r1, #8 */
/* @0x197358 mov r2, r6 */
/* @0x19735c str r8, [r9, #0x38] */
/* @0x197360 mov r0, r9 */
/* @0x197364 vmov r4, r5, d6 */
/* @0x197368 vstr s12, [r9, #44] */
/* @0x19736c str r5, [r9, #0x30] */
/* @0x197370 ldr r3, [r3, #0x8] */
/* @0x197374 blx r3 */
/* @0x197378 vldr s15, [r7, #316] */
/* @0x19737c vcvt.f64.f32 d6, s15 */
/* @0x197380 ldr r3, [r9] */
/* @0x197384 mov r1, #8 */
/* @0x197388 mov r2, r6 */
/* @0x19738c str r8, [r9, #0x38] */
/* @0x197390 mov r0, r9 */
/* @0x197394 vmov r4, r5, d6 */
/* @0x197398 vstr s12, [r9, #44] */
/* @0x19739c str r5, [r9, #0x30] */
/* @0x1973a0 ldr r3, [r3, #0x8] */
/* @0x1973a4 blx r3 */
/* @0x1973a8 ldr r4, [r7, #0x140] */
/* @0x1973ac ldr r3, [r9] */
/* @0x1973b0 mov r1, #6 */
/* @0x1973b4 mov r2, r6 */
/* @0x1973b8 mov r0, r9 */
/* @0x1973bc vmov s15, r4 */
/* @0x1973c0 str r8, [r9, #0x38] */
/* @0x1973c4 vcvt.f64.s32 d7, s15 */
/* @0x1973c8 vmov r4, r5, d7 */
/* @0x1973cc vstr s14, [r9, #44] */
/* @0x1973d0 str r5, [r9, #0x30] */
/* @0x1973d4 ldr r3, [r3, #0x8] */
/* @0x1973d8 blx r3 */
/* @0x1973dc vldr s15, [r7, #324] */
/* @0x1973e0 vcvt.f64.f32 d6, s15 */
/* @0x1973e4 ldr r3, [r9] */
/* @0x1973e8 mov r1, #8 */
/* @0x1973ec mov r2, r6 */
/* @0x1973f0 str r8, [r9, #0x38] */
/* @0x1973f4 mov r0, r9 */
/* @0x1973f8 vmov r4, r5, d6 */
/* @0x1973fc vstr s12, [r9, #44] */
/* @0x197400 str r5, [r9, #0x30] */
/* @0x197404 ldr r3, [r3, #0x8] */
/* @0x197408 blx r3 */
/* @0x19740c vldr s15, [r7, #328] */
/* @0x197410 vcvt.f64.f32 d6, s15 */
/* @0x197414 ldr r3, [r9] */
/* @0x197418 mov r1, #8 */
/* @0x19741c mov r2, r6 */
/* @0x197420 str r8, [r9, #0x38] */
/* @0x197424 mov r0, r9 */
/* @0x197428 vmov r4, r5, d6 */
/* @0x19742c vstr s12, [r9, #44] */
/* @0x197430 str r5, [r9, #0x30] */
/* @0x197434 ldr r3, [r3, #0x8] */
/* @0x197438 blx r3 */
/* @0x19743c ldr r4, [r7, #0x14c] */
/* @0x197440 ldr r3, [r9] */
/* @0x197444 mov r1, #6 */
/* @0x197448 mov r2, r6 */
/* @0x19744c mov r0, r9 */
/* @0x197450 vmov s15, r4 */
/* @0x197454 str r8, [r9, #0x38] */
/* @0x197458 vcvt.f64.s32 d7, s15 */
/* @0x19745c vmov r4, r5, d7 */
/* @0x197460 vstr s14, [r9, #44] */
/* @0x197464 str r5, [r9, #0x30] */
/* @0x197468 ldr r3, [r3, #0x8] */
/* @0x19746c blx r3 */
/* @0x197470 vldr s15, [r7, #336] */
/* @0x197474 vcvt.f64.f32 d6, s15 */
/* @0x197478 ldr r3, [r9] */
/* @0x19747c mov r1, #8 */
/* @0x197480 mov r2, r6 */
/* @0x197484 str r8, [r9, #0x38] */
/* @0x197488 mov r0, r9 */
/* @0x19748c vmov r4, r5, d6 */
/* @0x197490 vstr s12, [r9, #44] */
/* @0x197494 str r5, [r9, #0x30] */
/* @0x197498 ldr r3, [r3, #0x8] */
/* @0x19749c blx r3 */
/* @0x1974a0 vldr s15, [r7, #340] */
/* @0x1974a4 vcvt.f64.f32 d6, s15 */
/* @0x1974a8 ldr r3, [r9] */
/* @0x1974ac mov r1, #8 */
/* @0x1974b0 mov r2, r6 */
/* @0x1974b4 str r8, [r9, #0x38] */
/* @0x1974b8 mov r0, r9 */
/* @0x1974bc vmov r4, r5, d6 */
/* @0x1974c0 vstr s12, [r9, #44] */
/* @0x1974c4 str r5, [r9, #0x30] */
/* @0x1974c8 ldr r3, [r3, #0x8] */
/* @0x1974cc blx r3 */
/* @0x1974d0 vldr s15, [r7, #344] */
/* @0x1974d4 vcvt.f64.f32 d6, s15 */
/* @0x1974d8 ldr r3, [r9] */
/* @0x1974dc mov r1, #8 */
/* @0x1974e0 mov r2, r6 */
/* @0x1974e4 str r8, [r9, #0x38] */
/* @0x1974e8 mov r0, r9 */
/* @0x1974ec vmov r4, r5, d6 */
/* @0x1974f0 vstr s12, [r9, #44] */
/* @0x1974f4 str r5, [r9, #0x30] */
/* @0x1974f8 ldr r3, [r3, #0x8] */
/* @0x1974fc blx r3 */
/* @0x197500 ldrb r4, [r7, #0x15c] */
/* @0x197504 ldr r3, [r9] */
/* @0x197508 mov r1, #6 */
/* @0x19750c mov r2, r6 */
/* @0x197510 mov r0, r9 */
/* @0x197514 vmov s15, r4 */
/* @0x197518 str r8, [r9, #0x38] */
/* @0x19751c vcvt.f64.u32 d7, s15 */
/* @0x197520 vmov r4, r5, d7 */
/* @0x197524 vstr s14, [r9, #44] */
/* @0x197528 str r5, [r9, #0x30] */
/* @0x19752c ldr r3, [r3, #0x8] */
/* @0x197530 blx r3 */
/* @0x197534 ldrb r4, [r7, #0x15d] */
/* @0x197538 ldr r3, [r9] */
/* @0x19753c mov r1, #6 */
/* @0x197540 mov r2, r6 */
/* @0x197544 mov r0, r9 */
/* @0x197548 vmov s13, r4 */
/* @0x19754c str r8, [r9, #0x38] */
/* @0x197550 vcvt.f64.u32 d6, s13 */
/* @0x197554 vmov r4, r5, d6 */
/* @0x197558 vstr s12, [r9, #44] */
/* @0x19755c str r5, [r9, #0x30] */
/* @0x197560 ldr r3, [r3, #0x8] */
/* @0x197564 blx r3 */
/* @0x197568 ldrb r4, [r7, #0x15e] */
/* @0x19756c ldr r3, [r9] */
/* @0x197570 mov r1, #6 */
/* @0x197574 mov r2, r6 */
/* @0x197578 mov r0, r9 */
/* @0x19757c vmov s15, r4 */
/* @0x197580 str r8, [r9, #0x38] */
/* @0x197584 vcvt.f64.u32 d7, s15 */
/* @0x197588 vmov r4, r5, d7 */
/* @0x19758c vstr s14, [r9, #44] */
/* @0x197590 str r5, [r9, #0x30] */
/* @0x197594 ldr r3, [r3, #0x8] */
/* @0x197598 blx r3 */
/* @0x19759c ldr r4, [r7, #0x170] */
/* @0x1975a0 ldr r3, [r9] */
/* @0x1975a4 mov r0, r9 */
/* @0x1975a8 str r8, [r9, #0x38] */
/* @0x1975ac mov r1, #6 */
/* @0x1975b0 vmov s13, r4 */
/* @0x1975b4 mov r2, r6 */
/* @0x1975b8 vcvt.f64.s32 d6, s13 */
/* @0x1975bc vmov r4, r5, d6 */
/* @0x1975c0 vstr s12, [r9, #44] */
/* @0x1975c4 str r5, [r9, #0x30] */
/* @0x1975c8 ldr r3, [r3, #0x8] */
/* @0x1975cc blx r3 */
/* @0x1975d0 ldr r3, [r7, #0x24] */
/* @0x1975d4 cmp r3, #0 */
/* @0x1975d8 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1975dc ldr r10, [pc, #0x84] */
/* @0x1975e0 mov r2, r6 */
/* @0x1975e4 ldr r3, [r9] */
/* @0x1975e8 mov r0, r9 */
/* @0x1975ec ldr r10, [pc, r10] */
/* @0x1975f0 vldr s15, [r10] */
/* @0x1975f4 vcvt.f64.s32 d7, s15 */
/* @0x1975f8 str r8, [r9, #0x38] */
/* @0x1975fc mov r1, #6 */
/* @0x197600 vmov r4, r5, d7 */
/* @0x197604 vstr s14, [r9, #44] */
/* @0x197608 str r5, [r9, #0x30] */
/* @0x19760c ldr r3, [r3, #0x8] */
/* @0x197610 blx r3 */
/* @0x197614 ldr r3, [r10] */
/* @0x197618 cmp r3, #0 */
/* @0x19761c pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x197620 ldr r0, [r7, #0x4] */
/* @0x197624 cmp r0, #0 */
/* @0x197628 add r0, r0, r8, lsl #4 */
/* @0x19762c beq 0x197658 <_ZN9CInstance9SerialiseEP7IBuffer+0xa64> */
/* @0x197630 mov r1, r9 */
/* @0x197634 add r8, r8, #1 */
/* @0x197638 bl 0xcf47c <_ZN6RValue9SerialiseEP7IBuffer> */
/* @0x19763c ldr r3, [r10] */
/* @0x197640 cmp r3, r8 */
/* @0x197644 bgt 0x197620 <_ZN9CInstance9SerialiseEP7IBuffer+0xa2c> */
/* @0x197648 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19764c mov r1, #1 */
/* @0x197650 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x197654 b 0x196c0c <_ZN9CInstance9SerialiseEP7IBuffer+0x18> */
/* @0x197658 mov r0, r7 */
/* @0x19765c mov r1, r8 */
/* @0x197660 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x197664 b 0x197630 <_ZN9CInstance9SerialiseEP7IBuffer+0xa3c> */
/* @0x197668 eoreq r6, r5, r8, lsr #14 */

/* ── FUNC 0x19766c · CInstance::DeSerialise(IBuffer*, bool) · size=2368 · insn=592 */
/* @0x19766c ldr r3, [r1] */
/* @0x197670 push {r4, r5, r6, r7, r8, lr} */
/* @0x197674 add r5, r1, #44 */
/* @0x197678 mov r4, r1 */
/* @0x19767c mov r6, r0 */
/* @0x197680 mov r7, r2 */
/* @0x197684 ldr r3, [r3, #0xc] */
/* @0x197688 mov r2, r5 */
/* @0x19768c mov r0, r1 */
/* @0x197690 mov r1, #6 */
/* @0x197694 mov r8, r6 */
/* @0x197698 blx r3 */
/* @0x19769c mov r1, #0 */
/* @0x1976a0 mov r0, r5 */
/* @0x1976a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1976a8 ldr r3, [r4] */
/* @0x1976ac mov r2, r5 */
/* @0x1976b0 mov r1, #6 */
/* @0x1976b4 ldr r3, [r3, #0xc] */
/* @0x1976b8 str r0, [r6, #0x78] */
/* @0x1976bc mov r0, r4 */
/* @0x1976c0 blx r3 */
/* @0x1976c4 mov r1, #0 */
/* @0x1976c8 mov r0, r5 */
/* @0x1976cc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1976d0 ldr r3, [r4] */
/* @0x1976d4 mov r2, r5 */
/* @0x1976d8 mov r1, #6 */
/* @0x1976dc ldr r3, [r3, #0xc] */
/* @0x1976e0 strb r0, [r6, #0x69] */
/* @0x1976e4 mov r0, r4 */
/* @0x1976e8 blx r3 */
/* @0x1976ec mov r1, #0 */
/* @0x1976f0 mov r0, r5 */
/* @0x1976f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1976f8 ldrb r2, [r6, #0x69] */
/* @0x1976fc cmp r2, #0 */
/* @0x197700 moveq r2, r7 */
/* @0x197704 movne r2, #0 */
/* @0x197708 mov r7, #12 */
/* @0x19770c mov r1, r0 */
/* @0x197710 mov r0, r6 */
/* @0x197714 bl 0x19324c <_ZN9CInstance14SetObjectIndexEib> */
/* @0x197718 ldr r3, [r4] */
/* @0x19771c mov r2, r5 */
/* @0x197720 mov r1, #6 */
/* @0x197724 mov r0, r4 */
/* @0x197728 ldr r3, [r3, #0xc] */
/* @0x19772c blx r3 */
/* @0x197730 mov r1, #0 */
/* @0x197734 mov r0, r5 */
/* @0x197738 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x19773c ldr r3, [r4] */
/* @0x197740 mov r2, r5 */
/* @0x197744 mov r1, #8 */
/* @0x197748 ldr r3, [r3, #0xc] */
/* @0x19774c str r0, [r6, #0x8c] */
/* @0x197750 mov r0, r4 */
/* @0x197754 blx r3 */
/* @0x197758 mov r1, #0 */
/* @0x19775c mov r0, r5 */
/* @0x197760 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197764 ldr r3, [r4] */
/* @0x197768 mov r2, r5 */
/* @0x19776c mov r1, #8 */
/* @0x197770 ldr r3, [r3, #0xc] */
/* @0x197774 str r0, [r6, #0x90] */
/* @0x197778 mov r0, r4 */
/* @0x19777c blx r3 */
/* @0x197780 mov r1, #0 */
/* @0x197784 mov r0, r5 */
/* @0x197788 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x19778c ldr r3, [r4] */
/* @0x197790 mov r2, r5 */
/* @0x197794 mov r1, #8 */
/* @0x197798 ldr r3, [r3, #0xc] */
/* @0x19779c str r0, [r6, #0x94] */
/* @0x1977a0 mov r0, r4 */
/* @0x1977a4 blx r3 */
/* @0x1977a8 mov r1, #0 */
/* @0x1977ac mov r0, r5 */
/* @0x1977b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1977b4 ldr r3, [r4] */
/* @0x1977b8 mov r2, r5 */
/* @0x1977bc mov r1, #8 */
/* @0x1977c0 ldr r3, [r3, #0xc] */
/* @0x1977c4 str r0, [r6, #0x98] */
/* @0x1977c8 mov r0, r4 */
/* @0x1977cc blx r3 */
/* @0x1977d0 mov r1, #0 */
/* @0x1977d4 mov r0, r5 */
/* @0x1977d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1977dc ldr r3, [r4] */
/* @0x1977e0 mov r2, r5 */
/* @0x1977e4 mov r1, #8 */
/* @0x1977e8 ldr r3, [r3, #0xc] */
/* @0x1977ec str r0, [r6, #0x9c] */
/* @0x1977f0 mov r0, r4 */
/* @0x1977f4 blx r3 */
/* @0x1977f8 mov r1, #0 */
/* @0x1977fc mov r0, r5 */
/* @0x197800 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197804 ldr r3, [r4] */
/* @0x197808 mov r2, r5 */
/* @0x19780c mov r1, #8 */
/* @0x197810 ldr r3, [r3, #0xc] */
/* @0x197814 str r0, [r6, #0xa0] */
/* @0x197818 mov r0, r4 */
/* @0x19781c blx r3 */
/* @0x197820 mov r1, #0 */
/* @0x197824 mov r0, r5 */
/* @0x197828 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x19782c ldr r3, [r4] */
/* @0x197830 mov r2, r5 */
/* @0x197834 mov r1, #5 */
/* @0x197838 ldr r3, [r3, #0xc] */
/* @0x19783c str r0, [r6, #0xa4] */
/* @0x197840 mov r0, r4 */
/* @0x197844 blx r3 */
/* @0x197848 mov r1, #0 */
/* @0x19784c mov r0, r5 */
/* @0x197850 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x197854 ldr r3, [r4] */
/* @0x197858 mov r2, r5 */
/* @0x19785c mov r1, #6 */
/* @0x197860 ldr r3, [r3, #0xc] */
/* @0x197864 str r0, [r6, #0xa8] */
/* @0x197868 mov r0, r4 */
/* @0x19786c blx r3 */
/* @0x197870 mov r1, #0 */
/* @0x197874 mov r0, r5 */
/* @0x197878 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x19787c ldr r3, [r4] */
/* @0x197880 mov r2, r5 */
/* @0x197884 mov r1, #8 */
/* @0x197888 ldr r3, [r3, #0xc] */
/* @0x19788c str r0, [r6, #0xac] */
/* @0x197890 mov r0, r4 */
/* @0x197894 blx r3 */
/* @0x197898 mov r1, #0 */
/* @0x19789c mov r0, r5 */
/* @0x1978a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1978a4 ldr r3, [r4] */
/* @0x1978a8 mov r2, r5 */
/* @0x1978ac mov r1, #6 */
/* @0x1978b0 ldr r3, [r3, #0xc] */
/* @0x1978b4 str r0, [r6, #0x180] */
/* @0x1978b8 mov r0, r4 */
/* @0x1978bc blx r3 */
/* @0x1978c0 mov r1, #0 */
/* @0x1978c4 mov r0, r5 */
/* @0x1978c8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1978cc ldr r3, [r4] */
/* @0x1978d0 mov r2, r5 */
/* @0x1978d4 mov r1, #8 */
/* @0x1978d8 ldr r3, [r3, #0xc] */
/* @0x1978dc strb r0, [r6, #0xb0] */
/* @0x1978e0 mov r0, r4 */
/* @0x1978e4 blx r3 */
/* @0x1978e8 mov r1, #0 */
/* @0x1978ec mov r0, r5 */
/* @0x1978f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1978f4 ldr r3, [r4] */
/* @0x1978f8 mov r2, r5 */
/* @0x1978fc mov r1, #8 */
/* @0x197900 ldr r3, [r3, #0xc] */
/* @0x197904 str r0, [r6, #0xb4] */
/* @0x197908 mov r0, r4 */
/* @0x19790c blx r3 */
/* @0x197910 mov r1, #0 */
/* @0x197914 mov r0, r5 */
/* @0x197918 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x19791c ldr r3, [r4] */
/* @0x197920 mov r2, r5 */
/* @0x197924 mov r1, #8 */
/* @0x197928 ldr r3, [r3, #0xc] */
/* @0x19792c str r0, [r6, #0xb8] */
/* @0x197930 mov r0, r4 */
/* @0x197934 blx r3 */
/* @0x197938 mov r1, #0 */
/* @0x19793c mov r0, r5 */
/* @0x197940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197944 ldr r3, [r4] */
/* @0x197948 mov r2, r5 */
/* @0x19794c mov r1, #8 */
/* @0x197950 ldr r3, [r3, #0xc] */
/* @0x197954 str r0, [r6, #0xbc] */
/* @0x197958 mov r0, r4 */
/* @0x19795c blx r3 */
/* @0x197960 mov r1, #0 */
/* @0x197964 mov r0, r5 */
/* @0x197968 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x19796c ldr r3, [r4] */
/* @0x197970 mov r2, r5 */
/* @0x197974 mov r1, #8 */
/* @0x197978 ldr r3, [r3, #0xc] */
/* @0x19797c str r0, [r6, #0xc0] */
/* @0x197980 mov r0, r4 */
/* @0x197984 blx r3 */
/* @0x197988 mov r1, #0 */
/* @0x19798c mov r0, r5 */
/* @0x197990 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197994 ldr r3, [r4] */
/* @0x197998 mov r2, r5 */
/* @0x19799c mov r1, #8 */
/* @0x1979a0 ldr r3, [r3, #0xc] */
/* @0x1979a4 str r0, [r6, #0xc4] */
/* @0x1979a8 mov r0, r4 */
/* @0x1979ac blx r3 */
/* @0x1979b0 mov r1, #0 */
/* @0x1979b4 mov r0, r5 */
/* @0x1979b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1979bc ldr r3, [r4] */
/* @0x1979c0 mov r2, r5 */
/* @0x1979c4 mov r1, #8 */
/* @0x1979c8 ldr r3, [r3, #0xc] */
/* @0x1979cc str r0, [r6, #0xc8] */
/* @0x1979d0 mov r0, r4 */
/* @0x1979d4 blx r3 */
/* @0x1979d8 mov r1, #0 */
/* @0x1979dc mov r0, r5 */
/* @0x1979e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1979e4 ldr r3, [r4] */
/* @0x1979e8 mov r2, r5 */
/* @0x1979ec mov r1, #8 */
/* @0x1979f0 ldr r3, [r3, #0xc] */
/* @0x1979f4 str r0, [r6, #0xcc] */
/* @0x1979f8 mov r0, r4 */
/* @0x1979fc blx r3 */
/* @0x197a00 mov r1, #0 */
/* @0x197a04 mov r0, r5 */
/* @0x197a08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197a0c ldr r3, [r4] */
/* @0x197a10 mov r2, r5 */
/* @0x197a14 mov r1, #8 */
/* @0x197a18 ldr r3, [r3, #0xc] */
/* @0x197a1c str r0, [r6, #0xd0] */
/* @0x197a20 mov r0, r4 */
/* @0x197a24 blx r3 */
/* @0x197a28 mov r1, #0 */
/* @0x197a2c mov r0, r5 */
/* @0x197a30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197a34 ldr r3, [r4] */
/* @0x197a38 mov r2, r5 */
/* @0x197a3c mov r1, #8 */
/* @0x197a40 ldr r3, [r3, #0xc] */
/* @0x197a44 str r0, [r6, #0xd4] */
/* @0x197a48 mov r0, r4 */
/* @0x197a4c blx r3 */
/* @0x197a50 mov r1, #0 */
/* @0x197a54 mov r0, r5 */
/* @0x197a58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197a5c ldr r3, [r4] */
/* @0x197a60 mov r2, r5 */
/* @0x197a64 mov r1, #8 */
/* @0x197a68 ldr r3, [r3, #0xc] */
/* @0x197a6c str r0, [r6, #0xd8] */
/* @0x197a70 mov r0, r4 */
/* @0x197a74 blx r3 */
/* @0x197a78 mov r1, #0 */
/* @0x197a7c mov r0, r5 */
/* @0x197a80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197a84 ldr r3, [r4] */
/* @0x197a88 mov r2, r5 */
/* @0x197a8c mov r1, #8 */
/* @0x197a90 ldr r3, [r3, #0xc] */
/* @0x197a94 str r0, [r6, #0xdc] */
/* @0x197a98 mov r0, r4 */
/* @0x197a9c blx r3 */
/* @0x197aa0 mov r1, #0 */
/* @0x197aa4 mov r0, r5 */
/* @0x197aa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197aac ldr r3, [r4] */
/* @0x197ab0 mov r2, r5 */
/* @0x197ab4 mov r1, #8 */
/* @0x197ab8 ldr r3, [r3, #0xc] */
/* @0x197abc str r0, [r6, #0xe0] */
/* @0x197ac0 mov r0, r4 */
/* @0x197ac4 blx r3 */
/* @0x197ac8 mov r1, #0 */
/* @0x197acc mov r0, r5 */
/* @0x197ad0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197ad4 ldr r3, [r4] */
/* @0x197ad8 mov r2, r5 */
/* @0x197adc mov r1, #6 */
/* @0x197ae0 ldr r3, [r3, #0xc] */
/* @0x197ae4 str r0, [r6, #0xe4] */
/* @0x197ae8 mov r0, r4 */
/* @0x197aec blx r3 */
/* @0x197af0 mov r1, #0 */
/* @0x197af4 mov r0, r5 */
/* @0x197af8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197afc ldr r3, [r4] */
/* @0x197b00 mov r2, r5 */
/* @0x197b04 mov r1, #6 */
/* @0x197b08 ldr r3, [r3, #0xc] */
/* @0x197b0c str r0, [r6, #0xe8] */
/* @0x197b10 mov r0, r4 */
/* @0x197b14 blx r3 */
/* @0x197b18 mov r1, #0 */
/* @0x197b1c mov r0, r5 */
/* @0x197b20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197b24 ldr r3, [r4] */
/* @0x197b28 mov r2, r5 */
/* @0x197b2c mov r1, #6 */
/* @0x197b30 ldr r3, [r3, #0xc] */
/* @0x197b34 str r0, [r6, #0xf0] */
/* @0x197b38 mov r0, r4 */
/* @0x197b3c blx r3 */
/* @0x197b40 mov r1, #0 */
/* @0x197b44 mov r0, r5 */
/* @0x197b48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197b4c ldr r3, [r4] */
/* @0x197b50 mov r2, r5 */
/* @0x197b54 mov r1, #6 */
/* @0x197b58 ldr r3, [r3, #0xc] */
/* @0x197b5c str r0, [r6, #0xec] */
/* @0x197b60 mov r0, r4 */
/* @0x197b64 blx r3 */
/* @0x197b68 mov r1, #0 */
/* @0x197b6c mov r0, r5 */
/* @0x197b70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197b74 ldr r3, [r4] */
/* @0x197b78 mov r2, r5 */
/* @0x197b7c mov r1, #6 */
/* @0x197b80 ldr r3, [r3, #0xc] */
/* @0x197b84 str r0, [r6, #0xf4] */
/* @0x197b88 mov r0, r4 */
/* @0x197b8c blx r3 */
/* @0x197b90 mov r1, #0 */
/* @0x197b94 mov r0, r5 */
/* @0x197b98 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197b9c ldr r3, [r4] */
/* @0x197ba0 mov r2, r5 */
/* @0x197ba4 mov r1, #6 */
/* @0x197ba8 ldr r3, [r3, #0xc] */
/* @0x197bac strb r0, [r6, #0x65] */
/* @0x197bb0 mov r0, r4 */
/* @0x197bb4 blx r3 */
/* @0x197bb8 mov r1, #0 */
/* @0x197bbc mov r0, r5 */
/* @0x197bc0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197bc4 ldr r3, [r4] */
/* @0x197bc8 mov r2, r5 */
/* @0x197bcc mov r1, #6 */
/* @0x197bd0 ldr r3, [r3, #0xc] */
/* @0x197bd4 strb r0, [r6, #0x66] */
/* @0x197bd8 mov r0, r4 */
/* @0x197bdc blx r3 */
/* @0x197be0 mov r0, r5 */
/* @0x197be4 mov r1, #0 */
/* @0x197be8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197bec strb r0, [r6, #0x67] */
/* @0x197bf0 ldr r3, [r4] */
/* @0x197bf4 mov r1, #6 */
/* @0x197bf8 mov r2, r5 */
/* @0x197bfc mov r0, r4 */
/* @0x197c00 add r8, r8, #4 */
/* @0x197c04 ldr r3, [r3, #0xc] */
/* @0x197c08 blx r3 */
/* @0x197c0c mov r0, r5 */
/* @0x197c10 mov r1, #0 */
/* @0x197c14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197c18 subs r7, r7, #1 */
/* @0x197c1c str r0, [r8, #0xf4] */
/* @0x197c20 bne 0x197bf0 <_ZN9CInstance11DeSerialiseEP7IBufferb+0x584> */
/* @0x197c24 ldr r3, [r4] */
/* @0x197c28 mov r2, r5 */
/* @0x197c2c mov r1, #6 */
/* @0x197c30 mov r0, r4 */
/* @0x197c34 ldr r3, [r3, #0xc] */
/* @0x197c38 blx r3 */
/* @0x197c3c mov r1, r7 */
/* @0x197c40 mov r0, r5 */
/* @0x197c44 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197c48 ldr r3, [r4] */
/* @0x197c4c mov r2, r5 */
/* @0x197c50 mov r1, #6 */
/* @0x197c54 ldr r3, [r3, #0xc] */
/* @0x197c58 strb r0, [r6, #0x68] */
/* @0x197c5c mov r0, r4 */
/* @0x197c60 blx r3 */
/* @0x197c64 mov r1, r7 */
/* @0x197c68 mov r0, r5 */
/* @0x197c6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197c70 ldr r3, [r4] */
/* @0x197c74 mov r2, r5 */
/* @0x197c78 mov r1, #8 */
/* @0x197c7c ldr r3, [r3, #0xc] */
/* @0x197c80 str r0, [r6, #0x128] */
/* @0x197c84 mov r0, r4 */
/* @0x197c88 blx r3 */
/* @0x197c8c mov r1, r7 */
/* @0x197c90 mov r0, r5 */
/* @0x197c94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197c98 ldr r3, [r4] */
/* @0x197c9c mov r2, r5 */
/* @0x197ca0 mov r1, #8 */
/* @0x197ca4 ldr r3, [r3, #0xc] */
/* @0x197ca8 str r0, [r6, #0x12c] */
/* @0x197cac mov r0, r4 */
/* @0x197cb0 blx r3 */
/* @0x197cb4 mov r1, r7 */
/* @0x197cb8 mov r0, r5 */
/* @0x197cbc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197cc0 ldr r3, [r4] */
/* @0x197cc4 mov r2, r5 */
/* @0x197cc8 mov r1, #8 */
/* @0x197ccc ldr r3, [r3, #0xc] */
/* @0x197cd0 str r0, [r6, #0x130] */
/* @0x197cd4 mov r0, r4 */
/* @0x197cd8 blx r3 */
/* @0x197cdc mov r1, r7 */
/* @0x197ce0 mov r0, r5 */
/* @0x197ce4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197ce8 ldr r3, [r4] */
/* @0x197cec mov r2, r5 */
/* @0x197cf0 mov r1, #8 */
/* @0x197cf4 ldr r3, [r3, #0xc] */
/* @0x197cf8 str r0, [r6, #0x134] */
/* @0x197cfc mov r0, r4 */
/* @0x197d00 blx r3 */
/* @0x197d04 mov r1, r7 */
/* @0x197d08 mov r0, r5 */
/* @0x197d0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197d10 ldr r3, [r4] */
/* @0x197d14 mov r2, r5 */
/* @0x197d18 mov r1, #8 */
/* @0x197d1c ldr r3, [r3, #0xc] */
/* @0x197d20 str r0, [r6, #0x138] */
/* @0x197d24 mov r0, r4 */
/* @0x197d28 blx r3 */
/* @0x197d2c mov r1, r7 */
/* @0x197d30 mov r0, r5 */
/* @0x197d34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197d38 ldr r3, [r4] */
/* @0x197d3c mov r2, r5 */
/* @0x197d40 mov r1, #6 */
/* @0x197d44 ldr r3, [r3, #0xc] */
/* @0x197d48 str r0, [r6, #0x13c] */
/* @0x197d4c mov r0, r4 */
/* @0x197d50 blx r3 */
/* @0x197d54 mov r1, r7 */
/* @0x197d58 mov r0, r5 */
/* @0x197d5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197d60 ldr r3, [r4] */
/* @0x197d64 mov r2, r5 */
/* @0x197d68 mov r1, #8 */
/* @0x197d6c ldr r3, [r3, #0xc] */
/* @0x197d70 str r0, [r6, #0x140] */
/* @0x197d74 mov r0, r4 */
/* @0x197d78 blx r3 */
/* @0x197d7c mov r1, r7 */
/* @0x197d80 mov r0, r5 */
/* @0x197d84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197d88 ldr r3, [r4] */
/* @0x197d8c mov r2, r5 */
/* @0x197d90 mov r1, #8 */
/* @0x197d94 ldr r3, [r3, #0xc] */
/* @0x197d98 str r0, [r6, #0x144] */
/* @0x197d9c mov r0, r4 */
/* @0x197da0 blx r3 */
/* @0x197da4 mov r1, r7 */
/* @0x197da8 mov r0, r5 */
/* @0x197dac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197db0 ldr r3, [r4] */
/* @0x197db4 mov r2, r5 */
/* @0x197db8 mov r1, #6 */
/* @0x197dbc ldr r3, [r3, #0xc] */
/* @0x197dc0 str r0, [r6, #0x148] */
/* @0x197dc4 mov r0, r4 */
/* @0x197dc8 blx r3 */
/* @0x197dcc mov r1, r7 */
/* @0x197dd0 mov r0, r5 */
/* @0x197dd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197dd8 ldr r3, [r4] */
/* @0x197ddc mov r2, r5 */
/* @0x197de0 mov r1, #8 */
/* @0x197de4 ldr r3, [r3, #0xc] */
/* @0x197de8 str r0, [r6, #0x14c] */
/* @0x197dec mov r0, r4 */
/* @0x197df0 blx r3 */
/* @0x197df4 mov r1, r7 */
/* @0x197df8 mov r0, r5 */
/* @0x197dfc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197e00 ldr r3, [r4] */
/* @0x197e04 mov r2, r5 */
/* @0x197e08 mov r1, #8 */
/* @0x197e0c ldr r3, [r3, #0xc] */
/* @0x197e10 str r0, [r6, #0x150] */
/* @0x197e14 mov r0, r4 */
/* @0x197e18 blx r3 */
/* @0x197e1c mov r1, r7 */
/* @0x197e20 mov r0, r5 */
/* @0x197e24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197e28 ldr r3, [r4] */
/* @0x197e2c mov r2, r5 */
/* @0x197e30 mov r1, #8 */
/* @0x197e34 ldr r3, [r3, #0xc] */
/* @0x197e38 str r0, [r6, #0x154] */
/* @0x197e3c mov r0, r4 */
/* @0x197e40 blx r3 */
/* @0x197e44 mov r1, r7 */
/* @0x197e48 mov r0, r5 */
/* @0x197e4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197e50 ldr r3, [r4] */
/* @0x197e54 mov r2, r5 */
/* @0x197e58 mov r1, #6 */
/* @0x197e5c ldr r3, [r3, #0xc] */
/* @0x197e60 str r0, [r6, #0x158] */
/* @0x197e64 mov r0, r4 */
/* @0x197e68 blx r3 */
/* @0x197e6c mov r1, r7 */
/* @0x197e70 mov r0, r5 */
/* @0x197e74 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197e78 ldr r3, [r4] */
/* @0x197e7c mov r2, r5 */
/* @0x197e80 mov r1, #6 */
/* @0x197e84 ldr r3, [r3, #0xc] */
/* @0x197e88 strb r0, [r6, #0x15c] */
/* @0x197e8c mov r0, r4 */
/* @0x197e90 blx r3 */
/* @0x197e94 mov r1, r7 */
/* @0x197e98 mov r0, r5 */
/* @0x197e9c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197ea0 ldr r3, [r4] */
/* @0x197ea4 mov r2, r5 */
/* @0x197ea8 mov r1, #6 */
/* @0x197eac ldr r3, [r3, #0xc] */
/* @0x197eb0 strb r0, [r6, #0x15d] */
/* @0x197eb4 mov r0, r4 */
/* @0x197eb8 blx r3 */
/* @0x197ebc mov r1, r7 */
/* @0x197ec0 mov r0, r5 */
/* @0x197ec4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197ec8 ldr r3, [r4] */
/* @0x197ecc mov r1, #6 */
/* @0x197ed0 mov r2, r5 */
/* @0x197ed4 ldr r3, [r3, #0xc] */
/* @0x197ed8 strb r0, [r6, #0x15e] */
/* @0x197edc mov r0, r4 */
/* @0x197ee0 blx r3 */
/* @0x197ee4 mov r0, r5 */
/* @0x197ee8 mov r1, r7 */
/* @0x197eec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197ef0 ldr r3, [r6, #0x24] */
/* @0x197ef4 cmp r3, #0 */
/* @0x197ef8 str r0, [r6, #0x170] */
/* @0x197efc popeq {r4, r5, r6, r7, r8, pc} */
/* @0x197f00 ldr r3, [r4] */
/* @0x197f04 mov r1, #6 */
/* @0x197f08 mov r2, r5 */
/* @0x197f0c mov r0, r4 */
/* @0x197f10 ldr r3, [r3, #0xc] */
/* @0x197f14 blx r3 */
/* @0x197f18 mov r1, r7 */
/* @0x197f1c mov r0, r5 */
/* @0x197f20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197f24 ldr r3, [pc, #0x74] */
/* @0x197f28 ldr r3, [pc, r3] */
/* @0x197f2c ldr r3, [r3] */
/* @0x197f30 cmp r3, r0 */
/* @0x197f34 mov r7, r0 */
/* @0x197f38 beq 0x197f5c <_ZN9CInstance11DeSerialiseEP7IBufferb+0x8f0> */
/* @0x197f3c ldr r3, [pc, #0x60] */
/* @0x197f40 ldr r1, [pc, #0x60] */
/* @0x197f44 ldr r3, [pc, r3] */
/* @0x197f48 add r1, pc, r1 */
/* @0x197f4c ldr r0, [r3] */
/* @0x197f50 ldr r3, [r0] */
/* @0x197f54 ldr r3, [r3, #0xc] */
/* @0x197f58 blx r3 */
/* @0x197f5c cmp r7, #0 */
/* @0x197f60 pople {r4, r5, r6, r7, r8, pc} */
/* @0x197f64 mov r5, #0 */
/* @0x197f68 ldr r3, [r6, #0x4] */
/* @0x197f6c cmp r3, #0 */
/* @0x197f70 add r0, r3, r5, lsl #4 */
/* @0x197f74 beq 0x197f90 <_ZN9CInstance11DeSerialiseEP7IBufferb+0x924> */
/* @0x197f78 add r5, r5, #1 */
/* @0x197f7c mov r1, r4 */
/* @0x197f80 bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer> */
/* @0x197f84 cmp r5, r7 */
/* @0x197f88 bne 0x197f68 <_ZN9CInstance11DeSerialiseEP7IBufferb+0x8fc> */
/* @0x197f8c pop {r4, r5, r6, r7, r8, pc} */
/* @0x197f90 mov r0, r6 */
/* @0x197f94 mov r1, r5 */
/* @0x197f98 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x197f9c b 0x197f78 <_ZN9CInstance11DeSerialiseEP7IBufferb+0x90c> */
/* @0x197fa0 eoreq r5, r5, r12, ror #27 */
/* @0x197fa4 .word 0x002557d0 */
/* @0x197fa8 mulseq r11, r0, sp */

/* ── FUNC 0x197fac · YYObjectBase::InternalGetYYVarRef(int) · size=808 · insn=202 */
/* @0x197fac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x197fb0 mov r6, r0 */
/* @0x197fb4 ldr r7, [r0, #0x60] */
/* @0x197fb8 sub sp, sp, #12 */
/* @0x197fbc mov r5, r1 */
/* @0x197fc0 cmp r7, #0 */
/* @0x197fc4 beq 0x1981a0 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1f4> */
/* @0x197fc8 mov r0, r5 */
/* @0x197fcc bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x197fd0 ldr r1, [r7, #0x8] */
/* @0x197fd4 ldr r9, [r7, #0x10] */
/* @0x197fd8 bic r0, r0, #-2147483648 */
/* @0x197fdc and r3, r1, r0 */
/* @0x197fe0 lsl r4, r3, #1 */
/* @0x197fe4 add r2, r4, r3 */
/* @0x197fe8 add r2, r9, r2, lsl #2 */
/* @0x197fec ldr r2, [r2, #0x8] */
/* @0x197ff0 cmp r2, #0 */
/* @0x197ff4 beq 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8> */
/* @0x197ff8 cmp r0, r2 */
/* @0x197ffc beq 0x198180 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1d4> */
/* @0x198000 ldr r10, [r7] */
/* @0x198004 and r2, r1, r2 */
/* @0x198008 add r12, r3, r10 */
/* @0x19800c rsb r2, r2, r12 */
/* @0x198010 tst r2, r1 */
/* @0x198014 bmi 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8> */
/* @0x198018 mov r12, #0 */
/* @0x19801c b 0x198030 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x84> */
/* @0x198020 cmp r0, r2 */
/* @0x198024 beq 0x198178 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1cc> */
/* @0x198028 cmp r7, r12 */
/* @0x19802c blt 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8> */
/* @0x198030 add r3, r3, #1 */
/* @0x198034 add r12, r12, #1 */
/* @0x198038 and r3, r1, r3 */
/* @0x19803c add r8, r3, r10 */
/* @0x198040 lsl r4, r3, #1 */
/* @0x198044 add r2, r4, r3 */
/* @0x198048 add r2, r9, r2, lsl #2 */
/* @0x19804c ldr r2, [r2, #0x8] */
/* @0x198050 and r7, r1, r2 */
/* @0x198054 cmp r2, #0 */
/* @0x198058 rsb r7, r7, r8 */
/* @0x19805c and r7, r7, r1 */
/* @0x198060 bne 0x198020 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x74> */
/* @0x198064 bl 0x190dc0 <_Z9GetRValuev> */
/* @0x198068 mov r7, #0 */
/* @0x19806c ldr r3, [r6, #0x58] */
/* @0x198070 str r7, [r0] */
/* @0x198074 mov r4, r0 */
/* @0x198078 ldr r6, [r6, #0x60] */
/* @0x19807c str r3, [r0, #0xc] */
/* @0x198080 ldr r2, [r6, #0xc] */
/* @0x198084 mov r12, r6 */
/* @0x198088 ldr r3, [r6, #0x4] */
/* @0x19808c str r6, [sp, #0x4] */
/* @0x198090 cmp r3, r2 */
/* @0x198094 bgt 0x1981bc <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x210> */
/* @0x198098 ldr r12, [sp, #0x4] */
/* @0x19809c add r3, r3, #1 */
/* @0x1980a0 mov r0, r5 */
/* @0x1980a4 str r3, [r12, #0x4] */
/* @0x1980a8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1980ac ldr r12, [sp, #0x4] */
/* @0x1980b0 ldr r6, [r12, #0x8] */
/* @0x1980b4 ldr r10, [r12, #0x10] */
/* @0x1980b8 bic r0, r0, #-2147483648 */
/* @0x1980bc and r3, r0, r6 */
/* @0x1980c0 add r2, r3, r3, lsl #1 */
/* @0x1980c4 add r2, r10, r2, lsl #2 */
/* @0x1980c8 ldr r1, [r2, #0x8] */
/* @0x1980cc cmp r1, #0 */
/* @0x1980d0 beq 0x1981ac <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x200> */
/* @0x1980d4 ldr r12, [sp, #0x4] */
/* @0x1980d8 mov r9, r4 */
/* @0x1980dc mov r7, #0 */
/* @0x1980e0 ldr r11, [r12] */
/* @0x1980e4 b 0x198128 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x17c> */
/* @0x1980e8 ldr r8, [r2] */
/* @0x1980ec ldr r7, [r2, #0x4] */
/* @0x1980f0 str r0, [r2, #0x8] */
/* @0x1980f4 mov r0, r1 */
/* @0x1980f8 str r5, [r2] */
/* @0x1980fc mov r5, r8 */
/* @0x198100 str r9, [r2, #0x4] */
/* @0x198104 mov r9, r7 */
/* @0x198108 add r3, r3, #1 */
/* @0x19810c add r7, r12, #1 */
/* @0x198110 and r3, r3, r6 */
/* @0x198114 add r2, r3, r3, lsl #1 */
/* @0x198118 add r2, r10, r2, lsl #2 */
/* @0x19811c ldr r1, [r2, #0x8] */
/* @0x198120 cmp r1, #0 */
/* @0x198124 beq 0x1981b0 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x204> */
/* @0x198128 add r12, r3, r11 */
/* @0x19812c and r8, r1, r6 */
/* @0x198130 rsb r12, r8, r12 */
/* @0x198134 and r12, r12, r6 */
/* @0x198138 cmp r12, r7 */
/* @0x19813c blt 0x1980e8 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x13c> */
/* @0x198140 movne r12, r7 */
/* @0x198144 bne 0x198108 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x15c> */
/* @0x198148 cmp r1, r0 */
/* @0x19814c bne 0x198108 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x15c> */
/* @0x198150 ldr r7, [r2] */
/* @0x198154 cmp r5, r7 */
/* @0x198158 bne 0x198108 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x15c> */
/* @0x19815c ldr r12, [sp, #0x4] */
/* @0x198160 ldr r3, [r12, #0x4] */
/* @0x198164 stm r2, {r5, r9} */
/* @0x198168 sub r3, r3, #1 */
/* @0x19816c str r1, [r2, #0x8] */
/* @0x198170 str r3, [r12, #0x4] */
/* @0x198174 b 0x198194 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1e8> */
/* @0x198178 cmn r3, #1 */
/* @0x19817c beq 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8> */
/* @0x198180 add r3, r4, r3 */
/* @0x198184 add r9, r9, r3, lsl #2 */
/* @0x198188 cmn r9, #4 */
/* @0x19818c ldrne r4, [r9, #0x4] */
/* @0x198190 beq 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8> */
/* @0x198194 mov r0, r4 */
/* @0x198198 add sp, sp, #12 */
/* @0x19819c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1981a0 bl 0x1917dc <_ZN12YYObjectBase9AllocVarsEv> */
/* @0x1981a4 ldr r7, [r6, #0x60] */
/* @0x1981a8 b 0x197fc8 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1c> */
/* @0x1981ac mov r9, r4 */
/* @0x1981b0 stm r2, {r5, r9} */
/* @0x1981b4 str r0, [r2, #0x8] */
/* @0x1981b8 b 0x198194 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1e8> */
/* @0x1981bc ldr r9, [r6] */
/* @0x1981c0 mov r3, #1 */
/* @0x1981c4 ldr r8, [r6, #0x10] */
/* @0x1981c8 mov r2, #70 */
/* @0x1981cc ldr r1, [pc, #0xfc] */
/* @0x1981d0 lsl r0, r9, r3 */
/* @0x1981d4 str r0, [r6] */
/* @0x1981d8 add r6, r0, r9, lsl #2 */
/* @0x1981dc add r1, pc, r1 */
/* @0x1981e0 sub r0, r0, #1 */
/* @0x1981e4 str r0, [r12, #0x8] */
/* @0x1981e8 lsl r6, r6, #2 */
/* @0x1981ec mov r0, r6 */
/* @0x1981f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1981f4 ldr r12, [sp, #0x4] */
/* @0x1981f8 mov r2, r6 */
/* @0x1981fc mov r1, r7 */
/* @0x198200 str r0, [r12, #0x10] */
/* @0x198204 bl 0xb65b0 <memset@plt> */
/* @0x198208 ldr r12, [sp, #0x4] */
/* @0x19820c vldr s15, [pc, #184] */
/* @0x198210 ldr r2, [r12] */
/* @0x198214 str r7, [r12, #0x4] */
/* @0x198218 cmp r2, r7 */
/* @0x19821c vmov s13, r2 */
/* @0x198220 vcvt.f32.s32 s14, s13 */
/* @0x198224 vmul.f32 s15, s14, s15 */
/* @0x198228 vcvt.s32.f32 s15, s15 */
/* @0x19822c vstr s15, [r12, #12] */
/* @0x198230 ble 0x198258 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x2ac> */
/* @0x198234 ldr r12, [sp, #0x4] */
/* @0x198238 add r2, r2, r2, lsl #1 */
/* @0x19823c mov r1, r7 */
/* @0x198240 ldr r3, [r12, #0x10] */
/* @0x198244 add r2, r3, r2, lsl #2 */
/* @0x198248 str r1, [r3, #0x8] */
/* @0x19824c add r3, r3, #12 */
/* @0x198250 cmp r3, r2 */
/* @0x198254 bne 0x198248 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x29c> */
/* @0x198258 cmp r9, #0 */
/* @0x19825c ble 0x198294 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x2e8> */
/* @0x198260 ldr r10, [sp, #0x4] */
/* @0x198264 mov r6, r8 */
/* @0x198268 mov r7, #0 */
/* @0x19826c ldr r3, [r6, #0x8] */
/* @0x198270 mov r0, r10 */
/* @0x198274 add r7, r7, #1 */
/* @0x198278 cmp r3, #0 */
/* @0x19827c ble 0x198288 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x2dc> */
/* @0x198280 ldm r6, {r1, r2} */
/* @0x198284 bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_> */
/* @0x198288 cmp r7, r9 */
/* @0x19828c add r6, r6, #12 */
/* @0x198290 bne 0x19826c <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x2c0> */
/* @0x198294 mov r0, r8 */
/* @0x198298 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19829c ldr r12, [sp, #0x4] */
/* @0x1982a0 vldr s15, [pc, #36] */
/* @0x1982a4 ldr r12, [r12] */
/* @0x1982a8 str r12, [sp] */
/* @0x1982ac vldr s13, [sp] */
/* @0x1982b0 vcvt.f32.s32 s14, s13 */
/* @0x1982b4 ldr r12, [sp, #0x4] */
/* @0x1982b8 ldr r3, [r12, #0x4] */
/* @0x1982bc vmul.f32 s15, s14, s15 */
/* @0x1982c0 vcvt.s32.f32 s15, s15 */
/* @0x1982c4 vstr s15, [r12, #12] */
/* @0x1982c8 b 0x198098 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xec> */
/* @0x1982cc svclo #0x19999a */
/* @0x1982d0 andseq r8, r9, r4, asr lr */

/* ── FUNC 0x1982d4 · YYObjectBase::AssignVars(YYObjectBase*) · size=1048 · insn=262 */
/* @0x1982d4 ldr r3, [r1, #0x60] */
/* @0x1982d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1982dc vpush {d8} */
/* @0x1982e0 cmp r3, #0 */
/* @0x1982e4 sub sp, sp, #20 */
/* @0x1982e8 str r1, [sp, #0x4] */
/* @0x1982ec str r0, [sp, #0x8] */
/* @0x1982f0 beq 0x1985ec <_ZN12YYObjectBase10AssignVarsEPS_+0x318> */
/* @0x1982f4 mov r0, #20 */
/* @0x1982f8 mov r5, #0 */
/* @0x1982fc bl 0x27c524 <_Znwj> */
/* @0x198300 ldr r1, [pc, #0x3dc] */
/* @0x198304 mov r2, #8 */
/* @0x198308 mov r3, #7 */
/* @0x19830c add r1, pc, r1 */
/* @0x198310 mov r4, r0 */
/* @0x198314 str r2, [r0] */
/* @0x198318 str r3, [r4, #0x8] */
/* @0x19831c mov r2, #70 */
/* @0x198320 mov r3, #1 */
/* @0x198324 mov r0, #96 */
/* @0x198328 str r5, [r4, #0x10] */
/* @0x19832c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x198330 mov r2, #96 */
/* @0x198334 mov r1, r5 */
/* @0x198338 str r0, [r4, #0x10] */
/* @0x19833c bl 0xb65b0 <memset@plt> */
/* @0x198340 ldr r2, [r4] */
/* @0x198344 vldr s15, [pc, #916] */
/* @0x198348 str r5, [r4, #0x4] */
/* @0x19834c cmp r2, r5 */
/* @0x198350 vmov s13, r2 */
/* @0x198354 vcvt.f32.s32 s14, s13 */
/* @0x198358 vmul.f32 s15, s14, s15 */
/* @0x19835c vcvt.s32.f32 s15, s15 */
/* @0x198360 vstr s15, [r4, #12] */
/* @0x198364 ble 0x198388 <_ZN12YYObjectBase10AssignVarsEPS_+0xb4> */
/* @0x198368 add r2, r2, r2, lsl #1 */
/* @0x19836c ldr r3, [r4, #0x10] */
/* @0x198370 mov r1, r5 */
/* @0x198374 add r2, r3, r2, lsl #2 */
/* @0x198378 str r1, [r3, #0x8] */
/* @0x19837c add r3, r3, #12 */
/* @0x198380 cmp r3, r2 */
/* @0x198384 bne 0x198378 <_ZN12YYObjectBase10AssignVarsEPS_+0xa4> */
/* @0x198388 ldr r2, [sp, #0x4] */
/* @0x19838c ldr r1, [sp, #0x8] */
/* @0x198390 str r4, [r1, #0x60] */
/* @0x198394 ldr r3, [r2, #0x60] */
/* @0x198398 ldr r2, [r3, #0x4] */
/* @0x19839c cmp r2, #0 */
/* @0x1983a0 ble 0x1985ec <_ZN12YYObjectBase10AssignVarsEPS_+0x318> */
/* @0x1983a4 ldr r1, [pc, #0x33c] */
/* @0x1983a8 mov r2, #0 */
/* @0x1983ac vldr s16, [pc, #812] */
/* @0x1983b0 str r2, [sp] */
/* @0x1983b4 add r1, pc, r1 */
/* @0x1983b8 str r1, [sp, #0xc] */
/* @0x1983bc ldr r4, [r3, #0x10] */
/* @0x1983c0 mov r3, #0 */
/* @0x1983c4 ldr r1, [sp] */
/* @0x1983c8 b 0x1983d0 <_ZN12YYObjectBase10AssignVarsEPS_+0xfc> */
/* @0x1983cc add r4, r4, #12 */
/* @0x1983d0 ldr r2, [r4, #0x8] */
/* @0x1983d4 cmp r2, #0 */
/* @0x1983d8 ble 0x1983cc <_ZN12YYObjectBase10AssignVarsEPS_+0xf8> */
/* @0x1983dc cmp r1, r3 */
/* @0x1983e0 add r3, r3, #1 */
/* @0x1983e4 bne 0x1983cc <_ZN12YYObjectBase10AssignVarsEPS_+0xf8> */
/* @0x1983e8 ldr r7, [r4] */
/* @0x1983ec bl 0x190dc0 <_Z9GetRValuev> */
/* @0x1983f0 ldr r4, [r4, #0x4] */
/* @0x1983f4 ldr r3, [r4, #0xc] */
/* @0x1983f8 ldr r2, [r4, #0x8] */
/* @0x1983fc str r3, [r0, #0xc] */
/* @0x198400 mov r6, r0 */
/* @0x198404 ldr r3, [r4, #0xc] */
/* @0x198408 str r2, [r0, #0x8] */
/* @0x19840c bic r3, r3, #-16777216 */
/* @0x198410 cmp r3, #14 */
/* @0x198414 addls pc, pc, r3, lsl #2 */
/* @0x198418 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x19841c b 0x198548 <_ZN12YYObjectBase10AssignVarsEPS_+0x274> */
/* @0x198420 b 0x1985a4 <_ZN12YYObjectBase10AssignVarsEPS_+0x2d0> */
/* @0x198424 b 0x198578 <_ZN12YYObjectBase10AssignVarsEPS_+0x2a4> */
/* @0x198428 b 0x198458 <_ZN12YYObjectBase10AssignVarsEPS_+0x184> */
/* @0x19842c b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198430 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198434 b 0x198554 <_ZN12YYObjectBase10AssignVarsEPS_+0x280> */
/* @0x198438 b 0x198458 <_ZN12YYObjectBase10AssignVarsEPS_+0x184> */
/* @0x19843c b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198440 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198444 b 0x198548 <_ZN12YYObjectBase10AssignVarsEPS_+0x274> */
/* @0x198448 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x19844c b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198450 b 0x198548 <_ZN12YYObjectBase10AssignVarsEPS_+0x274> */
/* @0x198454 b 0x198458 <_ZN12YYObjectBase10AssignVarsEPS_+0x184> */
/* @0x198458 ldr r3, [r4] */
/* @0x19845c str r3, [r6] */
/* @0x198460 ldr r3, [sp, #0x8] */
/* @0x198464 ldr r8, [r3, #0x60] */
/* @0x198468 ldr r3, [r8, #0x4] */
/* @0x19846c ldr r2, [r8, #0xc] */
/* @0x198470 cmp r3, r2 */
/* @0x198474 bgt 0x1985f8 <_ZN12YYObjectBase10AssignVarsEPS_+0x324> */
/* @0x198478 add r3, r3, #1 */
/* @0x19847c mov r0, r7 */
/* @0x198480 str r3, [r8, #0x4] */
/* @0x198484 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x198488 ldr r4, [r8, #0x8] */
/* @0x19848c ldr r10, [r8, #0x10] */
/* @0x198490 bic r0, r0, #-2147483648 */
/* @0x198494 and r3, r0, r4 */
/* @0x198498 add r2, r3, r3, lsl #1 */
/* @0x19849c add r2, r10, r2, lsl #2 */
/* @0x1984a0 ldr r1, [r2, #0x8] */
/* @0x1984a4 cmp r1, #0 */
/* @0x1984a8 ldrne r11, [r8] */
/* @0x1984ac movne r5, #0 */
/* @0x1984b0 bne 0x1984f8 <_ZN12YYObjectBase10AssignVarsEPS_+0x224> */
/* @0x1984b4 b 0x1985bc <_ZN12YYObjectBase10AssignVarsEPS_+0x2e8> */
/* @0x1984b8 ldr r9, [r2] */
/* @0x1984bc ldr r5, [r2, #0x4] */
/* @0x1984c0 str r0, [r2, #0x8] */
/* @0x1984c4 mov r0, r1 */
/* @0x1984c8 str r7, [r2] */
/* @0x1984cc mov r7, r9 */
/* @0x1984d0 str r6, [r2, #0x4] */
/* @0x1984d4 mov r6, r5 */
/* @0x1984d8 add r3, r3, #1 */
/* @0x1984dc add r5, r12, #1 */
/* @0x1984e0 and r3, r3, r4 */
/* @0x1984e4 add r2, r3, r3, lsl #1 */
/* @0x1984e8 add r2, r10, r2, lsl #2 */
/* @0x1984ec ldr r1, [r2, #0x8] */
/* @0x1984f0 cmp r1, #0 */
/* @0x1984f4 beq 0x1985bc <_ZN12YYObjectBase10AssignVarsEPS_+0x2e8> */
/* @0x1984f8 add r12, r11, r3 */
/* @0x1984fc and r9, r1, r4 */
/* @0x198500 rsb r12, r9, r12 */
/* @0x198504 and r12, r12, r4 */
/* @0x198508 cmp r12, r5 */
/* @0x19850c blt 0x1984b8 <_ZN12YYObjectBase10AssignVarsEPS_+0x1e4> */
/* @0x198510 movne r12, r5 */
/* @0x198514 bne 0x1984d8 <_ZN12YYObjectBase10AssignVarsEPS_+0x204> */
/* @0x198518 cmp r1, r0 */
/* @0x19851c bne 0x1984d8 <_ZN12YYObjectBase10AssignVarsEPS_+0x204> */
/* @0x198520 ldr r5, [r2] */
/* @0x198524 cmp r7, r5 */
/* @0x198528 bne 0x1984d8 <_ZN12YYObjectBase10AssignVarsEPS_+0x204> */
/* @0x19852c ldr r3, [r8, #0x4] */
/* @0x198530 str r7, [r2] */
/* @0x198534 str r6, [r2, #0x4] */
/* @0x198538 sub r3, r3, #1 */
/* @0x19853c str r1, [r2, #0x8] */
/* @0x198540 str r3, [r8, #0x4] */
/* @0x198544 b 0x1985c8 <_ZN12YYObjectBase10AssignVarsEPS_+0x2f4> */
/* @0x198548 ldm r4, {r2, r3} */
/* @0x19854c stm r0, {r2, r3} */
/* @0x198550 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198554 ldr r3, [r4] */
/* @0x198558 str r3, [r0] */
/* @0x19855c ldr r3, [r4] */
/* @0x198560 cmp r3, #0 */
/* @0x198564 beq 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198568 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x19856c ldr r1, [r4] */
/* @0x198570 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x198574 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198578 ldr r3, [r4] */
/* @0x19857c cmp r3, #0 */
/* @0x198580 str r3, [r0] */
/* @0x198584 beq 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x198588 ldr r1, [r3, #0x8] */
/* @0x19858c ldr r2, [r3] */
/* @0x198590 cmp r1, #0 */
/* @0x198594 streq r0, [r3, #0x8] */
/* @0x198598 add r2, r2, #1 */
/* @0x19859c str r2, [r3] */
/* @0x1985a0 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c> */
/* @0x1985a4 ldr r3, [r4] */
/* @0x1985a8 cmp r3, #0 */
/* @0x1985ac ldrne r2, [r3, #0x4] */
/* @0x1985b0 addne r2, r2, #1 */
/* @0x1985b4 strne r2, [r3, #0x4] */
/* @0x1985b8 b 0x19845c <_ZN12YYObjectBase10AssignVarsEPS_+0x188> */
/* @0x1985bc str r7, [r2] */
/* @0x1985c0 str r6, [r2, #0x4] */
/* @0x1985c4 str r0, [r2, #0x8] */
/* @0x1985c8 ldr r1, [sp, #0x4] */
/* @0x1985cc ldr r2, [sp] */
/* @0x1985d0 ldr r3, [r1, #0x60] */
/* @0x1985d4 add r2, r2, #1 */
/* @0x1985d8 str r2, [sp] */
/* @0x1985dc ldr r1, [sp] */
/* @0x1985e0 ldr r2, [r3, #0x4] */
/* @0x1985e4 cmp r2, r1 */
/* @0x1985e8 bgt 0x1983bc <_ZN12YYObjectBase10AssignVarsEPS_+0xe8> */
/* @0x1985ec add sp, sp, #20 */
/* @0x1985f0 vpop {d8} */
/* @0x1985f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1985f8 ldr r9, [r8] */
/* @0x1985fc mov r3, #1 */
/* @0x198600 ldr r1, [sp, #0xc] */
/* @0x198604 mov r2, #70 */
/* @0x198608 ldr r5, [r8, #0x10] */
/* @0x19860c lsl r0, r9, r3 */
/* @0x198610 str r0, [r8] */
/* @0x198614 add r4, r0, r9, lsl #2 */
/* @0x198618 sub r0, r0, #1 */
/* @0x19861c str r0, [r8, #0x8] */
/* @0x198620 lsl r4, r4, #2 */
/* @0x198624 mov r0, r4 */
/* @0x198628 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19862c mov r2, r4 */
/* @0x198630 mov r1, #0 */
/* @0x198634 str r0, [r8, #0x10] */
/* @0x198638 bl 0xb65b0 <memset@plt> */
/* @0x19863c ldr r2, [r8] */
/* @0x198640 mov r1, #0 */
/* @0x198644 str r1, [r8, #0x4] */
/* @0x198648 cmp r2, r1 */
/* @0x19864c vmov s13, r2 */
/* @0x198650 vcvt.f32.s32 s15, s13 */
/* @0x198654 vmul.f32 s15, s15, s16 */
/* @0x198658 vcvt.s32.f32 s15, s15 */
/* @0x19865c vstr s15, [r8, #12] */
/* @0x198660 ble 0x198684 <_ZN12YYObjectBase10AssignVarsEPS_+0x3b0> */
/* @0x198664 add r2, r2, r2, lsl #1 */
/* @0x198668 ldr r3, [r8, #0x10] */
/* @0x19866c add r2, r3, r2, lsl #2 */
/* @0x198670 mov r1, #0 */
/* @0x198674 add r3, r3, #12 */
/* @0x198678 str r1, [r3, #-0x4] */
/* @0x19867c cmp r3, r2 */
/* @0x198680 bne 0x198670 <_ZN12YYObjectBase10AssignVarsEPS_+0x39c> */
/* @0x198684 cmp r9, #0 */
/* @0x198688 movgt r4, r5 */
/* @0x19868c movgt r10, #0 */
/* @0x198690 ble 0x1986bc <_ZN12YYObjectBase10AssignVarsEPS_+0x3e8> */
/* @0x198694 ldr r3, [r4, #0x8] */
/* @0x198698 mov r0, r8 */
/* @0x19869c add r10, r10, #1 */
/* @0x1986a0 cmp r3, #0 */
/* @0x1986a4 ble 0x1986b0 <_ZN12YYObjectBase10AssignVarsEPS_+0x3dc> */
/* @0x1986a8 ldm r4, {r1, r2} */
/* @0x1986ac bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_> */
/* @0x1986b0 cmp r10, r9 */
/* @0x1986b4 add r4, r4, #12 */
/* @0x1986b8 bne 0x198694 <_ZN12YYObjectBase10AssignVarsEPS_+0x3c0> */
/* @0x1986bc mov r0, r5 */
/* @0x1986c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1986c4 vldr s13, [r8] */
/* @0x1986c8 vcvt.f32.s32 s15, s13 */
/* @0x1986cc ldr r3, [r8, #0x4] */
/* @0x1986d0 vmul.f32 s15, s15, s16 */
/* @0x1986d4 vcvt.s32.f32 s15, s15 */
/* @0x1986d8 vstr s15, [r8, #12] */
/* @0x1986dc b 0x198478 <_ZN12YYObjectBase10AssignVarsEPS_+0x1a4> */
/* @0x1986e0 svclo #0x19999a */
/* @0x1986e4 andseq r8, r9, r4, lsr #26 */
/* @0x1986e8 andseq r8, r9, r12, ror r12 */

/* ── FUNC 0x1986ec · CInstance::Assign(CInstance*, bool) · size=1728 · insn=432 */
/* @0x1986ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1986f0 vpush {d8} */
/* @0x1986f4 sub sp, sp, #20 */
/* @0x1986f8 mov r4, r2 */
/* @0x1986fc stm sp, {r0, r1} */
/* @0x198700 ldr r0, [r0, #0x80] */
/* @0x198704 cmp r0, #0 */
/* @0x198708 beq 0x198720 <_ZN9CInstance6AssignEPS_b+0x34> */
/* @0x19870c ldr r1, [sp] */
/* @0x198710 bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> */
/* @0x198714 ldr r5, [sp] */
/* @0x198718 mov r3, #0 */
/* @0x19871c str r3, [r5, #0x80] */
/* @0x198720 ldr r6, [sp, #0x4] */
/* @0x198724 ldr r7, [sp] */
/* @0x198728 ldr r12, [r6, #0x78] */
/* @0x19872c ldr r2, [r6, #0x90] */
/* @0x198730 ldr r0, [r6, #0x8c] */
/* @0x198734 ldr r3, [r6, #0x94] */
/* @0x198738 ldr r1, [r6, #0xa8] */
/* @0x19873c ldr r5, [r6, #0x98] */
/* @0x198740 str r2, [r7, #0x90] */
/* @0x198744 ldr r2, [r6, #0xac] */
/* @0x198748 str r3, [r7, #0x94] */
/* @0x19874c ldrb r3, [r6, #0xb0] */
/* @0x198750 str r12, [r7, #0x78] */
/* @0x198754 str r0, [r7, #0x8c] */
/* @0x198758 ldr r12, [r6, #0x9c] */
/* @0x19875c ldr r0, [r6, #0xa0] */
/* @0x198760 str r5, [r7, #0x98] */
/* @0x198764 str r12, [r7, #0x9c] */
/* @0x198768 str r0, [r7, #0xa0] */
/* @0x19876c ldr r12, [r6, #0xa4] */
/* @0x198770 ldr r0, [r6, #0x180] */
/* @0x198774 str r2, [r7, #0xac] */
/* @0x198778 ldr r2, [r6, #0xb4] */
/* @0x19877c strb r3, [r7, #0xb0] */
/* @0x198780 mov r3, #0 */
/* @0x198784 strb r3, [r7, #0x6b] */
/* @0x198788 str r2, [r7, #0xb4] */
/* @0x19878c ldr r2, [r6, #0xb8] */
/* @0x198790 ldr r3, [r6, #0xbc] */
/* @0x198794 str r1, [r7, #0xa8] */
/* @0x198798 str r2, [r7, #0xb8] */
/* @0x19879c ldr r2, [r6, #0xc0] */
/* @0x1987a0 str r3, [r7, #0xbc] */
/* @0x1987a4 str r12, [r7, #0xa4] */
/* @0x1987a8 ldr r3, [r6, #0xc4] */
/* @0x1987ac str r0, [r7, #0x180] */
/* @0x1987b0 str r2, [r7, #0xc0] */
/* @0x1987b4 ldr r1, [r6, #0xc8] */
/* @0x1987b8 ldr r2, [r6, #0xcc] */
/* @0x1987bc str r3, [r7, #0xc4] */
/* @0x1987c0 ldrb r3, [r6, #0x64] */
/* @0x1987c4 str r1, [r7, #0xc8] */
/* @0x1987c8 str r2, [r7, #0xcc] */
/* @0x1987cc cmp r3, #0 */
/* @0x1987d0 ldr r1, [r6, #0xd0] */
/* @0x1987d4 ldr r2, [r6, #0xd4] */
/* @0x1987d8 str r1, [r7, #0xd0] */
/* @0x1987dc str r2, [r7, #0xd4] */
/* @0x1987e0 ldr r1, [r6, #0xd8] */
/* @0x1987e4 ldr r2, [r6, #0xdc] */
/* @0x1987e8 str r1, [r7, #0xd8] */
/* @0x1987ec str r2, [r7, #0xdc] */
/* @0x1987f0 ldr r1, [r6, #0xe0] */
/* @0x1987f4 ldr r2, [r6, #0xe4] */
/* @0x1987f8 strb r3, [r7, #0x64] */
/* @0x1987fc str r1, [r7, #0xe0] */
/* @0x198800 str r2, [r7, #0xe4] */
/* @0x198804 bne 0x198da0 <_ZN9CInstance6AssignEPS_b+0x6b4> */
/* @0x198808 ldr r3, [sp, #0x4] */
/* @0x19880c cmp r4, #0 */
/* @0x198810 ldr r8, [sp] */
/* @0x198814 ldr r9, [sp, #0x4] */
/* @0x198818 ldr r5, [r3, #0xe8]! */
/* @0x19881c add r12, r8, #232 */
/* @0x198820 ldr r0, [r3, #0x4] */
/* @0x198824 ldr r1, [r3, #0x8] */
/* @0x198828 ldr r2, [r3, #0xc] */
/* @0x19882c str r5, [r8, #0xe8] */
/* @0x198830 str r0, [r12, #0x4] */
/* @0x198834 str r1, [r12, #0x8] */
/* @0x198838 str r2, [r12, #0xc] */
/* @0x19883c ldrb r12, [r9, #0x65] */
/* @0x198840 ldrb r1, [r9, #0x66] */
/* @0x198844 ldrb r2, [r9, #0x67] */
/* @0x198848 ldr r3, [r9, #0x7c] */
/* @0x19884c ldr r0, [r9, #0x80] */
/* @0x198850 strb r12, [r8, #0x65] */
/* @0x198854 strb r1, [r8, #0x66] */
/* @0x198858 strb r2, [r8, #0x67] */
/* @0x19885c str r3, [r8, #0x7c] */
/* @0x198860 str r0, [r8, #0x80] */
/* @0x198864 beq 0x198878 <_ZN9CInstance6AssignEPS_b+0x18c> */
/* @0x198868 cmp r0, #0 */
/* @0x19886c beq 0x198878 <_ZN9CInstance6AssignEPS_b+0x18c> */
/* @0x198870 mov r1, r8 */
/* @0x198874 bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> */
/* @0x198878 ldr r2, [sp, #0x4] */
/* @0x19887c mov r4, #12 */
/* @0x198880 ldr r3, [sp] */
/* @0x198884 ldr r1, [r2, #0xf8] */
/* @0x198888 subs r4, r4, #1 */
/* @0x19888c add r2, r2, #4 */
/* @0x198890 add r3, r3, #4 */
/* @0x198894 str r1, [r3, #0xf4] */
/* @0x198898 bne 0x198884 <_ZN9CInstance6AssignEPS_b+0x198> */
/* @0x19889c ldr r12, [sp, #0x4] */
/* @0x1988a0 ldr r3, [r12, #0x60] */
/* @0x1988a4 cmp r3, #0 */
/* @0x1988a8 beq 0x198b98 <_ZN9CInstance6AssignEPS_b+0x4ac> */
/* @0x1988ac mov r0, #20 */
/* @0x1988b0 bl 0x27c524 <_Znwj> */
/* @0x1988b4 ldr r1, [pc, #0x3f4] */
/* @0x1988b8 mov r2, #8 */
/* @0x1988bc mov r3, #7 */
/* @0x1988c0 add r1, pc, r1 */
/* @0x1988c4 mov r5, r0 */
/* @0x1988c8 str r2, [r0] */
/* @0x1988cc str r3, [r0, #0x8] */
/* @0x1988d0 mov r2, #70 */
/* @0x1988d4 str r4, [r0, #0x10] */
/* @0x1988d8 mov r3, #1 */
/* @0x1988dc mov r0, #96 */
/* @0x1988e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1988e4 mov r2, #96 */
/* @0x1988e8 mov r1, r4 */
/* @0x1988ec str r0, [r5, #0x10] */
/* @0x1988f0 bl 0xb65b0 <memset@plt> */
/* @0x1988f4 ldr r2, [r5] */
/* @0x1988f8 vldr s15, [pc, #940] */
/* @0x1988fc str r4, [r5, #0x4] */
/* @0x198900 cmp r2, #0 */
/* @0x198904 vmov s13, r2 */
/* @0x198908 vcvt.f32.s32 s14, s13 */
/* @0x19890c vmul.f32 s15, s14, s15 */
/* @0x198910 vcvt.s32.f32 s15, s15 */
/* @0x198914 vstr s15, [r5, #12] */
/* @0x198918 ble 0x198938 <_ZN9CInstance6AssignEPS_b+0x24c> */
/* @0x19891c add r2, r2, r2, lsl #1 */
/* @0x198920 ldr r3, [r5, #0x10] */
/* @0x198924 add r2, r3, r2, lsl #2 */
/* @0x198928 str r4, [r3, #0x8] */
/* @0x19892c add r3, r3, #12 */
/* @0x198930 cmp r3, r2 */
/* @0x198934 bne 0x198928 <_ZN9CInstance6AssignEPS_b+0x23c> */
/* @0x198938 ldr r4, [sp] */
/* @0x19893c str r5, [r4, #0x60] */
/* @0x198940 ldr r5, [sp, #0x4] */
/* @0x198944 ldr r3, [r5, #0x60] */
/* @0x198948 ldr r2, [r3, #0x4] */
/* @0x19894c cmp r2, #0 */
/* @0x198950 ble 0x198b98 <_ZN9CInstance6AssignEPS_b+0x4ac> */
/* @0x198954 ldr r6, [pc, #0x358] */
/* @0x198958 mov r7, #0 */
/* @0x19895c vldr s16, [pc, #840] */
/* @0x198960 str r7, [sp, #0x8] */
/* @0x198964 add r6, pc, r6 */
/* @0x198968 str r6, [sp, #0xc] */
/* @0x19896c ldr r4, [r3, #0x10] */
/* @0x198970 mov r3, #0 */
/* @0x198974 ldr r1, [sp, #0x8] */
/* @0x198978 b 0x198980 <_ZN9CInstance6AssignEPS_b+0x294> */
/* @0x19897c add r4, r4, #12 */
/* @0x198980 ldr r2, [r4, #0x8] */
/* @0x198984 cmp r2, #0 */
/* @0x198988 ble 0x19897c <_ZN9CInstance6AssignEPS_b+0x290> */
/* @0x19898c cmp r1, r3 */
/* @0x198990 add r3, r3, #1 */
/* @0x198994 bne 0x19897c <_ZN9CInstance6AssignEPS_b+0x290> */
/* @0x198998 ldr r7, [r4] */
/* @0x19899c bl 0x190dc0 <_Z9GetRValuev> */
/* @0x1989a0 ldr r4, [r4, #0x4] */
/* @0x1989a4 ldr r3, [r4, #0xc] */
/* @0x1989a8 ldr r2, [r4, #0x8] */
/* @0x1989ac str r3, [r0, #0xc] */
/* @0x1989b0 mov r6, r0 */
/* @0x1989b4 ldr r3, [r4, #0xc] */
/* @0x1989b8 str r2, [r0, #0x8] */
/* @0x1989bc bic r3, r3, #-16777216 */
/* @0x1989c0 cmp r3, #14 */
/* @0x1989c4 addls pc, pc, r3, lsl #2 */
/* @0x1989c8 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989cc b 0x198af8 <_ZN9CInstance6AssignEPS_b+0x40c> */
/* @0x1989d0 b 0x198b54 <_ZN9CInstance6AssignEPS_b+0x468> */
/* @0x1989d4 b 0x198b28 <_ZN9CInstance6AssignEPS_b+0x43c> */
/* @0x1989d8 b 0x198a08 <_ZN9CInstance6AssignEPS_b+0x31c> */
/* @0x1989dc b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989e0 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989e4 b 0x198b04 <_ZN9CInstance6AssignEPS_b+0x418> */
/* @0x1989e8 b 0x198a08 <_ZN9CInstance6AssignEPS_b+0x31c> */
/* @0x1989ec b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989f0 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989f4 b 0x198af8 <_ZN9CInstance6AssignEPS_b+0x40c> */
/* @0x1989f8 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989fc b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198a00 b 0x198af8 <_ZN9CInstance6AssignEPS_b+0x40c> */
/* @0x198a04 b 0x198a08 <_ZN9CInstance6AssignEPS_b+0x31c> */
/* @0x198a08 ldr r3, [r4] */
/* @0x198a0c str r3, [r6] */
/* @0x198a10 ldr r9, [sp] */
/* @0x198a14 ldr r8, [r9, #0x60] */
/* @0x198a18 ldr r3, [r8, #0x4] */
/* @0x198a1c ldr r2, [r8, #0xc] */
/* @0x198a20 cmp r3, r2 */
/* @0x198a24 bgt 0x198cb8 <_ZN9CInstance6AssignEPS_b+0x5cc> */
/* @0x198a28 add r3, r3, #1 */
/* @0x198a2c mov r0, r7 */
/* @0x198a30 str r3, [r8, #0x4] */
/* @0x198a34 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x198a38 ldr r4, [r8, #0x8] */
/* @0x198a3c ldr r10, [r8, #0x10] */
/* @0x198a40 bic r0, r0, #-2147483648 */
/* @0x198a44 and r3, r0, r4 */
/* @0x198a48 add r2, r3, r3, lsl #1 */
/* @0x198a4c add r2, r10, r2, lsl #2 */
/* @0x198a50 ldr r1, [r2, #0x8] */
/* @0x198a54 cmp r1, #0 */
/* @0x198a58 ldrne r11, [r8] */
/* @0x198a5c movne r5, #0 */
/* @0x198a60 bne 0x198aa8 <_ZN9CInstance6AssignEPS_b+0x3bc> */
/* @0x198a64 b 0x198b6c <_ZN9CInstance6AssignEPS_b+0x480> */
/* @0x198a68 ldr r9, [r2] */
/* @0x198a6c ldr r5, [r2, #0x4] */
/* @0x198a70 str r0, [r2, #0x8] */
/* @0x198a74 mov r0, r1 */
/* @0x198a78 str r7, [r2] */
/* @0x198a7c mov r7, r9 */
/* @0x198a80 str r6, [r2, #0x4] */
/* @0x198a84 mov r6, r5 */
/* @0x198a88 add r3, r3, #1 */
/* @0x198a8c add r5, r12, #1 */
/* @0x198a90 and r3, r3, r4 */
/* @0x198a94 add r2, r3, r3, lsl #1 */
/* @0x198a98 add r2, r10, r2, lsl #2 */
/* @0x198a9c ldr r1, [r2, #0x8] */
/* @0x198aa0 cmp r1, #0 */
/* @0x198aa4 beq 0x198b6c <_ZN9CInstance6AssignEPS_b+0x480> */
/* @0x198aa8 add r12, r11, r3 */
/* @0x198aac and r9, r1, r4 */
/* @0x198ab0 rsb r12, r9, r12 */
/* @0x198ab4 and r12, r12, r4 */
/* @0x198ab8 cmp r12, r5 */
/* @0x198abc blt 0x198a68 <_ZN9CInstance6AssignEPS_b+0x37c> */
/* @0x198ac0 movne r12, r5 */
/* @0x198ac4 bne 0x198a88 <_ZN9CInstance6AssignEPS_b+0x39c> */
/* @0x198ac8 cmp r1, r0 */
/* @0x198acc bne 0x198a88 <_ZN9CInstance6AssignEPS_b+0x39c> */
/* @0x198ad0 ldr r5, [r2] */
/* @0x198ad4 cmp r7, r5 */
/* @0x198ad8 bne 0x198a88 <_ZN9CInstance6AssignEPS_b+0x39c> */
/* @0x198adc ldr r3, [r8, #0x4] */
/* @0x198ae0 str r7, [r2] */
/* @0x198ae4 str r6, [r2, #0x4] */
/* @0x198ae8 sub r3, r3, #1 */
/* @0x198aec str r1, [r2, #0x8] */
/* @0x198af0 str r3, [r8, #0x4] */
/* @0x198af4 b 0x198b78 <_ZN9CInstance6AssignEPS_b+0x48c> */
/* @0x198af8 ldm r4, {r2, r3} */
/* @0x198afc stm r0, {r2, r3} */
/* @0x198b00 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b04 ldr r3, [r4] */
/* @0x198b08 str r3, [r0] */
/* @0x198b0c ldr r3, [r4] */
/* @0x198b10 cmp r3, #0 */
/* @0x198b14 beq 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b18 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x198b1c ldr r1, [r4] */
/* @0x198b20 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x198b24 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b28 ldr r3, [r4] */
/* @0x198b2c cmp r3, #0 */
/* @0x198b30 str r3, [r0] */
/* @0x198b34 beq 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b38 ldr r1, [r3, #0x8] */
/* @0x198b3c ldr r2, [r3] */
/* @0x198b40 cmp r1, #0 */
/* @0x198b44 streq r0, [r3, #0x8] */
/* @0x198b48 add r2, r2, #1 */
/* @0x198b4c str r2, [r3] */
/* @0x198b50 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b54 ldr r3, [r4] */
/* @0x198b58 cmp r3, #0 */
/* @0x198b5c ldrne r2, [r3, #0x4] */
/* @0x198b60 addne r2, r2, #1 */
/* @0x198b64 strne r2, [r3, #0x4] */
/* @0x198b68 b 0x198a0c <_ZN9CInstance6AssignEPS_b+0x320> */
/* @0x198b6c str r7, [r2] */
/* @0x198b70 str r6, [r2, #0x4] */
/* @0x198b74 str r0, [r2, #0x8] */
/* @0x198b78 ldr r4, [sp, #0x4] */
/* @0x198b7c ldr r5, [sp, #0x8] */
/* @0x198b80 ldr r3, [r4, #0x60] */
/* @0x198b84 add r5, r5, #1 */
/* @0x198b88 str r5, [sp, #0x8] */
/* @0x198b8c ldr r2, [r3, #0x4] */
/* @0x198b90 cmp r2, r5 */
/* @0x198b94 bgt 0x19896c <_ZN9CInstance6AssignEPS_b+0x280> */
/* @0x198b98 ldr r4, [sp, #0x4] */
/* @0x198b9c ldr r9, [sp, #0x4] */
/* @0x198ba0 ldr r8, [sp] */
/* @0x198ba4 ldr r3, [r4, #0x134] */
/* @0x198ba8 ldrb r7, [r4, #0x68] */
/* @0x198bac ldr r1, [r4, #0x12c] */
/* @0x198bb0 ldrb r6, [r4, #0x69] */
/* @0x198bb4 ldr r2, [r4, #0x130] */
/* @0x198bb8 ldr r5, [r4, #0x128] */
/* @0x198bbc ldr r12, [r9, #0x14c] */
/* @0x198bc0 ldr r4, [r4, #0x140] */
/* @0x198bc4 ldrb r0, [r9, #0x15c] */
/* @0x198bc8 str r3, [r8, #0x134] */
/* @0x198bcc ldr r3, [r9, #0x138] */
/* @0x198bd0 str r1, [r8, #0x12c] */
/* @0x198bd4 str r2, [r8, #0x130] */
/* @0x198bd8 ldrb r1, [r9, #0x15d] */
/* @0x198bdc ldr r2, [r9, #0x160] */
/* @0x198be0 str r3, [r8, #0x138] */
/* @0x198be4 ldr r3, [r9, #0x164] */
/* @0x198be8 ldr r8, [r9, #0x13c] */
/* @0x198bec ldr r9, [sp] */
/* @0x198bf0 strb r7, [r9, #0x68] */
/* @0x198bf4 ldr r7, [sp, #0x4] */
/* @0x198bf8 strb r6, [r9, #0x69] */
/* @0x198bfc str r8, [r9, #0x13c] */
/* @0x198c00 ldr r6, [r7, #0x150] */
/* @0x198c04 str r4, [r9, #0x140] */
/* @0x198c08 ldr r4, [r7, #0x154] */
/* @0x198c0c str r5, [r9, #0x128] */
/* @0x198c10 str r12, [r9, #0x14c] */
/* @0x198c14 str r6, [r9, #0x150] */
/* @0x198c18 ldr r12, [r7, #0x158] */
/* @0x198c1c str r4, [r9, #0x154] */
/* @0x198c20 strb r0, [r9, #0x15c] */
/* @0x198c24 str r2, [r9, #0x160] */
/* @0x198c28 ldr r2, [r7, #0x88] */
/* @0x198c2c str r3, [r9, #0x164] */
/* @0x198c30 ldrb r3, [r7, #0x15e] */
/* @0x198c34 cmp r2, #0 */
/* @0x198c38 str r12, [r9, #0x158] */
/* @0x198c3c strb r1, [r9, #0x15d] */
/* @0x198c40 strb r3, [r9, #0x15e] */
/* @0x198c44 beq 0x198c90 <_ZN9CInstance6AssignEPS_b+0x5a4> */
/* @0x198c48 ldr r6, [sp] */
/* @0x198c4c ldr r4, [r6, #0x88] */
/* @0x198c50 cmp r4, #0 */
/* @0x198c54 beq 0x198c70 <_ZN9CInstance6AssignEPS_b+0x584> */
/* @0x198c58 mov r0, r4 */
/* @0x198c5c bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> */
/* @0x198c60 mov r0, r4 */
/* @0x198c64 bl 0x27d1d0 <_ZdlPv> */
/* @0x198c68 mov r3, #0 */
/* @0x198c6c str r3, [r6, #0x88] */
/* @0x198c70 mov r0, #52 */
/* @0x198c74 bl 0x27c524 <_Znwj> */
/* @0x198c78 ldr r7, [sp, #0x4] */
/* @0x198c7c ldr r1, [r7, #0x88] */
/* @0x198c80 mov r4, r0 */
/* @0x198c84 bl 0xc04d8 <_ZN17CSkeletonInstanceC2EPS_> */
/* @0x198c88 ldr r8, [sp] */
/* @0x198c8c str r4, [r8, #0x88] */
/* @0x198c90 ldr r9, [sp, #0x4] */
/* @0x198c94 ldr r12, [sp] */
/* @0x198c98 ldr r3, [r9, #0x170] */
/* @0x198c9c str r3, [r12, #0x170] */
/* @0x198ca0 add sp, sp, #20 */
/* @0x198ca4 vpop {d8} */
/* @0x198ca8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x198cac svclo #0x19999a */
/* @0x198cb0 andseq r8, r9, r0, ror r7 */
/* @0x198cb4 andseq r8, r9, r12, asr #13 */
/* @0x198cb8 ldr r9, [r8] */
/* @0x198cbc mov r3, #1 */
/* @0x198cc0 ldr r1, [sp, #0xc] */
/* @0x198cc4 mov r2, #70 */
/* @0x198cc8 ldr r5, [r8, #0x10] */
/* @0x198ccc lsl r0, r9, r3 */
/* @0x198cd0 str r0, [r8] */
/* @0x198cd4 add r4, r0, r9, lsl #2 */
/* @0x198cd8 sub r0, r0, #1 */
/* @0x198cdc str r0, [r8, #0x8] */
/* @0x198ce0 lsl r4, r4, #2 */
/* @0x198ce4 mov r0, r4 */
/* @0x198ce8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x198cec mov r2, r4 */
/* @0x198cf0 mov r1, #0 */
/* @0x198cf4 str r0, [r8, #0x10] */
/* @0x198cf8 bl 0xb65b0 <memset@plt> */
/* @0x198cfc ldr r2, [r8] */
/* @0x198d00 mov r12, #0 */
/* @0x198d04 str r12, [r8, #0x4] */
/* @0x198d08 cmp r2, r12 */
/* @0x198d0c vmov s13, r2 */
/* @0x198d10 vcvt.f32.s32 s15, s13 */
/* @0x198d14 vmul.f32 s15, s15, s16 */
/* @0x198d18 vcvt.s32.f32 s15, s15 */
/* @0x198d1c vstr s15, [r8, #12] */
/* @0x198d20 ble 0x198d44 <_ZN9CInstance6AssignEPS_b+0x658> */
/* @0x198d24 add r2, r2, r2, lsl #1 */
/* @0x198d28 ldr r3, [r8, #0x10] */
/* @0x198d2c add r2, r3, r2, lsl #2 */
/* @0x198d30 mov r0, #0 */
/* @0x198d34 add r3, r3, #12 */
/* @0x198d38 str r0, [r3, #-0x4] */
/* @0x198d3c cmp r3, r2 */
/* @0x198d40 bne 0x198d30 <_ZN9CInstance6AssignEPS_b+0x644> */
/* @0x198d44 cmp r9, #0 */
/* @0x198d48 movgt r4, r5 */
/* @0x198d4c movgt r10, #0 */
/* @0x198d50 ble 0x198d7c <_ZN9CInstance6AssignEPS_b+0x690> */
/* @0x198d54 ldr r3, [r4, #0x8] */
/* @0x198d58 mov r0, r8 */
/* @0x198d5c add r10, r10, #1 */
/* @0x198d60 cmp r3, #0 */
/* @0x198d64 ble 0x198d70 <_ZN9CInstance6AssignEPS_b+0x684> */
/* @0x198d68 ldm r4, {r1, r2} */
/* @0x198d6c bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_> */
/* @0x198d70 cmp r10, r9 */
/* @0x198d74 add r4, r4, #12 */
/* @0x198d78 bne 0x198d54 <_ZN9CInstance6AssignEPS_b+0x668> */
/* @0x198d7c mov r0, r5 */
/* @0x198d80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x198d84 vldr s13, [r8] */
/* @0x198d88 vcvt.f32.s32 s15, s13 */
/* @0x198d8c ldr r3, [r8, #0x4] */
/* @0x198d90 vmul.f32 s15, s15, s16 */
/* @0x198d94 vcvt.s32.f32 s15, s15 */
/* @0x198d98 vstr s15, [r8, #12] */
/* @0x198d9c b 0x198a28 <_ZN9CInstance6AssignEPS_b+0x33c> */
/* @0x198da0 mov r0, r7 */
/* @0x198da4 bl 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x198da8 b 0x198808 <_ZN9CInstance6AssignEPS_b+0x11c> */

/* ── FUNC 0x198dac · YYObjectBase::FreeVars(YYObjectBase*, RValue**, RValue**, RVariable**, RVariable**) · size=476 · insn=119 */
/* @0x198dac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x198db0 mov r8, r0 */
/* @0x198db4 ldr r4, [r0, #0x4] */
/* @0x198db8 sub sp, sp, #12 */
/* @0x198dbc mov r10, r1 */
/* @0x198dc0 mov r11, r2 */
/* @0x198dc4 cmp r4, #0 */
/* @0x198dc8 beq 0x198e34 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x88> */
/* @0x198dcc ldr r5, [r0, #0x24] */
/* @0x198dd0 cmp r5, #0 */
/* @0x198dd4 ble 0x198f70 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x1c4> */
/* @0x198dd8 mov r6, #0 */
/* @0x198ddc mov r7, #5 */
/* @0x198de0 b 0x198df8 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x4c> */
/* @0x198de4 subs r5, r5, #1 */
/* @0x198de8 str r6, [r4, #0x8] */
/* @0x198dec str r7, [r4, #0xc] */
/* @0x198df0 str r6, [r4], #16 */
/* @0x198df4 beq 0x198e1c <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x70> */
/* @0x198df8 ldr r3, [r4, #0xc] */
/* @0x198dfc sub r3, r3, #1 */
/* @0x198e00 bic r3, r3, #-16777216 */
/* @0x198e04 bic r3, r3, #3 */
/* @0x198e08 cmp r3, #0 */
/* @0x198e0c bne 0x198de4 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x38> */
/* @0x198e10 mov r0, r4 */
/* @0x198e14 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x198e18 b 0x198de4 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x38> */
/* @0x198e1c ldr r0, [r8, #0x4] */
/* @0x198e20 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x198e24 mov r3, #0 */
/* @0x198e28 str r3, [r8, #0x4] */
/* @0x198e2c str r3, [r8, #0x2c] */
/* @0x198e30 str r3, [r8, #0x24] */
/* @0x198e34 ldr r12, [r8, #0x60] */
/* @0x198e38 cmp r12, #0 */
/* @0x198e3c beq 0x198ec0 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x114> */
/* @0x198e40 ldr r7, [r12, #0x4] */
/* @0x198e44 cmp r7, #0 */
/* @0x198e48 blt 0x198f78 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x1cc> */
/* @0x198e4c ldr r1, [r12] */
/* @0x198e50 mov r4, #0 */
/* @0x198e54 ldr r0, [r12, #0x10] */
/* @0x198e58 mov r6, r4 */
/* @0x198e5c mov r9, #5 */
/* @0x198e60 add r3, r4, r4, lsl #1 */
/* @0x198e64 add r3, r0, r3, lsl #2 */
/* @0x198e68 b 0x198e78 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xcc> */
/* @0x198e6c ldr r2, [r5, #0x8] */
/* @0x198e70 cmp r2, #0 */
/* @0x198e74 bgt 0x198f18 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x16c> */
/* @0x198e78 add r4, r4, #1 */
/* @0x198e7c mov r5, r3 */
/* @0x198e80 cmp r4, r1 */
/* @0x198e84 add r3, r3, #12 */
/* @0x198e88 ble 0x198e6c <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xc0> */
/* @0x198e8c subs r7, r7, #1 */
/* @0x198e90 bhs 0x198e60 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xb4> */
/* @0x198e94 cmp r0, #0 */
/* @0x198e98 beq 0x198eb0 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x104> */
/* @0x198e9c str r12, [sp, #0x4] */
/* @0x198ea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x198ea4 ldr r12, [sp, #0x4] */
/* @0x198ea8 mov r3, #0 */
/* @0x198eac str r3, [r12, #0x10] */
/* @0x198eb0 mov r0, r12 */
/* @0x198eb4 bl 0x27d1d0 <_ZdlPv> */
/* @0x198eb8 mov r3, #0 */
/* @0x198ebc str r3, [r8, #0x60] */
/* @0x198ec0 ldr r0, [r8, #0x1c] */
/* @0x198ec4 cmp r0, #0 */
/* @0x198ec8 beq 0x198ee4 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x138> */
/* @0x198ecc ldr r3, [pc, #0xac] */
/* @0x198ed0 ldr r3, [pc, r3] */
/* @0x198ed4 ldr r3, [r3] */
/* @0x198ed8 blx r3 */
/* @0x198edc mov r3, #0 */
/* @0x198ee0 str r3, [r8, #0x1c] */
/* @0x198ee4 ldr r0, [r8, #0x20] */
/* @0x198ee8 cmp r0, #0 */
/* @0x198eec beq 0x198f08 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x15c> */
/* @0x198ef0 ldr r3, [pc, #0x8c] */
/* @0x198ef4 ldr r3, [pc, r3] */
/* @0x198ef8 ldr r3, [r3] */
/* @0x198efc blx r3 */
/* @0x198f00 mov r3, #0 */
/* @0x198f04 str r3, [r8, #0x20] */
/* @0x198f08 mov r3, #0 */
/* @0x198f0c str r3, [r8, #0x18] */
/* @0x198f10 add sp, sp, #12 */
/* @0x198f14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x198f18 ldr r3, [r5, #0x4] */
/* @0x198f1c ldr r2, [r3, #0xc] */
/* @0x198f20 sub r2, r2, #1 */
/* @0x198f24 bic r2, r2, #-16777216 */
/* @0x198f28 bic r2, r2, #3 */
/* @0x198f2c cmp r2, #0 */
/* @0x198f30 bne 0x198f44 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x198> */
/* @0x198f34 mov r0, r3 */
/* @0x198f38 str r3, [sp, #0x4] */
/* @0x198f3c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x198f40 ldr r3, [sp, #0x4] */
/* @0x198f44 str r6, [r3] */
/* @0x198f48 mov r1, r10 */
/* @0x198f4c ldr r0, [r5, #0x4] */
/* @0x198f50 mov r2, r11 */
/* @0x198f54 str r6, [r3, #0x8] */
/* @0x198f58 str r9, [r3, #0xc] */
/* @0x198f5c bl 0x190e84 <_Z10FreeRValueP6RValuePS0_S1_> */
/* @0x198f60 ldr r12, [r8, #0x60] */
/* @0x198f64 ldr r1, [r12] */
/* @0x198f68 ldr r0, [r12, #0x10] */
/* @0x198f6c b 0x198e60 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xb4> */
/* @0x198f70 mov r0, r4 */
/* @0x198f74 b 0x198e20 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x74> */
/* @0x198f78 ldr r0, [r12, #0x10] */
/* @0x198f7c b 0x198e94 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xe8> */
/* @0x198f80 .word 0x002577b8 */
/* @0x198f84 mlaeq r5, r4, r7, r7 */

/* ── FUNC 0x198f88 · YYObjectBase::Free(YYObjectBase*) · size=392 · insn=98 */
/* @0x198f88 ldr r2, [r0, #0x48] */
/* @0x198f8c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x198f90 cmp r2, #3 */
/* @0x198f94 ldr r7, [pc, #0x160] */
/* @0x198f98 sub sp, sp, #28 */
/* @0x198f9c mov r6, r0 */
/* @0x198fa0 ldr r3, [pc, #0x158] */
/* @0x198fa4 add r7, pc, r7 */
/* @0x198fa8 beq 0x1990b8 <_ZN12YYObjectBase4FreeEPS_+0x130> */
/* @0x198fac ldr r3, [r7, r3] */
/* @0x198fb0 mov r1, #0 */
/* @0x198fb4 ldr r12, [r0, #0x44] */
/* @0x198fb8 mvn lr, #0 */
/* @0x198fbc ldr r5, [r3, #0xc] */
/* @0x198fc0 ldr r8, [r3] */
/* @0x198fc4 ldr r4, [r3, #0x8] */
/* @0x198fc8 str r1, [r8, r12, lsl #2] */
/* @0x198fcc cmp r5, r12 */
/* @0x198fd0 strle r5, [r3, #0xc] */
/* @0x198fd4 strgt r12, [r3, #0xc] */
/* @0x198fd8 cmp r2, r1 */
/* @0x198fdc str r1, [r0, #0x38] */
/* @0x198fe0 add r2, r4, lr */
/* @0x198fe4 str lr, [r0, #0x44] */
/* @0x198fe8 str r2, [r3, #0x8] */
/* @0x198fec beq 0x199034 <_ZN12YYObjectBase4FreeEPS_+0xac> */
/* @0x198ff0 mov r4, #0 */
/* @0x198ff4 mov r0, r6 */
/* @0x198ff8 str r4, [r6, #0x40] */
/* @0x198ffc mov r2, r4 */
/* @0x199000 str r4, [r6, #0x18] */
/* @0x199004 mov r3, r4 */
/* @0x199008 mov r1, r4 */
/* @0x19900c str r4, [sp] */
/* @0x199010 bl 0x198dac <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_> */
/* @0x199014 ldr r3, [pc, #0xe8] */
/* @0x199018 ldr r3, [r7, r3] */
/* @0x19901c str r4, [r6, #0xc] */
/* @0x199020 ldr r2, [r3] */
/* @0x199024 str r6, [r3] */
/* @0x199028 str r2, [r6, #0x8] */
/* @0x19902c add sp, sp, #28 */
/* @0x199030 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x199034 ldr r8, [r0, #0x4] */
/* @0x199038 cmp r8, r1 */
/* @0x19903c bne 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68> */
/* @0x199040 ldr r3, [pc, #0xc0] */
/* @0x199044 ldr r3, [r7, r3] */
/* @0x199048 ldrb r3, [r3] */
/* @0x19904c cmp r3, r1 */
/* @0x199050 beq 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68> */
/* @0x199054 add r9, sp, #8 */
/* @0x199058 ldr r2, [pc, #0xac] */
/* @0x19905c mov r4, #0 */
/* @0x199060 str r8, [sp, #0x10] */
/* @0x199064 add r2, pc, r2 */
/* @0x199068 mov r1, r9 */
/* @0x19906c mov r5, #0 */
/* @0x199070 strd r4, r5, [sp, #8] */
/* @0x199074 mvn r4, #-16777216 */
/* @0x199078 str r4, [sp, #0x14] */
/* @0x19907c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x199080 ldr r3, [sp, #0x14] */
/* @0x199084 cmp r3, r4 */
/* @0x199088 beq 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68> */
/* @0x19908c mov r0, r9 */
/* @0x199090 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x199094 cmp r0, #0 */
/* @0x199098 beq 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68> */
/* @0x19909c mov r1, r8 */
/* @0x1990a0 str r8, [sp] */
/* @0x1990a4 mov r2, r9 */
/* @0x1990a8 mov r3, r8 */
/* @0x1990ac mov r0, r6 */
/* @0x1990b0 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x1990b4 b 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68> */
/* @0x1990b8 ldr r3, [r7, r3] */
/* @0x1990bc mov r4, #0 */
/* @0x1990c0 ldr r2, [r0, #0x44] */
/* @0x1990c4 ldr r1, [r3] */
/* @0x1990c8 ldr lr, [r3, #0xc] */
/* @0x1990cc ldr r12, [r3, #0x8] */
/* @0x1990d0 str r4, [r1, r2, lsl #2] */
/* @0x1990d4 ldr r1, [r0] */
/* @0x1990d8 sub r12, r12, #1 */
/* @0x1990dc cmp lr, r2 */
/* @0x1990e0 strle lr, [r3, #0xc] */
/* @0x1990e4 strgt r2, [r3, #0xc] */
/* @0x1990e8 str r12, [r3, #0x8] */
/* @0x1990ec ldr r3, [r1, #0x4] */
/* @0x1990f0 blx r3 */
/* @0x1990f4 add sp, sp, #28 */
/* @0x1990f8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1990fc eoreq r8, r5, r12, lsr #25 */
/* @0x199100 .word 0xffffc014 */
/* @0x199104 .word 0xffffbfc0 */
/* @0x199108 .word 0xffffc04c */
/* @0x19910c andseq r9, r9, r8, asr #14 */

/* ── FUNC 0x199110 · YYObjectBase::~YYObjectBase() · size=500 · insn=125 */
/* @0x199110 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x199114 mov r6, r0 */
/* @0x199118 ldr r9, [pc, #0x1d4] */
/* @0x19911c ldr r3, [pc, #0x1d4] */
/* @0x199120 add r9, pc, r9 */
/* @0x199124 ldr r10, [r0, #0x60] */
/* @0x199128 ldr r3, [r9, r3] */
/* @0x19912c cmp r10, #0 */
/* @0x199130 add r3, r3, #8 */
/* @0x199134 str r3, [r0] */
/* @0x199138 beq 0x1991a0 <_ZN12YYObjectBaseD2Ev+0x90> */
/* @0x19913c mov r4, #0 */
/* @0x199140 mov r8, #5 */
/* @0x199144 mov r7, r4 */
/* @0x199148 ldr r0, [r10, #0x10] */
/* @0x19914c add r3, r4, r4, lsl #1 */
/* @0x199150 ldr r1, [r10] */
/* @0x199154 add r3, r0, r3, lsl #2 */
/* @0x199158 b 0x199168 <_ZN12YYObjectBaseD2Ev+0x58> */
/* @0x19915c ldr r2, [r5, #0x8] */
/* @0x199160 cmp r2, #0 */
/* @0x199164 bgt 0x1991fc <_ZN12YYObjectBaseD2Ev+0xec> */
/* @0x199168 add r4, r4, #1 */
/* @0x19916c mov r5, r3 */
/* @0x199170 cmp r1, r4 */
/* @0x199174 add r3, r3, #12 */
/* @0x199178 bge 0x19915c <_ZN12YYObjectBaseD2Ev+0x4c> */
/* @0x19917c cmp r0, #0 */
/* @0x199180 beq 0x199190 <_ZN12YYObjectBaseD2Ev+0x80> */
/* @0x199184 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x199188 mov r3, #0 */
/* @0x19918c str r3, [r10, #0x10] */
/* @0x199190 mov r0, r10 */
/* @0x199194 bl 0x27d1d0 <_ZdlPv> */
/* @0x199198 mov r3, #0 */
/* @0x19919c str r3, [r6, #0x60] */
/* @0x1991a0 ldr r4, [r6, #0x4] */
/* @0x1991a4 cmp r4, #0 */
/* @0x1991a8 beq 0x199254 <_ZN12YYObjectBaseD2Ev+0x144> */
/* @0x1991ac ldr r5, [r6, #0x24] */
/* @0x1991b0 cmp r5, #0 */
/* @0x1991b4 ble 0x1992ec <_ZN12YYObjectBaseD2Ev+0x1dc> */
/* @0x1991b8 mov r7, #0 */
/* @0x1991bc mov r8, #5 */
/* @0x1991c0 b 0x1991d8 <_ZN12YYObjectBaseD2Ev+0xc8> */
/* @0x1991c4 subs r5, r5, #1 */
/* @0x1991c8 str r7, [r4, #0x8] */
/* @0x1991cc str r8, [r4, #0xc] */
/* @0x1991d0 str r7, [r4], #16 */
/* @0x1991d4 beq 0x199244 <_ZN12YYObjectBaseD2Ev+0x134> */
/* @0x1991d8 ldr r3, [r4, #0xc] */
/* @0x1991dc sub r3, r3, #1 */
/* @0x1991e0 bic r3, r3, #-16777216 */
/* @0x1991e4 bic r3, r3, #3 */
/* @0x1991e8 cmp r3, #0 */
/* @0x1991ec bne 0x1991c4 <_ZN12YYObjectBaseD2Ev+0xb4> */
/* @0x1991f0 mov r0, r4 */
/* @0x1991f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1991f8 b 0x1991c4 <_ZN12YYObjectBaseD2Ev+0xb4> */
/* @0x1991fc ldr r10, [r5, #0x4] */
/* @0x199200 ldr r3, [r10, #0xc] */
/* @0x199204 sub r3, r3, #1 */
/* @0x199208 bic r3, r3, #-16777216 */
/* @0x19920c bic r3, r3, #3 */
/* @0x199210 cmp r3, #0 */
/* @0x199214 bne 0x199220 <_ZN12YYObjectBaseD2Ev+0x110> */
/* @0x199218 mov r0, r10 */
/* @0x19921c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x199220 mov r1, #0 */
/* @0x199224 str r7, [r10] */
/* @0x199228 str r7, [r10, #0x8] */
/* @0x19922c mov r2, r1 */
/* @0x199230 ldr r0, [r5, #0x4] */
/* @0x199234 str r8, [r10, #0xc] */
/* @0x199238 bl 0x190e84 <_Z10FreeRValueP6RValuePS0_S1_> */
/* @0x19923c ldr r10, [r6, #0x60] */
/* @0x199240 b 0x199148 <_ZN12YYObjectBaseD2Ev+0x38> */
/* @0x199244 ldr r0, [r6, #0x4] */
/* @0x199248 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19924c mov r3, #0 */
/* @0x199250 str r3, [r6, #0x4] */
/* @0x199254 ldr r0, [r6, #0x1c] */
/* @0x199258 mov r4, #0 */
/* @0x19925c str r4, [r6, #0x18] */
/* @0x199260 cmp r0, r4 */
/* @0x199264 str r4, [r6, #0x24] */
/* @0x199268 beq 0x199280 <_ZN12YYObjectBaseD2Ev+0x170> */
/* @0x19926c ldr r3, [pc, #0x88] */
/* @0x199270 ldr r3, [r9, r3] */
/* @0x199274 ldr r3, [r3] */
/* @0x199278 blx r3 */
/* @0x19927c str r4, [r6, #0x1c] */
/* @0x199280 ldr r0, [r6, #0x20] */
/* @0x199284 cmp r0, #0 */
/* @0x199288 beq 0x1992a4 <_ZN12YYObjectBaseD2Ev+0x194> */
/* @0x19928c ldr r3, [pc, #0x68] */
/* @0x199290 ldr r3, [r9, r3] */
/* @0x199294 ldr r3, [r3] */
/* @0x199298 blx r3 */
/* @0x19929c mov r3, #0 */
/* @0x1992a0 str r3, [r6, #0x20] */
/* @0x1992a4 ldr r0, [r6, #0x10] */
/* @0x1992a8 cmp r0, #0 */
/* @0x1992ac beq 0x1992bc <_ZN12YYObjectBaseD2Ev+0x1ac> */
/* @0x1992b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1992b4 mov r3, #0 */
/* @0x1992b8 str r3, [r6, #0x10] */
/* @0x1992bc ldr r0, [r6, #0x14] */
/* @0x1992c0 cmp r0, #0 */
/* @0x1992c4 beq 0x1992d4 <_ZN12YYObjectBaseD2Ev+0x1c4> */
/* @0x1992c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1992cc mov r3, #0 */
/* @0x1992d0 str r3, [r6, #0x14] */
/* @0x1992d4 ldr r3, [pc, #0x24] */
/* @0x1992d8 mov r0, r6 */
/* @0x1992dc ldr r3, [r9, r3] */
/* @0x1992e0 add r3, r3, #8 */
/* @0x1992e4 str r3, [r6] */
/* @0x1992e8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1992ec mov r0, r4 */
/* @0x1992f0 b 0x199248 <_ZN12YYObjectBaseD2Ev+0x138> */
/* @0x1992f4 eoreq r8, r5, r0, lsr r11 */
/* @0x1992f8 .word 0xffffea28 */
/* @0x1992fc .word 0xffffea38 */
/* @0x199300 .word 0xffffea1c */

/* ── FUNC 0x199110 · YYObjectBase::~YYObjectBase() · alias of the symbol above · insn=0 */

/* ── FUNC 0x199304 · YYObjectBase::~YYObjectBase() · size=28 · insn=7 */
/* @0x199304 push {r4, lr} */
/* @0x199308 mov r4, r0 */
/* @0x19930c bl 0x199110 <_ZN12YYObjectBaseD2Ev> */
/* @0x199310 mov r0, r4 */
/* @0x199314 bl 0x27d1d0 <_ZdlPv> */
/* @0x199318 mov r0, r4 */
/* @0x19931c pop {r4, pc} */

/* ── FUNC 0x199320 · CInstance::~CInstance() · size=216 · insn=54 */
/* @0x199320 push {r4, r5, r6, lr} */
/* @0x199324 mov r4, r0 */
/* @0x199328 ldr r5, [r0, #0x84] */
/* @0x19932c ldr r3, [pc, #0xbc] */
/* @0x199330 cmp r5, #0 */
/* @0x199334 ldr r3, [pc, r3] */
/* @0x199338 add r3, r3, #8 */
/* @0x19933c str r3, [r0] */
/* @0x199340 beq 0x19935c <_ZN9CInstanceD2Ev+0x3c> */
/* @0x199344 mov r0, r5 */
/* @0x199348 bl 0x236c60 <_ZN14CPhysicsObjectD2Ev> */
/* @0x19934c mov r0, r5 */
/* @0x199350 bl 0x27d1d0 <_ZdlPv> */
/* @0x199354 mov r3, #0 */
/* @0x199358 str r3, [r4, #0x84] */
/* @0x19935c ldr r0, [r4, #0x80] */
/* @0x199360 cmp r0, #0 */
/* @0x199364 beq 0x199378 <_ZN9CInstanceD2Ev+0x58> */
/* @0x199368 mov r1, r4 */
/* @0x19936c bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> */
/* @0x199370 mov r3, #0 */
/* @0x199374 str r3, [r4, #0x80] */
/* @0x199378 ldr r5, [r4, #0x88] */
/* @0x19937c cmp r5, #0 */
/* @0x199380 beq 0x19939c <_ZN9CInstanceD2Ev+0x7c> */
/* @0x199384 mov r0, r5 */
/* @0x199388 bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> */
/* @0x19938c mov r0, r5 */
/* @0x199390 bl 0x27d1d0 <_ZdlPv> */
/* @0x199394 mov r3, #0 */
/* @0x199398 str r3, [r4, #0x88] */
/* @0x19939c ldr r3, [pc, #0x50] */
/* @0x1993a0 mvn lr, #0 */
/* @0x1993a4 ldr r2, [r4, #0x44] */
/* @0x1993a8 mov r0, r4 */
/* @0x1993ac ldr r3, [pc, r3] */
/* @0x1993b0 mov r6, #0 */
/* @0x1993b4 ldr r5, [r3] */
/* @0x1993b8 ldr r12, [r3, #0xc] */
/* @0x1993bc ldr r1, [r3, #0x8] */
/* @0x1993c0 str r6, [r5, r2, lsl #2] */
/* @0x1993c4 str lr, [r4, #0x44] */
/* @0x1993c8 add r1, r1, lr */
/* @0x1993cc cmp r12, r2 */
/* @0x1993d0 strle r12, [r3, #0xc] */
/* @0x1993d4 strgt r2, [r3, #0xc] */
/* @0x1993d8 str r1, [r3, #0x8] */
/* @0x1993dc bl 0x1cd9f0 <_Z15CollisionRemoveP9CInstance> */
/* @0x1993e0 mov r0, r4 */
/* @0x1993e4 bl 0x199110 <_ZN12YYObjectBaseD2Ev> */
/* @0x1993e8 mov r0, r4 */
/* @0x1993ec pop {r4, r5, r6, pc} */
/* @0x1993f0 eoreq r7, r5, r8, asr r3 */
/* @0x1993f4 .word 0x002548b8 */

/* ── FUNC 0x199320 · CInstance::~CInstance() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1993f8 · CInstance::~CInstance() · size=28 · insn=7 */
/* @0x1993f8 push {r4, lr} */
/* @0x1993fc mov r4, r0 */
/* @0x199400 bl 0x199320 <_ZN9CInstanceD2Ev> */
/* @0x199404 mov r0, r4 */
/* @0x199408 bl 0x27d1d0 <_ZdlPv> */
/* @0x19940c mov r0, r4 */
/* @0x199410 pop {r4, pc} */

/* ── FUNC 0x199414 · CScriptRef::~CScriptRef() · size=40 · insn=10 */
/* @0x199414 ldr r3, [pc, #0x1c] */
/* @0x199418 push {r4, lr} */
/* @0x19941c ldr r3, [pc, r3] */
/* @0x199420 mov r4, r0 */
/* @0x199424 add r3, r3, #8 */
/* @0x199428 str r3, [r0] */
/* @0x19942c bl 0x199110 <_ZN12YYObjectBaseD2Ev> */
/* @0x199430 mov r0, r4 */
/* @0x199434 pop {r4, pc} */
/* @0x199438 eoreq r7, r5, r0, ror #4 */

/* ── FUNC 0x199414 · CScriptRef::~CScriptRef() · alias of the symbol above · insn=0 */

/* ── FUNC 0x19943c · CScriptRef::~CScriptRef() · size=48 · insn=12 */
/* @0x19943c ldr r3, [pc, #0x24] */
/* @0x199440 push {r4, lr} */
/* @0x199444 ldr r3, [pc, r3] */
/* @0x199448 mov r4, r0 */
/* @0x19944c add r3, r3, #8 */
/* @0x199450 str r3, [r0] */
/* @0x199454 bl 0x199110 <_ZN12YYObjectBaseD2Ev> */
/* @0x199458 mov r0, r4 */
/* @0x19945c bl 0x27d1d0 <_ZdlPv> */
/* @0x199460 mov r0, r4 */
/* @0x199464 pop {r4, pc} */
/* @0x199468 eoreq r7, r5, r8, lsr r2 */

/* ── FUNC 0x19946c · YYObjectBase::Add(char const*, YYObjectBase*, int) · size=112 · insn=28 */
/* @0x19946c push {r3, r4, r5, r6, r7, lr} */
/* @0x199470 mov r4, r1 */
/* @0x199474 mov r5, r2 */
/* @0x199478 mov r7, r3 */
/* @0x19947c mov r6, r0 */
/* @0x199480 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x199484 cmp r0, #0 */
/* @0x199488 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x19948c mov r1, r4 */
/* @0x199490 mov r0, r6 */
/* @0x199494 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x199498 ldr r3, [r0, #0xc] */
/* @0x19949c mov r4, r0 */
/* @0x1994a0 sub r3, r3, #1 */
/* @0x1994a4 bic r3, r3, #-16777216 */
/* @0x1994a8 bic r3, r3, #3 */
/* @0x1994ac cmp r3, #0 */
/* @0x1994b0 beq 0x1994d4 <_ZN12YYObjectBase3AddEPKcPS_i+0x68> */
/* @0x1994b4 mov r3, #6 */
/* @0x1994b8 str r5, [r4] */
/* @0x1994bc mov r0, r6 */
/* @0x1994c0 str r7, [r4, #0x8] */
/* @0x1994c4 mov r1, r5 */
/* @0x1994c8 str r3, [r4, #0xc] */
/* @0x1994cc pop {r3, r4, r5, r6, r7, lr} */
/* @0x1994d0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1994d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1994d8 b 0x1994b4 <_ZN12YYObjectBase3AddEPKcPS_i+0x48> */

/* ── FUNC 0x1994dc · CInstance::CInstance(float, float, int, int, bool) · size=1028 · insn=257 */
/* @0x1994dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1994e0 mov r11, r1 */
/* @0x1994e4 ldr r8, [pc, #0x3d4] */
/* @0x1994e8 sub sp, sp, #12 */
/* @0x1994ec ldr r1, [pc, #0x3d0] */
/* @0x1994f0 mov r10, r3 */
/* @0x1994f4 add r8, pc, r8 */
/* @0x1994f8 ldrb r3, [sp, #0x34] */
/* @0x1994fc mov r9, r2 */
/* @0x199500 mvn r2, #-16777216 */
/* @0x199504 ldr r1, [r8, r1] */
/* @0x199508 mov r6, r0 */
/* @0x19950c ldr r5, [pc, #0x3b4] */
/* @0x199510 mvn r4, #0 */
/* @0x199514 mov r7, #12 */
/* @0x199518 ldr r1, [r1] */
/* @0x19951c str r3, [sp, #0x4] */
/* @0x199520 bl 0x19188c <_ZN12YYObjectBaseC2Eii> */
/* @0x199524 ldr r1, [pc, #0x3a0] */
/* @0x199528 mov lr, #0 */
/* @0x19952c add r2, r6, #396 */
/* @0x199530 ldr r0, [r8, r1] */
/* @0x199534 add r1, r6, #408 */
/* @0x199538 str r4, [r6, #0x188] */
/* @0x19953c add r4, r6, #420 */
/* @0x199540 str r2, [r6, #0x18c] */
/* @0x199544 add r0, r0, #8 */
/* @0x199548 str r2, [r6, #0x190] */
/* @0x19954c mov r2, r6 */
/* @0x199550 str r0, [r6] */
/* @0x199554 mov r0, lr */
/* @0x199558 str r1, [r6, #0x198] */
/* @0x19955c str r1, [r6, #0x19c] */
/* @0x199560 mov r1, #0 */
/* @0x199564 str lr, [r6, #0x194] */
/* @0x199568 str lr, [r6, #0x1a0] */
/* @0x19956c str lr, [r6, #0x1ac] */
/* @0x199570 str r4, [r6, #0x1a4] */
/* @0x199574 str r4, [r6, #0x1a8] */
/* @0x199578 ldr r4, [r8, r5] */
/* @0x19957c str r1, [r6, #0xb4] */
/* @0x199580 str lr, [r6, #0x78] */
/* @0x199584 ldrd r4, r5, [r4] */
/* @0x199588 str r1, [r6, #0xb8] */
/* @0x19958c strb lr, [r6, #0x6b] */
/* @0x199590 str r1, [r6, #0x180] */
/* @0x199594 str r1, [r6, #0x184] */
/* @0x199598 strb lr, [r6, #0x6c] */
/* @0x19959c str r1, [r6, #0x90] */
/* @0x1995a0 strb lr, [r6, #0x6a] */
/* @0x1995a4 str r1, [r6, #0x94] */
/* @0x1995a8 str lr, [r6, #0xa8] */
/* @0x1995ac str r1, [r6, #0x98] */
/* @0x1995b0 strd r4, r5, [r6, #112] */
/* @0x1995b4 str r1, [r6, #0x9c] */
/* @0x1995b8 str r1, [r6, #0xa0] */
/* @0x1995bc str r1, [r6, #0xa4] */
/* @0x1995c0 str r1, [r6, #0xbc] */
/* @0x1995c4 str r1, [r6, #0xc0] */
/* @0x1995c8 str r1, [r6, #0xc4] */
/* @0x1995cc str r1, [r6, #0xc8] */
/* @0x1995d0 ldr r3, [sp, #0x4] */
/* @0x1995d4 str r1, [r6, #0xcc] */
/* @0x1995d8 str r1, [r6, #0xd0] */
/* @0x1995dc str r1, [r6, #0xe0] */
/* @0x1995e0 str r1, [r6, #0xe4] */
/* @0x1995e4 str r1, [r6, #0xd4] */
/* @0x1995e8 str r1, [r6, #0xd8] */
/* @0x1995ec str r1, [r6, #0xdc] */
/* @0x1995f0 subs r7, r7, #1 */
/* @0x1995f4 str r0, [r2, #0xf8] */
/* @0x1995f8 add r2, r2, #4 */
/* @0x1995fc bne 0x1995f0 <_ZN9CInstanceC2Effiib+0x114> */
/* @0x199600 mov r4, #0 */
/* @0x199604 mov r2, r3 */
/* @0x199608 ldr r1, [sp, #0x30] */
/* @0x19960c mov r0, r6 */
/* @0x199610 strb r7, [r6, #0x68] */
/* @0x199614 strb r7, [r6, #0x69] */
/* @0x199618 str r7, [r6, #0x160] */
/* @0x19961c str r7, [r6, #0x164] */
/* @0x199620 str r4, [r6, #0x12c] */
/* @0x199624 str r7, [r6, #0x128] */
/* @0x199628 str r4, [r6, #0x130] */
/* @0x19962c str r7, [r6, #0x140] */
/* @0x199630 str r4, [r6, #0x134] */
/* @0x199634 str r7, [r6, #0x14c] */
/* @0x199638 str r4, [r6, #0x138] */
/* @0x19963c strb r7, [r6, #0x15c] */
/* @0x199640 str r4, [r6, #0x13c] */
/* @0x199644 strb r7, [r6, #0x15d] */
/* @0x199648 str r4, [r6, #0x150] */
/* @0x19964c str r7, [r6, #0x80] */
/* @0x199650 str r4, [r6, #0x154] */
/* @0x199654 str r7, [r6, #0x84] */
/* @0x199658 str r4, [r6, #0x158] */
/* @0x19965c str r7, [r6, #0x88] */
/* @0x199660 bl 0x19324c <_ZN9CInstance14SetObjectIndexEib> */
/* @0x199664 mov r3, r6 */
/* @0x199668 mvn r1, #0 */
/* @0x19966c mov r2, #1065353216 */
/* @0x199670 mov r0, #0 */
/* @0x199674 str r2, [r6, #0x94] */
/* @0x199678 str r2, [r6, #0x98] */
/* @0x19967c movt r0, #0x4387 */
/* @0x199680 str r2, [r6, #0x9c] */
/* @0x199684 str r2, [r6, #0xa4] */
/* @0x199688 mvn r2, #-16777216 */
/* @0x19968c str r4, [r6, #0x90] */
/* @0x199690 str r4, [r6, #0xa0] */
/* @0x199694 str r4, [r6, #0xcc] */
/* @0x199698 str r4, [r6, #0xd0] */
/* @0x19969c str r4, [r6, #0xe0] */
/* @0x1996a0 str r4, [r6, #0xe4] */
/* @0x1996a4 str r4, [r6, #0xd4] */
/* @0x1996a8 str r4, [r6, #0xdc] */
/* @0x1996ac str r11, [r6, #0xb4] */
/* @0x1996b0 str r9, [r6, #0xb8] */
/* @0x1996b4 str r10, [r6, #0x78] */
/* @0x1996b8 str r11, [r6, #0xbc] */
/* @0x1996bc str r9, [r6, #0xc0] */
/* @0x1996c0 str r11, [r6, #0xc4] */
/* @0x1996c4 str r9, [r6, #0xc8] */
/* @0x1996c8 str r2, [r6, #0xa8] */
/* @0x1996cc str r0, [r6, #0xd8] */
/* @0x1996d0 add r7, r7, #1 */
/* @0x1996d4 str r1, [r3, #0xf8] */
/* @0x1996d8 cmp r7, #12 */
/* @0x1996dc add r3, r3, #4 */
/* @0x1996e0 mvn r2, #0 */
/* @0x1996e4 bne 0x1996d0 <_ZN9CInstanceC2Effiib+0x1f4> */
/* @0x1996e8 ldr r0, [pc, #0x1e0] */
/* @0x1996ec mov r4, #0 */
/* @0x1996f0 mov r3, #0 */
/* @0x1996f4 mov r1, #1065353216 */
/* @0x1996f8 str r3, [r6, #0x12c] */
/* @0x1996fc str r3, [r6, #0x130] */
/* @0x199700 str r3, [r6, #0x134] */
/* @0x199704 str r3, [r6, #0x13c] */
/* @0x199708 str r3, [r6, #0x150] */
/* @0x19970c str r3, [r6, #0x154] */
/* @0x199710 mov r3, #2 */
/* @0x199714 str r2, [r6, #0x128] */
/* @0x199718 str r2, [r6, #0x14c] */
/* @0x19971c str r2, [r6, #0x170] */
/* @0x199720 str r4, [r6, #0xf4] */
/* @0x199724 str r4, [r6, #0xe8] */
/* @0x199728 str r4, [r6, #0xf0] */
/* @0x19972c str r4, [r6, #0xec] */
/* @0x199730 strb r4, [r6, #0x68] */
/* @0x199734 strb r4, [r6, #0x69] */
/* @0x199738 str r1, [r6, #0x138] */
/* @0x19973c str r1, [r6, #0x158] */
/* @0x199740 str r4, [r6, #0x140] */
/* @0x199744 str r4, [r6, #0x160] */
/* @0x199748 str r4, [r6, #0x164] */
/* @0x19974c str r4, [r6, #0x168] */
/* @0x199750 strb r4, [r6, #0x15e] */
/* @0x199754 strb r4, [r6, #0x174] */
/* @0x199758 str r3, [r6, #0x16c] */
/* @0x19975c ldr r5, [r8, r0] */
/* @0x199760 ldr r7, [r5, #0x8] */
/* @0x199764 ldr r12, [r5, #0x4] */
/* @0x199768 cmp r7, r12 */
/* @0x19976c bge 0x19987c <_ZN9CInstanceC2Effiib+0x3a0> */
/* @0x199770 cmp r12, #0 */
/* @0x199774 ldr r3, [r5, #0xc] */
/* @0x199778 ble 0x1997c0 <_ZN9CInstanceC2Effiib+0x2e4> */
/* @0x19977c ldr r0, [r5] */
/* @0x199780 mov r1, r12 */
/* @0x199784 b 0x199794 <_ZN9CInstanceC2Effiib+0x2b8> */
/* @0x199788 subs r1, r1, #1 */
/* @0x19978c add r3, r3, #1 */
/* @0x199790 beq 0x1997c0 <_ZN9CInstanceC2Effiib+0x2e4> */
/* @0x199794 cmp r12, r3 */
/* @0x199798 lsl r2, r3, #2 */
/* @0x19979c movle r3, #0 */
/* @0x1997a0 movle r2, r3 */
/* @0x1997a4 add r4, r0, r2 */
/* @0x1997a8 ldr r2, [r0, r2] */
/* @0x1997ac cmp r2, #0 */
/* @0x1997b0 bne 0x199788 <_ZN9CInstanceC2Effiib+0x2ac> */
/* @0x1997b4 str r6, [r4] */
/* @0x1997b8 str r3, [r5, #0xc] */
/* @0x1997bc b 0x1997c4 <_ZN9CInstanceC2Effiib+0x2e8> */
/* @0x1997c0 mvn r3, #0 */
/* @0x1997c4 ldr r2, [pc, #0x108] */
/* @0x1997c8 add r7, r7, #1 */
/* @0x1997cc str r3, [r6, #0x44] */
/* @0x1997d0 str r7, [r5, #0x8] */
/* @0x1997d4 ldr r3, [r8, r2] */
/* @0x1997d8 ldrb r3, [r3] */
/* @0x1997dc cmp r3, #0 */
/* @0x1997e0 beq 0x19985c <_ZN9CInstanceC2Effiib+0x380> */
/* @0x1997e4 ldr r3, [pc, #0xec] */
/* @0x1997e8 ldr r7, [r8, r3] */
/* @0x1997ec ldr r3, [r7] */
/* @0x1997f0 cmp r3, #0 */
/* @0x1997f4 ble 0x19985c <_ZN9CInstanceC2Effiib+0x380> */
/* @0x1997f8 ldr r3, [pc, #0xdc] */
/* @0x1997fc mov r5, #0 */
/* @0x199800 ldr r4, [r8, r3] */
/* @0x199804 add r4, r4, #8 */
/* @0x199808 b 0x19981c <_ZN9CInstanceC2Effiib+0x340> */
/* @0x19980c ldr r3, [r7] */
/* @0x199810 add r4, r4, #16 */
/* @0x199814 cmp r3, r5 */
/* @0x199818 ble 0x19985c <_ZN9CInstanceC2Effiib+0x380> */
/* @0x19981c ldr r0, [r4, #-0x8] */
/* @0x199820 add r5, r5, #1 */
/* @0x199824 bl 0x23f8f0 <_Z18isGlobalBuiltinVarPKc> */
/* @0x199828 cmp r0, #0 */
/* @0x19982c bne 0x19980c <_ZN9CInstanceC2Effiib+0x330> */
/* @0x199830 ldmda r4, {r0, r1} */
/* @0x199834 add r4, r4, #16 */
/* @0x199838 bl 0x23ffac <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_> */
/* @0x19983c ldr r1, [r4, #-0x18] */
/* @0x199840 mov r3, #1 */
/* @0x199844 mov r2, r0 */
/* @0x199848 mov r0, r6 */
/* @0x19984c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x199850 ldr r3, [r7] */
/* @0x199854 cmp r3, r5 */
/* @0x199858 bgt 0x19981c <_ZN9CInstanceC2Effiib+0x340> */
/* @0x19985c mov r3, #0 */
/* @0x199860 mov r2, #1 */
/* @0x199864 mov r0, r6 */
/* @0x199868 str r2, [r6, #0x48] */
/* @0x19986c str r3, [r6, #0x10] */
/* @0x199870 str r3, [r6, #0x14] */
/* @0x199874 add sp, sp, #12 */
/* @0x199878 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19987c add r12, r12, r12, lsl #1 */
/* @0x199880 ldr r0, [r5] */
/* @0x199884 add r12, r12, r12, lsr #31 */
/* @0x199888 asr r7, r12, #1 */
/* @0x19988c lsl r1, r7, #2 */
/* @0x199890 bl 0xcef64 <_Z9YYReallocPvi> */
/* @0x199894 ldr r3, [r5, #0x4] */
/* @0x199898 mov r1, r4 */
/* @0x19989c rsb r2, r3, r7 */
/* @0x1998a0 lsl r2, r2, #2 */
/* @0x1998a4 str r0, [r5] */
/* @0x1998a8 add r0, r0, r3, lsl #2 */
/* @0x1998ac bl 0xb65b0 <memset@plt> */
/* @0x1998b0 str r7, [r5, #0x4] */
/* @0x1998b4 mov r12, r7 */
/* @0x1998b8 ldr r7, [r5, #0x8] */
/* @0x1998bc b 0x199770 <_ZN9CInstanceC2Effiib+0x294> */
/* @0x1998c0 eoreq r8, r5, r12, asr r7 */
/* @0x1998c4 .word 0xffffc0c4 */
/* @0x1998c8 .word 0xffffdeb4 */
/* @0x1998cc .word 0xffffea3c */
/* @0x1998d0 .word 0xffffc014 */
/* @0x1998d4 .word 0xffffbf68 */
/* @0x1998d8 .word 0xffffbfe4 */
/* @0x1998dc .word 0xffffbfe8 */

/* ── FUNC 0x1994dc · CInstance::CInstance(float, float, int, int, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1998e0 · YYObjectBase::Add(char const*, bool, int) · size=128 · insn=32 */
/* @0x1998e0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1998e4 mov r4, r1 */
/* @0x1998e8 mov r5, r2 */
/* @0x1998ec mov r6, r3 */
/* @0x1998f0 mov r7, r0 */
/* @0x1998f4 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x1998f8 cmp r0, #0 */
/* @0x1998fc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x199900 mov r1, r4 */
/* @0x199904 mov r0, r7 */
/* @0x199908 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x19990c ldr r3, [r0, #0xc] */
/* @0x199910 mov r4, r0 */
/* @0x199914 sub r3, r3, #1 */
/* @0x199918 bic r3, r3, #-16777216 */
/* @0x19991c bic r3, r3, #3 */
/* @0x199920 cmp r3, #0 */
/* @0x199924 beq 0x199958 <_ZN12YYObjectBase3AddEPKcbi+0x78> */
/* @0x199928 cmp r5, #0 */
/* @0x19992c mov r3, #0 */
/* @0x199930 str r3, [r4] */
/* @0x199934 movne r5, r3 */
/* @0x199938 moveq r2, r5 */
/* @0x19993c movne r2, r5 */
/* @0x199940 mov r3, #13 */
/* @0x199944 movtne r2, #0x3ff0 */
/* @0x199948 str r5, [r4] */
/* @0x19994c stmib r4, {r2, r6} */
/* @0x199950 str r3, [r4, #0xc] */
/* @0x199954 pop {r3, r4, r5, r6, r7, pc} */
/* @0x199958 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x19995c b 0x199928 <_ZN12YYObjectBase3AddEPKcbi+0x48> */

/* ── FUNC 0x199960 · YYObjectBase::Add(char const*, int, int) · size=112 · insn=28 */
/* @0x199960 push {r3, r4, r5, r6, r7, lr} */
/* @0x199964 mov r4, r1 */
/* @0x199968 mov r6, r2 */
/* @0x19996c mov r5, r3 */
/* @0x199970 mov r7, r0 */
/* @0x199974 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x199978 cmp r0, #0 */
/* @0x19997c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x199980 mov r1, r4 */
/* @0x199984 mov r0, r7 */
/* @0x199988 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x19998c ldr r3, [r0, #0xc] */
/* @0x199990 mov r4, r0 */
/* @0x199994 sub r3, r3, #1 */
/* @0x199998 bic r3, r3, #-16777216 */
/* @0x19999c bic r3, r3, #3 */
/* @0x1999a0 cmp r3, #0 */
/* @0x1999a4 beq 0x1999c8 <_ZN12YYObjectBase3AddEPKcii+0x68> */
/* @0x1999a8 vmov s15, r6 */
/* @0x1999ac mov r1, #0 */
/* @0x1999b0 str r5, [r4, #0x8] */
/* @0x1999b4 vcvt.f64.s32 d7, s15 */
/* @0x1999b8 str r1, [r4, #0xc] */
/* @0x1999bc vmov r2, r3, d7 */
/* @0x1999c0 stm r4, {r2, r3} */
/* @0x1999c4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1999c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1999cc b 0x1999a8 <_ZN12YYObjectBase3AddEPKcii+0x48> */
