/* cally 逆向卡：碰撞盒更新 + 层滚动/动画推进（原版 libyoyo.so，armv7）—— 一卡两节
 * @func 两节按地址升序，逐节自带 @func 头与逐条锚点：
 *   §1 0x1abfa0 CRoom::UpdateLayers      size 608    152 行（147 指令 + 1 nop 填充 + 4 池字）
 *   §2 0x1cdc1c CollisionUpdate          size 340     85 行（83 指令 + 2 池字）
 * 总账: 237 锚点 = 230 条指令 + 1 条 nop 填充 + 6 个字面量池字（1ac1f0 / 1ac1f4 是 double 1e6 的两半，
 *       1ac1f8 / 1ac1fc / 1cdd68 / 1cdd6c 是 GOT 偏移字），与 asm/index-CollisionUpdate_Room_all.tsv 逐字一致
 *       （scripts/check_card_anchors.py → index=237 card=237 missing=0 extra=0 mismatch=0 RESULT EXACT）。
 *       注：这 6 个池字在 objdump 里的写法分别是 andeq(1ac1f0, 0x00000000) / smlawbmi(1ac1f4) /
 *       eoreq(1ac1f8, 1ac1fc, 1cdd68) / .word(1cdd6c) —— 按 README 规矩 3 保留原样，
 *       并在锚点旁的注释里逐条标「非指令」。
 * 级别: 正文（两节都逐条解码到闸门 / 字段 / 算术 / 跳转；每节末尾单列本节 open。tier = bytecode_anchored）
 * 锚点来源: 全部由 asm_index.py 从二进制生成，本卡未手写转录。
 *
 * ── 全局坐标（本轮按 .rel.dyn（R_ARM_RELATIVE=23）槽内 addend 直读 + .symtab 实测）──
 *   GOT 槽      目标        符号（.symtab 原名）                     本卡用处
 *   0x3ed92c → 0x5428e8   g_isZeus（1 B）                          §1 总闸
 *   0x3ed934 → 0x5428c0   g_GameTimer（CTimingSource）             §1 GetFPS 的 this
 *   0x3f0688 → 0x542379   option_use_fast_collision（1 B）          §2 第 1 道闸
 *   0x3ee24c → 0x5429a8   g_tree（RTree<CInstance*,int,float,6,2>*）§2 懒建/摘/插
 *   ⇒ 其中三条（g_isZeus / option_use_fast_collision / g_tree）与 LayerHelpers 卡头部独立吻合；
 *     g_GameTimer（0x3ed934）是本卡新增的一条（UpdateActive 卡只用到相邻的 0x3ed930 = Run_Room）。
 *   §1 池里的 double：1ac1f0..1ac1f7 = 0x412e848000000000 = 1000000.0（`vldr d10,[pc,#540]` 1abfcc 取）。
 *
 * ── 两节的关系 ──────────────────────────────────────────────────────────
 *   同属「每帧一次」的状态推进，但作用域不同：§1 只动层的滚动偏移与元素的动画帧（房间层系统，g_isZeus 总闸）；
 *   §2 只动全局 RTree 里某个实例的包围盒（碰撞系统，option_use_fast_collision 总闸）。两者没有调用边，
 *   也不共享字段：§1 读 CLayer(+0x08/+0x0c/+0x10/+0x14/+0x58) 与元素，§2 读 CInstance(+0x68/+0x69/+0x80/
 *   +0xe8..+0xf4)。唯一同名常量是 1e6 —— 但 §1 的 1e6 是「每秒微秒数」，§2 里没有这个常量（§2 用 1024 建树）。
 *
 * ── 跨节结论（本题重点：RTree 新旧盒替换）───────────────────────────────
 *   A. CollisionUpdate 的「换盒」是两次独立操作，**旧盒来自入参、新盒来自实例字段**：
 *      Remove 用 `RTree::Remove(&min2, &max2, &inst, true)`，两个键数组由**入参 rect** 归一化得到（min/min、max/max）；
 *      Insert 用 `RTree::InsertRect(&branch, &g_tree->[0x10], 0)`，branch 的盒由 inst+0xe8/+0xec/+0xf0/+0xf4
 *      （当前 bbox）归一化得到，branch+0x14 = inst。
 *      ⇒ 唯一调用点 Compute_BoundingBox(updateRTree=true) 0x19265c 在**重算前**把四条 bbox 存到 [sp] 再传进来
 *        （该卡 0x192380 stm + 0x192654 mov r0,r4 已钉），所以入参确实是「已被 RTree 记着的旧盒」。
 *   B. 四道闸在 Update 侧，不在 Compute 侧：option_use_fast_collision == 0、inst+0x68 != 0（已销毁）、
 *      inst+0x69 != 0（已停用）、(*(int*)inst->[0x80] & 0x10) == 0 —— 任一成立就整段跳过。
 *      ⇒ 「盒子重算了但树没换」是正常状态（四道闸里的任何一条都能造成）。
 *   C. g_tree 懒建点在四道闸**之后**（1cdc80 → 1cdd48），所以「option 开、树还没建」不会在本函数崩；
 *      会崩的是 ShouldUseFastCollision 0x1c8e84 那条无保护解引用（Builtins_Instance 卡 open 2 已记）。
 *   D. UpdateLayers 的推进是「层先、元素后」：每层先把 +0x10/+0x14 加进 +0x08/+0x0c（滚动），再逐个元素推帧；
 *      FPS 在**外层循环体内**取（每层一次 GetFPS），所以同一帧内多层的除数可能不同。
 *   E. 停用实例的元素在 §1 里是「终结整层遍历」而不是「跳过该元素」（1ac15c 直接取下一层），
 *      与 DrawRoomLayers 的习惯一致（LayerHelpers 卡跨节结论 D）。
 *
 * ── 汇总 open ───────────────────────────────────────────────────────────
 *   · RTree 模板参数 <CInstance*, int, float, 6, 2> 的后两个（6 / 2）只从符号名读到，语义（最大条目/维数）未证。
 *   · RTree::Remove 第 4 实参 true 的效果：摘完再用 tree+0x10 经 0x1cbc60（未命名，落在
 *     FINALIZE_Run_Global+0x1f4）生成的矩形再 RemoveRect 一次。tree+0x10 在 InsertRect 侧是 Node** 根指针，
 *     在 Remove 侧却被当数据（`ldr r1,[tree,#0x10]`），两处解释不一致 —— 未钉。
 *   · option_use_fast_collision（0x542379）的写点仍未知（Compute_BoundingBox 卡与 Builtins_Instance 卡同结论）。
 *   · layer+0x10/+0x14（速度）与 elem/bg 的 +0x24（速度）谁写：本卡只证加法与除法，未向上追写方。
 */

