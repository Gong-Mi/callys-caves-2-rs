/* libyoyo.so 覆盖卡组 0050
 * 函数 0x11cd18..0x11ea2c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x11cd18 · F_SkeletonAnimationSetFrame(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11cd18 mov r3, r0 */
/* @0x11cd1c mov r0, r1 */
/* @0x11cd20 push {r4, r5, r6, lr} */
/* @0x11cd24 mov r4, #0 */
/* @0x11cd28 str r4, [r3, #0xc] */
/* @0x11cd2c str r4, [r3] */
/* @0x11cd30 str r4, [r3, #0x4] */
/* @0x11cd34 ldr r5, [sp, #0x10] */
/* @0x11cd38 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cd3c subs r6, r0, #0 */
/* @0x11cd40 popeq {r4, r5, r6, pc} */
/* @0x11cd44 mov r1, r4 */
/* @0x11cd48 mov r0, r5 */
/* @0x11cd4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11cd50 mov r1, #1 */
/* @0x11cd54 mov r4, r0 */
/* @0x11cd58 mov r0, r5 */
/* @0x11cd5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11cd60 mov r1, r4 */
/* @0x11cd64 mov r2, r0 */
/* @0x11cd68 mov r0, r6 */
/* @0x11cd6c pop {r4, r5, r6, lr} */
/* @0x11cd70 b 0xbe3e8 <_ZN17CSkeletonInstance13SetImageIndexEif> */

/* ── FUNC 0x11cd74 · F_SkeletonGetNumBounds(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x11cd74 push {r4, lr} */
/* @0x11cd78 mov r4, r0 */
/* @0x11cd7c mov r3, #0 */
/* @0x11cd80 mov r0, r1 */
/* @0x11cd84 str r3, [r4, #0xc] */
/* @0x11cd88 str r3, [r4] */
/* @0x11cd8c str r3, [r4, #0x4] */
/* @0x11cd90 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cd94 cmp r0, #0 */
/* @0x11cd98 popeq {r4, pc} */
/* @0x11cd9c bl 0xbeedc <_ZN17CSkeletonInstance28GetNumBoundingBoxAttachmentsEv> */
/* @0x11cda0 vmov s15, r0 */
/* @0x11cda4 vcvt.f64.s32 d7, s15 */
/* @0x11cda8 vmov r0, r1, d7 */
/* @0x11cdac vmov r2, s14 */
/* @0x11cdb0 mov r3, r1 */
/* @0x11cdb4 stm r4, {r2, r3} */
/* @0x11cdb8 pop {r4, pc} */

/* ── FUNC 0x11cdbc · F_SkeletonAnimationMix(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x11cdbc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x11cdc0 mov r5, #0 */
/* @0x11cdc4 ldr r6, [sp, #0x20] */
/* @0x11cdc8 mov r7, r1 */
/* @0x11cdcc str r5, [r0, #0xc] */
/* @0x11cdd0 mov r1, r5 */
/* @0x11cdd4 str r5, [r0] */
/* @0x11cdd8 mov r4, r0 */
/* @0x11cddc mov r3, r5 */
/* @0x11cde0 movt r3, #0xbff0 */
/* @0x11cde4 str r3, [r0, #0x4] */
/* @0x11cde8 mov r0, r6 */
/* @0x11cdec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11cdf0 mov r1, #1 */
/* @0x11cdf4 mov r8, r0 */
/* @0x11cdf8 mov r0, r6 */
/* @0x11cdfc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11ce00 mov r1, #2 */
/* @0x11ce04 mov r9, r0 */
/* @0x11ce08 mov r0, r6 */
/* @0x11ce0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ce10 mov r6, r0 */
/* @0x11ce14 mov r0, r7 */
/* @0x11ce18 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11ce1c cmp r0, r5 */
/* @0x11ce20 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x11ce24 mov r3, r6 */
/* @0x11ce28 mov r1, r8 */
/* @0x11ce2c mov r2, r9 */
/* @0x11ce30 bl 0xbe580 <_ZN17CSkeletonInstance15SetAnimationMixEPKcS1_f> */
/* @0x11ce34 mov r3, r5 */
/* @0x11ce38 str r5, [r4] */
/* @0x11ce3c movt r3, #0x3ff0 */
/* @0x11ce40 str r3, [r4, #0x4] */
/* @0x11ce44 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x11ce48 · F_SkeletonSetAnimationExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x11ce48 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x11ce4c mov r4, r0 */
/* @0x11ce50 mov r3, #0 */
/* @0x11ce54 mov r7, r1 */
/* @0x11ce58 mov r5, r3 */
/* @0x11ce5c movt r3, #0xbff0 */
/* @0x11ce60 str r5, [r0, #0xc] */
/* @0x11ce64 str r3, [r0, #0x4] */
/* @0x11ce68 mov r0, r1 */
/* @0x11ce6c str r5, [r4] */
/* @0x11ce70 ldr r6, [sp, #0x20] */
/* @0x11ce74 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11ce78 subs r9, r0, #0 */
/* @0x11ce7c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x11ce80 mov r1, #1 */
/* @0x11ce84 mov r0, r6 */
/* @0x11ce88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ce8c mov r1, r5 */
/* @0x11ce90 mov r8, r0 */
/* @0x11ce94 mov r0, r6 */
/* @0x11ce98 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11ce9c mov r2, r8 */
/* @0x11cea0 mov r1, r0 */
/* @0x11cea4 mov r0, r9 */
/* @0x11cea8 bl 0xbe4ec <_ZN17CSkeletonInstance18SelectAnimationExtEPKci> */
/* @0x11ceac cmp r8, r5 */
/* @0x11ceb0 moveq r3, #0 */
/* @0x11ceb4 streq r3, [r7, #0x90] */
/* @0x11ceb8 mov r3, #0 */
/* @0x11cebc mov r2, r3 */
/* @0x11cec0 movt r3, #0x3ff0 */
/* @0x11cec4 stm r4, {r2, r3} */
/* @0x11cec8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x11cecc · F_SkeletonCreateAttachment(RValue&, CInstance*, CInstance*, int, RValue*) · size=304 · insn=76 */
/* @0x11cecc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11ced0 mov r4, r0 */
/* @0x11ced4 sub sp, sp, #44 */
/* @0x11ced8 mov r6, #0 */
/* @0x11cedc mov r3, #0 */
/* @0x11cee0 mov r0, r1 */
/* @0x11cee4 movt r3, #0xbff0 */
/* @0x11cee8 str r6, [r4, #0xc] */
/* @0x11ceec str r3, [r4, #0x4] */
/* @0x11cef0 str r6, [r4] */
/* @0x11cef4 ldr r5, [sp, #0x50] */
/* @0x11cef8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11cefc subs r9, r0, #0 */
/* @0x11cf00 beq 0x11cff4 <_Z26F_SkeletonCreateAttachmentR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x11cf04 mov r1, #1 */
/* @0x11cf08 mov r0, r5 */
/* @0x11cf0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11cf10 mov r1, #2 */
/* @0x11cf14 mov r7, r0 */
/* @0x11cf18 mov r0, r5 */
/* @0x11cf1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11cf20 mov r8, r0 */
/* @0x11cf24 mov r0, r7 */
/* @0x11cf28 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x11cf2c cmp r0, r6 */
/* @0x11cf30 beq 0x11cff4 <_Z26F_SkeletonCreateAttachmentR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x11cf34 cmp r8, r6 */
/* @0x11cf38 blt 0x11cff4 <_Z26F_SkeletonCreateAttachmentR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x11cf3c mov r1, r6 */
/* @0x11cf40 mov r0, r5 */
/* @0x11cf44 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11cf48 mov r10, r0 */
/* @0x11cf4c mov r0, r7 */
/* @0x11cf50 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11cf54 mov r1, #3 */
/* @0x11cf58 mov r7, r0 */
/* @0x11cf5c mov r0, r5 */
/* @0x11cf60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11cf64 mov r1, #4 */
/* @0x11cf68 mov r12, r0 */
/* @0x11cf6c mov r0, r5 */
/* @0x11cf70 str r12, [sp, #0x1c] */
/* @0x11cf74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11cf78 mov r1, #5 */
/* @0x11cf7c mov r2, r0 */
/* @0x11cf80 mov r0, r5 */
/* @0x11cf84 str r2, [sp, #0x20] */
/* @0x11cf88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11cf8c mov r1, #6 */
/* @0x11cf90 mov r3, r0 */
/* @0x11cf94 mov r0, r5 */
/* @0x11cf98 str r3, [sp, #0x24] */
/* @0x11cf9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11cfa0 mov r1, #7 */
/* @0x11cfa4 mov r11, r0 */
/* @0x11cfa8 mov r0, r5 */
/* @0x11cfac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11cfb0 ldr r2, [sp, #0x20] */
/* @0x11cfb4 ldr r3, [sp, #0x24] */
/* @0x11cfb8 mov r1, r10 */
/* @0x11cfbc ldr r12, [sp, #0x1c] */
/* @0x11cfc0 str r2, [sp, #0x4] */
/* @0x11cfc4 mov r2, r7 */
/* @0x11cfc8 str r3, [sp, #0x8] */
/* @0x11cfcc mov r3, r8 */
/* @0x11cfd0 str r12, [sp] */
/* @0x11cfd4 str r11, [sp, #0xc] */
/* @0x11cfd8 str r0, [sp, #0x10] */
/* @0x11cfdc mov r0, r9 */
/* @0x11cfe0 bl 0xbfb44 <_ZN17CSkeletonInstance16CreateAttachmentEPKcP7CSpriteifffff> */
/* @0x11cfe4 mov r3, r6 */
/* @0x11cfe8 str r6, [r4] */
/* @0x11cfec movt r3, #0x3ff0 */
/* @0x11cff0 str r3, [r4, #0x4] */
/* @0x11cff4 add sp, sp, #44 */
/* @0x11cff8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x11cffc · F_SkeletonSetAttachment(RValue&, CInstance*, CInstance*, int, RValue*) · size=328 · insn=82 */
/* @0x11cffc push {r4, r5, r6, r7, r8, lr} */
/* @0x11d000 mov r4, r0 */
/* @0x11d004 sub sp, sp, #24 */
/* @0x11d008 mov r5, #0 */
/* @0x11d00c mov r0, r1 */
/* @0x11d010 mov r3, #0 */
/* @0x11d014 str r5, [r4, #0xc] */
/* @0x11d018 movt r3, #0xbff0 */
/* @0x11d01c str r5, [r4] */
/* @0x11d020 str r3, [r4, #0x4] */
/* @0x11d024 ldr r6, [sp, #0x30] */
/* @0x11d028 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d02c mov r1, r5 */
/* @0x11d030 mov r7, r0 */
/* @0x11d034 mov r0, r6 */
/* @0x11d038 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d03c cmp r7, r5 */
/* @0x11d040 mov r8, r0 */
/* @0x11d044 beq 0x11d0b8 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x11d048 ldr r1, [r6, #0x1c] */
/* @0x11d04c mov r0, r6 */
/* @0x11d050 cmp r1, #1 */
/* @0x11d054 beq 0x11d0e8 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x11d058 mov r1, #1 */
/* @0x11d05c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d060 mov r5, r0 */
/* @0x11d064 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x11d068 subs r2, r0, #0 */
/* @0x11d06c beq 0x11d0c0 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x11d070 mov r0, r5 */
/* @0x11d074 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11d078 mov r1, r8 */
/* @0x11d07c mov r5, r0 */
/* @0x11d080 mov r0, r7 */
/* @0x11d084 ldr r2, [r5, #0x5c] */
/* @0x11d088 bl 0xc0810 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_> */
/* @0x11d08c subs r3, r0, #0 */
/* @0x11d090 beq 0x11d104 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x11d094 ldr r2, [r5, #0x5c] */
/* @0x11d098 mov r3, #0 */
/* @0x11d09c mov r0, r7 */
/* @0x11d0a0 mov r1, r8 */
/* @0x11d0a4 bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b> */
/* @0x11d0a8 mov r3, #0 */
/* @0x11d0ac mov r2, r3 */
/* @0x11d0b0 movt r3, #0x3ff0 */
/* @0x11d0b4 stm r4, {r2, r3} */
/* @0x11d0b8 add sp, sp, #24 */
/* @0x11d0bc pop {r4, r5, r6, r7, r8, pc} */
/* @0x11d0c0 mov r0, r7 */
/* @0x11d0c4 mov r1, r8 */
/* @0x11d0c8 mov r3, r2 */
/* @0x11d0cc bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b> */
/* @0x11d0d0 mov r3, #0 */
/* @0x11d0d4 mov r2, r3 */
/* @0x11d0d8 movt r3, #0x3ff0 */
/* @0x11d0dc stm r4, {r2, r3} */
/* @0x11d0e0 add sp, sp, #24 */
/* @0x11d0e4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x11d0e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d0ec mov r1, r8 */
/* @0x11d0f0 mov r3, r5 */
/* @0x11d0f4 mov r2, r0 */
/* @0x11d0f8 mov r0, r7 */
/* @0x11d0fc bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b> */
/* @0x11d100 b 0x11d0d0 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x11d104 vldr s14, [r5, #36] */
/* @0x11d108 vcvt.f32.s32 s15, s14 */
/* @0x11d10c ldr r1, [r5, #0x5c] */
/* @0x11d110 mov r12, #1065353216 */
/* @0x11d114 mov lr, #0 */
/* @0x11d118 mov r0, r7 */
/* @0x11d11c mov r2, r5 */
/* @0x11d120 vstr s15, [sp] */
/* @0x11d124 vldr s15, [r5, #40] */
/* @0x11d128 vcvt.f32.s32 s15, s15 */
/* @0x11d12c str r12, [sp, #0x8] */
/* @0x11d130 str r12, [sp, #0xc] */
/* @0x11d134 str lr, [sp, #0x10] */
/* @0x11d138 vstr s15, [sp, #4] */
/* @0x11d13c bl 0xbfb44 <_ZN17CSkeletonInstance16CreateAttachmentEPKcP7CSpriteifffff> */
/* @0x11d140 b 0x11d094 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0x98> */

