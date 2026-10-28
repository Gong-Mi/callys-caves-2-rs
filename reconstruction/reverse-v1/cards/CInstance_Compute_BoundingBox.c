/* cally 逆向卡：CInstance::Compute_BoundingBox(bool)（原版 libyoyo.so，armv7）
 * @func 0x192340 0x1928d4  size 1428  357 条（350 条指令 + 末 7 字 0x1927cc..0x1927e4 为 literal pool；
 *       0x1928d4 是 1 字填充，不属于本函数；下一个符号是 CInstance::Compute_Speed1 0x1928d8）
 * 级别: 正文（357/357 逐条落锚。两条几何路径的算式逐条解出；掩码选择、两套取整选择的真值表、
 *       四个 bbox 字段的写入顺序与整数类型、尾部脏标记清除、CollisionUpdate 的入参来源全部钉死。
 *       未钉的只是三个 .bss 字节与 spr 字段的官方名，不是控制流或算式。tier = bytecode_anchored）
 * 符号: _ZN9CInstance19Compute_BoundingBoxEb → void CInstance::Compute_BoundingBox(bool updateRTree)
 * 位置: CInstance::SetSpriteIndex 0x1931c0 之后、CInstance::Compute_Speed1 0x1928d8 之前
 * 调用点: 全图 70 处 bl（按 cond=AL 的 BL 编码扫 .text 得）。其中 36 处在 HandleOther 0x1cf52c..0x1cffe8，
 *       全部来自「+0x64 脏标记 → 惰性重算」派发（见 HandleOther 卡）；其余 34 处落在尚未出卡的函数里。
 *       抽样的 13 处中 12 处是 mov r1,#1（true），1 处（0x1ca94c）传寄存器 r4。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   「掩码精灵优先」取 CSprite，把精灵的四条 bbox 边按 image_xscale/yscale（含 image_angle 的旋转）
 *   换算成实例的整数包围盒 +0xE8/+0xEC/+0xF0/+0xF4，清 +0x64 脏标记；updateRTree 为真时把
 *   「计算前的旧盒」交给 CollisionUpdate —— 它先按旧盒从 RTree 摘除、再按新盒插入。
 *
 * ── 语义草案（可编译；CVT 见「已证 4」）────────────────────────────────────
 *   void CInstance::Compute_BoundingBox(bool updateRTree) {
 *     if (*(char*)0x757e7c) CProfiler::Push(*(void**)0x757e80, 6, 2);     // 0x192360..0x192364 / 0x192664
 *     YYRECT old = this->bbox;                                            // +0xe8..+0xf4 → [sp]（0x192378/0x192380）
 *     int idx = (this->mask_index >= 0) ? this->mask_index : this->sprite_index;   // +0xac / +0x8c
 *     CSprite* s = Sprite_Data(idx);                                      // 0x19238c
 *     if (!s) {                                                           // 0x192398 → 0x1928ac
 *       this->bbox.left = this->bbox.right  = (int)this->x;               // 截断，不看 flag
 *       this->bbox.top  = this->bbox.bottom = (int)this->y;
 *       this->[0xb0] = 0;                                                 // Sprite_Data 返回值 0 的低字节
 *       goto done;
 *     }
 *     int L=s->[8], T=s->[0xc], R=s->[0x10], B=s->[0x14], H=s->[0x24], V=s->[0x28];
 *     float sx = this->image_xscale, sy = this->image_yscale, ang = this->image_angle;
 *     bool trunc = (*(char*)0x542379 != 0) && (*(char*)0x54237a == 0);
 *
 *     if (ang == 0) {                                                    // 0x1923a8 → 0x19267c
 *       int l = CVT(this->x + sx*(L - H));                               // 以 spr 的 x 边与 x 原点为基准
 *       int r = CVT(l + sx*((R + 1) - L));                               // ★ 以已取整的 l 为基准，不是从 x 重算
 *       int t = CVT(this->y + sy*(T - V));
 *       int b = CVT(t + sy*((B + 1) - T));
 *       if (r < l) { int u=l; l=r; r=u; }                                // 0x192738/0x19273c
 *       if (b < t) { int u=t; t=b; b=u; }                                // 0x1927a4/0x1927a8
 *       this->bbox.left=l; this->bbox.top=t; this->bbox.right=r-1; this->bbox.bottom=b-1;
 *     } else {                                                           // 0x1923ac 起
 *       float rad = ang * 3.14159274f / 180.0f;                          // 池字 0x40490fdb / 0x43340000
 *       float c = cosf(rad), s = sinf(rad);                              // 0xb658c / 0xb6580
 *       // 边选择：min 边取 lo、max 边取 hi+1；L>=R / T>=B 时按同一规则换边（0x1923c0..0x1923d8、0x192400..0x192418）
 *       float h1 = (min(L,R) - H)*sx, h2 = ((max(L,R) + 1) - H)*sx;
 *       float v1 = (min(T,B) - V)*sy, v2 = ((max(T,B) + 1) - V)*sy;
 *       this->bbox.left   =   CVT(this->x + min(c*h1, c*h2) + min(s*v1, s*v2));
 *       this->bbox.right  =   CVT(this->x + max(c*h1, c*h2) + max(s*v1, s*v2)) - 1;
 *       this->bbox.top    =   CVT(this->y + min(c*v1, c*v2) - max(s*h1, s*h2));
 *       this->bbox.bottom =   CVT(this->y + max(c*v1, c*v2) - min(s*h1, s*h2)) - 1;
 *     }
 *     this->[0xb0] = s->[0x30];                                          // 0x19256c/0x192570 或 0x1927ac/0x1927c0
 *   done:
 *     this->[0x64] = 0;                                                  // 0x19257c
 *     if (updateRTree) CollisionUpdate(this, old);                       // 0x192654（先 Remove(旧) 再 Insert(新)）
 *     if (*(char*)0x757e7c) CProfiler::Pop();                            // 0x192584..0x192598
 *   }
 *   注意 x/y 的 ±1 不对称：min 边原样、max 边统一 -1（轴对齐档在公共尾 0x1927ac..0x1927c4 减，旋转档在各自
 *   出口减）。两条路径的 x 与 y 用同一套取整开关，但取整发生在不同位置：轴对齐档先取整 min 边再以它为基准算
 *   max 边，旋转档把整条和式一次取整。
 *
 * ── 字段与全局（本卡读写的全部地址）────────────────────────────────────────
 *   this+0x08c  int   sprite_index（SetSpriteIndex 0x1931c8 写；本函数 0x192388 读）
 *   this+0x098  f32   image_xscale        this+0x09c  f32  image_yscale
 *   this+0x0a0  f32   image_angle（==0 → 轴对齐路径）
 *   this+0x0ac  int   mask_index（>=0 时优先于 sprite_index；<0 = 无掩码）
 *   this+0x0b0  u8    写点 = spr+0x30；另有 Assign 0x19874c/0x19877c、DeSerialise 0x1978dc 的整字段拷贝。
 *                     已索引函数里**没有读点** ⇒ 语义未定（形似碰撞掩码类别）
 *   this+0x0b4  f32   x                   this+0x0b8  f32  y
 *   this+0x0e8/+0x0ec/+0x0f0/+0x0f4  int32 ×4 = tagYYRECT {left, top, right, bottom}
 *   this+0x064  u8    bbox 脏标记：SetObjectIndex 0x193344 与 SetSpriteIndex 0x193204 置 1，本函数 0x19257c 清 0
 *   spr+0x008 / spr+0x010  int  x 方向两条边      spr+0x00c / spr+0x014  int  y 方向两条边
 *   spr+0x024 / spr+0x028  int  原点 x/y（旁证：CSprite::Draw 0x1ec804/0x1ec810 把这两个字段当原点偏移传下去）
 *   spr+0x030  u8     原样拷进 this+0x0b0（名字未定）
 *   0x542379 / 0x54237a  u8 ×2  取整模式（本函数只读，真值表见「已证 4」）
 *   0x757e7c  u8      g_bProfile（非 0 才 Push/Pop）    0x757e80  g_Profiler 对象
 *   GOT 基址 0x3f1c58（add r7, pc, r7，0x19235c）；四个槽 0x3edb70 / 0x3edb74 / 0x3f0688 / 0x3f068c，
 *   全是 R_ARM_RELATIVE，槽内 addend 直读得上表四个 .bss 地址（本卡末段池字逐条解出）。
 *
 * ── 已证（指令级，每条都能落到锚点）──────────────────────────────────────
 *  1. 掩码关系：idx = (mask_index >= 0) ? mask_index : sprite_index。0x192374 读 +0xac、0x19237c cmp、
 *     movge/ldrlt 二选一（0x192384/0x192388），再 bl Sprite_Data。Sprite_Data 自身对 idx<0 或
 *     idx >= 精灵总数返回 0（Sprite_Data 卡已证）⇒ 「mask 越界」与「无精灵」在这里合流成同一条空路径。
 *  2. 空精灵路径（0x1928ac..0x1928d0）：bbox 退化成点盒 left=right=(int)x、top=bottom=(int)y，
 *     取整是 vcvt.s32（截断，不受两个 flag 影响）；同时 this+0xb0 = 0（0x1928b8 存的是 r0 的低字节，
 *     此处 r0 = Sprite_Data 的返回值 0）。
 *  3. 轴对齐路径（ang == 0，0x19267c 起）：先把 spr 的四条边原样播到 +0xe8..+0xf4（0x192694..0x1926a0），
 *     再算 w+1 = (R+1)-L、h+1 = (B+1)-T（0x1926b4/0x1926b8/0x1926bc/0x1926d0），
 *     left = CVT(x + sx*(L-H))、right = CVT(left + sx*(w+1))（0x1926fc..0x192730 截断档 /
 *     0x1927f4..0x192844 lrint 档）；sx<0 时靠 strlt 交换（0x192738/0x19273c）。
 *     y 同理：top = CVT(y + sy*(T-V))、bottom = CVT(top + sy*(h+1))（0x19275c..0x1927a8 截断档 /
 *     0x19284c..0x1928a4 lrint 档），bb<tt 时 0x1927a4/0x1927a8 交换。
 *  4. 取整模式真值表（两处独立闸：0x1924a0/0x1924a8 与 0x192524/0x19252c，轴对齐侧 0x192740/0x192748，
 *     旋转 y 侧同构）：设 A = 0x542379、B = 0x54237a 两个字节，
 *       A == 0            → lrint   （0x1924a4 / 0x1926d4 的 beq 走 lrint 档）
 *       A != 0 && B != 0  → lrint   （0x1924b8 / 0x1926e8 的 bne 走 lrint 档）
 *       A != 0 && B == 0  → 截断    （vcvt.s32.f32，只在这一格出现）
 *     截断档会把常量 1 放进 r3/r12（0x1924c4 / 0x192704），让后面「复用同一个寄存器」的第二道闸必然
 *     走截断分支 —— 这是编译器把「同一开关用两次」压成一个寄存器的结果，不是第三个条件。
 *  5. 四个 bbox 字段是 int32，不是 float：写入用 vcvt.s32.f32（把结果做成整数位）再 vstr（0x1924e0、
 *     0x1924dc、0x192560、0x1927c4 等），读侧 CollisionUpdate 0x1cdc84..0x1cdc9c 用 ldr（不是 vldr）
 *     取 +0xe8/+0xec/+0xf0/+0xf4，并把 min/max 后的 int* 交给 RTree::Remove / InsertRect。
 *     ⇒ 「+0xe8..+0xf4 是 float」不成立（任务上下文里的这条前提按本卡改正）。
 *  6. 旋转路径的偏移与符号：x = c*ox + s*oy、y = c*oy - s*ox（两轴符号不同是代码事实：x 侧 vadd
 *     0x1924c0/0x1924c8，y 侧 vsub 0x192548/0x192558）。ox 用 (lo-H) 与 (hi+1)-H 两档，oy 用 (lo-V) 与
 *     (hi+1)-V 两档；L>=R / T>=B（精灵自带反向 bbox）时两档对调（0x1923c4..0x1923d8、0x192410..0x192418、
 *     0x1925a8..0x1925c8）。
 *  7. min/max 归一：旋转 x 侧先比 c*h2 与 c*h1（0x19246c），按 PL 交换成 (min,max)（0x192474/0x19247c）；
 *     s*v 的那一对用「先算 vcmpe 再在 vmovpl 里用上一次 vmrs 的 APSR」（0x19248c 读的是 0x192470 的旗标，
 *     0x192494..0x19249c 读的是 0x192490 的旗标），四个组合都收敛到 min_x+min_y / max_x+max_y，逐条核过。
 *     y 侧同构（0x1924fc..0x192520）。
 *  8. 尾部：+0xb0 ← spr+0x30（0x19256c/0x192570 旋转档；0x1927ac/0x1927c0 轴对齐档）；
 *     +0x64 = 0（0x192578/0x19257c，无条件）；r10（= 入口 r1 = updateRTree）非 0 → 0x192654
 *     CollisionUpdate(this, [sp])；最后按 g_bProfile 决定 bl CProfiler::Pop() 后 pop 返回。
 *  9. old 盒的来源：入口 0x192378 ldm r6(=this+0xe8) 四条 → 0x192380 stm sp 四条，全程没有回写，
 *     所以 CollisionUpdate 拿到的是**重算前**的盒。CollisionUpdate 0x1cdcd8 先 RTree::Remove(旧盒的
 *     min/max 角)，0x1cdcf4..0x1cdd04 再按 this+0xe8..+0xf4（新盒）RTree::InsertRect。
 * 10. 几条必经的拦截在 CollisionUpdate 里而非本函数：先是「0x542379 字节 == 0 就直接返回」（0x1cdc30..
 *     0x1cdc3c，GOT 0x3f0688 ——**与本函数 flagA 同一个字节**），再是 inst+0x68、inst+0x69、
 *     对象 flags bit4（0x1cdc40..0x1cdc6c），任一不满足就只返回、不碰 RTree。本函数无条件调用，不自己判。
 * 11. 于是 flagA(0x542379) 的作用面比本函数大：它为 0 时 ① bbox 走 lrint（浮点精确）② CollisionUpdate 整个
 *     不工作（RTree 既不摘也不插）。两件事同源 ⇒ flagA 更像「启用 RTree 精确碰撞」的开关，
 *     这也解释了为什么同一个字节要同时决定取整：不进 RTree 时整数盒没有消费者。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. 0x542379 / 0x54237a 两个字节**只有读点**（本函数 4 处读 A、2 处读 B，外加 CollisionUpdate 1 处读 A），写点未找到 ⇒
 *     名字与谁在什么时候置位未定；只证真值表与「flagA 同时管 RTree 开关」。邻位只有两条命名证据：
 *     0x542374 = g_ObjectHash 指针、0x542378 = option_test_fast_collision（Object_Name 卡），
 *     所以这两个字节很可能同属一块 option 字节区。
 *  2. spr+0x08/+0x0c/+0x10/+0x14 与 +0x24/+0x28 的名字是本卡按用法命名的：x 端/ y 端 / 原点 x / 原点 y。
 *     其中 +0x24/+0x28 有 CSprite::Draw 的旁证；四个边字段在本卡内没有写点，谁在装载 SPRT 时填、填的是
 *     file 里的 (left,right,bottom,top) 还是已归一化成 (left,top,right,bottom)，未证。
 *  3. this+0xb0 无读点（已索引函数范围内），语义未定；本卡只证「= spr+0x30 的字节」。
 *  4. bbox 的区间约定：max 边一律 -1，min 边不减 ⇒ 看起来是闭区间；但 CollisionUpdate 交给 RTree 的是
 *     (lo, hi) 两个角点，RTree 侧是否再 -1/+1 未验证，所以「闭/半开」不下结论。
 *  5. 轴对齐档的 right 以**已取整的 left** 为基准（0x19271c/0x192720），负坐标时与「先算浮点右边界再取整」
 *     不等价（差 1 px 量级）。这是代码事实，但是否即设计意图（还是 1.4 runner 的已知取整怪癖）未定。
 *  6. cosf/sinf 的入参用 softfp 传（float 位在 r0、返回值也在 r0），与 Android armeabi 的调用约定一致；
 *     本卡不涉及 libm 实现，lrint 的舍入模式按 C 默认（就近偶数）记录，未在目标上实测。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────────────────
 */
