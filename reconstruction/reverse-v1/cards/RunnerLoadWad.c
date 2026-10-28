/* cally 逆向卡：RunnerLoadWad（原版 libyoyo.so，armv7）
 * @func 0x1df59c 0x1df5ec  size 84  21 条（17 条指令 + 0x1df5e0..0x1df5ec 4 个池字，池字被 objdump 译成
 *       eoreq/andseq，不是指令）
 * 级别: 正文（17 条指令全部落地：一次 trace、两处全局取参、一次尾跳；无分支、无循环、无错误处理，
 *             所以「全部指令都钉住」= 「全部语义都钉住」。open 只剩「那两个全局谁写」）
 * 符号: _Z13RunnerLoadWadv → int RunnerLoadWad()      ← **无参数**
 * ABI : softfp；push {r3, lr}（r3 是占位，为了让 sp 8 字节对齐，没有 sub sp）；结尾 pop {r3, lr} + b，
 *       即**尾跳**（tail call）LoadGameData —— 所以本函数的返回值**就是 LoadGameData 的返回值**，
 *       自己一条 mov r0 都没有。
 * 调用者: DoTheWork 0x2a16dc 的 0x2a16ec（唯一）；DoTheWork 拿它的返回值当「有没有加载成功」的判据，
 *         0 → 打 "Failed to load the game\n" 并返回 0，非 0 → Variable_Global_Init → PrepareGame → Run_Start。
 *         启动序：srand48(2101988) → **RunnerLoadWad** → PrepareGame → Run_Start。
 * 同层: LoadGameData 0x1ddce4（尾跳目标）、Console::Output（虚表 +0xc）
 *
 * ── 一句话 ─────────────────────────────────────────────────────────
 *   两件事：先朝控制台打一行 "LoadGameData()\n"，再把两个 .bss 全局（WAD 基址 + 字节数）当实参
 *   尾跳给 LoadGameData。它不打开文件、不检查魔数、不做任何失败处理 —— 名字叫 "LoadWad"，
 *   但**取 WAD 的动作不在这个函数里**。
 *
 * ── 逐段（地址即锚点）────────────────────────────────────────────
 *   0x1df5a0..0x1df5bc  取控制台对象并打印
 *       池字 0x210574（0x1df5e0）→ ldr r3,[pc,r3] 得 GOT 槽 0x3efb24，槽里是 .data.rel.ro 的
 *       控制台指针槽 0x3eb6b8，再解一层得实例（.bss 0x479d08）；obj->[0] 取虚表、[vtable+0xc] 取函数，
 *       r0 = 对象、r1 = 串 0x351a38 = "LoadGameData()\n" → blx。
 *       这条与 DoTheWork 里 PrepareGame()/Run_Start 的打印是**同一个槽、同一个虚表偏移**（该卡已钉），
 *       措辞也同构：打印的是「即将进入的函数名」。
 *   0x1df5c0..0x1df5d4  取两个实参
 *       池字 0x211744（0x1df5e8）→ GOT 0x3f0d14 → 全局 0x544b78 → r0（WAD 基址）
 *       池字 0x21173c（0x1df5ec）→ GOT 0x3f0d10 → 全局 0x544b74 → r1（WAD 字节数）
 *       两个全局紧邻（0x544b74、0x544b78），形状就是 {u32 size; void* data;}
 *   0x1df5d8..0x1df5dc  pop {r3, lr} → b LoadGameData(0x1ddce4)
 *       尾跳：不建帧、不保存返回地址，LoadGameData 的 return 直接回到 DoTheWork。
 *
 * ── 与 LoadGameData 的契约（跨卡一致，已核）────────────────────────
 *   · LoadGameData(void* pWAD, u32 size) 只吃「内存里的整份包」；本函数是它**唯一**的调用者，
 *     所以 0x544b78/0x544b74 这对全局就是 WAD 的唯一入口。
 *   · 返回 0 的两种情形（pWAD == NULL；出现未知块）都会让 DoTheWork 打 "Failed to load the game"；
 *     而「包长字段对不上 size-8」这种明显不是 WAD 的包，LoadGameData 反而返回 1 —— 本函数不补救。
 *   · 本函数**没有失败分支**（全函数只有 1 个 blx、1 个 b，没有条件跳转），失败判定全在下游。
 *
 * ── 这对全局的引用面（全 .so 扫过）──────────────────────────────────
 *   .rel.dyn 13,432 条 R_ARM_RELATIVE 里，指向 0x544b74 / 0x544b78 的重定位各只有一条，
 *   就是本函数的两个 GOT 槽（0x3f0d10 / 0x3f0d14）；.text 里也没有别处引用这两个池字
 *   （池字 0x21173c / 0x211744 各只出现一次，都在本函数）。⇒ 本函数是这两个全局**唯一**的读者。
 *
 * ── open ───────────────────────────────────────────────────────────
 *   1. 0x544b74/0x544b78 的**写入方**：本模块里没有第二个显式引用，说明写的代码要么经由别的模块/数据表，
 *      要么这对全局本身就是「外部装配好的输入」。未钉。
 *   2. 控制台实例的具体子类（0x479d08 的虚表在 .bss，构造期才写）——与 DoTheWork 卡同一条 open，
 *      静态只证到「槽 0x3eb6b8 + 虚表 +0xc」这一层。
 *   3. 0x544b74 到底是「文件字节数」还是「FORM 长度字段」：本函数只把它整字传给 LoadGameData，
 *      而 LoadGameData 用它和 size-8 比，所以语义上必须是**整份映像的字节数**。
 */

