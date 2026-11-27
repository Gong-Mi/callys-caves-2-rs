/* libyoyo.so 覆盖卡组 0061
 * 函数 0x12cf28..0x12dc40，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x12cf28 · F_FontAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x12cf28 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12cf2c sub sp, sp, #8 */
/* @0x12cf30 mov r5, r0 */
/* @0x12cf34 mov r1, #0 */
/* @0x12cf38 ldr r4, [sp, #0x28] */
/* @0x12cf3c str r1, [r0, #0xc] */
/* @0x12cf40 mov r0, r4 */
/* @0x12cf44 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12cf48 mov r1, #1 */
/* @0x12cf4c mov r6, r0 */
/* @0x12cf50 mov r0, r4 */
/* @0x12cf54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cf58 mov r1, #2 */
/* @0x12cf5c mov r9, r0 */
/* @0x12cf60 mov r0, r4 */
/* @0x12cf64 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12cf68 mov r1, #3 */
/* @0x12cf6c mov r8, r0 */
/* @0x12cf70 mov r0, r4 */
/* @0x12cf74 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12cf78 mov r1, #4 */
/* @0x12cf7c mov r7, r0 */
/* @0x12cf80 mov r0, r4 */
/* @0x12cf84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cf88 mov r1, #5 */
/* @0x12cf8c mov r10, r0 */
/* @0x12cf90 mov r0, r4 */
/* @0x12cf94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cf98 mov r1, r9 */
/* @0x12cf9c mov r2, r8 */
/* @0x12cfa0 mov r3, r7 */
/* @0x12cfa4 str r10, [sp] */
/* @0x12cfa8 str r0, [sp, #0x4] */
/* @0x12cfac mov r0, r6 */
/* @0x12cfb0 bl 0xfa43c <_Z8Font_AddPKcibbii> */
/* @0x12cfb4 vmov s15, r0 */
/* @0x12cfb8 vcvt.f64.s32 d7, s15 */
/* @0x12cfbc vmov r0, r1, d7 */
/* @0x12cfc0 vmov r2, s14 */
/* @0x12cfc4 mov r3, r1 */
/* @0x12cfc8 stm r5, {r2, r3} */
/* @0x12cfcc add sp, sp, #8 */
/* @0x12cfd0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x12cfd4 · F_FontAddSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x12cfd4 push {r4, r5, r6, r7, r8, lr} */
/* @0x12cfd8 mov r1, #0 */
/* @0x12cfdc ldr r5, [sp, #0x18] */
/* @0x12cfe0 mov r4, r0 */
/* @0x12cfe4 mov r0, r5 */
/* @0x12cfe8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12cfec mov r6, r0 */
/* @0x12cff0 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x12cff4 subs r1, r0, #0 */
/* @0x12cff8 beq 0x12d058 <_Z15F_FontAddSpriteR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12cffc mov r1, #1 */
/* @0x12d000 mov r0, r5 */
/* @0x12d004 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d008 mov r1, #2 */
/* @0x12d00c mov r8, r0 */
/* @0x12d010 mov r0, r5 */
/* @0x12d014 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12d018 mov r1, #3 */
/* @0x12d01c mov r7, r0 */
/* @0x12d020 mov r0, r5 */
/* @0x12d024 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d028 mov r2, r7 */
/* @0x12d02c mov r1, r8 */
/* @0x12d030 mov r3, r0 */
/* @0x12d034 mov r0, r6 */
/* @0x12d038 bl 0xfa5ac <_Z14Font_AddSpriteiibi> */
/* @0x12d03c vmov s15, r0 */
/* @0x12d040 vcvt.f64.s32 d7, s15 */
/* @0x12d044 vmov r2, r3, d7 */
/* @0x12d048 mov r1, #0 */
/* @0x12d04c stm r4, {r2, r3} */
/* @0x12d050 str r1, [r4, #0xc] */
/* @0x12d054 pop {r4, r5, r6, r7, r8, pc} */
/* @0x12d058 ldr r0, [pc, #0x14] */
/* @0x12d05c add r0, pc, r0 */
/* @0x12d060 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12d064 mov r3, #0 */
/* @0x12d068 mov r2, #0 */
/* @0x12d06c movt r3, #0xbff0 */
/* @0x12d070 b 0x12d048 <_Z15F_FontAddSpriteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12d074 eoreq r0, r1, r4, ror #9 */

/* ── FUNC 0x12d078 · F_FontAddSpriteExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x12d078 push {r4, r5, r6, r7, r8, lr} */
/* @0x12d07c mov r1, #0 */
/* @0x12d080 ldr r5, [sp, #0x18] */
/* @0x12d084 mov r4, r0 */
/* @0x12d088 mov r0, r5 */
/* @0x12d08c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d090 mov r6, r0 */
/* @0x12d094 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x12d098 subs r1, r0, #0 */
/* @0x12d09c beq 0x12d0fc <_Z18F_FontAddSpriteExtR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12d0a0 mov r1, #1 */
/* @0x12d0a4 mov r0, r5 */
/* @0x12d0a8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12d0ac mov r1, #2 */
/* @0x12d0b0 mov r8, r0 */
/* @0x12d0b4 mov r0, r5 */
/* @0x12d0b8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12d0bc mov r1, #3 */
/* @0x12d0c0 mov r7, r0 */
/* @0x12d0c4 mov r0, r5 */
/* @0x12d0c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d0cc mov r2, r7 */
/* @0x12d0d0 mov r1, r8 */
/* @0x12d0d4 mov r3, r0 */
/* @0x12d0d8 mov r0, r6 */
/* @0x12d0dc bl 0xfa7a8 <_Z17Font_AddSpriteExtiPKcbi> */
/* @0x12d0e0 vmov s15, r0 */
/* @0x12d0e4 vcvt.f64.s32 d7, s15 */
/* @0x12d0e8 vmov r2, r3, d7 */
/* @0x12d0ec mov r1, #0 */
/* @0x12d0f0 stm r4, {r2, r3} */
/* @0x12d0f4 str r1, [r4, #0xc] */
/* @0x12d0f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x12d0fc ldr r0, [pc, #0x14] */
/* @0x12d100 add r0, pc, r0 */
/* @0x12d104 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12d108 mov r3, #0 */
/* @0x12d10c mov r2, #0 */
/* @0x12d110 movt r3, #0xbff0 */
/* @0x12d114 b 0x12d0ec <_Z18F_FontAddSpriteExtR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12d118 eoreq r0, r1, r0, asr #8 */

