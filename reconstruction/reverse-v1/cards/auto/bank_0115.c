/* libyoyo.so 覆盖卡组 0115
 * 函数 0x17acec..0x17b3e4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x17acec · GR_Window_Views_Mouse_Get_XY(int&, int&, int) · size=160 · insn=40 */
/* @0x17acec cmp r2, #9 */
/* @0x17acf0 ldr r12, [pc, #0x84] */
/* @0x17acf4 push {r4, r5, r6} */
/* @0x17acf8 add r12, pc, r12 */
/* @0x17acfc mov r4, r2 */
/* @0x17ad00 bhi 0x17ad40 <_Z28GR_Window_Views_Mouse_Get_XYRiS_i+0x54> */
/* @0x17ad04 ldr r3, [pc, #0x74] */
/* @0x17ad08 ldr r3, [r12, r3] */
/* @0x17ad0c ldr r3, [r3] */
/* @0x17ad10 cmp r3, #0 */
/* @0x17ad14 beq 0x17ad54 <_Z28GR_Window_Views_Mouse_Get_XYRiS_i+0x68> */
/* @0x17ad18 ldr r6, [pc, #0x64] */
/* @0x17ad1c mov r2, r0 */
/* @0x17ad20 ldr r5, [pc, #0x60] */
/* @0x17ad24 mov r3, r1 */
/* @0x17ad28 ldr r0, [r12, r6] */
/* @0x17ad2c ldr r1, [r12, r5] */
/* @0x17ad30 ldr r0, [r0, r4, lsl #2] */
/* @0x17ad34 ldr r1, [r1, r4, lsl #2] */
/* @0x17ad38 pop {r4, r5, r6} */
/* @0x17ad3c b 0x17a6a0 <_Z23GR_Window_Views_ConvertiiRiS_> */
/* @0x17ad40 mov r3, #0 */
/* @0x17ad44 str r3, [r0] */
/* @0x17ad48 pop {r4, r5, r6} */
/* @0x17ad4c str r3, [r1] */
/* @0x17ad50 bx lr */
/* @0x17ad54 ldr r2, [pc, #0x28] */
/* @0x17ad58 ldr r3, [pc, #0x28] */
/* @0x17ad5c ldr r2, [r12, r2] */
/* @0x17ad60 ldr r2, [r2, r4, lsl #2] */
/* @0x17ad64 str r2, [r0] */
/* @0x17ad68 ldr r3, [r12, r3] */
/* @0x17ad6c ldr r3, [r3, r4, lsl #2] */
/* @0x17ad70 pop {r4, r5, r6} */
/* @0x17ad74 str r3, [r1] */
/* @0x17ad78 bx lr */
/* @0x17ad7c eoreq r6, r7, r8, asr pc */
/* @0x17ad80 .word 0xffffbcd8 */
/* @0x17ad84 .word 0xffffdf4c */
/* @0x17ad88 .word 0xffffdf48 */

/* ── FUNC 0x17ad8c · GR_Window_Views_Mouse_Get_X(int) · size=36 · insn=9 */
/* @0x17ad8c str lr, [sp, #-0x4]! */
/* @0x17ad90 sub sp, sp, #12 */
/* @0x17ad94 mov r2, r0 */
/* @0x17ad98 add r1, sp, #4 */
/* @0x17ad9c mov r0, sp */
/* @0x17ada0 bl 0x17acec <_Z28GR_Window_Views_Mouse_Get_XYRiS_i> */
/* @0x17ada4 ldr r0, [sp] */
/* @0x17ada8 add sp, sp, #12 */
/* @0x17adac ldr pc, [sp], #4 */

/* ── FUNC 0x17adb0 · GR_Window_Views_Mouse_Get_Y(int) · size=36 · insn=9 */
/* @0x17adb0 str lr, [sp, #-0x4]! */
/* @0x17adb4 sub sp, sp, #12 */
/* @0x17adb8 mov r2, r0 */
/* @0x17adbc add r1, sp, #4 */
/* @0x17adc0 mov r0, sp */
/* @0x17adc4 bl 0x17acec <_Z28GR_Window_Views_Mouse_Get_XYRiS_i> */
/* @0x17adc8 ldr r0, [sp, #0x4] */
/* @0x17adcc add sp, sp, #12 */
/* @0x17add0 ldr pc, [sp], #4 */

