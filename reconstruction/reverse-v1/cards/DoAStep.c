/* cally 逆向卡：DoAStep（原版 libyoyo.so，armv7）
 * @func 0x1d32c0 0x1d3654  size 920  230 条（1d3614..1d3654 为 literal pool，17 字）
 * 级别: 正文（整条 step 管线、五段 GraphicsPerf 段名与其色值、时间基准两个 int64 全局、
 *             实例动画推进前后字段、13 处「退出码闸门」全部逐条锚定；未钉：
 *             CInstance +0x15c / +0x128 两个字段的语义名、Perform_Event_All(8,65) 的 65 是什么子事件、
 *             0x5429D0 这个 pending 标志由谁置位）
 * 符号: _Z7DoAStepv → void DoAStep(void)（mangled 里无返回值；本函数从不设 r0 返回）
 * 位置: 每步调用一次的主 step。本函数调 CRoom::UpdateLayers 0x1abfa0、Draw_Room 0x1b3e98、
 *       Instance_Animate 0x1d317c；同一帧的计时/限速在 DoFrameTiming 0x2903f8（另一张卡）；
 *       尾部 Command_EndGame 0x1c9f50 是尾调
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   不是「动画步进」，是整帧的 step 驱动：先结算时间差 → GC → IO/函数表 → Update 段
 *   （实例动画、事件、物理、粒子）→ Draw 段 → 授权自检 → Scroll 段 → 退出判定。
 *   实例的「动画步进」只占其中 1 条调用（Instance_Animate 0x1d317c，见下）。
 *
 * ── 时间基准（本函数开头，最先做的事）───────────────────────────
 *   GOT 0x3F0B78 → 0x5429F8（.bss, int64）：上一次的 now；本帧被写成 Timing_Time()
 *   GOT 0x3F0B7C → 0x542A00（.bss, int64）：本帧增量 = now - 旧值（strd r2,r3,[lr]）
 *   两个全局紧邻（0x5429F8 / 0x542A00），写 now 在算差值之前，寄存器里保留旧值
 *
 * ── 五段 GraphicsPerf 段名（.rodata 字符串 + 色值，全部实测）──────
 *   0xff808080 "Garbage Collector"  → MarkAndSweep(NULL)
 *   0xff00ff00 "IO&YoYo"            → IO_Start_Step + UpdateYoYoFunctions
 *   0xff0000ff "Update"             → 实例动画/事件/物理/粒子（本函数主体）
 *   0xFF00FFFF "Draw"               → CRoom::RemoveMarked + Draw_Room
 *   0xff008080 "Scroll"             → CRoom::ScrollBackground + 步计数自增
 *   （字符串地址：0x351084 / 0x351098 / 0x3510A0 / 0x3378EC / 0x3510A8）
 *
 * ── 「退出码闸门」同一段重复 13 次 ────────────────────────────
 *   UpdateActiveLists() 共 15 次，其中 13 次紧跟一段：r3 = *(int*)0x542954；cmn r3,#1；popne
 *   ⇒ 只有该值 == -1 才继续，其它值整帧返回（-1 = 运行中）。GOT 0x3EDDAC → 0x542954
 *   例外两次：Draw 段 1d3534（Draw_Room 之后）与 Scroll 段 1d358c，只刷新活动表、不查退出码
 *
 * ── 其余被读/写的全局（GOT 槽 → 目标地址）────────────────────────
 *   0x3F0B78 → 0x5429F8 int64 上次 now      0x3F0B7C → 0x542A00 int64 本帧 delta
 *   0x3EDD00 → 0x4859C8        RenderStateManager 单例本体（地址即 this）
 *   0x3ED930 → 0x54298C        全局 Run_Room（CRoom*）
 *   0x3EDDAC → 0x542954        step 退出码（-1 = 继续）
 *   0x3EE5CC → 0x542910 byte   Draw 段闸门：非 0 才调 Draw_Room
 *   0x3F0B5C → 0x544C5C        授权对象指针（为 0 则跳过自检）
 *   0x3F0848 → 0x542914 int    步计数（Scroll 段末自增）
 *   0x3F0B68 → 0x544B98        退出请求指针（非 0 → 尾调 Command_EndGame）
 *   0x5429D0 byte = pending-draw 标志（本函数只消费），0x5429D1 byte = 已自检标志
 *
 * ── 实例动画这一步到底动了什么（Instance_Animate 0x1d317c，81 条，另卡）──
 *   [+0x90] image_index += [+0x94] image_speed；过 GetImageNumber() 上界则减去帧数，
 *   下界 <0 则加回帧数，两端都 Perform_Event(inst,inst,7,7)（7 = ev_other，子事件 7 = Animation End）
 *   非 1:1 模式（全局字节非 0）时按 CTimingSource::GetFPS() 与 sprite[108] 缩放
 *   本函数只负责「每实例调一次」，不碰这些字段
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 时间结算 + 第一段 profiler（"Garbage Collector"）─────────────
 *   r12 = [GOT 0x3F0B78] = 0x5429F8（&上次 now）；lr = [0x3F0B7C] = 0x542A00（&delta）
 *   ldrd r4,r5,[r12] 取旧 now → 把 Timing_Time() 的结果 strd 回 [r12]
 *   subs/sbc 得到 now - 旧值 → strd 到 [lr]（增量先算后存，旧值来自寄存器）
 *   r1 = pc-relative 0x351084 = "Garbage Collector"，r0 = 0xff808080
 */

