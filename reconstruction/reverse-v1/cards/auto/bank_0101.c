/* libyoyo.so 覆盖卡组 0101
 * 函数 0x163800..0x165210，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x163800 · GR_3D_Transform_Set_Rotation_Y(float) · size=44 · insn=11 */
/* @0x163800 push {r4, lr} */
/* @0x163804 sub sp, sp, #64 */
/* @0x163808 mov r1, r0 */
/* @0x16380c mov r0, sp */
/* @0x163810 bl 0x27af60 <_ZN8yyMatrix12SetYRotationEPS_f> */
/* @0x163814 mov r1, sp */
/* @0x163818 mov r0, #2 */
/* @0x16381c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163820 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163824 add sp, sp, #64 */
/* @0x163828 pop {r4, pc} */

/* ── FUNC 0x16382c · GR_3D_Transform_Set_Rotation_Z(float) · size=44 · insn=11 */
/* @0x16382c push {r4, lr} */
/* @0x163830 sub sp, sp, #64 */
/* @0x163834 mov r1, r0 */
/* @0x163838 mov r0, sp */
/* @0x16383c bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f> */
/* @0x163840 mov r1, sp */
/* @0x163844 mov r0, #2 */
/* @0x163848 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x16384c bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163850 add sp, sp, #64 */
/* @0x163854 pop {r4, pc} */

/* ── FUNC 0x163858 · GR_3D_Transform_Set_Rotation_Axis(float, float, float, float) · size=64 · insn=16 */
/* @0x163858 push {r4, lr} */
/* @0x16385c sub sp, sp, #80 */
/* @0x163860 add r4, sp, #16 */
/* @0x163864 str r0, [sp, #0x4] */
/* @0x163868 str r1, [sp, #0x8] */
/* @0x16386c mov r0, r4 */
/* @0x163870 add r1, sp, #4 */
/* @0x163874 str r2, [sp, #0xc] */
/* @0x163878 eor r2, r3, #-2147483648 */
/* @0x16387c bl 0x27a8b8 <_ZN8yyMatrix18CreateRotationAxisEPS_P9yyVector3f> */
/* @0x163880 mov r1, r4 */
/* @0x163884 mov r0, #2 */
/* @0x163888 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x16388c bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163890 add sp, sp, #80 */
/* @0x163894 pop {r4, pc} */

/* ── FUNC 0x163898 · GR_3D_Transform_Add_Translation(float, float, float) · size=140 · insn=35 */
/* @0x163898 push {r4, lr} */
/* @0x16389c sub sp, sp, #192 */
/* @0x1638a0 add r4, sp, #64 */
/* @0x1638a4 mov r3, #0 */
/* @0x1638a8 str r0, [sp, #0x30] */
/* @0x1638ac mov r0, #2 */
/* @0x1638b0 str r1, [sp, #0x34] */
/* @0x1638b4 mov r1, r4 */
/* @0x1638b8 mov r12, #1065353216 */
/* @0x1638bc str r3, [sp, #0x2c] */
/* @0x1638c0 str r3, [sp, #0x24] */
/* @0x1638c4 str r3, [sp, #0x20] */
/* @0x1638c8 str r3, [sp, #0x1c] */
/* @0x1638cc str r3, [sp, #0x18] */
/* @0x1638d0 str r3, [sp, #0x10] */
/* @0x1638d4 str r12, [sp, #0x3c] */
/* @0x1638d8 str r12, [sp, #0x28] */
/* @0x1638dc str r12, [sp, #0x14] */
/* @0x1638e0 str r12, [sp] */
/* @0x1638e4 str r3, [sp, #0xc] */
/* @0x1638e8 str r3, [sp, #0x8] */
/* @0x1638ec str r3, [sp, #0x4] */
/* @0x1638f0 str r2, [sp, #0x38] */
/* @0x1638f4 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1638f8 mov r1, r4 */
/* @0x1638fc add r4, sp, #128 */
/* @0x163900 mov r2, sp */
/* @0x163904 mov r0, r4 */
/* @0x163908 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x16390c mov r1, r4 */
/* @0x163910 mov r0, #2 */
/* @0x163914 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163918 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x16391c add sp, sp, #192 */
/* @0x163920 pop {r4, pc} */

/* ── FUNC 0x163924 · GR_3D_Transform_Add_Scaling(float, float, float) · size=136 · insn=34 */
/* @0x163924 push {r4, lr} */
/* @0x163928 sub sp, sp, #192 */
/* @0x16392c add r4, sp, #128 */
/* @0x163930 mov r3, #0 */
/* @0x163934 str r0, [sp, #0x40] */
/* @0x163938 mov r0, #2 */
/* @0x16393c str r1, [sp, #0x54] */
/* @0x163940 mov r1, sp */
/* @0x163944 mov r12, #1065353216 */
/* @0x163948 str r3, [sp, #0x78] */
/* @0x16394c str r3, [sp, #0x74] */
/* @0x163950 str r3, [sp, #0x70] */
/* @0x163954 str r3, [sp, #0x6c] */
/* @0x163958 str r3, [sp, #0x64] */
/* @0x16395c str r3, [sp, #0x60] */
/* @0x163960 str r12, [sp, #0x7c] */
/* @0x163964 str r3, [sp, #0x5c] */
/* @0x163968 str r3, [sp, #0x58] */
/* @0x16396c str r3, [sp, #0x50] */
/* @0x163970 str r3, [sp, #0x4c] */
/* @0x163974 str r3, [sp, #0x48] */
/* @0x163978 str r3, [sp, #0x44] */
/* @0x16397c str r2, [sp, #0x68] */
/* @0x163980 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x163984 add r2, sp, #64 */
/* @0x163988 mov r1, sp */
/* @0x16398c mov r0, r4 */
/* @0x163990 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x163994 mov r1, r4 */
/* @0x163998 mov r0, #2 */
/* @0x16399c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1639a0 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1639a4 add sp, sp, #192 */
/* @0x1639a8 pop {r4, pc} */

/* ── FUNC 0x1639ac · GR_3D_Transform_Add_Rotation_X(float) · size=80 · insn=20 */
/* @0x1639ac push {r4, r5, lr} */
/* @0x1639b0 sub sp, sp, #196 */
/* @0x1639b4 add r4, sp, #64 */
/* @0x1639b8 mov r1, r0 */
/* @0x1639bc mov r0, r4 */
/* @0x1639c0 bl 0x27afe4 <_ZN8yyMatrix12SetXRotationEPS_f> */
/* @0x1639c4 mov r1, sp */
/* @0x1639c8 mov r0, #2 */
/* @0x1639cc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1639d0 mov r2, r4 */
/* @0x1639d4 add r4, sp, #128 */
/* @0x1639d8 mov r1, sp */
/* @0x1639dc mov r0, r4 */
/* @0x1639e0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1639e4 mov r1, r4 */
/* @0x1639e8 mov r0, #2 */
/* @0x1639ec bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1639f0 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1639f4 add sp, sp, #196 */
/* @0x1639f8 pop {r4, r5, pc} */

/* ── FUNC 0x1639fc · GR_3D_Transform_Add_Rotation_Y(float) · size=80 · insn=20 */
/* @0x1639fc push {r4, r5, lr} */
/* @0x163a00 sub sp, sp, #196 */
/* @0x163a04 add r4, sp, #64 */
/* @0x163a08 mov r1, r0 */
/* @0x163a0c mov r0, r4 */
/* @0x163a10 bl 0x27af60 <_ZN8yyMatrix12SetYRotationEPS_f> */
/* @0x163a14 mov r1, sp */
/* @0x163a18 mov r0, #2 */
/* @0x163a1c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x163a20 mov r2, r4 */
/* @0x163a24 add r4, sp, #128 */
/* @0x163a28 mov r1, sp */
/* @0x163a2c mov r0, r4 */
/* @0x163a30 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x163a34 mov r1, r4 */
/* @0x163a38 mov r0, #2 */
/* @0x163a3c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163a40 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163a44 add sp, sp, #196 */
/* @0x163a48 pop {r4, r5, pc} */

/* ── FUNC 0x163a4c · GR_3D_Transform_Add_Rotation_Z(float) · size=80 · insn=20 */
/* @0x163a4c push {r4, r5, lr} */
/* @0x163a50 sub sp, sp, #196 */
/* @0x163a54 add r4, sp, #64 */
/* @0x163a58 mov r1, r0 */
/* @0x163a5c mov r0, r4 */
/* @0x163a60 bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f> */
/* @0x163a64 mov r1, sp */
/* @0x163a68 mov r0, #2 */
/* @0x163a6c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x163a70 mov r2, r4 */
/* @0x163a74 add r4, sp, #128 */
/* @0x163a78 mov r1, sp */
/* @0x163a7c mov r0, r4 */
/* @0x163a80 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x163a84 mov r1, r4 */
/* @0x163a88 mov r0, #2 */
/* @0x163a8c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163a90 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163a94 add sp, sp, #196 */
/* @0x163a98 pop {r4, r5, pc} */

/* ── FUNC 0x163a9c · GR_3D_Transform_Add_Rotation_Axis(float, float, float, float) · size=100 · insn=25 */
/* @0x163a9c push {r4, r5, lr} */
/* @0x163aa0 sub sp, sp, #212 */
/* @0x163aa4 add r4, sp, #80 */
/* @0x163aa8 add r5, sp, #16 */
/* @0x163aac str r0, [sp, #0x4] */
/* @0x163ab0 str r1, [sp, #0x8] */
/* @0x163ab4 mov r0, r4 */
/* @0x163ab8 str r2, [sp, #0xc] */
/* @0x163abc add r1, sp, #4 */
/* @0x163ac0 eor r2, r3, #-2147483648 */
/* @0x163ac4 bl 0x27a8b8 <_ZN8yyMatrix18CreateRotationAxisEPS_P9yyVector3f> */
/* @0x163ac8 mov r1, r5 */
/* @0x163acc mov r0, #2 */
/* @0x163ad0 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x163ad4 mov r2, r4 */
/* @0x163ad8 add r4, sp, #144 */
/* @0x163adc mov r1, r5 */
/* @0x163ae0 mov r0, r4 */
/* @0x163ae4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x163ae8 mov r1, r4 */
/* @0x163aec mov r0, #2 */
/* @0x163af0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163af4 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163af8 add sp, sp, #212 */
/* @0x163afc pop {r4, r5, pc} */

/* ── FUNC 0x163b00 · GR_3D_Transform_Stack_Clear() · size=24 · insn=6 */
/* @0x163b00 ldr r3, [pc, #0xc] */
/* @0x163b04 mvn r2, #0 */
/* @0x163b08 ldr r3, [pc, r3] */
/* @0x163b0c str r2, [r3] */
/* @0x163b10 bx lr */
/* @0x163b14 .word 0x0028c5dc */

/* ── FUNC 0x163b18 · GR_3D_Transform_Stack_Empty() · size=24 · insn=6 */
/* @0x163b18 ldr r3, [pc, #0xc] */
/* @0x163b1c ldr r3, [pc, r3] */
/* @0x163b20 ldr r0, [r3] */
/* @0x163b24 lsr r0, r0, #31 */
/* @0x163b28 bx lr */
/* @0x163b2c eoreq r12, r8, r8, asr #11 */

/* ── FUNC 0x163b30 · GR_3D_Transform_Stack_Push() · size=76 · insn=19 */
/* @0x163b30 push {r3, lr} */
/* @0x163b34 ldr r3, [pc, #0x38] */
/* @0x163b38 ldr r3, [pc, r3] */
/* @0x163b3c ldr r2, [r3] */
/* @0x163b40 cmp r2, #49 */
/* @0x163b44 ble 0x163b50 <_Z26GR_3D_Transform_Stack_Pushv+0x20> */
/* @0x163b48 mov r0, #0 */
/* @0x163b4c pop {r3, pc} */
/* @0x163b50 ldr r1, [pc, #0x20] */
/* @0x163b54 add r2, r2, #1 */
/* @0x163b58 mov r0, #2 */
/* @0x163b5c str r2, [r3] */
/* @0x163b60 ldr r1, [pc, r1] */
/* @0x163b64 add r1, r1, r2, lsl #6 */
/* @0x163b68 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x163b6c mov r0, #1 */
/* @0x163b70 pop {r3, pc} */
/* @0x163b74 eoreq r12, r8, r12, lsr #11 */
/* @0x163b78 eoreq r12, r8, r8, lsl #11 */

