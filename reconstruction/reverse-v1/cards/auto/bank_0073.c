/* libyoyo.so 覆盖卡组 0073
 * 函数 0x13daf8..0x13eb4c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x13daf8 · F_ActionMoveTo(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x13daf8 push {r3, r4, r5, lr} */
/* @0x13dafc vpush {d8} */
/* @0x13db00 mov r5, r1 */
/* @0x13db04 ldr r4, [sp, #0x18] */
/* @0x13db08 mov r1, #0 */
/* @0x13db0c mov r0, r4 */
/* @0x13db10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13db14 mov r1, #1 */
/* @0x13db18 vmov s16, r0 */
/* @0x13db1c mov r0, r4 */
/* @0x13db20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13db24 ldr r3, [pc, #0x50] */
/* @0x13db28 ldr r3, [pc, r3] */
/* @0x13db2c ldrb r3, [r3] */
/* @0x13db30 cmp r3, #0 */
/* @0x13db34 vmov s15, r0 */
/* @0x13db38 bne 0x13db54 <_Z14F_ActionMoveToR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x13db3c vmov r1, s16 */
/* @0x13db40 mov r0, r5 */
/* @0x13db44 vpop {d8} */
/* @0x13db48 vmov r2, s15 */
/* @0x13db4c pop {r3, r4, r5, lr} */
/* @0x13db50 b 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x13db54 vldr s13, [r5, #180] */
/* @0x13db58 vldr s14, [r5, #184] */
/* @0x13db5c vadd.f32 s13, s16, s13 */
/* @0x13db60 mov r0, r5 */
/* @0x13db64 vpop {d8} */
/* @0x13db68 pop {r3, r4, r5, lr} */
/* @0x13db6c vadd.f32 s14, s15, s14 */
/* @0x13db70 vmov r1, s13 */
/* @0x13db74 vmov r2, s14 */
/* @0x13db78 b 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x13db7c eoreq r0, r11, r4, lsl r0 */

/* ── FUNC 0x13db80 · F_ActionMoveStart(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x13db80 mov r0, r1 */
/* @0x13db84 ldr r1, [r1, #0xbc] */
/* @0x13db88 ldr r2, [r0, #0xc0] */
/* @0x13db8c b 0x193e7c <_ZN9CInstance11SetPositionEff> */

