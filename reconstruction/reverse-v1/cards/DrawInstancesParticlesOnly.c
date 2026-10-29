/* cally 逆向卡：DrawInstancesParticlesOnly（原版 libyoyo.so，armv7）
 * @func 0x1b0b04 0x1b0f50  size 1100  275 条（1b0ee8..1b0efc 为 literal pool，6 字，被 objdump 译成指令）
 * 级别: 骨架（275/275 锚定；粒子游标的两条空判据、归并判据、四处 3D 字节门、三个浮点常量、
 *             两段实例块与 DrawSimple 判据逐条钉住。未钉：ParticleSystem_NextDepth 的游标方向
 *             （按名字读作「下一个更小的 depth」）、DrawDepth 是「画该 depth 全部粒子」还是
 *             「画到该 depth 为止」、-1e8 与 DrawTheRoom 的 -1e9 阈值不一致的原因）
 * 符号: _Z26DrawInstancesParticlesOnlyP9tagYYRECT → void DrawInstancesParticlesOnly(tagYYRECT* pRect)
 * 同层: DrawTheRoom 0x1b3b10（唯一调用者：瓦片数==0、实例数!=0、LargestDepth() > -1e9 时）、
 *       DrawInstancesOnly 0x1b0f50（兄弟：本函数去掉粒子游标后的形态）、DoSlowDrawRoom 0x1b06a0、
 *       ParticleSystem_LargestDepth 0x1a570c / DrawDepth 0x1a583c / NextDepth 0x1a579c、
 *       CSprite::Draw 0x1ec720 / DrawSimple 0x1ecab4 / Sprite_Data 0x1ef03c、
 *       CObjectGM::HasEventRecursive 0x19dcdc、Perform_Event 0xf3380、GR_3D_Set_Depth 0x1631dc
 *       GOT 基址 0x3F1C58（1b0b20 的 0x00241130 + pc 0x1b0b28）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   先取粒子系统的最大 depth 当游标，把「实例链（depth 降序）」与「粒子 depth 层（从深到浅）」
 *   两条流归并输出：谁的 depth 更大谁先画。粒子用完后自动降级成 DrawInstancesOnly 的实例尾段
 *   （唯一差别是帧号走 floorf）。形参 pRect 一次也没读。
 *
 * ── 粒子游标：取数、判空、推进（本题重点；锚点见 1b0b14 / 1b0b34 / 1b0b74 / 1b0bb8）──
 *   s16 = ParticleSystem_LargestDepth()               1b0b14；这是**深度值**，不是下标、不是计数。
 *   判空①：1b0b34 vcmpe s16,-1e8 + ble → 1b0bf0      游标 <= -1e8 即「没有粒子」，直接进实例尾段。
 *   归并 ：1b0b74 s15 = inst->[0x180]；vcmpe s15,s16；bpl 1b0d24
 *          ⇒ 实例 depth >= 游标 → 先画实例；否则（实例更近）先吐这一层粒子。
 *   吐一层：1b0b98..1b0bbc
 *          GR_3D_Set_Depth(min(游标, 11000.0f))   （被 3D 字节门控）
 *          ParticleSystem_DrawDepth(游标)
 *          游标 = ParticleSystem_NextDepth(游标)
 *   判空②：1b0bc0 vcmpe s16,-1e8 + ble → 1b0bf0      吐完变空 → 进实例尾段。
 *   判空③：1b0be4（推进实例指针后）同一条比较，bgt 回 1b0bcc，否则落尾段。
 *   ⚠ 游标比较全用 vcmpe + 条件码，**没有一次整数比较**；-1e8 = literal 1b0ee8 = 0xccbebc20。
 *   ⚠ 尾段里 s16 被复用成常量 11000.0f（1b0c04），s17 被复用成 1.0f（1b0bf8）。把「s16 = 游标」
 *     带进尾段会读成「拿 11000 去吐粒子」—— 尾段根本没有粒子代码。
 *
 * ── 四条出口 ───────────────────────────────────────────────────
 *   ① 1b0b3c 游标空                    → 1b0bf0 实例尾段
 *   ② 1b0b44 游标非空但链头空          → 1b0e78 全吐循环（只吐粒子，不画实例）
 *   ③ 1b0bc8 / 1b0be4 游标耗尽          → 1b0bf0 实例尾段
 *   ④ 1b0ec8 尾段走完                  → 返回（add sp / vpop {d8,d9} / pop {r4-r9,pc}）
 *   全函数无 Graphics::Flush、无瓦片/背景访问。
 *
 * ── 常量表（六处 literal）──────────────────────────────────────
 *   1b0ee8 = 0xccbebc20 = -1e8f      粒子空哨兵（DoSlowDrawRoom 同值；DrawTheRoom 的选路用 -1e9）
 *   1b0eec = 0x462be000 = 11000.0f   深度上限（DoSlowDrawRoom / DrawInstancesOnly 同值）
 *   1b0ef0 = 0x00241130              GOT 基址加数
 *   1b0ef4 = 0xffffbcd8 → 0x3ed930   &Run_Room
 *   1b0ef8 = 0xffffc0b4 → 0x3edd0c   3D 模式字节 0x4859b0
 *   1b0efc = 0xffffbce4 → 0x3ed93c   g_drawInst
 *   s19 = 1.0f、r8 = 0x00FFFFFF 是立即数（vmov/mvn），不占 literal。
 *
 * ── 与两个兄弟的字段一致性（逐条对齐）───────────────────────────
 *   实例链头 room+0x84（1b0b2c）｜next +0x17c｜depth +0x180（=#384）｜可见性 +0x68 → +0x69 → +0x65
 *   ｜CObjectGM +0x80｜精灵号 +0x8c｜image_index +0x90｜五个绘制量 +0x98/+0x9c/+0xa0/+0xa4/+0xa8
 *   ｜x/y +0xb4/+0xb8｜g_drawInst 0x479cac｜事件 8｜11000 上限 —— 与 DrawInstancesOnly、DoSlowDrawRoom 完全同址。
 *   差异只在：① 有粒子归并；② Set_Depth 被 3D 字节门控（DoSlow 无条件）；③ 本函数用 floorf 取帧号
 *   （DrawInstancesOnly 用截断，1b10f8）。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */
