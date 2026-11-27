/* cally 逆向卡：DoSlowDrawRoom（原版 libyoyo.so，armv7）
 * @func 0x1b06a0 0x1b0b04  size 1124  281 条（1b0a88..1b0a98 为 literal pool，5 字）
 * 级别: 正文（三条绘制流按 depth 交错、实例与层项字段表、Draw 事件派发、两条精灵输出路径、
 *             背景 DrawPart 调用协议已逐条钉住；未钉：层项 56 字节数组由谁生成、11000.0 上限的来历、
 *             CBackground::DrawPart 后四个形参的名字）
 * 符号: _Z14DoSlowDrawRoomP9tagYYRECT → void DoSlowDrawRoom(tagYYRECT* pRect)
 * 同层: Draw_Room 0x1b3e98（房间绘制外层）、CRoom::UpdateLayers 0x1abfa0、
 *       ParticleSystem_LargestDepth 0x1a570c / DrawDepth 0x1a583c / NextDepth 0x1a579c、
 *       CSprite::Draw 0x1ec720 / DrawSimple 0x1ecab4、CBackground::DrawPart 0xc2184、
 *       Graphics::Flush 0x1852ec（本函数收尾是尾调）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   给定一个裁剪矩形 pRect（tagYYRECT = 4 个 int32：x1,y1,x2,y2），把房间的
 *   「层项数组」「实例绘制链」「粒子系统」三股流按 depth 合成一条递增序列输出。
 *   三股流各自只保留一个游标，比较只发生在游标之间 —— 说明三股流本已按 depth 有序（结构推断）。
 *
 * ── 三股流的入口（全部来自 CRoom）───────────────────────────────
 *   实例链: room+0x84 = **头**，next 在 CInstance+0x17c、prev 在 +0x178；room+0x80 是**同一个链的尾**，
 *   ⚠ 修正（2026-10-28，CRoom::DeSerialise 0x1acd58..0x1acda4 实证）：不是『两条链』，也不是 +0x80 当头
 *   瓦片表    : room+0xb8 条数、room+0xbc 容量、room+0xc0 基址，记录 56 字节（=14 字段）
 *   ⚠ 修正（batchAH，cards/DrawTheRoom.c + cards/CRoom_DeSerialise.c）：这不是「层项数组」，
 *     是 tile 表（AddTile 0x1ac240 维护），名称早先写错了，语义（逐记录画）不变
 *   粒子      : ParticleSystem_LargestDepth()/NextDepth() 给出当前 depth 游标，-1e8 表示空
 *
 * ── 层项 56 字节记录（本函数读到的字段，偏移/类型均为实测）─────────
 *   +0x00 float x            +0x04 float y
 *   +0x08 int   背景号（喂 Background_Exists/Background_Data，不是精灵号）
 *   +0x0c int / +0x10 int / +0x14 int / +0x18 int  源矩形四边（vcvt.f32.s32 后才参与 DrawPart）
 *   +0x14/+0x18 同时当 tile 计数用：x0 = x + (float)(int)[+0x14]*[+0x24]
 *   +0x1c float depth（与实例 +0x180、粒子游标同域比较）
 *   +0x24 float tile 宽   +0x28 float tile 高   +0x2c/+0x30 float（原样进 DrawPart 末两参）
 *   +0x34 byte 「没有实例也要画」标志（r4==0 时唯一的放行条件）
 *   未读字段：+0x20（56 字节里唯一没被本函数碰过的 4 字节）
 *
 * ── CInstance 字段（本函数读到的，与 live-oracle 契约同址）─────────
 *   +0x65 byte 非 0 才画     +0x68/+0x69 byte 非 0 就跳过
 *   +0x80 CObjectGM*（喂 HasEventRecursive）
 *   +0x84 否（那是 CRoom 的）  +0x8c int 精灵号（喂 Sprite_Data）
 *   +0x90 float image_index（(int) 截断给 Draw、floorf 给 DrawSimple）
 *   +0x98 float 量①  +0x9c float 量②  +0xa0 float 量③  +0xa4 float 量⑤  +0xa8 uint32 量④
 *        （按 CSprite::Draw 的形参顺序落位：见 1b0a04 段，故 0x98/0x9c/0xa0 = 双轴缩放/角度，
 *          0xa8 = blend（白=0x00FFFFFF），0xa4 = alpha）
 *   +0xb4 float x  +0xb8 float y  +0x180 float depth  +0x17c CInstance* next
 *
 * ── 唯一的全局写：g_drawInst ───────────────────────────────────
 *   GOT 0x3ED93C → 0x479CAC（.bss）。派发 Draw 事件与调 CSprite 之前写 [0x479CAC] = inst，
 *   之后写回 0（不是恢复旧值：旧值只被压到 [sp+0x24] 当「地址」用，见 1b096c 段）。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 *
 * ── 本批补证：房间慢绘制路径（逐条锚在下方）──
 *   GR_3D_Set_Depth ×3（按深度分档设深度）+ ParticleSystem_LargestDepth ×1（粒子层分界）
 *   open 1 三条深度档与 tile/instance 交错顺序
 *   open 2 与 DrawTheRoom 条件树（room+0xdc/0xb8/0x88）的对应
 */