/* ── FUNC 0x13db90 · F_ActionMoveRandom(RValue&, CInstance*, CInstance*, int, RValue*) · size=916 · insn=229 */
/* @0x13db90 ldr r3, [pc, #0x388] */
/* @0x13db94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13db98 vpush {d8, d9} */
/* @0x13db9c ldr r3, [pc, r3] */
/* @0x13dba0 sub sp, sp, #12 */
/* @0x13dba4 ldr r0, [r1, #0x8c] */
/* @0x13dba8 ldr r3, [r3] */
/* @0x13dbac mov r4, r1 */
/* @0x13dbb0 ldr r10, [sp, #0x40] */
/* @0x13dbb4 ldr r8, [r3, #0x10] */
/* @0x13dbb8 ldr r9, [r3, #0x14] */
/* @0x13dbbc bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x13dbc0 cmp r0, #0 */
/* @0x13dbc4 beq 0x13dd7c <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x13dbc8 ldrb r3, [r4, #0x64] */
/* @0x13dbcc cmp r3, #0 */
/* @0x13dbd0 bne 0x13df10 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x380> */
/* @0x13dbd4 vldr s12, [r4, #232] */
/* @0x13dbd8 vcvt.f32.s32 s15, s12 */
/* @0x13dbdc vldr s14, [r4, #180] */
/* @0x13dbe0 vsub.f32 s15, s14, s15 */
/* @0x13dbe4 vcvt.f64.f32 d6, s15 */
/* @0x13dbe8 vmov r0, r1, d6 */
/* @0x13dbec bl 0xb66e8 <lrint@plt> */
/* @0x13dbf0 vldr s15, [r4, #180] */
/* @0x13dbf4 vmov s13, r8 */
/* @0x13dbf8 vldr s12, [r4, #240] */
/* @0x13dbfc vcvt.f32.s32 s14, s13 */
/* @0x13dc00 vadd.f32 s14, s14, s15 */
/* @0x13dc04 vcvt.f32.s32 s15, s12 */
/* @0x13dc08 vsub.f32 s15, s14, s15 */
/* @0x13dc0c mov r11, r0 */
/* @0x13dc10 mov r6, r0 */
/* @0x13dc14 vcvt.f64.f32 d6, s15 */
/* @0x13dc18 vmov r0, r1, d6 */
/* @0x13dc1c bl 0xb66e8 <lrint@plt> */
/* @0x13dc20 vldr s13, [r4, #236] */
/* @0x13dc24 vcvt.f32.s32 s15, s13 */
/* @0x13dc28 vldr s14, [r4, #184] */
/* @0x13dc2c vsub.f32 s15, s14, s15 */
/* @0x13dc30 vcvt.f64.f32 d6, s15 */
/* @0x13dc34 mov r8, r0 */
/* @0x13dc38 vmov r0, r1, d6 */
/* @0x13dc3c bl 0xb66e8 <lrint@plt> */
/* @0x13dc40 vldr s15, [r4, #184] */
/* @0x13dc44 vmov s13, r9 */
/* @0x13dc48 vldr s12, [r4, #244] */
/* @0x13dc4c vcvt.f32.s32 s14, s13 */
/* @0x13dc50 vadd.f32 s14, s14, s15 */
/* @0x13dc54 vcvt.f32.s32 s15, s12 */
/* @0x13dc58 vsub.f32 s15, s14, s15 */
/* @0x13dc5c str r0, [sp, #0x4] */
/* @0x13dc60 mov r5, r0 */
/* @0x13dc64 vcvt.f64.f32 d6, s15 */
/* @0x13dc68 vmov r0, r1, d6 */
/* @0x13dc6c bl 0xb66e8 <lrint@plt> */
/* @0x13dc70 mov r9, r0 */
/* @0x13dc74 mov r0, r10 */
/* @0x13dc78 mov r1, #0 */
/* @0x13dc7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13dc80 mov r1, #1 */
/* @0x13dc84 rsb r8, r11, r8 */
/* @0x13dc88 mov r7, r0 */
/* @0x13dc8c mov r0, r10 */
/* @0x13dc90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13dc94 ldr r3, [sp, #0x4] */
/* @0x13dc98 cmp r7, #0 */
/* @0x13dc9c rsb r9, r3, r9 */
/* @0x13dca0 mov r10, r0 */
/* @0x13dca4 ble 0x13dda0 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x13dca8 cmp r0, #0 */
/* @0x13dcac ble 0x13de80 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x13dcb0 vmov s12, r0 */
/* @0x13dcb4 mov r11, #99 */
/* @0x13dcb8 vmov s13, r7 */
/* @0x13dcbc vcvt.f32.s32 s19, s12 */
/* @0x13dcc0 vcvt.f32.s32 s18, s13 */
/* @0x13dcc4 b 0x13dcd0 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x13dcc8 subs r11, r11, #1 */
/* @0x13dccc beq 0x13df04 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x13dcd0 mov r0, r8 */
/* @0x13dcd4 bl 0xc4600 <_Z8YYRandomi> */
/* @0x13dcd8 add r0, r0, r6 */
/* @0x13dcdc vmov s14, r0 */
/* @0x13dce0 vcvt.f32.u32 s15, s14 */
/* @0x13dce4 vdiv.f32 s15, s15, s18 */
/* @0x13dce8 vcvt.f64.f32 d6, s15 */
/* @0x13dcec vmov r0, r1, d6 */
/* @0x13dcf0 bl 0xb6598 <floor@plt> */
/* @0x13dcf4 vmov d7, r0, r1 */
/* @0x13dcf8 mov r0, r9 */
/* @0x13dcfc vcvt.s32.f64 s17, d7 */
/* @0x13dd00 vmov r3, s17 */
/* @0x13dd04 mul r3, r7, r3 */
/* @0x13dd08 vmov s17, r3 */
/* @0x13dd0c bl 0xc4600 <_Z8YYRandomi> */
/* @0x13dd10 vcvt.f32.s32 s17, s17 */
/* @0x13dd14 add r0, r0, r5 */
/* @0x13dd18 vmov s12, r0 */
/* @0x13dd1c vcvt.f32.u32 s15, s12 */
/* @0x13dd20 vdiv.f32 s15, s15, s19 */
/* @0x13dd24 vcvt.f64.f32 d6, s15 */
/* @0x13dd28 vmov r0, r1, d6 */
/* @0x13dd2c bl 0xb6598 <floor@plt> */
/* @0x13dd30 vmov d7, r0, r1 */
/* @0x13dd34 mov r0, r4 */
/* @0x13dd38 vcvt.s32.f64 s16, d7 */
/* @0x13dd3c vmov r1, s17 */
/* @0x13dd40 vmov r3, s16 */
/* @0x13dd44 mul r3, r10, r3 */
/* @0x13dd48 vmov s16, r3 */
/* @0x13dd4c vcvt.f32.s32 s16, s16 */
/* @0x13dd50 vmov r2, s16 */
/* @0x13dd54 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x13dd58 cmp r0, #0 */
/* @0x13dd5c beq 0x13dcc8 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x13dd60 vmov r1, s17 */
/* @0x13dd64 mov r0, r4 */
/* @0x13dd68 vmov r2, s16 */
/* @0x13dd6c add sp, sp, #12 */
/* @0x13dd70 vpop {d8, d9} */
/* @0x13dd74 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13dd78 b 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x13dd7c ldr r0, [r4, #0xac] */
/* @0x13dd80 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x13dd84 cmp r0, #0 */
/* @0x13dd88 bne 0x13dbc8 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x13dd8c mov r5, r0 */
/* @0x13dd90 mov r6, r0 */
/* @0x13dd94 str r0, [sp, #0x4] */
/* @0x13dd98 mov r11, r0 */
/* @0x13dd9c b 0x13dc74 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x13dda0 cmp r0, #0 */
/* @0x13dda4 ble 0x13de2c <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x13dda8 vmov s12, r0 */
/* @0x13ddac mov r7, #99 */
/* @0x13ddb0 vcvt.f32.s32 s19, s12 */
/* @0x13ddb4 b 0x13ddc0 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x13ddb8 subs r7, r7, #1 */
/* @0x13ddbc beq 0x13df04 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x13ddc0 mov r0, r8 */
/* @0x13ddc4 bl 0xc4600 <_Z8YYRandomi> */
/* @0x13ddc8 add r0, r0, r6 */
/* @0x13ddcc vmov s17, r0 */
/* @0x13ddd0 mov r0, r9 */
/* @0x13ddd4 bl 0xc4600 <_Z8YYRandomi> */
/* @0x13ddd8 vcvt.f32.u32 s17, s17 */
/* @0x13dddc add r0, r0, r5 */
/* @0x13dde0 vmov s13, r0 */
/* @0x13dde4 vcvt.f32.u32 s15, s13 */
/* @0x13dde8 vdiv.f32 s15, s15, s19 */
/* @0x13ddec vcvt.f64.f32 d6, s15 */
/* @0x13ddf0 vmov r0, r1, d6 */
/* @0x13ddf4 bl 0xb6598 <floor@plt> */
/* @0x13ddf8 vmov d7, r0, r1 */
/* @0x13ddfc mov r0, r4 */
/* @0x13de00 vcvt.s32.f64 s16, d7 */
/* @0x13de04 vmov r1, s17 */
/* @0x13de08 vmov r3, s16 */
/* @0x13de0c mul r3, r10, r3 */
/* @0x13de10 vmov s16, r3 */
/* @0x13de14 vcvt.f32.s32 s16, s16 */
/* @0x13de18 vmov r2, s16 */
/* @0x13de1c bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x13de20 cmp r0, #0 */
/* @0x13de24 beq 0x13ddb8 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x13de28 b 0x13dd60 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x13de2c mov r7, #99 */
/* @0x13de30 b 0x13de3c <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x13de34 subs r7, r7, #1 */
/* @0x13de38 beq 0x13df04 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x13de3c mov r0, r8 */
/* @0x13de40 bl 0xc4600 <_Z8YYRandomi> */
/* @0x13de44 add r0, r0, r6 */
/* @0x13de48 vmov s17, r0 */
/* @0x13de4c mov r0, r9 */
/* @0x13de50 bl 0xc4600 <_Z8YYRandomi> */
/* @0x13de54 vcvt.f32.u32 s17, s17 */
/* @0x13de58 vmov r1, s17 */
/* @0x13de5c add r0, r0, r5 */
/* @0x13de60 vmov s16, r0 */
/* @0x13de64 mov r0, r4 */
/* @0x13de68 vcvt.f32.u32 s16, s16 */
/* @0x13de6c vmov r2, s16 */
/* @0x13de70 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x13de74 cmp r0, #0 */
/* @0x13de78 beq 0x13de34 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x13de7c b 0x13dd60 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x13de80 vmov s12, r7 */
/* @0x13de84 mov r10, #99 */
/* @0x13de88 vcvt.f32.s32 s18, s12 */
/* @0x13de8c b 0x13de98 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x13de90 subs r10, r10, #1 */
/* @0x13de94 beq 0x13df04 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x13de98 mov r0, r8 */
/* @0x13de9c bl 0xc4600 <_Z8YYRandomi> */
/* @0x13dea0 add r0, r0, r6 */
/* @0x13dea4 vmov s13, r0 */
/* @0x13dea8 vcvt.f32.u32 s15, s13 */
/* @0x13deac vdiv.f32 s15, s15, s18 */
/* @0x13deb0 vcvt.f64.f32 d6, s15 */
/* @0x13deb4 vmov r0, r1, d6 */
/* @0x13deb8 bl 0xb6598 <floor@plt> */
/* @0x13debc vmov d7, r0, r1 */
/* @0x13dec0 mov r0, r9 */
/* @0x13dec4 vcvt.s32.f64 s17, d7 */
/* @0x13dec8 vmov r3, s17 */
/* @0x13decc mul r3, r7, r3 */
/* @0x13ded0 vmov s17, r3 */
/* @0x13ded4 bl 0xc4600 <_Z8YYRandomi> */
/* @0x13ded8 vcvt.f32.s32 s17, s17 */
/* @0x13dedc vmov r1, s17 */
/* @0x13dee0 add r0, r0, r5 */
/* @0x13dee4 vmov s16, r0 */
/* @0x13dee8 mov r0, r4 */
/* @0x13deec vcvt.f32.u32 s16, s16 */
/* @0x13def0 vmov r2, s16 */
/* @0x13def4 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x13def8 cmp r0, #0 */
/* @0x13defc beq 0x13de90 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x300> */
/* @0x13df00 b 0x13dd60 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x13df04 add sp, sp, #12 */
/* @0x13df08 vpop {d8, d9} */
/* @0x13df0c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13df10 mov r0, r4 */
/* @0x13df14 mov r1, #1 */
/* @0x13df18 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x13df1c b 0x13dbd4 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x13df20 eoreq pc, r10, r12, lsl #27 */

