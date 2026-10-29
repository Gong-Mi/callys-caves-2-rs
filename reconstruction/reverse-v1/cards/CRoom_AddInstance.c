/* cally 逆向卡：CRoom::AddInstance 家族（原版 libyoyo.so，armv7）
 *
 * @card 0x001aadac .. 0x001ab794（5 个函数 / 520 条锚点，地址各只出现一次）
 *        —— 本卡按 @func 分成 5 节：AddInstanceToStorage + 4 个 AddInstance 重载。
 *           verify_reverse_v1 的 range 列只取文件里第一个 @func（0x001aadac..0x001aaf74），
 *           本卡真实覆盖面看上面 @card 这一行与 5 个 @func 小节。
 * @func 0x1aadac 0x1aaf78  size 460  115 条（AddInstanceToStorage：只登记 40 B 蓝图，不造对象）
 * @func 0x1ab144 0x1ab2f0  size 428  107 条（AddInstance(f,f,int)：第 3 参是 objindex）
 * @func 0x1ab2e4 0x1ab4a0  size 444  111 条（AddInstance(f,f,int,int)：第 3 参是 depth、第 4 参才是 objindex）
 * @func 0x1ab494 0x1ab660  size 460  115 条（AddInstance(f,f,CLayer*,int)：depth 抄自 layer+0x04，层内注册）
 * @func 0x1ab654 0x1ab798  size 324  81 条（AddInstance(CInstance*)：不分配、不建物理体、只挂链+登记）
 * 级别: 正文（520/520 条逐条解出；两条链的四个分支、id 哈希表的桶/节点形状、5 个入口的
 *            上半身差异、以及 ToStorage 记录的 12 个字段全部钉住。未钉：字段的「官方名字」
 *            —— CInstance+0x180/+0x184、CRoom+0xc8、CLayer+0x04、哈希表头 +0x04 的掩码语义、
 *            ToStorage 记录里 6 个常量格的用途；另 AddInstance(CInstance*) 无 .text 内直接调用点）
 * 符号: _ZN5CRoom20AddInstanceToStorageEffi   void CRoom::AddInstanceToStorage(float, float, int)
 *       _ZN5CRoom11AddInstanceEffi            CInstance* CRoom::AddInstance(float, float, int)
 *       _ZN5CRoom11AddInstanceEffii           CInstance* CRoom::AddInstance(float, float, int, int)
 *       _ZN5CRoom11AddInstanceEffP6CLayeri    CInstance* CRoom::AddInstance(float, float, CLayer*, int)
 *       _ZN5CRoom11AddInstanceEP9CInstance    CInstance* CRoom::AddInstance(CInstance*)
 * ABI : softfp（float 走 r1/r2；栈上的 float 实参 4 B/个）；返回 CInstance*（ToStorage 那个无返回值）
 * 来源: libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f…（4,689,844 B，stripped，ELF32 ARM）
 * 锚表: asm/index-CRoom_AddInstance_all.tsv（520 行 = index-CRoom_AddInstance_1..5.tsv 顺序拼接；
 *       五段各自与本卡同名小节逐字一致：115 + 104 + 108 + 112 + 81 = 520）
 * 同层: CInstance::C2 0x1994dc（本卡 3 处调用）、CInstance::CreatePhysicsBody 0x192cd4、
 *       CLayerManager::AddInstance 0x1c5d18、CLayerManager::AddInstanceToLayer 0x1c5a38、
 *       CollisionInsert 0x1cc494、CRoom::UpdateActive 0x1abd9c（同构的三档插链）、
 *       CRoom::DeSerialise 0x1ac33c（自建同样的链，但不走本卡）、CRoom::AddTile 0x1ac240、
 *       CRoom::AddTileToStorage 0x1aaf78（同一套 cARRAY 惯用法）、
 *       MemoryManager::Alloc 0x27ce78 / operator new 0x27c524
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   四个 AddInstance 重载共用同一段「下半身」：拿到/造出 CInstance → 插 room+0x84 的 depth
 *   降序链 → 插 ms_ID2InstanceE 的 id 哈希 → CLayerManager 注册 → CollisionInsert。
 *   它们只在「上半身」分家：谁分配对象、id 从哪来、depth 取什么、注册到哪个层。
 *   AddInstanceToStorage 是**另一条路**：一个 CInstance 都不造，只把一条 40 B 蓝图记录追加进
 *   room+0xc8 的堆数组，并向 room_maxid 预取 id —— 它是「暂存」，不是「实例化」。
 *
 * ── 5 个入口的差别（一行一格）────────────────────────────────
 *   入口                                CInstance  id 来源        depth 来源           层注册            碰撞
 *   AddInstanceToStorage(f,f,obj)        不造      ++room_maxid   —（记录里没有 depth） 无                无
 *   AddInstance(f,f,obj)                 new 432   ++room_maxid   ctor 留下的 +0x180    AddInstance       CollisionInsert
 *   AddInstance(f,f,depth,obj)           new 432   ++room_maxid   (float)第3参，ctor 后覆写  AddInstance   CollisionInsert
 *   AddInstance(f,f,layer,obj)           new 432   ++room_maxid   (float)layer[+0x04]   AddInstanceToLayer CollisionInsert
 *   AddInstance(inst)                    外部给    inst+0x78      inst+0x180            AddInstance       CollisionInsert
 *   ★ 参数位次是坑：3 参版第 3 个 int 是 **objindex**；4 参版第 3 个 int 是 **depth**、
 *     第 4 个 int（在栈上）才是 objindex。唯一调用 4 参版的 Command_Create_Depth(int obj,float x,
 *     float y,int depth) 0x1c98d4 正好按 (x=r1, y=r2, depth=r3, obj=[sp]) 摆参（0x1c990c-0x1c9914）。
 *
 * ── A 链插入的完整条件（本卡主结论）────────────────────────────
 *   链域：room+0x84 头 / room+0x80 尾 / room+0x88 计数；节点 +0x178 prev / +0x17c next /
 *         +0x184 depth 快照（排序键）；对象自己的 depth 在 +0x180。
 *   ① count：进入插入前先 room+0x88 += 1，**空链也加**，且加在分支判断之前（5 个入口一致）。
 *   ② head == 0（空链）→ head = tail = 新节点；新节点 prev = next = 0；
 *      +0x184 = +0x180（拷一份快照）。
 *   ③ head != 0 → 从 head 起 while (cur+0x184 > new+0x180) cur = cur->next：
 *      · 走到 cur == 0  → 尾插：old_tail->next = new、new->prev = old_tail、
 *                        room+0x80 = new、new->next = 0；
 *      · 停在某 cur   → 前插（插在 cur 之前）：
 *                        cur->prev == 0 → new->next = cur、cur->prev = new、room+0x84 = new、new->prev = 0；
 *                        否则           → new->prev = cur->prev、new->next = cur、
 *                                         cur->prev->next = new、cur->prev = new。
 *      两路结尾都写 new+0x184 = new+0x180。
 *   ④ 判据用 vcmpe.f32 + vmrs + bls（cur+0x184 ≤ new+0x180 就停）⇒ 链按 depth **降序**；
 *      相等时新节点插在旧节点**之前**（bls 是「≤」）。
 *   ⑤ 全程只碰 A 链：B 链（room+0x90/+0x8c/+0x94）在 5 个入口里一条指令都没出现。
 *
 * ── id 哈希表（ms_ID2InstanceE，GOT 0x3edc4c → .bss 0x536f28）──
 *   表头 12 B：+0x00 桶数组基址、+0x04 掩码、+0x08 计数；
 *   桶 8 B：{head@0, tail@4}；桶号 = id & [map+0x04]；桶地址 = buckets + 桶号*8；
 *   节点 16 B：{prev@0, next@4, key@8, value@0xc}，Alloc(16, "…/Platform/Hash.h", 306, true)；
 *   插**桶尾**（node->prev = tail、tail->next = node、bucket->tail = node、node->next = 0），
 *   空桶时 head = tail = node 且两链域清零；最后 [map+0x08] += 1。
 *   ★ 不查重：同 id 再插入会得到两个节点（本卡不负责 id 唯一性）。
 *
 * ── 与两个 ToStorage 的分工 ───────────────────────────────────
 *   AddInstance*（本卡 4 个重载）改的是**活房间**：链、id 表、层表、碰撞世界。
 *   AddInstanceToStorage 改的是 room+0xc8 上一个独立堆数组（40 B/条），不碰上述四处，
 *   也不碰 room+0xc4（那是 AddTileToStorage 的 48 B/条 tile 暂存数组，见 CRoom_AddTile 卡）。
 *   两者唯一共享的是 room_maxid 这条 id 序列 —— 所以「暂存过的 id」和「实例化过的 id」
 *   会交错消耗同一个计数器（open 5：这条交错的后果未做运行期验证）。
 *
 * ── 未定（open）────────────────────────────────────────────
 *   1. CInstance+0x180（depth）与 +0x184（快照）的官方名字；本卡只用「排序键是快照」这一事实
 *   2. CLayer+0x04 的语义：4 参重载把它当 depth 用（vcvt.f32.s32），字段名未证
 *   3. AddInstanceToStorage 记录里 +0x10=0 / +0x14=1.0f / +0x18=1.0f / +0x1c=-1 / +0x20=0 /
 *      +0x24=0 六个常量格的用途（形状像图像号与缩放/旋转默认值，但没有第二个写入点可对照）
 *   4. 哈希表头 +0x04 是「掩码」还是「桶数-1」：只证到用它做 `and`，未证桶数组长度
 *   5. room_maxid 被 create 与 room_instance_add 共用一条序列，交错后的 id 语义（是否被存档依赖）
 *   6. AddInstance(CInstance*) 在 .text 内**零**个 b/bl 直呼点（8/1/2 个调用点分别落在其余三个
 *      重载上）⇒ 只能经函数指针/vtable/库外调用；谁在调它未证
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ══════════════════════════════════════════════════════════════════
 * 1) AddInstanceToStorage(float x, float y, int objindex) —— 只登记蓝图
 * ══════════════════════════════════════════════════════════════════ */