/* ── FUNC 0x12d11c · F_FontReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0x12d11c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x12d120 sub sp, sp, #12 */
/* @0x12d124 mov r1, #0 */
/* @0x12d128 mov r5, r0 */
/* @0x12d12c ldr r4, [sp, #0x28] */
/* @0x12d130 mov r0, r4 */
/* @0x12d134 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d138 mov r1, #1 */
/* @0x12d13c mov r6, r0 */
/* @0x12d140 mov r0, r4 */
/* @0x12d144 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d148 mov r8, r0 */
/* @0x12d14c mov r0, r6 */
/* @0x12d150 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x12d154 subs r1, r0, #0 */
/* @0x12d158 beq 0x12d204 <_Z19F_FontReplaceSpriteR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x12d15c mov r0, r6 */
/* @0x12d160 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x12d164 subs r7, r0, #0 */
/* @0x12d168 bne 0x12d198 <_Z19F_FontReplaceSpriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x12d16c ldr r0, [pc, #0xa0] */
/* @0x12d170 mov r1, r7 */
/* @0x12d174 add r0, pc, r0 */
/* @0x12d178 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12d17c str r7, [r5, #0xc] */
/* @0x12d180 mov r3, #0 */
/* @0x12d184 str r3, [r5] */
/* @0x12d188 mov r2, r3 */
/* @0x12d18c str r2, [r5, #0x4] */
/* @0x12d190 add sp, sp, #12 */
/* @0x12d194 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x12d198 mov r1, #2 */
/* @0x12d19c mov r0, r4 */
/* @0x12d1a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d1a4 mov r1, #3 */
/* @0x12d1a8 mov r9, r0 */
/* @0x12d1ac mov r0, r4 */
/* @0x12d1b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12d1b4 mov r1, #4 */
/* @0x12d1b8 mov r7, r0 */
/* @0x12d1bc mov r0, r4 */
/* @0x12d1c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d1c4 mov r2, r9 */
/* @0x12d1c8 mov r3, r7 */
/* @0x12d1cc mov r1, r8 */
/* @0x12d1d0 str r0, [sp] */
/* @0x12d1d4 mov r0, r6 */
/* @0x12d1d8 bl 0xfa9c4 <_Z18Font_ReplaceSpriteiiibi> */
/* @0x12d1dc mov r3, #0 */
/* @0x12d1e0 str r3, [r5, #0xc] */
/* @0x12d1e4 cmp r0, r3 */
/* @0x12d1e8 movne r2, #0 */
/* @0x12d1ec movtne r2, #0x3ff0 */
/* @0x12d1f0 beq 0x12d180 <_Z19F_FontReplaceSpriteR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12d1f4 str r3, [r5] */
/* @0x12d1f8 str r2, [r5, #0x4] */
/* @0x12d1fc add sp, sp, #12 */
/* @0x12d200 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x12d204 ldr r0, [pc, #0xc] */
/* @0x12d208 add r0, pc, r0 */
/* @0x12d20c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12d210 b 0x12d15c <_Z19F_FontReplaceSpriteR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12d214 eoreq r0, r1, r4, lsr #8 */
/* @0x12d218 eoreq r0, r1, r8, ror #6 */

/* ── FUNC 0x12d21c · F_FontReplaceSpriteExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0x12d21c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x12d220 sub sp, sp, #12 */
/* @0x12d224 mov r1, #0 */
/* @0x12d228 mov r5, r0 */
/* @0x12d22c ldr r4, [sp, #0x28] */
/* @0x12d230 mov r0, r4 */
/* @0x12d234 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d238 mov r1, #1 */
/* @0x12d23c mov r6, r0 */
/* @0x12d240 mov r0, r4 */
/* @0x12d244 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d248 mov r8, r0 */
/* @0x12d24c mov r0, r6 */
/* @0x12d250 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x12d254 subs r1, r0, #0 */
/* @0x12d258 beq 0x12d304 <_Z22F_FontReplaceSpriteExtR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x12d25c mov r0, r6 */
/* @0x12d260 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x12d264 subs r7, r0, #0 */
/* @0x12d268 bne 0x12d298 <_Z22F_FontReplaceSpriteExtR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x12d26c ldr r0, [pc, #0xa0] */
/* @0x12d270 mov r1, r7 */
/* @0x12d274 add r0, pc, r0 */
/* @0x12d278 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12d27c str r7, [r5, #0xc] */
/* @0x12d280 mov r3, #0 */
/* @0x12d284 str r3, [r5] */
/* @0x12d288 mov r2, r3 */
/* @0x12d28c str r2, [r5, #0x4] */
/* @0x12d290 add sp, sp, #12 */
/* @0x12d294 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x12d298 mov r1, #2 */
/* @0x12d29c mov r0, r4 */
/* @0x12d2a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12d2a4 mov r1, #3 */
/* @0x12d2a8 mov r9, r0 */
/* @0x12d2ac mov r0, r4 */
/* @0x12d2b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12d2b4 mov r1, #4 */
/* @0x12d2b8 mov r7, r0 */
/* @0x12d2bc mov r0, r4 */
/* @0x12d2c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d2c4 mov r2, r9 */
/* @0x12d2c8 mov r3, r7 */
/* @0x12d2cc mov r1, r8 */
/* @0x12d2d0 str r0, [sp] */
/* @0x12d2d4 mov r0, r6 */
/* @0x12d2d8 bl 0xfab0c <_Z21Font_ReplaceSpriteExtiiPKcbi> */
/* @0x12d2dc mov r3, #0 */
/* @0x12d2e0 str r3, [r5, #0xc] */
/* @0x12d2e4 cmp r0, r3 */
/* @0x12d2e8 movne r2, #0 */
/* @0x12d2ec movtne r2, #0x3ff0 */
/* @0x12d2f0 beq 0x12d280 <_Z22F_FontReplaceSpriteExtR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12d2f4 str r3, [r5] */
/* @0x12d2f8 str r2, [r5, #0x4] */
/* @0x12d2fc add sp, sp, #12 */
/* @0x12d300 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x12d304 ldr r0, [pc, #0xc] */
/* @0x12d308 add r0, pc, r0 */
/* @0x12d30c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12d310 b 0x12d25c <_Z22F_FontReplaceSpriteExtR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12d314 eoreq r0, r1, r4, lsr #6 */
/* @0x12d318 eoreq r0, r1, r8, ror #4 */

