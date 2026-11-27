/* libyoyo.so 覆盖卡组 0051
 * 函数 0x11eb0c..0x12057c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x11eb0c · F_DrawSurfacePartExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=296 · insn=74 */
/* @0x11eb0c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11eb10 sub sp, sp, #52 */
/* @0x11eb14 mov r1, #0 */
/* @0x11eb18 ldr r4, [sp, #0x58] */
/* @0x11eb1c mov r0, r4 */
/* @0x11eb20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11eb24 mov r1, #1 */
/* @0x11eb28 mov r5, r0 */
/* @0x11eb2c mov r0, r4 */
/* @0x11eb30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eb34 mov r1, #2 */
/* @0x11eb38 mov r8, r0 */
/* @0x11eb3c mov r0, r4 */
/* @0x11eb40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eb44 mov r1, #3 */
/* @0x11eb48 mov r7, r0 */
/* @0x11eb4c mov r0, r4 */
/* @0x11eb50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eb54 mov r1, #4 */
/* @0x11eb58 mov r6, r0 */
/* @0x11eb5c mov r0, r4 */
/* @0x11eb60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eb64 mov r1, #5 */
/* @0x11eb68 mov r12, r0 */
/* @0x11eb6c mov r0, r4 */
/* @0x11eb70 str r12, [sp, #0x24] */
/* @0x11eb74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eb78 mov r1, #6 */
/* @0x11eb7c mov r2, r0 */
/* @0x11eb80 mov r0, r4 */
/* @0x11eb84 str r2, [sp, #0x28] */
/* @0x11eb88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eb8c mov r1, #7 */
/* @0x11eb90 mov r3, r0 */
/* @0x11eb94 mov r0, r4 */
/* @0x11eb98 str r3, [sp, #0x2c] */
/* @0x11eb9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eba0 mov r1, #8 */
/* @0x11eba4 mov r11, r0 */
/* @0x11eba8 mov r0, r4 */
/* @0x11ebac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ebb0 mov r1, #9 */
/* @0x11ebb4 mov r10, r0 */
/* @0x11ebb8 mov r0, r4 */
/* @0x11ebbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ebc0 mov r1, #10 */
/* @0x11ebc4 mov r9, r0 */
/* @0x11ebc8 mov r0, r4 */
/* @0x11ebcc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ebd0 ldr r2, [sp, #0x28] */
/* @0x11ebd4 ldr r3, [sp, #0x2c] */
/* @0x11ebd8 mov r1, r8 */
/* @0x11ebdc ldr r12, [sp, #0x24] */
/* @0x11ebe0 str r2, [sp, #0x4] */
/* @0x11ebe4 mov r2, r7 */
/* @0x11ebe8 str r3, [sp, #0x8] */
/* @0x11ebec mov r3, r6 */
/* @0x11ebf0 str r12, [sp] */
/* @0x11ebf4 str r11, [sp, #0xc] */
/* @0x11ebf8 str r10, [sp, #0x10] */
/* @0x11ebfc str r9, [sp, #0x14] */
/* @0x11ec00 str r0, [sp, #0x18] */
/* @0x11ec04 mov r0, r5 */
/* @0x11ec08 bl 0x171ee0 <_Z27YYGML_draw_surface_part_extiffffffffif> */
/* @0x11ec0c subs r1, r0, #0 */
/* @0x11ec10 beq 0x11ec1c <_Z20F_DrawSurfacePartExtR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x11ec14 add sp, sp, #52 */
/* @0x11ec18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11ec1c ldr r0, [pc, #0xc] */
/* @0x11ec20 add r0, pc, r0 */
/* @0x11ec24 add sp, sp, #52 */
/* @0x11ec28 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11ec2c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11ec30 eoreq r11, r1, r8, asr #12 */

/* ── FUNC 0x11ec34 · F_DrawSurfaceGeneral(RValue&, CInstance*, CInstance*, int, RValue*) · size=384 · insn=96 */
/* @0x11ec34 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11ec38 sub sp, sp, #84 */
/* @0x11ec3c mov r1, #0 */
/* @0x11ec40 ldr r4, [sp, #0x78] */
/* @0x11ec44 mov r0, r4 */
/* @0x11ec48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ec4c mov r5, r0 */
/* @0x11ec50 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11ec54 subs r1, r0, #0 */
/* @0x11ec58 beq 0x11ed9c <_Z20F_DrawSurfaceGeneralR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x11ec5c mov r0, r4 */
/* @0x11ec60 mov r1, #1 */
/* @0x11ec64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ec68 mov r1, #2 */
/* @0x11ec6c str r0, [sp, #0x40] */
/* @0x11ec70 mov r0, r4 */
/* @0x11ec74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ec78 mov r1, #3 */
/* @0x11ec7c mov r2, r0 */
/* @0x11ec80 mov r0, r4 */
/* @0x11ec84 str r2, [sp, #0x34] */
/* @0x11ec88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ec8c mov r1, #4 */
/* @0x11ec90 mov r3, r0 */
/* @0x11ec94 mov r0, r4 */
/* @0x11ec98 str r3, [sp, #0x38] */
/* @0x11ec9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eca0 mov r1, #5 */
/* @0x11eca4 mov r12, r0 */
/* @0x11eca8 mov r0, r4 */
/* @0x11ecac str r12, [sp, #0x3c] */
/* @0x11ecb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ecb4 mov r1, #6 */
/* @0x11ecb8 str r0, [sp, #0x44] */
/* @0x11ecbc mov r0, r4 */
/* @0x11ecc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ecc4 mov r1, #7 */
/* @0x11ecc8 str r0, [sp, #0x48] */
/* @0x11eccc mov r0, r4 */
/* @0x11ecd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ecd4 mov r1, #8 */
/* @0x11ecd8 mov r11, r0 */
/* @0x11ecdc mov r0, r4 */
/* @0x11ece0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ece4 mov r1, #9 */
/* @0x11ece8 mov r10, r0 */
/* @0x11ecec mov r0, r4 */
/* @0x11ecf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ecf4 mov r1, #10 */
/* @0x11ecf8 mov r9, r0 */
/* @0x11ecfc mov r0, r4 */
/* @0x11ed00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ed04 mov r1, #11 */
/* @0x11ed08 str r0, [sp, #0x4c] */
/* @0x11ed0c mov r0, r4 */
/* @0x11ed10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ed14 mov r1, #12 */
/* @0x11ed18 mov r8, r0 */
/* @0x11ed1c mov r0, r4 */
/* @0x11ed20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ed24 mov r1, #13 */
/* @0x11ed28 mov r7, r0 */
/* @0x11ed2c mov r0, r4 */
/* @0x11ed30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ed34 mov r1, #14 */
/* @0x11ed38 mov r6, r0 */
/* @0x11ed3c mov r0, r4 */
/* @0x11ed40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ed44 ldr r1, [sp, #0x44] */
/* @0x11ed48 ldr r12, [sp, #0x3c] */
/* @0x11ed4c str r11, [sp, #0xc] */
/* @0x11ed50 str r1, [sp, #0x4] */
/* @0x11ed54 ldr r1, [sp, #0x48] */
/* @0x11ed58 str r12, [sp] */
/* @0x11ed5c str r10, [sp, #0x10] */
/* @0x11ed60 str r1, [sp, #0x8] */
/* @0x11ed64 ldr r1, [sp, #0x4c] */
/* @0x11ed68 str r9, [sp, #0x14] */
/* @0x11ed6c str r8, [sp, #0x1c] */
/* @0x11ed70 str r1, [sp, #0x18] */
/* @0x11ed74 str r7, [sp, #0x20] */
/* @0x11ed78 str r6, [sp, #0x24] */
/* @0x11ed7c ldr r1, [sp, #0x40] */
/* @0x11ed80 ldr r2, [sp, #0x34] */
/* @0x11ed84 ldr r3, [sp, #0x38] */
/* @0x11ed88 str r0, [sp, #0x28] */
/* @0x11ed8c mov r0, r5 */
/* @0x11ed90 bl 0x171fa4 <_Z22GR_Surface_DrawGeneralifffffffffjjjjf> */
/* @0x11ed94 add sp, sp, #84 */
/* @0x11ed98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11ed9c ldr r0, [pc, #0xc] */
/* @0x11eda0 add r0, pc, r0 */
/* @0x11eda4 add sp, sp, #84 */
/* @0x11eda8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11edac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11edb0 eoreq r11, r1, r8, asr #9 */

/* ── FUNC 0x11edb4 · F_DrawSurfaceStretched(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x11edb4 push {r4, r5, r6, r7, r8, lr} */
/* @0x11edb8 sub sp, sp, #16 */
/* @0x11edbc mov r1, #0 */
/* @0x11edc0 ldr r4, [sp, #0x28] */
/* @0x11edc4 mov r0, r4 */
/* @0x11edc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11edcc mov r5, r0 */
/* @0x11edd0 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11edd4 subs r1, r0, #0 */
/* @0x11edd8 beq 0x11ee4c <_Z22F_DrawSurfaceStretchedR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x11eddc mov r0, r4 */
/* @0x11ede0 mov r1, #1 */
/* @0x11ede4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ede8 mov r1, #2 */
/* @0x11edec mov r8, r0 */
/* @0x11edf0 mov r0, r4 */
/* @0x11edf4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11edf8 mov r1, #3 */
/* @0x11edfc mov r7, r0 */
/* @0x11ee00 mov r0, r4 */
/* @0x11ee04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ee08 mov r1, #4 */
/* @0x11ee0c mov r6, r0 */
/* @0x11ee10 mov r0, r4 */
/* @0x11ee14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ee18 mov r4, r0 */
/* @0x11ee1c bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11ee20 mvn r12, #-16777216 */
/* @0x11ee24 str r4, [sp] */
/* @0x11ee28 mov r1, r8 */
/* @0x11ee2c mov r2, r7 */
/* @0x11ee30 mov r3, r6 */
/* @0x11ee34 str r12, [sp, #0x4] */
/* @0x11ee38 str r0, [sp, #0x8] */
/* @0x11ee3c mov r0, r5 */
/* @0x11ee40 bl 0x171e2c <_Z24GR_Surface_DrawStretchediffffjf> */
/* @0x11ee44 add sp, sp, #16 */
/* @0x11ee48 pop {r4, r5, r6, r7, r8, pc} */
/* @0x11ee4c ldr r0, [pc, #0xc] */
/* @0x11ee50 add r0, pc, r0 */
/* @0x11ee54 add sp, sp, #16 */
/* @0x11ee58 pop {r4, r5, r6, r7, r8, lr} */
/* @0x11ee5c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11ee60 eoreq r11, r1, r8, lsl r4 */

