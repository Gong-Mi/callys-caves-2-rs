/* cally 逆向卡：DrawTheRoom（原版 libyoyo.so，armv7）
 * @func 0x1b3b10 0x1b3e98  size 904  226 条（1b3e78..1b3e94 为 literal pool，8 字；前两字被 objdump 译成指令）
 * 级别: 骨架（226/226 锚定；profiler 进出、绘制矩形回写、三条清屏判据、8 槽背景的前后两轮、
 *             快/慢选路的完整条件树、四处 GR_3D_Set_Depth 常量、事件 72/73 全部逐条钉住。
 *             未钉：0x5428e8 与 0x4859b0 两个字节各自的清屏语义（名字借 Draw_Room 卡）、
 *             背景记录 44 B 的字段名（CRoom_DeSerialise 卡 open 1）、CBackground::DrawTiled 12 个形参的名字、
 *             eClearFlags 的位义（只证 6/7 两值）、CRoom+0x1c/+0x20 的正式名）
 * 符号: _Z11DrawTheRoomP9tagYYRECT → void DrawTheRoom(tagYYRECT* pRect)
 * 同层: Draw_Room 0x1b3e98（唯一调用者：每视图一次 / 无视图时一次）、DoSlowDrawRoom 0x1b06a0、
 *       DrawInstancesParticlesOnly 0x1b0b04、DrawInstancesOnly 0x1b0f50、DrawRoomLayers 0x1b3938、
 *       ExecuteDrawEvent 0x1b3544、DirtyRoomExtents 0x168d7c、Graphics::Clear 0x17eec4、
 *       GR_3D_Set_Depth 0x1631dc、ParticleSystem_LargestDepth 0x1a570c、
 *       Background_Exists 0xc3640 / Background_Data 0xc3794 / CBackground::DrawTiled 0xc22d8、
 *       CProfiler::Push 0x2a0738 / Pop 0x2a08ac
 *       GOT 基址 0x3F1C58（1b3b20 的 0x0023e12c + pc 0x1b3b2c）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   房间绘制的中间层（每视图一次，无返回值）：把 pRect 写进全局矩形 0x5425c0、按三个字节条件决定清屏、
 *   发 Draw Begin(72)，再在「房间前 / 房间后」两轮 8 槽背景之间选一条内容路径（图层 / 慢 / 两条快），
 *   最后 GR_3D_Set_Depth(-13000) 并补发 Draw End(73)。实例与瓦片的遍历全在被调函数里。
 *
 * ── 选路：完整条件树（本题重点；锚点从 1b3d14 起）─────────────────
 *   前提：**只有 room->[0xdc] <= 0 才可能走到选路**。room->[0xdc] > 0 时 1b3bc0 直接
 *   DrawRoomLayers(pRect) 与事件 73 后返回，1b3d14 之后整段（两轮 8 槽背景、三条内容路径、
 *   12000/-12000/-13000 三个深度）全不执行 ⇒ 「图层路径」与「快/慢选路」互斥。
 *
 *   1b3d14  d = ParticleSystem_LargestDepth()      ; 先取粒子游标，再读房间
 *   1b3d18  room = *(CRoom**)0x54298c              ; Run_Room（与 Draw_Room 同一来源）
 *   1b3d1c  tiles = room->[0xb8]                   ; 瓦片表条数（DeSerialise：+0xb8 计数 / +0xbc 容量 / +0xc0 基址 / 56 B）
 *   1b3d28  tiles != 0                  → DoSlowDrawRoom
 *   1b3d2c  insts = room->[0x88]                   ; 实例计数（DeSerialise 每条 +1）
 *   1b3d34  tiles == 0 && insts != 0    → 快路径二选一
 *   1b3d38  否则（两表皆空）             → DoSlowDrawRoom（仍旧慢）
 *
 *   快路径二选一（1b3e4c..1b3e74；literal 0xce6e6b28 = -1e9f 在 1b3e78）：
 *   1b3e50  vcmpe d, -1e9
 *   1b3e58  ble 1b3e68                ; d <= -1e9（以及 unordered）落到第二道判
 *   1b3e60  d >  -1e9  → DrawInstancesParticlesOnly
 *   1b3e68  bhi 1b3d38                ; 同一次比较再测「无符号更大」：NaN 命中这里 → 回慢路径
 *   1b3e70  其余（d < -1e9 或 d == -1e9）→ DrawInstancesOnly
 *   ⇒ 判据链 = 瓦片数 → 实例数 → 粒子游标，三个来源都是 CRoom / ParticleSystem 的状态；
 *     除了「取哪个 CRoom」用的 0x54298c，没有任何全局开关参与选路。
 *   ⚠ 两个哨兵不同值：本函数用 -1e9 判「有没有粒子」，而 DrawInstancesParticlesOnly 内部用
 *     -1e8（literal 0xccbebc20）判「粒子是否耗尽」，DoSlowDrawRoom 用的也是 -1e8。LargestDepth()
 *     落在 (-1e9, -1e8] 时本函数选 ParticlesOnly，而它进门就把自己判成无粒子、直接走实例尾段 ——
 *     阈值不一致是事实，可观测差异只剩 DrawSimple 帧号 floorf/截断那一条（见 claims open）。
 *   ⚠ 两表皆空仍走慢路径不是笔误：1b3d20 的 bne 落在 1b3d38，1b3d30 的 beq/bne 之外没有第三条出口。
 *
 * ── 全局（本函数碰到的；槽内值 = R_ARM_RELATIVE 目标）──────────────
 *   0x54298c  CRoom**    &Run_Room                          GOT 0x3ed930（1b3b60 / 1b3c00 / 1b3c4c）
 *   0x5425c0  int[4]     当前房间绘制矩形 = *pRect           GOT 0x3f0154（1b3b38；Draw_Room 卡同址）
 *   0x757e7c  byte       profiler 开关                      GOT 0x3edb70（1b3b1c，r9 常驻）
 *   0x757e80  CProfiler  profiler 实例（Push/Pop 的 this）    GOT 0x3edb74（1b3e40 / 1b3c20）
 *   0x4859b0  byte       3D 模式位                          GOT 0x3edd0c（1b3b4c，名字借 Draw_Room 卡）
 *   0x5428e8  byte       Zeus（调试器）在线                  GOT 0x3ed92c（1b3bec，名字借 Draw_Room 卡）
 *   0x479cac  CInstance* g_drawInst                         GOT 0x3ed93c（本函数不碰；被调的三条路径都写它）
 *
 * ── CRoom 字段（本函数读到的；与 DoSlowDrawRoom / CRoom_DeSerialise 卡同址）──
 *   +0x1c uint32 颜色   +0x20 byte 布尔（DeSerialise 流序：uint32 → bool）
 *   +0x24 + i*4（i=0..7）8 个背景记录指针，每记录 44 B（DeSerialise 卡）
 *   +0x88 int 实例计数   +0xb8 int 瓦片条数   +0xdc int 图层数
 *   背景记录 44 B 本函数读到的字段：+0x00 byte 启用、+0x01 byte 前景、+0x04 int 背景号（喂
 *   Background_Exists/Data）、+0x08/+0x0c/+0x1c/+0x20 float 位型（原样进 DrawTiled 前四参）、
 *   +0x10/+0x11 byte（两个 bool）、+0x24 uint、+0x28 float。字段名仍未定（DeSerialise 卡 open 1）。
 *
 * ── 深度布景：四处 GR_3D_Set_Depth，三个常量 ───────────────────────
 *   1b3c30/1b3c34  mov r0,#32768 + movt r0,#0x463b → 0x463B8000 =  12000.0f  房间前（背景）
 *   1b3d40/1b3d44  mov r0,#32768 + movt r0,#0xc63b → 0xC63B8000 = -12000.0f  房间后（前景）
 *   1b3e24/1b3e28  mov r0,#8192  + movt r0,#0xc64b → 0xC64B2000 = -13000.0f  收尾（事件 73 前）
 *   ⇒ 房间内容被夹在 12000 与 -12000 之间；DoSlowDrawRoom 的 11000 上限正好落在 12000 内侧。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */
/* ── 帧 + GOT 基址 + profiler 入口 ──────────────────────
 *   push {r4-r10,lr} + sub sp,#40（0x28）。r7 = pRect（全程只读，四次 ldr 取四边）。
 *   1b3b18 的 literal 1b3e7c = 0x0023e12c 加 pc(1b3b2c) = 0x3F1C58 = GOT 基址 → r8。
 *   1b3b20 的 literal 1b3e80 = 0xffffbf18 → 槽 0x3edb70 = &0x757e7c（profiler 开关）；r9 常驻该地址，
 *   出口 1b3bd8 要再读一次。非 0 → 1b3e34 Push(0x757e80, 6, 13) 后回 1b3b38。
 *   ⚠ 40 字节栈帧全部留给 DrawTiled 的 9 个栈参数（0x00..0x20 用满 0x24，余 4 字节对齐）：本函数没有局部变量。
 */

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

/* ── 绘制矩形回写 + DirtyRoomExtents ────────────────────
 *   1b3b38 的 literal 1b3e84 = 0xffffe4fc → 槽 0x3f0154 = &0x5425c0（Draw_Room 卡：当前房间绘制矩形 int[4]）。
 *   ldm r7,{r0-r3} 把 pRect 四字原样抄进 0x5425c0..0x5425cc（x1,y1,x2,y2），随后 DirtyRoomExtents()。
 *   ⇒ 后文画背景的几何仍从 r7 现取，但这四值已对外公开 —— 「当前正在画的矩形」只有一个真相。
 */