/* ── FUNC 0x12d31c · F_FontDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x12d31c push {r4, r5, r6, lr} */
/* @0x12d320 mov r1, #0 */
/* @0x12d324 mov r4, r0 */
/* @0x12d328 ldr r0, [sp, #0x10] */
/* @0x12d32c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d330 mov r6, r0 */
/* @0x12d334 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x12d338 subs r5, r0, #0 */
/* @0x12d33c bne 0x12d368 <_Z12F_FontDeleteR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12d340 ldr r0, [pc, #0x44] */
/* @0x12d344 mov r1, r5 */
/* @0x12d348 add r0, pc, r0 */
/* @0x12d34c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12d350 str r5, [r4, #0xc] */
/* @0x12d354 mov r3, #0 */
/* @0x12d358 mov r2, r3 */
/* @0x12d35c str r3, [r4] */
/* @0x12d360 str r2, [r4, #0x4] */
/* @0x12d364 pop {r4, r5, r6, pc} */
/* @0x12d368 mov r0, r6 */
/* @0x12d36c bl 0xfabb8 <_Z11Font_Deletei> */
/* @0x12d370 mov r3, #0 */
/* @0x12d374 str r3, [r4, #0xc] */
/* @0x12d378 cmp r0, r3 */
/* @0x12d37c movne r2, #0 */
/* @0x12d380 movtne r2, #0x3ff0 */
/* @0x12d384 bne 0x12d35c <_Z12F_FontDeleteR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12d388 b 0x12d354 <_Z12F_FontDeleteR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x12d38c eoreq r0, r1, r4, lsl #5 */

/* ── FUNC 0x12d390 · F_PathExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x12d390 push {r3, r4, r5, lr} */
/* @0x12d394 mov r5, #0 */
/* @0x12d398 mov r4, r0 */
/* @0x12d39c mov r1, r5 */
/* @0x12d3a0 str r5, [r0, #0xc] */
/* @0x12d3a4 ldr r0, [sp, #0x10] */
/* @0x12d3a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d3ac bl 0x1a8008 <_Z11Path_Existsi> */
/* @0x12d3b0 cmp r0, #0 */
/* @0x12d3b4 moveq r5, r0 */
/* @0x12d3b8 movne r3, r5 */
/* @0x12d3bc moveq r3, r5 */
/* @0x12d3c0 movtne r3, #0x3ff0 */
/* @0x12d3c4 str r5, [r4] */
/* @0x12d3c8 str r3, [r4, #0x4] */
/* @0x12d3cc pop {r3, r4, r5, pc} */

/* ── FUNC 0x12d3d0 · F_PathGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x12d3d0 push {r4, lr} */
/* @0x12d3d4 mov r1, #0 */
/* @0x12d3d8 mov r4, r0 */
/* @0x12d3dc ldr r0, [sp, #0x8] */
/* @0x12d3e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d3e4 bl 0x1a8050 <_Z9Path_Namei> */
/* @0x12d3e8 mov r1, r0 */
/* @0x12d3ec mov r0, r4 */
/* @0x12d3f0 pop {r4, lr} */
/* @0x12d3f4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12d3f8 · F_PathGetLength(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12d3f8 push {r4, lr} */
/* @0x12d3fc mov r1, #0 */
/* @0x12d400 mov r4, r0 */
/* @0x12d404 ldr r0, [sp, #0x8] */
/* @0x12d408 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d40c bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d410 cmp r0, #0 */
/* @0x12d414 beq 0x12d438 <_Z15F_PathGetLengthR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12d418 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv> */
/* @0x12d41c vmov s15, r0 */
/* @0x12d420 vcvt.f64.f32 d7, s15 */
/* @0x12d424 vmov r2, r3, d7 */
/* @0x12d428 mov r1, #0 */
/* @0x12d42c stm r4, {r2, r3} */
/* @0x12d430 str r1, [r4, #0xc] */
/* @0x12d434 pop {r4, pc} */
/* @0x12d438 mov r3, #0 */
/* @0x12d43c mov r2, #0 */
/* @0x12d440 movt r3, #0xbff0 */
/* @0x12d444 b 0x12d428 <_Z15F_PathGetLengthR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12d448 · F_PathGetTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x12d448 push {r3, r4, r5, lr} */
/* @0x12d44c vpush {d8} */
/* @0x12d450 mov r1, #0 */
/* @0x12d454 ldr r5, [sp, #0x18] */
/* @0x12d458 mov r4, r0 */
/* @0x12d45c mov r0, r5 */
/* @0x12d460 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d464 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d468 cmp r0, #0 */
/* @0x12d46c beq 0x12d4a8 <_Z13F_PathGetTimeR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x12d470 bl 0x1a7bc0 <_ZN5CPath11GetPathTimeEv> */
/* @0x12d474 mov r1, #1 */
/* @0x12d478 vmov s16, r0 */
/* @0x12d47c mov r0, r5 */
/* @0x12d480 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12d484 vmov s14, r0 */
/* @0x12d488 vmul.f32 s16, s16, s14 */
/* @0x12d48c vcvt.f64.f32 d7, s16 */
/* @0x12d490 vmov r2, r3, d7 */
/* @0x12d494 stm r4, {r2, r3} */
/* @0x12d498 mov r1, #0 */
/* @0x12d49c vpop {d8} */
/* @0x12d4a0 str r1, [r4, #0xc] */
/* @0x12d4a4 pop {r3, r4, r5, pc} */
/* @0x12d4a8 mov r3, #0 */
/* @0x12d4ac mov r2, #0 */
/* @0x12d4b0 movt r3, #0xbff0 */
/* @0x12d4b4 b 0x12d494 <_Z13F_PathGetTimeR6RValueP9CInstanceS2_iPS_+0x4c> */

