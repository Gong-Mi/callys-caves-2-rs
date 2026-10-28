/* libyoyo.so 覆盖卡组 0143
 * 函数 0x1afa00..0x1b4a28，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1afa00 · CRoom::~CRoom() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1afef0 · CreateDefaultCamera() · size=44 · insn=11 */
/* @0x1afef0 ldr r0, [pc, #0x1c] */
/* @0x1afef4 push {r3, lr} */
/* @0x1afef8 ldr r0, [pc, r0] */
/* @0x1afefc bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv> */
/* @0x1aff00 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x1aff04 ldr r3, [pc, #0xc] */
/* @0x1aff08 ldr r3, [pc, r3] */
/* @0x1aff0c str r0, [r3] */
/* @0x1aff10 pop {r3, pc} */
/* @0x1aff14 eoreq sp, r3, r12, ror sp */
/* @0x1aff18 eoreq r0, r4, r4, asr r3 */

/* ── FUNC 0x1aff1c · UpdateDefaultCamera(float, float, float, float, float) · size=584 · insn=146 */
/* @0x1aff1c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1aff20 vpush {d8, d9, d10} */
/* @0x1aff24 vmov s20, r0 */
/* @0x1aff28 ldr r5, [pc, #0x214] */
/* @0x1aff2c vmov s19, r1 */
/* @0x1aff30 ldr r0, [pc, #0x210] */
/* @0x1aff34 sub sp, sp, #116 */
/* @0x1aff38 ldr r1, [pc, #0x20c] */
/* @0x1aff3c add r5, pc, r5 */
/* @0x1aff40 vmov s16, r2 */
/* @0x1aff44 vldr s17, [sp, #168] */
/* @0x1aff48 ldr r7, [r5, r0] */
/* @0x1aff4c vmov s18, r3 */
/* @0x1aff50 ldr r6, [r5, r1] */
/* @0x1aff54 mov r0, r7 */
/* @0x1aff58 ldr r1, [r6] */
/* @0x1aff5c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1aff60 subs r4, r0, #0 */
/* @0x1aff64 beq 0x1b00a0 <_Z19UpdateDefaultCamerafffff+0x184> */
/* @0x1aff68 bl 0x16d398 <_ZN7CCamera4Is2DEv> */
/* @0x1aff6c cmp r0, #0 */
/* @0x1aff70 bne 0x1b00ac <_Z19UpdateDefaultCamerafffff+0x190> */
/* @0x1aff74 vmov.f32 s15, #5.000000e-01 */
/* @0x1aff78 vldr s21, [pc, #448] */
/* @0x1aff7c mov r8, #0 */
/* @0x1aff80 str r8, [sp, #0x20] */
/* @0x1aff84 vmov.f32 s14, s20 */
/* @0x1aff88 vmov.f32 s13, s19 */
/* @0x1aff8c vmla.f32 s14, s16, s15 */
/* @0x1aff90 vmla.f32 s13, s18, s15 */
/* @0x1aff94 vstr s14, [sp, #12] */
/* @0x1aff98 vstr s14, [sp, #24] */
/* @0x1aff9c vnmul.f32 s15, s17, s21 */
/* @0x1affa0 vstr s13, [sp, #16] */
/* @0x1affa4 vstr s13, [sp, #28] */
/* @0x1affa8 vneg.f32 s14, s16 */
/* @0x1affac vmov r0, s15 */
/* @0x1affb0 vstr s14, [sp, #20] */
/* @0x1affb4 bl 0xb6580 <sinf@plt> */
/* @0x1affb8 vmul.f32 s21, s17, s21 */
/* @0x1affbc mov r9, r0 */
/* @0x1affc0 vmov r0, s21 */
/* @0x1affc4 bl 0xb658c <cosf@plt> */
/* @0x1affc8 str r8, [sp, #0x2c] */
/* @0x1affcc add r8, sp, #48 */
/* @0x1affd0 add r2, sp, #24 */
/* @0x1affd4 add r3, sp, #36 */
/* @0x1affd8 add r1, sp, #12 */
/* @0x1affdc str r9, [sp, #0x24] */
/* @0x1affe0 str r0, [sp, #0x28] */
/* @0x1affe4 mov r0, r8 */
/* @0x1affe8 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x1affec mov r0, r4 */
/* @0x1afff0 mov r1, r8 */
/* @0x1afff4 bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix> */
/* @0x1afff8 vdiv.f32 s15, s18, s16 */
/* @0x1afffc mov r3, #1065353216 */
/* @0x1b0000 mov r0, r8 */
/* @0x1b0004 mov r2, #0 */
/* @0x1b0008 movt r2, #0x46fa */
/* @0x1b000c str r2, [sp] */
/* @0x1b0010 vdiv.f32 s13, s16, s16 */
/* @0x1b0014 vneg.f32 s15, s15 */
/* @0x1b0018 vmov r1, s13 */
/* @0x1b001c vmov r2, s15 */
/* @0x1b0020 bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff> */
/* @0x1b0024 mov r1, r8 */
/* @0x1b0028 mov r0, r4 */
/* @0x1b002c bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix> */
/* @0x1b0030 mov r0, r4 */
/* @0x1b0034 bl 0x16d3bc <_ZN7CCamera13ApplyMatricesEv> */
/* @0x1b0038 ldr r0, [pc, #0x110] */
/* @0x1b003c ldr r1, [pc, #0x110] */
/* @0x1b0040 ldr r2, [pc, #0x110] */
/* @0x1b0044 ldr r3, [pc, #0x110] */
/* @0x1b0048 ldr r12, [pc, #0x110] */
/* @0x1b004c ldr r0, [r5, r0] */
/* @0x1b0050 vstr s20, [r0] */
/* @0x1b0054 vmov r0, s20 */
/* @0x1b0058 ldr r1, [r5, r1] */
/* @0x1b005c vstr s19, [r1] */
/* @0x1b0060 vmov r1, s19 */
/* @0x1b0064 ldr r2, [r5, r2] */
/* @0x1b0068 vstr s16, [r2] */
/* @0x1b006c vmov r2, s16 */
/* @0x1b0070 ldr r3, [r5, r3] */
/* @0x1b0074 vstr s18, [r3] */
/* @0x1b0078 vmov r3, s18 */
/* @0x1b007c ldr r12, [r5, r12] */
/* @0x1b0080 vstr s17, [sp] */
/* @0x1b0084 vstr s17, [r12] */
/* @0x1b0088 bl 0x1692e4 <_Z14SetViewExtentsfffff> */
/* @0x1b008c mov r0, r7 */
/* @0x1b0090 ldr r1, [r6] */
/* @0x1b0094 bl 0x1707c8 <_ZN14CCameraManager15SetActiveCameraEi> */
/* @0x1b0098 mov r0, r4 */
/* @0x1b009c bl 0x16d3bc <_ZN7CCamera13ApplyMatricesEv> */
/* @0x1b00a0 add sp, sp, #116 */
/* @0x1b00a4 vpop {d8, d9, d10} */
/* @0x1b00a8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b00ac mov r0, r4 */
/* @0x1b00b0 vmov r1, s20 */
/* @0x1b00b4 bl 0x16d29c <_ZN7CCamera8SetViewXEf> */
/* @0x1b00b8 mov r0, r4 */
/* @0x1b00bc vmov r1, s19 */
/* @0x1b00c0 bl 0x16d2ac <_ZN7CCamera8SetViewYEf> */
/* @0x1b00c4 mov r0, r4 */
/* @0x1b00c8 vmov r1, s16 */
/* @0x1b00cc bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf> */
/* @0x1b00d0 mov r0, r4 */
/* @0x1b00d4 vmov r1, s18 */
/* @0x1b00d8 bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf> */
/* @0x1b00dc vmov r1, s17 */
/* @0x1b00e0 mov r0, r4 */
/* @0x1b00e4 vmov.f32 s17, #5.000000e-01 */
/* @0x1b00e8 bl 0x16d31c <_ZN7CCamera12SetViewAngleEf> */
/* @0x1b00ec mov r0, r4 */
/* @0x1b00f0 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv> */
/* @0x1b00f4 vmov s16, r0 */
/* @0x1b00f8 mov r0, r4 */
/* @0x1b00fc bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv> */
/* @0x1b0100 vmov s13, r0 */
/* @0x1b0104 mov r0, r4 */
/* @0x1b0108 vmla.f32 s16, s13, s17 */
/* @0x1b010c bl 0x16d2b4 <_ZN7CCamera8GetViewYEv> */
/* @0x1b0110 vmov s18, r0 */
/* @0x1b0114 mov r0, r4 */
/* @0x1b0118 bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv> */
/* @0x1b011c vmov r1, s16 */
/* @0x1b0120 vmov s15, r0 */
/* @0x1b0124 mov r0, r4 */
/* @0x1b0128 vmla.f32 s18, s15, s17 */
/* @0x1b012c vmov r2, s18 */
/* @0x1b0130 bl 0x16db44 <_ZN7CCamera11Build2DViewEff> */
/* @0x1b0134 mov r0, r4 */
/* @0x1b0138 bl 0x16d3bc <_ZN7CCamera13ApplyMatricesEv> */
/* @0x1b013c b 0x1b008c <_Z19UpdateDefaultCamerafffff+0x170> */
/* @0x1b0140 vstmialo lr, {s30, s31} */
/* @0x1b0144 eoreq r1, r4, r4, lsl sp */
/* @0x1b0148 .word 0xffffc024 */
/* @0x1b014c .word 0xffffe60c */
/* @0x1b0150 .word 0xffffe504 */
/* @0x1b0154 .word 0xffffe508 */
/* @0x1b0158 .word 0xffffe50c */
/* @0x1b015c .word 0xffffe510 */
/* @0x1b0160 .word 0xffffe514 */

/* ── FUNC 0x1b0164 · UpdateViews() · size=1340 · insn=335 */
/* @0x1b0164 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b0168 vpush {d8, d9, d10} */
/* @0x1b016c sub sp, sp, #44 */
/* @0x1b0170 ldr r6, [pc, #0x418] */
/* @0x1b0174 ldr r3, [pc, #0x418] */
/* @0x1b0178 add r6, pc, r6 */
/* @0x1b017c ldr r7, [r6, r3] */
/* @0x1b0180 ldr r2, [r7] */
/* @0x1b0184 ldrb r4, [r2, #0x44] */
/* @0x1b0188 cmp r4, #0 */
/* @0x1b018c beq 0x1b035c <_Z11UpdateViewsv+0x1f8> */
/* @0x1b0190 vmov.f32 s18, #5.000000e-01 */
/* @0x1b0194 movw r8, #0x869f */
/* @0x1b0198 movt r8, #0x1 */
/* @0x1b019c mov r9, #0 */
/* @0x1b01a0 vldr s16, [pc, #996] */
/* @0x1b01a4 add r3, r9, #18 */
/* @0x1b01a8 ldr r4, [r2, r3, lsl #2] */
/* @0x1b01ac ldrb r3, [r4] */
/* @0x1b01b0 cmp r3, #0 */
/* @0x1b01b4 beq 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b01b8 ldr r3, [pc, #0x3d8] */
/* @0x1b01bc ldr r3, [r6, r3] */
/* @0x1b01c0 ldrb r3, [r3] */
/* @0x1b01c4 cmp r3, #0 */
/* @0x1b01c8 beq 0x1b0374 <_Z11UpdateViewsv+0x210> */
/* @0x1b01cc ldr r1, [r4, #0x40] */
/* @0x1b01d0 cmn r1, #1 */
/* @0x1b01d4 beq 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b01d8 ldr r3, [pc, #0x3bc] */
/* @0x1b01dc ldr r0, [r6, r3] */
/* @0x1b01e0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1b01e4 cmp r0, #0 */
/* @0x1b01e8 beq 0x1b01f0 <_Z11UpdateViewsv+0x8c> */
/* @0x1b01ec bl 0x170b30 <_ZN7CCamera12CameraUpdateEv> */
/* @0x1b01f0 ldr r2, [r7] */
/* @0x1b01f4 add r9, r9, #1 */
/* @0x1b01f8 cmp r9, #8 */
/* @0x1b01fc bne 0x1b01a4 <_Z11UpdateViewsv+0x40> */
/* @0x1b0200 movw r9, #0xbdc1 */
/* @0x1b0204 movw r8, #0x423f */
/* @0x1b0208 movt r9, #0xfff0 */
/* @0x1b020c movt r8, #0xf */
/* @0x1b0210 mov r5, #0 */
/* @0x1b0214 mov r11, r9 */
/* @0x1b0218 mov r10, r8 */
/* @0x1b021c b 0x1b0224 <_Z11UpdateViewsv+0xc0> */
/* @0x1b0220 ldr r2, [r7] */
/* @0x1b0224 add r3, r5, #18 */
/* @0x1b0228 mov r0, r5 */
/* @0x1b022c ldr r4, [r2, r3, lsl #2] */
/* @0x1b0230 bl 0x179cac <_Z23GR_Window_View_UnDefinei> */
/* @0x1b0234 mov r0, r5 */
/* @0x1b0238 add r5, r5, #1 */
/* @0x1b023c ldrb r3, [r4] */
/* @0x1b0240 cmp r3, #0 */
/* @0x1b0244 beq 0x1b02f0 <_Z11UpdateViewsv+0x18c> */
/* @0x1b0248 vldr s9, [r4, #32] */
/* @0x1b024c vcvt.f32.s32 s15, s9 */
/* @0x1b0250 ldr r1, [r4, #0x14] */
/* @0x1b0254 ldr r3, [r4, #0x1c] */
/* @0x1b0258 ldr r2, [r4, #0x18] */
/* @0x1b025c cmp r10, r1 */
/* @0x1b0260 movge r10, r1 */
/* @0x1b0264 add r12, r1, r3 */
/* @0x1b0268 vmov s10, r1 */
/* @0x1b026c cmp r11, r12 */
/* @0x1b0270 movlt r11, r12 */
/* @0x1b0274 str r3, [sp, #0x20] */
/* @0x1b0278 vmov r3, s9 */
/* @0x1b027c vldr s14, [sp, #32] */
/* @0x1b0280 vstr s15, [sp] */
/* @0x1b0284 ldr r12, [r4, #0x4] */
/* @0x1b0288 vmov s9, r2 */
/* @0x1b028c cmp r8, r2 */
/* @0x1b0290 movge r8, r2 */
/* @0x1b0294 vcvt.f32.s32 s10, s10 */
/* @0x1b0298 str r12, [sp, #0x4] */
/* @0x1b029c ldr r12, [r4, #0x8] */
/* @0x1b02a0 str r12, [sp, #0x8] */
/* @0x1b02a4 ldr r12, [r4, #0xc] */
/* @0x1b02a8 vcvt.f32.s32 s9, s9 */
/* @0x1b02ac vmov r1, s10 */
/* @0x1b02b0 str r12, [sp, #0xc] */
/* @0x1b02b4 ldr r12, [r4, #0x10] */
/* @0x1b02b8 str r12, [sp, #0x10] */
/* @0x1b02bc ldr r12, [r4, #0x24] */
/* @0x1b02c0 vcvt.f32.s32 s14, s14 */
/* @0x1b02c4 str r12, [sp, #0x14] */
/* @0x1b02c8 add lr, r2, r3 */
/* @0x1b02cc ldr r12, [r4, #0x3c] */
/* @0x1b02d0 cmp r9, lr */
/* @0x1b02d4 movlt r9, lr */
/* @0x1b02d8 vmov r2, s9 */
/* @0x1b02dc str r12, [sp, #0x18] */
/* @0x1b02e0 ldr r12, [r4, #0x40] */
/* @0x1b02e4 vmov r3, s14 */
/* @0x1b02e8 str r12, [sp, #0x1c] */
/* @0x1b02ec bl 0x179bfc <_Z21GR_Window_View_Defineifffffffffii> */
/* @0x1b02f0 cmp r5, #8 */
/* @0x1b02f4 bne 0x1b0220 <_Z11UpdateViewsv+0xbc> */
/* @0x1b02f8 rsb r10, r10, r11 */
/* @0x1b02fc ldr r1, [pc, #0x29c] */
/* @0x1b0300 rsb r8, r8, r9 */
/* @0x1b0304 ldr r3, [pc, #0x298] */
/* @0x1b0308 vmov s15, r10 */
/* @0x1b030c ldr r2, [pc, #0x294] */
/* @0x1b0310 ldr r0, [r6, r1] */
/* @0x1b0314 vldr s13, [r0] */
/* @0x1b0318 vcvt.f32.s32 s12, s15 */
/* @0x1b031c ldr r1, [r6, r3] */
/* @0x1b0320 vmov s9, r8 */
/* @0x1b0324 ldr r3, [pc, #0x280] */
/* @0x1b0328 vcvt.f32.s32 s13, s13 */
/* @0x1b032c vdiv.f32 s13, s13, s12 */
/* @0x1b0330 vcvt.f32.s32 s14, s9 */
/* @0x1b0334 vstr s13, [r1] */
/* @0x1b0338 ldr r2, [r6, r2] */
/* @0x1b033c vldr s15, [r2] */
/* @0x1b0340 ldr r3, [r6, r3] */
/* @0x1b0344 vcvt.f32.s32 s15, s15 */
/* @0x1b0348 vdiv.f32 s15, s15, s14 */
/* @0x1b034c vstr s15, [r3] */
/* @0x1b0350 add sp, sp, #44 */
/* @0x1b0354 vpop {d8, d9, d10} */
/* @0x1b0358 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b035c mov r0, r4 */
/* @0x1b0360 add r4, r4, #1 */
/* @0x1b0364 bl 0x179cac <_Z23GR_Window_View_UnDefinei> */
/* @0x1b0368 cmp r4, #8 */
/* @0x1b036c bne 0x1b035c <_Z11UpdateViewsv+0x1f8> */
/* @0x1b0370 b 0x1b0350 <_Z11UpdateViewsv+0x1ec> */
/* @0x1b0374 ldr r0, [r4, #0x38] */
/* @0x1b0378 cmp r0, r8 */
/* @0x1b037c bgt 0x1b0628 <_Z11UpdateViewsv+0x4c4> */
/* @0x1b0380 ldr r3, [pc, #0x228] */
/* @0x1b0384 ldr r3, [r6, r3] */
/* @0x1b0388 ldr r3, [r3] */
/* @0x1b038c ldr r1, [r3, #0x4] */
/* @0x1b0390 ldr r3, [r3] */
/* @0x1b0394 and r1, r0, r1 */
/* @0x1b0398 ldr r3, [r3, r1, lsl #3] */
/* @0x1b039c cmp r3, #0 */
/* @0x1b03a0 bne 0x1b03b4 <_Z11UpdateViewsv+0x250> */
/* @0x1b03a4 b 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b03a8 ldr r3, [r3, #0x4] */
/* @0x1b03ac cmp r3, #0 */
/* @0x1b03b0 beq 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b03b4 ldr r1, [r3, #0x8] */
/* @0x1b03b8 cmp r0, r1 */
/* @0x1b03bc bne 0x1b03a8 <_Z11UpdateViewsv+0x244> */
/* @0x1b03c0 ldr r3, [r3, #0xc] */
/* @0x1b03c4 cmp r3, #0 */
/* @0x1b03c8 ldrne r3, [r3, #0xd0] */
/* @0x1b03cc beq 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b03d0 cmp r3, #0 */
/* @0x1b03d4 beq 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b03d8 ldr r1, [r3, #0x8] */
/* @0x1b03dc cmp r1, #0 */
/* @0x1b03e0 beq 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b03e4 ldr r5, [r3, #0x8] */
/* @0x1b03e8 ldr r3, [r3] */
/* @0x1b03ec ldrb r1, [r5, #0x68] */
/* @0x1b03f0 cmp r1, #0 */
/* @0x1b03f4 bne 0x1b03d0 <_Z11UpdateViewsv+0x26c> */
/* @0x1b03f8 ldrb r1, [r5, #0x69] */
/* @0x1b03fc cmp r1, #0 */
/* @0x1b0400 bne 0x1b03d0 <_Z11UpdateViewsv+0x26c> */
/* @0x1b0404 ldrb r3, [r5, #0x64] */
/* @0x1b0408 vldr s20, [r4, #4] */
/* @0x1b040c vldr s19, [r4, #8] */
/* @0x1b0410 cmp r3, #0 */
/* @0x1b0414 bne 0x1b068c <_Z11UpdateViewsv+0x528> */
/* @0x1b0418 ldr r0, [r5, #0xb4] */
/* @0x1b041c str r2, [sp, #0x24] */
/* @0x1b0420 bl 0xb6910 <floorf@plt> */
/* @0x1b0424 vmov s17, r0 */
/* @0x1b0428 ldr r0, [r5, #0xb8] */
/* @0x1b042c bl 0xb6910 <floorf@plt> */
/* @0x1b0430 ldr r3, [r4, #0x28] */
/* @0x1b0434 vldr s12, [r4, #12] */
/* @0x1b0438 ldr r2, [sp, #0x24] */
/* @0x1b043c lsl r1, r3, #1 */
/* @0x1b0440 vmov s15, r1 */
/* @0x1b0444 vcvt.f32.s32 s15, s15 */
/* @0x1b0448 vcmpe.f32 s15, s12 */
/* @0x1b044c vmrs APSR_nzcv, fpscr */
/* @0x1b0450 vmov s11, r0 */
/* @0x1b0454 blt 0x1b05f0 <_Z11UpdateViewsv+0x48c> */
/* @0x1b0458 vmov.f32 s14, s17 */
/* @0x1b045c vmls.f32 s14, s12, s18 */
/* @0x1b0460 ldr r3, [r4, #0x2c] */
/* @0x1b0464 vldr s13, [r4, #16] */
/* @0x1b0468 lsl r1, r3, #1 */
/* @0x1b046c vmov s15, r1 */
/* @0x1b0470 vcvt.f32.s32 s15, s15 */
/* @0x1b0474 vcmpe.f32 s15, s13 */
/* @0x1b0478 vmrs APSR_nzcv, fpscr */
/* @0x1b047c blt 0x1b05b8 <_Z11UpdateViewsv+0x454> */
/* @0x1b0480 vmov.f32 s15, s11 */
/* @0x1b0484 vmls.f32 s15, s13, s18 */
/* @0x1b0488 vldr s9, [r2, #16] */
/* @0x1b048c ldr r3, [r4, #0x30] */
/* @0x1b0490 vcmp.f32 s14, #0 */
/* @0x1b0494 vmrs APSR_nzcv, fpscr */
/* @0x1b0498 vmovmi.f32 s14, s16 */
/* @0x1b049c vadd.f32 s10, s14, s12 */
/* @0x1b04a0 vcvt.f32.s32 s11, s9 */
/* @0x1b04a4 vcmpe.f32 s10, s11 */
/* @0x1b04a8 vldr s10, [r2, #20] */
/* @0x1b04ac vmrs APSR_nzcv, fpscr */
/* @0x1b04b0 vcmp.f32 s15, #0 */
/* @0x1b04b4 vsubgt.f32 s14, s11, s12 */
/* @0x1b04b8 vmrs APSR_nzcv, fpscr */
/* @0x1b04bc vmovmi.f32 s15, s16 */
/* @0x1b04c0 vadd.f32 s11, s15, s13 */
/* @0x1b04c4 vcvt.f32.s32 s12, s10 */
/* @0x1b04c8 vcmpe.f32 s11, s12 */
/* @0x1b04cc vmrs APSR_nzcv, fpscr */
/* @0x1b04d0 vsubgt.f32 s15, s12, s13 */
/* @0x1b04d4 cmp r3, #0 */
/* @0x1b04d8 blt 0x1b0528 <_Z11UpdateViewsv+0x3c4> */
/* @0x1b04dc vldr s13, [r4, #4] */
/* @0x1b04e0 vcmpe.f32 s14, s13 */
/* @0x1b04e4 vmrs APSR_nzcv, fpscr */
/* @0x1b04e8 bpl 0x1b0504 <_Z11UpdateViewsv+0x3a0> */
/* @0x1b04ec vsub.f32 s11, s13, s14 */
/* @0x1b04f0 vmov s9, r3 */
/* @0x1b04f4 vcvt.f32.s32 s12, s9 */
/* @0x1b04f8 vcmpe.f32 s11, s12 */
/* @0x1b04fc vmrs APSR_nzcv, fpscr */
/* @0x1b0500 vsubgt.f32 s14, s13, s12 */
/* @0x1b0504 vcmpe.f32 s14, s13 */
/* @0x1b0508 vmrs APSR_nzcv, fpscr */
/* @0x1b050c ble 0x1b0528 <_Z11UpdateViewsv+0x3c4> */
/* @0x1b0510 vsub.f32 s11, s14, s13 */
/* @0x1b0514 vmov s10, r3 */
/* @0x1b0518 vcvt.f32.s32 s12, s10 */
/* @0x1b051c vcmpe.f32 s11, s12 */
/* @0x1b0520 vmrs APSR_nzcv, fpscr */
/* @0x1b0524 vaddgt.f32 s14, s13, s12 */
/* @0x1b0528 ldr r3, [r4, #0x34] */
/* @0x1b052c cmp r3, #0 */
/* @0x1b0530 blt 0x1b0580 <_Z11UpdateViewsv+0x41c> */
/* @0x1b0534 vldr s13, [r4, #8] */
/* @0x1b0538 vcmpe.f32 s15, s13 */
/* @0x1b053c vmrs APSR_nzcv, fpscr */
/* @0x1b0540 bpl 0x1b055c <_Z11UpdateViewsv+0x3f8> */
/* @0x1b0544 vsub.f32 s11, s13, s15 */
/* @0x1b0548 vmov s9, r3 */
/* @0x1b054c vcvt.f32.s32 s12, s9 */
/* @0x1b0550 vcmpe.f32 s11, s12 */
/* @0x1b0554 vmrs APSR_nzcv, fpscr */
/* @0x1b0558 vsubgt.f32 s15, s13, s12 */
/* @0x1b055c vcmpe.f32 s15, s13 */
/* @0x1b0560 vmrs APSR_nzcv, fpscr */
/* @0x1b0564 ble 0x1b0580 <_Z11UpdateViewsv+0x41c> */
/* @0x1b0568 vsub.f32 s11, s15, s13 */
/* @0x1b056c vmov s10, r3 */
/* @0x1b0570 vcvt.f32.s32 s12, s10 */
/* @0x1b0574 vcmpe.f32 s11, s12 */
/* @0x1b0578 vmrs APSR_nzcv, fpscr */
/* @0x1b057c vaddgt.f32 s15, s13, s12 */
/* @0x1b0580 vstr s14, [r4, #4] */
/* @0x1b0584 vstr s15, [r4, #8] */
/* @0x1b0588 b 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b058c andeq r0, r0, r0 */
/* @0x1b0590 .word 0x00241ad8 */
/* @0x1b0594 .word 0xffffbcd8 */
/* @0x1b0598 .word 0xffffbcd4 */
/* @0x1b059c .word 0xffffc024 */
/* @0x1b05a0 .word 0xffffdf38 */
/* @0x1b05a4 .word 0xffffe6bc */
/* @0x1b05a8 .word 0xffffdf40 */
/* @0x1b05ac .word 0xffffe6c4 */
/* @0x1b05b0 .word 0xffffbfec */
/* @0x1b05b4 .word 0xffffbff4 */
/* @0x1b05b8 vmov s10, r3 */
/* @0x1b05bc vcvt.f32.s32 s9, s10 */
/* @0x1b05c0 vldr s10, [r4, #8] */
/* @0x1b05c4 vsub.f32 s15, s11, s9 */
/* @0x1b05c8 vcmpe.f32 s15, s10 */
/* @0x1b05cc vmrs APSR_nzcv, fpscr */
/* @0x1b05d0 bmi 0x1b0488 <_Z11UpdateViewsv+0x324> */
/* @0x1b05d4 vadd.f32 s11, s9, s11 */
/* @0x1b05d8 vadd.f32 s10, s13, s10 */
/* @0x1b05dc vcmpe.f32 s11, s10 */
/* @0x1b05e0 vmrs APSR_nzcv, fpscr */
/* @0x1b05e4 vsubgt.f32 s15, s11, s13 */
/* @0x1b05e8 vmovle.f32 s15, s19 */
/* @0x1b05ec b 0x1b0488 <_Z11UpdateViewsv+0x324> */
/* @0x1b05f0 vmov s9, r3 */
/* @0x1b05f4 vldr s15, [r4, #4] */
/* @0x1b05f8 vcvt.f32.s32 s13, s9 */
/* @0x1b05fc vsub.f32 s14, s17, s13 */
/* @0x1b0600 vcmpe.f32 s14, s15 */
/* @0x1b0604 vmrs APSR_nzcv, fpscr */
/* @0x1b0608 bmi 0x1b0460 <_Z11UpdateViewsv+0x2fc> */
/* @0x1b060c vadd.f32 s13, s13, s17 */
/* @0x1b0610 vadd.f32 s15, s12, s15 */
/* @0x1b0614 vcmpe.f32 s13, s15 */
/* @0x1b0618 vmrs APSR_nzcv, fpscr */
/* @0x1b061c vsubgt.f32 s14, s13, s12 */
/* @0x1b0620 vmovle.f32 s14, s20 */
/* @0x1b0624 b 0x1b0460 <_Z11UpdateViewsv+0x2fc> */
/* @0x1b0628 ldr r3, [pc, #-0x7c] */
/* @0x1b062c ldr r3, [r6, r3] */
/* @0x1b0630 ldr r1, [r3, #0x4] */
/* @0x1b0634 ldr r3, [r3] */
/* @0x1b0638 and r1, r0, r1 */
/* @0x1b063c ldr r3, [r3, r1, lsl #3] */
/* @0x1b0640 cmp r3, #0 */
/* @0x1b0644 bne 0x1b0658 <_Z11UpdateViewsv+0x4f4> */
/* @0x1b0648 b 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b064c ldr r3, [r3, #0x4] */
/* @0x1b0650 cmp r3, #0 */
/* @0x1b0654 beq 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b0658 ldr r1, [r3, #0x8] */
/* @0x1b065c cmp r0, r1 */
/* @0x1b0660 bne 0x1b064c <_Z11UpdateViewsv+0x4e8> */
/* @0x1b0664 ldr r5, [r3, #0xc] */
/* @0x1b0668 cmp r5, #0 */
/* @0x1b066c beq 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b0670 ldrb r3, [r5, #0x68] */
/* @0x1b0674 cmp r3, #0 */
/* @0x1b0678 bne 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b067c ldrb r3, [r5, #0x69] */
/* @0x1b0680 cmp r3, #0 */
/* @0x1b0684 bne 0x1b01f4 <_Z11UpdateViewsv+0x90> */
/* @0x1b0688 b 0x1b0404 <_Z11UpdateViewsv+0x2a0> */
/* @0x1b068c mov r0, r5 */
/* @0x1b0690 mov r1, #1 */
/* @0x1b0694 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1b0698 ldr r2, [r7] */
/* @0x1b069c b 0x1b0418 <_Z11UpdateViewsv+0x2b4> */