/* ── 装载：常量、GOT 基址、房间指针、两条流的头 ────────────────────
 *   帧：push {r4-r11,lr} + vpush {d8-d11} + sub sp,#44（44 字节临时区，Draw 的栈上传参用）
 *   s17 = 11000.0（字面量 1b0a88 = 0x462be000）：后文三处 GR_3D_Set_Depth 之前的深度上限
 *   s20 = -1e8（字面量 1b0a8c = 0xccbebc20）：粒子「空」哨兵，与 LargestDepth 的返回值同域
 *   s21 = 1.0；r10 = 0x00FFFFFF（mvn r10,#-16777216；后文当 blend 缺省值比较）
 *   r7 = GOT 基址 0x3F1C58（1b0a90 的 0x241588 与后续 pc 相加得到）
 *   r6 = [GOT 0x3ED930] = 0x54298C = &Run_Room（.rel.dyn R_ARM_RELATIVE，加数即 .bss 地址）
 *   [r6] = CRoom*：+0x84 绘制链头、+0xb8 层项条数、+0xc0 层项基址
 *   s16 = 粒子 depth 游标 = ParticleSystem_LargestDepth()（r0 直接进 s16）
 *   r5 = i（层项下标），r4 = 当前实例，r11 = 当前层项指针，r8 = 0（清 g_drawInst 用的常量）
 */

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
/* ── 主循环头：i 只走层项数组，实例指针独立推进 ────────────────────
 *   i >= room->[0xb8] → 层项耗尽，去 1b08d4（此后只画实例）
 *   entry = room->[0xc0] + i*56：rsb r12,r5,r5,lsl #3 → r12 = i*7；再 lsl #3 → i*56
 */

/* @0x1b06f4 cmp r5, r3 */
/* @0x1b06f8 bge 0x1b08d4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x234> */
/* @0x1b06fc rsb r12, r5, r5, lsl #3 */
/* @0x1b0700 ldr r2, [r1, #0xc0] */
/* @0x1b0704 cmp r4, #0 */
/* @0x1b0708 add r11, r2, r12, lsl #3 */
/* ── 实例指针为空：是否画层项由层项自己的 +0x34 决定 ─────────────── */

/* @0x1b070c beq 0x1b09b0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x310> */
/* ── 实例可见性三连测（任一不满足 → 1b09a8 跳过该实例，i 不动）─────
 *   [inst+0x68] != 0 → 跳过；[inst+0x69] != 0 → 跳过；[inst+0x65] == 0 → 跳过
 */