/* ── 1. 入口：帧、GOT 基址、第二实参进 r10、profiler 闸（0x192340..0x19236c）──
 *   r4 = this、r10 = updateRTree、r7 = GOT 基址 0x3f1c58（0x19235c add r7,pc,r7）；
 *   r9 = *(GOT 0x3edb70) = 0x757e7c（g_bProfile 的地址），0x192364 取它的字节。
 *   非 0 直接跳 0x192664 压 6/2 段，压完回 0x192370。 */
/* @0x192340 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— r4 = this */
/* @0x192344 vpush {d8, d9, d10, d11} */
/* @0x192348 mov r4, r0 */
/* @0x19234c ldr r7, [pc, #0x480] —— pc 相对池字 → 0x1927d4 = 0x0025f8f4（GOT 基址偏移） */
/* @0x192350 sub sp, sp, #20 */
/* @0x192354 ldr r3, [pc, #0x47c] */
/* @0x192358 mov r10, r1 —— r10 = 第二实参 updateRTree */
/* @0x19235c add r7, pc, r7 —— r7 = 0x192364 + 0x0025f8f4 = 0x3f1c58（GOT 基址） */
/* @0x192360 ldr r9, [r7, r3] —— r9 = *(GOT 0x3edb70) = 0x757e7c（g_bProfile 地址） */
/* @0x192364 ldrb r3, [r9] */
/* @0x192368 cmp r3, #0 */
/* @0x19236c bne 0x192664 <_ZN9CInstance19Compute_BoundingBoxEb+0x324> —— g_bProfile 非 0 → 0x192664 压 profiler 段 */
/* ── 2. 旧盒快照到栈 + 选精灵：mask_index ≥ 0 优先，否则 sprite_index（0x192370..0x192398）──
 *   0x192378 ldm r6,{r0..r3} 从 this+0xe8 取四条 / 0x192380 stm sp 四条 —— 这份 [sp] 就是后面 CollisionUpdate 的入参。
 *   0x19237c..0x192388：r12 = this+0xac，非负取 r12、否则取 this+0x8c，进 r0 调 Sprite_Data。 */
