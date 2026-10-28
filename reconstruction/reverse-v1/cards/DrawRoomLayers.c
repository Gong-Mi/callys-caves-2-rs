/* cally 逆向卡：DrawRoomLayers（原版 libyoyo.so，armv7）
 * @func 0x1b3938 0x1b3b0c size 472  118 条（115 条指令 + 1b3b04..1b3b0c 三个字面量池字，前两个被 objdump 译成指令）
 * 级别: 骨架（118/118 锚定。层链**从尾到头**的遍历方向、层链按 +0x04 升序的外部证据、两套深度来源与
 *             写它们的 GML 内建、SetLayerShader/ResetLayerShader 与前后两个层脚本的夹心结构、7 路元素分派表、
 *             type 2 的「实例已停用就跳掉本层剩余元素」这道门、尾调 Graphics::Flush 全部逐条钉住。
 *             两个深度全局的身份（0x5425e8/0x5425ec）由 layer_force_draw_depth / layer_get_forced_depth /
 *             layer_is_draw_depth_forced 三个内建的读写共同钉死。
 *             未钉：CLayer+0x18 的正式名（行为=整层可见性）、+0x20/+0x24 两个脚本槽在 GML 侧的名字、
 *             type 2 元素 +0x20 为 0 时仍照画的意图、7 个 DrawLayer*Element 内部画法（各应独立成卡））
 * 符号: _Z14DrawRoomLayersP9tagYYRECT → void DrawRoomLayers(tagYYRECT* pRect)
 * 同层: DrawTheRoom 0x1b3b10（唯一调用者：room+0xdc > 0 时先本函数、后发事件 73）、
 *       SetLayerShader 0x1b1128 / ResetLayerShader 0x1b1170、ExecuteLayerScript 0x1b3418、
 *       DrawLayerBackgroundElement 0x1b11a0 / DrawLayerInstanceElement 0x1b1600 /
 *       DrawLayerOldTilemapElement 0x1b1784 / DrawLayerSpriteElement 0x1b193c /
 *       DrawLayerTilemapElement 0x1b2124 / DrawLayerParticleElement 0x1b2834 /
 *       DrawLayerTileElement 0x1b283c、GR_3D_Set_Depth 0x1631dc、Graphics::Flush 0x1852ec、
 *       F_LayerForceDrawDepth 0x1b6864（唯一写本函数读的那两个全局的函数）、
 *       F_LayerIsDrawDepthForced 0x1b5ee4 / F_LayerGetForcedDepth 0x1b5f18（两个全局的读方内建）、
 *       InsertLayerIntoActiveList 0x1c30f8（层链有序插入的现场）、GetLayerWithDepth 0x1b87f4（靠顺序早退）
 *       GOT 基址不常驻：三个全局各用一次「字面量 + ldr pc 相对」现取槽（1b3938 / 1b3974 / 1b3988）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把一个房间的图层从上到下画一遍（每视图一次，void）：room+0xd8 起沿 prev 反向走完整条层链；每层先过可见性，
 *   再设一次 3D 深度（层的 +0x04，或被 layer_force_draw_depth 强制成同一个值），套上该层 shader，跑前脚本，
 *   沿 layer+0x58 正向画完层内元素（7 路按 type 分派，type 2 遇到已停用实例会直接跳掉本层剩余元素），
 *   跑后脚本、复位 shader，最后尾调 Graphics::Flush。
 *
 * ── 绘制顺序（本题重点 1）─────────────────────────────────────
 *   a) 起点是**链尾**：1b3958 取 room+0xd8（不是 +0xd4 的链头）；循环末尾 1b3a34 取 [层+0x6c] = prev。
 *      ⇒ 本函数的遍历方向 = 层链的逆序。后插进链尾的层先画，链头的层最后画（最后画 = 压在最上面）。
 *   b) 层链本身按 depth 升序：InsertLayerIntoActiveList（0x1c30f8）先扫 room+0xd4 链，跳过所有
 *      「层 depth <= 新层 depth」的项，插在第一个更深的层之前（1c313c..1c317c）；GetLayerWithDepth 也
 *      把这个顺序当契约用（命中 depth 判等，层 depth > 目标就直接返回 0，0x1b881c/0x1b8854）。
 *      ⇒ 合成结论：**depth 大的先画、depth 小的后画**，小 depth 覆盖大 depth —— 与 GameMaker「depth 越小越靠前」同向。
 *      ⚠ 这个结论只在链有序时成立。DuplicateRoomLayers 是沿源链**尾插**（1c4f04..1c4f18）而不是有序插入，
 *        房间文件里层记录若不是按 depth 排好，本函数画出来的叠放顺序就与文件顺序成反比 —— 顺序真相在链上，
 *        不在本函数里。
 *   c) 层内元素从 layer+0x58 正向走（+0x14 = next，1b39c4/1b3a0c），即按元素入链顺序画，先入链的先画。
 *      入链位置由 AddElementToLayer 的第 4 实参决定（false=头插、true=尾插，见 AddInstanceToLayer 卡）。
 *
 * ── 每层做的四件事（顺序固定）────────────────────────────────────
 *   1. 可见性门：layer+0x18 字节为 0 → 整层跳过（不设深度、不跑脚本、不画元素，1b3968..1b3970）。
 *   2. 深度：1b3974 读字节 0x5425ec；为 0 → 用 (float)layer+0x04（1b3ae8）；非 0 → 用
 *      (float)*(int*)0x5425e8，所有层同一个深度（1b3990）。两层含义见下节。
 *   3. shader：SetLayerShader(layer+0x28)。该函数 0x1b1128 开头 cmn r0,#1 为真（即 -1）就原地返回，
 *      否则把 shader 号当 double 喂 F_Shader_Set(0x1e207c)。⇒ layer+0x28 = 该层绑定的 shader 号，-1 = 不绑。
 *   4. 前脚本 / 元素 / 后脚本 / 复位 shader：
 *        ExecuteLayerScript(layer+0x00, layer+0x20, 8, 0)  ← 层 id, 脚本 id, 事件类型 8, 0
 *        …元素循环…
 *        ExecuteLayerScript(layer+0x00, layer+0x24, 8, 0)
 *        ResetLayerShader(layer+0x28) → F_Shader_Reset(0x1e2110)
 *      ExecuteLayerScript 在 r1 == -1 时也原地返回（1b3418 的 cmn r1,#1），所以 +0x20/+0x24 允许是 -1。
 *      它把 0x54290c / 0x542908 / 0x542904 三个全局槽（分别接层 id / 8 / 第 4 实参）和 0x544be0 临时换掉再恢复，
 *      再按 0x47f295 字节二选一（0x542610 里的指针 —— 形似 self 实例，未证 —— 或 0x544be0）调
 *      Script_Perform(0x1e0774)，最后按 RValue 的 kind 决定是否 FREE_RValue__Pre。
 *      ⇒ 「层脚本」在机器层就是「把层 id 塞进全局上下文、拿事件常量 8 跑一个脚本 id」；8 与 DrawTheRoom 调
 *        ExecuteDrawEvent(pRect, 8, 72) 用的是同一个常量（Draw_Room 卡记作 ev_draw）。
 *
 * ── 深度：两套来源，一个全局开关（本题重点 2）────────────────────
 *   0x5425ec byte  非 0 ⇒ 本函数忽略每层自己的 depth，全部用 0x5425e8 的值
 *   0x5425e8 int   被强制的绘制深度（float 化后进 GR_3D_Set_Depth）
 *   这两个全局的身份由整个内建族坐实（全 .text 的 GOT 槽扫描，四类访问点全部命中）：
 *     写：F_LayerForceDrawDepth 0x1b6864（GML layer_force_draw_depth）—— YYGetBool(args[0]) → 0x5425ec
 *         （1b68a0 strb）、YYGetInt32(args[1]) → 0x5425e8（1b68b4 str），argc != 2 走 Error_Show(0xecd7c)。
 *         args 取自内建实参数组、与源码书写序相反，所以源码里的 (depth, force) 正好落成「args[0]=force」。
 *     读：本函数 1b3978（字节）/ 1b398c（int）；
 *         F_LayerIsDrawDepthForced 0x1b5ee4 → 读 0x5425ec 并返回 bool（layer_is_draw_depth_forced）；
 *         F_LayerGetForcedDepth 0x1b5f18 → 读 0x5425e8、int→double 返回（layer_get_forced_depth）。
 *   ⇒ 「0x5425e8/0x5425ec = 强制绘制深度与其开关」不是靠字段形状猜的，是三个内建函数的读写共同钉的。
 *   ⚠ 本函数每层都调一次 GR_3D_Set_Depth，层与层之间**不恢复**深度；函数收尾也不设深度 ——
 *     DrawTheRoom 是在事件 73 之前才补 -13000（见 DrawTheRoom 卡）。
 *
 * ── 元素 7 路分派（跳表在 1b39dc..1b39f8，基址 = 1b39e0）────────────
 *   r3 = elem+0x00 - 1；cmp r3,#6；addls pc,pc,r3,lsl#2 ⇒
 *     type 1 background  → 1b3aa8  DrawLayerBackgroundElement
 *     type 2 instance    → 1b3abc  DrawLayerInstanceElement（**带门**，见下）
 *     type 3 old tilemap → 1b3a94  DrawLayerOldTilemapElement
 *     type 4 sprite      → 1b3a80  DrawLayerSpriteElement
 *     type 5 tilemap     → 1b3a60  DrawLayerTilemapElement(rect, layer, elem, 0.0f, 0.0f, 0.0f)
 *     type 6 particle    → 1b3a4c  DrawLayerParticleElement
 *     type 7 tile        → 1b39fc  DrawLayerTileElement（1b39f8 只是 b 1b39fc 的跳板）
 *     其它（0 或 >7）    → 1b39dc 直接跳过该元素，链照常推进
 *   三个类身份与 DuplicateRoomLayers 卡的尺寸表对得上：type 1=32 B、2=36 B、3=52 B、4=72 B、5=60 B、
 *   6=32 B、7=80 B；本卡只按 type 调函数，不读元素内部字段（唯一例外是 type 2 的 +0x20）。
 *   type 5 的三个 float 实参全为 0：r3 = 0，[sp] 与 [sp+4] = r7（本函数全函数恒 0）。这 12 B 栈帧就是为它们开的。
 *
 * ── type 2 的门：停用的实例会掐掉本层剩余元素（实测语义，容易读漏）────
 *   1b3abc：r3 = elem+0x20（CInstance*）
 *     · 为 0            → 照画（元素没挂实例时反而无条件画）
 *     · 非 0，读 +0x69   → 为 0 照画；非 0 → **bne 1b3a18**
 *   1b3a18 不是「跳过这一个元素」，而是「本层元素循环的出口」：它直接去跑后脚本 + 复位 shader + 走下一层。
 *   ⇒ 一个已停用（+0x69 = 1，见 CInstance::SetDeactivated 0x19230c 的 strb r1,[r0,#0x69]）的实例元素，
 *     会让它**后面**的同层元素全部不画。等价的源码形态是 for 循环里那句 `if (inst->deactivated) break;`
 *     打穿了 switch —— 这是行为事实，是否有意未证（记 open）。
 *
 * ── 出口 ─────────────────────────────────────────────────────
 *   正常（含「一层都没有」）：1b3964 直接落到 1b3a40 → add sp,#12 → pop {r4,r5,r6,r7,lr} →
 *     b Graphics::Flush(0x1852ec) 尾调。⇒ **没有任何层时也会 flush**。
 *   room == 0：1b3afc → add sp,#12 → pop {r4,r5,r6,r7,pc}，**不 flush**。
 *   本函数无返回值（两条出口都不定义 r0）。
 *
 * ── 全局（槽内值 = R_ARM_RELATIVE 目标）──────────────────────────
 *   槽 0x3ed930 → 0x54298c  CRoom* Run_Room（1b3938/1b3940 现取；与 DrawTheRoom 卡同址）
 *   槽 0x3f0838 → 0x5425ec  byte 强制深度开关（1b3974/1b3978）
 *   槽 0x3f083c → 0x5425e8  int  强制深度值（1b3988/1b398c）
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */
/* ── 帧 + 取房 + 空房直接返回 ────────────────────────────────
 *   push {r4,r5,r6,r7,lr} + sub sp,#12（12 B 只装 type 5 的两个栈 float，余 4 B 对齐）。
 *   r6 = pRect（全程只读，元素绘制时原样转发）。r7 在 1b3960 被置 0 且此后不再改写 ⇒ 全函数恒 0。
 *   1b3938 的字面量在 1b3b04（0x00239fe8），1b3940 用它算出槽 0x3ed930，取 [槽] = &Run_Room，再解引用得 room。
 */

