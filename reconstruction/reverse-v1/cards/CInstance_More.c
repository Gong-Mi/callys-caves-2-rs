/* cally 逆向卡：CInstance 的 Debug 打印 / 椭圆碰撞 / 路径适配 / 12 个剩余小访问器
 *    （原版 libyoyo.so，armv7；一卡十六节，前四节是正文大函数，后十二节是访问器）
 *
 * @func 十六节，逐节自带 @func 头与逐条锚点（每节的 index 文件都是 asm_index.py 从二进制现生成）：
 *   §1 0x195558 CInstance::Collision_Instance(CInstance*,bool)       size  884  221 条
 *   §2 0x194a90 CInstance::Collision_Ellipse(float×4,bool)           size 1176  294 条
 *   §3 0x19411c CInstance::Adapt_Path()                              size  916  229 条
 *   §4 0x19363c CInstance::Dump(tagIConsole&)                        size 2112  528 条
 *   §5 0x19230c CInstance::SetDeactivated(bool)                      size   52   13 条
 *   §6 0x192ba8 CInstance::Set_MaskIndex(int)                        size   28    7 条
 *   §7 0x192fec CInstance::SetImageScaleX(float)                     size   40   10 条
 *   §8 0x193014 CInstance::SetImageScaleY(float)                     size   40   10 条
 *   §9 0x19303c CInstance::SetImageAngle(float)                      size   40   10 条
 *   §10 0x1930d4 CInstance::SetSpeed(float)                          size   32    8 条
 *   §11 0x1930f4 CInstance::SetHspeed(float)                         size   32    8 条
 *   §12 0x193114 CInstance::SetVspeed(float)                         size   32    8 条
 *   §13 0x193148 CInstance::SetTimer(int,int)                        size   16    4 条
 *   §14 0x1935c4 CInstance::SetPathPosition(float)                   size   56   14 条（13+1 池字）
 *   §15 0x1935fc CInstance::SetPathPositionPrevious(float)           size   56   14 条（13+1 池字）
 *   §16 0x193634 CInstance::SetPathSpeed(float)                      size    8    2 条
 * 总账: 1380 锚点 = 528 + 294 + 229 + 221 + 108，与五个 index 文件逐字一致
 *       （scripts/check_card_anchors.py：missing=0 extra=0 mismatch=0 ⇒ RESULT EXACT）。
 *       其中 63 个是 literal pool 字（objdump 会把它们解成「像指令」的样子），
 *       锚点里保留原写法，注释逐字标「非指令」。
 * 级别: 正文（1380/1380 逐条落锚）。tier = bytecode_anchored。
 *       未钉的东西全在每节末尾的 open 里单列，不在正文里含糊。
 * 锚点来源: 全部由 scripts/asm_index.py 从 ~/cally-oracle/libyoyo.so 生成，本卡未手写转录任何一条；
 *       index 文件：asm/index-CInstance_Collision_Instance.tsv、index-CInstance_Collision_Ellipse.tsv、
 *       index-CInstance_Adapt_Path.tsv、index-CInstance_Dump.tsv、
 *       index-CInst_Set*.tsv（12 个访问器，合并视图 asm/index-CInstance_More.tsv）。
 * 读法: 注释里的地址都是**指令地址**；被调函数的入口在注释里另行写出。
 *
 * ── 这张卡回答的三个问题（任务书指定）────────────────────────────────────────
 *   1. Collision_Ellipse 的椭圆判据是什么？—— 椭圆用它的外接矩形表示
 *      {lrint(min x), lrint(min y), lrint(max x), lrint(max y)}，真正的椭圆判定只有一支静态函数
 *      InEll(rect,x,y)（0x1949e8，42 条）：c=(l+r)/2、hw=(r-l)/2，判 ((x-cx)/hw)²+((y-cy)/hh)² ≤ 1
 *      （双精度）。用法是「中心在 bbox 内就放行，否则要求 bbox 四角至少一角在椭圆内」，
 *      再交给 CSprite::PreciseCollisionEllipse / CSkeletonInstance::EllipseCollision 做掩码级判定。
 *   2. Adapt_Path 对 path 字段写了什么？—— 写 +0x12c path_position（含 endaction 分支改写）、
 *      写 +0x134 path_speed（只有 reverse 分支）、写 +0x144/+0x148 pathxstart/pathystart（只有
 *      continue 分支，累加「末点-起点」的旋转位移）、写 +0x128 path_index（只有 stop/default 置 -1），
 *      以及 x/y（经 SetPosition）与 hspeed/vspeed（经 SetHspeed/SetVspeed）、speed（经 SetSpeed(0)）。
 *   3. Dump 打印哪些字段？—— 61 行固定顺序 + 变量表。字段名不是猜的：52 个池字解出的 61 条
 *      格式串就是原件的字段名（i_id / i_precise / i_bbox.left / i_pathxstart / i_timelinerunning …）。
 *      完整清单与「不打印的 20 个偏移」见 §4。
 *
 * ── 跨节结论（每条都能落到锚点）──────────────────────────────────────────────
 *   A. 「置脏」的写方全集在本卡的 6 个访问器里就有一半：§6/§7/§8/§9 一律 `+0x64 = 1` 后
 *      尾跳 CollisionMarkDirty 0x1cc1d0；而 §10/§11/§12（速度）与 §14/§15/§16（路径）一个字节
 *      都不碰 +0x64。加上已出卡的 SetPosition（0x193eb8）、SetObjectIndex（0x193344），
 *      「哪些 setter 会重算包围盒」这件事是逐函数决定的，没有统一模板。
 *   B. 三档判据的两条不同闸门：§1 用「精灵侧」的 spr+0x30（两侧都无掩码 ⇒ 直接返回 1），
 *      §2 用「实例侧」的 +0xb0（i_precise == 0 ⇒ 直接返回 1）。而 +0xb0 正是
 *      Compute_BoundingBox 从 spr+0x30 拷来的缓存值 —— 两者是同一信息的两种缓存位置。
 *   C. 取整策略：§1 读全局 option_use_fast_collision（0x542379）在 lrint 与 vcvt.s32 之间二选一
 *      （两条 15 实参的 PreciseCollision 调用只差这一点）；§2 不做选择，一律 lrint。
 *      ⇒ 「快碰撞」开关只穿透单实例碰撞，不穿透椭圆碰撞。
 *   D. bbox 就是 +0xe8 的 tagYYRECT {left,top,right,bottom}，三个独立来源互证：
 *      §4 的格式串（i_bbox.left@+0xe8 / .right@+0xf0 / .top@+0xec / .bottom@+0xf4）、
 *      §1 的裸 `<` 分离四闸、§2 的 +1 四闸。ctor 卡里 0xe8/0xec/0xf0/0xf4「未定」到此结案。
 *   E. +0x144/+0x148 结案：Dump 名为 i_pathxstart/i_pathystart 且按 %f 打印，§3 用 vldr/vmla/vstr
 *      做浮点累加，Assign_Path 0x1940e0..0x1940ec 直接把 x/y 的位模式拷进去。ctor 卡「疑似
 *      CPath* / CTimeline*」的猜测被三条独立证据否证。
 *   F. 四个大函数都不在「热门调用链」上：Dump 零调用者；Adapt_Path 的 7 个调用点全在
 *      碰撞/物理收尾（processCollision / HandleCollision / HandleInstanceMovement /
 *      CPhysicsWorld::UpdatePaths）；Collision_Ellipse 只有 Command_CollisionEllipse 一个调用者；
 *      Collision_Instance 的 12 个调用点全在 0x1c86e0..0x1cc800 这一段碰撞命令群里。
 *
 * ── 汇总 open（各节还有细项）────────────────────────────────────────────────
 *   1. Dump 在本 .so 内**零调用点**（.text 0..0x3a5a1c 无 bl/blx 指向 0x19363c）。它是导出符号，
 *      但链接期没有任何调用者；谁在运行期调它（IDE/调试器/脚本 dump 命令）本卡给不出证据。
 *   2. option_use_fast_collision（0x542379）的写方未证。本卡只证它是一个按字节读的开关，
 *      非 0 ⇒ §1 的 x/y 用 vcvt.s32 截断，0 ⇒ 用 lrint 四舍五入。
 *   3. CSkeletonInstance::ComputeBoundingBox 的返回值语义（§2 用它决定 +0x64=0/+0xb0=1 还是
 *      退回脏标志路）不在本卡；需要在 CSkeletonInstance 侧开卡。
 *   4. §4 变量表容器的确切类型（+0x60，{count@+0, base@+0x10}、12 B 项、+8 的 int 语义）只有
 *      结构与两条跳过规则是实证的；项 +8 究竟是「类型」还是「作用域下标」未定。
 *   5. §3 末尾 SetSpeed(0) 的后果取决于 Compute_Speed2 是否按 speed/direction 重算
 *      hspeed/vspeed；若是，则 Adapt_Path 每步先把位移写进 hspeed/vspeed、随后又被清零。
 *      本卡只证调用顺序，不断言最终值。
 *   6. g_isZeus（0x5428e8）的含义（§5 用它决定是否调 CLayerManager::UpdateInstanceActivation）
 *      与 Run_Room（0x54298c）的生命周期，都需要 CLayerManager 侧证据。
 *   7. +0x150、+0x160/+0x164/+0x168、+0x16c、+0x170、+0x174、+0x184 这些偏移本卡四节都没碰、
 *      Dump 也不打印，语义仍然未定。
 *   8. CPath::GetPosition 第 3 出参的语义：本卡证它在 0x1a756c..0x1a7588 与 x/y 同构线性插值
 *      （路径点 12 B = {x,y,speed}），按位置推是「该点的速度百分比」，但没有 CPath 侧卡钉名。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────────────────
 */

/* ══ §1 CInstance::Collision_Instance(CInstance*, bool) 0x195558 ══════════════
 * @func 0x195558 0x1958cc size 884  221 条（217 指令 + 末 4 字 0x1958bc..0x1958c8 为 literal pool；
 *       0x1958cc 是下一个符号 CInstance::SetID 的入口，不属于本节）
 * 级别: 正文（221/221 逐条落锚。五道早退、四道 bbox 闸、掩码号取值规则、三档判据、
 *       两条取整路径、PreciseCollision 的 15 个实参槽全部钉死；未钉的是被调方内部语义与
 *       option_use_fast_collision 的写方）
 * 符号: _ZN9CInstance18Collision_InstanceEPS_b → int CInstance::Collision_Instance(CInstance* other, bool checkMask)
 * 位置: CInstance::Collision_Skeleton 0x195294（size 708）之后、CInstance::SetID 0x1958cc 之前
 * 调用点（全 .text bl 扫描，12 处）
 *   0x1cc048 / 0x1cc184  processCollision(SCollision*) 0x1cc034
 *   0x1cc6b8 / 0x1cc800  HandleCollision() 0x1cc500
 *   0x1ca7a0 / 0x1ca924 / 0x1ca9c0  Command_InstancePlace(CInstance*,float,float,int) 0x1ca6d8
 *   0x1cab30  Command_IsEmpty(CInstance*,float,float) 0x1caa1c
 *   0x1cacc0  Command_IsFree(CInstance*,float,float) 0x1cab94
 *   0x1c86e0 / 0x1c87a4 / 0x1c8850  .dynsym 未覆盖的局部函数（0x1c8380..0x1c8bb4 之间，碰撞命令群）
 *
 */
