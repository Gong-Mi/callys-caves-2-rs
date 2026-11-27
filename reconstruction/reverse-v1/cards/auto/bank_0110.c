/* libyoyo.so 覆盖卡组 0110
 * 函数 0x16f108..0x170468，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x16f108 · CCameraManager::CreateCameraFromView(YYRoomView*) · size=300 · insn=75 */
/* @0x16f108 push {r3, r4, r5, lr} */
/* @0x16f10c vpush {d8, d9} */
/* @0x16f110 subs r5, r1, #0 */
/* @0x16f114 beq 0x16f22c <_ZN14CCameraManager20CreateCameraFromViewEP10YYRoomView+0x124> */
/* @0x16f118 bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv> */
/* @0x16f11c vldr s15, [r5, #4] */
/* @0x16f120 vcvt.f32.s32 s15, s15 */
/* @0x16f124 vmov r1, s15 */
/* @0x16f128 vmov.f32 s17, #5.000000e-01 */
/* @0x16f12c mov r4, r0 */
/* @0x16f130 bl 0x16d29c <_ZN7CCamera8SetViewXEf> */
/* @0x16f134 vldr s15, [r5, #8] */
/* @0x16f138 vcvt.f32.s32 s15, s15 */
/* @0x16f13c mov r0, r4 */
/* @0x16f140 vmov r1, s15 */
/* @0x16f144 bl 0x16d2ac <_ZN7CCamera8SetViewYEf> */
/* @0x16f148 vldr s15, [r5, #12] */
/* @0x16f14c vcvt.f32.s32 s15, s15 */
/* @0x16f150 mov r0, r4 */
/* @0x16f154 vmov r1, s15 */
/* @0x16f158 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf> */
/* @0x16f15c vldr s15, [r5, #16] */
/* @0x16f160 vcvt.f32.s32 s15, s15 */
/* @0x16f164 mov r0, r4 */
/* @0x16f168 vmov r1, s15 */
/* @0x16f16c bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf> */
/* @0x16f170 vldr s15, [r5, #44] */
/* @0x16f174 vcvt.f32.s32 s15, s15 */
/* @0x16f178 mov r0, r4 */
/* @0x16f17c vmov r1, s15 */
/* @0x16f180 bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf> */
/* @0x16f184 vldr s15, [r5, #48] */
/* @0x16f188 vcvt.f32.s32 s15, s15 */
/* @0x16f18c mov r0, r4 */
/* @0x16f190 vmov r1, s15 */
/* @0x16f194 bl 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf> */
/* @0x16f198 vldr s15, [r5, #36] */
/* @0x16f19c vcvt.f32.s32 s15, s15 */
/* @0x16f1a0 mov r0, r4 */
/* @0x16f1a4 vmov r1, s15 */
/* @0x16f1a8 bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf> */
/* @0x16f1ac vldr s15, [r5, #40] */
/* @0x16f1b0 vcvt.f32.s32 s15, s15 */
/* @0x16f1b4 mov r0, r4 */
/* @0x16f1b8 vmov r1, s15 */
/* @0x16f1bc bl 0x16d30c <_ZN7CCamera14SetViewBorderYEf> */
/* @0x16f1c0 mov r0, r4 */
/* @0x16f1c4 mov r1, #0 */
/* @0x16f1c8 bl 0x16d31c <_ZN7CCamera12SetViewAngleEf> */
/* @0x16f1cc ldr r1, [r5, #0x34] */
/* @0x16f1d0 mov r0, r4 */
/* @0x16f1d4 bl 0x16d32c <_ZN7CCamera17SetTargetInstanceEi> */
/* @0x16f1d8 mov r0, r4 */
/* @0x16f1dc bl 0x16d2a4 <_ZN7CCamera8GetViewXEv> */
/* @0x16f1e0 vmov s16, r0 */
/* @0x16f1e4 mov r0, r4 */
/* @0x16f1e8 bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv> */
/* @0x16f1ec vmov s15, r0 */
/* @0x16f1f0 mov r0, r4 */
/* @0x16f1f4 vmla.f32 s16, s15, s17 */
/* @0x16f1f8 bl 0x16d2b4 <_ZN7CCamera8GetViewYEv> */
/* @0x16f1fc vmov s18, r0 */
/* @0x16f200 mov r0, r4 */
/* @0x16f204 bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv> */
/* @0x16f208 vmov r1, s16 */
/* @0x16f20c vmov s15, r0 */
/* @0x16f210 mov r0, r4 */
/* @0x16f214 vmla.f32 s18, s15, s17 */
/* @0x16f218 vmov r2, s18 */
/* @0x16f21c bl 0x16db44 <_ZN7CCamera11Build2DViewEff> */
/* @0x16f220 mov r0, r4 */
/* @0x16f224 vpop {d8, d9} */
/* @0x16f228 pop {r3, r4, r5, pc} */
/* @0x16f22c mov r0, r5 */
/* @0x16f230 b 0x16f224 <_ZN14CCameraManager20CreateCameraFromViewEP10YYRoomView+0x11c> */