/* ── FUNC 0x163b7c · GR_3D_Transform_Stack_Pop() · size=84 · insn=21 */
/* @0x163b7c push {r4, lr} */
/* @0x163b80 ldr r4, [pc, #0x40] */
/* @0x163b84 ldr r4, [pc, r4] */
/* @0x163b88 ldr r3, [r4] */
/* @0x163b8c cmp r3, #0 */
/* @0x163b90 blt 0x163bc0 <_Z25GR_3D_Transform_Stack_Popv+0x44> */
/* @0x163b94 ldr r1, [pc, #0x30] */
/* @0x163b98 mov r0, #2 */
/* @0x163b9c ldr r1, [pc, r1] */
/* @0x163ba0 add r1, r1, r3, lsl #6 */
/* @0x163ba4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163ba8 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x163bac ldr r3, [r4] */
/* @0x163bb0 mov r0, #1 */
/* @0x163bb4 sub r3, r3, #1 */
/* @0x163bb8 str r3, [r4] */
/* @0x163bbc pop {r4, pc} */
/* @0x163bc0 mov r0, #0 */
/* @0x163bc4 pop {r4, pc} */
/* @0x163bc8 eoreq r12, r8, r0, ror #10 */
/* @0x163bcc eoreq r12, r8, r12, asr #10 */

/* ── FUNC 0x163bd0 · GR_3D_Transform_Stack_Top() · size=68 · insn=17 */
/* @0x163bd0 push {r3, lr} */
/* @0x163bd4 ldr r3, [pc, #0x30] */
/* @0x163bd8 ldr r3, [pc, r3] */
/* @0x163bdc ldr r3, [r3] */
/* @0x163be0 cmp r3, #0 */
/* @0x163be4 blt 0x163c04 <_Z25GR_3D_Transform_Stack_Topv+0x34> */
/* @0x163be8 ldr r1, [pc, #0x20] */
/* @0x163bec mov r0, #2 */
/* @0x163bf0 ldr r1, [pc, r1] */
/* @0x163bf4 add r1, r1, r3, lsl #6 */
/* @0x163bf8 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x163bfc mov r0, #1 */
/* @0x163c00 pop {r3, pc} */
/* @0x163c04 mov r0, #0 */
/* @0x163c08 pop {r3, pc} */
/* @0x163c0c eoreq r12, r8, r12, lsl #10 */
/* @0x163c10 .word 0x0028c4f8 */

/* ── FUNC 0x163c14 · GR_3D_Transform_Stack_Discard() · size=40 · insn=10 */
/* @0x163c14 ldr r3, [pc, #0x1c] */
/* @0x163c18 ldr r3, [pc, r3] */
/* @0x163c1c ldr r2, [r3] */
/* @0x163c20 cmp r2, #0 */
/* @0x163c24 subge r2, r2, #1 */
/* @0x163c28 strge r2, [r3] */
/* @0x163c2c movge r0, #1 */
/* @0x163c30 movlt r0, #0 */
/* @0x163c34 bx lr */
/* @0x163c38 eoreq r12, r8, r12, asr #9 */

/* ── FUNC 0x163c3c · GR_3D_TransformVertex(float&, float&, float&) · size=160 · insn=40 */
/* @0x163c3c push {r4, r5, r6, lr} */
/* @0x163c40 sub sp, sp, #64 */
/* @0x163c44 mov r5, r0 */
/* @0x163c48 mov r4, r1 */
/* @0x163c4c mov r0, #2 */
/* @0x163c50 mov r1, sp */
/* @0x163c54 mov r6, r2 */
/* @0x163c58 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x163c5c vldr s10, [r4] */
/* @0x163c60 vldr s13, [sp, #16] */
/* @0x163c64 vldr s14, [sp, #20] */
/* @0x163c68 vldr s15, [sp, #24] */
/* @0x163c6c vmul.f32 s13, s10, s13 */
/* @0x163c70 vldr s11, [r5] */
/* @0x163c74 vldr s1, [sp] */
/* @0x163c78 vldr s2, [sp, #4] */
/* @0x163c7c vldr s3, [sp, #8] */
/* @0x163c80 vldr s12, [r6] */
/* @0x163c84 vldr s4, [sp, #32] */
/* @0x163c88 vldr s5, [sp, #36] */
/* @0x163c8c vldr s6, [sp, #40] */
/* @0x163c90 vldr s7, [sp, #48] */
/* @0x163c94 vldr s8, [sp, #52] */
/* @0x163c98 vldr s9, [sp, #56] */
/* @0x163c9c vmul.f32 s14, s10, s14 */
/* @0x163ca0 vmul.f32 s15, s10, s15 */
/* @0x163ca4 vmla.f32 s13, s11, s1 */
/* @0x163ca8 vmla.f32 s14, s11, s2 */
/* @0x163cac vmla.f32 s15, s11, s3 */
/* @0x163cb0 vmla.f32 s13, s12, s4 */
/* @0x163cb4 vmla.f32 s14, s12, s5 */
/* @0x163cb8 vmla.f32 s15, s12, s6 */
/* @0x163cbc vadd.f32 s13, s13, s7 */
/* @0x163cc0 vadd.f32 s14, s14, s8 */
/* @0x163cc4 vstr s13, [r5] */
/* @0x163cc8 vadd.f32 s15, s15, s9 */
/* @0x163ccc vstr s14, [r4] */
/* @0x163cd0 vstr s15, [r6] */
/* @0x163cd4 add sp, sp, #64 */
/* @0x163cd8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x163cdc · GM_GetMatrix(eMatrix) · size=4 · insn=1 */
/* @0x163cdc bx lr */

/* ── FUNC 0x163ce0 · C3D_Model::Clear() · size=164 · insn=41 */
/* @0x163ce0 ldr r3, [r0, #0x8] */
/* @0x163ce4 push {r4, r5, r6, lr} */
/* @0x163ce8 cmp r3, #0 */
/* @0x163cec mov r6, r0 */
/* @0x163cf0 beq 0x163d3c <_ZN9C3D_Model5ClearEv+0x5c> */
/* @0x163cf4 ldr r2, [r0] */
/* @0x163cf8 cmp r2, #0 */
/* @0x163cfc ble 0x163d28 <_ZN9C3D_Model5ClearEv+0x48> */
/* @0x163d00 mov r4, #0 */
/* @0x163d04 ldr r0, [r3, r4, lsl #2] */
/* @0x163d08 add r4, r4, #1 */
/* @0x163d0c cmp r0, #0 */
/* @0x163d10 beq 0x163d20 <_ZN9C3D_Model5ClearEv+0x40> */
/* @0x163d14 bl 0x27d1d0 <_ZdlPv> */
/* @0x163d18 ldr r3, [r6, #0x8] */
/* @0x163d1c ldr r2, [r6] */
/* @0x163d20 cmp r2, r4 */
/* @0x163d24 bgt 0x163d04 <_ZN9C3D_Model5ClearEv+0x24> */
/* @0x163d28 mov r0, r3 */
/* @0x163d2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x163d30 mov r3, #0 */
/* @0x163d34 str r3, [r6, #0x8] */
/* @0x163d38 str r3, [r6, #0x4] */
/* @0x163d3c ldr r4, [r6, #0xc] */
/* @0x163d40 mov r3, #0 */
/* @0x163d44 str r3, [r6] */
/* @0x163d48 cmp r4, r3 */
/* @0x163d4c beq 0x163d70 <_ZN9C3D_Model5ClearEv+0x90> */
/* @0x163d50 ldr r5, [r4] */
/* @0x163d54 mov r0, r4 */
/* @0x163d58 bl 0x188ca4 <_ZN16GraphicsRecorderD2Ev> */
/* @0x163d5c mov r0, r4 */
/* @0x163d60 bl 0x27d1d0 <_ZdlPv> */
/* @0x163d64 cmp r5, #0 */
/* @0x163d68 mov r4, r5 */
/* @0x163d6c bne 0x163d50 <_ZN9C3D_Model5ClearEv+0x70> */
/* @0x163d70 mov r3, #0 */
/* @0x163d74 str r3, [r6, #0x14] */
/* @0x163d78 str r3, [r6, #0x10] */
/* @0x163d7c str r3, [r6, #0xc] */
/* @0x163d80 pop {r4, r5, r6, pc} */

/* ── FUNC 0x163d84 · C3D_Model::C3D_Model() · size=56 · insn=14 */
/* @0x163d84 push {r4, lr} */
/* @0x163d88 mov r3, #0 */
/* @0x163d8c mov r4, r0 */
/* @0x163d90 mov r2, #1 */
/* @0x163d94 str r3, [r0, #0x10] */
/* @0x163d98 str r2, [r0, #0x18] */
/* @0x163d9c str r3, [r0, #0xc] */
/* @0x163da0 str r3, [r0, #0x14] */
/* @0x163da4 str r3, [r0] */
/* @0x163da8 str r3, [r0, #0x8] */
/* @0x163dac str r3, [r0, #0x4] */
/* @0x163db0 bl 0x163ce0 <_ZN9C3D_Model5ClearEv> */
/* @0x163db4 mov r0, r4 */
/* @0x163db8 pop {r4, pc} */

/* ── FUNC 0x163d84 · C3D_Model::C3D_Model() · alias of the symbol above · insn=0 */

/* ── FUNC 0x163dbc · ReadLn(CStream*, char const*&) · size=320 · insn=80 */
/* @0x163dbc push {r4, r5, r6, r7, r8, lr} */
/* @0x163dc0 sub sp, sp, #8 */
/* @0x163dc4 add r8, sp, #8 */
/* @0x163dc8 mov r4, r0 */
/* @0x163dcc mov r7, r1 */
/* @0x163dd0 mov r3, #0 */
/* @0x163dd4 strb r3, [r8, #-0x1]! */
/* @0x163dd8 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x163ddc mov r1, r8 */
/* @0x163de0 mov r2, #1 */
/* @0x163de4 mov r6, r0 */
/* @0x163de8 mov r0, r4 */
/* @0x163dec bl 0x20172c <_ZN7CStream4ReadEPvi> */
/* @0x163df0 ldrb r3, [sp, #0x7] */
/* @0x163df4 mov r0, r4 */
/* @0x163df8 cmp r3, #13 */
/* @0x163dfc cmpne r3, #10 */
/* @0x163e00 beq 0x163ed8 <_Z6ReadLnP7CStreamRPKc+0x11c> */
/* @0x163e04 cmp r3, #0 */
/* @0x163e08 beq 0x163ed8 <_Z6ReadLnP7CStreamRPKc+0x11c> */
/* @0x163e0c mov r0, r4 */
/* @0x163e10 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x163e14 mov r5, r0 */
/* @0x163e18 mov r0, r4 */
/* @0x163e1c bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x163e20 mov r1, r8 */
/* @0x163e24 mov r2, #1 */
/* @0x163e28 cmp r5, r0 */
/* @0x163e2c mov r0, r4 */
/* @0x163e30 bge 0x163e50 <_Z6ReadLnP7CStreamRPKc+0x94> */
/* @0x163e34 bl 0x20172c <_ZN7CStream4ReadEPvi> */
/* @0x163e38 ldrb r3, [sp, #0x7] */
/* @0x163e3c cmp r3, #10 */
/* @0x163e40 cmpne r3, #13 */
/* @0x163e44 beq 0x163e50 <_Z6ReadLnP7CStreamRPKc+0x94> */
/* @0x163e48 cmp r3, #0 */
/* @0x163e4c bne 0x163e0c <_Z6ReadLnP7CStreamRPKc+0x50> */
/* @0x163e50 mov r0, r4 */
/* @0x163e54 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x163e58 rsb r0, r6, r0 */
/* @0x163e5c sub r5, r0, #1 */
/* @0x163e60 cmp r5, #0 */
/* @0x163e64 movle r3, #0 */
/* @0x163e68 strle r3, [r7] */
/* @0x163e6c ble 0x163ed0 <_Z6ReadLnP7CStreamRPKc+0x114> */
/* @0x163e70 ldr r1, [pc, #0x80] */
/* @0x163e74 mov r2, #108 */
/* @0x163e78 mov r3, #1 */
/* @0x163e7c add r1, pc, r1 */
/* @0x163e80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x163e84 mov r1, r6 */
/* @0x163e88 mov r8, r0 */
/* @0x163e8c mov r0, r4 */
/* @0x163e90 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x163e94 mov r0, r4 */
/* @0x163e98 mov r1, r8 */
/* @0x163e9c mov r2, r5 */
/* @0x163ea0 bl 0x20172c <_ZN7CStream4ReadEPvi> */
/* @0x163ea4 ldr r0, [r7] */
/* @0x163ea8 cmp r0, #0 */
/* @0x163eac beq 0x163eb4 <_Z6ReadLnP7CStreamRPKc+0xf8> */
/* @0x163eb0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x163eb4 mov r0, r8 */
/* @0x163eb8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x163ebc cmp r8, #0 */
/* @0x163ec0 str r0, [r7] */
/* @0x163ec4 beq 0x163ed0 <_Z6ReadLnP7CStreamRPKc+0x114> */
/* @0x163ec8 mov r0, r8 */
/* @0x163ecc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x163ed0 add sp, sp, #8 */
/* @0x163ed4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x163ed8 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x163edc mov r5, r0 */
/* @0x163ee0 mov r0, r4 */
/* @0x163ee4 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x163ee8 cmp r5, r0 */
/* @0x163eec mov r0, r4 */
/* @0x163ef0 blt 0x163dd8 <_Z6ReadLnP7CStreamRPKc+0x1c> */
/* @0x163ef4 b 0x163e38 <_Z6ReadLnP7CStreamRPKc+0x7c> */
/* @0x163ef8 mulseq lr, r8, r6 */

