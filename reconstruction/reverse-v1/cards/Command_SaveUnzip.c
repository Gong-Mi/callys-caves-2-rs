/* cally 逆向卡：存档/解压/反弹三命令（原版 libyoyo.so，armv7）—— 一卡三节
 * @func 三节 = index 的三个分组，逐节自带 @func 头与逐条锚点：
 *   §1 0x1d07c8 Command_SaveGame(int)   size 1552  388 锚点（361 条指令 + 27 个池字 0x1d0d6c..0x1d0dd4）
 *   §2 0x1ca040 Command_Unzip(...)      size 784   196 锚点（186 条指令 + 10 个池字 0x1ca328..0x1ca34c）
 *   §3 0x1cafa0 Command_Bounce(...)     size 660   165 锚点（163 条指令 + 2 个池字 0x1cb22c/0x1cb230）
 * 总账: 749 锚点 = 710 条指令 + 39 个池字，与 asm/index-Command_SaveUnzip_all.tsv 逐字一致
 *       （自校验：index=749 card=749 missing=0 extra=0 mismatch=0 RESULT EXACT；卡内锚点顺序 = index 行序
 *         §1→§2→§3，三节地址互不重叠，任意一行 index 都能与卡内同序号锚点直接对拍）
 * 级别: 正文 ×3。三节的控制流、实参、全局槽、返回路径都逐条解到；有三处旁证不在本索引，只给地址与调用
 *       边界、不越权下结论：①IBuffer 写入器（buf->vt+8）的类型码语义 —— 本卡用同文件的
 *       GlobalState_DeSerialise 0x1d039c 的读回码反证 6=int32、用 RValue::Serialise 0xcf47c 反证 9=8 字节
 *       real；②minizip（zip_open_buff/zip_stat/…）内部；③Command_IsFree 0x1cab94 / Command_IsEmpty
 *       0x1caa1c 的判据（本卡只证「非 0 = 空/自由」，内部见 Builtins_Misc2 卡）。
 * 锚点来源: asm_index.py 从二进制直出，本卡未手写转录；池字保留 objdump 的「像指令」写法
 *       （§1 的 1d0dcc/1d0dd0/1d0dd4 印成 mulseq/ldrsbeq sp,[r5],-lr，§2 的 1ca334..1ca344 印成 andseq，
 *        §3 的 1cb22c/1cb230 印成 ldrdmi/teqmi），逐处标「非指令」。
 *
 * ── 三节的关系（本卡正面回答）────────────────────────────────────────────────
 *   SaveGame 与 Unzip 都是 IBuffer 消费者，用法相反：
 *     SaveGame 收**别人给的句柄**（int），只往里写，不负责开/关/落盘（落盘在 char* 包装层）；
 *     Unzip 自己 operator new(64) 造缓冲、IBuffer::Load 把整个 zip 读进来、结束时 vtable+4 释放。
 *   Bounce 不碰缓冲，只碰 CInstance 的运动学字段（+0xb4/+0xb8/+0xc4/+0xc8/+0xcc/+0xd0/+0xe0/+0xe4）。
 *   §1/§2 共用 PIC 锚 0x3f1c58（1d07dc / 1ca060）；§3 不用 GOT，只有实例字段与两个 pc 池常量。
 *
 * ── 逐条锚点（3 节，749 条）────────────────────────────────────────────────────
 */

/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 1 · Command_SaveGame(int)（整局状态 → 一个 IBuffer）
 * @func 0x1d07c8 0x1d0dd8  size 1552  388 锚点（361 条指令 + 27 个池字 0x1d0d6c..0x1d0dd4）
 * 符号: _Z16Command_SaveGamei → int Command_SaveGame(int bufferId)
 * 位置: index 第 1 组。函数体 0x1d07c8..0x1d0d68（361 条），其后 27 个池字全是 pc 相对加数/串偏移。
 * 调用者: 全 .text 精确 1 处 bl —— Command_SaveGame(char const*) 0x1d1468 的 0x1d149c；
 *         再上一层 F_ActionSaveGame 0x13ec54 尾跳 char* 版（0x13ec68）。
 * 同层: GetIBuffer 0xc6720、IBuffer::Write(char const*) 0xcddb8、Variable_Global_Serialise 0x1f4a28、
 *       CCameraManager::Serialize 0x16e874、CRoom::Serialise 0x1aa228、VirtualKeys_Serialise 0x18c698、
 *       Debug_AddTag 0x29c3ec、GlobalState_DeSerialise 0x1d039c（读回方）、Check_LoadGameState 0x1d0ed4
 * 一句话: 按固定次序把 1 个版本常量 + 17 条全局格（含 3 段串、1 段 8 字节 real）+ 4 个委派块写进调用方
 *         给的 IBuffer；除了「句柄查不到缓冲」之外没有失败出口，所有写调用的返回值一律不读，恒返 1。
 * ═══════════════════════════════════════════════════════════════════════════
 */

/* ── 语义草案 ─────────────────────────────────────────────────────────────
 *   int Command_SaveGame(int bufferId) {
 *     IBuffer* b = GetIBuffer(bufferId);              // 1d07cc → 0xc6720
 *     if (!b) return 0;                               // 1d07d8/1d07dc → 1d0d34
 *     W(6, 851.0);                                    // 1d07e8..1d080c  版本常量
 *     W(6, *(int*)0x542974);                          // 1d0810..1d0848  版本格（读回侧原样存回同一格）
 *     W(6, *(int*)0x542958);                          // 当前房间号
 *     W(6, *(int*)0x542954);                          // New_Room / 步进退出码
 *     W(6, *(int*)0x542950);                          // Transition_Kind
 *     W(6, *(int*)0x54294c);
 *     W(6, *(uint8_t*)0x542949);
 *     W(6, *(uint8_t*)0x542948);
 *     p = *(void**)0x542944; b->Write(p ? *(char**)p : "");   // 1d09b4..1d09d4
 *     W(6, *(int*)0x542940);
 *     W(6, *(uint8_t*)0x54293c);
 *     q = *(void**)0x542938; b->Write(q ? *(char**)q : "");   // 1d0a50..1d0a70
 *     W(9, *(uint64_t*)0x542930);                     // 8 字节原样（不经 vcvt）
 *     W(6, *(uint8_t*)0x542928);
 *     b->Write(*(char**)(*(void**)0x542924));         // 1d0ae4..1d0af8，无空判
 *     W(6, *(int*)0x542918);                          // GUI 精灵号
 *     W(6, *(int*)0x542914);                          // 步计数
 *     W(6, *(uint8_t*)0x542910);                      // Draw 段闸门
 *     Variable_Global_Serialise(b);                   // 1d0bb0
 *     CCameraManager::Serialize(&g_CM, b);            // 1d0bb8 → 0x48f78c
 *     W(6, *(int*)0x542990);                          // Run_Room_List.count
 *     W(6, *(int*)0x54255c);                          // room_maxid
 *     W(6, *(int*)0x542558);                          // room_maxtileid
 *     for (i = 0; i < count; i++) {                   // 1d0c78..1d0cf8
 *        W(6, rooms[i] != NULL);                      //   存在位
 *        if (rooms[i]) CRoom::Serialise(rooms[i], b); //   房间块（0x1aa228）
 *     }
 *     VirtualKeys_Serialise(b);                       // 1d0cfc → 0x18c698
 *     if (g_isZeus(0x5428e8) && *(void**)0x544c38 == 0)
 *        Debug_AddTag(2, "Save game");                // 1d0d3c..1d0d50，仍返 1
 *     return 1;                                       // 1d0d2c / 1d0d4c
 *   }
 *
 * ── 帧与实参 ─────────────────────────────────────────────────────────────
 *   push {r3,r4,r5,r6,r7,r8,r9,r10,r11,lr}（10 字 = 40 B），**没有 sub sp**：不需要栈上暂存。
 *   实参只有一个 int，直接进 GetIBuffer（1d07cc），返回的 IBuffer* 进 r6 ⇒ 这个 int 是**缓冲句柄号**，
 *   不是存档槽号、也不是文件名。硬证据在 char* 版：0x1d1468 先 CreateBuffer(0x20000,1,1) 拿句柄，
 *   再把句柄原样当 r0 调本函数（1d1494 → 1d149c），写完从同一句柄取 [buf+0xc]/[buf+0x1c] 落盘。
 *   寄存器分工：r7 = PIC 锚 0x3f1c58（1d07d0/1d07d4）；r8 = buf+0x2c（RValue 数据槽，1d07e4）；
 *   r9 = 0（前半的零，1d07e8 起）→ 1d0bdc 起改当房间表指针；r10 = 0（后半的零，1d0a6c 起）→ 1d0c78 起
 *   当房间循环下标；r6 = buf 全程不变。
 *
 * ── 写协议（与 CRoom::Serialise 完全同一条）──────────────────────────────
 *   调用形状：r0 = buf、r1 = 类型码、r2 = buf+0x2c，blx [buf->vt+8]；tag（buf+0x38）每次先清 0；
 *   数值先摊成 8 字节到 +0x2c（低字，vstr s14）+ +0x30（高字）：
 *     int  → vmov s15,r4; vcvt.f64.s32 d7,s15; vmov r4,r5,d7; vstr s14,[r6,#44]; str r5,[r6,#0x30]
 *     byte → 同上但 vcvt.f64.u32（1d0960/1d099c/1d0a38/1d0ac8/1d0b98 五处）
 *   类型码只出现两种：**6**（19 个 blx 里的 18 个）与 **9**（1d0a7c，唯一一处，8 字节原样搬）。
 *   字符串不走虚表：直调 IBuffer::Write(char const*) 0xcddb8（1d09d0、1d0a70、1d0af8 三处）。
 *   码 6 = int32 的反证：同文件 GlobalState_DeSerialise 0x1d039c 用同一个码 6 读回（0x1d03a8/0x1d03bc），
 *     再 YYGetInt32（0x1d03c4）取值、movw 0x353 比较（0x1d03d4/0x1d03dc）。
 *   码 9 = 8 字节 real 的反证：RValue::Serialise 0xcf47c 的 real 分支（0xcf544）正是 r1=9 + 两字原样搬。
 *   ⇒ 第一段那 8 字节槽（double 851.0）经码 6 落盘后是 **int32 851 = 0x353**，与读回侧的 movw 0x353
 *     对得上 —— 这是把首段判成「版本」而不是「浮点 851.0」的全部依据。
 *
 * ── 段序总表（写侧 1d07c8 起；读回侧 = GlobalState_DeSerialise 0x1d039c 的同位指令）──────────
 *   #   写点区间         源（写什么）                                码  读回点（同序，一一对应）
 *   1   1d07e8..1d080c   常量 851.0 → int32                          6   1d03a8..1d03e0（存 0x3f5118，比 0x353）
 *   2   1d0810..1d0848   *(int*)0x542974（版本格的当前值）           6   1d0418 → 存回 0x542974
 *   3   1d084c..1d0884   *(int*)0x542958  当前房间号                 6   1d0448 → 0x542958
 *   4   1d0888..1d08c0   *(int*)0x542954  New_Room / 退出码          6   1d0478 → 0x542954
 *   5   1d08c4..1d08fc   *(int*)0x542950  Transition_Kind            6   1d04a8 → 0x542950
 *   6   1d0900..1d0938   *(int*)0x54294c                             6   1d04d8 → 0x54294c
 *   7   1d093c..1d0974   *(uint8_t*)0x542949                         6   1d0508 → 0x542949
 *   8   1d0978..1d09b0   *(uint8_t*)0x542948                         6   1d0538 → 0x542948
 *   9   1d09b4..1d09d4   串：p=*(void**)0x542944 → *(char**)p，空则 ""  —  1d0574 → 0x542944
 *  10   1d09d8..1d0a10   *(int*)0x542940                             6   1d05b4 → 0x542940
 *  11   1d0a14..1d0a4c   *(uint8_t*)0x54293c                         6   1d05e4 → 0x54293c
 *  12   1d0a50..1d0a70   串：q=*(void**)0x542938 → *(char**)q，空则 ""  —  1d0620 → 0x542938
 *  13   1d0a74..1d0aa4   8 字节：0x542930/+0x542934 原样               9   1d0650 → 0x542930
 *  14   1d0aa8..1d0ae0   *(uint8_t*)0x542928                         6   1d0688 → 0x542928
 *  15   1d0ae4..1d0af8   串：**(char***)0x542924（两次解引用，无空判）    —  1d06c4 → 0x542924
 *  16   1d0afc..1d0b34   *(int*)0x542918  GUI 精灵号                 6   1d0704 → 0x542918
 *  17   1d0b38..1d0b70   *(int*)0x542914  步计数                     6   1d0734 → 0x542914
 *  18   1d0b74..1d0bac   *(uint8_t*)0x542910  Draw 闸门               6   1d0764 → 0x542910
 *  A    1d0bb0          Variable_Global_Serialise(b)                 —   读回方 0x1d0f44
 *  B    1d0bb8          CCameraManager::Serialize(&g_CM, b)          —   读回方 0x1d0f5c
 *  C    1d0bc8..1d0cf8  房间表：count → maxid → maxtileid → 每房 {bool, CRoom::Serialise}
 *                                                                    —   读回方 0x1d1010..（count 进局部、
 *                                                                        0x1d1060 → maxid、0x1d1090 → maxtileid、
 *                                                                        0x1d1094 → 房间表指针后逐房）
 *  D    1d0cfc          VirtualKeys_Serialise(b)                     —   读回方 0x1d1384
 *   ★ 18 段 ↔ 读回侧 18 次读（1 次 temp + 17 次 GOT 落点）：写侧 18 个 vtable 写点/串写点与读侧
 *     1d03a8 + 1d0418..1d0764 逐个同序对上 —— 段序不是猜的，是两侧同序对上了。
 *   ★ 读回侧处处查返回值（GlobalState_DeSerialise 版本不等就 0x1d03ec 返 0；Check_LoadGameState
 *     0x1d0ed4 对 Variable_Global/Camera/房间/VirtualKeys 逐个 beq 失败出口），写侧一处不查 —— 这个
 *     不对称是真的，且是「写失败不可见」的根因。
 *
 * ── 失败路径（逐条，全部落锚）────────────────────────────────────────────
 *   ① 句柄查不到缓冲：1d07cc bl GetIBuffer → subs r6,r0,#0（1d07d8）→ beq 1d0d34 → mov r0,r6（=0）返回。
 *      这是**唯一**会让返回值变 0 的路径，且此时一个字节都没写。
 *   ② 字符串源为空：1d09c0 cmp r3,r9 + 1d09c4 beq 1d0d54 → r1 = 空串（0x32eb3e 是 .rodata 里紧贴
 *      "libGLESv2.so" 前的一串 0，按 C 串即 ""）→ 跳回 1d09cc 继续写。第二处同构（1d0a50 → 1d0d60）。
 *   ③ 第三处字符串**没有空判**：1d0ae4..1d0af4 连解两次引用后直接 ldr r1,[r3]，指针链断在哪一层都会崩。
 *   ④ 写入失败不可见：19 个 blx 之后没有一条指令读 r0（逐条可核），写满/类型不符的返回码全丢；
 *      函数照常走到 1d0d2c 的 mov r0,#1。⇒ 本函数只提供「缓冲存在」信号，不提供「写成功」信号。
 *   ⑤ 收尾的 Debug_AddTag 不是失败：g_isZeus==0 直接返回 1（1d0d14 beq 1d0d2c）；g_isZeus!=0 且
 *      *(void**)0x544c38==0 时打 "Save game"（0x350ddc）后仍返 1（1d0d4c）。
 *   ⑥ 落盘在包装层：0x1d1468 的 CreateBuffer(0x20000,1,1) 给 128 KiB 上限；WriteFile(名字,[buf+0xc],
 *      [buf+0x1c]) 之后无论成败都 FreeIBuffer（0x1d14d0/0x1d14d4），且**不检查**本函数返回值
 *      （0x1d149c 的 bl 后没有 cmp r0）—— 缓冲不存在时它会把一个零长度缓冲当内容写出去。
 *
 * ── 已证（指令级）───────────────────────────────────────────────────────
 *  1. 首段常量：1d07f0 清 +0x2c、1d07fc 清 +0x38、1d07f8/1d0800 拼 0x408a9800 进 +0x30 ⇒ 槽内是
 *     double 851.0（低位全 0）；类型码 6（1d07ec）⇒ 落盘 int32 851 = 0x353，与读回侧 movw 0x353 一致。
 *  2. 数值转换的分布：全函数 17 次 vcvt —— 8 次 f64.s32（1d0834/870/8ac/8e8/924/9fc/b20/b5c）、
 *     5 次 f64.u32 落在 18 段里的字节段（1d0960/99c/a38/acc/b98）、3 次 s32 落在房间表三个 int
 *     （1d0be4/c24/c60）、1 次 u32 落在房间存在位（1d0cb0）。⇒ 字节段与 int 段在指令形状上可区分。
 *  3. 房间表三段：1d0bc8 取 (int)*0x542990（Run_Room_List 首字 = count；vldr s15 只是把 int 当
 *     float 载入，随后 s32 转换，位模式等价）；1d0c00 写 0x54255c（CRoom_AddInstance 卡的 room_maxid）；
 *     1d0c3c 写 0x542558（CRoom_AddTile/DeSerialise 卡的 room_maxtileid）。
 *  4. 房间循环：1d0c78 重读 count、r10=0 起；每轮 1d0c9c 取 rooms[i]、1d0ca4/1d0ca8 归一成 0/1 写
 *     「存在位」，随后 1d0cd8..1d0ce8 再判非空才 CRoom::Serialise ⇒ 空房只留 1 个 bool。
 *  5. 循环边界是 `i < count`（1d0cf4/1d0cf8 blt 回 1d0c88），不是 `<=`；count<=0 时 1d0c84 ble 跳过。
 *  6. 收尾只读两个全局：0x5428e8 一字节（g_isZeus，CSprite_Draw/DoBreak 卡同址）与 0x544c38 的一层
 *     指针（g_DebugBuild，Builtins_Misc2 卡同址）；两处都是「非 0 才继续判」，没有任何写操作。
 *  7. 三条出口：1d0d2c mov r0,#1、1d0d4c mov r0,#1、1d0d34 mov r0,r6(=0)，全部 pop {…,pc}，无尾跳。
 *
 * ── open（本卡不解）────────────────────────────────────────────────────
 *   · 0x54294c / 0x542949 / 0x542948 / 0x542944 / 0x542940 / 0x54293c / 0x542938 / 0x542930 / 0x542928 /
 *     0x542924 这 10 格的**名字**未证（只能按形状分成 int / byte / 指针→串 / 8 字节 real）。它们与
 *     0x542910..0x542974 同属一段 .bss，语义应由 GML 全局表或初始化段给出，本索引不含。
 *   · 缓冲写满时的行为：Buffer_Standard::Write 不在本索引，只能证「本函数不看返回码」。
 *   · WriteFile 0x18fa3c 的失败语义与 128 KiB 上限溢出后果：属 LoadSave 卡范围。
 */