/* @0x195558 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 帧：9 个核寄存器 36 B + 3 个 d 寄存器 24 B + 局部 60 B(0x3c) */
/* @0x19555c vpush {d8, d9, d10} */
/* @0x195560 mov r5, r0 */
/* @0x195564 ldr r4, [pc, #0x350] —— 池 0x1958bc = 0x0025c6dc；add 在 0x195574 ⇒ GOT 基址 0x3F1C58（与 CSprite::PreciseCollision 同一基址） */
/* @0x195568 sub sp, sp, #60 */
/* @0x19556c ldr r3, [pc, #0x34c] —— 池 0x1958c0 = 0xffffbf18 = -0x40E8 ⇒ 槽 0x3EDB70 = GOT 项 → g_bProfile（1 B） */
/* @0x195570 mov r7, r1 */
/* @0x195574 add r4, pc, r4 */
/* @0x195578 mov r8, r2 */
/* @0x19557c ldr r6, [r4, r3] —— r6 = &g_bProfile */
/* @0x195580 ldrb r3, [r6] —— *g_bProfile */
/* @0x195584 cmp r3, #0 */
/* @0x195588 bne 0x195600 <_ZN9CInstance18Collision_InstanceEPS_b+0xa8> —— 非 0 才进 profile 分支 */
/* @0x19558c cmp r5, r7 —— 早退①：this == other */
/* @0x195590 beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195594 ldrb r3, [r5, #0x68] —— 早退②：this->[0x68]（Dump 名 i_marked） */
/* @0x195598 cmp r3, #0 */
/* @0x19559c beq 0x1955cc <_ZN9CInstance18Collision_InstanceEPS_b+0x74> */
/* @0x1955a0 mov r5, #0 */
/* @0x1955a4 ldrb r3, [r6] */
/* @0x1955a8 cmp r3, #0 */
/* @0x1955ac beq 0x1955bc <_ZN9CInstance18Collision_InstanceEPS_b+0x64> */
/* @0x1955b0 ldr r3, [pc, #0x30c] */
/* @0x1955b4 ldr r0, [r4, r3] */
/* @0x1955b8 bl 0x2a08ac <_ZN9CProfiler3PopEv> —— CProfiler::Pop（与 Push 对称） */
/* @0x1955bc mov r0, r5 */
/* @0x1955c0 add sp, sp, #60 */
/* @0x1955c4 vpop {d8, d9, d10} */
/* @0x1955c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1955cc ldrb r3, [r7, #0x68] —— 早退③：other->[0x68] */
/* @0x1955d0 cmp r3, #0 */
/* @0x1955d4 bne 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1955d8 mov r0, r5 —— 骨架优先：this->SkeletonAnimation() 非 0 */
/* @0x1955dc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x1955e0 cmp r0, #0 */
/* @0x1955e4 beq 0x195618 <_ZN9CInstance18Collision_InstanceEPS_b+0xc0> */
/* @0x1955e8 mov r0, r5 */
/* @0x1955ec mov r1, r7 */
/* @0x1955f0 mov r2, r8 */
/* @0x1955f4 bl 0x195294 <_ZN9CInstance18Collision_SkeletonEPS_b> —— ⇒ 直接交给 Collision_Skeleton(this, other, checkMask)，不再做任何 bbox 判断 */
/* @0x1955f8 mov r5, r0 */
/* @0x1955fc b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x195600 ldr r3, [pc, #0x2bc] —— CProfiler::Push(6, 1)：段号 6 = 碰撞 profile 段 */
/* @0x195604 mov r1, #6 */
/* @0x195608 mov r2, #1 */
/* @0x19560c ldr r0, [r4, r3] */
/* @0x195610 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x195614 b 0x19558c <_ZN9CInstance18Collision_InstanceEPS_b+0x34> */
/* @0x195618 mov r0, r7 */
/* @0x19561c bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> —— other->SkeletonAnimation() 非 0 ⇒ Collision_Skeleton(other, this, checkMask)（实参顺序交换） */
/* @0x195620 cmp r0, #0 */
/* @0x195624 beq 0x195640 <_ZN9CInstance18Collision_InstanceEPS_b+0xe8> */
/* @0x195628 mov r1, r5 */
/* @0x19562c mov r0, r7 */
/* @0x195630 mov r2, r8 */
/* @0x195634 bl 0x195294 <_ZN9CInstance18Collision_SkeletonEPS_b> */
/* @0x195638 mov r5, r0 */
/* @0x19563c b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x195640 ldrb r3, [r7, #0x64] —— bbox 脏标志：other->[0x64] */
/* @0x195644 cmp r3, #0 */
/* @0x195648 bne 0x1957c8 <_ZN9CInstance18Collision_InstanceEPS_b+0x270> */
/* @0x19564c ldrb r3, [r5, #0x64] —— this->[0x64] */
/* @0x195650 cmp r3, #0 */
/* @0x195654 bne 0x1957b8 <_ZN9CInstance18Collision_InstanceEPS_b+0x260> */
/* @0x195658 ldr r2, [r5, #0xf0] —— bbox 四闸之一：this->bbox.right(+0xf0) < other->bbox.left(+0xe8) ⇒ 分离 */
/* @0x19565c ldr r3, [r7, #0xe8] */
/* @0x195660 cmp r2, r3 */
/* @0x195664 blt 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195668 ldr r2, [r7, #0xf0] —— other->bbox.right(+0xf0) < this->bbox.left(+0xe8) */
/* @0x19566c ldr r3, [r5, #0xe8] */
/* @0x195670 cmp r2, r3 */
/* @0x195674 blt 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195678 ldr r2, [r5, #0xf4] —— this->bbox.bottom(+0xf4) < other->bbox.top(+0xec) */
/* @0x19567c ldr r3, [r7, #0xec] */
/* @0x195680 cmp r2, r3 */
/* @0x195684 blt 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195688 ldr r2, [r7, #0xf4] —— other->bbox.bottom(+0xf4) < this->bbox.top(+0xec) */
/* @0x19568c ldr r3, [r5, #0xec] */
/* @0x195690 cmp r2, r3 */
/* @0x195694 blt 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x195698 ldr r0, [r5, #0xac] —— 掩码号：mask_index(+0xac) */
/* @0x19569c cmp r0, #0 */
/* @0x1956a0 ldrlt r0, [r5, #0x8c] —— mask_index < 0 时改用 sprite_index(+0x8c) */
/* @0x1956a4 bl 0x1ef03c <_Z11Sprite_Datai> —— Sprite_Data(idx) → CSprite*（this 侧存 r9） */
/* @0x1956a8 cmp r0, #0 */
/* @0x1956ac mov r9, r0 —— 空精灵 ⇒ 返回 0 */
/* @0x1956b0 beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1956b4 ldr r3, [r0, #0x18] —— spr+0x18 = 帧数，必须 > 0 */
/* @0x1956b8 cmp r3, #0 */
/* @0x1956bc beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1956c0 ldr r0, [r7, #0xac] —— other->mask_index */
/* @0x1956c4 cmp r0, #0 */
/* @0x1956c8 blt 0x1958ac <_ZN9CInstance18Collision_InstanceEPS_b+0x354> —— other 的 mask_index < 0 ⇒ 走 0x1958ac 用 sprite_index */
/* @0x1956cc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1956d0 mov r10, r0 */
/* @0x1956d4 cmp r10, #0 */
/* @0x1956d8 beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1956dc ldr r3, [r10, #0x18] */
/* @0x1956e0 cmp r3, #0 */
/* @0x1956e4 beq 0x1955a0 <_ZN9CInstance18Collision_InstanceEPS_b+0x48> */
/* @0x1956e8 cmp r8, #0 —— checkMask == 0 ⇒ 返回 1（bbox 相交即算碰） */
/* @0x1956ec beq 0x1957d8 <_ZN9CInstance18Collision_InstanceEPS_b+0x280> */
/* @0x1956f0 ldrb r3, [r9, #0x30] —— sprA+0x30 = 该精灵是否有掩码 */
/* @0x1956f4 cmp r3, #0 */
/* @0x1956f8 bne 0x195708 <_ZN9CInstance18Collision_InstanceEPS_b+0x1b0> */
/* @0x1956fc ldrb r3, [r10, #0x30] —— sprB+0x30 */
/* @0x195700 cmp r3, #0 */
/* @0x195704 beq 0x1957d8 <_ZN9CInstance18Collision_InstanceEPS_b+0x280> —— 两侧都无掩码 ⇒ 返回 1（全实心） */
/* @0x195708 ldr r3, [pc, #0x1b8] —— 池 0x1958c8 = 0xffffea30 = -0x15D0 ⇒ 槽 0x3F0688 → option_use_fast_collision（0x542379） */
/* @0x19570c ldr r3, [r4, r3] */
/* @0x195710 ldrb r3, [r3] */
/* @0x195714 cmp r3, #0 */
/* @0x195718 beq 0x1957e0 <_ZN9CInstance18Collision_InstanceEPS_b+0x288> */
/* @0x19571c vldr s15, [r5, #184] —— 快路径：x/y 用 vcvt.s32 截断 */
/* @0x195720 vcvt.s32.f32 s15, s15 */
/* @0x195724 vldr s11, [r7, #144] */
/* @0x195728 vldr s12, [r7, #180] */
/* @0x19572c vldr s13, [r7, #184] */
/* @0x195730 str r10, [sp, #0x10] */
/* @0x195734 ldr r1, [r5, #0x98] */
/* @0x195738 vldr s14, [r5, #144] */
/* @0x19573c ldr r2, [r5, #0x9c] */
/* @0x195740 mov r0, r9 */
/* @0x195744 vmov r3, s15 —— r3 = (int)this->y（第 4 实参 yA） */
/* @0x195748 vldr s15, [r5, #180] */
/* @0x19574c str r2, [sp, #0x8] */
/* @0x195750 vcvt.s32.f32 s11, s11 */
/* @0x195754 str r1, [sp, #0x4] */
/* @0x195758 add r2, r5, #232 —— r2 = &this->bbox（第 2 实参 rectA） */
/* @0x19575c ldr r1, [r5, #0xa0] */
/* @0x195760 str r1, [sp, #0xc] */
/* @0x195764 vcvt.s32.f32 s12, s12 */
/* @0x195768 vcvt.s32.f32 s13, s13 */
/* @0x19576c str r3, [sp] */
/* @0x195770 add r3, r7, #232 —— r3 = &other->bbox（第 10 实参 rectB） */
/* @0x195774 ldr r1, [r7, #0x98] */
/* @0x195778 vcvt.s32.f32 s14, s14 */
/* @0x19577c str r3, [sp, #0x18] */
/* @0x195780 str r1, [sp, #0x24] */
/* @0x195784 ldr r1, [r7, #0x9c] */
/* @0x195788 ldr r3, [r7, #0xa0] */
/* @0x19578c vstr s11, [sp, #20] */
/* @0x195790 vstr s12, [sp, #28] */
/* @0x195794 vstr s13, [sp, #32] */
/* @0x195798 str r1, [sp, #0x28] */
/* @0x19579c vcvt.s32.f32 s15, s15 */
/* @0x1957a0 str r3, [sp, #0x2c] */
/* @0x1957a4 vmov r1, s14 */
/* @0x1957a8 vmov r3, s15 */
/* @0x1957ac bl 0x1e4298 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff> —— CSprite::PreciseCollision(15 实参，见下表) */
/* @0x1957b0 mov r5, r0 */
/* @0x1957b4 b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x1957b8 mov r0, r5 —— this->+0x64 非 0 ⇒ Compute_BoundingBox(this, true) 后再比 bbox */
/* @0x1957bc mov r1, #1 */
/* @0x1957c0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1957c4 b 0x195658 <_ZN9CInstance18Collision_InstanceEPS_b+0x100> */
/* @0x1957c8 mov r0, r7 —— other->+0x64 非 0 ⇒ Compute_BoundingBox(other, true) */
/* @0x1957cc mov r1, #1 */
/* @0x1957d0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1957d4 b 0x19564c <_ZN9CInstance18Collision_InstanceEPS_b+0xf4> */
/* @0x1957d8 mov r5, #1 —— 返回 1 */
/* @0x1957dc b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x1957e0 vldr s15, [r5, #180] —— 慢/精确路径：x/y 用 lrint 四舍五入（option_use_fast_collision == 0 时） */
/* @0x1957e4 vcvt.f64.f32 d6, s15 */
/* @0x1957e8 vldr s16, [r5, #144] */
/* @0x1957ec vmov r0, r1, d6 */
/* @0x1957f0 bl 0xb66e8 <lrint@plt> */
/* @0x1957f4 vldr s15, [r5, #184] */
/* @0x1957f8 vcvt.f64.f32 d6, s15 */
/* @0x1957fc vcvt.s32.f32 s16, s16 */
/* @0x195800 mov r8, r0 */
/* @0x195804 vmov r0, r1, d6 */
/* @0x195808 bl 0xb66e8 <lrint@plt> */
/* @0x19580c vldr s15, [r7, #180] —— other->x → lrint */
/* @0x195810 vcvt.f64.f32 d6, s15 */
/* @0x195814 vldr s20, [r5, #152] */
/* @0x195818 vldr s19, [r5, #156] */
/* @0x19581c vldr s18, [r5, #160] */
/* @0x195820 vldr s17, [r7, #144] */
/* @0x195824 vcvt.s32.f32 s17, s17 */
/* @0x195828 mov r3, r0 */
/* @0x19582c vmov r0, r1, d6 */
/* @0x195830 str r3, [sp, #0x34] */
/* @0x195834 bl 0xb66e8 <lrint@plt> */
/* @0x195838 vldr s15, [r7, #184] —— other->y → lrint */
/* @0x19583c vcvt.f64.f32 d6, s15 */
/* @0x195840 mov r11, r0 */
/* @0x195844 vmov r0, r1, d6 */
/* @0x195848 bl 0xb66e8 <lrint@plt> */
/* @0x19584c ldr r3, [sp, #0x34] */
/* @0x195850 vstr s17, [sp, #20] */
/* @0x195854 vstr s20, [sp, #4] */
/* @0x195858 vstr s19, [sp, #8] */
/* @0x19585c vstr s18, [sp, #12] */
/* @0x195860 str r3, [sp] */
/* @0x195864 add r12, r7, #232 */
/* @0x195868 str r11, [sp, #0x1c] */
/* @0x19586c add r2, r5, #232 */
/* @0x195870 str r10, [sp, #0x10] */
/* @0x195874 mov r3, r8 */
/* @0x195878 ldr lr, [r7, #0x98] */
/* @0x19587c str r12, [sp, #0x18] */
/* @0x195880 vmov r1, s16 */
/* @0x195884 str lr, [sp, #0x24] */
/* @0x195888 ldr lr, [r7, #0x9c] */
/* @0x19588c ldr r12, [r7, #0xa0] */
/* @0x195890 str lr, [sp, #0x28] */
/* @0x195894 str r12, [sp, #0x2c] */
/* @0x195898 str r0, [sp, #0x20] —— yB = lrint(other->y) 落 [sp+0x20] */
/* @0x19589c mov r0, r9 */
/* @0x1958a0 bl 0x1e4298 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff> —— 同一个 PreciseCollision，只有取整方式不同 */
/* @0x1958a4 mov r5, r0 */
/* @0x1958a8 b 0x1955a4 <_ZN9CInstance18Collision_InstanceEPS_b+0x4c> */
/* @0x1958ac ldr r0, [r7, #0x8c] —— other 侧 sprite_index 兜底 */
/* @0x1958b0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1958b4 mov r10, r0 */
/* @0x1958b8 b 0x1956d4 <_ZN9CInstance18Collision_InstanceEPS_b+0x17c> */
/* @0x1958bc .word 0x0025c6dc —— 池字 0x0025c6dc（GOT 基址增量），非指令 */
/* @0x1958c0 .word 0xffffbf18 —— 池字 0xffffbf18 = -0x40E8（g_bProfile 槽），非指令 */
/* @0x1958c4 .word 0xffffbf1c —— 池字 0xffffbf1c = -0x40E4（g_Profiler 槽），非指令 */
/* @0x1958c8 .word 0xffffea30 —— 池字 0xffffea30 = -0x15D0（option_use_fast_collision 槽），非指令 */
/* ══ §2 CInstance::Collision_Ellipse(float,float,float,float,bool) 0x194a90 ═══
 * @func 0x194a90 0x194f28 size 1176  294 条（293 指令 + 末 1 字 0x194f24 为 literal pool；
 *       0x194f28 是下一个符号 Collision_Line 的入口）
 * 级别: 正文（294/294 逐条落锚。椭圆判据 = 外接矩形 + InEll 角点测试 + 中心短路，
 *       两级掩码闸、骨架/精灵两条像素级出口、四条带 +1 的 bbox 闸全部钉死）
 * 符号: _ZN9CInstance17Collision_EllipseEffffb → int CInstance::Collision_Ellipse(float x1, float y1, float x2, float y2, bool checkMask)
 * 位置: CInstance::Collision_Rectangle 0x1946f4（size 756）之后、Collision_Line 0x194f28 之前
 *       同群静态函数 InEll(tagYYRECT*, int, int) 0x1949e8（size 168，42 条）位于 Collision_Rectangle 与本节之间
 * 调用点（全 .text bl 扫描，3 处，全在同一个函数里）：
 *   Command_CollisionEllipse(CInstance*,float,float,float,float,int,bool) 0x1c8bb4
 *     → 0x1c8ca8（第 1 条出口）、0x1c8d50、0x1c8dc0
 *
 */
