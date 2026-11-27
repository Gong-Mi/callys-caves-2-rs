/* libyoyo.so 覆盖卡组 0111
 * 函数 0x1704e4..0x172058，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1704e4 · F_CameraGetViewBorderX(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1704e4 cmp r3, #1 */
/* @0x1704e8 mov r3, #0 */
/* @0x1704ec push {r4, lr} */
/* @0x1704f0 mov r1, r3 */
/* @0x1704f4 mov r4, r0 */
/* @0x1704f8 movt r3, #0xbff0 */
/* @0x1704fc str r1, [r0, #0xc] */
/* @0x170500 stm r0, {r1, r3} */
/* @0x170504 ldr r0, [sp, #0x8] */
/* @0x170508 beq 0x17051c <_Z22F_CameraGetViewBorderXR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x17050c ldr r0, [pc, #0x44] */
/* @0x170510 pop {r4, lr} */
/* @0x170514 add r0, pc, r0 */
/* @0x170518 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x17051c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x170520 ldr r3, [pc, #0x34] */
/* @0x170524 mov r1, r0 */
/* @0x170528 ldr r0, [pc, r3] */
/* @0x17052c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170530 cmp r0, #0 */
/* @0x170534 popeq {r4, pc} */
/* @0x170538 bl 0x16d304 <_ZN7CCamera14GetViewBorderXEv> */
/* @0x17053c vmov s15, r0 */
/* @0x170540 vcvt.f64.f32 d7, s15 */
/* @0x170544 vmov r0, r1, d7 */
/* @0x170548 vmov r2, s14 */
/* @0x17054c mov r3, r1 */
/* @0x170550 stm r4, {r2, r3} */
/* @0x170554 pop {r4, pc} */
/* @0x170558 ldrheq r10, [sp], -r12 */
/* @0x17055c eoreq sp, r7, r12, asr #14 */

/* ── FUNC 0x170560 · F_CameraGetViewBorderY(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x170560 cmp r3, #1 */
/* @0x170564 mov r3, #0 */
/* @0x170568 push {r4, lr} */
/* @0x17056c mov r1, r3 */
/* @0x170570 mov r4, r0 */
/* @0x170574 movt r3, #0xbff0 */
/* @0x170578 str r1, [r0, #0xc] */
/* @0x17057c stm r0, {r1, r3} */
/* @0x170580 ldr r0, [sp, #0x8] */
/* @0x170584 beq 0x170598 <_Z22F_CameraGetViewBorderYR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x170588 ldr r0, [pc, #0x44] */
/* @0x17058c pop {r4, lr} */
/* @0x170590 add r0, pc, r0 */
/* @0x170594 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x170598 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x17059c ldr r3, [pc, #0x34] */
/* @0x1705a0 mov r1, r0 */
/* @0x1705a4 ldr r0, [pc, r3] */
/* @0x1705a8 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1705ac cmp r0, #0 */
/* @0x1705b0 popeq {r4, pc} */
/* @0x1705b4 bl 0x16d314 <_ZN7CCamera14GetViewBorderYEv> */
/* @0x1705b8 vmov s15, r0 */
/* @0x1705bc vcvt.f64.f32 d7, s15 */
/* @0x1705c0 vmov r0, r1, d7 */
/* @0x1705c4 vmov r2, s14 */
/* @0x1705c8 mov r3, r1 */
/* @0x1705cc stm r4, {r2, r3} */
/* @0x1705d0 pop {r4, pc} */
/* @0x1705d4 andseq r10, sp, r8, ror sp */
/* @0x1705d8 .word 0x0027d6d0 */

/* ── FUNC 0x1705dc · F_CameraGetViewAngle(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1705dc cmp r3, #1 */
/* @0x1705e0 mov r3, #0 */
/* @0x1705e4 push {r4, lr} */
/* @0x1705e8 mov r1, r3 */
/* @0x1705ec mov r4, r0 */
/* @0x1705f0 movt r3, #0xbff0 */
/* @0x1705f4 str r1, [r0, #0xc] */
/* @0x1705f8 stm r0, {r1, r3} */
/* @0x1705fc ldr r0, [sp, #0x8] */
/* @0x170600 beq 0x170614 <_Z20F_CameraGetViewAngleR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x170604 ldr r0, [pc, #0x44] */
/* @0x170608 pop {r4, lr} */
/* @0x17060c add r0, pc, r0 */
/* @0x170610 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x170614 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x170618 ldr r3, [pc, #0x34] */
/* @0x17061c mov r1, r0 */
/* @0x170620 ldr r0, [pc, r3] */
/* @0x170624 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170628 cmp r0, #0 */
/* @0x17062c popeq {r4, pc} */
/* @0x170630 bl 0x16d324 <_ZN7CCamera12GetViewAngleEv> */
/* @0x170634 vmov s15, r0 */
/* @0x170638 vcvt.f64.f32 d7, s15 */
/* @0x17063c vmov r0, r1, d7 */
/* @0x170640 vmov r2, s14 */
/* @0x170644 mov r3, r1 */
/* @0x170648 stm r4, {r2, r3} */
/* @0x17064c pop {r4, pc} */
/* @0x170650 andseq r10, sp, r4, lsr sp */
/* @0x170654 eoreq sp, r7, r4, asr r6 */

/* ── FUNC 0x170658 · CCameraManager::CloneCamera(int) · size=368 · insn=92 */
/* @0x170658 push {r4, r5, r6, lr} */
/* @0x17065c sub sp, sp, #128 */
/* @0x170660 mov r4, r0 */
/* @0x170664 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170668 subs r5, r0, #0 */
/* @0x17066c beq 0x1707c0 <_ZN14CCameraManager11CloneCameraEi+0x168> */
/* @0x170670 mov r0, r4 */
/* @0x170674 bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv> */
/* @0x170678 mov r4, r0 */
/* @0x17067c mov r0, r5 */
/* @0x170680 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv> */
/* @0x170684 mov r1, r0 */
/* @0x170688 mov r0, r4 */
/* @0x17068c bl 0x16d29c <_ZN7CCamera8SetViewXEf> */
/* @0x170690 mov r0, r5 */
/* @0x170694 bl 0x16d2b4 <_ZN7CCamera8GetViewYEv> */
/* @0x170698 mov r1, r0 */
/* @0x17069c mov r0, r4 */
/* @0x1706a0 bl 0x16d2ac <_ZN7CCamera8SetViewYEf> */
/* @0x1706a4 mov r0, r5 */
/* @0x1706a8 bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv> */
/* @0x1706ac mov r1, r0 */
/* @0x1706b0 mov r0, r4 */
/* @0x1706b4 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf> */
/* @0x1706b8 mov r0, r5 */
/* @0x1706bc bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv> */
/* @0x1706c0 mov r1, r0 */
/* @0x1706c4 mov r0, r4 */
/* @0x1706c8 bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf> */
/* @0x1706cc mov r0, r5 */
/* @0x1706d0 bl 0x16d2e4 <_ZN7CCamera13GetViewSpeedXEv> */
/* @0x1706d4 mov r1, r0 */
/* @0x1706d8 mov r0, r4 */
/* @0x1706dc bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf> */
/* @0x1706e0 mov r0, r5 */
/* @0x1706e4 bl 0x16d2f4 <_ZN7CCamera13GetViewSpeedYEv> */
/* @0x1706e8 mov r1, r0 */
/* @0x1706ec mov r0, r4 */
/* @0x1706f0 bl 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf> */
/* @0x1706f4 mov r0, r5 */
/* @0x1706f8 bl 0x16d304 <_ZN7CCamera14GetViewBorderXEv> */
/* @0x1706fc mov r1, r0 */
/* @0x170700 mov r0, r4 */
/* @0x170704 bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf> */
/* @0x170708 mov r0, r5 */
/* @0x17070c bl 0x16d314 <_ZN7CCamera14GetViewBorderYEv> */
/* @0x170710 mov r1, r0 */
/* @0x170714 mov r0, r4 */
/* @0x170718 bl 0x16d30c <_ZN7CCamera14SetViewBorderYEf> */
/* @0x17071c mov r0, r5 */
/* @0x170720 bl 0x16d324 <_ZN7CCamera12GetViewAngleEv> */
/* @0x170724 mov r1, r0 */
/* @0x170728 mov r0, r4 */
/* @0x17072c bl 0x16d31c <_ZN7CCamera12SetViewAngleEf> */
/* @0x170730 mov r0, r5 */
/* @0x170734 bl 0x16d334 <_ZN7CCamera17GetTargetInstanceEv> */
/* @0x170738 mov r1, r0 */
/* @0x17073c mov r0, r4 */
/* @0x170740 bl 0x16d32c <_ZN7CCamera17SetTargetInstanceEi> */
/* @0x170744 mov r0, r5 */
/* @0x170748 bl 0x16d344 <_ZN7CCamera14GetBeginScriptEv> */
/* @0x17074c mov r1, r0 */
/* @0x170750 mov r0, r4 */
/* @0x170754 bl 0x16d33c <_ZN7CCamera14SetBeginScriptEi> */
/* @0x170758 mov r0, r5 */
/* @0x17075c bl 0x16d354 <_ZN7CCamera12GetEndScriptEv> */
/* @0x170760 mov r1, r0 */
/* @0x170764 mov r0, r4 */
/* @0x170768 bl 0x16d34c <_ZN7CCamera12SetEndScriptEi> */
/* @0x17076c mov r0, r5 */
/* @0x170770 bl 0x16d364 <_ZN7CCamera15GetUpdateScriptEv> */
/* @0x170774 mov r1, r0 */
/* @0x170778 mov r0, r4 */
/* @0x17077c bl 0x16d35c <_ZN7CCamera15SetUpdateScriptEi> */
/* @0x170780 mov r1, r5 */
/* @0x170784 mov r0, sp */
/* @0x170788 bl 0x16d170 <_ZN7CCamera10GetViewMatEv> */
/* @0x17078c mov r1, r5 */
/* @0x170790 add r5, sp, #64 */
/* @0x170794 mov r0, r5 */
/* @0x170798 bl 0x16d134 <_ZN7CCamera10GetProjMatEv> */
/* @0x17079c mov r0, r4 */
/* @0x1707a0 mov r1, sp */
/* @0x1707a4 bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix> */
/* @0x1707a8 mov r0, r4 */
/* @0x1707ac mov r1, r5 */
/* @0x1707b0 bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix> */
/* @0x1707b4 mov r0, r4 */
/* @0x1707b8 add sp, sp, #128 */
/* @0x1707bc pop {r4, r5, r6, pc} */
/* @0x1707c0 mov r0, r5 */
/* @0x1707c4 b 0x1707b8 <_ZN14CCameraManager11CloneCameraEi+0x160> */

/* ── FUNC 0x1707c8 · CCameraManager::SetActiveCamera(int) · size=44 · insn=11 */
/* @0x1707c8 cmn r1, #1 */
/* @0x1707cc push {r4, lr} */
/* @0x1707d0 moveq r3, #0 */
/* @0x1707d4 streq r3, [r0, #0x4] */
/* @0x1707d8 mov r4, r0 */
/* @0x1707dc bl 0x16f234 <_ZN14CCameraManager16FindCameraInListEi> */
/* @0x1707e0 cmn r0, #1 */
/* @0x1707e4 ldrne r3, [r4, #0xc] */
/* @0x1707e8 ldrne r3, [r3, r0, lsl #2] */
/* @0x1707ec strne r3, [r4, #0x4] */
/* @0x1707f0 pop {r4, pc} */

/* ── FUNC 0x1707f4 · F_CameraDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1707f4 cmp r3, #1 */
/* @0x1707f8 push {r3, r4, r5, lr} */
/* @0x1707fc mov r3, #0 */
/* @0x170800 mov r1, r3 */
/* @0x170804 movt r3, #0xbff0 */
/* @0x170808 str r1, [r0, #0xc] */
/* @0x17080c stm r0, {r1, r3} */
/* @0x170810 ldr r0, [sp, #0x10] */
/* @0x170814 beq 0x170828 <_Z15F_CameraDestroyR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x170818 ldr r0, [pc, #0x60] */
/* @0x17081c pop {r3, r4, r5, lr} */
/* @0x170820 add r0, pc, r0 */
/* @0x170824 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x170828 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x17082c ldr r4, [pc, #0x50] */
/* @0x170830 ldr r4, [pc, r4] */
/* @0x170834 mov r1, r0 */
/* @0x170838 mov r0, r4 */
/* @0x17083c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x170840 subs r5, r0, #0 */
/* @0x170844 popeq {r3, r4, r5, pc} */
/* @0x170848 mov r0, r4 */
/* @0x17084c bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x170850 cmp r5, r0 */
/* @0x170854 beq 0x170870 <_Z15F_CameraDestroyR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x170858 mov r0, r5 */
/* @0x17085c bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x170860 mov r1, r0 */
/* @0x170864 mov r0, r4 */
/* @0x170868 pop {r3, r4, r5, lr} */
/* @0x17086c b 0x16f2cc <_ZN14CCameraManager13DestroyCameraEi> */
/* @0x170870 mov r0, r4 */
/* @0x170874 mvn r1, #0 */
/* @0x170878 bl 0x1707c8 <_ZN14CCameraManager15SetActiveCameraEi> */
/* @0x17087c b 0x170858 <_Z15F_CameraDestroyR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x170880 andseq r10, sp, r4, asr r11 */
/* @0x170884 eoreq sp, r7, r4, asr #8 */

