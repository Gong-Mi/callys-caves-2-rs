/* cally 逆向卡：Draw_Room（原版 libyoyo.so，armv7）
 * @func 0x1b3e98 0x1b4a24  size 2960  740 条（1b4988..1b4a24 为 literal pool，40 字，被 objdump 译成指令的也是池词）
 * 级别: 骨架（740/740 锚定；外层流程、8 视图环、事件常量、房间表面四道开关的读写点、
 *             GUI 段、profiler 进出、表面栈检错全部逐条钉住。未钉：0x3f50f0/f1/fc/b0 四个字节的正式名、
 *             0x3f5108 与 0x3f510c 孰宽孰高、0x3f5104/0x3f5100 的写入者、GUI 那颗精灵的用途、
 *             0x3f23bd 与 0x7530c9 两个字节的语义）
 * 符号: _Z9Draw_Roomv → void Draw_Room()
 * 同层: DrawTheRoom 0x1b3b10（快/慢选路真正发生的地方，226 条）、DoSlowDrawRoom 0x1b06a0、
 *       DrawInstancesParticlesOnly 0x1b0b04、DrawInstancesOnly 0x1b0f50、DrawRoomLayers 0x1b3938、
 *       CRoom::SortTiles 0x1af3f4、Draw_Room_SetSize 0x1b29bc、UpdateViews 0x1b0164、
 *       ExecuteDrawEvent 0x1b3544、ExecutePreDrawEvent 0x1b3718、SetGuiView 0x1b3330、
 *       UpdateDefaultCamera 0x1aff1c、RenderSurface_AspectAdjusted 0x1b2bb8、
 *       Graphics::Flush 0x1852ec / Clear 0x17eec4 / SetMatrix 0x17eb1c、
 *       GR_D3D_Set_View_Port 0x168cd8 / View_Area 0x169408、GR_3D_Set_Mode 0x163170 / Set_Depth 0x1631dc、
 *       CSprite::Draw 0x1ec720 / Sprite_Data 0x1ef03c、CProfiler::Push 0x2a0738 / Pop 0x2a08ac、Error_Show 0xecd7c
 *       Run_Room 在 .bss 0x54298c；GOT 基址 0x3F1C58（1b4988 的 0x0023dda4 + pc 0x1b3eb4，非负的那个加数就是它）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   每帧房间绘制的唯一外层入口（无参无返回）：先把「渲染目标 + 视口 + 相机 + 缩放系数」摆好，
 *   再按 room->[0x44]（有无视图）走「8 个视图各画一次」或「整屏画一次」，每次都只调 DrawTheRoom(rect)；
 *   之后跑 Post-Draw、表面栈检错、GUI 三事件和一颗 GUI 精灵，退出前把强改过的全局逐一写回。
 *   它自己不做任何「画什么」的决定 —— 连房间指针都是每次现从 Run_Room 取。
 *
 * ── 选路：快路径 / DoSlowDrawRoom（本题重点）──────────────────────
 *   本函数不含这个判断，一次也没有直接调 DoSlowDrawRoom / DrawInstancesOnly /
 *   DrawInstancesParticlesOnly（0x1b3e98..0x1b4a24 全表没有这三个目标），也从不读 +0xb8/+0x88。
 *   它只在两处（1b41a0 视图环内、1b4840 无视图）把矩形交给 DrawTheRoom，选路全在 DrawTheRoom 里：
 *     1b3d18  r3 = *(CRoom**)0x54298c          ; Run_Room —— 与本函数 1b4100/1b41e0 同一个来源
 *     1b3d1c  r2 = r3->[0xb8]                  ; 层项条数（DoSlowDrawRoom 用的那个层项数组条数）
 *     1b3d28  bne → 1b3d38                     ; 条数 != 0 ⇒ 慢路径
 *     1b3d2c  r3 = r3->[0x88]                  ; 实例计数（CRoom::DeSerialise 每条实例 +1，见 1acd68）
 *     1b3d34  bne → 1b3e4c                     ; 条数 == 0 且实例数 != 0 ⇒ 快路径
 *     两条都不满足（0xb8==0 且 0x88==0）→ 落到 1b3d38，仍旧慢路径
 *   快路径内部再按粒子游标分两支（1b3e4c 起，哨兵是 literal 0xce6e6b28 ≈ -1e9，池地址 1b3e78）：
 *     LargestDepth() >  -1e9 ⇒ DrawInstancesParticlesOnly 0x1b0b04
 *     LargestDepth() <= -1e9 ⇒ DrawInstancesOnly 0x1b0f50（NaN 由 1b3e68 的 bhi 拉回慢路径）
 *   两条专用函数都只走 room->[0x84] 的实例绘制链（1b0b2c / 1b0f70），完全不碰 +0xb8/+0xc0 层项。
 *   ⇒ 选路依据是 CRoom 的字段，不是任何全局开关；全局只提供 CRoom*（*0x54298c）和几条旁路
 *     （Zeus 字节 0x5428e8、3D 模式字节 0x4859b0、房间表面四道开关）。二进制里没有名为 FastDraw 的符号
 *     （functions.tsv 全表 fast 只有 Buffer_Fast / ShouldUseFastCollision / InitFastCRC / jpeg_idct_ifast），
 *     「快路径」就是上面那两条 Draw*Only。
 *   ⚠ 最容易认错的一处：CRoom+0xdc 在 1b410c 是「非 0 就跳过 CRoom::SortTiles」，在 DrawTheRoom 里是
 *     「> 0 才 DrawRoomLayers」。它管图层/平铺，不是快慢选路。
 *   ⚠ 第二处：本函数确实有「先画进离屏表面再整块贴回」的一条链（0x3f50f0 生效位），那是渲染目标的
 *     选择，与 DrawTheRoom 内的快/慢是两件事，不要混为一谈。
 *
 * ── CRoom 字段（本函数读到的；与 DoSlowDrawRoom 卡同址）──────────────
 *   +0x10 int 房间宽   +0x14 int 房间高（1b4800/1b4804、1b4930，无视图时当 View_Area 用）
 *   +0x44 byte 有视图（0 ⇒ 只画一次全屏，1b4128）
 *   +0x45 byte 画前用窗口底色清屏（1b413c）
 *   +0x46 byte 决定 Pre-Draw 的 bool 实参（1b40b0）
 *   +0x48 + i*4  视图项指针数组，i=0..7（1b41e4：r2 = i+18，lsl #2）
 *   +0xdc int 图层数（!=0 ⇒ 跳过旧式 SortTiles；DrawTheRoom 侧用 >0 判有无图层）
 *   +0x84 绘制链头 / +0x88 实例计数 / +0xb8 层项条数 / +0xc0 层项基址：本函数一律不读，
 *         但它们是 DrawTheRoom 选路的全部依据（见上节）
 *
 * ── 视图项（room->[0x48 + i*4] 指向的对象）────────────────────────
 *   +0x00 byte 启用          +0x04,+0x08,+0x0c,+0x10  四个 int：视区 x,y,w,h（1b4298 起）
 *   +0x14,+0x18,+0x1c,+0x20 四个 int：视口矩形（1b4238 起，乘两个 float 全局后截断）
 *   +0x24 int/float Set_View_Area 的第 5 个 float（1b4298 取、1b42ac 压栈）
 *   +0x3c int 视图专用表面号（-1 = 无，1b4200 用 cmn r0,#1 判）
 *   +0x40 int 相机号（仅 Zeus 路径，1b4160）
 *
 * ── 事件常量（8 = ev_draw）──────────────────────────────────────
 *   本函数发：76 Pre-Draw（1b40d8/1b46c8）、77 Post-Draw（1b43ac）、74 GUI Begin、64 Draw GUI、
 *   75 GUI End（1b4440/1b4470/1b4480）。DrawTheRoom 侧发 72 Draw Begin / 73 Draw End。
 *
 * ── 全局表（本函数碰到的；槽内值 = R_ARM_RELATIVE 目标，.data 初值一并记下）──
 *   0x54298c  CRoom**   &Run_Room                              GOT 0x3ed930
 *   0x757e7c  byte      profiler 开关（非 0 才 Push/Pop）       GOT 0x3edb70
 *   0x757e80  CProfiler CProfiler 实例（Push/Pop 的 this）      GOT 0x3edb74  与 UpdateActiveLists 卡同址
 *   0x3f50f0  byte      表面模式「生效」位                      GOT 0x3f02fc  初值 1
 *   0x3f50f1  byte      表面模式「请求」位（为 0 触发拆表面）    GOT 0x3efb50  初值 1
 *   0x3f50f4  int       改尺寸请求 A（侧别见 open 2）            GOT 0x3ee5ec  初值 -1
 *   0x3f50f8  int       改尺寸请求 B                             GOT 0x3ee5e8  初值 -1
 *   0x3f5100  int       视口备份 B（侧别见 open 2）               GOT 0x3efb9c  初值 -1
 *   0x3f5104  int       视口备份 A                             GOT 0x3efb94  初值 -1
 *   0x3f5108  int       房间表面尺寸缓存 B                     GOT 0x3efb98  初值 -1
 *   0x3f510c  int       房间表面尺寸缓存 A                     GOT 0x3efb90  初值 -1
 *   0x3f5110  int       房间表面号                             GOT 0x3ee5e0  初值 0xFEEEDEAD（无效哨兵）
 *   0x3f2420  int       表面尺寸副本 B（按 Create 顺序 = 高）    GOT 0x3f02e4  初值 480
 *   0x3f2424  int       表面尺寸副本 A（按 Create 顺序 = 宽）    GOT 0x3f02e0  初值 640
 *   0x3f26bc  int       屏幕高                                 GOT 0x3efea8  初值 768
 *   0x3f26c0  int       屏幕宽                                 GOT 0x3efea4  初值 1024
 *   0x3f50b0  byte      回贴方式开关（0 = DrawStretched，非 0 = AspectAdjusted）GOT 0x3f084c 初值 1
 *   0x3f50fc  byte      是否把离屏表面回贴到屏幕                 GOT 0x3efb8c  初值 1
 *   0x3f50d4  float     视图缩放 Y（房间绘制期强制 1.0）         GOT 0x3f031c  初值 1.0f
 *   0x3f50d8  float     视图缩放 X                              GOT 0x3f0314  初值 1.0f
 *   0x3f23bd  byte      被 Set_Mode 段保存/写回的字节            GOT 0x3f0108
 *   0x3f243c  byte      RenderSurface_AspectAdjusted 的第 7 实参  GOT 0x3f0130
 *   0x4859b0  byte      3D 模式位（同时是 GR_3D_Set_Mode 的实参） GOT 0x3edd0c
 *   0x48ffac  int       表面栈深度（set_target_ext 里以 496 为上限）GOT 0x3f026c
 *   0x48f78c  CCameraManager 单例                               GOT 0x3edc7c
 *   0x499309  byte      AspectAdjusted 的第 6 实参               GOT 0x3f02f8
 *   0x542560  byte      「正在建表面」标志                       GOT 0x3f0840
 *   0x5425a4  byte      Zeus 路径的 GUI 段标志（置 1 期间跑 GUI 事件）GOT 0x3efb88
 *   0x5425c0  int[4]    当前房间绘制矩形（DrawTheRoom 开头回写）  GOT 0x3f0154
 *   0x5428e8  byte      Zeus（调试器）在线                    GOT 0x3ed92c  与 DoBreak/Instance_Animate 卡同址
 *   0x5428ec  void*     本视图重定向到的表面（0 = 未重定向）      GOT 0x3f0844
 *   0x5428f0  byte      改尺寸请求                           GOT 0x3ee5e4
 *   0x542914  int       GUI 精灵帧号（DoAStep 卡：步计数）        GOT 0x3f0848
 *   0x542918  int       GUI 精灵号（喂 Sprite_Data）             GOT 0x3ef3f0
 *   0x542920  int       当前视图号                             GOT 0x3ee5d8
 *   0x534664  int       GUI 精灵 y                             GOT 0x3efba0
 *   0x53468c  int       GUI 精灵 x                             GOT 0x3efba4
 *   0x7530c9  byte      画 GUI 精灵前后保存/置位的字节            GOT 0x3f00e8
 *   0x34d2ac  char[]    "Unbalanced surface stack. You MUST use surface_r…"（1b4a18 的 0x198bc0 + pc 1b46ec）
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 帧 + GOT 基址 + profiler 入口 ────────────────────────────────
 *   push {r4-r11,lr} + vpush {d8}（只用到 d8）+ sub sp,#148。148 字节的分区：
 *     +0x00..+0x10 CSprite::Draw 的栈上传参   +0x1c..+0x38 八个「全局地址」
 *     +0x40..+0x4c 本地 tagYYRECT（也当全屏视口备份）  +0x50..+0x8c GUI 段的 4x4 矩阵
 *     +0x3c 清屏标志  +0x20 当前视图号地址  +0x24 3D 位地址  +0x28 表面生效位地址
 *   1b3ea4 的 0x0023dda4 + pc(1b3eb4) = 0x3F1C58 = GOT 基址，之后全部全局都走 ldr rX,[r4,负偏移]。
 *   [sp+0x38] = 0x757e7c；字节非 0 → 1b4714 CProfiler::Push(0x757e80, 6, 12)。
 *   本函数是 (6,12)，DrawTheRoom 是 (6,13)，UpdateActiveLists 是 (6,7) —— 同节区不同子项。
 */

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