/* @0x1b0710 ldrb r2, [r4, #0x68] */
/* @0x1b0714 cmp r2, #0 */
/* @0x1b0718 bne 0x1b09a8 <_Z14DoSlowDrawRoomP9tagYYRECT+0x308> */
/* @0x1b071c ldrb r2, [r4, #0x69] */
/* @0x1b0720 cmp r2, #0 */
/* @0x1b0724 bne 0x1b09a8 <_Z14DoSlowDrawRoomP9tagYYRECT+0x308> */
/* @0x1b0728 ldrb r2, [r4, #0x65] */
/* @0x1b072c cmp r2, #0 */
/* @0x1b0730 beq 0x1b09a8 <_Z14DoSlowDrawRoomP9tagYYRECT+0x308> */
/* ── i<条数时先去层项闸门（1b09b0），i>=条数则直接进三路汇合 ──────── */

/* @0x1b0734 cmp r5, r3 */
/* @0x1b0738 blt 0x1b09b0 <_Z14DoSlowDrawRoomP9tagYYRECT+0x310> */
/* ── 三路汇合：先看粒子游标是否比实例更靠前 ────────────────────────
 *   inst==0 → 1b08e8；s16(粒子) > inst->[0x180](深度) → 1b08e8（先把粒子吐出来）
 *   否则：层项深度 s14 = entry->[0x1c]
 *     s14 <= inst 深度 → 1b0940（画实例）
 *     s14 >  inst 深度 → 1b076c（画层项，并把深度夹到 11000.0）
 */

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
/* ── 层项（背景切片）绘制：深度夹紧 → 建矩形 → 背景号查询 → 剔除 ────
 *   GR_3D_Set_Depth(min(s14, 11000.0))：vcmpe/vmovle/vmovgt 三连，<=11000 取自身，否则取上限
 */

/* @0x1b076c vcmpe.f32 s14, s17 */
/* @0x1b0770 vmrs APSR_nzcv, fpscr */
/* @0x1b0774 vmovle r0, s14 */
/* @0x1b0778 vmovgt r0, s17 */
/* @0x1b077c bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* ── 由层项算覆盖矩形（两组 min/max）──────────────────────────────
 *   x0 = [entry+0x00] + (float)(int)[entry+0x14] * [entry+0x24]
 *   y0 = [entry+0x04] + (float)(int)[entry+0x18] * [entry+0x28]
 *   ⇒ (x,y) 是这一片背景的锚点，(x0,y0) 是加上 tile 平铺偏移后的第二角
 *   归约结果（后文剔除直接按这四值比较）：
 *     s22 = min(x,x0) = 左   s18 = max(x,x0) = 右
 *     s23 = min(y,y0) = 上   s19 = max(y,y0) = 下
 *   ★ 1b07d0 的 vmovgt.f32 s18, s14（右 = x，当 x > x0）用的是 1b07c8 那次 vmrs 抄下来的
 *     APSR（x 与 x0 的比较），而 1b07cc 的 vcmpe 刚把 fpscr 改成 y 与 y0 的比较、要到 1b07d4
 *     才 vmrs 回 APSR。读错这一拍就会把「右边界」当成 y 的条件，整段矩形的语义随之变形。
 *   注意 [entry+0x18] 的取数在 1b07a4（vldr s11,[r11,#24]），与 1b0798 的 r0=[+0x8] 交错
 */

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
/* ── 背景号存在性 + 视图矩形四边剔除 ─────────────────────────────
 *   Background_Exists(entry->[0x08]) == 0 → 不画
 *   剔除条件是「完全在 pRect 外」：左 > pRect.x2、上 > pRect.y2、右 < pRect.x1、下 < pRect.y1
 *   （pRect 四个 int32 都是 vcvt.f32.s32 后才比较，所以 tagYYRECT 是整型矩形）
 */

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
/* ── Background_Data(背景号) → CBackground*，再 DrawPart ─────────
 *   实参：r1 = (float)(int)[+0x0c]，r2 = (float)(int)[+0x10]，r3 = (float)(int)[+0x14]，
 *   栈上：[sp] = (float)(int)[+0x18]、[sp+4] = [0x00]、[sp+8] = [0x04]、
 *        [sp+0xc] = [0x24]、[sp+0x10] = [0x28]、[sp+0x14] = [0x2c]、[sp+0x18] = [0x30]
 *   即 DrawPart(源矩形四边 int→float, x, y, tileW, tileH, +0x2c, +0x30)；后四参名字未钉
 */

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
/* ── 层项迭代尾：只 i++，实例指针 r4 原地不动 ───────────────────── */