/* ── FUNC 0x11d144 · F_SkeletonGetAttachment(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x11d144 push {r3, r4, r5, r6, r7, lr} */
/* @0x11d148 mov r4, r0 */
/* @0x11d14c mov r3, #1 */
/* @0x11d150 mov r0, r1 */
/* @0x11d154 str r3, [r4, #0xc] */
/* @0x11d158 mov r5, #0 */
/* @0x11d15c str r5, [r4] */
/* @0x11d160 ldr r6, [sp, #0x18] */
/* @0x11d164 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d168 subs r7, r0, #0 */
/* @0x11d16c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x11d170 mov r1, r5 */
/* @0x11d174 mov r0, r6 */
/* @0x11d178 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d17c mov r1, r0 */
/* @0x11d180 mov r0, r7 */
/* @0x11d184 bl 0xc07c8 <_ZNK17CSkeletonInstance13GetAttachmentEPc> */
/* @0x11d188 mov r1, r0 */
/* @0x11d18c mov r0, r4 */
/* @0x11d190 pop {r3, r4, r5, r6, r7, lr} */
/* @0x11d194 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x11d198 · F_SkeletonSetSkin(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x11d198 push {r4, r5, r6, lr} */
/* @0x11d19c mov r4, r0 */
/* @0x11d1a0 mov r5, #0 */
/* @0x11d1a4 mov r3, #0 */
/* @0x11d1a8 mov r0, r1 */
/* @0x11d1ac movt r3, #0xbff0 */
/* @0x11d1b0 str r5, [r4, #0xc] */
/* @0x11d1b4 str r3, [r4, #0x4] */
/* @0x11d1b8 str r5, [r4] */
/* @0x11d1bc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d1c0 subs r6, r0, #0 */
/* @0x11d1c4 popeq {r4, r5, r6, pc} */
/* @0x11d1c8 mov r1, r5 */
/* @0x11d1cc ldr r0, [sp, #0x10] */
/* @0x11d1d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d1d4 mov r1, r0 */
/* @0x11d1d8 mov r0, r6 */
/* @0x11d1dc bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc> */
/* @0x11d1e0 mov r3, r5 */
/* @0x11d1e4 str r5, [r4] */
/* @0x11d1e8 movt r3, #0x3ff0 */
/* @0x11d1ec str r3, [r4, #0x4] */
/* @0x11d1f0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x11d1f4 · F_SkeletonGetSkin(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x11d1f4 push {r4, lr} */
/* @0x11d1f8 mov r4, r0 */
/* @0x11d1fc mov r3, #1 */
/* @0x11d200 mov r0, r1 */
/* @0x11d204 str r3, [r4, #0xc] */
/* @0x11d208 mov r3, #0 */
/* @0x11d20c str r3, [r4] */
/* @0x11d210 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d214 cmp r0, #0 */
/* @0x11d218 popeq {r4, pc} */
/* @0x11d21c bl 0xc0170 <_ZNK17CSkeletonInstance7GetSkinEv> */
/* @0x11d220 mov r1, r0 */
/* @0x11d224 mov r0, r4 */
/* @0x11d228 pop {r4, lr} */
/* @0x11d22c b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x11d230 · F_SkeletonGetBoneData(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x11d230 push {r4, r5, r6, r7, r8, lr} */
/* @0x11d234 mov r4, r0 */
/* @0x11d238 mov r5, #0 */
/* @0x11d23c mov r3, #0 */
/* @0x11d240 mov r0, r1 */
/* @0x11d244 movt r3, #0xbff0 */
/* @0x11d248 str r5, [r4, #0xc] */
/* @0x11d24c str r3, [r4, #0x4] */
/* @0x11d250 str r5, [r4] */
/* @0x11d254 ldr r6, [sp, #0x18] */
/* @0x11d258 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d25c subs r7, r0, #0 */
/* @0x11d260 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x11d264 mov r1, r5 */
/* @0x11d268 mov r0, r6 */
/* @0x11d26c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d270 mov r1, #1 */
/* @0x11d274 mov r8, r0 */
/* @0x11d278 mov r0, r6 */
/* @0x11d27c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d280 mov r1, r8 */
/* @0x11d284 mov r2, r0 */
/* @0x11d288 mov r0, r7 */
/* @0x11d28c bl 0xbfd18 <_ZN17CSkeletonInstance11GetBoneDataEPKci> */
/* @0x11d290 cmp r0, #0 */
/* @0x11d294 moveq r5, r0 */
/* @0x11d298 movne r3, r5 */
/* @0x11d29c moveq r3, r5 */
/* @0x11d2a0 movtne r3, #0x3ff0 */
/* @0x11d2a4 str r5, [r4] */
/* @0x11d2a8 str r3, [r4, #0x4] */
/* @0x11d2ac pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x11d2b0 · F_SkeletonSetBoneData(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x11d2b0 push {r4, r5, r6, r7, r8, lr} */
/* @0x11d2b4 mov r4, r0 */
/* @0x11d2b8 mov r5, #0 */
/* @0x11d2bc mov r3, #0 */
/* @0x11d2c0 mov r0, r1 */
/* @0x11d2c4 movt r3, #0xbff0 */
/* @0x11d2c8 str r5, [r4, #0xc] */
/* @0x11d2cc str r3, [r4, #0x4] */
/* @0x11d2d0 str r5, [r4] */
/* @0x11d2d4 ldr r6, [sp, #0x18] */
/* @0x11d2d8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d2dc subs r7, r0, #0 */
/* @0x11d2e0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x11d2e4 mov r1, r5 */
/* @0x11d2e8 mov r0, r6 */
/* @0x11d2ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d2f0 mov r1, #1 */
/* @0x11d2f4 mov r8, r0 */
/* @0x11d2f8 mov r0, r6 */
/* @0x11d2fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d300 mov r1, r8 */
/* @0x11d304 mov r2, r0 */
/* @0x11d308 mov r0, r7 */
/* @0x11d30c bl 0xc16c0 <_ZN17CSkeletonInstance11SetBoneDataEPKci> */
/* @0x11d310 cmp r0, #0 */
/* @0x11d314 moveq r5, r0 */
/* @0x11d318 movne r3, r5 */
/* @0x11d31c moveq r3, r5 */
/* @0x11d320 movtne r3, #0x3ff0 */
/* @0x11d324 str r5, [r4] */
/* @0x11d328 str r3, [r4, #0x4] */
/* @0x11d32c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x11d330 · F_SkeletonGetBoneState(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x11d330 push {r4, r5, r6, r7, r8, lr} */
/* @0x11d334 mov r4, r0 */
/* @0x11d338 mov r5, #0 */
/* @0x11d33c mov r3, #0 */
/* @0x11d340 mov r0, r1 */
/* @0x11d344 movt r3, #0xbff0 */
/* @0x11d348 str r5, [r4, #0xc] */
/* @0x11d34c str r3, [r4, #0x4] */
/* @0x11d350 str r5, [r4] */
/* @0x11d354 ldr r6, [sp, #0x18] */
/* @0x11d358 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d35c subs r7, r0, #0 */
/* @0x11d360 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x11d364 mov r1, r5 */
/* @0x11d368 mov r0, r6 */
/* @0x11d36c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d370 mov r1, #1 */
/* @0x11d374 mov r8, r0 */
/* @0x11d378 mov r0, r6 */
/* @0x11d37c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d380 mov r1, r8 */
/* @0x11d384 mov r2, r0 */
/* @0x11d388 mov r0, r7 */
/* @0x11d38c bl 0xbfea8 <_ZN17CSkeletonInstance12GetBoneStateEPKci> */
/* @0x11d390 cmp r0, #0 */
/* @0x11d394 moveq r5, r0 */
/* @0x11d398 movne r3, r5 */
/* @0x11d39c moveq r3, r5 */
/* @0x11d3a0 movtne r3, #0x3ff0 */
/* @0x11d3a4 str r5, [r4] */
/* @0x11d3a8 str r3, [r4, #0x4] */
/* @0x11d3ac pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x11d3b0 · F_SkeletonSetBoneState(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x11d3b0 push {r4, r5, r6, r7, r8, lr} */
/* @0x11d3b4 mov r4, r0 */
/* @0x11d3b8 mov r5, #0 */
/* @0x11d3bc mov r3, #0 */
/* @0x11d3c0 mov r0, r1 */
/* @0x11d3c4 movt r3, #0xbff0 */
/* @0x11d3c8 str r5, [r4, #0xc] */
/* @0x11d3cc str r3, [r4, #0x4] */
/* @0x11d3d0 str r5, [r4] */
/* @0x11d3d4 ldr r6, [sp, #0x18] */
/* @0x11d3d8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d3dc subs r7, r0, #0 */
/* @0x11d3e0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x11d3e4 mov r1, r5 */
/* @0x11d3e8 mov r0, r6 */
/* @0x11d3ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d3f0 mov r1, #1 */
/* @0x11d3f4 mov r8, r0 */
/* @0x11d3f8 mov r0, r6 */
/* @0x11d3fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d400 mov r1, r8 */
/* @0x11d404 mov r2, r0 */
/* @0x11d408 mov r0, r7 */
/* @0x11d40c bl 0xc1480 <_ZN17CSkeletonInstance12SetBoneStateEPKci> */
/* @0x11d410 cmp r0, #0 */
/* @0x11d414 moveq r5, r0 */
/* @0x11d418 movne r3, r5 */
/* @0x11d41c moveq r3, r5 */
/* @0x11d420 movtne r3, #0x3ff0 */
/* @0x11d424 str r5, [r4] */
/* @0x11d428 str r3, [r4, #0x4] */
/* @0x11d42c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x11d430 · F_SkeletonDraw(RValue&, CInstance*, CInstance*, int, RValue*) · size=332 · insn=83 */
/* @0x11d430 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11d434 sub sp, sp, #52 */
/* @0x11d438 mov r3, #0 */
/* @0x11d43c mov r5, r1 */
/* @0x11d440 ldr r4, [sp, #0x58] */
/* @0x11d444 mov r2, r3 */
/* @0x11d448 str r3, [r0, #0xc] */
/* @0x11d44c movt r2, #0xbff0 */
/* @0x11d450 str r3, [r0] */
/* @0x11d454 mov r1, r3 */
/* @0x11d458 str r2, [r0, #0x4] */
/* @0x11d45c mov r0, r4 */
/* @0x11d460 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d464 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11d468 subs r3, r0, #0 */
/* @0x11d46c beq 0x11d47c <_Z14F_SkeletonDrawR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x11d470 ldr r6, [r3, #0x74] */
/* @0x11d474 cmp r6, #2 */
/* @0x11d478 beq 0x11d484 <_Z14F_SkeletonDrawR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x11d47c add sp, sp, #52 */
/* @0x11d480 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11d484 ldr r3, [r3, #0x58] */
/* @0x11d488 mov r0, r4 */
/* @0x11d48c mov r1, #1 */
/* @0x11d490 str r3, [sp, #0x2c] */
/* @0x11d494 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d498 mov r1, r6 */
/* @0x11d49c mov r8, r0 */
/* @0x11d4a0 mov r0, r4 */
/* @0x11d4a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d4a8 mov r1, #3 */
/* @0x11d4ac mov r7, r0 */
/* @0x11d4b0 mov r0, r4 */
/* @0x11d4b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d4b8 mov r1, #4 */
/* @0x11d4bc mov r6, r0 */
/* @0x11d4c0 mov r0, r4 */
/* @0x11d4c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d4c8 mov r1, #5 */
/* @0x11d4cc mov r12, r0 */
/* @0x11d4d0 mov r0, r4 */
/* @0x11d4d4 str r12, [sp, #0x20] */
/* @0x11d4d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d4dc mov r1, #6 */
/* @0x11d4e0 mov r2, r0 */
/* @0x11d4e4 mov r0, r4 */
/* @0x11d4e8 str r2, [sp, #0x24] */
/* @0x11d4ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d4f0 mov r1, #7 */
/* @0x11d4f4 mov r3, r0 */
/* @0x11d4f8 mov r0, r4 */
/* @0x11d4fc str r3, [sp, #0x28] */
/* @0x11d500 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d504 mov r1, #8 */
/* @0x11d508 mov r11, r0 */
/* @0x11d50c mov r0, r4 */
/* @0x11d510 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d514 mov r1, #9 */
/* @0x11d518 mov r10, r0 */
/* @0x11d51c mov r0, r4 */
/* @0x11d520 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d524 mov r1, #10 */
/* @0x11d528 mov r9, r0 */
/* @0x11d52c mov r0, r4 */
/* @0x11d530 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d534 ldr r2, [sp, #0x24] */
/* @0x11d538 ldr r3, [sp, #0x28] */
/* @0x11d53c mov r1, r8 */
/* @0x11d540 ldr r12, [sp, #0x20] */
/* @0x11d544 str r2, [sp, #0x4] */
/* @0x11d548 mov r2, r7 */
/* @0x11d54c str r3, [sp, #0x8] */
/* @0x11d550 mov r3, r6 */
/* @0x11d554 str r12, [sp] */
/* @0x11d558 str r11, [sp, #0xc] */
/* @0x11d55c str r10, [sp, #0x10] */
/* @0x11d560 str r9, [sp, #0x14] */
/* @0x11d564 str r5, [sp, #0x1c] */
/* @0x11d568 str r0, [sp, #0x18] */
/* @0x11d56c ldr r0, [sp, #0x2c] */
/* @0x11d570 bl 0xc0244 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance> */
/* @0x11d574 add sp, sp, #52 */
/* @0x11d578 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x11d57c · F_SkeletonDrawTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=312 · insn=78 */
/* @0x11d57c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11d580 sub sp, sp, #52 */
/* @0x11d584 mov r1, #0 */
/* @0x11d588 str r1, [r0, #0xc] */
/* @0x11d58c ldr r4, [sp, #0x58] */
/* @0x11d590 mov r3, r1 */
/* @0x11d594 movt r3, #0xbff0 */
/* @0x11d598 stm r0, {r1, r3} */
/* @0x11d59c mov r0, r4 */
/* @0x11d5a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d5a4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11d5a8 subs r3, r0, #0 */
/* @0x11d5ac beq 0x11d5bc <_Z18F_SkeletonDrawTimeR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x11d5b0 ldr r5, [r3, #0x74] */
/* @0x11d5b4 cmp r5, #2 */
/* @0x11d5b8 beq 0x11d5c4 <_Z18F_SkeletonDrawTimeR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x11d5bc add sp, sp, #52 */
/* @0x11d5c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11d5c4 mov r0, r4 */
/* @0x11d5c8 mov r1, #1 */
/* @0x11d5cc ldr r6, [r3, #0x58] */
/* @0x11d5d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d5d4 mov r1, r5 */
/* @0x11d5d8 mov r8, r0 */
/* @0x11d5dc mov r0, r4 */
/* @0x11d5e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d5e4 mov r1, #3 */
/* @0x11d5e8 mov r7, r0 */
/* @0x11d5ec mov r0, r4 */
/* @0x11d5f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d5f4 mov r1, #4 */
/* @0x11d5f8 mov r5, r0 */
/* @0x11d5fc mov r0, r4 */
/* @0x11d600 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d604 mov r1, #5 */
/* @0x11d608 mov r12, r0 */
/* @0x11d60c mov r0, r4 */
/* @0x11d610 str r12, [sp, #0x24] */
/* @0x11d614 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d618 mov r1, #6 */
/* @0x11d61c mov r2, r0 */
/* @0x11d620 mov r0, r4 */
/* @0x11d624 str r2, [sp, #0x28] */
/* @0x11d628 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d62c mov r1, #7 */
/* @0x11d630 mov r3, r0 */
/* @0x11d634 mov r0, r4 */
/* @0x11d638 str r3, [sp, #0x2c] */
/* @0x11d63c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d640 mov r1, #8 */
/* @0x11d644 mov r11, r0 */
/* @0x11d648 mov r0, r4 */
/* @0x11d64c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d650 mov r1, #9 */
/* @0x11d654 mov r10, r0 */
/* @0x11d658 mov r0, r4 */
/* @0x11d65c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d660 mov r1, #10 */
/* @0x11d664 mov r9, r0 */
/* @0x11d668 mov r0, r4 */
/* @0x11d66c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d670 ldr r2, [sp, #0x28] */
/* @0x11d674 ldr r3, [sp, #0x2c] */
/* @0x11d678 mov r1, r8 */
/* @0x11d67c ldr r12, [sp, #0x24] */
/* @0x11d680 str r2, [sp, #0x4] */
/* @0x11d684 mov r2, r7 */
/* @0x11d688 str r3, [sp, #0x8] */
/* @0x11d68c mov r3, r5 */
/* @0x11d690 str r12, [sp] */
/* @0x11d694 str r11, [sp, #0xc] */
/* @0x11d698 str r10, [sp, #0x10] */
/* @0x11d69c str r9, [sp, #0x14] */
/* @0x11d6a0 str r0, [sp, #0x18] */
/* @0x11d6a4 mov r0, r6 */
/* @0x11d6a8 bl 0xbeb24 <_ZN15CSkeletonSprite8DrawTimeEPKcS1_ffffffjf> */
/* @0x11d6ac add sp, sp, #52 */
/* @0x11d6b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x11d6b4 · F_SkeletonDrawInstance(RValue&, CInstance*, CInstance*, int, RValue*) · size=524 · insn=131 */
/* @0x11d6b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11d6b8 sub sp, sp, #52 */
/* @0x11d6bc mov r1, #0 */
/* @0x11d6c0 str r1, [r0, #0xc] */
/* @0x11d6c4 ldr r4, [sp, #0x58] */
/* @0x11d6c8 mov r3, r1 */
/* @0x11d6cc movt r3, #0xbff0 */
/* @0x11d6d0 stm r0, {r1, r3} */
/* @0x11d6d4 ldr r7, [pc, #0x1d0] */
/* @0x11d6d8 mov r0, r4 */
/* @0x11d6dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d6e0 add r7, pc, r7 */
/* @0x11d6e4 subs r6, r0, #0 */
/* @0x11d6e8 blt 0x11d734 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x11d6ec ldr r3, [pc, #0x1bc] */
/* @0x11d6f0 ldr r3, [r7, r3] */
/* @0x11d6f4 ldr r2, [r3, #0x4] */
/* @0x11d6f8 ldr r3, [r3] */
/* @0x11d6fc and r2, r6, r2 */
/* @0x11d700 ldr r3, [r3, r2, lsl #3] */
/* @0x11d704 cmp r3, #0 */
/* @0x11d708 beq 0x11d734 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x11d70c ldr r2, [r3, #0x8] */
/* @0x11d710 cmp r6, r2 */
/* @0x11d714 bne 0x11d728 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x11d718 b 0x11d760 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x11d71c ldr r1, [r3, #0x8] */
/* @0x11d720 cmp r6, r1 */
/* @0x11d724 beq 0x11d760 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x11d728 ldr r3, [r3, #0x4] */
/* @0x11d72c cmp r3, #0 */
/* @0x11d730 bne 0x11d71c <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x11d734 ldr r1, [pc, #0x178] */
/* @0x11d738 mov r2, r6 */
/* @0x11d73c ldr r3, [pc, #0x174] */
/* @0x11d740 add r1, pc, r1 */
/* @0x11d744 ldr r3, [r7, r3] */
/* @0x11d748 ldr r0, [r3] */
/* @0x11d74c ldr r3, [r0] */
/* @0x11d750 ldr r3, [r3, #0xc] */
/* @0x11d754 blx r3 */
/* @0x11d758 add sp, sp, #52 */
/* @0x11d75c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11d760 ldr r8, [r3, #0xc] */
/* @0x11d764 cmp r8, #0 */
/* @0x11d768 beq 0x11d734 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x11d76c mov r0, r8 */
/* @0x11d770 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x11d774 subs r5, r0, #0 */
/* @0x11d778 beq 0x11d898 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11d77c ldr r0, [r8, #0x8c] */
/* @0x11d780 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11d784 subs r3, r0, #0 */
/* @0x11d788 beq 0x11d798 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x11d78c ldr r6, [r3, #0x74] */
/* @0x11d790 cmp r6, #2 */
/* @0x11d794 beq 0x11d7a0 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x11d798 add sp, sp, #52 */
/* @0x11d79c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11d7a0 ldr r3, [r3, #0x58] */
/* @0x11d7a4 mov r0, r4 */
/* @0x11d7a8 mov r1, #1 */
/* @0x11d7ac str r3, [sp, #0x2c] */
/* @0x11d7b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d7b4 mov r1, r6 */
/* @0x11d7b8 mov r7, r0 */
/* @0x11d7bc mov r0, r4 */
/* @0x11d7c0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d7c4 mov r1, #3 */
/* @0x11d7c8 mov r6, r0 */
/* @0x11d7cc mov r0, r4 */
/* @0x11d7d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d7d4 mov r1, #4 */
/* @0x11d7d8 mov r12, r0 */
/* @0x11d7dc mov r0, r4 */
/* @0x11d7e0 str r12, [sp, #0x20] */
/* @0x11d7e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d7e8 mov r1, #5 */
/* @0x11d7ec mov r2, r0 */
/* @0x11d7f0 mov r0, r4 */
/* @0x11d7f4 str r2, [sp, #0x24] */
/* @0x11d7f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d7fc mov r1, #6 */
/* @0x11d800 mov r3, r0 */
/* @0x11d804 mov r0, r4 */
/* @0x11d808 str r3, [sp, #0x28] */
/* @0x11d80c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d810 mov r1, #7 */
/* @0x11d814 mov r11, r0 */
/* @0x11d818 mov r0, r4 */
/* @0x11d81c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d820 mov r1, #8 */
/* @0x11d824 mov r10, r0 */
/* @0x11d828 mov r0, r4 */
/* @0x11d82c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d830 mov r1, #9 */
/* @0x11d834 mov r9, r0 */
/* @0x11d838 mov r0, r4 */
/* @0x11d83c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d840 mov r1, #10 */
/* @0x11d844 mov r8, r0 */
/* @0x11d848 mov r0, r4 */
/* @0x11d84c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d850 ldr r2, [sp, #0x24] */
/* @0x11d854 ldr r3, [sp, #0x28] */
/* @0x11d858 mov r1, r5 */
/* @0x11d85c ldr r12, [sp, #0x20] */
/* @0x11d860 str r2, [sp, #0x4] */
/* @0x11d864 mov r2, r7 */
/* @0x11d868 str r3, [sp, #0x8] */
/* @0x11d86c mov r3, r6 */
/* @0x11d870 str r12, [sp] */
/* @0x11d874 str r11, [sp, #0xc] */
/* @0x11d878 str r10, [sp, #0x10] */
/* @0x11d87c str r9, [sp, #0x14] */
/* @0x11d880 str r8, [sp, #0x18] */
/* @0x11d884 str r0, [sp, #0x1c] */
/* @0x11d888 ldr r0, [sp, #0x2c] */
/* @0x11d88c bl 0xc069c <_ZN15CSkeletonSprite9DrawFrameEP17CSkeletonInstancePKcS3_ffffffjf> */
/* @0x11d890 add sp, sp, #52 */
/* @0x11d894 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11d898 ldr r1, [pc, #0x1c] */
/* @0x11d89c mov r2, r6 */
/* @0x11d8a0 ldr r3, [pc, #0x10] */
/* @0x11d8a4 add r1, pc, r1 */
/* @0x11d8a8 b 0x11d744 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x11d8ac eoreq r4, sp, r0, ror r5 */
/* @0x11d8b0 .word 0xffffbff4 */
/* @0x11d8b4 eoreq r12, r1, r0, lsl #19 */
/* @0x11d8b8 .word 0xffffbac4 */
/* @0x11d8bc eoreq r12, r1, r12, asr r8 */