/* ── FUNC 0x170888 · CCamera::ExecuteScript(int) · size=664 · insn=166 */
/* @0x170888 cmn r1, #1 */
/* @0x17088c ldr r2, [pc, #0x278] */
/* @0x170890 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x170894 mov r12, r1 */
/* @0x170898 sub sp, sp, #36 */
/* @0x17089c add r2, pc, r2 */
/* @0x1708a0 beq 0x170918 <_ZN7CCamera13ExecuteScriptEi+0x90> */
/* @0x1708a4 ldr r4, [pc, #0x264] */
/* @0x1708a8 mov r1, #0 */
/* @0x1708ac ldr r0, [r0] */
/* @0x1708b0 str r1, [sp, #0x10] */
/* @0x1708b4 ldr r3, [pc, #0x258] */
/* @0x1708b8 ldr r5, [r2, r4] */
/* @0x1708bc ldr r7, [r5] */
/* @0x1708c0 str r0, [r5] */
/* @0x1708c4 ldr r3, [r2, r3] */
/* @0x1708c8 ldrb r3, [r3] */
/* @0x1708cc cmp r3, r1 */
/* @0x1708d0 bne 0x170920 <_ZN7CCamera13ExecuteScriptEi+0x98> */
/* @0x1708d4 ldr r1, [pc, #0x23c] */
/* @0x1708d8 ldr r2, [r2, r1] */
/* @0x1708dc ldr r1, [r2, #0x8] */
/* @0x1708e0 cmp r1, #0 */
/* @0x1708e4 beq 0x170900 <_ZN7CCamera13ExecuteScriptEi+0x78> */
/* @0x1708e8 mov r0, r12 */
/* @0x1708ec str r3, [sp, #0x4] */
/* @0x1708f0 add r12, sp, #16 */
/* @0x1708f4 mov r2, r1 */
/* @0x1708f8 str r12, [sp] */
/* @0x1708fc bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x170900 ldr r2, [sp, #0x1c] */
/* @0x170904 sub r3, r2, #1 */
/* @0x170908 bic r3, r3, #-16777216 */
/* @0x17090c bics r4, r3, #3 */
/* @0x170910 beq 0x17094c <_ZN7CCamera13ExecuteScriptEi+0xc4> */
/* @0x170914 str r7, [r5] */
/* @0x170918 add sp, sp, #36 */
/* @0x17091c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x170920 ldr lr, [pc, #0x1f4] */
/* @0x170924 mov r3, r1 */
/* @0x170928 mov r0, r12 */
/* @0x17092c ldr r2, [r2, lr] */
/* @0x170930 str r1, [sp, #0x4] */
/* @0x170934 add r1, sp, #16 */
/* @0x170938 str r1, [sp] */
/* @0x17093c ldr r1, [r2] */
/* @0x170940 mov r2, r1 */
/* @0x170944 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x170948 b 0x170900 <_ZN7CCamera13ExecuteScriptEi+0x78> */
/* @0x17094c bic r2, r2, #-16777216 */
/* @0x170950 cmp r2, #2 */
/* @0x170954 beq 0x170994 <_ZN7CCamera13ExecuteScriptEi+0x10c> */
/* @0x170958 cmp r2, #3 */
/* @0x17095c beq 0x170a3c <_ZN7CCamera13ExecuteScriptEi+0x1b4> */
/* @0x170960 cmp r2, #1 */
/* @0x170964 bne 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c> */
/* @0x170968 ldr r4, [sp, #0x10] */
/* @0x17096c cmp r4, #0 */
/* @0x170970 beq 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c> */
/* @0x170974 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x170978 ldr r6, [r4, #0x4] */
/* @0x17097c sub r6, r6, #1 */
/* @0x170980 str r6, [r4, #0x4] */
/* @0x170984 cmp r6, #0 */
/* @0x170988 beq 0x170aa8 <_ZN7CCamera13ExecuteScriptEi+0x220> */
/* @0x17098c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x170990 b 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c> */
/* @0x170994 ldr r9, [sp, #0x10] */
/* @0x170998 cmp r9, #0 */
/* @0x17099c beq 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c> */
/* @0x1709a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1709a4 ldr r3, [r9] */
/* @0x1709a8 ldr r1, [r9, #0x8] */
/* @0x1709ac add r2, sp, #16 */
/* @0x1709b0 sub r3, r3, #1 */
/* @0x1709b4 str r3, [r9] */
/* @0x1709b8 cmp r1, r2 */
/* @0x1709bc streq r4, [r9, #0x8] */
/* @0x1709c0 cmp r3, #0 */
/* @0x1709c4 bgt 0x17098c <_ZN7CCamera13ExecuteScriptEi+0x104> */
/* @0x1709c8 ldr r3, [r9, #0x10] */
/* @0x1709cc cmp r3, #0 */
/* @0x1709d0 movgt r8, #0 */
/* @0x1709d4 movgt r10, #5 */
/* @0x1709d8 movgt r6, r8 */
/* @0x1709dc ble 0x170a88 <_ZN7CCamera13ExecuteScriptEi+0x200> */
/* @0x1709e0 ldr r3, [r9, #0x4] */
/* @0x1709e4 add r2, r3, r8, lsl #3 */
/* @0x1709e8 str r2, [sp, #0xc] */
/* @0x1709ec ldr r11, [r3, r8, lsl #3] */
/* @0x1709f0 ldr r4, [r2, #0x4] */
/* @0x1709f4 add r11, r4, r11, lsl #4 */
/* @0x1709f8 cmp r4, r11 */
/* @0x1709fc blo 0x170a18 <_ZN7CCamera13ExecuteScriptEi+0x190> */
/* @0x170a00 b 0x170ae0 <_ZN7CCamera13ExecuteScriptEi+0x258> */
/* @0x170a04 str r6, [r4, #0x8] */
/* @0x170a08 str r10, [r4, #0xc] */
/* @0x170a0c str r6, [r4], #16 */
/* @0x170a10 cmp r11, r4 */
/* @0x170a14 bls 0x170a64 <_ZN7CCamera13ExecuteScriptEi+0x1dc> */
/* @0x170a18 ldr r3, [r4, #0xc] */
/* @0x170a1c sub r3, r3, #1 */
/* @0x170a20 bic r3, r3, #-16777216 */
/* @0x170a24 bic r3, r3, #3 */
/* @0x170a28 cmp r3, #0 */
/* @0x170a2c bne 0x170a04 <_ZN7CCamera13ExecuteScriptEi+0x17c> */
/* @0x170a30 mov r0, r4 */
/* @0x170a34 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x170a38 b 0x170a04 <_ZN7CCamera13ExecuteScriptEi+0x17c> */
/* @0x170a3c ldr r3, [sp, #0x18] */
/* @0x170a40 tst r3, #8 */
/* @0x170a44 beq 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c> */
/* @0x170a48 ldr r0, [sp, #0x10] */
/* @0x170a4c cmp r0, #0 */
/* @0x170a50 beq 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c> */
/* @0x170a54 ldr r3, [r0] */
/* @0x170a58 ldr r3, [r3, #0x4] */
/* @0x170a5c blx r3 */
/* @0x170a60 b 0x170914 <_ZN7CCamera13ExecuteScriptEi+0x8c> */
/* @0x170a64 ldr r3, [sp, #0xc] */
/* @0x170a68 ldr r0, [r3, #0x4] */
/* @0x170a6c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x170a70 ldr r3, [r9, #0x10] */
/* @0x170a74 add r8, r8, #1 */
/* @0x170a78 ldr r2, [sp, #0xc] */
/* @0x170a7c cmp r8, r3 */
/* @0x170a80 str r6, [r2, #0x4] */
/* @0x170a84 blt 0x1709e0 <_ZN7CCamera13ExecuteScriptEi+0x158> */
/* @0x170a88 ldr r0, [r9, #0x4] */
/* @0x170a8c mov r4, #0 */
/* @0x170a90 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x170a94 str r4, [r9, #0x4] */
/* @0x170a98 mov r0, r9 */
/* @0x170a9c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x170aa0 str r4, [sp, #0x10] */
/* @0x170aa4 b 0x17098c <_ZN7CCamera13ExecuteScriptEi+0x104> */
/* @0x170aa8 ldr r0, [r4] */
/* @0x170aac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x170ab0 str r6, [r4] */
/* @0x170ab4 str r6, [r4, #0x8] */
/* @0x170ab8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x170abc ldr r6, [r4, #0x4] */
/* @0x170ac0 sub r6, r6, #1 */
/* @0x170ac4 str r6, [r4, #0x4] */
/* @0x170ac8 cmp r6, #0 */
/* @0x170acc beq 0x170ae8 <_ZN7CCamera13ExecuteScriptEi+0x260> */
/* @0x170ad0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x170ad4 mov r0, r4 */
/* @0x170ad8 bl 0x27d1d0 <_ZdlPv> */
/* @0x170adc b 0x17098c <_ZN7CCamera13ExecuteScriptEi+0x104> */
/* @0x170ae0 mov r0, r4 */
/* @0x170ae4 b 0x170a6c <_ZN7CCamera13ExecuteScriptEi+0x1e4> */
/* @0x170ae8 ldr r0, [r4] */
/* @0x170aec bl 0xcef90 <_Z6YYFreePKv> */
/* @0x170af0 mov r0, r4 */
/* @0x170af4 str r6, [r4] */
/* @0x170af8 str r6, [r4, #0x8] */
/* @0x170afc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x170b00 mov r0, r4 */
/* @0x170b04 bl 0x27d1d0 <_ZdlPv> */
/* @0x170b08 b 0x170ad0 <_ZN7CCamera13ExecuteScriptEi+0x248> */
/* @0x170b0c .word 0x002813b4 */
/* @0x170b10 .word 0xffffc168 */
/* @0x170b14 .word 0xffffbf68 */
/* @0x170b18 .word 0xffffc024 */
/* @0x170b1c .word 0xffffbf64 */

/* ── FUNC 0x170b20 · CCamera::Begin() · size=8 · insn=2 */
/* @0x170b20 ldr r1, [r0, #0x1ac] */
/* @0x170b24 b 0x170888 <_ZN7CCamera13ExecuteScriptEi> */

/* ── FUNC 0x170b28 · CCamera::End() · size=8 · insn=2 */
/* @0x170b28 ldr r1, [r0, #0x1b0] */
/* @0x170b2c b 0x170888 <_ZN7CCamera13ExecuteScriptEi> */