/* @0x1b08c0 ldr r1, [r6] */
/* @0x1b08c4 add r5, r5, #1 */
/* @0x1b08c8 ldr r3, [r1, #0xb8] */
/* @0x1b08cc cmp r5, r3 */
/* @0x1b08d0 blt 0x1b06fc <_Z14DoSlowDrawRoomP9tagYYRECT+0x5c> */
/* ── 层项耗尽：还有实例就回去继续（1b0710 重新测可见性）─────────── */

/* @0x1b08d4 cmp r4, #0 */
/* @0x1b08d8 bne 0x1b0710 <_Z14DoSlowDrawRoomP9tagYYRECT+0x70> */
/* ── 没实例了：粒子也空了才收尾，否则继续吐粒子 ─────────────────── */

/* @0x1b08dc vcmpe.f32 s16, s20 */
/* @0x1b08e0 vmrs APSR_nzcv, fpscr */
/* @0x1b08e4 ble 0x1b0a50 <_Z14DoSlowDrawRoomP9tagYYRECT+0x3b0> */
/* ── 粒子段闸门：粒子游标与层项深度比大小 ─────────────────────────
 *   i >= 条数 → 1b0900（没有层项可比）；s16 < entry 深度 → 1b0af4（先让层项/实例走）
 *   否则落到 1b0900 吐粒子
 */

/* @0x1b08e8 cmp r5, r3 */
/* @0x1b08ec bge 0x1b0900 <_Z14DoSlowDrawRoomP9tagYYRECT+0x260> */
/* @0x1b08f0 vldr s14, [r11, #28] */
/* @0x1b08f4 vcmpe.f32 s16, s14 */
/* @0x1b08f8 vmrs APSR_nzcv, fpscr */
/* @0x1b08fc blt 0x1b0af4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x454> */
/* ── 粒子：空哨兵判定 → 设深度 → 画 → 取下一个 depth，再回主循环 ────
 *   s16 <= -1e8 → 1b09c4（粒子耗尽，回层项/实例）
 *   否则 GR_3D_Set_Depth(min(s16,11000.0)) → ParticleSystem_DrawDepth(s16)
 *        → s16 = ParticleSystem_NextDepth(s16) → 回 1b06f4（i、r4 都不动）
 */

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
/* ── 实例绘制：先设深度，再看有没有 Draw 事件 ─────────────────────
 *   GR_3D_Set_Depth(min(inst->[0x180], 11000.0))
 *   HasEventRecursive(inst->[0x80], 8, 0)：8 = ev_draw、0 = 子事件 Draw（同一对常量
 *   在 1b098c 的 Perform_Event(inst,inst,8,0) 上重复出现）
 */

/* @0x1b0940 vcmpe.f32 s15, s17 */
/* @0x1b0944 vmrs APSR_nzcv, fpscr */
/* @0x1b0948 vmovle r0, s15 */
/* @0x1b094c vmovgt r0, s17 */
/* @0x1b0950 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* ── 有 Draw 事件：g_drawInst = inst → Perform_Event → g_drawInst = 0 ───────────
 *   旧值处理：把「全局的地址」压进 [sp+0x24]（1b0984），回来只把 [该地址] 写 0，
 *   所以这处不是「恢复旧值」，而是「用后清零」；若原本非 0 会被抹掉（open）
 */

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
/* ── 推进到下一个实例（+0x17c），重读层项条数，回主循环 ───────────── */

/* @0x1b0998 ldr r1, [r6] */
/* @0x1b099c ldr r4, [r4, #0x17c] */
/* @0x1b09a0 ldr r3, [r1, #0xb8] */
/* @0x1b09a4 b 0x1b06f4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x54> */
/* ── 跳过：留、删、不可见三者任一不满足，只推进实例指针 ───────────── */