/* @0x1d32c0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1d32c4 bl 0x215148 <Timing_Time> */
/* @0x1d32c8 ldr r6, [pc, #0x344] */
/* @0x1d32cc ldr r12, [pc, #0x344] */
/* @0x1d32d0 add r6, pc, r6 */
/* @0x1d32d4 ldr lr, [pc, #0x340] */
/* @0x1d32d8 ldr r12, [r6, r12] */
/* @0x1d32dc ldr lr, [r6, lr] */
/* @0x1d32e0 ldrd r4, r5, [r12] */
/* @0x1d32e4 mov r3, r1 */
/* @0x1d32e8 ldr r1, [pc, #0x330] */
/* @0x1d32ec mov r2, r0 */
/* @0x1d32f0 movw r0, #0x8080 */
/* @0x1d32f4 add r1, pc, r1 */
/* @0x1d32f8 movt r0, #0xff80 */
/* @0x1d32fc strd r2, r3, [r12] */
/* @0x1d3300 subs r2, r2, r4 */
/* @0x1d3304 sbc r3, r3, r5 */
/* @0x1d3308 strd r2, r3, [lr] */
/* @0x1d330c bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* ── GC → 渲染状态 → 读档检查 ───────────────────────────────────
 *   MarkAndSweep(NULL)（r0=0 显式清空根），随后 GraphicsPerf::Pop
 *   RenderStateManager::Force()：r0 = [GOT 0x3EDD00] = 0x4859C8，单例对象地址直接当 this
 *   Check_LoadGameState()（0x1d0ed4，读档请求检查）
 */

/* @0x1d3310 mov r0, #0 */
/* @0x1d3314 bl 0xd6aac <_Z12MarkAndSweepP12YYObjectBase> */
/* @0x1d3318 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1d331c ldr r3, [pc, #0x300] */
/* @0x1d3320 ldr r0, [r6, r3] */
/* @0x1d3324 bl 0x168294 <_ZN18RenderStateManager5ForceEv> */
/* @0x1d3328 bl 0x1d0ed4 <_Z19Check_LoadGameStatev> */
/* ── 第二段 profiler "IO&YoYo"：IO_Start_Step + UpdateYoYoFunctions ──
 *   r0 = 0xff00ff00；字符串 pc-relative 0x351098
 */