/* ── FUNC 0x12d4b8 · F_SpriteSetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x12d4b8 push {r4, r5, r6, lr} */
/* @0x12d4bc mov r1, #0 */
/* @0x12d4c0 ldr r4, [sp, #0x10] */
/* @0x12d4c4 mov r0, r4 */
/* @0x12d4c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d4cc mov r1, #0 */
/* @0x12d4d0 mov r6, r0 */
/* @0x12d4d4 mov r0, r4 */
/* @0x12d4d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d4dc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12d4e0 subs r5, r0, #0 */
/* @0x12d4e4 beq 0x12d50c <_Z16F_SpriteSetSpeedR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x12d4e8 mov r1, #1 */
/* @0x12d4ec mov r0, r4 */
/* @0x12d4f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12d4f4 mov r1, #2 */
/* @0x12d4f8 str r0, [r5, #0x6c] */
/* @0x12d4fc mov r0, r4 */
/* @0x12d500 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d504 str r0, [r5, #0x70] */
/* @0x12d508 pop {r4, r5, r6, pc} */
/* @0x12d50c ldr r3, [pc, #0x20] */
/* @0x12d510 mov r2, r6 */
/* @0x12d514 ldr r1, [pc, #0x1c] */
/* @0x12d518 ldr r3, [pc, r3] */
/* @0x12d51c add r1, pc, r1 */
/* @0x12d520 ldr r0, [r3] */
/* @0x12d524 ldr r3, [r0] */
/* @0x12d528 ldr r3, [r3, #0xc] */
/* @0x12d52c blx r3 */
/* @0x12d530 pop {r4, r5, r6, pc} */
/* @0x12d534 .word 0x002c01fc */
/* @0x12d538 eoreq pc, r0, r4, lsl #31 */

/* ── FUNC 0x12d53c · F_PathGetKind(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12d53c push {r4, lr} */
/* @0x12d540 mov r1, #0 */
/* @0x12d544 mov r4, r0 */
/* @0x12d548 ldr r0, [sp, #0x8] */
/* @0x12d54c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d550 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d554 cmp r0, #0 */
/* @0x12d558 beq 0x12d57c <_Z13F_PathGetKindR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12d55c bl 0x1a7bd0 <_ZN5CPath7GetKindEv> */
/* @0x12d560 vmov s15, r0 */
/* @0x12d564 vcvt.f64.s32 d7, s15 */
/* @0x12d568 vmov r2, r3, d7 */
/* @0x12d56c mov r1, #0 */
/* @0x12d570 stm r4, {r2, r3} */
/* @0x12d574 str r1, [r4, #0xc] */
/* @0x12d578 pop {r4, pc} */
/* @0x12d57c mov r3, #0 */
/* @0x12d580 mov r2, #0 */
/* @0x12d584 movt r3, #0xbff0 */
/* @0x12d588 b 0x12d56c <_Z13F_PathGetKindR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12d58c · F_PathGetClosed(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12d58c push {r4, lr} */
/* @0x12d590 mov r1, #0 */
/* @0x12d594 mov r4, r0 */
/* @0x12d598 ldr r0, [sp, #0x8] */
/* @0x12d59c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d5a0 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d5a4 subs r3, r0, #0 */
/* @0x12d5a8 beq 0x12d5d4 <_Z15F_PathGetClosedR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12d5ac bl 0x1a7bd8 <_ZN5CPath9GetClosedEv> */
/* @0x12d5b0 mov r3, #0 */
/* @0x12d5b4 str r3, [r4, #0xc] */
/* @0x12d5b8 cmp r0, r3 */
/* @0x12d5bc movne r2, #0 */
/* @0x12d5c0 movtne r2, #0x3ff0 */
/* @0x12d5c4 beq 0x12d5d8 <_Z15F_PathGetClosedR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12d5c8 str r3, [r4] */
/* @0x12d5cc str r2, [r4, #0x4] */
/* @0x12d5d0 pop {r4, pc} */
/* @0x12d5d4 str r3, [r4, #0xc] */
/* @0x12d5d8 mov r3, #0 */
/* @0x12d5dc mov r2, r3 */
/* @0x12d5e0 b 0x12d5c8 <_Z15F_PathGetClosedR6RValueP9CInstanceS2_iPS_+0x3c> */