/* ── 入口 ───────────────────────────────────────────────────────
 *   帧：push {r4-r11,lr} + vpush {d8} + sub sp,#20
 *   r6 = this(CRoom*)；[sp+0xc] = objindex；s17 = x、s16 = y（softfp 走 r1/r2）
 *   r7 = CRoom+0xc8 = 「实例暂存数组」指针；本函数只在 1aaebc 写它。
 *   ★ 分工：这里一个 CInstance 都不分配、不挂链、不进层、不插碰撞；只把一条 40 B 记录
 *     追加进 +0xc8 的数组，并向 room_maxid 预取一个 id。
 */

/* @0x1aadac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1aadb0 vpush {d8} */
/* @0x1aadb4 sub sp, sp, #20 */
/* ── 数组形状（cARRAY 惯用法，AddTileToStorage 同构）──────────
 *   +0xc8 → { int count; void* slots[count+1]; Record entries[count+1]; }
 *   slots[i] 指进**同一块**的 entries[i]；Record = 40 B（字段表见 1aaecc）。
 *   每次调用整块重建：新块 = 44*(count+1)+4 B（4 头 + 4*(n+1) 槽 + 40*(n+1) 记录），
 *   旧记录抄进新块、槽逐条重指向，最后 Free 旧块 ⇒ **上次拿到的 entries 指针全部失效**。
 */

/* @0x1aadb8 ldr r7, [r0, #0xc8] */
/* @0x1aadbc mov r6, r0 */
/* @0x1aadc0 str r3, [sp, #0xc] */
/* @0x1aadc4 vmov s17, r1 */
/* @0x1aadc8 cmp r7, #0 */
/* @0x1aadcc vmov s16, r2 */
/* ── +0xc8 == 0 的分支：走 1aaf38 就地建 count=0 的空块（48 B = 4+4+40）──
 *   注意 AddTileToStorage 没有这一步：它直接解引用 +0xc4（见 CRoom_AddTile 卡）。
 */

/* @0x1aadd0 beq 0x1aaf38 <_ZN5CRoom20AddInstanceToStorageEffi+0x18c> */
/* @0x1aadd4 ldr r12, [r7] */
/* ── 扩容：字节数 = 44*(count+1) + 4 ─────────────────────────
 *   44 = 4（槽）+ 40（记录）；+4 是 count 头。文件串 = "jni/../jni/yoyo/../../../Files/
 *   Room/Room_Class.cpp"（池字 1aaf6c 与 1aaf74 两个站点都指向 0x34d1b0），行 1225，
 *   第 5 实参 false = 不清零（随后逐字段写补上）。
 */

/* @0x1aadd8 mov r0, #44 */
/* @0x1aaddc ldr r1, [pc, #0x188] */
/* @0x1aade0 movw r2, #0x4c9 */
/* @0x1aade4 mov r3, #1 */
/* @0x1aade8 mla r0, r12, r0, r0 */
/* @0x1aadec add r1, pc, r1 */
/* @0x1aadf0 add r0, r0, #4 */
/* @0x1aadf4 str r0, [sp, #0x8] */
/* @0x1aadf8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* ── 旧块回放：r1 = new + 4*count + 8 = 新块 entries 区起点 ──
 *   lr 走槽游标、r1 走记录游标；每轮 slots[i] = 记录新址（NULL 槽写 0 并跳过复制）。
 *   count == 0（空块）直接跳到 1aae98。
 */

/* @0x1aadfc ldr r2, [r7] */
/* @0x1aae00 cmp r2, #0 */
/* @0x1aae04 add r1, r0, #4 */
/* @0x1aae08 str r1, [sp, #0x4] */
/* @0x1aae0c add r1, r0, r2, lsl #2 */
/* @0x1aae10 mov r10, r0 */
/* @0x1aae14 add r1, r1, #8 */
/* @0x1aae18 ble 0x1aae98 <_ZN5CRoom20AddInstanceToStorageEffi+0xec> */
/* @0x1aae1c ldr lr, [sp, #0x4] */
/* @0x1aae20 mov r4, r7 */
/* @0x1aae24 mov r12, #0 */
/* @0x1aae28 str r1, [lr], #4 */
/* @0x1aae2c ldr r3, [r4, #0x4]! */
/* @0x1aae30 cmp r3, #0 */
/* @0x1aae34 streq r3, [lr, #-0x4] */
/* @0x1aae38 beq 0x1aae88 <_ZN5CRoom20AddInstanceToStorageEffi+0xdc> */
/* ── 记录复制：先 32 B（8 字，两轮 4 字），再在 1aae74 补最后 8 B = 40 B ──
 *   记录是纯 POD：无指针、无引用计数，抄过去即可。
 */

/* @0x1aae3c add r0, r3, #32 */
/* @0x1aae40 mov r2, r1 */
/* @0x1aae44 ldr r11, [r3] */
/* @0x1aae48 add r3, r3, #16 */
/* @0x1aae4c ldr r9, [r3, #-0xc] */
/* @0x1aae50 add r2, r2, #16 */
/* @0x1aae54 ldr r8, [r3, #-0x8] */
/* @0x1aae58 ldr r5, [r3, #-0x4] */
/* @0x1aae5c cmp r3, r0 */
/* @0x1aae60 str r11, [r2, #-0x10] */
/* @0x1aae64 str r9, [r2, #-0xc] */
/* @0x1aae68 str r8, [r2, #-0x8] */
/* @0x1aae6c str r5, [r2, #-0x4] */
/* @0x1aae70 bne 0x1aae44 <_ZN5CRoom20AddInstanceToStorageEffi+0x98> */
/* @0x1aae74 ldr r0, [r3] */
/* @0x1aae78 ldr r3, [r3, #0x4] */
/* @0x1aae7c str r0, [r2] */
/* @0x1aae80 str r3, [r2, #0x4] */
/* @0x1aae84 ldr r2, [r7] */
/* @0x1aae88 add r12, r12, #1 */
/* @0x1aae8c add r1, r1, #40 */
/* @0x1aae90 cmp r2, r12 */
/* @0x1aae94 bgt 0x1aae28 <_ZN5CRoom20AddInstanceToStorageEffi+0x7c> */
/* ── 新块收尾：写 count → Free 旧块 → +0xc8 换成新基址 ──
 *   ★ 顺序是「先 Free 旧的、再写新记录」；1aaea8 把 r7 换成 [sp+8]（新块字节数），
 *     所以 1aaeb0 的 sub r12,r7,#40 求的正是新记录偏移 = 44n+8。
 */