/* ══ §1 CRoom::UpdateLayers 0x1abfa0 ══════════════════════════════════════
 * @func 0x1abfa0 0x1ac200 size 608  152 行（147 指令 + 1 条 nop 填充 1ac1ec + 4 池字 1ac1f0..1ac1fc）
 * 级别: 正文（147/147。两道门、每层取 FPS、四条累加、四类元素分派与回绕算术全部钉住；
 *       未钉：三处字段的正式名（bg+0x28 / back+0x30 / back+0x38）、速度写方、g_isZeus == 0 时的替代路径）
 * 符号: _ZN5CRoom12UpdateLayersEv → void CRoom::UpdateLayers()
 * 调用者（全 .text 1 处）：DoAStep 0x1d32c0 的 0x1d33e0（每步一次，紧跟在实例链处理之后）
 * 同层: g_GameTimer 0x5428c0 + CTimingSource::GetFPS 0x214808、_GetSpriteFrames 0x1abf6c、
 *       Background_Data 0xc3794、fmodf@plt 0xb6790、__floatdidf 0x319164、
 *       CRoom::UpdateActive 0x1abd9c（同卡族，room+0xd4 之前的那条链）、DrawRoomLayers（同一停用习惯）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   每帧推进一次房间的「层时间」：先给每层的滚动偏移 += 速度（+0x08 += +0x10、+0x0c += +0x14），
 *   再沿层元素链按 type 推进各自的动画位置并按帧数回绕。全部工作都在 g_isZeus != 0 且层链非空时才发生。
 *
 * ── ① 两道门（1abfa8..1abfc4）───────────────────────────────────────────
 *   `ldrb r3,[g_isZeus]`（槽 0x3ed92c → 0x5428e8）== 0 → 直接 vpop/pop 返回；
 *   `ldr r5,[room+0xd4]`（层链头）== 0 → 返回。
 *   ⇒ 层系统的总闸是 g_isZeus；room+0xd4/+0xd8/+0xdc 是层链头/尾/层数（本函数只用头与 +0x68 的 next）。
 *
 * ── ② 每层先取一次 FPS（1abfc8..1abfd8 + 1ac004）──────────────────────────
 *   r6 = *(槽 0x3ed934) = g_GameTimer（CTimingSource 全局对象）；r0 = g_GameTimer → GetFPS() 0x214808，
 *   返回 double（r0/r1）→ `vmov d8,r0,r1` 存进 d8。
 *   ⚠ 取指在**外层循环体内**（回边 1ac0cc → 1abfd4），每层各取一次；同帧内多层可能拿到不同 FPS。
 *   d10 = 1e6（池字 1ac1f0..1ac1f7）在循环外取一次，只被 §1 的 type 5 用到。
 *
 * ── ③ 层滚动累加（1abfdc..1ac000）────────────────────────────────────────
 *   s14 = [layer+0x08] + [layer+0x10] → 写回 +0x08；
 *   s15 = [layer+0x0c] + [layer+0x14] → 写回 +0x0c。
 *   ⇒ +0x08/+0x0c = 当前滚动偏移（x/y），+0x10/+0x14 = 每帧增量。**不除 FPS、不取模、不夹取**。
 *   然后 r4 = [layer+0x58]（元素链头）；为 0 → 直接下一层（1ac00c → 1ac0c4）。
 *
 * ── ④ 元素分派（1ac034..1ac03c + 1ac010..1ac02c）──────────────────────────
 *   r3 = elem+0x00（type）：== 1 → ⑤；否则**依次**比 4（→⑥）、5（→⑧）、2（→⑦）—— 源码顺序是 4/5/2，
 *   不是按 type 升序；其余（0/3/6/7）→ 什么都不做，直接 1ac028 取下一个元素（elem+0x14）。
 *
 * ── ⑤ type 1（背景元素，1ac040..1ac0bc）──────────────────────────────────
 *   bg = elem+0x1c（指向背景数据块的指针）== 0 → 下一个元素；
 *   `[bg+0x28] == 1` → **免 FPS 档**：bg+0x20 += bg+0x24（1ac1c4 三连）；
 *   否则 FPS != 0 时 bg+0x20 += bg+0x24 / FPS（1ac064..1ac078 的 vdiv），FPS == 0 则跳过推进（1ac058 的 beq）；
 *   之后帧数 frames = _GetSpriteFrames([bg+0x04])（0x1abf6c，返回 int），把 bg+0x20 归一到 [0, frames)：
 *     若 >= frames → 减 frames（1ac09c..1ac0a4 的 vsubge，且直接跳下一个元素）；
 *     若 <  0     → 加 frames（1ac0a8..1ac0b8 的 vaddmi）。
 *   ⇒ 三个字段：+0x20 位置(float)、+0x24 速度(float)、+0x28 模式(int，1 = 不按 FPS 缩放)。
 *
 * ── ⑥ type 4（精灵元素，1ac0d8..1ac140）──────────────────────────────────
 *   与 ⑤ 逐条同构，只是字段落在**元素自身**：elem+0x28 == 1 → elem+0x20 += elem+0x24（1ac1d8 三连）；
 *   否则 elem+0x20 += elem+0x24/FPS（1ac0e4..1ac104）；frames = _GetSpriteFrames(elem+0x1c)；
 *   再用同样两条 vsubge/vaddmi 把 elem+0x20 归一到 [0, frames)。
 *   ⇒ type 4 的 +0x1c 是**精灵索引**（不是指针），喂给 _GetSpriteFrames。
 *
 * ── ⑧ type 5（背景动画元素，1ac16c..1ac1c0）──────────────────────────────
 *   back = Background_Data(elem+0x1c)（0xc3794，按背景 id 取数据块）== 0 → 下一个元素；
 *   pos = elem+0x30(float)；增量 = 1e6 / (double)*(int64*)(back+0x38) / FPS：
 *     1ac17c `ldrd r0,r1,[r7,#56]` 取 back+0x38 的 8 字节 → __floatdidf 转 double（d6）
 *     1ac194 `vdiv d7,d10,d6`（1e6 / frames）→ 1ac19c `vdiv d7,d7,d8`（/ FPS）
 *   elem+0x30 = (float)(pos + 增量)（1ac1a0..1ac1b0），再用 fmodf(新值, (float)*(int*)(back+0x30)) 回绕
 *   （1ac1a4 把 back+0x30 的 int 转 float 当模数，1ac1b8 bl fmodf，1ac1bc 把 float 结果按 int 写回 +0x30）。
 *   ⇒ 与 ⑤⑥ 的「加减 frames」不同：type 5 用 fmodf，模数是**数据块里的整数字段**。
 *
 * ── ⑦ type 2（实例元素，1ac144..1ac158）─────────────────────────────────
 *   inst = elem+0x20 == 0 → 下一个元素；`ldrb [inst+0x69]` != 0（已停用）→ **取下一层**（1ac15c 直接
 *   `ldr r5,[r5,#0x68]` 再回外层循环），本层剩余元素一个都不再处理。
 *   ⇒ 停用实例的元素是「整层遍历的终止符」，与 DrawRoomLayers 的跳出习惯一致。
 *
 * ── ⑨ 收尾（1ac028 / 1ac0c4 / 1ac0d0）───────────────────────────────────
 *   下一个元素：elem = elem+0x14；为 0 → 下一层。下一层：layer = layer+0x68；非 0 → 回 1abfd4（重取 FPS）。
 *   出口：`vpop {d8,d9,d10}` + `pop {r3,r4,r5,r6,r7,pc}`（d9/d10 只在 type 5 用，仍按 AAPCS 保存）。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · 1ac1ec 是 nop（0xe320f000），1ac1f0..1ac1f7 是 double 1e6，1ac1f8/1ac1fc 是两个 GOT 偏移字 ——
 *     四条都在函数返回之后、控制流不可达处（1ac1e8 的 b 之后）。
 *   · bg+0x28 / elem+0x28 的「1 = 免 FPS」档：只从 `cmp #1 / beq 免 FPS` 反推，没有第二处写方对照。
 *   · back+0x38 的 int64 与 back+0x30 的 int 是从算术反推的「帧数 / 模数」，字段名未证。
 *   · g_isZeus == 0 时谁负责滚动与动画（层系统整体关闭时的替代路径）未找。
 *   · 层 +0x10/+0x14（每帧增量）的写方未追（本卡只证累加与不除 FPS）。
 */