/* @0x194a90 push {r4, r5, r6, r7, r8, r9, lr} —— 帧：7 核寄存器 28 B + 6 个 d 寄存器 48 B + 局部 60 B；两个栈形参落在 [sp+0x88]/[sp+0x8c] */
/* @0x194a94 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x194a98 sub sp, sp, #60 */
/* @0x194a9c vldr s27, [sp, #136] —— [sp+0x88] = 第 5 实参 y2 */
/* @0x194aa0 mov r4, r0 */
/* @0x194aa4 vmov s25, r3 */
/* @0x194aa8 vmov s24, r1 */
/* @0x194aac ldrb r7, [sp, #0x8c] —— [sp+0x8c] = 第 6 实参 checkMask */
/* @0x194ab0 vmov s26, r2 */
/* @0x194ab4 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> —— this->SkeletonAnimation() → CSkeletonInstance* 或 0（r8） */
/* @0x194ab8 subs r8, r0, #0 */
/* @0x194abc ldrbeq r3, [r4, #0x64] —— 无骨架：r3 = this->[0x64]（bbox 脏标志） */
/* @0x194ac0 beq 0x194b2c <_ZN9CInstance17Collision_EllipseEffffb+0x9c> */
/* @0x194ac4 vldr s15, [r4, #144] —— (float)(int)image_index(+0x90) → r2 */
/* @0x194ac8 vcvt.s32.f32 s15, s15 */
/* @0x194acc ldr r5, [pc, #0x450] —— 池 0x194f24 = 0x00258e5c；ldr r5,[pc,r5] 在 0x194ad8 ⇒ 槽 0x3ED93C → CSkeletonSprite::ms_drawInstance */
/* @0x194ad0 ldr r1, [r4, #0xa0] */
/* @0x194ad4 ldr r9, [r4, #0xb8] */
/* @0x194ad8 ldr r5, [pc, r5] */
/* @0x194adc ldr lr, [r4, #0x98] */
/* @0x194ae0 ldr r12, [r4, #0x9c] */
/* @0x194ae4 ldr r3, [r4, #0xb4] */
/* @0x194ae8 ldr r6, [r5] —— 保存 ms_drawInstance 旧值（r6） */
/* @0x194aec vmov r2, s15 */
/* @0x194af0 str r4, [r5] —— 临时把 this 写进 ms_drawInstance */
/* @0x194af4 str r1, [sp, #0xc] */
/* @0x194af8 add r1, r4, #232 —— r1 = &this->bbox(+0xe8) */
/* @0x194afc str r9, [sp] */
/* @0x194b00 str lr, [sp, #0x4] */
/* @0x194b04 str r12, [sp, #0x8] */
/* @0x194b08 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff> —— CSkeletonInstance::ComputeBoundingBox(bbox, (int)image_index, x, y, xscale, yscale, …) */
/* @0x194b0c str r6, [r5] —— 还原 ms_drawInstance */
/* @0x194b10 cmp r0, #0 */
/* @0x194b14 ldrbeq r3, [r4, #0x64] —— 返回 0 ⇒ r3 = this->[0x64]（退回脏标志路） */
/* @0x194b18 movne r2, #0 */
/* @0x194b1c movne r3, r2 */
/* @0x194b20 movne r1, #1 */
/* @0x194b24 strbne r2, [r4, #0x64] —— 返回非 0 ⇒ +0x64 = 0（bbox 不再是脏的） */
/* @0x194b28 strbne r1, [r4, #0xb0] —— 同时 +0xb0 = 1（Dump 名 i_precise） */
/* @0x194b2c cmp r3, #0 */
/* @0x194b30 bne 0x194e58 <_ZN9CInstance17Collision_EllipseEffffb+0x3c8> —— r3 != 0（脏）⇒ 走 0x194e58 的 Compute_BoundingBox(this, true) */
/* @0x194b34 ldr r3, [r4, #0xf0] —— 闸①：min(x1,x2) >= (float)(bbox.right+1) ⇒ 分离返回 0 */
/* @0x194b38 vcmpe.f32 s24, s25 */
/* @0x194b3c add r3, r3, #1 */
/* @0x194b40 vmov s12, r3 */
/* @0x194b44 vmrs APSR_nzcv, fpscr */
/* @0x194b48 vmovpl.f32 s14, s25 */
/* @0x194b4c vmovmi.f32 s14, s24 */
/* @0x194b50 vcvt.f32.s32 s15, s12 */
/* @0x194b54 vcmpe.f32 s14, s15 */
/* @0x194b58 vmrs APSR_nzcv, fpscr */
/* @0x194b5c bge 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194b60 vcmpe.f32 s24, s25 —— 闸②：max(x1,x2) < (float)bbox.left ⇒ 返回 0 */
/* @0x194b64 vldr s13, [r4, #232] */
/* @0x194b68 vcvt.f32.s32 s15, s13 */
/* @0x194b6c vmrs APSR_nzcv, fpscr */
/* @0x194b70 vmovle.f32 s14, s25 */
/* @0x194b74 vmovgt.f32 s14, s24 */
/* @0x194b78 vcmpe.f32 s14, s15 */
/* @0x194b7c vmrs APSR_nzcv, fpscr */
/* @0x194b80 bmi 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194b84 ldr r3, [r4, #0xf4] —— 闸③：min(y1,y2) >= (float)(bbox.bottom+1) ⇒ 返回 0 */
/* @0x194b88 vcmpe.f32 s26, s27 */
/* @0x194b8c add r3, r3, #1 */
/* @0x194b90 vmov s14, r3 */
/* @0x194b94 vmrs APSR_nzcv, fpscr */
/* @0x194b98 vcvt.f32.s32 s15, s14 */
/* @0x194b9c vmovpl.f32 s14, s27 */
/* @0x194ba0 vmovmi.f32 s14, s26 */
/* @0x194ba4 vcmpe.f32 s14, s15 */
/* @0x194ba8 vmrs APSR_nzcv, fpscr */
/* @0x194bac bge 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194bb0 vcmpe.f32 s26, s27 —— 闸④：max(y1,y2) < (float)bbox.top ⇒ 返回 0 */
/* @0x194bb4 vldr s12, [r4, #236] */
/* @0x194bb8 vcvt.f32.s32 s15, s12 */
/* @0x194bbc vmrs APSR_nzcv, fpscr */
/* @0x194bc0 vmovle.f32 s14, s27 */
/* @0x194bc4 vmovgt.f32 s14, s26 */
/* @0x194bc8 vcmpe.f32 s14, s15 */
/* @0x194bcc vmrs APSR_nzcv, fpscr */
/* @0x194bd0 bmi 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194bd4 ldrb r3, [r4, #0x68] —— 闸⑤：this->+0x68（i_marked）非 0 ⇒ 返回 0 */
/* @0x194bd8 cmp r3, #0 */
/* @0x194bdc bne 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194be0 vcvt.f64.f32 d9, s24 —— 退化判定：lrint(x1) */
/* @0x194be4 vmov r0, r1, d9 */
/* @0x194be8 bl 0xb66e8 <lrint@plt> —— 与 lrint(x2) 比较 */
/* @0x194bec vcvt.f64.f32 d8, s25 */
/* @0x194bf0 mov r5, r0 */
/* @0x194bf4 vmov r0, r1, d8 */
/* @0x194bf8 bl 0xb66e8 <lrint@plt> —— lrint(x2) */
/* @0x194bfc cmp r5, r0 */
/* @0x194c00 beq 0x194e68 <_ZN9CInstance17Collision_EllipseEffffb+0x3d8> —— 相等 ⇒ 0x194e68 退化成 Collision_Rectangle */
/* @0x194c04 vcvt.f64.f32 d11, s26 */
/* @0x194c08 vmov r0, r1, d11 */
/* @0x194c0c bl 0xb66e8 <lrint@plt> —— lrint(y1) / lrint(y2) 同理 */
/* @0x194c10 vcvt.f64.f32 d10, s27 */
/* @0x194c14 mov r5, r0 */
/* @0x194c18 vmov r0, r1, d10 */
/* @0x194c1c bl 0xb66e8 <lrint@plt> */
/* @0x194c20 cmp r5, r0 */
/* @0x194c24 beq 0x194e68 <_ZN9CInstance17Collision_EllipseEffffb+0x3d8> —— y 相等也退化 */
/* @0x194c28 vcmpe.f32 s24, s25 —— [sp+0x18] = lrint(min(x1,x2)) */
/* @0x194c2c vmrs APSR_nzcv, fpscr */
/* @0x194c30 vmovpl r0, r1, d8 */
/* @0x194c34 vmovmi r0, r1, d9 */
/* @0x194c38 bl 0xb66e8 <lrint@plt> */
/* @0x194c3c vcmpe.f32 s26, s27 */
/* @0x194c40 vmrs APSR_nzcv, fpscr */
/* @0x194c44 str r0, [sp, #0x18] */
/* @0x194c48 vmovpl r0, r1, d10 —— [sp+0x1c] = lrint(min(y1,y2)) */
/* @0x194c4c vmovmi r0, r1, d11 */
/* @0x194c50 bl 0xb66e8 <lrint@plt> */
/* @0x194c54 vcmpe.f32 s24, s25 */
/* @0x194c58 vmrs APSR_nzcv, fpscr */
/* @0x194c5c str r0, [sp, #0x1c] */
/* @0x194c60 vmovle r0, r1, d8 —— [sp+0x20] = lrint(max(x1,x2)) */
/* @0x194c64 vmovgt r0, r1, d9 */
/* @0x194c68 bl 0xb66e8 <lrint@plt> */
/* @0x194c6c vcmpe.f32 s26, s27 */
/* @0x194c70 vmrs APSR_nzcv, fpscr */
/* @0x194c74 str r0, [sp, #0x20] */
/* @0x194c78 vmovle r0, r1, d10 —— [sp+0x24] = lrint(max(y1,y2)) */
/* @0x194c7c vmovgt r0, r1, d11 */
/* @0x194c80 bl 0xb66e8 <lrint@plt> */
/* @0x194c84 ldr r1, [r4, #0xe8] —— 中心 cx = (x1+x2)*0.5，与 bbox.left 比 */
/* @0x194c88 vadd.f32 s14, s24, s25 */
/* @0x194c8c vmov s12, r1 */
/* @0x194c90 vmov.f32 s15, #5.000000e-01 */
/* @0x194c94 vmul.f32 s15, s14, s15 */
/* @0x194c98 str r0, [sp, #0x24] */
/* @0x194c9c vcvt.f32.s32 s14, s12 */
/* @0x194ca0 vcmpe.f32 s14, s15 */
/* @0x194ca4 vmrs APSR_nzcv, fpscr */
/* @0x194ca8 bhi 0x194cc0 <_ZN9CInstance17Collision_EllipseEffffb+0x230> */
/* @0x194cac vldr s13, [r4, #240] */
/* @0x194cb0 vcvt.f32.s32 s14, s13 */
/* @0x194cb4 vcmpe.f32 s15, s14 */
/* @0x194cb8 vmrs APSR_nzcv, fpscr */
/* @0x194cbc bls 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> —— cx 落在 [left,right] 内 ⇒ 直接放行到 0x194d0c */
/* @0x194cc0 vadd.f32 s14, s26, s27 —— 否则同样判 cy 是否在 [top,bottom] 内 */
/* @0x194cc4 ldr r2, [r4, #0xec] */
/* @0x194cc8 vmov s12, r2 */
/* @0x194ccc vmov.f32 s15, #5.000000e-01 */
/* @0x194cd0 vmul.f32 s15, s14, s15 */
/* @0x194cd4 vcvt.f32.s32 s14, s12 */
/* @0x194cd8 vcmpe.f32 s14, s15 */
/* @0x194cdc vmrs APSR_nzcv, fpscr */
/* @0x194ce0 bhi 0x194cf8 <_ZN9CInstance17Collision_EllipseEffffb+0x268> */
/* @0x194ce4 vldr s13, [r4, #244] */
/* @0x194ce8 vcvt.f32.s32 s14, s13 */
/* @0x194cec vcmpe.f32 s15, s14 */
/* @0x194cf0 vmrs APSR_nzcv, fpscr */
/* @0x194cf4 bls 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> —— cy 也在区间内 ⇒ 放行 */
/* @0x194cf8 add r5, sp, #24 */
/* @0x194cfc mov r0, r5 */
/* @0x194d00 bl 0x1949e8 <_Z5InEllP9tagYYRECTii> —— InEll(&rect(sp+0x18), bbox.left, bbox.top) */
/* @0x194d04 cmp r0, #0 */
/* @0x194d08 beq 0x194e00 <_ZN9CInstance17Collision_EllipseEffffb+0x370> —— 角点不在椭圆内 ⇒ 继续试其余三角 */
/* @0x194d0c cmp r7, #0 —— 闸⑥：checkMask == 0 ⇒ 返回 1 */
/* @0x194d10 beq 0x194e88 <_ZN9CInstance17Collision_EllipseEffffb+0x3f8> */
/* @0x194d14 ldrb r3, [r4, #0xb0] —— 闸⑦：this->+0xb0（i_precise）== 0 ⇒ 返回 1 */
/* @0x194d18 cmp r3, #0 */
/* @0x194d1c beq 0x194e88 <_ZN9CInstance17Collision_EllipseEffffb+0x3f8> */
/* @0x194d20 vcmpe.f32 s24, s25 —— 第二份矩形 [sp+0x28..0x34]（与 sp+0x18 同值，这次用 vcmp 非 excepting 版） */
/* @0x194d24 vmrs APSR_nzcv, fpscr */
/* @0x194d28 vmovpl r0, r1, d8 */
/* @0x194d2c vmovmi r0, r1, d9 */
/* @0x194d30 bl 0xb66e8 <lrint@plt> */
/* @0x194d34 vcmpe.f32 s26, s27 */
/* @0x194d38 vmrs APSR_nzcv, fpscr */
/* @0x194d3c str r0, [sp, #0x28] */
/* @0x194d40 vmovpl r0, r1, d10 */
/* @0x194d44 vmovmi r0, r1, d11 */
/* @0x194d48 bl 0xb66e8 <lrint@plt> */
/* @0x194d4c vcmp.f32 s24, s25 */
/* @0x194d50 vmrs APSR_nzcv, fpscr */
/* @0x194d54 str r0, [sp, #0x2c] */
/* @0x194d58 vmovgt r0, r1, d9 */
/* @0x194d5c vmovle r0, r1, d8 */
/* @0x194d60 bl 0xb66e8 <lrint@plt> */
/* @0x194d64 vcmp.f32 s26, s27 */
/* @0x194d68 vmrs APSR_nzcv, fpscr */
/* @0x194d6c str r0, [sp, #0x30] */
/* @0x194d70 vmovgt r0, r1, d11 */
/* @0x194d74 vmovle r0, r1, d10 */
/* @0x194d78 bl 0xb66e8 <lrint@plt> */
/* @0x194d7c cmp r8, #0 —— 有骨架 ⇒ 0x194d88；无骨架 ⇒ 0x194e90 走 CSprite */
/* @0x194d80 str r0, [sp, #0x34] */
/* @0x194d84 beq 0x194e90 <_ZN9CInstance17Collision_EllipseEffffb+0x400> */
/* @0x194d88 vldr s15, [r4, #180] —— lrint(this->x) → r5 */
/* @0x194d8c vcvt.f64.f32 d6, s15 */
/* @0x194d90 vldr s15, [r4, #144] —— (int)image_index → r6 */
/* @0x194d94 vcvt.s32.f32 s15, s15 */
/* @0x194d98 vmov r0, r1, d6 */
/* @0x194d9c vmov r6, s15 */
/* @0x194da0 bl 0xb66e8 <lrint@plt> */
/* @0x194da4 vldr s15, [r4, #184] —— lrint(this->y) → r0 */
/* @0x194da8 vcvt.f64.f32 d6, s15 */
/* @0x194dac mov r5, r0 */
/* @0x194db0 vmov r0, r1, d6 */
/* @0x194db4 bl 0xb66e8 <lrint@plt> */
/* @0x194db8 ldr r2, [r4, #0x98] */
/* @0x194dbc vmov s13, r5 */
/* @0x194dc0 ldr r3, [r4, #0x9c] */
/* @0x194dc4 mov r1, r6 */
/* @0x194dc8 vcvt.f32.s32 s13, s13 */
/* @0x194dcc str r2, [sp] */
/* @0x194dd0 str r3, [sp, #0x4] */
/* @0x194dd4 ldr r3, [r4, #0xa0] */
/* @0x194dd8 str r3, [sp, #0x8] */
/* @0x194ddc add r3, sp, #40 */
/* @0x194de0 str r3, [sp, #0xc] */
/* @0x194de4 vmov r2, s13 —— r2 = (float)lrint(x)，r3 = (float)lrint(y) */
/* @0x194de8 vmov s14, r0 */
/* @0x194dec mov r0, r8 —— r0 = CSkeletonInstance* */
/* @0x194df0 vcvt.f32.s32 s15, s14 */
/* @0x194df4 vmov r3, s15 */
/* @0x194df8 bl 0xbf524 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT> —— CSkeletonInstance::EllipseCollision((int)frame, x, y, xscale, yscale, angle, &rect) */
/* @0x194dfc b 0x194e4c <_ZN9CInstance17Collision_EllipseEffffb+0x3bc> */
/* @0x194e00 mov r0, r5 —— 角点②：InEll(rect, bbox.left, bbox.bottom) */
/* @0x194e04 ldr r1, [r4, #0xe8] */
/* @0x194e08 ldr r2, [r4, #0xf4] */
/* @0x194e0c bl 0x1949e8 <_Z5InEllP9tagYYRECTii> */
/* @0x194e10 cmp r0, #0 */
/* @0x194e14 bne 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> */
/* @0x194e18 mov r0, r5 */
/* @0x194e1c ldr r1, [r4, #0xf0] —— 角点③：InEll(rect, bbox.right, bbox.top) */
/* @0x194e20 ldr r2, [r4, #0xec] */
/* @0x194e24 bl 0x1949e8 <_Z5InEllP9tagYYRECTii> */
/* @0x194e28 cmp r0, #0 */
/* @0x194e2c bne 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> */
/* @0x194e30 mov r0, r5 */
/* @0x194e34 ldr r1, [r4, #0xf0] —— 角点④：InEll(rect, bbox.right, bbox.bottom) */
/* @0x194e38 ldr r2, [r4, #0xf4] */
/* @0x194e3c bl 0x1949e8 <_Z5InEllP9tagYYRECTii> */
/* @0x194e40 cmp r0, #0 */
/* @0x194e44 bne 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> */
/* @0x194e48 mov r0, #0 —— 四角全在椭圆外 ⇒ 返回 0 */
/* @0x194e4c add sp, sp, #60 */
/* @0x194e50 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x194e54 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x194e58 mov r0, r4 —— Compute_BoundingBox(this, true) 后回到闸① */
/* @0x194e5c mov r1, #1 */
/* @0x194e60 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x194e64 b 0x194b34 <_ZN9CInstance17Collision_EllipseEffffb+0xa4> */
/* @0x194e68 vstr s27, [sp] —— 退化成矩形判碰：Collision_Rectangle(this, x1, y1, x2, y2, checkMask)（原始 float，非取整值） */
/* @0x194e6c str r7, [sp, #0x4] */
/* @0x194e70 mov r0, r4 */
/* @0x194e74 vmov r1, s24 */
/* @0x194e78 vmov r2, s26 */
/* @0x194e7c vmov r3, s25 */
/* @0x194e80 bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x194e84 b 0x194e4c <_ZN9CInstance17Collision_EllipseEffffb+0x3bc> */
/* @0x194e88 mov r0, #1 —— 返回 1 */
/* @0x194e8c b 0x194e4c <_ZN9CInstance17Collision_EllipseEffffb+0x3bc> */
/* @0x194e90 ldr r0, [r4, #0xac] —— 掩码号：mask_index(+0xac)，<0 时用 sprite_index(+0x8c) */
/* @0x194e94 cmp r0, #0 */
/* @0x194e98 ldrlt r0, [r4, #0x8c] */
/* @0x194e9c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x194ea0 cmp r0, #0 —— Sprite_Data → CSprite* */
/* @0x194ea4 mov r5, r0 */
/* @0x194ea8 beq 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194eac ldr r3, [r0, #0x18] —— spr+0x18（帧数）必须 > 0，否则返回 0 */
/* @0x194eb0 cmp r3, #0 */
/* @0x194eb4 beq 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194eb8 vldr s15, [r4, #180] */
/* @0x194ebc vcvt.f64.f32 d6, s15 */
/* @0x194ec0 vldr s15, [r4, #144] */
/* @0x194ec4 vcvt.s32.f32 s15, s15 */
/* @0x194ec8 vmov r0, r1, d6 */
/* @0x194ecc vmov r7, s15 */
/* @0x194ed0 bl 0xb66e8 <lrint@plt> */
/* @0x194ed4 vldr s15, [r4, #184] */
/* @0x194ed8 vcvt.f64.f32 d6, s15 */
/* @0x194edc mov r6, r0 */
/* @0x194ee0 vmov r0, r1, d6 */
/* @0x194ee4 bl 0xb66e8 <lrint@plt> */
/* @0x194ee8 ldr r12, [r4, #0x98] */
/* @0x194eec ldr r2, [r4, #0x9c] */
/* @0x194ef0 mov r1, r7 */
/* @0x194ef4 mov r3, r6 */
/* @0x194ef8 str r12, [sp, #0x4] —— 实参：[sp+4]=xscale、[sp+8]=yscale、[sp+0xc]=angle、[sp+0x10]=&rect */
/* @0x194efc str r2, [sp, #0x8] */
/* @0x194f00 add r2, r4, #232 */
/* @0x194f04 ldr r12, [r4, #0xa0] */
/* @0x194f08 str r12, [sp, #0xc] */
/* @0x194f0c add r12, sp, #40 */
/* @0x194f10 str r12, [sp, #0x10] */
/* @0x194f14 str r0, [sp] */
/* @0x194f18 mov r0, r5 */
/* @0x194f1c bl 0x1e4f0c <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_> —— CSprite::PreciseCollisionEllipse((int)frame, &this->bbox, x, y, xscale, yscale, angle, &rect) */
/* @0x194f20 b 0x194e4c <_ZN9CInstance17Collision_EllipseEffffb+0x3bc> */
/* @0x194f24 eoreq r8, r5, r12, asr lr —— 池字 0x00258e5c（ms_drawInstance 的 GOT 增量），非指令 */
/* ══ §3 CInstance::Adapt_Path() 0x19411c ═══════════════════════════════════════
 * @func 0x19411c 0x1944b0 size 916  229 条（225 指令 + 末 4 字 0x1944a0..0x1944ac 为 literal pool；
 *       0x1944b0 是下一个符号 Collision_Point 的入口）
 * 级别: 正文（229/229 逐条落锚。三道前置闸、步长公式的三个乘除项、endaction 跳表的 4+1 个出口、
 *       +0x144/+0x148 的读写、四个 Set* 的调用顺序全部钉死；未钉的是 GetPosition 第 3 出参的
 *       语义名与 SetSpeed(0) 的后果）
 * 符号: _ZN9CInstance10Adapt_PathEv → int CInstance::Adapt_Path(void)
 * 位置: CInstance::Assign_Path 0x193fe0（size 316）之后、Collision_Point 0x1944b0 之前
 * 调用点（全 .text bl 扫描，7 处）：
 *   0x1cc11c / 0x1cc124  processCollision(SCollision*) 0x1cc034
 *   0x1cc6dc / 0x1cc6e4  HandleCollision() 0x1cc500
 *   0x1d1dd8  HandleInstanceMovement(bool) 0x1d1cec
 *   0x237fbc / 0x238028  CPhysicsWorld::UpdatePaths() 0x237f94
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   沿路径推进一步：按「实例 path_speed × 该点速度百分比 ÷(path_scale×100) ÷ 路径长度」算出
 *   path_position 的增量，写回 +0x12c；越界时按 path_endaction(+0x140) 四选一处理
 *   （停/重来/接续/反向），然后把路径坐标经 path_orientation 旋转、乘 path_scale、
 *   加上 pathxstart/pathystart(+0x144/+0x148) 得到世界坐标，用 SetPosition 落位，
 *   并把位移写进 hspeed/vspeed。全函数不碰 bbox、不置脏标志。
 *
 * ── 语义草案 ──────────────────────────────────────────────────────────────
 *   int CInstance::Adapt_Path() {
 *     if (path_index < 0) return 0;                       // 0x194130
 *     CPath* cp = Path_Data(path_index); if (!cp) return 0;
 *     float len = cp->GetPathLength(); if (!(len > 0)) return 0;
 *     float th  = path_orientation * PI / 180.0f;         // 0x194158..0x19418c
 *     float p3; cp->GetPosition(path_position, &px, &py, &p3);
 *     float dpos = path_speed * (p3 / (path_scale*100.0f)) / len;
 *     path_position += dpos;                              // 0x1941d0
 *     int r = 0;
 *     if (path_position >= 1.0f || path_position <= 0.0f) {
 *       r = (path_speed != 0);                            // 0x1941ec/0x1941f0
 *       switch (path_endaction) {
 *       case 0: // stop：  if (path_speed < 0) { path_position = 0; path_index = -1; }
 *                            else if (path_speed != 0) { path_index = -1; path_position = 1.0f; }
 *                            break;                      // 0x19423c / 0x194258 / 0x194460
 *       case 1: // restart：path_position += (path_position < 0 ? +1.0f : -1.0f); break;
 *       case 2: // continue：位移累加见 0x1943a0 / 0x194478
 *         break;
 *       case 3: // reverse：path_position = (path_position >= 0) ? 2.0f - path_position
 *                                                                 : -path_position;
 *                            path_speed = (path_position >= 0 ? -1 : 1) * fabsf(path_speed);
 *                            break;                      // 0x19434c
 *       default: return 0;                                // 0x194210
 *       }
 *     }
 *     float c = cosf(th), s = sinf(th);
 *     cp->GetPosition(path_position, &px, &py, &p3);
 *     float dx = px - cp->XPosition(0.0f), dy = py - cp->YPosition(0.0f);
 *     float nx = pathxstart + path_scale * ( dx*c + dy*s);
 *     float ny = pathystart + path_scale * ( dx*s - dy*c);
 *     SetHspeed(nx - x); SetVspeed(ny - y); SetSpeed(0); SetPosition(nx, ny);
 *     return r;
 *   }
 *
 * ── 字段读写表（本函数碰到的全部偏移）────────────────────────────────────────
 *   +0x0b4 float x           只读（0x1942d8，用来算 hspeed = nx - x）
 *   +0x0b8 float y           只读（0x19430c，算 vspeed）
 *   +0x128 int   path_index  只读（0x194128）与写 -1（0x194264 / 0x19446c）
 *   +0x12c float path_position  读（0x1941a4）→ 写新值（0x1941d0）→ 分支里再改
 *   +0x134 float path_speed  只读（0x1941a0、0x1941dc）与写（0x19437c reverse 分支）
 *   +0x138 float path_scale  只读（0x194190）
 *   +0x13c float path_orientation 只读（0x194158）
 *   +0x140 int   path_endaction   只读（0x1941e4，跳表键）
 *   +0x144 float pathxstart  读（0x1942d0）与写（0x194444 / 0x19447c / 0x19448c）
 *   +0x148 float pathystart  读（0x1942d4）与写（0x194458 / 0x194490 / 0x194498）
 *   ★ +0x144/+0x148 是**浮点**：vldr/vmla/vstr 直接当 s 寄存器用。ctor 卡把它们猜成
 *     「疑似 CPath* / CTimeline*」是错的；Dump 卡（§4）把它们叫 i_pathxstart / i_pathystart，
 *     Assign_Path 0x1940e0..0x1940ec 更是直接把 this->x / this->y 的 32 位模式拷进去
 *     （ldr r2,[r4,#0xb4]; ldr r3,[r4,#0xb8]; str r2,[r4,#0x144]; str r3,[r4,#0x148]）。
 *     语义：路径坐标系的世界原点，Adapt_Path 用它当基准，endaction==continue 时把
 *     「末点-首点」的旋转位移累加进去，从而让环状路径在接缝处连续。
 *
 */