/* @0x1aae98 mov r0, r7 */
/* @0x1aae9c str r2, [r10] */
/* @0x1aaea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aaea4 ldr r1, [r10] */
/* @0x1aaea8 ldr r7, [sp, #0x8] */
/* ── 新记录落位：r3 = base + (44*(n+1)+4) - 40 = base + 44n + 8 ──
 *   与 entries 起点（base+4n+8）再走 40n 完全一致；此刻 [r10] 处的 count 仍是旧值 n。
 */

/* @0x1aaeac lsl r1, r1, #2 */
/* @0x1aaeb0 sub r12, r7, #40 */
/* ── 坐标整型化：x、y 都过 vcvt.s32.f32，落盘是 int（不是 float）──
 *   x：vcvt → vmov r7,s17 → str（1aaf08）；y：vcvt → vstr s16（1aaf0c，vstr 写的正是那个
 *   32 位整数位型）。⇒ 记录里是**截断整型**坐标，与 CInstance+0xb4/+0xb8 的 float 不同。
 *   1aaebc 同时把 +0xc8 换成新块基址（先换、后写记录）。
 */

/* @0x1aaeb4 vcvt.s32.f32 s17, s17 */
/* @0x1aaeb8 ldr r7, [sp, #0x4] */
/* @0x1aaebc str r10, [r6, #0xc8] */
/* @0x1aaec0 add r3, r10, r12 */
/* @0x1aaec4 ldr r2, [pc, #0xa4] */
/* @0x1aaec8 mov r4, #1065353216 */
/* ── 槽回写 + 字段表（Record = 40 B）────────────────────────
 *   +0x00 int   (int)x        1aaf08
 *   +0x04 int   (int)y        1aaf0c（vcvt 之后的位型，按 int 读）
 *   +0x08 int   objindex      1aaee8（第 3 实参原样）
 *   +0x0c int   id            1aaf00，取自 ++room_maxid（池字 1aaf70 → GOT 0x3f0814 → .bss 0x54255c）
 *   +0x10 int   0             1aaf20
 *   +0x14 float 1.0f          1aaf18（r4 = 0x3F800000）
 *   +0x18 float 1.0f          1aaf1c
 *   +0x1c int   -1            1aaf14（mvn r5,#0）
 *   +0x20 int   0             1aaf10
 *   +0x24 int   0             1aaf24
 *   6 个常量格语义未定（open 3）。★ 记录里没有 depth、没有层指针、没有链域。
 */

/* @0x1aaecc str r3, [r7, r1] */
/* @0x1aaed0 mov r6, #0 */
/* @0x1aaed4 ldr r7, [sp, #0xc] */
/* @0x1aaed8 ldr r2, [pc, r2] */
/* @0x1aaedc mov r1, #0 */
/* @0x1aaee0 mvn r5, #0 */
/* @0x1aaee4 ldr r0, [r2] */
/* @0x1aaee8 str r7, [r3, #0x8] */
/* @0x1aaeec vcvt.s32.f32 s16, s16 */
/* @0x1aaef0 vmov r7, s17 */
/* @0x1aaef4 add r0, r0, #1 */
/* @0x1aaef8 str r0, [r2] */
/* @0x1aaefc ldr r2, [r10] */
/* @0x1aaf00 str r0, [r3, #0xc] */
/* @0x1aaf04 add r2, r2, #1 */
/* @0x1aaf08 str r7, [r10, r12] */
/* @0x1aaf0c vstr s16, [r3, #4] */
/* @0x1aaf10 str r6, [r3, #0x20] */
/* @0x1aaf14 str r5, [r3, #0x1c] */
/* @0x1aaf18 str r4, [r3, #0x14] */
/* @0x1aaf1c str r4, [r3, #0x18] */
/* @0x1aaf20 str r1, [r3, #0x10] */
/* @0x1aaf24 str r1, [r3, #0x24] */
/* ── count = n+1（先写槽、再写字段、最后抬 count）→ 返回 void ──
 *   r0 此刻是 Alloc 的残留值，函数不设返回值。
 */

/* @0x1aaf28 str r2, [r10] */
/* @0x1aaf2c add sp, sp, #20 */
/* @0x1aaf30 vpop {d8} */
/* @0x1aaf34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 首建路径：Alloc(48, Room_Class.cpp, 1249, true) → {count=0, slots[0]=base+4} ──
 *   48 = 4（count）+ 4（slots[0]）+ 40（entries[0]）：正好够放第一条，所以首建不需要
 *   单独的「扩容」分支，建完 b 1aaeb4 直接写第 0 条。r12 = 8 = entries[0] 相对块基址的偏移。
 */

/* @0x1aaf38 ldr r1, [pc, #0x34] */
/* @0x1aaf3c mov r0, #48 */
/* @0x1aaf40 movw r2, #0x4e1 */
/* @0x1aaf44 mov r3, #1 */
/* @0x1aaf48 add r1, pc, r1 */
/* @0x1aaf4c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aaf50 mov r12, #8 */
/* @0x1aaf54 add r1, r0, #4 */
/* @0x1aaf58 mov r10, r0 */
/* @0x1aaf5c str r1, [sp, #0x4] */
/* @0x1aaf60 mov r1, r7 */
/* @0x1aaf64 str r7, [r0] */
/* @0x1aaf68 b 0x1aaeb4 <_ZN5CRoom20AddInstanceToStorageEffi+0x108> */
/* ── literal pool（3 字，objdump 译成指令，按规矩保留原写法）──
 *   1aaf6c = 0x001a23bc  加数：pc 1aadf4 + 0x1a23bc = 0x34d1b0 = Room_Class.cpp（扩容站点）
 *   1aaf70 = 0x00245934  加数：pc 1aaee0 + 0x245934 = 0x3f0814 → .bss 0x54255c = room_maxid
 *   1aaf74 = 0x001a2260  加数：pc 1aaf50 + 0x1a2260 = 0x34d1b0 = Room_Class.cpp（首建站点）
 */

/* @0x1aaf6c ldrheq r2, [r10], -r12 */
/* @0x1aaf70 eoreq r5, r4, r4, lsr r9 */
/* @0x1aaf74 andseq r2, r10, r0, ror #4 */
/* ══════════════════════════════════════════════════════════════════
 * 2) AddInstance(float x, float y, int objindex) —— 最常用入口（.text 内 8 个调用点）
 * ══════════════════════════════════════════════════════════════════ */

/* ── 入口：r5 = this、r8 = x、r7 = y、r9 = objindex（r3）──
 *   池字 1ab2d8 = 0x002456c0 → 1ab154 + 0x2456c0 = 0x3f0814 → room_maxid。
 *   ★ 本重载不写 depth：ctor 留下的 +0x180 原样保留（CInstance_ctor 用对象的 depth 值，
 *     见 CInstance_ctor.c 字段表「+0x180 ← (float)(int)obj+0x08」）。
 *   调用点：Command_Create 0x1c9870、F_InstanceCopy 0x109818、F_ActionCreateObjectRandom 0x13e330
 *   等 8 处（0x109818/0x13e41c/0x13e488/0x14179c/0x141818/0x14192c/0x1419c0/0x1c9870）。
 */