/* ── FUNC 0x17add4 · GR_Window_Set_Rectangle(int, int, int, int) · size=52 · insn=13 */
/* @0x17add4 push {r3, r4, r5, lr} */
/* @0x17add8 mov r4, r2 */
/* @0x17addc mov r5, r3 */
/* @0x17ade0 bl 0x17af38 <_Z22GR_Window_Set_Positionii> */
/* @0x17ade4 mov r0, r4 */
/* @0x17ade8 mov r1, r5 */
/* @0x17adec bl 0x17af3c <_Z18GR_Window_Set_Sizeii> */
/* @0x17adf0 ldr r3, [pc, #0xc] */
/* @0x17adf4 mov r2, #1 */
/* @0x17adf8 ldr r3, [pc, r3] */
/* @0x17adfc strb r2, [r3] */
/* @0x17ae00 pop {r3, r4, r5, pc} */
/* @0x17ae04 eoreq r5, r7, r0, lsr #10 */

/* ── FUNC 0x17ae08 · GR_Window_Set_Color(unsigned int) · size=24 · insn=6 */
/* @0x17ae08 ldr r3, [pc, #0xc] */
/* @0x17ae0c orr r0, r0, #-16777216 */
/* @0x17ae10 ldr r3, [pc, r3] */
/* @0x17ae14 str r0, [r3] */
/* @0x17ae18 bx lr */
/* @0x17ae1c eoreq r5, r7, r12, lsl #10 */

/* ── FUNC 0x17ae20 · GR_Window_Get_Color() · size=24 · insn=6 */
/* @0x17ae20 ldr r3, [pc, #0xc] */
/* @0x17ae24 ldr r3, [pc, r3] */
/* @0x17ae28 ldr r0, [r3] */
/* @0x17ae2c bic r0, r0, #-16777216 */
/* @0x17ae30 bx lr */
/* @0x17ae34 .word 0x002754f8 */

/* ── FUNC 0x17ae38 · GR_Window_Set_Caption(char const*, bool) · size=196 · insn=49 */
/* @0x17ae38 ldr r3, [pc, #0xb0] */
/* @0x17ae3c push {r4, r5, r6, r7, lr} */
/* @0x17ae40 ldr r3, [pc, r3] */
/* @0x17ae44 sub sp, sp, #12 */
/* @0x17ae48 mov r4, r0 */
/* @0x17ae4c ldr r3, [r3] */
/* @0x17ae50 mov r6, r1 */
/* @0x17ae54 sub r3, r3, #2 */
/* @0x17ae58 cmp r3, #1 */
/* @0x17ae5c bls 0x17ae68 <_Z21GR_Window_Set_CaptionPKcb+0x30> */
/* @0x17ae60 cmp r1, #0 */
/* @0x17ae64 beq 0x17aee8 <_Z21GR_Window_Set_CaptionPKcb+0xb0> */
/* @0x17ae68 cmp r4, #0 */
/* @0x17ae6c mov r3, #0 */
/* @0x17ae70 strh r3, [sp, #4] */
/* @0x17ae74 beq 0x17ae84 <_Z21GR_Window_Set_CaptionPKcb+0x4c> */
/* @0x17ae78 ldrb r3, [r4] */
/* @0x17ae7c cmp r3, #0 */
/* @0x17ae80 bne 0x17ae88 <_Z21GR_Window_Set_CaptionPKcb+0x50> */
/* @0x17ae84 add r4, sp, #4 */
/* @0x17ae88 ldr r5, [pc, #0x64] */
/* @0x17ae8c ldr r5, [pc, r5] */
/* @0x17ae90 ldr r0, [r5] */
/* @0x17ae94 cmp r0, #0 */
/* @0x17ae98 beq 0x17aea0 <_Z21GR_Window_Set_CaptionPKcb+0x68> */
/* @0x17ae9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x17aea0 mov r0, r4 */
/* @0x17aea4 mov r3, #0 */
/* @0x17aea8 str r3, [r5] */
/* @0x17aeac bl 0xb6538 <strlen@plt> */
/* @0x17aeb0 mov r3, #1 */
/* @0x17aeb4 ldr r1, [pc, #0x3c] */
/* @0x17aeb8 movw r2, #0x3a7 */
/* @0x17aebc add r1, pc, r1 */
/* @0x17aec0 add r7, r0, r3 */
/* @0x17aec4 mov r0, r7 */
/* @0x17aec8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17aecc mov r1, r4 */
/* @0x17aed0 mov r2, r7 */
/* @0x17aed4 str r0, [r5] */
/* @0x17aed8 bl 0xb65bc <memcpy@plt> */
/* @0x17aedc mov r0, r4 */
/* @0x17aee0 mov r1, r6 */
/* @0x17aee4 bl 0x17af2c <_Z22GR_Window_Set_CaptionMPKcb> */
/* @0x17aee8 add sp, sp, #12 */
/* @0x17aeec pop {r4, r5, r6, r7, pc} */
/* @0x17aef0 eoreq r5, r7, r0, ror #9 */
/* @0x17aef4 .word 0x00273bf4 */
/* @0x17aef8 mulseq sp, r8, r6 */