/* @0x192370 add r6, r4, #232 */
/* @0x192374 ldr r12, [r4, #0xac] —— r12 = this->mask_index(+0xac) */
/* @0x192378 ldm r6, {r0, r1, r2, r3} —— r6 = this+0xe8，四字段快照起点 */
/* @0x19237c cmp r12, #0 */
/* @0x192380 stm sp, {r0, r1, r2, r3} —— 旧盒 → [sp]（CollisionUpdate 的入参） */
/* @0x192384 movge r0, r12 —— mask_index ≥ 0 → 用 mask_index */
/* @0x192388 ldrlt r0, [r4, #0x8c] —— 否则用 sprite_index(+0x8c) */
/* @0x19238c bl 0x1ef03c <_Z11Sprite_Datai> —— Sprite_Data(idx) */
/* @0x192390 cmp r0, #0 */
/* @0x192394 mov r5, r0 */
/* @0x192398 beq 0x1928ac <_ZN9CInstance19Compute_BoundingBoxEb+0x56c> —— 无精灵 → 0x1928ac 点盒 */
/* ── 3. 角度闸：image_angle(+0xa0) == 0 → 轴对齐路径 0x19267c（0x19239c..0x1923a8）── */
/* @0x19239c vldr s14, [r4, #160] */
/* @0x1923a0 vcmp.f32 s14, #0 */
/* @0x1923a4 vmrs APSR_nzcv, fpscr */
/* @0x1923a8 beq 0x19267c <_ZN9CInstance19Compute_BoundingBoxEb+0x33c> —— angle == 0 → 0x19267c 轴对齐路径 */
/* ── 4. 旋转路径之一：四条边换成「相对原点的有符号偏移」，再算 cos/sin（0x1923ac..0x192434）──
 *   L=spr[8]、R=spr[0x10]、T=spr[0xc]、B=spr[0x14]、H=spr[0x24]、V=spr[0x28]；
 *   L<R 档：s21=(L-H)*sx、s18=((R+1)-H)*sx；L≥R 档：s21=(R-H)*sx、s18=((L+1)-H)*sx（0x1923c4..0x1923d8）。
 *   垂直同理（0x192410..0x192418 / 0x1925a8..0x1925c8）。0x192434/0x192438 从池取 pi 与 180.0f，
 *   0x19243c vmul、0x192440 vdiv 得弧度。 */