/* @0x1ab144 ldr r12, [pc, #0x18c] */
/* @0x1ab148 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ab14c ldr r12, [pc, r12] */
/* @0x1ab150 sub sp, sp, #12 */
/* @0x1ab154 mov r5, r0 */
/* ── id 分配：id = ++room_maxid（先加后取；全局单调，不查重、不复用）──
 *   ★ 与 AddInstanceToStorage 用**同一个** room_maxid ⇒ 运行期 create 与 room_instance_add
 *     共用一条 id 序列（open 5）。
 */

/* @0x1ab158 ldr r6, [r12] */
/* ── operator new(432) —— sizeof(CInstance) = 432（与 CInstance_ctor 卡同值）──
 *   r9 暂存 objindex；[sp] = objindex、[sp+4] = 1 是 C2 的第 4/5 个值参。
 */

/* @0x1ab15c mov r0, #432 */
/* @0x1ab160 mov r9, r3 */
/* @0x1ab164 mov r8, r1 */
/* @0x1ab168 mov r7, r2 */
/* @0x1ab16c add r6, r6, #1 */
/* @0x1ab170 str r6, [r12] */
/* @0x1ab174 bl 0x27c524 <_Znwj> */
/* @0x1ab178 mov r3, r6 */
/* @0x1ab17c mov r12, #1 */
/* @0x1ab180 mov r2, r7 */
/* @0x1ab184 mov r1, r8 */
/* @0x1ab188 str r12, [sp, #0x4] */
/* @0x1ab18c str r9, [sp] */
/* @0x1ab190 mov r4, r0 */
/* ── CInstance::C2(x, y, id, objindex, true) → CreatePhysicsBody(room) ──
 *   ★ 三个 float 重载都建物理体；AddInstance(CInstance*) 不建（对象已存在）。
 *   注意 vcvt 不会在这里出现：x/y 全程以 float 进 ctor（+0xb4/+0xb8）。
 */

/* @0x1ab194 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ab198 mov r0, r4 */
/* @0x1ab19c mov r1, r5 */
/* @0x1ab1a0 bl 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
/* ── A 链插入起点（room+0x84 头 / +0x80 尾 / +0x88 计数）──
 *   ① 1ab1b4/1ab1b8：+0x88 += 1 **无条件**，且在分支之前（空链也加）；
 *   ② 1ab1b0 的 vldrne 说明只有 head != 0 才读 inst+0x180；
 *   ③ 1ab1c0 读的是 cur+0x184（快照），不是 cur+0x180。
 */

/* @0x1ab1a4 ldr r3, [r5, #0x84] */
/* @0x1ab1a8 ldr r2, [r5, #0x88] */
/* @0x1ab1ac cmp r3, #0 */
/* @0x1ab1b0 vldrne s14, [r4, #384] */
/* @0x1ab1b4 add r2, r2, #1 */
/* @0x1ab1b8 str r2, [r5, #0x88] */
/* @0x1ab1bc beq 0x1ab2bc <_ZN5CRoom11AddInstanceEffi+0x178> */
/* ── 有序遍历：while (cur+0x184 > inst+0x180) cur = cur+0x17c ──
 *   vcmpe.f32 + vmrs + bls = 「cur ≤ new 就停」⇒ 链按 depth 降序；相等时新节点在前。
 *   与 CRoom::UpdateActive 0x1abd9c 的三档（空链 / 前插 / 尾插）同构。
 */

/* @0x1ab1c0 vldr s15, [r3, #388] */
/* @0x1ab1c4 vcmpe.f32 s15, s14 */
/* @0x1ab1c8 vmrs APSR_nzcv, fpscr */
/* @0x1ab1cc bls 0x1ab288 <_ZN5CRoom11AddInstanceEffi+0x144> */
/* @0x1ab1d0 ldr r3, [r3, #0x17c] */
/* @0x1ab1d4 cmp r3, #0 */
/* @0x1ab1d8 bne 0x1ab1c0 <_ZN5CRoom11AddInstanceEffi+0x7c> */
/* ── 尾插档（走到 cur == 0）：挂到 room+0x80 的 tail 后面 ──
 *   old_tail->[0x17c] = inst；inst->[0x178] = old_tail；room+0x80 = inst；inst->[0x17c] = 0。
 */

/* @0x1ab1dc ldr r2, [r5, #0x80] */
/* @0x1ab1e0 vstr s14, [r4, #388] */
/* @0x1ab1e4 str r4, [r2, #0x17c] */
/* @0x1ab1e8 str r2, [r4, #0x178] */
/* @0x1ab1ec str r4, [r5, #0x80] */
/* @0x1ab1f0 str r3, [r4, #0x17c] */
/* ── id 哈希插入（ms_ID2InstanceE：GOT 0x3edc4c → .bss 0x536f28）──
 *   表头 +0x00 桶数组 / +0x04 掩码 / +0x08 计数；桶号 = id & [map+4]；
 *   节点 Alloc(16, "…/Platform/Hash.h", 306, true)：{prev@0, next@4, key=id@8, value=inst@0xc}；
 *   插桶尾（node->prev = tail、tail->next = node、bucket->tail = node、node->next = 0），
 *   空桶 head = tail = node 且两链域清零；最后 [map+8] += 1。★ 不查重。
 */

/* @0x1ab1f4 ldr r6, [pc, #0xe0] */
/* @0x1ab1f8 movw r2, #0x132 */
/* @0x1ab1fc ldr r1, [pc, #0xdc] */
/* @0x1ab200 mov r3, #1 */
/* @0x1ab204 ldr r6, [pc, r6] */
/* @0x1ab208 mov r0, #16 */
/* @0x1ab20c add r1, pc, r1 */
/* @0x1ab210 ldr r9, [r4, #0x78] */
/* @0x1ab214 ldm r6, {r7, r8} */
/* @0x1ab218 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab21c and r8, r9, r8 */
/* @0x1ab220 ldr r2, [r7, r8, lsl #3] */
/* @0x1ab224 add r3, r7, r8, lsl #3 */
/* @0x1ab228 cmp r2, #0 */
/* @0x1ab22c ldrne r2, [r3, #0x4] */
/* @0x1ab230 movne r1, #0 */
/* @0x1ab234 str r9, [r0, #0x8] */
/* @0x1ab238 str r4, [r0, #0xc] */
/* @0x1ab23c strne r2, [r0] */
/* @0x1ab240 streq r0, [r3, #0x4] */
/* @0x1ab244 strne r0, [r2, #0x4] */
/* @0x1ab248 strne r0, [r3, #0x4] */
/* @0x1ab24c ldr r3, [r6, #0x8] */
/* @0x1ab250 streq r0, [r7, r8, lsl #3] */
/* @0x1ab254 strne r1, [r0, #0x4] */
/* @0x1ab258 mov r1, r4 */
/* @0x1ab25c streq r2, [r0, #0x4] */
/* @0x1ab260 add r3, r3, #1 */
/* @0x1ab264 streq r2, [r0] */
/* ── 层注册 + 碰撞 + 返回 ─────────────────────────────────
 *   CLayerManager::AddInstance(room, inst)（0x1c5d18）→ CollisionInsert(inst)（0x1cc494）
 *   → r0 = inst 返回。★ 这条路径完全不碰 room+0xc4/+0xc8 两个暂存数组。
 */

/* @0x1ab268 mov r0, r5 */
/* @0x1ab26c str r3, [r6, #0x8] */
/* @0x1ab270 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1ab274 mov r0, r4 */
/* @0x1ab278 bl 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ab27c mov r0, r4 */
/* @0x1ab280 add sp, sp, #12 */
/* @0x1ab284 pop {r4, r5, r6, r7, r8, r9, pc} */
/* ── 前插档（cur+0x184 ≤ inst+0x180）：插在 cur 之前 ──
 *   cur->prev == 0（cur 就是头）→ inst->next = cur、cur->prev = inst、room+0x84 = inst、
 *                                  inst->prev = 0（r2 == 0 直接复用）；
 *   否则                         → inst->prev = cur->prev、inst->next = cur、
 *                                  cur->prev->next = inst、cur->prev = inst。
 *   两路末尾都写 inst+0x184 = inst+0x180（1ab2b4）。
 */

