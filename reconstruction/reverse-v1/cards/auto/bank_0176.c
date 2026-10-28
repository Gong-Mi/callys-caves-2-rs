/* libyoyo.so 覆盖卡组 0176
 * 函数 0x1fa688..0x1fb26c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1fa688 · SV_Argument11(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa688 push {r3, lr} */
/* @0x1fa68c mov r0, r1 */
/* @0x1fa690 ldr r3, [pc, #0x1c] */
/* @0x1fa694 mov r1, r2 */
/* @0x1fa698 mov r2, r0 */
/* @0x1fa69c ldr r3, [pc, r3] */
/* @0x1fa6a0 ldr r0, [r3] */
/* @0x1fa6a4 add r0, r0, #176 */
/* @0x1fa6a8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa6ac mov r0, #1 */
/* @0x1fa6b0 pop {r3, pc} */
/* @0x1fa6b4 andseq r3, pc, r4, ror r6 */

/* ── FUNC 0x1fa6b8 · SV_Argument12(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa6b8 push {r3, lr} */
/* @0x1fa6bc mov r0, r1 */
/* @0x1fa6c0 ldr r3, [pc, #0x1c] */
/* @0x1fa6c4 mov r1, r2 */
/* @0x1fa6c8 mov r2, r0 */
/* @0x1fa6cc ldr r3, [pc, r3] */
/* @0x1fa6d0 ldr r0, [r3] */
/* @0x1fa6d4 add r0, r0, #192 */
/* @0x1fa6d8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa6dc mov r0, #1 */
/* @0x1fa6e0 pop {r3, pc} */
/* @0x1fa6e4 andseq r3, pc, r4, asr #12 */

/* ── FUNC 0x1fa6e8 · SV_Argument13(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa6e8 push {r3, lr} */
/* @0x1fa6ec mov r0, r1 */
/* @0x1fa6f0 ldr r3, [pc, #0x1c] */
/* @0x1fa6f4 mov r1, r2 */
/* @0x1fa6f8 mov r2, r0 */
/* @0x1fa6fc ldr r3, [pc, r3] */
/* @0x1fa700 ldr r0, [r3] */
/* @0x1fa704 add r0, r0, #208 */
/* @0x1fa708 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa70c mov r0, #1 */
/* @0x1fa710 pop {r3, pc} */
/* @0x1fa714 andseq r3, pc, r4, lsl r6 */

/* ── FUNC 0x1fa718 · SV_Argument14(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa718 push {r3, lr} */
/* @0x1fa71c mov r0, r1 */
/* @0x1fa720 ldr r3, [pc, #0x1c] */
/* @0x1fa724 mov r1, r2 */
/* @0x1fa728 mov r2, r0 */
/* @0x1fa72c ldr r3, [pc, r3] */
/* @0x1fa730 ldr r0, [r3] */
/* @0x1fa734 add r0, r0, #224 */
/* @0x1fa738 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa73c mov r0, #1 */
/* @0x1fa740 pop {r3, pc} */
/* @0x1fa744 andseq r3, pc, r4, ror #11 */

/* ── FUNC 0x1fa748 · SV_Argument15(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa748 push {r3, lr} */
/* @0x1fa74c mov r0, r1 */
/* @0x1fa750 ldr r3, [pc, #0x1c] */
/* @0x1fa754 mov r1, r2 */
/* @0x1fa758 mov r2, r0 */
/* @0x1fa75c ldr r3, [pc, r3] */
/* @0x1fa760 ldr r0, [r3] */
/* @0x1fa764 add r0, r0, #240 */
/* @0x1fa768 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1fa76c mov r0, #1 */
/* @0x1fa770 pop {r3, pc} */
/* @0x1fa774 ldrheq r3, [pc], -r4 */

/* ── FUNC 0x1fa778 · SV_TransitionKind(CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1fa778 push {r4, lr} */
/* @0x1fa77c ldr r1, [r2, #0x4] */
/* @0x1fa780 ldr r0, [r2] */
/* @0x1fa784 bl 0xb66e8 <lrint@plt> */
/* @0x1fa788 ldr r3, [pc, #0x38] */
/* @0x1fa78c ldr r4, [pc, #0x38] */
/* @0x1fa790 ldr r3, [pc, r3] */
/* @0x1fa794 ldr r1, [pc, #0x34] */
/* @0x1fa798 ldr r4, [pc, r4] */
/* @0x1fa79c ldr r3, [r3] */
/* @0x1fa7a0 add r1, pc, r1 */
/* @0x1fa7a4 ldr r2, [r3] */
/* @0x1fa7a8 ldr r2, [r2, #0xc] */
/* @0x1fa7ac str r0, [r4] */
/* @0x1fa7b0 mov r0, r3 */
/* @0x1fa7b4 blx r2 */
/* @0x1fa7b8 mov r3, #0 */
/* @0x1fa7bc mov r0, #1 */
/* @0x1fa7c0 str r3, [r4] */
/* @0x1fa7c4 pop {r4, pc} */
/* @0x1fa7c8 andseq r2, pc, r4, lsl #31 */
/* @0x1fa7cc andseq r3, pc, r0, lsl r9 */
/* @0x1fa7d0 andseq r8, r5, r8, ror #2 */

/* ── FUNC 0x1fa7d4 · SV_Room(CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1fa7d4 push {r3, lr} */
/* @0x1fa7d8 ldm r2, {r0, r1} */
/* @0x1fa7dc bl 0xb66e8 <lrint@plt> */
/* @0x1fa7e0 ldr r3, [pc, #0x10] */
/* @0x1fa7e4 ldr r3, [pc, r3] */
/* @0x1fa7e8 ldr r1, [r3] */
/* @0x1fa7ec bl 0x1c9e08 <_Z16Command_GotoRoomii> */
/* @0x1fa7f0 mov r0, #1 */
/* @0x1fa7f4 pop {r3, pc} */
/* @0x1fa7f8 andseq r3, pc, r4, asr #17 */