/* @0x1b3b38 ldr r12, [pc, #0x344] */
/* @0x1b3b3c ldm r7, {r0, r1, r2, r3} */
/* @0x1b3b40 ldr r12, [r8, r12] */
/* @0x1b3b44 stm r12, {r0, r1, r2, r3} */
/* @0x1b3b48 bl 0x168d7c <_Z16DirtyRoomExtentsv> */

/* ── 清屏第一判：3D 模式位 ──────────────────────────────────────────────
 *   literal 1b3e88 = 0xffffc0b4 → 槽 0x3edd0c = &0x4859b0（3D 模式位）。非 0 → 1b3b60；为 0 → 1b3bec 再问 Zeus。
 */

/* @0x1b3b4c ldr r3, [pc, #0x334] */
/* @0x1b3b50 ldr r3, [r8, r3] */
/* @0x1b3b54 ldrb r3, [r3] */
/* @0x1b3b58 cmp r3, #0 */
/* @0x1b3b5c beq 0x1b3bec <_Z11DrawTheRoomP9tagYYRECT+0xdc> */

/* ── 取房 + 颜色位：r0 = room->[0x20]，非 0 才取颜色 ────
 *   r6 = [槽 0x3ed930] = &Run_Room；r2 = [r6] = CRoom*。r3 = 2（清屏标志初值）。
 *   r0 = [room+0x20] byte：为 0 时 r0 就停在 0（后文当颜色用 = 0）；非 0 时 r0 = [room+0x1c] | 0xFF000000，
 *   并给标志补 bit0。⚠ 这一句已经解引用 room —— room==NULL 必崩，见 1b3bac 的死防御。
 */

/* @0x1b3b60 ldr r3, [pc, #0x324] */
/* @0x1b3b64 ldr r6, [r8, r3] */
/* @0x1b3b68 mov r3, #2 */
/* @0x1b3b6c ldr r2, [r6] */
/* @0x1b3b70 ldrb r0, [r2, #0x20] */
/* @0x1b3b74 cmp r0, #0 */
/* @0x1b3b78 beq 0x1b3b88 <_Z11DrawTheRoomP9tagYYRECT+0x78> */