/* ── FUNC 0x170b30 · CCamera::CameraUpdate() · size=920 · insn=230 */
/* @0x170b30 ldr r1, [r0, #0x1b4] */
/* @0x170b34 push {r3, r4, r5, lr} */
/* @0x170b38 vpush {d8, d9, d10, d11} */
/* @0x170b3c cmn r1, #1 */
/* @0x170b40 mov r5, r0 */
/* @0x170b44 bne 0x170ddc <_ZN7CCamera12CameraUpdateEv+0x2ac> */
/* @0x170b48 ldr r2, [r0, #0x1a8] */
/* @0x170b4c cmp r2, #0 */
/* @0x170b50 blt 0x170e50 <_ZN7CCamera12CameraUpdateEv+0x320> */
/* @0x170b54 movw r3, #0x869f */
/* @0x170b58 movt r3, #0x1 */
/* @0x170b5c cmp r2, r3 */
/* @0x170b60 bgt 0x170de8 <_ZN7CCamera12CameraUpdateEv+0x2b8> */
/* @0x170b64 ldr r3, [pc, #0x350] */
/* @0x170b68 ldr r3, [pc, r3] */
/* @0x170b6c ldr r3, [r3] */
/* @0x170b70 ldr r1, [r3, #0x4] */
/* @0x170b74 ldr r3, [r3] */
/* @0x170b78 and r1, r2, r1 */
/* @0x170b7c ldr r3, [r3, r1, lsl #3] */
/* @0x170b80 cmp r3, #0 */
/* @0x170b84 bne 0x170b98 <_ZN7CCamera12CameraUpdateEv+0x68> */
/* @0x170b88 b 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170b8c ldr r3, [r3, #0x4] */
/* @0x170b90 cmp r3, #0 */
/* @0x170b94 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170b98 ldr r1, [r3, #0x8] */
/* @0x170b9c cmp r2, r1 */
/* @0x170ba0 bne 0x170b8c <_ZN7CCamera12CameraUpdateEv+0x5c> */
/* @0x170ba4 ldr r3, [r3, #0xc] */
/* @0x170ba8 cmp r3, #0 */
/* @0x170bac ldrne r3, [r3, #0xd0] */
/* @0x170bb0 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170bb4 cmp r3, #0 */
/* @0x170bb8 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170bbc ldr r2, [r3, #0x8] */
/* @0x170bc0 cmp r2, #0 */
/* @0x170bc4 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170bc8 ldr r4, [r3, #0x8] */
/* @0x170bcc ldr r3, [r3] */
/* @0x170bd0 ldrb r2, [r4, #0x68] */
/* @0x170bd4 cmp r2, #0 */
/* @0x170bd8 bne 0x170bb4 <_ZN7CCamera12CameraUpdateEv+0x84> */
/* @0x170bdc ldrb r2, [r4, #0x69] */
/* @0x170be0 cmp r2, #0 */
/* @0x170be4 bne 0x170bb4 <_ZN7CCamera12CameraUpdateEv+0x84> */
/* @0x170be8 vmov.f32 s15, #5.000000e-01 */
/* @0x170bec ldrb r3, [r4, #0x64] */
/* @0x170bf0 vldr s19, [r5, #396] */
/* @0x170bf4 vldr s18, [r5, #400] */
/* @0x170bf8 cmp r3, #0 */
/* @0x170bfc vldr s16, [r5, #388] */
/* @0x170c00 vldr s23, [r5, #392] */
/* @0x170c04 vmul.f32 s21, s19, s15 */
/* @0x170c08 vmul.f32 s20, s18, s15 */
/* @0x170c0c bne 0x170ea0 <_ZN7CCamera12CameraUpdateEv+0x370> */
/* @0x170c10 ldr r0, [r4, #0xb4] */
/* @0x170c14 bl 0xb6910 <floorf@plt> */
/* @0x170c18 vmov s22, r0 */
/* @0x170c1c ldr r0, [r4, #0xb8] */
/* @0x170c20 bl 0xb6910 <floorf@plt> */
/* @0x170c24 vldr s14, [r5, #412] */
/* @0x170c28 vadd.f32 s15, s14, s14 */
/* @0x170c2c vcmpe.f32 s15, s19 */
/* @0x170c30 vmrs APSR_nzcv, fpscr */
/* @0x170c34 vsubge.f32 s17, s22, s21 */
/* @0x170c38 vmov s13, r0 */
/* @0x170c3c bge 0x170c6c <_ZN7CCamera12CameraUpdateEv+0x13c> */
/* @0x170c40 vsub.f32 s17, s22, s14 */
/* @0x170c44 vldr s15, [r5, #388] */
/* @0x170c48 vcmpe.f32 s17, s15 */
/* @0x170c4c vmrs APSR_nzcv, fpscr */
/* @0x170c50 bmi 0x170c6c <_ZN7CCamera12CameraUpdateEv+0x13c> */
/* @0x170c54 vadd.f32 s14, s22, s14 */
/* @0x170c58 vadd.f32 s15, s15, s19 */
/* @0x170c5c vcmpe.f32 s14, s15 */
/* @0x170c60 vmrs APSR_nzcv, fpscr */
/* @0x170c64 vsubgt.f32 s17, s14, s19 */
/* @0x170c68 vmovle.f32 s17, s16 */
/* @0x170c6c vldr s15, [r5, #416] */
/* @0x170c70 vadd.f32 s14, s15, s15 */
/* @0x170c74 vcmpe.f32 s18, s14 */
/* @0x170c78 vmrs APSR_nzcv, fpscr */
/* @0x170c7c vsubls.f32 s16, s13, s20 */
/* @0x170c80 bls 0x170cb0 <_ZN7CCamera12CameraUpdateEv+0x180> */
/* @0x170c84 vldr s14, [r5, #392] */
/* @0x170c88 vsub.f32 s16, s13, s15 */
/* @0x170c8c vcmpe.f32 s16, s14 */
/* @0x170c90 vmrs APSR_nzcv, fpscr */
/* @0x170c94 bmi 0x170cb0 <_ZN7CCamera12CameraUpdateEv+0x180> */
/* @0x170c98 vadd.f32 s15, s13, s15 */
/* @0x170c9c vadd.f32 s14, s18, s14 */
/* @0x170ca0 vcmpe.f32 s15, s14 */
/* @0x170ca4 vmrs APSR_nzcv, fpscr */
/* @0x170ca8 vsubgt.f32 s16, s15, s18 */
/* @0x170cac vmovle.f32 s16, s23 */
/* @0x170cb0 vldr s15, [pc, #512] */
/* @0x170cb4 ldr r3, [pc, #0x204] */
/* @0x170cb8 vcmp.f32 s17, #0 */
/* @0x170cbc ldr r3, [pc, r3] */
/* @0x170cc0 ldr r3, [r3] */
/* @0x170cc4 vldr s13, [r3, #16] */
/* @0x170cc8 vmrs APSR_nzcv, fpscr */
/* @0x170ccc vmovmi.f32 s17, s15 */
/* @0x170cd0 vadd.f32 s15, s17, s19 */
/* @0x170cd4 vcvt.f32.s32 s14, s13 */
/* @0x170cd8 vcmpe.f32 s15, s14 */
/* @0x170cdc vldr s15, [pc, #468] */
/* @0x170ce0 vmrs APSR_nzcv, fpscr */
/* @0x170ce4 vcmp.f32 s16, s15 */
/* @0x170ce8 vsubgt.f32 s17, s14, s19 */
/* @0x170cec vmrs APSR_nzcv, fpscr */
/* @0x170cf0 vldr s14, [r3, #20] */
/* @0x170cf4 vmovmi.f32 s16, s15 */
/* @0x170cf8 vadd.f32 s15, s16, s18 */
/* @0x170cfc vcvt.f32.s32 s14, s14 */
/* @0x170d00 vcmpe.f32 s15, s14 */
/* @0x170d04 vmrs APSR_nzcv, fpscr */
/* @0x170d08 vsubgt.f32 s16, s14, s18 */
/* @0x170d0c vldr s14, [r5, #404] */
/* @0x170d10 vcmpe.f32 s14, #0 */
/* @0x170d14 vmrs APSR_nzcv, fpscr */
/* @0x170d18 blt 0x170d58 <_ZN7CCamera12CameraUpdateEv+0x228> */
/* @0x170d1c vldr s15, [r5, #388] */
/* @0x170d20 vcmpe.f32 s17, s15 */
/* @0x170d24 vmrs APSR_nzcv, fpscr */
/* @0x170d28 bpl 0x170d3c <_ZN7CCamera12CameraUpdateEv+0x20c> */
/* @0x170d2c vsub.f32 s13, s15, s17 */
/* @0x170d30 vcmpe.f32 s14, s13 */
/* @0x170d34 vmrs APSR_nzcv, fpscr */
/* @0x170d38 vsubmi.f32 s17, s15, s14 */
/* @0x170d3c vcmpe.f32 s17, s15 */
/* @0x170d40 vmrs APSR_nzcv, fpscr */
/* @0x170d44 ble 0x170d58 <_ZN7CCamera12CameraUpdateEv+0x228> */
/* @0x170d48 vsub.f32 s13, s17, s15 */
/* @0x170d4c vcmpe.f32 s14, s13 */
/* @0x170d50 vmrs APSR_nzcv, fpscr */
/* @0x170d54 vaddmi.f32 s17, s14, s15 */
/* @0x170d58 vldr s14, [r5, #408] */
/* @0x170d5c vcmpe.f32 s14, #0 */
/* @0x170d60 vmrs APSR_nzcv, fpscr */
/* @0x170d64 blt 0x170da4 <_ZN7CCamera12CameraUpdateEv+0x274> */
/* @0x170d68 vldr s15, [r5, #392] */
/* @0x170d6c vcmpe.f32 s16, s15 */
/* @0x170d70 vmrs APSR_nzcv, fpscr */
/* @0x170d74 bpl 0x170d88 <_ZN7CCamera12CameraUpdateEv+0x258> */
/* @0x170d78 vsub.f32 s13, s15, s16 */
/* @0x170d7c vcmpe.f32 s14, s13 */
/* @0x170d80 vmrs APSR_nzcv, fpscr */
/* @0x170d84 vsubmi.f32 s16, s15, s14 */
/* @0x170d88 vcmpe.f32 s16, s15 */
/* @0x170d8c vmrs APSR_nzcv, fpscr */
/* @0x170d90 ble 0x170da4 <_ZN7CCamera12CameraUpdateEv+0x274> */
/* @0x170d94 vsub.f32 s13, s16, s15 */
/* @0x170d98 vcmpe.f32 s14, s13 */
/* @0x170d9c vmrs APSR_nzcv, fpscr */
/* @0x170da0 vaddmi.f32 s16, s14, s15 */
/* @0x170da4 vstr s17, [r5, #388] */
/* @0x170da8 vstr s16, [r5, #392] */
/* @0x170dac mov r0, r5 */
/* @0x170db0 bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv> */
/* @0x170db4 vadd.f32 s21, s17, s21 */
/* @0x170db8 vadd.f32 s20, s16, s20 */
/* @0x170dbc vmov r1, s21 */
/* @0x170dc0 vmov r2, s20 */
/* @0x170dc4 cmp r0, #0 */
/* @0x170dc8 mov r0, r5 */
/* @0x170dcc beq 0x170e94 <_ZN7CCamera12CameraUpdateEv+0x364> */
/* @0x170dd0 vpop {d8, d9, d10, d11} */
/* @0x170dd4 pop {r3, r4, r5, lr} */
/* @0x170dd8 b 0x16db44 <_ZN7CCamera11Build2DViewEff> */
/* @0x170ddc vpop {d8, d9, d10, d11} */
/* @0x170de0 pop {r3, r4, r5, lr} */
/* @0x170de4 b 0x170888 <_ZN7CCamera13ExecuteScriptEi> */
/* @0x170de8 ldr r3, [pc, #0xd4] */
/* @0x170dec ldr r3, [pc, r3] */
/* @0x170df0 ldr r1, [r3, #0x4] */
/* @0x170df4 ldr r3, [r3] */
/* @0x170df8 and r1, r2, r1 */
/* @0x170dfc ldr r3, [r3, r1, lsl #3] */
/* @0x170e00 cmp r3, #0 */
/* @0x170e04 bne 0x170e18 <_ZN7CCamera12CameraUpdateEv+0x2e8> */
/* @0x170e08 b 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170e0c ldr r3, [r3, #0x4] */
/* @0x170e10 cmp r3, #0 */
/* @0x170e14 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170e18 ldr r1, [r3, #0x8] */
/* @0x170e1c cmp r2, r1 */
/* @0x170e20 bne 0x170e0c <_ZN7CCamera12CameraUpdateEv+0x2dc> */
/* @0x170e24 ldr r4, [r3, #0xc] */
/* @0x170e28 cmp r4, #0 */
/* @0x170e2c beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170e30 ldrb r3, [r4, #0x68] */
/* @0x170e34 cmp r3, #0 */
/* @0x170e38 bne 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170e3c ldrb r3, [r4, #0x69] */
/* @0x170e40 cmp r3, #0 */
/* @0x170e44 beq 0x170be8 <_ZN7CCamera12CameraUpdateEv+0xb8> */
/* @0x170e48 vpop {d8, d9, d10, d11} */
/* @0x170e4c pop {r3, r4, r5, pc} */
/* @0x170e50 bl 0x16d378 <_ZN7CCamera11IsViewDirtyEv> */
/* @0x170e54 cmp r0, #0 */
/* @0x170e58 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318> */
/* @0x170e5c mov r0, r5 */
/* @0x170e60 bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv> */
/* @0x170e64 vmov.f32 s15, #5.000000e-01 */
/* @0x170e68 vldr s11, [r5, #396] */
/* @0x170e6c vldr s12, [r5, #388] */
/* @0x170e70 vldr s13, [r5, #400] */
/* @0x170e74 vldr s14, [r5, #392] */
/* @0x170e78 vmla.f32 s12, s11, s15 */
/* @0x170e7c vmla.f32 s14, s13, s15 */
/* @0x170e80 cmp r0, #0 */
/* @0x170e84 vmov r1, s12 */
/* @0x170e88 mov r0, r5 */
/* @0x170e8c vmov r2, s14 */
/* @0x170e90 bne 0x170dd0 <_ZN7CCamera12CameraUpdateEv+0x2a0> */
/* @0x170e94 vpop {d8, d9, d10, d11} */
/* @0x170e98 pop {r3, r4, r5, lr} */
/* @0x170e9c b 0x16dc0c <_ZN7CCamera11Build3DViewEff> */
/* @0x170ea0 mov r0, r4 */
/* @0x170ea4 mov r1, #1 */
/* @0x170ea8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x170eac vldr s19, [r5, #396] */
/* @0x170eb0 vldr s18, [r5, #400] */
/* @0x170eb4 b 0x170c10 <_ZN7CCamera12CameraUpdateEv+0xe0> */
/* @0x170eb8 andeq r0, r0, r0 */
/* @0x170ebc .word 0x0027d0d4 */
/* @0x170ec0 eoreq r12, r7, r12, ror #24 */
/* @0x170ec4 eoreq r12, r7, r8, asr lr */

/* ── FUNC 0x170ec8 · Hash<RSurface>::~Hash() · size=128 · insn=32 */
/* @0x170ec8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x170ecc mov r6, r0 */
/* @0x170ed0 ldm r0, {r0, r8} */
/* @0x170ed4 cmp r8, #0 */
/* @0x170ed8 lslge r7, r8, #3 */
/* @0x170edc movge r9, #0 */
/* @0x170ee0 blt 0x170f3c <_ZN4HashI8RSurfaceED2Ev+0x74> */
/* @0x170ee4 ldr r4, [r0, r7] */
/* @0x170ee8 add r3, r0, r7 */
/* @0x170eec str r9, [r0, r7] */
/* @0x170ef0 cmp r4, #0 */
/* @0x170ef4 str r9, [r3, #0x4] */
/* @0x170ef8 beq 0x170f2c <_ZN4HashI8RSurfaceED2Ev+0x64> */
/* @0x170efc ldr r5, [r4, #0x4] */
/* @0x170f00 ldr r0, [r4, #0xc] */
/* @0x170f04 bl 0x27d1d0 <_ZdlPv> */
/* @0x170f08 mov r0, r4 */
/* @0x170f0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x170f10 ldr r3, [r6, #0x8] */
/* @0x170f14 cmp r5, #0 */
/* @0x170f18 mov r4, r5 */
/* @0x170f1c sub r3, r3, #1 */
/* @0x170f20 str r3, [r6, #0x8] */
/* @0x170f24 bne 0x170efc <_ZN4HashI8RSurfaceED2Ev+0x34> */
/* @0x170f28 ldr r0, [r6] */
/* @0x170f2c sub r8, r8, #1 */
/* @0x170f30 sub r7, r7, #8 */
/* @0x170f34 cmn r8, #1 */
/* @0x170f38 bne 0x170ee4 <_ZN4HashI8RSurfaceED2Ev+0x1c> */
/* @0x170f3c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x170f40 mov r0, r6 */
/* @0x170f44 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x170ec8 · Hash<RSurface>::~Hash() · alias of the symbol above · insn=0 */

