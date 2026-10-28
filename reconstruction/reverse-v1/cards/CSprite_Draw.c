/* cally 逆向卡：CSprite::Draw / DrawSimple / DrawTiled（原版 libyoyo.so，armv7）
 * @func 0x1ec720 0x1ecab0  size 916  229 条（literal pool 0x1eca7c..0x1ecab0 共 14 字；真指令 215）
 * @func 0x1ecab4 0x1ecdc0  size 784  196 条（literal pool 0x1ecd98..0x1ecdc0 共 11 字；真指令 185）
 * @func 0x1ed1dc 0x1ed3cc  size 500  125 条（literal pool 0x1ed3c0..0x1ed3cc 共 4 字；真指令 121）
 * 级别: 正文（550/550 逐条落锚；三函数形参落位、三条后端分派、剔除判据、错误串出口、
 *             九个全局的 .dynsym 定名与「零全局写」全部证到指令；
 *             未钉：CSprite 字段的官方名（+0x2c/+0x50/+0x54/+0x58/+0x74）、GR_*_Tiled 末四参的名字）
 * 符号: _ZN7CSprite4DrawEifffffjf             → void CSprite::Draw(int i, float x, float y, float xs, float ys, float rot, uint32 colour, float alpha)
 *       _ZN7CSprite10DrawSimpleEiff           → void CSprite::DrawSimple(int i, float x, float y)
 *       _ZN7CSprite9DrawTiledEiffffbbffffjf   → void CSprite::DrawTiled(int i, float f1, float f2, float f3, float f4, bool b1, bool b2, float f5, float f6, float f7, float f8, uint32 colour, float alpha)
 *       ⚠ 计数更正：DrawTiled 的 mangled 尾是 E i f f f f b b f f f f j f = **13 个显式形参**（含 this 14），
 *         不是 12；栈上传 10 字（1ed1e8..1ed220 正好读满），与 13 个形参的 4 寄存器 + 10 栈完全对账。
 * 同层: 紧跟其后的第四个绘制口 CSprite::DrawStretched 0x1ecdc4（draw_sprite_stretched_ext 用）、
 *       CSprite::DrawSWF 0x1ebf08 / CSprite::DrawSWFTiled 0x1ecfb8、CSkeletonSprite::Draw 0xc03bc、
 *       GR_Texture_Draw 0x174ee0 / GR_Texture_Drawi 0x174c40 / GR_Texture_Draw_Simple 0x174868 /
 *       GR_Texture_Draw_Simplei 0x174498 / GR_Texture_Draw_Tiled 0x1762b0 / GR_Texture_Draw_Tiledi 0x175e90、
 *       __aeabi_idivmod 0x318dec、UpdateTransRoomExtents 0x168d94、CCameraManager::GetActiveCamera 0x16ec3c、
 *       CCamera::Is2D 0x16d398、CProfiler::Push 0x2a0738 / Pop 0x2a08ac
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   这三条是 CSprite 的**像素输出口**，都不设深度、不设混合、不写任何全局：
 *   先把子图号归一化到 [0, image_number)，再按 this+0x74 三档后端分派
 *   （0 = 纹理页，1 = SWF 矢量，2 = 骨骼），纹理档再按 this+0x54 有无 tpe 表
 *   在「GR_Texture_Draw(tpe,…)」与「GR_Texture_Drawi(贴图号,…)」之间二选一；
 *   三条纹理路径失败（返回 0）时统一走 dbg_csol 打印同一句 "Error attempting to draw sprite %s\n"，
 *   %s 取 this+0x5c（精灵名字符串）。
 *
 * ── 三函数的分工（同一份 this，三种能力）───────────────────────
 *   Draw       : 全能力 —— 双轴缩放 + 旋转 + 调色 + alpha，且带屏幕剔除。
 *   DrawSimple : 只 x,y —— 无缩放/旋转/调色/alpha（纹理档只传 (tpe, x-ox, y-oy)），也带屏幕剔除。
 *   DrawTiled  : 平铺 —— x,y + 双轴缩放 + 两个平铺布尔 + 四个浮点 + 调色 + alpha；**无剔除、无 profile、无旋转**。
 *   三者共同的头部骨架：image_number<=0 直接返回 → 子图号取模 → (Draw/DrawSimple) 剔除闸 → 分派。
 *
 * ── 形参落位（三张表，逐条来自本函数的取参指令）─────────────────
 *   Draw   帧 88（push 36 + vpush 16 + sub 36）：
 *     this=r0  i=r1  x=r2  y=r3  xs=[sp+0x58]  ys=[sp+0x5c]  rot=[sp+0x60]  colour=[sp+0x64]  alpha=[sp+0x68]
 *     this 一直在 r0（1ec730 直接拿它读 +0x18）；i/x/y 的搬运：1ec73c / 1ec744 / 1ec74c；
 *     栈五参的读点：1ec72c, 1ec750, 1ec754, 1ec758, 1ec75c
 *   DrawSimple 帧 64（push 24 + vpush 8 + sub 32）：
 *     this=r0  i=r1  x=r2  y=r3    —— 这就是四参的全部，没有第 5 个形参可读
 *     取参点：1ecacc(r0) 1ecad4(r1) 1ecad8(r2) 1ecabc(r3)
 *   DrawTiled 帧 112（push 36 + vpush 24 + sub 52）：
 *     this=r0  i=r1  f1=r2  f2=r3，栈上 10 字（入口 sp + 0,4,8,0xc,0x10,0x14,0x18,0x1c,0x20,0x24）：
 *       [sp+112]=f3  [sp+116]=f4  [sp+120]=b1  [sp+124]=b2  [sp+128]=f5
 *       [sp+132]=f6  [sp+136]=f7  [sp+140]=f8  [sp+144]=colour  [sp+148]=alpha
 *     搬运：1ed1f0(r4=this) 1ed228(r1→idivmod) 1ed1f4(r10=r2) 1ed1f8(r6=r3)；栈十字读点 1ed1e8..1ed220
 *     语义由调用方定（cards/auto/bank_0053.c 的 F_DrawSpriteTiled 122e90 与 F_DrawSpriteTiledExt 122f74）：
 *       f1,f2 = x,y；f3,f4 = xscale,yscale；b1,b2 两个内建都写死 1,1；f5,f6 都写死 0,0；
 *       f7,f8 两个内建都传 (float)Run_Room->[0x10] 与 [0x14]（CRoom 卡：+0x10 宽 640 / +0x14 高 480）；
 *       colour = draw_sprite_tiled 的常量 0x00FFFFFF、_ext 的 YYGetInt32(6)；
 *       alpha  = draw_sprite_tiled 的 GR_Draw_Get_Alpha()、_ext 的 YYGetFloat(7)。
 *       ⇒ f7,f8 是「平铺边界（房间宽高）」，f5,f6 是保留/未用（两个内建都不给）。
 *
 * ── 深度与混合：本卡最重要的一条负事实 ─────────────────────────
 *   0 条 GR_3D_Set_Depth（0x1631dc）调用、0 条深度读取、0 条全局写：
 *   三函数共 74 条落栈指令（Draw 26 / DrawSimple 14 / DrawTiled 34；扣掉 6 条 push/vpush，
 *   真 store 68 条），**基址全是 sp**，一条都没有写 this、也没有写全局。
 *   ⇒ 深度是**调用者的责任**：DoSlowDrawRoom 在每一条流（实例/瓦片/粒子）调绘制前先
 *     GR_3D_Set_Depth(min(depth, 11000.0))，CSprite 只负责按当前深度画。
 *   ⇒ 混合也是调用者用实参给的：Draw 的 colour 原样进 GR_Texture_Draw 第 9 参、
 *     DrawTiled 的 colour/alpha 原样进第 13/14 参；DrawSimple **没有 colour/alpha 形参**，
 *     纹理档只传 (tpe, x-ox, y-oy)，所以它画出来什么样完全取决于 GR 当前混合/alpha 状态。
 *
 * ── 全局表（9 个，全部 R_ARM_RELATIVE=23；名字全部来自 .dynsym，非推断）──
 *   GOT 0x3edb70 → .bss 0x757e7c  g_bProfile               1 B    byte  剖析开关
 *   GOT 0x3edb74 → .bss 0x757e80  g_Profiler               128 B  CProfiler 实例
 *   GOT 0x3ef638 → .data 0x3f50dc g_transRoomExtentsDirty  1 B    byte  视野矩形脏标志
 *   GOT 0x3edd0c → .bss 0x4859b0  GR_3DMode                1 B    byte  3D 渲染模式
 *   GOT 0x3ed71c → .data.rel.ro 0x3eb70c dbg_csol          4 B    TRelConsole* 调试控制台
 *   GOT 0x3f00e8 → .bss 0x7530c9  CSprite::ms_ignoreCull   1 B    byte  静态：忽略剔除
 *   GOT 0x3f0158 → .bss 0x5425b0  g_transRoomExtents       16 B   4×int32 视野矩形
 *   GOT 0x3ed92c → .bss 0x5428e8  g_isZeus                1 B    byte  Zeus(3D) 渲染器开关
 *   GOT 0x3edc7c → .bss 0x48f78c  g_CM                    28 B   CCameraManager 单例
 *   GOT 基址三函数都是 0x3f1c58（Draw/DrawSimple 用 r4 = pc + 0x00205508 / 0x00205180 算出；
 *   DrawTiled 不用基址，直接用 [pc, rX] 形式的正偏移 0x0020044c / 0x002003b8 打到同一槽）。
 *   错误串：.rodata 0x35259c = "Error attempting to draw sprite %s\n"（Draw 两处、DrawSimple 两处、
 *   DrawTiled 两处共用同一地址，池字 0x00165d34/0x00165b20/0x00165860/0x00165804/0x001652c4/0x00165230）。
 *
 * ── CSprite 字段（本卡读到的，偏移实测，官方名未证）──────────────
 *   +0x18 int    image_number（取模除数；<=0 ⇒ 不画）
 *   +0x24 int    ox 原点 x（纹理档作 GR 的第 2 参；DrawSimple 直接 x-ox）
 *   +0x28 int    oy 原点 y（同上）
 *   +0x2c int    方形半边长量 w（Draw: max(|w*xs|,|w*ys|)；DrawSimple: w；两者都喂剔除）
 *   +0x50 ptr    贴图号表（tpe 表为空时的退化路径，元素 4 字节 int，按子图索引）
 *   +0x54 ptr    YYTPageEntry* 表（首选路径，元素 4 字节，按子图索引）
 *   +0x58 ptr    CSkeletonSprite*（kind==2 时当 this 用）
 *   +0x5c ptr    精灵名字符串（错误串的 %s）
 *   +0x74 int    后端档位：0 纹理 / 1 SWF / 2 骨骼
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */
/* ── 段 A · CSprite::Draw 0x1ec720 —— 帧、取参、image_number 闸 ────────────────
 *   帧：push 36 + vpush {d8,d9} 16 + sub 36 = 88。所有栈形参的读点都 = 88 + 4k。
 *   r5=this、r8=i、r9=x(float 位型)、s18=y、s16=xs、s17=ys、s19=rot、r10=colour、r11=alpha。
 *   ⚠ 注意 1ec72c 的 vldr s16,[sp,#88] 在 r0/r1 还没搬走之前就读了 —— 编译器把取参加进了序言。
 *   image_number 在 1ec730 就读进 r6：若 <=0（ble）直接跳到 1ec87c 的**纯返回**（不经 profile），
 *   所以 1ec760 这条早退与后面 1ec9c4 的 Pop 是平衡的：Push 只发生在 1ec960。 */