/* ── FUNC 0x17aefc · GR_Window_Get_Caption() · size=20 · insn=5 */
/* @0x17aefc ldr r3, [pc, #0x8] */
/* @0x17af00 ldr r3, [pc, r3] */
/* @0x17af04 ldr r0, [r3] */
/* @0x17af08 bx lr */
/* @0x17af0c eoreq r3, r7, r0, lsl #23 */

/* ── FUNC 0x17af10 · GR_Window_Set_FullScreen(bool) · size=4 · insn=1 */
/* @0x17af10 bx lr */

/* ── FUNC 0x17af14 · GR_Window_Set_Min_WidthM(int) · size=4 · insn=1 */
/* @0x17af14 bx lr */

/* ── FUNC 0x17af18 · GR_Window_Set_Max_WidthM(int) · size=4 · insn=1 */
/* @0x17af18 bx lr */

/* ── FUNC 0x17af1c · GR_Window_Set_Min_HeightM(int) · size=4 · insn=1 */
/* @0x17af1c bx lr */

/* ── FUNC 0x17af20 · GR_Window_Set_Max_HeightM(int) · size=4 · insn=1 */
/* @0x17af20 bx lr */

/* ── FUNC 0x17af24 · GR_Window_Get_FullScreen() · size=8 · insn=2 */
/* @0x17af24 mov r0, #1 */
/* @0x17af28 bx lr */

/* ── FUNC 0x17af2c · GR_Window_Set_CaptionM(char const*, bool) · size=4 · insn=1 */
/* @0x17af2c bx lr */

/* ── FUNC 0x17af30 · GR_Window_Mouse_Set(int, int) · size=4 · insn=1 */
/* @0x17af30 bx lr */

/* ── FUNC 0x17af34 · GR_Window_Center() · size=4 · insn=1 */
/* @0x17af34 bx lr */

/* ── FUNC 0x17af38 · GR_Window_Set_Position(int, int) · size=4 · insn=1 */
/* @0x17af38 bx lr */

/* ── FUNC 0x17af3c · GR_Window_Set_Size(int, int) · size=4 · insn=1 */
/* @0x17af3c bx lr */

/* ── FUNC 0x17af40 · GR_Window_Get_X() · size=8 · insn=2 */
/* @0x17af40 mov r0, #0 */
/* @0x17af44 bx lr */

/* ── FUNC 0x17af48 · GR_Window_Get_Y() · size=8 · insn=2 */
/* @0x17af48 mov r0, #0 */
/* @0x17af4c bx lr */

/* ── FUNC 0x17af50 · GR_Window_Get_Width() · size=20 · insn=5 */
/* @0x17af50 ldr r3, [pc, #0x8] */
/* @0x17af54 ldr r3, [pc, r3] */
/* @0x17af58 ldr r0, [r3] */
/* @0x17af5c bx lr */
/* @0x17af60 eoreq r4, r7, r8, asr #30 */