/* ── 1.1 入口 / 取缓冲（1d07c8..1d07dc）────────────────────────────────────
 *   push 10 字、无 sub sp；r0 原样进 GetIBuffer；r6 = 返回的 IBuffer*。
 *   1d07d8 的 subs 同时完成「置 Z 标志」与「r6 = r0」，所以 1d07dc 的 beq 判的就是 r6==0。
 */

/* @0x1d07c8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d07cc bl 0xc6720 <_Z10GetIBufferi> */
/* ── 1.2 PIC 锚（1d07d0/1d07d4）───────────────────────────────────────────
 *   池字 1d0d6c = 0x0022147c；pc(1d07dc) + 0x22147c = 0x3f1c58 —— 与 Command_Collision 卡同一个锚。
 */

/* @0x1d07d0 ldr r7, [pc, #0x594] */
/* @0x1d07d4 add r7, pc, r7 */
/* @0x1d07d8 subs r6, r0, #0 */
/* @0x1d07dc beq 0x1d0d34 <_Z16Command_SaveGamei+0x56c> */
/* @0x1d07e0 ldr r12, [r6] */
/* ── 1.3 r8 = buf+0x2c（1d07e4）───────────────────────────────────────────
 *   r8 全程只当 RValue 数据槽指针用，等价于 CRoom::Serialise 里的 r7。
 */

/* @0x1d07e4 add r8, r6, #44 */
/* ── 1.4 段 1：版本常量 851（1d07e8..1d080c）───────────────────────────────
 *   低字 0（r9）、高字 0x408a9800、tag 0、类型码 6 ⇒ double 851.0 经码 6 落成 int32 851。
 *   r9 在这里被赋 0，到 1d0a6c 之前都是「零寄存器」。
 */

/* @0x1d07e8 mov r9, #0 */
/* @0x1d07ec mov r1, #6 */
/* @0x1d07f0 str r9, [r6, #0x2c] */
/* @0x1d07f4 mov r2, r8 */
/* @0x1d07f8 mov r3, #38912 */
/* @0x1d07fc str r9, [r6, #0x38] */
/* @0x1d0800 movt r3, #0x408a */
/* @0x1d0804 str r3, [r6, #0x30] */
/* ── 1.5 写协议的收尾形状（每段都是这 4 条）────────────────────────────────
 *   ldr r3,[r12,#8]（vtable+8）→ blx r3；r0=buf、r1=码、r2=buf+0x2c 已在前面装好。
 */

/* @0x1d0808 ldr r3, [r12, #0x8] */
/* @0x1d080c blx r3 */
/* ── 1.6 段 2：版本格 0x542974（1d0810..1d0848）────────────────────────────
 *   与段 1 形状相同，但源是 *(int*)0x542974 —— 读回侧 1d0418 把读到的值原样存回同一格，是 round-trip。
 *   注意：全流里「唯一会被读回方拿去比 0x353」的是段 1 的常量，段 2 只被存回、不参与判定。
 */

/* @0x1d0810 ldr r12, [pc, #0x558] */
/* @0x1d0814 ldr r3, [r6] */
/* @0x1d0818 mov r2, r8 */
/* @0x1d081c mov r1, #6 */
/* @0x1d0820 mov r0, r6 */
/* @0x1d0824 ldr r12, [r7, r12] */
/* @0x1d0828 str r9, [r6, #0x38] */
/* @0x1d082c ldr r4, [r12] */
/* @0x1d0830 vmov s15, r4 */
/* @0x1d0834 vcvt.f64.s32 d7, s15 */
/* @0x1d0838 vmov r4, r5, d7 */
/* @0x1d083c vstr s14, [r6, #44] */
/* @0x1d0840 str r5, [r6, #0x30] */
/* @0x1d0844 ldr r3, [r3, #0x8] */
/* @0x1d0848 blx r3 */
/* ── 1.7 段 3：当前房间号 0x542958（1d084c..1d0884）─────────────────────────
 *   GOT 0x3ef3dc → 0x542958；StartRoom 卡：这一格就是当前房间下标，StartRoom 写两次。
 */

/* @0x1d084c ldr r12, [pc, #0x520] */
/* @0x1d0850 ldr r3, [r6] */
/* @0x1d0854 mov r2, r8 */
/* @0x1d0858 mov r1, #6 */
/* @0x1d085c mov r0, r6 */
/* @0x1d0860 ldr r12, [r7, r12] */
/* @0x1d0864 str r9, [r6, #0x38] */
/* @0x1d0868 ldr r4, [r12] */
/* @0x1d086c vmov s15, r4 */
/* @0x1d0870 vcvt.f64.s32 d7, s15 */
/* @0x1d0874 vmov r4, r5, d7 */
/* @0x1d0878 vstr s14, [r6, #44] */
/* @0x1d087c str r5, [r6, #0x30] */
/* @0x1d0880 ldr r3, [r3, #0x8] */
/* @0x1d0884 blx r3 */
/* ── 1.8 段 4：New_Room / 步进退出码 0x542954（1d0888..1d08c0）──────────────
 *   GOT 0x3eddac → 0x542954；DoAStep 卡：-1 = 继续跑，其它值整帧返回；Command_GotoRoom 也写这一格。
 */

/* @0x1d0888 ldr r12, [pc, #0x4e8] */
/* @0x1d088c ldr r3, [r6] */
/* @0x1d0890 mov r2, r8 */
/* @0x1d0894 mov r1, #6 */
/* @0x1d0898 mov r0, r6 */
/* @0x1d089c ldr r12, [r7, r12] */
/* @0x1d08a0 str r9, [r6, #0x38] */
/* @0x1d08a4 ldr r4, [r12] */
/* @0x1d08a8 vmov s15, r4 */
/* @0x1d08ac vcvt.f64.s32 d7, s15 */
/* @0x1d08b0 vmov r4, r5, d7 */
/* @0x1d08b4 vstr s14, [r6, #44] */
/* @0x1d08b8 str r5, [r6, #0x30] */
/* @0x1d08bc ldr r3, [r3, #0x8] */
/* @0x1d08c0 blx r3 */
/* ── 1.9 段 5：Transition_Kind 0x542950（1d08c4..1d08fc）───────────────────
 *   GOT 0x3ee0b0 → 0x542950；Builtins_Misc2 卡：Command_GotoRoom 每次置 0。
 */

/* @0x1d08c4 ldr r12, [pc, #0x4b0] */
/* @0x1d08c8 ldr r3, [r6] */
/* @0x1d08cc mov r2, r8 */
/* @0x1d08d0 mov r1, #6 */
/* @0x1d08d4 mov r0, r6 */
/* @0x1d08d8 ldr r12, [r7, r12] */
/* @0x1d08dc str r9, [r6, #0x38] */
/* @0x1d08e0 ldr r4, [r12] */
/* @0x1d08e4 vmov s15, r4 */
/* @0x1d08e8 vcvt.f64.s32 d7, s15 */
/* @0x1d08ec vmov r4, r5, d7 */
/* @0x1d08f0 vstr s14, [r6, #44] */
/* @0x1d08f4 str r5, [r6, #0x30] */
/* @0x1d08f8 ldr r3, [r3, #0x8] */
/* @0x1d08fc blx r3 */
/* ── 1.10 段 6：0x54294c（int，名字未证）（1d0900..1d0938）─────────────────── */