/* @0x1923ac ldr r2, [r0, #0x8] */
/* @0x1923b0 vldr s15, [r4, #152] */
/* @0x1923b4 ldr r3, [r0, #0x10] */
/* @0x1923b8 vldr s13, [r4, #156] */
/* @0x1923bc ldr r1, [r0, #0x24] */
/* @0x1923c0 cmp r2, r3 */
/* @0x1923c4 rsblt r3, r1, r3 —— L<R 档：r3 = R-H */
/* @0x1923c8 rsbge r2, r1, r2 —— L≥R 档：r2 = L-H */
/* @0x1923cc rsblt r1, r1, r2 */
/* @0x1923d0 rsbge r1, r1, r3 */
/* @0x1923d4 addlt r3, r3, #1 */
/* @0x1923d8 addge r2, r2, #1 */
/* @0x1923dc vmovlt s21, r1 */
/* @0x1923e0 vmovlt s18, r3 */
/* @0x1923e4 ldr r3, [r0, #0x14] */
/* @0x1923e8 vmovge s21, r1 */
/* @0x1923ec ldr r1, [r0, #0x28] */
/* @0x1923f0 vmovge s18, r2 */
/* @0x1923f4 ldr r2, [r0, #0xc] */
/* @0x1923f8 vcvt.f32.s32 s21, s21 */
/* @0x1923fc cmp r2, r3 */
/* @0x192400 vcvt.f32.s32 s18, s18 */
/* @0x192404 vmul.f32 s21, s15, s21 */
/* @0x192408 vmul.f32 s18, s15, s18 */
/* @0x19240c blt 0x1925a8 <_ZN9CInstance19Compute_BoundingBoxEb+0x268> */
/* @0x192410 rsb r2, r1, r2 */
/* @0x192414 rsb r1, r1, r3 */
/* @0x192418 add r2, r2, #1 */
/* @0x19241c vmov s22, r1 */
/* @0x192420 vmov s11, r2 */
/* @0x192424 vcvt.f32.s32 s22, s22 */
/* @0x192428 vcvt.f32.s32 s23, s11 */
/* @0x19242c vmul.f32 s22, s13, s22 */
/* @0x192430 vmul.f32 s23, s13, s23 */
/* ── 5. 旋转路径之二：x 侧 c*h 与 s*v 分开归一出 min/max（0x192434..0x19249c）──
 *   0x19246c 比 c*h2 与 c*h1 → 0x192474/0x19247c 交换成 (min,max)；
 *   0x192488 比 s*v 那一对，0x19248c 用的还是**上一次** vmrs 的旗标（横向结论），
 *   0x192490 vmrs 之后 0x192494..0x19249c 才按纵向结论交换。四种组合都收敛，逐条核过。 */
/* @0x192434 vldr s19, [pc, #912] */
/* @0x192438 vldr s15, [pc, #912] */
/* @0x19243c vmul.f32 s14, s14, s19 —— angle*pi */
/* @0x192440 vdiv.f32 s19, s14, s15 —— rad = angle*pi/180 */
/* @0x192444 vmov r0, s19 */
/* @0x192448 bl 0xb658c <cosf@plt> —— cosf(softfp: float 位在 r0) */
/* @0x19244c vmov s17, r0 */
/* @0x192450 vmov r0, s19 */
/* @0x192454 bl 0xb6580 <sinf@plt> —— sinf */
/* @0x192458 vmul.f32 s20, s17, s21 */
/* @0x19245c ldr r3, [pc, #0x378] */
/* @0x192460 ldr r6, [r7, r3] */
/* @0x192464 ldrb r3, [r6] */
/* @0x192468 vmul.f32 s13, s17, s18 */
/* @0x19246c vcmpe.f32 s13, s20 —— 比 c*s18 与 c*s21 */
/* @0x192470 vmrs APSR_nzcv, fpscr */
/* @0x192474 vmovpl.f32 s15, s20 —— PL(s13≥s20) → s15 = 较小者 */
/* @0x192478 vmov s16, r0 */
/* @0x19247c vmovpl.f32 s20, s13 —— PL → s20 = 较大者 */
/* @0x192480 vmul.f32 s14, s16, s23 */
/* @0x192484 vmul.f32 s19, s16, s22 */
/* @0x192488 vcmpe.f32 s14, s19 */
/* @0x19248c vmovpl.f32 s13, s15 —— 旗标来自 0x192470 的 vmrs（横向），s13 变成 min_h */
/* @0x192490 vmrs APSR_nzcv, fpscr —— 此后旗标来自纵向 vcmpe */
/* @0x192494 vmovpl.f32 s15, s19 */
/* @0x192498 vmovpl.f32 s19, s14 */
/* @0x19249c vmovpl.f32 s14, s15 */
/* ── 6. 取整模式闸 A：A(0x542379) 非 0 才可能截断（0x1924a0..0x1924b8）──
 *   0x1924a4 beq → lrint 档；否则读 B(0x54237a)，0x1924b8 bne → 也走 lrint 档；只剩 A!=0 且 B==0 落到截断。 */
