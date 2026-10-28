/* cally 逆向卡：CSprite::DrawSWF / CSprite::DrawShape（原版 libyoyo.so，armv7）
 * @func 0x1ebf08 0x1ec71c  size 2072  518 条（literal pool 0x1ec2bc..0x1ec2d0 共 6 字；真指令 512）
 * @func 0x1ed768 0x1ee764  size 4096  1024 条（literal pool 0x1edbe4..0x1edc24 共 17 字 +
 *                                    0x1ee668..0x1ee688 共 9 字；真指令 998）
 * 级别: 正文（1542/1542 逐条落锚；形参落位、两道守卫、颜色合成、矩阵链、状态存取、帧取模、
 *       228 B 记录步长、图形通道三矩阵合成与透视除法、sqrtf 回退全部证到指令。
 *       未钉：CSprite 字段官方名（+0x54/+0x7c/+0x80/+0x84）、GOT 0x3f0ddc / 0x3ee5d0 / 0x3ed924 /
 *       0x3f014c / 0x3f0150 / 0x3f0480 的符号名、this+0x84 帧表的 ×8 步长、
 *       0x1edee8 的 sp+320/sp+324 两字来源、DrawDictionaryItem 六个指针形参各自指向的数组语义、
 *       DrawSWFObject 的 bool 形参语义）
 * 符号: _ZN7CSprite7DrawSWFEifffffffjf  → void CSprite::DrawSWF(int i, float ox, float oy, float x,
 *                                     float y, float xs, float ys, float rot, uint32 colour, float alpha)
 *       _ZN7CSprite9DrawShapeEiiifffffjjf → void CSprite::DrawShape(int i, int j, int k, float x, float y,
 *                                     float xs, float ys, float rot, uint32 c1, uint32 c2, float alpha)
 *       ⚠ DrawSWF 的 7 个 float 里前两个是**原点**（ox,oy），不是 x,y：全仓卡组里能查到的四个
 *         调用点（CSprite::Draw 1ec9c0、DrawSimple 1ecd20、DrawStretched 1ecfa0、DrawSWFTiled 1ed19c），
 *         其中三处（1ec97c/1ec98c、1eccd0 段、1ed144/1ed148）明确把 this+0x24/+0x28 装进 r2/r3。
 * 同层: CSprite::DrawSWFObject 0x1eba90、CSprite::DrawSWFTiled 0x1ecfb8、
 *       CSprite::DrawDictionaryItem 0x1e9c10、CSprite::DrawShapeString 0x1ee768（size 4，未展开）、
 *       yyMatrix::SetZRotation 0x27aedc / Multiply 0x27aa00、Graphics::GetMatrix 0x17ead0、
 *       RenderStateManager Get/SetRenderState 0x167f8c/0x167e64、Get/SetSamplerState 0x167fa0/0x167ef4、
 *       GR_Texture_Exists 0x173e2c、F_DrawShape 0x11c038（唯一入口，GML 内建，12 个实参）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   这两条是 CSprite 的**矢量（SWF）输出口**，与纹理档的三条（Draw/DrawSimple/DrawTiled）互不重叠：
 *   它们一条 GR_Texture_* 都不调，只负责「算矩阵 + 算颜色 + 排序 + 改/还原渲染状态」，
 *   真正的光栅化全部落在 CSprite::DrawSWFObject（逐子项）与 CSprite::DrawDictionaryItem（逐形状）。
 *   DrawSWF = 时间线驱动（i 是帧号，取模后按该帧子项深度排序后逐个画）；
 *   DrawShape = 立即模式图形（GML 内建 F_DrawShape 0x11c038 那条路），228 B 记录做延迟队列，
 *   并用 Graphics 的当前矩阵栈把形状的两个基向量变换出去求一个归一化比例。
 *
 * ── 与纹理后端（cards/CSprite_Draw.c）的差异（本卡重点 1）────────────
 *   ① 后端档位：纹理档由 CSprite::Draw 内部按 this+0x74 分派后进来，本卡两函数**不看 +0x74**
 *      （两段各自只有 0 条 / 2 条「0x74」，且那 2 条都是 [sp,#0x74] 的栈偏移，不是字段）。
 *      它们自己就是「1 号档」的实现。
 *   ② 像素来源：纹理档调 GR_Texture_Draw / _Drawi / _Tiled；本卡调 DrawSWFObject / DrawDictionaryItem。
 *      ⇒ 纹理档的形参是 (tpe|贴图号, ox, oy, x, y, xs, ys, rot, colour, alpha)，
 *        本卡交付的是 (this, 子项, 矩阵×2, 四个颜色缓冲指针, bool) 或 (this, 形状, 矩阵, f, b, b, 6 指针, 2 float)。
 *   ③ 角度单位：纹理档在 1ec7f0 处先乘 π 再除 180（度→弧度）；本卡两函数**没有任何 π/180**
 *      （两张 literal pool 里都没有 0x40490fdb），rot 原样进 yyMatrix::SetZRotation
 *      ⇒ 上游的 CSprite::Draw 确实是在分派之后才做换算的（1ec7e0/1ec7e8 先跳走）。
 *   ④ 剔除与剖析：纹理档 Draw/DrawSimple 有 GR_3DMode 闸、ms_ignoreCull 闸、四边视野矩形判定、
 *      g_isZeus 旁路、CProfiler Push/Pop；本卡两函数**全都没有**（GOT 槽清单可数：
 *      DrawSWF 只碰 4 个槽（栈保护 / RSM / 字节开关 / float）；DrawShape 只碰 0x3edd00（RSM）、
 *      0x3ed924（纹理表）、0x3ed928（float z）、0x3ee5c0（float g2）、0x3ee5d0（字节开关）、
 *      0x3f014c/0x3f0150（两个 int 标量）、0x3f0480（int 判非 0）、0x3f0ddc（float g），
 *      外加 8 个状态/队列槽 0x3f0df0/f4/f8/fc 与 0x3f0e00/04/08/0c）。剔除只发生在 CSprite::Draw 里。
 *   ⑤ 状态责任：纹理档把 colour/alpha 原样透传、不改任何状态；DrawSWF 自己存/还原 8 个状态；
 *      DrawShape 更进一步，用 a1==-1/-2 两个魔法值把状态保存/还原**跨调用**做成协议。
 *   ⑥ 零字段写：DrawSWF 的 119 条 str/vstr = 102 条 r11 相对 + 15 条 sp 相对 + 1 条写 alloca 数组
 *      + 1 条数组内搬移，**没有一条写 this 或写全局**；DrawShape 的 189 条 str/vstr = 169 条 sp 相对
 *      + 2 条写栈上变换目标 + 8 条写队列记录(lr) + 1 条写记录 +0x00 + 3 条写队列计数器 + 6 条写状态槽，
 *      **同样没有一条写 this**（r11=this 却 0 条 str [r11…]）。
 *
 * ── 形参落位（两段各一张表，逐条来自取参指令）────────────────────
 *   DrawSWF 帧 712（push 36 + vpush {d8} 8 + sub 668），r11 = 入口 sp − 4 ⇒ 第 k 个栈字在 [r11, #4+4k]：
 *     this=r0  i=r1  ox=r2  oy=r3
 *     [r11+4]=x  [r11+8]=y  [r11+0xc]=xs  [r11+0x10]=ys  [r11+0x14]=rot  [r11+0x18]=colour  [r11+0x1c]=alpha
 *     读点：1ebf34(ox) 1ebf80(oy 落栈 -0x2ac) 1ebf38(colour) 1ec020(alpha) 1ec064(x) 1ec068(y)
 *           1ec12c(xs) 1ec1bc(ys) 1ebf54(rot)；7 个栈字全部读满，无一遗漏。
 *   DrawShape 帧 1344（push 36 + vpush {d8,d9} 16 + sub 1280 + sub 12），**r11 = this，不是帧指针**：
 *     this=r0  i=r1  j=r2  k=r3
 *     [sp+1344]=x  [1348]=y  [1352]=xs  [1356]=ys  [1360]=rot  [1364]=c1  [1368]=c2  [1372]=alpha
 *     读点：1ed890(x，直接落矩阵 A 的 e12=[sp+0x178]) 1ed8b0(y→[sp+0x17c]=e13) 1ed944(xs) 1ed95c(ys)
 *           1ed8a0(rot) 1ed818/1ed820(c1)
 *           1ed884(c2) 1ed7f8(alpha)
 *     语义由唯一入口 F_DrawShape 0x11c038（cards/auto/bank_0049.c:141-221）的 12 个 YYGet* 落位互证：
 *       YYGetInt32(0)→Sprite_Data → this；1→i；2→j；3→k；4→x；5→y；6→xs；7→ys；8→rot；9→c1；10→c2；11→alpha
 *
 * ── SWF 矩阵与时序（本卡重点 2）────────────────────────────────
 *   两个函数造的是同一条 4×4 仿射链，差别只在 DrawSWF 多一个「原点平移」前置块：
 *     DrawSWF   : A = T(−ox/g, −oy/g) → B = S(g·xs, g·ys) → R = Rz(rot) → D = T(x, y)
 *                 M1=A·B（-0x130）、M2=M1·R（-0xF0）、M3=M2·D（-0xB0）
 *     DrawShape : A = T(x, y)（sp+328） → B = Rz(rot)（sp+392） → C = I（sp+456） → D = S(g·xs, g·ys)（sp+520）
 *                 E=C·D（sp+584）、F=E·B（sp+648）、G=F·A（sp+712）
 *     g = *GOT 0x3f0ddc（float，两函数共用；在 T 里做除数、在 S 里做乘数）。
 *   列主序证据：平移落在 e12/e13、缩放落在 e0/e5、齐次项 e15=1.0f、SetZRotation 只写旋转块；
 *   yyMatrix 是 64 B（8 个块在 DrawSWF 里按 -0x230,-0x1f0,…, -0x70 连续排；
 *   DrawShape 里按 sp+328/392/456/520/584/648/712 连续排）。
 *   时序（DrawSWF 独有）：i 不是子图号而是**帧号** → i % *(*(this+0x84)+0x18)（帧数）；
 *   该帧 [帧+0x00]=子项数组、[帧+0x14]=子项数 n，子项 144 B，按 [子项+0xc]（深度）插入排序，
 *   比较用 blt（严格小于）⇒ 同深度保持原序；排序过程中就地调 DrawSWFObject，最后按排好的
 *   数组整表再画一遍（1ec628..1ec65c）。
 *
 * ── DrawShape 的图形通道（本卡重点 3）───────────────────────────
 *   1ede1c 起是本函数独有的「Graphics 通道」，开关是一个全局字节（GOT 0x3ee5d0，与 DrawSWF
 *   1ec59c 传给 DrawSWFObject 的 bool 同源）：
 *     开关 == 0 → s15 = 1.0f，直接跳到 1ee5cc（不做任何矩阵合成）
 *     开关 != 0 → Graphics::GetMatrix(2, sp+904) / (0, sp+968) / (1, sp+1032) 取三个矩阵，
 *                三次 Multiply 合成到 sp+1224：((M2·M0)·M1)·M_local，
 *                再把**单位基向量** (1,0)/(0,1) 逐点过这个矩阵（含透视除法），
 *                结果乘上两个全局 int（GOT 0x3f014c / 0x3f0150，vcvt 后当 float 用），
 *                最后用这两条边求 f3 = g2 / (0.5·max(|e1|,|e2|))（负数/零走 sqrtf@plt 回退）。
 *   ⇒ 形状顶点本身不在本函数变换：它把合成好的矩阵、两条 UV 比值（s18/s16）和 f3 一起交给
 *     DrawDictionaryItem，由那边逐顶点光栅化。


/* ══ 段 A · CSprite::DrawSWF 0x1ebf08 ══════════════════════════════════════════════════════
 *   2072 B / 518 字 = 512 条真指令 + 6 字 literal pool（0x1ec2bc..0x1ec2d0）。
 *   49 条 bl：SetRenderState 30、GetRenderState 6、SetSamplerState 2、GetSamplerState 2、
 *   yyMatrix::Multiply 3、DrawSWFObject 3、SetZRotation 1、__aeabi_idivmod 1、__stack_chk_fail 1。
 *   没有 GR_Texture_*、没有 GR_3D_*、没有 CProfiler、没有 CCamera。
 *
 *   控制流骨架（按地址，语义块与源码块不同序）：
 *     0x1ebf08 序言/守卫/存 8 个状态     0x1ec000 帧取模 + alpha 覆盖 colour
 *     0x1ec048 颜色拆成 4 块缓冲          0x1ec0b4 4 个 yyMatrix 装配
 *     0x1ec100 SetZRotation              0x1ec1d0 3 次 Multiply
 *     0x1ec1f8 固定 UV 矩阵 + 帧表 + alloca
 *     0x1ec2ac 逐子项：状态进→DrawSWFObject→状态出（三个调用点 1ec370/1ec4d4/1ec654）
 *     0x1ec42c 按深度插入排序（边排边画）  0x1ec5c0 按排好的数组整表重画
 *     0x1ec664 还原 8 个状态              0x1ec6ec canary 校验 + 返回
 */

/* ── 序言：帧 712、r11 = 入口 sp−4、形参落位、两道守卫、栈保护 ─────────────────
 *   push 36 + vpush {d8} 8 = 44；add r11, sp, #40 ⇒ r11 = 入口 sp − 4；sub 668 ⇒ 帧 712。
 *   于是 7 个栈形参正好落在 [r11, #4] .. [r11, #0x1c]（见卡片头的落位表）。
 *   r4 = i（后面 1ec014 拿去 idivmod）、s16 = ox（r2）、[r11-0x2ac] = oy（r3）、r7 = colour。
 *   ★ this 先落 [r11-0x264]，之后每次要用都从栈上重读（-O2 下的寄存器压力证据）。
 *   ★ GOT 基址 0x3f1c58 由池字 0x00205d30 + pc(1ebf28) 算出，存 [r11-0x28c] 复用；
 *     DrawShape 用同一个基址（0x1edbec 的 0x002044cc + pc=1ed78c）。
 */

/* @0x1ebf08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ebf0c vpush {d8} */
/* @0x1ebf10 add r11, sp, #40 */
/* @0x1ebf14 ldr r12, [pc, #0x3a4] */
/* @0x1ebf18 sub sp, sp, #668 */
/* @0x1ebf1c str r0, [r11, #-0x264] */
/* @0x1ebf20 add r12, pc, r12 */
/* @0x1ebf24 str r12, [r11, #-0x28c] */
/* @0x1ebf28 ldr r12, [r11, #-0x264] */
/* @0x1ebf2c mov r4, r1 */
/* @0x1ebf30 ldr r0, [pc, #0x38c] */
/* @0x1ebf34 vmov s16, r2 */
/* @0x1ebf38 ldr r7, [r11, #0x18] */
/* @0x1ebf3c ldr r1, [r12, #0x7c] */
/* @0x1ebf40 ldr r12, [r11, #-0x28c] */
/* ── 守卫与 canary：this+0x7c / this+0x84 任一为 0 就纯返回 ────────────────────
 *   目标都是 0x1ec6ec（canary 校验 + 恢复 + pop），即「什么都没做」。
 *   0x3ed958（池字 0xffffbd00）= __stack_chk_guard 的 GOT 槽（同 DoReplace.c 已定名的那一条）：
 *   先存 guard 指针 [r11-0x290]、再存 (*guard) [r11-0x30]，出口重读两者比较。
 *   ★ 1ebf48/4c/50/54 是 cmp 之后、beq 之前的投机搬运（ldr 不改标志），返回分支也会执行。
 *   ★ 这两道守卫与 DrawShape 1ed788/1ed79c 是同一对字段：+0x7c = 显示对象指针数组
 *     （DrawShape 1edda8 起按 [entry+4] == id 线性查）、+0x84 = 影片/时间线（本函数 1ec008 读 +0x18 当帧数）。
 */

/* @0x1ebf44 cmp r1, #0 */
/* @0x1ebf48 ldr r0, [r12, r0] */
/* @0x1ebf4c ldr r1, [r0] */
/* @0x1ebf50 str r0, [r11, #-0x290] */
/* @0x1ebf54 str r1, [r11, #-0x30] */
/* @0x1ebf58 beq 0x1ec6ec <_ZN7CSprite7DrawSWFEifffffffjf+0x7e4> */
/* @0x1ebf5c ldr r12, [r11, #-0x264] */
/* @0x1ebf60 ldr r1, [r12, #0x84] */
/* @0x1ebf64 cmp r1, #0 */
/* @0x1ebf68 beq 0x1ec6ec <_ZN7CSprite7DrawSWFEifffffffjf+0x7e4> */
/* ── 进函数先存 8 个状态：2 采样器 + 6 渲染状态 ────────────────────────────────
 *   r5 = *GOT 0x3edd00（.bss 单例指针，直接当 RenderStateManager 的 this 传，不是对象本体）。
 *   GetSamplerState(0,2)→-0x294  (0,3)→-0x298
 *   GetRenderState(30)→-0x29c  (25)→-0x2a0  (29)→-0x2a4  (28)→-0x2a8  (24)→-0x280  (4)→-0x284
 *   还原（1ec664..1ec6e8）顺序一致：采样器 2/3 先还原，再 30,25,29,28,24,4。
 *   ⇒ 本函数的绘制窗口固定是「25=1 / 29=8 / 28=7 / 24=0 / 4=0」，退出前逐项还原。
 *     这是它与纹理档最大的一处行为差别：纹理档只把 colour/alpha 交给 GR，状态全由调用方掌控；
 *     本函数自己改状态、自己还原，因此**不依赖调用方的状态约定**。
 */

/* @0x1ebf6c ldr r12, [r11, #-0x28c] */
/* @0x1ebf70 mov r1, #0 */
/* @0x1ebf74 ldr r0, [pc, #0x34c] */
/* @0x1ebf78 mov r2, #2 */
/* @0x1ebf7c ldr r5, [r12, r0] */
/* @0x1ebf80 str r3, [r11, #-0x2ac] */
/* @0x1ebf84 mov r0, r5 */
/* @0x1ebf88 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1ebf8c mov r2, #3 */
/* @0x1ebf90 mov r1, #0 */
/* @0x1ebf94 str r0, [r11, #-0x294] */
/* @0x1ebf98 mov r0, r5 */
/* @0x1ebf9c bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1ebfa0 mov r1, #30 */
/* @0x1ebfa4 str r0, [r11, #-0x298] */
/* @0x1ebfa8 mov r0, r5 */
/* @0x1ebfac bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebfb0 mov r1, #25 */
/* @0x1ebfb4 str r0, [r11, #-0x29c] */
/* @0x1ebfb8 mov r0, r5 */
/* @0x1ebfbc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebfc0 mov r1, #29 */
/* @0x1ebfc4 str r0, [r11, #-0x2a0] */
/* @0x1ebfc8 mov r0, r5 */
/* @0x1ebfcc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebfd0 mov r1, #28 */
/* @0x1ebfd4 str r0, [r11, #-0x2a4] */
/* @0x1ebfd8 mov r0, r5 */
/* @0x1ebfdc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebfe0 mov r1, #24 */
/* @0x1ebfe4 str r0, [r11, #-0x2a8] */
/* @0x1ebfe8 mov r0, r5 */
/* @0x1ebfec bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebff0 mov r1, #4 */
/* @0x1ebff4 str r0, [r11, #-0x280] */
/* @0x1ebff8 mov r0, r5 */
/* @0x1ebffc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* ── 帧号归一化 + alpha 覆盖 colour 的高字节 ──────────────────────────────────
 *   r6 = *(*(this+0x84) + 0x18) = 时间线帧数；i % 帧数（__aeabi_idivmod，余数在 r1），
 *   负数补回（subs r4,r1,#0 / addlt r4,r4,r6）—— 与纹理档 1ec778..1ec794 的子图取模逐条同构。
 *   alpha：s15 = 池字 0x1ec2bc = 255.0f；255·alpha → vcvt.s32.f32 → r3
 *     r3 > 255 → r12 = 0xFF000000（movgt r12,#-16777216）
 *     r3 ≤ 255 → 0x1ec70c：r3 ≥ 0 时 r12 = r3<<24，r3 < 0 时 r12 = 0
 *   1ec048 bic lr, r7, #0xFF000000（lr = colour & 0x00FFFFFF）、1ec050 orr r12, r12, lr
 *   ⇒ 最终色 = (clamp(alpha·255,0,255) << 24) | (colour & 0x00FFFFFF)
 *   ★ 硬差别：Draw 把 colour/alpha 原样交给 GR_Texture_Draw（含调用方的透明度语义）；
 *     本函数**丢弃 colour 的 alpha 字节**，只用最后的 float 形参。DrawSimple 走这条路时
 *     把 alpha 写死 1.0f（1ecd10 的 str r12 是 0x3F800000）⇒ 恒 0xFF 不透明，与纹理档一致地不透明。
 */