/* ── FUNC 0x1b06a0 · DoSlowDrawRoom(tagYYRECT*) · size=1124 · insn=281 */
/* @0x1b06a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b06a4 vpush {d8, d9, d10, d11} */
/* @0x1b06a8 sub sp, sp, #44 */
/* @0x1b06ac vldr s17, [pc, #980] */
/* @0x1b06b0 mov r9, r0 */
/* @0x1b06b4 bl 0x1a570c <_Z27ParticleSystem_LargestDepthv> */
/* @0x1b06b8 ldr r7, [pc, #0x3d0] */
/* @0x1b06bc vmov.f32 s21, #1.000000e+00 */
/* @0x1b06c0 ldr r3, [pc, #0x3cc] */
/* @0x1b06c4 mov r5, #0 */
/* @0x1b06c8 add r7, pc, r7 */
/* @0x1b06cc mov r11, r5 */
/* @0x1b06d0 mov r8, r5 */
/* @0x1b06d4 mvn r10, #-16777216 */
/* @0x1b06d8 ldr r6, [r7, r3] */
/* @0x1b06dc vldr s20, [pc, #936] */
/* @0x1b06e0 ldr r3, [r6] */
/* @0x1b06e4 ldr r4, [r3, #0x84] */
/* @0x1b06e8 mov r1, r3 */
/* @0x1b06ec ldr r3, [r3, #0xb8] */
/* @0x1b06f0 vmov s16, r0 */
/* @0x1b06f4 cmp r5, r3 */
/* @0x1b06f8 bge 0x1b08d4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x234> */
/* @0x1b06fc rsb r12, r5, r5, lsl #3 */
/* @0x1b0700 ldr r2, [r1, #0xc0] */
/* @0x1b0704 cmp r4, #0 */
/* @0x1b0708 add r11, r2, r12, lsl #3 */
/* @0x1b070c beq 0x1b09b0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x310> */
/* @0x1b0710 ldrb r2, [r4, #0x68] */
/* @0x1b0714 cmp r2, #0 */
/* @0x1b0718 bne 0x1b09a8 <_Z14DoSlowDrawRoomP9tagYYRECT+0x308> */
/* @0x1b071c ldrb r2, [r4, #0x69] */
/* @0x1b0720 cmp r2, #0 */
/* @0x1b0724 bne 0x1b09a8 <_Z14DoSlowDrawRoomP9tagYYRECT+0x308> */
/* @0x1b0728 ldrb r2, [r4, #0x65] */
/* @0x1b072c cmp r2, #0 */
/* @0x1b0730 beq 0x1b09a8 <_Z14DoSlowDrawRoomP9tagYYRECT+0x308> */
/* @0x1b0734 cmp r5, r3 */
/* @0x1b0738 blt 0x1b09b0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x310> */
/* @0x1b073c cmp r4, #0 */
/* @0x1b0740 beq 0x1b08e8 <_Z14DoSlowDrawRoomP9tagYYRECT+0x248> */
/* @0x1b0744 vldr s15, [r4, #384] */
/* @0x1b0748 vcmpe.f32 s16, s15 */
/* @0x1b074c vmrs APSR_nzcv, fpscr */
/* @0x1b0750 bgt 0x1b08e8 <_Z14DoSlowDrawRoomP9tagYYRECT+0x248> */
/* @0x1b0754 cmp r5, r3 */
/* @0x1b0758 bge 0x1b0940 <_Z14DoSlowDrawRoomP9tagYYRECT+0x2a0> */
/* @0x1b075c vldr s14, [r11, #28] */
/* @0x1b0760 vcmpe.f32 s14, s15 */
/* @0x1b0764 vmrs APSR_nzcv, fpscr */
/* @0x1b0768 ble 0x1b0940 <_Z14DoSlowDrawRoomP9tagYYRECT+0x2a0> */
/* @0x1b076c vcmpe.f32 s14, s17 */
/* @0x1b0770 vmrs APSR_nzcv, fpscr */
/* @0x1b0774 vmovle r0, s14 */
/* @0x1b0778 vmovgt r0, s17 */
/* @0x1b077c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b0780 vldr s13, [r11, #20] */
/* @0x1b0784 vcvt.f32.s32 s11, s13 */
/* @0x1b0788 vldr s14, [r11] */
/* @0x1b078c vldr s12, [r11, #36] */
/* @0x1b0790 vldr s15, [r11, #4] */
/* @0x1b0794 vldr s13, [r11, #40] */
/* @0x1b0798 ldr r0, [r11, #0x8] */
/* @0x1b079c vmov.f32 s18, s14 */
/* @0x1b07a0 vmla.f32 s18, s11, s12 */
/* @0x1b07a4 vldr s11, [r11, #24] */
/* @0x1b07a8 vcvt.f32.s32 s12, s11 */
/* @0x1b07ac vmov.f32 s19, s15 */
/* @0x1b07b0 vmla.f32 s19, s12, s13 */
/* @0x1b07b4 vcmpe.f32 s14, s18 */
/* @0x1b07b8 vmrs APSR_nzcv, fpscr */
/* @0x1b07bc vcmp.f32 s14, s18 */
/* @0x1b07c0 vmovpl.f32 s22, s18 */
/* @0x1b07c4 vmovmi.f32 s22, s14 */
/* @0x1b07c8 vmrs APSR_nzcv, fpscr */
/* @0x1b07cc vcmpe.f32 s15, s19 */
/* @0x1b07d0 vmovgt.f32 s18, s14 */
/* @0x1b07d4 vmrs APSR_nzcv, fpscr */
/* @0x1b07d8 vcmp.f32 s15, s19 */
/* @0x1b07dc vmovpl.f32 s23, s19 */
/* @0x1b07e0 vmovmi.f32 s23, s15 */
/* @0x1b07e4 vmrs APSR_nzcv, fpscr */
/* @0x1b07e8 vmovgt.f32 s19, s15 */
/* @0x1b07ec bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1b07f0 cmp r0, #0 */
/* @0x1b07f4 beq 0x1b08c0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x220> */
/* @0x1b07f8 vldr s11, [r9, #8] */
/* @0x1b07fc vcvt.f32.s32 s15, s11 */
/* @0x1b0800 vcmpe.f32 s22, s15 */
/* @0x1b0804 vmrs APSR_nzcv, fpscr */
/* @0x1b0808 bhi 0x1b08c0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x220> */
/* @0x1b080c vldr s13, [r9, #12] */
/* @0x1b0810 vcvt.f32.s32 s15, s13 */
/* @0x1b0814 vcmpe.f32 s23, s15 */
/* @0x1b0818 vmrs APSR_nzcv, fpscr */
/* @0x1b081c bhi 0x1b08c0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x220> */
/* @0x1b0820 vldr s14, [r9] */
/* @0x1b0824 vcvt.f32.s32 s15, s14 */
/* @0x1b0828 vcmpe.f32 s18, s15 */
/* @0x1b082c vmrs APSR_nzcv, fpscr */
/* @0x1b0830 blt 0x1b08c0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x220> */
/* @0x1b0834 vldr s11, [r9, #4] */
/* @0x1b0838 vcvt.f32.s32 s15, s11 */
/* @0x1b083c vcmpe.f32 s19, s15 */
/* @0x1b0840 vmrs APSR_nzcv, fpscr */
/* @0x1b0844 blt 0x1b08c0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x220> */
/* @0x1b0848 ldr r0, [r11, #0x8] */
/* @0x1b084c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1b0850 vldr s13, [r11, #24] */
/* @0x1b0854 vcvt.f32.s32 s15, s13 */
/* @0x1b0858 ldr r1, [r11, #0xc] */
/* @0x1b085c ldr r2, [r11, #0x10] */
/* @0x1b0860 ldr r3, [r11, #0x14] */
/* @0x1b0864 vmov s14, r1 */
/* @0x1b0868 vmov s11, r3 */
/* @0x1b086c vstr s15, [sp] */
/* @0x1b0870 vmov s15, r2 */
/* @0x1b0874 ldr lr, [r11] */
/* @0x1b0878 vcvt.f32.s32 s14, s14 */
/* @0x1b087c str lr, [sp, #0x4] */
/* @0x1b0880 ldr lr, [r11, #0x4] */
/* @0x1b0884 str lr, [sp, #0x8] */
/* @0x1b0888 vcvt.f32.s32 s15, s15 */
/* @0x1b088c ldr lr, [r11, #0x24] */
/* @0x1b0890 vmov r1, s14 */
/* @0x1b0894 str lr, [sp, #0xc] */
/* @0x1b0898 ldr lr, [r11, #0x28] */
/* @0x1b089c vcvt.f32.s32 s11, s11 */
/* @0x1b08a0 str lr, [sp, #0x10] */
/* @0x1b08a4 ldr lr, [r11, #0x2c] */
/* @0x1b08a8 vmov r2, s15 */
/* @0x1b08ac str lr, [sp, #0x14] */
/* @0x1b08b0 ldr lr, [r11, #0x30] */
/* @0x1b08b4 vmov r3, s11 */
/* @0x1b08b8 str lr, [sp, #0x18] */
/* @0x1b08bc bl 0xc2184 <_ZN11CBackground8DrawPartEffffffffjf> */
/* @0x1b08c0 ldr r1, [r6] */
/* @0x1b08c4 add r5, r5, #1 */
/* @0x1b08c8 ldr r3, [r1, #0xb8] */
/* @0x1b08cc cmp r5, r3 */
/* @0x1b08d0 blt 0x1b06fc <_Z14DoSlowDrawRoomP9tagYYRECT+0x5c> */
/* @0x1b08d4 cmp r4, #0 */
/* @0x1b08d8 bne 0x1b0710 <_Z14DoSlowDrawRoomP9tagYYRECT+0x70> */
/* @0x1b08dc vcmpe.f32 s16, s20 */
/* @0x1b08e0 vmrs APSR_nzcv, fpscr */
/* @0x1b08e4 ble 0x1b0a50 <_Z14DoSlowDrawRoomP9tagYYRECT+0x3b0> */
/* @0x1b08e8 cmp r5, r3 */
/* @0x1b08ec bge 0x1b0900 <_Z14DoSlowDrawRoomP9tagYYRECT+0x260> */
/* @0x1b08f0 vldr s14, [r11, #28] */
/* @0x1b08f4 vcmpe.f32 s16, s14 */
/* @0x1b08f8 vmrs APSR_nzcv, fpscr */
/* @0x1b08fc blt 0x1b0af4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x454> */
/* @0x1b0900 vcmpe.f32 s16, s20 */
/* @0x1b0904 vmrs APSR_nzcv, fpscr */
/* @0x1b0908 ble 0x1b09c4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x324> */
/* @0x1b090c vcmpe.f32 s16, s17 */
/* @0x1b0910 vmrs APSR_nzcv, fpscr */
/* @0x1b0914 vmovle r0, s16 */
/* @0x1b0918 vmovgt r0, s17 */
/* @0x1b091c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b0920 vmov r0, s16 */
/* @0x1b0924 bl 0x1a583c <_Z24ParticleSystem_DrawDepthf> */
/* @0x1b0928 vmov r0, s16 */
/* @0x1b092c bl 0x1a579c <_Z24ParticleSystem_NextDepthf> */
/* @0x1b0930 ldr r1, [r6] */
/* @0x1b0934 ldr r3, [r1, #0xb8] */
/* @0x1b0938 vmov s16, r0 */
/* @0x1b093c b 0x1b06f4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x54> */
/* @0x1b0940 vcmpe.f32 s15, s17 */
/* @0x1b0944 vmrs APSR_nzcv, fpscr */
/* @0x1b0948 vmovle r0, s15 */
/* @0x1b094c vmovgt r0, s17 */
/* @0x1b0950 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b0954 ldr r0, [r4, #0x80] */
/* @0x1b0958 mov r1, #8 */
/* @0x1b095c mov r2, #0 */
/* @0x1b0960 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b0964 cmp r0, #0 */
/* @0x1b0968 beq 0x1b09d4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x334> */
/* @0x1b096c ldr lr, [pc, #0x124] */
/* @0x1b0970 mov r0, r4 */
/* @0x1b0974 mov r1, r4 */
/* @0x1b0978 mov r2, #8 */
/* @0x1b097c mov r3, #0 */
/* @0x1b0980 ldr lr, [r7, lr] */
/* @0x1b0984 str lr, [sp, #0x24] */
/* @0x1b0988 str r4, [lr] */
/* @0x1b098c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b0990 ldr r12, [sp, #0x24] */
/* @0x1b0994 str r8, [r12] */
/* @0x1b0998 ldr r1, [r6] */
/* @0x1b099c ldr r4, [r4, #0x17c] */
/* @0x1b09a0 ldr r3, [r1, #0xb8] */
/* @0x1b09a4 b 0x1b06f4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x54> */
/* @0x1b09a8 ldr r4, [r4, #0x17c] */
/* @0x1b09ac b 0x1b06f4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x54> */
/* @0x1b09b0 ldrb r2, [r11, #0x34] */
/* @0x1b09b4 cmp r2, #0 */
/* @0x1b09b8 bne 0x1b073c <_Z14DoSlowDrawRoomP9tagYYRECT+0x9c> */
/* @0x1b09bc add r5, r5, #1 */
/* @0x1b09c0 b 0x1b06f4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x54> */
/* @0x1b09c4 cmp r4, #0 */
/* @0x1b09c8 beq 0x1b0a60 <_Z14DoSlowDrawRoomP9tagYYRECT+0x3c0> */
/* @0x1b09cc vldr s15, [r4, #384] */
/* @0x1b09d0 b 0x1b0754 <_Z14DoSlowDrawRoomP9tagYYRECT+0xb4> */
/* @0x1b09d4 ldr r0, [r4, #0x8c] */
/* @0x1b09d8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b09dc subs r1, r0, #0 */
/* @0x1b09e0 beq 0x1b0998 <_Z14DoSlowDrawRoomP9tagYYRECT+0x2f8> */
/* @0x1b09e4 ldr r3, [pc, #0xac] */
/* @0x1b09e8 vldr s15, [r4, #152] */
/* @0x1b09ec vcmp.f32 s15, s21 */
/* @0x1b09f0 ldr r3, [r7, r3] */
/* @0x1b09f4 vmrs APSR_nzcv, fpscr */
/* @0x1b09f8 str r3, [sp, #0x24] */
/* @0x1b09fc str r4, [r3] */
/* @0x1b0a00 beq 0x1b0a68 <_Z14DoSlowDrawRoomP9tagYYRECT+0x3c8> */
/* @0x1b0a04 ldr lr, [r4, #0xa8] */
/* @0x1b0a08 vldr s14, [r4, #156] */
/* @0x1b0a0c vldr s13, [r4, #160] */
/* @0x1b0a10 vldr s12, [r4, #164] */
/* @0x1b0a14 vldr s11, [r4, #144] */
/* @0x1b0a18 vcvt.s32.f32 s11, s11 */
/* @0x1b0a1c ldr r2, [r4, #0xb4] */
/* @0x1b0a20 mov r0, r1 */
/* @0x1b0a24 ldr r3, [r4, #0xb8] */
/* @0x1b0a28 vstr s15, [sp] */
/* @0x1b0a2c vstr s14, [sp, #4] */
/* @0x1b0a30 vstr s13, [sp, #8] */
/* @0x1b0a34 str lr, [sp, #0xc] */
/* @0x1b0a38 vstr s12, [sp, #16] */
/* @0x1b0a3c vmov r1, s11 */
/* @0x1b0a40 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x1b0a44 ldr r12, [sp, #0x24] */
/* @0x1b0a48 str r8, [r12] */
/* @0x1b0a4c b 0x1b0998 <_Z14DoSlowDrawRoomP9tagYYRECT+0x2f8> */
/* @0x1b0a50 add sp, sp, #44 */
/* @0x1b0a54 vpop {d8, d9, d10, d11} */
/* @0x1b0a58 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b0a5c b 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b0a60 vldr s14, [r11, #28] */
/* @0x1b0a64 b 0x1b076c <_Z14DoSlowDrawRoomP9tagYYRECT+0xcc> */
/* @0x1b0a68 vldr s14, [r4, #156] */
/* @0x1b0a6c vcmp.f32 s14, s21 */
/* @0x1b0a70 vldr s13, [r4, #160] */
/* @0x1b0a74 vmrs APSR_nzcv, fpscr */
/* @0x1b0a78 beq 0x1b0a9c <_Z14DoSlowDrawRoomP9tagYYRECT+0x3fc> */
/* @0x1b0a7c ldr lr, [r4, #0xa8] */
/* @0x1b0a80 vldr s12, [r4, #164] */
/* @0x1b0a84 b 0x1b0a14 <_Z14DoSlowDrawRoomP9tagYYRECT+0x374> */
/* @0x1b0a88 strtmi lr, [r11], -r0 */
/* @0x1b0a8c ldcgt p12, c11, [lr], #128 */
/* @0x1b0a90 eoreq r1, r4, r8, lsl #11 */
/* @0x1b0a94 .word 0xffffbcd8 */
/* @0x1b0a98 .word 0xffffbce4 */
/* @0x1b0a9c vcmp.f32 s13, #0 */
/* @0x1b0aa0 ldr lr, [r4, #0xa8] */
/* @0x1b0aa4 vmrs APSR_nzcv, fpscr */
/* @0x1b0aa8 bne 0x1b0a10 <_Z14DoSlowDrawRoomP9tagYYRECT+0x370> */
/* @0x1b0aac cmp lr, r10 */
/* @0x1b0ab0 vldr s12, [r4, #164] */
/* @0x1b0ab4 bne 0x1b0a14 <_Z14DoSlowDrawRoomP9tagYYRECT+0x374> */
/* @0x1b0ab8 vcmp.f32 s12, s21 */
/* @0x1b0abc vmrs APSR_nzcv, fpscr */
/* @0x1b0ac0 bne 0x1b0a14 <_Z14DoSlowDrawRoomP9tagYYRECT+0x374> */
/* @0x1b0ac4 ldr r0, [r4, #0x90] */
/* @0x1b0ac8 str r1, [sp, #0x20] */
/* @0x1b0acc bl 0xb6910 <floorf@plt> */
/* @0x1b0ad0 ldr r1, [sp, #0x20] */
/* @0x1b0ad4 ldr r2, [r4, #0xb4] */
/* @0x1b0ad8 ldr r3, [r4, #0xb8] */
/* @0x1b0adc vmov s13, r0 */
/* @0x1b0ae0 mov r0, r1 */
/* @0x1b0ae4 vcvt.s32.f32 s13, s13 */
/* @0x1b0ae8 vmov r1, s13 */
/* @0x1b0aec bl 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x1b0af0 b 0x1b0a44 <_Z14DoSlowDrawRoomP9tagYYRECT+0x3a4> */
/* @0x1b0af4 cmp r4, #0 */
/* @0x1b0af8 beq 0x1b076c <_Z14DoSlowDrawRoomP9tagYYRECT+0xcc> */
/* @0x1b0afc vldr s15, [r4, #384] */
/* @0x1b0b00 b 0x1b0760 <_Z14DoSlowDrawRoomP9tagYYRECT+0xc0> */

/* ── FUNC 0x1b0b04 · DrawInstancesParticlesOnly(tagYYRECT*) · size=1100 · insn=275 */
/* @0x1b0b04 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b0b08 vpush {d8, d9} */
/* @0x1b0b0c sub sp, sp, #28 */
/* @0x1b0b10 vldr s17, [pc, #976] */
/* @0x1b0b14 bl 0x1a570c <_Z27ParticleSystem_LargestDepthv> */
/* @0x1b0b18 ldr r6, [pc, #0x3d0] */
/* @0x1b0b1c ldr r3, [pc, #0x3d0] */
/* @0x1b0b20 add r6, pc, r6 */
/* @0x1b0b24 ldr r3, [r6, r3] */
/* @0x1b0b28 ldr r3, [r3] */
/* @0x1b0b2c ldr r4, [r3, #0x84] */
/* @0x1b0b30 vmov s16, r0 */
/* @0x1b0b34 vcmpe.f32 s16, s17 */
/* @0x1b0b38 vmrs APSR_nzcv, fpscr */
/* @0x1b0b3c ble 0x1b0bf0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xec> */
/* @0x1b0b40 cmp r4, #0 */
/* @0x1b0b44 beq 0x1b0e78 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x374> */
/* @0x1b0b48 mov r7, #0 */
/* @0x1b0b4c vmov.f32 s19, #1.000000e+00 */
/* @0x1b0b50 mvn r8, #-16777216 */
/* @0x1b0b54 vldr s18, [pc, #912] */
/* @0x1b0b58 b 0x1b0bd4 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xd0> */
/* @0x1b0b5c ldrb r3, [r4, #0x69] */
/* @0x1b0b60 cmp r3, #0 */
/* @0x1b0b64 bne 0x1b0be0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xdc> */
/* @0x1b0b68 ldrb r3, [r4, #0x65] */
/* @0x1b0b6c cmp r3, #0 */
/* @0x1b0b70 beq 0x1b0be0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xdc> */
/* @0x1b0b74 vldr s15, [r4, #384] */
/* @0x1b0b78 vcmpe.f32 s15, s16 */
/* @0x1b0b7c vmrs APSR_nzcv, fpscr */
/* @0x1b0b80 bpl 0x1b0d24 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x220> */
/* @0x1b0b84 ldr r3, [pc, #0x36c] */
/* @0x1b0b88 ldr r5, [r6, r3] */
/* @0x1b0b8c ldrb r3, [r5] */
/* @0x1b0b90 cmp r3, #0 */
/* @0x1b0b94 beq 0x1b0bac <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xa8> */
/* @0x1b0b98 vcmpe.f32 s16, s18 */
/* @0x1b0b9c vmrs APSR_nzcv, fpscr */
/* @0x1b0ba0 vmovle r0, s16 */
/* @0x1b0ba4 vmovgt r0, s18 */
/* @0x1b0ba8 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b0bac vmov r0, s16 */
/* @0x1b0bb0 bl 0x1a583c <_Z24ParticleSystem_DrawDepthf> */
/* @0x1b0bb4 vmov r0, s16 */
/* @0x1b0bb8 bl 0x1a579c <_Z24ParticleSystem_NextDepthf> */
/* @0x1b0bbc vmov s16, r0 */
/* @0x1b0bc0 vcmpe.f32 s16, s17 */
/* @0x1b0bc4 vmrs APSR_nzcv, fpscr */
/* @0x1b0bc8 ble 0x1b0bf0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xec> */
/* @0x1b0bcc cmp r4, #0 */
/* @0x1b0bd0 beq 0x1b0e78 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x374> */
/* @0x1b0bd4 ldrb r3, [r4, #0x68] */
/* @0x1b0bd8 cmp r3, #0 */
/* @0x1b0bdc beq 0x1b0b5c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x58> */
/* @0x1b0be0 ldr r4, [r4, #0x17c] */
/* @0x1b0be4 vcmpe.f32 s16, s17 */
/* @0x1b0be8 vmrs APSR_nzcv, fpscr */
/* @0x1b0bec bgt 0x1b0bcc <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xc8> */
/* @0x1b0bf0 cmp r4, #0 */
/* @0x1b0bf4 beq 0x1b0ec8 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3c4> */
/* @0x1b0bf8 vmov.f32 s17, #1.000000e+00 */
/* @0x1b0bfc mov r7, #0 */
/* @0x1b0c00 mvn r8, #-16777216 */
/* @0x1b0c04 vldr s16, [pc, #736] */
/* @0x1b0c08 b 0x1b0c3c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x138> */
/* @0x1b0c0c ldr r12, [pc, #0x2e8] */
/* @0x1b0c10 mov r0, r4 */
/* @0x1b0c14 mov r1, r4 */
/* @0x1b0c18 mov r2, #8 */
/* @0x1b0c1c mov r3, #0 */
/* @0x1b0c20 ldr r5, [r6, r12] */
/* @0x1b0c24 str r4, [r5] */
/* @0x1b0c28 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b0c2c str r7, [r5] */
/* @0x1b0c30 ldr r4, [r4, #0x17c] */
/* @0x1b0c34 cmp r4, #0 */
/* @0x1b0c38 beq 0x1b0ec8 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3c4> */
/* @0x1b0c3c ldrb r3, [r4, #0x68] */
/* @0x1b0c40 cmp r3, #0 */
/* @0x1b0c44 bne 0x1b0c30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x12c> */
/* @0x1b0c48 ldrb r3, [r4, #0x69] */
/* @0x1b0c4c cmp r3, #0 */
/* @0x1b0c50 bne 0x1b0c30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x12c> */
/* @0x1b0c54 ldrb r3, [r4, #0x65] */
/* @0x1b0c58 cmp r3, #0 */
/* @0x1b0c5c beq 0x1b0c30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x12c> */
/* @0x1b0c60 ldr r3, [pc, #0x290] */
/* @0x1b0c64 ldr r3, [r6, r3] */
/* @0x1b0c68 ldrb r3, [r3] */
/* @0x1b0c6c cmp r3, #0 */
/* @0x1b0c70 beq 0x1b0c8c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x188> */
/* @0x1b0c74 vldr s15, [r4, #384] */
/* @0x1b0c78 vcmpe.f32 s15, s16 */
/* @0x1b0c7c vmrs APSR_nzcv, fpscr */
/* @0x1b0c80 vmovle r0, s15 */
/* @0x1b0c84 vmovgt r0, s16 */
/* @0x1b0c88 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b0c8c ldr r0, [r4, #0x80] */
/* @0x1b0c90 mov r1, #8 */
/* @0x1b0c94 mov r2, #0 */
/* @0x1b0c98 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b0c9c cmp r0, #0 */
/* @0x1b0ca0 bne 0x1b0c0c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x108> */
/* @0x1b0ca4 ldr r0, [r4, #0x8c] */
/* @0x1b0ca8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b0cac subs r9, r0, #0 */
/* @0x1b0cb0 beq 0x1b0c30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x12c> */
/* @0x1b0cb4 ldr r3, [pc, #0x240] */
/* @0x1b0cb8 vldr s15, [r4, #152] */
/* @0x1b0cbc vcmp.f32 s15, s17 */
/* @0x1b0cc0 ldr r5, [r6, r3] */
/* @0x1b0cc4 vmrs APSR_nzcv, fpscr */
/* @0x1b0cc8 str r4, [r5] */
/* @0x1b0ccc bne 0x1b0ed4 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3d0> */
/* @0x1b0cd0 vldr s14, [r4, #156] */
/* @0x1b0cd4 vcmp.f32 s14, s17 */
/* @0x1b0cd8 vldr s13, [r4, #160] */
/* @0x1b0cdc vmrs APSR_nzcv, fpscr */
/* @0x1b0ce0 beq 0x1b0f00 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3fc> */
/* @0x1b0ce4 ldr r12, [r4, #0xa8] */
/* @0x1b0ce8 vldr s12, [r4, #164] */
/* @0x1b0cec vldr s11, [r4, #144] */
/* @0x1b0cf0 vcvt.s32.f32 s11, s11 */
/* @0x1b0cf4 ldr r2, [r4, #0xb4] */
/* @0x1b0cf8 mov r0, r9 */
/* @0x1b0cfc ldr r3, [r4, #0xb8] */
/* @0x1b0d00 vstr s15, [sp] */
/* @0x1b0d04 vstr s14, [sp, #4] */
/* @0x1b0d08 vstr s13, [sp, #8] */
/* @0x1b0d0c str r12, [sp, #0xc] */
/* @0x1b0d10 vstr s12, [sp, #16] */
/* @0x1b0d14 vmov r1, s11 */
/* @0x1b0d18 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x1b0d1c str r7, [r5] */
/* @0x1b0d20 b 0x1b0c30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x12c> */
/* @0x1b0d24 ldr r3, [pc, #0x1cc] */
/* @0x1b0d28 ldr r5, [r6, r3] */
/* @0x1b0d2c ldrb r3, [r5] */
/* @0x1b0d30 cmp r3, #0 */
/* @0x1b0d34 beq 0x1b0d4c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x248> */
/* @0x1b0d38 vcmpe.f32 s15, s18 */
/* @0x1b0d3c vmrs APSR_nzcv, fpscr */
/* @0x1b0d40 vmovle r0, s15 */
/* @0x1b0d44 vmovgt r0, s18 */
/* @0x1b0d48 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b0d4c ldr r0, [r4, #0x80] */
/* @0x1b0d50 mov r1, #8 */
/* @0x1b0d54 mov r2, #0 */
/* @0x1b0d58 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b0d5c cmp r0, #0 */
/* @0x1b0d60 beq 0x1b0d90 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x28c> */
/* @0x1b0d64 ldr r12, [pc, #0x190] */
/* @0x1b0d68 mov r0, r4 */
/* @0x1b0d6c mov r1, r4 */
/* @0x1b0d70 mov r2, #8 */
/* @0x1b0d74 mov r3, #0 */
/* @0x1b0d78 ldr r5, [r6, r12] */
/* @0x1b0d7c str r4, [r5] */
/* @0x1b0d80 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b0d84 str r7, [r5] */
/* @0x1b0d88 ldr r4, [r4, #0x17c] */
/* @0x1b0d8c b 0x1b0be4 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xe0> */
/* @0x1b0d90 ldr r0, [r4, #0x8c] */
/* @0x1b0d94 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b0d98 subs r9, r0, #0 */
/* @0x1b0d9c beq 0x1b0be0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xdc> */
/* @0x1b0da0 ldr r3, [pc, #0x154] */
/* @0x1b0da4 vldr s15, [r4, #152] */
/* @0x1b0da8 vcmp.f32 s15, s19 */
/* @0x1b0dac ldr r5, [r6, r3] */
/* @0x1b0db0 vmrs APSR_nzcv, fpscr */
/* @0x1b0db4 str r4, [r5] */
/* @0x1b0db8 bne 0x1b0e20 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x31c> */
/* @0x1b0dbc vldr s14, [r4, #156] */
/* @0x1b0dc0 vcmp.f32 s14, s19 */
/* @0x1b0dc4 vldr s13, [r4, #160] */
/* @0x1b0dc8 vmrs APSR_nzcv, fpscr */
/* @0x1b0dcc bne 0x1b0e6c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x368> */
/* @0x1b0dd0 vcmp.f32 s13, #0 */
/* @0x1b0dd4 ldr r12, [r4, #0xa8] */
/* @0x1b0dd8 vmrs APSR_nzcv, fpscr */
/* @0x1b0ddc bne 0x1b0e2c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x328> */
/* @0x1b0de0 cmp r12, r8 */
/* @0x1b0de4 vldr s12, [r4, #164] */
/* @0x1b0de8 bne 0x1b0e30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x32c> */
/* @0x1b0dec vcmp.f32 s12, s19 */
/* @0x1b0df0 vmrs APSR_nzcv, fpscr */
/* @0x1b0df4 bne 0x1b0e30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x32c> */
/* @0x1b0df8 ldr r0, [r4, #0x90] */
/* @0x1b0dfc bl 0xb6910 <floorf@plt> */
/* @0x1b0e00 ldr r2, [r4, #0xb4] */
/* @0x1b0e04 ldr r3, [r4, #0xb8] */
/* @0x1b0e08 vmov s15, r0 */
/* @0x1b0e0c mov r0, r9 */
/* @0x1b0e10 vcvt.s32.f32 s15, s15 */
/* @0x1b0e14 vmov r1, s15 */
/* @0x1b0e18 bl 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x1b0e1c b 0x1b0e60 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x35c> */
/* @0x1b0e20 ldr r12, [r4, #0xa8] */
/* @0x1b0e24 vldr s14, [r4, #156] */
/* @0x1b0e28 vldr s13, [r4, #160] */
/* @0x1b0e2c vldr s12, [r4, #164] */
/* @0x1b0e30 vldr s11, [r4, #144] */
/* @0x1b0e34 vcvt.s32.f32 s11, s11 */
/* @0x1b0e38 ldr r2, [r4, #0xb4] */
/* @0x1b0e3c mov r0, r9 */
/* @0x1b0e40 ldr r3, [r4, #0xb8] */
/* @0x1b0e44 vstr s15, [sp] */
/* @0x1b0e48 vstr s14, [sp, #4] */
/* @0x1b0e4c vstr s13, [sp, #8] */
/* @0x1b0e50 str r12, [sp, #0xc] */
/* @0x1b0e54 vstr s12, [sp, #16] */
/* @0x1b0e58 vmov r1, s11 */
/* @0x1b0e5c bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x1b0e60 str r7, [r5] */
/* @0x1b0e64 ldr r4, [r4, #0x17c] */
/* @0x1b0e68 b 0x1b0be4 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xe0> */
/* @0x1b0e6c ldr r12, [r4, #0xa8] */
/* @0x1b0e70 vldr s12, [r4, #164] */
/* @0x1b0e74 b 0x1b0e30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x32c> */
/* @0x1b0e78 ldr r3, [pc, #0x78] */
/* @0x1b0e7c vldr s18, [pc, #104] */
/* @0x1b0e80 vldr s17, [pc, #96] */
/* @0x1b0e84 ldr r5, [r6, r3] */
/* @0x1b0e88 ldrb r3, [r5] */
/* @0x1b0e8c cmp r3, #0 */
/* @0x1b0e90 beq 0x1b0ea8 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3a4> */
/* @0x1b0e94 vcmpe.f32 s16, s18 */
/* @0x1b0e98 vmrs APSR_nzcv, fpscr */
/* @0x1b0e9c vmovle r0, s16 */
/* @0x1b0ea0 vmovgt r0, s18 */
/* @0x1b0ea4 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b0ea8 vmov r0, s16 */
/* @0x1b0eac bl 0x1a583c <_Z24ParticleSystem_DrawDepthf> */
/* @0x1b0eb0 vmov r0, s16 */
/* @0x1b0eb4 bl 0x1a579c <_Z24ParticleSystem_NextDepthf> */
/* @0x1b0eb8 vmov s16, r0 */
/* @0x1b0ebc vcmpe.f32 s16, s17 */
/* @0x1b0ec0 vmrs APSR_nzcv, fpscr */
/* @0x1b0ec4 bgt 0x1b0e88 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x384> */
/* @0x1b0ec8 add sp, sp, #28 */
/* @0x1b0ecc vpop {d8, d9} */
/* @0x1b0ed0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b0ed4 ldr r12, [r4, #0xa8] */
/* @0x1b0ed8 vldr s14, [r4, #156] */
/* @0x1b0edc vldr s13, [r4, #160] */
/* @0x1b0ee0 vldr s12, [r4, #164] */
/* @0x1b0ee4 b 0x1b0cec <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x1e8> */
/* @0x1b0ee8 ldcgt p12, c11, [lr], #128 */
/* @0x1b0eec strtmi lr, [r11], -r0 */
/* @0x1b0ef0 eoreq r1, r4, r0, lsr r1 */
/* @0x1b0ef4 .word 0xffffbcd8 */
/* @0x1b0ef8 .word 0xffffc0b4 */
/* @0x1b0efc .word 0xffffbce4 */
/* @0x1b0f00 vcmp.f32 s13, #0 */
/* @0x1b0f04 ldr r12, [r4, #0xa8] */
/* @0x1b0f08 vmrs APSR_nzcv, fpscr */
/* @0x1b0f0c bne 0x1b0ee0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3dc> */
/* @0x1b0f10 cmp r12, r8 */
/* @0x1b0f14 vldr s12, [r4, #164] */
/* @0x1b0f18 bne 0x1b0cec <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x1e8> */
/* @0x1b0f1c vcmp.f32 s12, s17 */
/* @0x1b0f20 vmrs APSR_nzcv, fpscr */
/* @0x1b0f24 bne 0x1b0cec <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x1e8> */
/* @0x1b0f28 ldr r0, [r4, #0x90] */
/* @0x1b0f2c bl 0xb6910 <floorf@plt> */
/* @0x1b0f30 ldr r2, [r4, #0xb4] */
/* @0x1b0f34 ldr r3, [r4, #0xb8] */
/* @0x1b0f38 vmov s15, r0 */
/* @0x1b0f3c mov r0, r9 */
/* @0x1b0f40 vcvt.s32.f32 s15, s15 */
/* @0x1b0f44 vmov r1, s15 */
/* @0x1b0f48 bl 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x1b0f4c b 0x1b0d1c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x218> */

/* ── FUNC 0x1b0f50 · DrawInstancesOnly(tagYYRECT*) · size=472 · insn=118 */
/* @0x1b0f50 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b0f54 vpush {d8} */
/* @0x1b0f58 sub sp, sp, #28 */
/* @0x1b0f5c ldr r6, [pc, #0x1b4] */
/* @0x1b0f60 ldr r3, [pc, #0x1b4] */
/* @0x1b0f64 add r6, pc, r6 */
/* @0x1b0f68 ldr r3, [r6, r3] */
/* @0x1b0f6c ldr r3, [r3] */
/* @0x1b0f70 ldr r4, [r3, #0x84] */
/* @0x1b0f74 cmp r4, #0 */
/* @0x1b0f78 beq 0x1b10b0 <_Z17DrawInstancesOnlyP9tagYYRECT+0x160> */
/* @0x1b0f7c vmov.f32 s17, #1.000000e+00 */
/* @0x1b0f80 mov r8, #0 */
/* @0x1b0f84 mvn r9, #-16777216 */
/* @0x1b0f88 vldr s16, [pc, #388] */
/* @0x1b0f8c b 0x1b0fc0 <_Z17DrawInstancesOnlyP9tagYYRECT+0x70> */
/* @0x1b0f90 ldr r12, [pc, #0x188] */
/* @0x1b0f94 mov r0, r4 */
/* @0x1b0f98 mov r1, r4 */
/* @0x1b0f9c mov r2, #8 */
/* @0x1b0fa0 mov r3, #0 */
/* @0x1b0fa4 ldr r7, [r6, r12] */
/* @0x1b0fa8 str r4, [r7] */
/* @0x1b0fac bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b0fb0 str r8, [r7] */
/* @0x1b0fb4 cmp r5, #0 */
/* @0x1b0fb8 beq 0x1b10b0 <_Z17DrawInstancesOnlyP9tagYYRECT+0x160> */
/* @0x1b0fbc mov r4, r5 */
/* @0x1b0fc0 ldrb r3, [r4, #0x68] */
/* @0x1b0fc4 ldr r5, [r4, #0x17c] */
/* @0x1b0fc8 cmp r3, #0 */
/* @0x1b0fcc bne 0x1b0fb4 <_Z17DrawInstancesOnlyP9tagYYRECT+0x64> */
/* @0x1b0fd0 ldrb r3, [r4, #0x69] */
/* @0x1b0fd4 cmp r3, #0 */
/* @0x1b0fd8 bne 0x1b0fb4 <_Z17DrawInstancesOnlyP9tagYYRECT+0x64> */
/* @0x1b0fdc ldrb r3, [r4, #0x65] */
/* @0x1b0fe0 cmp r3, #0 */
/* @0x1b0fe4 beq 0x1b0fb4 <_Z17DrawInstancesOnlyP9tagYYRECT+0x64> */
/* @0x1b0fe8 ldr r3, [pc, #0x134] */
/* @0x1b0fec ldr r3, [r6, r3] */
/* @0x1b0ff0 ldrb r3, [r3] */
/* @0x1b0ff4 cmp r3, #0 */
/* @0x1b0ff8 beq 0x1b1014 <_Z17DrawInstancesOnlyP9tagYYRECT+0xc4> */
/* @0x1b0ffc vldr s15, [r4, #384] */
/* @0x1b1000 vcmpe.f32 s15, s16 */
/* @0x1b1004 vmrs APSR_nzcv, fpscr */
/* @0x1b1008 vmovle r0, s15 */
/* @0x1b100c vmovgt r0, s16 */
/* @0x1b1010 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b1014 ldr r0, [r4, #0x80] */
/* @0x1b1018 mov r1, #8 */
/* @0x1b101c mov r2, #0 */
/* @0x1b1020 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b1024 cmp r0, #0 */
/* @0x1b1028 bne 0x1b0f90 <_Z17DrawInstancesOnlyP9tagYYRECT+0x40> */
/* @0x1b102c ldr r0, [r4, #0x8c] */
/* @0x1b1030 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b1034 subs r3, r0, #0 */
/* @0x1b1038 beq 0x1b0fb4 <_Z17DrawInstancesOnlyP9tagYYRECT+0x64> */
/* @0x1b103c ldr r2, [pc, #0xdc] */
/* @0x1b1040 vldr s15, [r4, #152] */
/* @0x1b1044 vcmp.f32 s15, s17 */
/* @0x1b1048 ldr r7, [r6, r2] */
/* @0x1b104c vmrs APSR_nzcv, fpscr */
/* @0x1b1050 str r4, [r7] */
/* @0x1b1054 bne 0x1b10bc <_Z17DrawInstancesOnlyP9tagYYRECT+0x16c> */
/* @0x1b1058 vldr s14, [r4, #156] */
/* @0x1b105c vcmp.f32 s14, s17 */
/* @0x1b1060 vldr s13, [r4, #160] */
/* @0x1b1064 vmrs APSR_nzcv, fpscr */
/* @0x1b1068 beq 0x1b10d0 <_Z17DrawInstancesOnlyP9tagYYRECT+0x180> */
/* @0x1b106c ldr r12, [r4, #0xa8] */
/* @0x1b1070 vldr s12, [r4, #164] */
/* @0x1b1074 vldr s11, [r4, #144] */
/* @0x1b1078 vcvt.s32.f32 s11, s11 */
/* @0x1b107c ldr r2, [r4, #0xb4] */
/* @0x1b1080 mov r0, r3 */
/* @0x1b1084 ldr r3, [r4, #0xb8] */
/* @0x1b1088 vstr s15, [sp] */
/* @0x1b108c vstr s14, [sp, #4] */
/* @0x1b1090 vstr s13, [sp, #8] */
/* @0x1b1094 str r12, [sp, #0xc] */
/* @0x1b1098 vstr s12, [sp, #16] */
/* @0x1b109c vmov r1, s11 */
/* @0x1b10a0 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x1b10a4 cmp r5, #0 */
/* @0x1b10a8 str r8, [r7] */
/* @0x1b10ac bne 0x1b0fbc <_Z17DrawInstancesOnlyP9tagYYRECT+0x6c> */
/* @0x1b10b0 add sp, sp, #28 */
/* @0x1b10b4 vpop {d8} */
/* @0x1b10b8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b10bc ldr r12, [r4, #0xa8] */
/* @0x1b10c0 vldr s14, [r4, #156] */
/* @0x1b10c4 vldr s13, [r4, #160] */
/* @0x1b10c8 vldr s12, [r4, #164] */
/* @0x1b10cc b 0x1b1074 <_Z17DrawInstancesOnlyP9tagYYRECT+0x124> */
/* @0x1b10d0 vcmp.f32 s13, #0 */
/* @0x1b10d4 ldr r12, [r4, #0xa8] */
/* @0x1b10d8 vmrs APSR_nzcv, fpscr */
/* @0x1b10dc bne 0x1b10c8 <_Z17DrawInstancesOnlyP9tagYYRECT+0x178> */
/* @0x1b10e0 cmp r12, r9 */
/* @0x1b10e4 vldr s12, [r4, #164] */
/* @0x1b10e8 bne 0x1b1074 <_Z17DrawInstancesOnlyP9tagYYRECT+0x124> */
/* @0x1b10ec vcmp.f32 s12, s17 */
/* @0x1b10f0 vmrs APSR_nzcv, fpscr */
/* @0x1b10f4 bne 0x1b1074 <_Z17DrawInstancesOnlyP9tagYYRECT+0x124> */
/* @0x1b10f8 vldr s15, [r4, #144] */
/* @0x1b10fc vcvt.s32.f32 s15, s15 */
/* @0x1b1100 ldr r2, [r4, #0xb4] */
/* @0x1b1104 ldr r3, [r4, #0xb8] */
/* @0x1b1108 vmov r1, s15 */
/* @0x1b110c bl 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x1b1110 b 0x1b10a4 <_Z17DrawInstancesOnlyP9tagYYRECT+0x154> */
/* @0x1b1114 strtmi lr, [r11], -r0 */
/* @0x1b1118 eoreq r0, r4, r12, ror #25 */
/* @0x1b111c .word 0xffffbcd8 */
/* @0x1b1120 .word 0xffffbce4 */
/* @0x1b1124 .word 0xffffc0b4 */

