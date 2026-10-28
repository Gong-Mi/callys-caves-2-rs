/* libyoyo.so 覆盖卡组 0062
 * 函数 0x12dc64..0x12e6dc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x12dc64 · F_PathReverse(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12dc64 push {r3, lr} */
/* @0x12dc68 mov r1, #0 */
/* @0x12dc6c ldr r0, [sp, #0x8] */
/* @0x12dc70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dc74 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dc78 cmp r0, #0 */
/* @0x12dc7c popeq {r3, pc} */
/* @0x12dc80 pop {r3, lr} */
/* @0x12dc84 b 0x1a76b4 <_ZN5CPath7ReverseEv> */

/* ── FUNC 0x12dc88 · F_PathMirror(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12dc88 push {r3, lr} */
/* @0x12dc8c mov r1, #0 */
/* @0x12dc90 ldr r0, [sp, #0x8] */
/* @0x12dc94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dc98 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dc9c cmp r0, #0 */
/* @0x12dca0 popeq {r3, pc} */
/* @0x12dca4 pop {r3, lr} */
/* @0x12dca8 b 0x1a777c <_ZN5CPath6MirrorEv> */

/* ── FUNC 0x12dcac · F_PathFlip(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12dcac push {r3, lr} */
/* @0x12dcb0 mov r1, #0 */
/* @0x12dcb4 ldr r0, [sp, #0x8] */
/* @0x12dcb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dcbc bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dcc0 cmp r0, #0 */
/* @0x12dcc4 popeq {r3, pc} */
/* @0x12dcc8 pop {r3, lr} */
/* @0x12dccc b 0x1a77fc <_ZN5CPath4FlipEv> */

/* ── FUNC 0x12dcd0 · F_PathRotate(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x12dcd0 push {r3, r4, r5, lr} */
/* @0x12dcd4 mov r1, #0 */
/* @0x12dcd8 ldr r4, [sp, #0x10] */
/* @0x12dcdc mov r0, r4 */
/* @0x12dce0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dce4 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dce8 subs r5, r0, #0 */
/* @0x12dcec popeq {r3, r4, r5, pc} */
/* @0x12dcf0 mov r0, r4 */
/* @0x12dcf4 mov r1, #1 */
/* @0x12dcf8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dcfc mov r1, r0 */
/* @0x12dd00 mov r0, r5 */
/* @0x12dd04 pop {r3, r4, r5, lr} */
/* @0x12dd08 b 0x1a787c <_ZN5CPath6RotateEf> */

/* ── FUNC 0x12dd0c · F_PathReScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12dd0c push {r4, r5, r6, lr} */
/* @0x12dd10 mov r1, #0 */
/* @0x12dd14 ldr r4, [sp, #0x10] */
/* @0x12dd18 mov r0, r4 */
/* @0x12dd1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dd20 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dd24 subs r5, r0, #0 */
/* @0x12dd28 popeq {r4, r5, r6, pc} */
/* @0x12dd2c mov r0, r4 */
/* @0x12dd30 mov r1, #1 */
/* @0x12dd34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dd38 mov r1, #2 */
/* @0x12dd3c mov r6, r0 */
/* @0x12dd40 mov r0, r4 */
/* @0x12dd44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dd48 mov r1, r6 */
/* @0x12dd4c mov r2, r0 */
/* @0x12dd50 mov r0, r5 */
/* @0x12dd54 pop {r4, r5, r6, lr} */
/* @0x12dd58 b 0x1a794c <_ZN5CPath5ScaleEff> */

/* ── FUNC 0x12dd5c · F_PathShift(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12dd5c push {r4, r5, r6, lr} */
/* @0x12dd60 mov r1, #0 */
/* @0x12dd64 ldr r4, [sp, #0x10] */
/* @0x12dd68 mov r0, r4 */
/* @0x12dd6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dd70 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12dd74 subs r5, r0, #0 */
/* @0x12dd78 popeq {r4, r5, r6, pc} */
/* @0x12dd7c mov r0, r4 */
/* @0x12dd80 mov r1, #1 */
/* @0x12dd84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dd88 mov r1, #2 */
/* @0x12dd8c mov r6, r0 */
/* @0x12dd90 mov r0, r4 */
/* @0x12dd94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12dd98 mov r1, r6 */
/* @0x12dd9c mov r2, r0 */
/* @0x12dda0 mov r0, r5 */
/* @0x12dda4 pop {r4, r5, r6, lr} */
/* @0x12dda8 b 0x1a7734 <_ZN5CPath5ShiftEff> */