/* ── FUNC 0x13df24 · F_ActionSnap(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13df24 push {r4, r5, r6, lr} */
/* @0x13df28 mov r6, r1 */
/* @0x13df2c ldr r4, [sp, #0x10] */
/* @0x13df30 mov r1, #0 */
/* @0x13df34 mov r0, r4 */
/* @0x13df38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13df3c mov r1, #1 */
/* @0x13df40 mov r5, r0 */
/* @0x13df44 mov r0, r4 */
/* @0x13df48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13df4c mov r1, r5 */
/* @0x13df50 mov r2, r0 */
/* @0x13df54 mov r0, r6 */
/* @0x13df58 pop {r4, r5, r6, lr} */
/* @0x13df5c b 0x1c9594 <_Z12Command_SnapP9CInstanceff> */

/* ── FUNC 0x13df60 · F_ActionWrap(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13df60 push {r4, lr} */
/* @0x13df64 mov r4, r1 */
/* @0x13df68 ldr r0, [sp, #0x8] */
/* @0x13df6c mov r1, #0 */
/* @0x13df70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13df74 bics r3, r0, #2 */
/* @0x13df78 sub r2, r0, #1 */
/* @0x13df7c mov r0, r4 */
/* @0x13df80 movne r1, #0 */
/* @0x13df84 moveq r1, #1 */
/* @0x13df88 cmp r2, #1 */
/* @0x13df8c pop {r4, lr} */
/* @0x13df90 movhi r2, #0 */
/* @0x13df94 movls r2, #1 */
/* @0x13df98 b 0x1c961c <_Z12Command_WrapP9CInstancebb> */

/* ── FUNC 0x13df9c · F_ActionMoveContact(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x13df9c push {r4, r5, r6, r7, r8, lr} */
/* @0x13dfa0 mov r7, r1 */
/* @0x13dfa4 ldr r4, [sp, #0x18] */
/* @0x13dfa8 mov r1, #0 */
/* @0x13dfac mov r0, r4 */
/* @0x13dfb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13dfb4 mov r1, #1 */
/* @0x13dfb8 mov r6, r0 */
/* @0x13dfbc mov r0, r4 */
/* @0x13dfc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13dfc4 mov r1, #2 */
/* @0x13dfc8 mov r5, r0 */
/* @0x13dfcc mov r0, r4 */
/* @0x13dfd0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13dfd4 mov r1, r6 */
/* @0x13dfd8 mov r2, r5 */
/* @0x13dfdc mov r3, r0 */
/* @0x13dfe0 mov r0, r7 */
/* @0x13dfe4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x13dfe8 b 0x1cad28 <_Z19Command_MoveContactP9CInstanceffb> */

/* ── FUNC 0x13dfec · F_ActionBounce(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13dfec push {r4, r5, r6, lr} */
/* @0x13dff0 mov r6, r1 */
/* @0x13dff4 ldr r4, [sp, #0x10] */
/* @0x13dff8 mov r1, #0 */
/* @0x13dffc mov r0, r4 */
/* @0x13e000 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13e004 mov r1, #1 */
/* @0x13e008 mov r5, r0 */
/* @0x13e00c mov r0, r4 */
/* @0x13e010 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13e014 mov r1, r5 */
/* @0x13e018 mov r2, r0 */
/* @0x13e01c mov r0, r6 */
/* @0x13e020 pop {r4, r5, r6, lr} */
/* @0x13e024 b 0x1cafa0 <_Z14Command_BounceP9CInstancebb> */

/* ── FUNC 0x13e028 · F_ActionPath(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x13e028 push {r4, r5, r6, r7, r8, lr} */
/* @0x13e02c sub sp, sp, #16 */
/* @0x13e030 mov r5, r1 */
/* @0x13e034 mov r1, #0 */
/* @0x13e038 ldr r4, [sp, #0x28] */
/* @0x13e03c mov r0, r4 */
/* @0x13e040 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e044 mov r1, #1 */
/* @0x13e048 mov r7, r0 */
/* @0x13e04c mov r0, r4 */
/* @0x13e050 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e054 mov r1, #3 */
/* @0x13e058 mov r6, r0 */
/* @0x13e05c mov r0, r4 */
/* @0x13e060 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13e064 mov r1, #2 */
/* @0x13e068 mov r8, r0 */
/* @0x13e06c mov r0, r4 */
/* @0x13e070 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e074 eor r3, r8, #1 */
/* @0x13e078 mov r12, #0 */
/* @0x13e07c mov r1, r7 */
/* @0x13e080 mov r2, r6 */
/* @0x13e084 uxtb r3, r3 */
/* @0x13e088 str r12, [sp] */
/* @0x13e08c str r3, [sp, #0x4] */
/* @0x13e090 mov r3, #1065353216 */
/* @0x13e094 str r0, [sp, #0x8] */
/* @0x13e098 mov r0, r5 */
/* @0x13e09c bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi> */
/* @0x13e0a0 add sp, sp, #16 */
/* @0x13e0a4 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x13e0a8 · F_ActionPathEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x13e0a8 str lr, [sp, #-0x4]! */
/* @0x13e0ac sub sp, sp, #20 */
/* @0x13e0b0 mov r0, r1 */
/* @0x13e0b4 mov r2, #0 */
/* @0x13e0b8 mov r3, #0 */
/* @0x13e0bc str r2, [sp] */
/* @0x13e0c0 str r3, [sp, #0x4] */
/* @0x13e0c4 mvn r1, #0 */
/* @0x13e0c8 str r3, [sp, #0x8] */
/* @0x13e0cc mov r3, #1065353216 */
/* @0x13e0d0 bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi> */
/* @0x13e0d4 add sp, sp, #20 */
/* @0x13e0d8 ldr pc, [sp], #4 */

/* ── FUNC 0x13e0dc · F_ActionPathPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x13e0dc push {r4, lr} */
/* @0x13e0e0 mov r4, r1 */
/* @0x13e0e4 ldr r0, [sp, #0x8] */
/* @0x13e0e8 mov r1, #0 */
/* @0x13e0ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e0f0 ldr r3, [pc, #0x38] */
/* @0x13e0f4 ldr r3, [pc, r3] */
/* @0x13e0f8 ldrb r3, [r3] */
/* @0x13e0fc cmp r3, #0 */
/* @0x13e100 vmov s15, r0 */
/* @0x13e104 bne 0x13e118 <_Z20F_ActionPathPositionR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x13e108 mov r0, r4 */
/* @0x13e10c vmov r1, s15 */
/* @0x13e110 pop {r4, lr} */
/* @0x13e114 b 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x13e118 vldr s14, [r4, #300] */
/* @0x13e11c vadd.f32 s14, s15, s14 */
/* @0x13e120 mov r0, r4 */
/* @0x13e124 pop {r4, lr} */
/* @0x13e128 vmov r1, s14 */
/* @0x13e12c b 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x13e130 eoreq pc, r10, r8, asr #20 */