/* ── FUNC 0x11ee64 · F_DrawSurfaceStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x11ee64 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11ee68 sub sp, sp, #16 */
/* @0x11ee6c mov r1, #0 */
/* @0x11ee70 ldr r4, [sp, #0x30] */
/* @0x11ee74 mov r0, r4 */
/* @0x11ee78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ee7c mov r5, r0 */
/* @0x11ee80 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11ee84 subs r1, r0, #0 */
/* @0x11ee88 beq 0x11ef10 <_Z25F_DrawSurfaceStretchedExtR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x11ee8c mov r0, r4 */
/* @0x11ee90 mov r1, #1 */
/* @0x11ee94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11ee98 mov r1, #2 */
/* @0x11ee9c mov r8, r0 */
/* @0x11eea0 mov r0, r4 */
/* @0x11eea4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eea8 mov r1, #3 */
/* @0x11eeac mov r7, r0 */
/* @0x11eeb0 mov r0, r4 */
/* @0x11eeb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eeb8 mov r1, #4 */
/* @0x11eebc mov r6, r0 */
/* @0x11eec0 mov r0, r4 */
/* @0x11eec4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eec8 mov r1, #5 */
/* @0x11eecc mov r10, r0 */
/* @0x11eed0 mov r0, r4 */
/* @0x11eed4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11eed8 mov r1, #6 */
/* @0x11eedc mov r9, r0 */
/* @0x11eee0 mov r0, r4 */
/* @0x11eee4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11eee8 str r10, [sp] */
/* @0x11eeec str r9, [sp, #0x4] */
/* @0x11eef0 mov r1, r8 */
/* @0x11eef4 mov r2, r7 */
/* @0x11eef8 mov r3, r6 */
/* @0x11eefc str r0, [sp, #0x8] */
/* @0x11ef00 mov r0, r5 */
/* @0x11ef04 bl 0x171e2c <_Z24GR_Surface_DrawStretchediffffjf> */
/* @0x11ef08 add sp, sp, #16 */
/* @0x11ef0c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11ef10 ldr r0, [pc, #0xc] */
/* @0x11ef14 add r0, pc, r0 */
/* @0x11ef18 add sp, sp, #16 */
/* @0x11ef1c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11ef20 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11ef24 eoreq r11, r1, r4, asr r3 */

/* ── FUNC 0x11ef28 · F_SurfaceSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x11ef28 push {r4, r5, r6, r7, lr} */
/* @0x11ef2c sub sp, sp, #12 */
/* @0x11ef30 mov r1, #0 */
/* @0x11ef34 ldr r5, [sp, #0x20] */
/* @0x11ef38 mov r0, r5 */
/* @0x11ef3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ef40 mov r1, #1 */
/* @0x11ef44 mov r4, r0 */
/* @0x11ef48 mov r0, r5 */
/* @0x11ef4c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11ef50 mov r7, r0 */
/* @0x11ef54 mov r0, r4 */
/* @0x11ef58 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11ef5c subs r1, r0, #0 */
/* @0x11ef60 beq 0x11efc8 <_Z13F_SurfaceSaveR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x11ef64 mov r0, r4 */
/* @0x11ef68 bl 0x1714d4 <_Z20GR_Surface_Get_Widthi> */
/* @0x11ef6c mov r6, r0 */
/* @0x11ef70 mov r0, r4 */
/* @0x11ef74 bl 0x171518 <_Z21GR_Surface_Get_Heighti> */
/* @0x11ef78 mov r5, r0 */
/* @0x11ef7c mov r0, r4 */
/* @0x11ef80 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x11ef84 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x11ef88 mov r1, #0 */
/* @0x11ef8c str r5, [sp] */
/* @0x11ef90 mov r3, r6 */
/* @0x11ef94 mov r2, r1 */
/* @0x11ef98 bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii> */
/* @0x11ef9c subs r4, r0, #0 */
/* @0x11efa0 beq 0x11efdc <_Z13F_SurfaceSaveR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x11efa4 mov r0, r7 */
/* @0x11efa8 mov r2, r6 */
/* @0x11efac mov r3, r5 */
/* @0x11efb0 mov r1, r4 */
/* @0x11efb4 bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x11efb8 mov r0, r4 */
/* @0x11efbc add sp, sp, #12 */
/* @0x11efc0 pop {r4, r5, r6, r7, lr} */
/* @0x11efc4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x11efc8 ldr r0, [pc, #0x14] */
/* @0x11efcc add r0, pc, r0 */
/* @0x11efd0 add sp, sp, #12 */
/* @0x11efd4 pop {r4, r5, r6, r7, lr} */
/* @0x11efd8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11efdc add sp, sp, #12 */
/* @0x11efe0 pop {r4, r5, r6, r7, pc} */
/* @0x11efe4 mlaeq r1, r12, r2, r11 */

/* ── FUNC 0x11efe8 · F_SurfaceSavePart(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0x11efe8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x11efec sub sp, sp, #12 */
/* @0x11eff0 mov r1, #0 */
/* @0x11eff4 ldr r4, [sp, #0x28] */
/* @0x11eff8 mov r0, r4 */
/* @0x11effc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f000 mov r1, #1 */
/* @0x11f004 mov r5, r0 */
/* @0x11f008 mov r0, r4 */
/* @0x11f00c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11f010 mov r1, #2 */
/* @0x11f014 mov r9, r0 */
/* @0x11f018 mov r0, r4 */
/* @0x11f01c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f020 mov r1, #3 */
/* @0x11f024 mov r8, r0 */
/* @0x11f028 mov r0, r4 */
/* @0x11f02c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f030 mov r1, #4 */
/* @0x11f034 mov r7, r0 */
/* @0x11f038 mov r0, r4 */
/* @0x11f03c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f040 mov r1, #5 */
/* @0x11f044 mov r6, r0 */
/* @0x11f048 mov r0, r4 */
/* @0x11f04c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f050 mov r4, r0 */
/* @0x11f054 mov r0, r5 */
/* @0x11f058 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f05c subs r1, r0, #0 */
/* @0x11f060 beq 0x11f0b0 <_Z17F_SurfaceSavePartR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x11f064 mov r0, r5 */
/* @0x11f068 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x11f06c bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x11f070 str r4, [sp] */
/* @0x11f074 mov r1, r8 */
/* @0x11f078 mov r2, r7 */
/* @0x11f07c mov r3, r6 */
/* @0x11f080 bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii> */
/* @0x11f084 subs r5, r0, #0 */
/* @0x11f088 beq 0x11f0c4 <_Z17F_SurfaceSavePartR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x11f08c mov r0, r9 */
/* @0x11f090 mov r2, r6 */
/* @0x11f094 mov r3, r4 */
/* @0x11f098 mov r1, r5 */
/* @0x11f09c bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x11f0a0 mov r0, r5 */
/* @0x11f0a4 add sp, sp, #12 */
/* @0x11f0a8 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x11f0ac b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x11f0b0 ldr r0, [pc, #0x14] */
/* @0x11f0b4 add r0, pc, r0 */
/* @0x11f0b8 add sp, sp, #12 */
/* @0x11f0bc pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x11f0c0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11f0c4 add sp, sp, #12 */
/* @0x11f0c8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x11f0cc .word 0x0021b1b4 */

/* ── FUNC 0x11f0d0 · F_SurfaceGetPixelExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x11f0d0 push {r4, r5, r6, r7, lr} */
/* @0x11f0d4 sub sp, sp, #12 */
/* @0x11f0d8 mov r1, #0 */
/* @0x11f0dc mov r4, r0 */
/* @0x11f0e0 ldr r5, [sp, #0x20] */
/* @0x11f0e4 mov r0, r5 */
/* @0x11f0e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f0ec mov r6, r0 */
/* @0x11f0f0 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f0f4 subs r1, r0, #0 */
/* @0x11f0f8 beq 0x11f190 <_Z20F_SurfaceGetPixelExtR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x11f0fc mov r3, #0 */
/* @0x11f100 mov r0, r6 */
/* @0x11f104 str r3, [r4, #0xc] */
/* @0x11f108 str r3, [r4] */
/* @0x11f10c str r3, [r4, #0x4] */
/* @0x11f110 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f114 cmp r0, #0 */
/* @0x11f118 bne 0x11f124 <_Z20F_SurfaceGetPixelExtR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x11f11c add sp, sp, #12 */
/* @0x11f120 pop {r4, r5, r6, r7, pc} */
/* @0x11f124 mov r0, r6 */
/* @0x11f128 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x11f12c bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x11f130 mov r1, #1 */
/* @0x11f134 mov r6, r0 */
/* @0x11f138 mov r0, r5 */
/* @0x11f13c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f140 mov r1, #2 */
/* @0x11f144 mov r7, r0 */
/* @0x11f148 mov r0, r5 */
/* @0x11f14c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f150 mov r3, #1 */
/* @0x11f154 mov r1, r7 */
/* @0x11f158 str r3, [sp] */
/* @0x11f15c mov r2, r0 */
/* @0x11f160 mov r0, r6 */
/* @0x11f164 bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii> */
/* @0x11f168 subs r3, r0, #0 */
/* @0x11f16c beq 0x11f11c <_Z20F_SurfaceGetPixelExtR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x11f170 ldr r2, [r3] */
/* @0x11f174 vmov s15, r2 */
/* @0x11f178 vcvt.f64.u32 d7, s15 */
/* @0x11f17c vmov r2, r3, d7 */
/* @0x11f180 stm r4, {r2, r3} */
/* @0x11f184 add sp, sp, #12 */
/* @0x11f188 pop {r4, r5, r6, r7, lr} */
/* @0x11f18c b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x11f190 ldr r0, [pc, #0xc] */
/* @0x11f194 add r0, pc, r0 */
/* @0x11f198 add sp, sp, #12 */
/* @0x11f19c pop {r4, r5, r6, r7, lr} */
/* @0x11f1a0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11f1a4 .word 0x0021b0d4 */

/* ── FUNC 0x11f1a8 · F_SurfaceGetPixel(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x11f1a8 push {r4, lr} */
/* @0x11f1ac sub sp, sp, #8 */
/* @0x11f1b0 mov r4, r0 */
/* @0x11f1b4 ldr r12, [sp, #0x10] */
/* @0x11f1b8 str r12, [sp] */
/* @0x11f1bc bl 0x11f0d0 <_Z20F_SurfaceGetPixelExtR6RValueP9CInstanceS2_iPS_> */
/* @0x11f1c0 ldr r2, [r4] */
/* @0x11f1c4 ldr r3, [r4, #0x4] */
/* @0x11f1c8 mov r1, #0 */
/* @0x11f1cc str r1, [r4, #0xc] */
/* @0x11f1d0 vmov d7, r2, r3 */
/* @0x11f1d4 vcvt.u32.f64 s15, d7 */
/* @0x11f1d8 vmov r2, s15 */
/* @0x11f1dc bic r2, r2, #-16777216 */
/* @0x11f1e0 vmov s15, r2 */
/* @0x11f1e4 vcvt.f64.s32 d7, s15 */
/* @0x11f1e8 vmov r2, r3, d7 */
/* @0x11f1ec stm r4, {r2, r3} */
/* @0x11f1f0 add sp, sp, #8 */
/* @0x11f1f4 pop {r4, pc} */