/* ── FUNC 0x12ddac · F_ScriptExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x12ddac push {r3, r4, r5, lr} */
/* @0x12ddb0 mov r1, #0 */
/* @0x12ddb4 mov r4, r0 */
/* @0x12ddb8 ldr r0, [sp, #0x10] */
/* @0x12ddbc mov r5, r1 */
/* @0x12ddc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ddc4 str r5, [r4, #0xc] */
/* @0x12ddc8 bl 0x1e0544 <_Z13Script_Existsi> */
/* @0x12ddcc cmp r0, #0 */
/* @0x12ddd0 movne r0, r5 */
/* @0x12ddd4 moveq r3, r0 */
/* @0x12ddd8 movne r3, r0 */
/* @0x12dddc movtne r3, #0x3ff0 */
/* @0x12dde0 stm r4, {r0, r3} */
/* @0x12dde4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x12dde8 · F_ScriptGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x12dde8 push {r4, lr} */
/* @0x12ddec mov r1, #0 */
/* @0x12ddf0 mov r4, r0 */
/* @0x12ddf4 ldr r0, [sp, #0x8] */
/* @0x12ddf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ddfc bl 0x1e058c <_Z11Script_Namei> */
/* @0x12de00 mov r1, r0 */
/* @0x12de04 mov r0, r4 */
/* @0x12de08 pop {r4, lr} */
/* @0x12de0c b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12de10 · F_ScriptGetText(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12de10 push {r4, lr} */
/* @0x12de14 mov r1, #0 */
/* @0x12de18 mov r4, r0 */
/* @0x12de1c ldr r0, [sp, #0x8] */
/* @0x12de20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12de24 bl 0x1e069c <_Z11Script_Datai> */
/* @0x12de28 subs r1, r0, #0 */
/* @0x12de2c beq 0x12de38 <_Z15F_ScriptGetTextR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x12de30 bl 0x1dfe94 <_ZN7CScript7GetTextEv> */
/* @0x12de34 mov r1, r0 */
/* @0x12de38 mov r0, r4 */
/* @0x12de3c pop {r4, lr} */
/* @0x12de40 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12de44 · F_TimeLineExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x12de44 push {r3, r4, r5, lr} */
/* @0x12de48 mov r5, #0 */
/* @0x12de4c mov r4, r0 */
/* @0x12de50 mov r1, r5 */
/* @0x12de54 str r5, [r0, #0xc] */
/* @0x12de58 ldr r0, [sp, #0x10] */
/* @0x12de5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12de60 bl 0x1f2b18 <_Z15TimeLine_Existsi> */
/* @0x12de64 cmp r0, #0 */
/* @0x12de68 moveq r5, r0 */
/* @0x12de6c movne r3, r5 */
/* @0x12de70 moveq r3, r5 */
/* @0x12de74 movtne r3, #0x3ff0 */
/* @0x12de78 str r5, [r4] */
/* @0x12de7c str r3, [r4, #0x4] */
/* @0x12de80 pop {r3, r4, r5, pc} */

/* ── FUNC 0x12de84 · F_TimeLineGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x12de84 push {r4, lr} */
/* @0x12de88 mov r1, #0 */
/* @0x12de8c mov r4, r0 */
/* @0x12de90 ldr r0, [sp, #0x8] */
/* @0x12de94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12de98 bl 0x1f2b58 <_Z13TimeLine_Namei> */
/* @0x12de9c mov r1, r0 */
/* @0x12dea0 mov r0, r4 */
/* @0x12dea4 pop {r4, lr} */
/* @0x12dea8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12deac · F_TimeLineAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x12deac push {r4, lr} */
/* @0x12deb0 mov r3, #0 */
/* @0x12deb4 str r3, [r0, #0xc] */
/* @0x12deb8 mov r4, r0 */
/* @0x12debc bl 0x1f2cfc <_Z12TimeLine_Addv> */
/* @0x12dec0 vmov s15, r0 */
/* @0x12dec4 vcvt.f64.s32 d7, s15 */
/* @0x12dec8 vmov r0, r1, d7 */
/* @0x12decc vmov r2, s14 */
/* @0x12ded0 mov r3, r1 */
/* @0x12ded4 stm r4, {r2, r3} */
/* @0x12ded8 pop {r4, pc} */