/* ── FUNC 0x17af64 · GR_Window_Get_Height() · size=20 · insn=5 */
/* @0x17af64 ldr r3, [pc, #0x8] */
/* @0x17af68 ldr r3, [pc, r3] */
/* @0x17af6c ldr r0, [r3] */
/* @0x17af70 bx lr */
/* @0x17af74 eoreq r4, r7, r8, lsr pc */

/* ── FUNC 0x17af78 · GR_Display_Get_Visible_Rects(double, double, double, double, double**) · size=8 · insn=2 */
/* @0x17af78 mov r0, #0 */
/* @0x17af7c bx lr */

/* ── FUNC 0x17af80 · GameMaker_PaintEvent(void*) · size=4 · insn=1 */
/* @0x17af80 b 0x169b1c <_Z14GR_D3D_Refreshv> */

/* ── FUNC 0x17af84 · GR_Window_Get_Cursor() · size=8 · insn=2 */
/* @0x17af84 mov r0, #0 */
/* @0x17af88 bx lr */

/* ── FUNC 0x17af8c · GR_Window_Set_Cursor(int) · size=20 · insn=5 */
/* @0x17af8c ldr r3, [pc, #0x8] */
/* @0x17af90 ldr r3, [pc, r3] */
/* @0x17af94 str r0, [r3] */
/* @0x17af98 bx lr */
/* @0x17af9c mlaeq r7, r4, r3, r5 */

/* ── FUNC 0x17afa0 · GraphicsPerf::Init() · size=168 · insn=42 */
/* @0x17afa0 push {r3, r4, r5, lr} */
/* @0x17afa4 movw r12, #0x3555 */
/* @0x17afa8 ldr r4, [pc, #0x7c] */
/* @0x17afac movt r12, #0x4782 */
/* @0x17afb0 ldr r0, [pc, #0x78] */
/* @0x17afb4 mov r1, #0 */
/* @0x17afb8 add r4, pc, r4 */
/* @0x17afbc ldr r2, [pc, #0x70] */
/* @0x17afc0 ldr r3, [pc, #0x70] */
/* @0x17afc4 ldr r0, [r4, r0] */
/* @0x17afc8 str r12, [r0] */
/* @0x17afcc ldr r2, [r4, r2] */
/* @0x17afd0 str r1, [r2] */
/* @0x17afd4 ldr r5, [r4, r3] */
/* @0x17afd8 ldr r3, [r5] */
/* @0x17afdc cmp r3, r1 */
/* @0x17afe0 beq 0x17b01c <_ZN12GraphicsPerf4InitEv+0x7c> */
/* @0x17afe4 ldr r1, [pc, #0x50] */
/* @0x17afe8 mov r0, #0 */
/* @0x17afec ldr r2, [pc, #0x4c] */
/* @0x17aff0 ldr r3, [pc, #0x4c] */
/* @0x17aff4 ldr r1, [r4, r1] */
/* @0x17aff8 str r0, [r1] */
/* @0x17affc ldr r2, [r4, r2] */
/* @0x17b000 ldr r3, [r4, r3] */
/* @0x17b004 ldrb r2, [r2, #0x83] */
/* @0x17b008 add r2, r2, #2 */
/* @0x17b00c vmov s14, r2 */
/* @0x17b010 vcvt.f32.s32 s15, s14 */
/* @0x17b014 vstr s15, [r3] */
/* @0x17b018 pop {r3, r4, r5, pc} */
/* @0x17b01c mov r0, #15 */
/* @0x17b020 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x17b024 str r0, [r5] */
/* @0x17b028 b 0x17afe4 <_ZN12GraphicsPerf4InitEv+0x44> */
/* @0x17b02c mlaeq r7, r8, r12, r6 */
/* @0x17b030 .word 0xffffe6d8 */
/* @0x17b034 .word 0xffffe6dc */
/* @0x17b038 .word 0xffffe648 */
/* @0x17b03c .word 0xffffe6e0 */
/* @0x17b040 .word 0xffffe64c */
/* @0x17b044 .word 0xffffe6e4 */

