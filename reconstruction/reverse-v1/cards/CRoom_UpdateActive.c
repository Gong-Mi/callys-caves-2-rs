/* cally 逆向卡：CRoom::UpdateActive()（原版 libyoyo.so，armv7）
 * @func 0x1abd9c 0x1abf6c  size 464  116 条（116 条指令，无 literal pool、无栈帧扩展；
 *       下一个符号 _Z16_GetSpriteFramesi 0x1abf6c）
 * 级别: 正文（116/116 逐条落锚。两条实例链的每个字段角色、两条遍历方向、四分支搬运条件、A 链三档插入与
 *       B 链两档头插全部逐条解出。未钉的只有 inst+0x69 由谁置位/清除的时机。tier = bytecode_anchored）
 * 符号: _ZN5CRoom12UpdateActiveEv → void CRoom::UpdateActive()
 * 调用点: 全图唯一 0x1d3084，在 ProcessActivateDeactveLists 0x1d3074 里：
 *         r0 = *(GOT 0x3ed930 → 0x54298c = &Run_Room)，调完再把 *(0x542a4c + 8) 清 0（0x1d3088..0x1d3094）。
 *         即「每帧处理激活/去激活」时调一次，调用后清掉待处理标志。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   按 inst+0x69 把实例在 A 链（room+0x84 头 / +0x80 尾 / +0x88 计数，depth 降序）与 B 链
 *   （room+0x90 头 / +0x8c 尾 / +0x94 计数，头插无序）之间来回搬：第一趟把 B 里的活动实例按 depth
 *   插进 A，第二趟把 A 里的非活动实例头插进 B；每搬一个就调一次 CObjectGM::AddInstance / RemoveInstance。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   void CRoom::UpdateActive() {
 *     // 相位 1：B → A（活动实例）
 *     for (CInstance* p = this->[0x8c]; p; ) {          // 0x1abd9c 取 B 尾；0x1abdc4 先存 prev
 *       CInstance* prev = p->[0x178];
 *       if (p->[0x69] == 0) {                           // 0x1abdc8/0x1abdcc：活动才搬
 *         UnlinkB(this, p);                             // 0x1abdd0..0x1abdf8
 *         this->[0x94]--; this->[0x88]++;               // 0x1abde4/0x1abe0c、0x1abe04/0x1abe18
 *         InsertA_ByDepth(this, p);                     // 0x1abe1c → 0x1abe3c / 0x1abf1c / 0x1abf50
 *         ((CObjectGM*)p->[0x80])->AddInstance(p);      // 0x1abe54/0x1abe58
 *       }
 *       p = prev;                                       // 0x1abdbc / 0x1abe60
 *     }
 *     // 相位 2：A → B（非活动实例）
 *     for (CInstance* p = this->[0x80]; p; ) {          // 0x1abe64 取 A 尾
 *       CInstance* prev = p->[0x178];                   // 0x1abe88
 *       if (p->[0x69] != 0) {                           // 0x1abe8c/0x1abe90：非活动才搬
 *         UnlinkA(this, p);                             // 0x1abe94..0x1abec0
 *         PushFrontB(this, p);                          // 0x1abed0..0x1abf04（+0x88-- / +0x94++）
 *         ((CObjectGM*)p->[0x80])->RemoveInstance(p);   // 0x1abf08/0x1abf0c
 *       }
 *       p = prev;                                       // 0x1abe80 / 0x1abf14
 *     }
 *   }
 *
 * ── 四分支搬运条件（本卡的核心结论）──────────────────────────────────────
 *   分支 1（B→A）：相位 1 里 inst+0x69 == 0  → 从 B 摘下、按 depth 插入 A、AddInstance。
 *                锚点 0x1abdc8/0x1abdcc（bne 跳过）+ 0x1abdd0..0x1abe58。
 *   分支 2（留在 B）：相位 1 里 inst+0x69 != 0 → 不动链，只把游标退到 prev（回 0x1abdb4 判空）。
 *   分支 3（A→B）：相位 2 里 inst+0x69 != 0  → 从 A 摘下、头插 B、RemoveInstance。
 *                锚点 0x1abe8c/0x1abe90（beq 跳过）+ 0x1abe94..0x1abf0c。
 *   分支 4（留在 A）：相位 2 里 inst+0x69 == 0 → 不动链，只把游标退到 prev（回 0x1abe78）。
 *   两条判据互补（相位 1 只动活动、相位 2 只动非活动），且 +0x69 在本函数内没有任何写点
 *   （全函数无 strb，只有 str 写链接域与两个计数）⇒ 同一帧内一个实例最多被搬一次。
 *   插入子分支（A 链，三档）：
 *     ① A 空链：0x1abf50 — head = tail = inst、inst+0x184 = inst+0x180、+0x178 = +0x17c = 0；
 *     ② 前插：   0x1abf1c — 从 head 起 while (cur+0x184 > new+0x180) 沿 +0x17c 前进，
 *                停在第一个 cur+0x184 <= new+0x180 的节点前插入（cur 恰是头时改 room+0x84）；
 *     ③ 尾插：   0x1abe3c — 走到 cur == 0，挂到旧 tail 后面并更新 room+0x80 = inst。
 *     三档都在插入时把 inst+0x184 刷成 inst+0x180（0x1abf5c / 0x1abf48 / 0x1abe40）。
 *   B 链两档：空链（0x1abee4/0x1abef0 同时写头尾）与头插（旧 head->prev = new、new->next = 旧 head、
 *   head = new，0x1abee4/0x1abef4/0x1abefc）；B 不排序、不碰 +0x184。
 *
 * ── 两条链的字段角色（本卡逐条取证，与 CRoom_DeSerialise 卡一致）──────────
 *   A 链（活动）：room+0x84 = 头、room+0x80 = 尾、room+0x88 = 计数；depth 降序（head = 最大 depth），
 *                 排序键是 inst+0x184（快照），不是实时的 inst+0x180
 *   B 链（非活动）：room+0x90 = 头、room+0x8c = 尾、room+0x94 = 计数；头插、无序、无排序键
 *   实例侧：+0x178 = prev、+0x17c = next（两链共用同一对链接域 ⇒ 一个实例同一时刻只可能在一条链上）
 *   inst+0x69  = u8「非活动」标记（非 0 = 非活动；本函数只读）
 *   inst+0x180 = f32 depth（SetObjectIndex 0x193334 从 obj+0x08 写）
 *   inst+0x184 = f32 depth 快照（本函数每次插入 A 时写，A 的排序只认它）
 *   判据：摘链处「next == 0 就改 +0x8c」（0x1abddc）⇒ +0x8c 是尾；「prev == 0 就改 +0x90」（0x1abdf8）⇒ +0x90 是头；
 *   A 链同构（0x1abea0 改 +0x80 = 尾、0x1abebc 改 +0x84 = 头）。
 *
 * ── 已证（指令级）────────────────────────────────────────────────────────
 *  1. 相位 1 起点是 B 的**尾**（0x1abd9c 读 room+0x8c），沿 +0x178(prev) 向头走，prev == 0 收工（0x1abdb4）。
 *  2. 摘链四步（0x1abdd0..0x1abdfc）：next = inst+0x17c；next == 0 → room+0x8c = prev，否则 next->prev = prev；
 *     prev == 0 → room+0x90 = next，否则 prev->next = next。0x1abde8/0x1abdec 是编译器把「next == 0 时
 *     r2 = prev」写成 ldrne + moveq（两者值相同，只是省一次取数）。
 *  3. 计数在摘链后立刻更新：0x1abde4 sub、0x1abe0c 写回 room+0x94；0x1abe04 读 A 计数、0x1abe10 +1、
 *     0x1abe18 写回 room+0x88 —— 先减后加，中间没有能跳出的分支。
 *  4. 相位 2 起点是 A 的尾（0x1abe64 读 room+0x80）；摘链四步 0x1abe94..0x1abec0 与相位 1 同构，
 *     头尾字段换成 0x1abea0(room+0x80) / 0x1abebc(room+0x84)。0x1abea8 sub、0x1abedc 写 room+0x88；
 *     0x1abec8 读 room+0x94、0x1abed8 +1、0x1abee0 写回。
 *  5. B 的头插先把两个链接域清 0（0x1abed0/0x1abed4），再按 head 是否为空改写（0x1abee4..0x1abf04）；
 *     0x1abee8 是「head 非空时重读 room+0x90」的编译器重排（值不变）。
 *  6. 对象链副作用：搬进 A 调 CObjectGM::AddInstance 0x19e02c（0x1abe58，r0 = inst+0x80）；
 *     搬出 A 调 CObjectGM::RemoveInstance 0x19e0fc（0x1abf0c）。两处都不判 inst+0x80 是否为空。
 *  7. 全函数只有 2 个 bl（各在一条环里），无 blx、无异常表引用、无栈帧扩展；r6 只用来放常量 0（0x1abe70）。
 *  8. 相位 1 搬进来的节点在相位 2 会被再访问一次：它们 +0x69 == 0，命中分支 4（0x1abe78 跳过），
 *     所以第 6 条的「一帧最多搬一次」成立，但相位 2 的遍历量 = 整条 A 链（含刚搬入的）。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. inst+0x69 的写点不在本卡：已知只读闸（DoDestroy 0x10b0dc、CollisionUpdate 0x1cdc54），
 *     置位/清除者应在 instance_activate/deactivate_object 一族，那些函数还没出卡 ⇒ 时机未证。
 *  2. room+0x88 / room+0x94 两个计数是否始终等于实际链长，未做运行期核对；本卡只证每个搬运分支各 ∓1。
 *  3. A 链排序只认 +0x184 快照 ⇒ depth 变化后不重排；谁负责在 depth 变化后把实例重插一遍（或经 +0x69
 *     走一次 B 往返）未证。
 *  4. 跨卡不一致（不改别人的卡，只记）：StartRoom 卡第 332 行写「头 room+0x80 / 尾 room+0x84 / next +0x178 /
 *     prev +0x17c」，与本卡、以及 CRoom_DeSerialise 卡第 52 行（头 +0x84 / 尾 +0x80 / prev +0x178 /
 *     next +0x17c）相反。本卡以摘链代码与遍历方向逐条取证：+0x178 是 prev（从尾往头走）、+0x84 是头。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────────────────
 */