/* ── FUNC 0x12dedc · F_TimeLineDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x12dedc push {r4, r5, r6, lr} */
/* @0x12dee0 mov r1, #0 */
/* @0x12dee4 mov r4, r0 */
/* @0x12dee8 ldr r0, [sp, #0x10] */
/* @0x12deec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12def0 mov r6, r0 */
/* @0x12def4 bl 0x1f2b18 <_Z15TimeLine_Existsi> */
/* @0x12def8 subs r5, r0, #0 */
/* @0x12defc bne 0x12df28 <_Z16F_TimeLineDeleteR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12df00 ldr r0, [pc, #0x44] */
/* @0x12df04 mov r1, r5 */
/* @0x12df08 add r0, pc, r0 */
/* @0x12df0c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12df10 str r5, [r4, #0xc] */
/* @0x12df14 mov r3, #0 */
/* @0x12df18 mov r2, r3 */
/* @0x12df1c str r3, [r4] */
/* @0x12df20 str r2, [r4, #0x4] */
/* @0x12df24 pop {r4, r5, r6, pc} */
/* @0x12df28 mov r0, r6 */
/* @0x12df2c bl 0x1f2fb4 <_Z15TimeLine_Deletei> */
/* @0x12df30 mov r3, #0 */
/* @0x12df34 str r3, [r4, #0xc] */
/* @0x12df38 cmp r0, r3 */
/* @0x12df3c movne r2, #0 */
/* @0x12df40 movtne r2, #0x3ff0 */
/* @0x12df44 bne 0x12df1c <_Z16F_TimeLineDeleteR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12df48 b 0x12df14 <_Z16F_TimeLineDeleteR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x12df4c eoreq pc, r0, r4, lsr r7 */

/* ── FUNC 0x12df50 · F_TimeLineMomentClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x12df50 push {r3, r4, r5, lr} */
/* @0x12df54 mov r1, #0 */
/* @0x12df58 ldr r4, [sp, #0x10] */
/* @0x12df5c mov r0, r4 */
/* @0x12df60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12df64 bl 0x1f2c48 <_Z13TimeLine_Datai> */
/* @0x12df68 subs r5, r0, #0 */
/* @0x12df6c popeq {r3, r4, r5, pc} */
/* @0x12df70 mov r0, r4 */
/* @0x12df74 mov r1, #1 */
/* @0x12df78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12df7c mov r1, r0 */
/* @0x12df80 mov r0, r5 */
/* @0x12df84 pop {r3, r4, r5, lr} */
/* @0x12df88 b 0x1f2250 <_ZN9CTimeLine12DeleteMomentEi> */

/* ── FUNC 0x12df8c · F_TimeLineClearAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12df8c push {r3, lr} */
/* @0x12df90 mov r1, #0 */
/* @0x12df94 ldr r0, [sp, #0x8] */
/* @0x12df98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12df9c bl 0x1f2c48 <_Z13TimeLine_Datai> */
/* @0x12dfa0 cmp r0, #0 */
/* @0x12dfa4 popeq {r3, pc} */
/* @0x12dfa8 pop {r3, lr} */
/* @0x12dfac b 0x1f1768 <_ZN9CTimeLine5ClearEv> */

/* ── FUNC 0x12dfb0 · F_TimeLineSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12dfb0 push {r4, lr} */
/* @0x12dfb4 mov r1, #0 */
/* @0x12dfb8 mov r4, r0 */
/* @0x12dfbc ldr r0, [sp, #0x8] */
/* @0x12dfc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12dfc4 bl 0x1f2c48 <_Z13TimeLine_Datai> */
/* @0x12dfc8 cmp r0, #0 */
/* @0x12dfcc beq 0x12dff0 <_Z14F_TimeLineSizeR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12dfd0 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv> */
/* @0x12dfd4 vmov s15, r0 */
/* @0x12dfd8 vcvt.f64.s32 d7, s15 */
/* @0x12dfdc vmov r2, r3, d7 */
/* @0x12dfe0 mov r1, #0 */
/* @0x12dfe4 stm r4, {r2, r3} */
/* @0x12dfe8 str r1, [r4, #0xc] */
/* @0x12dfec pop {r4, pc} */
/* @0x12dff0 mov r3, #0 */
/* @0x12dff4 mov r2, #0 */
/* @0x12dff8 movt r3, #0xbff0 */
/* @0x12dffc b 0x12dfe0 <_Z14F_TimeLineSizeR6RValueP9CInstanceS2_iPS_+0x30> */