/* ── 帧 + 粒子空哨兵 ────────────────────────────────────────────────────
 *   push {r4-r9,lr} + vpush {d8,d9} + sub sp,#28（0x1c）。r0(pRect) 之后从未被读。
 *   s17 = literal 1b0ee8 = 0xccbebc20 = -1e8f（粒子空哨兵）。用 d8/d9 两个双字：要同时保 s16/s17/s18/s19。
 */

/* @0x1b0b04 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b0b08 vpush {d8, d9} */
/* @0x1b0b0c sub sp, sp, #28 */
/* @0x1b0b10 vldr s17, [pc, #976] */

/* ── 取粒子游标 + 取链头 ────────────────────────────────────────────────
 *   LargestDepth() 的返回值直接进 s16（1b0b30）—— 这就是全函数的粒子游标。
 *   r6 = GOT 基址 0x3F1C58（1b0b20 的 0x00241130 + pc 0x1b0b28）；r3 = [槽 0x3ed930] = &Run_Room；
 *   r3 = [r3] = CRoom*；r4 = room->[0x84] = 实例绘制链头。⚠ 链头在判空之前就已读出。
 */

/* @0x1b0b14 bl 0x1a570c <_Z27ParticleSystem_LargestDepthv> */
/* @0x1b0b18 ldr r6, [pc, #0x3d0] */
/* @0x1b0b1c ldr r3, [pc, #0x3d0] */
/* @0x1b0b20 add r6, pc, r6 */
/* @0x1b0b24 ldr r3, [r6, r3] */
/* @0x1b0b28 ldr r3, [r3] */
/* @0x1b0b2c ldr r4, [r3, #0x84] */

/* ── 粒子判空①：游标 <= -1e8 直接进实例尾段 ──────────────────────
 *   vcmpe s16,s17(-1e8) + ble → 1b0bf0。LE =（Z==1 或 N!=V），NaN 时 N!=V 成立 ⇒ NaN 同样落尾段；
 *   本函数只有这一道判，没有 DrawTheRoom 1b3e68 那样的 bhi 二次测。
 */

/* @0x1b0b30 vmov s16, r0 */
/* @0x1b0b34 vcmpe.f32 s16, s17 */
/* @0x1b0b38 vmrs APSR_nzcv, fpscr */
/* @0x1b0b3c ble 0x1b0bf0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xec> */