/* ── FUNC 0x13e134 · F_ActionPathSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x13e134 push {r4, lr} */
/* @0x13e138 mov r4, r1 */
/* @0x13e13c ldr r0, [sp, #0x8] */
/* @0x13e140 mov r1, #0 */
/* @0x13e144 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e148 ldr r3, [pc, #0x38] */
/* @0x13e14c ldr r3, [pc, r3] */
/* @0x13e150 ldrb r3, [r3] */
/* @0x13e154 cmp r3, #0 */
/* @0x13e158 vmov s15, r0 */
/* @0x13e15c bne 0x13e170 <_Z17F_ActionPathSpeedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x13e160 mov r0, r4 */
/* @0x13e164 vmov r1, s15 */
/* @0x13e168 pop {r4, lr} */
/* @0x13e16c b 0x193634 <_ZN9CInstance12SetPathSpeedEf> */
/* @0x13e170 vldr s14, [r4, #308] */
/* @0x13e174 vadd.f32 s14, s15, s14 */
/* @0x13e178 mov r0, r4 */
/* @0x13e17c pop {r4, lr} */
/* @0x13e180 vmov r1, s14 */
/* @0x13e184 b 0x193634 <_ZN9CInstance12SetPathSpeedEf> */
/* @0x13e188 .word 0x002af9f0 */

/* ── FUNC 0x13e18c · F_ActionLinearStep(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x13e18c push {r4, r5, r6, lr} */
/* @0x13e190 vpush {d8} */
/* @0x13e194 sub sp, sp, #8 */
/* @0x13e198 mov r5, r1 */
/* @0x13e19c mov r1, #0 */
/* @0x13e1a0 ldr r4, [sp, #0x20] */
/* @0x13e1a4 mov r0, r4 */
/* @0x13e1a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e1ac mov r1, #1 */
/* @0x13e1b0 vmov s17, r0 */
/* @0x13e1b4 mov r0, r4 */
/* @0x13e1b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e1bc mov r1, #2 */
/* @0x13e1c0 vmov s16, r0 */
/* @0x13e1c4 mov r0, r4 */
/* @0x13e1c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e1cc mov r1, #3 */
/* @0x13e1d0 mov r6, r0 */
/* @0x13e1d4 mov r0, r4 */
/* @0x13e1d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13e1dc ldr r2, [pc, #0x70] */
/* @0x13e1e0 ldr r2, [pc, r2] */
/* @0x13e1e4 ldrb r3, [r2] */
/* @0x13e1e8 cmp r3, #0 */
/* @0x13e1ec str r0, [sp, #0x4] */
/* @0x13e1f0 bne 0x13e21c <_Z18F_ActionLinearStepR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x13e1f4 mov r0, r5 */
/* @0x13e1f8 mov r3, r6 */
/* @0x13e1fc mvn r2, #2 */
/* @0x13e200 vmov r1, s17 */
/* @0x13e204 str r2, [sp] */
/* @0x13e208 vmov r2, s16 */
/* @0x13e20c bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib> */
/* @0x13e210 add sp, sp, #8 */
/* @0x13e214 vpop {d8} */
/* @0x13e218 pop {r4, r5, r6, pc} */
/* @0x13e21c vldr s14, [r5, #180] */
/* @0x13e220 vldr s15, [r5, #184] */
/* @0x13e224 vadd.f32 s14, s17, s14 */
/* @0x13e228 mov r3, r6 */
/* @0x13e22c mov r0, r5 */
/* @0x13e230 mvn r2, #2 */
/* @0x13e234 str r2, [sp] */
/* @0x13e238 vadd.f32 s15, s16, s15 */
/* @0x13e23c vmov r1, s14 */
/* @0x13e240 vmov r2, s15 */
/* @0x13e244 bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib> */
/* @0x13e248 add sp, sp, #8 */
/* @0x13e24c vpop {d8} */
/* @0x13e250 pop {r4, r5, r6, pc} */
/* @0x13e254 eoreq pc, r10, r12, asr r9 */

/* ── FUNC 0x13e258 · F_ActionPotentialStep(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x13e258 push {r4, r5, r6, lr} */
/* @0x13e25c vpush {d8} */
/* @0x13e260 sub sp, sp, #8 */
/* @0x13e264 mov r5, r1 */
/* @0x13e268 mov r1, #0 */
/* @0x13e26c ldr r4, [sp, #0x20] */
/* @0x13e270 mov r0, r4 */
/* @0x13e274 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e278 mov r1, #1 */
/* @0x13e27c vmov s17, r0 */
/* @0x13e280 mov r0, r4 */
/* @0x13e284 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e288 mov r1, #2 */
/* @0x13e28c vmov s16, r0 */
/* @0x13e290 mov r0, r4 */
/* @0x13e294 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e298 mov r1, #3 */
/* @0x13e29c mov r6, r0 */
/* @0x13e2a0 mov r0, r4 */
/* @0x13e2a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e2a8 ldr r2, [pc, #0x7c] */
/* @0x13e2ac ldr r2, [pc, r2] */
/* @0x13e2b0 ldrb r3, [r2] */
/* @0x13e2b4 cmp r0, #0 */
/* @0x13e2b8 movle r0, #0 */
/* @0x13e2bc movgt r0, #1 */
/* @0x13e2c0 cmp r3, #0 */
/* @0x13e2c4 str r0, [sp, #0x4] */
/* @0x13e2c8 bne 0x13e2f4 <_Z21F_ActionPotentialStepR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13e2cc mov r0, r5 */
/* @0x13e2d0 mov r3, r6 */
/* @0x13e2d4 mvn r2, #2 */
/* @0x13e2d8 vmov r1, s17 */
/* @0x13e2dc str r2, [sp] */
/* @0x13e2e0 vmov r2, s16 */
/* @0x13e2e4 bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib> */
/* @0x13e2e8 add sp, sp, #8 */
/* @0x13e2ec vpop {d8} */
/* @0x13e2f0 pop {r4, r5, r6, pc} */
/* @0x13e2f4 vldr s14, [r5, #180] */
/* @0x13e2f8 vldr s15, [r5, #184] */
/* @0x13e2fc vadd.f32 s14, s17, s14 */
/* @0x13e300 mov r3, r6 */
/* @0x13e304 mov r0, r5 */
/* @0x13e308 mvn r2, #2 */
/* @0x13e30c str r2, [sp] */
/* @0x13e310 vadd.f32 s15, s16, s15 */
/* @0x13e314 vmov r1, s14 */
/* @0x13e318 vmov r2, s15 */
/* @0x13e31c bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib> */
/* @0x13e320 add sp, sp, #8 */
/* @0x13e324 vpop {d8} */
/* @0x13e328 pop {r4, r5, r6, pc} */
/* @0x13e32c mlaeq r10, r0, r8, pc */