/* ── FUNC 0x12e000 · F_TimeLineMaxMoment(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x12e000 push {r3, r4, r5, lr} */
/* @0x12e004 mov r1, #0 */
/* @0x12e008 mov r4, r0 */
/* @0x12e00c ldr r0, [sp, #0x10] */
/* @0x12e010 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e014 bl 0x1f2c48 <_Z13TimeLine_Datai> */
/* @0x12e018 subs r5, r0, #0 */
/* @0x12e01c beq 0x12e04c <_Z19F_TimeLineMaxMomentR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12e020 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv> */
/* @0x12e024 sub r1, r0, #1 */
/* @0x12e028 mov r0, r5 */
/* @0x12e02c bl 0x1f1738 <_ZN9CTimeLine7GetStepEi> */
/* @0x12e030 vmov s15, r0 */
/* @0x12e034 vcvt.f64.s32 d7, s15 */
/* @0x12e038 vmov r2, r3, d7 */
/* @0x12e03c mov r1, #0 */
/* @0x12e040 stm r4, {r2, r3} */
/* @0x12e044 str r1, [r4, #0xc] */
/* @0x12e048 pop {r3, r4, r5, pc} */
/* @0x12e04c mov r3, #0 */
/* @0x12e050 mov r2, #0 */
/* @0x12e054 movt r3, #0xbff0 */
/* @0x12e058 b 0x12e03c <_Z19F_TimeLineMaxMomentR6RValueP9CInstanceS2_iPS_+0x3c> */

/* ── FUNC 0x12e05c · F_TimeLineMomentAddScript(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x12e05c push {r4, r5, r6, lr} */
/* @0x12e060 mov r1, #0 */
/* @0x12e064 ldr r4, [sp, #0x10] */
/* @0x12e068 mov r0, r4 */
/* @0x12e06c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e070 bl 0x1f2c48 <_Z13TimeLine_Datai> */
/* @0x12e074 subs r5, r0, #0 */
/* @0x12e078 popeq {r4, r5, r6, pc} */
/* @0x12e07c mov r0, r4 */
/* @0x12e080 mov r1, #1 */
/* @0x12e084 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e088 mov r1, #2 */
/* @0x12e08c mov r6, r0 */
/* @0x12e090 mov r0, r4 */
/* @0x12e094 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e098 mov r1, r6 */
/* @0x12e09c mov r4, r0 */
/* @0x12e0a0 mov r0, r5 */
/* @0x12e0a4 bl 0x1f1c28 <_ZN9CTimeLine4FindEi> */
/* @0x12e0a8 mov r1, r6 */
/* @0x12e0ac mov r2, r4 */
/* @0x12e0b0 cmp r0, #0 */
/* @0x12e0b4 mov r0, r5 */
/* @0x12e0b8 blt 0x12e0c4 <_Z25F_TimeLineMomentAddScriptR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x12e0bc pop {r4, r5, r6, lr} */
/* @0x12e0c0 b 0x1f1f9c <_ZN9CTimeLine16MakeMomentScriptEii> */
/* @0x12e0c4 pop {r4, r5, r6, lr} */
/* @0x12e0c8 b 0x1f1d80 <_ZN9CTimeLine15AddMomentScriptEii> */

/* ── FUNC 0x12e0cc · F_ObjectExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x12e0cc push {r3, r4, r5, lr} */
/* @0x12e0d0 mov r5, #0 */
/* @0x12e0d4 mov r4, r0 */
/* @0x12e0d8 mov r1, r5 */
/* @0x12e0dc str r5, [r0, #0xc] */
/* @0x12e0e0 ldr r0, [sp, #0x10] */
/* @0x12e0e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e0e8 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x12e0ec cmp r0, #0 */
/* @0x12e0f0 moveq r5, r0 */
/* @0x12e0f4 movne r3, r5 */
/* @0x12e0f8 moveq r3, r5 */
/* @0x12e0fc movtne r3, #0x3ff0 */
/* @0x12e100 str r5, [r4] */
/* @0x12e104 str r3, [r4, #0x4] */
/* @0x12e108 pop {r3, r4, r5, pc} */

/* ── FUNC 0x12e10c · F_ObjectGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x12e10c push {r4, lr} */
/* @0x12e110 mov r1, #0 */
/* @0x12e114 mov r4, r0 */
/* @0x12e118 ldr r0, [sp, #0x8] */
/* @0x12e11c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e120 bl 0x19ed54 <_Z11Object_Namei> */
/* @0x12e124 mov r1, r0 */
/* @0x12e128 mov r0, r4 */
/* @0x12e12c pop {r4, lr} */
/* @0x12e130 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12e134 · F_ObjectAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x12e134 push {r4, lr} */
/* @0x12e138 mov r3, #0 */
/* @0x12e13c str r3, [r0, #0xc] */
/* @0x12e140 mov r4, r0 */
/* @0x12e144 bl 0x19eebc <_Z10Object_Addv> */
/* @0x12e148 vmov s15, r0 */
/* @0x12e14c vcvt.f64.s32 d7, s15 */
/* @0x12e150 vmov r0, r1, d7 */
/* @0x12e154 vmov r2, s14 */
/* @0x12e158 mov r3, r1 */
/* @0x12e15c stm r4, {r2, r3} */
/* @0x12e160 pop {r4, pc} */