/* @0x1d332c ldr r1, [pc, #0x2f4] */
/* @0x1d3330 mov r0, #65280 */
/* @0x1d3334 movt r0, #0xff00 */
/* @0x1d3338 add r1, pc, r1 */
/* @0x1d333c bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1d3340 bl 0x18d37c <_Z13IO_Start_Stepv> */
/* @0x1d3344 bl 0x15a0ac <_Z19UpdateYoYoFunctionsv> */
/* @0x1d3348 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* ── 第三段 profiler "Update"（主体段，直到 1d3500 才 Pop）─────────
 *   r0 = 0xff0000ff（mov #255 + movt #0xff00）；字符串 0x3510A0
 */

/* @0x1d334c ldr r1, [pc, #0x2d8] */
/* @0x1d3350 mov r0, #255 */
/* @0x1d3354 movt r0, #0xff00 */
/* @0x1d3358 add r1, pc, r1 */
/* @0x1d335c bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* ── 房间指针对齐 + pending-draw 闸门 ──────────────────────────
 *   r9 = [GOT 0x3ED930] = 0x54298C = &Run_Room；[r9] = CRoom*
 *   r3 = pc-relative 0x5429D0（.bss 字节）；r2 = *r3；r4 = [room+0x80]（步进链头）
 *   若 *0x5429D0 != 0 → 1d35c4：清标志 → room->RemoveMarked() →
 *       Perform_Event_All(8, 65) → room->RemoveMarked() → 回到实例循环
 *       （8 = ev_draw，与 DoSlowDrawRoom 的 HasEventRecursive(8,0) 同一常量；65 未钉）
 *   否则落到 1d3384：r4 == 0（房间没实例）→ 1d35e8（两个标志清零）
 */

/* @0x1d3360 ldr r2, [pc, #0x2c8] */
/* @0x1d3364 ldr r3, [pc, #0x2c8] */
/* @0x1d3368 ldr r9, [r6, r2] */
/* @0x1d336c add r3, pc, r3 */
/* @0x1d3370 ldrb r2, [r3] */
/* @0x1d3374 ldr r0, [r9] */
/* @0x1d3378 cmp r2, #0 */
/* @0x1d337c ldr r4, [r0, #0x80] */
/* @0x1d3380 bne 0x1d35c4 <_Z7DoAStepv+0x304> */
/* @0x1d3384 cmp r4, #0 */
/* @0x1d3388 beq 0x1d35e8 <_Z7DoAStepv+0x328> */
/* ── 实例步进循环前置：r7 = 0（喂 HandleInstanceMovement 的布尔），r8 = 0（时间线标志）── */

/* @0x1d338c mov r7, #0 */
/* @0x1d3390 mov r8, r7 */
/* ── 实例循环体：先存前值，再推进动画，再抽两个「有实例这么要求」的标志 ──
 *   r5 = [inst+0x178]（步进链 next，先取再动，允许动画里删实例）
 *   [inst+0xc8] = [inst+0xb8]（y → prev_y）
 *   [inst+0xc4] = [inst+0xb4]（x → prev_x）
 *   [inst+0x130] = [inst+0x12c]（未钉的一对标量，同名语义：前值）
 *   Instance_Animate(inst)：image_index(0x90) += image_speed(0x94)，越界回绕并抛 Animation End
 *   然后：byte[inst+0x15c] != 0 → r8 = 1；int[inst+0x128] >= 0 → r7 = 1
 *   两个字段哪来、谁的语义未钉；它们的用途见 1d3418（r8 → HandleTimeLine）与 1d3498（r7 → 移动）
 */