/* ── FUNC 0x1fa7fc · SV_KeyboardLastChar(CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1fa7fc push {r3, lr} */
/* @0x1fa800 ldr r3, [r2, #0xc] */
/* @0x1fa804 bic r3, r3, #-16777216 */
/* @0x1fa808 cmp r3, #1 */
/* @0x1fa80c beq 0x1fa818 <_Z19SV_KeyboardLastCharP9CInstanceiP6RValue+0x1c> */
/* @0x1fa810 mov r0, #1 */
/* @0x1fa814 pop {r3, pc} */
/* @0x1fa818 ldr r3, [r2] */
/* @0x1fa81c cmp r3, #0 */
/* @0x1fa820 beq 0x1fa810 <_Z19SV_KeyboardLastCharP9CInstanceiP6RValue+0x14> */
/* @0x1fa824 ldr r3, [r3] */
/* @0x1fa828 cmp r3, #0 */
/* @0x1fa82c beq 0x1fa810 <_Z19SV_KeyboardLastCharP9CInstanceiP6RValue+0x14> */
/* @0x1fa830 ldrb r0, [r3] */
/* @0x1fa834 bl 0x18bd20 <_Z16IO_Char_Last_Setc> */
/* @0x1fa838 mov r0, #1 */
/* @0x1fa83c pop {r3, pc} */

/* ── FUNC 0x1fa840 · SV_KeyboardString(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1fa840 push {r3, lr} */
/* @0x1fa844 ldr r3, [r2, #0xc] */
/* @0x1fa848 bic r3, r3, #-16777216 */
/* @0x1fa84c cmp r3, #1 */
/* @0x1fa850 movne r0, #0 */
/* @0x1fa854 bne 0x1fa864 <_Z17SV_KeyboardStringP9CInstanceiP6RValue+0x24> */
/* @0x1fa858 ldr r0, [r2] */
/* @0x1fa85c cmp r0, #0 */
/* @0x1fa860 ldrne r0, [r0] */
/* @0x1fa864 bl 0x18bdb4 <_Z13IO_String_SetPKc> */
/* @0x1fa868 mov r0, #1 */
/* @0x1fa86c pop {r3, pc} */

/* ── FUNC 0x1fa870 · GV_Alarm(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fa870 cmp r1, #11 */
/* @0x1fa874 mov r3, #0 */
/* @0x1fa878 push {r4, r5, r6, lr} */
/* @0x1fa87c movhi r1, #0 */
/* @0x1fa880 str r3, [r2, #0xc] */
/* @0x1fa884 mov r6, r2 */
/* @0x1fa888 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x1fa88c vmov s15, r0 */
/* @0x1fa890 mov r0, #1 */
/* @0x1fa894 vcvt.f64.s32 d7, s15 */
/* @0x1fa898 vmov r4, r5, d7 */
/* @0x1fa89c vmov r2, s14 */
/* @0x1fa8a0 mov r3, r5 */
/* @0x1fa8a4 stm r6, {r2, r3} */
/* @0x1fa8a8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa8ac · GV_Bbl(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fa8ac ldrb r3, [r0, #0x64] */
/* @0x1fa8b0 push {r4, r5, r6, lr} */
/* @0x1fa8b4 mov r6, r2 */
/* @0x1fa8b8 mov r2, #0 */
/* @0x1fa8bc cmp r3, r2 */
/* @0x1fa8c0 mov r4, r0 */
/* @0x1fa8c4 str r2, [r6, #0xc] */
/* @0x1fa8c8 beq 0x1fa8d4 <_Z6GV_BblP9CInstanceiP6RValue+0x28> */
/* @0x1fa8cc mov r1, #1 */
/* @0x1fa8d0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1fa8d4 ldr r4, [r4, #0xe8] */
/* @0x1fa8d8 mov r0, #1 */
/* @0x1fa8dc vmov s15, r4 */
/* @0x1fa8e0 vcvt.f64.s32 d7, s15 */
/* @0x1fa8e4 vmov r4, r5, d7 */
/* @0x1fa8e8 vmov r2, s14 */
/* @0x1fa8ec mov r3, r5 */
/* @0x1fa8f0 stm r6, {r2, r3} */
/* @0x1fa8f4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa8f8 · GV_Bbr(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fa8f8 ldrb r3, [r0, #0x64] */
/* @0x1fa8fc push {r4, r5, r6, lr} */
/* @0x1fa900 mov r6, r2 */
/* @0x1fa904 mov r2, #0 */
/* @0x1fa908 cmp r3, r2 */
/* @0x1fa90c mov r4, r0 */
/* @0x1fa910 str r2, [r6, #0xc] */
/* @0x1fa914 beq 0x1fa920 <_Z6GV_BbrP9CInstanceiP6RValue+0x28> */
/* @0x1fa918 mov r1, #1 */
/* @0x1fa91c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1fa920 ldr r4, [r4, #0xf0] */
/* @0x1fa924 mov r0, #1 */
/* @0x1fa928 vmov s15, r4 */
/* @0x1fa92c vcvt.f64.s32 d7, s15 */
/* @0x1fa930 vmov r4, r5, d7 */
/* @0x1fa934 vmov r2, s14 */
/* @0x1fa938 mov r3, r5 */
/* @0x1fa93c stm r6, {r2, r3} */
/* @0x1fa940 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa944 · GV_Bbb(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fa944 ldrb r3, [r0, #0x64] */
/* @0x1fa948 push {r4, r5, r6, lr} */
/* @0x1fa94c mov r6, r2 */
/* @0x1fa950 mov r2, #0 */
/* @0x1fa954 cmp r3, r2 */
/* @0x1fa958 mov r4, r0 */
/* @0x1fa95c str r2, [r6, #0xc] */
/* @0x1fa960 beq 0x1fa96c <_Z6GV_BbbP9CInstanceiP6RValue+0x28> */
/* @0x1fa964 mov r1, #1 */
/* @0x1fa968 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1fa96c ldr r4, [r4, #0xf4] */
/* @0x1fa970 mov r0, #1 */
/* @0x1fa974 vmov s15, r4 */
/* @0x1fa978 vcvt.f64.s32 d7, s15 */
/* @0x1fa97c vmov r4, r5, d7 */
/* @0x1fa980 vmov r2, s14 */
/* @0x1fa984 mov r3, r5 */
/* @0x1fa988 stm r6, {r2, r3} */
/* @0x1fa98c pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa990 · GV_Bbt(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1fa990 ldrb r3, [r0, #0x64] */
/* @0x1fa994 push {r4, r5, r6, lr} */
/* @0x1fa998 mov r6, r2 */
/* @0x1fa99c mov r2, #0 */
/* @0x1fa9a0 cmp r3, r2 */
/* @0x1fa9a4 mov r4, r0 */
/* @0x1fa9a8 str r2, [r6, #0xc] */
/* @0x1fa9ac beq 0x1fa9b8 <_Z6GV_BbtP9CInstanceiP6RValue+0x28> */
/* @0x1fa9b0 mov r1, #1 */
/* @0x1fa9b4 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1fa9b8 ldr r4, [r4, #0xec] */
/* @0x1fa9bc mov r0, #1 */
/* @0x1fa9c0 vmov s15, r4 */
/* @0x1fa9c4 vcvt.f64.s32 d7, s15 */
/* @0x1fa9c8 vmov r4, r5, d7 */
/* @0x1fa9cc vmov r2, s14 */
/* @0x1fa9d0 mov r3, r5 */
/* @0x1fa9d4 stm r6, {r2, r3} */
/* @0x1fa9d8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1fa9dc · GV_ImageNumber(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1fa9dc push {r4, r5, r6, lr} */
/* @0x1fa9e0 mov r3, #0 */
/* @0x1fa9e4 str r3, [r2, #0xc] */
/* @0x1fa9e8 mov r6, r2 */
/* @0x1fa9ec bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0x1fa9f0 vmov s15, r0 */
/* @0x1fa9f4 mov r0, #1 */
/* @0x1fa9f8 vcvt.f64.s32 d7, s15 */
/* @0x1fa9fc vmov r4, r5, d7 */
/* @0x1faa00 vmov r2, s14 */
/* @0x1faa04 mov r3, r5 */
/* @0x1faa08 stm r6, {r2, r3} */
/* @0x1faa0c pop {r4, r5, r6, pc} */