/* ── FUNC 0x12e164 · F_ObjectDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x12e164 push {r4, r5, r6, lr} */
/* @0x12e168 mov r1, #0 */
/* @0x12e16c mov r4, r0 */
/* @0x12e170 ldr r0, [sp, #0x10] */
/* @0x12e174 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e178 mov r6, r0 */
/* @0x12e17c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x12e180 subs r5, r0, #0 */
/* @0x12e184 beq 0x12e1b4 <_Z14F_ObjectDeleteR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x12e188 mov r0, r6 */
/* @0x12e18c bl 0x19f014 <_Z13Object_Deletei> */
/* @0x12e190 mov r3, #0 */
/* @0x12e194 str r3, [r4, #0xc] */
/* @0x12e198 cmp r0, r3 */
/* @0x12e19c movne r2, #0 */
/* @0x12e1a0 movtne r2, #0x3ff0 */
/* @0x12e1a4 beq 0x12e1c8 <_Z14F_ObjectDeleteR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12e1a8 str r3, [r4] */
/* @0x12e1ac str r2, [r4, #0x4] */
/* @0x12e1b0 pop {r4, r5, r6, pc} */
/* @0x12e1b4 ldr r0, [pc, #0x18] */
/* @0x12e1b8 mov r1, r5 */
/* @0x12e1bc add r0, pc, r0 */
/* @0x12e1c0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12e1c4 str r5, [r4, #0xc] */
/* @0x12e1c8 mov r3, #0 */
/* @0x12e1cc mov r2, r3 */
/* @0x12e1d0 b 0x12e1a8 <_Z14F_ObjectDeleteR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x12e1d4 eoreq pc, r0, r8, lsr #9 */

/* ── FUNC 0x12e1d8 · F_ObjectEventClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x12e1d8 push {r4, r5, r6, lr} */
/* @0x12e1dc mov r1, #0 */
/* @0x12e1e0 ldr r4, [sp, #0x10] */
/* @0x12e1e4 mov r0, r4 */
/* @0x12e1e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e1ec ldr r3, [pc, #0x88] */
/* @0x12e1f0 ldr r3, [pc, r3] */
/* @0x12e1f4 ldr r3, [r3] */
/* @0x12e1f8 ldr r2, [r3, #0x4] */
/* @0x12e1fc ldr r3, [r3] */
/* @0x12e200 and r2, r0, r2 */
/* @0x12e204 ldr r3, [r3, r2, lsl #3] */
/* @0x12e208 cmp r3, #0 */
/* @0x12e20c bne 0x12e220 <_Z18F_ObjectEventClearR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12e210 pop {r4, r5, r6, pc} */
/* @0x12e214 ldr r3, [r3, #0x4] */
/* @0x12e218 cmp r3, #0 */
/* @0x12e21c beq 0x12e278 <_Z18F_ObjectEventClearR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x12e220 ldr r2, [r3, #0x8] */
/* @0x12e224 cmp r0, r2 */
/* @0x12e228 bne 0x12e214 <_Z18F_ObjectEventClearR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12e22c ldr r5, [r3, #0xc] */
/* @0x12e230 cmp r5, #0 */
/* @0x12e234 popeq {r4, r5, r6, pc} */
/* @0x12e238 mov r1, #1 */
/* @0x12e23c mov r0, r4 */
/* @0x12e240 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e244 mov r1, #2 */
/* @0x12e248 mov r6, r0 */
/* @0x12e24c mov r0, r4 */
/* @0x12e250 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e254 mov r1, r6 */
/* @0x12e258 mov r2, r0 */
/* @0x12e25c mov r0, r5 */
/* @0x12e260 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii> */
/* @0x12e264 cmp r0, #0 */
/* @0x12e268 popeq {r4, r5, r6, pc} */
/* @0x12e26c bl 0xf2d08 <_ZN6CEvent5ClearEv> */
/* @0x12e270 pop {r4, r5, r6, lr} */
/* @0x12e274 b 0x19e7dc <_Z19Create_Object_Listsv> */
/* @0x12e278 pop {r4, r5, r6, pc} */
/* @0x12e27c eoreq pc, r11, r12, asr #20 */