/* ── FUNC 0x170f48 · GR_Surface_Get(int) · size=80 · insn=20 */
/* @0x170f48 ldr r3, [pc, #0x44] */
/* @0x170f4c ldr r3, [pc, r3] */
/* @0x170f50 ldr r2, [r3, #0x4] */
/* @0x170f54 ldr r3, [r3] */
/* @0x170f58 and r2, r0, r2 */
/* @0x170f5c ldr r3, [r3, r2, lsl #3] */
/* @0x170f60 cmp r3, #0 */
/* @0x170f64 bne 0x170f78 <_Z14GR_Surface_Geti+0x30> */
/* @0x170f68 b 0x170f8c <_Z14GR_Surface_Geti+0x44> */
/* @0x170f6c ldr r3, [r3, #0x4] */
/* @0x170f70 cmp r3, #0 */
/* @0x170f74 beq 0x170f8c <_Z14GR_Surface_Geti+0x44> */
/* @0x170f78 ldr r2, [r3, #0x8] */
/* @0x170f7c cmp r0, r2 */
/* @0x170f80 bne 0x170f6c <_Z14GR_Surface_Geti+0x24> */
/* @0x170f84 ldr r0, [r3, #0xc] */
/* @0x170f88 bx lr */
/* @0x170f8c mov r0, r3 */
/* @0x170f90 bx lr */
/* @0x170f94 eoreq r12, r7, r4, asr #23 */

/* ── FUNC 0x170f98 · GR_Surface_Create(int, int, int) · size=656 · insn=164 */
/* @0x170f98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x170f9c cmp r2, #0 */
/* @0x170fa0 ldr r5, [pc, #0x25c] */
/* @0x170fa4 sub sp, sp, #20 */
/* @0x170fa8 mov r7, r0 */
/* @0x170fac mov r6, r1 */
/* @0x170fb0 add r5, pc, r5 */
/* @0x170fb4 blt 0x17107c <_Z17GR_Surface_Createiii+0xe4> */
/* @0x170fb8 ldr r3, [pc, #0x248] */
/* @0x170fbc ldr r9, [r5, r3] */
/* @0x170fc0 ldr r1, [r9, #0x4] */
/* @0x170fc4 ldr r3, [r9] */
/* @0x170fc8 and r1, r2, r1 */
/* @0x170fcc ldr r3, [r3, r1, lsl #3] */
/* @0x170fd0 cmp r3, #0 */
/* @0x170fd4 beq 0x171000 <_Z17GR_Surface_Createiii+0x68> */
/* @0x170fd8 ldr r1, [r3, #0x8] */
/* @0x170fdc cmp r2, r1 */
/* @0x170fe0 bne 0x170ff4 <_Z17GR_Surface_Createiii+0x5c> */
/* @0x170fe4 b 0x17100c <_Z17GR_Surface_Createiii+0x74> */
/* @0x170fe8 ldr r12, [r3, #0x8] */
/* @0x170fec cmp r2, r12 */
/* @0x170ff0 beq 0x17100c <_Z17GR_Surface_Createiii+0x74> */
/* @0x170ff4 ldr r3, [r3, #0x4] */
/* @0x170ff8 cmp r3, #0 */
/* @0x170ffc bne 0x170fe8 <_Z17GR_Surface_Createiii+0x50> */
/* @0x171000 mvn r0, #0 */
/* @0x171004 add sp, sp, #20 */
/* @0x171008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17100c ldr r4, [r3, #0xc] */
/* @0x171010 cmp r4, #0 */
/* @0x171014 beq 0x171000 <_Z17GR_Surface_Createiii+0x68> */
/* @0x171018 mov r3, #4 */
/* @0x17101c mov r0, r7 */
/* @0x171020 str r3, [sp] */
/* @0x171024 mov r1, r6 */
/* @0x171028 mov r3, #0 */
/* @0x17102c mov r2, #1 */
/* @0x171030 bl 0x173a24 <_Z23GR_Texture_Create_Emptyiibbi> */
/* @0x171034 ldr r3, [pc, #0x1d0] */
/* @0x171038 cmp r0, #0 */
/* @0x17103c blt 0x171158 <_Z17GR_Surface_Createiii+0x1c0> */
/* @0x171040 stmib r4, {r0, r7} */
/* @0x171044 str r6, [r4, #0xc] */
/* @0x171048 ldr r3, [r5, r3] */
/* @0x17104c ldr r0, [r4] */
/* @0x171050 ldr r3, [r3] */
/* @0x171054 cmp r0, r3 */
/* @0x171058 bne 0x171004 <_Z17GR_Surface_Createiii+0x6c> */
/* @0x17105c ldr r2, [pc, #0x1ac] */
/* @0x171060 ldr r3, [pc, #0x1ac] */
/* @0x171064 ldr r2, [r5, r2] */
/* @0x171068 str r7, [r2] */
/* @0x17106c ldr r3, [r5, r3] */
/* @0x171070 str r6, [r3] */
/* @0x171074 add sp, sp, #20 */
/* @0x171078 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17107c ldr r3, [pc, #0x194] */
/* @0x171080 ldr r4, [pc, #0x194] */
/* @0x171084 add r3, pc, r3 */
/* @0x171088 add r4, pc, r4 */
/* @0x17108c ldr r0, [r3] */
/* @0x171090 b 0x1710a4 <_Z17GR_Surface_Createiii+0x10c> */
/* @0x171094 ldr r3, [r4] */
/* @0x171098 add r3, r3, #1 */
/* @0x17109c str r3, [r4] */
/* @0x1710a0 mov r0, r3 */
/* @0x1710a4 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x1710a8 subs r8, r0, #0 */
/* @0x1710ac bne 0x171094 <_Z17GR_Surface_Createiii+0xfc> */
/* @0x1710b0 mov r0, #16 */
/* @0x1710b4 bl 0x27c524 <_Znwj> */
/* @0x1710b8 ldr r1, [pc, #0x160] */
/* @0x1710bc ldr r12, [pc, #0x144] */
/* @0x1710c0 mov r3, #1 */
/* @0x1710c4 add r1, pc, r1 */
/* @0x1710c8 movw r2, #0x132 */
/* @0x1710cc ldr r10, [r1] */
/* @0x1710d0 add lr, r10, r3 */
/* @0x1710d4 str lr, [r1] */
/* @0x1710d8 ldr r1, [pc, #0x144] */
/* @0x1710dc add r1, pc, r1 */
/* @0x1710e0 mov r4, r0 */
/* @0x1710e4 mov r0, #16 */
/* @0x1710e8 str r8, [r4, #0x4] */
/* @0x1710ec str r8, [r4, #0x8] */
/* @0x1710f0 str r8, [r4, #0xc] */
/* @0x1710f4 str r10, [r4] */
/* @0x1710f8 ldr r9, [r5, r12] */
/* @0x1710fc ldm r9, {r11, r12} */
/* @0x171100 and r12, r10, r12 */
/* @0x171104 str r12, [sp, #0xc] */
/* @0x171108 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17110c ldr r12, [sp, #0xc] */
/* @0x171110 ldr r2, [r11, r12, lsl #3] */
/* @0x171114 add r3, r11, r12, lsl #3 */
/* @0x171118 cmp r2, #0 */
/* @0x17111c ldrne r2, [r3, #0x4] */
/* @0x171120 str r10, [r0, #0x8] */
/* @0x171124 str r4, [r0, #0xc] */
/* @0x171128 strne r2, [r0] */
/* @0x17112c streq r0, [r3, #0x4] */
/* @0x171130 strne r0, [r2, #0x4] */
/* @0x171134 strne r0, [r3, #0x4] */
/* @0x171138 ldr r3, [r9, #0x8] */
/* @0x17113c streq r0, [r11, r12, lsl #3] */
/* @0x171140 strne r8, [r0, #0x4] */
/* @0x171144 add r3, r3, #1 */
/* @0x171148 streq r2, [r0, #0x4] */
/* @0x17114c streq r2, [r0] */
/* @0x171150 str r3, [r9, #0x8] */
/* @0x171154 b 0x171018 <_Z17GR_Surface_Createiii+0x80> */
/* @0x171158 ldr r3, [r5, r3] */
/* @0x17115c ldr r2, [r4] */
/* @0x171160 ldr r3, [r3] */
/* @0x171164 cmp r2, r3 */
/* @0x171168 bne 0x171188 <_Z17GR_Surface_Createiii+0x1f0> */
/* @0x17116c ldr r0, [pc, #0x9c] */
/* @0x171170 mov r3, #1 */
/* @0x171174 ldr r1, [pc, #0x98] */
/* @0x171178 ldr r0, [r5, r0] */
/* @0x17117c str r3, [r0] */
/* @0x171180 ldr r1, [r5, r1] */
/* @0x171184 str r3, [r1] */
/* @0x171188 ldr r0, [r9, #0x4] */
/* @0x17118c ldr r1, [r9] */
/* @0x171190 and r0, r2, r0 */
/* @0x171194 ldr r4, [r1, r0, lsl #3] */
/* @0x171198 add r12, r1, r0, lsl #3 */
/* @0x17119c cmp r4, #0 */
/* @0x1711a0 bne 0x1711b4 <_Z17GR_Surface_Createiii+0x21c> */
/* @0x1711a4 b 0x171000 <_Z17GR_Surface_Createiii+0x68> */
/* @0x1711a8 ldr r4, [r4, #0x4] */
/* @0x1711ac cmp r4, #0 */
/* @0x1711b0 beq 0x171000 <_Z17GR_Surface_Createiii+0x68> */
/* @0x1711b4 ldr r3, [r4, #0x8] */
/* @0x1711b8 cmp r2, r3 */
/* @0x1711bc bne 0x1711a8 <_Z17GR_Surface_Createiii+0x210> */
/* @0x1711c0 ldm r4, {r2, r3} */
/* @0x1711c4 cmp r2, #0 */
/* @0x1711c8 strne r3, [r2, #0x4] */
/* @0x1711cc ldrne r3, [r4, #0x4] */
/* @0x1711d0 streq r3, [r1, r0, lsl #3] */
/* @0x1711d4 cmp r3, #0 */
/* @0x1711d8 ldr r0, [r4, #0xc] */
/* @0x1711dc strne r2, [r3] */
/* @0x1711e0 streq r2, [r12, #0x4] */
/* @0x1711e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1711e8 mov r0, r4 */
/* @0x1711ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1711f0 ldr r3, [r9, #0x8] */
/* @0x1711f4 mvn r0, #0 */
/* @0x1711f8 add r3, r3, r0 */
/* @0x1711fc str r3, [r9, #0x8] */
/* @0x171200 b 0x171004 <_Z17GR_Surface_Createiii+0x6c> */
/* @0x171204 eoreq r0, r8, r0, lsr #25 */
/* @0x171208 .word 0xffffbec0 */
/* @0x17120c .word 0xffffc988 */
/* @0x171210 .word 0xffffdf38 */
/* @0x171214 .word 0xffffdf40 */
/* @0x171218 eorseq lr, r1, r12, lsl r7 */
/* @0x17121c eorseq lr, r1, r8, lsl r7 */
/* @0x171220 ldrsbteq lr, [r1], -r12 */
/* @0x171224 andseq r10, sp, r8, asr #5 */