/* ── FUNC 0x163efc · C3D_Model::LoadFromFile(char const*) · size=756 · insn=189 */
/* @0x163efc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x163f00 sub sp, sp, #124 */
/* @0x163f04 mov r7, r1 */
/* @0x163f08 mov r6, #0 */
/* @0x163f0c mov r5, r0 */
/* @0x163f10 str r6, [sp, #0x48] */
/* @0x163f14 bl 0x163ce0 <_ZN9C3D_Model5ClearEv> */
/* @0x163f18 mov r0, #32 */
/* @0x163f1c bl 0x27c524 <_Znwj> */
/* @0x163f20 mov r1, r6 */
/* @0x163f24 mov r4, r0 */
/* @0x163f28 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x163f2c mov r1, r7 */
/* @0x163f30 mov r0, r4 */
/* @0x163f34 mov r2, r6 */
/* @0x163f38 bl 0x201358 <_ZN7CStream12LoadFromFileEPKci> */
/* @0x163f3c mov r0, r4 */
/* @0x163f40 bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x163f44 subs r7, r0, #0 */
/* @0x163f48 beq 0x164190 <_ZN9C3D_Model12LoadFromFileEPKc+0x294> */
/* @0x163f4c add r7, sp, #72 */
/* @0x163f50 mov r0, r4 */
/* @0x163f54 mov r1, r7 */
/* @0x163f58 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc> */
/* @0x163f5c ldr r1, [pc, #0x280] */
/* @0x163f60 ldr r0, [sp, #0x48] */
/* @0x163f64 add r1, pc, r1 */
/* @0x163f68 bl 0xb6574 <strcmp@plt> */
/* @0x163f6c cmp r0, #0 */
/* @0x163f70 beq 0x163f98 <_ZN9C3D_Model12LoadFromFileEPKc+0x9c> */
/* @0x163f74 cmp r4, #0 */
/* @0x163f78 beq 0x1641b4 <_ZN9C3D_Model12LoadFromFileEPKc+0x2b8> */
/* @0x163f7c mov r0, r4 */
/* @0x163f80 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x163f84 mov r0, r4 */
/* @0x163f88 bl 0x27d1d0 <_ZdlPv> */
/* @0x163f8c mov r0, r6 */
/* @0x163f90 add sp, sp, #124 */
/* @0x163f94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x163f98 mov r0, r4 */
/* @0x163f9c mov r1, r7 */
/* @0x163fa0 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc> */
/* @0x163fa4 ldr r0, [sp, #0x48] */
/* @0x163fa8 cmp r0, #0 */
/* @0x163fac ldreq r0, [r5] */
/* @0x163fb0 beq 0x163fbc <_ZN9C3D_Model12LoadFromFileEPKc+0xc0> */
/* @0x163fb4 bl 0xb66b8 <atoi@plt> */
/* @0x163fb8 str r0, [r5] */
/* @0x163fbc cmp r0, #0 */
/* @0x163fc0 ble 0x16416c <_ZN9C3D_Model12LoadFromFileEPKc+0x270> */
/* @0x163fc4 ldr r2, [pc, #0x21c] */
/* @0x163fc8 lsl r1, r0, #2 */
/* @0x163fcc mov r3, #162 */
/* @0x163fd0 add r0, r5, #8 */
/* @0x163fd4 add r2, pc, r2 */
/* @0x163fd8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x163fdc ldr r3, [r5] */
/* @0x163fe0 cmp r3, #0 */
/* @0x163fe4 str r3, [r5, #0x4] */
/* @0x163fe8 ble 0x16416c <_ZN9C3D_Model12LoadFromFileEPKc+0x270> */
/* @0x163fec ldr r11, [pc, #0x1f8] */
/* @0x163ff0 add r10, sp, #76 */
/* @0x163ff4 add r9, sp, #80 */
/* @0x163ff8 add r8, sp, #84 */
/* @0x163ffc add r11, pc, r11 */
/* @0x164000 mov r6, #0 */
/* @0x164004 add r12, sp, #88 */
/* @0x164008 str r12, [sp, #0x28] */
/* @0x16400c add r12, sp, #92 */
/* @0x164010 str r12, [sp, #0x2c] */
/* @0x164014 add r12, sp, #96 */
/* @0x164018 str r12, [sp, #0x30] */
/* @0x16401c add r12, sp, #100 */
/* @0x164020 str r12, [sp, #0x34] */
/* @0x164024 add r12, sp, #104 */
/* @0x164028 str r12, [sp, #0x38] */
/* @0x16402c add r12, sp, #108 */
/* @0x164030 str r12, [sp, #0x3c] */
/* @0x164034 add r12, sp, #112 */
/* @0x164038 str r12, [sp, #0x40] */
/* @0x16403c add r12, sp, #116 */
/* @0x164040 str r12, [sp, #0x44] */
/* @0x164044 mov r1, r10 */
/* @0x164048 mov r0, r4 */
/* @0x16404c mov r3, #0 */
/* @0x164050 str r3, [sp, #0x4c] */
/* @0x164054 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc> */
/* @0x164058 mov r0, #44 */
/* @0x16405c ldr r7, [r5, #0x8] */
/* @0x164060 bl 0x27c524 <_Znwj> */
/* @0x164064 mov r1, r11 */
/* @0x164068 mov r3, r9 */
/* @0x16406c add r12, sp, #88 */
/* @0x164070 str r0, [r7, r6, lsl #2] */
/* @0x164074 ldr r2, [r5, #0x8] */
/* @0x164078 ldr r0, [sp, #0x4c] */
/* @0x16407c ldr r2, [r2, r6, lsl #2] */
/* @0x164080 str r12, [sp, #0x4] */
/* @0x164084 add r12, sp, #92 */
/* @0x164088 str r8, [sp] */
/* @0x16408c str r12, [sp, #0x8] */
/* @0x164090 add r12, sp, #96 */
/* @0x164094 str r12, [sp, #0xc] */
/* @0x164098 add r12, sp, #100 */
/* @0x16409c str r12, [sp, #0x10] */
/* @0x1640a0 add r12, sp, #104 */
/* @0x1640a4 str r12, [sp, #0x14] */
/* @0x1640a8 add r12, sp, #108 */
/* @0x1640ac str r12, [sp, #0x18] */
/* @0x1640b0 add r12, sp, #112 */
/* @0x1640b4 str r12, [sp, #0x1c] */
/* @0x1640b8 add r12, sp, #116 */
/* @0x1640bc str r12, [sp, #0x20] */
/* @0x1640c0 bl 0xb68f8 <sscanf@plt> */
/* @0x1640c4 ldr r3, [r5, #0x8] */
/* @0x1640c8 ldr r2, [sp, #0x50] */
/* @0x1640cc ldr r3, [r3, r6, lsl #2] */
/* @0x1640d0 str r2, [r3, #0x4] */
/* @0x1640d4 ldr r2, [sp, #0x54] */
/* @0x1640d8 str r2, [r3, #0x8] */
/* @0x1640dc ldr r2, [sp, #0x58] */
/* @0x1640e0 str r2, [r3, #0xc] */
/* @0x1640e4 vldr s12, [sp, #92] */
/* @0x1640e8 vstr s12, [r3, #16] */
/* @0x1640ec ldr r2, [sp, #0x60] */
/* @0x1640f0 str r2, [r3, #0x14] */
/* @0x1640f4 vldr s13, [sp, #100] */
/* @0x1640f8 vstr s13, [r3, #24] */
/* @0x1640fc vldr s14, [sp, #104] */
/* @0x164100 vstr s14, [r3, #28] */
/* @0x164104 ldr r1, [sp, #0x6c] */
/* @0x164108 ldr r2, [r3] */
/* @0x16410c str r1, [r3, #0x20] */
/* @0x164110 sub r2, r2, #3 */
/* @0x164114 vldr s15, [sp, #112] */
/* @0x164118 vstr s15, [r3, #36] */
/* @0x16411c ldr r1, [sp, #0x74] */
/* @0x164120 str r1, [r3, #0x28] */
/* @0x164124 cmp r2, #6 */
/* @0x164128 addls pc, pc, r2, lsl #2 */
/* @0x16412c b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258> */
/* @0x164130 b 0x1641cc <_ZN9C3D_Model12LoadFromFileEPKc+0x2d0> */
/* @0x164134 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258> */
/* @0x164138 b 0x1641d8 <_ZN9C3D_Model12LoadFromFileEPKc+0x2dc> */
/* @0x16413c b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258> */
/* @0x164140 b 0x1641c0 <_ZN9C3D_Model12LoadFromFileEPKc+0x2c4> */
/* @0x164144 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258> */
/* @0x164148 b 0x16414c <_ZN9C3D_Model12LoadFromFileEPKc+0x250> */
/* @0x16414c vcvt.s32.f32 s15, s15 */
/* @0x164150 vstr s15, [r3, #36] */
/* @0x164154 ldr r0, [sp, #0x4c] */
/* @0x164158 add r6, r6, #1 */
/* @0x16415c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x164160 ldr r3, [r5] */
/* @0x164164 cmp r3, r6 */
/* @0x164168 bgt 0x164044 <_ZN9C3D_Model12LoadFromFileEPKc+0x148> */
/* @0x16416c cmp r4, #0 */
/* @0x164170 beq 0x164184 <_ZN9C3D_Model12LoadFromFileEPKc+0x288> */
/* @0x164174 mov r0, r4 */
/* @0x164178 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x16417c mov r0, r4 */
/* @0x164180 bl 0x27d1d0 <_ZdlPv> */
/* @0x164184 mov r0, #1 */
/* @0x164188 add sp, sp, #124 */
/* @0x16418c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x164190 cmp r4, r6 */
/* @0x164194 beq 0x1641b4 <_ZN9C3D_Model12LoadFromFileEPKc+0x2b8> */
/* @0x164198 mov r0, r4 */
/* @0x16419c bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1641a0 mov r0, r4 */
/* @0x1641a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1641a8 mov r0, r7 */
/* @0x1641ac add sp, sp, #124 */
/* @0x1641b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1641b4 mov r0, #0 */
/* @0x1641b8 add sp, sp, #124 */
/* @0x1641bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1641c0 vcvt.s32.f32 s14, s14 */
/* @0x1641c4 vstr s14, [r3, #28] */
/* @0x1641c8 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258> */
/* @0x1641cc vcvt.s32.f32 s12, s12 */
/* @0x1641d0 vstr s12, [r3, #16] */
/* @0x1641d4 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258> */
/* @0x1641d8 vcvt.s32.f32 s13, s13 */
/* @0x1641dc vstr s13, [r3, #24] */
/* @0x1641e0 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258> */
/* @0x1641e4 ldrsheq r6, [lr], -r0 */
/* @0x1641e8 andseq r6, lr, r0, asr #10 */
/* @0x1641ec andseq r6, lr, r12, asr r5 */