/* @0x1ab288 ldr r2, [r3, #0x178] */
/* @0x1ab28c cmp r2, #0 */
/* @0x1ab290 streq r3, [r4, #0x17c] */
/* @0x1ab294 strne r2, [r4, #0x178] */
/* @0x1ab298 ldrne r2, [r3, #0x178] */
/* @0x1ab29c streq r4, [r3, #0x178] */
/* @0x1ab2a0 strne r3, [r4, #0x17c] */
/* @0x1ab2a4 streq r4, [r5, #0x84] */
/* @0x1ab2a8 strne r4, [r2, #0x17c] */
/* @0x1ab2ac streq r2, [r4, #0x178] */
/* @0x1ab2b0 strne r4, [r3, #0x178] */
/* @0x1ab2b4 vstr s14, [r4, #388] */
/* @0x1ab2b8 b 0x1ab1f4 <_ZN5CRoom11AddInstanceEffi+0xb0> */
/* ── 空链档（head == 0）：head = tail = inst；+0x184 = +0x180；next = prev = 0 ──
 *   这里用的 r3 就是 cmp 之后的那个 0。
 */

/* @0x1ab2bc ldr r2, [r4, #0x180] */
/* @0x1ab2c0 str r4, [r5, #0x84] */
/* @0x1ab2c4 str r4, [r5, #0x80] */
/* @0x1ab2c8 str r2, [r4, #0x184] */
/* @0x1ab2cc str r3, [r4, #0x17c] */
/* @0x1ab2d0 str r3, [r4, #0x178] */
/* @0x1ab2d4 b 0x1ab1f4 <_ZN5CRoom11AddInstanceEffi+0xb0> */
/* ── literal pool（3 字）─────────────────────────────────
 *   1ab2d8 = 0x002456c0  → pc 1ab154 + 0x2456c0 = 0x3f0814 = &room_maxid
 *   1ab2dc = 0x00242a40  → pc 1ab20c + 0x242a40 = 0x3edc4c = &ms_ID2InstanceE
 *   1ab2e0 = 0x001a1aa0  → pc 1ab214 + 0x1a1aa0 = 0x34ccb4 = "…/Platform/Hash.h"
 */

/* @0x1ab2d8 eoreq r5, r4, r0, asr #13 */
/* @0x1ab2dc eoreq r2, r4, r0, asr #20 */
/* @0x1ab2e0 andseq r1, r10, r0, lsr #21 */
/* ══════════════════════════════════════════════════════════════════
 * 3) AddInstance(float x, float y, int depth, int objindex) —— 显式 depth
 * ══════════════════════════════════════════════════════════════════ */

/* ── 入口：r10 = depth（r3）、r7 = objindex（[sp+0x28]，第 4 个值参在栈上）──
 *   ★ 参数位次的坑：3 参版第 3 个 int 是 objindex；本版第 3 个是 **depth**，
 *     第 4 个（栈上）才是 objindex。唯一调用点 Command_Create_Depth(int obj, float x, float y,
 *     int depth) 0x1c98d4 在 0x1c990c-0x1c9914 摆参：r1 = x、r2 = y、r3 = depth、[sp] = obj。
 *   [sp+0x28] = 入口 sp（push 32 B + sub 8 B = 40 = 0x28）。
 */

/* @0x1ab2e4 ldr r12, [pc, #0x19c] */
/* @0x1ab2e8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ab2ec ldr r12, [pc, r12] */
/* @0x1ab2f0 sub sp, sp, #8 */
/* @0x1ab2f4 mov r5, r0 */
/* @0x1ab2f8 ldr r6, [r12] */
/* @0x1ab2fc mov r0, #432 */
/* @0x1ab300 mov r10, r3 */
/* @0x1ab304 mov r9, r1 */
/* ── 取第 4 值参：r7 = [sp+0x28] = objindex（本函数的「第 5 个」寄存器落点）──
 *   depth 在 r10 = r3，稍后 vcvt.f32.s32 成 float。
 */

/* @0x1ab308 ldr r7, [sp, #0x28] */
/* @0x1ab30c mov r8, r2 */
/* @0x1ab310 add r6, r6, #1 */
/* @0x1ab314 str r6, [r12] */
/* @0x1ab318 bl 0x27c524 <_Znwj> */
/* @0x1ab31c mov r12, #1 */
/* ── new(432) + C2(x, y, id, objindex, true)：与 3 参版同形 ──
 *   注意 ctor 先按对象默认 depth 初始化，随后 1ab33c-1ab34c 用实参覆写。
 */

/* @0x1ab320 mov r3, r6 */
/* @0x1ab324 mov r2, r8 */
/* @0x1ab328 mov r1, r9 */
/* @0x1ab32c str r12, [sp, #0x4] */
/* @0x1ab330 str r7, [sp] */
/* @0x1ab334 mov r4, r0 */
/* @0x1ab338 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* ── depth 覆写（本版唯一的上半身差异之一）─────────────
 *   vmov s14,r10 → vcvt.f32.s32 s15,s14 → vstr s15,[inst+0x180]
 *   位置在 **C2 之后、CreatePhysicsBody 之前**：物理体按覆写后的 depth 建立。
 */

/* @0x1ab33c vmov s14, r10 */
/* @0x1ab340 mov r0, r4 */
/* @0x1ab344 mov r1, r5 */
/* @0x1ab348 vcvt.f32.s32 s15, s14 */
/* @0x1ab34c vstr s15, [r4, #384] */
/* ── CreatePhysicsBody(room) 之后进 A 链 ──
 *   1ab354 起与 3 参版逐条同构（同偏移、同分支、同 vcmpe/bls 判据）：count 无条件 +1 →
 *   空链 / 前插 / 尾插 → 哈希桶尾插入 → CLayerManager::AddInstance → CollisionInsert。
 */

/* @0x1ab350 bl 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
/* @0x1ab354 ldr r3, [r5, #0x84] */
/* @0x1ab358 ldr r2, [r5, #0x88] */
/* @0x1ab35c cmp r3, #0 */
/* @0x1ab360 vldrne s14, [r4, #384] */
/* @0x1ab364 add r2, r2, #1 */
/* @0x1ab368 str r2, [r5, #0x88] */
/* @0x1ab36c beq 0x1ab46c <_ZN5CRoom11AddInstanceEffii+0x188> */
/* @0x1ab370 vldr s15, [r3, #388] */
/* @0x1ab374 vcmpe.f32 s15, s14 */
/* @0x1ab378 vmrs APSR_nzcv, fpscr */
/* @0x1ab37c bls 0x1ab438 <_ZN5CRoom11AddInstanceEffii+0x154> */
/* @0x1ab380 ldr r3, [r3, #0x17c] */
/* @0x1ab384 cmp r3, #0 */
/* @0x1ab388 bne 0x1ab370 <_ZN5CRoom11AddInstanceEffii+0x8c> */
/* @0x1ab38c ldr r2, [r5, #0x80] */
/* @0x1ab390 vstr s14, [r4, #388] */
/* @0x1ab394 str r4, [r2, #0x17c] */
/* @0x1ab398 str r2, [r4, #0x178] */
/* @0x1ab39c str r4, [r5, #0x80] */
/* @0x1ab3a0 str r3, [r4, #0x17c] */
/* @0x1ab3a4 ldr r6, [pc, #0xe0] */
/* @0x1ab3a8 movw r2, #0x132 */
/* @0x1ab3ac ldr r1, [pc, #0xdc] */
/* @0x1ab3b0 mov r3, #1 */
/* @0x1ab3b4 ldr r6, [pc, r6] */
/* @0x1ab3b8 mov r0, #16 */
/* @0x1ab3bc add r1, pc, r1 */
/* @0x1ab3c0 ldr r9, [r4, #0x78] */
/* @0x1ab3c4 ldm r6, {r7, r8} */
/* @0x1ab3c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab3cc and r8, r9, r8 */
/* @0x1ab3d0 ldr r2, [r7, r8, lsl #3] */
/* @0x1ab3d4 add r3, r7, r8, lsl #3 */
/* @0x1ab3d8 cmp r2, #0 */
/* @0x1ab3dc ldrne r2, [r3, #0x4] */
/* @0x1ab3e0 movne r1, #0 */
/* @0x1ab3e4 str r9, [r0, #0x8] */
/* @0x1ab3e8 str r4, [r0, #0xc] */
/* @0x1ab3ec strne r2, [r0] */
/* @0x1ab3f0 streq r0, [r3, #0x4] */
/* @0x1ab3f4 strne r0, [r2, #0x4] */
/* @0x1ab3f8 strne r0, [r3, #0x4] */
/* @0x1ab3fc ldr r3, [r6, #0x8] */
/* @0x1ab400 streq r0, [r7, r8, lsl #3] */
/* @0x1ab404 strne r1, [r0, #0x4] */
/* @0x1ab408 mov r1, r4 */
/* @0x1ab40c streq r2, [r0, #0x4] */
/* @0x1ab410 add r3, r3, #1 */
/* @0x1ab414 streq r2, [r0] */
/* @0x1ab418 mov r0, r5 */
/* @0x1ab41c str r3, [r6, #0x8] */
/* @0x1ab420 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1ab424 mov r0, r4 */
/* @0x1ab428 bl 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ab42c mov r0, r4 */
/* @0x1ab430 add sp, sp, #8 */
/* @0x1ab434 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ── 前插档：与 3 参版 1ab288 同构（cur->prev 是否为空决定要不要改 room+0x84）──
 *   末尾 1ab464 写 inst+0x184 = inst+0x180。
 */