/* ── FUNC 0x1b1128 · SetLayerShader(int) · size=72 · insn=18 */
/* @0x1b1128 cmn r0, #1 */
/* @0x1b112c str lr, [sp, #-0x4]! */
/* @0x1b1130 sub sp, sp, #44 */
/* @0x1b1134 beq 0x1b1168 <_Z14SetLayerShaderi+0x40> */
/* @0x1b1138 vmov s13, r0 */
/* @0x1b113c mov r12, #0 */
/* @0x1b1140 add r3, sp, #8 */
/* @0x1b1144 mov r1, r12 */
/* @0x1b1148 vcvt.f64.s32 d7, s13 */
/* @0x1b114c str r3, [sp] */
/* @0x1b1150 mov r2, r12 */
/* @0x1b1154 add r0, sp, #24 */
/* @0x1b1158 mov r3, #1 */
/* @0x1b115c str r12, [sp, #0x14] */
/* @0x1b1160 vstr d7, [sp, #8] */
/* @0x1b1164 bl 0x1e207c <_Z12F_Shader_SetR6RValueP9CInstanceS2_iPS_> */
/* @0x1b1168 add sp, sp, #44 */
/* @0x1b116c ldr pc, [sp], #4 */

/* ── FUNC 0x1b1170 · ResetLayerShader(int) · size=48 · insn=12 */
/* @0x1b1170 cmn r0, #1 */
/* @0x1b1174 str lr, [sp, #-0x4]! */
/* @0x1b1178 sub sp, sp, #28 */
/* @0x1b117c beq 0x1b1198 <_Z16ResetLayerShaderi+0x28> */
/* @0x1b1180 mov r3, #0 */
/* @0x1b1184 add r0, sp, #8 */
/* @0x1b1188 mov r1, r3 */
/* @0x1b118c str r3, [sp] */
/* @0x1b1190 mov r2, r3 */
/* @0x1b1194 bl 0x1e2110 <_Z14F_Shader_ResetR6RValueP9CInstanceS2_iPS_> */
/* @0x1b1198 add sp, sp, #28 */
/* @0x1b119c ldr pc, [sp], #4 */

/* ── FUNC 0x1b11a0 · DrawLayerBackgroundElement(tagYYRECT*, CLayer*, CLayerBackgroundElement*) · size=1120 · insn=280 */
/* @0x1b11a0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b11a4 vpush {d8} */
/* @0x1b11a8 mov r7, r0 */
/* @0x1b11ac ldr r4, [r2, #0x1c] */
/* @0x1b11b0 sub sp, sp, #424 */
/* @0x1b11b4 ldr r6, [pc, #0x430] */
/* @0x1b11b8 mov r8, r1 */
/* @0x1b11bc ldrb r3, [r4] */
/* @0x1b11c0 add r6, pc, r6 */
/* @0x1b11c4 cmp r3, #0 */
/* @0x1b11c8 bne 0x1b11d8 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x38> */
/* @0x1b11cc add sp, sp, #424 */
/* @0x1b11d0 vpop {d8} */
/* @0x1b11d4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b11d8 ldr r0, [r4, #0x4] */
/* @0x1b11dc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b11e0 subs r5, r0, #0 */
/* @0x1b11e4 beq 0x1b12f4 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x154> */
/* @0x1b11e8 ldrb r3, [r4, #0x14] */
/* @0x1b11ec cmp r3, #0 */
/* @0x1b11f0 beq 0x1b1234 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x94> */
/* @0x1b11f4 ldr r3, [pc, #0x3f4] */
/* @0x1b11f8 ldr r3, [r6, r3] */
/* @0x1b11fc ldr r3, [r3] */
/* @0x1b1200 cmp r3, #0 */
/* @0x1b1204 beq 0x1b1234 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x94> */
/* @0x1b1208 vldr s17, [r3, #16] */
/* @0x1b120c vldr s16, [r3, #20] */
/* @0x1b1210 vcvt.f32.s32 s17, s17 */
/* @0x1b1214 vldr s12, [r5, #28] */
/* @0x1b1218 vldr s13, [r5, #32] */
/* @0x1b121c vcvt.f32.s32 s14, s12 */
/* @0x1b1220 vcvt.f32.s32 s16, s16 */
/* @0x1b1224 vcvt.f32.s32 s15, s13 */
/* @0x1b1228 vdiv.f32 s17, s17, s14 */
/* @0x1b122c vdiv.f32 s16, s16, s15 */
/* @0x1b1230 b 0x1b123c <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x9c> */
/* @0x1b1234 vldr s17, [r4, #12] */
/* @0x1b1238 vldr s16, [r4, #16] */
/* @0x1b123c ldr r9, [r5, #0x24] */
/* @0x1b1240 mov r3, #0 */
/* @0x1b1244 ldr r6, [r5, #0x28] */
/* @0x1b1248 str r3, [r5, #0x24] */
/* @0x1b124c str r3, [r5, #0x28] */
/* @0x1b1250 ldr r0, [r4, #0x4] */
/* @0x1b1254 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b1258 ldr r3, [r7] */
/* @0x1b125c ldr r12, [r7, #0x8] */
/* @0x1b1260 vldr s15, [r4, #32] */
/* @0x1b1264 ldr r1, [r7, #0x4] */
/* @0x1b1268 vstr s17, [sp] */
/* @0x1b126c rsb r12, r3, r12 */
/* @0x1b1270 vmov s13, r3 */
/* @0x1b1274 ldr r2, [r7, #0xc] */
/* @0x1b1278 vstr s16, [sp, #4] */
/* @0x1b127c vcvt.f32.s32 s12, s13 */
/* @0x1b1280 ldr r3, [r8, #0xc] */
/* @0x1b1284 vmov s14, r12 */
/* @0x1b1288 ldrb r12, [r4, #0x8] */
/* @0x1b128c rsb r2, r1, r2 */
/* @0x1b1290 vmov s13, r2 */
/* @0x1b1294 ldr r2, [r8, #0x8] */
/* @0x1b1298 str r12, [sp, #0x8] */
/* @0x1b129c ldrb r12, [r4, #0x9] */
/* @0x1b12a0 vcvt.f32.s32 s14, s14 */
/* @0x1b12a4 vstr s12, [sp, #16] */
/* @0x1b12a8 vmov s12, r1 */
/* @0x1b12ac str r12, [sp, #0xc] */
/* @0x1b12b0 vstr s14, [sp, #24] */
/* @0x1b12b4 vcvt.f32.s32 s13, s13 */
/* @0x1b12b8 vcvt.f32.s32 s14, s12 */
/* @0x1b12bc vstr s13, [sp, #28] */
/* @0x1b12c0 vcvt.s32.f32 s15, s15 */
/* @0x1b12c4 vstr s14, [sp, #20] */
/* @0x1b12c8 ldr r12, [r4, #0x18] */
/* @0x1b12cc str r12, [sp, #0x20] */
/* @0x1b12d0 ldr r12, [r4, #0x1c] */
/* @0x1b12d4 vmov r1, s15 */
/* @0x1b12d8 str r12, [sp, #0x24] */
/* @0x1b12dc bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf> */
/* @0x1b12e0 str r9, [r5, #0x24] */
/* @0x1b12e4 str r6, [r5, #0x28] */
/* @0x1b12e8 add sp, sp, #424 */
/* @0x1b12ec vpop {d8} */
/* @0x1b12f0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b12f4 ldr r3, [pc, #0x2f8] */
/* @0x1b12f8 ldr r3, [r6, r3] */
/* @0x1b12fc ldr r10, [r3] */
/* @0x1b1300 cmp r10, #0 */
/* @0x1b1304 beq 0x1b1328 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x188> */
/* @0x1b1308 ldr r3, [pc, #0x2e8] */
/* @0x1b130c ldr r3, [r6, r3] */
/* @0x1b1310 ldr r10, [r3] */
/* @0x1b1314 cmp r10, #0 */
/* @0x1b1318 beq 0x1b1328 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x188> */
/* @0x1b131c ldr r10, [r10] */
/* @0x1b1320 adds r10, r10, #0 */
/* @0x1b1324 movne r10, #1 */
/* @0x1b1328 add r8, sp, #40 */
/* @0x1b132c add r7, sp, #104 */
/* @0x1b1330 mov r0, #2 */
/* @0x1b1334 add r5, sp, #168 */
/* @0x1b1338 mov r1, r8 */
/* @0x1b133c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1b1340 mov r1, r7 */
/* @0x1b1344 mov r0, #0 */
/* @0x1b1348 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1b134c mov r1, r5 */
/* @0x1b1350 mov r0, #1 */
/* @0x1b1354 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1b1358 mov r0, #2 */
/* @0x1b135c add r1, sp, #232 */
/* @0x1b1360 mov r3, #0 */
/* @0x1b1364 mov r2, #1065353216 */
/* @0x1b1368 str r3, [sp, #0x120] */
/* @0x1b136c str r2, [sp, #0x124] */
/* @0x1b1370 str r2, [sp, #0x110] */
/* @0x1b1374 str r2, [sp, #0xfc] */
/* @0x1b1378 str r2, [sp, #0xe8] */
/* @0x1b137c str r2, [sp, #0x164] */
/* @0x1b1380 str r2, [sp, #0x150] */
/* @0x1b1384 str r2, [sp, #0x13c] */
/* @0x1b1388 str r2, [sp, #0x128] */
/* @0x1b138c str r2, [sp, #0x1a4] */
/* @0x1b1390 str r3, [sp, #0x11c] */
/* @0x1b1394 str r3, [sp, #0x118] */
/* @0x1b1398 str r3, [sp, #0x114] */
/* @0x1b139c str r3, [sp, #0x10c] */
/* @0x1b13a0 str r3, [sp, #0x108] */
/* @0x1b13a4 str r3, [sp, #0x104] */
/* @0x1b13a8 str r3, [sp, #0x100] */
/* @0x1b13ac str r3, [sp, #0xf8] */
/* @0x1b13b0 str r3, [sp, #0xf4] */
/* @0x1b13b4 str r3, [sp, #0xf0] */
/* @0x1b13b8 str r3, [sp, #0xec] */
/* @0x1b13bc str r3, [sp, #0x160] */
/* @0x1b13c0 str r3, [sp, #0x15c] */
/* @0x1b13c4 str r3, [sp, #0x158] */
/* @0x1b13c8 str r3, [sp, #0x154] */
/* @0x1b13cc str r3, [sp, #0x14c] */
/* @0x1b13d0 str r3, [sp, #0x148] */
/* @0x1b13d4 str r3, [sp, #0x144] */
/* @0x1b13d8 str r3, [sp, #0x140] */
/* @0x1b13dc str r3, [sp, #0x138] */
/* @0x1b13e0 str r3, [sp, #0x134] */
/* @0x1b13e4 str r3, [sp, #0x130] */
/* @0x1b13e8 str r3, [sp, #0x12c] */
/* @0x1b13ec str r2, [sp, #0x190] */
/* @0x1b13f0 str r2, [sp, #0x17c] */
/* @0x1b13f4 str r2, [sp, #0x168] */
/* @0x1b13f8 str r3, [sp, #0x1a0] */
/* @0x1b13fc str r3, [sp, #0x19c] */
/* @0x1b1400 str r3, [sp, #0x198] */
/* @0x1b1404 str r3, [sp, #0x194] */
/* @0x1b1408 str r3, [sp, #0x18c] */
/* @0x1b140c str r3, [sp, #0x188] */
/* @0x1b1410 str r3, [sp, #0x184] */
/* @0x1b1414 str r3, [sp, #0x180] */
/* @0x1b1418 str r3, [sp, #0x178] */
/* @0x1b141c str r3, [sp, #0x174] */
/* @0x1b1420 str r3, [sp, #0x170] */
/* @0x1b1424 str r3, [sp, #0x16c] */
/* @0x1b1428 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b142c bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b1430 mov r0, #0 */
/* @0x1b1434 add r1, sp, #296 */
/* @0x1b1438 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b143c bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b1440 add r1, sp, #360 */
/* @0x1b1444 mov r0, #1 */
/* @0x1b1448 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b144c bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b1450 ldr r3, [pc, #0x1a4] */
/* @0x1b1454 ldr r9, [r6, r3] */
/* @0x1b1458 mov r0, r9 */
/* @0x1b145c bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv> */
/* @0x1b1460 mov r0, r9 */
/* @0x1b1464 mov r1, #8 */
/* @0x1b1468 mov r2, #0 */
/* @0x1b146c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1b1470 vldr s14, [r4, #28] */
/* @0x1b1474 vldr s15, [pc, #364] */
/* @0x1b1478 vmul.f32 s15, s14, s15 */
/* @0x1b147c ldr r3, [r4, #0x18] */
/* @0x1b1480 vcvt.s32.f32 s15, s15 */
/* @0x1b1484 vmov r4, s15 */
/* @0x1b1488 cmp r4, #255 */
/* @0x1b148c movgt r4, #-16777216 */
/* @0x1b1490 ble 0x1b15d8 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x438> */
/* @0x1b1494 cmp r10, #0 */
/* @0x1b1498 bic r3, r3, #-16777216 */
/* @0x1b149c orr r4, r4, r3 */
/* @0x1b14a0 bne 0x1b1544 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x3a4> */
/* @0x1b14a4 mov r1, r10 */
/* @0x1b14a8 mov r2, #16 */
/* @0x1b14ac mov r0, #5 */
/* @0x1b14b0 mov r3, #4 */
/* @0x1b14b4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1b14b8 mov r2, #1065353216 */
/* @0x1b14bc mov r1, #0 */
/* @0x1b14c0 movt r1, #0xbf80 */
/* @0x1b14c4 str r4, [r0, #0x3c] */
/* @0x1b14c8 str r4, [r0, #0x2c] */
/* @0x1b14cc str r4, [r0, #0x1c] */
/* @0x1b14d0 str r4, [r0, #0xc] */
/* @0x1b14d4 str r1, [r0] */
/* @0x1b14d8 str r1, [r0, #0x4] */
/* @0x1b14dc str r1, [r0, #0x10] */
/* @0x1b14e0 str r1, [r0, #0x24] */
/* @0x1b14e4 str r2, [r0, #0x14] */
/* @0x1b14e8 str r2, [r0, #0x20] */
/* @0x1b14ec str r2, [r0, #0x30] */
/* @0x1b14f0 str r2, [r0, #0x34] */
/* @0x1b14f4 str r2, [r0, #0x38] */
/* @0x1b14f8 str r2, [r0, #0x28] */
/* @0x1b14fc str r2, [r0, #0x18] */
/* @0x1b1500 str r2, [r0, #0x8] */
/* @0x1b1504 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b1508 mov r1, r8 */
/* @0x1b150c mov r0, #2 */
/* @0x1b1510 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b1514 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b1518 mov r1, r7 */
/* @0x1b151c mov r0, #0 */
/* @0x1b1520 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b1524 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b1528 mov r1, r5 */
/* @0x1b152c mov r0, #1 */
/* @0x1b1530 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b1534 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b1538 mov r0, r9 */
/* @0x1b153c bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv> */
/* @0x1b1540 b 0x1b11cc <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x2c> */
/* @0x1b1544 ldr r1, [pc, #0xac] */
/* @0x1b1548 mov r2, #24 */
/* @0x1b154c mov r0, #5 */
/* @0x1b1550 mov r3, #4 */
/* @0x1b1554 ldr r1, [r6, r1] */
/* @0x1b1558 ldr r1, [r1] */
/* @0x1b155c ldr r1, [r1] */
/* @0x1b1560 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1b1564 mov r2, #0 */
/* @0x1b1568 mov r1, #0 */
/* @0x1b156c movt r1, #0xbf80 */
/* @0x1b1570 str r2, [r0, #0x10] */
/* @0x1b1574 str r2, [r0, #0x14] */
/* @0x1b1578 str r2, [r0, #0x28] */
/* @0x1b157c str r2, [r0, #0x44] */
/* @0x1b1580 mov r2, #1065353216 */
/* @0x1b1584 str r4, [r0, #0x54] */
/* @0x1b1588 str r4, [r0, #0x3c] */
/* @0x1b158c str r4, [r0, #0x24] */
/* @0x1b1590 str r4, [r0, #0xc] */
/* @0x1b1594 str r1, [r0] */
/* @0x1b1598 str r1, [r0, #0x4] */
/* @0x1b159c str r1, [r0, #0x18] */
/* @0x1b15a0 str r1, [r0, #0x34] */
/* @0x1b15a4 str r2, [r0, #0x1c] */
/* @0x1b15a8 str r2, [r0, #0x2c] */
/* @0x1b15ac str r2, [r0, #0x30] */
/* @0x1b15b0 str r2, [r0, #0x40] */
/* @0x1b15b4 str r2, [r0, #0x48] */
/* @0x1b15b8 str r2, [r0, #0x4c] */
/* @0x1b15bc str r2, [r0, #0x58] */
/* @0x1b15c0 str r2, [r0, #0x5c] */
/* @0x1b15c4 str r2, [r0, #0x50] */
/* @0x1b15c8 str r2, [r0, #0x38] */
/* @0x1b15cc str r2, [r0, #0x20] */
/* @0x1b15d0 str r2, [r0, #0x8] */
/* @0x1b15d4 b 0x1b1504 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x364> */
/* @0x1b15d8 cmp r4, #0 */
/* @0x1b15dc lslge r4, r4, #24 */
/* @0x1b15e0 movlt r4, #0 */
/* @0x1b15e4 b 0x1b1494 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x2f4> */
/* @0x1b15e8 cmnmi pc, #0 */
/* @0x1b15ec mlaeq r4, r0, r10, r0 */
/* @0x1b15f0 .word 0xffffbcd8 */
/* @0x1b15f4 .word 0xffffe828 */
/* @0x1b15f8 .word 0xffffe4e0 */
/* @0x1b15fc .word 0xffffc0a8 */

/* ── FUNC 0x1b1600 · DrawLayerInstanceElement(tagYYRECT*, CLayer*, CLayerInstanceElement*) · size=388 · insn=97 */
/* @0x1b1600 push {r4, r5, r6, lr} */
/* @0x1b1604 sub sp, sp, #24 */
/* @0x1b1608 ldr r4, [r2, #0x20] */
/* @0x1b160c cmp r4, #0 */
/* @0x1b1610 beq 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc> */
/* @0x1b1614 ldrb r3, [r4, #0x68] */
/* @0x1b1618 cmp r3, #0 */
/* @0x1b161c bne 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc> */
/* @0x1b1620 ldrb r5, [r4, #0x69] */
/* @0x1b1624 cmp r5, #0 */
/* @0x1b1628 bne 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc> */
/* @0x1b162c ldrb r3, [r4, #0x65] */
/* @0x1b1630 cmp r3, #0 */
/* @0x1b1634 beq 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc> */
/* @0x1b1638 ldr r0, [r4, #0x80] */
/* @0x1b163c cmp r0, #0 */
/* @0x1b1640 beq 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc> */
/* @0x1b1644 mov r1, #8 */
/* @0x1b1648 mov r2, r5 */
/* @0x1b164c bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b1650 cmp r0, #0 */
/* @0x1b1654 bne 0x1b16e4 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xe4> */
/* @0x1b1658 ldr r0, [r4, #0x8c] */
/* @0x1b165c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b1660 subs r6, r0, #0 */
/* @0x1b1664 beq 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc> */
/* @0x1b1668 vmov.f32 s14, #1.000000e+00 */
/* @0x1b166c vldr s15, [r4, #152] */
/* @0x1b1670 ldr r5, [pc, #0x104] */
/* @0x1b1674 ldr r5, [pc, r5] */
/* @0x1b1678 str r4, [r5] */
/* @0x1b167c vcmp.f32 s15, s14 */
/* @0x1b1680 vmrs APSR_nzcv, fpscr */
/* @0x1b1684 bne 0x1b1710 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0x110> */
/* @0x1b1688 vldr s13, [r4, #156] */
/* @0x1b168c vcmp.f32 s13, s14 */
/* @0x1b1690 vldr s14, [r4, #160] */
/* @0x1b1694 vmrs APSR_nzcv, fpscr */
/* @0x1b1698 beq 0x1b1724 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0x124> */
/* @0x1b169c ldr r12, [r4, #0xa8] */
/* @0x1b16a0 vldr s12, [r4, #164] */
/* @0x1b16a4 vldr s11, [r4, #144] */
/* @0x1b16a8 vcvt.s32.f32 s11, s11 */
/* @0x1b16ac ldr r2, [r4, #0xb4] */
/* @0x1b16b0 mov r0, r6 */
/* @0x1b16b4 ldr r3, [r4, #0xb8] */
/* @0x1b16b8 vstr s15, [sp] */
/* @0x1b16bc vstr s13, [sp, #4] */
/* @0x1b16c0 vstr s14, [sp, #8] */
/* @0x1b16c4 str r12, [sp, #0xc] */
/* @0x1b16c8 vstr s12, [sp, #16] */
/* @0x1b16cc vmov r1, s11 */
/* @0x1b16d0 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x1b16d4 mov r3, #0 */
/* @0x1b16d8 str r3, [r5] */
/* @0x1b16dc add sp, sp, #24 */
/* @0x1b16e0 pop {r4, r5, r6, pc} */
/* @0x1b16e4 ldr r6, [pc, #0x94] */
/* @0x1b16e8 mov r0, r4 */
/* @0x1b16ec mov r1, r4 */
/* @0x1b16f0 mov r2, #8 */
/* @0x1b16f4 ldr r6, [pc, r6] */
/* @0x1b16f8 mov r3, r5 */
/* @0x1b16fc str r4, [r6] */
/* @0x1b1700 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b1704 str r5, [r6] */
/* @0x1b1708 add sp, sp, #24 */
/* @0x1b170c pop {r4, r5, r6, pc} */
/* @0x1b1710 ldr r12, [r4, #0xa8] */
/* @0x1b1714 vldr s13, [r4, #156] */
/* @0x1b1718 vldr s14, [r4, #160] */
/* @0x1b171c vldr s12, [r4, #164] */
/* @0x1b1720 b 0x1b16a4 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xa4> */
/* @0x1b1724 vcmp.f32 s14, #0 */
/* @0x1b1728 ldr r12, [r4, #0xa8] */
/* @0x1b172c vmrs APSR_nzcv, fpscr */
/* @0x1b1730 bne 0x1b171c <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0x11c> */
/* @0x1b1734 mvn r3, #-16777216 */
/* @0x1b1738 cmp r12, r3 */
/* @0x1b173c bne 0x1b171c <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0x11c> */
/* @0x1b1740 vmov.f32 s11, #1.000000e+00 */
/* @0x1b1744 vldr s12, [r4, #164] */
/* @0x1b1748 vcmp.f32 s12, s11 */
/* @0x1b174c vmrs APSR_nzcv, fpscr */
/* @0x1b1750 bne 0x1b16a4 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xa4> */
/* @0x1b1754 ldr r0, [r4, #0x90] */
/* @0x1b1758 bl 0xb6910 <floorf@plt> */
/* @0x1b175c ldr r2, [r4, #0xb4] */
/* @0x1b1760 ldr r3, [r4, #0xb8] */
/* @0x1b1764 vmov s15, r0 */
/* @0x1b1768 mov r0, r6 */
/* @0x1b176c vcvt.s32.f32 s15, s15 */
/* @0x1b1770 vmov r1, s15 */
/* @0x1b1774 bl 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x1b1778 b 0x1b16d4 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xd4> */
/* @0x1b177c eoreq r12, r3, r0, asr #5 */
/* @0x1b1780 eoreq r12, r3, r0, asr #4 */

/* ── FUNC 0x1b1784 · DrawLayerOldTilemapElement(tagYYRECT*, CLayer*, CLayerOldTilemapElement*) · size=440 · insn=110 */
/* @0x1b1784 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b1788 vpush {d8, d9} */
/* @0x1b178c mov r8, r0 */
/* @0x1b1790 ldr r7, [r2, #0x24] */
/* @0x1b1794 sub sp, sp, #36 */
/* @0x1b1798 mov r9, r1 */
/* @0x1b179c cmp r7, #0 */
/* @0x1b17a0 beq 0x1b1930 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x1ac> */
/* @0x1b17a4 ldr r6, [r7, #0x700] */
/* @0x1b17a8 cmp r6, #0 */
/* @0x1b17ac addgt r4, r7, #52 */
/* @0x1b17b0 movgt r5, #0 */
/* @0x1b17b4 ble 0x1b1924 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x1a0> */
/* @0x1b17b8 ldrb r3, [r4] */
/* @0x1b17bc cmp r3, #0 */
/* @0x1b17c0 beq 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190> */
/* @0x1b17c4 vldr s10, [r4, #-32] */
/* @0x1b17c8 vcvt.f32.s32 s11, s10 */
/* @0x1b17cc vldr s14, [r4, #-52] */
/* @0x1b17d0 vldr s12, [r4, #-16] */
/* @0x1b17d4 vldr s15, [r4, #-48] */
/* @0x1b17d8 vldr s13, [r4, #-12] */
/* @0x1b17dc ldr r0, [r4, #-0x2c] */
/* @0x1b17e0 vmov.f32 s16, s14 */
/* @0x1b17e4 vmla.f32 s16, s11, s12 */
/* @0x1b17e8 vldr s11, [r4, #-28] */
/* @0x1b17ec vcvt.f32.s32 s12, s11 */
/* @0x1b17f0 vmov.f32 s17, s15 */
/* @0x1b17f4 vmla.f32 s17, s12, s13 */
/* @0x1b17f8 vcmpe.f32 s14, s16 */
/* @0x1b17fc vmrs APSR_nzcv, fpscr */
/* @0x1b1800 vcmp.f32 s14, s16 */
/* @0x1b1804 vmovpl.f32 s18, s16 */
/* @0x1b1808 vmovmi.f32 s18, s14 */
/* @0x1b180c vmrs APSR_nzcv, fpscr */
/* @0x1b1810 vcmpe.f32 s15, s17 */
/* @0x1b1814 vmovgt.f32 s16, s14 */
/* @0x1b1818 vmrs APSR_nzcv, fpscr */
/* @0x1b181c vcmp.f32 s15, s17 */
/* @0x1b1820 vmovpl.f32 s19, s17 */
/* @0x1b1824 vmovmi.f32 s19, s15 */
/* @0x1b1828 vmrs APSR_nzcv, fpscr */
/* @0x1b182c vmovgt.f32 s17, s15 */
/* @0x1b1830 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1b1834 cmp r0, #0 */
/* @0x1b1838 beq 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190> */
/* @0x1b183c vldr s12, [r8, #8] */
/* @0x1b1840 vcvt.f32.s32 s15, s12 */
/* @0x1b1844 vcmpe.f32 s18, s15 */
/* @0x1b1848 vmrs APSR_nzcv, fpscr */
/* @0x1b184c bhi 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190> */
/* @0x1b1850 vldr s13, [r8, #12] */
/* @0x1b1854 vcvt.f32.s32 s15, s13 */
/* @0x1b1858 vcmpe.f32 s19, s15 */
/* @0x1b185c vmrs APSR_nzcv, fpscr */
/* @0x1b1860 bhi 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190> */
/* @0x1b1864 vldr s14, [r8] */
/* @0x1b1868 vcvt.f32.s32 s15, s14 */
/* @0x1b186c vcmpe.f32 s16, s15 */
/* @0x1b1870 vmrs APSR_nzcv, fpscr */
/* @0x1b1874 blt 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190> */
/* @0x1b1878 vldr s10, [r8, #4] */
/* @0x1b187c vcvt.f32.s32 s15, s10 */
/* @0x1b1880 vcmpe.f32 s17, s15 */
/* @0x1b1884 vmrs APSR_nzcv, fpscr */
/* @0x1b1888 blt 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190> */
/* @0x1b188c ldr r0, [r4, #-0x2c] */
/* @0x1b1890 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b1894 vldr s11, [r4, #-32] */
/* @0x1b1898 vcvt.f32.s32 s13, s11 */
/* @0x1b189c ldr r2, [r4, #-0x28] */
/* @0x1b18a0 ldr r3, [r4, #-0x24] */
/* @0x1b18a4 vldr s14, [r9, #8] */
/* @0x1b18a8 vldr s15, [r9, #12] */
/* @0x1b18ac mov r1, #0 */
/* @0x1b18b0 vmov s12, r2 */
/* @0x1b18b4 vmov s11, r3 */
/* @0x1b18b8 vstr s13, [sp] */
/* @0x1b18bc vldr s10, [r4, #-28] */
/* @0x1b18c0 vcvt.f32.s32 s13, s10 */
/* @0x1b18c4 vstr s13, [sp, #4] */
/* @0x1b18c8 vldr s13, [r4, #-52] */
/* @0x1b18cc vadd.f32 s14, s13, s14 */
/* @0x1b18d0 vstr s14, [sp, #8] */
/* @0x1b18d4 vldr s14, [r4, #-48] */
/* @0x1b18d8 vadd.f32 s15, s14, s15 */
/* @0x1b18dc vstr s15, [sp, #12] */
/* @0x1b18e0 ldr r12, [r4, #-0x10] */
/* @0x1b18e4 vcvt.f32.s32 s12, s12 */
/* @0x1b18e8 str r12, [sp, #0x10] */
/* @0x1b18ec ldr r12, [r4, #-0xc] */
/* @0x1b18f0 str r12, [sp, #0x14] */
/* @0x1b18f4 vcvt.f32.s32 s11, s11 */
/* @0x1b18f8 ldr r12, [r4, #-0x8] */
/* @0x1b18fc vmov r2, s12 */
/* @0x1b1900 str r12, [sp, #0x18] */
/* @0x1b1904 ldr r12, [r4, #-0x4] */
/* @0x1b1908 vmov r3, s11 */
/* @0x1b190c str r12, [sp, #0x1c] */
/* @0x1b1910 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf> */
/* @0x1b1914 add r5, r5, #1 */
/* @0x1b1918 add r4, r4, #56 */
/* @0x1b191c cmp r5, r6 */
/* @0x1b1920 bne 0x1b17b8 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x34> */
/* @0x1b1924 ldr r7, [r7, #0x704] */
/* @0x1b1928 cmp r7, #0 */
/* @0x1b192c bne 0x1b17a4 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x20> */
/* @0x1b1930 add sp, sp, #36 */
/* @0x1b1934 vpop {d8, d9} */
/* @0x1b1938 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1b193c · DrawLayerSpriteElement(tagYYRECT*, CLayer*, CLayerSpriteElement*) · size=136 · insn=34 */
/* @0x1b193c push {r4, r5, lr} */
/* @0x1b1940 sub sp, sp, #28 */
/* @0x1b1944 ldr r0, [r2, #0x1c] */
/* @0x1b1948 mov r4, r2 */
/* @0x1b194c mov r5, r1 */
/* @0x1b1950 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1b1954 cmp r0, #0 */
/* @0x1b1958 beq 0x1b19bc <_Z22DrawLayerSpriteElementP9tagYYRECTP6CLayerP19CLayerSpriteElement+0x80> */
/* @0x1b195c ldr r0, [r4, #0x1c] */
/* @0x1b1960 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b1964 vldr s15, [r4, #32] */
/* @0x1b1968 vcvt.s32.f32 s15, s15 */
/* @0x1b196c ldr r3, [r4, #0x38] */
/* @0x1b1970 vldr s12, [r4, #64] */
/* @0x1b1974 vldr s13, [r5, #8] */
/* @0x1b1978 str r3, [sp, #0xc] */
/* @0x1b197c vldr s14, [r4, #68] */
/* @0x1b1980 ldr r2, [r4, #0x2c] */
/* @0x1b1984 ldr r3, [r4, #0x30] */
/* @0x1b1988 vmov r1, s15 */
/* @0x1b198c vldr s15, [r5, #12] */
/* @0x1b1990 vadd.f32 s13, s12, s13 */
/* @0x1b1994 str r2, [sp] */
/* @0x1b1998 str r3, [sp, #0x4] */
/* @0x1b199c ldr r2, [r4, #0x34] */
/* @0x1b19a0 ldr r3, [r4, #0x3c] */
/* @0x1b19a4 str r2, [sp, #0x8] */
/* @0x1b19a8 str r3, [sp, #0x10] */
/* @0x1b19ac vadd.f32 s15, s14, s15 */
/* @0x1b19b0 vmov r2, s13 */
/* @0x1b19b4 vmov r3, s15 */
/* @0x1b19b8 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x1b19bc add sp, sp, #28 */
/* @0x1b19c0 pop {r4, r5, pc} */