/* ── 第一道闸：0x3f50f1 == 0 ⇒ 先拆掉房间表面 ─────────────────────
 *   r5 = 0x3f50f1（请求位，.data 初值 1）；为 0 走 1b472c：把表面尺寸缓存重置成屏幕尺寸、
 *   若 GR_Surface_Exists(0x3f5110) 则 GR_Surface_Free，并把表面号写回哨兵 0xFEEEDEAD。
 *   ⚠ r5 在这里装的是「请求位地址」，到 1b4000 会被覆盖成 0x4859b0 的字节值 —— 同名不同物。
 */

/* @0x1b3ec4 ldr r3, [pc, #0xac4] */
/* @0x1b3ec8 ldr r5, [r4, r3] */
/* @0x1b3ecc ldrb r3, [r5] */
/* @0x1b3ed0 cmp r3, #0 */
/* @0x1b3ed4 beq 0x1b472c <_Z9Draw_Roomv+0x894> */

/* ── 第二道闸：生效位 0x3f50f0 != 0 ⇒ 跳过「存视口」────────────────
 *   从此刻起 [sp+0x28] 固定指向 0x3f50f0，后面 1b40f4 / 1b464c / 1b4788 都在用它。
 *   首帧请求位刚置 1 时生效位仍是 0 ⇒ 会走一次存视口，然后才建表面；之后每帧跳过。
 */