/* ── FUNC 0x1faa10 · SV_SpriteIndex(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1faa10 push {r4, lr} */
/* @0x1faa14 mov r4, r0 */
/* @0x1faa18 mov r0, r2 */
/* @0x1faa1c bl 0xd11b0 <_Z12INT32_RValuePK6RValue> */
/* @0x1faa20 mov r1, r0 */
/* @0x1faa24 mov r0, r4 */
/* @0x1faa28 bl 0x1931c0 <_ZN9CInstance14SetSpriteIndexEi> */
/* @0x1faa2c mov r0, #1 */
/* @0x1faa30 pop {r4, pc} */

/* ── FUNC 0x1faa34 · GV_PhysicsSpeed(CInstance*, int, RValue*) · size=308 · insn=77 */
/* @0x1faa34 ldr r3, [pc, #0x120] */
/* @0x1faa38 push {r4, r5, r6, r7, lr} */
/* @0x1faa3c vpush {d8} */
/* @0x1faa40 ldr r3, [pc, r3] */
/* @0x1faa44 ldr r5, [r0, #0x84] */
/* @0x1faa48 sub sp, sp, #12 */
/* @0x1faa4c ldr r1, [r3] */
/* @0x1faa50 ldr r4, [r1, #0xb4] */
/* @0x1faa54 cmp r5, #0 */
/* @0x1faa58 cmpne r4, #0 */
/* @0x1faa5c moveq r6, #0 */
/* @0x1faa60 movne r6, #1 */
/* @0x1faa64 beq 0x1faad8 <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0xa4> */
/* @0x1faa68 ldr r3, [pc, #0xf0] */
/* @0x1faa6c mov r0, #0 */
/* @0x1faa70 str r0, [r2, #0xc] */
/* @0x1faa74 ldr r3, [pc, r3] */
/* @0x1faa78 ldrb r3, [r3] */
/* @0x1faa7c cmp r3, r0 */
/* @0x1faa80 bne 0x1faae8 <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0xb4> */
/* @0x1faa84 ldr r3, [r5] */
/* @0x1faa88 vldr s13, [r4, #96] */
/* @0x1faa8c vldr s16, [r3, #80] */
/* @0x1faa90 vldr s12, [r3, #84] */
/* @0x1faa94 vdiv.f32 s16, s16, s13 */
/* @0x1faa98 vldr s15, [r1, #12] */
/* @0x1faa9c vdiv.f32 s13, s12, s13 */
/* @0x1faaa0 vcvt.f32.s32 s15, s15 */
/* @0x1faaa4 vdiv.f32 s16, s16, s15 */
/* @0x1faaa8 vdiv.f32 s14, s13, s15 */
/* @0x1faaac vmul.f32 s14, s14, s14 */
/* @0x1faab0 vmla.f32 s14, s16, s16 */
/* @0x1faab4 vsqrt.f32 s15, s14 */
/* @0x1faab8 vcmp.f32 s15, s15 */
/* @0x1faabc vmrs APSR_nzcv, fpscr */
/* @0x1faac0 bne 0x1fab44 <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0x110> */
/* @0x1faac4 vcvt.f64.f32 d6, s15 */
/* @0x1faac8 vmov r4, r5, d6 */
/* @0x1faacc vmov r1, s12 */
/* @0x1faad0 mov r3, r5 */
/* @0x1faad4 stm r2, {r1, r3} */
/* @0x1faad8 mov r0, r6 */
/* @0x1faadc add sp, sp, #12 */
/* @0x1faae0 vpop {d8} */
/* @0x1faae4 pop {r4, r5, r6, r7, pc} */
/* @0x1faae8 ldr r7, [pc, #0x74] */
/* @0x1faaec vldr s15, [r4, #96] */
/* @0x1faaf0 ldr r3, [r5] */
/* @0x1faaf4 vldr s16, [r3, #80] */
/* @0x1faaf8 ldr r7, [pc, r7] */
/* @0x1faafc vdiv.f32 s16, s16, s15 */
/* @0x1fab00 str r2, [sp, #0x4] */
/* @0x1fab04 mov r0, r7 */
/* @0x1fab08 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1fab0c ldr r3, [r5] */
/* @0x1fab10 vldr s15, [r4, #96] */
/* @0x1fab14 vldr s17, [r3, #84] */
/* @0x1fab18 vmov d6, r0, r1 */
/* @0x1fab1c mov r0, r7 */
/* @0x1fab20 vcvt.f32.f64 s14, d6 */
/* @0x1fab24 vdiv.f32 s17, s17, s15 */
/* @0x1fab28 vdiv.f32 s16, s16, s14 */
/* @0x1fab2c bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1fab30 ldr r2, [sp, #0x4] */
/* @0x1fab34 vmov d6, r0, r1 */
/* @0x1fab38 vcvt.f32.f64 s14, d6 */
/* @0x1fab3c vdiv.f32 s14, s17, s14 */
/* @0x1fab40 b 0x1faaac <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0x78> */
/* @0x1fab44 vmov r0, s14 */
/* @0x1fab48 str r2, [sp, #0x4] */
/* @0x1fab4c bl 0xb6700 <sqrtf@plt> */
/* @0x1fab50 ldr r2, [sp, #0x4] */
/* @0x1fab54 vmov s15, r0 */
/* @0x1fab58 b 0x1faac4 <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0x90> */
/* @0x1fab5c andseq r2, pc, r8, ror #29 */
/* @0x1fab60 ldrheq r2, [pc], -r0 */
/* @0x1fab64 andseq r2, pc, r4, lsr lr */