/* ── FUNC 0x11f1f8 · F_SurfaceCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=316 · insn=79 */
/* @0x11f1f8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11f1fc sub sp, sp, #16 */
/* @0x11f200 mov r1, #0 */
/* @0x11f204 ldr r4, [sp, #0x30] */
/* @0x11f208 mov r0, r4 */
/* @0x11f20c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f210 mov r6, r0 */
/* @0x11f214 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f218 cmp r0, #0 */
/* @0x11f21c beq 0x11f314 <_Z13F_SurfaceCopyR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x11f220 mov r1, #3 */
/* @0x11f224 mov r0, r4 */
/* @0x11f228 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f22c mov r7, r0 */
/* @0x11f230 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f234 cmp r0, #0 */
/* @0x11f238 beq 0x11f314 <_Z13F_SurfaceCopyR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x11f23c ldr r5, [pc, #0xe8] */
/* @0x11f240 mov r1, r6 */
/* @0x11f244 mov r0, #0 */
/* @0x11f248 bl 0x171574 <_Z28YYGML_surface_set_target_extii> */
/* @0x11f24c ldr r5, [pc, r5] */
/* @0x11f250 mov r0, r5 */
/* @0x11f254 bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv> */
/* @0x11f258 mov r0, r4 */
/* @0x11f25c mov r1, #0 */
/* @0x11f260 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f264 mov r1, #12 */
/* @0x11f268 mov r2, r0 */
/* @0x11f26c mov r0, r5 */
/* @0x11f270 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x11f274 mov r2, #0 */
/* @0x11f278 mov r1, #1 */
/* @0x11f27c mov r0, r5 */
/* @0x11f280 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x11f284 mov r0, r7 */
/* @0x11f288 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x11f28c bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x11f290 mov r8, r0 */
/* @0x11f294 mov r0, r6 */
/* @0x11f298 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x11f29c bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x11f2a0 mov r1, #1 */
/* @0x11f2a4 mov r6, r0 */
/* @0x11f2a8 mov r0, r4 */
/* @0x11f2ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f2b0 mov r1, #2 */
/* @0x11f2b4 mov r9, r0 */
/* @0x11f2b8 mov r0, r4 */
/* @0x11f2bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f2c0 mov r4, r0 */
/* @0x11f2c4 mov r0, r7 */
/* @0x11f2c8 bl 0x1714d4 <_Z20GR_Surface_Get_Widthi> */
/* @0x11f2cc mov r10, r0 */
/* @0x11f2d0 mov r0, r7 */
/* @0x11f2d4 bl 0x171518 <_Z21GR_Surface_Get_Heighti> */
/* @0x11f2d8 mov r12, #0 */
/* @0x11f2dc mov r1, r9 */
/* @0x11f2e0 mov r2, r4 */
/* @0x11f2e4 mov r3, r8 */
/* @0x11f2e8 str r12, [sp] */
/* @0x11f2ec str r12, [sp, #0x4] */
/* @0x11f2f0 str r10, [sp, #0x8] */
/* @0x11f2f4 str r0, [sp, #0xc] */
/* @0x11f2f8 mov r0, r6 */
/* @0x11f2fc bl 0x17e850 <_ZN8Graphics11SurfaceCopyEPviiS0_iiii> */
/* @0x11f300 mov r0, r5 */
/* @0x11f304 bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv> */
/* @0x11f308 add sp, sp, #16 */
/* @0x11f30c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11f310 b 0x171808 <_Z26YYGML_surface_reset_targetv> */
/* @0x11f314 ldr r0, [pc, #0x14] */
/* @0x11f318 mov r1, #0 */
/* @0x11f31c add r0, pc, r0 */
/* @0x11f320 add sp, sp, #16 */
/* @0x11f324 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11f328 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11f32c eoreq lr, r12, r12, lsr #21 */
/* @0x11f330 eoreq r10, r1, r12, asr #30 */

/* ── FUNC 0x11f334 · F_SurfaceCopyPart(RValue&, CInstance*, CInstance*, int, RValue*) · size=356 · insn=89 */
/* @0x11f334 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11f338 sub sp, sp, #28 */
/* @0x11f33c mov r1, #0 */
/* @0x11f340 ldr r4, [sp, #0x40] */
/* @0x11f344 mov r0, r4 */
/* @0x11f348 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f34c mov r6, r0 */
/* @0x11f350 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f354 cmp r0, #0 */
/* @0x11f358 beq 0x11f478 <_Z17F_SurfaceCopyPartR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x11f35c mov r1, #3 */
/* @0x11f360 mov r0, r4 */
/* @0x11f364 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f368 mov r7, r0 */
/* @0x11f36c bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f370 cmp r0, #0 */
/* @0x11f374 beq 0x11f478 <_Z17F_SurfaceCopyPartR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x11f378 ldr r5, [pc, #0x110] */
/* @0x11f37c mov r1, r6 */
/* @0x11f380 mov r0, #0 */
/* @0x11f384 bl 0x171574 <_Z28YYGML_surface_set_target_extii> */
/* @0x11f388 ldr r5, [pc, r5] */
/* @0x11f38c mov r0, r5 */
/* @0x11f390 bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv> */
/* @0x11f394 mov r0, r4 */
/* @0x11f398 mov r1, #0 */
/* @0x11f39c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f3a0 mov r1, #12 */
/* @0x11f3a4 mov r2, r0 */
/* @0x11f3a8 mov r0, r5 */
/* @0x11f3ac bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x11f3b0 mov r2, #0 */
/* @0x11f3b4 mov r1, #1 */
/* @0x11f3b8 mov r0, r5 */
/* @0x11f3bc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x11f3c0 mov r0, r7 */
/* @0x11f3c4 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x11f3c8 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x11f3cc mov r7, r0 */
/* @0x11f3d0 mov r0, r6 */
/* @0x11f3d4 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x11f3d8 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x11f3dc mov r1, #1 */
/* @0x11f3e0 mov r6, r0 */
/* @0x11f3e4 mov r0, r4 */
/* @0x11f3e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f3ec mov r1, #2 */
/* @0x11f3f0 mov r10, r0 */
/* @0x11f3f4 mov r0, r4 */
/* @0x11f3f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f3fc mov r1, #4 */
/* @0x11f400 mov r8, r0 */
/* @0x11f404 mov r0, r4 */
/* @0x11f408 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f40c mov r1, #5 */
/* @0x11f410 mov r3, r0 */
/* @0x11f414 mov r0, r4 */
/* @0x11f418 str r3, [sp, #0x14] */
/* @0x11f41c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f420 mov r1, #6 */
/* @0x11f424 mov r11, r0 */
/* @0x11f428 mov r0, r4 */
/* @0x11f42c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f430 mov r1, #7 */
/* @0x11f434 mov r9, r0 */
/* @0x11f438 mov r0, r4 */
/* @0x11f43c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f440 ldr r3, [sp, #0x14] */
/* @0x11f444 mov r1, r10 */
/* @0x11f448 mov r2, r8 */
/* @0x11f44c str r9, [sp, #0x8] */
/* @0x11f450 stm sp, {r3, r11} */
/* @0x11f454 mov r3, r7 */
/* @0x11f458 str r0, [sp, #0xc] */
/* @0x11f45c mov r0, r6 */
/* @0x11f460 bl 0x17e850 <_ZN8Graphics11SurfaceCopyEPviiS0_iiii> */
/* @0x11f464 mov r0, r5 */
/* @0x11f468 bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv> */
/* @0x11f46c add sp, sp, #28 */
/* @0x11f470 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11f474 b 0x171808 <_Z26YYGML_surface_reset_targetv> */
/* @0x11f478 ldr r0, [pc, #0x14] */
/* @0x11f47c mov r1, #0 */
/* @0x11f480 add r0, pc, r0 */
/* @0x11f484 add sp, sp, #28 */
/* @0x11f488 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11f48c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11f490 eoreq lr, r12, r0, ror r9 */
/* @0x11f494 eoreq r10, r1, r8, ror #27 */

/* ── FUNC 0x11f498 · F_DrawBackgroundTiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=424 · insn=106 */
/* @0x11f498 push {r4, r5, r6, r7, lr} */
/* @0x11f49c vpush {d8} */
/* @0x11f4a0 sub sp, sp, #44 */
/* @0x11f4a4 ldr r4, [pc, #0x184] */
/* @0x11f4a8 ldr r3, [pc, #0x184] */
/* @0x11f4ac add r4, pc, r4 */
/* @0x11f4b0 ldr r5, [sp, #0x48] */
/* @0x11f4b4 ldr r3, [r4, r3] */
/* @0x11f4b8 mov r0, r5 */
/* @0x11f4bc ldrb r1, [r3] */
/* @0x11f4c0 cmp r1, #0 */
/* @0x11f4c4 beq 0x11f574 <_Z21F_DrawBackgroundTiledR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x11f4c8 mov r1, #0 */
/* @0x11f4cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f4d0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11f4d4 subs r6, r0, #0 */
/* @0x11f4d8 beq 0x11f614 <_Z21F_DrawBackgroundTiledR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x11f4dc mov r0, r5 */
/* @0x11f4e0 mov r1, #1 */
/* @0x11f4e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f4e8 mov r1, #2 */
/* @0x11f4ec mov r7, r0 */
/* @0x11f4f0 mov r0, r5 */
/* @0x11f4f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f4f8 ldr r3, [pc, #0x138] */
/* @0x11f4fc ldr r3, [r4, r3] */
/* @0x11f500 ldr r1, [r3] */
/* @0x11f504 vldr s17, [r1, #16] */
/* @0x11f508 vldr s16, [r1, #20] */
/* @0x11f50c vcvt.f32.s32 s17, s17 */
/* @0x11f510 vcvt.f32.s32 s16, s16 */
/* @0x11f514 mov r5, r0 */
/* @0x11f518 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11f51c mov r1, #1 */
/* @0x11f520 mov r12, #0 */
/* @0x11f524 str r1, [sp, #0x8] */
/* @0x11f528 vstr s17, [sp, #24] */
/* @0x11f52c str r1, [sp, #0xc] */
/* @0x11f530 mov r2, r7 */
/* @0x11f534 str r12, [sp, #0x10] */
/* @0x11f538 mov r3, r5 */
/* @0x11f53c str r12, [sp, #0x14] */
/* @0x11f540 mov r1, #0 */
/* @0x11f544 mvn r12, #-16777216 */
/* @0x11f548 vstr s16, [sp, #28] */
/* @0x11f54c str r12, [sp, #0x20] */
/* @0x11f550 mov r12, #1065353216 */
/* @0x11f554 str r12, [sp] */
/* @0x11f558 str r12, [sp, #0x4] */
/* @0x11f55c str r0, [sp, #0x24] */
/* @0x11f560 mov r0, r6 */
/* @0x11f564 bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf> */
/* @0x11f568 add sp, sp, #44 */
/* @0x11f56c vpop {d8} */
/* @0x11f570 pop {r4, r5, r6, r7, pc} */
/* @0x11f574 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f578 bl 0xc3794 <_Z15Background_Datai> */
/* @0x11f57c subs r6, r0, #0 */
/* @0x11f580 beq 0x11f614 <_Z21F_DrawBackgroundTiledR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x11f584 mov r0, r5 */
/* @0x11f588 mov r1, #1 */
/* @0x11f58c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f590 mov r1, #2 */
/* @0x11f594 mov r7, r0 */
/* @0x11f598 mov r0, r5 */
/* @0x11f59c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f5a0 ldr r3, [pc, #0x90] */
/* @0x11f5a4 ldr r3, [r4, r3] */
/* @0x11f5a8 ldr r3, [r3] */
/* @0x11f5ac vldr s17, [r3, #16] */
/* @0x11f5b0 vldr s16, [r3, #20] */
/* @0x11f5b4 vcvt.f32.s32 s17, s17 */
/* @0x11f5b8 vcvt.f32.s32 s16, s16 */
/* @0x11f5bc mov r5, r0 */
/* @0x11f5c0 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11f5c4 mov r12, #0 */
/* @0x11f5c8 mov r3, #1 */
/* @0x11f5cc vstr s17, [sp, #20] */
/* @0x11f5d0 str r3, [sp, #0x4] */
/* @0x11f5d4 str r3, [sp, #0x8] */
/* @0x11f5d8 mov r1, r7 */
/* @0x11f5dc mov r2, r5 */
/* @0x11f5e0 str r12, [sp, #0xc] */
/* @0x11f5e4 str r12, [sp, #0x10] */
/* @0x11f5e8 mvn r3, #-16777216 */
/* @0x11f5ec vstr s16, [sp, #24] */
/* @0x11f5f0 str r3, [sp, #0x1c] */
/* @0x11f5f4 mov r3, #1065353216 */
/* @0x11f5f8 str r3, [sp] */
/* @0x11f5fc str r0, [sp, #0x20] */
/* @0x11f600 mov r0, r6 */
/* @0x11f604 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf> */
/* @0x11f608 add sp, sp, #44 */
/* @0x11f60c vpop {d8} */
/* @0x11f610 pop {r4, r5, r6, r7, pc} */
/* @0x11f614 ldr r0, [pc, #0x20] */
/* @0x11f618 mov r1, #0 */
/* @0x11f61c add r0, pc, r0 */
/* @0x11f620 add sp, sp, #44 */
/* @0x11f624 vpop {d8} */
/* @0x11f628 pop {r4, r5, r6, r7, lr} */
/* @0x11f62c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11f630 eoreq r2, sp, r4, lsr #15 */
/* @0x11f634 .word 0xffffbcd4 */
/* @0x11f638 .word 0xffffbcd8 */
/* @0x11f63c .word 0x0021abb8 */