/* ── FUNC 0x17b048 · GraphicsPerf::Quit() · size=204 · insn=51 */
/* @0x17b048 push {r4, r5, r6, lr} */
/* @0x17b04c sub sp, sp, #8 */
/* @0x17b050 ldr r5, [pc, #0x9c] */
/* @0x17b054 ldr r3, [pc, #0x9c] */
/* @0x17b058 add r5, pc, r5 */
/* @0x17b05c ldr r6, [pc, #0x98] */
/* @0x17b060 ldr r3, [r5, r3] */
/* @0x17b064 add r6, pc, r6 */
/* @0x17b068 mov r1, r6 */
/* @0x17b06c ldr r4, [r3] */
/* @0x17b070 ldr r3, [r4] */
/* @0x17b074 mov r0, r4 */
/* @0x17b078 ldr r3, [r3, #0xc] */
/* @0x17b07c blx r3 */
/* @0x17b080 ldr r3, [r4] */
/* @0x17b084 ldr r1, [pc, #0x74] */
/* @0x17b088 mov r0, r4 */
/* @0x17b08c add r1, pc, r1 */
/* @0x17b090 ldr r3, [r3, #0xc] */
/* @0x17b094 blx r3 */
/* @0x17b098 ldr r1, [pc, #0x64] */
/* @0x17b09c ldr r2, [pc, #0x64] */
/* @0x17b0a0 mov r0, r4 */
/* @0x17b0a4 ldr r3, [pc, #0x60] */
/* @0x17b0a8 ldr r12, [r5, r1] */
/* @0x17b0ac ldr r2, [r5, r2] */
/* @0x17b0b0 ldr r1, [r4] */
/* @0x17b0b4 ldr r3, [r5, r3] */
/* @0x17b0b8 ldr r12, [r12] */
/* @0x17b0bc ldr r2, [r2] */
/* @0x17b0c0 ldr r3, [r3] */
/* @0x17b0c4 str r12, [sp] */
/* @0x17b0c8 ldr r12, [r1, #0xc] */
/* @0x17b0cc ldr r1, [pc, #0x3c] */
/* @0x17b0d0 add r1, pc, r1 */
/* @0x17b0d4 blx r12 */
/* @0x17b0d8 ldr r3, [r4] */
/* @0x17b0dc mov r1, r6 */
/* @0x17b0e0 mov r0, r4 */
/* @0x17b0e4 ldr r3, [r3, #0xc] */
/* @0x17b0e8 blx r3 */
/* @0x17b0ec add sp, sp, #8 */
/* @0x17b0f0 pop {r4, r5, r6, pc} */
/* @0x17b0f4 .word 0x00276bf8 */
/* @0x17b0f8 .word 0xffffbac4 */
/* @0x17b0fc andseq r0, sp, r12, lsr #10 */
/* @0x17b100 andseq r0, sp, r8, asr #10 */
/* @0x17b104 .word 0xffffe6e8 */
/* @0x17b108 .word 0xffffe6ec */
/* @0x17b10c .word 0xffffe6f0 */
/* @0x17b110 andseq r0, sp, r12, lsl r5 */