/* @0x1ab438 ldr r2, [r3, #0x178] */
/* @0x1ab43c cmp r2, #0 */
/* @0x1ab440 streq r3, [r4, #0x17c] */
/* @0x1ab444 strne r2, [r4, #0x178] */
/* @0x1ab448 ldrne r2, [r3, #0x178] */
/* @0x1ab44c streq r4, [r3, #0x178] */
/* @0x1ab450 strne r3, [r4, #0x17c] */
/* @0x1ab454 streq r4, [r5, #0x84] */
/* @0x1ab458 strne r4, [r2, #0x17c] */
/* @0x1ab45c streq r2, [r4, #0x178] */
/* @0x1ab460 strne r4, [r3, #0x178] */
/* @0x1ab464 vstr s14, [r4, #388] */
/* @0x1ab468 b 0x1ab3a4 <_ZN5CRoom11AddInstanceEffii+0xc0> */
/* ── 空链档：head = tail = inst、+0x184 = +0x180、两链域清零 ──
 *   与 3 参版 1ab2bc 同构。
 */

/* @0x1ab46c ldr r2, [r4, #0x180] */
/* @0x1ab470 str r4, [r5, #0x84] */
/* @0x1ab474 str r4, [r5, #0x80] */
/* @0x1ab478 str r2, [r4, #0x184] */
/* @0x1ab47c str r3, [r4, #0x17c] */
/* @0x1ab480 str r3, [r4, #0x178] */
/* @0x1ab484 b 0x1ab3a4 <_ZN5CRoom11AddInstanceEffii+0xc0> */
/* ── literal pool（3 字）─────────────────────────────────
 *   1ab488 = 0x00245520  → pc 1ab2f4 + 0x245520 = 0x3f0814 = &room_maxid
 *   1ab48c = 0x00242890  → pc 1ab3bc + 0x242890 = 0x3edc4c = &ms_ID2InstanceE
 *   1ab490 = 0x001a18f0  → pc 1ab3c4 + 0x1a18f0 = 0x34ccb4 = "…/Platform/Hash.h"
 */

/* @0x1ab488 eoreq r5, r4, r0, lsr #10 */
/* @0x1ab48c mlaeq r4, r0, r8, r2 */
/* @0x1ab490 ldrsheq r1, [r10], -r0 */
/* ══════════════════════════════════════════════════════════════════
 * 4) AddInstance(float x, float y, CLayer* layer, int objindex) —— 指定层
 * ══════════════════════════════════════════════════════════════════ */

/* ── 入口：r7 = layer（r3）、[sp+0x28] = objindex ──
 *   subs r7,r3,#0 顺手把 layer == 0 的判据置起来：**layer 为空直接返回 0**，
 *   连 room_maxid 都不递增（分支在 ++ 之前，1ab4ac → 1ab640）。
 *   调用点：Command_Create_Layer 0x1c9980（0x1c99d0）与
 *           Command_Create_Layer(int,float,float,char const*) 0x1c9a74（0x1c9ac4）。
 */

/* @0x1ab494 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ab498 subs r7, r3, #0 */
/* @0x1ab49c sub sp, sp, #8 */
/* @0x1ab4a0 mov r5, r0 */
/* @0x1ab4a4 mov r9, r1 */
/* @0x1ab4a8 mov r8, r2 */
/* ── layer == 0 → 1ab640：r0 = r7 = 0，跳 1ab5e8 恢复现场返回 0 ──
 *   ⇒ 空层不建对象、不占 id、不插链。本卡唯一「静默失败」的入口。
 */

/* @0x1ab4ac beq 0x1ab640 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x1ac> */
/* ── 非空层：id = ++room_maxid（池字 1ab648 → 0x3f0814）→ new(432) → C2(x,y,id,obj,true) ──
 *   objindex 来自 [sp+0x28]（1ab4cc），与 4 参版同一个栈位。
 */

/* @0x1ab4b0 ldr r12, [pc, #0x190] */
/* @0x1ab4b4 mov r0, #432 */
/* @0x1ab4b8 ldr r12, [pc, r12] */
/* @0x1ab4bc ldr r6, [r12] */
/* @0x1ab4c0 add r6, r6, #1 */
/* @0x1ab4c4 str r6, [r12] */
/* @0x1ab4c8 bl 0x27c524 <_Znwj> */
/* @0x1ab4cc ldr r2, [sp, #0x28] */
/* @0x1ab4d0 mov r12, #1 */
/* @0x1ab4d4 mov r3, r6 */
/* @0x1ab4d8 str r12, [sp, #0x4] */
/* @0x1ab4dc mov r1, r9 */
/* @0x1ab4e0 str r2, [sp] */
/* @0x1ab4e4 mov r2, r8 */
/* @0x1ab4e8 mov r4, r0 */
/* @0x1ab4ec bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* ── depth 来自层：vldr s14,[layer+0x04] → vcvt.f32.s32 → inst+0x180 ──
 *   ★ 即 CLayer+0x04 是一个 int，被当作层的 depth 用（字段名未证，open 2）。
 *   位置同样在 C2 之后、CreatePhysicsBody 之前。
 */

/* @0x1ab4f0 vldr s14, [r7, #4] */
/* @0x1ab4f4 vcvt.f32.s32 s15, s14 */
/* @0x1ab4f8 mov r0, r4 */
/* @0x1ab4fc mov r1, r5 */
/* @0x1ab500 vstr s15, [r4, #384] */
/* ── CreatePhysicsBody 之后进 A 链（与其它重载同构）──
 *   唯一差别落在最后一步：这里调 CLayerManager::AddInstanceToLayer(room, layer, inst)
 *   （0x1c5a38），而不是 AddInstance(room, inst)。
 */