/* @0x19411c push {r4, r5, r6, r7, r8, r9, lr} —— 帧：7 核寄存器 28 B + 4 个 d 寄存器 32 B + 局部 28 B */
/* @0x194120 vpush {d8, d9, d10, d11} */
/* @0x194124 mov r4, r0 */
/* @0x194128 ldr r0, [r0, #0x128] —— r0 = path_index(+0x128) */
/* @0x19412c sub sp, sp, #28 */
/* @0x194130 cmp r0, #0 */
/* @0x194134 blt 0x194210 <_ZN9CInstance10Adapt_PathEv+0xf4> —— path_index < 0 ⇒ 直接返回 0 */
/* @0x194138 bl 0x1a815c <_Z9Path_Datai> —— Path_Data(path_index) → CPath*（r6） */
/* @0x19413c subs r6, r0, #0 */
/* @0x194140 beq 0x194210 <_ZN9CInstance10Adapt_PathEv+0xf4> —— 空指针 ⇒ 返回 0 */
/* @0x194144 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv> —— CPath::GetPathLength() = CPath+0x24（0x1a7ab8 只有两条指令：ldr r0,[r0,#0x24] / bx lr） */
/* @0x194148 vmov s14, r0 */
/* @0x19414c vcmpe.f32 s14, #0 */
/* @0x194150 vmrs APSR_nzcv, fpscr */
/* @0x194154 bls 0x194210 <_ZN9CInstance10Adapt_PathEv+0xf4> —— 长度 <= 0 ⇒ 返回 0（除零闸） */
/* @0x194158 vldr s17, [r4, #316] —— s17 = path_orientation(+0x13c) */
/* @0x19415c vldr s15, [pc, #828] —— 池 0x1944a0 = 0x40490fdb = π */
/* @0x194160 vmul.f32 s17, s17, s15 */
/* @0x194164 add r8, sp, #16 */
/* @0x194168 add r9, sp, #20 */
/* @0x19416c ldr r1, [r4, #0x12c] */
/* @0x194170 mov r2, r8 */
/* @0x194174 mov r0, r6 */
/* @0x194178 mov r3, r9 */
/* @0x19417c add r7, sp, #12 */
/* @0x194180 str r7, [sp] */
/* @0x194184 vldr s15, [pc, #792] —— 池 0x1944a4 = 0x43340000 = 180.0f ⇒ s17 = orientation*π/180（度→弧度） */
/* @0x194188 vdiv.f32 s17, s17, s15 */
/* @0x19418c bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> —— CPath::GetPosition(pos, &x@sp+16, &y@sp+20, &pt3@sp+12) */
/* @0x194190 vldr s13, [r4, #312] —— s13 = path_scale(+0x138) */
/* @0x194194 vldr s15, [pc, #780] —— 池 0x1944a8 = 0x42c80000 = 100.0f */
/* @0x194198 vldr s14, [sp, #12] */
/* @0x19419c mov r0, r6 */
/* @0x1941a0 vldr s16, [r4, #308] —— s16 = path_speed(+0x134) */
/* @0x1941a4 vldr s18, [r4, #300] —— s18 = path_position(+0x12c) */
/* @0x1941a8 vmul.f32 s15, s13, s15 —— s15 = path_scale * 100 */
/* @0x1941ac vdiv.f32 s15, s14, s15 —— s15 = pt3 / (path_scale*100) */
/* @0x1941b0 vmul.f32 s16, s15, s16 —— s16 = s15 * path_speed */
/* @0x1941b4 vstr s15, [sp, #12] */
/* @0x1941b8 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv> */
/* @0x1941bc vmov.f32 s14, #1.000000e+00 */
/* @0x1941c0 vmov s15, r0 */
/* @0x1941c4 vdiv.f32 s16, s16, s15 —— s16 = s16 / pathlen */
/* @0x1941c8 vadd.f32 s16, s18, s16 —— s16 = path_position + 步长 */
/* @0x1941cc vcmpe.f32 s16, s14 */
/* @0x1941d0 vstr s16, [r4, #300] —— path_position 先写回 +0x12c（越界与否都先写） */
/* @0x1941d4 vmrs APSR_nzcv, fpscr */
/* @0x1941d8 blt 0x194224 <_ZN9CInstance10Adapt_PathEv+0x108> —— new_pos < 1.0 ⇒ 0x194224 继续判下界；否则落入 endaction 分派 */
/* @0x1941dc vldr s15, [r4, #308] —— endaction 分派头：r3 = path_endaction(+0x140) */
/* @0x1941e0 vcmp.f32 s15, #0 */
/* @0x1941e4 ldr r3, [r4, #0x140] */
/* @0x1941e8 vmrs APSR_nzcv, fpscr */
/* @0x1941ec moveq r5, #0 —— r5 = (path_speed != 0)，这是唯一的非 0 返回值来源 */
/* @0x1941f0 movne r5, #1 */
/* @0x1941f4 cmp r3, #3 —— cmp r3,#3 + addls ⇒ 4 项跳表，>=4 落到 0x194210 返回 0 */
/* @0x1941f8 addls pc, pc, r3, lsl #2 */
/* @0x1941fc b 0x194258 <_ZN9CInstance10Adapt_PathEv+0x13c> */
/* @0x194200 b 0x19423c <_ZN9CInstance10Adapt_PathEv+0x120> —— endaction 0（stop）→ 0x19423c */
/* @0x194204 b 0x194384 <_ZN9CInstance10Adapt_PathEv+0x268> —— endaction 1（restart）→ 0x194384 */
/* @0x194208 b 0x1943a0 <_ZN9CInstance10Adapt_PathEv+0x284> —— endaction 2（continue）→ 0x1943a0 */
/* @0x19420c b 0x19434c <_ZN9CInstance10Adapt_PathEv+0x230> —— endaction 3（reverse）→ 0x19434c */
/* @0x194210 mov r5, #0 —— endaction >= 4 ⇒ 返回 0 */
/* @0x194214 mov r0, r5 */
/* @0x194218 add sp, sp, #28 */
/* @0x19421c vpop {d8, d9, d10, d11} */
/* @0x194220 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x194224 vcmpe.f32 s16, #0 —— new_pos <= 0 也进同一个 endaction 分派（bls 覆盖负与零） */
/* @0x194228 vmrs APSR_nzcv, fpscr */
/* @0x19422c bls 0x1941dc <_ZN9CInstance10Adapt_PathEv+0xc0> */
/* @0x194230 vmov r0, s17 */
/* @0x194234 mov r5, #0 */
/* @0x194238 b 0x19426c <_ZN9CInstance10Adapt_PathEv+0x150> */
/* @0x19423c vcmpe.f32 s15, #0 —— stop 分支：先看 path_speed 符号 */
/* @0x194240 vldr s15, [pc, #612] —— 池 0x1944ac = 0.0f */
/* @0x194244 vmrs APSR_nzcv, fpscr */
/* @0x194248 bmi 0x194460 <_ZN9CInstance10Adapt_PathEv+0x344> —— path_speed < 0 ⇒ 0x194460（停在起点） */
/* @0x19424c cmp r5, #0 */
/* @0x194250 vmoveq r0, s17 —— path_speed == 0 ⇒ 原地继续（r0 = 旋转角） */
/* @0x194254 beq 0x19426c <_ZN9CInstance10Adapt_PathEv+0x150> */
/* @0x194258 vmov r0, s17 —— 正向 stop：path_index = -1、path_position = 1.0f */
/* @0x19425c mvn r3, #0 */
/* @0x194260 vmov.f32 s16, #1.000000e+00 */
/* @0x194264 str r3, [r4, #0x128] —— path_index = -1（脱离路径） */
/* @0x194268 vstr s16, [r4, #300] */
/* @0x19426c bl 0xb658c <cosf@plt> —— 主循环体：cosf(θ) */
/* @0x194270 vmov s18, r0 */
/* @0x194274 vmov r0, s17 */
/* @0x194278 bl 0xb6580 <sinf@plt> —— sinf(θ) */
/* @0x19427c vmov s19, r0 */
/* @0x194280 mov r2, r8 */
/* @0x194284 mov r3, r9 */
/* @0x194288 mov r0, r6 */
/* @0x19428c vmov r1, s16 */
/* @0x194290 str r7, [sp] */
/* @0x194294 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> —— 用心位置再取一次点：GetPosition(new_pos, &px, &py, &dummy) */
/* @0x194298 mov r0, r6 */
/* @0x19429c mov r1, #0 */
/* @0x1942a0 vldr s16, [sp, #16] */
/* @0x1942a4 bl 0x1a7598 <_ZN5CPath9XPositionEf> —— CPath::XPosition(0.0f) = 路径起点 x */
/* @0x1942a8 mov r1, #0 */
/* @0x1942ac vldr s20, [sp, #20] */
/* @0x1942b0 vmov s15, r0 */
/* @0x1942b4 mov r0, r6 */
/* @0x1942b8 vsub.f32 s16, s16, s15 —— dx = px - X(0) */
/* @0x1942bc vstr s16, [sp, #16] */
/* @0x1942c0 bl 0x1a75c0 <_ZN5CPath9YPositionEf> —— CPath::YPosition(0.0f) = 路径起点 y */
/* @0x1942c4 vldr s11, [sp, #16] */
/* @0x1942c8 vmul.f32 s15, s11, s19 */
/* @0x1942cc vldr s12, [r4, #312] —— s12 = path_scale(+0x138) */
/* @0x1942d0 vldr s17, [r4, #324] —— s17 = pathxstart(+0x144) */
/* @0x1942d4 vldr s16, [r4, #328] —— s16 = pathystart(+0x148) */
/* @0x1942d8 vldr s10, [r4, #180] —— s10 = this->x(+0xb4)（位移前的旧值，后面算 hspeed 用） */
/* @0x1942dc vmov s14, r0 */
/* @0x1942e0 mov r0, r4 */
/* @0x1942e4 vsub.f32 s13, s20, s14 —— dy = py - Y(0) */
/* @0x1942e8 vmul.f32 s14, s13, s19 */
/* @0x1942ec vstr s13, [sp, #20] */
/* @0x1942f0 vmla.f32 s14, s11, s18 —— s14 = dy*sin + dx*cos（即 R(-θ) 的 x 分量） */
/* @0x1942f4 vnmls.f32 s15, s13, s18 —— s15 = dx*sin - dy*cos（y 分量） */
/* @0x1942f8 vmla.f32 s17, s12, s14 —— nx = pathxstart + path_scale*s14 */
/* @0x1942fc vmla.f32 s16, s12, s15 —— ny = pathystart + path_scale*s15 */
/* @0x194300 vsub.f32 s10, s17, s10 —— hspeed 实参 = nx - this->x */
/* @0x194304 vmov r1, s10 */
/* @0x194308 bl 0x1930f4 <_ZN9CInstance9SetHspeedEf> —— SetHspeed(nx - x) */
/* @0x19430c vldr s15, [r4, #184] */
/* @0x194310 vsub.f32 s15, s16, s15 —— vspeed 实参 = ny - this->y */
/* @0x194314 mov r0, r4 */
/* @0x194318 vmov r1, s15 */
/* @0x19431c bl 0x193114 <_ZN9CInstance9SetVspeedEf> —— SetVspeed(ny - y) */
/* @0x194320 mov r0, r4 */
/* @0x194324 mov r1, #0 */
/* @0x194328 bl 0x1930d4 <_ZN9CInstance8SetSpeedEf> —— SetSpeed(0) */
/* @0x19432c mov r0, r4 */
/* @0x194330 vmov r1, s17 */
/* @0x194334 vmov r2, s16 */
/* @0x194338 bl 0x193e7c <_ZN9CInstance11SetPositionEff> —— SetPosition(nx, ny) */
/* @0x19433c mov r0, r5 —— 返回 r5 */
/* @0x194340 add sp, sp, #28 */
/* @0x194344 vpop {d8, d9, d10, d11} */
/* @0x194348 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x19434c vcmpe.f32 s16, #0 —— reverse：pos >= 0 ⇒ pos = 2 - pos、path_speed = -|path_speed| */
/* @0x194350 vmrs APSR_nzcv, fpscr */
/* @0x194354 vmovpl.f32 s14, #2.000000e+00 */
/* @0x194358 vmovmi r0, s17 */
/* @0x19435c vmovpl r0, s17 */
/* @0x194360 vsubpl.f32 s16, s14, s16 —— pos' = 2.0 - pos */
/* @0x194364 vabspl.f32 s15, s15 —— s15 = |path_speed| */
/* @0x194368 vstrpl s16, [r4, #300] */
/* @0x19436c vnegmi.f32 s16, s16 —— pos < 0 ⇒ pos' = -pos（vmovmi 版） */
/* @0x194370 vabsmi.f32 s15, s15 */
/* @0x194374 vstrmi s16, [r4, #300] */
/* @0x194378 vnegpl.f32 s15, s15 —— ↑ 两条路都写 path_speed(+0x134) = ∓|speed| */
/* @0x19437c vstr s15, [r4, #308] */
/* @0x194380 b 0x19426c <_ZN9CInstance10Adapt_PathEv+0x150> */
/* @0x194384 vmov.f32 s15, #1.000000e+00 —— restart：把 pos 折回 [0,1)（>=1 减 1，<0 加 1） */
/* @0x194388 vmov r0, s17 */
/* @0x19438c vcmpe.f32 s16, #0 */
/* @0x194390 vmrs APSR_nzcv, fpscr */
/* @0x194394 vaddmi.f32 s16, s16, s15 —— pos < 0 ⇒ pos += 1 */
/* @0x194398 vsubpl.f32 s16, s16, s15 —— pos >= 0 ⇒ pos -= 1 */
/* @0x19439c b 0x194268 <_ZN9CInstance10Adapt_PathEv+0x14c> */
/* @0x1943a0 mov r1, #1065353216 —— continue：X(1.0f) = 路径末点 x */
/* @0x1943a4 mov r0, r6 */
/* @0x1943a8 bl 0x1a7598 <_ZN5CPath9XPositionEf> */
/* @0x1943ac mov r1, #0 */
/* @0x1943b0 vmov s16, r0 */
/* @0x1943b4 mov r0, r6 */
/* @0x1943b8 bl 0x1a7598 <_ZN5CPath9XPositionEf> —— X(0.0f) = 起点 x ⇒ s16 = 末点-起点 */
/* @0x1943bc mov r1, #1065353216 */
/* @0x1943c0 vmov s15, r0 */
/* @0x1943c4 mov r0, r6 */
/* @0x1943c8 vsub.f32 s16, s16, s15 */
/* @0x1943cc vstr s16, [sp, #16] —— [sp+16] = dx（末点-起点） */
/* @0x1943d0 bl 0x1a75c0 <_ZN5CPath9YPositionEf> —— Y(1.0f) */
/* @0x1943d4 mov r1, #0 */
/* @0x1943d8 vmov s20, r0 */
/* @0x1943dc mov r0, r6 */
/* @0x1943e0 bl 0x1a75c0 <_ZN5CPath9YPositionEf> —— Y(0.0f) ⇒ s20 = 末点-起点 */
/* @0x1943e4 vldr s21, [r4, #312] —— s21 = path_scale */
/* @0x1943e8 vmov s14, r0 */
/* @0x1943ec vmov r0, s17 */
/* @0x1943f0 vsub.f32 s20, s20, s14 */
/* @0x1943f4 vstr s20, [sp, #20] */
/* @0x1943f8 bl 0xb658c <cosf@plt> */
/* @0x1943fc vldr s22, [sp, #16] */
/* @0x194400 vmov s18, r0 */
/* @0x194404 vmov r0, s17 */
/* @0x194408 bl 0xb6580 <sinf@plt> */
/* @0x19440c vldr s13, [r4, #300] */
/* @0x194410 vcmpe.f32 s13, #0 */
/* @0x194414 vmrs APSR_nzcv, fpscr */
/* @0x194418 vmov s19, r0 */
/* @0x19441c vmul.f32 s14, s20, s19 —— s14 = dy*sin */
/* @0x194420 vmul.f32 s15, s22, s19 —— s15 = dx*sin */
/* @0x194424 vmla.f32 s14, s18, s22 —— s14 = dy*sin + dx*cos */
/* @0x194428 vnmls.f32 s15, s20, s18 —— s15 = dx*sin - dy*cos */
/* @0x19442c vmul.f32 s14, s21, s14 —— s14 *= path_scale */
/* @0x194430 vmul.f32 s15, s21, s15 —— s15 *= path_scale */
/* @0x194434 bmi 0x194478 <_ZN9CInstance10Adapt_PathEv+0x35c> —— path_position < 0 ⇒ 走 0x194478（减而不是加） */
/* @0x194438 vldr s11, [r4, #324] */
/* @0x19443c vldr s12, [r4, #328] */
/* @0x194440 vmov.f32 s16, #1.000000e+00 */
/* @0x194444 vadd.f32 s14, s11, s14 —— pathxstart += 位移（正向环） */
/* @0x194448 vsub.f32 s16, s13, s16 —— path_position -= 1.0f */
/* @0x19444c vstr s14, [r4, #324] */
/* @0x194450 vadd.f32 s15, s12, s15 */
/* @0x194454 vstr s16, [r4, #300] */
/* @0x194458 vstr s15, [r4, #328] —— pathystart += 位移 */
/* @0x19445c b 0x194280 <_ZN9CInstance10Adapt_PathEv+0x164> */
/* @0x194460 mvn r3, #0 —— 反向 stop：path_position = 0.0f（池里的 0.0f 在 0x194240 已装入 s15） */
/* @0x194464 vstr s15, [r4, #300] */
/* @0x194468 vmov r0, s17 */
/* @0x19446c str r3, [r4, #0x128] —— path_index = -1 */
/* @0x194470 vmov.f32 s16, s15 */
/* @0x194474 b 0x19426c <_ZN9CInstance10Adapt_PathEv+0x150> */
/* @0x194478 vmov.f32 s16, #1.000000e+00 —— 反向环：pathxstart -= 位移 */
/* @0x19447c vldr s11, [r4, #324] */
/* @0x194480 vldr s12, [r4, #328] */
/* @0x194484 vsub.f32 s14, s11, s14 */
/* @0x194488 vadd.f32 s16, s13, s16 —— path_position += 1.0f */
/* @0x19448c vstr s14, [r4, #324] */
/* @0x194490 vsub.f32 s15, s12, s15 */
/* @0x194494 vstr s16, [r4, #300] */
/* @0x194498 vstr s15, [r4, #328] */
/* @0x19449c b 0x194280 <_ZN9CInstance10Adapt_PathEv+0x164> —— 回到主循环体 0x194280（用新 pos 重新取点） */
/* @0x1944a0 ldrdmi r0, r1, [r9], #-251 —— 池字 0x40490fdb = 3.14159274f（π），非指令 */
/* @0x1944a4 teqmi r4, #0 —— 池字 0x43340000 = 180.0f，非指令 */
/* @0x1944a8 sbcmi r0, r8, #0 —— 池字 0x42c80000 = 100.0f，非指令 */
/* @0x1944ac andeq r0, r0, r0 —— 池字 0x00000000 = 0.0f，非指令 */
/* ══ §4 CInstance::Dump(tagIConsole&) 0x19363c ══════════════════════════════
 * @func 0x19363c 0x193e7c size 2112  528 条（476 指令 + 末 52 字 0x193dac..0x193e78 为 literal pool；
 *       0x193e7c 是下一个符号 CInstance::SetPosition 的入口）
 * 级别: 正文（528/528 逐条落锚。61 次打印的**顺序与字段**由 52 个池字逐字解出的 61 条格式串
 *       直接给出（不是猜的字段名，是原件自带的字符串常量）；变量表循环的结构与 12 B 项布局、
 *       两条跳过规则、tag==0x00FFFFFF 的哨兵全部钉死）
 * 符号: _ZN9CInstance4DumpER11tagIConsole → void CInstance::Dump(tagIConsole& console)
 * 位置: CInstance::SetPathSpeed 0x193634（size 8）之后、CInstance::SetPosition 0x193e7c 之前
 * 调用点: **零**。全 .text（0..0x3a5a1c）无 bl/blx 指向 0x19363c；它是导出符号但没有链接期调用者，
 *         只能经 vtable/调试路径进入（与 SetID 0x1958cc 同病，见 §1 头与 open）
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   把实例的 61 个字段按**固定顺序**逐行打印到 tagIConsole（实例 id → 精灵/图像组 → 掩码 →
 *   depth → precise → 位置组 → 运动学 → bbox 四边 → visible/solid/persistent → objindex →
 *   12 个 alarm → marked/deactivated → path 组 → timeline 组），最后再把 +0x60 的变量表
 *   逐项打成 "名字 = 值"。整段打印零分支，只有末尾的变量表循环有判空与跳过。
 *
 * ── console 契约（本节唯一的外部依赖）────────────────────────────────────────
 *   tagIConsole& 的第 1 个字是 vtable；唯一被调的槽是 [+0xc]，签名形如
 *   int printf(char const* fmt, ...)：float 走 vcvt.f64 后以 r2/r3 一对核寄存器传
 *   （0x1936bc ec532b16 vmov r2,r3,d6 这种成对传法，共 25 处），int/指针直接放 r2。
 *   调用形如 `ldr r3,[r10]; ldr r12,[r3,#0xc]; blx r12`，r0 恒 = console，r1 恒 = 格式串。
 *
 * ── 打印清单（54 行固定 + 12 行 alarm + 变量表）────────────────────────────────
 *   行  格式串（.rodata 原文，去掉对齐空格）            取值
 *    1  i_id                   = %d                    +0x078
 *    2  i_spriteindex          = %d(%s)                +0x08c + Sprite_Name(0x8c)
 *    3  i_imageindex           = %f                    +0x090
 *    4  i_imagespeed           = %f                    +0x094
 *    5  i_imagescalex          = %f                    +0x098
 *    6  i_imagescaley          = %f                    +0x09c
 *    7  i_imageangle           = %f                    +0x0a0
 *    8  i_imagealpha           = %f                    +0x0a4
 *    9  i_imageblend           = %d                    +0x0a8
 *   10  i_maskindex            = %d                    +0x0ac
 *   11  i_depth                = %f                    +0x180
 *   12  i_precise              = %d                    ldrb +0x0b0
 *   13  i_x                    = %f                    +0x0b4
 *   14  i_y                    = %f                    +0x0b8
 *   15  i_xstart               = %f                    +0x0bc
 *   16  i_ystart               = %f                    +0x0c0
 *   17  i_xprevious            = %f                    +0x0c4
 *   18  i_yprevious            = %f                    +0x0c8
 *   19  i_direction            = %f                    +0x0cc
 *   20  i_speed                = %f                    +0x0d0
 *   21  i_friction             = %f                    +0x0d4
 *   22  i_gravitydir           = %f                    +0x0d8
 *   23  i_gravity              = %f                    +0x0dc
 *   24  i_hspeed               = %f                    +0x0e0
 *   25  i_vspeed               = %f                    +0x0e4
 *   26  i_bbox.left            = %d                    +0x0e8
 *   27  i_bbox.right           = %d                    +0x0f0
 *   28  i_bbox.top             = %d                    +0x0ec
 *   29  i_bbox.bottom          = %d                    +0x0f4
 *   30  i_visible              = %d                    ldrb +0x065
 *   31  i_solid                = %d                    ldrb +0x066
 *   32  i_persistent           = %d                    ldrb +0x067
 *   33  i_objindex             = %d                    +0x07c + Object_Name(0x7c)
 *  34..45  i_timer[%d]         = %d                    +0x0f8 + 4*i，i=0..11
 *   46  i_marked               = %d                    ldrb +0x068
 *   47  i_deactivated          = %d                    ldrb +0x069
 *   48  i_pathindex            = %d                    +0x128
 *   49  i_pathposition         = %f                    +0x12c
 *   50  i_pathpositionprevious = %f                    +0x130
 *   51  i_pathspeed            = %f                    +0x134
 *   52  i_pathscale            = %f                    +0x138
 *   53  i_pathorientation      = %f                    +0x13c
 *   54  i_pathend              = %d                    +0x140
 *   55  i_pathxstart           = %f                    +0x144
 *   56  i_pathystart           = %f                    +0x148
 *   57  i_timelineindex        = %d                    +0x14c
 *   58  i_timelineposition     = %f                    +0x154
 *   59  i_timelinespeed        = %f                    +0x158
 *   60  i_timelinerunning      = %d                    ldrb +0x15c
 *   61  i_timelineloop         = %d                    ldrb +0x15d
 *   62+ 每个变量                  %s = <值>\n             见下
 *
 * ── 本卡借 Dump 钉死的三件事（别的卡只能推、这里能读）──────────────────────────
 *   A. bbox 就在 +0xe8，成员名自带：+0xe8=left、+0xec=top、+0xf0=right、+0xf4=bottom
 *      （打印顺序是 left→right→top→bottom，与结构体顺序无关）。§1 的四道闸、§2 的四道
 *      +1 闸、Compute_BoundingBox 卡的写法三方一致。
 *   B. +0x144/+0x148 的字段名是 **i_pathxstart / i_pathystart**，且按 %f 打印 ⇒ 浮点。
 *      ctor 卡「疑似 CPath* / CTimeline*」的猜测到此作废（§3 另有算术证据）。
 *   C. +0xb0 的字段名是 **i_precise**，由 Compute_BoundingBox 从 spr+0x30 拷来
 *      （见该卡 0x192570 / 0x1927c0 / 0x1928b8）；§2 正是拿它当像素级判碰的闸。
 *
 * ── Dump **不**打印的字段（受本卡约束：这 20 个偏移的语义不能靠 Dump 命名）──────────
 *   +0x044（实例表槽号）、+0x048、+0x06a/+0x06b/+0x06c、+0x070..+0x077（创建计数 8 B）、
 *   +0x080（CObjectGM*）、+0x084（CPhysicsObject*）、+0x088（CSkeletonInstance*）、
 *   +0x150（timeline 区未定槽）、+0x160/+0x164/+0x168、+0x16c、+0x170（layer）、+0x174、
 *   +0x184、+0x188，以及 0x18c 起的三段侵入式链表（本就是引擎内部结构，不是「属性」）。
 *
 * ── 变量表循环（+0x60）──────────────────────────────────────────────────────
 *   容器（this->[0x60]）布局：+0x00 int count、+0x10 Entry* base；Entry 12 B：
 *   {+0x00 int id, +0x04 RValue* value, +0x08 int kind}。
 *     for (i = 0; i < count; i++) {
 *        Entry* e = base + i;
 *        if (e->kind <= 0) continue;                      // 0x193d34 ble
 *        if ((e->value->tag & 0x00FFFFFF) == 0x00FFFFFF) continue;   // 0x193d3c..0x193d4c
 *        name = Code_Variable_Find_Name(0, -1, e->id + 100000);      // 0x193d60
 *        Printf("%s = ", name); OutputValue(console, e->value); Printf("\n");
 *     }
 *   三点值得记：① 分派键是 **id+100000**（id>=100000 = 作用域变量域，见 Code_Variable_Find_Name 卡
 *   的 99999 分界）；② name 形参传 0、type 传 -1，说明这一路只按 id 查名，不按名字作用域搜；
 *   ③ tag 0x00FFFFFF 是「空值」哨兵，与 ctor 的 image_blend/基类 +0x58 用同一个值不是巧合。
 *
 */