/* ── ① 两道门：g_isZeus == 0 或 room+0xd4 层链头 == 0 → 返回 ── */
/* @0x1abfa0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1abfa4 vpush {d8, d9, d10} */
/* @0x1abfa8 ldr r3, [pc, #0x248] */
/* @0x1abfac ldr r3, [pc, r3] */
/* @0x1abfb0 ldrb r3, [r3] */
/* @0x1abfb4 cmp r3, #0 */
/* @0x1abfb8 beq 0x1ac0d0 <_ZN5CRoom12UpdateLayersEv+0x130> */
/* @0x1abfbc ldr r5, [r0, #0xd4] */
/* @0x1abfc0 cmp r5, #0 */
/* @0x1abfc4 beq 0x1ac0d0 <_ZN5CRoom12UpdateLayersEv+0x130> */
/* ── ② g_GameTimer（槽 0x3ed934）+ CTimingSource::GetFPS：取指在外层循环体内，每层一次 ── */
/* @0x1abfc8 ldr r6, [pc, #0x22c] */
/* @0x1abfcc vldr d10, [pc, #540] */
/* @0x1abfd0 ldr r6, [pc, r6] */
/* @0x1abfd4 mov r0, r6 */
/* @0x1abfd8 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* ── ③ 层滚动累加：+0x08 += +0x10，+0x0c += +0x14（同时取元素链头 +0x58）── */
/* @0x1abfdc vldr s14, [r5, #8] */
/* @0x1abfe0 vldr s15, [r5, #16] */
/* @0x1abfe4 vldr s13, [r5, #12] */
/* @0x1abfe8 vadd.f32 s14, s14, s15 */
/* @0x1abfec vldr s15, [r5, #20] */
/* @0x1abff0 ldr r4, [r5, #0x58] */
/* @0x1abff4 cmp r4, #0 */
/* @0x1abff8 vadd.f32 s15, s13, s15 */
/* @0x1abffc vstr s14, [r5, #8] */
/* @0x1ac000 vstr s15, [r5, #12] */
/* @0x1ac004 vmov d8, r0, r1 */
/* @0x1ac008 bne 0x1ac034 <_ZN5CRoom12UpdateLayersEv+0x94> */
/* @0x1ac00c b 0x1ac0c4 <_ZN5CRoom12UpdateLayersEv+0x124> */
/* ── ④ 分派续：type 4 → ⑥、type 2 → ⑦、type 5 → ⑧，其余什么都不做 ── */
/* @0x1ac010 cmp r3, #4 */
/* @0x1ac014 beq 0x1ac0d8 <_ZN5CRoom12UpdateLayersEv+0x138> */
/* @0x1ac018 cmp r3, #5 */
/* @0x1ac01c beq 0x1ac16c <_ZN5CRoom12UpdateLayersEv+0x1cc> */
/* @0x1ac020 cmp r3, #2 */
/* @0x1ac024 beq 0x1ac144 <_ZN5CRoom12UpdateLayersEv+0x1a4> */
/* @0x1ac028 ldr r4, [r4, #0x14] */
/* @0x1ac02c cmp r4, #0 */
/* @0x1ac030 beq 0x1ac0c4 <_ZN5CRoom12UpdateLayersEv+0x124> */
/* ── ④ 元素分派入口：type == 1 先判 ── */
/* @0x1ac034 ldr r3, [r4] */
/* @0x1ac038 cmp r3, #1 */
/* @0x1ac03c bne 0x1ac010 <_ZN5CRoom12UpdateLayersEv+0x70> */
/* ── ⑤ type 1 背景元素：bg+0x20 推进 + 按 _GetSpriteFrames(bg+0x04) 回绕 ── */
/* @0x1ac040 ldr r3, [r4, #0x1c] */
/* @0x1ac044 cmp r3, #0 */
/* @0x1ac048 beq 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac04c ldr r2, [r3, #0x28] */
/* @0x1ac050 cmp r2, #1 */
/* @0x1ac054 beq 0x1ac1c4 <_ZN5CRoom12UpdateLayersEv+0x224> */
/* @0x1ac058 vcmp.f64 d8, #0 */
/* @0x1ac05c vmrs APSR_nzcv, fpscr */
/* @0x1ac060 beq 0x1ac07c <_ZN5CRoom12UpdateLayersEv+0xdc> */
/* @0x1ac064 vcvt.f32.f64 s15, d8 */
/* @0x1ac068 vldr s13, [r3, #36] */
/* @0x1ac06c vldr s14, [r3, #32] */
/* @0x1ac070 vdiv.f32 s15, s13, s15 */
/* @0x1ac074 vadd.f32 s15, s14, s15 */
/* @0x1ac078 vstr s15, [r3, #32] */
/* @0x1ac07c ldr r0, [r3, #0x4] */
/* @0x1ac080 bl 0x1abf6c <_Z16_GetSpriteFramesi> */
/* @0x1ac084 ldr r3, [r4, #0x1c] */
/* @0x1ac088 vldr s15, [r3, #32] */
/* @0x1ac08c vmov s12, r0 */
/* @0x1ac090 vcvt.f32.s32 s14, s12 */
/* @0x1ac094 vcmpe.f32 s15, s14 */
/* @0x1ac098 vmrs APSR_nzcv, fpscr */
/* @0x1ac09c vsubge.f32 s15, s15, s14 */
/* @0x1ac0a0 vstrge s15, [r3, #32] */
/* @0x1ac0a4 bge 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac0a8 vcmpe.f32 s15, #0 */
/* @0x1ac0ac ldr r4, [r4, #0x14] */
/* @0x1ac0b0 vmrs APSR_nzcv, fpscr */
/* @0x1ac0b4 vaddmi.f32 s15, s15, s14 */
/* @0x1ac0b8 vstrmi s15, [r3, #32] */
/* @0x1ac0bc cmp r4, #0 */
/* @0x1ac0c0 bne 0x1ac034 <_ZN5CRoom12UpdateLayersEv+0x94> */
/* @0x1ac0c4 ldr r5, [r5, #0x68] */
/* @0x1ac0c8 cmp r5, #0 */
/* @0x1ac0cc bne 0x1abfd4 <_ZN5CRoom12UpdateLayersEv+0x34> */
/* @0x1ac0d0 vpop {d8, d9, d10} */
/* @0x1ac0d4 pop {r3, r4, r5, r6, r7, pc} */
/* ── ⑥ type 4 精灵元素：同一套算术，字段落在元素自身（+0x1c 精灵索引 / +0x20 位置 / +0x24 速度 / +0x28 档）── */
/* @0x1ac0d8 ldr r3, [r4, #0x28] */
/* @0x1ac0dc cmp r3, #1 */
/* @0x1ac0e0 beq 0x1ac1d8 <_ZN5CRoom12UpdateLayersEv+0x238> */
/* @0x1ac0e4 vcmp.f64 d8, #0 */
/* @0x1ac0e8 vmrs APSR_nzcv, fpscr */
/* @0x1ac0ec beq 0x1ac108 <_ZN5CRoom12UpdateLayersEv+0x168> */
/* @0x1ac0f0 vcvt.f32.f64 s15, d8 */
/* @0x1ac0f4 vldr s13, [r4, #36] */
/* @0x1ac0f8 vldr s14, [r4, #32] */
/* @0x1ac0fc vdiv.f32 s15, s13, s15 */
/* @0x1ac100 vadd.f32 s15, s14, s15 */
/* @0x1ac104 vstr s15, [r4, #32] */
/* @0x1ac108 ldr r0, [r4, #0x1c] */
/* @0x1ac10c bl 0x1abf6c <_Z16_GetSpriteFramesi> */
/* @0x1ac110 vldr s15, [r4, #32] */
/* @0x1ac114 vmov s13, r0 */
/* @0x1ac118 vcvt.f32.s32 s14, s13 */
/* @0x1ac11c vcmpe.f32 s15, s14 */
/* @0x1ac120 vmrs APSR_nzcv, fpscr */
/* @0x1ac124 vsubge.f32 s15, s15, s14 */
/* @0x1ac128 vstrge s15, [r4, #32] */
/* @0x1ac12c bge 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac130 vcmpe.f32 s15, #0 */
/* @0x1ac134 vmrs APSR_nzcv, fpscr */
/* @0x1ac138 vaddmi.f32 s15, s15, s14 */
/* @0x1ac13c vstrmi s15, [r4, #32] */
/* @0x1ac140 b 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* ── ⑦ type 2 实例元素：elem+0x20 实例的 +0x69 非 0 → 直接取下一层（终止整层遍历）── */
/* @0x1ac144 ldr r3, [r4, #0x20] */
/* @0x1ac148 cmp r3, #0 */
/* @0x1ac14c beq 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac150 ldrb r3, [r3, #0x69] */
/* @0x1ac154 cmp r3, #0 */
/* @0x1ac158 beq 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac15c ldr r5, [r5, #0x68] */
/* @0x1ac160 cmp r5, #0 */
/* @0x1ac164 bne 0x1abfd4 <_ZN5CRoom12UpdateLayersEv+0x34> */
/* @0x1ac168 b 0x1ac0d0 <_ZN5CRoom12UpdateLayersEv+0x130> */
/* ── ⑧ type 5 背景动画元素：Background_Data(elem+0x1c) + 1e6/frames/FPS + fmodf 回绕 ── */
/* @0x1ac16c ldr r0, [r4, #0x1c] */
/* @0x1ac170 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1ac174 subs r7, r0, #0 */
/* @0x1ac178 beq 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* @0x1ac17c ldrd r0, r1, [r7, #56] */
/* @0x1ac180 vldr s18, [r4, #48] */
/* @0x1ac184 bl 0x319164 <__floatdidf> */
/* @0x1ac188 vcvt.f64.f32 d9, s18 */
/* @0x1ac18c ldr r3, [r7, #0x30] */
/* @0x1ac190 vmov d6, r0, r1 */
/* @0x1ac194 vdiv.f64 d7, d10, d6 */
/* @0x1ac198 vmov s13, r3 */
/* @0x1ac19c vdiv.f64 d7, d7, d8 */
/* @0x1ac1a0 vadd.f64 d9, d9, d7 */
/* @0x1ac1a4 vcvt.f32.s32 s13, s13 */
/* @0x1ac1a8 vcvt.f32.f64 s18, d9 */
/* @0x1ac1ac vmov r1, s13 */
/* @0x1ac1b0 vstr s18, [r4, #48] */
/* @0x1ac1b4 vmov r0, s18 */
/* @0x1ac1b8 bl 0xb6790 <fmodf@plt> */
/* @0x1ac1bc str r0, [r4, #0x30] */
/* @0x1ac1c0 b 0x1ac028 <_ZN5CRoom12UpdateLayersEv+0x88> */
/* ⑤ 的免 FPS 档（bg+0x28 == 1）：bg+0x20 += bg+0x24 后直接进回绕 ── */
/* @0x1ac1c4 vldr s14, [r3, #32] */
/* @0x1ac1c8 vldr s15, [r3, #36] */
/* @0x1ac1cc vadd.f32 s15, s14, s15 */
/* @0x1ac1d0 vstr s15, [r3, #32] */
/* @0x1ac1d4 b 0x1ac07c <_ZN5CRoom12UpdateLayersEv+0xdc> */
/* ⑥ 的免 FPS 档（elem+0x28 == 1）：elem+0x20 += elem+0x24 ── */
/* @0x1ac1d8 vldr s14, [r4, #32] */
/* @0x1ac1dc vldr s15, [r4, #36] */
/* @0x1ac1e0 vadd.f32 s15, s14, s15 */
/* @0x1ac1e4 vstr s15, [r4, #32] */
/* @0x1ac1e8 b 0x1ac108 <_ZN5CRoom12UpdateLayersEv+0x168> */
/* nop 填充（0xe320f000）：函数体在 1ac1e8 的 b 之后结束，以下四条不可达 ── */
/* @0x1ac1ec nop */
/* 非指令：double 1e6 的低半字 0x00000000（1ac1f0..1ac1f7 = 0x412e848000000000）*/
/* @0x1ac1f0 andeq r0, r0, r0 */
/* 非指令：double 1e6 的高半字（objdump 译成 smlawbmi）*/
/* @0x1ac1f4 smlawbmi lr, r0, r4, r8 */
/* 池字（非指令）：0x00241978 → GOT 0x3ed92c = g_isZeus */
/* @0x1ac1f8 eoreq r1, r4, r8, ror r9 */
/* 池字（非指令）：0x0024195c → GOT 0x3ed934 = g_GameTimer */
/* @0x1ac1fc eoreq r1, r4, r12, asr r9 */