/* ── FUNC 0x16f234 · CCameraManager::FindCameraInList(int) · size=152 · insn=38 */
/* @0x16f234 ldr r3, [r0, #0x18] */
/* @0x16f238 ldr r2, [r0, #0x14] */
/* @0x16f23c push {r4, r5, r6, lr} */
/* @0x16f240 cmp r3, r2 */
/* @0x16f244 mov r5, r0 */
/* @0x16f248 mov r6, r1 */
/* @0x16f24c bge 0x16f270 <_ZN14CCameraManager16FindCameraInListEi+0x3c> */
/* @0x16f250 ldr r1, [r0, #0xc] */
/* @0x16f254 ldr r0, [r1, r3, lsl #2] */
/* @0x16f258 cmp r0, #0 */
/* @0x16f25c beq 0x16f270 <_ZN14CCameraManager16FindCameraInListEi+0x3c> */
/* @0x16f260 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16f264 cmp r0, r6 */
/* @0x16f268 beq 0x16f2c4 <_ZN14CCameraManager16FindCameraInListEi+0x90> */
/* @0x16f26c ldr r2, [r5, #0x14] */
/* @0x16f270 cmp r2, #0 */
/* @0x16f274 movgt r4, #0 */
/* @0x16f278 ble 0x16f2b0 <_ZN14CCameraManager16FindCameraInListEi+0x7c> */
/* @0x16f27c ldr r3, [r5, #0xc] */
/* @0x16f280 ldr r0, [r3, r4, lsl #2] */
/* @0x16f284 cmp r0, #0 */
/* @0x16f288 beq 0x16f2a4 <_ZN14CCameraManager16FindCameraInListEi+0x70> */
/* @0x16f28c bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16f290 cmp r0, r6 */
/* @0x16f294 beq 0x16f2b8 <_ZN14CCameraManager16FindCameraInListEi+0x84> */
/* @0x16f298 cmp r6, r0 */
/* @0x16f29c blt 0x16f2b0 <_ZN14CCameraManager16FindCameraInListEi+0x7c> */
/* @0x16f2a0 ldr r2, [r5, #0x14] */
/* @0x16f2a4 add r4, r4, #1 */
/* @0x16f2a8 cmp r2, r4 */
/* @0x16f2ac bgt 0x16f27c <_ZN14CCameraManager16FindCameraInListEi+0x48> */
/* @0x16f2b0 mvn r0, #0 */
/* @0x16f2b4 pop {r4, r5, r6, pc} */
/* @0x16f2b8 str r4, [r5, #0x18] */
/* @0x16f2bc mov r0, r4 */
/* @0x16f2c0 pop {r4, r5, r6, pc} */
/* @0x16f2c4 ldr r0, [r5, #0x18] */
/* @0x16f2c8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x16f2cc · CCameraManager::DestroyCamera(int) · size=128 · insn=32 */
/* @0x16f2cc push {r3, r4, r5, r6, r7, lr} */
/* @0x16f2d0 mov r5, r0 */
/* @0x16f2d4 bl 0x16f234 <_ZN14CCameraManager16FindCameraInListEi> */
/* @0x16f2d8 cmn r0, #1 */
/* @0x16f2dc mov r4, r0 */
/* @0x16f2e0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x16f2e4 ldr r1, [r5, #0xc] */
/* @0x16f2e8 lsl r7, r0, #2 */
/* @0x16f2ec ldr r2, [r5, #0x4] */
/* @0x16f2f0 ldr r6, [r1, r0, lsl #2] */
/* @0x16f2f4 cmp r2, r6 */
/* @0x16f2f8 mov r0, r6 */
/* @0x16f2fc moveq r3, #0 */
/* @0x16f300 streq r3, [r5, #0x4] */
/* @0x16f304 bl 0x16d120 <_ZN7CCameraD2Ev> */
/* @0x16f308 mov r0, r6 */
/* @0x16f30c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x16f310 ldr r0, [r5, #0x14] */
/* @0x16f314 sub r0, r0, #1 */
/* @0x16f318 str r0, [r5, #0x14] */
/* @0x16f31c cmp r4, r0 */
/* @0x16f320 popge {r3, r4, r5, r6, r7, pc} */
/* @0x16f324 mov r3, r7 */
/* @0x16f328 ldr r1, [r5, #0xc] */
/* @0x16f32c add r2, r3, #4 */
/* @0x16f330 add r4, r4, #1 */
/* @0x16f334 cmp r4, r0 */
/* @0x16f338 ldr r12, [r1, r2] */
/* @0x16f33c str r12, [r1, r3] */
/* @0x16f340 mov r3, r2 */
/* @0x16f344 bne 0x16f328 <_ZN14CCameraManager13DestroyCameraEi+0x5c> */
/* @0x16f348 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x16f34c · CCameraManager::DeSerialize(IBuffer*) · size=272 · insn=68 */
/* @0x16f34c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x16f350 mov r6, r0 */
/* @0x16f354 ldr r7, [r0, #0x14] */
/* @0x16f358 mov r5, r1 */
/* @0x16f35c cmp r7, #0 */
/* @0x16f360 movgt r4, #0 */
/* @0x16f364 ble 0x16f38c <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x40> */
/* @0x16f368 ldr r3, [r6, #0xc] */
/* @0x16f36c add r4, r4, #1 */
/* @0x16f370 ldr r0, [r3] */
/* @0x16f374 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16f378 mov r1, r0 */
/* @0x16f37c mov r0, r6 */
/* @0x16f380 bl 0x16f2cc <_ZN14CCameraManager13DestroyCameraEi> */
/* @0x16f384 cmp r4, r7 */
/* @0x16f388 bne 0x16f368 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x1c> */
/* @0x16f38c ldr r3, [r5] */
/* @0x16f390 add r7, r5, #44 */
/* @0x16f394 mov r1, #6 */
/* @0x16f398 mov r0, r5 */
/* @0x16f39c mov r2, r7 */
/* @0x16f3a0 ldr r3, [r3, #0xc] */
/* @0x16f3a4 blx r3 */
/* @0x16f3a8 mov r0, r7 */
/* @0x16f3ac mov r1, #0 */
/* @0x16f3b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f3b4 subs r8, r0, #0 */
/* @0x16f3b8 ble 0x16f450 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x104> */
/* @0x16f3bc ldr r9, [pc, #0x94] */
/* @0x16f3c0 mov r4, #0 */
/* @0x16f3c4 add r9, pc, r9 */
/* @0x16f3c8 b 0x16f3d4 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x88> */
/* @0x16f3cc cmp r4, r8 */
/* @0x16f3d0 beq 0x16f450 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x104> */
/* @0x16f3d4 ldr r3, [r5] */
/* @0x16f3d8 mov r1, #6 */
/* @0x16f3dc mov r2, r7 */
/* @0x16f3e0 mov r0, r5 */
/* @0x16f3e4 add r4, r4, #1 */
/* @0x16f3e8 ldr r3, [r3, #0xc] */
/* @0x16f3ec blx r3 */
/* @0x16f3f0 mov r0, r7 */
/* @0x16f3f4 mov r1, #0 */
/* @0x16f3f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x16f3fc cmp r0, #0 */
/* @0x16f400 beq 0x16f3cc <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x80> */
/* @0x16f404 mov r0, #444 */
/* @0x16f408 mov r1, r9 */
/* @0x16f40c movw r2, #0x7f5 */
/* @0x16f410 mov r3, #1 */
/* @0x16f414 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x16f418 subs r10, r0, #0 */
/* @0x16f41c beq 0x16f424 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0xd8> */
/* @0x16f420 bl 0x16cfc0 <_ZN7CCameraC2Ev> */
/* @0x16f424 mov r1, r5 */
/* @0x16f428 mov r0, r10 */
/* @0x16f42c bl 0x16e95c <_ZN7CCamera11DeSerializeEP7IBuffer> */
/* @0x16f430 mov r0, r10 */
/* @0x16f434 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16f438 mov r1, r10 */
/* @0x16f43c mov r2, r0 */
/* @0x16f440 mov r0, r6 */
/* @0x16f444 bl 0x16ed1c <_ZN14CCameraManager15AddCameraToListEP7CCamerai> */
/* @0x16f448 cmp r4, r8 */
/* @0x16f44c bne 0x16f3d4 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x88> */
/* @0x16f450 mov r0, #1 */
/* @0x16f454 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x16f458 mulseq sp, r4, r4 */

/* ── FUNC 0x16f45c · CCameraManager::GetCamera(int) · size=32 · insn=8 */
/* @0x16f45c push {r4, lr} */
/* @0x16f460 mov r4, r0 */
/* @0x16f464 bl 0x16f234 <_ZN14CCameraManager16FindCameraInListEi> */
/* @0x16f468 cmn r0, #1 */
/* @0x16f46c ldrne r3, [r4, #0xc] */
/* @0x16f470 ldrne r0, [r3, r0, lsl #2] */
/* @0x16f474 moveq r0, #0 */
/* @0x16f478 pop {r4, pc} */

/* ── FUNC 0x16f47c · F_CameraApply(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x16f47c cmp r3, #1 */
/* @0x16f480 push {r3, lr} */
/* @0x16f484 mov r3, #0 */
/* @0x16f488 mov r1, r3 */
/* @0x16f48c movt r3, #0xbff0 */
/* @0x16f490 str r1, [r0, #0xc] */
/* @0x16f494 stm r0, {r1, r3} */
/* @0x16f498 ldr r0, [sp, #0x8] */
/* @0x16f49c beq 0x16f4b0 <_Z13F_CameraApplyR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16f4a0 ldr r0, [pc, #0x2c] */
/* @0x16f4a4 pop {r3, lr} */
/* @0x16f4a8 add r0, pc, r0 */
/* @0x16f4ac b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f4b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f4b4 ldr r3, [pc, #0x1c] */
/* @0x16f4b8 mov r1, r0 */
/* @0x16f4bc ldr r0, [pc, r3] */
/* @0x16f4c0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f4c4 cmp r0, #0 */
/* @0x16f4c8 popeq {r3, pc} */
/* @0x16f4cc pop {r3, lr} */
/* @0x16f4d0 b 0x16d3bc <_ZN7CCamera13ApplyMatricesEv> */
/* @0x16f4d4 andseq r11, sp, r4, lsl #17 */
/* @0x16f4d8 .word 0x0027e7b8 */

/* ── FUNC 0x16f4dc · F_CameraGetDefault(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x16f4dc ldr r3, [pc, #0x58] */
/* @0x16f4e0 mov r2, #0 */
/* @0x16f4e4 push {r4, lr} */
/* @0x16f4e8 ldr r3, [pc, r3] */
/* @0x16f4ec mov r4, r0 */
/* @0x16f4f0 ldr r0, [pc, #0x48] */
/* @0x16f4f4 str r2, [r4] */
/* @0x16f4f8 mov r1, #0 */
/* @0x16f4fc ldr r0, [pc, r0] */
/* @0x16f500 movt r1, #0xbff0 */
/* @0x16f504 str r2, [r4, #0xc] */
/* @0x16f508 str r1, [r4, #0x4] */
/* @0x16f50c ldr r1, [r3] */
/* @0x16f510 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f514 cmp r0, #0 */
/* @0x16f518 popeq {r4, pc} */
/* @0x16f51c bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16f520 vmov s15, r0 */
/* @0x16f524 vcvt.f64.s32 d7, s15 */
/* @0x16f528 vmov r0, r1, d7 */
/* @0x16f52c vmov r2, s14 */
/* @0x16f530 mov r3, r1 */
/* @0x16f534 stm r4, {r2, r3} */
/* @0x16f538 pop {r4, pc} */
/* @0x16f53c eoreq r0, r8, r4, ror sp */
/* @0x16f540 eoreq lr, r7, r8, ror r7 */

/* ── FUNC 0x16f544 · F_CameraSetDefault(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x16f544 push {r4, lr} */
/* @0x16f548 mov r1, #0 */
/* @0x16f54c ldr r0, [sp, #0x8] */
/* @0x16f550 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f554 mov r4, r0 */
/* @0x16f558 ldr r0, [pc, #0x1c] */
/* @0x16f55c mov r1, r4 */
/* @0x16f560 ldr r0, [pc, r0] */
/* @0x16f564 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f568 cmp r0, #0 */
/* @0x16f56c ldrne r3, [pc, #0xc] */
/* @0x16f570 ldrne r3, [pc, r3] */
/* @0x16f574 strne r4, [r3] */
/* @0x16f578 pop {r4, pc} */
/* @0x16f57c eoreq lr, r7, r4, lsl r7 */
/* @0x16f580 eoreq r0, r8, r12, ror #25 */