/* @0x19363c ldr r3, [r1] —— 入口第一件事就是取 console 的 vtable（r1 = tagIConsole&） */
/* @0x193640 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x193644 mov r10, r1 */
/* @0x193648 mov r6, r0 */
/* @0x19364c mov r0, r1 */
/* @0x193650 ldr r1, [pc, #0x754] —— 格式串 "i_id                   = %d" ← +0x78 int id */
/* @0x193654 mov r5, r6 */
/* @0x193658 ldr r2, [r6, #0x78] —— r2 = this->id(+0x78) */
/* @0x19365c mov r4, #0 */
/* @0x193660 add r1, pc, r1 */
/* @0x193664 ldr r3, [r3, #0xc] */
/* @0x193668 blx r3 —— console->vt[+0xc]：printf 风格，此签名是全卡唯一的外部接口 */
/* @0x19366c ldr r8, [r6, #0x8c] —— r8 = sprite_index(+0x8c)，同时作为 Sprite_Name 的实参 */
/* @0x193670 ldr r3, [r10] */
/* @0x193674 ldr r7, [pc, #0x734] —— r7 预装 alarm 行的格式串（池 0x193db0 = 0x001b93fc，定位于 add 0x19368c ⇒ 0x34ca90） */
/* @0x193678 mov r0, r8 */
/* @0x19367c ldr r9, [r3, #0xc] */
/* @0x193680 bl 0x1eeee0 <_Z11Sprite_Namei> —— Sprite_Name(0x8c) → %s 那一栏 */
/* @0x193684 ldr r1, [pc, #0x728] —— 格式串 "i_spriteindex          = %d(%s)" ← +0x8c sprite_index + Sprite_Name(+0x8c) */
/* @0x193688 mov r2, r8 */
/* @0x19368c add r7, pc, r7 */
/* @0x193690 add r1, pc, r1 */
/* @0x193694 mov r3, r0 */
/* @0x193698 mov r0, r10 */
/* @0x19369c blx r9 */
/* @0x1936a0 vldr s15, [r6, #144] —— float 一律 vcvt.f64 后以 r2/r3 传（变参 printf 的 double 提升） */
/* @0x1936a4 vcvt.f64.f32 d6, s15 */
/* @0x1936a8 ldr r12, [r10] */
/* @0x1936ac ldr r1, [pc, #0x704] —— 格式串 "i_imageindex           = %f" ← +0x90 image_index */
/* @0x1936b0 mov r0, r10 */
/* @0x1936b4 add r1, pc, r1 */
/* @0x1936b8 ldr r12, [r12, #0xc] */
/* @0x1936bc vmov r2, r3, d6 */
/* @0x1936c0 blx r12 */
/* @0x1936c4 vldr s15, [r6, #148] */
/* @0x1936c8 vcvt.f64.f32 d6, s15 */
/* @0x1936cc ldr r3, [r10] */
/* @0x1936d0 ldr r1, [pc, #0x6e4] —— 格式串 "i_imagespeed           = %f" ← +0x94 image_speed */
/* @0x1936d4 mov r0, r10 */
/* @0x1936d8 ldr r12, [r3, #0xc] */
/* @0x1936dc add r1, pc, r1 */
/* @0x1936e0 vmov r2, r3, d6 */
/* @0x1936e4 blx r12 */
/* @0x1936e8 vldr s15, [r6, #152] */
/* @0x1936ec vcvt.f64.f32 d6, s15 */
/* @0x1936f0 ldr r3, [r10] */
/* @0x1936f4 ldr r1, [pc, #0x6c4] —— 格式串 "i_imagescalex          = %f" ← +0x98 image_xscale */
/* @0x1936f8 mov r0, r10 */
/* @0x1936fc ldr r12, [r3, #0xc] */
/* @0x193700 add r1, pc, r1 */
/* @0x193704 vmov r2, r3, d6 */
/* @0x193708 blx r12 */
/* @0x19370c vldr s15, [r6, #156] */
/* @0x193710 vcvt.f64.f32 d6, s15 */
/* @0x193714 ldr r3, [r10] */
/* @0x193718 ldr r1, [pc, #0x6a4] —— 格式串 "i_imagescaley          = %f" ← +0x9c image_yscale */
/* @0x19371c mov r0, r10 */
/* @0x193720 ldr r12, [r3, #0xc] */
/* @0x193724 add r1, pc, r1 */
/* @0x193728 vmov r2, r3, d6 */
/* @0x19372c blx r12 */
/* @0x193730 vldr s15, [r6, #160] */
/* @0x193734 vcvt.f64.f32 d6, s15 */
/* @0x193738 ldr r3, [r10] */
/* @0x19373c ldr r1, [pc, #0x684] —— 格式串 "i_imageangle           = %f" ← +0xa0 image_angle */
/* @0x193740 mov r0, r10 */
/* @0x193744 ldr r12, [r3, #0xc] */
/* @0x193748 add r1, pc, r1 */
/* @0x19374c vmov r2, r3, d6 */
/* @0x193750 blx r12 */
/* @0x193754 vldr s15, [r6, #164] */
/* @0x193758 vcvt.f64.f32 d6, s15 */
/* @0x19375c ldr r3, [r10] */
/* @0x193760 ldr r1, [pc, #0x664] —— 格式串 "i_imagealpha           = %f" ← +0xa4 image_alpha */
/* @0x193764 mov r0, r10 */
/* @0x193768 ldr r12, [r3, #0xc] */
/* @0x19376c add r1, pc, r1 */
/* @0x193770 vmov r2, r3, d6 */
/* @0x193774 blx r12 */
/* @0x193778 ldr r3, [r10] */
/* @0x19377c ldr r1, [pc, #0x64c] —— 格式串 "i_imageblend           = %d" ← +0xa8 image_blend（int，0x00FFFFFF） */
/* @0x193780 mov r0, r10 */
/* @0x193784 ldr r2, [r6, #0xa8] */
/* @0x193788 add r1, pc, r1 */
/* @0x19378c ldr r3, [r3, #0xc] */
/* @0x193790 blx r3 */
/* @0x193794 ldr r3, [r10] */
/* @0x193798 ldr r1, [pc, #0x634] —— 格式串 "i_maskindex            = %d" ← +0xac mask_index */
/* @0x19379c mov r0, r10 */
/* @0x1937a0 ldr r2, [r6, #0xac] */
/* @0x1937a4 add r1, pc, r1 */
/* @0x1937a8 ldr r3, [r3, #0xc] */
/* @0x1937ac blx r3 */
/* @0x1937b0 vldr s15, [r6, #384] —— 先印 depth(+0x180) */
/* @0x1937b4 vcvt.f64.f32 d6, s15 */
/* @0x1937b8 ldr r12, [r10] */
/* @0x1937bc ldr r1, [pc, #0x614] —— 格式串 "i_depth                = %f" ← +0x180 depth */
/* @0x1937c0 mov r0, r10 */
/* @0x1937c4 ldr r12, [r12, #0xc] */
/* @0x1937c8 add r1, pc, r1 */
/* @0x1937cc vmov r2, r3, d6 */
/* @0x1937d0 blx r12 */
/* @0x1937d4 ldr r3, [r10] */
/* @0x1937d8 ldr r1, [pc, #0x5fc] —— 格式串 "i_precise              = %d" ← ldrb +0xb0 precise */
/* @0x1937dc mov r0, r10 */
/* @0x1937e0 ldrb r2, [r6, #0xb0] —— 再印 precise(+0xb0，字节) */
/* @0x1937e4 add r1, pc, r1 */
/* @0x1937e8 ldr r3, [r3, #0xc] */
/* @0x1937ec blx r3 */
/* @0x1937f0 vldr s15, [r6, #180] */
/* @0x1937f4 vcvt.f64.f32 d6, s15 */
/* @0x1937f8 ldr r12, [r10] */
/* @0x1937fc ldr r1, [pc, #0x5dc] —— 格式串 "i_x                    = %f" ← +0xb4 x */
/* @0x193800 mov r0, r10 */
/* @0x193804 add r1, pc, r1 */
/* @0x193808 ldr r12, [r12, #0xc] */
/* @0x19380c vmov r2, r3, d6 */
/* @0x193810 blx r12 */
/* @0x193814 vldr s15, [r6, #184] */
/* @0x193818 vcvt.f64.f32 d6, s15 */
/* @0x19381c ldr r3, [r10] */
/* @0x193820 ldr r1, [pc, #0x5bc] —— 格式串 "i_y                    = %f" ← +0xb8 y */
/* @0x193824 mov r0, r10 */
/* @0x193828 ldr r12, [r3, #0xc] */
/* @0x19382c add r1, pc, r1 */
/* @0x193830 vmov r2, r3, d6 */
/* @0x193834 blx r12 */
/* @0x193838 vldr s15, [r6, #188] */
/* @0x19383c vcvt.f64.f32 d6, s15 */
/* @0x193840 ldr r3, [r10] */
/* @0x193844 ldr r1, [pc, #0x59c] —— 格式串 "i_xstart               = %f" ← +0xbc xstart */
/* @0x193848 mov r0, r10 */
/* @0x19384c ldr r12, [r3, #0xc] */
/* @0x193850 add r1, pc, r1 */
/* @0x193854 vmov r2, r3, d6 */
/* @0x193858 blx r12 */
/* @0x19385c vldr s15, [r6, #192] */
/* @0x193860 vcvt.f64.f32 d6, s15 */
/* @0x193864 ldr r3, [r10] */
/* @0x193868 ldr r1, [pc, #0x57c] —— 格式串 "i_ystart               = %f" ← +0xc0 ystart */
/* @0x19386c mov r0, r10 */
/* @0x193870 ldr r12, [r3, #0xc] */
/* @0x193874 add r1, pc, r1 */
/* @0x193878 vmov r2, r3, d6 */
/* @0x19387c blx r12 */
/* @0x193880 vldr s15, [r6, #196] */
/* @0x193884 vcvt.f64.f32 d6, s15 */
/* @0x193888 ldr r3, [r10] */
/* @0x19388c ldr r1, [pc, #0x55c] —— 格式串 "i_xprevious            = %f" ← +0xc4 xprevious */
/* @0x193890 mov r0, r10 */
/* @0x193894 ldr r12, [r3, #0xc] */
/* @0x193898 add r1, pc, r1 */
/* @0x19389c vmov r2, r3, d6 */
/* @0x1938a0 blx r12 */
/* @0x1938a4 vldr s15, [r6, #200] */
/* @0x1938a8 vcvt.f64.f32 d6, s15 */
/* @0x1938ac ldr r3, [r10] */
/* @0x1938b0 ldr r1, [pc, #0x53c] —— 格式串 "i_yprevious            = %f" ← +0xc8 yprevious */
/* @0x1938b4 mov r0, r10 */
/* @0x1938b8 ldr r12, [r3, #0xc] */
/* @0x1938bc add r1, pc, r1 */
/* @0x1938c0 vmov r2, r3, d6 */
/* @0x1938c4 blx r12 */
/* @0x1938c8 vldr s15, [r6, #204] */
/* @0x1938cc vcvt.f64.f32 d6, s15 */
/* @0x1938d0 ldr r3, [r10] */
/* @0x1938d4 ldr r1, [pc, #0x51c] —— 格式串 "i_direction            = %f" ← +0xcc direction */
/* @0x1938d8 mov r0, r10 */
/* @0x1938dc ldr r12, [r3, #0xc] */
/* @0x1938e0 add r1, pc, r1 */
/* @0x1938e4 vmov r2, r3, d6 */
/* @0x1938e8 blx r12 */
/* @0x1938ec vldr s15, [r6, #208] */
/* @0x1938f0 vcvt.f64.f32 d6, s15 */
/* @0x1938f4 ldr r3, [r10] */
/* @0x1938f8 ldr r1, [pc, #0x4fc] —— 格式串 "i_speed                = %f" ← +0xd0 speed */
/* @0x1938fc mov r0, r10 */
/* @0x193900 ldr r12, [r3, #0xc] */
/* @0x193904 add r1, pc, r1 */
/* @0x193908 vmov r2, r3, d6 */
/* @0x19390c blx r12 */
/* @0x193910 vldr s15, [r6, #212] */
/* @0x193914 vcvt.f64.f32 d6, s15 */
/* @0x193918 ldr r3, [r10] */
/* @0x19391c ldr r1, [pc, #0x4dc] —— 格式串 "i_friction             = %f" ← +0xd4 friction */
/* @0x193920 mov r0, r10 */
/* @0x193924 ldr r12, [r3, #0xc] */
/* @0x193928 add r1, pc, r1 */
/* @0x19392c vmov r2, r3, d6 */
/* @0x193930 blx r12 */
/* @0x193934 vldr s15, [r6, #216] */
/* @0x193938 vcvt.f64.f32 d6, s15 */
/* @0x19393c ldr r3, [r10] */
/* @0x193940 ldr r1, [pc, #0x4bc] —— 格式串 "i_gravitydir           = %f" ← +0xd8 gravity_direction */
/* @0x193944 mov r0, r10 */
/* @0x193948 ldr r12, [r3, #0xc] */
/* @0x19394c add r1, pc, r1 */
/* @0x193950 vmov r2, r3, d6 */
/* @0x193954 blx r12 */
/* @0x193958 vldr s15, [r6, #220] */
/* @0x19395c vcvt.f64.f32 d6, s15 */
/* @0x193960 ldr r3, [r10] */
/* @0x193964 ldr r1, [pc, #0x49c] —— 格式串 "i_gravity              = %f" ← +0xdc gravity */
/* @0x193968 mov r0, r10 */
/* @0x19396c ldr r12, [r3, #0xc] */
/* @0x193970 add r1, pc, r1 */
/* @0x193974 vmov r2, r3, d6 */
/* @0x193978 blx r12 */
/* @0x19397c vldr s15, [r6, #224] */
/* @0x193980 vcvt.f64.f32 d6, s15 */
/* @0x193984 ldr r3, [r10] */
/* @0x193988 ldr r1, [pc, #0x47c] —— 格式串 "i_hspeed               = %f" ← +0xe0 hspeed */
/* @0x19398c mov r0, r10 */
/* @0x193990 ldr r12, [r3, #0xc] */
/* @0x193994 add r1, pc, r1 */
/* @0x193998 vmov r2, r3, d6 */
/* @0x19399c blx r12 */
/* @0x1939a0 vldr s15, [r6, #228] */
/* @0x1939a4 vcvt.f64.f32 d6, s15 */
/* @0x1939a8 ldr r3, [r10] */
/* @0x1939ac ldr r1, [pc, #0x45c] —— 格式串 "i_vspeed               = %f" ← +0xe4 vspeed */
/* @0x1939b0 mov r0, r10 */
/* @0x1939b4 ldr r12, [r3, #0xc] */
/* @0x1939b8 add r1, pc, r1 */
/* @0x1939bc vmov r2, r3, d6 */
/* @0x1939c0 blx r12 */
/* @0x1939c4 ldr r3, [r10] */
/* @0x1939c8 ldr r1, [pc, #0x444] —— 格式串 "i_bbox.left            = %d" ← +0xe8（tagYYRECT.l） */
/* @0x1939cc mov r0, r10 */
/* @0x1939d0 ldr r2, [r6, #0xe8] —— bbox 四行：+0xe8 印 left、+0xf0 印 right、+0xec 印 top、+0xf4 印 bottom */
/* @0x1939d4 add r1, pc, r1 */
/* @0x1939d8 ldr r3, [r3, #0xc] */
/* @0x1939dc blx r3 */
/* @0x1939e0 ldr r3, [r10] */
/* @0x1939e4 ldr r1, [pc, #0x42c] —— 格式串 "i_bbox.right           = %d" ← +0xf0（tagYYRECT.r）—— 先印 right 再印 top */
/* @0x1939e8 mov r0, r10 */
/* @0x1939ec ldr r2, [r6, #0xf0] */
/* @0x1939f0 add r1, pc, r1 */
/* @0x1939f4 ldr r3, [r3, #0xc] */
/* @0x1939f8 blx r3 */
/* @0x1939fc ldr r3, [r10] */
/* @0x193a00 ldr r1, [pc, #0x414] —— 格式串 "i_bbox.top             = %d" ← +0xec（tagYYRECT.t） */
/* @0x193a04 mov r0, r10 */
/* @0x193a08 ldr r2, [r6, #0xec] */
/* @0x193a0c add r1, pc, r1 */
/* @0x193a10 ldr r3, [r3, #0xc] */
/* @0x193a14 blx r3 */
/* @0x193a18 ldr r3, [r10] */
/* @0x193a1c ldr r1, [pc, #0x3fc] —— 格式串 "i_bbox.bottom          = %d" ← +0xf4（tagYYRECT.b） */
/* @0x193a20 mov r0, r10 */
/* @0x193a24 ldr r2, [r6, #0xf4] */
/* @0x193a28 add r1, pc, r1 */
/* @0x193a2c ldr r3, [r3, #0xc] */
/* @0x193a30 blx r3 */
/* @0x193a34 ldr r3, [r10] */
/* @0x193a38 ldr r1, [pc, #0x3e4] —— 格式串 "i_visible              = %d" ← ldrb +0x65 visible */
/* @0x193a3c mov r0, r10 */
/* @0x193a40 ldrb r2, [r6, #0x65] */
/* @0x193a44 add r1, pc, r1 */
/* @0x193a48 ldr r3, [r3, #0xc] */
/* @0x193a4c blx r3 */
/* @0x193a50 ldr r3, [r10] */
/* @0x193a54 ldr r1, [pc, #0x3cc] —— 格式串 "i_solid                = %d" ← ldrb +0x66 solid */
/* @0x193a58 mov r0, r10 */
/* @0x193a5c ldrb r2, [r6, #0x66] */
/* @0x193a60 add r1, pc, r1 */
/* @0x193a64 ldr r3, [r3, #0xc] */
/* @0x193a68 blx r3 */
/* @0x193a6c ldr r3, [r10] */
/* @0x193a70 ldr r1, [pc, #0x3b4] —— 格式串 "i_persistent           = %d" ← ldrb +0x67 persistent */
/* @0x193a74 mov r0, r10 */
/* @0x193a78 ldrb r2, [r6, #0x67] */
/* @0x193a7c add r1, pc, r1 */
/* @0x193a80 ldr r3, [r3, #0xc] */
/* @0x193a84 blx r3 */
/* @0x193a88 ldr r8, [r6, #0x7c] —— r8 = objindex(+0x7c)，同时作为 Object_Name 的实参 */
/* @0x193a8c ldr r3, [r10] */
/* @0x193a90 mov r0, r8 */
/* @0x193a94 ldr r9, [r3, #0xc] */
/* @0x193a98 bl 0x19ed54 <_Z11Object_Namei> —— Object_Name(0x7c) → %s 那一栏 */
/* @0x193a9c ldr r1, [pc, #0x38c] —— 格式串 "i_objindex             = %d" ← +0x7c objindex + Object_Name(+0x7c) */
/* @0x193aa0 mov r2, r8 */
/* @0x193aa4 add r1, pc, r1 */
/* @0x193aa8 mov r3, r0 */
/* @0x193aac mov r0, r10 —— 变量表循环前最后一次 Printf */
/* @0x193ab0 blx r9 */
/* @0x193ab4 ldr r12, [r10] —— alarm 循环头：r4 = i(0..11)、r5 从 this 起每轮 +4、读 [r5+0xf8] */
/* @0x193ab8 mov r2, r4 */
/* @0x193abc ldr r3, [r5, #0xf8] */
/* @0x193ac0 mov r0, r10 */
/* @0x193ac4 mov r1, r7 */
/* @0x193ac8 add r4, r4, #1 */
/* @0x193acc ldr r12, [r12, #0xc] */
/* @0x193ad0 add r5, r5, #4 */
/* @0x193ad4 blx r12 */
/* @0x193ad8 cmp r4, #12 —— 12 次后退出（cmp r4,#12） */
/* @0x193adc bne 0x193ab4 <_ZN9CInstance4DumpER11tagIConsole+0x478> */
/* @0x193ae0 ldr r3, [r10] */
/* @0x193ae4 mov r0, r10 */
/* @0x193ae8 ldr r1, [pc, #0x344] —— 格式串 "i_marked               = %d" ← ldrb +0x68 marked（§1/§2 的早退闸） */
/* @0x193aec ldrb r2, [r6, #0x68] */
/* @0x193af0 add r1, pc, r1 */
/* @0x193af4 ldr r3, [r3, #0xc] */
/* @0x193af8 blx r3 */
/* @0x193afc ldr r3, [r10] */
/* @0x193b00 ldr r1, [pc, #0x330] —— 格式串 "i_deactivated          = %d" ← ldrb +0x69 deactivated（§5 的唯一写点） */
/* @0x193b04 mov r0, r10 */
/* @0x193b08 ldrb r2, [r6, #0x69] */
/* @0x193b0c add r1, pc, r1 */
/* @0x193b10 ldr r3, [r3, #0xc] */
/* @0x193b14 blx r3 */
/* @0x193b18 ldr r3, [r10] */
/* @0x193b1c ldr r1, [pc, #0x318] —— 格式串 "i_pathindex            = %d" ← +0x128 path_index */
/* @0x193b20 mov r0, r10 */
/* @0x193b24 ldr r2, [r6, #0x128] */
/* @0x193b28 add r1, pc, r1 */
/* @0x193b2c ldr r3, [r3, #0xc] */
/* @0x193b30 blx r3 */
/* @0x193b34 vldr s15, [r6, #300] */
/* @0x193b38 vcvt.f64.f32 d6, s15 */
/* @0x193b3c ldr r12, [r10] */
/* @0x193b40 ldr r1, [pc, #0x2f8] —— 格式串 "i_pathposition         = %f" ← +0x12c path_position */
/* @0x193b44 mov r0, r10 */
/* @0x193b48 add r1, pc, r1 */
/* @0x193b4c ldr r12, [r12, #0xc] */
/* @0x193b50 vmov r2, r3, d6 */
/* @0x193b54 blx r12 */
/* @0x193b58 vldr s15, [r6, #304] */
/* @0x193b5c vcvt.f64.f32 d6, s15 */
/* @0x193b60 ldr r3, [r10] */
/* @0x193b64 ldr r1, [pc, #0x2d8] —— 格式串 "i_pathpositionprevious = %f" ← +0x130 path_positionprevious */
/* @0x193b68 mov r0, r10 */
/* @0x193b6c ldr r12, [r3, #0xc] */
/* @0x193b70 add r1, pc, r1 */
/* @0x193b74 vmov r2, r3, d6 */
/* @0x193b78 blx r12 */
/* @0x193b7c vldr s15, [r6, #308] */
/* @0x193b80 vcvt.f64.f32 d6, s15 */
/* @0x193b84 ldr r3, [r10] */
/* @0x193b88 ldr r1, [pc, #0x2b8] —— 格式串 "i_pathspeed            = %f" ← +0x134 path_speed */
/* @0x193b8c mov r0, r10 */
/* @0x193b90 ldr r12, [r3, #0xc] */
/* @0x193b94 add r1, pc, r1 */
/* @0x193b98 vmov r2, r3, d6 */
/* @0x193b9c blx r12 */
/* @0x193ba0 vldr s15, [r6, #312] */
/* @0x193ba4 vcvt.f64.f32 d6, s15 */
/* @0x193ba8 ldr r3, [r10] */
/* @0x193bac ldr r1, [pc, #0x298] —— 格式串 "i_pathscale            = %f" ← +0x138 path_scale */
/* @0x193bb0 mov r0, r10 */
/* @0x193bb4 ldr r12, [r3, #0xc] */
/* @0x193bb8 add r1, pc, r1 */
/* @0x193bbc vmov r2, r3, d6 */
/* @0x193bc0 blx r12 */
/* @0x193bc4 vldr s15, [r6, #316] */
/* @0x193bc8 vcvt.f64.f32 d6, s15 */
/* @0x193bcc ldr r3, [r10] */
/* @0x193bd0 ldr r1, [pc, #0x278] —— 格式串 "i_pathorientation      = %f" ← +0x13c path_orientation */
/* @0x193bd4 mov r0, r10 */
/* @0x193bd8 ldr r12, [r3, #0xc] */
/* @0x193bdc add r1, pc, r1 */
/* @0x193be0 vmov r2, r3, d6 */
/* @0x193be4 blx r12 */
/* @0x193be8 ldr r3, [r10] */
/* @0x193bec ldr r1, [pc, #0x260] —— 格式串 "i_pathend              = %d" ← +0x140 path_endaction（int） */
/* @0x193bf0 mov r0, r10 */
/* @0x193bf4 ldr r2, [r6, #0x140] */
/* @0x193bf8 add r1, pc, r1 */
/* @0x193bfc ldr r3, [r3, #0xc] */
/* @0x193c00 blx r3 */
/* @0x193c04 vldr s15, [r6, #324] */
/* @0x193c08 vcvt.f64.f32 d6, s15 */
/* @0x193c0c ldr r12, [r10] */
/* @0x193c10 ldr r1, [pc, #0x240] —— 格式串 "i_pathxstart           = %f" ← +0x144（§3 的世界原点，浮点） */
/* @0x193c14 mov r0, r10 */
/* @0x193c18 add r1, pc, r1 */
/* @0x193c1c ldr r12, [r12, #0xc] */
/* @0x193c20 vmov r2, r3, d6 */
/* @0x193c24 blx r12 */
/* @0x193c28 vldr s15, [r6, #328] */
/* @0x193c2c vcvt.f64.f32 d6, s15 */
/* @0x193c30 ldr r3, [r10] */
/* @0x193c34 ldr r1, [pc, #0x220] —— 格式串 "i_pathystart           = %f" ← +0x148（同上） */
/* @0x193c38 mov r0, r10 */
/* @0x193c3c ldr r12, [r3, #0xc] */
/* @0x193c40 add r1, pc, r1 */
/* @0x193c44 vmov r2, r3, d6 */
/* @0x193c48 blx r12 */
/* @0x193c4c ldr r3, [r10] */
/* @0x193c50 ldr r1, [pc, #0x208] —— 格式串 "i_timelineindex        = %d" ← +0x14c timeline_index */
/* @0x193c54 mov r0, r10 */
/* @0x193c58 ldr r2, [r6, #0x14c] */
/* @0x193c5c add r1, pc, r1 */
/* @0x193c60 ldr r3, [r3, #0xc] */
/* @0x193c64 blx r3 */
/* @0x193c68 vldr s15, [r6, #340] */
/* @0x193c6c vcvt.f64.f32 d6, s15 */
/* @0x193c70 ldr r12, [r10] */
/* @0x193c74 ldr r1, [pc, #0x1e8] —— 格式串 "i_timelineposition     = %f" ← +0x154 timeline_position */
/* @0x193c78 mov r0, r10 */
/* @0x193c7c add r1, pc, r1 */
/* @0x193c80 ldr r12, [r12, #0xc] */
/* @0x193c84 vmov r2, r3, d6 */
/* @0x193c88 blx r12 */
/* @0x193c8c vldr s15, [r6, #344] */
/* @0x193c90 vcvt.f64.f32 d6, s15 */
/* @0x193c94 ldr r3, [r10] */
/* @0x193c98 ldr r1, [pc, #0x1c8] —— 格式串 "i_timelinespeed        = %f" ← +0x158 timeline_speed */
/* @0x193c9c mov r0, r10 */
/* @0x193ca0 ldr r12, [r3, #0xc] */
/* @0x193ca4 add r1, pc, r1 */
/* @0x193ca8 vmov r2, r3, d6 */
/* @0x193cac blx r12 */
/* @0x193cb0 ldr r3, [r10] */
/* @0x193cb4 ldr r1, [pc, #0x1b0] —— 格式串 "i_timelinerunning      = %d" ← ldrb +0x15c timeline_running */
/* @0x193cb8 mov r0, r10 */
/* @0x193cbc ldrb r2, [r6, #0x15c] */
/* @0x193cc0 add r1, pc, r1 */
/* @0x193cc4 ldr r3, [r3, #0xc] */
/* @0x193cc8 blx r3 */
/* @0x193ccc ldr r3, [r10] */
/* @0x193cd0 ldr r1, [pc, #0x198] —— 格式串 "i_timelineloop         = %d" ← ldrb +0x15d timeline_loop */
/* @0x193cd4 mov r0, r10 */
/* @0x193cd8 ldrb r2, [r6, #0x15d] */
/* @0x193cdc ldr r3, [r3, #0xc] */
/* @0x193ce0 add r1, pc, r1 */
/* @0x193ce4 blx r3 */
/* @0x193ce8 ldr r3, [r6, #0x60] —— 变量表：this->[0x60] 是容器指针，0 则整段跳过 */
/* @0x193cec cmp r3, #0 */
/* @0x193cf0 popeq {r4, r5, r6, r7, r8, r9, r10, pc} —— 无变量容器 ⇒ 直接返回（全卡唯一的早退） */
/* @0x193cf4 ldr r9, [pc, #0x178] */
/* @0x193cf8 mov r4, #0 */
/* @0x193cfc ldr r8, [pc, #0x174] */
/* @0x193d00 mvn r7, #-16777216 */
/* @0x193d04 ldr r1, [r3] —— r1 = 容器->count（+0） */
/* @0x193d08 add r9, pc, r9 */
/* @0x193d0c ldr r0, [r3, #0x10] —— r0 = 容器->base（+0x10），项宽 12 B */
/* @0x193d10 add r8, pc, r8 */
/* @0x193d14 add r3, r4, r4, lsl #1 —— 项地址 = base + 12*i（3*i<<2） */
/* @0x193d18 add r3, r0, r3, lsl #2 */
/* @0x193d1c add r4, r4, #1 */
/* @0x193d20 mov r5, r3 */
/* @0x193d24 cmp r4, r1 —— cmp 在自增之后、popgt ⇒ 正好 count 次（i = 0..count-1） */
/* @0x193d28 add r3, r3, #12 */
/* @0x193d2c popgt {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x193d30 ldr r2, [r5, #0x8] —— 项 +8（int）<= 0 ⇒ 跳过该项 */
/* @0x193d34 cmp r2, #0 */
/* @0x193d38 ble 0x193d1c <_ZN9CInstance4DumpER11tagIConsole+0x6e0> */
/* @0x193d3c ldm r5, {r2, r3} —— 项 = {+0 int id, +4 RValue*, +8 int} */
/* @0x193d40 ldr r3, [r3, #0xc] */
/* @0x193d44 bic r3, r3, #-16777216 —— RValue 的 tag 在 +0xc，取低 24 位 */
/* @0x193d48 cmp r3, r7 */
/* @0x193d4c beq 0x193d14 <_ZN9CInstance4DumpER11tagIConsole+0x6d8> —— tag == 0x00FFFFFF（空值）⇒ 跳过 */
/* @0x193d50 add r2, r2, #99328 —— r2 = id + 99328 */
/* @0x193d54 mvn r1, #0 */
/* @0x193d58 add r2, r2, #672 —— r2 = id + 100000（99328+672），即作用域变量 id 基址 */
/* @0x193d5c mov r0, #0 —— name 传 0 */
/* @0x193d60 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> —— Code_Variable_Find_Name(0, -1, id+100000) → 变量名字符串 */
/* @0x193d64 ldr r3, [r10] */
/* @0x193d68 mov r1, r9 */
/* @0x193d6c ldr r3, [r3, #0xc] */
/* @0x193d70 mov r2, r0 */
/* @0x193d74 mov r0, r10 —— Printf("%s = ", name) */
/* @0x193d78 blx r3 */
/* @0x193d7c mov r0, r10 */
/* @0x193d80 ldr r1, [r5, #0x4] */
/* @0x193d84 bl 0x1f563c <_Z11OutputValueP11tagIConsoleP6RValue> —— OutputValue(console, RValue*) 打值 */
/* @0x193d88 ldr r3, [r10] */
/* @0x193d8c mov r0, r10 */
/* @0x193d90 mov r1, r8 —— Printf("\n") */
/* @0x193d94 ldr r3, [r3, #0xc] */
/* @0x193d98 blx r3 */
/* @0x193d9c ldr r3, [r6, #0x60] */
/* @0x193da0 ldr r1, [r3] */
/* @0x193da4 ldr r0, [r3, #0x10] */
/* @0x193da8 b 0x193d14 <_ZN9CInstance4DumpER11tagIConsole+0x6d8> */
/* @0x193dac andseq r9, r11, r4 —— 池字 0x001b9004（i_id 串），非指令 */
/* @0x193db0 ldrsheq r9, [r11], -r12 —— 池字 0x001b93fc（0x34ca90 的增量），非指令 */
/* @0x193db4 ldrsheq r8, [r11], -r4 —— 池字 0x001b8ff4（i_spriteindex 串），非指令 */
/* @0x193db8 ldrsheq r8, [r11], -r4 */
/* @0x193dbc andseq r8, r11, r12, ror #31 */
/* @0x193dc0 andseq r8, r11, r8, ror #31 */
/* @0x193dc4 andseq r8, r11, r4, ror #31 */
/* @0x193dc8 andseq r8, r11, r0, ror #31 */
/* @0x193dcc ldrsbeq r8, [r11], -r12 */
/* @0x193dd0 andseq r8, r11, r0, ror #31 */
/* @0x193dd4 andseq r8, r11, r4, ror #31 */
/* @0x193dd8 andseq r8, r11, r0, ror #31 */
/* @0x193ddc andseq r8, r11, r4, ror #31 */
/* @0x193de0 andseq r8, r11, r4, ror #31 */
/* @0x193de4 ldrsbeq r8, [r11], -r12 */
/* @0x193de8 ldrsbeq r8, [r11], -r8 */
/* @0x193dec ldrsbeq r8, [r11], -r4 */
/* @0x193df0 ldrsbeq r8, [r11], -r0 */
/* @0x193df4 andseq r8, r11, r12, asr #31 */
/* @0x193df8 andseq r8, r11, r8, asr #31 */
/* @0x193dfc andseq r8, r11, r4, asr #31 */
/* @0x193e00 andseq r8, r11, r0, asr #31 */
/* @0x193e04 ldrheq r8, [r11], -r12 */
/* @0x193e08 ldrheq r8, [r11], -r8 */
/* @0x193e0c ldrheq r8, [r11], -r4 */
/* @0x193e10 ldrheq r8, [r11], -r0 */
/* @0x193e14 ldrheq r8, [r11], -r4 */
/* @0x193e18 ldrheq r8, [r11], -r8 */
/* @0x193e1c ldrheq r8, [r11], -r12 */
/* @0x193e20 andseq r8, r11, r0, asr #31 */
/* @0x193e24 andseq r8, r11, r4, asr #31 */
/* @0x193e28 andseq r8, r11, r8, asr #31 */
/* @0x193e2c andseq r8, r11, r12, asr #31 */
/* @0x193e30 andseq r8, r11, r4, asr #31 */
/* @0x193e34 ldrheq r8, [r11], -r4 */
/* @0x193e38 ldrheq r8, [r11], -r8 */
/* @0x193e3c ldrheq r8, [r11], -r12 */
/* @0x193e40 ldrheq r8, [r11], -r12 */
/* @0x193e44 ldrheq r8, [r11], -r4 */
/* @0x193e48 ldrheq r8, [r11], -r0 */
/* @0x193e4c andseq r8, r11, r12, lsr #31 */
/* @0x193e50 andseq r8, r11, r8, lsr #31 */
/* @0x193e54 andseq r8, r11, r12, lsr #31 */
/* @0x193e58 andseq r8, r11, r12, lsr #31 */
/* @0x193e5c andseq r8, r11, r4, lsr #31 */
/* @0x193e60 andseq r8, r11, r8, lsr #31 */
/* @0x193e64 andseq r8, r11, r8, lsr #31 */
/* @0x193e68 andseq r8, r11, r0, lsr #31 */
/* @0x193e6c andseq r8, r11, r4, lsr #31 */
/* @0x193e70 andseq r8, r11, r4, lsr #31 */
/* @0x193e74 mulseq r11, r12, pc */
/* @0x193e78 andseq lr, r9, r8, lsl #31 */
/* ══ §5 CInstance::SetDeactivated(bool) 0x19230c ═════════════════════════════
 * @func 0x19230c 0x192340 size 52  13 条（11 指令 + 末 2 字 0x192338/0x19233c 为 literal pool）
 * 级别: 正文（13/13。写点、闸门、尾跳全钉）
 * 符号: _ZN9CInstance14SetDeactivatedEb → void CInstance::SetDeactivated(bool)
 * 位置: CInstance 方法群里地址最低的一个；下一个符号是 Compute_BoundingBox 0x192340（相隔 0x34 B）
 * 调用点（7）：F_InstanceDeactivateObject 0x10a624、F_InstanceDeactivateAll 0x10b500、
 *   F_InstanceActivateAll 0x10be5c、F_InstanceActivateObject 0x10bf58/0x10c118、
 *   F_LayerActivate 0x1bba68、F_LayerDeactivate 0x1bbbbc
 * 语义: this->[0x69] = d; if (g_isZeus) CLayerManager::UpdateInstanceActivation(Run_Room, this);
 *   +0x69 = Dump 的 i_deactivated（§4 第 47 行）；g_isZeus（0x5428e8，1 B）与 Run_Room
 *   （0x54298c，CRoom*）经 GOT 0x3ed92c / 0x3ed930 取得。两条出口都是 bx lr / b（无帧）
 */