/* ── FUNC 0x13e330 · F_ActionCreateObjectRandom(RValue&, CInstance*, CInstance*, int, RValue*) · size=420 · insn=105 */
/* @0x13e330 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x13e334 vpush {d8} */
/* @0x13e338 sub sp, sp, #16 */
/* @0x13e33c mov r9, r1 */
/* @0x13e340 mov r1, #0 */
/* @0x13e344 ldr r4, [sp, #0x38] */
/* @0x13e348 ldr r5, [pc, #0x178] */
/* @0x13e34c mov r0, r4 */
/* @0x13e350 add r5, pc, r5 */
/* @0x13e354 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e358 mov r1, #1 */
/* @0x13e35c mov r6, r0 */
/* @0x13e360 mov r0, r4 */
/* @0x13e364 str r6, [sp] */
/* @0x13e368 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e36c mov r1, #2 */
/* @0x13e370 mov r7, r0 */
/* @0x13e374 mov r0, r4 */
/* @0x13e378 str r7, [sp, #0x4] */
/* @0x13e37c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e380 mov r1, #3 */
/* @0x13e384 mov r8, r0 */
/* @0x13e388 mov r0, r4 */
/* @0x13e38c str r8, [sp, #0x8] */
/* @0x13e390 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e394 mov r1, #4 */
/* @0x13e398 mov r10, r0 */
/* @0x13e39c mov r0, r4 */
/* @0x13e3a0 str r10, [sp, #0xc] */
/* @0x13e3a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e3a8 mov r1, #5 */
/* @0x13e3ac vmov s17, r0 */
/* @0x13e3b0 mov r0, r4 */
/* @0x13e3b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e3b8 vmov s16, r0 */
/* @0x13e3bc mov r0, r6 */
/* @0x13e3c0 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x13e3c4 cmp r0, #0 */
/* @0x13e3c8 beq 0x13e494 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x13e3cc mov r0, #4 */
/* @0x13e3d0 bl 0xc4600 <_Z8YYRandomi> */
/* @0x13e3d4 add r3, sp, #16 */
/* @0x13e3d8 add r0, r3, r0, lsl #2 */
/* @0x13e3dc ldr r4, [r0, #-0x10] */
/* @0x13e3e0 mov r0, r4 */
/* @0x13e3e4 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x13e3e8 cmp r0, #0 */
/* @0x13e3ec beq 0x13e3cc <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13e3f0 ldr r3, [pc, #0xd4] */
/* @0x13e3f4 ldr r3, [r5, r3] */
/* @0x13e3f8 ldrb r3, [r3] */
/* @0x13e3fc cmp r3, #0 */
/* @0x13e400 bne 0x13e460 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x13e404 ldr r0, [pc, #0xc4] */
/* @0x13e408 mov r3, r4 */
/* @0x13e40c vmov r1, s17 */
/* @0x13e410 vmov r2, s16 */
/* @0x13e414 ldr r0, [r5, r0] */
/* @0x13e418 ldr r0, [r0] */
/* @0x13e41c bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x13e420 mov r4, r0 */
/* @0x13e424 mov r0, r4 */
/* @0x13e428 mov r1, r4 */
/* @0x13e42c mov r2, #14 */
/* @0x13e430 mov r3, #0 */
/* @0x13e434 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x13e438 mov r2, #0 */
/* @0x13e43c mov r3, r2 */
/* @0x13e440 mov r0, r4 */
/* @0x13e444 mov r1, r4 */
/* @0x13e448 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x13e44c mov r3, #1 */
/* @0x13e450 strb r3, [r4, #0x6c] */
/* @0x13e454 add sp, sp, #16 */
/* @0x13e458 vpop {d8} */
/* @0x13e45c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x13e460 vldr s14, [r9, #180] */
/* @0x13e464 vldr s15, [r9, #184] */
/* @0x13e468 vadd.f32 s14, s17, s14 */
/* @0x13e46c ldr r2, [pc, #0x5c] */
/* @0x13e470 mov r3, r4 */
/* @0x13e474 ldr r2, [r5, r2] */
/* @0x13e478 ldr r0, [r2] */
/* @0x13e47c vadd.f32 s15, s16, s15 */
/* @0x13e480 vmov r1, s14 */
/* @0x13e484 vmov r2, s15 */
/* @0x13e488 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x13e48c mov r4, r0 */
/* @0x13e490 b 0x13e424 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x13e494 mov r0, r7 */
/* @0x13e498 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x13e49c cmp r0, #0 */
/* @0x13e4a0 bne 0x13e3cc <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13e4a4 mov r0, r8 */
/* @0x13e4a8 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x13e4ac cmp r0, #0 */
/* @0x13e4b0 bne 0x13e3cc <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13e4b4 mov r0, r10 */
/* @0x13e4b8 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x13e4bc cmp r0, #0 */
/* @0x13e4c0 beq 0x13e454 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x13e4c4 b 0x13e3cc <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13e4c8 eoreq r3, r11, r0, lsl #18 */
/* @0x13e4cc .word 0xffffbeec */
/* @0x13e4d0 .word 0xffffbcd8 */

/* ── FUNC 0x13e4d4 · F_ActionChangeObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13e4d4 push {r4, r5, r6, lr} */
/* @0x13e4d8 mov r6, r1 */
/* @0x13e4dc ldr r4, [sp, #0x10] */
/* @0x13e4e0 mov r1, #0 */
/* @0x13e4e4 mov r0, r4 */
/* @0x13e4e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e4ec mov r1, #1 */
/* @0x13e4f0 mov r5, r0 */
/* @0x13e4f4 mov r0, r4 */
/* @0x13e4f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13e4fc mov r1, r5 */
/* @0x13e500 mov r2, r0 */
/* @0x13e504 mov r0, r6 */
/* @0x13e508 pop {r4, r5, r6, lr} */
/* @0x13e50c b 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib> */

/* ── FUNC 0x13e510 · F_ActionKillPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x13e510 push {r3, r4, r5, lr} */
/* @0x13e514 vpush {d8} */
/* @0x13e518 mov r5, r1 */
/* @0x13e51c ldr r4, [sp, #0x18] */
/* @0x13e520 mov r1, #0 */
/* @0x13e524 mov r0, r4 */
/* @0x13e528 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e52c mov r1, #1 */
/* @0x13e530 vmov s16, r0 */
/* @0x13e534 mov r0, r4 */
/* @0x13e538 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e53c ldr r3, [pc, #0x48] */
/* @0x13e540 ldr r3, [pc, r3] */
/* @0x13e544 ldrb r3, [r3] */
/* @0x13e548 cmp r3, #0 */
/* @0x13e54c vmov s15, r0 */
/* @0x13e550 bne 0x13e568 <_Z20F_ActionKillPositionR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x13e554 vmov r0, s16 */
/* @0x13e558 vpop {d8} */
/* @0x13e55c vmov r1, s15 */
/* @0x13e560 pop {r3, r4, r5, lr} */
/* @0x13e564 b 0x1c9c88 <_Z17Command_DestroyAtff> */
/* @0x13e568 vldr s13, [r5, #180] */
/* @0x13e56c vldr s14, [r5, #184] */
/* @0x13e570 vadd.f32 s13, s16, s13 */
/* @0x13e574 vpop {d8} */
/* @0x13e578 pop {r3, r4, r5, lr} */
/* @0x13e57c vadd.f32 s14, s15, s14 */
/* @0x13e580 vmov r0, s13 */
/* @0x13e584 vmov r1, s14 */
/* @0x13e588 b 0x1c9c88 <_Z17Command_DestroyAtff> */
/* @0x13e58c .word 0x002af5fc */