/* ── FUNC 0x11d8c0 · F_SkeletonDrawCollision(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0x11d8c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11d8c4 sub sp, sp, #36 */
/* @0x11d8c8 mov r1, #0 */
/* @0x11d8cc str r1, [r0, #0xc] */
/* @0x11d8d0 ldr r4, [sp, #0x48] */
/* @0x11d8d4 mov r2, r1 */
/* @0x11d8d8 movt r2, #0xbff0 */
/* @0x11d8dc stm r0, {r1, r2} */
/* @0x11d8e0 mov r0, r4 */
/* @0x11d8e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d8e8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11d8ec subs r3, r0, #0 */
/* @0x11d8f0 beq 0x11d900 <_Z23F_SkeletonDrawCollisionR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x11d8f4 ldr r5, [r3, #0x74] */
/* @0x11d8f8 cmp r5, #2 */
/* @0x11d8fc beq 0x11d908 <_Z23F_SkeletonDrawCollisionR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x11d900 add sp, sp, #36 */
/* @0x11d904 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11d908 mov r0, r4 */
/* @0x11d90c mov r1, #1 */
/* @0x11d910 ldr r6, [r3, #0x58] */
/* @0x11d914 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11d918 mov r1, r5 */
/* @0x11d91c mov r8, r0 */
/* @0x11d920 mov r0, r4 */
/* @0x11d924 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d928 mov r1, #3 */
/* @0x11d92c mov r7, r0 */
/* @0x11d930 mov r0, r4 */
/* @0x11d934 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d938 mov r1, #4 */
/* @0x11d93c mov r5, r0 */
/* @0x11d940 mov r0, r4 */
/* @0x11d944 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d948 mov r1, #5 */
/* @0x11d94c mov r3, r0 */
/* @0x11d950 mov r0, r4 */
/* @0x11d954 str r3, [sp, #0x1c] */
/* @0x11d958 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d95c mov r1, #6 */
/* @0x11d960 mov r11, r0 */
/* @0x11d964 mov r0, r4 */
/* @0x11d968 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d96c mov r1, #7 */
/* @0x11d970 mov r10, r0 */
/* @0x11d974 mov r0, r4 */
/* @0x11d978 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d97c mov r1, #8 */
/* @0x11d980 mov r9, r0 */
/* @0x11d984 mov r0, r4 */
/* @0x11d988 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d98c ldr r3, [sp, #0x1c] */
/* @0x11d990 str r11, [sp, #0x4] */
/* @0x11d994 mov r1, r8 */
/* @0x11d998 str r10, [sp, #0x8] */
/* @0x11d99c mov r2, r7 */
/* @0x11d9a0 str r3, [sp] */
/* @0x11d9a4 mov r3, r5 */
/* @0x11d9a8 str r9, [sp, #0xc] */
/* @0x11d9ac str r0, [sp, #0x10] */
/* @0x11d9b0 mov r0, r6 */
/* @0x11d9b4 bl 0xbe9fc <_ZN15CSkeletonSprite13DrawCollisionEPKcifffffj> */
/* @0x11d9b8 add sp, sp, #36 */
/* @0x11d9bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x11d9c0 · F_DrawPath(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x11d9c0 push {r4, r5, r6, r7, r8, lr} */
/* @0x11d9c4 mov r1, #0 */
/* @0x11d9c8 ldr r4, [sp, #0x18] */
/* @0x11d9cc mov r0, r4 */
/* @0x11d9d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11d9d4 mov r1, #1 */
/* @0x11d9d8 mov r5, r0 */
/* @0x11d9dc mov r0, r4 */
/* @0x11d9e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d9e4 mov r1, #2 */
/* @0x11d9e8 mov r7, r0 */
/* @0x11d9ec mov r0, r4 */
/* @0x11d9f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11d9f4 mov r1, #3 */
/* @0x11d9f8 mov r6, r0 */
/* @0x11d9fc mov r0, r4 */
/* @0x11da00 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11da04 mov r4, r0 */
/* @0x11da08 mov r0, r5 */
/* @0x11da0c bl 0x1a8008 <_Z11Path_Existsi> */
/* @0x11da10 subs r1, r0, #0 */
/* @0x11da14 beq 0x11da54 <_Z10F_DrawPathR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11da18 cmp r4, #0 */
/* @0x11da1c mov r0, r5 */
/* @0x11da20 bne 0x11da3c <_Z10F_DrawPathR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x11da24 bl 0x1a815c <_Z9Path_Datai> */
/* @0x11da28 mov r1, r7 */
/* @0x11da2c mov r2, r6 */
/* @0x11da30 mov r3, r4 */
/* @0x11da34 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11da38 b 0x1a7ac0 <_ZN5CPath4DrawEffb> */
/* @0x11da3c bl 0x1a815c <_Z9Path_Datai> */
/* @0x11da40 mov r1, #0 */
/* @0x11da44 mov r3, #1 */
/* @0x11da48 mov r2, r1 */
/* @0x11da4c pop {r4, r5, r6, r7, r8, lr} */
/* @0x11da50 b 0x1a7ac0 <_ZN5CPath4DrawEffb> */
/* @0x11da54 ldr r0, [pc, #0x8] */
/* @0x11da58 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11da5c add r0, pc, r0 */
/* @0x11da60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11da64 .word 0x0021c6f0 */