/* ── FUNC 0x12d5e4 · F_PathGetPrecision(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12d5e4 push {r4, lr} */
/* @0x12d5e8 mov r1, #0 */
/* @0x12d5ec mov r4, r0 */
/* @0x12d5f0 ldr r0, [sp, #0x8] */
/* @0x12d5f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d5f8 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d5fc cmp r0, #0 */
/* @0x12d600 beq 0x12d624 <_Z18F_PathGetPrecisionR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12d604 bl 0x1a7be0 <_ZN5CPath12GetPrecisionEv> */
/* @0x12d608 vmov s15, r0 */
/* @0x12d60c vcvt.f64.s32 d7, s15 */
/* @0x12d610 vmov r2, r3, d7 */
/* @0x12d614 mov r1, #0 */
/* @0x12d618 stm r4, {r2, r3} */
/* @0x12d61c str r1, [r4, #0xc] */
/* @0x12d620 pop {r4, pc} */
/* @0x12d624 mov r3, #0 */
/* @0x12d628 mov r2, #0 */
/* @0x12d62c movt r3, #0xbff0 */
/* @0x12d630 b 0x12d614 <_Z18F_PathGetPrecisionR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12d634 · F_PathGetNumber(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12d634 push {r4, lr} */
/* @0x12d638 mov r1, #0 */
/* @0x12d63c mov r4, r0 */
/* @0x12d640 ldr r0, [sp, #0x8] */
/* @0x12d644 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d648 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d64c cmp r0, #0 */
/* @0x12d650 beq 0x12d674 <_Z15F_PathGetNumberR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12d654 bl 0x1a7bc8 <_ZN5CPath8GetCountEv> */
/* @0x12d658 vmov s15, r0 */
/* @0x12d65c vcvt.f64.s32 d7, s15 */
/* @0x12d660 vmov r2, r3, d7 */
/* @0x12d664 mov r1, #0 */
/* @0x12d668 stm r4, {r2, r3} */
/* @0x12d66c str r1, [r4, #0xc] */
/* @0x12d670 pop {r4, pc} */
/* @0x12d674 mov r3, #0 */
/* @0x12d678 mov r2, #0 */
/* @0x12d67c movt r3, #0xbff0 */
/* @0x12d680 b 0x12d664 <_Z15F_PathGetNumberR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12d684 · F_PathGetPointX(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x12d684 push {r4, r5, r6, lr} */
/* @0x12d688 mov r1, #0 */
/* @0x12d68c ldr r5, [sp, #0x10] */
/* @0x12d690 mov r4, r0 */
/* @0x12d694 mov r0, r5 */
/* @0x12d698 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d69c bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d6a0 subs r6, r0, #0 */
/* @0x12d6a4 beq 0x12d6dc <_Z15F_PathGetPointXR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x12d6a8 mov r1, #1 */
/* @0x12d6ac mov r0, r5 */
/* @0x12d6b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d6b4 mov r1, r0 */
/* @0x12d6b8 mov r0, r6 */
/* @0x12d6bc bl 0x1a5f34 <_ZN5CPath8GetPointEi> */
/* @0x12d6c0 vldr s15, [r0] */
/* @0x12d6c4 vcvt.f64.f32 d6, s15 */
/* @0x12d6c8 vmov r2, r3, d6 */
/* @0x12d6cc mov r1, #0 */
/* @0x12d6d0 stm r4, {r2, r3} */
/* @0x12d6d4 str r1, [r4, #0xc] */
/* @0x12d6d8 pop {r4, r5, r6, pc} */
/* @0x12d6dc mov r3, #0 */
/* @0x12d6e0 mov r2, #0 */
/* @0x12d6e4 movt r3, #0xbff0 */
/* @0x12d6e8 b 0x12d6cc <_Z15F_PathGetPointXR6RValueP9CInstanceS2_iPS_+0x48> */

/* ── FUNC 0x12d6ec · F_PathGetPointY(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x12d6ec push {r4, r5, r6, lr} */
/* @0x12d6f0 mov r1, #0 */
/* @0x12d6f4 ldr r5, [sp, #0x10] */
/* @0x12d6f8 mov r4, r0 */
/* @0x12d6fc mov r0, r5 */
/* @0x12d700 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d704 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d708 subs r6, r0, #0 */
/* @0x12d70c beq 0x12d744 <_Z15F_PathGetPointYR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x12d710 mov r1, #1 */
/* @0x12d714 mov r0, r5 */
/* @0x12d718 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d71c mov r1, r0 */
/* @0x12d720 mov r0, r6 */
/* @0x12d724 bl 0x1a5f34 <_ZN5CPath8GetPointEi> */
/* @0x12d728 vldr s15, [r0, #4] */
/* @0x12d72c vcvt.f64.f32 d6, s15 */
/* @0x12d730 vmov r2, r3, d6 */
/* @0x12d734 mov r1, #0 */
/* @0x12d738 stm r4, {r2, r3} */
/* @0x12d73c str r1, [r4, #0xc] */
/* @0x12d740 pop {r4, r5, r6, pc} */
/* @0x12d744 mov r3, #0 */
/* @0x12d748 mov r2, #0 */
/* @0x12d74c movt r3, #0xbff0 */
/* @0x12d750 b 0x12d734 <_Z15F_PathGetPointYR6RValueP9CInstanceS2_iPS_+0x48> */