/* ── FUNC 0x13e590 · F_ActionSpriteTransform(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x13e590 push {r4, r5, r6, r7, r8, lr} */
/* @0x13e594 mov r5, r1 */
/* @0x13e598 ldr r4, [sp, #0x18] */
/* @0x13e59c mov r1, #0 */
/* @0x13e5a0 mov r0, r4 */
/* @0x13e5a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e5a8 mov r1, #1 */
/* @0x13e5ac mov r6, r0 */
/* @0x13e5b0 mov r0, r4 */
/* @0x13e5b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e5b8 mov r1, #2 */
/* @0x13e5bc mov r7, r0 */
/* @0x13e5c0 mov r0, r4 */
/* @0x13e5c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x13e5c8 mov r1, #3 */
/* @0x13e5cc mov r8, r0 */
/* @0x13e5d0 mov r0, r4 */
/* @0x13e5d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e5d8 mov r1, r6 */
/* @0x13e5dc mov r4, r0 */
/* @0x13e5e0 mov r0, r5 */
/* @0x13e5e4 bl 0x192fec <_ZN9CInstance14SetImageScaleXEf> */
/* @0x13e5e8 mov r0, r5 */
/* @0x13e5ec mov r1, r7 */
/* @0x13e5f0 bl 0x193014 <_ZN9CInstance14SetImageScaleYEf> */
/* @0x13e5f4 mov r0, r5 */
/* @0x13e5f8 mov r1, r8 */
/* @0x13e5fc bl 0x19303c <_ZN9CInstance13SetImageAngleEf> */
/* @0x13e600 bic r3, r4, #2 */
/* @0x13e604 cmp r3, #1 */
/* @0x13e608 beq 0x13e628 <_Z23F_ActionSpriteTransformR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x13e60c sub r4, r4, #2 */
/* @0x13e610 cmp r4, #1 */
/* @0x13e614 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x13e618 mov r0, r5 */
/* @0x13e61c eor r1, r7, #-2147483648 */
/* @0x13e620 pop {r4, r5, r6, r7, r8, lr} */
/* @0x13e624 b 0x193014 <_ZN9CInstance14SetImageScaleYEf> */
/* @0x13e628 eor r1, r6, #-2147483648 */
/* @0x13e62c mov r0, r5 */
/* @0x13e630 bl 0x192fec <_ZN9CInstance14SetImageScaleXEf> */
/* @0x13e634 b 0x13e60c <_Z23F_ActionSpriteTransformR6RValueP9CInstanceS2_iPS_+0x7c> */

/* ── FUNC 0x13e638 · F_ActionIfSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x13e638 push {r3, r4, r5, lr} */
/* @0x13e63c mov r1, #0 */
/* @0x13e640 mov r4, r0 */
/* @0x13e644 ldr r0, [sp, #0x10] */
/* @0x13e648 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e64c ldr r3, [pc, #0x68] */
/* @0x13e650 ldr r3, [pc, r3] */
/* @0x13e654 ldrb r3, [r3] */
/* @0x13e658 cmp r3, #0 */
/* @0x13e65c beq 0x13e690 <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x13e660 bl 0x21717c <_Z20Audio_SoundIsPlayingi> */
/* @0x13e664 cmp r0, #0 */
/* @0x13e668 mov r3, #0 */
/* @0x13e66c str r3, [r4, #0xc] */
/* @0x13e670 movne r2, #0 */
/* @0x13e674 movtne r2, #0x3ff0 */
/* @0x13e678 bne 0x13e684 <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x13e67c mov r3, #0 */
/* @0x13e680 mov r2, r3 */
/* @0x13e684 str r3, [r4] */
/* @0x13e688 str r2, [r4, #0x4] */
/* @0x13e68c pop {r3, r4, r5, pc} */
/* @0x13e690 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x13e694 subs r3, r0, #0 */
/* @0x13e698 beq 0x13e6b4 <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x13e69c ldr r5, [r3, #0xc] */
/* @0x13e6a0 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x13e6a4 mov r1, r0 */
/* @0x13e6a8 mov r0, r5 */
/* @0x13e6ac bl 0x21edc0 <_Z13SND_IsPlayingPKci> */
/* @0x13e6b0 b 0x13e664 <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x13e6b4 str r3, [r4, #0xc] */
/* @0x13e6b8 b 0x13e67c <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x13e6bc eoreq r0, r11, r0, ror #13 */

/* ── FUNC 0x13e6c0 · F_ActionPreviousRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x13e6c0 mov r0, #0 */
/* @0x13e6c4 b 0x1c9e68 <_Z20Command_PreviousRoomi> */

/* ── FUNC 0x13e6c8 · F_ActionNextRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x13e6c8 mov r0, #0 */
/* @0x13e6cc b 0x1c9ed0 <_Z16Command_NextRoomi> */

/* ── FUNC 0x13e6d0 · F_ActionCurrentRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x13e6d0 mov r0, #0 */
/* @0x13e6d4 b 0x1c9f38 <_Z19Command_CurrentRoomi> */

/* ── FUNC 0x13e6d8 · F_ActionAnotherRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x13e6d8 push {r3, lr} */
/* @0x13e6dc mov r1, #0 */
/* @0x13e6e0 ldr r0, [sp, #0x8] */
/* @0x13e6e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e6e8 mov r1, #0 */
/* @0x13e6ec pop {r3, lr} */
/* @0x13e6f0 b 0x1c9e08 <_Z16Command_GotoRoomii> */

/* ── FUNC 0x13e6f4 · F_ActionIfPreviousRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13e6f4 push {r3, r4, r5, lr} */
/* @0x13e6f8 mov r5, #0 */
/* @0x13e6fc str r5, [r0, #0xc] */
/* @0x13e700 mov r4, r0 */
/* @0x13e704 bl 0x1b5d08 <_Z10Room_Firstv> */
/* @0x13e708 ldr r3, [pc, #0x1c] */
/* @0x13e70c ldr r3, [pc, r3] */
/* @0x13e710 ldr r3, [r3] */
/* @0x13e714 str r5, [r4] */
/* @0x13e718 cmp r0, r3 */
/* @0x13e71c mov r3, r5 */
/* @0x13e720 movtne r3, #0x3ff0 */
/* @0x13e724 str r3, [r4, #0x4] */
/* @0x13e728 pop {r3, r4, r5, pc} */
/* @0x13e72c eoreq r0, r11, r8, asr #25 */

/* ── FUNC 0x13e730 · F_ActionIfNextRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13e730 push {r3, r4, r5, lr} */
/* @0x13e734 mov r5, #0 */
/* @0x13e738 str r5, [r0, #0xc] */
/* @0x13e73c mov r4, r0 */
/* @0x13e740 bl 0x1b5d20 <_Z9Room_Lastv> */
/* @0x13e744 ldr r3, [pc, #0x1c] */
/* @0x13e748 ldr r3, [pc, r3] */
/* @0x13e74c ldr r3, [r3] */
/* @0x13e750 str r5, [r4] */
/* @0x13e754 cmp r0, r3 */
/* @0x13e758 mov r3, r5 */
/* @0x13e75c movtne r3, #0x3ff0 */
/* @0x13e760 str r3, [r4, #0x4] */
/* @0x13e764 pop {r3, r4, r5, pc} */
/* @0x13e768 eoreq r0, r11, r12, lsl #25 */

/* ── FUNC 0x13e76c · F_ActionSetAlarm(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x13e76c push {r4, r5, r6, lr} */
/* @0x13e770 mov r6, r1 */
/* @0x13e774 ldr r4, [sp, #0x10] */
/* @0x13e778 mov r1, #1 */
/* @0x13e77c mov r0, r4 */
/* @0x13e780 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e784 mov r1, #0 */
/* @0x13e788 mov r5, r0 */
/* @0x13e78c mov r0, r4 */
/* @0x13e790 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e794 ldr r3, [pc, #0x58] */
/* @0x13e798 ldr r3, [pc, r3] */
/* @0x13e79c ldrb r3, [r3] */
/* @0x13e7a0 cmp r3, #0 */
/* @0x13e7a4 mov r4, r0 */
/* @0x13e7a8 bne 0x13e7c0 <_Z16F_ActionSetAlarmR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x13e7ac mov r0, r6 */
/* @0x13e7b0 mov r1, r5 */
/* @0x13e7b4 mov r2, r4 */
/* @0x13e7b8 pop {r4, r5, r6, lr} */
/* @0x13e7bc b 0x193148 <_ZN9CInstance8SetTimerEii> */
/* @0x13e7c0 mov r0, r6 */
/* @0x13e7c4 mov r1, r5 */
/* @0x13e7c8 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x13e7cc cmp r0, #0 */
/* @0x13e7d0 blt 0x13e7ac <_Z16F_ActionSetAlarmR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x13e7d4 mov r1, r5 */
/* @0x13e7d8 mov r0, r6 */
/* @0x13e7dc bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x13e7e0 mov r1, r5 */
/* @0x13e7e4 add r2, r0, r4 */
/* @0x13e7e8 mov r0, r6 */
/* @0x13e7ec pop {r4, r5, r6, lr} */
/* @0x13e7f0 b 0x193148 <_ZN9CInstance8SetTimerEii> */
/* @0x13e7f4 eoreq pc, r10, r4, lsr #7 */