/* ── FUNC 0x11da68 · F_BackgroundGetTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x11da68 push {r3, r4, r5, lr} */
/* @0x11da6c mov r1, #0 */
/* @0x11da70 mov r4, r0 */
/* @0x11da74 ldr r0, [sp, #0x10] */
/* @0x11da78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11da7c mov r5, r0 */
/* @0x11da80 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x11da84 subs r1, r0, #0 */
/* @0x11da88 beq 0x11daa8 <_Z22F_BackgroundGetTextureR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x11da8c mov r3, #3 */
/* @0x11da90 mov r0, r5 */
/* @0x11da94 str r3, [r4, #0xc] */
/* @0x11da98 bl 0xc3794 <_Z15Background_Datai> */
/* @0x11da9c bl 0xc1e8c <_ZN11CBackground10GetTextureEv> */
/* @0x11daa0 str r0, [r4] */
/* @0x11daa4 pop {r3, r4, r5, pc} */
/* @0x11daa8 ldr r0, [pc, #0x8] */
/* @0x11daac pop {r3, r4, r5, lr} */
/* @0x11dab0 add r0, pc, r0 */
/* @0x11dab4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11dab8 eoreq r12, r1, r0, asr #13 */

/* ── FUNC 0x11dabc · F_FontGetTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x11dabc push {r3, r4, r5, lr} */
/* @0x11dac0 mov r1, #0 */
/* @0x11dac4 mov r4, r0 */
/* @0x11dac8 ldr r0, [sp, #0x10] */
/* @0x11dacc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dad0 mov r5, r0 */
/* @0x11dad4 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x11dad8 subs r1, r0, #0 */
/* @0x11dadc beq 0x11dafc <_Z16F_FontGetTextureR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x11dae0 mov r3, #3 */
/* @0x11dae4 mov r0, r5 */
/* @0x11dae8 str r3, [r4, #0xc] */
/* @0x11daec bl 0xfa3fc <_Z9Font_Datai> */
/* @0x11daf0 bl 0xf94e4 <_ZN7CFontGM10GetTextureEv> */
/* @0x11daf4 str r0, [r4] */
/* @0x11daf8 pop {r3, r4, r5, pc} */
/* @0x11dafc ldr r0, [pc, #0x8] */
/* @0x11db00 pop {r3, r4, r5, lr} */
/* @0x11db04 add r0, pc, r0 */
/* @0x11db08 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11db0c eoreq r12, r1, r0, lsr #13 */

/* ── FUNC 0x11db10 · F_DrawBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x11db10 ldr r3, [pc, #0xb4] */
/* @0x11db14 push {r4, r5, r6, lr} */
/* @0x11db18 ldr r3, [pc, r3] */
/* @0x11db1c ldr r4, [sp, #0x10] */
/* @0x11db20 ldrb r1, [r3] */
/* @0x11db24 cmp r1, #0 */
/* @0x11db28 mov r0, r4 */
/* @0x11db2c beq 0x11db78 <_Z16F_DrawBackgroundR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x11db30 mov r1, #0 */
/* @0x11db34 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11db38 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11db3c subs r5, r0, #0 */
/* @0x11db40 beq 0x11dbb8 <_Z16F_DrawBackgroundR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x11db44 mov r0, r4 */
/* @0x11db48 mov r1, #1 */
/* @0x11db4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11db50 mov r1, #2 */
/* @0x11db54 mov r6, r0 */
/* @0x11db58 mov r0, r4 */
/* @0x11db5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11db60 mov r2, r6 */
/* @0x11db64 mov r1, #0 */
/* @0x11db68 mov r3, r0 */
/* @0x11db6c mov r0, r5 */
/* @0x11db70 pop {r4, r5, r6, lr} */
/* @0x11db74 b 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x11db78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11db7c bl 0xc3794 <_Z15Background_Datai> */
/* @0x11db80 subs r5, r0, #0 */
/* @0x11db84 beq 0x11dbb8 <_Z16F_DrawBackgroundR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x11db88 mov r0, r4 */
/* @0x11db8c mov r1, #1 */
/* @0x11db90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11db94 mov r1, #2 */
/* @0x11db98 mov r6, r0 */
/* @0x11db9c mov r0, r4 */
/* @0x11dba0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dba4 mov r1, r6 */
/* @0x11dba8 mov r2, r0 */
/* @0x11dbac mov r0, r5 */
/* @0x11dbb0 pop {r4, r5, r6, lr} */
/* @0x11dbb4 b 0xc1fb4 <_ZN11CBackground10DrawSimpleEff> */
/* @0x11dbb8 ldr r0, [pc, #0x10] */
/* @0x11dbbc mov r1, #0 */
/* @0x11dbc0 pop {r4, r5, r6, lr} */
/* @0x11dbc4 add r0, pc, r0 */
/* @0x11dbc8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11dbcc eoreq pc, r12, r12, lsl #28 */
/* @0x11dbd0 eoreq r12, r1, r0, lsl r6 */