/* ── FUNC 0x16f584 · F_CameraSetViewMat(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x16f584 push {r4, r5, r6, r7, r8, lr} */
/* @0x16f588 cmp r3, #2 */
/* @0x16f58c sub sp, sp, #64 */
/* @0x16f590 mov r3, #0 */
/* @0x16f594 mov r4, r3 */
/* @0x16f598 movt r3, #0xbff0 */
/* @0x16f59c str r4, [r0, #0xc] */
/* @0x16f5a0 str r3, [r0, #0x4] */
/* @0x16f5a4 str r4, [r0] */
/* @0x16f5a8 ldr r6, [sp, #0x58] */
/* @0x16f5ac beq 0x16f5c8 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x16f5b0 ldr r0, [pc, #0xb8] */
/* @0x16f5b4 mov r1, r4 */
/* @0x16f5b8 add r0, pc, r0 */
/* @0x16f5bc bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f5c0 add sp, sp, #64 */
/* @0x16f5c4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16f5c8 mov r1, r4 */
/* @0x16f5cc mov r0, r6 */
/* @0x16f5d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f5d4 ldr r3, [pc, #0x98] */
/* @0x16f5d8 mov r1, r0 */
/* @0x16f5dc ldr r0, [pc, r3] */
/* @0x16f5e0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f5e4 subs r7, r0, #0 */
/* @0x16f5e8 beq 0x16f5c0 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x16f5ec ldr r1, [r6, #0x10] */
/* @0x16f5f0 cmp r1, #0 */
/* @0x16f5f4 beq 0x16f660 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x16f5f8 ldr r3, [r1, #0x4] */
/* @0x16f5fc ldr r2, [r3] */
/* @0x16f600 cmp r2, #16 */
/* @0x16f604 beq 0x16f620 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x16f608 ldr r0, [pc, #0x68] */
/* @0x16f60c mov r1, r4 */
/* @0x16f610 add r0, pc, r0 */
/* @0x16f614 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x16f618 add sp, sp, #64 */
/* @0x16f61c pop {r4, r5, r6, r7, r8, pc} */
/* @0x16f620 mov r5, sp */
/* @0x16f624 b 0x16f630 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x16f628 ldr r3, [r6, #0x10] */
/* @0x16f62c ldr r3, [r3, #0x4] */
/* @0x16f630 mov r1, r4 */
/* @0x16f634 ldr r0, [r3, #0x4] */
/* @0x16f638 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f63c add r4, r4, #1 */
/* @0x16f640 cmp r4, #16 */
/* @0x16f644 str r0, [r5], #4 */
/* @0x16f648 bne 0x16f628 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x16f64c mov r0, r7 */
/* @0x16f650 mov r1, sp */
/* @0x16f654 bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix> */
/* @0x16f658 add sp, sp, #64 */
/* @0x16f65c pop {r4, r5, r6, r7, r8, pc} */
/* @0x16f660 ldr r0, [pc, #0x14] */
/* @0x16f664 add r0, pc, r0 */
/* @0x16f668 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x16f66c b 0x16f5c0 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x16f670 andseq r11, sp, r0, lsr #15 */
/* @0x16f674 mlaeq r7, r8, r6, lr */
/* @0x16f678 andseq r11, sp, r4, asr #15 */
/* @0x16f67c andseq r11, sp, r8, lsr #14 */

/* ── FUNC 0x16f680 · F_CameraSetProjMat(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x16f680 push {r4, r5, r6, r7, r8, lr} */
/* @0x16f684 cmp r3, #2 */
/* @0x16f688 sub sp, sp, #64 */
/* @0x16f68c mov r3, #0 */
/* @0x16f690 mov r4, r3 */
/* @0x16f694 movt r3, #0xbff0 */
/* @0x16f698 str r4, [r0, #0xc] */
/* @0x16f69c str r3, [r0, #0x4] */
/* @0x16f6a0 str r4, [r0] */
/* @0x16f6a4 ldr r6, [sp, #0x58] */
/* @0x16f6a8 beq 0x16f6c4 <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x16f6ac ldr r0, [pc, #0xb8] */
/* @0x16f6b0 mov r1, r4 */
/* @0x16f6b4 add r0, pc, r0 */
/* @0x16f6b8 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f6bc add sp, sp, #64 */
/* @0x16f6c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16f6c4 mov r1, r4 */
/* @0x16f6c8 mov r0, r6 */
/* @0x16f6cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f6d0 ldr r3, [pc, #0x98] */
/* @0x16f6d4 mov r1, r0 */
/* @0x16f6d8 ldr r0, [pc, r3] */
/* @0x16f6dc bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f6e0 subs r7, r0, #0 */
/* @0x16f6e4 beq 0x16f6bc <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x16f6e8 ldr r1, [r6, #0x10] */
/* @0x16f6ec cmp r1, #0 */
/* @0x16f6f0 beq 0x16f75c <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x16f6f4 ldr r3, [r1, #0x4] */
/* @0x16f6f8 ldr r2, [r3] */
/* @0x16f6fc cmp r2, #16 */
/* @0x16f700 beq 0x16f71c <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x16f704 ldr r0, [pc, #0x68] */
/* @0x16f708 mov r1, r4 */
/* @0x16f70c add r0, pc, r0 */
/* @0x16f710 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x16f714 add sp, sp, #64 */
/* @0x16f718 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16f71c mov r5, sp */
/* @0x16f720 b 0x16f72c <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x16f724 ldr r3, [r6, #0x10] */
/* @0x16f728 ldr r3, [r3, #0x4] */
/* @0x16f72c mov r1, r4 */
/* @0x16f730 ldr r0, [r3, #0x4] */
/* @0x16f734 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f738 add r4, r4, #1 */
/* @0x16f73c cmp r4, #16 */
/* @0x16f740 str r0, [r5], #4 */
/* @0x16f744 bne 0x16f724 <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x16f748 mov r0, r7 */
/* @0x16f74c mov r1, sp */
/* @0x16f750 bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix> */
/* @0x16f754 add sp, sp, #64 */
/* @0x16f758 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16f75c ldr r0, [pc, #0x14] */
/* @0x16f760 add r0, pc, r0 */
/* @0x16f764 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x16f768 b 0x16f6bc <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x16f76c andseq r11, sp, r4, asr r7 */
/* @0x16f770 mlaeq r7, r12, r5, lr */
/* @0x16f774 andseq r11, sp, r8, asr #13 */
/* @0x16f778 andseq r11, sp, r12, lsr #12 */

/* ── FUNC 0x16f77c · F_CameraSetViewTarget(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x16f77c cmp r3, #2 */
/* @0x16f780 push {r3, r4, r5, lr} */
/* @0x16f784 mov r3, #0 */
/* @0x16f788 mov r1, r3 */
/* @0x16f78c ldr r4, [sp, #0x10] */
/* @0x16f790 movt r3, #0xbff0 */
/* @0x16f794 str r1, [r0, #0xc] */
/* @0x16f798 stm r0, {r1, r3} */
/* @0x16f79c beq 0x16f7b0 <_Z21F_CameraSetViewTargetR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16f7a0 ldr r0, [pc, #0x44] */
/* @0x16f7a4 pop {r3, r4, r5, lr} */
/* @0x16f7a8 add r0, pc, r0 */
/* @0x16f7ac b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f7b0 mov r0, r4 */
/* @0x16f7b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f7b8 ldr r3, [pc, #0x30] */
/* @0x16f7bc mov r1, r0 */
/* @0x16f7c0 ldr r0, [pc, r3] */
/* @0x16f7c4 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f7c8 subs r5, r0, #0 */
/* @0x16f7cc popeq {r3, r4, r5, pc} */
/* @0x16f7d0 mov r0, r4 */
/* @0x16f7d4 mov r1, #1 */
/* @0x16f7d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f7dc mov r1, r0 */
/* @0x16f7e0 mov r0, r5 */
/* @0x16f7e4 pop {r3, r4, r5, lr} */
/* @0x16f7e8 b 0x16d32c <_ZN7CCamera17SetTargetInstanceEi> */
/* @0x16f7ec mulseq sp, r4, r6 */
/* @0x16f7f0 .word 0x0027e4b4 */

/* ── FUNC 0x16f7f4 · F_CameraSetUpdateScript(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x16f7f4 cmp r3, #2 */
/* @0x16f7f8 push {r3, r4, r5, lr} */
/* @0x16f7fc mov r3, #0 */
/* @0x16f800 mov r1, r3 */
/* @0x16f804 ldr r4, [sp, #0x10] */
/* @0x16f808 movt r3, #0xbff0 */
/* @0x16f80c str r1, [r0, #0xc] */
/* @0x16f810 stm r0, {r1, r3} */
/* @0x16f814 beq 0x16f828 <_Z23F_CameraSetUpdateScriptR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16f818 ldr r0, [pc, #0x44] */
/* @0x16f81c pop {r3, r4, r5, lr} */
/* @0x16f820 add r0, pc, r0 */
/* @0x16f824 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f828 mov r0, r4 */
/* @0x16f82c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f830 ldr r3, [pc, #0x30] */
/* @0x16f834 mov r1, r0 */
/* @0x16f838 ldr r0, [pc, r3] */
/* @0x16f83c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f840 subs r5, r0, #0 */
/* @0x16f844 popeq {r3, r4, r5, pc} */
/* @0x16f848 mov r0, r4 */
/* @0x16f84c mov r1, #1 */
/* @0x16f850 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f854 mov r1, r0 */
/* @0x16f858 mov r0, r5 */
/* @0x16f85c pop {r3, r4, r5, lr} */
/* @0x16f860 b 0x16d35c <_ZN7CCamera15SetUpdateScriptEi> */
/* @0x16f864 andseq r11, sp, r4, asr r6 */
/* @0x16f868 eoreq lr, r7, r12, lsr r4 */