/* @0x1ec720 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ec724 vpush {d8, d9} */
/* @0x1ec728 sub sp, sp, #36 */
/* @0x1ec72c vldr s16, [sp, #88] */
/* @0x1ec730 ldr r6, [r0, #0x18] */
/* @0x1ec734 mov r5, r0 */
/* @0x1ec738 ldr r4, [pc, #0x344] */
/* @0x1ec73c mov r8, r1 */
/* @0x1ec740 cmp r6, #0 */
/* @0x1ec744 mov r9, r2 */
/* @0x1ec748 add r4, pc, r4 */
/* @0x1ec74c vmov s18, r3 */
/* @0x1ec750 vldr s17, [sp, #92] */
/* @0x1ec754 vldr s19, [sp, #96] */
/* @0x1ec758 ldr r10, [sp, #0x64] */
/* @0x1ec75c ldr r11, [sp, #0x68] */
/* ── image_number <= 0 ⇒ 直接返回（1ec87c），一个字节都不写 ──────────────────── */

/* @0x1ec760 ble 0x1ec87c <_ZN7CSprite4DrawEifffffjf+0x15c> */
/* ── 剖析闸：g_bProfile 非 0 才 Push(6, 15) ────────────────────────────────────
 *   1ec764 取池字 0xffffbf18 → [r4+…] = &g_bProfile（GOT 0x3edb70 → 0x757e7c）；
 *   ldrb 读的就是那个 bool；非 0 跳 1ec960 做 Push(6,15)，回来再 1ec778 继续。
 *   类别 6 / 编号 15 这一对是 CProfiler 的段标识：DrawSimple 用 (6,16)，两者不同。 */

/* @0x1ec764 ldr r3, [pc, #0x31c] */
/* @0x1ec768 ldr r7, [r4, r3] */
/* @0x1ec76c ldrb r3, [r7] */
/* @0x1ec770 cmp r3, #0 */
/* @0x1ec774 bne 0x1ec960 <_ZN7CSprite4DrawEifffffjf+0x240> */
/* ── 子图号归一化：i = i % image_number，负数补回正区间 ────────────────────────
 *   r0=i、r1=image_number 进 __aeabi_idivmod，余数在 r1。
 *   subs r8, r1, #0 / addlt r8, r8, r6 ⇒ 余数 < 0 时 +image_number（C 的 % 已是这个口径，
 *   这条 addlt 是编译器为 idivmod 的「商向零取整」补的符号修正）。
 *   ⇒ 之后全函数都用 r8 当子图下标，越界/负号在这里被吃掉。 */

/* @0x1ec778 mov r0, r8 */
/* @0x1ec77c mov r1, r6 */
/* @0x1ec780 bl 0x318dec <__aeabi_idivmod> */
/* @0x1ec784 ldr r3, [pc, #0x300] */
/* @0x1ec788 ldr r3, [r4, r3] */
/* @0x1ec78c ldrb r3, [r3] */
/* @0x1ec790 subs r8, r1, #0 */
/* @0x1ec794 addlt r8, r8, r6 */
/* ── 视野矩形脏标志：非 0 就先 UpdateTransRoomExtents() ─────────────────────────
 *   1ec784 的池字 0xffffd9e0 → GOT 0x3ef638 → 0x3f50dc = g_transRoomExtentsDirty。
 *   非 0 → 1ec958：bl UpdateTransRoomExtents() 然后 b 1ec7a0（= 跳过标志重读，直接算半边长）；
 *   为 0 → 直接落到 1ec7a0。⇒ 剔除用的 g_transRoomExtents 在**每次绘制前**按需刷新。 */

/* @0x1ec798 cmp r3, #0 */
/* @0x1ec79c bne 0x1ec958 <_ZN7CSprite4DrawEifffffjf+0x238> */
/* ── 方形半边长：e = max(|w*xs|, |w*ys|)，w 取 int32 this+0x2c ─────────────────
 *   1ec7a0 vldr s13,[r5,#44] 是 **float 读**，1ec7a4 vcvt.f32.s32 才把它当 int 转 ⇒ +0x2c 是 int32。
 *   两条 vmul 各乘 xs、ys，再 vabs 两次、vcmp/vmovgt 取大 ⇒ e 是一个与轴向无关的方形半边长。
 *   这个 e 就是后面剔除判据里唯一的「半径」。xs/ys 任一为 0 时 e=0，只剩平移参与判定。 */

/* @0x1ec7a0 vldr s13, [r5, #44] */
/* @0x1ec7a4 vcvt.f32.s32 s15, s13 */
/* @0x1ec7a8 ldr r3, [pc, #0x2e0] */
/* @0x1ec7ac ldr r3, [r4, r3] */
/* @0x1ec7b0 vmul.f32 s14, s15, s16 */
/* @0x1ec7b4 ldrb r3, [r3] */
/* @0x1ec7b8 vmul.f32 s15, s15, s17 */
/* @0x1ec7bc vabs.f32 s14, s14 */
/* @0x1ec7c0 vabs.f32 s15, s15 */
/* @0x1ec7c4 vcmp.f32 s14, s15 */
/* @0x1ec7c8 vmrs APSR_nzcv, fpscr */
/* @0x1ec7cc vmovgt.f32 s15, s14 */
/* ── 剔除闸一：GR_3DMode 非 0 就不剔（1ec7d8 直接画）────────────────────────────
 *   池字 0xffffc0b4 → GOT 0x3edd0c → 0x4859b0 = GR_3DMode（1 B）。
 *   为 0（2D）才继续 1ec888 看 ms_ignoreCull；非 0 则跳过全部剔除逻辑。
 *   ⚠ DrawSimple 里**没有**这道闸（它的池里根本没有 0xffffc0b4 这个槽），见段 B。 */

/* @0x1ec7d0 cmp r3, #0 */
/* @0x1ec7d4 beq 0x1ec888 <_ZN7CSprite4DrawEifffffjf+0x168> */
/* ── 后端分派：this+0x74 = 0/1/2 ───────────────────────────────────────────────
 *   kind 先读进 r0。1 → CSprite::DrawSWF 1ec97c；2 → CSkeletonSprite::Draw 1ec9e8；
 *   其它（含 0）→ 纹理路（1ec7ec 起）。三条闸（GR_3DMode / ms_ignoreCull / 剔除通过）
 *   都跳回 1ec7d8 **重读** kind，只有剔除通过那条跳到 1ec7dc 复用已读的 r0。 */

/* @0x1ec7d8 ldr r0, [r5, #0x74] */
/* @0x1ec7dc cmp r0, #1 */
/* @0x1ec7e0 beq 0x1ec97c <_ZN7CSprite4DrawEifffffjf+0x25c> */
/* @0x1ec7e4 cmp r0, #2 */
/* @0x1ec7e8 beq 0x1ec9e8 <_ZN7CSprite4DrawEifffffjf+0x2c8> */
/* ── 旋转单位换算：rot_rad = rot * π / 180（只在纹理两路上做）───────────────────
 *   1ec7f0 池字 0x1eca7c = 0x40490fdb = π；1ec7f4 vmul s19 = rot * π；
 *   1ec7f8 池字 0x1eca80 = 0x43340000 = 180.0；1ec830 vdiv s19 = (rot*π)/180。
 *   ★ 两条 SWF/骨骼分支（1ec7e0 / 1ec7e8）在 1ec7f0 **之前**就跳走了 ⇒
 *     DrawSWF 与 CSkeletonSprite::Draw 收到的 rot 仍是**角度**，只有 GR_Texture_* 收到弧度。
 *   同时这里选 tpe 表：this+0x54 非 0 → 走 tpe 版；为 0 → 1eca14 用 this+0x50 的贴图号表。 */