/* ── FUNC 0x11f640 · F_DrawBackgroundTiledExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=524 · insn=131 */
/* @0x11f640 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11f644 vpush {d8} */
/* @0x11f648 sub sp, sp, #40 */
/* @0x11f64c ldr r5, [pc, #0x1e8] */
/* @0x11f650 ldr r3, [pc, #0x1e8] */
/* @0x11f654 add r5, pc, r5 */
/* @0x11f658 ldr r4, [sp, #0x50] */
/* @0x11f65c ldr r3, [r5, r3] */
/* @0x11f660 mov r0, r4 */
/* @0x11f664 ldrb r1, [r3] */
/* @0x11f668 cmp r1, #0 */
/* @0x11f66c beq 0x11f74c <_Z24F_DrawBackgroundTiledExtR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x11f670 mov r1, #0 */
/* @0x11f674 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f678 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11f67c subs r6, r0, #0 */
/* @0x11f680 beq 0x11f820 <_Z24F_DrawBackgroundTiledExtR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x11f684 mov r0, r4 */
/* @0x11f688 mov r1, #1 */
/* @0x11f68c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f690 mov r1, #2 */
/* @0x11f694 mov r8, r0 */
/* @0x11f698 mov r0, r4 */
/* @0x11f69c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f6a0 mov r1, #3 */
/* @0x11f6a4 mov r7, r0 */
/* @0x11f6a8 mov r0, r4 */
/* @0x11f6ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f6b0 mov r1, #4 */
/* @0x11f6b4 mov r10, r0 */
/* @0x11f6b8 mov r0, r4 */
/* @0x11f6bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f6c0 ldr r3, [pc, #0x17c] */
/* @0x11f6c4 mov r1, #5 */
/* @0x11f6c8 ldr r3, [r5, r3] */
/* @0x11f6cc ldr r12, [r3] */
/* @0x11f6d0 vldr s17, [r12, #16] */
/* @0x11f6d4 vldr s16, [r12, #20] */
/* @0x11f6d8 vcvt.f32.s32 s17, s17 */
/* @0x11f6dc vcvt.f32.s32 s16, s16 */
/* @0x11f6e0 mov r9, r0 */
/* @0x11f6e4 mov r0, r4 */
/* @0x11f6e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f6ec mov r1, #6 */
/* @0x11f6f0 mov r5, r0 */
/* @0x11f6f4 mov r0, r4 */
/* @0x11f6f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f6fc mov r12, #0 */
/* @0x11f700 mov r1, #1 */
/* @0x11f704 str r10, [sp] */
/* @0x11f708 str r1, [sp, #0x8] */
/* @0x11f70c vstr s17, [sp, #24] */
/* @0x11f710 str r1, [sp, #0xc] */
/* @0x11f714 mov r2, r8 */
/* @0x11f718 str r9, [sp, #0x4] */
/* @0x11f71c vstr s16, [sp, #28] */
/* @0x11f720 str r5, [sp, #0x20] */
/* @0x11f724 mov r3, r7 */
/* @0x11f728 str r12, [sp, #0x10] */
/* @0x11f72c mov r1, #0 */
/* @0x11f730 str r12, [sp, #0x14] */
/* @0x11f734 str r0, [sp, #0x24] */
/* @0x11f738 mov r0, r6 */
/* @0x11f73c bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf> */
/* @0x11f740 add sp, sp, #40 */
/* @0x11f744 vpop {d8} */
/* @0x11f748 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11f74c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f750 bl 0xc3794 <_Z15Background_Datai> */
/* @0x11f754 subs r6, r0, #0 */
/* @0x11f758 beq 0x11f820 <_Z24F_DrawBackgroundTiledExtR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x11f75c mov r0, r4 */
/* @0x11f760 mov r1, #1 */
/* @0x11f764 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f768 mov r1, #2 */
/* @0x11f76c mov r9, r0 */
/* @0x11f770 mov r0, r4 */
/* @0x11f774 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f778 mov r1, #3 */
/* @0x11f77c mov r8, r0 */
/* @0x11f780 mov r0, r4 */
/* @0x11f784 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f788 mov r1, #4 */
/* @0x11f78c mov r7, r0 */
/* @0x11f790 mov r0, r4 */
/* @0x11f794 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f798 ldr r3, [pc, #0xa4] */
/* @0x11f79c mov r1, #5 */
/* @0x11f7a0 ldr r3, [r5, r3] */
/* @0x11f7a4 ldr r12, [r3] */
/* @0x11f7a8 vldr s17, [r12, #16] */
/* @0x11f7ac vldr s16, [r12, #20] */
/* @0x11f7b0 vcvt.f32.s32 s17, s17 */
/* @0x11f7b4 vcvt.f32.s32 s16, s16 */
/* @0x11f7b8 mov r10, r0 */
/* @0x11f7bc mov r0, r4 */
/* @0x11f7c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f7c4 mov r1, #6 */
/* @0x11f7c8 mov r5, r0 */
/* @0x11f7cc mov r0, r4 */
/* @0x11f7d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f7d4 mov r12, #1 */
/* @0x11f7d8 mov lr, #0 */
/* @0x11f7dc str r10, [sp] */
/* @0x11f7e0 vstr s17, [sp, #20] */
/* @0x11f7e4 str r5, [sp, #0x1c] */
/* @0x11f7e8 mov r1, r9 */
/* @0x11f7ec mov r2, r8 */
/* @0x11f7f0 vstr s16, [sp, #24] */
/* @0x11f7f4 mov r3, r7 */
/* @0x11f7f8 str r12, [sp, #0x4] */
/* @0x11f7fc str lr, [sp, #0xc] */
/* @0x11f800 str r12, [sp, #0x8] */
/* @0x11f804 str lr, [sp, #0x10] */
/* @0x11f808 str r0, [sp, #0x20] */
/* @0x11f80c mov r0, r6 */
/* @0x11f810 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf> */
/* @0x11f814 add sp, sp, #40 */
/* @0x11f818 vpop {d8} */
/* @0x11f81c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11f820 ldr r0, [pc, #0x20] */
/* @0x11f824 mov r1, #0 */
/* @0x11f828 add r0, pc, r0 */
/* @0x11f82c add sp, sp, #40 */
/* @0x11f830 vpop {d8} */
/* @0x11f834 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11f838 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11f83c .word 0x002d25fc */
/* @0x11f840 .word 0xffffbcd4 */
/* @0x11f844 .word 0xffffbcd8 */
/* @0x11f848 eoreq r10, r1, r12, lsr #19 */

/* ── FUNC 0x11f84c · F_DrawSurfaceTiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x11f84c push {r4, r5, r6, lr} */
/* @0x11f850 vpush {d8} */
/* @0x11f854 sub sp, sp, #40 */
/* @0x11f858 mov r1, #0 */
/* @0x11f85c ldr r4, [sp, #0x40] */
/* @0x11f860 mov r0, r4 */
/* @0x11f864 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f868 mov r5, r0 */
/* @0x11f86c bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f870 subs r1, r0, #0 */
/* @0x11f874 beq 0x11f908 <_Z18F_DrawSurfaceTiledR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x11f878 mov r0, r4 */
/* @0x11f87c mov r1, #1 */
/* @0x11f880 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f884 mov r1, #2 */
/* @0x11f888 mov r6, r0 */
/* @0x11f88c mov r0, r4 */
/* @0x11f890 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f894 ldr r3, [pc, #0x84] */
/* @0x11f898 ldr r3, [pc, r3] */
/* @0x11f89c ldr r3, [r3] */
/* @0x11f8a0 vldr s17, [r3, #16] */
/* @0x11f8a4 vldr s16, [r3, #20] */
/* @0x11f8a8 vcvt.f32.s32 s17, s17 */
/* @0x11f8ac vcvt.f32.s32 s16, s16 */
/* @0x11f8b0 mov r4, r0 */
/* @0x11f8b4 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x11f8b8 mov r12, #0 */
/* @0x11f8bc mov r3, #1 */
/* @0x11f8c0 vstr s17, [sp, #20] */
/* @0x11f8c4 str r3, [sp, #0x4] */
/* @0x11f8c8 str r3, [sp, #0x8] */
/* @0x11f8cc mov r1, r6 */
/* @0x11f8d0 mov r2, r4 */
/* @0x11f8d4 str r12, [sp, #0xc] */
/* @0x11f8d8 str r12, [sp, #0x10] */
/* @0x11f8dc mvn r3, #-16777216 */
/* @0x11f8e0 vstr s16, [sp, #24] */
/* @0x11f8e4 str r3, [sp, #0x1c] */
/* @0x11f8e8 mov r3, #1065353216 */
/* @0x11f8ec str r3, [sp] */
/* @0x11f8f0 str r0, [sp, #0x20] */
/* @0x11f8f4 mov r0, r5 */
/* @0x11f8f8 bl 0x172058 <_Z20GR_Surface_DrawTilediffffbbffffjf> */
/* @0x11f8fc add sp, sp, #40 */
/* @0x11f900 vpop {d8} */
/* @0x11f904 pop {r4, r5, r6, pc} */
/* @0x11f908 ldr r0, [pc, #0x14] */
/* @0x11f90c add r0, pc, r0 */
/* @0x11f910 add sp, sp, #40 */
/* @0x11f914 vpop {d8} */
/* @0x11f918 pop {r4, r5, r6, lr} */
/* @0x11f91c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11f920 mlaeq r12, r0, r0, lr */
/* @0x11f924 eoreq r10, r1, r12, asr r9 */