/* ── FUNC 0x1b19c4 · CalcLayerTilemapParams(CBackground*, RTexture**, float&, float&, float&, float&, float&, float&, float&, float&, bool&) · size=836 · insn=209 */
/* @0x1b19c4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b19c8 subs r6, r1, #0 */
/* @0x1b19cc mov r9, r2 */
/* @0x1b19d0 mov r8, r3 */
/* @0x1b19d4 mov r4, r0 */
/* @0x1b19d8 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b19dc cmp r0, #0 */
/* @0x1b19e0 streq r0, [r6] */
/* @0x1b19e4 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b19e8 bl 0xc2d78 <_ZN11CBackground8GetWidthEv> */
/* @0x1b19ec mov r10, r0 */
/* @0x1b19f0 mov r0, r4 */
/* @0x1b19f4 bl 0xc2d80 <_ZN11CBackground9GetHeightEv> */
/* @0x1b19f8 mov r7, r0 */
/* @0x1b19fc mov r0, r4 */
/* @0x1b1a00 bl 0xc1e8c <_ZN11CBackground10GetTextureEv> */
/* @0x1b1a04 mov r5, r0 */
/* @0x1b1a08 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1b1a0c cmp r0, #0 */
/* @0x1b1a10 bne 0x1b1a3c <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x78> */
/* @0x1b1a14 cmn r5, #1 */
/* @0x1b1a18 beq 0x1b1a30 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x6c> */
/* @0x1b1a1c ldr r7, [pc, #0x2dc] */
/* @0x1b1a20 ldr r7, [pc, r7] */
/* @0x1b1a24 ldr r3, [r7] */
/* @0x1b1a28 cmp r5, r3 */
/* @0x1b1a2c bhs 0x1b1af8 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x134> */
/* @0x1b1a30 mov r3, #0 */
/* @0x1b1a34 str r3, [r6] */
/* @0x1b1a38 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b1a3c ldr r3, [pc, #0x2c0] */
/* @0x1b1a40 vmov s11, r7 */
/* @0x1b1a44 vmov s9, r10 */
/* @0x1b1a48 ldr r1, [sp, #0x20] */
/* @0x1b1a4c ldr r3, [pc, r3] */
/* @0x1b1a50 vcvt.f32.s32 s13, s11 */
/* @0x1b1a54 mov r2, #1 */
/* @0x1b1a58 ldr r3, [r3, #0x4] */
/* @0x1b1a5c ldr r3, [r3, r5, lsl #2] */
/* @0x1b1a60 vcvt.f32.s32 s12, s9 */
/* @0x1b1a64 str r3, [r6] */
/* @0x1b1a68 vldr s15, [r4, #36] */
/* @0x1b1a6c vldr s10, [r4, #28] */
/* @0x1b1a70 vldr s11, [r4, #32] */
/* @0x1b1a74 ldr r3, [sp, #0x24] */
/* @0x1b1a78 vcvt.f32.s32 s14, s15 */
/* @0x1b1a7c vldr s15, [r4, #40] */
/* @0x1b1a80 vcvt.f32.s32 s10, s10 */
/* @0x1b1a84 vcvt.f32.s32 s11, s11 */
/* @0x1b1a88 vdiv.f32 s14, s14, s12 */
/* @0x1b1a8c vdiv.f32 s11, s11, s13 */
/* @0x1b1a90 vdiv.f32 s12, s10, s12 */
/* @0x1b1a94 vcvt.f32.s32 s15, s15 */
/* @0x1b1a98 vstr s12, [r1] */
/* @0x1b1a9c vstr s11, [r3] */
/* @0x1b1aa0 vstr s14, [r9] */
/* @0x1b1aa4 mov r3, #1065353216 */
/* @0x1b1aa8 vdiv.f32 s15, s15, s13 */
/* @0x1b1aac vadd.f32 s14, s14, s14 */
/* @0x1b1ab0 vstr s15, [r8] */
/* @0x1b1ab4 vldr s13, [r1] */
/* @0x1b1ab8 ldr r1, [sp, #0x28] */
/* @0x1b1abc vadd.f32 s14, s13, s14 */
/* @0x1b1ac0 vadd.f32 s15, s15, s15 */
/* @0x1b1ac4 vstr s14, [r1] */
/* @0x1b1ac8 ldr r1, [sp, #0x24] */
/* @0x1b1acc vldr s14, [r1] */
/* @0x1b1ad0 ldr r1, [sp, #0x2c] */
/* @0x1b1ad4 vadd.f32 s15, s14, s15 */
/* @0x1b1ad8 vstr s15, [r1] */
/* @0x1b1adc ldr r1, [sp, #0x34] */
/* @0x1b1ae0 str r3, [r1] */
/* @0x1b1ae4 ldr r1, [sp, #0x30] */
/* @0x1b1ae8 str r3, [r1] */
/* @0x1b1aec ldr r3, [sp, #0x38] */
/* @0x1b1af0 strb r2, [r3] */
/* @0x1b1af4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b1af8 ldrsh r10, [r5, #20] */
/* @0x1b1afc mov r0, r10 */
/* @0x1b1b00 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1b1b04 cmp r0, #0 */
/* @0x1b1b08 streq r0, [r6] */
/* @0x1b1b0c popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b1b10 ldr r3, [r7, #0x4] */
/* @0x1b1b14 ldrsh r2, [r5, #8] */
/* @0x1b1b18 ldr r3, [r3, r10, lsl #2] */
/* @0x1b1b1c cmp r2, #0 */
/* @0x1b1b20 str r3, [r6] */
/* @0x1b1b24 bne 0x1b1ba4 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x1e0> */
/* @0x1b1b28 ldrsh r2, [r5, #10] */
/* @0x1b1b2c cmp r2, #0 */
/* @0x1b1b30 bne 0x1b1ba4 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x1e0> */
/* @0x1b1b34 ldrh r1, [r5, #12] */
/* @0x1b1b38 ldrh r2, [r5, #16] */
/* @0x1b1b3c cmp r2, r1 */
/* @0x1b1b40 sxth r0, r1 */
/* @0x1b1b44 beq 0x1b1bb0 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x1ec> */
/* @0x1b1b48 ldrh r3, [r5, #18] */
/* @0x1b1b4c ldrsh r1, [r5, #4] */
/* @0x1b1b50 sxth r2, r2 */
/* @0x1b1b54 ldrsh r5, [r5, #6] */
/* @0x1b1b58 sxth r3, r3 */
/* @0x1b1b5c vmov s12, r2 */
/* @0x1b1b60 ldr r2, [sp, #0x30] */
/* @0x1b1b64 vmov s14, r1 */
/* @0x1b1b68 ldr r1, [sp, #0x34] */
/* @0x1b1b6c vcvt.f32.s32 s12, s12 */
/* @0x1b1b70 vmov s15, r3 */
/* @0x1b1b74 mov r3, #0 */
/* @0x1b1b78 vmov s13, r5 */
/* @0x1b1b7c vcvt.f32.s32 s14, s14 */
/* @0x1b1b80 vcvt.f32.s32 s13, s13 */
/* @0x1b1b84 vcvt.f32.s32 s15, s15 */
/* @0x1b1b88 vdiv.f32 s14, s14, s12 */
/* @0x1b1b8c vdiv.f32 s15, s13, s15 */
/* @0x1b1b90 vstr s14, [r2] */
/* @0x1b1b94 ldr r2, [sp, #0x38] */
/* @0x1b1b98 vstr s15, [r1] */
/* @0x1b1b9c strb r3, [r2] */
/* @0x1b1ba0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b1ba4 ldrh r2, [r5, #16] */
/* @0x1b1ba8 ldrh r3, [r5, #18] */
/* @0x1b1bac b 0x1b1b4c <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x188> */
/* @0x1b1bb0 ldrh r2, [r5, #18] */
/* @0x1b1bb4 ldrsh r12, [r5, #14] */
/* @0x1b1bb8 sxth r6, r2 */
/* @0x1b1bbc cmp r12, r6 */
/* @0x1b1bc0 movne r3, r2 */
/* @0x1b1bc4 movne r2, r1 */
/* @0x1b1bc8 bne 0x1b1b4c <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x188> */
/* @0x1b1bcc ldrsh r1, [r5, #4] */
/* @0x1b1bd0 vmov s9, r0 */
/* @0x1b1bd4 vldr s7, [r4, #28] */
/* @0x1b1bd8 vcvt.f32.s32 s7, s7 */
/* @0x1b1bdc vldr s13, [r4, #32] */
/* @0x1b1be0 vldr s8, [r4, #36] */
/* @0x1b1be4 vmov s6, r1 */
/* @0x1b1be8 ldrsh r1, [r5, #6] */
/* @0x1b1bec vldr s11, [r4, #40] */
/* @0x1b1bf0 mov r2, #1 */
/* @0x1b1bf4 vmov s5, r1 */
/* @0x1b1bf8 ldrsh r1, [r5] */
/* @0x1b1bfc ldrsh r5, [r5, #2] */
/* @0x1b1c00 vcvt.f32.s32 s4, s9 */
/* @0x1b1c04 vmov s9, r12 */
/* @0x1b1c08 vmov s10, r1 */
/* @0x1b1c0c ldr r1, [sp, #0x30] */
/* @0x1b1c10 vmov s12, r5 */
/* @0x1b1c14 vcvt.f32.s32 s15, s9 */
/* @0x1b1c18 vcvt.f32.s32 s6, s6 */
/* @0x1b1c1c vcvt.f32.s32 s5, s5 */
/* @0x1b1c20 vdiv.f32 s6, s6, s4 */
/* @0x1b1c24 vdiv.f32 s15, s5, s15 */
/* @0x1b1c28 vstr s6, [r1] */
/* @0x1b1c2c ldr r1, [sp, #0x34] */
/* @0x1b1c30 vstr s15, [r1] */
/* @0x1b1c34 vldr s9, [r3, #8] */
/* @0x1b1c38 vmul.f32 s9, s7, s9 */
/* @0x1b1c3c ldr r1, [sp, #0x30] */
/* @0x1b1c40 vldr s15, [r1] */
/* @0x1b1c44 ldr r1, [sp, #0x20] */
/* @0x1b1c48 vmul.f32 s15, s9, s15 */
/* @0x1b1c4c vcvt.f32.s32 s13, s13 */
/* @0x1b1c50 vstr s15, [r1] */
/* @0x1b1c54 vldr s14, [r3, #12] */
/* @0x1b1c58 ldr r1, [sp, #0x34] */
/* @0x1b1c5c vldr s15, [r1] */
/* @0x1b1c60 ldr r1, [sp, #0x24] */
/* @0x1b1c64 vmul.f32 s14, s13, s14 */
/* @0x1b1c68 vmul.f32 s15, s14, s15 */
/* @0x1b1c6c vcvt.f32.s32 s8, s8 */
/* @0x1b1c70 vstr s15, [r1] */
/* @0x1b1c74 vldr s13, [r3, #8] */
/* @0x1b1c78 ldr r1, [sp, #0x30] */
/* @0x1b1c7c vldr s14, [r1] */
/* @0x1b1c80 vldr s9, [r3, #12] */
/* @0x1b1c84 ldr r1, [sp, #0x34] */
/* @0x1b1c88 vldr s15, [r1] */
/* @0x1b1c8c ldr r1, [sp, #0x20] */
/* @0x1b1c90 vmul.f32 s8, s8, s13 */
/* @0x1b1c94 vmul.f32 s14, s8, s14 */
/* @0x1b1c98 vcvt.f32.s32 s11, s11 */
/* @0x1b1c9c vcvt.f32.s32 s10, s10 */
/* @0x1b1ca0 vmul.f32 s11, s11, s9 */
/* @0x1b1ca4 vmov.f32 s9, s14 */
/* @0x1b1ca8 vmla.f32 s9, s13, s10 */
/* @0x1b1cac vmul.f32 s15, s11, s15 */
/* @0x1b1cb0 vstr s9, [r9] */
/* @0x1b1cb4 vldr s13, [r3, #12] */
/* @0x1b1cb8 ldr r3, [sp, #0x28] */
/* @0x1b1cbc vcvt.f32.s32 s12, s12 */
/* @0x1b1cc0 vmov.f32 s11, s15 */
/* @0x1b1cc4 vmla.f32 s11, s12, s13 */
/* @0x1b1cc8 vadd.f32 s14, s14, s14 */
/* @0x1b1ccc vstr s11, [r8] */
/* @0x1b1cd0 vldr s13, [r1] */
/* @0x1b1cd4 vadd.f32 s15, s15, s15 */
/* @0x1b1cd8 vadd.f32 s14, s13, s14 */
/* @0x1b1cdc vstr s14, [r3] */
/* @0x1b1ce0 ldr r1, [sp, #0x24] */
/* @0x1b1ce4 vldr s14, [r1] */
/* @0x1b1ce8 vadd.f32 s15, s14, s15 */
/* @0x1b1cec ldr r1, [sp, #0x38] */
/* @0x1b1cf0 ldr r3, [sp, #0x2c] */
/* @0x1b1cf4 vstr s15, [r3] */
/* @0x1b1cf8 strb r2, [r1] */
/* @0x1b1cfc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b1d00 .word 0x0023befc */
/* @0x1b1d04 .word 0x0023bed0 */

/* ── FUNC 0x1b1d08 · DrawTile(tagYYRECT*, CBackground*, unsigned int, int, float, float, float) · size=1052 · insn=263 */
/* @0x1b1d08 cmp r0, #0 */
/* @0x1b1d0c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b1d10 vpush {d8, d9, d10, d11} */
/* @0x1b1d14 mov r4, r1 */
/* @0x1b1d18 sub sp, sp, #92 */
/* @0x1b1d1c mov r5, r2 */
/* @0x1b1d20 mov r6, r3 */
/* @0x1b1d24 beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0> */
/* @0x1b1d28 cmp r1, #0 */
/* @0x1b1d2c beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0> */
/* @0x1b1d30 mov r0, r1 */
/* @0x1b1d34 add r2, sp, #52 */
/* @0x1b1d38 add r3, sp, #60 */
/* @0x1b1d3c add r1, sp, #84 */
/* @0x1b1d40 str r3, [sp] */
/* @0x1b1d44 add r3, sp, #64 */
/* @0x1b1d48 str r3, [sp, #0x4] */
/* @0x1b1d4c add r3, sp, #68 */
/* @0x1b1d50 str r3, [sp, #0x8] */
/* @0x1b1d54 add r3, sp, #72 */
/* @0x1b1d58 str r3, [sp, #0xc] */
/* @0x1b1d5c add r3, sp, #76 */
/* @0x1b1d60 str r3, [sp, #0x10] */
/* @0x1b1d64 add r3, sp, #80 */
/* @0x1b1d68 str r3, [sp, #0x14] */
/* @0x1b1d6c add r3, sp, #51 */
/* @0x1b1d70 str r3, [sp, #0x18] */
/* @0x1b1d74 add r3, sp, #56 */
/* @0x1b1d78 bl 0x1b19c4 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb> */
/* @0x1b1d7c ldr r7, [r4, #0x30] */
/* @0x1b1d80 mov r0, r6 */
/* @0x1b1d84 mov r1, r7 */
/* @0x1b1d88 bl 0x318dec <__aeabi_idivmod> */
/* @0x1b1d8c ldr r2, [sp, #0x54] */
/* @0x1b1d90 cmp r2, #0 */
/* @0x1b1d94 beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0> */
/* @0x1b1d98 ldr r3, [pc, #0x380] */
/* @0x1b1d9c ldrb r0, [sp, #0x33] */
/* @0x1b1da0 ldr r3, [pc, r3] */
/* @0x1b1da4 cmp r0, #0 */
/* @0x1b1da8 ldr r3, [r3] */
/* @0x1b1dac beq 0x1b1dd4 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xcc> */
/* @0x1b1db0 ubfx r3, r5, #0x0, #0x13 */
/* @0x1b1db4 ldr r9, [r4, #0x1c] */
/* @0x1b1db8 cmp r3, #0 */
/* @0x1b1dbc ldr r8, [r4, #0x20] */
/* @0x1b1dc0 ldr r6, [r4, #0x2c] */
/* @0x1b1dc4 bne 0x1b1f50 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x248> */
/* @0x1b1dc8 add sp, sp, #92 */
/* @0x1b1dcc vpop {d8, d9, d10, d11} */
/* @0x1b1dd0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b1dd4 and r5, r5, r3 */
/* @0x1b1dd8 ldr r12, [r4, #0x1c] */
/* @0x1b1ddc ubfx r3, r5, #0x0, #0x13 */
/* @0x1b1de0 vldr s17, [sp, #76] */
/* @0x1b1de4 cmp r3, #0 */
/* @0x1b1de8 ldr r2, [r4, #0x20] */
/* @0x1b1dec vldr s16, [sp, #80] */
/* @0x1b1df0 ldr r0, [r4, #0x24] */
/* @0x1b1df4 ldr r8, [r4, #0x28] */
/* @0x1b1df8 beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0> */
/* @0x1b1dfc mla r7, r3, r7, r1 */
/* @0x1b1e00 ldr r6, [r4, #0x40] */
/* @0x1b1e04 ldr r6, [r6, r7, lsl #2] */
/* @0x1b1e08 cmp r6, #0 */
/* @0x1b1e0c beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0> */
/* @0x1b1e10 ldr r7, [r4, #0x2c] */
/* @0x1b1e14 vmov s10, r0 */
/* @0x1b1e18 vmov s12, r8 */
/* @0x1b1e1c mov r0, r6 */
/* @0x1b1e20 vmov s13, r12 */
/* @0x1b1e24 vmov s15, r2 */
/* @0x1b1e28 mov r1, r7 */
/* @0x1b1e2c vcvt.f32.s32 s22, s13 */
/* @0x1b1e30 vcvt.f32.s32 s19, s10 */
/* @0x1b1e34 vcvt.f32.s32 s18, s12 */
/* @0x1b1e38 vcvt.f32.s32 s21, s15 */
/* @0x1b1e3c bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x1b1e40 mov r0, r6 */
/* @0x1b1e44 vmul.f32 s19, s17, s19 */
/* @0x1b1e48 vmul.f32 s20, s22, s17 */
/* @0x1b1e4c vadd.f32 s15, s19, s19 */
/* @0x1b1e50 vmov s5, r1 */
/* @0x1b1e54 mov r1, r7 */
/* @0x1b1e58 vadd.f32 s15, s15, s20 */
/* @0x1b1e5c vcvt.f32.u32 s14, s5 */
/* @0x1b1e60 vmla.f32 s19, s14, s15 */
/* @0x1b1e64 bl 0x318c48 <__udivsi3> */
/* @0x1b1e68 ubfx r3, r5, #0x1c, #0x1 */
/* @0x1b1e6c tst r5, #1073741824 */
/* @0x1b1e70 vldr s10, [pc, #676] */
/* @0x1b1e74 vmov s13, r3 */
/* @0x1b1e78 ubfx r3, r5, #0x1d, #0x1 */
/* @0x1b1e7c vmov s8, r3 */
/* @0x1b1e80 ubfx r3, r5, #0x1e, #0x1 */
/* @0x1b1e84 vmov s9, r3 */
/* @0x1b1e88 vmul.f32 s18, s16, s18 */
/* @0x1b1e8c vmov s5, r0 */
/* @0x1b1e90 vmul.f32 s12, s21, s16 */
/* @0x1b1e94 vadd.f32 s7, s18, s18 */
/* @0x1b1e98 vmov.f32 s14, #1.000000e+00 */
/* @0x1b1e9c vadd.f32 s7, s7, s12 */
/* @0x1b1ea0 vcvt.f32.u32 s6, s5 */
/* @0x1b1ea4 vmov.f32 s15, #-2.000000e+00 */
/* @0x1b1ea8 vcvt.f32.s32 s13, s13 */
/* @0x1b1eac vmla.f32 s18, s6, s7 */
/* @0x1b1eb0 vmov.f32 s6, s14 */
/* @0x1b1eb4 vmla.f32 s6, s13, s15 */
/* @0x1b1eb8 vmov.f32 s11, #5.000000e-01 */
/* @0x1b1ebc vcvt.f32.s32 s8, s8 */
/* @0x1b1ec0 vcvt.f32.s32 s9, s9 */
/* @0x1b1ec4 vmla.f32 s14, s8, s15 */
/* @0x1b1ec8 vmul.f32 s22, s22, s11 */
/* @0x1b1ecc vmov.f32 s13, s6 */
/* @0x1b1ed0 vmul.f32 s15, s9, s10 */
/* @0x1b1ed4 vmul.f32 s11, s21, s11 */
/* @0x1b1ed8 bne 0x1b20d8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x3d0> */
/* @0x1b1edc vldr s9, [sp, #152] */
/* @0x1b1ee0 vldr s5, [sp, #156] */
/* @0x1b1ee4 vmls.f32 s22, s22, s6 */
/* @0x1b1ee8 vmls.f32 s11, s11, s14 */
/* @0x1b1eec vadd.f32 s10, s9, s22 */
/* @0x1b1ef0 vadd.f32 s11, s5, s11 */
/* @0x1b1ef4 vstr s15, [sp, #20] */
/* @0x1b1ef8 mvn r3, #0 */
/* @0x1b1efc vstr s12, [sp] */
/* @0x1b1f00 str r3, [sp, #0x18] */
/* @0x1b1f04 str r3, [sp, #0x1c] */
/* @0x1b1f08 vstr s10, [sp, #4] */
/* @0x1b1f0c str r3, [sp, #0x20] */
/* @0x1b1f10 vstr s11, [sp, #8] */
/* @0x1b1f14 str r3, [sp, #0x24] */
/* @0x1b1f18 mov r0, r4 */
/* @0x1b1f1c vmov r1, s19 */
/* @0x1b1f20 vmov r2, s18 */
/* @0x1b1f24 vmov r3, s20 */
/* @0x1b1f28 vmov.f32 s15, #1.000000e+00 */
/* @0x1b1f2c vdiv.f32 s17, s15, s17 */
/* @0x1b1f30 vstr s15, [sp, #40] */
/* @0x1b1f34 vdiv.f32 s16, s15, s16 */
/* @0x1b1f38 vmul.f32 s13, s13, s17 */
/* @0x1b1f3c vmul.f32 s14, s14, s16 */
/* @0x1b1f40 vstr s13, [sp, #12] */
/* @0x1b1f44 vstr s14, [sp, #16] */
/* @0x1b1f48 bl 0xc2238 <_ZN11CBackground11DrawGeneralEfffffffffjjjjf> */
/* @0x1b1f4c b 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0> */
/* @0x1b1f50 mla r7, r3, r7, r1 */
/* @0x1b1f54 ldr r0, [r4, #0x40] */
/* @0x1b1f58 ldr r7, [r0, r7, lsl #2] */
/* @0x1b1f5c cmp r7, #0 */
/* @0x1b1f60 beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0> */
/* @0x1b1f64 ldr r1, [r2] */
/* @0x1b1f68 mov r3, #6 */
/* @0x1b1f6c mov r2, #24 */
/* @0x1b1f70 mov r0, #4 */
/* @0x1b1f74 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1b1f78 mov r1, r6 */
/* @0x1b1f7c mov r4, r0 */
/* @0x1b1f80 mov r0, r7 */
/* @0x1b1f84 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x1b1f88 mov r0, r7 */
/* @0x1b1f8c vldr s15, [sp, #68] */
/* @0x1b1f90 vldr s16, [sp, #52] */
/* @0x1b1f94 vmov s5, r1 */
/* @0x1b1f98 mov r1, r6 */
/* @0x1b1f9c vcvt.f32.u32 s14, s5 */
/* @0x1b1fa0 vmla.f32 s16, s14, s15 */
/* @0x1b1fa4 bl 0x318c48 <__udivsi3> */
/* @0x1b1fa8 vldr s10, [sp, #72] */
/* @0x1b1fac vldr s15, [sp, #56] */
/* @0x1b1fb0 vmov s6, r9 */
/* @0x1b1fb4 tst r5, #1879048192 */
/* @0x1b1fb8 vmov s7, r8 */
/* @0x1b1fbc vldr s14, [sp, #60] */
/* @0x1b1fc0 vldr s13, [sp, #64] */
/* @0x1b1fc4 vcvt.f32.s32 s11, s6 */
/* @0x1b1fc8 vcvt.f32.s32 s12, s7 */
/* @0x1b1fcc vmov s8, r0 */
/* @0x1b1fd0 vcvt.f32.u32 s9, s8 */
/* @0x1b1fd4 vmla.f32 s15, s9, s10 */
/* @0x1b1fd8 vldr s9, [sp, #152] */
/* @0x1b1fdc vldr s10, [sp, #156] */
/* @0x1b1fe0 vadd.f32 s14, s16, s14 */
/* @0x1b1fe4 vadd.f32 s13, s15, s13 */
/* @0x1b1fe8 vadd.f32 s11, s9, s11 */
/* @0x1b1fec vadd.f32 s12, s10, s12 */
/* @0x1b1ff0 beq 0x1b20f4 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x3ec> */
/* @0x1b1ff4 tst r5, #268435456 */
/* @0x1b1ff8 vmovne.f32 s8, s16 */
/* @0x1b1ffc vmoveq.f32 s8, s14 */
/* @0x1b2000 vmovne.f32 s16, s14 */
/* @0x1b2004 tst r5, #536870912 */
/* @0x1b2008 vmovne.f32 s10, s13 */
/* @0x1b200c vmoveq.f32 s10, s15 */
/* @0x1b2010 vmovne.f32 s13, s15 */
/* @0x1b2014 tst r5, #1073741824 */
/* @0x1b2018 bne 0x1b2108 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x400> */
/* @0x1b201c vmov.f32 s7, s13 */
/* @0x1b2020 vmov.f32 s9, s16 */
/* @0x1b2024 vmov.f32 s14, s8 */
/* @0x1b2028 vmov.f32 s15, s10 */
/* @0x1b202c mvn r3, #0 */
/* @0x1b2030 vldr s6, [sp, #156] */
/* @0x1b2034 vldr s5, [sp, #152] */
/* @0x1b2038 vstr s6, [r4, #4] */
/* @0x1b203c vstr s5, [r4] */
/* @0x1b2040 vstr s6, [r4, #28] */
/* @0x1b2044 vldr s5, [sp, #160] */
/* @0x1b2048 vldr s6, [sp, #152] */
/* @0x1b204c vstr s9, [r4, #64] */
/* @0x1b2050 vstr s9, [r4, #88] */
/* @0x1b2054 vstr s5, [r4, #8] */
/* @0x1b2058 vldr s9, [sp, #156] */
/* @0x1b205c vstr s16, [r4, #16] */
/* @0x1b2060 vstr s15, [r4, #20] */
/* @0x1b2064 vstr s11, [r4, #24] */
/* @0x1b2068 vstr s5, [r4, #32] */
/* @0x1b206c vstr s14, [r4, #40] */
/* @0x1b2070 vstr s10, [r4, #44] */
/* @0x1b2074 vstr s6, [r4, #48] */
/* @0x1b2078 vstr s12, [r4, #52] */
/* @0x1b207c vstr s5, [r4, #56] */
/* @0x1b2080 vstr s13, [r4, #68] */
/* @0x1b2084 vstr s6, [r4, #72] */
/* @0x1b2088 vstr s12, [r4, #76] */
/* @0x1b208c vstr s5, [r4, #80] */
/* @0x1b2090 vstr s13, [r4, #92] */
/* @0x1b2094 vstr s11, [r4, #96] */
/* @0x1b2098 vstr s9, [r4, #100] */
/* @0x1b209c vstr s5, [r4, #104] */
/* @0x1b20a0 vstr s14, [r4, #112] */
/* @0x1b20a4 vstr s10, [r4, #116] */
/* @0x1b20a8 vstr s11, [r4, #120] */
/* @0x1b20ac vstr s12, [r4, #124] */
/* @0x1b20b0 vstr s5, [r4, #128] */
/* @0x1b20b4 str r3, [r4, #0xc] */
/* @0x1b20b8 vstr s8, [r4, #136] */
/* @0x1b20bc str r3, [r4, #0x24] */
/* @0x1b20c0 vstr s7, [r4, #140] */
/* @0x1b20c4 str r3, [r4, #0x3c] */
/* @0x1b20c8 str r3, [r4, #0x54] */
/* @0x1b20cc str r3, [r4, #0x6c] */
/* @0x1b20d0 str r3, [r4, #0x84] */
/* @0x1b20d4 b 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0> */
/* @0x1b20d8 vmla.f32 s11, s11, s14 */
/* @0x1b20dc vldr s7, [sp, #152] */
/* @0x1b20e0 vldr s8, [sp, #156] */
/* @0x1b20e4 vmls.f32 s22, s22, s6 */
/* @0x1b20e8 vadd.f32 s10, s7, s11 */
/* @0x1b20ec vadd.f32 s11, s8, s22 */
/* @0x1b20f0 b 0x1b1ef4 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x1ec> */
/* @0x1b20f4 vmov.f32 s7, s13 */
/* @0x1b20f8 vmov.f32 s8, s14 */
/* @0x1b20fc vmov.f32 s9, s16 */
/* @0x1b2100 vmov.f32 s10, s15 */
/* @0x1b2104 b 0x1b202c <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x324> */
/* @0x1b2108 vmov.f32 s7, s10 */
/* @0x1b210c vmov.f32 s9, s8 */
/* @0x1b2110 vmov.f32 s14, s16 */
/* @0x1b2114 vmov.f32 s15, s13 */
/* @0x1b2118 b 0x1b202c <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x324> */
/* @0x1b211c adcsgt r0, r4, #0 */
/* @0x1b2120 eoreq lr, r3, r8, ror r10 */

/* ── FUNC 0x1b2124 · DrawLayerTilemapElement(tagYYRECT*, CLayer*, CLayerTilemapElement*, float, float, float) · size=1808 · insn=452 */
/* @0x1b2124 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b2128 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1b212c sub sp, sp, #140 */
/* @0x1b2130 vldr s27, [sp, #240] */
/* @0x1b2134 mov r4, r0 */
/* @0x1b2138 ldr r0, [r2, #0x1c] */
/* @0x1b213c mov r7, r2 */
/* @0x1b2140 str r1, [sp, #0x40] */
/* @0x1b2144 vmov s26, r3 */
/* @0x1b2148 vldr s16, [sp, #244] */
/* @0x1b214c bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1b2150 cmp r0, #0 */
/* @0x1b2154 bne 0x1b2164 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x40> */
/* @0x1b2158 add sp, sp, #140 */
/* @0x1b215c vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1b2160 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b2164 ldr r0, [r7, #0x1c] */
/* @0x1b2168 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1b216c add r3, sp, #108 */
/* @0x1b2170 add r1, sp, #132 */
/* @0x1b2174 str r3, [sp] */
/* @0x1b2178 add r2, sp, #100 */
/* @0x1b217c add r3, sp, #112 */
/* @0x1b2180 str r3, [sp, #0x4] */
/* @0x1b2184 add r3, sp, #116 */
/* @0x1b2188 str r3, [sp, #0x8] */
/* @0x1b218c add r3, sp, #120 */
/* @0x1b2190 str r3, [sp, #0xc] */
/* @0x1b2194 add r3, sp, #124 */
/* @0x1b2198 str r3, [sp, #0x10] */
/* @0x1b219c add r3, sp, #128 */
/* @0x1b21a0 str r3, [sp, #0x14] */
/* @0x1b21a4 add r3, sp, #99 */
/* @0x1b21a8 str r3, [sp, #0x18] */
/* @0x1b21ac add r3, sp, #104 */
/* @0x1b21b0 mov r11, r0 */
/* @0x1b21b4 bl 0x1b19c4 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb> */
/* @0x1b21b8 ldr r10, [sp, #0x40] */
/* @0x1b21bc cmp r10, #0 */
/* @0x1b21c0 beq 0x1b21e8 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0xc4> */
/* @0x1b21c4 vldr s15, [r7, #32] */
/* @0x1b21c8 vldr s26, [r10, #8] */
/* @0x1b21cc vldr s27, [r10, #12] */
/* @0x1b21d0 vadd.f32 s26, s26, s15 */
/* @0x1b21d4 vldr s15, [r7, #36] */
/* @0x1b21d8 ldr r3, [pc, #0x3ec] */
/* @0x1b21dc ldr r3, [pc, r3] */
/* @0x1b21e0 vldr s16, [r3] */
/* @0x1b21e4 vadd.f32 s27, s27, s15 */
/* @0x1b21e8 ldr r3, [sp, #0x84] */
/* @0x1b21ec cmp r3, #0 */
/* @0x1b21f0 beq 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34> */
/* @0x1b21f4 ldr r3, [pc, #0x3d4] */
/* @0x1b21f8 ldrb r2, [sp, #0x63] */
/* @0x1b21fc ldr r3, [pc, r3] */
/* @0x1b2200 ldr r1, [r7, #0x38] */
/* @0x1b2204 cmp r2, #0 */
/* @0x1b2208 ldr r3, [r3] */
/* @0x1b220c and r10, r3, r1 */
/* @0x1b2210 bne 0x1b247c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x358> */
/* @0x1b2214 vmov.f32 s16, #1.000000e+00 */
/* @0x1b2218 vldr s9, [r11, #28] */
/* @0x1b221c vldr s10, [r11, #32] */
/* @0x1b2220 vldr s13, [r11, #36] */
/* @0x1b2224 vldr s14, [r11, #40] */
/* @0x1b2228 ldr r1, [r7, #0x2c] */
/* @0x1b222c vldr s29, [sp, #124] */
/* @0x1b2230 vldr s30, [sp, #128] */
/* @0x1b2234 cmp r1, #0 */
/* @0x1b2238 vcvt.f32.s32 s21, s9 */
/* @0x1b223c vcvt.f32.s32 s22, s10 */
/* @0x1b2240 vcvt.f32.s32 s17, s13 */
/* @0x1b2244 vcvt.f32.s32 s18, s14 */
/* @0x1b2248 vmul.f32 s21, s21, s29 */
/* @0x1b224c vmul.f32 s22, s22, s30 */
/* @0x1b2250 vmul.f32 s17, s29, s17 */
/* @0x1b2254 vmul.f32 s18, s30, s18 */
/* @0x1b2258 vdiv.f32 s29, s16, s29 */
/* @0x1b225c vdiv.f32 s30, s16, s30 */
/* @0x1b2260 ble 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34> */
/* @0x1b2264 str r2, [sp, #0x44] */
/* @0x1b2268 mov r3, r2 */
/* @0x1b226c ldr r2, [r7, #0x28] */
/* @0x1b2270 mvn r9, #0 */
/* @0x1b2274 vldr s28, [pc, #844] */
/* @0x1b2278 vmov.f32 s20, #-2.000000e+00 */
/* @0x1b227c vmov.f32 s19, #5.000000e-01 */
/* @0x1b2280 cmp r2, #0 */
/* @0x1b2284 ble 0x1b245c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x338> */
/* @0x1b2288 lsl r5, r3, #2 */
/* @0x1b228c mov r8, r3 */
/* @0x1b2290 mov r4, #0 */
/* @0x1b2294 ldr r3, [r7, #0x34] */
/* @0x1b2298 ldr r6, [r3, r5] */
/* @0x1b229c and r6, r6, r10 */
/* @0x1b22a0 ubfx r3, r6, #0x0, #0x13 */
/* @0x1b22a4 cmp r3, #0 */
/* @0x1b22a8 beq 0x1b2444 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x320> */
/* @0x1b22ac vldr s15, [r7, #48] */
/* @0x1b22b0 vcvt.s32.f32 s15, s15 */
/* @0x1b22b4 ldr r0, [r11, #0x30] */
/* @0x1b22b8 ldr r1, [r11, #0x40] */
/* @0x1b22bc vmov r12, s15 */
/* @0x1b22c0 mla r3, r0, r3, r12 */
/* @0x1b22c4 ldr r3, [r1, r3, lsl #2] */
/* @0x1b22c8 cmp r3, #0 */
/* @0x1b22cc mov r0, r3 */
/* @0x1b22d0 beq 0x1b2444 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x320> */
/* @0x1b22d4 vldr s31, [r11, #28] */
/* @0x1b22d8 vmov r12, s31 */
/* @0x1b22dc ldr r2, [r11, #0x20] */
/* @0x1b22e0 vmov.f32 s23, s17 */
/* @0x1b22e4 ldr r1, [sp, #0x44] */
/* @0x1b22e8 str r2, [sp, #0x3c] */
/* @0x1b22ec ldr r2, [r11, #0x2c] */
/* @0x1b22f0 vcvt.f32.s32 s31, s31 */
/* @0x1b22f4 str r3, [sp, #0x30] */
/* @0x1b22f8 str r2, [sp, #0x38] */
/* @0x1b22fc vmul.f32 s31, s31, s19 */
/* @0x1b2300 mul r12, r12, r4 */
/* @0x1b2304 vmov s25, r12 */
/* @0x1b2308 ldr r12, [sp, #0x3c] */
/* @0x1b230c vcvt.f32.s32 s25, s25 */
/* @0x1b2310 mul r12, r12, r1 */
/* @0x1b2314 mov r1, r2 */
/* @0x1b2318 vmov s24, r12 */
/* @0x1b231c bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x1b2320 vadd.f32 s15, s17, s17 */
/* @0x1b2324 ldr r3, [sp, #0x30] */
/* @0x1b2328 ldr r2, [sp, #0x38] */
/* @0x1b232c mov r0, r3 */
/* @0x1b2330 vadd.f32 s15, s15, s21 */
/* @0x1b2334 vcvt.f32.s32 s24, s24 */
/* @0x1b2338 vadd.f32 s25, s25, s26 */
/* @0x1b233c vmov s9, r1 */
/* @0x1b2340 mov r1, r2 */
/* @0x1b2344 vcvt.f32.u32 s14, s9 */
/* @0x1b2348 vmla.f32 s23, s14, s15 */
/* @0x1b234c bl 0x318c48 <__udivsi3> */
/* @0x1b2350 ubfx r1, r6, #0x1c, #0x1 */
/* @0x1b2354 ubfx r2, r6, #0x1d, #0x1 */
/* @0x1b2358 vldr s10, [sp, #60] */
/* @0x1b235c tst r6, #1073741824 */
/* @0x1b2360 vmov s13, r1 */
/* @0x1b2364 ubfx r3, r6, #0x1e, #0x1 */
/* @0x1b2368 vmov s14, r2 */
/* @0x1b236c ldr r12, [sp, #0x40] */
/* @0x1b2370 vmov s8, r3 */
/* @0x1b2374 vmov r3, s21 */
/* @0x1b2378 vcvt.f32.s32 s13, s13 */
/* @0x1b237c vmov r1, s23 */
/* @0x1b2380 vcvt.f32.s32 s14, s14 */
/* @0x1b2384 vmov s9, r0 */
/* @0x1b2388 mov r0, r11 */
/* @0x1b238c vcvt.f32.u32 s11, s9 */
/* @0x1b2390 vcvt.f32.s32 s15, s10 */
/* @0x1b2394 vmov.f32 s9, s16 */
/* @0x1b2398 vmov.f32 s10, s16 */
/* @0x1b239c vadd.f32 s12, s18, s18 */
/* @0x1b23a0 vmla.f32 s9, s13, s20 */
/* @0x1b23a4 vmla.f32 s10, s14, s20 */
/* @0x1b23a8 vmul.f32 s15, s15, s19 */
/* @0x1b23ac vadd.f32 s12, s12, s22 */
/* @0x1b23b0 vmov.f32 s7, s18 */
/* @0x1b23b4 vmla.f32 s7, s11, s12 */
/* @0x1b23b8 vmov.f32 s11, s31 */
/* @0x1b23bc vmov r2, s7 */
/* @0x1b23c0 vmov.f32 s12, s15 */
/* @0x1b23c4 vmlsne.f32 s31, s31, s9 */
/* @0x1b23c8 vmlane.f32 s15, s15, s10 */
/* @0x1b23cc vmlseq.f32 s11, s11, s9 */
/* @0x1b23d0 vmlseq.f32 s12, s12, s10 */
/* @0x1b23d4 vadd.f32 s24, s24, s27 */
/* @0x1b23d8 vaddne.f32 s15, s15, s25 */
/* @0x1b23dc vaddne.f32 s31, s31, s24 */
/* @0x1b23e0 vaddeq.f32 s15, s11, s25 */
/* @0x1b23e4 vaddeq.f32 s31, s12, s24 */
/* @0x1b23e8 vcvt.f32.s32 s8, s8 */
/* @0x1b23ec vmov.f32 s13, s9 */
/* @0x1b23f0 vldr s9, [r12, #8] */
/* @0x1b23f4 vmov.f32 s14, s10 */
/* @0x1b23f8 vldr s10, [r12, #12] */
/* @0x1b23fc vstr s22, [sp] */
/* @0x1b2400 str r9, [sp, #0x18] */
/* @0x1b2404 str r9, [sp, #0x1c] */
/* @0x1b2408 vstr s16, [sp, #40] */
/* @0x1b240c str r9, [sp, #0x20] */
/* @0x1b2410 vmul.f32 s8, s8, s28 */
/* @0x1b2414 str r9, [sp, #0x24] */
/* @0x1b2418 vmul.f32 s13, s13, s29 */
/* @0x1b241c vstr s8, [sp, #20] */
/* @0x1b2420 vmul.f32 s14, s14, s30 */
/* @0x1b2424 vstr s13, [sp, #12] */
/* @0x1b2428 vadd.f32 s15, s15, s9 */
/* @0x1b242c vstr s14, [sp, #16] */
/* @0x1b2430 vadd.f32 s31, s31, s10 */
/* @0x1b2434 vstr s15, [sp, #4] */
/* @0x1b2438 vstr s31, [sp, #8] */
/* @0x1b243c bl 0xc2238 <_ZN11CBackground11DrawGeneralEfffffffffjjjjf> */
/* @0x1b2440 ldr r2, [r7, #0x28] */
/* @0x1b2444 add r4, r4, #1 */
/* @0x1b2448 add r5, r5, #4 */
/* @0x1b244c cmp r2, r4 */
/* @0x1b2450 add r3, r4, r8 */
/* @0x1b2454 bgt 0x1b2294 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x170> */
/* @0x1b2458 ldr r1, [r7, #0x2c] */
/* @0x1b245c ldr r12, [sp, #0x44] */
/* @0x1b2460 add r12, r12, #1 */
/* @0x1b2464 str r12, [sp, #0x44] */
/* @0x1b2468 cmp r1, r12 */
/* @0x1b246c bgt 0x1b2280 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x15c> */
/* @0x1b2470 add sp, sp, #140 */
/* @0x1b2474 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1b2478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b247c bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x1b2480 vcvt.s32.f32 s9, s26 */
/* @0x1b2484 movw r2, #0xaaab */
/* @0x1b2488 movt r2, #0x2aaa */
/* @0x1b248c ldr r5, [r11, #0x1c] */
/* @0x1b2490 mov r1, r5 */
/* @0x1b2494 mov r3, r0 */
/* @0x1b2498 ldr r0, [r4, #0x8] */
/* @0x1b249c smull r12, r2, r2, r3 */
/* @0x1b24a0 vmov r12, s9 */
/* @0x1b24a4 vstr s9, [sp, #52] */
/* @0x1b24a8 sub r2, r2, r3, asr #31 */
/* @0x1b24ac str r2, [sp, #0x54] */
/* @0x1b24b0 rsb r0, r12, r0 */
/* @0x1b24b4 add r0, r5, r0 */
/* @0x1b24b8 bl 0x318d10 <__divsi3> */
/* @0x1b24bc vcvt.s32.f32 s10, s27 */
/* @0x1b24c0 ldr r9, [r11, #0x20] */
/* @0x1b24c4 vmov s13, r5 */
/* @0x1b24c8 mov r1, r9 */
/* @0x1b24cc vmov r8, s10 */
/* @0x1b24d0 vcvt.f32.s32 s21, s13 */
/* @0x1b24d4 mov r2, r0 */
/* @0x1b24d8 ldr r0, [r4, #0xc] */
/* @0x1b24dc str r2, [sp, #0x38] */
/* @0x1b24e0 rsb r0, r8, r0 */
/* @0x1b24e4 add r0, r9, r0 */
/* @0x1b24e8 bl 0x318d10 <__divsi3> */
/* @0x1b24ec ldr r12, [sp, #0x34] */
/* @0x1b24f0 mov r1, r5 */
/* @0x1b24f4 mov r6, r0 */
/* @0x1b24f8 ldr r0, [r4] */
/* @0x1b24fc rsb r0, r12, r0 */
/* @0x1b2500 bl 0x318d10 <__divsi3> */
/* @0x1b2504 ldr r3, [r4, #0x4] */
/* @0x1b2508 vmov s14, r9 */
/* @0x1b250c ldr r4, [r7, #0x28] */
/* @0x1b2510 ldr r2, [sp, #0x38] */
/* @0x1b2514 mov r1, r9 */
/* @0x1b2518 vcvt.f32.s32 s22, s14 */
/* @0x1b251c cmp r2, r4 */
/* @0x1b2520 movge r2, r4 */
/* @0x1b2524 str r2, [sp, #0x3c] */
/* @0x1b2528 bic r0, r0, r0, asr #31 */
/* @0x1b252c str r0, [sp, #0x4c] */
/* @0x1b2530 rsb r0, r8, r3 */
/* @0x1b2534 bl 0x318d10 <__divsi3> */
/* @0x1b2538 ldr r2, [r7, #0x2c] */
/* @0x1b253c ldr r12, [sp, #0x3c] */
/* @0x1b2540 ldr r1, [sp, #0x4c] */
/* @0x1b2544 cmp r6, r2 */
/* @0x1b2548 movge r6, r2 */
/* @0x1b254c str r6, [sp, #0x58] */
/* @0x1b2550 rsb r3, r1, r12 */
/* @0x1b2554 ldr r12, [r11, #0x2c] */
/* @0x1b2558 str r12, [sp, #0x44] */
/* @0x1b255c bic r0, r0, r0, asr #31 */
/* @0x1b2560 rsb r2, r0, r6 */
/* @0x1b2564 cmp r0, r6 */
/* @0x1b2568 vmov s20, r0 */
/* @0x1b256c mul r2, r2, r3 */
/* @0x1b2570 str r2, [sp, #0x50] */
/* @0x1b2574 bge 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34> */
/* @0x1b2578 ldr r12, [sp, #0x3c] */
/* @0x1b257c mov r3, #0 */
/* @0x1b2580 mvn r9, #0 */
/* @0x1b2584 str r10, [sp, #0x40] */
/* @0x1b2588 rsb r12, r12, r1 */
/* @0x1b258c str r12, [sp, #0x5c] */
/* @0x1b2590 mov r12, r11 */
/* @0x1b2594 mov r11, r3 */
/* @0x1b2598 vstr s20, [sp, #72] */
/* @0x1b259c ldr r10, [sp, #0x4c] */
/* @0x1b25a0 ldr r0, [sp, #0x3c] */
/* @0x1b25a4 ldr r1, [sp, #0x48] */
/* @0x1b25a8 cmp r10, r0 */
/* @0x1b25ac mla r4, r4, r1, r10 */
/* @0x1b25b0 bge 0x1b27e8 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x6c4> */
/* @0x1b25b4 lsl r5, r4, #2 */
/* @0x1b25b8 ldr r8, [sp, #0x50] */
/* @0x1b25bc mov r4, r10 */
/* @0x1b25c0 vmov s20, r1 */
/* @0x1b25c4 b 0x1b26bc <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x598> */
/* @0x1b25c8 adcsgt r0, r4, #0 */
/* @0x1b25cc eoreq r11, r3, r4, asr #14 */
/* @0x1b25d0 eoreq lr, r3, r12, lsl r6 */
/* @0x1b25d4 tst r6, #268435456 */
/* @0x1b25d8 vmovne.f32 s8, s17 */
/* @0x1b25dc vmoveq.f32 s8, s14 */
/* @0x1b25e0 vmovne.f32 s17, s14 */
/* @0x1b25e4 tst r6, #536870912 */
/* @0x1b25e8 vmovne.f32 s10, s13 */
/* @0x1b25ec vmoveq.f32 s10, s15 */
/* @0x1b25f0 vmovne.f32 s13, s15 */
/* @0x1b25f4 tst r6, #1073741824 */
/* @0x1b25f8 bne 0x1b2808 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x6e4> */
/* @0x1b25fc vmov.f32 s7, s13 */
/* @0x1b2600 vmov.f32 s9, s17 */
/* @0x1b2604 vmov.f32 s14, s8 */
/* @0x1b2608 vmov.f32 s15, s10 */
/* @0x1b260c vstr s19, [r3] */
/* @0x1b2610 vstr s18, [r3, #4] */
/* @0x1b2614 vstr s16, [r3, #8] */
/* @0x1b2618 vstr s17, [r3, #16] */
/* @0x1b261c vstr s15, [r3, #20] */
/* @0x1b2620 str r9, [r3, #0xc] */
/* @0x1b2624 vstr s11, [r3, #24] */
/* @0x1b2628 vstr s18, [r3, #28] */
/* @0x1b262c vstr s16, [r3, #32] */
/* @0x1b2630 vstr s14, [r3, #40] */
/* @0x1b2634 vstr s10, [r3, #44] */
/* @0x1b2638 str r9, [r3, #0x24] */
/* @0x1b263c vstr s19, [r3, #48] */
/* @0x1b2640 vstr s12, [r3, #52] */
/* @0x1b2644 vstr s16, [r3, #56] */
/* @0x1b2648 vstr s9, [r3, #64] */
/* @0x1b264c vstr s13, [r3, #68] */
/* @0x1b2650 str r9, [r3, #0x3c] */
/* @0x1b2654 vstr s19, [r3, #72] */
/* @0x1b2658 vstr s12, [r3, #76] */
/* @0x1b265c vstr s16, [r3, #80] */
/* @0x1b2660 vstr s9, [r3, #88] */
/* @0x1b2664 vstr s13, [r3, #92] */
/* @0x1b2668 str r9, [r3, #0x54] */
/* @0x1b266c vstr s11, [r3, #96] */
/* @0x1b2670 vstr s18, [r3, #100] */
/* @0x1b2674 vstr s16, [r3, #104] */
/* @0x1b2678 vstr s14, [r3, #112] */
/* @0x1b267c vstr s10, [r3, #116] */
/* @0x1b2680 str r9, [r3, #0x6c] */
/* @0x1b2684 vstr s11, [r3, #120] */
/* @0x1b2688 vstr s12, [r3, #124] */
/* @0x1b268c vstr s16, [r3, #128] */
/* @0x1b2690 sub r11, r11, #1 */
/* @0x1b2694 vstr s8, [r3, #136] */
/* @0x1b2698 vstr s7, [r3, #140] */
/* @0x1b269c str r9, [r3, #0x84] */
/* @0x1b26a0 add r3, r3, #144 */
/* @0x1b26a4 ldr r10, [sp, #0x3c] */
/* @0x1b26a8 add r4, r4, #1 */
/* @0x1b26ac sub r8, r8, #1 */
/* @0x1b26b0 add r5, r5, #4 */
/* @0x1b26b4 cmp r4, r10 */
/* @0x1b26b8 beq 0x1b27d8 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x6b4> */
/* @0x1b26bc ldr r2, [r7, #0x34] */
/* @0x1b26c0 ldr r10, [sp, #0x40] */
/* @0x1b26c4 ldr r6, [r2, r5] */
/* @0x1b26c8 and r6, r6, r10 */
/* @0x1b26cc ubfx r2, r6, #0x0, #0x13 */
/* @0x1b26d0 cmp r2, #0 */
/* @0x1b26d4 beq 0x1b26a4 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x580> */
/* @0x1b26d8 vldr s15, [r7, #48] */
/* @0x1b26dc vcvt.s32.f32 s15, s15 */
/* @0x1b26e0 ldr r0, [r12, #0x30] */
/* @0x1b26e4 ldr r1, [r12, #0x40] */
/* @0x1b26e8 vmov r10, s15 */
/* @0x1b26ec mla r2, r0, r2, r10 */
/* @0x1b26f0 ldr r10, [r1, r2, lsl #2] */
/* @0x1b26f4 cmp r10, #0 */
/* @0x1b26f8 beq 0x1b26a4 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x580> */
/* @0x1b26fc cmp r11, #0 */
/* @0x1b2700 bne 0x1b2738 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x614> */
/* @0x1b2704 ldr r11, [sp, #0x54] */
/* @0x1b2708 mov r0, #4 */
/* @0x1b270c ldr r1, [sp, #0x84] */
/* @0x1b2710 mov r2, #24 */
/* @0x1b2714 cmp r11, r8 */
/* @0x1b2718 movge r11, r8 */
/* @0x1b271c add r3, r11, r11, lsl #1 */
/* @0x1b2720 ldr r1, [r1] */
/* @0x1b2724 str r12, [sp, #0x34] */
/* @0x1b2728 lsl r3, r3, #1 */
/* @0x1b272c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1b2730 ldr r12, [sp, #0x34] */
/* @0x1b2734 mov r3, r0 */
/* @0x1b2738 vmov s9, r4 */
/* @0x1b273c mov r0, r10 */
/* @0x1b2740 vmov.f32 s19, s26 */
/* @0x1b2744 ldr r1, [sp, #0x44] */
/* @0x1b2748 str r3, [sp, #0x30] */
/* @0x1b274c str r12, [sp, #0x34] */
/* @0x1b2750 vcvt.f32.s32 s15, s9 */
/* @0x1b2754 vmla.f32 s19, s15, s21 */
/* @0x1b2758 vcvt.f32.s32 s15, s20 */
/* @0x1b275c vmov.f32 s18, s27 */
/* @0x1b2760 vmla.f32 s18, s15, s22 */
/* @0x1b2764 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x1b2768 mov r0, r10 */
/* @0x1b276c vldr s15, [sp, #116] */
/* @0x1b2770 vldr s17, [sp, #100] */
/* @0x1b2774 vmov s10, r1 */
/* @0x1b2778 ldr r1, [sp, #0x44] */
/* @0x1b277c vcvt.f32.u32 s14, s10 */
/* @0x1b2780 vmla.f32 s17, s14, s15 */
/* @0x1b2784 bl 0x318c48 <__udivsi3> */
/* @0x1b2788 vldr s12, [sp, #120] */
/* @0x1b278c vldr s15, [sp, #104] */
/* @0x1b2790 tst r6, #1879048192 */
/* @0x1b2794 vldr s14, [sp, #108] */
/* @0x1b2798 vldr s13, [sp, #112] */
/* @0x1b279c ldr r3, [sp, #0x30] */
/* @0x1b27a0 ldr r12, [sp, #0x34] */
/* @0x1b27a4 vadd.f32 s14, s17, s14 */
/* @0x1b27a8 vadd.f32 s11, s19, s21 */
/* @0x1b27ac vmov s9, r0 */
/* @0x1b27b0 vcvt.f32.u32 s10, s9 */
/* @0x1b27b4 vmla.f32 s15, s10, s12 */
/* @0x1b27b8 vadd.f32 s12, s18, s22 */
/* @0x1b27bc vadd.f32 s13, s15, s13 */
/* @0x1b27c0 bne 0x1b25d4 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x4b0> */
/* @0x1b27c4 vmov.f32 s7, s13 */
/* @0x1b27c8 vmov.f32 s8, s14 */
/* @0x1b27cc vmov.f32 s9, s17 */
/* @0x1b27d0 vmov.f32 s10, s15 */
/* @0x1b27d4 b 0x1b260c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x4e8> */
/* @0x1b27d8 ldr r0, [sp, #0x50] */
/* @0x1b27dc ldr r10, [sp, #0x5c] */
/* @0x1b27e0 add r0, r10, r0 */
/* @0x1b27e4 str r0, [sp, #0x50] */
/* @0x1b27e8 ldr r10, [sp, #0x48] */
/* @0x1b27ec ldr r0, [sp, #0x58] */
/* @0x1b27f0 add r10, r10, #1 */
/* @0x1b27f4 str r10, [sp, #0x48] */
/* @0x1b27f8 cmp r10, r0 */
/* @0x1b27fc beq 0x1b281c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x6f8> */
/* @0x1b2800 ldr r4, [r7, #0x28] */
/* @0x1b2804 b 0x1b259c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x478> */
/* @0x1b2808 vmov.f32 s7, s10 */
/* @0x1b280c vmov.f32 s9, s8 */
/* @0x1b2810 vmov.f32 s14, s17 */
/* @0x1b2814 vmov.f32 s15, s13 */
/* @0x1b2818 b 0x1b260c <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x4e8> */
/* @0x1b281c cmp r11, #0 */
/* @0x1b2820 ble 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34> */
/* @0x1b2824 add r0, r11, r11, lsl #1 */
/* @0x1b2828 lsl r0, r0, #1 */
/* @0x1b282c bl 0x185600 <_ZN8Graphics9FreeVertsEi> */
/* @0x1b2830 b 0x1b2158 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff+0x34> */