/* @0x1ec7ec ldr r3, [r5, #0x54] */
/* @0x1ec7f0 vldr s15, [pc, #644] */
/* @0x1ec7f4 vmul.f32 s19, s19, s15 */
/* @0x1ec7f8 vldr s15, [pc, #640] */
/* @0x1ec7fc cmp r3, #0 */
/* @0x1ec800 beq 0x1eca14 <_ZN7CSprite4DrawEifffffjf+0x2f4> */
/* ── 纹理档（有 tpe 表）：GR_Texture_Draw(tpe, ox, oy, x, y, xs, ys, rot, colour, alpha) ─
 *   r0 = this->[0x54][subimg]（元素 4 字节，无上界检查）；r1 = (float)(int)[+0x24] = ox；
 *   r2 = (float)(int)[+0x28] = oy；r3 = x；栈 [0]=y [4]=xs [8]=ys [0xc]=rot(已换算)
 *   [0x10]=colour [0x14]=alpha —— 与 _Z15GR_Texture_DrawP12YYTPageEntryfffffffjf 的
 *   1+7f+j+f = 10 参完全对账（4 寄存器 + 6 栈）。
 *   ⇒ +0x24/+0x28 是**原点**而不是 UV：tpe 与贴图号两条路都把它们单独当两个形参传，
 *     而 DrawSimple 在调 _Simple 版之前先自己减掉（见段 B），两种用法互证。 */

/* @0x1ec804 ldr r1, [r5, #0x24] */
/* @0x1ec808 ldr r0, [r3, r8, lsl #2] */
/* @0x1ec80c vstr s18, [sp] */
/* @0x1ec810 ldr r2, [r5, #0x28] */
/* @0x1ec814 mov r3, r9 */
/* @0x1ec818 vmov s13, r1 */
/* @0x1ec81c vstr s16, [sp, #4] */
/* @0x1ec820 vstr s17, [sp, #8] */
/* @0x1ec824 str r10, [sp, #0x10] */
/* @0x1ec828 vmov s14, r2 */
/* @0x1ec82c str r11, [sp, #0x14] */
/* @0x1ec830 vdiv.f32 s19, s19, s15 */
/* @0x1ec834 vcvt.f32.s32 s13, s13 */
/* @0x1ec838 vstr s19, [sp, #12] */
/* @0x1ec83c vcvt.f32.s32 s14, s14 */
/* @0x1ec840 vmov r1, s13 */
/* @0x1ec844 vmov r2, s14 */
/* @0x1ec848 bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf> */
/* @0x1ec84c cmp r0, #0 */
/* @0x1ec850 bne 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* ── 失败出口：dbg_csol->vtable[3](dbg_csol, "Error attempting to draw sprite %s\n", this+0x5c) ─
 *   GR_Texture_Draw 返回 0 = 没画成（贴图页缺失等），非 0 = 成功 ⇒ 只有 0 才进来。
 *   r3 取池字 0xffffbac4 → GOT 0x3ed71c → 0x3eb70c = dbg_csol（4 B 指针，TRelConsole*）；
 *   r1 = pc + 0x00165d34 = 0x35259c（.rodata 的错误串）；r2 = this+0x5c（%s）。
 *   调用形如 obj->[vtable+0xc](obj, fmt, name)：ldr r0,[r3] 取 *dbg_csol、ldr r3,[r0] 取 vtable、
 *   ldr r3,[r3,#0xc] 取第 4 个虚槽，blx。返回后 b 1ec9c4（走公共出口）。 */

/* @0x1ec854 ldr r1, [pc, #0x238] */
/* @0x1ec858 ldr r3, [pc, #0x238] */
/* @0x1ec85c ldr r2, [r5, #0x5c] */
/* @0x1ec860 add r1, pc, r1 */
/* @0x1ec864 ldr r3, [r4, r3] */
/* @0x1ec868 ldr r0, [r3] */
/* @0x1ec86c ldr r3, [r0] */
/* @0x1ec870 ldr r3, [r3, #0xc] */
/* @0x1ec874 blx r3 */
/* @0x1ec878 b 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* ── 纯返回出口（无 Pop）：只从 1ec760（image_number<=0）与 1ec9cc（g_bProfile==0）进来 ── */

/* @0x1ec87c add sp, sp, #36 */
/* @0x1ec880 vpop {d8, d9} */
/* @0x1ec884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 剔除闸二：CSprite::ms_ignoreCull 非 0 就不剔 ─────────────────────────────
 *   池字 0xffffe490 → GOT 0x3f00e8 → 0x7530c9 = CSprite::ms_ignoreCull（1 B 静态成员）。
 *   非 0 → 1ec7d8 全量分派；为 0 → 1ec89c 继续做剔除测试。 */

/* @0x1ec888 ldr r3, [pc, #0x20c] */
/* @0x1ec88c ldr r3, [r4, r3] */
/* @0x1ec890 ldrb r3, [r3] */
/* @0x1ec894 cmp r3, #0 */
/* @0x1ec898 bne 0x1ec7d8 <_ZN7CSprite4DrawEifffffjf+0xb8> */
/* ── 剔除：kind==2 先旁路；否则用方形 e 对 g_transRoomExtents 做四边「整块在外」判定 ──
 *   kind==2（骨骼）→ 1ec9e8，**完全跳过剔除**。
 *   g_transRoomExtents（GOT 0x3f0158 → 0x5425b0，16 B = 4×int32）按 (x1,y1,x2,y2) 用，
 *   四个字段都 vcvt.f32.s32 后才比较。判据（s15 = e）：
 *     e < (y1 - y) ⇒ 整块在视野上方；e < (y - y2) ⇒ 在下方；
 *     e < (x1 - x) ⇒ 在左侧；       e < (x - x2) ⇒ 在右侧（这条写在最后，用 bge 反向跳）
 *   任一成立即「整块在外」→ 1ec914。四条都过 = 与视野相交 → 1ec7dc 直接分派。
 *   ⚠ 第三条的 x 由 1ec8e8 vmov s13,r9 从 r9 取（r9 一直是 x 的位型，本段没被覆写）。 */

/* @0x1ec89c ldr r0, [r5, #0x74] */
/* @0x1ec8a0 cmp r0, #2 */
/* @0x1ec8a4 beq 0x1ec9e8 <_ZN7CSprite4DrawEifffffjf+0x2c8> */
/* @0x1ec8a8 ldr r3, [pc, #0x1f0] */
/* @0x1ec8ac ldr r3, [r4, r3] */
/* @0x1ec8b0 vldr s13, [r3, #4] */
/* @0x1ec8b4 vcvt.f32.s32 s14, s13 */
/* @0x1ec8b8 vsub.f32 s14, s14, s18 */
/* @0x1ec8bc vcmpe.f32 s15, s14 */
/* @0x1ec8c0 vmrs APSR_nzcv, fpscr */
/* @0x1ec8c4 blt 0x1ec914 <_ZN7CSprite4DrawEifffffjf+0x1f4> */
/* @0x1ec8c8 vldr s13, [r3, #12] */
/* @0x1ec8cc vcvt.f32.s32 s14, s13 */
/* @0x1ec8d0 vsub.f32 s14, s18, s14 */
/* @0x1ec8d4 vcmpe.f32 s15, s14 */
/* @0x1ec8d8 vmrs APSR_nzcv, fpscr */
/* @0x1ec8dc blt 0x1ec914 <_ZN7CSprite4DrawEifffffjf+0x1f4> */
/* @0x1ec8e0 vldr s13, [r3] */
/* @0x1ec8e4 vcvt.f32.s32 s14, s13 */
/* @0x1ec8e8 vmov s13, r9 */
/* @0x1ec8ec vsub.f32 s14, s14, s13 */
/* @0x1ec8f0 vcmpe.f32 s15, s14 */
/* @0x1ec8f4 vmrs APSR_nzcv, fpscr */
/* @0x1ec8f8 blt 0x1ec914 <_ZN7CSprite4DrawEifffffjf+0x1f4> */
/* @0x1ec8fc vldr s14, [r3, #8] */
/* @0x1ec900 vcvt.f32.s32 s14, s14 */
/* @0x1ec904 vsub.f32 s14, s13, s14 */
/* @0x1ec908 vcmpe.f32 s15, s14 */
/* @0x1ec90c vmrs APSR_nzcv, fpscr */
/* @0x1ec910 bge 0x1ec7dc <_ZN7CSprite4DrawEifffffjf+0xbc> */
/* ── 剔除命中后的旁路：只有 g_isZeus 非 0 且「当前相机不是 2D」才继续画 ─────────
 *   池字 0xffffbcd4 → GOT 0x3ed92c → 0x5428e8 = g_isZeus（1 B，与 draw_background 的资产开关同址）。
 *   g_isZeus==0 → 1ec9c4 收尾（真的不画）。
 *   g_isZeus!=0 → g_CM（GOT 0x3edc7c → 0x48f78c，28 B）两次 GetActiveCamera()：
 *     第一次判空（空 → 收尾）；第二次取指针调 CCamera::Is2D()，非 0（是 2D）→ 收尾；
 *     只有「有相机且不是 2D」才 b 1ec7d8 照画。
 *   ⇒ 剔除判据只对 2D 相机成立；3D 相机下不信任 g_transRoomExtents。 */