/* ── 标志拼装 + 三实参 ──────────────────────────────────────────────────
 *   r3 |= 6（bit1|bit2；按调用点实参读作深度位 + 模板位）；r1 = 1065353216 = 1.0f（深度清除值）；r2 = 0（模板值）。
 *   颜色 + 1.0f + 0 + 标志 6/7 就是本函数对 eClearFlags 位义的全部证据（位义本身仍是推断）。
 */

/* @0x1b3b7c ldr r0, [r2, #0x1c] */
/* @0x1b3b80 orr r3, r3, #1 */
/* @0x1b3b84 orr r0, r0, #-16777216 */
/* @0x1b3b88 orr r3, r3, #6 */
/* @0x1b3b8c mov r1, #1065353216 */
/* @0x1b3b90 mov r2, #0 */

/* ── Graphics::Clear + Draw Begin(72) ──────
 *   Clear(color, 1.0f, 0, flags)，随后 ExecuteDrawEvent(pRect, 8, 72)。8 = ev_draw（Draw_Room 卡事件表）。
 */

/* @0x1b3b94 bl 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags> */
/* @0x1b3b98 mov r0, r7 */
/* @0x1b3b9c mov r1, #8 */
/* @0x1b3ba0 mov r2, #72 */
/* @0x1b3ba4 bl 0x1b3544 <_Z16ExecuteDrawEventP9tagYYRECTii> */

/* ── 图层路径：room->[0xdc] > 0 ⇒ DrawRoomLayers + 事件 73，然后直接返回 ────
 *   [room]==0 → 1b3c30；[room+0xdc] <= 0 → 1b3c30；否则 DrawRoomLayers(pRect) + 事件 73。
 *   再看 profiler 开关：非 0 → 1b3c1c（Pop 后返回），为 0 → 就地 add sp/pop 返回。
 *   ⇒ 这条路径不设 12000/-12000/-13000、不画 8 槽背景、不进 1b3d14：与下面整段互斥。
 *   ⚠ room==0 在 1b3bac 被显式放行，但走到这里必然已经在 1b3b70 / 1b3c0c 解引用过 room+0x20，
 *      所以这个空指针分支实际不可达；1b3c30 里还会再读 [r6] 与 [room+0x24+4i]，null 房必崩于 0x24。
 */

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

/* ── 第二条清屏判：Zeus 字节（三条内容路径都不读它） ──────────────────
 *   1b3bec 的 literal 1b3e90 = 0xffffbcd4 → 槽 0x3ed92c = &0x5428e8（Zeus 在线）。非 0 → 1b3b60（同一条清屏块）。
 *   为 0 → 1b3c00 直接读 room+0x20：
 *     · 非 0 → 跳进 1b3b7c，此时 r3 是刚读出的 Zeus 字节（必为 0），orr #1 → 1、orr #6 → 7 ⇒ flags 7；
 *     · 为 0 → 1b3b98，**不清屏**（不调 Clear，也不写深度）。
 *   ⇒ Clear 发生 ⇔ (3D 位 || Zeus || room->[0x20])；flags = 7 ⇔ room->[0x20]，否则 6；
 *     颜色 = 0xFF000000|room->[0x1c] ⇔ room->[0x20]，否则 0（r0 就是刚读到那个 0 字节）。
 *   ⚠ 编译器把「flags 种子 = 0」这条路径特化成 1b3b7c 入口，读卡时别把 r3 当成常量 2 一路带下来。
 */

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

/* ── profiler 出口（尾调 Pop） ────────────────────────────────
 *   r0 = [槽 0x3edb74] = 0x757e80（CProfiler 实例）；先 add sp/pop 再 b CProfiler::Pop —— 本函数无返回值。
 */