/* @0x1b3ed8 ldr r3, [pc, #0xab4] */
/* @0x1b3edc ldr r3, [r4, r3] */
/* @0x1b3ee0 str r3, [sp, #0x28] */
/* @0x1b3ee4 ldrb r3, [r3] */
/* @0x1b3ee8 cmp r3, #0 */
/* @0x1b3eec bne 0x1b3f20 <_Z9Draw_Roomv+0x88> */
/* ── 存视口：0x3f5104→0x3f510c、0x3f5100→0x3f5108（各 4 字节）─────
 *   只是搬运，不判断宽高；四个地址的 .data 初值都是 -1。
 */

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

/* ── 房间表面存在性：id<0 或 GR_Surface_Exists(id)==0 ⇒ 重建 ────────
 *   id 在 0x3f5110（初值 0xFEEEDEAD）；[sp+0x34] 从此刻起 = &id。
 */

/* @0x1b3f20 ldr r3, [pc, #0xa80] */
/* @0x1b3f24 ldr r3, [r4, r3] */
/* @0x1b3f28 ldr r0, [r3] */
/* @0x1b3f2c str r3, [sp, #0x34] */
/* @0x1b3f30 cmp r0, #0 */
/* @0x1b3f34 blt 0x1b3f44 <_Z9Draw_Roomv+0xac> */
/* @0x1b3f38 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0x1b3f3c cmp r0, #0 */
/* @0x1b3f40 bne 0x1b3fa4 <_Z9Draw_Roomv+0x10c> */

/* ── 建表面：GR_Surface_Create([0x3f510c], [0x3f5108], -1) ─────────
 *   期间 0x542560（「正在建表面」字节）置 1、建完清 0；结果写 0x3f5110，
 *   同一对尺寸再写进 0x3f2424 / 0x3f2420（初值 640 / 480，与相机默认分辨率同级）。
 */

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

/* ── 第三道闸：0x5428f0（字节）非 0 ⇒ 改表面尺寸 ────────────────────
 *   该字节由外部置位，本函数在 1b4878 清 0 后调 GR_Surface_Resize(id,[0x3f50f8],[0x3f50f4])。
 */

/* @0x1b3fa4 ldr r3, [pc, #0xa0c] */
/* @0x1b3fa8 ldr r3, [r4, r3] */
/* @0x1b3fac ldrb r2, [r3] */
/* @0x1b3fb0 cmp r2, #0 */
/* @0x1b3fb4 bne 0x1b4878 <_Z9Draw_Roomv+0x9e0> */

/* ── 屏幕宽高指针：[sp+0x2c] = &0x3f26c0(1024)、[sp+0x30] = &0x3f26bc(768) ──
 *   后面所有「全屏视口/视区」都从这两个地址取值（1b403c、1b434c、1b461c、1b490c）。
 */

/* @0x1b3fb8 ldr r2, [pc, #0x9fc] */
/* @0x1b3fbc ldr r3, [pc, #0x9fc] */
/* @0x1b3fc0 ldr r2, [r4, r2] */
/* @0x1b3fc4 str r2, [sp, #0x2c] */
/* @0x1b3fc8 ldr r3, [r4, r3] */
/* @0x1b3fcc str r3, [sp, #0x30] */

/* ── 同步生效位 + 保存三个会被强改的字节 ──────────────────────────
 *   [0x3f50f0] = [0x3f50f1]（请求位落到生效位）。r7 = 0x5428e8（Zeus 在线字节），
 *   r5 = [0x4859b0] 的旧值（3D 模式位），[sp+0x24] = &0x4859b0，r3 存到 [sp+0x24] 前的临时槽。
 */

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