/* @0x1b3938 ldr r3, [pc, #0x1c4] */
/* @0x1b393c push {r4, r5, r6, r7, lr} */
/* @0x1b3940 ldr r3, [pc, r3] */
/* @0x1b3944 sub sp, sp, #12 */
/* @0x1b3948 mov r6, r0 */
/* @0x1b394c ldr r3, [r3] */
/* @0x1b3950 cmp r3, #0 */
/* @0x1b3954 beq 0x1b3afc <_Z14DrawRoomLayersP9tagYYRECT+0x1c4> */

/* ── 层链：从链尾进，空链也去 flush ───────────────────────────
 *   r5 = room+0xd8（链尾）；r5 == 0 → 1b3a40（照样 flush）。
 *   ⇒ 「有没有层」与「要不要 flush」无关；room==0 才是唯一不 flush 的出口。
 */

/* @0x1b3958 ldr r5, [r3, #0xd8] */
/* @0x1b395c cmp r5, #0 */
/* @0x1b3960 movne r7, #0 */
/* @0x1b3964 beq 0x1b3a40 <_Z14DrawRoomLayersP9tagYYRECT+0x108> */

/* ── 层循环头（每轮回到这里）：可见性门 + 深度 ────────────────
 *   1b3968 读层 +0x18 字节，为 0 → 1b3a34（下一层，连 shader/脚本都不碰）。
 *   1b3974..1b3984 读 0x5425ec：为 0 → 1b3ae8（用层自己的 depth），非 0 → 1b3988（用强制值）。
 */