/* @0x1b09a8 ldr r4, [r4, #0x17c] */
/* @0x1b09ac b 0x1b06f4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x54> */
/* ── 层项闸门：+0x34 == 0 就跳过这条层项（i++），非 0 才继续往下 ──── */

/* @0x1b09b0 ldrb r2, [r11, #0x34] */
/* @0x1b09b4 cmp r2, #0 */
/* @0x1b09b8 bne 0x1b073c <_Z14DoSlowDrawRoomP9tagYYRECT+0x9c> */
/* ── 跳过层项：i++ 后回主循环（实例指针不动）─────────────────────── */

/* @0x1b09bc add r5, r5, #1 */
/* @0x1b09c0 b 0x1b06f4 <_Z14DoSlowDrawRoomP9tagYYRECT+0x54> */
/* ── 粒子耗尽后回到层项/实例：inst==0 → 用层项深度进 1b076c ─────── */

/* @0x1b09c4 cmp r4, #0 */
/* @0x1b09c8 beq 0x1b0a60 <_Z14DoSlowDrawRoomP9tagYYRECT+0x3c0> */
/* @0x1b09cc vldr s15, [r4, #384] */
/* @0x1b09d0 b 0x1b0754 <_Z14DoSlowDrawRoomP9tagYYRECT+0xb4> */
/* ── 无 Draw 事件：按精灵自动绘制 ─────────────────────────────────
 *   Sprite_Data(inst->[0x8c]) == 0 → 该实例什么都不画（直接下一个）
 *   注意 1b09e4/1b09e8 先把 g_drawInst 置为 inst，再判 [+0x98] 是否 1.0
 */

/* @0x1b09d4 ldr r0, [r4, #0x8c] */
/* @0x1b09d8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1b09dc subs r1, r0, #0 */
/* @0x1b09e0 beq 0x1b0998 <_Z14DoSlowDrawRoomP9tagYYRECT+0x2f8> */
/* ── 全参路径准备：把 5 个量从实例搬到寄存器/栈 ───────────────────
 *   r2 = [0xb4]（x）、r3 = [0xb8]（y）、lr = [0xa8]、s12 = [0xa4]、
 *   s15/s14/s13 = [0x98]/[0x9c]/[0xa0]，r1 = (int)[0x90]（截断，不是 floor）
 */

/* @0x1b09e4 ldr r3, [pc, #0xac] */
/* @0x1b09e8 vldr s15, [r4, #152] */
/* @0x1b09ec vcmp.f32 s15, s21 */
/* @0x1b09f0 ldr r3, [r7, r3] */
/* @0x1b09f4 vmrs APSR_nzcv, fpscr */
/* @0x1b09f8 str r3, [sp, #0x24] */
/* @0x1b09fc str r4, [r3] */
/* @0x1b0a00 beq 0x1b0a68 <_Z14DoSlowDrawRoomP9tagYYRECT+0x3c8> */
/* ── CSprite::Draw(int i, float x, float y, float a, float b, float c, uint32 blend, float d)
 *   实参落位：r1 = (int)image_index、r2 = x、r3 = y、[sp] = [0x98]、[sp+4] = [0x9c]、
 *   [sp+8] = [0xa0]、[sp+0xc] = [0xa8]、[sp+0x10] = [0xa4]
 *   ⇒ 0x98/0x9c 是双轴缩放，0xa0 是角度，0xa8 是 blend，0xa4 是 alpha（按形参顺序定）
 */

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
/* ── 清 g_drawInst（写 0），随后与事件路径汇合到 1b0998 推进实例 ────── */

/* @0x1b0a44 ldr r12, [sp, #0x24] */
/* @0x1b0a48 str r8, [r12] */
/* @0x1b0a4c b 0x1b0998 <_Z14DoSlowDrawRoomP9tagYYRECT+0x2f8> */
/* ── 收尾：撤帧后尾调 Graphics::Flush()（b 而不是 bl，本函数无返回值）── */