/* @0x1d0900 ldr r12, [pc, #0x478] */
/* @0x1d0904 ldr r3, [r6] */
/* @0x1d0908 mov r2, r8 */
/* @0x1d090c mov r1, #6 */
/* @0x1d0910 mov r0, r6 */
/* @0x1d0914 ldr r12, [r7, r12] */
/* @0x1d0918 str r9, [r6, #0x38] */
/* @0x1d091c ldr r4, [r12] */
/* @0x1d0920 vmov s15, r4 */
/* @0x1d0924 vcvt.f64.s32 d7, s15 */
/* @0x1d0928 vmov r4, r5, d7 */
/* @0x1d092c vstr s14, [r6, #44] */
/* @0x1d0930 str r5, [r6, #0x30] */
/* @0x1d0934 ldr r3, [r3, #0x8] */
/* @0x1d0938 blx r3 */
/* ── 1.11 段 7：0x542949（1 字节，u32 转换）（1d093c..1d0974）─────────────────
 *   ldrb 而不是 ldr ⇒ 与相邻的 0x542948 是两个独立 byte，不是同一 int 的两半。
 */

/* @0x1d093c ldr r12, [pc, #0x440] */
/* @0x1d0940 ldr r3, [r6] */
/* @0x1d0944 mov r2, r8 */
/* @0x1d0948 mov r1, #6 */
/* @0x1d094c mov r0, r6 */
/* @0x1d0950 ldr r12, [r7, r12] */
/* @0x1d0954 str r9, [r6, #0x38] */
/* @0x1d0958 ldrb r4, [r12] */
/* @0x1d095c vmov s15, r4 */
/* @0x1d0960 vcvt.f64.u32 d7, s15 */
/* @0x1d0964 vmov r4, r5, d7 */
/* @0x1d0968 vstr s14, [r6, #44] */
/* @0x1d096c str r5, [r6, #0x30] */
/* @0x1d0970 ldr r3, [r3, #0x8] */
/* @0x1d0974 blx r3 */
/* ── 1.12 段 8：0x542948（1 字节，u32 转换）（1d0978..1d09b0）───────────────── */

/* @0x1d0978 ldr r12, [pc, #0x408] */
/* @0x1d097c ldr r3, [r6] */
/* @0x1d0980 mov r2, r8 */
/* @0x1d0984 mov r0, r6 */
/* @0x1d0988 mov r1, #6 */
/* @0x1d098c ldr r12, [r7, r12] */
/* @0x1d0990 str r9, [r6, #0x38] */
/* @0x1d0994 ldrb r4, [r12] */
/* @0x1d0998 vmov s15, r4 */
/* @0x1d099c vcvt.f64.u32 d7, s15 */
/* @0x1d09a0 vmov r4, r5, d7 */
/* @0x1d09a4 vstr s14, [r6, #44] */
/* @0x1d09a8 str r5, [r6, #0x30] */
/* @0x1d09ac ldr r3, [r3, #0x8] */
/* @0x1d09b0 blx r3 */
/* ── 1.13 段 9：串 A（1d09b4..1d09d4）────────────────────────────────────
 *   r3 = *(void**)0x542944；为空 → 1d0d54 把 r1 换成空串再跳 1d09cc；非空 → ldr r1,[r3] 取对象首字段。
 *   ⇒ 0x542944 是「指向某对象的指针」，写的是对象 +0 的 char*。
 */

/* @0x1d09b4 ldr r3, [pc, #0x3d0] */
/* @0x1d09b8 ldr r3, [r7, r3] */
/* @0x1d09bc ldr r3, [r3] */
/* @0x1d09c0 cmp r3, r9 */
/* @0x1d09c4 beq 0x1d0d54 <_Z16Command_SaveGamei+0x58c> */
/* @0x1d09c8 ldr r1, [r3] */
/* @0x1d09cc mov r0, r6 */
/* @0x1d09d0 mov r9, #0 */
/* @0x1d09d4 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* ── 1.14 段 10：0x542940（int）（1d09d8..1d0a10）──────────────────────────── */

/* @0x1d09d8 ldr r2, [pc, #0x3b0] */
/* @0x1d09dc ldr r3, [r6] */
/* @0x1d09e0 mov r1, #6 */
/* @0x1d09e4 mov r0, r6 */
/* @0x1d09e8 ldr r12, [r7, r2] */
/* @0x1d09ec mov r2, r8 */
/* @0x1d09f0 str r9, [r6, #0x38] */
/* @0x1d09f4 ldr r4, [r12] */
/* @0x1d09f8 vmov s15, r4 */
/* @0x1d09fc vcvt.f64.s32 d7, s15 */
/* @0x1d0a00 vmov r4, r5, d7 */
/* @0x1d0a04 vstr s14, [r6, #44] */
/* @0x1d0a08 str r5, [r6, #0x30] */
/* @0x1d0a0c ldr r3, [r3, #0x8] */
/* @0x1d0a10 blx r3 */
/* ── 1.15 段 11：0x54293c（1 字节）（1d0a14..1d0a4c）────────────────────────── */

/* @0x1d0a14 ldr r12, [pc, #0x378] */
/* @0x1d0a18 ldr r3, [r6] */
/* @0x1d0a1c mov r0, r6 */
/* @0x1d0a20 mov r1, #6 */
/* @0x1d0a24 mov r2, r8 */
/* @0x1d0a28 ldr r12, [r7, r12] */
/* @0x1d0a2c str r9, [r6, #0x38] */
/* @0x1d0a30 ldrb r4, [r12] */
/* @0x1d0a34 vmov s15, r4 */
/* @0x1d0a38 vcvt.f64.u32 d7, s15 */
/* @0x1d0a3c vmov r4, r5, d7 */
/* @0x1d0a40 vstr s14, [r6, #44] */
/* @0x1d0a44 str r5, [r6, #0x30] */
/* @0x1d0a48 ldr r3, [r3, #0x8] */
/* @0x1d0a4c blx r3 */
/* ── 1.16 段 12：串 B（1d0a50..1d0a70）───────────────────────────────────
 *   与段 9 同构（同一个空串常量 0x32eb3e）。1d0a6c 在这里把 r10 也置 0 —— 后半的零换了寄存器。
 */

/* @0x1d0a50 ldr r3, [pc, #0x340] */
/* @0x1d0a54 ldr r3, [r7, r3] */
/* @0x1d0a58 ldr r3, [r3] */
/* @0x1d0a5c cmp r3, r9 */
/* @0x1d0a60 beq 0x1d0d60 <_Z16Command_SaveGamei+0x598> */
/* @0x1d0a64 ldr r1, [r3] */
/* @0x1d0a68 mov r0, r6 */
/* @0x1d0a6c mov r10, #0 */
/* @0x1d0a70 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* ── 1.17 段 13：8 字节 real（1d0a74..1d0aa4）─────────────────────────────
 *   唯一一处类型码 9；两条 ldr 原样搬 0x542930/+0x542934，**没有 vcvt** —— 与数值段（先转 double）
 *   形状完全不同，这是「8 字节整体」而非两个 int 的直接证据。
 */

/* @0x1d0a74 ldr r3, [pc, #0x320] */
/* @0x1d0a78 ldr r12, [r6] */
/* @0x1d0a7c mov r1, #9 */
/* @0x1d0a80 mov r2, r8 */
/* @0x1d0a84 mov r0, r6 */
/* @0x1d0a88 ldr r3, [r7, r3] */
/* @0x1d0a8c str r10, [r6, #0x38] */
/* @0x1d0a90 ldr lr, [r3] */
/* @0x1d0a94 ldr r3, [r3, #0x4] */
/* @0x1d0a98 str lr, [r6, #0x2c] */
/* @0x1d0a9c str r3, [r6, #0x30] */
/* @0x1d0aa0 ldr r3, [r12, #0x8] */
/* @0x1d0aa4 blx r3 */
/* ── 1.18 段 14：0x542928（1 字节）（1d0aa8..1d0ae0）────────────────────────── */

/* @0x1d0aa8 ldr r12, [pc, #0x2f0] */
/* @0x1d0aac ldr r3, [r6] */
/* @0x1d0ab0 mov r2, r8 */
/* @0x1d0ab4 mov r1, #6 */
/* @0x1d0ab8 mov r0, r6 */
/* @0x1d0abc ldr r12, [r7, r12] */
/* @0x1d0ac0 str r10, [r6, #0x38] */
/* @0x1d0ac4 ldrb r4, [r12] */
/* @0x1d0ac8 vmov s15, r4 */
/* @0x1d0acc vcvt.f64.u32 d7, s15 */
/* @0x1d0ad0 vmov r4, r5, d7 */
/* @0x1d0ad4 vstr s14, [r6, #44] */
/* @0x1d0ad8 str r5, [r6, #0x30] */
/* @0x1d0adc ldr r3, [r3, #0x8] */
/* @0x1d0ae0 blx r3 */
/* ── 1.19 段 15：串 C（1d0ae4..1d0af8）───────────────────────────────────
 *   两次解引用：P = *(void**)0x542924；s = *(char**)P。与段 9/12 不同，这里**没有**空判。
 */

/* @0x1d0ae4 ldr r3, [pc, #0x2b8] */
/* @0x1d0ae8 mov r0, r6 */
/* @0x1d0aec ldr r3, [r7, r3] */
/* @0x1d0af0 ldr r3, [r3] */
/* @0x1d0af4 ldr r1, [r3] */
/* @0x1d0af8 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* ── 1.20 段 16：GUI 精灵号 0x542918（1d0afc..1d0b34）───────────────────────
 *   Draw_Room 卡同址：GUI 段喂 Sprite_Data 的精灵号。
 */

/* @0x1d0afc ldr r12, [pc, #0x2a4] */
/* @0x1d0b00 ldr r3, [r6] */
/* @0x1d0b04 mov r1, #6 */
/* @0x1d0b08 mov r2, r8 */
/* @0x1d0b0c mov r0, r6 */
/* @0x1d0b10 ldr r12, [r7, r12] */
/* @0x1d0b14 str r10, [r6, #0x38] */
/* @0x1d0b18 ldr r4, [r12] */
/* @0x1d0b1c vmov s15, r4 */
/* @0x1d0b20 vcvt.f64.s32 d7, s15 */
/* @0x1d0b24 vmov r4, r5, d7 */
/* @0x1d0b28 vstr s14, [r6, #44] */
/* @0x1d0b2c str r5, [r6, #0x30] */
/* @0x1d0b30 ldr r3, [r3, #0x8] */
/* @0x1d0b34 blx r3 */
/* ── 1.21 段 17：步计数 0x542914（1d0b38..1d0b70）──────────────────────────
 *   DoAStep 卡：Scroll 段末自增的那一格。
 */

/* @0x1d0b38 ldr r12, [pc, #0x26c] */
/* @0x1d0b3c ldr r3, [r6] */
/* @0x1d0b40 mov r1, #6 */
/* @0x1d0b44 mov r2, r8 */
/* @0x1d0b48 mov r0, r6 */
/* @0x1d0b4c ldr r12, [r7, r12] */
/* @0x1d0b50 str r10, [r6, #0x38] */
/* @0x1d0b54 ldr r4, [r12] */
/* @0x1d0b58 vmov s15, r4 */
/* @0x1d0b5c vcvt.f64.s32 d7, s15 */
/* @0x1d0b60 vmov r4, r5, d7 */
/* @0x1d0b64 vstr s14, [r6, #44] */
/* @0x1d0b68 str r5, [r6, #0x30] */
/* @0x1d0b6c ldr r3, [r3, #0x8] */
/* @0x1d0b70 blx r3 */
/* ── 1.22 段 18：Draw 闸门 0x542910（1d0b74..1d0bac）───────────────────────
 *   DoAStep 卡：非 0 才调 Draw_Room；这里按 1 字节读。
 */

/* @0x1d0b74 ldr r12, [pc, #0x234] */
/* @0x1d0b78 ldr r3, [r6] */
/* @0x1d0b7c mov r2, r8 */
/* @0x1d0b80 mov r1, #6 */
/* @0x1d0b84 mov r0, r6 */
/* @0x1d0b88 ldr r12, [r7, r12] */
/* @0x1d0b8c str r10, [r6, #0x38] */
/* @0x1d0b90 ldrb r4, [r12] */
/* @0x1d0b94 vmov s15, r4 */
/* @0x1d0b98 vcvt.f64.u32 d7, s15 */
/* @0x1d0b9c vmov r4, r5, d7 */
/* @0x1d0ba0 vstr s14, [r6, #44] */
/* @0x1d0ba4 str r5, [r6, #0x30] */
/* @0x1d0ba8 ldr r3, [r3, #0x8] */
/* @0x1d0bac blx r3 */
/* ── 1.23 委派 A：全局变量表（1d0bb0）─────────────────────────────────────
 *   唯一一个把 buf 直接当 r0 的调用（没有类型码、没有数据槽）。
 */

/* @0x1d0bb0 mov r0, r6 */
/* @0x1d0bb4 bl 0x1f4a28 <_Z25Variable_Global_SerialiseP7IBuffer> */
/* ── 1.24 委派 B：相机（1d0bb8..1d0bc4）──────────────────────────────────
 *   GOT 0x3edc7c → 0x48f78c（g_CM，CCameraManager 单例）；r1 = buf。
 */