/* ── FUNC 0x12e280 · F_RoomExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x12e280 push {r3, r4, r5, lr} */
/* @0x12e284 mov r5, #0 */
/* @0x12e288 mov r4, r0 */
/* @0x12e28c mov r1, r5 */
/* @0x12e290 str r5, [r0, #0xc] */
/* @0x12e294 ldr r0, [sp, #0x10] */
/* @0x12e298 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e29c bl 0x1b52f8 <_Z11Room_Existsi> */
/* @0x12e2a0 cmp r0, #0 */
/* @0x12e2a4 moveq r5, r0 */
/* @0x12e2a8 movne r3, r5 */
/* @0x12e2ac moveq r3, r5 */
/* @0x12e2b0 movtne r3, #0x3ff0 */
/* @0x12e2b4 str r5, [r4] */
/* @0x12e2b8 str r3, [r4, #0x4] */
/* @0x12e2bc pop {r3, r4, r5, pc} */

/* ── FUNC 0x12e2c0 · F_RoomGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x12e2c0 push {r4, lr} */
/* @0x12e2c4 mov r1, #0 */
/* @0x12e2c8 mov r4, r0 */
/* @0x12e2cc ldr r0, [sp, #0x8] */
/* @0x12e2d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e2d4 bl 0x1b530c <_Z9Room_Namei> */
/* @0x12e2d8 mov r1, r0 */
/* @0x12e2dc mov r0, r4 */
/* @0x12e2e0 pop {r4, lr} */
/* @0x12e2e4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12e2e8 · F_RoomSetView(RValue&, CInstance*, CInstance*, int, RValue*) · size=308 · insn=77 */
/* @0x12e2e8 push {r4, r5, r6, lr} */
/* @0x12e2ec mov r1, #0 */
/* @0x12e2f0 ldr r4, [sp, #0x10] */
/* @0x12e2f4 mov r0, r4 */
/* @0x12e2f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e2fc mov r1, #1 */
/* @0x12e300 mov r6, r0 */
/* @0x12e304 mov r0, r4 */
/* @0x12e308 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e30c mov r5, r0 */
/* @0x12e310 mov r0, r6 */
/* @0x12e314 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e318 cmp r0, #0 */
/* @0x12e31c popeq {r4, r5, r6, pc} */
/* @0x12e320 cmp r5, #7 */
/* @0x12e324 pophi {r4, r5, r6, pc} */
/* @0x12e328 add r5, r5, #18 */
/* @0x12e32c ldr r5, [r0, r5, lsl #2] */
/* @0x12e330 cmp r5, #0 */
/* @0x12e334 popeq {r4, r5, r6, pc} */
/* @0x12e338 mov r1, #2 */
/* @0x12e33c mov r0, r4 */
/* @0x12e340 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e344 mov r1, #3 */
/* @0x12e348 strb r0, [r5] */
/* @0x12e34c mov r0, r4 */
/* @0x12e350 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e354 mov r1, #4 */
/* @0x12e358 str r0, [r5, #0x4] */
/* @0x12e35c mov r0, r4 */
/* @0x12e360 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e364 mov r1, #5 */
/* @0x12e368 str r0, [r5, #0x8] */
/* @0x12e36c mov r0, r4 */
/* @0x12e370 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e374 mov r1, #6 */
/* @0x12e378 str r0, [r5, #0xc] */
/* @0x12e37c mov r0, r4 */
/* @0x12e380 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e384 mov r1, #7 */
/* @0x12e388 str r0, [r5, #0x10] */
/* @0x12e38c mov r0, r4 */
/* @0x12e390 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e394 mov r1, #8 */
/* @0x12e398 str r0, [r5, #0x14] */
/* @0x12e39c mov r0, r4 */
/* @0x12e3a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e3a4 mov r1, #9 */
/* @0x12e3a8 str r0, [r5, #0x18] */
/* @0x12e3ac mov r0, r4 */
/* @0x12e3b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e3b4 mov r1, #10 */
/* @0x12e3b8 str r0, [r5, #0x1c] */
/* @0x12e3bc mov r0, r4 */
/* @0x12e3c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e3c4 mov r1, #11 */
/* @0x12e3c8 str r0, [r5, #0x20] */
/* @0x12e3cc mov r0, r4 */
/* @0x12e3d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e3d4 mov r1, #12 */
/* @0x12e3d8 str r0, [r5, #0x28] */
/* @0x12e3dc mov r0, r4 */
/* @0x12e3e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e3e4 mov r1, #13 */
/* @0x12e3e8 str r0, [r5, #0x2c] */
/* @0x12e3ec mov r0, r4 */
/* @0x12e3f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e3f4 mov r1, #14 */
/* @0x12e3f8 str r0, [r5, #0x30] */
/* @0x12e3fc mov r0, r4 */
/* @0x12e400 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e404 mov r1, #15 */
/* @0x12e408 str r0, [r5, #0x34] */
/* @0x12e40c mov r0, r4 */
/* @0x12e410 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e414 str r0, [r5, #0x38] */
/* @0x12e418 pop {r4, r5, r6, pc} */