/* @0x1b3968 ldrb r3, [r5, #0x18] */
/* @0x1b396c cmp r3, #0 */
/* @0x1b3970 beq 0x1b3a34 <_Z14DrawRoomLayersP9tagYYRECT+0xfc> */
/* @0x1b3974 ldr r3, [pc, #0x18c] */
/* @0x1b3978 ldr r3, [pc, r3] */
/* @0x1b397c ldrb r3, [r3] */
/* @0x1b3980 cmp r3, #0 */
/* @0x1b3984 beq 0x1b3ae8 <_Z14DrawRoomLayersP9tagYYRECT+0x1b0> */

/* ── 强制深度分支：所有层同一个深度 ─────────────────────────
 *   r3 = 槽 0x3f083c 指向的 int（0x5425e8）→ s15 = (float)r3 → GR_3D_Set_Depth。
 */

/* @0x1b3988 ldr r3, [pc, #0x17c] */
/* @0x1b398c ldr r3, [pc, r3] */
/* @0x1b3990 ldr r0, [r3] */
/* @0x1b3994 vmov s15, r0 */
/* @0x1b3998 vcvt.f32.s32 s15, s15 */
/* @0x1b399c vmov r0, s15 */
/* @0x1b39a0 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */

/* ── shader + 前脚本 ─────────────────────────────────────────
 *   SetLayerShader(layer+0x28)；ExecuteLayerScript(layer+0x00, layer+0x20, 8, 0)。
 *   ⚠ 这两个调用的顺序固定：shader 先绑、前脚本后跑 ⇒ 前脚本里设的绘制状态可以覆盖层 shader。
 */