/* ── FUNC 0x1fab68 · GV_PhysicsCollisionPointCount(CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1fab68 ldr r3, [pc, #0x50] */
/* @0x1fab6c mov r1, r0 */
/* @0x1fab70 push {r4, r5, r6, lr} */
/* @0x1fab74 ldr r3, [pc, r3] */
/* @0x1fab78 mov r6, r2 */
/* @0x1fab7c ldr r3, [r3] */
/* @0x1fab80 ldr r0, [r3, #0xb4] */
/* @0x1fab84 cmp r0, #0 */
/* @0x1fab88 moveq r3, r0 */
/* @0x1fab8c beq 0x1fabb8 <_Z29GV_PhysicsCollisionPointCountP9CInstanceiP6RValue+0x50> */
/* @0x1fab90 mov r3, #0 */
/* @0x1fab94 str r3, [r2, #0xc] */
/* @0x1fab98 bl 0x238e28 <_ZN13CPhysicsWorld27GetCurrentContactPointCountEP9CInstance> */
/* @0x1fab9c mov r3, #1 */
/* @0x1faba0 vmov s15, r0 */
/* @0x1faba4 vcvt.f64.s32 d7, s15 */
/* @0x1faba8 vmov r4, r5, d7 */
/* @0x1fabac vmov r1, s14 */
/* @0x1fabb0 mov r2, r5 */
/* @0x1fabb4 stm r6, {r1, r2} */
/* @0x1fabb8 mov r0, r3 */
/* @0x1fabbc pop {r4, r5, r6, pc} */
/* @0x1fabc0 ldrheq r2, [pc], -r4 */

/* ── FUNC 0x1fabc4 · GV_PhysicsCollisionPositionX(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fabc4 ldr r3, [pc, #0x78] */
/* @0x1fabc8 mov r12, r1 */
/* @0x1fabcc push {r4, r5, r6, lr} */
/* @0x1fabd0 ldr r3, [pc, r3] */
/* @0x1fabd4 mov r4, r0 */
/* @0x1fabd8 sub sp, sp, #16 */
/* @0x1fabdc ldr r3, [r3] */
/* @0x1fabe0 mov r6, r2 */
/* @0x1fabe4 ldr r0, [r3, #0xb4] */
/* @0x1fabe8 cmp r0, #0 */
/* @0x1fabec beq 0x1fac10 <_Z28GV_PhysicsCollisionPositionXP9CInstanceiP6RValue+0x4c> */
/* @0x1fabf0 mov r2, r12 */
/* @0x1fabf4 mov r1, r4 */
/* @0x1fabf8 add r12, sp, #12 */
/* @0x1fabfc add r3, sp, #8 */
/* @0x1fac00 str r12, [sp] */
/* @0x1fac04 bl 0x238ce4 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_> */
/* @0x1fac08 cmp r0, #0 */
/* @0x1fac0c bne 0x1fac18 <_Z28GV_PhysicsCollisionPositionXP9CInstanceiP6RValue+0x54> */
/* @0x1fac10 add sp, sp, #16 */
/* @0x1fac14 pop {r4, r5, r6, pc} */
/* @0x1fac18 vldr s15, [sp, #8] */
/* @0x1fac1c vcvt.f64.f32 d6, s15 */
/* @0x1fac20 mov r3, #0 */
/* @0x1fac24 mov r0, #1 */
/* @0x1fac28 str r3, [r6, #0xc] */
/* @0x1fac2c vmov r4, r5, d6 */
/* @0x1fac30 vmov r2, s12 */
/* @0x1fac34 mov r3, r5 */
/* @0x1fac38 stm r6, {r2, r3} */
/* @0x1fac3c add sp, sp, #16 */
/* @0x1fac40 pop {r4, r5, r6, pc} */
/* @0x1fac44 andseq r2, pc, r8, asr sp */

/* ── FUNC 0x1fac48 · GV_PhysicsCollisionPositionY(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fac48 ldr r3, [pc, #0x78] */
/* @0x1fac4c mov r12, r1 */
/* @0x1fac50 push {r4, r5, r6, lr} */
/* @0x1fac54 ldr r3, [pc, r3] */
/* @0x1fac58 mov r4, r0 */
/* @0x1fac5c sub sp, sp, #16 */
/* @0x1fac60 ldr r3, [r3] */
/* @0x1fac64 mov r6, r2 */
/* @0x1fac68 ldr r0, [r3, #0xb4] */
/* @0x1fac6c cmp r0, #0 */
/* @0x1fac70 beq 0x1fac94 <_Z28GV_PhysicsCollisionPositionYP9CInstanceiP6RValue+0x4c> */
/* @0x1fac74 mov r2, r12 */
/* @0x1fac78 mov r1, r4 */
/* @0x1fac7c add r12, sp, #12 */
/* @0x1fac80 add r3, sp, #8 */
/* @0x1fac84 str r12, [sp] */
/* @0x1fac88 bl 0x238ce4 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_> */
/* @0x1fac8c cmp r0, #0 */
/* @0x1fac90 bne 0x1fac9c <_Z28GV_PhysicsCollisionPositionYP9CInstanceiP6RValue+0x54> */
/* @0x1fac94 add sp, sp, #16 */
/* @0x1fac98 pop {r4, r5, r6, pc} */
/* @0x1fac9c vldr s15, [sp, #12] */
/* @0x1faca0 vcvt.f64.f32 d6, s15 */
/* @0x1faca4 mov r3, #0 */
/* @0x1faca8 mov r0, #1 */
/* @0x1facac str r3, [r6, #0xc] */
/* @0x1facb0 vmov r4, r5, d6 */
/* @0x1facb4 vmov r2, s12 */
/* @0x1facb8 mov r3, r5 */
/* @0x1facbc stm r6, {r2, r3} */
/* @0x1facc0 add sp, sp, #16 */
/* @0x1facc4 pop {r4, r5, r6, pc} */
/* @0x1facc8 ldrsbeq r2, [pc], -r4 */