/* @0x1d3394 ldr r3, [r4, #0xb8] */
/* @0x1d3398 mov r0, r4 */
/* @0x1d339c ldr r2, [r4, #0xb4] */
/* @0x1d33a0 ldr r5, [r4, #0x178] */
/* @0x1d33a4 str r3, [r4, #0xc8] */
/* @0x1d33a8 ldr r3, [r4, #0x12c] */
/* @0x1d33ac str r2, [r4, #0xc4] */
/* @0x1d33b0 str r3, [r4, #0x130] */
/* @0x1d33b4 bl 0x1d317c <_Z16Instance_AnimateP9CInstance> */
/* @0x1d33b8 ldrb r2, [r4, #0x15c] */
/* @0x1d33bc ldr r3, [r4, #0x128] */
/* @0x1d33c0 mov r4, r5 */
/* @0x1d33c4 cmp r2, #0 */
/* @0x1d33c8 movne r8, #1 */
/* @0x1d33cc cmp r3, #0 */
/* @0x1d33d0 movge r7, #1 */
/* @0x1d33d4 cmp r5, #0 */
/* @0x1d33d8 bne 0x1d3394 <_Z7DoAStepv+0xd4> */
/* ── Update 段正文：图层 → Step(1) → 网络，每步后一次退出码闸门 ─────
 *   CRoom::UpdateLayers()（r0 = [r9] = 当前 CRoom）
 *   HandleStep(1)：三步以 1 / 0 / 2 调用，与 GM 的 Begin/Step/End Step 一致（此对应关系是推断，非本函数所证）
 *   UpdateActiveLists() → 若 *(int*)0x542954 != -1 则整帧返回
 */

/* @0x1d33dc ldr r0, [r9] */
/* @0x1d33e0 bl 0x1abfa0 <_ZN5CRoom12UpdateLayersEv> */
/* @0x1d33e4 mov r0, #1 */
/* @0x1d33e8 bl 0x1cdf6c <_Z10HandleStepi> */
/* @0x1d33ec bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d33f0 ldr r3, [pc, #0x240] */
/* @0x1d33f4 ldr r4, [r6, r3] */
/* @0x1d33f8 ldr r3, [r4] */
/* @0x1d33fc cmn r3, #1 */
/* @0x1d3400 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* ── ProcessNetworking() → 闸门 ──────────────────────────────── */

/* @0x1d3404 bl 0x29a764 <_Z17ProcessNetworkingv> */
/* @0x1d3408 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d340c ldr r3, [r4] */
/* @0x1d3410 cmn r3, #1 */
/* @0x1d3414 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* ── 时间线：任一实例 [+0x15c] != 0 才走 HandleTimeLine() ───────── */

/* @0x1d3418 cmp r8, #0 */
/* @0x1d341c bne 0x1d35f4 <_Z7DoAStepv+0x334> */
/* ── 警报 → 键盘 → 摇杆 → 鼠标，每条事件处理后面都挂同一闸门 ───────
 *   HandleAlarm() 1d3430 / HandleKeyboard() 1d3444 / HandleJoystick() 1d3458 /
 *   HandleMouse() 1d346c；每个 bl 之后都是 UpdateActiveLists + 退出码闸门
 */

/* @0x1d3420 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3424 ldr r3, [r4] */
/* @0x1d3428 cmn r3, #1 */
/* @0x1d342c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3430 bl 0x1cdd70 <_Z11HandleAlarmv> */
/* @0x1d3434 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3438 ldr r3, [r4] */
/* @0x1d343c cmn r3, #1 */
/* @0x1d3440 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3444 bl 0x1d5c3c <_Z14HandleKeyboardv> */
/* @0x1d3448 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d344c ldr r3, [r4] */
/* @0x1d3450 cmn r3, #1 */
/* @0x1d3454 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3458 bl 0x1dc75c <_Z14HandleJoystickv> */
/* @0x1d345c bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3460 ldr r3, [r4] */
/* @0x1d3464 cmn r3, #1 */
/* @0x1d3468 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d346c bl 0x1db7bc <_Z11HandleMousev> */
/* @0x1d3470 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3474 ldr r3, [r4] */
/* @0x1d3478 cmn r3, #1 */
/* @0x1d347c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* ── HandleStep(0)（三步里的中间档）→ 闸门 ─────────────────────── */