/* @0x19230c ldr r3, [pc, #0x24] */
/* @0x192310 strb r1, [r0, #0x69] */
/* @0x192314 ldr r3, [pc, r3] */
/* @0x192318 ldrb r3, [r3] */
/* @0x19231c cmp r3, #0 */
/* @0x192320 bxeq lr */
/* @0x192324 ldr r3, [pc, #0x10] */
/* @0x192328 mov r1, r0 */
/* @0x19232c ldr r3, [pc, r3] */
/* @0x192330 ldr r0, [r3] */
/* @0x192334 b 0x1b8a28 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance> */
/* @0x192338 eoreq r11, r5, r0, lsl r6 */
/* @0x19233c .word 0x0025b5fc */
/* ══ §6 CInstance::Set_MaskIndex(int) 0x192ba8 ═══════════════════════════════
 * @func 0x192ba8 0x192bc4 size 28  7 条
 * 级别: 正文（7/7）
 * 符号: _ZN9CInstance13Set_MaskIndexEi → void CInstance::Set_MaskIndex(int)
 * 位置: Compute_Speed2 0x192aa0 之后、RelinkObjectTypes 0x192bc4 之前
 * 调用点（1）：SV_MaskIndex 0x1fb974（builtin 的 setter 包装）
 * 语义: if (this->[0xac] == v) return; this->[0xac] = v; this->[0x64] = 1; CollisionMarkDirty(this);
 *   —— 本卡里「置脏 + 尾跳 CollisionMarkDirty 0x1cc1d0」的最小样板，与 SetImageScaleX/Y/Angle、
 *   SetPosition、SetObjectIndex 同构；值相同则一个字节都不写（连脏都不置）
 */