/* ── FUNC 0x17b114 · GraphicsPerf::BeginDebugDraw() · size=684 · insn=171 */
/* @0x17b114 push {r4, r5, r6, r7, r8, lr} */
/* @0x17b118 vpush {d8} */
/* @0x17b11c mov r6, #1 */
/* @0x17b120 ldr r4, [pc, #0x254] */
/* @0x17b124 sub sp, sp, #72 */
/* @0x17b128 ldr r3, [pc, #0x250] */
/* @0x17b12c vmov.f32 s16, #1.000000e+00 */
/* @0x17b130 add r4, pc, r4 */
/* @0x17b134 ldr r5, [r4, r3] */
/* @0x17b138 mov r0, r5 */
/* @0x17b13c bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv> */
/* @0x17b140 mov r1, r6 */
/* @0x17b144 mov r0, r5 */
/* @0x17b148 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x17b14c ldr r3, [pc, #0x230] */
/* @0x17b150 mov r1, #8 */
/* @0x17b154 ldr r3, [r4, r3] */
/* @0x17b158 adds r2, r0, #0 */
/* @0x17b15c mov r0, r5 */
/* @0x17b160 movne r2, #1 */
/* @0x17b164 strb r2, [r3] */
/* @0x17b168 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x17b16c ldr r3, [pc, #0x214] */
/* @0x17b170 mov r1, #21 */
/* @0x17b174 ldr r3, [r4, r3] */
/* @0x17b178 str r0, [r3] */
/* @0x17b17c mov r0, r5 */
/* @0x17b180 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x17b184 ldr r3, [pc, #0x200] */
/* @0x17b188 mov r1, #13 */
/* @0x17b18c ldr r3, [r4, r3] */
/* @0x17b190 adds r2, r0, #0 */
/* @0x17b194 mov r0, r5 */
/* @0x17b198 movne r2, #1 */
/* @0x17b19c strb r2, [r3] */
/* @0x17b1a0 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x17b1a4 ldr r3, [pc, #0x1e4] */
/* @0x17b1a8 ldr r2, [pc, #0x1e4] */
/* @0x17b1ac ldr r1, [pc, #0x1e4] */
/* @0x17b1b0 ldr r12, [r4, r3] */
/* @0x17b1b4 ldr r3, [pc, #0x1e0] */
/* @0x17b1b8 adds r0, r0, #0 */
/* @0x17b1bc movne r0, #1 */
/* @0x17b1c0 strb r0, [r12] */
/* @0x17b1c4 ldr r2, [r4, r2] */
/* @0x17b1c8 mov r0, r6 */
/* @0x17b1cc ldr r3, [r4, r3] */
/* @0x17b1d0 ldr r1, [r4, r1] */
/* @0x17b1d4 ldr r8, [r2] */
/* @0x17b1d8 ldr r7, [r3] */
/* @0x17b1dc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x17b1e0 ldr r3, [pc, #0x1b8] */
/* @0x17b1e4 mov r0, #0 */
/* @0x17b1e8 ldr r1, [r4, r3] */
/* @0x17b1ec bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x17b1f0 vmov s11, r8 */
/* @0x17b1f4 vmov s13, r7 */
/* @0x17b1f8 add r8, r8, r8, lsr #31 */
/* @0x17b1fc vcvt.f32.s32 s17, s11 */
/* @0x17b200 add r2, r7, r7, lsr #31 */
/* @0x17b204 asr r8, r8, r6 */
/* @0x17b208 add r1, sp, #8 */
/* @0x17b20c rsb r8, r8, #0 */
/* @0x17b210 asr r2, r2, r6 */
/* @0x17b214 rsb r2, r2, #0 */
/* @0x17b218 mov r0, #0 */
/* @0x17b21c vmov s11, r8 */
/* @0x17b220 mov r3, #0 */
/* @0x17b224 vstr s16, [sp, #68] */
/* @0x17b228 str r3, [sp, #0x34] */
/* @0x17b22c str r3, [sp, #0x2c] */
/* @0x17b230 vstr s16, [sp, #48] */
/* @0x17b234 vcvt.f32.s32 s15, s13 */
/* @0x17b238 str r3, [sp, #0x28] */
/* @0x17b23c str r3, [sp, #0x24] */
/* @0x17b240 vstr s16, [sp, #28] */
/* @0x17b244 str r3, [sp, #0x20] */
/* @0x17b248 vstr s16, [sp, #8] */
/* @0x17b24c str r3, [sp, #0x18] */
/* @0x17b250 mov r12, #0 */
/* @0x17b254 str r3, [sp, #0x14] */
/* @0x17b258 movt r12, #0x467a */
/* @0x17b25c str r3, [sp, #0x10] */
/* @0x17b260 str r3, [sp, #0xc] */
/* @0x17b264 vdiv.f32 s14, s16, s17 */
/* @0x17b268 str r12, [sp, #0x40] */
/* @0x17b26c vdiv.f32 s15, s16, s15 */
/* @0x17b270 vcvt.f32.s32 s12, s11 */
/* @0x17b274 vmov s11, r2 */
/* @0x17b278 vcvt.f32.s32 s13, s11 */
/* @0x17b27c vsub.f32 s14, s12, s14 */
/* @0x17b280 vadd.f32 s15, s13, s15 */
/* @0x17b284 vstr s14, [sp, #56] */
/* @0x17b288 vstr s15, [sp, #60] */
/* @0x17b28c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x17b290 ldr r1, [pc, #0x10c] */
/* @0x17b294 rsb r2, r7, #0 */
/* @0x17b298 ldr lr, [pc, #0x108] */
/* @0x17b29c mov r3, #0 */
/* @0x17b2a0 vmov s13, r2 */
/* @0x17b2a4 ldr r12, [pc, #0x100] */
/* @0x17b2a8 ldr r8, [r4, r1] */
/* @0x17b2ac movt r3, #0x46fa */
/* @0x17b2b0 vcvt.f32.s32 s13, s13 */
/* @0x17b2b4 ldr r0, [pc, #0xf4] */
/* @0x17b2b8 vmov r1, s17 */
/* @0x17b2bc strb r6, [r8] */
/* @0x17b2c0 ldr lr, [r4, lr] */
/* @0x17b2c4 vstr s16, [lr] */
/* @0x17b2c8 ldr r12, [r4, r12] */
/* @0x17b2cc str r3, [r12] */
/* @0x17b2d0 ldr r7, [r4, r0] */
/* @0x17b2d4 vmov r2, s13 */
/* @0x17b2d8 str r3, [sp] */
/* @0x17b2dc mov r0, r7 */
/* @0x17b2e0 vmov r3, s16 */
/* @0x17b2e4 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff> */
/* @0x17b2e8 mov r0, r6 */
/* @0x17b2ec mov r1, r7 */
/* @0x17b2f0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x17b2f4 mov r0, r5 */
/* @0x17b2f8 mov r1, #8 */
/* @0x17b2fc mov r2, #0 */
/* @0x17b300 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b304 mov r0, r5 */
/* @0x17b308 mov r1, r6 */
/* @0x17b30c mov r2, #0 */
/* @0x17b310 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b314 mov r0, r5 */
/* @0x17b318 mov r1, #21 */
/* @0x17b31c mov r2, #0 */
/* @0x17b320 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b324 mov r0, r5 */
/* @0x17b328 mov r1, #13 */
/* @0x17b32c mov r2, #0 */
/* @0x17b330 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b334 mov r2, r6 */
/* @0x17b338 mov r0, r5 */
/* @0x17b33c mov r1, #12 */
/* @0x17b340 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b344 ldr r3, [pc, #0x68] */
/* @0x17b348 mov r0, #2 */
/* @0x17b34c ldr r1, [r4, r3] */
/* @0x17b350 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x17b354 ldr r2, [pc, #0x5c] */
/* @0x17b358 ldr r3, [pc, #0x5c] */
/* @0x17b35c ldr r2, [r4, r2] */
/* @0x17b360 ldr r3, [r4, r3] */
/* @0x17b364 ldr r0, [r2] */
/* @0x17b368 ldr r1, [r3] */
/* @0x17b36c bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x17b370 add sp, sp, #72 */
/* @0x17b374 vpop {d8} */
/* @0x17b378 pop {r4, r5, r6, r7, r8, pc} */
/* @0x17b37c eoreq r6, r7, r0, lsr #22 */
/* @0x17b380 .word 0xffffc0a8 */
/* @0x17b384 .word 0xffffe6f4 */
/* @0x17b388 .word 0xffffe6f8 */
/* @0x17b38c .word 0xffffe6fc */
/* @0x17b390 .word 0xffffe700 */
/* @0x17b394 .word 0xffffe24c */
/* @0x17b398 .word 0xffffe704 */
/* @0x17b39c .word 0xffffe250 */
/* @0x17b3a0 .word 0xffffe708 */
/* @0x17b3a4 .word 0xffffe480 */
/* @0x17b3a8 .word 0xffffe484 */
/* @0x17b3ac .word 0xffffe488 */
/* @0x17b3b0 .word 0xffffe70c */
/* @0x17b3b4 .word 0xffffe710 */
/* @0x17b3b8 .word 0xffffe4d4 */
/* @0x17b3bc .word 0xffffe648 */