/* ── FUNC 0x11f928 · F_DrawSurfaceTiledExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x11f928 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11f92c vpush {d8} */
/* @0x11f930 sub sp, sp, #40 */
/* @0x11f934 mov r1, #0 */
/* @0x11f938 ldr r4, [sp, #0x50] */
/* @0x11f93c mov r0, r4 */
/* @0x11f940 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f944 mov r5, r0 */
/* @0x11f948 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x11f94c subs r1, r0, #0 */
/* @0x11f950 beq 0x11fa18 <_Z21F_DrawSurfaceTiledExtR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x11f954 mov r0, r4 */
/* @0x11f958 mov r1, #1 */
/* @0x11f95c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f960 mov r1, #2 */
/* @0x11f964 mov r8, r0 */
/* @0x11f968 mov r0, r4 */
/* @0x11f96c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f970 mov r1, #3 */
/* @0x11f974 mov r7, r0 */
/* @0x11f978 mov r0, r4 */
/* @0x11f97c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f980 mov r1, #4 */
/* @0x11f984 mov r6, r0 */
/* @0x11f988 mov r0, r4 */
/* @0x11f98c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f990 ldr r12, [pc, #0x98] */
/* @0x11f994 mov r1, #5 */
/* @0x11f998 ldr r12, [pc, r12] */
/* @0x11f99c ldr r12, [r12] */
/* @0x11f9a0 vldr s17, [r12, #16] */
/* @0x11f9a4 vldr s16, [r12, #20] */
/* @0x11f9a8 vcvt.f32.s32 s17, s17 */
/* @0x11f9ac vcvt.f32.s32 s16, s16 */
/* @0x11f9b0 mov r10, r0 */
/* @0x11f9b4 mov r0, r4 */
/* @0x11f9b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11f9bc mov r1, #6 */
/* @0x11f9c0 mov r9, r0 */
/* @0x11f9c4 mov r0, r4 */
/* @0x11f9c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11f9cc mov r12, #1 */
/* @0x11f9d0 mov lr, #0 */
/* @0x11f9d4 str r10, [sp] */
/* @0x11f9d8 vstr s17, [sp, #20] */
/* @0x11f9dc str r9, [sp, #0x1c] */
/* @0x11f9e0 mov r1, r8 */
/* @0x11f9e4 mov r2, r7 */
/* @0x11f9e8 vstr s16, [sp, #24] */
/* @0x11f9ec mov r3, r6 */
/* @0x11f9f0 str r12, [sp, #0x4] */
/* @0x11f9f4 str lr, [sp, #0xc] */
/* @0x11f9f8 str r12, [sp, #0x8] */
/* @0x11f9fc str lr, [sp, #0x10] */
/* @0x11fa00 str r0, [sp, #0x20] */
/* @0x11fa04 mov r0, r5 */
/* @0x11fa08 bl 0x172058 <_Z20GR_Surface_DrawTilediffffbbffffjf> */
/* @0x11fa0c add sp, sp, #40 */
/* @0x11fa10 vpop {d8} */
/* @0x11fa14 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x11fa18 ldr r0, [pc, #0x14] */
/* @0x11fa1c add r0, pc, r0 */
/* @0x11fa20 add sp, sp, #40 */
/* @0x11fa24 vpop {d8} */
/* @0x11fa28 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x11fa2c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fa30 mlaeq r12, r0, pc, sp */
/* @0x11fa34 eoreq r10, r1, r12, asr #16 */

/* ── FUNC 0x11fa38 · F_SpriteGetTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x11fa38 push {r3, r4, r5, r6, r7, lr} */
/* @0x11fa3c mov r4, r0 */
/* @0x11fa40 ldr r5, [sp, #0x18] */
/* @0x11fa44 mov r7, r1 */
/* @0x11fa48 mov r1, #0 */
/* @0x11fa4c mov r0, r5 */
/* @0x11fa50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fa54 mov r1, #1 */
/* @0x11fa58 mov r6, r0 */
/* @0x11fa5c mov r0, r5 */
/* @0x11fa60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fa64 subs r5, r0, #0 */
/* @0x11fa68 blt 0x11faa8 <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x11fa6c mov r0, r6 */
/* @0x11fa70 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11fa74 subs r1, r0, #0 */
/* @0x11fa78 beq 0x11fb10 <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x11fa7c ldr r3, [r1, #0x74] */
/* @0x11fa80 cmp r3, #1 */
/* @0x11fa84 beq 0x11faec <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x11fa88 cmp r3, #2 */
/* @0x11fa8c beq 0x11fac8 <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x11fa90 mov r3, #3 */
/* @0x11fa94 mov r1, r5 */
/* @0x11fa98 str r3, [r4, #0xc] */
/* @0x11fa9c bl 0x1e57f4 <_ZN7CSprite10GetTextureEi> */
/* @0x11faa0 str r0, [r4] */
/* @0x11faa4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x11faa8 vldr s15, [r7, #144] */
/* @0x11faac vcvt.f64.f32 d6, s15 */
/* @0x11fab0 vmov r0, r1, d6 */
/* @0x11fab4 bl 0xb6598 <floor@plt> */
/* @0x11fab8 vmov d7, r0, r1 */
/* @0x11fabc vcvt.s32.f64 s15, d7 */
/* @0x11fac0 vmov r5, s15 */
/* @0x11fac4 b 0x11fa6c <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x11fac8 ldr r0, [pc, #0x50] */
/* @0x11facc mov r1, #0 */
/* @0x11fad0 mov r3, r1 */
/* @0x11fad4 str r1, [r4, #0xc] */
/* @0x11fad8 movt r3, #0xbff0 */
/* @0x11fadc add r0, pc, r0 */
/* @0x11fae0 stm r4, {r1, r3} */
/* @0x11fae4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x11fae8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11faec ldr r0, [pc, #0x30] */
/* @0x11faf0 mov r1, #0 */
/* @0x11faf4 mov r3, r1 */
/* @0x11faf8 str r1, [r4, #0xc] */
/* @0x11fafc movt r3, #0xbff0 */
/* @0x11fb00 add r0, pc, r0 */
/* @0x11fb04 stm r4, {r1, r3} */
/* @0x11fb08 pop {r3, r4, r5, r6, r7, lr} */
/* @0x11fb0c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fb10 ldr r0, [pc, #0x10] */
/* @0x11fb14 pop {r3, r4, r5, r6, r7, lr} */
/* @0x11fb18 add r0, pc, r0 */
/* @0x11fb1c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fb20 eoreq r10, r1, r8, lsl r8 */
/* @0x11fb24 .word 0x0021a7bc */
/* @0x11fb28 eoreq r10, r1, r4, ror r7 */

/* ── FUNC 0x11fb2c · F_DrawSpritePos(RValue&, CInstance*, CInstance*, int, RValue*) · size=360 · insn=90 */
/* @0x11fb2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11fb30 sub sp, sp, #52 */
/* @0x11fb34 mov r1, #0 */
/* @0x11fb38 ldr r4, [sp, #0x58] */
/* @0x11fb3c mov r0, r4 */
/* @0x11fb40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fb44 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11fb48 subs r5, r0, #0 */
/* @0x11fb4c beq 0x11fc78 <_Z15F_DrawSpritePosR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x11fb50 ldr r3, [r5, #0x74] */
/* @0x11fb54 ldr r0, [pc, #0x12c] */
/* @0x11fb58 cmp r3, #1 */
/* @0x11fb5c add r0, pc, r0 */
/* @0x11fb60 beq 0x11fc68 <_Z15F_DrawSpritePosR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x11fb64 cmp r3, #2 */
/* @0x11fb68 beq 0x11fc60 <_Z15F_DrawSpritePosR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x11fb6c mov r0, r4 */
/* @0x11fb70 mov r1, #1 */
/* @0x11fb74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fb78 mov r1, #2 */
/* @0x11fb7c mov r8, r0 */
/* @0x11fb80 mov r0, r4 */
/* @0x11fb84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fb88 mov r1, #3 */
/* @0x11fb8c mov r7, r0 */
/* @0x11fb90 mov r0, r4 */
/* @0x11fb94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fb98 mov r1, #4 */
/* @0x11fb9c mov r6, r0 */
/* @0x11fba0 mov r0, r4 */
/* @0x11fba4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fba8 mov r1, #5 */
/* @0x11fbac mov r12, r0 */
/* @0x11fbb0 mov r0, r4 */
/* @0x11fbb4 str r12, [sp, #0x24] */
/* @0x11fbb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fbbc mov r1, #6 */
/* @0x11fbc0 mov r2, r0 */
/* @0x11fbc4 mov r0, r4 */
/* @0x11fbc8 str r2, [sp, #0x28] */
/* @0x11fbcc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fbd0 mov r1, #7 */
/* @0x11fbd4 mov r3, r0 */
/* @0x11fbd8 mov r0, r4 */
/* @0x11fbdc str r3, [sp, #0x2c] */
/* @0x11fbe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fbe4 mov r1, #8 */
/* @0x11fbe8 mov r11, r0 */
/* @0x11fbec mov r0, r4 */
/* @0x11fbf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fbf4 mov r1, #9 */
/* @0x11fbf8 mov r10, r0 */
/* @0x11fbfc mov r0, r4 */
/* @0x11fc00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fc04 mov r1, #10 */
/* @0x11fc08 mov r9, r0 */
/* @0x11fc0c mov r0, r4 */
/* @0x11fc10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11fc14 ldr r12, [sp, #0x24] */
/* @0x11fc18 ldr r2, [sp, #0x28] */
/* @0x11fc1c mov r1, r8 */
/* @0x11fc20 ldr r3, [sp, #0x2c] */
/* @0x11fc24 str r12, [sp] */
/* @0x11fc28 mvn r12, #0 */
/* @0x11fc2c str r2, [sp, #0x4] */
/* @0x11fc30 mov r2, r7 */
/* @0x11fc34 str r3, [sp, #0x8] */
/* @0x11fc38 mov r3, r6 */
/* @0x11fc3c str r11, [sp, #0xc] */
/* @0x11fc40 str r10, [sp, #0x10] */
/* @0x11fc44 str r9, [sp, #0x14] */
/* @0x11fc48 str r12, [sp, #0x18] */
/* @0x11fc4c str r0, [sp, #0x1c] */
/* @0x11fc50 mov r0, r5 */
/* @0x11fc54 bl 0x1e5d64 <_ZN7CSprite7DrawPosEiffffffffjf> */
/* @0x11fc58 add sp, sp, #52 */
/* @0x11fc5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11fc60 ldr r0, [pc, #0x24] */
/* @0x11fc64 add r0, pc, r0 */
/* @0x11fc68 mov r1, #0 */
/* @0x11fc6c add sp, sp, #52 */
/* @0x11fc70 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11fc74 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fc78 ldr r0, [pc, #0x10] */
/* @0x11fc7c mov r1, r5 */
/* @0x11fc80 add r0, pc, r0 */
/* @0x11fc84 b 0x11fc6c <_Z15F_DrawSpritePosR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x11fc88 .word 0x0021a7d8 */
/* @0x11fc8c eoreq r10, r1, r4, lsl #14 */
/* @0x11fc90 eoreq r10, r1, r4, lsr r3 */