/* ── FUNC 0x1faccc · GV_PhysicsCollisionNormalX(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1faccc ldr r3, [pc, #0x78] */
/* @0x1facd0 mov r12, r1 */
/* @0x1facd4 push {r4, r5, r6, lr} */
/* @0x1facd8 ldr r3, [pc, r3] */
/* @0x1facdc mov r4, r0 */
/* @0x1face0 sub sp, sp, #16 */
/* @0x1face4 ldr r3, [r3] */
/* @0x1face8 mov r6, r2 */
/* @0x1facec ldr r0, [r3, #0xb4] */
/* @0x1facf0 cmp r0, #0 */
/* @0x1facf4 beq 0x1fad18 <_Z26GV_PhysicsCollisionNormalXP9CInstanceiP6RValue+0x4c> */
/* @0x1facf8 mov r2, r12 */
/* @0x1facfc mov r1, r4 */
/* @0x1fad00 add r12, sp, #12 */
/* @0x1fad04 add r3, sp, #8 */
/* @0x1fad08 str r12, [sp] */
/* @0x1fad0c bl 0x238d9c <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_> */
/* @0x1fad10 cmp r0, #0 */
/* @0x1fad14 bne 0x1fad20 <_Z26GV_PhysicsCollisionNormalXP9CInstanceiP6RValue+0x54> */
/* @0x1fad18 add sp, sp, #16 */
/* @0x1fad1c pop {r4, r5, r6, pc} */
/* @0x1fad20 vldr s15, [sp, #8] */
/* @0x1fad24 vcvt.f64.f32 d6, s15 */
/* @0x1fad28 mov r3, #0 */
/* @0x1fad2c mov r0, #1 */
/* @0x1fad30 str r3, [r6, #0xc] */
/* @0x1fad34 vmov r4, r5, d6 */
/* @0x1fad38 vmov r2, s12 */
/* @0x1fad3c mov r3, r5 */
/* @0x1fad40 stm r6, {r2, r3} */
/* @0x1fad44 add sp, sp, #16 */
/* @0x1fad48 pop {r4, r5, r6, pc} */
/* @0x1fad4c andseq r2, pc, r0, asr r12 */

/* ── FUNC 0x1fad50 · GV_PhysicsCollisionNormalY(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fad50 ldr r3, [pc, #0x78] */
/* @0x1fad54 mov r12, r1 */
/* @0x1fad58 push {r4, r5, r6, lr} */
/* @0x1fad5c ldr r3, [pc, r3] */
/* @0x1fad60 mov r4, r0 */
/* @0x1fad64 sub sp, sp, #16 */
/* @0x1fad68 ldr r3, [r3] */
/* @0x1fad6c mov r6, r2 */
/* @0x1fad70 ldr r0, [r3, #0xb4] */
/* @0x1fad74 cmp r0, #0 */
/* @0x1fad78 beq 0x1fad9c <_Z26GV_PhysicsCollisionNormalYP9CInstanceiP6RValue+0x4c> */
/* @0x1fad7c mov r2, r12 */
/* @0x1fad80 mov r1, r4 */
/* @0x1fad84 add r12, sp, #12 */
/* @0x1fad88 add r3, sp, #8 */
/* @0x1fad8c str r12, [sp] */
/* @0x1fad90 bl 0x238d9c <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_> */
/* @0x1fad94 cmp r0, #0 */
/* @0x1fad98 bne 0x1fada4 <_Z26GV_PhysicsCollisionNormalYP9CInstanceiP6RValue+0x54> */
/* @0x1fad9c add sp, sp, #16 */
/* @0x1fada0 pop {r4, r5, r6, pc} */
/* @0x1fada4 vldr s15, [sp, #12] */
/* @0x1fada8 vcvt.f64.f32 d6, s15 */
/* @0x1fadac mov r3, #0 */
/* @0x1fadb0 mov r0, #1 */
/* @0x1fadb4 str r3, [r6, #0xc] */
/* @0x1fadb8 vmov r4, r5, d6 */
/* @0x1fadbc vmov r2, s12 */
/* @0x1fadc0 mov r3, r5 */
/* @0x1fadc4 stm r6, {r2, r3} */
/* @0x1fadc8 add sp, sp, #16 */
/* @0x1fadcc pop {r4, r5, r6, pc} */
/* @0x1fadd0 andseq r2, pc, r12, asr #23 */

/* ── FUNC 0x1fadd4 · GV_Layer(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fadd4 push {r4, lr} */
/* @0x1fadd8 mov r4, r2 */
/* @0x1faddc mov r2, #0 */
/* @0x1fade0 mov r3, r2 */
/* @0x1fade4 movt r2, #0xbff0 */
/* @0x1fade8 str r3, [r4] */
/* @0x1fadec str r2, [r4, #0x4] */
/* @0x1fadf0 ldrb r2, [r0, #0x174] */
/* @0x1fadf4 str r3, [r4, #0xc] */
/* @0x1fadf8 cmp r2, r3 */
/* @0x1fadfc bne 0x1fae08 <_Z8GV_LayerP9CInstanceiP6RValue+0x34> */
/* @0x1fae00 mov r0, #1 */
/* @0x1fae04 pop {r4, pc} */
/* @0x1fae08 ldr r3, [pc, #0x44] */
/* @0x1fae0c ldr r1, [r0, #0x170] */
/* @0x1fae10 ldr r3, [pc, r3] */
/* @0x1fae14 ldr r0, [r3] */
/* @0x1fae18 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1fae1c cmp r0, #0 */
/* @0x1fae20 beq 0x1fae00 <_Z8GV_LayerP9CInstanceiP6RValue+0x2c> */
/* @0x1fae24 ldrb r3, [r0, #0x19] */
/* @0x1fae28 cmp r3, #0 */
/* @0x1fae2c bne 0x1fae00 <_Z8GV_LayerP9CInstanceiP6RValue+0x2c> */
/* @0x1fae30 ldr r0, [r0] */
/* @0x1fae34 vmov s15, r0 */
/* @0x1fae38 vcvt.f64.s32 d7, s15 */
/* @0x1fae3c vmov r0, r1, d7 */
/* @0x1fae40 mov r0, #1 */
/* @0x1fae44 vmov r2, s14 */
/* @0x1fae48 mov r3, r1 */
/* @0x1fae4c stm r4, {r2, r3} */
/* @0x1fae50 pop {r4, pc} */
/* @0x1fae54 andseq r2, pc, r8, lsl r11 */