/* @0x1924a0 cmp r3, #0 —— A = 0x542379 字节 */
/* @0x1924a4 beq 0x192610 <_ZN9CInstance19Compute_BoundingBoxEb+0x2d0> —— A == 0 → lrint 档 0x192610 */
/* @0x1924a8 ldr r3, [pc, #0x330] */
/* @0x1924ac ldr r3, [r7, r3] —— B = 0x54237a 字节 */
/* @0x1924b0 ldrb r3, [r3] */
/* @0x1924b4 cmp r3, #0 */
/* @0x1924b8 bne 0x192610 <_ZN9CInstance19Compute_BoundingBoxEb+0x2d0> —— B != 0 → lrint 档 */
/* ── 7. 旋转 x 截断档：left=(int)(x+min_c+min_s)，right=(int)(x+max_c+max_s)-1（0x1924bc..0x1924e8）──
 *   0x1924c4 把 r3 置 1（下面第二道闸必然走截断）。0x1924e0 写 +0xe8、0x1924e8 写 +0xf0（差 1）。 */
/* @0x1924bc vldr s15, [r4, #180] */
/* @0x1924c0 vadd.f32 s20, s20, s15 */
/* @0x1924c4 mov r3, #1 —— 截断档标记：第二道闸复用 r3 */
/* @0x1924c8 vadd.f32 s19, s20, s19 */
/* @0x1924cc vadd.f32 s13, s15, s13 */
/* @0x1924d0 vcvt.s32.f32 s19, s19 */
/* @0x1924d4 vmov r1, s19 */
/* @0x1924d8 vadd.f32 s14, s13, s14 */
/* @0x1924dc vcvt.s32.f32 s14, s14 */
/* @0x1924e0 vstr s14, [r4, #232] —— +0xe8 = left（整数位） */
/* @0x1924e4 sub r2, r1, #1 */
/* @0x1924e8 str r2, [r4, #0xf0] —— +0xf0 = right - 1 */
/* ── 8. 旋转 y 的四组乘积：c*v 与 s*h 各自取 min/max（0x1924ec..0x192524）──
 *   0x1924fc/0x192504 两次 vcmpe，交换靠 0x192508..0x192510（用第一次 vmrs）与 0x192518..0x192520（第二次）。 */
/* @0x1924ec vmul.f32 s15, s17, s23 */
/* @0x1924f0 vmul.f32 s17, s17, s22 */
/* @0x1924f4 vmul.f32 s18, s16, s18 */
/* @0x1924f8 vmul.f32 s16, s16, s21 */
/* @0x1924fc vcmpe.f32 s15, s17 */
/* @0x192500 vmrs APSR_nzcv, fpscr */
/* @0x192504 vcmpe.f32 s18, s16 */
/* @0x192508 vmovpl.f32 s14, s17 */
/* @0x19250c vmovpl.f32 s17, s15 */
/* @0x192510 vmovpl.f32 s15, s14 */
/* @0x192514 vmrs APSR_nzcv, fpscr */
/* @0x192518 vmovpl.f32 s14, s16 */
/* @0x19251c vmovpl.f32 s16, s18 */
/* @0x192520 vmovpl.f32 s18, s14 */
/* ── 9. 取整模式闸 B（复用 r3）+ 旋转 y 截断档（0x192524..0x192568）──
 *   截断档进来时 r3 = 1（0x1924c4），lrint 档进来时 r3 = A 的字节（0x192644 重读）⇒ 同一寄存器两种含义。
 *   top=(int)(y+min_c-max_s) 写 +0xec（0x192560），bottom=(int)(y+max_c-min_s)-1 写 +0xf4（0x192568）。 */
/* @0x192524 cmp r3, #0 —— 截断档 r3 = 1 / lrint 档 r3 = A */
/* @0x192528 beq 0x1925d0 <_ZN9CInstance19Compute_BoundingBoxEb+0x290> */
/* @0x19252c ldr r3, [pc, #0x2ac] */
/* @0x192530 ldr r3, [r7, r3] */
/* @0x192534 ldrb r3, [r3] */
/* @0x192538 cmp r3, #0 */
/* @0x19253c bne 0x1925d0 <_ZN9CInstance19Compute_BoundingBoxEb+0x290> */
/* @0x192540 vldr s14, [r4, #184] */
/* @0x192544 vadd.f32 s17, s17, s14 */
/* @0x192548 vsub.f32 s18, s17, s18 */
/* @0x19254c vadd.f32 s15, s14, s15 */
/* @0x192550 vcvt.s32.f32 s18, s18 */
/* @0x192554 vmov r1, s18 */
/* @0x192558 vsub.f32 s16, s15, s16 */
/* @0x19255c vcvt.s32.f32 s16, s16 */
/* @0x192560 vstr s16, [r4, #236] —— +0xec = top（整数位） */
/* @0x192564 sub r3, r1, #1 */
/* @0x192568 str r3, [r4, #0xf4] —— +0xf4 = bottom - 1 */
/* ── 10. 收尾 A：+0xb0 ← spr+0x30、清 +0x64、updateRTree 非 0 → CollisionUpdate（0x19256c..0x192580）── */
/* @0x19256c ldrb r3, [r5, #0x30] —— spr+0x30 字节 */
/* @0x192570 strb r3, [r4, #0xb0] —— +0xb0 ← spr+0x30 */
/* @0x192574 cmp r10, #0 */
/* @0x192578 mov r3, #0 —— r3 = 0 */
/* @0x19257c strb r3, [r4, #0x64] —— +0x64 = 0（脏标记清除，无条件） */
/* @0x192580 bne 0x192654 <_ZN9CInstance19Compute_BoundingBoxEb+0x314> —— updateRTree 非 0 → 0x192654 */
/* ── 11. profiler 出口与返回（0x192584..0x1925a4）── */
/* @0x192584 ldrb r3, [r9] */
/* @0x192588 cmp r3, #0 */
/* @0x19258c beq 0x19259c <_ZN9CInstance19Compute_BoundingBoxEb+0x25c> */
/* @0x192590 ldr r3, [pc, #0x24c] —— g_bProfile */
/* @0x192594 ldr r0, [r7, r3] */
/* @0x192598 bl 0x2a08ac <_ZN9CProfiler3PopEv> —— CProfiler::Pop() */
/* @0x19259c add sp, sp, #20 */
/* @0x1925a0 vpop {d8, d9, d10, d11} */
/* @0x1925a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 12. 垂直偏移第二档（T<B）→ 回 0x192434（0x1925a8..0x1925cc）── */
/* @0x1925a8 rsb r3, r1, r3 */
/* @0x1925ac rsb r1, r1, r2 */
/* @0x1925b0 add r3, r3, #1 */
/* @0x1925b4 vmov s22, r1 */
/* @0x1925b8 vmov s15, r3 */
/* @0x1925bc vcvt.f32.s32 s22, s22 */
/* @0x1925c0 vcvt.f32.s32 s23, s15 */
/* @0x1925c4 vmul.f32 s22, s13, s22 */
/* @0x1925c8 vmul.f32 s23, s13, s23 */
/* @0x1925cc b 0x192434 <_ZN9CInstance19Compute_BoundingBoxEb+0xf4> */
/* ── 13. 旋转 y 的 lrint 档（0x1925d0..0x19260c）──
 *   与 0x192540 同一组 min/max 值，只把 vcvt.s32 换成 vcvt.f64+lrint；bottom 仍 -1。 */