/* ── FUNC 0x11fc94 · F_SkeletonAnimationList(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x11fc94 push {r3, r4, r5, lr} */
/* @0x11fc98 mov r1, #0 */
/* @0x11fc9c ldr r4, [sp, #0x10] */
/* @0x11fca0 mov r3, r1 */
/* @0x11fca4 str r1, [r0, #0xc] */
/* @0x11fca8 movt r3, #0xbff0 */
/* @0x11fcac stm r0, {r1, r3} */
/* @0x11fcb0 mov r0, r4 */
/* @0x11fcb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fcb8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11fcbc subs r5, r0, #0 */
/* @0x11fcc0 beq 0x11fcd0 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x11fcc4 ldr r3, [r5, #0x74] */
/* @0x11fcc8 cmp r3, #2 */
/* @0x11fccc beq 0x11fce4 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x11fcd0 ldr r0, [pc, #0x6c] */
/* @0x11fcd4 mov r1, #0 */
/* @0x11fcd8 pop {r3, r4, r5, lr} */
/* @0x11fcdc add r0, pc, r0 */
/* @0x11fce0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fce4 mov r0, r4 */
/* @0x11fce8 mov r1, #1 */
/* @0x11fcec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fcf0 cmp r0, #0 */
/* @0x11fcf4 blt 0x11fd30 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fcf8 ldr r3, [pc, #0x48] */
/* @0x11fcfc ldr r3, [pc, r3] */
/* @0x11fd00 ldr r3, [r3] */
/* @0x11fd04 cmp r0, r3 */
/* @0x11fd08 bge 0x11fd30 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fd0c ldr r3, [pc, #0x38] */
/* @0x11fd10 ldr r3, [pc, r3] */
/* @0x11fd14 ldr r3, [r3, #0x4] */
/* @0x11fd18 ldr r1, [r3, r0, lsl #2] */
/* @0x11fd1c cmp r1, #0 */
/* @0x11fd20 beq 0x11fd30 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fd24 ldr r0, [r5, #0x58] */
/* @0x11fd28 pop {r3, r4, r5, lr} */
/* @0x11fd2c b 0xc1bd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List> */
/* @0x11fd30 ldr r0, [pc, #0x18] */
/* @0x11fd34 mov r1, #0 */
/* @0x11fd38 pop {r3, r4, r5, lr} */
/* @0x11fd3c add r0, pc, r0 */
/* @0x11fd40 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fd44 eoreq r10, r1, r8, asr #13 */
/* @0x11fd48 eoreq sp, r12, r0, lsl #31 */
/* @0x11fd4c eoreq sp, r12, r0, ror pc */
/* @0x11fd50 eoreq r7, r1, r0, asr #29 */

/* ── FUNC 0x11fd54 · F_SkeletonSkinList(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x11fd54 push {r3, r4, r5, lr} */
/* @0x11fd58 mov r1, #0 */
/* @0x11fd5c ldr r4, [sp, #0x10] */
/* @0x11fd60 mov r3, r1 */
/* @0x11fd64 str r1, [r0, #0xc] */
/* @0x11fd68 movt r3, #0xbff0 */
/* @0x11fd6c stm r0, {r1, r3} */
/* @0x11fd70 mov r0, r4 */
/* @0x11fd74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fd78 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11fd7c subs r5, r0, #0 */
/* @0x11fd80 beq 0x11fd90 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x11fd84 ldr r3, [r5, #0x74] */
/* @0x11fd88 cmp r3, #2 */
/* @0x11fd8c beq 0x11fda4 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x11fd90 ldr r0, [pc, #0x6c] */
/* @0x11fd94 mov r1, #0 */
/* @0x11fd98 pop {r3, r4, r5, lr} */
/* @0x11fd9c add r0, pc, r0 */
/* @0x11fda0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fda4 mov r0, r4 */
/* @0x11fda8 mov r1, #1 */
/* @0x11fdac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fdb0 cmp r0, #0 */
/* @0x11fdb4 blt 0x11fdf0 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fdb8 ldr r3, [pc, #0x48] */
/* @0x11fdbc ldr r3, [pc, r3] */
/* @0x11fdc0 ldr r3, [r3] */
/* @0x11fdc4 cmp r0, r3 */
/* @0x11fdc8 bge 0x11fdf0 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fdcc ldr r3, [pc, #0x38] */
/* @0x11fdd0 ldr r3, [pc, r3] */
/* @0x11fdd4 ldr r3, [r3, #0x4] */
/* @0x11fdd8 ldr r1, [r3, r0, lsl #2] */
/* @0x11fddc cmp r1, #0 */
/* @0x11fde0 beq 0x11fdf0 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fde4 ldr r0, [r5, #0x58] */
/* @0x11fde8 pop {r3, r4, r5, lr} */
/* @0x11fdec b 0xc1974 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List> */
/* @0x11fdf0 ldr r0, [pc, #0x18] */
/* @0x11fdf4 mov r1, #0 */
/* @0x11fdf8 pop {r3, r4, r5, lr} */
/* @0x11fdfc add r0, pc, r0 */
/* @0x11fe00 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fe04 eoreq r10, r1, r12, lsr r6 */
/* @0x11fe08 eoreq sp, r12, r0, asr #29 */
/* @0x11fe0c .word 0x002cdeb0 */
/* @0x11fe10 eoreq r7, r1, r0, lsl #28 */

/* ── FUNC 0x11fe14 · F_SkeletonSlotData(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x11fe14 push {r3, r4, r5, lr} */
/* @0x11fe18 mov r1, #0 */
/* @0x11fe1c ldr r4, [sp, #0x10] */
/* @0x11fe20 mov r3, r1 */
/* @0x11fe24 str r1, [r0, #0xc] */
/* @0x11fe28 movt r3, #0xbff0 */
/* @0x11fe2c stm r0, {r1, r3} */
/* @0x11fe30 mov r0, r4 */
/* @0x11fe34 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fe38 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11fe3c subs r5, r0, #0 */
/* @0x11fe40 beq 0x11fe50 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x11fe44 ldr r3, [r5, #0x74] */
/* @0x11fe48 cmp r3, #2 */
/* @0x11fe4c beq 0x11fe64 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x11fe50 ldr r0, [pc, #0x6c] */
/* @0x11fe54 mov r1, #0 */
/* @0x11fe58 pop {r3, r4, r5, lr} */
/* @0x11fe5c add r0, pc, r0 */
/* @0x11fe60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fe64 mov r0, r4 */
/* @0x11fe68 mov r1, #1 */
/* @0x11fe6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fe70 cmp r0, #0 */
/* @0x11fe74 blt 0x11feb0 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fe78 ldr r3, [pc, #0x48] */
/* @0x11fe7c ldr r3, [pc, r3] */
/* @0x11fe80 ldr r3, [r3] */
/* @0x11fe84 cmp r0, r3 */
/* @0x11fe88 bge 0x11feb0 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fe8c ldr r3, [pc, #0x38] */
/* @0x11fe90 ldr r3, [pc, r3] */
/* @0x11fe94 ldr r3, [r3, #0x4] */
/* @0x11fe98 ldr r1, [r3, r0, lsl #2] */
/* @0x11fe9c cmp r1, #0 */
/* @0x11fea0 beq 0x11feb0 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11fea4 ldr r0, [r5, #0x58] */
/* @0x11fea8 pop {r3, r4, r5, lr} */
/* @0x11feac b 0xc1350 <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List> */
/* @0x11feb0 ldr r0, [pc, #0x18] */
/* @0x11feb4 mov r1, #0 */
/* @0x11feb8 pop {r3, r4, r5, lr} */
/* @0x11febc add r0, pc, r0 */
/* @0x11fec0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11fec4 eoreq r10, r1, r12, lsr #11 */
/* @0x11fec8 eoreq sp, r12, r0, lsl #28 */
/* @0x11fecc .word 0x002cddf0 */
/* @0x11fed0 eoreq r7, r1, r0, asr #26 */

/* ── FUNC 0x11fed4 · F_TileGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x11fed4 push {r3, r4, r5, r6, r7, lr} */
/* @0x11fed8 mov r5, r0 */
/* @0x11fedc ldr r4, [pc, #0x74] */
/* @0x11fee0 mov r6, #0 */
/* @0x11fee4 mov r1, r6 */
/* @0x11fee8 ldr r0, [sp, #0x18] */
/* @0x11feec ldr r4, [pc, r4] */
/* @0x11fef0 str r6, [r5, #0xc] */
/* @0x11fef4 ldr r7, [r4] */
/* @0x11fef8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11fefc mov r1, r0 */
/* @0x11ff00 mov r0, r7 */
/* @0x11ff04 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x11ff08 cmp r0, #0 */
/* @0x11ff0c blt 0x11ff3c <_Z10F_TileGetXR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x11ff10 ldr r3, [r4] */
/* @0x11ff14 ldr r2, [r3, #0xb8] */
/* @0x11ff18 cmp r0, r2 */
/* @0x11ff1c rsblt r0, r0, r0, lsl #3 */
/* @0x11ff20 ldrlt r3, [r3, #0xc0] */
/* @0x11ff24 addlt r6, r3, r0, lsl #3 */
/* @0x11ff28 vldr s15, [r6] */
/* @0x11ff2c vcvt.f64.f32 d6, s15 */
/* @0x11ff30 vmov r2, r3, d6 */
/* @0x11ff34 stm r5, {r2, r3} */
/* @0x11ff38 pop {r3, r4, r5, r6, r7, pc} */
/* @0x11ff3c ldr r0, [pc, #0x18] */
/* @0x11ff40 mov r1, r6 */
/* @0x11ff44 str r6, [r5] */
/* @0x11ff48 str r6, [r5, #0x4] */
/* @0x11ff4c add r0, pc, r0 */
/* @0x11ff50 pop {r3, r4, r5, r6, r7, lr} */
/* @0x11ff54 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11ff58 eoreq sp, r12, r12, lsr r10 */
/* @0x11ff5c .word 0x0021a2b0 */