/* ── FUNC 0x12e41c · F_RoomSetViewport(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x12e41c push {r4, r5, r6, lr} */
/* @0x12e420 mov r1, #0 */
/* @0x12e424 ldr r4, [sp, #0x10] */
/* @0x12e428 mov r0, r4 */
/* @0x12e42c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e430 mov r1, #1 */
/* @0x12e434 mov r6, r0 */
/* @0x12e438 mov r0, r4 */
/* @0x12e43c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e440 mov r5, r0 */
/* @0x12e444 mov r0, r6 */
/* @0x12e448 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e44c cmp r0, #0 */
/* @0x12e450 popeq {r4, r5, r6, pc} */
/* @0x12e454 cmp r5, #7 */
/* @0x12e458 pophi {r4, r5, r6, pc} */
/* @0x12e45c add r5, r5, #18 */
/* @0x12e460 ldr r5, [r0, r5, lsl #2] */
/* @0x12e464 cmp r5, #0 */
/* @0x12e468 popeq {r4, r5, r6, pc} */
/* @0x12e46c mov r1, #2 */
/* @0x12e470 mov r0, r4 */
/* @0x12e474 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e478 mov r1, #3 */
/* @0x12e47c strb r0, [r5] */
/* @0x12e480 mov r0, r4 */
/* @0x12e484 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e488 mov r1, #4 */
/* @0x12e48c str r0, [r5, #0x14] */
/* @0x12e490 mov r0, r4 */
/* @0x12e494 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e498 mov r1, #5 */
/* @0x12e49c str r0, [r5, #0x18] */
/* @0x12e4a0 mov r0, r4 */
/* @0x12e4a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e4a8 mov r1, #6 */
/* @0x12e4ac str r0, [r5, #0x1c] */
/* @0x12e4b0 mov r0, r4 */
/* @0x12e4b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e4b8 str r0, [r5, #0x20] */
/* @0x12e4bc pop {r4, r5, r6, pc} */

/* ── FUNC 0x12e4c0 · F_RoomGetCamera(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x12e4c0 push {r4, r5, r6, lr} */
/* @0x12e4c4 mov r1, #0 */
/* @0x12e4c8 ldr r5, [sp, #0x10] */
/* @0x12e4cc mov r4, r0 */
/* @0x12e4d0 str r1, [r0, #0xc] */
/* @0x12e4d4 mov r0, r5 */
/* @0x12e4d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e4dc mov r1, #1 */
/* @0x12e4e0 mov r6, r0 */
/* @0x12e4e4 mov r0, r5 */
/* @0x12e4e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e4ec mov r5, r0 */
/* @0x12e4f0 mov r0, r6 */
/* @0x12e4f4 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e4f8 cmp r0, #0 */
/* @0x12e4fc beq 0x12e530 <_Z15F_RoomGetCameraR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x12e500 cmp r5, #7 */
/* @0x12e504 bhi 0x12e530 <_Z15F_RoomGetCameraR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x12e508 add r5, r5, #18 */
/* @0x12e50c ldr r3, [r0, r5, lsl #2] */
/* @0x12e510 cmp r3, #0 */
/* @0x12e514 beq 0x12e530 <_Z15F_RoomGetCameraR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x12e518 ldr r2, [r3, #0x40] */
/* @0x12e51c vmov s15, r2 */
/* @0x12e520 vcvt.f64.s32 d7, s15 */
/* @0x12e524 vmov r2, r3, d7 */
/* @0x12e528 stm r4, {r2, r3} */
/* @0x12e52c pop {r4, r5, r6, pc} */
/* @0x12e530 mov r3, #0 */
/* @0x12e534 mov r2, r3 */
/* @0x12e538 movt r3, #0xbff0 */
/* @0x12e53c stm r4, {r2, r3} */
/* @0x12e540 pop {r4, r5, r6, pc} */