/* ── FUNC 0x171228 · GR_Surface_Create_Special(int, int, int, int) · size=664 · insn=166 */
/* @0x171228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17122c cmp r2, #0 */
/* @0x171230 ldr r5, [pc, #0x264] */
/* @0x171234 sub sp, sp, #20 */
/* @0x171238 mov r9, r0 */
/* @0x17123c mov r8, r1 */
/* @0x171240 mov r10, r3 */
/* @0x171244 add r5, pc, r5 */
/* @0x171248 blt 0x171308 <_Z25GR_Surface_Create_Specialiiii+0xe0> */
/* @0x17124c ldr r3, [pc, #0x24c] */
/* @0x171250 ldr r7, [r5, r3] */
/* @0x171254 ldr r1, [r7, #0x4] */
/* @0x171258 ldr r3, [r7] */
/* @0x17125c and r1, r2, r1 */
/* @0x171260 ldr r3, [r3, r1, lsl #3] */
/* @0x171264 cmp r3, #0 */
/* @0x171268 bne 0x17127c <_Z25GR_Surface_Create_Specialiiii+0x54> */
/* @0x17126c b 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4> */
/* @0x171270 ldr r3, [r3, #0x4] */
/* @0x171274 cmp r3, #0 */
/* @0x171278 beq 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4> */
/* @0x17127c ldr r1, [r3, #0x8] */
/* @0x171280 cmp r2, r1 */
/* @0x171284 bne 0x171270 <_Z25GR_Surface_Create_Specialiiii+0x48> */
/* @0x171288 ldr r4, [r3, #0xc] */
/* @0x17128c cmp r4, #0 */
/* @0x171290 beq 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4> */
/* @0x171294 mov r2, #1 */
/* @0x171298 str r10, [sp] */
/* @0x17129c mov r3, r2 */
/* @0x1712a0 mov r0, r9 */
/* @0x1712a4 mov r1, r8 */
/* @0x1712a8 bl 0x173a24 <_Z23GR_Texture_Create_Emptyiibbi> */
/* @0x1712ac ldr r3, [pc, #0x1f0] */
/* @0x1712b0 cmp r0, #0 */
/* @0x1712b4 blt 0x1713f0 <_Z25GR_Surface_Create_Specialiiii+0x1c8> */
/* @0x1712b8 stmib r4, {r0, r9} */
/* @0x1712bc str r8, [r4, #0xc] */
/* @0x1712c0 ldr r3, [r5, r3] */
/* @0x1712c4 ldr r0, [r4] */
/* @0x1712c8 ldr r3, [r3] */
/* @0x1712cc cmp r0, r3 */
/* @0x1712d0 beq 0x1712e8 <_Z25GR_Surface_Create_Specialiiii+0xc0> */
/* @0x1712d4 add sp, sp, #20 */
/* @0x1712d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1712dc mvn r0, #0 */
/* @0x1712e0 add sp, sp, #20 */
/* @0x1712e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1712e8 ldr r2, [pc, #0x1b8] */
/* @0x1712ec ldr r3, [pc, #0x1b8] */
/* @0x1712f0 ldr r2, [r5, r2] */
/* @0x1712f4 str r9, [r2] */
/* @0x1712f8 ldr r3, [r5, r3] */
/* @0x1712fc str r8, [r3] */
/* @0x171300 add sp, sp, #20 */
/* @0x171304 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x171308 ldr r3, [pc, #0x1a0] */
/* @0x17130c ldr r4, [pc, #0x1a0] */
/* @0x171310 add r3, pc, r3 */
/* @0x171314 add r4, pc, r4 */
/* @0x171318 ldr r0, [r3] */
/* @0x17131c b 0x17132c <_Z25GR_Surface_Create_Specialiiii+0x104> */
/* @0x171320 ldr r0, [r4] */
/* @0x171324 add r0, r0, #1 */
/* @0x171328 str r0, [r4] */
/* @0x17132c bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x171330 cmp r0, #0 */
/* @0x171334 bne 0x171320 <_Z25GR_Surface_Create_Specialiiii+0xf8> */
/* @0x171338 mov r6, r0 */
/* @0x17133c mov r0, #16 */
/* @0x171340 bl 0x27c524 <_Znwj> */
/* @0x171344 ldr r1, [pc, #0x16c] */
/* @0x171348 ldr r12, [pc, #0x150] */
/* @0x17134c mov r3, #1 */
/* @0x171350 add r1, pc, r1 */
/* @0x171354 movw r2, #0x132 */
/* @0x171358 ldr r11, [r1] */
/* @0x17135c add lr, r11, r3 */
/* @0x171360 str lr, [r1] */
/* @0x171364 ldr r1, [pc, #0x150] */
/* @0x171368 add r1, pc, r1 */
/* @0x17136c mov r4, r0 */
/* @0x171370 mov r0, #16 */
/* @0x171374 str r6, [r4, #0x4] */
/* @0x171378 str r6, [r4, #0x8] */
/* @0x17137c str r6, [r4, #0xc] */
/* @0x171380 str r11, [r4] */
/* @0x171384 ldr r7, [r5, r12] */
/* @0x171388 ldr lr, [r7] */
/* @0x17138c ldr r12, [r7, #0x4] */
/* @0x171390 str lr, [sp, #0xc] */
/* @0x171394 and r12, r11, r12 */
/* @0x171398 str r12, [sp, #0x8] */
/* @0x17139c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1713a0 ldr r12, [sp, #0x8] */
/* @0x1713a4 ldr r1, [sp, #0xc] */
/* @0x1713a8 add r3, r1, r12, lsl #3 */
/* @0x1713ac ldr r2, [r1, r12, lsl #3] */
/* @0x1713b0 cmp r2, #0 */
/* @0x1713b4 ldrne r2, [r3, #0x4] */
/* @0x1713b8 str r11, [r0, #0x8] */
/* @0x1713bc str r4, [r0, #0xc] */
/* @0x1713c0 strne r2, [r0] */
/* @0x1713c4 streq r0, [r3, #0x4] */
/* @0x1713c8 strne r0, [r2, #0x4] */
/* @0x1713cc strne r0, [r3, #0x4] */
/* @0x1713d0 ldr r3, [r7, #0x8] */
/* @0x1713d4 streq r0, [r1, r12, lsl #3] */
/* @0x1713d8 strne r6, [r0, #0x4] */
/* @0x1713dc add r3, r3, #1 */
/* @0x1713e0 streq r2, [r0, #0x4] */
/* @0x1713e4 streq r2, [r0] */
/* @0x1713e8 str r3, [r7, #0x8] */
/* @0x1713ec b 0x171294 <_Z25GR_Surface_Create_Specialiiii+0x6c> */
/* @0x1713f0 ldr r3, [r5, r3] */
/* @0x1713f4 ldr r2, [r4] */
/* @0x1713f8 ldr r3, [r3] */
/* @0x1713fc cmp r2, r3 */
/* @0x171400 bne 0x171420 <_Z25GR_Surface_Create_Specialiiii+0x1f8> */
/* @0x171404 ldr r0, [pc, #0x9c] */
/* @0x171408 mov r3, #1 */
/* @0x17140c ldr r1, [pc, #0x98] */
/* @0x171410 ldr r0, [r5, r0] */
/* @0x171414 str r3, [r0] */
/* @0x171418 ldr r1, [r5, r1] */
/* @0x17141c str r3, [r1] */
/* @0x171420 ldr r0, [r7, #0x4] */
/* @0x171424 ldr r1, [r7] */
/* @0x171428 and r0, r2, r0 */
/* @0x17142c ldr r4, [r1, r0, lsl #3] */
/* @0x171430 add r12, r1, r0, lsl #3 */
/* @0x171434 cmp r4, #0 */
/* @0x171438 bne 0x17144c <_Z25GR_Surface_Create_Specialiiii+0x224> */
/* @0x17143c b 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4> */
/* @0x171440 ldr r4, [r4, #0x4] */
/* @0x171444 cmp r4, #0 */
/* @0x171448 beq 0x1712dc <_Z25GR_Surface_Create_Specialiiii+0xb4> */
/* @0x17144c ldr r3, [r4, #0x8] */
/* @0x171450 cmp r2, r3 */
/* @0x171454 bne 0x171440 <_Z25GR_Surface_Create_Specialiiii+0x218> */
/* @0x171458 ldm r4, {r2, r3} */
/* @0x17145c cmp r2, #0 */
/* @0x171460 strne r3, [r2, #0x4] */
/* @0x171464 ldrne r3, [r4, #0x4] */
/* @0x171468 streq r3, [r1, r0, lsl #3] */
/* @0x17146c cmp r3, #0 */
/* @0x171470 ldr r0, [r4, #0xc] */
/* @0x171474 strne r2, [r3] */
/* @0x171478 streq r2, [r12, #0x4] */
/* @0x17147c bl 0x27d1d0 <_ZdlPv> */
/* @0x171480 mov r0, r4 */
/* @0x171484 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x171488 ldr r3, [r7, #0x8] */
/* @0x17148c mvn r0, #0 */
/* @0x171490 add r3, r3, r0 */
/* @0x171494 str r3, [r7, #0x8] */
/* @0x171498 b 0x1712d4 <_Z25GR_Surface_Create_Specialiiii+0xac> */
/* @0x17149c eoreq r0, r8, r12, lsl #20 */
/* @0x1714a0 .word 0xffffbec0 */
/* @0x1714a4 .word 0xffffc988 */
/* @0x1714a8 .word 0xffffdf38 */
/* @0x1714ac .word 0xffffdf40 */
/* @0x1714b0 mlaseq r1, r0, r4, lr */
/* @0x1714b4 eorseq lr, r1, r12, lsl #9 */
/* @0x1714b8 eorseq lr, r1, r0, asr r4 */
/* @0x1714bc andseq r10, sp, r12, lsr r0 */

/* ── FUNC 0x1714c0 · GR_Surface_Exists(int) · size=20 · insn=5 */
/* @0x1714c0 push {r3, lr} */
/* @0x1714c4 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x1714c8 adds r0, r0, #0 */
/* @0x1714cc movne r0, #1 */
/* @0x1714d0 pop {r3, pc} */

/* ── FUNC 0x1714d4 · GR_Surface_Get_Width(int) · size=68 · insn=17 */
/* @0x1714d4 push {r3, lr} */
/* @0x1714d8 ldr r3, [pc, #0x30] */
/* @0x1714dc ldr r3, [pc, r3] */
/* @0x1714e0 ldr r3, [r3] */
/* @0x1714e4 cmp r0, r3 */
/* @0x1714e8 beq 0x171500 <_Z20GR_Surface_Get_Widthi+0x2c> */
/* @0x1714ec bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x1714f0 cmp r0, #0 */
/* @0x1714f4 ldrne r0, [r0, #0x8] */
/* @0x1714f8 mvneq r0, #0 */
/* @0x1714fc pop {r3, pc} */
/* @0x171500 ldr r3, [pc, #0xc] */
/* @0x171504 ldr r3, [pc, r3] */
/* @0x171508 ldr r0, [r3] */
/* @0x17150c pop {r3, pc} */
/* @0x171510 .word 0x0027d0fc */
/* @0x171514 eoreq lr, r7, r4, lsl #13 */

/* ── FUNC 0x171518 · GR_Surface_Get_Height(int) · size=68 · insn=17 */
/* @0x171518 push {r3, lr} */
/* @0x17151c ldr r3, [pc, #0x30] */
/* @0x171520 ldr r3, [pc, r3] */
/* @0x171524 ldr r3, [r3] */
/* @0x171528 cmp r0, r3 */
/* @0x17152c beq 0x171544 <_Z21GR_Surface_Get_Heighti+0x2c> */
/* @0x171530 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x171534 cmp r0, #0 */
/* @0x171538 ldrne r0, [r0, #0xc] */
/* @0x17153c mvneq r0, #0 */
/* @0x171540 pop {r3, pc} */
/* @0x171544 ldr r3, [pc, #0xc] */
/* @0x171548 ldr r3, [pc, r3] */
/* @0x17154c ldr r0, [r3] */
/* @0x171550 pop {r3, pc} */
/* @0x171554 strhteq sp, [r7], -r8 */
/* @0x171558 eoreq lr, r7, r8, asr #12 */

/* ── FUNC 0x17155c · GR_Surface_Get_Texture(int) · size=24 · insn=6 */
/* @0x17155c push {r3, lr} */
/* @0x171560 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x171564 cmp r0, #0 */
/* @0x171568 ldrne r0, [r0, #0x4] */
/* @0x17156c mvneq r0, #0 */
/* @0x171570 pop {r3, pc} */