/* @0x1ec914 ldr r3, [pc, #0x188] */
/* @0x1ec918 ldr r3, [r4, r3] */
/* @0x1ec91c ldrb r3, [r3] */
/* @0x1ec920 cmp r3, #0 */
/* @0x1ec924 beq 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1ec928 ldr r3, [pc, #0x178] */
/* @0x1ec92c ldr r6, [r4, r3] */
/* @0x1ec930 mov r0, r6 */
/* @0x1ec934 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1ec938 cmp r0, #0 */
/* @0x1ec93c beq 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1ec940 mov r0, r6 */
/* @0x1ec944 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1ec948 bl 0x16d398 <_ZN7CCamera4Is2DEv> */
/* @0x1ec94c cmp r0, #0 */
/* @0x1ec950 bne 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1ec954 b 0x1ec7d8 <_ZN7CSprite4DrawEifffffjf+0xb8> */
/* ── 脏标志命中：重算视野矩形后回到 1ec7a0（重新算 e，不重读标志）──────────────── */

/* @0x1ec958 bl 0x168d94 <_Z22UpdateTransRoomExtentsv> */
/* @0x1ec95c b 0x1ec7a0 <_ZN7CSprite4DrawEifffffjf+0x80> */
/* ── 剖析 Push(6, 15)：g_Profiler 是 .bss 里的 128 B 实例 ─────────────────────
 *   池字 0xffffbf1c → GOT 0x3edb74 → 0x757e80 = g_Profiler（对象本体地址，直接当 this 传）。
 *   r6 被重新读一次 image_number（Push 是外部调用，r6 caller-saved）。 */

/* @0x1ec960 ldr r3, [pc, #0x144] */
/* @0x1ec964 mov r1, #6 */
/* @0x1ec968 mov r2, #15 */
/* @0x1ec96c ldr r0, [r4, r3] */
/* @0x1ec970 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1ec974 ldr r6, [r5, #0x18] */
/* @0x1ec978 b 0x1ec778 <_ZN7CSprite4DrawEifffffjf+0x58> */
/* ── SWF 档（kind==1）：CSprite::DrawSWF(this, i, ox, oy, x, y, xs, ys, rot, colour, alpha) ─
 *   _ZN7CSprite7DrawSWFEifffffffjf = i + 7f + j + f = 10 个显式形参（含 this 11）：
 *   r0=this r1=i r2=(float)+0x24 r3=(float)+0x28，栈 [0]=x [4]=y [8]=xs [0xc]=ys [0x10]=rot
 *   [0x14]=colour [0x18]=alpha。
 *   ★ rot 在这里仍是**角度**（1ec7f0 的 π/180 换算还没执行），与纹理档不同。
 *   ★ 注意这里把 this 放进 r0 且把 ox/oy 放在 r2/r3 —— 与纹理档的 r0=tpe 不同：
 *     这条是被调方自己从 this 里再取 tpe。 */

/* @0x1ec97c ldr r2, [r5, #0x24] */
/* @0x1ec980 mov r1, r8 */
/* @0x1ec984 str r9, [sp] */
/* @0x1ec988 mov r0, r5 */
/* @0x1ec98c ldr r3, [r5, #0x28] */
/* @0x1ec990 vstr s18, [sp, #4] */
/* @0x1ec994 vmov s14, r2 */
/* @0x1ec998 vstr s16, [sp, #8] */
/* @0x1ec99c vstr s17, [sp, #12] */
/* @0x1ec9a0 vstr s19, [sp, #16] */
/* @0x1ec9a4 vmov s15, r3 */
/* @0x1ec9a8 str r10, [sp, #0x14] */
/* @0x1ec9ac vcvt.f32.s32 s14, s14 */
/* @0x1ec9b0 str r11, [sp, #0x18] */
/* @0x1ec9b4 vcvt.f32.s32 s15, s15 */
/* @0x1ec9b8 vmov r2, s14 */
/* @0x1ec9bc vmov r3, s15 */
/* @0x1ec9c0 bl 0x1ebf08 <_ZN7CSprite7DrawSWFEifffffffjf> */
/* ── 公共出口：g_bProfile 非 0 才 Pop（尾跳，无返回值）────────────────────────
 *   1ec9d0 又取 0xffffbf1c（g_Profiler）→ 与 1ec960 的 Push 严格配对。
 *   ⚠ 1ec9c4 也是「剔除命中且不旁路」「两条失败出口」「三条后端路径」的汇合点。 */

/* @0x1ec9c4 ldrb r3, [r7] */
/* @0x1ec9c8 cmp r3, #0 */
/* @0x1ec9cc beq 0x1ec87c <_ZN7CSprite4DrawEifffffjf+0x15c> */
/* @0x1ec9d0 ldr r3, [pc, #0xd4] */
/* @0x1ec9d4 ldr r0, [r4, r3] */
/* @0x1ec9d8 add sp, sp, #36 */
/* @0x1ec9dc vpop {d8, d9} */
/* @0x1ec9e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ec9e4 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* ── 骨骼档（kind==2）：CSkeletonSprite::Draw(this->[0x58], i, x, y, xs, ys, rot, colour, alpha) ─
 *   _ZN15CSkeletonSprite4DrawEifffffjf = i + 5f + j + f = 8 显式（含 this 9）：
 *   r0=[+0x58] r1=i r2=x r3=y，栈 [0]=xs [4]=ys [8]=rot [0xc]=colour [0x10]=alpha。
 *   colour/alpha 原样透传（没有 DrawSimple 那种自造 0xFFFFFFFF）。 */

/* @0x1ec9e8 ldr r0, [r5, #0x58] */
/* @0x1ec9ec mov r1, r8 */
/* @0x1ec9f0 vstr s16, [sp] */
/* @0x1ec9f4 vstr s17, [sp, #4] */
/* @0x1ec9f8 vstr s19, [sp, #8] */
/* @0x1ec9fc str r10, [sp, #0xc] */
/* @0x1eca00 str r11, [sp, #0x10] */
/* @0x1eca04 mov r2, r9 */
/* @0x1eca08 vmov r3, s18 */
/* @0x1eca0c bl 0xc03bc <_ZN15CSkeletonSprite4DrawEifffffjf> */
/* @0x1eca10 b 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* ── 纹理档（无 tpe 表）：GR_Texture_Drawi(贴图号, ox, oy, x, y, xs, ys, rot, colour, alpha) ─
 *   this+0x54 为 0 时改用 this+0x50：r3 = [r5+0x50]，r0 = [r3 + subimg*4] 得到**整数贴图号**。
 *   _Z15GR_Texture_Drawifffffffjf = int + 7f + j + f（10 参），落位与 tpe 版逐项同形，
 *   唯一差别是首参是 int 而不是 YYTPageEntry*。
 *   vdiv 在这里补做（1eca14）：π 已乘过，这里只除 180。 */

/* @0x1eca14 vdiv.f32 s19, s19, s15 */
/* @0x1eca18 ldr r1, [r5, #0x24] */
/* @0x1eca1c ldr r2, [r5, #0x28] */
/* @0x1eca20 ldr r3, [r5, #0x50] */
/* @0x1eca24 vmov s15, r1 */
/* @0x1eca28 vmov s13, r2 */
/* @0x1eca2c ldr r0, [r3, r8, lsl #2] */
/* @0x1eca30 vstr s18, [sp] */
/* @0x1eca34 mov r3, r9 */
/* @0x1eca38 vstr s16, [sp, #4] */
/* @0x1eca3c vstr s17, [sp, #8] */
/* @0x1eca40 str r10, [sp, #0x10] */
/* @0x1eca44 str r11, [sp, #0x14] */
/* @0x1eca48 vcvt.f32.s32 s15, s15 */
/* @0x1eca4c vstr s19, [sp, #12] */
/* @0x1eca50 vcvt.f32.s32 s13, s13 */
/* @0x1eca54 vmov r1, s15 */
/* @0x1eca58 vmov r2, s13 */
/* @0x1eca5c bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf> */
/* @0x1eca60 cmp r0, #0 */
/* @0x1eca64 bne 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* ── 第二条失败出口：与 1ec854 同构，只是串偏移换成池字 0x00165b20，汇合到 1ec864 ────── */

/* @0x1eca68 ldr r1, [pc, #0x40] */
/* @0x1eca6c ldr r3, [pc, #0x24] */
/* @0x1eca70 ldr r2, [r5, #0x5c] */
/* @0x1eca74 add r1, pc, r1 */
/* @0x1eca78 b 0x1ec864 <_ZN7CSprite4DrawEifffffjf+0x144> */
/* ── literal pool（0x1eca7c..0x1ecab0，14 字；objdump 把前三个与后两个译成了指令，非指令）──
 *   1eca7c 0x40490fdb = π            1eca80 0x43340000 = 180.0
 *   1eca84 0x00205508 GOT 基址加数（+1ec748 pc=1ec750 ⇒ 0x3f1c58）
 *   1eca88 0xffffbf18 → g_bProfile            1eca8c 0xffffd9e0 → g_transRoomExtentsDirty
 *   1eca90 0xffffc0b4 → GR_3DMode             1eca94 0x00165d34 → 串 0x35259c
 *   1eca98 0xffffbac4 → dbg_csol              1eca9c 0xffffe490 → CSprite::ms_ignoreCull
 *   1ecaa0 0xffffe500 → g_transRoomExtents    1ecaa4 0xffffbcd4 → g_isZeus
 *   1ecaa8 0xffffc024 → g_CM                  1ecaac 0xffffbf1c → g_Profiler
 *   1ecab0 0x00165b20 → 同一串（pc=1eca7c+0x165b20 = 0x35259c）
 *   ★ 1eca78 是**真指令**（b 1ec864），不是池字 —— 唯一的坑。 */