/* ── FUNC 0x17b3c0 · GraphicsPerf::SetDebugFont() · size=36 · insn=9 */
/* @0x17b3c0 ldr r2, [pc, #0x14] */
/* @0x17b3c4 ldr r3, [pc, #0x14] */
/* @0x17b3c8 ldr r2, [pc, r2] */
/* @0x17b3cc ldr r3, [pc, r3] */
/* @0x17b3d0 ldr r0, [r2] */
/* @0x17b3d4 ldr r1, [r3] */
/* @0x17b3d8 b 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x17b3dc eoreq r4, r7, r12, asr sp */
/* @0x17b3e0 eoreq r4, r7, r12, asr #29 */

/* ── FUNC 0x17b3e4 · GraphicsPerf::EndDebugDraw() · size=232 · insn=58 */
/* @0x17b3e4 push {r3, r4, r5, lr} */
/* @0x17b3e8 mov r1, #0 */
/* @0x17b3ec ldr r4, [pc, #0xb4] */
/* @0x17b3f0 ldr r3, [pc, #0xb4] */
/* @0x17b3f4 add r4, pc, r4 */
/* @0x17b3f8 ldr r3, [r4, r3] */
/* @0x17b3fc ldr r0, [r3] */
/* @0x17b400 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x17b404 ldr r2, [pc, #0xa4] */
/* @0x17b408 ldr r3, [pc, #0xa4] */
/* @0x17b40c mov r1, #8 */
/* @0x17b410 ldr r5, [r4, r2] */
/* @0x17b414 ldr r3, [r4, r3] */
/* @0x17b418 mov r0, r5 */
/* @0x17b41c ldr r2, [r3] */
/* @0x17b420 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b424 ldr r3, [pc, #0x8c] */
/* @0x17b428 mov r0, r5 */
/* @0x17b42c mov r1, #1 */
/* @0x17b430 ldr r3, [r4, r3] */
/* @0x17b434 ldrb r2, [r3] */
/* @0x17b438 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b43c ldr r3, [pc, #0x78] */
/* @0x17b440 mov r0, r5 */
/* @0x17b444 mov r1, #21 */
/* @0x17b448 ldr r3, [r4, r3] */
/* @0x17b44c ldrb r2, [r3] */
/* @0x17b450 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b454 ldr r3, [pc, #0x64] */
/* @0x17b458 mov r0, r5 */
/* @0x17b45c mov r1, #13 */
/* @0x17b460 ldr r3, [r4, r3] */
/* @0x17b464 ldrb r2, [r3] */
/* @0x17b468 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b46c mov r0, r5 */
/* @0x17b470 mov r2, #1 */
/* @0x17b474 mov r1, #12 */
/* @0x17b478 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x17b47c ldr r3, [pc, #0x40] */
/* @0x17b480 mov r0, #1 */
/* @0x17b484 ldr r1, [r4, r3] */
/* @0x17b488 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x17b48c ldr r3, [pc, #0x34] */
/* @0x17b490 mov r0, #0 */
/* @0x17b494 ldr r1, [r4, r3] */
/* @0x17b498 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x17b49c mov r0, r5 */
/* @0x17b4a0 pop {r3, r4, r5, lr} */
/* @0x17b4a4 b 0x168050 <_ZN18RenderStateManager13RestoreStatesEv> */
/* @0x17b4a8 eoreq r6, r7, r12, asr r8 */
/* @0x17b4ac .word 0xffffe4d4 */
/* @0x17b4b0 .word 0xffffc0a8 */
/* @0x17b4b4 .word 0xffffe6f8 */
/* @0x17b4b8 .word 0xffffe6f4 */
/* @0x17b4bc .word 0xffffe6fc */
/* @0x17b4c0 .word 0xffffe700 */
/* @0x17b4c4 .word 0xffffe704 */
/* @0x17b4c8 .word 0xffffe708 */