/* @0x1b39a4 ldr r0, [r5, #0x28] */
/* @0x1b39a8 bl 0x1b1128 <_Z14SetLayerShaderi> */
/* @0x1b39ac ldr r0, [r5] */
/* @0x1b39b0 ldr r1, [r5, #0x20] */
/* @0x1b39b4 mov r2, #8 */
/* @0x1b39b8 mov r3, #0 */
/* @0x1b39bc bl 0x1b3418 <_Z18ExecuteLayerScriptiiii> */

/* ── 元素链头 + type 分派（跳表在 1b39dc，执行基址 1b39e0）──────
 *   r4 = layer+0x58；为 0 → 1b3a18（不画元素，但仍跑后脚本）。
 *   r3 = [r4] - 1；> 6 → 落到 1b39dc 的默认项（跳过该元素）。
 */

/* @0x1b39c0 ldr r4, [r5, #0x58] */
/* @0x1b39c4 cmp r4, #0 */
/* @0x1b39c8 beq 0x1b3a18 <_Z14DrawRoomLayersP9tagYYRECT+0xe0> */
/* @0x1b39cc ldr r3, [r4] */
/* @0x1b39d0 sub r3, r3, #1 */
/* @0x1b39d4 cmp r3, #6 */
/* @0x1b39d8 addls pc, pc, r3, lsl #2 */
/* @0x1b39dc b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */
/* @0x1b39e0 b 0x1b3aa8 <_Z14DrawRoomLayersP9tagYYRECT+0x170> */
/* @0x1b39e4 b 0x1b3abc <_Z14DrawRoomLayersP9tagYYRECT+0x184> */
/* @0x1b39e8 b 0x1b3a94 <_Z14DrawRoomLayersP9tagYYRECT+0x15c> */
/* @0x1b39ec b 0x1b3a80 <_Z14DrawRoomLayersP9tagYYRECT+0x148> */
/* @0x1b39f0 b 0x1b3a60 <_Z14DrawRoomLayersP9tagYYRECT+0x128> */
/* @0x1b39f4 b 0x1b3a4c <_Z14DrawRoomLayersP9tagYYRECT+0x114> */
/* @0x1b39f8 b 0x1b39fc <_Z14DrawRoomLayersP9tagYYRECT+0xc4> */