/* @0x1eca7c ldrdmi r0, r1, [r9], #-251 */
/* @0x1eca80 teqmi r4, #0 */
/* @0x1eca84 eoreq r5, r0, r8, lsl #10 */
/* @0x1eca88 .word 0xffffbf18 */
/* @0x1eca8c .word 0xffffd9e0 */
/* @0x1eca90 .word 0xffffc0b4 */
/* @0x1eca94 andseq r5, r6, r4, lsr sp */
/* @0x1eca98 .word 0xffffbac4 */
/* @0x1eca9c .word 0xffffe490 */
/* @0x1ecaa0 .word 0xffffe500 */
/* @0x1ecaa4 .word 0xffffbcd4 */
/* @0x1ecaa8 .word 0xffffc024 */
/* @0x1ecaac .word 0xffffbf1c */
/* @0x1ecab0 andseq r5, r6, r0, lsr #22 */
/* ══ 段 B · CSprite::DrawSimple 0x1ecab4 ═════════════════════════════════════════════════
 *   帧 64（push 24 + vpush {d8} 8 + sub 32）。四参全部落寄存器：this=r0 i=r1 x=r2 y=r3。
 *   ℹ 本段没有「取参」指令 —— 四参在 1ecacc/1ecad4/1ecad8/1ecabc 就搬完，之后只用 r5/r8/s17/s16。
 *
 *   与段 A 的三处结构性差别（都是逐指令可验的负事实）：
 *   ① 剔除闸只认 CSprite::ms_ignoreCull，**不看 GR_3DMode**：本函数的 literal pool 里根本没有
 *      0xffffc0b4 这个槽（见 1ecd98 段），而 0x1ecb20..0x1ecb38 直接拿 ms_ignoreCull 开闸。
 *   ② 纹理档只调 GR_Texture_Draw_Simple(tpe, x-ox, y-oy)（3 参），**没有 colour/alpha**，
 *      也没有旋转 —— 混合/透明度全靠 GR 当前状态。
 *   ③ SWF/骨骼两档的变换被写死：xs=ys=alpha=1.0、rot=0、colour=0xFFFFFFFF
 *      （注意是 4 字节全 1，不是内建里常用的 0x00FFFFFF）。 */

/* @0x1ecab4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1ecab8 vpush {d8} */
/* @0x1ecabc vmov s16, r3 */
/* @0x1ecac0 ldr r4, [pc, #0x2d0] */
/* @0x1ecac4 sub sp, sp, #32 */
/* @0x1ecac8 ldr r12, [pc, #0x2cc] */
/* @0x1ecacc mov r5, r0 */
/* @0x1ecad0 add r4, pc, r4 */
/* @0x1ecad4 mov r8, r1 */
/* @0x1ecad8 vmov s17, r2 */
/* @0x1ecadc ldr r6, [r4, r12] */
/* @0x1ecae0 ldrb r3, [r6] */
/* @0x1ecae4 cmp r3, #0 */
/* @0x1ecae8 bne 0x1ecc78 <_ZN7CSprite10DrawSimpleEiff+0x1c4> */
/* ── image_number <= 0 ⇒ 1ecb88 直接返回（r7 = [this+0x18]）────────────────────── */

/* @0x1ecaec ldr r7, [r5, #0x18] */
/* @0x1ecaf0 cmp r7, #0 */
/* @0x1ecaf4 ble 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* ── 子图号取模（与 Draw 同构），随后看视野矩形脏标志 ──────────────────────────
 *   1ecb04 池字 0xffffd9e0 → g_transRoomExtentsDirty；非 0 → 1ecc90：UpdateTransRoomExtents()
 *   再 b 1ecb20。⚠ 顺序与 Draw 不同：Draw 是先 dirty 后算 e，DrawSimple 先取模、再 dirty。 */

/* @0x1ecaf8 mov r0, r8 */
/* @0x1ecafc mov r1, r7 */
/* @0x1ecb00 bl 0x318dec <__aeabi_idivmod> */
/* @0x1ecb04 ldr r3, [pc, #0x294] */
/* @0x1ecb08 ldr r3, [r4, r3] */
/* @0x1ecb0c ldrb r3, [r3] */
/* @0x1ecb10 subs r8, r1, #0 */
/* @0x1ecb14 addlt r8, r8, r7 */
/* @0x1ecb18 cmp r3, #0 */
/* @0x1ecb1c bne 0x1ecc90 <_ZN7CSprite10DrawSimpleEiff+0x1dc> */
/* ── 剔除闸（唯一一道）：CSprite::ms_ignoreCull 非 0 就不剔 ─────────────────────
 *   池字 0xffffe490 → GOT 0x3f00e8 → 0x7530c9。
 *   同时把 kind（this+0x74）读进 r3 —— 后面 1ecba0 用它判 kind==2。 */

/* @0x1ecb20 ldr r3, [pc, #0x27c] */
/* @0x1ecb24 ldr r2, [r5, #0x2c] */
/* @0x1ecb28 ldr r3, [r4, r3] */
/* @0x1ecb2c ldrb r3, [r3] */
/* @0x1ecb30 cmp r3, #0 */
/* @0x1ecb34 ldr r3, [r5, #0x74] */
/* @0x1ecb38 beq 0x1ecba0 <_ZN7CSprite10DrawSimpleEiff+0xec> */
/* ── 分派（不剔时直接进）：1 → DrawSWF 1eccd0；2 → 骨骼 1ecc98；其余 → 纹理 1ecb4c ────── */

/* @0x1ecb3c cmp r3, #1 */
/* @0x1ecb40 beq 0x1eccd0 <_ZN7CSprite10DrawSimpleEiff+0x21c> */
/* @0x1ecb44 cmp r3, #2 */
/* @0x1ecb48 beq 0x1ecc98 <_ZN7CSprite10DrawSimpleEiff+0x1e4> */
/* ── 纹理档（有 tpe 表）：GR_Texture_Draw_Simple(tpe, x - ox, y - oy) ─────────────
 *   _Z22GR_Texture_Draw_SimpleP12YYTPageEntryff = 3 参，全部走寄存器（r0,r1,r2）。
 *   1ecb58/1ecb5c 用 vldr 读 +0x24/+0x28 再 vcvt.f32.s32 ⇒ 两个 int32 原点；
 *   1ecb6c/1ecb70 在这就把原点从 x/y 里减掉（Draw 是留给 GR 自己减）。
 *   ⇒ 这条与段 A 的 tpe 路互证：+0x24/+0x28 = 原点，不是 UV。 */

/* @0x1ecb4c ldr r3, [r5, #0x54] */
/* @0x1ecb50 cmp r3, #0 */
/* @0x1ecb54 beq 0x1ecd50 <_ZN7CSprite10DrawSimpleEiff+0x29c> */
/* @0x1ecb58 vldr s15, [r5, #36] */
/* @0x1ecb5c vldr s13, [r5, #40] */
/* @0x1ecb60 vcvt.f32.s32 s14, s15 */
/* @0x1ecb64 ldr r0, [r3, r8, lsl #2] */
/* @0x1ecb68 vcvt.f32.s32 s15, s13 */
/* @0x1ecb6c vsub.f32 s14, s17, s14 */
/* @0x1ecb70 vsub.f32 s15, s16, s15 */
/* @0x1ecb74 vmov r1, s14 */
/* @0x1ecb78 vmov r2, s15 */
/* @0x1ecb7c bl 0x174868 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff> */
/* @0x1ecb80 cmp r0, #0 */
/* @0x1ecb84 beq 0x1ecd28 <_ZN7CSprite10DrawSimpleEiff+0x274> */
/* ── 统一出口：g_bProfile 非 0 走 1ecc60 的 Pop，否则就地返回 ───────────────────
 *   ⚠ 1ecb88 被 8 条路汇合：image_number<=0、g_isZeus 三判（见 1ecc18 段 3 条）、
 *   骨骼档画完、SWF 档画完、tpe 失败串、贴图号档（画完/失败串），外加 1ecb8c 的自身落空。 */

/* @0x1ecb88 ldrb r3, [r6] */
/* @0x1ecb8c cmp r3, #0 */
/* @0x1ecb90 bne 0x1ecc60 <_ZN7CSprite10DrawSimpleEiff+0x1ac> */
/* @0x1ecb94 add sp, sp, #32 */
/* @0x1ecb98 vpop {d8} */
/* @0x1ecb9c pop {r4, r5, r6, r7, r8, pc} */
/* ── 剔除：kind==2 旁路；e = (float)(int)this+0x2c（**不乘缩放、不取绝对值**）────────
 *   与段 A 的差别：Draw 算 max(|w*xs|,|w*ys|)，DrawSimple 直接用 w 本体（r2 = [r5+0x2c]，
 *   在 1ecb24 读进 r2、1ecbac vmov s13,r2、1ecbb0 vcvt.f32.s32 转 float）。
 *   四个判据与 Draw 逐条同形（g_transRoomExtents 的 4 个 int32：(x1,y1,x2,y2)）：
 *     e < y1-y → 1ecc18；e < y-y2 → 1ecc18；e < x1-x → 1ecc18；e < x-x2 由 bge 反向表示。
 *   四条全过（bge 1ecb3c）→ 回到分派（kind 仍在 r3 里）。 */