/* @0x1d3480 mov r0, #0 */
/* @0x1d3484 bl 0x1cdf6c <_Z10HandleStepi> */
/* @0x1d3488 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d348c ldr r3, [r4] */
/* @0x1d3490 cmn r3, #1 */
/* @0x1d3494 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* ── 实例位移：bMoved = HandleInstanceMovement(r7) ─────────────────
 *   形参就是 r7（任一实例 [+0x128] >= 0 的结果）→ 透传成 CPhysicsWorld::Update(int, bool)
 *   的第二参；物理世界为空时改走逐实例 Adapt_Speed/Adapt_Path + SetPosition(x+[0xe0], y+[0xe4])
 *   返回值 r5 决定后面要不要跑碰撞（1d34dc）
 */

/* @0x1d3498 mov r0, r7 */
/* @0x1d349c bl 0x1d1cec <_Z22HandleInstanceMovementb> */
/* @0x1d34a0 mov r5, r0 */
/* @0x1d34a4 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d34a8 ldr r3, [r4] */
/* @0x1d34ac cmn r3, #1 */
/* @0x1d34b0 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* ── HandleOther() → HandleAsyncEvents()，各自带闸门 ────────────── */

/* @0x1d34b4 bl 0x1ce594 <_Z11HandleOtherv> */
/* @0x1d34b8 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d34bc ldr r3, [r4] */
/* @0x1d34c0 cmn r3, #1 */
/* @0x1d34c4 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d34c8 bl 0x1ce38c <_Z17HandleAsyncEventsv> */
/* @0x1d34cc bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d34d0 ldr r3, [r4] */
/* @0x1d34d4 cmn r3, #1 */
/* @0x1d34d8 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* ── 碰撞闸门：HandleInstanceMovement 返回 0 才跑 HandleCollision ─── */

/* @0x1d34dc cmp r5, #0 */
/* @0x1d34e0 beq 0x1d35fc <_Z7DoAStepv+0x33c> */
/* ── HandleStep(2)（三步里的最后一档；= End Step 属推断）→ 粒子更新 → 关 Update 段 ──
 *   ParticleSystem_UpdateAll() 是 Update 段最后一条语句，随后 GraphicsPerf::Pop
 */

/* @0x1d34e4 mov r0, #2 */
/* @0x1d34e8 bl 0x1cdf6c <_Z10HandleStepi> */
/* @0x1d34ec bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d34f0 ldr r3, [r4] */
/* @0x1d34f4 cmn r3, #1 */
/* @0x1d34f8 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d34fc bl 0x1a4fbc <_Z24ParticleSystem_UpdateAllv> */
/* @0x1d3500 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* ── 第四段 profiler "Draw"：色值 0xFF00FFFF（mvn r0,#0x00FF0000）─── */

/* @0x1d3504 ldr r1, [pc, #0x130] */
/* @0x1d3508 mvn r0, #16711680 */
/* @0x1d350c add r1, pc, r1 */
/* @0x1d3510 bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* ── Draw 段：RemoveMarked → 条件 Draw_Room → 关段 ──────────────
 *   r3 = [GOT 0x3EE5CC] = 0x542910，ldrb 读第一字节；为 0 则跳过 Draw_Room()（只 UpdateActiveLists）
 */