/* ── FUNC 0x11ff60 · F_TileGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x11ff60 push {r3, r4, r5, r6, r7, lr} */
/* @0x11ff64 mov r5, r0 */
/* @0x11ff68 ldr r4, [pc, #0x74] */
/* @0x11ff6c mov r6, #0 */
/* @0x11ff70 mov r1, r6 */
/* @0x11ff74 ldr r0, [sp, #0x18] */
/* @0x11ff78 ldr r4, [pc, r4] */
/* @0x11ff7c str r6, [r5, #0xc] */
/* @0x11ff80 ldr r7, [r4] */
/* @0x11ff84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11ff88 mov r1, r0 */
/* @0x11ff8c mov r0, r7 */
/* @0x11ff90 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x11ff94 cmp r0, #0 */
/* @0x11ff98 blt 0x11ffc8 <_Z10F_TileGetYR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x11ff9c ldr r3, [r4] */
/* @0x11ffa0 ldr r2, [r3, #0xb8] */
/* @0x11ffa4 cmp r0, r2 */
/* @0x11ffa8 rsblt r0, r0, r0, lsl #3 */
/* @0x11ffac ldrlt r3, [r3, #0xc0] */
/* @0x11ffb0 addlt r6, r3, r0, lsl #3 */
/* @0x11ffb4 vldr s15, [r6, #4] */
/* @0x11ffb8 vcvt.f64.f32 d6, s15 */
/* @0x11ffbc vmov r2, r3, d6 */
/* @0x11ffc0 stm r5, {r2, r3} */
/* @0x11ffc4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x11ffc8 ldr r0, [pc, #0x18] */
/* @0x11ffcc mov r1, r6 */
/* @0x11ffd0 str r6, [r5] */
/* @0x11ffd4 str r6, [r5, #0x4] */
/* @0x11ffd8 add r0, pc, r0 */
/* @0x11ffdc pop {r3, r4, r5, r6, r7, lr} */
/* @0x11ffe0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x11ffe4 .word 0x002cd9b0 */
/* @0x11ffe8 eoreq r10, r1, r4, lsr #4 */

/* ── FUNC 0x11ffec · F_TileGetLeft(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x11ffec push {r3, r4, r5, r6, r7, lr} */
/* @0x11fff0 mov r5, r0 */
/* @0x11fff4 ldr r4, [pc, #0x78] */
/* @0x11fff8 mov r6, #0 */
/* @0x11fffc mov r1, r6 */
/* @0x120000 ldr r0, [sp, #0x18] */
/* @0x120004 ldr r4, [pc, r4] */
/* @0x120008 str r6, [r5, #0xc] */
/* @0x12000c ldr r7, [r4] */
/* @0x120010 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120014 mov r1, r0 */
/* @0x120018 mov r0, r7 */
/* @0x12001c bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120020 cmp r0, #0 */
/* @0x120024 blt 0x120058 <_Z13F_TileGetLeftR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x120028 ldr r3, [r4] */
/* @0x12002c ldr r2, [r3, #0xb8] */
/* @0x120030 cmp r0, r2 */
/* @0x120034 rsblt r0, r0, r0, lsl #3 */
/* @0x120038 ldrlt r3, [r3, #0xc0] */
/* @0x12003c addlt r6, r3, r0, lsl #3 */
/* @0x120040 ldr r2, [r6, #0xc] */
/* @0x120044 vmov s15, r2 */
/* @0x120048 vcvt.f64.s32 d7, s15 */
/* @0x12004c vmov r2, r3, d7 */
/* @0x120050 stm r5, {r2, r3} */
/* @0x120054 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120058 ldr r0, [pc, #0x18] */
/* @0x12005c mov r1, r6 */
/* @0x120060 str r6, [r5] */
/* @0x120064 str r6, [r5, #0x4] */
/* @0x120068 add r0, pc, r0 */
/* @0x12006c pop {r3, r4, r5, r6, r7, lr} */
/* @0x120070 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120074 eoreq sp, r12, r4, lsr #18 */
/* @0x120078 mlaeq r1, r4, r1, r10 */

/* ── FUNC 0x12007c · F_TileGetTop(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x12007c push {r3, r4, r5, r6, r7, lr} */
/* @0x120080 mov r5, r0 */
/* @0x120084 ldr r4, [pc, #0x78] */
/* @0x120088 mov r6, #0 */
/* @0x12008c mov r1, r6 */
/* @0x120090 ldr r0, [sp, #0x18] */
/* @0x120094 ldr r4, [pc, r4] */
/* @0x120098 str r6, [r5, #0xc] */
/* @0x12009c ldr r7, [r4] */
/* @0x1200a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1200a4 mov r1, r0 */
/* @0x1200a8 mov r0, r7 */
/* @0x1200ac bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x1200b0 cmp r0, #0 */
/* @0x1200b4 blt 0x1200e8 <_Z12F_TileGetTopR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1200b8 ldr r3, [r4] */
/* @0x1200bc ldr r2, [r3, #0xb8] */
/* @0x1200c0 cmp r0, r2 */
/* @0x1200c4 rsblt r0, r0, r0, lsl #3 */
/* @0x1200c8 ldrlt r3, [r3, #0xc0] */
/* @0x1200cc addlt r6, r3, r0, lsl #3 */
/* @0x1200d0 ldr r2, [r6, #0x10] */
/* @0x1200d4 vmov s15, r2 */
/* @0x1200d8 vcvt.f64.s32 d7, s15 */
/* @0x1200dc vmov r2, r3, d7 */
/* @0x1200e0 stm r5, {r2, r3} */
/* @0x1200e4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1200e8 ldr r0, [pc, #0x18] */
/* @0x1200ec mov r1, r6 */
/* @0x1200f0 str r6, [r5] */
/* @0x1200f4 str r6, [r5, #0x4] */
/* @0x1200f8 add r0, pc, r0 */
/* @0x1200fc pop {r3, r4, r5, r6, r7, lr} */
/* @0x120100 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120104 mlaeq r12, r4, r8, sp */
/* @0x120108 eoreq r10, r1, r4, lsl #2 */

/* ── FUNC 0x12010c · F_TileGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x12010c push {r3, r4, r5, r6, r7, lr} */
/* @0x120110 mov r5, r0 */
/* @0x120114 ldr r4, [pc, #0x78] */
/* @0x120118 mov r6, #0 */
/* @0x12011c mov r1, r6 */
/* @0x120120 ldr r0, [sp, #0x18] */
/* @0x120124 ldr r4, [pc, r4] */
/* @0x120128 str r6, [r5, #0xc] */
/* @0x12012c ldr r7, [r4] */
/* @0x120130 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120134 mov r1, r0 */
/* @0x120138 mov r0, r7 */
/* @0x12013c bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120140 cmp r0, #0 */
/* @0x120144 blt 0x120178 <_Z14F_TileGetWidthR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x120148 ldr r3, [r4] */
/* @0x12014c ldr r2, [r3, #0xb8] */
/* @0x120150 cmp r0, r2 */
/* @0x120154 rsblt r0, r0, r0, lsl #3 */
/* @0x120158 ldrlt r3, [r3, #0xc0] */
/* @0x12015c addlt r6, r3, r0, lsl #3 */
/* @0x120160 ldr r2, [r6, #0x14] */
/* @0x120164 vmov s15, r2 */
/* @0x120168 vcvt.f64.s32 d7, s15 */
/* @0x12016c vmov r2, r3, d7 */
/* @0x120170 stm r5, {r2, r3} */
/* @0x120174 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120178 ldr r0, [pc, #0x18] */
/* @0x12017c mov r1, r6 */
/* @0x120180 str r6, [r5] */
/* @0x120184 str r6, [r5, #0x4] */
/* @0x120188 add r0, pc, r0 */
/* @0x12018c pop {r3, r4, r5, r6, r7, lr} */
/* @0x120190 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120194 eoreq sp, r12, r4, lsl #16 */
/* @0x120198 eoreq r10, r1, r4, ror r0 */

/* ── FUNC 0x12019c · F_TileGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x12019c push {r3, r4, r5, r6, r7, lr} */
/* @0x1201a0 mov r5, r0 */
/* @0x1201a4 ldr r4, [pc, #0x78] */
/* @0x1201a8 mov r6, #0 */
/* @0x1201ac mov r1, r6 */
/* @0x1201b0 ldr r0, [sp, #0x18] */
/* @0x1201b4 ldr r4, [pc, r4] */
/* @0x1201b8 str r6, [r5, #0xc] */
/* @0x1201bc ldr r7, [r4] */
/* @0x1201c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1201c4 mov r1, r0 */
/* @0x1201c8 mov r0, r7 */
/* @0x1201cc bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x1201d0 cmp r0, #0 */
/* @0x1201d4 blt 0x120208 <_Z15F_TileGetHeightR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1201d8 ldr r3, [r4] */
/* @0x1201dc ldr r2, [r3, #0xb8] */
/* @0x1201e0 cmp r0, r2 */
/* @0x1201e4 rsblt r0, r0, r0, lsl #3 */
/* @0x1201e8 ldrlt r3, [r3, #0xc0] */
/* @0x1201ec addlt r6, r3, r0, lsl #3 */
/* @0x1201f0 ldr r2, [r6, #0x18] */
/* @0x1201f4 vmov s15, r2 */
/* @0x1201f8 vcvt.f64.s32 d7, s15 */
/* @0x1201fc vmov r2, r3, d7 */
/* @0x120200 stm r5, {r2, r3} */
/* @0x120204 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120208 ldr r0, [pc, #0x18] */
/* @0x12020c mov r1, r6 */
/* @0x120210 str r6, [r5] */
/* @0x120214 str r6, [r5, #0x4] */
/* @0x120218 add r0, pc, r0 */
/* @0x12021c pop {r3, r4, r5, r6, r7, lr} */
/* @0x120220 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120224 eoreq sp, r12, r4, ror r7 */
/* @0x120228 eoreq r9, r1, r4, ror #31 */

/* ── FUNC 0x12022c · F_TileGetDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x12022c push {r3, r4, r5, r6, r7, lr} */
/* @0x120230 mov r5, r0 */
/* @0x120234 ldr r4, [pc, #0x74] */
/* @0x120238 mov r6, #0 */
/* @0x12023c mov r1, r6 */
/* @0x120240 ldr r0, [sp, #0x18] */
/* @0x120244 ldr r4, [pc, r4] */
/* @0x120248 str r6, [r5, #0xc] */
/* @0x12024c ldr r7, [r4] */
/* @0x120250 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120254 mov r1, r0 */
/* @0x120258 mov r0, r7 */
/* @0x12025c bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120260 cmp r0, #0 */
/* @0x120264 blt 0x120294 <_Z14F_TileGetDepthR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x120268 ldr r3, [r4] */
/* @0x12026c ldr r2, [r3, #0xb8] */
/* @0x120270 cmp r0, r2 */
/* @0x120274 rsblt r0, r0, r0, lsl #3 */
/* @0x120278 ldrlt r3, [r3, #0xc0] */
/* @0x12027c addlt r6, r3, r0, lsl #3 */
/* @0x120280 vldr s15, [r6, #28] */
/* @0x120284 vcvt.f64.f32 d6, s15 */
/* @0x120288 vmov r2, r3, d6 */
/* @0x12028c stm r5, {r2, r3} */
/* @0x120290 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120294 ldr r0, [pc, #0x18] */
/* @0x120298 mov r1, r6 */
/* @0x12029c str r6, [r5] */
/* @0x1202a0 str r6, [r5, #0x4] */
/* @0x1202a4 add r0, pc, r0 */
/* @0x1202a8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1202ac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1202b0 eoreq sp, r12, r4, ror #13 */
/* @0x1202b4 eoreq r9, r1, r8, asr pc */

