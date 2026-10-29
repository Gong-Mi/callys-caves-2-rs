/* cally 逆向卡：DrawInstancesOnly（原版 libyoyo.so，armv7）
 * @func 0x1b0f50 0x1b1128  size 472  118 条（1b1114..1b1124 为 literal pool，5 字）
 * 级别: 骨架（118/118 锚定；单链遍历、可见性三连测、3D 字节门、事件派发、两条精灵输出路径、
 *             DrawSimple 五项判据与帧号截断逐条钉住。未钉：0x4859b0 为何能整体关掉 Set_Depth、
 *             本函数 DrawSimple 帧号用截断而另两个函数用 floorf 的原因）
 * 符号: _Z17DrawInstancesOnlyP9tagYYRECT → void DrawInstancesOnly(tagYYRECT* pRect)
 * 同层: DrawTheRoom 0x1b3b10（唯一调用者：瓦片数==0、实例数!=0、LargestDepth() <= -1e9；NaN 被 1b3e68 拉回慢路径）、
 *       DrawInstancesParticlesOnly 0x1b0b04（兄弟：同一实例块 + 粒子归并）、DoSlowDrawRoom 0x1b06a0（三路归并版）、
 *       CSprite::Draw 0x1ec720 / DrawSimple 0x1ecab4、Sprite_Data 0x1ef03c、
 *       CObjectGM::HasEventRecursive 0x19dcdc、Perform_Event 0xf3380、GR_3D_Set_Depth 0x1631dc
 *       GOT 基址 0x3F1C58（1b0f5c 的 0x00240cec + pc 1b0f6c）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   只画实例绘制链：从 room+0x84 起沿 +0x17c 走一遍，跳过不可见/非活动/无精灵的实例，
 *   按 HasEventRecursive 决定发 Draw 事件还是自己调 CSprite。不碰瓦片、粒子、房间背景，
 *   不调 Graphics::Flush，也不读形参 pRect —— 它与两个兄弟函数共享签名只为调用点统一。
 *
 * ── 与兄弟/慢路径的关系 ─────────────────────────────────────────
 *   本函数 = DrawInstancesParticlesOnly 的「无粒子」形态：同一段实例块，去掉粒子游标的取数与归并。
 *   逐条对照的结果（差异只有三处）：
 *     1) 起点：本函数直接读 room+0x84；ParticlesOnly 先 LargestDepth() 并用 -1e8 判空（本函数无此调用）。
 *     2) DrawSimple 帧号：本函数 vcvt.s32.f32 直接截断 [0x90]（1b10f8/1b10fc，全函数无 floorf 调用）；
 *        ParticlesOnly 与 DoSlowDrawRoom 都走 floorf@plt（0xb6910）。image_index 为负时两者结果不同
 *        （-1.5 → 本函数 -1，floorf 版 -2）。三处差异里只有这一处会改变绘制结果。
 *     3) 深度门：本函数与 ParticlesOnly 都被 3D 字节 0x4859b0 门控（为 0 时完全不调 GR_3D_Set_Depth）；
 *        DoSlowDrawRoom 无条件调。
 *   共同点（字段级逐条对齐，见下表）：room+0x84 头、+0x17c next、+0x180 depth、+0x65/+0x68/+0x69 三连测、
 *   +0x80 CObjectGM、+0x8c 精灵号、+0x90 image_index、+0x98/+0x9c/+0xa0/+0xa4/+0xa8 五个绘制量、
 *   +0xb4/+0xb8 x/y、g_drawInst 0x479cac、事件号 8、11000.0f 上限。
 *
 * ── CInstance 字段（本函数读到的）─────────────────────────────────
 *   +0x65 byte 可见（CInstance_ctor 卡：objflags bit1 → 0x65）；== 0 就跳过
 *   +0x68 byte 第二道跳过位（ctor 清零；语义未钉）      != 0 就跳过
 *   +0x69 byte 非活动（CRoom_DeSerialise / UpdateActive 卡）!= 0 就跳过
 *   +0x80 CObjectGM*（喂 HasEventRecursive）   +0x8c int 精灵号（喂 Sprite_Data）
 *   +0x90 float image_index   +0x98/+0x9c float 双轴缩放   +0xa0 float 角度
 *   +0xa8 uint32 blend（缺省 0x00FFFFFF）   +0xa4 float alpha
 *   +0xb4 float x   +0xb8 float y   +0x180 float depth   +0x17c CInstance* next
 *   ⚠ 全函数不读 +0x184（DeSerialise 存在那里的 depth 快照）、不读 +0x178（prev）。
 *
 * ── 三个全局 ───────────────────────────────────────────────────
 *   0x54298c CRoom**  &Run_Room   GOT 0x3ed930（1b0f60 槽号 0xffffbcd8，1b0f6c 取 [r3]）
 *   0x4859b0 byte     3D 模式位   GOT 0x3edd0c（1b0fe8 槽号 0xffffc0b4）：为 0 则跳过 Set_Depth
 *   0x479cac CInstance* g_drawInst GOT 0x3ed93c（1b0f90 / 1b103c 槽号 0xffffbce4）
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */
/* ── 帧 + 常量 + 取链头 ──────────────────────────────────────────────
 *   push {r4-r9,lr} + vpush {d8} + sub sp,#28（0x1c）。r0(pRect) 之后从未被读 —— 形参只为签名统一。
 *   literal 1b1114 = 0x462be000 = 11000.0f → s16（深度上限）；1b1118 = 0x00240cec（GOT 基址加数）；
 *   1b111c = 0xffffbcd8 → &Run_Room；1b1120 = 0xffffbce4 → g_drawInst；1b1124 = 0xffffc0b4 → 3D 位。
 *   s17 = 1.0f，r8 = 0（清 g_drawInst 用），r9 = 0x00FFFFFF（mvn #-16777216，blend 缺省值）。
 *   r4 = room->[0x84]（绘制链头）；为 0 直接退出。
 */

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