/* ── FUNC 0x1fae58 · SV_RoomCaption(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fae58 ldr r1, [r2, #0xc] */
/* @0x1fae5c push {r3, r4, r5, lr} */
/* @0x1fae60 bic r1, r1, #-16777216 */
/* @0x1fae64 ldr r3, [pc, #0x40] */
/* @0x1fae68 cmp r1, #1 */
/* @0x1fae6c ldr r3, [pc, r3] */
/* @0x1fae70 movne r5, #0 */
/* @0x1fae74 ldr r4, [r3] */
/* @0x1fae78 bne 0x1fae88 <_Z14SV_RoomCaptionP9CInstanceiP6RValue+0x30> */
/* @0x1fae7c ldr r5, [r2] */
/* @0x1fae80 cmp r5, #0 */
/* @0x1fae84 ldrne r5, [r5] */
/* @0x1fae88 ldr r0, [r4, #0x8] */
/* @0x1fae8c cmp r0, #0 */
/* @0x1fae90 beq 0x1fae98 <_Z14SV_RoomCaptionP9CInstanceiP6RValue+0x40> */
/* @0x1fae94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1fae98 mov r0, r5 */
/* @0x1fae9c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1faea0 str r0, [r4, #0x8] */
/* @0x1faea4 mov r0, #1 */
/* @0x1faea8 pop {r3, r4, r5, pc} */
/* @0x1faeac ldrheq r2, [pc], -r12 */

/* ── FUNC 0x1faeb0 · GV_RoomSpeed(CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1faeb0 ldr r3, [pc, #0x64] */
/* @0x1faeb4 push {r4, lr} */
/* @0x1faeb8 ldr r3, [pc, r3] */
/* @0x1faebc mov r4, r2 */
/* @0x1faec0 mov r2, #0 */
/* @0x1faec4 ldrb r3, [r3] */
/* @0x1faec8 str r2, [r4, #0xc] */
/* @0x1faecc cmp r3, r2 */
/* @0x1faed0 bne 0x1faf04 <_Z12GV_RoomSpeedP9CInstanceiP6RValue+0x54> */
/* @0x1faed4 ldr r3, [pc, #0x44] */
/* @0x1faed8 ldr r3, [pc, r3] */
/* @0x1faedc ldr r3, [r3] */
/* @0x1faee0 ldr r0, [r3, #0xc] */
/* @0x1faee4 vmov s15, r0 */
/* @0x1faee8 vcvt.f64.s32 d7, s15 */
/* @0x1faeec vmov r0, r1, d7 */
/* @0x1faef0 mov r0, #1 */
/* @0x1faef4 vmov r2, s14 */
/* @0x1faef8 mov r3, r1 */
/* @0x1faefc stm r4, {r2, r3} */
/* @0x1faf00 pop {r4, pc} */
/* @0x1faf04 ldr r0, [pc, #0x18] */
/* @0x1faf08 ldr r0, [pc, r0] */
/* @0x1faf0c bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1faf10 stm r4, {r0, r1} */
/* @0x1faf14 mov r0, #1 */
/* @0x1faf18 pop {r4, pc} */
/* @0x1faf1c andseq r2, pc, r12, ror #20 */
/* @0x1faf20 andseq r2, pc, r0, asr r10 */
/* @0x1faf24 andseq r2, pc, r4, lsr #20 */