/* ── 全屏视口：Set_View_Port(0,0,w,h)，并把 (0,0,w,h) 备份进本地矩形槽 ──
 *   [sp+0x40..0x4c] 一物两用：此刻是全屏备份，1b4198 的 stm 会把它覆盖成本视图的矩形，
 *   但 8 视图结束后 1b4314 又从这里取回全屏四边。
 */

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

/* ── Zeus 二分（本函数到处出现的那颗字节）───────────────────────────
 *   1b4040 再读 0x5428e8：非 0 → 1b4058 UpdateDefaultCamera；== 0 → 1b461c View_Area。
 *   同一条判据在 1b410c 之后、1b4290、1b4410、1b47ec 各出现一次。
 */

/* @0x1b4040 ldrb r3, [r7] */
/* @0x1b4044 cmp r3, #0 */
/* @0x1b4048 mov r3, #0 */
/* @0x1b404c mov r0, r3 */
/* @0x1b4050 str r3, [sp] */
/* @0x1b4054 beq 0x1b461c <_Z9Draw_Roomv+0x784> */
/* ── UpdateDefaultCamera(0,0,w,h,0)：四边都是 int→float，第 5 参是压栈的 0 ── */

/* @0x1b4058 vldr s9, [sp, #72] */
/* @0x1b405c vldr s11, [sp, #76] */
/* @0x1b4060 vcvt.f32.s32 s9, s9 */
/* @0x1b4064 mov r1, r0 */
/* @0x1b4068 vcvt.f32.s32 s11, s11 */
/* @0x1b406c vmov r2, s9 */
/* @0x1b4070 vmov r3, s11 */
/* @0x1b4074 bl 0x1aff1c <_Z19UpdateDefaultCamerafffff> */

/* ── 两个 float 全局强制 1.0（旧值留到 1b43d0/1b43d4 恢复）─────────────
 *   0x3f50d8（X）/ 0x3f50d4（Y）在 1b4238 参与 vmul，把 view+0x14..+0x20 四个 int 缩放成视口
 *   ⇒ 它们是视图缩放/映射系数；房间绘制期间被压成 1.0，全局写 1.0 发生在 1b4090/1b4098。
 *   r9 = 0x54298c = &Run_Room，此后 r9 一直当 CRoom** 用。
 */

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

/* ── room->[0x46] 决定 Pre-Draw 的清屏实参 ────────────────────────
 *   0x46 != 0 且生效位 0x3f50f0 != 0 → 1b46c0 ExecutePreDrawEvent(rect,8,76,true)，
 *   返回取反存 [sp+0x3c]；否则 1b40cc 直接 ExecutePreDrawEvent(rect,8,76,false) 且 [sp+0x3c]=0。
 *   [sp+0x3c] 到 1b437c 决定要不要用窗口底色清屏。
 */

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

/* ── Pre-Draw 的副作用收尾：还 3D 位、表面模式下切渲染目标 ───────────
 *   1b40dc 再读 Zeus 字节（r7 = 0x5428e8）：非 0 时把 r5 写回 0x4859b0（1b40f0 的 strbne），
 *   与 1b4004/1b4008 的清零配对。随后 1b40f4 读生效位：非 0 → 1b4794 把房间画进
 *   离屏表面 0x3f5110，否则直接画到当前目标。
 */

/* @0x1b40dc ldrb r3, [r7] */
/* @0x1b40e0 ldr r8, [sp, #0x28] */
/* @0x1b40e4 cmp r3, #0 */
/* @0x1b40e8 ldrne r12, [sp, #0x24] */
/* @0x1b40ec ldrb r3, [r8] */
/* @0x1b40f0 strbne r5, [r12] */
/* @0x1b40f4 cmp r3, #0 */
/* @0x1b40f8 bne 0x1b4794 <_Z9Draw_Roomv+0x8fc> */

/* ── UpdateViews() → CRoom::SortTiles 的条件调用 ──────────────────
 *   room 为 NULL 或 room->[0xdc] == 0 → 调 SortTiles；[0xdc] != 0（有图层）→ 1b4640 跳过，
 *   平铺顺序交给 DrawTheRoom 里的 DrawRoomLayers。+0xdc 在 DrawTheRoom 侧是「> 0 才画图层」，
 *   两处极性一致：非 0/正数 = 有图层。
 */

/* @0x1b40fc bl 0x1b0164 <_Z11UpdateViewsv> */
/* @0x1b4100 ldr r0, [r9] */
/* @0x1b4104 cmp r0, #0 */
/* @0x1b4108 beq 0x1b4118 <_Z9Draw_Roomv+0x280> */
/* @0x1b410c ldr r3, [r0, #0xdc] */
/* @0x1b4110 cmp r3, #0 */
/* @0x1b4114 bne 0x1b4640 <_Z9Draw_Roomv+0x7a8> */
/* @0x1b4118 bl 0x1af3f4 <_ZN5CRoom9SortTilesEv> */

/* ── 视图环初始化：0x5428ec 清零（表面重定向痕迹），room->[0x44] 决定单画还-loop ──
 *   [sp+0x20] = &0x542920（当前视图号）；r5 = 视图下标 0..7。
 */

/* @0x1b411c ldr r3, [r9] */
/* @0x1b4120 ldr r1, [pc, #0x8b0] */
/* @0x1b4124 mov r2, #0 */
/* @0x1b4128 ldrb r5, [r3, #0x44] */
/* @0x1b412c ldr r8, [r4, r1] */
/* @0x1b4130 cmp r5, r2 */
/* @0x1b4134 str r2, [r8] */
/* @0x1b4138 beq 0x1b47b4 <_Z9Draw_Roomv+0x91c> */

/* ── room->[0x45]：画前用窗口底色清屏；随后进视图环 ────────────────
 *   1b4868 是清屏块（GR_Window_Get_Color → GR_Draw_Clear），清完回到 1b4148 继续。
 */

/* @0x1b413c ldrb r2, [r3, #0x45] */
/* @0x1b4140 cmp r2, #0 */
/* @0x1b4144 bne 0x1b4868 <_Z9Draw_Roomv+0x9d0> */
/* @0x1b4148 ldr r2, [pc, #0x88c] */
/* @0x1b414c mov r5, #0 */
/* @0x1b4150 ldr r2, [r4, r2] */
/* @0x1b4154 str r2, [sp, #0x20] */
/* @0x1b4158 b 0x1b41e4 <_Z9Draw_Roomv+0x34c> */