/* ── FUNC 0x16f86c · F_CameraSetBeginScript(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x16f86c cmp r3, #2 */
/* @0x16f870 push {r3, r4, r5, lr} */
/* @0x16f874 mov r3, #0 */
/* @0x16f878 mov r1, r3 */
/* @0x16f87c ldr r4, [sp, #0x10] */
/* @0x16f880 movt r3, #0xbff0 */
/* @0x16f884 str r1, [r0, #0xc] */
/* @0x16f888 stm r0, {r1, r3} */
/* @0x16f88c beq 0x16f8a0 <_Z22F_CameraSetBeginScriptR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16f890 ldr r0, [pc, #0x44] */
/* @0x16f894 pop {r3, r4, r5, lr} */
/* @0x16f898 add r0, pc, r0 */
/* @0x16f89c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f8a0 mov r0, r4 */
/* @0x16f8a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f8a8 ldr r3, [pc, #0x30] */
/* @0x16f8ac mov r1, r0 */
/* @0x16f8b0 ldr r0, [pc, r3] */
/* @0x16f8b4 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f8b8 subs r5, r0, #0 */
/* @0x16f8bc popeq {r3, r4, r5, pc} */
/* @0x16f8c0 mov r0, r4 */
/* @0x16f8c4 mov r1, #1 */
/* @0x16f8c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f8cc mov r1, r0 */
/* @0x16f8d0 mov r0, r5 */
/* @0x16f8d4 pop {r3, r4, r5, lr} */
/* @0x16f8d8 b 0x16d33c <_ZN7CCamera14SetBeginScriptEi> */
/* @0x16f8dc andseq r11, sp, r4, lsl r6 */
/* @0x16f8e0 eoreq lr, r7, r4, asr #7 */

/* ── FUNC 0x16f8e4 · F_CameraSetEndScript(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x16f8e4 cmp r3, #2 */
/* @0x16f8e8 push {r3, r4, r5, lr} */
/* @0x16f8ec mov r3, #0 */
/* @0x16f8f0 mov r1, r3 */
/* @0x16f8f4 ldr r4, [sp, #0x10] */
/* @0x16f8f8 movt r3, #0xbff0 */
/* @0x16f8fc str r1, [r0, #0xc] */
/* @0x16f900 stm r0, {r1, r3} */
/* @0x16f904 beq 0x16f918 <_Z20F_CameraSetEndScriptR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16f908 ldr r0, [pc, #0x44] */
/* @0x16f90c pop {r3, r4, r5, lr} */
/* @0x16f910 add r0, pc, r0 */
/* @0x16f914 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f918 mov r0, r4 */
/* @0x16f91c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f920 ldr r3, [pc, #0x30] */
/* @0x16f924 mov r1, r0 */
/* @0x16f928 ldr r0, [pc, r3] */
/* @0x16f92c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f930 subs r5, r0, #0 */
/* @0x16f934 popeq {r3, r4, r5, pc} */
/* @0x16f938 mov r0, r4 */
/* @0x16f93c mov r1, #1 */
/* @0x16f940 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f944 mov r1, r0 */
/* @0x16f948 mov r0, r5 */
/* @0x16f94c pop {r3, r4, r5, lr} */
/* @0x16f950 b 0x16d34c <_ZN7CCamera12SetEndScriptEi> */
/* @0x16f954 ldrsbeq r11, [sp], -r4 */
/* @0x16f958 eoreq lr, r7, r12, asr #6 */

/* ── FUNC 0x16f95c · F_CameraSetView(RValue&, CInstance*, CInstance*, int, RValue*) · size=344 · insn=86 */
/* @0x16f95c cmp r3, #11 */
/* @0x16f960 push {r3, r4, r5, lr} */
/* @0x16f964 mov r3, #0 */
/* @0x16f968 mov r1, r3 */
/* @0x16f96c ldr r4, [sp, #0x10] */
/* @0x16f970 movt r3, #0xbff0 */
/* @0x16f974 str r1, [r0, #0xc] */
/* @0x16f978 stm r0, {r1, r3} */
/* @0x16f97c beq 0x16f990 <_Z15F_CameraSetViewR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16f980 ldr r0, [pc, #0x124] */
/* @0x16f984 pop {r3, r4, r5, lr} */
/* @0x16f988 add r0, pc, r0 */
/* @0x16f98c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f990 mov r0, r4 */
/* @0x16f994 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f998 ldr r3, [pc, #0x110] */
/* @0x16f99c mov r1, r0 */
/* @0x16f9a0 ldr r0, [pc, r3] */
/* @0x16f9a4 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16f9a8 subs r5, r0, #0 */
/* @0x16f9ac popeq {r3, r4, r5, pc} */
/* @0x16f9b0 mov r0, r4 */
/* @0x16f9b4 mov r1, #1 */
/* @0x16f9b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f9bc mov r1, r0 */
/* @0x16f9c0 mov r0, r5 */
/* @0x16f9c4 bl 0x16d29c <_ZN7CCamera8SetViewXEf> */
/* @0x16f9c8 mov r0, r4 */
/* @0x16f9cc mov r1, #2 */
/* @0x16f9d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f9d4 mov r1, r0 */
/* @0x16f9d8 mov r0, r5 */
/* @0x16f9dc bl 0x16d2ac <_ZN7CCamera8SetViewYEf> */
/* @0x16f9e0 mov r0, r4 */
/* @0x16f9e4 mov r1, #3 */
/* @0x16f9e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f9ec mov r1, r0 */
/* @0x16f9f0 mov r0, r5 */
/* @0x16f9f4 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf> */
/* @0x16f9f8 mov r0, r4 */
/* @0x16f9fc mov r1, #4 */
/* @0x16fa00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fa04 mov r1, r0 */
/* @0x16fa08 mov r0, r5 */
/* @0x16fa0c bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf> */
/* @0x16fa10 mov r0, r4 */
/* @0x16fa14 mov r1, #5 */
/* @0x16fa18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fa1c mov r1, r0 */
/* @0x16fa20 mov r0, r5 */
/* @0x16fa24 bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf> */
/* @0x16fa28 mov r0, r4 */
/* @0x16fa2c mov r1, #6 */
/* @0x16fa30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fa34 mov r1, r0 */
/* @0x16fa38 mov r0, r5 */
/* @0x16fa3c bl 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf> */
/* @0x16fa40 mov r0, r4 */
/* @0x16fa44 mov r1, #7 */
/* @0x16fa48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fa4c mov r1, r0 */
/* @0x16fa50 mov r0, r5 */
/* @0x16fa54 bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf> */
/* @0x16fa58 mov r0, r4 */
/* @0x16fa5c mov r1, #8 */
/* @0x16fa60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fa64 mov r1, r0 */
/* @0x16fa68 mov r0, r5 */
/* @0x16fa6c bl 0x16d30c <_ZN7CCamera14SetViewBorderYEf> */
/* @0x16fa70 mov r0, r4 */
/* @0x16fa74 mov r1, #9 */
/* @0x16fa78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fa7c mov r1, r0 */
/* @0x16fa80 mov r0, r5 */
/* @0x16fa84 bl 0x16d31c <_ZN7CCamera12SetViewAngleEf> */
/* @0x16fa88 mov r0, r4 */
/* @0x16fa8c mov r1, #10 */
/* @0x16fa90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16fa94 mov r1, r0 */
/* @0x16fa98 mov r0, r5 */
/* @0x16fa9c bl 0x16d32c <_ZN7CCamera17SetTargetInstanceEi> */
/* @0x16faa0 mov r0, r5 */
/* @0x16faa4 pop {r3, r4, r5, lr} */
/* @0x16faa8 b 0x16d36c <_ZN7CCamera12SetViewDirtyEv> */
/* @0x16faac mulseq sp, r0, r5 */
/* @0x16fab0 .word 0x0027e2d4 */