/* @0x1ec000 ldr r12, [r11, #-0x264] */
/* @0x1ec004 ldr r2, [r12, #0x84] */
/* @0x1ec008 ldr r6, [r2, #0x18] */
/* @0x1ec00c mov r1, r6 */
/* @0x1ec010 str r0, [r11, #-0x284] */
/* @0x1ec014 mov r0, r4 */
/* @0x1ec018 bl 0x318dec <__aeabi_idivmod> */
/* @0x1ec01c vldr s15, [pc, #664] */
/* @0x1ec020 vldr s12, [r11, #28] */
/* @0x1ec024 vmul.f32 s15, s12, s15 */
/* @0x1ec028 ldr r3, [r11, #-0x2ac] */
/* @0x1ec02c vcvt.s32.f32 s15, s15 */
/* @0x1ec030 vmov r12, s15 */
/* @0x1ec034 subs r4, r1, #0 */
/* @0x1ec038 addlt r4, r4, r6 */
/* @0x1ec03c cmp r12, #255 */
/* @0x1ec040 movgt r12, #-16777216 */
/* @0x1ec044 ble 0x1ec70c <_ZN7CSprite7DrawSWFEifffffffjf+0x804> */
/* ── 颜色拆成四块缓冲（两个打包值 + 两组 4×int 通道），按指针交给 DrawSWFObject ───
 *   打包：-0x258 = colour'（ARGB）               → 第 5 形参 Pj
 *         -0x254 = colour & 0x00FFFFFF（RGB）    → 第 7 形参 Pj
 *   通道一（基址 -0x250）：-0x250=uxtb(c')=B  -0x24c=ubfx(c',8,8)=G  -0x248=ubfx(c',16,8)=R  -0x244=c'>>24=A
 *   通道二（基址 -0x240）：-0x240=uxtb(colour)=B  -0x23c=(colour&0xFFFFFF)>>8=G
 *                          -0x238=(colour&0xFFFFFF)>>16=R  -0x234=0
 *   ⇒ 同一个颜色被拆成「带 alpha」与「不带 alpha（A 恒 0）」两套；每套是 4 个 int（不是 4 个 byte），
 *     一共 16 B，与 DrawSWFObject 的 4 个 uint* 形参一一对应（1ec338 的 [sp]/[4]/[8]/[0xc]）。
 *   ★ 这套「打包 + 逐通道」双份缓冲是 SWF 矢量管线要的输入形态，纹理档完全没有对应物。
 */

/* @0x1ec048 bic lr, r7, #-16777216 */
/* @0x1ec04c sub r6, r11, #496 */
/* @0x1ec050 orr r12, r12, lr */
/* @0x1ec054 ldr r1, [r11, #0x14] */
/* @0x1ec058 mov r0, r6 */
/* @0x1ec05c mov r9, #0 */
/* @0x1ec060 mov r10, #1065353216 */
/* @0x1ec064 vldr s13, [r11, #4] */
/* @0x1ec068 vldr s14, [r11, #8] */
/* @0x1ec06c uxtb r7, r7 */
/* @0x1ec070 vstr s13, [r11, #-512] */
/* @0x1ec074 vstr s14, [r11, #-508] */
/* @0x1ec078 str r12, [r11, #-0x258] */
/* @0x1ec07c mov r8, #0 */
/* @0x1ec080 str lr, [r11, #-0x254] */
/* @0x1ec084 add r4, r4, r4, lsl #1 */
/* @0x1ec088 str r7, [r11, #-0x240] */
/* @0x1ec08c uxtb r7, r12 */
/* @0x1ec090 str r3, [r11, #-0x2ac] */
/* @0x1ec094 str r7, [r11, #-0x250] */
/* @0x1ec098 ubfx r7, r12, #0x8, #0x8 */
/* @0x1ec09c str r10, [r11, #-0x1f4] */
/* @0x1ec0a0 str r7, [r11, #-0x24c] */
/* @0x1ec0a4 ubfx r7, r12, #0x10, #0x8 */
/* @0x1ec0a8 str r10, [r11, #-0x208] */
/* @0x1ec0ac lsr r12, r12, #24 */
/* @0x1ec0b0 str r7, [r11, #-0x248] */
/* ── 4 个 64 B 的 yyMatrix 块装配（-0x230/-0x1f0/-0x1b0/-0x170）─────────────────
 *   恒等装配是逐元素的：1.0f（r10 = 0x3F800000）写 e0/e5/e10/e15，其余 12 个元素写 0（r9 = 0）。
 *   ★ 寄存器复用的一处坑：1ec610 str r5,[r11-0x260] / 1ec618 mov r5,r7 / 1ec660 ldr r5,[r11-0x260]
 *     是**把 RSM 指针 r5 暂存**（r5 被借去当 z 序数组游标），与矩阵内容无关。
 *   ★ 块基址间隔 64 B，全部 r11 相对 ⇒ 全部是栈上局部，符合 "yyMatrix = 16×float = 64 B"。
 */

/* @0x1ec0b4 sub r7, r11, #304 */
/* @0x1ec0b8 str r12, [r11, #-0x244] */
/* @0x1ec0bc ubfx r12, lr, #0x8, #0x8 */
/* @0x1ec0c0 str r10, [r11, #-0x21c] */
/* @0x1ec0c4 lsr lr, lr, #16 */
/* @0x1ec0c8 str r12, [r11, #-0x23c] */
/* @0x1ec0cc str lr, [r11, #-0x238] */
/* @0x1ec0d0 str r10, [r11, #-0x230] */
/* @0x1ec0d4 str r8, [r11, #-0x234] */
/* @0x1ec0d8 str r9, [r11, #-0x204] */
/* @0x1ec0dc str r9, [r11, #-0x20c] */
/* @0x1ec0e0 str r9, [r11, #-0x210] */
/* @0x1ec0e4 str r9, [r11, #-0x214] */
/* @0x1ec0e8 str r9, [r11, #-0x218] */
/* @0x1ec0ec str r9, [r11, #-0x220] */
/* @0x1ec0f0 str r9, [r11, #-0x224] */
/* @0x1ec0f4 str r9, [r11, #-0x228] */
/* @0x1ec0f8 str r9, [r11, #-0x22c] */
/* @0x1ec0fc str r9, [r11, #-0x1f8] */
/* ── SetZRotation(rot)：旋转块基址 -0x1f0，rot 是第 5 个栈 float（[r11+0x14]）────────
 *   ⚠ 这里 rot 是**角度原样**：两张 literal pool 里都没有 π/180 的常量
 *     （0x40490fdb / 0x43340000 只出现在纹理档 0x1eca7c/0x1eca80）。
 *     与本卡头部第 ③ 条差异互证：CSprite::Draw 在 1ec7e0/1ec7e8 先跳去 SWF/骨骼分支，
 *     1ec7f0 的「乘 π 除 180」只服务纹理两路。
 */

/* @0x1ec100 bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f> */
/* @0x1ec104 ldr r3, [r11, #-0x2ac] */
/* @0x1ec108 vneg.f32 s14, s16 */
/* @0x1ec10c ldr r12, [r11, #-0x28c] */
/* @0x1ec110 mov r0, r7 */
/* @0x1ec114 ldr r2, [pc, #0x1b0] */
/* @0x1ec118 sub r1, r11, #432 */
/* @0x1ec11c vmov s12, r3 */
/* @0x1ec120 vneg.f32 s13, s12 */
/* @0x1ec124 ldr r2, [r12, r2] */
/* @0x1ec128 vldr s15, [r2] */
/* @0x1ec12c vldr s12, [r11, #12] */
/* @0x1ec130 str r10, [r11, #-0x174] */
/* @0x1ec134 sub r2, r11, #368 */
/* @0x1ec138 str r10, [r11, #-0x188] */
/* @0x1ec13c sub r12, r11, #176 */
/* @0x1ec140 vdiv.f32 s14, s14, s15 */
/* @0x1ec144 str r10, [r11, #-0x19c] */
/* @0x1ec148 str r10, [r11, #-0x1b0] */
/* @0x1ec14c str r9, [r11, #-0x184] */
/* @0x1ec150 str r9, [r11, #-0x18c] */
/* @0x1ec154 str r9, [r11, #-0x190] */
/* @0x1ec158 str r9, [r11, #-0x194] */
/* @0x1ec15c str r9, [r11, #-0x198] */
/* @0x1ec160 str r9, [r11, #-0x1a0] */
/* @0x1ec164 str r9, [r11, #-0x1a4] */
/* @0x1ec168 str r9, [r11, #-0x1a8] */
/* @0x1ec16c str r9, [r11, #-0x1ac] */
/* @0x1ec170 str r9, [r11, #-0x178] */
/* @0x1ec174 str r10, [r11, #-0x134] */
/* @0x1ec178 str r10, [r11, #-0x148] */
/* @0x1ec17c str r9, [r11, #-0x138] */
/* @0x1ec180 str r9, [r11, #-0x13c] */
/* @0x1ec184 str r9, [r11, #-0x140] */
/* @0x1ec188 str r9, [r11, #-0x144] */
/* @0x1ec18c str r9, [r11, #-0x14c] */
/* @0x1ec190 str r9, [r11, #-0x150] */
/* @0x1ec194 str r9, [r11, #-0x154] */
/* @0x1ec198 str r9, [r11, #-0x158] */
/* @0x1ec19c str r9, [r11, #-0x160] */
/* @0x1ec1a0 str r9, [r11, #-0x164] */
/* @0x1ec1a4 str r9, [r11, #-0x168] */
/* @0x1ec1a8 str r9, [r11, #-0x16c] */
/* @0x1ec1ac vdiv.f32 s13, s13, s15 */
/* ── 平移/缩放写进 A、B 两块：e12/e13 = −ox/g、−oy/g；e0/e5 = g·xs、g·ys ────────
 *   g = *GOT 0x3f0ddc（池字 0xfffff184，float；同一条 GOT 槽在 DrawShape 1ed938 也被读）。
 *   A 基址 -0x1b0（1ec1b0/1ec1b8 写 -0x180/-0x17c = e12/e13）
 *   B 基址 -0x170（1ec1c8/1ec1cc 写 -0x170/-0x15c = e0/e5）
 *   ⇒ 原点做**除法**、缩放做**乘法**，同一个 g 两个方向用 ⇒ g 是「全局单位换算」类常量
 *     （像素↔局部）。★ 这条是 DrawSWF 与纹理档在几何上唯一不可替代的差别：
 *     纹理档把 ox/oy 当形参交给 GR_Texture_Draw，由 GR 去减；这里必须自己除 g 再进矩阵。
 */

/* @0x1ec1b0 vstr s14, [r11, #-384] */
/* @0x1ec1b4 vmul.f32 s14, s15, s12 */
/* @0x1ec1b8 vstr s13, [r11, #-380] */
/* @0x1ec1bc vldr s13, [r11, #16] */
/* @0x1ec1c0 str r12, [r11, #-0x268] */
/* @0x1ec1c4 vmul.f32 s15, s15, s13 */
/* @0x1ec1c8 vstr s14, [r11, #-368] */
/* @0x1ec1cc vstr s15, [r11, #-348] */
/* ── 三次 yyMatrix::Multiply(dest, a, b) ───────────────────────────────────────
 *   1) Multiply(-0x130, -0x1b0 A, -0x170 B)   → M1 = A·B      （T(−origin/g) · S(g·scale)）
 *   2) Multiply(-0xF0,  -0x130 M1, -0x1f0 R)  → M2 = M1·R     （· Rz(rot)）
 *   3) Multiply(-0xB0,  -0xF0  M2, -0x230 D)  → M3 = M2·D     （· T(x, y)）
 *   交给 DrawSWFObject 的 r2 = -0xB0（M3）、r3 = -0x70（固定 UV 矩阵，见 1ec1f8）。
 *   ⚠ 行/列向量约定未证：只能确定实参次序（dest, a, b）与嵌套关系；
 *     「先平移后旋转再缩放」还是「先缩放再旋转后平移」取决于 Multiply 内部是 a·b 还是 b·a。
 *     元素级证据（e12/e13 承平移、e0/e5 承缩放、e15 恒 1）与列主序 4×4 完全自洽。
 */

/* @0x1ec1d0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ec1d4 mov r2, r6 */
/* @0x1ec1d8 sub r6, r11, #240 */
/* @0x1ec1dc mov r1, r7 */
/* @0x1ec1e0 mov r0, r6 */
/* @0x1ec1e4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ec1e8 mov r1, r6 */
/* @0x1ec1ec sub r0, r11, #176 */
/* @0x1ec1f0 sub r2, r11, #560 */
/* @0x1ec1f4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* ── 固定矩阵块 -0x70：给 DrawSWFObject 的第 4 形参（「退化 UV」矩阵）──────────
 *   e0 = e5 = 0x38000000（2^−128 ≈ 0，用非零值避开非规格化数）、e10 = e15 = 1.0f、
 *   e12 = e13 = 0.5f，其余 8 个元素 = 0。
 *   ⇒ 几何缩放压到 ~0、平移给 0.5 ⇒ 等价于「所有 UV 收到 (0.5,0.5) 这一个 texel」。
 *   ★ 三个 DrawSWFObject 调用点（1ec370 / 1ec4d4 / 1ec654）都用这个固定块，
 *     所以本函数里**没有任何按帧/子图选择 UV 或贴图的指令**（对比纹理档 1ec804 的 tpe 索引）。
 *   ★ 顺带一处：1ec1fc/1ec200 的 mov r1,#939524096 / mov r0,#1056964608 就是这两个常量
 *     （0x38000000 / 0x3F000000），不是随机字面量。
 */

/* @0x1ec1f8 ldr r12, [r11, #-0x264] */
/* @0x1ec1fc mov r1, #939524096 */
/* @0x1ec200 mov r0, #1056964608 */
/* @0x1ec204 str r10, [r11, #-0x34] */
/* ── 帧表取项 + alloca（子项 z 序表）────────────────────────────────────────────
 *   r1 = *(this+0x84)（帧表基址），r2 = 帧号×8 ⇒ r12 = 基址 + 帧号×8；[r12+0x14] = 子项数 n。
 *   alloca 大小 = (4n + 14) & ~7；数组基址 r7 = 新 sp + 24；元素是子项指针（1ec2e0 的 str …[r7,r8,lsl #2]）。
 *   ⚠ 步长与记录大小不自洽（open）：后续 1ec3e0..1ec410 把 [r12+0x14] 当子项数、[r12+0x00] 当子项
 *     数组首址，而单个子项是 144 B（1ec408 add r10,r0,r0,lsl #3 再 lsl #4 = ×144）⇒ 帧记录至少 0x18 B，
 *     但这里的索引步长是 ×8。可能 *(this+0x84) 指向的是「句柄/指针数组」而不是帧记录数组，
 *     也可能 i 的单位不是帧号。此处不影响后文的排序与绘制结论。
 *   ★ 1ec26c 是本函数唯一的 sp 动态下移；出口 1ec700 用 sub sp, r11, #40 精确还原（不依赖 alloca 大小）。
 */

/* @0x1ec208 lsl r2, r4, #3 */
/* @0x1ec20c ldr r3, [r12, #0x84] */
/* @0x1ec210 str r10, [r11, #-0x48] */
/* @0x1ec214 str r9, [r11, #-0x38] */
/* @0x1ec218 str r9, [r11, #-0x44] */
/* @0x1ec21c str r9, [r11, #-0x4c] */
/* @0x1ec220 str r9, [r11, #-0x50] */
/* @0x1ec224 str r9, [r11, #-0x54] */
/* @0x1ec228 str r9, [r11, #-0x58] */
/* @0x1ec22c str r0, [r11, #-0x40] */
/* @0x1ec230 str r0, [r11, #-0x3c] */
/* @0x1ec234 str r1, [r11, #-0x5c] */
/* @0x1ec238 str r9, [r11, #-0x60] */
/* @0x1ec23c str r9, [r11, #-0x64] */
/* @0x1ec240 str r9, [r11, #-0x68] */
/* @0x1ec244 str r9, [r11, #-0x6c] */
/* @0x1ec248 str r1, [r11, #-0x70] */
/* @0x1ec24c ldr r1, [r3] */
/* @0x1ec250 add r12, r1, r2 */
/* @0x1ec254 str r12, [r11, #-0x288] */
/* @0x1ec258 ldr r3, [r12, #0x14] */
/* @0x1ec25c cmp r3, r8 */
/* @0x1ec260 lsl r3, r3, #2 */
/* @0x1ec264 add r3, r3, #14 */
/* @0x1ec268 bic r3, r3, #7 */
/* @0x1ec26c sub sp, sp, r3 */
/* @0x1ec270 add r7, sp, #24 */
/* @0x1ec274 ble 0x1ec664 <_ZN7CSprite7DrawSWFEifffffffjf+0x75c> */
/* @0x1ec278 mov r12, #1 */
/* @0x1ec27c ldr r10, [r1, r2] */
/* @0x1ec280 sub r3, r11, #112 */
/* @0x1ec284 sub r0, r11, #600 */
/* @0x1ec288 str r3, [r11, #-0x26c] */
/* @0x1ec28c sub r1, r11, #592 */
/* @0x1ec290 sub r2, r11, #596 */
/* @0x1ec294 sub r3, r11, #576 */
/* @0x1ec298 str r8, [r11, #-0x260] */
/* @0x1ec29c str r0, [r11, #-0x270] */
/* @0x1ec2a0 str r1, [r11, #-0x274] */
/* @0x1ec2a4 str r2, [r11, #-0x278] */
/* @0x1ec2a8 str r3, [r11, #-0x27c] */
/* ── 逐子项：进绘制状态 → DrawSWFObject → 出绘制状态 ──────────────────────────
 *   进（1ec2d4..1ec328）：SetRenderState(25,1)、(29,8)、(28,7)、(24,0)、(4,0)
 *   出（1ec398..1ec3d8，仅当该子项 [子项+0xc] > 0 时）：(30,序号)、(29,3)、(28,1)、(24,保存值)、(4,保存值)
 *   ★ 29/28 的 (8,7) 与 (3,1) 是两对固定组合，24/4 一出窗口就还原成进函数时的值。
 *   ★ 1ec2b4 的 ble 0x1ec574 是本帧「没有子项」的出口，直接去收尾。
 */

/* @0x1ec2ac ldr r3, [r10, #0xc] */
/* @0x1ec2b0 cmp r3, #0 */
/* @0x1ec2b4 ble 0x1ec574 <_ZN7CSprite7DrawSWFEifffffffjf+0x66c> */
/* @0x1ec2b8 b 0x1ec2d4 <_ZN7CSprite7DrawSWFEifffffffjf+0x3cc> */
/* ── literal pool（0x1ec2bc..0x1ec2d0，6 字；objdump 把前两个字译成了指令）──────
 *   0x1ec2bc 0x437f0000 = 255.0f（alpha 归一，1ec01c 用）
 *   0x1ec2c0 0x00205d30 GOT 基址加数（pc 1ebf28 ⇒ 0x3f1c58）
 *   0x1ec2c4 0xffffbd00 → GOT 0x3ed958 = __stack_chk_guard
 *   0x1ec2c8 0xffffc0a8 → GOT 0x3edd00 = RenderStateManager 单例指针
 *   0x1ec2cc 0xfffff184 → GOT 0x3f0ddc = 全局 float g（T 里除、S 里乘）
 *   0x1ec2d0 0xffffc978 → GOT 0x3ee5d0 = 全局字节开关（唯一一处 1ec59c 读，作 bool 传下去）
 *   ★ 6 个字全被用到（1ec01c/1ebf14/1ebf30/1ebf74/1ec114/1ec58c），没有废字。
 *   ★ 只有 1 个全局 float + 1 个全局 byte ⇒ 本函数对绘制全局的依赖面极小。
 */