/* ── FUNC 0x1faf28 · GV_SpriteWidth(CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1faf28 push {r3, r4, r5, lr} */
/* @0x1faf2c mov r3, #0 */
/* @0x1faf30 mov r5, r0 */
/* @0x1faf34 ldr r0, [r0, #0x8c] */
/* @0x1faf38 str r3, [r2, #0xc] */
/* @0x1faf3c mov r4, r2 */
/* @0x1faf40 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1faf44 cmp r0, #0 */
/* @0x1faf48 streq r0, [r4] */
/* @0x1faf4c streq r0, [r4, #0x4] */
/* @0x1faf50 beq 0x1faf80 <_Z14GV_SpriteWidthP9CInstanceiP6RValue+0x58> */
/* @0x1faf54 ldr r0, [r5, #0x8c] */
/* @0x1faf58 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1faf5c vldr s14, [r5, #152] */
/* @0x1faf60 vldr s15, [r0, #28] */
/* @0x1faf64 vcvt.f32.s32 s15, s15 */
/* @0x1faf68 vmul.f32 s15, s15, s14 */
/* @0x1faf6c vcvt.f64.f32 d6, s15 */
/* @0x1faf70 vmov r0, r1, d6 */
/* @0x1faf74 vmov r2, s12 */
/* @0x1faf78 mov r3, r1 */
/* @0x1faf7c stm r4, {r2, r3} */
/* @0x1faf80 mov r0, #1 */
/* @0x1faf84 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1faf88 · GV_SpriteHeight(CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1faf88 push {r3, r4, r5, lr} */
/* @0x1faf8c mov r3, #0 */
/* @0x1faf90 mov r5, r0 */
/* @0x1faf94 ldr r0, [r0, #0x8c] */
/* @0x1faf98 str r3, [r2, #0xc] */
/* @0x1faf9c mov r4, r2 */
/* @0x1fafa0 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1fafa4 cmp r0, #0 */
/* @0x1fafa8 streq r0, [r4] */
/* @0x1fafac streq r0, [r4, #0x4] */
/* @0x1fafb0 beq 0x1fafe0 <_Z15GV_SpriteHeightP9CInstanceiP6RValue+0x58> */
/* @0x1fafb4 ldr r0, [r5, #0x8c] */
/* @0x1fafb8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1fafbc vldr s14, [r5, #156] */
/* @0x1fafc0 vldr s15, [r0, #32] */
/* @0x1fafc4 vcvt.f32.s32 s15, s15 */
/* @0x1fafc8 vmul.f32 s15, s15, s14 */
/* @0x1fafcc vcvt.f64.f32 d6, s15 */
/* @0x1fafd0 vmov r0, r1, d6 */
/* @0x1fafd4 vmov r2, s12 */
/* @0x1fafd8 mov r3, r1 */
/* @0x1fafdc stm r4, {r2, r3} */
/* @0x1fafe0 mov r0, #1 */
/* @0x1fafe4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1fafe8 · GV_SpriteXOffset(CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1fafe8 push {r3, r4, r5, lr} */
/* @0x1fafec mov r3, #0 */
/* @0x1faff0 mov r5, r0 */
/* @0x1faff4 ldr r0, [r0, #0x8c] */
/* @0x1faff8 str r3, [r2, #0xc] */
/* @0x1faffc mov r4, r2 */
/* @0x1fb000 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1fb004 cmp r0, #0 */
/* @0x1fb008 streq r0, [r4] */
/* @0x1fb00c streq r0, [r4, #0x4] */
/* @0x1fb010 beq 0x1fb040 <_Z16GV_SpriteXOffsetP9CInstanceiP6RValue+0x58> */
/* @0x1fb014 ldr r0, [r5, #0x8c] */
/* @0x1fb018 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1fb01c vldr s14, [r5, #152] */
/* @0x1fb020 vldr s15, [r0, #36] */
/* @0x1fb024 vcvt.f32.s32 s15, s15 */
/* @0x1fb028 vmul.f32 s15, s15, s14 */
/* @0x1fb02c vcvt.f64.f32 d6, s15 */
/* @0x1fb030 vmov r0, r1, d6 */
/* @0x1fb034 vmov r2, s12 */
/* @0x1fb038 mov r3, r1 */
/* @0x1fb03c stm r4, {r2, r3} */
/* @0x1fb040 mov r0, #1 */
/* @0x1fb044 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1fb048 · GV_SpriteYOffset(CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1fb048 push {r3, r4, r5, lr} */
/* @0x1fb04c mov r3, #0 */
/* @0x1fb050 mov r5, r0 */
/* @0x1fb054 ldr r0, [r0, #0x8c] */
/* @0x1fb058 str r3, [r2, #0xc] */
/* @0x1fb05c mov r4, r2 */
/* @0x1fb060 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1fb064 cmp r0, #0 */
/* @0x1fb068 streq r0, [r4] */
/* @0x1fb06c streq r0, [r4, #0x4] */
/* @0x1fb070 beq 0x1fb0a0 <_Z16GV_SpriteYOffsetP9CInstanceiP6RValue+0x58> */
/* @0x1fb074 ldr r0, [r5, #0x8c] */
/* @0x1fb078 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1fb07c vldr s14, [r5, #156] */
/* @0x1fb080 vldr s15, [r0, #40] */
/* @0x1fb084 vcvt.f32.s32 s15, s15 */
/* @0x1fb088 vmul.f32 s15, s15, s14 */
/* @0x1fb08c vcvt.f64.f32 d6, s15 */
/* @0x1fb090 vmov r0, r1, d6 */
/* @0x1fb094 vmov r2, s12 */
/* @0x1fb098 mov r3, r1 */
/* @0x1fb09c stm r4, {r2, r3} */
/* @0x1fb0a0 mov r0, #1 */
/* @0x1fb0a4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1fb0a8 · GV_InstanceId(CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1fb0a8 cmp r1, #0 */
/* @0x1fb0ac mov r0, #0 */
/* @0x1fb0b0 mov r3, r0 */
/* @0x1fb0b4 movt r0, #0xc010 */
/* @0x1fb0b8 str r3, [r2, #0xc] */
/* @0x1fb0bc str r0, [r2, #0x4] */
/* @0x1fb0c0 str r3, [r2] */
/* @0x1fb0c4 blt 0x1fb118 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x70> */
/* @0x1fb0c8 ldr r3, [pc, #0x74] */
/* @0x1fb0cc ldr r3, [pc, r3] */
/* @0x1fb0d0 ldr r3, [r3] */
/* @0x1fb0d4 ldr r0, [r3, #0x88] */
/* @0x1fb0d8 cmp r1, r0 */
/* @0x1fb0dc bge 0x1fb118 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x70> */
/* @0x1fb0e0 ldr r0, [r3, #0x80] */
/* @0x1fb0e4 cmp r0, #0 */
/* @0x1fb0e8 beq 0x1fb118 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x70> */
/* @0x1fb0ec cmp r1, #0 */
/* @0x1fb0f0 ldr r3, [r0, #0x178] */
/* @0x1fb0f4 bne 0x1fb10c <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x64> */
/* @0x1fb0f8 b 0x1fb120 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x78> */
/* @0x1fb0fc cmp r1, #0 */
/* @0x1fb100 ldr r0, [r3, #0x178] */
/* @0x1fb104 beq 0x1fb124 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x7c> */
/* @0x1fb108 mov r3, r0 */
/* @0x1fb10c cmp r3, #0 */
/* @0x1fb110 sub r1, r1, #1 */
/* @0x1fb114 bne 0x1fb0fc <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x54> */
/* @0x1fb118 mov r0, #1 */
/* @0x1fb11c bx lr */
/* @0x1fb120 mov r3, r0 */
/* @0x1fb124 ldr r0, [r3, #0x78] */
/* @0x1fb128 vmov s15, r0 */
/* @0x1fb12c vcvt.f64.s32 d7, s15 */
/* @0x1fb130 vmov r0, r1, d7 */
/* @0x1fb134 mov r3, r1 */
/* @0x1fb138 stm r2, {r0, r3} */
/* @0x1fb13c mov r0, #1 */
/* @0x1fb140 bx lr */
/* @0x1fb144 andseq r2, pc, r12, asr r8 */