/* ── FUNC 0x1b2834 · DrawLayerParticleElement(tagYYRECT*, CLayer*, CLayerParticleElement*) · size=8 · insn=2 */
/* @0x1b2834 ldr r0, [r2, #0x1c] */
/* @0x1b2838 b 0x1a5d98 <_Z23ParticleSystem_AutoDrawi> */

/* ── FUNC 0x1b283c · DrawLayerTileElement(tagYYRECT*, CLayer*, CLayerTileElement*) · size=384 · insn=96 */
/* @0x1b283c ldrb r3, [r2, #0x1c] */
/* @0x1b2840 push {r4, r5, r6, lr} */
/* @0x1b2844 vpush {d8, d9} */
/* @0x1b2848 cmp r3, #0 */
/* @0x1b284c sub sp, sp, #32 */
/* @0x1b2850 mov r4, r2 */
/* @0x1b2854 mov r5, r0 */
/* @0x1b2858 mov r6, r1 */
/* @0x1b285c beq 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174> */
/* @0x1b2860 vldr s10, [r2, #44] */
/* @0x1b2864 vcvt.f32.s32 s11, s10 */
/* @0x1b2868 vldr s14, [r2, #36] */
/* @0x1b286c vldr s12, [r2, #52] */
/* @0x1b2870 vldr s15, [r2, #40] */
/* @0x1b2874 vldr s13, [r2, #56] */
/* @0x1b2878 ldr r0, [r2, #0x20] */
/* @0x1b287c vmov.f32 s16, s14 */
/* @0x1b2880 vmla.f32 s16, s11, s12 */
/* @0x1b2884 vldr s11, [r2, #48] */
/* @0x1b2888 vcvt.f32.s32 s12, s11 */
/* @0x1b288c vmov.f32 s17, s15 */
/* @0x1b2890 vmla.f32 s17, s12, s13 */
/* @0x1b2894 vcmpe.f32 s14, s16 */
/* @0x1b2898 vmrs APSR_nzcv, fpscr */
/* @0x1b289c vcmp.f32 s14, s16 */
/* @0x1b28a0 vmovpl.f32 s18, s16 */
/* @0x1b28a4 vmovmi.f32 s18, s14 */
/* @0x1b28a8 vmrs APSR_nzcv, fpscr */
/* @0x1b28ac vcmpe.f32 s15, s17 */
/* @0x1b28b0 vmovgt.f32 s16, s14 */
/* @0x1b28b4 vmrs APSR_nzcv, fpscr */
/* @0x1b28b8 vcmp.f32 s15, s17 */
/* @0x1b28bc vmovpl.f32 s19, s17 */
/* @0x1b28c0 vmovmi.f32 s19, s15 */
/* @0x1b28c4 vmrs APSR_nzcv, fpscr */
/* @0x1b28c8 vmovgt.f32 s17, s15 */
/* @0x1b28cc bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1b28d0 cmp r0, #0 */
/* @0x1b28d4 beq 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174> */
/* @0x1b28d8 vldr s14, [r5, #8] */
/* @0x1b28dc vcvt.f32.s32 s15, s14 */
/* @0x1b28e0 vcmpe.f32 s18, s15 */
/* @0x1b28e4 vmrs APSR_nzcv, fpscr */
/* @0x1b28e8 bhi 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174> */
/* @0x1b28ec vldr s10, [r5, #12] */
/* @0x1b28f0 vcvt.f32.s32 s15, s10 */
/* @0x1b28f4 vcmpe.f32 s19, s15 */
/* @0x1b28f8 vmrs APSR_nzcv, fpscr */
/* @0x1b28fc bhi 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174> */
/* @0x1b2900 vldr s11, [r5] */
/* @0x1b2904 vcvt.f32.s32 s15, s11 */
/* @0x1b2908 vcmpe.f32 s16, s15 */
/* @0x1b290c vmrs APSR_nzcv, fpscr */
/* @0x1b2910 blt 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174> */
/* @0x1b2914 vldr s15, [r5, #4] */
/* @0x1b2918 vcvt.f32.s32 s15, s15 */
/* @0x1b291c vcmpe.f32 s17, s15 */
/* @0x1b2920 vmrs APSR_nzcv, fpscr */
/* @0x1b2924 blt 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174> */
/* @0x1b2928 ldr r0, [r4, #0x20] */
/* @0x1b292c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b2930 vldr s14, [r4, #44] */
/* @0x1b2934 vldr s15, [r4, #48] */
/* @0x1b2938 vcvt.f32.s32 s14, s14 */
/* @0x1b293c ldr r2, [r4, #0x48] */
/* @0x1b2940 vldr s13, [r6, #8] */
/* @0x1b2944 ldr r3, [r4, #0x4c] */
/* @0x1b2948 vldr s12, [r4, #36] */
/* @0x1b294c ldr r1, [r4, #0x34] */
/* @0x1b2950 vldr s11, [r4, #40] */
/* @0x1b2954 vcvt.f32.s32 s15, s15 */
/* @0x1b2958 vadd.f32 s12, s12, s13 */
/* @0x1b295c vldr s13, [r6, #12] */
/* @0x1b2960 str r1, [sp, #0x10] */
/* @0x1b2964 ldr r1, [r4, #0x44] */
/* @0x1b2968 ldr r12, [r4, #0x40] */
/* @0x1b296c ldr lr, [r4, #0x38] */
/* @0x1b2970 vstr s14, [sp] */
/* @0x1b2974 vstr s15, [sp, #4] */
/* @0x1b2978 vmov s14, r2 */
/* @0x1b297c vmov s15, r3 */
/* @0x1b2980 str r1, [sp, #0x1c] */
/* @0x1b2984 str lr, [sp, #0x14] */
/* @0x1b2988 mov r1, #0 */
/* @0x1b298c str r12, [sp, #0x18] */
/* @0x1b2990 vadd.f32 s13, s11, s13 */
/* @0x1b2994 vstr s12, [sp, #8] */
/* @0x1b2998 vcvt.f32.s32 s14, s14 */
/* @0x1b299c vstr s13, [sp, #12] */
/* @0x1b29a0 vcvt.f32.s32 s15, s15 */
/* @0x1b29a4 vmov r2, s14 */
/* @0x1b29a8 vmov r3, s15 */
/* @0x1b29ac bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf> */
/* @0x1b29b0 add sp, sp, #32 */
/* @0x1b29b4 vpop {d8, d9} */
/* @0x1b29b8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1b29bc · Draw_Room_SetSize() · size=244 · insn=61 */
/* @0x1b29bc push {r3, r4, r5, lr} */
/* @0x1b29c0 ldr r3, [pc, #0xe4] */
/* @0x1b29c4 ldr r3, [pc, r3] */
/* @0x1b29c8 ldr r12, [r3] */
/* @0x1b29cc ldrb r3, [r12, #0x44] */
/* @0x1b29d0 cmp r3, #0 */
/* @0x1b29d4 beq 0x1b2a60 <_Z17Draw_Room_SetSizev+0xa4> */
/* @0x1b29d8 mov r5, #8 */
/* @0x1b29dc mov r2, #0 */
/* @0x1b29e0 mov r4, r5 */
/* @0x1b29e4 ldr r3, [r12, #0x48] */
/* @0x1b29e8 add r2, r2, #1 */
/* @0x1b29ec add r12, r12, #4 */
/* @0x1b29f0 ldrb lr, [r3] */
/* @0x1b29f4 cmp lr, #0 */
/* @0x1b29f8 beq 0x1b2a24 <_Z17Draw_Room_SetSizev+0x68> */
/* @0x1b29fc ldr lr, [r3, #0x1c] */
/* @0x1b2a00 ldr r0, [r3, #0x14] */
/* @0x1b2a04 ldr r1, [r3, #0x20] */
/* @0x1b2a08 ldr r3, [r3, #0x18] */
/* @0x1b2a0c add r0, lr, r0 */
/* @0x1b2a10 cmp r4, r0 */
/* @0x1b2a14 movlt r4, r0 */
/* @0x1b2a18 add r3, r1, r3 */
/* @0x1b2a1c cmp r5, r3 */
/* @0x1b2a20 movlt r5, r3 */
/* @0x1b2a24 cmp r2, #8 */
/* @0x1b2a28 bne 0x1b29e4 <_Z17Draw_Room_SetSizev+0x28> */
/* @0x1b2a2c bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x1b2a30 cmp r4, r0 */
/* @0x1b2a34 bgt 0x1b2a74 <_Z17Draw_Room_SetSizev+0xb8> */
/* @0x1b2a38 bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x1b2a3c cmp r5, r0 */
/* @0x1b2a40 bgt 0x1b2a88 <_Z17Draw_Room_SetSizev+0xcc> */
/* @0x1b2a44 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x1b2a48 cmp r0, r4 */
/* @0x1b2a4c beq 0x1b2a9c <_Z17Draw_Room_SetSizev+0xe0> */
/* @0x1b2a50 mov r0, r4 */
/* @0x1b2a54 mov r1, r5 */
/* @0x1b2a58 pop {r3, r4, r5, lr} */
/* @0x1b2a5c b 0x1698ec <_Z17GR_D3D_Set_Regionii> */
/* @0x1b2a60 ldr r4, [r12, #0x10] */
/* @0x1b2a64 ldr r5, [r12, #0x14] */
/* @0x1b2a68 bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x1b2a6c cmp r4, r0 */
/* @0x1b2a70 ble 0x1b2a38 <_Z17Draw_Room_SetSizev+0x7c> */
/* @0x1b2a74 bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x1b2a78 mov r4, r0 */
/* @0x1b2a7c bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x1b2a80 cmp r5, r0 */
/* @0x1b2a84 ble 0x1b2a44 <_Z17Draw_Room_SetSizev+0x88> */
/* @0x1b2a88 bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x1b2a8c mov r5, r0 */
/* @0x1b2a90 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x1b2a94 cmp r0, r4 */
/* @0x1b2a98 bne 0x1b2a50 <_Z17Draw_Room_SetSizev+0x94> */
/* @0x1b2a9c bl 0x17999c <_Z27GR_Window_Get_Region_Heightv> */
/* @0x1b2aa0 cmp r0, r5 */
/* @0x1b2aa4 bne 0x1b2a50 <_Z17Draw_Room_SetSizev+0x94> */
/* @0x1b2aa8 pop {r3, r4, r5, pc} */
/* @0x1b2aac eoreq r10, r3, r4, ror #30 */

/* ── FUNC 0x1b2ab0 · DrawHardwareCursor(float, float, float) · size=264 · insn=66 */
/* @0x1b2ab0 ldr r12, [pc, #0xfc] */
/* @0x1b2ab4 push {r3, lr} */
/* @0x1b2ab8 vpush {d8, d9} */
/* @0x1b2abc ldr r12, [pc, r12] */
/* @0x1b2ac0 vmov s16, r1 */
/* @0x1b2ac4 mov r3, #6 */
/* @0x1b2ac8 vmov s17, r0 */
/* @0x1b2acc ldr r1, [r12] */
/* @0x1b2ad0 vmov s18, r2 */
/* @0x1b2ad4 mov r0, #4 */
/* @0x1b2ad8 mov r2, #24 */
/* @0x1b2adc bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1b2ae0 vldr s15, [pc, #196] */
/* @0x1b2ae4 vmul.f32 s18, s18, s15 */
/* @0x1b2ae8 vldr s15, [pc, #192] */
/* @0x1b2aec mov r3, #0 */
/* @0x1b2af0 mvn r1, #-16777216 */
/* @0x1b2af4 vcvt.u32.f32 s18, s18 */
/* @0x1b2af8 vsub.f32 s14, s17, s15 */
/* @0x1b2afc vmov r12, s18 */
/* @0x1b2b00 vadd.f32 s13, s17, s15 */
/* @0x1b2b04 vstr s14, [r0, #120] */
/* @0x1b2b08 vstr s14, [r0, #96] */
/* @0x1b2b0c vstr s14, [r0] */
/* @0x1b2b10 str r3, [r0, #0x8c] */
/* @0x1b2b14 str r3, [r0, #0x88] */
/* @0x1b2b18 str r3, [r0, #0x70] */
/* @0x1b2b1c str r3, [r0, #0x2c] */
/* @0x1b2b20 str r3, [r0, #0x14] */
/* @0x1b2b24 str r3, [r0, #0x10] */
/* @0x1b2b28 mov r3, #1065353216 */
/* @0x1b2b2c str r3, [r0, #0x80] */
/* @0x1b2b30 vsub.f32 s14, s16, s15 */
/* @0x1b2b34 vstr s13, [r0, #72] */
/* @0x1b2b38 orr r2, r1, r12, lsl #24 */
/* @0x1b2b3c vstr s13, [r0, #48] */
/* @0x1b2b40 vstr s13, [r0, #24] */
/* @0x1b2b44 str r3, [r0, #0x68] */
/* @0x1b2b48 str r3, [r0, #0x50] */
/* @0x1b2b4c str r3, [r0, #0x38] */
/* @0x1b2b50 str r3, [r0, #0x20] */
/* @0x1b2b54 str r3, [r0, #0x8] */
/* @0x1b2b58 str r3, [r0, #0x74] */
/* @0x1b2b5c str r3, [r0, #0x5c] */
/* @0x1b2b60 str r3, [r0, #0x58] */
/* @0x1b2b64 vadd.f32 s15, s16, s15 */
/* @0x1b2b68 vstr s14, [r0, #124] */
/* @0x1b2b6c vstr s14, [r0, #28] */
/* @0x1b2b70 vstr s14, [r0, #4] */
/* @0x1b2b74 str r2, [r0, #0x84] */
/* @0x1b2b78 str r2, [r0, #0x6c] */
/* @0x1b2b7c str r2, [r0, #0x54] */
/* @0x1b2b80 str r2, [r0, #0x3c] */
/* @0x1b2b84 str r2, [r0, #0x24] */
/* @0x1b2b88 str r2, [r0, #0xc] */
/* @0x1b2b8c vstr s15, [r0, #100] */
/* @0x1b2b90 vstr s15, [r0, #52] */
/* @0x1b2b94 vstr s15, [r0, #76] */
/* @0x1b2b98 str r3, [r0, #0x44] */
/* @0x1b2b9c str r3, [r0, #0x40] */
/* @0x1b2ba0 str r3, [r0, #0x28] */
/* @0x1b2ba4 vpop {d8, d9} */
/* @0x1b2ba8 pop {r3, pc} */
/* @0x1b2bac cmnmi pc, #0 */
/* @0x1b2bb0 andmi r0, r0, #0 */
/* @0x1b2bb4 eoreq sp, r3, r0, ror #26 */

/* ── FUNC 0x1b2bb8 · RenderSurface_AspectAdjusted(int, int, int, int, int, bool, bool, bool) · size=604 · insn=151 */
/* @0x1b2bb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b2bbc vpush {d8, d9} */
/* @0x1b2bc0 sub sp, sp, #20 */
/* @0x1b2bc4 vldr s18, [sp, #72] */
/* @0x1b2bc8 ldr r4, [pc, #0x21c] */
/* @0x1b2bcc mov r10, r1 */
/* @0x1b2bd0 mov r9, r2 */
/* @0x1b2bd4 vmov s17, r3 */
/* @0x1b2bd8 mov r7, r0 */
/* @0x1b2bdc ldrb r8, [sp, #0x4c] */
/* @0x1b2be0 ldrb r6, [sp, #0x54] */
/* @0x1b2be4 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b2be8 ldr r0, [pc, #0x200] */
/* @0x1b2bec add r4, pc, r4 */
/* @0x1b2bf0 ldr r5, [r4, r0] */
/* @0x1b2bf4 ldr r0, [r5] */
/* @0x1b2bf8 bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x1b2bfc bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x1b2c00 cmp r0, #0 */
/* @0x1b2c04 beq 0x1b2d0c <_Z28RenderSurface_AspectAdjustediiiiibbb+0x154> */
/* @0x1b2c08 mov r0, r7 */
/* @0x1b2c0c bl 0x1714d4 <_Z20GR_Surface_Get_Widthi> */
/* @0x1b2c10 mov r11, r0 */
/* @0x1b2c14 mov r0, r7 */
/* @0x1b2c18 bl 0x171518 <_Z21GR_Surface_Get_Heighti> */
/* @0x1b2c1c cmp r6, #0 */
/* @0x1b2c20 mov r7, r0 */
/* @0x1b2c24 bne 0x1b2d64 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x1ac> */
/* @0x1b2c28 cmp r8, #0 */
/* @0x1b2c2c bne 0x1b2d18 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x160> */
/* @0x1b2c30 vcvt.f32.s32 s17, s17 */
/* @0x1b2c34 vldr s15, [pc, #428] */
/* @0x1b2c38 vcvt.f32.s32 s14, s18 */
/* @0x1b2c3c vmov.f32 s16, s15 */
/* @0x1b2c40 vmov s12, r10 */
/* @0x1b2c44 ldr r0, [r5] */
/* @0x1b2c48 mvn r3, #-16777216 */
/* @0x1b2c4c str r3, [sp, #0x4] */
/* @0x1b2c50 vsub.f32 s14, s14, s15 */
/* @0x1b2c54 mov r3, #1065353216 */
/* @0x1b2c58 str r3, [sp, #0x8] */
/* @0x1b2c5c vcvt.f32.s32 s13, s12 */
/* @0x1b2c60 vstr s14, [sp] */
/* @0x1b2c64 vmov s12, r9 */
/* @0x1b2c68 vcvt.f32.s32 s14, s12 */
/* @0x1b2c6c vadd.f32 s14, s14, s15 */
/* @0x1b2c70 vadd.f32 s13, s13, s16 */
/* @0x1b2c74 vmov r2, s14 */
/* @0x1b2c78 vsub.f32 s14, s17, s16 */
/* @0x1b2c7c vmov r1, s13 */
/* @0x1b2c80 vmov r3, s14 */
/* @0x1b2c84 bl 0x171e2c <_Z24GR_Surface_DrawStretchediffffjf> */
/* @0x1b2c88 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b2c8c cmp r6, #0 */
/* @0x1b2c90 beq 0x1b2d0c <_Z28RenderSurface_AspectAdjustediiiiibbb+0x154> */
/* @0x1b2c94 vcvt.s32.f32 s16, s16 */
/* @0x1b2c98 ldr r2, [pc, #0x154] */
/* @0x1b2c9c ldr r8, [pc, #0x154] */
/* @0x1b2ca0 mov r3, #0 */
/* @0x1b2ca4 ldr r6, [pc, #0x150] */
/* @0x1b2ca8 ldr r9, [r4, r2] */
/* @0x1b2cac ldr r5, [pc, #0x14c] */
/* @0x1b2cb0 ldr r7, [pc, #0x14c] */
/* @0x1b2cb4 ldr r12, [pc, #0x14c] */
/* @0x1b2cb8 vcvt.s32.f32 s17, s17 */
/* @0x1b2cbc vstr s16, [r9] */
/* @0x1b2cc0 ldr r8, [r4, r8] */
/* @0x1b2cc4 ldr r0, [pc, #0x140] */
/* @0x1b2cc8 ldr r1, [pc, #0x140] */
/* @0x1b2ccc str r3, [r8] */
/* @0x1b2cd0 ldr r7, [r4, r7] */
/* @0x1b2cd4 vstr s16, [r7] */
/* @0x1b2cd8 ldr r2, [r4, r6] */
/* @0x1b2cdc vstr s17, [r2] */
/* @0x1b2ce0 ldr r2, [r4, r5] */
/* @0x1b2ce4 str r3, [r2] */
/* @0x1b2ce8 ldr r2, [r4, r12] */
/* @0x1b2cec ldr r3, [r4, r0] */
/* @0x1b2cf0 ldr r2, [r2] */
/* @0x1b2cf4 str r2, [r3] */
/* @0x1b2cf8 ldr r0, [r4, r1] */
/* @0x1b2cfc add sp, sp, #20 */
/* @0x1b2d00 vpop {d8, d9} */
/* @0x1b2d04 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b2d08 b 0x168294 <_ZN18RenderStateManager5ForceEv> */
/* @0x1b2d0c add sp, sp, #20 */
/* @0x1b2d10 vpop {d8, d9} */
/* @0x1b2d14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b2d18 vmov s12, r11 */
/* @0x1b2d1c vmov s14, r7 */
/* @0x1b2d20 vcvt.f32.s32 s15, s12 */
/* @0x1b2d24 vcvt.f32.s32 s13, s14 */
/* @0x1b2d28 vdiv.f32 s12, s15, s13 */
/* @0x1b2d2c vcvt.f32.s32 s17, s17 */
/* @0x1b2d30 vdiv.f32 s11, s17, s12 */
/* @0x1b2d34 vcvt.f32.s32 s14, s18 */
/* @0x1b2d38 vcmpe.f32 s11, s14 */
/* @0x1b2d3c vmrs APSR_nzcv, fpscr */
/* @0x1b2d40 bmi 0x1b2dbc <_Z28RenderSurface_AspectAdjustediiiiibbb+0x204> */
/* @0x1b2d44 ble 0x1b2ddc <_Z28RenderSurface_AspectAdjustediiiiibbb+0x224> */
/* @0x1b2d48 vmul.f32 s12, s12, s14 */
/* @0x1b2d4c vldr s15, [pc, #148] */
/* @0x1b2d50 vsub.f32 s16, s17, s12 */
/* @0x1b2d54 vmov.f32 s13, #5.000000e-01 */
/* @0x1b2d58 vmul.f32 s16, s16, s13 */
/* @0x1b2d5c vadd.f32 s17, s16, s12 */
/* @0x1b2d60 b 0x1b2c40 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x88> */
/* @0x1b2d64 mov r0, #8 */
/* @0x1b2d68 mov r1, #0 */
/* @0x1b2d6c bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x1b2d70 mov r0, #1 */
/* @0x1b2d74 mov r1, #0 */
/* @0x1b2d78 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x1b2d7c mov r0, #21 */
/* @0x1b2d80 mov r1, #0 */
/* @0x1b2d84 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x1b2d88 mov r0, #13 */
/* @0x1b2d8c mov r1, #0 */
/* @0x1b2d90 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x1b2d94 mov r0, #12 */
/* @0x1b2d98 mov r1, #0 */
/* @0x1b2d9c bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x1b2da0 mov r0, #5 */
/* @0x1b2da4 mov r1, #0 */
/* @0x1b2da8 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x1b2dac mov r0, #25 */
/* @0x1b2db0 mov r1, #0 */
/* @0x1b2db4 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */
/* @0x1b2db8 b 0x1b2c28 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x70> */
/* @0x1b2dbc vdiv.f32 s13, s13, s15 */
/* @0x1b2dc0 vldr s16, [pc, #32] */
/* @0x1b2dc4 vmul.f32 s13, s17, s13 */
/* @0x1b2dc8 vmov.f32 s12, #5.000000e-01 */
/* @0x1b2dcc vsub.f32 s15, s14, s13 */
/* @0x1b2dd0 vmul.f32 s15, s15, s12 */
/* @0x1b2dd4 vadd.f32 s14, s15, s13 */
/* @0x1b2dd8 b 0x1b2c40 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x88> */
/* @0x1b2ddc vldr s15, [pc, #4] */
/* @0x1b2de0 vmov.f32 s16, s15 */
/* @0x1b2de4 b 0x1b2c40 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x88> */
/* @0x1b2de8 andeq r0, r0, r0 */
/* @0x1b2dec eoreq pc, r3, r4, rrx */
/* @0x1b2df0 .word 0xffffc988 */
/* @0x1b2df4 .word 0xffffeb94 */
/* @0x1b2df8 .word 0xffffeb98 */
/* @0x1b2dfc .word 0xffffebd0 */
/* @0x1b2e00 .word 0xffffebd4 */
/* @0x1b2e04 .word 0xffffebd8 */
/* @0x1b2e08 .word 0xffffe250 */
/* @0x1b2e0c .word 0xffffebdc */
/* @0x1b2e10 .word 0xffffc0a8 */