/* @0x1ab504 bl 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
/* @0x1ab508 ldr r12, [r5, #0x84] */
/* @0x1ab50c ldr r3, [r5, #0x88] */
/* @0x1ab510 cmp r12, #0 */
/* @0x1ab514 vldrne s14, [r4, #384] */
/* @0x1ab518 add r3, r3, #1 */
/* @0x1ab51c str r3, [r5, #0x88] */
/* @0x1ab520 beq 0x1ab624 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x190> */
/* @0x1ab524 vldr s15, [r12, #388] */
/* @0x1ab528 vcmpe.f32 s15, s14 */
/* @0x1ab52c vmrs APSR_nzcv, fpscr */
/* @0x1ab530 bls 0x1ab5f0 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x15c> */
/* @0x1ab534 ldr r12, [r12, #0x17c] */
/* @0x1ab538 cmp r12, #0 */
/* @0x1ab53c bne 0x1ab524 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x90> */
/* @0x1ab540 ldr r3, [r5, #0x80] */
/* @0x1ab544 vstr s14, [r4, #388] */
/* @0x1ab548 str r4, [r3, #0x17c] */
/* @0x1ab54c str r3, [r4, #0x178] */
/* @0x1ab550 str r4, [r5, #0x80] */
/* @0x1ab554 str r12, [r4, #0x17c] */
/* @0x1ab558 ldr r6, [pc, #0xec] */
/* @0x1ab55c movw r2, #0x132 */
/* @0x1ab560 ldr r1, [pc, #0xe8] */
/* @0x1ab564 mov r3, #1 */
/* @0x1ab568 ldr r6, [pc, r6] */
/* @0x1ab56c mov r0, #16 */
/* @0x1ab570 add r1, pc, r1 */
/* @0x1ab574 ldr r10, [r4, #0x78] */
/* @0x1ab578 ldm r6, {r8, r9} */
/* @0x1ab57c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab580 and r9, r10, r9 */
/* @0x1ab584 ldr r2, [r8, r9, lsl #3] */
/* @0x1ab588 add r3, r8, r9, lsl #3 */
/* @0x1ab58c cmp r2, #0 */
/* @0x1ab590 ldrne r2, [r3, #0x4] */
/* @0x1ab594 movne r1, #0 */
/* @0x1ab598 str r10, [r0, #0x8] */
/* @0x1ab59c strne r2, [r0] */
/* @0x1ab5a0 str r4, [r0, #0xc] */
/* @0x1ab5a4 streq r0, [r3, #0x4] */
/* @0x1ab5a8 strne r0, [r2, #0x4] */
/* @0x1ab5ac strne r0, [r3, #0x4] */
/* @0x1ab5b0 ldr r3, [r6, #0x8] */
/* @0x1ab5b4 streq r0, [r8, r9, lsl #3] */
/* @0x1ab5b8 strne r1, [r0, #0x4] */
/* ── 层内注册：CLayerManager::AddInstanceToLayer(room=this, layer=r7, inst) ──
 *   之后 CollisionInsert(inst)、返回 inst。★ 仍然不碰 room+0xc4/+0xc8。
 */

/* @0x1ab5bc mov r1, r7 */
/* @0x1ab5c0 streq r2, [r0, #0x4] */
/* @0x1ab5c4 add r3, r3, #1 */
/* @0x1ab5c8 streq r2, [r0] */
/* @0x1ab5cc mov r0, r5 */
/* @0x1ab5d0 mov r2, r4 */
/* @0x1ab5d4 str r3, [r6, #0x8] */
/* @0x1ab5d8 bl 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance> */
/* @0x1ab5dc mov r0, r4 */
/* @0x1ab5e0 bl 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ab5e4 mov r0, r4 */
/* @0x1ab5e8 add sp, sp, #8 */
/* @0x1ab5ec pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ── 前插档：与 3 参版 1ab288 同构，但寄存器分配不同（cur 在 r12，prev 在 r3）──
 *   末尾 1ab61c 写 inst+0x184 = inst+0x180。
 */

/* @0x1ab5f0 ldr r3, [r12, #0x178] */
/* @0x1ab5f4 cmp r3, #0 */
/* @0x1ab5f8 streq r12, [r4, #0x17c] */
/* @0x1ab5fc strne r3, [r4, #0x178] */
/* @0x1ab600 ldrne r3, [r12, #0x178] */
/* @0x1ab604 streq r4, [r12, #0x178] */
/* @0x1ab608 strne r12, [r4, #0x17c] */
/* @0x1ab60c streq r4, [r5, #0x84] */
/* @0x1ab610 strne r4, [r3, #0x17c] */
/* @0x1ab614 streq r3, [r4, #0x178] */
/* @0x1ab618 strne r4, [r12, #0x178] */
/* @0x1ab61c vstr s14, [r4, #388] */
/* @0x1ab620 b 0x1ab558 <_ZN5CRoom11AddInstanceEffP6CLayeri+0xc4> */
/* ── 空链档：head = tail = inst、+0x184 = +0x180、两链域清零（r12 此时为 0）──
 */

/* @0x1ab624 ldr r3, [r4, #0x180] */
/* @0x1ab628 str r4, [r5, #0x84] */
/* @0x1ab62c str r4, [r5, #0x80] */
/* @0x1ab630 str r3, [r4, #0x184] */
/* @0x1ab634 str r12, [r4, #0x17c] */
/* @0x1ab638 str r12, [r4, #0x178] */
/* @0x1ab63c b 0x1ab558 <_ZN5CRoom11AddInstanceEffP6CLayeri+0xc4> */
/* ── layer == NULL 的出口：r0 = 0 → 1ab5e8 的 add sp/pop ──
 *   ⇒ 「层不存在就不创建」是**静默**的，没有错误回调、没有日志。
 */

/* @0x1ab640 mov r0, r7 */
/* @0x1ab644 b 0x1ab5e8 <_ZN5CRoom11AddInstanceEffP6CLayeri+0x154> */
/* ── literal pool（3 字）─────────────────────────────────
 *   1ab648 = 0x00245354  → pc 1ab4c0 + 0x245354 = 0x3f0814 = &room_maxid
 *   1ab64c = 0x002426dc  → pc 1ab570 + 0x2426dc = 0x3edc4c = &ms_ID2InstanceE
 *   1ab650 = 0x001a173c  → pc 1ab578 + 0x1a173c = 0x34ccb4 = "…/Platform/Hash.h"
 */

/* @0x1ab648 eoreq r5, r4, r4, asr r3 */
/* @0x1ab64c .word 0x002426dc */
/* @0x1ab650 andseq r1, r10, r12, lsr r7 */
/* ══════════════════════════════════════════════════════════════════
 * 5) AddInstance(CInstance* inst) —— 「对象已经存在」的挂链入口
 * ══════════════════════════════════════════════════════════════════ */

/* ── 入口：r4 = inst。不分配、不调 ctor、不建物理体 —— 只做四件事：
 *   ① A 链插入（含 count++）② id 哈希插入 ③ CLayerManager::AddInstance ④ 尾跳 CollisionInsert。
 *   id 取 inst+0x78，depth 取 inst+0x180（不覆写）；本函数是 5 个入口里唯一「只读对象、
 *   不改对象字段（除 +0x178/+0x17c/+0x184）」的一个。
 *   push {r3,...} 里的 r3 只是 8 B 对齐占位，本函数没有任何栈实参。
 *   ★ .text 内 **0** 个 b/bl 直呼点（其余三个重载分别 8/1/2 个），只能经函数指针/vtable/库外调用。
 */

/* @0x1ab654 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ab658 mov r6, r0 */
/* ── 读链头与计数：r3 = room+0x84（head）、r2 = room+0x88（count）──
 *   cmp r3,#0 之后：head 非空才在 1ab66c 读 inst+0x180（vldrne）；count 的 +1 与写回
 *   在 1ab670/1ab674，位于分支**之前** ⇒ 空链也计数。
 */

/* @0x1ab65c ldr r3, [r0, #0x84] */
/* @0x1ab660 mov r4, r1 */
/* @0x1ab664 ldr r2, [r0, #0x88] */
/* @0x1ab668 cmp r3, #0 */
/* ── head != 0 才加载新节点 depth（s14 = inst+0x180）──
 *   空链分支（1ab774）不读这里，而是把 +0x180 直接抄进 +0x184。
 */

/* @0x1ab66c vldrne s14, [r1, #384] */
/* @0x1ab670 add r2, r2, #1 */
/* @0x1ab674 str r2, [r0, #0x88] */
/* @0x1ab678 beq 0x1ab774 <_ZN5CRoom11AddInstanceEP9CInstance+0x120> */
/* ── 有序遍历：cur+0x184 vs inst+0x180，bls（≤）→ 1ab740 前插 ──
 *   与三个 float 重载逐字节同构（偏移相同，仅寄存器不同）；排序键是 cur 的**快照** +0x184。
 */