/* @0x1d0bb8 ldr r3, [pc, #0x1f4] */
/* @0x1d0bbc mov r1, r6 */
/* @0x1d0bc0 ldr r0, [r7, r3] */
/* @0x1d0bc4 bl 0x16e874 <_ZN14CCameraManager9SerializeEP7IBuffer> */
/* ── 1.25 委派 C：房间表（1d0bc8..1d0cf8）─────────────────────────────────
 *   r9 = *(GOT 0x3f0b30) = 0x542990（Run_Room_List，导出符号，size 8 = {count@0, array@4}）。
 *   1d0be0 用 vldr s15,[r9] 取首字（objdump 把 int 当 float 载入，随后按 s32 转 double，位模式等价）。
 *   随后 maxid / maxtileid 两条 int，再进每房循环。
 */

/* @0x1d0bc8 ldr r12, [pc, #0x1e8] */
/* @0x1d0bcc ldr r3, [r6] */
/* @0x1d0bd0 mov r1, #6 */
/* @0x1d0bd4 mov r2, r8 */
/* @0x1d0bd8 mov r0, r6 */
/* @0x1d0bdc ldr r9, [r7, r12] */
/* @0x1d0be0 vldr s15, [r9] */
/* @0x1d0be4 vcvt.f64.s32 d7, s15 */
/* @0x1d0be8 str r10, [r6, #0x38] */
/* @0x1d0bec vmov r4, r5, d7 */
/* @0x1d0bf0 vstr s14, [r6, #44] */
/* @0x1d0bf4 str r5, [r6, #0x30] */
/* @0x1d0bf8 ldr r3, [r3, #0x8] */
/* @0x1d0bfc blx r3 */
/* @0x1d0c00 ldr r12, [pc, #0x1b4] */
/* @0x1d0c04 ldr r3, [r6] */
/* @0x1d0c08 mov r1, #6 */
/* @0x1d0c0c mov r2, r8 */
/* @0x1d0c10 mov r0, r6 */
/* @0x1d0c14 ldr r12, [r7, r12] */
/* @0x1d0c18 str r10, [r6, #0x38] */
/* @0x1d0c1c ldr r4, [r12] */
/* @0x1d0c20 vmov s15, r4 */
/* @0x1d0c24 vcvt.f64.s32 d7, s15 */
/* @0x1d0c28 vmov r4, r5, d7 */
/* @0x1d0c2c vstr s14, [r6, #44] */
/* @0x1d0c30 str r5, [r6, #0x30] */
/* @0x1d0c34 ldr r3, [r3, #0x8] */
/* @0x1d0c38 blx r3 */
/* @0x1d0c3c ldr r12, [pc, #0x17c] */
/* @0x1d0c40 ldr r3, [r6] */
/* @0x1d0c44 mov r0, r6 */
/* @0x1d0c48 mov r1, #6 */
/* @0x1d0c4c mov r2, r8 */
/* @0x1d0c50 ldr r12, [r7, r12] */
/* @0x1d0c54 str r10, [r6, #0x38] */
/* @0x1d0c58 ldr r4, [r12] */
/* @0x1d0c5c vmov s15, r4 */
/* @0x1d0c60 vcvt.f64.s32 d7, s15 */
/* @0x1d0c64 vmov r4, r5, d7 */
/* @0x1d0c68 vstr s14, [r6, #44] */
/* @0x1d0c6c str r5, [r6, #0x30] */
/* @0x1d0c70 ldr r3, [r3, #0x8] */
/* @0x1d0c74 blx r3 */
/* ── 1.26 房间循环（1d0c78..1d0cf8）──────────────────────────────────────
 *   count<=0 → 1d0c84 ble 直接去 1d0cfc；每轮：bool(rooms[i]!=0) → 非空则 CRoom::Serialise。
 */

/* @0x1d0c78 ldr r3, [r9] */
/* @0x1d0c7c cmp r3, r10 */
/* @0x1d0c80 movgt r11, r10 */
/* @0x1d0c84 ble 0x1d0cfc <_Z16Command_SaveGamei+0x534> */
/* @0x1d0c88 ldr r12, [r9, #0x4] */
/* @0x1d0c8c mov r1, #6 */
/* @0x1d0c90 ldr r3, [r6] */
/* @0x1d0c94 mov r0, r6 */
/* @0x1d0c98 mov r2, r8 */
/* @0x1d0c9c ldr r4, [r12, r10, lsl #2] */
/* @0x1d0ca0 str r11, [r6, #0x38] */
/* @0x1d0ca4 adds r4, r4, #0 */
/* @0x1d0ca8 movne r4, #1 */
/* @0x1d0cac vmov s15, r4 */
/* @0x1d0cb0 vcvt.f64.u32 d7, s15 */
/* @0x1d0cb4 vmov r4, r5, d7 */
/* @0x1d0cb8 vstr s14, [r6, #44] */
/* @0x1d0cbc str r5, [r6, #0x30] */
/* @0x1d0cc0 ldr r3, [r3, #0x8] */
/* @0x1d0cc4 blx r3 */
/* @0x1d0cc8 ldr r3, [r9] */
/* @0x1d0ccc mov r1, r6 */
/* @0x1d0cd0 cmp r10, r3 */
/* @0x1d0cd4 bge 0x1d0cf0 <_Z16Command_SaveGamei+0x528> */
/* @0x1d0cd8 ldr r2, [r9, #0x4] */
/* @0x1d0cdc ldr r0, [r2, r10, lsl #2] */
/* @0x1d0ce0 cmp r0, #0 */
/* @0x1d0ce4 beq 0x1d0cf0 <_Z16Command_SaveGamei+0x528> */
/* @0x1d0ce8 bl 0x1aa228 <_ZN5CRoom9SerialiseEP7IBuffer> */
/* @0x1d0cec ldr r3, [r9] */
/* @0x1d0cf0 add r10, r10, #1 */
/* @0x1d0cf4 cmp r10, r3 */
/* @0x1d0cf8 blt 0x1d0c88 <_Z16Command_SaveGamei+0x4c0> */
/* ── 1.27 委派 D：虚拟按键（1d0cfc..1d0d00）────────────────────────────── */

/* @0x1d0cfc mov r0, r6 */
/* @0x1d0d00 bl 0x18c698 <_Z21VirtualKeys_SerialiseP7IBuffer> */
/* ── 1.28 收尾：两个调试标志（1d0d04..1d0d30）─────────────────────────────
 *   0x5428e8 读 1 字节；非 0 再看 0x544c38 的一层指针；两者组合才打 tag。
 */

/* @0x1d0d04 ldr r3, [pc, #0xb8] */
/* @0x1d0d08 ldr r3, [r7, r3] */
/* @0x1d0d0c ldrb r3, [r3] */
/* @0x1d0d10 cmp r3, #0 */
/* @0x1d0d14 beq 0x1d0d2c <_Z16Command_SaveGamei+0x564> */
/* @0x1d0d18 ldr r3, [pc, #0xa8] */
/* @0x1d0d1c ldr r3, [r7, r3] */
/* @0x1d0d20 ldr r3, [r3] */
/* @0x1d0d24 cmp r3, #0 */
/* @0x1d0d28 beq 0x1d0d3c <_Z16Command_SaveGamei+0x574> */
/* @0x1d0d2c mov r0, #1 */
/* @0x1d0d30 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 1.29 唯一失败出口（1d0d34/1d0d38）───────────────────────────────────
 *   r6 此时必为 0（1d07d8 的 subs 已把它清掉），mov r0,r6 即 return 0。
 */

/* @0x1d0d34 mov r0, r6 */
/* @0x1d0d38 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 1.30 Debug_AddTag 的形状（1d0d3c..1d0d50）───────────────────────────
 *   r1 = pc(1d0d4c) + 0x180090 = 0x350ddc = "Save game"；r0 = 2；打完 mov r0,#1 返回。
 */

/* @0x1d0d3c ldr r1, [pc, #0x88] */
/* @0x1d0d40 mov r0, #2 */
/* @0x1d0d44 add r1, pc, r1 */
/* @0x1d0d48 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x1d0d4c mov r0, #1 */
/* @0x1d0d50 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 1.31 两处空串回落（1d0d54..1d0d5c / 1d0d60..1d0d68）──────────────────
 *   两处算出的都是 0x32eb3e —— .rodata 里 "libGLESv2.so" 前面的一串 0，按 C 串就是 ""。
 */

/* @0x1d0d54 ldr r1, [pc, #0x74] */
/* @0x1d0d58 add r1, pc, r1 */
/* @0x1d0d5c b 0x1d09cc <_Z16Command_SaveGamei+0x204> */
/* @0x1d0d60 ldr r1, [pc, #0x6c] */
/* @0x1d0d64 add r1, pc, r1 */
/* @0x1d0d68 b 0x1d0a68 <_Z16Command_SaveGamei+0x2a0> */
/* ── 1.32 池字 27 个（0x1d0d6c..0x1d0dd4，非指令）─────────────────────────
 *   前 18 个是 GOT 偏移，后 9 个是串/常量偏移。逐字（pc 基准一律 +8）：
 *    1d0d6c 0x0022147c → PIC 锚（1d07dc+0x22147c = 0x3f1c58）
 *    1d0d70 0xffffeec4 → 0x3f0b1c → 0x542974   1d0d74 0xffffd784 → 0x3ef3dc → 0x542958
 *    1d0d78 0xffffc154 → 0x3eddac → 0x542954   1d0d7c 0xffffc458 → 0x3ee0b0 → 0x542950
 *    1d0d80 0xffffce34 → 0x3eea8c → 0x54294c   1d0d84 0xffffd99c → 0x3ef5f4 → 0x542949
 *    1d0d88 0xffffd998 → 0x3ef5f0 → 0x542948   1d0d8c 0xffffd9a0 → 0x3ef5f8 → 0x542944
 *    1d0d90 0xffffd780 → 0x3ef3d8 → 0x542940   1d0d94 0xffffd9a4 → 0x3ef5fc → 0x54293c
 *    1d0d98 0xffffd9a8 → 0x3ef600 → 0x542938   1d0d9c 0xffffd788 → 0x3ef3e0 → 0x542930
 *    1d0da0 0xffffd9ac → 0x3ef604 → 0x542928   1d0da4 0xffffd9b0 → 0x3ef608 → 0x542924
 *    1d0da8 0xffffd798 → 0x3ef3f0 → 0x542918   1d0dac 0xffffebf0 → 0x3f0848 → 0x542914
 *    1d0db0 0xffffc974 → 0x3ee5cc → 0x542910   1d0db4 0xffffc024 → 0x3edc7c → 0x48f78c
 *    1d0db8 0xffffeed8 → 0x3f0b30 → 0x542990   1d0dbc 0xffffebbc → 0x3f0814 → 0x54255c
 *    1d0dc0 0xffffebc0 → 0x3f0818 → 0x542558   1d0dc4 0xffffbcd4 → 0x3ed92c → 0x5428e8
 *    1d0dc8 0xffffc7d0 → 0x3ee428 → 0x544c38   1d0dcc 0x00180090（Debug_AddTag 串偏移）
 *    1d0dd0 0x0015ddde / 1d0dd4 0x0015ddd2（两处空串偏移，落点同为 0x32eb3e）
 */

/* @0x1d0d6c eoreq r1, r2, r12, ror r4 */
/* @0x1d0d70 .word 0xffffeec4 */
/* @0x1d0d74 .word 0xffffd784 */
/* @0x1d0d78 .word 0xffffc154 */
/* @0x1d0d7c .word 0xffffc458 */
/* @0x1d0d80 .word 0xffffce34 */
/* @0x1d0d84 .word 0xffffd99c */
/* @0x1d0d88 .word 0xffffd998 */
/* @0x1d0d8c .word 0xffffd9a0 */
/* @0x1d0d90 .word 0xffffd780 */
/* @0x1d0d94 .word 0xffffd9a4 */
/* @0x1d0d98 .word 0xffffd9a8 */
/* @0x1d0d9c .word 0xffffd788 */
/* @0x1d0da0 .word 0xffffd9ac */
/* @0x1d0da4 .word 0xffffd9b0 */
/* @0x1d0da8 .word 0xffffd798 */
/* @0x1d0dac .word 0xffffebf0 */
/* @0x1d0db0 .word 0xffffc974 */
/* @0x1d0db4 .word 0xffffc024 */
/* @0x1d0db8 .word 0xffffeed8 */
/* @0x1d0dbc .word 0xffffebbc */
/* @0x1d0dc0 .word 0xffffebc0 */
/* @0x1d0dc4 .word 0xffffbcd4 */
/* @0x1d0dc8 .word 0xffffc7d0 */
/* @0x1d0dcc mulseq r8, r0, r0 */
/* @0x1d0dd0 ldrsbeq sp, [r5], -lr */
/* @0x1d0dd4 ldrsbeq sp, [r5], -r2 */