/* @0x1ec2bc cmnmi pc, #0 */
/* @0x1ec2c0 eoreq r5, r0, r0, lsr sp */
/* @0x1ec2c4 .word 0xffffbd00 */
/* @0x1ec2c8 .word 0xffffc0a8 */
/* @0x1ec2cc .word 0xfffff184 */
/* @0x1ec2d0 .word 0xffffc978 */
/* ── 进绘制状态 + 第一次 DrawSWFObject（z 序数组里定位到的那个子项）───────────────
 *   1ec2d4 序列：SetRenderState(25,1) → (29,8) → (28,7) → (24,0) → (4,0)。
 *   1ec2e0 str r10,[r7,r8,lsl #2] 把子项指针写进 alloca 数组的第 r8 格（r8 从 0 递增）。
 *   1ec2ac 是这轮循环的头（1ec2d4 由 1ec414 的 beq 与 1ec570 的 bgt 回来）。
 */

/* @0x1ec2d4 mov r0, r5 */
/* @0x1ec2d8 mov r1, #25 */
/* @0x1ec2dc mov r2, #1 */
/* @0x1ec2e0 str r10, [r7, r8, lsl #2] */
/* @0x1ec2e4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec2e8 mov r0, r5 */
/* @0x1ec2ec mov r1, #29 */
/* @0x1ec2f0 mov r2, #8 */
/* @0x1ec2f4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec2f8 mov r0, r5 */
/* @0x1ec2fc mov r1, #28 */
/* @0x1ec300 mov r2, #7 */
/* @0x1ec304 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec308 mov r0, r5 */
/* @0x1ec30c mov r1, #24 */
/* @0x1ec310 mov r2, #0 */
/* @0x1ec314 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec318 mov r2, #0 */
/* @0x1ec31c mov r0, r5 */
/* @0x1ec320 mov r1, #4 */
/* @0x1ec324 str r2, [r11, #-0x2ac] */
/* @0x1ec328 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec32c ldr r12, [r11, #-0x2ac] */
/* @0x1ec330 add r8, r8, #1 */
/* @0x1ec334 mov lr, r12 */
/* ── DrawSWFObject(this, 子项, M3, 固定矩阵, &ARGB, &通道1, &RGB, &通道2, bool) ───
 *   _ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b = 8 显式（含 this 9）：
 *   r0=this r1=子项 r2=-0xB0(M3) r3=-0x70(固定 UV)，栈 [0]=-0x258 [4]=-0x250 [8]=-0x254 [0xc]=-0x240
 *   [0x10]=bool。
 *   三个调用点只有 bool 不同：
 *     1ec370 → 0x1ec59c ldrb lr,[*GOT 0x3ee5d0]（全局字节）
 *     1ec4d4 → 0（1ec4bc mov r3,#0 / str [sp,#0x10]）
 *     1ec654 → 0（1ec650 str r4,[sp,#0x10]，r4 恒 0）
 *   ⇒ 同一个「全局字节开关」在 DrawShape 里当图形通道开关（1ede24），在这里当第 8 形参。
 */

/* @0x1ec338 sub r1, r11, #600 */
/* @0x1ec33c sub r2, r11, #592 */
/* @0x1ec340 str r1, [sp] */
/* @0x1ec344 sub r3, r11, #596 */
/* @0x1ec348 str r2, [sp, #0x4] */
/* @0x1ec34c mov r1, r10 */
/* @0x1ec350 str r3, [sp, #0x8] */
/* @0x1ec354 sub r2, r11, #176 */
/* @0x1ec358 sub r3, r11, #576 */
/* @0x1ec35c ldr r0, [r11, #-0x264] */
/* @0x1ec360 str r3, [sp, #0xc] */
/* @0x1ec364 sub r3, r11, #112 */
/* @0x1ec368 str lr, [sp, #0x10] */
/* @0x1ec36c str r12, [r11, #-0x2ac] */
/* @0x1ec370 bl 0x1eba90 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b> */
/* @0x1ec374 ldr r3, [r10, #0xc] */
/* @0x1ec378 ldr r12, [r11, #-0x2ac] */
/* @0x1ec37c cmp r3, #0 */
/* @0x1ec380 ble 0x1ec3e0 <_ZN7CSprite7DrawSWFEifffffffjf+0x4d8> */
/* @0x1ec384 mov r0, r5 */
/* @0x1ec388 mov r1, #30 */
/* @0x1ec38c mov r2, r8 */
/* @0x1ec390 mov r12, #1 */
/* @0x1ec394 str r12, [r11, #-0x2ac] */
/* @0x1ec398 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec39c mov r0, r5 */
/* @0x1ec3a0 mov r1, #29 */
/* @0x1ec3a4 mov r2, #3 */
/* @0x1ec3a8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec3ac mov r0, r5 */
/* @0x1ec3b0 mov r1, #28 */
/* @0x1ec3b4 mov r2, #1 */
/* @0x1ec3b8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec3bc mov r0, r5 */
/* @0x1ec3c0 mov r1, #24 */
/* @0x1ec3c4 ldr r2, [r11, #-0x280] */
/* @0x1ec3c8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec3cc mov r0, r5 */
/* @0x1ec3d0 mov r1, #4 */
/* @0x1ec3d4 ldr r2, [r11, #-0x284] */
/* @0x1ec3d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec3dc ldr r12, [r11, #-0x2ac] */
/* ── 取下一个子项 / 深度比较（排序键 [子项+0xc]）────────────────────────────────
 *   1ec3e4 把子项下标 +1；1ec3e8 重读子项数 [帧+0x14]；1ec3f4 越界 → 1ec5c0（收尾）。
 *   1ec408 add r10, r0, r0, lsl #3 → 下标×9；1ec410 再 lsl #4 ⇒ **子项步长 144 B**，
 *   子项数组首址 = [帧+0x00]（1ec40c ldr r3,[r1]）。
 *   1ec418 取 [子项+0x8]（排序比较的右值），1ec420/1ec424 把 r4（已放置数）与 r8（计数）对齐。
 */

/* @0x1ec3e0 ldr r0, [r11, #-0x288] */
/* @0x1ec3e4 ldr r1, [r11, #-0x260] */
/* @0x1ec3e8 ldr r3, [r0, #0x14] */
/* @0x1ec3ec add r1, r1, #1 */
/* @0x1ec3f0 str r1, [r11, #-0x260] */
/* @0x1ec3f4 cmp r3, r1 */
/* @0x1ec3f8 ble 0x1ec5c0 <_ZN7CSprite7DrawSWFEifffffffjf+0x6b8> */
/* @0x1ec3fc ldr r0, [r11, #-0x260] */
/* @0x1ec400 cmp r8, #0 */
/* @0x1ec404 ldr r1, [r11, #-0x288] */
/* @0x1ec408 add r10, r0, r0, lsl #3 */
/* @0x1ec40c ldr r3, [r1] */
/* @0x1ec410 add r10, r3, r10, lsl #4 */
/* @0x1ec414 beq 0x1ec2ac <_ZN7CSprite7DrawSWFEifffffffjf+0x3a4> */
/* @0x1ec418 ldr r1, [r10, #0x8] */
/* @0x1ec41c mov r4, #0 */
/* @0x1ec420 mov r6, r4 */
/* @0x1ec424 mov r9, r8 */
/* @0x1ec428 mov r2, r12 */
/* ── 插入排序：按 [子项+0xc] 找位置，边排边画 ────────────────────────────────
 *   1ec42c 顺着已排好的前缀线性扫描：r8 = 数组[r6]、r3 = [r8+0xc]（深度），
 *   与 1ec418 取来的 [子项+0x8] 比较；`blt` 严格小于才认定「已到插入点」⇒ **同深度保持原序**。
 *   命中点若还有余量就整段右移一格（1ec53c 的 str r2,[r3],#4 循环），把该子项插回前缀。
 *   ⚠ 精确的「是否会把同一子项画两次」取决于 1ec4d4 与 1ec654 两处调用在相邻迭代里的重叠，
 *     本条只证「排序键 = +0xc、比较用 blt、数组元素 = 子项指针、搬移是 +4 步长」。
 *   ★ 1ec454..1ec498 是 (29,8)(28,8)(24,0)(4,0) 进窗口，1ec488 先 sub r9,r9,#1，
 *     1ec4d4 调 DrawSWFObject，1ec4d8..1ec524 出窗口 (30, r9)(29,3)(28,1)(24,保存)(4,保存)。
 */

/* @0x1ec42c ldr r8, [r7, r6] */
/* @0x1ec430 add r12, r7, r6 */
/* @0x1ec434 ldr r3, [r8, #0xc] */
/* @0x1ec438 cmp r3, r1 */
/* @0x1ec43c blt 0x1ec454 <_ZN7CSprite7DrawSWFEifffffffjf+0x54c> */
/* @0x1ec440 add r4, r4, #1 */
/* @0x1ec444 cmp r4, r9 */
/* @0x1ec448 bge 0x1ec560 <_ZN7CSprite7DrawSWFEifffffffjf+0x658> */
/* @0x1ec44c lsl r6, r4, #2 */
/* @0x1ec450 b 0x1ec42c <_ZN7CSprite7DrawSWFEifffffffjf+0x524> */
/* @0x1ec454 mov r0, r5 */
/* @0x1ec458 mov r1, #29 */
/* @0x1ec45c mov r2, #8 */
/* @0x1ec460 str r12, [r11, #-0x2ac] */
/* @0x1ec464 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec468 mov r0, r5 */
/* @0x1ec46c mov r1, #28 */
/* @0x1ec470 mov r2, #8 */
/* @0x1ec474 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec478 mov r0, r5 */
/* @0x1ec47c mov r1, #24 */
/* @0x1ec480 mov r2, #0 */
/* @0x1ec484 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec488 sub r9, r9, #1 */
/* @0x1ec48c mov r0, r5 */
/* @0x1ec490 mov r1, #4 */
/* @0x1ec494 mov r2, #0 */
/* @0x1ec498 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec49c sub r2, r11, #600 */
/* @0x1ec4a0 sub r3, r11, #592 */
/* @0x1ec4a4 str r2, [sp] */
/* @0x1ec4a8 str r3, [sp, #0x4] */
/* @0x1ec4ac mov r1, r8 */
/* @0x1ec4b0 sub r0, r11, #596 */
/* @0x1ec4b4 sub r2, r11, #576 */
/* @0x1ec4b8 str r0, [sp, #0x8] */
/* @0x1ec4bc mov r3, #0 */
/* @0x1ec4c0 str r2, [sp, #0xc] */
/* @0x1ec4c4 sub r2, r11, #176 */
/* @0x1ec4c8 str r3, [sp, #0x10] */
/* @0x1ec4cc sub r3, r11, #112 */
/* @0x1ec4d0 ldr r0, [r11, #-0x264] */
/* @0x1ec4d4 bl 0x1eba90 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b> */
/* @0x1ec4d8 mov r2, r9 */
/* @0x1ec4dc mov r0, r5 */
/* @0x1ec4e0 mov r1, #30 */
/* @0x1ec4e4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec4e8 mov r0, r5 */
/* @0x1ec4ec mov r1, #29 */
/* @0x1ec4f0 mov r2, #3 */
/* @0x1ec4f4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec4f8 mov r0, r5 */
/* @0x1ec4fc mov r1, #28 */
/* @0x1ec500 mov r2, #1 */
/* @0x1ec504 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec508 mov r0, r5 */
/* @0x1ec50c mov r1, #24 */
/* @0x1ec510 ldr r2, [r11, #-0x280] */
/* @0x1ec514 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec518 mov r0, r5 */
/* @0x1ec51c mov r1, #4 */
/* @0x1ec520 ldr r2, [r11, #-0x284] */
/* @0x1ec524 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec528 cmp r9, r4 */
/* @0x1ec52c ldr r12, [r11, #-0x2ac] */
/* @0x1ec530 ble 0x1ec5a4 <_ZN7CSprite7DrawSWFEifffffffjf+0x69c> */
/* @0x1ec534 mov r3, r12 */
/* @0x1ec538 mov r8, r4 */
/* ── 数组内右移一格（元素 4 B，方向从后往前，dest > src）────────────────────────
 *   r3 = 数组 + r4*4；循环把 [r3] 搬到 [r3+4]，直到 r8 == r9（已放置数）。
 *   ★ 这是全函数**唯一**一条非栈、非 alloca 首址的 store（str r2,[r3],#4），
 *     也是「零字段写、零全局写」这条负事实里唯一的例外形态（写的是自己 alloca 出来的数组）。
 */

/* @0x1ec53c add r8, r8, #1 */
/* @0x1ec540 ldr r2, [r3, #0x4] */
/* @0x1ec544 cmp r8, r9 */
/* @0x1ec548 str r2, [r3], #4 */
/* @0x1ec54c bne 0x1ec53c <_ZN7CSprite7DrawSWFEifffffffjf+0x634> */
/* @0x1ec550 mov r9, r8 */
/* @0x1ec554 ldr r1, [r10, #0x8] */
/* @0x1ec558 mov r2, #1 */
/* @0x1ec55c b 0x1ec42c <_ZN7CSprite7DrawSWFEifffffffjf+0x524> */
/* @0x1ec560 ldr r3, [r10, #0xc] */
/* @0x1ec564 mov r8, r9 */
/* @0x1ec568 mov r12, r2 */
/* @0x1ec56c cmp r3, #0 */
/* @0x1ec570 bgt 0x1ec2d4 <_ZN7CSprite7DrawSWFEifffffffjf+0x3cc> */
/* ── 收尾前：25 号状态回写「已放置数」+ 决定 bool ──────────────────────────────
 *   r8（已放置数）== 0 → SetRenderState(25, 0)，lr = 全局字节开关，跳 1ec338 再画一次；
 *   r8 != 0 → 若 r12（本轮标记）为 0 则 lr = 0，否则 lr = 全局字节开关，再跳 1ec338。
 *   ⇒ 25 号状态在本函数里被用作「当前子项序号」（1ec388 的 mov r2,r8），不是布尔。
 */

/* @0x1ec574 cmp r8, #0 */
/* @0x1ec578 bne 0x1ec5b0 <_ZN7CSprite7DrawSWFEifffffffjf+0x6a8> */
/* @0x1ec57c mov r0, r5 */
/* @0x1ec580 mov r1, #25 */
/* @0x1ec584 mov r2, r8 */
/* @0x1ec588 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec58c ldr r3, [pc, #-0x2c4] */
/* @0x1ec590 mov r12, #1 */
/* @0x1ec594 ldr r0, [r11, #-0x28c] */
/* @0x1ec598 ldr r3, [r0, r3] */
/* @0x1ec59c ldrb lr, [r3] */
/* @0x1ec5a0 b 0x1ec338 <_ZN7CSprite7DrawSWFEifffffffjf+0x430> */
/* @0x1ec5a4 mov r8, r9 */
/* @0x1ec5a8 mov r12, #1 */
/* @0x1ec5ac b 0x1ec2ac <_ZN7CSprite7DrawSWFEifffffffjf+0x3a4> */
/* @0x1ec5b0 cmp r12, #0 */
/* @0x1ec5b4 moveq lr, r12 */
/* @0x1ec5b8 bne 0x1ec58c <_ZN7CSprite7DrawSWFEifffffffjf+0x684> */
/* @0x1ec5bc b 0x1ec338 <_ZN7CSprite7DrawSWFEifffffffjf+0x430> */
/* ── 排序完成后按数组顺序整表再画一遍（bool = 0）──────────────────────────────
 *   1ec5c4 若 r8 == 0 直接收尾；否则再进一次 (29,8)(28,8)(24,0)(4,0)，
 *   1ec5d4 sub r7,r7,#4 把基址退一格，配合 1ec628 的 `ldr r1,[r5,#4]!` 前索引（首次读仍是 数组[0]），
 *   1ec610 把 RSM 指针 r5 暂存到 [r11-0x260]
 *   （因为 r5 被借去当游标），1ec628 起 `ldr r1,[r5,#4]!` 逐元素取子项并调 DrawSWFObject，
 *   1ec658 计数到 r8 为止，1ec660 再把 r5 从 [r11-0x260] 恢复。
 *   ★ 所以一帧的子项会经历两次绘制路径：排序中一次、整表一次；第二次的 bool 恒 0。
 */

/* @0x1ec5c0 cmp r8, #0 */
/* @0x1ec5c4 beq 0x1ec664 <_ZN7CSprite7DrawSWFEifffffffjf+0x75c> */
/* @0x1ec5c8 mov r0, r5 */
/* @0x1ec5cc mov r1, #29 */
/* @0x1ec5d0 mov r2, #8 */
/* @0x1ec5d4 sub r7, r7, #4 */
/* @0x1ec5d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec5dc mov r0, r5 */
/* @0x1ec5e0 mov r1, #28 */
/* @0x1ec5e4 mov r2, #8 */
/* @0x1ec5e8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec5ec mov r0, r5 */
/* @0x1ec5f0 mov r1, #24 */
/* @0x1ec5f4 mov r2, #0 */
/* @0x1ec5f8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec5fc mov r0, r5 */
/* @0x1ec600 mov r1, #4 */
/* @0x1ec604 mov r2, #0 */
/* @0x1ec608 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec60c mov r6, #0 */
/* @0x1ec610 str r5, [r11, #-0x260] */
/* @0x1ec614 sub r9, r11, #596 */
/* @0x1ec618 mov r5, r7 */
/* @0x1ec61c sub r10, r11, #592 */
/* @0x1ec620 sub r7, r11, #576 */
/* @0x1ec624 mov r4, r6 */
/* @0x1ec628 ldr r1, [r5, #0x4]! */
/* @0x1ec62c sub r2, r11, #600 */
/* @0x1ec630 add r6, r6, #1 */
/* @0x1ec634 str r2, [sp] */
/* @0x1ec638 ldr r0, [r11, #-0x264] */
/* @0x1ec63c sub r2, r11, #176 */
/* @0x1ec640 str r10, [sp, #0x4] */
/* @0x1ec644 sub r3, r11, #112 */
/* @0x1ec648 str r9, [sp, #0x8] */
/* @0x1ec64c str r7, [sp, #0xc] */
/* @0x1ec650 str r4, [sp, #0x10] */
/* @0x1ec654 bl 0x1eba90 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b> */
/* @0x1ec658 cmp r6, r8 */
/* @0x1ec65c blt 0x1ec628 <_ZN7CSprite7DrawSWFEifffffffjf+0x720> */
/* @0x1ec660 ldr r5, [r11, #-0x260] */
/* ── 还原 8 个状态（与 1ebf6c..1ebffc 严格配对）──────────────────────────────
 *   SetSamplerState(0,2,-0x294) → (0,3,-0x298)
 *   SetRenderState(30,-0x29c) (25,-0x2a0) (29,-0x2a4) (28,-0x2a8) (24,-0x280) (4,-0x284)
 *   ⇒ 本函数是**自洽的**：不管调用方原来是什么状态，出去时与进来时一致（DrawShape 不是，见段 B）。
 */