/* ── 1. 入口 + 相位 1 起步：r1 = room+0x8c（B 链尾）、r4 = room（0x1abd9c..0x1abdac）──
 *   0x1abd9c 的 ldr 排在 push 之前是编译器的槽位重排，不影响语义。 */
/* @0x1abd9c ldr r1, [r0, #0x8c] —— r1 = room+0x8c = B 链尾 */
/* @0x1abda0 push {r4, r5, r6, lr} */
/* @0x1abda4 cmp r1, #0 */
/* @0x1abda8 mov r4, r0 —— r4 = room（this） */
/* @0x1abdac bne 0x1abdc0 <_ZN5CRoom12UpdateActiveEv+0x24> —— B 尾非空 → 进环 0x1abdc0 */
/* @0x1abdb0 b 0x1abe64 <_ZN5CRoom12UpdateActiveEv+0xc8> —— B 空 → 直接进相位 2 */
/* ── 2. 相位 1 的跳过分支：r5 已是 prev；prev == 0 → 转相位 2（0x1abdb4..0x1abdbc）── */
/* @0x1abdb4 cmp r5, #0 */
/* @0x1abdb8 beq 0x1abe64 <_ZN5CRoom12UpdateActiveEv+0xc8> —— prev == 0 → 相位 1 结束 */
/* @0x1abdbc mov r1, r5 —— 游标 = prev */
/* ── 3. 相位 1 判据：先存 prev（0x1abdc4），再读 +0x69；非 0 → 回循环头跳过（0x1abdc0..0x1abdcc）── */
/* @0x1abdc0 ldrb r3, [r1, #0x69] */
/* @0x1abdc4 ldr r5, [r1, #0x178] —— 先存 prev（摘链后还要用它继续走） */
/* @0x1abdc8 cmp r3, #0 */
/* @0x1abdcc bne 0x1abdb4 <_ZN5CRoom12UpdateActiveEv+0x18> —— +0x69 != 0（非活动）→ 跳过，不搬 */
/* ── 4. 从 B 链摘下（四步）：尾字段 0x1abddc(+0x8c)、头字段 0x1abdf8(+0x90)（0x1abdd0..0x1abdfc）── */
/* @0x1abdd0 ldr r3, [r1, #0x17c] —— next = inst+0x17c */
/* @0x1abdd4 ldr r0, [r4, #0x94] —— B 计数 */
/* @0x1abdd8 cmp r3, #0 */
/* @0x1abddc streq r5, [r4, #0x8c] —— next == 0（inst 是尾）→ room+0x8c = prev */
/* @0x1abde0 strne r5, [r3, #0x178] —— 否则 next->prev = prev */
/* @0x1abde4 sub r0, r0, #1 —— B 计数 -1 */
/* @0x1abde8 ldrne r2, [r1, #0x178] —— r2 = prev */
/* @0x1abdec moveq r2, r5 —— next == 0 时直接复用 r5（同一个 prev），省一次 ldr */
/* @0x1abdf0 ldrne r3, [r1, #0x17c] */
/* @0x1abdf4 cmp r2, #0 */
/* @0x1abdf8 streq r3, [r4, #0x90] —— prev == 0（inst 是头）→ room+0x90 = next */
/* @0x1abdfc strne r3, [r2, #0x17c] —— 否则 prev->next = next */
/* ── 5. 相位 1 插入 A 的公共前段：取 A 头/计数、计数 +1 写回、A 空链则跳 0x1abf50（0x1abe00..0x1abe1c）── */
/* @0x1abe00 ldr r3, [r4, #0x84] —— A 链头 */
/* @0x1abe04 ldr r2, [r4, #0x88] —— A 计数 */
/* @0x1abe08 cmp r3, #0 */
/* @0x1abe0c str r0, [r4, #0x94] —— 写回 room+0x94 */
/* @0x1abe10 add r2, r2, #1 —— A 计数 +1 */
/* @0x1abe14 vldrne s14, [r1, #384] —— head 非空才读 depth(+0x180) */
/* @0x1abe18 str r2, [r4, #0x88] —— 写回 room+0x88 */
/* @0x1abe1c beq 0x1abf50 <_ZN5CRoom12UpdateActiveEv+0x1b4> —— A 空链 → 0x1abf50 首插 */
/* ── 6. A 链有序插入循环：vcmpe(cur+0x184, new+0x180)；bls（cur ≤ new）→ 0x1abf1c 前插；
 *   cur->next == 0 → 落到 0x1abe3c 尾插（0x1abe20..0x1abe38）── */