/* ── 有粒子但链头为空 → 全吐循环 ────────────────────────────────────────
 *   cmp r4,#0 + beq 1b0e78：没有实例可画，但粒子仍要按 depth 逐层吐完。
 */

/* @0x1b0b40 cmp r4, #0 */
/* @0x1b0b44 beq 0x1b0e78 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x374> */

/* ── 归并段常量 + 进循环 ────────────────────────────────────────────────
 *   r7 = 0（清 g_drawInst 用）、s19 = 1.0f、r8 = 0x00FFFFFF、s18 = literal 1b0eec = 11000.0f；
 *   b 1b0bd4 进归并循环头。⚠ 归并段的 11000 在 s18，尾段的 11000 在 s16 —— 同一个常量两个寄存器。
 */

/* @0x1b0b48 mov r7, #0 */
/* @0x1b0b4c vmov.f32 s19, #1.000000e+00 */
/* @0x1b0b50 mvn r8, #-16777216 */
/* @0x1b0b54 vldr s18, [pc, #912] */
/* @0x1b0b58 b 0x1b0bd4 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xd0> */

/* ── 归并循环的可见性后两测（0x68 在 1b0bd4） ──────────────────
 *   0x69 != 0 → 1b0be0（推进实例）；0x65 == 0 → 1b0be0。顺序 0x68 → 0x69 → 0x65，与另两个函数一致。
 */

/* @0x1b0b5c ldrb r3, [r4, #0x69] */
/* @0x1b0b60 cmp r3, #0 */
/* @0x1b0b64 bne 0x1b0be0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xdc> */
/* @0x1b0b68 ldrb r3, [r4, #0x65] */
/* @0x1b0b6c cmp r3, #0 */
/* @0x1b0b70 beq 0x1b0be0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xdc> */

/* ── 归并判据：实例 depth vs 粒子游标 ────────────────────────────
 *   s15 = inst->[0x180]（#384）；vcmpe s15,s16；bpl 1b0d24。
 *   bpl = N==0 ⇒ 实例 depth >= 游标 → 先画实例；否则落 1b0b84 先吐粒子（NaN 时 N=0，也走画实例）。
 *   ⇒ 两条流都是 depth 降序（CRoom_DeSerialise 卡：插入用 +0x184 快照、链头最深），所以「取较大者」
 *     就是正确的降序归并。DoSlowDrawRoom 卡正文把这条流写成「递增序列」，方向与此相反（见 claims）。
 */

/* @0x1b0b74 vldr s15, [r4, #384] */
/* @0x1b0b78 vcmpe.f32 s15, s16 */
/* @0x1b0b7c vmrs APSR_nzcv, fpscr */
/* @0x1b0b80 bpl 0x1b0d24 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x220> */

/* ── 吐一层粒子：3D 门 + 钳位 + DrawDepth + NextDepth ────
 *   3D 字节 0x4859b0 为 0 → 跳过 Set_Depth，但 DrawDepth/NextDepth 照调（门只作用于深度写入）。
 *   非 0 → Set_Depth(min(游标, 11000.0f))：vcmpe s16,s18 + vmovle/vmovgt 三连（s18 = 11000）。
 *   ParticleSystem_DrawDepth(游标)；ParticleSystem_NextDepth(游标) → 新游标进 s16。
 */

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

/* ── 粒子判空② + 分支回环 ──────────────────────────────────────────────
 *   新游标 <= -1e8 → 1b0bf0（实例尾段）；否则看链头：r4==0 → 1b0e78（全吐），否则回 1b0bd4。
 *   回 1b0bd4 意味着**重新做一遍可见性三连测**（同一个 r4），可见性没有被缓存。
 */

/* @0x1b0bc0 vcmpe.f32 s16, s17 */
/* @0x1b0bc4 vmrs APSR_nzcv, fpscr */
/* @0x1b0bc8 ble 0x1b0bf0 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xec> */
/* @0x1b0bcc cmp r4, #0 */
/* @0x1b0bd0 beq 0x1b0e78 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x374> */
/* @0x1b0bd4 ldrb r3, [r4, #0x68] */
/* @0x1b0bd8 cmp r3, #0 */
/* @0x1b0bdc beq 0x1b0b5c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x58> */

/* ── 推进实例后的游标复测（判空③） ────────────────────────────────────────
 *   1b0be0 先 r4 = inst->[0x17c]（next），再用同一条 vcmpe s16,-1e8 复测：bgt 回 1b0bcc，否则落 1b0bf0。
 *   ⇒ 跳过不可见实例不会阻止粒子继续吐；反过来，粒子吐完就立刻收束到实例尾段。
 */