/* ── FUNC 0x1641f0 · C3D_Model::LoadFromBuffer(int) · size=776 · insn=194 */
/* @0x1641f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1641f4 sub sp, sp, #124 */
/* @0x1641f8 mov r7, r1 */
/* @0x1641fc mov r6, #0 */
/* @0x164200 mov r5, r0 */
/* @0x164204 str r6, [sp, #0x48] */
/* @0x164208 bl 0x163ce0 <_ZN9C3D_Model5ClearEv> */
/* @0x16420c mov r0, #32 */
/* @0x164210 bl 0x27c524 <_Znwj> */
/* @0x164214 mov r1, r6 */
/* @0x164218 mov r4, r0 */
/* @0x16421c bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x164220 mov r0, r7 */
/* @0x164224 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x164228 subs r7, r0, #0 */
/* @0x16422c beq 0x1642c4 <_ZN9C3D_Model14LoadFromBufferEi+0xd4> */
/* @0x164230 ldr r2, [r7, #0x20] */
/* @0x164234 mov r0, r4 */
/* @0x164238 ldr r1, [r7, #0x4] */
/* @0x16423c asr r3, r2, #31 */
/* @0x164240 bl 0x201170 <_ZN7CStream14LoadFromMemoryEPvx> */
/* @0x164244 mov r0, r4 */
/* @0x164248 bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x16424c subs r7, r0, #0 */
/* @0x164250 beq 0x1642a0 <_ZN9C3D_Model14LoadFromBufferEi+0xb0> */
/* @0x164254 add r7, sp, #72 */
/* @0x164258 mov r3, #1 */
/* @0x16425c mov r0, r4 */
/* @0x164260 strb r3, [r4] */
/* @0x164264 mov r1, r7 */
/* @0x164268 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc> */
/* @0x16426c ldr r1, [pc, #0x278] */
/* @0x164270 ldr r0, [sp, #0x48] */
/* @0x164274 add r1, pc, r1 */
/* @0x164278 bl 0xb6574 <strcmp@plt> */
/* @0x16427c cmp r0, #0 */
/* @0x164280 beq 0x1642d8 <_ZN9C3D_Model14LoadFromBufferEi+0xe8> */
/* @0x164284 mov r0, r4 */
/* @0x164288 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x16428c mov r0, r4 */
/* @0x164290 bl 0x27d1d0 <_ZdlPv> */
/* @0x164294 mov r0, r6 */
/* @0x164298 add sp, sp, #124 */
/* @0x16429c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1642a0 cmp r4, #0 */
/* @0x1642a4 beq 0x1642cc <_ZN9C3D_Model14LoadFromBufferEi+0xdc> */
/* @0x1642a8 mov r0, r4 */
/* @0x1642ac bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1642b0 mov r0, r4 */
/* @0x1642b4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1642b8 mov r0, r7 */
/* @0x1642bc add sp, sp, #124 */
/* @0x1642c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1642c4 cmp r4, r6 */
/* @0x1642c8 bne 0x1642a8 <_ZN9C3D_Model14LoadFromBufferEi+0xb8> */
/* @0x1642cc mov r0, #0 */
/* @0x1642d0 add sp, sp, #124 */
/* @0x1642d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1642d8 mov r0, r4 */
/* @0x1642dc mov r1, r7 */
/* @0x1642e0 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc> */
/* @0x1642e4 ldr r0, [sp, #0x48] */
/* @0x1642e8 cmp r0, #0 */
/* @0x1642ec ldreq r0, [r5] */
/* @0x1642f0 beq 0x1642fc <_ZN9C3D_Model14LoadFromBufferEi+0x10c> */
/* @0x1642f4 bl 0xb66b8 <atoi@plt> */
/* @0x1642f8 str r0, [r5] */
/* @0x1642fc cmp r0, #0 */
/* @0x164300 ble 0x1644ac <_ZN9C3D_Model14LoadFromBufferEi+0x2bc> */
/* @0x164304 ldr r2, [pc, #0x1e4] */
/* @0x164308 lsl r1, r0, #2 */
/* @0x16430c mov r3, #247 */
/* @0x164310 add r0, r5, #8 */
/* @0x164314 add r2, pc, r2 */
/* @0x164318 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x16431c ldr r3, [r5] */
/* @0x164320 cmp r3, #0 */
/* @0x164324 str r3, [r5, #0x4] */
/* @0x164328 ble 0x1644ac <_ZN9C3D_Model14LoadFromBufferEi+0x2bc> */
/* @0x16432c ldr r11, [pc, #0x1c0] */
/* @0x164330 add r10, sp, #76 */
/* @0x164334 add r9, sp, #80 */
/* @0x164338 add r8, sp, #84 */
/* @0x16433c add r11, pc, r11 */
/* @0x164340 mov r6, #0 */
/* @0x164344 add r12, sp, #88 */
/* @0x164348 str r12, [sp, #0x44] */
/* @0x16434c add r12, sp, #92 */
/* @0x164350 str r12, [sp, #0x28] */
/* @0x164354 add r12, sp, #96 */
/* @0x164358 str r12, [sp, #0x2c] */
/* @0x16435c add r12, sp, #100 */
/* @0x164360 str r12, [sp, #0x30] */
/* @0x164364 add r12, sp, #104 */
/* @0x164368 str r12, [sp, #0x34] */
/* @0x16436c add r12, sp, #108 */
/* @0x164370 str r12, [sp, #0x38] */
/* @0x164374 add r12, sp, #112 */
/* @0x164378 str r12, [sp, #0x3c] */
/* @0x16437c add r12, sp, #116 */
/* @0x164380 str r12, [sp, #0x40] */
/* @0x164384 mov r1, r10 */
/* @0x164388 mov r0, r4 */
/* @0x16438c mov r3, #0 */
/* @0x164390 str r3, [sp, #0x4c] */
/* @0x164394 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc> */
/* @0x164398 mov r0, #44 */
/* @0x16439c ldr r7, [r5, #0x8] */
/* @0x1643a0 bl 0x27c524 <_Znwj> */
/* @0x1643a4 mov r1, r11 */
/* @0x1643a8 mov r3, r9 */
/* @0x1643ac add r12, sp, #88 */
/* @0x1643b0 str r0, [r7, r6, lsl #2] */
/* @0x1643b4 ldr r2, [r5, #0x8] */
/* @0x1643b8 ldr r0, [sp, #0x4c] */
/* @0x1643bc ldr r2, [r2, r6, lsl #2] */
/* @0x1643c0 str r12, [sp, #0x4] */
/* @0x1643c4 add r12, sp, #92 */
/* @0x1643c8 str r8, [sp] */
/* @0x1643cc str r12, [sp, #0x8] */
/* @0x1643d0 add r12, sp, #96 */
/* @0x1643d4 str r12, [sp, #0xc] */
/* @0x1643d8 add r12, sp, #100 */
/* @0x1643dc str r12, [sp, #0x10] */
/* @0x1643e0 add r12, sp, #104 */
/* @0x1643e4 str r12, [sp, #0x14] */
/* @0x1643e8 add r12, sp, #108 */
/* @0x1643ec str r12, [sp, #0x18] */
/* @0x1643f0 add r12, sp, #112 */
/* @0x1643f4 str r12, [sp, #0x1c] */
/* @0x1643f8 add r12, sp, #116 */
/* @0x1643fc str r12, [sp, #0x20] */
/* @0x164400 bl 0xb68f8 <sscanf@plt> */
/* @0x164404 ldr r3, [r5, #0x8] */
/* @0x164408 ldr r2, [sp, #0x50] */
/* @0x16440c ldr r3, [r3, r6, lsl #2] */
/* @0x164410 str r2, [r3, #0x4] */
/* @0x164414 ldr r2, [sp, #0x54] */
/* @0x164418 str r2, [r3, #0x8] */
/* @0x16441c ldr r2, [sp, #0x58] */
/* @0x164420 str r2, [r3, #0xc] */
/* @0x164424 vldr s12, [sp, #92] */
/* @0x164428 vstr s12, [r3, #16] */
/* @0x16442c ldr r2, [sp, #0x60] */
/* @0x164430 str r2, [r3, #0x14] */
/* @0x164434 vldr s13, [sp, #100] */
/* @0x164438 vstr s13, [r3, #24] */
/* @0x16443c vldr s14, [sp, #104] */
/* @0x164440 vstr s14, [r3, #28] */
/* @0x164444 ldr r1, [sp, #0x6c] */
/* @0x164448 ldr r2, [r3] */
/* @0x16444c str r1, [r3, #0x20] */
/* @0x164450 sub r2, r2, #3 */
/* @0x164454 vldr s15, [sp, #112] */
/* @0x164458 vstr s15, [r3, #36] */
/* @0x16445c ldr r1, [sp, #0x74] */
/* @0x164460 str r1, [r3, #0x28] */
/* @0x164464 cmp r2, #6 */
/* @0x164468 addls pc, pc, r2, lsl #2 */
/* @0x16446c b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4> */
/* @0x164470 b 0x1644d4 <_ZN9C3D_Model14LoadFromBufferEi+0x2e4> */
/* @0x164474 b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4> */
/* @0x164478 b 0x1644c8 <_ZN9C3D_Model14LoadFromBufferEi+0x2d8> */
/* @0x16447c b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4> */
/* @0x164480 b 0x1644e0 <_ZN9C3D_Model14LoadFromBufferEi+0x2f0> */
/* @0x164484 b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4> */
/* @0x164488 b 0x16448c <_ZN9C3D_Model14LoadFromBufferEi+0x29c> */
/* @0x16448c vcvt.s32.f32 s15, s15 */
/* @0x164490 vstr s15, [r3, #36] */
/* @0x164494 ldr r0, [sp, #0x4c] */
/* @0x164498 add r6, r6, #1 */
/* @0x16449c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1644a0 ldr r3, [r5] */
/* @0x1644a4 cmp r3, r6 */
/* @0x1644a8 bgt 0x164384 <_ZN9C3D_Model14LoadFromBufferEi+0x194> */
/* @0x1644ac mov r0, r4 */
/* @0x1644b0 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1644b4 mov r0, r4 */
/* @0x1644b8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1644bc mov r0, #1 */
/* @0x1644c0 add sp, sp, #124 */
/* @0x1644c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1644c8 vcvt.s32.f32 s13, s13 */
/* @0x1644cc vstr s13, [r3, #24] */
/* @0x1644d0 b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4> */
/* @0x1644d4 vcvt.s32.f32 s12, s12 */
/* @0x1644d8 vstr s12, [r3, #16] */
/* @0x1644dc b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4> */
/* @0x1644e0 vcvt.s32.f32 s14, s14 */
/* @0x1644e4 vstr s14, [r3, #28] */
/* @0x1644e8 b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4> */
/* @0x1644ec andseq r6, lr, r0, ror #5 */
/* @0x1644f0 andseq r6, lr, r0, lsl #4 */
/* @0x1644f4 andseq r6, lr, r12, lsl r2 */