/* ── FUNC 0x11dbd4 · F_DrawBackgroundExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=412 · insn=103 */
/* @0x11dbd4 ldr r3, [pc, #0x18c] */
/* @0x11dbd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11dbdc ldr r3, [pc, r3] */
/* @0x11dbe0 sub sp, sp, #28 */
/* @0x11dbe4 ldrb r1, [r3] */
/* @0x11dbe8 ldr r4, [sp, #0x40] */
/* @0x11dbec cmp r1, #0 */
/* @0x11dbf0 mov r0, r4 */
/* @0x11dbf4 beq 0x11dca8 <_Z19F_DrawBackgroundExtR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x11dbf8 mov r1, #0 */
/* @0x11dbfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dc00 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11dc04 subs r5, r0, #0 */
/* @0x11dc08 beq 0x11dd50 <_Z19F_DrawBackgroundExtR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x11dc0c mov r0, r4 */
/* @0x11dc10 mov r1, #1 */
/* @0x11dc14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc18 mov r1, #2 */
/* @0x11dc1c mov r7, r0 */
/* @0x11dc20 mov r0, r4 */
/* @0x11dc24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc28 mov r1, #3 */
/* @0x11dc2c mov r6, r0 */
/* @0x11dc30 mov r0, r4 */
/* @0x11dc34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc38 mov r1, #4 */
/* @0x11dc3c mov r11, r0 */
/* @0x11dc40 mov r0, r4 */
/* @0x11dc44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc48 mov r1, #5 */
/* @0x11dc4c mov r10, r0 */
/* @0x11dc50 mov r0, r4 */
/* @0x11dc54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc58 mov r1, #6 */
/* @0x11dc5c mov r9, r0 */
/* @0x11dc60 mov r0, r4 */
/* @0x11dc64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dc68 mov r1, #7 */
/* @0x11dc6c mov r8, r0 */
/* @0x11dc70 mov r0, r4 */
/* @0x11dc74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc78 str r11, [sp] */
/* @0x11dc7c str r10, [sp, #0x4] */
/* @0x11dc80 mov r1, #0 */
/* @0x11dc84 str r9, [sp, #0x8] */
/* @0x11dc88 mov r2, r7 */
/* @0x11dc8c str r8, [sp, #0xc] */
/* @0x11dc90 mov r3, r6 */
/* @0x11dc94 str r0, [sp, #0x10] */
/* @0x11dc98 mov r0, r5 */
/* @0x11dc9c bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x11dca0 add sp, sp, #28 */
/* @0x11dca4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11dca8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dcac bl 0xc3794 <_Z15Background_Datai> */
/* @0x11dcb0 subs r5, r0, #0 */
/* @0x11dcb4 beq 0x11dd50 <_Z19F_DrawBackgroundExtR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x11dcb8 mov r0, r4 */
/* @0x11dcbc mov r1, #1 */
/* @0x11dcc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dcc4 mov r1, #2 */
/* @0x11dcc8 mov r8, r0 */
/* @0x11dccc mov r0, r4 */
/* @0x11dcd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dcd4 mov r1, #3 */
/* @0x11dcd8 mov r7, r0 */
/* @0x11dcdc mov r0, r4 */
/* @0x11dce0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dce4 mov r1, #4 */
/* @0x11dce8 mov r6, r0 */
/* @0x11dcec mov r0, r4 */
/* @0x11dcf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dcf4 mov r1, #5 */
/* @0x11dcf8 mov r11, r0 */
/* @0x11dcfc mov r0, r4 */
/* @0x11dd00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dd04 mov r1, #6 */
/* @0x11dd08 mov r10, r0 */
/* @0x11dd0c mov r0, r4 */
/* @0x11dd10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dd14 mov r1, #7 */
/* @0x11dd18 mov r9, r0 */
/* @0x11dd1c mov r0, r4 */
/* @0x11dd20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dd24 str r11, [sp] */
/* @0x11dd28 str r10, [sp, #0x4] */
/* @0x11dd2c mov r1, r8 */
/* @0x11dd30 str r9, [sp, #0x8] */
/* @0x11dd34 mov r2, r7 */
/* @0x11dd38 mov r3, r6 */
/* @0x11dd3c str r0, [sp, #0xc] */
/* @0x11dd40 mov r0, r5 */
/* @0x11dd44 bl 0xc1fd0 <_ZN11CBackground4DrawEfffffjf> */
/* @0x11dd48 add sp, sp, #28 */
/* @0x11dd4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11dd50 ldr r0, [pc, #0x14] */
/* @0x11dd54 mov r1, #0 */
/* @0x11dd58 add r0, pc, r0 */
/* @0x11dd5c add sp, sp, #28 */
/* @0x11dd60 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11dd64 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11dd68 eoreq pc, r12, r8, asr #26 */
/* @0x11dd6c eoreq r12, r1, r12, ror r4 */

/* ── FUNC 0x11dd70 · F_DrawBackgroundPart(RValue&, CInstance*, CInstance*, int, RValue*) · size=436 · insn=109 */
/* @0x11dd70 ldr r3, [pc, #0x1a4] */
/* @0x11dd74 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11dd78 ldr r3, [pc, r3] */
/* @0x11dd7c sub sp, sp, #32 */
/* @0x11dd80 ldrb r1, [r3] */
/* @0x11dd84 ldr r4, [sp, #0x40] */
/* @0x11dd88 cmp r1, #0 */
/* @0x11dd8c mov r0, r4 */
/* @0x11dd90 beq 0x11de50 <_Z20F_DrawBackgroundPartR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x11dd94 mov r1, #0 */
/* @0x11dd98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dd9c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11dda0 subs r5, r0, #0 */
/* @0x11dda4 beq 0x11df04 <_Z20F_DrawBackgroundPartR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x11dda8 mov r0, r4 */
/* @0x11ddac mov r1, #1 */
/* @0x11ddb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ddb4 mov r1, #2 */
/* @0x11ddb8 mov r7, r0 */
/* @0x11ddbc mov r0, r4 */
/* @0x11ddc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ddc4 mov r1, #3 */
/* @0x11ddc8 mov r6, r0 */
/* @0x11ddcc mov r0, r4 */
/* @0x11ddd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ddd4 mov r1, #4 */
/* @0x11ddd8 mov r10, r0 */
/* @0x11dddc mov r0, r4 */
/* @0x11dde0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dde4 mov r1, #5 */
/* @0x11dde8 mov r9, r0 */
/* @0x11ddec mov r0, r4 */
/* @0x11ddf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ddf4 mov r1, #6 */
/* @0x11ddf8 mov r8, r0 */
/* @0x11ddfc mov r0, r4 */
/* @0x11de00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11de04 mov r4, r0 */
/* @0x11de08 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11de0c mov r12, #1065353216 */
/* @0x11de10 mvn lr, #-16777216 */
/* @0x11de14 str r10, [sp] */
/* @0x11de18 mov r2, r7 */
/* @0x11de1c str r9, [sp, #0x4] */
/* @0x11de20 mov r3, r6 */
/* @0x11de24 str r8, [sp, #0x8] */
/* @0x11de28 mov r1, #0 */
/* @0x11de2c str r4, [sp, #0xc] */
/* @0x11de30 str lr, [sp, #0x18] */
/* @0x11de34 str r12, [sp, #0x10] */
/* @0x11de38 str r12, [sp, #0x14] */
/* @0x11de3c str r0, [sp, #0x1c] */
/* @0x11de40 mov r0, r5 */
/* @0x11de44 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf> */
/* @0x11de48 add sp, sp, #32 */
/* @0x11de4c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11de50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11de54 bl 0xc3794 <_Z15Background_Datai> */
/* @0x11de58 subs r5, r0, #0 */
/* @0x11de5c beq 0x11df04 <_Z20F_DrawBackgroundPartR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x11de60 mov r0, r4 */
/* @0x11de64 mov r1, #1 */
/* @0x11de68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11de6c mov r1, #2 */
/* @0x11de70 mov r8, r0 */
/* @0x11de74 mov r0, r4 */
/* @0x11de78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11de7c mov r1, #3 */
/* @0x11de80 mov r7, r0 */
/* @0x11de84 mov r0, r4 */
/* @0x11de88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11de8c mov r1, #4 */
/* @0x11de90 mov r6, r0 */
/* @0x11de94 mov r0, r4 */
/* @0x11de98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11de9c mov r1, #5 */
/* @0x11dea0 mov r10, r0 */
/* @0x11dea4 mov r0, r4 */
/* @0x11dea8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11deac mov r1, #6 */
/* @0x11deb0 mov r9, r0 */
/* @0x11deb4 mov r0, r4 */
/* @0x11deb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11debc mov r4, r0 */
/* @0x11dec0 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11dec4 mov r12, #1065353216 */
/* @0x11dec8 mvn lr, #-16777216 */
/* @0x11decc str r10, [sp] */
/* @0x11ded0 mov r1, r8 */
/* @0x11ded4 str r9, [sp, #0x4] */
/* @0x11ded8 mov r2, r7 */
/* @0x11dedc str r4, [sp, #0x8] */
/* @0x11dee0 mov r3, r6 */
/* @0x11dee4 str lr, [sp, #0x14] */
/* @0x11dee8 str r12, [sp, #0xc] */
/* @0x11deec str r12, [sp, #0x10] */
/* @0x11def0 str r0, [sp, #0x18] */
/* @0x11def4 mov r0, r5 */
/* @0x11def8 bl 0xc2184 <_ZN11CBackground8DrawPartEffffffffjf> */
/* @0x11defc add sp, sp, #32 */
/* @0x11df00 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11df04 ldr r0, [pc, #0x14] */
/* @0x11df08 mov r1, #0 */
/* @0x11df0c add r0, pc, r0 */
/* @0x11df10 add sp, sp, #32 */
/* @0x11df14 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11df18 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11df1c eoreq pc, r12, r12, lsr #23 */
/* @0x11df20 eoreq r12, r1, r8, asr #5 */