/* @0x1b3c1c ldr r3, [pc, #0x270] */
/* @0x1b3c20 ldr r0, [r8, r3] */
/* @0x1b3c24 add sp, sp, #40 */
/* @0x1b3c28 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b3c2c b 0x2a08ac <_ZN9CProfiler3PopEv> */

/* ── 深度 12000：房间之前 ────────────────────────────────────────────
 *   mov r0,#32768 + movt r0,#0x463b = 0x463B8000 = 12000.0f；r4 = 0（背景槽下标）；b 1b3c4c 进入第一轮。
 */

/* @0x1b3c30 mov r0, #32768 */
/* @0x1b3c34 movt r0, #0x463b */
/* @0x1b3c38 mov r4, #0 */
/* @0x1b3c3c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b3c40 b 0x1b3c4c <_Z11DrawTheRoomP9tagYYRECT+0x13c> */

/* ── 第一轮 8 槽背景（房间之前，深度 12000） ──────────────────────
 *   r5 = room->[0x24 + i*4]（44 B 背景记录；r4 先自增，r3 用的是自增前的 i）。
 *   跳过条件：bg->[0]==0；bg->[1] != 0（**前景位为 0 的才在这里画**）；Background_Exists(bg->[4])==0。
 *   ⚠ 记录指针 r5 没有判空 —— DeSerialise 恒建 8 条 44 B 记录，这里直接 ldrb [r5]。
 *   否则 Background_Data(bg->[4]) 当 this 调 DrawTiled。矩形取自 pRect：x1、y1、(x2-x1)、(y2-y1)，
 *   四次都用 vmov 搬位型再 vcvt.f32.s32。
 *   12 参落位（mangled Effffbbffffjf）：r0 = this，r1 = bg+0x08，r2 = bg+0x0c，r3 = bg+0x1c，
 *     [sp+0x00] = bg+0x20，[sp+0x04] = bg+0x10(bool)，[sp+0x08] = bg+0x11(bool)，
 *     [sp+0x0c] = (float)x1，[sp+0x10] = (float)y1，[sp+0x14] = (float)w，[sp+0x18] = (float)h，
 *     [sp+0x1c] = bg+0x24(uint)，[sp+0x20] = bg+0x28(float)。
 *   循环：1b3c44 判 i==8 → 1b3d14；1b3d0c 再判一次 i==8 后 bne 回 1b3c4c（双出口）。
 */

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

/* ── 选路（完整条件树见文件头） ────────────────────────────────────────────
 *   s15 = LargestDepth() 的返回值。tiles != 0 → 慢；tiles==0 且 insts != 0 → 快（二选一在 1b3e4c）；
 *   tiles==0 且 insts==0 → 落到 1b3d38 仍旧慢。tiles 用的条件码是 bne，insts 也是 bne —— 两个都为 0 时
 *   没人跳走，直落慢路径；两条路共用 1b3d3c 这一个 bl。
 */

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

/* ── 深度 -12000：房间之后 ──────────────────────────────────────────
 *   mov r0,#32768 + movt r0,#0xc63b = 0xC63B8000 = -12000.0f；r4 = 0；b 1b3d5c 进入第二轮。
 */

/* @0x1b3d40 mov r0, #32768 */
/* @0x1b3d44 movt r0, #0xc63b */
/* @0x1b3d48 mov r4, #0 */
/* @0x1b3d4c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b3d50 b 0x1b3d5c <_Z11DrawTheRoomP9tagYYRECT+0x24c> */
/* @0x1b3d54 cmp r4, #8 */
/* @0x1b3d58 beq 0x1b3e24 <_Z11DrawTheRoomP9tagYYRECT+0x314> */