/* ── FUNC 0x13e7f8 · F_ActionIfDice(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x13e7f8 push {r3, r4, r5, lr} */
/* @0x13e7fc mov r1, #0 */
/* @0x13e800 mov r4, r0 */
/* @0x13e804 ldr r0, [sp, #0x10] */
/* @0x13e808 mov r5, r1 */
/* @0x13e80c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13e810 vmov.f64 d6, #1.000000e+00 */
/* @0x13e814 str r5, [r4, #0xc] */
/* @0x13e818 vmov d7, r0, r1 */
/* @0x13e81c vcmpe.f64 d7, d6 */
/* @0x13e820 vmrs APSR_nzcv, fpscr */
/* @0x13e824 bls 0x13e858 <_Z14F_ActionIfDiceR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x13e828 vldr d6, [pc, #64] */
/* @0x13e82c vmul.f64 d5, d7, d6 */
/* @0x13e830 vmov r0, r1, d5 */
/* @0x13e834 bl 0xb66e8 <lrint@plt> */
/* @0x13e838 bl 0xc4600 <_Z8YYRandomi> */
/* @0x13e83c str r5, [r4] */
/* @0x13e840 cmp r0, #1000 */
/* @0x13e844 movls r3, #0 */
/* @0x13e848 movhi r3, r5 */
/* @0x13e84c movtls r3, #0x3ff0 */
/* @0x13e850 str r3, [r4, #0x4] */
/* @0x13e854 pop {r3, r4, r5, pc} */
/* @0x13e858 mov r3, r5 */
/* @0x13e85c str r5, [r4] */
/* @0x13e860 movt r3, #0x3ff0 */
/* @0x13e864 str r3, [r4, #0x4] */
/* @0x13e868 pop {r3, r4, r5, pc} */
/* @0x13e86c nop */
/* @0x13e870 andeq r0, r0, r0 */
/* @0x13e874 addmi r4, pc, r0 */

/* ── FUNC 0x13e878 · F_ActionIfScore(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x13e878 push {r3, r4, r5, r6, r7, lr} */
/* @0x13e87c vpush {d8} */
/* @0x13e880 mov r5, #0 */
/* @0x13e884 ldr r6, [sp, #0x20] */
/* @0x13e888 mov r4, r0 */
/* @0x13e88c str r5, [r0, #0xc] */
/* @0x13e890 mov r1, r5 */
/* @0x13e894 ldr r7, [pc, #0x9c] */
/* @0x13e898 mov r0, r6 */
/* @0x13e89c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13e8a0 add r7, pc, r7 */
/* @0x13e8a4 vmov d8, r0, r1 */
/* @0x13e8a8 mov r0, r6 */
/* @0x13e8ac mov r1, #1 */
/* @0x13e8b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e8b4 ldr r3, [pc, #0x80] */
/* @0x13e8b8 ldr r3, [r7, r3] */
/* @0x13e8bc vldr s14, [r3] */
/* @0x13e8c0 vcvt.f64.s32 d7, s14 */
/* @0x13e8c4 cmp r0, #1 */
/* @0x13e8c8 beq 0x13e918 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x13e8cc cmp r0, #2 */
/* @0x13e8d0 beq 0x13e8f8 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13e8d4 vcmp.f64 d7, d8 */
/* @0x13e8d8 vmrs APSR_nzcv, fpscr */
/* @0x13e8dc bne 0x13e904 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x13e8e0 mov r3, #0 */
/* @0x13e8e4 movt r3, #0x3ff0 */
/* @0x13e8e8 str r5, [r4] */
/* @0x13e8ec str r3, [r4, #0x4] */
/* @0x13e8f0 vpop {d8} */
/* @0x13e8f4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x13e8f8 vcmpe.f64 d8, d7 */
/* @0x13e8fc vmrs APSR_nzcv, fpscr */
/* @0x13e900 bmi 0x13e8e0 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x13e904 mov r3, r5 */
/* @0x13e908 str r5, [r4] */
/* @0x13e90c str r3, [r4, #0x4] */
/* @0x13e910 vpop {d8} */
/* @0x13e914 pop {r3, r4, r5, r6, r7, pc} */
/* @0x13e918 vcmpe.f64 d8, d7 */
/* @0x13e91c mov r3, r5 */
/* @0x13e920 vmrs APSR_nzcv, fpscr */
/* @0x13e924 bgt 0x13e8e4 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x13e928 str r5, [r4] */
/* @0x13e92c str r3, [r4, #0x4] */
/* @0x13e930 vpop {d8} */
/* @0x13e934 pop {r3, r4, r5, r6, r7, pc} */
/* @0x13e938 .word 0x002b33b0 */
/* @0x13e93c .word 0xffffce34 */

/* ── FUNC 0x13e940 · F_ActionIfHealth(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x13e940 push {r4, r5, r6, lr} */
/* @0x13e944 vpush {d8} */
/* @0x13e948 mov r4, r0 */
/* @0x13e94c ldr r5, [sp, #0x18] */
/* @0x13e950 mov r1, #0 */
/* @0x13e954 ldr r6, [pc, #0x94] */
/* @0x13e958 mov r0, r5 */
/* @0x13e95c add r6, pc, r6 */
/* @0x13e960 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13e964 vmov d8, r0, r1 */
/* @0x13e968 mov r0, r5 */
/* @0x13e96c mov r1, #1 */
/* @0x13e970 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13e974 ldr r3, [pc, #0x78] */
/* @0x13e978 ldr r3, [r6, r3] */
/* @0x13e97c vldr d7, [r3] */
/* @0x13e980 cmp r0, #1 */
/* @0x13e984 beq 0x13e9c8 <_Z16F_ActionIfHealthR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x13e988 cmp r0, #2 */
/* @0x13e98c beq 0x13e9dc <_Z16F_ActionIfHealthR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13e990 vcmp.f64 d7, d8 */
/* @0x13e994 vmrs APSR_nzcv, fpscr */
/* @0x13e998 movne r3, #0 */
/* @0x13e99c moveq r3, #1 */
/* @0x13e9a0 cmp r3, #0 */
/* @0x13e9a4 mov r2, #0 */
/* @0x13e9a8 str r2, [r4, #0xc] */
/* @0x13e9ac movne r3, r2 */
/* @0x13e9b0 moveq r2, r3 */
/* @0x13e9b4 movtne r2, #0x3ff0 */
/* @0x13e9b8 str r3, [r4] */
/* @0x13e9bc str r2, [r4, #0x4] */
/* @0x13e9c0 vpop {d8} */
/* @0x13e9c4 pop {r4, r5, r6, pc} */
/* @0x13e9c8 vcmpe.f64 d7, d8 */
/* @0x13e9cc vmrs APSR_nzcv, fpscr */
/* @0x13e9d0 movpl r3, #0 */
/* @0x13e9d4 movmi r3, #1 */
/* @0x13e9d8 b 0x13e9a0 <_Z16F_ActionIfHealthR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x13e9dc vcmpe.f64 d7, d8 */
/* @0x13e9e0 vmrs APSR_nzcv, fpscr */
/* @0x13e9e4 movle r3, #0 */
/* @0x13e9e8 movgt r3, #1 */
/* @0x13e9ec b 0x13e9a0 <_Z16F_ActionIfHealthR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x13e9f0 .word 0x002b32f4 */
/* @0x13e9f4 .word 0xffffd788 */