/* ── type 7：tile 元素（跳板落点）─────────────────────────── */

/* @0x1b39fc mov r0, r6 */
/* @0x1b3a00 mov r1, r5 */
/* @0x1b3a04 mov r2, r4 */
/* @0x1b3a08 bl 0x1b283c <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement> */

/* ── 元素循环尾：+0x14 前进，非 0 回分派 ──────────────────── */

/* @0x1b3a0c ldr r4, [r4, #0x14] */
/* @0x1b3a10 cmp r4, #0 */
/* @0x1b3a14 bne 0x1b39cc <_Z14DrawRoomLayersP9tagYYRECT+0x94> */

/* ── 后脚本 + 复位 shader（也是 type 2 停用时的落点）─────────
 *   顺序：后脚本（layer+0x24）先、ResetLayerShader(layer+0x28) 后。
 */

/* @0x1b3a18 ldr r0, [r5] */
/* @0x1b3a1c mov r2, #8 */
/* @0x1b3a20 ldr r1, [r5, #0x24] */
/* @0x1b3a24 mov r3, #0 */
/* @0x1b3a28 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii> */
/* @0x1b3a2c ldr r0, [r5, #0x28] */
/* @0x1b3a30 bl 0x1b1170 <_Z16ResetLayerShaderi> */

/* ── 下一层：r5 = [r5+0x6c]（prev），非 0 回 1b3968 ──────────
 *   ⇒ 这就是「逆序遍历」唯一的一条边：+0x6c 是 prev。
 */

/* @0x1b3a34 ldr r5, [r5, #0x6c] */
/* @0x1b3a38 cmp r5, #0 */
/* @0x1b3a3c bne 0x1b3968 <_Z14DrawRoomLayersP9tagYYRECT+0x30> */

/* ── 正常出口：尾调 Graphics::Flush ────────────────────────── */

/* @0x1b3a40 add sp, sp, #12 */
/* @0x1b3a44 pop {r4, r5, r6, r7, lr} */
/* @0x1b3a48 b 0x1852ec <_ZN8Graphics5FlushEv> */

/* ── type 6：particle 元素 ─────────────────────────────────── */

/* @0x1b3a4c mov r0, r6 */
/* @0x1b3a50 mov r1, r5 */
/* @0x1b3a54 mov r2, r4 */
/* @0x1b3a58 bl 0x1b2834 <_Z24DrawLayerParticleElementP9tagYYRECTP6CLayerP21CLayerParticleElement> */
/* @0x1b3a5c b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */

/* ── type 5：tilemap 元素（三个 float 实参 = 0）──────────────
 *   r3 = 0 = 第 4 实参；str r7,[sp] 与 str r7,[sp,#4] = 第 5/6 实参（r7 恒 0）。
 */