/* ── 第二轮 8 槽背景（房间之后，深度 -12000） ────────────────────
 *   与第一轮逐指令同构（1b3d9c..1b3e18 的 32 条与 1b3c8c..1b3d08 完全相同，含 9 个栈参数落位），
 *   只有 +0x01 的判据方向相反：这里的两个 beq（1b3d70 / 1b3d80）意味着只画 bg->[1] != 0 的槽（同样不判空）。
 *   ⇒ 同一个 44 B 记录用 +0x01 把自己分流到「房间前」或「房间后」，两轮之间夹着全部房间内容。
 */

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

/* ── 深度 -13000 → Draw End(73) ──────────────────────
 *   mov r0,#8192 + movt r0,#0xc64b = 0xC64B2000 = -13000.0f；b 1b3bc8 = ExecuteDrawEvent(pRect,8,73) 后收尾。
 *   ⚠ 本函数 226 条里没有一处 Graphics::Flush（0x1852ec 不在调用表里）—— Flush 在 Draw_Room 里。
 */

/* @0x1b3e24 mov r0, #8192 */
/* @0x1b3e28 movt r0, #0xc64b */
/* @0x1b3e2c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b3e30 b 0x1b3bc8 <_Z11DrawTheRoomP9tagYYRECT+0xb8> */

/* ── profiler 入场（1b3b34 跳到这里） ──────────────────────
 *   r0 = [槽 0x3edb74] = 0x757e80；Push(this, 6, 13)；回 1b3b38。与 Draw_Room 的 (6,12)、
 *   UpdateActiveLists 的 (6,7) 同节区不同子项。
 */

/* @0x1b3e34 ldr r3, [pc, #0x58] */
/* @0x1b3e38 mov r1, #6 */
/* @0x1b3e3c mov r2, #13 */
/* @0x1b3e40 ldr r0, [r8, r3] */
/* @0x1b3e44 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1b3e48 b 0x1b3b38 <_Z11DrawTheRoomP9tagYYRECT+0x28> */

/* ── 快路径二选一（粒子游标 vs -1e9） ──────────────────────────────
 *   s14 = 0xce6e6b28 = -1e9f。vcmpe s15,s14 后：ble → 1b3e68（第二道判）；否则 1b3e5c → ParticlesOnly。
 *   1b3e68 是 bhi（C=1 && Z=0）：d < -1e9 时 C=0 不跳、d == -1e9 时 Z=1 不跳 → 都去 InstancesOnly；
 *   unordered（NaN）时 C=1,Z=0 → 跳回 1b3d38 = 慢路径。⇒ 这条 double-test 是 NaN 的兜底，不是冗余。
 */

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

/* ── literal pool（1b3e78..1b3e94，8 字；前两字被 objdump 译成指令，非指令） ────
 *   1b3e78 = 0xce6e6b28 = -1e9f（快路径判据哨兵）        1b3e7c = 0x0023e12c（GOT 基址加数）
 *   1b3e80 = 0xffffbf18 → 0x3edb70 (profiler 开关)       1b3e84 = 0xffffe4fc → 0x3f0154 (0x5425c0 矩形)
 *   1b3e88 = 0xffffc0b4 → 0x3edd0c (0x4859b0 3D 位)      1b3e8c = 0xffffbcd8 → 0x3ed930 (&Run_Room)
 *   1b3e90 = 0xffffbcd4 → 0x3ed92c (0x5428e8 Zeus)       1b3e94 = 0xffffbf1c → 0x3edb74 (0x757e80 profiler)
 */

/* @0x1b3e78 vmulgt.f64 d22, d14, d24 */
/* @0x1b3e7c eoreq lr, r3, r12, lsr #2 */
/* @0x1b3e80 .word 0xffffbf18 */
/* @0x1b3e84 .word 0xffffe4fc */
/* @0x1b3e88 .word 0xffffc0b4 */
/* @0x1b3e8c .word 0xffffbcd8 */
/* @0x1b3e90 .word 0xffffbcd4 */
/* @0x1b3e94 .word 0xffffbf1c */