/* ── FUNC 0x1644f8 · C3D_Model::SaveToFile(char const*) · size=508 · insn=127 */
/* @0x1644f8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1644fc vpush {d8, d9, d10, d11, d12} */
/* @0x164500 mov r7, r0 */
/* @0x164504 mov r0, r1 */
/* @0x164508 ldr r1, [pc, #0x1d4] */
/* @0x16450c add r1, pc, r1 */
/* @0x164510 bl 0xb6844 <fopen@plt> */
/* @0x164514 subs r4, r0, #0 */
/* @0x164518 moveq r0, r4 */
/* @0x16451c beq 0x1646c4 <_ZN9C3D_Model10SaveToFileEPKc+0x1cc> */
/* @0x164520 ldr r5, [pc, #0x1c0] */
/* @0x164524 mov r2, #100 */
/* @0x164528 add r5, pc, r5 */
/* @0x16452c mov r1, r5 */
/* @0x164530 bl 0xb68a4 <fprintf@plt> */
/* @0x164534 mov r0, r4 */
/* @0x164538 mov r1, r5 */
/* @0x16453c ldr r2, [r7] */
/* @0x164540 bl 0xb68a4 <fprintf@plt> */
/* @0x164544 ldr r3, [r7] */
/* @0x164548 cmp r3, #0 */
/* @0x16454c ble 0x1646b8 <_ZN9C3D_Model10SaveToFileEPKc+0x1c0> */
/* @0x164550 ldr r8, [pc, #0x194] */
/* @0x164554 mov r6, #0 */
/* @0x164558 ldr r5, [pc, #0x190] */
/* @0x16455c add r8, pc, r8 */
/* @0x164560 add r5, pc, r5 */
/* @0x164564 ldr r3, [r7, #0x8] */
/* @0x164568 ldr r3, [r3, r6, lsl #2] */
/* @0x16456c vldr s25, [r3, #4] */
/* @0x164570 vldr s24, [r3, #8] */
/* @0x164574 vldr s23, [r3, #12] */
/* @0x164578 vldr s19, [r3, #16] */
/* @0x16457c vldr s22, [r3, #20] */
/* @0x164580 ldr r2, [r3] */
/* @0x164584 vldr s18, [r3, #24] */
/* @0x164588 vldr s17, [r3, #28] */
/* @0x16458c vldr s21, [r3, #32] */
/* @0x164590 sub r12, r2, #3 */
/* @0x164594 vldr s16, [r3, #36] */
/* @0x164598 vldr s20, [r3, #40] */
/* @0x16459c cmp r12, #6 */
/* @0x1645a0 addls pc, pc, r12, lsl #2 */
/* @0x1645a4 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0> */
/* @0x1645a8 b 0x1646cc <_ZN9C3D_Model10SaveToFileEPKc+0x1d4> */
/* @0x1645ac b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0> */
/* @0x1645b0 b 0x1646dc <_ZN9C3D_Model10SaveToFileEPKc+0x1e4> */
/* @0x1645b4 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0> */
/* @0x1645b8 b 0x1646d4 <_ZN9C3D_Model10SaveToFileEPKc+0x1dc> */
/* @0x1645bc b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0> */
/* @0x1645c0 b 0x1645c4 <_ZN9C3D_Model10SaveToFileEPKc+0xcc> */
/* @0x1645c4 vcvt.f32.s32 s16, s16 */
/* @0x1645c8 mov r1, r8 */
/* @0x1645cc mov r0, r4 */
/* @0x1645d0 bl 0xb68a4 <fprintf@plt> */
/* @0x1645d4 mov r1, r5 */
/* @0x1645d8 mov r0, r4 */
/* @0x1645dc add r6, r6, #1 */
/* @0x1645e0 vcvt.f64.f32 d7, s25 */
/* @0x1645e4 vmov r2, r3, d7 */
/* @0x1645e8 bl 0xb68a4 <fprintf@plt> */
/* @0x1645ec mov r1, r5 */
/* @0x1645f0 vcvt.f64.f32 d7, s24 */
/* @0x1645f4 mov r0, r4 */
/* @0x1645f8 vmov r2, r3, d7 */
/* @0x1645fc bl 0xb68a4 <fprintf@plt> */
/* @0x164600 mov r1, r5 */
/* @0x164604 vcvt.f64.f32 d7, s23 */
/* @0x164608 mov r0, r4 */
/* @0x16460c vmov r2, r3, d7 */
/* @0x164610 bl 0xb68a4 <fprintf@plt> */
/* @0x164614 mov r1, r5 */
/* @0x164618 vcvt.f64.f32 d7, s19 */
/* @0x16461c mov r0, r4 */
/* @0x164620 vmov r2, r3, d7 */
/* @0x164624 bl 0xb68a4 <fprintf@plt> */
/* @0x164628 mov r1, r5 */
/* @0x16462c vcvt.f64.f32 d7, s22 */
/* @0x164630 mov r0, r4 */
/* @0x164634 vmov r2, r3, d7 */
/* @0x164638 bl 0xb68a4 <fprintf@plt> */
/* @0x16463c mov r1, r5 */
/* @0x164640 vcvt.f64.f32 d7, s18 */
/* @0x164644 mov r0, r4 */
/* @0x164648 vmov r2, r3, d7 */
/* @0x16464c bl 0xb68a4 <fprintf@plt> */
/* @0x164650 mov r1, r5 */
/* @0x164654 vcvt.f64.f32 d7, s17 */
/* @0x164658 mov r0, r4 */
/* @0x16465c vmov r2, r3, d7 */
/* @0x164660 bl 0xb68a4 <fprintf@plt> */
/* @0x164664 mov r1, r5 */
/* @0x164668 vcvt.f64.f32 d7, s21 */
/* @0x16466c mov r0, r4 */
/* @0x164670 vmov r2, r3, d7 */
/* @0x164674 bl 0xb68a4 <fprintf@plt> */
/* @0x164678 mov r1, r5 */
/* @0x16467c vcvt.f64.f32 d7, s16 */
/* @0x164680 mov r0, r4 */
/* @0x164684 vmov r2, r3, d7 */
/* @0x164688 bl 0xb68a4 <fprintf@plt> */
/* @0x16468c mov r1, r5 */
/* @0x164690 vcvt.f64.f32 d7, s20 */
/* @0x164694 mov r0, r4 */
/* @0x164698 vmov r2, r3, d7 */
/* @0x16469c bl 0xb68a4 <fprintf@plt> */
/* @0x1646a0 mov r0, #10 */
/* @0x1646a4 mov r1, r4 */
/* @0x1646a8 bl 0xb68b0 <fputc@plt> */
/* @0x1646ac ldr r3, [r7] */
/* @0x1646b0 cmp r3, r6 */
/* @0x1646b4 bgt 0x164564 <_ZN9C3D_Model10SaveToFileEPKc+0x6c> */
/* @0x1646b8 mov r0, r4 */
/* @0x1646bc bl 0xb6850 <fclose@plt> */
/* @0x1646c0 mov r0, #1 */
/* @0x1646c4 vpop {d8, d9, d10, d11, d12} */
/* @0x1646c8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1646cc vcvt.f32.s32 s19, s19 */
/* @0x1646d0 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0> */
/* @0x1646d4 vcvt.f32.s32 s17, s17 */
/* @0x1646d8 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0> */
/* @0x1646dc vcvt.f32.s32 s18, s18 */
/* @0x1646e0 b 0x1645c8 <_ZN9C3D_Model10SaveToFileEPKc+0xd0> */
/* @0x1646e4 andseq r11, sp, r0, ror #28 */
/* @0x1646e8 andseq r6, lr, r4, asr r0 */
/* @0x1646ec ldrheq sp, [r12], -r0 */
/* @0x1646f0 andseq r6, lr, r0, lsr #32 */

/* ── FUNC 0x1646f4 · C3D_Model::SaveToBuffer(int) · size=480 · insn=120 */
/* @0x1646f4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1646f8 vpush {d8, d9} */
/* @0x1646fc sub sp, sp, #2128 */
/* @0x164700 ldr r8, [pc, #0x1c0] */
/* @0x164704 sub sp, sp, #12 */
/* @0x164708 mov r9, r0 */
/* @0x16470c mov r0, r1 */
/* @0x164710 ldr r8, [pc, r8] */
/* @0x164714 ldr r3, [r8] */
/* @0x164718 str r3, [sp, #0x854] */
/* @0x16471c bl 0xc6720 <_Z10GetIBufferi> */
/* @0x164720 subs r6, r0, #0 */
/* @0x164724 moveq r0, r6 */
/* @0x164728 beq 0x16488c <_ZN9C3D_Model12SaveToBufferEi+0x198> */
/* @0x16472c ldr r4, [pc, #0x198] */
/* @0x164730 add r5, sp, #84 */
/* @0x164734 mov r3, #100 */
/* @0x164738 mov r1, #2048 */
/* @0x16473c add r4, pc, r4 */
/* @0x164740 mov r0, r5 */
/* @0x164744 ldr r7, [pc, #0x184] */
/* @0x164748 mov r2, r4 */
/* @0x16474c bl 0xb65c8 <snprintf@plt> */
/* @0x164750 mov r1, r5 */
/* @0x164754 mov r0, r6 */
/* @0x164758 add r7, pc, r7 */
/* @0x16475c bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x164760 mov r2, r4 */
/* @0x164764 ldr r3, [r9] */
/* @0x164768 mov r1, #2048 */
/* @0x16476c mov r0, r5 */
/* @0x164770 mov r4, #0 */
/* @0x164774 bl 0xb65c8 <snprintf@plt> */
/* @0x164778 mov r0, r6 */
/* @0x16477c mov r1, r5 */
/* @0x164780 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x164784 ldr r3, [r9] */
/* @0x164788 cmp r3, #0 */
/* @0x16478c ble 0x164870 <_ZN9C3D_Model12SaveToBufferEi+0x17c> */
/* @0x164790 ldr r3, [r9, #0x8] */
/* @0x164794 ldr r12, [r3, r4, lsl #2] */
/* @0x164798 vldr s18, [r12, #4] */
/* @0x16479c vldr s16, [r12, #8] */
/* @0x1647a0 vldr s0, [r12, #12] */
/* @0x1647a4 vldr s2, [r12, #16] */
/* @0x1647a8 vldr s4, [r12, #20] */
/* @0x1647ac ldr r3, [r12] */
/* @0x1647b0 vldr s6, [r12, #24] */
/* @0x1647b4 vldr s8, [r12, #28] */
/* @0x1647b8 vldr s10, [r12, #32] */
/* @0x1647bc sub lr, r3, #3 */
/* @0x1647c0 vldr s12, [r12, #36] */
/* @0x1647c4 vldr s14, [r12, #40] */
/* @0x1647c8 cmp lr, #6 */
/* @0x1647cc addls pc, pc, lr, lsl #2 */
/* @0x1647d0 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100> */
/* @0x1647d4 b 0x1648ac <_ZN9C3D_Model12SaveToBufferEi+0x1b8> */
/* @0x1647d8 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100> */
/* @0x1647dc b 0x1648bc <_ZN9C3D_Model12SaveToBufferEi+0x1c8> */
/* @0x1647e0 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100> */
/* @0x1647e4 b 0x1648b4 <_ZN9C3D_Model12SaveToBufferEi+0x1c0> */
/* @0x1647e8 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100> */
/* @0x1647ec b 0x1647f0 <_ZN9C3D_Model12SaveToBufferEi+0xfc> */
/* @0x1647f0 vcvt.f32.s32 s12, s12 */
/* @0x1647f4 mov r1, #2048 */
/* @0x1647f8 mov r2, r7 */
/* @0x1647fc mov r0, r5 */
/* @0x164800 add r4, r4, #1 */
/* @0x164804 vcvt.f64.f32 d0, s0 */
/* @0x164808 vcvt.f64.f32 d1, s2 */
/* @0x16480c vstr d0, [sp, #16] */
/* @0x164810 vcvt.f64.f32 d2, s4 */
/* @0x164814 vstr d1, [sp, #24] */
/* @0x164818 vcvt.f64.f32 d3, s6 */
/* @0x16481c vstr d2, [sp, #32] */
/* @0x164820 vcvt.f64.f32 d4, s8 */
/* @0x164824 vstr d3, [sp, #40] */
/* @0x164828 vcvt.f64.f32 d5, s10 */
/* @0x16482c vstr d4, [sp, #48] */
/* @0x164830 vcvt.f64.f32 d6, s12 */
/* @0x164834 vstr d5, [sp, #56] */
/* @0x164838 vcvt.f64.f32 d7, s14 */
/* @0x16483c vstr d6, [sp, #64] */
/* @0x164840 vcvt.f64.f32 d9, s18 */
/* @0x164844 vstr d7, [sp, #72] */
/* @0x164848 vcvt.f64.f32 d8, s16 */
/* @0x16484c vstr d9, [sp] */
/* @0x164850 vstr d8, [sp, #8] */
/* @0x164854 bl 0xb65c8 <snprintf@plt> */
/* @0x164858 mov r0, r6 */
/* @0x16485c mov r1, r5 */
/* @0x164860 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x164864 ldr r3, [r9] */
/* @0x164868 cmp r3, r4 */
/* @0x16486c bgt 0x164790 <_ZN9C3D_Model12SaveToBufferEi+0x9c> */
/* @0x164870 ldr r3, [r6] */
/* @0x164874 mov r1, #0 */
/* @0x164878 mov r0, r6 */
/* @0x16487c mov r2, r1 */
/* @0x164880 ldr r3, [r3, #0x10] */
/* @0x164884 blx r3 */
/* @0x164888 mov r0, #1 */
/* @0x16488c ldr r2, [sp, #0x854] */
/* @0x164890 ldr r3, [r8] */
/* @0x164894 cmp r2, r3 */
/* @0x164898 bne 0x1648c4 <_ZN9C3D_Model12SaveToBufferEi+0x1d0> */
/* @0x16489c add sp, sp, #2128 */
/* @0x1648a0 add sp, sp, #12 */
/* @0x1648a4 vpop {d8, d9} */
/* @0x1648a8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1648ac vcvt.f32.s32 s2, s2 */
/* @0x1648b0 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100> */
/* @0x1648b4 vcvt.f32.s32 s8, s8 */
/* @0x1648b8 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100> */
/* @0x1648bc vcvt.f32.s32 s6, s6 */
/* @0x1648c0 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100> */
/* @0x1648c4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1648c8 eoreq r9, r8, r0, asr #4 */
/* @0x1648cc andseq r5, lr, r0, asr #28 */
/* @0x1648d0 andseq r5, lr, r0, lsr lr */