/* ── FUNC 0x1b2e14 · CalcGUITransformMat(yyMatrix&, yyMatrix&, float&, float&, float&, float&) · size=1008 · insn=252 */
/* @0x1b2e14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b2e18 vpush {d8, d9} */
/* @0x1b2e1c sub sp, sp, #44 */
/* @0x1b2e20 ldr r6, [pc, #0x3b4] */
/* @0x1b2e24 mov r4, r1 */
/* @0x1b2e28 ldr lr, [pc, #0x3b0] */
/* @0x1b2e2c mov r1, #0 */
/* @0x1b2e30 add r6, pc, r6 */
/* @0x1b2e34 str r1, [r0, #0x38] */
/* @0x1b2e38 str r1, [r0, #0x34] */
/* @0x1b2e3c mov r12, #1065353216 */
/* @0x1b2e40 str r1, [r0, #0x30] */
/* @0x1b2e44 mov r7, r2 */
/* @0x1b2e48 str r1, [r0, #0x2c] */
/* @0x1b2e4c mov r10, r3 */
/* @0x1b2e50 str r1, [r0, #0x24] */
/* @0x1b2e54 mov r5, r0 */
/* @0x1b2e58 str r1, [r0, #0x20] */
/* @0x1b2e5c str r1, [r0, #0x1c] */
/* @0x1b2e60 str r1, [r0, #0x18] */
/* @0x1b2e64 str r1, [r0, #0x10] */
/* @0x1b2e68 str r1, [r0, #0xc] */
/* @0x1b2e6c str r1, [r0, #0x8] */
/* @0x1b2e70 str r1, [r0, #0x4] */
/* @0x1b2e74 str r12, [r0, #0x3c] */
/* @0x1b2e78 str r12, [r0, #0x28] */
/* @0x1b2e7c str r12, [r0, #0x14] */
/* @0x1b2e80 str r12, [r0] */
/* @0x1b2e84 add r0, sp, #24 */
/* @0x1b2e88 str r12, [r4, #0x3c] */
/* @0x1b2e8c str r12, [r4, #0x28] */
/* @0x1b2e90 str r12, [r4, #0x14] */
/* @0x1b2e94 str r12, [r4] */
/* @0x1b2e98 str r1, [r4, #0x38] */
/* @0x1b2e9c str r1, [r4, #0x34] */
/* @0x1b2ea0 str r1, [r4, #0x30] */
/* @0x1b2ea4 str r1, [r4, #0x2c] */
/* @0x1b2ea8 str r1, [r4, #0x24] */
/* @0x1b2eac str r1, [r4, #0x20] */
/* @0x1b2eb0 str r1, [r4, #0x1c] */
/* @0x1b2eb4 str r1, [r4, #0x18] */
/* @0x1b2eb8 str r1, [r4, #0x10] */
/* @0x1b2ebc ldr r8, [sp, #0x60] */
/* @0x1b2ec0 ldr r9, [sp, #0x64] */
/* @0x1b2ec4 str r1, [r4, #0xc] */
/* @0x1b2ec8 str r1, [r4, #0x8] */
/* @0x1b2ecc str r1, [r4, #0x4] */
/* @0x1b2ed0 ldr lr, [r6, lr] */
/* @0x1b2ed4 ldr r2, [pc, #0x308] */
/* @0x1b2ed8 ldr r3, [pc, #0x308] */
/* @0x1b2edc ldr r1, [lr] */
/* @0x1b2ee0 str lr, [sp, #0xc] */
/* @0x1b2ee4 cmp r1, #0 */
/* @0x1b2ee8 str r1, [sp, #0x8] */
/* @0x1b2eec add r1, sp, #28 */
/* @0x1b2ef0 ldr r2, [r6, r2] */
/* @0x1b2ef4 str r2, [sp, #0x10] */
/* @0x1b2ef8 ldr r11, [r6, r3] */
/* @0x1b2efc ldr r12, [r2] */
/* @0x1b2f00 add r2, sp, #32 */
/* @0x1b2f04 ldrlt r3, [r11] */
/* @0x1b2f08 strlt r3, [sp, #0x8] */
/* @0x1b2f0c cmp r12, #0 */
/* @0x1b2f10 ldr r3, [pc, #0x2d4] */
/* @0x1b2f14 ldr r3, [r6, r3] */
/* @0x1b2f18 ldrlt r12, [r3] */
/* @0x1b2f1c str r3, [sp, #0x14] */
/* @0x1b2f20 add r3, sp, #36 */
/* @0x1b2f24 str r12, [sp, #0x4] */
/* @0x1b2f28 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x1b2f2c ldr r3, [pc, #0x2bc] */
/* @0x1b2f30 ldr lr, [sp, #0x20] */
/* @0x1b2f34 ldr r0, [sp, #0x18] */
/* @0x1b2f38 ldr r3, [r6, r3] */
/* @0x1b2f3c ldr r1, [sp, #0x24] */
/* @0x1b2f40 ldr r2, [sp, #0x1c] */
/* @0x1b2f44 ldrb r3, [r3] */
/* @0x1b2f48 ldr r12, [sp, #0x4] */
/* @0x1b2f4c cmp r3, #0 */
/* @0x1b2f50 beq 0x1b3120 <_Z19CalcGUITransformMatR8yyMatrixS0_RfS1_S1_S1_+0x30c> */
/* @0x1b2f54 vmov.f32 s18, #5.000000e-01 */
/* @0x1b2f58 vldr s16, [r11] */
/* @0x1b2f5c vcvt.f32.s32 s16, s16 */
/* @0x1b2f60 vmul.f32 s16, s16, s18 */
/* @0x1b2f64 vmov r0, s16 */
/* @0x1b2f68 bl 0xb6910 <floorf@plt> */
/* @0x1b2f6c ldr r1, [sp, #0x14] */
/* @0x1b2f70 vldr s17, [r1] */
/* @0x1b2f74 vcvt.f32.s32 s17, s17 */
/* @0x1b2f78 vmul.f32 s17, s17, s18 */
/* @0x1b2f7c vmov s19, r0 */
/* @0x1b2f80 vmov r0, s17 */
/* @0x1b2f84 bl 0xb6910 <floorf@plt> */
/* @0x1b2f88 ldr r3, [pc, #0x264] */
/* @0x1b2f8c vldr s15, [pc, #580] */
/* @0x1b2f90 ldr r2, [pc, #0x260] */
/* @0x1b2f94 ldr r3, [r6, r3] */
/* @0x1b2f98 vldr s14, [r3] */
/* @0x1b2f9c vcmp.f32 s14, s15 */
/* @0x1b2fa0 ldr r3, [pc, #0x254] */
/* @0x1b2fa4 ldr r3, [r6, r3] */
/* @0x1b2fa8 vldr s15, [r3] */
/* @0x1b2fac vmrs APSR_nzcv, fpscr */
/* @0x1b2fb0 vsubne.f32 s19, s14, s19 */
/* @0x1b2fb4 vldr s14, [pc, #540] */
/* @0x1b2fb8 ldr r3, [pc, #0x240] */
/* @0x1b2fbc vcmp.f32 s15, s14 */
/* @0x1b2fc0 vnegeq.f32 s19, s19 */
/* @0x1b2fc4 vmrs APSR_nzcv, fpscr */
/* @0x1b2fc8 vstr s19, [r8] */
/* @0x1b2fcc vmov s13, r0 */
/* @0x1b2fd0 vsubne.f32 s15, s15, s13 */
/* @0x1b2fd4 vnegeq.f32 s15, s13 */
/* @0x1b2fd8 vstr s15, [r9] */
/* @0x1b2fdc ldr r2, [r6, r2] */
/* @0x1b2fe0 ldr r2, [r2] */
/* @0x1b2fe4 str r2, [r7] */
/* @0x1b2fe8 ldr r3, [r6, r3] */
/* @0x1b2fec vldr s15, [r3] */
/* @0x1b2ff0 vstr s15, [r10] */
/* @0x1b2ff4 vldr s14, [r7] */
/* @0x1b2ff8 vldr s9, [r5, #32] */
/* @0x1b2ffc vldr s8, [r5] */
/* @0x1b3000 vldr s10, [r5, #16] */
/* @0x1b3004 vmul.f32 s8, s8, s14 */
/* @0x1b3008 vldr s12, [r5, #36] */
/* @0x1b300c vldr s11, [r5, #4] */
/* @0x1b3010 vldr s13, [r5, #20] */
/* @0x1b3014 vldr s4, [r5, #52] */
/* @0x1b3018 vldr s5, [r5, #48] */
/* @0x1b301c vldr s6, [r5, #56] */
/* @0x1b3020 vmul.f32 s10, s10, s14 */
/* @0x1b3024 vstr s8, [r5] */
/* @0x1b3028 vldr s7, [r4] */
/* @0x1b302c vmul.f32 s14, s9, s14 */
/* @0x1b3030 vstr s10, [r5, #16] */
/* @0x1b3034 vldr s10, [r4, #16] */
/* @0x1b3038 vmul.f32 s11, s11, s15 */
/* @0x1b303c vstr s14, [r5, #32] */
/* @0x1b3040 vldr s9, [r4, #32] */
/* @0x1b3044 vmul.f32 s14, s12, s15 */
/* @0x1b3048 vstr s11, [r5, #4] */
/* @0x1b304c vldr s8, [r4, #4] */
/* @0x1b3050 vmul.f32 s13, s13, s15 */
/* @0x1b3054 vmov.f32 s15, #1.000000e+00 */
/* @0x1b3058 vstr s13, [r5, #20] */
/* @0x1b305c vldr s12, [r4, #20] */
/* @0x1b3060 vstr s14, [r5, #36] */
/* @0x1b3064 vldr s14, [r9] */
/* @0x1b3068 vldr s13, [r8] */
/* @0x1b306c vldr s11, [r4, #36] */
/* @0x1b3070 vadd.f32 s14, s4, s14 */
/* @0x1b3074 vadd.f32 s13, s5, s13 */
/* @0x1b3078 vstr s14, [r5, #52] */
/* @0x1b307c vadd.f32 s14, s6, s15 */
/* @0x1b3080 vstr s13, [r5, #48] */
/* @0x1b3084 vstr s14, [r5, #56] */
/* @0x1b3088 vldr s13, [r7] */
/* @0x1b308c vldr s14, [r10] */
/* @0x1b3090 vdiv.f32 s13, s15, s13 */
/* @0x1b3094 vdiv.f32 s14, s15, s14 */
/* @0x1b3098 vmul.f32 s7, s7, s13 */
/* @0x1b309c vmul.f32 s8, s8, s14 */
/* @0x1b30a0 vstr s7, [r4] */
/* @0x1b30a4 vmul.f32 s10, s10, s13 */
/* @0x1b30a8 vstr s8, [r4, #4] */
/* @0x1b30ac vmul.f32 s13, s9, s13 */
/* @0x1b30b0 vstr s10, [r4, #16] */
/* @0x1b30b4 vmul.f32 s12, s12, s14 */
/* @0x1b30b8 vstr s13, [r4, #32] */
/* @0x1b30bc vmul.f32 s14, s11, s14 */
/* @0x1b30c0 vstr s12, [r4, #20] */
/* @0x1b30c4 vldr s12, [r4, #56] */
/* @0x1b30c8 vldr s13, [r4, #48] */
/* @0x1b30cc vstr s14, [r4, #36] */
/* @0x1b30d0 vldr s14, [r9] */
/* @0x1b30d4 vldr s9, [r8] */
/* @0x1b30d8 vadd.f32 s17, s17, s14 */
/* @0x1b30dc vldr s10, [r10] */
/* @0x1b30e0 vldr s11, [r7] */
/* @0x1b30e4 vldr s14, [r4, #52] */
/* @0x1b30e8 vadd.f32 s16, s16, s9 */
/* @0x1b30ec vneg.f32 s17, s17 */
/* @0x1b30f0 vneg.f32 s16, s16 */
/* @0x1b30f4 vdiv.f32 s17, s17, s10 */
/* @0x1b30f8 vdiv.f32 s16, s16, s11 */
/* @0x1b30fc vsub.f32 s15, s12, s15 */
/* @0x1b3100 vadd.f32 s16, s13, s16 */
/* @0x1b3104 vstr s15, [r4, #56] */
/* @0x1b3108 vadd.f32 s17, s14, s17 */
/* @0x1b310c vstr s16, [r4, #48] */
/* @0x1b3110 vstr s17, [r4, #52] */
/* @0x1b3114 add sp, sp, #44 */
/* @0x1b3118 vpop {d8, d9} */
/* @0x1b311c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b3120 rsb r0, r0, lr */
/* @0x1b3124 rsb r2, r2, r1 */
/* @0x1b3128 vldr s12, [sp, #8] */
/* @0x1b312c vcvt.f32.s32 s13, s12 */
/* @0x1b3130 vmov s12, r0 */
/* @0x1b3134 ldr r1, [sp, #0xc] */
/* @0x1b3138 vmov s14, r2 */
/* @0x1b313c ldr r3, [r1] */
/* @0x1b3140 ldr r1, [sp, #0x10] */
/* @0x1b3144 cmp r3, #0 */
/* @0x1b3148 vcvt.f32.s32 s15, s12 */
/* @0x1b314c vmov s12, r12 */
/* @0x1b3150 ldr r3, [r1] */
/* @0x1b3154 movlt r2, #1065353216 */
/* @0x1b3158 vcvt.f32.s32 s16, s14 */
/* @0x1b315c vcvt.f32.s32 s14, s12 */
/* @0x1b3160 vdiv.f32 s13, s15, s13 */
/* @0x1b3164 vdiv.f32 s14, s16, s14 */
/* @0x1b3168 vstr s13, [r7] */
/* @0x1b316c vmov.f32 s18, #5.000000e-01 */
/* @0x1b3170 vstr s14, [r10] */
/* @0x1b3174 ldrge r2, [r7] */
/* @0x1b3178 cmp r3, #0 */
/* @0x1b317c movlt r3, #1065353216 */
/* @0x1b3180 str r2, [r7] */
/* @0x1b3184 ldrge r3, [r10] */
/* @0x1b3188 str r3, [r10] */
/* @0x1b318c vmul.f32 s15, s15, s18 */
/* @0x1b3190 vmov r0, s15 */
/* @0x1b3194 bl 0xb6910 <floorf@plt> */
/* @0x1b3198 vmul.f32 s16, s16, s18 */
/* @0x1b319c eor r3, r0, #-2147483648 */
/* @0x1b31a0 vmov r0, s16 */
/* @0x1b31a4 str r3, [r8] */
/* @0x1b31a8 bl 0xb6910 <floorf@plt> */
/* @0x1b31ac vldr s16, [r11] */
/* @0x1b31b0 ldr r3, [sp, #0x14] */
/* @0x1b31b4 vcvt.f32.s32 s16, s16 */
/* @0x1b31b8 vldr s17, [r3] */
/* @0x1b31bc vcvt.f32.s32 s17, s17 */
/* @0x1b31c0 vmul.f32 s16, s16, s18 */
/* @0x1b31c4 vmul.f32 s17, s17, s18 */
/* @0x1b31c8 eor r0, r0, #-2147483648 */
/* @0x1b31cc str r0, [r9] */
/* @0x1b31d0 vldr s15, [r10] */
/* @0x1b31d4 b 0x1b2ff4 <_Z19CalcGUITransformMatR8yyMatrixS0_RfS1_S1_S1_+0x1e0> */
/* @0x1b31d8 svcmi #0x0 */
/* @0x1b31dc eoreq lr, r3, r0, lsr #28 */
/* @0x1b31e0 .word 0xffffdf18 */
/* @0x1b31e4 .word 0xffffdf24 */
/* @0x1b31e8 .word 0xffffe24c */
/* @0x1b31ec .word 0xffffe250 */
/* @0x1b31f0 .word 0xffffdf14 */
/* @0x1b31f4 .word 0xffffdf1c */
/* @0x1b31f8 .word 0xffffdf28 */
/* @0x1b31fc .word 0xffffdf20 */
/* @0x1b3200 .word 0xffffdf2c */

/* ── FUNC 0x1b3204 · Calc_GUI_Scale() · size=300 · insn=75 */
/* @0x1b3204 push {r4, r5, lr} */
/* @0x1b3208 vpush {d8, d9, d10} */
/* @0x1b320c sub sp, sp, #92 */
/* @0x1b3210 ldr r4, [pc, #0x104] */
/* @0x1b3214 add r5, sp, #24 */
/* @0x1b3218 ldr r1, [pc, #0x100] */
/* @0x1b321c add r2, sp, #8 */
/* @0x1b3220 add r4, pc, r4 */
/* @0x1b3224 add r3, sp, #12 */
/* @0x1b3228 mov r0, r5 */
/* @0x1b322c add r12, sp, #16 */
/* @0x1b3230 ldr r1, [r4, r1] */
/* @0x1b3234 str r12, [sp] */
/* @0x1b3238 add r12, sp, #20 */
/* @0x1b323c str r12, [sp, #0x4] */
/* @0x1b3240 bl 0x1b2e14 <_Z19CalcGUITransformMatR8yyMatrixS0_RfS1_S1_S1_> */
/* @0x1b3244 mov r1, r5 */
/* @0x1b3248 mov r0, #0 */
/* @0x1b324c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b3250 vmov.f32 s15, #5.000000e-01 */
/* @0x1b3254 ldr r2, [pc, #0xc8] */
/* @0x1b3258 vldr s19, [sp, #16] */
/* @0x1b325c vldr s16, [sp, #8] */
/* @0x1b3260 ldr r3, [pc, #0xc0] */
/* @0x1b3264 ldr r2, [r4, r2] */
/* @0x1b3268 vldr s20, [r2] */
/* @0x1b326c ldr r3, [r4, r3] */
/* @0x1b3270 vldr s18, [r3] */
/* @0x1b3274 vcvt.f32.s32 s20, s20 */
/* @0x1b3278 vmul.f32 s20, s20, s15 */
/* @0x1b327c vneg.f32 s14, s20 */
/* @0x1b3280 vsub.f32 s14, s14, s19 */
/* @0x1b3284 vdiv.f32 s14, s14, s16 */
/* @0x1b3288 vsub.f32 s19, s20, s19 */
/* @0x1b328c vmov r0, s14 */
/* @0x1b3290 vcvt.f32.s32 s18, s18 */
/* @0x1b3294 vmul.f32 s18, s18, s15 */
/* @0x1b3298 bl 0xb6910 <floorf@plt> */
/* @0x1b329c ldr r3, [pc, #0x88] */
/* @0x1b32a0 ldr r4, [r4, r3] */
/* @0x1b32a4 vdiv.f32 s19, s19, s16 */
/* @0x1b32a8 vmov s14, r0 */
/* @0x1b32ac vcvt.s32.f32 s14, s14 */
/* @0x1b32b0 vmov r0, s19 */
/* @0x1b32b4 vstr s14, [r4] */
/* @0x1b32b8 bl 0xb6994 <ceilf@plt> */
/* @0x1b32bc vneg.f32 s15, s18 */
/* @0x1b32c0 vldr s17, [sp, #20] */
/* @0x1b32c4 vldr s16, [sp, #12] */
/* @0x1b32c8 vsub.f32 s15, s15, s17 */
/* @0x1b32cc vdiv.f32 s15, s15, s16 */
/* @0x1b32d0 vmov s14, r0 */
/* @0x1b32d4 vsub.f32 s17, s18, s17 */
/* @0x1b32d8 vmov r0, s15 */
/* @0x1b32dc vcvt.s32.f32 s14, s14 */
/* @0x1b32e0 vstr s14, [r4, #8] */
/* @0x1b32e4 bl 0xb6910 <floorf@plt> */
/* @0x1b32e8 vdiv.f32 s17, s17, s16 */
/* @0x1b32ec vmov s15, r0 */
/* @0x1b32f0 vcvt.s32.f32 s15, s15 */
/* @0x1b32f4 vmov r0, s17 */
/* @0x1b32f8 vstr s15, [r4, #4] */
/* @0x1b32fc bl 0xb6994 <ceilf@plt> */
/* @0x1b3300 vmov s14, r0 */
/* @0x1b3304 vcvt.s32.f32 s14, s14 */
/* @0x1b3308 vstr s14, [r4, #12] */
/* @0x1b330c bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b3310 add sp, sp, #92 */
/* @0x1b3314 vpop {d8, d9, d10} */
/* @0x1b3318 pop {r4, r5, pc} */
/* @0x1b331c eoreq lr, r3, r0, lsr r10 */
/* @0x1b3320 .word 0xffffdf50 */
/* @0x1b3324 .word 0xffffe24c */
/* @0x1b3328 .word 0xffffe250 */
/* @0x1b332c .word 0xffffe4fc */

/* ── FUNC 0x1b3330 · SetGuiView() · size=232 · insn=58 */
/* @0x1b3330 push {r4, r5, lr} */
/* @0x1b3334 mov r0, #0 */
/* @0x1b3338 ldr r4, [pc, #0xcc] */
/* @0x1b333c sub sp, sp, #76 */
/* @0x1b3340 ldr r5, [pc, #0xc8] */
/* @0x1b3344 mov r1, r0 */
/* @0x1b3348 ldr r4, [pc, r4] */
/* @0x1b334c ldr r5, [pc, r5] */
/* @0x1b3350 ldr r2, [r4] */
/* @0x1b3354 ldr r3, [r5] */
/* @0x1b3358 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x1b335c ldr r3, [pc, #0xb0] */
/* @0x1b3360 ldr r1, [r4] */
/* @0x1b3364 add r4, sp, #8 */
/* @0x1b3368 ldr r3, [pc, r3] */
/* @0x1b336c ldr r2, [r5] */
/* @0x1b3370 mov lr, #1065353216 */
/* @0x1b3374 mov r0, r4 */
/* @0x1b3378 ldr r3, [r3] */
/* @0x1b337c vmov s15, r1 */
/* @0x1b3380 rsb r2, r2, #0 */
/* @0x1b3384 mov r12, #0 */
/* @0x1b3388 vcvt.f32.s32 s15, s15 */
/* @0x1b338c movt r12, #0x46fa */
/* @0x1b3390 mul r2, r3, r2 */
/* @0x1b3394 str r12, [sp] */
/* @0x1b3398 mov r3, lr */
/* @0x1b339c mov r12, #0 */
/* @0x1b33a0 str lr, [sp, #0x44] */
/* @0x1b33a4 str r12, [sp, #0x40] */
/* @0x1b33a8 str r12, [sp, #0x3c] */
/* @0x1b33ac vmov r1, s15 */
/* @0x1b33b0 vmov s15, r2 */
/* @0x1b33b4 str r12, [sp, #0x38] */
/* @0x1b33b8 str r12, [sp, #0x34] */
/* @0x1b33bc vcvt.f32.s32 s15, s15 */
/* @0x1b33c0 str lr, [sp, #0x30] */
/* @0x1b33c4 str lr, [sp, #0x1c] */
/* @0x1b33c8 str lr, [sp, #0x8] */
/* @0x1b33cc str r12, [sp, #0x2c] */
/* @0x1b33d0 str r12, [sp, #0x28] */
/* @0x1b33d4 str r12, [sp, #0x24] */
/* @0x1b33d8 str r12, [sp, #0x20] */
/* @0x1b33dc vmov r2, s15 */
/* @0x1b33e0 str r12, [sp, #0x18] */
/* @0x1b33e4 str r12, [sp, #0x14] */
/* @0x1b33e8 str r12, [sp, #0x10] */
/* @0x1b33ec str r12, [sp, #0xc] */
/* @0x1b33f0 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff> */
/* @0x1b33f4 mov r1, r4 */
/* @0x1b33f8 mov r0, #1 */
/* @0x1b33fc bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b3400 bl 0x1b3204 <_Z14Calc_GUI_Scalev> */
/* @0x1b3404 add sp, sp, #76 */
/* @0x1b3408 pop {r4, r5, pc} */
/* @0x1b340c eoreq r12, r3, r4, asr r11 */
/* @0x1b3410 eoreq r12, r3, r4, asr r11 */
/* @0x1b3414 eoreq r12, r3, r4, ror sp */

/* ── FUNC 0x1b3418 · ExecuteLayerScript(int, int, int, int) · size=300 · insn=75 */
/* @0x1b3418 cmn r1, #1 */
/* @0x1b341c ldr r12, [pc, #0x104] */
/* @0x1b3420 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b3424 add r12, pc, r12 */
/* @0x1b3428 sub sp, sp, #28 */
/* @0x1b342c mov r7, r1 */
/* @0x1b3430 beq 0x1b34d4 <_Z18ExecuteLayerScriptiiii+0xbc> */
/* @0x1b3434 ldr r6, [pc, #0xf0] */
/* @0x1b3438 mov r1, #0 */
/* @0x1b343c ldr r5, [pc, #0xec] */
/* @0x1b3440 ldr r4, [pc, #0xec] */
/* @0x1b3444 str r1, [sp, #0x8] */
/* @0x1b3448 ldr r6, [r12, r6] */
/* @0x1b344c ldr r5, [r12, r5] */
/* @0x1b3450 ldr r4, [r12, r4] */
/* @0x1b3454 ldr r11, [pc, #0xdc] */
/* @0x1b3458 ldr r10, [r6] */
/* @0x1b345c ldr r9, [r5] */
/* @0x1b3460 str r0, [r6] */
/* @0x1b3464 str r2, [r5] */
/* @0x1b3468 ldr r8, [r4] */
/* @0x1b346c str r3, [r4] */
/* @0x1b3470 ldr r3, [r12, r11] */
/* @0x1b3474 ldrb r3, [r3] */
/* @0x1b3478 cmp r3, r1 */
/* @0x1b347c bne 0x1b34dc <_Z18ExecuteLayerScriptiiii+0xc4> */
/* @0x1b3480 ldr r2, [pc, #0xb4] */
/* @0x1b3484 ldr r2, [r12, r2] */
/* @0x1b3488 ldr r1, [r2] */
/* @0x1b348c cmp r1, #0 */
/* @0x1b3490 beq 0x1b34ac <_Z18ExecuteLayerScriptiiii+0x94> */
/* @0x1b3494 mov r0, r7 */
/* @0x1b3498 str r3, [sp, #0x4] */
/* @0x1b349c add r7, sp, #8 */
/* @0x1b34a0 mov r2, r1 */
/* @0x1b34a4 str r7, [sp] */
/* @0x1b34a8 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x1b34ac ldr r3, [sp, #0x14] */
/* @0x1b34b0 sub r3, r3, #1 */
/* @0x1b34b4 bic r3, r3, #-16777216 */
/* @0x1b34b8 bic r3, r3, #3 */
/* @0x1b34bc cmp r3, #0 */
/* @0x1b34c0 addeq r7, sp, #8 */
/* @0x1b34c4 beq 0x1b351c <_Z18ExecuteLayerScriptiiii+0x104> */
/* @0x1b34c8 str r10, [r6] */
/* @0x1b34cc str r9, [r5] */
/* @0x1b34d0 str r8, [r4] */
/* @0x1b34d4 add sp, sp, #28 */
/* @0x1b34d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b34dc ldr r2, [pc, #0x5c] */
/* @0x1b34e0 mov r3, r1 */
/* @0x1b34e4 mov r0, r7 */
/* @0x1b34e8 add r7, sp, #8 */
/* @0x1b34ec ldr r2, [r12, r2] */
/* @0x1b34f0 str r1, [sp, #0x4] */
/* @0x1b34f4 str r7, [sp] */
/* @0x1b34f8 ldr r1, [r2] */
/* @0x1b34fc mov r2, r1 */
/* @0x1b3500 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x1b3504 ldr r3, [sp, #0x14] */
/* @0x1b3508 sub r3, r3, #1 */
/* @0x1b350c bic r3, r3, #-16777216 */
/* @0x1b3510 bic r3, r3, #3 */
/* @0x1b3514 cmp r3, #0 */
/* @0x1b3518 bne 0x1b34c8 <_Z18ExecuteLayerScriptiiii+0xb0> */
/* @0x1b351c mov r0, r7 */
/* @0x1b3520 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1b3524 b 0x1b34c8 <_Z18ExecuteLayerScriptiiii+0xb0> */
/* @0x1b3528 eoreq lr, r3, r12, lsr #16 */
/* @0x1b352c .word 0xffffc168 */
/* @0x1b3530 .word 0xffffc160 */
/* @0x1b3534 .word 0xffffc164 */
/* @0x1b3538 .word 0xffffbf68 */
/* @0x1b353c .word 0xffffc020 */
/* @0x1b3540 .word 0xffffbf64 */

/* ── FUNC 0x1b3544 · ExecuteDrawEvent(tagYYRECT*, int, int) · size=468 · insn=117 */
/* @0x1b3544 push {r4, r5, r6, r7, r8, lr} */
/* @0x1b3548 mov r7, r1 */
/* @0x1b354c mov r8, r2 */
/* @0x1b3550 ldr r12, [pc, #0x1b8] */
/* @0x1b3554 ldm r0, {r0, r1, r2, r3} */
/* @0x1b3558 ldr r12, [pc, r12] */
/* @0x1b355c stm r12, {r0, r1, r2, r3} */
/* @0x1b3560 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b3564 ldr r3, [pc, #0x1a8] */
/* @0x1b3568 ldr r3, [pc, r3] */
/* @0x1b356c ldr r3, [r3] */
/* @0x1b3570 cmp r3, #0 */
/* @0x1b3574 beq 0x1b368c <_Z16ExecuteDrawEventP9tagYYRECTii+0x148> */
/* @0x1b3578 ldr r2, [r3, #0xdc] */
/* @0x1b357c cmp r2, #0 */
/* @0x1b3580 ble 0x1b368c <_Z16ExecuteDrawEventP9tagYYRECTii+0x148> */
/* @0x1b3584 ldr r5, [r3, #0xd8] */
/* @0x1b3588 cmp r5, #0 */
/* @0x1b358c bne 0x1b35a0 <_Z16ExecuteDrawEventP9tagYYRECTii+0x5c> */
/* @0x1b3590 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1b3594 ldr r5, [r5, #0x6c] */
/* @0x1b3598 cmp r5, #0 */
/* @0x1b359c beq 0x1b3688 <_Z16ExecuteDrawEventP9tagYYRECTii+0x144> */
/* @0x1b35a0 ldrb r3, [r5, #0x18] */
/* @0x1b35a4 cmp r3, #0 */
/* @0x1b35a8 beq 0x1b3594 <_Z16ExecuteDrawEventP9tagYYRECTii+0x50> */
/* @0x1b35ac ldr r0, [r5, #0x28] */
/* @0x1b35b0 bl 0x1b1128 <_Z14SetLayerShaderi> */
/* @0x1b35b4 ldr r0, [r5] */
/* @0x1b35b8 ldr r1, [r5, #0x20] */
/* @0x1b35bc mov r2, r7 */
/* @0x1b35c0 mov r3, r8 */
/* @0x1b35c4 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii> */
/* @0x1b35c8 ldr r4, [r5, #0x58] */
/* @0x1b35cc cmp r4, #0 */
/* @0x1b35d0 bne 0x1b35e4 <_Z16ExecuteDrawEventP9tagYYRECTii+0xa0> */
/* @0x1b35d4 b 0x1b3660 <_Z16ExecuteDrawEventP9tagYYRECTii+0x11c> */
/* @0x1b35d8 ldr r4, [r4, #0x14] */
/* @0x1b35dc cmp r4, #0 */
/* @0x1b35e0 beq 0x1b3660 <_Z16ExecuteDrawEventP9tagYYRECTii+0x11c> */
/* @0x1b35e4 ldr r0, [r4] */
/* @0x1b35e8 cmp r0, #2 */
/* @0x1b35ec bne 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94> */
/* @0x1b35f0 ldr r6, [r4, #0x20] */
/* @0x1b35f4 cmp r6, #0 */
/* @0x1b35f8 beq 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94> */
/* @0x1b35fc ldrb r0, [r6, #0x69] */
/* @0x1b3600 cmp r0, #0 */
/* @0x1b3604 bne 0x1b3660 <_Z16ExecuteDrawEventP9tagYYRECTii+0x11c> */
/* @0x1b3608 ldrb r3, [r6, #0x68] */
/* @0x1b360c cmp r3, #0 */
/* @0x1b3610 bne 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94> */
/* @0x1b3614 ldrb r3, [r6, #0x65] */
/* @0x1b3618 cmp r3, #0 */
/* @0x1b361c beq 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94> */
/* @0x1b3620 ldr r0, [r6, #0x80] */
/* @0x1b3624 cmp r0, #0 */
/* @0x1b3628 beq 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94> */
/* @0x1b362c mov r1, r7 */
/* @0x1b3630 mov r2, r8 */
/* @0x1b3634 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b3638 cmp r0, #0 */
/* @0x1b363c beq 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94> */
/* @0x1b3640 mov r0, r6 */
/* @0x1b3644 mov r2, r7 */
/* @0x1b3648 mov r1, r6 */
/* @0x1b364c mov r3, r8 */
/* @0x1b3650 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b3654 ldr r4, [r4, #0x14] */
/* @0x1b3658 cmp r4, #0 */
/* @0x1b365c bne 0x1b35e4 <_Z16ExecuteDrawEventP9tagYYRECTii+0xa0> */
/* @0x1b3660 ldr r0, [r5] */
/* @0x1b3664 mov r2, r7 */
/* @0x1b3668 ldr r1, [r5, #0x24] */
/* @0x1b366c mov r3, r8 */
/* @0x1b3670 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii> */
/* @0x1b3674 ldr r0, [r5, #0x28] */
/* @0x1b3678 bl 0x1b1170 <_Z16ResetLayerShaderi> */
/* @0x1b367c ldr r5, [r5, #0x6c] */
/* @0x1b3680 cmp r5, #0 */
/* @0x1b3684 bne 0x1b35a0 <_Z16ExecuteDrawEventP9tagYYRECTii+0x5c> */
/* @0x1b3688 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1b368c ldr r4, [r3, #0x84] */
/* @0x1b3690 cmp r4, #0 */
/* @0x1b3694 bne 0x1b36a8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x164> */
/* @0x1b3698 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1b369c ldr r4, [r4, #0x17c] */
/* @0x1b36a0 cmp r4, #0 */
/* @0x1b36a4 beq 0x1b370c <_Z16ExecuteDrawEventP9tagYYRECTii+0x1c8> */
/* @0x1b36a8 ldrb r3, [r4, #0x68] */
/* @0x1b36ac cmp r3, #0 */
/* @0x1b36b0 bne 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158> */
/* @0x1b36b4 ldrb r3, [r4, #0x69] */
/* @0x1b36b8 cmp r3, #0 */
/* @0x1b36bc bne 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158> */
/* @0x1b36c0 ldrb r3, [r4, #0x65] */
/* @0x1b36c4 cmp r3, #0 */
/* @0x1b36c8 beq 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158> */
/* @0x1b36cc ldr r0, [r4, #0x80] */
/* @0x1b36d0 mov r1, r7 */
/* @0x1b36d4 mov r2, r8 */
/* @0x1b36d8 cmp r0, #0 */
/* @0x1b36dc beq 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158> */
/* @0x1b36e0 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b36e4 cmp r0, #0 */
/* @0x1b36e8 beq 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158> */
/* @0x1b36ec mov r0, r4 */
/* @0x1b36f0 mov r1, r4 */
/* @0x1b36f4 mov r2, r7 */
/* @0x1b36f8 mov r3, r8 */
/* @0x1b36fc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b3700 ldr r4, [r4, #0x17c] */
/* @0x1b3704 cmp r4, #0 */
/* @0x1b3708 bne 0x1b36a8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x164> */
/* @0x1b370c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1b3710 .word 0x0023cbf4 */
/* @0x1b3714 eoreq r10, r3, r0, asr #7 */