/* ── FUNC 0x12d754 · F_PathGetPointSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x12d754 push {r4, r5, r6, lr} */
/* @0x12d758 mov r1, #0 */
/* @0x12d75c ldr r5, [sp, #0x10] */
/* @0x12d760 mov r4, r0 */
/* @0x12d764 mov r0, r5 */
/* @0x12d768 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d76c bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d770 subs r6, r0, #0 */
/* @0x12d774 beq 0x12d7ac <_Z19F_PathGetPointSpeedR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x12d778 mov r1, #1 */
/* @0x12d77c mov r0, r5 */
/* @0x12d780 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d784 mov r1, r0 */
/* @0x12d788 mov r0, r6 */
/* @0x12d78c bl 0x1a5f34 <_ZN5CPath8GetPointEi> */
/* @0x12d790 vldr s15, [r0, #8] */
/* @0x12d794 vcvt.f64.f32 d6, s15 */
/* @0x12d798 vmov r2, r3, d6 */
/* @0x12d79c mov r1, #0 */
/* @0x12d7a0 stm r4, {r2, r3} */
/* @0x12d7a4 str r1, [r4, #0xc] */
/* @0x12d7a8 pop {r4, r5, r6, pc} */
/* @0x12d7ac mov r3, #0 */
/* @0x12d7b0 mov r2, #0 */
/* @0x12d7b4 movt r3, #0xbff0 */
/* @0x12d7b8 b 0x12d79c <_Z19F_PathGetPointSpeedR6RValueP9CInstanceS2_iPS_+0x48> */

/* ── FUNC 0x12d7bc · F_PathGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x12d7bc push {r4, r5, r6, lr} */
/* @0x12d7c0 mov r1, #0 */
/* @0x12d7c4 ldr r5, [sp, #0x10] */
/* @0x12d7c8 mov r4, r0 */
/* @0x12d7cc mov r0, r5 */
/* @0x12d7d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d7d4 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d7d8 subs r6, r0, #0 */
/* @0x12d7dc beq 0x12d814 <_Z10F_PathGetXR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x12d7e0 mov r1, #1 */
/* @0x12d7e4 mov r0, r5 */
/* @0x12d7e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12d7ec mov r1, r0 */
/* @0x12d7f0 mov r0, r6 */
/* @0x12d7f4 bl 0x1a7598 <_ZN5CPath9XPositionEf> */
/* @0x12d7f8 vmov s15, r0 */
/* @0x12d7fc vcvt.f64.f32 d7, s15 */
/* @0x12d800 vmov r2, r3, d7 */
/* @0x12d804 mov r1, #0 */
/* @0x12d808 stm r4, {r2, r3} */
/* @0x12d80c str r1, [r4, #0xc] */
/* @0x12d810 pop {r4, r5, r6, pc} */
/* @0x12d814 mov r3, #0 */
/* @0x12d818 mov r2, #0 */
/* @0x12d81c movt r3, #0xbff0 */
/* @0x12d820 b 0x12d804 <_Z10F_PathGetXR6RValueP9CInstanceS2_iPS_+0x48> */

/* ── FUNC 0x12d824 · F_PathGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x12d824 push {r4, r5, r6, lr} */
/* @0x12d828 mov r1, #0 */
/* @0x12d82c ldr r5, [sp, #0x10] */
/* @0x12d830 mov r4, r0 */
/* @0x12d834 mov r0, r5 */
/* @0x12d838 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d83c bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d840 subs r6, r0, #0 */
/* @0x12d844 beq 0x12d87c <_Z10F_PathGetYR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x12d848 mov r1, #1 */
/* @0x12d84c mov r0, r5 */
/* @0x12d850 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12d854 mov r1, r0 */
/* @0x12d858 mov r0, r6 */
/* @0x12d85c bl 0x1a75c0 <_ZN5CPath9YPositionEf> */
/* @0x12d860 vmov s15, r0 */
/* @0x12d864 vcvt.f64.f32 d7, s15 */
/* @0x12d868 vmov r2, r3, d7 */
/* @0x12d86c mov r1, #0 */
/* @0x12d870 stm r4, {r2, r3} */
/* @0x12d874 str r1, [r4, #0xc] */
/* @0x12d878 pop {r4, r5, r6, pc} */
/* @0x12d87c mov r3, #0 */
/* @0x12d880 mov r2, #0 */
/* @0x12d884 movt r3, #0xbff0 */
/* @0x12d888 b 0x12d86c <_Z10F_PathGetYR6RValueP9CInstanceS2_iPS_+0x48> */

/* ── FUNC 0x12d88c · F_PathGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x12d88c push {r4, r5, r6, lr} */
/* @0x12d890 mov r1, #0 */
/* @0x12d894 ldr r5, [sp, #0x10] */
/* @0x12d898 mov r4, r0 */
/* @0x12d89c mov r0, r5 */
/* @0x12d8a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d8a4 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d8a8 subs r6, r0, #0 */
/* @0x12d8ac beq 0x12d8e4 <_Z14F_PathGetSpeedR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x12d8b0 mov r1, #1 */
/* @0x12d8b4 mov r0, r5 */
/* @0x12d8b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12d8bc mov r1, r0 */
/* @0x12d8c0 mov r0, r6 */
/* @0x12d8c4 bl 0x1a75e8 <_ZN5CPath5SpeedEf> */
/* @0x12d8c8 vmov s15, r0 */
/* @0x12d8cc vcvt.f64.f32 d7, s15 */
/* @0x12d8d0 vmov r2, r3, d7 */
/* @0x12d8d4 mov r1, #0 */
/* @0x12d8d8 stm r4, {r2, r3} */
/* @0x12d8dc str r1, [r4, #0xc] */
/* @0x12d8e0 pop {r4, r5, r6, pc} */
/* @0x12d8e4 mov r3, #0 */
/* @0x12d8e8 mov r2, #0 */
/* @0x12d8ec movt r3, #0xbff0 */
/* @0x12d8f0 b 0x12d8d4 <_Z14F_PathGetSpeedR6RValueP9CInstanceS2_iPS_+0x48> */