/* ── Zeus 路径：按 view+0x40 的相机号激活相机并取矩阵 ───────────────
 *   SetActiveCamera(id) → GetActiveCamera → 非 0 则 CCamera::Begin + ApplyMatrices。
 *   0x48f78c 是 CCameraManager 单例（GOT 0x3edc7c）。
 */

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

/* ── 投递：从全局矩形拷到本地，叫 DrawTheRoom，然后按需弹表面 ──────────
 *   0x5425c0 是「当前房间绘制矩形」，DrawTheRoom 自己开头会把它写成实参（1b3b44），
 *   本函数每画一个视图都从它重拷一次。1b41a4 看 0x5428ec（本视图若切过目标就非 0）：
 *   非 0 → 清零 + YYGML_surface_reset_target()。
 */

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

/* ── 每视图收尾：把两个缩放全局写回旧值；i++ 到 8 为止 ──────────────
 *   s16/s17 是 1b420c/1b4218 从 0x3f50d8 / 0x3f50d4 取的旧值；r10/[sp+0x1c] 是它们的地址。
 *   循环上限是硬编码 8（cmp r5,#8），与 room->[0x48] 数组长度一致。
 */

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

/* ── 环头：view = room->[0x48 + i*4]（r2 = i+18 再 lsl #2）───────────
 *   [0x542920] = i；view+0x00 是启用字节，为 0 直接下一个视图。
 */

/* @0x1b41e4 add r2, r5, #18 */
/* @0x1b41e8 ldr r12, [sp, #0x20] */
/* @0x1b41ec ldr r11, [r3, r2, lsl #2] */
/* @0x1b41f0 str r5, [r12] */
/* @0x1b41f4 ldrb r3, [r11] */
/* @0x1b41f8 cmp r3, #0 */
/* @0x1b41fc beq 0x1b41d4 <_Z9Draw_Roomv+0x33c> */

/* ── view+0x3c 表面号：-1 = 没有；有且存在 → 画进该表面 ──────────────
 *   1b4200 用 cmn r0,#1 判 -1；1b4220 GR_Surface_Exists 为真 → 1b45d8。
 *   同时先把 Zeus 位取出、0x4859b0 的清零（str lr,[r8]）准备好。
 */

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

/* ── 按视图矩形设视口：(int)(view[i] * 缩放全局) 后 Set_View_Port ───────
 *   view+0x14/+0x18/+0x1c/+0x20 四个 int → float，乘 0x3f50d8(X)/0x3f50d4(Y) 再截断。
 *   四个 int 依序是 x1,y1,x2,y2：s12/s13 乘 X 缩放 s14，s10/s11 乘 Y 缩放 s15；
 *   1b4260/1b4264 再用结果覆写 s14/s15 —— 两条轴没有串。
 */

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

/* ── 分叉：Zeus 在线才设相机，否则只设 View_Area ────────────────────
 *   view+0x04/+0x08/+0x0c/+0x10 = 视区四边，(view+0x24) 是第 5 个 float（压栈）。
 */

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

/* ── 没有视图表面（-1）：矩形沿用前面取到的全屏 s16/s17 ───────────────── */

/* @0x1b42b8 vmov.f32 s15, s17 */
/* @0x1b42bc vmov.f32 s14, s16 */
/* @0x1b42c0 b 0x1b4238 <_Z9Draw_Roomv+0x3a0> */

/* ── Zeus 且视图重定向过：结束相机、相机号复位 -1、推进下标 ────────────
 *   r5 在这里重新当循环下标用（1b42e8 add r5,r5,#1），1b42f0 与 8 比较。
 */

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

/* ── 8 视图画完：Flush()；表面模式下弹目标 ─────────────────────────── */

/* @0x1b42f8 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1b42fc ldr r8, [sp, #0x28] */
/* @0x1b4300 ldrb r3, [r8] */
/* @0x1b4304 cmp r3, #0 */
/* @0x1b4308 bne 0x1b4854 <_Z9Draw_Roomv+0x9bc> */

/* ── 恢复全屏视口/视区（用 [sp+0x40..0x4c] 备份的 0,0,w,h）────────────
 *   1b4340 重新取 0x4859b0 的字节进 r5，1b4348 把它清 0 —— 从此直到 1b43f0 才写回。
 */

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

/* ── 全屏 View_Area(0,0,w,h,0) ───────────────────────────────── */

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

/* ── 清屏（按 Pre-Draw 的 [sp+0x3c]）→ Post-Draw（8,77）────────────────
 *   1b438c/1b4394 先把 0x3f50d8 / 0x3f50d4 的旧值取到 r9/r8，1b4390/1b4398 再次写 1.0
 *   （Post-Draw 期间继续压平缩放），到 1b43d0/1b43d4 才真正恢复。
 */

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

/* ── 表面栈检错：*0x48ffac != 0 ⇒ Error_Show 并直接收尾 ─────────────
 *   0x48ffac 就是 YYGML_surface_set_target_ext 里「与 496 比较」的那个栈深度；非 0 = 本帧
 *   surface_set_target / reset 没配平。字符串 0x34D2AC = "Unbalanced surface stack. You MUST
 *   use surface_reset_target…"（1b4a18 的 0x198bc0 + pc 1b46ec）。Error_Show 之后走到 1b46ec：
 *   profiler 开关非 0 → Pop 再返回，否则直接返回 —— 不会继续画 GUI。
 */

/* @0x1b43b0 ldr r3, [pc, #0x630] */
/* @0x1b43b4 ldr r3, [r4, r3] */
/* @0x1b43b8 ldr r3, [r3] */
/* @0x1b43bc cmp r3, #0 */
/* @0x1b43c0 bne 0x1b46dc <_Z9Draw_Roomv+0x844> */

/* ── 恢复两个缩放全局；Zeus 在线则深度先归 0 ────────────────────── */