/* ── FUNC 0x11df24 · F_DrawBackgroundPartExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=580 · insn=145 */
/* @0x11df24 ldr r3, [pc, #0x234] */
/* @0x11df28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11df2c ldr r3, [pc, r3] */
/* @0x11df30 sub sp, sp, #52 */
/* @0x11df34 ldrb r1, [r3] */
/* @0x11df38 ldr r4, [sp, #0x58] */
/* @0x11df3c cmp r1, #0 */
/* @0x11df40 mov r0, r4 */
/* @0x11df44 beq 0x11e04c <_Z23F_DrawBackgroundPartExtR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x11df48 mov r1, #0 */
/* @0x11df4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11df50 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11df54 subs r5, r0, #0 */
/* @0x11df58 beq 0x11e148 <_Z23F_DrawBackgroundPartExtR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x11df5c mov r0, r4 */
/* @0x11df60 mov r1, #1 */
/* @0x11df64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11df68 mov r1, #2 */
/* @0x11df6c mov r7, r0 */
/* @0x11df70 mov r0, r4 */
/* @0x11df74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11df78 mov r1, #3 */
/* @0x11df7c mov r6, r0 */
/* @0x11df80 mov r0, r4 */
/* @0x11df84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11df88 mov r1, #4 */
/* @0x11df8c mov r12, r0 */
/* @0x11df90 mov r0, r4 */
/* @0x11df94 str r12, [sp, #0x24] */
/* @0x11df98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11df9c mov r1, #5 */
/* @0x11dfa0 mov r2, r0 */
/* @0x11dfa4 mov r0, r4 */
/* @0x11dfa8 str r2, [sp, #0x28] */
/* @0x11dfac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dfb0 mov r1, #6 */
/* @0x11dfb4 mov r3, r0 */
/* @0x11dfb8 mov r0, r4 */
/* @0x11dfbc str r3, [sp, #0x2c] */
/* @0x11dfc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dfc4 mov r1, #7 */
/* @0x11dfc8 mov r11, r0 */
/* @0x11dfcc mov r0, r4 */
/* @0x11dfd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dfd4 mov r1, #8 */
/* @0x11dfd8 mov r10, r0 */
/* @0x11dfdc mov r0, r4 */
/* @0x11dfe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dfe4 mov r1, #9 */
/* @0x11dfe8 mov r9, r0 */
/* @0x11dfec mov r0, r4 */
/* @0x11dff0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dff4 mov r1, #10 */
/* @0x11dff8 mov r8, r0 */
/* @0x11dffc mov r0, r4 */
/* @0x11e000 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e004 ldr r2, [sp, #0x28] */
/* @0x11e008 ldr r3, [sp, #0x2c] */
/* @0x11e00c mov r1, #0 */
/* @0x11e010 ldr r12, [sp, #0x24] */
/* @0x11e014 str r2, [sp, #0x4] */
/* @0x11e018 mov r2, r7 */
/* @0x11e01c str r3, [sp, #0x8] */
/* @0x11e020 mov r3, r6 */
/* @0x11e024 str r12, [sp] */
/* @0x11e028 str r11, [sp, #0xc] */
/* @0x11e02c str r10, [sp, #0x10] */
/* @0x11e030 str r9, [sp, #0x14] */
/* @0x11e034 str r8, [sp, #0x18] */
/* @0x11e038 str r0, [sp, #0x1c] */
/* @0x11e03c mov r0, r5 */
/* @0x11e040 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf> */
/* @0x11e044 add sp, sp, #52 */
/* @0x11e048 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11e04c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e050 bl 0xc3794 <_Z15Background_Datai> */
/* @0x11e054 subs r5, r0, #0 */
/* @0x11e058 beq 0x11e148 <_Z23F_DrawBackgroundPartExtR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x11e05c mov r0, r4 */
/* @0x11e060 mov r1, #1 */
/* @0x11e064 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e068 mov r1, #2 */
/* @0x11e06c mov r8, r0 */
/* @0x11e070 mov r0, r4 */
/* @0x11e074 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e078 mov r1, #3 */
/* @0x11e07c mov r7, r0 */
/* @0x11e080 mov r0, r4 */
/* @0x11e084 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e088 mov r1, #4 */
/* @0x11e08c mov r6, r0 */
/* @0x11e090 mov r0, r4 */
/* @0x11e094 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e098 mov r1, #5 */
/* @0x11e09c mov r12, r0 */
/* @0x11e0a0 mov r0, r4 */
/* @0x11e0a4 str r12, [sp, #0x24] */
/* @0x11e0a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e0ac mov r1, #6 */
/* @0x11e0b0 mov r2, r0 */
/* @0x11e0b4 mov r0, r4 */
/* @0x11e0b8 str r2, [sp, #0x28] */
/* @0x11e0bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e0c0 mov r1, #7 */
/* @0x11e0c4 mov r3, r0 */
/* @0x11e0c8 mov r0, r4 */
/* @0x11e0cc str r3, [sp, #0x2c] */
/* @0x11e0d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e0d4 mov r1, #8 */
/* @0x11e0d8 mov r11, r0 */
/* @0x11e0dc mov r0, r4 */
/* @0x11e0e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e0e4 mov r1, #9 */
/* @0x11e0e8 mov r10, r0 */
/* @0x11e0ec mov r0, r4 */
/* @0x11e0f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e0f4 mov r1, #10 */
/* @0x11e0f8 mov r9, r0 */
/* @0x11e0fc mov r0, r4 */
/* @0x11e100 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e104 ldr r2, [sp, #0x28] */
/* @0x11e108 ldr r3, [sp, #0x2c] */
/* @0x11e10c mov r1, r8 */
/* @0x11e110 ldr r12, [sp, #0x24] */
/* @0x11e114 str r2, [sp, #0x4] */
/* @0x11e118 mov r2, r7 */
/* @0x11e11c str r3, [sp, #0x8] */
/* @0x11e120 mov r3, r6 */
/* @0x11e124 str r12, [sp] */
/* @0x11e128 str r11, [sp, #0xc] */
/* @0x11e12c str r10, [sp, #0x10] */
/* @0x11e130 str r9, [sp, #0x14] */
/* @0x11e134 str r0, [sp, #0x18] */
/* @0x11e138 mov r0, r5 */
/* @0x11e13c bl 0xc2184 <_ZN11CBackground8DrawPartEffffffffjf> */
/* @0x11e140 add sp, sp, #52 */
/* @0x11e144 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11e148 ldr r0, [pc, #0x14] */
/* @0x11e14c mov r1, #0 */
/* @0x11e150 add r0, pc, r0 */
/* @0x11e154 add sp, sp, #52 */
/* @0x11e158 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11e15c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11e160 .word 0x002cf9f8 */
/* @0x11e164 eoreq r12, r1, r4, lsl #1 */

/* ── FUNC 0x11e168 · F_DrawBackgroundGeneral(RValue&, CInstance*, CInstance*, int, RValue*) · size=752 · insn=188 */
/* @0x11e168 ldr r3, [pc, #0x2e0] */
/* @0x11e16c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11e170 ldr r3, [pc, r3] */
/* @0x11e174 sub sp, sp, #84 */
/* @0x11e178 ldrb r1, [r3] */
/* @0x11e17c ldr r4, [sp, #0x78] */
/* @0x11e180 cmp r1, #0 */
/* @0x11e184 mov r0, r4 */
/* @0x11e188 beq 0x11e2e8 <_Z23F_DrawBackgroundGeneralR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x11e18c mov r1, #0 */
/* @0x11e190 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e194 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11e198 subs r5, r0, #0 */
/* @0x11e19c beq 0x11e438 <_Z23F_DrawBackgroundGeneralR6RValueP9CInstanceS2_iPS_+0x2d0> */
/* @0x11e1a0 mov r0, r4 */
/* @0x11e1a4 mov r1, #1 */
/* @0x11e1a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e1ac mov r1, #2 */
/* @0x11e1b0 mov r2, r0 */
/* @0x11e1b4 mov r0, r4 */
/* @0x11e1b8 str r2, [sp, #0x34] */
/* @0x11e1bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e1c0 mov r1, #3 */
/* @0x11e1c4 mov r3, r0 */
/* @0x11e1c8 mov r0, r4 */
/* @0x11e1cc str r3, [sp, #0x38] */
/* @0x11e1d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e1d4 mov r1, #4 */
/* @0x11e1d8 mov r12, r0 */
/* @0x11e1dc mov r0, r4 */
/* @0x11e1e0 str r12, [sp, #0x3c] */
/* @0x11e1e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e1e8 mov r1, #5 */
/* @0x11e1ec str r0, [sp, #0x40] */
/* @0x11e1f0 mov r0, r4 */
/* @0x11e1f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e1f8 mov r1, #6 */
/* @0x11e1fc str r0, [sp, #0x44] */
/* @0x11e200 mov r0, r4 */
/* @0x11e204 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e208 mov r1, #7 */
/* @0x11e20c mov r11, r0 */
/* @0x11e210 mov r0, r4 */
/* @0x11e214 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e218 mov r1, #8 */
/* @0x11e21c mov r10, r0 */
/* @0x11e220 mov r0, r4 */
/* @0x11e224 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e228 mov r1, #9 */
/* @0x11e22c mov r9, r0 */
/* @0x11e230 mov r0, r4 */
/* @0x11e234 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e238 mov r1, #10 */
/* @0x11e23c str r0, [sp, #0x48] */
/* @0x11e240 mov r0, r4 */
/* @0x11e244 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e248 mov r1, #11 */
/* @0x11e24c str r0, [sp, #0x4c] */
/* @0x11e250 mov r0, r4 */
/* @0x11e254 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e258 mov r1, #12 */
/* @0x11e25c mov r8, r0 */
/* @0x11e260 mov r0, r4 */
/* @0x11e264 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e268 mov r1, #13 */
/* @0x11e26c mov r7, r0 */
/* @0x11e270 mov r0, r4 */
/* @0x11e274 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e278 mov r1, #14 */
/* @0x11e27c mov r6, r0 */
/* @0x11e280 mov r0, r4 */
/* @0x11e284 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e288 ldr r1, [sp, #0x40] */
/* @0x11e28c ldr r12, [sp, #0x3c] */
/* @0x11e290 str r11, [sp, #0xc] */
/* @0x11e294 str r1, [sp, #0x4] */
/* @0x11e298 ldr r1, [sp, #0x44] */
/* @0x11e29c str r12, [sp] */
/* @0x11e2a0 str r10, [sp, #0x10] */
/* @0x11e2a4 str r1, [sp, #0x8] */
/* @0x11e2a8 ldr r1, [sp, #0x48] */
/* @0x11e2ac str r9, [sp, #0x14] */
/* @0x11e2b0 str r8, [sp, #0x20] */
/* @0x11e2b4 str r1, [sp, #0x18] */
/* @0x11e2b8 ldr r1, [sp, #0x4c] */
/* @0x11e2bc str r7, [sp, #0x24] */
/* @0x11e2c0 str r6, [sp, #0x28] */
/* @0x11e2c4 str r1, [sp, #0x1c] */
/* @0x11e2c8 mov r1, #0 */
/* @0x11e2cc ldr r2, [sp, #0x34] */
/* @0x11e2d0 ldr r3, [sp, #0x38] */
/* @0x11e2d4 str r0, [sp, #0x2c] */
/* @0x11e2d8 mov r0, r5 */
/* @0x11e2dc bl 0x1e5fa8 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf> */
/* @0x11e2e0 add sp, sp, #84 */
/* @0x11e2e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11e2e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e2ec bl 0xc3794 <_Z15Background_Datai> */
/* @0x11e2f0 subs r5, r0, #0 */
/* @0x11e2f4 beq 0x11e438 <_Z23F_DrawBackgroundGeneralR6RValueP9CInstanceS2_iPS_+0x2d0> */
/* @0x11e2f8 mov r0, r4 */
/* @0x11e2fc mov r1, #1 */
/* @0x11e300 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e304 mov r1, #2 */
/* @0x11e308 str r0, [sp, #0x40] */
/* @0x11e30c mov r0, r4 */
/* @0x11e310 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e314 mov r1, #3 */
/* @0x11e318 mov r2, r0 */
/* @0x11e31c mov r0, r4 */
/* @0x11e320 str r2, [sp, #0x34] */
/* @0x11e324 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e328 mov r1, #4 */
/* @0x11e32c mov r3, r0 */
/* @0x11e330 mov r0, r4 */
/* @0x11e334 str r3, [sp, #0x38] */
/* @0x11e338 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e33c mov r1, #5 */
/* @0x11e340 mov r12, r0 */
/* @0x11e344 mov r0, r4 */
/* @0x11e348 str r12, [sp, #0x3c] */
/* @0x11e34c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e350 mov r1, #6 */
/* @0x11e354 str r0, [sp, #0x44] */
/* @0x11e358 mov r0, r4 */
/* @0x11e35c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e360 mov r1, #7 */
/* @0x11e364 str r0, [sp, #0x48] */
/* @0x11e368 mov r0, r4 */
/* @0x11e36c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e370 mov r1, #8 */
/* @0x11e374 mov r11, r0 */
/* @0x11e378 mov r0, r4 */
/* @0x11e37c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e380 mov r1, #9 */
/* @0x11e384 mov r10, r0 */
/* @0x11e388 mov r0, r4 */
/* @0x11e38c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e390 mov r1, #10 */
/* @0x11e394 mov r9, r0 */
/* @0x11e398 mov r0, r4 */
/* @0x11e39c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e3a0 mov r1, #11 */
/* @0x11e3a4 str r0, [sp, #0x4c] */
/* @0x11e3a8 mov r0, r4 */
/* @0x11e3ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e3b0 mov r1, #12 */
/* @0x11e3b4 mov r8, r0 */
/* @0x11e3b8 mov r0, r4 */
/* @0x11e3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e3c0 mov r1, #13 */
/* @0x11e3c4 mov r7, r0 */
/* @0x11e3c8 mov r0, r4 */
/* @0x11e3cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e3d0 mov r1, #14 */
/* @0x11e3d4 mov r6, r0 */
/* @0x11e3d8 mov r0, r4 */
/* @0x11e3dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e3e0 ldr r1, [sp, #0x44] */
/* @0x11e3e4 ldr r12, [sp, #0x3c] */
/* @0x11e3e8 str r11, [sp, #0xc] */
/* @0x11e3ec str r1, [sp, #0x4] */
/* @0x11e3f0 ldr r1, [sp, #0x48] */
/* @0x11e3f4 str r12, [sp] */
/* @0x11e3f8 str r10, [sp, #0x10] */
/* @0x11e3fc str r1, [sp, #0x8] */
/* @0x11e400 ldr r1, [sp, #0x4c] */
/* @0x11e404 str r9, [sp, #0x14] */
/* @0x11e408 str r8, [sp, #0x1c] */
/* @0x11e40c str r1, [sp, #0x18] */
/* @0x11e410 str r7, [sp, #0x20] */
/* @0x11e414 str r6, [sp, #0x24] */
/* @0x11e418 ldr r1, [sp, #0x40] */
/* @0x11e41c ldr r2, [sp, #0x34] */
/* @0x11e420 ldr r3, [sp, #0x38] */
/* @0x11e424 str r0, [sp, #0x28] */
/* @0x11e428 mov r0, r5 */
/* @0x11e42c bl 0xc2238 <_ZN11CBackground11DrawGeneralEfffffffffjjjjf> */
/* @0x11e430 add sp, sp, #84 */
/* @0x11e434 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11e438 ldr r0, [pc, #0x14] */
/* @0x11e43c mov r1, #0 */
/* @0x11e440 add r0, pc, r0 */
/* @0x11e444 add sp, sp, #84 */
/* @0x11e448 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11e44c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11e450 .word 0x002cf7b4 */
/* @0x11e454 mlaeq r1, r4, sp, r11 */