/* ── FUNC 0x1fb148 · SV_Depth(CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0x1fb148 ldr r3, [r2, #0xc] */
/* @0x1fb14c push {r4, r5, r6, lr} */
/* @0x1fb150 vpush {d8} */
/* @0x1fb154 bic r3, r3, #-16777216 */
/* @0x1fb158 vldr s16, [r0, #384] */
/* @0x1fb15c cmp r3, #0 */
/* @0x1fb160 sub sp, sp, #8 */
/* @0x1fb164 mov r4, r0 */
/* @0x1fb168 bne 0x1fb21c <_Z8SV_DepthP9CInstanceiP6RValue+0xd4> */
/* @0x1fb16c ldm r2, {r0, r1} */
/* @0x1fb170 vmov d6, r0, r1 */
/* @0x1fb174 vcvt.f32.f64 s15, d6 */
/* @0x1fb178 vcmp.f32 s16, s15 */
/* @0x1fb17c vmrs APSR_nzcv, fpscr */
/* @0x1fb180 bne 0x1fb194 <_Z8SV_DepthP9CInstanceiP6RValue+0x4c> */
/* @0x1fb184 mov r0, #1 */
/* @0x1fb188 add sp, sp, #8 */
/* @0x1fb18c vpop {d8} */
/* @0x1fb190 pop {r4, r5, r6, pc} */
/* @0x1fb194 ldr r3, [pc, #0xc4] */
/* @0x1fb198 mov r1, r4 */
/* @0x1fb19c ldr r5, [pc, #0xc0] */
/* @0x1fb1a0 vstr s15, [r4, #384] */
/* @0x1fb1a4 ldr r3, [pc, r3] */
/* @0x1fb1a8 ldr r0, [r3] */
/* @0x1fb1ac bl 0x1c5f40 <_ZN13CLayerManager19ChangeInstanceDepthEP5CRoomP9CInstance> */
/* @0x1fb1b0 ldr r5, [pc, r5] */
/* @0x1fb1b4 ldr r1, [r5, #0x8] */
/* @0x1fb1b8 ldr r3, [r5, #0x4] */
/* @0x1fb1bc cmp r1, r3 */
/* @0x1fb1c0 beq 0x1fb228 <_Z8SV_DepthP9CInstanceiP6RValue+0xe0> */
/* @0x1fb1c4 ldr r6, [r5] */
/* @0x1fb1c8 cmp r1, #0 */
/* @0x1fb1cc ble 0x1fb200 <_Z8SV_DepthP9CInstanceiP6RValue+0xb8> */
/* @0x1fb1d0 ldr r3, [r6] */
/* @0x1fb1d4 cmp r4, r3 */
/* @0x1fb1d8 beq 0x1fb184 <_Z8SV_DepthP9CInstanceiP6RValue+0x3c> */
/* @0x1fb1dc mov r2, r6 */
/* @0x1fb1e0 mov r3, #0 */
/* @0x1fb1e4 b 0x1fb1f4 <_Z8SV_DepthP9CInstanceiP6RValue+0xac> */
/* @0x1fb1e8 ldr r12, [r2, #0x4]! */
/* @0x1fb1ec cmp r4, r12 */
/* @0x1fb1f0 beq 0x1fb184 <_Z8SV_DepthP9CInstanceiP6RValue+0x3c> */
/* @0x1fb1f4 add r3, r3, #1 */
/* @0x1fb1f8 cmp r3, r1 */
/* @0x1fb1fc bne 0x1fb1e8 <_Z8SV_DepthP9CInstanceiP6RValue+0xa0> */
/* @0x1fb200 str r4, [r6, r1, lsl #2] */
/* @0x1fb204 mov r0, #1 */
/* @0x1fb208 add r1, r1, #1 */
/* @0x1fb20c str r1, [r5, #0x8] */
/* @0x1fb210 add sp, sp, #8 */
/* @0x1fb214 vpop {d8} */
/* @0x1fb218 pop {r4, r5, r6, pc} */
/* @0x1fb21c mov r0, r2 */
/* @0x1fb220 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb224 b 0x1fb170 <_Z8SV_DepthP9CInstanceiP6RValue+0x28> */
/* @0x1fb228 ldr r2, [pc, #0x38] */
/* @0x1fb22c lsl r3, r1, #1 */
/* @0x1fb230 ldr r0, [r5] */
/* @0x1fb234 lsl r1, r1, #3 */
/* @0x1fb238 str r3, [r5, #0x4] */
/* @0x1fb23c add r2, pc, r2 */
/* @0x1fb240 mov r3, #0 */
/* @0x1fb244 str r3, [sp] */
/* @0x1fb248 mov r3, #74 */
/* @0x1fb24c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1fb250 ldr r1, [r5, #0x8] */
/* @0x1fb254 mov r6, r0 */
/* @0x1fb258 str r0, [r5] */
/* @0x1fb25c b 0x1fb1c8 <_Z8SV_DepthP9CInstanceiP6RValue+0x80> */
/* @0x1fb260 andseq r2, pc, r4, lsl #15 */
/* @0x1fb264 ldrsheq r2, [pc], -r4 */
/* @0x1fb268 ldrsheq r5, [r3], -r4 */

/* ── FUNC 0x1fb26c · SV_Score(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1fb26c push {r3, lr} */
/* @0x1fb270 ldr r3, [r2, #0xc] */
/* @0x1fb274 bic r3, r3, #-16777216 */
/* @0x1fb278 cmp r3, #0 */
/* @0x1fb27c bne 0x1fb2a8 <_Z8SV_ScoreP9CInstanceiP6RValue+0x3c> */
/* @0x1fb280 ldr r12, [r2] */
/* @0x1fb284 ldr r3, [r2, #0x4] */
/* @0x1fb288 mov r1, r3 */
/* @0x1fb28c mov r0, r12 */
/* @0x1fb290 bl 0xb66e8 <lrint@plt> */
/* @0x1fb294 ldr r3, [pc, #0x20] */
/* @0x1fb298 ldr r3, [pc, r3] */
/* @0x1fb29c str r0, [r3] */
/* @0x1fb2a0 mov r0, #1 */
/* @0x1fb2a4 pop {r3, pc} */
/* @0x1fb2a8 mov r0, r2 */
/* @0x1fb2ac bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fb2b0 mov r12, r0 */
/* @0x1fb2b4 mov r3, r1 */
/* @0x1fb2b8 b 0x1fb288 <_Z8SV_ScoreP9CInstanceiP6RValue+0x1c> */
/* @0x1fb2bc andseq r3, pc, r12, ror #15 */