/* ── FUNC 0x1648d4 · C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float) · size=216 · insn=54 */
/* @0x1648d4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1648d8 vpush {d8, d9, d10} */
/* @0x1648dc mov r4, r0 */
/* @0x1648e0 vldr s21, [sp, #64] */
/* @0x1648e4 ldr r0, [r0] */
/* @0x1648e8 mov r7, r2 */
/* @0x1648ec ldr r2, [r4, #0x4] */
/* @0x1648f0 mov r5, r1 */
/* @0x1648f4 mov r6, r3 */
/* @0x1648f8 vldr s20, [sp, #68] */
/* @0x1648fc cmp r0, r2 */
/* @0x164900 vldr s19, [sp, #72] */
/* @0x164904 vldr s18, [sp, #76] */
/* @0x164908 vldr s17, [sp, #80] */
/* @0x16490c vldr s16, [sp, #84] */
/* @0x164910 ldr r11, [sp, #0x58] */
/* @0x164914 ldr r10, [sp, #0x5c] */
/* @0x164918 movlt r9, r0 */
/* @0x16491c blt 0x164950 <_ZN9C3D_Model8AddEntryEiffffffffff+0x7c> */
/* @0x164920 cmp r0, #0 */
/* @0x164924 ldr r2, [pc, #0x7c] */
/* @0x164928 lslne r8, r0, #1 */
/* @0x16492c lslne r1, r0, #3 */
/* @0x164930 moveq r1, #128 */
/* @0x164934 add r0, r4, #8 */
/* @0x164938 add r2, pc, r2 */
/* @0x16493c movw r3, #0x195 */
/* @0x164940 moveq r8, #32 */
/* @0x164944 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x164948 ldr r9, [r4] */
/* @0x16494c str r8, [r4, #0x4] */
/* @0x164950 mov r0, #44 */
/* @0x164954 ldr r8, [r4, #0x8] */
/* @0x164958 bl 0x27c524 <_Znwj> */
/* @0x16495c ldr r12, [r4] */
/* @0x164960 add r3, r12, #1 */
/* @0x164964 str r0, [r8, r9, lsl #2] */
/* @0x164968 ldr r2, [r4, #0x8] */
/* @0x16496c ldr r12, [r2, r12, lsl #2] */
/* @0x164970 vstr s21, [r12, #12] */
/* @0x164974 vstr s20, [r12, #16] */
/* @0x164978 vstr s19, [r12, #20] */
/* @0x16497c vstr s18, [r12, #24] */
/* @0x164980 vstr s17, [r12, #28] */
/* @0x164984 str r7, [r12, #0x4] */
/* @0x164988 vstr s16, [r12, #32] */
/* @0x16498c str r6, [r12, #0x8] */
/* @0x164990 str r11, [r12, #0x24] */
/* @0x164994 str r10, [r12, #0x28] */
/* @0x164998 vpop {d8, d9, d10} */
/* @0x16499c str r5, [r12] */
/* @0x1649a0 str r3, [r4] */
/* @0x1649a4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1649a8 ldrsbeq r5, [lr], -r12 */