/* @0x1ec664 ldr r3, [r11, #-0x294] */
/* @0x1ec668 mov r0, r5 */
/* @0x1ec66c mov r1, #0 */
/* @0x1ec670 mov r2, #2 */
/* @0x1ec674 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1ec678 ldr r3, [r11, #-0x298] */
/* @0x1ec67c mov r0, r5 */
/* @0x1ec680 mov r1, #0 */
/* @0x1ec684 mov r2, #3 */
/* @0x1ec688 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1ec68c mov r0, r5 */
/* @0x1ec690 ldr r2, [r11, #-0x29c] */
/* @0x1ec694 mov r1, #30 */
/* @0x1ec698 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec69c mov r0, r5 */
/* @0x1ec6a0 ldr r2, [r11, #-0x2a0] */
/* @0x1ec6a4 mov r1, #25 */
/* @0x1ec6a8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6ac mov r0, r5 */
/* @0x1ec6b0 ldr r2, [r11, #-0x2a4] */
/* @0x1ec6b4 mov r1, #29 */
/* @0x1ec6b8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6bc mov r0, r5 */
/* @0x1ec6c0 ldr r2, [r11, #-0x2a8] */
/* @0x1ec6c4 mov r1, #28 */
/* @0x1ec6c8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6cc mov r0, r5 */
/* @0x1ec6d0 ldr r2, [r11, #-0x280] */
/* @0x1ec6d4 mov r1, #24 */
/* @0x1ec6d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6dc mov r0, r5 */
/* @0x1ec6e0 ldr r2, [r11, #-0x284] */
/* @0x1ec6e4 mov r1, #4 */
/* @0x1ec6e8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* ── canary 校验 + 返回（也是所有守卫失败/正常结束的汇合点）───────────────────
 *   重读 [r11-0x290]（guard 指针）与 [r11-0x30]（保存值），比较 *(guard) 与保存值；
 *   不等 → bl __stack_chk_fail@plt（1ec71c）。相等 → sub sp,r11,#40 还原栈（对 alloca 免疫）、
 *   vpop {d8}、pop {r4-r11,pc}。
 *   ★ 返回值：本函数 void，出口不设 r0（调用方 CSprite::Draw 1ec9c0 之后也不读 r0）。
 */

/* @0x1ec6ec ldr r12, [r11, #-0x290] */
/* @0x1ec6f0 ldr r2, [r11, #-0x30] */
/* @0x1ec6f4 ldr r3, [r12] */
/* @0x1ec6f8 cmp r2, r3 */
/* @0x1ec6fc bne 0x1ec71c <_ZN7CSprite7DrawSWFEifffffffjf+0x814> */
/* @0x1ec700 sub sp, r11, #40 */
/* @0x1ec704 vpop {d8} */
/* @0x1ec708 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── alpha 钳位尾块（从 1ec044 的 ble 进来）────────────────────────────────────
 *   r3 ≤ 255 时：r3 ≥ 0 → r12 = r3<<24；r3 < 0 → r12 = 0。随后 b 0x1ec048 汇合。
 *   ⇒ 「alpha > 1.0 一律当 1.0」与「alpha < 0 一律当 0」两条都落在这 5 条指令里。
 */

/* @0x1ec70c cmp r12, #0 */
/* @0x1ec710 lslge r12, r12, #24 */
/* @0x1ec714 movlt r12, #0 */
/* @0x1ec718 b 0x1ec048 <_ZN7CSprite7DrawSWFEifffffffjf+0x140> */
/* @0x1ec71c bl 0xb65d4 <__stack_chk_fail@plt> */


/* ══ 段 B · CSprite::DrawShape 0x1ed768 ═════════════════════════════════════════════════════
 *   4096 B / 1024 字 = 998 条真指令 + 26 字 pool（0x1edbe4..0x1edc24 共 17 字、0x1ee668..0x1ee688 共 9 字）。
 *   58 条 bl：SetRenderState 30、GetRenderState 6、SetSamplerState 2、GetSamplerState 2、
 *   yyMatrix::Multiply 6、DrawDictionaryItem 4、Graphics::GetMatrix 3、sqrtf 2、SetZRotation 1、
 *   GR_Texture_Exists 1、memcpy 1。**没有一条 GR_Texture_Draw / DrawSWFObject**。
 *   帧 1344；r11 = this（不是帧指针，全函数 0 条 str [r11,…]）。
 *
 *   三个入口形态（由 a1 决定，1ed7a8..1ed7bc；a1/a2/a3 就是形参表里的 i/j/k）：
 *     a1 == −1 → 0x1ee68c：把 6 个渲染状态存进 6 个 .bss 全局后返回（**保存**）
 *     a1 == −2 → 0x1ee28c：进绘制状态 → 把队列里所有 228 B 记录各画一次 → 从 6 个全局还原（**刷新+还原**）
 *     其它      → 正常绘制（a3 > 0 走延迟入队，a3 ≤ 0 走图形通道立即画）
 *   ⇒ 与 DrawSWF 的「自洽 8 状态」不同，DrawShape 把状态保存/还原做成了**跨调用协议**：
 *     正常路径还原 24/4 时读的全局（GOT 0x3f0df0/0x3f0df4）**只有 a1 == −1 会写**（1ee700/1ee718），
 *     25 号状态更是只由 a1 == −2 还原（1ee448）。
 *
 *   控制流骨架：
 *     0x1ed768 序言/守卫/a1 分派        0x1ed7c0 采样器 + RSM + alpha
 *     0x1ed818 c1 合成                  0x1ed880 c2 合成 + 通道拆分
 *     0x1ed888..0x1ed9e8 四个矩阵 + 三次 Multiply
 *     0x1eda10 tpe[0] 查纹理 + GR_Texture_Exists + 两个 16 位比值
 *     0x1edae4 矩阵 16 字复制 + .rodata 常量表 → sp+248
 *     0x1edb3c 队列扫描（键 = 记录+8）→ 0x1edce0 画队头 + 0x1edd50 出队
 *     0x1edd98 按 a1 找对象 → 0x1edfe4 入队（a3>0）或 0x1ede1c 图形通道（a3≤0）
 *     0x1ee1f0/0x1ee254 还原状态与采样器、0x1ee27c 公共尾声
 *     0x1ee68c（a1=−1 保存）、0x1ee28c（a1=−2 刷新+还原）、0x1ee748/0x1ee758（sqrtf 回退）
 *
 *   228 B 记录队列（*GOT 0x3f0dfc = 记录数组，*GOT 0x3f0df8 = 计数）字段（全部有锚）：
 *     +0x00 i  +0x04 j  +0x08 k  +0x0c..+0x4b 16 字矩阵  +0x4c..+0x8b 第二个 64 B 块
 *     +0x8c c1（ARGB）  +0x90..+0x9c 4 字  +0xa0 c1&0xFFFFFF  +0xb4..+0xc0 4 字  +0xc4..+0xd0 4 字
 *     +0xd4 一字节  +0xd8 一字  +0xdc/+0xe0 两个 UV 比值（s18/s16）
 *   该布局与 this+0x7c 里的对象同构（+0x0c 矩阵 / +0x4c 第二块 / +0x8c 颜色 / +0x90,+0xb4,+0xc4 三组 4 字）：
 *   记录就是对象的一次快照，a1==−2 靠它重放。
 *
 *   图形通道（1ede1c..1ee5cc，本卡重点 3）见卡片头；要素：
 *     GetMatrix(2)/GetMatrix(0)/GetMatrix(1) → 三次 Multiply → 单位基向量过矩阵（含透视除法）
 *     → 乘两个全局 int 标量 → f3 = g2/(0.5·max(|e1|,|e2|))，开关关掉时 f3 = 1.0f。
 */

/* ── 序言：帧 1344、r11 = this、8 个栈形参的落位 ───────────────────────────────
 *   push 36 + vpush {d8,d9} 16 + sub 1280 + sub 12 = 1344；栈形参在 [sp+1344+4k]（k=0..7）。
 *   i/j/k 先落 [sp+0x8c]/[sp+0x88]/[sp+0xa8]（1ed780/1ed78c/1ed794），全函数按栈重读。
 *   ★ pc 相对取数有三种用途：GOT 基址加数（池字 0x1edbec 0x002044cc）、.rodata 表加数
 *     （池字 0x1edbfc 0x00170444）、其余全是 GOT 槽；0x002044cc + pc(1ed78c) = 0x3f1c58
 *     —— 与 DrawSWF 同一个 GOT 基址。
 *   ★ r11 = this 意味着所有局部都必须用 sp 相对寻址（189 条 str/vstr 里 169 条是 sp 相对）。
 */

/* @0x1ed768 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ed76c vpush {d8, d9} */
/* @0x1ed770 sub sp, sp, #1280 */
/* @0x1ed774 sub sp, sp, #12 */
/* @0x1ed778 ldr r7, [pc, #0x46c] */
/* @0x1ed77c mov r11, r0 */
/* @0x1ed780 str r1, [sp, #0x8c] */
/* @0x1ed784 add r7, pc, r7 */
/* @0x1ed788 ldr r1, [r0, #0x7c] */
/* @0x1ed78c str r2, [sp, #0x88] */
/* @0x1ed790 cmp r1, #0 */
/* @0x1ed794 str r3, [sp, #0xa8] */
/* @0x1ed798 beq 0x1ee27c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xb14> */
/* ── 两道守卫：this+0x7c / this+0x84（与 DrawSWF 1ebf3c/1ebf60 同一对字段）───────
 *   任一为 0 → 0x1ee27c（只 add sp ×2 + vpop + pop，**不还原任何状态**，因为还没动过状态）。
 *   ⇒ 这两个字段是「SWF 数据已就绪」的必要条件：+0x7c = 显示对象指针数组（1edda8 起线性查），
 *     +0x80 = 该数组的长度（1edbbc/1edda0 读），+0x84 = 影片/时间线（DrawSWF 读 +0x18 当帧数）。
 */

/* @0x1ed79c ldr r3, [r0, #0x84] */
/* @0x1ed7a0 cmp r3, #0 */
/* @0x1ed7a4 beq 0x1ee27c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xb14> */
/* ── a1 的两个魔法值：−1 = 保存状态，−2 = 刷新队列 + 还原状态 ───────────────────
 *   cmn r6,#1（i == −1）→ 0x1ee68c；cmn r9,#2（i == −2）→ 0x1ee28c。
 *   ★ 这是本函数独有的跨调用协议：−1 与 −2 都不查 this+0x7c 之外的任何数据、也不画形状，
 *     只读写 6 个 .bss 状态槽（GOT 0x3f0e00/04/08/0c 与 0x3f0df0/f4）。
 *   ★ 唯一入口 F_DrawShape 0x11c038 只是把 GML 的 12 个实参原样传进来，没有对 i 做任何特殊化
 *     ⇒ −1/−2 是 GML 侧可以直接调的「保存/刷新」哨兵值。
 */

/* @0x1ed7a8 ldr r6, [sp, #0x8c] */
/* @0x1ed7ac cmn r6, #1 */
/* @0x1ed7b0 beq 0x1ee68c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xf24> */
/* @0x1ed7b4 ldr r9, [sp, #0x8c] */
/* @0x1ed7b8 cmn r9, #2 */
/* @0x1ed7bc beq 0x1ee28c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xb24> */
/* ── 采样器存两个 + RSM 指针 ───────────────────────────────────────────────────
 *   r5 = *GOT 0x3edd00（同 DrawSWF 的 RSM 单例指针）。
 *   GetSamplerState(0,2) → [sp+0xb0]；GetSamplerState(0,3) → [sp+0xb4]（出口 1ee264/1ee278 还原）。
 *   ★ 只有 2 个采样器要存，**没有** GetRenderState：6 个渲染状态靠 a1==−1 的全局协议，
 *     所以正常路径里一次 GetRenderState 都没有（6 次全在 1ee68c 那个分支）。
 */

/* @0x1ed7c0 ldr r3, [pc, #0x454] */
/* @0x1ed7c4 mov r1, #0 */
/* @0x1ed7c8 mov r2, #2 */
/* @0x1ed7cc ldr r5, [r7, r3] */
/* @0x1ed7d0 mov r0, r5 */
/* @0x1ed7d4 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1ed7d8 mov r2, #3 */
/* @0x1ed7dc mov r1, #0 */
/* @0x1ed7e0 str r0, [sp, #0xb0] */
/* @0x1ed7e4 mov r0, r5 */
/* @0x1ed7e8 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1ed7ec vldr s15, [pc, #1008] */
/* @0x1ed7f0 str r0, [sp, #0xb4] */
/* ── alpha（a11，栈字 7）→ 高字节，随后合成 c1 ─────────────────────────────────
 *   a11 在 [sp+2048-0x2a4] = [sp+1372]（add r0,sp,#2048 / ldr lr,[r0,#-0x2a4] 两段式寻址）；
 *   ×255 → vcvt.s32 → r3；>255 → 0xFF000000；≤255 走 0x1ee4cc 的 lslge/movlt。
 *   ⇒ 与 DrawSWF 1ec000..1ec044 逐条同构（同一段源码的两个实例）。
 */

/* @0x1ed7f4 add r0, sp, #2048 */
/* @0x1ed7f8 ldr lr, [r0, #-0x2a4] */
/* @0x1ed7fc vmov s12, lr */
/* @0x1ed800 vmul.f32 s15, s12, s15 */
/* @0x1ed804 vcvt.s32.f32 s15, s15 */
/* @0x1ed808 vmov r3, s15 */
/* @0x1ed80c cmp r3, #255 */
/* @0x1ed810 movgt r2, #-16777216 */
/* @0x1ed814 ble 0x1ee4cc <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd64> */
/* ── c1（a9，栈字 5）合成：colour1 = alpha<<24 | (a9 & 0x00FFFFFF) ─────────────
 *   1ed818 ldr r6,[sp,#0x554] = a9；1ed824 bic r6,r6,#0xFF000000；1ed82c orr r2,r2,r6
 *   ⇒ c1 存 [sp+0x94]（包），c1&0xFFFFFF 存 [sp+0xac]，再拆通道：
 *     [sp+0xb8]=uxtb(c1)=B  [sp+0xbc]=ubfx(c1,8,8)=G  [sp+0xc0]=ubfx(c1,16,8)=R  [sp+0xc4]=c1>>24=A
 *     [sp+0xc8]=uxtb(a9)=B  [sp+0xcc]=ubfx(a9,8,8)=G  [sp+0xd0]=a9>>16=R
 *   ⇒ 与 DrawSWF 一样是「打包 + 逐通道」双份，但这里是**两个颜色各自一套**（c1 与 c2）。
 */

/* @0x1ed818 ldr r6, [sp, #0x554] */
/* @0x1ed81c cmp r3, #255 */
/* @0x1ed820 ldr r10, [sp, #0x554] */
/* @0x1ed824 bic r6, r6, #-16777216 */
/* @0x1ed828 movgt r3, #-16777216 */
/* @0x1ed82c orr r2, r2, r6 */
/* @0x1ed830 str r2, [sp, #0x94] */
/* @0x1ed834 ldr r9, [sp, #0x94] */
/* @0x1ed838 ubfx r2, r6, #0x8, #0x8 */
/* @0x1ed83c str r6, [sp, #0xac] */
/* @0x1ed840 ubfx r1, r9, #0x8, #0x8 */
/* @0x1ed844 str r2, [sp, #0xcc] */
/* @0x1ed848 str r1, [sp, #0xbc] */
/* @0x1ed84c uxtb r2, r9 */
/* @0x1ed850 ubfx r1, r9, #0x10, #0x8 */
/* @0x1ed854 str r2, [sp, #0xb8] */
/* @0x1ed858 str r1, [sp, #0xc0] */
/* @0x1ed85c lsr r2, r9, #24 */
/* @0x1ed860 lsr r1, r6, #16 */
/* @0x1ed864 str r2, [sp, #0xc4] */
/* @0x1ed868 str r1, [sp, #0xd0] */
/* @0x1ed86c uxtb r2, r10 */
/* @0x1ed870 str r2, [sp, #0xc8] */
/* @0x1ed874 mov r2, #0 */
/* @0x1ed878 str r2, [sp, #0xd4] */
/* @0x1ed87c ble 0x1ee4dc <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd74> */
/* ── c2（a10，栈字 6）合成 + 通道拆分 + 矩阵 A/B/C 的恒等装配 ──────────────────
 *   c2' = alpha<<24 | (a10 & 0x00FFFFFF)（1ed894 bic / 1ed898 orr；alpha 字节复用 1ed87c 的 r3）
 *   通道：-0xd8=B -0xdc=G -0xe0=R -0xe4=A -0xe8=B(a10) -0xec=G -0xf0=R
 *   ★ 三个 64 B 块在这里一次性铺好：sp+328 = I+T(x,y)（e12/e13 由 a4/a5 填）、sp+392 交给
 *     SetZRotation、sp+456 是纯恒等（e12/e13 = −0.0，1ed940 的 vdiv 用 −0.0f 池字 0x80000000）。
 *   ★ s16 = 池字 0x1edc24 = 0.0f（不是 1.0f）—— 所有「置零」写都用 s16，置 1 用 r9 = 0x3F800000。
 */

/* @0x1ed880 add lr, sp, #2048 */
/* @0x1ed884 ldr r12, [sp, #0x558] */
/* @0x1ed888 add r6, sp, #392 */
/* @0x1ed88c vldr s16, [pc, #912] */
/* @0x1ed890 ldr r10, [lr, #-0x2c0] */
/* @0x1ed894 bic r1, r12, #-16777216 */
/* @0x1ed898 orr r3, r3, r1 */
/* @0x1ed89c mov r0, r6 */
/* @0x1ed8a0 ldr r1, [lr, #-0x2b0] */
/* @0x1ed8a4 mov r9, #1065353216 */
/* @0x1ed8a8 str r10, [sp, #0x178] */
/* @0x1ed8ac ubfx r2, r3, #0x8, #0x8 */
/* @0x1ed8b0 ldr r10, [lr, #-0x2bc] */
/* @0x1ed8b4 uxtb r12, r3 */
/* @0x1ed8b8 str r2, [sp, #0xdc] */
/* @0x1ed8bc vstr s16, [sp, #372] */
/* @0x1ed8c0 str r12, [sp, #0xd8] */
/* @0x1ed8c4 vstr s16, [sp, #364] */
/* @0x1ed8c8 str r10, [sp, #0x17c] */
/* @0x1ed8cc vstr s16, [sp, #360] */
/* @0x1ed8d0 str r12, [sp, #0xe8] */
/* @0x1ed8d4 vstr s16, [sp, #356] */
/* @0x1ed8d8 ubfx r12, r3, #0x10, #0x8 */
/* @0x1ed8dc str r2, [sp, #0xec] */
/* @0x1ed8e0 str r12, [sp, #0xe0] */
/* @0x1ed8e4 lsr r3, r3, #24 */
/* @0x1ed8e8 mov r2, #0 */
/* @0x1ed8ec str r3, [sp, #0xe4] */
/* @0x1ed8f0 str r3, [sp, #0xf0] */
/* @0x1ed8f4 vstr s16, [sp, #352] */
/* @0x1ed8f8 str r2, [sp, #0xf4] */
/* @0x1ed8fc vstr s16, [sp, #344] */
/* @0x1ed900 str r9, [sp, #0x184] */
/* @0x1ed904 vstr s16, [sp, #340] */
/* @0x1ed908 str r9, [sp, #0x170] */
/* @0x1ed90c vstr s16, [sp, #336] */
/* @0x1ed910 str r9, [sp, #0x15c] */
/* @0x1ed914 vstr s16, [sp, #332] */
/* @0x1ed918 str r9, [sp, #0x148] */
/* @0x1ed91c vstr s16, [sp, #384] */
/* ── SetZRotation(angle)：旋转块 = sp+392，angle = a8（栈字 4）──────────────────
 *   r6 = sp+392（1ed888），r1 = a8（1ed8a0 从 [sp+2048-0x2b0] = [sp+1360] 取），1ed920 bl。
 *   ★ 同 DrawSWF：没有 π/180 ⇒ angle 是角度原样（两段 pool 都没有 0x40490fdb）。
 */

/* @0x1ed920 bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f> */
/* ── 缩放块 sp+520 = diag(g·xs, g·ys, 1, 1)，g = *GOT 0x3f0ddc ─────────────────
 *   1ed938 ldr r3,[r7,r3]（GOT 0x3f0ddc）→ 1ed93c vldr s15,[r3] = g
 *   1ed9cc vmul s13 = g*a6（xs）→ 1ed9e0 vstr [sp+520] = e0
 *   1ed9dc vmul s15 = g*a7（ys）→ 1ed9e4 vstr [sp+540] = e5
 *   ⇒ 与 DrawSWF 的 B 块同构；DrawShape 没有原点项，所以只有 T(x,y) 没有 T(−origin/g)。
 */