/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 2 · Command_Unzip(char const* zip, char const* dir, int limit, int stride, char* out)
 * @func 0x1ca040 0x1ca350  size 784  196 锚点（186 条指令 + 10 个池字 0x1ca328..0x1ca34c）
 * 符号: _Z13Command_UnzipPKcS0_iiPc
 * 调用者: F_ZipUnzip 0x13914c 的 0x139210（bl；limit=0、stride=0、out=NULL）；
 *         LoadSave::_ExpandCompressedFile 0x18fc44 的 0x18fc64（b 尾跳，装参重排成 (b,a,e,d,c)）
 * 同层: IBuffer ctor 0xcc994、IBuffer::Load 0xcd91c、zip_open_buff 0x2a51a0、zip_get_num_files 0x2a490e、
 *       zip_get_name 0x2a4970、zip_fopen 0x2a44b8、zip_stat 0x2a5670、zip_fread 0x2a476c、
 *       zip_fclose 0x2a4388、zip_close 0x2a31ec、MemoryManager::Alloc 0x27ce78 / Free 0x27c2d0、
 *       LoadSave::WriteFile 0x18fa3c
 * 一句话: 把 zip 整体读进自己 new 出来的 IBuffer，逐条 entry 解到 dir/name；limit/stride/out 只控制
 *         「顺便把前 limit 条路径按 stride 拷进调用方数组」，不限制解压本身。返回值 = entry 数。
 * ═══════════════════════════════════════════════════════════════════════════
 */

/* ── 语义草案 ─────────────────────────────────────────────────────────────
 *   int Command_Unzip(const char* zipPath, const char* dir, int limit, int stride, char* out) {
 *     buf = new(64) IBuffer(0, 1, 1);                 // 1ca08c..1ca0a0
 *     *(void**)buf = *(GOT 0x3ed9b8) + 8;             // 1ca0bc..1ca0c4  vptr 改成 0x3eb790
 *     buf->Load(zipPath, 0, -1, 0);                   // 1ca0cc  整个 zip 进内存
 *     zip = zip_open_buff(buf, 0, 0);                 // 1ca0dc
 *     if (!zip) { 释放 buf; 报 "Unable to open %s for decompression"; return 0; }
 *     n = zip_get_num_files(zip);                     // 1ca0e8
 *     if (n > 0) for (i = 0; i < n; i++) {            // 1ca190/1ca194/1ca198
 *        name = zip_get_name(zip, i, 8);              // 1ca1a4
 *        if (limit > i)                               // 1ca1ac bgt→1ca1b8
 *           snprintf(out, stride - 1, "%s/%s", dir, name);   // 1ca1d0
 *        f = zip_fopen(zip, name, 1);                 // 1ca150
 *        zip_stat(zip, name, 1, &st);                 // 1ca168
 *        size = st.size;                              // 1ca16c（st+0x10）
 *        if (size) {                                  // 1ca174 bne→1ca1d8
 *           p = Alloc(size, "…/Files/Run/Run_Command.cpp", 0x78e, 1);   // 1ca1e4
 *           while ((got = zip_fread(f, q, left)) != left) {  // 1ca208
 *              if (!got) break;                       // 1ca224
 *              printf("read underflow detected");     // 1ca21c
 *              left -= got; q += got;                 // 1ca228/1ca22c
 *           }
 *           zip_fclose(f);                            // 1ca23c
 *           snprintf(path, 0x3ff, "%s/%s", dir, name);  // 1ca254
 *           if (!WriteFile(path, p, size))             // 1ca264/1ca268
 *              报 "UNZIP: Failed to write compressed file entry :o";  // 1ca2bc..1ca2d8
 *           Free(p);                                  // 1ca274
 *        }                                            // size==0 分支**不 fclose**
 *        i++; out += stride;                          // 1ca17c..1ca18c
 *     }
 *     zip_close(zip); buf->vt[+4](); return n;        // 1ca280..1ca2b8
 *   }
 *
 * ── 帧与实参 ─────────────────────────────────────────────────────────────
 *   push {r4..r11,lr}（36 B）+ sub sp,#1120 + sub sp,#4 = 1160 B ⇒ 第 5 实参在 [sp,#0x488]（1ca07c，装入 r10）。
 *   实参落位：r0→r4（zip 路径，1ca050）、r1→[sp+0xc]（dir 前缀，1ca06c）、r2→[sp+0x20]（limit，1ca070）、
 *   r3→[sp+0x18]（stride，1ca074）、第 5 个→r10→[sp+8]（out 游标，1ca0fc）。
 *   栈上布局：sp+0x28 存 new 出来的 IBuffer*；sp+0x2c = PIC 锚 0x3f1c58；sp+0x40 起是 zip_stat 记录
 *   （size 在 +0x10，即 [sp+0x50]）；sp+0x5c 起是 1024 B 路径缓冲；sp+0x45c 是栈金丝雀。
 *
 * ── 失败路径（逐条，全部落锚）────────────────────────────────────────────
 *   ① zip 打开失败（1ca0e0 subs r8 / 1ca0e4 beq 1ca2e0）：先 vtable+4 释放缓冲（1ca2e4..1ca2f0），
 *      再对 *(GOT 0x3ed71c → 0x3eb70c) 指向的对象调 vt+0xc("Unable to open %s for decompression\n",
 *      zipPath)（1ca2f4..1ca318），最后 mov r0,r8(=0) 走公共收尾（1ca31c → 1ca29c）。返回 0。
 *   ② n<=0（1ca0f0 str / 1ca0f4 ble 1ca27c）：关 zip、释放缓冲、返回 n（可能是 0 或负数）。
 *   ③ 短读（1ca20c cmp r0,r11 不等）：printf("read underflow detected")（1ca21c）；got==0 时放弃该 entry
 *      （1ca224 beq 1ca234）；但 1ca260 仍拿 **stat 的 size** 调 WriteFile ⇒ 没读到的尾部是 Alloc 出来的
 *      未初始化内存，照样落盘。全函数没有一条指令把「短读」变成错误返回。
 *   ④ WriteFile 返回 0（1ca268 cmp / 1ca26c beq 1ca2bc）：打 "UNZIP: Failed to write compressed file
 *      entry :o"（1ca2cc 的 r1 = [sp+0x3c]），随后照常 Free（1ca270）并继续下一条。
 *   ⑤ 返回值是 entry 数（1ca298 ldr r0,[sp,#0x1c]），不是成败；除 ① 外没有任何路径能把「失败」传出去。
 *   ⑥ size==0 的 entry 只开不关：1ca178 直接跳过 1ca234 那段 zip_fclose ⇒ 每条空 entry 漏一个 zip 句柄。
 *
 * ── 已证（指令级）───────────────────────────────────────────────────────
 *  1. 两个 snprintf 的模板都是 "%s/%s"（0x350d50，池字 1ca334/1ca340 两次算到同一地址）；列表模式限长
 *     是 stride-1（1ca1c0 sub r1,r12,#1），全路径模式限长 0x3ff（1ca240 movw）；全路径缓冲从 sp+0x5c
 *     起 1024 B，正好抵到栈金丝雀 [sp+0x45c]（0x5c+0x400=0x45c）—— 缓冲边界是算出来的，不是猜的。
 *  2. 路径不做任何清洗：全函数没有一条指令检查 name 里的 "../"、绝对路径或分隔符，直接 "%s/%s" 拼接。
 *  3. stat.size 取 stat+0x10（1ca16c ldr r0,[sp,#0x50]，基址 sp+0x40）；32 位读，Alloc 的 size 同源
 *     （1ca1e4 的 r0 就是这格），WriteFile 的长度也是这格（1ca260）⇒ 分配/写入/落盘三处同一个值。
 *  4. 读取循环三出口：读满（1ca20c beq 1ca234）、got==0（1ca224 beq 1ca234）、left 归零（1ca230 bne 回
 *     1ca1fc，否则落进 1ca234）。分配用的是 MemoryManager::Alloc（带文件名/行号 0x78e 与一个 bool）。
 *  5. 收尾顺序：zip_close（1ca27c）→ vtable+4 释放（1ca284..1ca294）→ 取返回值（1ca298）→ 栈金丝雀比对
 *     （1ca2a0..1ca2ac，不等就 __stack_chk_fail）→ 恢复 sp/寄存器。
 *  6. 常量实参：zip_get_name 的第 3 实参恒 8（1ca1a0）、zip_open_buff 的第 2/3 实参恒 0（1ca0d4/1ca0d8）、
 *     zip_fopen/zip_stat 的第 3 实参恒 1（1ca148/1ca158）。IBuffer 大小 64 B（1ca054 mov r0,#64）。
 *  7. 两条调用路径的差异只在 limit/stride/out：F_ZipUnzip 传 (0,0,NULL) ⇒ 列表分支恒不执行；
 *     _ExpandCompressedFile 把 (d,e,c) 原样透传 ⇒ 才是列表模式的唯一真实使用者。
 *
 * ── open（本卡不解）────────────────────────────────────────────────────
 *   · minizip 内部（zip_open_buff / zip_stat / zip_fread 的错误码语义）；zip_stat 失败时 [sp+0x50] 是
 *     否仍为 0（本卡只能证「为 0 就跳过写入」）。
 *   · IBuffer::Load 对 > 内部容量的 zip 的行为；128 KiB 是 SaveGame 侧的常量，与本函数无关。
 *   · limit/stride 的上游来源（_ExpandCompressedFile 的第 4/5 实参由谁给），以及 out 数组的释放方。
 */

/* ── 2.1 入口与帧（1ca040..1ca060）───────────────────────────────────────
 *   sub sp,#1120 + sub sp,#4 两个减法（objdump 不合并），加 9 个 push 共 1160 B。
 *   第一个池字 1ca328 = 0x00227bf8；pc(1ca060) + 0x227bf8 = 0x3f1c58（PIC 锚），存进 [sp+0x2c] 备用。
 */

/* @0x1ca040 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ca044 sub sp, sp, #1120 */
/* @0x1ca048 sub sp, sp, #4 */
/* @0x1ca04c ldr r12, [pc, #0x2d4] */
/* @0x1ca050 mov r4, r0 */
/* ── 2.2 operator new(64) + IBuffer ctor（1ca054..1ca0a4）─────────────────
 *   r0=64 进 operator new；ctor 收 (0,1,1)；this 存 [sp+0x28]。
 */

/* @0x1ca054 mov r0, #64 */
/* @0x1ca058 add r12, pc, r12 */
/* @0x1ca05c str r12, [sp, #0x2c] */
/* @0x1ca060 ldr lr, [sp, #0x2c] */
/* @0x1ca064 mov r6, #0 */
/* @0x1ca068 ldr r12, [pc, #0x2bc] */
/* @0x1ca06c str r1, [sp, #0xc] */
/* @0x1ca070 str r2, [sp, #0x20] */
/* @0x1ca074 str r3, [sp, #0x18] */
/* @0x1ca078 ldr r12, [lr, r12] */
/* @0x1ca07c ldr r10, [sp, #0x488] */
/* @0x1ca080 ldr r3, [r12] */
/* @0x1ca084 str r12, [sp, #0x30] */
/* @0x1ca088 str r3, [sp, #0x45c] */
/* @0x1ca08c bl 0x27c524 <_Znwj> */
/* @0x1ca090 mov r2, #1 */
/* @0x1ca094 mov r1, r6 */
/* @0x1ca098 mov r3, r2 */
/* @0x1ca09c str r0, [sp, #0x28] */
/* @0x1ca0a0 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* ── 2.3 vptr 覆写（1ca0ac..1ca0c4）──────────────────────────────────────
 *   *(GOT 0x3ed9b8) = 0x3eb788，再 +8 ⇒ vptr = 0x3eb790（ctor 里设的基类 vptr 被换成 Buffer_Standard）。
 */

/* @0x1ca0a4 ldr lr, [sp, #0x2c] */
/* @0x1ca0a8 mov r1, r4 */
/* @0x1ca0ac ldr r12, [pc, #0x27c] */
/* @0x1ca0b0 mov r2, r6 */
/* @0x1ca0b4 ldr r0, [sp, #0x28] */
/* @0x1ca0b8 mvn r3, #0 */
/* @0x1ca0bc ldr r12, [lr, r12] */
/* @0x1ca0c0 add r12, r12, #8 */
/* @0x1ca0c4 str r12, [r0] */
/* ── 2.4 IBuffer::Load(zip,0,-1,0)（1ca0c8..1ca0cc）────────────────────────
 *   r3 = mvn #0 = -1；第 5 实参 [sp] = 0。整个 zip 读进这块缓冲。
 */

/* @0x1ca0c8 str r6, [sp] */
/* @0x1ca0cc bl 0xcd91c <_ZN7IBuffer4LoadEPKciii> */
/* ── 2.5 zip_open_buff(buf,0,0)（1ca0d0..1ca0dc）───────────────────────────
 *   r8 = zip 句柄；为 0 走 1ca2e0 的打开失败路径。
 */

/* @0x1ca0d0 ldr r0, [sp, #0x28] */
/* @0x1ca0d4 mov r1, r6 */
/* @0x1ca0d8 mov r2, r6 */
/* @0x1ca0dc blx 0x2a51a0 <zip_open_buff> */
/* @0x1ca0e0 subs r8, r0, #0 */
/* @0x1ca0e4 beq 0x1ca2e0 <_Z13Command_UnzipPKcS0_iiPc+0x2a0> */
/* ── 2.6 entry 计数（1ca0e8..1ca0f4）──────────────────────────────────────
 *   n 存 [sp+0x1c]，同时也是最终返回值；<=0 直接去收尾。
 */