/* ── FUNC 0x1649ac · C3D_Model::Draw(float, float, float, int) · size=1612 · insn=403 */
/* @0x1649ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1649b0 mov r7, r1 */
/* @0x1649b4 ldr r1, [r0, #0xc] */
/* @0x1649b8 sub sp, sp, #44 */
/* @0x1649bc ldr r10, [pc, #0x624] */
/* @0x1649c0 mov r6, r0 */
/* @0x1649c4 cmp r1, #0 */
/* @0x1649c8 mov r8, r2 */
/* @0x1649cc add r10, pc, r10 */
/* @0x1649d0 mov r9, r3 */
/* @0x1649d4 ldr r5, [sp, #0x50] */
/* @0x1649d8 beq 0x164a0c <_ZN9C3D_Model4DrawEfffi+0x60> */
/* @0x1649dc ldr r3, [r1, #0xc] */
/* @0x1649e0 ldr r4, [r1] */
/* @0x1649e4 cmp r3, r5 */
/* @0x1649e8 bne 0x164a04 <_ZN9C3D_Model4DrawEfffi+0x58> */
/* @0x1649ec b 0x164b50 <_ZN9C3D_Model4DrawEfffi+0x1a4> */
/* @0x1649f0 ldr r3, [r4, #0xc] */
/* @0x1649f4 ldr r2, [r4] */
/* @0x1649f8 cmp r3, r5 */
/* @0x1649fc beq 0x164b54 <_ZN9C3D_Model4DrawEfffi+0x1a8> */
/* @0x164a00 mov r4, r2 */
/* @0x164a04 cmp r4, #0 */
/* @0x164a08 bne 0x1649f0 <_ZN9C3D_Model4DrawEfffi+0x44> */
/* @0x164a0c mov r0, #68 */
/* @0x164a10 bl 0x27c524 <_Znwj> */
/* @0x164a14 ldr r1, [pc, #0x5d0] */
/* @0x164a18 mov r3, #0 */
/* @0x164a1c ldr r2, [pc, #0x5cc] */
/* @0x164a20 cmn r5, #1 */
/* @0x164a24 str r3, [r0] */
/* @0x164a28 mov r4, r0 */
/* @0x164a2c str r3, [r0, #0x4] */
/* @0x164a30 str r3, [r0, #0x34] */
/* @0x164a34 str r3, [r0, #0x24] */
/* @0x164a38 str r3, [r0, #0x14] */
/* @0x164a3c str r3, [r0, #0x3c] */
/* @0x164a40 str r3, [r0, #0x2c] */
/* @0x164a44 str r3, [r0, #0x1c] */
/* @0x164a48 str r3, [r0, #0x10] */
/* @0x164a4c str r3, [r0, #0x38] */
/* @0x164a50 str r3, [r0, #0x28] */
/* @0x164a54 str r3, [r0, #0x18] */
/* @0x164a58 str r3, [r0, #0x40] */
/* @0x164a5c str r3, [r0, #0x30] */
/* @0x164a60 str r3, [r0, #0x20] */
/* @0x164a64 ldr r3, [r10, r1] */
/* @0x164a68 str r0, [r3] */
/* @0x164a6c str r3, [sp, #0x24] */
/* @0x164a70 ldr r3, [r10, r2] */
/* @0x164a74 str r5, [r0, #0xc] */
/* @0x164a78 ldr r3, [r3] */
/* @0x164a7c bic r3, r3, #1 */
/* @0x164a80 str r3, [r0, #0x8] */
/* @0x164a84 beq 0x164ab4 <_ZN9C3D_Model4DrawEfffi+0x108> */
/* @0x164a88 ldr r3, [pc, #0x564] */
/* @0x164a8c cmp r5, #16384 */
/* @0x164a90 ldrshhi r2, [r5, #20] */
/* @0x164a94 ldrhi r3, [r10, r3] */
/* @0x164a98 ldrls r3, [r10, r3] */
/* @0x164a9c ldrhi r3, [r3, #0x4] */
/* @0x164aa0 ldrls r3, [r3, #0x4] */
/* @0x164aa4 ldrhi r3, [r3, r2, lsl #2] */
/* @0x164aa8 ldrls r3, [r3, r5, lsl #2] */
/* @0x164aac ldr r3, [r3] */
/* @0x164ab0 str r3, [r4, #0x10] */
/* @0x164ab4 ldr r3, [r6, #0x10] */
/* @0x164ab8 ldr r2, [r6, #0x14] */
/* @0x164abc cmp r3, #0 */
/* @0x164ac0 add r2, r2, #1 */
/* @0x164ac4 str r2, [r6, #0x14] */
/* @0x164ac8 beq 0x164fd4 <_ZN9C3D_Model4DrawEfffi+0x628> */
/* @0x164acc str r4, [r3] */
/* @0x164ad0 mov r3, #0 */
/* @0x164ad4 ldr r2, [r6, #0x10] */
/* @0x164ad8 str r2, [r4, #0x4] */
/* @0x164adc str r4, [r6, #0x10] */
/* @0x164ae0 str r3, [r4] */
/* @0x164ae4 ldr r2, [r6] */
/* @0x164ae8 cmp r2, #0 */
/* @0x164aec movgt r10, #0 */
/* @0x164af0 movgt r11, r10 */
/* @0x164af4 ble 0x164c00 <_ZN9C3D_Model4DrawEfffi+0x254> */
/* @0x164af8 ldr r3, [r6, #0x8] */
/* @0x164afc ldr r12, [r3, r11, lsl #2] */
/* @0x164b00 ldr r3, [r12] */
/* @0x164b04 cmp r3, #15 */
/* @0x164b08 addls pc, pc, r3, lsl #2 */
/* @0x164b0c b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164b10 b 0x164fa8 <_ZN9C3D_Model4DrawEfffi+0x5fc> */
/* @0x164b14 b 0x164f9c <_ZN9C3D_Model4DrawEfffi+0x5f0> */
/* @0x164b18 b 0x164f80 <_ZN9C3D_Model4DrawEfffi+0x5d4> */
/* @0x164b1c b 0x164f5c <_ZN9C3D_Model4DrawEfffi+0x5b0> */
/* @0x164b20 b 0x164f34 <_ZN9C3D_Model4DrawEfffi+0x588> */
/* @0x164b24 b 0x164f00 <_ZN9C3D_Model4DrawEfffi+0x554> */
/* @0x164b28 b 0x164ed0 <_ZN9C3D_Model4DrawEfffi+0x524> */
/* @0x164b2c b 0x164e94 <_ZN9C3D_Model4DrawEfffi+0x4e8> */
/* @0x164b30 b 0x164e54 <_ZN9C3D_Model4DrawEfffi+0x4a8> */
/* @0x164b34 b 0x164e08 <_ZN9C3D_Model4DrawEfffi+0x45c> */
/* @0x164b38 b 0x164dc4 <_ZN9C3D_Model4DrawEfffi+0x418> */
/* @0x164b3c b 0x164d70 <_ZN9C3D_Model4DrawEfffi+0x3c4> */
/* @0x164b40 b 0x164d1c <_ZN9C3D_Model4DrawEfffi+0x370> */
/* @0x164b44 b 0x164cd0 <_ZN9C3D_Model4DrawEfffi+0x324> */
/* @0x164b48 b 0x164c8c <_ZN9C3D_Model4DrawEfffi+0x2e0> */
/* @0x164b4c b 0x164bac <_ZN9C3D_Model4DrawEfffi+0x200> */
/* @0x164b50 mov r4, r1 */
/* @0x164b54 cmn r5, #1 */
/* @0x164b58 beq 0x164b64 <_ZN9C3D_Model4DrawEfffi+0x1b8> */
/* @0x164b5c cmp r5, #16384 */
/* @0x164b60 bls 0x164c18 <_ZN9C3D_Model4DrawEfffi+0x26c> */
/* @0x164b64 ldr r3, [r4, #0x8] */
/* @0x164b68 cmp r3, #1 */
/* @0x164b6c beq 0x164b90 <_ZN9C3D_Model4DrawEfffi+0x1e4> */
/* @0x164b70 ldr r2, [pc, #0x478] */
/* @0x164b74 ldr r2, [r10, r2] */
/* @0x164b78 ldr r1, [r2] */
/* @0x164b7c bic r2, r1, #1 */
/* @0x164b80 cmp r3, r2 */
/* @0x164b84 beq 0x164b90 <_ZN9C3D_Model4DrawEfffi+0x1e4> */
/* @0x164b88 mov r0, r4 */
/* @0x164b8c bl 0x189120 <_ZN16GraphicsRecorder12ChangeColourEj> */
/* @0x164b90 mov r0, r4 */
/* @0x164b94 mov r1, r7 */
/* @0x164b98 mov r2, r8 */
/* @0x164b9c mov r3, r9 */
/* @0x164ba0 add sp, sp, #44 */
/* @0x164ba4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x164ba8 b 0x185a24 <_ZN16GraphicsRecorder4DrawEfff> */
/* @0x164bac ldr lr, [r12, #0x14] */
/* @0x164bb0 mov r10, #1 */
/* @0x164bb4 ldr r2, [r12, #0xc] */
/* @0x164bb8 ldr r0, [r12, #0x4] */
/* @0x164bbc ldr r1, [r12, #0x8] */
/* @0x164bc0 ldr r3, [r12, #0x10] */
/* @0x164bc4 str lr, [sp] */
/* @0x164bc8 ldr lr, [r12, #0x18] */
/* @0x164bcc str r5, [sp, #0x8] */
/* @0x164bd0 str lr, [sp, #0x4] */
/* @0x164bd4 ldr lr, [r12, #0x1c] */
/* @0x164bd8 str lr, [sp, #0xc] */
/* @0x164bdc ldr r12, [r12, #0x20] */
/* @0x164be0 str r12, [sp, #0x10] */
/* @0x164be4 bl 0x179834 <_Z16GR_3D_Draw_Floorffffffiff> */
/* @0x164be8 ldr r2, [r6] */
/* @0x164bec add r11, r11, #1 */
/* @0x164bf0 cmp r2, r11 */
/* @0x164bf4 bgt 0x164af8 <_ZN9C3D_Model4DrawEfffi+0x14c> */
/* @0x164bf8 cmp r10, #0 */
/* @0x164bfc bne 0x164c08 <_ZN9C3D_Model4DrawEfffi+0x25c> */
/* @0x164c00 mov r3, #0 */
/* @0x164c04 str r3, [r4, #0x8] */
/* @0x164c08 ldr r2, [sp, #0x24] */
/* @0x164c0c mov r3, #0 */
/* @0x164c10 str r3, [r2] */
/* @0x164c14 b 0x164b90 <_ZN9C3D_Model4DrawEfffi+0x1e4> */
/* @0x164c18 mov r0, r5 */
/* @0x164c1c bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x164c20 cmp r0, #0 */
/* @0x164c24 beq 0x164c48 <_ZN9C3D_Model4DrawEfffi+0x29c> */
/* @0x164c28 ldr r3, [pc, #0x3c4] */
/* @0x164c2c ldr r2, [r4, #0x10] */
/* @0x164c30 ldr r3, [r10, r3] */
/* @0x164c34 ldr r3, [r3, #0x4] */
/* @0x164c38 ldr r3, [r3, r5, lsl #2] */
/* @0x164c3c ldr r3, [r3] */
/* @0x164c40 cmp r2, r3 */
/* @0x164c44 beq 0x164b64 <_ZN9C3D_Model4DrawEfffi+0x1b8> */
/* @0x164c48 ldr r3, [r4, #0x4] */
/* @0x164c4c cmp r3, #0 */
/* @0x164c50 beq 0x164fc8 <_ZN9C3D_Model4DrawEfffi+0x61c> */
/* @0x164c54 ldr r2, [r4] */
/* @0x164c58 str r2, [r3] */
/* @0x164c5c ldm r4, {r2, r3} */
/* @0x164c60 cmp r2, #0 */
/* @0x164c64 mov r0, r4 */
/* @0x164c68 streq r3, [r6, #0x10] */
/* @0x164c6c strne r3, [r2, #0x4] */
/* @0x164c70 bl 0x188ca4 <_ZN16GraphicsRecorderD2Ev> */
/* @0x164c74 mov r0, r4 */
/* @0x164c78 bl 0x27d1d0 <_ZdlPv> */
/* @0x164c7c ldr r3, [r6, #0x14] */
/* @0x164c80 sub r3, r3, #1 */
/* @0x164c84 str r3, [r6, #0x14] */
/* @0x164c88 b 0x164a0c <_ZN9C3D_Model4DrawEfffi+0x60> */
/* @0x164c8c ldr lr, [r12, #0x14] */
/* @0x164c90 mov r10, #1 */
/* @0x164c94 ldr r2, [r12, #0xc] */
/* @0x164c98 ldr r0, [r12, #0x4] */
/* @0x164c9c ldr r1, [r12, #0x8] */
/* @0x164ca0 ldr r3, [r12, #0x10] */
/* @0x164ca4 str lr, [sp] */
/* @0x164ca8 ldr lr, [r12, #0x18] */
/* @0x164cac str r5, [sp, #0x8] */
/* @0x164cb0 str lr, [sp, #0x4] */
/* @0x164cb4 ldr lr, [r12, #0x1c] */
/* @0x164cb8 str lr, [sp, #0xc] */
/* @0x164cbc ldr r12, [r12, #0x20] */
/* @0x164cc0 str r12, [sp, #0x10] */
/* @0x164cc4 bl 0x1796e0 <_Z15GR_3D_Draw_Wallffffffiff> */
/* @0x164cc8 ldr r2, [r6] */
/* @0x164ccc b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164cd0 ldr lr, [r12, #0x14] */
/* @0x164cd4 mov r10, #1 */
/* @0x164cd8 ldr r2, [r12, #0xc] */
/* @0x164cdc ldr r0, [r12, #0x4] */
/* @0x164ce0 ldr r1, [r12, #0x8] */
/* @0x164ce4 ldr r3, [r12, #0x10] */
/* @0x164ce8 str lr, [sp] */
/* @0x164cec ldr lr, [r12, #0x18] */
/* @0x164cf0 str r5, [sp, #0x8] */
/* @0x164cf4 str lr, [sp, #0x4] */
/* @0x164cf8 ldr lr, [r12, #0x1c] */
/* @0x164cfc str lr, [sp, #0xc] */
/* @0x164d00 ldr lr, [r12, #0x20] */
/* @0x164d04 str lr, [sp, #0x10] */
/* @0x164d08 ldr r12, [r12, #0x24] */
/* @0x164d0c str r12, [sp, #0x14] */
/* @0x164d10 bl 0x17934c <_Z20GR_3D_Draw_Ellipsoidffffffiffi> */
/* @0x164d14 ldr r2, [r6] */
/* @0x164d18 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164d1c ldr lr, [r12, #0x14] */
/* @0x164d20 mov r10, #1 */
/* @0x164d24 ldr r2, [r12, #0xc] */
/* @0x164d28 ldr r0, [r12, #0x4] */
/* @0x164d2c ldr r1, [r12, #0x8] */
/* @0x164d30 ldr r3, [r12, #0x10] */
/* @0x164d34 str lr, [sp] */
/* @0x164d38 ldr lr, [r12, #0x18] */
/* @0x164d3c str r5, [sp, #0x8] */
/* @0x164d40 str lr, [sp, #0x4] */
/* @0x164d44 ldr lr, [r12, #0x1c] */
/* @0x164d48 str lr, [sp, #0xc] */
/* @0x164d4c ldr lr, [r12, #0x20] */
/* @0x164d50 str lr, [sp, #0x10] */
/* @0x164d54 ldrb lr, [r12, #0x24] */
/* @0x164d58 str lr, [sp, #0x14] */
/* @0x164d5c ldr r12, [r12, #0x28] */
/* @0x164d60 str r12, [sp, #0x18] */
/* @0x164d64 bl 0x179094 <_Z15GR_3D_Draw_Coneffffffiffbi> */
/* @0x164d68 ldr r2, [r6] */
/* @0x164d6c b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164d70 ldr lr, [r12, #0x14] */
/* @0x164d74 mov r10, #1 */
/* @0x164d78 ldr r2, [r12, #0xc] */
/* @0x164d7c ldr r0, [r12, #0x4] */
/* @0x164d80 ldr r1, [r12, #0x8] */
/* @0x164d84 ldr r3, [r12, #0x10] */
/* @0x164d88 str lr, [sp] */
/* @0x164d8c ldr lr, [r12, #0x18] */
/* @0x164d90 str r5, [sp, #0x8] */
/* @0x164d94 str lr, [sp, #0x4] */
/* @0x164d98 ldr lr, [r12, #0x1c] */
/* @0x164d9c str lr, [sp, #0xc] */
/* @0x164da0 ldr lr, [r12, #0x20] */
/* @0x164da4 str lr, [sp, #0x10] */
/* @0x164da8 ldrb lr, [r12, #0x24] */
/* @0x164dac str lr, [sp, #0x14] */
/* @0x164db0 ldr r12, [r12, #0x28] */
/* @0x164db4 str r12, [sp, #0x18] */
/* @0x164db8 bl 0x178d44 <_Z19GR_3D_Draw_Cylinderffffffiffbi> */
/* @0x164dbc ldr r2, [r6] */
/* @0x164dc0 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164dc4 ldr lr, [r12, #0x14] */
/* @0x164dc8 mov r10, #1 */
/* @0x164dcc ldr r2, [r12, #0xc] */
/* @0x164dd0 ldr r0, [r12, #0x4] */
/* @0x164dd4 ldr r1, [r12, #0x8] */
/* @0x164dd8 ldr r3, [r12, #0x10] */
/* @0x164ddc str lr, [sp] */
/* @0x164de0 ldr lr, [r12, #0x18] */
/* @0x164de4 str r5, [sp, #0x8] */
/* @0x164de8 str lr, [sp, #0x4] */
/* @0x164dec ldr lr, [r12, #0x1c] */
/* @0x164df0 str lr, [sp, #0xc] */
/* @0x164df4 ldr r12, [r12, #0x20] */
/* @0x164df8 str r12, [sp, #0x10] */
/* @0x164dfc bl 0x17763c <_Z16GR_3D_Draw_Blockffffffiff> */
/* @0x164e00 ldr r2, [r6] */
/* @0x164e04 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164e08 ldr lr, [r12, #0x14] */
/* @0x164e0c ldr r2, [r12, #0xc] */
/* @0x164e10 ldr r0, [r12, #0x4] */
/* @0x164e14 ldr r1, [r12, #0x8] */
/* @0x164e18 ldr r3, [r12, #0x10] */
/* @0x164e1c str lr, [sp] */
/* @0x164e20 ldr lr, [r12, #0x18] */
/* @0x164e24 str lr, [sp, #0x4] */
/* @0x164e28 ldr lr, [r12, #0x1c] */
/* @0x164e2c str lr, [sp, #0x8] */
/* @0x164e30 ldr lr, [r12, #0x20] */
/* @0x164e34 str lr, [sp, #0xc] */
/* @0x164e38 ldr lr, [r12, #0x24] */
/* @0x164e3c str lr, [sp, #0x10] */
/* @0x164e40 ldr r12, [r12, #0x28] */
/* @0x164e44 str r12, [sp, #0x14] */
/* @0x164e48 bl 0x1774e4 <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf> */
/* @0x164e4c ldr r2, [r6] */
/* @0x164e50 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164e54 ldr lr, [r12, #0x14] */
/* @0x164e58 mov r10, #1 */
/* @0x164e5c ldr r2, [r12, #0xc] */
/* @0x164e60 ldr r0, [r12, #0x4] */
/* @0x164e64 ldr r1, [r12, #0x8] */
/* @0x164e68 ldr r3, [r12, #0x10] */
/* @0x164e6c str lr, [sp] */
/* @0x164e70 ldr lr, [r12, #0x18] */
/* @0x164e74 str lr, [sp, #0x4] */
/* @0x164e78 ldr lr, [r12, #0x1c] */
/* @0x164e7c str lr, [sp, #0x8] */
/* @0x164e80 ldr r12, [r12, #0x20] */
/* @0x164e84 str r12, [sp, #0xc] */
/* @0x164e88 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x164e8c ldr r2, [r6] */
/* @0x164e90 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164e94 ldr lr, [r12, #0x14] */
/* @0x164e98 ldr r2, [r12, #0xc] */
/* @0x164e9c ldr r0, [r12, #0x4] */
/* @0x164ea0 ldr r1, [r12, #0x8] */
/* @0x164ea4 ldr r3, [r12, #0x10] */
/* @0x164ea8 str lr, [sp] */
/* @0x164eac ldr lr, [r12, #0x18] */
/* @0x164eb0 str lr, [sp, #0x4] */
/* @0x164eb4 ldr lr, [r12, #0x1c] */
/* @0x164eb8 str lr, [sp, #0x8] */
/* @0x164ebc ldr r12, [r12, #0x20] */
/* @0x164ec0 str r12, [sp, #0xc] */
/* @0x164ec4 bl 0x1772d0 <_Z20GR_3D_Vertex_N_Colorffffffjf> */
/* @0x164ec8 ldr r2, [r6] */
/* @0x164ecc b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164ed0 ldr lr, [r12, #0x14] */
/* @0x164ed4 mov r10, #1 */
/* @0x164ed8 ldr r2, [r12, #0xc] */
/* @0x164edc ldr r0, [r12, #0x4] */
/* @0x164ee0 ldr r1, [r12, #0x8] */
/* @0x164ee4 ldr r3, [r12, #0x10] */
/* @0x164ee8 str lr, [sp] */
/* @0x164eec ldr r12, [r12, #0x18] */
/* @0x164ef0 str r12, [sp, #0x4] */
/* @0x164ef4 bl 0x177214 <_Z14GR_3D_Vertex_Nffffff> */
/* @0x164ef8 ldr r2, [r6] */
/* @0x164efc b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164f00 ldr lr, [r12, #0x14] */
/* @0x164f04 ldr r2, [r12, #0xc] */
/* @0x164f08 ldr r0, [r12, #0x4] */
/* @0x164f0c ldr r1, [r12, #0x8] */
/* @0x164f10 ldr r3, [r12, #0x10] */
/* @0x164f14 str lr, [sp] */
/* @0x164f18 ldr lr, [r12, #0x18] */
/* @0x164f1c str lr, [sp, #0x4] */
/* @0x164f20 ldr r12, [r12, #0x1c] */
/* @0x164f24 str r12, [sp, #0x8] */
/* @0x164f28 bl 0x1770c8 <_Z26GR_3D_Vertex_Texture_Colorfffffjf> */
/* @0x164f2c ldr r2, [r6] */
/* @0x164f30 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164f34 ldr r2, [r12, #0xc] */
/* @0x164f38 mov r10, #1 */
/* @0x164f3c ldr r0, [r12, #0x4] */
/* @0x164f40 ldr r1, [r12, #0x8] */
/* @0x164f44 ldr r3, [r12, #0x10] */
/* @0x164f48 ldr r12, [r12, #0x14] */
/* @0x164f4c str r12, [sp] */
/* @0x164f50 bl 0x176f7c <_Z20GR_3D_Vertex_Texturefffff> */
/* @0x164f54 ldr r2, [r6] */
/* @0x164f58 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164f5c ldr r2, [r12, #0xc] */
/* @0x164f60 ldr r3, [r12, #0x10] */
/* @0x164f64 ldr r0, [r12, #0x4] */
/* @0x164f68 ldr r1, [r12, #0x8] */
/* @0x164f6c ldr r12, [r12, #0x14] */
/* @0x164f70 str r12, [sp] */
/* @0x164f74 bl 0x176ed4 <_Z18GR_3D_Vertex_Colorfffjf> */
/* @0x164f78 ldr r2, [r6] */
/* @0x164f7c b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164f80 ldr r2, [r12, #0xc] */
/* @0x164f84 mov r10, #1 */
/* @0x164f88 ldr r0, [r12, #0x4] */
/* @0x164f8c ldr r1, [r12, #0x8] */
/* @0x164f90 bl 0x176e2c <_Z12GR_3D_Vertexfff> */
/* @0x164f94 ldr r2, [r6] */
/* @0x164f98 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164f9c bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x164fa0 ldr r2, [r6] */
/* @0x164fa4 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164fa8 vldr s15, [r12, #4] */
/* @0x164fac vcvt.f64.f32 d6, s15 */
/* @0x164fb0 vmov r0, r1, d6 */
/* @0x164fb4 bl 0xb66e8 <lrint@plt> */
/* @0x164fb8 mov r1, r5 */
/* @0x164fbc bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */
/* @0x164fc0 ldr r2, [r6] */
/* @0x164fc4 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240> */
/* @0x164fc8 ldr r2, [r4] */
/* @0x164fcc str r2, [r6, #0xc] */
/* @0x164fd0 b 0x164c60 <_ZN9C3D_Model4DrawEfffi+0x2b4> */
/* @0x164fd4 str r4, [r6, #0x10] */
/* @0x164fd8 str r4, [r6, #0xc] */
/* @0x164fdc str r3, [r4, #0x4] */
/* @0x164fe0 str r3, [r4] */
/* @0x164fe4 b 0x164ae4 <_ZN9C3D_Model4DrawEfffi+0x138> */
/* @0x164fe8 eoreq sp, r8, r4, lsl #5 */
/* @0x164fec .word 0xffffe49c */
/* @0x164ff0 .word 0xffffc0ac */
/* @0x164ff4 .word 0xffffbccc */