/* @0x1abe20 vldr s15, [r3, #388] */
/* @0x1abe24 vcmpe.f32 s15, s14 —— cur+0x184 vs inst+0x180 */
/* @0x1abe28 vmrs APSR_nzcv, fpscr */
/* @0x1abe2c bls 0x1abf1c <_ZN5CRoom12UpdateActiveEv+0x180> —— cur ≤ new → 0x1abf1c 前插 */
/* @0x1abe30 ldr r3, [r3, #0x17c] —— cur = cur->next */
/* @0x1abe34 cmp r3, #0 */
/* @0x1abe38 bne 0x1abe20 <_ZN5CRoom12UpdateActiveEv+0x84> —— 非空继续比 */
/* ── 7. A 链尾插：旧 tail->next = inst、inst->prev = tail、room+0x80 = inst、inst->next = 0、
 *   inst+0x184 = inst+0x180（0x1abe3c..0x1abe50）── */
/* @0x1abe3c ldr r2, [r4, #0x80] —— 旧 tail */
/* @0x1abe40 vstr s14, [r1, #388] —— inst+0x184 = depth（快照刷新） */
/* @0x1abe44 str r1, [r2, #0x17c] —— tail->next = inst */
/* @0x1abe48 str r2, [r1, #0x178] —— inst->prev = tail */
/* @0x1abe4c str r1, [r4, #0x80] —— room+0x80 = inst（新尾） */
/* @0x1abe50 str r3, [r1, #0x17c] —— inst->next = 0 */
/* ── 8. 相位 1 收尾：CObjectGM::AddInstance(inst+0x80)，然后按 prev 继续（0x1abe54..0x1abe60）── */
/* @0x1abe54 ldr r0, [r1, #0x80] —— r0 = inst+0x80（CObjectGM*） */
/* @0x1abe58 bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> —— CObjectGM::AddInstance */
/* @0x1abe5c cmp r5, #0 —— prev 判空 */
/* @0x1abe60 bne 0x1abdbc <_ZN5CRoom12UpdateActiveEv+0x20> */
/* ── 9. 相位 2 起步：r1 = room+0x80（A 链尾）；空链直接返回（0x1abe64..0x1abe6c）── */
/* @0x1abe64 ldr r1, [r4, #0x80] —— r1 = room+0x80 = A 链尾 */
/* @0x1abe68 cmp r1, #0 —— A 空 → 返回 */
/* @0x1abe6c popeq {r4, r5, r6, pc} —— 返回（出口之一，另一条在 0x1abf18） */
/* ── 10. 相位 2 循环头：r6 = 0（零寄存器，头插时清链接域用）；跳过分支在 0x1abe78（0x1abe70..0x1abe80）── */
/* @0x1abe70 mov r6, #0 —— r6 = 0 */
/* @0x1abe74 b 0x1abe84 <_ZN5CRoom12UpdateActiveEv+0xe8> */
/* @0x1abe78 cmp r5, #0 —— prev == 0 → 返回 */
/* @0x1abe7c popeq {r4, r5, r6, pc} */
/* @0x1abe80 mov r1, r5 */
/* ── 11. 相位 2 判据：先存 prev（0x1abe88），再读 +0x69；为 0 → 回循环头跳过（0x1abe84..0x1abe90）── */
/* @0x1abe84 ldrb r3, [r1, #0x69] —— +0x69 */
/* @0x1abe88 ldr r5, [r1, #0x178] —— 先存 prev */
/* @0x1abe8c cmp r3, #0 */
/* @0x1abe90 beq 0x1abe78 <_ZN5CRoom12UpdateActiveEv+0xdc> —— +0x69 == 0（活动）→ 跳过，不搬 */
/* ── 12. 从 A 链摘下：尾字段 0x1abea0(room+0x80)、头字段 0x1abebc(room+0x84)（0x1abe94..0x1abec0）── */
/* @0x1abe94 ldr r3, [r1, #0x17c] —— next = inst+0x17c */
/* @0x1abe98 ldr r0, [r4, #0x88] —— A 计数 */
/* @0x1abe9c cmp r3, #0 */
/* @0x1abea0 streq r5, [r4, #0x80] —— next == 0（inst 是尾）→ room+0x80 = prev */
/* @0x1abea4 strne r5, [r3, #0x178] —— 否则 next->prev = prev */
/* @0x1abea8 sub r0, r0, #1 —— A 计数 -1 */
/* @0x1abeac ldrne r2, [r1, #0x178] */
/* @0x1abeb0 moveq r2, r5 */
/* @0x1abeb4 ldrne r3, [r1, #0x17c] */
/* @0x1abeb8 cmp r2, #0 */
/* @0x1abebc streq r3, [r4, #0x84] —— prev == 0（inst 是头）→ room+0x84 = next */
/* @0x1abec0 strne r3, [r2, #0x17c] —— 否则 prev->next = next */
/* ── 13. B 链头插 + 计数更新 + RemoveInstance（0x1abec4..0x1abf18）──
 *   0x1abed0/0x1abed4 先把新节点的两个链接域清 0，再按 head 是否为空分两档。 */