/* @0x1ecba0 cmp r3, #2 */
/* @0x1ecba4 beq 0x1ecc98 <_ZN7CSprite10DrawSimpleEiff+0x1e4> */
/* @0x1ecba8 ldr r1, [pc, #0x1f8] */
/* @0x1ecbac vmov s13, r2 */
/* @0x1ecbb0 vcvt.f32.s32 s15, s13 */
/* @0x1ecbb4 ldr r2, [r4, r1] */
/* @0x1ecbb8 vldr s13, [r2, #4] */
/* @0x1ecbbc vcvt.f32.s32 s14, s13 */
/* @0x1ecbc0 vsub.f32 s14, s14, s16 */
/* @0x1ecbc4 vcmpe.f32 s15, s14 */
/* @0x1ecbc8 vmrs APSR_nzcv, fpscr */
/* @0x1ecbcc blt 0x1ecc18 <_ZN7CSprite10DrawSimpleEiff+0x164> */
/* @0x1ecbd0 vldr s13, [r2, #12] */
/* @0x1ecbd4 vcvt.f32.s32 s14, s13 */
/* @0x1ecbd8 vsub.f32 s14, s16, s14 */
/* @0x1ecbdc vcmpe.f32 s15, s14 */
/* @0x1ecbe0 vmrs APSR_nzcv, fpscr */
/* @0x1ecbe4 blt 0x1ecc18 <_ZN7CSprite10DrawSimpleEiff+0x164> */
/* @0x1ecbe8 vldr s13, [r2] */
/* @0x1ecbec vcvt.f32.s32 s14, s13 */
/* @0x1ecbf0 vsub.f32 s14, s14, s17 */
/* @0x1ecbf4 vcmpe.f32 s15, s14 */
/* @0x1ecbf8 vmrs APSR_nzcv, fpscr */
/* @0x1ecbfc blt 0x1ecc18 <_ZN7CSprite10DrawSimpleEiff+0x164> */
/* @0x1ecc00 vldr s14, [r2, #8] */
/* @0x1ecc04 vcvt.f32.s32 s14, s14 */
/* @0x1ecc08 vsub.f32 s14, s17, s14 */
/* @0x1ecc0c vcmpe.f32 s15, s14 */
/* @0x1ecc10 vmrs APSR_nzcv, fpscr */
/* @0x1ecc14 bge 0x1ecb3c <_ZN7CSprite10DrawSimpleEiff+0x88> */
/* ── 剔除命中后的旁路：g_isZeus 非 0 且相机存在且非 2D 才照画 ───────────────────
 *   池字 0xffffbcd4 → g_isZeus；0xffffc024 → g_CM。与段 A 1ec914..1ec954 逐条同构，
 *   只是回来时用 1ecc58 重读 kind 再跳 1ecb3c（因为 r3 已被寄存器溢出用了）。 */

/* @0x1ecc18 ldr r3, [pc, #0x18c] */
/* @0x1ecc1c ldr r3, [r4, r3] */
/* @0x1ecc20 ldrb r3, [r3] */
/* @0x1ecc24 cmp r3, #0 */
/* @0x1ecc28 beq 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecc2c ldr r3, [pc, #0x17c] */
/* @0x1ecc30 ldr r7, [r4, r3] */
/* @0x1ecc34 mov r0, r7 */
/* @0x1ecc38 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1ecc3c cmp r0, #0 */
/* @0x1ecc40 beq 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecc44 mov r0, r7 */
/* @0x1ecc48 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1ecc4c bl 0x16d398 <_ZN7CCamera4Is2DEv> */
/* @0x1ecc50 cmp r0, #0 */
/* @0x1ecc54 bne 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecc58 ldr r3, [r5, #0x74] */
/* @0x1ecc5c b 0x1ecb3c <_ZN7CSprite10DrawSimpleEiff+0x88> */
/* ── Pop 出口（尾跳）：池字 0xffffbf1c → g_Profiler ───────────────────────────── */

/* @0x1ecc60 ldr r3, [pc, #0x14c] */
/* @0x1ecc64 ldr r0, [r4, r3] */
/* @0x1ecc68 add sp, sp, #32 */
/* @0x1ecc6c vpop {d8} */
/* @0x1ecc70 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1ecc74 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* ── 剖析 Push(6, **16**)：与 Draw 的 (6,15) 只差编号 ⇒ 两段在剖析器里是两个段 ───────── */

/* @0x1ecc78 ldr r3, [pc, #0x134] */
/* @0x1ecc7c mov r1, #6 */
/* @0x1ecc80 mov r2, #16 */
/* @0x1ecc84 ldr r0, [r4, r3] */
/* @0x1ecc88 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1ecc8c b 0x1ecaec <_ZN7CSprite10DrawSimpleEiff+0x38> */
/* ── 脏标志命中：重算视野矩形，回 1ecb20（即重新过 ms_ignoreCull 闸）────────────── */

/* @0x1ecc90 bl 0x168d94 <_Z22UpdateTransRoomExtentsv> */
/* @0x1ecc94 b 0x1ecb20 <_ZN7CSprite10DrawSimpleEiff+0x6c> */
/* ── 骨骼档（kind==2）：恒等变换 CSkeletonSprite::Draw(i, x, y, 1, 1, 0, 0xFFFFFFFF, 1) ─
 *   r12 = 0x3F800000 = 1.0f 填 [sp]/[sp+4]/[sp+0x10]；r2=0 填 [sp+8]=rot；
 *   mvn r3,#0 = 0xFFFFFFFF 填 [sp+0xc]=colour。
 *   ★ colour 是 0xFFFFFFFF（含 alpha 字节），不是 0x00FFFFFF —— 与内建里默认的白色不同。 */

/* @0x1ecc98 ldr r0, [r5, #0x58] */
/* @0x1ecc9c mov r12, #1065353216 */
/* @0x1ecca0 mov r2, #0 */
/* @0x1ecca4 mvn r3, #0 */
/* @0x1ecca8 str r2, [sp, #0x8] */
/* @0x1eccac mov r1, r8 */
/* @0x1eccb0 str r3, [sp, #0xc] */
/* @0x1eccb4 vmov r2, s17 */
/* @0x1eccb8 vmov r3, s16 */
/* @0x1eccbc str r12, [sp] */
/* @0x1eccc0 str r12, [sp, #0x4] */
/* @0x1eccc4 str r12, [sp, #0x10] */
/* @0x1eccc8 bl 0xc03bc <_ZN15CSkeletonSprite4DrawEifffffjf> */
/* @0x1ecccc b 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* ── SWF 档（kind==1）：恒等变换 CSprite::DrawSWF(this, i, ox, oy, x, y, 1, 1, 0, 0xFFFFFFFF, 1) ─
 *   r12=1.0f 填 [sp+8]/[sp+0xc]/[sp+0x18]；r5 被 1ecce4 清 0 后填 [sp+0x10]=rot=0
 *   （this 已在 1eccdc 搬进 r0，r5 之后不再需要）；lr=-1 填 [sp+0x14]=colour。
 *   与段 A 的 SWF 路相比：ox/oy 仍来自 +0x24/+0x28（vcvt 后进 r2/r3），x/y 走 s17/s16。 */

/* @0x1eccd0 ldr r2, [r5, #0x24] */
/* @0x1eccd4 mov r12, #1065353216 */
/* @0x1eccd8 ldr r3, [r5, #0x28] */
/* @0x1eccdc mov r0, r5 */
/* @0x1ecce0 mvn lr, #0 */
/* @0x1ecce4 mov r5, #0 */
/* @0x1ecce8 vmov s14, r2 */
/* @0x1eccec vstr s17, [sp] */
/* @0x1eccf0 vmov s15, r3 */
/* @0x1eccf4 vstr s16, [sp, #4] */
/* @0x1eccf8 vcvt.f32.s32 s14, s14 */
/* @0x1eccfc mov r1, r8 */
/* @0x1ecd00 str r5, [sp, #0x10] */
/* @0x1ecd04 str lr, [sp, #0x14] */
/* @0x1ecd08 str r12, [sp, #0x8] */
/* @0x1ecd0c str r12, [sp, #0xc] */
/* @0x1ecd10 str r12, [sp, #0x18] */
/* @0x1ecd14 vcvt.f32.s32 s15, s15 */
/* @0x1ecd18 vmov r2, s14 */
/* @0x1ecd1c vmov r3, s15 */
/* @0x1ecd20 bl 0x1ebf08 <_ZN7CSprite7DrawSWFEifffffffjf> */
/* @0x1ecd24 b 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* ── 失败出口（tpe 版）：串 0x00165860（pc 1ecd3c ⇒ 0x35259c），%s = this+0x5c ───────── */

/* @0x1ecd28 ldr r1, [pc, #0x88] */
/* @0x1ecd2c ldr r3, [pc, #0x88] */
/* @0x1ecd30 ldr r2, [r5, #0x5c] */
/* @0x1ecd34 add r1, pc, r1 */
/* @0x1ecd38 ldr r3, [r4, r3] */
/* @0x1ecd3c ldr r0, [r3] */
/* @0x1ecd40 ldr r3, [r0] */
/* @0x1ecd44 ldr r3, [r3, #0xc] */
/* @0x1ecd48 blx r3 */
/* @0x1ecd4c b 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* ── 纹理档（无 tpe 表）：GR_Texture_Draw_Simplei(贴图号, x - ox, y - oy) ─────────────
 *   this+0x54 为 0 ⇒ 用 this+0x50 的 int 表；_Z22GR_Texture_Draw_Simpleiff = 3 参。
 *   原点仍在这边先减（1ecd68/1ecd6c），与 tpe 版同构。 */

