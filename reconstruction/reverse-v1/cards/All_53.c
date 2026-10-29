/* cally 逆向卡：All_53 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 137 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/137 RemoveDialogAndKick(HTTP_REQ_CONTEXT*)  0xf1d98  size 228  57 条（0xf1d98..0xf1e7c）
 * @func 0xf1d98 0xf1e7c  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×7 / 0x44×5 / 0x48×3 / 0x4c×3 / 0xd8×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1d98 ldr r3, [pc, #0xd8]
 *   @0xf1d9c ldr r3, [pc, r3]
 *   @0xf1da0 ldr r12, [r3]
 *   @0xf1da4 cmp r12, #0
 *   @0xf1da8 bxeq lr
 *   @0xf1dac ldr r2, [r12, #0x24]
 *   @0xf1db0 ldr r0, [r0, #0x24]
 *   @0xf1db4 cmp r2, r0
 *   @0xf1db8 movne r2, r12
 *   @0xf1dbc bne 0xf1dd4 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x3c>
 *   @0xf1dc0 b 0xf1e64 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0xcc>
 *   @0xf1dc4 ldr r1, [r3, #0x24]
 *   @0xf1dc8 cmp r1, r0
 *   @0xf1dcc beq 0xf1e14 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x7c>
 *   @0xf1dd0 mov r2, r3
 *   @0xf1dd4 ldr r3, [r2, #0x44]
 *   @0xf1dd8 cmp r3, #0
 *   @0xf1ddc bne 0xf1dc4 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x2c>
 *   @0xf1de0 b 0xf1de8 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x50>
 *   @0xf1de4 mov r12, r3
 *   @0xf1de8 ldr r3, [r12, #0x44]
 *   @0xf1dec cmp r3, #0
 *   @0xf1df0 bne 0xf1de4 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x4c>
 *   @0xf1df4 ldr r3, [r12, #0x54]
 *   @0xf1df8 cmp r3, #3
 *   @0xf1dfc addls pc, pc, r3, lsl #2
 *   @0xf1e00 b 0xf1e20 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x88>
 *   @0xf1e04 b 0xf1e34 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x9c>
 *   @0xf1e08 b 0xf1e44 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0xac>
 *   @0xf1e0c b 0xf1e54 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0xbc>
 *   @0xf1e10 b 0xf1e24 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x8c>
 *   @0xf1e14 ldr r3, [r3, #0x44]
 *   @0xf1e18 str r3, [r2, #0x44]
 *   @0xf1e1c b 0xf1de8 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x50>
 *   @0xf1e20 bx lr
 *   @0xf1e24 ldr r0, [r12, #0x48]
 *   @0xf1e28 ldr r1, [r12, #0x4c]
 *   @0xf1e2c ldr r2, [r12, #0x24]
 *   @0xf1e30 b 0xf2ad0 <loginDialogAsync>
 *   @0xf1e34 add r0, r12, #72
 *   @0xf1e38 ldr r3, [r12, #0x24]
 *   @0xf1e3c ldm r0, {r0, r1, r2}
 *   @0xf1e40 b 0xf29f4 <inputDialogAsync>
 *   @0xf1e44 ldr r0, [r12, #0x48]
 *   @0xf1e48 ldr r1, [r12, #0x4c]
 *   @0xf1e4c ldr r2, [r12, #0x24]
 *   @0xf1e50 b 0xf2a70 <questionDialogAsync>
 *   @0xf1e54 ldr r0, [r12, #0x48]
 *   @0xf1e58 ldr r1, [r12, #0x4c]
 *   @0xf1e5c ldr r2, [r12, #0x24]
 *   @0xf1e60 b 0xf2b4c <showMessage>
 *   @0xf1e64 ldr r12, [r12, #0x44]
 *   @0xf1e68 cmp r12, #0
 *   @0xf1e6c str r12, [r3]
 *   @0xf1e70 bxeq lr
 *   @0xf1e74 b 0xf1de8 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x50>
 *   @0xf1e78 eoreq r12, pc, r8, asr #32
 *
 * ══ §2/137 F_ExternalDefine1(RValue&, CInstance*, CInstance*, int, RValue*)  0x115f50  size 228  57 条（0x115f50..0x116034）
 * @func 0x115f50 0x116034  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / YYGetInt32(RValue const*, int)×2 / 0xb65b0 / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x70×1 / 0x4×1 / 0xc×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115f50 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x115f54 sub sp, sp, #84
 *   @0x115f58 add r5, sp, #12
 *   @0x115f5c mov r2, #68
 *   @0x115f60 ldr r4, [sp, #0x70]
 *   @0x115f64 mov r6, r0
 *   @0x115f68 mov r1, #0
 *   @0x115f6c mov r0, r5
 *   @0x115f70 bl 0xb65b0 <memset@plt>
 *   @0x115f74 mov r1, #0
 *   @0x115f78 mov r0, r4
 *   @0x115f7c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x115f80 mov r1, #1
 *   @0x115f84 mov r9, r0
 *   @0x115f88 mov r0, r4
 *   @0x115f8c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x115f90 mov r1, #2
 *   @0x115f94 mov r8, r0
 *   @0x115f98 mov r0, r4
 *   @0x115f9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115fa0 mov r1, #3
 *   @0x115fa4 mov r7, r0
 *   @0x115fa8 mov r0, r4
 *   @0x115fac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115fb0 cmp r7, #1
 *   @0x115fb4 streq r7, [sp, #0xc]
 *   @0x115fb8 mov r7, #0
 *   @0x115fbc movne r3, #0
 *   @0x115fc0 str r5, [sp]
 *   @0x115fc4 mov r1, r8
 *   @0x115fc8 strne r3, [sp, #0xc]
 *   @0x115fcc subs r2, r0, #1
 *   @0x115fd0 rsbs r3, r2, #0
 *   @0x115fd4 mov r0, r9
 *   @0x115fd8 adcs r3, r3, r2
 *   @0x115fdc mov r2, r7
 *   @0x115fe0 str r3, [sp, #0x4]
 *   @0x115fe4 mov r3, #1
 *   @0x115fe8 str r7, [r6, #0xc]
 *   @0x115fec bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x115ff0 vmov.f64 d7, #-1.000000e+00
 *   @0x115ff4 vmov s13, r0
 *   @0x115ff8 vcvt.f64.s32 d6, s13
 *   @0x115ffc vmov r0, r1, d6
 *   @0x116000 vmov r2, s12
 *   @0x116004 vcmp.f64 d6, d7
 *   @0x116008 vmrs APSR_nzcv, fpscr
 *   @0x11600c mov r3, r1
 *   @0x116010 stm r6, {r2, r3}
 *   @0x116014 bne 0x116028 <_Z17F_ExternalDefine1R6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x116018 ldr r0, [pc, #0x10]
 *   @0x11601c mov r1, r7
 *   @0x116020 add r0, pc, r0
 *   @0x116024 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x116028 add sp, sp, #84
 *   @0x11602c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x116030 eoreq r3, r2, r0, lsl #13
 *
 * ══ §3/137 F_GameSetSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x116758  size 228  57 条（0x116758..0x11683c）
 * @func 0x116758 0x11683c  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1167c4→0x5428c0, 0x1167e0→0x5428c0, 0x1167fc→0x5428c0
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x18×1 / 0xc0×1 / 0x68×1 / 0x4c×1 / 0x30×1 / 0x1c×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116758 push {r4, r5, r6, lr}
 *   @0x11675c vpush {d8}
 *   @0x116760 mov r1, #0
 *   @0x116764 ldr r4, [sp, #0x18]
 *   @0x116768 ldr r5, [pc, #0xc0]
 *   @0x11676c mov r0, r4
 *   @0x116770 add r5, pc, r5
 *   @0x116774 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x116778 vmov d8, r0, r1
 *   @0x11677c mov r0, r4
 *   @0x116780 mov r1, #1
 *   @0x116784 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x116788 vcmpe.f64 d8, #0
 *   @0x11678c vmrs APSR_nzcv, fpscr
 *   @0x116790 bmi 0x11680c <_Z14F_GameSetSpeedR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x116794 vcmp.f64 d8, #0
 *   @0x116798 vmrs APSR_nzcv, fpscr
 *   @0x11679c beq 0x1167d8 <_Z14F_GameSetSpeedR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1167a0 cmp r0, #0
 *   @0x1167a4 beq 0x1167f4 <_Z14F_GameSetSpeedR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1167a8 cmp r0, #1
 *   @0x1167ac beq 0x1167b8 <_Z14F_GameSetSpeedR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x1167b0 vpop {d8}
 *   @0x1167b4 pop {r4, r5, r6, pc}
 *   @0x1167b8 vldr d7, [pc, #104]
 *   @0x1167bc vdiv.f64 d6, d7, d8
 *   @0x1167c0 vpop {d8}
 *   @0x1167c4 ldr r1, [pc, #0x68]
 *   @0x1167c8 ldr r0, [r5, r1]
 *   @0x1167cc pop {r4, r5, r6, lr}
 *   @0x1167d0 vmov r2, r3, d6
 *   @0x1167d4 b 0x214800 <_ZN13CTimingSource12SetFrameRateEd>
 *   @0x1167d8 vpop {d8}
 *   @0x1167dc mov r2, #0
 *   @0x1167e0 ldr r1, [pc, #0x4c]
 *   @0x1167e4 mov r3, #0
 *   @0x1167e8 ldr r0, [r5, r1]
 *   @0x1167ec pop {r4, r5, r6, lr}
 *   @0x1167f0 b 0x214800 <_ZN13CTimingSource12SetFrameRateEd>
 *   @0x1167f4 vmov r2, r3, d8
 *   @0x1167f8 vpop {d8}
 *   @0x1167fc ldr r1, [pc, #0x30]
 *   @0x116800 ldr r0, [r5, r1]
 *   @0x116804 pop {r4, r5, r6, lr}
 *   @0x116808 b 0x214800 <_ZN13CTimingSource12SetFrameRateEd>
 *   @0x11680c vpop {d8}
 *   @0x116810 mov r1, #0
 *   @0x116814 ldr r0, [pc, #0x1c]
 *   @0x116818 add r0, pc, r0
 *   @0x11681c pop {r4, r5, r6, lr}
 *   @0x116820 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x116824 nop
 *   @0x116828 andeq r0, r0, r0
 *   @0x11682c smlawbmi lr, r0, r4, r8
 *   @0x116830 eoreq r11, sp, r0, ror #9
 *   @0x116834 .word 0xffffbcdc
 *   @0x116838 mlaeq r2, r0, pc, r2
 *
 * ══ §4/137 F_DrawSpriteTiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x122e90  size 228  57 条（0x122e90..0x122f74）
 * @func 0x122e90 0x122f74  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / GetSpriteIndices(CInstance*, RValue*, int&, int&) / Sprite_Data(int) / GR_Draw_Get_Alpha() / CSprite::DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x50×1 / 0x28×1 / 0x2c×1 / 0x74×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122e90 push {r4, r5, r6, r7, lr}
 *   @0x122e94 vpush {d8}
 *   @0x122e98 sub sp, sp, #52
 *   @0x122e9c mov r0, r1
 *   @0x122ea0 add r2, sp, #40
 *   @0x122ea4 ldr r4, [sp, #0x50]
 *   @0x122ea8 add r3, sp, #44
 *   @0x122eac mov r1, r4
 *   @0x122eb0 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_>
 *   @0x122eb4 cmp r0, #0
 *   @0x122eb8 bne 0x122ec8 <_Z17F_DrawSpriteTiledR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x122ebc add sp, sp, #52
 *   @0x122ec0 vpop {d8}
 *   @0x122ec4 pop {r4, r5, r6, r7, pc}
 *   @0x122ec8 ldr r0, [sp, #0x28]
 *   @0x122ecc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x122ed0 mov r1, #2
 *   @0x122ed4 ldr r7, [sp, #0x2c]
 *   @0x122ed8 mov r5, r0
 *   @0x122edc mov r0, r4
 *   @0x122ee0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122ee4 mov r1, #3
 *   @0x122ee8 mov r6, r0
 *   @0x122eec mov r0, r4
 *   @0x122ef0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122ef4 ldr r12, [pc, #0x74]
 *   @0x122ef8 ldr r12, [pc, r12]
 *   @0x122efc ldr r12, [r12]
 *   @0x122f00 vldr s17, [r12, #16]
 *   @0x122f04 vldr s16, [r12, #20]
 *   @0x122f08 vcvt.f32.s32 s17, s17
 *   @0x122f0c vcvt.f32.s32 s16, s16
 *   @0x122f10 mov r4, r0
 *   @0x122f14 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x122f18 mov lr, #0
 *   @0x122f1c mov r12, #1
 *   @0x122f20 vstr s17, [sp, #24]
 *   @0x122f24 str r12, [sp, #0x8]
 *   @0x122f28 str r12, [sp, #0xc]
 *   @0x122f2c mov r1, r7
 *   @0x122f30 mov r2, r6
 *   @0x122f34 mov r3, r4
 *   @0x122f38 str lr, [sp, #0x10]
 *   @0x122f3c mvn r12, #-16777216
 *   @0x122f40 str lr, [sp, #0x14]
 *   @0x122f44 vstr s16, [sp, #28]
 *   @0x122f48 str r12, [sp, #0x20]
 *   @0x122f4c mov r12, #1065353216
 *   @0x122f50 str r12, [sp]
 *   @0x122f54 str r12, [sp, #0x4]
 *   @0x122f58 str r0, [sp, #0x24]
 *   @0x122f5c mov r0, r5
 *   @0x122f60 bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf>
 *   @0x122f64 add sp, sp, #52
 *   @0x122f68 vpop {d8}
 *   @0x122f6c pop {r4, r5, r6, r7, pc}
 *   @0x122f70 eoreq r10, r12, r0, lsr r10
 *
 * ══ §5/137 F_ShowMessage(RValue&, CInstance*, CInstance*, int, RValue*)  0x126e60  size 228  57 条（0x126e60..0x126f44）
 * @func 0x126e60 0x126f44  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ShowMessage(char const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / DebuggerIsConnected() / DebuggerRunBackgroundMessageLoop() / DebuggerStopBackgroundMessageLoop() / IO_Clear()
 * 字段偏移 top8: 0x8×5 / 0x18×2 / 0xcc×1 / 0x4×1 / 0x-4×1 / 0x68×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126e60 ldr r1, [pc, #0xcc]
 *   @0x126e64 mov r12, #16
 *   @0x126e68 push {r4, lr}
 *   @0x126e6c sub sp, sp, #16
 *   @0x126e70 mov r0, r12
 *   @0x126e74 add r1, pc, r1
 *   @0x126e78 movw r2, #0x575
 *   @0x126e7c mov r3, #1
 *   @0x126e80 str r12, [sp, #0x4]
 *   @0x126e84 ldr r4, [sp, #0x18]
 *   @0x126e88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x126e8c mov r1, #0
 *   @0x126e90 mov r3, r4
 *   @0x126e94 mov r2, r0
 *   @0x126e98 str r0, [sp, #0x8]
 *   @0x126e9c add r0, sp, #16
 *   @0x126ea0 str r2, [r0, #-0x4]!
 *   @0x126ea4 strb r1, [r2]
 *   @0x126ea8 add r1, sp, #8
 *   @0x126eac add r2, sp, #4
 *   @0x126eb0 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x126eb4 ldr r0, [sp, #0x8]
 *   @0x126eb8 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x126ebc bl 0x29cb74 <_Z19DebuggerIsConnectedv>
 *   @0x126ec0 cmp r0, #0
 *   @0x126ec4 beq 0x126f14 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x126ec8 ldr r3, [pc, #0x68]
 *   @0x126ecc ldr r3, [pc, r3]
 *   @0x126ed0 ldrb r3, [r3]
 *   @0x126ed4 cmp r3, #0
 *   @0x126ed8 beq 0x126ef0 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x126edc ldr r3, [pc, #0x58]
 *   @0x126ee0 ldr r3, [pc, r3]
 *   @0x126ee4 ldr r3, [r3]
 *   @0x126ee8 cmp r3, #0
 *   @0x126eec beq 0x126f20 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x126ef0 bl 0x29cb88 <_Z32DebuggerRunBackgroundMessageLoopv>
 *   @0x126ef4 ldr r0, [sp, #0x8]
 *   @0x126ef8 bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x126efc bl 0x29cc30 <_Z33DebuggerStopBackgroundMessageLoopv>
 *   @0x126f00 bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126f04 ldr r0, [sp, #0x8]
 *   @0x126f08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x126f0c add sp, sp, #16
 *   @0x126f10 pop {r4, pc}
 *   @0x126f14 ldr r0, [sp, #0x8]
 *   @0x126f18 bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x126f1c b 0x126f00 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x126f20 ldr r1, [pc, #0x18]
 *   @0x126f24 mov r0, #1
 *   @0x126f28 add r1, pc, r1
 *   @0x126f2c bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x126f30 b 0x126ef0 <_Z13F_ShowMessageR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x126f34 eoreq r5, r1, r0, asr #7
 *   @0x126f38 eoreq r6, r12, r8, asr r10
 *   @0x126f3c eoreq r7, r12, r0, asr #10
 *   @0x126f40 eoreq r5, r1, r0, asr r3
 *
 * ══ §6/137 F_SoundEffectReverb(RValue&, CInstance*, CInstance*, int, RValue*)  0x13445c  size 228  57 条（0x13445c..0x134540）
 * @func 0x13445c 0x134540  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×4 / YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId() / SND_Set_Effect_Reverb(int, double, double, double, double)
 * 字段偏移 top8: 0xd0×1 / 0x40×1 / 0xb4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13445c ldr r3, [pc, #0xd0]
 *   @0x134460 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x134464 ldr r3, [pc, r3]
 *   @0x134468 sub sp, sp, #28
 *   @0x13446c ldrb r3, [r3]
 *   @0x134470 ldr r10, [sp, #0x40]
 *   @0x134474 cmp r3, #0
 *   @0x134478 bne 0x134490 <_Z19F_SoundEffectReverbR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x13447c ldr r3, [pc, #0xb4]
 *   @0x134480 ldr r3, [pc, r3]
 *   @0x134484 ldrb r1, [r3]
 *   @0x134488 cmp r1, #0
 *   @0x13448c beq 0x134498 <_Z19F_SoundEffectReverbR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x134490 add sp, sp, #28
 *   @0x134494 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x134498 mov r0, r10
 *   @0x13449c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1344a0 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x1344a4 subs r1, r0, #0
 *   @0x1344a8 beq 0x134520 <_Z19F_SoundEffectReverbR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x1344ac bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x1344b0 mov r1, #1
 *   @0x1344b4 mov r11, r0
 *   @0x1344b8 mov r0, r10
 *   @0x1344bc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1344c0 mov r4, r0
 *   @0x1344c4 mov r5, r1
 *   @0x1344c8 mov r0, r10
 *   @0x1344cc mov r1, #2
 *   @0x1344d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1344d4 mov r8, r0
 *   @0x1344d8 mov r9, r1
 *   @0x1344dc mov r0, r10
 *   @0x1344e0 mov r1, #3
 *   @0x1344e4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1344e8 mov r6, r0
 *   @0x1344ec mov r7, r1
 *   @0x1344f0 mov r0, r10
 *   @0x1344f4 mov r1, #4
 *   @0x1344f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1344fc strd r8, r9, [sp]
 *   @0x134500 strd r6, r7, [sp, #8]
 *   @0x134504 mov r2, r4
 *   @0x134508 mov r3, r5
 *   @0x13450c strd r0, r1, [sp, #16]
 *   @0x134510 mov r0, r11
 *   @0x134514 bl 0x21f154 <_Z21SND_Set_Effect_Reverbidddd>
 *   @0x134518 add sp, sp, #28
 *   @0x13451c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x134520 ldr r0, [pc, #0x14]
 *   @0x134524 add r0, pc, r0
 *   @0x134528 add sp, sp, #28
 *   @0x13452c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x134530 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x134534 eoreq r10, r11, r12, asr #17
 *   @0x134538 eoreq r10, r11, r12, asr #23
 *   @0x13453c eoreq r10, r0, r8, ror #30
 *
 * ══ §7/137 F_ActionDrawText(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f0d8  size 228  57 条（0x13f0d8..0x13f1bc）
 * @func 0x13f0d8 0x13f1bc  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / GR_Text_Draw(float, float, char const*, int, int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x10×4 / 0xc8×1 / 0xc×1 / 0x30×1 / 0x-4×1 / 0x58×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f0d8 push {r4, r5, lr}
 *   @0x13f0dc vpush {d8}
 *   @0x13f0e0 mov r5, r1
 *   @0x13f0e4 ldr r1, [pc, #0xc8]
 *   @0x13f0e8 sub sp, sp, #28
 *   @0x13f0ec mov r12, #16
 *   @0x13f0f0 movw r2, #0x7fb
 *   @0x13f0f4 mov r0, r12
 *   @0x13f0f8 add r1, pc, r1
 *   @0x13f0fc mov r3, #1
 *   @0x13f100 str r12, [sp, #0xc]
 *   @0x13f104 ldr r4, [sp, #0x30]
 *   @0x13f108 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13f10c add r1, sp, #16
 *   @0x13f110 mov r2, #0
 *   @0x13f114 mov r3, r0
 *   @0x13f118 add r0, sp, #24
 *   @0x13f11c str r3, [sp, #0x10]
 *   @0x13f120 str r3, [r0, #-0x4]!
 *   @0x13f124 strb r2, [r3]
 *   @0x13f128 mov r3, r4
 *   @0x13f12c add r2, sp, #12
 *   @0x13f130 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x13f134 ldr r0, [sp, #0x10]
 *   @0x13f138 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x13f13c mov r0, r4
 *   @0x13f140 mov r1, #1
 *   @0x13f144 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f148 mov r1, #2
 *   @0x13f14c vmov s16, r0
 *   @0x13f150 mov r0, r4
 *   @0x13f154 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f158 ldr r3, [pc, #0x58]
 *   @0x13f15c mvn r1, #0
 *   @0x13f160 ldr r2, [sp, #0x10]
 *   @0x13f164 ldr r3, [pc, r3]
 *   @0x13f168 ldrb r3, [r3]
 *   @0x13f16c str r1, [sp]
 *   @0x13f170 cmp r3, #0
 *   @0x13f174 vldrne s13, [r5, #180]
 *   @0x13f178 vldrne s14, [r5, #184]
 *   @0x13f17c mov r3, r1
 *   @0x13f180 vmov s15, r0
 *   @0x13f184 vaddne.f32 s13, s16, s13
 *   @0x13f188 vmoveq r0, s16
 *   @0x13f18c vmoveq r1, s15
 *   @0x13f190 vaddne.f32 s14, s15, s14
 *   @0x13f194 vmovne r0, s13
 *   @0x13f198 vmovne r1, s14
 *   @0x13f19c bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x13f1a0 ldr r0, [sp, #0x10]
 *   @0x13f1a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13f1a8 add sp, sp, #28
 *   @0x13f1ac vpop {d8}
 *   @0x13f1b0 pop {r4, r5, pc}
 *   @0x13f1b4 .word 0x002017f4
 *   @0x13f1b8 .word 0x002ae9d8
 *
 * ══ §8/137 F_YoYo_OsGetInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x156fb0  size 228  57 条（0x156fb0..0x157094）
 * @func 0x156fb0 0x157094  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Os_Get_Info() / GetDsMap(int) / YYUDID(char**) / 0xb6574 / 0xb6550 / CDS_Map::Add(char const*, double, char const*) / 0xb65d4
 * 字段偏移 top8: 0x80c×2 / 0x8×2 / 0xc4×1 / 0x88×1 / 0x70×1 / 0x5c×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156fb0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x156fb4 sub sp, sp, #2064
 *   @0x156fb8 ldr r4, [pc, #0xc4]
 *   @0x156fbc sub sp, sp, #4
 *   @0x156fc0 mov r5, r0
 *   @0x156fc4 add r6, sp, #16
 *   @0x156fc8 ldr r4, [pc, r4]
 *   @0x156fcc ldr r3, [r4]
 *   @0x156fd0 str r3, [sp, #0x80c]
 *   @0x156fd4 bl 0x161220 <_Z11Os_Get_Infov>
 *   @0x156fd8 mov r8, r0
 *   @0x156fdc bl 0x2052d4 <_Z8GetDsMapi>
 *   @0x156fe0 mov r3, #0
 *   @0x156fe4 str r3, [sp, #0x8]
 *   @0x156fe8 mov r9, r0
 *   @0x156fec sub r0, r6, #8
 *   @0x156ff0 bl 0x15f574 <_Z6YYUDIDPPc>
 *   @0x156ff4 ldr r7, [sp, #0x8]
 *   @0x156ff8 ldr r1, [pc, #0x88]
 *   @0x156ffc mov r0, r7
 *   @0x157000 add r1, pc, r1
 *   @0x157004 bl 0xb6574 <strcmp@plt>
 *   @0x157008 cmp r0, #0
 *   @0x15700c beq 0x157048 <_Z16F_YoYo_OsGetInfoR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x157010 sub r6, r6, #4
 *   @0x157014 ldr r1, [pc, #0x70]
 *   @0x157018 mov r3, r7
 *   @0x15701c movw r2, #0x7ff
 *   @0x157020 add r1, pc, r1
 *   @0x157024 mov r0, r6
 *   @0x157028 bl 0xb6550 <sprintf@plt>
 *   @0x15702c ldr r1, [pc, #0x5c]
 *   @0x157030 str r6, [sp]
 *   @0x157034 mov r0, r9
 *   @0x157038 add r1, pc, r1
 *   @0x15703c mov r2, #0
 *   @0x157040 mov r3, #0
 *   @0x157044 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x157048 vmov s15, r8
 *   @0x15704c ldr r1, [sp, #0x80c]
 *   @0x157050 mov r0, #0
 *   @0x157054 str r0, [r5, #0xc]
 *   @0x157058 vcvt.f64.s32 d7, s15
 *   @0x15705c vmov r2, r3, d7
 *   @0x157060 vstr s14, [r5]
 *   @0x157064 ldr r2, [r4]
 *   @0x157068 cmp r1, r2
 *   @0x15706c str r3, [r5, #0x4]
 *   @0x157070 bne 0x157080 <_Z16F_YoYo_OsGetInfoR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x157074 add sp, sp, #2064
 *   @0x157078 add sp, sp, #4
 *   @0x15707c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x157080 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x157084 eoreq r6, r9, r8, lsl #19
 *   @0x157088 mulseq lr, r12, r6
 *   @0x15708c mulseq lr, r0, r6
 *   @0x157090 andseq pc, lr, r0, lsl #13
 *
 * ══ §9/137 F_YoYo_MD5Utf8(RValue&, CInstance*, CInstance*, int, RValue*)  0x157c54  size 228  57 条（0x157c54..0x157d38）
 * @func 0x157c54 0x157d38  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / MD5Init(MD5_CTX*) / 0xb6538 / MD5Update(MD5_CTX*, unsigned char*, unsigned int) / MD5Final(MD5_CTX*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6550 / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x6c×3 / 0xc8×1 / 0x90×1 / 0xb4×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157c54 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x157c58 sub sp, sp, #112
 *   @0x157c5c ldr r8, [pc, #0xc8]
 *   @0x157c60 mov r1, #0
 *   @0x157c64 ldr r2, [sp, #0x90]
 *   @0x157c68 mov r10, r0
 *   @0x157c6c ldr r8, [pc, r8]
 *   @0x157c70 add r5, sp, #4
 *   @0x157c74 ldr r7, [pc, #0xb4]
 *   @0x157c78 add r4, sp, #91
 *   @0x157c7c ldr r3, [r8]
 *   @0x157c80 mov r0, r2
 *   @0x157c84 add r7, pc, r7
 *   @0x157c88 add r6, sp, #107
 *   @0x157c8c str r3, [sp, #0x6c]
 *   @0x157c90 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157c94 mov r9, r0
 *   @0x157c98 mov r0, r5
 *   @0x157c9c bl 0x2140d8 <_Z7MD5InitP7MD5_CTX>
 *   @0x157ca0 mov r0, r9
 *   @0x157ca4 bl 0xb6538 <strlen@plt>
 *   @0x157ca8 mov r1, r9
 *   @0x157cac mov r2, r0
 *   @0x157cb0 mov r0, r5
 *   @0x157cb4 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x157cb8 mov r0, r5
 *   @0x157cbc bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX>
 *   @0x157cc0 ldr r1, [pc, #0x6c]
 *   @0x157cc4 mov r0, #33
 *   @0x157cc8 movw r2, #0x989
 *   @0x157ccc add r1, pc, r1
 *   @0x157cd0 mov r3, #1
 *   @0x157cd4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x157cd8 mov r9, r0
 *   @0x157cdc mov r5, r0
 *   @0x157ce0 ldrb r2, [r4, #0x1]!
 *   @0x157ce4 mov r0, r5
 *   @0x157ce8 mov r1, r7
 *   @0x157cec add r5, r5, #2
 *   @0x157cf0 bl 0xb6550 <sprintf@plt>
 *   @0x157cf4 cmp r4, r6
 *   @0x157cf8 bne 0x157ce0 <_Z14F_YoYo_MD5Utf8R6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x157cfc mov r0, r10
 *   @0x157d00 mov r1, r9
 *   @0x157d04 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x157d08 mov r0, r9
 *   @0x157d0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x157d10 ldr r2, [sp, #0x6c]
 *   @0x157d14 ldr r3, [r8]
 *   @0x157d18 cmp r2, r3
 *   @0x157d1c bne 0x157d28 <_Z14F_YoYo_MD5Utf8R6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x157d20 add sp, sp, #112
 *   @0x157d24 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x157d28 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x157d2c eoreq r5, r9, r4, ror #25
 *   @0x157d30 andseq r10, sp, r0, lsr #10
 *   @0x157d34 mulseq lr, r8, r8
 *
 * ══ §10/137 F_YoYo_SHA1Utf8(RValue&, CInstance*, CInstance*, int, RValue*)  0x158078  size 228  57 条（0x158078..0x15815c）
 * @func 0x158078 0x15815c  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / SHA1Reset(SHA1Context*) / 0xb6538 / SHA1Input(SHA1Context*, unsigned char const*, unsigned int) / SHA1Result(SHA1Context*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6550 / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x6c×3 / 0xc8×1 / 0x90×1 / 0xb4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158078 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x15807c sub sp, sp, #112
 *   @0x158080 ldr r8, [pc, #0xc8]
 *   @0x158084 mov r1, #0
 *   @0x158088 ldr r2, [sp, #0x90]
 *   @0x15808c mov r10, r0
 *   @0x158090 ldr r8, [pc, r8]
 *   @0x158094 add r5, sp, #4
 *   @0x158098 ldr r7, [pc, #0xb4]
 *   @0x15809c add r6, sp, #20
 *   @0x1580a0 ldr r3, [r8]
 *   @0x1580a4 mov r0, r2
 *   @0x1580a8 add r7, pc, r7
 *   @0x1580ac mov r4, sp
 *   @0x1580b0 str r3, [sp, #0x6c]
 *   @0x1580b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1580b8 mov r9, r0
 *   @0x1580bc mov r0, r5
 *   @0x1580c0 bl 0x214294 <_Z9SHA1ResetP11SHA1Context>
 *   @0x1580c4 mov r0, r9
 *   @0x1580c8 bl 0xb6538 <strlen@plt>
 *   @0x1580cc mov r1, r9
 *   @0x1580d0 mov r2, r0
 *   @0x1580d4 mov r0, r5
 *   @0x1580d8 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj>
 *   @0x1580dc mov r0, r5
 *   @0x1580e0 bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context>
 *   @0x1580e4 ldr r1, [pc, #0x6c]
 *   @0x1580e8 mov r0, #45
 *   @0x1580ec movw r2, #0x9f9
 *   @0x1580f0 add r1, pc, r1
 *   @0x1580f4 mov r3, #1
 *   @0x1580f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1580fc mov r9, r0
 *   @0x158100 mov r5, r0
 *   @0x158104 ldr r2, [r4, #0x4]!
 *   @0x158108 mov r0, r5
 *   @0x15810c mov r1, r7
 *   @0x158110 add r5, r5, #8
 *   @0x158114 bl 0xb6550 <sprintf@plt>
 *   @0x158118 cmp r4, r6
 *   @0x15811c bne 0x158104 <_Z15F_YoYo_SHA1Utf8R6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x158120 mov r0, r10
 *   @0x158124 mov r1, r9
 *   @0x158128 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x15812c mov r0, r9
 *   @0x158130 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x158134 ldr r2, [sp, #0x6c]
 *   @0x158138 ldr r3, [r8]
 *   @0x15813c cmp r2, r3
 *   @0x158140 bne 0x15814c <_Z15F_YoYo_SHA1Utf8R6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x158144 add sp, sp, #112
 *   @0x158148 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x15814c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x158150 eoreq r5, r9, r0, asr #17
 *   @0x158154 andseq r10, sp, r4, lsl #2
 *   @0x158158 andseq lr, lr, r4, ror r4
 *
 * ══ §11/137 F_LayerGetElementType(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf3d4  size 228  57 条（0x1bf3d4..0x1bf4b8）
 * @func 0x1bf3d4 0x1bf4b8  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×3 / 0x44×2 / 0x28×2 / 0x4×1 / 0x18×1 / 0x9c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf3d4 cmp r3, #1
 *   @0x1bf3d8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bf3dc mov r3, #0
 *   @0x1bf3e0 mov r5, r3
 *   @0x1bf3e4 mov r4, r0
 *   @0x1bf3e8 movt r3, #0xbff0
 *   @0x1bf3ec str r5, [r0, #0xc]
 *   @0x1bf3f0 str r3, [r0, #0x4]
 *   @0x1bf3f4 str r5, [r0]
 *   @0x1bf3f8 ldr r6, [sp, #0x18]
 *   @0x1bf3fc beq 0x1bf414 <_Z21F_LayerGetElementTypeR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bf400 ldr r0, [pc, #0x9c]
 *   @0x1bf404 mov r1, r5
 *   @0x1bf408 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bf40c add r0, pc, r0
 *   @0x1bf410 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf414 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf418 subs r7, r0, #0
 *   @0x1bf41c beq 0x1bf45c <_Z21F_LayerGetElementTypeR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1bf420 mov r1, r5
 *   @0x1bf424 mov r0, r6
 *   @0x1bf428 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf42c mov r2, r5
 *   @0x1bf430 mov r1, r0
 *   @0x1bf434 mov r0, r7
 *   @0x1bf438 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf43c cmp r0, #0
 *   @0x1bf440 beq 0x1bf480 <_Z21F_LayerGetElementTypeR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x1bf444 ldr r2, [r0]
 *   @0x1bf448 vmov s15, r2
 *   @0x1bf44c vcvt.f64.s32 d7, s15
 *   @0x1bf450 vmov r2, r3, d7
 *   @0x1bf454 stm r4, {r2, r3}
 *   @0x1bf458 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bf45c ldr r3, [pc, #0x44]
 *   @0x1bf460 ldr r1, [pc, #0x44]
 *   @0x1bf464 ldr r3, [pc, r3]
 *   @0x1bf468 add r1, pc, r1
 *   @0x1bf46c ldr r0, [r3]
 *   @0x1bf470 ldr r3, [r0]
 *   @0x1bf474 ldr r3, [r3, #0xc]
 *   @0x1bf478 blx r3
 *   @0x1bf47c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bf480 ldr r3, [pc, #0x28]
 *   @0x1bf484 ldr r1, [pc, #0x28]
 *   @0x1bf488 ldr r3, [pc, r3]
 *   @0x1bf48c add r1, pc, r1
 *   @0x1bf490 ldr r0, [r3]
 *   @0x1bf494 ldr r3, [r0]
 *   @0x1bf498 ldr r3, [r3, #0xc]
 *   @0x1bf49c blx r3
 *   @0x1bf4a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bf4a4 ldrsheq pc, [r8], -r4
 *   @0x1bf4a8 .word 0x0022e2b0
 *   @0x1bf4ac andseq pc, r8, r8, lsl #28
 *   @0x1bf4b0 eoreq lr, r2, r12, lsl #5
 *   @0x1bf4b4 andseq pc, r8, r8, lsr #27
 *
 * ══ §12/137 F_LayerSpriteGetID(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c0610  size 228  57 条（0x1c0610..0x1c06f4）
 * @func 0x1c0610 0x1c06f4  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetElementFromName(CLayer*, char const*) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x18×1 / 0xac×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0610 cmp r3, #2
 *   @0x1c0614 push {r3, r4, r5, r6, r7, lr}
 *   @0x1c0618 mov r3, #0
 *   @0x1c061c mov r5, r3
 *   @0x1c0620 mov r4, r0
 *   @0x1c0624 movt r3, #0xbff0
 *   @0x1c0628 str r5, [r0, #0xc]
 *   @0x1c062c str r3, [r0, #0x4]
 *   @0x1c0630 str r5, [r0]
 *   @0x1c0634 ldr r6, [sp, #0x18]
 *   @0x1c0638 beq 0x1c0650 <_Z18F_LayerSpriteGetIDR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c063c ldr r0, [pc, #0xac]
 *   @0x1c0640 mov r1, r5
 *   @0x1c0644 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c0648 add r0, pc, r0
 *   @0x1c064c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c0650 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0654 ldr r3, [r6, #0xc]
 *   @0x1c0658 mov r1, r5
 *   @0x1c065c bic r3, r3, #-16777216
 *   @0x1c0660 cmp r3, #1
 *   @0x1c0664 mov r7, r0
 *   @0x1c0668 mov r0, r6
 *   @0x1c066c beq 0x1c06d0 <_Z18F_LayerSpriteGetIDR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1c0670 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0674 mov r1, r0
 *   @0x1c0678 mov r0, r7
 *   @0x1c067c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c0680 mov r5, r0
 *   @0x1c0684 cmp r5, #0
 *   @0x1c0688 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c068c mov r1, #1
 *   @0x1c0690 mov r0, r6
 *   @0x1c0694 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c0698 mov r1, r0
 *   @0x1c069c mov r0, r5
 *   @0x1c06a0 bl 0x1c048c <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc>
 *   @0x1c06a4 cmp r0, #0
 *   @0x1c06a8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c06ac ldr r3, [r0]
 *   @0x1c06b0 cmp r3, #4
 *   @0x1c06b4 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1c06b8 ldr r2, [r0, #0x4]
 *   @0x1c06bc vmov s15, r2
 *   @0x1c06c0 vcvt.f64.s32 d7, s15
 *   @0x1c06c4 vmov r2, r3, d7
 *   @0x1c06c8 stm r4, {r2, r3}
 *   @0x1c06cc pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c06d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c06d4 mov r1, r0
 *   @0x1c06d8 mov r0, r7
 *   @0x1c06dc bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c06e0 mov r5, r0
 *   @0x1c06e4 cmp r5, #0
 *   @0x1c06e8 bne 0x1c068c <_Z18F_LayerSpriteGetIDR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1c06ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c06f0 andseq pc, r8, r4, ror r2
 *
 * ══ §13/137 GV_PhysicsSpeedX(CInstance*, int, RValue*)  0x1f9d58  size 228  57 条（0x1f9d58..0x1f9e3c）
 * @func 0x1f9d58 0x1f9e3c  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::GetFPS()
 * 字段偏移 top8: 0x4×2 / 0xd0×1 / 0x84×1 / 0xb4×1 / 0xa0×1 / 0xc×1 / 0x40×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9d58 ldr r3, [pc, #0xd0]
 *   @0x1f9d5c ldr r1, [r0, #0x84]
 *   @0x1f9d60 ldr r3, [pc, r3]
 *   @0x1f9d64 push {r4, r5, r6, lr}
 *   @0x1f9d68 vpush {d8}
 *   @0x1f9d6c sub sp, sp, #8
 *   @0x1f9d70 ldr r12, [r3]
 *   @0x1f9d74 ldr r3, [r12, #0xb4]
 *   @0x1f9d78 cmp r1, #0
 *   @0x1f9d7c cmpne r3, #0
 *   @0x1f9d80 moveq r6, #0
 *   @0x1f9d84 movne r6, #1
 *   @0x1f9d88 beq 0x1f9dd8 <_Z16GV_PhysicsSpeedXP9CInstanceiP6RValue+0x80>
 *   @0x1f9d8c ldr r4, [pc, #0xa0]
 *   @0x1f9d90 mov r0, #0
 *   @0x1f9d94 str r0, [r2, #0xc]
 *   @0x1f9d98 vldr s15, [r3, #96]
 *   @0x1f9d9c ldr r4, [pc, r4]
 *   @0x1f9da0 ldr r1, [r1]
 *   @0x1f9da4 ldrb r0, [r4]
 *   @0x1f9da8 cmp r0, #0
 *   @0x1f9dac bne 0x1f9de8 <_Z16GV_PhysicsSpeedXP9CInstanceiP6RValue+0x90>
 *   @0x1f9db0 vldr s13, [r1, #80]
 *   @0x1f9db4 vdiv.f32 s13, s13, s15
 *   @0x1f9db8 vldr s14, [r12, #12]
 *   @0x1f9dbc vcvt.f32.s32 s14, s14
 *   @0x1f9dc0 vdiv.f32 s15, s13, s14
 *   @0x1f9dc4 vcvt.f64.f32 d6, s15
 *   @0x1f9dc8 vmov r4, r5, d6
 *   @0x1f9dcc vmov r1, s12
 *   @0x1f9dd0 mov r3, r5
 *   @0x1f9dd4 stm r2, {r1, r3}
 *   @0x1f9dd8 mov r0, r6
 *   @0x1f9ddc add sp, sp, #8
 *   @0x1f9de0 vpop {d8}
 *   @0x1f9de4 pop {r4, r5, r6, pc}
 *   @0x1f9de8 vldr s16, [r1, #80]
 *   @0x1f9dec vdiv.f32 s16, s16, s15
 *   @0x1f9df0 ldr r0, [pc, #0x40]
 *   @0x1f9df4 str r2, [sp, #0x4]
 *   @0x1f9df8 ldr r0, [pc, r0]
 *   @0x1f9dfc bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1f9e00 ldr r2, [sp, #0x4]
 *   @0x1f9e04 vmov d6, r0, r1
 *   @0x1f9e08 mov r0, r6
 *   @0x1f9e0c vcvt.f64.f32 d8, s16
 *   @0x1f9e10 vdiv.f64 d6, d8, d6
 *   @0x1f9e14 vmov r4, r5, d6
 *   @0x1f9e18 vmov r1, s12
 *   @0x1f9e1c mov r3, r5
 *   @0x1f9e20 stm r2, {r1, r3}
 *   @0x1f9e24 add sp, sp, #8
 *   @0x1f9e28 vpop {d8}
 *   @0x1f9e2c pop {r4, r5, r6, pc}
 *   @0x1f9e30 andseq r3, pc, r8, asr #23
 *   @0x1f9e34 andseq r3, pc, r8, lsl #23
 *   @0x1f9e38 andseq r3, pc, r4, lsr r11
 *
 * ══ §14/137 GV_PhysicsSpeedY(CInstance*, int, RValue*)  0x1f9e3c  size 228  57 条（0x1f9e3c..0x1f9f20）
 * @func 0x1f9e3c 0x1f9f20  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::GetFPS()
 * 字段偏移 top8: 0x4×2 / 0xd0×1 / 0x84×1 / 0xb4×1 / 0xa0×1 / 0xc×1 / 0x40×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9e3c ldr r3, [pc, #0xd0]
 *   @0x1f9e40 ldr r1, [r0, #0x84]
 *   @0x1f9e44 ldr r3, [pc, r3]
 *   @0x1f9e48 push {r4, r5, r6, lr}
 *   @0x1f9e4c vpush {d8}
 *   @0x1f9e50 sub sp, sp, #8
 *   @0x1f9e54 ldr r12, [r3]
 *   @0x1f9e58 ldr r3, [r12, #0xb4]
 *   @0x1f9e5c cmp r1, #0
 *   @0x1f9e60 cmpne r3, #0
 *   @0x1f9e64 moveq r6, #0
 *   @0x1f9e68 movne r6, #1
 *   @0x1f9e6c beq 0x1f9ebc <_Z16GV_PhysicsSpeedYP9CInstanceiP6RValue+0x80>
 *   @0x1f9e70 ldr r4, [pc, #0xa0]
 *   @0x1f9e74 mov r0, #0
 *   @0x1f9e78 str r0, [r2, #0xc]
 *   @0x1f9e7c vldr s15, [r3, #96]
 *   @0x1f9e80 ldr r4, [pc, r4]
 *   @0x1f9e84 ldr r1, [r1]
 *   @0x1f9e88 ldrb r0, [r4]
 *   @0x1f9e8c cmp r0, #0
 *   @0x1f9e90 bne 0x1f9ecc <_Z16GV_PhysicsSpeedYP9CInstanceiP6RValue+0x90>
 *   @0x1f9e94 vldr s13, [r1, #84]
 *   @0x1f9e98 vdiv.f32 s13, s13, s15
 *   @0x1f9e9c vldr s14, [r12, #12]
 *   @0x1f9ea0 vcvt.f32.s32 s14, s14
 *   @0x1f9ea4 vdiv.f32 s15, s13, s14
 *   @0x1f9ea8 vcvt.f64.f32 d6, s15
 *   @0x1f9eac vmov r4, r5, d6
 *   @0x1f9eb0 vmov r1, s12
 *   @0x1f9eb4 mov r3, r5
 *   @0x1f9eb8 stm r2, {r1, r3}
 *   @0x1f9ebc mov r0, r6
 *   @0x1f9ec0 add sp, sp, #8
 *   @0x1f9ec4 vpop {d8}
 *   @0x1f9ec8 pop {r4, r5, r6, pc}
 *   @0x1f9ecc vldr s16, [r1, #84]
 *   @0x1f9ed0 vdiv.f32 s16, s16, s15
 *   @0x1f9ed4 ldr r0, [pc, #0x40]
 *   @0x1f9ed8 str r2, [sp, #0x4]
 *   @0x1f9edc ldr r0, [pc, r0]
 *   @0x1f9ee0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1f9ee4 ldr r2, [sp, #0x4]
 *   @0x1f9ee8 vmov d6, r0, r1
 *   @0x1f9eec mov r0, r6
 *   @0x1f9ef0 vcvt.f64.f32 d8, s16
 *   @0x1f9ef4 vdiv.f64 d6, d8, d6
 *   @0x1f9ef8 vmov r4, r5, d6
 *   @0x1f9efc vmov r1, s12
 *   @0x1f9f00 mov r3, r5
 *   @0x1f9f04 stm r2, {r1, r3}
 *   @0x1f9f08 add sp, sp, #8
 *   @0x1f9f0c vpop {d8}
 *   @0x1f9f10 pop {r4, r5, r6, pc}
 *   @0x1f9f14 andseq r3, pc, r4, ror #21
 *   @0x1f9f18 andseq r3, pc, r4, lsr #21
 *   @0x1f9f1c andseq r3, pc, r0, asr r10
 *
 * ══ §15/137 Audio_SoundIsPaused(int)  0x217098  size 228  57 条（0x217098..0x21717c）
 * @func 0x217098 0x21717c  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_SoundIsPaused(int)+0xc0 / Audio_SoundIsPaused(int)+0xb8 / Audio_NoiseIsPaused(CNoise*) / Audio_GetNoiseFromID(int)
 * 字段偏移 top8: 0x38×2 / 0xc4×1 / 0xac×1 / 0x9c×1 / 0x8c×1 / 0x7c×1 / 0x78×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217098 ldr r3, [pc, #0xc4]
 *   @0x21709c push {r4, r5, r6, r7, r8, lr}
 *   @0x2170a0 ldr r3, [pc, r3]
 *   @0x2170a4 mov r6, r0
 *   @0x2170a8 ldrb r4, [r3]
 *   @0x2170ac cmp r4, #0
 *   @0x2170b0 bne 0x217150 <_Z19Audio_SoundIsPausedi+0xb8>
 *   @0x2170b4 ldr r3, [pc, #0xac]
 *   @0x2170b8 ldr r3, [pc, r3]
 *   @0x2170bc ldrb r3, [r3]
 *   @0x2170c0 cmp r3, #0
 *   @0x2170c4 beq 0x217150 <_Z19Audio_SoundIsPausedi+0xb8>
 *   @0x2170c8 ldr r3, [pc, #0x9c]
 *   @0x2170cc ldr r3, [pc, r3]
 *   @0x2170d0 ldr r3, [r3]
 *   @0x2170d4 cmp r3, r0
 *   @0x2170d8 ble 0x217158 <_Z19Audio_SoundIsPausedi+0xc0>
 *   @0x2170dc ldr r3, [pc, #0x8c]
 *   @0x2170e0 add r3, pc, r3
 *   @0x2170e4 ldr r5, [r3, #0x38]
 *   @0x2170e8 cmp r5, #0
 *   @0x2170ec ble 0x217150 <_Z19Audio_SoundIsPausedi+0xb8>
 *   @0x2170f0 ldr r8, [pc, #0x7c]
 *   @0x2170f4 mov r3, r5
 *   @0x2170f8 ldr r7, [pc, #0x78]
 *   @0x2170fc add r8, pc, r8
 *   @0x217100 add r7, pc, r7
 *   @0x217104 b 0x217118 <_Z19Audio_SoundIsPausedi+0x80>
 *   @0x217108 add r4, r4, #1
 *   @0x21710c cmp r4, r5
 *   @0x217110 beq 0x217150 <_Z19Audio_SoundIsPausedi+0xb8>
 *   @0x217114 ldr r3, [r7, #0x38]
 *   @0x217118 cmp r4, r3
 *   @0x21711c bge 0x217108 <_Z19Audio_SoundIsPausedi+0x70>
 *   @0x217120 ldr r3, [r8, #0x3c]
 *   @0x217124 ldr r0, [r3, r4, lsl #2]
 *   @0x217128 cmp r0, #0
 *   @0x21712c beq 0x217108 <_Z19Audio_SoundIsPausedi+0x70>
 *   @0x217130 ldr r3, [r0, #0x18]
 *   @0x217134 cmp r3, r6
 *   @0x217138 bne 0x217108 <_Z19Audio_SoundIsPausedi+0x70>
 *   @0x21713c bl 0x216450 <_Z19Audio_NoiseIsPausedP6CNoise>
 *   @0x217140 cmp r0, #0
 *   @0x217144 beq 0x217108 <_Z19Audio_SoundIsPausedi+0x70>
 *   @0x217148 mov r0, #1
 *   @0x21714c pop {r4, r5, r6, r7, r8, pc}
 *   @0x217150 mov r0, #0
 *   @0x217154 pop {r4, r5, r6, r7, r8, pc}
 *   @0x217158 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x21715c pop {r4, r5, r6, r7, r8, lr}
 *   @0x217160 b 0x216450 <_Z19Audio_NoiseIsPausedP6CNoise>
 *   @0x217164 andseq r7, sp, r12, lsr #31
 *   @0x217168 andseq r7, sp, r8, ror r12
 *   @0x21716c andseq r10, sp, r8, lsl r3
 *   @0x217170 ldrheq lr, [r3], #-20
 *   @0x217174 .word 0x0053e198
 *   @0x217178 .word 0x0053e194
 *
 * ══ §16/137 Audio_SoundIsPlaying(int)  0x21717c  size 228  57 条（0x21717c..0x217260）
 * @func 0x21717c 0x217260  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_SoundIsPlaying(int)+0xc0 / Audio_SoundIsPlaying(int)+0xb8 / Audio_NoiseIsPlaying(CNoise*) / Audio_GetNoiseFromID(int)
 * 字段偏移 top8: 0x38×2 / 0xc4×1 / 0xac×1 / 0x9c×1 / 0x8c×1 / 0x7c×1 / 0x78×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21717c ldr r3, [pc, #0xc4]
 *   @0x217180 push {r4, r5, r6, r7, r8, lr}
 *   @0x217184 ldr r3, [pc, r3]
 *   @0x217188 mov r6, r0
 *   @0x21718c ldrb r4, [r3]
 *   @0x217190 cmp r4, #0
 *   @0x217194 bne 0x217234 <_Z20Audio_SoundIsPlayingi+0xb8>
 *   @0x217198 ldr r3, [pc, #0xac]
 *   @0x21719c ldr r3, [pc, r3]
 *   @0x2171a0 ldrb r3, [r3]
 *   @0x2171a4 cmp r3, #0
 *   @0x2171a8 beq 0x217234 <_Z20Audio_SoundIsPlayingi+0xb8>
 *   @0x2171ac ldr r3, [pc, #0x9c]
 *   @0x2171b0 ldr r3, [pc, r3]
 *   @0x2171b4 ldr r3, [r3]
 *   @0x2171b8 cmp r3, r0
 *   @0x2171bc ble 0x21723c <_Z20Audio_SoundIsPlayingi+0xc0>
 *   @0x2171c0 ldr r3, [pc, #0x8c]
 *   @0x2171c4 add r3, pc, r3
 *   @0x2171c8 ldr r5, [r3, #0x38]
 *   @0x2171cc cmp r5, #0
 *   @0x2171d0 ble 0x217234 <_Z20Audio_SoundIsPlayingi+0xb8>
 *   @0x2171d4 ldr r8, [pc, #0x7c]
 *   @0x2171d8 mov r3, r5
 *   @0x2171dc ldr r7, [pc, #0x78]
 *   @0x2171e0 add r8, pc, r8
 *   @0x2171e4 add r7, pc, r7
 *   @0x2171e8 b 0x2171fc <_Z20Audio_SoundIsPlayingi+0x80>
 *   @0x2171ec add r4, r4, #1
 *   @0x2171f0 cmp r4, r5
 *   @0x2171f4 beq 0x217234 <_Z20Audio_SoundIsPlayingi+0xb8>
 *   @0x2171f8 ldr r3, [r7, #0x38]
 *   @0x2171fc cmp r4, r3
 *   @0x217200 bge 0x2171ec <_Z20Audio_SoundIsPlayingi+0x70>
 *   @0x217204 ldr r3, [r8, #0x3c]
 *   @0x217208 ldr r0, [r3, r4, lsl #2]
 *   @0x21720c cmp r0, #0
 *   @0x217210 beq 0x2171ec <_Z20Audio_SoundIsPlayingi+0x70>
 *   @0x217214 ldr r3, [r0, #0x18]
 *   @0x217218 cmp r3, r6
 *   @0x21721c bne 0x2171ec <_Z20Audio_SoundIsPlayingi+0x70>
 *   @0x217220 bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise>
 *   @0x217224 cmp r0, #0
 *   @0x217228 beq 0x2171ec <_Z20Audio_SoundIsPlayingi+0x70>
 *   @0x21722c mov r0, #1
 *   @0x217230 pop {r4, r5, r6, r7, r8, pc}
 *   @0x217234 mov r0, #0
 *   @0x217238 pop {r4, r5, r6, r7, r8, pc}
 *   @0x21723c bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x217240 pop {r4, r5, r6, r7, r8, lr}
 *   @0x217244 b 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise>
 *   @0x217248 andseq r7, sp, r8, asr #29
 *   @0x21724c mulseq sp, r4, r11
 *   @0x217250 andseq r10, sp, r4, lsr r2
 *   @0x217254 ldrsbeq lr, [r3], #-0
 *   @0x217258 ldrheq lr, [r3], #-4
 *   @0x21725c ldrheq lr, [r3], #-0
 *
 * ══ §17/137 _alutPassBufferData  0x221424  size 228  57 条（0x221424..0x221508）
 * @func 0x221424 0x221508  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a54×2 / _alutSetError×2 / 0xb6af0 / _alutGetFormat / _alutBufferDataGetLength / _alutBufferDataGetSampleFrequency / _alutBufferDataGetData / 0xb6afc
 * 字段偏移 top8: 0xc×2
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221424 push {r4, r5, r6, r7, lr}
 *   @0x221428 vpush {d8}
 *   @0x22142c sub sp, sp, #20
 *   @0x221430 add r5, sp, #12
 *   @0x221434 mov r6, r0
 *   @0x221438 mov r0, #1
 *   @0x22143c mov r1, r5
 *   @0x221440 bl 0xb6af0 <alGenBuffers@plt>
 *   @0x221444 bl 0xb6a54 <alGetError@plt>
 *   @0x221448 cmp r0, #0
 *   @0x22144c bne 0x221494 <_alutPassBufferData+0x70>
 *   @0x221450 ldr r4, [sp, #0xc]
 *   @0x221454 cmp r4, #0
 *   @0x221458 bne 0x22146c <_alutPassBufferData+0x48>
 *   @0x22145c mov r0, r4
 *   @0x221460 add sp, sp, #20
 *   @0x221464 vpop {d8}
 *   @0x221468 pop {r4, r5, r6, r7, pc}
 *   @0x22146c mov r1, r5
 *   @0x221470 mov r0, r6
 *   @0x221474 bl 0x2213ec <_alutGetFormat>
 *   @0x221478 cmp r0, #0
 *   @0x22147c bne 0x2214b0 <_alutPassBufferData+0x8c>
 *   @0x221480 mov r4, #0
 *   @0x221484 mov r0, r4
 *   @0x221488 add sp, sp, #20
 *   @0x22148c vpop {d8}
 *   @0x221490 pop {r4, r5, r6, r7, pc}
 *   @0x221494 mov r0, #524
 *   @0x221498 mov r4, #0
 *   @0x22149c bl 0x221940 <_alutSetError>
 *   @0x2214a0 mov r0, r4
 *   @0x2214a4 add sp, sp, #20
 *   @0x2214a8 vpop {d8}
 *   @0x2214ac pop {r4, r5, r6, r7, pc}
 *   @0x2214b0 mov r0, r6
 *   @0x2214b4 bl 0x2213dc <_alutBufferDataGetLength>
 *   @0x2214b8 mov r7, r0
 *   @0x2214bc mov r0, r6
 *   @0x2214c0 bl 0x2213e4 <_alutBufferDataGetSampleFrequency>
 *   @0x2214c4 ldr r5, [sp, #0xc]
 *   @0x2214c8 vmov s16, r0
 *   @0x2214cc mov r0, r6
 *   @0x2214d0 bl 0x2213c8 <_alutBufferDataGetData>
 *   @0x2214d4 mov r3, r7
 *   @0x2214d8 vcvt.s32.f32 s16, s16
 *   @0x2214dc mov r1, r5
 *   @0x2214e0 vstr s16, [sp]
 *   @0x2214e4 mov r2, r0
 *   @0x2214e8 mov r0, r4
 *   @0x2214ec bl 0xb6afc <alBufferData@plt>
 *   @0x2214f0 bl 0xb6a54 <alGetError@plt>
 *   @0x2214f4 cmp r0, #0
 *   @0x2214f8 beq 0x22145c <_alutPassBufferData+0x38>
 *   @0x2214fc movw r0, #0x20d
 *   @0x221500 bl 0x221940 <_alutSetError>
 *   @0x221504 b 0x221480 <_alutPassBufferData+0x5c>
 *
 * ══ §18/137 MakeTime(double, double, double, double)  0x2451d8  size 228  57 条（0x2451d8..0x2452bc）
 * @func 0x2451d8 0x2452bc  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: myisinf(double)×4 / 0xb6598×4
 * 字段偏移 top8: 0xb4×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2451d8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2451dc vpush {d8, d9, d10}
 *   @0x2451e0 mov r4, r2
 *   @0x2451e4 mov r5, r3
 *   @0x2451e8 mov r6, r0
 *   @0x2451ec mov r7, r1
 *   @0x2451f0 bl 0x24364c <_Z7myisinfd>
 *   @0x2451f4 cmp r0, #0
 *   @0x2451f8 beq 0x245210 <_Z8MakeTimedddd+0x38>
 *   @0x2451fc ldr r3, [pc, #0xb4]
 *   @0x245200 ldr r3, [pc, r3]
 *   @0x245204 ldrd r0, r1, [r3]
 *   @0x245208 vpop {d8, d9, d10}
 *   @0x24520c pop {r3, r4, r5, r6, r7, pc}
 *   @0x245210 mov r0, r4
 *   @0x245214 mov r1, r5
 *   @0x245218 bl 0x24364c <_Z7myisinfd>
 *   @0x24521c cmp r0, #0
 *   @0x245220 bne 0x2451fc <_Z8MakeTimedddd+0x24>
 *   @0x245224 ldrd r0, r1, [sp, #48]
 *   @0x245228 bl 0x24364c <_Z7myisinfd>
 *   @0x24522c cmp r0, #0
 *   @0x245230 bne 0x2451fc <_Z8MakeTimedddd+0x24>
 *   @0x245234 ldrd r0, r1, [sp, #56]
 *   @0x245238 bl 0x24364c <_Z7myisinfd>
 *   @0x24523c cmp r0, #0
 *   @0x245240 bne 0x2451fc <_Z8MakeTimedddd+0x24>
 *   @0x245244 mov r0, r6
 *   @0x245248 mov r1, r7
 *   @0x24524c bl 0xb6598 <floor@plt>
 *   @0x245250 vmov d9, r0, r1
 *   @0x245254 mov r0, r4
 *   @0x245258 mov r1, r5
 *   @0x24525c bl 0xb6598 <floor@plt>
 *   @0x245260 vmov d10, r0, r1
 *   @0x245264 ldrd r0, r1, [sp, #48]
 *   @0x245268 bl 0xb6598 <floor@plt>
 *   @0x24526c vmov d8, r0, r1
 *   @0x245270 ldrd r0, r1, [sp, #56]
 *   @0x245274 bl 0xb6598 <floor@plt>
 *   @0x245278 vldr d7, [pc, #32]
 *   @0x24527c vmul.f64 d7, d10, d7
 *   @0x245280 vldr d5, [pc, #32]
 *   @0x245284 vldr d6, [pc, #36]
 *   @0x245288 vmla.f64 d7, d9, d5
 *   @0x24528c vmla.f64 d7, d8, d6
 *   @0x245290 vmov d6, r0, r1
 *   @0x245294 vadd.f64 d6, d6, d7
 *   @0x245298 vmov r0, r1, d6
 *   @0x24529c b 0x245208 <_Z8MakeTimedddd+0x30>
 *   @0x2452a0 andeq r0, r0, r0
 *   @0x2452a4 rscmi r4, sp, r0, lsl #24
 *   @0x2452a8 andeq r0, r0, r0
 *   @0x2452ac .word 0x414b7740
 *   @0x2452b0 andeq r0, r0, r0
 *   @0x2452b4 addmi r4, pc, r0
 *   @0x2452b8 andseq r12, r10, r8, lsr #10
 *
 * ══ §19/137 _spDrawOrderTimeline_apply  0x2811d0  size 228  57 条（0x2811d0..0x2812b4）
 * @func 0x2811d0 0x2812b4  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spDrawOrderTimeline_apply+0x88 / _spDrawOrderTimeline_apply+0x80
 * 字段偏移 top8: 0x14×4 / 0x18×2 / 0xc×1 / 0x8×1 / 0x10×1 / 0x2×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2811d0 vmov s15, r3
 *   @0x2811d4 push {r4, r5, r6}
 *   @0x2811d8 ldr r5, [r0, #0xc]
 *   @0x2811dc vldr s14, [r5]
 *   @0x2811e0 vcmpe.f32 s14, s15
 *   @0x2811e4 vmrs APSR_nzcv, fpscr
 *   @0x2811e8 bgt 0x281250 <_spDrawOrderTimeline_apply+0x80>
 *   @0x2811ec ldr r12, [r0, #0x8]
 *   @0x2811f0 sub r3, r12, #-1073741823
 *   @0x2811f4 lsl r3, r3, #2
 *   @0x2811f8 add r2, r5, r3
 *   @0x2811fc vldr s14, [r2]
 *   @0x281200 vcmpe.f32 s15, s14
 *   @0x281204 vmrs APSR_nzcv, fpscr
 *   @0x281208 blt 0x281258 <_spDrawOrderTimeline_apply+0x88>
 *   @0x28120c ldr r12, [r0, #0x10]
 *   @0x281210 ldr r4, [r12, r3]
 *   @0x281214 cmp r4, #0
 *   @0x281218 beq 0x28129c <_spDrawOrderTimeline_apply+0xcc>
 *   @0x28121c ldr r5, [r0, #0x14]
 *   @0x281220 cmp r5, #0
 *   @0x281224 lslgt r5, r5, #2
 *   @0x281228 movgt r3, #0
 *   @0x28122c ble 0x281250 <_spDrawOrderTimeline_apply+0x80>
 *   @0x281230 ldr r12, [r4, r3]
 *   @0x281234 ldr r0, [r1, #0x14]
 *   @0x281238 ldr r2, [r1, #0x18]
 *   @0x28123c ldr r0, [r0, r12, lsl #2]
 *   @0x281240 str r0, [r2, r3]
 *   @0x281244 add r3, r3, #4
 *   @0x281248 cmp r3, r5
 *   @0x28124c bne 0x281230 <_spDrawOrderTimeline_apply+0x60>
 *   @0x281250 pop {r4, r5, r6}
 *   @0x281254 bx lr
 *   @0x281258 subs r3, r12, #2
 *   @0x28125c beq 0x28120c <_spDrawOrderTimeline_apply+0x3c>
 *   @0x281260 asr r12, r3, #1
 *   @0x281264 mov r2, #0
 *   @0x281268 add r4, r12, #1
 *   @0x28126c add r6, r5, r4, lsl #2
 *   @0x281270 vldr s14, [r6]
 *   @0x281274 vcmpe.f32 s15, s14
 *   @0x281278 vmrs APSR_nzcv, fpscr
 *   @0x28127c movge r2, r4
 *   @0x281280 movlt r3, r12
 *   @0x281284 add r12, r2, r3
 *   @0x281288 cmp r2, r3
 *   @0x28128c asr r12, r12, #1
 *   @0x281290 bne 0x281268 <_spDrawOrderTimeline_apply+0x98>
 *   @0x281294 lsl r3, r2, #2
 *   @0x281298 b 0x28120c <_spDrawOrderTimeline_apply+0x3c>
 *   @0x28129c ldr r2, [r0, #0x14]
 *   @0x2812a0 pop {r4, r5, r6}
 *   @0x2812a4 ldr r0, [r1, #0x18]
 *   @0x2812a8 lsl r2, r2, #2
 *   @0x2812ac ldr r1, [r1, #0x14]
 *   @0x2812b0 b 0xb65bc <memcpy@plt>
 *
 * ══ §20/137 GetNextCmd(int, char*)  0x2a1c0c  size 228  57 条（0x2a1c0c..0x2a1cf0）
 * @func 0x2a1c0c 0x2a1cf0  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetNextCmd(int, char*)+0x44 / GetNextCmd(int, char*)+0x3c / GetNextCmd(int, char*)+0x64 / YYStrDup(char const*)
 * 字段偏移 top8: 0x1×2 / 0xc8×1 / 0x38×1 / 0x20×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a1c0c push {r4, r5, r6, lr}
 *   @0x2a1c10 cmp r1, #0
 *   @0x2a1c14 ldr r5, [pc, #0xc8]
 *   @0x2a1c18 mov r3, #0
 *   @0x2a1c1c mov r4, r0
 *   @0x2a1c20 ldr r5, [pc, r5]
 *   @0x2a1c24 strb r3, [r5]
 *   @0x2a1c28 beq 0x2a1cdc <_Z10GetNextCmdiPc+0xd0>
 *   @0x2a1c2c ldrb r3, [r1, r0]
 *   @0x2a1c30 add r2, r1, r0
 *   @0x2a1c34 cmp r3, #0
 *   @0x2a1c38 beq 0x2a1cdc <_Z10GetNextCmdiPc+0xd0>
 *   @0x2a1c3c cmp r3, #32
 *   @0x2a1c40 bls 0x2a1c50 <_Z10GetNextCmdiPc+0x44>
 *   @0x2a1c44 b 0x2a1c64 <_Z10GetNextCmdiPc+0x58>
 *   @0x2a1c48 cmp r3, #0
 *   @0x2a1c4c beq 0x2a1cdc <_Z10GetNextCmdiPc+0xd0>
 *   @0x2a1c50 ldrb r3, [r2, #0x1]!
 *   @0x2a1c54 add r4, r4, #1
 *   @0x2a1c58 cmp r3, #32
 *   @0x2a1c5c bls 0x2a1c48 <_Z10GetNextCmdiPc+0x3c>
 *   @0x2a1c60 add r2, r1, r4
 *   @0x2a1c64 mov r0, #0
 *   @0x2a1c68 mov r12, r0
 *   @0x2a1c6c b 0x2a1c84 <_Z10GetNextCmdiPc+0x78>
 *   @0x2a1c70 cmp r0, #0
 *   @0x2a1c74 beq 0x2a1ca8 <_Z10GetNextCmdiPc+0x9c>
 *   @0x2a1c78 strb r3, [r5, r12]
 *   @0x2a1c7c add r12, r12, #1
 *   @0x2a1c80 ldrb r3, [r2, #0x1]!
 *   @0x2a1c84 cmp r3, #0
 *   @0x2a1c88 rsb r4, r1, r2
 *   @0x2a1c8c beq 0x2a1ca8 <_Z10GetNextCmdiPc+0x9c>
 *   @0x2a1c90 cmp r3, #32
 *   @0x2a1c94 bls 0x2a1c70 <_Z10GetNextCmdiPc+0x64>
 *   @0x2a1c98 cmp r3, #34
 *   @0x2a1c9c eoreq r0, r0, #1
 *   @0x2a1ca0 beq 0x2a1c80 <_Z10GetNextCmdiPc+0x74>
 *   @0x2a1ca4 b 0x2a1c78 <_Z10GetNextCmdiPc+0x6c>
 *   @0x2a1ca8 ldr r6, [pc, #0x38]
 *   @0x2a1cac mov r0, r5
 *   @0x2a1cb0 mov r3, #0
 *   @0x2a1cb4 strb r3, [r5, r12]
 *   @0x2a1cb8 ldr r6, [pc, r6]
 *   @0x2a1cbc ldr r5, [r6]
 *   @0x2a1cc0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2a1cc4 ldr r3, [pc, #0x20]
 *   @0x2a1cc8 ldr r2, [r6]
 *   @0x2a1ccc ldr r3, [pc, r3]
 *   @0x2a1cd0 add r2, r2, #1
 *   @0x2a1cd4 str r2, [r6]
 *   @0x2a1cd8 str r0, [r3, r5, lsl #2]
 *   @0x2a1cdc mov r0, r4
 *   @0x2a1ce0 pop {r4, r5, r6, pc}
 *   @0x2a1ce4 andseq pc, r4, r12, lsl #28
 *   @0x2a1ce8 andseq sp, r4, r8, ror #11
 *   @0x2a1cec ldrsbeq sp, [r4], -r8
 *
 * ══ §21/137 jpeg_finish_decompress  0x2b32c0  size 228  57 条（0x2b32c0..0x2b33a4）
 * @func 0x2b32c0 0x2b33a4  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_finish_decompress+0x94 / jpeg_abort / jpeg_finish_decompress+0xcc
 * 字段偏移 top8: 0x14×4 / 0x18×3 / 0x190×1 / 0x11×1 / 0x40×1 / 0x78×1 / 0x60×1 / 0x180×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b32c0 ldr r3, [r0, #0x14]
 *   @0x2b32c4 push {r4, lr}
 *   @0x2b32c8 sub r2, r3, #205
 *   @0x2b32cc cmp r2, #1
 *   @0x2b32d0 mov r4, r0
 *   @0x2b32d4 bls 0x2b3354 <jpeg_finish_decompress+0x94>
 *   @0x2b32d8 cmp r3, #207
 *   @0x2b32dc moveq r3, #210
 *   @0x2b32e0 streq r3, [r0, #0x14]
 *   @0x2b32e4 beq 0x2b3324 <jpeg_finish_decompress+0x64>
 *   @0x2b32e8 cmp r3, #210
 *   @0x2b32ec beq 0x2b3324 <jpeg_finish_decompress+0x64>
 *   @0x2b32f0 ldr r2, [r4]
 *   @0x2b32f4 mov r1, #20
 *   @0x2b32f8 mov r0, r4
 *   @0x2b32fc str r3, [r2, #0x18]
 *   @0x2b3300 ldr r3, [r4]
 *   @0x2b3304 str r1, [r2, #0x14]
 *   @0x2b3308 ldr r3, [r3]
 *   @0x2b330c blx r3
 *   @0x2b3310 b 0x2b3324 <jpeg_finish_decompress+0x64>
 *   @0x2b3314 ldr r3, [r3]
 *   @0x2b3318 blx r3
 *   @0x2b331c cmp r0, #0
 *   @0x2b3320 popeq {r4, pc}
 *   @0x2b3324 ldr r3, [r4, #0x190]
 *   @0x2b3328 mov r0, r4
 *   @0x2b332c ldrb r2, [r3, #0x11]
 *   @0x2b3330 cmp r2, #0
 *   @0x2b3334 beq 0x2b3314 <jpeg_finish_decompress+0x54>
 *   @0x2b3338 ldr r3, [r4, #0x18]
 *   @0x2b333c ldr r3, [r3, #0x18]
 *   @0x2b3340 blx r3
 *   @0x2b3344 mov r0, r4
 *   @0x2b3348 bl 0x2bc874 <jpeg_abort>
 *   @0x2b334c mov r0, #1
 *   @0x2b3350 pop {r4, pc}
 *   @0x2b3354 ldrb r2, [r0, #0x40]
 *   @0x2b3358 cmp r2, #0
 *   @0x2b335c bne 0x2b32f0 <jpeg_finish_decompress+0x30>
 *   @0x2b3360 ldr r2, [r0, #0x78]
 *   @0x2b3364 ldr r3, [r0, #0x60]
 *   @0x2b3368 cmp r2, r3
 *   @0x2b336c blo 0x2b338c <jpeg_finish_decompress+0xcc>
 *   @0x2b3370 ldr r3, [r4, #0x180]
 *   @0x2b3374 mov r0, r4
 *   @0x2b3378 ldr r3, [r3, #0x4]
 *   @0x2b337c blx r3
 *   @0x2b3380 mov r3, #210
 *   @0x2b3384 str r3, [r4, #0x14]
 *   @0x2b3388 b 0x2b3324 <jpeg_finish_decompress+0x64>
 *   @0x2b338c ldr r3, [r0]
 *   @0x2b3390 mov r1, #67
 *   @0x2b3394 ldr r2, [r3]
 *   @0x2b3398 str r1, [r3, #0x14]
 *   @0x2b339c blx r2
 *   @0x2b33a0 b 0x2b3370 <jpeg_finish_decompress+0xb0>
 *
 * ══ §22/137 png_do_read_swap_alpha  0x2a8d58  size 226  57 条（0x2a8d58..0x2a8e3a）
 * @func 0x2a8d58 0x2a8e3a  size 226  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-2×5 / 0x-1×3 / 0x1a×2 / 0x-4×2 / 0x-5×2 / 0x-3×2 / 0x-6×2 / 0x-7×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8d58 push {r4, r5, lr}
 *   @0x2a8d5c ldr r3, [r0]
 *   @0x2a8d60 bne 0x2a8de4 <png_do_read_swap_alpha+0x8c>
 *   @0x2a8d64 cmp r2, #0x8
 *   @0x2a8d68 add r1, r2
 *   @0x2a8d6c tstle r4, r0, lsl #4
 *   @0x2a8d70 cmp r2, r3
 *   @0x2a8d74 ldrb r4, [r1, #-2]
 *   @0x2a8d78 adds r2, #0x1
 *   @0x2a8d7c .word 0xf8010c01
 *   @0x2a8d80 .word 0xf8114c01
 *   @0x2a8d84 .word 0xf8014c03
 *   @0x2a8d88 .word 0xf8114c02
 *   @0x2a8d8c .word 0xf8014c04
 *   @0x2a8d90 .word 0xf8014c03
 *   @0x2a8d94 strb r0, [r11, r4, lsl #26]!
 *   @0x2a8d98 pop {r4, r5, pc}
 *   @0x2a8d9c beq 0x2a8de2 <png_do_read_swap_alpha+0x8a>
 *   @0x2a8da0 andlo r5, r1, #768
 *   @0x2a8da4 ldrb r4, [r1, #-1]
 *   @0x2a8da8 ldrb r0, [r1, #-2]
 *   @0x2a8dac strb r5, [r1, #-1]
 *   @0x2a8db0 ldrb r5, [r1, #-4]
 *   @0x2a8db4 strb r5, [r1, #-2]
 *   @0x2a8db8 ldrb r5, [r1, #-5]
 *   @0x2a8dbc strb r5, [r1, #-3]
 *   @0x2a8dc0 ldrb r5, [r1, #-6]
 *   @0x2a8dc4 strb r5, [r1, #-4]
 *   @0x2a8dc8 ldrb r5, [r1, #-7]
 *   @0x2a8dcc strb r4, [r1, #-7]
 *   @0x2a8dd0 strb r5, [r1, #-5]
 *   @0x2a8dd4 ldrb r5, [r1, #-8]
 *   @0x2a8dd8 strb r5, [r1, #-6]
 *   @0x2a8ddc strb r0, [r1, #-8]!
 *   @0x2a8de0 b 0x2a8d9a <png_do_read_swap_alpha+0x42>
 *   @0x2a8de4 cmp r2, #0x4
 *   @0x2a8de8 ldrb r2, [r0, #0x9]
 *   @0x2a8dec ldr r2, [r0, #0x4]
 *   @0x2a8df0 mov.w r2, #0x0
 *   @0x2a8df4 bne 0x2a8e10 <png_do_read_swap_alpha+0xb8>
 *   @0x2a8df8 beq 0x2a8e0e <png_do_read_swap_alpha+0xb6>
 *   @0x2a8dfc andlo r0, r1, #256
 *   @0x2a8e00 ldrb r4, [r1, #-2]
 *   @0x2a8e04 strb r4, [r1, #-1]
 *   @0x2a8e08 strb r0, [r1, #-2]!
 *   @0x2a8e0c b 0x2a8df6 <png_do_read_swap_alpha+0x9e>
 *   @0x2a8e10 cmp r2, r3
 *   @0x2a8e14 ldrb r5, [r1, #-3]
 *   @0x2a8e18 adds r2, #0x1
 *   @0x2a8e1c .word 0xf8114c01
 *   @0x2a8e20 .word 0xf8010c02
 *   @0x2a8e24 .word 0xf8115c01
 *   @0x2a8e28 .word 0xf8015c04
 *   @0x2a8e2c .word 0xf8014c03
 *   @0x2a8e30 .word 0xf8015c02
 *   @0x2a8e34 strb r0, [r11, r4, lsl #26]!
 *   @0x2a8e38 pop {r4, r5, pc}
 *
 * ══ §23/137 VM::GetDSList(Buffer_Standard*, int, int)  0xdb130  size 224  56 条（0xdb130..0xdb210）
 * @func 0xdb130 0xdb210  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::GetDSList(Buffer_Standard*, int, int)+0x98 / VM::WriteDSSizeCount(Buffer_Standard*, int, int&) / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)
 * 字段偏移 top8: 0x4×5 / 0x2c×2 / 0xb8×1 / 0xa8×1 / 0x2×1 / 0xc×1 / 0x30×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb130 push {r4, r5, r6, r7, r8, lr}
 *   @0xdb134 cmp r1, #0
 *   @0xdb138 sub sp, sp, #8
 *   @0xdb13c mov r8, r0
 *   @0xdb140 str r2, [sp, #0x4]
 *   @0xdb144 blt 0xdb1c8 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x98>
 *   @0xdb148 ldr r3, [pc, #0xb8]
 *   @0xdb14c ldr r3, [pc, r3]
 *   @0xdb150 ldr r3, [r3]
 *   @0xdb154 cmp r1, r3
 *   @0xdb158 bge 0xdb1c8 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x98>
 *   @0xdb15c ldr r3, [pc, #0xa8]
 *   @0xdb160 ldr r3, [pc, r3]
 *   @0xdb164 ldr r3, [r3, #0x4]
 *   @0xdb168 ldr r7, [r3, r1, lsl #2]
 *   @0xdb16c cmp r7, #0
 *   @0xdb170 beq 0xdb1c8 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x98>
 *   @0xdb174 ldr r1, [r7, #0x4]
 *   @0xdb178 add r2, sp, #4
 *   @0xdb17c bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi>
 *   @0xdb180 ldr r4, [sp, #0x4]
 *   @0xdb184 add r3, r0, r4
 *   @0xdb188 mov r6, r0
 *   @0xdb18c cmp r4, r3
 *   @0xdb190 bge 0xdb1c0 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x90>
 *   @0xdb194 lsl r5, r4, #4
 *   @0xdb198 ldr r0, [r7, #0xc]
 *   @0xdb19c mov r1, r8
 *   @0xdb1a0 add r4, r4, #1
 *   @0xdb1a4 add r0, r0, r5
 *   @0xdb1a8 add r5, r5, #16
 *   @0xdb1ac bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdb1b0 ldr r3, [sp, #0x4]
 *   @0xdb1b4 add r3, r6, r3
 *   @0xdb1b8 cmp r3, r4
 *   @0xdb1bc bgt 0xdb198 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x68>
 *   @0xdb1c0 add sp, sp, #8
 *   @0xdb1c4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xdb1c8 mov r2, r8
 *   @0xdb1cc mov r1, #0
 *   @0xdb1d0 ldr r0, [r2], #44
 *   @0xdb1d4 movt r1, #0xffe0
 *   @0xdb1d8 movw r3, #0xffff
 *   @0xdb1dc str r1, [r8, #0x2c]
 *   @0xdb1e0 movt r3, #0x41ef
 *   @0xdb1e4 mov r1, #0
 *   @0xdb1e8 str r3, [r8, #0x30]
 *   @0xdb1ec ldr r3, [r0, #0x8]
 *   @0xdb1f0 mov r0, r8
 *   @0xdb1f4 str r1, [r8, #0x38]
 *   @0xdb1f8 mov r1, #5
 *   @0xdb1fc blx r3
 *   @0xdb200 add sp, sp, #8
 *   @0xdb204 pop {r4, r5, r6, r7, r8, pc}
 *   @0xdb208 eorseq r2, r1, r0, lsr r11
 *   @0xdb20c eorseq r2, r1, r0, lsr #22
 *
 * ══ §24/137 FINALIZE_Code_Constant()  0xf1bb0  size 224  56 条（0xf1bb0..0xf1c90）
 * @func 0xf1bb0 0xf1c90  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xf1bb8→0x47f3d4, 0xf1bd0→0x47f3cc, 0xf1be0→0x47f3d0
 * 调用序列: MemoryManager::Free(void const*)×3 / FINALIZE_Code_Constant()+0xac / FINALIZE_Code_Constant()+0xb0 / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc4×2 / 0xc×2 / 0xb0×1 / 0xa4×1 / 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1bb0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf1bb4 ldr r3, [pc, #0xc4]
 *   @0xf1bb8 ldr r2, [pc, #0xc4]
 *   @0xf1bbc add r3, pc, r3
 *   @0xf1bc0 ldr r8, [r3, r2]
 *   @0xf1bc4 ldr r0, [r8]
 *   @0xf1bc8 cmp r0, #0
 *   @0xf1bcc popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf1bd0 ldr r2, [pc, #0xb0]
 *   @0xf1bd4 ldr r10, [r3, r2]
 *   @0xf1bd8 ldr r1, [r10]
 *   @0xf1bdc cmp r1, #0
 *   @0xf1be0 ldr r1, [pc, #0xa4]
 *   @0xf1be4 ble 0xf1c5c <_Z22FINALIZE_Code_Constantv+0xac>
 *   @0xf1be8 mov r4, #0
 *   @0xf1bec ldr r9, [r3, r1]
 *   @0xf1bf0 mov r11, r4
 *   @0xf1bf4 b 0xf1c18 <_Z22FINALIZE_Code_Constantv+0x68>
 *   @0xf1bf8 mov r3, #5
 *   @0xf1bfc str r11, [r5, #0x8]
 *   @0xf1c00 str r3, [r5, #0xc]
 *   @0xf1c04 str r11, [r7, r6]
 *   @0xf1c08 ldr r3, [r10]
 *   @0xf1c0c ldr r0, [r8]
 *   @0xf1c10 cmp r3, r4
 *   @0xf1c14 ble 0xf1c60 <_Z22FINALIZE_Code_Constantv+0xb0>
 *   @0xf1c18 ldr r0, [r0, r4, lsl #2]
 *   @0xf1c1c lsl r6, r4, #4
 *   @0xf1c20 add r4, r4, #1
 *   @0xf1c24 cmp r0, #0
 *   @0xf1c28 beq 0xf1c30 <_Z22FINALIZE_Code_Constantv+0x80>
 *   @0xf1c2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf1c30 ldr r7, [r9]
 *   @0xf1c34 add r5, r7, r6
 *   @0xf1c38 ldr r3, [r5, #0xc]
 *   @0xf1c3c sub r3, r3, #1
 *   @0xf1c40 bic r3, r3, #-16777216
 *   @0xf1c44 bic r3, r3, #3
 *   @0xf1c48 cmp r3, #0
 *   @0xf1c4c bne 0xf1bf8 <_Z22FINALIZE_Code_Constantv+0x48>
 *   @0xf1c50 mov r0, r5
 *   @0xf1c54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xf1c58 b 0xf1bf8 <_Z22FINALIZE_Code_Constantv+0x48>
 *   @0xf1c5c ldr r9, [r3, r1]
 *   @0xf1c60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf1c64 ldr r0, [r9]
 *   @0xf1c68 mov r4, #0
 *   @0xf1c6c str r4, [r8]
 *   @0xf1c70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf1c74 str r4, [r10]
 *   @0xf1c78 str r4, [r9]
 *   @0xf1c7c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf1c80 mlaseq r0, r4, r0, r0
 *   @0xf1c84 .word 0xffffc178
 *   @0xf1c88 .word 0xffffc174
 *   @0xf1c8c .word 0xffffc17c
 *
 * ══ §25/137 FindFaceIndex(unsigned char*, int, long)  0xf9580  size 224  56 条（0xf9580..0xf9660）
 * @func 0xf9580 0xf9660  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_New_Memory_Face×2 / FT_Done_Face×2 / FindFaceIndex(unsigned char*, int, long)+0x54
 * 字段偏移 top8: 0xc×3 / 0xcc×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9580 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf9584 sub sp, sp, #20
 *   @0xf9588 ldr r9, [pc, #0xcc]
 *   @0xf958c add r8, sp, #16
 *   @0xf9590 mov r10, r0
 *   @0xf9594 mov r11, r1
 *   @0xf9598 ldr r9, [pc, r9]
 *   @0xf959c mov r4, #0
 *   @0xf95a0 mov r7, r2
 *   @0xf95a4 str r4, [r8, #-0x4]!
 *   @0xf95a8 ldr r0, [r9]
 *   @0xf95ac mov r1, r10
 *   @0xf95b0 str r8, [sp]
 *   @0xf95b4 mov r2, r11
 *   @0xf95b8 mov r3, r4
 *   @0xf95bc blx 0x2e96f0 <FT_New_Memory_Face>
 *   @0xf95c0 subs r6, r0, #0
 *   @0xf95c4 beq 0xf9654 <_Z13FindFaceIndexPhil+0xd4>
 *   @0xf95c8 ldr r3, [sp, #0xc]
 *   @0xf95cc ldr r5, [r3]
 *   @0xf95d0 b 0xf95f0 <_Z13FindFaceIndexPhil+0x70>
 *   @0xf95d4 rsbs r3, r6, #1
 *   @0xf95d8 movlo r3, #0
 *   @0xf95dc cmp r4, r5
 *   @0xf95e0 movge r3, #0
 *   @0xf95e4 cmp r3, #0
 *   @0xf95e8 ldr r3, [sp, #0xc]
 *   @0xf95ec beq 0xf9634 <_Z13FindFaceIndexPhil+0xb4>
 *   @0xf95f0 ldr r2, [r3, #0xc]
 *   @0xf95f4 mov r0, r3
 *   @0xf95f8 and r2, r2, #3
 *   @0xf95fc cmp r2, r7
 *   @0xf9600 beq 0xf9640 <_Z13FindFaceIndexPhil+0xc0>
 *   @0xf9604 add r4, r4, #1
 *   @0xf9608 blx 0x2e8bdc <FT_Done_Face>
 *   @0xf960c cmp r5, r4
 *   @0xf9610 ble 0xf95d4 <_Z13FindFaceIndexPhil+0x54>
 *   @0xf9614 ldr r0, [r9]
 *   @0xf9618 mov r1, r10
 *   @0xf961c str r8, [sp]
 *   @0xf9620 mov r2, r11
 *   @0xf9624 mov r3, r4
 *   @0xf9628 blx 0x2e96f0 <FT_New_Memory_Face>
 *   @0xf962c mov r6, r0
 *   @0xf9630 b 0xf95d4 <_Z13FindFaceIndexPhil+0x54>
 *   @0xf9634 cmp r3, #0
 *   @0xf9638 mvn r4, #0
 *   @0xf963c beq 0xf9648 <_Z13FindFaceIndexPhil+0xc8>
 *   @0xf9640 mov r0, r3
 *   @0xf9644 blx 0x2e8bdc <FT_Done_Face>
 *   @0xf9648 mov r0, r4
 *   @0xf964c add sp, sp, #20
 *   @0xf9650 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf9654 mvn r4, #0
 *   @0xf9658 b 0xf9648 <_Z13FindFaceIndexPhil+0xc8>
 *   @0xf965c .word 0x002f48b8
 *
 * ══ §26/137 F_CollisionRectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x109030  size 224  56 条（0x109030..0x109110）
 * @func 0x109030 0x109110  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_CollisionRectangle(CInstance*, float, float, float, float, int, bool, bool)
 * 字段偏移 top8: 0x14×2 / 0xc×2 / 0x40×1 / 0x4×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109030 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109034 sub sp, sp, #28
 *   @0x109038 mov r5, r0
 *   @0x10903c mov r6, r1
 *   @0x109040 ldr r4, [sp, #0x40]
 *   @0x109044 mov r1, #0
 *   @0x109048 mov r0, r4
 *   @0x10904c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109050 mov r1, #1
 *   @0x109054 mov r9, r0
 *   @0x109058 mov r0, r4
 *   @0x10905c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109060 mov r1, #2
 *   @0x109064 mov r8, r0
 *   @0x109068 mov r0, r4
 *   @0x10906c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109070 mov r1, #3
 *   @0x109074 mov r7, r0
 *   @0x109078 mov r0, r4
 *   @0x10907c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109080 mov r1, #4
 *   @0x109084 mov r3, r0
 *   @0x109088 mov r0, r4
 *   @0x10908c str r3, [sp, #0x14]
 *   @0x109090 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109094 mov r1, #5
 *   @0x109098 mov r11, r0
 *   @0x10909c mov r0, r4
 *   @0x1090a0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1090a4 mov r1, #6
 *   @0x1090a8 mov r10, r0
 *   @0x1090ac mov r0, r4
 *   @0x1090b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1090b4 ldr r3, [sp, #0x14]
 *   @0x1090b8 mov r2, r8
 *   @0x1090bc str r11, [sp, #0x4]
 *   @0x1090c0 str r10, [sp, #0x8]
 *   @0x1090c4 mov r1, r9
 *   @0x1090c8 str r3, [sp]
 *   @0x1090cc mov r3, r7
 *   @0x1090d0 str r0, [sp, #0xc]
 *   @0x1090d4 mov r0, r6
 *   @0x1090d8 bl 0x1ca350 <_Z26Command_CollisionRectangleP9CInstanceffffibb>
 *   @0x1090dc mov r3, #0
 *   @0x1090e0 str r3, [r5, #0xc]
 *   @0x1090e4 cmp r0, #0
 *   @0x1090e8 ldrne r2, [r0, #0x78]
 *   @0x1090ec moveq r3, #0
 *   @0x1090f0 moveq r2, #0
 *   @0x1090f4 movteq r3, #0xc010
 *   @0x1090f8 vmovne s15, r2
 *   @0x1090fc vcvtne.f64.s32 d7, s15
 *   @0x109100 vmovne r2, r3, d7
 *   @0x109104 stm r5, {r2, r3}
 *   @0x109108 add sp, sp, #28
 *   @0x10910c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §27/137 F_CollisionEllipse(RValue&, CInstance*, CInstance*, int, RValue*)  0x109110  size 224  56 条（0x109110..0x1091f0）
 * @func 0x109110 0x1091f0  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_CollisionEllipse(CInstance*, float, float, float, float, int, bool, bool)
 * 字段偏移 top8: 0x14×2 / 0xc×2 / 0x40×1 / 0x4×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109110 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109114 sub sp, sp, #28
 *   @0x109118 mov r5, r0
 *   @0x10911c mov r6, r1
 *   @0x109120 ldr r4, [sp, #0x40]
 *   @0x109124 mov r1, #0
 *   @0x109128 mov r0, r4
 *   @0x10912c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109130 mov r1, #1
 *   @0x109134 mov r9, r0
 *   @0x109138 mov r0, r4
 *   @0x10913c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109140 mov r1, #2
 *   @0x109144 mov r8, r0
 *   @0x109148 mov r0, r4
 *   @0x10914c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109150 mov r1, #3
 *   @0x109154 mov r7, r0
 *   @0x109158 mov r0, r4
 *   @0x10915c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109160 mov r1, #4
 *   @0x109164 mov r3, r0
 *   @0x109168 mov r0, r4
 *   @0x10916c str r3, [sp, #0x14]
 *   @0x109170 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109174 mov r1, #5
 *   @0x109178 mov r11, r0
 *   @0x10917c mov r0, r4
 *   @0x109180 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x109184 mov r1, #6
 *   @0x109188 mov r10, r0
 *   @0x10918c mov r0, r4
 *   @0x109190 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x109194 ldr r3, [sp, #0x14]
 *   @0x109198 mov r2, r8
 *   @0x10919c str r11, [sp, #0x4]
 *   @0x1091a0 str r10, [sp, #0x8]
 *   @0x1091a4 mov r1, r9
 *   @0x1091a8 str r3, [sp]
 *   @0x1091ac mov r3, r7
 *   @0x1091b0 str r0, [sp, #0xc]
 *   @0x1091b4 mov r0, r6
 *   @0x1091b8 bl 0x1c8bb4 <_Z24Command_CollisionEllipseP9CInstanceffffibb>
 *   @0x1091bc mov r3, #0
 *   @0x1091c0 str r3, [r5, #0xc]
 *   @0x1091c4 cmp r0, #0
 *   @0x1091c8 ldrne r2, [r0, #0x78]
 *   @0x1091cc moveq r3, #0
 *   @0x1091d0 moveq r2, #0
 *   @0x1091d4 movteq r3, #0xc010
 *   @0x1091d8 vmovne s15, r2
 *   @0x1091dc vcvtne.f64.s32 d7, s15
 *   @0x1091e0 vmovne r2, r3, d7
 *   @0x1091e4 stm r5, {r2, r3}
 *   @0x1091e8 add sp, sp, #28
 *   @0x1091ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §28/137 F_CollisionCircle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1091f0  size 224  56 条（0x1091f0..0x1092d0）
 * @func 0x1091f0 0x1092d0  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetBool(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_CollisionEllipse(CInstance*, float, float, float, float, int, bool, bool)
 * 字段偏移 top8: 0xc×2 / 0x38×1 / 0x4×1 / 0x8×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1091f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1091f4 vpush {d8, d9}
 *   @0x1091f8 sub sp, sp, #16
 *   @0x1091fc mov r5, r0
 *   @0x109200 mov r6, r1
 *   @0x109204 ldr r4, [sp, #0x38]
 *   @0x109208 mov r1, #0
 *   @0x10920c mov r0, r4
 *   @0x109210 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109214 mov r1, #1
 *   @0x109218 vmov s17, r0
 *   @0x10921c mov r0, r4
 *   @0x109220 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109224 mov r1, #2
 *   @0x109228 vmov s18, r0
 *   @0x10922c mov r0, r4
 *   @0x109230 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109234 mov r1, #3
 *   @0x109238 vmov s16, r0
 *   @0x10923c mov r0, r4
 *   @0x109240 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109244 mov r1, #4
 *   @0x109248 mov r8, r0
 *   @0x10924c mov r0, r4
 *   @0x109250 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x109254 mov r1, #5
 *   @0x109258 mov r7, r0
 *   @0x10925c mov r0, r4
 *   @0x109260 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x109264 vadd.f32 s15, s18, s16
 *   @0x109268 str r8, [sp, #0x4]
 *   @0x10926c str r7, [sp, #0x8]
 *   @0x109270 vsub.f32 s14, s17, s16
 *   @0x109274 vstr s15, [sp]
 *   @0x109278 vsub.f32 s18, s18, s16
 *   @0x10927c vmov r1, s14
 *   @0x109280 vadd.f32 s16, s17, s16
 *   @0x109284 vmov r2, s18
 *   @0x109288 str r0, [sp, #0xc]
 *   @0x10928c mov r0, r6
 *   @0x109290 vmov r3, s16
 *   @0x109294 bl 0x1c8bb4 <_Z24Command_CollisionEllipseP9CInstanceffffibb>
 *   @0x109298 mov r3, #0
 *   @0x10929c str r3, [r5, #0xc]
 *   @0x1092a0 cmp r0, #0
 *   @0x1092a4 ldrne r2, [r0, #0x78]
 *   @0x1092a8 moveq r3, #0
 *   @0x1092ac moveq r2, #0
 *   @0x1092b0 movteq r3, #0xc010
 *   @0x1092b4 vmovne s15, r2
 *   @0x1092b8 vcvtne.f64.s32 d7, s15
 *   @0x1092bc vmovne r2, r3, d7
 *   @0x1092c0 stm r5, {r2, r3}
 *   @0x1092c4 add sp, sp, #16
 *   @0x1092c8 vpop {d8, d9}
 *   @0x1092cc pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §29/137 F_MpLinearPath(RValue&, CInstance*, CInstance*, int, RValue*)  0x109c88  size 224  56 条（0x109c88..0x109d68）
 * @func 0x109c88 0x109d68  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Path_Exists(int) / Path_Data(int) / YYGetBool(RValue const*, int) / Motion_Linear_Path(CInstance*, CPath*, float, float, float, int, bool)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x38×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109c88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109c8c sub sp, sp, #20
 *   @0x109c90 mov r5, r0
 *   @0x109c94 mov r6, r1
 *   @0x109c98 ldr r4, [sp, #0x38]
 *   @0x109c9c mov r1, #0
 *   @0x109ca0 mov r0, r4
 *   @0x109ca4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109ca8 mov r7, r0
 *   @0x109cac bl 0x1a8008 <_Z11Path_Existsi>
 *   @0x109cb0 subs r1, r0, #0
 *   @0x109cb4 beq 0x109d50 <_Z14F_MpLinearPathR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x109cb8 mov r0, r7
 *   @0x109cbc mov r7, #0
 *   @0x109cc0 str r7, [r5, #0xc]
 *   @0x109cc4 bl 0x1a815c <_Z9Path_Datai>
 *   @0x109cc8 mov r1, #1
 *   @0x109ccc mov r10, r0
 *   @0x109cd0 mov r0, r4
 *   @0x109cd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109cd8 mov r1, #2
 *   @0x109cdc mov r9, r0
 *   @0x109ce0 mov r0, r4
 *   @0x109ce4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109ce8 mov r1, #3
 *   @0x109cec mov r8, r0
 *   @0x109cf0 mov r0, r4
 *   @0x109cf4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109cf8 mov r1, #4
 *   @0x109cfc mov r11, r0
 *   @0x109d00 mov r0, r4
 *   @0x109d04 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x109d08 mov r3, r8
 *   @0x109d0c mvn r12, #2
 *   @0x109d10 str r11, [sp]
 *   @0x109d14 mov r1, r10
 *   @0x109d18 mov r2, r9
 *   @0x109d1c str r12, [sp, #0x4]
 *   @0x109d20 str r0, [sp, #0x8]
 *   @0x109d24 mov r0, r6
 *   @0x109d28 bl 0x19c9cc <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib>
 *   @0x109d2c cmp r0, #0
 *   @0x109d30 moveq r7, r0
 *   @0x109d34 movne r3, r7
 *   @0x109d38 moveq r3, r7
 *   @0x109d3c movtne r3, #0x3ff0
 *   @0x109d40 str r7, [r5]
 *   @0x109d44 str r3, [r5, #0x4]
 *   @0x109d48 add sp, sp, #20
 *   @0x109d4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x109d50 ldr r0, [pc, #0xc]
 *   @0x109d54 add r0, pc, r0
 *   @0x109d58 add sp, sp, #20
 *   @0x109d5c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109d60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x109d64 eoreq lr, r2, r8, ror r9
 *
 * ══ §30/137 F_VariableGlobalExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x1197a4  size 224  56 条（0x1197a4..0x119884）
 * @func 0x1197a4 0x119884  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / Variable_BuiltIn_Find(char const*) / F_VariableGlobalExists(RValue&, CInstance*, CInstance*, int, RValue*)+0xbc / Variable_GetValue_Direct(YYObjectBase*, int, int, RValue*) / FREE_RValue__Pre(RValue*) / Code_Variable_Find_Slot_From_Name(YYObjectBase*, char const*) / F_VariableGlobalExists(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4
 * 字段偏移 top8: 0xc×3 / 0x4×3 / 0x20×1 / 0xbc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1197a4 push {r4, r5, r6, lr}
 *   @0x1197a8 sub sp, sp, #16
 *   @0x1197ac mov r5, r0
 *   @0x1197b0 mov r1, #0
 *   @0x1197b4 ldr r0, [sp, #0x20]
 *   @0x1197b8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1197bc ldr r3, [pc, #0xbc]
 *   @0x1197c0 mov r2, #0
 *   @0x1197c4 mov r12, #13
 *   @0x1197c8 ldr r3, [pc, r3]
 *   @0x1197cc str r12, [r5, #0xc]
 *   @0x1197d0 str r2, [r5, #0x4]
 *   @0x1197d4 ldr r4, [r3]
 *   @0x1197d8 str r2, [r5]
 *   @0x1197dc mov r6, r0
 *   @0x1197e0 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc>
 *   @0x1197e4 subs r1, r0, #0
 *   @0x1197e8 blt 0x119860 <_Z22F_VariableGlobalExistsR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1197ec mov r0, r4
 *   @0x1197f0 mov r2, #-2147483648
 *   @0x1197f4 mov r3, sp
 *   @0x1197f8 mov r4, #0
 *   @0x1197fc str r4, [sp]
 *   @0x119800 str r4, [sp, #0x4]
 *   @0x119804 str r4, [sp, #0x8]
 *   @0x119808 str r4, [sp, #0xc]
 *   @0x11980c bl 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue>
 *   @0x119810 ldr r2, [sp, #0xc]
 *   @0x119814 mvn r3, #-16777216
 *   @0x119818 and r1, r2, r3
 *   @0x11981c cmp r1, r3
 *   @0x119820 moveq r1, r4
 *   @0x119824 movne r1, #0
 *   @0x119828 movtne r1, #0x3ff0
 *   @0x11982c sub r2, r2, #1
 *   @0x119830 str r4, [r5]
 *   @0x119834 bic r2, r2, #-16777216
 *   @0x119838 str r1, [r5, #0x4]
 *   @0x11983c bic r2, r2, #3
 *   @0x119840 cmp r2, #0
 *   @0x119844 beq 0x119850 <_Z22F_VariableGlobalExistsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x119848 add sp, sp, #16
 *   @0x11984c pop {r4, r5, r6, pc}
 *   @0x119850 mov r0, sp
 *   @0x119854 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x119858 add sp, sp, #16
 *   @0x11985c pop {r4, r5, r6, pc}
 *   @0x119860 mov r1, r6
 *   @0x119864 mov r0, r4
 *   @0x119868 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x11986c cmp r0, #0
 *   @0x119870 blt 0x119848 <_Z22F_VariableGlobalExistsR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x119874 add r1, r0, #99328
 *   @0x119878 add r1, r1, #672
 *   @0x11987c b 0x1197ec <_Z22F_VariableGlobalExistsR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x119880 eoreq r4, sp, r12, ror #7
 *
 * ══ §31/137 F_DrawSurfacePart(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ea2c  size 224  56 条（0x11ea2c..0x11eb0c）
 * @func 0x11ea2c 0x11eb0c  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int) / GR_Draw_Get_Alpha() / YYGML_draw_surface_part_ext(int, float, float, float, float, float, float, float, float, int, float)
 * 字段偏移 top8: 0xc×2 / 0x40×1 / 0x4×1 / 0x8×1 / 0x14×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ea2c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11ea30 sub sp, sp, #32
 *   @0x11ea34 mov r1, #0
 *   @0x11ea38 ldr r4, [sp, #0x40]
 *   @0x11ea3c mov r0, r4
 *   @0x11ea40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ea44 mov r1, #1
 *   @0x11ea48 mov r5, r0
 *   @0x11ea4c mov r0, r4
 *   @0x11ea50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ea54 mov r1, #2
 *   @0x11ea58 mov r8, r0
 *   @0x11ea5c mov r0, r4
 *   @0x11ea60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ea64 mov r1, #3
 *   @0x11ea68 mov r7, r0
 *   @0x11ea6c mov r0, r4
 *   @0x11ea70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ea74 mov r1, #4
 *   @0x11ea78 mov r6, r0
 *   @0x11ea7c mov r0, r4
 *   @0x11ea80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ea84 mov r1, #5
 *   @0x11ea88 mov r10, r0
 *   @0x11ea8c mov r0, r4
 *   @0x11ea90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ea94 mov r1, #6
 *   @0x11ea98 mov r9, r0
 *   @0x11ea9c mov r0, r4
 *   @0x11eaa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eaa4 mov r4, r0
 *   @0x11eaa8 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11eaac mov r12, #1065353216
 *   @0x11eab0 mov r1, r8
 *   @0x11eab4 mvn lr, #-16777216
 *   @0x11eab8 str r10, [sp]
 *   @0x11eabc str r9, [sp, #0x4]
 *   @0x11eac0 mov r2, r7
 *   @0x11eac4 str r4, [sp, #0x8]
 *   @0x11eac8 mov r3, r6
 *   @0x11eacc str lr, [sp, #0x14]
 *   @0x11ead0 str r12, [sp, #0xc]
 *   @0x11ead4 str r12, [sp, #0x10]
 *   @0x11ead8 str r0, [sp, #0x18]
 *   @0x11eadc mov r0, r5
 *   @0x11eae0 bl 0x171ee0 <_Z27YYGML_draw_surface_part_extiffffffffif>
 *   @0x11eae4 subs r1, r0, #0
 *   @0x11eae8 beq 0x11eaf4 <_Z17F_DrawSurfacePartR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x11eaec add sp, sp, #32
 *   @0x11eaf0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11eaf4 ldr r0, [pc, #0xc]
 *   @0x11eaf8 add r0, pc, r0
 *   @0x11eafc add sp, sp, #32
 *   @0x11eb00 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11eb04 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11eb08 eoreq r11, r1, r0, ror r7
 *
 * ══ §32/137 F_GPUSetTexFilterExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1474ac  size 224  56 条（0x1474ac..0x14758c）
 * @func 0x1474ac 0x14758c  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)×2 / YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0xa4×1 / 0x64×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1474ac cmp r3, #2
 *   @0x1474b0 mov r3, #0
 *   @0x1474b4 push {r4, r5, r6, lr}
 *   @0x1474b8 mov r4, r3
 *   @0x1474bc ldr r5, [sp, #0x10]
 *   @0x1474c0 movt r3, #0xbff0
 *   @0x1474c4 str r4, [r0, #0xc]
 *   @0x1474c8 str r3, [r0, #0x4]
 *   @0x1474cc str r4, [r0]
 *   @0x1474d0 beq 0x1474e8 <_Z20F_GPUSetTexFilterExtR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1474d4 ldr r0, [pc, #0xa4]
 *   @0x1474d8 mov r1, r4
 *   @0x1474dc pop {r4, r5, r6, lr}
 *   @0x1474e0 add r0, pc, r0
 *   @0x1474e4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1474e8 mov r0, r5
 *   @0x1474ec mov r1, r4
 *   @0x1474f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1474f4 mov r1, #1
 *   @0x1474f8 mov r6, r0
 *   @0x1474fc mov r0, r5
 *   @0x147500 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x147504 cmp r6, #7
 *   @0x147508 mov r5, r0
 *   @0x14750c pophi {r4, r5, r6, pc}
 *   @0x147510 cmp r0, #0
 *   @0x147514 bne 0x14754c <_Z20F_GPUSetTexFilterExtR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x147518 ldr r4, [pc, #0x64]
 *   @0x14751c mov r1, r6
 *   @0x147520 mov r2, r0
 *   @0x147524 mov r3, r0
 *   @0x147528 ldr r4, [pc, r4]
 *   @0x14752c mov r0, r4
 *   @0x147530 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147534 mov r0, r4
 *   @0x147538 mov r1, r6
 *   @0x14753c mov r3, r5
 *   @0x147540 mov r2, #1
 *   @0x147544 pop {r4, r5, r6, lr}
 *   @0x147548 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x14754c ldr r5, [pc, #0x34]
 *   @0x147550 mov r2, r4
 *   @0x147554 mov r1, r6
 *   @0x147558 mov r3, #1
 *   @0x14755c ldr r5, [pc, r5]
 *   @0x147560 mov r0, r5
 *   @0x147564 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147568 mov r2, #1
 *   @0x14756c mov r0, r5
 *   @0x147570 mov r1, r6
 *   @0x147574 mov r3, r2
 *   @0x147578 pop {r4, r5, r6, lr}
 *   @0x14757c b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147580 mulseq pc, r12, r5
 *   @0x147584 .word 0x002a67d0
 *   @0x147588 mlaeq r10, r12, r7, r6
 *
 * ══ §33/137 F_GPUSetTexRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x147664  size 224  56 条（0x147664..0x147744）
 * @func 0x147664 0x147744  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)×2 / YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0xa0×1 / 0x64×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147664 cmp r3, #2
 *   @0x147668 mov r1, #0
 *   @0x14766c push {r4, r5, r6, r7, r8, lr}
 *   @0x147670 mov r4, r1
 *   @0x147674 mov r5, r3
 *   @0x147678 movt r1, #0xbff0
 *   @0x14767c str r4, [r0, #0xc]
 *   @0x147680 str r1, [r0, #0x4]
 *   @0x147684 str r4, [r0]
 *   @0x147688 ldr r6, [sp, #0x18]
 *   @0x14768c beq 0x1476a4 <_Z20F_GPUSetTexRepeatExtR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x147690 ldr r0, [pc, #0xa0]
 *   @0x147694 mov r1, r4
 *   @0x147698 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14769c add r0, pc, r0
 *   @0x1476a0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1476a4 mov r1, r4
 *   @0x1476a8 mov r0, r6
 *   @0x1476ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1476b0 mov r1, #1
 *   @0x1476b4 mov r7, r0
 *   @0x1476b8 mov r0, r6
 *   @0x1476bc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1476c0 cmp r7, #7
 *   @0x1476c4 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x1476c8 cmp r0, #0
 *   @0x1476cc bne 0x147704 <_Z20F_GPUSetTexRepeatExtR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1476d0 ldr r4, [pc, #0x64]
 *   @0x1476d4 mov r2, r5
 *   @0x1476d8 mov r1, r7
 *   @0x1476dc mov r3, #1
 *   @0x1476e0 ldr r4, [pc, r4]
 *   @0x1476e4 mov r0, r4
 *   @0x1476e8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1476ec mov r0, r4
 *   @0x1476f0 mov r1, r7
 *   @0x1476f4 mov r2, #3
 *   @0x1476f8 mov r3, #1
 *   @0x1476fc pop {r4, r5, r6, r7, r8, lr}
 *   @0x147700 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147704 ldr r6, [pc, #0x34]
 *   @0x147708 mov r2, r5
 *   @0x14770c mov r1, r7
 *   @0x147710 mov r3, r4
 *   @0x147714 ldr r6, [pc, r6]
 *   @0x147718 mov r0, r6
 *   @0x14771c bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147720 mov r0, r6
 *   @0x147724 mov r1, r7
 *   @0x147728 mov r3, r4
 *   @0x14772c mov r2, #3
 *   @0x147730 pop {r4, r5, r6, r7, r8, lr}
 *   @0x147734 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147738 andseq r10, pc, r0, ror r4
 *   @0x14773c eoreq r6, r10, r8, lsl r6
 *   @0x147740 eoreq r6, r10, r4, ror #11
 *
 * ══ §34/137 F_PhysicsFixtureAddShapePoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c49c  size 224  56 条（0x14c49c..0x14c57c）
 * @func 0x14c49c 0x14c57c  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / CPhysicsFixture::AddShapePoint(float, float)
 * 字段偏移 top8: 0x18×1 / 0xa4×1 / 0xb4×1 / 0x3c×1 / 0x28×1 / 0x14×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c49c push {r4, r5, r6, lr}
 *   @0x14c4a0 vpush {d8}
 *   @0x14c4a4 mov r1, #0
 *   @0x14c4a8 ldr r5, [sp, #0x18]
 *   @0x14c4ac mov r0, r5
 *   @0x14c4b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c4b4 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14c4b8 subs r6, r0, #0
 *   @0x14c4bc beq 0x14c554 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14c4c0 ldr r3, [pc, #0xa4]
 *   @0x14c4c4 ldr r3, [pc, r3]
 *   @0x14c4c8 ldr r3, [r3]
 *   @0x14c4cc ldr r4, [r3, #0xb4]
 *   @0x14c4d0 cmp r4, #0
 *   @0x14c4d4 beq 0x14c53c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14c4d8 mov r1, #1
 *   @0x14c4dc mov r0, r5
 *   @0x14c4e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c4e4 mov r1, #2
 *   @0x14c4e8 vldr s16, [r4, #96]
 *   @0x14c4ec vmov s14, r0
 *   @0x14c4f0 mov r0, r5
 *   @0x14c4f4 vmul.f32 s16, s14, s16
 *   @0x14c4f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c4fc vldr s15, [r4, #96]
 *   @0x14c500 vmov r1, s16
 *   @0x14c504 vmov s14, r0
 *   @0x14c508 mov r0, r6
 *   @0x14c50c vmul.f32 s15, s14, s15
 *   @0x14c510 vmov r2, s15
 *   @0x14c514 bl 0x236ac8 <_ZN15CPhysicsFixture13AddShapePointEff>
 *   @0x14c518 subs r1, r0, #0
 *   @0x14c51c beq 0x14c528 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x14c520 vpop {d8}
 *   @0x14c524 pop {r4, r5, r6, pc}
 *   @0x14c528 vpop {d8}
 *   @0x14c52c ldr r0, [pc, #0x3c]
 *   @0x14c530 add r0, pc, r0
 *   @0x14c534 pop {r4, r5, r6, lr}
 *   @0x14c538 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c53c vpop {d8}
 *   @0x14c540 mov r1, r4
 *   @0x14c544 ldr r0, [pc, #0x28]
 *   @0x14c548 add r0, pc, r0
 *   @0x14c54c pop {r4, r5, r6, lr}
 *   @0x14c550 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c554 vpop {d8}
 *   @0x14c558 mov r1, r6
 *   @0x14c55c ldr r0, [pc, #0x14]
 *   @0x14c560 add r0, pc, r0
 *   @0x14c564 pop {r4, r5, r6, lr}
 *   @0x14c568 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c56c eoreq r1, r10, r4, ror #8
 *   @0x14c570 andseq r7, pc, r4, lsr r9
 *   @0x14c574 ldrsbeq r7, [pc], -r12
 *   @0x14c578 andseq r7, pc, r8, asr #16
 *
 * ══ §35/137 FacebookLoginStatusM()  0x15f0dc  size 224  56 条（0x15f0dc..0x15f1bc）
 * @func 0x15f0dc 0x15f1bc  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×4 / _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) / 0xb6568
 * 字段偏移 top8: 0xb8×2 / 0x2c×2 / 0x2a4×1 / 0x7c×1 / 0x2a8×1 / 0x5c×1 / 0x38×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f0dc push {r3, r4, r5, lr}
 *   @0x15f0e0 bl 0x290274 <getJNIEnv>
 *   @0x15f0e4 ldr r2, [pc, #0xb8]
 *   @0x15f0e8 ldr r3, [pc, #0xb8]
 *   @0x15f0ec ldr r2, [pc, r2]
 *   @0x15f0f0 ldr r3, [pc, r3]
 *   @0x15f0f4 ldr r1, [r2]
 *   @0x15f0f8 ldr r2, [r3]
 *   @0x15f0fc bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f100 subs r5, r0, #0
 *   @0x15f104 beq 0x15f180 <_Z20FacebookLoginStatusMv+0xa4>
 *   @0x15f108 bl 0x290274 <getJNIEnv>
 *   @0x15f10c mov r1, r5
 *   @0x15f110 mov r2, #0
 *   @0x15f114 ldr r3, [r0]
 *   @0x15f118 ldr r3, [r3, #0x2a4]
 *   @0x15f11c blx r3
 *   @0x15f120 mov r2, #31
 *   @0x15f124 mov r4, r0
 *   @0x15f128 ldr r0, [pc, #0x7c]
 *   @0x15f12c mov r1, r4
 *   @0x15f130 add r0, pc, r0
 *   @0x15f134 add r0, r0, #512
 *   @0x15f138 bl 0xb6568 <strncpy@plt>
 *   @0x15f13c cmp r4, #0
 *   @0x15f140 beq 0x15f170 <_Z20FacebookLoginStatusMv+0x94>
 *   @0x15f144 bl 0x290274 <getJNIEnv>
 *   @0x15f148 mov r1, r5
 *   @0x15f14c mov r2, r4
 *   @0x15f150 ldr r3, [r0]
 *   @0x15f154 ldr r3, [r3, #0x2a8]
 *   @0x15f158 blx r3
 *   @0x15f15c bl 0x290274 <getJNIEnv>
 *   @0x15f160 mov r1, r5
 *   @0x15f164 ldr r3, [r0]
 *   @0x15f168 ldr r3, [r3, #0x5c]
 *   @0x15f16c blx r3
 *   @0x15f170 ldr r0, [pc, #0x38]
 *   @0x15f174 add r0, pc, r0
 *   @0x15f178 add r0, r0, #512
 *   @0x15f17c pop {r3, r4, r5, pc}
 *   @0x15f180 ldr r3, [pc, #0x2c]
 *   @0x15f184 ldr r1, [pc, #0x2c]
 *   @0x15f188 ldr r3, [pc, r3]
 *   @0x15f18c add r1, pc, r1
 *   @0x15f190 ldr r0, [r3]
 *   @0x15f194 ldr r3, [r0]
 *   @0x15f198 ldr r3, [r3, #0xc]
 *   @0x15f19c blx r3
 *   @0x15f1a0 b 0x15f170 <_Z20FacebookLoginStatusMv+0x94>
 *   @0x15f1a4 .word 0x0028e8b8
 *   @0x15f1a8 .word 0x00290dd8
 *   @0x15f1ac eorseq r5, r2, r8, lsl #19
 *   @0x15f1b0 eorseq r5, r2, r4, asr #18
 *   @0x15f1b4 eoreq lr, r8, r12, lsl #11
 *   @0x15f1b8 andseq r10, lr, r4, asr r6
 *
 * ══ §36/137 F_CheckMouseButton_Common(RValue&, CInstance*, CInstance*, int, int)  0x160b2c  size 224  56 条（0x160b2c..0x160c0c）
 * @func 0x160b2c 0x160c0c  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Button_Down(int, int)×3
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160b2c cmn r3, #1
 *   @0x160b30 mov r2, #0
 *   @0x160b34 push {r4, r5, r6, r7, r8, lr}
 *   @0x160b38 mov r4, r0
 *   @0x160b3c ldr r6, [sp, #0x18]
 *   @0x160b40 str r2, [r0, #0xc]
 *   @0x160b44 str r2, [r0]
 *   @0x160b48 str r2, [r0, #0x4]
 *   @0x160b4c beq 0x160bd4 <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0xa8>
 *   @0x160b50 cmp r3, #0
 *   @0x160b54 bne 0x160b94 <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0x68>
 *   @0x160b58 mov r5, #1
 *   @0x160b5c mov r7, r3
 *   @0x160b60 str r3, [r0]
 *   @0x160b64 movt r3, #0x3ff0
 *   @0x160b68 str r3, [r0, #0x4]
 *   @0x160b6c mov r0, r5
 *   @0x160b70 mov r1, r6
 *   @0x160b74 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x160b78 add r5, r5, #1
 *   @0x160b7c cmp r0, #0
 *   @0x160b80 strne r7, [r4]
 *   @0x160b84 strne r7, [r4, #0x4]
 *   @0x160b88 cmp r5, #4
 *   @0x160b8c bne 0x160b6c <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0x40>
 *   @0x160b90 pop {r4, r5, r6, r7, r8, pc}
 *   @0x160b94 cmp r3, #2
 *   @0x160b98 beq 0x160bac <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0x80>
 *   @0x160b9c cmp r3, #3
 *   @0x160ba0 beq 0x160bac <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0x80>
 *   @0x160ba4 cmp r3, #1
 *   @0x160ba8 popne {r4, r5, r6, r7, r8, pc}
 *   @0x160bac mov r0, r3
 *   @0x160bb0 mov r1, r6
 *   @0x160bb4 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x160bb8 vmov s15, r0
 *   @0x160bbc vcvt.f64.u32 d7, s15
 *   @0x160bc0 vmov r0, r1, d7
 *   @0x160bc4 vmov r2, s14
 *   @0x160bc8 mov r3, r1
 *   @0x160bcc stm r4, {r2, r3}
 *   @0x160bd0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x160bd4 mov r7, r2
 *   @0x160bd8 movt r7, #0x3ff0
 *   @0x160bdc mov r8, r2
 *   @0x160be0 mov r5, #1
 *   @0x160be4 mov r0, r5
 *   @0x160be8 mov r1, r6
 *   @0x160bec bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x160bf0 add r5, r5, #1
 *   @0x160bf4 cmp r0, #0
 *   @0x160bf8 strne r8, [r4]
 *   @0x160bfc strne r7, [r4, #0x4]
 *   @0x160c00 cmp r5, #4
 *   @0x160c04 bne 0x160be4 <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii+0xb8>
 *   @0x160c08 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §37/137 F_CheckMouseButtonPressed_Common(RValue&, CInstance*, CInstance*, int, int)  0x160c0c  size 224  56 条（0x160c0c..0x160cec）
 * @func 0x160c0c 0x160cec  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Button_Pressed(int, int)×3
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160c0c cmn r3, #1
 *   @0x160c10 mov r2, #0
 *   @0x160c14 push {r4, r5, r6, r7, r8, lr}
 *   @0x160c18 mov r4, r0
 *   @0x160c1c ldr r6, [sp, #0x18]
 *   @0x160c20 str r2, [r0, #0xc]
 *   @0x160c24 str r2, [r0]
 *   @0x160c28 str r2, [r0, #0x4]
 *   @0x160c2c beq 0x160cb4 <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0xa8>
 *   @0x160c30 cmp r3, #0
 *   @0x160c34 bne 0x160c74 <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0x68>
 *   @0x160c38 mov r5, #1
 *   @0x160c3c mov r7, r3
 *   @0x160c40 str r3, [r0]
 *   @0x160c44 movt r3, #0x3ff0
 *   @0x160c48 str r3, [r0, #0x4]
 *   @0x160c4c mov r0, r5
 *   @0x160c50 mov r1, r6
 *   @0x160c54 bl 0x18c0f0 <_Z17IO_Button_Pressedii>
 *   @0x160c58 add r5, r5, #1
 *   @0x160c5c cmp r0, #0
 *   @0x160c60 strne r7, [r4]
 *   @0x160c64 strne r7, [r4, #0x4]
 *   @0x160c68 cmp r5, #4
 *   @0x160c6c bne 0x160c4c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0x40>
 *   @0x160c70 pop {r4, r5, r6, r7, r8, pc}
 *   @0x160c74 cmp r3, #2
 *   @0x160c78 beq 0x160c8c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0x80>
 *   @0x160c7c cmp r3, #3
 *   @0x160c80 beq 0x160c8c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0x80>
 *   @0x160c84 cmp r3, #1
 *   @0x160c88 popne {r4, r5, r6, r7, r8, pc}
 *   @0x160c8c mov r0, r3
 *   @0x160c90 mov r1, r6
 *   @0x160c94 bl 0x18c0f0 <_Z17IO_Button_Pressedii>
 *   @0x160c98 vmov s15, r0
 *   @0x160c9c vcvt.f64.u32 d7, s15
 *   @0x160ca0 vmov r0, r1, d7
 *   @0x160ca4 vmov r2, s14
 *   @0x160ca8 mov r3, r1
 *   @0x160cac stm r4, {r2, r3}
 *   @0x160cb0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x160cb4 mov r7, r2
 *   @0x160cb8 movt r7, #0x3ff0
 *   @0x160cbc mov r8, r2
 *   @0x160cc0 mov r5, #1
 *   @0x160cc4 mov r0, r5
 *   @0x160cc8 mov r1, r6
 *   @0x160ccc bl 0x18c0f0 <_Z17IO_Button_Pressedii>
 *   @0x160cd0 add r5, r5, #1
 *   @0x160cd4 cmp r0, #0
 *   @0x160cd8 strne r8, [r4]
 *   @0x160cdc strne r7, [r4, #0x4]
 *   @0x160ce0 cmp r5, #4
 *   @0x160ce4 bne 0x160cc4 <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii+0xb8>
 *   @0x160ce8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §38/137 F_CheckMouseButtonReleased_Common(RValue&, CInstance*, CInstance*, int, int)  0x160cec  size 224  56 条（0x160cec..0x160dcc）
 * @func 0x160cec 0x160dcc  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Button_Released(int, int)×3
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160cec cmn r3, #1
 *   @0x160cf0 mov r2, #0
 *   @0x160cf4 push {r4, r5, r6, r7, r8, lr}
 *   @0x160cf8 mov r4, r0
 *   @0x160cfc ldr r6, [sp, #0x18]
 *   @0x160d00 str r2, [r0, #0xc]
 *   @0x160d04 str r2, [r0]
 *   @0x160d08 str r2, [r0, #0x4]
 *   @0x160d0c beq 0x160d94 <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0xa8>
 *   @0x160d10 cmp r3, #0
 *   @0x160d14 bne 0x160d54 <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0x68>
 *   @0x160d18 mov r5, #1
 *   @0x160d1c mov r7, r3
 *   @0x160d20 str r3, [r0]
 *   @0x160d24 movt r3, #0x3ff0
 *   @0x160d28 str r3, [r0, #0x4]
 *   @0x160d2c mov r0, r5
 *   @0x160d30 mov r1, r6
 *   @0x160d34 bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x160d38 add r5, r5, #1
 *   @0x160d3c cmp r0, #0
 *   @0x160d40 strne r7, [r4]
 *   @0x160d44 strne r7, [r4, #0x4]
 *   @0x160d48 cmp r5, #4
 *   @0x160d4c bne 0x160d2c <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0x40>
 *   @0x160d50 pop {r4, r5, r6, r7, r8, pc}
 *   @0x160d54 cmp r3, #2
 *   @0x160d58 beq 0x160d6c <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0x80>
 *   @0x160d5c cmp r3, #3
 *   @0x160d60 beq 0x160d6c <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0x80>
 *   @0x160d64 cmp r3, #1
 *   @0x160d68 popne {r4, r5, r6, r7, r8, pc}
 *   @0x160d6c mov r0, r3
 *   @0x160d70 mov r1, r6
 *   @0x160d74 bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x160d78 vmov s15, r0
 *   @0x160d7c vcvt.f64.u32 d7, s15
 *   @0x160d80 vmov r0, r1, d7
 *   @0x160d84 vmov r2, s14
 *   @0x160d88 mov r3, r1
 *   @0x160d8c stm r4, {r2, r3}
 *   @0x160d90 pop {r4, r5, r6, r7, r8, pc}
 *   @0x160d94 mov r7, r2
 *   @0x160d98 movt r7, #0x3ff0
 *   @0x160d9c mov r8, r2
 *   @0x160da0 mov r5, #1
 *   @0x160da4 mov r0, r5
 *   @0x160da8 mov r1, r6
 *   @0x160dac bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x160db0 add r5, r5, #1
 *   @0x160db4 cmp r0, #0
 *   @0x160db8 strne r8, [r4]
 *   @0x160dbc strne r7, [r4, #0x4]
 *   @0x160dc0 cmp r5, #4
 *   @0x160dc4 bne 0x160da4 <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii+0xb8>
 *   @0x160dc8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §39/137 Cloud_String_Save(char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*))  0x1612b0  size 224  56 条（0x1612b0..0x161390）
 * @func 0x1612b0 0x161390  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×3 / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x4×2 / 0x29c×2 / 0xc8×1 / 0xa8×1 / 0xc×1 / 0x8×1 / 0x34×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1612b0 ldr r12, [pc, #0xc8]
 *   @0x1612b4 mov r3, r0
 *   @0x1612b8 push {r4, r5, r6, r7, lr}
 *   @0x1612bc ldr r12, [pc, r12]
 *   @0x1612c0 mov r4, r0
 *   @0x1612c4 mov r5, r1
 *   @0x1612c8 ldr r0, [r12]
 *   @0x1612cc mov r7, r2
 *   @0x1612d0 mov r2, r1
 *   @0x1612d4 ldr r1, [pc, #0xa8]
 *   @0x1612d8 sub sp, sp, #20
 *   @0x1612dc ldr r12, [r0]
 *   @0x1612e0 add r1, pc, r1
 *   @0x1612e4 ldr r12, [r12, #0xc]
 *   @0x1612e8 blx r12
 *   @0x1612ec mov r0, #68
 *   @0x1612f0 bl 0x27c524 <_Znwj>
 *   @0x1612f4 mov r12, #0
 *   @0x1612f8 mov r2, r12
 *   @0x1612fc str r12, [sp]
 *   @0x161300 str r12, [sp, #0x4]
 *   @0x161304 mov r3, r7
 *   @0x161308 str r12, [sp, #0x8]
 *   @0x16130c mov r1, r4
 *   @0x161310 mov r6, r0
 *   @0x161314 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x161318 bl 0x290274 <getJNIEnv>
 *   @0x16131c mov r1, r4
 *   @0x161320 ldr r3, [r0]
 *   @0x161324 ldr r3, [r3, #0x29c]
 *   @0x161328 blx r3
 *   @0x16132c mov r7, r0
 *   @0x161330 bl 0x290274 <getJNIEnv>
 *   @0x161334 mov r1, r5
 *   @0x161338 ldr r3, [r0]
 *   @0x16133c ldr r3, [r3, #0x29c]
 *   @0x161340 blx r3
 *   @0x161344 mov r4, r0
 *   @0x161348 bl 0x290274 <getJNIEnv>
 *   @0x16134c ldr r1, [pc, #0x34]
 *   @0x161350 mov r3, r7
 *   @0x161354 ldr r2, [pc, #0x30]
 *   @0x161358 ldr r1, [pc, r1]
 *   @0x16135c ldr r2, [pc, r2]
 *   @0x161360 ldr r1, [r1]
 *   @0x161364 ldr r2, [r2]
 *   @0x161368 str r4, [sp]
 *   @0x16136c ldr r12, [r6, #0x24]
 *   @0x161370 str r12, [sp, #0x4]
 *   @0x161374 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161378 add sp, sp, #20
 *   @0x16137c pop {r4, r5, r6, r7, pc}
 *   @0x161380 eoreq r12, r8, r8, asr r4
 *   @0x161384 andseq r8, lr, r4, lsl #16
 *   @0x161388 eoreq r12, r8, r12, asr #12
 *   @0x16138c .word 0x0028ebf0
 *
 * ══ §40/137 CBitmap32::BoundingBox()  0x167508  size 224  56 条（0x167508..0x1675e8）
 * @func 0x167508 0x1675e8  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / CBitmap32::BoundingBox()+0xc8
 * 字段偏移 top8: 0x4×3 / 0xc×3 / 0x8×3 / 0xd4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167508 ldr r1, [pc, #0xd4]
 *   @0x16750c mov r3, #1
 *   @0x167510 push {r4, r5, r6, r7, r8, lr}
 *   @0x167514 add r1, pc, r1
 *   @0x167518 mov r5, r0
 *   @0x16751c movw r2, #0x476
 *   @0x167520 mov r0, #16
 *   @0x167524 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x167528 ldrb r3, [r5, #0x4]
 *   @0x16752c cmp r3, #0
 *   @0x167530 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x167534 ldr r7, [r5, #0xc]
 *   @0x167538 cmp r7, #0
 *   @0x16753c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x167540 ldr r4, [r5, #0x8]
 *   @0x167544 cmp r4, #0
 *   @0x167548 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x16754c cmp r7, #0
 *   @0x167550 mov r12, #0
 *   @0x167554 sub r2, r4, #1
 *   @0x167558 sub r3, r7, #1
 *   @0x16755c str r12, [r0, #0x8]
 *   @0x167560 stm r0, {r2, r3}
 *   @0x167564 str r12, [r0, #0xc]
 *   @0x167568 pople {r4, r5, r6, r7, r8, pc}
 *   @0x16756c lsl r8, r4, #2
 *   @0x167570 mvn r6, #3
 *   @0x167574 cmp r4, #0
 *   @0x167578 ble 0x1675d0 <_ZN9CBitmap3211BoundingBoxEv+0xc8>
 *   @0x16757c ldr r2, [r5, #0x14]
 *   @0x167580 mov r3, #0
 *   @0x167584 add r2, r2, r6
 *   @0x167588 ldr r1, [r2, #0x4]!
 *   @0x16758c tst r1, #-16777216
 *   @0x167590 beq 0x1675c4 <_ZN9CBitmap3211BoundingBoxEv+0xbc>
 *   @0x167594 ldr r1, [r0]
 *   @0x167598 cmp r1, r3
 *   @0x16759c ldr r1, [r0, #0x8]
 *   @0x1675a0 strgt r3, [r0]
 *   @0x1675a4 cmp r1, r3
 *   @0x1675a8 ldr r1, [r0, #0x4]
 *   @0x1675ac strlt r3, [r0, #0x8]
 *   @0x1675b0 cmp r1, r12
 *   @0x1675b4 ldr r1, [r0, #0xc]
 *   @0x1675b8 strgt r12, [r0, #0x4]
 *   @0x1675bc cmp r1, r12
 *   @0x1675c0 strlt r12, [r0, #0xc]
 *   @0x1675c4 add r3, r3, #1
 *   @0x1675c8 cmp r3, r4
 *   @0x1675cc bne 0x167588 <_ZN9CBitmap3211BoundingBoxEv+0x80>
 *   @0x1675d0 add r12, r12, #1
 *   @0x1675d4 add r6, r6, r8
 *   @0x1675d8 cmp r12, r7
 *   @0x1675dc bne 0x167574 <_ZN9CBitmap3211BoundingBoxEv+0x6c>
 *   @0x1675e0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1675e4 andseq r3, lr, r12, lsr #1
 *
 * ══ §41/137 GR_Draw_Arrow(float, float, float, float, float)  0x16bee4  size 224  56 条（0x16bee4..0x16bfc4）
 * @func 0x16bee4 0x16bfc4  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Draw_Line(float, float, float, float) / GR_Draw_Triangle(float, float, float, float, float, float, bool) / 0xb6700
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x4×1
 * VFP 指令 44 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16bee4 str lr, [sp, #-0x4]!
 *   @0x16bee8 vpush {d8, d9, d10, d11}
 *   @0x16beec vmov s21, r1
 *   @0x16bef0 vmov s17, r3
 *   @0x16bef4 sub sp, sp, #20
 *   @0x16bef8 vmov s22, r0
 *   @0x16befc vldr s16, [sp, #56]
 *   @0x16bf00 vsub.f32 s19, s17, s21
 *   @0x16bf04 vmov s18, r2
 *   @0x16bf08 vmul.f32 s14, s19, s19
 *   @0x16bf0c vsub.f32 s20, s18, s22
 *   @0x16bf10 vmla.f32 s14, s20, s20
 *   @0x16bf14 vsqrt.f32 s15, s14
 *   @0x16bf18 vcmp.f32 s15, s15
 *   @0x16bf1c vmrs APSR_nzcv, fpscr
 *   @0x16bf20 bne 0x16bfb4 <_Z13GR_Draw_Arrowfffff+0xd0>
 *   @0x16bf24 vcmp.f32 s15, #0
 *   @0x16bf28 vmrs APSR_nzcv, fpscr
 *   @0x16bf2c beq 0x16bfa8 <_Z13GR_Draw_Arrowfffff+0xc4>
 *   @0x16bf30 vcmp.f32 s15, s16
 *   @0x16bf34 vmov r2, s18
 *   @0x16bf38 vmov r0, s22
 *   @0x16bf3c vmov r1, s21
 *   @0x16bf40 vmrs APSR_nzcv, fpscr
 *   @0x16bf44 vmovmi.f32 s16, s15
 *   @0x16bf48 vmov r3, s17
 *   @0x16bf4c vmul.f32 s20, s16, s20
 *   @0x16bf50 vmul.f32 s16, s16, s19
 *   @0x16bf54 vdiv.f32 s20, s20, s15
 *   @0x16bf58 vdiv.f32 s16, s16, s15
 *   @0x16bf5c bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x16bf60 vmov r2, s18
 *   @0x16bf64 mov r3, #0
 *   @0x16bf68 str r3, [sp, #0x8]
 *   @0x16bf6c vmov r3, s17
 *   @0x16bf70 vmov.f32 s14, #3.000000e+00
 *   @0x16bf74 vdiv.f32 s15, s16, s14
 *   @0x16bf78 vdiv.f32 s14, s20, s14
 *   @0x16bf7c vsub.f32 s18, s18, s20
 *   @0x16bf80 vsub.f32 s16, s17, s16
 *   @0x16bf84 vadd.f32 s12, s18, s15
 *   @0x16bf88 vsub.f32 s13, s16, s14
 *   @0x16bf8c vstr s12, [sp]
 *   @0x16bf90 vsub.f32 s15, s18, s15
 *   @0x16bf94 vstr s13, [sp, #4]
 *   @0x16bf98 vadd.f32 s14, s16, s14
 *   @0x16bf9c vmov r0, s15
 *   @0x16bfa0 vmov r1, s14
 *   @0x16bfa4 bl 0x16a6f0 <_Z16GR_Draw_Triangleffffffb>
 *   @0x16bfa8 add sp, sp, #20
 *   @0x16bfac vpop {d8, d9, d10, d11}
 *   @0x16bfb0 ldr pc, [sp], #4
 *   @0x16bfb4 vmov r0, s14
 *   @0x16bfb8 bl 0xb6700 <sqrtf@plt>
 *   @0x16bfbc vmov s15, r0
 *   @0x16bfc0 b 0x16bf24 <_Z13GR_Draw_Arrowfffff+0x40>
 *
 * ══ §42/137 GR_3D_Primitive_End()  0x176ad0  size 224  56 条（0x176ad0..0x176bb0）
 * @func 0x176ad0 0x176bb0  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x176ad8→0x490004, 0x176b04→0x48fff4, 0x176b18→0x490008, 0x176b20→0x49000c, 0x176b4c→0x3f241c, 0x176b5c→0x490008, 0x176b78→0x49000c
 * 调用序列: GR_3D_Primitive_End()+0x68 / GR_Texture_Get_Surface(int) / Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0xb8×2 / 0x90×1 / 0x80×1 / 0x7c×1 / 0x68×1 / 0x1c×1 / 0x58×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x176ad0 push {r4, r5, r6, lr}
 *   @0x176ad4 ldr r4, [pc, #0xb8]
 *   @0x176ad8 ldr r3, [pc, #0xb8]
 *   @0x176adc add r4, pc, r4
 *   @0x176ae0 ldr r3, [r4, r3]
 *   @0x176ae4 ldr r3, [r3]
 *   @0x176ae8 sub r2, r3, #1
 *   @0x176aec cmp r2, #5
 *   @0x176af0 pophi {r4, r5, r6, pc}
 *   @0x176af4 sub r3, r3, #2
 *   @0x176af8 cmp r3, #4
 *   @0x176afc movhi r5, #1
 *   @0x176b00 bls 0x176b38 <_Z19GR_3D_Primitive_Endv+0x68>
 *   @0x176b04 ldr r3, [pc, #0x90]
 *   @0x176b08 ldr r3, [r4, r3]
 *   @0x176b0c ldr r0, [r3]
 *   @0x176b10 cmp r0, #0
 *   @0x176b14 beq 0x176b4c <_Z19GR_3D_Primitive_Endv+0x7c>
 *   @0x176b18 ldr r2, [pc, #0x80]
 *   @0x176b1c mov r1, r5
 *   @0x176b20 ldr r3, [pc, #0x7c]
 *   @0x176b24 ldr r2, [r4, r2]
 *   @0x176b28 ldr r3, [r4, r3]
 *   @0x176b2c pop {r4, r5, r6, lr}
 *   @0x176b30 ldr r2, [r2]
 *   @0x176b34 b 0x188e28 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv>
 *   @0x176b38 ldr r2, [pc, #0x68]
 *   @0x176b3c add r2, pc, r2
 *   @0x176b40 add r3, r2, r3, lsl #2
 *   @0x176b44 ldr r5, [r3, #0x1c]
 *   @0x176b48 b 0x176b04 <_Z19GR_3D_Primitive_Endv+0x34>
 *   @0x176b4c ldr r3, [pc, #0x58]
 *   @0x176b50 ldr r3, [r4, r3]
 *   @0x176b54 ldr r0, [r3]
 *   @0x176b58 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x176b5c ldr r3, [pc, #0x3c]
 *   @0x176b60 mov r2, #36
 *   @0x176b64 mov r1, r0
 *   @0x176b68 mov r0, r5
 *   @0x176b6c ldr r5, [r4, r3]
 *   @0x176b70 ldr r3, [r5]
 *   @0x176b74 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x176b78 ldr r2, [pc, #0x24]
 *   @0x176b7c ldr r3, [r5]
 *   @0x176b80 ldr r1, [r4, r2]
 *   @0x176b84 add r2, r3, r3, lsl #3
 *   @0x176b88 pop {r4, r5, r6, lr}
 *   @0x176b8c lsl r2, r2, #2
 *   @0x176b90 b 0xb65bc <memcpy@plt>
 *   @0x176b94 eoreq r11, r7, r4, ror r1
 *   @0x176b98 .word 0xffffe674
 *   @0x176b9c .word 0xffffe49c
 *   @0x176ba0 .word 0xffffe670
 *   @0x176ba4 .word 0xffffe680
 *   @0x176ba8 andseq r6, lr, r0, ror #31
 *   @0x176bac .word 0xffffe678
 *
 * ══ §43/137 Graphics::DrawQuad(Texture*, float, float, float, float, float, float, float, float, unsigned int)  0x17f39c  size 224  56 条（0x17f39c..0x17f47c）
 * @func 0x17f39c 0x17f47c  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x44×2 / 0x38×2 / 0x3c×2 / 0x40×2 / 0x34×1 / 0x84×1 / 0x4×1 / 0x6c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f39c mov r12, r0
 *   @0x17f3a0 mov r0, #4
 *   @0x17f3a4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17f3a8 vpush {d8}
 *   @0x17f3ac mov r6, r1
 *   @0x17f3b0 vldr s16, [sp, #48]
 *   @0x17f3b4 mov r5, r2
 *   @0x17f3b8 mov r7, r3
 *   @0x17f3bc mov r1, r12
 *   @0x17f3c0 mov r3, #6
 *   @0x17f3c4 mov r2, #24
 *   @0x17f3c8 ldr r4, [sp, #0x44]
 *   @0x17f3cc ldr r9, [sp, #0x34]
 *   @0x17f3d0 ldr r8, [sp, #0x38]
 *   @0x17f3d4 ldr r11, [sp, #0x3c]
 *   @0x17f3d8 ldr r10, [sp, #0x40]
 *   @0x17f3dc bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17f3e0 mov r3, #0
 *   @0x17f3e4 vstr s16, [r0, #52]
 *   @0x17f3e8 vstr s16, [r0, #76]
 *   @0x17f3ec vstr s16, [r0, #100]
 *   @0x17f3f0 str r6, [r0]
 *   @0x17f3f4 str r4, [r0, #0x84]
 *   @0x17f3f8 str r5, [r0, #0x4]
 *   @0x17f3fc str r4, [r0, #0x6c]
 *   @0x17f400 str r7, [r0, #0x18]
 *   @0x17f404 str r4, [r0, #0x54]
 *   @0x17f408 str r5, [r0, #0x1c]
 *   @0x17f40c str r4, [r0, #0x3c]
 *   @0x17f410 str r7, [r0, #0x30]
 *   @0x17f414 str r4, [r0, #0x24]
 *   @0x17f418 str r4, [r0, #0xc]
 *   @0x17f41c str r7, [r0, #0x48]
 *   @0x17f420 str r6, [r0, #0x60]
 *   @0x17f424 str r6, [r0, #0x78]
 *   @0x17f428 str r5, [r0, #0x7c]
 *   @0x17f42c str r9, [r0, #0x10]
 *   @0x17f430 str r8, [r0, #0x14]
 *   @0x17f434 str r11, [r0, #0x28]
 *   @0x17f438 str r8, [r0, #0x2c]
 *   @0x17f43c str r11, [r0, #0x40]
 *   @0x17f440 str r10, [r0, #0x44]
 *   @0x17f444 str r11, [r0, #0x58]
 *   @0x17f448 str r10, [r0, #0x5c]
 *   @0x17f44c str r9, [r0, #0x70]
 *   @0x17f450 str r3, [r0, #0x80]
 *   @0x17f454 str r3, [r0, #0x68]
 *   @0x17f458 str r3, [r0, #0x50]
 *   @0x17f45c str r3, [r0, #0x38]
 *   @0x17f460 str r3, [r0, #0x20]
 *   @0x17f464 str r3, [r0, #0x8]
 *   @0x17f468 str r10, [r0, #0x74]
 *   @0x17f46c str r9, [r0, #0x88]
 *   @0x17f470 str r8, [r0, #0x8c]
 *   @0x17f474 vpop {d8}
 *   @0x17f478 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §44/137 CGCGeneration::IsRoot(YYObjectBase*)  0x1910e8  size 224  56 条（0x1910e8..0x1911c8）
 * @func 0x1910e8 0x1911c8  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<YYObjectBase*>(YYObjectBase*) / CGCGeneration::IsRoot(YYObjectBase*)+0xb0
 * 字段偏移 top8: 0x8×3 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1910e8 cmp r1, #0
 *   @0x1910ec mov r3, r0
 *   @0x1910f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1910f4 mov r0, r1
 *   @0x1910f8 beq 0x1911bc <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xd4>
 *   @0x1910fc ldr r5, [r3]
 *   @0x191100 bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_>
 *   @0x191104 ldr r1, [r5, #0x8]
 *   @0x191108 ldr r7, [r5, #0x10]
 *   @0x19110c bic r0, r0, #-2147483648
 *   @0x191110 and r3, r0, r1
 *   @0x191114 lsl r4, r3, #1
 *   @0x191118 add r2, r4, r3
 *   @0x19111c add r2, r7, r2, lsl #2
 *   @0x191120 ldr r2, [r2, #0x8]
 *   @0x191124 cmp r2, #0
 *   @0x191128 beq 0x1911c0 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xd8>
 *   @0x19112c cmp r0, r2
 *   @0x191130 beq 0x1911a8 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xc0>
 *   @0x191134 ldr r8, [r5]
 *   @0x191138 and r2, r1, r2
 *   @0x19113c add r12, r3, r8
 *   @0x191140 rsb r2, r2, r12
 *   @0x191144 tst r2, r1
 *   @0x191148 bmi 0x191198 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xb0>
 *   @0x19114c mov r12, #0
 *   @0x191150 b 0x191164 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0x7c>
 *   @0x191154 cmp r0, r2
 *   @0x191158 beq 0x1911a0 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xb8>
 *   @0x19115c cmp r5, r12
 *   @0x191160 blt 0x191198 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xb0>
 *   @0x191164 add r3, r3, #1
 *   @0x191168 add r12, r12, #1
 *   @0x19116c and r3, r1, r3
 *   @0x191170 add r6, r3, r8
 *   @0x191174 lsl r4, r3, #1
 *   @0x191178 add r2, r4, r3
 *   @0x19117c add r2, r7, r2, lsl #2
 *   @0x191180 ldr r2, [r2, #0x8]
 *   @0x191184 and r5, r1, r2
 *   @0x191188 cmp r2, #0
 *   @0x19118c rsb r5, r5, r6
 *   @0x191190 and r5, r5, r1
 *   @0x191194 bne 0x191154 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0x6c>
 *   @0x191198 mov r0, #0
 *   @0x19119c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1911a0 cmn r3, #1
 *   @0x1911a4 beq 0x191198 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xb0>
 *   @0x1911a8 add r0, r4, r3
 *   @0x1911ac add r0, r7, r0, lsl #2
 *   @0x1911b0 adds r0, r0, #4
 *   @0x1911b4 movne r0, #1
 *   @0x1911b8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1911bc pop {r4, r5, r6, r7, r8, pc}
 *   @0x1911c0 mov r0, r2
 *   @0x1911c4 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §45/137 String_Replace_Hash(char*)  0x212da8  size 224  56 条（0x212da8..0x212e88）
 * @func 0x212da8 0x212e88  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char / utf8_add_char / utf8_strlen
 * 字段偏移 top8: 0x4×3 / 0xc4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x212da8 subs r3, r0, #0
 *   @0x212dac push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x212db0 sub sp, sp, #12
 *   @0x212db4 beq 0x212e78 <_Z19String_Replace_HashPc+0xd0>
 *   @0x212db8 ldr r2, [pc, #0xc4]
 *   @0x212dbc ldr r2, [pc, r2]
 *   @0x212dc0 ldrb r6, [r2]
 *   @0x212dc4 cmp r6, #0
 *   @0x212dc8 bne 0x212e6c <_Z19String_Replace_HashPc+0xc4>
 *   @0x212dcc str r3, [sp]
 *   @0x212dd0 mov r5, r6
 *   @0x212dd4 str r3, [sp, #0x4]
 *   @0x212dd8 add r8, sp, #4
 *   @0x212ddc mov r9, #10
 *   @0x212de0 b 0x212e20 <_Z19String_Replace_HashPc+0x78>
 *   @0x212de4 cmp r5, #0
 *   @0x212de8 movle r3, #0
 *   @0x212dec movgt r3, #1
 *   @0x212df0 cmp r6, #92
 *   @0x212df4 mov r6, r4
 *   @0x212df8 movne r3, #0
 *   @0x212dfc cmp r3, #0
 *   @0x212e00 ldr r3, [sp, #0x4]
 *   @0x212e04 addeq r5, r5, #1
 *   @0x212e08 moveq r6, r4
 *   @0x212e0c addeq r2, r3, #1
 *   @0x212e10 streq r2, [sp, #0x4]
 *   @0x212e14 strbne r4, [r3, #-0x1]
 *   @0x212e18 strbeq r9, [r3]
 *   @0x212e1c ldr r3, [sp]
 *   @0x212e20 ldrb r3, [r3]
 *   @0x212e24 mov r0, sp
 *   @0x212e28 cmp r3, #0
 *   @0x212e2c beq 0x212e58 <_Z19String_Replace_HashPc+0xb0>
 *   @0x212e30 bl 0x10fb38 <utf8_extract_char>
 *   @0x212e34 mov r4, r0
 *   @0x212e38 cmp r4, #35
 *   @0x212e3c mov r1, r0
 *   @0x212e40 mov r0, r8
 *   @0x212e44 beq 0x212de4 <_Z19String_Replace_HashPc+0x3c>
 *   @0x212e48 bl 0x10fe28 <utf8_add_char>
 *   @0x212e4c add r5, r5, #1
 *   @0x212e50 mov r6, r4
 *   @0x212e54 b 0x212e1c <_Z19String_Replace_HashPc+0x74>
 *   @0x212e58 ldr r2, [sp, #0x4]
 *   @0x212e5c mov r0, r5
 *   @0x212e60 strb r3, [r2]
 *   @0x212e64 add sp, sp, #12
 *   @0x212e68 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x212e6c bl 0x110648 <utf8_strlen>
 *   @0x212e70 add sp, sp, #12
 *   @0x212e74 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x212e78 mov r0, r3
 *   @0x212e7c add sp, sp, #12
 *   @0x212e80 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x212e84 andseq r10, sp, r8, ror #22
 *
 * ══ §46/137 F_JS_Object_isSealed(RValue&, CInstance*, CInstance*, int, RValue*)  0x2506ec  size 224  56 条（0x2506ec..0x2507cc）
 * @func 0x2506ec 0x2507cc  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowTypeError(char const*) / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / YYObject_PropertyNameIterator::Next(RValue*) / YYObjectBase::IsExtensible()
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x68×1 / 0xac×1 / 0x20×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2506ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2506f0 cmp r3, #0
 *   @0x2506f4 sub sp, sp, #68
 *   @0x2506f8 mov r10, r0
 *   @0x2506fc ldr r6, [sp, #0x68]
 *   @0x250700 beq 0x250714 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x250704 ldr r3, [r6, #0xc]
 *   @0x250708 bic r3, r3, #-16777216
 *   @0x25070c cmp r3, #6
 *   @0x250710 beq 0x250728 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x250714 ldr r0, [pc, #0xac]
 *   @0x250718 add r0, pc, r0
 *   @0x25071c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x250720 add sp, sp, #68
 *   @0x250724 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x250728 ldr r4, [r6]
 *   @0x25072c add r5, sp, #36
 *   @0x250730 mov r3, #13
 *   @0x250734 mov r2, #1
 *   @0x250738 mov r0, r5
 *   @0x25073c str r3, [r10, #0xc]
 *   @0x250740 mov r1, r4
 *   @0x250744 add r8, sp, #4
 *   @0x250748 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x25074c mov r9, #5
 *   @0x250750 add r7, sp, #20
 *   @0x250754 b 0x250774 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x250758 ldr r3, [sp, #0x4]
 *   @0x25075c str r9, [sp, #0x20]
 *   @0x250760 ldr r2, [r3]
 *   @0x250764 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x250768 ldr r3, [sp, #0x1c]
 *   @0x25076c tst r3, #2
 *   @0x250770 bne 0x2507b8 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x250774 mov r1, r8
 *   @0x250778 mov r0, r5
 *   @0x25077c bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x250780 mov r1, r7
 *   @0x250784 subs r11, r0, #0
 *   @0x250788 mov r0, r4
 *   @0x25078c bne 0x250758 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x250790 ldr r0, [r6]
 *   @0x250794 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x250798 cmp r0, #0
 *   @0x25079c streq r0, [r10]
 *   @0x2507a0 strne r11, [r10]
 *   @0x2507a4 moveq r3, #0
 *   @0x2507a8 strne r11, [r10, #0x4]
 *   @0x2507ac movteq r3, #0x3ff0
 *   @0x2507b0 streq r3, [r10, #0x4]
 *   @0x2507b4 b 0x250720 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2507b8 mov r3, #0
 *   @0x2507bc str r3, [r10]
 *   @0x2507c0 str r3, [r10, #0x4]
 *   @0x2507c4 b 0x250720 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2507c8 andseq r5, r0, r0, lsr r8
 *
 * ══ §47/137 JS_Array_prototype_sort(RValue&, CInstance*, CInstance*, int, RValue*)  0x251304  size 224  56 条（0x251304..0x2513e4）
 * @func 0x251304 0x2513e4  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Array_prototype_sort(RValue&, CInstance*, CInstance*, int, RValue*)+0x88 / JS_IsCallable(RValue&) / mysort(RValue*, int, int, RValue*, E_MYSORTVAL (*)(RValue*, RValue*, RValue*)) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x28×1 / 0x24×1 / 0x84×1 / 0x44×1 / 0x38×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x251304 ldr r2, [r1, #0x4]
 *   @0x251308 push {r4, r5, r6, r7, r8, lr}
 *   @0x25130c cmp r2, #0
 *   @0x251310 sub sp, sp, #16
 *   @0x251314 mov r6, r1
 *   @0x251318 mov r7, r0
 *   @0x25131c ldr r5, [sp, #0x28]
 *   @0x251320 beq 0x2513b0 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x251324 add r0, r2, #16
 *   @0x251328 ldr r4, [r0]
 *   @0x25132c cmp r3, #0
 *   @0x251330 ldr r8, [r4, #0x24]
 *   @0x251334 ble 0x25138c <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x251338 mov r0, r5
 *   @0x25133c bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x251340 cmp r0, #0
 *   @0x251344 beq 0x25139c <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x251348 ldr r12, [pc, #0x84]
 *   @0x25134c ldr r12, [pc, r12]
 *   @0x251350 ldr r0, [r4, #0x4]
 *   @0x251354 sub r2, r8, #1
 *   @0x251358 str r12, [sp]
 *   @0x25135c mov r3, r5
 *   @0x251360 mov r1, #0
 *   @0x251364 bl 0x242f54 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E>
 *   @0x251368 cmn r0, #4
 *   @0x25136c beq 0x251384 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x251370 cmn r0, #5
 *   @0x251374 strne r6, [r7]
 *   @0x251378 movne r3, #6
 *   @0x25137c strne r3, [r7, #0xc]
 *   @0x251380 beq 0x2513c8 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x251384 add sp, sp, #16
 *   @0x251388 pop {r4, r5, r6, r7, r8, pc}
 *   @0x25138c ldr r12, [pc, #0x44]
 *   @0x251390 mov r5, #0
 *   @0x251394 ldr r12, [pc, r12]
 *   @0x251398 b 0x251350 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x25139c ldr r0, [pc, #0x38]
 *   @0x2513a0 add r0, pc, r0
 *   @0x2513a4 add sp, sp, #16
 *   @0x2513a8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x2513ac b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2513b0 mov r0, r1
 *   @0x2513b4 mov r1, #1
 *   @0x2513b8 str r3, [sp, #0xc]
 *   @0x2513bc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2513c0 ldr r3, [sp, #0xc]
 *   @0x2513c4 b 0x251328 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x2513c8 ldr r0, [pc, #0x10]
 *   @0x2513cc add r0, pc, r0
 *   @0x2513d0 b 0x2513a4 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x2513d4 andseq r0, r10, r0, lsl #9
 *   @0x2513d8 andseq r0, r10, r12, lsr r4
 *   @0x2513dc andseq r4, r0, r8, lsr #27
 *   @0x2513e0 ldrheq r4, [r0], -r12
 *
 * ══ §48/137 lh_table_delete_entry  0x280bc0  size 224  56 条（0x280bc0..0x280ca0）
 * @func 0x280bc0 0x280ca0  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lh_table_delete_entry+0xd0
 * 字段偏移 top8: 0x8×5 / 0x4×4 / 0xc×4 / 0x28×2 / 0x20×2 / 0x2c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280bc0 push {r3, r4, r5, lr}
 *   @0x280bc4 mov r4, r0
 *   @0x280bc8 ldr r3, [r0, #0x28]
 *   @0x280bcc rsb r2, r3, r1
 *   @0x280bd0 asrs r2, r2, #4
 *   @0x280bd4 bmi 0x280c98 <lh_table_delete_entry+0xd8>
 *   @0x280bd8 ldr r0, [r3, r2, lsl #4]
 *   @0x280bdc lsl r5, r2, #4
 *   @0x280be0 add r3, r3, r5
 *   @0x280be4 add r2, r0, #2
 *   @0x280be8 cmp r2, #1
 *   @0x280bec bls 0x280c90 <lh_table_delete_entry+0xd0>
 *   @0x280bf0 ldr r2, [r4, #0x2c]
 *   @0x280bf4 ldr r0, [r4, #0x4]
 *   @0x280bf8 cmp r2, #0
 *   @0x280bfc sub r0, r0, #1
 *   @0x280c00 str r0, [r4, #0x4]
 *   @0x280c04 beq 0x280c18 <lh_table_delete_entry+0x58>
 *   @0x280c08 mov r0, r1
 *   @0x280c0c blx r2
 *   @0x280c10 ldr r3, [r4, #0x28]
 *   @0x280c14 add r3, r3, r5
 *   @0x280c18 ldr r0, [r4, #0x24]
 *   @0x280c1c mvn r1, #1
 *   @0x280c20 mov r2, #0
 *   @0x280c24 str r1, [r3]
 *   @0x280c28 cmp r0, r3
 *   @0x280c2c str r2, [r3, #0x4]
 *   @0x280c30 ldr r1, [r4, #0x20]
 *   @0x280c34 beq 0x280c64 <lh_table_delete_entry+0xa4>
 *   @0x280c38 cmp r3, r1
 *   @0x280c3c beq 0x280c80 <lh_table_delete_entry+0xc0>
 *   @0x280c40 ldr r1, [r3, #0x8]
 *   @0x280c44 ldr r2, [r3, #0xc]
 *   @0x280c48 str r1, [r2, #0x8]
 *   @0x280c4c ldr r1, [r3, #0x8]
 *   @0x280c50 str r2, [r1, #0xc]
 *   @0x280c54 mov r0, #0
 *   @0x280c58 str r0, [r3, #0xc]
 *   @0x280c5c str r0, [r3, #0x8]
 *   @0x280c60 pop {r3, r4, r5, pc}
 *   @0x280c64 cmp r3, r1
 *   @0x280c68 streq r2, [r4, #0x24]
 *   @0x280c6c streq r2, [r4, #0x20]
 *   @0x280c70 ldrne r1, [r3, #0xc]
 *   @0x280c74 strne r2, [r1, #0x8]
 *   @0x280c78 strne r1, [r4, #0x24]
 *   @0x280c7c b 0x280c54 <lh_table_delete_entry+0x94>
 *   @0x280c80 ldr r1, [r3, #0x8]
 *   @0x280c84 str r2, [r1, #0xc]
 *   @0x280c88 str r1, [r4, #0x20]
 *   @0x280c8c b 0x280c54 <lh_table_delete_entry+0x94>
 *   @0x280c90 mvn r0, #0
 *   @0x280c94 pop {r3, r4, r5, pc}
 *   @0x280c98 mvn r0, #1
 *   @0x280c9c pop {r3, r4, r5, pc}
 *
 * ══ §49/137 yySocket::ReadDataStream(int)  0x2960b4  size 224  56 条（0x2960b4..0x296194）
 * @func 0x2960b4 0x296194  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::ReadDataStream(int)+0xc0×2 / yySocket::Read(void*, unsigned int, unsigned int) / yySocket::Peek() / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x50×4 / 0x54×4 / 0xb8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2960b4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2960b8 mov r5, r0
 *   @0x2960bc ldr r6, [r0, #0x50]
 *   @0x2960c0 sub sp, sp, #12
 *   @0x2960c4 mov r7, r1
 *   @0x2960c8 cmp r6, #0
 *   @0x2960cc beq 0x296184 <_ZN8yySocket14ReadDataStreamEi+0xd0>
 *   @0x2960d0 ldr r8, [pc, #0xb8]
 *   @0x2960d4 mov r9, #0
 *   @0x2960d8 ldr r4, [r0, #0x54]
 *   @0x2960dc add r8, pc, r8
 *   @0x2960e0 b 0x296118 <_ZN8yySocket14ReadDataStreamEi+0x64>
 *   @0x2960e4 cmp r7, r4
 *   @0x2960e8 movlt r2, r7
 *   @0x2960ec movge r2, r4
 *   @0x2960f0 mov r0, r5
 *   @0x2960f4 mov r1, r6
 *   @0x2960f8 mov r3, #0
 *   @0x2960fc bl 0x2952dc <_ZN8yySocket4ReadEPvjj>
 *   @0x296100 cmp r0, #0
 *   @0x296104 rsb r4, r0, r4
 *   @0x296108 ble 0x296174 <_ZN8yySocket14ReadDataStreamEi+0xc0>
 *   @0x29610c cmp r0, r7
 *   @0x296110 add r6, r6, r0
 *   @0x296114 beq 0x296174 <_ZN8yySocket14ReadDataStreamEi+0xc0>
 *   @0x296118 mov r0, r5
 *   @0x29611c bl 0x295438 <_ZN8yySocket4PeekEv>
 *   @0x296120 cmp r0, #0
 *   @0x296124 ble 0x296174 <_ZN8yySocket14ReadDataStreamEi+0xc0>
 *   @0x296128 cmp r4, r0
 *   @0x29612c bge 0x2960e4 <_ZN8yySocket14ReadDataStreamEi+0x30>
 *   @0x296130 rsb r1, r4, r0
 *   @0x296134 ldr r4, [r5, #0x50]
 *   @0x296138 ldr r3, [r5, #0x54]
 *   @0x29613c add r1, r1, #16384
 *   @0x296140 str r9, [sp]
 *   @0x296144 mov r2, r8
 *   @0x296148 add r1, r1, r3
 *   @0x29614c mov r0, r4
 *   @0x296150 mov r3, #74
 *   @0x296154 str r1, [r5, #0x54]
 *   @0x296158 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x29615c ldr r3, [r5, #0x54]
 *   @0x296160 rsb r4, r4, r6
 *   @0x296164 add r6, r0, r4
 *   @0x296168 str r0, [r5, #0x50]
 *   @0x29616c rsb r4, r4, r3
 *   @0x296170 b 0x2960e4 <_ZN8yySocket14ReadDataStreamEi+0x30>
 *   @0x296174 ldr r0, [r5, #0x50]
 *   @0x296178 rsb r0, r0, r6
 *   @0x29617c add sp, sp, #12
 *   @0x296180 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x296184 mov r0, r6
 *   @0x296188 add sp, sp, #12
 *   @0x29618c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x296190 andeq r10, r9, r4, asr pc
 *
 * ══ §50/137 F_NETWORK_Send_Raw(RValue&, CInstance*, CInstance*, int, RValue*)  0x2984f0  size 224  56 条（0x2984f0..0x2985d0）
 * @func 0x2984f0 0x2985d0  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / GetIBuffer(int) / yySocket::Write(void*, unsigned int)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0xd0×1 / 0x18×1 / 0x60×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2984f0 ldr r3, [pc, #0xd0]
 *   @0x2984f4 mov r1, #0
 *   @0x2984f8 push {r4, r5, r6, r7, r8, lr}
 *   @0x2984fc ldr r3, [pc, r3]
 *   @0x298500 str r1, [r0]
 *   @0x298504 mov r2, r1
 *   @0x298508 ldr r3, [r3]
 *   @0x29850c movt r2, #0xbff0
 *   @0x298510 mov r4, r0
 *   @0x298514 str r1, [r0, #0xc]
 *   @0x298518 sub r3, r3, #2
 *   @0x29851c str r2, [r0, #0x4]
 *   @0x298520 cmp r3, #2
 *   @0x298524 ldr r5, [sp, #0x18]
 *   @0x298528 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x29852c mov r0, r5
 *   @0x298530 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298534 mov r1, #1
 *   @0x298538 mov r6, r0
 *   @0x29853c mov r0, r5
 *   @0x298540 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298544 mov r1, #2
 *   @0x298548 mov r7, r0
 *   @0x29854c mov r0, r5
 *   @0x298550 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298554 cmp r6, #63
 *   @0x298558 mov r5, r0
 *   @0x29855c pophi {r4, r5, r6, r7, r8, pc}
 *   @0x298560 add r6, r6, r6, lsl #1
 *   @0x298564 ldr r3, [pc, #0x60]
 *   @0x298568 lsl r6, r6, #2
 *   @0x29856c ldr r3, [pc, r3]
 *   @0x298570 add r8, r3, r6
 *   @0x298574 ldrb r3, [r3, r6]
 *   @0x298578 cmp r3, #0
 *   @0x29857c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x298580 mov r0, r7
 *   @0x298584 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x298588 subs r3, r0, #0
 *   @0x29858c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x298590 ldr r0, [r8, #0x4]
 *   @0x298594 mov r2, r5
 *   @0x298598 ldr r1, [r3, #0xc]
 *   @0x29859c cmp r0, #0
 *   @0x2985a0 ldreq r3, [r8, #0x8]
 *   @0x2985a4 ldreq r0, [r3]
 *   @0x2985a8 bl 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x2985ac vmov s15, r0
 *   @0x2985b0 vcvt.f64.s32 d7, s15
 *   @0x2985b4 vmov r0, r1, d7
 *   @0x2985b8 vmov r2, s14
 *   @0x2985bc mov r3, r1
 *   @0x2985c0 stm r4, {r2, r3}
 *   @0x2985c4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2985c8 andseq r7, r5, r4, lsr #28
 *   @0x2985cc andseq r9, r5, r8, lsr r4
 *
 * ══ §51/137 anon_2a5478  0x2a5478  size 224  56 条（0x2a5478..0x2a5558）
 * @func 0x2a5478 0x2a5558  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3f6cb4 / 0x1235f0c / 0x3e3618
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5478 mvnsmi lr, sp, lsr #18
 *   @0x2a547c ldmdami r6!, {r2, r9, r10, lr}
 *   @0x2a5480 stcpl p5, c15, [r0, #-692]
 *   @0x2a5484 ldrbtmi r11, [r8], #-130
 *   @0x2a5488 .word 0xf50d6800
 *   @0x2a548c strlo r5, [r4], -r0, lsl #12
 *   @0x2a5490 eorsvs r6, r5, r5, lsl #16
 *   @0x2a5494 blhs 0x3f6cb4 <g_MP3UpdateVolume+0x19d8>
 *   @0x2a5498 ldm pc, {r0, r2, r3, r6, r11, r12, lr, pc} ^
 *   @0x2a549c cdpne p0, #0x0, c15, c3, c3, #0x0
 *   @0x2a54a0 ldrtmi r3, [r12], #-74
 *   @0x2a54a4 stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x2a54a8 vrshl.s8 d18, d0, d2
 *   @0x2a54ac bvs 0xb270b8 <b2_toiTime+0x3cdc14>
 *   @0x2a54b0 ble 0x1235f0c <b2_toiTime+0xadca68>
 *   @0x2a54b4 stmdavs r0!, {r1, r4, r6, r8, r9, r11, r12}
 *   @0x2a54b8 svclt #0x2842ba
 *   @0x2a54bc andpl pc, r0, #1325400064
 *   @0x2a54c0 .word 0xf7ff4641
 *   @0x2a54c4 stmdahs r0, {r0, r1, r4, r6, r8, r11, r12, sp, lr, pc}
 *   @0x2a54c8 stmdavs r0!, {r0, r2, r9, r11, r12, lr, pc}
 *   @0x2a54cc .word 0xff5cf7fe
 *   @0x2a54d0 eorvs r2, r3, r0, lsl #6
 *   @0x2a54d4 strmi lr, [r5], #-47
 *   @0x2a54d8 bvs 0x1b9f484 <b2_toiTime+0x1445fe0>
 *   @0x2a54dc andle r1, r1, r8, asr r12
 *   @0x2a54e0 stmdale r0, {r1, r3, r4, r7, r9, lr}
 *   @0x2a54e4 stmdavs r0!, {r0, r1, r4, r9, r10, lr}
 *   @0x2a54e8 .word 0xf7ff461a
 *   @0x2a54ec stmdahs r0, {r0, r1, r2, r3, r4, r5, r8, r11, r12, sp, lr, pc}
 *   @0x2a54f0 bvs 0x1b9c17c <b2_toiTime+0x1442cd8>
 *   @0x2a54f4 eorle r1, r0, r10, asr r12
 *   @0x2a54f8 rsbvs r1, r3, #110592
 *   @0x2a54fc bhs 0x9dd578 <b2_toiTime+0x2840d4>
 *   @0x2a5500 stcne p3, c13, [r3, #-100]!
 *   @0x2a5504 .word 0xf8533420
 *   @0x2a5508 adcmi r2, r3, #4, #22
 *   @0x2a550c blhs 0x3e3618 <error_g0017+0x3c2bc>
 *   @0x2a5510 ldrshhs sp, [r12], -r9
 *   @0x2a5514 bhs 0x49d560 <TimingData+0x3548>
 *   @0x2a5518 stmdavs r0!, {r0, r2, r3, r8, r11, r12, lr, pc}
 *   @0x2a551c .word 0xf0001d0a
 *   @0x2a5520 andhs pc, r8, r3, ror #19
 *   @0x2a5524 stmdavs r0!, {r0, r3, sp, lr, pc}
 *   @0x2a5528 .word 0xff2ef7fe
 *   @0x2a552c .word 0xf6114620
 *   @0x2a5530 andhs lr, r0, r6, lsl r8
 *   @0x2a5534 .word 0xf04fe001
 *   @0x2a5538 .word 0xf50d30ff
 *   @0x2a553c movwlo r5, #0x4300
 *   @0x2a5540 ldmdavs r3!, {r1, r3, r4, r11, sp, lr}
 *   @0x2a5544 mulle r1, r10, r2
 *   @0x2a5548 stmda r4, {r0, r4, r9, r10, r12, sp, lr, pc} ^
 *   @0x2a554c stcpl p5, c15, [r0, #-52]
 *   @0x2a5550 pop {r1, r12, sp, pc}
 *   @0x2a5554 svclt #0x81f0
 *
 * ══ §52/137 b2PolygonShape::ComputeAABB(b2AABB*, b2Transform const&, int) const  0x2c58b0  size 224  56 条（0x2c58b0..0x2c5990）
 * @func 0x2c58b0 0x2c5990  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PolygonShape::ComputeAABB(b2AABB*, b2Transform const&, int) const+0xd4
 * 字段偏移 top8: 0x94×1
 * VFP 指令 45 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c58b0 vldr s12, [r0, #24]
 *   @0x2c58b4 vldr s8, [r2, #12]
 *   @0x2c58b8 vldr s7, [r2, #8]
 *   @0x2c58bc vmul.f32 s13, s8, s12
 *   @0x2c58c0 vldr s15, [r0, #20]
 *   @0x2c58c4 ldr r12, [r0, #0x94]
 *   @0x2c58c8 vldr s6, [r2]
 *   @0x2c58cc vldr s5, [r2, #4]
 *   @0x2c58d0 cmp r12, #1
 *   @0x2c58d4 vmul.f32 s12, s7, s12
 *   @0x2c58d8 vmla.f32 s13, s15, s7
 *   @0x2c58dc vnmls.f32 s12, s8, s15
 *   @0x2c58e0 vadd.f32 s13, s13, s5
 *   @0x2c58e4 vadd.f32 s12, s12, s6
 *   @0x2c58e8 ble 0x2c5984 <_ZNK14b2PolygonShape11ComputeAABBEP6b2AABBRK11b2Transformi+0xd4>
 *   @0x2c58ec add r3, r0, #28
 *   @0x2c58f0 mov r2, #1
 *   @0x2c58f4 vmov.f32 s10, s12
 *   @0x2c58f8 vmov.f32 s11, s13
 *   @0x2c58fc vldr s15, [r3, #4]
 *   @0x2c5900 vldr s9, [r3]
 *   @0x2c5904 add r2, r2, #1
 *   @0x2c5908 add r3, r3, #8
 *   @0x2c590c vmul.f32 s14, s7, s15
 *   @0x2c5910 vmul.f32 s15, s8, s15
 *   @0x2c5914 vnmls.f32 s14, s8, s9
 *   @0x2c5918 vmla.f32 s15, s7, s9
 *   @0x2c591c vadd.f32 s14, s6, s14
 *   @0x2c5920 vadd.f32 s15, s5, s15
 *   @0x2c5924 vcmpe.f32 s14, s12
 *   @0x2c5928 vmrs APSR_nzcv, fpscr
 *   @0x2c592c vcmpe.f32 s15, s13
 *   @0x2c5930 vmovle.f32 s12, s14
 *   @0x2c5934 vmrs APSR_nzcv, fpscr
 *   @0x2c5938 vcmpe.f32 s14, s10
 *   @0x2c593c vmovle.f32 s13, s15
 *   @0x2c5940 vmrs APSR_nzcv, fpscr
 *   @0x2c5944 vcmpe.f32 s15, s11
 *   @0x2c5948 vmovpl.f32 s10, s14
 *   @0x2c594c vmrs APSR_nzcv, fpscr
 *   @0x2c5950 vmovpl.f32 s11, s15
 *   @0x2c5954 cmp r2, r12
 *   @0x2c5958 bne 0x2c58fc <_ZNK14b2PolygonShape11ComputeAABBEP6b2AABBRK11b2Transformi+0x4c>
 *   @0x2c595c vldr s15, [r0, #8]
 *   @0x2c5960 vsub.f32 s12, s12, s15
 *   @0x2c5964 vsub.f32 s13, s13, s15
 *   @0x2c5968 vstr s12, [r1]
 *   @0x2c596c vadd.f32 s10, s15, s10
 *   @0x2c5970 vstr s13, [r1, #4]
 *   @0x2c5974 vadd.f32 s11, s15, s11
 *   @0x2c5978 vstr s10, [r1, #8]
 *   @0x2c597c vstr s11, [r1, #12]
 *   @0x2c5980 bx lr
 *   @0x2c5984 vmov.f32 s10, s12
 *   @0x2c5988 vmov.f32 s11, s13
 *   @0x2c598c b 0x2c595c <_ZNK14b2PolygonShape11ComputeAABBEP6b2AABBRK11b2Transformi+0xac>
 *
 * ══ §53/137 b2Mat33::Solve33(b2Vec3 const&) const  0x2c6808  size 224  56 条（0x2c6808..0x2c68e8）
 * @func 0x2c6808 0x2c68e8  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 54 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6808 vldr s2, [r1, #32]
 *   @0x2c680c vldr s7, [r1, #12]
 *   @0x2c6810 vmul.f32 s12, s2, s7
 *   @0x2c6814 vldr s1, [r1, #20]
 *   @0x2c6818 vldr s3, [r1, #24]
 *   @0x2c681c vldr s6, [r1, #28]
 *   @0x2c6820 vldr s4, [r1, #16]
 *   @0x2c6824 vpush {d8, d9}
 *   @0x2c6828 vldr s18, [r1, #4]
 *   @0x2c682c vldr s16, [r1]
 *   @0x2c6830 vldr s0, [r1, #8]
 *   @0x2c6834 vldr s9, [r2]
 *   @0x2c6838 vldr s11, [r2, #8]
 *   @0x2c683c vldr s10, [r2, #4]
 *   @0x2c6840 mov r3, r0
 *   @0x2c6844 vnmls.f32 s12, s1, s3
 *   @0x2c6848 vmul.f32 s5, s1, s6
 *   @0x2c684c vnmls.f32 s5, s4, s2
 *   @0x2c6850 vmul.f32 s15, s12, s18
 *   @0x2c6854 vmul.f32 s8, s4, s3
 *   @0x2c6858 vmla.f32 s15, s5, s16
 *   @0x2c685c vnmls.f32 s8, s6, s7
 *   @0x2c6860 vmla.f32 s15, s8, s0
 *   @0x2c6864 vcmp.f32 s15, #0
 *   @0x2c6868 vmrs APSR_nzcv, fpscr
 *   @0x2c686c vmovne.f32 s14, #1.000000e+00
 *   @0x2c6870 vmul.f32 s13, s2, s9
 *   @0x2c6874 vdivne.f32 s15, s14, s15
 *   @0x2c6878 vmul.f32 s14, s7, s11
 *   @0x2c687c vnmls.f32 s13, s3, s11
 *   @0x2c6880 vnmls.f32 s14, s1, s9
 *   @0x2c6884 vmul.f32 s17, s6, s11
 *   @0x2c6888 vmul.f32 s1, s1, s10
 *   @0x2c688c vnmls.f32 s17, s2, s10
 *   @0x2c6890 vnmls.f32 s1, s4, s11
 *   @0x2c6894 vmul.f32 s13, s18, s13
 *   @0x2c6898 vmul.f32 s14, s18, s14
 *   @0x2c689c vmul.f32 s12, s12, s10
 *   @0x2c68a0 vmul.f32 s3, s3, s10
 *   @0x2c68a4 vmul.f32 s4, s4, s9
 *   @0x2c68a8 vmla.f32 s13, s16, s17
 *   @0x2c68ac vmla.f32 s14, s16, s1
 *   @0x2c68b0 vpop {d8, d9}
 *   @0x2c68b4 vmla.f32 s12, s5, s9
 *   @0x2c68b8 vnmls.f32 s3, s6, s9
 *   @0x2c68bc vnmls.f32 s4, s7, s10
 *   @0x2c68c0 vmla.f32 s12, s8, s11
 *   @0x2c68c4 vmla.f32 s13, s0, s3
 *   @0x2c68c8 vmla.f32 s14, s0, s4
 *   @0x2c68cc vmul.f32 s12, s15, s12
 *   @0x2c68d0 vmul.f32 s13, s15, s13
 *   @0x2c68d4 vstr s12, [r3]
 *   @0x2c68d8 vmul.f32 s15, s15, s14
 *   @0x2c68dc vstr s13, [r3, #4]
 *   @0x2c68e0 vstr s15, [r3, #8]
 *   @0x2c68e4 bx lr
 *
 * ══ §54/137 b2CollideCircles(b2Manifold*, b2CircleShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)  0x2dc9f0  size 224  56 条（0x2dc9f0..0x2dcad0）
 * @func 0x2dc9f0 0x2dcad0  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×2 / 0xc×1 / 0x38×1 / 0x28×1 / 0x2c×1 / 0x10×1
 * VFP 指令 34 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc9f0 push {r4, r5, r6}
 *   @0x2dc9f4 vldr s7, [r2, #12]
 *   @0x2dc9f8 vldr s14, [r1, #16]
 *   @0x2dc9fc vldr s6, [r3, #16]
 *   @0x2dca00 ldr r12, [sp, #0xc]
 *   @0x2dca04 vmul.f32 s11, s7, s14
 *   @0x2dca08 vldr s9, [r12, #12]
 *   @0x2dca0c vldr s5, [r2, #8]
 *   @0x2dca10 vldr s13, [r12, #8]
 *   @0x2dca14 vldr s8, [r1, #12]
 *   @0x2dca18 vldr s10, [r3, #12]
 *   @0x2dca1c vldr s0, [r2, #4]
 *   @0x2dca20 vldr s15, [r12, #4]
 *   @0x2dca24 vldr s1, [r12]
 *   @0x2dca28 vldr s2, [r2]
 *   @0x2dca2c vldr s3, [r1, #8]
 *   @0x2dca30 vldr s4, [r3, #8]
 *   @0x2dca34 mov r12, #0
 *   @0x2dca38 mov r2, r0
 *   @0x2dca3c str r12, [r0, #0x3c]
 *   @0x2dca40 vmul.f32 s12, s9, s6
 *   @0x2dca44 vmul.f32 s14, s5, s14
 *   @0x2dca48 vmla.f32 s12, s10, s13
 *   @0x2dca4c vmla.f32 s11, s8, s5
 *   @0x2dca50 vmul.f32 s13, s13, s6
 *   @0x2dca54 vnmls.f32 s14, s7, s8
 *   @0x2dca58 vnmls.f32 s13, s9, s10
 *   @0x2dca5c vadd.f32 s15, s12, s15
 *   @0x2dca60 vadd.f32 s11, s11, s0
 *   @0x2dca64 vsub.f32 s15, s15, s11
 *   @0x2dca68 vadd.f32 s13, s13, s1
 *   @0x2dca6c vadd.f32 s14, s14, s2
 *   @0x2dca70 vmul.f32 s15, s15, s15
 *   @0x2dca74 vsub.f32 s14, s13, s14
 *   @0x2dca78 vadd.f32 s12, s3, s4
 *   @0x2dca7c vmla.f32 s15, s14, s14
 *   @0x2dca80 vmul.f32 s12, s12, s12
 *   @0x2dca84 vcmpe.f32 s12, s15
 *   @0x2dca88 vmrs APSR_nzcv, fpscr
 *   @0x2dca8c bmi 0x2dcac8 <_Z16b2CollideCirclesP10b2ManifoldPK13b2CircleShapeRK11b2TransformS3_S6_+0xd8>
 *   @0x2dca90 add r1, r1, #12
 *   @0x2dca94 str r12, [r0, #0x38]
 *   @0x2dca98 add r4, r0, #48
 *   @0x2dca9c add r3, r3, #12
 *   @0x2dcaa0 ldm r1, {r0, r1}
 *   @0x2dcaa4 mov r5, #0
 *   @0x2dcaa8 mov r6, #1
 *   @0x2dcaac stm r4, {r0, r1}
 *   @0x2dcab0 str r5, [r2, #0x28]
 *   @0x2dcab4 str r5, [r2, #0x2c]
 *   @0x2dcab8 ldm r3, {r0, r1}
 *   @0x2dcabc str r6, [r2, #0x3c]
 *   @0x2dcac0 str r12, [r2, #0x10]
 *   @0x2dcac4 stm r2, {r0, r1}
 *   @0x2dcac8 pop {r4, r5, r6}
 *   @0x2dcacc bx lr
 *
 * ══ §55/137 CSkeletonInstance::ImageIndex(int)  0xbe30c  size 220  55 条（0xbe30c..0xbe3e8）
 * @func 0xbe30c 0xbe3e8  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::ImageIndex(int)+0xa4×2 / CTimingSource::GetFPS()
 * 字段偏移 top8: 0xc×3 / 0x28×2 / 0x10×2 / 0x2×2 / 0x90×1 / 0x80×1 / 0x24×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe30c push {r3, r4, r5, lr}
 *   @0xbe310 subs r4, r1, #0
 *   @0xbe314 mov r5, r0
 *   @0xbe318 blt 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4>
 *   @0xbe31c ldr r3, [r0, #0x28]
 *   @0xbe320 cmp r3, #0
 *   @0xbe324 beq 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4>
 *   @0xbe328 ldr r2, [r3, #0xc]
 *   @0xbe32c cmp r4, r2
 *   @0xbe330 bge 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4>
 *   @0xbe334 ldr r3, [r3, #0x10]
 *   @0xbe338 ldr r3, [r3, r4, lsl #2]
 *   @0xbe33c cmp r3, #0
 *   @0xbe340 beq 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4>
 *   @0xbe344 ldr r2, [pc, #0x90]
 *   @0xbe348 ldr r2, [pc, r2]
 *   @0xbe34c ldrb r2, [r2]
 *   @0xbe350 cmp r2, #0
 *   @0xbe354 bne 0xbe3b8 <_ZN17CSkeletonInstance10ImageIndexEi+0xac>
 *   @0xbe358 ldr r2, [pc, #0x80]
 *   @0xbe35c ldr r2, [pc, r2]
 *   @0xbe360 ldr r2, [r2]
 *   @0xbe364 cmp r2, #0
 *   @0xbe368 beq 0xbe3d4 <_ZN17CSkeletonInstance10ImageIndexEi+0xc8>
 *   @0xbe36c ldr r0, [r2, #0xc]
 *   @0xbe370 cmp r0, #0
 *   @0xbe374 ble 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4>
 *   @0xbe378 ldr r3, [r5, #0x28]
 *   @0xbe37c vmov s14, r0
 *   @0xbe380 vcvt.f32.s32 s15, s14
 *   @0xbe384 ldr r3, [r3, #0x10]
 *   @0xbe388 ldr r3, [r3, r4, lsl #2]
 *   @0xbe38c ldr r2, [r3, #0xc]
 *   @0xbe390 vldr s13, [r3, #24]
 *   @0xbe394 vldr s14, [r2, #4]
 *   @0xbe398 vmul.f32 s13, s15, s13
 *   @0xbe39c pop {r3, r4, r5, lr}
 *   @0xbe3a0 vmul.f32 s14, s15, s14
 *   @0xbe3a4 vmov r0, s13
 *   @0xbe3a8 vmov r1, s14
 *   @0xbe3ac b 0x1e62fc <_Z5fwrapff>
 *   @0xbe3b0 mov r0, #0
 *   @0xbe3b4 pop {r3, r4, r5, pc}
 *   @0xbe3b8 ldr r0, [pc, #0x24]
 *   @0xbe3bc ldr r0, [pc, r0]
 *   @0xbe3c0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0xbe3c4 vmov d7, r0, r1
 *   @0xbe3c8 vcvt.s32.f64 s15, d7
 *   @0xbe3cc vmov r0, s15
 *   @0xbe3d0 b 0xbe370 <_ZN17CSkeletonInstance10ImageIndexEi+0x64>
 *   @0xbe3d4 vmov.f32 s15, #3.000000e+01
 *   @0xbe3d8 b 0xbe38c <_ZN17CSkeletonInstance10ImageIndexEi+0x80>
 *   @0xbe3dc ldrsbteq pc, [r2], -r12
 *   @0xbe3e0 eorseq pc, r2, r12, asr #11
 *   @0xbe3e4 eorseq pc, r2, r0, ror r5
 *
 * ══ §56/137 CExtensionFunction::LoadFromExeStream(CStream*)  0xf4ab8  size 220  55 条（0xf4ab8..0xf4b94）
 * @func 0xf4ab8 0xf4b94  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×6 / MemoryManager::Free(void const*)×2 / CStream::ReadString(char const*&)×2 / CExtensionFunction::Clear()
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x14×2 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4ab8 push {r3, r4, r5, r6, r7, lr}
 *   @0xf4abc mov r6, r1
 *   @0xf4ac0 mov r7, r0
 *   @0xf4ac4 bl 0xf4998 <_ZN18CExtensionFunction5ClearEv>
 *   @0xf4ac8 mov r0, r6
 *   @0xf4acc bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf4ad0 cmp r0, #700
 *   @0xf4ad4 beq 0xf4ae0 <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream+0x28>
 *   @0xf4ad8 mov r0, #0
 *   @0xf4adc pop {r3, r4, r5, r6, r7, pc}
 *   @0xf4ae0 ldr r0, [r7, #0x4]
 *   @0xf4ae4 cmp r0, #0
 *   @0xf4ae8 beq 0xf4af8 <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream+0x40>
 *   @0xf4aec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf4af0 mov r3, #0
 *   @0xf4af4 str r3, [r7, #0x4]
 *   @0xf4af8 mov r0, r6
 *   @0xf4afc add r1, r7, #4
 *   @0xf4b00 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0xf4b04 ldr r0, [r7, #0x8]
 *   @0xf4b08 cmp r0, #0
 *   @0xf4b0c beq 0xf4b1c <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream+0x64>
 *   @0xf4b10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf4b14 mov r3, #0
 *   @0xf4b18 str r3, [r7, #0x8]
 *   @0xf4b1c add r1, r7, #8
 *   @0xf4b20 mov r0, r6
 *   @0xf4b24 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0xf4b28 mov r0, r6
 *   @0xf4b2c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf4b30 mov r5, r7
 *   @0xf4b34 mov r4, #16
 *   @0xf4b38 str r0, [r7, #0xc]
 *   @0xf4b3c mov r0, r6
 *   @0xf4b40 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf4b44 str r0, [r7, #0x10]
 *   @0xf4b48 mov r0, r6
 *   @0xf4b4c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf4b50 str r0, [r7, #0x14]
 *   @0xf4b54 mov r0, r6
 *   @0xf4b58 add r5, r5, #4
 *   @0xf4b5c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf4b60 subs r4, r4, #1
 *   @0xf4b64 str r0, [r5, #0x14]
 *   @0xf4b68 bne 0xf4b54 <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream+0x9c>
 *   @0xf4b6c mov r0, r6
 *   @0xf4b70 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf4b74 sub r3, r0, #1
 *   @0xf4b78 cmp r3, #1
 *   @0xf4b7c strls r0, [r7, #0x58]
 *   @0xf4b80 movhi r3, #2
 *   @0xf4b84 movls r0, #1
 *   @0xf4b88 strhi r3, [r7, #0x58]
 *   @0xf4b8c movhi r0, #1
 *   @0xf4b90 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §57/137 F_DsGridValueExists(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe370  size 220  55 条（0xfe370..0xfe44c）
 * @func 0xfe370 0xfe44c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridValueExists(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8 / CDS_Grid::Value_Exists(RValue&, int, int, int, int, RValue*)
 * 字段偏移 top8: 0x30×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe370 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfe374 sub sp, sp, #20
 *   @0xfe378 mov r1, #0
 *   @0xfe37c mov r8, r0
 *   @0xfe380 ldr r4, [sp, #0x30]
 *   @0xfe384 mov r0, r4
 *   @0xfe388 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe38c mov r1, #1
 *   @0xfe390 mov r5, r0
 *   @0xfe394 mov r0, r4
 *   @0xfe398 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe39c mov r1, #2
 *   @0xfe3a0 mov r7, r0
 *   @0xfe3a4 mov r0, r4
 *   @0xfe3a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe3ac mov r1, #3
 *   @0xfe3b0 mov r6, r0
 *   @0xfe3b4 mov r0, r4
 *   @0xfe3b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe3bc mov r1, #4
 *   @0xfe3c0 mov r9, r0
 *   @0xfe3c4 mov r0, r4
 *   @0xfe3c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe3cc cmp r5, #0
 *   @0xfe3d0 mov r2, r0
 *   @0xfe3d4 blt 0xfe428 <_Z19F_DsGridValueExistsR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe3d8 ldr r12, [pc, #0x60]
 *   @0xfe3dc ldr r12, [pc, r12]
 *   @0xfe3e0 ldr r3, [r12]
 *   @0xfe3e4 cmp r5, r3
 *   @0xfe3e8 bge 0xfe428 <_Z19F_DsGridValueExistsR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe3ec ldr r12, [pc, #0x50]
 *   @0xfe3f0 ldr r12, [pc, r12]
 *   @0xfe3f4 ldr r3, [r12, #0x4]
 *   @0xfe3f8 ldr r0, [r3, r5, lsl #2]
 *   @0xfe3fc cmp r0, #0
 *   @0xfe400 beq 0xfe428 <_Z19F_DsGridValueExistsR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe404 add r4, r4, #80
 *   @0xfe408 str r9, [sp]
 *   @0xfe40c stmib sp, {r2, r4}
 *   @0xfe410 mov r1, r8
 *   @0xfe414 mov r2, r7
 *   @0xfe418 mov r3, r6
 *   @0xfe41c bl 0x20478c <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_>
 *   @0xfe420 add sp, sp, #20
 *   @0xfe424 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfe428 ldr r0, [pc, #0x18]
 *   @0xfe42c mov r1, #0
 *   @0xfe430 add r0, pc, r0
 *   @0xfe434 add sp, sp, #20
 *   @0xfe438 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfe43c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe440 eoreq pc, lr, r8, lsr #21
 *   @0xfe444 mlaeq lr, r8, r10, pc
 *   @0xfe448 eoreq r9, r3, r12, asr #15
 *
 * ══ §58/137 F_DsGridValueX(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe44c  size 220  55 条（0xfe44c..0xfe528）
 * @func 0xfe44c 0xfe528  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridValueX(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8 / CDS_Grid::Value_X(RValue&, int, int, int, int, RValue*)
 * 字段偏移 top8: 0x30×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe44c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfe450 sub sp, sp, #20
 *   @0xfe454 mov r1, #0
 *   @0xfe458 mov r8, r0
 *   @0xfe45c ldr r4, [sp, #0x30]
 *   @0xfe460 mov r0, r4
 *   @0xfe464 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe468 mov r1, #1
 *   @0xfe46c mov r5, r0
 *   @0xfe470 mov r0, r4
 *   @0xfe474 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe478 mov r1, #2
 *   @0xfe47c mov r7, r0
 *   @0xfe480 mov r0, r4
 *   @0xfe484 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe488 mov r1, #3
 *   @0xfe48c mov r6, r0
 *   @0xfe490 mov r0, r4
 *   @0xfe494 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe498 mov r1, #4
 *   @0xfe49c mov r9, r0
 *   @0xfe4a0 mov r0, r4
 *   @0xfe4a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe4a8 cmp r5, #0
 *   @0xfe4ac mov r2, r0
 *   @0xfe4b0 blt 0xfe504 <_Z14F_DsGridValueXR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe4b4 ldr r12, [pc, #0x60]
 *   @0xfe4b8 ldr r12, [pc, r12]
 *   @0xfe4bc ldr r3, [r12]
 *   @0xfe4c0 cmp r5, r3
 *   @0xfe4c4 bge 0xfe504 <_Z14F_DsGridValueXR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe4c8 ldr r12, [pc, #0x50]
 *   @0xfe4cc ldr r12, [pc, r12]
 *   @0xfe4d0 ldr r3, [r12, #0x4]
 *   @0xfe4d4 ldr r0, [r3, r5, lsl #2]
 *   @0xfe4d8 cmp r0, #0
 *   @0xfe4dc beq 0xfe504 <_Z14F_DsGridValueXR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe4e0 add r4, r4, #80
 *   @0xfe4e4 str r9, [sp]
 *   @0xfe4e8 stmib sp, {r2, r4}
 *   @0xfe4ec mov r1, r8
 *   @0xfe4f0 mov r2, r7
 *   @0xfe4f4 mov r3, r6
 *   @0xfe4f8 bl 0x20489c <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_>
 *   @0xfe4fc add sp, sp, #20
 *   @0xfe500 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfe504 ldr r0, [pc, #0x18]
 *   @0xfe508 mov r1, #0
 *   @0xfe50c add r0, pc, r0
 *   @0xfe510 add sp, sp, #20
 *   @0xfe514 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfe518 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe51c eoreq pc, lr, r12, asr #19
 *   @0xfe520 .word 0x002ef9bc
 *   @0xfe524 .word 0x002396f0
 *
 * ══ §59/137 F_DsGridValueY(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe528  size 220  55 条（0xfe528..0xfe604）
 * @func 0xfe528 0xfe604  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridValueY(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8 / CDS_Grid::Value_Y(RValue&, int, int, int, int, RValue*)
 * 字段偏移 top8: 0x30×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe528 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfe52c sub sp, sp, #20
 *   @0xfe530 mov r1, #0
 *   @0xfe534 mov r8, r0
 *   @0xfe538 ldr r4, [sp, #0x30]
 *   @0xfe53c mov r0, r4
 *   @0xfe540 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe544 mov r1, #1
 *   @0xfe548 mov r5, r0
 *   @0xfe54c mov r0, r4
 *   @0xfe550 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe554 mov r1, #2
 *   @0xfe558 mov r7, r0
 *   @0xfe55c mov r0, r4
 *   @0xfe560 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe564 mov r1, #3
 *   @0xfe568 mov r6, r0
 *   @0xfe56c mov r0, r4
 *   @0xfe570 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe574 mov r1, #4
 *   @0xfe578 mov r9, r0
 *   @0xfe57c mov r0, r4
 *   @0xfe580 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe584 cmp r5, #0
 *   @0xfe588 mov r2, r0
 *   @0xfe58c blt 0xfe5e0 <_Z14F_DsGridValueYR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe590 ldr r12, [pc, #0x60]
 *   @0xfe594 ldr r12, [pc, r12]
 *   @0xfe598 ldr r3, [r12]
 *   @0xfe59c cmp r5, r3
 *   @0xfe5a0 bge 0xfe5e0 <_Z14F_DsGridValueYR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe5a4 ldr r12, [pc, #0x50]
 *   @0xfe5a8 ldr r12, [pc, r12]
 *   @0xfe5ac ldr r3, [r12, #0x4]
 *   @0xfe5b0 ldr r0, [r3, r5, lsl #2]
 *   @0xfe5b4 cmp r0, #0
 *   @0xfe5b8 beq 0xfe5e0 <_Z14F_DsGridValueYR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe5bc add r4, r4, #80
 *   @0xfe5c0 str r9, [sp]
 *   @0xfe5c4 stmib sp, {r2, r4}
 *   @0xfe5c8 mov r1, r8
 *   @0xfe5cc mov r2, r7
 *   @0xfe5d0 mov r3, r6
 *   @0xfe5d4 bl 0x2049b4 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_>
 *   @0xfe5d8 add sp, sp, #20
 *   @0xfe5dc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfe5e0 ldr r0, [pc, #0x18]
 *   @0xfe5e4 mov r1, #0
 *   @0xfe5e8 add r0, pc, r0
 *   @0xfe5ec add sp, sp, #20
 *   @0xfe5f0 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfe5f4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe5f8 .word 0x002ef8f0
 *   @0xfe5fc eoreq pc, lr, r0, ror #17
 *   @0xfe600 eoreq r9, r3, r4, lsl r6
 *
 * ══ §60/137 F_DsGridValueDiskExists(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe604  size 220  55 条（0xfe604..0xfe6e0）
 * @func 0xfe604 0xfe6e0  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridValueDiskExists(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8 / CDS_Grid::Value_Disk_Exists(RValue&, double, double, double, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe604 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe608 sub sp, sp, #24
 *   @0xfe60c mov r1, #0
 *   @0xfe610 mov r9, r0
 *   @0xfe614 ldr r8, [sp, #0x38]
 *   @0xfe618 mov r0, r8
 *   @0xfe61c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe620 mov r1, #1
 *   @0xfe624 mov r10, r0
 *   @0xfe628 mov r0, r8
 *   @0xfe62c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe630 mov r4, r0
 *   @0xfe634 mov r5, r1
 *   @0xfe638 mov r0, r8
 *   @0xfe63c mov r1, #2
 *   @0xfe640 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe644 mov r6, r0
 *   @0xfe648 mov r7, r1
 *   @0xfe64c mov r0, r8
 *   @0xfe650 mov r1, #3
 *   @0xfe654 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe658 cmp r10, #0
 *   @0xfe65c mov r2, r0
 *   @0xfe660 mov r3, r1
 *   @0xfe664 blt 0xfe6bc <_Z23F_DsGridValueDiskExistsR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe668 ldr r1, [pc, #0x64]
 *   @0xfe66c ldr r1, [pc, r1]
 *   @0xfe670 ldr r1, [r1]
 *   @0xfe674 cmp r10, r1
 *   @0xfe678 bge 0xfe6bc <_Z23F_DsGridValueDiskExistsR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe67c ldr r1, [pc, #0x54]
 *   @0xfe680 ldr r1, [pc, r1]
 *   @0xfe684 ldr r1, [r1, #0x4]
 *   @0xfe688 ldr r0, [r1, r10, lsl #2]
 *   @0xfe68c cmp r0, #0
 *   @0xfe690 beq 0xfe6bc <_Z23F_DsGridValueDiskExistsR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe694 strd r2, r3, [sp, #8]
 *   @0xfe698 add r8, r8, #64
 *   @0xfe69c strd r6, r7, [sp]
 *   @0xfe6a0 mov r1, r9
 *   @0xfe6a4 str r8, [sp, #0x10]
 *   @0xfe6a8 mov r2, r4
 *   @0xfe6ac mov r3, r5
 *   @0xfe6b0 bl 0x204acc <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_>
 *   @0xfe6b4 add sp, sp, #24
 *   @0xfe6b8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfe6bc ldr r0, [pc, #0x18]
 *   @0xfe6c0 mov r1, #0
 *   @0xfe6c4 add r0, pc, r0
 *   @0xfe6c8 add sp, sp, #24
 *   @0xfe6cc pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe6d0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe6d4 eoreq pc, lr, r8, lsl r8
 *   @0xfe6d8 eoreq pc, lr, r8, lsl #16
 *   @0xfe6dc eoreq r9, r3, r8, lsr r5
 *
 * ══ §61/137 F_DsGridValueDiskX(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe6e0  size 220  55 条（0xfe6e0..0xfe7bc）
 * @func 0xfe6e0 0xfe7bc  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridValueDiskX(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8 / CDS_Grid::Value_Disk_X(RValue&, double, double, double, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe6e0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe6e4 sub sp, sp, #24
 *   @0xfe6e8 mov r1, #0
 *   @0xfe6ec mov r9, r0
 *   @0xfe6f0 ldr r8, [sp, #0x38]
 *   @0xfe6f4 mov r0, r8
 *   @0xfe6f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe6fc mov r1, #1
 *   @0xfe700 mov r10, r0
 *   @0xfe704 mov r0, r8
 *   @0xfe708 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe70c mov r4, r0
 *   @0xfe710 mov r5, r1
 *   @0xfe714 mov r0, r8
 *   @0xfe718 mov r1, #2
 *   @0xfe71c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe720 mov r6, r0
 *   @0xfe724 mov r7, r1
 *   @0xfe728 mov r0, r8
 *   @0xfe72c mov r1, #3
 *   @0xfe730 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe734 cmp r10, #0
 *   @0xfe738 mov r2, r0
 *   @0xfe73c mov r3, r1
 *   @0xfe740 blt 0xfe798 <_Z18F_DsGridValueDiskXR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe744 ldr r1, [pc, #0x64]
 *   @0xfe748 ldr r1, [pc, r1]
 *   @0xfe74c ldr r1, [r1]
 *   @0xfe750 cmp r10, r1
 *   @0xfe754 bge 0xfe798 <_Z18F_DsGridValueDiskXR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe758 ldr r1, [pc, #0x54]
 *   @0xfe75c ldr r1, [pc, r1]
 *   @0xfe760 ldr r1, [r1, #0x4]
 *   @0xfe764 ldr r0, [r1, r10, lsl #2]
 *   @0xfe768 cmp r0, #0
 *   @0xfe76c beq 0xfe798 <_Z18F_DsGridValueDiskXR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe770 strd r2, r3, [sp, #8]
 *   @0xfe774 add r8, r8, #64
 *   @0xfe778 strd r6, r7, [sp]
 *   @0xfe77c mov r1, r9
 *   @0xfe780 str r8, [sp, #0x10]
 *   @0xfe784 mov r2, r4
 *   @0xfe788 mov r3, r5
 *   @0xfe78c bl 0x204c54 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_>
 *   @0xfe790 add sp, sp, #24
 *   @0xfe794 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfe798 ldr r0, [pc, #0x18]
 *   @0xfe79c mov r1, #0
 *   @0xfe7a0 add r0, pc, r0
 *   @0xfe7a4 add sp, sp, #24
 *   @0xfe7a8 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe7ac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe7b0 eoreq pc, lr, r12, lsr r7
 *   @0xfe7b4 eoreq pc, lr, r12, lsr #14
 *   @0xfe7b8 eoreq r9, r3, r12, asr r4
 *
 * ══ §62/137 F_DsGridValueDiskY(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe7bc  size 220  55 条（0xfe7bc..0xfe898）
 * @func 0xfe7bc 0xfe898  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridValueDiskY(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8 / CDS_Grid::Value_Disk_Y(RValue&, double, double, double, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe7bc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe7c0 sub sp, sp, #24
 *   @0xfe7c4 mov r1, #0
 *   @0xfe7c8 mov r9, r0
 *   @0xfe7cc ldr r8, [sp, #0x38]
 *   @0xfe7d0 mov r0, r8
 *   @0xfe7d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe7d8 mov r1, #1
 *   @0xfe7dc mov r10, r0
 *   @0xfe7e0 mov r0, r8
 *   @0xfe7e4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe7e8 mov r4, r0
 *   @0xfe7ec mov r5, r1
 *   @0xfe7f0 mov r0, r8
 *   @0xfe7f4 mov r1, #2
 *   @0xfe7f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe7fc mov r6, r0
 *   @0xfe800 mov r7, r1
 *   @0xfe804 mov r0, r8
 *   @0xfe808 mov r1, #3
 *   @0xfe80c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe810 cmp r10, #0
 *   @0xfe814 mov r2, r0
 *   @0xfe818 mov r3, r1
 *   @0xfe81c blt 0xfe874 <_Z18F_DsGridValueDiskYR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe820 ldr r1, [pc, #0x64]
 *   @0xfe824 ldr r1, [pc, r1]
 *   @0xfe828 ldr r1, [r1]
 *   @0xfe82c cmp r10, r1
 *   @0xfe830 bge 0xfe874 <_Z18F_DsGridValueDiskYR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe834 ldr r1, [pc, #0x54]
 *   @0xfe838 ldr r1, [pc, r1]
 *   @0xfe83c ldr r1, [r1, #0x4]
 *   @0xfe840 ldr r0, [r1, r10, lsl #2]
 *   @0xfe844 cmp r0, #0
 *   @0xfe848 beq 0xfe874 <_Z18F_DsGridValueDiskYR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xfe84c strd r2, r3, [sp, #8]
 *   @0xfe850 add r8, r8, #64
 *   @0xfe854 strd r6, r7, [sp]
 *   @0xfe858 mov r1, r9
 *   @0xfe85c str r8, [sp, #0x10]
 *   @0xfe860 mov r2, r4
 *   @0xfe864 mov r3, r5
 *   @0xfe868 bl 0x204de0 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_>
 *   @0xfe86c add sp, sp, #24
 *   @0xfe870 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfe874 ldr r0, [pc, #0x18]
 *   @0xfe878 mov r1, #0
 *   @0xfe87c add r0, pc, r0
 *   @0xfe880 add sp, sp, #24
 *   @0xfe884 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe888 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe88c eoreq pc, lr, r0, ror #12
 *   @0xfe890 eoreq pc, lr, r0, asr r6
 *   @0xfe894 eoreq r9, r3, r0, lsl #7
 *
 * ══ §63/137 F_DsMapRead(RValue&, CInstance*, CInstance*, int, RValue*)  0xffa10  size 220  55 条（0xffa10..0xffaec）
 * @func 0xffa10 0xffaec  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetString(RValue const*, int) / F_DsMapRead(RValue&, CInstance*, CInstance*, int, RValue*)+0x94 / CDS_Map::ReadFromString(char const*, bool) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x20×1 / 0x78×1 / 0x68×1 / 0x4×1 / 0x2×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xffa10 push {r4, r5, r6, r7, r8, lr}
 *   @0xffa14 sub sp, sp, #8
 *   @0xffa18 add r6, sp, #4
 *   @0xffa1c mov r7, r3
 *   @0xffa20 ldr r5, [sp, #0x20]
 *   @0xffa24 mov r0, r6
 *   @0xffa28 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xffa2c mov r1, #0
 *   @0xffa30 mov r0, r5
 *   @0xffa34 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xffa38 mov r1, #1
 *   @0xffa3c mov r4, r0
 *   @0xffa40 mov r0, r5
 *   @0xffa44 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xffa48 cmp r7, #3
 *   @0xffa4c movne r2, #0
 *   @0xffa50 mov r8, r0
 *   @0xffa54 beq 0xffac4 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xffa58 cmp r4, #0
 *   @0xffa5c blt 0xffaa4 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xffa60 ldr r3, [pc, #0x78]
 *   @0xffa64 ldr r3, [pc, r3]
 *   @0xffa68 ldr r3, [r3]
 *   @0xffa6c cmp r4, r3
 *   @0xffa70 bge 0xffaa4 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xffa74 ldr r3, [pc, #0x68]
 *   @0xffa78 ldr r3, [pc, r3]
 *   @0xffa7c ldr r3, [r3, #0x4]
 *   @0xffa80 ldr r0, [r3, r4, lsl #2]
 *   @0xffa84 cmp r0, #0
 *   @0xffa88 beq 0xffaa4 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xffa8c mov r1, r8
 *   @0xffa90 bl 0x20de08 <_ZN7CDS_Map14ReadFromStringEPKcb>
 *   @0xffa94 mov r0, r6
 *   @0xffa98 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xffa9c add sp, sp, #8
 *   @0xffaa0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xffaa4 ldr r0, [pc, #0x3c]
 *   @0xffaa8 mov r1, #0
 *   @0xffaac add r0, pc, r0
 *   @0xffab0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xffab4 mov r0, r6
 *   @0xffab8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xffabc add sp, sp, #8
 *   @0xffac0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xffac4 mov r0, r5
 *   @0xffac8 mov r1, #2
 *   @0xffacc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xffad0 cmp r0, #0
 *   @0xffad4 movle r2, #0
 *   @0xffad8 movgt r2, #1
 *   @0xffadc b 0xffa58 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xffae0 eoreq lr, lr, r4, lsl r2
 *   @0xffae4 eoreq sp, lr, r4, asr #29
 *   @0xffae8 eoreq r8, r3, r0, asr r1
 *
 * ══ §64/137 F_MpLinearPathObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x109d68  size 220  55 条（0x109d68..0x109e44）
 * @func 0x109d68 0x109e44  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int)×2 / Path_Exists(int) / Path_Data(int) / Motion_Linear_Path(CInstance*, CPath*, float, float, float, int, bool)
 * 字段偏移 top8: 0xc×2 / 0x38×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109d68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109d6c sub sp, sp, #20
 *   @0x109d70 mov r5, r0
 *   @0x109d74 mov r6, r1
 *   @0x109d78 ldr r4, [sp, #0x38]
 *   @0x109d7c mov r1, #0
 *   @0x109d80 mov r0, r4
 *   @0x109d84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109d88 mov r7, r0
 *   @0x109d8c bl 0x1a8008 <_Z11Path_Existsi>
 *   @0x109d90 subs r1, r0, #0
 *   @0x109d94 beq 0x109e2c <_Z20F_MpLinearPathObjectR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x109d98 mov r0, r7
 *   @0x109d9c mov r7, #0
 *   @0x109da0 str r7, [r5, #0xc]
 *   @0x109da4 bl 0x1a815c <_Z9Path_Datai>
 *   @0x109da8 mov r1, #1
 *   @0x109dac mov r10, r0
 *   @0x109db0 mov r0, r4
 *   @0x109db4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109db8 mov r1, #2
 *   @0x109dbc mov r9, r0
 *   @0x109dc0 mov r0, r4
 *   @0x109dc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109dc8 mov r1, #3
 *   @0x109dcc mov r8, r0
 *   @0x109dd0 mov r0, r4
 *   @0x109dd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109dd8 mov r1, #4
 *   @0x109ddc mov r11, r0
 *   @0x109de0 mov r0, r4
 *   @0x109de4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109de8 mov r3, r8
 *   @0x109dec mov r12, #1
 *   @0x109df0 str r11, [sp]
 *   @0x109df4 mov r1, r10
 *   @0x109df8 mov r2, r9
 *   @0x109dfc stmib sp, {r0, r12}
 *   @0x109e00 mov r0, r6
 *   @0x109e04 bl 0x19c9cc <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib>
 *   @0x109e08 cmp r0, #0
 *   @0x109e0c moveq r7, r0
 *   @0x109e10 movne r3, r7
 *   @0x109e14 moveq r3, r7
 *   @0x109e18 movtne r3, #0x3ff0
 *   @0x109e1c str r7, [r5]
 *   @0x109e20 str r3, [r5, #0x4]
 *   @0x109e24 add sp, sp, #20
 *   @0x109e28 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x109e2c ldr r0, [pc, #0xc]
 *   @0x109e30 add r0, pc, r0
 *   @0x109e34 add sp, sp, #20
 *   @0x109e38 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109e3c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x109e40 mlaeq r2, r12, r8, lr
 *
 * ══ §65/137 F_Point_In_Triangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x10c3e8  size 220  55 条（0x10c3e8..0x10c4c4）
 * @func 0x10c3e8 0x10c4c4  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / Point_In_Triangle(float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0xc×2 / 0x14×2 / 0x40×1 / 0x4×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c3e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10c3ec sub sp, sp, #28
 *   @0x10c3f0 mov r5, r0
 *   @0x10c3f4 mov r1, #0
 *   @0x10c3f8 ldr r4, [sp, #0x40]
 *   @0x10c3fc str r1, [r0, #0xc]
 *   @0x10c400 mov r0, r4
 *   @0x10c404 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c408 mov r1, #1
 *   @0x10c40c mov r6, r0
 *   @0x10c410 mov r0, r4
 *   @0x10c414 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c418 mov r1, #2
 *   @0x10c41c mov r9, r0
 *   @0x10c420 mov r0, r4
 *   @0x10c424 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c428 mov r1, #3
 *   @0x10c42c mov r8, r0
 *   @0x10c430 mov r0, r4
 *   @0x10c434 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c438 mov r1, #4
 *   @0x10c43c mov r7, r0
 *   @0x10c440 mov r0, r4
 *   @0x10c444 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c448 mov r1, #5
 *   @0x10c44c mov r3, r0
 *   @0x10c450 mov r0, r4
 *   @0x10c454 str r3, [sp, #0x14]
 *   @0x10c458 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c45c mov r1, #6
 *   @0x10c460 mov r11, r0
 *   @0x10c464 mov r0, r4
 *   @0x10c468 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c46c mov r1, #7
 *   @0x10c470 mov r10, r0
 *   @0x10c474 mov r0, r4
 *   @0x10c478 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c47c ldr r3, [sp, #0x14]
 *   @0x10c480 mov r1, r9
 *   @0x10c484 mov r2, r8
 *   @0x10c488 str r11, [sp, #0x4]
 *   @0x10c48c str r3, [sp]
 *   @0x10c490 mov r3, r7
 *   @0x10c494 str r10, [sp, #0x8]
 *   @0x10c498 str r0, [sp, #0xc]
 *   @0x10c49c mov r0, r6
 *   @0x10c4a0 bl 0x10c328 <_Z17Point_In_Triangleffffffff>
 *   @0x10c4a4 vmov s15, r0
 *   @0x10c4a8 vcvt.f64.u32 d7, s15
 *   @0x10c4ac vmov r0, r1, d7
 *   @0x10c4b0 vmov r2, s14
 *   @0x10c4b4 mov r3, r1
 *   @0x10c4b8 stm r5, {r2, r3}
 *   @0x10c4bc add sp, sp, #28
 *   @0x10c4c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §66/137 F_ArrayCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0x10fa08  size 220  55 条（0x10fa08..0x10fae4）
 * @func 0x10fa08 0x10fae4  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / ARRAY_RVAL_RValue(RValue const*, int) / SET_RValue_Array(RValue*, RValue*, int)
 * 字段偏移 top8: 0x18×1 / 0xb8×1 / 0xc×1 / 0x94×1 / 0x88×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10fa08 cmp r3, #5
 *   @0x10fa0c push {r4, r5, r6, r7, r8, lr}
 *   @0x10fa10 ldr r5, [sp, #0x18]
 *   @0x10fa14 beq 0x10fa28 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x10fa18 ldr r0, [pc, #0xb8]
 *   @0x10fa1c pop {r4, r5, r6, r7, r8, lr}
 *   @0x10fa20 add r0, pc, r0
 *   @0x10fa24 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10fa28 ldr r3, [r5, #0xc]
 *   @0x10fa2c bic r2, r3, #-16777216
 *   @0x10fa30 cmp r2, #2
 *   @0x10fa34 beq 0x10fa60 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x10fa38 cmp r3, #2
 *   @0x10fa3c beq 0x10fa50 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x10fa40 ldr r0, [pc, #0x94]
 *   @0x10fa44 pop {r4, r5, r6, r7, r8, lr}
 *   @0x10fa48 add r0, pc, r0
 *   @0x10fa4c b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10fa50 ldr r0, [pc, #0x88]
 *   @0x10fa54 pop {r4, r5, r6, r7, r8, lr}
 *   @0x10fa58 add r0, pc, r0
 *   @0x10fa5c b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10fa60 ldr r2, [r5, #0x2c]
 *   @0x10fa64 bic r2, r2, #-16777216
 *   @0x10fa68 cmp r2, #2
 *   @0x10fa6c bne 0x10fa38 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x10fa70 mov r1, #1
 *   @0x10fa74 mov r0, r5
 *   @0x10fa78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10fa7c mov r1, #3
 *   @0x10fa80 add r7, r5, #32
 *   @0x10fa84 mov r8, r0
 *   @0x10fa88 mov r0, r5
 *   @0x10fa8c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10fa90 mov r1, #4
 *   @0x10fa94 mov r6, r0
 *   @0x10fa98 mov r0, r5
 *   @0x10fa9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10faa0 subs r4, r0, #1
 *   @0x10faa4 popmi {r4, r5, r6, r7, r8, pc}
 *   @0x10faa8 add r1, r4, r6
 *   @0x10faac mov r0, r7
 *   @0x10fab0 bl 0xcede4 <_Z17ARRAY_RVAL_RValuePK6RValuei>
 *   @0x10fab4 add r2, r4, r8
 *   @0x10fab8 sub r4, r4, #1
 *   @0x10fabc subs r1, r0, #0
 *   @0x10fac0 mov r0, r5
 *   @0x10fac4 beq 0x10facc <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x10fac8 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x10facc cmn r4, #1
 *   @0x10fad0 bne 0x10faa8 <_Z11F_ArrayCopyR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x10fad4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x10fad8 eoreq r9, r2, r8, lsl #12
 *   @0x10fadc eoreq r9, r2, r0, lsl #12
 *   @0x10fae0 eoreq r9, r2, r12, lsl r6
 *
 * ══ §67/137 F_ExternalDefine6(RValue&, CInstance*, CInstance*, int, RValue*)  0x116474  size 220  55 条（0x116474..0x116550）
 * @func 0x116474 0x116550  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / 0xb65b0 / YYGetInt32(RValue const*, int) / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×2 / 0x70×1 / 0xc×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116474 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x116478 sub sp, sp, #84
 *   @0x11647c add r5, sp, #12
 *   @0x116480 mov r2, #68
 *   @0x116484 ldr r4, [sp, #0x70]
 *   @0x116488 mov r1, #0
 *   @0x11648c mov r7, r0
 *   @0x116490 mov r0, r5
 *   @0x116494 bl 0xb65b0 <memset@plt>
 *   @0x116498 mov r1, #0
 *   @0x11649c mov r0, r4
 *   @0x1164a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1164a4 mov r1, #1
 *   @0x1164a8 mov r9, r0
 *   @0x1164ac mov r0, r4
 *   @0x1164b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1164b4 mov r1, #2
 *   @0x1164b8 mov r8, r0
 *   @0x1164bc mov r0, r4
 *   @0x1164c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1164c4 add r3, sp, #8
 *   @0x1164c8 add r12, sp, #76
 *   @0x1164cc mov r2, #0
 *   @0x1164d0 subs r1, r0, #1
 *   @0x1164d4 rsbs lr, r1, #0
 *   @0x1164d8 adcs lr, lr, r1
 *   @0x1164dc str r2, [r3, #0x4]!
 *   @0x1164e0 cmp r3, r12
 *   @0x1164e4 mov r6, #0
 *   @0x1164e8 bne 0x1164dc <_Z17F_ExternalDefine6R6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x1164ec str r6, [r7, #0xc]
 *   @0x1164f0 mov r1, r8
 *   @0x1164f4 mov r2, r6
 *   @0x1164f8 mov r3, #6
 *   @0x1164fc mov r0, r9
 *   @0x116500 str r5, [sp]
 *   @0x116504 str lr, [sp, #0x4]
 *   @0x116508 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x11650c vmov.f64 d7, #-1.000000e+00
 *   @0x116510 vmov s13, r0
 *   @0x116514 vcvt.f64.s32 d6, s13
 *   @0x116518 vmov r0, r1, d6
 *   @0x11651c vmov r2, s12
 *   @0x116520 vcmp.f64 d6, d7
 *   @0x116524 vmrs APSR_nzcv, fpscr
 *   @0x116528 mov r3, r1
 *   @0x11652c stm r7, {r2, r3}
 *   @0x116530 bne 0x116544 <_Z17F_ExternalDefine6R6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x116534 ldr r0, [pc, #0x10]
 *   @0x116538 mov r1, r6
 *   @0x11653c add r0, pc, r0
 *   @0x116540 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x116544 add sp, sp, #84
 *   @0x116548 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x11654c eoreq r3, r2, r4, ror #2
 *
 * ══ §68/137 F_ExternalDefine7(RValue&, CInstance*, CInstance*, int, RValue*)  0x116550  size 220  55 条（0x116550..0x11662c）
 * @func 0x116550 0x11662c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / 0xb65b0 / YYGetInt32(RValue const*, int) / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×2 / 0x70×1 / 0xc×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116550 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x116554 sub sp, sp, #84
 *   @0x116558 add r5, sp, #12
 *   @0x11655c mov r2, #68
 *   @0x116560 ldr r4, [sp, #0x70]
 *   @0x116564 mov r1, #0
 *   @0x116568 mov r7, r0
 *   @0x11656c mov r0, r5
 *   @0x116570 bl 0xb65b0 <memset@plt>
 *   @0x116574 mov r1, #0
 *   @0x116578 mov r0, r4
 *   @0x11657c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x116580 mov r1, #1
 *   @0x116584 mov r9, r0
 *   @0x116588 mov r0, r4
 *   @0x11658c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x116590 mov r1, #2
 *   @0x116594 mov r8, r0
 *   @0x116598 mov r0, r4
 *   @0x11659c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1165a0 add r3, sp, #8
 *   @0x1165a4 add r12, sp, #76
 *   @0x1165a8 mov r2, #0
 *   @0x1165ac subs r1, r0, #1
 *   @0x1165b0 rsbs lr, r1, #0
 *   @0x1165b4 adcs lr, lr, r1
 *   @0x1165b8 str r2, [r3, #0x4]!
 *   @0x1165bc cmp r3, r12
 *   @0x1165c0 mov r6, #0
 *   @0x1165c4 bne 0x1165b8 <_Z17F_ExternalDefine7R6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x1165c8 str r6, [r7, #0xc]
 *   @0x1165cc mov r1, r8
 *   @0x1165d0 mov r2, r6
 *   @0x1165d4 mov r3, #7
 *   @0x1165d8 mov r0, r9
 *   @0x1165dc str r5, [sp]
 *   @0x1165e0 str lr, [sp, #0x4]
 *   @0x1165e4 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x1165e8 vmov.f64 d7, #-1.000000e+00
 *   @0x1165ec vmov s13, r0
 *   @0x1165f0 vcvt.f64.s32 d6, s13
 *   @0x1165f4 vmov r0, r1, d6
 *   @0x1165f8 vmov r2, s12
 *   @0x1165fc vcmp.f64 d6, d7
 *   @0x116600 vmrs APSR_nzcv, fpscr
 *   @0x116604 mov r3, r1
 *   @0x116608 stm r7, {r2, r3}
 *   @0x11660c bne 0x116620 <_Z17F_ExternalDefine7R6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x116610 ldr r0, [pc, #0x10]
 *   @0x116614 mov r1, r6
 *   @0x116618 add r0, pc, r0
 *   @0x11661c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x116620 add sp, sp, #84
 *   @0x116624 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x116628 eoreq r3, r2, r8, lsl #1
 *
 * ══ §69/137 F_ExternalDefine8(RValue&, CInstance*, CInstance*, int, RValue*)  0x11662c  size 220  55 条（0x11662c..0x116708）
 * @func 0x11662c 0x116708  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / 0xb65b0 / YYGetInt32(RValue const*, int) / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×2 / 0x70×1 / 0xc×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11662c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x116630 sub sp, sp, #84
 *   @0x116634 add r5, sp, #12
 *   @0x116638 mov r2, #68
 *   @0x11663c ldr r4, [sp, #0x70]
 *   @0x116640 mov r1, #0
 *   @0x116644 mov r7, r0
 *   @0x116648 mov r0, r5
 *   @0x11664c bl 0xb65b0 <memset@plt>
 *   @0x116650 mov r1, #0
 *   @0x116654 mov r0, r4
 *   @0x116658 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11665c mov r1, #1
 *   @0x116660 mov r9, r0
 *   @0x116664 mov r0, r4
 *   @0x116668 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11666c mov r1, #2
 *   @0x116670 mov r8, r0
 *   @0x116674 mov r0, r4
 *   @0x116678 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11667c add r3, sp, #8
 *   @0x116680 add r12, sp, #76
 *   @0x116684 mov r2, #0
 *   @0x116688 subs r1, r0, #1
 *   @0x11668c rsbs lr, r1, #0
 *   @0x116690 adcs lr, lr, r1
 *   @0x116694 str r2, [r3, #0x4]!
 *   @0x116698 cmp r3, r12
 *   @0x11669c mov r6, #0
 *   @0x1166a0 bne 0x116694 <_Z17F_ExternalDefine8R6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x1166a4 str r6, [r7, #0xc]
 *   @0x1166a8 mov r1, r8
 *   @0x1166ac mov r2, r6
 *   @0x1166b0 mov r3, #8
 *   @0x1166b4 mov r0, r9
 *   @0x1166b8 str r5, [sp]
 *   @0x1166bc str lr, [sp, #0x4]
 *   @0x1166c0 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x1166c4 vmov.f64 d7, #-1.000000e+00
 *   @0x1166c8 vmov s13, r0
 *   @0x1166cc vcvt.f64.s32 d6, s13
 *   @0x1166d0 vmov r0, r1, d6
 *   @0x1166d4 vmov r2, s12
 *   @0x1166d8 vcmp.f64 d6, d7
 *   @0x1166dc vmrs APSR_nzcv, fpscr
 *   @0x1166e0 mov r3, r1
 *   @0x1166e4 stm r7, {r2, r3}
 *   @0x1166e8 bne 0x1166fc <_Z17F_ExternalDefine8R6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x1166ec ldr r0, [pc, #0x10]
 *   @0x1166f0 mov r1, r6
 *   @0x1166f4 add r0, pc, r0
 *   @0x1166f8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1166fc add sp, sp, #84
 *   @0x116700 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x116704 eoreq r2, r2, r12, lsr #31
 *
 * ══ §70/137 F_EventInherited(RValue&, CInstance*, CInstance*, int, RValue*)  0x1168c8  size 220  55 条（0x1168c8..0x1169a4）
 * @func 0x1168c8 0x1169a4  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1168d8→0x54290c, 0x1168f4→0x542374, 0x116958→0x542904, 0x116960→0x542908
 * 调用序列: Object_Exists(int)×2
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×2 / 0xb8×1 / 0xb4×1 / 0x9c×1 / 0x3×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1168c8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1168cc mov r7, r1
 *   @0x1168d0 ldr r4, [pc, #0xb8]
 *   @0x1168d4 mov r6, r2
 *   @0x1168d8 ldr r3, [pc, #0xb4]
 *   @0x1168dc add r4, pc, r4
 *   @0x1168e0 ldr r5, [r4, r3]
 *   @0x1168e4 ldr r0, [r5]
 *   @0x1168e8 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x1168ec cmp r0, #0
 *   @0x1168f0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1168f4 ldr r3, [pc, #0x9c]
 *   @0x1168f8 ldr lr, [r5]
 *   @0x1168fc ldr r3, [r4, r3]
 *   @0x116900 ldr r3, [r3]
 *   @0x116904 ldr r2, [r3, #0x4]
 *   @0x116908 ldr r3, [r3]
 *   @0x11690c and r2, lr, r2
 *   @0x116910 ldr r3, [r3, r2, lsl #3]
 *   @0x116914 cmp r3, #0
 *   @0x116918 beq 0x116944 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x11691c ldr r2, [r3, #0x8]
 *   @0x116920 cmp lr, r2
 *   @0x116924 bne 0x116938 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x116928 b 0x116988 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x11692c ldr r12, [r3, #0x8]
 *   @0x116930 cmp lr, r12
 *   @0x116934 beq 0x116988 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x116938 ldr r3, [r3, #0x4]
 *   @0x11693c cmp r3, #0
 *   @0x116940 bne 0x11692c <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x116944 ldr r5, [r3, #0xc]
 *   @0x116948 mov r0, r5
 *   @0x11694c bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x116950 cmp r0, #0
 *   @0x116954 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x116958 ldr r12, [pc, #0x3c]
 *   @0x11695c mov r0, r7
 *   @0x116960 ldr r3, [pc, #0x38]
 *   @0x116964 mov r1, r6
 *   @0x116968 mov r2, r5
 *   @0x11696c ldr r12, [r4, r12]
 *   @0x116970 ldr r3, [r4, r3]
 *   @0x116974 ldr r12, [r12]
 *   @0x116978 ldr r3, [r3]
 *   @0x11697c str r12, [sp, #0x18]
 *   @0x116980 pop {r4, r5, r6, r7, r8, lr}
 *   @0x116984 b 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii>
 *   @0x116988 ldr r3, [r3, #0xc]
 *   @0x11698c b 0x116944 <_Z16F_EventInheritedR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x116990 eoreq r11, sp, r4, ror r3
 *   @0x116994 .word 0xffffc168
 *   @0x116998 .word 0xffffbfec
 *   @0x11699c .word 0xffffc164
 *   @0x1169a0 .word 0xffffc160
 *
 * ══ §71/137 F_DateDaysInYear(RValue&, CInstance*, CInstance*, int, RValue*)  0x117bd8  size 220  55 条（0x117bd8..0x117cb4）
 * @func 0x117bd8 0x117cb4  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / is_leap_year(int) / 0xb682c / 0x82895c
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x74×1 / 0x14×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117bd8 push {r4, lr}
 *   @0x117bdc sub sp, sp, #8
 *   @0x117be0 mov r1, #0
 *   @0x117be4 mov r4, r0
 *   @0x117be8 str r1, [r0, #0xc]
 *   @0x117bec mov r3, #53248
 *   @0x117bf0 movt r3, #0x4076
 *   @0x117bf4 stm r0, {r1, r3}
 *   @0x117bf8 ldr r0, [sp, #0x10]
 *   @0x117bfc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x117c00 vldr d7, [pc, #144]
 *   @0x117c04 vldr d5, [pc, #148]
 *   @0x117c08 vmov d6, r0, r1
 *   @0x117c0c vsub.f64 d7, d6, d7
 *   @0x117c10 vabs.f64 d4, d7
 *   @0x117c14 vcmpe.f64 d4, d5
 *   @0x117c18 vmrs APSR_nzcv, fpscr
 *   @0x117c1c vldrls d7, [pc, #132]
 *   @0x117c20 vldrhi d6, [pc, #128]
 *   @0x117c24 vmul.f64 d5, d7, d6
 *   @0x117c28 vmov r0, r1, d5
 *   @0x117c2c bl 0x3194a0 <__fixdfdi>
 *   @0x117c30 mov r3, r1
 *   @0x117c34 ldr r1, [pc, #0x74]
 *   @0x117c38 mov r2, r0
 *   @0x117c3c strd r2, r3, [sp]
 *   @0x117c40 add r1, pc, r1
 *   @0x117c44 mov r0, sp
 *   @0x117c48 ldrb r3, [r1]
 *   @0x117c4c cmp r3, #0
 *   @0x117c50 bne 0x117c8c <_Z16F_DateDaysInYearR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x117c54 bl 0xb6820 <gmtime64@plt>
 *   @0x117c58 cmp r0, #0
 *   @0x117c5c beq 0x117c84 <_Z16F_DateDaysInYearR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x117c60 ldr r0, [r0, #0x14]
 *   @0x117c64 add r0, r0, #1888
 *   @0x117c68 add r0, r0, #12
 *   @0x117c6c bl 0x117a5c <_Z12is_leap_yeari>
 *   @0x117c70 cmp r0, #0
 *   @0x117c74 movne r3, #57344
 *   @0x117c78 movne r2, #0
 *   @0x117c7c movtne r3, #0x4076
 *   @0x117c80 stmne r4, {r2, r3}
 *   @0x117c84 add sp, sp, #8
 *   @0x117c88 pop {r4, pc}
 *   @0x117c8c bl 0xb682c <localtime64@plt>
 *   @0x117c90 b 0x117c58 <_Z16F_DateDaysInYearR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x117c94 nop
 *   @0x117c98 andeq r0, r0, r0
 *   @0x117c9c sbcsmi pc, r8, r0, asr #16
 *   @0x117ca0 bl 0x82895c <b2_toiTime+0xcf4b8>
 *   @0x117ca4 svclo #0x1a36e2
 *   @0x117ca8 andeq r0, r0, r0
 *   @0x117cac rscsmi r1, r5, r0, lsl #16
 *   @0x117cb0 .word 0x002da4f8
 *
 * ══ §72/137 F_DateLeapYear(RValue&, CInstance*, CInstance*, int, RValue*)  0x117cb8  size 220  55 条（0x117cb8..0x117d94）
 * @func 0x117cb8 0x117d94  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / is_leap_year(int) / 0xb682c / 0x828a3c
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x74×1 / 0x14×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117cb8 push {r4, lr}
 *   @0x117cbc sub sp, sp, #8
 *   @0x117cc0 mov r3, #0
 *   @0x117cc4 mov r4, r0
 *   @0x117cc8 str r3, [r0, #0xc]
 *   @0x117ccc mov r1, r3
 *   @0x117cd0 str r3, [r0]
 *   @0x117cd4 str r3, [r0, #0x4]
 *   @0x117cd8 ldr r0, [sp, #0x10]
 *   @0x117cdc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x117ce0 vldr d7, [pc, #144]
 *   @0x117ce4 vldr d5, [pc, #148]
 *   @0x117ce8 vmov d6, r0, r1
 *   @0x117cec vsub.f64 d7, d6, d7
 *   @0x117cf0 vabs.f64 d4, d7
 *   @0x117cf4 vcmpe.f64 d4, d5
 *   @0x117cf8 vmrs APSR_nzcv, fpscr
 *   @0x117cfc vldrls d7, [pc, #132]
 *   @0x117d00 vldrhi d6, [pc, #128]
 *   @0x117d04 vmul.f64 d5, d7, d6
 *   @0x117d08 vmov r0, r1, d5
 *   @0x117d0c bl 0x3194a0 <__fixdfdi>
 *   @0x117d10 mov r3, r1
 *   @0x117d14 ldr r1, [pc, #0x74]
 *   @0x117d18 mov r2, r0
 *   @0x117d1c strd r2, r3, [sp]
 *   @0x117d20 add r1, pc, r1
 *   @0x117d24 mov r0, sp
 *   @0x117d28 ldrb r3, [r1]
 *   @0x117d2c cmp r3, #0
 *   @0x117d30 bne 0x117d6c <_Z14F_DateLeapYearR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x117d34 bl 0xb6820 <gmtime64@plt>
 *   @0x117d38 cmp r0, #0
 *   @0x117d3c beq 0x117d64 <_Z14F_DateLeapYearR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x117d40 ldr r0, [r0, #0x14]
 *   @0x117d44 add r0, r0, #1888
 *   @0x117d48 add r0, r0, #12
 *   @0x117d4c bl 0x117a5c <_Z12is_leap_yeari>
 *   @0x117d50 cmp r0, #0
 *   @0x117d54 movne r3, #0
 *   @0x117d58 movne r2, r3
 *   @0x117d5c movtne r3, #0x3ff0
 *   @0x117d60 stmne r4, {r2, r3}
 *   @0x117d64 add sp, sp, #8
 *   @0x117d68 pop {r4, pc}
 *   @0x117d6c bl 0xb682c <localtime64@plt>
 *   @0x117d70 b 0x117d38 <_Z14F_DateLeapYearR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x117d74 nop
 *   @0x117d78 andeq r0, r0, r0
 *   @0x117d7c sbcsmi pc, r8, r0, asr #16
 *   @0x117d80 bl 0x828a3c <b2_toiTime+0xcf598>
 *   @0x117d84 svclo #0x1a36e2
 *   @0x117d88 andeq r0, r0, r0
 *   @0x117d8c rscsmi r1, r5, r0, lsl #16
 *   @0x117d90 eoreq r10, sp, r8, lsl r4
 *
 * ══ §73/137 F_DrawSurfaceTiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x11f84c  size 220  55 条（0x11f84c..0x11f928）
 * @func 0x11f84c 0x11f928  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / GR_Surface_Exists(int) / GR_Draw_Get_Alpha() / GR_Surface_DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x40×1 / 0x84×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x1c×1 / 0x20×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11f84c push {r4, r5, r6, lr}
 *   @0x11f850 vpush {d8}
 *   @0x11f854 sub sp, sp, #40
 *   @0x11f858 mov r1, #0
 *   @0x11f85c ldr r4, [sp, #0x40]
 *   @0x11f860 mov r0, r4
 *   @0x11f864 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f868 mov r5, r0
 *   @0x11f86c bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f870 subs r1, r0, #0
 *   @0x11f874 beq 0x11f908 <_Z18F_DrawSurfaceTiledR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x11f878 mov r0, r4
 *   @0x11f87c mov r1, #1
 *   @0x11f880 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f884 mov r1, #2
 *   @0x11f888 mov r6, r0
 *   @0x11f88c mov r0, r4
 *   @0x11f890 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f894 ldr r3, [pc, #0x84]
 *   @0x11f898 ldr r3, [pc, r3]
 *   @0x11f89c ldr r3, [r3]
 *   @0x11f8a0 vldr s17, [r3, #16]
 *   @0x11f8a4 vldr s16, [r3, #20]
 *   @0x11f8a8 vcvt.f32.s32 s17, s17
 *   @0x11f8ac vcvt.f32.s32 s16, s16
 *   @0x11f8b0 mov r4, r0
 *   @0x11f8b4 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11f8b8 mov r12, #0
 *   @0x11f8bc mov r3, #1
 *   @0x11f8c0 vstr s17, [sp, #20]
 *   @0x11f8c4 str r3, [sp, #0x4]
 *   @0x11f8c8 str r3, [sp, #0x8]
 *   @0x11f8cc mov r1, r6
 *   @0x11f8d0 mov r2, r4
 *   @0x11f8d4 str r12, [sp, #0xc]
 *   @0x11f8d8 str r12, [sp, #0x10]
 *   @0x11f8dc mvn r3, #-16777216
 *   @0x11f8e0 vstr s16, [sp, #24]
 *   @0x11f8e4 str r3, [sp, #0x1c]
 *   @0x11f8e8 mov r3, #1065353216
 *   @0x11f8ec str r3, [sp]
 *   @0x11f8f0 str r0, [sp, #0x20]
 *   @0x11f8f4 mov r0, r5
 *   @0x11f8f8 bl 0x172058 <_Z20GR_Surface_DrawTilediffffbbffffjf>
 *   @0x11f8fc add sp, sp, #40
 *   @0x11f900 vpop {d8}
 *   @0x11f904 pop {r4, r5, r6, pc}
 *   @0x11f908 ldr r0, [pc, #0x14]
 *   @0x11f90c add r0, pc, r0
 *   @0x11f910 add sp, sp, #40
 *   @0x11f914 vpop {d8}
 *   @0x11f918 pop {r4, r5, r6, lr}
 *   @0x11f91c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11f920 mlaeq r12, r0, r0, lr
 *   @0x11f924 eoreq r10, r1, r12, asr r9
 *
 * ══ §74/137 F_SpriteReplaceAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c06c  size 220  55 条（0x12c06c..0x12c148）
 * @func 0x12c06c 0x12c148  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / Sprite_Data(int) / YYGetString(RValue const*, int) / Sprite_Replace_Alpha(int, char const*, int, bool, bool, int, int)
 * 字段偏移 top8: 0x4×2 / 0x38×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c06c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12c070 sub sp, sp, #20
 *   @0x12c074 mov r1, #0
 *   @0x12c078 mov r5, r0
 *   @0x12c07c ldr r4, [sp, #0x38]
 *   @0x12c080 mov r0, r4
 *   @0x12c084 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c088 mov r6, r0
 *   @0x12c08c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12c090 cmp r0, #0
 *   @0x12c094 beq 0x12c128 <_Z20F_SpriteReplaceAlphaR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x12c098 mov r1, #1
 *   @0x12c09c mov r0, r4
 *   @0x12c0a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12c0a4 mov r1, #2
 *   @0x12c0a8 mov r9, r0
 *   @0x12c0ac mov r0, r4
 *   @0x12c0b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c0b4 mov r1, #3
 *   @0x12c0b8 mov r8, r0
 *   @0x12c0bc mov r0, r4
 *   @0x12c0c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c0c4 mov r1, #4
 *   @0x12c0c8 mov r7, r0
 *   @0x12c0cc mov r0, r4
 *   @0x12c0d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c0d4 mov r1, #5
 *   @0x12c0d8 mov r11, r0
 *   @0x12c0dc mov r0, r4
 *   @0x12c0e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c0e4 mov r1, #6
 *   @0x12c0e8 mov r10, r0
 *   @0x12c0ec mov r0, r4
 *   @0x12c0f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c0f4 cmp r11, #0
 *   @0x12c0f8 str r10, [sp, #0x4]
 *   @0x12c0fc mov r1, r9
 *   @0x12c100 movle r11, #0
 *   @0x12c104 movgt r11, #1
 *   @0x12c108 cmp r7, #0
 *   @0x12c10c str r11, [sp]
 *   @0x12c110 mov r2, r8
 *   @0x12c114 movle r3, #0
 *   @0x12c118 movgt r3, #1
 *   @0x12c11c str r0, [sp, #0x8]
 *   @0x12c120 mov r0, r6
 *   @0x12c124 bl 0x1ef07c <_Z20Sprite_Replace_AlphaiPKcibbii>
 *   @0x12c128 mov r2, #0
 *   @0x12c12c mov r3, r2
 *   @0x12c130 movt r2, #0xbff0
 *   @0x12c134 str r3, [r5, #0xc]
 *   @0x12c138 str r2, [r5, #0x4]
 *   @0x12c13c str r3, [r5]
 *   @0x12c140 add sp, sp, #20
 *   @0x12c144 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §75/137 F_BackgroundCreateColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c680  size 220  55 条（0x12c680..0x12c75c）
 * @func 0x12c680 0x12c75c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / Background_AddEmpty() / Background_Data(int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x20×3 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c680 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12c684 mov r6, #0
 *   @0x12c688 str r6, [r0, #0xc]
 *   @0x12c68c mov r7, r3
 *   @0x12c690 mov r5, r0
 *   @0x12c694 ldr r4, [sp, #0x20]
 *   @0x12c698 bl 0xc41f0 <_Z19Background_AddEmptyv>
 *   @0x12c69c mov r9, r0
 *   @0x12c6a0 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c6a4 vmov s15, r9
 *   @0x12c6a8 cmp r7, #4
 *   @0x12c6ac mov r1, r6
 *   @0x12c6b0 vcvt.f64.s32 d7, s15
 *   @0x12c6b4 vmov r2, r3, d7
 *   @0x12c6b8 stm r5, {r2, r3}
 *   @0x12c6bc mov r8, r0
 *   @0x12c6c0 mov r0, r4
 *   @0x12c6c4 beq 0x12c70c <_Z23F_BackgroundCreateColorR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x12c6c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c6cc mov r1, #1
 *   @0x12c6d0 mov r6, r0
 *   @0x12c6d4 mov r0, r4
 *   @0x12c6d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c6dc mov r1, #2
 *   @0x12c6e0 mov r5, r0
 *   @0x12c6e4 mov r0, r4
 *   @0x12c6e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c6ec mov r1, r6
 *   @0x12c6f0 mov r2, r5
 *   @0x12c6f4 mov r12, #1
 *   @0x12c6f8 str r12, [sp, #0x20]
 *   @0x12c6fc mov r3, r0
 *   @0x12c700 mov r0, r8
 *   @0x12c704 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12c708 b 0xc2a40 <_ZN11CBackground11CreateColorEiijb>
 *   @0x12c70c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c710 mov r1, #1
 *   @0x12c714 mov r7, r0
 *   @0x12c718 mov r0, r4
 *   @0x12c71c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c720 mov r1, #2
 *   @0x12c724 mov r6, r0
 *   @0x12c728 mov r0, r4
 *   @0x12c72c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c730 mov r1, #3
 *   @0x12c734 mov r5, r0
 *   @0x12c738 mov r0, r4
 *   @0x12c73c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c740 mov r1, r7
 *   @0x12c744 mov r2, r6
 *   @0x12c748 mov r3, r5
 *   @0x12c74c str r0, [sp, #0x20]
 *   @0x12c750 mov r0, r8
 *   @0x12c754 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12c758 b 0xc2a40 <_ZN11CBackground11CreateColorEiijb>
 *
 * ══ §76/137 F_FileAttributes(RValue&, CInstance*, CInstance*, int, RValue*)  0x13870c  size 220  55 条（0x13870c..0x1387e8）
 * @func 0x13870c 0x1387e8  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / YYGetFileAttributes(char const*, bool) / LoadSave::_GetSaveFileName(char*, int, char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0xc8×1 / 0x420×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13870c push {r4, r5, r6, r7, lr}
 *   @0x138710 sub sp, sp, #1024
 *   @0x138714 ldr r5, [pc, #0xc8]
 *   @0x138718 sub sp, sp, #12
 *   @0x13871c mov r4, r0
 *   @0x138720 mov r1, #0
 *   @0x138724 ldr r5, [pc, r5]
 *   @0x138728 ldr r0, [sp, #0x420]
 *   @0x13872c ldr r3, [r5]
 *   @0x138730 str r3, [sp, #0x404]
 *   @0x138734 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138738 mov r3, #0
 *   @0x13873c str r3, [r4, #0xc]
 *   @0x138740 str r3, [r4]
 *   @0x138744 str r3, [r4, #0x4]
 *   @0x138748 mov r6, r0
 *   @0x13874c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x138750 subs r7, r0, #0
 *   @0x138754 bne 0x1387c0 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x138758 mov r0, r6
 *   @0x13875c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x138760 cmp r0, #0
 *   @0x138764 bne 0x138784 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x138768 ldr r2, [sp, #0x404]
 *   @0x13876c ldr r3, [r5]
 *   @0x138770 cmp r2, r3
 *   @0x138774 bne 0x1387e0 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x138778 add sp, sp, #1024
 *   @0x13877c add sp, sp, #12
 *   @0x138780 pop {r4, r5, r6, r7, pc}
 *   @0x138784 mov r2, r6
 *   @0x138788 add r6, sp, #4
 *   @0x13878c mov r1, #1024
 *   @0x138790 mov r0, r6
 *   @0x138794 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x138798 mov r0, r6
 *   @0x13879c mov r1, r7
 *   @0x1387a0 bl 0x160ad8 <_Z19YYGetFileAttributesPKcb>
 *   @0x1387a4 vmov s15, r0
 *   @0x1387a8 vcvt.f64.s32 d7, s15
 *   @0x1387ac vmov r0, r1, d7
 *   @0x1387b0 vmov r2, s14
 *   @0x1387b4 mov r3, r1
 *   @0x1387b8 stm r4, {r2, r3}
 *   @0x1387bc b 0x138768 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1387c0 mov r2, r6
 *   @0x1387c4 add r6, sp, #4
 *   @0x1387c8 mov r1, #1024
 *   @0x1387cc mov r0, r6
 *   @0x1387d0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1387d4 mov r0, r6
 *   @0x1387d8 mov r1, #1
 *   @0x1387dc b 0x1387a0 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x1387e0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1387e4 eoreq r5, r11, r12, lsr #4
 *
 * ══ §77/137 json_value(json_object*, RValue*)  0x13c274  size 220  55 条（0x13c274..0x13c350）
 * @func 0x13c274 0x13c350  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_get_type / json_object_get_string / json_object_get_boolean / json_object_get_double / json_object_get_int
 * 字段偏移 top8: 0xc×4 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c274 push {r3, r4, r5, lr}
 *   @0x13c278 subs r5, r0, #0
 *   @0x13c27c mov r4, r1
 *   @0x13c280 beq 0x13c2b0 <_Z10json_valueP11json_objectP6RValue+0x3c>
 *   @0x13c284 bl 0x27e828 <json_object_get_type>
 *   @0x13c288 cmp r0, #6
 *   @0x13c28c addls pc, pc, r0, lsl #2
 *   @0x13c290 b 0x13c2c4 <_Z10json_valueP11json_objectP6RValue+0x50>
 *   @0x13c294 b 0x13c2b0 <_Z10json_valueP11json_objectP6RValue+0x3c>
 *   @0x13c298 b 0x13c2e0 <_Z10json_valueP11json_objectP6RValue+0x6c>
 *   @0x13c29c b 0x13c30c <_Z10json_valueP11json_objectP6RValue+0x98>
 *   @0x13c2a0 b 0x13c324 <_Z10json_valueP11json_objectP6RValue+0xb0>
 *   @0x13c2a4 b 0x13c2c4 <_Z10json_valueP11json_objectP6RValue+0x50>
 *   @0x13c2a8 b 0x13c2c4 <_Z10json_valueP11json_objectP6RValue+0x50>
 *   @0x13c2ac b 0x13c2c8 <_Z10json_valueP11json_objectP6RValue+0x54>
 *   @0x13c2b0 mov r3, #0
 *   @0x13c2b4 mov r2, #5
 *   @0x13c2b8 str r3, [r4]
 *   @0x13c2bc str r2, [r4, #0xc]
 *   @0x13c2c0 str r3, [r4, #0x4]
 *   @0x13c2c4 pop {r3, r4, r5, pc}
 *   @0x13c2c8 mov r0, r5
 *   @0x13c2cc bl 0x27ed58 <json_object_get_string>
 *   @0x13c2d0 mov r1, r0
 *   @0x13c2d4 mov r0, r4
 *   @0x13c2d8 pop {r3, r4, r5, lr}
 *   @0x13c2dc b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x13c2e0 mov r0, r5
 *   @0x13c2e4 mov r5, #0
 *   @0x13c2e8 str r5, [r4, #0xc]
 *   @0x13c2ec bl 0x27ea78 <json_object_get_boolean>
 *   @0x13c2f0 cmp r0, #0
 *   @0x13c2f4 movne r0, r5
 *   @0x13c2f8 moveq r3, r0
 *   @0x13c2fc movne r3, r0
 *   @0x13c300 movtne r3, #0x3ff0
 *   @0x13c304 stm r4, {r0, r3}
 *   @0x13c308 pop {r3, r4, r5, pc}
 *   @0x13c30c mov r3, #0
 *   @0x13c310 mov r0, r5
 *   @0x13c314 str r3, [r4, #0xc]
 *   @0x13c318 bl 0x27ebf0 <json_object_get_double>
 *   @0x13c31c stm r4, {r0, r1}
 *   @0x13c320 pop {r3, r4, r5, pc}
 *   @0x13c324 mov r3, #0
 *   @0x13c328 mov r0, r5
 *   @0x13c32c str r3, [r4, #0xc]
 *   @0x13c330 bl 0x27eb28 <json_object_get_int>
 *   @0x13c334 vmov s15, r0
 *   @0x13c338 vcvt.f64.s32 d7, s15
 *   @0x13c33c vmov r0, r1, d7
 *   @0x13c340 vmov r2, s14
 *   @0x13c344 mov r3, r1
 *   @0x13c348 stm r4, {r2, r3}
 *   @0x13c34c pop {r3, r4, r5, pc}
 *
 * ══ §78/137 F_ActionReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x1411dc  size 220  55 条（0x1411dc..0x1412b8）
 * @func 0x1411dc 0x1412b8  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / Sprite_Exists(int) / FileExists(char const*) / Sprite_Data(int) / Sprite_Replace(int, char const*, int, bool, bool, bool, bool, int, int)
 * 字段偏移 top8: 0x28×2 / 0x10×2 / 0x32×1 / 0x30×1 / 0x33×1 / 0x4×1 / 0x34×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1411dc push {r4, r5, r6, lr}
 *   @0x1411e0 sub sp, sp, #24
 *   @0x1411e4 mov r1, #0
 *   @0x1411e8 ldr r4, [sp, #0x28]
 *   @0x1411ec mov r0, r4
 *   @0x1411f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1411f4 mov r1, #1
 *   @0x1411f8 mov r5, r0
 *   @0x1411fc mov r0, r4
 *   @0x141200 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x141204 mov r1, #2
 *   @0x141208 mov r6, r0
 *   @0x14120c mov r0, r4
 *   @0x141210 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x141214 mov r4, r0
 *   @0x141218 mov r0, r5
 *   @0x14121c bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x141220 subs r1, r0, #0
 *   @0x141224 beq 0x14129c <_Z21F_ActionReplaceSpriteR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x141228 mov r0, r6
 *   @0x14122c bl 0x214e48 <_Z10FileExistsPKc>
 *   @0x141230 subs r1, r0, #0
 *   @0x141234 beq 0x141288 <_Z21F_ActionReplaceSpriteR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x141238 mov r0, r5
 *   @0x14123c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x141240 mov r1, r6
 *   @0x141244 mov r2, r4
 *   @0x141248 ldrb lr, [r0, #0x32]
 *   @0x14124c mov r12, r0
 *   @0x141250 ldrb r3, [r12, #0x30]
 *   @0x141254 mov r0, r5
 *   @0x141258 str lr, [sp]
 *   @0x14125c ldrb lr, [r12, #0x33]
 *   @0x141260 str lr, [sp, #0x4]
 *   @0x141264 ldrb lr, [r12, #0x34]
 *   @0x141268 str lr, [sp, #0x8]
 *   @0x14126c ldr lr, [r12, #0x24]
 *   @0x141270 str lr, [sp, #0xc]
 *   @0x141274 ldr r12, [r12, #0x28]
 *   @0x141278 str r12, [sp, #0x10]
 *   @0x14127c bl 0x1ef5a8 <_Z14Sprite_ReplaceiPKcibbbbii>
 *   @0x141280 add sp, sp, #24
 *   @0x141284 pop {r4, r5, r6, pc}
 *   @0x141288 ldr r0, [pc, #0x20]
 *   @0x14128c add r0, pc, r0
 *   @0x141290 add sp, sp, #24
 *   @0x141294 pop {r4, r5, r6, lr}
 *   @0x141298 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14129c ldr r0, [pc, #0x10]
 *   @0x1412a0 add r0, pc, r0
 *   @0x1412a4 add sp, sp, #24
 *   @0x1412a8 pop {r4, r5, r6, lr}
 *   @0x1412ac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1412b0 andseq pc, pc, r4, ror #13
 *   @0x1412b4 andseq pc, pc, r4, lsr #13
 *
 * ══ §79/137 F_ActionInherited(RValue&, CInstance*, CInstance*, int, RValue*)  0x1412b8  size 220  55 条（0x1412b8..0x141394）
 * @func 0x1412b8 0x141394  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1412c8→0x54290c, 0x1412e4→0x542374, 0x141348→0x542904, 0x141350→0x542908
 * 调用序列: Object_Exists(int)×2
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×2 / 0xb8×1 / 0xb4×1 / 0x9c×1 / 0x3×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1412b8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1412bc mov r7, r1
 *   @0x1412c0 ldr r4, [pc, #0xb8]
 *   @0x1412c4 mov r6, r2
 *   @0x1412c8 ldr r3, [pc, #0xb4]
 *   @0x1412cc add r4, pc, r4
 *   @0x1412d0 ldr r5, [r4, r3]
 *   @0x1412d4 ldr r0, [r5]
 *   @0x1412d8 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x1412dc cmp r0, #0
 *   @0x1412e0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1412e4 ldr r3, [pc, #0x9c]
 *   @0x1412e8 ldr lr, [r5]
 *   @0x1412ec ldr r3, [r4, r3]
 *   @0x1412f0 ldr r3, [r3]
 *   @0x1412f4 ldr r2, [r3, #0x4]
 *   @0x1412f8 ldr r3, [r3]
 *   @0x1412fc and r2, lr, r2
 *   @0x141300 ldr r3, [r3, r2, lsl #3]
 *   @0x141304 cmp r3, #0
 *   @0x141308 beq 0x141334 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x14130c ldr r2, [r3, #0x8]
 *   @0x141310 cmp lr, r2
 *   @0x141314 bne 0x141328 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x141318 b 0x141378 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x14131c ldr r12, [r3, #0x8]
 *   @0x141320 cmp lr, r12
 *   @0x141324 beq 0x141378 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x141328 ldr r3, [r3, #0x4]
 *   @0x14132c cmp r3, #0
 *   @0x141330 bne 0x14131c <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x141334 ldr r5, [r3, #0xc]
 *   @0x141338 mov r0, r5
 *   @0x14133c bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x141340 cmp r0, #0
 *   @0x141344 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x141348 ldr r12, [pc, #0x3c]
 *   @0x14134c mov r0, r7
 *   @0x141350 ldr r3, [pc, #0x38]
 *   @0x141354 mov r1, r6
 *   @0x141358 mov r2, r5
 *   @0x14135c ldr r12, [r4, r12]
 *   @0x141360 ldr r3, [r4, r3]
 *   @0x141364 ldr r12, [r12]
 *   @0x141368 ldr r3, [r3]
 *   @0x14136c str r12, [sp, #0x18]
 *   @0x141370 pop {r4, r5, r6, r7, r8, lr}
 *   @0x141374 b 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii>
 *   @0x141378 ldr r3, [r3, #0xc]
 *   @0x14137c b 0x141334 <_Z17F_ActionInheritedR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x141380 eoreq r0, r11, r4, lsl #19
 *   @0x141384 .word 0xffffc168
 *   @0x141388 .word 0xffffbfec
 *   @0x14138c .word 0xffffc164
 *   @0x141390 .word 0xffffc160
 *
 * ══ §80/137 F_PhysicsSetMass(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c794  size 220  55 条（0x14c794..0x14c870）
 * @func 0x14c794 0x14c870  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×2 / 0x84×1 / 0xb0×1 / 0xb4×1 / 0x24×1 / 0x10×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c794 push {r4, r5, r6, lr}
 *   @0x14c798 vpush {d8}
 *   @0x14c79c ldr r5, [r1, #0x84]
 *   @0x14c7a0 ldr r4, [sp, #0x18]
 *   @0x14c7a4 cmp r5, #0
 *   @0x14c7a8 beq 0x14c84c <_Z16F_PhysicsSetMassR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14c7ac ldr r3, [pc, #0xb0]
 *   @0x14c7b0 ldr r3, [pc, r3]
 *   @0x14c7b4 ldr r3, [r3]
 *   @0x14c7b8 cmp r3, #0
 *   @0x14c7bc beq 0x14c834 <_Z16F_PhysicsSetMassR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14c7c0 ldr r3, [r3, #0xb4]
 *   @0x14c7c4 cmp r3, #0
 *   @0x14c7c8 beq 0x14c834 <_Z16F_PhysicsSetMassR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14c7cc mov r0, r4
 *   @0x14c7d0 mov r1, #0
 *   @0x14c7d4 vldr s16, [r3, #96]
 *   @0x14c7d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c7dc mov r1, #1
 *   @0x14c7e0 mov r6, r0
 *   @0x14c7e4 mov r0, r4
 *   @0x14c7e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c7ec mov r1, #2
 *   @0x14c7f0 vmov s15, r0
 *   @0x14c7f4 mov r0, r4
 *   @0x14c7f8 vmul.f32 s17, s16, s15
 *   @0x14c7fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c800 mov r1, #3
 *   @0x14c804 vmov s15, r0
 *   @0x14c808 mov r0, r4
 *   @0x14c80c vmul.f32 s16, s16, s15
 *   @0x14c810 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c814 vmov r2, s17
 *   @0x14c818 mov r1, r6
 *   @0x14c81c vmov r3, s16
 *   @0x14c820 str r0, [sp, #0x18]
 *   @0x14c824 mov r0, r5
 *   @0x14c828 vpop {d8}
 *   @0x14c82c pop {r4, r5, r6, lr}
 *   @0x14c830 b 0x236dd0 <_ZN14CPhysicsObject7SetMassEffff>
 *   @0x14c834 vpop {d8}
 *   @0x14c838 mov r1, #0
 *   @0x14c83c ldr r0, [pc, #0x24]
 *   @0x14c840 add r0, pc, r0
 *   @0x14c844 pop {r4, r5, r6, lr}
 *   @0x14c848 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c84c vpop {d8}
 *   @0x14c850 mov r1, r5
 *   @0x14c854 ldr r0, [pc, #0x10]
 *   @0x14c858 add r0, pc, r0
 *   @0x14c85c pop {r4, r5, r6, lr}
 *   @0x14c860 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c864 eoreq r1, r10, r8, ror r1
 *   @0x14c868 andseq r7, pc, r4, ror #11
 *   @0x14c86c andseq r7, pc, r12, lsl #11
 *
 * ══ §81/137 F_PhysicsApplyForce(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c870  size 220  55 条（0x14c870..0x14c94c）
 * @func 0x14c870 0x14c94c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×2 / 0x84×1 / 0xb0×1 / 0xb4×1 / 0x24×1 / 0x10×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c870 push {r4, r5, r6, lr}
 *   @0x14c874 vpush {d8}
 *   @0x14c878 ldr r5, [r1, #0x84]
 *   @0x14c87c ldr r4, [sp, #0x18]
 *   @0x14c880 cmp r5, #0
 *   @0x14c884 beq 0x14c928 <_Z19F_PhysicsApplyForceR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14c888 ldr r3, [pc, #0xb0]
 *   @0x14c88c ldr r3, [pc, r3]
 *   @0x14c890 ldr r3, [r3]
 *   @0x14c894 cmp r3, #0
 *   @0x14c898 beq 0x14c910 <_Z19F_PhysicsApplyForceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14c89c ldr r3, [r3, #0xb4]
 *   @0x14c8a0 cmp r3, #0
 *   @0x14c8a4 beq 0x14c910 <_Z19F_PhysicsApplyForceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14c8a8 mov r0, r4
 *   @0x14c8ac mov r1, #0
 *   @0x14c8b0 vldr s16, [r3, #96]
 *   @0x14c8b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c8b8 mov r1, #1
 *   @0x14c8bc vmov s15, r0
 *   @0x14c8c0 mov r0, r4
 *   @0x14c8c4 vmul.f32 s17, s16, s15
 *   @0x14c8c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c8cc mov r1, #2
 *   @0x14c8d0 vmov s15, r0
 *   @0x14c8d4 mov r0, r4
 *   @0x14c8d8 vmul.f32 s16, s16, s15
 *   @0x14c8dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c8e0 mov r1, #3
 *   @0x14c8e4 mov r6, r0
 *   @0x14c8e8 mov r0, r4
 *   @0x14c8ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c8f0 vmov r1, s17
 *   @0x14c8f4 vmov r2, s16
 *   @0x14c8f8 mov r3, r6
 *   @0x14c8fc str r0, [sp, #0x18]
 *   @0x14c900 mov r0, r5
 *   @0x14c904 vpop {d8}
 *   @0x14c908 pop {r4, r5, r6, lr}
 *   @0x14c90c b 0x237058 <_ZN14CPhysicsObject10ApplyForceEffff>
 *   @0x14c910 vpop {d8}
 *   @0x14c914 mov r1, #0
 *   @0x14c918 ldr r0, [pc, #0x24]
 *   @0x14c91c add r0, pc, r0
 *   @0x14c920 pop {r4, r5, r6, lr}
 *   @0x14c924 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c928 vpop {d8}
 *   @0x14c92c mov r1, r5
 *   @0x14c930 ldr r0, [pc, #0x10]
 *   @0x14c934 add r0, pc, r0
 *   @0x14c938 pop {r4, r5, r6, lr}
 *   @0x14c93c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c940 mlaeq r10, r12, r0, r1
 *   @0x14c944 andseq r7, pc, r8, lsl #10
 *   @0x14c948 ldrheq r7, [pc], -r0
 *
 * ══ §82/137 F_PhysicsApplyImpulse(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c94c  size 220  55 条（0x14c94c..0x14ca28）
 * @func 0x14c94c 0x14ca28  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×2 / 0x84×1 / 0xb0×1 / 0xb4×1 / 0x24×1 / 0x10×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c94c push {r4, r5, r6, lr}
 *   @0x14c950 vpush {d8}
 *   @0x14c954 ldr r5, [r1, #0x84]
 *   @0x14c958 ldr r4, [sp, #0x18]
 *   @0x14c95c cmp r5, #0
 *   @0x14c960 beq 0x14ca04 <_Z21F_PhysicsApplyImpulseR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14c964 ldr r3, [pc, #0xb0]
 *   @0x14c968 ldr r3, [pc, r3]
 *   @0x14c96c ldr r3, [r3]
 *   @0x14c970 cmp r3, #0
 *   @0x14c974 beq 0x14c9ec <_Z21F_PhysicsApplyImpulseR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14c978 ldr r3, [r3, #0xb4]
 *   @0x14c97c cmp r3, #0
 *   @0x14c980 beq 0x14c9ec <_Z21F_PhysicsApplyImpulseR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14c984 mov r0, r4
 *   @0x14c988 mov r1, #0
 *   @0x14c98c vldr s16, [r3, #96]
 *   @0x14c990 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c994 mov r1, #1
 *   @0x14c998 vmov s15, r0
 *   @0x14c99c mov r0, r4
 *   @0x14c9a0 vmul.f32 s17, s16, s15
 *   @0x14c9a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c9a8 mov r1, #2
 *   @0x14c9ac vmov s15, r0
 *   @0x14c9b0 mov r0, r4
 *   @0x14c9b4 vmul.f32 s16, s16, s15
 *   @0x14c9b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c9bc mov r1, #3
 *   @0x14c9c0 mov r6, r0
 *   @0x14c9c4 mov r0, r4
 *   @0x14c9c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c9cc vmov r1, s17
 *   @0x14c9d0 vmov r2, s16
 *   @0x14c9d4 mov r3, r6
 *   @0x14c9d8 str r0, [sp, #0x18]
 *   @0x14c9dc mov r0, r5
 *   @0x14c9e0 vpop {d8}
 *   @0x14c9e4 pop {r4, r5, r6, lr}
 *   @0x14c9e8 b 0x236fd0 <_ZN14CPhysicsObject12ApplyImpulseEffff>
 *   @0x14c9ec vpop {d8}
 *   @0x14c9f0 mov r1, #0
 *   @0x14c9f4 ldr r0, [pc, #0x24]
 *   @0x14c9f8 add r0, pc, r0
 *   @0x14c9fc pop {r4, r5, r6, lr}
 *   @0x14ca00 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ca04 vpop {d8}
 *   @0x14ca08 mov r1, r5
 *   @0x14ca0c ldr r0, [pc, #0x10]
 *   @0x14ca10 add r0, pc, r0
 *   @0x14ca14 pop {r4, r5, r6, lr}
 *   @0x14ca18 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ca1c eoreq r0, r10, r0, asr #31
 *   @0x14ca20 andseq r7, pc, r12, lsr #8
 *   @0x14ca24 ldrsbeq r7, [pc], -r4
 *
 * ══ §83/137 F_PhysicsApplyLocalForce(RValue&, CInstance*, CInstance*, int, RValue*)  0x14caa8  size 220  55 条（0x14caa8..0x14cb84）
 * @func 0x14caa8 0x14cb84  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×2 / 0x84×1 / 0xb0×1 / 0xb4×1 / 0x24×1 / 0x10×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14caa8 push {r4, r5, r6, lr}
 *   @0x14caac vpush {d8}
 *   @0x14cab0 ldr r5, [r1, #0x84]
 *   @0x14cab4 ldr r4, [sp, #0x18]
 *   @0x14cab8 cmp r5, #0
 *   @0x14cabc beq 0x14cb60 <_Z24F_PhysicsApplyLocalForceR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14cac0 ldr r3, [pc, #0xb0]
 *   @0x14cac4 ldr r3, [pc, r3]
 *   @0x14cac8 ldr r3, [r3]
 *   @0x14cacc cmp r3, #0
 *   @0x14cad0 beq 0x14cb48 <_Z24F_PhysicsApplyLocalForceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14cad4 ldr r3, [r3, #0xb4]
 *   @0x14cad8 cmp r3, #0
 *   @0x14cadc beq 0x14cb48 <_Z24F_PhysicsApplyLocalForceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14cae0 mov r0, r4
 *   @0x14cae4 mov r1, #0
 *   @0x14cae8 vldr s16, [r3, #96]
 *   @0x14caec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14caf0 mov r1, #1
 *   @0x14caf4 vmov s15, r0
 *   @0x14caf8 mov r0, r4
 *   @0x14cafc vmul.f32 s17, s16, s15
 *   @0x14cb00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cb04 mov r1, #2
 *   @0x14cb08 vmov s15, r0
 *   @0x14cb0c mov r0, r4
 *   @0x14cb10 vmul.f32 s16, s16, s15
 *   @0x14cb14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cb18 mov r1, #3
 *   @0x14cb1c mov r6, r0
 *   @0x14cb20 mov r0, r4
 *   @0x14cb24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cb28 vmov r1, s17
 *   @0x14cb2c vmov r2, s16
 *   @0x14cb30 mov r3, r6
 *   @0x14cb34 str r0, [sp, #0x18]
 *   @0x14cb38 mov r0, r5
 *   @0x14cb3c vpop {d8}
 *   @0x14cb40 pop {r4, r5, r6, lr}
 *   @0x14cb44 b 0x2370d8 <_ZN14CPhysicsObject15ApplyLocalForceEffff>
 *   @0x14cb48 vpop {d8}
 *   @0x14cb4c mov r1, #0
 *   @0x14cb50 ldr r0, [pc, #0x24]
 *   @0x14cb54 add r0, pc, r0
 *   @0x14cb58 pop {r4, r5, r6, lr}
 *   @0x14cb5c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cb60 vpop {d8}
 *   @0x14cb64 mov r1, r5
 *   @0x14cb68 ldr r0, [pc, #0x10]
 *   @0x14cb6c add r0, pc, r0
 *   @0x14cb70 pop {r4, r5, r6, lr}
 *   @0x14cb74 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cb78 eoreq r0, r10, r4, ror #28
 *   @0x14cb7c ldrsbeq r7, [pc], -r0
 *   @0x14cb80 andseq r7, pc, r8, ror r2
 *
 * ══ §84/137 F_PhysicsApplyLocalImpulse(RValue&, CInstance*, CInstance*, int, RValue*)  0x14cb84  size 220  55 条（0x14cb84..0x14cc60）
 * @func 0x14cb84 0x14cc60  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×2 / 0x84×1 / 0xb0×1 / 0xb4×1 / 0x24×1 / 0x10×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14cb84 push {r4, r5, r6, lr}
 *   @0x14cb88 vpush {d8}
 *   @0x14cb8c ldr r5, [r1, #0x84]
 *   @0x14cb90 ldr r4, [sp, #0x18]
 *   @0x14cb94 cmp r5, #0
 *   @0x14cb98 beq 0x14cc3c <_Z26F_PhysicsApplyLocalImpulseR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14cb9c ldr r3, [pc, #0xb0]
 *   @0x14cba0 ldr r3, [pc, r3]
 *   @0x14cba4 ldr r3, [r3]
 *   @0x14cba8 cmp r3, #0
 *   @0x14cbac beq 0x14cc24 <_Z26F_PhysicsApplyLocalImpulseR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14cbb0 ldr r3, [r3, #0xb4]
 *   @0x14cbb4 cmp r3, #0
 *   @0x14cbb8 beq 0x14cc24 <_Z26F_PhysicsApplyLocalImpulseR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x14cbbc mov r0, r4
 *   @0x14cbc0 mov r1, #0
 *   @0x14cbc4 vldr s16, [r3, #96]
 *   @0x14cbc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cbcc mov r1, #1
 *   @0x14cbd0 vmov s15, r0
 *   @0x14cbd4 mov r0, r4
 *   @0x14cbd8 vmul.f32 s17, s16, s15
 *   @0x14cbdc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cbe0 mov r1, #2
 *   @0x14cbe4 vmov s15, r0
 *   @0x14cbe8 mov r0, r4
 *   @0x14cbec vmul.f32 s16, s16, s15
 *   @0x14cbf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cbf4 mov r1, #3
 *   @0x14cbf8 mov r6, r0
 *   @0x14cbfc mov r0, r4
 *   @0x14cc00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cc04 vmov r1, s17
 *   @0x14cc08 vmov r2, s16
 *   @0x14cc0c mov r3, r6
 *   @0x14cc10 str r0, [sp, #0x18]
 *   @0x14cc14 mov r0, r5
 *   @0x14cc18 vpop {d8}
 *   @0x14cc1c pop {r4, r5, r6, lr}
 *   @0x14cc20 b 0x237190 <_ZN14CPhysicsObject17ApplyLocalImpulseEffff>
 *   @0x14cc24 vpop {d8}
 *   @0x14cc28 mov r1, #0
 *   @0x14cc2c ldr r0, [pc, #0x24]
 *   @0x14cc30 add r0, pc, r0
 *   @0x14cc34 pop {r4, r5, r6, lr}
 *   @0x14cc38 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cc3c vpop {d8}
 *   @0x14cc40 mov r1, r5
 *   @0x14cc44 ldr r0, [pc, #0x10]
 *   @0x14cc48 add r0, pc, r0
 *   @0x14cc4c pop {r4, r5, r6, lr}
 *   @0x14cc50 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cc54 eoreq r0, r10, r8, lsl #27
 *   @0x14cc58 ldrsheq r7, [pc], -r4
 *   @0x14cc5c mulseq pc, r12, r1
 *
 * ══ §85/137 F_YoYo_SetGUISize(RValue&, CInstance*, CInstance*, int, RValue*)  0x157718  size 220  55 条（0x157718..0x1577f4）
 * @func 0x157718 0x1577f4  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x157730→0x5425a5, 0x157740→0x3f50d0, 0x157748→0x3f50c8, 0x15774c→0x3f50c4, 0x157760→0x3f50cc, 0x157768→0x3f50c0, 0x15776c→0x3f50bc, 0x157778→0x5425a4
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Calc_GUI_Scale()
 * 字段偏移 top8: 0x8c×2 / 0x78×2 / 0x28×1 / 0xa0×1 / 0x9c×1 / 0x90×1 / 0x7c×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157718 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x15771c mov r1, #0
 *   @0x157720 ldr r6, [sp, #0x28]
 *   @0x157724 mov r5, r0
 *   @0x157728 ldr r4, [pc, #0xa0]
 *   @0x15772c mov r9, #0
 *   @0x157730 ldr r10, [pc, #0x9c]
 *   @0x157734 mov r0, r6
 *   @0x157738 add r4, pc, r4
 *   @0x15773c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x157740 ldr r3, [pc, #0x90]
 *   @0x157744 mov r1, #1
 *   @0x157748 ldr r8, [pc, #0x8c]
 *   @0x15774c ldr r7, [pc, #0x8c]
 *   @0x157750 ldr r3, [r4, r3]
 *   @0x157754 str r0, [r3]
 *   @0x157758 mov r0, r6
 *   @0x15775c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x157760 ldr r1, [pc, #0x7c]
 *   @0x157764 mov r2, #1325400064
 *   @0x157768 ldr r6, [pc, #0x78]
 *   @0x15776c ldr r12, [pc, #0x78]
 *   @0x157770 mov r3, #1065353216
 *   @0x157774 ldr r11, [r4, r1]
 *   @0x157778 ldr r1, [pc, #0x70]
 *   @0x15777c str r0, [r11]
 *   @0x157780 ldr r0, [r4, r10]
 *   @0x157784 strb r9, [r0]
 *   @0x157788 ldr r0, [r4, r8]
 *   @0x15778c str r2, [r0]
 *   @0x157790 ldr r0, [r4, r7]
 *   @0x157794 str r2, [r0]
 *   @0x157798 ldr r2, [r4, r6]
 *   @0x15779c str r3, [r2]
 *   @0x1577a0 ldr r2, [r4, r12]
 *   @0x1577a4 str r3, [r2]
 *   @0x1577a8 ldr r3, [r4, r1]
 *   @0x1577ac ldrb r3, [r3]
 *   @0x1577b0 cmp r3, r9
 *   @0x1577b4 beq 0x1577bc <_Z17F_YoYo_SetGUISizeR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1577b8 bl 0x1b3204 <_Z14Calc_GUI_Scalev>
 *   @0x1577bc mov r3, #0
 *   @0x1577c0 str r3, [r5, #0xc]
 *   @0x1577c4 str r3, [r5]
 *   @0x1577c8 str r3, [r5, #0x4]
 *   @0x1577cc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1577d0 eoreq r10, r9, r8, lsl r5
 *   @0x1577d4 .word 0xffffdf14
 *   @0x1577d8 .word 0xffffdf18
 *   @0x1577dc .word 0xffffdf1c
 *   @0x1577e0 .word 0xffffdf20
 *   @0x1577e4 .word 0xffffdf24
 *   @0x1577e8 .word 0xffffdf28
 *   @0x1577ec .word 0xffffdf2c
 *   @0x1577f0 .word 0xffffdf30
 *
 * ══ §86/137 CBitmap32::SetAlphaFromBitmap(CBitmap32*)  0x1672d0  size 220  55 条（0x1672d0..0x1673ac）
 * @func 0x1672d0 0x1673ac  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::SetAlphaFromBitmap(CBitmap32*)+0xd0 / CBitmap32::SetAlphaFromBitmap(CBitmap32*)+0xc0
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0x2×3 / 0xc×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1672d0 ldrb r3, [r0, #0x4]
 *   @0x1672d4 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x1672d8 cmp r3, #0
 *   @0x1672dc sub sp, sp, #8
 *   @0x1672e0 beq 0x1673a0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0xd0>
 *   @0x1672e4 cmp r1, #0
 *   @0x1672e8 beq 0x1673a0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0xd0>
 *   @0x1672ec ldr r2, [r0, #0xc]
 *   @0x1672f0 ldr r10, [r1, #0xc]
 *   @0x1672f4 ldr r3, [r0, #0x8]
 *   @0x1672f8 ldr r7, [r1, #0x8]
 *   @0x1672fc cmp r10, r2
 *   @0x167300 movge r10, r2
 *   @0x167304 str r10, [sp, #0x4]
 *   @0x167308 cmp r7, r3
 *   @0x16730c movge r7, r3
 *   @0x167310 cmp r10, #0
 *   @0x167314 ble 0x1673a0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0xd0>
 *   @0x167318 movw r9, #0xaaab
 *   @0x16731c movt r9, #0xaaaa
 *   @0x167320 mov r5, #0
 *   @0x167324 cmp r7, #0
 *   @0x167328 ble 0x167390 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0xc0>
 *   @0x16732c ldr r8, [r1, #0x14]
 *   @0x167330 mov r3, #0
 *   @0x167334 ldr r6, [r0, #0x14]
 *   @0x167338 ldr r2, [r1, #0x8]
 *   @0x16733c ldr r12, [r0, #0x8]
 *   @0x167340 mla r2, r2, r5, r3
 *   @0x167344 mla r12, r12, r5, r3
 *   @0x167348 add r3, r3, #1
 *   @0x16734c ldr r2, [r8, r2, lsl #2]
 *   @0x167350 ubfx r4, r2, #0x10, #0x8
 *   @0x167354 ubfx r11, r2, #0x8, #0x8
 *   @0x167358 add r11, r11, r4
 *   @0x16735c ldr r4, [r6, r12, lsl #2]
 *   @0x167360 uxtab r2, r11, r2
 *   @0x167364 and r11, r4, #-16777216
 *   @0x167368 bic r4, r4, #-16777216
 *   @0x16736c umull r10, r2, r9, r2
 *   @0x167370 lsr r2, r2, #1
 *   @0x167374 lsl r2, r2, #24
 *   @0x167378 cmp r2, r11
 *   @0x16737c addls r4, r4, r2
 *   @0x167380 addhi r4, r4, r11
 *   @0x167384 cmp r3, r7
 *   @0x167388 str r4, [r6, r12, lsl #2]
 *   @0x16738c bne 0x167338 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0x68>
 *   @0x167390 ldr r3, [sp, #0x4]
 *   @0x167394 add r5, r5, #1
 *   @0x167398 cmp r5, r3
 *   @0x16739c bne 0x167324 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0x54>
 *   @0x1673a0 add sp, sp, #8
 *   @0x1673a4 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x1673a8 bx lr
 *
 * ══ §87/137 _GetCPUSideTextureData(Texture*, bool&)  0x182da0  size 220  55 条（0x182da0..0x182e7c）
 * @func 0x182da0 0x182e7c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadPNGFile(void*, int, int*, int*, bool)
 * 字段偏移 top8: 0x2c×2 / 0x70×2 / 0xc×2 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182da0 ldr r3, [r0, #0x2c]
 *   @0x182da4 push {r4, r5, lr}
 *   @0x182da8 mov r4, #0
 *   @0x182dac cmp r3, r4
 *   @0x182db0 sub sp, sp, #20
 *   @0x182db4 mov r5, r1
 *   @0x182db8 strb r4, [r1]
 *   @0x182dbc ldreq r0, [r0, #0x28]
 *   @0x182dc0 beq 0x182e20 <_Z22_GetCPUSideTextureDataP7TextureRb+0x80>
 *   @0x182dc4 ldr r12, [r3]
 *   @0x182dc8 movw r2, #0x4152
 *   @0x182dcc movt r2, #0x2057
 *   @0x182dd0 cmp r12, r2
 *   @0x182dd4 beq 0x182e34 <_Z22_GetCPUSideTextureDataP7TextureRb+0x94>
 *   @0x182dd8 movw r2, #0x5089
 *   @0x182ddc movt r2, #0x474e
 *   @0x182de0 cmp r12, r2
 *   @0x182de4 beq 0x182e4c <_Z22_GetCPUSideTextureDataP7TextureRb+0xac>
 *   @0x182de8 ldr r2, [r3, #0x2c]
 *   @0x182dec movw r3, #0x5650
 *   @0x182df0 movt r3, #0x2152
 *   @0x182df4 cmp r2, r3
 *   @0x182df8 beq 0x182e28 <_Z22_GetCPUSideTextureDataP7TextureRb+0x88>
 *   @0x182dfc ldr r3, [pc, #0x70]
 *   @0x182e00 ldr r1, [pc, #0x70]
 *   @0x182e04 ldr r3, [pc, r3]
 *   @0x182e08 add r1, pc, r1
 *   @0x182e0c ldr r0, [r3]
 *   @0x182e10 ldr r3, [r0]
 *   @0x182e14 ldr r3, [r3, #0xc]
 *   @0x182e18 blx r3
 *   @0x182e1c mov r0, r4
 *   @0x182e20 add sp, sp, #20
 *   @0x182e24 pop {r4, r5, pc}
 *   @0x182e28 mov r0, r4
 *   @0x182e2c add sp, sp, #20
 *   @0x182e30 pop {r4, r5, pc}
 *   @0x182e34 ldr r2, [r3, #0xc]
 *   @0x182e38 cmp r2, #1
 *   @0x182e3c beq 0x182e28 <_Z22_GetCPUSideTextureDataP7TextureRb+0x88>
 *   @0x182e40 add r0, r3, #16
 *   @0x182e44 add sp, sp, #20
 *   @0x182e48 pop {r4, r5, pc}
 *   @0x182e4c ldr r1, [r0, #0x30]
 *   @0x182e50 add r2, sp, #8
 *   @0x182e54 mov r0, r3
 *   @0x182e58 str r4, [sp]
 *   @0x182e5c add r3, sp, #12
 *   @0x182e60 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b>
 *   @0x182e64 cmp r0, #0
 *   @0x182e68 movne r3, #1
 *   @0x182e6c strbne r3, [r5]
 *   @0x182e70 b 0x182e20 <_Z22_GetCPUSideTextureDataP7TextureRb+0x80>
 *   @0x182e74 eoreq r10, r6, r0, lsl r9
 *   @0x182e78 andseq r8, r12, r12, ror #25
 *
 * ══ §88/137 Graphics::CopySurface(void*, int, int, int, void*)  0x183000  size 220  55 条（0x183000..0x1830dc）
 * @func 0x183000 0x1830dc  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::CopySurface(void*, int, int, int, void*)+0x88 / 0xb65bc / _CreateTextureIfInvalid(Texture*, bool, eMipEnable) / 0xb65b0
 * 字段偏移 top8: 0x34×2 / 0x8×1 / 0x20×1 / 0x4×1 / 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183000 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x183004 mov r9, r0
 *   @0x183008 ldr r0, [r0, #0x8]
 *   @0x18300c mov r7, r2
 *   @0x183010 mov r4, r3
 *   @0x183014 ldr r5, [sp, #0x20]
 *   @0x183018 cmp r0, #0
 *   @0x18301c beq 0x18302c <_ZN8Graphics11CopySurfaceEPviiiS0_+0x2c>
 *   @0x183020 ldr r8, [r9, #0x4]
 *   @0x183024 cmp r8, #0
 *   @0x183028 bne 0x183034 <_ZN8Graphics11CopySurfaceEPviiiS0_+0x34>
 *   @0x18302c mov r0, #1
 *   @0x183030 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x183034 cmp r3, #0
 *   @0x183038 cmpne r2, #0
 *   @0x18303c movne r1, #0
 *   @0x183040 moveq r1, #1
 *   @0x183044 beq 0x18302c <_ZN8Graphics11CopySurfaceEPviiiS0_+0x2c>
 *   @0x183048 cmp r8, r7
 *   @0x18304c cmple r0, r4
 *   @0x183050 ldr r6, [r9, #0x28]
 *   @0x183054 bgt 0x1830c0 <_ZN8Graphics11CopySurfaceEPviiiS0_+0xc0>
 *   @0x183058 cmp r4, #0
 *   @0x18305c lslgt r7, r7, #2
 *   @0x183060 lslgt r8, r8, #2
 *   @0x183064 ble 0x183088 <_ZN8Graphics11CopySurfaceEPviiiS0_+0x88>
 *   @0x183068 mov r0, r6
 *   @0x18306c mov r1, r5
 *   @0x183070 mov r2, r7
 *   @0x183074 add r6, r6, r8
 *   @0x183078 bl 0xb65bc <memcpy@plt>
 *   @0x18307c subs r4, r4, #1
 *   @0x183080 add r5, r5, r7
 *   @0x183084 bne 0x183068 <_ZN8Graphics11CopySurfaceEPviiiS0_+0x68>
 *   @0x183088 mov r0, r9
 *   @0x18308c mvn r2, #0
 *   @0x183090 mov r1, #1
 *   @0x183094 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable>
 *   @0x183098 ldr r3, [pc, #0x34]
 *   @0x18309c ldr r1, [pc, #0x34]
 *   @0x1830a0 ldr r3, [pc, r3]
 *   @0x1830a4 add r1, pc, r1
 *   @0x1830a8 ldr r0, [r3]
 *   @0x1830ac ldr r3, [r0]
 *   @0x1830b0 ldr r3, [r3, #0xc]
 *   @0x1830b4 blx r3
 *   @0x1830b8 mov r0, #1
 *   @0x1830bc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1830c0 mul r2, r8, r0
 *   @0x1830c4 mov r0, r6
 *   @0x1830c8 lsl r2, r2, #2
 *   @0x1830cc bl 0xb65b0 <memset@plt>
 *   @0x1830d0 b 0x183058 <_ZN8Graphics11CopySurfaceEPviiiS0_+0x58>
 *   @0x1830d4 eoreq r10, r6, r4, ror r6
 *   @0x1830d8 andseq r8, r12, r8, asr #21
 *
 * ══ §89/137 GMGamePad::UpdateCounts(int, int)  0x18e69c  size 220  55 条（0x18e69c..0x18e778）
 * @func 0x18e69c 0x18e778  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×4
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x10×2 / 0x8×2 / 0x14×2 / 0x18×2 / 0xb0×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e69c ldr r3, [r0, #0x4]
 *   @0x18e6a0 push {r4, r5, r6, r7, r8, lr}
 *   @0x18e6a4 cmp r3, r1
 *   @0x18e6a8 sub sp, sp, #8
 *   @0x18e6ac mov r4, r0
 *   @0x18e6b0 mov r5, r2
 *   @0x18e6b4 beq 0x18e708 <_ZN9GMGamePad12UpdateCountsEii+0x6c>
 *   @0x18e6b8 ldr r6, [pc, #0xb0]
 *   @0x18e6bc lsl r7, r1, #2
 *   @0x18e6c0 ldr r0, [r0, #0xc]
 *   @0x18e6c4 mov r8, #0
 *   @0x18e6c8 add r6, pc, r6
 *   @0x18e6cc str r1, [r4, #0x4]
 *   @0x18e6d0 mov r3, #74
 *   @0x18e6d4 mov r1, r7
 *   @0x18e6d8 mov r2, r6
 *   @0x18e6dc str r8, [sp]
 *   @0x18e6e0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x18e6e4 ldr r12, [r4, #0x10]
 *   @0x18e6e8 mov r1, r7
 *   @0x18e6ec str r8, [sp]
 *   @0x18e6f0 mov r2, r6
 *   @0x18e6f4 mov r3, #74
 *   @0x18e6f8 str r0, [r4, #0xc]
 *   @0x18e6fc mov r0, r12
 *   @0x18e700 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x18e704 str r0, [r4, #0x10]
 *   @0x18e708 ldr r3, [r4, #0x8]
 *   @0x18e70c cmp r3, r5
 *   @0x18e710 beq 0x18e768 <_ZN9GMGamePad12UpdateCountsEii+0xcc>
 *   @0x18e714 ldr r3, [pc, #0x58]
 *   @0x18e718 lsl r6, r5, #2
 *   @0x18e71c str r5, [r4, #0x8]
 *   @0x18e720 mov r7, #0
 *   @0x18e724 add r3, pc, r3
 *   @0x18e728 ldr r0, [r4, #0x14]
 *   @0x18e72c mov r1, r6
 *   @0x18e730 str r7, [sp]
 *   @0x18e734 mov r2, r3
 *   @0x18e738 mov r5, r3
 *   @0x18e73c mov r3, #74
 *   @0x18e740 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x18e744 ldr r12, [r4, #0x18]
 *   @0x18e748 mov r1, r6
 *   @0x18e74c str r7, [sp]
 *   @0x18e750 mov r2, r5
 *   @0x18e754 mov r3, #74
 *   @0x18e758 str r0, [r4, #0x14]
 *   @0x18e75c mov r0, r12
 *   @0x18e760 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x18e764 str r0, [r4, #0x18]
 *   @0x18e768 add sp, sp, #8
 *   @0x18e76c pop {r4, r5, r6, r7, r8, pc}
 *   @0x18e770 andseq sp, r11, r8, ror r12
 *   @0x18e774 andseq sp, r11, r12, lsl r12
 *
 * ══ §90/137 F_LayerGetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x1baeac  size 220  55 条（0x1baeac..0x1baf88）
 * @func 0x1baeac 0x1baf88  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x18×2 / 0x4×2 / 0xa4×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1baeac cmp r3, #1
 *   @0x1baeb0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1baeb4 mov r4, #0
 *   @0x1baeb8 mov r5, r0
 *   @0x1baebc ldr r6, [sp, #0x18]
 *   @0x1baec0 str r4, [r0, #0xc]
 *   @0x1baec4 str r4, [r0]
 *   @0x1baec8 str r4, [r0, #0x4]
 *   @0x1baecc beq 0x1baee4 <_Z17F_LayerGetVisibleR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1baed0 ldr r0, [pc, #0xa4]
 *   @0x1baed4 mov r1, r4
 *   @0x1baed8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1baedc add r0, pc, r0
 *   @0x1baee0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1baee4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1baee8 ldr r3, [r6, #0xc]
 *   @0x1baeec mov r1, r4
 *   @0x1baef0 bic r3, r3, #-16777216
 *   @0x1baef4 cmp r3, #1
 *   @0x1baef8 mov r7, r0
 *   @0x1baefc mov r0, r6
 *   @0x1baf00 beq 0x1baf40 <_Z17F_LayerGetVisibleR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x1baf04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1baf08 mov r1, r0
 *   @0x1baf0c mov r0, r7
 *   @0x1baf10 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1baf14 cmp r0, #0
 *   @0x1baf18 beq 0x1baf54 <_Z17F_LayerGetVisibleR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1baf1c ldrb r3, [r0, #0x18]
 *   @0x1baf20 cmp r3, #0
 *   @0x1baf24 movne r2, #0
 *   @0x1baf28 moveq r2, r3
 *   @0x1baf2c movne r3, r2
 *   @0x1baf30 movtne r2, #0x3ff0
 *   @0x1baf34 str r3, [r5]
 *   @0x1baf38 str r2, [r5, #0x4]
 *   @0x1baf3c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1baf40 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1baf44 mov r1, r0
 *   @0x1baf48 mov r0, r7
 *   @0x1baf4c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1baf50 b 0x1baf14 <_Z17F_LayerGetVisibleR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x1baf54 ldr r3, [pc, #0x24]
 *   @0x1baf58 mov r2, r0
 *   @0x1baf5c ldr r1, [pc, #0x20]
 *   @0x1baf60 ldr r3, [pc, r3]
 *   @0x1baf64 add r1, pc, r1
 *   @0x1baf68 ldr r0, [r3]
 *   @0x1baf6c ldr r3, [r0]
 *   @0x1baf70 ldr r3, [r3, #0xc]
 *   @0x1baf74 blx r3
 *   @0x1baf78 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1baf7c andseq r2, r9, r12, lsl #21
 *   @0x1baf80 .word 0x002327b4
 *   @0x1baf84 andseq r2, r9, r4, lsr r10
 *
 * ══ §91/137 VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int)  0x1e2440  size 220  55 条（0x1e2440..0x1e251c）
 * @func 0x1e2440 0x1e251c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VertexFormat::GetTypeSize(yyVertexType)×2 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int)+0xcc
 * 字段偏移 top8: 0x8×5 / 0x4×4 / 0x10×2 / 0x18×2 / 0xb4×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2440 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e2444 mov r6, r0
 *   @0x1e2448 ldr r7, [r0, #0x4]
 *   @0x1e244c sub sp, sp, #12
 *   @0x1e2450 ldr r0, [r0, #0x8]
 *   @0x1e2454 mov r8, r2
 *   @0x1e2458 add r11, r7, #1
 *   @0x1e245c ldr r2, [pc, #0xb4]
 *   @0x1e2460 str r11, [r6, #0x4]
 *   @0x1e2464 mov r4, #0
 *   @0x1e2468 lsl r11, r11, #4
 *   @0x1e246c mov r10, r1
 *   @0x1e2470 mov r9, r3
 *   @0x1e2474 str r4, [sp]
 *   @0x1e2478 mov r3, #74
 *   @0x1e247c mov r1, r11
 *   @0x1e2480 add r2, pc, r2
 *   @0x1e2484 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1e2488 cmp r7, r4
 *   @0x1e248c str r0, [r6, #0x8]
 *   @0x1e2490 ble 0x1e250c <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej+0xcc>
 *   @0x1e2494 mov r5, r4
 *   @0x1e2498 b 0x1e24a0 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej+0x60>
 *   @0x1e249c ldr r0, [r6, #0x8]
 *   @0x1e24a0 add r0, r0, r4, lsl #4
 *   @0x1e24a4 add r4, r4, #1
 *   @0x1e24a8 ldr r0, [r0, #0x4]
 *   @0x1e24ac bl 0x1e23d8 <_ZN12VertexFormat11GetTypeSizeE12yyVertexType>
 *   @0x1e24b0 cmp r4, r7
 *   @0x1e24b4 add r5, r5, r0
 *   @0x1e24b8 bne 0x1e249c <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej+0x5c>
 *   @0x1e24bc ldr r2, [r6, #0x8]
 *   @0x1e24c0 sub r11, r11, #16
 *   @0x1e24c4 ldr r1, [r6, #0x10]
 *   @0x1e24c8 add r3, r2, r11
 *   @0x1e24cc mov r0, r10
 *   @0x1e24d0 str r5, [r2, r11]
 *   @0x1e24d4 orr r2, r1, r9
 *   @0x1e24d8 str r10, [r3, #0x4]
 *   @0x1e24dc str r8, [r3, #0x8]
 *   @0x1e24e0 str r9, [r3, #0xc]
 *   @0x1e24e4 str r2, [r6, #0x10]
 *   @0x1e24e8 bl 0x1e23d8 <_ZN12VertexFormat11GetTypeSizeE12yyVertexType>
 *   @0x1e24ec ldr r3, [r6, #0x18]
 *   @0x1e24f0 mov r2, #1
 *   @0x1e24f4 orr r8, r3, r2, lsl r8
 *   @0x1e24f8 str r8, [r6, #0x18]
 *   @0x1e24fc add r0, r0, r5
 *   @0x1e2500 str r0, [r6, #0x14]
 *   @0x1e2504 add sp, sp, #12
 *   @0x1e2508 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e250c mov r2, r0
 *   @0x1e2510 mov r5, r4
 *   @0x1e2514 b 0x1e24c0 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej+0x80>
 *   @0x1e2518 ldrheq lr, [r4], -r0
 *
 * ══ §92/137 CSprite::LoadFromData(void*, int, int, int, bool, bool, bool, int, int, bool)  0x1e6fd4  size 220  55 条（0x1e6fd4..0x1e70b0）
 * @func 0x1e6fd4 0x1e70b0  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBitmapLoader::Create(void*, int, int) / CSprite::LoadFromAnimation(IBitmapLoader*, bool, bool) / CSprite::InitTexture() / CSprite::InitLocalTPE() / CSprite::ComputeBoundingBox() / CSprite::CreateMask() / CSprite::LoadStrip(IBitmapLoader*, bool, bool, int, bool)
 * 字段偏移 top8: 0x4×3 / 0x34×2 / 0x30×2 / 0x38×1 / 0x3c×1 / 0x40×1 / 0x44×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e6fd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e6fd8 sub sp, sp, #12
 *   @0x1e6fdc mov r4, r0
 *   @0x1e6fe0 mov r0, r1
 *   @0x1e6fe4 mov r1, r2
 *   @0x1e6fe8 mov r2, r3
 *   @0x1e6fec ldrb r8, [sp, #0x34]
 *   @0x1e6ff0 ldrb r10, [sp, #0x38]
 *   @0x1e6ff4 ldrb r9, [sp, #0x3c]
 *   @0x1e6ff8 ldr r7, [sp, #0x40]
 *   @0x1e6ffc ldr r6, [sp, #0x44]
 *   @0x1e7000 ldrb r11, [sp, #0x48]
 *   @0x1e7004 bl 0x1a928c <_ZN13IBitmapLoader6CreateEPvii>
 *   @0x1e7008 ldr r3, [r0]
 *   @0x1e700c mov r5, r0
 *   @0x1e7010 ldr r3, [r3, #0x8]
 *   @0x1e7014 blx r3
 *   @0x1e7018 cmp r0, #0
 *   @0x1e701c beq 0x1e708c <_ZN7CSprite12LoadFromDataEPviiibbbiib+0xb8>
 *   @0x1e7020 mov r2, r10
 *   @0x1e7024 mov r3, r9
 *   @0x1e7028 mov r0, r4
 *   @0x1e702c mov r1, r5
 *   @0x1e7030 bl 0x1e6cb0 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb>
 *   @0x1e7034 ldr r3, [r5]
 *   @0x1e7038 mov r0, r5
 *   @0x1e703c mov r5, #1
 *   @0x1e7040 ldr r3, [r3, #0x4]
 *   @0x1e7044 blx r3
 *   @0x1e7048 mov r3, #0
 *   @0x1e704c mov r0, r4
 *   @0x1e7050 str r3, [r4, #0x4]
 *   @0x1e7054 strb r8, [r4, #0x30]
 *   @0x1e7058 str r7, [r4, #0x24]
 *   @0x1e705c str r6, [r4, #0x28]
 *   @0x1e7060 strb r5, [r4, #0x34]
 *   @0x1e7064 bl 0x1e5748 <_ZN7CSprite11InitTextureEv>
 *   @0x1e7068 mov r0, r4
 *   @0x1e706c bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv>
 *   @0x1e7070 mov r0, r4
 *   @0x1e7074 bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv>
 *   @0x1e7078 mov r0, r4
 *   @0x1e707c bl 0x1e3bcc <_ZN7CSprite10CreateMaskEv>
 *   @0x1e7080 mov r0, r5
 *   @0x1e7084 add sp, sp, #12
 *   @0x1e7088 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e708c ldr r3, [sp, #0x30]
 *   @0x1e7090 mov r2, r10
 *   @0x1e7094 str r11, [sp, #0x4]
 *   @0x1e7098 mov r0, r4
 *   @0x1e709c mov r1, r5
 *   @0x1e70a0 str r3, [sp]
 *   @0x1e70a4 mov r3, r9
 *   @0x1e70a8 bl 0x1e6e04 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib>
 *   @0x1e70ac b 0x1e7034 <_ZN7CSprite12LoadFromDataEPviiibbbiib+0x60>
 *
 * ══ §93/137 _BuildLineList(char*, int)  0x212f10  size 220  55 条（0x212f10..0x212fec）
 * @func 0x212f10 0x212fec  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _BuildLineList(char*, int)+0xd0 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x1×2 / 0x-1×2 / 0xac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x212f10 push {r3, r4, r5, r6, r7, lr}
 *   @0x212f14 subs r7, r0, #0
 *   @0x212f18 beq 0x212fe0 <_Z14_BuildLineListPci+0xd0>
 *   @0x212f1c ldrb r0, [r7]
 *   @0x212f20 cmp r0, #0
 *   @0x212f24 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x212f28 cmp r1, #0
 *   @0x212f2c ble 0x212fe0 <_Z14_BuildLineListPci+0xd0>
 *   @0x212f30 lsl r0, r1, #2
 *   @0x212f34 ldr r1, [pc, #0xac]
 *   @0x212f38 mov r3, #1
 *   @0x212f3c mov r2, #236
 *   @0x212f40 add r1, pc, r1
 *   @0x212f44 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x212f48 ldrb r3, [r7]
 *   @0x212f4c cmp r3, #0
 *   @0x212f50 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x212f54 mov r4, #0
 *   @0x212f58 add r2, r7, #1
 *   @0x212f5c mov r5, r4
 *   @0x212f60 mov r6, r4
 *   @0x212f64 mov r12, r7
 *   @0x212f68 mov r1, #1
 *   @0x212f6c b 0x212f9c <_Z14_BuildLineListPci+0x8c>
 *   @0x212f70 cmp r3, #10
 *   @0x212f74 beq 0x212fc8 <_Z14_BuildLineListPci+0xb8>
 *   @0x212f78 cmp r1, #0
 *   @0x212f7c mov r4, r1
 *   @0x212f80 strne r12, [r0, r5, lsl #2]
 *   @0x212f84 movne r1, #0
 *   @0x212f88 movne r4, r1
 *   @0x212f8c ldrb r3, [r12, #0x1]!
 *   @0x212f90 add r2, r2, #1
 *   @0x212f94 cmp r3, #0
 *   @0x212f98 beq 0x212fc4 <_Z14_BuildLineListPci+0xb4>
 *   @0x212f9c cmp r3, #13
 *   @0x212fa0 bne 0x212f70 <_Z14_BuildLineListPci+0x60>
 *   @0x212fa4 strb r6, [r2, #-0x1]
 *   @0x212fa8 mov r1, #1
 *   @0x212fac ldrb r3, [r12, #0x1]!
 *   @0x212fb0 add r5, r5, r1
 *   @0x212fb4 mov r4, r1
 *   @0x212fb8 add r2, r2, #1
 *   @0x212fbc cmp r3, #0
 *   @0x212fc0 bne 0x212f9c <_Z14_BuildLineListPci+0x8c>
 *   @0x212fc4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x212fc8 cmp r4, #0
 *   @0x212fcc mov r1, #1
 *   @0x212fd0 mov r4, #0
 *   @0x212fd4 addeq r5, r5, r1
 *   @0x212fd8 strb r6, [r2, #-0x1]
 *   @0x212fdc b 0x212f8c <_Z14_BuildLineListPci+0x7c>
 *   @0x212fe0 mov r0, #0
 *   @0x212fe4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x212fe8 andseq r0, r4, r8, asr #20
 *
 * ══ §94/137 deviceListClear()  0x21c470  size 220  55 条（0x21c470..0x21c54c）
 * @func 0x21c470 0x21c54c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / deviceListClear()+0xac / operator delete(void*) / deviceListClear()+0x34
 * 字段偏移 top8: 0x4×5 / 0xcc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21c470 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x21c474 ldr r7, [pc, #0xcc]
 *   @0x21c478 ldr r7, [pc, r7]
 *   @0x21c47c ldr r3, [r7]
 *   @0x21c480 cmp r3, #0
 *   @0x21c484 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21c488 ldr r5, [r7, #0x4]
 *   @0x21c48c cmp r5, #0
 *   @0x21c490 beq 0x21c538 <_Z15deviceListClearv+0xc8>
 *   @0x21c494 cmp r3, #0
 *   @0x21c498 ble 0x21c51c <_Z15deviceListClearv+0xac>
 *   @0x21c49c mov r4, #0
 *   @0x21c4a0 mov r8, r4
 *   @0x21c4a4 ldr r1, [r5]
 *   @0x21c4a8 movw r3, #0xfeee
 *   @0x21c4ac movt r3, #0xfeee
 *   @0x21c4b0 movw r2, #0xfeee
 *   @0x21c4b4 cmp r1, r3
 *   @0x21c4b8 movt r2, #0xfeee
 *   @0x21c4bc lsl r9, r4, #2
 *   @0x21c4c0 beq 0x21c50c <_Z15deviceListClearv+0x9c>
 *   @0x21c4c4 ldr r6, [r5, r4, lsl #2]
 *   @0x21c4c8 add r1, r5, r9
 *   @0x21c4cc cmp r6, #0
 *   @0x21c4d0 beq 0x21c50c <_Z15deviceListClearv+0x9c>
 *   @0x21c4d4 ldr r3, [r6]
 *   @0x21c4d8 cmp r3, r2
 *   @0x21c4dc mov r0, r3
 *   @0x21c4e0 beq 0x21c504 <_Z15deviceListClearv+0x94>
 *   @0x21c4e4 cmp r3, #0
 *   @0x21c4e8 beq 0x21c4f4 <_Z15deviceListClearv+0x84>
 *   @0x21c4ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21c4f0 str r8, [r6]
 *   @0x21c4f4 mov r0, r6
 *   @0x21c4f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x21c4fc ldr r1, [r7, #0x4]
 *   @0x21c500 add r1, r1, r9
 *   @0x21c504 str r8, [r1]
 *   @0x21c508 ldr r5, [r7, #0x4]
 *   @0x21c50c ldr r3, [r7]
 *   @0x21c510 add r4, r4, #1
 *   @0x21c514 cmp r4, r3
 *   @0x21c518 blt 0x21c4a4 <_Z15deviceListClearv+0x34>
 *   @0x21c51c mov r0, r5
 *   @0x21c520 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21c524 mov r3, #0
 *   @0x21c528 str r3, [r7, #0x4]
 *   @0x21c52c mov r3, #0
 *   @0x21c530 str r3, [r7]
 *   @0x21c534 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21c538 mov r0, r5
 *   @0x21c53c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21c540 str r5, [r7, #0x4]
 *   @0x21c544 b 0x21c52c <_Z15deviceListClearv+0xbc>
 *   @0x21c548 andseq r4, sp, r0, lsl #31
 *
 * ══ §95/137 COggAudio::GetSyncGroupTrackPos(int)  0x226934  size 220  55 条（0x226934..0x226a10）
 * @func 0x226934 0x226a10  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::GetSyncGroupTrackPos(int)+0xa0 / 0xb6a9c / COggAudio::GetSyncGroupTrackPos(int)+0xbc / __floatdisf / COggAudio::CalcSoundInfo(cAudio_Sound*)
 * 字段偏移 top8: 0x4×2 / 0x804×2 / 0x2bc×2 / 0x10×1 / 0x2×1 / 0x86c×1 / 0x-4×1 / 0x38×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226934 ldr r3, [r0, #0x4]
 *   @0x226938 push {r4, r5, lr}
 *   @0x22693c vpush {d8}
 *   @0x226940 cmp r3, r1
 *   @0x226944 sub sp, sp, #12
 *   @0x226948 mov r5, r0
 *   @0x22694c ble 0x2269d4 <_ZN9COggAudio20GetSyncGroupTrackPosEi+0xa0>
 *   @0x226950 ldr r3, [r0, #0x10]
 *   @0x226954 ldr r4, [r3, r1, lsl #2]
 *   @0x226958 cmp r4, #0
 *   @0x22695c beq 0x2269d4 <_ZN9COggAudio20GetSyncGroupTrackPosEi+0xa0>
 *   @0x226960 add r2, sp, #8
 *   @0x226964 mov r3, #0
 *   @0x226968 movw r1, #0x1025
 *   @0x22696c ldr r0, [r4, #0x86c]
 *   @0x226970 str r3, [r2, #-0x4]!
 *   @0x226974 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x226978 ldr r3, [r4, #0x804]
 *   @0x22697c ldr r1, [r3, #0x2bc]
 *   @0x226980 cmp r1, #0
 *   @0x226984 beq 0x2269e8 <_ZN9COggAudio20GetSyncGroupTrackPosEi+0xb4>
 *   @0x226988 ldr r3, [r1, #0x38]
 *   @0x22698c cmp r3, #0
 *   @0x226990 ble 0x2269f0 <_ZN9COggAudio20GetSyncGroupTrackPosEi+0xbc>
 *   @0x226994 vmov s14, r3
 *   @0x226998 vcvt.f32.s32 s16, s14
 *   @0x22699c movw r3, #0x818
 *   @0x2269a0 ldr r0, [sp, #0x4]
 *   @0x2269a4 ldrd r2, r3, [r3, r4]
 *   @0x2269a8 adds r4, r2, r0
 *   @0x2269ac adc r5, r3, r0, asr #31
 *   @0x2269b0 mov r0, r4
 *   @0x2269b4 mov r1, r5
 *   @0x2269b8 bl 0x319398 <__floatdisf>
 *   @0x2269bc vmov s14, r0
 *   @0x2269c0 vdiv.f32 s15, s14, s16
 *   @0x2269c4 vmov r0, s15
 *   @0x2269c8 add sp, sp, #12
 *   @0x2269cc vpop {d8}
 *   @0x2269d0 pop {r4, r5, pc}
 *   @0x2269d4 vmov.f32 s15, #-1.000000e+00
 *   @0x2269d8 vmov r0, s15
 *   @0x2269dc add sp, sp, #12
 *   @0x2269e0 vpop {d8}
 *   @0x2269e4 pop {r4, r5, pc}
 *   @0x2269e8 vldr s16, [pc, #28]
 *   @0x2269ec b 0x22699c <_ZN9COggAudio20GetSyncGroupTrackPosEi+0x68>
 *   @0x2269f0 mov r0, r5
 *   @0x2269f4 bl 0x22688c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound>
 *   @0x2269f8 ldr r3, [r4, #0x804]
 *   @0x2269fc ldr r3, [r3, #0x2bc]
 *   @0x226a00 vldr s16, [r3, #56]
 *   @0x226a04 vcvt.f32.s32 s16, s16
 *   @0x226a08 b 0x22699c <_ZN9COggAudio20GetSyncGroupTrackPosEi+0x68>
 *   @0x226a0c strmi r4, [r12, -r0, lsl #8]!
 *
 * ══ §96/137 CPhysicsJoint::EnableMotor(bool)  0x23b534  size 220  55 条（0x23b534..0x23b610）
 * @func 0x23b534 0x23b610  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×8 / 0x30×3 / 0x34×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23b534 ldr r0, [r0, #0x4]
 *   @0x23b538 cmp r0, #0
 *   @0x23b53c bxeq lr
 *   @0x23b540 ldr r3, [r0, #0x4]
 *   @0x23b544 cmp r3, #2
 *   @0x23b548 beq 0x23b5d4 <_ZN13CPhysicsJoint11EnableMotorEb+0xa0>
 *   @0x23b54c cmp r3, #7
 *   @0x23b550 beq 0x23b598 <_ZN13CPhysicsJoint11EnableMotorEb+0x64>
 *   @0x23b554 cmp r3, #1
 *   @0x23b558 bxne lr
 *   @0x23b55c ldr r3, [r0, #0x30]
 *   @0x23b560 ldrh r2, [r3, #4]
 *   @0x23b564 tst r2, #2
 *   @0x23b568 orreq r2, r2, #2
 *   @0x23b56c strheq r2, [r3, #4]
 *   @0x23b570 moveq r12, #0
 *   @0x23b574 streq r12, [r3, #0xa0]
 *   @0x23b578 ldr r3, [r0, #0x34]
 *   @0x23b57c ldrh r2, [r3, #4]
 *   @0x23b580 tst r2, #2
 *   @0x23b584 orreq r2, r2, #2
 *   @0x23b588 strheq r2, [r3, #4]
 *   @0x23b58c moveq r12, #0
 *   @0x23b590 streq r12, [r3, #0xa0]
 *   @0x23b594 b 0x2d214c <_ZN15b2RevoluteJoint11EnableMotorEb>
 *   @0x23b598 ldr r3, [r0, #0x30]
 *   @0x23b59c ldrh r2, [r3, #4]
 *   @0x23b5a0 tst r2, #2
 *   @0x23b5a4 orreq r2, r2, #2
 *   @0x23b5a8 strheq r2, [r3, #4]
 *   @0x23b5ac moveq r12, #0
 *   @0x23b5b0 streq r12, [r3, #0xa0]
 *   @0x23b5b4 ldr r3, [r0, #0x34]
 *   @0x23b5b8 ldrh r2, [r3, #4]
 *   @0x23b5bc tst r2, #2
 *   @0x23b5c0 orreq r2, r2, #2
 *   @0x23b5c4 strheq r2, [r3, #4]
 *   @0x23b5c8 moveq r12, #0
 *   @0x23b5cc streq r12, [r3, #0xa0]
 *   @0x23b5d0 b 0x2d43a4 <_ZN12b2WheelJoint11EnableMotorEb>
 *   @0x23b5d4 ldr r3, [r0, #0x30]
 *   @0x23b5d8 ldrh r2, [r3, #4]
 *   @0x23b5dc tst r2, #2
 *   @0x23b5e0 orreq r2, r2, #2
 *   @0x23b5e4 strheq r2, [r3, #4]
 *   @0x23b5e8 moveq r12, #0
 *   @0x23b5ec streq r12, [r3, #0xa0]
 *   @0x23b5f0 ldr r3, [r0, #0x34]
 *   @0x23b5f4 ldrh r2, [r3, #4]
 *   @0x23b5f8 tst r2, #2
 *   @0x23b5fc orreq r2, r2, #2
 *   @0x23b600 strheq r2, [r3, #4]
 *   @0x23b604 moveq r12, #0
 *   @0x23b608 streq r12, [r3, #0xa0]
 *   @0x23b60c b 0x2d043c <_ZN16b2PrismaticJoint11EnableMotorEb>
 *
 * ══ §97/137 JS_Function_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*)  0x24e770  size 220  55 条（0x24e770..0x24e84c）
 * @func 0x24e770 0x24e84c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65c8×2 / 0xb6574 / YYStrDup(char const*) / YYCreateString(RValue*, char const*) / JSThrowTypeError(char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0xb8×1 / 0xb4×1 / 0x40×1 / 0x64×1 / 0x7c×1 / 0x14×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24e770 push {r4, r5, r6, lr}
 *   @0x24e774 mov r5, r1
 *   @0x24e778 ldr r4, [pc, #0xb8]
 *   @0x24e77c sub sp, sp, #1024
 *   @0x24e780 ldr r1, [pc, #0xb4]
 *   @0x24e784 sub sp, sp, #8
 *   @0x24e788 ldr r4, [pc, r4]
 *   @0x24e78c mov r6, r0
 *   @0x24e790 add r1, pc, r1
 *   @0x24e794 ldr r0, [r5, #0x40]
 *   @0x24e798 ldr r3, [r4]
 *   @0x24e79c str r3, [sp, #0x404]
 *   @0x24e7a0 bl 0xb6574 <strcmp@plt>
 *   @0x24e7a4 cmp r0, #0
 *   @0x24e7a8 bne 0x24e804 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x24e7ac ldr r3, [r5, #0x64]
 *   @0x24e7b0 cmp r3, #0
 *   @0x24e7b4 beq 0x24e814 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x24e7b8 add r5, sp, #4
 *   @0x24e7bc ldr r2, [pc, #0x7c]
 *   @0x24e7c0 ldr r3, [r3, #0x14]
 *   @0x24e7c4 mov r1, #1024
 *   @0x24e7c8 add r2, pc, r2
 *   @0x24e7cc mov r0, r5
 *   @0x24e7d0 bl 0xb65c8 <snprintf@plt>
 *   @0x24e7d4 mov r0, r5
 *   @0x24e7d8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x24e7dc mov r1, r0
 *   @0x24e7e0 mov r0, r6
 *   @0x24e7e4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x24e7e8 ldr r2, [sp, #0x404]
 *   @0x24e7ec ldr r3, [r4]
 *   @0x24e7f0 cmp r2, r3
 *   @0x24e7f4 bne 0x24e834 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x24e7f8 add sp, sp, #1024
 *   @0x24e7fc add sp, sp, #8
 *   @0x24e800 pop {r4, r5, r6, pc}
 *   @0x24e804 ldr r0, [pc, #0x38]
 *   @0x24e808 add r0, pc, r0
 *   @0x24e80c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24e810 b 0x24e7e8 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x24e814 ldr r3, [r5, #0x68]
 *   @0x24e818 add r5, sp, #4
 *   @0x24e81c ldr r2, [pc, #0x24]
 *   @0x24e820 mov r1, #1024
 *   @0x24e824 mov r0, r5
 *   @0x24e828 add r2, pc, r2
 *   @0x24e82c bl 0xb65c8 <snprintf@plt>
 *   @0x24e830 b 0x24e7d4 <_Z30JS_Function_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x24e834 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x24e838 andseq pc, r9, r8, asr #3
 *   @0x24e83c andseq r6, r0, r4, asr #27
 *   @0x24e840 andseq r7, r0, r12, lsl #15
 *   @0x24e844 andseq r7, r0, r0, asr #14
 *   @0x24e848 andseq r7, r0, r0, asr #14
 *
 * ══ §98/137 WriteData(Buffer_Standard*, unsigned char const*, int)  0x29e730  size 220  55 条（0x29e730..0x29e80c）
 * @func 0x29e730 0x29e80c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WriteData(Buffer_Standard*, unsigned char const*, int)+0x8c
 * 字段偏移 top8: 0x38×3 / 0x30×3 / 0x8×3 / 0x1×1 / 0x2c×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29e730 vmov s15, r2
 *   @0x29e734 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29e738 vcvt.f64.u32 d7, s15
 *   @0x29e73c ldr r3, [r0]
 *   @0x29e740 add r8, r0, #44
 *   @0x29e744 mov r6, r0
 *   @0x29e748 mov r9, r2
 *   @0x29e74c mov r7, r1
 *   @0x29e750 mov r10, #0
 *   @0x29e754 mov r1, #5
 *   @0x29e758 str r10, [r0, #0x38]
 *   @0x29e75c mov r2, r8
 *   @0x29e760 vmov r4, r5, d7
 *   @0x29e764 vstr s14, [r6, #44]
 *   @0x29e768 str r5, [r6, #0x30]
 *   @0x29e76c ldr r3, [r3, #0x8]
 *   @0x29e770 blx r3
 *   @0x29e774 cmp r9, r10
 *   @0x29e778 addgt r11, r7, r9
 *   @0x29e77c ble 0x29e7bc <_Z9WriteDataP15Buffer_StandardPKhi+0x8c>
 *   @0x29e780 ldrb r4, [r7], #1
 *   @0x29e784 mov r0, r6
 *   @0x29e788 ldr r3, [r6]
 *   @0x29e78c mov r1, #1
 *   @0x29e790 str r10, [r6, #0x38]
 *   @0x29e794 mov r2, r8
 *   @0x29e798 vmov s15, r4
 *   @0x29e79c vcvt.f64.u32 d7, s15
 *   @0x29e7a0 vmov r4, r5, d7
 *   @0x29e7a4 vstr s14, [r6, #44]
 *   @0x29e7a8 str r5, [r6, #0x30]
 *   @0x29e7ac ldr r3, [r3, #0x8]
 *   @0x29e7b0 blx r3
 *   @0x29e7b4 cmp r7, r11
 *   @0x29e7b8 bne 0x29e780 <_Z9WriteDataP15Buffer_StandardPKhi+0x50>
 *   @0x29e7bc add r3, r9, #3
 *   @0x29e7c0 bic r3, r3, #3
 *   @0x29e7c4 rsb r9, r9, r3
 *   @0x29e7c8 cmp r9, #0
 *   @0x29e7cc pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29e7d0 mov r4, #0
 *   @0x29e7d4 mov r5, r4
 *   @0x29e7d8 ldr r3, [r6]
 *   @0x29e7dc add r4, r4, #1
 *   @0x29e7e0 str r5, [r6, #0x2c]
 *   @0x29e7e4 mov r0, r6
 *   @0x29e7e8 str r5, [r6, #0x30]
 *   @0x29e7ec mov r1, #1
 *   @0x29e7f0 str r5, [r6, #0x38]
 *   @0x29e7f4 mov r2, r8
 *   @0x29e7f8 ldr r3, [r3, #0x8]
 *   @0x29e7fc blx r3
 *   @0x29e800 cmp r4, r9
 *   @0x29e804 bne 0x29e7d8 <_Z9WriteDataP15Buffer_StandardPKhi+0xa8>
 *   @0x29e808 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §99/137 jinit_d_post_controller  0x2b840c  size 220  55 条（0x2b840c..0x2b84e8）
 * @func 0x2b840c 0x2b84e8  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jround_up
 * 字段偏移 top8: 0x4×4 / 0x8×3 / 0x10×3 / 0xc×2 / 0x64×2 / 0x5c×2 / 0xac×1 / 0x18c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b840c ldr r3, [r0, #0x4]
 *   @0x2b8410 mov r2, #28
 *   @0x2b8414 push {r4, r5, r6, r7, r8, lr}
 *   @0x2b8418 mov r7, r1
 *   @0x2b841c ldr r3, [r3]
 *   @0x2b8420 sub sp, sp, #8
 *   @0x2b8424 mov r1, #1
 *   @0x2b8428 mov r4, r0
 *   @0x2b842c blx r3
 *   @0x2b8430 ldr r3, [pc, #0xac]
 *   @0x2b8434 mov r6, #0
 *   @0x2b8438 add r3, pc, r3
 *   @0x2b843c str r0, [r4, #0x18c]
 *   @0x2b8440 mov r5, r0
 *   @0x2b8444 str r6, [r0, #0x8]
 *   @0x2b8448 str r3, [r0]
 *   @0x2b844c str r6, [r0, #0xc]
 *   @0x2b8450 ldrb r3, [r4, #0x4a]
 *   @0x2b8454 cmp r3, r6
 *   @0x2b8458 beq 0x2b8490 <jinit_d_post_controller+0x84>
 *   @0x2b845c ldr r3, [r4, #0x114]
 *   @0x2b8460 cmp r7, r6
 *   @0x2b8464 str r3, [r0, #0x10]
 *   @0x2b8468 bne 0x2b8498 <jinit_d_post_controller+0x8c>
 *   @0x2b846c ldr r12, [r4, #0x4]
 *   @0x2b8470 mov r0, r4
 *   @0x2b8474 ldr r2, [r4, #0x64]
 *   @0x2b8478 mov r1, #1
 *   @0x2b847c ldr lr, [r4, #0x5c]
 *   @0x2b8480 ldr r12, [r12, #0x8]
 *   @0x2b8484 mul r2, lr, r2
 *   @0x2b8488 blx r12
 *   @0x2b848c str r0, [r5, #0xc]
 *   @0x2b8490 add sp, sp, #8
 *   @0x2b8494 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b8498 ldr r2, [r4, #0x4]
 *   @0x2b849c mov r1, r3
 *   @0x2b84a0 ldr r8, [r4, #0x5c]
 *   @0x2b84a4 ldr r3, [r4, #0x64]
 *   @0x2b84a8 ldr r0, [r4, #0x60]
 *   @0x2b84ac ldr r7, [r2, #0x10]
 *   @0x2b84b0 mul r8, r8, r3
 *   @0x2b84b4 bl 0x2bc800 <jround_up>
 *   @0x2b84b8 mov r2, r6
 *   @0x2b84bc mov r1, #1
 *   @0x2b84c0 mov r3, r8
 *   @0x2b84c4 str r0, [sp]
 *   @0x2b84c8 mov r0, r4
 *   @0x2b84cc ldr r12, [r5, #0x10]
 *   @0x2b84d0 str r12, [sp, #0x4]
 *   @0x2b84d4 blx r7
 *   @0x2b84d8 str r0, [r5, #0x8]
 *   @0x2b84dc add sp, sp, #8
 *   @0x2b84e0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b84e4 .word 0xfffffc44
 *
 * ══ §100/137 DGifCloseFile(GifFileType*)  0x2c24e4  size 220  55 条（0x2c24e4..0x2c25c0）
 * @func 0x2c24e4 0x2c25c0  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GifFreeMapObject(ColorMapObject*)×2 / 0xb655c×2 / GifFreeSavedImages(GifFileType*) / GifFreeExtensions(int*, ExtensionBlock**) / 0xb6850
 * 字段偏移 top8: 0x48×3 / 0x30×2 / 0x14×2 / 0x34×2 / 0x40×2 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c24e4 push {r4, lr}
 *   @0x2c24e8 subs r4, r0, #0
 *   @0x2c24ec beq 0x2c25b8 <_Z13DGifCloseFileP11GifFileType+0xd4>
 *   @0x2c24f0 ldr r0, [r4, #0x48]
 *   @0x2c24f4 cmp r0, #0
 *   @0x2c24f8 popeq {r4, pc}
 *   @0x2c24fc ldr r0, [r4, #0x30]
 *   @0x2c2500 cmp r0, #0
 *   @0x2c2504 beq 0x2c2514 <_Z13DGifCloseFileP11GifFileType+0x30>
 *   @0x2c2508 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c250c mov r3, #0
 *   @0x2c2510 str r3, [r4, #0x30]
 *   @0x2c2514 ldr r0, [r4, #0x14]
 *   @0x2c2518 cmp r0, #0
 *   @0x2c251c beq 0x2c252c <_Z13DGifCloseFileP11GifFileType+0x48>
 *   @0x2c2520 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c2524 mov r3, #0
 *   @0x2c2528 str r3, [r4, #0x14]
 *   @0x2c252c ldr r3, [r4, #0x34]
 *   @0x2c2530 cmp r3, #0
 *   @0x2c2534 beq 0x2c2548 <_Z13DGifCloseFileP11GifFileType+0x64>
 *   @0x2c2538 mov r0, r4
 *   @0x2c253c bl 0x2c3234 <_Z18GifFreeSavedImagesP11GifFileType>
 *   @0x2c2540 mov r3, #0
 *   @0x2c2544 str r3, [r4, #0x34]
 *   @0x2c2548 add r0, r4, #56
 *   @0x2c254c add r1, r4, #60
 *   @0x2c2550 bl 0x2c2ff8 <_Z17GifFreeExtensionsPiPP14ExtensionBlock>
 *   @0x2c2554 ldr r3, [r4, #0x48]
 *   @0x2c2558 ldr r0, [r3]
 *   @0x2c255c ands r0, r0, #8
 *   @0x2c2560 beq 0x2c2594 <_Z13DGifCloseFileP11GifFileType+0xb0>
 *   @0x2c2564 ldr r0, [r3, #0x38]
 *   @0x2c2568 cmp r0, #0
 *   @0x2c256c beq 0x2c25b0 <_Z13DGifCloseFileP11GifFileType+0xcc>
 *   @0x2c2570 bl 0xb6850 <fclose@plt>
 *   @0x2c2574 cmp r0, #0
 *   @0x2c2578 bne 0x2c25a0 <_Z13DGifCloseFileP11GifFileType+0xbc>
 *   @0x2c257c ldr r0, [r4, #0x48]
 *   @0x2c2580 bl 0xb655c <free@plt>
 *   @0x2c2584 mov r0, r4
 *   @0x2c2588 bl 0xb655c <free@plt>
 *   @0x2c258c mov r0, #1
 *   @0x2c2590 pop {r4, pc}
 *   @0x2c2594 mov r3, #111
 *   @0x2c2598 str r3, [r4, #0x40]
 *   @0x2c259c pop {r4, pc}
 *   @0x2c25a0 mov r3, #110
 *   @0x2c25a4 mov r0, #0
 *   @0x2c25a8 str r3, [r4, #0x40]
 *   @0x2c25ac pop {r4, pc}
 *   @0x2c25b0 mov r0, r3
 *   @0x2c25b4 b 0x2c2580 <_Z13DGifCloseFileP11GifFileType+0x9c>
 *   @0x2c25b8 mov r0, r4
 *   @0x2c25bc pop {r4, pc}
 *
 * ══ §101/137 anon_31a51c  0x31a51c  size 220  55 条（0x31a51c..0x31a5f8）
 * @func 0x31a51c 0x31a5f8  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a51c fldmiax r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x31a520 bx lr
 *   @0x31a524 fstmiax r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x31a528 bx lr
 *   @0x31a52c vldmia r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x31a530 bx lr
 *   @0x31a534 vstmia r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x31a538 bx lr
 *   @0x31a53c vldmia r0, {d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31}
 *   @0x31a540 bx lr
 *   @0x31a544 vstmia r0, {d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31}
 *   @0x31a548 bx lr
 *   @0x31a54c ldcl p1, c0, [r0], #8
 *   @0x31a550 ldcl p1, c1, [r0], #8
 *   @0x31a554 ldcl p1, c2, [r0], #8
 *   @0x31a558 ldcl p1, c3, [r0], #8
 *   @0x31a55c ldcl p1, c4, [r0], #8
 *   @0x31a560 ldcl p1, c5, [r0], #8
 *   @0x31a564 ldcl p1, c6, [r0], #8
 *   @0x31a568 ldcl p1, c7, [r0], #8
 *   @0x31a56c ldcl p1, c8, [r0], #8
 *   @0x31a570 ldcl p1, c9, [r0], #8
 *   @0x31a574 ldcl p1, c10, [r0], #8
 *   @0x31a578 ldcl p1, c11, [r0], #8
 *   @0x31a57c ldcl p1, c12, [r0], #8
 *   @0x31a580 ldcl p1, c13, [r0], #8
 *   @0x31a584 ldcl p1, c14, [r0], #8
 *   @0x31a588 ldcl p1, c15, [r0], #8
 *   @0x31a58c bx lr
 *   @0x31a590 stcl p1, c0, [r0], #8
 *   @0x31a594 stcl p1, c1, [r0], #8
 *   @0x31a598 stcl p1, c2, [r0], #8
 *   @0x31a59c stcl p1, c3, [r0], #8
 *   @0x31a5a0 stcl p1, c4, [r0], #8
 *   @0x31a5a4 stcl p1, c5, [r0], #8
 *   @0x31a5a8 stcl p1, c6, [r0], #8
 *   @0x31a5ac stcl p1, c7, [r0], #8
 *   @0x31a5b0 stcl p1, c8, [r0], #8
 *   @0x31a5b4 stcl p1, c9, [r0], #8
 *   @0x31a5b8 stcl p1, c10, [r0], #8
 *   @0x31a5bc stcl p1, c11, [r0], #8
 *   @0x31a5c0 stcl p1, c12, [r0], #8
 *   @0x31a5c4 stcl p1, c13, [r0], #8
 *   @0x31a5c8 stcl p1, c14, [r0], #8
 *   @0x31a5cc stcl p1, c15, [r0], #8
 *   @0x31a5d0 bx lr
 *   @0x31a5d4 ldc2 p1, c8, [r0], #4
 *   @0x31a5d8 ldc2 p1, c9, [r0], #4
 *   @0x31a5dc ldc2 p1, c10, [r0], #4
 *   @0x31a5e0 ldc2 p1, c11, [r0], #4
 *   @0x31a5e4 bx lr
 *   @0x31a5e8 stc2 p1, c8, [r0], #4
 *   @0x31a5ec stc2 p1, c9, [r0], #4
 *   @0x31a5f0 stc2 p1, c10, [r0], #4
 *   @0x31a5f4 stc2 p1, c11, [r0], #4
 *
 * ══ §102/137 png_do_write_swap_alpha  0x2b0c58  size 218  55 条（0x2b0c58..0x2b0d32）
 * @func 0x2b0c58 0x2b0d32  size 218  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-2×5 / 0x-1×4 / 0x-4×3 / 0x-3×3 / 0x9×2 / 0x-7×2 / 0x-5×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0c58 push {r4, r5, lr}
 *   @0x2b0c5c cmp r3, #0x6
 *   @0x2b0c60 ldrb r3, [r0, #0x9]
 *   @0x2b0c64 cmp r3, #0x8
 *   @0x2b0c68 tstle r3, r0, lsl #6
 *   @0x2b0c6c cmp r3, r2
 *   @0x2b0c70 ldrb r4, [r1, #0x1]
 *   @0x2b0c74 ldrb r0, [r1]
 *   @0x2b0c78 strb r4, [r1, #-4]
 *   @0x2b0c7c ldrb r4, [r1, #-2]
 *   @0x2b0c80 strb r4, [r1, #-3]
 *   @0x2b0c84 ldrb r4, [r1, #-1]
 *   @0x2b0c88 strb r0, [r1, #-1]
 *   @0x2b0c8c strb r4, [r1, #-2]
 *   @0x2b0c90 b 0x2b0c6c <png_do_write_swap_alpha+0x14>
 *   @0x2b0c94 cmp r3, r2
 *   @0x2b0c98 ldrb r5, [r1, #0x2]
 *   @0x2b0c9c ldrb r4, [r1]
 *   @0x2b0ca0 ldrb r0, [r1, #-7]
 *   @0x2b0ca4 strb r5, [r1, #-8]
 *   @0x2b0ca8 ldrb r5, [r1, #-5]
 *   @0x2b0cac strb r5, [r1, #-7]
 *   @0x2b0cb0 ldrb r5, [r1, #-4]
 *   @0x2b0cb4 strb r5, [r1, #-6]
 *   @0x2b0cb8 ldrb r5, [r1, #-3]
 *   @0x2b0cbc strb r5, [r1, #-5]
 *   @0x2b0cc0 ldrb r5, [r1, #-2]
 *   @0x2b0cc4 strb r4, [r1, #-2]
 *   @0x2b0cc8 strb r5, [r1, #-4]
 *   @0x2b0ccc ldrb r5, [r1, #-1]
 *   @0x2b0cd0 strb r0, [r1, #-1]
 *   @0x2b0cd4 strb r5, [r1, #-3]
 *   @0x2b0cd8 b 0x2b0c94 <png_do_write_swap_alpha+0x3c>
 *   @0x2b0cdc cmp r3, #0x4
 *   @0x2b0ce0 ldrb r3, [r0, #0x9]
 *   @0x2b0ce4 cmp r3, #0x8
 *   @0x2b0ce8 .word 0xd10e0300
 *   @0x2b0cec cmp r3, r2
 *   @0x2b0cf0 andle r0, r9, r2, lsl #2
 *   @0x2b0cf4 ldrb r0, [r1, #-2]
 *   @0x2b0cf8 adds r3, #0x1
 *   @0x2b0cfc .word 0xf8014c01
 *   @0x2b0d00 .word 0xf8010c01
 *   @0x2b0d04 ldrb r4, [r1, r2, lsl #24]!
 *   @0x2b0d08 pop {r4, r5, pc}
 *   @0x2b0d0c beq 0x2b0d30 <png_do_write_swap_alpha+0xd8>
 *   @0x2b0d10 adds r3, #0x1
 *   @0x2b0d14 adds r1, #0x4
 *   @0x2b0d18 .word 0xf8010c03
 *   @0x2b0d1c .word 0xf8115c04
 *   @0x2b0d20 .word 0xf8015c01
 *   @0x2b0d24 .word 0xf8014c02
 *   @0x2b0d28 .word 0xf8010c01
 *   @0x2b0d2c strb r5, [r12, r3, lsl #24]!
 *   @0x2b0d30 pop {r4, r5, pc}
 *
 * ══ §103/137 F_Vertex_Float1_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc7cb4  size 216  54 条（0xc7cb4..0xc7d8c）
 * @func 0xc7cb4 0xc7d8c  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Vertex_Float1_release(RValue&, CInstance*, CInstance*, int, RValue*)+0x98 / YYGetFloat(RValue const*, int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x18×2 / 0x4×2 / 0x14×2 / 0x10×2 / 0xc0×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7cb4 push {r4, r5, lr}
 *   @0xc7cb8 sub sp, sp, #12
 *   @0xc7cbc ldr r3, [pc, #0xc0]
 *   @0xc7cc0 mov r1, #0
 *   @0xc7cc4 ldr r5, [sp, #0x18]
 *   @0xc7cc8 add r3, pc, r3
 *   @0xc7ccc mov r0, r5
 *   @0xc7cd0 ldr r4, [r3]
 *   @0xc7cd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc7cd8 ldr r4, [r4, r0, lsl #2]
 *   @0xc7cdc ldr r1, [r4, #0x2c]
 *   @0xc7ce0 ldr r3, [r4, #0xc]
 *   @0xc7ce4 ldr r2, [r4, #0x4]
 *   @0xc7ce8 ldr r1, [r1, #0x14]
 *   @0xc7cec add r0, r1, r3
 *   @0xc7cf0 cmp r2, r0
 *   @0xc7cf4 blo 0xc7d4c <_Z23F_Vertex_Float1_releaseR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xc7cf8 ldr r2, [r4]
 *   @0xc7cfc mov r0, r5
 *   @0xc7d00 mov r1, #1
 *   @0xc7d04 add r5, r2, r3
 *   @0xc7d08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7d0c ldr r2, [r4, #0x10]
 *   @0xc7d10 ldr r1, [r4, #0x14]
 *   @0xc7d14 add r2, r2, #1
 *   @0xc7d18 ldr r3, [r4, #0xc]
 *   @0xc7d1c cmp r2, r1
 *   @0xc7d20 add r3, r3, #4
 *   @0xc7d24 str r0, [r5]
 *   @0xc7d28 str r3, [r4, #0xc]
 *   @0xc7d2c ldrhs r3, [r4, #0x1c]
 *   @0xc7d30 str r2, [r4, #0x10]
 *   @0xc7d34 movhs r2, #0
 *   @0xc7d38 addhs r3, r3, #1
 *   @0xc7d3c strhs r2, [r4, #0x10]
 *   @0xc7d40 strhs r3, [r4, #0x1c]
 *   @0xc7d44 add sp, sp, #12
 *   @0xc7d48 pop {r4, r5, pc}
 *   @0xc7d4c add r1, r1, r2
 *   @0xc7d50 ldr r0, [r4]
 *   @0xc7d54 add r1, r1, r2, lsr #1
 *   @0xc7d58 mov r2, #0
 *   @0xc7d5c str r1, [r4, #0x4]
 *   @0xc7d60 mov r3, #74
 *   @0xc7d64 str r2, [sp]
 *   @0xc7d68 ldr r2, [pc, #0x18]
 *   @0xc7d6c add r2, pc, r2
 *   @0xc7d70 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc7d74 ldr r3, [r4, #0xc]
 *   @0xc7d78 mov r2, r0
 *   @0xc7d7c str r0, [r4]
 *   @0xc7d80 b 0xc7cfc <_Z23F_Vertex_Float1_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc7d84 eorseq r2, r11, r12, ror #8
 *   @0xc7d88 eoreq r9, r6, r4, asr #5
 *
 * ══ §104/137 IBuffer::Resize(int)  0xcbf1c  size 216  54 条（0xcbf1c..0xcbff4）
 * @func 0xcbf1c 0xcbff4  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / IBuffer::Resize(int)+0xc8 / 0xb65bc / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x10×5 / 0x14×2 / 0xc×2 / 0x4×2 / 0xac×1 / 0x8×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcbf1c push {r3, r4, r5, r6, r7, lr}
 *   @0xcbf20 mov r4, r0
 *   @0xcbf24 ldr r0, [r0, #0x14]
 *   @0xcbf28 movw r2, #0x53a
 *   @0xcbf2c ldr r5, [r4, #0x10]
 *   @0xcbf30 mov r3, #0
 *   @0xcbf34 add r0, r1, r0
 *   @0xcbf38 str r1, [r4, #0x10]
 *   @0xcbf3c ldr r1, [pc, #0xac]
 *   @0xcbf40 str r0, [r4, #0x8]
 *   @0xcbf44 add r1, pc, r1
 *   @0xcbf48 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcbf4c ldr r3, [r4, #0x14]
 *   @0xcbf50 ldr r2, [r4, #0x10]
 *   @0xcbf54 sub r6, r3, #1
 *   @0xcbf58 rsb r3, r3, #0
 *   @0xcbf5c cmp r5, r2
 *   @0xcbf60 movge r5, r2
 *   @0xcbf64 cmp r5, #0
 *   @0xcbf68 add r6, r0, r6
 *   @0xcbf6c mov r7, r0
 *   @0xcbf70 and r6, r6, r3
 *   @0xcbf74 mov r0, r6
 *   @0xcbf78 ble 0xcbfe4 <_ZN7IBuffer6ResizeEi+0xc8>
 *   @0xcbf7c ldr r1, [r4, #0xc]
 *   @0xcbf80 mov r2, r5
 *   @0xcbf84 bl 0xb65bc <memcpy@plt>
 *   @0xcbf88 ldr r2, [r4, #0x10]
 *   @0xcbf8c add r0, r6, r5
 *   @0xcbf90 mov r1, #0
 *   @0xcbf94 rsb r2, r5, r2
 *   @0xcbf98 bl 0xb65b0 <memset@plt>
 *   @0xcbf9c ldr r0, [r4, #0x4]
 *   @0xcbfa0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcbfa4 ldr r3, [r4, #0x1c]
 *   @0xcbfa8 ldr r2, [r4, #0x10]
 *   @0xcbfac str r7, [r4, #0x4]
 *   @0xcbfb0 cmp r3, r2
 *   @0xcbfb4 str r6, [r4, #0xc]
 *   @0xcbfb8 movge r1, #0
 *   @0xcbfbc movge r3, r1
 *   @0xcbfc0 strge r1, [r4, #0x1c]
 *   @0xcbfc4 strge r1, [r4, #0x24]
 *   @0xcbfc8 ldr r1, [r4, #0x20]
 *   @0xcbfcc cmp r3, r1
 *   @0xcbfd0 movlt r3, r1
 *   @0xcbfd4 cmp r3, r2
 *   @0xcbfd8 strle r3, [r4, #0x20]
 *   @0xcbfdc strgt r2, [r4, #0x20]
 *   @0xcbfe0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xcbfe4 mov r1, #0
 *   @0xcbfe8 bl 0xb65b0 <memset@plt>
 *   @0xcbfec b 0xcbf9c <_ZN7IBuffer6ResizeEi+0x80>
 *   @0xcbff0 eoreq r6, r6, r12, lsr #4
 *
 * ══ §105/137 F_DsGridSetRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd438  size 216  54 条（0xfd438..0xfd510）
 * @func 0xfd438 0xfd510  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridSetRegion(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Region_Operation(int, int, int, int, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd438 push {r4, r5, r6, r7, r8, lr}
 *   @0xfd43c sub sp, sp, #16
 *   @0xfd440 mov r1, #0
 *   @0xfd444 ldr r4, [sp, #0x28]
 *   @0xfd448 mov r0, r4
 *   @0xfd44c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd450 mov r1, #1
 *   @0xfd454 mov r5, r0
 *   @0xfd458 mov r0, r4
 *   @0xfd45c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd460 mov r1, #2
 *   @0xfd464 mov r7, r0
 *   @0xfd468 mov r0, r4
 *   @0xfd46c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd470 mov r1, #3
 *   @0xfd474 mov r6, r0
 *   @0xfd478 mov r0, r4
 *   @0xfd47c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd480 mov r1, #4
 *   @0xfd484 mov r8, r0
 *   @0xfd488 mov r0, r4
 *   @0xfd48c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd490 cmp r5, #0
 *   @0xfd494 mov r2, r0
 *   @0xfd498 blt 0xfd4ec <_Z17F_DsGridSetRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd49c ldr r1, [pc, #0x60]
 *   @0xfd4a0 ldr r1, [pc, r1]
 *   @0xfd4a4 ldr r1, [r1]
 *   @0xfd4a8 cmp r5, r1
 *   @0xfd4ac bge 0xfd4ec <_Z17F_DsGridSetRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd4b0 ldr r1, [pc, #0x50]
 *   @0xfd4b4 ldr r1, [pc, r1]
 *   @0xfd4b8 ldr r3, [r1, #0x4]
 *   @0xfd4bc ldr r0, [r3, r5, lsl #2]
 *   @0xfd4c0 cmp r0, #0
 *   @0xfd4c4 beq 0xfd4ec <_Z17F_DsGridSetRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd4c8 add r4, r4, #80
 *   @0xfd4cc str r8, [sp]
 *   @0xfd4d0 stmib sp, {r2, r4}
 *   @0xfd4d4 mov r3, r6
 *   @0xfd4d8 mov r2, r7
 *   @0xfd4dc mov r1, #1
 *   @0xfd4e0 bl 0x207db4 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue>
 *   @0xfd4e4 add sp, sp, #16
 *   @0xfd4e8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xfd4ec ldr r0, [pc, #0x18]
 *   @0xfd4f0 mov r1, #0
 *   @0xfd4f4 add r0, pc, r0
 *   @0xfd4f8 add sp, sp, #16
 *   @0xfd4fc pop {r4, r5, r6, r7, r8, lr}
 *   @0xfd500 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd504 eoreq r0, pc, r4, ror #19
 *   @0xfd508 .word 0x002f09d4
 *   @0xfd50c eoreq r10, r3, r8, lsl #14
 *
 * ══ §106/137 F_DsGridAddRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd510  size 216  54 条（0xfd510..0xfd5e8）
 * @func 0xfd510 0xfd5e8  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridAddRegion(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Region_Operation(int, int, int, int, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd510 push {r4, r5, r6, r7, r8, lr}
 *   @0xfd514 sub sp, sp, #16
 *   @0xfd518 mov r1, #0
 *   @0xfd51c ldr r4, [sp, #0x28]
 *   @0xfd520 mov r0, r4
 *   @0xfd524 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd528 mov r1, #1
 *   @0xfd52c mov r5, r0
 *   @0xfd530 mov r0, r4
 *   @0xfd534 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd538 mov r1, #2
 *   @0xfd53c mov r7, r0
 *   @0xfd540 mov r0, r4
 *   @0xfd544 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd548 mov r1, #3
 *   @0xfd54c mov r6, r0
 *   @0xfd550 mov r0, r4
 *   @0xfd554 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd558 mov r1, #4
 *   @0xfd55c mov r8, r0
 *   @0xfd560 mov r0, r4
 *   @0xfd564 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd568 cmp r5, #0
 *   @0xfd56c mov r2, r0
 *   @0xfd570 blt 0xfd5c4 <_Z17F_DsGridAddRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd574 ldr r1, [pc, #0x60]
 *   @0xfd578 ldr r1, [pc, r1]
 *   @0xfd57c ldr r1, [r1]
 *   @0xfd580 cmp r5, r1
 *   @0xfd584 bge 0xfd5c4 <_Z17F_DsGridAddRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd588 ldr r1, [pc, #0x50]
 *   @0xfd58c ldr r1, [pc, r1]
 *   @0xfd590 ldr r3, [r1, #0x4]
 *   @0xfd594 ldr r0, [r3, r5, lsl #2]
 *   @0xfd598 cmp r0, #0
 *   @0xfd59c beq 0xfd5c4 <_Z17F_DsGridAddRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd5a0 add r4, r4, #80
 *   @0xfd5a4 str r8, [sp]
 *   @0xfd5a8 stmib sp, {r2, r4}
 *   @0xfd5ac mov r3, r6
 *   @0xfd5b0 mov r2, r7
 *   @0xfd5b4 mov r1, #2
 *   @0xfd5b8 bl 0x207db4 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue>
 *   @0xfd5bc add sp, sp, #16
 *   @0xfd5c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xfd5c4 ldr r0, [pc, #0x18]
 *   @0xfd5c8 mov r1, #0
 *   @0xfd5cc add r0, pc, r0
 *   @0xfd5d0 add sp, sp, #16
 *   @0xfd5d4 pop {r4, r5, r6, r7, r8, lr}
 *   @0xfd5d8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd5dc eoreq r0, pc, r12, lsl #18
 *   @0xfd5e0 .word 0x002f08fc
 *   @0xfd5e4 eoreq r10, r3, r0, lsr r6
 *
 * ══ §107/137 F_DsGridMultiplyRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd5e8  size 216  54 条（0xfd5e8..0xfd6c0）
 * @func 0xfd5e8 0xfd6c0  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridMultiplyRegion(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Region_Operation(int, int, int, int, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd5e8 push {r4, r5, r6, r7, r8, lr}
 *   @0xfd5ec sub sp, sp, #16
 *   @0xfd5f0 mov r1, #0
 *   @0xfd5f4 ldr r4, [sp, #0x28]
 *   @0xfd5f8 mov r0, r4
 *   @0xfd5fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd600 mov r1, #1
 *   @0xfd604 mov r5, r0
 *   @0xfd608 mov r0, r4
 *   @0xfd60c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd610 mov r1, #2
 *   @0xfd614 mov r7, r0
 *   @0xfd618 mov r0, r4
 *   @0xfd61c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd620 mov r1, #3
 *   @0xfd624 mov r6, r0
 *   @0xfd628 mov r0, r4
 *   @0xfd62c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd630 mov r1, #4
 *   @0xfd634 mov r8, r0
 *   @0xfd638 mov r0, r4
 *   @0xfd63c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd640 cmp r5, #0
 *   @0xfd644 mov r2, r0
 *   @0xfd648 blt 0xfd69c <_Z22F_DsGridMultiplyRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd64c ldr r1, [pc, #0x60]
 *   @0xfd650 ldr r1, [pc, r1]
 *   @0xfd654 ldr r1, [r1]
 *   @0xfd658 cmp r5, r1
 *   @0xfd65c bge 0xfd69c <_Z22F_DsGridMultiplyRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd660 ldr r1, [pc, #0x50]
 *   @0xfd664 ldr r1, [pc, r1]
 *   @0xfd668 ldr r3, [r1, #0x4]
 *   @0xfd66c ldr r0, [r3, r5, lsl #2]
 *   @0xfd670 cmp r0, #0
 *   @0xfd674 beq 0xfd69c <_Z22F_DsGridMultiplyRegionR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd678 add r4, r4, #80
 *   @0xfd67c str r8, [sp]
 *   @0xfd680 stmib sp, {r2, r4}
 *   @0xfd684 mov r3, r6
 *   @0xfd688 mov r2, r7
 *   @0xfd68c mov r1, #3
 *   @0xfd690 bl 0x207db4 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue>
 *   @0xfd694 add sp, sp, #16
 *   @0xfd698 pop {r4, r5, r6, r7, r8, pc}
 *   @0xfd69c ldr r0, [pc, #0x18]
 *   @0xfd6a0 mov r1, #0
 *   @0xfd6a4 add r0, pc, r0
 *   @0xfd6a8 add sp, sp, #16
 *   @0xfd6ac pop {r4, r5, r6, r7, r8, lr}
 *   @0xfd6b0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd6b4 eoreq r0, pc, r4, lsr r8
 *   @0xfd6b8 eoreq r0, pc, r4, lsr #16
 *   @0xfd6bc eoreq r10, r3, r8, asr r5
 *
 * ══ §108/137 F_DsGridSetDisk(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd6c0  size 216  54 条（0xfd6c0..0xfd798）
 * @func 0xfd6c0 0xfd798  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridSetDisk(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Disk_Operation(int, double, double, double, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd6c0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfd6c4 sub sp, sp, #28
 *   @0xfd6c8 mov r1, #0
 *   @0xfd6cc ldr r8, [sp, #0x38]
 *   @0xfd6d0 mov r0, r8
 *   @0xfd6d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd6d8 mov r1, #1
 *   @0xfd6dc mov r9, r0
 *   @0xfd6e0 mov r0, r8
 *   @0xfd6e4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd6e8 mov r4, r0
 *   @0xfd6ec mov r5, r1
 *   @0xfd6f0 mov r0, r8
 *   @0xfd6f4 mov r1, #2
 *   @0xfd6f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd6fc mov r6, r0
 *   @0xfd700 mov r7, r1
 *   @0xfd704 mov r0, r8
 *   @0xfd708 mov r1, #3
 *   @0xfd70c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd710 cmp r9, #0
 *   @0xfd714 mov r2, r0
 *   @0xfd718 mov r3, r1
 *   @0xfd71c blt 0xfd774 <_Z15F_DsGridSetDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd720 ldr r1, [pc, #0x64]
 *   @0xfd724 ldr r1, [pc, r1]
 *   @0xfd728 ldr r1, [r1]
 *   @0xfd72c cmp r9, r1
 *   @0xfd730 bge 0xfd774 <_Z15F_DsGridSetDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd734 ldr r1, [pc, #0x54]
 *   @0xfd738 ldr r1, [pc, r1]
 *   @0xfd73c ldr r1, [r1, #0x4]
 *   @0xfd740 ldr r0, [r1, r9, lsl #2]
 *   @0xfd744 cmp r0, #0
 *   @0xfd748 beq 0xfd774 <_Z15F_DsGridSetDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd74c strd r2, r3, [sp, #8]
 *   @0xfd750 add r8, r8, #64
 *   @0xfd754 strd r6, r7, [sp]
 *   @0xfd758 mov r2, r4
 *   @0xfd75c str r8, [sp, #0x10]
 *   @0xfd760 mov r3, r5
 *   @0xfd764 mov r1, #1
 *   @0xfd768 bl 0x207e8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue>
 *   @0xfd76c add sp, sp, #28
 *   @0xfd770 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfd774 ldr r0, [pc, #0x18]
 *   @0xfd778 mov r1, #0
 *   @0xfd77c add r0, pc, r0
 *   @0xfd780 add sp, sp, #28
 *   @0xfd784 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfd788 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd78c eoreq r0, pc, r0, ror #14
 *   @0xfd790 eoreq r0, pc, r0, asr r7
 *   @0xfd794 eoreq r10, r3, r0, lsl #9
 *
 * ══ §109/137 F_DsGridAddDisk(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd798  size 216  54 条（0xfd798..0xfd870）
 * @func 0xfd798 0xfd870  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridAddDisk(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Disk_Operation(int, double, double, double, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd798 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfd79c sub sp, sp, #28
 *   @0xfd7a0 mov r1, #0
 *   @0xfd7a4 ldr r8, [sp, #0x38]
 *   @0xfd7a8 mov r0, r8
 *   @0xfd7ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd7b0 mov r1, #1
 *   @0xfd7b4 mov r9, r0
 *   @0xfd7b8 mov r0, r8
 *   @0xfd7bc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd7c0 mov r4, r0
 *   @0xfd7c4 mov r5, r1
 *   @0xfd7c8 mov r0, r8
 *   @0xfd7cc mov r1, #2
 *   @0xfd7d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd7d4 mov r6, r0
 *   @0xfd7d8 mov r7, r1
 *   @0xfd7dc mov r0, r8
 *   @0xfd7e0 mov r1, #3
 *   @0xfd7e4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd7e8 cmp r9, #0
 *   @0xfd7ec mov r2, r0
 *   @0xfd7f0 mov r3, r1
 *   @0xfd7f4 blt 0xfd84c <_Z15F_DsGridAddDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd7f8 ldr r1, [pc, #0x64]
 *   @0xfd7fc ldr r1, [pc, r1]
 *   @0xfd800 ldr r1, [r1]
 *   @0xfd804 cmp r9, r1
 *   @0xfd808 bge 0xfd84c <_Z15F_DsGridAddDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd80c ldr r1, [pc, #0x54]
 *   @0xfd810 ldr r1, [pc, r1]
 *   @0xfd814 ldr r1, [r1, #0x4]
 *   @0xfd818 ldr r0, [r1, r9, lsl #2]
 *   @0xfd81c cmp r0, #0
 *   @0xfd820 beq 0xfd84c <_Z15F_DsGridAddDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd824 strd r2, r3, [sp, #8]
 *   @0xfd828 add r8, r8, #64
 *   @0xfd82c strd r6, r7, [sp]
 *   @0xfd830 mov r2, r4
 *   @0xfd834 str r8, [sp, #0x10]
 *   @0xfd838 mov r3, r5
 *   @0xfd83c mov r1, #2
 *   @0xfd840 bl 0x207e8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue>
 *   @0xfd844 add sp, sp, #28
 *   @0xfd848 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfd84c ldr r0, [pc, #0x18]
 *   @0xfd850 mov r1, #0
 *   @0xfd854 add r0, pc, r0
 *   @0xfd858 add sp, sp, #28
 *   @0xfd85c pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfd860 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd864 eoreq r0, pc, r8, lsl #13
 *   @0xfd868 eoreq r0, pc, r8, ror r6
 *   @0xfd86c eoreq r10, r3, r8, lsr #7
 *
 * ══ §110/137 F_DsGridMultiplyDisk(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd870  size 216  54 条（0xfd870..0xfd948）
 * @func 0xfd870 0xfd948  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridMultiplyDisk(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Disk_Operation(int, double, double, double, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd870 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfd874 sub sp, sp, #28
 *   @0xfd878 mov r1, #0
 *   @0xfd87c ldr r8, [sp, #0x38]
 *   @0xfd880 mov r0, r8
 *   @0xfd884 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd888 mov r1, #1
 *   @0xfd88c mov r9, r0
 *   @0xfd890 mov r0, r8
 *   @0xfd894 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd898 mov r4, r0
 *   @0xfd89c mov r5, r1
 *   @0xfd8a0 mov r0, r8
 *   @0xfd8a4 mov r1, #2
 *   @0xfd8a8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd8ac mov r6, r0
 *   @0xfd8b0 mov r7, r1
 *   @0xfd8b4 mov r0, r8
 *   @0xfd8b8 mov r1, #3
 *   @0xfd8bc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfd8c0 cmp r9, #0
 *   @0xfd8c4 mov r2, r0
 *   @0xfd8c8 mov r3, r1
 *   @0xfd8cc blt 0xfd924 <_Z20F_DsGridMultiplyDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd8d0 ldr r1, [pc, #0x64]
 *   @0xfd8d4 ldr r1, [pc, r1]
 *   @0xfd8d8 ldr r1, [r1]
 *   @0xfd8dc cmp r9, r1
 *   @0xfd8e0 bge 0xfd924 <_Z20F_DsGridMultiplyDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd8e4 ldr r1, [pc, #0x54]
 *   @0xfd8e8 ldr r1, [pc, r1]
 *   @0xfd8ec ldr r1, [r1, #0x4]
 *   @0xfd8f0 ldr r0, [r1, r9, lsl #2]
 *   @0xfd8f4 cmp r0, #0
 *   @0xfd8f8 beq 0xfd924 <_Z20F_DsGridMultiplyDiskR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfd8fc strd r2, r3, [sp, #8]
 *   @0xfd900 add r8, r8, #64
 *   @0xfd904 strd r6, r7, [sp]
 *   @0xfd908 mov r2, r4
 *   @0xfd90c str r8, [sp, #0x10]
 *   @0xfd910 mov r3, r5
 *   @0xfd914 mov r1, #3
 *   @0xfd918 bl 0x207e8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue>
 *   @0xfd91c add sp, sp, #28
 *   @0xfd920 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfd924 ldr r0, [pc, #0x18]
 *   @0xfd928 mov r1, #0
 *   @0xfd92c add r0, pc, r0
 *   @0xfd930 add sp, sp, #28
 *   @0xfd934 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfd938 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd93c .word 0x002f05b0
 *   @0xfd940 eoreq r0, pc, r0, lsr #11
 *   @0xfd944 .word 0x0023a2d0
 *
 * ══ §111/137 F_DsGridGetSum(RValue&, CInstance*, CInstance*, int, RValue*)  0xfdcc0  size 216  54 条（0xfdcc0..0xfdd98）
 * @func 0xfdcc0 0xfdd98  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridGetSum(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Get_Sum(RValue&, int, int, int, int)
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x5c×1 / 0x4c×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfdcc0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfdcc4 sub sp, sp, #12
 *   @0xfdcc8 mov r1, #0
 *   @0xfdccc mov r8, r0
 *   @0xfdcd0 ldr r4, [sp, #0x28]
 *   @0xfdcd4 mov r0, r4
 *   @0xfdcd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdcdc mov r1, #1
 *   @0xfdce0 mov r5, r0
 *   @0xfdce4 mov r0, r4
 *   @0xfdce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdcec mov r1, #2
 *   @0xfdcf0 mov r7, r0
 *   @0xfdcf4 mov r0, r4
 *   @0xfdcf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdcfc mov r1, #3
 *   @0xfdd00 mov r6, r0
 *   @0xfdd04 mov r0, r4
 *   @0xfdd08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdd0c mov r1, #4
 *   @0xfdd10 mov r9, r0
 *   @0xfdd14 mov r0, r4
 *   @0xfdd18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdd1c cmp r5, #0
 *   @0xfdd20 mov r2, r0
 *   @0xfdd24 blt 0xfdd74 <_Z14F_DsGridGetSumR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfdd28 ldr r12, [pc, #0x5c]
 *   @0xfdd2c ldr r12, [pc, r12]
 *   @0xfdd30 ldr r3, [r12]
 *   @0xfdd34 cmp r5, r3
 *   @0xfdd38 bge 0xfdd74 <_Z14F_DsGridGetSumR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfdd3c ldr r12, [pc, #0x4c]
 *   @0xfdd40 ldr r12, [pc, r12]
 *   @0xfdd44 ldr r3, [r12, #0x4]
 *   @0xfdd48 ldr r0, [r3, r5, lsl #2]
 *   @0xfdd4c cmp r0, #0
 *   @0xfdd50 beq 0xfdd74 <_Z14F_DsGridGetSumR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfdd54 str r2, [sp, #0x4]
 *   @0xfdd58 mov r1, r8
 *   @0xfdd5c str r9, [sp]
 *   @0xfdd60 mov r2, r7
 *   @0xfdd64 mov r3, r6
 *   @0xfdd68 bl 0x2041c8 <_ZN8CDS_Grid7Get_SumER6RValueiiii>
 *   @0xfdd6c add sp, sp, #12
 *   @0xfdd70 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfdd74 ldr r0, [pc, #0x18]
 *   @0xfdd78 mov r1, #0
 *   @0xfdd7c add r0, pc, r0
 *   @0xfdd80 add sp, sp, #12
 *   @0xfdd84 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfdd88 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfdd8c eoreq r0, pc, r8, asr r1
 *   @0xfdd90 eoreq r0, pc, r8, asr #2
 *   @0xfdd94 eoreq r9, r3, r0, lsl #29
 *
 * ══ §112/137 F_DsGridGetMax(RValue&, CInstance*, CInstance*, int, RValue*)  0xfdd98  size 216  54 条（0xfdd98..0xfde70）
 * @func 0xfdd98 0xfde70  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridGetMax(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Get_Max(RValue&, int, int, int, int)
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x5c×1 / 0x4c×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfdd98 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfdd9c sub sp, sp, #12
 *   @0xfdda0 mov r1, #0
 *   @0xfdda4 mov r8, r0
 *   @0xfdda8 ldr r4, [sp, #0x28]
 *   @0xfddac mov r0, r4
 *   @0xfddb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfddb4 mov r1, #1
 *   @0xfddb8 mov r5, r0
 *   @0xfddbc mov r0, r4
 *   @0xfddc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfddc4 mov r1, #2
 *   @0xfddc8 mov r7, r0
 *   @0xfddcc mov r0, r4
 *   @0xfddd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfddd4 mov r1, #3
 *   @0xfddd8 mov r6, r0
 *   @0xfdddc mov r0, r4
 *   @0xfdde0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdde4 mov r1, #4
 *   @0xfdde8 mov r9, r0
 *   @0xfddec mov r0, r4
 *   @0xfddf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfddf4 cmp r5, #0
 *   @0xfddf8 mov r2, r0
 *   @0xfddfc blt 0xfde4c <_Z14F_DsGridGetMaxR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfde00 ldr r12, [pc, #0x5c]
 *   @0xfde04 ldr r12, [pc, r12]
 *   @0xfde08 ldr r3, [r12]
 *   @0xfde0c cmp r5, r3
 *   @0xfde10 bge 0xfde4c <_Z14F_DsGridGetMaxR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfde14 ldr r12, [pc, #0x4c]
 *   @0xfde18 ldr r12, [pc, r12]
 *   @0xfde1c ldr r3, [r12, #0x4]
 *   @0xfde20 ldr r0, [r3, r5, lsl #2]
 *   @0xfde24 cmp r0, #0
 *   @0xfde28 beq 0xfde4c <_Z14F_DsGridGetMaxR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfde2c str r2, [sp, #0x4]
 *   @0xfde30 mov r1, r8
 *   @0xfde34 str r9, [sp]
 *   @0xfde38 mov r2, r7
 *   @0xfde3c mov r3, r6
 *   @0xfde40 bl 0x206924 <_ZN8CDS_Grid7Get_MaxER6RValueiiii>
 *   @0xfde44 add sp, sp, #12
 *   @0xfde48 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfde4c ldr r0, [pc, #0x18]
 *   @0xfde50 mov r1, #0
 *   @0xfde54 add r0, pc, r0
 *   @0xfde58 add sp, sp, #12
 *   @0xfde5c pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfde60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfde64 eoreq r0, pc, r0, lsl #1
 *   @0xfde68 eoreq r0, pc, r0, ror r0
 *   @0xfde6c eoreq r9, r3, r8, lsr #27
 *
 * ══ §113/137 F_DsGridGetMin(RValue&, CInstance*, CInstance*, int, RValue*)  0xfde70  size 216  54 条（0xfde70..0xfdf48）
 * @func 0xfde70 0xfdf48  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridGetMin(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Get_Min(RValue&, int, int, int, int)
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x5c×1 / 0x4c×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfde70 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfde74 sub sp, sp, #12
 *   @0xfde78 mov r1, #0
 *   @0xfde7c mov r8, r0
 *   @0xfde80 ldr r4, [sp, #0x28]
 *   @0xfde84 mov r0, r4
 *   @0xfde88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfde8c mov r1, #1
 *   @0xfde90 mov r5, r0
 *   @0xfde94 mov r0, r4
 *   @0xfde98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfde9c mov r1, #2
 *   @0xfdea0 mov r7, r0
 *   @0xfdea4 mov r0, r4
 *   @0xfdea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdeac mov r1, #3
 *   @0xfdeb0 mov r6, r0
 *   @0xfdeb4 mov r0, r4
 *   @0xfdeb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdebc mov r1, #4
 *   @0xfdec0 mov r9, r0
 *   @0xfdec4 mov r0, r4
 *   @0xfdec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdecc cmp r5, #0
 *   @0xfded0 mov r2, r0
 *   @0xfded4 blt 0xfdf24 <_Z14F_DsGridGetMinR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfded8 ldr r12, [pc, #0x5c]
 *   @0xfdedc ldr r12, [pc, r12]
 *   @0xfdee0 ldr r3, [r12]
 *   @0xfdee4 cmp r5, r3
 *   @0xfdee8 bge 0xfdf24 <_Z14F_DsGridGetMinR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfdeec ldr r12, [pc, #0x4c]
 *   @0xfdef0 ldr r12, [pc, r12]
 *   @0xfdef4 ldr r3, [r12, #0x4]
 *   @0xfdef8 ldr r0, [r3, r5, lsl #2]
 *   @0xfdefc cmp r0, #0
 *   @0xfdf00 beq 0xfdf24 <_Z14F_DsGridGetMinR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfdf04 str r2, [sp, #0x4]
 *   @0xfdf08 mov r1, r8
 *   @0xfdf0c str r9, [sp]
 *   @0xfdf10 mov r2, r7
 *   @0xfdf14 mov r3, r6
 *   @0xfdf18 bl 0x206d14 <_ZN8CDS_Grid7Get_MinER6RValueiiii>
 *   @0xfdf1c add sp, sp, #12
 *   @0xfdf20 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfdf24 ldr r0, [pc, #0x18]
 *   @0xfdf28 mov r1, #0
 *   @0xfdf2c add r0, pc, r0
 *   @0xfdf30 add sp, sp, #12
 *   @0xfdf34 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfdf38 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfdf3c eoreq pc, lr, r8, lsr #31
 *   @0xfdf40 mlaeq lr, r8, pc, pc
 *   @0xfdf44 .word 0x00239cd0
 *
 * ══ §114/137 F_DsGridGetMean(RValue&, CInstance*, CInstance*, int, RValue*)  0xfdf48  size 216  54 条（0xfdf48..0xfe020）
 * @func 0xfdf48 0xfe020  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_DsGridGetMean(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / CDS_Grid::Get_Mean(RValue&, int, int, int, int)
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x5c×1 / 0x4c×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfdf48 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfdf4c sub sp, sp, #12
 *   @0xfdf50 mov r1, #0
 *   @0xfdf54 mov r8, r0
 *   @0xfdf58 ldr r4, [sp, #0x28]
 *   @0xfdf5c mov r0, r4
 *   @0xfdf60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdf64 mov r1, #1
 *   @0xfdf68 mov r5, r0
 *   @0xfdf6c mov r0, r4
 *   @0xfdf70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdf74 mov r1, #2
 *   @0xfdf78 mov r7, r0
 *   @0xfdf7c mov r0, r4
 *   @0xfdf80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdf84 mov r1, #3
 *   @0xfdf88 mov r6, r0
 *   @0xfdf8c mov r0, r4
 *   @0xfdf90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdf94 mov r1, #4
 *   @0xfdf98 mov r9, r0
 *   @0xfdf9c mov r0, r4
 *   @0xfdfa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdfa4 cmp r5, #0
 *   @0xfdfa8 mov r2, r0
 *   @0xfdfac blt 0xfdffc <_Z15F_DsGridGetMeanR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfdfb0 ldr r12, [pc, #0x5c]
 *   @0xfdfb4 ldr r12, [pc, r12]
 *   @0xfdfb8 ldr r3, [r12]
 *   @0xfdfbc cmp r5, r3
 *   @0xfdfc0 bge 0xfdffc <_Z15F_DsGridGetMeanR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfdfc4 ldr r12, [pc, #0x4c]
 *   @0xfdfc8 ldr r12, [pc, r12]
 *   @0xfdfcc ldr r3, [r12, #0x4]
 *   @0xfdfd0 ldr r0, [r3, r5, lsl #2]
 *   @0xfdfd4 cmp r0, #0
 *   @0xfdfd8 beq 0xfdffc <_Z15F_DsGridGetMeanR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfdfdc str r2, [sp, #0x4]
 *   @0xfdfe0 mov r1, r8
 *   @0xfdfe4 str r9, [sp]
 *   @0xfdfe8 mov r2, r7
 *   @0xfdfec mov r3, r6
 *   @0xfdff0 bl 0x2042c8 <_ZN8CDS_Grid8Get_MeanER6RValueiiii>
 *   @0xfdff4 add sp, sp, #12
 *   @0xfdff8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfdffc ldr r0, [pc, #0x18]
 *   @0xfe000 mov r1, #0
 *   @0xfe004 add r0, pc, r0
 *   @0xfe008 add sp, sp, #12
 *   @0xfe00c pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfe010 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe014 .word 0x002efed0
 *   @0xfe018 eoreq pc, lr, r0, asr #29
 *   @0xfe01c .word 0x00239bf8
 *
 * ══ §115/137 F_SurfaceCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c6c8  size 216  54 条（0x11c6c8..0x11c7a0）
 * @func 0x11c6c8 0x11c7a0  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GR_Surface_Create(int, int, int) / Debug_AddTag(eTagNameType, char const*, ...) / YYError(char const*, ...)
 * 字段偏移 top8: 0x20×1 / 0xc×1 / 0x70×1 / 0x4×1 / 0x4c×1 / 0x34×1 / 0x14×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c6c8 push {r4, r6, r7, r8, lr}
 *   @0x11c6cc sub sp, sp, #12
 *   @0x11c6d0 mov r1, #0
 *   @0x11c6d4 mov r6, r0
 *   @0x11c6d8 ldr r4, [sp, #0x20]
 *   @0x11c6dc str r1, [r0, #0xc]
 *   @0x11c6e0 mov r0, r4
 *   @0x11c6e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c6e8 mov r1, #1
 *   @0x11c6ec mov r7, r0
 *   @0x11c6f0 mov r0, r4
 *   @0x11c6f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c6f8 cmp r7, #0
 *   @0x11c6fc cmpne r0, #0
 *   @0x11c700 mov r8, r0
 *   @0x11c704 beq 0x11c780 <_Z15F_SurfaceCreateR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x11c708 mov r1, r8
 *   @0x11c70c mov r0, r7
 *   @0x11c710 mvn r2, #0
 *   @0x11c714 bl 0x170f98 <_Z17GR_Surface_Createiii>
 *   @0x11c718 ldr r12, [pc, #0x70]
 *   @0x11c71c ldr r12, [pc, r12]
 *   @0x11c720 vmov s15, r0
 *   @0x11c724 vcvt.f64.s32 d7, s15
 *   @0x11c728 vmov r0, r1, d7
 *   @0x11c72c vstr s14, [r6]
 *   @0x11c730 ldrb r3, [r12]
 *   @0x11c734 cmp r3, #0
 *   @0x11c738 str r1, [r6, #0x4]
 *   @0x11c73c beq 0x11c754 <_Z15F_SurfaceCreateR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x11c740 ldr r3, [pc, #0x4c]
 *   @0x11c744 ldr r3, [pc, r3]
 *   @0x11c748 ldr r3, [r3]
 *   @0x11c74c cmp r3, #0
 *   @0x11c750 beq 0x11c75c <_Z15F_SurfaceCreateR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x11c754 add sp, sp, #12
 *   @0x11c758 pop {r4, r6, r7, r8, pc}
 *   @0x11c75c ldr r1, [pc, #0x34]
 *   @0x11c760 vstr d7, [sp]
 *   @0x11c764 mov r2, r7
 *   @0x11c768 mov r3, r8
 *   @0x11c76c mov r0, #4
 *   @0x11c770 add r1, pc, r1
 *   @0x11c774 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x11c778 add sp, sp, #12
 *   @0x11c77c pop {r4, r6, r7, r8, pc}
 *   @0x11c780 ldr r0, [pc, #0x14]
 *   @0x11c784 add r0, pc, r0
 *   @0x11c788 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x11c78c b 0x11c708 <_Z15F_SurfaceCreateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x11c790 eoreq r1, sp, r8, lsl #4
 *   @0x11c794 .word 0x002d1cdc
 *   @0x11c798 eoreq sp, r1, r8, lsl r9
 *   @0x11c79c eoreq sp, r1, r8, asr #17
 *
 * ══ §116/137 F_DrawSurfaceExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11e954  size 216  54 条（0x11e954..0x11ea2c）
 * @func 0x11e954 0x11ea2c  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×2 / GR_Surface_Exists(int) / GR_Surface_Draw(int, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0xc×2 / 0x38×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11e954 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11e958 sub sp, sp, #20
 *   @0x11e95c mov r1, #0
 *   @0x11e960 ldr r4, [sp, #0x38]
 *   @0x11e964 mov r0, r4
 *   @0x11e968 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e96c mov r5, r0
 *   @0x11e970 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11e974 subs r1, r0, #0
 *   @0x11e978 beq 0x11ea14 <_Z16F_DrawSurfaceExtR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x11e97c mov r0, r4
 *   @0x11e980 mov r1, #1
 *   @0x11e984 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e988 mov r1, #2
 *   @0x11e98c mov r8, r0
 *   @0x11e990 mov r0, r4
 *   @0x11e994 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e998 mov r1, #3
 *   @0x11e99c mov r7, r0
 *   @0x11e9a0 mov r0, r4
 *   @0x11e9a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e9a8 mov r1, #4
 *   @0x11e9ac mov r6, r0
 *   @0x11e9b0 mov r0, r4
 *   @0x11e9b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e9b8 mov r1, #5
 *   @0x11e9bc mov r11, r0
 *   @0x11e9c0 mov r0, r4
 *   @0x11e9c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e9c8 mov r1, #6
 *   @0x11e9cc mov r10, r0
 *   @0x11e9d0 mov r0, r4
 *   @0x11e9d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e9d8 mov r1, #7
 *   @0x11e9dc mov r9, r0
 *   @0x11e9e0 mov r0, r4
 *   @0x11e9e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e9e8 str r11, [sp]
 *   @0x11e9ec str r10, [sp, #0x4]
 *   @0x11e9f0 mov r1, r8
 *   @0x11e9f4 str r9, [sp, #0x8]
 *   @0x11e9f8 mov r2, r7
 *   @0x11e9fc mov r3, r6
 *   @0x11ea00 str r0, [sp, #0xc]
 *   @0x11ea04 mov r0, r5
 *   @0x11ea08 bl 0x171dbc <_Z15GR_Surface_Drawifffffjf>
 *   @0x11ea0c add sp, sp, #20
 *   @0x11ea10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11ea14 ldr r0, [pc, #0xc]
 *   @0x11ea18 add r0, pc, r0
 *   @0x11ea1c add sp, sp, #20
 *   @0x11ea20 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11ea24 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11ea28 eoreq r11, r1, r0, asr r8
 *
 * ══ §117/137 F_SurfaceGetPixelExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11f0d0  size 216  54 条（0x11f0d0..0x11f1a8）
 * @func 0x11f0d0 0x11f1a8  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / GR_Surface_Exists(int)×2 / GR_Surface_Get_Texture(int) / GR_Texture_Get_Surface(int) / Graphics::Surface_GrabRect(void*, int, int, int, int)
 * 字段偏移 top8: 0xc×2 / 0x20×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11f0d0 push {r4, r5, r6, r7, lr}
 *   @0x11f0d4 sub sp, sp, #12
 *   @0x11f0d8 mov r1, #0
 *   @0x11f0dc mov r4, r0
 *   @0x11f0e0 ldr r5, [sp, #0x20]
 *   @0x11f0e4 mov r0, r5
 *   @0x11f0e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f0ec mov r6, r0
 *   @0x11f0f0 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f0f4 subs r1, r0, #0
 *   @0x11f0f8 beq 0x11f190 <_Z20F_SurfaceGetPixelExtR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x11f0fc mov r3, #0
 *   @0x11f100 mov r0, r6
 *   @0x11f104 str r3, [r4, #0xc]
 *   @0x11f108 str r3, [r4]
 *   @0x11f10c str r3, [r4, #0x4]
 *   @0x11f110 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f114 cmp r0, #0
 *   @0x11f118 bne 0x11f124 <_Z20F_SurfaceGetPixelExtR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x11f11c add sp, sp, #12
 *   @0x11f120 pop {r4, r5, r6, r7, pc}
 *   @0x11f124 mov r0, r6
 *   @0x11f128 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x11f12c bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x11f130 mov r1, #1
 *   @0x11f134 mov r6, r0
 *   @0x11f138 mov r0, r5
 *   @0x11f13c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f140 mov r1, #2
 *   @0x11f144 mov r7, r0
 *   @0x11f148 mov r0, r5
 *   @0x11f14c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f150 mov r3, #1
 *   @0x11f154 mov r1, r7
 *   @0x11f158 str r3, [sp]
 *   @0x11f15c mov r2, r0
 *   @0x11f160 mov r0, r6
 *   @0x11f164 bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii>
 *   @0x11f168 subs r3, r0, #0
 *   @0x11f16c beq 0x11f11c <_Z20F_SurfaceGetPixelExtR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x11f170 ldr r2, [r3]
 *   @0x11f174 vmov s15, r2
 *   @0x11f178 vcvt.f64.u32 d7, s15
 *   @0x11f17c vmov r2, r3, d7
 *   @0x11f180 stm r4, {r2, r3}
 *   @0x11f184 add sp, sp, #12
 *   @0x11f188 pop {r4, r5, r6, r7, lr}
 *   @0x11f18c b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x11f190 ldr r0, [pc, #0xc]
 *   @0x11f194 add r0, pc, r0
 *   @0x11f198 add sp, sp, #12
 *   @0x11f19c pop {r4, r5, r6, r7, lr}
 *   @0x11f1a0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11f1a4 .word 0x0021b0d4
 *
 * ══ §118/137 F_CheckKeyPressed(RValue&, CInstance*, CInstance*, int, RValue*)  0x12746c  size 216  54 条（0x12746c..0x127544）
 * @func 0x12746c 0x127544  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Key_Pressed(int)×3 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x18×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12746c push {r4, r5, r6, r7, r8, lr}
 *   @0x127470 mov r8, #0
 *   @0x127474 mov r5, r0
 *   @0x127478 str r8, [r0, #0xc]
 *   @0x12747c str r8, [r0]
 *   @0x127480 mov r1, r8
 *   @0x127484 str r8, [r0, #0x4]
 *   @0x127488 ldr r0, [sp, #0x18]
 *   @0x12748c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x127490 subs r3, r0, #0
 *   @0x127494 bne 0x1274d4 <_Z17F_CheckKeyPressedR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x127498 mov r4, r3
 *   @0x12749c str r3, [r5]
 *   @0x1274a0 mov r6, r3
 *   @0x1274a4 mov r3, r8
 *   @0x1274a8 movt r3, #0x3ff0
 *   @0x1274ac str r3, [r5, #0x4]
 *   @0x1274b0 mov r0, r4
 *   @0x1274b4 add r4, r4, #1
 *   @0x1274b8 bl 0x18bf0c <_Z14IO_Key_Pressedi>
 *   @0x1274bc cmp r0, #0
 *   @0x1274c0 strne r6, [r5]
 *   @0x1274c4 strne r6, [r5, #0x4]
 *   @0x1274c8 cmp r4, #256
 *   @0x1274cc bne 0x1274b0 <_Z17F_CheckKeyPressedR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1274d0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1274d4 cmp r3, #1
 *   @0x1274d8 beq 0x127508 <_Z17F_CheckKeyPressedR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1274dc sub r3, r3, #2
 *   @0x1274e0 cmp r3, #253
 *   @0x1274e4 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x1274e8 bl 0x18bf0c <_Z14IO_Key_Pressedi>
 *   @0x1274ec vmov s15, r0
 *   @0x1274f0 vcvt.f64.u32 d7, s15
 *   @0x1274f4 vmov r0, r1, d7
 *   @0x1274f8 vmov r2, s14
 *   @0x1274fc mov r3, r1
 *   @0x127500 stm r5, {r2, r3}
 *   @0x127504 pop {r4, r5, r6, r7, r8, pc}
 *   @0x127508 mov r6, #0
 *   @0x12750c movt r6, #0x3ff0
 *   @0x127510 mov r4, r8
 *   @0x127514 mov r7, r8
 *   @0x127518 str r8, [r5]
 *   @0x12751c str r8, [r5, #0x4]
 *   @0x127520 mov r0, r4
 *   @0x127524 add r4, r4, #1
 *   @0x127528 bl 0x18bf0c <_Z14IO_Key_Pressedi>
 *   @0x12752c cmp r0, #0
 *   @0x127530 strne r7, [r5]
 *   @0x127534 strne r6, [r5, #0x4]
 *   @0x127538 cmp r4, #256
 *   @0x12753c bne 0x127520 <_Z17F_CheckKeyPressedR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x127540 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §119/137 F_RoomGetViewport(RValue&, CInstance*, CInstance*, int, RValue*)  0x12fe10  size 216  54 条（0x12fe10..0x12fee8）
 * @func 0x12fe10 0x12fee8  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CreateArray(RValue*, int, ...)×2 / Room_Data(int)
 * 字段偏移 top8: 0x30×1 / 0x2×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12fe10 push {r4, r5, r6, lr}
 *   @0x12fe14 sub sp, sp, #32
 *   @0x12fe18 mov r1, #0
 *   @0x12fe1c mov r5, r0
 *   @0x12fe20 ldr r4, [sp, #0x30]
 *   @0x12fe24 mov r0, r4
 *   @0x12fe28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12fe2c mov r1, #1
 *   @0x12fe30 mov r6, r0
 *   @0x12fe34 mov r0, r4
 *   @0x12fe38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12fe3c mov r4, r0
 *   @0x12fe40 mov r0, r6
 *   @0x12fe44 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12fe48 cmp r0, #0
 *   @0x12fe4c beq 0x12febc <_Z17F_RoomGetViewportR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x12fe50 cmp r4, #7
 *   @0x12fe54 bhi 0x12febc <_Z17F_RoomGetViewportR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x12fe58 add r4, r4, #18
 *   @0x12fe5c ldr r12, [r0, r4, lsl #2]
 *   @0x12fe60 cmp r12, #0
 *   @0x12fe64 beq 0x12febc <_Z17F_RoomGetViewportR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x12fe68 vldr s13, [r12, #20]
 *   @0x12fe6c vcvt.f64.s32 d7, s13
 *   @0x12fe70 ldrb r2, [r12]
 *   @0x12fe74 mov r0, r5
 *   @0x12fe78 mov r1, #5
 *   @0x12fe7c vstr d7, [sp]
 *   @0x12fe80 vmov s15, r2
 *   @0x12fe84 vldr s13, [r12, #24]
 *   @0x12fe88 vcvt.f64.u32 d7, s15
 *   @0x12fe8c vmov r2, r3, d7
 *   @0x12fe90 vcvt.f64.s32 d7, s13
 *   @0x12fe94 vstr d7, [sp, #8]
 *   @0x12fe98 vldr s13, [r12, #28]
 *   @0x12fe9c vcvt.f64.s32 d7, s13
 *   @0x12fea0 vstr d7, [sp, #16]
 *   @0x12fea4 vldr s14, [r12, #32]
 *   @0x12fea8 vcvt.f64.s32 d7, s14
 *   @0x12feac vstr d7, [sp, #24]
 *   @0x12feb0 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x12feb4 add sp, sp, #32
 *   @0x12feb8 pop {r4, r5, r6, pc}
 *   @0x12febc mov r2, #0
 *   @0x12fec0 mov r3, #0
 *   @0x12fec4 mov r0, r5
 *   @0x12fec8 mov r1, #5
 *   @0x12fecc strd r2, r3, [sp]
 *   @0x12fed0 strd r2, r3, [sp, #8]
 *   @0x12fed4 strd r2, r3, [sp, #16]
 *   @0x12fed8 strd r2, r3, [sp, #24]
 *   @0x12fedc bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x12fee0 add sp, sp, #32
 *   @0x12fee4 pop {r4, r5, r6, pc}
 *
 * ══ §120/137 F_HttpGet(RValue&, CInstance*, CInstance*, int, RValue*)  0x139074  size 216  54 条（0x139074..0x13914c）
 * @func 0x139074 0x13914c  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65e0×2 / YYGetString(RValue const*, int) / LoadSave::HTTP_Get(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*)
 * 字段偏移 top8: 0xbc×1 / 0x18×1 / 0xc×1 / 0x4×1 / 0x78×1 / 0x60×1 / 0x48×1 / 0x44×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139074 ldr r3, [pc, #0xbc]
 *   @0x139078 mov r1, #0
 *   @0x13907c push {r4, r5, lr}
 *   @0x139080 sub sp, sp, #12
 *   @0x139084 ldr r3, [pc, r3]
 *   @0x139088 mov r4, r0
 *   @0x13908c ldr r0, [sp, #0x18]
 *   @0x139090 mov r2, #1
 *   @0x139094 strb r2, [r3]
 *   @0x139098 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13909c mov r2, #0
 *   @0x1390a0 mov r3, r2
 *   @0x1390a4 movt r2, #0xbff0
 *   @0x1390a8 str r3, [r4, #0xc]
 *   @0x1390ac str r2, [r4, #0x4]
 *   @0x1390b0 str r3, [r4]
 *   @0x1390b4 subs r5, r0, #0
 *   @0x1390b8 beq 0x139130 <_Z9F_HttpGetR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1390bc ldr r0, [pc, #0x78]
 *   @0x1390c0 mov r1, r5
 *   @0x1390c4 mov r2, #7
 *   @0x1390c8 add r0, pc, r0
 *   @0x1390cc bl 0xb65e0 <strncmp@plt>
 *   @0x1390d0 cmp r0, #0
 *   @0x1390d4 beq 0x1390f4 <_Z9F_HttpGetR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1390d8 ldr r0, [pc, #0x60]
 *   @0x1390dc mov r1, r5
 *   @0x1390e0 mov r2, #8
 *   @0x1390e4 add r0, pc, r0
 *   @0x1390e8 bl 0xb65e0 <strncmp@plt>
 *   @0x1390ec cmp r0, #0
 *   @0x1390f0 bne 0x139130 <_Z9F_HttpGetR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1390f4 ldr r12, [pc, #0x48]
 *   @0x1390f8 mov r0, r5
 *   @0x1390fc ldr r2, [pc, #0x44]
 *   @0x139100 mov lr, #0
 *   @0x139104 ldr r12, [pc, r12]
 *   @0x139108 mov r3, lr
 *   @0x13910c ldr r2, [pc, r2]
 *   @0x139110 mvn r1, #0
 *   @0x139114 ldr r5, [r12]
 *   @0x139118 str lr, [sp]
 *   @0x13911c bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_>
 *   @0x139120 vmov s15, r5
 *   @0x139124 vcvt.f64.s32 d7, s15
 *   @0x139128 vmov r2, r3, d7
 *   @0x13912c stm r4, {r2, r3}
 *   @0x139130 add sp, sp, #12
 *   @0x139134 pop {r4, r5, pc}
 *   @0x139138 .word 0x002b48d0
 *   @0x13913c andseq r7, pc, r8, lsl r10
 *   @0x139140 andseq r7, pc, r4, lsl #20
 *   @0x139144 eoreq r6, r11, r4, ror r1
 *   @0x139148 eoreq r6, r11, r0, ror r1
 *
 * ══ §121/137 F_ActionPotentialStep(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e258  size 216  54 条（0x13e258..0x13e330）
 * @func 0x13e258 0x13e330  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / Motion_Potential_Step(CInstance*, float, float, float, int, bool)×2 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x20×1 / 0x7c×1 / 0x4×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e258 push {r4, r5, r6, lr}
 *   @0x13e25c vpush {d8}
 *   @0x13e260 sub sp, sp, #8
 *   @0x13e264 mov r5, r1
 *   @0x13e268 mov r1, #0
 *   @0x13e26c ldr r4, [sp, #0x20]
 *   @0x13e270 mov r0, r4
 *   @0x13e274 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e278 mov r1, #1
 *   @0x13e27c vmov s17, r0
 *   @0x13e280 mov r0, r4
 *   @0x13e284 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e288 mov r1, #2
 *   @0x13e28c vmov s16, r0
 *   @0x13e290 mov r0, r4
 *   @0x13e294 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e298 mov r1, #3
 *   @0x13e29c mov r6, r0
 *   @0x13e2a0 mov r0, r4
 *   @0x13e2a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e2a8 ldr r2, [pc, #0x7c]
 *   @0x13e2ac ldr r2, [pc, r2]
 *   @0x13e2b0 ldrb r3, [r2]
 *   @0x13e2b4 cmp r0, #0
 *   @0x13e2b8 movle r0, #0
 *   @0x13e2bc movgt r0, #1
 *   @0x13e2c0 cmp r3, #0
 *   @0x13e2c4 str r0, [sp, #0x4]
 *   @0x13e2c8 bne 0x13e2f4 <_Z21F_ActionPotentialStepR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13e2cc mov r0, r5
 *   @0x13e2d0 mov r3, r6
 *   @0x13e2d4 mvn r2, #2
 *   @0x13e2d8 vmov r1, s17
 *   @0x13e2dc str r2, [sp]
 *   @0x13e2e0 vmov r2, s16
 *   @0x13e2e4 bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib>
 *   @0x13e2e8 add sp, sp, #8
 *   @0x13e2ec vpop {d8}
 *   @0x13e2f0 pop {r4, r5, r6, pc}
 *   @0x13e2f4 vldr s14, [r5, #180]
 *   @0x13e2f8 vldr s15, [r5, #184]
 *   @0x13e2fc vadd.f32 s14, s17, s14
 *   @0x13e300 mov r3, r6
 *   @0x13e304 mov r0, r5
 *   @0x13e308 mvn r2, #2
 *   @0x13e30c str r2, [sp]
 *   @0x13e310 vadd.f32 s15, s16, s15
 *   @0x13e314 vmov r1, s14
 *   @0x13e318 vmov r2, s15
 *   @0x13e31c bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib>
 *   @0x13e320 add sp, sp, #8
 *   @0x13e324 vpop {d8}
 *   @0x13e328 pop {r4, r5, r6, pc}
 *   @0x13e32c mlaeq r10, r0, r8, pc
 *
 * ══ §122/137 F_GPUSetTexFilter(RValue&, CInstance*, CInstance*, int, RValue*)  0x1473d4  size 216  54 条（0x1473d4..0x1474ac）
 * @func 0x1473d4 0x1474ac  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)×4 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x98×1 / 0x80×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1473d4 push {r3, r4, r5, lr}
 *   @0x1473d8 cmp r3, #1
 *   @0x1473dc mov r3, #0
 *   @0x1473e0 mov r4, r3
 *   @0x1473e4 movt r3, #0xbff0
 *   @0x1473e8 str r4, [r0, #0xc]
 *   @0x1473ec mov r1, r4
 *   @0x1473f0 str r3, [r0, #0x4]
 *   @0x1473f4 str r4, [r0]
 *   @0x1473f8 ldr r0, [sp, #0x10]
 *   @0x1473fc beq 0x147410 <_Z17F_GPUSetTexFilterR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x147400 ldr r0, [pc, #0x98]
 *   @0x147404 pop {r3, r4, r5, lr}
 *   @0x147408 add r0, pc, r0
 *   @0x14740c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147410 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x147414 cmp r0, #0
 *   @0x147418 beq 0x14745c <_Z17F_GPUSetTexFilterR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x14741c ldr r5, [pc, #0x80]
 *   @0x147420 ldr r5, [pc, r5]
 *   @0x147424 mov r1, r4
 *   @0x147428 mov r0, r5
 *   @0x14742c mov r2, #0
 *   @0x147430 mov r3, #1
 *   @0x147434 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147438 mov r2, #1
 *   @0x14743c mov r1, r4
 *   @0x147440 mov r0, r5
 *   @0x147444 add r4, r4, #1
 *   @0x147448 mov r3, r2
 *   @0x14744c bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147450 cmp r4, #8
 *   @0x147454 bne 0x147424 <_Z17F_GPUSetTexFilterR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x147458 pop {r3, r4, r5, pc}
 *   @0x14745c ldr r5, [pc, #0x44]
 *   @0x147460 mov r4, r0
 *   @0x147464 ldr r5, [pc, r5]
 *   @0x147468 mov r2, #0
 *   @0x14746c mov r1, r4
 *   @0x147470 mov r3, r2
 *   @0x147474 mov r0, r5
 *   @0x147478 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x14747c mov r1, r4
 *   @0x147480 mov r0, r5
 *   @0x147484 add r4, r4, #1
 *   @0x147488 mov r2, #1
 *   @0x14748c mov r3, #0
 *   @0x147490 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147494 cmp r4, #8
 *   @0x147498 bne 0x147468 <_Z17F_GPUSetTexFilterR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x14749c pop {r3, r4, r5, pc}
 *   @0x1474a0 andseq r10, pc, r8, lsr r6
 *   @0x1474a4 .word 0x002a68d8
 *   @0x1474a8 mlaeq r10, r4, r8, r6
 *
 * ══ §123/137 F_GPUSetTexRepeat(RValue&, CInstance*, CInstance*, int, RValue*)  0x14758c  size 216  54 条（0x14758c..0x147664）
 * @func 0x14758c 0x147664  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)×4 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x98×1 / 0x80×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14758c push {r3, r4, r5, lr}
 *   @0x147590 cmp r3, #1
 *   @0x147594 mov r3, #0
 *   @0x147598 mov r4, r3
 *   @0x14759c movt r3, #0xbff0
 *   @0x1475a0 str r4, [r0, #0xc]
 *   @0x1475a4 mov r1, r4
 *   @0x1475a8 str r3, [r0, #0x4]
 *   @0x1475ac str r4, [r0]
 *   @0x1475b0 ldr r0, [sp, #0x10]
 *   @0x1475b4 beq 0x1475c8 <_Z17F_GPUSetTexRepeatR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1475b8 ldr r0, [pc, #0x98]
 *   @0x1475bc pop {r3, r4, r5, lr}
 *   @0x1475c0 add r0, pc, r0
 *   @0x1475c4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1475c8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1475cc cmp r0, #0
 *   @0x1475d0 beq 0x147614 <_Z17F_GPUSetTexRepeatR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1475d4 ldr r5, [pc, #0x80]
 *   @0x1475d8 ldr r5, [pc, r5]
 *   @0x1475dc mov r1, r4
 *   @0x1475e0 mov r0, r5
 *   @0x1475e4 mov r2, #2
 *   @0x1475e8 mov r3, #0
 *   @0x1475ec bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1475f0 mov r1, r4
 *   @0x1475f4 mov r0, r5
 *   @0x1475f8 add r4, r4, #1
 *   @0x1475fc mov r2, #3
 *   @0x147600 mov r3, #0
 *   @0x147604 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147608 cmp r4, #8
 *   @0x14760c bne 0x1475dc <_Z17F_GPUSetTexRepeatR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x147610 pop {r3, r4, r5, pc}
 *   @0x147614 ldr r5, [pc, #0x44]
 *   @0x147618 mov r4, r0
 *   @0x14761c ldr r5, [pc, r5]
 *   @0x147620 mov r1, r4
 *   @0x147624 mov r0, r5
 *   @0x147628 mov r2, #2
 *   @0x14762c mov r3, #1
 *   @0x147630 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147634 mov r1, r4
 *   @0x147638 mov r0, r5
 *   @0x14763c add r4, r4, #1
 *   @0x147640 mov r2, #3
 *   @0x147644 mov r3, #1
 *   @0x147648 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x14764c cmp r4, #8
 *   @0x147650 bne 0x147620 <_Z17F_GPUSetTexRepeatR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x147654 pop {r3, r4, r5, pc}
 *   @0x147658 andseq r10, pc, r0, lsl r5
 *   @0x14765c eoreq r6, r10, r0, lsr #14
 *   @0x147660 .word 0x002a66dc
 *
 * ══ §124/137 F_YoYo_LockOrientation(RValue&, CInstance*, CInstance*, int, RValue*)  0x1594dc  size 216  54 条（0x1594dc..0x1595b4）
 * @func 0x1594dc 0x1595b4  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x159548→0x544c58, 0x15954c→0x544c50, 0x159550→0x544c54, 0x15955c→0x544c4c
 * 调用序列: YYGetInt32(RValue const*, int) / F_YoYo_LockOrientation(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c / GetOrientation
 * 字段偏移 top8: 0x54×3 / 0x8×1 / 0xc×1 / 0x4×1 / 0x98×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1594dc push {r4, lr}
 *   @0x1594e0 mov r3, #0
 *   @0x1594e4 ldr r12, [sp, #0x8]
 *   @0x1594e8 mov r1, r3
 *   @0x1594ec str r3, [r0, #0xc]
 *   @0x1594f0 str r3, [r0]
 *   @0x1594f4 str r3, [r0, #0x4]
 *   @0x1594f8 mov r0, r12
 *   @0x1594fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x159500 ldr r3, [pc, #0x98]
 *   @0x159504 add r3, pc, r3
 *   @0x159508 cmp r0, #0
 *   @0x15950c ble 0x159548 <_Z22F_YoYo_LockOrientationR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x159510 bl 0x15e288 <GetOrientation>
 *   @0x159514 subs r2, r0, #1
 *   @0x159518 rsbs r1, r2, #0
 *   @0x15951c adcs r1, r1, r2
 *   @0x159520 subs r12, r0, #2
 *   @0x159524 rsbs r2, r12, #0
 *   @0x159528 adcs r2, r2, r12
 *   @0x15952c subs lr, r0, #3
 *   @0x159530 rsbs r3, lr, #0
 *   @0x159534 adcs r3, r3, lr
 *   @0x159538 rsbs r0, r0, #1
 *   @0x15953c pop {r4, lr}
 *   @0x159540 movlo r0, #0
 *   @0x159544 b 0x15f1bc <_Z19RestrictOrientationbbbb>
 *   @0x159548 ldr r0, [pc, #0x54]
 *   @0x15954c ldr r1, [pc, #0x54]
 *   @0x159550 ldr r2, [pc, #0x54]
 *   @0x159554 ldr r0, [r3, r0]
 *   @0x159558 ldr r1, [r3, r1]
 *   @0x15955c ldr r12, [pc, #0x4c]
 *   @0x159560 ldr r0, [r0]
 *   @0x159564 ldr r2, [r3, r2]
 *   @0x159568 adds r0, r0, #0
 *   @0x15956c ldr r1, [r1]
 *   @0x159570 ldr r3, [r3, r12]
 *   @0x159574 ldr r2, [r2]
 *   @0x159578 movne r0, #1
 *   @0x15957c adds r1, r1, #0
 *   @0x159580 ldr r3, [r3]
 *   @0x159584 movne r1, #1
 *   @0x159588 adds r2, r2, #0
 *   @0x15958c pop {r4, lr}
 *   @0x159590 movne r2, #1
 *   @0x159594 adds r3, r3, #0
 *   @0x159598 movne r3, #1
 *   @0x15959c b 0x15f1bc <_Z19RestrictOrientationbbbb>
 *   @0x1595a0 eoreq r8, r9, r12, asr #14
 *   @0x1595a4 .word 0xffffdf64
 *   @0x1595a8 .word 0xffffdf68
 *   @0x1595ac .word 0xffffdf6c
 *   @0x1595b0 .word 0xffffdf70
 *
 * ══ §125/137 C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)  0x1648d4  size 216  54 条（0x1648d4..0x1649ac）
 * @func 0x1648d4 0x1649ac  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)+0x7c / MemoryManager::SetLength(void**, unsigned int, char const*, int) / operator new(unsigned int)
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x2×2 / 0x58×1 / 0x5c×1 / 0x7c×1 / 0x24×1 / 0x28×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1648d4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1648d8 vpush {d8, d9, d10}
 *   @0x1648dc mov r4, r0
 *   @0x1648e0 vldr s21, [sp, #64]
 *   @0x1648e4 ldr r0, [r0]
 *   @0x1648e8 mov r7, r2
 *   @0x1648ec ldr r2, [r4, #0x4]
 *   @0x1648f0 mov r5, r1
 *   @0x1648f4 mov r6, r3
 *   @0x1648f8 vldr s20, [sp, #68]
 *   @0x1648fc cmp r0, r2
 *   @0x164900 vldr s19, [sp, #72]
 *   @0x164904 vldr s18, [sp, #76]
 *   @0x164908 vldr s17, [sp, #80]
 *   @0x16490c vldr s16, [sp, #84]
 *   @0x164910 ldr r11, [sp, #0x58]
 *   @0x164914 ldr r10, [sp, #0x5c]
 *   @0x164918 movlt r9, r0
 *   @0x16491c blt 0x164950 <_ZN9C3D_Model8AddEntryEiffffffffff+0x7c>
 *   @0x164920 cmp r0, #0
 *   @0x164924 ldr r2, [pc, #0x7c]
 *   @0x164928 lslne r8, r0, #1
 *   @0x16492c lslne r1, r0, #3
 *   @0x164930 moveq r1, #128
 *   @0x164934 add r0, r4, #8
 *   @0x164938 add r2, pc, r2
 *   @0x16493c movw r3, #0x195
 *   @0x164940 moveq r8, #32
 *   @0x164944 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x164948 ldr r9, [r4]
 *   @0x16494c str r8, [r4, #0x4]
 *   @0x164950 mov r0, #44
 *   @0x164954 ldr r8, [r4, #0x8]
 *   @0x164958 bl 0x27c524 <_Znwj>
 *   @0x16495c ldr r12, [r4]
 *   @0x164960 add r3, r12, #1
 *   @0x164964 str r0, [r8, r9, lsl #2]
 *   @0x164968 ldr r2, [r4, #0x8]
 *   @0x16496c ldr r12, [r2, r12, lsl #2]
 *   @0x164970 vstr s21, [r12, #12]
 *   @0x164974 vstr s20, [r12, #16]
 *   @0x164978 vstr s19, [r12, #20]
 *   @0x16497c vstr s18, [r12, #24]
 *   @0x164980 vstr s17, [r12, #28]
 *   @0x164984 str r7, [r12, #0x4]
 *   @0x164988 vstr s16, [r12, #32]
 *   @0x16498c str r6, [r12, #0x8]
 *   @0x164990 str r11, [r12, #0x24]
 *   @0x164994 str r10, [r12, #0x28]
 *   @0x164998 vpop {d8, d9, d10}
 *   @0x16499c str r5, [r12]
 *   @0x1649a0 str r3, [r4]
 *   @0x1649a4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1649a8 ldrsbeq r5, [lr], -r12
 *
 * ══ §126/137 GR_Draw_Circle_Precision(int)  0x16ae64  size 216  54 条（0x16ae64..0x16af3c）
 * @func 0x16ae64 0x16af3c  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb658c×2 / 0xb6580×2
 * 字段偏移 top8: 0x4×2 / 0x84×1 / 0x80×1 / 0x7c×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ae64 cmp r0, #64
 *   @0x16ae68 push {r4, r5, r6, r7, r8, lr}
 *   @0x16ae6c vpush {d8, d9}
 *   @0x16ae70 bgt 0x16af10 <_Z24GR_Draw_Circle_Precisioni+0xac>
 *   @0x16ae74 cmp r0, #4
 *   @0x16ae78 movlt r0, #4
 *   @0x16ae7c vldr s16, [pc, #160]
 *   @0x16ae80 bic r8, r0, #3
 *   @0x16ae84 vmov s15, r8
 *   @0x16ae88 vcvt.f32.s32 s17, s15
 *   @0x16ae8c vdiv.f32 s16, s16, s17
 *   @0x16ae90 vmov r0, s16
 *   @0x16ae94 bl 0xb658c <cosf@plt>
 *   @0x16ae98 mov r7, r0
 *   @0x16ae9c vmov r0, s16
 *   @0x16aea0 bl 0xb6580 <sinf@plt>
 *   @0x16aea4 ldr r3, [pc, #0x84]
 *   @0x16aea8 mov r4, #0
 *   @0x16aeac ldr r6, [pc, #0x80]
 *   @0x16aeb0 vldr s18, [pc, #112]
 *   @0x16aeb4 ldr r5, [pc, #0x7c]
 *   @0x16aeb8 ldr r3, [pc, r3]
 *   @0x16aebc ldr r6, [pc, r6]
 *   @0x16aec0 ldr r5, [pc, r5]
 *   @0x16aec4 str r8, [r3]
 *   @0x16aec8 b 0x16aef0 <_Z24GR_Draw_Circle_Precisioni+0x8c>
 *   @0x16aecc vmov s15, r3
 *   @0x16aed0 vcvt.f32.s32 s16, s15
 *   @0x16aed4 vmul.f32 s16, s16, s18
 *   @0x16aed8 vdiv.f32 s16, s16, s17
 *   @0x16aedc vmov r0, s16
 *   @0x16aee0 bl 0xb658c <cosf@plt>
 *   @0x16aee4 mov r7, r0
 *   @0x16aee8 vmov r0, s16
 *   @0x16aeec bl 0xb6580 <sinf@plt>
 *   @0x16aef0 add r4, r4, #1
 *   @0x16aef4 str r7, [r6], #4
 *   @0x16aef8 cmp r8, r4
 *   @0x16aefc str r0, [r5], #4
 *   @0x16af00 lsl r3, r4, #1
 *   @0x16af04 bge 0x16aecc <_Z24GR_Draw_Circle_Precisioni+0x68>
 *   @0x16af08 vpop {d8, d9}
 *   @0x16af0c pop {r4, r5, r6, r7, r8, pc}
 *   @0x16af10 mov r7, #1065353216
 *   @0x16af14 mov r8, #64
 *   @0x16af18 mov r0, #0
 *   @0x16af1c vldr s17, [pc, #8]
 *   @0x16af20 b 0x16aea4 <_Z24GR_Draw_Circle_Precisioni+0x40>
 *   @0x16af24 andeq r0, r0, r0
 *   @0x16af28 ldrdmi r0, r1, [r9], #-251
 *   @0x16af2c addmi r0, r0, #0
 *   @0x16af30 eoreq r5, r8, r0, asr #5
 *   @0x16af34 eoreq r5, r8, r0, asr #5
 *   @0x16af38 eoreq r5, r8, r0, asr #5
 *
 * ══ §127/137 CCamera::Build3DView(float, float)  0x16dc0c  size 216  54 条（0x16dc0c..0x16dce4）
 * @func 0x16dc0c 0x16dce4  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c / yyMatrix::LookAtLH(yyMatrix*, yyVector3*, yyVector3*, yyVector3*) / yyMatrix::PerspectiveLH(yyMatrix*, float, float, float, float) / CCamera::SetViewMat(yyMatrix&) / CCamera::SetProjMat(yyMatrix&)
 * 字段偏移 top8: 0xc×1 / 0x18×1 / 0x10×1 / 0x1c×1 / 0x20×1 / 0x24×1 / 0x2c×1 / 0x28×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16dc0c push {r4, r5, r6, lr}
 *   @0x16dc10 vpush {d8}
 *   @0x16dc14 vldr s17, [r0, #420]
 *   @0x16dc18 vldr s16, [pc, #192]
 *   @0x16dc1c vnmul.f32 s14, s17, s16
 *   @0x16dc20 vldr s15, [r0, #396]
 *   @0x16dc24 sub sp, sp, #176
 *   @0x16dc28 mov r4, r0
 *   @0x16dc2c mov r5, #0
 *   @0x16dc30 str r1, [sp, #0xc]
 *   @0x16dc34 str r1, [sp, #0x18]
 *   @0x16dc38 str r2, [sp, #0x10]
 *   @0x16dc3c str r2, [sp, #0x1c]
 *   @0x16dc40 str r5, [sp, #0x20]
 *   @0x16dc44 vneg.f32 s15, s15
 *   @0x16dc48 vmov r0, s14
 *   @0x16dc4c vstr s15, [sp, #20]
 *   @0x16dc50 bl 0xb6580 <sinf@plt>
 *   @0x16dc54 vmul.f32 s16, s17, s16
 *   @0x16dc58 mov r6, r0
 *   @0x16dc5c vmov r0, s16
 *   @0x16dc60 bl 0xb658c <cosf@plt>
 *   @0x16dc64 str r6, [sp, #0x24]
 *   @0x16dc68 add r6, sp, #48
 *   @0x16dc6c add r1, sp, #12
 *   @0x16dc70 add r2, sp, #24
 *   @0x16dc74 add r3, sp, #36
 *   @0x16dc78 str r5, [sp, #0x2c]
 *   @0x16dc7c add r5, sp, #112
 *   @0x16dc80 str r0, [sp, #0x28]
 *   @0x16dc84 mov r0, r6
 *   @0x16dc88 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x16dc8c vldr s14, [r4, #400]
 *   @0x16dc90 vneg.f32 s14, s14
 *   @0x16dc94 vldr s15, [r4, #396]
 *   @0x16dc98 mov r1, #1065353216
 *   @0x16dc9c mov r0, r5
 *   @0x16dca0 mov r3, #0
 *   @0x16dca4 movt r3, #0x46fa
 *   @0x16dca8 str r3, [sp]
 *   @0x16dcac mov r3, r1
 *   @0x16dcb0 vdiv.f32 s15, s14, s15
 *   @0x16dcb4 vmov r2, s15
 *   @0x16dcb8 bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff>
 *   @0x16dcbc mov r0, r4
 *   @0x16dcc0 mov r1, r6
 *   @0x16dcc4 bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix>
 *   @0x16dcc8 mov r0, r4
 *   @0x16dccc mov r1, r5
 *   @0x16dcd0 bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix>
 *   @0x16dcd4 add sp, sp, #176
 *   @0x16dcd8 vpop {d8}
 *   @0x16dcdc pop {r4, r5, r6, pc}
 *   @0x16dce0 vstmialo lr, {s30, s31}
 *
 * ══ §128/137 GMGamePad::AxisValue(int) const  0x18ed9c  size 216  54 条（0x18ed9c..0x18ee74）
 * @func 0x18ed9c 0x18ee74  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GMGamePad::AxisValue(int) const+0x34 / GMGamePad::AxisValue(int) const+0xac / GMGamePad::AxisValue(int) const+0xc0
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x8×1 / 0x14×1
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ed9c cmp r1, #0
 *   @0x18eda0 blt 0x18edd0 <_ZNK9GMGamePad9AxisValueEi+0x34>
 *   @0x18eda4 tst r1, #4096
 *   @0x18eda8 beq 0x18eddc <_ZNK9GMGamePad9AxisValueEi+0x40>
 *   @0x18edac ldr r3, [r0, #0x4]
 *   @0x18edb0 bic r1, r1, #4096
 *   @0x18edb4 cmp r1, r3
 *   @0x18edb8 bge 0x18edd0 <_ZNK9GMGamePad9AxisValueEi+0x34>
 *   @0x18edbc ldr r3, [r0, #0x10]
 *   @0x18edc0 add r1, r3, r1, lsl #2
 *   @0x18edc4 vldr s15, [r1]
 *   @0x18edc8 vmov r0, s15
 *   @0x18edcc bx lr
 *   @0x18edd0 vldr s15, [pc, #152]
 *   @0x18edd4 vmov r0, s15
 *   @0x18edd8 bx lr
 *   @0x18eddc tst r1, #32768
 *   @0x18ede0 ldr r3, [r0, #0x8]
 *   @0x18ede4 bicne r1, r1, #32768
 *   @0x18ede8 vmovne.f32 s13, #-1.000000e+00
 *   @0x18edec vmoveq.f32 s13, #1.000000e+00
 *   @0x18edf0 cmp r1, r3
 *   @0x18edf4 bge 0x18edd0 <_ZNK9GMGamePad9AxisValueEi+0x34>
 *   @0x18edf8 vldr s14, [r0, #32]
 *   @0x18edfc ldr r3, [r0, #0x14]
 *   @0x18ee00 add r1, r3, r1, lsl #2
 *   @0x18ee04 vldr s15, [r1]
 *   @0x18ee08 vcmpe.f32 s14, #0
 *   @0x18ee0c vmrs APSR_nzcv, fpscr
 *   @0x18ee10 ble 0x18ee48 <_ZNK9GMGamePad9AxisValueEi+0xac>
 *   @0x18ee14 vabs.f32 s12, s15
 *   @0x18ee18 vcmpe.f32 s14, s12
 *   @0x18ee1c vmrs APSR_nzcv, fpscr
 *   @0x18ee20 bgt 0x18ee54 <_ZNK9GMGamePad9AxisValueEi+0xb8>
 *   @0x18ee24 vmov.f32 s11, #1.000000e+00
 *   @0x18ee28 vmov.f32 s10, #-1.000000e+00
 *   @0x18ee2c vcmpe.f32 s15, #0
 *   @0x18ee30 vmrs APSR_nzcv, fpscr
 *   @0x18ee34 vcmpe.f32 s14, s11
 *   @0x18ee38 vmovlt.f32 s15, s10
 *   @0x18ee3c vmovge.f32 s15, s11
 *   @0x18ee40 vmrs APSR_nzcv, fpscr
 *   @0x18ee44 blt 0x18ee5c <_ZNK9GMGamePad9AxisValueEi+0xc0>
 *   @0x18ee48 vmul.f32 s15, s15, s13
 *   @0x18ee4c vmov r0, s15
 *   @0x18ee50 bx lr
 *   @0x18ee54 vldr s15, [pc, #20]
 *   @0x18ee58 b 0x18ee48 <_ZNK9GMGamePad9AxisValueEi+0xac>
 *   @0x18ee5c vsub.f32 s12, s12, s14
 *   @0x18ee60 vsub.f32 s14, s11, s14
 *   @0x18ee64 vdiv.f32 s14, s12, s14
 *   @0x18ee68 vmul.f32 s15, s15, s14
 *   @0x18ee6c b 0x18ee48 <_ZNK9GMGamePad9AxisValueEi+0xac>
 *   @0x18ee70 andeq r0, r0, r0
 *
 * ══ §129/137 CLayerManager::RemoveTileElement(CLayer*, CLayerTileElement*)  0x1b7f64  size 216  54 条（0x1b7f64..0x1b803c）
 * @func 0x1b7f64 0x1b803c  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×3 / 0x18×2 / 0x14×2 / 0x60×2 / 0x90×1 / 0x24×1 / 0x28×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b7f64 ldr r3, [r1, #0x18]
 *   @0x1b7f68 mvn r12, #0
 *   @0x1b7f6c ldr r2, [r1, #0x14]
 *   @0x1b7f70 cmp r3, #0
 *   @0x1b7f74 push {r4, r5, r6, r7, r8, r9}
 *   @0x1b7f78 mov r5, #1065353216
 *   @0x1b7f7c strne r2, [r3, #0x14]
 *   @0x1b7f80 mov r4, #0
 *   @0x1b7f84 ldrne r2, [r1, #0x14]
 *   @0x1b7f88 mov r7, #7
 *   @0x1b7f8c ldrne r3, [r1, #0x18]
 *   @0x1b7f90 streq r2, [r0, #0x58]
 *   @0x1b7f94 cmp r2, #0
 *   @0x1b7f98 ldr r9, [r0, #0x60]
 *   @0x1b7f9c strne r3, [r2, #0x18]
 *   @0x1b7fa0 ldr r2, [pc, #0x90]
 *   @0x1b7fa4 add r9, r9, r12
 *   @0x1b7fa8 streq r3, [r0, #0x5c]
 *   @0x1b7fac mov r3, #0
 *   @0x1b7fb0 ldr r2, [pc, r2]
 *   @0x1b7fb4 str r9, [r0, #0x60]
 *   @0x1b7fb8 str r4, [r1, #0x24]
 *   @0x1b7fbc ldr r6, [r2]
 *   @0x1b7fc0 ldr r8, [r2, #0x8]
 *   @0x1b7fc4 cmp r6, r3
 *   @0x1b7fc8 str r4, [r1, #0x28]
 *   @0x1b7fcc add r0, r8, #1
 *   @0x1b7fd0 str r5, [r1, #0x34]
 *   @0x1b7fd4 str r5, [r1, #0x38]
 *   @0x1b7fd8 str r5, [r1, #0x44]
 *   @0x1b7fdc str r4, [r1, #0x3c]
 *   @0x1b7fe0 str r7, [r1]
 *   @0x1b7fe4 strb r3, [r1, #0x8]
 *   @0x1b7fe8 str r3, [r1, #0xc]
 *   @0x1b7fec str r3, [r1, #0x10]
 *   @0x1b7ff0 str r3, [r1, #0x14]
 *   @0x1b7ff4 str r3, [r1, #0x18]
 *   @0x1b7ff8 str r3, [r1, #0x2c]
 *   @0x1b7ffc str r3, [r1, #0x30]
 *   @0x1b8000 str r3, [r1, #0x48]
 *   @0x1b8004 str r3, [r1, #0x4c]
 *   @0x1b8008 str r12, [r1, #0x4]
 *   @0x1b800c str r12, [r1, #0x20]
 *   @0x1b8010 str r12, [r1, #0x40]
 *   @0x1b8014 str r0, [r2, #0x8]
 *   @0x1b8018 strne r1, [r6, #0x18]
 *   @0x1b801c streq r1, [r2, #0x4]
 *   @0x1b8020 strne r6, [r1, #0x14]
 *   @0x1b8024 streq r1, [r2]
 *   @0x1b8028 strne r1, [r2]
 *   @0x1b802c strne r3, [r1, #0x18]
 *   @0x1b8030 pop {r4, r5, r6, r7, r8, r9}
 *   @0x1b8034 bx lr
 *   @0x1b8038 eoreq r8, r3, r8, asr #17
 *
 * ══ §130/137 F_LayerSetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x1badd4  size 216  54 条（0x1badd4..0x1baeac）
 * @func 0x1badd4 0x1baeac  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetBool(RValue const*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x10×1 / 0x4×1 / 0x9c×1 / 0x18×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1badd4 cmp r3, #2
 *   @0x1badd8 mov r3, #0
 *   @0x1baddc push {r4, r5, r6, lr}
 *   @0x1bade0 mov r4, r3
 *   @0x1bade4 ldr r5, [sp, #0x10]
 *   @0x1bade8 movt r3, #0xbff0
 *   @0x1badec str r4, [r0, #0xc]
 *   @0x1badf0 str r3, [r0, #0x4]
 *   @0x1badf4 str r4, [r0]
 *   @0x1badf8 beq 0x1bae10 <_Z17F_LayerSetVisibleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1badfc ldr r0, [pc, #0x9c]
 *   @0x1bae00 mov r1, r4
 *   @0x1bae04 pop {r4, r5, r6, lr}
 *   @0x1bae08 add r0, pc, r0
 *   @0x1bae0c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bae10 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bae14 ldr r3, [r5, #0xc]
 *   @0x1bae18 mov r1, r4
 *   @0x1bae1c bic r3, r3, #-16777216
 *   @0x1bae20 cmp r3, #1
 *   @0x1bae24 mov r6, r0
 *   @0x1bae28 mov r0, r5
 *   @0x1bae2c beq 0x1bae60 <_Z17F_LayerSetVisibleR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bae30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bae34 mov r1, r0
 *   @0x1bae38 mov r0, r6
 *   @0x1bae3c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bae40 mov r4, r0
 *   @0x1bae44 cmp r4, #0
 *   @0x1bae48 beq 0x1bae78 <_Z17F_LayerSetVisibleR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1bae4c mov r0, r5
 *   @0x1bae50 mov r1, #1
 *   @0x1bae54 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1bae58 strb r0, [r4, #0x18]
 *   @0x1bae5c pop {r4, r5, r6, pc}
 *   @0x1bae60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bae64 mov r1, r0
 *   @0x1bae68 mov r0, r6
 *   @0x1bae6c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bae70 mov r4, r0
 *   @0x1bae74 b 0x1bae44 <_Z17F_LayerSetVisibleR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1bae78 ldr r3, [pc, #0x24]
 *   @0x1bae7c mov r2, r4
 *   @0x1bae80 ldr r1, [pc, #0x20]
 *   @0x1bae84 ldr r3, [pc, r3]
 *   @0x1bae88 add r1, pc, r1
 *   @0x1bae8c ldr r0, [r3]
 *   @0x1bae90 ldr r3, [r0]
 *   @0x1bae94 ldr r3, [r3, #0xc]
 *   @0x1bae98 blx r3
 *   @0x1bae9c pop {r4, r5, r6, pc}
 *   @0x1baea0 andseq r2, r9, r8, ror #21
 *   @0x1baea4 mlaeq r3, r0, r8, r2
 *   @0x1baea8 mulseq r9, r8, r10
 *
 * ══ §131/137 ShouldUseFastCollision(int, CObjectGM**)  0x1c8df8  size 216  54 条（0x1c8df8..0x1c8ed0）
 * @func 0x1c8df8 0x1c8ed0  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ShouldUseFastCollision(int, CObjectGM**)+0x18
 * 字段偏移 top8: 0x4×3 / 0xac×1 / 0x94×1 / 0x3×1 / 0x8×1 / 0xc×1 / 0x48×1 / 0xd8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c8df8 movw r3, #0x869f
 *   @0x1c8dfc movt r3, #0x1
 *   @0x1c8e00 cmp r0, r3
 *   @0x1c8e04 ble 0x1c8e10 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0x18>
 *   @0x1c8e08 mov r0, #2
 *   @0x1c8e0c bx lr
 *   @0x1c8e10 ldr r3, [pc, #0xac]
 *   @0x1c8e14 ldr r3, [pc, r3]
 *   @0x1c8e18 ldrb r3, [r3]
 *   @0x1c8e1c cmp r3, #0
 *   @0x1c8e20 beq 0x1c8e08 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0x10>
 *   @0x1c8e24 cmn r0, #3
 *   @0x1c8e28 beq 0x1c8eb4 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0xbc>
 *   @0x1c8e2c ldr r3, [pc, #0x94]
 *   @0x1c8e30 ldr r3, [pc, r3]
 *   @0x1c8e34 ldr r3, [r3]
 *   @0x1c8e38 ldr r2, [r3, #0x4]
 *   @0x1c8e3c ldr r3, [r3]
 *   @0x1c8e40 and r2, r0, r2
 *   @0x1c8e44 ldr r3, [r3, r2, lsl #3]
 *   @0x1c8e48 cmp r3, #0
 *   @0x1c8e4c bne 0x1c8e60 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0x68>
 *   @0x1c8e50 b 0x1c8ea4 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0xac>
 *   @0x1c8e54 ldr r3, [r3, #0x4]
 *   @0x1c8e58 cmp r3, #0
 *   @0x1c8e5c beq 0x1c8ea4 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0xac>
 *   @0x1c8e60 ldr r2, [r3, #0x8]
 *   @0x1c8e64 cmp r0, r2
 *   @0x1c8e68 bne 0x1c8e54 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0x5c>
 *   @0x1c8e6c ldr r2, [r3, #0xc]
 *   @0x1c8e70 cmp r2, #0
 *   @0x1c8e74 str r2, [r1]
 *   @0x1c8e78 beq 0x1c8ebc <_Z22ShouldUseFastCollisioniPP9CObjectGM+0xc4>
 *   @0x1c8e7c ldr r3, [pc, #0x48]
 *   @0x1c8e80 ldr r0, [r2, #0xd8]
 *   @0x1c8e84 ldr r3, [pc, r3]
 *   @0x1c8e88 ldr r3, [r3]
 *   @0x1c8e8c ldr r3, [r3, #0x10]
 *   @0x1c8e90 ldr r3, [r3, #0x4]
 *   @0x1c8e94 cmp r0, r3
 *   @0x1c8e98 movge r0, #1
 *   @0x1c8e9c movlt r0, #2
 *   @0x1c8ea0 bx lr
 *   @0x1c8ea4 mov r3, #0
 *   @0x1c8ea8 mvn r0, #0
 *   @0x1c8eac str r3, [r1]
 *   @0x1c8eb0 bx lr
 *   @0x1c8eb4 mov r0, #1
 *   @0x1c8eb8 bx lr
 *   @0x1c8ebc mvn r0, #0
 *   @0x1c8ec0 bx lr
 *   @0x1c8ec4 eoreq r7, r2, r12, ror #16
 *   @0x1c8ec8 eoreq r4, r2, r12, lsl #28
 *   @0x1c8ecc eoreq r5, r2, r0, asr #7
 *
 * ══ §132/137 CSingleFingerGesture::CommonUpdate(long long)  0x1d677c  size 216  54 条（0x1d677c..0x1d6854）
 * @func 0x1d677c 0x1d6854  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Button_Down(int, int) / GetRawMouseX(int) / GetRawMouseY(int) / CSingleFingerGesture::CommonUpdate(long long)+0xb4 / CalcDistInches(int, int) / __floatdisf / GR_Window_Views_Get_ID(int, int)
 * 字段偏移 top8: 0x30×4 / 0x28×3 / 0x34×3 / 0x38×2 / 0x3c×2 / 0x2c×2 / 0x4c×1 / 0x48×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d677c push {r4, r5, r6, lr}
 *   @0x1d6780 vpush {d8}
 *   @0x1d6784 mov r6, r0
 *   @0x1d6788 ldr r1, [r6, #0x28]
 *   @0x1d678c mov r0, #1
 *   @0x1d6790 mov r4, r2
 *   @0x1d6794 mov r5, r3
 *   @0x1d6798 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d679c cmp r0, #0
 *   @0x1d67a0 bne 0x1d67ac <_ZN20CSingleFingerGesture12CommonUpdateEx+0x30>
 *   @0x1d67a4 vpop {d8}
 *   @0x1d67a8 pop {r4, r5, r6, pc}
 *   @0x1d67ac ldr r2, [r6, #0x30]
 *   @0x1d67b0 ldr r3, [r6, #0x34]
 *   @0x1d67b4 ldr r0, [r6, #0x28]
 *   @0x1d67b8 str r2, [r6, #0x38]
 *   @0x1d67bc str r3, [r6, #0x3c]
 *   @0x1d67c0 bl 0x159e8c <_Z12GetRawMouseXi>
 *   @0x1d67c4 str r0, [r6, #0x30]
 *   @0x1d67c8 ldr r0, [r6, #0x28]
 *   @0x1d67cc bl 0x159eec <_Z12GetRawMouseYi>
 *   @0x1d67d0 ldrd r2, r3, [r6, #32]
 *   @0x1d67d4 ldr r1, [r6, #0x3c]
 *   @0x1d67d8 subs r4, r4, r2
 *   @0x1d67dc sbc r5, r5, r3
 *   @0x1d67e0 ldr r2, [r6, #0x30]
 *   @0x1d67e4 cmp r4, #1
 *   @0x1d67e8 sbcs r3, r5, #0
 *   @0x1d67ec ldr r3, [r6, #0x38]
 *   @0x1d67f0 rsb r1, r1, r0
 *   @0x1d67f4 str r0, [r6, #0x34]
 *   @0x1d67f8 str r1, [r6, #0x4c]
 *   @0x1d67fc rsb r0, r3, r2
 *   @0x1d6800 str r0, [r6, #0x48]
 *   @0x1d6804 blt 0x1d6830 <_ZN20CSingleFingerGesture12CommonUpdateEx+0xb4>
 *   @0x1d6808 bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1d680c mov r1, r5
 *   @0x1d6810 vmov s16, r0
 *   @0x1d6814 mov r0, r4
 *   @0x1d6818 bl 0x319398 <__floatdisf>
 *   @0x1d681c vldr s15, [pc, #44]
 *   @0x1d6820 vmov s14, r0
 *   @0x1d6824 vdiv.f32 s15, s14, s15
 *   @0x1d6828 vdiv.f32 s16, s16, s15
 *   @0x1d682c vstr s16, [r6, #88]
 *   @0x1d6830 ldr r3, [r6, #0x2c]
 *   @0x1d6834 cmn r3, #1
 *   @0x1d6838 bne 0x1d67a4 <_ZN20CSingleFingerGesture12CommonUpdateEx+0x28>
 *   @0x1d683c ldr r0, [r6, #0x30]
 *   @0x1d6840 ldr r1, [r6, #0x34]
 *   @0x1d6844 bl 0x17a3b8 <_Z22GR_Window_Views_Get_IDii>
 *   @0x1d6848 str r0, [r6, #0x2c]
 *   @0x1d684c b 0x1d67a4 <_ZN20CSingleFingerGesture12CommonUpdateEx+0x28>
 *   @0x1d6850 ldmdbmi r4!, {r10, sp} ^
 *
 * ══ §133/137 CDS_Grid::Region_Operation(int, int, int, int, int, RValue*)  0x207db4  size 216  54 条（0x207db4..0x207e8c）
 * @func 0x207db4 0x207e8c  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DoOperation(int, RValue*, RValue*) / CDS_Grid::Region_Operation(int, int, int, int, int, RValue*)+0x94
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x2c×1 / 0x30×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x207db4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x207db8 mov r5, r0
 *   @0x207dbc ldr r12, [sp, #0x28]
 *   @0x207dc0 mov r7, r1
 *   @0x207dc4 ldr r1, [sp, #0x2c]
 *   @0x207dc8 cmp r2, r12
 *   @0x207dcc ldr r8, [sp, #0x30]
 *   @0x207dd0 lsrge r0, r12, #31
 *   @0x207dd4 lsrlt r0, r2, #31
 *   @0x207dd8 cmp r2, r12
 *   @0x207ddc movlt r6, r2
 *   @0x207de0 movge r6, r12
 *   @0x207de4 cmp r0, #0
 *   @0x207de8 movne r6, #0
 *   @0x207dec cmp r3, r1
 *   @0x207df0 movlt r0, r3
 *   @0x207df4 movge r0, r1
 *   @0x207df8 cmp r3, r1
 *   @0x207dfc lsrlt r10, r3, #31
 *   @0x207e00 lsrge r10, r1, #31
 *   @0x207e04 cmp r2, r12
 *   @0x207e08 movge r9, r2
 *   @0x207e0c movlt r9, r12
 *   @0x207e10 cmp r10, #0
 *   @0x207e14 ldr r12, [r5, #0x4]
 *   @0x207e18 moveq r10, r0
 *   @0x207e1c movne r10, #0
 *   @0x207e20 cmp r3, r1
 *   @0x207e24 movge r11, r3
 *   @0x207e28 movlt r11, r1
 *   @0x207e2c cmp r9, r12
 *   @0x207e30 subge r3, r12, #1
 *   @0x207e34 movlt r3, r9
 *   @0x207e38 cmp r6, r3
 *   @0x207e3c bgt 0x207e88 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue+0xd4>
 *   @0x207e40 mov r4, r10
 *   @0x207e44 b 0x207e58 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue+0xa4>
 *   @0x207e48 ldr r1, [r5]
 *   @0x207e4c add r1, r1, r3, lsl #4
 *   @0x207e50 bl 0x207a0c <_Z11DoOperationiP6RValueS0_>
 *   @0x207e54 ldr r12, [r5, #0x4]
 *   @0x207e58 ldr r2, [r5, #0x8]
 *   @0x207e5c mov r3, r11
 *   @0x207e60 mov r0, r7
 *   @0x207e64 cmp r11, r2
 *   @0x207e68 subge r3, r2, #1
 *   @0x207e6c mov r2, r8
 *   @0x207e70 cmp r4, r3
 *   @0x207e74 mla r3, r12, r4, r6
 *   @0x207e78 add r4, r4, #1
 *   @0x207e7c ble 0x207e48 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue+0x94>
 *   @0x207e80 add r6, r6, #1
 *   @0x207e84 b 0x207e2c <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue+0x78>
 *   @0x207e88 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §134/137 cARRAY_CLASS<SRecordingDevice*>::~cARRAY_CLASS()  0x215e1c  size 216  54 条（0x215e1c..0x215ef4）
 * @func 0x215e1c 0x215ef4  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / cARRAY_CLASS<SRecordingDevice*>::~cARRAY_CLASS()+0xa8 / operator delete(void*) / cARRAY_CLASS<SRecordingDevice*>::~cARRAY_CLASS()+0x30
 * 字段偏移 top8: 0x4×5 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215e1c ldr r12, [r0]
 *   @0x215e20 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x215e24 cmp r12, #0
 *   @0x215e28 mov r7, r0
 *   @0x215e2c beq 0x215edc <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0xc0>
 *   @0x215e30 ldr r5, [r0, #0x4]
 *   @0x215e34 cmp r5, #0
 *   @0x215e38 beq 0x215ee4 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0xc8>
 *   @0x215e3c cmp r12, #0
 *   @0x215e40 ble 0x215ec4 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0xa8>
 *   @0x215e44 mov r4, #0
 *   @0x215e48 mov r8, r4
 *   @0x215e4c ldr r1, [r5]
 *   @0x215e50 movw r3, #0xfeee
 *   @0x215e54 movt r3, #0xfeee
 *   @0x215e58 movw r2, #0xfeee
 *   @0x215e5c cmp r1, r3
 *   @0x215e60 movt r2, #0xfeee
 *   @0x215e64 lsl r9, r4, #2
 *   @0x215e68 beq 0x215eb8 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x9c>
 *   @0x215e6c ldr r6, [r5, r4, lsl #2]
 *   @0x215e70 add r1, r5, r9
 *   @0x215e74 cmp r6, #0
 *   @0x215e78 beq 0x215eb8 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x9c>
 *   @0x215e7c ldr r3, [r6]
 *   @0x215e80 cmp r3, r2
 *   @0x215e84 mov r0, r3
 *   @0x215e88 beq 0x215eb0 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x94>
 *   @0x215e8c cmp r3, #0
 *   @0x215e90 beq 0x215e9c <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x80>
 *   @0x215e94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215e98 str r8, [r6]
 *   @0x215e9c mov r0, r6
 *   @0x215ea0 bl 0x27d1d0 <_ZdlPv>
 *   @0x215ea4 ldr r1, [r7, #0x4]
 *   @0x215ea8 ldr r12, [r7]
 *   @0x215eac add r1, r1, r9
 *   @0x215eb0 str r8, [r1]
 *   @0x215eb4 ldr r5, [r7, #0x4]
 *   @0x215eb8 add r4, r4, #1
 *   @0x215ebc cmp r4, r12
 *   @0x215ec0 blt 0x215e4c <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0x30>
 *   @0x215ec4 mov r0, r5
 *   @0x215ec8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215ecc mov r3, #0
 *   @0x215ed0 str r3, [r7, #0x4]
 *   @0x215ed4 mov r3, #0
 *   @0x215ed8 str r3, [r7]
 *   @0x215edc mov r0, r7
 *   @0x215ee0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x215ee4 mov r0, r5
 *   @0x215ee8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215eec str r5, [r7, #0x4]
 *   @0x215ef0 b 0x215ed4 <_ZN12cARRAY_CLASSIP16SRecordingDeviceED2Ev+0xb8>
 *
 * ══ §135/137 SoundHardware::Quit()  0x220324  size 216  47 条（0x220324..0x2203fc）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x220324 0x2203fc  size 216  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x22032c→0x755361, 0x220344→0x755363, 0x220358→0x755360, 0x220384→0x755362, 0x2203a0→0x3eb70c
 * 调用序列: Audio_Quit() / alutExit
 * 字段偏移 top8: 0x48×3 / 0xa8×2 / 0x94×1 / 0x84×1 / 0x74×1 / 0x60×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220324 push {r4, lr}
 *   @0x220328 ldr r4, [pc, #0xa8]
 *   @0x22032c ldr r3, [pc, #0xa8]
 *   @0x220330 add r4, pc, r4
 *   @0x220334 ldr r3, [r4, r3]
 *   @0x220338 ldrb r3, [r3]
 *   @0x220358 ldr r3, [pc, #0x84]
 *   @0x22035c ldr r3, [r4, r3]
 *   @0x220360 ldrb r3, [r3]
 *   @0x220364 cmp r3, #0
 *   @0x220368 popne {r4, pc}
 *   @0x22036c ldr r3, [pc, #0x74]
 *   @0x220370 add r3, pc, r3
 *   @0x220374 ldrb r3, [r3]
 *   @0x220378 cmp r3, #0
 *   @0x22037c popeq {r4, pc}
 *   @0x220380 bl 0x21a664 <_Z10Audio_Quitv>
 *   @0x220384 ldr r3, [pc, #0x60]
 *   @0x220388 ldr r3, [r4, r3]
 *   @0x22038c ldrb r3, [r3]
 *   @0x220390 cmp r3, #0
 *   @0x220394 beq 0x2203d0 <_ZN13SoundHardware4QuitEv+0xac>
 *   @0x220398 pop {r4, lr}
 *   @0x22039c b 0x2232e4 <_Z11OpenAL_Quitv>
 *   @0x2203a0 ldr r3, [pc, #0x48]
 *   @0x2203a4 ldr r2, [pc, #0x48]
 *   @0x2203a8 ldr r1, [pc, #0x48]
 *   @0x2203ac ldr r3, [r4, r3]
 *   @0x2203b0 add r2, pc, r2
 *   @0x2203b4 add r1, pc, r1
 *   @0x2203b8 add r2, r2, #8
 *   @0x2203bc ldr r0, [r3]
 *   @0x2203c0 ldr r3, [r0]
 *   @0x2203c4 ldr r3, [r3, #0xc]
 *   @0x2203c8 blx r3
 *   @0x2203cc b 0x220344 <_ZN13SoundHardware4QuitEv+0x20>
 *   @0x2203d0 bl 0x221b78 <alutExit>
 *   @0x2203d4 b 0x220398 <_ZN13SoundHardware4QuitEv+0x74>
 *   @0x2203d8 andseq r1, sp, r0, lsr #18
 *   @0x2203dc .word 0xfffff7d8
 *   @0x2203e0 .word 0xffffd3fc
 *   @0x2203e4 .word 0xfffff7e4
 *   @0x2203e8 ldrsbeq r4, [r3], #-252
 *   @0x2203ec .word 0xfffff7e0
 *   @0x2203f0 .word 0xffffbac4
 *   @0x2203f4 andseq sp, r3, r8, lsl r12
 *   @0x2203f8 andseq r4, r3, r8, lsl #9
 *
 * ══ §136/137 SND_PlatformPause()  0x21ef20  size 168  35 条（0x21ef20..0x21efc8）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21ef20 0x21efc8  size 168  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21ef28→0x755363, 0x21ef40→0x755314, 0x21ef54→0x755334, 0x21ef68→0x755338
 * 调用序列: SoundHardware::Pause(void*)
 * 字段偏移 top8: 0x84×2 / 0x70×1 / 0x60×1 / 0x50×1 / 0x4c×1 / 0x4×1 / 0x8×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21ef3c popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21ef40 ldr r2, [pc, #0x70]
 *   @0x21ef44 ldr r2, [r3, r2]
 *   @0x21ef48 ldrb r4, [r2]
 *   @0x21ef4c cmp r4, #0
 *   @0x21ef50 popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21ef54 ldr r2, [pc, #0x60]
 *   @0x21ef58 ldr r7, [r3, r2]
 *   @0x21ef5c ldr r2, [r7]
 *   @0x21ef60 cmp r2, #0
 *   @0x21ef64 pople {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21ef68 ldr r2, [pc, #0x50]
 *   @0x21ef6c mov r5, r4
 *   @0x21ef70 ldr r8, [pc, #0x4c]
 *   @0x21ef74 ldr r9, [r3, r2]
 *   @0x21ef78 add r8, pc, r8
 *   @0x21ef7c ldr r3, [r9, #0x4]
 *   @0x21ef80 add r5, r5, #1
 *   @0x21ef84 adds r6, r3, r4
 *   @0x21ef88 add r4, r4, #20
 *   @0x21ef8c beq 0x21efa0 <_Z17SND_PlatformPausev+0x80>
 *   @0x21ef90 ldr r0, [r8]
 *   @0x21ef94 ldr r1, [r6, #0x8]
 *   @0x21ef98 bl 0x220fe8 <_ZN13SoundHardware5PauseEPv>
 *   @0x21ef9c strb r0, [r6, #0x1]
 *   @0x21efa0 ldr r3, [r7]
 *   @0x21efa4 cmp r3, r5
 *   @0x21efa8 bgt 0x21ef7c <_Z17SND_PlatformPausev+0x5c>
 *   @0x21efac pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21efb0 andseq r2, sp, r4, lsr #26
 *   @0x21efb4 .word 0xffffd3fc
 *   @0x21efb8 .word 0xffffd0e0
 *   @0x21efbc .word 0xfffff7c4
 *   @0x21efc0 .word 0xfffff7c8
 *   @0x21efc4 subseq r6, r3, r12, lsr #7
 *
 * ══ §137/137 iYYRandom()  0xc4588  size 16  4 条（0xc4588..0xc4598）
 * @func 0xc4588 0xc4598  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYRandom()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4588 push {r3, lr}
 *   @0xc458c bl 0xc44ec <_Z8YYRandomv>
 *   @0xc4590 bic r0, r0, #-2147483648
 *   @0xc4594 pop {r3, pc}
 */