/* ── FUNC 0x11e458 · F_DrawBackgroundStretched(RValue&, CInstance*, CInstance*, int, RValue*) · size=332 · insn=83 */
/* @0x11e458 ldr r3, [pc, #0x13c] */
/* @0x11e45c push {r4, r5, r6, r7, r8, lr} */
/* @0x11e460 ldr r3, [pc, r3] */
/* @0x11e464 sub sp, sp, #16 */
/* @0x11e468 ldrb r1, [r3] */
/* @0x11e46c ldr r4, [sp, #0x28] */
/* @0x11e470 cmp r1, #0 */
/* @0x11e474 mov r0, r4 */
/* @0x11e478 beq 0x11e504 <_Z25F_DrawBackgroundStretchedR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x11e47c mov r1, #0 */
/* @0x11e480 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e484 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11e488 subs r5, r0, #0 */
/* @0x11e48c beq 0x11e584 <_Z25F_DrawBackgroundStretchedR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x11e490 mov r0, r4 */
/* @0x11e494 mov r1, #1 */
/* @0x11e498 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e49c mov r1, #2 */
/* @0x11e4a0 mov r7, r0 */
/* @0x11e4a4 mov r0, r4 */
/* @0x11e4a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e4ac mov r1, #3 */
/* @0x11e4b0 mov r6, r0 */
/* @0x11e4b4 mov r0, r4 */
/* @0x11e4b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e4bc mov r1, #4 */
/* @0x11e4c0 mov r8, r0 */
/* @0x11e4c4 mov r0, r4 */
/* @0x11e4c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e4cc mov r4, r0 */
/* @0x11e4d0 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11e4d4 mvn r12, #-16777216 */
/* @0x11e4d8 str r8, [sp] */
/* @0x11e4dc str r4, [sp, #0x4] */
/* @0x11e4e0 mov r2, r7 */
/* @0x11e4e4 mov r3, r6 */
/* @0x11e4e8 mov r1, #0 */
/* @0x11e4ec str r12, [sp, #0x8] */
/* @0x11e4f0 str r0, [sp, #0xc] */
/* @0x11e4f4 mov r0, r5 */
/* @0x11e4f8 bl 0x1ecdc4 <_ZN7CSprite13DrawStretchedEiffffjf> */
/* @0x11e4fc add sp, sp, #16 */
/* @0x11e500 pop {r4, r5, r6, r7, r8, pc} */
/* @0x11e504 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e508 bl 0xc3794 <_Z15Background_Datai> */
/* @0x11e50c subs r5, r0, #0 */
/* @0x11e510 beq 0x11e584 <_Z25F_DrawBackgroundStretchedR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x11e514 mov r0, r4 */
/* @0x11e518 mov r1, #1 */
/* @0x11e51c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e520 mov r1, #2 */
/* @0x11e524 mov r8, r0 */
/* @0x11e528 mov r0, r4 */
/* @0x11e52c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e530 mov r1, #3 */
/* @0x11e534 mov r7, r0 */
/* @0x11e538 mov r0, r4 */
/* @0x11e53c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e540 mov r1, #4 */
/* @0x11e544 mov r6, r0 */
/* @0x11e548 mov r0, r4 */
/* @0x11e54c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e550 mov r4, r0 */
/* @0x11e554 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11e558 mvn r12, #-16777216 */
/* @0x11e55c str r4, [sp] */
/* @0x11e560 mov r1, r8 */
/* @0x11e564 mov r2, r7 */
/* @0x11e568 mov r3, r6 */
/* @0x11e56c str r12, [sp, #0x4] */
/* @0x11e570 str r0, [sp, #0x8] */
/* @0x11e574 mov r0, r5 */
/* @0x11e578 bl 0xc2094 <_ZN11CBackground13DrawStretchedEffffjf> */
/* @0x11e57c add sp, sp, #16 */
/* @0x11e580 pop {r4, r5, r6, r7, r8, pc} */
/* @0x11e584 ldr r0, [pc, #0x14] */
/* @0x11e588 mov r1, #0 */
/* @0x11e58c add r0, pc, r0 */
/* @0x11e590 add sp, sp, #16 */
/* @0x11e594 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11e598 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11e59c eoreq pc, r12, r4, asr #9 */
/* @0x11e5a0 eoreq r11, r1, r8, asr #24 */

/* ── FUNC 0x11e5a4 · F_DrawBackgroundStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=372 · insn=93 */
/* @0x11e5a4 ldr r3, [pc, #0x164] */
/* @0x11e5a8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11e5ac ldr r3, [pc, r3] */
/* @0x11e5b0 sub sp, sp, #16 */
/* @0x11e5b4 ldrb r1, [r3] */
/* @0x11e5b8 ldr r4, [sp, #0x30] */
/* @0x11e5bc cmp r1, #0 */
/* @0x11e5c0 mov r0, r4 */
/* @0x11e5c4 beq 0x11e664 <_Z28F_DrawBackgroundStretchedExtR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x11e5c8 mov r1, #0 */
/* @0x11e5cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e5d0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11e5d4 subs r5, r0, #0 */
/* @0x11e5d8 beq 0x11e6f8 <_Z28F_DrawBackgroundStretchedExtR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x11e5dc mov r0, r4 */
/* @0x11e5e0 mov r1, #1 */
/* @0x11e5e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e5e8 mov r1, #2 */
/* @0x11e5ec mov r7, r0 */
/* @0x11e5f0 mov r0, r4 */
/* @0x11e5f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e5f8 mov r1, #3 */
/* @0x11e5fc mov r6, r0 */
/* @0x11e600 mov r0, r4 */
/* @0x11e604 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e608 mov r1, #4 */
/* @0x11e60c mov r10, r0 */
/* @0x11e610 mov r0, r4 */
/* @0x11e614 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e618 mov r1, #5 */
/* @0x11e61c mov r9, r0 */
/* @0x11e620 mov r0, r4 */
/* @0x11e624 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e628 mov r1, #6 */
/* @0x11e62c mov r8, r0 */
/* @0x11e630 mov r0, r4 */
/* @0x11e634 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e638 str r10, [sp] */
/* @0x11e63c str r9, [sp, #0x4] */
/* @0x11e640 mov r2, r7 */
/* @0x11e644 str r8, [sp, #0x8] */
/* @0x11e648 mov r1, #0 */
/* @0x11e64c mov r3, r6 */
/* @0x11e650 str r0, [sp, #0xc] */
/* @0x11e654 mov r0, r5 */
/* @0x11e658 bl 0x1ecdc4 <_ZN7CSprite13DrawStretchedEiffffjf> */
/* @0x11e65c add sp, sp, #16 */
/* @0x11e660 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11e664 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e668 bl 0xc3794 <_Z15Background_Datai> */
/* @0x11e66c subs r5, r0, #0 */
/* @0x11e670 beq 0x11e6f8 <_Z28F_DrawBackgroundStretchedExtR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x11e674 mov r0, r4 */
/* @0x11e678 mov r1, #1 */
/* @0x11e67c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e680 mov r1, #2 */
/* @0x11e684 mov r8, r0 */
/* @0x11e688 mov r0, r4 */
/* @0x11e68c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e690 mov r1, #3 */
/* @0x11e694 mov r7, r0 */
/* @0x11e698 mov r0, r4 */
/* @0x11e69c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e6a0 mov r1, #4 */
/* @0x11e6a4 mov r6, r0 */
/* @0x11e6a8 mov r0, r4 */
/* @0x11e6ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e6b0 mov r1, #5 */
/* @0x11e6b4 mov r10, r0 */
/* @0x11e6b8 mov r0, r4 */
/* @0x11e6bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e6c0 mov r1, #6 */
/* @0x11e6c4 mov r9, r0 */
/* @0x11e6c8 mov r0, r4 */
/* @0x11e6cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e6d0 str r10, [sp] */
/* @0x11e6d4 str r9, [sp, #0x4] */
/* @0x11e6d8 mov r1, r8 */
/* @0x11e6dc mov r2, r7 */
/* @0x11e6e0 mov r3, r6 */
/* @0x11e6e4 str r0, [sp, #0x8] */
/* @0x11e6e8 mov r0, r5 */
/* @0x11e6ec bl 0xc2094 <_ZN11CBackground13DrawStretchedEffffjf> */
/* @0x11e6f0 add sp, sp, #16 */
/* @0x11e6f4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11e6f8 ldr r0, [pc, #0x14] */
/* @0x11e6fc mov r1, #0 */
/* @0x11e700 add r0, pc, r0 */
/* @0x11e704 add sp, sp, #16 */
/* @0x11e708 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11e70c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11e710 eoreq pc, r12, r8, ror r3 */
/* @0x11e714 .word 0x0021bad4 */

/* ── FUNC 0x11e718 · F_TileDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x11e718 push {r3, r4, r5, lr} */
/* @0x11e71c mov r1, #0 */
/* @0x11e720 ldr r4, [pc, #0x40] */
/* @0x11e724 ldr r0, [sp, #0x10] */
/* @0x11e728 ldr r4, [pc, r4] */
/* @0x11e72c ldr r5, [r4] */
/* @0x11e730 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e734 mov r1, r0 */
/* @0x11e738 mov r0, r5 */
/* @0x11e73c bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x11e740 subs r1, r0, #0 */
/* @0x11e744 blt 0x11e754 <_Z12F_TileDeleteR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x11e748 ldr r0, [r4] */
/* @0x11e74c pop {r3, r4, r5, lr} */
/* @0x11e750 b 0x1af35c <_ZN5CRoom10DeleteTileEi> */
/* @0x11e754 ldr r0, [pc, #0x10] */
/* @0x11e758 mov r1, #0 */
/* @0x11e75c pop {r3, r4, r5, lr} */
/* @0x11e760 add r0, pc, r0 */
/* @0x11e764 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11e768 eoreq pc, r12, r0, lsl #4 */
/* @0x11e76c mlaeq r1, r12, r10, r11 */