/* @0x1925d0 vldr s14, [r4, #184] */
/* @0x1925d4 vadd.f32 s15, s15, s14 */
/* @0x1925d8 vsub.f32 s16, s15, s16 */
/* @0x1925dc vcvt.f64.f32 d6, s16 */
/* @0x1925e0 vmov r0, r1, d6 */
/* @0x1925e4 bl 0xb66e8 <lrint@plt> */
/* @0x1925e8 vldr s15, [r4, #184] */
/* @0x1925ec vadd.f32 s17, s17, s15 */
/* @0x1925f0 vsub.f32 s18, s17, s18 */
/* @0x1925f4 vcvt.f64.f32 d7, s18 */
/* @0x1925f8 str r0, [r4, #0xec] */
/* @0x1925fc vmov r0, r1, d7 */
/* @0x192600 bl 0xb66e8 <lrint@plt> */
/* @0x192604 sub r0, r0, #1 */
/* @0x192608 str r0, [r4, #0xf4] */
/* @0x19260c b 0x19256c <_ZN9CInstance19Compute_BoundingBoxEb+0x22c> */
/* ── 14. 旋转 x 的 lrint 档（0x192610..0x192650）──
 *   0x192644 重读 A 的字节到 r3，供 0x192524 的第二道闸复用。 */
/* @0x192610 vldr s15, [r4, #180] */
/* @0x192614 vadd.f32 s13, s13, s15 */
/* @0x192618 vadd.f32 s14, s13, s14 */
/* @0x19261c vcvt.f64.f32 d6, s14 */
/* @0x192620 vmov r0, r1, d6 */
/* @0x192624 bl 0xb66e8 <lrint@plt> */
/* @0x192628 vldr s15, [r4, #180] */
/* @0x19262c vadd.f32 s20, s20, s15 */
/* @0x192630 vadd.f32 s19, s20, s19 */
/* @0x192634 vcvt.f64.f32 d7, s19 */
/* @0x192638 str r0, [r4, #0xe8] */
/* @0x19263c vmov r0, r1, d7 */
/* @0x192640 bl 0xb66e8 <lrint@plt> */
/* @0x192644 ldrb r3, [r6] */
/* @0x192648 sub r0, r0, #1 */
/* @0x19264c str r0, [r4, #0xf0] */
/* @0x192650 b 0x1924ec <_ZN9CInstance19Compute_BoundingBoxEb+0x1ac> */
/* ── 15. CollisionUpdate(this, &[sp])（0x192654..0x192660）──
 *   [sp] 是入口那份**旧**盒；CollisionUpdate 内部先 RTree::Remove(旧) 再 InsertRect(this+0xe8 新)。 */
/* @0x192654 mov r0, r4 —— CollisionUpdate(this, [sp])：旧盒 */
/* @0x192658 mov r1, sp */
/* @0x19265c bl 0x1cdc1c <_Z15CollisionUpdateP9CInstanceR9tagYYRECT> */
/* @0x192660 b 0x192584 <_ZN9CInstance19Compute_BoundingBoxEb+0x244> */
/* ── 16. CProfiler::Push(g_Profiler, 6, 2)（0x192664..0x192678）──
 *   0x192664 池字 0xffffbf1c → GOT 0x3edb74 → 0x757e80（g_Profiler）。 */
/* @0x192664 ldr r3, [pc, #0x178] —— 池字 → 0x3edb74 = &g_Profiler */
/* @0x192668 mov r1, #6 —— 段号 r1 = 6 */
/* @0x19266c mov r2, #2 —— 段号 r2 = 2 */
/* @0x192670 ldr r0, [r7, r3] */
/* @0x192674 bl 0x2a0738 <_ZN9CProfiler4PushEii> —— CProfiler::Push */
/* @0x192678 b 0x192370 <_ZN9CInstance19Compute_BoundingBoxEb+0x30> */
/* ── 17. 轴对齐路径（angle == 0）：四边原样播到 +0xe8..+0xf4，再算 w+1 / h+1 与取整闸（0x19267c..0x1926e8）──
 *   0x192684 是带写回的 [r3,#8]!，所以后面 r0/r1/r3 用 +4/+8/+0xc 取到 T/R/B。
 *   0x1926b4 加 1（w+1）、0x1926bc 求 (R+1)-L；0x1926d4/0x1926e8 两道闸决定下面走截断还是 lrint。 */