/* ══ §2 CollisionUpdate 0x1cdc1c ══════════════════════════════════════════
 * @func 0x1cdc1c 0x1cdd70 size 340  85 行（83 指令 + 2 池字 1cdd68/1cdd6c）
 * 级别: 正文（83/83。四道闸、懒建树、旧盒归一化 + Remove、新盒归一化 + InsertRect 全部钉住；
 *       未钉：RTree::Remove 第 4 实参的第二次摘除、tree+0x10 的双重解释、模板参数 6/2 的语义）
 * 符号: _Z15CollisionUpdateP9CInstanceR9tagYYRECT → void CollisionUpdate(CInstance* inst, tagYYRECT& oldBox)
 * 调用者（全 .text 1 处）：CInstance::Compute_BoundingBox(bool) 0x192340 的 0x19265c（updateRTree 为真时）
 * 同层: RTree::Remove 0x1cd978、RTree::RemoveRect 0x1cd87c、RTree::InsertRect 0x1cd700、
 *       RTree::InsertRectRec 0x1cd4bc、RTree::RTree(int) 0x1cc320、operator new 0x27c524、0x1cbc60（未命名）、
 *       ShouldUseFastCollision 0x1c8e84（同一棵树的读侧，无空指针保护）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   把某个实例在全局 RTree 里的盒子换成当前 bbox：先按**入参旧盒**把旧条目摘掉（Remove），
 *   再按**实例当前 bbox**把新条目插回去（InsertRect）。四道闸任一不过就什么都不做。
 *
 * ── ① 四道闸（1cdc1c..1cdc6c）───────────────────────────────────────────
 *   槽 0x3f0688 → 0x542379 = option_use_fast_collision：
 *     `ldrb r3,[…]; cmp r3,#0; beq 1cdc4c`  → 为 0 直接返回；
 *     `ldrb r3,[inst+0x68]; cmp; beq 1cdc54` → +0x68 != 0（已销毁）返回；
 *     `ldrb r3,[inst+0x69]; cmp; bne 1cdc4c` → +0x69 != 0（已停用）返回；
 *     `ldr r3,[inst+0x80]; ldr r3,[r3]; tst r3,#16; beq 1cdc4c` → 对象首字段 bit4 为 0 返回。
 *   ⇒ inst+0x80 = CObjectGM*，其 +0x00 是标志字，bit4(0x10) = 「参与快碰撞」。
 *   ⚠ 1cdc34 先把 inst 存到 [sp+0xc]，后面 Remove 的 value 实参就是 &[sp+0xc]。
 *
 * ── ② g_tree 懒建（1cdc70..1cdc80 + 1cdd48..1cdd64）──────────────────────
 *   槽 0x3ee24c → 0x5429a8 = g_tree；`ldr r0,[g_tree]` == 0 →
 *     operator new(24)（0x27c524）→ RTree::RTree(this, 1024)（0x1cc320）→ `str r6,[g_tree]`
 *     → `mov r0,r6; b 1cdc84`（继续，不返回）。
 *   ⇒ 树对象 24 B，构造实参 1024（容量/阈值）；全图唯一建树点（Builtins_Instance 卡同结论）。
 *
 * ── ③ 摘旧盒（1cdc84..1cdcd8）───────────────────────────────────────────
 *   入参 rect（r4）四条 int：+0x00 left、+0x04 top、+0x08 right、+0x0c bottom（Compute_BoundingBox 卡已钉类型）。
 *   归一化成两个 int[2] 键（每个键是 {x,y} 相邻两字）：
 *     [sp+0x10] = min(left,right)   [sp+0x14] = min(top,bottom)
 *     [sp+0x18] = max(right,left)   [sp+0x1c] = max(bottom,top)   ← strle/strgt 成对实现 min/max
 *   `RTree<CInstance*,int,float,6,2>::Remove(&[sp+0x10], &[sp+0x18], &[sp+0xc], true)` 0x1cd978
 *     r0 = 树、r1 = &min 键、r2 = &max 键、r3 = &inst、`str r3,[sp]`（r3 = 1）= 第 4 实参 bool。
 *   Remove 内部（0x1cd978）先 `RemoveRect(rect{4 字}, value, root)`，再看该 bool：
 *     非 0 → 用 `[tree+0x10]` 经 0x1cbc60 生成另一个矩形，再 RemoveRect 一次（两次摘除）。
 *
 * ── ④ 插新盒（1cdcdc..1cdd3c）───────────────────────────────────────────
 *   新盒来自实例字段：+0xe8 left、+0xec top、+0xf0 right、+0xf4 bottom（四条 `ldr`，不是 vldr）。
 *   同样归一化成 [sp+0x20]/[sp+0x24]/[sp+0x28]/[sp+0x2c] = min(x) / min(y) / max(x) / max(y)；
 *   Branch 结构（r1 = sp+0x20 起）：+0x00..+0x0c = 四个 int 盒、+0x10 = 0（`str r2,[sp+0x30]`，r2 = 0）、
 *   +0x14 = inst（`str r12,[sp+0x34]`）。
 *   `RTree::InsertRect(&branch, &g_tree->[0x10], 0)` 0x1cd700：r0 = 树、r1 = &branch、r2 = tree+0x10（Node** 根）、
 *   r3 = 0（层级）。InsertRect 内 `InsertRectRec(branch, *root, &out, 0)` 0x1cd4bc。
 *   ⇒ **树对象里 +0x10 是根指针槽**（InsertRect 侧取 `ldr r2,[r2]` 当 Node*）。
 *
 * ── ⑤ 为什么「旧盒从入参来」（跨卡证据）─────────────────────────────────
 *   Compute_BoundingBox 0x192340 在重算前把四条 bbox `ldm r6,{r0..r3}` / `stm sp,{r0..r3}`（0x192378/0x192380），
 *   重算后才 0x192654 `mov r0,r4` + 0x19265c `bl 0x1cdc1c`。⇒ 入参 = 重算前的盒 = 树里现存的盒。
 *   本函数 ③ 用它 Remove、④ 用实例新字段 Insert，替换才自洽（若两次都用新盒，旧条目会残留）。
 *   ⚠ 若调用方传进来的盒与树里实际存的不一致（例如两处 bbox 写点绕过 Compute），Remove 会摘空、树里留下死条目
 *     —— 代码里没有任何一致性校验（RemoveRect 返回 0 也不报）。
 *
 * ── ⑥ 退出（1cdd40/1cdd44）────────────────────────────────────────────
 *   `add sp,#60` + `pop {r4,r5,r6,r7,pc}`，void。两条路径（闸门拦下 / 正常结束）共用同一个出口。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · RTree::Remove 第 4 实参为 true 时的第二次摘除：矩形由 0x1cbc60（符号表里没有名字，落在
 *     FINALIZE_Run_Global+0x1f4）用 `[tree+0x10]` 生成。同一字段在 InsertRect 侧是 Node** 根指针槽，
 *     这里却把 `[tree+0x10]` 当实参读出来 —— 两种解释互斥，未钉。
 *   · RTree 模板参数 6 / 2（最大条目数 / 维数？）只有符号名可读。
 *   · 建树实参 1024 的语义（容量 or 阈值）未证；RTree 对象 24 B 的字段划分只证到 +0x10 = 根。
 *   · base 盒的 min/max 归一化只在「left<=right / top<=bottom」时是恒等；调用方若传反序盒，摘除键会与插入键不同
 *     （这反而说明归一化是必要的：两次都用同一套 min/max 规则）。
 *   · option_use_fast_collision 的写点仍未找到（跨卡 open）。
 */