/* @0x1ed924 ldr r3, [pc, #0x2c4] */
/* @0x1ed928 vldr s14, [pc, #696] */
/* @0x1ed92c add r10, sp, #2048 */
/* @0x1ed930 add r8, sp, #584 */
/* @0x1ed934 add r1, sp, #456 */
/* @0x1ed938 ldr r3, [r7, r3] */
/* @0x1ed93c vldr s15, [r3] */
/* @0x1ed940 vdiv.f32 s14, s14, s15 */
/* @0x1ed944 ldr r3, [r10, #-0x2b8] */
/* @0x1ed948 mov r0, r8 */
/* @0x1ed94c add r2, sp, #520 */
/* @0x1ed950 str r9, [sp, #0x204] */
/* @0x1ed954 vstr s16, [sp, #500] */
/* @0x1ed958 vmov s12, r3 */
/* @0x1ed95c ldr r3, [r10, #-0x2b4] */
/* @0x1ed960 str r9, [sp, #0x1f0] */
/* @0x1ed964 vstr s16, [sp, #492] */
/* @0x1ed968 str r9, [sp, #0x1dc] */
/* @0x1ed96c vstr s16, [sp, #488] */
/* @0x1ed970 str r9, [sp, #0x1c8] */
/* @0x1ed974 vstr s16, [sp, #484] */
/* @0x1ed978 vstr s16, [sp, #480] */
/* @0x1ed97c vstr s16, [sp, #472] */
/* @0x1ed980 vstr s16, [sp, #468] */
/* @0x1ed984 vstr s16, [sp, #464] */
/* @0x1ed988 vstr s16, [sp, #460] */
/* @0x1ed98c vstr s16, [sp, #512] */
/* @0x1ed990 str r9, [sp, #0x244] */
/* @0x1ed994 vstr s16, [sp, #576] */
/* @0x1ed998 str r9, [sp, #0x230] */
/* @0x1ed99c vstr s16, [sp, #572] */
/* @0x1ed9a0 vstr s16, [sp, #568] */
/* @0x1ed9a4 vstr s16, [sp, #564] */
/* @0x1ed9a8 vstr s16, [sp, #556] */
/* @0x1ed9ac vstr s16, [sp, #552] */
/* @0x1ed9b0 vstr s16, [sp, #548] */
/* @0x1ed9b4 vstr s16, [sp, #544] */
/* @0x1ed9b8 vstr s16, [sp, #536] */
/* @0x1ed9bc vstr s16, [sp, #532] */
/* @0x1ed9c0 vstr s16, [sp, #528] */
/* @0x1ed9c4 vstr s16, [sp, #524] */
/* @0x1ed9c8 add r4, sp, #712 */
/* @0x1ed9cc vmul.f32 s13, s15, s12 */
/* @0x1ed9d0 vstr s14, [sp, #504] */
/* @0x1ed9d4 vmov s12, r3 */
/* @0x1ed9d8 vstr s14, [sp, #508] */
/* @0x1ed9dc vmul.f32 s15, s15, s12 */
/* @0x1ed9e0 vstr s13, [sp, #520] */
/* @0x1ed9e4 vstr s15, [sp, #540] */
/* ── 三次 Multiply 合成局部矩阵（sp+584 → sp+648 → sp+712）─────────────────────
 *   1) Multiply(sp+584, sp+456 I, sp+520 S)        → E = I·S
 *   2) Multiply(sp+648, sp+584 E, sp+392 R)        → F = E·R
 *   3) Multiply(sp+712, sp+648 F, sp+328 I+T(x,y)) → G = F·T
 *   ⇒ 与 DrawSWF 的三次链同形（少一个原点块）；交给 DrawDictionaryItem 的就是 sp+712 这块。
 */

/* @0x1ed9e8 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ed9ec mov r2, r6 */
/* @0x1ed9f0 add r6, sp, #648 */
/* @0x1ed9f4 mov r1, r8 */
/* @0x1ed9f8 mov r0, r6 */
/* @0x1ed9fc bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eda00 mov r1, r6 */
/* @0x1eda04 mov r0, r4 */
/* @0x1eda08 add r2, sp, #328 */
/* @0x1eda0c bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* ── this+0x54[0] 取纹理页 + GR_Texture_Exists + 两个 16 位比值 ──────────────────
 *   1eda10 ldr r0,[r11,#0x54]（tpe 表）→ 1eda60 ldr r8,[r0] ⇒ **只用第 0 个元素**，
 *   不是按子图索引（纹理档才按 image_number 索引 + 取模）。
 *   1eda68 ldrsh r0,[r8,#0x14] = 一个 int16 → GR_Texture_Exists(它)，为 0 退到 0x1ee4bc。
 *   1eda94/1eda98 ldrsh r0,[r8]/[r8,#2] = 两个 int16；
 *   1eda7c..1edab8 用同一个 int16（[r8+0x14]）当索引查 *(*(GOT 0x3ed924)+4)[idx] → Texture*，
 *   再取其 [+4]/[+8] 两个 int 当宽/高；1edadc/1edae0 vdiv：
 *     s18 = (float)[页+0] / (float)宽      s16 = (float)[页+2] / (float)高
 *   ⇒ 两个比值就是「页上这块相对整张贴图的 UV 尺寸」，最后作 DrawDictionaryItem 的 f13/f14
 *     （1ee168/1ee170 存 [sp+96]/[sp+100]）。★ 这条是纹理相关但**不调任何 GR 绘制**的唯一证据面。
 *   ⚠ 页结构未钉名：+0x00/+0x02 两个 int16、+0x14 一个 int16（纹理号）；Texture 的 +0/+4/+8 亦然。
 */

/* @0x1eda10 ldr r0, [r11, #0x54] */
/* @0x1eda14 ldr r1, [pc, #0x1d8] */
/* @0x1eda18 vstr s16, [sp, #832] */
/* @0x1eda1c str r9, [sp, #0x344] */
/* @0x1eda20 vstr s16, [sp, #820] */
/* @0x1eda24 str r9, [sp, #0x330] */
/* @0x1eda28 vstr s16, [sp, #812] */
/* @0x1eda2c vstr s16, [sp, #808] */
/* @0x1eda30 vstr s16, [sp, #804] */
/* @0x1eda34 vstr s16, [sp, #800] */
/* @0x1eda38 mov r2, #1056964608 */
/* @0x1eda3c mov r3, #939524096 */
/* @0x1eda40 str r2, [sp, #0x338] */
/* @0x1eda44 str r2, [sp, #0x33c] */
/* @0x1eda48 vstr s16, [sp, #792] */
/* @0x1eda4c str r3, [sp, #0x31c] */
/* @0x1eda50 vstr s16, [sp, #788] */
/* @0x1eda54 vstr s16, [sp, #784] */
/* @0x1eda58 vstr s16, [sp, #780] */
/* @0x1eda5c str r3, [sp, #0x308] */
/* @0x1eda60 ldr r8, [r0] */
/* @0x1eda64 ldr r3, [r7, r1] */
/* @0x1eda68 ldrsh r0, [r8, #20] */
/* @0x1eda6c ldr r6, [r3] */
/* @0x1eda70 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1eda74 cmp r0, #0 */
/* @0x1eda78 beq 0x1ee4bc <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd54> */
/* @0x1eda7c ldr r3, [pc, #0x174] */
/* @0x1eda80 adds r6, r6, #0 */
/* @0x1eda84 ldrsh r2, [r8, #20] */
/* @0x1eda88 movne r6, #1 */
/* @0x1eda8c str r6, [sp, #0xa4] */
/* @0x1eda90 ldr r3, [r7, r3] */
/* @0x1eda94 ldrsh r0, [r8] */
/* @0x1eda98 ldrsh r8, [r8, #2] */
/* @0x1eda9c ldr r3, [r3, #0x4] */
/* @0x1edaa0 vmov s18, r0 */
/* @0x1edaa4 vmov s16, r8 */
/* @0x1edaa8 ldr r3, [r3, r2, lsl #2] */
/* @0x1edaac vcvt.f32.s32 s18, s18 */
/* @0x1edab0 ldr r3, [r3] */
/* @0x1edab4 ldr r1, [r3, #0x4] */
/* @0x1edab8 ldr r2, [r3, #0x8] */
/* @0x1edabc vcvt.f32.s32 s16, s16 */
/* @0x1edac0 str r3, [sp, #0xa0] */
/* @0x1edac4 vmov s12, r1 */
/* @0x1edac8 str r1, [sp, #0x7c] */
/* @0x1edacc vmov s13, r2 */
/* @0x1edad0 str r2, [sp, #0x78] */
/* @0x1edad4 vcvt.f32.s32 s14, s12 */
/* @0x1edad8 vcvt.f32.s32 s15, s13 */
/* @0x1edadc vdiv.f32 s18, s18, s14 */
/* @0x1edae0 vdiv.f32 s16, s16, s15 */
/* ── 局部矩阵 16 字复制到 sp+840；.rodata 常量表 4 字复制到 sp+248 ────────────────
 *   1edae4..1edb28 是 4 组 ldm/stm：源 sp+712（= G 矩阵，64 B），目的 sp+840（绘图用的只读副本）。
 *   1edaf0 ldr lr,[pc,#0x104]（池字 0x00170444）+ 1edb00 add lr,pc,lr（pc 1edb08）
 *     ⇒ lr = 0x350f4c，.rodata 里的一张 4 字常量表，1edb2c ldm 取 4 字 → 1edb38 stm 到 sp+248。
 *   1edafc 把 sp+840 存 [sp+0x98]（后面 1ee1d8 ldm 取它的前两字当 DrawDictionaryItem 的 r2/r3）。
 *   ★ 0x350f4c 这 16 B 的内容没有 .so 可读，只能定性为「4 个字常量」——open。
 */

/* @0x1edae4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1edae8 vldr s17, [pc, #308] */
/* @0x1edaec add r6, sp, #840 */
/* @0x1edaf0 ldr lr, [pc, #0x104] */
/* @0x1edaf4 add r9, sp, #248 */
/* @0x1edaf8 mov r12, r6 */
/* @0x1edafc str r6, [sp, #0x98] */
/* @0x1edb00 add lr, pc, lr */
/* @0x1edb04 str r9, [sp, #0x90] */
/* @0x1edb08 stm r12!, {r0, r1, r2, r3} */
/* @0x1edb0c mov r6, #0 */
/* @0x1edb10 ldm r4!, {r0, r1, r2, r3} */
/* @0x1edb14 mov r9, #228 */
/* @0x1edb18 stm r12!, {r0, r1, r2, r3} */
/* @0x1edb1c ldm r4!, {r0, r1, r2, r3} */
/* @0x1edb20 stm r12!, {r0, r1, r2, r3} */
/* @0x1edb24 ldm r4, {r0, r1, r2, r3} */
/* @0x1edb28 stm r12, {r0, r1, r2, r3} */
/* @0x1edb2c ldm lr, {r0, r1, r2, r3} */
/* @0x1edb30 ldr r12, [pc, #0xe0] */
/* @0x1edb34 ldr r10, [sp, #0x90] */
/* @0x1edb38 stm r10, {r0, r1, r2, r3} */
/* ── 队列计数器 + 扫描起点：*GOT 0x3f0df8 = 计数，*GOT 0x3f0dfc = 228 B 记录数组 ────
 *   1edb30 ldr r12,[pc,#0xe0] → 池字 0xfffff1a0 → GOT 0x3f0df8；1edb3c ldr r12,[r7,r12]；
 *   1edb40 把**槽地址**存 [sp+0x84]，1edb44 再把**值**（计数）读进 r12（随后 1edb48 与 r6 比较）。
 *   1edb48 循环：r6 从 0 开始，键是 [记录+8]（= k），与 [sp+0x88]（= j）比较；
 *   `addge r6,r6,#1; bge` ⇒ **跳过所有 k ≥ j 的记录**，停在第一个 k < j 的槽位。
 *   ★ 也就是说队列是按 k 递增维持的，j 是本次要插入/命中的深度键。
 *   ★ 记录步长 228 B 由 1edb14 mov r9,#228 与 1edb54 mul r4,r9,r6 定死。
 */

/* @0x1edb3c ldr r12, [r7, r12] */
/* @0x1edb40 str r12, [sp, #0x84] */
/* @0x1edb44 ldr r12, [r12] */
/* @0x1edb48 cmp r6, r12 */
/* @0x1edb4c bge 0x1edd98 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x630> */
/* ── 命中槽位：取记录、比键、准备画队头 ───────────────────────────────────────
 *   1edb50..1edb74：r8 = 队列 + 228·r6；[r8+8] < j 则落到 1edb78（画这条记录）。
 *   1edb78..1edbb4：进绘制状态 (29,8)(28,8)(24,0)(4,0)（本块**不设 25**；25 只在入队路径 1ee0f0 设 1、
 *   在「槽位为 0」的 1ee734 清 0）。
 *   1edbb8..1edbe0：r0 = [this+0x80]（对象数）、r2 = [this+0x7c]（对象数组）、
 *     lr = 记录[+0]（= i），然后在对象数组里按 [entry+4] == i 线性查（1edbd0..1edc48 的
 *     `ldr r12,[r2,#4]!` 步长 4 的指针数组）；查不到 → r12 = 0（1edc4c）。
 */

/* @0x1edb50 ldr r3, [pc, #0xc8] */
/* @0x1edb54 mul r4, r9, r6 */
/* @0x1edb58 ldr r10, [sp, #0x88] */
/* @0x1edb5c ldr r3, [r7, r3] */
/* @0x1edb60 add r8, r3, r4 */
/* @0x1edb64 str r3, [sp, #0x80] */
/* @0x1edb68 ldr r3, [r8, #0x8] */
/* @0x1edb6c cmp r3, r10 */
/* @0x1edb70 addge r6, r6, #1 */
/* @0x1edb74 bge 0x1edb48 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x3e0> */
/* @0x1edb78 mov r0, r5 */
/* @0x1edb7c mov r1, #29 */
/* @0x1edb80 mov r2, #8 */
/* @0x1edb84 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edb88 mov r0, r5 */
/* @0x1edb8c mov r1, #28 */
/* @0x1edb90 mov r2, #8 */
/* @0x1edb94 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edb98 mov r0, r5 */
/* @0x1edb9c mov r1, #24 */
/* @0x1edba0 mov r2, #0 */
/* @0x1edba4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edba8 mov r0, r5 */
/* @0x1edbac mov r2, #0 */
/* @0x1edbb0 mov r1, #4 */
/* @0x1edbb4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edbb8 ldr r0, [r11, #0x80] */
/* @0x1edbbc ldr r12, [sp, #0x80] */
/* @0x1edbc0 cmp r0, #0 */
/* @0x1edbc4 ldr r2, [r11, #0x7c] */
/* @0x1edbc8 ldr lr, [r12, r4] */
/* @0x1edbcc ble 0x1edc4c <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4e4> */
/* @0x1edbd0 ldr r12, [r2] */
/* @0x1edbd4 ldr r3, [r12, #0x4] */
/* @0x1edbd8 cmp lr, r3 */
/* @0x1edbdc beq 0x1edc50 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4e8> */
/* @0x1edbe0 b 0x1edc28 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4c0> */
/* ── pool #1（0x1edbe4..0x1edc24，17 字；前 4 个被 objdump 译成指令）─────────────
 *   0x1edbe4 0x437f0000 = 255.0f        0x1edbe8 0x80000000 = −0.0f
 *   0x1edbec 0x002044cc GOT 基址加数（+pc 1ed78c ⇒ 0x3f1c58）
 *   0x1edbf0 0xfffff184 → GOT 0x3f0ddc（全局 float g，与 DrawSWF 共用）
 *   0x1edbf4 0xffffe828 → GOT 0x3f0480（全局 int，1eda6c 解引用后只用来判「非 0」→ b5）
 *   0x1edbf8 0xffffbccc → GOT 0x3ed924（纹理表基址：+4 是指针数组）
 *   0x1edbfc 0x00170444 .rodata 加数（+pc 1edb08 ⇒ 0x350f4c，4 字常量表）
 *   0x1edc00 0xffffc978 → GOT 0x3ee5d0（全局字节开关：图形通道闸，也与 DrawSWF 共用）
 *   0x1edc04 0xffffe4f4 → GOT 0x3f014c（全局 int，当 float 乘 x'）
 *   0x1edc08 0xffffe4f8 → GOT 0x3f0150（全局 int，当 float 乘 y'）
 *   0x1edc0c 0xffffbcd0 → GOT 0x3ed928（全局 float，当矩阵的第三维输入 g）
 *   0x1edc10 0xfffff198 → GOT 0x3f0df0（状态 24 的保存槽）
 *   0x1edc14 0xfffff19c → GOT 0x3f0df4（状态 4 的保存槽）
 *   0x1edc18 0xfffff1a0 → GOT 0x3f0df8（队列计数）
 *   0x1edc1c 0xffffc0a8 → GOT 0x3edd00（RenderStateManager 单例指针）
 *   0x1edc20 0xfffff1a4 → GOT 0x3f0dfc（队列记录数组）
 *   0x1edc24 0x00000000 = 0.0f（置零用）
 *   ★ 17 个字全部被引用（1ed7ec/1ed928/1ed778/1ed924/1eda14/1eda7c/1edaf0/1ede1c/1edeb4/1edeb8/
 *     1edec4/1edd1c/1edd34/1edb30/1ed7c0/1edb50/1edae8），无废字。
 */

/* @0x1edbe4 cmnmi pc, #0 */
/* @0x1edbe8 andhi r0, r0, r0 */
/* @0x1edbec eoreq r4, r0, r12, asr #9 */
/* @0x1edbf0 .word 0xfffff184 */
/* @0x1edbf4 .word 0xffffe828 */
/* @0x1edbf8 .word 0xffffbccc */
/* @0x1edbfc andseq r0, r7, r4, asr #8 */
/* @0x1edc00 .word 0xffffc978 */
/* @0x1edc04 .word 0xffffe4f4 */
/* @0x1edc08 .word 0xffffe4f8 */
/* @0x1edc0c .word 0xffffbcd0 */
/* @0x1edc10 .word 0xfffff198 */
/* @0x1edc14 .word 0xfffff19c */
/* @0x1edc18 .word 0xfffff1a0 */
/* @0x1edc1c .word 0xffffc0a8 */
/* @0x1edc20 .word 0xfffff1a4 */
/* @0x1edc24 andeq r0, r0, r0 */
/* @0x1edc28 mov r3, #0 */
/* @0x1edc2c b 0x1edc40 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4d8> */
/* @0x1edc30 ldr r12, [r2, #0x4]! */
/* @0x1edc34 ldr r1, [r12, #0x4] */
/* @0x1edc38 cmp lr, r1 */
/* @0x1edc3c beq 0x1edc50 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4e8> */
/* @0x1edc40 add r3, r3, #1 */
/* @0x1edc44 cmp r3, r0 */
/* @0x1edc48 bne 0x1edc30 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4c8> */
/* @0x1edc4c mov r12, #0 */
/* ── 构造 DrawDictionaryItem 的栈实参块（第一个调用点，画队头）──────────────────
 *   布局（与 callee 0x1e9c10 的取参互为证据）：
 *     stack[0..13]（0x00..0x37）= yyMatrix 的 m2..m15（14 字，来自源对象 +0x14，即矩阵 +0xc 起 16 字的后 14 字）
 *     r2/r3（寄存器）= m0/m1（来自源对象 +0xc/+0x10）⇒ **16 字矩阵被拆成 2 寄存器 + 14 栈字**
 *     [0x38] = f3（此处 s17 = 0.0f）      [0x3c] = b4（恒 0）      [0x40] = b5（源对象 +0xd4 的字节）
 *     [0x44] = p6 = 源+76（第二个 64 B 块）   [0x48] = p7 = 源+144   [0x4c] = p8 = 源+164
 *     [0x50] = p9 = 源+180                 [0x54]/[0x58] = p10/p11 = 源+196
 *     [0x5c] = 源+0xd8  [0x60] = 源+0xdc   [0x64] = 源+0xe0
 *   ⇒ 前 6 个指针（+76/+144/+164/+180/+196/+196）都是**同一对象内部**的定长块地址，
 *     不是外部缓冲 ⇒ 每条 228 B 记录/每个 SWF 对象自带它的矩阵与顶点/颜色数组。
 *   ★ callee 侧证据（cards/auto/bank_0166.c:1934-1980）：DrawDictionaryItem 的帧 608，
 *     r2/r3 经 stmib 落到 sp+600/604 后被 vldr 当 float 读（s19/s18），
 *     栈 14 字后的 664/668/672（word14/15/16）分别被当 float/byte/byte 读，与上表逐项对齐。
 */