/* ── 逐条锚点（17 条指令 + 4 个池字）────────────────────────────── */
/* @0x1df59c push {r3, lr} —— 无帧：r3 占位，保证 sp 8 字节对齐 */
/* @0x1df5a0 ldr r3, [pc, #0x38] —— 池字 0x210574（GOT 相对偏移） */
/* @0x1df5a4 ldr r1, [pc, #0x38] —— 池字 0x172484（串偏移） */
/* @0x1df5a8 ldr r3, [pc, r3] —— GOT 0x3efb24 → 0x3eb6b8（控制台指针槽） */
/* @0x1df5ac add r1, pc, r1 —— 串址 = 0x1df5b4 + 0x172484 = 0x351a38 */
/* @0x1df5b0 ldr r0, [r3] —— r0 = 控制台对象 */
/* @0x1df5b4 ldr r3, [r0] —— obj->[0] = 虚表 */
/* @0x1df5b8 ldr r3, [r3, #0xc] —— [vtable+0xc] = Console::Output */
/* @0x1df5bc blx r3 —— Output("LoadGameData()\n") */
/* @0x1df5c0 ldr r2, [pc, #0x20] —— 池字 0x211744 */
/* @0x1df5c4 ldr r3, [pc, #0x20] —— 池字 0x21173c */
/* @0x1df5c8 ldr r2, [pc, r2] —— GOT 0x3f0d14 → 0x544b78（WAD 基址） */
/* @0x1df5cc ldr r3, [pc, r3] —— GOT 0x3f0d10 → 0x544b74（WAD 字节数） */
/* @0x1df5d0 ldr r0, [r2] —— arg0 = *(void**)0x544b78 */
/* @0x1df5d4 ldr r1, [r3] —— arg1 = *(u32*)0x544b74 */
/* @0x1df5d8 pop {r3, lr} —— 恢复 lr（尾跳用），r3 丢弃 */
/* @0x1df5dc b 0x1ddce4 <_Z12LoadGameDataPvj> —— 尾跳 LoadGameData：返回值直通 DoTheWork */
/* @0x1df5e0 eoreq r0, r1, r4, ror r5 —— 池字（非指令） */
/* @0x1df5e4 andseq r2, r7, r4, lsl #9 —— 池字（非指令） */
/* @0x1df5e8 eoreq r1, r1, r4, asr #14 —— 池字（非指令） */
/* @0x1df5ec eoreq r1, r1, r12, lsr r7 —— 池字（非指令） */
