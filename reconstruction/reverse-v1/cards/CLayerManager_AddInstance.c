/* cally 逆向卡：CLayerManager::AddInstance（原版 libyoyo.so，armv7）
 * @func 0x1c5d18 0x1c5dbc  size 164  41 条（40 条指令 + 1c5db8 一个字面量池字）
 * 级别: 骨架（41/41 锚定，全函数逐条解码：四道门、三级归层、两条尾调路径、float→int 的截断方式、
 *             每一级用哪张表/哪个 bool 都钉住了。未钉：0x5428e8 字节的正式名（借 DrawTheRoom 卡的 Zeus）、
 *             instance+0x170 的全部写入方（本卡只证它与 GetLayerFromID 的消费关系）、
 *             GetLayerWithDepth 的 +0x19 筛子在 GML 侧叫什么）
 * 符号: _ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance
 *       → CLayerManager::AddInstance(CRoom*, CInstance*)
 * 同层: AddInstanceToLayer 0x1c5a38（唯一落点，尾调）、GetLayerFromID 0x1b8868、
 *       GetLayerWithDepth 0x1b87f4、AddDynamicLayer 0x1c33e4、InsertLayerIntoActiveList 0x1c30f8
 *       调用者（全仓 10 处）：CRoom::AddInstance 三个重载（0x1ab270 / 0x1ab420 / 0x1ab730）、
 *       CRoom::DeSerialise 两处（0x1acf2c / 0x1ad024）、BuildRoomLayerRuntimeData 0x1c5e70、
 *       ChangeInstanceDepth 0x1c5fc4、Check_LoadGameState 0x1d1358、StartRoom 两处（0x1d3c38 / 0x1d3e94）
 *       GOT 基址不常驻：只有一次「字面量 + ldr pc 相对」（1c5d20/1c5d28）取 0x5428e8 的槽。
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把实例挂进房间的层：四道门（Zeus 字节 / room 空 / instance 空 / 已在层）之后，
 *   按「实例记录的层 id → 该深度上已存在的动态层 → 现造一个动态层」三级归层，
 *   三条路都尾调 AddInstanceToLayer(room, layer, instance)。
 *
 * ── 四道门（顺序即语义）─────────────────────────────────────────
 *   1) 0x5428e8 字节 **等于 0 → 直接返回**（1c5d2c..1c5d34 是 ldrb/cmp #0/popeq）。
 *      ⚠ 修正（batchAW，cards/LayerHelpers.c）：前期本卡写成「非 0 返回」是反的。
 *      真值：字节为 0 时实例**不进层**（层链/三张表保持空，也不写 +0x170/+0x174）；
 *      字节非 0 才继续归层。这个字节与 DrawTheRoom 那道「Zeus（调试器）在线」同址（槽 0x3ed92c → 0x5428e8）。
 *   2) room == 0 → 返回（1c5d38）。
 *   3) instance == 0 → 返回（1c5d40）。注意第 2/3 关用的是 r0/r1 的原值，不是 r5/r4 的副本。
 *   4) instance+0x174 != 0 → 返回（1c5d48..1c5d50）。本卡与 AddInstanceToLayer 都用这一个字节当
 *      「已经在某个层的元素链上」的幂等门 ⇒ AddInstance 是幂等的，重复调用不会产生第二个元素。
 *
 * ── 第一级：按实例记录的层 id（1c5d54..1c5d68）──────────────────
 *   r1 = instance+0x170（CInstance ctor 卡：layer，初值 -1，语义「-1 = 按 depth 归层」）。
 *   1c5d58 的 cmn r1,#1 就是「r1 == -1 ?」→ 是则跳过本级。
 *   GetLayerFromID(room, id) 查表 1（room+0xe4 簇：键 = 层 id）：
 *      命中 → 返回 CLayer*；未命中 → 返回 0（1b8868 的三条出口都写 r0 = 0）。
 *   ⚠ 表 1 的桶里存的是「键 + 值 + 31 位哈希」，比较只用哈希（1b88a0 的 cmp r8,r2 比的是哈希），
 *     GetLayerFromID 的值取自桶 +0x04（1b8924/1b8928）。
 *
 * ── 第二级：该深度上的动态层（1c5d7c..1c5d98）───────────────────
 *   d = (int)instance+0x180（1c5d7c vldr 的是 +0x180 的 float，1c5d80 vcvt.s32.f32 **向零截断**）。
 *   GetLayerWithDepth(room, d, true)：
 *       沿 room+0xd4 链正向走（+0x68 = next）；层 depth == d 时**还要**看 layer+0x19 != 0 才返回它，
 *       为 0 则继续往后找；层 depth > d 立刻返回 0（1b881c / 1b8828 / 1b8830）。
 *   ⇒ 第三实参 = true 时这个函数只认「+0x19 != 0」的层。全仓只有 AddDynamicLayer 会把 +0x19 置 1
 *     （1c3558 strb lr,[r4,#0x19]，lr = 1），而 DeSerializeLayer 是从房间流里读进这个字节的（1c77b0）。
 *     实际效果：**运行期没有层号（+0x170 == -1）的实例只会落进动态层，不会塞进房间文件里的静态层。**
 *     这是行为层结论；+0x19 在 GML 侧叫什么仍未证。
 *
 * ── 第三级：现造动态层（1c5d9c..1c5db4）─────────────────────────
 *   AddDynamicLayer(room, d)：112 B 的 CLayer（Alloc 站点 = Room_Layers.h，行 63）
 *     +0x00 = max(两个全局计数器)+1（1c355c..1c356c）  +0x04 = d  +0x18 = 1  +0x19 = 1
 *     +0x20/+0x24/+0x28 = -1（= 无前/后脚本、无 shader），元素链/计数清零，CTimingSource::Reset
 *   造完就调 InsertLayerIntoActiveList(room, layer)：按 +0x04 升序插进 room+0xd4 链并把 id 插进表 1
 *   ⇒ 三级归层的最后一级同时也是「层链有序」的维护者。
 *
 * ── 汇合：尾调 AddInstanceToLayer ───────────────────────────────
 *   1c5d6c..1c5d78：r0 = room（r5）、r1 = 那一层的指针（1c5d54 的返回值 / GetLayerFromID / AddDynamicLayer
 *   的返回）、r2 = instance（r4）；先 pop {r3,r4,r5,lr} 再 b AddInstanceToLayer —— 尾调，本函数不再碰栈。
 *   ⚠ 三条路里只有第三级会把 r0 直接当层指针（1c5db0 mov r1,r0）；第一/二级的层指针在 r0，
 *     由 1c5d64 的 subs/1c5d98 的 subs 之后的 r1 = r0 承接（1c5d6c 只重写 r0 = room）。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 帧 + 取 Zeus 字节 ───────────────────────────────────────
 *   push {r3,r4,r5,lr}（r3 只是占位凑 16 B 对齐）。r4 = instance、r5 = room。
 *   1c5d20 的字面量在 1c5db8（0x00227bfc），1c5d28 用它算出槽 0x3ed92c → 0x5428e8。
 */