/* @0x1edc50 vstr s17, [sp, #56] */
/* @0x1edc54 mov r3, #0 */
/* @0x1edc58 str r3, [sp, #0x3c] */
/* @0x1edc5c add r0, r8, #76 */
/* @0x1edc60 ldrb lr, [r8, #0xd4] */
/* @0x1edc64 add r3, r8, #196 */
/* @0x1edc68 str r0, [sp, #0x44] */
/* @0x1edc6c add r1, r8, #144 */
/* @0x1edc70 str r3, [sp, #0x54] */
/* @0x1edc74 add r2, r8, #164 */
/* @0x1edc78 str r3, [sp, #0x58] */
/* @0x1edc7c add r3, r8, #180 */
/* @0x1edc80 str lr, [sp, #0x40] */
/* @0x1edc84 add r4, r8, #20 */
/* @0x1edc88 str r1, [sp, #0x48] */
/* @0x1edc8c mov lr, sp */
/* @0x1edc90 str r2, [sp, #0x4c] */
/* @0x1edc94 add r10, r8, #12 */
/* @0x1edc98 str r3, [sp, #0x50] */
/* @0x1edc9c ldr r3, [r8, #0xd8] */
/* @0x1edca0 str r3, [sp, #0x5c] */
/* @0x1edca4 ldr r3, [r8, #0xdc] */
/* @0x1edca8 str r3, [sp, #0x60] */
/* @0x1edcac ldr r3, [r8, #0xe0] */
/* @0x1edcb0 str r3, [sp, #0x64] */
/* @0x1edcb4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1edcb8 stm lr!, {r0, r1, r2, r3} */
/* @0x1edcbc ldm r4!, {r0, r1, r2, r3} */
/* @0x1edcc0 stm lr!, {r0, r1, r2, r3} */
/* @0x1edcc4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1edcc8 stm lr!, {r0, r1, r2, r3} */
/* @0x1edccc ldm r4, {r0, r1} */
/* @0x1edcd0 stm lr, {r0, r1} */
/* @0x1edcd4 mov r1, r12 */
/* @0x1edcd8 ldm r10, {r2, r3} */
/* @0x1edcdc mov r0, r11 */
/* ── 第一个 DrawDictionaryItem：画队头记录（源 = 记录本身）─────────────────────
 *   r0 = r11（this）、r1 = r12（查到的对象）、r2/r3 = [对象+0xc]/[对象+0x10]（矩阵 m0/m1），
 *   其余见 1edc50 的布局表。随后 1edce4..1edcf8 立刻设 SetRenderState(30, 计数-1)，
 *   1edcfc..1eddd4 出绘制状态：(29,3)(28,1)(24, 全局 0x3f0df0)(4, 全局 0x3f0df4)。
 *   ★ 24/4 的「还原值」来自 .bss 全局而不是本帧保存值 ⇒ 必须先有一轮 a1==−1 的保存。
 */

/* @0x1edce0 bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* @0x1edce4 ldr r10, [sp, #0x84] */
/* @0x1edce8 mov r0, r5 */
/* @0x1edcec mov r1, #30 */
/* @0x1edcf0 ldr r2, [r10] */
/* @0x1edcf4 sub r2, r2, #1 */
/* @0x1edcf8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edcfc mov r0, r5 */
/* @0x1edd00 mov r1, #29 */
/* @0x1edd04 mov r2, #3 */
/* @0x1edd08 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edd0c mov r0, r5 */
/* @0x1edd10 mov r1, #28 */
/* @0x1edd14 mov r2, #1 */
/* @0x1edd18 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edd1c ldr r3, [pc, #-0x114] */
/* @0x1edd20 mov r0, r5 */
/* @0x1edd24 mov r1, #24 */
/* @0x1edd28 ldr r3, [r7, r3] */
/* @0x1edd2c ldr r2, [r3] */
/* @0x1edd30 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edd34 ldr r3, [pc, #-0x128] */
/* @0x1edd38 mov r0, r5 */
/* @0x1edd3c mov r1, #4 */
/* @0x1edd40 ldr r3, [r7, r3] */
/* @0x1edd44 ldr r2, [r3] */
/* @0x1edd48 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edd4c ldr r4, [r10] */
/* ── 出队：计数−1 + 整段 memcpy 下移（每条 228 B）──────────────────────────────
 *   1edd4c..1edd54：r4 = 计数、r8 = 计数−1、写回计数器（*GOT 0x3f0df8）。
 *   1edd58..1edd88：从 r6 位置开始，把 r6+1.. 的记录逐条 memcpy 到 r6（每次 228 B，
 *     `mla r10, r6, r9, r9` / `mla r4, r9, r4, r12` 两处 228 步长运算），直到游标追平旧的计数。
 *   ⇒ 队列是**紧凑数组**（不是链表），删除代价 O(n·228 B)。
 */

/* @0x1edd50 sub r8, r4, #1 */
/* @0x1edd54 str r8, [r10] */
/* @0x1edd58 cmp r6, r8 */
/* @0x1edd5c bge 0x1edd8c <_ZN7CSprite9DrawShapeEiiifffffjjf+0x624> */
/* @0x1edd60 ldr r12, [sp, #0x80] */
/* @0x1edd64 mla r10, r6, r9, r9 */
/* @0x1edd68 mla r4, r9, r4, r12 */
/* @0x1edd6c add r10, r12, r10 */
/* @0x1edd70 sub r0, r10, #228 */
/* @0x1edd74 mov r1, r10 */
/* @0x1edd78 mov r2, #228 */
/* @0x1edd7c add r10, r10, r2 */
/* @0x1edd80 bl 0xb65bc <memcpy@plt> */
/* @0x1edd84 cmp r10, r4 */
/* @0x1edd88 bne 0x1edd70 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x608> */
/* @0x1edd8c mov r12, r8 */
/* @0x1edd90 cmp r6, r12 */
/* @0x1edd94 blt 0x1edb50 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x3e8> */
/* ── 第二个搜索：按 a1 在 this+0x7c 的对象数组里找对象（步长 4 的指针数组）─────────
 *   1edd98..1edde4：r0 = [this+0x80]（长度）、r2 = [this+0x7c]（数组）、比较 [entry+4] == a1；
 *   找不到 → r4 = 0（1edde4）。
 *   ⇒ 队列记录只存 i（[+0]），真正要画的对象每次都用 i 现查 ⇒ 对象可以随时被替换/销毁。
 */

/* @0x1edd98 ldr r0, [r11, #0x80] */
/* @0x1edd9c ldr r2, [r11, #0x7c] */
/* @0x1edda0 cmp r0, #0 */
/* @0x1edda4 ble 0x1edde4 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x67c> */
/* @0x1edda8 ldr r4, [r2] */
/* @0x1eddac ldr r6, [sp, #0x8c] */
/* @0x1eddb0 ldr r3, [r4, #0x4] */
/* @0x1eddb4 cmp r6, r3 */
/* @0x1eddb8 beq 0x1edde8 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x680> */
/* @0x1eddbc mov r3, #0 */
/* @0x1eddc0 mov lr, r6 */
/* @0x1eddc4 b 0x1eddd8 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x670> */
/* @0x1eddc8 ldr r4, [r2, #0x4]! */
/* @0x1eddcc ldr r1, [r4, #0x4] */
/* @0x1eddd0 cmp lr, r1 */
/* @0x1eddd4 beq 0x1edde8 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x680> */
/* @0x1eddd8 add r3, r3, #1 */
/* @0x1edddc cmp r3, r0 */
/* @0x1edde0 bne 0x1eddc8 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x660> */
/* @0x1edde4 mov r4, #0 */
/* ── 分支总闸：a3 > 0 走延迟入队，a3 ≤ 0 走图形通道立即画 ───────────────────────
 *   1edde8 ldr r9,[sp,#0xa8]（a3）；cmp #0；bgt 0x1edfe4（入队）。
 *   a3 ≤ 0：cmp r12,#0（上面那次扫描的槽位）；槽位为 0 → 0x1ee734（先把 25 置 0 再回图形通道）。
 *   ★ 于是 a3 是「要不要延后画」的开关；a3 越大并不改变键（键是 j），只决定入队与否。
 */

/* @0x1edde8 ldr r9, [sp, #0xa8] */
/* @0x1eddec cmp r9, #0 */
/* @0x1eddf0 bgt 0x1edfe4 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x87c> */
/* @0x1eddf4 cmp r12, #0 */
/* @0x1eddf8 add r9, sp, #184 */
/* @0x1eddfc add r10, sp, #216 */
/* @0x1ede00 add r12, sp, #776 */
/* @0x1ede04 add r6, sp, #200 */
/* @0x1ede08 str r9, [sp, #0x80] */
/* @0x1ede0c str r10, [sp, #0x9c] */
/* @0x1ede10 str r12, [sp, #0x6c] */
/* @0x1ede14 str r6, [sp, #0x88] */
/* @0x1ede18 beq 0x1ee734 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xfcc> */
/* @0x1ede1c ldr r3, [pc, #-0x224] */
/* @0x1ede20 ldr r3, [r7, r3] */
/* @0x1ede24 ldrb r9, [r3] */
/* @0x1ede28 cmp r9, #0 */
/* @0x1ede2c vmoveq.f32 s15, #1.000000e+00 */
/* @0x1ede30 beq 0x1ee5cc <_ZN7CSprite9DrawShapeEiiifffffjjf+0xe64> */
/* @0x1ede34 add r3, sp, #904 */
/* @0x1ede38 add r8, sp, #968 */
/* @0x1ede3c add r6, sp, #1024 */
/* @0x1ede40 mov r0, #2 */
/* @0x1ede44 mov r1, r3 */
/* @0x1ede48 add r6, r6, #8 */
/* @0x1ede4c str r3, [sp, #0x70] */
/* @0x1ede50 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ede54 mov r1, r8 */
/* @0x1ede58 mov r0, #0 */
/* @0x1ede5c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ede60 mov r1, r6 */
/* @0x1ede64 mov r0, #1 */
/* @0x1ede68 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ede6c ldr r3, [sp, #0x70] */
/* @0x1ede70 mov r2, r8 */
/* @0x1ede74 add r8, sp, #1088 */
/* @0x1ede78 add r8, r8, #8 */
/* @0x1ede7c mov r1, r3 */
/* @0x1ede80 mov r0, r8 */
/* @0x1ede84 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ede88 mov r2, r6 */
/* @0x1ede8c add r6, sp, #1152 */
/* @0x1ede90 mov r1, r8 */
/* @0x1ede94 add r6, r6, #8 */
/* @0x1ede98 mov r0, r6 */
/* @0x1ede9c bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1edea0 add r0, sp, #1216 */
/* @0x1edea4 mov r2, r6 */
/* @0x1edea8 add r0, r0, #8 */
/* @0x1edeac add r1, sp, #840 */
/* @0x1edeb0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1edeb4 ldr r2, [pc, #-0x2b8] */
/* @0x1edeb8 ldr r3, [pc, #-0x2b8] */
/* @0x1edebc vldr s14, [pc, #-672] */
/* @0x1edec0 vmov.f32 s15, s14 */
/* @0x1edec4 ldr r1, [pc, #-0x2c0] */
/* @0x1edec8 ldr r12, [r7, r2] */
/* @0x1edecc vldr s2, [r12] */
/* @0x1eded0 ldr r0, [r7, r3] */
/* @0x1eded4 vldr s3, [r0] */
/* @0x1eded8 ldr r10, [sp, #0x6c] */
/* @0x1ededc add r2, sp, #288 */
/* @0x1edee0 vcvt.f32.s32 s2, s2 */
/* @0x1edee4 add r3, sp, #304 */
/* @0x1edee8 add r0, sp, #320 */
/* @0x1edeec mov lr, #1065353216 */
/* @0x1edef0 vstr s14, [sp, #280] */
/* @0x1edef4 vstr s14, [sp, #284] */
/* @0x1edef8 vstr s14, [sp, #292] */
/* @0x1edefc str lr, [sp, #0x120] */
/* @0x1edf00 str lr, [sp, #0x12c] */
/* @0x1edf04 vstr s14, [sp, #296] */
/* @0x1edf08 ldr r1, [r7, r1] */
/* @0x1edf0c vldr s11, [r1] */
/* @0x1edf10 vcvt.f32.s32 s3, s3 */
/* @0x1edf14 vmov.f32 s12, s14 */
/* @0x1edf18 add r12, sp, #2048 */
/* @0x1edf1c add lr, sp, #2048 */
/* @0x1edf20 vldr s13, [r12, #-796] */
/* @0x1edf24 vldr s14, [lr, #-808] */
/* @0x1edf28 vmul.f32 s13, s15, s13 */
/* @0x1edf2c add r6, sp, #2048 */
/* @0x1edf30 add r12, sp, #2048 */
/* @0x1edf34 vldr s4, [r6, #-812] */
/* @0x1edf38 vldr s5, [r12, #-824] */
/* @0x1edf3c add lr, sp, #2048 */
/* @0x1edf40 add r6, sp, #2048 */
/* @0x1edf44 vldr s6, [lr, #-780] */
/* @0x1edf48 vldr s7, [r6, #-792] */
/* @0x1edf4c add r12, sp, #2048 */
/* @0x1edf50 add lr, sp, #2048 */
/* @0x1edf54 vldr s8, [r12, #-764] */
/* @0x1edf58 vldr s9, [lr, #-776] */
/* @0x1edf5c vldr s10, [r1] */
/* @0x1edf60 add r6, sp, #2048 */
/* @0x1edf64 add r12, sp, #2048 */
/* @0x1edf68 add lr, sp, #2048 */
/* @0x1edf6c cmp r3, r0 */
/* @0x1edf70 add r2, r2, #8 */
/* @0x1edf74 add r3, r3, #8 */
/* @0x1edf78 vmul.f32 s14, s15, s14 */
/* @0x1edf7c vmla.f32 s13, s12, s4 */
/* @0x1edf80 vmla.f32 s14, s12, s5 */
/* @0x1edf84 vmla.f32 s13, s11, s6 */
/* @0x1edf88 vmla.f32 s14, s11, s7 */
/* @0x1edf8c vadd.f32 s13, s13, s8 */
/* @0x1edf90 vadd.f32 s14, s14, s9 */
/* @0x1edf94 vdiv.f32 s14, s14, s13 */
/* @0x1edf98 vmul.f32 s14, s2, s14 */
/* @0x1edf9c vstr s14, [r3, #-8] */
/* @0x1edfa0 vldr s14, [r6, #-804] */
/* @0x1edfa4 vmul.f32 s15, s15, s14 */
/* @0x1edfa8 vldr s8, [r12, #-820] */
/* @0x1edfac vldr s9, [lr, #-788] */
/* @0x1edfb0 add r6, sp, #2048 */
/* @0x1edfb4 vldr s14, [r6, #-772] */
/* @0x1edfb8 vmla.f32 s15, s12, s8 */
/* @0x1edfbc vmla.f32 s15, s10, s9 */
/* @0x1edfc0 vadd.f32 s15, s15, s14 */
/* @0x1edfc4 vdiv.f32 s15, s15, s13 */
/* @0x1edfc8 vmul.f32 s15, s3, s15 */
/* @0x1edfcc vmov.f32 s11, s10 */
/* @0x1edfd0 vstr s15, [r3, #-4] */
/* @0x1edfd4 beq 0x1ee4f4 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd8c> */
/* @0x1edfd8 vldr s12, [r2, #-8] */
/* @0x1edfdc vldr s15, [r2, #-4] */
/* @0x1edfe0 b 0x1edf18 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x7b0> */
/* ── 入队：把本次调用写成 228 B 记录（字段表逐项有锚）───────────────────────────
 *   目的地址 = *GOT 0x3f0dfc + 228·槽位（1edfec mul r6,r6,r12 的 r12 = 上面扫到的槽位）。
 *   字段：+0x00 = i（1ee024）        +0x04 = j（1ee07c）        +0x08 = k（1ee034）
 *         +0x0c..+0x4b = 16 字矩阵（1ee080..1ee0c4 四组 ldm/stm，源 sp+776）
 *         +0x4c..+0x8b = 第二个 64 B 块（1ee050/1ee084..1ee09c，源 sp+840 段）
 *         +0x8c = c1 ARGB（1ee0a8）  +0x90..+0x9c = 4 字（1ee03c，源 sp+184）
 *         +0xa0 = c1&0xFFFFFF（1ee0ec，源 [sp+0xac]）
 *         +0xb4..+0xc0 = 4 字（1ee05c，源 sp+248）   +0xc4..+0xd0 = 4 字（1ee06c，源 sp+216）
 *         +0xd4 = 字节（1ee100 strb，源 [sp+0xa4]）  +0xd8 = 源 [sp+0xa0]（1ee104）
 *         +0xdc/+0xe0 = 源 [sp+0xac]/[sp+0xa4] 之外的两字（1ee0d0/1ee0d4 读入 → 1ee100/1ee104 落位）
 *         +220/+224（0xdc/0xe0）= s18/s16 两个 UV 比值（1ee0e0/1ee0e4）
 *   写完后 1ee108 把计数写成「槽位+1」⇒ 新记录成为队尾（旧队尾在 +228·(槽位+1) 之后，未被覆盖）。
 *   ★ 也就是说入队**不搬移已有元素**：新记录直接盖在槽位上，槽位之后的内容原样保留，
 *     但计数被截成 槽位+1 ⇒ 队列语义是「后进先出 + 按 k 截断」，这是本函数最反直觉的一处（open）。
 */

/* @0x1edfe4 ldr r3, [pc, #-0x3cc] */
/* @0x1edfe8 mov r6, #228 */
/* @0x1edfec mul r6, r6, r12 */
/* @0x1edff0 add r10, sp, #184 */
/* @0x1edff4 str r10, [sp, #0x80] */
/* @0x1edff8 add r9, sp, #216 */
/* @0x1edffc ldr r8, [r7, r3] */
/* @0x1ee000 add r12, r12, #1 */
/* @0x1ee004 ldm r10, {r0, r1, r2, r3} */
/* @0x1ee008 add lr, r8, r6 */
/* @0x1ee00c ldr r10, [sp, #0x8c] */
/* @0x1ee010 str r9, [sp, #0x9c] */
/* @0x1ee014 add r9, r6, #144 */
/* @0x1ee018 str r12, [sp, #0x74] */
/* @0x1ee01c add r9, r9, r8 */
/* @0x1ee020 ldr r12, [sp, #0xa8] */
/* @0x1ee024 str r10, [r8, r6] */
/* @0x1ee028 add r10, sp, #776 */
/* @0x1ee02c add r6, lr, #164 */
/* @0x1ee030 str r10, [sp, #0x6c] */
/* @0x1ee034 str r12, [lr, #0x8] */
/* @0x1ee038 add r12, lr, #180 */
/* @0x1ee03c stm r9, {r0, r1, r2, r3} */
/* @0x1ee040 mov r8, r10 */
/* @0x1ee044 ldr r9, [sp, #0x90] */
/* @0x1ee048 add r10, sp, #200 */
/* @0x1ee04c str r6, [sp, #0x8c] */
/* @0x1ee050 add r6, lr, #76 */
/* @0x1ee054 ldm r9, {r0, r1, r2, r3} */
/* @0x1ee058 add r9, lr, #196 */
/* @0x1ee05c stm r12, {r0, r1, r2, r3} */
/* @0x1ee060 ldr r12, [sp, #0x9c] */
/* @0x1ee064 ldm r12, {r0, r1, r2, r3} */
/* @0x1ee068 add r12, sp, #840 */
/* @0x1ee06c stm r9, {r0, r1, r2, r3} */
/* @0x1ee070 ldm r8!, {r0, r1, r2, r3} */
/* @0x1ee074 ldr r9, [sp, #0x88] */
/* @0x1ee078 str r10, [sp, #0x88] */
/* @0x1ee07c str r9, [lr, #0x4] */
/* @0x1ee080 add r9, lr, #12 */
/* @0x1ee084 stm r6!, {r0, r1, r2, r3} */
/* @0x1ee088 ldm r8!, {r0, r1, r2, r3} */
/* @0x1ee08c stm r6!, {r0, r1, r2, r3} */
/* @0x1ee090 ldm r8!, {r0, r1, r2, r3} */
/* @0x1ee094 stm r6!, {r0, r1, r2, r3} */
/* @0x1ee098 ldm r8, {r0, r1, r2, r3} */
/* @0x1ee09c stm r6, {r0, r1, r2, r3} */
/* @0x1ee0a0 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee0a4 ldr r6, [sp, #0x94] */
/* @0x1ee0a8 str r6, [lr, #0x8c] */
/* @0x1ee0ac stm r9!, {r0, r1, r2, r3} */
/* @0x1ee0b0 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee0b4 stm r9!, {r0, r1, r2, r3} */
/* @0x1ee0b8 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee0bc stm r9!, {r0, r1, r2, r3} */
/* @0x1ee0c0 ldm r12, {r0, r1, r2, r3} */
/* @0x1ee0c4 stm r9, {r0, r1, r2, r3} */
/* @0x1ee0c8 ldm r10, {r0, r1, r2, r3} */
/* @0x1ee0cc ldr r9, [sp, #0x8c] */
/* @0x1ee0d0 ldr r10, [sp, #0xac] */
/* @0x1ee0d4 ldr r12, [sp, #0xa4] */
/* @0x1ee0d8 ldr r6, [sp, #0xa0] */
/* @0x1ee0dc stm r9, {r0, r1, r2, r3} */
/* ── 记录尾部两个比值 + 进绘制状态（入队路径也要先把状态推上去）────────────────
 *   1ee0e0/1ee0e4：vstr s18 → [+220]、s16 → [+224]（两个 UV 比值，来自 1edadc/1edae0）。
 *   1ee0f0..1ee14c：SetRenderState(25,1)（注意这里是 1，不是 DrawSWF 的 25=序号）→ (29,8)(28,7)(24,0)(4,0)。
 *   ⇒ 入队路径也走同一套状态窗口，随后在 1ee15c 立刻画一次（见下）。
 */