/* @0x192ba8 ldr r2, [r0, #0xac] */
/* @0x192bac cmp r2, r1 */
/* @0x192bb0 bxeq lr */
/* @0x192bb4 mov r2, #1 */
/* @0x192bb8 str r1, [r0, #0xac] */
/* @0x192bbc strb r2, [r0, #0x64] */
/* @0x192bc0 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* ══ §7 CInstance::SetImageScaleX(float) 0x192fec ════════════════════════════
 * @func 0x192fec 0x193014 size 40  10 条
 * 级别: 正文（10/10）
 * 符号: _ZN9CInstance14SetImageScaleXEf → void CInstance::SetImageScaleX(float)
 * 位置: RebuildPhysicsBody 0x192fa4 之后、SetImageScaleY 0x193014 之前（三个 setter 连排）
 * 调用点（5）：F_ActionSetSprite 0x13d994、F_ActionSpriteTransform 0x13e5e4/0x13e630、
 *   CRoom::Assign 0x1adf6c、SV_ImageXScale 0x1fb854
 * 语义: 浮点相等短路（vcmp + vmrs + bxeq）→ 写 +0x98 → +0x64=1 → 尾跳 CollisionMarkDirty
 */
/* @0x192fec vmov s15, r1 */
/* @0x192ff0 vldr s14, [r0, #152] */
/* @0x192ff4 mov r3, r0 */
/* @0x192ff8 vcmp.f32 s14, s15 */
/* @0x192ffc vmrs APSR_nzcv, fpscr */
/* @0x193000 bxeq lr */
/* @0x193004 str r1, [r3, #0x98] */
/* @0x193008 mov r2, #1 */
/* @0x19300c strb r2, [r0, #0x64] */
/* @0x193010 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* ══ §8 CInstance::SetImageScaleY(float) 0x193014 ════════════════════════════
 * @func 0x193014 0x19303c size 40  10 条
 * 级别: 正文（10/10）
 * 符号: _ZN9CInstance14SetImageScaleYEf → void CInstance::SetImageScaleY(float)
 * 位置: SetImageScaleX 0x192fec 之后、SetImageAngle 0x19303c 之前
 * 调用点（3）：F_ActionSpriteTransform 0x13e5f0、CRoom::Assign 0x1adf78、SV_ImageYScale 0x1fb8a0
 * 语义: 同 §7，字段为 +0x9c
 */