/* @0x1b3a60 str r7, [sp] */
/* @0x1b3a64 mov r0, r6 */
/* @0x1b3a68 str r7, [sp, #0x4] */
/* @0x1b3a6c mov r1, r5 */
/* @0x1b3a70 mov r2, r4 */
/* @0x1b3a74 mov r3, #0 */
/* @0x1b3a78 bl 0x1b2124 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff> */
/* @0x1b3a7c b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */

/* ── type 4：sprite 元素 ───────────────────────────────────── */

/* @0x1b3a80 mov r0, r6 */
/* @0x1b3a84 mov r1, r5 */
/* @0x1b3a88 mov r2, r4 */
/* @0x1b3a8c bl 0x1b193c <_Z22DrawLayerSpriteElementP9tagYYRECTP6CLayerP19CLayerSpriteElement> */
/* @0x1b3a90 b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */

/* ── type 3：old tilemap 元素 ──────────────────────────────── */

/* @0x1b3a94 mov r0, r6 */
/* @0x1b3a98 mov r1, r5 */
/* @0x1b3a9c mov r2, r4 */
/* @0x1b3aa0 bl 0x1b1784 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement> */
/* @0x1b3aa4 b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */

/* ── type 1：background 元素 ───────────────────────────────── */

/* @0x1b3aa8 mov r0, r6 */
/* @0x1b3aac mov r1, r5 */
/* @0x1b3ab0 mov r2, r4 */
/* @0x1b3ab4 bl 0x1b11a0 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement> */
/* @0x1b3ab8 b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */

/* ── type 2：instance 元素（唯一的条件分支）──────────────────
 *   elem+0x20 == 0 → 1b3ad4 照画；!= 0 且 [实例+0x69] != 0 → 1b3a18（跳掉本层剩余元素）。
 *   注意 1b3ac4 的 beq 目标是「画」，1b3ad0 的 bne 目标是「层尾」—— 两个方向别读反。
 */

/* @0x1b3abc ldr r3, [r4, #0x20] */
/* @0x1b3ac0 cmp r3, #0 */
/* @0x1b3ac4 beq 0x1b3ad4 <_Z14DrawRoomLayersP9tagYYRECT+0x19c> */
/* @0x1b3ac8 ldrb r3, [r3, #0x69] */
/* @0x1b3acc cmp r3, #0 */
/* @0x1b3ad0 bne 0x1b3a18 <_Z14DrawRoomLayersP9tagYYRECT+0xe0> */
/* @0x1b3ad4 mov r0, r6 */
/* @0x1b3ad8 mov r1, r5 */
/* @0x1b3adc mov r2, r4 */
/* @0x1b3ae0 bl 0x1b1600 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement> */
/* @0x1b3ae4 b 0x1b3a0c <_Z14DrawRoomLayersP9tagYYRECT+0xd4> */

/* ── 用层自己的 depth（0x5425ec == 0 时）─────────────────────
 *   s15 = (float)(int)layer+0x04；GR_3D_Set_Depth 后与强制分支汇合到 1b39a4。
 */

/* @0x1b3ae8 vldr s15, [r5, #4] */
/* @0x1b3aec vcvt.f32.s32 s15, s15 */
/* @0x1b3af0 vmov r0, s15 */
/* @0x1b3af4 bl 0x1631dc <_Z15GR_3D_Set_Depthf> */
/* @0x1b3af8 b 0x1b39a4 <_Z14DrawRoomLayersP9tagYYRECT+0x6c> */

/* ── 空房出口：pop {r4,r5,r6,r7,pc}，不 flush、不设深度 ────── */

/* @0x1b3afc add sp, sp, #12 */
/* @0x1b3b00 pop {r4, r5, r6, r7, pc} */

/* ── 字面量池（1b3b04..1b3b0c，3 字；前两字被 objdump 译成指令）──
 *   1b3b04 = 0x00239fe8 → 槽 0x3ed930（&Run_Room）
 *   1b3b08 = 0x0023ceb8 → 槽 0x3f0838（0x5425ec 强制深度开关）
 *   1b3b0c = 0x0023cea8 → 槽 0x3f083c（0x5425e8 强制深度值）
 */

/* @0x1b3b04 eoreq r9, r3, r8, ror #31 */
/* @0x1b3b08 .word 0x0023ceb8 */
/* @0x1b3b0c eoreq r12, r3, r8, lsr #29 */