/* @0x1ee0e0 vstr s18, [lr, #220] */
/* @0x1ee0e4 vstr s16, [lr, #224] */
/* @0x1ee0e8 mov r0, r5 */
/* @0x1ee0ec str r10, [lr, #0xa0] */
/* @0x1ee0f0 mov r1, #25 */
/* @0x1ee0f4 ldr r10, [sp, #0x84] */
/* @0x1ee0f8 mov r2, #1 */
/* @0x1ee0fc ldr r9, [sp, #0x74] */
/* @0x1ee100 strb r12, [lr, #0xd4] */
/* @0x1ee104 str r6, [lr, #0xd8] */
/* @0x1ee108 str r9, [r10] */
/* @0x1ee10c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee110 mov r0, r5 */
/* @0x1ee114 mov r1, #29 */
/* @0x1ee118 mov r2, #8 */
/* @0x1ee11c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee120 mov r0, r5 */
/* @0x1ee124 mov r1, #28 */
/* @0x1ee128 mov r2, #7 */
/* @0x1ee12c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee130 mov r0, r5 */
/* @0x1ee134 mov r1, #24 */
/* @0x1ee138 mov r2, #0 */
/* @0x1ee13c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee140 mov r0, r5 */
/* @0x1ee144 mov r1, #4 */
/* @0x1ee148 mov r2, #0 */
/* @0x1ee14c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee150 ldr r3, [r10] */
/* @0x1ee154 cmp r3, #0 */
/* @0x1ee158 beq 0x1ee734 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xfcc> */
/* ── 入队后立刻画一次（f3 = 1.0f）───────────────────────────────────────────────
 *   1ee150 的 `ldr r3,[r10]; cmp #0; beq 0x1ee734` 在 1ee108 刚写完 槽位+1 之后 ⇒ **恒真**，
 *   是把源码里的 `if (count)` 保留下来的死分支（本行结论可逐条复核：1ee108 与 1ee150 相邻）。
 *   1ee15c..1ee1ec：矩阵 14 字从 sp+848 复制到栈、[0x38]=1.0f（1ee1b8 的 0x3F800000）、
 *   [0x40]=[sp+0xa4]（b5）、7 个指针 + f13/f14 = s18/s16，然后 DrawDictionaryItem（1ee1ec）。
 *   ⇒ 同一次 DrawShape 调用里，记录被**写进队列**并且**立刻画一遍**。
 */

/* @0x1ee15c ldr r9, [sp, #0xa4] */
/* @0x1ee160 add r12, sp, #848 */
/* @0x1ee164 ldr r10, [sp, #0x6c] */
/* @0x1ee168 vstr s18, [sp, #96] */
/* @0x1ee16c ldr r6, [sp, #0x80] */
/* @0x1ee170 vstr s16, [sp, #100] */
/* @0x1ee174 str r9, [sp, #0x40] */
/* @0x1ee178 mov lr, sp */
/* @0x1ee17c ldr r9, [sp, #0x88] */
/* @0x1ee180 mov r8, #1065353216 */
/* @0x1ee184 str r10, [sp, #0x44] */
/* @0x1ee188 add r10, sp, #248 */
/* @0x1ee18c str r6, [sp, #0x48] */
/* @0x1ee190 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee194 ldr r6, [sp, #0x9c] */
/* @0x1ee198 str r9, [sp, #0x4c] */
/* @0x1ee19c ldr r9, [sp, #0xa0] */
/* @0x1ee1a0 str r10, [sp, #0x50] */
/* @0x1ee1a4 str r6, [sp, #0x54] */
/* @0x1ee1a8 mov r6, #0 */
/* @0x1ee1ac str r9, [sp, #0x5c] */
/* @0x1ee1b0 str r6, [sp, #0x3c] */
/* @0x1ee1b4 add r6, sp, #232 */
/* @0x1ee1b8 str r8, [sp, #0x38] */
/* @0x1ee1bc str r6, [sp, #0x58] */
/* @0x1ee1c0 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee1c4 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee1c8 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee1cc ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee1d0 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee1d4 ldm r12, {r0, r1} */
/* @0x1ee1d8 ldr r10, [sp, #0x98] */
/* @0x1ee1dc ldm r10, {r2, r3} */
/* @0x1ee1e0 stm lr, {r0, r1} */
/* @0x1ee1e4 mov r0, r11 */
/* @0x1ee1e8 mov r1, r4 */
/* @0x1ee1ec bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* ── 出绘制状态（入队/图形两路共用）：(30,计数)(29,3)(28,1)(24,全局)(4,全局) ───────
 *   1ee1f0..1ee250；随后 1ee254..1ee278 还原两个采样器。
 *   走到 1ee254 的路径：a3 ≤ 0 的图形通道（1ee664 的 b），a3 > 0 的入队（1ee658 的 bgt 反向）。
 */

/* @0x1ee1f0 ldr r6, [sp, #0x84] */
/* @0x1ee1f4 mov r0, r5 */
/* @0x1ee1f8 mov r1, #30 */
/* @0x1ee1fc ldr r2, [r6] */
/* @0x1ee200 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee204 mov r0, r5 */
/* @0x1ee208 mov r1, #29 */
/* @0x1ee20c mov r2, #3 */
/* @0x1ee210 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee214 mov r0, r5 */
/* @0x1ee218 mov r1, #28 */
/* @0x1ee21c mov r2, #1 */
/* @0x1ee220 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee224 ldr r3, [pc, #-0x61c] */
/* @0x1ee228 mov r0, r5 */
/* @0x1ee22c mov r1, #24 */
/* @0x1ee230 ldr r3, [r7, r3] */
/* @0x1ee234 ldr r2, [r3] */
/* @0x1ee238 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee23c ldr r3, [pc, #-0x630] */
/* @0x1ee240 mov r0, r5 */
/* @0x1ee244 mov r1, #4 */
/* @0x1ee248 ldr r3, [r7, r3] */
/* @0x1ee24c ldr r2, [r3] */
/* @0x1ee250 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* ── 还原采样器（与 1ed7d4/1ed7e8 配对）──────────────────────────────────────────
 *   SetSamplerState(0,2,[sp+0xb0])、(0,3,[sp+0xb4])，然后落进 1ee27c 的公共尾声。
 */

/* @0x1ee254 ldr r3, [sp, #0xb0] */
/* @0x1ee258 mov r0, r5 */
/* @0x1ee25c mov r1, #0 */
/* @0x1ee260 mov r2, #2 */
/* @0x1ee264 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1ee268 mov r0, r5 */
/* @0x1ee26c ldr r3, [sp, #0xb4] */
/* @0x1ee270 mov r1, #0 */
/* @0x1ee274 mov r2, #3 */
/* @0x1ee278 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* ── 公共尾声：add sp,#1280 + add sp,#12 + vpop {d8,d9} + pop ──────────────────
 *   也是两道守卫失败（1ed798/1ed7a4）的落地：那种情况**没有**任何状态被改过，所以不还原。
 *   ★ 分两次 add 是因为 sp 的立即数范围（1280 + 12 = 1344）。
 */

/* @0x1ee27c add sp, sp, #1280 */
/* @0x1ee280 add sp, sp, #12 */
/* @0x1ee284 vpop {d8, d9} */
/* @0x1ee288 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── a1 == −2：刷新队列 + 从全局还原状态 ────────────────────────────────────────
 *   1ee28c..1ee2a8：r3 = *GOT 0x3f0df8（计数器槽）→ [sp+0x84]；[r3] ≤ 0 → 0x1ee4ec
 *     （只取 r5 = *GOT 0x3edd00 后直接跳还原块）；否则 r5 = RSM。
 *   1ee2ac..1ee2e8：进绘制状态 (29,8)(28,8)(24,0)(4,0)。
 *   1ee31c..1ee408：**把队列里每条记录各画一次**（记录步长 228，源 sp+184 段四组 ldm/stm，
 *     矩阵取 [+0x14] 起 14 字 + r2/r3 取 [+0x0c]/[+0x10]，f3 = s16 = 0.0f，b4 = 0，b5 = 记录字节）。
 *   1ee410：清零计数器（str r2,[r10]），然后按 30,25,29,28,24,4 的顺序从 6 个全局还原
 *     （GOT 0x3f0e00/04/08/0c/0df0/0df4）→ 1ee4ac 尾声。
 *   ⇒ 这一支是**唯一**会写回 25 号状态的地方（1ee448）。
 */

/* @0x1ee28c ldr r3, [pc, #-0x67c] */
/* @0x1ee290 ldr r3, [r7, r3] */
/* @0x1ee294 str r3, [sp, #0x84] */
/* @0x1ee298 ldr r3, [r3] */
/* @0x1ee29c cmp r3, #0 */
/* @0x1ee2a0 ldr r3, [pc, #-0x68c] */
/* @0x1ee2a4 ble 0x1ee4ec <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd84> */
/* @0x1ee2a8 ldr r5, [r7, r3] */
/* @0x1ee2ac mov r1, #29 */
/* @0x1ee2b0 mov r2, #8 */
/* @0x1ee2b4 mov r0, r5 */
/* @0x1ee2b8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee2bc mov r0, r5 */
/* @0x1ee2c0 mov r1, #28 */
/* @0x1ee2c4 mov r2, #8 */
/* @0x1ee2c8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee2cc mov r0, r5 */
/* @0x1ee2d0 mov r1, #24 */
/* @0x1ee2d4 mov r2, #0 */
/* @0x1ee2d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee2dc mov r0, r5 */
/* @0x1ee2e0 mov r1, #4 */
/* @0x1ee2e4 mov r2, #0 */
/* @0x1ee2e8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee2ec ldr r12, [sp, #0x84] */
/* @0x1ee2f0 ldr r3, [r12] */
/* @0x1ee2f4 cmp r3, #0 */
/* @0x1ee2f8 ble 0x1ee410 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xca8> */
/* @0x1ee2fc ldr r3, [pc, #-0x6e4] */
/* @0x1ee300 mov r9, #0 */
/* @0x1ee304 mov r8, r9 */
/* @0x1ee308 vldr s16, [pc, #856] */
/* @0x1ee30c ldr r6, [r7, r3] */
/* @0x1ee310 str r7, [sp, #0x80] */
/* @0x1ee314 mov r7, r12 */
/* @0x1ee318 add r6, r6, #224 */
/* @0x1ee31c ldr r0, [r11, #0x80] */
/* @0x1ee320 sub r10, r6, #224 */
/* @0x1ee324 ldr lr, [r6, #-0xe0] */
/* @0x1ee328 cmp r0, #0 */
/* @0x1ee32c ldr r2, [r11, #0x7c] */
/* @0x1ee330 ble 0x1ee368 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xc00> */
/* @0x1ee334 ldr r12, [r2] */
/* @0x1ee338 ldr r3, [r12, #0x4] */
/* @0x1ee33c cmp lr, r3 */
/* @0x1ee340 beq 0x1ee36c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xc04> */
/* @0x1ee344 mov r3, #0 */
/* @0x1ee348 b 0x1ee35c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xbf4> */
/* @0x1ee34c ldr r12, [r2, #0x4]! */
/* @0x1ee350 ldr r1, [r12, #0x4] */
/* @0x1ee354 cmp lr, r1 */
/* @0x1ee358 beq 0x1ee36c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xc04> */
/* @0x1ee35c add r3, r3, #1 */
/* @0x1ee360 cmp r3, r0 */
/* @0x1ee364 bne 0x1ee34c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xbe4> */
/* @0x1ee368 mov r12, #0 */
/* @0x1ee36c vstr s16, [sp, #56] */
/* @0x1ee370 str r8, [sp, #0x3c] */
/* @0x1ee374 ldrb r2, [r6, #-0xc] */
/* @0x1ee378 sub r3, r6, #28 */
/* @0x1ee37c sub r0, r6, #148 */
/* @0x1ee380 str r3, [sp, #0x54] */
/* @0x1ee384 str r3, [sp, #0x58] */
/* @0x1ee388 sub r1, r6, #80 */
/* @0x1ee38c str r2, [sp, #0x40] */
/* @0x1ee390 sub r3, r6, #44 */
/* @0x1ee394 str r0, [sp, #0x44] */
/* @0x1ee398 sub r2, r6, #60 */
/* @0x1ee39c str r1, [sp, #0x48] */
/* @0x1ee3a0 add r4, r10, #20 */
/* @0x1ee3a4 str r2, [sp, #0x4c] */
/* @0x1ee3a8 mov lr, sp */
/* @0x1ee3ac str r3, [sp, #0x50] */
/* @0x1ee3b0 add r10, r10, #12 */
/* @0x1ee3b4 ldr r3, [r6, #-0x8] */
/* @0x1ee3b8 add r9, r9, #1 */
/* @0x1ee3bc str r3, [sp, #0x5c] */
/* @0x1ee3c0 ldr r3, [r6, #-0x4] */
/* @0x1ee3c4 str r3, [sp, #0x60] */
/* @0x1ee3c8 ldr r3, [r6], #228 */
/* @0x1ee3cc str r3, [sp, #0x64] */
/* @0x1ee3d0 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ee3d4 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee3d8 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ee3dc stm lr!, {r0, r1, r2, r3} */
/* @0x1ee3e0 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ee3e4 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee3e8 ldm r4, {r0, r1} */
/* @0x1ee3ec stm lr, {r0, r1} */
/* @0x1ee3f0 mov r1, r12 */
/* @0x1ee3f4 ldm r10, {r2, r3} */
/* @0x1ee3f8 mov r0, r11 */
/* @0x1ee3fc bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* @0x1ee400 ldr r3, [r7] */
/* @0x1ee404 cmp r3, r9 */
/* @0x1ee408 bgt 0x1ee31c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xbb4> */
/* @0x1ee40c ldr r7, [sp, #0x80] */
/* ── a1 == −2 的还原块：6 个状态全部来自 .bss 全局 ─────────────────────────────
 *   先把计数器清零（1ee424 str r2,[r10]，r2 = 0）——注意清零发生在**还原之前**，
 *   所以队列在还原完成时已经是空队列。
 *   30←*0x3f0e00  25←*0x3f0e04  29←*0x3f0e08  28←*0x3f0e0c  24←*0x3f0df0  4←*0x3f0df4
 *   ★ 与 a1 == −1 的保存集合（1ee6a0..1ee720）逐个同址互证：30/25/29/28 走 0x3f0e00..0c，
 *     24/4 走 0x3f0df0/f4 —— 后一对同时也是正常路径 1edd1c/1edd34 的还原来源。
 */

/* @0x1ee410 ldr r10, [sp, #0x84] */
/* @0x1ee414 mov r2, #0 */
/* @0x1ee418 ldr r3, [pc, #0x254] */
/* @0x1ee41c mov r0, r5 */
/* @0x1ee420 mov r1, #30 */
/* @0x1ee424 str r2, [r10] */
/* @0x1ee428 ldr r3, [r7, r3] */
/* @0x1ee42c ldr r2, [r3] */
/* @0x1ee430 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee434 ldr r3, [pc, #0x23c] */
/* @0x1ee438 mov r0, r5 */
/* @0x1ee43c mov r1, #25 */
/* @0x1ee440 ldr r3, [r7, r3] */
/* @0x1ee444 ldr r2, [r3] */
/* @0x1ee448 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee44c ldr r3, [pc, #0x228] */
/* @0x1ee450 mov r0, r5 */
/* @0x1ee454 mov r1, #29 */
/* @0x1ee458 ldr r3, [r7, r3] */
/* @0x1ee45c ldr r2, [r3] */
/* @0x1ee460 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee464 ldr r3, [pc, #0x214] */
/* @0x1ee468 mov r0, r5 */
/* @0x1ee46c mov r1, #28 */
/* @0x1ee470 ldr r3, [r7, r3] */
/* @0x1ee474 ldr r2, [r3] */
/* @0x1ee478 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee47c ldr r3, [pc, #0x200] */
/* @0x1ee480 mov r0, r5 */
/* @0x1ee484 mov r1, #24 */
/* @0x1ee488 ldr r3, [r7, r3] */
/* @0x1ee48c ldr r2, [r3] */
/* @0x1ee490 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee494 ldr r3, [pc, #0x1ec] */
/* @0x1ee498 mov r0, r5 */
/* @0x1ee49c mov r1, #4 */
/* @0x1ee4a0 ldr r3, [r7, r3] */
/* @0x1ee4a4 ldr r2, [r3] */
/* @0x1ee4a8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee4ac add sp, sp, #1280 */
/* @0x1ee4b0 add sp, sp, #12 */
/* @0x1ee4b4 vpop {d8, d9} */
/* @0x1ee4b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── GR_Texture_Exists == 0 的退化：跳过纹理相关比例，直接进绘制准备 ─────────────
 *   1ee4bc：b5 存 [sp+0xa0]（= r0 的返回值 0）、b4 存 [sp+0xa4]、s18 = s16（把 x 比例抄给 y）
 *   ⇒ 贴图不存在时两个比例都被压成 0/同一值，后面照样画（不会崩，只是 UV 全 0）。
 *   ★ 1ee4bc 是 1eda78 的 beq 目标，只此一条入口。
 */

/* @0x1ee4bc str r0, [sp, #0xa0] */
/* @0x1ee4c0 vmov.f32 s18, s16 */
/* @0x1ee4c4 str r0, [sp, #0xa4] */
/* @0x1ee4c8 b 0x1edae4 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x37c> */
/* ── alpha 钳位的 0 ≤ r3 ≤ 255 分支（1ed814 的 ble 目标）──────────────────────
 *   cmp r3,#0；r3 ≥ 0 → r2 = r3<<24；r3 < 0 → r2 = 0；b 0x1ed818（回到 c1 合成）。
 *   1ee4dc 是同构的第二份（c2 用），cmp r3,r2 / lslge / movlt / b 0x1ed880。
 */