/* ── FUNC 0x16fab4 · F_CameraSetViewPos(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x16fab4 cmp r3, #3 */
/* @0x16fab8 push {r3, r4, r5, lr} */
/* @0x16fabc mov r3, #0 */
/* @0x16fac0 mov r1, r3 */
/* @0x16fac4 ldr r4, [sp, #0x10] */
/* @0x16fac8 movt r3, #0xbff0 */
/* @0x16facc str r1, [r0, #0xc] */
/* @0x16fad0 stm r0, {r1, r3} */
/* @0x16fad4 beq 0x16fae8 <_Z18F_CameraSetViewPosR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16fad8 ldr r0, [pc, #0x64] */
/* @0x16fadc pop {r3, r4, r5, lr} */
/* @0x16fae0 add r0, pc, r0 */
/* @0x16fae4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16fae8 mov r0, r4 */
/* @0x16faec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16faf0 ldr r3, [pc, #0x50] */
/* @0x16faf4 mov r1, r0 */
/* @0x16faf8 ldr r0, [pc, r3] */
/* @0x16fafc bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16fb00 subs r5, r0, #0 */
/* @0x16fb04 popeq {r3, r4, r5, pc} */
/* @0x16fb08 mov r0, r4 */
/* @0x16fb0c mov r1, #1 */
/* @0x16fb10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fb14 mov r1, r0 */
/* @0x16fb18 mov r0, r5 */
/* @0x16fb1c bl 0x16d29c <_ZN7CCamera8SetViewXEf> */
/* @0x16fb20 mov r0, r4 */
/* @0x16fb24 mov r1, #2 */
/* @0x16fb28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fb2c mov r1, r0 */
/* @0x16fb30 mov r0, r5 */
/* @0x16fb34 bl 0x16d2ac <_ZN7CCamera8SetViewYEf> */
/* @0x16fb38 mov r0, r5 */
/* @0x16fb3c pop {r3, r4, r5, lr} */
/* @0x16fb40 b 0x16d36c <_ZN7CCamera12SetViewDirtyEv> */
/* @0x16fb44 andseq r11, sp, r8, ror #8 */
/* @0x16fb48 eoreq lr, r7, r12, ror r1 */

/* ── FUNC 0x16fb4c · F_CameraSetViewSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x16fb4c cmp r3, #3 */
/* @0x16fb50 push {r3, r4, r5, lr} */
/* @0x16fb54 mov r3, #0 */
/* @0x16fb58 mov r1, r3 */
/* @0x16fb5c ldr r4, [sp, #0x10] */
/* @0x16fb60 movt r3, #0xbff0 */
/* @0x16fb64 str r1, [r0, #0xc] */
/* @0x16fb68 stm r0, {r1, r3} */
/* @0x16fb6c beq 0x16fb80 <_Z19F_CameraSetViewSizeR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16fb70 ldr r0, [pc, #0x64] */
/* @0x16fb74 pop {r3, r4, r5, lr} */
/* @0x16fb78 add r0, pc, r0 */
/* @0x16fb7c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16fb80 mov r0, r4 */
/* @0x16fb84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16fb88 ldr r3, [pc, #0x50] */
/* @0x16fb8c mov r1, r0 */
/* @0x16fb90 ldr r0, [pc, r3] */
/* @0x16fb94 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16fb98 subs r5, r0, #0 */
/* @0x16fb9c popeq {r3, r4, r5, pc} */
/* @0x16fba0 mov r0, r4 */
/* @0x16fba4 mov r1, #1 */
/* @0x16fba8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fbac mov r1, r0 */
/* @0x16fbb0 mov r0, r5 */
/* @0x16fbb4 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf> */
/* @0x16fbb8 mov r0, r4 */
/* @0x16fbbc mov r1, #2 */
/* @0x16fbc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fbc4 mov r1, r0 */
/* @0x16fbc8 mov r0, r5 */
/* @0x16fbcc bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf> */
/* @0x16fbd0 mov r0, r5 */
/* @0x16fbd4 pop {r3, r4, r5, lr} */
/* @0x16fbd8 b 0x16d36c <_ZN7CCamera12SetViewDirtyEv> */
/* @0x16fbdc andseq r11, sp, r4, lsl #8 */
/* @0x16fbe0 eoreq lr, r7, r4, ror #1 */

/* ── FUNC 0x16fbe4 · F_CameraSetViewSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x16fbe4 cmp r3, #3 */
/* @0x16fbe8 push {r3, r4, r5, lr} */
/* @0x16fbec mov r3, #0 */
/* @0x16fbf0 mov r1, r3 */
/* @0x16fbf4 ldr r4, [sp, #0x10] */
/* @0x16fbf8 movt r3, #0xbff0 */
/* @0x16fbfc str r1, [r0, #0xc] */
/* @0x16fc00 stm r0, {r1, r3} */
/* @0x16fc04 beq 0x16fc18 <_Z20F_CameraSetViewSpeedR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16fc08 ldr r0, [pc, #0x5c] */
/* @0x16fc0c pop {r3, r4, r5, lr} */
/* @0x16fc10 add r0, pc, r0 */
/* @0x16fc14 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16fc18 mov r0, r4 */
/* @0x16fc1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16fc20 ldr r3, [pc, #0x48] */
/* @0x16fc24 mov r1, r0 */
/* @0x16fc28 ldr r0, [pc, r3] */
/* @0x16fc2c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16fc30 subs r5, r0, #0 */
/* @0x16fc34 popeq {r3, r4, r5, pc} */
/* @0x16fc38 mov r0, r4 */
/* @0x16fc3c mov r1, #1 */
/* @0x16fc40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fc44 mov r1, r0 */
/* @0x16fc48 mov r0, r5 */
/* @0x16fc4c bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf> */
/* @0x16fc50 mov r0, r4 */
/* @0x16fc54 mov r1, #2 */
/* @0x16fc58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fc5c mov r1, r0 */
/* @0x16fc60 mov r0, r5 */
/* @0x16fc64 pop {r3, r4, r5, lr} */
/* @0x16fc68 b 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf> */
/* @0x16fc6c andseq r11, sp, r0, lsr #7 */
/* @0x16fc70 eoreq lr, r7, r12, asr #32 */

/* ── FUNC 0x16fc74 · F_CameraSetViewBorder(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x16fc74 cmp r3, #3 */
/* @0x16fc78 push {r3, r4, r5, lr} */
/* @0x16fc7c mov r3, #0 */
/* @0x16fc80 mov r1, r3 */
/* @0x16fc84 ldr r4, [sp, #0x10] */
/* @0x16fc88 movt r3, #0xbff0 */
/* @0x16fc8c str r1, [r0, #0xc] */
/* @0x16fc90 stm r0, {r1, r3} */
/* @0x16fc94 beq 0x16fca8 <_Z21F_CameraSetViewBorderR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16fc98 ldr r0, [pc, #0x5c] */
/* @0x16fc9c pop {r3, r4, r5, lr} */
/* @0x16fca0 add r0, pc, r0 */
/* @0x16fca4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16fca8 mov r0, r4 */
/* @0x16fcac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16fcb0 ldr r3, [pc, #0x48] */
/* @0x16fcb4 mov r1, r0 */
/* @0x16fcb8 ldr r0, [pc, r3] */
/* @0x16fcbc bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16fcc0 subs r5, r0, #0 */
/* @0x16fcc4 popeq {r3, r4, r5, pc} */
/* @0x16fcc8 mov r0, r4 */
/* @0x16fccc mov r1, #1 */
/* @0x16fcd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fcd4 mov r1, r0 */
/* @0x16fcd8 mov r0, r5 */
/* @0x16fcdc bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf> */
/* @0x16fce0 mov r0, r4 */
/* @0x16fce4 mov r1, #2 */
/* @0x16fce8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fcec mov r1, r0 */
/* @0x16fcf0 mov r0, r5 */
/* @0x16fcf4 pop {r3, r4, r5, lr} */
/* @0x16fcf8 b 0x16d30c <_ZN7CCamera14SetViewBorderYEf> */
/* @0x16fcfc andseq r11, sp, r4, asr #6 */
/* @0x16fd00 .word 0x0027dfbc */

/* ── FUNC 0x16fd04 · F_CameraSetViewAngle(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x16fd04 cmp r3, #2 */
/* @0x16fd08 push {r3, r4, r5, lr} */
/* @0x16fd0c mov r3, #0 */
/* @0x16fd10 mov r1, r3 */
/* @0x16fd14 ldr r4, [sp, #0x10] */
/* @0x16fd18 movt r3, #0xbff0 */
/* @0x16fd1c str r1, [r0, #0xc] */
/* @0x16fd20 stm r0, {r1, r3} */
/* @0x16fd24 beq 0x16fd38 <_Z20F_CameraSetViewAngleR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x16fd28 ldr r0, [pc, #0x4c] */
/* @0x16fd2c pop {r3, r4, r5, lr} */
/* @0x16fd30 add r0, pc, r0 */
/* @0x16fd34 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16fd38 mov r0, r4 */
/* @0x16fd3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16fd40 ldr r3, [pc, #0x38] */
/* @0x16fd44 mov r1, r0 */
/* @0x16fd48 ldr r0, [pc, r3] */
/* @0x16fd4c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16fd50 subs r5, r0, #0 */
/* @0x16fd54 popeq {r3, r4, r5, pc} */
/* @0x16fd58 mov r0, r4 */
/* @0x16fd5c mov r1, #1 */
/* @0x16fd60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16fd64 mov r1, r0 */
/* @0x16fd68 mov r0, r5 */
/* @0x16fd6c bl 0x16d31c <_ZN7CCamera12SetViewAngleEf> */
/* @0x16fd70 mov r0, r5 */
/* @0x16fd74 pop {r3, r4, r5, lr} */
/* @0x16fd78 b 0x16d36c <_ZN7CCamera12SetViewDirtyEv> */
/* @0x16fd7c andseq r11, sp, r12, ror #5 */
/* @0x16fd80 eoreq sp, r7, r12, lsr #30 */