/* ── FUNC 0x1b3718 · ExecutePreDrawEvent(tagYYRECT*, int, int, bool) · size=544 · insn=136 */
/* @0x1b3718 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b371c mov r7, r1 */
/* @0x1b3720 mov r8, r2 */
/* @0x1b3724 mov r10, r3 */
/* @0x1b3728 ldm r0, {r0, r1, r2, r3} */
/* @0x1b372c ldr r12, [pc, #0x1fc] */
/* @0x1b3730 ldr r12, [pc, r12] */
/* @0x1b3734 stm r12, {r0, r1, r2, r3} */
/* @0x1b3738 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b373c ldr r3, [pc, #0x1f0] */
/* @0x1b3740 ldr r3, [pc, r3] */
/* @0x1b3744 ldr r3, [r3] */
/* @0x1b3748 cmp r3, #0 */
/* @0x1b374c beq 0x1b3878 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x160> */
/* @0x1b3750 ldr r2, [r3, #0xdc] */
/* @0x1b3754 cmp r2, #0 */
/* @0x1b3758 ble 0x1b3878 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x160> */
/* @0x1b375c ldr r5, [r3, #0xd8] */
/* @0x1b3760 cmp r5, #0 */
/* @0x1b3764 beq 0x1b3920 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x208> */
/* @0x1b3768 mov r9, #0 */
/* @0x1b376c b 0x1b377c <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x64> */
/* @0x1b3770 ldr r5, [r5, #0x6c] */
/* @0x1b3774 cmp r5, #0 */
/* @0x1b3778 beq 0x1b3870 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x158> */
/* @0x1b377c ldrb r3, [r5, #0x18] */
/* @0x1b3780 cmp r3, #0 */
/* @0x1b3784 beq 0x1b3770 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x58> */
/* @0x1b3788 ldr r0, [r5, #0x28] */
/* @0x1b378c bl 0x1b1128 <_Z14SetLayerShaderi> */
/* @0x1b3790 ldr r0, [r5] */
/* @0x1b3794 ldr r1, [r5, #0x20] */
/* @0x1b3798 mov r2, r7 */
/* @0x1b379c mov r3, r8 */
/* @0x1b37a0 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii> */
/* @0x1b37a4 ldr r4, [r5, #0x58] */
/* @0x1b37a8 cmp r4, #0 */
/* @0x1b37ac bne 0x1b37c0 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0xa8> */
/* @0x1b37b0 b 0x1b3848 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x130> */
/* @0x1b37b4 ldr r4, [r4, #0x14] */
/* @0x1b37b8 cmp r4, #0 */
/* @0x1b37bc beq 0x1b3848 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x130> */
/* @0x1b37c0 ldr r12, [r4] */
/* @0x1b37c4 cmp r12, #2 */
/* @0x1b37c8 bne 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c> */
/* @0x1b37cc ldr r6, [r4, #0x20] */
/* @0x1b37d0 cmp r6, #0 */
/* @0x1b37d4 beq 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c> */
/* @0x1b37d8 ldrb r3, [r6, #0x69] */
/* @0x1b37dc cmp r3, #0 */
/* @0x1b37e0 bne 0x1b3848 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x130> */
/* @0x1b37e4 ldrb r3, [r6, #0x68] */
/* @0x1b37e8 cmp r3, #0 */
/* @0x1b37ec bne 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c> */
/* @0x1b37f0 ldrb r3, [r6, #0x65] */
/* @0x1b37f4 cmp r3, #0 */
/* @0x1b37f8 beq 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c> */
/* @0x1b37fc ldr r0, [r6, #0x80] */
/* @0x1b3800 cmp r0, #0 */
/* @0x1b3804 beq 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c> */
/* @0x1b3808 mov r1, r7 */
/* @0x1b380c mov r2, r8 */
/* @0x1b3810 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b3814 cmp r0, #0 */
/* @0x1b3818 beq 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c> */
/* @0x1b381c eor r3, r9, #1 */
/* @0x1b3820 tst r10, r3 */
/* @0x1b3824 bne 0x1b3900 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1e8> */
/* @0x1b3828 mov r0, r6 */
/* @0x1b382c mov r2, r7 */
/* @0x1b3830 mov r1, r6 */
/* @0x1b3834 mov r3, r8 */
/* @0x1b3838 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b383c ldr r4, [r4, #0x14] */
/* @0x1b3840 cmp r4, #0 */
/* @0x1b3844 bne 0x1b37c0 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0xa8> */
/* @0x1b3848 ldr r0, [r5] */
/* @0x1b384c mov r2, r7 */
/* @0x1b3850 ldr r1, [r5, #0x24] */
/* @0x1b3854 mov r3, r8 */
/* @0x1b3858 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii> */
/* @0x1b385c ldr r0, [r5, #0x28] */
/* @0x1b3860 bl 0x1b1170 <_Z16ResetLayerShaderi> */
/* @0x1b3864 ldr r5, [r5, #0x6c] */
/* @0x1b3868 cmp r5, #0 */
/* @0x1b386c bne 0x1b377c <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x64> */
/* @0x1b3870 mov r0, r9 */
/* @0x1b3874 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b3878 ldr r4, [r3, #0x84] */
/* @0x1b387c cmp r4, #0 */
/* @0x1b3880 beq 0x1b3928 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x210> */
/* @0x1b3884 mov r9, #0 */
/* @0x1b3888 ldrb r3, [r4, #0x68] */
/* @0x1b388c cmp r3, #0 */
/* @0x1b3890 bne 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4> */
/* @0x1b3894 ldrb r3, [r4, #0x69] */
/* @0x1b3898 cmp r3, #0 */
/* @0x1b389c bne 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4> */
/* @0x1b38a0 ldrb r3, [r4, #0x65] */
/* @0x1b38a4 cmp r3, #0 */
/* @0x1b38a8 beq 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4> */
/* @0x1b38ac ldr r0, [r4, #0x80] */
/* @0x1b38b0 cmp r0, #0 */
/* @0x1b38b4 beq 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4> */
/* @0x1b38b8 mov r1, r7 */
/* @0x1b38bc mov r2, r8 */
/* @0x1b38c0 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b38c4 cmp r0, #0 */
/* @0x1b38c8 beq 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4> */
/* @0x1b38cc eor r3, r9, #1 */
/* @0x1b38d0 tst r10, r3 */
/* @0x1b38d4 bne 0x1b3910 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1f8> */
/* @0x1b38d8 mov r0, r4 */
/* @0x1b38dc mov r1, r4 */
/* @0x1b38e0 mov r2, r7 */
/* @0x1b38e4 mov r3, r8 */
/* @0x1b38e8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b38ec ldr r4, [r4, #0x17c] */
/* @0x1b38f0 cmp r4, #0 */
/* @0x1b38f4 bne 0x1b3888 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x170> */
/* @0x1b38f8 mov r0, r9 */
/* @0x1b38fc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b3900 bl 0x17ae20 <_Z19GR_Window_Get_Colorv> */
/* @0x1b3904 mov r9, #1 */
/* @0x1b3908 bl 0x169f58 <_Z13GR_Draw_Clearj> */
/* @0x1b390c b 0x1b3828 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x110> */
/* @0x1b3910 bl 0x17ae20 <_Z19GR_Window_Get_Colorv> */
/* @0x1b3914 mov r9, #1 */
/* @0x1b3918 bl 0x169f58 <_Z13GR_Draw_Clearj> */
/* @0x1b391c b 0x1b38d8 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1c0> */
/* @0x1b3920 mov r9, r5 */
/* @0x1b3924 b 0x1b3870 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x158> */
/* @0x1b3928 mov r9, r4 */
/* @0x1b392c b 0x1b3870 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x158> */
/* @0x1b3930 eoreq r12, r3, r12, lsl r10 */
/* @0x1b3934 eoreq r10, r3, r8, ror #3 */

/* ── FUNC 0x1b3938 · DrawRoomLayers(tagYYRECT*) · size=472 · insn=118 */
/* @0x1b3938 ldr r3, [pc, #0x1c4] */
/* @0x1b393c push {r4, r5, r6, r7, lr} */
/* @0x1b3940 ldr r3, [pc, r3] */
/* @0x1b3944 sub sp, sp, #12 */
/* @0x1b3948 mov r6, r0 */
/* @0x1b394c ldr r3, [r3] */
/* @0x1b3950 cmp r3, #0 */
/* @0x1b3954 beq 0x1b3afc <_Z14DrawRoomLayersP9tagYYRECT+0x1c4> */
/* @0x1b3958 ldr r5, [r3, #0xd8] */
/* @0x1b395c cmp r5, #0 */
/* @0x1b3960 movne r7, #0 */
/* @0x1b3964 beq 0x1b3a40 <_Z14DrawRoomLayersP9tagYYRECT+0x108> */
/* @0x1b3968 ldrb r3, [r5, #0x18] */
/* @0x1b396c cmp r3, #0 */
/* @0x1b3970 beq 0x1b3a34 <_Z14DrawRoomLayersP9tagYYRECT+0xfc> */
/* @0x1b3974 ldr r3, [pc, #0x18c] */
/* @0x1b3978 ldr r3, [pc, r3] */
/* @0x1b397c ldrb r3, [r3] */
/* @0x1b3980 cmp r3, #0 */
/* @0x1b3984 beq 0x1b3ae8 <_Z14DrawRoomLayersP9tagYYRECT+0x1b0> */
/* @0x1b3988 ldr r3, [pc, #0x17c] */
/* @0x1b398c ldr r3, [pc, r3] */
/* @0x1b3990 ldr r0, [r3] */
/* @0x1b3994 vmov s15, r0 */
/* @0x1b3998 vcvt.f32.s32 s15, s15 */
/* @0x1b399c vmov r0, s15 */
/* @0x1b39a0 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b39a4 ldr r0, [r5, #0x28] */
/* @0x1b39a8 bl 0x1b1128 <_Z14SetLayerShaderi> */
/* @0x1b39ac ldr r0, [r5] */
/* @0x1b39b0 ldr r1, [r5, #0x20] */
/* @0x1b39b4 mov r2, #8 */
/* @0x1b39b8 mov r3, #0 */
/* @0x1b39bc bl 0x1b3418 <_Z18ExecuteLayerScriptiiii> */
/* @0x1b39c0 ldr r4, [r5, #0x58] */
/* @0x1b39c4 cmp r4, #0 */
/* @0x1b39c8 beq 0x1b3a18 <_Z14DrawRoomLayersP9tagYYRECT+0xe0> */
/* @0x1b39cc ldr r3, [r4] */
/* @0x1b39d0 sub r3, r3, #1 */
/* @0x1b39d4 cmp r3, #6 */
/* @0x1b39d8 addls pc, pc, r3, lsl #2 */
/* @0x1b39dc b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */
/* @0x1b39e0 b 0x1b3aa8 <_Z14DrawRoomLayersP9tagYYRECT+0x170> */
/* @0x1b39e4 b 0x1b3abc <_Z14DrawRoomLayersP9tagYYRECT+0x184> */
/* @0x1b39e8 b 0x1b3a94 <_Z14DrawRoomLayersP9tagYYRECT+0x15c> */
/* @0x1b39ec b 0x1b3a80 <_Z14DrawRoomLayersP9tagYYRECT+0x148> */
/* @0x1b39f0 b 0x1b3a60 <_Z14DrawRoomLayersP9tagYYRECT+0x128> */
/* @0x1b39f4 b 0x1b3a4c <_Z14DrawRoomLayersP9tagYYRECT+0x114> */
/* @0x1b39f8 b 0x1b39fc <_Z14DrawRoomLayersP9tagYYRECT+0xc4> */
/* @0x1b39fc mov r0, r6 */
/* @0x1b3a00 mov r1, r5 */
/* @0x1b3a04 mov r2, r4 */
/* @0x1b3a08 bl 0x1b283c <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement> */
/* @0x1b3a0c ldr r4, [r4, #0x14] */
/* @0x1b3a10 cmp r4, #0 */
/* @0x1b3a14 bne 0x1b39cc <_Z14DrawRoomLayersP9tagYYRECT+0x94> */
/* @0x1b3a18 ldr r0, [r5] */
/* @0x1b3a1c mov r2, #8 */
/* @0x1b3a20 ldr r1, [r5, #0x24] */
/* @0x1b3a24 mov r3, #0 */
/* @0x1b3a28 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii> */
/* @0x1b3a2c ldr r0, [r5, #0x28] */
/* @0x1b3a30 bl 0x1b1170 <_Z16ResetLayerShaderi> */
/* @0x1b3a34 ldr r5, [r5, #0x6c] */
/* @0x1b3a38 cmp r5, #0 */
/* @0x1b3a3c bne 0x1b3968 <_Z14DrawRoomLayersP9tagYYRECT+0x30> */
/* @0x1b3a40 add sp, sp, #12 */
/* @0x1b3a44 pop {r4, r5, r6, r7, lr} */
/* @0x1b3a48 b 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b3a4c mov r0, r6 */
/* @0x1b3a50 mov r1, r5 */
/* @0x1b3a54 mov r2, r4 */
/* @0x1b3a58 bl 0x1b2834 <_Z24DrawLayerParticleElementP9tagYYRECTP6CLayerP21CLayerParticleElement> */
/* @0x1b3a5c b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */
/* @0x1b3a60 str r7, [sp] */
/* @0x1b3a64 mov r0, r6 */
/* @0x1b3a68 str r7, [sp, #0x4] */
/* @0x1b3a6c mov r1, r5 */
/* @0x1b3a70 mov r2, r4 */
/* @0x1b3a74 mov r3, #0 */
/* @0x1b3a78 bl 0x1b2124 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff> */
/* @0x1b3a7c b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */
/* @0x1b3a80 mov r0, r6 */
/* @0x1b3a84 mov r1, r5 */
/* @0x1b3a88 mov r2, r4 */
/* @0x1b3a8c bl 0x1b193c <_Z22DrawLayerSpriteElementP9tagYYRECTP6CLayerP19CLayerSpriteElement> */
/* @0x1b3a90 b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */
/* @0x1b3a94 mov r0, r6 */
/* @0x1b3a98 mov r1, r5 */
/* @0x1b3a9c mov r2, r4 */
/* @0x1b3aa0 bl 0x1b1784 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement> */
/* @0x1b3aa4 b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */
/* @0x1b3aa8 mov r0, r6 */
/* @0x1b3aac mov r1, r5 */
/* @0x1b3ab0 mov r2, r4 */
/* @0x1b3ab4 bl 0x1b11a0 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement> */
/* @0x1b3ab8 b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */
/* @0x1b3abc ldr r3, [r4, #0x20] */
/* @0x1b3ac0 cmp r3, #0 */
/* @0x1b3ac4 beq 0x1b3ad4 <_Z14DrawRoomLayersP9tagYYRECT+0x19c> */
/* @0x1b3ac8 ldrb r3, [r3, #0x69] */
/* @0x1b3acc cmp r3, #0 */
/* @0x1b3ad0 bne 0x1b3a18 <_Z14DrawRoomLayersP9tagYYRECT+0xe0> */
/* @0x1b3ad4 mov r0, r6 */
/* @0x1b3ad8 mov r1, r5 */
/* @0x1b3adc mov r2, r4 */
/* @0x1b3ae0 bl 0x1b1600 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement> */
/* @0x1b3ae4 b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */
/* @0x1b3ae8 vldr s15, [r5, #4] */
/* @0x1b3aec vcvt.f32.s32 s15, s15 */
/* @0x1b3af0 vmov r0, s15 */
/* @0x1b3af4 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b3af8 b 0x1b39a4 <_Z14DrawRoomLayersP9tagYYRECT+0x6c> */
/* @0x1b3afc add sp, sp, #12 */
/* @0x1b3b00 pop {r4, r5, r6, r7, pc} */
/* @0x1b3b04 eoreq r9, r3, r8, ror #31 */
/* @0x1b3b08 .word 0x0023ceb8 */
/* @0x1b3b0c eoreq r12, r3, r8, lsr #29 */

/* ── FUNC 0x1b3b10 · DrawTheRoom(tagYYRECT*) · size=904 · insn=226 */
/* @0x1b3b10 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b3b14 mov r7, r0 */
/* @0x1b3b18 ldr r8, [pc, #0x35c] */
/* @0x1b3b1c sub sp, sp, #40 */
/* @0x1b3b20 ldr r3, [pc, #0x358] */
/* @0x1b3b24 add r8, pc, r8 */
/* @0x1b3b28 ldr r9, [r8, r3] */
/* @0x1b3b2c ldrb r3, [r9] */
/* @0x1b3b30 cmp r3, #0 */
/* @0x1b3b34 bne 0x1b3e34 <_Z11DrawTheRoomP9tagYYRECT+0x324> */
/* @0x1b3b38 ldr r12, [pc, #0x344] */
/* @0x1b3b3c ldm r7, {r0, r1, r2, r3} */
/* @0x1b3b40 ldr r12, [r8, r12] */
/* @0x1b3b44 stm r12, {r0, r1, r2, r3} */
/* @0x1b3b48 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1b3b4c ldr r3, [pc, #0x334] */
/* @0x1b3b50 ldr r3, [r8, r3] */
/* @0x1b3b54 ldrb r3, [r3] */
/* @0x1b3b58 cmp r3, #0 */
/* @0x1b3b5c beq 0x1b3bec <_Z11DrawTheRoomP9tagYYRECT+0xdc> */
/* @0x1b3b60 ldr r3, [pc, #0x324] */
/* @0x1b3b64 ldr r6, [r8, r3] */
/* @0x1b3b68 mov r3, #2 */
/* @0x1b3b6c ldr r2, [r6] */
/* @0x1b3b70 ldrb r0, [r2, #0x20] */
/* @0x1b3b74 cmp r0, #0 */
/* @0x1b3b78 beq 0x1b3b88 <_Z11DrawTheRoomP9tagYYRECT+0x78> */
/* @0x1b3b7c ldr r0, [r2, #0x1c] */
/* @0x1b3b80 orr r3, r3, #1 */
/* @0x1b3b84 orr r0, r0, #-16777216 */
/* @0x1b3b88 orr r3, r3, #6 */
/* @0x1b3b8c mov r1, #1065353216 */
/* @0x1b3b90 mov r2, #0 */
/* @0x1b3b94 bl 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags> */
/* @0x1b3b98 mov r0, r7 */
/* @0x1b3b9c mov r1, #8 */
/* @0x1b3ba0 mov r2, #72 */
/* @0x1b3ba4 bl 0x1b3544 <_Z16ExecuteDrawEventP9tagYYRECTii> */
/* @0x1b3ba8 ldr r3, [r6] */
/* @0x1b3bac cmp r3, #0 */
/* @0x1b3bb0 beq 0x1b3c30 <_Z11DrawTheRoomP9tagYYRECT+0x120> */
/* @0x1b3bb4 ldr r3, [r3, #0xdc] */
/* @0x1b3bb8 cmp r3, #0 */
/* @0x1b3bbc ble 0x1b3c30 <_Z11DrawTheRoomP9tagYYRECT+0x120> */
/* @0x1b3bc0 mov r0, r7 */
/* @0x1b3bc4 bl 0x1b3938 <_Z14DrawRoomLayersP9tagYYRECT> */
/* @0x1b3bc8 mov r0, r7 */
/* @0x1b3bcc mov r1, #8 */
/* @0x1b3bd0 mov r2, #73 */
/* @0x1b3bd4 bl 0x1b3544 <_Z16ExecuteDrawEventP9tagYYRECTii> */
/* @0x1b3bd8 ldrb r3, [r9] */
/* @0x1b3bdc cmp r3, #0 */
/* @0x1b3be0 bne 0x1b3c1c <_Z11DrawTheRoomP9tagYYRECT+0x10c> */
/* @0x1b3be4 add sp, sp, #40 */
/* @0x1b3be8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b3bec ldr r3, [pc, #0x29c] */
/* @0x1b3bf0 ldr r3, [r8, r3] */
/* @0x1b3bf4 ldrb r3, [r3] */
/* @0x1b3bf8 cmp r3, #0 */
/* @0x1b3bfc bne 0x1b3b60 <_Z11DrawTheRoomP9tagYYRECT+0x50> */
/* @0x1b3c00 ldr r2, [pc, #0x284] */
/* @0x1b3c04 ldr r6, [r8, r2] */
/* @0x1b3c08 ldr r2, [r6] */
/* @0x1b3c0c ldrb r1, [r2, #0x20] */
/* @0x1b3c10 cmp r1, #0 */
/* @0x1b3c14 bne 0x1b3b7c <_Z11DrawTheRoomP9tagYYRECT+0x6c> */
/* @0x1b3c18 b 0x1b3b98 <_Z11DrawTheRoomP9tagYYRECT+0x88> */
/* @0x1b3c1c ldr r3, [pc, #0x270] */
/* @0x1b3c20 ldr r0, [r8, r3] */
/* @0x1b3c24 add sp, sp, #40 */
/* @0x1b3c28 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b3c2c b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1b3c30 mov r0, #32768 */
/* @0x1b3c34 movt r0, #0x463b */
/* @0x1b3c38 mov r4, #0 */
/* @0x1b3c3c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b3c40 b 0x1b3c4c <_Z11DrawTheRoomP9tagYYRECT+0x13c> */
/* @0x1b3c44 cmp r4, #8 */
/* @0x1b3c48 beq 0x1b3d14 <_Z11DrawTheRoomP9tagYYRECT+0x204> */
/* @0x1b3c4c ldr r3, [r6] */
/* @0x1b3c50 add r3, r3, r4, lsl #2 */
/* @0x1b3c54 add r4, r4, #1 */
/* @0x1b3c58 ldr r5, [r3, #0x24] */
/* @0x1b3c5c ldrb r3, [r5] */
/* @0x1b3c60 cmp r3, #0 */
/* @0x1b3c64 beq 0x1b3c44 <_Z11DrawTheRoomP9tagYYRECT+0x134> */
/* @0x1b3c68 ldrb r3, [r5, #0x1] */
/* @0x1b3c6c cmp r3, #0 */
/* @0x1b3c70 bne 0x1b3c44 <_Z11DrawTheRoomP9tagYYRECT+0x134> */
/* @0x1b3c74 ldr r0, [r5, #0x4] */
/* @0x1b3c78 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1b3c7c cmp r0, #0 */
/* @0x1b3c80 beq 0x1b3c44 <_Z11DrawTheRoomP9tagYYRECT+0x134> */
/* @0x1b3c84 ldr r0, [r5, #0x4] */
/* @0x1b3c88 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1b3c8c ldr r3, [r7, #0x8] */
/* @0x1b3c90 ldr r10, [r7] */
/* @0x1b3c94 vldr s14, [r7] */
/* @0x1b3c98 ldr r12, [r7, #0x4] */
/* @0x1b3c9c vcvt.f32.s32 s13, s14 */
/* @0x1b3ca0 ldr lr, [r7, #0xc] */
/* @0x1b3ca4 rsb r10, r10, r3 */
/* @0x1b3ca8 ldr r1, [r5, #0x8] */
/* @0x1b3cac rsb lr, r12, lr */
/* @0x1b3cb0 vmov s15, r10 */
/* @0x1b3cb4 ldr r2, [r5, #0xc] */
/* @0x1b3cb8 vmov s14, lr */
/* @0x1b3cbc ldr lr, [r5, #0x20] */
/* @0x1b3cc0 ldr r3, [r5, #0x1c] */
/* @0x1b3cc4 vcvt.f32.s32 s15, s15 */
/* @0x1b3cc8 str lr, [sp] */
/* @0x1b3ccc ldrb lr, [r5, #0x10] */
/* @0x1b3cd0 str lr, [sp, #0x4] */
/* @0x1b3cd4 ldrb lr, [r5, #0x11] */
/* @0x1b3cd8 vstr s13, [sp, #12] */
/* @0x1b3cdc vmov s13, r12 */
/* @0x1b3ce0 vstr s15, [sp, #20] */
/* @0x1b3ce4 vcvt.f32.s32 s14, s14 */
/* @0x1b3ce8 str lr, [sp, #0x8] */
/* @0x1b3cec vcvt.f32.s32 s15, s13 */
/* @0x1b3cf0 vstr s14, [sp, #24] */
/* @0x1b3cf4 vstr s15, [sp, #16] */
/* @0x1b3cf8 ldr r12, [r5, #0x24] */
/* @0x1b3cfc str r12, [sp, #0x1c] */
/* @0x1b3d00 ldr r12, [r5, #0x28] */
/* @0x1b3d04 str r12, [sp, #0x20] */
/* @0x1b3d08 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf> */
/* @0x1b3d0c cmp r4, #8 */
/* @0x1b3d10 bne 0x1b3c4c <_Z11DrawTheRoomP9tagYYRECT+0x13c> */
/* @0x1b3d14 bl 0x1a570c <_Z27ParticleSystem_LargestDepthv> */
/* @0x1b3d18 ldr r3, [r6] */
/* @0x1b3d1c ldr r2, [r3, #0xb8] */
/* @0x1b3d20 cmp r2, #0 */
/* @0x1b3d24 vmov s15, r0 */
/* @0x1b3d28 bne 0x1b3d38 <_Z11DrawTheRoomP9tagYYRECT+0x228> */
/* @0x1b3d2c ldr r3, [r3, #0x88] */
/* @0x1b3d30 cmp r3, #0 */
/* @0x1b3d34 bne 0x1b3e4c <_Z11DrawTheRoomP9tagYYRECT+0x33c> */
/* @0x1b3d38 mov r0, r7 */
/* @0x1b3d3c bl 0x1b06a0 <_Z14DoSlowDrawRoomP9tagYYRECT> */
/* @0x1b3d40 mov r0, #32768 */
/* @0x1b3d44 movt r0, #0xc63b */
/* @0x1b3d48 mov r4, #0 */
/* @0x1b3d4c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b3d50 b 0x1b3d5c <_Z11DrawTheRoomP9tagYYRECT+0x24c> */
/* @0x1b3d54 cmp r4, #8 */
/* @0x1b3d58 beq 0x1b3e24 <_Z11DrawTheRoomP9tagYYRECT+0x314> */
/* @0x1b3d5c ldr r3, [r6] */
/* @0x1b3d60 add r3, r3, r4, lsl #2 */
/* @0x1b3d64 add r4, r4, #1 */
/* @0x1b3d68 ldr r5, [r3, #0x24] */
/* @0x1b3d6c ldrb r3, [r5] */
/* @0x1b3d70 cmp r3, #0 */
/* @0x1b3d74 beq 0x1b3d54 <_Z11DrawTheRoomP9tagYYRECT+0x244> */
/* @0x1b3d78 ldrb r3, [r5, #0x1] */
/* @0x1b3d7c cmp r3, #0 */
/* @0x1b3d80 beq 0x1b3d54 <_Z11DrawTheRoomP9tagYYRECT+0x244> */
/* @0x1b3d84 ldr r0, [r5, #0x4] */
/* @0x1b3d88 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1b3d8c cmp r0, #0 */
/* @0x1b3d90 beq 0x1b3d54 <_Z11DrawTheRoomP9tagYYRECT+0x244> */
/* @0x1b3d94 ldr r0, [r5, #0x4] */
/* @0x1b3d98 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1b3d9c ldr r3, [r7, #0x8] */
/* @0x1b3da0 ldr r10, [r7] */
/* @0x1b3da4 vldr s14, [r7] */
/* @0x1b3da8 ldr r12, [r7, #0x4] */
/* @0x1b3dac vcvt.f32.s32 s13, s14 */
/* @0x1b3db0 ldr lr, [r7, #0xc] */
/* @0x1b3db4 rsb r10, r10, r3 */
/* @0x1b3db8 ldr r1, [r5, #0x8] */
/* @0x1b3dbc rsb lr, r12, lr */
/* @0x1b3dc0 vmov s15, r10 */
/* @0x1b3dc4 ldr r2, [r5, #0xc] */
/* @0x1b3dc8 vmov s14, lr */
/* @0x1b3dcc ldr lr, [r5, #0x20] */
/* @0x1b3dd0 ldr r3, [r5, #0x1c] */
/* @0x1b3dd4 vcvt.f32.s32 s15, s15 */
/* @0x1b3dd8 str lr, [sp] */
/* @0x1b3ddc ldrb lr, [r5, #0x10] */
/* @0x1b3de0 str lr, [sp, #0x4] */
/* @0x1b3de4 ldrb lr, [r5, #0x11] */
/* @0x1b3de8 vstr s13, [sp, #12] */
/* @0x1b3dec vmov s13, r12 */
/* @0x1b3df0 vstr s15, [sp, #20] */
/* @0x1b3df4 vcvt.f32.s32 s14, s14 */
/* @0x1b3df8 str lr, [sp, #0x8] */
/* @0x1b3dfc vcvt.f32.s32 s15, s13 */
/* @0x1b3e00 vstr s14, [sp, #24] */
/* @0x1b3e04 vstr s15, [sp, #16] */
/* @0x1b3e08 ldr r12, [r5, #0x24] */
/* @0x1b3e0c str r12, [sp, #0x1c] */
/* @0x1b3e10 ldr r12, [r5, #0x28] */
/* @0x1b3e14 str r12, [sp, #0x20] */
/* @0x1b3e18 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf> */
/* @0x1b3e1c cmp r4, #8 */
/* @0x1b3e20 bne 0x1b3d5c <_Z11DrawTheRoomP9tagYYRECT+0x24c> */
/* @0x1b3e24 mov r0, #8192 */
/* @0x1b3e28 movt r0, #0xc64b */
/* @0x1b3e2c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b3e30 b 0x1b3bc8 <_Z11DrawTheRoomP9tagYYRECT+0xb8> */
/* @0x1b3e34 ldr r3, [pc, #0x58] */
/* @0x1b3e38 mov r1, #6 */
/* @0x1b3e3c mov r2, #13 */
/* @0x1b3e40 ldr r0, [r8, r3] */
/* @0x1b3e44 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1b3e48 b 0x1b3b38 <_Z11DrawTheRoomP9tagYYRECT+0x28> */
/* @0x1b3e4c vldr s14, [pc, #36] */
/* @0x1b3e50 vcmpe.f32 s15, s14 */
/* @0x1b3e54 vmrs APSR_nzcv, fpscr */
/* @0x1b3e58 ble 0x1b3e68 <_Z11DrawTheRoomP9tagYYRECT+0x358> */
/* @0x1b3e5c mov r0, r7 */
/* @0x1b3e60 bl 0x1b0b04 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT> */
/* @0x1b3e64 b 0x1b3d40 <_Z11DrawTheRoomP9tagYYRECT+0x230> */
/* @0x1b3e68 bhi 0x1b3d38 <_Z11DrawTheRoomP9tagYYRECT+0x228> */
/* @0x1b3e6c mov r0, r7 */
/* @0x1b3e70 bl 0x1b0f50 <_Z17DrawInstancesOnlyP9tagYYRECT> */
/* @0x1b3e74 b 0x1b3d40 <_Z11DrawTheRoomP9tagYYRECT+0x230> */
/* @0x1b3e78 vmulgt.f64 d22, d14, d24 */
/* @0x1b3e7c eoreq lr, r3, r12, lsr #2 */
/* @0x1b3e80 .word 0xffffbf18 */
/* @0x1b3e84 .word 0xffffe4fc */
/* @0x1b3e88 .word 0xffffc0b4 */
/* @0x1b3e8c .word 0xffffbcd8 */
/* @0x1b3e90 .word 0xffffbcd4 */
/* @0x1b3e94 .word 0xffffbf1c */