/* ── ① 四道闸：option_use_fast_collision / +0x68 / +0x69 / [0x80]->[0] & 0x10 ── */
/* @0x1cdc1c ldr r3, [pc, #0x144] */
/* @0x1cdc20 push {r4, r5, r6, r7, lr} */
/* @0x1cdc24 ldr r3, [pc, r3] */
/* @0x1cdc28 sub sp, sp, #60 */
/* @0x1cdc2c mov r4, r1 */
/* @0x1cdc30 ldrb r3, [r3] */
/* @0x1cdc34 str r0, [sp, #0xc] */
/* @0x1cdc38 cmp r3, #0 */
/* @0x1cdc3c beq 0x1cdc4c <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x30> */
/* @0x1cdc40 ldrb r3, [r0, #0x68] */
/* @0x1cdc44 cmp r3, #0 */
/* @0x1cdc48 beq 0x1cdc54 <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x38> */
/* @0x1cdc4c add sp, sp, #60 */
/* @0x1cdc50 pop {r4, r5, r6, r7, pc} */
/* @0x1cdc54 ldrb r3, [r0, #0x69] */
/* @0x1cdc58 cmp r3, #0 */
/* @0x1cdc5c bne 0x1cdc4c <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x30> */
/* @0x1cdc60 ldr r3, [r0, #0x80] */
/* @0x1cdc64 ldr r3, [r3] */
/* @0x1cdc68 tst r3, #16 */
/* @0x1cdc6c beq 0x1cdc4c <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x30> */
/* ── ② g_tree（槽 0x3ee24c）为 0 → 1cdd48 建树后回来继续（懒建，不返回）── */
/* @0x1cdc70 ldr r5, [pc, #0xf4] */
/* @0x1cdc74 ldr r5, [pc, r5] */
/* @0x1cdc78 ldr r0, [r5] */
/* @0x1cdc7c cmp r0, #0 */
/* @0x1cdc80 beq 0x1cdd48 <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x12c> */
/* ── ③ 摘旧盒：入参 rect 归一化成 min/max 两个 int[2] 键 → RTree::Remove(&min,&max,&inst,true) ── */
/* @0x1cdc84 ldr r6, [r4] */
/* @0x1cdc88 add r1, sp, #16 */
/* @0x1cdc8c ldr r7, [r4, #0x8] */
/* @0x1cdc90 add r2, sp, #24 */
/* @0x1cdc94 ldr r12, [r4, #0x4] */
/* @0x1cdc98 mov r3, #1 */
/* @0x1cdc9c ldr lr, [r4, #0xc] */
/* @0x1cdca0 str r3, [sp] */
/* @0x1cdca4 add r3, sp, #12 */
/* @0x1cdca8 cmp r7, r6 */
/* @0x1cdcac strle r7, [sp, #0x10] */
/* @0x1cdcb0 strgt r6, [sp, #0x10] */
/* @0x1cdcb4 cmp lr, r12 */
/* @0x1cdcb8 strle lr, [sp, #0x14] */
/* @0x1cdcbc strgt r12, [sp, #0x14] */
/* @0x1cdcc0 cmp lr, r12 */
/* @0x1cdcc4 strge lr, [sp, #0x1c] */
/* @0x1cdcc8 strlt r12, [sp, #0x1c] */
/* @0x1cdccc cmp r7, r6 */
/* @0x1cdcd0 strge r7, [sp, #0x18] */
/* @0x1cdcd4 strlt r6, [sp, #0x18] */
/* @0x1cdcd8 bl 0x1cd978 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6RemoveEPKiS4_RKS1_b> */
/* ── ④ 插新盒：inst+0xe8..+0xf4 归一化成 Branch 盒 → InsertRect(&branch,&tree->[0x10],0) ── */
/* @0x1cdcdc ldr r12, [sp, #0xc] */
/* @0x1cdce0 mov r2, #0 */
/* @0x1cdce4 ldr r0, [r5] */
/* @0x1cdce8 mov r3, r2 */
/* @0x1cdcec str r2, [sp, #0x30] */
/* @0x1cdcf0 add r1, sp, #32 */
/* @0x1cdcf4 ldr r5, [r12, #0xe8] */
/* @0x1cdcf8 add r2, r0, #16 */
/* @0x1cdcfc ldr r6, [r12, #0xf0] */
/* @0x1cdd00 ldr lr, [r12, #0xec] */
/* @0x1cdd04 ldr r4, [r12, #0xf4] */
/* @0x1cdd08 str r12, [sp, #0x34] */
/* @0x1cdd0c cmp r6, r5 */
/* @0x1cdd10 strle r6, [sp, #0x20] */
/* @0x1cdd14 strgt r5, [sp, #0x20] */
/* @0x1cdd18 cmp r6, r5 */
/* @0x1cdd1c strge r6, [sp, #0x28] */
/* @0x1cdd20 strlt r5, [sp, #0x28] */
/* @0x1cdd24 cmp r4, lr */
/* @0x1cdd28 strle r4, [sp, #0x24] */
/* @0x1cdd2c strgt lr, [sp, #0x24] */
/* @0x1cdd30 cmp r4, lr */
/* @0x1cdd34 strge r4, [sp, #0x2c] */
/* @0x1cdd38 strlt lr, [sp, #0x2c] */
/* @0x1cdd3c bl 0x1cd700 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi> */
/* @0x1cdd40 add sp, sp, #60 */
/* @0x1cdd44 pop {r4, r5, r6, r7, pc} */
/* ② 的懒建支路：operator new(24) + RTree::RTree(1024) → 写回 g_tree ── */
/* @0x1cdd48 mov r0, #24 */
/* @0x1cdd4c bl 0x27c524 <_Znwj> */
/* @0x1cdd50 mov r1, #1024 */
/* @0x1cdd54 mov r6, r0 */
/* @0x1cdd58 bl 0x1cc320 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei> */
/* @0x1cdd5c str r6, [r5] */
/* @0x1cdd60 mov r0, r6 */
/* @0x1cdd64 b 0x1cdc84 <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x68> */
/* 池字（非指令）：0x00222a5c → GOT 0x3f0688 = option_use_fast_collision */
/* @0x1cdd68 eoreq r2, r2, r12, asr r10 */
/* 池字（非指令，objdump 记为 .word）：0x002205d0 → GOT 0x3ee24c = g_tree */
/* @0x1cdd6c .word 0x002205d0 */