/* ── FUNC 0x164ff8 · C3D_Model::~C3D_Model() · size=200 · insn=50 */
/* @0x164ff8 push {r4, r5, r6, lr} */
/* @0x164ffc mov r6, r0 */
/* @0x165000 bl 0x163ce0 <_ZN9C3D_Model5ClearEv> */
/* @0x165004 ldr r3, [r6, #0x18] */
/* @0x165008 cmp r3, #0 */
/* @0x16500c beq 0x165044 <_ZN9C3D_ModelD2Ev+0x4c> */
/* @0x165010 ldr r4, [r6, #0xc] */
/* @0x165014 cmp r4, #0 */
/* @0x165018 beq 0x165044 <_ZN9C3D_ModelD2Ev+0x4c> */
/* @0x16501c cmp r3, #2 */
/* @0x165020 beq 0x16505c <_ZN9C3D_ModelD2Ev+0x64> */
/* @0x165024 cmp r3, #3 */
/* @0x165028 beq 0x165078 <_ZN9C3D_ModelD2Ev+0x80> */
/* @0x16502c cmp r3, #1 */
/* @0x165030 beq 0x16509c <_ZN9C3D_ModelD2Ev+0xa4> */
/* @0x165034 ldr r5, [r4] */
/* @0x165038 cmp r5, #0 */
/* @0x16503c mov r4, r5 */
/* @0x165040 bne 0x165034 <_ZN9C3D_ModelD2Ev+0x3c> */
/* @0x165044 mov r3, #0 */
/* @0x165048 mov r0, r6 */
/* @0x16504c str r3, [r6, #0x14] */
/* @0x165050 str r3, [r6, #0x10] */
/* @0x165054 str r3, [r6, #0xc] */
/* @0x165058 pop {r4, r5, r6, pc} */
/* @0x16505c ldr r5, [r4] */
/* @0x165060 mov r0, r4 */
/* @0x165064 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x165068 cmp r5, #0 */
/* @0x16506c mov r4, r5 */
/* @0x165070 bne 0x16505c <_ZN9C3D_ModelD2Ev+0x64> */
/* @0x165074 b 0x165044 <_ZN9C3D_ModelD2Ev+0x4c> */
/* @0x165078 ldr r5, [r4] */
/* @0x16507c mov r0, r4 */
/* @0x165080 bl 0x188ca4 <_ZN16GraphicsRecorderD2Ev> */
/* @0x165084 mov r0, r4 */
/* @0x165088 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x16508c cmp r5, #0 */
/* @0x165090 mov r4, r5 */
/* @0x165094 bne 0x165078 <_ZN9C3D_ModelD2Ev+0x80> */
/* @0x165098 b 0x165044 <_ZN9C3D_ModelD2Ev+0x4c> */
/* @0x16509c ldr r5, [r4] */
/* @0x1650a0 mov r0, r4 */
/* @0x1650a4 bl 0x188ca4 <_ZN16GraphicsRecorderD2Ev> */
/* @0x1650a8 mov r0, r4 */
/* @0x1650ac bl 0x27d1d0 <_ZdlPv> */
/* @0x1650b0 cmp r5, #0 */
/* @0x1650b4 mov r4, r5 */
/* @0x1650b8 bne 0x16509c <_ZN9C3D_ModelD2Ev+0xa4> */
/* @0x1650bc b 0x165044 <_ZN9C3D_ModelD2Ev+0x4c> */

/* ── FUNC 0x164ff8 · C3D_Model::~C3D_Model() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1650c0 · GR_3DM_Create() · size=240 · insn=60 */
/* @0x1650c0 ldr r3, [pc, #0xd8] */
/* @0x1650c4 ldr r2, [pc, #0xd8] */
/* @0x1650c8 add r3, pc, r3 */
/* @0x1650cc push {r4, r5, r6, r7, r8, lr} */
/* @0x1650d0 ldr r8, [r3, r2] */
/* @0x1650d4 ldr r2, [pc, #0xcc] */
/* @0x1650d8 ldr r5, [r8] */
/* @0x1650dc ldr r7, [r3, r2] */
/* @0x1650e0 cmp r5, #0 */
/* @0x1650e4 ble 0x16511c <_Z13GR_3DM_Createv+0x5c> */
/* @0x1650e8 ldr r3, [r7, #0x4] */
/* @0x1650ec ldr r6, [r3] */
/* @0x1650f0 cmp r6, #0 */
/* @0x1650f4 beq 0x165198 <_Z13GR_3DM_Createv+0xd8> */
/* @0x1650f8 mov r4, #0 */
/* @0x1650fc b 0x16510c <_Z13GR_3DM_Createv+0x4c> */
/* @0x165100 ldr r2, [r3, #0x4]! */
/* @0x165104 cmp r2, #0 */
/* @0x165108 beq 0x16513c <_Z13GR_3DM_Createv+0x7c> */
/* @0x16510c add r4, r4, #1 */
/* @0x165110 cmp r4, r5 */
/* @0x165114 lsl r6, r4, #2 */
/* @0x165118 bne 0x165100 <_Z13GR_3DM_Createv+0x40> */
/* @0x16511c ldr r3, [r7] */
/* @0x165120 cmp r5, r3 */
/* @0x165124 movlt r3, r5 */
/* @0x165128 bge 0x16515c <_Z13GR_3DM_Createv+0x9c> */
/* @0x16512c lsl r6, r5, #2 */
/* @0x165130 mov r4, r5 */
/* @0x165134 add r3, r3, #1 */
/* @0x165138 str r3, [r8] */
/* @0x16513c mov r0, #28 */
/* @0x165140 bl 0x27c524 <_Znwj> */
/* @0x165144 mov r5, r0 */
/* @0x165148 bl 0x163d84 <_ZN9C3D_ModelC2Ev> */
/* @0x16514c ldr r3, [r7, #0x4] */
/* @0x165150 mov r0, r4 */
/* @0x165154 str r5, [r3, r6] */
/* @0x165158 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16515c add r1, r5, #16 */
/* @0x165160 ldr r2, [pc, #0x44] */
/* @0x165164 movw r3, #0x283 */
/* @0x165168 add r0, r7, #4 */
/* @0x16516c add r2, pc, r2 */
/* @0x165170 lsl r1, r1, #2 */
/* @0x165174 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x165178 ldr r3, [r8] */
/* @0x16517c lsl r6, r5, #2 */
/* @0x165180 mov r4, r5 */
/* @0x165184 add r2, r3, #16 */
/* @0x165188 add r3, r3, #1 */
/* @0x16518c str r2, [r7] */
/* @0x165190 str r3, [r8] */
/* @0x165194 b 0x16513c <_Z13GR_3DM_Createv+0x7c> */
/* @0x165198 mov r4, r6 */
/* @0x16519c b 0x16513c <_Z13GR_3DM_Createv+0x7c> */
/* @0x1651a0 eoreq r12, r8, r8, lsl #23 */
/* @0x1651a4 .word 0xffffe4a0 */
/* @0x1651a8 .word 0xffffe4a4 */
/* @0x1651ac andseq r5, lr, r8, lsr #7 */

/* ── FUNC 0x1651b0 · GR_3DM_Destroy(int) · size=96 · insn=24 */
/* @0x1651b0 push {r4, r5, r6, lr} */
/* @0x1651b4 subs r4, r0, #0 */
/* @0x1651b8 poplt {r4, r5, r6, pc} */
/* @0x1651bc ldr r3, [pc, #0x44] */
/* @0x1651c0 ldr r3, [pc, r3] */
/* @0x1651c4 ldr r3, [r3] */
/* @0x1651c8 cmp r4, r3 */
/* @0x1651cc popge {r4, r5, r6, pc} */
/* @0x1651d0 ldr r5, [pc, #0x34] */
/* @0x1651d4 ldr r5, [pc, r5] */
/* @0x1651d8 ldr r3, [r5, #0x4] */
/* @0x1651dc ldr r6, [r3, r4, lsl #2] */
/* @0x1651e0 cmp r6, #0 */
/* @0x1651e4 popeq {r4, r5, r6, pc} */
/* @0x1651e8 mov r0, r6 */
/* @0x1651ec bl 0x164ff8 <_ZN9C3D_ModelD2Ev> */
/* @0x1651f0 mov r0, r6 */
/* @0x1651f4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1651f8 ldr r3, [r5, #0x4] */
/* @0x1651fc mov r2, #0 */
/* @0x165200 str r2, [r3, r4, lsl #2] */
/* @0x165204 pop {r4, r5, r6, pc} */
/* @0x165208 eoreq r10, r8, r0, lsr pc */
/* @0x16520c eoreq r10, r8, r0, lsr #30 */

/* ── FUNC 0x165210 · GR_3DM_Clear(int) · size=64 · insn=16 */
/* @0x165210 cmp r0, #0 */
/* @0x165214 bxlt lr */
/* @0x165218 ldr r3, [pc, #0x28] */
/* @0x16521c ldr r3, [pc, r3] */
/* @0x165220 ldr r3, [r3] */
/* @0x165224 cmp r0, r3 */
/* @0x165228 bxge lr */
/* @0x16522c ldr r3, [pc, #0x18] */
/* @0x165230 ldr r3, [pc, r3] */
/* @0x165234 ldr r3, [r3, #0x4] */
/* @0x165238 ldr r0, [r3, r0, lsl #2] */
/* @0x16523c cmp r0, #0 */
/* @0x165240 bxeq lr */
/* @0x165244 b 0x163ce0 <_ZN9C3D_Model5ClearEv> */
/* @0x165248 .word 0x0028aed4 */
/* @0x16524c eoreq r10, r8, r4, asr #29 */