/* @0x19267c mov r3, r0 */
/* @0x192680 ldr r2, [pc, #0x154] */
/* @0x192684 ldr r12, [r3, #0x8]! —— 带写回：[r3+8] → r12(=L)，r3 += 8 */
/* @0x192688 ldr r0, [r3, #0x4] */
/* @0x19268c ldr r1, [r3, #0x8] */
/* @0x192690 ldr r3, [r3, #0xc] */
/* @0x192694 str r12, [r4, #0xe8] —— +0xe8 = spr[8]（L） */
/* @0x192698 str r0, [r6, #0x4] —— +0xec = spr[0xc]（T） */
/* @0x19269c str r1, [r6, #0x8] —— +0xf0 = spr[0x10]（R） */
/* @0x1926a0 str r3, [r6, #0xc] —— +0xf4 = spr[0x14]（B） */
/* @0x1926a4 ldr r6, [r7, r2] */
/* @0x1926a8 ldr r0, [r4, #0xf0] */
/* @0x1926ac ldr r3, [r4, #0xe8] */
/* @0x1926b0 ldrb r2, [r6] */
/* @0x1926b4 add r0, r0, #1 —— (R+1) */
/* @0x1926b8 ldr r1, [r4, #0xf4] */
/* @0x1926bc rsb r0, r3, r0 —— w+1 = (R+1)-L */
/* @0x1926c0 cmp r2, #0 */
/* @0x1926c4 ldr r2, [r4, #0xec] */
/* @0x1926c8 add r1, r1, #1 */
/* @0x1926cc vmov s16, r0 */
/* @0x1926d0 rsb r11, r2, r1 —— h+1 = (B+1)-T */
/* @0x1926d4 beq 0x1927e8 <_ZN9CInstance19Compute_BoundingBoxEb+0x4a8> —— A == 0 → x 的 lrint 档 */
/* @0x1926d8 ldr r1, [pc, #0x100] */
/* @0x1926dc ldr r1, [r7, r1] */
/* @0x1926e0 ldrb r1, [r1] */
/* @0x1926e4 cmp r1, #0 */
/* @0x1926e8 bne 0x1927e8 <_ZN9CInstance19Compute_BoundingBoxEb+0x4a8> —— B != 0 → x 的 lrint 档 */
/* ── 18. 轴对齐 x 截断档：left=(int)(x+sx*(L-H))，right=(int)(left+sx*((R+1)-L))（0x1926ec..0x192730）──
 *   0x19271c 把已取整的 left 转回 float 再 vmla（0x192720）—— right 以整数 left 为基准。
 *   0x192730 先把 right 落到 +0xf0，再在 0x192734 判序。 */
/* @0x1926ec ldr r1, [r5, #0x24] */
/* @0x1926f0 vldr s14, [r4, #152] */
/* @0x1926f4 vldr s15, [r4, #180] */
/* @0x1926f8 vcvt.f32.s32 s16, s16 */
/* @0x1926fc rsb r3, r1, r3 —— L-H */
/* @0x192700 mov r1, r2 */
/* @0x192704 mov r12, #1 */
/* @0x192708 vmov s11, r3 */
/* @0x19270c vcvt.f32.s32 s13, s11 */
/* @0x192710 vmla.f32 s15, s14, s13 —— left_f = x + sx*(L-H) */
/* @0x192714 vcvt.s32.f32 s15, s15 —— 截断 */
/* @0x192718 vmov r3, s15 */
/* @0x19271c vcvt.f32.s32 s15, s15 */
/* @0x192720 vmla.f32 s15, s14, s16 —— right_f = left_int + sx*(w+1) */
/* @0x192724 str r3, [r4, #0xe8] —— +0xe8 = left */
/* @0x192728 vcvt.s32.f32 s15, s15 */
/* @0x19272c vmov r2, s15 */
/* @0x192730 vstr s15, [r4, #240] —— +0xf0 = right（待 0x192734 判序） */
/* ── 19. x 的 min/max 归位（sx<0 时交换）：0x192738 写 +0xe8、0x19273c 写 +0xf0（0x192734..0x19273c）── */
/* @0x192734 cmp r2, r3 */
/* @0x192738 strlt r2, [r4, #0xe8] —— right<left → +0xe8 = right */
/* @0x19273c strlt r3, [r4, #0xf0] —— 并 +0xf0 = left（旧值） */
/* ── 20. y 的取整模式闸（r12 在截断档里是常量 1、在 lrint 档里是 A 的字节，0x192834 重读）（0x192740..0x192758）── */
/* @0x192740 cmp r12, #0 —— r12：截断档为 1，lrint 档为 A */
/* @0x192744 beq 0x19284c <_ZN9CInstance19Compute_BoundingBoxEb+0x50c> —— r12 == 0 → y 的 lrint 档 0x19284c */
/* @0x192748 ldr r3, [pc, #0x90] */
/* @0x19274c ldr r3, [r7, r3] */
/* @0x192750 ldrb r3, [r3] */
/* @0x192754 cmp r3, #0 */
/* @0x192758 bne 0x19284c <_ZN9CInstance19Compute_BoundingBoxEb+0x50c> —— B != 0 → y 的 lrint 档 */
/* ── 21. 轴对齐 y 截断档：top=(int)(y+sy*(T-V))、bottom=(int)(top+sy*((B+1)-T))（0x19275c..0x1927a8）── */
/* @0x19275c ldr r2, [r5, #0x28] */
/* @0x192760 vmov s11, r11 */
/* @0x192764 vldr s14, [r4, #156] */
/* @0x192768 vldr s15, [r4, #184] */
/* @0x19276c rsb r2, r2, r1 */
/* @0x192770 vcvt.f32.s32 s13, s11 */
/* @0x192774 vmov s11, r2 */
/* @0x192778 vcvt.f32.s32 s12, s11 */
/* @0x19277c vmla.f32 s15, s14, s12 */
/* @0x192780 vcvt.s32.f32 s15, s15 */
/* @0x192784 vmov r2, s15 */
/* @0x192788 vcvt.f32.s32 s15, s15 */
/* @0x19278c vmla.f32 s15, s14, s13 */
/* @0x192790 str r2, [r4, #0xec] */
/* @0x192794 vcvt.s32.f32 s15, s15 */
/* @0x192798 vmov r3, s15 */
/* @0x19279c vstr s15, [r4, #244] */
/* @0x1927a0 cmp r3, r2 */
/* @0x1927a4 strlt r3, [r4, #0xec] */
/* @0x1927a8 movlt r3, r2 */
/* ── 22. 轴对齐公共尾：+0xb0 ← spr+0x30、bottom=max-1、right=max-1（0x1927ac..0x1927c8）── */
/* @0x1927ac ldrb r2, [r5, #0x30] —— spr+0x30 字节 */
/* @0x1927b0 sub r1, r3, #1 —— max(top,bottom) - 1 */
/* @0x1927b4 ldr r3, [r4, #0xf0] */
/* @0x1927b8 str r1, [r4, #0xf4] —— +0xf4 = bottom - 1 */
/* @0x1927bc sub r3, r3, #1 —— right - 1 */
/* @0x1927c0 strb r2, [r4, #0xb0] —— +0xb0 ← spr+0x30 */
/* @0x1927c4 str r3, [r4, #0xf0] —— +0xf0 = right - 1 */
/* @0x1927c8 b 0x192574 <_ZN9CInstance19Compute_BoundingBoxEb+0x234> */
/* ── 23. literal pool 7 字（非指令）：0x40490fdb(pi)、0x43340000(180.0f)、0x0025f8f4(GOT 基址)、
 *   0xffffbf18(→0x3edb70 = g_bProfile)、0xffffea30(→0x3f0688 = 0x542379)、
 *   0xffffea34(→0x3f068c = 0x54237a)、0xffffbf1c(→0x3edb74 = g_Profiler)（0x1927cc..0x1927e4）── */