/* @0x1ca0e8 blx 0x2a490e <zip_get_num_files> */
/* @0x1ca0ec cmp r0, #0 */
/* @0x1ca0f0 str r0, [sp, #0x1c] */
/* @0x1ca0f4 ble 0x1ca27c <_Z13Command_UnzipPKcS0_iiPc+0x23c> */
/* ── 2.7 循环前的四个指针常量（1ca0f8..1ca13c）────────────────────────────
 *   [sp+0x34] = "%s/%s"（1ca100 → 0x350d50）；[sp+0x38] = 分配点文件名
 *   "jni/../jni/yoyo/../../../Files/Run/Run_Command.cpp"（1ca114 → 0x350d58）；
 *   [sp+0x14] = "read underflow detected"（1ca120 → 0x34c494）；[sp+0x10] = "%s/%s"（1ca12c）；
 *   [sp+0x3c] = "UNZIP: Failed to write compressed file entry :o"（1ca138 → 0x350d8c）。
 */

/* @0x1ca0f8 ldr r12, [pc, #0x234] */
/* @0x1ca0fc str r10, [sp, #0x8] */
/* @0x1ca100 add r12, pc, r12 */
/* @0x1ca104 str r12, [sp, #0x34] */
/* @0x1ca108 add r12, sp, #64 */
/* @0x1ca10c str r12, [sp, #0x24] */
/* @0x1ca110 ldr r12, [pc, #0x220] */
/* @0x1ca114 add r12, pc, r12 */
/* @0x1ca118 str r12, [sp, #0x38] */
/* @0x1ca11c ldr r12, [pc, #0x218] */
/* @0x1ca120 add r12, pc, r12 */
/* @0x1ca124 str r12, [sp, #0x14] */
/* @0x1ca128 ldr r12, [pc, #0x210] */
/* @0x1ca12c add r12, pc, r12 */
/* @0x1ca130 str r12, [sp, #0x10] */
/* @0x1ca134 ldr r12, [pc, #0x208] */
/* @0x1ca138 add r12, pc, r12 */
/* @0x1ca13c str r12, [sp, #0x3c] */
/* @0x1ca140 b 0x1ca198 <_Z13Command_UnzipPKcS0_iiPc+0x158> */
/* ── 2.8 单条 entry 的取流（1ca144..1ca16c）──────────────────────────────
 *   zip_fopen(name,1) → zip_stat(name,1,&st@sp+0x40) → size = [sp+0x50]（st+0x10）。
 */

/* @0x1ca144 mov r1, r7 */
/* @0x1ca148 mov r2, #1 */
/* @0x1ca14c mov r0, r8 */
/* @0x1ca150 blx 0x2a44b8 <zip_fopen> */
/* @0x1ca154 mov r1, r7 */
/* @0x1ca158 mov r2, #1 */
/* @0x1ca15c add r3, sp, #64 */
/* @0x1ca160 mov r5, r0 */
/* @0x1ca164 mov r0, r8 */
/* @0x1ca168 blx 0x2a5670 <zip_stat> */
/* ── 2.9 size 判零（1ca16c..1ca174）───────────────────────────────────────
 *   非 0 → 1ca1d8 解压；为 0 → 1ca178 只推进游标，**不 fclose**（句柄泄漏点）。
 */

/* @0x1ca16c ldr r0, [sp, #0x50] */
/* @0x1ca170 cmp r0, #0 */
/* @0x1ca174 bne 0x1ca1d8 <_Z13Command_UnzipPKcS0_iiPc+0x198> */
/* ── 2.10 跳过/收尾推进（1ca178..1ca194）──────────────────────────────────
 *   out 游标 += stride、i++；i==n 就跳 1ca27c 收尾，否则回 1ca198 取下一条。
 */

/* @0x1ca178 ldr r12, [sp, #0x8] */
/* @0x1ca17c add r6, r6, #1 */
/* @0x1ca180 ldr lr, [sp, #0x18] */
/* @0x1ca184 add r12, r12, lr */
/* @0x1ca188 str r12, [sp, #0x8] */
/* @0x1ca18c ldr r12, [sp, #0x1c] */
/* @0x1ca190 cmp r6, r12 */
/* @0x1ca194 beq 0x1ca27c <_Z13Command_UnzipPKcS0_iiPc+0x23c> */
/* ── 2.11 循环头：取名字（1ca198..1ca1ac）───────────────────────────────── */

/* @0x1ca198 mov r0, r8 */
/* @0x1ca19c mov r1, r6 */
/* @0x1ca1a0 mov r2, #8 */
/* @0x1ca1a4 blx 0x2a4970 <zip_get_name> */
/* ── 2.12 limit 门（1ca1a8..1ca1b4）──────────────────────────────────────
 *   limit > i 才把路径写进调用方数组（1ca1b4 ble 跳 1ca144 直接去解压——**解压不受 limit 限制**）。
 */

/* @0x1ca1a8 ldr r12, [sp, #0x20] */
/* @0x1ca1ac cmp r12, r6 */
/* @0x1ca1b0 mov r7, r0 */
/* @0x1ca1b4 ble 0x1ca144 <_Z13Command_UnzipPKcS0_iiPc+0x104> */
/* ── 2.13 列表模式的 snprintf（1ca1b8..1ca1d4）────────────────────────────
 *   snprintf(out, stride-1, "%s/%s", dir, name)；out 游标本轮末尾按 stride 前进。
 */

/* @0x1ca1b8 ldr r12, [sp, #0x18] */
/* @0x1ca1bc str r0, [sp] */
/* @0x1ca1c0 sub r1, r12, #1 */
/* @0x1ca1c4 ldr r0, [sp, #0x8] */
/* @0x1ca1c8 ldr r2, [sp, #0x34] */
/* @0x1ca1cc ldr r3, [sp, #0xc] */
/* @0x1ca1d0 bl 0xb65c8 <snprintf@plt> */
/* @0x1ca1d4 b 0x1ca144 <_Z13Command_UnzipPKcS0_iiPc+0x104> */
/* ── 2.14 分配 entry 缓冲（1ca1d8..1ca1f8）────────────────────────────────
 *   Alloc(size, "…Run_Command.cpp", 0x78e, 1)；r9 保存基址、r4 当写游标。1ca1f8 的 beq 只看 r11==0，
 *   而入口 1ca174 已判过 size!=0 ⇒ 该支路在此不可达（1ca1f0/1ca1f4 仍无条件写 r9、条件写 r4）。
 */

/* @0x1ca1d8 ldr r1, [sp, #0x38] */
/* @0x1ca1dc movw r2, #0x78e */
/* @0x1ca1e0 mov r3, #1 */
/* @0x1ca1e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ca1e8 ldr r11, [sp, #0x50] */
/* @0x1ca1ec cmp r11, #0 */
/* @0x1ca1f0 mov r9, r0 */
/* @0x1ca1f4 movne r4, r0 */
/* @0x1ca1f8 beq 0x1ca234 <_Z13Command_UnzipPKcS0_iiPc+0x1f4> */
/* ── 2.15 短读循环（1ca1fc..1ca230）───────────────────────────────────────
 *   zip_fread(f, cur, left)；不等于 left 就 printf 一句，got==0 放弃，否则 left-=got、cur+=got 再来。
 */

/* @0x1ca1fc mov r0, r5 */
/* @0x1ca200 mov r1, r4 */
/* @0x1ca204 mov r2, r11 */
/* @0x1ca208 blx 0x2a476c <zip_fread> */
/* @0x1ca20c cmp r0, r11 */
/* @0x1ca210 mov r10, r0 */
/* @0x1ca214 beq 0x1ca234 <_Z13Command_UnzipPKcS0_iiPc+0x1f4> */
/* ── 2.16 短读告警（1ca218..1ca21c）──────────────────────────────────────
 *   格式串 = 0x34c494 "read underflow detected"，无参数。
 */

/* @0x1ca218 ldr r0, [sp, #0x14] */
/* @0x1ca21c bl 0xb6964 <printf@plt> */
/* @0x1ca220 cmp r10, #0 */
/* @0x1ca224 beq 0x1ca234 <_Z13Command_UnzipPKcS0_iiPc+0x1f4> */
/* @0x1ca228 subs r11, r11, r10 */
/* @0x1ca22c add r4, r4, r10 */
/* @0x1ca230 bne 0x1ca1fc <_Z13Command_UnzipPKcS0_iiPc+0x1bc> */
/* ── 2.17 关 entry + 拼全路径（1ca234..1ca254）────────────────────────────
 *   zip_fclose(f)；snprintf(sp+0x5c, 0x3ff, "%s/%s", dir, name) —— 1024 B 栈缓冲。
 */

/* @0x1ca234 add r4, sp, #92 */
/* @0x1ca238 mov r0, r5 */
/* @0x1ca23c blx 0x2a4388 <zip_fclose> */
/* @0x1ca240 movw r1, #0x3ff */
/* @0x1ca244 ldr r2, [sp, #0x10] */
/* @0x1ca248 mov r0, r4 */
/* @0x1ca24c ldr r3, [sp, #0xc] */
/* @0x1ca250 str r7, [sp] */
/* @0x1ca254 bl 0xb65c8 <snprintf@plt> */
/* ── 2.18 落盘（1ca258..1ca264）──────────────────────────────────────────
 *   WriteFile(路径, p, size)；size 仍是 stat 那格，与短读无关。
 */

/* @0x1ca258 mov r0, r4 */
/* @0x1ca25c mov r1, r9 */
/* @0x1ca260 ldr r2, [sp, #0x50] */
/* @0x1ca264 bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* ── 2.19 写失败（1ca268..1ca270）────────────────────────────────────────
 *   返回 0 → 1ca2bc 打错误串；成功 → Free(p)；两条路最后都回 1ca178 推进。
 */

/* @0x1ca268 cmp r0, #0 */
/* @0x1ca26c beq 0x1ca2bc <_Z13Command_UnzipPKcS0_iiPc+0x27c> */
/* @0x1ca270 mov r0, r9 */
/* @0x1ca274 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ca278 b 0x1ca178 <_Z13Command_UnzipPKcS0_iiPc+0x138> */
/* ── 2.20 收尾（1ca27c..1ca2b8）──────────────────────────────────────────
 *   zip_close → vtable+4 释放缓冲 → 取 [sp+0x1c] 当返回值 → 栈金丝雀 → 恢复 1160 B 帧。
 */

/* @0x1ca27c mov r0, r8 */
/* @0x1ca280 blx 0x2a31ec <zip_close> */
/* @0x1ca284 ldr r12, [sp, #0x28] */
/* @0x1ca288 ldr r3, [r12] */
/* @0x1ca28c mov r0, r12 */
/* @0x1ca290 ldr r3, [r3, #0x4] */
/* @0x1ca294 blx r3 */
/* @0x1ca298 ldr r0, [sp, #0x1c] */
/* @0x1ca29c ldr r12, [sp, #0x30] */
/* @0x1ca2a0 ldr r2, [sp, #0x45c] */
/* @0x1ca2a4 ldr r3, [r12] */
/* @0x1ca2a8 cmp r2, r3 */
/* @0x1ca2ac bne 0x1ca324 <_Z13Command_UnzipPKcS0_iiPc+0x2e4> */
/* @0x1ca2b0 add sp, sp, #1120 */
/* @0x1ca2b4 add sp, sp, #4 */
/* @0x1ca2b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 2.21 写失败的错误上报（1ca2bc..1ca2dc）──────────────────────────────
 *   r12 = PIC；r3 = *(GOT 0x3ed71c) = 0x3eb70c；r1 = [sp+0x3c]（"UNZIP: Failed to write…"）；
 *   对着 *(*(0x3eb70c)) 的 vtable 调 +0xc。调用后 b 1ca270 照常 Free。
 */

/* @0x1ca2bc ldr r12, [sp, #0x2c] */
/* @0x1ca2c0 ldr r3, [pc, #0x80] */
/* @0x1ca2c4 ldr r1, [sp, #0x3c] */
/* @0x1ca2c8 ldr r3, [r12, r3] */
/* @0x1ca2cc ldr r0, [r3] */
/* @0x1ca2d0 ldr r3, [r0] */
/* @0x1ca2d4 ldr r3, [r3, #0xc] */
/* @0x1ca2d8 blx r3 */
/* @0x1ca2dc b 0x1ca270 <_Z13Command_UnzipPKcS0_iiPc+0x230> */
/* ── 2.22 打开失败的错误上报（1ca2e0..1ca320）────────────────────────────
 *   释放缓冲 → 同一个对象收 "Unable to open %s for decompression\n" + zipPath（1ca2f8 的 r2 = r4）
 *   → mov r0,r8(=0) 跳公共收尾。
 */

/* @0x1ca2e0 ldr r12, [sp, #0x28] */
/* @0x1ca2e4 ldr r3, [r12] */
/* @0x1ca2e8 mov r0, r12 */
/* @0x1ca2ec ldr r3, [r3, #0x4] */
/* @0x1ca2f0 blx r3 */
/* @0x1ca2f4 ldr r12, [sp, #0x2c] */
/* @0x1ca2f8 ldr r3, [pc, #0x48] */
/* @0x1ca2fc mov r2, r4 */
/* @0x1ca300 ldr r1, [pc, #0x44] */
/* @0x1ca304 ldr r3, [r12, r3] */
/* @0x1ca308 add r1, pc, r1 */
/* @0x1ca30c ldr r0, [r3] */
/* @0x1ca310 ldr r3, [r0] */
/* @0x1ca314 ldr r3, [r3, #0xc] */
/* @0x1ca318 blx r3 */
/* @0x1ca31c mov r0, r8 */
/* @0x1ca320 b 0x1ca29c <_Z13Command_UnzipPKcS0_iiPc+0x25c> */
/* ── 2.23 金丝雀（1ca324）───────────────────────────────────────────────── */