/* ── FUNC 0x16fd84 · F_CameraGetViewMat(RValue&, CInstance*, CInstance*, int, RValue*) · size=324 · insn=81 */
/* @0x16fd84 cmp r3, #1 */
/* @0x16fd88 mov r2, #0 */
/* @0x16fd8c push {r4, r5, r6, r7, r8, lr} */
/* @0x16fd90 mov r6, r2 */
/* @0x16fd94 sub sp, sp, #64 */
/* @0x16fd98 movt r2, #0xbff0 */
/* @0x16fd9c mov r7, r3 */
/* @0x16fda0 mov r4, r0 */
/* @0x16fda4 str r6, [r0, #0xc] */
/* @0x16fda8 str r2, [r0, #0x4] */
/* @0x16fdac str r6, [r0] */
/* @0x16fdb0 beq 0x16fdcc <_Z18F_CameraGetViewMatR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x16fdb4 ldr r0, [pc, #0xfc] */
/* @0x16fdb8 mov r1, r6 */
/* @0x16fdbc add r0, pc, r0 */
/* @0x16fdc0 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16fdc4 add sp, sp, #64 */
/* @0x16fdc8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16fdcc mov r1, r6 */
/* @0x16fdd0 ldr r0, [sp, #0x58] */
/* @0x16fdd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16fdd8 ldr r3, [pc, #0xdc] */
/* @0x16fddc mov r1, r0 */
/* @0x16fde0 ldr r0, [pc, r3] */
/* @0x16fde4 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16fde8 subs r1, r0, #0 */
/* @0x16fdec beq 0x16fdc4 <_Z18F_CameraGetViewMatR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x16fdf0 mov r0, sp */
/* @0x16fdf4 mov r5, sp */
/* @0x16fdf8 bl 0x16d170 <_ZN7CCamera10GetViewMatEv> */
/* @0x16fdfc mov r3, #2 */
/* @0x16fe00 mov r0, r4 */
/* @0x16fe04 str r3, [r4, #0xc] */
/* @0x16fe08 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x16fe0c ldr r1, [pc, #0xac] */
/* @0x16fe10 mov r3, r7 */
/* @0x16fe14 mov r2, #70 */
/* @0x16fe18 add r1, pc, r1 */
/* @0x16fe1c mov r8, r0 */
/* @0x16fe20 mov r0, #8 */
/* @0x16fe24 str r8, [r4] */
/* @0x16fe28 str r7, [r8, #0x10] */
/* @0x16fe2c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x16fe30 ldr r1, [pc, #0x8c] */
/* @0x16fe34 mov r3, r7 */
/* @0x16fe38 movw r2, #0x62d */
/* @0x16fe3c add r1, pc, r1 */
/* @0x16fe40 str r0, [r8, #0x4] */
/* @0x16fe44 mov r0, #256 */
/* @0x16fe48 ldr r12, [r4] */
/* @0x16fe4c ldr r7, [r12, #0x4] */
/* @0x16fe50 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x16fe54 mov r3, #16 */
/* @0x16fe58 mov r1, r6 */
/* @0x16fe5c str r0, [r7, #0x4] */
/* @0x16fe60 ldr r2, [r4] */
/* @0x16fe64 ldr r0, [r2, #0x4] */
/* @0x16fe68 str r3, [r0] */
/* @0x16fe6c ldr r12, [r4] */
/* @0x16fe70 b 0x16fe7c <_Z18F_CameraGetViewMatR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x16fe74 ldr r12, [r4] */
/* @0x16fe78 ldr r0, [r12, #0x4] */
/* @0x16fe7c vldmia r5!, {s15} */
/* @0x16fe80 vcvt.f64.f32 d6, s15 */
/* @0x16fe84 ldr r12, [r12, #0x4] */
/* @0x16fe88 ldr r0, [r0, #0x4] */
/* @0x16fe8c ldr r12, [r12, #0x4] */
/* @0x16fe90 add r0, r0, r1 */
/* @0x16fe94 str r6, [r0, #0xc] */
/* @0x16fe98 vmov r2, r3, d6 */
/* @0x16fe9c str r2, [r12, r1]! */
/* @0x16fea0 add r1, r1, #16 */
/* @0x16fea4 cmp r1, #256 */
/* @0x16fea8 str r3, [r12, #0x4] */
/* @0x16feac bne 0x16fe74 <_Z18F_CameraGetViewMatR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x16feb0 add sp, sp, #64 */
/* @0x16feb4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16feb8 mulseq sp, r4, r2 */
/* @0x16febc mlaeq r7, r4, lr, sp */
/* @0x16fec0 andseq r1, r12, r8, lsl r2 */
/* @0x16fec4 andseq r10, sp, r12, lsl r10 */

/* ── FUNC 0x16fec8 · F_CameraGetProjMat(RValue&, CInstance*, CInstance*, int, RValue*) · size=324 · insn=81 */
/* @0x16fec8 cmp r3, #1 */
/* @0x16fecc mov r2, #0 */
/* @0x16fed0 push {r4, r5, r6, r7, r8, lr} */
/* @0x16fed4 mov r6, r2 */
/* @0x16fed8 sub sp, sp, #64 */
/* @0x16fedc movt r2, #0xbff0 */
/* @0x16fee0 mov r7, r3 */
/* @0x16fee4 mov r4, r0 */
/* @0x16fee8 str r6, [r0, #0xc] */
/* @0x16feec str r2, [r0, #0x4] */
/* @0x16fef0 str r6, [r0] */
/* @0x16fef4 beq 0x16ff10 <_Z18F_CameraGetProjMatR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x16fef8 ldr r0, [pc, #0xfc] */
/* @0x16fefc mov r1, r6 */
/* @0x16ff00 add r0, pc, r0 */
/* @0x16ff04 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16ff08 add sp, sp, #64 */
/* @0x16ff0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x16ff10 mov r1, r6 */
/* @0x16ff14 ldr r0, [sp, #0x58] */
/* @0x16ff18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16ff1c ldr r3, [pc, #0xdc] */
/* @0x16ff20 mov r1, r0 */
/* @0x16ff24 ldr r0, [pc, r3] */
/* @0x16ff28 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x16ff2c subs r1, r0, #0 */
/* @0x16ff30 beq 0x16ff08 <_Z18F_CameraGetProjMatR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x16ff34 mov r0, sp */
/* @0x16ff38 mov r5, sp */
/* @0x16ff3c bl 0x16d134 <_ZN7CCamera10GetProjMatEv> */
/* @0x16ff40 mov r3, #2 */
/* @0x16ff44 mov r0, r4 */
/* @0x16ff48 str r3, [r4, #0xc] */
/* @0x16ff4c bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x16ff50 ldr r1, [pc, #0xac] */
/* @0x16ff54 mov r3, r7 */
/* @0x16ff58 mov r2, #70 */
/* @0x16ff5c add r1, pc, r1 */
/* @0x16ff60 mov r8, r0 */
/* @0x16ff64 mov r0, #8 */
/* @0x16ff68 str r8, [r4] */
/* @0x16ff6c str r7, [r8, #0x10] */
/* @0x16ff70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x16ff74 ldr r1, [pc, #0x8c] */
/* @0x16ff78 mov r3, r7 */
/* @0x16ff7c movw r2, #0x64c */
/* @0x16ff80 add r1, pc, r1 */
/* @0x16ff84 str r0, [r8, #0x4] */
/* @0x16ff88 mov r0, #256 */
/* @0x16ff8c ldr r12, [r4] */
/* @0x16ff90 ldr r7, [r12, #0x4] */
/* @0x16ff94 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x16ff98 mov r3, #16 */
/* @0x16ff9c mov r1, r6 */
/* @0x16ffa0 str r0, [r7, #0x4] */
/* @0x16ffa4 ldr r2, [r4] */
/* @0x16ffa8 ldr r0, [r2, #0x4] */
/* @0x16ffac str r3, [r0] */
/* @0x16ffb0 ldr r12, [r4] */
/* @0x16ffb4 b 0x16ffc0 <_Z18F_CameraGetProjMatR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x16ffb8 ldr r12, [r4] */
/* @0x16ffbc ldr r0, [r12, #0x4] */
/* @0x16ffc0 vldmia r5!, {s15} */
/* @0x16ffc4 vcvt.f64.f32 d6, s15 */
/* @0x16ffc8 ldr r12, [r12, #0x4] */
/* @0x16ffcc ldr r0, [r0, #0x4] */
/* @0x16ffd0 ldr r12, [r12, #0x4] */
/* @0x16ffd4 add r0, r0, r1 */
/* @0x16ffd8 str r6, [r0, #0xc] */
/* @0x16ffdc vmov r2, r3, d6 */
/* @0x16ffe0 str r2, [r12, r1]! */
/* @0x16ffe4 add r1, r1, #16 */
/* @0x16ffe8 cmp r1, #256 */
/* @0x16ffec str r3, [r12, #0x4] */
/* @0x16fff0 bne 0x16ffb8 <_Z18F_CameraGetProjMatR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x16fff4 add sp, sp, #64 */
/* @0x16fff8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16fffc andseq r11, sp, r4, lsl #3 */
/* @0x170000 eoreq sp, r7, r0, asr sp */
/* @0x170004 ldrsbeq r1, [r12], -r4 */
/* @0x170008 ldrsbeq r10, [sp], -r8 */