/* @0x1c5d18 push {r3, r4, r5, lr} */
/* @0x1c5d1c mov r4, r1 */
/* @0x1c5d20 ldr r3, [pc, #0x90] */
/* @0x1c5d24 mov r5, r0 */
/* @0x1c5d28 ldr r3, [pc, r3] */
/* @0x1c5d2c ldrb r3, [r3] */
/* @0x1c5d30 cmp r3, #0 */
/* @0x1c5d34 popeq {r3, r4, r5, pc} */

/* ── 第 2/3 关：room、instance 非空 ────────────────────────── */

/* @0x1c5d38 cmp r0, #0 */
/* @0x1c5d3c popeq {r3, r4, r5, pc} */
/* @0x1c5d40 cmp r1, #0 */
/* @0x1c5d44 popeq {r3, r4, r5, pc} */

/* ── 第 4 关：已在层上就直接返回（幂等）──────────────────── */

/* @0x1c5d48 ldrb r3, [r1, #0x174] */
/* @0x1c5d4c cmp r3, #0 */
/* @0x1c5d50 popne {r3, r4, r5, pc} */

/* ── 第一级：instance+0x170 的层 id → GetLayerFromID ───────── */

/* @0x1c5d54 ldr r1, [r1, #0x170] */
/* @0x1c5d58 cmn r1, #1 */
/* @0x1c5d5c beq 0x1c5d7c <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance+0x64> */
/* @0x1c5d60 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c5d64 subs r1, r0, #0 */
/* @0x1c5d68 beq 0x1c5d7c <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance+0x64> */

/* ── 汇合点（三条路都到这里）：r0 = room、r1 = layer、r2 = instance ──
 *   pop 掉本函数的帧后 b AddInstanceToLayer ⇒ 尾部调用。
 */

/* @0x1c5d6c mov r0, r5 */
/* @0x1c5d70 mov r2, r4 */
/* @0x1c5d74 pop {r3, r4, r5, lr} */
/* @0x1c5d78 b 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance> */

/* ── 第二级：按 +0x180 的 depth（截断成 int）找动态层 ────────
 *   1c5d88 的 r2 = 1 直接落进 GetLayerWithDepth 的第三形参（bool）。
 */

/* @0x1c5d7c vldr s15, [r4, #384] */
/* @0x1c5d80 vcvt.s32.f32 s15, s15 */
/* @0x1c5d84 mov r0, r5 */
/* @0x1c5d88 mov r2, #1 */
/* @0x1c5d8c vmov r1, s15 */
/* @0x1c5d90 bl 0x1b87f4 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib> */
/* @0x1c5d94 subs r1, r0, #0 */
/* @0x1c5d98 bne 0x1c5d6c <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance+0x54> */

/* ── 第三级：AddDynamicLayer(room, d) 造层再用它 ────────────── */

/* @0x1c5d9c vldr s15, [r4, #384] */
/* @0x1c5da0 vcvt.s32.f32 s15, s15 */
/* @0x1c5da4 mov r0, r5 */
/* @0x1c5da8 vmov r1, s15 */
/* @0x1c5dac bl 0x1c33e4 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi> */
/* @0x1c5db0 mov r1, r0 */
/* @0x1c5db4 b 0x1c5d6c <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance+0x54> */

/* ── 字面量池（1 字）────────────────────────────────────────
 *   1c5db8 = 0x00227bfc → 槽 0x3ed92c（0x5428e8 Zeus 字节）
 */

/* @0x1c5db8 .word 0x00227bfc */