/* @0x1b43c4 ldrb r3, [r7] */
/* @0x1b43c8 ldr r12, [sp, #0x1c] */
/* @0x1b43cc cmp r3, #0 */
/* @0x1b43d0 str r9, [r10] */
/* @0x1b43d4 str r8, [r12] */
/* @0x1b43d8 bne 0x1b48e0 <_Z9Draw_Roomv+0xa48> */

/* ── 第四道闸：0x3f50fc（初值 1）非 0 ⇒ 尝试把离屏表面回贴到屏幕 ──────
 *   回贴还要求生效位非 0（1b464c）与表面号有效，否则落回 1b43f0 的直画路径。
 */

/* @0x1b43dc ldr r3, [pc, #0x608] */
/* @0x1b43e0 ldr r3, [r4, r3] */
/* @0x1b43e4 ldrb r3, [r3] */
/* @0x1b43e8 cmp r3, #0 */
/* @0x1b43ec bne 0x1b4648 <_Z9Draw_Roomv+0x7b0> */

/* ── 直画路径收尾：还 3D 位 → Set_Mode(0) → 存 0x3f23bd 字节 ──────────
 *   1b43f0 取 0x3f23bd（1 字节），1b4400/1b4404 取出旧值到 r9，1b45b8 写回；
 *   GR_3D_Set_Mode(0) 进 GUI 段，退出时 1b45a8 用 r5（0x4859b0 的旧值）恢复。
 *   Zeus 在线才把 0x5425a4 置 1 再 SetGuiView；两条路都会跑 74/64/75 三个 GUI 事件。
 */

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

/* ── GUI 段：0x5425a4 = 1 → SetGuiView → 74 / 64 / 75 → 0 ──────────────
 *   事件实参都是 (rect, 8, 子事件号)：(74) GUI Begin、(64) Draw GUI、(75) GUI End。
 *   1b4430 取 0x5425c0 的矩形再压回 [sp+0x40..0x4c]，保证 GUI 事件拿到同一块矩形。
 */

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

/* ── GUI 精灵：0x5425a4 复位，0x542918 号精灵喂 Sprite_Data ────────────── */

/* @0x1b4488 ldr r3, [pc, #0x568] */
/* @0x1b448c strb r10, [r7] */
/* @0x1b4490 ldr r3, [r4, r3] */
/* @0x1b4494 ldr r0, [r3] */
/* @0x1b4498 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b449c subs r6, r0, #0 */
/* @0x1b44a0 beq 0x1b45a4 <_Z9Draw_Roomv+0x70c> */

/* ── GUI 矩阵：单位阵 + 平移(-w/2, -h/2, 16000) → Graphics::SetMatrix ────
 *   4x4 列主序放在 sp+0x50..sp+0x8c：m0=m5=m10=m15=1.0、m12=-w*0.5（0x1b451c 的 vstr）、
 *   m13=-h*0.5、m14=16000.0（0x467a0000，1b44e4 的 movt）。r6 已换成 CSprite*。
 */

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

/* ── 画那颗 GUI 精灵：帧号 [0x542914]、位置 ([0x53468c],[0x534664])、blend 白、alpha 1 ──
 *   CSprite::Draw(this=r6, i=帧号, x, y, xs=1, ys=1, ang=0, blend=0x00FFFFFF, alpha=1)。
 *   1b4548 取 0x7530c9（字节），旧值进 r7、写 1，1b45a0 写回 —— 一个「正在画 GUI 精灵」的
 *   重入保护位，语义未钉。
 */

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

/* ── 退出：还标志字节 → 还 3D 模式 → profiler Pop / 直接 pop ────────────
 *   1b45a0 把 0x7530c9 的旧值 r7 写回；1b45a8 GR_3D_Set_Mode(r5)（r5 = 0x4859b0 的旧字节）；
 *   1b45b8 把 0x3f23bd 的旧值 r9 写回、1b45c0 清 [sp+0x20] 指向的 0x542920。
 *   1b45bc/1b45c4 是 profiler 开关的分支：非 0 → 1b46fc CProfiler::Pop 再返回。
 */

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

/* ── 视图专用表面：切目标 → 用表面尺寸设视口 ──────────────────────
 *   YYGML_surface_set_target_ext(0, view+0x3c)；GR_Surface_Get(id) 拿到的结构里 +0x8/+0xc
 *   被当作宽高直接喂 Set_View_Port（1b4608/1b4610）；GR_Texture_Get_Surface 的结果
 *   记进 0x5428ec，作为「本视图重定向过」的痕迹（1b41a4 见非 0 就弹）。
 */

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

/* ── 非 Zeus：全屏 View_Area(0,0,w,h,0) ──────────────────────── */

/* @0x1b461c vldr s12, [sp, #72] */
/* @0x1b4620 vldr s13, [sp, #76] */
/* @0x1b4624 vcvt.f32.s32 s12, s12 */
/* @0x1b4628 mov r1, r0 */
/* @0x1b462c vcvt.f32.s32 s13, s13 */
/* @0x1b4630 vmov r2, s12 */
/* @0x1b4634 vmov r3, s13 */
/* @0x1b4638 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x1b463c b 0x1b4078 <_Z9Draw_Roomv+0x1e0> */

/* ── 跳过 SortTiles 的跳板（room->[0xdc] != 0）────────────────────── */

/* @0x1b4640 mov r3, r0 */
/* @0x1b4644 b 0x1b4120 <_Z9Draw_Roomv+0x288> */

/* ── 回贴闸：生效位为 0 直接去 GUI；否则按 0x3f50b0 选回贴方式 ────────── */

/* @0x1b4648 ldr r8, [sp, #0x28] */
/* @0x1b464c ldrb r3, [r8] */
/* @0x1b4650 cmp r3, #0 */
/* @0x1b4654 beq 0x1b43f0 <_Z9Draw_Roomv+0x558> */
/* @0x1b4658 ldr r3, [pc, #0x3ac] */
/* @0x1b465c ldr r3, [r4, r3] */
/* @0x1b4660 ldrb r3, [r3] */
/* @0x1b4664 cmp r3, #0 */
/* @0x1b4668 beq 0x1b490c <_Z9Draw_Roomv+0xa74> */