/* @0x1ca324 bl 0xb65d4 <__stack_chk_fail@plt> */
/* ── 2.24 池字 10 个（0x1ca328..0x1ca34c，非指令）─────────────────────────
 *   1ca328 0x00227bf8 → PIC 锚   1ca32c 0xffffbd00 → 0x3ed958（GOT，文件里是 0；运行时指向
 *     __stack_chk_guard —— 1ca078/1ca080 取初值存 [sp+0x45c]，收尾 1ca2a0..1ca2ac 比对）
 *   1ca330 0xffffbd60 → 0x3ed9b8 → 0x3eb788（IBuffer vtable 基址，+8 后写进 vptr）
 *   1ca334 0x00186c48 → "%s/%s"  1ca338 0x00186c3c → "jni/../jni/yoyo/../../../Files/Run/Run_Command.cpp"
 *   1ca33c 0x0018236c → "read underflow detected"   1ca340 0x00186c1c → "%s/%s"
 *   1ca344 0x00186c4c → "UNZIP: Failed to write compressed file entry :o"
 *   1ca348 0xffffbac4 → 0x3ed71c → 0x3eb70c（错误上报对象的间接格）
 *   1ca34c 0x00186a18 → "Unable to open %s for decompression\n"
 */

/* @0x1ca328 .word 0x00227bf8 */
/* @0x1ca32c .word 0xffffbd00 */
/* @0x1ca330 .word 0xffffbd60 */
/* @0x1ca334 andseq r6, r8, r8, asr #24 */
/* @0x1ca338 andseq r6, r8, r12, lsr r12 */
/* @0x1ca33c andseq r2, r8, r12, ror #6 */
/* @0x1ca340 andseq r6, r8, r12, lsl r12 */
/* @0x1ca344 andseq r6, r8, r12, asr #24 */
/* @0x1ca348 .word 0xffffbac4 */
/* @0x1ca34c andseq r6, r8, r8, lsl r10 */

/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 3 · Command_Bounce(CInstance* inst, bool advanced, bool solid)
 * @func 0x1cafa0 0x1cb234  size 660  165 锚点（163 条指令 + 2 个池字 0x1cb22c/0x1cb230）
 * 符号: _Z14Command_BounceP9CInstancebb
 * 调用者: F_MoveBounceSolid 0x10837c（尾跳，第三实参 0）、F_MoveBounceAll 0x1083a4（尾跳，第三实参 1）、
 *         F_ActionBounce 0x13dfec（尾跳，第三实参 = GML 的第二个 bool）
 * 同层: Bounce_Test 0x1caf90、Command_IsFree 0x1cab94、Command_IsEmpty 0x1caa1c、
 *       CInstance::SetPosition 0x193e7c、SetHspeed 0x1930f4、SetVspeed 0x193114、SetDirection 0x193064、
 *       cosf/sinf/lrint@plt
 * 一句话: 按 advanced 分两条路 —— false 沿 hspeed/vspeed 轴做四向探测、按命中组合取反速度；true 把
 *         direction 量化到 10° 后向两侧各扫 35 步（合计 350°），用 cos/sin 采样，最后用两个扫描终值与
 *         量化方向合成新 direction。
 * ═══════════════════════════════════════════════════════════════════════════
 */

/* ── 语义草案 ─────────────────────────────────────────────────────────────
 *   void Command_Bounce(CInstance* inst, bool advanced, bool solid) {
 *     if (!Bounce_Test(inst, x, y, solid)) {           // 1cafc0；非 0 = 空，0 = 撞
 *        SetPosition(inst, xprevious, yprevious);      // 1cb1cc（0x193e7c）
 *        stepped = 1;                                  // r7 = 1
 *     } else stepped = 0;
 *     h = inst->hspeed(+0xe0); v = inst->vspeed(+0xe4); x = inst->x; y = inst->y;   // 1cafd4..1cafd8
 *     if (!advanced) {                                  // 1cafdc beq 1cb104
 *        Th  = Bounce_Test(x + h, y,        solid);    // 1cb11c → r5
 *        Tv  = Bounce_Test(x,     y + v,    solid);    // 1cb140 → r7
 *        Thv = Bounce_Test(x + h, y + v,    solid);    // 1cb170 → r0
 *        ... 见「四向判定表」...
 *     } else {                                          // 1cafe0 起
 *        base = lrint(direction / 10) * 10;            // 1cb000..1cb010 → s24
 *        for (k = 1; k <= 35; k++) {                   // scan1：base - 10k
 *           if (Bounce_Test(x + spd*cos(a), y - spd*sin(a), solid) != 0) break;
 *           r7 = 1;
 *        }
 *        for (m = 1; m <= 35; m++) {                   // scan2：base + 10m
 *           if (Bounce_Test(...) != 0) break;
 *           r7 = 1;
 *        }
 *        if (!r7) return;                              // 1cb0f4
 *        SetDirection(inst, a1 + a2 + 180 - base);     // 1cb1f0..1cb210（0x193064）
 *     }
 *   }
 *
 * ── 帧与实参 ─────────────────────────────────────────────────────────────
 *   push {r3,r4,r5,r6,r7,lr}（24 B）+ vpush {d8..d13}（48 B）= 72 B，无 sub sp。
 *   r4 = inst、r5 = advanced（1cafb0）、r6 = solid（1cafac，同时当 r3 传给 Bounce_Test）。
 *   s20 = y、s21 = x（1cafd4/1cafd8，**在可能的回退之后**重读）；s24 = 量化方向；s23 = 180、s25 = pi。
 *   r7 复用两次：入口是「回退过」标志（1cafc8/1cb1c4），进了扫描段后变成「采到过碰撞样本」标志。
 *
 * ── 谓词选择（Bounce_Test 0x1caf90，4 条）────────────────────────────────
 *   solid != 0 → Command_IsEmpty(inst,x,y) 0x1caa1c；solid == 0 → Command_IsFree(inst,x,y) 0x1cab94。
 *   两者都是「把实例挪到 (x,y) 试一次再挪回」，返回值 **非 0 = 空/自由**（IsFree 的 1cac98 mov r4,#1 与
 *   1cacfc mov r4,#0 两条路径直接决定 r0）。⇒ IsFree 只看 +0x66（solid 位），IsEmpty 看所有实例。
 *
 * ── 四向判定表（advanced == 0；Th=+0xe0 方向、Tv=+0xe4 方向、Thv=两者同时；非 0 = 空）──────
 *   Th    Tv    Thv   动作                                        指令
 *   0     0     —     取反 h **和** v（掉头）                      1cb184 → 1cb1dc → 1cb1a4
 *   ≠0    ≠0    ≠0    什么都不做（三条都通）                        1cb190 → 1cb1d8 → 1cb0fc
 *   ≠0    ≠0    0     取反 h 和 v（只有斜向堵）                     1cb190 → 1cb1d4 → 1cb1dc
 *   0     ≠0    —     只取反 h                                     1cb198 → 1cb214（尾跳 SetHspeed）
 *   ≠0    0     —     只取反 v                                     1cb19c → 1cb1a4（尾跳 SetVspeed）
 *   ★ 取反 = 把 float 的符号位异或 1（1cb1b4/1cb1e4/1cb224 的 eor r1,r1,#-2147483648）。
 *   ★ 「掉头」与「只取反 h」的区别只在有没有接着执行 1cb1a4：1cb1dc 打完 SetHspeed 后**落下**到 1cb1a4
 *     再打 SetVspeed；1cb214 是尾跳，只打 SetHspeed。这是本卡最容易读错的一处。
 *
 * ── 35 步角度扫描（advanced != 0）───────────────────────────────────────
 *   量化：s15 = direction / 10（1caff4 除以 vmov 的 10.0）→ vcvt.f64.f32 → lrint（1cb000）→ vcvt.f32.s32
 *        → 乘 10（1cb010）⇒ base 是 10° 的整数倍；s24 = base，s16 = base。
 *   scan1（1cb028..1cb078）：每轮先 s16 -= 10 再采样；样本 = (x + spd*cos, y - spd*sin)，spd = +0xd0，
 *        角度先 ×pi/180（1cb030/1cb034）；Bounce_Test 返回 0（撞）就再减一次，返回非 0（空）就跳出；
 *        r5 从 35 递减，减到 0 也跳出（1cb01c..1cb024）。
 *   scan2（1cb0a0..1cb0f0）：s17 = base，每轮 +10，其余同构；出口 1cb094..1cb09c 与 1cb0ec..1cb0f0。
 *   合成（1cb1f0..1cb204）：s16 + s17 → +180.0 → -s24 → SetDirection。
 *   ⇒ 若两段都扫满 35 次，s16 = base-350、s17 = base+350，新方向 = base + 180（纯反向）；
 *     若 scan1 第 k 次就空、scan2 第 m 次就空，新方向 = base + 10*(m-k) + 180。
 *
 * ── 失败/早退路径 ───────────────────────────────────────────────────────
 *   ① 入口就空（T0 != 0）→ 不回退，r7 = 0（1cafc8）。
 *   ② 四向：三条都空 → 1cb0fc 的 vpop+pop 直接返回，一个字段都不写。
 *   ③ 扫描：两段都没撞到过（r7 == 0）→ 1cb0f4 bne 不成立 → 1cb0fc 返回，不写 direction。
 *   ④ 扫描：至少撞到过 → 一定走 SetDirection（1cb210 尾跳），不碰 hspeed/vspeed。
 *   ⇒ 两条路互斥：advanced 只决定「取反 h/v」还是「重算 direction」，不会两者都做。
 *
 * ── 已证（指令级）───────────────────────────────────────────────────────
 *  1. 35 是硬编码（1cafe8/1cb080 的 mov r5,#35），每轮减 1，最多 35 个样本 = 350°，差 10° 不满一圈。
 *  2. 池常量：1cb22c = 0x40490fdb = pi(float)、1cb230 = 0x43340000 = 180.0f；10.0 走 vmov 立即数
 *     （1cafe0 与 1cb07c）。两者都是「像指令」的池字，非指令。
 *  3. 量化用 lrint 而不是截断：1cb000 bl lrint、1cb008 vmov s13,r0、1cb00c vcvt.f32.s32、1cb010 vmul。
 *  4. 采样用 vmla/vmls 合成：x 加 spd*cos（1cb058/1cb0d0 的 vmla），y 减 spd*sin（1cb068/1cb0e0 的 vmls）
 *     ⇒ 方向角 0 = +x、90 = -y（GM 的屏幕坐标约定）。
 *  5. 四向分支全程不碰 +0xcc/+0xd0（无一条 ldr/str 落在这两格）；扫描分支只读这两格 + 末尾写 +0xcc。
 *  6. 四个 setter 的调用形状：SetPosition 0x193e7c 是 bl（1cb1cc，要回来继续）；SetHspeed 两处 ——
 *     1cb1e8 是 bl（打完还要落到 1cb1a4 反 v）、1cb228 是 b 尾跳（只反 h）；SetVspeed 1cb1b8 与
 *     SetDirection 1cb210 都是 b 尾跳。
 *  7. 所有出口都先 vpop {d8..d13} 再 pop {r3,r4,r5,r6,r7,pc}，无栈帧残留；函数无返回值（void）。
 *
 * ── open（本卡不解）────────────────────────────────────────────────────
 *   · IsFree/IsEmpty 的内部碰撞判据（0x1cab94/0x1caa1c）：本卡只用它们的返回寄存器定极性。
 *   · 合成公式的几何含义（是否为「以可行窗口中心为法线的反射」）：本卡只证算术，不证几何解释。
 *   · +0xcc/+0xd0 与 +0xe0/+0xe4 的同步关系由 SetHspeed/SetVspeed/SetDirection 维护，不在本索引。
 */

/* ── 3.1 入口（1cafa0..1cafac）───────────────────────────────────────────
 *   r4=inst、r5=advanced、r6=solid；r2 同时抄给 r3（Bounce_Test 的第 4 实参）。
 */

/* @0x1cafa0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1cafa4 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x1cafa8 mov r3, r2 */
/* @0x1cafac mov r6, r2 */
/* @0x1cafb0 mov r5, r1 */
/* ── 3.2 入口探测 T0（1cafb4..1cafc0）────────────────────────────────────
 *   Bounce_Test(inst, [0xb4]=x, [0xb8]=y, solid)；返回非 0 = 空。
 */

/* @0x1cafb4 ldr r2, [r0, #0xb8] */
/* @0x1cafb8 mov r4, r0 */
/* @0x1cafbc ldr r1, [r0, #0xb4] */
/* @0x1cafc0 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* ── 3.3 入口分流（1cafc4..1cafcc）────────────────────────────────────────
 *   T0!=0 → r7=0（不回退）；T0==0 → 1cb1bc 回退到 (xprevious,yprevious) 并 r7=1。
 */

/* @0x1cafc4 cmp r0, #0 */
/* @0x1cafc8 movne r7, #0 */
/* @0x1cafcc beq 0x1cb1bc <_Z14Command_BounceP9CInstancebb+0x21c> */
/* ── 3.4 重读 x,y（1cafd0..1cafd8）───────────────────────────────────────
 *   回退分支 b 回 1cafd0，所以 s21/s20 拿到的是**回退后**的坐标。
 */