/* ── FUNC 0x171574 · YYGML_surface_set_target_ext(int, int) · size=660 · insn=165 */
/* @0x171574 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x171578 cmp r0, #3 */
/* @0x17157c ldr r4, [pc, #0x240] */
/* @0x171580 sub sp, sp, #20 */
/* @0x171584 mov r8, r0 */
/* @0x171588 mov r5, r1 */
/* @0x17158c add r4, pc, r4 */
/* @0x171590 bhi 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34> */
/* @0x171594 ldr r3, [pc, #0x22c] */
/* @0x171598 ldr r3, [r4, r3] */
/* @0x17159c ldrb r3, [r3] */
/* @0x1715a0 cmp r3, #0 */
/* @0x1715a4 bne 0x1715b8 <_Z28YYGML_surface_set_target_extii+0x44> */
/* @0x1715a8 mov r9, #0 */
/* @0x1715ac mov r0, r9 */
/* @0x1715b0 add sp, sp, #20 */
/* @0x1715b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1715b8 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1715bc mov r0, r5 */
/* @0x1715c0 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x1715c4 subs r6, r0, #0 */
/* @0x1715c8 beq 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34> */
/* @0x1715cc ldr r0, [r6, #0x4] */
/* @0x1715d0 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x1715d4 subs r7, r0, #0 */
/* @0x1715d8 beq 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34> */
/* @0x1715dc ldr r3, [pc, #0x1e8] */
/* @0x1715e0 ldr r3, [r4, r3] */
/* @0x1715e4 str r3, [sp, #0xc] */
/* @0x1715e8 ldr r3, [r3] */
/* @0x1715ec cmp r3, #496 */
/* @0x1715f0 bgt 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34> */
/* @0x1715f4 cmp r8, #0 */
/* @0x1715f8 bne 0x17179c <_Z28YYGML_surface_set_target_extii+0x228> */
/* @0x1715fc ldr r8, [pc, #0x1cc] */
/* @0x171600 add r0, r3, #1 */
/* @0x171604 ldr r2, [pc, #0x1c8] */
/* @0x171608 add lr, r3, #2 */
/* @0x17160c ldr r1, [pc, #0x1c4] */
/* @0x171610 add r12, r3, #3 */
/* @0x171614 ldr r8, [r4, r8] */
/* @0x171618 add r9, r3, #4 */
/* @0x17161c ldr r2, [r4, r2] */
/* @0x171620 add r11, r3, #5 */
/* @0x171624 add r10, r3, #6 */
/* @0x171628 ldr r8, [r8] */
/* @0x17162c str r8, [r2, r3, lsl #2] */
/* @0x171630 ldr r8, [r4, r1] */
/* @0x171634 ldr r1, [pc, #0x1a0] */
/* @0x171638 ldr r8, [r8] */
/* @0x17163c str r8, [r2, r0, lsl #2] */
/* @0x171640 add r8, r3, #7 */
/* @0x171644 ldr r0, [r4, r1] */
/* @0x171648 ldr r1, [pc, #0x190] */
/* @0x17164c ldr r0, [r0] */
/* @0x171650 str r0, [r2, lr, lsl #2] */
/* @0x171654 add r0, r3, #8 */
/* @0x171658 ldr lr, [r4, r1] */
/* @0x17165c ldr r1, [pc, #0x180] */
/* @0x171660 ldr lr, [lr] */
/* @0x171664 str lr, [r2, r12, lsl #2] */
/* @0x171668 add lr, r3, #10 */
/* @0x17166c ldr r1, [r4, r1] */
/* @0x171670 ldr r12, [pc, #0x170] */
/* @0x171674 ldr r1, [r1] */
/* @0x171678 str r1, [r2, r9, lsl #2] */
/* @0x17167c add r1, r3, #9 */
/* @0x171680 ldr r12, [r4, r12] */
/* @0x171684 ldr r9, [pc, #0x160] */
/* @0x171688 ldr r12, [r12] */
/* @0x17168c str r12, [r2, r11, lsl #2] */
/* @0x171690 add r12, r2, r1, lsl #2 */
/* @0x171694 ldr r11, [r4, r9] */
/* @0x171698 ldr r9, [pc, #0x150] */
/* @0x17169c ldr r11, [r11] */
/* @0x1716a0 str r11, [r2, r10, lsl #2] */
/* @0x1716a4 ldr r9, [r4, r9] */
/* @0x1716a8 ldr r10, [pc, #0x144] */
/* @0x1716ac ldr r11, [r9] */
/* @0x1716b0 ldr r9, [pc, #0x140] */
/* @0x1716b4 str r11, [r2, r8, lsl #2] */
/* @0x1716b8 ldr r8, [r4, r10] */
/* @0x1716bc ldr r10, [sp, #0xc] */
/* @0x1716c0 ldr r8, [r8] */
/* @0x1716c4 str lr, [r10] */
/* @0x1716c8 ldr lr, [pc, #0x12c] */
/* @0x1716cc str r8, [r2, r0, lsl #2] */
/* @0x1716d0 ldr r0, [r4, r9] */
/* @0x1716d4 ldrb r0, [r0] */
/* @0x1716d8 str r0, [r2, r1, lsl #2] */
/* @0x1716dc ldr r8, [r4, lr] */
/* @0x1716e0 sub r2, r8, #4 */
/* @0x1716e4 add r0, r8, #12 */
/* @0x1716e8 ldr r1, [r2, #0x4]! */
/* @0x1716ec cmp r2, r0 */
/* @0x1716f0 str r1, [r12, #0x4]! */
/* @0x1716f4 bne 0x1716e8 <_Z28YYGML_surface_set_target_extii+0x174> */
/* @0x1716f8 ldr r2, [sp, #0xc] */
/* @0x1716fc add r3, r3, #14 */
/* @0x171700 str r3, [r2] */
/* @0x171704 bl 0x1833cc <_ZN8Graphics16SaveRenderTargetEv> */
/* @0x171708 subs r9, r0, #0 */
/* @0x17170c beq 0x171788 <_Z28YYGML_surface_set_target_extii+0x214> */
/* @0x171710 mov r1, r7 */
/* @0x171714 mov r0, #0 */
/* @0x171718 bl 0x183590 <_ZN8Graphics15SetRenderTargetEiPv> */
/* @0x17171c subs r9, r0, #0 */
/* @0x171720 beq 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34> */
/* @0x171724 mov r0, #0 */
/* @0x171728 ldr r2, [r6, #0x8] */
/* @0x17172c mov r1, r0 */
/* @0x171730 ldr r3, [r6, #0xc] */
/* @0x171734 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x171738 ldr r2, [r6, #0x8] */
/* @0x17173c ldr r3, [pc, #0xbc] */
/* @0x171740 mov r1, #0 */
/* @0x171744 mov r0, r1 */
/* @0x171748 vmov s15, r2 */
/* @0x17174c ldr r3, [r4, r3] */
/* @0x171750 vcvt.f32.s32 s15, s15 */
/* @0x171754 ldrb r3, [r3] */
/* @0x171758 cmp r3, #0 */
/* @0x17175c ldr r3, [r6, #0xc] */
/* @0x171760 str r1, [sp] */
/* @0x171764 vmov r2, s15 */
/* @0x171768 vmov s15, r3 */
/* @0x17176c vcvt.f32.s32 s15, s15 */
/* @0x171770 vmov r3, s15 */
/* @0x171774 beq 0x1717bc <_Z28YYGML_surface_set_target_extii+0x248> */
/* @0x171778 bl 0x1aff1c <_Z19UpdateDefaultCamerafffff> */
/* @0x17177c str r5, [r8] */
/* @0x171780 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x171784 b 0x1715ac <_Z28YYGML_surface_set_target_extii+0x38> */
/* @0x171788 ldr r0, [pc, #0x74] */
/* @0x17178c mov r1, r9 */
/* @0x171790 add r0, pc, r0 */
/* @0x171794 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x171798 b 0x1715ac <_Z28YYGML_surface_set_target_extii+0x38> */
/* @0x17179c ldr r3, [pc, #0x58] */
/* @0x1717a0 mov r1, r7 */
/* @0x1717a4 mov r0, r8 */
/* @0x1717a8 ldr r3, [r4, r3] */
/* @0x1717ac str r5, [r3, r8, lsl #2] */
/* @0x1717b0 add sp, sp, #20 */
/* @0x1717b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1717b8 b 0x183590 <_ZN8Graphics15SetRenderTargetEiPv> */
/* @0x1717bc bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x1717c0 b 0x17177c <_Z28YYGML_surface_set_target_extii+0x208> */
/* @0x1717c4 eoreq r0, r8, r4, asr #13 */
/* @0x1717c8 .word 0xffffe4d0 */
/* @0x1717cc .word 0xffffe614 */
/* @0x1717d0 .word 0xffffe4ec */
/* @0x1717d4 .word 0xffffe618 */
/* @0x1717d8 .word 0xffffe4f0 */
/* @0x1717dc .word 0xffffe4f4 */
/* @0x1717e0 .word 0xffffe4f8 */
/* @0x1717e4 .word 0xffffe504 */
/* @0x1717e8 .word 0xffffe508 */
/* @0x1717ec .word 0xffffe50c */
/* @0x1717f0 .word 0xffffe510 */
/* @0x1717f4 .word 0xffffe514 */
/* @0x1717f8 .word 0xffffe490 */
/* @0x1717fc .word 0xffffe51c */
/* @0x171800 .word 0xffffbcd4 */
/* @0x171804 andseq r9, sp, r8, asr #24 */

/* ── FUNC 0x171808 · YYGML_surface_reset_target() · size=648 · insn=162 */
/* @0x171808 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17180c sub sp, sp, #36 */
/* @0x171810 ldr r4, [pc, #0x234] */
/* @0x171814 mov r3, #0 */
/* @0x171818 ldr r2, [pc, #0x230] */
/* @0x17181c add r4, pc, r4 */
/* @0x171820 str r3, [sp, #0x18] */
/* @0x171824 str r3, [sp, #0x1c] */
/* @0x171828 ldr r3, [r4, r2] */
/* @0x17182c ldrb r3, [r3] */
/* @0x171830 cmp r3, #0 */
/* @0x171834 bne 0x171848 <_Z26YYGML_surface_reset_targetv+0x40> */
/* @0x171838 mov r8, #0 */
/* @0x17183c mov r0, r8 */
/* @0x171840 add sp, sp, #36 */
/* @0x171844 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x171848 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17184c bl 0x183404 <_ZN8Graphics19RestoreRenderTargetEv> */
/* @0x171850 subs r8, r0, #0 */
/* @0x171854 beq 0x171838 <_Z26YYGML_surface_reset_targetv+0x30> */
/* @0x171858 ldr r3, [pc, #0x1f4] */
/* @0x17185c ldr r12, [r4, r3] */
/* @0x171860 ldr r3, [r12] */
/* @0x171864 cmp r3, #0 */
/* @0x171868 beq 0x171a04 <_Z26YYGML_surface_reset_targetv+0x1fc> */
/* @0x17186c ldr r1, [pc, #0x1e4] */
/* @0x171870 ldr r2, [pc, #0x1e4] */
/* @0x171874 ldr r5, [r4, r1] */
/* @0x171878 ldr r2, [r4, r2] */
/* @0x17187c add r1, r5, #12 */
/* @0x171880 sub r5, r5, #4 */
/* @0x171884 add r0, r2, r3, lsl #2 */
/* @0x171888 ldr lr, [r0, #-0x4]! */
/* @0x17188c str lr, [r1], #-4 */
/* @0x171890 cmp r1, r5 */
/* @0x171894 bne 0x171888 <_Z26YYGML_surface_reset_targetv+0x80> */
/* @0x171898 ldr r5, [pc, #0x1c0] */
/* @0x17189c sub r1, r3, #5 */
/* @0x1718a0 add r11, r2, r3, lsl #2 */
/* @0x1718a4 ldr r9, [pc, #0x1b8] */
/* @0x1718a8 ldr r10, [r2, r1, lsl #2] */
/* @0x1718ac vldr s15, [r11, #-32] */
/* @0x1718b0 ldr r5, [r4, r5] */
/* @0x1718b4 add r0, r2, r3, lsl #2 */
/* @0x1718b8 ldr r7, [pc, #0x1a8] */
/* @0x1718bc adds r10, r10, #0 */
/* @0x1718c0 vldr s13, [r0, #-24] */
/* @0x1718c4 ldr r6, [pc, #0x1a0] */
/* @0x1718c8 str r5, [sp, #0xc] */
/* @0x1718cc movne r10, #1 */
/* @0x1718d0 ldr r11, [sp, #0xc] */
/* @0x1718d4 vldr s14, [r0, #-28] */
/* @0x1718d8 ldr r5, [pc, #0x190] */
/* @0x1718dc sub lr, r3, #11 */
/* @0x1718e0 ldr r0, [pc, #0x18c] */
/* @0x1718e4 strb r10, [r11] */
/* @0x1718e8 add r10, r2, r3, lsl #2 */
/* @0x1718ec ldr r9, [r4, r9] */
/* @0x1718f0 vstr s13, [r9] */
/* @0x1718f4 ldr r7, [r4, r7] */
/* @0x1718f8 vstr s14, [r7] */
/* @0x1718fc ldr r11, [r10, #-0x24] */
/* @0x171900 ldr r1, [pc, #0x170] */
/* @0x171904 str r7, [sp, #0x14] */
/* @0x171908 ldr r6, [r4, r6] */
/* @0x17190c vstr s15, [r6] */
/* @0x171910 ldr lr, [r2, lr, lsl #2] */
/* @0x171914 str r6, [sp, #0xc] */
/* @0x171918 ldr r5, [r4, r5] */
/* @0x17191c str r5, [sp, #0x10] */
/* @0x171920 ldr r6, [sp, #0x10] */
/* @0x171924 ldr r5, [r10, #-0x28] */
/* @0x171928 str r11, [r6] */
/* @0x17192c ldr r11, [r4, r0] */
/* @0x171930 sub r0, r3, #12 */
/* @0x171934 ldr r6, [pc, #0x140] */
/* @0x171938 ldr r0, [r2, r0, lsl #2] */
/* @0x17193c str r5, [r11] */
/* @0x171940 ldr r5, [r4, r1] */
/* @0x171944 ldr r1, [pc, #0x134] */
/* @0x171948 str lr, [r5] */
/* @0x17194c sub lr, r3, #13 */
/* @0x171950 ldr r6, [r4, r6] */
/* @0x171954 sub r3, r3, #14 */
/* @0x171958 ldr lr, [r2, lr, lsl #2] */
/* @0x17195c ldr r2, [r2, r3, lsl #2] */
/* @0x171960 str r0, [r6] */
/* @0x171964 ldr r7, [r4, r1] */
/* @0x171968 ldr r1, [pc, #0x114] */
/* @0x17196c str r3, [r12] */
/* @0x171970 ldr r0, [pc, #0x110] */
/* @0x171974 str lr, [r7] */
/* @0x171978 ldr r10, [r4, r1] */
/* @0x17197c str r2, [r10] */
/* @0x171980 ldr r2, [r4, r0] */
/* @0x171984 ldrb r2, [r2] */
/* @0x171988 cmp r2, #0 */
/* @0x17198c beq 0x171998 <_Z26YYGML_surface_reset_targetv+0x190> */
/* @0x171990 cmp r3, #0 */
/* @0x171994 beq 0x171a44 <_Z26YYGML_surface_reset_targetv+0x23c> */
/* @0x171998 add r0, sp, #24 */
/* @0x17199c add r1, sp, #28 */
/* @0x1719a0 bl 0x168cac <_Z17GR_D3D_Get_RegionRiS_> */
/* @0x1719a4 ldr r0, [r10] */
/* @0x1719a8 ldr r3, [r5] */
/* @0x1719ac ldr r1, [r7] */
/* @0x1719b0 ldr r2, [r6] */
/* @0x1719b4 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x1719b8 ldr r3, [pc, #0xcc] */
/* @0x1719bc ldr r0, [r11] */
/* @0x1719c0 ldr r3, [r4, r3] */
/* @0x1719c4 ldrb r3, [r3] */
/* @0x1719c8 cmp r3, #0 */
/* @0x1719cc beq 0x171a1c <_Z26YYGML_surface_reset_targetv+0x214> */
/* @0x1719d0 ldr r7, [sp, #0x10] */
/* @0x1719d4 ldr r11, [sp, #0xc] */
/* @0x1719d8 ldr r12, [sp, #0x14] */
/* @0x1719dc ldr lr, [r9] */
/* @0x1719e0 ldr r1, [r7] */
/* @0x1719e4 ldr r2, [r11] */
/* @0x1719e8 ldr r3, [r12] */
/* @0x1719ec str lr, [sp] */
/* @0x1719f0 bl 0x1aff1c <_Z19UpdateDefaultCamerafffff> */
/* @0x1719f4 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x1719f8 mov r0, r8 */
/* @0x1719fc add sp, sp, #36 */
/* @0x171a00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x171a04 ldr r1, [pc, #0x4c] */
/* @0x171a08 mov r8, r3 */
/* @0x171a0c mvn r2, #0 */
/* @0x171a10 ldr r3, [r4, r1] */
/* @0x171a14 str r2, [r3] */
/* @0x171a18 b 0x17183c <_Z26YYGML_surface_reset_targetv+0x34> */
/* @0x171a1c ldr r6, [sp, #0x10] */
/* @0x171a20 ldr r7, [sp, #0xc] */
/* @0x171a24 ldr r11, [sp, #0x14] */
/* @0x171a28 ldr lr, [r9] */
/* @0x171a2c ldr r1, [r6] */
/* @0x171a30 ldr r2, [r7] */
/* @0x171a34 ldr r3, [r11] */
/* @0x171a38 str lr, [sp] */
/* @0x171a3c bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x171a40 b 0x1719f4 <_Z26YYGML_surface_reset_targetv+0x1ec> */
/* @0x171a44 bl 0x1b3330 <_Z10SetGuiViewv> */
/* @0x171a48 b 0x1719f4 <_Z26YYGML_surface_reset_targetv+0x1ec> */
/* @0x171a4c eoreq r0, r8, r4, lsr r4 */
/* @0x171a50 .word 0xffffe4d0 */
/* @0x171a54 .word 0xffffe614 */
/* @0x171a58 .word 0xffffe51c */
/* @0x171a5c .word 0xffffe618 */
/* @0x171a60 .word 0xffffe490 */
/* @0x171a64 .word 0xffffe61c */
/* @0x171a68 .word 0xffffe620 */
/* @0x171a6c .word 0xffffe624 */
/* @0x171a70 .word 0xffffe628 */
/* @0x171a74 .word 0xffffe62c */
/* @0x171a78 .word 0xffffe630 */
/* @0x171a7c .word 0xffffe634 */
/* @0x171a80 .word 0xffffe638 */
/* @0x171a84 .word 0xffffe63c */
/* @0x171a88 .word 0xffffdf30 */
/* @0x171a8c .word 0xffffbcd4 */