/* @0x1d3514 ldr r0, [r9] */
/* @0x1d3518 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d351c ldr r3, [pc, #0x11c] */
/* @0x1d3520 ldr r3, [r6, r3] */
/* @0x1d3524 ldrb r3, [r3] */
/* @0x1d3528 cmp r3, #0 */
/* @0x1d352c beq 0x1d3538 <_Z7DoAStepv+0x278> */
/* @0x1d3530 bl 0x1b3e98 <_Z9Draw_Roomv> */
/* @0x1d3534 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* ── 授权自检（不在任何 profiler 段内）────────────────────────
 *   r3 = pc-relative 0x5429D0；byte[0x5429D1] != 0 → 已查过，跳过
 *   否则 r2 = [GOT 0x3F0B5C] = 0x544C5C，读 [0x544C5C] 这个指针；为 0 → 跳过
 *   否则把 0x5429D1 置 1 并调 CheckLicense()（只查一次的懒初始化）
 */

/* @0x1d3538 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1d353c ldr r3, [pc, #0x100] */
/* @0x1d3540 add r3, pc, r3 */
/* @0x1d3544 ldrb r2, [r3, #0x1] */
/* @0x1d3548 cmp r2, #0 */
/* @0x1d354c bne 0x1d3570 <_Z7DoAStepv+0x2b0> */
/* @0x1d3550 ldr r2, [pc, #0xf0] */
/* @0x1d3554 ldr r2, [r6, r2] */
/* @0x1d3558 ldr r2, [r2] */
/* @0x1d355c cmp r2, #0 */
/* @0x1d3560 beq 0x1d3570 <_Z7DoAStepv+0x2b0> */
/* @0x1d3564 mov r2, #1 */
/* @0x1d3568 strb r2, [r3, #0x1] */
/* @0x1d356c bl 0x1d23a0 <CheckLicense> */
/* ── 第五段 profiler "Scroll"：色值 0xff008080 ──────────────────── */

/* @0x1d3570 ldr r1, [pc, #0xd4] */
/* @0x1d3574 movw r0, #0x8080 */
/* @0x1d3578 movt r0, #0xff00 */
/* @0x1d357c add r1, pc, r1 */
/* @0x1d3580 bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1d3584 ldr r0, [r9] */
/* @0x1d3588 bl 0x1ac200 <_ZN5CRoom16ScrollBackgroundEv> */
/* @0x1d358c bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* ── Scroll 段：ScrollBackground → ++*(int*)0x542914 → 关段 ────── */

/* @0x1d3590 ldr r3, [pc, #0xb8] */
/* @0x1d3594 ldr r3, [r6, r3] */
/* @0x1d3598 ldr r2, [r3] */
/* @0x1d359c add r2, r2, #1 */
/* @0x1d35a0 str r2, [r3] */
/* @0x1d35a4 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* ── 退出判定：r3 = *(void**)0x544B98；为 0 直接返回，非 0 尾调 Command_EndGame()── */

/* @0x1d35a8 ldr r3, [pc, #0xa4] */
/* @0x1d35ac ldr r3, [r6, r3] */
/* @0x1d35b0 ldr r3, [r3] */
/* ── 尾调 Command_EndGame：pop 到 lr（不是 pc）再 b ───────────────
 *   弹出的是本函数自己的 8 个寄存器，lr 里仍是 DoAStep 的返回地址；
 *   Command_EndGame 结束时 ret 直接回调用方 —— 即「本帧结束后收尾」的尾调写法
 */

/* @0x1d35b4 cmp r3, #0 */
/* @0x1d35b8 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d35bc pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1d35c0 b 0x1c9f50 <_Z15Command_EndGamev> */
/* ── pending-draw 实体：清标志、RemoveMarked、Perform_Event_All(8,65)、再 RemoveMarked ──
 *   两次 RemoveMarked 夹着一次「对全部实例发事件」，像「删干净后重排」的场景；
 *   65 这个子事件常量未钉（DoSlowDrawRoom 用的是 8/0）
 *   ★ 注意 r4（步进链头）在 1d337c 就已取出，这一段跑完不会重读 room+0x80，
 *     所以 pending 事件里新建/销毁的实例不改变本帧随后遍历的那条链
 */