/* ── FUNC 0x12e544 · F_RoomSetCamera(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x12e544 push {r4, r5, r6, lr} */
/* @0x12e548 mov r1, #0 */
/* @0x12e54c ldr r4, [sp, #0x10] */
/* @0x12e550 mov r0, r4 */
/* @0x12e554 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e558 mov r1, #1 */
/* @0x12e55c mov r6, r0 */
/* @0x12e560 mov r0, r4 */
/* @0x12e564 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e568 mov r1, #2 */
/* @0x12e56c mov r5, r0 */
/* @0x12e570 mov r0, r4 */
/* @0x12e574 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e578 mov r4, r0 */
/* @0x12e57c mov r0, r6 */
/* @0x12e580 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e584 cmp r0, #0 */
/* @0x12e588 popeq {r4, r5, r6, pc} */
/* @0x12e58c cmp r5, #7 */
/* @0x12e590 pophi {r4, r5, r6, pc} */
/* @0x12e594 add r5, r5, #18 */
/* @0x12e598 ldr r3, [r0, r5, lsl #2] */
/* @0x12e59c cmp r3, #0 */
/* @0x12e5a0 strne r4, [r3, #0x40] */
/* @0x12e5a4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x12e5a8 · F_RoomSetBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0x12e5a8 push {r4, r5, r6, lr} */
/* @0x12e5ac mov r1, #0 */
/* @0x12e5b0 ldr r4, [sp, #0x10] */
/* @0x12e5b4 mov r0, r4 */
/* @0x12e5b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e5bc mov r1, #1 */
/* @0x12e5c0 mov r6, r0 */
/* @0x12e5c4 mov r0, r4 */
/* @0x12e5c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e5cc mov r5, r0 */
/* @0x12e5d0 mov r0, r6 */
/* @0x12e5d4 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e5d8 cmp r0, #0 */
/* @0x12e5dc popeq {r4, r5, r6, pc} */
/* @0x12e5e0 cmp r5, #7 */
/* @0x12e5e4 pophi {r4, r5, r6, pc} */
/* @0x12e5e8 add r5, r0, r5, lsl #2 */
/* @0x12e5ec ldr r5, [r5, #0x24] */
/* @0x12e5f0 cmp r5, #0 */
/* @0x12e5f4 popeq {r4, r5, r6, pc} */
/* @0x12e5f8 mov r1, #2 */
/* @0x12e5fc mov r0, r4 */
/* @0x12e600 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e604 mov r1, #3 */
/* @0x12e608 strb r0, [r5] */
/* @0x12e60c mov r0, r4 */
/* @0x12e610 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e614 mov r1, #4 */
/* @0x12e618 strb r0, [r5, #0x1] */
/* @0x12e61c mov r0, r4 */
/* @0x12e620 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e624 mov r1, #5 */
/* @0x12e628 str r0, [r5, #0x4] */
/* @0x12e62c mov r0, r4 */
/* @0x12e630 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e634 mov r1, #6 */
/* @0x12e638 str r0, [r5, #0x8] */
/* @0x12e63c mov r0, r4 */
/* @0x12e640 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e644 mov r1, #7 */
/* @0x12e648 str r0, [r5, #0xc] */
/* @0x12e64c mov r0, r4 */
/* @0x12e650 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e654 mov r1, #8 */
/* @0x12e658 strb r0, [r5, #0x10] */
/* @0x12e65c mov r0, r4 */
/* @0x12e660 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e664 mov r3, #1065353216 */
/* @0x12e668 mov r1, #9 */
/* @0x12e66c str r3, [r5, #0x1c] */
/* @0x12e670 str r3, [r5, #0x20] */
/* @0x12e674 strb r0, [r5, #0x11] */
/* @0x12e678 mov r0, r4 */
/* @0x12e67c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e680 mov r1, #10 */
/* @0x12e684 str r0, [r5, #0x14] */
/* @0x12e688 mov r0, r4 */
/* @0x12e68c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e690 mov r1, #11 */
/* @0x12e694 str r0, [r5, #0x18] */
/* @0x12e698 mov r0, r4 */
/* @0x12e69c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e6a0 str r0, [r5, #0x28] */
/* @0x12e6a4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x12e6a8 · F_RoomSetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12e6a8 push {r3, r4, r5, lr} */
/* @0x12e6ac mov r1, #0 */
/* @0x12e6b0 ldr r4, [sp, #0x10] */
/* @0x12e6b4 mov r0, r4 */
/* @0x12e6b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e6bc bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e6c0 subs r5, r0, #0 */
/* @0x12e6c4 popeq {r3, r4, r5, pc} */
/* @0x12e6c8 mov r0, r4 */
/* @0x12e6cc mov r1, #1 */
/* @0x12e6d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e6d4 str r0, [r5, #0x14] */
/* @0x12e6d8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x12e6dc · F_RoomSetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12e6dc push {r3, r4, r5, lr} */
/* @0x12e6e0 mov r1, #0 */
/* @0x12e6e4 ldr r4, [sp, #0x10] */
/* @0x12e6e8 mov r0, r4 */
/* @0x12e6ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e6f0 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e6f4 subs r5, r0, #0 */
/* @0x12e6f8 popeq {r3, r4, r5, pc} */
/* @0x12e6fc mov r0, r4 */
/* @0x12e700 mov r1, #1 */
/* @0x12e704 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e708 str r0, [r5, #0x10] */
/* @0x12e70c pop {r3, r4, r5, pc} */