/* ── 常量就位 + 进循环 ──────────────────────────────────────────────────
 *   r8 = 0、r9 = 0x00FFFFFF、s16 = 11000.0f；b 1b0fc0 直接进循环头（跳过 1b0f90 的事件块）。
 */

/* @0x1b0f7c vmov.f32 s17, #1.000000e+00 */
/* @0x1b0f80 mov r8, #0 */
/* @0x1b0f84 mvn r9, #-16777216 */
/* @0x1b0f88 vldr s16, [pc, #388] */
/* @0x1b0f8c b 0x1b0fc0 <_Z17DrawInstancesOnlyP9tagYYRECT+0x70> */

/* ── 事件路径（HasEventRecursive 非 0 时跳到这里） ────
 *   r12 = 槽号 0xffffbce4；r7 = [r6,r12] = &g_drawInst（先存槽地址，r7 是 callee-saved，跨调用有效）；
 *   写 [r7] = inst → Perform_Event(inst, inst, 8, 0) → 写 [r7] = 0。
 *   ⚠ 与 DoSlowDrawRoom 的写法差别：那里 r7 被 GOT 基址占着，只能把槽地址压进 [sp+0x24] 再取回；
 *     本函数直接留在 r7 里，所以没有那句 str lr,[sp,#0x24]。语义相同：用后清零，不恢复旧值。
 */

/* @0x1b0f90 ldr r12, [pc, #0x188] */
/* @0x1b0f94 mov r0, r4 */
/* @0x1b0f98 mov r1, r4 */
/* @0x1b0f9c mov r2, #8 */
/* @0x1b0fa0 mov r3, #0 */
/* @0x1b0fa4 ldr r7, [r6, r12] */
/* @0x1b0fa8 str r4, [r7] */
/* @0x1b0fac bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1b0fb0 str r8, [r7] */

/* ── 推进/跳过：next 已在 1b0fc4 预取 ────────────────────────
 *   cmp r5,#0（next）：为 0 → 1b10b0 退出；否则 r4 = r5 回循环头。
 *   这是「跳过、事件后、画完后」三个出口的公共汇合点 —— 本函数只有这一个推进点。
 */

/* @0x1b0fb4 cmp r5, #0 */
/* @0x1b0fb8 beq 0x1b10b0 <_Z17DrawInstancesOnlyP9tagYYRECT+0x160> */
/* @0x1b0fbc mov r4, r5 */

/* ── 循环头 + 可见性三连测 ──────────────────────────────────────────────
 *   先取 r3 = inst->[0x68]、r5 = inst->[0x17c]（next 提前装好，测试失败也不用再读内存）。
 *   0x68 != 0 → 跳过；0x69 != 0 → 跳过；0x65 == 0 → 跳过。三者全过才画。
 *   ⇒ 顺序固定为 0x68 → 0x69 → 0x65，与 DoSlowDrawRoom 1b0710 起、ParticlesOnly 1b0bd4 起完全一致。
 */

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

/* ── 3D 字节门 + 深度钳位 ────────────────────────────────────────────
 *   r3 = [槽 0x3edd0c] = &0x4859b0；ldrb。为 0 → 直接跳 1b1014（**完全不设深度**）。
 *   非 0 → GR_3D_Set_Depth(min(inst->[0x180], 11000.0f))：vcmpe s15,s16 + vmovle/vmovgt 三连。
 *   ⇒ 2D 模式下实例深度一个字节都不写；这是与 DoSlowDrawRoom（无条件 Set_Depth）的实质差异。
 */

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

/* ── Draw 事件判定 ────────────────────────────────────────────────────
 *   HasEventRecursive(inst->[0x80], 8, 0)：非 0 → 1b0f90 发事件（不再走精灵自绘）；为 0 → 落 1b102c。
 *   事件号 8 = ev_draw，实参 (inst, inst, 8, 0)，与 DoSlow / ParticlesOnly 同形。
 */