/* @0x1abec4 ldr r3, [r4, #0x90] —— B 链头 */
/* @0x1abec8 ldr r2, [r4, #0x94] —— B 计数 */
/* @0x1abecc cmp r3, #0 */
/* @0x1abed0 str r6, [r1, #0x178] —— inst->prev = 0 */
/* @0x1abed4 str r6, [r1, #0x17c] —— inst->next = 0 */
/* @0x1abed8 add r2, r2, #1 —— B 计数 +1 */
/* @0x1abedc str r0, [r4, #0x88] —— 写回 room+0x88 */
/* @0x1abee0 str r2, [r4, #0x94] —— 写回 room+0x94 */
/* @0x1abee4 strne r1, [r3, #0x178] —— head 非空 → 旧 head->prev = inst */
/* @0x1abee8 ldrne r3, [r4, #0x90] —— 重读 head（值不变） */
/* @0x1abeec streq r1, [r4, #0x90] —— head 空 → room+0x90 = inst */
/* @0x1abef0 streq r1, [r4, #0x8c] —— head 空 → room+0x8c = inst（尾也是它） */
/* @0x1abef4 strne r3, [r1, #0x17c] —— head 非空 → inst->next = 旧 head */
/* @0x1abef8 streq r3, [r1, #0x17c] —— head 空 → inst->next = 0 */
/* @0x1abefc strne r1, [r4, #0x90] —— head = inst */
/* @0x1abf00 streq r3, [r1, #0x178] —— head 空 → inst->prev = 0 */
/* @0x1abf04 strne r6, [r1, #0x178] —— head 非空 → inst->prev = 0 */
/* @0x1abf08 ldr r0, [r1, #0x80] —— r0 = inst+0x80 */
/* @0x1abf0c bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> —— CObjectGM::RemoveInstance */
/* @0x1abf10 cmp r5, #0 —— prev 非空 → 继续相位 2 */
/* @0x1abf14 bne 0x1abe80 <_ZN5CRoom12UpdateActiveEv+0xe4> —— 否则返回 */
/* @0x1abf18 pop {r4, r5, r6, pc} —— 返回（另一出口） */
/* ── 14. 相位 1 的「前插」子分支：停在第一个 cur+0x184 <= new+0x180 的节点前；cur 是 A 头时改 room+0x84
 *   （0x1abf1c..0x1abf4c）── */