/* @0x1b0be0 ldr r4, [r4, #0x17c] */
/* @0x1b0be4 vcmpe.f32 s16, s17 */
/* @0x1b0be8 vmrs APSR_nzcv, fpscr */
/* @0x1b0bec bgt 0x1b0bcc <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xc8> */

/* ── 实例尾段入口（游标空 / 耗尽都到这里） ──────────────────────────────
 *   r4==0 → 1b0ec8 直接返回；否则重新装常量：s17 = 1.0f、r7 = 0、r8 = 0xFFFFFF、s16 = 11000.0f。
 *   ★ 从这一行起 s16 不再是游标：它是深度上限 11000。尾段与粒子无关。
 */

/* @0x1b0bf0 cmp r4, #0 */
/* @0x1b0bf4 beq 0x1b0ec8 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3c4> */
/* @0x1b0bf8 vmov.f32 s17, #1.000000e+00 */
/* @0x1b0bfc mov r7, #0 */
/* @0x1b0c00 mvn r8, #-16777216 */
/* @0x1b0c04 vldr s16, [pc, #736] */
/* @0x1b0c08 b 0x1b0c3c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x138> */

/* ── 尾段事件路径（与归并段的事件块是两份拷贝） ────────────────────────────
 *   r5 = [r6,槽号] = &g_drawInst；写 [r5] = inst → Perform_Event(inst,inst,8,0) → 写 [r5] = 0；
 *   然后推进 r4 = [r4,#0x17c]，r4==0 → 1b0ec8 返回，否则回 1b0c3c。
 */

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

/* ── 尾段可见性三连测 ──────────────────────────────────────────────────────
 *   0x68 != 0 / 0x69 != 0 / 0x65 == 0 → 1b0c30（推进）。
 */

/* @0x1b0c3c ldrb r3, [r4, #0x68] */
/* @0x1b0c40 cmp r3, #0 */
/* @0x1b0c44 bne 0x1b0c30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x12c> */
/* @0x1b0c48 ldrb r3, [r4, #0x69] */
/* @0x1b0c4c cmp r3, #0 */
/* @0x1b0c50 bne 0x1b0c30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x12c> */
/* @0x1b0c54 ldrb r3, [r4, #0x65] */
/* @0x1b0c58 cmp r3, #0 */
/* @0x1b0c5c beq 0x1b0c30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x12c> */

/* ── 尾段 3D 门 + 钳位（用 s16=11000 作上限） ────────────
 *   门控与归并段同形；钳位比较的是 inst->[0x180] 与 s16(=11000.0f)，容易误读成「与游标比」。
 */

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

/* ── 尾段 Draw 事件判定 + Sprite_Data ──────────────────
 *   HasEventRecursive(inst->[0x80],8,0) 非 0 → 1b0c0c；Sprite_Data(inst->[0x8c]) 返回 0 → 1b0c30。
 *   精灵号留在 r9（1b0cac 的 subs r9,r0,#0），后面 Draw/DrawSimple 的 r0 都从 r9 取。
 */

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

/* ── 尾段：置 g_drawInst + 第一道判据 ────────────────────────
 *   r5 = &g_drawInst；s15 = [0x98]；与 s17(1.0) 比较；写 [r5] = inst；不等 → 1b0ed4 全参。
 */

/* @0x1b0cb4 ldr r3, [pc, #0x240] */
/* @0x1b0cb8 vldr s15, [r4, #152] */
/* @0x1b0cbc vcmp.f32 s15, s17 */
/* @0x1b0cc0 ldr r5, [r6, r3] */
/* @0x1b0cc4 vmrs APSR_nzcv, fpscr */
/* @0x1b0cc8 str r4, [r5] */
/* @0x1b0ccc bne 0x1b0ed4 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3d0> */

/* ── 尾段：[0x9c] 判据 ──────────────────────────────────────────────
 *   不等 → 1b0f00（继续测 0xa0/0xa8/0xa4，那条链在字面池之后）；相等 → 落 1b0ce4 直接备全参。
 *   ⚠ 尾段的 DrawSimple 判据链被 literal pool 切成两段（1b0cd0 与 1b0f00），不是两条路径。
 */