/* ── FUNC 0x171a90 · _FreeSurfaceData(int) · size=84 · insn=21 */
/* @0x171a90 push {r3, r4, r5, lr} */
/* @0x171a94 mov r4, r0 */
/* @0x171a98 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x171a9c subs r5, r0, #0 */
/* @0x171aa0 beq 0x171ad0 <_Z16_FreeSurfaceDatai+0x40> */
/* @0x171aa4 ldr r2, [pc, #0x34] */
/* @0x171aa8 ldr r2, [pc, r2] */
/* @0x171aac sub r3, r2, #4 */
/* @0x171ab0 add r1, r2, #12 */
/* @0x171ab4 ldr r2, [r3, #0x4]! */
/* @0x171ab8 cmp r2, r4 */
/* @0x171abc beq 0x171ad8 <_Z16_FreeSurfaceDatai+0x48> */
/* @0x171ac0 cmp r3, r1 */
/* @0x171ac4 bne 0x171ab4 <_Z16_FreeSurfaceDatai+0x24> */
/* @0x171ac8 ldr r0, [r5, #0x4] */
/* @0x171acc bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0x171ad0 mov r0, r5 */
/* @0x171ad4 pop {r3, r4, r5, pc} */
/* @0x171ad8 bl 0x171808 <_Z26YYGML_surface_reset_targetv> */
/* @0x171adc b 0x171ac8 <_Z16_FreeSurfaceDatai+0x38> */
/* @0x171ae0 eoreq lr, r7, r4, asr #13 */

/* ── FUNC 0x171ae4 · GR_Texture_Free_Only(int) · size=132 · insn=33 */
/* @0x171ae4 push {r4, lr} */
/* @0x171ae8 mov r4, r0 */
/* @0x171aec bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x171af0 mov r0, r4 */
/* @0x171af4 bl 0x171a90 <_Z16_FreeSurfaceDatai> */
/* @0x171af8 subs r3, r0, #0 */
/* @0x171afc beq 0x171b54 <_Z20GR_Texture_Free_Onlyi+0x70> */
/* @0x171b00 ldr r2, [pc, #0x54] */
/* @0x171b04 mov r1, #0 */
/* @0x171b08 mvn r0, #0 */
/* @0x171b0c str r1, [r3, #0x8] */
/* @0x171b10 ldr r2, [pc, r2] */
/* @0x171b14 str r0, [r3, #0x4] */
/* @0x171b18 str r1, [r3, #0xc] */
/* @0x171b1c ldr r3, [r2] */
/* @0x171b20 cmp r3, r4 */
/* @0x171b24 beq 0x171b30 <_Z20GR_Texture_Free_Onlyi+0x4c> */
/* @0x171b28 mov r0, #1 */
/* @0x171b2c pop {r4, pc} */
/* @0x171b30 ldr r1, [pc, #0x28] */
/* @0x171b34 mov r2, #1 */
/* @0x171b38 ldr r3, [pc, #0x24] */
/* @0x171b3c mov r0, r2 */
/* @0x171b40 ldr r1, [pc, r1] */
/* @0x171b44 ldr r3, [pc, r3] */
/* @0x171b48 str r2, [r1] */
/* @0x171b4c str r2, [r3] */
/* @0x171b50 pop {r4, pc} */
/* @0x171b54 mov r0, r3 */
/* @0x171b58 pop {r4, pc} */
/* @0x171b5c eoreq r12, r7, r8, asr #21 */
/* @0x171b60 eoreq lr, r7, r8, asr #32 */
/* @0x171b64 eoreq lr, r7, r12, asr #32 */

/* ── FUNC 0x171b68 · GR_Surface_Resize(int, int, int) · size=56 · insn=14 */
/* @0x171b68 push {r4, r5, r6, lr} */
/* @0x171b6c mov r6, r1 */
/* @0x171b70 mov r5, r2 */
/* @0x171b74 mov r4, r0 */
/* @0x171b78 bl 0x171ae4 <_Z20GR_Texture_Free_Onlyi> */
/* @0x171b7c cmp r0, #0 */
/* @0x171b80 popeq {r4, r5, r6, pc} */
/* @0x171b84 mov r0, r6 */
/* @0x171b88 mov r1, r5 */
/* @0x171b8c mov r2, r4 */
/* @0x171b90 bl 0x170f98 <_Z17GR_Surface_Createiii> */
/* @0x171b94 mvn r0, r0 */
/* @0x171b98 lsr r0, r0, #31 */
/* @0x171b9c pop {r4, r5, r6, pc} */

/* ── FUNC 0x171ba0 · GR_Surface_Free(int, bool) · size=196 · insn=49 */
/* @0x171ba0 cmp r1, #0 */
/* @0x171ba4 push {r4, r5, r6, lr} */
/* @0x171ba8 mov r5, r0 */
/* @0x171bac bne 0x171bc4 <_Z15GR_Surface_Freeib+0x24> */
/* @0x171bb0 ldr r3, [pc, #0xa4] */
/* @0x171bb4 ldr r3, [pc, r3] */
/* @0x171bb8 ldr r3, [r3] */
/* @0x171bbc cmp r3, r0 */
/* @0x171bc0 popeq {r4, r5, r6, pc} */
/* @0x171bc4 ldr r6, [pc, #0x94] */
/* @0x171bc8 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x171bcc mov r0, r5 */
/* @0x171bd0 bl 0x171a90 <_Z16_FreeSurfaceDatai> */
/* @0x171bd4 ldr r6, [pc, r6] */
/* @0x171bd8 ldr r1, [r6, #0x4] */
/* @0x171bdc ldr r2, [r6] */
/* @0x171be0 and r1, r5, r1 */
/* @0x171be4 ldr r4, [r2, r1, lsl #3] */
/* @0x171be8 add r12, r2, r1, lsl #3 */
/* @0x171bec cmp r4, #0 */
/* @0x171bf0 bne 0x171c04 <_Z15GR_Surface_Freeib+0x64> */
/* @0x171bf4 pop {r4, r5, r6, pc} */
/* @0x171bf8 ldr r4, [r4, #0x4] */
/* @0x171bfc cmp r4, #0 */
/* @0x171c00 beq 0x171c58 <_Z15GR_Surface_Freeib+0xb8> */
/* @0x171c04 ldr r3, [r4, #0x8] */
/* @0x171c08 cmp r5, r3 */
/* @0x171c0c bne 0x171bf8 <_Z15GR_Surface_Freeib+0x58> */
/* @0x171c10 ldr r3, [r4] */
/* @0x171c14 cmp r3, #0 */
/* @0x171c18 ldrne r2, [r4, #0x4] */
/* @0x171c1c ldreq r0, [r4, #0x4] */
/* @0x171c20 strne r2, [r3, #0x4] */
/* @0x171c24 ldrne r0, [r4, #0x4] */
/* @0x171c28 streq r0, [r2, r1, lsl #3] */
/* @0x171c2c cmp r0, #0 */
/* @0x171c30 streq r3, [r12, #0x4] */
/* @0x171c34 strne r3, [r0] */
/* @0x171c38 ldr r0, [r4, #0xc] */
/* @0x171c3c bl 0x27d1d0 <_ZdlPv> */
/* @0x171c40 mov r0, r4 */
/* @0x171c44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x171c48 ldr r3, [r6, #0x8] */
/* @0x171c4c sub r3, r3, #1 */
/* @0x171c50 str r3, [r6, #0x8] */
/* @0x171c54 pop {r4, r5, r6, pc} */
/* @0x171c58 pop {r4, r5, r6, pc} */
/* @0x171c5c eoreq r12, r7, r4, lsr #20 */
/* @0x171c60 eoreq r11, r7, r12, lsr pc */

/* ── FUNC 0x171c64 · GR_Surface_FreeAll() · size=300 · insn=75 */
/* @0x171c64 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x171c68 mov r3, #0 */
/* @0x171c6c ldr r6, [pc, #0x114] */
/* @0x171c70 ldr r6, [pc, r6] */
/* @0x171c74 ldm r6, {r2, r8} */
/* @0x171c78 b 0x171c84 <_Z18GR_Surface_FreeAllv+0x20> */
/* @0x171c7c cmp r8, r3 */
/* @0x171c80 blt 0x171d00 <_Z18GR_Surface_FreeAllv+0x9c> */
/* @0x171c84 ldr r4, [r2, r3, lsl #3] */
/* @0x171c88 mov r5, r3 */
/* @0x171c8c add r3, r3, #1 */
/* @0x171c90 cmp r4, #0 */
/* @0x171c94 beq 0x171c7c <_Z18GR_Surface_FreeAllv+0x18> */
/* @0x171c98 ldr r3, [r4, #0xc] */
/* @0x171c9c cmp r3, #0 */
/* @0x171ca0 bne 0x171cb4 <_Z18GR_Surface_FreeAllv+0x50> */
/* @0x171ca4 b 0x171d00 <_Z18GR_Surface_FreeAllv+0x9c> */
/* @0x171ca8 ldr r3, [r4, #0xc] */
/* @0x171cac cmp r3, #0 */
/* @0x171cb0 beq 0x171d80 <_Z18GR_Surface_FreeAllv+0x11c> */
/* @0x171cb4 ldr r0, [r3] */
/* @0x171cb8 bl 0x171a90 <_Z16_FreeSurfaceDatai> */
/* @0x171cbc ldr r4, [r4, #0x4] */
/* @0x171cc0 cmp r4, #0 */
/* @0x171cc4 bne 0x171ca8 <_Z18GR_Surface_FreeAllv+0x44> */
/* @0x171cc8 ldr r8, [r6, #0x4] */
/* @0x171ccc add r3, r5, #1 */
/* @0x171cd0 cmp r3, r8 */
/* @0x171cd4 bgt 0x171d00 <_Z18GR_Surface_FreeAllv+0x9c> */
/* @0x171cd8 ldr r2, [r6] */
/* @0x171cdc add r2, r2, r5, lsl #3 */
/* @0x171ce0 ldr r4, [r2, #0x8] */
/* @0x171ce4 mov r5, r3 */
/* @0x171ce8 add r2, r2, #8 */
/* @0x171cec add r3, r3, #1 */
/* @0x171cf0 cmp r4, #0 */
/* @0x171cf4 bne 0x171ca8 <_Z18GR_Surface_FreeAllv+0x44> */
/* @0x171cf8 cmp r3, r8 */
/* @0x171cfc ble 0x171ce0 <_Z18GR_Surface_FreeAllv+0x7c> */
/* @0x171d00 cmp r8, #0 */
/* @0x171d04 lslge r7, r8, #3 */
/* @0x171d08 movge r9, #0 */
/* @0x171d0c blt 0x171d68 <_Z18GR_Surface_FreeAllv+0x104> */
/* @0x171d10 ldr r3, [r6] */
/* @0x171d14 add r2, r3, r7 */
/* @0x171d18 ldr r4, [r3, r7] */
/* @0x171d1c str r9, [r3, r7] */
/* @0x171d20 cmp r4, #0 */
/* @0x171d24 str r9, [r2, #0x4] */
/* @0x171d28 beq 0x171d58 <_Z18GR_Surface_FreeAllv+0xf4> */
/* @0x171d2c ldr r5, [r4, #0x4] */
/* @0x171d30 ldr r0, [r4, #0xc] */
/* @0x171d34 bl 0x27d1d0 <_ZdlPv> */
/* @0x171d38 mov r0, r4 */
/* @0x171d3c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x171d40 ldr r3, [r6, #0x8] */
/* @0x171d44 cmp r5, #0 */
/* @0x171d48 mov r4, r5 */
/* @0x171d4c sub r3, r3, #1 */
/* @0x171d50 str r3, [r6, #0x8] */
/* @0x171d54 bne 0x171d2c <_Z18GR_Surface_FreeAllv+0xc8> */
/* @0x171d58 sub r8, r8, #1 */
/* @0x171d5c sub r7, r7, #8 */
/* @0x171d60 cmn r8, #1 */
/* @0x171d64 bne 0x171d10 <_Z18GR_Surface_FreeAllv+0xac> */
/* @0x171d68 ldr r3, [pc, #0x1c] */
/* @0x171d6c movw r2, #0xdead */
/* @0x171d70 movt r2, #0xfeee */
/* @0x171d74 ldr r3, [pc, r3] */
/* @0x171d78 str r2, [r3] */
/* @0x171d7c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x171d80 ldr r8, [r6, #0x4] */
/* @0x171d84 b 0x171d00 <_Z18GR_Surface_FreeAllv+0x9c> */
/* @0x171d88 eoreq r11, r7, r0, lsr #29 */
/* @0x171d8c eoreq r12, r7, r4, ror #16 */