/* ── FUNC 0x12d8f4 · F_PathSetKind(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x12d8f4 push {r3, r4, r5, lr} */
/* @0x12d8f8 mov r1, #0 */
/* @0x12d8fc ldr r4, [sp, #0x10] */
/* @0x12d900 mov r0, r4 */
/* @0x12d904 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d908 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d90c subs r5, r0, #0 */
/* @0x12d910 popeq {r3, r4, r5, pc} */
/* @0x12d914 mov r0, r4 */
/* @0x12d918 mov r1, #1 */
/* @0x12d91c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d920 mov r1, r0 */
/* @0x12d924 mov r0, r5 */
/* @0x12d928 pop {r3, r4, r5, lr} */
/* @0x12d92c b 0x1a6e64 <_ZN5CPath7SetKindEi> */

/* ── FUNC 0x12d930 · F_PathSetClosed(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x12d930 push {r3, r4, r5, lr} */
/* @0x12d934 mov r1, #0 */
/* @0x12d938 ldr r4, [sp, #0x10] */
/* @0x12d93c mov r0, r4 */
/* @0x12d940 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d944 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d948 subs r5, r0, #0 */
/* @0x12d94c popeq {r3, r4, r5, pc} */
/* @0x12d950 mov r0, r4 */
/* @0x12d954 mov r1, #1 */
/* @0x12d958 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12d95c mov r1, r0 */
/* @0x12d960 mov r0, r5 */
/* @0x12d964 pop {r3, r4, r5, lr} */
/* @0x12d968 b 0x1a6e78 <_ZN5CPath9SetClosedEb> */

/* ── FUNC 0x12d96c · F_PathSetPrecision(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x12d96c push {r3, r4, r5, lr} */
/* @0x12d970 mov r1, #0 */
/* @0x12d974 ldr r4, [sp, #0x10] */
/* @0x12d978 mov r0, r4 */
/* @0x12d97c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d980 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d984 subs r5, r0, #0 */
/* @0x12d988 popeq {r3, r4, r5, pc} */
/* @0x12d98c mov r0, r4 */
/* @0x12d990 mov r1, #1 */
/* @0x12d994 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d998 mov r1, r0 */
/* @0x12d99c mov r0, r5 */
/* @0x12d9a0 pop {r3, r4, r5, lr} */
/* @0x12d9a4 b 0x1a6e80 <_ZN5CPath12SetPrecisionEi> */

/* ── FUNC 0x12d9a8 · F_PathAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x12d9a8 push {r4, lr} */
/* @0x12d9ac mov r3, #0 */
/* @0x12d9b0 str r3, [r0, #0xc] */
/* @0x12d9b4 mov r4, r0 */
/* @0x12d9b8 bl 0x1a819c <_Z8Path_Addv> */
/* @0x12d9bc vmov s15, r0 */
/* @0x12d9c0 vcvt.f64.s32 d7, s15 */
/* @0x12d9c4 vmov r0, r1, d7 */
/* @0x12d9c8 vmov r2, s14 */
/* @0x12d9cc mov r3, r1 */
/* @0x12d9d0 stm r4, {r2, r3} */
/* @0x12d9d4 pop {r4, pc} */

/* ── FUNC 0x12d9d8 · F_PathDuplicate(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x12d9d8 push {r3, r4, r5, lr} */
/* @0x12d9dc mov r1, #0 */
/* @0x12d9e0 mov r4, r0 */
/* @0x12d9e4 ldr r0, [sp, #0x10] */
/* @0x12d9e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12d9ec mov r5, r0 */
/* @0x12d9f0 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12d9f4 subs r1, r0, #0 */
/* @0x12d9f8 beq 0x12da20 <_Z15F_PathDuplicateR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12d9fc mov r0, r5 */
/* @0x12da00 bl 0x1a8320 <_Z14Path_Duplicatei> */
/* @0x12da04 vmov s15, r0 */
/* @0x12da08 vcvt.f64.s32 d7, s15 */
/* @0x12da0c vmov r2, r3, d7 */
/* @0x12da10 mov r1, #0 */
/* @0x12da14 stm r4, {r2, r3} */
/* @0x12da18 str r1, [r4, #0xc] */
/* @0x12da1c pop {r3, r4, r5, pc} */
/* @0x12da20 ldr r0, [pc, #0x10] */
/* @0x12da24 add r0, pc, r0 */
/* @0x12da28 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12da2c mov r2, #0 */
/* @0x12da30 mov r3, #0 */
/* @0x12da34 b 0x12da10 <_Z15F_PathDuplicateR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x12da38 eoreq pc, r0, r12, asr #23 */

/* ── FUNC 0x12da3c · F_PathDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x12da3c push {r4, r5, r6, lr} */
/* @0x12da40 mov r1, #0 */
/* @0x12da44 mov r4, r0 */
/* @0x12da48 ldr r0, [sp, #0x10] */
/* @0x12da4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12da50 mov r5, r0 */
/* @0x12da54 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12da58 subs r6, r0, #0 */
/* @0x12da5c beq 0x12da94 <_Z12F_PathDeleteR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x12da60 mov r0, r5 */
/* @0x12da64 bl 0x1a82a0 <_Z11Path_Deletei> */
/* @0x12da68 mov r3, #0 */
/* @0x12da6c str r3, [r4, #0xc] */
/* @0x12da70 cmp r0, r3 */
/* @0x12da74 movne r2, #0 */
/* @0x12da78 movtne r2, #0x3ff0 */
/* @0x12da7c bne 0x12da88 <_Z12F_PathDeleteR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12da80 mov r3, #0 */
/* @0x12da84 mov r2, r3 */
/* @0x12da88 str r3, [r4] */
/* @0x12da8c str r2, [r4, #0x4] */
/* @0x12da90 pop {r4, r5, r6, pc} */
/* @0x12da94 ldr r0, [pc, #0x10] */
/* @0x12da98 mov r1, r6 */
/* @0x12da9c add r0, pc, r0 */
/* @0x12daa0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12daa4 str r6, [r4, #0xc] */
/* @0x12daa8 b 0x12da80 <_Z12F_PathDeleteR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x12daac eoreq pc, r0, r12, ror r11 */