/* @0x1b0cd0 vldr s14, [r4, #156] */
/* @0x1b0cd4 vcmp.f32 s14, s17 */
/* @0x1b0cd8 vldr s13, [r4, #160] */
/* @0x1b0cdc vmrs APSR_nzcv, fpscr */
/* @0x1b0ce0 beq 0x1b0f00 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x3fc> */

/* ── 尾段全参 Draw + 清 g_drawInst + 推进 ────────────
 *   r2 = x、r3 = y；栈上 [sp]=[0x98]、[sp+4]=[0x9c]、[sp+8]=[0xa0]、[sp+0xc]=[0xa8]、[sp+0x10]=[0xa4]；
 *   帧号 = vcvt.s32.f32 [0x90]（截断）。Draw 后清 [r5]=0，b 1b0c30 推进。
 */

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

/* ── 归并段的实例绘制入口：3D 门 + Set_Depth + 事件判定 ────
 *   s15 = [0x180]；门控后 Set_Depth(min(深度, s18=11000))；HasEventRecursive 非 0 → 1b0d64。
 */

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

/* ── 归并段事件路径 ────────────────────────────────────────────────────────
 *   r5 = &g_drawInst；置 inst → Perform_Event → 清 0；推进 r4 = [r4,#0x17c]；b 1b0be4（游标复测）。
 */

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

/* ── 归并段精灵路径：Sprite_Data 与第一道判据 ──────────────────
 *   Sprite_Data(inst->[0x8c]) → r9；为 0 → 1b0be0（推进）；否则置 g_drawInst、比 [0x98] 与 s19(1.0)，
 *   不等 → 1b0e20 全参。
 */

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

/* ── 归并段判据续（[0x9c] / [0xa0]） ────────────────────────
 *   [0x9c] != 1.0 → 1b0e6c（补 s12 后全参）；[0xa0] != 0 → 1b0e2c（补 s12 后全参）。
 */

/* @0x1b0dbc vldr s14, [r4, #156] */
/* @0x1b0dc0 vcmp.f32 s14, s19 */
/* @0x1b0dc4 vldr s13, [r4, #160] */
/* @0x1b0dc8 vmrs APSR_nzcv, fpscr */
/* @0x1b0dcc bne 0x1b0e6c <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x368> */

/* ── 归并段 DrawSimple 路径（floorf） ────────────────────
 *   过了 [0xa8] == 0x00FFFFFF、[0xa4] == 1.0 两道才到 1b0df8：**floorf([0x90])** 再 vcvt.s32.f32 →
 *   DrawSimple(sprite, i, x, y)，然后 b 1b0e60 清 g_drawInst、推进、复测游标。
 *   ★ 与 DrawInstancesOnly 的同段（1b10f8）唯一的差别就在这一句：这里 bl floorf@plt(0xb6910)，那里没有。
 *     [0xa0] != 0 → 1b0e2c、[0xa8] != 0xFFFFFF → 1b0e30、[0xa4] != 1.0 → 1b0e30，三条都回全参。
 */

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

/* ── 归并段全参 Draw（三个入口汇合） ──────────────────────────────────
 *   1b0e20（[0x98] != 1.0）：补 r12、s14 = [0x9c]、s13 = [0xa0]，落到 1b0e2c 再重读一次 r12；
 *   1b0e2c（[0xa0] != 0，从 1b0ddc 来）：只重读 r12；
 *   1b0e6c（[0x9c] != 1.0）：补 r12 与 s12 = [0xa4]，跳 1b0e30。
 *   三条都汇到 1b0e30..1b0e5c 的传参段（s11 = (int)[0x90]、r2/r3 = x/y、5 个字栈参），与尾段逐条同形。
 */

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

/* ── 归并段收尾：清 g_drawInst → 推进 → 游标复测 ──────────
 *   str r7,[r5]（r7=0）；r4 = [r4,#0x17c]；b 1b0be4。⚠ 这里回到的是游标比较，不是可见性检查。
 */

/* @0x1b0e60 str r7, [r5] */
/* @0x1b0e64 ldr r4, [r4, #0x17c] */
/* @0x1b0e68 b 0x1b0be4 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0xe0> */

/* ── 归并段判据残段（从 1b0dcc 跳来） ──────────────────────────────
 *   只补 r12 = [0xa8] 与 s12 = [0xa4]，b 1b0e30。
 */