/* @0x1ecd50 vldr s13, [r5, #36] */
/* @0x1ecd54 vcvt.f32.s32 s14, s13 */
/* @0x1ecd58 vldr s13, [r5, #40] */
/* @0x1ecd5c ldr r3, [r5, #0x50] */
/* @0x1ecd60 ldr r0, [r3, r8, lsl #2] */
/* @0x1ecd64 vcvt.f32.s32 s15, s13 */
/* @0x1ecd68 vsub.f32 s14, s17, s14 */
/* @0x1ecd6c vsub.f32 s15, s16, s15 */
/* @0x1ecd70 vmov r1, s14 */
/* @0x1ecd74 vmov r2, s15 */
/* @0x1ecd78 bl 0x174498 <_Z22GR_Texture_Draw_Simpleiff> */
/* @0x1ecd7c cmp r0, #0 */
/* @0x1ecd80 bne 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* ── 失败出口（贴图号版）：串 0x00165804（pc 1ecd98 ⇒ 同一地址 0x35259c），汇合到 1ecd38 ── */

/* @0x1ecd84 ldr r1, [pc, #0x34] */
/* @0x1ecd88 ldr r3, [pc, #0x2c] */
/* @0x1ecd8c ldr r2, [r5, #0x5c] */
/* @0x1ecd90 add r1, pc, r1 */
/* @0x1ecd94 b 0x1ecd38 <_ZN7CSprite10DrawSimpleEiff+0x284> */
/* ── literal pool（0x1ecd98..0x1ecdc0，11 字）──────────────────────────────────────
 *   1ecd98 0x00205180 GOT 基址加数（+1ecad8 pc=1ecae0 ⇒ 0x3f1c58，与 Draw 同一个基址）
 *   1ecd9c g_bProfile   1ecda0 g_transRoomExtentsDirty   1ecda4 CSprite::ms_ignoreCull
 *   1ecda8 g_transRoomExtents   1ecdac g_isZeus   1ecdb0 g_CM   1ecdb4 g_Profiler
 *   1ecdb8 0x00165860 串   1ecdbc 0xffffbac4 dbg_csol   1ecdc0 0x00165804 串
 *   ★ 缺 0xffffc0b4（GR_3DMode）：本函数**没有** GR_3DMode 闸，见段首 ①。
 *   ★ 也缺 π/180 两个字 ⇒ 本函数没有任何角度换算。
 *   1ecdc4 起是**下一个函数** CSprite::DrawStretched（draw_sprite_stretched_ext 用），不属于本卡。 */

/* @0x1ecd98 eoreq r5, r0, r0, lsl #3 */
/* @0x1ecd9c .word 0xffffbf18 */
/* @0x1ecda0 .word 0xffffd9e0 */
/* @0x1ecda4 .word 0xffffe490 */
/* @0x1ecda8 .word 0xffffe500 */
/* @0x1ecdac .word 0xffffbcd4 */
/* @0x1ecdb0 .word 0xffffc024 */
/* @0x1ecdb4 .word 0xffffbf1c */
/* @0x1ecdb8 andseq r5, r6, r0, ror #16 */
/* @0x1ecdbc .word 0xffffbac4 */
/* @0x1ecdc0 andseq r5, r6, r4, lsl #16 */
/* ══ 段 C · CSprite::DrawTiled 0x1ed1dc ═════════════════════════════════════════════════
 *   帧 112（push 36 + vpush {d8,d9,d10} 24 + sub 52）。形参 13 个（含 this 14）：
 *     this=r0 i=r1 f1=r2 f2=r3，栈 10 字：[112]=f3 [116]=f4 [120]=b1 [124]=b2 [128]=f5
 *                                    [132]=f6 [136]=f7 [140]=f8 [144]=colour [148]=alpha
 *   语义（调用方 bank_0053.c 122e90 / 122f74 两处落位互证）：f1,f2=x,y；f3,f4=xscale,yscale；
 *     b1,b2=两向平铺开关（两个内建都写死 1）；f5,f6 两个内建都写死 0；f7,f8=(float)Run_Room->[0x10]/[0x14]
 *     =房间宽高（CRoom 卡：+0x10=640 / +0x14=480）；colour/alpha 见 1ed2a8 段。
 *
 *   ⚠ 本段比 A/B 少了四样东西，全是负事实（调用清单只有 7 条：idivmod、2 个 GR、2 个 blx、2 个 b）：
 *     ① 没有 image_number 之外的任何前置检查（无 dirty 重算、无剔除、无 GR_3DMode、无 ms_ignoreCull）；
 *     ② 没有 CProfiler Push/Pop；③ 没有旋转（形参里根本没有角度）；
 *     ④ 没有 kind==2（骨骼）分支 —— 只有 kind==1 跳 DrawSWFTiled，其余全落到纹理两路。
 *   于是 tpe 表为 0 且 +0x50 也为 0 时，kind==2 的精灵会走 GR_Texture_Draw_Tiledi 用垃圾贴图号（open）。 */

/* @0x1ed1dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ed1e0 vpush {d8, d9, d10} */
/* @0x1ed1e4 sub sp, sp, #52 */
/* @0x1ed1e8 vldr s21, [sp, #112] */
/* @0x1ed1ec ldr r5, [r0, #0x18] */
/* @0x1ed1f0 mov r4, r0 */
/* @0x1ed1f4 mov r10, r2 */
/* @0x1ed1f8 mov r6, r3 */
/* @0x1ed1fc cmp r5, #0 */
/* @0x1ed200 vldr s20, [sp, #116] */
/* @0x1ed204 ldrb r9, [sp, #0x78] */
/* @0x1ed208 vldr s19, [sp, #128] */
/* @0x1ed20c ldrb r8, [sp, #0x7c] */
/* @0x1ed210 vldr s18, [sp, #132] */
/* @0x1ed214 vldr s17, [sp, #136] */
/* @0x1ed218 vldr s16, [sp, #140] */
/* @0x1ed21c ldr r7, [sp, #0x90] */
/* @0x1ed220 ldr r11, [sp, #0x94] */
/* ── image_number <= 0 ⇒ 1ed2b4 纯返回（没有 Pop，因为本函数从不 Push）────────────── */

/* @0x1ed224 ble 0x1ed2b4 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0xd8> */
/* ── 取模 + kind==1 旁路 ──────────────────────────────────────────────────────
 *   ⚠ 取模只做 addlt 修正（没有像 A/B 那样把余数先 subs 出来）。r1 直接就是归一化后的子图号。
 *   1ed234 先读 kind：==1 直接跳 1ed37c 尾调 DrawSWFTiled（**在选 tpe 表之前**）。 */

/* @0x1ed228 mov r0, r1 */
/* @0x1ed22c mov r1, r5 */
/* @0x1ed230 bl 0x318dec <__aeabi_idivmod> */
/* @0x1ed234 ldr r3, [r4, #0x74] */
/* @0x1ed238 cmp r1, #0 */
/* @0x1ed23c addlt r1, r1, r5 */
/* @0x1ed240 cmp r3, #1 */
/* @0x1ed244 beq 0x1ed37c <_ZN7CSprite9DrawTiledEiffffbbffffjf+0x1a0> */
/* ── 纹理档（有 tpe 表）：GR_Texture_Draw_Tiled(tpe, ox, oy, f1, f2, f3, f4, b1, b2, f5, f6, f7, f8, colour, alpha) ─
 *   _Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf = P + 6f + 2b + 4f + j + f（15 参）：
 *   r0=tpe r1=ox r2=oy r3=f1；栈 [0]=f2 [4]=f3 [8]=f4 [0xc]=b1 [0x10]=b2 [0x14]=f5
 *   [0x18]=f6 [0x1c]=f7 [0x20]=f8 [0x24]=colour [0x28]=alpha —— 11 字栈，正好是 sub 52 的用途。
 *   ★ 原生形参 13 个里有 10 个进本调用的栈/寄存器，剩下的 ox/oy 来自 this+0x24/+0x28（int32→float）。 */

/* @0x1ed248 ldr r0, [r4, #0x54] */
/* @0x1ed24c cmp r0, #0 */
/* @0x1ed250 beq 0x1ed2f0 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0x114> */
/* @0x1ed254 ldr r0, [r0, r1, lsl #2] */
/* @0x1ed258 mov r3, r10 */
/* @0x1ed25c str r6, [sp] */
/* @0x1ed260 ldr r1, [r4, #0x24] */
/* @0x1ed264 vstr s21, [sp, #4] */
/* @0x1ed268 ldr r2, [r4, #0x28] */
/* @0x1ed26c vstr s20, [sp, #8] */
/* @0x1ed270 str r9, [sp, #0xc] */
/* @0x1ed274 vstr s19, [sp, #20] */
/* @0x1ed278 vmov s15, r1 */
/* @0x1ed27c str r8, [sp, #0x10] */
/* @0x1ed280 vstr s18, [sp, #24] */
/* @0x1ed284 vstr s17, [sp, #28] */
/* @0x1ed288 vcvt.f32.s32 s15, s15 */
/* @0x1ed28c vstr s16, [sp, #32] */
/* @0x1ed290 str r7, [sp, #0x24] */
/* @0x1ed294 str r11, [sp, #0x28] */
/* @0x1ed298 vmov r1, s15 */
/* @0x1ed29c vmov s15, r2 */
/* @0x1ed2a0 vcvt.f32.s32 s15, s15 */
/* @0x1ed2a4 vmov r2, s15 */
/* @0x1ed2a8 bl 0x1762b0 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf> */
/* @0x1ed2ac cmp r0, #0 */
/* @0x1ed2b0 beq 0x1ed2c0 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0xe4> */
/* ── 唯一出口（纯返回）：成功路径 1ed2ac 直接落到这里，失败路径 1ed378 也 b 到这里 ─────── */