/* ── FUNC 0x1b3e98 · Draw_Room() · size=2960 · insn=740 */
/* @0x1b3e98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b3e9c vpush {d8} */
/* @0x1b3ea0 sub sp, sp, #148 */
/* @0x1b3ea4 ldr r4, [pc, #0xadc] */
/* @0x1b3ea8 ldr r3, [pc, #0xadc] */
/* @0x1b3eac add r4, pc, r4 */
/* @0x1b3eb0 ldr r3, [r4, r3] */
/* @0x1b3eb4 str r3, [sp, #0x38] */
/* @0x1b3eb8 ldrb r3, [r3] */
/* @0x1b3ebc cmp r3, #0 */
/* @0x1b3ec0 bne 0x1b4714 <_Z9Draw_Roomv+0x87c> */
/* @0x1b3ec4 ldr r3, [pc, #0xac4] */
/* @0x1b3ec8 ldr r5, [r4, r3] */
/* @0x1b3ecc ldrb r3, [r5] */
/* @0x1b3ed0 cmp r3, #0 */
/* @0x1b3ed4 beq 0x1b472c <_Z9Draw_Roomv+0x894> */
/* @0x1b3ed8 ldr r3, [pc, #0xab4] */
/* @0x1b3edc ldr r3, [r4, r3] */
/* @0x1b3ee0 str r3, [sp, #0x28] */
/* @0x1b3ee4 ldrb r3, [r3] */
/* @0x1b3ee8 cmp r3, #0 */
/* @0x1b3eec bne 0x1b3f20 <_Z9Draw_Roomv+0x88> */
/* @0x1b3ef0 ldr r1, [pc, #0xaa0] */
/* @0x1b3ef4 ldr r3, [pc, #0xaa0] */
/* @0x1b3ef8 ldr r2, [pc, #0xaa0] */
/* @0x1b3efc ldr r0, [r4, r1] */
/* @0x1b3f00 ldr r1, [r4, r3] */
/* @0x1b3f04 ldr r3, [pc, #0xa98] */
/* @0x1b3f08 ldr r0, [r0] */
/* @0x1b3f0c str r0, [r1] */
/* @0x1b3f10 ldr r2, [r4, r2] */
/* @0x1b3f14 ldr r3, [r4, r3] */
/* @0x1b3f18 ldr r2, [r2] */
/* @0x1b3f1c str r2, [r3] */
/* @0x1b3f20 ldr r3, [pc, #0xa80] */
/* @0x1b3f24 ldr r3, [r4, r3] */
/* @0x1b3f28 ldr r0, [r3] */
/* @0x1b3f2c str r3, [sp, #0x34] */
/* @0x1b3f30 cmp r0, #0 */
/* @0x1b3f34 blt 0x1b3f44 <_Z9Draw_Roomv+0xac> */
/* @0x1b3f38 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x1b3f3c cmp r0, #0 */
/* @0x1b3f40 bne 0x1b3fa4 <_Z9Draw_Roomv+0x10c> */
/* @0x1b3f44 ldr r12, [pc, #0xa60] */
/* @0x1b3f48 mov r0, #1 */
/* @0x1b3f4c ldr r3, [pc, #0xa50] */
/* @0x1b3f50 mvn r2, #0 */
/* @0x1b3f54 ldr r1, [pc, #0xa40] */
/* @0x1b3f58 ldr r7, [r4, r12] */
/* @0x1b3f5c strb r0, [r7] */
/* @0x1b3f60 ldr r8, [r4, r1] */
/* @0x1b3f64 ldr r6, [r4, r3] */
/* @0x1b3f68 ldr r0, [r8] */
/* @0x1b3f6c ldr r1, [r6] */
/* @0x1b3f70 bl 0x170f98 <_Z17GR_Surface_Createiii> */
/* @0x1b3f74 ldr r1, [r8] */
/* @0x1b3f78 ldr r12, [pc, #0xa30] */
/* @0x1b3f7c mov r3, #0 */
/* @0x1b3f80 ldr r8, [sp, #0x34] */
/* @0x1b3f84 strb r3, [r7] */
/* @0x1b3f88 ldr r2, [pc, #0xa24] */
/* @0x1b3f8c ldr r3, [r6] */
/* @0x1b3f90 str r0, [r8] */
/* @0x1b3f94 ldr r0, [r4, r12] */
/* @0x1b3f98 str r1, [r0] */
/* @0x1b3f9c ldr r2, [r4, r2] */
/* @0x1b3fa0 str r3, [r2] */
/* @0x1b3fa4 ldr r3, [pc, #0xa0c] */
/* @0x1b3fa8 ldr r3, [r4, r3] */
/* @0x1b3fac ldrb r2, [r3] */
/* @0x1b3fb0 cmp r2, #0 */
/* @0x1b3fb4 bne 0x1b4878 <_Z9Draw_Roomv+0x9e0> */
/* @0x1b3fb8 ldr r2, [pc, #0x9fc] */
/* @0x1b3fbc ldr r3, [pc, #0x9fc] */
/* @0x1b3fc0 ldr r2, [r4, r2] */
/* @0x1b3fc4 str r2, [sp, #0x2c] */
/* @0x1b3fc8 ldr r3, [r4, r3] */
/* @0x1b3fcc str r3, [sp, #0x30] */
/* @0x1b3fd0 ldrb r1, [r5] */
/* @0x1b3fd4 ldr r12, [sp, #0x28] */
/* @0x1b3fd8 ldr r2, [pc, #0x9e4] */
/* @0x1b3fdc ldr r3, [pc, #0x9e4] */
/* @0x1b3fe0 strb r1, [r12] */
/* @0x1b3fe4 ldr r7, [r4, r2] */
/* @0x1b3fe8 ldr r3, [r4, r3] */
/* @0x1b3fec ldr r12, [sp, #0x2c] */
/* @0x1b3ff0 str r3, [sp, #0x24] */
/* @0x1b3ff4 ldrb r3, [r7] */
/* @0x1b3ff8 ldr r8, [sp, #0x24] */
/* @0x1b3ffc cmp r3, #0 */
/* @0x1b4000 ldrb r5, [r8] */
/* @0x1b4004 movne r3, #0 */
/* @0x1b4008 strbne r3, [r8] */
/* @0x1b400c ldr r8, [sp, #0x30] */
/* @0x1b4010 ldr r3, [r12] */
/* @0x1b4014 mov r12, #0 */
/* @0x1b4018 mov r0, r12 */
/* @0x1b401c mov r1, r12 */
/* @0x1b4020 ldr lr, [r8] */
/* @0x1b4024 mov r2, r3 */
/* @0x1b4028 str r3, [sp, #0x48] */
/* @0x1b402c str r12, [sp, #0x44] */
/* @0x1b4030 mov r3, lr */
/* @0x1b4034 str r12, [sp, #0x40] */
/* @0x1b4038 str lr, [sp, #0x4c] */
/* @0x1b403c bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x1b4040 ldrb r3, [r7] */
/* @0x1b4044 cmp r3, #0 */
/* @0x1b4048 mov r3, #0 */
/* @0x1b404c mov r0, r3 */
/* @0x1b4050 str r3, [sp] */
/* @0x1b4054 beq 0x1b461c <_Z9Draw_Roomv+0x784> */
/* @0x1b4058 vldr s9, [sp, #72] */
/* @0x1b405c vldr s11, [sp, #76] */
/* @0x1b4060 vcvt.f32.s32 s9, s9 */
/* @0x1b4064 mov r1, r0 */
/* @0x1b4068 vcvt.f32.s32 s11, s11 */
/* @0x1b406c vmov r2, s9 */
/* @0x1b4070 vmov r3, s11 */
/* @0x1b4074 bl 0x1aff1c <_Z19UpdateDefaultCamerafffff> */
/* @0x1b4078 ldr r0, [pc, #0x94c] */
/* @0x1b407c mov r3, #1065353216 */
/* @0x1b4080 ldr r1, [pc, #0x948] */
/* @0x1b4084 add r6, sp, #64 */
/* @0x1b4088 ldr r2, [pc, #0x944] */
/* @0x1b408c ldr r10, [r4, r0] */
/* @0x1b4090 str r3, [r10] */
/* @0x1b4094 ldr r1, [r4, r1] */
/* @0x1b4098 str r3, [r1] */
/* @0x1b409c str r1, [sp, #0x1c] */
/* @0x1b40a0 mov r1, #8 */
/* @0x1b40a4 ldr r9, [r4, r2] */
/* @0x1b40a8 mov r2, #76 */
/* @0x1b40ac ldr r3, [r9] */
/* @0x1b40b0 ldrb r3, [r3, #0x46] */
/* @0x1b40b4 cmp r3, #0 */
/* @0x1b40b8 beq 0x1b40cc <_Z9Draw_Roomv+0x234> */
/* @0x1b40bc ldr r8, [sp, #0x28] */
/* @0x1b40c0 ldrb r3, [r8] */
/* @0x1b40c4 cmp r3, #0 */
/* @0x1b40c8 bne 0x1b46c0 <_Z9Draw_Roomv+0x828> */
/* @0x1b40cc mov r3, #0 */
/* @0x1b40d0 mov r0, r6 */
/* @0x1b40d4 str r3, [sp, #0x3c] */
/* @0x1b40d8 bl 0x1b3718 <_Z19ExecutePreDrawEventP9tagYYRECTiib> */
/* @0x1b40dc ldrb r3, [r7] */
/* @0x1b40e0 ldr r8, [sp, #0x28] */
/* @0x1b40e4 cmp r3, #0 */
/* @0x1b40e8 ldrne r12, [sp, #0x24] */
/* @0x1b40ec ldrb r3, [r8] */
/* @0x1b40f0 strbne r5, [r12] */
/* @0x1b40f4 cmp r3, #0 */
/* @0x1b40f8 bne 0x1b4794 <_Z9Draw_Roomv+0x8fc> */
/* @0x1b40fc bl 0x1b0164 <_Z11UpdateViewsv> */
/* @0x1b4100 ldr r0, [r9] */
/* @0x1b4104 cmp r0, #0 */
/* @0x1b4108 beq 0x1b4118 <_Z9Draw_Roomv+0x280> */
/* @0x1b410c ldr r3, [r0, #0xdc] */
/* @0x1b4110 cmp r3, #0 */
/* @0x1b4114 bne 0x1b4640 <_Z9Draw_Roomv+0x7a8> */
/* @0x1b4118 bl 0x1af3f4 <_ZN5CRoom9SortTilesEv> */
/* @0x1b411c ldr r3, [r9] */
/* @0x1b4120 ldr r1, [pc, #0x8b0] */
/* @0x1b4124 mov r2, #0 */
/* @0x1b4128 ldrb r5, [r3, #0x44] */
/* @0x1b412c ldr r8, [r4, r1] */
/* @0x1b4130 cmp r5, r2 */
/* @0x1b4134 str r2, [r8] */
/* @0x1b4138 beq 0x1b47b4 <_Z9Draw_Roomv+0x91c> */
/* @0x1b413c ldrb r2, [r3, #0x45] */
/* @0x1b4140 cmp r2, #0 */
/* @0x1b4144 bne 0x1b4868 <_Z9Draw_Roomv+0x9d0> */
/* @0x1b4148 ldr r2, [pc, #0x88c] */
/* @0x1b414c mov r5, #0 */
/* @0x1b4150 ldr r2, [r4, r2] */
/* @0x1b4154 str r2, [sp, #0x20] */
/* @0x1b4158 b 0x1b41e4 <_Z9Draw_Roomv+0x34c> */
/* @0x1b415c ldr r3, [pc, #0x87c] */
/* @0x1b4160 ldr r1, [r11, #0x40] */
/* @0x1b4164 ldr r11, [r4, r3] */
/* @0x1b4168 mov r0, r11 */
/* @0x1b416c bl 0x1707c8 <_ZN14CCameraManager15SetActiveCameraEi> */
/* @0x1b4170 mov r0, r11 */
/* @0x1b4174 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1b4178 subs r11, r0, #0 */
/* @0x1b417c beq 0x1b418c <_Z9Draw_Roomv+0x2f4> */
/* @0x1b4180 bl 0x170b20 <_ZN7CCamera5BeginEv> */
/* @0x1b4184 mov r0, r11 */
/* @0x1b4188 bl 0x16d3bc <_ZN7CCamera13ApplyMatricesEv> */
/* @0x1b418c ldr r3, [pc, #0x850] */
/* @0x1b4190 ldr r3, [r4, r3] */
/* @0x1b4194 ldm r3, {r0, r1, r2, r3} */
/* @0x1b4198 stm r6, {r0, r1, r2, r3} */
/* @0x1b419c mov r0, r6 */
/* @0x1b41a0 bl 0x1b3b10 <_Z11DrawTheRoomP9tagYYRECT> */
/* @0x1b41a4 ldr r3, [r8] */
/* @0x1b41a8 cmp r3, #0 */
/* @0x1b41ac beq 0x1b41bc <_Z9Draw_Roomv+0x324> */
/* @0x1b41b0 mov lr, #0 */
/* @0x1b41b4 str lr, [r8] */
/* @0x1b41b8 bl 0x171808 <_Z26YYGML_surface_reset_targetv> */
/* @0x1b41bc ldrb r3, [r7] */
/* @0x1b41c0 vstr s16, [r10] */
/* @0x1b41c4 ldr r12, [sp, #0x1c] */
/* @0x1b41c8 vstr s17, [r12] */
/* @0x1b41cc cmp r3, #0 */
/* @0x1b41d0 bne 0x1b42c4 <_Z9Draw_Roomv+0x42c> */
/* @0x1b41d4 add r5, r5, #1 */
/* @0x1b41d8 cmp r5, #8 */
/* @0x1b41dc beq 0x1b42f8 <_Z9Draw_Roomv+0x460> */
/* @0x1b41e0 ldr r3, [r9] */
/* @0x1b41e4 add r2, r5, #18 */
/* @0x1b41e8 ldr r12, [sp, #0x20] */
/* @0x1b41ec ldr r11, [r3, r2, lsl #2] */
/* @0x1b41f0 str r5, [r12] */
/* @0x1b41f4 ldrb r3, [r11] */
/* @0x1b41f8 cmp r3, #0 */
/* @0x1b41fc beq 0x1b41d4 <_Z9Draw_Roomv+0x33c> */
/* @0x1b4200 ldr r0, [r11, #0x3c] */
/* @0x1b4204 mov lr, #0 */
/* @0x1b4208 ldr r12, [sp, #0x1c] */
/* @0x1b420c vldr s16, [r10] */
/* @0x1b4210 cmn r0, #1 */
/* @0x1b4214 str lr, [r8] */
/* @0x1b4218 vldr s17, [r12] */
/* @0x1b421c beq 0x1b42b8 <_Z9Draw_Roomv+0x420> */
/* @0x1b4220 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x1b4224 cmp r0, #0 */
/* @0x1b4228 bne 0x1b45d8 <_Z9Draw_Roomv+0x740> */
/* @0x1b422c ldr r12, [sp, #0x1c] */
/* @0x1b4230 vldr s14, [r10] */
/* @0x1b4234 vldr s15, [r12] */
/* @0x1b4238 vldr s9, [r11, #20] */
/* @0x1b423c vldr s11, [r11, #24] */
/* @0x1b4240 vcvt.f32.s32 s12, s9 */
/* @0x1b4244 vldr s9, [r11, #28] */
/* @0x1b4248 vcvt.f32.s32 s13, s11 */
/* @0x1b424c vcvt.f32.s32 s10, s9 */
/* @0x1b4250 vldr s9, [r11, #32] */
/* @0x1b4254 vcvt.f32.s32 s11, s9 */
/* @0x1b4258 vmul.f32 s12, s12, s14 */
/* @0x1b425c vmul.f32 s13, s13, s15 */
/* @0x1b4260 vmul.f32 s14, s10, s14 */
/* @0x1b4264 vmul.f32 s15, s11, s15 */
/* @0x1b4268 vcvt.s32.f32 s12, s12 */
/* @0x1b426c vcvt.s32.f32 s13, s13 */
/* @0x1b4270 vmov r0, s12 */
/* @0x1b4274 vcvt.s32.f32 s14, s14 */
/* @0x1b4278 vmov r1, s13 */
/* @0x1b427c vcvt.s32.f32 s15, s15 */
/* @0x1b4280 vmov r2, s14 */
/* @0x1b4284 vmov r3, s15 */
/* @0x1b4288 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x1b428c ldrb r3, [r7] */
/* @0x1b4290 cmp r3, #0 */
/* @0x1b4294 bne 0x1b415c <_Z9Draw_Roomv+0x2c4> */
/* @0x1b4298 ldr r12, [r11, #0x24] */
/* @0x1b429c ldr r0, [r11, #0x4] */
/* @0x1b42a0 ldr r1, [r11, #0x8] */
/* @0x1b42a4 ldr r2, [r11, #0xc] */
/* @0x1b42a8 ldr r3, [r11, #0x10] */
/* @0x1b42ac str r12, [sp] */
/* @0x1b42b0 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x1b42b4 b 0x1b418c <_Z9Draw_Roomv+0x2f4> */
/* @0x1b42b8 vmov.f32 s15, s17 */
/* @0x1b42bc vmov.f32 s14, s16 */
/* @0x1b42c0 b 0x1b4238 <_Z9Draw_Roomv+0x3a0> */
/* @0x1b42c4 ldr r3, [pc, #0x714] */
/* @0x1b42c8 ldr r11, [r4, r3] */
/* @0x1b42cc mov r0, r11 */
/* @0x1b42d0 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1b42d4 cmp r0, #0 */
/* @0x1b42d8 beq 0x1b42e0 <_Z9Draw_Roomv+0x448> */
/* @0x1b42dc bl 0x170b28 <_ZN7CCamera3EndEv> */
/* @0x1b42e0 mov r0, r11 */
/* @0x1b42e4 mvn r1, #0 */
/* @0x1b42e8 add r5, r5, #1 */
/* @0x1b42ec bl 0x1707c8 <_ZN14CCameraManager15SetActiveCameraEi> */
/* @0x1b42f0 cmp r5, #8 */
/* @0x1b42f4 bne 0x1b41e0 <_Z9Draw_Roomv+0x348> */
/* @0x1b42f8 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b42fc ldr r8, [sp, #0x28] */
/* @0x1b4300 ldrb r3, [r8] */
/* @0x1b4304 cmp r3, #0 */
/* @0x1b4308 bne 0x1b4854 <_Z9Draw_Roomv+0x9bc> */
/* @0x1b430c ldr r12, [sp, #0x2c] */
/* @0x1b4310 ldr r8, [sp, #0x30] */
/* @0x1b4314 ldr r3, [r12] */
/* @0x1b4318 mov r12, #0 */
/* @0x1b431c ldr lr, [r8] */
/* @0x1b4320 mov r0, r12 */
/* @0x1b4324 ldr r8, [sp, #0x24] */
/* @0x1b4328 mov r1, r12 */
/* @0x1b432c mov r2, r3 */
/* @0x1b4330 str r3, [sp, #0x48] */
/* @0x1b4334 mov r3, lr */
/* @0x1b4338 str r12, [sp, #0x44] */
/* @0x1b433c str r12, [sp, #0x40] */
/* @0x1b4340 ldrb r5, [r8] */
/* @0x1b4344 str lr, [sp, #0x4c] */
/* @0x1b4348 strb r12, [r8] */
/* @0x1b434c bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x1b4350 vldr s9, [sp, #72] */
/* @0x1b4354 vldr s11, [sp, #76] */
/* @0x1b4358 vcvt.f32.s32 s9, s9 */
/* @0x1b435c mov r3, #0 */
/* @0x1b4360 mov r0, r3 */
/* @0x1b4364 str r3, [sp] */
/* @0x1b4368 mov r1, r0 */
/* @0x1b436c vcvt.f32.s32 s11, s11 */
/* @0x1b4370 vmov r2, s9 */
/* @0x1b4374 vmov r3, s11 */
/* @0x1b4378 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x1b437c ldr r8, [sp, #0x3c] */
/* @0x1b4380 ldr r12, [sp, #0x1c] */
/* @0x1b4384 mov r3, #1065353216 */
/* @0x1b4388 cmp r8, #0 */
/* @0x1b438c ldr r9, [r10] */
/* @0x1b4390 str r3, [r10] */
/* @0x1b4394 ldr r8, [r12] */
/* @0x1b4398 str r3, [r12] */
/* @0x1b439c bne 0x1b47a8 <_Z9Draw_Roomv+0x910> */
/* @0x1b43a0 mov r0, r6 */
/* @0x1b43a4 mov r1, #8 */
/* @0x1b43a8 mov r2, #77 */
/* @0x1b43ac bl 0x1b3544 <_Z16ExecuteDrawEventP9tagYYRECTii> */
/* @0x1b43b0 ldr r3, [pc, #0x630] */
/* @0x1b43b4 ldr r3, [r4, r3] */
/* @0x1b43b8 ldr r3, [r3] */
/* @0x1b43bc cmp r3, #0 */
/* @0x1b43c0 bne 0x1b46dc <_Z9Draw_Roomv+0x844> */
/* @0x1b43c4 ldrb r3, [r7] */
/* @0x1b43c8 ldr r12, [sp, #0x1c] */
/* @0x1b43cc cmp r3, #0 */
/* @0x1b43d0 str r9, [r10] */
/* @0x1b43d4 str r8, [r12] */
/* @0x1b43d8 bne 0x1b48e0 <_Z9Draw_Roomv+0xa48> */
/* @0x1b43dc ldr r3, [pc, #0x608] */
/* @0x1b43e0 ldr r3, [r4, r3] */
/* @0x1b43e4 ldrb r3, [r3] */
/* @0x1b43e8 cmp r3, #0 */
/* @0x1b43ec bne 0x1b4648 <_Z9Draw_Roomv+0x7b0> */
/* @0x1b43f0 ldr r3, [pc, #0x5f8] */
/* @0x1b43f4 mov r0, #0 */
/* @0x1b43f8 ldr r8, [sp, #0x24] */
/* @0x1b43fc strb r5, [r8] */
/* @0x1b4400 ldr r11, [r4, r3] */
/* @0x1b4404 ldrb r9, [r11] */
/* @0x1b4408 bl 0x163170 <_Z14GR_3D_Set_Modeb> */
/* @0x1b440c ldrb r3, [r7] */
/* @0x1b4410 cmp r3, #0 */
/* @0x1b4414 beq 0x1b485c <_Z9Draw_Roomv+0x9c4> */
/* @0x1b4418 ldr r3, [pc, #0x5d4] */
/* @0x1b441c mov r8, #1 */
/* @0x1b4420 mov r10, #0 */
/* @0x1b4424 ldr r7, [r4, r3] */
/* @0x1b4428 strb r8, [r7] */
/* @0x1b442c bl 0x1b3330 <_Z10SetGuiViewv> */
/* @0x1b4430 ldr r3, [pc, #0x5ac] */
/* @0x1b4434 mov r0, r6 */
/* @0x1b4438 mov r1, #8 */
/* @0x1b443c mov r2, #74 */
/* @0x1b4440 ldr r3, [r4, r3] */
/* @0x1b4444 ldr r12, [r3, #0x8] */
/* @0x1b4448 ldr lr, [r3] */
/* @0x1b444c str r12, [sp, #0x48] */
/* @0x1b4450 ldr r12, [r3, #0x4] */
/* @0x1b4454 ldr r3, [r3, #0xc] */
/* @0x1b4458 str lr, [sp, #0x40] */
/* @0x1b445c str r12, [sp, #0x44] */
/* @0x1b4460 str r3, [sp, #0x4c] */
/* @0x1b4464 bl 0x1b3544 <_Z16ExecuteDrawEventP9tagYYRECTii> */
/* @0x1b4468 mov r0, r6 */
/* @0x1b446c mov r1, #8 */
/* @0x1b4470 mov r2, #64 */
/* @0x1b4474 bl 0x1b3544 <_Z16ExecuteDrawEventP9tagYYRECTii> */
/* @0x1b4478 mov r0, r6 */
/* @0x1b447c mov r1, #8 */
/* @0x1b4480 mov r2, #75 */
/* @0x1b4484 bl 0x1b3544 <_Z16ExecuteDrawEventP9tagYYRECTii> */
/* @0x1b4488 ldr r3, [pc, #0x568] */
/* @0x1b448c strb r10, [r7] */
/* @0x1b4490 ldr r3, [r4, r3] */
/* @0x1b4494 ldr r0, [r3] */
/* @0x1b4498 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b449c subs r6, r0, #0 */
/* @0x1b44a0 beq 0x1b45a4 <_Z9Draw_Roomv+0x70c> */
/* @0x1b44a4 ldr r12, [sp, #0x30] */
/* @0x1b44a8 vmov.f32 s15, #5.000000e-01 */
/* @0x1b44ac mov r0, r10 */
/* @0x1b44b0 add r1, sp, #80 */
/* @0x1b44b4 mov r10, #0 */
/* @0x1b44b8 str r10, [sp, #0x7c] */
/* @0x1b44bc ldr r2, [r12] */
/* @0x1b44c0 ldr r12, [sp, #0x2c] */
/* @0x1b44c4 rsb r2, r2, #0 */
/* @0x1b44c8 str r10, [sp, #0x74] */
/* @0x1b44cc str r10, [sp, #0x70] */
/* @0x1b44d0 ldr r3, [r12] */
/* @0x1b44d4 vmov s14, r2 */
/* @0x1b44d8 mov r12, #0 */
/* @0x1b44dc str r10, [sp, #0x6c] */
/* @0x1b44e0 rsb r3, r3, #0 */
/* @0x1b44e4 movt r12, #0x467a */
/* @0x1b44e8 vcvt.f32.s32 s14, s14 */
/* @0x1b44ec str r12, [sp, #0x88] */
/* @0x1b44f0 vmov s9, r3 */
/* @0x1b44f4 str r10, [sp, #0x68] */
/* @0x1b44f8 str r10, [sp, #0x60] */
/* @0x1b44fc str r10, [sp, #0x5c] */
/* @0x1b4500 str r10, [sp, #0x58] */
/* @0x1b4504 str r10, [sp, #0x54] */
/* @0x1b4508 vcvt.f32.s32 s13, s9 */
/* @0x1b450c vmul.f32 s14, s14, s15 */
/* @0x1b4510 vmul.f32 s15, s13, s15 */
/* @0x1b4514 vstr s14, [sp, #132] */
/* @0x1b4518 vmov.f32 s16, #1.000000e+00 */
/* @0x1b451c vstr s15, [sp, #128] */
/* @0x1b4520 vstr s16, [sp, #140] */
/* @0x1b4524 vstr s16, [sp, #120] */
/* @0x1b4528 vstr s16, [sp, #100] */
/* @0x1b452c vstr s16, [sp, #80] */
/* @0x1b4530 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x1b4534 ldr r3, [pc, #0x4c0] */
/* @0x1b4538 mov r0, r6 */
/* @0x1b453c ldr r1, [pc, #0x4bc] */
/* @0x1b4540 ldr r2, [pc, #0x4bc] */
/* @0x1b4544 mvn r12, #-16777216 */
/* @0x1b4548 ldr r6, [r4, r3] */
/* @0x1b454c ldr r3, [pc, #0x4b4] */
/* @0x1b4550 ldrb r7, [r6] */
/* @0x1b4554 strb r8, [r6] */
/* @0x1b4558 ldr r1, [r4, r1] */
/* @0x1b455c ldr r2, [r4, r2] */
/* @0x1b4560 ldr r3, [r4, r3] */
/* @0x1b4564 str r10, [sp, #0x8] */
/* @0x1b4568 ldr r1, [r1] */
/* @0x1b456c vstr s16, [sp] */
/* @0x1b4570 ldr r2, [r2] */
/* @0x1b4574 vstr s16, [sp, #4] */
/* @0x1b4578 ldr r3, [r3] */
/* @0x1b457c vstr s16, [sp, #16] */
/* @0x1b4580 str r12, [sp, #0xc] */
/* @0x1b4584 vmov s11, r2 */
/* @0x1b4588 vmov s12, r3 */
/* @0x1b458c vcvt.f32.s32 s11, s11 */
/* @0x1b4590 vcvt.f32.s32 s12, s12 */
/* @0x1b4594 vmov r2, s11 */
/* @0x1b4598 vmov r3, s12 */
/* @0x1b459c bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x1b45a0 strb r7, [r6] */
/* @0x1b45a4 mov r0, r5 */
/* @0x1b45a8 bl 0x163170 <_Z14GR_3D_Set_Modeb> */
/* @0x1b45ac ldr r8, [sp, #0x38] */
/* @0x1b45b0 ldr r12, [sp, #0x20] */
/* @0x1b45b4 mov r3, #0 */
/* @0x1b45b8 strb r9, [r11] */
/* @0x1b45bc ldrb r2, [r8] */
/* @0x1b45c0 str r3, [r12] */
/* @0x1b45c4 cmp r2, r3 */
/* @0x1b45c8 bne 0x1b46fc <_Z9Draw_Roomv+0x864> */
/* @0x1b45cc add sp, sp, #148 */
/* @0x1b45d0 vpop {d8} */
/* @0x1b45d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b45d8 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b45dc ldr r1, [r11, #0x3c] */
/* @0x1b45e0 mov r0, #0 */
/* @0x1b45e4 bl 0x171574 <_Z28YYGML_surface_set_target_extii> */
/* @0x1b45e8 ldr r0, [r11, #0x3c] */
/* @0x1b45ec bl 0x17155c <_Z22GR_Surface_Get_Texturei> */
/* @0x1b45f0 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x1b45f4 str r0, [r8] */
/* @0x1b45f8 ldr r0, [r11, #0x3c] */
/* @0x1b45fc bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x1b4600 mov r3, r0 */
/* @0x1b4604 mov r0, #0 */
/* @0x1b4608 ldr r2, [r3, #0x8] */
/* @0x1b460c mov r1, r0 */
/* @0x1b4610 ldr r3, [r3, #0xc] */
/* @0x1b4614 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x1b4618 b 0x1b428c <_Z9Draw_Roomv+0x3f4> */
/* @0x1b461c vldr s12, [sp, #72] */
/* @0x1b4620 vldr s13, [sp, #76] */
/* @0x1b4624 vcvt.f32.s32 s12, s12 */
/* @0x1b4628 mov r1, r0 */
/* @0x1b462c vcvt.f32.s32 s13, s13 */
/* @0x1b4630 vmov r2, s12 */
/* @0x1b4634 vmov r3, s13 */
/* @0x1b4638 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x1b463c b 0x1b4078 <_Z9Draw_Roomv+0x1e0> */
/* @0x1b4640 mov r3, r0 */
/* @0x1b4644 b 0x1b4120 <_Z9Draw_Roomv+0x288> */
/* @0x1b4648 ldr r8, [sp, #0x28] */
/* @0x1b464c ldrb r3, [r8] */
/* @0x1b4650 cmp r3, #0 */
/* @0x1b4654 beq 0x1b43f0 <_Z9Draw_Roomv+0x558> */
/* @0x1b4658 ldr r3, [pc, #0x3ac] */
/* @0x1b465c ldr r3, [r4, r3] */
/* @0x1b4660 ldrb r3, [r3] */
/* @0x1b4664 cmp r3, #0 */
/* @0x1b4668 beq 0x1b490c <_Z9Draw_Roomv+0xa74> */
/* @0x1b466c ldr r3, [pc, #0x39c] */
/* @0x1b4670 mov r12, #1 */
/* @0x1b4674 ldr r8, [sp, #0x34] */
/* @0x1b4678 ldr r1, [sp, #0x44] */
/* @0x1b467c ldr r2, [sp, #0x4c] */
/* @0x1b4680 ldr r0, [r8] */
/* @0x1b4684 rsb r2, r1, r2 */
/* @0x1b4688 str r2, [sp] */
/* @0x1b468c ldr lr, [r4, r3] */
/* @0x1b4690 ldr r3, [pc, #0x37c] */
/* @0x1b4694 ldr r2, [sp, #0x40] */
/* @0x1b4698 ldrb lr, [lr] */
/* @0x1b469c str lr, [sp, #0x4] */
/* @0x1b46a0 ldr lr, [r4, r3] */
/* @0x1b46a4 str r12, [sp, #0xc] */
/* @0x1b46a8 ldr r3, [sp, #0x48] */
/* @0x1b46ac ldrb r12, [lr] */
/* @0x1b46b0 rsb r3, r2, r3 */
/* @0x1b46b4 str r12, [sp, #0x8] */
/* @0x1b46b8 bl 0x1b2bb8 <_Z28RenderSurface_AspectAdjustediiiiibbb> */
/* @0x1b46bc b 0x1b43f0 <_Z9Draw_Roomv+0x558> */
/* @0x1b46c0 mov r3, #1 */
/* @0x1b46c4 mov r0, r6 */
/* @0x1b46c8 bl 0x1b3718 <_Z19ExecutePreDrawEventP9tagYYRECTiib> */
/* @0x1b46cc eor r0, r0, #1 */
/* @0x1b46d0 uxtb r0, r0 */
/* @0x1b46d4 str r0, [sp, #0x3c] */
/* @0x1b46d8 b 0x1b40dc <_Z9Draw_Roomv+0x244> */
/* @0x1b46dc ldr r0, [pc, #0x334] */
/* @0x1b46e0 mov r1, #0 */
/* @0x1b46e4 add r0, pc, r0 */
/* @0x1b46e8 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b46ec ldr r8, [sp, #0x38] */
/* @0x1b46f0 ldrb r3, [r8] */
/* @0x1b46f4 cmp r3, #0 */
/* @0x1b46f8 beq 0x1b45cc <_Z9Draw_Roomv+0x734> */
/* @0x1b46fc ldr r3, [pc, #0x318] */
/* @0x1b4700 ldr r0, [r4, r3] */
/* @0x1b4704 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1b4708 add sp, sp, #148 */
/* @0x1b470c vpop {d8} */
/* @0x1b4710 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b4714 ldr r3, [pc, #0x300] */
/* @0x1b4718 mov r1, #6 */
/* @0x1b471c mov r2, #12 */
/* @0x1b4720 ldr r0, [r4, r3] */
/* @0x1b4724 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1b4728 b 0x1b3ec4 <_Z9Draw_Roomv+0x2c> */
/* @0x1b472c ldr r2, [pc, #0x288] */
/* @0x1b4730 ldr r3, [pc, #0x264] */
/* @0x1b4734 ldr r1, [pc, #0x284] */
/* @0x1b4738 ldr r2, [r4, r2] */
/* @0x1b473c str r2, [sp, #0x2c] */
/* @0x1b4740 ldr r8, [sp, #0x2c] */
/* @0x1b4744 ldr r0, [r4, r3] */
/* @0x1b4748 ldr r2, [pc, #0x254] */
/* @0x1b474c ldr r12, [r8] */
/* @0x1b4750 ldr r3, [pc, #0x250] */
/* @0x1b4754 str r12, [r0] */
/* @0x1b4758 ldr r1, [r4, r1] */
/* @0x1b475c str r1, [sp, #0x30] */
/* @0x1b4760 ldr r1, [r1] */
/* @0x1b4764 ldr r2, [r4, r2] */
/* @0x1b4768 str r1, [r2] */
/* @0x1b476c ldr r3, [r4, r3] */
/* @0x1b4770 ldr r0, [r3] */
/* @0x1b4774 str r3, [sp, #0x34] */
/* @0x1b4778 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x1b477c cmp r0, #0 */
/* @0x1b4780 bne 0x1b4958 <_Z9Draw_Roomv+0xac0> */
/* @0x1b4784 ldr r3, [pc, #0x208] */
/* @0x1b4788 ldr r3, [r4, r3] */
/* @0x1b478c str r3, [sp, #0x28] */
/* @0x1b4790 b 0x1b3fd0 <_Z9Draw_Roomv+0x138> */
/* @0x1b4794 ldr r12, [sp, #0x34] */
/* @0x1b4798 mov r0, #0 */
/* @0x1b479c ldr r1, [r12] */
/* @0x1b47a0 bl 0x171574 <_Z28YYGML_surface_set_target_extii> */
/* @0x1b47a4 b 0x1b40fc <_Z9Draw_Roomv+0x264> */
/* @0x1b47a8 bl 0x17ae20 <_Z19GR_Window_Get_Colorv> */
/* @0x1b47ac bl 0x169f58 <_Z13GR_Draw_Clearj> */
/* @0x1b47b0 b 0x1b43a0 <_Z9Draw_Roomv+0x508> */
/* @0x1b47b4 ldr r3, [pc, #0x220] */
/* @0x1b47b8 ldr r3, [r4, r3] */
/* @0x1b47bc str r3, [sp, #0x20] */
/* @0x1b47c0 str r5, [r3] */
/* @0x1b47c4 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b47c8 ldr r2, [pc, #0x1cc] */
/* @0x1b47cc mov r0, r5 */
/* @0x1b47d0 ldr r3, [pc, #0x1cc] */
/* @0x1b47d4 mov r1, r5 */
/* @0x1b47d8 ldr r2, [r4, r2] */
/* @0x1b47dc ldr r3, [r4, r3] */
/* @0x1b47e0 ldr r2, [r2] */
/* @0x1b47e4 ldr r3, [r3] */
/* @0x1b47e8 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x1b47ec ldrb r3, [r7] */
/* @0x1b47f0 mov r1, #0 */
/* @0x1b47f4 cmp r3, #0 */
/* @0x1b47f8 ldr r3, [r9] */
/* @0x1b47fc mov r0, r1 */
/* @0x1b4800 ldr r2, [r3, #0x10] */
/* @0x1b4804 ldr r3, [r3, #0x14] */
/* @0x1b4808 str r1, [sp] */
/* @0x1b480c bne 0x1b48ec <_Z9Draw_Roomv+0xa54> */
/* @0x1b4810 vmov s12, r2 */
/* @0x1b4814 vmov s13, r3 */
/* @0x1b4818 vcvt.f32.s32 s12, s12 */
/* @0x1b481c vcvt.f32.s32 s13, s13 */
/* @0x1b4820 vmov r2, s12 */
/* @0x1b4824 vmov r3, s13 */
/* @0x1b4828 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x1b482c ldr r3, [pc, #0x1b0] */
/* @0x1b4830 ldr r3, [r4, r3] */
/* @0x1b4834 ldm r3, {r0, r1, r2, r3} */
/* @0x1b4838 stm r6, {r0, r1, r2, r3} */
/* @0x1b483c mov r0, r6 */
/* @0x1b4840 bl 0x1b3b10 <_Z11DrawTheRoomP9tagYYRECT> */
/* @0x1b4844 ldr r8, [sp, #0x28] */
/* @0x1b4848 ldrb r3, [r8] */
/* @0x1b484c cmp r3, #0 */
/* @0x1b4850 beq 0x1b430c <_Z9Draw_Roomv+0x474> */
/* @0x1b4854 bl 0x171808 <_Z26YYGML_surface_reset_targetv> */
/* @0x1b4858 b 0x1b430c <_Z9Draw_Roomv+0x474> */
/* @0x1b485c mov r0, #0 */
/* @0x1b4860 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b4864 b 0x1b4418 <_Z9Draw_Roomv+0x580> */
/* @0x1b4868 bl 0x17ae20 <_Z19GR_Window_Get_Colorv> */
/* @0x1b486c bl 0x169f58 <_Z13GR_Draw_Clearj> */
/* @0x1b4870 ldr r3, [r9] */
/* @0x1b4874 b 0x1b4148 <_Z9Draw_Roomv+0x2b0> */
/* @0x1b4878 ldr r1, [pc, #0x1a0] */
/* @0x1b487c mov r0, #0 */
/* @0x1b4880 ldr r2, [pc, #0x19c] */
/* @0x1b4884 strb r0, [r3] */
/* @0x1b4888 ldr r8, [sp, #0x34] */
/* @0x1b488c ldr r7, [r4, r1] */
/* @0x1b4890 ldr r6, [r4, r2] */
/* @0x1b4894 ldr r0, [r8] */
/* @0x1b4898 ldr r1, [r7] */
/* @0x1b489c ldr r2, [r6] */
/* @0x1b48a0 bl 0x171b68 <_Z17GR_Surface_Resizeiii> */
/* @0x1b48a4 ldr r3, [pc, #0xf0] */
/* @0x1b48a8 ldr r12, [r7] */
/* @0x1b48ac ldr r1, [pc, #0xf0] */
/* @0x1b48b0 ldr r3, [r4, r3] */
/* @0x1b48b4 ldr r0, [r6] */
/* @0x1b48b8 ldr r2, [pc, #0xfc] */
/* @0x1b48bc str r12, [r3] */
/* @0x1b48c0 ldr r1, [r4, r1] */
/* @0x1b48c4 ldr r3, [pc, #0xf4] */
/* @0x1b48c8 str r0, [r1] */
/* @0x1b48cc ldr r2, [r4, r2] */
/* @0x1b48d0 str r2, [sp, #0x2c] */
/* @0x1b48d4 ldr r3, [r4, r3] */
/* @0x1b48d8 str r3, [sp, #0x30] */
/* @0x1b48dc b 0x1b3fd0 <_Z9Draw_Roomv+0x138> */
/* @0x1b48e0 mov r0, #0 */
/* @0x1b48e4 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b48e8 b 0x1b43dc <_Z9Draw_Roomv+0x544> */
/* @0x1b48ec vmov s9, r2 */
/* @0x1b48f0 vmov s11, r3 */
/* @0x1b48f4 vcvt.f32.s32 s9, s9 */
/* @0x1b48f8 vcvt.f32.s32 s11, s11 */
/* @0x1b48fc vmov r2, s9 */
/* @0x1b4900 vmov r3, s11 */
/* @0x1b4904 bl 0x1aff1c <_Z19UpdateDefaultCamerafffff> */
/* @0x1b4908 b 0x1b482c <_Z9Draw_Roomv+0x994> */
/* @0x1b490c ldr r8, [sp, #0x34] */
/* @0x1b4910 mov r1, #0 */
/* @0x1b4914 ldr r12, [sp, #0x30] */
/* @0x1b4918 vldr s15, [r12] */
/* @0x1b491c vcvt.f32.s32 s15, s15 */
/* @0x1b4920 mov r12, #1065353216 */
/* @0x1b4924 ldr r0, [r8] */
/* @0x1b4928 mvn r2, #-16777216 */
/* @0x1b492c ldr r8, [sp, #0x2c] */
/* @0x1b4930 ldr r3, [r8] */
/* @0x1b4934 str r2, [sp, #0x4] */
/* @0x1b4938 mov r2, r1 */
/* @0x1b493c str r12, [sp, #0x8] */
/* @0x1b4940 vstr s15, [sp] */
/* @0x1b4944 vmov s9, r3 */
/* @0x1b4948 vcvt.f32.s32 s9, s9 */
/* @0x1b494c vmov r3, s9 */
/* @0x1b4950 bl 0x171e2c <_Z24GR_Surface_DrawStretchediffffjf> */
/* @0x1b4954 b 0x1b43f0 <_Z9Draw_Roomv+0x558> */
/* @0x1b4958 ldr r12, [sp, #0x34] */
/* @0x1b495c mov r1, #1 */
/* @0x1b4960 ldr r0, [r12] */
/* @0x1b4964 bl 0x171ba0 <_Z15GR_Surface_Freeib> */
/* @0x1b4968 ldr r2, [pc, #0x24] */
/* @0x1b496c ldr r8, [sp, #0x34] */
/* @0x1b4970 movw r3, #0xdead */
/* @0x1b4974 movt r3, #0xfeee */
/* @0x1b4978 str r3, [r8] */
/* @0x1b497c ldr r3, [r4, r2] */
/* @0x1b4980 str r3, [sp, #0x28] */
/* @0x1b4984 b 0x1b3fd0 <_Z9Draw_Roomv+0x138> */
/* @0x1b4988 eoreq sp, r3, r4, lsr #27 */
/* @0x1b498c .word 0xffffbf18 */
/* @0x1b4990 .word 0xffffdef8 */
/* @0x1b4994 .word 0xffffe6a4 */
/* @0x1b4998 .word 0xffffdf3c */
/* @0x1b499c .word 0xffffdf38 */
/* @0x1b49a0 .word 0xffffdf44 */
/* @0x1b49a4 .word 0xffffdf40 */
/* @0x1b49a8 .word 0xffffc988 */
/* @0x1b49ac .word 0xffffebe8 */
/* @0x1b49b0 .word 0xffffe688 */
/* @0x1b49b4 .word 0xffffe68c */
/* @0x1b49b8 .word 0xffffc98c */
/* @0x1b49bc .word 0xffffe24c */
/* @0x1b49c0 .word 0xffffe250 */
/* @0x1b49c4 .word 0xffffbcd4 */
/* @0x1b49c8 .word 0xffffc0b4 */
/* @0x1b49cc .word 0xffffe6bc */
/* @0x1b49d0 .word 0xffffe6c4 */
/* @0x1b49d4 .word 0xffffbcd8 */
/* @0x1b49d8 .word 0xffffebec */
/* @0x1b49dc .word 0xffffc980 */
/* @0x1b49e0 .word 0xffffc024 */
/* @0x1b49e4 .word 0xffffe4fc */
/* @0x1b49e8 .word 0xffffe614 */
/* @0x1b49ec .word 0xffffdf34 */
/* @0x1b49f0 .word 0xffffe4b0 */
/* @0x1b49f4 .word 0xffffdf30 */
/* @0x1b49f8 .word 0xffffd798 */
/* @0x1b49fc .word 0xffffe490 */
/* @0x1b4a00 .word 0xffffebf0 */
/* @0x1b4a04 .word 0xffffdf4c */
/* @0x1b4a08 .word 0xffffdf48 */
/* @0x1b4a0c .word 0xffffebf4 */
/* @0x1b4a10 .word 0xffffe6a0 */
/* @0x1b4a14 .word 0xffffe4d8 */
/* @0x1b4a18 andseq r8, r9, r0, asr #23 */
/* @0x1b4a1c .word 0xffffbf1c */
/* @0x1b4a20 .word 0xffffc990 */
/* @0x1b4a24 .word 0xffffc994 */

/* ── FUNC 0x1b4a28 · cARRAY_STRUCTURE<int>::~cARRAY_STRUCTURE() · size=60 · insn=15 */
/* @0x1b4a28 push {r3, r4, r5, lr} */
/* @0x1b4a2c mov r4, r0 */
/* @0x1b4a30 ldr r5, [r0, #0x4] */
/* @0x1b4a34 subs r0, r5, #0 */
/* @0x1b4a38 beq 0x1b4a58 <_ZN16cARRAY_STRUCTUREIiED2Ev+0x30> */
/* @0x1b4a3c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4a40 mov r3, #0 */
/* @0x1b4a44 str r3, [r4, #0x4] */
/* @0x1b4a48 mov r3, #0 */
/* @0x1b4a4c mov r0, r4 */
/* @0x1b4a50 str r3, [r4] */
/* @0x1b4a54 pop {r3, r4, r5, pc} */
/* @0x1b4a58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4a5c str r5, [r4, #0x4] */
/* @0x1b4a60 b 0x1b4a48 <_ZN16cARRAY_STRUCTUREIiED2Ev+0x20> */

/* ── FUNC 0x1b4a28 · cARRAY_STRUCTURE<int>::~cARRAY_STRUCTURE() · alias of the symbol above · insn=0 */
