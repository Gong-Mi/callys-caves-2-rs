/* cally 逆向卡：InitYoYoFunctions（原版 libyoyo.so，armv7）
 * @func 0x15a0d0 0x15d0f8  size 12328  3082 条（2539 条指令 + 543 个池字，两段池）
 * 级别: 正文（3082/3082 逐条落锚；385 条 Function_Add 的 4 个实参全部从指令流 + .got 的 R_ARM_RELATIVE
 *       重定位逐条解出，名字串与目标 F_* 符号逐条互证；prologue 的 2 个 Mutex、3 个全局槽、尾调都钉住；
 *       open 只剩 4 条，均不改变本函数的控制流）
 * 符号: _Z17InitYoYoFunctionsv → void InitYoYoFunctions()
 * 位置: **InitGMLFunctions(0x2a297c) 的第 23 个 init 调用**（0x2a2bac bl 本函数），原序为
 *       HighScore_InitLoad → InitGame → InitMath → InitGraphic → InitAction → InitFile → InitResource →
 *       InitInteraction → Init3D → InitParticles → InitMisc → InitDataStructures → InitSound → InitPhysics →
 *       InitGamepad → InitBuffer → InitBufferVertex → InitNetworking → InitShader → InitVertexFormats →
 *       InitSteam → InitPush → **InitYoYo** → InitMetro → CLayerManager::InitLayerFunctions（每步前先向控制台虚表 +0xc
 *       打一行函数名）。本函数**尾调** InitJavaScriptFunctions(0x246fe0)，不 return。
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────────
 *   它只做一件事：把 **385 条**「平台/扩展层」GML 函数逐条 Function_Add 进全局内建表；
 *   其中 **195 条直接绑到 F_Platform_Function_Not_Supported(0x1563a0) 占位**（Android 版没实现）。
 *   **与 cards/Builtins_*.c 那 87 个「游戏真正调用的 builtin」交集 = 0** —— 那 87 个是 core GML 层，
 *   目标地址落在 0x0fec90..0x143ba8，本表落在 0x156030..0x159d04 + 占位 0x1563a0，两批名字与符号都不相交（§4）。
 *
 * ── Function_Add 的表项布局（本卡 385 条全部落到这套字段；0xcdf84 只引其写回点）──────────
 *   n = (*g_counter)++         ; entry = table + n*80            （0xcdfb4 ldr r5,[r4] / 0xcdfd0 str）
 *   memcpy(entry, name, strlen(name)+1)  → **name 内联在 +0x00..+0x3f（64 B，含结尾 NUL）**（strlen 0xcdfd4 / memcpy 0xcdff4）
 *   [entry+0x40] = fn    0xce014 str r9,[r0,#0x40]
 *   [entry+0x44] = argc  0xce018 str r8,[r0,#0x44]
 *   [entry+0x48] = flag  0xce01c strb r7,[r0,#0x48]   ← 第 4 个参数只按**字节**落盘
 *   [entry+0x4c] = -1    0xce020 str r2,[r0,#0x4c]（r2 = mvn #0）
 *   容量不够时 MemoryManager::SetLength(&table, (n+500)*80, "…")（0xce050）—— 一次加 500 项
 *   ⇒ 与 cards/DoCall.c 的 `entry = builtinTable + id*80`、`fn = [entry+0x40]` 是同一张表；
 *     也就是说本卡解的 4 个实参正好是表项里除名字外的 3 个字段 + 名字。
 *
 * ── 计数（逐条可复核；解算方式：asm/index-InitYoYoFunctions.tsv 的指令 + .rel.dyn 的 RELATIVE 加数）──
 *   385 条注册 = 385 个不同名字（无重名） = 152 个不同函数指针；40 个函数指针被 ≥2 个名字共用（共 273 条）
 *   argc: 1×148  0×100  2×60  3×38  4×19  5×6  6×3  7×3  8×1，另 **-1/0xffffffff×7**（变参）
 *   flag(bool, entry+0x48): 1×202 / 0×183；202 个 true 里 195 个正好是 Not_Supported 占位，
 *         剩下 7 个是真实现：cloud_file_save / cloud_string_save / cloud_synchronise / gml_release_mode /
 *         application_surface_{draw_,}enable / application_surface_is_enabled → flag 与 stub 高度相关但不等价（open 1）
 *   名字族: xboxone_* 65 / xboxlive_* 57 / YoYo_* 44 / psn_* 37 / achievement_* 22 / matchmaking_* 21 /
 *           winphone_* 18 / ads_* 14 / facebook_* 14 / device_* 13 / os_* 10 / uwp_* 9 / clickable_* 7 /
 *           openfeint_* 7 / display_* 6 / virtual_* 4 / url_* 4 / application_* 4 / video_* 4 / cloud_* 3 /
 *           md5_* 3 / sha1_* 3 / yyg_* 3 / base64_* 2 / analytics_* 2 / extension_* 2 / ps4_* 2 /
 *           shop_* 1 / get_* 1 / code_* 1 / window_* 1 / gml_* 1（合计 32 族，无「无下划线」名）
 *   同实体两名（YoYo_ 旧名 + GML 小写名）例：YoYo_AddVirtualKey 与 virtual_key_add 同上 0x1563bc；
 *      YoYo_PostAchievement 与 achievement_post 同上 0x1590f4；openfeint_* 7 个与 YoYo_OF_* 7 个一一对上。
 *
 * ── 分段（地址即锚点）─────────────────────────────────────────────────────
 *   §0 0x15a0d0..0x15a150  前置：帧 28 B；2 个 Mutex（「comsachievementcache」/「comsgmlcallbacks」）→
 *                          g_pComsMutex / 0x484a70；g_pAchievementCache_First = NULL；
 *                          UpdateCache(1,NULL,0)；InitIAPFunctions()；InitYoYoFunctionsM()
 *   §1 0x15a154..0x15b0d4  注册块 1：#0..#141（142 条，其中 #141 的 bl 在池后）
 *   §池1 0x15b0dc..0x15b810 462 个字面量（块 1 前向引用 253 处、块 2 反向引用 209 处；全部被引用，无空洞）
 *   §2 0x15b814..0x15cfa4  注册块 2：#141 的 bl + #142..#384（243 条）
 *   §3 0x15cfa8..0x15cfb0  弹栈 + 尾调 InitJavaScriptFunctions
 *   §池2 0x15cfb4..0x15d0f4 81 个字面量
 *
 * ── 已证的硬事实（可直接引用）───────────────────────────────────────────────
 *   1. 385 条 Function_Add，名字串全部在 .rodata（0x3317a3..0x3490e8），函数指针全部经 GOT 取（r6/r10 = 0x3f1c58，
 *      负偏移 -0x208c..-0x1e00，154 个字面量对应 152 个函数；9 条先溢出到 sp 再取回）；**没有一条**是把地址
 *      立即数直接填进 r1 的。
 *   2. 表项 80 B：name 内联 64 B / +0x40 fn / +0x44 argc / +0x48 flag(byte) / +0x4c -1；
 *      与 DoCall 的 id*80 索引一致 —— 所以本函数的注册顺序**就是** id 顺序（id = 注册时的计数器值）。
 *   3. argc 的语义按 GML 侧口径直接落盘：0 参 100 条、1 参 148 条；7 条 argc = -1 是变参
 *      （analytics_event_ext / winphone_tile_cycle_images / xboxone_fire_event / xboxone_get_stats_for_user /
 *       xboxlive_gamertag_for_user / xboxlive_fire_event / xboxlive_get_stats_for_user）。
 *   4. 195 条 Not_Supported 全都是 flag=1；反过来 flag=1 的 202 条里 195 条是 Not_Supported（另 7 条见上）。
 *   5. 前置里的两个 Mutex 是本函数自己 new 出来的（不是取现成对象），名字串决定用途：
 *      「comsachievementcache」→ g_pComsMutex，「comsgmlcallbacks」→ 0x484a70（dynsym 无名静态槽）。
 *   6. 本函数不返回：尾调 InitJavaScriptFunctions —— 也就是说 JS 函数表在 YoYo 表之后才装。
 *   7. 解码自证：190 条真实现里 **189 条**的 GML 名与目标 F_* 符号词级一一对应（addvirtualkey ↔ AddVirtualKey、
 *      gettiltx ↔ GetTiltX、ospauseevent ↔ OSPauseEvent…）；唯一例外 os_is_paused → F_YoYo_OSPauseEvent，
 *      而 .bss 里确有 g_OSPauseEvent(0x484aad)，属命名不同而非解错 —— 385 条 (name, fn) 无漂移。
 *
 * ── open ─────────────────────────────────────────────────────────────────
 *   1. flag(第 4 参) 的真实语义：与「未实现占位」强相关（195/202），但有 7 条真实现也为 1，
 *      单靠静态看不出是「stub 标记」「不进 GML 全局命名空间」还是「no-copy 返回值」。
 *   2. 这 385 条在**全局**内建表里的 id 区间：id = Function_Add 被调用时的计数器值，取决于之前装了多少条
 *      （InitIAPFunctions/InitMetroFunctions 等也调 Function_Add），本卡只证「连续 385 个 id、按 §1→§2 顺序」。
 *   3. InitIAPFunctions(0x1534d4) 内部注册了哪些（它是紧邻的另一个 12KB 级 init，不在本卡范围）。
 *   4. card 之外：core GML 那 87 个 builtin 由**兄弟 init** 注册 —— 它们全在 InitGMLFunctions(0x2a297c) 的 25 个
 *      调用里（InitGame 0x10c7d8 / InitMath 0x111c5c / InitGraphic 0x12326c / InitAction 0x141e60 /
 *      InitFile 0x13c4a0 / InitResource 0x130ffc / InitInteraction 0x1278c4 / Init3D 0x149f4c /
 *      InitParticles 0x129f74 / …），本函数只是第 23 个；具体哪一族装哪几条未逐条核。
 *      旁证：'instance_create'(0x338b10) 与 'draw_self'(0x33b530) 在 ldr 绝对字面量、add-pc 相对偏移、
 *      .text/.data/.data.rel.ro/.rodata 的 4 字节指针三条路径上均 0 命中 ⇒ 兄弟 init 不是逐串取址，
 *      疑似按 .rodata 里连续名字 blob 的游标顺序注册。
 */

/* ══ §0 前置 0x15a0d0..0x15a150（33 条）：2 个 Mutex + 3 个全局 + UpdateCache + 两个 init ══ */
/* @0x15a0d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 帧：push 9 个寄存器（r4..r11 + lr），随后 sub sp,#28；被调方只用 r4..r11 与 sp+0x0..0x1b 的溢出槽 */
/* @0x15a0d4 mov r0, #8 —— new 的 size 实参 = 8（Mutex 对象大小） */
/* @0x15a0d8 sub sp, sp, #28 —— 帧 28 B = 7 个 4 字节槽；其中 sp+0x4..sp+0x14（5 槽）被 9 条溢出指令复用 */
/* @0x15a0dc ldr r6, [pc, #0xff8] —— 池字 0x297b68 = GOT 基址增量 */
/* @0x15a0e0 bl 0x27c524 <_Znwj> —— operator new(8) → 第 1 个 Mutex 的裸内存（r0） */
/* @0x15a0e4 ldr r1, [pc, #0xff4] —— 串偏移（Mutex 名） */
/* @0x15a0e8 add r6, pc, r6 —— r6 = 0x15a0f0 + 0x297b68 = **0x3f1c58 = GOT 基址**（全函数 385 条函数指针都按 r6 + 负偏移取） */
/* @0x15a0ec mov r4, #0 —— r4 = 0：本函数里 flag 的默认值，也是「清零」用的常量 0 */
/* @0x15a0f0 add r1, pc, r1 —— r1 = 0x346b2c = "comsachievementcache" */
/* @0x15a0f4 mov r10, r6 —— r10 = r6：GOT 基址存进 r10（r6 之后要拿来装函数指针） */
/* @0x15a0f8 mov r5, r0 —— r5 = 新 Mutex */
/* @0x15a0fc bl 0x27e070 <_ZN5MutexC2EPKc> —— Mutex::Mutex(const char*) —— Mutex("comsachievementcache") */
/* @0x15a100 ldr r2, [pc, #0xfdc] —— GOT 偏移 -0x207c → 槽 0x3efbdc，内容 0x484a94 = &g_pComsMutex */
/* @0x15a104 mov r0, #8 —— 第 2 个 Mutex 的 size = 8 */
/* @0x15a108 ldr r3, [pc, #0xfd8] —— GOT 偏移 → 槽 0x3efbcc = &g_pAchievementCache_First（0x484aa4） */
/* @0x15a10c ldr r2, [r6, r2] —— r2 = 0x484a94 = &g_pComsMutex */
/* @0x15a110 str r5, [r2] —— **g_pComsMutex = 第 1 个 Mutex**（"comsachievementcache"） */
/* @0x15a114 ldr r3, [r6, r3] —— r3 = 0x484aa4 = &g_pAchievementCache_First */
/* @0x15a118 str r4, [r3] —— **g_pAchievementCache_First = NULL**：成就缓存链表头清空（r4 == 0） */
/* @0x15a11c bl 0x27c524 <_Znwj> —— operator new(8) → 第 2 个 Mutex */
/* @0x15a120 ldr r1, [pc, #0xfc4] —— 串偏移（第 2 个 Mutex 名） */
/* @0x15a124 add r1, pc, r1 —— r1 = 0x346b44 = "comsgmlcallbacks" */
/* @0x15a128 mov r5, r0 —— r5 = 第 2 个 Mutex */
/* @0x15a12c bl 0x27e070 <_ZN5MutexC2EPKc> —— Mutex::Mutex("comsgmlcallbacks") */
/* @0x15a130 ldr r3, [pc, #0xfb8] —— 池字 0x32a928 = pc 相对偏移（**不是** GOT 偏移：结果直指 .bss） */
/* @0x15a134 mov r1, r4 —— UpdateCache 的第 2 参 = 0 */
/* @0x15a138 mov r2, r4 —— UpdateCache 的第 3 参 = 0 */
/* @0x15a13c mov r0, #1 —— UpdateCache 的第 1 参 = 1（eCacheType 1） */
/* @0x15a140 add r3, pc, r3 —— r3 = 0x15a148 + 0x32a928 = 0x484a70（.bss 里的静态指针槽，dynsym 无名；紧邻 g_pPushHead 0x484a6c 之后） */
/* @0x15a144 str r5, [r3] —— *(0x484a70) = 第 2 个 Mutex（"comsgmlcallbacks" 的锁） */
/* @0x15a148 bl 0x159c88 <_Z11UpdateCache10eCacheTypePKcj> —— UpdateCache((eCacheType)1, NULL, 0) */
/* @0x15a14c bl 0x1534d4 <_Z16InitIAPFunctionsv> —— InitIAPFunctions()（内购族，另一张卡的范围） */
/* @0x15a150 bl 0x15e2a8 <_Z18InitYoYoFunctionsMv> —— InitYoYoFunctionsM() —— 名为 M，实为 0x15e2a8 的 3 条指令：AreOnlineAchievementsAvailable() 后尾调 Set_AchievementSystem()，**不注册任何函数** */

/* ══ §1 注册块 1：0x15a154..0x15b0d4（#0..#141，142 条；每条 6..8 条指令，6×233 / 7×111 / 8×41）══ */
/*   每条形态固定：
 *     ldr r1,[pc]  (GOT 偏移)   ldr r0,[pc]  (串偏移)   mov r3,r4(=0)/#1   mov r2,#argc
 *     ldr rX,[r6|r10, r1] (=fn)  add r0,pc,r0 (=名字串)  mov r1,rX          bl Function_Add
 *   少数条目把 fn 先溢出到 sp+0x4..0x14（0x15ab2c..0x15ae1c 共 9 处），后面的条目用 ldr r1,[sp,#…] 复用。
 */

/* ── #0 · 0x15a154..0x15a170 · YoYo_AddVirtualKey → F_IO_AddVirtualKey (0x1563bc) · argc=5 · flag=0 ── */
/* @0x15a154 ldr r1, [pc, #0xf98] —— 池字 0xffffdfa4：GOT 偏移 -0x205c → 槽 0x3efbfc = 0x1563bc <F_IO_AddVirtualKey> */
/* @0x15a158 ldr r0, [pc, #0xf98] —— 池字 0x1ec9e8：串偏移 → 0x346b58 "YoYo_AddVirtualKey" */
/* @0x15a15c mov r3, r4 —— flag = 0 */
/* @0x15a160 mov r2, #5 —— argc = 5 */
/* @0x15a164 ldr r8, [r6, r1] —— r8 = *(槽 0x3efbfc) = 0x1563bc <F_IO_AddVirtualKey> */
/* @0x15a168 add r0, pc, r0 —— r0 = 0x346b58 = "YoYo_AddVirtualKey" */
/* @0x15a16c mov r1, r8 —— r1 = fn = 0x1563bc <F_IO_AddVirtualKey> */
/* @0x15a170 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_AddVirtualKey", 0x1563bc <F_IO_AddVirtualKey>, 5, 0) */
/* ── #1 · 0x15a174..0x15a190 · YoYo_DeleteVirtualKey → F_IO_DeleteVirtualKey (0x156564) · argc=1 · flag=0 ── */
/* @0x15a174 ldr r1, [pc, #0xf80] —— 池字 0xffffdfa8：GOT 偏移 -0x2058 → 槽 0x3efc00 = 0x156564 <F_IO_DeleteVirtualKey> */
/* @0x15a178 ldr r0, [pc, #0xf80] —— 池字 0x1ec9dc：串偏移 → 0x346b6c "YoYo_DeleteVirtualKey" */
/* @0x15a17c mov r3, r4 —— flag = 0 */
/* @0x15a180 mov r2, #1 —— argc = 1 */
/* @0x15a184 ldr r7, [r6, r1] —— r7 = *(槽 0x3efc00) = 0x156564 <F_IO_DeleteVirtualKey> */
/* @0x15a188 add r0, pc, r0 —— r0 = 0x346b6c = "YoYo_DeleteVirtualKey" */
/* @0x15a18c mov r1, r7 —— r1 = fn = 0x156564 <F_IO_DeleteVirtualKey> */
/* @0x15a190 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_DeleteVirtualKey", 0x156564 <F_IO_DeleteVirtualKey>, 1, 0) */
/* ── #2 · 0x15a194..0x15a1b0 · YoYo_ShowVirtualKey → F_IO_ShowVirtualKey (0x15648c) · argc=1 · flag=0 ── */
/* @0x15a194 ldr r1, [pc, #0xf68] —— 池字 0xffffdfac：GOT 偏移 -0x2054 → 槽 0x3efc04 = 0x15648c <F_IO_ShowVirtualKey> */
/* @0x15a198 ldr r0, [pc, #0xf68] —— 池字 0x1ec9d4：串偏移 → 0x346b84 "YoYo_ShowVirtualKey" */
/* @0x15a19c mov r3, r4 —— flag = 0 */
/* @0x15a1a0 mov r2, #1 —— argc = 1 */
/* @0x15a1a4 ldr r6, [r6, r1] —— r6 = *(槽 0x3efc04) = 0x15648c <F_IO_ShowVirtualKey> */
/* @0x15a1a8 add r0, pc, r0 —— r0 = 0x346b84 = "YoYo_ShowVirtualKey" */
/* @0x15a1ac mov r1, r6 —— r1 = fn = 0x15648c <F_IO_ShowVirtualKey> */
/* @0x15a1b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_ShowVirtualKey", 0x15648c <F_IO_ShowVirtualKey>, 1, 0) */
/* ── #3 · 0x15a1b4..0x15a1d0 · YoYo_HideVirtualKey → F_IO_HideVirtualKey (0x1564f8) · argc=1 · flag=0 ── */
/* @0x15a1b4 ldr r1, [pc, #0xf50] —— 池字 0xffffdfb0：GOT 偏移 -0x2050 → 槽 0x3efc08 = 0x1564f8 <F_IO_HideVirtualKey> */
/* @0x15a1b8 ldr r0, [pc, #0xf50] —— 池字 0x1ec9c8：串偏移 → 0x346b98 "YoYo_HideVirtualKey" */
/* @0x15a1bc mov r3, r4 —— flag = 0 */
/* @0x15a1c0 mov r2, #1 —— argc = 1 */
/* @0x15a1c4 ldr r5, [r10, r1] —— r5 = *(槽 0x3efc08) = 0x1564f8 <F_IO_HideVirtualKey> */
/* @0x15a1c8 add r0, pc, r0 —— r0 = 0x346b98 = "YoYo_HideVirtualKey" */
/* @0x15a1cc mov r1, r5 —— r1 = fn = 0x1564f8 <F_IO_HideVirtualKey> */
/* @0x15a1d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_HideVirtualKey", 0x1564f8 <F_IO_HideVirtualKey>, 1, 0) */
/* ── #4 · 0x15a1d4..0x15a1e8 · virtual_key_add → F_IO_AddVirtualKey (0x1563bc) · argc=5 · flag=0 ── */
/* @0x15a1d4 ldr r0, [pc, #0xf38] —— 池字 0x1ec9c4：串偏移 → 0x346bac "virtual_key_add" */
/* @0x15a1d8 mov r1, r8 —— r1 = fn = 0x1563bc <F_IO_AddVirtualKey> */
/* @0x15a1dc mov r3, r4 —— flag = 0 */
/* @0x15a1e0 add r0, pc, r0 —— r0 = 0x346bac = "virtual_key_add" */
/* @0x15a1e4 mov r2, #5 —— argc = 5 */
/* @0x15a1e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("virtual_key_add", 0x1563bc <F_IO_AddVirtualKey>, 5, 0) */
/* ── #5 · 0x15a1ec..0x15a200 · virtual_key_delete → F_IO_DeleteVirtualKey (0x156564) · argc=1 · flag=0 ── */
/* @0x15a1ec ldr r0, [pc, #0xf24] —— 池字 0x1ec9bc：串偏移 → 0x346bbc "virtual_key_delete" */
/* @0x15a1f0 mov r1, r7 —— r1 = fn = 0x156564 <F_IO_DeleteVirtualKey> */
/* @0x15a1f4 mov r3, r4 —— flag = 0 */
/* @0x15a1f8 add r0, pc, r0 —— r0 = 0x346bbc = "virtual_key_delete" */
/* @0x15a1fc mov r2, #1 —— argc = 1 */
/* @0x15a200 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("virtual_key_delete", 0x156564 <F_IO_DeleteVirtualKey>, 1, 0) */
/* ── #6 · 0x15a204..0x15a218 · virtual_key_show → F_IO_ShowVirtualKey (0x15648c) · argc=1 · flag=0 ── */
/* @0x15a204 ldr r0, [pc, #0xf10] —— 池字 0x1ec9b8：串偏移 → 0x346bd0 "virtual_key_show" */
/* @0x15a208 mov r1, r6 —— r1 = fn = 0x15648c <F_IO_ShowVirtualKey> */
/* @0x15a20c mov r3, r4 —— flag = 0 */
/* @0x15a210 add r0, pc, r0 —— r0 = 0x346bd0 = "virtual_key_show" */
/* @0x15a214 mov r2, #1 —— argc = 1 */
/* @0x15a218 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("virtual_key_show", 0x15648c <F_IO_ShowVirtualKey>, 1, 0) */
/* ── #7 · 0x15a21c..0x15a230 · virtual_key_hide → F_IO_HideVirtualKey (0x1564f8) · argc=1 · flag=0 ── */
/* @0x15a21c ldr r0, [pc, #0xefc] —— 池字 0x1ec9b4：串偏移 → 0x346be4 "virtual_key_hide" */
/* @0x15a220 mov r1, r5 —— r1 = fn = 0x1564f8 <F_IO_HideVirtualKey> */
/* @0x15a224 mov r3, r4 —— flag = 0 */
/* @0x15a228 add r0, pc, r0 —— r0 = 0x346be4 = "virtual_key_hide" */
/* @0x15a22c mov r2, #1 —— argc = 1 */
/* @0x15a230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("virtual_key_hide", 0x1564f8 <F_IO_HideVirtualKey>, 1, 0) */
/* ── #8 · 0x15a234..0x15a250 · YoYo_LoginAchievements → F_YoYo_LoginAchievements (0x1565b4) · argc=0 · flag=0 ── */
/* @0x15a234 ldr r1, [pc, #0xee8] —— 池字 0xffffdfb4：GOT 偏移 -0x204c → 槽 0x3efc0c = 0x1565b4 <F_YoYo_LoginAchievements> */
/* @0x15a238 ldr r0, [pc, #0xee8] —— 池字 0x1ec9a8：串偏移 → 0x346bf8 "YoYo_LoginAchievements" */
/* @0x15a23c mov r2, r4 —— argc = 0 */
/* @0x15a240 mov r3, r4 —— flag = 0 */
/* @0x15a244 ldr r6, [r10, r1] —— r6 = *(槽 0x3efc0c) = 0x1565b4 <F_YoYo_LoginAchievements> */
/* @0x15a248 add r0, pc, r0 —— r0 = 0x346bf8 = "YoYo_LoginAchievements" */
/* @0x15a24c mov r1, r6 —— r1 = fn = 0x1565b4 <F_YoYo_LoginAchievements> */
/* @0x15a250 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_LoginAchievements", 0x1565b4 <F_YoYo_LoginAchievements>, 0, 0) */
/* ── #9 · 0x15a254..0x15a270 · YoYo_LogoutAchievements → F_YoYo_LogoutAchievements (0x1565b8) · argc=0 · flag=0 ── */
/* @0x15a254 ldr r1, [pc, #0xed0] —— 池字 0xffffdfb8：GOT 偏移 -0x2048 → 槽 0x3efc10 = 0x1565b8 <F_YoYo_LogoutAchievements> */
/* @0x15a258 ldr r0, [pc, #0xed0] —— 池字 0x1ec9a0：串偏移 → 0x346c10 "YoYo_LogoutAchievements" */
/* @0x15a25c mov r2, r4 —— argc = 0 */
/* @0x15a260 mov r3, r4 —— flag = 0 */
/* @0x15a264 ldr r5, [r10, r1] —— r5 = *(槽 0x3efc10) = 0x1565b8 <F_YoYo_LogoutAchievements> */
/* @0x15a268 add r0, pc, r0 —— r0 = 0x346c10 = "YoYo_LogoutAchievements" */
/* @0x15a26c mov r1, r5 —— r1 = fn = 0x1565b8 <F_YoYo_LogoutAchievements> */
/* @0x15a270 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_LogoutAchievements", 0x1565b8 <F_YoYo_LogoutAchievements>, 0, 0) */
/* ── #10 · 0x15a274..0x15a290 · YoYo_PostAchievement → F_YoYo_PostAchievement (0x1590f4) · argc=2 · flag=0 ── */
/* @0x15a274 ldr r1, [pc, #0xeb8] —— 池字 0xffffdfbc：GOT 偏移 -0x2044 → 槽 0x3efc14 = 0x1590f4 <F_YoYo_PostAchievement> */
/* @0x15a278 ldr r0, [pc, #0xeb8] —— 池字 0x1ec998：串偏移 → 0x346c28 "YoYo_PostAchievement" */
/* @0x15a27c mov r3, r4 —— flag = 0 */
/* @0x15a280 mov r2, #2 —— argc = 2 */
/* @0x15a284 ldr r7, [r10, r1] —— r7 = *(槽 0x3efc14) = 0x1590f4 <F_YoYo_PostAchievement> */
/* @0x15a288 add r0, pc, r0 —— r0 = 0x346c28 = "YoYo_PostAchievement" */
/* @0x15a28c mov r1, r7 —— r1 = fn = 0x1590f4 <F_YoYo_PostAchievement> */
/* @0x15a290 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_PostAchievement", 0x1590f4 <F_YoYo_PostAchievement>, 2, 0) */
/* ── #11 · 0x15a294..0x15a2b0 · YoYo_PostScore → F_YoYo_PostScore (0x159254) · argc=2 · flag=0 ── */
/* @0x15a294 ldr r1, [pc, #0xea0] —— 池字 0xffffdfc0：GOT 偏移 -0x2040 → 槽 0x3efc18 = 0x159254 <F_YoYo_PostScore> */
/* @0x15a298 ldr r0, [pc, #0xea0] —— 池字 0x1ec990：串偏移 → 0x346c40 "YoYo_PostScore" */
/* @0x15a29c mov r3, r4 —— flag = 0 */
/* @0x15a2a0 mov r2, #2 —— argc = 2 */
/* @0x15a2a4 ldr r8, [r10, r1] —— r8 = *(槽 0x3efc18) = 0x159254 <F_YoYo_PostScore> */
/* @0x15a2a8 add r0, pc, r0 —— r0 = 0x346c40 = "YoYo_PostScore" */
/* @0x15a2ac mov r1, r8 —— r1 = fn = 0x159254 <F_YoYo_PostScore> */
/* @0x15a2b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_PostScore", 0x159254 <F_YoYo_PostScore>, 2, 0) */
/* ── #12 · 0x15a2b4..0x15a2d0 · YoYo_AchievementsAvailable → F_YoYo_AchievementsAvailable (0x156030) · argc=0 · flag=0 ── */
/* @0x15a2b4 ldr r1, [pc, #0xe88] —— 池字 0xffffdfc4：GOT 偏移 -0x203c → 槽 0x3efc1c = 0x156030 <F_YoYo_AchievementsAvailable> */
/* @0x15a2b8 ldr r0, [pc, #0xe88] —— 池字 0x1ec980：串偏移 → 0x346c50 "YoYo_AchievementsAvailable" */
/* @0x15a2bc mov r2, r4 —— argc = 0 */
/* @0x15a2c0 mov r3, r4 —— flag = 0 */
/* @0x15a2c4 ldr r9, [r10, r1] —— r9 = *(槽 0x3efc1c) = 0x156030 <F_YoYo_AchievementsAvailable> */
/* @0x15a2c8 add r0, pc, r0 —— r0 = 0x346c50 = "YoYo_AchievementsAvailable" */
/* @0x15a2cc mov r1, r9 —— r1 = fn = 0x156030 <F_YoYo_AchievementsAvailable> */
/* @0x15a2d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_AchievementsAvailable", 0x156030 <F_YoYo_AchievementsAvailable>, 0, 0) */
/* ── #13 · 0x15a2d4..0x15a2e8 · achievement_available → F_YoYo_AchievementsAvailable (0x156030) · argc=0 · flag=0 ── */
/* @0x15a2d4 ldr r0, [pc, #0xe70] —— 池字 0x1ec980：串偏移 → 0x346c6c "achievement_available" */
/* @0x15a2d8 mov r1, r9 —— r1 = fn = 0x156030 <F_YoYo_AchievementsAvailable> */
/* @0x15a2dc mov r2, r4 —— argc = 0 */
/* @0x15a2e0 mov r3, r4 —— flag = 0 */
/* @0x15a2e4 add r0, pc, r0 —— r0 = 0x346c6c = "achievement_available" */
/* @0x15a2e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_available", 0x156030 <F_YoYo_AchievementsAvailable>, 0, 0) */
/* ── #14 · 0x15a2ec..0x15a300 · achievement_post_score → F_YoYo_PostScore (0x159254) · argc=2 · flag=0 ── */
/* @0x15a2ec ldr r0, [pc, #0xe5c] —— 池字 0x1ec984：串偏移 → 0x346c84 "achievement_post_score" */
/* @0x15a2f0 mov r1, r8 —— r1 = fn = 0x159254 <F_YoYo_PostScore> */
/* @0x15a2f4 mov r3, r4 —— flag = 0 */
/* @0x15a2f8 add r0, pc, r0 —— r0 = 0x346c84 = "achievement_post_score" */
/* @0x15a2fc mov r2, #2 —— argc = 2 */
/* @0x15a300 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_post_score", 0x159254 <F_YoYo_PostScore>, 2, 0) */
/* ── #15 · 0x15a304..0x15a318 · achievement_post → F_YoYo_PostAchievement (0x1590f4) · argc=2 · flag=0 ── */
/* @0x15a304 ldr r0, [pc, #0xe48] —— 池字 0x1ec984：串偏移 → 0x346c9c "achievement_post" */
/* @0x15a308 mov r1, r7 —— r1 = fn = 0x1590f4 <F_YoYo_PostAchievement> */
/* @0x15a30c mov r3, r4 —— flag = 0 */
/* @0x15a310 add r0, pc, r0 —— r0 = 0x346c9c = "achievement_post" */
/* @0x15a314 mov r2, #2 —— argc = 2 */
/* @0x15a318 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_post", 0x1590f4 <F_YoYo_PostAchievement>, 2, 0) */
/* ── #16 · 0x15a31c..0x15a334 · achievement_increment → F_YoYo_IncrementAchievement (0x1591a4) · argc=2 · flag=0 ── */
/* @0x15a31c ldr r1, [pc, #0xe34] —— 池字 0xffffdfc8：GOT 偏移 -0x2038 → 槽 0x3efc20 = 0x1591a4 <F_YoYo_IncrementAchievement> */
/* @0x15a320 ldr r0, [pc, #0xe34] —— 池字 0x1ec978：串偏移 → 0x346cb0 "achievement_increment" */
/* @0x15a324 mov r3, r4 —— flag = 0 */
/* @0x15a328 mov r2, #2 —— argc = 2 */
/* @0x15a32c ldr r1, [r10, r1] —— r1 = *(槽 0x3efc20) = 0x1591a4 <F_YoYo_IncrementAchievement> */
/* @0x15a330 add r0, pc, r0 —— r0 = 0x346cb0 = "achievement_increment" */
/* @0x15a334 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_increment", 0x1591a4 <F_YoYo_IncrementAchievement>, 2, 0) */
/* ── #17 · 0x15a338..0x15a350 · achievement_event → F_YoYo_AchievementEvent (0x156b50) · argc=1 · flag=0 ── */
/* @0x15a338 ldr r1, [pc, #0xe20] —— 池字 0xffffdfcc：GOT 偏移 -0x2034 → 槽 0x3efc24 = 0x156b50 <F_YoYo_AchievementEvent> */
/* @0x15a33c ldr r0, [pc, #0xe20] —— 池字 0x1ec974：串偏移 → 0x346cc8 "achievement_event" */
/* @0x15a340 mov r3, r4 —— flag = 0 */
/* @0x15a344 mov r2, #1 —— argc = 1 */
/* @0x15a348 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc24) = 0x156b50 <F_YoYo_AchievementEvent> */
/* @0x15a34c add r0, pc, r0 —— r0 = 0x346cc8 = "achievement_event" */
/* @0x15a350 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_event", 0x156b50 <F_YoYo_AchievementEvent>, 1, 0) */
/* ── #18 · 0x15a354..0x15a368 · achievement_login → F_YoYo_LoginAchievements (0x1565b4) · argc=0 · flag=0 ── */
/* @0x15a354 ldr r0, [pc, #0xe0c] —— 池字 0x1ec970：串偏移 → 0x346cdc "achievement_login" */
/* @0x15a358 mov r1, r6 —— r1 = fn = 0x1565b4 <F_YoYo_LoginAchievements> */
/* @0x15a35c mov r2, r4 —— argc = 0 */
/* @0x15a360 mov r3, r4 —— flag = 0 */
/* @0x15a364 add r0, pc, r0 —— r0 = 0x346cdc = "achievement_login" */
/* @0x15a368 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_login", 0x1565b4 <F_YoYo_LoginAchievements>, 0, 0) */
/* ── #19 · 0x15a36c..0x15a380 · achievement_logout → F_YoYo_LogoutAchievements (0x1565b8) · argc=0 · flag=0 ── */
/* @0x15a36c ldr r0, [pc, #0xdf8] —— 池字 0x1ec96c：串偏移 → 0x346cf0 "achievement_logout" */
/* @0x15a370 mov r1, r5 —— r1 = fn = 0x1565b8 <F_YoYo_LogoutAchievements> */
/* @0x15a374 mov r2, r4 —— argc = 0 */
/* @0x15a378 mov r3, r4 —— flag = 0 */
/* @0x15a37c add r0, pc, r0 —— r0 = 0x346cf0 = "achievement_logout" */
/* @0x15a380 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_logout", 0x1565b8 <F_YoYo_LogoutAchievements>, 0, 0) */
/* ── #20 · 0x15a384..0x15a39c · achievement_reset → F_YoYo_AchievementReset (0x1567a0) · argc=0 · flag=0 ── */
/* @0x15a384 ldr r1, [pc, #0xde4] —— 池字 0xffffdfd0：GOT 偏移 -0x2030 → 槽 0x3efc28 = 0x1567a0 <F_YoYo_AchievementReset> */
/* @0x15a388 ldr r0, [pc, #0xde4] —— 池字 0x1ec964：串偏移 → 0x346d04 "achievement_reset" */
/* @0x15a38c mov r2, r4 —— argc = 0 */
/* @0x15a390 mov r3, r4 —— flag = 0 */
/* @0x15a394 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc28) = 0x1567a0 <F_YoYo_AchievementReset> */
/* @0x15a398 add r0, pc, r0 —— r0 = 0x346d04 = "achievement_reset" */
/* @0x15a39c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_reset", 0x1567a0 <F_YoYo_AchievementReset>, 0, 0) */
/* ── #21 · 0x15a3a0..0x15a3b8 · achievement_show_achievements → F_YoYo_AchievementsShowAchievements (0x1565bc) · argc=0 · flag=0 ── */
/* @0x15a3a0 ldr r1, [pc, #0xdd0] —— 池字 0xffffdfd4：GOT 偏移 -0x202c → 槽 0x3efc2c = 0x1565bc <F_YoYo_AchievementsShowAchievements> */
/* @0x15a3a4 ldr r0, [pc, #0xdd0] —— 池字 0x1ec95c：串偏移 → 0x346d18 "achievement_show_achievements" */
/* @0x15a3a8 mov r2, r4 —— argc = 0 */
/* @0x15a3ac mov r3, r4 —— flag = 0 */
/* @0x15a3b0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc2c) = 0x1565bc <F_YoYo_AchievementsShowAchievements> */
/* @0x15a3b4 add r0, pc, r0 —— r0 = 0x346d18 = "achievement_show_achievements" */
/* @0x15a3b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_show_achievements", 0x1565bc <F_YoYo_AchievementsShowAchievements>, 0, 0) */
/* ── #22 · 0x15a3bc..0x15a3d4 · achievement_show → F_YoYo_AchievementsShow (0x1565c0) · argc=2 · flag=0 ── */
/* @0x15a3bc ldr r1, [pc, #0xdbc] —— 池字 0xffffdfd8：GOT 偏移 -0x2028 → 槽 0x3efc30 = 0x1565c0 <F_YoYo_AchievementsShow> */
/* @0x15a3c0 ldr r0, [pc, #0xdbc] —— 池字 0x1ec960：串偏移 → 0x346d38 "achievement_show" */
/* @0x15a3c4 mov r3, r4 —— flag = 0 */
/* @0x15a3c8 mov r2, #2 —— argc = 2 */
/* @0x15a3cc ldr r1, [r10, r1] —— r1 = *(槽 0x3efc30) = 0x1565c0 <F_YoYo_AchievementsShow> */
/* @0x15a3d0 add r0, pc, r0 —— r0 = 0x346d38 = "achievement_show" */
/* @0x15a3d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_show", 0x1565c0 <F_YoYo_AchievementsShow>, 2, 0) */
/* ── #23 · 0x15a3d8..0x15a3f0 · achievement_show_leaderboards → F_YoYo_AchievementsShowLeaderboards (0x156608) · argc=0 · flag=0 ── */
/* @0x15a3d8 ldr r1, [pc, #0xda8] —— 池字 0xffffdfdc：GOT 偏移 -0x2024 → 槽 0x3efc34 = 0x156608 <F_YoYo_AchievementsShowLeaderboards> */
/* @0x15a3dc ldr r0, [pc, #0xda8] —— 池字 0x1ec958：串偏移 → 0x346d4c "achievement_show_leaderboards" */
/* @0x15a3e0 mov r2, r4 —— argc = 0 */
/* @0x15a3e4 mov r3, r4 —— flag = 0 */
/* @0x15a3e8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc34) = 0x156608 <F_YoYo_AchievementsShowLeaderboards> */
/* @0x15a3ec add r0, pc, r0 —— r0 = 0x346d4c = "achievement_show_leaderboards" */
/* @0x15a3f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_show_leaderboards", 0x156608 <F_YoYo_AchievementsShowLeaderboards>, 0, 0) */
/* ── #24 · 0x15a3f4..0x15a40c · achievement_load_friends → F_YoYo_AchievementsLoadFriends (0x15660c) · argc=0 · flag=0 ── */
/* @0x15a3f4 ldr r1, [pc, #0xd94] —— 池字 0xffffdfe0：GOT 偏移 -0x2020 → 槽 0x3efc38 = 0x15660c <F_YoYo_AchievementsLoadFriends> */
/* @0x15a3f8 ldr r0, [pc, #0xd94] —— 池字 0x1ec95c：串偏移 → 0x346d6c "achievement_load_friends" */
/* @0x15a3fc mov r2, r4 —— argc = 0 */
/* @0x15a400 mov r3, r4 —— flag = 0 */
/* @0x15a404 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc38) = 0x15660c <F_YoYo_AchievementsLoadFriends> */
/* @0x15a408 add r0, pc, r0 —— r0 = 0x346d6c = "achievement_load_friends" */
/* @0x15a40c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_load_friends", 0x15660c <F_YoYo_AchievementsLoadFriends>, 0, 0) */
/* ── #25 · 0x15a410..0x15a428 · achievement_load_leaderboard → F_YoYo_AchievementLoadLeaderboard (0x156654) · argc=4 · flag=0 ── */
/* @0x15a410 ldr r1, [pc, #0xd80] —— 池字 0xffffdfe4：GOT 偏移 -0x201c → 槽 0x3efc3c = 0x156654 <F_YoYo_AchievementLoadLeaderboard> */
/* @0x15a414 ldr r0, [pc, #0xd80] —— 池字 0x1ec95c：串偏移 → 0x346d88 "achievement_load_leaderboard" */
/* @0x15a418 mov r3, r4 —— flag = 0 */
/* @0x15a41c mov r2, #4 —— argc = 4 */
/* @0x15a420 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc3c) = 0x156654 <F_YoYo_AchievementLoadLeaderboard> */
/* @0x15a424 add r0, pc, r0 —— r0 = 0x346d88 = "achievement_load_leaderboard" */
/* @0x15a428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_load_leaderboard", 0x156654 <F_YoYo_AchievementLoadLeaderboard>, 4, 0) */
/* ── #26 · 0x15a42c..0x15a444 · achievement_get_pic → F_YoYo_Achievement_GetPic (0x156610) · argc=1 · flag=0 ── */
/* @0x15a42c ldr r1, [pc, #0xd6c] —— 池字 0xffffdfe8：GOT 偏移 -0x2018 → 槽 0x3efc40 = 0x156610 <F_YoYo_Achievement_GetPic> */
/* @0x15a430 ldr r0, [pc, #0xd6c] —— 池字 0x1ec960：串偏移 → 0x346da8 "achievement_get_pic" */
/* @0x15a434 mov r3, r4 —— flag = 0 */
/* @0x15a438 mov r2, #1 —— argc = 1 */
/* @0x15a43c ldr r1, [r10, r1] —— r1 = *(槽 0x3efc40) = 0x156610 <F_YoYo_Achievement_GetPic> */
/* @0x15a440 add r0, pc, r0 —— r0 = 0x346da8 = "achievement_get_pic" */
/* @0x15a444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_get_pic", 0x156610 <F_YoYo_Achievement_GetPic>, 1, 0) */
/* ── #27 · 0x15a448..0x15a460 · achievement_get_info → F_YoYo_Achievement_GetInfo (0x156628) · argc=1 · flag=0 ── */
/* @0x15a448 ldr r1, [pc, #0xd58] —— 池字 0xffffdfec：GOT 偏移 -0x2014 → 槽 0x3efc44 = 0x156628 <F_YoYo_Achievement_GetInfo> */
/* @0x15a44c ldr r0, [pc, #0xd58] —— 池字 0x1ec958：串偏移 → 0x346dbc "achievement_get_info" */
/* @0x15a450 mov r3, r4 —— flag = 0 */
/* @0x15a454 mov r2, #1 —— argc = 1 */
/* @0x15a458 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc44) = 0x156628 <F_YoYo_Achievement_GetInfo> */
/* @0x15a45c add r0, pc, r0 —— r0 = 0x346dbc = "achievement_get_info" */
/* @0x15a460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_get_info", 0x156628 <F_YoYo_Achievement_GetInfo>, 1, 0) */
/* ── #28 · 0x15a464..0x15a47c · achievement_load_progress → F_YoYo_AchievementLoadProgress (0x1566c0) · argc=0 · flag=0 ── */
/* @0x15a464 ldr r1, [pc, #0xd44] —— 池字 0xffffdff0：GOT 偏移 -0x2010 → 槽 0x3efc48 = 0x1566c0 <F_YoYo_AchievementLoadProgress> */
/* @0x15a468 ldr r0, [pc, #0xd44] —— 池字 0x1ec954：串偏移 → 0x346dd4 "achievement_load_progress" */
/* @0x15a46c mov r2, r4 —— argc = 0 */
/* @0x15a470 mov r3, r4 —— flag = 0 */
/* @0x15a474 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc48) = 0x1566c0 <F_YoYo_AchievementLoadProgress> */
/* @0x15a478 add r0, pc, r0 —— r0 = 0x346dd4 = "achievement_load_progress" */
/* @0x15a47c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_load_progress", 0x1566c0 <F_YoYo_AchievementLoadProgress>, 0, 0) */
/* ── #29 · 0x15a480..0x15a498 · achievement_send_challenge → F_YoYo_AchievementSendChallenge (0x1566d4) · argc=5 · flag=0 ── */
/* @0x15a480 ldr r1, [pc, #0xd30] —— 池字 0xffffdff4：GOT 偏移 -0x200c → 槽 0x3efc4c = 0x1566d4 <F_YoYo_AchievementSendChallenge> */
/* @0x15a484 ldr r0, [pc, #0xd30] —— 池字 0x1ec954：串偏移 → 0x346df0 "achievement_send_challenge" */
/* @0x15a488 mov r3, r4 —— flag = 0 */
/* @0x15a48c mov r2, #5 —— argc = 5 */
/* @0x15a490 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc4c) = 0x1566d4 <F_YoYo_AchievementSendChallenge> */
/* @0x15a494 add r0, pc, r0 —— r0 = 0x346df0 = "achievement_send_challenge" */
/* @0x15a498 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_send_challenge", 0x1566d4 <F_YoYo_AchievementSendChallenge>, 5, 0) */
/* ── #30 · 0x15a49c..0x15a4b4 · achievement_get_challenges → F_YoYo_AchievementGetChallenges (0x156754) · argc=0 · flag=0 ── */
/* @0x15a49c ldr r1, [pc, #0xd1c] —— 池字 0xffffdff8：GOT 偏移 -0x2008 → 槽 0x3efc50 = 0x156754 <F_YoYo_AchievementGetChallenges> */
/* @0x15a4a0 ldr r0, [pc, #0xd1c] —— 池字 0x1ec954：串偏移 → 0x346e0c "achievement_get_challenges" */
/* @0x15a4a4 mov r2, r4 —— argc = 0 */
/* @0x15a4a8 mov r3, r4 —— flag = 0 */
/* @0x15a4ac ldr r1, [r10, r1] —— r1 = *(槽 0x3efc50) = 0x156754 <F_YoYo_AchievementGetChallenges> */
/* @0x15a4b0 add r0, pc, r0 —— r0 = 0x346e0c = "achievement_get_challenges" */
/* @0x15a4b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_get_challenges", 0x156754 <F_YoYo_AchievementGetChallenges>, 0, 0) */
/* ── #31 · 0x15a4b8..0x15a4d0 · achievement_show_challenge_notifications → F_YoYo_AchievementShowChallengeNotifications (0x156758) · argc=3 · flag=0 ── */
/* @0x15a4b8 ldr r1, [pc, #0xd08] —— 池字 0xffffdffc：GOT 偏移 -0x2004 → 槽 0x3efc54 = 0x156758 <F_YoYo_AchievementShowChallengeNotifications> */
/* @0x15a4bc ldr r0, [pc, #0xd08] —— 池字 0x1ec954：串偏移 → 0x346e28 "achievement_show_challenge_notifications" */
/* @0x15a4c0 mov r3, r4 —— flag = 0 */
/* @0x15a4c4 mov r2, #3 —— argc = 3 */
/* @0x15a4c8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc54) = 0x156758 <F_YoYo_AchievementShowChallengeNotifications> */
/* @0x15a4cc add r0, pc, r0 —— r0 = 0x346e28 = "achievement_show_challenge_notifications" */
/* @0x15a4d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_show_challenge_notifications", 0x156758 <F_YoYo_AchievementShowChallengeNotifications>, 3, 0) */
/* ── #32 · 0x15a4d4..0x15a4ec · cloud_file_save → F_YoYo_CloudFileSave (0x1568e8) · argc=2 · flag=1 ── */
/* @0x15a4d4 ldr r1, [pc, #0xcf4] —— 池字 0xffffe000：GOT 偏移 -0x2000 → 槽 0x3efc58 = 0x1568e8 <F_YoYo_CloudFileSave> */
/* @0x15a4d8 ldr r0, [pc, #0xcf4] —— 池字 0x1ec964：串偏移 → 0x346e54 "cloud_file_save" */
/* @0x15a4dc mov r2, #2 —— argc = 2 */
/* @0x15a4e0 mov r3, #1 —— flag = 1 */
/* @0x15a4e4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc58) = 0x1568e8 <F_YoYo_CloudFileSave> */
/* @0x15a4e8 add r0, pc, r0 —— r0 = 0x346e54 = "cloud_file_save" */
/* @0x15a4ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("cloud_file_save", 0x1568e8 <F_YoYo_CloudFileSave>, 2, 1) */
/* ── #33 · 0x15a4f0..0x15a508 · cloud_string_save → F_YoYo_CloudStringSave (0x159038) · argc=2 · flag=1 ── */
/* @0x15a4f0 ldr r1, [pc, #0xce0] —— 池字 0xffffe004：GOT 偏移 -0x1ffc → 槽 0x3efc5c = 0x159038 <F_YoYo_CloudStringSave> */
/* @0x15a4f4 ldr r0, [pc, #0xce0] —— 池字 0x1ec958：串偏移 → 0x346e64 "cloud_string_save" */
/* @0x15a4f8 mov r2, #2 —— argc = 2 */
/* @0x15a4fc mov r3, #1 —— flag = 1 */
/* @0x15a500 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc5c) = 0x159038 <F_YoYo_CloudStringSave> */
/* @0x15a504 add r0, pc, r0 —— r0 = 0x346e64 = "cloud_string_save" */
/* @0x15a508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("cloud_string_save", 0x159038 <F_YoYo_CloudStringSave>, 2, 1) */
/* ── #34 · 0x15a50c..0x15a524 · cloud_synchronise → F_YoYo_CloudSynchronise (0x156b04) · argc=0 · flag=1 ── */
/* @0x15a50c ldr r1, [pc, #0xccc] —— 池字 0xffffe008：GOT 偏移 -0x1ff8 → 槽 0x3efc60 = 0x156b04 <F_YoYo_CloudSynchronise> */
/* @0x15a510 ldr r0, [pc, #0xccc] —— 池字 0x1ec950：串偏移 → 0x346e78 "cloud_synchronise" */
/* @0x15a514 mov r2, r4 —— argc = 0 */
/* @0x15a518 mov r3, #1 —— flag = 1 */
/* @0x15a51c ldr r1, [r10, r1] —— r1 = *(槽 0x3efc60) = 0x156b04 <F_YoYo_CloudSynchronise> */
/* @0x15a520 add r0, pc, r0 —— r0 = 0x346e78 = "cloud_synchronise" */
/* @0x15a524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("cloud_synchronise", 0x156b04 <F_YoYo_CloudSynchronise>, 0, 1) */
/* ── #35 · 0x15a528..0x15a544 · YoYo_OpenURL → F_YoYo_OpenURL (0x156be8) · argc=1 · flag=0 ── */
/* @0x15a528 ldr r1, [pc, #0xcb8] —— 池字 0xffffe00c：GOT 偏移 -0x1ff4 → 槽 0x3efc64 = 0x156be8 <F_YoYo_OpenURL> */
/* @0x15a52c ldr r0, [pc, #0xcb8] —— 池字 0x1ec948：串偏移 → 0x346e8c "YoYo_OpenURL" */
/* @0x15a530 mov r3, r4 —— flag = 0 */
/* @0x15a534 mov r2, #1 —— argc = 1 */
/* @0x15a538 ldr r7, [r10, r1] —— r7 = *(槽 0x3efc64) = 0x156be8 <F_YoYo_OpenURL> */
/* @0x15a53c add r0, pc, r0 —— r0 = 0x346e8c = "YoYo_OpenURL" */
/* @0x15a540 mov r1, r7 —— r1 = fn = 0x156be8 <F_YoYo_OpenURL> */
/* @0x15a544 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OpenURL", 0x156be8 <F_YoYo_OpenURL>, 1, 0) */
/* ── #36 · 0x15a548..0x15a564 · YoYo_OpenURL_ext → F_YoYo_OpenURL_ext (0x156dcc) · argc=2 · flag=0 ── */
/* @0x15a548 ldr r1, [pc, #0xca0] —— 池字 0xffffe010：GOT 偏移 -0x1ff0 → 槽 0x3efc68 = 0x156dcc <F_YoYo_OpenURL_ext> */
/* @0x15a54c ldr r0, [pc, #0xca0] —— 池字 0x1ec938：串偏移 → 0x346e9c "YoYo_OpenURL_ext" */
/* @0x15a550 mov r3, r4 —— flag = 0 */
/* @0x15a554 mov r2, #2 —— argc = 2 */
/* @0x15a558 ldr r6, [r10, r1] —— r6 = *(槽 0x3efc68) = 0x156dcc <F_YoYo_OpenURL_ext> */
/* @0x15a55c add r0, pc, r0 —— r0 = 0x346e9c = "YoYo_OpenURL_ext" */
/* @0x15a560 mov r1, r6 —— r1 = fn = 0x156dcc <F_YoYo_OpenURL_ext> */
/* @0x15a564 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OpenURL_ext", 0x156dcc <F_YoYo_OpenURL_ext>, 2, 0) */
/* ── #37 · 0x15a568..0x15a584 · YoYo_OpenURL_full → F_YoYo_OpenURL_full (0x156dc0) · argc=3 · flag=0 ── */
/* @0x15a568 ldr r1, [pc, #0xc88] —— 池字 0xffffe014：GOT 偏移 -0x1fec → 槽 0x3efc6c = 0x156dc0 <F_YoYo_OpenURL_full> */
/* @0x15a56c ldr r0, [pc, #0xc88] —— 池字 0x1ec92c：串偏移 → 0x346eb0 "YoYo_OpenURL_full" */
/* @0x15a570 mov r3, r4 —— flag = 0 */
/* @0x15a574 mov r2, #3 —— argc = 3 */
/* @0x15a578 ldr r5, [r10, r1] —— r5 = *(槽 0x3efc6c) = 0x156dc0 <F_YoYo_OpenURL_full> */
/* @0x15a57c add r0, pc, r0 —— r0 = 0x346eb0 = "YoYo_OpenURL_full" */
/* @0x15a580 mov r1, r5 —— r1 = fn = 0x156dc0 <F_YoYo_OpenURL_full> */
/* @0x15a584 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OpenURL_full", 0x156dc0 <F_YoYo_OpenURL_full>, 3, 0) */
/* ── #38 · 0x15a588..0x15a59c · url_open → F_YoYo_OpenURL (0x156be8) · argc=1 · flag=0 ── */
/* @0x15a588 ldr r0, [pc, #0xc70] —— 池字 0x1ec928：串偏移 → 0x346ec4 "url_open" */
/* @0x15a58c mov r1, r7 —— r1 = fn = 0x156be8 <F_YoYo_OpenURL> */
/* @0x15a590 mov r3, r4 —— flag = 0 */
/* @0x15a594 add r0, pc, r0 —— r0 = 0x346ec4 = "url_open" */
/* @0x15a598 mov r2, #1 —— argc = 1 */
/* @0x15a59c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("url_open", 0x156be8 <F_YoYo_OpenURL>, 1, 0) */
/* ── #39 · 0x15a5a0..0x15a5b4 · url_open_ext → F_YoYo_OpenURL_ext (0x156dcc) · argc=2 · flag=0 ── */
/* @0x15a5a0 ldr r0, [pc, #0xc5c] —— 池字 0x1ec91c：串偏移 → 0x346ed0 "url_open_ext" */
/* @0x15a5a4 mov r1, r6 —— r1 = fn = 0x156dcc <F_YoYo_OpenURL_ext> */
/* @0x15a5a8 mov r3, r4 —— flag = 0 */
/* @0x15a5ac add r0, pc, r0 —— r0 = 0x346ed0 = "url_open_ext" */
/* @0x15a5b0 mov r2, #2 —— argc = 2 */
/* @0x15a5b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("url_open_ext", 0x156dcc <F_YoYo_OpenURL_ext>, 2, 0) */
/* ── #40 · 0x15a5b8..0x15a5cc · url_open_full → F_YoYo_OpenURL_full (0x156dc0) · argc=3 · flag=0 ── */
/* @0x15a5b8 ldr r0, [pc, #0xc48] —— 池字 0x1ec914：串偏移 → 0x346ee0 "url_open_full" */
/* @0x15a5bc mov r1, r5 —— r1 = fn = 0x156dc0 <F_YoYo_OpenURL_full> */
/* @0x15a5c0 mov r3, r4 —— flag = 0 */
/* @0x15a5c4 add r0, pc, r0 —— r0 = 0x346ee0 = "url_open_full" */
/* @0x15a5c8 mov r2, #3 —— argc = 3 */
/* @0x15a5cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("url_open_full", 0x156dc0 <F_YoYo_OpenURL_full>, 3, 0) */
/* ── #41 · 0x15a5d0..0x15a5e8 · url_get_domain → F_YoYo_GetDomain (0x156ba8) · argc=1 · flag=0 ── */
/* @0x15a5d0 ldr r1, [pc, #0xc34] —— 池字 0xffffe018：GOT 偏移 -0x1fe8 → 槽 0x3efc70 = 0x156ba8 <F_YoYo_GetDomain> */
/* @0x15a5d4 ldr r0, [pc, #0xc34] —— 池字 0x1ec904：串偏移 → 0x346ef0 "url_get_domain" */
/* @0x15a5d8 mov r3, r4 —— flag = 0 */
/* @0x15a5dc mov r2, #1 —— argc = 1 */
/* @0x15a5e0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc70) = 0x156ba8 <F_YoYo_GetDomain> */
/* @0x15a5e4 add r0, pc, r0 —— r0 = 0x346ef0 = "url_get_domain" */
/* @0x15a5e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("url_get_domain", 0x156ba8 <F_YoYo_GetDomain>, 1, 0) */
/* ── #42 · 0x15a5ec..0x15a604 · YoYo_EnableAds → F_YoYo_EnableAds (0x156dd8) · argc=5 · flag=0 ── */
/* @0x15a5ec ldr r1, [pc, #0xc20] —— 池字 0xffffe01c：GOT 偏移 -0x1fe4 → 槽 0x3efc74 = 0x156dd8 <F_YoYo_EnableAds> */
/* @0x15a5f0 ldr r0, [pc, #0xc20] —— 池字 0x1ec8f8：串偏移 → 0x346f00 "YoYo_EnableAds" */
/* @0x15a5f4 mov r3, r4 —— flag = 0 */
/* @0x15a5f8 mov r2, #5 —— argc = 5 */
/* @0x15a5fc ldr r1, [r10, r1] —— r1 = *(槽 0x3efc74) = 0x156dd8 <F_YoYo_EnableAds> */
/* @0x15a600 add r0, pc, r0 —— r0 = 0x346f00 = "YoYo_EnableAds" */
/* @0x15a604 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_EnableAds", 0x156dd8 <F_YoYo_EnableAds>, 5, 0) */
/* ── #43 · 0x15a608..0x15a624 · YoYo_DisableAds → F_YoYo_DisableAds (0x15936c) · argc=0 · flag=0 ── */
/* @0x15a608 ldr r1, [pc, #0xc0c] —— 池字 0xffffe020：GOT 偏移 -0x1fe0 → 槽 0x3efc78 = 0x15936c <F_YoYo_DisableAds> */
/* @0x15a60c ldr r0, [pc, #0xc0c] —— 池字 0x1ec8ec：串偏移 → 0x346f10 "YoYo_DisableAds" */
/* @0x15a610 mov r2, r4 —— argc = 0 */
/* @0x15a614 mov r3, r4 —— flag = 0 */
/* @0x15a618 ldr r6, [r10, r1] —— r6 = *(槽 0x3efc78) = 0x15936c <F_YoYo_DisableAds> */
/* @0x15a61c add r0, pc, r0 —— r0 = 0x346f10 = "YoYo_DisableAds" */
/* @0x15a620 mov r1, r6 —— r1 = fn = 0x15936c <F_YoYo_DisableAds> */
/* @0x15a624 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_DisableAds", 0x15936c <F_YoYo_DisableAds>, 0, 0) */
/* ── #44 · 0x15a628..0x15a644 · YoYo_LeaveRating → F_YoYo_LeaveRating (0x156ea0) · argc=4 · flag=0 ── */
/* @0x15a628 ldr r1, [pc, #0xbf4] —— 池字 0xffffe024：GOT 偏移 -0x1fdc → 槽 0x3efc7c = 0x156ea0 <F_YoYo_LeaveRating> */
/* @0x15a62c ldr r0, [pc, #0xbf4] —— 池字 0x1ec8dc：串偏移 → 0x346f20 "YoYo_LeaveRating" */
/* @0x15a630 mov r3, r4 —— flag = 0 */
/* @0x15a634 mov r2, #4 —— argc = 4 */
/* @0x15a638 ldr r5, [r10, r1] —— r5 = *(槽 0x3efc7c) = 0x156ea0 <F_YoYo_LeaveRating> */
/* @0x15a63c add r0, pc, r0 —— r0 = 0x346f20 = "YoYo_LeaveRating" */
/* @0x15a640 mov r1, r5 —— r1 = fn = 0x156ea0 <F_YoYo_LeaveRating> */
/* @0x15a644 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_LeaveRating", 0x156ea0 <F_YoYo_LeaveRating>, 4, 0) */
/* ── #45 · 0x15a648..0x15a660 · ads_enable → F_YoYo_EnableAdsEx (0x156e10) · argc=3 · flag=0 ── */
/* @0x15a648 ldr r1, [pc, #0xbdc] —— 池字 0xffffe028：GOT 偏移 -0x1fd8 → 槽 0x3efc80 = 0x156e10 <F_YoYo_EnableAdsEx> */
/* @0x15a64c ldr r0, [pc, #0xbdc] —— 池字 0x1ec8d0：串偏移 → 0x346f34 "ads_enable" */
/* @0x15a650 mov r3, r4 —— flag = 0 */
/* @0x15a654 mov r2, #3 —— argc = 3 */
/* @0x15a658 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc80) = 0x156e10 <F_YoYo_EnableAdsEx> */
/* @0x15a65c add r0, pc, r0 —— r0 = 0x346f34 = "ads_enable" */
/* @0x15a660 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_enable", 0x156e10 <F_YoYo_EnableAdsEx>, 3, 0) */
/* ── #46 · 0x15a664..0x15a678 · ads_disable → F_YoYo_DisableAds (0x15936c) · argc=1 · flag=0 ── */
/* @0x15a664 ldr r0, [pc, #0xbc8] —— 池字 0x1ec8c8：串偏移 → 0x346f40 "ads_disable" */
/* @0x15a668 mov r1, r6 —— r1 = fn = 0x15936c <F_YoYo_DisableAds> */
/* @0x15a66c mov r3, r4 —— flag = 0 */
/* @0x15a670 add r0, pc, r0 —— r0 = 0x346f40 = "ads_disable" */
/* @0x15a674 mov r2, #1 —— argc = 1 */
/* @0x15a678 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_disable", 0x15936c <F_YoYo_DisableAds>, 1, 0) */
/* ── #47 · 0x15a67c..0x15a694 · ads_event → F_YoYo_AdsEvent (0x156e88) · argc=1 · flag=0 ── */
/* @0x15a67c ldr r1, [pc, #0xbb4] —— 池字 0xffffe02c：GOT 偏移 -0x1fd4 → 槽 0x3efc84 = 0x156e88 <F_YoYo_AdsEvent> */
/* @0x15a680 ldr r0, [pc, #0xbb4] —— 池字 0x1ec8b4：串偏移 → 0x346f4c "ads_event" */
/* @0x15a684 mov r3, r4 —— flag = 0 */
/* @0x15a688 mov r2, #1 —— argc = 1 */
/* @0x15a68c ldr r1, [r10, r1] —— r1 = *(槽 0x3efc84) = 0x156e88 <F_YoYo_AdsEvent> */
/* @0x15a690 add r0, pc, r0 —— r0 = 0x346f4c = "ads_event" */
/* @0x15a694 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_event", 0x156e88 <F_YoYo_AdsEvent>, 1, 0) */
/* ── #48 · 0x15a698..0x15a6b0 · ads_event_preload → F_YoYo_AdsPreload (0x156e70) · argc=1 · flag=0 ── */
/* @0x15a698 ldr r1, [pc, #0xba0] —— 池字 0xffffe030：GOT 偏移 -0x1fd0 → 槽 0x3efc88 = 0x156e70 <F_YoYo_AdsPreload> */
/* @0x15a69c ldr r0, [pc, #0xba0] —— 池字 0x1ec8a4：串偏移 → 0x346f58 "ads_event_preload" */
/* @0x15a6a0 mov r3, r4 —— flag = 0 */
/* @0x15a6a4 mov r2, #1 —— argc = 1 */
/* @0x15a6a8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc88) = 0x156e70 <F_YoYo_AdsPreload> */
/* @0x15a6ac add r0, pc, r0 —— r0 = 0x346f58 = "ads_event_preload" */
/* @0x15a6b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_event_preload", 0x156e70 <F_YoYo_AdsPreload>, 1, 0) */
/* ── #49 · 0x15a6b4..0x15a6cc · ads_get_display_width → F_YoYo_GetAdsWidth (0x1593a4) · argc=1 · flag=0 ── */
/* @0x15a6b4 ldr r1, [pc, #0xb8c] —— 池字 0xffffe034：GOT 偏移 -0x1fcc → 槽 0x3efc8c = 0x1593a4 <F_YoYo_GetAdsWidth> */
/* @0x15a6b8 ldr r0, [pc, #0xb8c] —— 池字 0x1ec89c：串偏移 → 0x346f6c "ads_get_display_width" */
/* @0x15a6bc mov r3, r4 —— flag = 0 */
/* @0x15a6c0 mov r2, #1 —— argc = 1 */
/* @0x15a6c4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc8c) = 0x1593a4 <F_YoYo_GetAdsWidth> */
/* @0x15a6c8 add r0, pc, r0 —— r0 = 0x346f6c = "ads_get_display_width" */
/* @0x15a6cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_get_display_width", 0x1593a4 <F_YoYo_GetAdsWidth>, 1, 0) */
/* ── #50 · 0x15a6d0..0x15a6e8 · ads_get_display_height → F_YoYo_GetAdsHeight (0x159404) · argc=1 · flag=0 ── */
/* @0x15a6d0 ldr r1, [pc, #0xb78] —— 池字 0xffffe038：GOT 偏移 -0x1fc8 → 槽 0x3efc90 = 0x159404 <F_YoYo_GetAdsHeight> */
/* @0x15a6d4 ldr r0, [pc, #0xb78] —— 池字 0x1ec898：串偏移 → 0x346f84 "ads_get_display_height" */
/* @0x15a6d8 mov r3, r4 —— flag = 0 */
/* @0x15a6dc mov r2, #1 —— argc = 1 */
/* @0x15a6e0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc90) = 0x159404 <F_YoYo_GetAdsHeight> */
/* @0x15a6e4 add r0, pc, r0 —— r0 = 0x346f84 = "ads_get_display_height" */
/* @0x15a6e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_get_display_height", 0x159404 <F_YoYo_GetAdsHeight>, 1, 0) */
/* ── #51 · 0x15a6ec..0x15a704 · ads_move → F_YoYo_MoveAdsEx (0x159304) · argc=3 · flag=0 ── */
/* @0x15a6ec ldr r1, [pc, #0xb64] —— 池字 0xffffe03c：GOT 偏移 -0x1fc4 → 槽 0x3efc94 = 0x159304 <F_YoYo_MoveAdsEx> */
/* @0x15a6f0 ldr r0, [pc, #0xb64] —— 池字 0x1ec894：串偏移 → 0x346f9c "ads_move" */
/* @0x15a6f4 mov r3, r4 —— flag = 0 */
/* @0x15a6f8 mov r2, #3 —— argc = 3 */
/* @0x15a6fc ldr r1, [r10, r1] —— r1 = *(槽 0x3efc94) = 0x159304 <F_YoYo_MoveAdsEx> */
/* @0x15a700 add r0, pc, r0 —— r0 = 0x346f9c = "ads_move" */
/* @0x15a704 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_move", 0x159304 <F_YoYo_MoveAdsEx>, 3, 0) */
/* ── #52 · 0x15a708..0x15a720 · ads_interstitial_available → F_YoYo_Ads_Interstitial_Available (0x1560b0) · argc=0 · flag=0 ── */
/* @0x15a708 ldr r1, [pc, #0xb50] —— 池字 0xffffe040：GOT 偏移 -0x1fc0 → 槽 0x3efc98 = 0x1560b0 <F_YoYo_Ads_Interstitial_Available> */
/* @0x15a70c ldr r0, [pc, #0xb50] —— 池字 0x1ec884：串偏移 → 0x346fa8 "ads_interstitial_available" */
/* @0x15a710 mov r2, r4 —— argc = 0 */
/* @0x15a714 mov r3, r4 —— flag = 0 */
/* @0x15a718 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc98) = 0x1560b0 <F_YoYo_Ads_Interstitial_Available> */
/* @0x15a71c add r0, pc, r0 —— r0 = 0x346fa8 = "ads_interstitial_available" */
/* @0x15a720 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_interstitial_available", 0x1560b0 <F_YoYo_Ads_Interstitial_Available>, 0, 0) */
/* ── #53 · 0x15a724..0x15a73c · ads_interstitial_display → F_YoYo_Ads_Interstitial_Display (0x1560c4) · argc=0 · flag=0 ── */
/* @0x15a724 ldr r1, [pc, #0xb3c] —— 池字 0xffffe044：GOT 偏移 -0x1fbc → 槽 0x3efc9c = 0x1560c4 <F_YoYo_Ads_Interstitial_Display> */
/* @0x15a728 ldr r0, [pc, #0xb3c] —— 池字 0x1ec884：串偏移 → 0x346fc4 "ads_interstitial_display" */
/* @0x15a72c mov r2, r4 —— argc = 0 */
/* @0x15a730 mov r3, r4 —— flag = 0 */
/* @0x15a734 ldr r1, [r10, r1] —— r1 = *(槽 0x3efc9c) = 0x1560c4 <F_YoYo_Ads_Interstitial_Display> */
/* @0x15a738 add r0, pc, r0 —— r0 = 0x346fc4 = "ads_interstitial_display" */
/* @0x15a73c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_interstitial_display", 0x1560c4 <F_YoYo_Ads_Interstitial_Display>, 0, 0) */
/* ── #54 · 0x15a740..0x15a758 · ads_engagement_available → F_YoYo_AdsEngagementAvailable (0x156080) · argc=1 · flag=0 ── */
/* @0x15a740 ldr r1, [pc, #0xb28] —— 池字 0xffffe048：GOT 偏移 -0x1fb8 → 槽 0x3efca0 = 0x156080 <F_YoYo_AdsEngagementAvailable> */
/* @0x15a744 ldr r0, [pc, #0xb28] —— 池字 0x1ec884：串偏移 → 0x346fe0 "ads_engagement_available" */
/* @0x15a748 mov r3, r4 —— flag = 0 */
/* @0x15a74c mov r2, #1 —— argc = 1 */
/* @0x15a750 ldr r1, [r10, r1] —— r1 = *(槽 0x3efca0) = 0x156080 <F_YoYo_AdsEngagementAvailable> */
/* @0x15a754 add r0, pc, r0 —— r0 = 0x346fe0 = "ads_engagement_available" */
/* @0x15a758 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_engagement_available", 0x156080 <F_YoYo_AdsEngagementAvailable>, 1, 0) */
/* ── #55 · 0x15a75c..0x15a774 · ads_engagement_launch → F_YoYoAdsEngagementLaunch (0x1560a8) · argc=1 · flag=0 ── */
/* @0x15a75c ldr r1, [pc, #0xb14] —— 池字 0xffffe04c：GOT 偏移 -0x1fb4 → 槽 0x3efca4 = 0x1560a8 <F_YoYoAdsEngagementLaunch> */
/* @0x15a760 ldr r0, [pc, #0xb14] —— 池字 0x1ec884：串偏移 → 0x346ffc "ads_engagement_launch" */
/* @0x15a764 mov r3, r4 —— flag = 0 */
/* @0x15a768 mov r2, #1 —— argc = 1 */
/* @0x15a76c ldr r1, [r10, r1] —— r1 = *(槽 0x3efca4) = 0x1560a8 <F_YoYoAdsEngagementLaunch> */
/* @0x15a770 add r0, pc, r0 —— r0 = 0x346ffc = "ads_engagement_launch" */
/* @0x15a774 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_engagement_launch", 0x1560a8 <F_YoYoAdsEngagementLaunch>, 1, 0) */
/* ── #56 · 0x15a778..0x15a790 · ads_engagement_active → F_YoYoAdsEngagementActive (0x156094) · argc=1 · flag=0 ── */
/* @0x15a778 ldr r1, [pc, #0xb00] —— 池字 0xffffe050：GOT 偏移 -0x1fb0 → 槽 0x3efca8 = 0x156094 <F_YoYoAdsEngagementActive> */
/* @0x15a77c ldr r0, [pc, #0xb00] —— 池字 0x1ec880：串偏移 → 0x347014 "ads_engagement_active" */
/* @0x15a780 mov r3, r4 —— flag = 0 */
/* @0x15a784 mov r2, #1 —— argc = 1 */
/* @0x15a788 ldr r1, [r10, r1] —— r1 = *(槽 0x3efca8) = 0x156094 <F_YoYoAdsEngagementActive> */
/* @0x15a78c add r0, pc, r0 —— r0 = 0x347014 = "ads_engagement_active" */
/* @0x15a790 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_engagement_active", 0x156094 <F_YoYoAdsEngagementActive>, 1, 0) */
/* ── #57 · 0x15a794..0x15a7ac · ads_setup → F_YoYoAdsSetup (0x156e58) · argc=2 · flag=0 ── */
/* @0x15a794 ldr r1, [pc, #0xaec] —— 池字 0xffffe054：GOT 偏移 -0x1fac → 槽 0x3efcac = 0x156e58 <F_YoYoAdsSetup> */
/* @0x15a798 ldr r0, [pc, #0xaec] —— 池字 0x1ec87c：串偏移 → 0x34702c "ads_setup" */
/* @0x15a79c mov r3, r4 —— flag = 0 */
/* @0x15a7a0 mov r2, #2 —— argc = 2 */
/* @0x15a7a4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcac) = 0x156e58 <F_YoYoAdsSetup> */
/* @0x15a7a8 add r0, pc, r0 —— r0 = 0x34702c = "ads_setup" */
/* @0x15a7ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_setup", 0x156e58 <F_YoYoAdsSetup>, 2, 0) */
/* ── #58 · 0x15a7b0..0x15a7c8 · ads_set_reward_callback → F_YoYoAdsRewardCallback (0x1560ac) · argc=1 · flag=0 ── */
/* @0x15a7b0 ldr r1, [pc, #0xad8] —— 池字 0xffffe058：GOT 偏移 -0x1fa8 → 槽 0x3efcb0 = 0x1560ac <F_YoYoAdsRewardCallback> */
/* @0x15a7b4 ldr r0, [pc, #0xad8] —— 池字 0x1ec86c：串偏移 → 0x347038 "ads_set_reward_callback" */
/* @0x15a7b8 mov r3, r4 —— flag = 0 */
/* @0x15a7bc mov r2, #1 —— argc = 1 */
/* @0x15a7c0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcb0) = 0x1560ac <F_YoYoAdsRewardCallback> */
/* @0x15a7c4 add r0, pc, r0 —— r0 = 0x347038 = "ads_set_reward_callback" */
/* @0x15a7c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ads_set_reward_callback", 0x1560ac <F_YoYoAdsRewardCallback>, 1, 0) */
/* ── #59 · 0x15a7cc..0x15a7e4 · clickable_add → F_BE_AddButton (0x156064) · argc=6 · flag=0 ── */
/* @0x15a7cc ldr r1, [pc, #0xac4] —— 池字 0xffffe05c：GOT 偏移 -0x1fa4 → 槽 0x3efcb4 = 0x156064 <F_BE_AddButton> */
/* @0x15a7d0 ldr r0, [pc, #0xac4] —— 池字 0x1ec868：串偏移 → 0x347050 "clickable_add" */
/* @0x15a7d4 mov r3, r4 —— flag = 0 */
/* @0x15a7d8 mov r2, #6 —— argc = 6 */
/* @0x15a7dc ldr r1, [r10, r1] —— r1 = *(槽 0x3efcb4) = 0x156064 <F_BE_AddButton> */
/* @0x15a7e0 add r0, pc, r0 —— r0 = 0x347050 = "clickable_add" */
/* @0x15a7e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("clickable_add", 0x156064 <F_BE_AddButton>, 6, 0) */
/* ── #60 · 0x15a7e8..0x15a800 · clickable_add_ext → F_BE_AddButtonExt (0x156068) · argc=8 · flag=0 ── */
/* @0x15a7e8 ldr r1, [pc, #0xab0] —— 池字 0xffffe060：GOT 偏移 -0x1fa0 → 槽 0x3efcb8 = 0x156068 <F_BE_AddButtonExt> */
/* @0x15a7ec ldr r0, [pc, #0xab0] —— 池字 0x1ec85c：串偏移 → 0x347060 "clickable_add_ext" */
/* @0x15a7f0 mov r3, r4 —— flag = 0 */
/* @0x15a7f4 mov r2, #8 —— argc = 8 */
/* @0x15a7f8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcb8) = 0x156068 <F_BE_AddButtonExt> */
/* @0x15a7fc add r0, pc, r0 —— r0 = 0x347060 = "clickable_add_ext" */
/* @0x15a800 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("clickable_add_ext", 0x156068 <F_BE_AddButtonExt>, 8, 0) */
/* ── #61 · 0x15a804..0x15a81c · clickable_change → F_BE_ChangeImage (0x15606c) · argc=4 · flag=0 ── */
/* @0x15a804 ldr r1, [pc, #0xa9c] —— 池字 0xffffe064：GOT 偏移 -0x1f9c → 槽 0x3efcbc = 0x15606c <F_BE_ChangeImage> */
/* @0x15a808 ldr r0, [pc, #0xa9c] —— 池字 0x1ec854：串偏移 → 0x347074 "clickable_change" */
/* @0x15a80c mov r3, r4 —— flag = 0 */
/* @0x15a810 mov r2, #4 —— argc = 4 */
/* @0x15a814 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcbc) = 0x15606c <F_BE_ChangeImage> */
/* @0x15a818 add r0, pc, r0 —— r0 = 0x347074 = "clickable_change" */
/* @0x15a81c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("clickable_change", 0x15606c <F_BE_ChangeImage>, 4, 0) */
/* ── #62 · 0x15a820..0x15a838 · clickable_change_ext → F_BE_Change (0x156070) · argc=5 · flag=0 ── */
/* @0x15a820 ldr r1, [pc, #0xa88] —— 池字 0xffffe068：GOT 偏移 -0x1f98 → 槽 0x3efcc0 = 0x156070 <F_BE_Change> */
/* @0x15a824 ldr r0, [pc, #0xa88] —— 池字 0x1ec84c：串偏移 → 0x347088 "clickable_change_ext" */
/* @0x15a828 mov r3, r4 —— flag = 0 */
/* @0x15a82c mov r2, #5 —— argc = 5 */
/* @0x15a830 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcc0) = 0x156070 <F_BE_Change> */
/* @0x15a834 add r0, pc, r0 —— r0 = 0x347088 = "clickable_change_ext" */
/* @0x15a838 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("clickable_change_ext", 0x156070 <F_BE_Change>, 5, 0) */
/* ── #63 · 0x15a83c..0x15a854 · clickable_delete → F_BE_DeleteButton (0x156074) · argc=1 · flag=0 ── */
/* @0x15a83c ldr r1, [pc, #0xa74] —— 池字 0xffffe06c：GOT 偏移 -0x1f94 → 槽 0x3efcc4 = 0x156074 <F_BE_DeleteButton> */
/* @0x15a840 ldr r0, [pc, #0xa74] —— 池字 0x1ec848：串偏移 → 0x3470a0 "clickable_delete" */
/* @0x15a844 mov r3, r4 —— flag = 0 */
/* @0x15a848 mov r2, #1 —— argc = 1 */
/* @0x15a84c ldr r1, [r10, r1] —— r1 = *(槽 0x3efcc4) = 0x156074 <F_BE_DeleteButton> */
/* @0x15a850 add r0, pc, r0 —— r0 = 0x3470a0 = "clickable_delete" */
/* @0x15a854 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("clickable_delete", 0x156074 <F_BE_DeleteButton>, 1, 0) */
/* ── #64 · 0x15a858..0x15a870 · clickable_exists → F_BE_ExistsButton (0x156078) · argc=1 · flag=0 ── */
/* @0x15a858 ldr r1, [pc, #0xa60] —— 池字 0xffffe070：GOT 偏移 -0x1f90 → 槽 0x3efcc8 = 0x156078 <F_BE_ExistsButton> */
/* @0x15a85c ldr r0, [pc, #0xa60] —— 池字 0x1ec840：串偏移 → 0x3470b4 "clickable_exists" */
/* @0x15a860 mov r3, r4 —— flag = 0 */
/* @0x15a864 mov r2, #1 —— argc = 1 */
/* @0x15a868 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcc8) = 0x156078 <F_BE_ExistsButton> */
/* @0x15a86c add r0, pc, r0 —— r0 = 0x3470b4 = "clickable_exists" */
/* @0x15a870 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("clickable_exists", 0x156078 <F_BE_ExistsButton>, 1, 0) */
/* ── #65 · 0x15a874..0x15a88c · clickable_set_style → F_BE_SetStyle (0x15607c) · argc=2 · flag=0 ── */
/* @0x15a874 ldr r1, [pc, #0xa4c] —— 池字 0xffffe074：GOT 偏移 -0x1f8c → 槽 0x3efccc = 0x15607c <F_BE_SetStyle> */
/* @0x15a878 ldr r0, [pc, #0xa4c] —— 池字 0x1ec838：串偏移 → 0x3470c8 "clickable_set_style" */
/* @0x15a87c mov r3, r4 —— flag = 0 */
/* @0x15a880 mov r2, #2 —— argc = 2 */
/* @0x15a884 ldr r1, [r10, r1] —— r1 = *(槽 0x3efccc) = 0x15607c <F_BE_SetStyle> */
/* @0x15a888 add r0, pc, r0 —— r0 = 0x3470c8 = "clickable_set_style" */
/* @0x15a88c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("clickable_set_style", 0x15607c <F_BE_SetStyle>, 2, 0) */
/* ── #66 · 0x15a890..0x15a8a4 · shop_leave_rating → F_YoYo_LeaveRating (0x156ea0) · argc=4 · flag=0 ── */
/* @0x15a890 ldr r0, [pc, #0xa38] —— 池字 0x1ec838：串偏移 → 0x3470dc "shop_leave_rating" */
/* @0x15a894 mov r1, r5 —— r1 = fn = 0x156ea0 <F_YoYo_LeaveRating> */
/* @0x15a898 mov r3, r4 —— flag = 0 */
/* @0x15a89c add r0, pc, r0 —— r0 = 0x3470dc = "shop_leave_rating" */
/* @0x15a8a0 mov r2, #4 —— argc = 4 */
/* @0x15a8a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("shop_leave_rating", 0x156ea0 <F_YoYo_LeaveRating>, 4, 0) */
/* ── #67 · 0x15a8a8..0x15a8c4 · YoYo_GetTimer → F_YoYo_GetTimer (0x156f90) · argc=0 · flag=0 ── */
/* @0x15a8a8 ldr r1, [pc, #0xa24] —— 池字 0xffffe078：GOT 偏移 -0x1f88 → 槽 0x3efcd0 = 0x156f90 <F_YoYo_GetTimer> */
/* @0x15a8ac ldr r0, [pc, #0xa24] —— 池字 0x1ec82c：串偏移 → 0x3470f0 "YoYo_GetTimer" */
/* @0x15a8b0 mov r2, r4 —— argc = 0 */
/* @0x15a8b4 mov r3, r4 —— flag = 0 */
/* @0x15a8b8 ldr r6, [r10, r1] —— r6 = *(槽 0x3efcd0) = 0x156f90 <F_YoYo_GetTimer> */
/* @0x15a8bc add r0, pc, r0 —— r0 = 0x3470f0 = "YoYo_GetTimer" */
/* @0x15a8c0 mov r1, r6 —— r1 = fn = 0x156f90 <F_YoYo_GetTimer> */
/* @0x15a8c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetTimer", 0x156f90 <F_YoYo_GetTimer>, 0, 0) */
/* ── #68 · 0x15a8c8..0x15a8e0 · YoYo_GetPlatform → F_YoYo_GetPlatform (0x159d04) · argc=0 · flag=0 ── */
/* @0x15a8c8 ldr r1, [pc, #0xa0c] —— 池字 0xffffe07c：GOT 偏移 -0x1f84 → 槽 0x3efcd4 = 0x159d04 <F_YoYo_GetPlatform> */
/* @0x15a8cc ldr r0, [pc, #0xa0c] —— 池字 0x1ec81c：串偏移 → 0x347100 "YoYo_GetPlatform" */
/* @0x15a8d0 mov r2, r4 —— argc = 0 */
/* @0x15a8d4 mov r3, r4 —— flag = 0 */
/* @0x15a8d8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcd4) = 0x159d04 <F_YoYo_GetPlatform> */
/* @0x15a8dc add r0, pc, r0 —— r0 = 0x347100 = "YoYo_GetPlatform" */
/* @0x15a8e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetPlatform", 0x159d04 <F_YoYo_GetPlatform>, 0, 0) */
/* ── #69 · 0x15a8e4..0x15a8fc · YoYo_GetDevice → F_YoYo_GetDevice (0x156efc) · argc=0 · flag=0 ── */
/* @0x15a8e4 ldr r1, [pc, #0x9f8] —— 池字 0xffffe080：GOT 偏移 -0x1f80 → 槽 0x3efcd8 = 0x156efc <F_YoYo_GetDevice> */
/* @0x15a8e8 ldr r0, [pc, #0x9f8] —— 池字 0x1ec814：串偏移 → 0x347114 "YoYo_GetDevice" */
/* @0x15a8ec mov r2, r4 —— argc = 0 */
/* @0x15a8f0 mov r3, r4 —— flag = 0 */
/* @0x15a8f4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcd8) = 0x156efc <F_YoYo_GetDevice> */
/* @0x15a8f8 add r0, pc, r0 —— r0 = 0x347114 = "YoYo_GetDevice" */
/* @0x15a8fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetDevice", 0x156efc <F_YoYo_GetDevice>, 0, 0) */
/* ── #70 · 0x15a900..0x15a918 · YoYo_GetCPUDetails → F_YoYo_GetCPUDetails (0x156f60) · argc=0 · flag=0 ── */
/* @0x15a900 ldr r1, [pc, #0x9e4] —— 池字 0xffffe084：GOT 偏移 -0x1f7c → 槽 0x3efcdc = 0x156f60 <F_YoYo_GetCPUDetails> */
/* @0x15a904 ldr r0, [pc, #0x9e4] —— 池字 0x1ec808：串偏移 → 0x347124 "YoYo_GetCPUDetails" */
/* @0x15a908 mov r2, r4 —— argc = 0 */
/* @0x15a90c mov r3, r4 —— flag = 0 */
/* @0x15a910 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcdc) = 0x156f60 <F_YoYo_GetCPUDetails> */
/* @0x15a914 add r0, pc, r0 —— r0 = 0x347124 = "YoYo_GetCPUDetails" */
/* @0x15a918 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetCPUDetails", 0x156f60 <F_YoYo_GetCPUDetails>, 0, 0) */
/* ── #71 · 0x15a91c..0x15a938 · YoYo_GetConfig → F_YoYo_GetConfig (0x156bb8) · argc=0 · flag=0 ── */
/* @0x15a91c ldr r1, [pc, #0x9d0] —— 池字 0xffffe088：GOT 偏移 -0x1f78 → 槽 0x3efce0 = 0x156bb8 <F_YoYo_GetConfig> */
/* @0x15a920 ldr r0, [pc, #0x9d0] —— 池字 0x1ec800：串偏移 → 0x347138 "YoYo_GetConfig" */
/* @0x15a924 mov r2, r4 —— argc = 0 */
/* @0x15a928 mov r3, r4 —— flag = 0 */
/* @0x15a92c ldr r5, [r10, r1] —— r5 = *(槽 0x3efce0) = 0x156bb8 <F_YoYo_GetConfig> */
/* @0x15a930 add r0, pc, r0 —— r0 = 0x347138 = "YoYo_GetConfig" */
/* @0x15a934 mov r1, r5 —— r1 = fn = 0x156bb8 <F_YoYo_GetConfig> */
/* @0x15a938 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetConfig", 0x156bb8 <F_YoYo_GetConfig>, 0, 0) */
/* ── #72 · 0x15a93c..0x15a954 · YoYo_GetSessionKey → F_YoYo_GetSessionKey (0x156184) · argc=0 · flag=0 ── */
/* @0x15a93c ldr r1, [pc, #0x9b8] —— 池字 0xffffe08c：GOT 偏移 -0x1f74 → 槽 0x3efce4 = 0x156184 <F_YoYo_GetSessionKey> */
/* @0x15a940 ldr r0, [pc, #0x9b8] —— 池字 0x1ec7f0：串偏移 → 0x347148 "YoYo_GetSessionKey" */
/* @0x15a944 mov r2, r4 —— argc = 0 */
/* @0x15a948 mov r3, r4 —— flag = 0 */
/* @0x15a94c ldr r1, [r10, r1] —— r1 = *(槽 0x3efce4) = 0x156184 <F_YoYo_GetSessionKey> */
/* @0x15a950 add r0, pc, r0 —— r0 = 0x347148 = "YoYo_GetSessionKey" */
/* @0x15a954 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetSessionKey", 0x156184 <F_YoYo_GetSessionKey>, 0, 0) */
/* ── #73 · 0x15a958..0x15a970 · YoYo_CheckSecurity → F_YoYo_CheckSecurity (0x156198) · argc=1 · flag=0 ── */
/* @0x15a958 ldr r1, [pc, #0x9a4] —— 池字 0xffffe090：GOT 偏移 -0x1f70 → 槽 0x3efce8 = 0x156198 <F_YoYo_CheckSecurity> */
/* @0x15a95c ldr r0, [pc, #0x9a4] —— 池字 0x1ec7e8：串偏移 → 0x34715c "YoYo_CheckSecurity" */
/* @0x15a960 mov r3, r4 —— flag = 0 */
/* @0x15a964 mov r2, #1 —— argc = 1 */
/* @0x15a968 ldr r1, [r10, r1] —— r1 = *(槽 0x3efce8) = 0x156198 <F_YoYo_CheckSecurity> */
/* @0x15a96c add r0, pc, r0 —— r0 = 0x34715c = "YoYo_CheckSecurity" */
/* @0x15a970 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_CheckSecurity", 0x156198 <F_YoYo_CheckSecurity>, 1, 0) */
/* ── #74 · 0x15a974..0x15a988 · get_timer → F_YoYo_GetTimer (0x156f90) · argc=0 · flag=0 ── */
/* @0x15a974 ldr r0, [pc, #0x990] —— 池字 0x1ec7e4：串偏移 → 0x347170 "get_timer" */
/* @0x15a978 mov r1, r6 —— r1 = fn = 0x156f90 <F_YoYo_GetTimer> */
/* @0x15a97c mov r2, r4 —— argc = 0 */
/* @0x15a980 mov r3, r4 —— flag = 0 */
/* @0x15a984 add r0, pc, r0 —— r0 = 0x347170 = "get_timer" */
/* @0x15a988 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("get_timer", 0x156f90 <F_YoYo_GetTimer>, 0, 0) */
/* ── #75 · 0x15a98c..0x15a9a0 · os_get_config → F_YoYo_GetConfig (0x156bb8) · argc=0 · flag=0 ── */
/* @0x15a98c ldr r0, [pc, #0x97c] —— 池字 0x1ec7d8：串偏移 → 0x34717c "os_get_config" */
/* @0x15a990 mov r1, r5 —— r1 = fn = 0x156bb8 <F_YoYo_GetConfig> */
/* @0x15a994 mov r2, r4 —— argc = 0 */
/* @0x15a998 mov r3, r4 —— flag = 0 */
/* @0x15a99c add r0, pc, r0 —— r0 = 0x34717c = "os_get_config" */
/* @0x15a9a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_get_config", 0x156bb8 <F_YoYo_GetConfig>, 0, 0) */
/* ── #76 · 0x15a9a4..0x15a9bc · os_get_info → F_YoYo_OsGetInfo (0x156fb0) · argc=0 · flag=0 ── */
/* @0x15a9a4 ldr r1, [pc, #0x968] —— 池字 0xffffe094：GOT 偏移 -0x1f6c → 槽 0x3efcec = 0x156fb0 <F_YoYo_OsGetInfo> */
/* @0x15a9a8 ldr r0, [pc, #0x968] —— 池字 0x1ec7cc：串偏移 → 0x34718c "os_get_info" */
/* @0x15a9ac mov r2, r4 —— argc = 0 */
/* @0x15a9b0 mov r3, r4 —— flag = 0 */
/* @0x15a9b4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcec) = 0x156fb0 <F_YoYo_OsGetInfo> */
/* @0x15a9b8 add r0, pc, r0 —— r0 = 0x34718c = "os_get_info" */
/* @0x15a9bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_get_info", 0x156fb0 <F_YoYo_OsGetInfo>, 0, 0) */
/* ── #77 · 0x15a9c0..0x15a9d8 · os_get_language → F_YoYo_GetLanguage (0x157610) · argc=0 · flag=0 ── */
/* @0x15a9c0 ldr r1, [pc, #0x954] —— 池字 0xffffe098：GOT 偏移 -0x1f68 → 槽 0x3efcf0 = 0x157610 <F_YoYo_GetLanguage> */
/* @0x15a9c4 ldr r0, [pc, #0x954] —— 池字 0x1ec7bc：串偏移 → 0x347198 "os_get_language" */
/* @0x15a9c8 mov r2, r4 —— argc = 0 */
/* @0x15a9cc mov r3, r4 —— flag = 0 */
/* @0x15a9d0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcf0) = 0x157610 <F_YoYo_GetLanguage> */
/* @0x15a9d4 add r0, pc, r0 —— r0 = 0x347198 = "os_get_language" */
/* @0x15a9d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_get_language", 0x157610 <F_YoYo_GetLanguage>, 0, 0) */
/* ── #78 · 0x15a9dc..0x15a9f4 · os_get_region → F_YoYo_GetRegion (0x15762c) · argc=0 · flag=0 ── */
/* @0x15a9dc ldr r1, [pc, #0x940] —— 池字 0xffffe09c：GOT 偏移 -0x1f64 → 槽 0x3efcf4 = 0x15762c <F_YoYo_GetRegion> */
/* @0x15a9e0 ldr r0, [pc, #0x940] —— 池字 0x1ec7b0：串偏移 → 0x3471a8 "os_get_region" */
/* @0x15a9e4 mov r2, r4 —— argc = 0 */
/* @0x15a9e8 mov r3, r4 —— flag = 0 */
/* @0x15a9ec ldr r1, [r10, r1] —— r1 = *(槽 0x3efcf4) = 0x15762c <F_YoYo_GetRegion> */
/* @0x15a9f0 add r0, pc, r0 —— r0 = 0x3471a8 = "os_get_region" */
/* @0x15a9f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_get_region", 0x15762c <F_YoYo_GetRegion>, 0, 0) */
/* ── #79 · 0x15a9f8..0x15aa10 · os_request_permission → F_YoYo_RequestPermission (0x157648) · argc=1 · flag=0 ── */
/* @0x15a9f8 ldr r1, [pc, #0x92c] —— 池字 0xffffe0a0：GOT 偏移 -0x1f60 → 槽 0x3efcf8 = 0x157648 <F_YoYo_RequestPermission> */
/* @0x15a9fc ldr r0, [pc, #0x92c] —— 池字 0x1ec7a4：串偏移 → 0x3471b8 "os_request_permission" */
/* @0x15aa00 mov r3, r4 —— flag = 0 */
/* @0x15aa04 mov r2, #1 —— argc = 1 */
/* @0x15aa08 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcf8) = 0x157648 <F_YoYo_RequestPermission> */
/* @0x15aa0c add r0, pc, r0 —— r0 = 0x3471b8 = "os_request_permission" */
/* @0x15aa10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_request_permission", 0x157648 <F_YoYo_RequestPermission>, 1, 0) */
/* ── #80 · 0x15aa14..0x15aa2c · os_check_permission → F_YoYo_CheckPermission (0x157674) · argc=1 · flag=0 ── */
/* @0x15aa14 ldr r1, [pc, #0x918] —— 池字 0xffffe0a4：GOT 偏移 -0x1f5c → 槽 0x3efcfc = 0x157674 <F_YoYo_CheckPermission> */
/* @0x15aa18 ldr r0, [pc, #0x918] —— 池字 0x1ec7a0：串偏移 → 0x3471d0 "os_check_permission" */
/* @0x15aa1c mov r3, r4 —— flag = 0 */
/* @0x15aa20 mov r2, #1 —— argc = 1 */
/* @0x15aa24 ldr r1, [r10, r1] —— r1 = *(槽 0x3efcfc) = 0x157674 <F_YoYo_CheckPermission> */
/* @0x15aa28 add r0, pc, r0 —— r0 = 0x3471d0 = "os_check_permission" */
/* @0x15aa2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_check_permission", 0x157674 <F_YoYo_CheckPermission>, 1, 0) */
/* ── #81 · 0x15aa30..0x15aa48 · code_is_compiled → F_CodeIsCompiled (0x156210) · argc=0 · flag=0 ── */
/* @0x15aa30 ldr r1, [pc, #0x904] —— 池字 0xffffe0a8：GOT 偏移 -0x1f58 → 槽 0x3efd00 = 0x156210 <F_CodeIsCompiled> */
/* @0x15aa34 ldr r0, [pc, #0x904] —— 池字 0x1ec798：串偏移 → 0x3471e4 "code_is_compiled" */
/* @0x15aa38 mov r2, r4 —— argc = 0 */
/* @0x15aa3c mov r3, r4 —— flag = 0 */
/* @0x15aa40 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd00) = 0x156210 <F_CodeIsCompiled> */
/* @0x15aa44 add r0, pc, r0 —— r0 = 0x3471e4 = "code_is_compiled" */
/* @0x15aa48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("code_is_compiled", 0x156210 <F_CodeIsCompiled>, 0, 0) */
/* ── #82 · 0x15aa4c..0x15aa64 · display_get_dpi_x → F_YoYo_GetDPIX (0x1576b8) · argc=0 · flag=0 ── */
/* @0x15aa4c ldr r1, [pc, #0x8f0] —— 池字 0xffffe0ac：GOT 偏移 -0x1f54 → 槽 0x3efd04 = 0x1576b8 <F_YoYo_GetDPIX> */
/* @0x15aa50 ldr r0, [pc, #0x8f0] —— 池字 0x1ec790：串偏移 → 0x3471f8 "display_get_dpi_x" */
/* @0x15aa54 mov r2, r4 —— argc = 0 */
/* @0x15aa58 mov r3, r4 —— flag = 0 */
/* @0x15aa5c ldr r1, [r10, r1] —— r1 = *(槽 0x3efd04) = 0x1576b8 <F_YoYo_GetDPIX> */
/* @0x15aa60 add r0, pc, r0 —— r0 = 0x3471f8 = "display_get_dpi_x" */
/* @0x15aa64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("display_get_dpi_x", 0x1576b8 <F_YoYo_GetDPIX>, 0, 0) */
/* ── #83 · 0x15aa68..0x15aa80 · display_get_dpi_y → F_YoYo_GetDPIY (0x1576e8) · argc=0 · flag=0 ── */
/* @0x15aa68 ldr r1, [pc, #0x8dc] —— 池字 0xffffe0b0：GOT 偏移 -0x1f50 → 槽 0x3efd08 = 0x1576e8 <F_YoYo_GetDPIY> */
/* @0x15aa6c ldr r0, [pc, #0x8dc] —— 池字 0x1ec788：串偏移 → 0x34720c "display_get_dpi_y" */
/* @0x15aa70 mov r2, r4 —— argc = 0 */
/* @0x15aa74 mov r3, r4 —— flag = 0 */
/* @0x15aa78 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd08) = 0x1576e8 <F_YoYo_GetDPIY> */
/* @0x15aa7c add r0, pc, r0 —— r0 = 0x34720c = "display_get_dpi_y" */
/* @0x15aa80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("display_get_dpi_y", 0x1576e8 <F_YoYo_GetDPIY>, 0, 0) */
/* ── #84 · 0x15aa84..0x15aa9c · display_set_gui_size → F_YoYo_SetGUISize (0x157718) · argc=2 · flag=0 ── */
/* @0x15aa84 ldr r1, [pc, #0x8c8] —— 池字 0xffffe0b4：GOT 偏移 -0x1f4c → 槽 0x3efd0c = 0x157718 <F_YoYo_SetGUISize> */
/* @0x15aa88 ldr r0, [pc, #0x8c8] —— 池字 0x1ec780：串偏移 → 0x347220 "display_set_gui_size" */
/* @0x15aa8c mov r3, r4 —— flag = 0 */
/* @0x15aa90 mov r2, #2 —— argc = 2 */
/* @0x15aa94 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd0c) = 0x157718 <F_YoYo_SetGUISize> */
/* @0x15aa98 add r0, pc, r0 —— r0 = 0x347220 = "display_set_gui_size" */
/* @0x15aa9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("display_set_gui_size", 0x157718 <F_YoYo_SetGUISize>, 2, 0) */
/* ── #85 · 0x15aaa0..0x15aab8 · display_get_gui_width → F_YoYo_GetGUIWidth (0x157908) · argc=0 · flag=0 ── */
/* @0x15aaa0 ldr r1, [pc, #0x8b4] —— 池字 0xffffe0b8：GOT 偏移 -0x1f48 → 槽 0x3efd10 = 0x157908 <F_YoYo_GetGUIWidth> */
/* @0x15aaa4 ldr r0, [pc, #0x8b4] —— 池字 0x1ec77c：串偏移 → 0x347238 "display_get_gui_width" */
/* @0x15aaa8 mov r2, r4 —— argc = 0 */
/* @0x15aaac mov r3, r4 —— flag = 0 */
/* @0x15aab0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd10) = 0x157908 <F_YoYo_GetGUIWidth> */
/* @0x15aab4 add r0, pc, r0 —— r0 = 0x347238 = "display_get_gui_width" */
/* @0x15aab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("display_get_gui_width", 0x157908 <F_YoYo_GetGUIWidth>, 0, 0) */
/* ── #86 · 0x15aabc..0x15aad4 · display_get_gui_height → F_YoYo_GetGUIHeight (0x15797c) · argc=0 · flag=0 ── */
/* @0x15aabc ldr r1, [pc, #0x8a0] —— 池字 0xffffe0bc：GOT 偏移 -0x1f44 → 槽 0x3efd14 = 0x15797c <F_YoYo_GetGUIHeight> */
/* @0x15aac0 ldr r0, [pc, #0x8a0] —— 池字 0x1ec778：串偏移 → 0x347250 "display_get_gui_height" */
/* @0x15aac4 mov r2, r4 —— argc = 0 */
/* @0x15aac8 mov r3, r4 —— flag = 0 */
/* @0x15aacc ldr r1, [r10, r1] —— r1 = *(槽 0x3efd14) = 0x15797c <F_YoYo_GetGUIHeight> */
/* @0x15aad0 add r0, pc, r0 —— r0 = 0x347250 = "display_get_gui_height" */
/* @0x15aad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("display_get_gui_height", 0x15797c <F_YoYo_GetGUIHeight>, 0, 0) */
/* ── #87 · 0x15aad8..0x15aaf0 · display_set_gui_maximise → F_YoYo_SetGUIMaximise (0x1577f4) · argc=2 · flag=0 ── */
/* @0x15aad8 ldr r1, [pc, #0x88c] —— 池字 0xffffe0c0：GOT 偏移 -0x1f40 → 槽 0x3efd18 = 0x1577f4 <F_YoYo_SetGUIMaximise> */
/* @0x15aadc ldr r0, [pc, #0x88c] —— 池字 0x1ec774：串偏移 → 0x347268 "display_set_gui_maximise" */
/* @0x15aae0 mov r3, r4 —— flag = 0 */
/* @0x15aae4 mov r2, #2 —— argc = 2 */
/* @0x15aae8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd18) = 0x1577f4 <F_YoYo_SetGUIMaximise> */
/* @0x15aaec add r0, pc, r0 —— r0 = 0x347268 = "display_set_gui_maximise" */
/* @0x15aaf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("display_set_gui_maximise", 0x1577f4 <F_YoYo_SetGUIMaximise>, 2, 0) */
/* ── #88 · 0x15aaf4..0x15ab10 · YoYo_OF_StartDashboard → F_YoYo_OF_StartDashboard (0x157094) · argc=0 · flag=0 ── */
/* @0x15aaf4 ldr r1, [pc, #0x878] —— 池字 0xffffe0c4：GOT 偏移 -0x1f3c → 槽 0x3efd1c = 0x157094 <F_YoYo_OF_StartDashboard> */
/* @0x15aaf8 ldr r0, [pc, #0x878] —— 池字 0x1ec774：串偏移 → 0x347284 "YoYo_OF_StartDashboard" */
/* @0x15aafc mov r2, r4 —— argc = 0 */
/* @0x15ab00 mov r3, r4 —— flag = 0 */
/* @0x15ab04 ldr r11, [r10, r1] —— r11 = *(槽 0x3efd1c) = 0x157094 <F_YoYo_OF_StartDashboard> */
/* @0x15ab08 add r0, pc, r0 —— r0 = 0x347284 = "YoYo_OF_StartDashboard" */
/* @0x15ab0c mov r1, r11 —— r1 = fn = 0x157094 <F_YoYo_OF_StartDashboard> */
/* @0x15ab10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_StartDashboard", 0x157094 <F_YoYo_OF_StartDashboard>, 0, 0) */
/* ── #89 · 0x15ab14..0x15ab30 · YoYo_OF_AddAchievement → F_YoYo_OF_AddAchievement (0x157098) · argc=2 · flag=0 ── */
/* @0x15ab14 ldr r1, [pc, #0x860] —— 池字 0xffffe0c8：GOT 偏移 -0x1f38 → 槽 0x3efd20 = 0x157098 <F_YoYo_OF_AddAchievement> */
/* @0x15ab18 ldr r0, [pc, #0x860] —— 池字 0x1ec76c：串偏移 → 0x34729c "YoYo_OF_AddAchievement" */
/* @0x15ab1c mov r3, r4 —— flag = 0 */
/* @0x15ab20 mov r2, #2 —— argc = 2 */
/* @0x15ab24 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd20) = 0x157098 <F_YoYo_OF_AddAchievement> */
/* @0x15ab28 add r0, pc, r0 —— r0 = 0x34729c = "YoYo_OF_AddAchievement" */
/* @0x15ab2c str r1, [sp, #0x4] —— 溢出：把 fn 0x157098 存到 sp+0x4（后面 2 条注册复用它） */
/* @0x15ab30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_AddAchievement", 0x157098 <F_YoYo_OF_AddAchievement>, 2, 0) */
/* ── #90 · 0x15ab34..0x15ab50 · YoYo_OF_AddLeaderboard → F_YoYo_OF_AddLeaderboard (0x159464) · argc=3 · flag=0 ── */
/* @0x15ab34 ldr r1, [pc, #0x848] —— 池字 0xffffe0cc：GOT 偏移 -0x1f34 → 槽 0x3efd24 = 0x159464 <F_YoYo_OF_AddLeaderboard> */
/* @0x15ab38 mov r3, r4 —— flag = 0 */
/* @0x15ab3c ldr r0, [pc, #0x844] —— 池字 0x1ec764：串偏移 → 0x3472b4 "YoYo_OF_AddLeaderboard" */
/* @0x15ab40 mov r2, #3 —— argc = 3 */
/* @0x15ab44 ldr r9, [r10, r1] —— r9 = *(槽 0x3efd24) = 0x159464 <F_YoYo_OF_AddLeaderboard> */
/* @0x15ab48 add r0, pc, r0 —— r0 = 0x3472b4 = "YoYo_OF_AddLeaderboard" */
/* @0x15ab4c mov r1, r9 —— r1 = fn = 0x159464 <F_YoYo_OF_AddLeaderboard> */
/* @0x15ab50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_AddLeaderboard", 0x159464 <F_YoYo_OF_AddLeaderboard>, 3, 0) */
/* ── #91 · 0x15ab54..0x15ab70 · YoYo_OF_SendChallenge → F_YoYo_OF_SendChallenge (0x1570cc) · argc=3 · flag=0 ── */
/* @0x15ab54 ldr r1, [pc, #0x830] —— 池字 0xffffe0d0：GOT 偏移 -0x1f30 → 槽 0x3efd28 = 0x1570cc <F_YoYo_OF_SendChallenge> */
/* @0x15ab58 ldr r0, [pc, #0x830] —— 池字 0x1ec75c：串偏移 → 0x3472cc "YoYo_OF_SendChallenge" */
/* @0x15ab5c mov r3, r4 —— flag = 0 */
/* @0x15ab60 mov r2, #3 —— argc = 3 */
/* @0x15ab64 ldr r8, [r10, r1] —— r8 = *(槽 0x3efd28) = 0x1570cc <F_YoYo_OF_SendChallenge> */
/* @0x15ab68 add r0, pc, r0 —— r0 = 0x3472cc = "YoYo_OF_SendChallenge" */
/* @0x15ab6c mov r1, r8 —— r1 = fn = 0x1570cc <F_YoYo_OF_SendChallenge> */
/* @0x15ab70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_SendChallenge", 0x1570cc <F_YoYo_OF_SendChallenge>, 3, 0) */
/* ── #92 · 0x15ab74..0x15ab90 · YoYo_OF_SendInvite → F_YoYo_OF_SendInvite (0x157114) · argc=1 · flag=0 ── */
/* @0x15ab74 ldr r1, [pc, #0x818] —— 池字 0xffffe0d4：GOT 偏移 -0x1f2c → 槽 0x3efd2c = 0x157114 <F_YoYo_OF_SendInvite> */
/* @0x15ab78 ldr r0, [pc, #0x818] —— 池字 0x1ec754：串偏移 → 0x3472e4 "YoYo_OF_SendInvite" */
/* @0x15ab7c mov r3, r4 —— flag = 0 */
/* @0x15ab80 mov r2, #1 —— argc = 1 */
/* @0x15ab84 ldr r7, [r10, r1] —— r7 = *(槽 0x3efd2c) = 0x157114 <F_YoYo_OF_SendInvite> */
/* @0x15ab88 add r0, pc, r0 —— r0 = 0x3472e4 = "YoYo_OF_SendInvite" */
/* @0x15ab8c mov r1, r7 —— r1 = fn = 0x157114 <F_YoYo_OF_SendInvite> */
/* @0x15ab90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_SendInvite", 0x157114 <F_YoYo_OF_SendInvite>, 1, 0) */
/* ── #93 · 0x15ab94..0x15abb0 · YoYo_OF_SendSocial → F_YoYo_OF_SendSocial (0x15712c) · argc=3 · flag=0 ── */
/* @0x15ab94 ldr r1, [pc, #0x800] —— 池字 0xffffe0d8：GOT 偏移 -0x1f28 → 槽 0x3efd30 = 0x15712c <F_YoYo_OF_SendSocial> */
/* @0x15ab98 ldr r0, [pc, #0x800] —— 池字 0x1ec748：串偏移 → 0x3472f8 "YoYo_OF_SendSocial" */
/* @0x15ab9c mov r3, r4 —— flag = 0 */
/* @0x15aba0 mov r2, #3 —— argc = 3 */
/* @0x15aba4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd30) = 0x15712c <F_YoYo_OF_SendSocial> */
/* @0x15aba8 add r0, pc, r0 —— r0 = 0x3472f8 = "YoYo_OF_SendSocial" */
/* @0x15abac str r1, [sp, #0x8] —— 溢出：把 fn 0x15712c 存到 sp+0x8（后面 2 条注册复用它） */
/* @0x15abb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_SendSocial", 0x15712c <F_YoYo_OF_SendSocial>, 3, 0) */
/* ── #94 · 0x15abb4..0x15abd0 · YoYo_OF_SetURL → F_YoYo_OF_SetURL (0x157174) · argc=1 · flag=0 ── */
/* @0x15abb4 ldr r1, [pc, #0x7e8] —— 池字 0xffffe0dc：GOT 偏移 -0x1f24 → 槽 0x3efd34 = 0x157174 <F_YoYo_OF_SetURL> */
/* @0x15abb8 mov r3, r4 —— flag = 0 */
/* @0x15abbc ldr r0, [pc, #0x7e4] —— 池字 0x1ec73c：串偏移 → 0x34730c "YoYo_OF_SetURL" */
/* @0x15abc0 mov r2, #1 —— argc = 1 */
/* @0x15abc4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd34) = 0x157174 <F_YoYo_OF_SetURL> */
/* @0x15abc8 add r0, pc, r0 —— r0 = 0x34730c = "YoYo_OF_SetURL" */
/* @0x15abcc str r1, [sp, #0xc] —— 溢出：把 fn 0x157174 存到 sp+0xc（后面 2 条注册复用它） */
/* @0x15abd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_SetURL", 0x157174 <F_YoYo_OF_SetURL>, 1, 0) */
/* ── #95 · 0x15abd4..0x15abf0 · YoYo_OF_AcceptChallenge → F_YoYo_OF_AcceptChallenge (0x15718c) · argc=0 · flag=0 ── */
/* @0x15abd4 ldr r1, [pc, #0x7d0] —— 池字 0xffffe0e0：GOT 偏移 -0x1f20 → 槽 0x3efd38 = 0x15718c <F_YoYo_OF_AcceptChallenge> */
/* @0x15abd8 mov r2, r4 —— argc = 0 */
/* @0x15abdc ldr r0, [pc, #0x7cc] —— 池字 0x1ec72c：串偏移 → 0x34731c "YoYo_OF_AcceptChallenge" */
/* @0x15abe0 mov r3, r4 —— flag = 0 */
/* @0x15abe4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd38) = 0x15718c <F_YoYo_OF_AcceptChallenge> */
/* @0x15abe8 add r0, pc, r0 —— r0 = 0x34731c = "YoYo_OF_AcceptChallenge" */
/* @0x15abec str r1, [sp, #0x10] —— 溢出：把 fn 0x15718c 存到 sp+0x10（后面 2 条注册复用它） */
/* @0x15abf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_AcceptChallenge", 0x15718c <F_YoYo_OF_AcceptChallenge>, 0, 0) */
/* ── #96 · 0x15abf4..0x15ac10 · YoYo_OF_IsOnline → F_YoYo_Achievement_IsOnline (0x1571a8) · argc=0 · flag=0 ── */
/* @0x15abf4 ldr r1, [pc, #0x7b8] —— 池字 0xffffe0e4：GOT 偏移 -0x1f1c → 槽 0x3efd3c = 0x1571a8 <F_YoYo_Achievement_IsOnline> */
/* @0x15abf8 mov r2, r4 —— argc = 0 */
/* @0x15abfc ldr r0, [pc, #0x7b4] —— 池字 0x1ec724：串偏移 → 0x347334 "YoYo_OF_IsOnline" */
/* @0x15ac00 mov r3, r4 —— flag = 0 */
/* @0x15ac04 ldr r6, [r10, r1] —— r6 = *(槽 0x3efd3c) = 0x1571a8 <F_YoYo_Achievement_IsOnline> */
/* @0x15ac08 add r0, pc, r0 —— r0 = 0x347334 = "YoYo_OF_IsOnline" */
/* @0x15ac0c mov r1, r6 —— r1 = fn = 0x1571a8 <F_YoYo_Achievement_IsOnline> */
/* @0x15ac10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_IsOnline", 0x1571a8 <F_YoYo_Achievement_IsOnline>, 0, 0) */
/* ── #97 · 0x15ac14..0x15ac30 · YoYo_OF_SendChallengeResult → F_YoYo_OF_SendChallengeResult (0x1571d8) · argc=2 · flag=0 ── */
/* @0x15ac14 ldr r1, [pc, #0x7a0] —— 池字 0xffffe0e8：GOT 偏移 -0x1f18 → 槽 0x3efd40 = 0x1571d8 <F_YoYo_OF_SendChallengeResult> */
/* @0x15ac18 ldr r0, [pc, #0x7a0] —— 池字 0x1ec718：串偏移 → 0x347348 "YoYo_OF_SendChallengeResult" */
/* @0x15ac1c mov r3, r4 —— flag = 0 */
/* @0x15ac20 mov r2, #2 —— argc = 2 */
/* @0x15ac24 ldr r5, [r10, r1] —— r5 = *(槽 0x3efd40) = 0x1571d8 <F_YoYo_OF_SendChallengeResult> */
/* @0x15ac28 add r0, pc, r0 —— r0 = 0x347348 = "YoYo_OF_SendChallengeResult" */
/* @0x15ac2c mov r1, r5 —— r1 = fn = 0x1571d8 <F_YoYo_OF_SendChallengeResult> */
/* @0x15ac30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OF_SendChallengeResult", 0x1571d8 <F_YoYo_OF_SendChallengeResult>, 2, 0) */
/* ── #98 · 0x15ac34..0x15ac48 · openfeint_start → F_YoYo_OF_StartDashboard (0x157094) · argc=0 · flag=0 ── */
/* @0x15ac34 ldr r0, [pc, #0x788] —— 池字 0x1ec718：串偏移 → 0x347364 "openfeint_start" */
/* @0x15ac38 mov r1, r11 —— r1 = fn = 0x157094 <F_YoYo_OF_StartDashboard> */
/* @0x15ac3c mov r2, r4 —— argc = 0 */
/* @0x15ac40 mov r3, r4 —— flag = 0 */
/* @0x15ac44 add r0, pc, r0 —— r0 = 0x347364 = "openfeint_start" */
/* @0x15ac48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("openfeint_start", 0x157094 <F_YoYo_OF_StartDashboard>, 0, 0) */
/* ── #99 · 0x15ac4c..0x15ac60 · achievement_map_achievement → F_YoYo_OF_AddAchievement (0x157098) · argc=2 · flag=0 ── */
/* @0x15ac4c ldr r0, [pc, #0x774] —— 池字 0x1ec714：串偏移 → 0x347374 "achievement_map_achievement" */
/* @0x15ac50 ldr r1, [sp, #0x4] —— r1 = fn（早先溢出在 sp+0x4）= 0x157098 <F_YoYo_OF_AddAchievement> */
/* @0x15ac54 mov r3, r4 —— flag = 0 */
/* @0x15ac58 add r0, pc, r0 —— r0 = 0x347374 = "achievement_map_achievement" */
/* @0x15ac5c mov r2, #2 —— argc = 2 */
/* @0x15ac60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_map_achievement", 0x157098 <F_YoYo_OF_AddAchievement>, 2, 0) */
/* ── #100 · 0x15ac64..0x15ac78 · achievement_map_leaderboard → F_YoYo_OF_AddLeaderboard (0x159464) · argc=3 · flag=0 ── */
/* @0x15ac64 ldr r0, [pc, #0x760] —— 池字 0x1ec718：串偏移 → 0x347390 "achievement_map_leaderboard" */
/* @0x15ac68 mov r1, r9 —— r1 = fn = 0x159464 <F_YoYo_OF_AddLeaderboard> */
/* @0x15ac6c mov r3, r4 —— flag = 0 */
/* @0x15ac70 add r0, pc, r0 —— r0 = 0x347390 = "achievement_map_leaderboard" */
/* @0x15ac74 mov r2, #3 —— argc = 3 */
/* @0x15ac78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_map_leaderboard", 0x159464 <F_YoYo_OF_AddLeaderboard>, 3, 0) */
/* ── #101 · 0x15ac7c..0x15ac90 · openfeint_send_challenge → F_YoYo_OF_SendChallenge (0x1570cc) · argc=3 · flag=0 ── */
/* @0x15ac7c ldr r0, [pc, #0x74c] —— 池字 0x1ec71c：串偏移 → 0x3473ac "openfeint_send_challenge" */
/* @0x15ac80 mov r1, r8 —— r1 = fn = 0x1570cc <F_YoYo_OF_SendChallenge> */
/* @0x15ac84 mov r3, r4 —— flag = 0 */
/* @0x15ac88 add r0, pc, r0 —— r0 = 0x3473ac = "openfeint_send_challenge" */
/* @0x15ac8c mov r2, #3 —— argc = 3 */
/* @0x15ac90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("openfeint_send_challenge", 0x1570cc <F_YoYo_OF_SendChallenge>, 3, 0) */
/* ── #102 · 0x15ac94..0x15aca8 · openfeint_send_invite → F_YoYo_OF_SendInvite (0x157114) · argc=1 · flag=0 ── */
/* @0x15ac94 ldr r0, [pc, #0x738] —— 池字 0x1ec720：串偏移 → 0x3473c8 "openfeint_send_invite" */
/* @0x15ac98 mov r1, r7 —— r1 = fn = 0x157114 <F_YoYo_OF_SendInvite> */
/* @0x15ac9c mov r3, r4 —— flag = 0 */
/* @0x15aca0 add r0, pc, r0 —— r0 = 0x3473c8 = "openfeint_send_invite" */
/* @0x15aca4 mov r2, #1 —— argc = 1 */
/* @0x15aca8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("openfeint_send_invite", 0x157114 <F_YoYo_OF_SendInvite>, 1, 0) */
/* ── #103 · 0x15acac..0x15acc0 · openfeint_send_social → F_YoYo_OF_SendSocial (0x15712c) · argc=3 · flag=0 ── */
/* @0x15acac ldr r0, [pc, #0x724] —— 池字 0x1ec720：串偏移 → 0x3473e0 "openfeint_send_social" */
/* @0x15acb0 ldr r1, [sp, #0x8] —— r1 = fn（早先溢出在 sp+0x8）= 0x15712c <F_YoYo_OF_SendSocial> */
/* @0x15acb4 mov r3, r4 —— flag = 0 */
/* @0x15acb8 add r0, pc, r0 —— r0 = 0x3473e0 = "openfeint_send_social" */
/* @0x15acbc mov r2, #3 —— argc = 3 */
/* @0x15acc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("openfeint_send_social", 0x15712c <F_YoYo_OF_SendSocial>, 3, 0) */
/* ── #104 · 0x15acc4..0x15acd8 · openfeint_set_url → F_YoYo_OF_SetURL (0x157174) · argc=1 · flag=0 ── */
/* @0x15acc4 ldr r0, [pc, #0x710] —— 池字 0x1ec720：串偏移 → 0x3473f8 "openfeint_set_url" */
/* @0x15acc8 ldr r1, [sp, #0xc] —— r1 = fn（早先溢出在 sp+0xc）= 0x157174 <F_YoYo_OF_SetURL> */
/* @0x15accc mov r3, r4 —— flag = 0 */
/* @0x15acd0 add r0, pc, r0 —— r0 = 0x3473f8 = "openfeint_set_url" */
/* @0x15acd4 mov r2, #1 —— argc = 1 */
/* @0x15acd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("openfeint_set_url", 0x157174 <F_YoYo_OF_SetURL>, 1, 0) */
/* ── #105 · 0x15acdc..0x15acf0 · openfeint_accept_challenge → F_YoYo_OF_AcceptChallenge (0x15718c) · argc=0 · flag=0 ── */
/* @0x15acdc ldr r0, [pc, #0x6fc] —— 池字 0x1ec718：串偏移 → 0x34740c "openfeint_accept_challenge" */
/* @0x15ace0 ldr r1, [sp, #0x10] —— r1 = fn（早先溢出在 sp+0x10）= 0x15718c <F_YoYo_OF_AcceptChallenge> */
/* @0x15ace4 mov r2, r4 —— argc = 0 */
/* @0x15ace8 mov r3, r4 —— flag = 0 */
/* @0x15acec add r0, pc, r0 —— r0 = 0x34740c = "openfeint_accept_challenge" */
/* @0x15acf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("openfeint_accept_challenge", 0x15718c <F_YoYo_OF_AcceptChallenge>, 0, 0) */
/* ── #106 · 0x15acf4..0x15ad08 · achievement_login_status → F_YoYo_Achievement_IsOnline (0x1571a8) · argc=0 · flag=0 ── */
/* @0x15acf4 ldr r0, [pc, #0x6e8] —— 池字 0x1ec71c：串偏移 → 0x347428 "achievement_login_status" */
/* @0x15acf8 mov r1, r6 —— r1 = fn = 0x1571a8 <F_YoYo_Achievement_IsOnline> */
/* @0x15acfc mov r2, r4 —— argc = 0 */
/* @0x15ad00 mov r3, r4 —— flag = 0 */
/* @0x15ad04 add r0, pc, r0 —— r0 = 0x347428 = "achievement_login_status" */
/* @0x15ad08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("achievement_login_status", 0x1571a8 <F_YoYo_Achievement_IsOnline>, 0, 0) */
/* ── #107 · 0x15ad0c..0x15ad20 · openfeint_send_result → F_YoYo_OF_SendChallengeResult (0x1571d8) · argc=2 · flag=0 ── */
/* @0x15ad0c ldr r0, [pc, #0x6d4] —— 池字 0x1ec724：串偏移 → 0x347444 "openfeint_send_result" */
/* @0x15ad10 mov r1, r5 —— r1 = fn = 0x1571d8 <F_YoYo_OF_SendChallengeResult> */
/* @0x15ad14 mov r3, r4 —— flag = 0 */
/* @0x15ad18 add r0, pc, r0 —— r0 = 0x347444 = "openfeint_send_result" */
/* @0x15ad1c mov r2, #2 —— argc = 2 */
/* @0x15ad20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("openfeint_send_result", 0x1571d8 <F_YoYo_OF_SendChallengeResult>, 2, 0) */
/* ── #108 · 0x15ad24..0x15ad40 · YoYo_MouseCheckButton → F_YoYo_MouseCheckButton (0x15e690) · argc=2 · flag=0 ── */
/* @0x15ad24 ldr r1, [pc, #0x6c0] —— 池字 0xffffe0ec：GOT 偏移 -0x1f14 → 槽 0x3efd44 = 0x15e690 <F_YoYo_MouseCheckButton> */
/* @0x15ad28 ldr r0, [pc, #0x6c0] —— 池字 0x1ec71c：串偏移 → 0x34745c "YoYo_MouseCheckButton" */
/* @0x15ad2c mov r3, r4 —— flag = 0 */
/* @0x15ad30 mov r2, #2 —— argc = 2 */
/* @0x15ad34 ldr r11, [r10, r1] —— r11 = *(槽 0x3efd44) = 0x15e690 <F_YoYo_MouseCheckButton> */
/* @0x15ad38 add r0, pc, r0 —— r0 = 0x34745c = "YoYo_MouseCheckButton" */
/* @0x15ad3c mov r1, r11 —— r1 = fn = 0x15e690 <F_YoYo_MouseCheckButton> */
/* @0x15ad40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_MouseCheckButton", 0x15e690 <F_YoYo_MouseCheckButton>, 2, 0) */
/* ── #109 · 0x15ad44..0x15ad60 · YoYo_MouseCheckButtonPressed → F_YoYo_MouseCheckButtonPressed (0x15e6dc) · argc=2 · flag=0 ── */
/* @0x15ad44 ldr r1, [pc, #0x6a8] —— 池字 0xffffe0f0：GOT 偏移 -0x1f10 → 槽 0x3efd48 = 0x15e6dc <F_YoYo_MouseCheckButtonPressed> */
/* @0x15ad48 ldr r0, [pc, #0x6a8] —— 池字 0x1ec714：串偏移 → 0x347474 "YoYo_MouseCheckButtonPressed" */
/* @0x15ad4c mov r3, r4 —— flag = 0 */
/* @0x15ad50 mov r2, #2 —— argc = 2 */
/* @0x15ad54 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd48) = 0x15e6dc <F_YoYo_MouseCheckButtonPressed> */
/* @0x15ad58 add r0, pc, r0 —— r0 = 0x347474 = "YoYo_MouseCheckButtonPressed" */
/* @0x15ad5c str r1, [sp, #0x4] —— 溢出：把 fn 0x15e6dc 存到 sp+0x4（后面 2 条注册复用它） */
/* @0x15ad60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_MouseCheckButtonPressed", 0x15e6dc <F_YoYo_MouseCheckButtonPressed>, 2, 0) */
/* ── #110 · 0x15ad64..0x15ad80 · YoYo_MouseCheckButtonReleased → F_YoYo_MouseCheckButtonReleased (0x15e728) · argc=2 · flag=0 ── */
/* @0x15ad64 ldr r1, [pc, #0x690] —— 池字 0xffffe0f4：GOT 偏移 -0x1f0c → 槽 0x3efd4c = 0x15e728 <F_YoYo_MouseCheckButtonReleased> */
/* @0x15ad68 mov r3, r4 —— flag = 0 */
/* @0x15ad6c ldr r0, [pc, #0x68c] —— 池字 0x1ec714：串偏移 → 0x347494 "YoYo_MouseCheckButtonReleased" */
/* @0x15ad70 mov r2, #2 —— argc = 2 */
/* @0x15ad74 ldr r9, [r10, r1] —— r9 = *(槽 0x3efd4c) = 0x15e728 <F_YoYo_MouseCheckButtonReleased> */
/* @0x15ad78 add r0, pc, r0 —— r0 = 0x347494 = "YoYo_MouseCheckButtonReleased" */
/* @0x15ad7c mov r1, r9 —— r1 = fn = 0x15e728 <F_YoYo_MouseCheckButtonReleased> */
/* @0x15ad80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_MouseCheckButtonReleased", 0x15e728 <F_YoYo_MouseCheckButtonReleased>, 2, 0) */
/* ── #111 · 0x15ad84..0x15ada0 · YoYo_MouseX → F_YoYo_MouseX (0x15e774) · argc=1 · flag=0 ── */
/* @0x15ad84 ldr r1, [pc, #0x678] —— 池字 0xffffe0f8：GOT 偏移 -0x1f08 → 槽 0x3efd50 = 0x15e774 <F_YoYo_MouseX> */
/* @0x15ad88 ldr r0, [pc, #0x678] —— 池字 0x1ec714：串偏移 → 0x3474b4 "YoYo_MouseX" */
/* @0x15ad8c mov r3, r4 —— flag = 0 */
/* @0x15ad90 mov r2, #1 —— argc = 1 */
/* @0x15ad94 ldr r8, [r10, r1] —— r8 = *(槽 0x3efd50) = 0x15e774 <F_YoYo_MouseX> */
/* @0x15ad98 add r0, pc, r0 —— r0 = 0x3474b4 = "YoYo_MouseX" */
/* @0x15ad9c mov r1, r8 —— r1 = fn = 0x15e774 <F_YoYo_MouseX> */
/* @0x15ada0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_MouseX", 0x15e774 <F_YoYo_MouseX>, 1, 0) */
/* ── #112 · 0x15ada4..0x15adc0 · YoYo_MouseY → F_YoYo_MouseY (0x15e7b0) · argc=1 · flag=0 ── */
/* @0x15ada4 ldr r1, [pc, #0x660] —— 池字 0xffffe0fc：GOT 偏移 -0x1f04 → 槽 0x3efd54 = 0x15e7b0 <F_YoYo_MouseY> */
/* @0x15ada8 ldr r0, [pc, #0x660] —— 池字 0x1ec700：串偏移 → 0x3474c0 "YoYo_MouseY" */
/* @0x15adac mov r3, r4 —— flag = 0 */
/* @0x15adb0 mov r2, #1 —— argc = 1 */
/* @0x15adb4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd54) = 0x15e7b0 <F_YoYo_MouseY> */
/* @0x15adb8 add r0, pc, r0 —— r0 = 0x3474c0 = "YoYo_MouseY" */
/* @0x15adbc str r1, [sp, #0x8] —— 溢出：把 fn 0x15e7b0 存到 sp+0x8（后面 2 条注册复用它） */
/* @0x15adc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_MouseY", 0x15e7b0 <F_YoYo_MouseY>, 1, 0) */
/* ── #113 · 0x15adc4..0x15ade0 · YoYo_MouseXRaw → F_YoYo_MouseXRaw (0x159eb0) · argc=1 · flag=0 ── */
/* @0x15adc4 ldr r1, [pc, #0x648] —— 池字 0xffffe100：GOT 偏移 -0x1f00 → 槽 0x3efd58 = 0x159eb0 <F_YoYo_MouseXRaw> */
/* @0x15adc8 mov r3, r4 —— flag = 0 */
/* @0x15adcc ldr r0, [pc, #0x644] —— 池字 0x1ec6ec：串偏移 → 0x3474cc "YoYo_MouseXRaw" */
/* @0x15add0 mov r2, #1 —— argc = 1 */
/* @0x15add4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd58) = 0x159eb0 <F_YoYo_MouseXRaw> */
/* @0x15add8 add r0, pc, r0 —— r0 = 0x3474cc = "YoYo_MouseXRaw" */
/* @0x15addc str r1, [sp, #0xc] —— 溢出：把 fn 0x159eb0 存到 sp+0xc（后面 2 条注册复用它） */
/* @0x15ade0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_MouseXRaw", 0x159eb0 <F_YoYo_MouseXRaw>, 1, 0) */
/* ── #114 · 0x15ade4..0x15ae00 · YoYo_MouseYRaw → F_YoYo_MouseYRaw (0x159f10) · argc=1 · flag=0 ── */
/* @0x15ade4 ldr r1, [pc, #0x630] —— 池字 0xffffe104：GOT 偏移 -0x1efc → 槽 0x3efd5c = 0x159f10 <F_YoYo_MouseYRaw> */
/* @0x15ade8 mov r3, r4 —— flag = 0 */
/* @0x15adec ldr r0, [pc, #0x62c] —— 池字 0x1ec6dc：串偏移 → 0x3474dc "YoYo_MouseYRaw" */
/* @0x15adf0 mov r2, #1 —— argc = 1 */
/* @0x15adf4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd5c) = 0x159f10 <F_YoYo_MouseYRaw> */
/* @0x15adf8 add r0, pc, r0 —— r0 = 0x3474dc = "YoYo_MouseYRaw" */
/* @0x15adfc str r1, [sp, #0x10] —— 溢出：把 fn 0x159f10 存到 sp+0x10（后面 2 条注册复用它） */
/* @0x15ae00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_MouseYRaw", 0x159f10 <F_YoYo_MouseYRaw>, 1, 0) */
/* ── #115 · 0x15ae04..0x15ae20 · YoYo_GetTiltX → F_YoYo_GetTiltX (0x1560d8) · argc=0 · flag=0 ── */
/* @0x15ae04 ldr r1, [pc, #0x618] —— 池字 0xffffe108：GOT 偏移 -0x1ef8 → 槽 0x3efd60 = 0x1560d8 <F_YoYo_GetTiltX> */
/* @0x15ae08 mov r2, r4 —— argc = 0 */
/* @0x15ae0c ldr r0, [pc, #0x614] —— 池字 0x1ec6cc：串偏移 → 0x3474ec "YoYo_GetTiltX" */
/* @0x15ae10 mov r3, r4 —— flag = 0 */
/* @0x15ae14 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd60) = 0x1560d8 <F_YoYo_GetTiltX> */
/* @0x15ae18 add r0, pc, r0 —— r0 = 0x3474ec = "YoYo_GetTiltX" */
/* @0x15ae1c str r1, [sp, #0x14] —— 溢出：把 fn 0x1560d8 存到 sp+0x14（后面 2 条注册复用它） */
/* @0x15ae20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetTiltX", 0x1560d8 <F_YoYo_GetTiltX>, 0, 0) */
/* ── #116 · 0x15ae24..0x15ae40 · YoYo_GetTiltY → F_YoYo_GetTiltY (0x156100) · argc=0 · flag=0 ── */
/* @0x15ae24 ldr r1, [pc, #0x600] —— 池字 0xffffe10c：GOT 偏移 -0x1ef4 → 槽 0x3efd64 = 0x156100 <F_YoYo_GetTiltY> */
/* @0x15ae28 mov r2, r4 —— argc = 0 */
/* @0x15ae2c ldr r0, [pc, #0x5fc] —— 池字 0x1ec6bc：串偏移 → 0x3474fc "YoYo_GetTiltY" */
/* @0x15ae30 mov r3, r4 —— flag = 0 */
/* @0x15ae34 ldr r7, [r10, r1] —— r7 = *(槽 0x3efd64) = 0x156100 <F_YoYo_GetTiltY> */
/* @0x15ae38 add r0, pc, r0 —— r0 = 0x3474fc = "YoYo_GetTiltY" */
/* @0x15ae3c mov r1, r7 —— r1 = fn = 0x156100 <F_YoYo_GetTiltY> */
/* @0x15ae40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetTiltY", 0x156100 <F_YoYo_GetTiltY>, 0, 0) */
/* ── #117 · 0x15ae44..0x15ae60 · YoYo_GetTiltZ → F_YoYo_GetTiltZ (0x156128) · argc=0 · flag=0 ── */
/* @0x15ae44 ldr r1, [pc, #0x5e8] —— 池字 0xffffe110：GOT 偏移 -0x1ef0 → 槽 0x3efd68 = 0x156128 <F_YoYo_GetTiltZ> */
/* @0x15ae48 ldr r0, [pc, #0x5e8] —— 池字 0x1ec6ac：串偏移 → 0x34750c "YoYo_GetTiltZ" */
/* @0x15ae4c mov r2, r4 —— argc = 0 */
/* @0x15ae50 mov r3, r4 —— flag = 0 */
/* @0x15ae54 ldr r6, [r10, r1] —— r6 = *(槽 0x3efd68) = 0x156128 <F_YoYo_GetTiltZ> */
/* @0x15ae58 add r0, pc, r0 —— r0 = 0x34750c = "YoYo_GetTiltZ" */
/* @0x15ae5c mov r1, r6 —— r1 = fn = 0x156128 <F_YoYo_GetTiltZ> */
/* @0x15ae60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_GetTiltZ", 0x156128 <F_YoYo_GetTiltZ>, 0, 0) */
/* ── #118 · 0x15ae64..0x15ae80 · YoYo_IsKeypadOpen → F_YoYo_IsKeypadOpen (0x156150) · argc=0 · flag=0 ── */
/* @0x15ae64 ldr r1, [pc, #0x5d0] —— 池字 0xffffe114：GOT 偏移 -0x1eec → 槽 0x3efd6c = 0x156150 <F_YoYo_IsKeypadOpen> */
/* @0x15ae68 ldr r0, [pc, #0x5d0] —— 池字 0x1ec69c：串偏移 → 0x34751c "YoYo_IsKeypadOpen" */
/* @0x15ae6c mov r2, r4 —— argc = 0 */
/* @0x15ae70 mov r3, r4 —— flag = 0 */
/* @0x15ae74 ldr r5, [r10, r1] —— r5 = *(槽 0x3efd6c) = 0x156150 <F_YoYo_IsKeypadOpen> */
/* @0x15ae78 add r0, pc, r0 —— r0 = 0x34751c = "YoYo_IsKeypadOpen" */
/* @0x15ae7c mov r1, r5 —— r1 = fn = 0x156150 <F_YoYo_IsKeypadOpen> */
/* @0x15ae80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_IsKeypadOpen", 0x156150 <F_YoYo_IsKeypadOpen>, 0, 0) */
/* ── #119 · 0x15ae84..0x15ae98 · device_mouse_check_button → F_YoYo_MouseCheckButton (0x15e690) · argc=2 · flag=0 ── */
/* @0x15ae84 ldr r0, [pc, #0x5b8] —— 池字 0x1ec698：串偏移 → 0x347530 "device_mouse_check_button" */
/* @0x15ae88 mov r1, r11 —— r1 = fn = 0x15e690 <F_YoYo_MouseCheckButton> */
/* @0x15ae8c mov r3, r4 —— flag = 0 */
/* @0x15ae90 add r0, pc, r0 —— r0 = 0x347530 = "device_mouse_check_button" */
/* @0x15ae94 mov r2, #2 —— argc = 2 */
/* @0x15ae98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_check_button", 0x15e690 <F_YoYo_MouseCheckButton>, 2, 0) */
/* ── #120 · 0x15ae9c..0x15aeb0 · device_mouse_check_button_pressed → F_YoYo_MouseCheckButtonPressed (0x15e6dc) · argc=2 · flag=0 ── */
/* @0x15ae9c ldr r0, [pc, #0x5a4] —— 池字 0x1ec69c：串偏移 → 0x34754c "device_mouse_check_button_pressed" */
/* @0x15aea0 ldr r1, [sp, #0x4] —— r1 = fn（早先溢出在 sp+0x4）= 0x15e6dc <F_YoYo_MouseCheckButtonPressed> */
/* @0x15aea4 mov r3, r4 —— flag = 0 */
/* @0x15aea8 add r0, pc, r0 —— r0 = 0x34754c = "device_mouse_check_button_pressed" */
/* @0x15aeac mov r2, #2 —— argc = 2 */
/* @0x15aeb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_check_button_pressed", 0x15e6dc <F_YoYo_MouseCheckButtonPressed>, 2, 0) */
/* ── #121 · 0x15aeb4..0x15aec8 · device_mouse_check_button_released → F_YoYo_MouseCheckButtonReleased (0x15e728) · argc=2 · flag=0 ── */
/* @0x15aeb4 ldr r0, [pc, #0x590] —— 池字 0x1ec6a8：串偏移 → 0x347570 "device_mouse_check_button_released" */
/* @0x15aeb8 mov r1, r9 —— r1 = fn = 0x15e728 <F_YoYo_MouseCheckButtonReleased> */
/* @0x15aebc mov r3, r4 —— flag = 0 */
/* @0x15aec0 add r0, pc, r0 —— r0 = 0x347570 = "device_mouse_check_button_released" */
/* @0x15aec4 mov r2, #2 —— argc = 2 */
/* @0x15aec8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_check_button_released", 0x15e728 <F_YoYo_MouseCheckButtonReleased>, 2, 0) */
/* ── #122 · 0x15aecc..0x15aee0 · device_mouse_x → F_YoYo_MouseX (0x15e774) · argc=1 · flag=0 ── */
/* @0x15aecc ldr r0, [pc, #0x57c] —— 池字 0x1ec6b4：串偏移 → 0x347594 "device_mouse_x" */
/* @0x15aed0 mov r1, r8 —— r1 = fn = 0x15e774 <F_YoYo_MouseX> */
/* @0x15aed4 mov r3, r4 —— flag = 0 */
/* @0x15aed8 add r0, pc, r0 —— r0 = 0x347594 = "device_mouse_x" */
/* @0x15aedc mov r2, #1 —— argc = 1 */
/* @0x15aee0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_x", 0x15e774 <F_YoYo_MouseX>, 1, 0) */
/* ── #123 · 0x15aee4..0x15aef8 · device_mouse_y → F_YoYo_MouseY (0x15e7b0) · argc=1 · flag=0 ── */
/* @0x15aee4 ldr r0, [pc, #0x568] —— 池字 0x1ec6ac：串偏移 → 0x3475a4 "device_mouse_y" */
/* @0x15aee8 ldr r1, [sp, #0x8] —— r1 = fn（早先溢出在 sp+0x8）= 0x15e7b0 <F_YoYo_MouseY> */
/* @0x15aeec mov r3, r4 —— flag = 0 */
/* @0x15aef0 add r0, pc, r0 —— r0 = 0x3475a4 = "device_mouse_y" */
/* @0x15aef4 mov r2, #1 —— argc = 1 */
/* @0x15aef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_y", 0x15e7b0 <F_YoYo_MouseY>, 1, 0) */
/* ── #124 · 0x15aefc..0x15af10 · device_mouse_raw_x → F_YoYo_MouseXRaw (0x159eb0) · argc=1 · flag=0 ── */
/* @0x15aefc ldr r0, [pc, #0x554] —— 池字 0x1ec6a4：串偏移 → 0x3475b4 "device_mouse_raw_x" */
/* @0x15af00 ldr r1, [sp, #0xc] —— r1 = fn（早先溢出在 sp+0xc）= 0x159eb0 <F_YoYo_MouseXRaw> */
/* @0x15af04 mov r3, r4 —— flag = 0 */
/* @0x15af08 add r0, pc, r0 —— r0 = 0x3475b4 = "device_mouse_raw_x" */
/* @0x15af0c mov r2, #1 —— argc = 1 */
/* @0x15af10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_raw_x", 0x159eb0 <F_YoYo_MouseXRaw>, 1, 0) */
/* ── #125 · 0x15af14..0x15af28 · device_mouse_raw_y → F_YoYo_MouseYRaw (0x159f10) · argc=1 · flag=0 ── */
/* @0x15af14 ldr r0, [pc, #0x540] —— 池字 0x1ec6a0：串偏移 → 0x3475c8 "device_mouse_raw_y" */
/* @0x15af18 ldr r1, [sp, #0x10] —— r1 = fn（早先溢出在 sp+0x10）= 0x159f10 <F_YoYo_MouseYRaw> */
/* @0x15af1c mov r3, r4 —— flag = 0 */
/* @0x15af20 add r0, pc, r0 —— r0 = 0x3475c8 = "device_mouse_raw_y" */
/* @0x15af24 mov r2, #1 —— argc = 1 */
/* @0x15af28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_raw_y", 0x159f10 <F_YoYo_MouseYRaw>, 1, 0) */
/* ── #126 · 0x15af2c..0x15af44 · device_mouse_x_to_gui → F_MouseXToGUI (0x158704) · argc=1 · flag=0 ── */
/* @0x15af2c ldr r1, [pc, #0x52c] —— 池字 0xffffe118：GOT 偏移 -0x1ee8 → 槽 0x3efd70 = 0x158704 <F_MouseXToGUI> */
/* @0x15af30 ldr r0, [pc, #0x52c] —— 池字 0x1ec694：串偏移 → 0x3475dc "device_mouse_x_to_gui" */
/* @0x15af34 mov r3, r4 —— flag = 0 */
/* @0x15af38 mov r2, #1 —— argc = 1 */
/* @0x15af3c ldr r1, [r10, r1] —— r1 = *(槽 0x3efd70) = 0x158704 <F_MouseXToGUI> */
/* @0x15af40 add r0, pc, r0 —— r0 = 0x3475dc = "device_mouse_x_to_gui" */
/* @0x15af44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_x_to_gui", 0x158704 <F_MouseXToGUI>, 1, 0) */
/* ── #127 · 0x15af48..0x15af60 · device_mouse_y_to_gui → F_MouseYToGUI (0x158794) · argc=1 · flag=0 ── */
/* @0x15af48 ldr r1, [pc, #0x518] —— 池字 0xffffe11c：GOT 偏移 -0x1ee4 → 槽 0x3efd74 = 0x158794 <F_MouseYToGUI> */
/* @0x15af4c ldr r0, [pc, #0x518] —— 池字 0x1ec690：串偏移 → 0x3475f4 "device_mouse_y_to_gui" */
/* @0x15af50 mov r3, r4 —— flag = 0 */
/* @0x15af54 mov r2, #1 —— argc = 1 */
/* @0x15af58 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd74) = 0x158794 <F_MouseYToGUI> */
/* @0x15af5c add r0, pc, r0 —— r0 = 0x3475f4 = "device_mouse_y_to_gui" */
/* @0x15af60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_mouse_y_to_gui", 0x158794 <F_MouseYToGUI>, 1, 0) */
/* ── #128 · 0x15af64..0x15af78 · device_get_tilt_x → F_YoYo_GetTiltX (0x1560d8) · argc=0 · flag=0 ── */
/* @0x15af64 ldr r0, [pc, #0x504] —— 池字 0x1ec690：串偏移 → 0x34760c "device_get_tilt_x" */
/* @0x15af68 ldr r1, [sp, #0x14] —— r1 = fn（早先溢出在 sp+0x14）= 0x1560d8 <F_YoYo_GetTiltX> */
/* @0x15af6c mov r2, r4 —— argc = 0 */
/* @0x15af70 mov r3, r4 —— flag = 0 */
/* @0x15af74 add r0, pc, r0 —— r0 = 0x34760c = "device_get_tilt_x" */
/* @0x15af78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_get_tilt_x", 0x1560d8 <F_YoYo_GetTiltX>, 0, 0) */
/* ── #129 · 0x15af7c..0x15af90 · device_get_tilt_y → F_YoYo_GetTiltY (0x156100) · argc=0 · flag=0 ── */
/* @0x15af7c ldr r0, [pc, #0x4f0] —— 池字 0x1ec68c：串偏移 → 0x347620 "device_get_tilt_y" */
/* @0x15af80 mov r1, r7 —— r1 = fn = 0x156100 <F_YoYo_GetTiltY> */
/* @0x15af84 mov r2, r4 —— argc = 0 */
/* @0x15af88 mov r3, r4 —— flag = 0 */
/* @0x15af8c add r0, pc, r0 —— r0 = 0x347620 = "device_get_tilt_y" */
/* @0x15af90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_get_tilt_y", 0x156100 <F_YoYo_GetTiltY>, 0, 0) */
/* ── #130 · 0x15af94..0x15afa8 · device_get_tilt_z → F_YoYo_GetTiltZ (0x156128) · argc=0 · flag=0 ── */
/* @0x15af94 ldr r0, [pc, #0x4dc] —— 池字 0x1ec688：串偏移 → 0x347634 "device_get_tilt_z" */
/* @0x15af98 mov r1, r6 —— r1 = fn = 0x156128 <F_YoYo_GetTiltZ> */
/* @0x15af9c mov r2, r4 —— argc = 0 */
/* @0x15afa0 mov r3, r4 —— flag = 0 */
/* @0x15afa4 add r0, pc, r0 —— r0 = 0x347634 = "device_get_tilt_z" */
/* @0x15afa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_get_tilt_z", 0x156128 <F_YoYo_GetTiltZ>, 0, 0) */
/* ── #131 · 0x15afac..0x15afc0 · device_is_keypad_open → F_YoYo_IsKeypadOpen (0x156150) · argc=0 · flag=0 ── */
/* @0x15afac ldr r0, [pc, #0x4c8] —— 池字 0x1ec684：串偏移 → 0x347648 "device_is_keypad_open" */
/* @0x15afb0 mov r1, r5 —— r1 = fn = 0x156150 <F_YoYo_IsKeypadOpen> */
/* @0x15afb4 mov r2, r4 —— argc = 0 */
/* @0x15afb8 mov r3, r4 —— flag = 0 */
/* @0x15afbc add r0, pc, r0 —— r0 = 0x347648 = "device_is_keypad_open" */
/* @0x15afc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("device_is_keypad_open", 0x156150 <F_YoYo_IsKeypadOpen>, 0, 0) */
/* ── #132 · 0x15afc4..0x15afdc · facebook_init → F_YoYo_FacebookInit (0x15720c) · argc=0 · flag=0 ── */
/* @0x15afc4 ldr r1, [pc, #0x4b4] —— 池字 0xffffe120：GOT 偏移 -0x1ee0 → 槽 0x3efd78 = 0x15720c <F_YoYo_FacebookInit> */
/* @0x15afc8 ldr r0, [pc, #0x4b4] —— 池字 0x1ec680：串偏移 → 0x347660 "facebook_init" */
/* @0x15afcc mov r2, r4 —— argc = 0 */
/* @0x15afd0 mov r3, r4 —— flag = 0 */
/* @0x15afd4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd78) = 0x15720c <F_YoYo_FacebookInit> */
/* @0x15afd8 add r0, pc, r0 —— r0 = 0x347660 = "facebook_init" */
/* @0x15afdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_init", 0x15720c <F_YoYo_FacebookInit>, 0, 0) */
/* ── #133 · 0x15afe0..0x15aff8 · facebook_login → F_YoYo_FacebookLogin (0x15723c) · argc=2 · flag=0 ── */
/* @0x15afe0 ldr r1, [pc, #0x4a0] —— 池字 0xffffe124：GOT 偏移 -0x1edc → 槽 0x3efd7c = 0x15723c <F_YoYo_FacebookLogin> */
/* @0x15afe4 ldr r0, [pc, #0x4a0] —— 池字 0x1ec674：串偏移 → 0x347670 "facebook_login" */
/* @0x15afe8 mov r3, r4 —— flag = 0 */
/* @0x15afec mov r2, #2 —— argc = 2 */
/* @0x15aff0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd7c) = 0x15723c <F_YoYo_FacebookLogin> */
/* @0x15aff4 add r0, pc, r0 —— r0 = 0x347670 = "facebook_login" */
/* @0x15aff8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_login", 0x15723c <F_YoYo_FacebookLogin>, 2, 0) */
/* ── #134 · 0x15affc..0x15b014 · facebook_status → F_YoYo_FacebookLoginStatus (0x157290) · argc=0 · flag=0 ── */
/* @0x15affc ldr r1, [pc, #0x48c] —— 池字 0xffffe128：GOT 偏移 -0x1ed8 → 槽 0x3efd80 = 0x157290 <F_YoYo_FacebookLoginStatus> */
/* @0x15b000 ldr r0, [pc, #0x48c] —— 池字 0x1ec668：串偏移 → 0x347680 "facebook_status" */
/* @0x15b004 mov r2, r4 —— argc = 0 */
/* @0x15b008 mov r3, r4 —— flag = 0 */
/* @0x15b00c ldr r1, [r10, r1] —— r1 = *(槽 0x3efd80) = 0x157290 <F_YoYo_FacebookLoginStatus> */
/* @0x15b010 add r0, pc, r0 —— r0 = 0x347680 = "facebook_status" */
/* @0x15b014 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_status", 0x157290 <F_YoYo_FacebookLoginStatus>, 0, 0) */
/* ── #135 · 0x15b018..0x15b030 · facebook_graph_request → F_YoYo_FacebookGraphRequest (0x1572ac) · argc=4 · flag=0 ── */
/* @0x15b018 ldr r1, [pc, #0x478] —— 池字 0xffffe12c：GOT 偏移 -0x1ed4 → 槽 0x3efd84 = 0x1572ac <F_YoYo_FacebookGraphRequest> */
/* @0x15b01c ldr r0, [pc, #0x478] —— 池字 0x1ec65c：串偏移 → 0x347690 "facebook_graph_request" */
/* @0x15b020 mov r3, r4 —— flag = 0 */
/* @0x15b024 mov r2, #4 —— argc = 4 */
/* @0x15b028 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd84) = 0x1572ac <F_YoYo_FacebookGraphRequest> */
/* @0x15b02c add r0, pc, r0 —— r0 = 0x347690 = "facebook_graph_request" */
/* @0x15b030 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_graph_request", 0x1572ac <F_YoYo_FacebookGraphRequest>, 4, 0) */
/* ── #136 · 0x15b034..0x15b04c · facebook_dialog → F_YoYo_FacebookDialog (0x157328) · argc=3 · flag=0 ── */
/* @0x15b034 ldr r1, [pc, #0x464] —— 池字 0xffffe130：GOT 偏移 -0x1ed0 → 槽 0x3efd88 = 0x157328 <F_YoYo_FacebookDialog> */
/* @0x15b038 ldr r0, [pc, #0x464] —— 池字 0x1ec658：串偏移 → 0x3476a8 "facebook_dialog" */
/* @0x15b03c mov r3, r4 —— flag = 0 */
/* @0x15b040 mov r2, #3 —— argc = 3 */
/* @0x15b044 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd88) = 0x157328 <F_YoYo_FacebookDialog> */
/* @0x15b048 add r0, pc, r0 —— r0 = 0x3476a8 = "facebook_dialog" */
/* @0x15b04c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_dialog", 0x157328 <F_YoYo_FacebookDialog>, 3, 0) */
/* ── #137 · 0x15b050..0x15b068 · facebook_logout → F_YoYo_FacebookLogout (0x157520) · argc=0 · flag=0 ── */
/* @0x15b050 ldr r1, [pc, #0x450] —— 池字 0xffffe134：GOT 偏移 -0x1ecc → 槽 0x3efd8c = 0x157520 <F_YoYo_FacebookLogout> */
/* @0x15b054 ldr r0, [pc, #0x450] —— 池字 0x1ec64c：串偏移 → 0x3476b8 "facebook_logout" */
/* @0x15b058 mov r2, r4 —— argc = 0 */
/* @0x15b05c mov r3, r4 —— flag = 0 */
/* @0x15b060 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd8c) = 0x157520 <F_YoYo_FacebookLogout> */
/* @0x15b064 add r0, pc, r0 —— r0 = 0x3476b8 = "facebook_logout" */
/* @0x15b068 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_logout", 0x157520 <F_YoYo_FacebookLogout>, 0, 0) */
/* ── #138 · 0x15b06c..0x15b084 · facebook_user_id → F_YoYo_FacebookUserId (0x1574e8) · argc=0 · flag=0 ── */
/* @0x15b06c ldr r1, [pc, #0x43c] —— 池字 0xffffe138：GOT 偏移 -0x1ec8 → 槽 0x3efd90 = 0x1574e8 <F_YoYo_FacebookUserId> */
/* @0x15b070 ldr r0, [pc, #0x43c] —— 池字 0x1ec640：串偏移 → 0x3476c8 "facebook_user_id" */
/* @0x15b074 mov r2, r4 —— argc = 0 */
/* @0x15b078 mov r3, r4 —— flag = 0 */
/* @0x15b07c ldr r1, [r10, r1] —— r1 = *(槽 0x3efd90) = 0x1574e8 <F_YoYo_FacebookUserId> */
/* @0x15b080 add r0, pc, r0 —— r0 = 0x3476c8 = "facebook_user_id" */
/* @0x15b084 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_user_id", 0x1574e8 <F_YoYo_FacebookUserId>, 0, 0) */
/* ── #139 · 0x15b088..0x15b0a0 · facebook_accesstoken → F_YoYo_FacebookAccessToken (0x157504) · argc=0 · flag=0 ── */
/* @0x15b088 ldr r1, [pc, #0x428] —— 池字 0xffffe13c：GOT 偏移 -0x1ec4 → 槽 0x3efd94 = 0x157504 <F_YoYo_FacebookAccessToken> */
/* @0x15b08c ldr r0, [pc, #0x428] —— 池字 0x1ec638：串偏移 → 0x3476dc "facebook_accesstoken" */
/* @0x15b090 mov r2, r4 —— argc = 0 */
/* @0x15b094 mov r3, r4 —— flag = 0 */
/* @0x15b098 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd94) = 0x157504 <F_YoYo_FacebookAccessToken> */
/* @0x15b09c add r0, pc, r0 —— r0 = 0x3476dc = "facebook_accesstoken" */
/* @0x15b0a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_accesstoken", 0x157504 <F_YoYo_FacebookAccessToken>, 0, 0) */
/* ── #140 · 0x15b0a4..0x15b0bc · facebook_launch_offerwall → F_YoYo_FacebookNull (0x1561ac) · argc=1 · flag=0 ── */
/* @0x15b0a4 ldr r1, [pc, #0x414] —— 池字 0xffffe140：GOT 偏移 -0x1ec0 → 槽 0x3efd98 = 0x1561ac <F_YoYo_FacebookNull> */
/* @0x15b0a8 ldr r0, [pc, #0x414] —— 池字 0x1ec634：串偏移 → 0x3476f4 "facebook_launch_offerwall" */
/* @0x15b0ac mov r3, r4 —— flag = 0 */
/* @0x15b0b0 mov r2, #1 —— argc = 1 */
/* @0x15b0b4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd98) = 0x1561ac <F_YoYo_FacebookNull> */
/* @0x15b0b8 add r0, pc, r0 —— r0 = 0x3476f4 = "facebook_launch_offerwall" */
/* @0x15b0bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_launch_offerwall", 0x1561ac <F_YoYo_FacebookNull>, 1, 0) */
/* ── #141 · 0x15b0c0..0x15b0d8 + bl@0x15b814 · facebook_post_message → F_YoYo_FacebookPostMessage (0x157390) · argc=7 · flag=0 ── */
/* @0x15b0c0 ldr r1, [pc, #0x400] —— 池字 0xffffe144：GOT 偏移 -0x1ebc → 槽 0x3efd9c = 0x157390 <F_YoYo_FacebookPostMessage> */
/* @0x15b0c4 ldr r0, [pc, #0x400] —— 池字 0x1ec634：串偏移 → 0x347710 "facebook_post_message" */
/* @0x15b0c8 mov r3, r4 —— flag = 0 */
/* @0x15b0cc mov r2, #7 —— argc = 7 */
/* @0x15b0d0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efd9c) = 0x157390 <F_YoYo_FacebookPostMessage> */
/* @0x15b0d4 add r0, pc, r0 —— r0 = 0x347710 = "facebook_post_message" */
/* @0x15b0d8 b 0x15b814 <_Z17InitYoYoFunctionsv+0x1744> */

/* ══ §池1 0x15b0dc..0x15b810（462 字）══ */
/*   起点就是 GOT 基址增量 0x297b68（r6 = 0x15a0f0 + 它 = 0x3f1c58）。整段被 462 处 ldr [pc,#…] 引用：
 *     · 块 1（0x15a154..0x15b0d4）前向引用 253 处；
 *     · 块 2（0x15b818..）**反向**引用 209 处（ldr rX,[pc,#-0x…]，池紧贴 0x15b814 之前）。
 *   池里只有两种字：串偏移（正，落到 0x346xxx 的 .rodata 名字串）与 GOT 偏移（负，落到 0x3efxxx 的槽）。
 */

/* ══ §池1 明细（462 字，全部是字面量：objdump 按 ARM 译成 andseq/eoreq/mulseq/… 等，**非指令**）══ */
/* @0x15b0dc eoreq r7, r9, r8, ror #22 —— 池字 0x297b68（1 处引用） */
/* @0x15b0e0 andseq r12, lr, r4, lsr r10 —— 池字 0x1eca34 = 串偏移 → 0x346b2c "comsachievementcache"（1 处引用） */
/* @0x15b0e4 .word 0xffffdf84 —— 池字 0xffffdf84 = GOT 偏移 → 槽 0x3efbdc = 0x484a94 <g_pComsMutex>（1 处引用） */
/* @0x15b0e8 .word 0xffffdf74 —— 池字 0xffffdf74 = GOT 偏移 → 槽 0x3efbcc = 0x484aa4 <g_pAchievementCache_First>（1 处引用） */
/* @0x15b0ec andseq r12, lr, r8, lsl r10 —— 池字 0x1eca18 = 串偏移 → 0x346b44 "comsgmlcallbacks"（1 处引用） */
/* @0x15b0f0 eorseq r10, r2, r8, lsr #18 —— 池字 0x32a928（1 处引用） */
/* @0x15b0f4 .word 0xffffdfa4 —— 池字 0xffffdfa4 = GOT 偏移 → 槽 0x3efbfc = 0x1563bc <F_IO_AddVirtualKey>（1 处引用） */
/* @0x15b0f8 andseq r12, lr, r8, ror #19 —— 池字 0x1ec9e8 = 串偏移 → 0x346b58 "YoYo_AddVirtualKey"（1 处引用） */
/* @0x15b0fc .word 0xffffdfa8 —— 池字 0xffffdfa8 = GOT 偏移 → 槽 0x3efc00 = 0x156564 <F_IO_DeleteVirtualKey>（1 处引用） */
/* @0x15b100 ldrsbeq r12, [lr], -r12 —— 池字 0x1ec9dc = 串偏移 → 0x346b6c "YoYo_DeleteVirtualKey"（1 处引用） */
/* @0x15b104 .word 0xffffdfac —— 池字 0xffffdfac = GOT 偏移 → 槽 0x3efc04 = 0x15648c <F_IO_ShowVirtualKey>（1 处引用） */
/* @0x15b108 ldrsbeq r12, [lr], -r4 —— 池字 0x1ec9d4 = 串偏移 → 0x346b84 "YoYo_ShowVirtualKey"（1 处引用） */
/* @0x15b10c .word 0xffffdfb0 —— 池字 0xffffdfb0 = GOT 偏移 → 槽 0x3efc08 = 0x1564f8 <F_IO_HideVirtualKey>（1 处引用） */
/* @0x15b110 andseq r12, lr, r8, asr #19 —— 池字 0x1ec9c8 = 串偏移 → 0x346b98 "YoYo_HideVirtualKey"（1 处引用） */
/* @0x15b114 andseq r12, lr, r4, asr #19 —— 池字 0x1ec9c4 = 串偏移 → 0x346bac "virtual_key_add"（1 处引用） */
/* @0x15b118 ldrheq r12, [lr], -r12 —— 池字 0x1ec9bc = 串偏移 → 0x346bbc "virtual_key_delete"（1 处引用） */
/* @0x15b11c ldrheq r12, [lr], -r8 —— 池字 0x1ec9b8 = 串偏移 → 0x346bd0 "virtual_key_show"（1 处引用） */
/* @0x15b120 ldrheq r12, [lr], -r4 —— 池字 0x1ec9b4 = 串偏移 → 0x346be4 "virtual_key_hide"（1 处引用） */
/* @0x15b124 .word 0xffffdfb4 —— 池字 0xffffdfb4 = GOT 偏移 → 槽 0x3efc0c = 0x1565b4 <F_YoYo_LoginAchievements>（1 处引用） */
/* @0x15b128 andseq r12, lr, r8, lsr #19 —— 池字 0x1ec9a8 = 串偏移 → 0x346bf8 "YoYo_LoginAchievements"（1 处引用） */
/* @0x15b12c .word 0xffffdfb8 —— 池字 0xffffdfb8 = GOT 偏移 → 槽 0x3efc10 = 0x1565b8 <F_YoYo_LogoutAchievements>（1 处引用） */
/* @0x15b130 andseq r12, lr, r0, lsr #19 —— 池字 0x1ec9a0 = 串偏移 → 0x346c10 "YoYo_LogoutAchievements"（1 处引用） */
/* @0x15b134 .word 0xffffdfbc —— 池字 0xffffdfbc = GOT 偏移 → 槽 0x3efc14 = 0x1590f4 <F_YoYo_PostAchievement>（1 处引用） */
/* @0x15b138 mulseq lr, r8, r9 —— 池字 0x1ec998 = 串偏移 → 0x346c28 "YoYo_PostAchievement"（1 处引用） */
/* @0x15b13c .word 0xffffdfc0 —— 池字 0xffffdfc0 = GOT 偏移 → 槽 0x3efc18 = 0x159254 <F_YoYo_PostScore>（1 处引用） */
/* @0x15b140 mulseq lr, r0, r9 —— 池字 0x1ec990 = 串偏移 → 0x346c40 "YoYo_PostScore"（1 处引用） */
/* @0x15b144 .word 0xffffdfc4 —— 池字 0xffffdfc4 = GOT 偏移 → 槽 0x3efc1c = 0x156030 <F_YoYo_AchievementsAvailable>（1 处引用） */
/* @0x15b148 andseq r12, lr, r0, lsl #19 —— 池字 0x1ec980 = 串偏移 → 0x346c50 "YoYo_AchievementsAvailable"（1 处引用） */
/* @0x15b14c andseq r12, lr, r0, lsl #19 —— 池字 0x1ec980 = 串偏移 → 0x346c6c "achievement_available"（1 处引用） */
/* @0x15b150 andseq r12, lr, r4, lsl #19 —— 池字 0x1ec984 = 串偏移 → 0x346c84 "achievement_post_score"（1 处引用） */
/* @0x15b154 andseq r12, lr, r4, lsl #19 —— 池字 0x1ec984 = 串偏移 → 0x346c9c "achievement_post"（1 处引用） */
/* @0x15b158 .word 0xffffdfc8 —— 池字 0xffffdfc8 = GOT 偏移 → 槽 0x3efc20 = 0x1591a4 <F_YoYo_IncrementAchievement>（1 处引用） */
/* @0x15b15c andseq r12, lr, r8, ror r9 —— 池字 0x1ec978 = 串偏移 → 0x346cb0 "achievement_increment"（1 处引用） */
/* @0x15b160 .word 0xffffdfcc —— 池字 0xffffdfcc = GOT 偏移 → 槽 0x3efc24 = 0x156b50 <F_YoYo_AchievementEvent>（1 处引用） */
/* @0x15b164 andseq r12, lr, r4, ror r9 —— 池字 0x1ec974 = 串偏移 → 0x346cc8 "achievement_event"（1 处引用） */
/* @0x15b168 andseq r12, lr, r0, ror r9 —— 池字 0x1ec970 = 串偏移 → 0x346cdc "achievement_login"（1 处引用） */
/* @0x15b16c andseq r12, lr, r12, ror #18 —— 池字 0x1ec96c = 串偏移 → 0x346cf0 "achievement_logout"（1 处引用） */
/* @0x15b170 .word 0xffffdfd0 —— 池字 0xffffdfd0 = GOT 偏移 → 槽 0x3efc28 = 0x1567a0 <F_YoYo_AchievementReset>（1 处引用） */
/* @0x15b174 andseq r12, lr, r4, ror #18 —— 池字 0x1ec964 = 串偏移 → 0x346d04 "achievement_reset"（1 处引用） */
/* @0x15b178 .word 0xffffdfd4 —— 池字 0xffffdfd4 = GOT 偏移 → 槽 0x3efc2c = 0x1565bc <F_YoYo_AchievementsShowAchievements>（1 处引用） */
/* @0x15b17c andseq r12, lr, r12, asr r9 —— 池字 0x1ec95c = 串偏移 → 0x346d18 "achievement_show_achievements"（1 处引用） */
/* @0x15b180 .word 0xffffdfd8 —— 池字 0xffffdfd8 = GOT 偏移 → 槽 0x3efc30 = 0x1565c0 <F_YoYo_AchievementsShow>（1 处引用） */
/* @0x15b184 andseq r12, lr, r0, ror #18 —— 池字 0x1ec960 = 串偏移 → 0x346d38 "achievement_show"（1 处引用） */
/* @0x15b188 .word 0xffffdfdc —— 池字 0xffffdfdc = GOT 偏移 → 槽 0x3efc34 = 0x156608 <F_YoYo_AchievementsShowLeaderboards>（1 处引用） */
/* @0x15b18c andseq r12, lr, r8, asr r9 —— 池字 0x1ec958 = 串偏移 → 0x346d4c "achievement_show_leaderboards"（1 处引用） */
/* @0x15b190 .word 0xffffdfe0 —— 池字 0xffffdfe0 = GOT 偏移 → 槽 0x3efc38 = 0x15660c <F_YoYo_AchievementsLoadFriends>（1 处引用） */
/* @0x15b194 andseq r12, lr, r12, asr r9 —— 池字 0x1ec95c = 串偏移 → 0x346d6c "achievement_load_friends"（1 处引用） */
/* @0x15b198 .word 0xffffdfe4 —— 池字 0xffffdfe4 = GOT 偏移 → 槽 0x3efc3c = 0x156654 <F_YoYo_AchievementLoadLeaderboard>（1 处引用） */
/* @0x15b19c andseq r12, lr, r12, asr r9 —— 池字 0x1ec95c = 串偏移 → 0x346d88 "achievement_load_leaderboard"（1 处引用） */
/* @0x15b1a0 .word 0xffffdfe8 —— 池字 0xffffdfe8 = GOT 偏移 → 槽 0x3efc40 = 0x156610 <F_YoYo_Achievement_GetPic>（1 处引用） */
/* @0x15b1a4 andseq r12, lr, r0, ror #18 —— 池字 0x1ec960 = 串偏移 → 0x346da8 "achievement_get_pic"（1 处引用） */
/* @0x15b1a8 .word 0xffffdfec —— 池字 0xffffdfec = GOT 偏移 → 槽 0x3efc44 = 0x156628 <F_YoYo_Achievement_GetInfo>（1 处引用） */
/* @0x15b1ac andseq r12, lr, r8, asr r9 —— 池字 0x1ec958 = 串偏移 → 0x346dbc "achievement_get_info"（1 处引用） */
/* @0x15b1b0 .word 0xffffdff0 —— 池字 0xffffdff0 = GOT 偏移 → 槽 0x3efc48 = 0x1566c0 <F_YoYo_AchievementLoadProgress>（1 处引用） */
/* @0x15b1b4 andseq r12, lr, r4, asr r9 —— 池字 0x1ec954 = 串偏移 → 0x346dd4 "achievement_load_progress"（1 处引用） */
/* @0x15b1b8 .word 0xffffdff4 —— 池字 0xffffdff4 = GOT 偏移 → 槽 0x3efc4c = 0x1566d4 <F_YoYo_AchievementSendChallenge>（1 处引用） */
/* @0x15b1bc andseq r12, lr, r4, asr r9 —— 池字 0x1ec954 = 串偏移 → 0x346df0 "achievement_send_challenge"（1 处引用） */
/* @0x15b1c0 .word 0xffffdff8 —— 池字 0xffffdff8 = GOT 偏移 → 槽 0x3efc50 = 0x156754 <F_YoYo_AchievementGetChallenges>（1 处引用） */
/* @0x15b1c4 andseq r12, lr, r4, asr r9 —— 池字 0x1ec954 = 串偏移 → 0x346e0c "achievement_get_challenges"（1 处引用） */
/* @0x15b1c8 .word 0xffffdffc —— 池字 0xffffdffc = GOT 偏移 → 槽 0x3efc54 = 0x156758 <F_YoYo_AchievementShowChallengeNotifications>（1 处引用） */
/* @0x15b1cc andseq r12, lr, r4, asr r9 —— 池字 0x1ec954 = 串偏移 → 0x346e28 "achievement_show_challenge_notifications"（1 处引用） */
/* @0x15b1d0 .word 0xffffe000 —— 池字 0xffffe000 = GOT 偏移 → 槽 0x3efc58 = 0x1568e8 <F_YoYo_CloudFileSave>（1 处引用） */
/* @0x15b1d4 andseq r12, lr, r4, ror #18 —— 池字 0x1ec964 = 串偏移 → 0x346e54 "cloud_file_save"（1 处引用） */
/* @0x15b1d8 .word 0xffffe004 —— 池字 0xffffe004 = GOT 偏移 → 槽 0x3efc5c = 0x159038 <F_YoYo_CloudStringSave>（1 处引用） */
/* @0x15b1dc andseq r12, lr, r8, asr r9 —— 池字 0x1ec958 = 串偏移 → 0x346e64 "cloud_string_save"（1 处引用） */
/* @0x15b1e0 .word 0xffffe008 —— 池字 0xffffe008 = GOT 偏移 → 槽 0x3efc60 = 0x156b04 <F_YoYo_CloudSynchronise>（1 处引用） */
/* @0x15b1e4 andseq r12, lr, r0, asr r9 —— 池字 0x1ec950 = 串偏移 → 0x346e78 "cloud_synchronise"（1 处引用） */
/* @0x15b1e8 .word 0xffffe00c —— 池字 0xffffe00c = GOT 偏移 → 槽 0x3efc64 = 0x156be8 <F_YoYo_OpenURL>（1 处引用） */
/* @0x15b1ec andseq r12, lr, r8, asr #18 —— 池字 0x1ec948 = 串偏移 → 0x346e8c "YoYo_OpenURL"（1 处引用） */
/* @0x15b1f0 .word 0xffffe010 —— 池字 0xffffe010 = GOT 偏移 → 槽 0x3efc68 = 0x156dcc <F_YoYo_OpenURL_ext>（1 处引用） */
/* @0x15b1f4 andseq r12, lr, r8, lsr r9 —— 池字 0x1ec938 = 串偏移 → 0x346e9c "YoYo_OpenURL_ext"（1 处引用） */
/* @0x15b1f8 .word 0xffffe014 —— 池字 0xffffe014 = GOT 偏移 → 槽 0x3efc6c = 0x156dc0 <F_YoYo_OpenURL_full>（1 处引用） */
/* @0x15b1fc andseq r12, lr, r12, lsr #18 —— 池字 0x1ec92c = 串偏移 → 0x346eb0 "YoYo_OpenURL_full"（1 处引用） */
/* @0x15b200 andseq r12, lr, r8, lsr #18 —— 池字 0x1ec928 = 串偏移 → 0x346ec4 "url_open"（1 处引用） */
/* @0x15b204 andseq r12, lr, r12, lsl r9 —— 池字 0x1ec91c = 串偏移 → 0x346ed0 "url_open_ext"（1 处引用） */
/* @0x15b208 andseq r12, lr, r4, lsl r9 —— 池字 0x1ec914 = 串偏移 → 0x346ee0 "url_open_full"（1 处引用） */
/* @0x15b20c .word 0xffffe018 —— 池字 0xffffe018 = GOT 偏移 → 槽 0x3efc70 = 0x156ba8 <F_YoYo_GetDomain>（1 处引用） */
/* @0x15b210 andseq r12, lr, r4, lsl #18 —— 池字 0x1ec904 = 串偏移 → 0x346ef0 "url_get_domain"（1 处引用） */
/* @0x15b214 .word 0xffffe01c —— 池字 0xffffe01c = GOT 偏移 → 槽 0x3efc74 = 0x156dd8 <F_YoYo_EnableAds>（1 处引用） */
/* @0x15b218 ldrsheq r12, [lr], -r8 —— 池字 0x1ec8f8 = 串偏移 → 0x346f00 "YoYo_EnableAds"（1 处引用） */
/* @0x15b21c .word 0xffffe020 —— 池字 0xffffe020 = GOT 偏移 → 槽 0x3efc78 = 0x15936c <F_YoYo_DisableAds>（1 处引用） */
/* @0x15b220 andseq r12, lr, r12, ror #17 —— 池字 0x1ec8ec = 串偏移 → 0x346f10 "YoYo_DisableAds"（1 处引用） */
/* @0x15b224 .word 0xffffe024 —— 池字 0xffffe024 = GOT 偏移 → 槽 0x3efc7c = 0x156ea0 <F_YoYo_LeaveRating>（1 处引用） */
/* @0x15b228 ldrsbeq r12, [lr], -r12 —— 池字 0x1ec8dc = 串偏移 → 0x346f20 "YoYo_LeaveRating"（1 处引用） */
/* @0x15b22c .word 0xffffe028 —— 池字 0xffffe028 = GOT 偏移 → 槽 0x3efc80 = 0x156e10 <F_YoYo_EnableAdsEx>（1 处引用） */
/* @0x15b230 ldrsbeq r12, [lr], -r0 —— 池字 0x1ec8d0 = 串偏移 → 0x346f34 "ads_enable"（1 处引用） */
/* @0x15b234 andseq r12, lr, r8, asr #17 —— 池字 0x1ec8c8 = 串偏移 → 0x346f40 "ads_disable"（1 处引用） */
/* @0x15b238 .word 0xffffe02c —— 池字 0xffffe02c = GOT 偏移 → 槽 0x3efc84 = 0x156e88 <F_YoYo_AdsEvent>（1 处引用） */
/* @0x15b23c ldrheq r12, [lr], -r4 —— 池字 0x1ec8b4 = 串偏移 → 0x346f4c "ads_event"（1 处引用） */
/* @0x15b240 .word 0xffffe030 —— 池字 0xffffe030 = GOT 偏移 → 槽 0x3efc88 = 0x156e70 <F_YoYo_AdsPreload>（1 处引用） */
/* @0x15b244 andseq r12, lr, r4, lsr #17 —— 池字 0x1ec8a4 = 串偏移 → 0x346f58 "ads_event_preload"（1 处引用） */
/* @0x15b248 .word 0xffffe034 —— 池字 0xffffe034 = GOT 偏移 → 槽 0x3efc8c = 0x1593a4 <F_YoYo_GetAdsWidth>（1 处引用） */
/* @0x15b24c mulseq lr, r12, r8 —— 池字 0x1ec89c = 串偏移 → 0x346f6c "ads_get_display_width"（1 处引用） */
/* @0x15b250 .word 0xffffe038 —— 池字 0xffffe038 = GOT 偏移 → 槽 0x3efc90 = 0x159404 <F_YoYo_GetAdsHeight>（1 处引用） */
/* @0x15b254 mulseq lr, r8, r8 —— 池字 0x1ec898 = 串偏移 → 0x346f84 "ads_get_display_height"（1 处引用） */
/* @0x15b258 .word 0xffffe03c —— 池字 0xffffe03c = GOT 偏移 → 槽 0x3efc94 = 0x159304 <F_YoYo_MoveAdsEx>（1 处引用） */
/* @0x15b25c mulseq lr, r4, r8 —— 池字 0x1ec894 = 串偏移 → 0x346f9c "ads_move"（1 处引用） */
/* @0x15b260 .word 0xffffe040 —— 池字 0xffffe040 = GOT 偏移 → 槽 0x3efc98 = 0x1560b0 <F_YoYo_Ads_Interstitial_Available>（1 处引用） */
/* @0x15b264 andseq r12, lr, r4, lsl #17 —— 池字 0x1ec884 = 串偏移 → 0x346fa8 "ads_interstitial_available"（1 处引用） */
/* @0x15b268 .word 0xffffe044 —— 池字 0xffffe044 = GOT 偏移 → 槽 0x3efc9c = 0x1560c4 <F_YoYo_Ads_Interstitial_Display>（1 处引用） */
/* @0x15b26c andseq r12, lr, r4, lsl #17 —— 池字 0x1ec884 = 串偏移 → 0x346fc4 "ads_interstitial_display"（1 处引用） */
/* @0x15b270 .word 0xffffe048 —— 池字 0xffffe048 = GOT 偏移 → 槽 0x3efca0 = 0x156080 <F_YoYo_AdsEngagementAvailable>（1 处引用） */
/* @0x15b274 andseq r12, lr, r4, lsl #17 —— 池字 0x1ec884 = 串偏移 → 0x346fe0 "ads_engagement_available"（1 处引用） */
/* @0x15b278 .word 0xffffe04c —— 池字 0xffffe04c = GOT 偏移 → 槽 0x3efca4 = 0x1560a8 <F_YoYoAdsEngagementLaunch>（1 处引用） */
/* @0x15b27c andseq r12, lr, r4, lsl #17 —— 池字 0x1ec884 = 串偏移 → 0x346ffc "ads_engagement_launch"（1 处引用） */
/* @0x15b280 .word 0xffffe050 —— 池字 0xffffe050 = GOT 偏移 → 槽 0x3efca8 = 0x156094 <F_YoYoAdsEngagementActive>（1 处引用） */
/* @0x15b284 andseq r12, lr, r0, lsl #17 —— 池字 0x1ec880 = 串偏移 → 0x347014 "ads_engagement_active"（1 处引用） */
/* @0x15b288 .word 0xffffe054 —— 池字 0xffffe054 = GOT 偏移 → 槽 0x3efcac = 0x156e58 <F_YoYoAdsSetup>（1 处引用） */
/* @0x15b28c andseq r12, lr, r12, ror r8 —— 池字 0x1ec87c = 串偏移 → 0x34702c "ads_setup"（1 处引用） */
/* @0x15b290 .word 0xffffe058 —— 池字 0xffffe058 = GOT 偏移 → 槽 0x3efcb0 = 0x1560ac <F_YoYoAdsRewardCallback>（1 处引用） */
/* @0x15b294 andseq r12, lr, r12, ror #16 —— 池字 0x1ec86c = 串偏移 → 0x347038 "ads_set_reward_callback"（1 处引用） */
/* @0x15b298 .word 0xffffe05c —— 池字 0xffffe05c = GOT 偏移 → 槽 0x3efcb4 = 0x156064 <F_BE_AddButton>（1 处引用） */
/* @0x15b29c andseq r12, lr, r8, ror #16 —— 池字 0x1ec868 = 串偏移 → 0x347050 "clickable_add"（1 处引用） */
/* @0x15b2a0 .word 0xffffe060 —— 池字 0xffffe060 = GOT 偏移 → 槽 0x3efcb8 = 0x156068 <F_BE_AddButtonExt>（1 处引用） */
/* @0x15b2a4 andseq r12, lr, r12, asr r8 —— 池字 0x1ec85c = 串偏移 → 0x347060 "clickable_add_ext"（1 处引用） */
/* @0x15b2a8 .word 0xffffe064 —— 池字 0xffffe064 = GOT 偏移 → 槽 0x3efcbc = 0x15606c <F_BE_ChangeImage>（1 处引用） */
/* @0x15b2ac andseq r12, lr, r4, asr r8 —— 池字 0x1ec854 = 串偏移 → 0x347074 "clickable_change"（1 处引用） */
/* @0x15b2b0 .word 0xffffe068 —— 池字 0xffffe068 = GOT 偏移 → 槽 0x3efcc0 = 0x156070 <F_BE_Change>（1 处引用） */
/* @0x15b2b4 andseq r12, lr, r12, asr #16 —— 池字 0x1ec84c = 串偏移 → 0x347088 "clickable_change_ext"（1 处引用） */
/* @0x15b2b8 .word 0xffffe06c —— 池字 0xffffe06c = GOT 偏移 → 槽 0x3efcc4 = 0x156074 <F_BE_DeleteButton>（1 处引用） */
/* @0x15b2bc andseq r12, lr, r8, asr #16 —— 池字 0x1ec848 = 串偏移 → 0x3470a0 "clickable_delete"（1 处引用） */
/* @0x15b2c0 .word 0xffffe070 —— 池字 0xffffe070 = GOT 偏移 → 槽 0x3efcc8 = 0x156078 <F_BE_ExistsButton>（1 处引用） */
/* @0x15b2c4 andseq r12, lr, r0, asr #16 —— 池字 0x1ec840 = 串偏移 → 0x3470b4 "clickable_exists"（1 处引用） */
/* @0x15b2c8 .word 0xffffe074 —— 池字 0xffffe074 = GOT 偏移 → 槽 0x3efccc = 0x15607c <F_BE_SetStyle>（1 处引用） */
/* @0x15b2cc andseq r12, lr, r8, lsr r8 —— 池字 0x1ec838 = 串偏移 → 0x3470c8 "clickable_set_style"（1 处引用） */
/* @0x15b2d0 andseq r12, lr, r8, lsr r8 —— 池字 0x1ec838 = 串偏移 → 0x3470dc "shop_leave_rating"（1 处引用） */
/* @0x15b2d4 .word 0xffffe078 —— 池字 0xffffe078 = GOT 偏移 → 槽 0x3efcd0 = 0x156f90 <F_YoYo_GetTimer>（1 处引用） */
/* @0x15b2d8 andseq r12, lr, r12, lsr #16 —— 池字 0x1ec82c = 串偏移 → 0x3470f0 "YoYo_GetTimer"（1 处引用） */
/* @0x15b2dc .word 0xffffe07c —— 池字 0xffffe07c = GOT 偏移 → 槽 0x3efcd4 = 0x159d04 <F_YoYo_GetPlatform>（1 处引用） */
/* @0x15b2e0 andseq r12, lr, r12, lsl r8 —— 池字 0x1ec81c = 串偏移 → 0x347100 "YoYo_GetPlatform"（1 处引用） */
/* @0x15b2e4 .word 0xffffe080 —— 池字 0xffffe080 = GOT 偏移 → 槽 0x3efcd8 = 0x156efc <F_YoYo_GetDevice>（1 处引用） */
/* @0x15b2e8 andseq r12, lr, r4, lsl r8 —— 池字 0x1ec814 = 串偏移 → 0x347114 "YoYo_GetDevice"（1 处引用） */
/* @0x15b2ec .word 0xffffe084 —— 池字 0xffffe084 = GOT 偏移 → 槽 0x3efcdc = 0x156f60 <F_YoYo_GetCPUDetails>（1 处引用） */
/* @0x15b2f0 andseq r12, lr, r8, lsl #16 —— 池字 0x1ec808 = 串偏移 → 0x347124 "YoYo_GetCPUDetails"（1 处引用） */
/* @0x15b2f4 .word 0xffffe088 —— 池字 0xffffe088 = GOT 偏移 → 槽 0x3efce0 = 0x156bb8 <F_YoYo_GetConfig>（1 处引用） */
/* @0x15b2f8 andseq r12, lr, r0, lsl #16 —— 池字 0x1ec800 = 串偏移 → 0x347138 "YoYo_GetConfig"（1 处引用） */
/* @0x15b2fc .word 0xffffe08c —— 池字 0xffffe08c = GOT 偏移 → 槽 0x3efce4 = 0x156184 <F_YoYo_GetSessionKey>（1 处引用） */
/* @0x15b300 ldrsheq r12, [lr], -r0 —— 池字 0x1ec7f0 = 串偏移 → 0x347148 "YoYo_GetSessionKey"（1 处引用） */
/* @0x15b304 .word 0xffffe090 —— 池字 0xffffe090 = GOT 偏移 → 槽 0x3efce8 = 0x156198 <F_YoYo_CheckSecurity>（1 处引用） */
/* @0x15b308 andseq r12, lr, r8, ror #15 —— 池字 0x1ec7e8 = 串偏移 → 0x34715c "YoYo_CheckSecurity"（1 处引用） */
/* @0x15b30c andseq r12, lr, r4, ror #15 —— 池字 0x1ec7e4 = 串偏移 → 0x347170 "get_timer"（1 处引用） */
/* @0x15b310 ldrsbeq r12, [lr], -r8 —— 池字 0x1ec7d8 = 串偏移 → 0x34717c "os_get_config"（1 处引用） */
/* @0x15b314 .word 0xffffe094 —— 池字 0xffffe094 = GOT 偏移 → 槽 0x3efcec = 0x156fb0 <F_YoYo_OsGetInfo>（1 处引用） */
/* @0x15b318 andseq r12, lr, r12, asr #15 —— 池字 0x1ec7cc = 串偏移 → 0x34718c "os_get_info"（1 处引用） */
/* @0x15b31c .word 0xffffe098 —— 池字 0xffffe098 = GOT 偏移 → 槽 0x3efcf0 = 0x157610 <F_YoYo_GetLanguage>（1 处引用） */
/* @0x15b320 ldrheq r12, [lr], -r12 —— 池字 0x1ec7bc = 串偏移 → 0x347198 "os_get_language"（1 处引用） */
/* @0x15b324 .word 0xffffe09c —— 池字 0xffffe09c = GOT 偏移 → 槽 0x3efcf4 = 0x15762c <F_YoYo_GetRegion>（1 处引用） */
/* @0x15b328 ldrheq r12, [lr], -r0 —— 池字 0x1ec7b0 = 串偏移 → 0x3471a8 "os_get_region"（1 处引用） */
/* @0x15b32c .word 0xffffe0a0 —— 池字 0xffffe0a0 = GOT 偏移 → 槽 0x3efcf8 = 0x157648 <F_YoYo_RequestPermission>（1 处引用） */
/* @0x15b330 andseq r12, lr, r4, lsr #15 —— 池字 0x1ec7a4 = 串偏移 → 0x3471b8 "os_request_permission"（1 处引用） */
/* @0x15b334 .word 0xffffe0a4 —— 池字 0xffffe0a4 = GOT 偏移 → 槽 0x3efcfc = 0x157674 <F_YoYo_CheckPermission>（1 处引用） */
/* @0x15b338 andseq r12, lr, r0, lsr #15 —— 池字 0x1ec7a0 = 串偏移 → 0x3471d0 "os_check_permission"（1 处引用） */
/* @0x15b33c .word 0xffffe0a8 —— 池字 0xffffe0a8 = GOT 偏移 → 槽 0x3efd00 = 0x156210 <F_CodeIsCompiled>（1 处引用） */
/* @0x15b340 mulseq lr, r8, r7 —— 池字 0x1ec798 = 串偏移 → 0x3471e4 "code_is_compiled"（1 处引用） */
/* @0x15b344 .word 0xffffe0ac —— 池字 0xffffe0ac = GOT 偏移 → 槽 0x3efd04 = 0x1576b8 <F_YoYo_GetDPIX>（1 处引用） */
/* @0x15b348 mulseq lr, r0, r7 —— 池字 0x1ec790 = 串偏移 → 0x3471f8 "display_get_dpi_x"（1 处引用） */
/* @0x15b34c .word 0xffffe0b0 —— 池字 0xffffe0b0 = GOT 偏移 → 槽 0x3efd08 = 0x1576e8 <F_YoYo_GetDPIY>（1 处引用） */
/* @0x15b350 andseq r12, lr, r8, lsl #15 —— 池字 0x1ec788 = 串偏移 → 0x34720c "display_get_dpi_y"（1 处引用） */
/* @0x15b354 .word 0xffffe0b4 —— 池字 0xffffe0b4 = GOT 偏移 → 槽 0x3efd0c = 0x157718 <F_YoYo_SetGUISize>（1 处引用） */
/* @0x15b358 andseq r12, lr, r0, lsl #15 —— 池字 0x1ec780 = 串偏移 → 0x347220 "display_set_gui_size"（1 处引用） */
/* @0x15b35c .word 0xffffe0b8 —— 池字 0xffffe0b8 = GOT 偏移 → 槽 0x3efd10 = 0x157908 <F_YoYo_GetGUIWidth>（1 处引用） */
/* @0x15b360 andseq r12, lr, r12, ror r7 —— 池字 0x1ec77c = 串偏移 → 0x347238 "display_get_gui_width"（1 处引用） */
/* @0x15b364 .word 0xffffe0bc —— 池字 0xffffe0bc = GOT 偏移 → 槽 0x3efd14 = 0x15797c <F_YoYo_GetGUIHeight>（1 处引用） */
/* @0x15b368 andseq r12, lr, r8, ror r7 —— 池字 0x1ec778 = 串偏移 → 0x347250 "display_get_gui_height"（1 处引用） */
/* @0x15b36c .word 0xffffe0c0 —— 池字 0xffffe0c0 = GOT 偏移 → 槽 0x3efd18 = 0x1577f4 <F_YoYo_SetGUIMaximise>（1 处引用） */
/* @0x15b370 andseq r12, lr, r4, ror r7 —— 池字 0x1ec774 = 串偏移 → 0x347268 "display_set_gui_maximise"（1 处引用） */
/* @0x15b374 .word 0xffffe0c4 —— 池字 0xffffe0c4 = GOT 偏移 → 槽 0x3efd1c = 0x157094 <F_YoYo_OF_StartDashboard>（1 处引用） */
/* @0x15b378 andseq r12, lr, r4, ror r7 —— 池字 0x1ec774 = 串偏移 → 0x347284 "YoYo_OF_StartDashboard"（1 处引用） */
/* @0x15b37c .word 0xffffe0c8 —— 池字 0xffffe0c8 = GOT 偏移 → 槽 0x3efd20 = 0x157098 <F_YoYo_OF_AddAchievement>（1 处引用） */
/* @0x15b380 andseq r12, lr, r12, ror #14 —— 池字 0x1ec76c = 串偏移 → 0x34729c "YoYo_OF_AddAchievement"（1 处引用） */
/* @0x15b384 .word 0xffffe0cc —— 池字 0xffffe0cc = GOT 偏移 → 槽 0x3efd24 = 0x159464 <F_YoYo_OF_AddLeaderboard>（1 处引用） */
/* @0x15b388 andseq r12, lr, r4, ror #14 —— 池字 0x1ec764 = 串偏移 → 0x3472b4 "YoYo_OF_AddLeaderboard"（1 处引用） */
/* @0x15b38c .word 0xffffe0d0 —— 池字 0xffffe0d0 = GOT 偏移 → 槽 0x3efd28 = 0x1570cc <F_YoYo_OF_SendChallenge>（1 处引用） */
/* @0x15b390 andseq r12, lr, r12, asr r7 —— 池字 0x1ec75c = 串偏移 → 0x3472cc "YoYo_OF_SendChallenge"（1 处引用） */
/* @0x15b394 .word 0xffffe0d4 —— 池字 0xffffe0d4 = GOT 偏移 → 槽 0x3efd2c = 0x157114 <F_YoYo_OF_SendInvite>（1 处引用） */
/* @0x15b398 andseq r12, lr, r4, asr r7 —— 池字 0x1ec754 = 串偏移 → 0x3472e4 "YoYo_OF_SendInvite"（1 处引用） */
/* @0x15b39c .word 0xffffe0d8 —— 池字 0xffffe0d8 = GOT 偏移 → 槽 0x3efd30 = 0x15712c <F_YoYo_OF_SendSocial>（1 处引用） */
/* @0x15b3a0 andseq r12, lr, r8, asr #14 —— 池字 0x1ec748 = 串偏移 → 0x3472f8 "YoYo_OF_SendSocial"（1 处引用） */
/* @0x15b3a4 .word 0xffffe0dc —— 池字 0xffffe0dc = GOT 偏移 → 槽 0x3efd34 = 0x157174 <F_YoYo_OF_SetURL>（1 处引用） */
/* @0x15b3a8 andseq r12, lr, r12, lsr r7 —— 池字 0x1ec73c = 串偏移 → 0x34730c "YoYo_OF_SetURL"（1 处引用） */
/* @0x15b3ac .word 0xffffe0e0 —— 池字 0xffffe0e0 = GOT 偏移 → 槽 0x3efd38 = 0x15718c <F_YoYo_OF_AcceptChallenge>（1 处引用） */
/* @0x15b3b0 andseq r12, lr, r12, lsr #14 —— 池字 0x1ec72c = 串偏移 → 0x34731c "YoYo_OF_AcceptChallenge"（1 处引用） */
/* @0x15b3b4 .word 0xffffe0e4 —— 池字 0xffffe0e4 = GOT 偏移 → 槽 0x3efd3c = 0x1571a8 <F_YoYo_Achievement_IsOnline>（1 处引用） */
/* @0x15b3b8 andseq r12, lr, r4, lsr #14 —— 池字 0x1ec724 = 串偏移 → 0x347334 "YoYo_OF_IsOnline"（1 处引用） */
/* @0x15b3bc .word 0xffffe0e8 —— 池字 0xffffe0e8 = GOT 偏移 → 槽 0x3efd40 = 0x1571d8 <F_YoYo_OF_SendChallengeResult>（1 处引用） */
/* @0x15b3c0 andseq r12, lr, r8, lsl r7 —— 池字 0x1ec718 = 串偏移 → 0x347348 "YoYo_OF_SendChallengeResult"（1 处引用） */
/* @0x15b3c4 andseq r12, lr, r8, lsl r7 —— 池字 0x1ec718 = 串偏移 → 0x347364 "openfeint_start"（1 处引用） */
/* @0x15b3c8 andseq r12, lr, r4, lsl r7 —— 池字 0x1ec714 = 串偏移 → 0x347374 "achievement_map_achievement"（1 处引用） */
/* @0x15b3cc andseq r12, lr, r8, lsl r7 —— 池字 0x1ec718 = 串偏移 → 0x347390 "achievement_map_leaderboard"（1 处引用） */
/* @0x15b3d0 andseq r12, lr, r12, lsl r7 —— 池字 0x1ec71c = 串偏移 → 0x3473ac "openfeint_send_challenge"（1 处引用） */
/* @0x15b3d4 andseq r12, lr, r0, lsr #14 —— 池字 0x1ec720 = 串偏移 → 0x3473c8 "openfeint_send_invite"（1 处引用） */
/* @0x15b3d8 andseq r12, lr, r0, lsr #14 —— 池字 0x1ec720 = 串偏移 → 0x3473e0 "openfeint_send_social"（1 处引用） */
/* @0x15b3dc andseq r12, lr, r0, lsr #14 —— 池字 0x1ec720 = 串偏移 → 0x3473f8 "openfeint_set_url"（1 处引用） */
/* @0x15b3e0 andseq r12, lr, r8, lsl r7 —— 池字 0x1ec718 = 串偏移 → 0x34740c "openfeint_accept_challenge"（1 处引用） */
/* @0x15b3e4 andseq r12, lr, r12, lsl r7 —— 池字 0x1ec71c = 串偏移 → 0x347428 "achievement_login_status"（1 处引用） */
/* @0x15b3e8 andseq r12, lr, r4, lsr #14 —— 池字 0x1ec724 = 串偏移 → 0x347444 "openfeint_send_result"（1 处引用） */
/* @0x15b3ec .word 0xffffe0ec —— 池字 0xffffe0ec = GOT 偏移 → 槽 0x3efd44 = 0x15e690 <F_YoYo_MouseCheckButton>（1 处引用） */
/* @0x15b3f0 andseq r12, lr, r12, lsl r7 —— 池字 0x1ec71c = 串偏移 → 0x34745c "YoYo_MouseCheckButton"（1 处引用） */
/* @0x15b3f4 .word 0xffffe0f0 —— 池字 0xffffe0f0 = GOT 偏移 → 槽 0x3efd48 = 0x15e6dc <F_YoYo_MouseCheckButtonPressed>（1 处引用） */
/* @0x15b3f8 andseq r12, lr, r4, lsl r7 —— 池字 0x1ec714 = 串偏移 → 0x347474 "YoYo_MouseCheckButtonPressed"（1 处引用） */
/* @0x15b3fc .word 0xffffe0f4 —— 池字 0xffffe0f4 = GOT 偏移 → 槽 0x3efd4c = 0x15e728 <F_YoYo_MouseCheckButtonReleased>（1 处引用） */
/* @0x15b400 andseq r12, lr, r4, lsl r7 —— 池字 0x1ec714 = 串偏移 → 0x347494 "YoYo_MouseCheckButtonReleased"（1 处引用） */
/* @0x15b404 .word 0xffffe0f8 —— 池字 0xffffe0f8 = GOT 偏移 → 槽 0x3efd50 = 0x15e774 <F_YoYo_MouseX>（1 处引用） */
/* @0x15b408 andseq r12, lr, r4, lsl r7 —— 池字 0x1ec714 = 串偏移 → 0x3474b4 "YoYo_MouseX"（1 处引用） */
/* @0x15b40c .word 0xffffe0fc —— 池字 0xffffe0fc = GOT 偏移 → 槽 0x3efd54 = 0x15e7b0 <F_YoYo_MouseY>（1 处引用） */
/* @0x15b410 andseq r12, lr, r0, lsl #14 —— 池字 0x1ec700 = 串偏移 → 0x3474c0 "YoYo_MouseY"（1 处引用） */
/* @0x15b414 .word 0xffffe100 —— 池字 0xffffe100 = GOT 偏移 → 槽 0x3efd58 = 0x159eb0 <F_YoYo_MouseXRaw>（1 处引用） */
/* @0x15b418 andseq r12, lr, r12, ror #13 —— 池字 0x1ec6ec = 串偏移 → 0x3474cc "YoYo_MouseXRaw"（1 处引用） */
/* @0x15b41c .word 0xffffe104 —— 池字 0xffffe104 = GOT 偏移 → 槽 0x3efd5c = 0x159f10 <F_YoYo_MouseYRaw>（1 处引用） */
/* @0x15b420 ldrsbeq r12, [lr], -r12 —— 池字 0x1ec6dc = 串偏移 → 0x3474dc "YoYo_MouseYRaw"（1 处引用） */
/* @0x15b424 .word 0xffffe108 —— 池字 0xffffe108 = GOT 偏移 → 槽 0x3efd60 = 0x1560d8 <F_YoYo_GetTiltX>（1 处引用） */
/* @0x15b428 andseq r12, lr, r12, asr #13 —— 池字 0x1ec6cc = 串偏移 → 0x3474ec "YoYo_GetTiltX"（1 处引用） */
/* @0x15b42c .word 0xffffe10c —— 池字 0xffffe10c = GOT 偏移 → 槽 0x3efd64 = 0x156100 <F_YoYo_GetTiltY>（1 处引用） */
/* @0x15b430 ldrheq r12, [lr], -r12 —— 池字 0x1ec6bc = 串偏移 → 0x3474fc "YoYo_GetTiltY"（1 处引用） */
/* @0x15b434 .word 0xffffe110 —— 池字 0xffffe110 = GOT 偏移 → 槽 0x3efd68 = 0x156128 <F_YoYo_GetTiltZ>（1 处引用） */
/* @0x15b438 andseq r12, lr, r12, lsr #13 —— 池字 0x1ec6ac = 串偏移 → 0x34750c "YoYo_GetTiltZ"（1 处引用） */
/* @0x15b43c .word 0xffffe114 —— 池字 0xffffe114 = GOT 偏移 → 槽 0x3efd6c = 0x156150 <F_YoYo_IsKeypadOpen>（1 处引用） */
/* @0x15b440 mulseq lr, r12, r6 —— 池字 0x1ec69c = 串偏移 → 0x34751c "YoYo_IsKeypadOpen"（1 处引用） */
/* @0x15b444 mulseq lr, r8, r6 —— 池字 0x1ec698 = 串偏移 → 0x347530 "device_mouse_check_button"（1 处引用） */
/* @0x15b448 mulseq lr, r12, r6 —— 池字 0x1ec69c = 串偏移 → 0x34754c "device_mouse_check_button_pressed"（1 处引用） */
/* @0x15b44c andseq r12, lr, r8, lsr #13 —— 池字 0x1ec6a8 = 串偏移 → 0x347570 "device_mouse_check_button_released"（1 处引用） */
/* @0x15b450 ldrheq r12, [lr], -r4 —— 池字 0x1ec6b4 = 串偏移 → 0x347594 "device_mouse_x"（1 处引用） */
/* @0x15b454 andseq r12, lr, r12, lsr #13 —— 池字 0x1ec6ac = 串偏移 → 0x3475a4 "device_mouse_y"（1 处引用） */
/* @0x15b458 andseq r12, lr, r4, lsr #13 —— 池字 0x1ec6a4 = 串偏移 → 0x3475b4 "device_mouse_raw_x"（1 处引用） */
/* @0x15b45c andseq r12, lr, r0, lsr #13 —— 池字 0x1ec6a0 = 串偏移 → 0x3475c8 "device_mouse_raw_y"（1 处引用） */
/* @0x15b460 .word 0xffffe118 —— 池字 0xffffe118 = GOT 偏移 → 槽 0x3efd70 = 0x158704 <F_MouseXToGUI>（1 处引用） */
/* @0x15b464 mulseq lr, r4, r6 —— 池字 0x1ec694 = 串偏移 → 0x3475dc "device_mouse_x_to_gui"（1 处引用） */
/* @0x15b468 .word 0xffffe11c —— 池字 0xffffe11c = GOT 偏移 → 槽 0x3efd74 = 0x158794 <F_MouseYToGUI>（1 处引用） */
/* @0x15b46c mulseq lr, r0, r6 —— 池字 0x1ec690 = 串偏移 → 0x3475f4 "device_mouse_y_to_gui"（1 处引用） */
/* @0x15b470 mulseq lr, r0, r6 —— 池字 0x1ec690 = 串偏移 → 0x34760c "device_get_tilt_x"（1 处引用） */
/* @0x15b474 andseq r12, lr, r12, lsl #13 —— 池字 0x1ec68c = 串偏移 → 0x347620 "device_get_tilt_y"（1 处引用） */
/* @0x15b478 andseq r12, lr, r8, lsl #13 —— 池字 0x1ec688 = 串偏移 → 0x347634 "device_get_tilt_z"（1 处引用） */
/* @0x15b47c andseq r12, lr, r4, lsl #13 —— 池字 0x1ec684 = 串偏移 → 0x347648 "device_is_keypad_open"（1 处引用） */
/* @0x15b480 .word 0xffffe120 —— 池字 0xffffe120 = GOT 偏移 → 槽 0x3efd78 = 0x15720c <F_YoYo_FacebookInit>（1 处引用） */
/* @0x15b484 andseq r12, lr, r0, lsl #13 —— 池字 0x1ec680 = 串偏移 → 0x347660 "facebook_init"（1 处引用） */
/* @0x15b488 .word 0xffffe124 —— 池字 0xffffe124 = GOT 偏移 → 槽 0x3efd7c = 0x15723c <F_YoYo_FacebookLogin>（1 处引用） */
/* @0x15b48c andseq r12, lr, r4, ror r6 —— 池字 0x1ec674 = 串偏移 → 0x347670 "facebook_login"（1 处引用） */
/* @0x15b490 .word 0xffffe128 —— 池字 0xffffe128 = GOT 偏移 → 槽 0x3efd80 = 0x157290 <F_YoYo_FacebookLoginStatus>（1 处引用） */
/* @0x15b494 andseq r12, lr, r8, ror #12 —— 池字 0x1ec668 = 串偏移 → 0x347680 "facebook_status"（1 处引用） */
/* @0x15b498 .word 0xffffe12c —— 池字 0xffffe12c = GOT 偏移 → 槽 0x3efd84 = 0x1572ac <F_YoYo_FacebookGraphRequest>（1 处引用） */
/* @0x15b49c andseq r12, lr, r12, asr r6 —— 池字 0x1ec65c = 串偏移 → 0x347690 "facebook_graph_request"（1 处引用） */
/* @0x15b4a0 .word 0xffffe130 —— 池字 0xffffe130 = GOT 偏移 → 槽 0x3efd88 = 0x157328 <F_YoYo_FacebookDialog>（1 处引用） */
/* @0x15b4a4 andseq r12, lr, r8, asr r6 —— 池字 0x1ec658 = 串偏移 → 0x3476a8 "facebook_dialog"（1 处引用） */
/* @0x15b4a8 .word 0xffffe134 —— 池字 0xffffe134 = GOT 偏移 → 槽 0x3efd8c = 0x157520 <F_YoYo_FacebookLogout>（1 处引用） */
/* @0x15b4ac andseq r12, lr, r12, asr #12 —— 池字 0x1ec64c = 串偏移 → 0x3476b8 "facebook_logout"（1 处引用） */
/* @0x15b4b0 .word 0xffffe138 —— 池字 0xffffe138 = GOT 偏移 → 槽 0x3efd90 = 0x1574e8 <F_YoYo_FacebookUserId>（1 处引用） */
/* @0x15b4b4 andseq r12, lr, r0, asr #12 —— 池字 0x1ec640 = 串偏移 → 0x3476c8 "facebook_user_id"（1 处引用） */
/* @0x15b4b8 .word 0xffffe13c —— 池字 0xffffe13c = GOT 偏移 → 槽 0x3efd94 = 0x157504 <F_YoYo_FacebookAccessToken>（1 处引用） */
/* @0x15b4bc andseq r12, lr, r8, lsr r6 —— 池字 0x1ec638 = 串偏移 → 0x3476dc "facebook_accesstoken"（1 处引用） */
/* @0x15b4c0 .word 0xffffe140 —— 池字 0xffffe140 = GOT 偏移 → 槽 0x3efd98 = 0x1561ac <F_YoYo_FacebookNull>（1 处引用） */
/* @0x15b4c4 andseq r12, lr, r4, lsr r6 —— 池字 0x1ec634 = 串偏移 → 0x3476f4 "facebook_launch_offerwall"（1 处引用） */
/* @0x15b4c8 .word 0xffffe144 —— 池字 0xffffe144 = GOT 偏移 → 槽 0x3efd9c = 0x157390 <F_YoYo_FacebookPostMessage>（1 处引用） */
/* @0x15b4cc andseq r12, lr, r4, lsr r6 —— 池字 0x1ec634 = 串偏移 → 0x347710 "facebook_post_message"（1 处引用） */
/* @0x15b4d0 .word 0xffffe148 —— 池字 0xffffe148 = GOT 偏移 → 槽 0x3efda0 = 0x157450 <F_YoYo_FacebookSendInvite>（1 处引用） */
/* @0x15b4d4 ldrsheq r11, [lr], -r4 —— 池字 0x1ebef4 = 串偏移 → 0x347728 "facebook_send_invite"（1 处引用） */
/* @0x15b4d8 .word 0xffffe14c —— 池字 0xffffe14c = GOT 偏移 → 槽 0x3efda4 = 0x157550 <F_YoYo_FacebookCheckPermission>（1 处引用） */
/* @0x15b4dc ldrsheq r11, [lr], -r0 —— 池字 0x1ebef0 = 串偏移 → 0x347740 "facebook_check_permission"（1 处引用） */
/* @0x15b4e0 .word 0xffffe150 —— 池字 0xffffe150 = GOT 偏移 → 槽 0x3efda8 = 0x157590 <F_YoYo_FacebookRequestReadPermissions>（1 处引用） */
/* @0x15b4e4 ldrsheq r11, [lr], -r0 —— 池字 0x1ebef0 = 串偏移 → 0x34775c "facebook_request_read_permissions"（1 处引用） */
/* @0x15b4e8 .word 0xffffe154 —— 池字 0xffffe154 = GOT 偏移 → 槽 0x3efdac = 0x1575d0 <F_YoYo_FacebookRequestPublishPermissions>（1 处引用） */
/* @0x15b4ec ldrsheq r11, [lr], -r8 —— 池字 0x1ebef8 = 串偏移 → 0x347780 "facebook_request_publish_permissions"（1 处引用） */
/* @0x15b4f0 .word 0xffffe158 —— 池字 0xffffe158 = GOT 偏移 → 槽 0x3efdb0 = 0x1561c0 <F_YoYo_OSPauseEvent>（1 处引用） */
/* @0x15b4f4 andseq r11, lr, r4, lsl #30 —— 池字 0x1ebf04 = 串偏移 → 0x3477a8 "YoYo_OSPauseEvent"（1 处引用） */
/* @0x15b4f8 ldrsheq r11, [lr], -r12 —— 池字 0x1ebefc = 串偏移 → 0x3477bc "os_is_paused"（1 处引用） */
/* @0x15b4fc .word 0xffffe15c —— 池字 0xffffe15c = GOT 偏移 → 槽 0x3efdb4 = 0x1561f4 <F_YoYo_OSHasFocus>（1 处引用） */
/* @0x15b500 ldrsheq r11, [lr], -r0 —— 池字 0x1ebef0 = 串偏移 → 0x3477cc "window_has_focus"（1 处引用） */
/* @0x15b504 .word 0xffffe160 —— 池字 0xffffe160 = GOT 偏移 → 槽 0x3efdb8 = 0x1579f0 <F_YoYo_Base64Encode>（1 处引用） */
/* @0x15b508 andseq r11, lr, r8, ror #29 —— 池字 0x1ebee8 = 串偏移 → 0x3477e0 "base64_encode"（1 处引用） */
/* @0x15b50c .word 0xffffe164 —— 池字 0xffffe164 = GOT 偏移 → 槽 0x3efdbc = 0x157a94 <F_YoYo_Base64Decode>（1 处引用） */
/* @0x15b510 ldrsbeq r11, [lr], -r12 —— 池字 0x1ebedc = 串偏移 → 0x3477f0 "base64_decode"（1 处引用） */
/* @0x15b514 .word 0xffffe168 —— 池字 0xffffe168 = GOT 偏移 → 槽 0x3efdc0 = 0x157b28 <F_YoYo_MD5Unicode>（1 处引用） */
/* @0x15b518 ldrsbeq r11, [lr], -r0 —— 池字 0x1ebed0 = 串偏移 → 0x347800 "md5_string_unicode"（1 处引用） */
/* @0x15b51c .word 0xffffe16c —— 池字 0xffffe16c = GOT 偏移 → 槽 0x3efdc4 = 0x157c54 <F_YoYo_MD5Utf8>（1 处引用） */
/* @0x15b520 andseq r11, lr, r8, asr #29 —— 池字 0x1ebec8 = 串偏移 → 0x347814 "md5_string_utf8"（1 处引用） */
/* @0x15b524 .word 0xffffe170 —— 池字 0xffffe170 = GOT 偏移 → 槽 0x3efdc8 = 0x157d38 <F_YoYo_MD5File>（1 处引用） */
/* @0x15b528 ldrheq r11, [lr], -r12 —— 池字 0x1ebebc = 串偏移 → 0x347824 "md5_file"（1 处引用） */
/* @0x15b52c .word 0xffffe174 —— 池字 0xffffe174 = GOT 偏移 → 槽 0x3efdcc = 0x157f4c <F_YoYo_SHA1Unicode>（1 处引用） */
/* @0x15b530 andseq r11, lr, r12, lsr #29 —— 池字 0x1ebeac = 串偏移 → 0x347830 "sha1_string_unicode"（1 处引用） */
/* @0x15b534 .word 0xffffe178 —— 池字 0xffffe178 = GOT 偏移 → 槽 0x3efdd0 = 0x158078 <F_YoYo_SHA1Utf8>（1 处引用） */
/* @0x15b538 andseq r11, lr, r4, lsr #29 —— 池字 0x1ebea4 = 串偏移 → 0x347844 "sha1_string_utf8"（1 处引用） */
/* @0x15b53c .word 0xffffe17c —— 池字 0xffffe17c = GOT 偏移 → 槽 0x3efdd4 = 0x15815c <F_YoYo_SHA1File>（1 处引用） */
/* @0x15b540 mulseq lr, r12, lr —— 池字 0x1ebe9c = 串偏移 → 0x347858 "sha1_file"（1 处引用） */
/* @0x15b544 .word 0xffffe180 —— 池字 0xffffe180 = GOT 偏移 → 槽 0x3efdd8 = 0x157f1c <F_YoYo_IsNetworkConnected>（1 处引用） */
/* @0x15b548 andseq r11, lr, r12, lsl #29 —— 池字 0x1ebe8c = 串偏移 → 0x347864 "os_is_network_connected"（1 处引用） */
/* @0x15b54c .word 0xffffe184 —— 池字 0xffffe184 = GOT 偏移 → 槽 0x3efddc = 0x158340 <F_YoYo_PowersaveEnable>（1 处引用） */
/* @0x15b550 andseq r11, lr, r8, lsl #29 —— 池字 0x1ebe88 = 串偏移 → 0x34787c "os_powersave_enable"（1 处引用） */
/* @0x15b554 .word 0xffffe188 —— 池字 0xffffe188 = GOT 偏移 → 槽 0x3efde0 = 0x1594dc <F_YoYo_LockOrientation>（1 处引用） */
/* @0x15b558 andseq r11, lr, r0, lsl #29 —— 池字 0x1ebe80 = 串偏移 → 0x347890 "os_lock_orientation"（1 处引用） */
/* @0x15b55c .word 0xffffe18c —— 池字 0xffffe18c = GOT 偏移 → 槽 0x3efde4 = 0x158358 <F_YoYo_AnalyticsEvent>（1 处引用） */
/* @0x15b560 andseq r11, lr, r8, ror lr —— 池字 0x1ebe78 = 串偏移 → 0x3478a4 "analytics_event"（1 处引用） */
/* @0x15b564 .word 0xffffe190 —— 池字 0xffffe190 = GOT 偏移 → 槽 0x3efde8 = 0x158440 <F_YoYo_AnalyticsEventExt>（1 处引用） */
/* @0x15b568 andseq r11, lr, r12, ror #28 —— 池字 0x1ebe6c = 串偏移 → 0x3478b4 "analytics_event_ext"（1 处引用） */
/* @0x15b56c .word 0xffffe194 —— 池字 0xffffe194 = GOT 偏移 → 槽 0x3efdec = 0x156224 <F_YoYo_WinPhone_License_Trial>（1 处引用） */
/* @0x15b570 andseq r11, lr, r4, ror #28 —— 池字 0x1ebe64 = 串偏移 → 0x3478c8 "winphone_license_trial_version"（1 处引用） */
/* @0x15b574 .word 0xffffe198 —— 池字 0xffffe198 = GOT 偏移 → 槽 0x3efdf0 = 0x158a08 <F_YoYo_WinPhone_SetTile_Common_Title>（1 处引用） */
/* @0x15b578 andseq r11, lr, r8, ror #28 —— 池字 0x1ebe68 = 串偏移 → 0x3478e8 "winphone_tile_title"（1 处引用） */
/* @0x15b57c .word 0xffffe19c —— 池字 0xffffe19c = GOT 偏移 → 槽 0x3efdf4 = 0x156264 <F_YoYo_WinPhone_SetTile_Common_Count>（1 处引用） */
/* @0x15b580 andseq r11, lr, r0, ror #28 —— 池字 0x1ebe60 = 串偏移 → 0x3478fc "winphone_tile_count"（1 处引用） */
/* @0x15b584 .word 0xffffe1a0 —— 池字 0xffffe1a0 = GOT 偏移 → 槽 0x3efdf8 = 0x158a8c <F_YoYo_WinPhone_SetTile_Flip_BackTitle>（1 处引用） */
/* @0x15b588 andseq r11, lr, r8, asr lr —— 池字 0x1ebe58 = 串偏移 → 0x347910 "winphone_tile_back_title"（1 处引用） */
/* @0x15b58c .word 0xffffe1a4 —— 池字 0xffffe1a4 = GOT 偏移 → 槽 0x3efdfc = 0x158b10 <F_YoYo_WinPhone_SetTile_Flip_BackContent>（1 处引用） */
/* @0x15b590 andseq r11, lr, r8, asr lr —— 池字 0x1ebe58 = 串偏移 → 0x34792c "winphone_tile_back_content"（1 处引用） */
/* @0x15b594 .word 0xffffe1a8 —— 池字 0xffffe1a8 = GOT 偏移 → 槽 0x3efe00 = 0x158b94 <F_YoYo_WinPhone_SetTile_Flip_BackContentWide>（1 处引用） */
/* @0x15b598 andseq r11, lr, r8, asr lr —— 池字 0x1ebe58 = 串偏移 → 0x347948 "winphone_tile_back_content_wide"（1 处引用） */
/* @0x15b59c .word 0xffffe1ac —— 池字 0xffffe1ac = GOT 偏移 → 槽 0x3efe04 = 0x158c18 <F_YoYo_WinPhone_SetTile_Flip_FrontImage>（1 处引用） */
/* @0x15b5a0 andseq r11, lr, r12, asr lr —— 池字 0x1ebe5c = 串偏移 → 0x347968 "winphone_tile_front_image"（1 处引用） */
/* @0x15b5a4 .word 0xffffe1b0 —— 池字 0xffffe1b0 = GOT 偏移 → 槽 0x3efe08 = 0x158c9c <F_YoYo_WinPhone_SetTile_Flip_FrontImageSmall>（1 处引用） */
/* @0x15b5a8 andseq r11, lr, r12, asr lr —— 池字 0x1ebe5c = 串偏移 → 0x347984 "winphone_tile_front_image_small"（1 处引用） */
/* @0x15b5ac .word 0xffffe1b4 —— 池字 0xffffe1b4 = GOT 偏移 → 槽 0x3efe0c = 0x158d20 <F_YoYo_WinPhone_SetTile_Flip_FrontImageWide>（1 处引用） */
/* @0x15b5b0 andseq r11, lr, r0, ror #28 —— 池字 0x1ebe60 = 串偏移 → 0x3479a4 "winphone_tile_front_image_wide"（1 处引用） */
/* @0x15b5b4 .word 0xffffe1b8 —— 池字 0xffffe1b8 = GOT 偏移 → 槽 0x3efe10 = 0x158da4 <F_YoYo_WinPhone_SetTile_Flip_BackImage>（1 处引用） */
/* @0x15b5b8 andseq r11, lr, r4, ror #28 —— 池字 0x1ebe64 = 串偏移 → 0x3479c4 "winphone_tile_back_image"（1 处引用） */
/* @0x15b5bc .word 0xffffe1bc —— 池字 0xffffe1bc = GOT 偏移 → 槽 0x3efe14 = 0x158e28 <F_YoYo_WinPhone_SetTile_Flip_BackImageWide>（1 处引用） */
/* @0x15b5c0 andseq r11, lr, r4, ror #28 —— 池字 0x1ebe64 = 串偏移 → 0x3479e0 "winphone_tile_back_image_wide"（1 处引用） */
/* @0x15b5c4 .word 0xffffe1c0 —— 池字 0xffffe1c0 = GOT 偏移 → 槽 0x3efe18 = 0x156294 <F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour>（1 处引用） */
/* @0x15b5c8 andseq r11, lr, r8, ror #28 —— 池字 0x1ebe68 = 串偏移 → 0x347a00 "winphone_tile_background_color"（1 处引用） */
/* @0x15b5cc andseq r11, lr, r0, ror lr —— 池字 0x1ebe70 = 串偏移 → 0x347a20 "winphone_tile_background_colour"（1 处引用） */
/* @0x15b5d0 .word 0xffffe1c4 —— 池字 0xffffe1c4 = GOT 偏移 → 槽 0x3efe1c = 0x158eac <F_YoYo_WinPhone_SetTile_Iconic_IconImage>（1 处引用） */
/* @0x15b5d4 andseq r11, lr, r0, ror lr —— 池字 0x1ebe70 = 串偏移 → 0x347a40 "winphone_tile_icon_image"（1 处引用） */
/* @0x15b5d8 .word 0xffffe1c8 —— 池字 0xffffe1c8 = GOT 偏移 → 槽 0x3efe20 = 0x158f30 <F_YoYo_WinPhone_SetTile_Iconic_SmallIconImage>（1 处引用） */
/* @0x15b5dc andseq r11, lr, r0, ror lr —— 池字 0x1ebe70 = 串偏移 → 0x347a5c "winphone_tile_small_icon_image"（1 处引用） */
/* @0x15b5e0 .word 0xffffe1cc —— 池字 0xffffe1cc = GOT 偏移 → 槽 0x3efe24 = 0x1562c4 <F_YoYo_WinPhone_SetTile_Iconic_WideContent>（1 处引用） */
/* @0x15b5e4 andseq r11, lr, r4, ror lr —— 池字 0x1ebe74 = 串偏移 → 0x347a7c "winphone_tile_wide_content"（1 处引用） */
/* @0x15b5e8 .word 0xffffe1d0 —— 池字 0xffffe1d0 = GOT 偏移 → 槽 0x3efe28 = 0x158578 <F_YoYo_WinPhone_SetTile_Cycle_CycleImages>（1 处引用） */
/* @0x15b5ec andseq r11, lr, r4, ror lr —— 池字 0x1ebe74 = 串偏移 → 0x347a98 "winphone_tile_cycle_images"（1 处引用） */
/* @0x15b5f0 .word 0xffffe1d4 —— 池字 0xffffe1d4 = GOT 偏移 → 槽 0x3efe2c = 0x158fb4 <F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImage>（1 处引用） */
/* @0x15b5f4 andseq r11, lr, r4, ror lr —— 池字 0x1ebe74 = 串偏移 → 0x347ab4 "winphone_tile_small_background_image"（1 处引用） */
/* @0x15b5f8 .word 0xffffe1d8 —— 池字 0xffffe1d8 = GOT 偏移 → 槽 0x3efe30 = 0x1586d4 <F_GMLReleaseMode>（1 处引用） */
/* @0x15b5fc andseq r11, lr, r0, lsl #29 —— 池字 0x1ebe80 = 串偏移 → 0x347adc "gml_release_mode"（1 处引用） */
/* @0x15b600 .word 0xffffe1dc —— 池字 0xffffe1dc = GOT 偏移 → 槽 0x3efe34 = 0x158370 <F_GMLApplicationSurfaceDrawEnable>（1 处引用） */
/* @0x15b604 andseq r11, lr, r8, ror lr —— 池字 0x1ebe78 = 串偏移 → 0x347af0 "application_surface_draw_enable"（1 处引用） */
/* @0x15b608 .word 0xffffe1e0 —— 池字 0xffffe1e0 = GOT 偏移 → 槽 0x3efe38 = 0x158980 <F_ApplicationGetPos>（1 处引用） */
/* @0x15b60c andseq r11, lr, r12, ror lr —— 池字 0x1ebe7c = 串偏移 → 0x347b10 "application_get_position"（1 处引用） */
/* @0x15b610 .word 0xffffe1e4 —— 池字 0xffffe1e4 = GOT 偏移 → 槽 0x3efe3c = 0x1583ac <F_AppSurfaceEnable>（1 处引用） */
/* @0x15b614 andseq r11, lr, r12, ror lr —— 池字 0x1ebe7c = 串偏移 → 0x347b2c "application_surface_enable"（1 处引用） */
/* @0x15b618 .word 0xffffe1e8 —— 池字 0xffffe1e8 = GOT 偏移 → 槽 0x3efe40 = 0x156304 <F_AppSurfaceIsEnabled>（1 处引用） */
/* @0x15b61c andseq r11, lr, r12, ror lr —— 池字 0x1ebe7c = 串偏移 → 0x347b48 "application_surface_is_enabled"（1 处引用） */
/* @0x15b620 .word 0xffffe1ec —— 池字 0xffffe1ec = GOT 偏移 → 槽 0x3efe44 = 0x158824 <F_PlayerRun>（1 处引用） */
/* @0x15b624 andseq r11, lr, r0, lsl #29 —— 池字 0x1ebe80 = 串偏移 → 0x347b68 "yyg_player_run"（1 处引用） */
/* @0x15b628 .word 0xffffe1f0 —— 池字 0xffffe1f0 = GOT 偏移 → 槽 0x3efe48 = 0x156338 <F_PlayerRestarted>（1 处引用） */
/* @0x15b62c andseq r11, lr, r4, ror lr —— 池字 0x1ebe74 = 串偏移 → 0x347b78 "yyg_player_restarted"（1 处引用） */
/* @0x15b630 .word 0xffffe1f4 —— 池字 0xffffe1f4 = GOT 偏移 → 槽 0x3efe4c = 0x156bcc <F_PlayerGetLaunchArgs>（1 处引用） */
/* @0x15b634 andseq r11, lr, r0, ror lr —— 池字 0x1ebe70 = 串偏移 → 0x347b90 "yyg_player_launch_args"（1 处引用） */
/* @0x15b638 .word 0xffffe1f8 —— 池字 0xffffe1f8 = GOT 偏移 → 槽 0x3efe50 = 0x15636c <F_ExtensionStubFuncReal>（1 处引用） */
/* @0x15b63c andseq r11, lr, r12, ror #28 —— 池字 0x1ebe6c = 串偏移 → 0x347ba8 "extension_stubfunc_real"（1 处引用） */
/* @0x15b640 .word 0xffffe1fc —— 池字 0xffffe1fc = GOT 偏移 → 槽 0x3efe54 = 0x156be0 <F_ExtensionStubFuncString>（1 处引用） */
/* @0x15b644 andseq r11, lr, r8, ror #28 —— 池字 0x1ebe68 = 串偏移 → 0x347bc0 "extension_stubfunc_string"（1 处引用） */
/* @0x15b648 .word 0xffffe200 —— 池字 0xffffe200 = GOT 偏移 → 槽 0x3efe58 = 0x1563a0 <F_Platform_Function_Not_Supported>（1 处引用） */
/* @0x15b64c andseq r11, lr, r8, ror #28 —— 池字 0x1ebe68 = 串偏移 → 0x347bdc "ps4_share_screenshot_enable"（1 处引用） */
/* @0x15b650 andseq r11, lr, r8, ror #28 —— 池字 0x1ebe68 = 串偏移 → 0x347bf8 "ps4_share_video_enable"（1 处引用） */
/* @0x15b654 andseq r11, lr, r8, ror #28 —— 池字 0x1ebe68 = 串偏移 → 0x347c10 "xboxone_package_check_license"（1 处引用） */
/* @0x15b658 andseq r11, lr, r4, ror lr —— 池字 0x1ebe74 = 串偏移 → 0x347c30 "xboxone_get_user_count"（1 处引用） */
/* @0x15b65c andseq r11, lr, r0, ror lr —— 池字 0x1ebe70 = 串偏移 → 0x347c48 "xboxone_get_user"（1 处引用） */
/* @0x15b660 andseq r11, lr, r12, ror #28 —— 池字 0x1ebe6c = 串偏移 → 0x347c5c "xboxone_get_activating_user"（1 处引用） */
/* @0x15b664 andseq r11, lr, r0, ror lr —— 池字 0x1ebe70 = 串偏移 → 0x347c78 "xboxone_user_is_active"（1 处引用） */
/* @0x15b668 andseq r11, lr, r0, ror lr —— 池字 0x1ebe70 = 串偏移 → 0x347c90 "xboxone_user_is_guest"（1 处引用） */
/* @0x15b66c andseq r11, lr, r0, ror lr —— 池字 0x1ebe70 = 串偏移 → 0x347ca8 "xboxone_user_is_signed_in"（1 处引用） */
/* @0x15b670 andseq r11, lr, r4, ror lr —— 池字 0x1ebe74 = 串偏移 → 0x347cc4 "xboxone_user_is_remote"（1 处引用） */
/* @0x15b674 andseq r11, lr, r4, ror lr —— 池字 0x1ebe74 = 串偏移 → 0x347cdc "xboxone_gamedisplayname_for_user"（1 处引用） */
/* @0x15b678 andseq r11, lr, r0, lsl #29 —— 池字 0x1ebe80 = 串偏移 → 0x347d00 "xboxone_appdisplayname_for_user"（1 处引用） */
/* @0x15b67c andseq r11, lr, r8, lsl #29 —— 池字 0x1ebe88 = 串偏移 → 0x347d20 "xboxone_user_id_for_user"（1 处引用） */
/* @0x15b680 andseq r11, lr, r12, lsl #29 —— 池字 0x1ebe8c = 串偏移 → 0x347d3c "xboxone_agegroup_for_user"（1 处引用） */
/* @0x15b684 mulseq lr, r0, lr —— 池字 0x1ebe90 = 串偏移 → 0x347d58 "xboxone_gamerscore_for_user"（1 处引用） */
/* @0x15b688 mulseq lr, r4, lr —— 池字 0x1ebe94 = 串偏移 → 0x347d74 "xboxone_reputation_for_user"（1 处引用） */
/* @0x15b68c mulseq lr, r8, lr —— 池字 0x1ebe98 = 串偏移 → 0x347d90 "xboxone_user_for_pad"（1 处引用） */
/* @0x15b690 mulseq lr, r8, lr —— 池字 0x1ebe98 = 串偏移 → 0x347da8 "xboxone_pad_count_for_user"（1 处引用） */
/* @0x15b694 andseq r11, lr, r0, lsr #29 —— 池字 0x1ebea0 = 串偏移 → 0x347dc4 "xboxone_pad_for_user"（1 处引用） */
/* @0x15b698 andseq r11, lr, r0, lsr #29 —— 池字 0x1ebea0 = 串偏移 → 0x347ddc "xboxone_sponsor_for_user"（1 处引用） */
/* @0x15b69c andseq r11, lr, r4, lsr #29 —— 池字 0x1ebea4 = 串偏移 → 0x347df8 "xboxone_show_account_picker"（1 处引用） */
/* @0x15b6a0 andseq r11, lr, r8, lsr #29 —— 池字 0x1ebea8 = 串偏移 → 0x347e14 "xboxone_sprite_add_from_gamerpicture"（1 处引用） */
/* @0x15b6a4 ldrheq r11, [lr], -r8 —— 池字 0x1ebeb8 = 串偏移 → 0x347e3c "xboxone_show_profile_card_for_user"（1 处引用） */
/* @0x15b6a8 andseq r11, lr, r4, asr #29 —— 池字 0x1ebec4 = 串偏移 → 0x347e60 "xboxone_generate_player_session_id"（1 处引用） */
/* @0x15b6ac andseq r11, lr, r12, asr #29 —— 池字 0x1ebecc = 串偏移 → 0x347e84 "xboxone_set_savedata_user"（1 处引用） */
/* @0x15b6b0 ldrsbeq r11, [lr], -r4 —— 池字 0x1ebed4 = 串偏移 → 0x347ea0 "xboxone_get_savedata_user"（1 处引用） */
/* @0x15b6b4 ldrsbeq r11, [lr], -r8 —— 池字 0x1ebed8 = 串偏移 → 0x347ebc "xboxone_get_file_error"（1 处引用） */
/* @0x15b6b8 ldrsbeq r11, [lr], -r8 —— 池字 0x1ebed8 = 串偏移 → 0x347ed4 "xboxone_was_terminated"（1 处引用） */
/* @0x15b6bc ldrsbeq r11, [lr], -r8 —— 池字 0x1ebed8 = 串偏移 → 0x347eec "xboxone_is_suspending"（1 处引用） */
/* @0x15b6c0 ldrsbeq r11, [lr], -r8 —— 池字 0x1ebed8 = 串偏移 → 0x347f04 "xboxone_is_constrained"（1 处引用） */
/* @0x15b6c4 ldrsbeq r11, [lr], -r8 —— 池字 0x1ebed8 = 串偏移 → 0x347f1c "xboxone_suspend"（1 处引用） */
/* @0x15b6c8 andseq r11, lr, r12, asr #29 —— 池字 0x1ebecc = 串偏移 → 0x347f2c "xboxone_show_help"（1 处引用） */
/* @0x15b6cc andseq r11, lr, r12, asr #29 —— 池字 0x1ebecc = 串偏移 → 0x347f40 "xboxone_license_trial_version"（1 处引用） */
/* @0x15b6d0 ldrsbeq r11, [lr], -r4 —— 池字 0x1ebed4 = 串偏移 → 0x347f60 "xboxone_license_trial_user"（1 处引用） */
/* @0x15b6d4 ldrsbeq r11, [lr], -r8 —— 池字 0x1ebed8 = 串偏移 → 0x347f7c "xboxone_license_trial_time_remaining"（1 处引用） */
/* @0x15b6d8 andseq r11, lr, r8, ror #29 —— 池字 0x1ebee8 = 串偏移 → 0x347fa4 "xboxone_check_privilege"（1 处引用） */
/* @0x15b6dc andseq r11, lr, r8, ror #29 —— 池字 0x1ebee8 = 串偏移 → 0x347fbc "xboxone_fire_event"（1 处引用） */
/* @0x15b6e0 andseq r11, lr, r4, ror #29 —— 池字 0x1ebee4 = 串偏移 → 0x347fd0 "xboxone_get_stats_for_user"（1 处引用） */
/* @0x15b6e4 andseq r11, lr, r8, ror #29 —— 池字 0x1ebee8 = 串偏移 → 0x347fec "xboxone_stats_setup"（1 处引用） */
/* @0x15b6e8 andseq r11, lr, r4, ror #29 —— 池字 0x1ebee4 = 串偏移 → 0x348000 "xboxone_stats_set_stat_real"（1 处引用） */
/* @0x15b6ec andseq r11, lr, r8, ror #29 —— 池字 0x1ebee8 = 串偏移 → 0x34801c "xboxone_stats_set_stat_int"（1 处引用） */
/* @0x15b6f0 andseq r11, lr, r12, ror #29 —— 池字 0x1ebeec = 串偏移 → 0x348038 "xboxone_stats_set_stat_string"（1 处引用） */
/* @0x15b6f4 ldrsheq r11, [lr], -r4 —— 池字 0x1ebef4 = 串偏移 → 0x348058 "xboxone_stats_delete_stat"（1 处引用） */
/* @0x15b6f8 ldrsheq r11, [lr], -r8 —— 池字 0x1ebef8 = 串偏移 → 0x348074 "xboxone_stats_get_stat"（1 处引用） */
/* @0x15b6fc ldrsheq r11, [lr], -r4 —— 池字 0x1ebef4 = 串偏移 → 0x34808c "xboxone_stats_get_stat_names"（1 处引用） */
/* @0x15b700 ldrsheq r11, [lr], -r12 —— 池字 0x1ebefc = 串偏移 → 0x3480ac "xboxone_stats_add_user"（1 处引用） */
/* @0x15b704 ldrsheq r11, [lr], -r12 —— 池字 0x1ebefc = 串偏移 → 0x3480c4 "xboxone_stats_remove_user"（1 处引用） */
/* @0x15b708 andseq r11, lr, r4, lsl #30 —— 池字 0x1ebf04 = 串偏移 → 0x3480e0 "xboxone_stats_flush_user"（1 处引用） */
/* @0x15b70c andseq r11, lr, r8, lsl #30 —— 池字 0x1ebf08 = 串偏移 → 0x3480fc "xboxone_stats_get_leaderboard"（1 处引用） */
/* @0x15b710 andseq r11, lr, r0, lsl pc —— 池字 0x1ebf10 = 串偏移 → 0x34811c "xboxone_stats_get_social_leaderboard"（1 处引用） */
/* @0x15b714 andseq r11, lr, r0, lsr #30 —— 池字 0x1ebf20 = 串偏移 → 0x348144 "xboxone_achievements_set_progress"（1 处引用） */
/* @0x15b718 andseq r11, lr, r12, lsr #30 —— 池字 0x1ebf2c = 串偏移 → 0x348168 "xboxone_set_rich_presence"（1 处引用） */
/* @0x15b71c andseq r11, lr, r0, lsr pc —— 池字 0x1ebf30 = 串偏移 → 0x348184 "xboxone_matchmaking_create"（1 处引用） */
/* @0x15b720 andseq r11, lr, r4, lsr pc —— 池字 0x1ebf34 = 串偏移 → 0x3481a0 "xboxone_matchmaking_find"（1 处引用） */
/* @0x15b724 andseq r11, lr, r4, lsr pc —— 池字 0x1ebf34 = 串偏移 → 0x3481bc "xboxone_matchmaking_start"（1 处引用） */
/* @0x15b728 andseq r11, lr, r8, lsr pc —— 池字 0x1ebf38 = 串偏移 → 0x3481d8 "xboxone_matchmaking_stop"（1 处引用） */
/* @0x15b72c andseq r11, lr, r12, lsr pc —— 池字 0x1ebf3c = 串偏移 → 0x3481f4 "xboxone_matchmaking_session_get_users"（1 处引用） */
/* @0x15b730 andseq r11, lr, r12, asr #30 —— 池字 0x1ebf4c = 串偏移 → 0x34821c "xboxone_matchmaking_session_leave"（1 处引用） */
/* @0x15b734 andseq r11, lr, r12, asr pc —— 池字 0x1ebf5c = 串偏移 → 0x348240 "xboxone_matchmaking_send_invites"（1 处引用） */
/* @0x15b738 andseq r11, lr, r8, ror #30 —— 池字 0x1ebf68 = 串偏移 → 0x348264 "xboxone_matchmaking_set_joinable_session"（1 处引用） */
/* @0x15b73c andseq r11, lr, r12, ror pc —— 池字 0x1ebf7c = 串偏移 → 0x348290 "xboxone_matchmaking_join_invite"（1 处引用） */
/* @0x15b740 andseq r11, lr, r4, lsl #31 —— 池字 0x1ebf84 = 串偏移 → 0x3482b0 "xboxone_matchmaking_join_session"（1 处引用） */
/* @0x15b744 mulseq lr, r0, pc —— 池字 0x1ebf90 = 串偏移 → 0x3482d4 "xboxone_chat_add_user_to_channel"（1 处引用） */
/* @0x15b748 mulseq lr, r12, pc —— 池字 0x1ebf9c = 串偏移 → 0x3482f8 "xboxone_chat_remove_user_from_channel"（1 处引用） */
/* @0x15b74c andseq r11, lr, r8, lsr #31 —— 池字 0x1ebfa8 = 串偏移 → 0x348320 "xboxone_chat_set_muted"（1 处引用） */
/* @0x15b750 andseq r11, lr, r8, lsr #31 —— 池字 0x1ebfa8 = 串偏移 → 0x348338 "xboxone_set_service_configuration_id"（1 处引用） */
/* @0x15b754 ldrheq r11, [lr], -r12 —— 池字 0x1ebfbc = 串偏移 → 0x348360 "xboxone_read_player_leaderboard"（1 处引用） */
/* @0x15b758 andseq r11, lr, r4, asr #31 —— 池字 0x1ebfc4 = 串偏移 → 0x348380 "xboxlive_get_user_count"（1 处引用） */
/* @0x15b75c andseq r11, lr, r0, asr #31 —— 池字 0x1ebfc0 = 串偏移 → 0x348398 "xboxlive_get_user"（1 处引用） */
/* @0x15b760 ldrheq r11, [lr], -r12 —— 池字 0x1ebfbc = 串偏移 → 0x3483ac "xboxlive_get_activating_user"（1 处引用） */
/* @0x15b764 andseq r11, lr, r4, asr #31 —— 池字 0x1ebfc4 = 串偏移 → 0x3483cc "xboxlive_user_is_active"（1 处引用） */
/* @0x15b768 andseq r11, lr, r4, asr #31 —— 池字 0x1ebfc4 = 串偏移 → 0x3483e4 "xboxlive_user_is_guest"（1 处引用） */
/* @0x15b76c andseq r11, lr, r4, asr #31 —— 池字 0x1ebfc4 = 串偏移 → 0x3483fc "xboxlive_user_is_signed_in"（1 处引用） */
/* @0x15b770 andseq r11, lr, r8, asr #31 —— 池字 0x1ebfc8 = 串偏移 → 0x348418 "xboxlive_user_is_signing_in"（1 处引用） */
/* @0x15b774 andseq r11, lr, r12, asr #31 —— 池字 0x1ebfcc = 串偏移 → 0x348434 "xboxlive_user_is_remote"（1 处引用） */
/* @0x15b778 andseq r11, lr, r12, asr #31 —— 池字 0x1ebfcc = 串偏移 → 0x34844c "xboxlive_gamedisplayname_for_user"（1 处引用） */
/* @0x15b77c ldrsbeq r11, [lr], -r8 —— 池字 0x1ebfd8 = 串偏移 → 0x348470 "xboxlive_appdisplayname_for_user"（1 处引用） */
/* @0x15b780 andseq r11, lr, r8, ror #31 —— 池字 0x1ebfe8 = 串偏移 → 0x348494 "xboxlive_gamertag_for_user"（1 处引用） */
/* @0x15b784 andseq r11, lr, r8, ror #31 —— 池字 0x1ebfe8 = 串偏移 → 0x3484b0 "xboxlive_user_id_for_user"（1 处引用） */
/* @0x15b788 andseq r11, lr, r12, ror #31 —— 池字 0x1ebfec = 串偏移 → 0x3484cc "xboxlive_agegroup_for_user"（1 处引用） */
/* @0x15b78c ldrsheq r11, [lr], -r0 —— 池字 0x1ebff0 = 串偏移 → 0x3484e8 "xboxlive_gamerscore_for_user"（1 处引用） */
/* @0x15b790 ldrsheq r11, [lr], -r8 —— 池字 0x1ebff8 = 串偏移 → 0x348508 "xboxlive_reputation_for_user"（1 处引用） */
/* @0x15b794 andseq r12, lr, r0 —— 池字 0x1ec000 = 串偏移 → 0x348528 "xboxlive_user_for_pad"（1 处引用） */
/* @0x15b798 andseq r12, lr, r0 —— 池字 0x1ec000 = 串偏移 → 0x348540 "xboxlive_pad_count_for_user"（1 处引用） */
/* @0x15b79c andseq r12, lr, r8 —— 池字 0x1ec008 = 串偏移 → 0x34855c "xboxlive_pad_for_user"（1 处引用） */
/* @0x15b7a0 andseq r12, lr, r8 —— 池字 0x1ec008 = 串偏移 → 0x348574 "xboxlive_sponsor_for_user"（1 处引用） */
/* @0x15b7a4 andseq r12, lr, r12 —— 池字 0x1ec00c = 串偏移 → 0x348590 "xboxlive_show_account_picker"（1 处引用） */
/* @0x15b7a8 andseq r12, lr, r4, lsl r0 —— 池字 0x1ec014 = 串偏移 → 0x3485b0 "xboxlive_sprite_add_from_gamerpicture"（1 处引用） */
/* @0x15b7ac andseq r12, lr, r4, lsr #32 —— 池字 0x1ec024 = 串偏移 → 0x3485d8 "xboxlive_show_profile_card_for_user"（1 处引用） */
/* @0x15b7b0 andseq r12, lr, r0, lsr r0 —— 池字 0x1ec030 = 串偏移 → 0x3485fc "xboxlive_generate_player_session_id"（1 处引用） */
/* @0x15b7b4 andseq r12, lr, r12, lsr r0 —— 池字 0x1ec03c = 串偏移 → 0x348620 "xboxlive_read_player_leaderboard"（1 处引用） */
/* @0x15b7b8 andseq r12, lr, r4, asr #32 —— 池字 0x1ec044 = 串偏移 → 0x348644 "xboxlive_set_savedata_user"（1 处引用） */
/* @0x15b7bc andseq r12, lr, r12, asr #32 —— 池字 0x1ec04c = 串偏移 → 0x348660 "xboxlive_get_savedata_user"（1 处引用） */
/* @0x15b7c0 andseq r12, lr, r0, asr r0 —— 池字 0x1ec050 = 串偏移 → 0x34867c "xboxlive_get_file_error"（1 处引用） */
/* @0x15b7c4 andseq r12, lr, r0, asr r0 —— 池字 0x1ec050 = 串偏移 → 0x348694 "uwp_was_terminated"（1 处引用） */
/* @0x15b7c8 andseq r12, lr, r12, asr #32 —— 池字 0x1ec04c = 串偏移 → 0x3486a8 "uwp_is_suspending"（1 处引用） */
/* @0x15b7cc andseq r12, lr, r8, asr #32 —— 池字 0x1ec048 = 串偏移 → 0x3486bc "uwp_is_constrained"（1 处引用） */
/* @0x15b7d0 andseq r12, lr, r4, asr #32 —— 池字 0x1ec044 = 串偏移 → 0x3486d0 "uwp_suspend"（1 处引用） */
/* @0x15b7d4 andseq r12, lr, r4, lsr r0 —— 池字 0x1ec034 = 串偏移 → 0x3486dc "uwp_show_help"（1 处引用） */
/* @0x15b7d8 andseq r12, lr, r0, lsr r0 —— 池字 0x1ec030 = 串偏移 → 0x3486ec "uwp_license_trial_version"（1 处引用） */
/* @0x15b7dc andseq r12, lr, r4, lsr r0 —— 池字 0x1ec034 = 串偏移 → 0x348708 "uwp_license_trial_user"（1 处引用） */
/* @0x15b7e0 andseq r12, lr, r4, lsr r0 —— 池字 0x1ec034 = 串偏移 → 0x348720 "uwp_license_trial_time_remaining"（1 处引用） */
/* @0x15b7e4 andseq r12, lr, r0, asr #32 —— 池字 0x1ec040 = 串偏移 → 0x348744 "uwp_check_privilege"（1 处引用） */
/* @0x15b7e8 andseq r12, lr, r12, lsr r0 —— 池字 0x1ec03c = 串偏移 → 0x348758 "xboxlive_fire_event"（1 处引用） */
/* @0x15b7ec andseq r12, lr, r8, lsr r0 —— 池字 0x1ec038 = 串偏移 → 0x34876c "xboxlive_get_stats_for_user"（1 处引用） */
/* @0x15b7f0 andseq r12, lr, r12, lsr r0 —— 池字 0x1ec03c = 串偏移 → 0x348788 "xboxlive_stats_setup"（1 处引用） */
/* @0x15b7f4 andseq r12, lr, r12, lsr r0 —— 池字 0x1ec03c = 串偏移 → 0x3487a0 "xboxlive_stats_set_stat_real"（1 处引用） */
/* @0x15b7f8 andseq r12, lr, r4, asr #32 —— 池字 0x1ec044 = 串偏移 → 0x3487c0 "xboxlive_stats_set_stat_int"（1 处引用） */
/* @0x15b7fc andseq r12, lr, r8, asr #32 —— 池字 0x1ec048 = 串偏移 → 0x3487dc "xboxlive_stats_set_stat_string"（1 处引用） */
/* @0x15b800 andseq r12, lr, r0, asr r0 —— 池字 0x1ec050 = 串偏移 → 0x3487fc "xboxlive_stats_delete_stat"（1 处引用） */
/* @0x15b804 andseq r12, lr, r4, asr r0 —— 池字 0x1ec054 = 串偏移 → 0x348818 "xboxlive_stats_get_stat"（1 处引用） */
/* @0x15b808 andseq r12, lr, r0, asr r0 —— 池字 0x1ec050 = 串偏移 → 0x348830 "xboxlive_stats_get_stat_names"（1 处引用） */
/* @0x15b80c andseq r12, lr, r8, asr r0 —— 池字 0x1ec058 = 串偏移 → 0x348850 "xboxlive_stats_add_user"（1 处引用） */
/* @0x15b810 andseq r12, lr, r8, asr r0 —— 池字 0x1ec058 = 串偏移 → 0x348868 "xboxlive_stats_remove_user"（1 处引用） */

/* ══ §2 注册块 2：0x15b814..0x15cfa4（#141 的 bl + #142..#384 共 244 条 bl）══ */
/*   #141 的 6 条在 §1 末尾（0x15b0c0..0x15b0d4），被 0x15b0d8 的 b 跨过整段池，bl 落在 0x15b814。
 *   下面先收这条的 bl，再按顺序列 #142..#384。
 */

/* ── #141 收尾 · 0x15b814 · facebook_post_message → F_YoYo_FacebookPostMessage (0x157390) · argc=7 · flag=0 ── */
/* @0x15b814 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_post_message", 0x157390 <F_YoYo_FacebookPostMessage>, 7, 0) */

/* ── #142 · 0x15b818..0x15b830 · facebook_send_invite → F_YoYo_FacebookSendInvite (0x157450) · argc=5 · flag=0 ── */
/* @0x15b818 ldr r1, [pc, #-0x350] —— 池字 0xffffe148：GOT 偏移 -0x1eb8 → 槽 0x3efda0 = 0x157450 <F_YoYo_FacebookSendInvite> */
/* @0x15b81c ldr r0, [pc, #-0x350] —— 池字 0x1ebef4：串偏移 → 0x347728 "facebook_send_invite" */
/* @0x15b820 mov r3, r4 —— flag = 0 */
/* @0x15b824 mov r2, #5 —— argc = 5 */
/* @0x15b828 ldr r1, [r10, r1] —— r1 = *(槽 0x3efda0) = 0x157450 <F_YoYo_FacebookSendInvite> */
/* @0x15b82c add r0, pc, r0 —— r0 = 0x347728 = "facebook_send_invite" */
/* @0x15b830 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_send_invite", 0x157450 <F_YoYo_FacebookSendInvite>, 5, 0) */
/* ── #143 · 0x15b834..0x15b84c · facebook_check_permission → F_YoYo_FacebookCheckPermission (0x157550) · argc=1 · flag=0 ── */
/* @0x15b834 ldr r1, [pc, #-0x364] —— 池字 0xffffe14c：GOT 偏移 -0x1eb4 → 槽 0x3efda4 = 0x157550 <F_YoYo_FacebookCheckPermission> */
/* @0x15b838 ldr r0, [pc, #-0x364] —— 池字 0x1ebef0：串偏移 → 0x347740 "facebook_check_permission" */
/* @0x15b83c mov r3, r4 —— flag = 0 */
/* @0x15b840 mov r2, #1 —— argc = 1 */
/* @0x15b844 ldr r1, [r10, r1] —— r1 = *(槽 0x3efda4) = 0x157550 <F_YoYo_FacebookCheckPermission> */
/* @0x15b848 add r0, pc, r0 —— r0 = 0x347740 = "facebook_check_permission" */
/* @0x15b84c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_check_permission", 0x157550 <F_YoYo_FacebookCheckPermission>, 1, 0) */
/* ── #144 · 0x15b850..0x15b868 · facebook_request_read_permissions → F_YoYo_FacebookRequestReadPermissions (0x157590) · argc=1 · flag=0 ── */
/* @0x15b850 ldr r1, [pc, #-0x378] —— 池字 0xffffe150：GOT 偏移 -0x1eb0 → 槽 0x3efda8 = 0x157590 <F_YoYo_FacebookRequestReadPermissions> */
/* @0x15b854 ldr r0, [pc, #-0x378] —— 池字 0x1ebef0：串偏移 → 0x34775c "facebook_request_read_permissions" */
/* @0x15b858 mov r3, r4 —— flag = 0 */
/* @0x15b85c mov r2, #1 —— argc = 1 */
/* @0x15b860 ldr r1, [r10, r1] —— r1 = *(槽 0x3efda8) = 0x157590 <F_YoYo_FacebookRequestReadPermissions> */
/* @0x15b864 add r0, pc, r0 —— r0 = 0x34775c = "facebook_request_read_permissions" */
/* @0x15b868 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_request_read_permissions", 0x157590 <F_YoYo_FacebookRequestReadPermissions>, 1, 0) */
/* ── #145 · 0x15b86c..0x15b884 · facebook_request_publish_permissions → F_YoYo_FacebookRequestPublishPermissions (0x1575d0) · argc=1 · flag=0 ── */
/* @0x15b86c ldr r1, [pc, #-0x38c] —— 池字 0xffffe154：GOT 偏移 -0x1eac → 槽 0x3efdac = 0x1575d0 <F_YoYo_FacebookRequestPublishPermissions> */
/* @0x15b870 ldr r0, [pc, #-0x38c] —— 池字 0x1ebef8：串偏移 → 0x347780 "facebook_request_publish_permissions" */
/* @0x15b874 mov r3, r4 —— flag = 0 */
/* @0x15b878 mov r2, #1 —— argc = 1 */
/* @0x15b87c ldr r1, [r10, r1] —— r1 = *(槽 0x3efdac) = 0x1575d0 <F_YoYo_FacebookRequestPublishPermissions> */
/* @0x15b880 add r0, pc, r0 —— r0 = 0x347780 = "facebook_request_publish_permissions" */
/* @0x15b884 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("facebook_request_publish_permissions", 0x1575d0 <F_YoYo_FacebookRequestPublishPermissions>, 1, 0) */
/* ── #146 · 0x15b888..0x15b8a4 · YoYo_OSPauseEvent → F_YoYo_OSPauseEvent (0x1561c0) · argc=0 · flag=0 ── */
/* @0x15b888 ldr r1, [pc, #-0x3a0] —— 池字 0xffffe158：GOT 偏移 -0x1ea8 → 槽 0x3efdb0 = 0x1561c0 <F_YoYo_OSPauseEvent> */
/* @0x15b88c mov r2, r4 —— argc = 0 */
/* @0x15b890 mov r3, r4 —— flag = 0 */
/* @0x15b894 ldr r0, [pc, #-0x3a8] —— 池字 0x1ebf04：串偏移 → 0x3477a8 "YoYo_OSPauseEvent" */
/* @0x15b898 ldr r4, [r10, r1] —— r4 = *(槽 0x3efdb0) = 0x1561c0 <F_YoYo_OSPauseEvent> */
/* @0x15b89c add r0, pc, r0 —— r0 = 0x3477a8 = "YoYo_OSPauseEvent" */
/* @0x15b8a0 mov r1, r4 —— r1 = fn = 0x1561c0 <F_YoYo_OSPauseEvent> */
/* @0x15b8a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("YoYo_OSPauseEvent", 0x1561c0 <F_YoYo_OSPauseEvent>, 0, 0) */
/* ── #147 · 0x15b8a8..0x15b8bc · os_is_paused → F_YoYo_OSPauseEvent (0x1561c0) · argc=0 · flag=0 ── */
/* @0x15b8a8 ldr r0, [pc, #-0x3b8] —— 池字 0x1ebefc：串偏移 → 0x3477bc "os_is_paused" */
/* @0x15b8ac mov r2, #0 —— argc = 0 */
/* @0x15b8b0 mov r1, r4 —— r1 = fn = 0x1561c0 <F_YoYo_OSPauseEvent> */
/* @0x15b8b4 mov r3, r2 —— flag = 0 */
/* @0x15b8b8 add r0, pc, r0 —— r0 = 0x3477bc = "os_is_paused" */
/* @0x15b8bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_is_paused", 0x1561c0 <F_YoYo_OSPauseEvent>, 0, 0) */
/* ── #148 · 0x15b8c0..0x15b8d8 · window_has_focus → F_YoYo_OSHasFocus (0x1561f4) · argc=0 · flag=0 ── */
/* @0x15b8c0 ldr r1, [pc, #-0x3cc] —— 池字 0xffffe15c：GOT 偏移 -0x1ea4 → 槽 0x3efdb4 = 0x1561f4 <F_YoYo_OSHasFocus> */
/* @0x15b8c4 ldr r0, [pc, #-0x3cc] —— 池字 0x1ebef0：串偏移 → 0x3477cc "window_has_focus" */
/* @0x15b8c8 mov r2, #0 —— argc = 0 */
/* @0x15b8cc mov r3, r2 —— flag = 0 */
/* @0x15b8d0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdb4) = 0x1561f4 <F_YoYo_OSHasFocus> */
/* @0x15b8d4 add r0, pc, r0 —— r0 = 0x3477cc = "window_has_focus" */
/* @0x15b8d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("window_has_focus", 0x1561f4 <F_YoYo_OSHasFocus>, 0, 0) */
/* ── #149 · 0x15b8dc..0x15b8f4 · base64_encode → F_YoYo_Base64Encode (0x1579f0) · argc=1 · flag=0 ── */
/* @0x15b8dc ldr r1, [pc, #-0x3e0] —— 池字 0xffffe160：GOT 偏移 -0x1ea0 → 槽 0x3efdb8 = 0x1579f0 <F_YoYo_Base64Encode> */
/* @0x15b8e0 ldr r0, [pc, #-0x3e0] —— 池字 0x1ebee8：串偏移 → 0x3477e0 "base64_encode" */
/* @0x15b8e4 mov r2, #1 —— argc = 1 */
/* @0x15b8e8 mov r3, #0 —— flag = 0 */
/* @0x15b8ec ldr r1, [r10, r1] —— r1 = *(槽 0x3efdb8) = 0x1579f0 <F_YoYo_Base64Encode> */
/* @0x15b8f0 add r0, pc, r0 —— r0 = 0x3477e0 = "base64_encode" */
/* @0x15b8f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("base64_encode", 0x1579f0 <F_YoYo_Base64Encode>, 1, 0) */
/* ── #150 · 0x15b8f8..0x15b910 · base64_decode → F_YoYo_Base64Decode (0x157a94) · argc=1 · flag=0 ── */
/* @0x15b8f8 ldr r1, [pc, #-0x3f4] —— 池字 0xffffe164：GOT 偏移 -0x1e9c → 槽 0x3efdbc = 0x157a94 <F_YoYo_Base64Decode> */
/* @0x15b8fc ldr r0, [pc, #-0x3f4] —— 池字 0x1ebedc：串偏移 → 0x3477f0 "base64_decode" */
/* @0x15b900 mov r2, #1 —— argc = 1 */
/* @0x15b904 mov r3, #0 —— flag = 0 */
/* @0x15b908 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdbc) = 0x157a94 <F_YoYo_Base64Decode> */
/* @0x15b90c add r0, pc, r0 —— r0 = 0x3477f0 = "base64_decode" */
/* @0x15b910 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("base64_decode", 0x157a94 <F_YoYo_Base64Decode>, 1, 0) */
/* ── #151 · 0x15b914..0x15b92c · md5_string_unicode → F_YoYo_MD5Unicode (0x157b28) · argc=1 · flag=0 ── */
/* @0x15b914 ldr r1, [pc, #-0x408] —— 池字 0xffffe168：GOT 偏移 -0x1e98 → 槽 0x3efdc0 = 0x157b28 <F_YoYo_MD5Unicode> */
/* @0x15b918 ldr r0, [pc, #-0x408] —— 池字 0x1ebed0：串偏移 → 0x347800 "md5_string_unicode" */
/* @0x15b91c mov r2, #1 —— argc = 1 */
/* @0x15b920 mov r3, #0 —— flag = 0 */
/* @0x15b924 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdc0) = 0x157b28 <F_YoYo_MD5Unicode> */
/* @0x15b928 add r0, pc, r0 —— r0 = 0x347800 = "md5_string_unicode" */
/* @0x15b92c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("md5_string_unicode", 0x157b28 <F_YoYo_MD5Unicode>, 1, 0) */
/* ── #152 · 0x15b930..0x15b948 · md5_string_utf8 → F_YoYo_MD5Utf8 (0x157c54) · argc=1 · flag=0 ── */
/* @0x15b930 ldr r1, [pc, #-0x41c] —— 池字 0xffffe16c：GOT 偏移 -0x1e94 → 槽 0x3efdc4 = 0x157c54 <F_YoYo_MD5Utf8> */
/* @0x15b934 ldr r0, [pc, #-0x41c] —— 池字 0x1ebec8：串偏移 → 0x347814 "md5_string_utf8" */
/* @0x15b938 mov r2, #1 —— argc = 1 */
/* @0x15b93c mov r3, #0 —— flag = 0 */
/* @0x15b940 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdc4) = 0x157c54 <F_YoYo_MD5Utf8> */
/* @0x15b944 add r0, pc, r0 —— r0 = 0x347814 = "md5_string_utf8" */
/* @0x15b948 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("md5_string_utf8", 0x157c54 <F_YoYo_MD5Utf8>, 1, 0) */
/* ── #153 · 0x15b94c..0x15b964 · md5_file → F_YoYo_MD5File (0x157d38) · argc=1 · flag=0 ── */
/* @0x15b94c ldr r1, [pc, #-0x430] —— 池字 0xffffe170：GOT 偏移 -0x1e90 → 槽 0x3efdc8 = 0x157d38 <F_YoYo_MD5File> */
/* @0x15b950 ldr r0, [pc, #-0x430] —— 池字 0x1ebebc：串偏移 → 0x347824 "md5_file" */
/* @0x15b954 mov r2, #1 —— argc = 1 */
/* @0x15b958 mov r3, #0 —— flag = 0 */
/* @0x15b95c ldr r1, [r10, r1] —— r1 = *(槽 0x3efdc8) = 0x157d38 <F_YoYo_MD5File> */
/* @0x15b960 add r0, pc, r0 —— r0 = 0x347824 = "md5_file" */
/* @0x15b964 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("md5_file", 0x157d38 <F_YoYo_MD5File>, 1, 0) */
/* ── #154 · 0x15b968..0x15b980 · sha1_string_unicode → F_YoYo_SHA1Unicode (0x157f4c) · argc=1 · flag=0 ── */
/* @0x15b968 ldr r1, [pc, #-0x444] —— 池字 0xffffe174：GOT 偏移 -0x1e8c → 槽 0x3efdcc = 0x157f4c <F_YoYo_SHA1Unicode> */
/* @0x15b96c ldr r0, [pc, #-0x444] —— 池字 0x1ebeac：串偏移 → 0x347830 "sha1_string_unicode" */
/* @0x15b970 mov r2, #1 —— argc = 1 */
/* @0x15b974 mov r3, #0 —— flag = 0 */
/* @0x15b978 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdcc) = 0x157f4c <F_YoYo_SHA1Unicode> */
/* @0x15b97c add r0, pc, r0 —— r0 = 0x347830 = "sha1_string_unicode" */
/* @0x15b980 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("sha1_string_unicode", 0x157f4c <F_YoYo_SHA1Unicode>, 1, 0) */
/* ── #155 · 0x15b984..0x15b99c · sha1_string_utf8 → F_YoYo_SHA1Utf8 (0x158078) · argc=1 · flag=0 ── */
/* @0x15b984 ldr r1, [pc, #-0x458] —— 池字 0xffffe178：GOT 偏移 -0x1e88 → 槽 0x3efdd0 = 0x158078 <F_YoYo_SHA1Utf8> */
/* @0x15b988 ldr r0, [pc, #-0x458] —— 池字 0x1ebea4：串偏移 → 0x347844 "sha1_string_utf8" */
/* @0x15b98c mov r2, #1 —— argc = 1 */
/* @0x15b990 mov r3, #0 —— flag = 0 */
/* @0x15b994 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdd0) = 0x158078 <F_YoYo_SHA1Utf8> */
/* @0x15b998 add r0, pc, r0 —— r0 = 0x347844 = "sha1_string_utf8" */
/* @0x15b99c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("sha1_string_utf8", 0x158078 <F_YoYo_SHA1Utf8>, 1, 0) */
/* ── #156 · 0x15b9a0..0x15b9b8 · sha1_file → F_YoYo_SHA1File (0x15815c) · argc=1 · flag=0 ── */
/* @0x15b9a0 ldr r1, [pc, #-0x46c] —— 池字 0xffffe17c：GOT 偏移 -0x1e84 → 槽 0x3efdd4 = 0x15815c <F_YoYo_SHA1File> */
/* @0x15b9a4 ldr r0, [pc, #-0x46c] —— 池字 0x1ebe9c：串偏移 → 0x347858 "sha1_file" */
/* @0x15b9a8 mov r2, #1 —— argc = 1 */
/* @0x15b9ac mov r3, #0 —— flag = 0 */
/* @0x15b9b0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdd4) = 0x15815c <F_YoYo_SHA1File> */
/* @0x15b9b4 add r0, pc, r0 —— r0 = 0x347858 = "sha1_file" */
/* @0x15b9b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("sha1_file", 0x15815c <F_YoYo_SHA1File>, 1, 0) */
/* ── #157 · 0x15b9bc..0x15b9d4 · os_is_network_connected → F_YoYo_IsNetworkConnected (0x157f1c) · argc=0 · flag=0 ── */
/* @0x15b9bc ldr r1, [pc, #-0x480] —— 池字 0xffffe180：GOT 偏移 -0x1e80 → 槽 0x3efdd8 = 0x157f1c <F_YoYo_IsNetworkConnected> */
/* @0x15b9c0 ldr r0, [pc, #-0x480] —— 池字 0x1ebe8c：串偏移 → 0x347864 "os_is_network_connected" */
/* @0x15b9c4 mov r2, #0 —— argc = 0 */
/* @0x15b9c8 mov r3, r2 —— flag = 0 */
/* @0x15b9cc ldr r1, [r10, r1] —— r1 = *(槽 0x3efdd8) = 0x157f1c <F_YoYo_IsNetworkConnected> */
/* @0x15b9d0 add r0, pc, r0 —— r0 = 0x347864 = "os_is_network_connected" */
/* @0x15b9d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_is_network_connected", 0x157f1c <F_YoYo_IsNetworkConnected>, 0, 0) */
/* ── #158 · 0x15b9d8..0x15b9f0 · os_powersave_enable → F_YoYo_PowersaveEnable (0x158340) · argc=1 · flag=0 ── */
/* @0x15b9d8 ldr r1, [pc, #-0x494] —— 池字 0xffffe184：GOT 偏移 -0x1e7c → 槽 0x3efddc = 0x158340 <F_YoYo_PowersaveEnable> */
/* @0x15b9dc ldr r0, [pc, #-0x494] —— 池字 0x1ebe88：串偏移 → 0x34787c "os_powersave_enable" */
/* @0x15b9e0 mov r2, #1 —— argc = 1 */
/* @0x15b9e4 mov r3, #0 —— flag = 0 */
/* @0x15b9e8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efddc) = 0x158340 <F_YoYo_PowersaveEnable> */
/* @0x15b9ec add r0, pc, r0 —— r0 = 0x34787c = "os_powersave_enable" */
/* @0x15b9f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_powersave_enable", 0x158340 <F_YoYo_PowersaveEnable>, 1, 0) */
/* ── #159 · 0x15b9f4..0x15ba0c · os_lock_orientation → F_YoYo_LockOrientation (0x1594dc) · argc=1 · flag=0 ── */
/* @0x15b9f4 ldr r1, [pc, #-0x4a8] —— 池字 0xffffe188：GOT 偏移 -0x1e78 → 槽 0x3efde0 = 0x1594dc <F_YoYo_LockOrientation> */
/* @0x15b9f8 ldr r0, [pc, #-0x4a8] —— 池字 0x1ebe80：串偏移 → 0x347890 "os_lock_orientation" */
/* @0x15b9fc mov r2, #1 —— argc = 1 */
/* @0x15ba00 mov r3, #0 —— flag = 0 */
/* @0x15ba04 ldr r1, [r10, r1] —— r1 = *(槽 0x3efde0) = 0x1594dc <F_YoYo_LockOrientation> */
/* @0x15ba08 add r0, pc, r0 —— r0 = 0x347890 = "os_lock_orientation" */
/* @0x15ba0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("os_lock_orientation", 0x1594dc <F_YoYo_LockOrientation>, 1, 0) */
/* ── #160 · 0x15ba10..0x15ba28 · analytics_event → F_YoYo_AnalyticsEvent (0x158358) · argc=1 · flag=0 ── */
/* @0x15ba10 ldr r1, [pc, #-0x4bc] —— 池字 0xffffe18c：GOT 偏移 -0x1e74 → 槽 0x3efde4 = 0x158358 <F_YoYo_AnalyticsEvent> */
/* @0x15ba14 ldr r0, [pc, #-0x4bc] —— 池字 0x1ebe78：串偏移 → 0x3478a4 "analytics_event" */
/* @0x15ba18 mov r2, #1 —— argc = 1 */
/* @0x15ba1c mov r3, #0 —— flag = 0 */
/* @0x15ba20 ldr r1, [r10, r1] —— r1 = *(槽 0x3efde4) = 0x158358 <F_YoYo_AnalyticsEvent> */
/* @0x15ba24 add r0, pc, r0 —— r0 = 0x3478a4 = "analytics_event" */
/* @0x15ba28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("analytics_event", 0x158358 <F_YoYo_AnalyticsEvent>, 1, 0) */
/* ── #161 · 0x15ba2c..0x15ba44 · analytics_event_ext → F_YoYo_AnalyticsEventExt (0x158440) · argc=4294967295 · flag=0 ── */
/* @0x15ba2c ldr r1, [pc, #-0x4d0] —— 池字 0xffffe190：GOT 偏移 -0x1e70 → 槽 0x3efde8 = 0x158440 <F_YoYo_AnalyticsEventExt> */
/* @0x15ba30 ldr r0, [pc, #-0x4d0] —— 池字 0x1ebe6c：串偏移 → 0x3478b4 "analytics_event_ext" */
/* @0x15ba34 mvn r2, #0 */
/* @0x15ba38 mov r3, #0 —— flag = 0 */
/* @0x15ba3c ldr r1, [r10, r1] —— r1 = *(槽 0x3efde8) = 0x158440 <F_YoYo_AnalyticsEventExt> */
/* @0x15ba40 add r0, pc, r0 —— r0 = 0x3478b4 = "analytics_event_ext" */
/* @0x15ba44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("analytics_event_ext", 0x158440 <F_YoYo_AnalyticsEventExt>, 4294967295, 0) */
/* ── #162 · 0x15ba48..0x15ba60 · winphone_license_trial_version → F_YoYo_WinPhone_License_Trial (0x156224) · argc=0 · flag=0 ── */
/* @0x15ba48 ldr r1, [pc, #-0x4e4] —— 池字 0xffffe194：GOT 偏移 -0x1e6c → 槽 0x3efdec = 0x156224 <F_YoYo_WinPhone_License_Trial> */
/* @0x15ba4c ldr r0, [pc, #-0x4e4] —— 池字 0x1ebe64：串偏移 → 0x3478c8 "winphone_license_trial_version" */
/* @0x15ba50 mov r2, #0 —— argc = 0 */
/* @0x15ba54 mov r3, r2 —— flag = 0 */
/* @0x15ba58 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdec) = 0x156224 <F_YoYo_WinPhone_License_Trial> */
/* @0x15ba5c add r0, pc, r0 —— r0 = 0x3478c8 = "winphone_license_trial_version" */
/* @0x15ba60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_license_trial_version", 0x156224 <F_YoYo_WinPhone_License_Trial>, 0, 0) */
/* ── #163 · 0x15ba64..0x15ba7c · winphone_tile_title → F_YoYo_WinPhone_SetTile_Common_Title (0x158a08) · argc=1 · flag=0 ── */
/* @0x15ba64 ldr r1, [pc, #-0x4f8] —— 池字 0xffffe198：GOT 偏移 -0x1e68 → 槽 0x3efdf0 = 0x158a08 <F_YoYo_WinPhone_SetTile_Common_Title> */
/* @0x15ba68 ldr r0, [pc, #-0x4f8] —— 池字 0x1ebe68：串偏移 → 0x3478e8 "winphone_tile_title" */
/* @0x15ba6c mov r2, #1 —— argc = 1 */
/* @0x15ba70 mov r3, #0 —— flag = 0 */
/* @0x15ba74 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdf0) = 0x158a08 <F_YoYo_WinPhone_SetTile_Common_Title> */
/* @0x15ba78 add r0, pc, r0 —— r0 = 0x3478e8 = "winphone_tile_title" */
/* @0x15ba7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_title", 0x158a08 <F_YoYo_WinPhone_SetTile_Common_Title>, 1, 0) */
/* ── #164 · 0x15ba80..0x15ba98 · winphone_tile_count → F_YoYo_WinPhone_SetTile_Common_Count (0x156264) · argc=1 · flag=0 ── */
/* @0x15ba80 ldr r1, [pc, #-0x50c] —— 池字 0xffffe19c：GOT 偏移 -0x1e64 → 槽 0x3efdf4 = 0x156264 <F_YoYo_WinPhone_SetTile_Common_Count> */
/* @0x15ba84 ldr r0, [pc, #-0x50c] —— 池字 0x1ebe60：串偏移 → 0x3478fc "winphone_tile_count" */
/* @0x15ba88 mov r2, #1 —— argc = 1 */
/* @0x15ba8c mov r3, #0 —— flag = 0 */
/* @0x15ba90 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdf4) = 0x156264 <F_YoYo_WinPhone_SetTile_Common_Count> */
/* @0x15ba94 add r0, pc, r0 —— r0 = 0x3478fc = "winphone_tile_count" */
/* @0x15ba98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_count", 0x156264 <F_YoYo_WinPhone_SetTile_Common_Count>, 1, 0) */
/* ── #165 · 0x15ba9c..0x15bab4 · winphone_tile_back_title → F_YoYo_WinPhone_SetTile_Flip_BackTitle (0x158a8c) · argc=1 · flag=0 ── */
/* @0x15ba9c ldr r1, [pc, #-0x520] —— 池字 0xffffe1a0：GOT 偏移 -0x1e60 → 槽 0x3efdf8 = 0x158a8c <F_YoYo_WinPhone_SetTile_Flip_BackTitle> */
/* @0x15baa0 ldr r0, [pc, #-0x520] —— 池字 0x1ebe58：串偏移 → 0x347910 "winphone_tile_back_title" */
/* @0x15baa4 mov r2, #1 —— argc = 1 */
/* @0x15baa8 mov r3, #0 —— flag = 0 */
/* @0x15baac ldr r1, [r10, r1] —— r1 = *(槽 0x3efdf8) = 0x158a8c <F_YoYo_WinPhone_SetTile_Flip_BackTitle> */
/* @0x15bab0 add r0, pc, r0 —— r0 = 0x347910 = "winphone_tile_back_title" */
/* @0x15bab4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_back_title", 0x158a8c <F_YoYo_WinPhone_SetTile_Flip_BackTitle>, 1, 0) */
/* ── #166 · 0x15bab8..0x15bad0 · winphone_tile_back_content → F_YoYo_WinPhone_SetTile_Flip_BackContent (0x158b10) · argc=1 · flag=0 ── */
/* @0x15bab8 ldr r1, [pc, #-0x534] —— 池字 0xffffe1a4：GOT 偏移 -0x1e5c → 槽 0x3efdfc = 0x158b10 <F_YoYo_WinPhone_SetTile_Flip_BackContent> */
/* @0x15babc ldr r0, [pc, #-0x534] —— 池字 0x1ebe58：串偏移 → 0x34792c "winphone_tile_back_content" */
/* @0x15bac0 mov r2, #1 —— argc = 1 */
/* @0x15bac4 mov r3, #0 —— flag = 0 */
/* @0x15bac8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efdfc) = 0x158b10 <F_YoYo_WinPhone_SetTile_Flip_BackContent> */
/* @0x15bacc add r0, pc, r0 —— r0 = 0x34792c = "winphone_tile_back_content" */
/* @0x15bad0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_back_content", 0x158b10 <F_YoYo_WinPhone_SetTile_Flip_BackContent>, 1, 0) */
/* ── #167 · 0x15bad4..0x15baec · winphone_tile_back_content_wide → F_YoYo_WinPhone_SetTile_Flip_BackContentWide (0x158b94) · argc=1 · flag=0 ── */
/* @0x15bad4 ldr r1, [pc, #-0x548] —— 池字 0xffffe1a8：GOT 偏移 -0x1e58 → 槽 0x3efe00 = 0x158b94 <F_YoYo_WinPhone_SetTile_Flip_BackContentWide> */
/* @0x15bad8 ldr r0, [pc, #-0x548] —— 池字 0x1ebe58：串偏移 → 0x347948 "winphone_tile_back_content_wide" */
/* @0x15badc mov r2, #1 —— argc = 1 */
/* @0x15bae0 mov r3, #0 —— flag = 0 */
/* @0x15bae4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe00) = 0x158b94 <F_YoYo_WinPhone_SetTile_Flip_BackContentWide> */
/* @0x15bae8 add r0, pc, r0 —— r0 = 0x347948 = "winphone_tile_back_content_wide" */
/* @0x15baec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_back_content_wide", 0x158b94 <F_YoYo_WinPhone_SetTile_Flip_BackContentWide>, 1, 0) */
/* ── #168 · 0x15baf0..0x15bb08 · winphone_tile_front_image → F_YoYo_WinPhone_SetTile_Flip_FrontImage (0x158c18) · argc=1 · flag=0 ── */
/* @0x15baf0 ldr r1, [pc, #-0x55c] —— 池字 0xffffe1ac：GOT 偏移 -0x1e54 → 槽 0x3efe04 = 0x158c18 <F_YoYo_WinPhone_SetTile_Flip_FrontImage> */
/* @0x15baf4 ldr r0, [pc, #-0x55c] —— 池字 0x1ebe5c：串偏移 → 0x347968 "winphone_tile_front_image" */
/* @0x15baf8 mov r2, #1 —— argc = 1 */
/* @0x15bafc mov r3, #0 —— flag = 0 */
/* @0x15bb00 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe04) = 0x158c18 <F_YoYo_WinPhone_SetTile_Flip_FrontImage> */
/* @0x15bb04 add r0, pc, r0 —— r0 = 0x347968 = "winphone_tile_front_image" */
/* @0x15bb08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_front_image", 0x158c18 <F_YoYo_WinPhone_SetTile_Flip_FrontImage>, 1, 0) */
/* ── #169 · 0x15bb0c..0x15bb24 · winphone_tile_front_image_small → F_YoYo_WinPhone_SetTile_Flip_FrontImageSmall (0x158c9c) · argc=1 · flag=0 ── */
/* @0x15bb0c ldr r1, [pc, #-0x570] —— 池字 0xffffe1b0：GOT 偏移 -0x1e50 → 槽 0x3efe08 = 0x158c9c <F_YoYo_WinPhone_SetTile_Flip_FrontImageSmall> */
/* @0x15bb10 ldr r0, [pc, #-0x570] —— 池字 0x1ebe5c：串偏移 → 0x347984 "winphone_tile_front_image_small" */
/* @0x15bb14 mov r2, #1 —— argc = 1 */
/* @0x15bb18 mov r3, #0 —— flag = 0 */
/* @0x15bb1c ldr r1, [r10, r1] —— r1 = *(槽 0x3efe08) = 0x158c9c <F_YoYo_WinPhone_SetTile_Flip_FrontImageSmall> */
/* @0x15bb20 add r0, pc, r0 —— r0 = 0x347984 = "winphone_tile_front_image_small" */
/* @0x15bb24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_front_image_small", 0x158c9c <F_YoYo_WinPhone_SetTile_Flip_FrontImageSmall>, 1, 0) */
/* ── #170 · 0x15bb28..0x15bb40 · winphone_tile_front_image_wide → F_YoYo_WinPhone_SetTile_Flip_FrontImageWide (0x158d20) · argc=1 · flag=0 ── */
/* @0x15bb28 ldr r1, [pc, #-0x584] —— 池字 0xffffe1b4：GOT 偏移 -0x1e4c → 槽 0x3efe0c = 0x158d20 <F_YoYo_WinPhone_SetTile_Flip_FrontImageWide> */
/* @0x15bb2c ldr r0, [pc, #-0x584] —— 池字 0x1ebe60：串偏移 → 0x3479a4 "winphone_tile_front_image_wide" */
/* @0x15bb30 mov r2, #1 —— argc = 1 */
/* @0x15bb34 mov r3, #0 —— flag = 0 */
/* @0x15bb38 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe0c) = 0x158d20 <F_YoYo_WinPhone_SetTile_Flip_FrontImageWide> */
/* @0x15bb3c add r0, pc, r0 —— r0 = 0x3479a4 = "winphone_tile_front_image_wide" */
/* @0x15bb40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_front_image_wide", 0x158d20 <F_YoYo_WinPhone_SetTile_Flip_FrontImageWide>, 1, 0) */
/* ── #171 · 0x15bb44..0x15bb5c · winphone_tile_back_image → F_YoYo_WinPhone_SetTile_Flip_BackImage (0x158da4) · argc=1 · flag=0 ── */
/* @0x15bb44 ldr r1, [pc, #-0x598] —— 池字 0xffffe1b8：GOT 偏移 -0x1e48 → 槽 0x3efe10 = 0x158da4 <F_YoYo_WinPhone_SetTile_Flip_BackImage> */
/* @0x15bb48 ldr r0, [pc, #-0x598] —— 池字 0x1ebe64：串偏移 → 0x3479c4 "winphone_tile_back_image" */
/* @0x15bb4c mov r2, #1 —— argc = 1 */
/* @0x15bb50 mov r3, #0 —— flag = 0 */
/* @0x15bb54 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe10) = 0x158da4 <F_YoYo_WinPhone_SetTile_Flip_BackImage> */
/* @0x15bb58 add r0, pc, r0 —— r0 = 0x3479c4 = "winphone_tile_back_image" */
/* @0x15bb5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_back_image", 0x158da4 <F_YoYo_WinPhone_SetTile_Flip_BackImage>, 1, 0) */
/* ── #172 · 0x15bb60..0x15bb78 · winphone_tile_back_image_wide → F_YoYo_WinPhone_SetTile_Flip_BackImageWide (0x158e28) · argc=1 · flag=0 ── */
/* @0x15bb60 ldr r1, [pc, #-0x5ac] —— 池字 0xffffe1bc：GOT 偏移 -0x1e44 → 槽 0x3efe14 = 0x158e28 <F_YoYo_WinPhone_SetTile_Flip_BackImageWide> */
/* @0x15bb64 ldr r0, [pc, #-0x5ac] —— 池字 0x1ebe64：串偏移 → 0x3479e0 "winphone_tile_back_image_wide" */
/* @0x15bb68 mov r2, #1 —— argc = 1 */
/* @0x15bb6c mov r3, #0 —— flag = 0 */
/* @0x15bb70 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe14) = 0x158e28 <F_YoYo_WinPhone_SetTile_Flip_BackImageWide> */
/* @0x15bb74 add r0, pc, r0 —— r0 = 0x3479e0 = "winphone_tile_back_image_wide" */
/* @0x15bb78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_back_image_wide", 0x158e28 <F_YoYo_WinPhone_SetTile_Flip_BackImageWide>, 1, 0) */
/* ── #173 · 0x15bb7c..0x15bb98 · winphone_tile_background_color → F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour (0x156294) · argc=1 · flag=0 ── */
/* @0x15bb7c ldr r1, [pc, #-0x5c0] —— 池字 0xffffe1c0：GOT 偏移 -0x1e40 → 槽 0x3efe18 = 0x156294 <F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour> */
/* @0x15bb80 ldr r0, [pc, #-0x5c0] —— 池字 0x1ebe68：串偏移 → 0x347a00 "winphone_tile_background_color" */
/* @0x15bb84 mov r2, #1 —— argc = 1 */
/* @0x15bb88 mov r3, #0 —— flag = 0 */
/* @0x15bb8c ldr r4, [r10, r1] —— r4 = *(槽 0x3efe18) = 0x156294 <F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour> */
/* @0x15bb90 add r0, pc, r0 —— r0 = 0x347a00 = "winphone_tile_background_color" */
/* @0x15bb94 mov r1, r4 —— r1 = fn = 0x156294 <F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour> */
/* @0x15bb98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_background_color", 0x156294 <F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour>, 1, 0) */
/* ── #174 · 0x15bb9c..0x15bbb0 · winphone_tile_background_colour → F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour (0x156294) · argc=1 · flag=0 ── */
/* @0x15bb9c ldr r0, [pc, #-0x5d8] —— 池字 0x1ebe70：串偏移 → 0x347a20 "winphone_tile_background_colour" */
/* @0x15bba0 mov r1, r4 —— r1 = fn = 0x156294 <F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour> */
/* @0x15bba4 mov r2, #1 —— argc = 1 */
/* @0x15bba8 add r0, pc, r0 —— r0 = 0x347a20 = "winphone_tile_background_colour" */
/* @0x15bbac mov r3, #0 —— flag = 0 */
/* @0x15bbb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_background_colour", 0x156294 <F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour>, 1, 0) */
/* ── #175 · 0x15bbb4..0x15bbcc · winphone_tile_icon_image → F_YoYo_WinPhone_SetTile_Iconic_IconImage (0x158eac) · argc=1 · flag=0 ── */
/* @0x15bbb4 ldr r1, [pc, #-0x5ec] —— 池字 0xffffe1c4：GOT 偏移 -0x1e3c → 槽 0x3efe1c = 0x158eac <F_YoYo_WinPhone_SetTile_Iconic_IconImage> */
/* @0x15bbb8 ldr r0, [pc, #-0x5ec] —— 池字 0x1ebe70：串偏移 → 0x347a40 "winphone_tile_icon_image" */
/* @0x15bbbc mov r2, #1 —— argc = 1 */
/* @0x15bbc0 mov r3, #0 —— flag = 0 */
/* @0x15bbc4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe1c) = 0x158eac <F_YoYo_WinPhone_SetTile_Iconic_IconImage> */
/* @0x15bbc8 add r0, pc, r0 —— r0 = 0x347a40 = "winphone_tile_icon_image" */
/* @0x15bbcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_icon_image", 0x158eac <F_YoYo_WinPhone_SetTile_Iconic_IconImage>, 1, 0) */
/* ── #176 · 0x15bbd0..0x15bbe8 · winphone_tile_small_icon_image → F_YoYo_WinPhone_SetTile_Iconic_SmallIconImage (0x158f30) · argc=1 · flag=0 ── */
/* @0x15bbd0 ldr r1, [pc, #-0x600] —— 池字 0xffffe1c8：GOT 偏移 -0x1e38 → 槽 0x3efe20 = 0x158f30 <F_YoYo_WinPhone_SetTile_Iconic_SmallIconImage> */
/* @0x15bbd4 ldr r0, [pc, #-0x600] —— 池字 0x1ebe70：串偏移 → 0x347a5c "winphone_tile_small_icon_image" */
/* @0x15bbd8 mov r2, #1 —— argc = 1 */
/* @0x15bbdc mov r3, #0 —— flag = 0 */
/* @0x15bbe0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe20) = 0x158f30 <F_YoYo_WinPhone_SetTile_Iconic_SmallIconImage> */
/* @0x15bbe4 add r0, pc, r0 —— r0 = 0x347a5c = "winphone_tile_small_icon_image" */
/* @0x15bbe8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_small_icon_image", 0x158f30 <F_YoYo_WinPhone_SetTile_Iconic_SmallIconImage>, 1, 0) */
/* ── #177 · 0x15bbec..0x15bc04 · winphone_tile_wide_content → F_YoYo_WinPhone_SetTile_Iconic_WideContent (0x1562c4) · argc=2 · flag=0 ── */
/* @0x15bbec ldr r1, [pc, #-0x614] —— 池字 0xffffe1cc：GOT 偏移 -0x1e34 → 槽 0x3efe24 = 0x1562c4 <F_YoYo_WinPhone_SetTile_Iconic_WideContent> */
/* @0x15bbf0 ldr r0, [pc, #-0x614] —— 池字 0x1ebe74：串偏移 → 0x347a7c "winphone_tile_wide_content" */
/* @0x15bbf4 mov r2, #2 —— argc = 2 */
/* @0x15bbf8 mov r3, #0 —— flag = 0 */
/* @0x15bbfc ldr r1, [r10, r1] —— r1 = *(槽 0x3efe24) = 0x1562c4 <F_YoYo_WinPhone_SetTile_Iconic_WideContent> */
/* @0x15bc00 add r0, pc, r0 —— r0 = 0x347a7c = "winphone_tile_wide_content" */
/* @0x15bc04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_wide_content", 0x1562c4 <F_YoYo_WinPhone_SetTile_Iconic_WideContent>, 2, 0) */
/* ── #178 · 0x15bc08..0x15bc20 · winphone_tile_cycle_images → F_YoYo_WinPhone_SetTile_Cycle_CycleImages (0x158578) · argc=4294967295 · flag=0 ── */
/* @0x15bc08 ldr r1, [pc, #-0x628] —— 池字 0xffffe1d0：GOT 偏移 -0x1e30 → 槽 0x3efe28 = 0x158578 <F_YoYo_WinPhone_SetTile_Cycle_CycleImages> */
/* @0x15bc0c ldr r0, [pc, #-0x628] —— 池字 0x1ebe74：串偏移 → 0x347a98 "winphone_tile_cycle_images" */
/* @0x15bc10 mvn r2, #0 */
/* @0x15bc14 mov r3, #0 —— flag = 0 */
/* @0x15bc18 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe28) = 0x158578 <F_YoYo_WinPhone_SetTile_Cycle_CycleImages> */
/* @0x15bc1c add r0, pc, r0 —— r0 = 0x347a98 = "winphone_tile_cycle_images" */
/* @0x15bc20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_cycle_images", 0x158578 <F_YoYo_WinPhone_SetTile_Cycle_CycleImages>, 4294967295, 0) */
/* ── #179 · 0x15bc24..0x15bc3c · winphone_tile_small_background_image → F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImage (0x158fb4) · argc=1 · flag=0 ── */
/* @0x15bc24 ldr r1, [pc, #-0x63c] —— 池字 0xffffe1d4：GOT 偏移 -0x1e2c → 槽 0x3efe2c = 0x158fb4 <F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImage> */
/* @0x15bc28 ldr r0, [pc, #-0x63c] —— 池字 0x1ebe74：串偏移 → 0x347ab4 "winphone_tile_small_background_image" */
/* @0x15bc2c mov r2, #1 —— argc = 1 */
/* @0x15bc30 mov r3, #0 —— flag = 0 */
/* @0x15bc34 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe2c) = 0x158fb4 <F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImage> */
/* @0x15bc38 add r0, pc, r0 —— r0 = 0x347ab4 = "winphone_tile_small_background_image" */
/* @0x15bc3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("winphone_tile_small_background_image", 0x158fb4 <F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImage>, 1, 0) */
/* ── #180 · 0x15bc40..0x15bc58 · gml_release_mode → F_GMLReleaseMode (0x1586d4) · argc=1 · flag=1 ── */
/* @0x15bc40 ldr r1, [pc, #-0x650] —— 池字 0xffffe1d8：GOT 偏移 -0x1e28 → 槽 0x3efe30 = 0x1586d4 <F_GMLReleaseMode> */
/* @0x15bc44 ldr r0, [pc, #-0x650] —— 池字 0x1ebe80：串偏移 → 0x347adc "gml_release_mode" */
/* @0x15bc48 mov r2, #1 —— argc = 1 */
/* @0x15bc4c mov r3, r2 —— flag = 1 */
/* @0x15bc50 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe30) = 0x1586d4 <F_GMLReleaseMode> */
/* @0x15bc54 add r0, pc, r0 —— r0 = 0x347adc = "gml_release_mode" */
/* @0x15bc58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("gml_release_mode", 0x1586d4 <F_GMLReleaseMode>, 1, 1) */
/* ── #181 · 0x15bc5c..0x15bc74 · application_surface_draw_enable → F_GMLApplicationSurfaceDrawEnable (0x158370) · argc=1 · flag=1 ── */
/* @0x15bc5c ldr r1, [pc, #-0x664] —— 池字 0xffffe1dc：GOT 偏移 -0x1e24 → 槽 0x3efe34 = 0x158370 <F_GMLApplicationSurfaceDrawEnable> */
/* @0x15bc60 ldr r0, [pc, #-0x664] —— 池字 0x1ebe78：串偏移 → 0x347af0 "application_surface_draw_enable" */
/* @0x15bc64 mov r2, #1 —— argc = 1 */
/* @0x15bc68 mov r3, r2 —— flag = 1 */
/* @0x15bc6c ldr r1, [r10, r1] —— r1 = *(槽 0x3efe34) = 0x158370 <F_GMLApplicationSurfaceDrawEnable> */
/* @0x15bc70 add r0, pc, r0 —— r0 = 0x347af0 = "application_surface_draw_enable" */
/* @0x15bc74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("application_surface_draw_enable", 0x158370 <F_GMLApplicationSurfaceDrawEnable>, 1, 1) */
/* ── #182 · 0x15bc78..0x15bc90 · application_get_position → F_ApplicationGetPos (0x158980) · argc=0 · flag=0 ── */
/* @0x15bc78 ldr r1, [pc, #-0x678] —— 池字 0xffffe1e0：GOT 偏移 -0x1e20 → 槽 0x3efe38 = 0x158980 <F_ApplicationGetPos> */
/* @0x15bc7c ldr r0, [pc, #-0x678] —— 池字 0x1ebe7c：串偏移 → 0x347b10 "application_get_position" */
/* @0x15bc80 mov r2, #0 —— argc = 0 */
/* @0x15bc84 mov r3, r2 —— flag = 0 */
/* @0x15bc88 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe38) = 0x158980 <F_ApplicationGetPos> */
/* @0x15bc8c add r0, pc, r0 —— r0 = 0x347b10 = "application_get_position" */
/* @0x15bc90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("application_get_position", 0x158980 <F_ApplicationGetPos>, 0, 0) */
/* ── #183 · 0x15bc94..0x15bcac · application_surface_enable → F_AppSurfaceEnable (0x1583ac) · argc=1 · flag=1 ── */
/* @0x15bc94 ldr r1, [pc, #-0x68c] —— 池字 0xffffe1e4：GOT 偏移 -0x1e1c → 槽 0x3efe3c = 0x1583ac <F_AppSurfaceEnable> */
/* @0x15bc98 ldr r0, [pc, #-0x68c] —— 池字 0x1ebe7c：串偏移 → 0x347b2c "application_surface_enable" */
/* @0x15bc9c mov r2, #1 —— argc = 1 */
/* @0x15bca0 mov r3, r2 —— flag = 1 */
/* @0x15bca4 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe3c) = 0x1583ac <F_AppSurfaceEnable> */
/* @0x15bca8 add r0, pc, r0 —— r0 = 0x347b2c = "application_surface_enable" */
/* @0x15bcac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("application_surface_enable", 0x1583ac <F_AppSurfaceEnable>, 1, 1) */
/* ── #184 · 0x15bcb0..0x15bcc8 · application_surface_is_enabled → F_AppSurfaceIsEnabled (0x156304) · argc=0 · flag=1 ── */
/* @0x15bcb0 ldr r1, [pc, #-0x6a0] —— 池字 0xffffe1e8：GOT 偏移 -0x1e18 → 槽 0x3efe40 = 0x156304 <F_AppSurfaceIsEnabled> */
/* @0x15bcb4 ldr r0, [pc, #-0x6a0] —— 池字 0x1ebe7c：串偏移 → 0x347b48 "application_surface_is_enabled" */
/* @0x15bcb8 mov r2, #0 —— argc = 0 */
/* @0x15bcbc mov r3, #1 —— flag = 1 */
/* @0x15bcc0 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe40) = 0x156304 <F_AppSurfaceIsEnabled> */
/* @0x15bcc4 add r0, pc, r0 —— r0 = 0x347b48 = "application_surface_is_enabled" */
/* @0x15bcc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("application_surface_is_enabled", 0x156304 <F_AppSurfaceIsEnabled>, 0, 1) */
/* ── #185 · 0x15bccc..0x15bce4 · yyg_player_run → F_PlayerRun (0x158824) · argc=4 · flag=0 ── */
/* @0x15bccc ldr r1, [pc, #-0x6b4] —— 池字 0xffffe1ec：GOT 偏移 -0x1e14 → 槽 0x3efe44 = 0x158824 <F_PlayerRun> */
/* @0x15bcd0 ldr r0, [pc, #-0x6b4] —— 池字 0x1ebe80：串偏移 → 0x347b68 "yyg_player_run" */
/* @0x15bcd4 mov r2, #4 —— argc = 4 */
/* @0x15bcd8 mov r3, #0 —— flag = 0 */
/* @0x15bcdc ldr r1, [r10, r1] —— r1 = *(槽 0x3efe44) = 0x158824 <F_PlayerRun> */
/* @0x15bce0 add r0, pc, r0 —— r0 = 0x347b68 = "yyg_player_run" */
/* @0x15bce4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("yyg_player_run", 0x158824 <F_PlayerRun>, 4, 0) */
/* ── #186 · 0x15bce8..0x15bd00 · yyg_player_restarted → F_PlayerRestarted (0x156338) · argc=0 · flag=0 ── */
/* @0x15bce8 ldr r1, [pc, #-0x6c8] —— 池字 0xffffe1f0：GOT 偏移 -0x1e10 → 槽 0x3efe48 = 0x156338 <F_PlayerRestarted> */
/* @0x15bcec ldr r0, [pc, #-0x6c8] —— 池字 0x1ebe74：串偏移 → 0x347b78 "yyg_player_restarted" */
/* @0x15bcf0 mov r2, #0 —— argc = 0 */
/* @0x15bcf4 mov r3, r2 —— flag = 0 */
/* @0x15bcf8 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe48) = 0x156338 <F_PlayerRestarted> */
/* @0x15bcfc add r0, pc, r0 —— r0 = 0x347b78 = "yyg_player_restarted" */
/* @0x15bd00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("yyg_player_restarted", 0x156338 <F_PlayerRestarted>, 0, 0) */
/* ── #187 · 0x15bd04..0x15bd1c · yyg_player_launch_args → F_PlayerGetLaunchArgs (0x156bcc) · argc=0 · flag=0 ── */
/* @0x15bd04 ldr r1, [pc, #-0x6dc] —— 池字 0xffffe1f4：GOT 偏移 -0x1e0c → 槽 0x3efe4c = 0x156bcc <F_PlayerGetLaunchArgs> */
/* @0x15bd08 ldr r0, [pc, #-0x6dc] —— 池字 0x1ebe70：串偏移 → 0x347b90 "yyg_player_launch_args" */
/* @0x15bd0c mov r2, #0 —— argc = 0 */
/* @0x15bd10 mov r3, r2 —— flag = 0 */
/* @0x15bd14 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe4c) = 0x156bcc <F_PlayerGetLaunchArgs> */
/* @0x15bd18 add r0, pc, r0 —— r0 = 0x347b90 = "yyg_player_launch_args" */
/* @0x15bd1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("yyg_player_launch_args", 0x156bcc <F_PlayerGetLaunchArgs>, 0, 0) */
/* ── #188 · 0x15bd20..0x15bd38 · extension_stubfunc_real → F_ExtensionStubFuncReal (0x15636c) · argc=0 · flag=0 ── */
/* @0x15bd20 ldr r1, [pc, #-0x6f0] —— 池字 0xffffe1f8：GOT 偏移 -0x1e08 → 槽 0x3efe50 = 0x15636c <F_ExtensionStubFuncReal> */
/* @0x15bd24 ldr r0, [pc, #-0x6f0] —— 池字 0x1ebe6c：串偏移 → 0x347ba8 "extension_stubfunc_real" */
/* @0x15bd28 mov r2, #0 —— argc = 0 */
/* @0x15bd2c mov r3, r2 —— flag = 0 */
/* @0x15bd30 ldr r1, [r10, r1] —— r1 = *(槽 0x3efe50) = 0x15636c <F_ExtensionStubFuncReal> */
/* @0x15bd34 add r0, pc, r0 —— r0 = 0x347ba8 = "extension_stubfunc_real" */
/* @0x15bd38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("extension_stubfunc_real", 0x15636c <F_ExtensionStubFuncReal>, 0, 0) */
/* ── #189 · 0x15bd3c..0x15bd54 · extension_stubfunc_string → F_ExtensionStubFuncString (0x156be0) · argc=0 · flag=0 ── */
/* @0x15bd3c ldr r1, [pc, #-0x704] —— 池字 0xffffe1fc：GOT 偏移 -0x1e04 → 槽 0x3efe54 = 0x156be0 <F_ExtensionStubFuncString> */
/* @0x15bd40 ldr r0, [pc, #-0x704] —— 池字 0x1ebe68：串偏移 → 0x347bc0 "extension_stubfunc_string" */
/* @0x15bd44 mov r2, #0 —— argc = 0 */
/* @0x15bd48 mov r3, r2 —— flag = 0 */
/* @0x15bd4c ldr r1, [r10, r1] —— r1 = *(槽 0x3efe54) = 0x156be0 <F_ExtensionStubFuncString> */
/* @0x15bd50 add r0, pc, r0 —— r0 = 0x347bc0 = "extension_stubfunc_string" */
/* @0x15bd54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("extension_stubfunc_string", 0x156be0 <F_ExtensionStubFuncString>, 0, 0) */
/* ── #190 · 0x15bd58..0x15bd74 · ps4_share_screenshot_enable → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bd58 ldr r1, [pc, #-0x718] —— 池字 0xffffe200：GOT 偏移 -0x1e00 → 槽 0x3efe58 = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bd5c ldr r0, [pc, #-0x718] —— 池字 0x1ebe68：串偏移 → 0x347bdc "ps4_share_screenshot_enable" */
/* @0x15bd60 mov r2, #1 —— argc = 1 */
/* @0x15bd64 mov r3, r2 —— flag = 1 */
/* @0x15bd68 ldr r5, [r10, r1] —— r5 = *(槽 0x3efe58) = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bd6c add r0, pc, r0 —— r0 = 0x347bdc = "ps4_share_screenshot_enable" */
/* @0x15bd70 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bd74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ps4_share_screenshot_enable", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #191 · 0x15bd78..0x15bd8c · ps4_share_video_enable → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bd78 ldr r0, [pc, #-0x730] —— 池字 0x1ebe68：串偏移 → 0x347bf8 "ps4_share_video_enable" */
/* @0x15bd7c mov r2, #1 —— argc = 1 */
/* @0x15bd80 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bd84 mov r3, r2 —— flag = 1 */
/* @0x15bd88 add r0, pc, r0 —— r0 = 0x347bf8 = "ps4_share_video_enable" */
/* @0x15bd8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("ps4_share_video_enable", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #192 · 0x15bd90..0x15bda4 · xboxone_package_check_license → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bd90 ldr r0, [pc, #-0x744] —— 池字 0x1ebe68：串偏移 → 0x347c10 "xboxone_package_check_license" */
/* @0x15bd94 mov r2, #1 —— argc = 1 */
/* @0x15bd98 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bd9c mov r3, r2 —— flag = 1 */
/* @0x15bda0 add r0, pc, r0 —— r0 = 0x347c10 = "xboxone_package_check_license" */
/* @0x15bda4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_package_check_license", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #193 · 0x15bda8..0x15bdbc · xboxone_get_user_count → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15bda8 ldr r0, [pc, #-0x758] —— 池字 0x1ebe74：串偏移 → 0x347c30 "xboxone_get_user_count" */
/* @0x15bdac mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bdb0 mov r2, #0 —— argc = 0 */
/* @0x15bdb4 add r0, pc, r0 —— r0 = 0x347c30 = "xboxone_get_user_count" */
/* @0x15bdb8 mov r3, #1 —— flag = 1 */
/* @0x15bdbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_get_user_count", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #194 · 0x15bdc0..0x15bdd4 · xboxone_get_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bdc0 ldr r0, [pc, #-0x76c] —— 池字 0x1ebe70：串偏移 → 0x347c48 "xboxone_get_user" */
/* @0x15bdc4 mov r2, #1 —— argc = 1 */
/* @0x15bdc8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bdcc mov r3, r2 —— flag = 1 */
/* @0x15bdd0 add r0, pc, r0 —— r0 = 0x347c48 = "xboxone_get_user" */
/* @0x15bdd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_get_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #195 · 0x15bdd8..0x15bdec · xboxone_get_activating_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bdd8 ldr r0, [pc, #-0x780] —— 池字 0x1ebe6c：串偏移 → 0x347c5c "xboxone_get_activating_user" */
/* @0x15bddc mov r2, #1 —— argc = 1 */
/* @0x15bde0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bde4 mov r3, r2 —— flag = 1 */
/* @0x15bde8 add r0, pc, r0 —— r0 = 0x347c5c = "xboxone_get_activating_user" */
/* @0x15bdec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_get_activating_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #196 · 0x15bdf0..0x15be04 · xboxone_user_is_active → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bdf0 ldr r0, [pc, #-0x794] —— 池字 0x1ebe70：串偏移 → 0x347c78 "xboxone_user_is_active" */
/* @0x15bdf4 mov r2, #1 —— argc = 1 */
/* @0x15bdf8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bdfc mov r3, r2 —— flag = 1 */
/* @0x15be00 add r0, pc, r0 —— r0 = 0x347c78 = "xboxone_user_is_active" */
/* @0x15be04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_user_is_active", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #197 · 0x15be08..0x15be1c · xboxone_user_is_guest → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15be08 ldr r0, [pc, #-0x7a8] —— 池字 0x1ebe70：串偏移 → 0x347c90 "xboxone_user_is_guest" */
/* @0x15be0c mov r2, #1 —— argc = 1 */
/* @0x15be10 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15be14 mov r3, r2 —— flag = 1 */
/* @0x15be18 add r0, pc, r0 —— r0 = 0x347c90 = "xboxone_user_is_guest" */
/* @0x15be1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_user_is_guest", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #198 · 0x15be20..0x15be34 · xboxone_user_is_signed_in → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15be20 ldr r0, [pc, #-0x7bc] —— 池字 0x1ebe70：串偏移 → 0x347ca8 "xboxone_user_is_signed_in" */
/* @0x15be24 mov r2, #1 —— argc = 1 */
/* @0x15be28 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15be2c mov r3, r2 —— flag = 1 */
/* @0x15be30 add r0, pc, r0 —— r0 = 0x347ca8 = "xboxone_user_is_signed_in" */
/* @0x15be34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_user_is_signed_in", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #199 · 0x15be38..0x15be4c · xboxone_user_is_remote → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15be38 ldr r0, [pc, #-0x7d0] —— 池字 0x1ebe74：串偏移 → 0x347cc4 "xboxone_user_is_remote" */
/* @0x15be3c mov r2, #1 —— argc = 1 */
/* @0x15be40 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15be44 mov r3, r2 —— flag = 1 */
/* @0x15be48 add r0, pc, r0 —— r0 = 0x347cc4 = "xboxone_user_is_remote" */
/* @0x15be4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_user_is_remote", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #200 · 0x15be50..0x15be64 · xboxone_gamedisplayname_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15be50 ldr r0, [pc, #-0x7e4] —— 池字 0x1ebe74：串偏移 → 0x347cdc "xboxone_gamedisplayname_for_user" */
/* @0x15be54 mov r2, #1 —— argc = 1 */
/* @0x15be58 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15be5c mov r3, r2 —— flag = 1 */
/* @0x15be60 add r0, pc, r0 —— r0 = 0x347cdc = "xboxone_gamedisplayname_for_user" */
/* @0x15be64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_gamedisplayname_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #201 · 0x15be68..0x15be7c · xboxone_appdisplayname_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15be68 ldr r0, [pc, #-0x7f8] —— 池字 0x1ebe80：串偏移 → 0x347d00 "xboxone_appdisplayname_for_user" */
/* @0x15be6c mov r2, #1 —— argc = 1 */
/* @0x15be70 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15be74 mov r3, r2 —— flag = 1 */
/* @0x15be78 add r0, pc, r0 —— r0 = 0x347d00 = "xboxone_appdisplayname_for_user" */
/* @0x15be7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_appdisplayname_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #202 · 0x15be80..0x15be94 · xboxone_user_id_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15be80 ldr r0, [pc, #-0x80c] —— 池字 0x1ebe88：串偏移 → 0x347d20 "xboxone_user_id_for_user" */
/* @0x15be84 mov r2, #1 —— argc = 1 */
/* @0x15be88 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15be8c mov r3, r2 —— flag = 1 */
/* @0x15be90 add r0, pc, r0 —— r0 = 0x347d20 = "xboxone_user_id_for_user" */
/* @0x15be94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_user_id_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #203 · 0x15be98..0x15beac · xboxone_agegroup_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15be98 ldr r0, [pc, #-0x820] —— 池字 0x1ebe8c：串偏移 → 0x347d3c "xboxone_agegroup_for_user" */
/* @0x15be9c mov r2, #1 —— argc = 1 */
/* @0x15bea0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bea4 mov r3, r2 —— flag = 1 */
/* @0x15bea8 add r0, pc, r0 —— r0 = 0x347d3c = "xboxone_agegroup_for_user" */
/* @0x15beac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_agegroup_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #204 · 0x15beb0..0x15bec4 · xboxone_gamerscore_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15beb0 ldr r0, [pc, #-0x834] —— 池字 0x1ebe90：串偏移 → 0x347d58 "xboxone_gamerscore_for_user" */
/* @0x15beb4 mov r2, #1 —— argc = 1 */
/* @0x15beb8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bebc mov r3, r2 —— flag = 1 */
/* @0x15bec0 add r0, pc, r0 —— r0 = 0x347d58 = "xboxone_gamerscore_for_user" */
/* @0x15bec4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_gamerscore_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #205 · 0x15bec8..0x15bedc · xboxone_reputation_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bec8 ldr r0, [pc, #-0x848] —— 池字 0x1ebe94：串偏移 → 0x347d74 "xboxone_reputation_for_user" */
/* @0x15becc mov r2, #1 —— argc = 1 */
/* @0x15bed0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bed4 mov r3, r2 —— flag = 1 */
/* @0x15bed8 add r0, pc, r0 —— r0 = 0x347d74 = "xboxone_reputation_for_user" */
/* @0x15bedc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_reputation_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #206 · 0x15bee0..0x15bef4 · xboxone_user_for_pad → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bee0 ldr r0, [pc, #-0x85c] —— 池字 0x1ebe98：串偏移 → 0x347d90 "xboxone_user_for_pad" */
/* @0x15bee4 mov r2, #1 —— argc = 1 */
/* @0x15bee8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15beec mov r3, r2 —— flag = 1 */
/* @0x15bef0 add r0, pc, r0 —— r0 = 0x347d90 = "xboxone_user_for_pad" */
/* @0x15bef4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_user_for_pad", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #207 · 0x15bef8..0x15bf0c · xboxone_pad_count_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bef8 ldr r0, [pc, #-0x870] —— 池字 0x1ebe98：串偏移 → 0x347da8 "xboxone_pad_count_for_user" */
/* @0x15befc mov r2, #1 —— argc = 1 */
/* @0x15bf00 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bf04 mov r3, r2 —— flag = 1 */
/* @0x15bf08 add r0, pc, r0 —— r0 = 0x347da8 = "xboxone_pad_count_for_user" */
/* @0x15bf0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_pad_count_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #208 · 0x15bf10..0x15bf24 · xboxone_pad_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15bf10 ldr r0, [pc, #-0x884] —— 池字 0x1ebea0：串偏移 → 0x347dc4 "xboxone_pad_for_user" */
/* @0x15bf14 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bf18 mov r2, #2 —— argc = 2 */
/* @0x15bf1c add r0, pc, r0 —— r0 = 0x347dc4 = "xboxone_pad_for_user" */
/* @0x15bf20 mov r3, #1 —— flag = 1 */
/* @0x15bf24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_pad_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #209 · 0x15bf28..0x15bf3c · xboxone_sponsor_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15bf28 ldr r0, [pc, #-0x898] —— 池字 0x1ebea0：串偏移 → 0x347ddc "xboxone_sponsor_for_user" */
/* @0x15bf2c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bf30 mov r2, #2 —— argc = 2 */
/* @0x15bf34 add r0, pc, r0 —— r0 = 0x347ddc = "xboxone_sponsor_for_user" */
/* @0x15bf38 mov r3, #1 —— flag = 1 */
/* @0x15bf3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_sponsor_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #210 · 0x15bf40..0x15bf54 · xboxone_show_account_picker → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15bf40 ldr r0, [pc, #-0x8ac] —— 池字 0x1ebea4：串偏移 → 0x347df8 "xboxone_show_account_picker" */
/* @0x15bf44 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bf48 mov r2, #2 —— argc = 2 */
/* @0x15bf4c add r0, pc, r0 —— r0 = 0x347df8 = "xboxone_show_account_picker" */
/* @0x15bf50 mov r3, #1 —— flag = 1 */
/* @0x15bf54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_show_account_picker", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #211 · 0x15bf58..0x15bf6c · xboxone_sprite_add_from_gamerpicture → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15bf58 ldr r0, [pc, #-0x8c0] —— 池字 0x1ebea8：串偏移 → 0x347e14 "xboxone_sprite_add_from_gamerpicture" */
/* @0x15bf5c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bf60 mov r2, #4 —— argc = 4 */
/* @0x15bf64 add r0, pc, r0 —— r0 = 0x347e14 = "xboxone_sprite_add_from_gamerpicture" */
/* @0x15bf68 mov r3, #1 —— flag = 1 */
/* @0x15bf6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_sprite_add_from_gamerpicture", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #212 · 0x15bf70..0x15bf84 · xboxone_show_profile_card_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15bf70 ldr r0, [pc, #-0x8d4] —— 池字 0x1ebeb8：串偏移 → 0x347e3c "xboxone_show_profile_card_for_user" */
/* @0x15bf74 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bf78 mov r2, #2 —— argc = 2 */
/* @0x15bf7c add r0, pc, r0 —— r0 = 0x347e3c = "xboxone_show_profile_card_for_user" */
/* @0x15bf80 mov r3, #1 —— flag = 1 */
/* @0x15bf84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_show_profile_card_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #213 · 0x15bf88..0x15bf9c · xboxone_generate_player_session_id → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15bf88 ldr r0, [pc, #-0x8e8] —— 池字 0x1ebec4：串偏移 → 0x347e60 "xboxone_generate_player_session_id" */
/* @0x15bf8c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bf90 mov r2, #0 —— argc = 0 */
/* @0x15bf94 add r0, pc, r0 —— r0 = 0x347e60 = "xboxone_generate_player_session_id" */
/* @0x15bf98 mov r3, #1 —— flag = 1 */
/* @0x15bf9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_generate_player_session_id", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #214 · 0x15bfa0..0x15bfb4 · xboxone_set_savedata_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15bfa0 ldr r0, [pc, #-0x8fc] —— 池字 0x1ebecc：串偏移 → 0x347e84 "xboxone_set_savedata_user" */
/* @0x15bfa4 mov r2, #1 —— argc = 1 */
/* @0x15bfa8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bfac mov r3, r2 —— flag = 1 */
/* @0x15bfb0 add r0, pc, r0 —— r0 = 0x347e84 = "xboxone_set_savedata_user" */
/* @0x15bfb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_set_savedata_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #215 · 0x15bfb8..0x15bfcc · xboxone_get_savedata_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15bfb8 ldr r0, [pc, #-0x910] —— 池字 0x1ebed4：串偏移 → 0x347ea0 "xboxone_get_savedata_user" */
/* @0x15bfbc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bfc0 mov r2, #0 —— argc = 0 */
/* @0x15bfc4 add r0, pc, r0 —— r0 = 0x347ea0 = "xboxone_get_savedata_user" */
/* @0x15bfc8 mov r3, #1 —— flag = 1 */
/* @0x15bfcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_get_savedata_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #216 · 0x15bfd0..0x15bfe4 · xboxone_get_file_error → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15bfd0 ldr r0, [pc, #-0x924] —— 池字 0x1ebed8：串偏移 → 0x347ebc "xboxone_get_file_error" */
/* @0x15bfd4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bfd8 mov r2, #0 —— argc = 0 */
/* @0x15bfdc add r0, pc, r0 —— r0 = 0x347ebc = "xboxone_get_file_error" */
/* @0x15bfe0 mov r3, #1 —— flag = 1 */
/* @0x15bfe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_get_file_error", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #217 · 0x15bfe8..0x15bffc · xboxone_was_terminated → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15bfe8 ldr r0, [pc, #-0x938] —— 池字 0x1ebed8：串偏移 → 0x347ed4 "xboxone_was_terminated" */
/* @0x15bfec mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15bff0 mov r2, #0 —— argc = 0 */
/* @0x15bff4 add r0, pc, r0 —— r0 = 0x347ed4 = "xboxone_was_terminated" */
/* @0x15bff8 mov r3, #1 —— flag = 1 */
/* @0x15bffc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_was_terminated", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #218 · 0x15c000..0x15c014 · xboxone_is_suspending → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c000 ldr r0, [pc, #-0x94c] —— 池字 0x1ebed8：串偏移 → 0x347eec "xboxone_is_suspending" */
/* @0x15c004 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c008 mov r2, #0 —— argc = 0 */
/* @0x15c00c add r0, pc, r0 —— r0 = 0x347eec = "xboxone_is_suspending" */
/* @0x15c010 mov r3, #1 —— flag = 1 */
/* @0x15c014 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_is_suspending", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #219 · 0x15c018..0x15c02c · xboxone_is_constrained → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c018 ldr r0, [pc, #-0x960] —— 池字 0x1ebed8：串偏移 → 0x347f04 "xboxone_is_constrained" */
/* @0x15c01c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c020 mov r2, #0 —— argc = 0 */
/* @0x15c024 add r0, pc, r0 —— r0 = 0x347f04 = "xboxone_is_constrained" */
/* @0x15c028 mov r3, #1 —— flag = 1 */
/* @0x15c02c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_is_constrained", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #220 · 0x15c030..0x15c044 · xboxone_suspend → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c030 ldr r0, [pc, #-0x974] —— 池字 0x1ebed8：串偏移 → 0x347f1c "xboxone_suspend" */
/* @0x15c034 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c038 mov r2, #0 —— argc = 0 */
/* @0x15c03c add r0, pc, r0 —— r0 = 0x347f1c = "xboxone_suspend" */
/* @0x15c040 mov r3, #1 —— flag = 1 */
/* @0x15c044 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_suspend", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #221 · 0x15c048..0x15c05c · xboxone_show_help → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c048 ldr r0, [pc, #-0x988] —— 池字 0x1ebecc：串偏移 → 0x347f2c "xboxone_show_help" */
/* @0x15c04c mov r2, #1 —— argc = 1 */
/* @0x15c050 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c054 mov r3, r2 —— flag = 1 */
/* @0x15c058 add r0, pc, r0 —— r0 = 0x347f2c = "xboxone_show_help" */
/* @0x15c05c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_show_help", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #222 · 0x15c060..0x15c074 · xboxone_license_trial_version → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c060 ldr r0, [pc, #-0x99c] —— 池字 0x1ebecc：串偏移 → 0x347f40 "xboxone_license_trial_version" */
/* @0x15c064 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c068 mov r2, #0 —— argc = 0 */
/* @0x15c06c add r0, pc, r0 —— r0 = 0x347f40 = "xboxone_license_trial_version" */
/* @0x15c070 mov r3, #1 —— flag = 1 */
/* @0x15c074 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_license_trial_version", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #223 · 0x15c078..0x15c08c · xboxone_license_trial_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c078 ldr r0, [pc, #-0x9b0] —— 池字 0x1ebed4：串偏移 → 0x347f60 "xboxone_license_trial_user" */
/* @0x15c07c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c080 mov r2, #0 —— argc = 0 */
/* @0x15c084 add r0, pc, r0 —— r0 = 0x347f60 = "xboxone_license_trial_user" */
/* @0x15c088 mov r3, #1 —— flag = 1 */
/* @0x15c08c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_license_trial_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #224 · 0x15c090..0x15c0a4 · xboxone_license_trial_time_remaining → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c090 ldr r0, [pc, #-0x9c4] —— 池字 0x1ebed8：串偏移 → 0x347f7c "xboxone_license_trial_time_remaining" */
/* @0x15c094 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c098 mov r2, #0 —— argc = 0 */
/* @0x15c09c add r0, pc, r0 —— r0 = 0x347f7c = "xboxone_license_trial_time_remaining" */
/* @0x15c0a0 mov r3, #1 —— flag = 1 */
/* @0x15c0a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_license_trial_time_remaining", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #225 · 0x15c0a8..0x15c0bc · xboxone_check_privilege → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c0a8 ldr r0, [pc, #-0x9d8] —— 池字 0x1ebee8：串偏移 → 0x347fa4 "xboxone_check_privilege" */
/* @0x15c0ac mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c0b0 mov r2, #3 —— argc = 3 */
/* @0x15c0b4 add r0, pc, r0 —— r0 = 0x347fa4 = "xboxone_check_privilege" */
/* @0x15c0b8 mov r3, #1 —— flag = 1 */
/* @0x15c0bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_check_privilege", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #226 · 0x15c0c0..0x15c0d4 · xboxone_fire_event → F_Platform_Function_Not_Supported (0x1563a0) · argc=4294967295 · flag=1 ── */
/* @0x15c0c0 ldr r0, [pc, #-0x9ec] —— 池字 0x1ebee8：串偏移 → 0x347fbc "xboxone_fire_event" */
/* @0x15c0c4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c0c8 mvn r2, #0 */
/* @0x15c0cc add r0, pc, r0 —— r0 = 0x347fbc = "xboxone_fire_event" */
/* @0x15c0d0 mov r3, #1 —— flag = 1 */
/* @0x15c0d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_fire_event", 0x1563a0 <F_Platform_Function_Not_Supported>, 4294967295, 1) */
/* ── #227 · 0x15c0d8..0x15c0ec · xboxone_get_stats_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=4294967295 · flag=1 ── */
/* @0x15c0d8 ldr r0, [pc, #-0xa00] —— 池字 0x1ebee4：串偏移 → 0x347fd0 "xboxone_get_stats_for_user" */
/* @0x15c0dc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c0e0 mvn r2, #0 */
/* @0x15c0e4 add r0, pc, r0 —— r0 = 0x347fd0 = "xboxone_get_stats_for_user" */
/* @0x15c0e8 mov r3, #1 —— flag = 1 */
/* @0x15c0ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_get_stats_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 4294967295, 1) */
/* ── #228 · 0x15c0f0..0x15c104 · xboxone_stats_setup → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c0f0 ldr r0, [pc, #-0xa14] —— 池字 0x1ebee8：串偏移 → 0x347fec "xboxone_stats_setup" */
/* @0x15c0f4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c0f8 mov r2, #2 —— argc = 2 */
/* @0x15c0fc add r0, pc, r0 —— r0 = 0x347fec = "xboxone_stats_setup" */
/* @0x15c100 mov r3, #1 —— flag = 1 */
/* @0x15c104 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_setup", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #229 · 0x15c108..0x15c11c · xboxone_stats_set_stat_real → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c108 ldr r0, [pc, #-0xa28] —— 池字 0x1ebee4：串偏移 → 0x348000 "xboxone_stats_set_stat_real" */
/* @0x15c10c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c110 mov r2, #3 —— argc = 3 */
/* @0x15c114 add r0, pc, r0 —— r0 = 0x348000 = "xboxone_stats_set_stat_real" */
/* @0x15c118 mov r3, #1 —— flag = 1 */
/* @0x15c11c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_set_stat_real", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #230 · 0x15c120..0x15c134 · xboxone_stats_set_stat_int → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c120 ldr r0, [pc, #-0xa3c] —— 池字 0x1ebee8：串偏移 → 0x34801c "xboxone_stats_set_stat_int" */
/* @0x15c124 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c128 mov r2, #3 —— argc = 3 */
/* @0x15c12c add r0, pc, r0 —— r0 = 0x34801c = "xboxone_stats_set_stat_int" */
/* @0x15c130 mov r3, #1 —— flag = 1 */
/* @0x15c134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_set_stat_int", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #231 · 0x15c138..0x15c14c · xboxone_stats_set_stat_string → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c138 ldr r0, [pc, #-0xa50] —— 池字 0x1ebeec：串偏移 → 0x348038 "xboxone_stats_set_stat_string" */
/* @0x15c13c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c140 mov r2, #3 —— argc = 3 */
/* @0x15c144 add r0, pc, r0 —— r0 = 0x348038 = "xboxone_stats_set_stat_string" */
/* @0x15c148 mov r3, #1 —— flag = 1 */
/* @0x15c14c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_set_stat_string", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #232 · 0x15c150..0x15c164 · xboxone_stats_delete_stat → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c150 ldr r0, [pc, #-0xa64] —— 池字 0x1ebef4：串偏移 → 0x348058 "xboxone_stats_delete_stat" */
/* @0x15c154 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c158 mov r2, #2 —— argc = 2 */
/* @0x15c15c add r0, pc, r0 —— r0 = 0x348058 = "xboxone_stats_delete_stat" */
/* @0x15c160 mov r3, #1 —— flag = 1 */
/* @0x15c164 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_delete_stat", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #233 · 0x15c168..0x15c17c · xboxone_stats_get_stat → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c168 ldr r0, [pc, #-0xa78] —— 池字 0x1ebef8：串偏移 → 0x348074 "xboxone_stats_get_stat" */
/* @0x15c16c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c170 mov r2, #2 —— argc = 2 */
/* @0x15c174 add r0, pc, r0 —— r0 = 0x348074 = "xboxone_stats_get_stat" */
/* @0x15c178 mov r3, #1 —— flag = 1 */
/* @0x15c17c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_get_stat", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #234 · 0x15c180..0x15c194 · xboxone_stats_get_stat_names → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c180 ldr r0, [pc, #-0xa8c] —— 池字 0x1ebef4：串偏移 → 0x34808c "xboxone_stats_get_stat_names" */
/* @0x15c184 mov r2, #1 —— argc = 1 */
/* @0x15c188 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c18c mov r3, r2 —— flag = 1 */
/* @0x15c190 add r0, pc, r0 —— r0 = 0x34808c = "xboxone_stats_get_stat_names" */
/* @0x15c194 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_get_stat_names", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #235 · 0x15c198..0x15c1ac · xboxone_stats_add_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c198 ldr r0, [pc, #-0xaa0] —— 池字 0x1ebefc：串偏移 → 0x3480ac "xboxone_stats_add_user" */
/* @0x15c19c mov r2, #1 —— argc = 1 */
/* @0x15c1a0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c1a4 mov r3, r2 —— flag = 1 */
/* @0x15c1a8 add r0, pc, r0 —— r0 = 0x3480ac = "xboxone_stats_add_user" */
/* @0x15c1ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_add_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #236 · 0x15c1b0..0x15c1c4 · xboxone_stats_remove_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c1b0 ldr r0, [pc, #-0xab4] —— 池字 0x1ebefc：串偏移 → 0x3480c4 "xboxone_stats_remove_user" */
/* @0x15c1b4 mov r2, #1 —— argc = 1 */
/* @0x15c1b8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c1bc mov r3, r2 —— flag = 1 */
/* @0x15c1c0 add r0, pc, r0 —— r0 = 0x3480c4 = "xboxone_stats_remove_user" */
/* @0x15c1c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_remove_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #237 · 0x15c1c8..0x15c1dc · xboxone_stats_flush_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c1c8 ldr r0, [pc, #-0xac8] —— 池字 0x1ebf04：串偏移 → 0x3480e0 "xboxone_stats_flush_user" */
/* @0x15c1cc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c1d0 mov r2, #2 —— argc = 2 */
/* @0x15c1d4 add r0, pc, r0 —— r0 = 0x3480e0 = "xboxone_stats_flush_user" */
/* @0x15c1d8 mov r3, #1 —— flag = 1 */
/* @0x15c1dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_flush_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #238 · 0x15c1e0..0x15c1f4 · xboxone_stats_get_leaderboard → F_Platform_Function_Not_Supported (0x1563a0) · argc=6 · flag=1 ── */
/* @0x15c1e0 ldr r0, [pc, #-0xadc] —— 池字 0x1ebf08：串偏移 → 0x3480fc "xboxone_stats_get_leaderboard" */
/* @0x15c1e4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c1e8 mov r2, #6 —— argc = 6 */
/* @0x15c1ec add r0, pc, r0 —— r0 = 0x3480fc = "xboxone_stats_get_leaderboard" */
/* @0x15c1f0 mov r3, #1 —— flag = 1 */
/* @0x15c1f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_get_leaderboard", 0x1563a0 <F_Platform_Function_Not_Supported>, 6, 1) */
/* ── #239 · 0x15c1f8..0x15c20c · xboxone_stats_get_social_leaderboard → F_Platform_Function_Not_Supported (0x1563a0) · argc=7 · flag=1 ── */
/* @0x15c1f8 ldr r0, [pc, #-0xaf0] —— 池字 0x1ebf10：串偏移 → 0x34811c "xboxone_stats_get_social_leaderboard" */
/* @0x15c1fc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c200 mov r2, #7 —— argc = 7 */
/* @0x15c204 add r0, pc, r0 —— r0 = 0x34811c = "xboxone_stats_get_social_leaderboard" */
/* @0x15c208 mov r3, #1 —— flag = 1 */
/* @0x15c20c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_stats_get_social_leaderboard", 0x1563a0 <F_Platform_Function_Not_Supported>, 7, 1) */
/* ── #240 · 0x15c210..0x15c224 · xboxone_achievements_set_progress → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c210 ldr r0, [pc, #-0xb04] —— 池字 0x1ebf20：串偏移 → 0x348144 "xboxone_achievements_set_progress" */
/* @0x15c214 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c218 mov r2, #3 —— argc = 3 */
/* @0x15c21c add r0, pc, r0 —— r0 = 0x348144 = "xboxone_achievements_set_progress" */
/* @0x15c220 mov r3, #1 —— flag = 1 */
/* @0x15c224 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_achievements_set_progress", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #241 · 0x15c228..0x15c23c · xboxone_set_rich_presence → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c228 ldr r0, [pc, #-0xb18] —— 池字 0x1ebf2c：串偏移 → 0x348168 "xboxone_set_rich_presence" */
/* @0x15c22c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c230 mov r2, #3 —— argc = 3 */
/* @0x15c234 add r0, pc, r0 —— r0 = 0x348168 = "xboxone_set_rich_presence" */
/* @0x15c238 mov r3, #1 —— flag = 1 */
/* @0x15c23c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_set_rich_presence", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #242 · 0x15c240..0x15c254 · xboxone_matchmaking_create → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15c240 ldr r0, [pc, #-0xb2c] —— 池字 0x1ebf30：串偏移 → 0x348184 "xboxone_matchmaking_create" */
/* @0x15c244 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c248 mov r2, #4 —— argc = 4 */
/* @0x15c24c add r0, pc, r0 —— r0 = 0x348184 = "xboxone_matchmaking_create" */
/* @0x15c250 mov r3, #1 —— flag = 1 */
/* @0x15c254 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_create", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #243 · 0x15c258..0x15c26c · xboxone_matchmaking_find → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c258 ldr r0, [pc, #-0xb40] —— 池字 0x1ebf34：串偏移 → 0x3481a0 "xboxone_matchmaking_find" */
/* @0x15c25c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c260 mov r2, #3 —— argc = 3 */
/* @0x15c264 add r0, pc, r0 —— r0 = 0x3481a0 = "xboxone_matchmaking_find" */
/* @0x15c268 mov r3, #1 —— flag = 1 */
/* @0x15c26c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_find", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #244 · 0x15c270..0x15c284 · xboxone_matchmaking_start → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c270 ldr r0, [pc, #-0xb54] —— 池字 0x1ebf34：串偏移 → 0x3481bc "xboxone_matchmaking_start" */
/* @0x15c274 mov r2, #1 —— argc = 1 */
/* @0x15c278 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c27c mov r3, r2 —— flag = 1 */
/* @0x15c280 add r0, pc, r0 —— r0 = 0x3481bc = "xboxone_matchmaking_start" */
/* @0x15c284 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_start", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #245 · 0x15c288..0x15c29c · xboxone_matchmaking_stop → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c288 ldr r0, [pc, #-0xb68] —— 池字 0x1ebf38：串偏移 → 0x3481d8 "xboxone_matchmaking_stop" */
/* @0x15c28c mov r2, #1 —— argc = 1 */
/* @0x15c290 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c294 mov r3, r2 —— flag = 1 */
/* @0x15c298 add r0, pc, r0 —— r0 = 0x3481d8 = "xboxone_matchmaking_stop" */
/* @0x15c29c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_stop", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #246 · 0x15c2a0..0x15c2b4 · xboxone_matchmaking_session_get_users → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c2a0 ldr r0, [pc, #-0xb7c] —— 池字 0x1ebf3c：串偏移 → 0x3481f4 "xboxone_matchmaking_session_get_users" */
/* @0x15c2a4 mov r2, #1 —— argc = 1 */
/* @0x15c2a8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c2ac mov r3, r2 —— flag = 1 */
/* @0x15c2b0 add r0, pc, r0 —— r0 = 0x3481f4 = "xboxone_matchmaking_session_get_users" */
/* @0x15c2b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_session_get_users", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #247 · 0x15c2b8..0x15c2cc · xboxone_matchmaking_session_leave → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c2b8 ldr r0, [pc, #-0xb90] —— 池字 0x1ebf4c：串偏移 → 0x34821c "xboxone_matchmaking_session_leave" */
/* @0x15c2bc mov r2, #1 —— argc = 1 */
/* @0x15c2c0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c2c4 mov r3, r2 —— flag = 1 */
/* @0x15c2c8 add r0, pc, r0 —— r0 = 0x34821c = "xboxone_matchmaking_session_leave" */
/* @0x15c2cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_session_leave", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #248 · 0x15c2d0..0x15c2e4 · xboxone_matchmaking_send_invites → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c2d0 ldr r0, [pc, #-0xba4] —— 池字 0x1ebf5c：串偏移 → 0x348240 "xboxone_matchmaking_send_invites" */
/* @0x15c2d4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c2d8 mov r2, #3 —— argc = 3 */
/* @0x15c2dc add r0, pc, r0 —— r0 = 0x348240 = "xboxone_matchmaking_send_invites" */
/* @0x15c2e0 mov r3, #1 —— flag = 1 */
/* @0x15c2e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_send_invites", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #249 · 0x15c2e8..0x15c2fc · xboxone_matchmaking_set_joinable_session → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c2e8 ldr r0, [pc, #-0xbb8] —— 池字 0x1ebf68：串偏移 → 0x348264 "xboxone_matchmaking_set_joinable_session" */
/* @0x15c2ec mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c2f0 mov r2, #2 —— argc = 2 */
/* @0x15c2f4 add r0, pc, r0 —— r0 = 0x348264 = "xboxone_matchmaking_set_joinable_session" */
/* @0x15c2f8 mov r3, #1 —— flag = 1 */
/* @0x15c2fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_set_joinable_session", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #250 · 0x15c300..0x15c314 · xboxone_matchmaking_join_invite → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15c300 ldr r0, [pc, #-0xbcc] —— 池字 0x1ebf7c：串偏移 → 0x348290 "xboxone_matchmaking_join_invite" */
/* @0x15c304 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c308 mov r2, #4 —— argc = 4 */
/* @0x15c30c add r0, pc, r0 —— r0 = 0x348290 = "xboxone_matchmaking_join_invite" */
/* @0x15c310 mov r3, #1 —— flag = 1 */
/* @0x15c314 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_join_invite", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #251 · 0x15c318..0x15c32c · xboxone_matchmaking_join_session → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c318 ldr r0, [pc, #-0xbe0] —— 池字 0x1ebf84：串偏移 → 0x3482b0 "xboxone_matchmaking_join_session" */
/* @0x15c31c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c320 mov r2, #3 —— argc = 3 */
/* @0x15c324 add r0, pc, r0 —— r0 = 0x3482b0 = "xboxone_matchmaking_join_session" */
/* @0x15c328 mov r3, #1 —— flag = 1 */
/* @0x15c32c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_matchmaking_join_session", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #252 · 0x15c330..0x15c344 · xboxone_chat_add_user_to_channel → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c330 ldr r0, [pc, #-0xbf4] —— 池字 0x1ebf90：串偏移 → 0x3482d4 "xboxone_chat_add_user_to_channel" */
/* @0x15c334 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c338 mov r2, #2 —— argc = 2 */
/* @0x15c33c add r0, pc, r0 —— r0 = 0x3482d4 = "xboxone_chat_add_user_to_channel" */
/* @0x15c340 mov r3, #1 —— flag = 1 */
/* @0x15c344 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_chat_add_user_to_channel", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #253 · 0x15c348..0x15c35c · xboxone_chat_remove_user_from_channel → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c348 ldr r0, [pc, #-0xc08] —— 池字 0x1ebf9c：串偏移 → 0x3482f8 "xboxone_chat_remove_user_from_channel" */
/* @0x15c34c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c350 mov r2, #2 —— argc = 2 */
/* @0x15c354 add r0, pc, r0 —— r0 = 0x3482f8 = "xboxone_chat_remove_user_from_channel" */
/* @0x15c358 mov r3, #1 —— flag = 1 */
/* @0x15c35c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_chat_remove_user_from_channel", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #254 · 0x15c360..0x15c374 · xboxone_chat_set_muted → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c360 ldr r0, [pc, #-0xc1c] —— 池字 0x1ebfa8：串偏移 → 0x348320 "xboxone_chat_set_muted" */
/* @0x15c364 mov r2, #1 —— argc = 1 */
/* @0x15c368 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c36c mov r3, r2 —— flag = 1 */
/* @0x15c370 add r0, pc, r0 —— r0 = 0x348320 = "xboxone_chat_set_muted" */
/* @0x15c374 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_chat_set_muted", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #255 · 0x15c378..0x15c38c · xboxone_set_service_configuration_id → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c378 ldr r0, [pc, #-0xc30] —— 池字 0x1ebfa8：串偏移 → 0x348338 "xboxone_set_service_configuration_id" */
/* @0x15c37c mov r2, #1 —— argc = 1 */
/* @0x15c380 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c384 mov r3, r2 —— flag = 1 */
/* @0x15c388 add r0, pc, r0 —— r0 = 0x348338 = "xboxone_set_service_configuration_id" */
/* @0x15c38c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_set_service_configuration_id", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #256 · 0x15c390..0x15c3a4 · xboxone_read_player_leaderboard → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15c390 ldr r0, [pc, #-0xc44] —— 池字 0x1ebfbc：串偏移 → 0x348360 "xboxone_read_player_leaderboard" */
/* @0x15c394 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c398 mov r2, #4 —— argc = 4 */
/* @0x15c39c add r0, pc, r0 —— r0 = 0x348360 = "xboxone_read_player_leaderboard" */
/* @0x15c3a0 mov r3, #1 —— flag = 1 */
/* @0x15c3a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxone_read_player_leaderboard", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #257 · 0x15c3a8..0x15c3bc · xboxlive_get_user_count → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c3a8 ldr r0, [pc, #-0xc58] —— 池字 0x1ebfc4：串偏移 → 0x348380 "xboxlive_get_user_count" */
/* @0x15c3ac mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c3b0 mov r2, #0 —— argc = 0 */
/* @0x15c3b4 add r0, pc, r0 —— r0 = 0x348380 = "xboxlive_get_user_count" */
/* @0x15c3b8 mov r3, #1 —— flag = 1 */
/* @0x15c3bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_get_user_count", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #258 · 0x15c3c0..0x15c3d4 · xboxlive_get_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c3c0 ldr r0, [pc, #-0xc6c] —— 池字 0x1ebfc0：串偏移 → 0x348398 "xboxlive_get_user" */
/* @0x15c3c4 mov r2, #1 —— argc = 1 */
/* @0x15c3c8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c3cc mov r3, r2 —— flag = 1 */
/* @0x15c3d0 add r0, pc, r0 —— r0 = 0x348398 = "xboxlive_get_user" */
/* @0x15c3d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_get_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #259 · 0x15c3d8..0x15c3ec · xboxlive_get_activating_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c3d8 ldr r0, [pc, #-0xc80] —— 池字 0x1ebfbc：串偏移 → 0x3483ac "xboxlive_get_activating_user" */
/* @0x15c3dc mov r2, #1 —— argc = 1 */
/* @0x15c3e0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c3e4 mov r3, r2 —— flag = 1 */
/* @0x15c3e8 add r0, pc, r0 —— r0 = 0x3483ac = "xboxlive_get_activating_user" */
/* @0x15c3ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_get_activating_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #260 · 0x15c3f0..0x15c404 · xboxlive_user_is_active → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c3f0 ldr r0, [pc, #-0xc94] —— 池字 0x1ebfc4：串偏移 → 0x3483cc "xboxlive_user_is_active" */
/* @0x15c3f4 mov r2, #1 —— argc = 1 */
/* @0x15c3f8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c3fc mov r3, r2 —— flag = 1 */
/* @0x15c400 add r0, pc, r0 —— r0 = 0x3483cc = "xboxlive_user_is_active" */
/* @0x15c404 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_user_is_active", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #261 · 0x15c408..0x15c41c · xboxlive_user_is_guest → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c408 ldr r0, [pc, #-0xca8] —— 池字 0x1ebfc4：串偏移 → 0x3483e4 "xboxlive_user_is_guest" */
/* @0x15c40c mov r2, #1 —— argc = 1 */
/* @0x15c410 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c414 mov r3, r2 —— flag = 1 */
/* @0x15c418 add r0, pc, r0 —— r0 = 0x3483e4 = "xboxlive_user_is_guest" */
/* @0x15c41c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_user_is_guest", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #262 · 0x15c420..0x15c434 · xboxlive_user_is_signed_in → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c420 ldr r0, [pc, #-0xcbc] —— 池字 0x1ebfc4：串偏移 → 0x3483fc "xboxlive_user_is_signed_in" */
/* @0x15c424 mov r2, #1 —— argc = 1 */
/* @0x15c428 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c42c mov r3, r2 —— flag = 1 */
/* @0x15c430 add r0, pc, r0 —— r0 = 0x3483fc = "xboxlive_user_is_signed_in" */
/* @0x15c434 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_user_is_signed_in", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #263 · 0x15c438..0x15c44c · xboxlive_user_is_signing_in → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c438 ldr r0, [pc, #-0xcd0] —— 池字 0x1ebfc8：串偏移 → 0x348418 "xboxlive_user_is_signing_in" */
/* @0x15c43c mov r2, #1 —— argc = 1 */
/* @0x15c440 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c444 mov r3, r2 —— flag = 1 */
/* @0x15c448 add r0, pc, r0 —— r0 = 0x348418 = "xboxlive_user_is_signing_in" */
/* @0x15c44c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_user_is_signing_in", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #264 · 0x15c450..0x15c464 · xboxlive_user_is_remote → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c450 ldr r0, [pc, #-0xce4] —— 池字 0x1ebfcc：串偏移 → 0x348434 "xboxlive_user_is_remote" */
/* @0x15c454 mov r2, #1 —— argc = 1 */
/* @0x15c458 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c45c mov r3, r2 —— flag = 1 */
/* @0x15c460 add r0, pc, r0 —— r0 = 0x348434 = "xboxlive_user_is_remote" */
/* @0x15c464 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_user_is_remote", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #265 · 0x15c468..0x15c47c · xboxlive_gamedisplayname_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c468 ldr r0, [pc, #-0xcf8] —— 池字 0x1ebfcc：串偏移 → 0x34844c "xboxlive_gamedisplayname_for_user" */
/* @0x15c46c mov r2, #1 —— argc = 1 */
/* @0x15c470 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c474 mov r3, r2 —— flag = 1 */
/* @0x15c478 add r0, pc, r0 —— r0 = 0x34844c = "xboxlive_gamedisplayname_for_user" */
/* @0x15c47c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_gamedisplayname_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #266 · 0x15c480..0x15c494 · xboxlive_appdisplayname_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c480 ldr r0, [pc, #-0xd0c] —— 池字 0x1ebfd8：串偏移 → 0x348470 "xboxlive_appdisplayname_for_user" */
/* @0x15c484 mov r2, #1 —— argc = 1 */
/* @0x15c488 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c48c mov r3, r2 —— flag = 1 */
/* @0x15c490 add r0, pc, r0 —— r0 = 0x348470 = "xboxlive_appdisplayname_for_user" */
/* @0x15c494 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_appdisplayname_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #267 · 0x15c498..0x15c4ac · xboxlive_gamertag_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=4294967295 · flag=1 ── */
/* @0x15c498 ldr r0, [pc, #-0xd20] —— 池字 0x1ebfe8：串偏移 → 0x348494 "xboxlive_gamertag_for_user" */
/* @0x15c49c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c4a0 mvn r2, #0 */
/* @0x15c4a4 add r0, pc, r0 —— r0 = 0x348494 = "xboxlive_gamertag_for_user" */
/* @0x15c4a8 mov r3, #1 —— flag = 1 */
/* @0x15c4ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_gamertag_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 4294967295, 1) */
/* ── #268 · 0x15c4b0..0x15c4c4 · xboxlive_user_id_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c4b0 ldr r0, [pc, #-0xd34] —— 池字 0x1ebfe8：串偏移 → 0x3484b0 "xboxlive_user_id_for_user" */
/* @0x15c4b4 mov r2, #1 —— argc = 1 */
/* @0x15c4b8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c4bc mov r3, r2 —— flag = 1 */
/* @0x15c4c0 add r0, pc, r0 —— r0 = 0x3484b0 = "xboxlive_user_id_for_user" */
/* @0x15c4c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_user_id_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #269 · 0x15c4c8..0x15c4dc · xboxlive_agegroup_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c4c8 ldr r0, [pc, #-0xd48] —— 池字 0x1ebfec：串偏移 → 0x3484cc "xboxlive_agegroup_for_user" */
/* @0x15c4cc mov r2, #1 —— argc = 1 */
/* @0x15c4d0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c4d4 mov r3, r2 —— flag = 1 */
/* @0x15c4d8 add r0, pc, r0 —— r0 = 0x3484cc = "xboxlive_agegroup_for_user" */
/* @0x15c4dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_agegroup_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #270 · 0x15c4e0..0x15c4f4 · xboxlive_gamerscore_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c4e0 ldr r0, [pc, #-0xd5c] —— 池字 0x1ebff0：串偏移 → 0x3484e8 "xboxlive_gamerscore_for_user" */
/* @0x15c4e4 mov r2, #1 —— argc = 1 */
/* @0x15c4e8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c4ec mov r3, r2 —— flag = 1 */
/* @0x15c4f0 add r0, pc, r0 —— r0 = 0x3484e8 = "xboxlive_gamerscore_for_user" */
/* @0x15c4f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_gamerscore_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #271 · 0x15c4f8..0x15c50c · xboxlive_reputation_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c4f8 ldr r0, [pc, #-0xd70] —— 池字 0x1ebff8：串偏移 → 0x348508 "xboxlive_reputation_for_user" */
/* @0x15c4fc mov r2, #1 —— argc = 1 */
/* @0x15c500 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c504 mov r3, r2 —— flag = 1 */
/* @0x15c508 add r0, pc, r0 —— r0 = 0x348508 = "xboxlive_reputation_for_user" */
/* @0x15c50c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_reputation_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #272 · 0x15c510..0x15c524 · xboxlive_user_for_pad → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c510 ldr r0, [pc, #-0xd84] —— 池字 0x1ec000：串偏移 → 0x348528 "xboxlive_user_for_pad" */
/* @0x15c514 mov r2, #1 —— argc = 1 */
/* @0x15c518 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c51c mov r3, r2 —— flag = 1 */
/* @0x15c520 add r0, pc, r0 —— r0 = 0x348528 = "xboxlive_user_for_pad" */
/* @0x15c524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_user_for_pad", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #273 · 0x15c528..0x15c53c · xboxlive_pad_count_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c528 ldr r0, [pc, #-0xd98] —— 池字 0x1ec000：串偏移 → 0x348540 "xboxlive_pad_count_for_user" */
/* @0x15c52c mov r2, #1 —— argc = 1 */
/* @0x15c530 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c534 mov r3, r2 —— flag = 1 */
/* @0x15c538 add r0, pc, r0 —— r0 = 0x348540 = "xboxlive_pad_count_for_user" */
/* @0x15c53c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_pad_count_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #274 · 0x15c540..0x15c554 · xboxlive_pad_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c540 ldr r0, [pc, #-0xdac] —— 池字 0x1ec008：串偏移 → 0x34855c "xboxlive_pad_for_user" */
/* @0x15c544 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c548 mov r2, #2 —— argc = 2 */
/* @0x15c54c add r0, pc, r0 —— r0 = 0x34855c = "xboxlive_pad_for_user" */
/* @0x15c550 mov r3, #1 —— flag = 1 */
/* @0x15c554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_pad_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #275 · 0x15c558..0x15c56c · xboxlive_sponsor_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c558 ldr r0, [pc, #-0xdc0] —— 池字 0x1ec008：串偏移 → 0x348574 "xboxlive_sponsor_for_user" */
/* @0x15c55c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c560 mov r2, #2 —— argc = 2 */
/* @0x15c564 add r0, pc, r0 —— r0 = 0x348574 = "xboxlive_sponsor_for_user" */
/* @0x15c568 mov r3, #1 —— flag = 1 */
/* @0x15c56c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_sponsor_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #276 · 0x15c570..0x15c584 · xboxlive_show_account_picker → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c570 ldr r0, [pc, #-0xdd4] —— 池字 0x1ec00c：串偏移 → 0x348590 "xboxlive_show_account_picker" */
/* @0x15c574 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c578 mov r2, #2 —— argc = 2 */
/* @0x15c57c add r0, pc, r0 —— r0 = 0x348590 = "xboxlive_show_account_picker" */
/* @0x15c580 mov r3, #1 —— flag = 1 */
/* @0x15c584 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_show_account_picker", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #277 · 0x15c588..0x15c59c · xboxlive_sprite_add_from_gamerpicture → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15c588 ldr r0, [pc, #-0xde8] —— 池字 0x1ec014：串偏移 → 0x3485b0 "xboxlive_sprite_add_from_gamerpicture" */
/* @0x15c58c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c590 mov r2, #4 —— argc = 4 */
/* @0x15c594 add r0, pc, r0 —— r0 = 0x3485b0 = "xboxlive_sprite_add_from_gamerpicture" */
/* @0x15c598 mov r3, #1 —— flag = 1 */
/* @0x15c59c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_sprite_add_from_gamerpicture", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #278 · 0x15c5a0..0x15c5b4 · xboxlive_show_profile_card_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c5a0 ldr r0, [pc, #-0xdfc] —— 池字 0x1ec024：串偏移 → 0x3485d8 "xboxlive_show_profile_card_for_user" */
/* @0x15c5a4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c5a8 mov r2, #2 —— argc = 2 */
/* @0x15c5ac add r0, pc, r0 —— r0 = 0x3485d8 = "xboxlive_show_profile_card_for_user" */
/* @0x15c5b0 mov r3, #1 —— flag = 1 */
/* @0x15c5b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_show_profile_card_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #279 · 0x15c5b8..0x15c5cc · xboxlive_generate_player_session_id → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c5b8 ldr r0, [pc, #-0xe10] —— 池字 0x1ec030：串偏移 → 0x3485fc "xboxlive_generate_player_session_id" */
/* @0x15c5bc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c5c0 mov r2, #0 —— argc = 0 */
/* @0x15c5c4 add r0, pc, r0 —— r0 = 0x3485fc = "xboxlive_generate_player_session_id" */
/* @0x15c5c8 mov r3, #1 —— flag = 1 */
/* @0x15c5cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_generate_player_session_id", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #280 · 0x15c5d0..0x15c5e4 · xboxlive_read_player_leaderboard → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15c5d0 ldr r0, [pc, #-0xe24] —— 池字 0x1ec03c：串偏移 → 0x348620 "xboxlive_read_player_leaderboard" */
/* @0x15c5d4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c5d8 mov r2, #4 —— argc = 4 */
/* @0x15c5dc add r0, pc, r0 —— r0 = 0x348620 = "xboxlive_read_player_leaderboard" */
/* @0x15c5e0 mov r3, #1 —— flag = 1 */
/* @0x15c5e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_read_player_leaderboard", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #281 · 0x15c5e8..0x15c5fc · xboxlive_set_savedata_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c5e8 ldr r0, [pc, #-0xe38] —— 池字 0x1ec044：串偏移 → 0x348644 "xboxlive_set_savedata_user" */
/* @0x15c5ec mov r2, #1 —— argc = 1 */
/* @0x15c5f0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c5f4 mov r3, r2 —— flag = 1 */
/* @0x15c5f8 add r0, pc, r0 —— r0 = 0x348644 = "xboxlive_set_savedata_user" */
/* @0x15c5fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_set_savedata_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #282 · 0x15c600..0x15c614 · xboxlive_get_savedata_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c600 ldr r0, [pc, #-0xe4c] —— 池字 0x1ec04c：串偏移 → 0x348660 "xboxlive_get_savedata_user" */
/* @0x15c604 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c608 mov r2, #0 —— argc = 0 */
/* @0x15c60c add r0, pc, r0 —— r0 = 0x348660 = "xboxlive_get_savedata_user" */
/* @0x15c610 mov r3, #1 —— flag = 1 */
/* @0x15c614 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_get_savedata_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #283 · 0x15c618..0x15c62c · xboxlive_get_file_error → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c618 ldr r0, [pc, #-0xe60] —— 池字 0x1ec050：串偏移 → 0x34867c "xboxlive_get_file_error" */
/* @0x15c61c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c620 mov r2, #0 —— argc = 0 */
/* @0x15c624 add r0, pc, r0 —— r0 = 0x34867c = "xboxlive_get_file_error" */
/* @0x15c628 mov r3, #1 —— flag = 1 */
/* @0x15c62c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_get_file_error", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #284 · 0x15c630..0x15c644 · uwp_was_terminated → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c630 ldr r0, [pc, #-0xe74] —— 池字 0x1ec050：串偏移 → 0x348694 "uwp_was_terminated" */
/* @0x15c634 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c638 mov r2, #0 —— argc = 0 */
/* @0x15c63c add r0, pc, r0 —— r0 = 0x348694 = "uwp_was_terminated" */
/* @0x15c640 mov r3, #1 —— flag = 1 */
/* @0x15c644 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_was_terminated", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #285 · 0x15c648..0x15c65c · uwp_is_suspending → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c648 ldr r0, [pc, #-0xe88] —— 池字 0x1ec04c：串偏移 → 0x3486a8 "uwp_is_suspending" */
/* @0x15c64c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c650 mov r2, #0 —— argc = 0 */
/* @0x15c654 add r0, pc, r0 —— r0 = 0x3486a8 = "uwp_is_suspending" */
/* @0x15c658 mov r3, #1 —— flag = 1 */
/* @0x15c65c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_is_suspending", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #286 · 0x15c660..0x15c674 · uwp_is_constrained → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c660 ldr r0, [pc, #-0xe9c] —— 池字 0x1ec048：串偏移 → 0x3486bc "uwp_is_constrained" */
/* @0x15c664 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c668 mov r2, #0 —— argc = 0 */
/* @0x15c66c add r0, pc, r0 —— r0 = 0x3486bc = "uwp_is_constrained" */
/* @0x15c670 mov r3, #1 —— flag = 1 */
/* @0x15c674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_is_constrained", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #287 · 0x15c678..0x15c68c · uwp_suspend → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c678 ldr r0, [pc, #-0xeb0] —— 池字 0x1ec044：串偏移 → 0x3486d0 "uwp_suspend" */
/* @0x15c67c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c680 mov r2, #0 —— argc = 0 */
/* @0x15c684 add r0, pc, r0 —— r0 = 0x3486d0 = "uwp_suspend" */
/* @0x15c688 mov r3, #1 —— flag = 1 */
/* @0x15c68c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_suspend", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #288 · 0x15c690..0x15c6a4 · uwp_show_help → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c690 ldr r0, [pc, #-0xec4] —— 池字 0x1ec034：串偏移 → 0x3486dc "uwp_show_help" */
/* @0x15c694 mov r2, #1 —— argc = 1 */
/* @0x15c698 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c69c mov r3, r2 —— flag = 1 */
/* @0x15c6a0 add r0, pc, r0 —— r0 = 0x3486dc = "uwp_show_help" */
/* @0x15c6a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_show_help", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #289 · 0x15c6a8..0x15c6bc · uwp_license_trial_version → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c6a8 ldr r0, [pc, #-0xed8] —— 池字 0x1ec030：串偏移 → 0x3486ec "uwp_license_trial_version" */
/* @0x15c6ac mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c6b0 mov r2, #0 —— argc = 0 */
/* @0x15c6b4 add r0, pc, r0 —— r0 = 0x3486ec = "uwp_license_trial_version" */
/* @0x15c6b8 mov r3, #1 —— flag = 1 */
/* @0x15c6bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_license_trial_version", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #290 · 0x15c6c0..0x15c6d4 · uwp_license_trial_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c6c0 ldr r0, [pc, #-0xeec] —— 池字 0x1ec034：串偏移 → 0x348708 "uwp_license_trial_user" */
/* @0x15c6c4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c6c8 mov r2, #0 —— argc = 0 */
/* @0x15c6cc add r0, pc, r0 —— r0 = 0x348708 = "uwp_license_trial_user" */
/* @0x15c6d0 mov r3, #1 —— flag = 1 */
/* @0x15c6d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_license_trial_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #291 · 0x15c6d8..0x15c6ec · uwp_license_trial_time_remaining → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c6d8 ldr r0, [pc, #-0xf00] —— 池字 0x1ec034：串偏移 → 0x348720 "uwp_license_trial_time_remaining" */
/* @0x15c6dc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c6e0 mov r2, #0 —— argc = 0 */
/* @0x15c6e4 add r0, pc, r0 —— r0 = 0x348720 = "uwp_license_trial_time_remaining" */
/* @0x15c6e8 mov r3, #1 —— flag = 1 */
/* @0x15c6ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_license_trial_time_remaining", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #292 · 0x15c6f0..0x15c704 · uwp_check_privilege → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c6f0 ldr r0, [pc, #-0xf14] —— 池字 0x1ec040：串偏移 → 0x348744 "uwp_check_privilege" */
/* @0x15c6f4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c6f8 mov r2, #3 —— argc = 3 */
/* @0x15c6fc add r0, pc, r0 —— r0 = 0x348744 = "uwp_check_privilege" */
/* @0x15c700 mov r3, #1 —— flag = 1 */
/* @0x15c704 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("uwp_check_privilege", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #293 · 0x15c708..0x15c71c · xboxlive_fire_event → F_Platform_Function_Not_Supported (0x1563a0) · argc=4294967295 · flag=1 ── */
/* @0x15c708 ldr r0, [pc, #-0xf28] —— 池字 0x1ec03c：串偏移 → 0x348758 "xboxlive_fire_event" */
/* @0x15c70c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c710 mvn r2, #0 */
/* @0x15c714 add r0, pc, r0 —— r0 = 0x348758 = "xboxlive_fire_event" */
/* @0x15c718 mov r3, #1 —— flag = 1 */
/* @0x15c71c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_fire_event", 0x1563a0 <F_Platform_Function_Not_Supported>, 4294967295, 1) */
/* ── #294 · 0x15c720..0x15c734 · xboxlive_get_stats_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=4294967295 · flag=1 ── */
/* @0x15c720 ldr r0, [pc, #-0xf3c] —— 池字 0x1ec038：串偏移 → 0x34876c "xboxlive_get_stats_for_user" */
/* @0x15c724 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c728 mvn r2, #0 */
/* @0x15c72c add r0, pc, r0 —— r0 = 0x34876c = "xboxlive_get_stats_for_user" */
/* @0x15c730 mov r3, #1 —— flag = 1 */
/* @0x15c734 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_get_stats_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 4294967295, 1) */
/* ── #295 · 0x15c738..0x15c74c · xboxlive_stats_setup → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c738 ldr r0, [pc, #-0xf50] —— 池字 0x1ec03c：串偏移 → 0x348788 "xboxlive_stats_setup" */
/* @0x15c73c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c740 mov r2, #2 —— argc = 2 */
/* @0x15c744 add r0, pc, r0 —— r0 = 0x348788 = "xboxlive_stats_setup" */
/* @0x15c748 mov r3, #1 —— flag = 1 */
/* @0x15c74c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_setup", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #296 · 0x15c750..0x15c764 · xboxlive_stats_set_stat_real → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c750 ldr r0, [pc, #-0xf64] —— 池字 0x1ec03c：串偏移 → 0x3487a0 "xboxlive_stats_set_stat_real" */
/* @0x15c754 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c758 mov r2, #3 —— argc = 3 */
/* @0x15c75c add r0, pc, r0 —— r0 = 0x3487a0 = "xboxlive_stats_set_stat_real" */
/* @0x15c760 mov r3, #1 —— flag = 1 */
/* @0x15c764 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_set_stat_real", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #297 · 0x15c768..0x15c77c · xboxlive_stats_set_stat_int → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c768 ldr r0, [pc, #-0xf78] —— 池字 0x1ec044：串偏移 → 0x3487c0 "xboxlive_stats_set_stat_int" */
/* @0x15c76c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c770 mov r2, #3 —— argc = 3 */
/* @0x15c774 add r0, pc, r0 —— r0 = 0x3487c0 = "xboxlive_stats_set_stat_int" */
/* @0x15c778 mov r3, #1 —— flag = 1 */
/* @0x15c77c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_set_stat_int", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #298 · 0x15c780..0x15c794 · xboxlive_stats_set_stat_string → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c780 ldr r0, [pc, #-0xf8c] —— 池字 0x1ec048：串偏移 → 0x3487dc "xboxlive_stats_set_stat_string" */
/* @0x15c784 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c788 mov r2, #3 —— argc = 3 */
/* @0x15c78c add r0, pc, r0 —— r0 = 0x3487dc = "xboxlive_stats_set_stat_string" */
/* @0x15c790 mov r3, #1 —— flag = 1 */
/* @0x15c794 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_set_stat_string", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #299 · 0x15c798..0x15c7ac · xboxlive_stats_delete_stat → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c798 ldr r0, [pc, #-0xfa0] —— 池字 0x1ec050：串偏移 → 0x3487fc "xboxlive_stats_delete_stat" */
/* @0x15c79c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c7a0 mov r2, #2 —— argc = 2 */
/* @0x15c7a4 add r0, pc, r0 —— r0 = 0x3487fc = "xboxlive_stats_delete_stat" */
/* @0x15c7a8 mov r3, #1 —— flag = 1 */
/* @0x15c7ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_delete_stat", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #300 · 0x15c7b0..0x15c7c4 · xboxlive_stats_get_stat → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c7b0 ldr r0, [pc, #-0xfb4] —— 池字 0x1ec054：串偏移 → 0x348818 "xboxlive_stats_get_stat" */
/* @0x15c7b4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c7b8 mov r2, #2 —— argc = 2 */
/* @0x15c7bc add r0, pc, r0 —— r0 = 0x348818 = "xboxlive_stats_get_stat" */
/* @0x15c7c0 mov r3, #1 —— flag = 1 */
/* @0x15c7c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_get_stat", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #301 · 0x15c7c8..0x15c7dc · xboxlive_stats_get_stat_names → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c7c8 ldr r0, [pc, #-0xfc8] —— 池字 0x1ec050：串偏移 → 0x348830 "xboxlive_stats_get_stat_names" */
/* @0x15c7cc mov r2, #1 —— argc = 1 */
/* @0x15c7d0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c7d4 mov r3, r2 —— flag = 1 */
/* @0x15c7d8 add r0, pc, r0 —— r0 = 0x348830 = "xboxlive_stats_get_stat_names" */
/* @0x15c7dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_get_stat_names", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #302 · 0x15c7e0..0x15c7f4 · xboxlive_stats_add_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c7e0 ldr r0, [pc, #-0xfdc] —— 池字 0x1ec058：串偏移 → 0x348850 "xboxlive_stats_add_user" */
/* @0x15c7e4 mov r2, #1 —— argc = 1 */
/* @0x15c7e8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c7ec mov r3, r2 —— flag = 1 */
/* @0x15c7f0 add r0, pc, r0 —— r0 = 0x348850 = "xboxlive_stats_add_user" */
/* @0x15c7f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_add_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #303 · 0x15c7f8..0x15c80c · xboxlive_stats_remove_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c7f8 ldr r0, [pc, #-0xff0] —— 池字 0x1ec058：串偏移 → 0x348868 "xboxlive_stats_remove_user" */
/* @0x15c7fc mov r2, #1 —— argc = 1 */
/* @0x15c800 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c804 mov r3, r2 —— flag = 1 */
/* @0x15c808 add r0, pc, r0 —— r0 = 0x348868 = "xboxlive_stats_remove_user" */
/* @0x15c80c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_remove_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #304 · 0x15c810..0x15c824 · xboxlive_stats_flush_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c810 ldr r0, [pc, #0x79c] —— 池字 0x1ec060：串偏移 → 0x348884 "xboxlive_stats_flush_user" */
/* @0x15c814 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c818 mov r2, #2 —— argc = 2 */
/* @0x15c81c add r0, pc, r0 —— r0 = 0x348884 = "xboxlive_stats_flush_user" */
/* @0x15c820 mov r3, #1 —— flag = 1 */
/* @0x15c824 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_flush_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #305 · 0x15c828..0x15c83c · xboxlive_stats_get_leaderboard → F_Platform_Function_Not_Supported (0x1563a0) · argc=6 · flag=1 ── */
/* @0x15c828 ldr r0, [pc, #0x788] —— 池字 0x1ec064：串偏移 → 0x3488a0 "xboxlive_stats_get_leaderboard" */
/* @0x15c82c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c830 mov r2, #6 —— argc = 6 */
/* @0x15c834 add r0, pc, r0 —— r0 = 0x3488a0 = "xboxlive_stats_get_leaderboard" */
/* @0x15c838 mov r3, #1 —— flag = 1 */
/* @0x15c83c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_get_leaderboard", 0x1563a0 <F_Platform_Function_Not_Supported>, 6, 1) */
/* ── #306 · 0x15c840..0x15c854 · xboxlive_stats_get_social_leaderboard → F_Platform_Function_Not_Supported (0x1563a0) · argc=7 · flag=1 ── */
/* @0x15c840 ldr r0, [pc, #0x774] —— 池字 0x1ec06c：串偏移 → 0x3488c0 "xboxlive_stats_get_social_leaderboard" */
/* @0x15c844 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c848 mov r2, #7 —— argc = 7 */
/* @0x15c84c add r0, pc, r0 —— r0 = 0x3488c0 = "xboxlive_stats_get_social_leaderboard" */
/* @0x15c850 mov r3, #1 —— flag = 1 */
/* @0x15c854 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_stats_get_social_leaderboard", 0x1563a0 <F_Platform_Function_Not_Supported>, 7, 1) */
/* ── #307 · 0x15c858..0x15c86c · xboxlive_achievements_set_progress → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c858 ldr r0, [pc, #0x760] —— 池字 0x1ec07c：串偏移 → 0x3488e8 "xboxlive_achievements_set_progress" */
/* @0x15c85c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c860 mov r2, #3 —— argc = 3 */
/* @0x15c864 add r0, pc, r0 —— r0 = 0x3488e8 = "xboxlive_achievements_set_progress" */
/* @0x15c868 mov r3, #1 —— flag = 1 */
/* @0x15c86c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_achievements_set_progress", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #308 · 0x15c870..0x15c884 · xboxlive_set_rich_presence → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c870 ldr r0, [pc, #0x74c] —— 池字 0x1ec088：串偏移 → 0x34890c "xboxlive_set_rich_presence" */
/* @0x15c874 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c878 mov r2, #3 —— argc = 3 */
/* @0x15c87c add r0, pc, r0 —— r0 = 0x34890c = "xboxlive_set_rich_presence" */
/* @0x15c880 mov r3, #1 —— flag = 1 */
/* @0x15c884 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_set_rich_presence", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #309 · 0x15c888..0x15c89c · xboxlive_matchmaking_create → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15c888 ldr r0, [pc, #0x738] —— 池字 0x1ec08c：串偏移 → 0x348928 "xboxlive_matchmaking_create" */
/* @0x15c88c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c890 mov r2, #4 —— argc = 4 */
/* @0x15c894 add r0, pc, r0 —— r0 = 0x348928 = "xboxlive_matchmaking_create" */
/* @0x15c898 mov r3, #1 —— flag = 1 */
/* @0x15c89c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_create", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #310 · 0x15c8a0..0x15c8b4 · xboxlive_matchmaking_find → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c8a0 ldr r0, [pc, #0x724] —— 池字 0x1ec090：串偏移 → 0x348944 "xboxlive_matchmaking_find" */
/* @0x15c8a4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c8a8 mov r2, #3 —— argc = 3 */
/* @0x15c8ac add r0, pc, r0 —— r0 = 0x348944 = "xboxlive_matchmaking_find" */
/* @0x15c8b0 mov r3, #1 —— flag = 1 */
/* @0x15c8b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_find", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #311 · 0x15c8b8..0x15c8cc · xboxlive_matchmaking_start → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c8b8 ldr r0, [pc, #0x710] —— 池字 0x1ec090：串偏移 → 0x348960 "xboxlive_matchmaking_start" */
/* @0x15c8bc mov r2, #1 —— argc = 1 */
/* @0x15c8c0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c8c4 mov r3, r2 —— flag = 1 */
/* @0x15c8c8 add r0, pc, r0 —— r0 = 0x348960 = "xboxlive_matchmaking_start" */
/* @0x15c8cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_start", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #312 · 0x15c8d0..0x15c8e4 · xboxlive_matchmaking_stop → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c8d0 ldr r0, [pc, #0x6fc] —— 池字 0x1ec094：串偏移 → 0x34897c "xboxlive_matchmaking_stop" */
/* @0x15c8d4 mov r2, #1 —— argc = 1 */
/* @0x15c8d8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c8dc mov r3, r2 —— flag = 1 */
/* @0x15c8e0 add r0, pc, r0 —— r0 = 0x34897c = "xboxlive_matchmaking_stop" */
/* @0x15c8e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_stop", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #313 · 0x15c8e8..0x15c8fc · xboxlive_matchmaking_session_get_users → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c8e8 ldr r0, [pc, #0x6e8] —— 池字 0x1ec098：串偏移 → 0x348998 "xboxlive_matchmaking_session_get_users" */
/* @0x15c8ec mov r2, #1 —— argc = 1 */
/* @0x15c8f0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c8f4 mov r3, r2 —— flag = 1 */
/* @0x15c8f8 add r0, pc, r0 —— r0 = 0x348998 = "xboxlive_matchmaking_session_get_users" */
/* @0x15c8fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_session_get_users", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #314 · 0x15c900..0x15c914 · xboxlive_matchmaking_session_leave → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c900 ldr r0, [pc, #0x6d4] —— 池字 0x1ec0a8：串偏移 → 0x3489c0 "xboxlive_matchmaking_session_leave" */
/* @0x15c904 mov r2, #1 —— argc = 1 */
/* @0x15c908 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c90c mov r3, r2 —— flag = 1 */
/* @0x15c910 add r0, pc, r0 —— r0 = 0x3489c0 = "xboxlive_matchmaking_session_leave" */
/* @0x15c914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_session_leave", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #315 · 0x15c918..0x15c92c · xboxlive_matchmaking_send_invites → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c918 ldr r0, [pc, #0x6c0] —— 池字 0x1ec0b8：串偏移 → 0x3489e4 "xboxlive_matchmaking_send_invites" */
/* @0x15c91c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c920 mov r2, #3 —— argc = 3 */
/* @0x15c924 add r0, pc, r0 —— r0 = 0x3489e4 = "xboxlive_matchmaking_send_invites" */
/* @0x15c928 mov r3, #1 —— flag = 1 */
/* @0x15c92c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_send_invites", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #316 · 0x15c930..0x15c944 · xboxlive_matchmaking_set_joinable_session → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c930 ldr r0, [pc, #0x6ac] —— 池字 0x1ec0c4：串偏移 → 0x348a08 "xboxlive_matchmaking_set_joinable_session" */
/* @0x15c934 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c938 mov r2, #2 —— argc = 2 */
/* @0x15c93c add r0, pc, r0 —— r0 = 0x348a08 = "xboxlive_matchmaking_set_joinable_session" */
/* @0x15c940 mov r3, #1 —— flag = 1 */
/* @0x15c944 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_set_joinable_session", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #317 · 0x15c948..0x15c95c · xboxlive_matchmaking_join_invite → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15c948 ldr r0, [pc, #0x698] —— 池字 0x1ec0d8：串偏移 → 0x348a34 "xboxlive_matchmaking_join_invite" */
/* @0x15c94c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c950 mov r2, #4 —— argc = 4 */
/* @0x15c954 add r0, pc, r0 —— r0 = 0x348a34 = "xboxlive_matchmaking_join_invite" */
/* @0x15c958 mov r3, #1 —— flag = 1 */
/* @0x15c95c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_join_invite", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #318 · 0x15c960..0x15c974 · xboxlive_matchmaking_join_session → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15c960 ldr r0, [pc, #0x684] —— 池字 0x1ec0e4：串偏移 → 0x348a58 "xboxlive_matchmaking_join_session" */
/* @0x15c964 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c968 mov r2, #3 —— argc = 3 */
/* @0x15c96c add r0, pc, r0 —— r0 = 0x348a58 = "xboxlive_matchmaking_join_session" */
/* @0x15c970 mov r3, #1 —— flag = 1 */
/* @0x15c974 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_matchmaking_join_session", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #319 · 0x15c978..0x15c98c · xboxlive_chat_add_user_to_channel → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c978 ldr r0, [pc, #0x670] —— 池字 0x1ec0f0：串偏移 → 0x348a7c "xboxlive_chat_add_user_to_channel" */
/* @0x15c97c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c980 mov r2, #2 —— argc = 2 */
/* @0x15c984 add r0, pc, r0 —— r0 = 0x348a7c = "xboxlive_chat_add_user_to_channel" */
/* @0x15c988 mov r3, #1 —— flag = 1 */
/* @0x15c98c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_chat_add_user_to_channel", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #320 · 0x15c990..0x15c9a4 · xboxlive_chat_remove_user_from_channel → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c990 ldr r0, [pc, #0x65c] —— 池字 0x1ec0fc：串偏移 → 0x348aa0 "xboxlive_chat_remove_user_from_channel" */
/* @0x15c994 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c998 mov r2, #2 —— argc = 2 */
/* @0x15c99c add r0, pc, r0 —— r0 = 0x348aa0 = "xboxlive_chat_remove_user_from_channel" */
/* @0x15c9a0 mov r3, #1 —— flag = 1 */
/* @0x15c9a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_chat_remove_user_from_channel", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #321 · 0x15c9a8..0x15c9bc · xboxlive_chat_set_muted → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15c9a8 ldr r0, [pc, #0x648] —— 池字 0x1ec10c：串偏移 → 0x348ac8 "xboxlive_chat_set_muted" */
/* @0x15c9ac mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c9b0 mov r2, #2 —— argc = 2 */
/* @0x15c9b4 add r0, pc, r0 —— r0 = 0x348ac8 = "xboxlive_chat_set_muted" */
/* @0x15c9b8 mov r3, #1 —— flag = 1 */
/* @0x15c9bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_chat_set_muted", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #322 · 0x15c9c0..0x15c9d4 · xboxlive_set_service_configuration_id → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15c9c0 ldr r0, [pc, #0x634] —— 池字 0x1ec108：串偏移 → 0x348ae0 "xboxlive_set_service_configuration_id" */
/* @0x15c9c4 mov r2, #1 —— argc = 1 */
/* @0x15c9c8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c9cc mov r3, r2 —— flag = 1 */
/* @0x15c9d0 add r0, pc, r0 —— r0 = 0x348ae0 = "xboxlive_set_service_configuration_id" */
/* @0x15c9d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("xboxlive_set_service_configuration_id", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #323 · 0x15c9d8..0x15c9ec · psn_get_leaderboard_score_range → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15c9d8 ldr r0, [pc, #0x620] —— 池字 0x1ec11c：串偏移 → 0x348b08 "psn_get_leaderboard_score_range" */
/* @0x15c9dc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c9e0 mov r2, #4 —— argc = 4 */
/* @0x15c9e4 add r0, pc, r0 —— r0 = 0x348b08 = "psn_get_leaderboard_score_range" */
/* @0x15c9e8 mov r3, #1 —— flag = 1 */
/* @0x15c9ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_get_leaderboard_score_range", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #324 · 0x15c9f0..0x15ca04 · psn_default_user_name → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15c9f0 ldr r0, [pc, #0x60c] —— 池字 0x1ec124：串偏移 → 0x348b28 "psn_default_user_name" */
/* @0x15c9f4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15c9f8 mov r2, #0 —— argc = 0 */
/* @0x15c9fc add r0, pc, r0 —— r0 = 0x348b28 = "psn_default_user_name" */
/* @0x15ca00 mov r3, #1 —— flag = 1 */
/* @0x15ca04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_default_user_name", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #325 · 0x15ca08..0x15ca1c · psn_name_for_pad → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15ca08 ldr r0, [pc, #0x5f8] —— 池字 0x1ec120：串偏移 → 0x348b40 "psn_name_for_pad" */
/* @0x15ca0c mov r2, #1 —— argc = 1 */
/* @0x15ca10 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ca14 mov r3, r2 —— flag = 1 */
/* @0x15ca18 add r0, pc, r0 —— r0 = 0x348b40 = "psn_name_for_pad" */
/* @0x15ca1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_name_for_pad", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #326 · 0x15ca20..0x15ca34 · psn_unlock_trophy → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15ca20 ldr r0, [pc, #0x5e4] —— 池字 0x1ec120：串偏移 → 0x348b54 "psn_unlock_trophy" */
/* @0x15ca24 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ca28 mov r2, #2 —— argc = 2 */
/* @0x15ca2c add r0, pc, r0 —— r0 = 0x348b54 = "psn_unlock_trophy" */
/* @0x15ca30 mov r3, #1 —— flag = 1 */
/* @0x15ca34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_unlock_trophy", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #327 · 0x15ca38..0x15ca4c · psn_get_trophy_unlock_state → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15ca38 ldr r0, [pc, #0x5d0] —— 池字 0x1ec118：串偏移 → 0x348b68 "psn_get_trophy_unlock_state" */
/* @0x15ca3c mov r2, #1 —— argc = 1 */
/* @0x15ca40 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ca44 mov r3, r2 —— flag = 1 */
/* @0x15ca48 add r0, pc, r0 —— r0 = 0x348b68 = "psn_get_trophy_unlock_state" */
/* @0x15ca4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_get_trophy_unlock_state", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #328 · 0x15ca50..0x15ca64 · psn_init_np_libs → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15ca50 ldr r0, [pc, #0x5bc] —— 池字 0x1ec120：串偏移 → 0x348b84 "psn_init_np_libs" */
/* @0x15ca54 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ca58 mov r2, #3 —— argc = 3 */
/* @0x15ca5c add r0, pc, r0 —— r0 = 0x348b84 = "psn_init_np_libs" */
/* @0x15ca60 mov r3, #1 —— flag = 1 */
/* @0x15ca64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_init_np_libs", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #329 · 0x15ca68..0x15ca7c · psn_exit_np_libs → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15ca68 ldr r0, [pc, #0x5a8] —— 池字 0x1ec11c：串偏移 → 0x348b98 "psn_exit_np_libs" */
/* @0x15ca6c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ca70 mov r2, #0 —— argc = 0 */
/* @0x15ca74 add r0, pc, r0 —— r0 = 0x348b98 = "psn_exit_np_libs" */
/* @0x15ca78 mov r3, #1 —— flag = 1 */
/* @0x15ca7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_exit_np_libs", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #330 · 0x15ca80..0x15ca94 · psn_get_leaderboard_score → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15ca80 ldr r0, [pc, #0x594] —— 池字 0x1ec118：串偏移 → 0x348bac "psn_get_leaderboard_score" */
/* @0x15ca84 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ca88 mov r2, #2 —— argc = 2 */
/* @0x15ca8c add r0, pc, r0 —— r0 = 0x348bac = "psn_get_leaderboard_score" */
/* @0x15ca90 mov r3, #1 —— flag = 1 */
/* @0x15ca94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_get_leaderboard_score", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #331 · 0x15ca98..0x15caac · psn_post_leaderboard_score → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15ca98 ldr r0, [pc, #0x580] —— 池字 0x1ec11c：串偏移 → 0x348bc8 "psn_post_leaderboard_score" */
/* @0x15ca9c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15caa0 mov r2, #3 —— argc = 3 */
/* @0x15caa4 add r0, pc, r0 —— r0 = 0x348bc8 = "psn_post_leaderboard_score" */
/* @0x15caa8 mov r3, #1 —— flag = 1 */
/* @0x15caac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_post_leaderboard_score", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #332 · 0x15cab0..0x15cac4 · psn_post_leaderboard_score_comment → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15cab0 ldr r0, [pc, #0x56c] —— 池字 0x1ec120：串偏移 → 0x348be4 "psn_post_leaderboard_score_comment" */
/* @0x15cab4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cab8 mov r2, #4 —— argc = 4 */
/* @0x15cabc add r0, pc, r0 —— r0 = 0x348be4 = "psn_post_leaderboard_score_comment" */
/* @0x15cac0 mov r3, #1 —— flag = 1 */
/* @0x15cac4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_post_leaderboard_score_comment", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #333 · 0x15cac8..0x15cadc · psn_check_np_availability → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15cac8 ldr r0, [pc, #0x558] —— 池字 0x1ec12c：串偏移 → 0x348c08 "psn_check_np_availability" */
/* @0x15cacc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cad0 mov r2, #2 —— argc = 2 */
/* @0x15cad4 add r0, pc, r0 —— r0 = 0x348c08 = "psn_check_np_availability" */
/* @0x15cad8 mov r3, #1 —— flag = 1 */
/* @0x15cadc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_check_np_availability", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #334 · 0x15cae0..0x15caf4 · psn_tick_error_dialog → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cae0 ldr r0, [pc, #0x544] —— 池字 0x1ec130：串偏移 → 0x348c24 "psn_tick_error_dialog" */
/* @0x15cae4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cae8 mov r2, #0 —— argc = 0 */
/* @0x15caec add r0, pc, r0 —— r0 = 0x348c24 = "psn_tick_error_dialog" */
/* @0x15caf0 mov r3, #1 —— flag = 1 */
/* @0x15caf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_tick_error_dialog", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #335 · 0x15caf8..0x15cb0c · psn_get_friends_scores → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15caf8 ldr r0, [pc, #0x530] —— 池字 0x1ec130：串偏移 → 0x348c3c "psn_get_friends_scores" */
/* @0x15cafc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cb00 mov r2, #4 —— argc = 4 */
/* @0x15cb04 add r0, pc, r0 —— r0 = 0x348c3c = "psn_get_friends_scores" */
/* @0x15cb08 mov r3, #1 —— flag = 1 */
/* @0x15cb0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_get_friends_scores", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #336 · 0x15cb10..0x15cb24 · psn_name_for_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cb10 ldr r0, [pc, #0x51c] —— 池字 0x1ec12c：串偏移 → 0x348c54 "psn_name_for_user" */
/* @0x15cb14 mov r2, #1 —— argc = 1 */
/* @0x15cb18 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cb1c mov r3, r2 —— flag = 1 */
/* @0x15cb20 add r0, pc, r0 —— r0 = 0x348c54 = "psn_name_for_user" */
/* @0x15cb24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_name_for_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #337 · 0x15cb28..0x15cb3c · psn_default_user → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cb28 ldr r0, [pc, #0x508] —— 池字 0x1ec12c：串偏移 → 0x348c68 "psn_default_user" */
/* @0x15cb2c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cb30 mov r2, #0 —— argc = 0 */
/* @0x15cb34 add r0, pc, r0 —— r0 = 0x348c68 = "psn_default_user" */
/* @0x15cb38 mov r3, #1 —— flag = 1 */
/* @0x15cb3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_default_user", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #338 · 0x15cb40..0x15cb54 · psn_user_for_pad → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cb40 ldr r0, [pc, #0x4f4] —— 池字 0x1ec124：串偏移 → 0x348c7c "psn_user_for_pad" */
/* @0x15cb44 mov r2, #1 —— argc = 1 */
/* @0x15cb48 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cb4c mov r3, r2 —— flag = 1 */
/* @0x15cb50 add r0, pc, r0 —— r0 = 0x348c7c = "psn_user_for_pad" */
/* @0x15cb54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_user_for_pad", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #339 · 0x15cb58..0x15cb6c · matchmaking_reset_create_params → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cb58 ldr r0, [pc, #0x4e0] —— 池字 0x1ec124：串偏移 → 0x348c90 "matchmaking_reset_create_params" */
/* @0x15cb5c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cb60 mov r2, #0 —— argc = 0 */
/* @0x15cb64 add r0, pc, r0 —— r0 = 0x348c90 = "matchmaking_reset_create_params" */
/* @0x15cb68 mov r3, #1 —— flag = 1 */
/* @0x15cb6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_reset_create_params", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #340 · 0x15cb70..0x15cb84 · matchmaking_add_create_param → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15cb70 ldr r0, [pc, #0x4cc] —— 池字 0x1ec12c：串偏移 → 0x348cb0 "matchmaking_add_create_param" */
/* @0x15cb74 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cb78 mov r2, #2 —— argc = 2 */
/* @0x15cb7c add r0, pc, r0 —— r0 = 0x348cb0 = "matchmaking_add_create_param" */
/* @0x15cb80 mov r3, #1 —— flag = 1 */
/* @0x15cb84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_add_create_param", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #341 · 0x15cb88..0x15cb9c · matchmaking_session_create → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15cb88 ldr r0, [pc, #0x4b8] —— 池字 0x1ec134：串偏移 → 0x348cd0 "matchmaking_session_create" */
/* @0x15cb8c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cb90 mov r2, #2 —— argc = 2 */
/* @0x15cb94 add r0, pc, r0 —— r0 = 0x348cd0 = "matchmaking_session_create" */
/* @0x15cb98 mov r3, #1 —— flag = 1 */
/* @0x15cb9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_create", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #342 · 0x15cba0..0x15cbb4 · matchmaking_session_get_users → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cba0 ldr r0, [pc, #0x4a4] —— 池字 0x1ec134：串偏移 → 0x348cec "matchmaking_session_get_users" */
/* @0x15cba4 mov r2, #1 —— argc = 1 */
/* @0x15cba8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cbac mov r3, r2 —— flag = 1 */
/* @0x15cbb0 add r0, pc, r0 —— r0 = 0x348cec = "matchmaking_session_get_users" */
/* @0x15cbb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_get_users", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #343 · 0x15cbb8..0x15cbcc · matchmaking_session_get_owner → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cbb8 ldr r0, [pc, #0x490] —— 池字 0x1ec13c：串偏移 → 0x348d0c "matchmaking_session_get_owner" */
/* @0x15cbbc mov r2, #1 —— argc = 1 */
/* @0x15cbc0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cbc4 mov r3, r2 —— flag = 1 */
/* @0x15cbc8 add r0, pc, r0 —— r0 = 0x348d0c = "matchmaking_session_get_owner" */
/* @0x15cbcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_get_owner", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #344 · 0x15cbd0..0x15cbe4 · matchmaking_session_set_closed → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cbd0 ldr r0, [pc, #0x47c] —— 池字 0x1ec144：串偏移 → 0x348d2c "matchmaking_session_set_closed" */
/* @0x15cbd4 mov r2, #1 —— argc = 1 */
/* @0x15cbd8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cbdc mov r3, r2 —— flag = 1 */
/* @0x15cbe0 add r0, pc, r0 —— r0 = 0x348d2c = "matchmaking_session_set_closed" */
/* @0x15cbe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_set_closed", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #345 · 0x15cbe8..0x15cbfc · matchmaking_session_set_open → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cbe8 ldr r0, [pc, #0x468] —— 池字 0x1ec14c：串偏移 → 0x348d4c "matchmaking_session_set_open" */
/* @0x15cbec mov r2, #1 —— argc = 1 */
/* @0x15cbf0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cbf4 mov r3, r2 —— flag = 1 */
/* @0x15cbf8 add r0, pc, r0 —— r0 = 0x348d4c = "matchmaking_session_set_open" */
/* @0x15cbfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_set_open", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #346 · 0x15cc00..0x15cc14 · matchmaking_session_set_hidden → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cc00 ldr r0, [pc, #0x454] —— 池字 0x1ec154：串偏移 → 0x348d6c "matchmaking_session_set_hidden" */
/* @0x15cc04 mov r2, #1 —— argc = 1 */
/* @0x15cc08 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cc0c mov r3, r2 —— flag = 1 */
/* @0x15cc10 add r0, pc, r0 —— r0 = 0x348d6c = "matchmaking_session_set_hidden" */
/* @0x15cc14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_set_hidden", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #347 · 0x15cc18..0x15cc2c · matchmaking_reset_find_params → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cc18 ldr r0, [pc, #0x440] —— 池字 0x1ec160：串偏移 → 0x348d8c "matchmaking_reset_find_params" */
/* @0x15cc1c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cc20 mov r2, #0 —— argc = 0 */
/* @0x15cc24 add r0, pc, r0 —— r0 = 0x348d8c = "matchmaking_reset_find_params" */
/* @0x15cc28 mov r3, #1 —— flag = 1 */
/* @0x15cc2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_reset_find_params", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #348 · 0x15cc30..0x15cc44 · matchmaking_add_find_param → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15cc30 ldr r0, [pc, #0x42c] —— 池字 0x1ec168：串偏移 → 0x348dac "matchmaking_add_find_param" */
/* @0x15cc34 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cc38 mov r2, #3 —— argc = 3 */
/* @0x15cc3c add r0, pc, r0 —— r0 = 0x348dac = "matchmaking_add_find_param" */
/* @0x15cc40 mov r3, #1 —— flag = 1 */
/* @0x15cc44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_add_find_param", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #349 · 0x15cc48..0x15cc5c · matchmaking_session_find → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cc48 ldr r0, [pc, #0x418] —— 池字 0x1ec16c：串偏移 → 0x348dc8 "matchmaking_session_find" */
/* @0x15cc4c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cc50 mov r2, #0 —— argc = 0 */
/* @0x15cc54 add r0, pc, r0 —— r0 = 0x348dc8 = "matchmaking_session_find" */
/* @0x15cc58 mov r3, #1 —— flag = 1 */
/* @0x15cc5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_find", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #350 · 0x15cc60..0x15cc74 · matchmaking_session_join → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cc60 ldr r0, [pc, #0x404] —— 池字 0x1ec16c：串偏移 → 0x348de4 "matchmaking_session_join" */
/* @0x15cc64 mov r2, #1 —— argc = 1 */
/* @0x15cc68 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cc6c mov r3, r2 —— flag = 1 */
/* @0x15cc70 add r0, pc, r0 —— r0 = 0x348de4 = "matchmaking_session_join" */
/* @0x15cc74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_join", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #351 · 0x15cc78..0x15cc8c · matchmaking_session_leave → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cc78 ldr r0, [pc, #0x3f0] —— 池字 0x1ec170：串偏移 → 0x348e00 "matchmaking_session_leave" */
/* @0x15cc7c mov r2, #1 —— argc = 1 */
/* @0x15cc80 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cc84 mov r3, r2 —— flag = 1 */
/* @0x15cc88 add r0, pc, r0 —— r0 = 0x348e00 = "matchmaking_session_leave" */
/* @0x15cc8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_leave", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #352 · 0x15cc90..0x15cca4 · matchmaking_session_update → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cc90 ldr r0, [pc, #0x3dc] —— 池字 0x1ec174：串偏移 → 0x348e1c "matchmaking_session_update" */
/* @0x15cc94 mov r2, #1 —— argc = 1 */
/* @0x15cc98 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cc9c mov r3, r2 —— flag = 1 */
/* @0x15cca0 add r0, pc, r0 —— r0 = 0x348e1c = "matchmaking_session_update" */
/* @0x15cca4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_update", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #353 · 0x15cca8..0x15ccbc · matchmaking_start → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15cca8 ldr r0, [pc, #0x3c8] —— 池字 0x1ec17c：串偏移 → 0x348e38 "matchmaking_start" */
/* @0x15ccac mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ccb0 mov r2, #2 —— argc = 2 */
/* @0x15ccb4 add r0, pc, r0 —— r0 = 0x348e38 = "matchmaking_start" */
/* @0x15ccb8 mov r3, #1 —— flag = 1 */
/* @0x15ccbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_start", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #354 · 0x15ccc0..0x15ccd4 · matchmaking_stop → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15ccc0 ldr r0, [pc, #0x3b4] —— 池字 0x1ec178：串偏移 → 0x348e4c "matchmaking_stop" */
/* @0x15ccc4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ccc8 mov r2, #0 —— argc = 0 */
/* @0x15cccc add r0, pc, r0 —— r0 = 0x348e4c = "matchmaking_stop" */
/* @0x15ccd0 mov r3, #1 —— flag = 1 */
/* @0x15ccd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_stop", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #355 · 0x15ccd8..0x15ccec · matchmaking_session_invite_start → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15ccd8 ldr r0, [pc, #0x3a0] —— 池字 0x1ec170：串偏移 → 0x348e60 "matchmaking_session_invite_start" */
/* @0x15ccdc mov r2, #1 —— argc = 1 */
/* @0x15cce0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cce4 mov r3, r2 —— flag = 1 */
/* @0x15cce8 add r0, pc, r0 —— r0 = 0x348e60 = "matchmaking_session_invite_start" */
/* @0x15ccec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_session_invite_start", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #356 · 0x15ccf0..0x15cd04 · matchmaking_send_invites_no_ui → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15ccf0 ldr r0, [pc, #0x38c] —— 池字 0x1ec180：串偏移 → 0x348e84 "matchmaking_send_invites_no_ui" */
/* @0x15ccf4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ccf8 mov r2, #4 —— argc = 4 */
/* @0x15ccfc add r0, pc, r0 —— r0 = 0x348e84 = "matchmaking_send_invites_no_ui" */
/* @0x15cd00 mov r3, #1 —— flag = 1 */
/* @0x15cd04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_send_invites_no_ui", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #357 · 0x15cd08..0x15cd1c · matchmaking_send_invites → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15cd08 ldr r0, [pc, #0x378] —— 池字 0x1ec188：串偏移 → 0x348ea4 "matchmaking_send_invites" */
/* @0x15cd0c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cd10 mov r2, #3 —— argc = 3 */
/* @0x15cd14 add r0, pc, r0 —— r0 = 0x348ea4 = "matchmaking_send_invites" */
/* @0x15cd18 mov r3, #1 —— flag = 1 */
/* @0x15cd1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_send_invites", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #358 · 0x15cd20..0x15cd34 · matchmaking_tick_invites → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cd20 ldr r0, [pc, #0x364] —— 池字 0x1ec18c：串偏移 → 0x348ec0 "matchmaking_tick_invites" */
/* @0x15cd24 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cd28 mov r2, #0 —— argc = 0 */
/* @0x15cd2c add r0, pc, r0 —— r0 = 0x348ec0 = "matchmaking_tick_invites" */
/* @0x15cd30 mov r3, #1 —— flag = 1 */
/* @0x15cd34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_tick_invites", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #359 · 0x15cd38..0x15cd4c · matchmaking_join_invite → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cd38 ldr r0, [pc, #0x350] —— 池字 0x1ec18c：串偏移 → 0x348edc "matchmaking_join_invite" */
/* @0x15cd3c mov r2, #1 —— argc = 1 */
/* @0x15cd40 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cd44 mov r3, r2 —— flag = 1 */
/* @0x15cd48 add r0, pc, r0 —— r0 = 0x348edc = "matchmaking_join_invite" */
/* @0x15cd4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("matchmaking_join_invite", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #360 · 0x15cd50..0x15cd64 · psn_np_check_plus → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15cd50 ldr r0, [pc, #0x33c] —— 池字 0x1ec190：串偏移 → 0x348ef4 "psn_np_check_plus" */
/* @0x15cd54 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cd58 mov r2, #3 —— argc = 3 */
/* @0x15cd5c add r0, pc, r0 —— r0 = 0x348ef4 = "psn_np_check_plus" */
/* @0x15cd60 mov r3, #1 —— flag = 1 */
/* @0x15cd64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_np_check_plus", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #361 · 0x15cd68..0x15cd7c · psn_np_commerce_dialog_open → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15cd68 ldr r0, [pc, #0x328] —— 池字 0x1ec18c：串偏移 → 0x348f08 "psn_np_commerce_dialog_open" */
/* @0x15cd6c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cd70 mov r2, #3 —— argc = 3 */
/* @0x15cd74 add r0, pc, r0 —— r0 = 0x348f08 = "psn_np_commerce_dialog_open" */
/* @0x15cd78 mov r3, #1 —— flag = 1 */
/* @0x15cd7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_np_commerce_dialog_open", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #362 · 0x15cd80..0x15cd94 · psn_np_commerce_dialog_tick → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cd80 ldr r0, [pc, #0x314] —— 池字 0x1ec190：串偏移 → 0x348f24 "psn_np_commerce_dialog_tick" */
/* @0x15cd84 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cd88 mov r2, #0 —— argc = 0 */
/* @0x15cd8c add r0, pc, r0 —— r0 = 0x348f24 = "psn_np_commerce_dialog_tick" */
/* @0x15cd90 mov r3, #1 —— flag = 1 */
/* @0x15cd94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_np_commerce_dialog_tick", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #363 · 0x15cd98..0x15cdac · psn_np_notify_plus_feature → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15cd98 ldr r0, [pc, #0x300] —— 池字 0x1ec194：串偏移 → 0x348f40 "psn_np_notify_plus_feature" */
/* @0x15cd9c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cda0 mov r2, #3 —— argc = 3 */
/* @0x15cda4 add r0, pc, r0 —— r0 = 0x348f40 = "psn_np_notify_plus_feature" */
/* @0x15cda8 mov r3, #1 —— flag = 1 */
/* @0x15cdac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_np_notify_plus_feature", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #364 · 0x15cdb0..0x15cdc4 · psn_set_content_restriction → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cdb0 ldr r0, [pc, #0x2ec] —— 池字 0x1ec194：串偏移 → 0x348f5c "psn_set_content_restriction" */
/* @0x15cdb4 mov r2, #1 —— argc = 1 */
/* @0x15cdb8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cdbc mov r3, r2 —— flag = 1 */
/* @0x15cdc0 add r0, pc, r0 —— r0 = 0x348f5c = "psn_set_content_restriction" */
/* @0x15cdc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_set_content_restriction", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #365 · 0x15cdc8..0x15cddc · psn_load_modules → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cdc8 ldr r0, [pc, #0x2d8] —— 池字 0x1ec19c：串偏移 → 0x348f78 "psn_load_modules" */
/* @0x15cdcc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cdd0 mov r2, #0 —— argc = 0 */
/* @0x15cdd4 add r0, pc, r0 —— r0 = 0x348f78 = "psn_load_modules" */
/* @0x15cdd8 mov r3, #1 —— flag = 1 */
/* @0x15cddc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_load_modules", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #366 · 0x15cde0..0x15cdf4 · psn_get_avatar_url → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cde0 ldr r0, [pc, #0x2c4] —— 池字 0x1ec194：串偏移 → 0x348f8c "psn_get_avatar_url" */
/* @0x15cde4 mov r2, #1 —— argc = 1 */
/* @0x15cde8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cdec mov r3, r2 —— flag = 1 */
/* @0x15cdf0 add r0, pc, r0 —— r0 = 0x348f8c = "psn_get_avatar_url" */
/* @0x15cdf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_get_avatar_url", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #367 · 0x15cdf8..0x15ce0c · psn_get_tus_data → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15cdf8 ldr r0, [pc, #0x2b0] —— 池字 0x1ec194：串偏移 → 0x348fa0 "psn_get_tus_data" */
/* @0x15cdfc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ce00 mov r2, #2 —— argc = 2 */
/* @0x15ce04 add r0, pc, r0 —— r0 = 0x348fa0 = "psn_get_tus_data" */
/* @0x15ce08 mov r3, #1 —— flag = 1 */
/* @0x15ce0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_get_tus_data", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #368 · 0x15ce10..0x15ce24 · psn_set_tus_data → F_Platform_Function_Not_Supported (0x1563a0) · argc=4 · flag=1 ── */
/* @0x15ce10 ldr r0, [pc, #0x29c] —— 池字 0x1ec190：串偏移 → 0x348fb4 "psn_set_tus_data" */
/* @0x15ce14 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ce18 mov r2, #4 —— argc = 4 */
/* @0x15ce1c add r0, pc, r0 —— r0 = 0x348fb4 = "psn_set_tus_data" */
/* @0x15ce20 mov r3, #1 —— flag = 1 */
/* @0x15ce24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_set_tus_data", 0x1563a0 <F_Platform_Function_Not_Supported>, 4, 1) */
/* ── #369 · 0x15ce28..0x15ce3c · psn_get_tus_variable → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15ce28 ldr r0, [pc, #0x288] —— 池字 0x1ec18c：串偏移 → 0x348fc8 "psn_get_tus_variable" */
/* @0x15ce2c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ce30 mov r2, #2 —— argc = 2 */
/* @0x15ce34 add r0, pc, r0 —— r0 = 0x348fc8 = "psn_get_tus_variable" */
/* @0x15ce38 mov r3, #1 —— flag = 1 */
/* @0x15ce3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_get_tus_variable", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #370 · 0x15ce40..0x15ce54 · psn_set_tus_variable → F_Platform_Function_Not_Supported (0x1563a0) · argc=3 · flag=1 ── */
/* @0x15ce40 ldr r0, [pc, #0x274] —— 池字 0x1ec18c：串偏移 → 0x348fe0 "psn_set_tus_variable" */
/* @0x15ce44 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ce48 mov r2, #3 —— argc = 3 */
/* @0x15ce4c add r0, pc, r0 —— r0 = 0x348fe0 = "psn_set_tus_variable" */
/* @0x15ce50 mov r3, #1 —— flag = 1 */
/* @0x15ce54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_set_tus_variable", 0x1563a0 <F_Platform_Function_Not_Supported>, 3, 1) */
/* ── #371 · 0x15ce58..0x15ce6c · psn_delete_tus_data → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15ce58 ldr r0, [pc, #0x260] —— 池字 0x1ec18c：串偏移 → 0x348ff8 "psn_delete_tus_data" */
/* @0x15ce5c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ce60 mov r2, #2 —— argc = 2 */
/* @0x15ce64 add r0, pc, r0 —— r0 = 0x348ff8 = "psn_delete_tus_data" */
/* @0x15ce68 mov r3, #1 —— flag = 1 */
/* @0x15ce6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_delete_tus_data", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #372 · 0x15ce70..0x15ce84 · psn_content_restriction_add → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15ce70 ldr r0, [pc, #0x24c] —— 池字 0x1ec188：串偏移 → 0x34900c "psn_content_restriction_add" */
/* @0x15ce74 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ce78 mov r2, #2 —— argc = 2 */
/* @0x15ce7c add r0, pc, r0 —— r0 = 0x34900c = "psn_content_restriction_add" */
/* @0x15ce80 mov r3, #1 —— flag = 1 */
/* @0x15ce84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_content_restriction_add", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #373 · 0x15ce88..0x15ce9c · psn_net_check → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15ce88 ldr r0, [pc, #0x238] —— 池字 0x1ec188：串偏移 → 0x349028 "psn_net_check" */
/* @0x15ce8c mov r2, #1 —— argc = 1 */
/* @0x15ce90 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15ce94 mov r3, r2 —— flag = 1 */
/* @0x15ce98 add r0, pc, r0 —— r0 = 0x349028 = "psn_net_check" */
/* @0x15ce9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_net_check", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #374 · 0x15cea0..0x15ceb4 · psn_setup_trophies → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cea0 ldr r0, [pc, #0x224] —— 池字 0x1ec184：串偏移 → 0x349038 "psn_setup_trophies" */
/* @0x15cea4 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cea8 mov r2, #0 —— argc = 0 */
/* @0x15ceac add r0, pc, r0 —— r0 = 0x349038 = "psn_setup_trophies" */
/* @0x15ceb0 mov r3, #1 —— flag = 1 */
/* @0x15ceb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_setup_trophies", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #375 · 0x15ceb8..0x15cecc · psn_tick → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15ceb8 ldr r0, [pc, #0x210] —— 池字 0x1ec180：串偏移 → 0x34904c "psn_tick" */
/* @0x15cebc mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cec0 mov r2, #0 —— argc = 0 */
/* @0x15cec4 add r0, pc, r0 —— r0 = 0x34904c = "psn_tick" */
/* @0x15cec8 mov r3, #1 —— flag = 1 */
/* @0x15cecc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_tick", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #376 · 0x15ced0..0x15cee4 · psn_init_trophy → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15ced0 ldr r0, [pc, #0x1fc] —— 池字 0x1ec170：串偏移 → 0x349058 "psn_init_trophy" */
/* @0x15ced4 mov r2, #1 —— argc = 1 */
/* @0x15ced8 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cedc mov r3, r2 —— flag = 1 */
/* @0x15cee0 add r0, pc, r0 —— r0 = 0x349058 = "psn_init_trophy" */
/* @0x15cee4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_init_trophy", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #377 · 0x15cee8..0x15cefc · psn_np_status → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cee8 ldr r0, [pc, #0x1e8] —— 池字 0x1ec168：串偏移 → 0x349068 "psn_np_status" */
/* @0x15ceec mov r2, #1 —— argc = 1 */
/* @0x15cef0 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cef4 mov r3, r2 —— flag = 1 */
/* @0x15cef8 add r0, pc, r0 —— r0 = 0x349068 = "psn_np_status" */
/* @0x15cefc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_np_status", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #378 · 0x15cf00..0x15cf14 · psn_show_error_dialog → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cf00 ldr r0, [pc, #0x1d4] —— 池字 0x1ec160：串偏移 → 0x349078 "psn_show_error_dialog" */
/* @0x15cf04 mov r2, #1 —— argc = 1 */
/* @0x15cf08 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cf0c mov r3, r2 —— flag = 1 */
/* @0x15cf10 add r0, pc, r0 —— r0 = 0x349078 = "psn_show_error_dialog" */
/* @0x15cf14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_show_error_dialog", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #379 · 0x15cf18..0x15cf2c · psn_check_free_space → F_Platform_Function_Not_Supported (0x1563a0) · argc=2 · flag=1 ── */
/* @0x15cf18 ldr r0, [pc, #0x1c0] —— 池字 0x1ec164：串偏移 → 0x349090 "psn_check_free_space" */
/* @0x15cf1c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cf20 mov r2, #2 —— argc = 2 */
/* @0x15cf24 add r0, pc, r0 —— r0 = 0x349090 = "psn_check_free_space" */
/* @0x15cf28 mov r3, #1 —— flag = 1 */
/* @0x15cf2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_check_free_space", 0x1563a0 <F_Platform_Function_Not_Supported>, 2, 1) */
/* ── #380 · 0x15cf30..0x15cf44 · psn_get_entitlement_list → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cf30 ldr r0, [pc, #0x1ac] —— 池字 0x1ec164：串偏移 → 0x3490a8 "psn_get_entitlement_list" */
/* @0x15cf34 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cf38 mov r2, #0 —— argc = 0 */
/* @0x15cf3c add r0, pc, r0 —— r0 = 0x3490a8 = "psn_get_entitlement_list" */
/* @0x15cf40 mov r3, #1 —— flag = 1 */
/* @0x15cf44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("psn_get_entitlement_list", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #381 · 0x15cf48..0x15cf5c · video_open → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cf48 ldr r0, [pc, #0x198] —— 池字 0x1ec164：串偏移 → 0x3490c4 "video_open" */
/* @0x15cf4c mov r2, #1 —— argc = 1 */
/* @0x15cf50 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cf54 mov r3, r2 —— flag = 1 */
/* @0x15cf58 add r0, pc, r0 —— r0 = 0x3490c4 = "video_open" */
/* @0x15cf5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("video_open", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */
/* ── #382 · 0x15cf60..0x15cf74 · video_close → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cf60 ldr r0, [pc, #0x184] —— 池字 0x1ec15c：串偏移 → 0x3490d0 "video_close" */
/* @0x15cf64 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cf68 mov r2, #0 —— argc = 0 */
/* @0x15cf6c add r0, pc, r0 —— r0 = 0x3490d0 = "video_close" */
/* @0x15cf70 mov r3, #1 —— flag = 1 */
/* @0x15cf74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("video_close", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #383 · 0x15cf78..0x15cf8c · video_draw → F_Platform_Function_Not_Supported (0x1563a0) · argc=0 · flag=1 ── */
/* @0x15cf78 ldr r0, [pc, #0x170] —— 池字 0x1ec150：串偏移 → 0x3490dc "video_draw" */
/* @0x15cf7c mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cf80 mov r2, #0 —— argc = 0 */
/* @0x15cf84 add r0, pc, r0 —— r0 = 0x3490dc = "video_draw" */
/* @0x15cf88 mov r3, #1 —— flag = 1 */
/* @0x15cf8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("video_draw", 0x1563a0 <F_Platform_Function_Not_Supported>, 0, 1) */
/* ── #384 · 0x15cf90..0x15cfa4 · video_set_volume → F_Platform_Function_Not_Supported (0x1563a0) · argc=1 · flag=1 ── */
/* @0x15cf90 ldr r0, [pc, #0x15c] —— 池字 0x1ec140：串偏移 → 0x3490e8 "video_set_volume" */
/* @0x15cf94 mov r2, #1 —— argc = 1 */
/* @0x15cf98 mov r1, r5 —— r1 = fn = 0x1563a0 <F_Platform_Function_Not_Supported> */
/* @0x15cf9c mov r3, r2 —— flag = 1 */
/* @0x15cfa0 add r0, pc, r0 —— r0 = 0x3490e8 = "video_set_volume" */
/* @0x15cfa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> —— Function_Add("video_set_volume", 0x1563a0 <F_Platform_Function_Not_Supported>, 1, 1) */

/* ══ §3 收尾 0x15cfa8..0x15cfb0：add sp / pop / **尾调** InitJavaScriptFunctions ══ */
/* @0x15cfa8 add sp, sp, #28 —— 帧释放 */
/* @0x15cfac pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— pop 9 个寄存器 */
/* @0x15cfb0 b 0x246fe0 <_Z23InitJavaScriptFunctionsv> —— **尾调** InitJavaScriptFunctions(0x246fe0)：本函数没有 return，把收尾交给它 */

/* ══ §4 与 cards/Builtins_*.c 的 87 个已用 builtin 的交集 = 0 ══ */
/*   87 个名字（9 张卡 11+5+5+11+9+9+14+14+9）逐个小写比对，能对上的 **0 个**。四条互证：
 *     a) 名字集不相交：本表是 YoYo_/psn_/xboxlive_/xboxone_/uwp_/winphone_/ads_/facebook_/openfeint_/… 的平台层，
 *        87 个是 core GML（draw_*/instance_*/ds_map_*/string/max/min/choose/…），没有一个同名。
 *     b) 目标地址区间不相交：87 个 F_* 落在 0x0fec90..0x143ba8；本表 385 个目标落在 0x156030..0x159d04（+ 占位 0x1563a0），
 *        两批的 152 个函数指针与 87 个 F_* 无一相同。
 *     c) 唯一「同名族」的错觉：本表有 display_get_dpi_x / display_get_gui_width 等，87 里有 display_get_width /
 *        display_get_height —— 名字相近但既非同名也不指向同一函数（0x1576b8 / 0x157908 vs 0x119bc4 / 0x119bf4）。
 *   因此这 385 条**不是**游戏脚本实际调用的内建；它们是把 runner 的平台 API 整体登记进表（大部分是占位）。
 *   (d) 结构旁证：InitGMLFunctions(0x2a297c) 里 25 个 init 逐个装各自的族，core GML 那批由
 *       InitGame/InitMath/InitGraphic/InitAction/InitFile/InitResource/… 负责，本函数只排第 23（脚本层最后一段）。
 */

/* ══ §池2 0x15cfb4..0x15d0f4（81 字，块 2 尾部的字面量）══ */

/* ══ §池2 明细（81 字，全部是字面量：objdump 按 ARM 译成 andseq/eoreq/mulseq/… 等，**非指令**）══ */
/* @0x15cfb4 andseq r12, lr, r0, rrx —— 池字 0x1ec060 = 串偏移 → 0x348884 "xboxlive_stats_flush_user"（1 处引用） */
/* @0x15cfb8 andseq r12, lr, r4, rrx —— 池字 0x1ec064 = 串偏移 → 0x3488a0 "xboxlive_stats_get_leaderboard"（1 处引用） */
/* @0x15cfbc andseq r12, lr, r12, rrx —— 池字 0x1ec06c = 串偏移 → 0x3488c0 "xboxlive_stats_get_social_leaderboard"（1 处引用） */
/* @0x15cfc0 andseq r12, lr, r12, ror r0 —— 池字 0x1ec07c = 串偏移 → 0x3488e8 "xboxlive_achievements_set_progress"（1 处引用） */
/* @0x15cfc4 andseq r12, lr, r8, lsl #1 —— 池字 0x1ec088 = 串偏移 → 0x34890c "xboxlive_set_rich_presence"（1 处引用） */
/* @0x15cfc8 andseq r12, lr, r12, lsl #1 —— 池字 0x1ec08c = 串偏移 → 0x348928 "xboxlive_matchmaking_create"（1 处引用） */
/* @0x15cfcc mulseq lr, r0, r0 —— 池字 0x1ec090 = 串偏移 → 0x348944 "xboxlive_matchmaking_find"（1 处引用） */
/* @0x15cfd0 mulseq lr, r0, r0 —— 池字 0x1ec090 = 串偏移 → 0x348960 "xboxlive_matchmaking_start"（1 处引用） */
/* @0x15cfd4 mulseq lr, r4, r0 —— 池字 0x1ec094 = 串偏移 → 0x34897c "xboxlive_matchmaking_stop"（1 处引用） */
/* @0x15cfd8 mulseq lr, r8, r0 —— 池字 0x1ec098 = 串偏移 → 0x348998 "xboxlive_matchmaking_session_get_users"（1 处引用） */
/* @0x15cfdc andseq r12, lr, r8, lsr #1 —— 池字 0x1ec0a8 = 串偏移 → 0x3489c0 "xboxlive_matchmaking_session_leave"（1 处引用） */
/* @0x15cfe0 ldrheq r12, [lr], -r8 —— 池字 0x1ec0b8 = 串偏移 → 0x3489e4 "xboxlive_matchmaking_send_invites"（1 处引用） */
/* @0x15cfe4 andseq r12, lr, r4, asr #1 —— 池字 0x1ec0c4 = 串偏移 → 0x348a08 "xboxlive_matchmaking_set_joinable_session"（1 处引用） */
/* @0x15cfe8 ldrsbeq r12, [lr], -r8 —— 池字 0x1ec0d8 = 串偏移 → 0x348a34 "xboxlive_matchmaking_join_invite"（1 处引用） */
/* @0x15cfec andseq r12, lr, r4, ror #1 —— 池字 0x1ec0e4 = 串偏移 → 0x348a58 "xboxlive_matchmaking_join_session"（1 处引用） */
/* @0x15cff0 ldrsheq r12, [lr], -r0 —— 池字 0x1ec0f0 = 串偏移 → 0x348a7c "xboxlive_chat_add_user_to_channel"（1 处引用） */
/* @0x15cff4 ldrsheq r12, [lr], -r12 —— 池字 0x1ec0fc = 串偏移 → 0x348aa0 "xboxlive_chat_remove_user_from_channel"（1 处引用） */
/* @0x15cff8 andseq r12, lr, r12, lsl #2 —— 池字 0x1ec10c = 串偏移 → 0x348ac8 "xboxlive_chat_set_muted"（1 处引用） */
/* @0x15cffc andseq r12, lr, r8, lsl #2 —— 池字 0x1ec108 = 串偏移 → 0x348ae0 "xboxlive_set_service_configuration_id"（1 处引用） */
/* @0x15d000 andseq r12, lr, r12, lsl r1 —— 池字 0x1ec11c = 串偏移 → 0x348b08 "psn_get_leaderboard_score_range"（1 处引用） */
/* @0x15d004 andseq r12, lr, r4, lsr #2 —— 池字 0x1ec124 = 串偏移 → 0x348b28 "psn_default_user_name"（1 处引用） */
/* @0x15d008 andseq r12, lr, r0, lsr #2 —— 池字 0x1ec120 = 串偏移 → 0x348b40 "psn_name_for_pad"（1 处引用） */
/* @0x15d00c andseq r12, lr, r0, lsr #2 —— 池字 0x1ec120 = 串偏移 → 0x348b54 "psn_unlock_trophy"（1 处引用） */
/* @0x15d010 andseq r12, lr, r8, lsl r1 —— 池字 0x1ec118 = 串偏移 → 0x348b68 "psn_get_trophy_unlock_state"（1 处引用） */
/* @0x15d014 andseq r12, lr, r0, lsr #2 —— 池字 0x1ec120 = 串偏移 → 0x348b84 "psn_init_np_libs"（1 处引用） */
/* @0x15d018 andseq r12, lr, r12, lsl r1 —— 池字 0x1ec11c = 串偏移 → 0x348b98 "psn_exit_np_libs"（1 处引用） */
/* @0x15d01c andseq r12, lr, r8, lsl r1 —— 池字 0x1ec118 = 串偏移 → 0x348bac "psn_get_leaderboard_score"（1 处引用） */
/* @0x15d020 andseq r12, lr, r12, lsl r1 —— 池字 0x1ec11c = 串偏移 → 0x348bc8 "psn_post_leaderboard_score"（1 处引用） */
/* @0x15d024 andseq r12, lr, r0, lsr #2 —— 池字 0x1ec120 = 串偏移 → 0x348be4 "psn_post_leaderboard_score_comment"（1 处引用） */
/* @0x15d028 andseq r12, lr, r12, lsr #2 —— 池字 0x1ec12c = 串偏移 → 0x348c08 "psn_check_np_availability"（1 处引用） */
/* @0x15d02c andseq r12, lr, r0, lsr r1 —— 池字 0x1ec130 = 串偏移 → 0x348c24 "psn_tick_error_dialog"（1 处引用） */
/* @0x15d030 andseq r12, lr, r0, lsr r1 —— 池字 0x1ec130 = 串偏移 → 0x348c3c "psn_get_friends_scores"（1 处引用） */
/* @0x15d034 andseq r12, lr, r12, lsr #2 —— 池字 0x1ec12c = 串偏移 → 0x348c54 "psn_name_for_user"（1 处引用） */
/* @0x15d038 andseq r12, lr, r12, lsr #2 —— 池字 0x1ec12c = 串偏移 → 0x348c68 "psn_default_user"（1 处引用） */
/* @0x15d03c andseq r12, lr, r4, lsr #2 —— 池字 0x1ec124 = 串偏移 → 0x348c7c "psn_user_for_pad"（1 处引用） */
/* @0x15d040 andseq r12, lr, r4, lsr #2 —— 池字 0x1ec124 = 串偏移 → 0x348c90 "matchmaking_reset_create_params"（1 处引用） */
/* @0x15d044 andseq r12, lr, r12, lsr #2 —— 池字 0x1ec12c = 串偏移 → 0x348cb0 "matchmaking_add_create_param"（1 处引用） */
/* @0x15d048 andseq r12, lr, r4, lsr r1 —— 池字 0x1ec134 = 串偏移 → 0x348cd0 "matchmaking_session_create"（1 处引用） */
/* @0x15d04c andseq r12, lr, r4, lsr r1 —— 池字 0x1ec134 = 串偏移 → 0x348cec "matchmaking_session_get_users"（1 处引用） */
/* @0x15d050 andseq r12, lr, r12, lsr r1 —— 池字 0x1ec13c = 串偏移 → 0x348d0c "matchmaking_session_get_owner"（1 处引用） */
/* @0x15d054 andseq r12, lr, r4, asr #2 —— 池字 0x1ec144 = 串偏移 → 0x348d2c "matchmaking_session_set_closed"（1 处引用） */
/* @0x15d058 andseq r12, lr, r12, asr #2 —— 池字 0x1ec14c = 串偏移 → 0x348d4c "matchmaking_session_set_open"（1 处引用） */
/* @0x15d05c andseq r12, lr, r4, asr r1 —— 池字 0x1ec154 = 串偏移 → 0x348d6c "matchmaking_session_set_hidden"（1 处引用） */
/* @0x15d060 andseq r12, lr, r0, ror #2 —— 池字 0x1ec160 = 串偏移 → 0x348d8c "matchmaking_reset_find_params"（1 处引用） */
/* @0x15d064 andseq r12, lr, r8, ror #2 —— 池字 0x1ec168 = 串偏移 → 0x348dac "matchmaking_add_find_param"（1 处引用） */
/* @0x15d068 andseq r12, lr, r12, ror #2 —— 池字 0x1ec16c = 串偏移 → 0x348dc8 "matchmaking_session_find"（1 处引用） */
/* @0x15d06c andseq r12, lr, r12, ror #2 —— 池字 0x1ec16c = 串偏移 → 0x348de4 "matchmaking_session_join"（1 处引用） */
/* @0x15d070 andseq r12, lr, r0, ror r1 —— 池字 0x1ec170 = 串偏移 → 0x348e00 "matchmaking_session_leave"（1 处引用） */
/* @0x15d074 andseq r12, lr, r4, ror r1 —— 池字 0x1ec174 = 串偏移 → 0x348e1c "matchmaking_session_update"（1 处引用） */
/* @0x15d078 andseq r12, lr, r12, ror r1 —— 池字 0x1ec17c = 串偏移 → 0x348e38 "matchmaking_start"（1 处引用） */
/* @0x15d07c andseq r12, lr, r8, ror r1 —— 池字 0x1ec178 = 串偏移 → 0x348e4c "matchmaking_stop"（1 处引用） */
/* @0x15d080 andseq r12, lr, r0, ror r1 —— 池字 0x1ec170 = 串偏移 → 0x348e60 "matchmaking_session_invite_start"（1 处引用） */
/* @0x15d084 andseq r12, lr, r0, lsl #3 —— 池字 0x1ec180 = 串偏移 → 0x348e84 "matchmaking_send_invites_no_ui"（1 处引用） */
/* @0x15d088 andseq r12, lr, r8, lsl #3 —— 池字 0x1ec188 = 串偏移 → 0x348ea4 "matchmaking_send_invites"（1 处引用） */
/* @0x15d08c andseq r12, lr, r12, lsl #3 —— 池字 0x1ec18c = 串偏移 → 0x348ec0 "matchmaking_tick_invites"（1 处引用） */
/* @0x15d090 andseq r12, lr, r12, lsl #3 —— 池字 0x1ec18c = 串偏移 → 0x348edc "matchmaking_join_invite"（1 处引用） */
/* @0x15d094 mulseq lr, r0, r1 —— 池字 0x1ec190 = 串偏移 → 0x348ef4 "psn_np_check_plus"（1 处引用） */
/* @0x15d098 andseq r12, lr, r12, lsl #3 —— 池字 0x1ec18c = 串偏移 → 0x348f08 "psn_np_commerce_dialog_open"（1 处引用） */
/* @0x15d09c mulseq lr, r0, r1 —— 池字 0x1ec190 = 串偏移 → 0x348f24 "psn_np_commerce_dialog_tick"（1 处引用） */
/* @0x15d0a0 mulseq lr, r4, r1 —— 池字 0x1ec194 = 串偏移 → 0x348f40 "psn_np_notify_plus_feature"（1 处引用） */
/* @0x15d0a4 mulseq lr, r4, r1 —— 池字 0x1ec194 = 串偏移 → 0x348f5c "psn_set_content_restriction"（1 处引用） */
/* @0x15d0a8 mulseq lr, r12, r1 —— 池字 0x1ec19c = 串偏移 → 0x348f78 "psn_load_modules"（1 处引用） */
/* @0x15d0ac mulseq lr, r4, r1 —— 池字 0x1ec194 = 串偏移 → 0x348f8c "psn_get_avatar_url"（1 处引用） */
/* @0x15d0b0 mulseq lr, r4, r1 —— 池字 0x1ec194 = 串偏移 → 0x348fa0 "psn_get_tus_data"（1 处引用） */
/* @0x15d0b4 mulseq lr, r0, r1 —— 池字 0x1ec190 = 串偏移 → 0x348fb4 "psn_set_tus_data"（1 处引用） */
/* @0x15d0b8 andseq r12, lr, r12, lsl #3 —— 池字 0x1ec18c = 串偏移 → 0x348fc8 "psn_get_tus_variable"（1 处引用） */
/* @0x15d0bc andseq r12, lr, r12, lsl #3 —— 池字 0x1ec18c = 串偏移 → 0x348fe0 "psn_set_tus_variable"（1 处引用） */
/* @0x15d0c0 andseq r12, lr, r12, lsl #3 —— 池字 0x1ec18c = 串偏移 → 0x348ff8 "psn_delete_tus_data"（1 处引用） */
/* @0x15d0c4 andseq r12, lr, r8, lsl #3 —— 池字 0x1ec188 = 串偏移 → 0x34900c "psn_content_restriction_add"（1 处引用） */
/* @0x15d0c8 andseq r12, lr, r8, lsl #3 —— 池字 0x1ec188 = 串偏移 → 0x349028 "psn_net_check"（1 处引用） */
/* @0x15d0cc andseq r12, lr, r4, lsl #3 —— 池字 0x1ec184 = 串偏移 → 0x349038 "psn_setup_trophies"（1 处引用） */
/* @0x15d0d0 andseq r12, lr, r0, lsl #3 —— 池字 0x1ec180 = 串偏移 → 0x34904c "psn_tick"（1 处引用） */
/* @0x15d0d4 andseq r12, lr, r0, ror r1 —— 池字 0x1ec170 = 串偏移 → 0x349058 "psn_init_trophy"（1 处引用） */
/* @0x15d0d8 andseq r12, lr, r8, ror #2 —— 池字 0x1ec168 = 串偏移 → 0x349068 "psn_np_status"（1 处引用） */
/* @0x15d0dc andseq r12, lr, r0, ror #2 —— 池字 0x1ec160 = 串偏移 → 0x349078 "psn_show_error_dialog"（1 处引用） */
/* @0x15d0e0 andseq r12, lr, r4, ror #2 —— 池字 0x1ec164 = 串偏移 → 0x349090 "psn_check_free_space"（1 处引用） */
/* @0x15d0e4 andseq r12, lr, r4, ror #2 —— 池字 0x1ec164 = 串偏移 → 0x3490a8 "psn_get_entitlement_list"（1 处引用） */
/* @0x15d0e8 andseq r12, lr, r4, ror #2 —— 池字 0x1ec164 = 串偏移 → 0x3490c4 "video_open"（1 处引用） */
/* @0x15d0ec andseq r12, lr, r12, asr r1 —— 池字 0x1ec15c = 串偏移 → 0x3490d0 "video_close"（1 处引用） */
/* @0x15d0f0 andseq r12, lr, r0, asr r1 —— 池字 0x1ec150 = 串偏移 → 0x3490dc "video_draw"（1 处引用） */
/* @0x15d0f4 andseq r12, lr, r0, asr #2 —— 池字 0x1ec140 = 串偏移 → 0x3490e8 "video_set_volume"（1 处引用） */