/* ── FUNC 0x11e770 · F_SurfaceResize(RValue&, CInstance*, CInstance*, int, RValue*) · size=380 · insn=95 */
/* @0x11e770 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11e774 mov r1, #0 */
/* @0x11e778 ldr r4, [sp, #0x20] */
/* @0x11e77c mov r9, r0 */
/* @0x11e780 ldr r5, [pc, #0x13c] */
/* @0x11e784 mov r0, r4 */
/* @0x11e788 add r5, pc, r5 */
/* @0x11e78c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e790 mov r1, #1 */
/* @0x11e794 mov r8, r0 */
/* @0x11e798 mov r0, r4 */
/* @0x11e79c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e7a0 mov r1, #2 */
/* @0x11e7a4 mov r6, r0 */
/* @0x11e7a8 mov r0, r4 */
/* @0x11e7ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e7b0 sub r12, r6, #1 */
/* @0x11e7b4 sub r4, r0, #1 */
/* @0x11e7b8 mov r7, r0 */
/* @0x11e7bc cmp r12, #8192 */
/* @0x11e7c0 cmplo r4, #8192 */
/* @0x11e7c4 movlo r4, #0 */
/* @0x11e7c8 movhs r4, #1 */
/* @0x11e7cc bhs 0x11e864 <_Z15F_SurfaceResizeR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x11e7d0 ldr r3, [pc, #0xf0] */
/* @0x11e7d4 ldr r3, [r5, r3] */
/* @0x11e7d8 ldr r3, [r3] */
/* @0x11e7dc cmp r8, r3 */
/* @0x11e7e0 beq 0x11e878 <_Z15F_SurfaceResizeR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x11e7e4 mov r0, r8 */
/* @0x11e7e8 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11e7ec subs r1, r0, #0 */
/* @0x11e7f0 beq 0x11e8b4 <_Z15F_SurfaceResizeR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x11e7f4 mov r0, r8 */
/* @0x11e7f8 mov r1, r6 */
/* @0x11e7fc mov r2, r7 */
/* @0x11e800 bl 0x171b68 <_Z17GR_Surface_Resizeiii> */
/* @0x11e804 cmp r0, #0 */
/* @0x11e808 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11e80c ldr r2, [pc, #0xb8] */
/* @0x11e810 mov r3, #0 */
/* @0x11e814 str r4, [r9] */
/* @0x11e818 movt r3, #0x3ff0 */
/* @0x11e81c str r3, [r9, #0x4] */
/* @0x11e820 ldr r3, [r5, r2] */
/* @0x11e824 ldrb r3, [r3] */
/* @0x11e828 cmp r3, #0 */
/* @0x11e82c popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11e830 ldr r3, [pc, #0x98] */
/* @0x11e834 ldr r3, [r5, r3] */
/* @0x11e838 ldr r3, [r3] */
/* @0x11e83c cmp r3, #0 */
/* @0x11e840 popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11e844 ldr r1, [pc, #0x88] */
/* @0x11e848 mov r2, r6 */
/* @0x11e84c str r8, [sp, #0x20] */
/* @0x11e850 mov r3, r7 */
/* @0x11e854 mov r0, #4 */
/* @0x11e858 add r1, pc, r1 */
/* @0x11e85c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11e860 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x11e864 ldr r0, [pc, #0x6c] */
/* @0x11e868 mov r1, #0 */
/* @0x11e86c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11e870 add r0, pc, r0 */
/* @0x11e874 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11e878 ldr r0, [pc, #0x5c] */
/* @0x11e87c mov r12, #1 */
/* @0x11e880 ldr r1, [pc, #0x58] */
/* @0x11e884 mov r3, #0 */
/* @0x11e888 ldr r2, [pc, #0x54] */
/* @0x11e88c movt r3, #0x3ff0 */
/* @0x11e890 ldr r0, [r5, r0] */
/* @0x11e894 strb r12, [r0] */
/* @0x11e898 ldr r1, [r5, r1] */
/* @0x11e89c str r6, [r1] */
/* @0x11e8a0 ldr r2, [r5, r2] */
/* @0x11e8a4 str r3, [r9, #0x4] */
/* @0x11e8a8 str r7, [r2] */
/* @0x11e8ac str r4, [r9] */
/* @0x11e8b0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11e8b4 ldr r0, [pc, #0x2c] */
/* @0x11e8b8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11e8bc add r0, pc, r0 */
/* @0x11e8c0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11e8c4 eoreq r3, sp, r8, asr #9 */
/* @0x11e8c8 .word 0xffffc988 */
/* @0x11e8cc .word 0xffffbcd4 */
/* @0x11e8d0 .word 0xffffc7d0 */
/* @0x11e8d4 .word 0x0021b9f0 */
/* @0x11e8d8 eoreq r11, r1, r4, lsr #19 */
/* @0x11e8dc .word 0xffffc98c */
/* @0x11e8e0 .word 0xffffc990 */
/* @0x11e8e4 .word 0xffffc994 */
/* @0x11e8e8 eoreq r11, r1, r4, ror r9 */

/* ── FUNC 0x11e8ec · F_DrawSurface(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x11e8ec push {r4, r5, r6, lr} */
/* @0x11e8f0 mov r1, #0 */
/* @0x11e8f4 ldr r4, [sp, #0x10] */
/* @0x11e8f8 mov r0, r4 */
/* @0x11e8fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e900 mov r5, r0 */
/* @0x11e904 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11e908 subs r1, r0, #0 */
/* @0x11e90c beq 0x11e940 <_Z13F_DrawSurfaceR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x11e910 mov r0, r4 */
/* @0x11e914 mov r1, #1 */
/* @0x11e918 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e91c mov r1, #2 */
/* @0x11e920 mov r6, r0 */
/* @0x11e924 mov r0, r4 */
/* @0x11e928 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e92c mov r1, r6 */
/* @0x11e930 mov r2, r0 */
/* @0x11e934 mov r0, r5 */
/* @0x11e938 pop {r4, r5, r6, lr} */
/* @0x11e93c b 0x171d90 <_Z21GR_Surface_DrawSimpleiff> */
/* @0x11e940 ldr r0, [pc, #0x8] */
/* @0x11e944 pop {r4, r5, r6, lr} */
/* @0x11e948 add r0, pc, r0 */
/* @0x11e94c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11e950 eoreq r11, r1, r0, lsr #18 */

/* ── FUNC 0x11e954 · F_DrawSurfaceExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x11e954 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11e958 sub sp, sp, #20 */
/* @0x11e95c mov r1, #0 */
/* @0x11e960 ldr r4, [sp, #0x38] */
/* @0x11e964 mov r0, r4 */
/* @0x11e968 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e96c mov r5, r0 */
/* @0x11e970 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11e974 subs r1, r0, #0 */
/* @0x11e978 beq 0x11ea14 <_Z16F_DrawSurfaceExtR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x11e97c mov r0, r4 */
/* @0x11e980 mov r1, #1 */
/* @0x11e984 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e988 mov r1, #2 */
/* @0x11e98c mov r8, r0 */
/* @0x11e990 mov r0, r4 */
/* @0x11e994 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e998 mov r1, #3 */
/* @0x11e99c mov r7, r0 */
/* @0x11e9a0 mov r0, r4 */
/* @0x11e9a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e9a8 mov r1, #4 */
/* @0x11e9ac mov r6, r0 */
/* @0x11e9b0 mov r0, r4 */
/* @0x11e9b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e9b8 mov r1, #5 */
/* @0x11e9bc mov r11, r0 */
/* @0x11e9c0 mov r0, r4 */
/* @0x11e9c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e9c8 mov r1, #6 */
/* @0x11e9cc mov r10, r0 */
/* @0x11e9d0 mov r0, r4 */
/* @0x11e9d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11e9d8 mov r1, #7 */
/* @0x11e9dc mov r9, r0 */
/* @0x11e9e0 mov r0, r4 */
/* @0x11e9e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11e9e8 str r11, [sp] */
/* @0x11e9ec str r10, [sp, #0x4] */
/* @0x11e9f0 mov r1, r8 */
/* @0x11e9f4 str r9, [sp, #0x8] */
/* @0x11e9f8 mov r2, r7 */
/* @0x11e9fc mov r3, r6 */
/* @0x11ea00 str r0, [sp, #0xc] */
/* @0x11ea04 mov r0, r5 */
/* @0x11ea08 bl 0x171dbc <_Z15GR_Surface_Drawifffffjf> */
/* @0x11ea0c add sp, sp, #20 */
/* @0x11ea10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11ea14 ldr r0, [pc, #0xc] */
/* @0x11ea18 add r0, pc, r0 */
/* @0x11ea1c add sp, sp, #20 */
/* @0x11ea20 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11ea24 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11ea28 eoreq r11, r1, r0, asr r8 */

/* ── FUNC 0x11ea2c · F_DrawSurfacePart(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x11ea2c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11ea30 sub sp, sp, #32 */
/* @0x11ea34 mov r1, #0 */
/* @0x11ea38 ldr r4, [sp, #0x40] */
/* @0x11ea3c mov r0, r4 */
/* @0x11ea40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ea44 mov r1, #1 */
/* @0x11ea48 mov r5, r0 */
/* @0x11ea4c mov r0, r4 */
/* @0x11ea50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ea54 mov r1, #2 */
/* @0x11ea58 mov r8, r0 */
/* @0x11ea5c mov r0, r4 */
/* @0x11ea60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ea64 mov r1, #3 */
/* @0x11ea68 mov r7, r0 */
/* @0x11ea6c mov r0, r4 */
/* @0x11ea70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ea74 mov r1, #4 */
/* @0x11ea78 mov r6, r0 */
/* @0x11ea7c mov r0, r4 */
/* @0x11ea80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ea84 mov r1, #5 */
/* @0x11ea88 mov r10, r0 */
/* @0x11ea8c mov r0, r4 */
/* @0x11ea90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ea94 mov r1, #6 */
/* @0x11ea98 mov r9, r0 */
/* @0x11ea9c mov r0, r4 */
/* @0x11eaa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eaa4 mov r4, r0 */
/* @0x11eaa8 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11eaac mov r12, #1065353216 */
/* @0x11eab0 mov r1, r8 */
/* @0x11eab4 mvn lr, #-16777216 */
/* @0x11eab8 str r10, [sp] */
/* @0x11eabc str r9, [sp, #0x4] */
/* @0x11eac0 mov r2, r7 */
/* @0x11eac4 str r4, [sp, #0x8] */
/* @0x11eac8 mov r3, r6 */
/* @0x11eacc str lr, [sp, #0x14] */
/* @0x11ead0 str r12, [sp, #0xc] */
/* @0x11ead4 str r12, [sp, #0x10] */
/* @0x11ead8 str r0, [sp, #0x18] */
/* @0x11eadc mov r0, r5 */
/* @0x11eae0 bl 0x171ee0 <_Z27YYGML_draw_surface_part_extiffffffffif> */
/* @0x11eae4 subs r1, r0, #0 */
/* @0x11eae8 beq 0x11eaf4 <_Z17F_DrawSurfacePartR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x11eaec add sp, sp, #32 */
/* @0x11eaf0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11eaf4 ldr r0, [pc, #0xc] */
/* @0x11eaf8 add r0, pc, r0 */
/* @0x11eafc add sp, sp, #32 */
/* @0x11eb00 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11eb04 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11eb08 eoreq r11, r1, r0, ror r7 */