/* ── FUNC 0x17000c · F_CameraGetViewTarget(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x17000c cmp r3, #1 */
/* @0x170010 mov r3, #0 */
/* @0x170014 push {r4, lr} */
/* @0x170018 mov r1, r3 */
/* @0x17001c mov r4, r0 */
/* @0x170020 movt r3, #0xbff0 */
/* @0x170024 str r1, [r0, #0xc] */
/* @0x170028 stm r0, {r1, r3} */
/* @0x17002c ldr r0, [sp, #0x8] */
/* @0x170030 beq 0x170044 <_Z21F_CameraGetViewTargetR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x170034 ldr r0, [pc, #0x44] */
/* @0x170038 pop {r4, lr} */
/* @0x17003c add r0, pc, r0 */
/* @0x170040 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x170044 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x170048 ldr r3, [pc, #0x34] */
/* @0x17004c mov r1, r0 */
/* @0x170050 ldr r0, [pc, r3] */
/* @0x170054 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170058 cmp r0, #0 */
/* @0x17005c popeq {r4, pc} */
/* @0x170060 bl 0x16d334 <_ZN7CCamera17GetTargetInstanceEv> */
/* @0x170064 vmov s15, r0 */
/* @0x170068 vcvt.f64.s32 d7, s15 */
/* @0x17006c vmov r0, r1, d7 */
/* @0x170070 vmov r2, s14 */
/* @0x170074 mov r3, r1 */
/* @0x170078 stm r4, {r2, r3} */
/* @0x17007c pop {r4, pc} */
/* @0x170080 andseq r11, sp, r12, ror r0 */
/* @0x170084 eoreq sp, r7, r4, lsr #24 */

/* ── FUNC 0x170088 · F_CameraGetUpdateScript(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x170088 cmp r3, #1 */
/* @0x17008c mov r3, #0 */
/* @0x170090 push {r4, lr} */
/* @0x170094 mov r1, r3 */
/* @0x170098 mov r4, r0 */
/* @0x17009c movt r3, #0xbff0 */
/* @0x1700a0 str r1, [r0, #0xc] */
/* @0x1700a4 stm r0, {r1, r3} */
/* @0x1700a8 ldr r0, [sp, #0x8] */
/* @0x1700ac beq 0x1700c0 <_Z23F_CameraGetUpdateScriptR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1700b0 ldr r0, [pc, #0x44] */
/* @0x1700b4 pop {r4, lr} */
/* @0x1700b8 add r0, pc, r0 */
/* @0x1700bc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1700c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1700c4 ldr r3, [pc, #0x34] */
/* @0x1700c8 mov r1, r0 */
/* @0x1700cc ldr r0, [pc, r3] */
/* @0x1700d0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1700d4 cmp r0, #0 */
/* @0x1700d8 popeq {r4, pc} */
/* @0x1700dc bl 0x16d364 <_ZN7CCamera15GetUpdateScriptEv> */
/* @0x1700e0 vmov s15, r0 */
/* @0x1700e4 vcvt.f64.s32 d7, s15 */
/* @0x1700e8 vmov r0, r1, d7 */
/* @0x1700ec vmov r2, s14 */
/* @0x1700f0 mov r3, r1 */
/* @0x1700f4 stm r4, {r2, r3} */
/* @0x1700f8 pop {r4, pc} */
/* @0x1700fc andseq r11, sp, r8, lsr r0 */
/* @0x170100 eoreq sp, r7, r8, lsr #23 */

/* ── FUNC 0x170104 · F_CameraGetBeginScript(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x170104 cmp r3, #1 */
/* @0x170108 mov r3, #0 */
/* @0x17010c push {r4, lr} */
/* @0x170110 mov r1, r3 */
/* @0x170114 mov r4, r0 */
/* @0x170118 movt r3, #0xbff0 */
/* @0x17011c str r1, [r0, #0xc] */
/* @0x170120 stm r0, {r1, r3} */
/* @0x170124 ldr r0, [sp, #0x8] */
/* @0x170128 beq 0x17013c <_Z22F_CameraGetBeginScriptR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x17012c ldr r0, [pc, #0x44] */
/* @0x170130 pop {r4, lr} */
/* @0x170134 add r0, pc, r0 */
/* @0x170138 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x17013c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x170140 ldr r3, [pc, #0x34] */
/* @0x170144 mov r1, r0 */
/* @0x170148 ldr r0, [pc, r3] */
/* @0x17014c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170150 cmp r0, #0 */
/* @0x170154 popeq {r4, pc} */
/* @0x170158 bl 0x16d344 <_ZN7CCamera14GetBeginScriptEv> */
/* @0x17015c vmov s15, r0 */
/* @0x170160 vcvt.f64.s32 d7, s15 */
/* @0x170164 vmov r0, r1, d7 */
/* @0x170168 vmov r2, s14 */
/* @0x17016c mov r3, r1 */
/* @0x170170 stm r4, {r2, r3} */
/* @0x170174 pop {r4, pc} */
/* @0x170178 ldrsheq r10, [sp], -r4 */
/* @0x17017c eoreq sp, r7, r12, lsr #22 */

/* ── FUNC 0x170180 · F_CameraGetEndScript(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x170180 cmp r3, #1 */
/* @0x170184 mov r3, #0 */
/* @0x170188 push {r4, lr} */
/* @0x17018c mov r1, r3 */
/* @0x170190 mov r4, r0 */
/* @0x170194 movt r3, #0xbff0 */
/* @0x170198 str r1, [r0, #0xc] */
/* @0x17019c stm r0, {r1, r3} */
/* @0x1701a0 ldr r0, [sp, #0x8] */
/* @0x1701a4 beq 0x1701b8 <_Z20F_CameraGetEndScriptR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1701a8 ldr r0, [pc, #0x44] */
/* @0x1701ac pop {r4, lr} */
/* @0x1701b0 add r0, pc, r0 */
/* @0x1701b4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1701b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1701bc ldr r3, [pc, #0x34] */
/* @0x1701c0 mov r1, r0 */
/* @0x1701c4 ldr r0, [pc, r3] */
/* @0x1701c8 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1701cc cmp r0, #0 */
/* @0x1701d0 popeq {r4, pc} */
/* @0x1701d4 bl 0x16d354 <_ZN7CCamera12GetEndScriptEv> */
/* @0x1701d8 vmov s15, r0 */
/* @0x1701dc vcvt.f64.s32 d7, s15 */
/* @0x1701e0 vmov r0, r1, d7 */
/* @0x1701e4 vmov r2, s14 */
/* @0x1701e8 mov r3, r1 */
/* @0x1701ec stm r4, {r2, r3} */
/* @0x1701f0 pop {r4, pc} */
/* @0x1701f4 ldrheq r10, [sp], -r0 */
/* @0x1701f8 .word 0x0027dab0 */

/* ── FUNC 0x1701fc · F_CameraGetViewX(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1701fc cmp r3, #1 */
/* @0x170200 mov r3, #0 */
/* @0x170204 push {r4, lr} */
/* @0x170208 mov r1, r3 */
/* @0x17020c mov r4, r0 */
/* @0x170210 movt r3, #0xbff0 */
/* @0x170214 str r1, [r0, #0xc] */
/* @0x170218 stm r0, {r1, r3} */
/* @0x17021c ldr r0, [sp, #0x8] */
/* @0x170220 beq 0x170234 <_Z16F_CameraGetViewXR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x170224 ldr r0, [pc, #0x44] */
/* @0x170228 pop {r4, lr} */
/* @0x17022c add r0, pc, r0 */
/* @0x170230 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x170234 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x170238 ldr r3, [pc, #0x34] */
/* @0x17023c mov r1, r0 */
/* @0x170240 ldr r0, [pc, r3] */
/* @0x170244 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170248 cmp r0, #0 */
/* @0x17024c popeq {r4, pc} */
/* @0x170250 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv> */
/* @0x170254 vmov s15, r0 */
/* @0x170258 vcvt.f64.f32 d7, s15 */
/* @0x17025c vmov r0, r1, d7 */
/* @0x170260 vmov r2, s14 */
/* @0x170264 mov r3, r1 */
/* @0x170268 stm r4, {r2, r3} */
/* @0x17026c pop {r4, pc} */
/* @0x170270 andseq r10, sp, r8, ror #30 */
/* @0x170274 eoreq sp, r7, r4, lsr r10 */