/* ── FUNC 0x1202b8 · F_TileGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x1202b8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1202bc mov r5, r0 */
/* @0x1202c0 ldr r4, [pc, #0x78] */
/* @0x1202c4 mov r6, #0 */
/* @0x1202c8 mov r1, r6 */
/* @0x1202cc ldr r0, [sp, #0x18] */
/* @0x1202d0 ldr r4, [pc, r4] */
/* @0x1202d4 str r6, [r5, #0xc] */
/* @0x1202d8 ldr r7, [r4] */
/* @0x1202dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1202e0 mov r1, r0 */
/* @0x1202e4 mov r0, r7 */
/* @0x1202e8 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x1202ec cmp r0, #0 */
/* @0x1202f0 blt 0x120324 <_Z16F_TileGetVisibleR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1202f4 ldr r3, [r4] */
/* @0x1202f8 ldr r2, [r3, #0xb8] */
/* @0x1202fc cmp r0, r2 */
/* @0x120300 rsblt r0, r0, r0, lsl #3 */
/* @0x120304 ldrlt r3, [r3, #0xc0] */
/* @0x120308 addlt r6, r3, r0, lsl #3 */
/* @0x12030c ldrb r2, [r6, #0x34] */
/* @0x120310 vmov s15, r2 */
/* @0x120314 vcvt.f64.u32 d7, s15 */
/* @0x120318 vmov r2, r3, d7 */
/* @0x12031c stm r5, {r2, r3} */
/* @0x120320 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120324 ldr r0, [pc, #0x18] */
/* @0x120328 mov r1, r6 */
/* @0x12032c str r6, [r5] */
/* @0x120330 str r6, [r5, #0x4] */
/* @0x120334 add r0, pc, r0 */
/* @0x120338 pop {r3, r4, r5, r6, r7, lr} */
/* @0x12033c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120340 eoreq sp, r12, r8, asr r6 */
/* @0x120344 eoreq r9, r1, r8, asr #29 */

/* ── FUNC 0x120348 · F_TileGetXscale(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x120348 push {r3, r4, r5, r6, r7, lr} */
/* @0x12034c mov r5, r0 */
/* @0x120350 ldr r4, [pc, #0x74] */
/* @0x120354 mov r6, #0 */
/* @0x120358 mov r1, r6 */
/* @0x12035c ldr r0, [sp, #0x18] */
/* @0x120360 ldr r4, [pc, r4] */
/* @0x120364 str r6, [r5, #0xc] */
/* @0x120368 ldr r7, [r4] */
/* @0x12036c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120370 mov r1, r0 */
/* @0x120374 mov r0, r7 */
/* @0x120378 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x12037c cmp r0, #0 */
/* @0x120380 blt 0x1203b0 <_Z15F_TileGetXscaleR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x120384 ldr r3, [r4] */
/* @0x120388 ldr r2, [r3, #0xb8] */
/* @0x12038c cmp r0, r2 */
/* @0x120390 rsblt r0, r0, r0, lsl #3 */
/* @0x120394 ldrlt r3, [r3, #0xc0] */
/* @0x120398 addlt r6, r3, r0, lsl #3 */
/* @0x12039c vldr s15, [r6, #36] */
/* @0x1203a0 vcvt.f64.f32 d6, s15 */
/* @0x1203a4 vmov r2, r3, d6 */
/* @0x1203a8 stm r5, {r2, r3} */
/* @0x1203ac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1203b0 ldr r0, [pc, #0x18] */
/* @0x1203b4 mov r1, r6 */
/* @0x1203b8 str r6, [r5] */
/* @0x1203bc str r6, [r5, #0x4] */
/* @0x1203c0 add r0, pc, r0 */
/* @0x1203c4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1203c8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1203cc eoreq sp, r12, r8, asr #11 */
/* @0x1203d0 eoreq r9, r1, r12, lsr lr */

/* ── FUNC 0x1203d4 · F_TileGetYscale(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1203d4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1203d8 mov r5, r0 */
/* @0x1203dc ldr r4, [pc, #0x74] */
/* @0x1203e0 mov r6, #0 */
/* @0x1203e4 mov r1, r6 */
/* @0x1203e8 ldr r0, [sp, #0x18] */
/* @0x1203ec ldr r4, [pc, r4] */
/* @0x1203f0 str r6, [r5, #0xc] */
/* @0x1203f4 ldr r7, [r4] */
/* @0x1203f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1203fc mov r1, r0 */
/* @0x120400 mov r0, r7 */
/* @0x120404 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120408 cmp r0, #0 */
/* @0x12040c blt 0x12043c <_Z15F_TileGetYscaleR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x120410 ldr r3, [r4] */
/* @0x120414 ldr r2, [r3, #0xb8] */
/* @0x120418 cmp r0, r2 */
/* @0x12041c rsblt r0, r0, r0, lsl #3 */
/* @0x120420 ldrlt r3, [r3, #0xc0] */
/* @0x120424 addlt r6, r3, r0, lsl #3 */
/* @0x120428 vldr s15, [r6, #40] */
/* @0x12042c vcvt.f64.f32 d6, s15 */
/* @0x120430 vmov r2, r3, d6 */
/* @0x120434 stm r5, {r2, r3} */
/* @0x120438 pop {r3, r4, r5, r6, r7, pc} */
/* @0x12043c ldr r0, [pc, #0x18] */
/* @0x120440 mov r1, r6 */
/* @0x120444 str r6, [r5] */
/* @0x120448 str r6, [r5, #0x4] */
/* @0x12044c add r0, pc, r0 */
/* @0x120450 pop {r3, r4, r5, r6, r7, lr} */
/* @0x120454 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120458 eoreq sp, r12, r12, lsr r5 */
/* @0x12045c .word 0x00219db0 */

/* ── FUNC 0x120460 · F_TileGetBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x120460 push {r3, r4, r5, r6, r7, lr} */
/* @0x120464 mov r5, r0 */
/* @0x120468 ldr r4, [pc, #0x78] */
/* @0x12046c mov r6, #0 */
/* @0x120470 mov r1, r6 */
/* @0x120474 ldr r0, [sp, #0x18] */
/* @0x120478 ldr r4, [pc, r4] */
/* @0x12047c str r6, [r5, #0xc] */
/* @0x120480 ldr r7, [r4] */
/* @0x120484 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120488 mov r1, r0 */
/* @0x12048c mov r0, r7 */
/* @0x120490 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120494 cmp r0, #0 */
/* @0x120498 blt 0x1204cc <_Z14F_TileGetBlendR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x12049c ldr r3, [r4] */
/* @0x1204a0 ldr r2, [r3, #0xb8] */
/* @0x1204a4 cmp r0, r2 */
/* @0x1204a8 rsblt r0, r0, r0, lsl #3 */
/* @0x1204ac ldrlt r3, [r3, #0xc0] */
/* @0x1204b0 addlt r6, r3, r0, lsl #3 */
/* @0x1204b4 ldr r2, [r6, #0x2c] */
/* @0x1204b8 vmov s15, r2 */
/* @0x1204bc vcvt.f64.s32 d7, s15 */
/* @0x1204c0 vmov r2, r3, d7 */
/* @0x1204c4 stm r5, {r2, r3} */
/* @0x1204c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1204cc ldr r0, [pc, #0x18] */
/* @0x1204d0 mov r1, r6 */
/* @0x1204d4 str r6, [r5] */
/* @0x1204d8 str r6, [r5, #0x4] */
/* @0x1204dc add r0, pc, r0 */
/* @0x1204e0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1204e4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1204e8 .word 0x002cd4b0 */
/* @0x1204ec eoreq r9, r1, r0, lsr #26 */

/* ── FUNC 0x1204f0 · F_TileGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1204f0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1204f4 mov r5, r0 */
/* @0x1204f8 ldr r4, [pc, #0x74] */
/* @0x1204fc mov r6, #0 */
/* @0x120500 mov r1, r6 */
/* @0x120504 ldr r0, [sp, #0x18] */
/* @0x120508 ldr r4, [pc, r4] */
/* @0x12050c str r6, [r5, #0xc] */
/* @0x120510 ldr r7, [r4] */
/* @0x120514 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120518 mov r1, r0 */
/* @0x12051c mov r0, r7 */
/* @0x120520 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120524 cmp r0, #0 */
/* @0x120528 blt 0x120558 <_Z14F_TileGetAlphaR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x12052c ldr r3, [r4] */
/* @0x120530 ldr r2, [r3, #0xb8] */
/* @0x120534 cmp r0, r2 */
/* @0x120538 rsblt r0, r0, r0, lsl #3 */
/* @0x12053c ldrlt r3, [r3, #0xc0] */
/* @0x120540 addlt r6, r3, r0, lsl #3 */
/* @0x120544 vldr s15, [r6, #48] */
/* @0x120548 vcvt.f64.f32 d6, s15 */
/* @0x12054c vmov r2, r3, d6 */
/* @0x120550 stm r5, {r2, r3} */
/* @0x120554 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120558 ldr r0, [pc, #0x18] */
/* @0x12055c mov r1, r6 */
/* @0x120560 str r6, [r5] */
/* @0x120564 str r6, [r5, #0x4] */
/* @0x120568 add r0, pc, r0 */
/* @0x12056c pop {r3, r4, r5, r6, r7, lr} */
/* @0x120570 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120574 eoreq sp, r12, r0, lsr #8 */
/* @0x120578 mlaeq r1, r4, r12, r9 */

/* ── FUNC 0x12057c · F_TileGetBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x12057c push {r3, r4, r5, r6, r7, lr} */
/* @0x120580 mov r5, r0 */
/* @0x120584 ldr r4, [pc, #0x78] */
/* @0x120588 mov r6, #0 */
/* @0x12058c mov r1, r6 */
/* @0x120590 ldr r0, [sp, #0x18] */
/* @0x120594 ldr r4, [pc, r4] */
/* @0x120598 str r6, [r5, #0xc] */
/* @0x12059c ldr r7, [r4] */
/* @0x1205a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1205a4 mov r1, r0 */
/* @0x1205a8 mov r0, r7 */
/* @0x1205ac bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x1205b0 cmp r0, #0 */
/* @0x1205b4 blt 0x1205e8 <_Z19F_TileGetBackgroundR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1205b8 ldr r3, [r4] */
/* @0x1205bc ldr r2, [r3, #0xb8] */
/* @0x1205c0 cmp r0, r2 */
/* @0x1205c4 rsblt r0, r0, r0, lsl #3 */
/* @0x1205c8 ldrlt r3, [r3, #0xc0] */
/* @0x1205cc addlt r6, r3, r0, lsl #3 */
/* @0x1205d0 ldr r2, [r6, #0x8] */
/* @0x1205d4 vmov s15, r2 */
/* @0x1205d8 vcvt.f64.s32 d7, s15 */
/* @0x1205dc vmov r2, r3, d7 */
/* @0x1205e0 stm r5, {r2, r3} */
/* @0x1205e4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1205e8 ldr r0, [pc, #0x18] */
/* @0x1205ec mov r1, r6 */
/* @0x1205f0 str r6, [r5] */
/* @0x1205f4 str r6, [r5, #0x4] */
/* @0x1205f8 add r0, pc, r0 */
/* @0x1205fc pop {r3, r4, r5, r6, r7, lr} */
/* @0x120600 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120604 mlaeq r12, r4, r3, sp */
/* @0x120608 eoreq r9, r1, r4, lsl #24 */