/* ── FUNC 0x171d90 · GR_Surface_DrawSimple(int, float, float) · size=44 · insn=11 */
/* @0x171d90 push {r3, r4, r5, lr} */
/* @0x171d94 mov r5, r1 */
/* @0x171d98 mov r4, r2 */
/* @0x171d9c bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x171da0 cmp r0, #0 */
/* @0x171da4 popeq {r3, r4, r5, pc} */
/* @0x171da8 mov r1, r5 */
/* @0x171dac mov r2, r4 */
/* @0x171db0 ldr r0, [r0, #0x4] */
/* @0x171db4 pop {r3, r4, r5, lr} */
/* @0x171db8 b 0x174498 <_Z22GR_Texture_Draw_Simpleiff> */

/* ── FUNC 0x171dbc · GR_Surface_Draw(int, float, float, float, float, float, unsigned int, float) · size=112 · insn=28 */
/* @0x171dbc push {r4, r5, r6, lr} */
/* @0x171dc0 sub sp, sp, #24 */
/* @0x171dc4 mov r4, r1 */
/* @0x171dc8 mov r6, r2 */
/* @0x171dcc mov r5, r3 */
/* @0x171dd0 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x171dd4 cmp r0, #0 */
/* @0x171dd8 beq 0x171e20 <_Z15GR_Surface_Drawifffffjf+0x64> */
/* @0x171ddc vldr s14, [sp, #44] */
/* @0x171de0 vldr s15, [pc, #64] */
/* @0x171de4 vmul.f32 s15, s14, s15 */
/* @0x171de8 ldr r3, [sp, #0x30] */
/* @0x171dec mov r1, #0 */
/* @0x171df0 ldr r0, [r0, #0x4] */
/* @0x171df4 vldr s14, [sp, #40] */
/* @0x171df8 str r6, [sp] */
/* @0x171dfc vstr s14, [sp, #8] */
/* @0x171e00 str r3, [sp, #0x10] */
/* @0x171e04 vldr s14, [sp, #52] */
/* @0x171e08 str r5, [sp, #0x4] */
/* @0x171e0c vstr s14, [sp, #20] */
/* @0x171e10 mov r3, r4 */
/* @0x171e14 mov r2, r1 */
/* @0x171e18 vstr s15, [sp, #12] */
/* @0x171e1c bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf> */
/* @0x171e20 add sp, sp, #24 */
/* @0x171e24 pop {r4, r5, r6, pc} */
/* @0x171e28 vstmialo lr, {s30, s31} */

/* ── FUNC 0x171e2c · GR_Surface_DrawStretched(int, float, float, float, float, unsigned int, float) · size=180 · insn=45 */
/* @0x171e2c push {r4, r5, r6, lr} */
/* @0x171e30 vpush {d8} */
/* @0x171e34 sub sp, sp, #24 */
/* @0x171e38 vldr s17, [sp, #48] */
/* @0x171e3c mov r5, r1 */
/* @0x171e40 mov r6, r2 */
/* @0x171e44 vmov s16, r3 */
/* @0x171e48 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x171e4c cmp r0, #0 */
/* @0x171e50 beq 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8> */
/* @0x171e54 vcmpe.f32 s16, #0 */
/* @0x171e58 mov r12, #0 */
/* @0x171e5c vmrs APSR_nzcv, fpscr */
/* @0x171e60 bls 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8> */
/* @0x171e64 vcmpe.f32 s17, #0 */
/* @0x171e68 vmrs APSR_nzcv, fpscr */
/* @0x171e6c bls 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8> */
/* @0x171e70 ldr r4, [r0, #0x8] */
/* @0x171e74 cmp r4, #0 */
/* @0x171e78 ble 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8> */
/* @0x171e7c ldr r2, [r0, #0xc] */
/* @0x171e80 cmp r2, #0 */
/* @0x171e84 ble 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8> */
/* @0x171e88 vmov s13, r4 */
/* @0x171e8c ldr r0, [r0, #0x4] */
/* @0x171e90 ldr r3, [sp, #0x34] */
/* @0x171e94 mov r1, r12 */
/* @0x171e98 vcvt.f32.s32 s14, s13 */
/* @0x171e9c vldr s13, [sp, #56] */
/* @0x171ea0 vstr s13, [sp, #20] */
/* @0x171ea4 vmov s13, r2 */
/* @0x171ea8 str r3, [sp, #0x10] */
/* @0x171eac mov r2, r12 */
/* @0x171eb0 str r6, [sp] */
/* @0x171eb4 mov r3, r5 */
/* @0x171eb8 str r12, [sp, #0xc] */
/* @0x171ebc vcvt.f32.s32 s15, s13 */
/* @0x171ec0 vdiv.f32 s16, s16, s14 */
/* @0x171ec4 vdiv.f32 s17, s17, s15 */
/* @0x171ec8 vstr s16, [sp, #4] */
/* @0x171ecc vstr s17, [sp, #8] */
/* @0x171ed0 bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf> */
/* @0x171ed4 add sp, sp, #24 */
/* @0x171ed8 vpop {d8} */
/* @0x171edc pop {r4, r5, r6, pc} */

/* ── FUNC 0x171ee0 · YYGML_draw_surface_part_ext(int, float, float, float, float, float, float, float, float, int, float) · size=196 · insn=49 */
/* @0x171ee0 ldr r12, [pc, #0xb4] */
/* @0x171ee4 str lr, [sp, #-0x4]! */
/* @0x171ee8 ldr r12, [pc, r12] */
/* @0x171eec sub sp, sp, #36 */
/* @0x171ef0 ldm r12, {r12, lr} */
/* @0x171ef4 and lr, r0, lr */
/* @0x171ef8 ldr r12, [r12, lr, lsl #3] */
/* @0x171efc cmp r12, #0 */
/* @0x171f00 bne 0x171f14 <_Z27YYGML_draw_surface_part_extiffffffffif+0x34> */
/* @0x171f04 b 0x171f80 <_Z27YYGML_draw_surface_part_extiffffffffif+0xa0> */
/* @0x171f08 ldr r12, [r12, #0x4] */
/* @0x171f0c cmp r12, #0 */
/* @0x171f10 beq 0x171f80 <_Z27YYGML_draw_surface_part_extiffffffffif+0xa0> */
/* @0x171f14 ldr lr, [r12, #0x8] */
/* @0x171f18 cmp r0, lr */
/* @0x171f1c bne 0x171f08 <_Z27YYGML_draw_surface_part_extiffffffffif+0x28> */
/* @0x171f20 ldr r0, [r12, #0xc] */
/* @0x171f24 cmp r0, #0 */
/* @0x171f28 beq 0x171f80 <_Z27YYGML_draw_surface_part_extiffffffffif+0xa0> */
/* @0x171f2c ldr lr, [sp, #0x3c] */
/* @0x171f30 vldr s15, [sp, #40] */
/* @0x171f34 ldr r0, [r0, #0x4] */
/* @0x171f38 mov r12, #0 */
/* @0x171f3c vstr s15, [sp] */
/* @0x171f40 str r12, [sp, #0x14] */
/* @0x171f44 vldr s15, [sp, #44] */
/* @0x171f48 str lr, [sp, #0x18] */
/* @0x171f4c vstr s15, [sp, #4] */
/* @0x171f50 vldr s15, [sp, #48] */
/* @0x171f54 vstr s15, [sp, #8] */
/* @0x171f58 vldr s15, [sp, #52] */
/* @0x171f5c vstr s15, [sp, #12] */
/* @0x171f60 vldr s15, [sp, #56] */
/* @0x171f64 vstr s15, [sp, #16] */
/* @0x171f68 vldr s15, [sp, #64] */
/* @0x171f6c vstr s15, [sp, #28] */
/* @0x171f70 bl 0x175208 <_Z20GR_Texture_Draw_Partifffffffffjf> */
/* @0x171f74 mov r0, #1 */
/* @0x171f78 add sp, sp, #36 */
/* @0x171f7c ldr pc, [sp], #4 */
/* @0x171f80 ldr r0, [pc, #0x18] */
/* @0x171f84 mov r1, #0 */
/* @0x171f88 add r0, pc, r0 */
/* @0x171f8c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x171f90 mov r0, #0 */
/* @0x171f94 add sp, sp, #36 */
/* @0x171f98 ldr pc, [sp], #4 */
/* @0x171f9c eoreq r11, r7, r8, lsr #24 */
/* @0x171fa0 andseq r8, r12, r0, ror #5 */

/* ── FUNC 0x171fa4 · GR_Surface_DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=180 · insn=45 */
/* @0x171fa4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x171fa8 vpush {d8, d9, d10} */
/* @0x171fac sub sp, sp, #4 */
/* @0x171fb0 vldr s21, [sp, #64] */
/* @0x171fb4 mov r10, r1 */
/* @0x171fb8 mov r9, r2 */
/* @0x171fbc vldr s20, [sp, #68] */
/* @0x171fc0 mov r8, r3 */
/* @0x171fc4 vldr s19, [sp, #72] */
/* @0x171fc8 vldr s18, [sp, #76] */
/* @0x171fcc vldr s17, [sp, #80] */
/* @0x171fd0 vldr s16, [sp, #84] */
/* @0x171fd4 ldr r7, [sp, #0x58] */
/* @0x171fd8 ldr r6, [sp, #0x5c] */
/* @0x171fdc ldr r5, [sp, #0x60] */
/* @0x171fe0 ldr r4, [sp, #0x64] */
/* @0x171fe4 ldr r11, [sp, #0x68] */
/* @0x171fe8 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x171fec cmp r0, #0 */
/* @0x171ff0 beq 0x172048 <_Z22GR_Surface_DrawGeneralifffffffffjjjjf+0xa4> */
/* @0x171ff4 vldr s15, [pc, #88] */
/* @0x171ff8 vmul.f32 s16, s16, s15 */
/* @0x171ffc ldr r0, [r0, #0x4] */
/* @0x172000 mov r1, r10 */
/* @0x172004 vstr s21, [sp, #64] */
/* @0x172008 vstr s20, [sp, #68] */
/* @0x17200c vstr s19, [sp, #72] */
/* @0x172010 vstr s18, [sp, #76] */
/* @0x172014 vstr s17, [sp, #80] */
/* @0x172018 str r7, [sp, #0x58] */
/* @0x17201c str r6, [sp, #0x5c] */
/* @0x172020 mov r2, r9 */
/* @0x172024 str r5, [sp, #0x60] */
/* @0x172028 mov r3, r8 */
/* @0x17202c str r4, [sp, #0x64] */
/* @0x172030 str r11, [sp, #0x68] */
/* @0x172034 vstr s16, [sp, #84] */
/* @0x172038 add sp, sp, #4 */
/* @0x17203c vpop {d8, d9, d10} */
/* @0x172040 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x172044 b 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf> */
/* @0x172048 add sp, sp, #4 */
/* @0x17204c vpop {d8, d9, d10} */
/* @0x172050 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x172054 vstmialo lr, {s30, s31} */

/* ── FUNC 0x172058 · GR_Surface_DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) · size=140 · insn=35 */
/* @0x172058 push {r4, r5, r6, r7, r8, lr} */
/* @0x17205c sub sp, sp, #48 */
/* @0x172060 mov r4, r1 */
/* @0x172064 mov r8, r2 */
/* @0x172068 mov r7, r3 */
/* @0x17206c ldrb r6, [sp, #0x4c] */
/* @0x172070 ldrb r5, [sp, #0x50] */
/* @0x172074 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x172078 cmp r0, #0 */
/* @0x17207c beq 0x1720dc <_Z20GR_Surface_DrawTilediffffbbffffjf+0x84> */
/* @0x172080 ldr r3, [sp, #0x64] */
/* @0x172084 mov r1, #0 */
/* @0x172088 ldr r0, [r0, #0x4] */
/* @0x17208c vldr s15, [sp, #72] */
/* @0x172090 str r8, [sp] */
/* @0x172094 vstr s15, [sp, #8] */
/* @0x172098 str r3, [sp, #0x24] */
/* @0x17209c vldr s15, [sp, #84] */
/* @0x1720a0 str r7, [sp, #0x4] */
/* @0x1720a4 vstr s15, [sp, #20] */
/* @0x1720a8 str r6, [sp, #0xc] */
/* @0x1720ac vldr s15, [sp, #88] */
/* @0x1720b0 str r5, [sp, #0x10] */
/* @0x1720b4 vstr s15, [sp, #24] */
/* @0x1720b8 mov r3, r4 */
/* @0x1720bc vldr s15, [sp, #92] */
/* @0x1720c0 mov r2, r1 */
/* @0x1720c4 vstr s15, [sp, #28] */
/* @0x1720c8 vldr s15, [sp, #96] */
/* @0x1720cc vstr s15, [sp, #32] */
/* @0x1720d0 vldr s15, [sp, #104] */
/* @0x1720d4 vstr s15, [sp, #40] */
/* @0x1720d8 bl 0x175e90 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf> */
/* @0x1720dc add sp, sp, #48 */
/* @0x1720e0 pop {r4, r5, r6, r7, r8, pc} */