/* @0x1ab67c vldr s15, [r3, #388] */
/* @0x1ab680 vcmpe.f32 s15, s14 */
/* @0x1ab684 vmrs APSR_nzcv, fpscr */
/* @0x1ab688 bls 0x1ab740 <_ZN5CRoom11AddInstanceEP9CInstance+0xec> */
/* @0x1ab68c ldr r3, [r3, #0x17c] */
/* @0x1ab690 cmp r3, #0 */
/* @0x1ab694 bne 0x1ab67c <_ZN5CRoom11AddInstanceEP9CInstance+0x28> */
/* ── 尾插档：room+0x80 是尾指针 ──
 *   old_tail->next = inst；inst->prev = old_tail；room+0x80 = inst；inst->next = 0（r3）；
 *   同步写 inst+0x184 = s14（= inst+0x180）。
 */

/* @0x1ab698 ldr r2, [r6, #0x80] */
/* @0x1ab69c vstr s14, [r4, #388] */
/* @0x1ab6a0 str r4, [r2, #0x17c] */
/* @0x1ab6a4 str r2, [r4, #0x178] */
/* @0x1ab6a8 str r4, [r6, #0x80] */
/* @0x1ab6ac str r3, [r4, #0x17c] */
/* ── id 哈希插入（ms_ID2InstanceE）────────────────────────
 *   池字 1ab790 = 0x00242584 → pc 1ab6c8 + 0x242584 = 0x3edc4c；Alloc(16, Hash.h, 306, true)。
 *   节点 {prev@0, next@4, key@8, value@0xc}；桶 {head@0, tail@4}；
 *   空桶（cmp r1,#0 → eq）时 head = tail = node、两链域清零；否则插桶尾。
 *   末尾 [map+8] += 1（两条路径都走 1ab70c-1ab72c）。
 */

/* @0x1ab6b0 ldr r5, [pc, #0xd8] */
/* @0x1ab6b4 movw r2, #0x132 */
/* @0x1ab6b8 ldr r1, [pc, #0xd4] */
/* @0x1ab6bc mov r3, #1 */
/* @0x1ab6c0 ldr r5, [pc, r5] */
/* @0x1ab6c4 mov r0, #16 */
/* @0x1ab6c8 add r1, pc, r1 */
/* @0x1ab6cc ldr r9, [r4, #0x78] */
/* @0x1ab6d0 ldm r5, {r7, r8} */
/* @0x1ab6d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab6d8 and r8, r9, r8 */
/* @0x1ab6dc ldr r1, [r7, r8, lsl #3] */
/* @0x1ab6e0 add r2, r7, r8, lsl #3 */
/* @0x1ab6e4 cmp r1, #0 */
/* @0x1ab6e8 ldrne r1, [r2, #0x4] */
/* @0x1ab6ec mov r3, r0 */
/* @0x1ab6f0 str r9, [r0, #0x8] */
/* @0x1ab6f4 str r4, [r0, #0xc] */
/* @0x1ab6f8 movne r0, #0 */
/* @0x1ab6fc strne r1, [r3] */
/* @0x1ab700 strne r3, [r1, #0x4] */
/* @0x1ab704 strne r3, [r2, #0x4] */
/* @0x1ab708 strne r0, [r3, #0x4] */
/* @0x1ab70c ldr r3, [r5, #0x8] */
/* @0x1ab710 streq r0, [r2, #0x4] */
/* @0x1ab714 streq r0, [r7, r8, lsl #3] */
/* @0x1ab718 add r3, r3, #1 */
/* @0x1ab71c streq r1, [r0, #0x4] */
/* @0x1ab720 streq r1, [r0] */
/* ── 层注册 + 尾跳碰撞 ──────────────────────────────────
 *   r0 = room、r1 = inst → CLayerManager::AddInstance（0x1c5d18）；
 *   然后 pop 恢复现场、r0 = inst，用 **b**（不是 bl）跳到 CollisionInsert 0x1cc494
 *   ⇒ 真尾跳：CollisionInsert 的返回地址就是本函数调用者的返回地址，栈深度不变。
 */

/* @0x1ab724 mov r0, r6 */
/* @0x1ab728 mov r1, r4 */
/* @0x1ab72c str r3, [r5, #0x8] */
/* @0x1ab730 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1ab734 mov r0, r4 */
/* @0x1ab738 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ab73c b 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* ── 前插档（cur+0x184 ≤ inst+0x180）────────────────────
 *   cur->prev == 0 → inst->next = cur；cur->prev = inst；room+0x84 = inst；inst->prev = 0
 *   否则           → inst->prev = cur->prev；inst->next = cur；
 *                    cur->prev->next = inst；cur->prev = inst
 *   末尾 1ab76c 写 inst+0x184 = s14。
 */

/* @0x1ab740 ldr r2, [r3, #0x178] */
/* @0x1ab744 cmp r2, #0 */
/* @0x1ab748 streq r3, [r4, #0x17c] */
/* @0x1ab74c strne r2, [r4, #0x178] */
/* @0x1ab750 ldrne r2, [r3, #0x178] */
/* @0x1ab754 streq r4, [r3, #0x178] */
/* @0x1ab758 strne r3, [r4, #0x17c] */
/* @0x1ab75c streq r4, [r6, #0x84] */
/* @0x1ab760 strne r4, [r2, #0x17c] */
/* @0x1ab764 streq r2, [r4, #0x178] */
/* @0x1ab768 strne r4, [r3, #0x178] */
/* @0x1ab76c vstr s14, [r4, #388] */
/* @0x1ab770 b 0x1ab6b0 <_ZN5CRoom11AddInstanceEP9CInstance+0x5c> */
/* ── 空链档（head == 0）：head = tail = inst；+0x184 = +0x180；next = prev = 0 ──
 *   room+0x88 已经在 1ab670 加过 1，这里不重复计数。
 */

/* @0x1ab774 ldr r2, [r1, #0x180] */
/* @0x1ab778 str r1, [r6, #0x84] */
/* @0x1ab77c str r1, [r6, #0x80] */
/* @0x1ab780 str r2, [r1, #0x184] */
/* @0x1ab784 str r3, [r1, #0x17c] */
/* @0x1ab788 str r3, [r1, #0x178] */
/* @0x1ab78c b 0x1ab6b0 <_ZN5CRoom11AddInstanceEP9CInstance+0x5c> */
/* ── literal pool（2 字）─────────────────────────────────
 *   1ab790 = 0x00242584  → pc 1ab6c8 + 0x242584 = 0x3edc4c = &ms_ID2InstanceE
 *   1ab794 = 0x001a15e4  → pc 1ab6d0 + 0x1a15e4 = 0x34ccb4 = "…/Platform/Hash.h"
 */

/* @0x1ab790 eoreq r2, r4, r4, lsl #11 */
/* @0x1ab794 andseq r1, r10, r4, ror #11 */
/* ══════════════════════════════════════════════════════════════════
 * 收尾：5 个入口的公共下半身（读这张卡只需要记住这一段）
 * ══════════════════════════════════════════════════════════════════
 *   除 AddInstanceToStorage 外，四个重载在「链插入」这一段是同一份代码的四份副本：
 *     +0x88 += 1 → 空链？(head/tail = inst, +0x184 = +0x180)
 *                → 否则从 head 沿 +0x17c 走，停在第一个 (cur+0x184 ≤ inst+0x180) 之前
 *                  （走到 0 就挂尾）；两路都写 +0x184 = +0x180
 *     → 哈希桶尾插入（key = id, value = inst）→ CLayerManager → CollisionInsert。
 *   唯一的语义分歧点是「id / depth / objindex 从哪来」和「注册到默认层还是指定层」。
 *   交叉印证：CRoom::UpdateActive 0x1abd9c 用同一套三档把实例在 A/B 两链间搬运，
 *   所以 A 链的排序契约（depth 降序、插入用快照 +0x184）在本卡之外还有第二处实现。
 */