/* @0x1cafd0 cmp r5, #0 */
/* @0x1cafd4 vldr s21, [r4, #180] */
/* @0x1cafd8 vldr s20, [r4, #184] */
/* @0x1cafdc beq 0x1cb104 <_Z14Command_BounceP9CInstancebb+0x164> */
/* ── 3.5 扫描段的量化（1cafe0..1cb018）───────────────────────────────────
 *   direction/10 → lrint → *10 = base（s24）；s16 = base 当 scan1 游标；s22 = 10.0。
 *   池字 1cb22c = pi、1cb230 = 180.0 在这里装入 s25/s23。
 */

/* @0x1cafe0 vmov.f32 s16, #1.000000e+01 */
/* @0x1cafe4 vldr s15, [r4, #204] */
/* @0x1cafe8 mov r5, #35 */
/* @0x1cafec vldr s25, [pc, #568] */
/* @0x1caff0 vldr s23, [pc, #568] */
/* @0x1caff4 vdiv.f32 s15, s15, s16 */
/* @0x1caff8 vcvt.f64.f32 d6, s15 */
/* @0x1caffc vmov r0, r1, d6 */
/* @0x1cb000 bl 0xb66e8 <lrint@plt> */
/* @0x1cb004 vmov.f32 s22, s16 */
/* @0x1cb008 vmov s13, r0 */
/* @0x1cb00c vcvt.f32.s32 s24, s13 */
/* @0x1cb010 vmul.f32 s24, s24, s16 */
/* @0x1cb014 vmov.f32 s16, s24 */
/* @0x1cb018 b 0x1cb028 <_Z14Command_BounceP9CInstancebb+0x88> */
/* @0x1cb01c subs r5, r5, #1 */
/* @0x1cb020 mov r7, #1 */
/* @0x1cb024 beq 0x1cb07c <_Z14Command_BounceP9CInstancebb+0xdc> */
/* ── 3.6 scan1 循环体（1cb028..1cb078）───────────────────────────────────
 *   s16 -= 10；样本 = (x + spd*cos(a), y - spd*sin(a))；返回 0 就继续减，非 0 跳出。
 */

/* @0x1cb028 vsub.f32 s16, s16, s22 */
/* @0x1cb02c vldr s17, [r4, #208] */
/* @0x1cb030 vmul.f32 s18, s16, s25 */
/* @0x1cb034 vdiv.f32 s18, s18, s23 */
/* @0x1cb038 vmov r0, s18 */
/* @0x1cb03c bl 0xb658c <cosf@plt> */
/* @0x1cb040 vmov s19, r0 */
/* @0x1cb044 vmov r0, s18 */
/* @0x1cb048 bl 0xb6580 <sinf@plt> */
/* @0x1cb04c vmov.f32 s14, s21 */
/* @0x1cb050 mov r3, r6 */
/* @0x1cb054 vmov.f32 s15, s20 */
/* @0x1cb058 vmla.f32 s14, s17, s19 */
/* @0x1cb05c vmov r1, s14 */
/* @0x1cb060 vmov s12, r0 */
/* @0x1cb064 mov r0, r4 */
/* @0x1cb068 vmls.f32 s15, s17, s12 */
/* @0x1cb06c vmov r2, s15 */
/* @0x1cb070 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* @0x1cb074 cmp r0, #0 */
/* @0x1cb078 beq 0x1cb01c <_Z14Command_BounceP9CInstancebb+0x7c> */
/* ── 3.7 scan2 起始（1cb07c..1cb0a0）────────────────────────────────────
 *   重新装 10.0/pi/180，s17 = s24（base），反向往 +10 扫。
 */

/* @0x1cb07c vmov.f32 s26, #1.000000e+01 */
/* @0x1cb080 mov r5, #35 */
/* @0x1cb084 vldr s25, [pc, #416] */
/* @0x1cb088 vldr s23, [pc, #416] */
/* @0x1cb08c vmov.f32 s17, s24 */
/* @0x1cb090 b 0x1cb0a0 <_Z14Command_BounceP9CInstancebb+0x100> */
/* @0x1cb094 subs r5, r5, #1 */
/* @0x1cb098 mov r7, #1 */
/* @0x1cb09c beq 0x1cb1f0 <_Z14Command_BounceP9CInstancebb+0x250> */
/* ── 3.8 scan2 循环体（1cb0a0..1cb0f0）─────────────────────────────────── */

/* @0x1cb0a0 vadd.f32 s17, s17, s26 */
/* @0x1cb0a4 vldr s18, [r4, #208] */
/* @0x1cb0a8 vmul.f32 s19, s17, s25 */
/* @0x1cb0ac vdiv.f32 s19, s19, s23 */
/* @0x1cb0b0 vmov r0, s19 */
/* @0x1cb0b4 bl 0xb658c <cosf@plt> */
/* @0x1cb0b8 vmov s22, r0 */
/* @0x1cb0bc vmov r0, s19 */
/* @0x1cb0c0 bl 0xb6580 <sinf@plt> */
/* @0x1cb0c4 vmov.f32 s13, s21 */
/* @0x1cb0c8 mov r3, r6 */
/* @0x1cb0cc vmov.f32 s15, s20 */
/* @0x1cb0d0 vmla.f32 s13, s18, s22 */
/* @0x1cb0d4 vmov r1, s13 */
/* @0x1cb0d8 vmov s14, r0 */
/* @0x1cb0dc mov r0, r4 */
/* @0x1cb0e0 vmls.f32 s15, s18, s14 */
/* @0x1cb0e4 vmov r2, s15 */
/* @0x1cb0e8 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* @0x1cb0ec cmp r0, #0 */
/* @0x1cb0f0 beq 0x1cb094 <_Z14Command_BounceP9CInstancebb+0xf4> */
/* ── 3.9 扫描收口判据（1cb0f4..1cb0fc）──────────────────────────────────
 *   r7 != 0（采到过碰撞样本）→ 1cb1f0 合成方向；r7 == 0 → 直接 vpop/pop 返回。
 */

/* @0x1cb0f4 cmp r7, #0 */
/* @0x1cb0f8 bne 0x1cb1f0 <_Z14Command_BounceP9CInstancebb+0x250> */
/* @0x1cb0fc vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1cb100 pop {r3, r4, r5, r6, r7, pc} */
/* ── 3.10 四向段入口（1cb104..1cb11c）────────────────────────────────────
 *   T1 = Test(x + hspeed, y)；h 取自 +0xe0（1cb104），y 取自 s20。
 */

/* @0x1cb104 vldr s15, [r4, #224] */
/* @0x1cb108 vadd.f32 s15, s21, s15 */
/* @0x1cb10c mov r3, r6 */
/* @0x1cb110 vmov r2, s20 */
/* @0x1cb114 mov r0, r4 */
/* @0x1cb118 vmov r1, s15 */
/* @0x1cb11c bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* ── 3.11 T2 = Test(x, y + vspeed)（1cb120..1cb140）────────────────────────
 *   vspeed 取自 +0xe4（1cb124）；结果在 1cb168 存进 r7。
 */

/* @0x1cb120 vldr s14, [r4, #184] */
/* @0x1cb124 vldr s15, [r4, #228] */
/* @0x1cb128 vadd.f32 s15, s14, s15 */
/* @0x1cb12c ldr r1, [r4, #0xb4] */
/* @0x1cb130 mov r3, r6 */
/* @0x1cb134 vmov r2, s15 */
/* @0x1cb138 mov r5, r0 */
/* @0x1cb13c mov r0, r4 */
/* @0x1cb140 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* ── 3.12 T3 = Test(x + h, y + v)（1cb144..1cb170）────────────────────────
 *   1cb148/1cb14c/1cb150/1cb154 四条 vldr+vadd 拼出 (x+h, y+v)，结果留在 r0。
 */

/* @0x1cb144 vldr s12, [r4, #180] */
/* @0x1cb148 vldr s13, [r4, #224] */
/* @0x1cb14c vldr s14, [r4, #184] */
/* @0x1cb150 vldr s15, [r4, #228] */
/* @0x1cb154 vadd.f32 s13, s12, s13 */
/* @0x1cb158 mov r3, r6 */
/* @0x1cb15c vadd.f32 s15, s14, s15 */
/* @0x1cb160 vmov r1, s13 */
/* @0x1cb164 vmov r2, s15 */
/* @0x1cb168 mov r7, r0 */
/* @0x1cb16c mov r0, r4 */
/* @0x1cb170 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* ── 3.13 四向判定（1cb174..1cb1a0）──────────────────────────────────────
 *   1cb174..1cb184：!(Tv) & !(Th) → 掉头；1cb188..1cb190：Tv & Th → 看 Thv；
 *   1cb194..1cb198：Th==0 → 只反 h；1cb19c..1cb1a0：Tv!=0 → 返回，否则只反 v。
 */

/* @0x1cb174 eor r2, r7, #1 */
/* @0x1cb178 eor r3, r5, #1 */
/* @0x1cb17c and r3, r2, r3 */
/* @0x1cb180 tst r3, #255 */
/* @0x1cb184 bne 0x1cb1dc <_Z14Command_BounceP9CInstancebb+0x23c> */
/* @0x1cb188 and r3, r7, r5 */
/* @0x1cb18c tst r3, #255 */
/* @0x1cb190 bne 0x1cb1d4 <_Z14Command_BounceP9CInstancebb+0x234> */
/* @0x1cb194 cmp r5, #0 */
/* @0x1cb198 beq 0x1cb214 <_Z14Command_BounceP9CInstancebb+0x274> */
/* @0x1cb19c cmp r7, #0 */
/* @0x1cb1a0 bne 0x1cb0fc <_Z14Command_BounceP9CInstancebb+0x15c> */
/* ── 3.14 反 v 并返回（1cb1a4..1cb1b8）───────────────────────────────────
 *   vpop → r1 = +0xe4 → eor 符号位 → 尾跳 SetVspeed。
 */

/* @0x1cb1a4 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1cb1a8 mov r0, r4 */
/* @0x1cb1ac ldr r1, [r4, #0xe4] */
/* @0x1cb1b0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1cb1b4 eor r1, r1, #-2147483648 */
/* @0x1cb1b8 b 0x193114 <_ZN9CInstance9SetVspeedEf> */
/* ── 3.15 回退（1cb1bc..1cb1d0）──────────────────────────────────────────
 *   SetPosition(inst, +0xc4, +0xc8) = (xprevious, yprevious)；r7=1；回 1cafd0 继续。
 */

/* @0x1cb1bc mov r0, r4 */
/* @0x1cb1c0 ldr r1, [r4, #0xc4] */
/* @0x1cb1c4 ldr r2, [r4, #0xc8] */
/* @0x1cb1c8 mov r7, #1 */
/* @0x1cb1cc bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cb1d0 b 0x1cafd0 <_Z14Command_BounceP9CInstancebb+0x30> */
/* ── 3.16 斜向堵（1cb1d4..1cb1d8）────────────────────────────────────────
 *   Thv != 0（斜向也空）→ 返回；Thv == 0 → 掉到 1cb1dc 掉头。
 */

/* @0x1cb1d4 cmp r0, #0 */
/* @0x1cb1d8 bne 0x1cb0fc <_Z14Command_BounceP9CInstancebb+0x15c> */
/* ── 3.17 反 h（并继续反 v）（1cb1dc..1cb1ec）─────────────────────────────
 *   SetHspeed(-hspeed) 是 bl，之后 b 1cb1a4 —— 所以这条路 h 和 v 都反。
 */

/* @0x1cb1dc ldr r1, [r4, #0xe0] */
/* @0x1cb1e0 mov r0, r4 */
/* @0x1cb1e4 eor r1, r1, #-2147483648 */
/* @0x1cb1e8 bl 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* @0x1cb1ec b 0x1cb1a4 <_Z14Command_BounceP9CInstancebb+0x204> */
/* ── 3.18 方向合成（1cb1f0..1cb210）──────────────────────────────────────
 *   s16 + s17 + 180.0 - s24 → SetDirection（尾跳 0x193064）。
 */

/* @0x1cb1f0 vadd.f32 s16, s16, s17 */
/* @0x1cb1f4 vldr s15, [pc, #52] */
/* @0x1cb1f8 mov r0, r4 */
/* @0x1cb1fc vadd.f32 s16, s16, s15 */
/* @0x1cb200 vsub.f32 s16, s16, s24 */
/* @0x1cb204 vmov r1, s16 */
/* @0x1cb208 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1cb20c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1cb210 b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* ── 3.19 只反 h（1cb214..1cb228）────────────────────────────────────────
 *   vpop → r1 = +0xe0 → eor → 尾跳 SetHspeed；与 1cb1dc 的差别就是不再落到反 v。
 */

/* @0x1cb214 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1cb218 mov r0, r4 */
/* @0x1cb21c ldr r1, [r4, #0xe0] */
/* @0x1cb220 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1cb224 eor r1, r1, #-2147483648 */
/* @0x1cb228 b 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* ── 3.20 池字 2 个（0x1cb22c/0x1cb230，非指令）──────────────────────────
 *   1cb22c 0x40490fdb = 3.14159274f（pi）；1cb230 0x43340000 = 180.0f。objdump 印成 ldrdmi/teqmi。
 */

/* @0x1cb22c ldrdmi r0, r1, [r9], #-251 */
/* @0x1cb230 teqmi r4, #0 */