/* ── RenderSurface_AspectAdjusted(surf, 0,0, w,h, [0x499309], [0x3f243c], 1) ──
 *   八个实参：r0..r3 = (表面号, 0, 0, w)，栈上 = (h, 字节A, 字节B, 1)。
 *   两个字节全局分别决定纵向/横向的适配方式（名字未钉）。
 */

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

/* ── Pre-Draw 的「清屏」真值路径：ExecutePreDrawEvent(rect,8,76,true) ──
 *   返回取反（uxtb）后存 [sp+0x3c]：事件自己清过了就不再清。
 */

/* @0x1b46c0 mov r3, #1 */
/* @0x1b46c4 mov r0, r6 */
/* @0x1b46c8 bl 0x1b3718 <_Z19ExecutePreDrawEventP9tagYYRECTiib> */
/* @0x1b46cc eor r0, r0, #1 */
/* @0x1b46d0 uxtb r0, r0 */
/* @0x1b46d4 str r0, [sp, #0x3c] */
/* @0x1b46d8 b 0x1b40dc <_Z9Draw_Roomv+0x244> */

/* ── 表面栈未配平：Error_Show(0x34d2ac, false) 然后直接收尾 ──────────── */

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

/* ── profiler 入口：CProfiler::Push(0x757e80, 6, 12) ───────────────── */

/* @0x1b4714 ldr r3, [pc, #0x300] */
/* @0x1b4718 mov r1, #6 */
/* @0x1b471c mov r2, #12 */
/* @0x1b4720 ldr r0, [r4, r3] */
/* @0x1b4724 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1b4728 b 0x1b3ec4 <_Z9Draw_Roomv+0x2c> */

/* ── 拆表面路径（请求位 0x3f50f1 == 0）──────────────────────────────
 *   [0x3f510c] = 屏幕宽、[0x3f5108] = 屏幕高（尺寸缓存回到全屏），
 *   GR_Surface_Exists(id) 为真 → 1b4958 Free(id,1) + id = 0xFEEEDEAD；
 *   为假就直接落到 1b3fd0（仍会把请求位 0 写进生效位）。
 */

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

/* ── 表面模式：把房间内容画进离屏表面（set_target_ext(0, id)）────────── */

/* @0x1b4794 ldr r12, [sp, #0x34] */
/* @0x1b4798 mov r0, #0 */
/* @0x1b479c ldr r1, [r12] */
/* @0x1b47a0 bl 0x171574 <_Z28YYGML_surface_set_target_extii> */
/* @0x1b47a4 b 0x1b40fc <_Z9Draw_Roomv+0x264> */

/* ── 用窗口底色清屏（Pre-Draw 说需要清）──────────────────────────── */

/* @0x1b47a8 bl 0x17ae20 <_Z19GR_Window_Get_Colorv> */
/* @0x1b47ac bl 0x169f58 <_Z13GR_Draw_Clearj> */
/* @0x1b47b0 b 0x1b43a0 <_Z9Draw_Roomv+0x508> */

/* ── 无视图：单次全屏绘制（room->[0x44] == 0）─────────────────────────
 *   当前视图号清 0、Flush、全屏视口（表面尺寸缓存）、再按 Zeus 决定 View_Area 还是
 *   UpdateDefaultCamera（用 room+0x10/+0x14 的房间宽高），最后一次 DrawTheRoom。
 */

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

/* ── 无视图的投递：同一块 0x5425c0 矩形 → DrawTheRoom → 按需弹目标 ────── */

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

/* ── 非 Zeus：GUI 段前深度归 0 ──────────────────────────────── */

/* @0x1b485c mov r0, #0 */
/* @0x1b4860 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b4864 b 0x1b4418 <_Z9Draw_Roomv+0x580> */

/* ── room->[0x45]：窗口底色清屏后回视图环 ─────────────────────── */

/* @0x1b4868 bl 0x17ae20 <_Z19GR_Window_Get_Colorv> */
/* @0x1b486c bl 0x169f58 <_Z13GR_Draw_Clearj> */
/* @0x1b4870 ldr r3, [r9] */
/* @0x1b4874 b 0x1b4148 <_Z9Draw_Roomv+0x2b0> */

/* ── 改尺寸路径（0x5428f0 非 0）─────────────────────────────────
 *   清请求字节 → GR_Surface_Resize(id, [0x3f50f8], [0x3f50f4]) → 更新
 *   [0x3f5108] = [0x3f50f8]、[0x3f510c] = [0x3f50f4]，再跳回 1b3fd0 继续本帧绘制。
 *   ⚠ Create 传的是 ([0x3f510c], [0x3f5108])，Resize 传的是 ([0x3f50f8], [0x3f50f4]) 且回写
 *     顺序相反 —— 宽高归属只能靠 GR_Surface_Create/Resize 的形参定名，见 open。
 */

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

/* ── Zeus 在线：深度归 0，然后接着判断回贴闸（1b48e8）────────────── */

/* @0x1b48e0 mov r0, #0 */
/* @0x1b48e4 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b48e8 b 0x1b43dc <_Z9Draw_Roomv+0x544> */

/* ── Zeus + 无视图：UpdateDefaultCamera(0,0,roomW,roomH,0) ──────── */

/* @0x1b48ec vmov s9, r2 */
/* @0x1b48f0 vmov s11, r3 */
/* @0x1b48f4 vcvt.f32.s32 s9, s9 */
/* @0x1b48f8 vcvt.f32.s32 s11, s11 */
/* @0x1b48fc vmov r2, s9 */
/* @0x1b4900 vmov r3, s11 */
/* @0x1b4904 bl 0x1aff1c <_Z19UpdateDefaultCamerafffff> */
/* @0x1b4908 b 0x1b482c <_Z9Draw_Roomv+0x994> */

/* ── 回贴方式 1：GR_Surface_DrawStretched(id, 0,0, w,h, 0x00FFFFFF, 1.0) ──
 *   0x3f50b0 为 0 时走这条（初值 1，所以默认走 AspectAdjusted）。
 */

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

/* ── 释放旧表面并把表面号写成无效哨兵 0xFEEEDEAD ────────────────────
 *   GR_Surface_Free(id, 1)；1b4970/1b4974 是 movw 0xdead + movt 0xfeee。
 */

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