/* @0x1ed2b4 add sp, sp, #52 */
/* @0x1ed2b8 vpop {d8, d9, d10} */
/* @0x1ed2bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 失败出口（tpe 版）：串偏移池字 0x001652c4（add 在 1ed2d0 ⇒ pc 1ed2d8，得 0x35259c），%s = this+0x5c ─
 *   ⚠ 这里用的是 `ldr r3,[pc,r3]` 的**正偏移**形式（池字 0x0020044c），因为 r4 被 this 占着，
 *     没有像 A/B 那样留一个 GOT 基址寄存器；算出来的槽仍是 0x3ed71c（dbg_csol）。 */

/* @0x1ed2c0 ldr r3, [pc, #0xf8] */
/* @0x1ed2c4 ldr r1, [pc, #0xf8] */
/* @0x1ed2c8 ldr r3, [pc, r3] */
/* @0x1ed2cc ldr r2, [r4, #0x5c] */
/* @0x1ed2d0 add r1, pc, r1 */
/* @0x1ed2d4 ldr r0, [r3] */
/* @0x1ed2d8 ldr r3, [r0] */
/* @0x1ed2dc ldr r3, [r3, #0xc] */
/* @0x1ed2e0 blx r3 */
/* @0x1ed2e4 add sp, sp, #52 */
/* @0x1ed2e8 vpop {d8, d9, d10} */
/* @0x1ed2ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 纹理档（无 tpe 表）：GR_Texture_Draw_Tiledi(贴图号, ox, oy, f1, …) ─────────────
 *   _Z21GR_Texture_Draw_Tilediffffffbbffffjf = int + 6f + 2b + 4f + j + f（15 参），
 *   与 P 版逐项同形，首参换成 int 贴图号（this+0x50 的表按子图索引）。
 *   栈布局与 1ed248 段**逐字节相同**（只是 store 顺序不同）。 */

/* @0x1ed2f0 ldr r12, [r4, #0x24] */
/* @0x1ed2f4 mov r3, r10 */
/* @0x1ed2f8 ldr r2, [r4, #0x50] */
/* @0x1ed2fc vmov s15, r12 */
/* @0x1ed300 ldr r0, [r2, r1, lsl #2] */
/* @0x1ed304 vcvt.f32.s32 s15, s15 */
/* @0x1ed308 str r6, [sp] */
/* @0x1ed30c ldr r2, [r4, #0x28] */
/* @0x1ed310 vstr s21, [sp, #4] */
/* @0x1ed314 vstr s20, [sp, #8] */
/* @0x1ed318 str r9, [sp, #0xc] */
/* @0x1ed31c str r8, [sp, #0x10] */
/* @0x1ed320 vstr s19, [sp, #20] */
/* @0x1ed324 vstr s18, [sp, #24] */
/* @0x1ed328 vstr s17, [sp, #28] */
/* @0x1ed32c vstr s16, [sp, #32] */
/* @0x1ed330 str r7, [sp, #0x24] */
/* @0x1ed334 str r11, [sp, #0x28] */
/* @0x1ed338 vmov r1, s15 */
/* @0x1ed33c vmov s15, r2 */
/* @0x1ed340 vcvt.f32.s32 s15, s15 */
/* @0x1ed344 vmov r2, s15 */
/* @0x1ed348 bl 0x175e90 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf> */
/* @0x1ed34c cmp r0, #0 */
/* @0x1ed350 bne 0x1ed2b4 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0xd8> */
/* ── 失败出口（贴图号版）：串偏移 0x00165230（pc 1ed36c ⇒ 0x35259c），汇合到 1ed368 ──── */

/* @0x1ed354 ldr r3, [pc, #0x6c] */
/* @0x1ed358 ldr r1, [pc, #0x6c] */
/* @0x1ed35c ldr r3, [pc, r3] */
/* @0x1ed360 ldr r2, [r4, #0x5c] */
/* @0x1ed364 add r1, pc, r1 */
/* @0x1ed368 ldr r0, [r3] */
/* @0x1ed36c ldr r3, [r0] */
/* @0x1ed370 ldr r3, [r3, #0xc] */
/* @0x1ed374 blx r3 */
/* @0x1ed378 b 0x1ed2b4 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0xd8> */
/* ── kind==1：把整块形参**原样写回自己的入参槽**，然后尾调 CSprite::DrawSWFTiled ────────
 *   1ed37c..1ed3a4 十条 vstr/str 写的正是 112/116/120/124/128/132/136/140/144/148 ——
 *   也就是入口 sp 上的那 10 个字；随后 r2=r10、r3=r6 复原两个寄存器形参，撤帧、pop、`b`。
 *   ⇒ DrawSWFTiled 与 DrawTiled 原型完全相同（functions.tsv: 1ecfb8 size 548 13 参，逐字同尾串），
 *     这条尾调是纯转发，没有任何字段被重新解释。 */

/* @0x1ed37c vstr s21, [sp, #112] */
/* @0x1ed380 mov r0, r4 */
/* @0x1ed384 vstr s20, [sp, #116] */
/* @0x1ed388 str r9, [sp, #0x78] */
/* @0x1ed38c str r8, [sp, #0x7c] */
/* @0x1ed390 vstr s19, [sp, #128] */
/* @0x1ed394 vstr s18, [sp, #132] */
/* @0x1ed398 vstr s17, [sp, #136] */
/* @0x1ed39c vstr s16, [sp, #140] */
/* @0x1ed3a0 str r7, [sp, #0x90] */
/* @0x1ed3a4 str r11, [sp, #0x94] */
/* @0x1ed3a8 mov r2, r10 */
/* @0x1ed3ac mov r3, r6 */
/* @0x1ed3b0 add sp, sp, #52 */
/* @0x1ed3b4 vpop {d8, d9, d10} */
/* @0x1ed3b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ed3bc b 0x1ecfb8 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf> */
/* ── literal pool（0x1ed3c0..0x1ed3cc，4 字；全是**正**偏移，因为 GOT(0x3ed7xx) 在 .text(0x1e…) 之上）──
 *   1ed3c0 0x0020044c → pc(1ed2d0)+ = 0x3ed71c（dbg_csol）
 *   1ed3c4 0x001652c4 → pc(1ed2d0)+ = 0x35259c（错误串）
 *   1ed3c8 0x002003b8 → pc(1ed364)+ = 0x3ed71c（同一槽，第二条失败路）
 *   1ed3cc 0x00165230 → pc(1ed36c)+ = 0x35259c（同一串）
 *   ★ 只有 dbg_csol 与错误串两种常量 ⇒ 本函数对 g_* 绘制状态**一个都不读**（无 profile/无剔除/无相机）。 */

/* @0x1ed3c0 eoreq r0, r0, r12, asr #8 */
/* @0x1ed3c4 andseq r5, r6, r4, asr #5 */
/* @0x1ed3c8 .word 0x002003b8 */
/* @0x1ed3cc andseq r5, r6, r0, lsr r2 */

/* ── 收束：三段的共同结论 ───────────────────────────────────────────
 *   1. 子图号归一化三处同构（idivmod + addlt），是本族唯一的「参数修正」。
 *   2. 后端分派是 this+0x74：0 纹理 / 1 SWF / 2 骨骼；纹理档再按 this+0x54 有无 tpe 表二选一。
 *      Draw 与 DrawSimple 都保留 1 和 2；DrawTiled 只留 1（2 掉进纹理路）。
 *   3. 深度、混合、alpha 全部由调用方给：本卡三条函数零全局写（68 条真 store，基址全 sp），
 *      也没有一条 GR_3D_Set_Depth —— 深度是 DoSlowDrawRoom 在调用前设的。
 *   4. 六条失败出口（每函数两条）共用同一句 .rodata 0x35259c 与同一个 dbg_csol 虚槽 [vtable+0xc]。
 *
 * ── open ─────────────────────────────────────────────────────────
 *   1. CSprite 字段官方名未证：+0x2c（方形半边长量）、+0x50（贴图号表）、+0x54（tpe 表）、
 *      +0x58（CSkeletonSprite）、+0x74（档位）都只有「用法」证据，没有符号/字符串证据。
 *   2. GR_Texture_Draw_Tiled 的第 9..12 个形参（f5,f6,f7,f8）名字未定：调用方给的
 *      f7,f8 = 房间宽高、f5,f6 = 0，只能说是「平铺边界两对」。
 *   3. DrawTiled 对 kind==2（骨骼）没有分支：是遗漏还是约定「骨骼精灵不平铺」未定；
 *      若 +0x50 也为 0，会以贴图号 0 去画。
 *   4. g_isZeus 与 GR_3DMode 的关系未定：前者只在「剔除命中」后决定是否看相机，
 *      后者直接跳过剔除；两者都非 0 时会不会互斥没有证据。
 */