/* @0x1b0a50 add sp, sp, #44 */
/* @0x1b0a54 vpop {d8, d9, d10, d11} */
/* @0x1b0a58 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b0a5c b 0x1852ec <_ZN8Graphics5FlushEv> */
/* ── 尾段：inst==0 时用层项深度进 1b076c（与 1b09c4 同一入口）─────── */

/* @0x1b0a60 vldr s14, [r11, #28] */
/* @0x1b0a64 b 0x1b076c <_Z14DoSlowDrawRoomP9tagYYRECT+0xcc> */
/* ── DrawSimple 快路径判定（省掉缩放/旋转/blend 的整条链）──────────
 *   条件全满足才走：+0x98 == 1.0、+0x9c == 1.0、+0xa0 == 0、+0xa8 == 0x00FFFFFF、+0xa4 == 1.0
 *   任一不满足 → 回 1b0a14 走全参 Draw；全满足 → DrawSimple((int)floorf([0x90]), x, y)
 */

/* @0x1b0a68 vldr s14, [r4, #156] */
/* @0x1b0a6c vcmp.f32 s14, s21 */
/* @0x1b0a70 vldr s13, [r4, #160] */
/* @0x1b0a74 vmrs APSR_nzcv, fpscr */
/* @0x1b0a78 beq 0x1b0a9c <_Z14DoSlowDrawRoomP9tagYYRECT+0x3fc> */
/* @0x1b0a7c ldr lr, [r4, #0xa8] */
/* @0x1b0a80 vldr s12, [r4, #164] */
/* @0x1b0a84 b 0x1b0a14 <_Z14DoSlowDrawRoomP9tagYYRECT+0x374> */
/* ── literal pool（1b0a88..1b0a98，5 字；objdump 把前三个译成了指令，非指令）──
 *   1b0a88 = 0x462be000 = 11000.0f（深度上限）      1b0a8c = 0xccbebc20 = -1e8f（粒子空哨兵）
 *   1b0a90 = 0x00241588（GOT 基址差的加数）          1b0a94 = 0xffffbcd8 → GOT 槽 → &Run_Room
 *   1b0a98 = 0xffffbce4 → GOT 槽 → 0x479CAC (g_drawInst)
 */

/* @0x1b0a88 strtmi lr, [r11], -r0 */
/* @0x1b0a8c ldcgt p12, c11, [lr], #128 */
/* @0x1b0a90 eoreq r1, r4, r8, lsl #11 */
/* @0x1b0a94 .word 0xffffbcd8 */
/* @0x1b0a98 .word 0xffffbce4 */
/* ── DrawSimple 判定的后半 + 调用 ────────────────────────────────
 *   +0xa0（角度）非 0 → 全参路径；+0xa8 != 0x00FFFFFF → 全参路径；+0xa4 != 1.0 → 全参路径
 *   全过：floorf((double? 否) [0x90]) → (int) → DrawSimple(精灵, 帧号, x, y)
 *   与全参路径唯一的差别：帧号用 floorf，而全参路径用 (int) 截断
 */

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
/* ── DrawSimple 之后并回清 g_drawInst 的公共出口 ─────────────────── */

/* @0x1b0af0 b 0x1b0a44 <_Z14DoSlowDrawRoomP9tagYYRECT+0x3a4> */
/* ── 层项深度不落后（粒子比它深）：inst==0 → 直接画层项；否则取实例深度回 1b0760 比较 ── */

/* @0x1b0af4 cmp r4, #0 */
/* @0x1b0af8 beq 0x1b076c <_Z14DoSlowDrawRoomP9tagYYRECT+0xcc> */
/* ── 末条：取实例深度后回 1b0760 ──────────────────────────────── */

/* @0x1b0afc vldr s15, [r4, #384] */
/* @0x1b0b00 b 0x1b0760 <_Z14DoSlowDrawRoomP9tagYYRECT+0xc0> */