/* ── literal pool（1b4988..1b4a24，40 字；被 objdump 译成指令的都是池词）──────
 *   1b4988 = 0x0023dda4  GOT 基址加数（+pc 0x1b3eb4 → 0x3F1C58）
 *   1b4a18 = 0x198bc0   错误串加数（+pc 0x1b46ec → 0x34D2AC）
 *   其余 38 个是 GOT 负偏移，按出现顺序（槽 = 0x3F1C58 + 偏移 → 槽内目标）：
 *     bf18 → 3edb70 → 757e7c(profiler 开关)   def8 → 3efb50 → 3f50f1(请求位)
 *     e6a4 → 3f02fc → 3f50f0(生效位)          df3c → 3efb94 → 3f5104(df38→3efb90→3f510c)
 *     df44 → 3efb9c → 3f5100                  df40 → 3efb98 → 3f5108
 *     c988 → 3ee5e0 → 3f5110(表面号)          ebe8 → 3f0840 → 542560(建表面中)
 *     e688 → 3f02e0 → 3f2424(尺寸副本 A)          e68c → 3f02e4 → 3f2420(尺寸副本 B)
 *     c98c → 3ee5e4 → 5428f0(改尺寸请求)      e24c → 3efea4 → 3f26c0(屏幕宽)
 *     e250 → 3efea8 → 3f26bc(屏幕高)          bcd4 → 3ed92c → 5428e8(Zeus)
 *     c0b4 → 3edd0c → 4859b0(3D 位)           e6bc → 3f0314 → 3f50d8(缩放 X)
 *     e6c4 → 3f031c → 3f50d4(缩放 Y)          bcd8 → 3ed930 → 54298c(&Run_Room)
 *     ebec → 3f0844 → 5428ec(表面痕迹)        c980 → 3ee5d8 → 542920(当前视图号)
 *     c024 → 3edc7c → 48f78c(CameraManager)   e4fc → 3f0154 → 5425c0(绘制矩形)
 *     e614 → 3f026c → 48ffac(表面栈深度)      df34 → 3efb8c → 3f50fc(回贴闸)
 *     e4b0 → 3f0108 → 3f23bd(GUI 段字节)      df30 → 3efb88 → 5425a4(GUI 中)
 *     d798 → 3ef3f0 → 542918(GUI 精灵号)      e490 → 3f00e8 → 7530c9(精灵段字节)
 *     ebf0 → 3f0848 → 542914(GUI 帧号)        df4c → 3efba4 → 53468c(GUI x)
 *     df48 → 3efba0 → 534664(GUI y)           ebf4 → 3f084c → 3f50b0(回贴方式)
 *     e6a0 → 3f02f8 → 499309(AspectAdjusted b1) e4d8 → 3f0130 → 3f243c(AspectAdjusted b2)
 *     bf1c → 3edb74 → 757e80(CProfiler)       c990 → 3ee5e8 → 3f50f8(改尺寸请求 B)
 *     c994 → 3ee5ec → 3f50f4(改尺寸请求 A)
 *
 * ── 结论（五条硬事实）──────────────────────────────────────────
 *   1. Draw_Room 是房间绘制的唯一外层入口：一次调用对 room->[0x48] 的 8 个视图各调一次
 *      DrawTheRoom（1b41a0），或（room->[0x44]==0）整屏调一次（1b4840）；它自己从不调用
 *      DoSlowDrawRoom/DrawInstancesOnly/DrawInstancesParticlesOnly。
 *   2. 快/慢选路不在本函数：判据在 DrawTheRoom 的 1b3d1c（CRoom+0xb8 层项条数）与
 *      1b3d2c（CRoom+0x88 实例计数），全局只提供 CRoom*（*0x54298c）。CRoom+0xdc 是图层数，
 *      不是快慢开关。
 *   3. 两个 float 全局 0x3f50d8/0x3f50d4 在整段房间绘制期间被强压成 1.0（1b4090/1b4098、
 *      1b4390/1b4398），1b43d0/1b43d4 恢复；它们在 1b4258 起是视图矩形的缩放系数。
 *   4. 房间可先画进离屏表面：Create(1b3f70)/Resize(1b48a0)/Free(1b4964)/切目标(1b479c)，
 *      表面号 0x3f5110、无效哨兵 0xFEEEDEAD；是否回贴由 0x3f50fc 决定（1b43e4），回贴方式由
 *      0x3f50b0 决定（DrawStretched 1b4950 / AspectAdjusted 1b46b8）。
 *   5. 收尾有硬检错：*0x48ffac（表面栈深度）!= 0 → Error_Show("Unbalanced surface stack…"，串在
 *      0x34D2AC) 并立即收尾（1b43c0 → 1b46dc），不再画 GUI。
 *
 * ── open ──────────────────────────────────────────────────────
 *   1. 0x3f50f0 / 0x3f50f1 / 0x3f50fc / 0x3f50b0 四个字节的正式名未定，只证行为：
 *      生效位 / 请求位（为 0 触发拆表面）/ 是否回贴 / 回贴方式（0 走 DrawStretched，非 0 走 AspectAdjusted）。
 *      四个的 .data 初值都是 1。
 *   2. 0x3f5108 与 0x3f510c 谁宽谁高未定：Create 传 ([0x3f510c],[0x3f5108])，Resize 传
 *      ([0x3f50f8],[0x3f50f4]) 却回写 [0x3f5108]=[0x3f50f8]、[0x3f510c]=[0x3f50f4]，顺序相反。
 *   3. 0x3f5104/0x3f5100 的写入者不在本函数（疑为 Draw_Room_SetSize 0x1b29bc，未验证）。
 *   4. GUI 那颗精灵的用途未定：精灵号 0x542918，帧号取 0x542914（DoAStep 卡称步计数），
 *      坐标取 0x53468c/0x534664，矩阵只有平移 —— 布局上像「整屏底图/GUI 背景」。
 *   5. 0x3f23bd 与 0x7530c9 两个字节只证到「进入某段前保存并置位、退出时写回」，语义未定。
 *   6. 0x5428ec 的类型按 1b45f4 的写入判为「表面指针」，但 1b4134 写的是 0；置非 0 的代码
 *      若存在则不在已索引函数内 —— 现阶段只能证「非 0 ⇒ 弹表面目标」。
 */

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