/* @0x1b1014 ldr r0, [r4, #0x80] */
/* @0x1b1018 mov r1, #8 */
/* @0x1b101c mov r2, #0 */
/* @0x1b1020 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1b1024 cmp r0, #0 */
/* @0x1b1028 bne 0x1b0f90 <_Z17DrawInstancesOnlyP9tagYYRECT+0x40> */

/* ── 精灵路径：Sprite_Data + 置 g_drawInst + 第一道 DrawSimple 判据 ────
 *   Sprite_Data(inst->[0x8c])：返回 0 → 1b0fb4 只推进（该实例什么都不画）。
 *   r7 = &g_drawInst，写 [r7] = inst（在判据之前就写，两条输出路径共用同一次置位）。
 *   s15 = inst->[0x98]，与 1.0f 比较：不等 → 1b10bc 走全参 Draw；相等 → 继续测 [0x9c]。
 */

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

/* ── DrawSimple 判据续 + 全参 Draw 的准备 ──────────────
 *   [0x9c] 与 1.0f 比较：不等 → 落进 1b106c 的全参准备（s12 = [0xa4]，再汇合到 1b1074）。
 *   1b1074 起是两条路共用的传参段：s11 = (int)[0x90]（**截断**，无 floorf），r2 = x、r3 = y，
 *   栈上依次 [sp] = [0x98]、[sp+4] = [0x9c]、[sp+8] = [0xa0]、[sp+0xc] = [0xa8]、[sp+0x10] = [0xa4]。
 *   CSprite::Draw(i, x, y, a, b, c, blend, d)：按形参顺序 ⇒ 0x98/0x9c 双轴缩放、0xa0 角度、0xa8 blend、0xa4 alpha。
 */

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

/* ── 画完清 g_drawInst + 单一退出 ────────────────────────────
 *   cmp r5,#0；写 [r7] = 0；next 非 0 → 1b0fbc 继续，否则落 1b10b0：add sp / vpop {d8} / pop {r4-r9,pc}。
 *   ⇒ 无返回值、无 Graphics::Flush —— 刷新由外层 Draw_Room 负责。
 */

/* @0x1b10a4 cmp r5, #0 */
/* @0x1b10a8 str r8, [r7] */
/* @0x1b10ac bne 0x1b0fbc <_Z17DrawInstancesOnlyP9tagYYRECT+0x6c> */
/* @0x1b10b0 add sp, sp, #28 */
/* @0x1b10b4 vpop {d8} */
/* @0x1b10b8 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── 全参入口（[0x98] != 1.0 时从 1b1054 跳来） ──────
 *   重新装载 r12 = [0xa8]、s14 = [0x9c]、s13 = [0xa0]、s12 = [0xa4]，回 1b1074 共用传参段。
 *   1b10c8 是全参准备的第二个入口（[0xa0] != 0 时从 1b10dc 跳来，只补 s12）。
 */

/* @0x1b10bc ldr r12, [r4, #0xa8] */
/* @0x1b10c0 vldr s14, [r4, #156] */
/* @0x1b10c4 vldr s13, [r4, #160] */
/* @0x1b10c8 vldr s12, [r4, #164] */
/* @0x1b10cc b 0x1b1074 <_Z17DrawInstancesOnlyP9tagYYRECT+0x124> */

/* ── DrawSimple 后三道判据 + 截断帧号 ────────────────────────
 *   [0x9c] == 1.0 才到这里：再测 [0xa0] == 0（不等 → 全参）、[0xa8] == 0x00FFFFFF（不等 → 全参）、
 *   [0xa4] == 1.0（不等 → 全参）。四项全过才 DrawSimple(精灵, (int)[0x90], x, y)。
 *   ★ 帧号是 vldr s15,[r4,#144] + vcvt.s32.f32（1b10f8/1b10fc）：直接截断，**本函数没有 floorf 调用**；
 *     ParticlesOnly 1b0f2c 与 DoSlowDrawRoom 1b0acc 都是 bl floorf@plt 再 vcvt。负 image_index 时结果差 1。
 */

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

/* ── literal pool（1b1114..1b1124，5 字；1b1114/1b1118 被 objdump 译成指令，非指令） ────
 *   1b1114 = 0x462be000 = 11000.0f（深度上限）      1b1118 = 0x00240cec（GOT 基址加数）
 *   1b111c = 0xffffbcd8 → 0x3ed930 (&Run_Room)      1b1120 = 0xffffbce4 → 0x3ed93c (g_drawInst)
 *   1b1124 = 0xffffc0b4 → 0x3edd0c (0x4859b0 3D 位)
 */

/* @0x1b1114 strtmi lr, [r11], -r0 */
/* @0x1b1118 eoreq r0, r4, r12, ror #25 */
/* @0x1b111c .word 0xffffbcd8 */
/* @0x1b1120 .word 0xffffbce4 */
/* @0x1b1124 .word 0xffffc0b4 */