/* ── FUNC 0x170278 · F_CameraGetViewY(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x170278 cmp r3, #1 */
/* @0x17027c mov r3, #0 */
/* @0x170280 push {r4, lr} */
/* @0x170284 mov r1, r3 */
/* @0x170288 mov r4, r0 */
/* @0x17028c movt r3, #0xbff0 */
/* @0x170290 str r1, [r0, #0xc] */
/* @0x170294 stm r0, {r1, r3} */
/* @0x170298 ldr r0, [sp, #0x8] */
/* @0x17029c beq 0x1702b0 <_Z16F_CameraGetViewYR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1702a0 ldr r0, [pc, #0x44] */
/* @0x1702a4 pop {r4, lr} */
/* @0x1702a8 add r0, pc, r0 */
/* @0x1702ac b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1702b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1702b4 ldr r3, [pc, #0x34] */
/* @0x1702b8 mov r1, r0 */
/* @0x1702bc ldr r0, [pc, r3] */
/* @0x1702c0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1702c4 cmp r0, #0 */
/* @0x1702c8 popeq {r4, pc} */
/* @0x1702cc bl 0x16d2b4 <_ZN7CCamera8GetViewYEv> */
/* @0x1702d0 vmov s15, r0 */
/* @0x1702d4 vcvt.f64.f32 d7, s15 */
/* @0x1702d8 vmov r0, r1, d7 */
/* @0x1702dc vmov r2, s14 */
/* @0x1702e0 mov r3, r1 */
/* @0x1702e4 stm r4, {r2, r3} */
/* @0x1702e8 pop {r4, pc} */
/* @0x1702ec andseq r10, sp, r12, lsl pc */
/* @0x1702f0 .word 0x0027d9b8 */

/* ── FUNC 0x1702f4 · F_CameraGetViewWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1702f4 cmp r3, #1 */
/* @0x1702f8 mov r3, #0 */
/* @0x1702fc push {r4, lr} */
/* @0x170300 mov r1, r3 */
/* @0x170304 mov r4, r0 */
/* @0x170308 movt r3, #0xbff0 */
/* @0x17030c str r1, [r0, #0xc] */
/* @0x170310 stm r0, {r1, r3} */
/* @0x170314 ldr r0, [sp, #0x8] */
/* @0x170318 beq 0x17032c <_Z20F_CameraGetViewWidthR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x17031c ldr r0, [pc, #0x44] */
/* @0x170320 pop {r4, lr} */
/* @0x170324 add r0, pc, r0 */
/* @0x170328 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x17032c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x170330 ldr r3, [pc, #0x34] */
/* @0x170334 mov r1, r0 */
/* @0x170338 ldr r0, [pc, r3] */
/* @0x17033c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170340 cmp r0, #0 */
/* @0x170344 popeq {r4, pc} */
/* @0x170348 bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv> */
/* @0x17034c vmov s15, r0 */
/* @0x170350 vcvt.f64.f32 d7, s15 */
/* @0x170354 vmov r0, r1, d7 */
/* @0x170358 vmov r2, s14 */
/* @0x17035c mov r3, r1 */
/* @0x170360 stm r4, {r2, r3} */
/* @0x170364 pop {r4, pc} */
/* @0x170368 ldrsbeq r10, [sp], -r0 */
/* @0x17036c eoreq sp, r7, r12, lsr r9 */

/* ── FUNC 0x170370 · F_CameraGetViewHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x170370 cmp r3, #1 */
/* @0x170374 mov r3, #0 */
/* @0x170378 push {r4, lr} */
/* @0x17037c mov r1, r3 */
/* @0x170380 mov r4, r0 */
/* @0x170384 movt r3, #0xbff0 */
/* @0x170388 str r1, [r0, #0xc] */
/* @0x17038c stm r0, {r1, r3} */
/* @0x170390 ldr r0, [sp, #0x8] */
/* @0x170394 beq 0x1703a8 <_Z21F_CameraGetViewHeightR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x170398 ldr r0, [pc, #0x44] */
/* @0x17039c pop {r4, lr} */
/* @0x1703a0 add r0, pc, r0 */
/* @0x1703a4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1703a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1703ac ldr r3, [pc, #0x34] */
/* @0x1703b0 mov r1, r0 */
/* @0x1703b4 ldr r0, [pc, r3] */
/* @0x1703b8 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1703bc cmp r0, #0 */
/* @0x1703c0 popeq {r4, pc} */
/* @0x1703c4 bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv> */
/* @0x1703c8 vmov s15, r0 */
/* @0x1703cc vcvt.f64.f32 d7, s15 */
/* @0x1703d0 vmov r0, r1, d7 */
/* @0x1703d4 vmov r2, s14 */
/* @0x1703d8 mov r3, r1 */
/* @0x1703dc stm r4, {r2, r3} */
/* @0x1703e0 pop {r4, pc} */
/* @0x1703e4 andseq r10, sp, r8, lsl #29 */
/* @0x1703e8 eoreq sp, r7, r0, asr #17 */

/* ── FUNC 0x1703ec · F_CameraGetViewSpeedX(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1703ec cmp r3, #1 */
/* @0x1703f0 mov r3, #0 */
/* @0x1703f4 push {r4, lr} */
/* @0x1703f8 mov r1, r3 */
/* @0x1703fc mov r4, r0 */
/* @0x170400 movt r3, #0xbff0 */
/* @0x170404 str r1, [r0, #0xc] */
/* @0x170408 stm r0, {r1, r3} */
/* @0x17040c ldr r0, [sp, #0x8] */
/* @0x170410 beq 0x170424 <_Z21F_CameraGetViewSpeedXR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x170414 ldr r0, [pc, #0x44] */
/* @0x170418 pop {r4, lr} */
/* @0x17041c add r0, pc, r0 */
/* @0x170420 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x170424 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x170428 ldr r3, [pc, #0x34] */
/* @0x17042c mov r1, r0 */
/* @0x170430 ldr r0, [pc, r3] */
/* @0x170434 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170438 cmp r0, #0 */
/* @0x17043c popeq {r4, pc} */
/* @0x170440 bl 0x16d2e4 <_ZN7CCamera13GetViewSpeedXEv> */
/* @0x170444 vmov s15, r0 */
/* @0x170448 vcvt.f64.f32 d7, s15 */
/* @0x17044c vmov r0, r1, d7 */
/* @0x170450 vmov r2, s14 */
/* @0x170454 mov r3, r1 */
/* @0x170458 stm r4, {r2, r3} */
/* @0x17045c pop {r4, pc} */
/* @0x170460 andseq r10, sp, r4, asr #28 */
/* @0x170464 eoreq sp, r7, r4, asr #16 */

/* ── FUNC 0x170468 · F_CameraGetViewSpeedY(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x170468 cmp r3, #1 */
/* @0x17046c mov r3, #0 */
/* @0x170470 push {r4, lr} */
/* @0x170474 mov r1, r3 */
/* @0x170478 mov r4, r0 */
/* @0x17047c movt r3, #0xbff0 */
/* @0x170480 str r1, [r0, #0xc] */
/* @0x170484 stm r0, {r1, r3} */
/* @0x170488 ldr r0, [sp, #0x8] */
/* @0x17048c beq 0x1704a0 <_Z21F_CameraGetViewSpeedYR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x170490 ldr r0, [pc, #0x44] */
/* @0x170494 pop {r4, lr} */
/* @0x170498 add r0, pc, r0 */
/* @0x17049c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1704a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1704a4 ldr r3, [pc, #0x34] */
/* @0x1704a8 mov r1, r0 */
/* @0x1704ac ldr r0, [pc, r3] */
/* @0x1704b0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1704b4 cmp r0, #0 */
/* @0x1704b8 popeq {r4, pc} */
/* @0x1704bc bl 0x16d2f4 <_ZN7CCamera13GetViewSpeedYEv> */
/* @0x1704c0 vmov s15, r0 */
/* @0x1704c4 vcvt.f64.f32 d7, s15 */
/* @0x1704c8 vmov r0, r1, d7 */
/* @0x1704cc vmov r2, s14 */
/* @0x1704d0 mov r3, r1 */
/* @0x1704d4 stm r4, {r2, r3} */
/* @0x1704d8 pop {r4, pc} */
/* @0x1704dc andseq r10, sp, r0, lsl #28 */
/* @0x1704e0 eoreq sp, r7, r8, asr #15 */