/* @0x1b0e6c ldr r12, [r4, #0xa8] */
/* @0x1b0e70 vldr s12, [r4, #164] */
/* @0x1b0e74 b 0x1b0e30 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x32c> */

/* ── 全吐循环（有粒子、无实例）：重装两个常量 + 3D 门 ────────────────
 *   s18 = 11000.0f（1b0eec）、s17 = -1e8（1b0ee8）在这里被重新装载 —— 因为尾段把 s17 改成了 1.0。
 *   3D 字节为 0 → 跳过 Set_Depth；否则 Set_Depth(min(游标,11000))。
 */

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

/* ── 全吐循环体：DrawDepth / NextDepth / 循环条件 ────
 *   DrawDepth(游标) → 游标 = NextDepth(游标) → bgt（游标 > -1e8）回 1b0e88 继续；否则落 1b0ec8 返回。
 *   ⇒ 这条循环没有实例、没有可见性、没有 g_drawInst —— 纯粒子冲刷。
 */

/* @0x1b0ea8 vmov r0, s16 */
/* @0x1b0eac bl 0x1a583c <_Z24ParticleSystem_DrawDepthf> */
/* @0x1b0eb0 vmov r0, s16 */
/* @0x1b0eb4 bl 0x1a579c <_Z24ParticleSystem_NextDepthf> */
/* @0x1b0eb8 vmov s16, r0 */
/* @0x1b0ebc vcmpe.f32 s16, s17 */
/* @0x1b0ec0 vmrs APSR_nzcv, fpscr */
/* @0x1b0ec4 bgt 0x1b0e88 <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x384> */

/* ── 返回 ──────────────────────────────────────────────────────────────────
 *   add sp,#28 + vpop {d8,d9} + pop {r4-r9,pc}：无返回值、无 Flush。
 */

/* @0x1b0ec8 add sp, sp, #28 */
/* @0x1b0ecc vpop {d8, d9} */
/* @0x1b0ed0 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── 尾段全参入口（[0x98] != 1.0 时从 1b0ccc 跳来） ────
 *   r12 = [0xa8]、s14 = [0x9c]、s13 = [0xa0]、s12 = [0xa4]，b 1b0cec 汇入尾段传参段。
 */

/* @0x1b0ed4 ldr r12, [r4, #0xa8] */
/* @0x1b0ed8 vldr s14, [r4, #156] */
/* @0x1b0edc vldr s13, [r4, #160] */
/* @0x1b0ee0 vldr s12, [r4, #164] */
/* @0x1b0ee4 b 0x1b0cec <_Z26DrawInstancesParticlesOnlyP9tagYYRECT+0x1e8> */

/* ── literal pool（1b0ee8..1b0efc，6 字；前两字被 objdump 译成指令，非指令） ────
 *   1b0ee8 = 0xccbebc20 = -1e8f（粒子空哨兵）    1b0eec = 0x462be000 = 11000.0f（深度上限）
 *   1b0ef0 = 0x00241130（GOT 基址加数）           1b0ef4 = 0xffffbcd8 → 0x3ed930 (&Run_Room)
 *   1b0ef8 = 0xffffc0b4 → 0x3edd0c (0x4859b0)     1b0efc = 0xffffbce4 → 0x3ed93c (g_drawInst)
 *   句柄：1b0b10 的 vldr s17、1b0b54 的 vldr s18、1b0c04 的 vldr s16 都指到这一对常量。
 */

/* @0x1b0ee8 ldcgt p12, c11, [lr], #128 */
/* @0x1b0eec strtmi lr, [r11], -r0 */
/* @0x1b0ef0 eoreq r1, r4, r0, lsr r1 */
/* @0x1b0ef4 .word 0xffffbcd8 */
/* @0x1b0ef8 .word 0xffffc0b4 */
/* @0x1b0efc .word 0xffffbce4 */

/* ── 尾段 DrawSimple 判据后三项 + floorf + DrawSimple ────
 *   从 1b0ce0 的 beq 进来（[0x9c] == 1.0）：[0xa0] == 0 → 否则 1b0ee0 全参；[0xa8] == 0xFFFFFF → 否则 1b0cec；
 *   [0xa4] == 1.0 → 否则 1b0cec；全过才 floorf([0x90]) → vcvt → DrawSimple(sprite, i, x, y) → b 1b0d1c 清 g_drawInst。
 */

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