/* ── FUNC 0x13e9f8 · F_ActionIfAligned(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0x13e9f8 push {r4, r5, r6, lr} */
/* @0x13e9fc vpush {d8, d9, d10} */
/* @0x13ea00 mov r3, #0 */
/* @0x13ea04 ldr r5, [sp, #0x28] */
/* @0x13ea08 mov r4, r0 */
/* @0x13ea0c str r3, [r0, #0xc] */
/* @0x13ea10 mov r6, r1 */
/* @0x13ea14 str r3, [r0] */
/* @0x13ea18 mov r1, r3 */
/* @0x13ea1c str r3, [r4, #0x4] */
/* @0x13ea20 mov r0, r5 */
/* @0x13ea24 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13ea28 vmov d8, r0, r1 */
/* @0x13ea2c mov r0, r5 */
/* @0x13ea30 mov r1, #1 */
/* @0x13ea34 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13ea38 vcmpe.f64 d8, #0 */
/* @0x13ea3c vmrs APSR_nzcv, fpscr */
/* @0x13ea40 vmov d9, r0, r1 */
/* @0x13ea44 ble 0x13ea7c <_Z17F_ActionIfAlignedR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x13ea48 vldr s20, [r6, #180] */
/* @0x13ea4c vcvt.f64.f32 d10, s20 */
/* @0x13ea50 vdiv.f64 d7, d10, d8 */
/* @0x13ea54 vmov r0, r1, d7 */
/* @0x13ea58 bl 0xb66e8 <lrint@plt> */
/* @0x13ea5c vldr d7, [pc, #116] */
/* @0x13ea60 vmov s11, r0 */
/* @0x13ea64 vcvt.f64.s32 d6, s11 */
/* @0x13ea68 vmls.f64 d10, d6, d8 */
/* @0x13ea6c vabs.f64 d10, d10 */
/* @0x13ea70 vcmpe.f64 d10, d7 */
/* @0x13ea74 vmrs APSR_nzcv, fpscr */
/* @0x13ea78 bge 0x13eacc <_Z17F_ActionIfAlignedR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x13ea7c vcmpe.f64 d9, #0 */
/* @0x13ea80 vmrs APSR_nzcv, fpscr */
/* @0x13ea84 ble 0x13eabc <_Z17F_ActionIfAlignedR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x13ea88 vldr s16, [r6, #184] */
/* @0x13ea8c vcvt.f64.f32 d8, s16 */
/* @0x13ea90 vdiv.f64 d7, d8, d9 */
/* @0x13ea94 vmov r0, r1, d7 */
/* @0x13ea98 bl 0xb66e8 <lrint@plt> */
/* @0x13ea9c vldr d7, [pc, #52] */
/* @0x13eaa0 vmov s11, r0 */
/* @0x13eaa4 vcvt.f64.s32 d6, s11 */
/* @0x13eaa8 vmls.f64 d8, d6, d9 */
/* @0x13eaac vabs.f64 d8, d8 */
/* @0x13eab0 vcmpe.f64 d8, d7 */
/* @0x13eab4 vmrs APSR_nzcv, fpscr */
/* @0x13eab8 bge 0x13eacc <_Z17F_ActionIfAlignedR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x13eabc mov r3, #0 */
/* @0x13eac0 mov r2, r3 */
/* @0x13eac4 movt r3, #0x3ff0 */
/* @0x13eac8 stm r4, {r2, r3} */
/* @0x13eacc vpop {d8, d9, d10} */
/* @0x13ead0 pop {r4, r5, r6, pc} */
/* @0x13ead4 nop */
/* @0x13ead8 rscsle r10, r1, #252, #18 */
/* @0x13eadc svclo #0x50624d */

/* ── FUNC 0x13eae0 · F_ActionSleep(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x13eae0 push {r4, lr} */
/* @0x13eae4 vpush {d8} */
/* @0x13eae8 mov r1, #0 */
/* @0x13eaec ldr r4, [sp, #0x10] */
/* @0x13eaf0 mov r0, r4 */
/* @0x13eaf4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13eaf8 vmov d8, r0, r1 */
/* @0x13eafc mov r0, r4 */
/* @0x13eb00 mov r1, #1 */
/* @0x13eb04 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13eb08 cmp r0, #0 */
/* @0x13eb0c beq 0x13eb20 <_Z13F_ActionSleepR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x13eb10 bl 0x1b3e98 <_Z9Draw_Roomv> */
/* @0x13eb14 mov r0, #1 */
/* @0x13eb18 bl 0x169a58 <_Z19GR_D3D_Finish_Frameb> */
/* @0x13eb1c bl 0x1699c0 <_Z18GR_D3D_Start_Framev> */
/* @0x13eb20 vldr d7, [pc, #24] */
/* @0x13eb24 vmul.f64 d6, d8, d7 */
/* @0x13eb28 vmov r0, r1, d6 */
/* @0x13eb2c bl 0xb66e8 <lrint@plt> */
/* @0x13eb30 vpop {d8} */
/* @0x13eb34 pop {r4, lr} */
/* @0x13eb38 asr r1, r0, #31 */
/* @0x13eb3c b 0x2151f0 <Timing_Sleep> */
/* @0x13eb40 andeq r0, r0, r0 */
/* @0x13eb44 addmi r4, pc, r0 */

/* ── FUNC 0x13eb48 · F_ActionShowInfo(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x13eb48 b 0x18c2c8 <_Z8IO_Clearv> */

/* ── FUNC 0x13eb4c · F_ActionMessage(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x13eb4c ldr r1, [pc, #0x70] */
/* @0x13eb50 mov r12, #16 */
/* @0x13eb54 push {r4, lr} */
/* @0x13eb58 sub sp, sp, #16 */
/* @0x13eb5c mov r0, r12 */
/* @0x13eb60 add r1, pc, r1 */
/* @0x13eb64 movw r2, #0x39e */
/* @0x13eb68 mov r3, #1 */
/* @0x13eb6c str r12, [sp, #0x4] */
/* @0x13eb70 ldr r4, [sp, #0x18] */
/* @0x13eb74 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13eb78 mov r1, #0 */
/* @0x13eb7c mov r3, r4 */
/* @0x13eb80 mov r2, r0 */
/* @0x13eb84 str r0, [sp, #0x8] */
/* @0x13eb88 add r0, sp, #16 */
/* @0x13eb8c str r2, [r0, #-0x4]! */
/* @0x13eb90 strb r1, [r2] */
/* @0x13eb94 add r1, sp, #8 */
/* @0x13eb98 add r2, sp, #4 */
/* @0x13eb9c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x13eba0 ldr r0, [sp, #0x8] */
/* @0x13eba4 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x13eba8 ldr r0, [sp, #0x8] */
/* @0x13ebac bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x13ebb0 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x13ebb4 ldr r0, [sp, #0x8] */
/* @0x13ebb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13ebbc add sp, sp, #16 */
/* @0x13ebc0 pop {r4, pc} */
/* @0x13ebc4 eoreq r1, r0, r12, lsl #27 */