/* ── FUNC 0x12dab0 · F_PathAddPoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x12dab0 push {r4, r5, r6, r7, r8, lr} */
/* @0x12dab4 mov r1, #0 */
/* @0x12dab8 ldr r4, [sp, #0x18] */
/* @0x12dabc mov r0, r4 */
/* @0x12dac0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dac4 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dac8 subs r5, r0, #0 */
/* @0x12dacc popeq {r4, r5, r6, r7, r8, pc} */
/* @0x12dad0 mov r0, r4 */
/* @0x12dad4 mov r1, #1 */
/* @0x12dad8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dadc mov r1, #2 */
/* @0x12dae0 mov r7, r0 */
/* @0x12dae4 mov r0, r4 */
/* @0x12dae8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12daec mov r1, #3 */
/* @0x12daf0 mov r6, r0 */
/* @0x12daf4 mov r0, r4 */
/* @0x12daf8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dafc mov r1, r7 */
/* @0x12db00 mov r2, r6 */
/* @0x12db04 mov r3, r0 */
/* @0x12db08 mov r0, r5 */
/* @0x12db0c pop {r4, r5, r6, r7, r8, lr} */
/* @0x12db10 b 0x1a72c0 <_ZN5CPath8AddPointEfff> */

/* ── FUNC 0x12db14 · F_PathInsertPoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x12db14 push {r4, r5, r6, r7, r8, lr} */
/* @0x12db18 mov r1, #0 */
/* @0x12db1c ldr r4, [sp, #0x18] */
/* @0x12db20 mov r0, r4 */
/* @0x12db24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12db28 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12db2c subs r5, r0, #0 */
/* @0x12db30 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x12db34 mov r0, r4 */
/* @0x12db38 mov r1, #1 */
/* @0x12db3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12db40 mov r1, #2 */
/* @0x12db44 mov r8, r0 */
/* @0x12db48 mov r0, r4 */
/* @0x12db4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12db50 mov r1, #3 */
/* @0x12db54 mov r7, r0 */
/* @0x12db58 mov r0, r4 */
/* @0x12db5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12db60 mov r1, #4 */
/* @0x12db64 mov r6, r0 */
/* @0x12db68 mov r0, r4 */
/* @0x12db6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12db70 mov r1, r8 */
/* @0x12db74 mov r2, r7 */
/* @0x12db78 mov r3, r6 */
/* @0x12db7c str r0, [sp, #0x18] */
/* @0x12db80 mov r0, r5 */
/* @0x12db84 pop {r4, r5, r6, r7, r8, lr} */
/* @0x12db88 b 0x1a71d0 <_ZN5CPath11InsertPointEifff> */

/* ── FUNC 0x12db8c · F_PathChangePoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x12db8c push {r4, r5, r6, r7, r8, lr} */
/* @0x12db90 mov r1, #0 */
/* @0x12db94 ldr r4, [sp, #0x18] */
/* @0x12db98 mov r0, r4 */
/* @0x12db9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dba0 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dba4 subs r5, r0, #0 */
/* @0x12dba8 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x12dbac mov r0, r4 */
/* @0x12dbb0 mov r1, #1 */
/* @0x12dbb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dbb8 mov r1, #2 */
/* @0x12dbbc mov r8, r0 */
/* @0x12dbc0 mov r0, r4 */
/* @0x12dbc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dbc8 mov r1, #3 */
/* @0x12dbcc mov r7, r0 */
/* @0x12dbd0 mov r0, r4 */
/* @0x12dbd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dbd8 mov r1, #4 */
/* @0x12dbdc mov r6, r0 */
/* @0x12dbe0 mov r0, r4 */
/* @0x12dbe4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dbe8 mov r1, r8 */
/* @0x12dbec mov r2, r7 */
/* @0x12dbf0 mov r3, r6 */
/* @0x12dbf4 str r0, [sp, #0x18] */
/* @0x12dbf8 mov r0, r5 */
/* @0x12dbfc pop {r4, r5, r6, r7, r8, lr} */
/* @0x12dc00 b 0x1a72f8 <_ZN5CPath11ChangePointEifff> */

/* ── FUNC 0x12dc04 · F_PathDeletePoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x12dc04 push {r3, r4, r5, lr} */
/* @0x12dc08 mov r1, #0 */
/* @0x12dc0c ldr r4, [sp, #0x10] */
/* @0x12dc10 mov r0, r4 */
/* @0x12dc14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dc18 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dc1c subs r5, r0, #0 */
/* @0x12dc20 popeq {r3, r4, r5, pc} */
/* @0x12dc24 mov r0, r4 */
/* @0x12dc28 mov r1, #1 */
/* @0x12dc2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dc30 mov r1, r0 */
/* @0x12dc34 mov r0, r5 */
/* @0x12dc38 pop {r3, r4, r5, lr} */
/* @0x12dc3c b 0x1a733c <_ZN5CPath11DeletePointEi> */

/* ── FUNC 0x12dc40 · F_PathClearPoints(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12dc40 push {r3, lr} */
/* @0x12dc44 mov r1, #0 */
/* @0x12dc48 ldr r0, [sp, #0x8] */
/* @0x12dc4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dc50 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dc54 cmp r0, #0 */
/* @0x12dc58 popeq {r3, pc} */
/* @0x12dc5c pop {r3, lr} */
/* @0x12dc60 b 0x1a6f98 <_ZN5CPath5ClearEv> */