/* @0x1abf1c ldr r2, [r3, #0x178] —— cur->prev */
/* @0x1abf20 cmp r2, #0 */
/* @0x1abf24 streq r3, [r1, #0x17c] —— cur 是头 → inst->next = cur */
/* @0x1abf28 strne r2, [r1, #0x178] —— 否则 inst->prev = cur->prev */
/* @0x1abf2c ldrne r2, [r3, #0x178] */
/* @0x1abf30 streq r1, [r3, #0x178] —— cur 是头 → cur->prev = inst */
/* @0x1abf34 strne r3, [r1, #0x17c] —— 否则 inst->next = cur */
/* @0x1abf38 streq r1, [r4, #0x84] —— cur 是头 → room+0x84 = inst */
/* @0x1abf3c strne r1, [r2, #0x17c] —— 否则 cur->prev->next = inst */
/* @0x1abf40 streq r2, [r1, #0x178] —— cur 是头 → inst->prev = 0 */
/* @0x1abf44 strne r1, [r3, #0x178] —— 否则 cur->prev = inst */
/* @0x1abf48 vstr s14, [r1, #388] —— inst+0x184 = depth */
/* @0x1abf4c b 0x1abe54 <_ZN5CRoom12UpdateActiveEv+0xb8> —— 回 0x1abe54 调 AddInstance */
/* ── 15. 相位 1 的「空链首插」子分支：head = tail = inst、+0x184 = +0x180、两链接域 0（0x1abf50..0x1abf68）── */
/* @0x1abf50 ldr r2, [r1, #0x180] —— depth = inst+0x180 */
/* @0x1abf54 str r1, [r4, #0x84] —— room+0x84 = inst（头） */
/* @0x1abf58 str r1, [r4, #0x80] —— room+0x80 = inst（尾） */
/* @0x1abf5c str r2, [r1, #0x184] —— inst+0x184 = depth */
/* @0x1abf60 str r3, [r1, #0x17c] —— inst->next = 0 */
/* @0x1abf64 str r3, [r1, #0x178] —— inst->prev = 0 */
/* @0x1abf68 b 0x1abe54 <_ZN5CRoom12UpdateActiveEv+0xb8> —— 回 0x1abe54 */