/* @0x1d35c4 mov r2, #0 */
/* @0x1d35c8 strb r2, [r3] */
/* @0x1d35cc bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d35d0 mov r0, #8 */
/* @0x1d35d4 mov r1, #65 */
/* @0x1d35d8 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1d35dc ldr r0, [r9] */
/* @0x1d35e0 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d35e4 b 0x1d3384 <_Z7DoAStepv+0xc4> */
/* ── 没有实例：两个标志都清零（跳过循环直接进 UpdateLayers）────────── */

/* @0x1d35e8 mov r7, r4 */
/* @0x1d35ec mov r8, r4 */
/* @0x1d35f0 b 0x1d33dc <_Z7DoAStepv+0x11c> */
/* ── HandleTimeLine()（由 r8 触发）后回到 1d3420 ──────────────── */

/* @0x1d35f4 bl 0x1d00b4 <_Z14HandleTimeLinev> */
/* @0x1d35f8 b 0x1d3420 <_Z7DoAStepv+0x160> */
/* ── HandleCollision() + 闸门，之后并回 1d34e4（HandleStep(2)）─── */

/* @0x1d35fc bl 0x1cc500 <_Z15HandleCollisionv> */
/* @0x1d3600 bl 0x1d30a4 <_Z17UpdateActiveListsv> */
/* @0x1d3604 ldr r3, [r4] */
/* @0x1d3608 cmn r3, #1 */
/* @0x1d360c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d3610 b 0x1d34e4 <_Z7DoAStepv+0x224> */
/* ── literal pool（1d3614..0x1d3654，17 字；前几条被 objdump 译成指令，非指令）──
 *   1d3614 = 0x0021e980  GOT 基址差（+pc 得 0x3F1C58）
 *   1d3618 = 0xffffef20 → GOT 0x3F0B78 → 0x5429F8（&上次 now）
 *   1d361c = 0xffffef24 → GOT 0x3F0B7C → 0x542A00（&delta）
 *   1d3620/1d3628/1d362c/1d363c/1d364c = 字符串 pc 相对量（"Garbage Collector"/"IO&YoYo"/"Update"/"Draw"/"Scroll"）
 *   1d3624 = 0xffffc0a8 → 0x4859C8（RenderStateManager 单例）
 *   1d3630 = 0xffffbcd8 → 0x54298C（&Run_Room）      1d3634 = 0x0036f65c → 0x5429D0（pending 标志）
 *   1d3638 = 0xffffc154 → 0x542954（退出码）          1d3640 = 0xffffc974 → 0x542910（Draw 闸门）
 *   1d3644 = 0x0036f488 → 0x5429D0（授权自检标志基址）1d3648 = 0xffffef04 → 0x544C5C（授权对象）
 *   1d3650 = 0xffffebf0 → 0x542914（步计数）          1d3654 = 0xffffef10 → 0x544B98（退出请求）
 */

/* @0x1d3614 eoreq lr, r1, r0, lsl #19 */
/* @0x1d3618 .word 0xffffef20 */
/* @0x1d361c .word 0xffffef24 */
/* @0x1d3620 andseq sp, r7, r8, lsl #27 */
/* @0x1d3624 .word 0xffffc0a8 */
/* @0x1d3628 andseq sp, r7, r8, asr sp */
/* @0x1d362c andseq sp, r7, r0, asr #26 */
/* @0x1d3630 .word 0xffffbcd8 */
/* @0x1d3634 eorseq pc, r6, r12, asr r6 */
/* @0x1d3638 .word 0xffffc154 */
/* @0x1d363c ldrsbeq r4, [r6], -r8 */
/* @0x1d3640 .word 0xffffc974 */
/* @0x1d3644 eorseq pc, r6, r8, lsl #9 */
/* @0x1d3648 .word 0xffffef04 */
/* @0x1d364c andseq sp, r7, r4, lsr #22 */
/* @0x1d3650 .word 0xffffebf0 */
/* @0x1d3654 .word 0xffffef10 */