/* @0x1927cc ldrdmi r0, r1, [r9], #-251 —— 非指令：0x40490fdb = 3.14159274f */
/* @0x1927d0 teqmi r4, #0 —— 非指令：0x43340000 = 180.0f */
/* @0x1927d4 .word 0x0025f8f4 —— 非指令：0x0025f8f4（GOT 基址偏移） */
/* @0x1927d8 .word 0xffffbf18 —— 非指令：0xffffbf18 → 槽 0x3edb70 = 0x757e7c */
/* @0x1927dc .word 0xffffea30 —— 非指令：0xffffea30 → 槽 0x3f0688 = 0x542379 */
/* @0x1927e0 .word 0xffffea34 —— 非指令：0xffffea34 → 槽 0x3f068c = 0x54237a */
/* @0x1927e4 .word 0xffffbf1c —— 非指令：0xffffbf1c → 槽 0x3edb74 = 0x757e80 */
/* ── 24. 轴对齐 x 的 lrint 档（0x1927e8..0x192848）── */
/* @0x1927e8 ldr r2, [r5, #0x24] */
/* @0x1927ec vldr s14, [r4, #152] */
/* @0x1927f0 vldr s15, [r4, #180] */
/* @0x1927f4 rsb r3, r2, r3 */
/* @0x1927f8 vmov s12, r3 */
/* @0x1927fc vcvt.f32.s32 s13, s12 */
/* @0x192800 vmla.f32 s15, s13, s14 */
/* @0x192804 vcvt.f64.f32 d6, s15 */
/* @0x192808 vmov r0, r1, d6 */
/* @0x19280c bl 0xb66e8 <lrint@plt> */
/* @0x192810 vldr s14, [r4, #152] */
/* @0x192814 vcvt.f32.s32 s16, s16 */
/* @0x192818 vmov s13, r0 */
/* @0x19281c str r0, [r4, #0xe8] */
/* @0x192820 vcvt.f32.s32 s15, s13 */
/* @0x192824 vmla.f32 s15, s16, s14 */
/* @0x192828 vcvt.f64.f32 d6, s15 */
/* @0x19282c vmov r0, r1, d6 */
/* @0x192830 bl 0xb66e8 <lrint@plt> */
/* @0x192834 ldrb r12, [r6] */
/* @0x192838 ldr r3, [r4, #0xe8] */
/* @0x19283c ldr r1, [r4, #0xec] */
/* @0x192840 mov r2, r0 */
/* @0x192844 str r0, [r4, #0xf0] */
/* @0x192848 b 0x192734 <_ZN9CInstance19Compute_BoundingBoxEb+0x3f4> */
/* ── 25. 轴对齐 y 的 lrint 档（0x19284c..0x1928a8）── */
/* @0x19284c ldr r2, [r5, #0x28] */
/* @0x192850 vldr s14, [r4, #156] */
/* @0x192854 vldr s15, [r4, #184] */
/* @0x192858 rsb r2, r2, r1 */
/* @0x19285c vmov s12, r2 */
/* @0x192860 vcvt.f32.s32 s13, s12 */
/* @0x192864 vmla.f32 s15, s13, s14 */
/* @0x192868 vcvt.f64.f32 d6, s15 */
/* @0x19286c vmov r0, r1, d6 */
/* @0x192870 bl 0xb66e8 <lrint@plt> */
/* @0x192874 vldr s14, [r4, #156] */
/* @0x192878 vmov s11, r11 */
/* @0x19287c vmov s13, r0 */
/* @0x192880 str r0, [r4, #0xec] */
/* @0x192884 vcvt.f32.s32 s15, s13 */
/* @0x192888 vcvt.f32.s32 s13, s11 */
/* @0x19288c vmla.f32 s15, s13, s14 */
/* @0x192890 vcvt.f64.f32 d6, s15 */
/* @0x192894 vmov r0, r1, d6 */
/* @0x192898 bl 0xb66e8 <lrint@plt> */
/* @0x19289c ldr r2, [r4, #0xec] */
/* @0x1928a0 mov r3, r0 */
/* @0x1928a4 str r0, [r4, #0xf4] */
/* @0x1928a8 b 0x1927a0 <_ZN9CInstance19Compute_BoundingBoxEb+0x460> */
/* ── 26. Sprite_Data 返回 0：bbox 退化成 (trunc x, trunc y) 点盒，+0xb0 = 0（0x1928ac..0x1928d0）── */
/* @0x1928ac vldr s14, [r4, #180] —— s14 = x */
/* @0x1928b0 vldr s15, [r4, #184] */
/* @0x1928b4 vcvt.s32.f32 s14, s14 —— (int)x（截断） */
/* @0x1928b8 strb r0, [r4, #0xb0] —— +0xb0 = 0（r0 = Sprite_Data 的 0） */
/* @0x1928bc vcvt.s32.f32 s15, s15 */
/* @0x1928c0 vstr s14, [r4, #232] —— +0xe8 = (int)x */
/* @0x1928c4 vstr s14, [r4, #240] —— +0xf0 = (int)x */
/* @0x1928c8 vstr s15, [r4, #236] —— +0xec = (int)y */
/* @0x1928cc vstr s15, [r4, #244] —— +0xf4 = (int)y */
/* @0x1928d0 b 0x192574 <_ZN9CInstance19Compute_BoundingBoxEb+0x234> */