/* @0x1ee4cc cmp r3, #0 */
/* @0x1ee4d0 lslge r2, r3, #24 */
/* @0x1ee4d4 movlt r2, #0 */
/* @0x1ee4d8 b 0x1ed818 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xb0> */
/* @0x1ee4dc cmp r3, r2 */
/* @0x1ee4e0 lslge r3, r3, #24 */
/* @0x1ee4e4 movlt r3, r2 */
/* @0x1ee4e8 b 0x1ed880 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x118> */
/* ── a1 == −2 且队列为空：取 RSM 后直接进还原块 ────────────────────────────────
 *   1ee4ec ldr r5,[r7,r3]：r3 是 1ee2a0 载入的池字 0xffffc0a8（GOT 0x3edd00）
 *   ⇒ r5 = RenderStateManager 单例指针；随后 b 0x1ee410 只做还原（1ee424 会把计数器再清一次 0）。
 *   ★ 这条路径不需要队列内容，说明「刷新」在空队列时退化成纯状态还原。
 */

/* @0x1ee4ec ldr r5, [r7, r3] */
/* @0x1ee4f0 b 0x1ee410 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xca8> */
/* ── 图形通道 A：把两个点求成两条边，算最大边长的一半 ──────────────────────────
 *   输入是 1edf18..1edfd4 循环写出的两个点：(sp+304,sp+308)、(sp+312,sp+316)。
 *   1ee4f4..1ee530：两条边 e1 = p1−p0、e2 = p2−p0（p2 = sp+320/sp+324），
 *   s17 = |e1|²（1ee514/1ee520 的 vmul+vmla），s15 = |e2|²（1ee564/1ee568）。
 *   1ee540/1ee558/1ee580/1ee598：两个平方和分别开方（vsqrte + vcmp 自比判 NaN，
 *   异常时走 0x1ee748 / 0x1ee758 的 sqrtf@plt 回退）；1ee5a4 取 max；1ee5b0 乘 0.5f。
 *   ⚠ sp+320/sp+324 从未被本函数写过：1edeec/1edf00 只写了 sp+288/292/296/300（(1,0)/(0,1)），
 *     1edf9c/1edfd0 只写 sp+304..319（两轮）。⇒ 这两字要么是形状的第三点（由更高层预先放在栈上），
 *     要么是编译器对定长数组的越界读。**open**，但两条 sqrtf 回退路径与 max/0.5 的算术全部可核。
 */

/* @0x1ee4f4 vldr s12, [sp, #304] */
/* @0x1ee4f8 vldr s14, [sp, #312] */
/* @0x1ee4fc vsub.f32 s14, s14, s12 */
/* @0x1ee500 vldr s13, [sp, #308] */
/* @0x1ee504 vldr s15, [sp, #316] */
/* @0x1ee508 vldr s10, [sp, #320] */
/* @0x1ee50c vldr s11, [sp, #324] */
/* @0x1ee510 str r10, [sp, #0x6c] */
/* @0x1ee514 vmul.f32 s17, s14, s14 */
/* @0x1ee518 vstr s14, [sp, #264] */
/* @0x1ee51c vsub.f32 s15, s15, s13 */
/* @0x1ee520 vmla.f32 s17, s15, s15 */
/* @0x1ee524 vstr s15, [sp, #268] */
/* @0x1ee528 vsub.f32 s12, s10, s12 */
/* @0x1ee52c vsub.f32 s13, s11, s13 */
/* @0x1ee530 vstr s12, [sp, #272] */
/* @0x1ee534 vcmpe.f32 s17, #0 */
/* @0x1ee538 vstr s13, [sp, #276] */
/* @0x1ee53c vmrs APSR_nzcv, fpscr */
/* @0x1ee540 ble 0x1ee558 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xdf0> */
/* @0x1ee544 vsqrt.f32 s15, s17 */
/* @0x1ee548 vcmp.f32 s15, s15 */
/* @0x1ee54c vmrs APSR_nzcv, fpscr */
/* @0x1ee550 bne 0x1ee748 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xfe0> */
/* @0x1ee554 vmov.f32 s17, s15 */
/* @0x1ee558 vldr s15, [sp, #272] */
/* @0x1ee55c vldr s14, [sp, #276] */
/* @0x1ee560 vldr s13, [pc, #256] */
/* @0x1ee564 vmul.f32 s15, s15, s15 */
/* @0x1ee568 vmla.f32 s15, s14, s14 */
/* @0x1ee56c vcmpe.f32 s17, #0 */
/* @0x1ee570 vmrs APSR_nzcv, fpscr */
/* @0x1ee574 vcmpe.f32 s15, s13 */
/* @0x1ee578 vmovle.f32 s17, s13 */
/* @0x1ee57c vmrs APSR_nzcv, fpscr */
/* @0x1ee580 ble 0x1ee598 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xe30> */
/* @0x1ee584 vsqrt.f32 s14, s15 */
/* @0x1ee588 vcmp.f32 s14, s14 */
/* @0x1ee58c vmrs APSR_nzcv, fpscr */
/* @0x1ee590 bne 0x1ee758 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xff0> */
/* @0x1ee594 vmov.f32 s15, s14 */
/* @0x1ee598 ldr r3, [pc, #0xcc] */
/* @0x1ee59c vmov.f32 s14, #5.000000e-01 */
/* @0x1ee5a0 ldr r3, [r7, r3] */
/* @0x1ee5a4 vcmp.f32 s15, s17 */
/* @0x1ee5a8 vmrs APSR_nzcv, fpscr */
/* @0x1ee5ac vmovgt.f32 s17, s15 */
/* @0x1ee5b0 vmul.f32 s17, s17, s14 */
/* @0x1ee5b4 vldr s14, [r3] */
/* @0x1ee5b8 vmov.f32 s15, #1.000000e+00 */
/* @0x1ee5bc vcmpe.f32 s17, #0 */
/* @0x1ee5c0 vmrs APSR_nzcv, fpscr */
/* @0x1ee5c4 vdivgt.f32 s15, s15, s17 */
/* @0x1ee5c8 vmul.f32 s15, s15, s14 */
/* ── 图形通道 B：f3 = g2/(0.5·max) 或 1.0f，然后第二次 DrawDictionaryItem ─────────
 *   1ee5b4 s14 = *GOT 0x3ee5c0（float g2）；1ee5b8 s15 = 1.0f；
 *   1ee5c4 vdivgt s15 = 1.0/max（max > 0 才除）；1ee5c8 vmul s15 = s15·g2 ⇒ f3 = g2/max。
 *   1ee5cc 是这个块的入口（开关为 0 时从 1ede2c 直接跳来，s15 = 1.0f）。
 *   1ee5cc..1ee654：与 1ee15c 同构的实参块（矩阵 14 字来自 sp+848、r2/r3 来自 sp+840 前两字、
 *   [0x38]=f3、[0x40]=[sp+0xa4]、7 指针、f13/f14 = s18/s16），然后 DrawDictionaryItem。
 *   ⇒ 到这一步为止，本函数对形状做的**全部几何工作**就是：合成矩阵 + 求一个标量 f3。
 */

/* @0x1ee5cc str r9, [sp, #0x3c] */
/* @0x1ee5d0 add lr, sp, #848 */
/* @0x1ee5d4 ldr r9, [sp, #0xa4] */
/* @0x1ee5d8 vstr s15, [sp, #56] */
/* @0x1ee5dc ldr r6, [sp, #0x80] */
/* @0x1ee5e0 vstr s18, [sp, #96] */
/* @0x1ee5e4 ldr r10, [sp, #0x6c] */
/* @0x1ee5e8 mov r12, sp */
/* @0x1ee5ec str r9, [sp, #0x40] */
/* @0x1ee5f0 ldr r9, [sp, #0x88] */
/* @0x1ee5f4 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ee5f8 vstr s16, [sp, #100] */
/* @0x1ee5fc str r6, [sp, #0x48] */
/* @0x1ee600 str r9, [sp, #0x4c] */
/* @0x1ee604 ldr r6, [sp, #0x9c] */
/* @0x1ee608 ldr r9, [sp, #0xa0] */
/* @0x1ee60c str r10, [sp, #0x44] */
/* @0x1ee610 add r10, sp, #248 */
/* @0x1ee614 str r6, [sp, #0x54] */
/* @0x1ee618 add r6, sp, #232 */
/* @0x1ee61c str r10, [sp, #0x50] */
/* @0x1ee620 str r9, [sp, #0x5c] */
/* @0x1ee624 str r6, [sp, #0x58] */
/* @0x1ee628 stm r12!, {r0, r1, r2, r3} */
/* @0x1ee62c ldm lr!, {r0, r1, r2, r3} */
/* @0x1ee630 stm r12!, {r0, r1, r2, r3} */
/* @0x1ee634 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ee638 stm r12!, {r0, r1, r2, r3} */
/* @0x1ee63c ldm lr, {r0, r1} */
/* @0x1ee640 ldr r10, [sp, #0x98] */
/* @0x1ee644 ldm r10, {r2, r3} */
/* @0x1ee648 stm r12, {r0, r1} */
/* @0x1ee64c mov r0, r11 */
/* @0x1ee650 mov r1, r4 */
/* @0x1ee654 bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* ── a3 判定 + 尾声分流 ───────────────────────────────────────────────────────
 *   1ee658 ldr r12,[sp,#0xa8]（a3）；cmp #0；bgt 0x1ee1f0（入队路：出绘制状态），
 *   否则 b 0x1ee254（只还原采样器）。⇒ 两条路的状态收尾不同，与 1edde8 的分支首尾呼应。
 */

/* @0x1ee658 ldr r12, [sp, #0xa8] */
/* @0x1ee65c cmp r12, #0 */
/* @0x1ee660 bgt 0x1ee1f0 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xa88> */
/* @0x1ee664 b 0x1ee254 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xaec> */
/* ── pool #2（0x1ee668..0x1ee688，9 字）────────────────────────────────────────
 *   0x1ee668 0x00000000 = 0.0f（1ee560 vldr s13 用作「平方和 ≤ 0」的比较基准）
 *   0x1ee66c 0xffffc968 → GOT 0x3ee5c0（全局 float g2，f3 的分子）
 *   0x1ee670 0xffffc0a8 → GOT 0x3edd00（RSM）
 *   0x1ee674 0xfffff1a8 → GOT 0x3f0e00（状态 30 槽；1ee418/1ee6a0 共用）
 *   0x1ee678 0xfffff1ac → GOT 0x3f0e04（状态 25）
 *   0x1ee67c 0xfffff1b0 → GOT 0x3f0e08（状态 29）
 *   0x1ee680 0xfffff1b4 → GOT 0x3f0e0c（状态 28）
 *   0x1ee684 0xfffff198 → GOT 0x3f0df0（状态 24）
 *   0x1ee688 0xfffff19c → GOT 0x3f0df4（状态 4）
 *   ★ 9 个字全部被引用：1 个常量浮点（0.0f）+ 8 个 GOT 槽（g2 / RSM / 6 个状态槽）
 *     ⇒ 第二段 pool 里没有任何 .rodata 地址，也没有 255/−0.0 这类算术常量。
 */

/* @0x1ee668 andeq r0, r0, r0 */
/* @0x1ee66c .word 0xffffc968 */
/* @0x1ee670 .word 0xffffc0a8 */
/* @0x1ee674 .word 0xfffff1a8 */
/* @0x1ee678 .word 0xfffff1ac */
/* @0x1ee67c .word 0xfffff1b0 */
/* @0x1ee680 .word 0xfffff1b4 */
/* @0x1ee684 .word 0xfffff198 */
/* @0x1ee688 .word 0xfffff19c */
/* ── a1 == −1：保存 6 个渲染状态到 .bss 全局，然后返回 ──────────────────────────
 *   r4 = *GOT 0x3edd00（RSM）；GetRenderState(30) → *(GOT 0x3f0e00)；
 *   同理 25 → 0x3f0e04、29 → 0x3f0e08、28 → 0x3f0e0c、24 → 0x3f0df0、4 → 0x3f0df4。
 *   1ee724..1ee730 直接尾声（不恢复、不画）。
 *   ⇒ 这是**唯一**写这 6 个槽的地方（正常路径的 24/4 还原、−2 的六连还原都读它们）。
 *     也就是说：正常绘制前必须先调 DrawShape(−1, …)，否则 24/4 会被还原成本帧之前的值
 *     （.bss 初值 0 = 状态被清成 0，可能与调用方期望不同）。
 */

/* @0x1ee68c ldr r3, [pc, #-0x24] */
/* @0x1ee690 mov r1, #30 */
/* @0x1ee694 ldr r4, [r7, r3] */
/* @0x1ee698 mov r0, r4 */
/* @0x1ee69c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee6a0 ldr r3, [pc, #-0x34] */
/* @0x1ee6a4 mov r1, #25 */
/* @0x1ee6a8 ldr r3, [r7, r3] */
/* @0x1ee6ac str r0, [r3] */
/* @0x1ee6b0 mov r0, r4 */
/* @0x1ee6b4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee6b8 ldr r3, [pc, #-0x48] */
/* @0x1ee6bc mov r1, #29 */
/* @0x1ee6c0 ldr r3, [r7, r3] */
/* @0x1ee6c4 str r0, [r3] */
/* @0x1ee6c8 mov r0, r4 */
/* @0x1ee6cc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee6d0 ldr r3, [pc, #-0x5c] */
/* @0x1ee6d4 mov r1, #28 */
/* @0x1ee6d8 ldr r3, [r7, r3] */
/* @0x1ee6dc str r0, [r3] */
/* @0x1ee6e0 mov r0, r4 */
/* @0x1ee6e4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee6e8 ldr r3, [pc, #-0x70] */
/* @0x1ee6ec mov r1, #24 */
/* @0x1ee6f0 ldr r3, [r7, r3] */
/* @0x1ee6f4 str r0, [r3] */
/* @0x1ee6f8 mov r0, r4 */
/* @0x1ee6fc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee700 ldr r3, [pc, #-0x84] */
/* @0x1ee704 mov r1, #4 */
/* @0x1ee708 ldr r3, [r7, r3] */
/* @0x1ee70c str r0, [r3] */
/* @0x1ee710 mov r0, r4 */
/* @0x1ee714 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee718 ldr r3, [pc, #-0x98] */
/* @0x1ee71c ldr r3, [r7, r3] */
/* @0x1ee720 str r0, [r3] */
/* @0x1ee724 add sp, sp, #1280 */
/* @0x1ee728 add sp, sp, #12 */
/* @0x1ee72c vpop {d8, d9} */
/* @0x1ee730 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 25 置 0 后回图形通道（1edde8 与 1ee158 的 beq 目标）───────────────────────
 *   SetRenderState(25, 0)；b 0x1ede1c。⇒ 「队列里没东西」时把 25 清 0 再立即画。
 */

/* @0x1ee734 mov r0, r5 */
/* @0x1ee738 mov r1, #25 */
/* @0x1ee73c mov r2, #0 */
/* @0x1ee740 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee744 b 0x1ede1c <_ZN7CSprite9DrawShapeEiiifffffjjf+0x6b4> */
/* ── sqrtf 回退 A：|e1|² 开方失败（NaN）时走 libm ──────────────────────────────
 *   vmov r0,s17；bl sqrtf@plt；vmov s15,r0；b 0x1ee554（回到 max 比较）。
 *   1ee758 是 e2 的同构回退（b 0x1ee594）。
 *   ★ 两条回退证明源码用的是 sqrtf() 而不是纯 vsqrt（编译器给了 fast-path + 回退两条腿）。
 */

/* @0x1ee748 vmov r0, s17 */
/* @0x1ee74c bl 0xb6700 <sqrtf@plt> */
/* @0x1ee750 vmov s15, r0 */
/* @0x1ee754 b 0x1ee554 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xdec> */
/* @0x1ee758 vmov r0, s15 */
/* @0x1ee75c bl 0xb6700 <sqrtf@plt> */
/* @0x1ee760 vmov s14, r0 */
/* @0x1ee764 b 0x1ee594 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xe2c> */

/* ── 收束：两段的共同结论与互相印证 ─────────────────────────────────────────────
 *   1. 形参：DrawSWF(i, ox, oy, x, y, xs, ys, rot, colour, alpha) —— 前两个 float 是原点，
 *      由四处调用点里三处的取参互证（1ec97c/1ec98c、1eccd0 段、1ed144/1ed148）；DrawShape(i, j, k, x, y, xs, ys, rot,
 *      c1, c2, alpha) —— 由唯一入口 F_DrawShape 0x11c038 的 12 个 YYGet* 互证。
 *   2. 角度：两段都没有 π/180 ⇒ 纹理档 1ec7f0 的「乘 π 除 180」只服务 GR_Texture_* 两路。
 *   3. 矩阵：两段都是 64 B 列主序 4×4，平移 e12/e13、缩放 e0/e5、齐次 e15 = 1.0f；
 *      共用的全局 float g（GOT 0x3f0ddc）在平移里除、在缩放里乘。
 *   4. 状态：DrawSWF 自洽（进函数存 8 个、出函数还原 8 个）；DrawShape 靠 a1 == −1/−2 的
 *      跨调用协议（保存 6 个到 .bss，正常路径只还原其中 24/4 两处，25 只由 −2 还原）。
 *   5. 输出：两段都不直接出像素 —— DrawSWF → DrawSWFObject（逐时间线子项），
 *      DrawShape → DrawDictionaryItem（逐形状，4 个调用点）。
 *   6. 零字段写：DrawSWF 119 条 store 全部落在本帧栈或自己的 alloca 数组；
 *      DrawShape 189 条里 18 条写非栈内存，写的是队列记录/计数器/6 个状态槽，仍然 0 条写 this。
 *
 * ── open ─────────────────────────────────────────────────────────────────────
 *   1. 字段官方名：CSprite +0x54（tpe 表）、+0x7c（对象指针数组）、+0x80（数组长度）、
 *      +0x84（影片/时间线）都只有用法证据，没有符号/字符串证据。
 *   2. GOT 0x3f0ddc（float g）、0x3ee5d0（字节开关）、0x3ed924（纹理表）、0x3ed928（float z）、
 *      0x3f014c/0x3f0150（两个 int 标量）、0x3f0480（int，判非 0）均无 .dynsym 可核（本仓库无 .so 副本）。
 *   3. this+0x84 的帧表：索引步长 ×8 与「记录 ≥ 0x18 B、子项 144 B」不自洽（1ec250 vs 1ec408/1ec410）。
 *   4. 图形通道里 sp+320/sp+324 两字从未被写（1edf9c/1edfd0 只覆盖 sp+304..319）⇒ 第三条边的来源未定。
 *   5. DrawShape 入队语义：1ee108 把计数写成「槽位+1」而 1ee024 起只覆盖一条 228 B 记录 ⇒
 *      「LIFO + 按 k 截断」是读法之一，但没有调用序列可以证伪/证实。
 *   6. DrawSWFObject 的第 8 形参 bool（1ec59c 读全局字节 / 其余两处恒 0）与 DrawDictionaryItem 的
 *      b4/b5 语义（0 与「源对象 +0xd4 字节」/「全局 0x3f0480 ≠ 0」）都未定。
 *   7. f3（DrawDictionaryItem 第 3 形参）三处取值：队头绘制 0.0（1edae8）、入队后立即画 1.0（1ee1b8）、
 *      图形通道 g2/(0.5·max)（1ee5c8）—— 语义未定（可能是描边宽度或某种归一化因子）。
 *   8. DrawShape 的 228 B 记录里 +0x4c..+0x8b 那第二个 64 B 块的用途未定（它被当 p6 传给
 *      DrawDictionaryItem 的第 6 形参 yyMatrix*）。
 */

/* ── 引用面（本轮只读，未改任何其它文件）────────────────────────────────────────
 *   asm/index-CSprite_DrawSWF.tsv（518 行）  asm/index-CSprite_DrawShape.tsv（1024 行）
 *   asm/functions.tsv:5320（DrawSWF 符号/尺寸）、:5327（DrawShape 符号/尺寸）、:5319（DrawSWFObject）
 *   cards/CSprite_Draw.c（纹理档三函数，作差异对照）  cards/auto/bank_0049.c:141-221（F_DrawShape 实参）
 *   cards/auto/bank_0166.c:1934-1980（DrawDictionaryItem 取参，用于反推矩阵拆分）
 *   scripts/check_card_anchors.py（RESULT EXACT 的判定器）
 */