/* @0x193014 vmov s15, r1 */
/* @0x193018 vldr s14, [r0, #156] */
/* @0x19301c mov r3, r0 */
/* @0x193020 vcmp.f32 s14, s15 */
/* @0x193024 vmrs APSR_nzcv, fpscr */
/* @0x193028 bxeq lr */
/* @0x19302c str r1, [r3, #0x9c] */
/* @0x193030 mov r2, #1 */
/* @0x193034 strb r2, [r0, #0x64] */
/* @0x193038 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* ══ §9 CInstance::SetImageAngle(float) 0x19303c ═════════════════════════════
 * @func 0x19303c 0x193064 size 40  10 条
 * 级别: 正文（10/10）
 * 符号: _ZN9CInstance13SetImageAngleEf → void CInstance::SetImageAngle(float)
 * 位置: SetImageScaleY 0x193014 之后、SetDirection 0x193064 之前
 * 调用点（4）：F_ActionSpriteTransform 0x13e5fc、CRoom::Assign 0x1adfa4、SV_ImageAngle 0x1fb900、
 *   0x2381d4（CPhysicsWorld 群）
 * 语义: 同 §7，字段为 +0xa0（image_angle）
 */
/* @0x19303c vmov s15, r1 */
/* @0x193040 vldr s14, [r0, #160] */
/* @0x193044 mov r3, r0 */
/* @0x193048 vcmp.f32 s14, s15 */
/* @0x19304c vmrs APSR_nzcv, fpscr */
/* @0x193050 bxeq lr */
/* @0x193054 str r1, [r3, #0xa0] */
/* @0x193058 mov r2, #1 */
/* @0x19305c strb r2, [r0, #0x64] */
/* @0x193060 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* ══ §10 CInstance::SetSpeed(float) 0x1930d4 ═════════════════════════════════
 * @func 0x1930d4 0x1930f4 size 32  8 条
 * 级别: 正文（8/8）
 * 符号: _ZN9CInstance8SetSpeedEf → void CInstance::SetSpeed(float)
 * 位置: SetDirection 0x193064 之后、SetHspeed 0x1930f4 之前
 * 调用点（6）：0x14142c、0x14193c、Adapt_Speed 0x193fc8/0x193fd8、**Adapt_Path 0x194328**、
 *   SV_Speed 0x1fb7a8
 * 语义: 浮点相等短路 → +0xd0 = v → **尾跳 Compute_Speed2 0x192aa0**。
 *   ★ 与 §7/§8/§9 不同：这里不置 +0x64、不调 CollisionMarkDirty —— 速度不是包围盒的输入。
 *   方向由 direction 与 speed 重算 hspeed/vspeed（Compute_Speed2 的语义见 open）。
 */
/* @0x1930d4 vmov s15, r1 */
/* @0x1930d8 vldr s14, [r0, #208] */
/* @0x1930dc mov r3, r0 */
/* @0x1930e0 vcmp.f32 s14, s15 */
/* @0x1930e4 vmrs APSR_nzcv, fpscr */
/* @0x1930e8 bxeq lr */
/* @0x1930ec str r1, [r3, #0xd0] */
/* @0x1930f0 b 0x192aa0 <_ZN9CInstance14Compute_Speed2Ev> */
/* ══ §11 CInstance::SetHspeed(float) 0x1930f4 ════════════════════════════════
 * @func 0x1930f4 0x193114 size 32  8 条
 * 级别: 正文（8/8）
 * 符号: _ZN9CInstance9SetHspeedEf → void CInstance::SetHspeed(float)
 * 位置: SetSpeed 0x1930d4 之后、SetVspeed 0x193114 之前
 * 调用点（4）：**Adapt_Path 0x194308**、0x1c9810、0x1cb1e8、SV_HSpeed 0x1fb6c4
 * 语义: 相等短路 → +0xe0 = v → 尾跳 Compute_Speed1 0x1928d8
 */
/* @0x1930f4 vmov s15, r1 */
/* @0x1930f8 vldr s14, [r0, #224] */
/* @0x1930fc mov r3, r0 */
/* @0x193100 vcmp.f32 s14, s15 */
/* @0x193104 vmrs APSR_nzcv, fpscr */
/* @0x193108 bxeq lr */
/* @0x19310c str r1, [r3, #0xe0] */
/* @0x193110 b 0x1928d8 <_ZN9CInstance14Compute_Speed1Ev> */
/* ══ §12 CInstance::SetVspeed(float) 0x193114 ════════════════════════════════
 * @func 0x193114 0x193134 size 32  8 条
 * 级别: 正文（8/8）
 * 符号: _ZN9CInstance9SetVspeedEf → void CInstance::SetVspeed(float)
 * 位置: SetHspeed 0x1930f4 之后、GetTimer 0x193134 之前
 * 调用点（3）：**Adapt_Path 0x19431c**、0x1c9824、SV_VSpeed 0x1fb710
 * 语义: 相等短路 → +0xe4 = v → 尾跳 Compute_Speed1 0x1928d8（与 hspeed 共用重算口）
 */
/* @0x193114 vmov s15, r1 */
/* @0x193118 vldr s14, [r0, #228] */
/* @0x19311c mov r3, r0 */
/* @0x193120 vcmp.f32 s14, s15 */
/* @0x193124 vmrs APSR_nzcv, fpscr */
/* @0x193128 bxeq lr */
/* @0x19312c str r1, [r3, #0xe4] */
/* @0x193130 b 0x1928d8 <_ZN9CInstance14Compute_Speed1Ev> */
/* ══ §13 CInstance::SetTimer(int, int) 0x193148 ══════════════════════════════
 * @func 0x193148 0x193158 size 16  4 条
 * 级别: 正文（4/4）
 * 符号: _ZN9CInstance8SetTimerEii → void CInstance::SetTimer(int slot, int value)
 * 位置: GetTimer 0x193134 之后、SkeletonAnimation 0x193158 之前（与 GetTimer 紧邻成对）
 * 调用点（2）：HandleAlarm 0x1cdeb8、SV_Alarm 0x1fb810
 * 语义: if ((unsigned)slot <= 11) this->alarm[slot] = value;
 *   即 `cmp r1,#11 / addls r1,r1,#62 / strls r2,[r0,r1,lsl #2]` —— 基址 0xf8、项宽 4、
 *   上界 12 项，与 ctor 的 alarm 双循环、GetTimer 的 `i<=11` 三方一致；
 *   无符号比较 ⇒ 负数 slot 直接丢弃（GetTimer 则返回 -1）
 */
/* @0x193148 cmp r1, #11 */
/* @0x19314c addls r1, r1, #62 */
/* @0x193150 strls r2, [r0, r1, lsl #2] */
/* @0x193154 bx lr */
/* ══ §14 CInstance::SetPathPosition(float) 0x1935c4 ══════════════════════════
 * @func 0x1935c4 0x1935fc size 56  14 条（13 指令 + 末 1 字 0x1935f8 = 0.0f 为 literal pool）
 * 级别: 正文（14/14）
 * 符号: _ZN9CInstance15SetPathPositionEf → void CInstance::SetPathPosition(float)
 * 位置: GetImageNumber 0x19357c 之后、SetPathPositionPrevious 0x1935fc 之前
 * 调用点（8）：processCollision 0x1cc0b8/0x1cc0d4、CollisionMarkDirty 群 0x1cc1a8、
 *   CollisionUpdate 0x1cc678/0x1cc694/0x1cc768/0x1cc784、SV_PathPosition 0x1fb9b8
 * 语义: 夹到闭区间 [0,1]：v < 0 ⇒ 0.0f（池里的 0x00000000）；v > 1 ⇒ 1.0f；其余原样。
 *   没有脏标志、没有 CollisionMarkDirty —— 路径位置不直接改包围盒（真改由 Adapt_Path 的
 *   SetPosition 完成）。NaN 进不来：vcmpe 的 N/Z 都为 1 时 bmi 与 vmovgt 都不成立，写的仍是 v。
 */
/* @0x1935c4 vmov s15, r1 */
/* @0x1935c8 vcmpe.f32 s15, #0 */
/* @0x1935cc vmrs APSR_nzcv, fpscr */
/* @0x1935d0 bmi 0x1935ec <_ZN9CInstance15SetPathPositionEf+0x28> */
/* @0x1935d4 vmov.f32 s14, #1.000000e+00 */
/* @0x1935d8 vcmp.f32 s15, s14 */
/* @0x1935dc vmrs APSR_nzcv, fpscr */
/* @0x1935e0 vmovgt.f32 s15, s14 */
/* @0x1935e4 vstr s15, [r0, #300] */
/* @0x1935e8 bx lr */
/* @0x1935ec vldr s15, [pc, #4] */
/* @0x1935f0 vstr s15, [r0, #300] */
/* @0x1935f4 bx lr */
/* @0x1935f8 andeq r0, r0, r0 */
/* ══ §15 CInstance::SetPathPositionPrevious(float) 0x1935fc ═══════════════════
 * @func 0x1935fc 0x193634 size 56  14 条（13 指令 + 末 1 字 0x193630 = 0.0f 为 literal pool）
 * 级别: 正文（14/14）
 * 符号: _ZN9CInstance23SetPathPositionPreviousEf → void CInstance::SetPathPositionPrevious(float)
 * 位置: SetPathPosition 0x1935c4 之后、SetPathSpeed 0x193634 之前
 * 调用点（1）：SV_PathPositionPrevious 0x1fba04
 * 语义: 与 §14 逐指令同构，字段换成 +0x130（path_positionprevious，Dump 第 50 行）
 */
/* @0x1935fc vmov s15, r1 */
/* @0x193600 vcmpe.f32 s15, #0 */
/* @0x193604 vmrs APSR_nzcv, fpscr */
/* @0x193608 bmi 0x193624 <_ZN9CInstance23SetPathPositionPreviousEf+0x28> */
/* @0x19360c vmov.f32 s14, #1.000000e+00 */
/* @0x193610 vcmp.f32 s15, s14 */
/* @0x193614 vmrs APSR_nzcv, fpscr */
/* @0x193618 vmovgt.f32 s15, s14 */
/* @0x19361c vstr s15, [r0, #304] */
/* @0x193620 bx lr */
/* @0x193624 vldr s15, [pc, #4] */
/* @0x193628 vstr s15, [r0, #304] */
/* @0x19362c bx lr */
/* @0x193630 andeq r0, r0, r0 */
/* ══ §16 CInstance::SetPathSpeed(float) 0x193634 ═════════════════════════════
 * @func 0x193634 0x19363c size 8  2 条
 * 级别: 正文（2/2）
 * 符号: _ZN9CInstance12SetPathSpeedEf → void CInstance::SetPathSpeed(float)
 * 位置: SetPathPositionPrevious 0x1935fc 之后、CInstance::Dump 0x19363c 之前
 * 调用点（1）：SV_PathSpeed 0x1fba50
 * 语义: this->[0x134] = v（str 直写，**无**相等短路、无脏标志、无尾跳）——
 *   是全卡最短的访问器，也是唯一一个连比较都省掉的 setter
 */
/* @0x193634 str r1, [r0, #0x134] */
/* @0x193638 bx lr */
