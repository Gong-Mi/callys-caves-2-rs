/* cally 逆向卡：DLL_Call（原版 libyoyo.so，armv7）
 * @func 0x212b10 0x212d18  size 520  128 条（126 条真指令 + 2 个池字 @0x212d10/@0x212d14；
 *       0x212d08..0x212d0c 是 vldr d8 的 8 字节常量 0.0，索引未覆盖）
 * 级别: 正文（128/128 逐条落锚；RValue→C 拆包、两条转换循环、可转实数 tag 掩码、四路叶子分派、全部早退点的副作用全证）
 * 符号: _Z8DLL_CalliiP6RValueS0_ → DLL_Call(int id, int argc, RValue* args, RValue* result)
 *       返回值未定：函数体从不写 r0，四个出口都直接 b 到 0x212b4c 的收尾。
 * 导出: .dynsym 里 GLOBAL DEFAULT（公开 ABI，外部/扩展可调）。
 * 位置: 紧接 Call_Normal(0x211fa8..0x212b08) 之后。在已建索引的 95 个函数里没有调用方，
 *       但它是四个叶子的唯一已见调用方 —— 上游入口在索引范围之外。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────
 *   「按 id 调用」的 C 侧总闸：把 RValue* args 拆成 double[] + char*[] 两套 C 形参数组，
 *   再按 (argc, 表项 +0x10) 选四个叶子之一（Call_Normal / Call_Normal_std / Call_Real / Call_Real_std）。
 *
 * ── 与 DoCall / DoCallScript / DoCallLibrary 的分工（本卡重点之一）────────
 *   字节码侧：DoCall(0xe8b48) 的实参是 VM 栈上的 16 B RValue 串、argc 取 opcode 低 16 位；内建路 blx 80 B
 *   描述符表的 +0x40，脚本路走 Script_Data 并交给 DoCallScript(0xe8588) 压帧。
 *   本函数是**另一套世界**：C 形参、直接 blx 表项 +0xc、零 VM 帧、零 opcode。两条路唯一共享的约定是
 *   「RValue 是 16 B、tag 在 +0xc 高字节」，而本函数正是这条约定的转换点：
 *     tag ∈ {0,1,6,7,10,13}（掩码 0x24c3）→ YYGetReal(args,i) → double[i]；其它 tag（含 2/3/4/5/8/9/11/12/14/15）→ 直接写 0.0
 *     tag 3（指针）→ value 直接当 char*；tag 1（字符串）→ 再解一次引用（= 12 B 字符串头里的 data 指针）
 *   而 DoCallScript 这条路根本不拆 RValue —— 它把 RValue 串原样当实参交给执行器。这就是两套入口的实质差别。
 *   对象侧还有第三条：Call_RValue(0x249860) 处理「可调用 RValue」，走 Call_ScriptRef，最终仍进 VM 帧。
 *
 * ── 帧与缓冲布局（272 B = push 36 + vpush 8 + 228）────────────────────
 *   [sp+0x04] = result（r3，argc==0 的路径靠它把 r3 复原）
 *   [sp+0x08] = &strs 数组（sp+0x14）
 *   [sp+0x0c] = id（r5 被 argc 占用后的寄存处）
 *   [sp+0x14] = strs[17]（68 B）  —— memset 0，逐实参回填 char*
 *   [sp+0x58] = doubles[17]（136 B）—— memset 0，逐实参回填 double
 *   两个数组都是 17 槽，正好覆盖 argc ≤ 17；但本函数**不检查 argc 上限**（见坑 3）。
 *
 * ── 主流程 ────────────────────────────────────────────────────────────
 *   1. 结果清零（0x212b24..0x212b30）：result->[0x0] = result->[0x4] = result->[0xc] = 0
 *      ⇒ tag = 0（Real）、值 = 0.0。注意 **+0x8 不清**（三个字，不是四个）。
 *   2. 四道闸，任一不过就直接返回（result 保持 0.0，不调用任何东西）：
 *      id < 0                        → 0x212b34 blt
 *      id ≥ *(int*)0x755270          → 0x212b48 blt 不跳，直落 0x212b4c 返回
 *      argc != entry->[0x14]         → 0x212b78 bne（**严格相等**，多一个少一个都直接返回 0.0）
 *      entry->[0x4] == 0             → 0x212b84 beq
 *      其中前两道是两个相邻计数（0x755270 / 0x755274）；表对象本体是 0x755274 {count, entries@0x755278}。
 *   3. 两个 memset（0x212ba4 / 0x212bb4）后进入两条循环：
 *      循环 1（0x212be4..0x212c34）：doubles[i] = tag 在掩码内 ? YYGetReal(args,i) : 0.0（0.0 来自 vldr d8）
 *      循环 2（0x212c94..0x212cd8）：strs[i] = tag==3 ? args[i].value : (tag==1 && value ? *(char**)value : NULL)
 *      两个循环的上界都是 entry->[0x14]（= argc，已校验相等）。
 *   4. 分派（0x212c38..0x212c5c）：重取 entry->[0x10]，==1 → std 档，否则非 std 档；
 *      再按 cmp argc,#4：≤4 → Call_Normal(_std)（double[] + char*[] + result 三参），
 *                        >4 → Call_Real(_std)（double[] + result 两参，字符指针数组直接丢弃）。
 *   5. 收尾：0x212b4c 复原栈与 9 个 callee-saved 寄存器后返回；r0 从未被设置。
 *
 * ── 可核对的行为断言 ──────────────────────────────────────────────────
 *   · argc 必须**恰好等于** entry->[0x14]，否则静默返回 0.0（不报错、不调用）—— 这是本卡最容易看错的一处。
 *   · 早退时 result 已被清零，所以「没调用」与「调用返回 0」在结果上不可区分（都读到 0.0）。
 *   · 布尔/整数类实参（tag 7/10/13）与对象（tag 6）都走 YYGetReal；数组（2）、指针（3）、undefined（5）、
 *     null（12）等一律变 0.0 —— 但 tag 3 会同时把 value 当 char* 塞进 strs[]，两条通道互不干扰。
 *   · 字符串实参双重表示：double[] 里是 YYGetReal 的结果（字符串→数值），strs[] 里是 data 指针；
 *     哪个生效由表项 +0x18/+0x1c/+0x20/+0x24 的标志决定（叶子里按标志选寄存器）。
 *
 * ── 坑 ────────────────────────────────────────────────────────────────
 *   1. 结果只清 3 个字：+0x8 保留旧内容。叶子只写 [0]/[4] 与 tag，所以 +0x8 可能带着上一轮的值离开。
 *   2. `movge r2,#0` 的越界兜底（0x212c4c）是死代码，且形式错误：若真发生越界，紧接着的 ldr r2,[r2,#0x10] 会空指针读；
 *      实际靠 0x212b44 那道闸挡住。
 *   3. 无 argc 上限检查：两个数组各 17 槽，argc ≥ 18 会写出缓冲。当前由表项声明的 [0x14] 与
 *      Call_Real 的「argc-5 ≤ 11」共同约束（≤16），所以不可达；一旦表能声明 >17 个形参就会踩到。
 *   4. 字符串取值对 tag 1 解一次引用、对 tag 3 不解 —— 与 YYCreateString 造的 12 B 头
 *      {char* data(+0), int refcount(+4), int len(+8)} 完全吻合（见 Call_Normal 卡 0x212390 一节）。
 *
 * 结论：
 *   1. DLL_Call 是「RValue 世界 → C 形参世界」的唯一转换点，转换规则是 tag 掩码 0x24c3 + 两条独立通道。
 *   2. 叶子选择是二维的：(argc ≤ 4 ? Normal : Real) × (entry->[0x10] == 1 ? std : 非 std)。
 *   3. entry 的 +0x14 = 形参个数、+0x10 = std 档标记、+0xc = 可直接 blx 的指针、+0x18..+0x24 = 前 4 个形参的
 *      「是否按 char* 传」标志、+0x5c = 返回 tag —— 这六个字段在本卡里各自被至少一条指令钉住。
 * open:
 *   1. 0x755270 与 0x755274 两个相邻计数各是什么（容量 vs 个数？表 vs 脚本表？）。
 *   2. entry->[0x4]（被要求非零的那个指针）是什么：编译后的代码体？名字？缓存？
 *   3. 上游调用方（本函数在索引范围内无调用方）——谁按什么协议算 id/argc。
 *   4. argc 与 entry->[0x14] 不等的真实用途：是「防误用」还是某个 GML 内建（如 script_execute）的语义要求。
 */
/* ── 段 1 · 序言 / 结果清零 / 四道闸（0x212b10..0x212b84）── */
/* @0x212b10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x212b14 vpush {d8} */
/* @0x212b18 subs r5, r0, #0 */
/* @0x212b1c mov r7, r2 */
/* @0x212b20 sub sp, sp, #228 */
/* @0x212b24 mov r2, #0 */
/* @0x212b28 str r2, [r3, #0xc] */
/* @0x212b2c str r2, [r3] */
/* @0x212b30 str r2, [r3, #0x4] */
/* @0x212b34 blt 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212b38 ldr r0, [pc, #0x1d0] */
/* @0x212b3c ldr r0, [pc, r0] */
/* @0x212b40 ldr r0, [r0] */
/* @0x212b44 cmp r5, r0 */
/* @0x212b48 blt 0x212b58 <_Z8DLL_CalliiP6RValueS0_+0x48> */
/* @0x212b4c add sp, sp, #228 */
/* @0x212b50 vpop {d8} */
/* @0x212b54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x212b58 ldr r10, [pc, #0x1b4] */
/* @0x212b5c ldr r10, [pc, r10] */
/* @0x212b60 ldr r4, [r10] */
/* @0x212b64 cmp r5, r4 */
/* @0x212b68 ldrlt r2, [r10, #0x4] */
/* @0x212b6c ldrlt r2, [r2, r5, lsl #2] */
/* @0x212b70 ldr r11, [r2, #0x14] */
/* @0x212b74 cmp r11, r1 */
/* @0x212b78 bne 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212b7c ldr r2, [r2, #0x4] */
/* @0x212b80 cmp r2, #0 */
/* @0x212b84 beq 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* ── 段 2 · 两个 17 槽缓冲 + doubles 转换循环（0x212b88..0x212c34）── */
/* @0x212b88 add r8, sp, #88 */
/* @0x212b8c add r2, sp, #20 */
/* @0x212b90 mov r1, #0 */
/* @0x212b94 str r2, [sp, #0x8] */
/* @0x212b98 mov r0, r8 */
/* @0x212b9c mov r2, #136 */
/* @0x212ba0 str r3, [sp, #0x4] */
/* @0x212ba4 bl 0xb65b0 <memset@plt> */
/* @0x212ba8 add r0, sp, #20 */
/* @0x212bac mov r1, #0 */
/* @0x212bb0 mov r2, #68 */
/* @0x212bb4 bl 0xb65b0 <memset@plt> */
/* @0x212bb8 cmp r11, #0 */
/* @0x212bbc ldr r3, [sp, #0x4] */
/* @0x212bc0 ble 0x212c3c <_Z8DLL_CalliiP6RValueS0_+0x12c> */
/* @0x212bc4 str r5, [sp, #0xc] */
/* @0x212bc8 mov r4, #0 */
/* @0x212bcc mov r5, r11 */
/* @0x212bd0 mov r9, #1 */
/* @0x212bd4 mov r11, r7 */
/* @0x212bd8 vldr d8, [pc, #296] */
/* @0x212bdc mov r7, r8 */
/* @0x212be0 mov r6, r3 */
/* @0x212be4 b 0x212bfc <_Z8DLL_CalliiP6RValueS0_+0xec> */
/* @0x212be8 vstr d8, [r7] */
/* @0x212bec add r4, r4, #1 */
/* @0x212bf0 add r7, r7, #8 */
/* @0x212bf4 cmp r4, r5 */
/* @0x212bf8 beq 0x212c74 <_Z8DLL_CalliiP6RValueS0_+0x164> */
/* @0x212bfc add r1, r11, r4, lsl #4 */
/* @0x212c00 movw r2, #0x24c3 */
/* @0x212c04 ldr r1, [r1, #0xc] */
/* @0x212c08 bic r1, r1, #-16777216 */
/* @0x212c0c cmp r1, #13 */
/* @0x212c10 lsl r0, r9, r1 */
/* @0x212c14 and r2, r0, r2 */
/* @0x212c18 bhi 0x212be8 <_Z8DLL_CalliiP6RValueS0_+0xd8> */
/* @0x212c1c cmp r2, #0 */
/* @0x212c20 beq 0x212be8 <_Z8DLL_CalliiP6RValueS0_+0xd8> */
/* @0x212c24 mov r0, r11 */
/* @0x212c28 mov r1, r4 */
/* @0x212c2c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x212c30 strd r0, r1, [r7] */
/* @0x212c34 b 0x212bec <_Z8DLL_CalliiP6RValueS0_+0xdc> */
/* ── 段 3 · 四路分派：entry->[0x10]==1 → _std；argc>4 → Call_Real（0x212c38..0x212d04）── */
/* @0x212c38 ldr r4, [r10] */
/* @0x212c3c cmp r5, r4 */
/* @0x212c40 mov r0, r5 */
/* @0x212c44 mov r1, r8 */
/* @0x212c48 ldrlt r2, [r10, #0x4] */
/* @0x212c4c movge r2, #0 */
/* @0x212c50 ldrlt r2, [r2, r5, lsl #2] */
/* @0x212c54 ldr r2, [r2, #0x10] */
/* @0x212c58 cmp r2, #1 */
/* @0x212c5c beq 0x212ce8 <_Z8DLL_CalliiP6RValueS0_+0x1d8> */
/* @0x212c60 cmp r11, #4 */
/* @0x212c64 ble 0x212cdc <_Z8DLL_CalliiP6RValueS0_+0x1cc> */
/* @0x212c68 mov r2, r3 */
/* @0x212c6c bl 0x21161c <_Z9Call_RealiPdP6RValue> */
/* @0x212c70 b 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* ── 段 2b · strs[] 转换循环体（tag 3 直取 / tag 1 解一层引用 / 其它 NULL）── */
/* @0x212c74 mov r7, r11 */
/* @0x212c78 mov r11, r5 */
/* @0x212c7c mov r2, r7 */
/* @0x212c80 ldr r5, [sp, #0xc] */
/* @0x212c84 mov r3, r6 */
/* @0x212c88 add r7, r7, #12 */
/* @0x212c8c add r4, r2, r11, lsl #4 */
/* @0x212c90 add r12, sp, #16 */
/* @0x212c94 b 0x212cac <_Z8DLL_CalliiP6RValueS0_+0x19c> */
/* @0x212c98 add r2, r2, #16 */
/* @0x212c9c str r0, [r12, #0x4]! */
/* @0x212ca0 cmp r2, r4 */
/* @0x212ca4 add r7, r7, #16 */
/* @0x212ca8 beq 0x212c38 <_Z8DLL_CalliiP6RValueS0_+0x128> */
/* @0x212cac ldr r1, [r2, #0xc] */
/* @0x212cb0 mov r0, #0 */
/* @0x212cb4 cmp r1, #3 */
/* @0x212cb8 bic lr, r1, #-16777216 */
/* @0x212cbc ldreq r0, [r7, #-0xc] */
/* @0x212cc0 beq 0x212c98 <_Z8DLL_CalliiP6RValueS0_+0x188> */
/* @0x212cc4 cmp lr, #1 */
/* @0x212cc8 bne 0x212c98 <_Z8DLL_CalliiP6RValueS0_+0x188> */
/* @0x212ccc ldr r0, [r7, #-0xc] */
/* @0x212cd0 cmp r0, #0 */
/* @0x212cd4 ldrne r0, [r0] */
/* @0x212cd8 b 0x212c98 <_Z8DLL_CalliiP6RValueS0_+0x188> */
/* @0x212cdc add r2, sp, #20 */
/* @0x212ce0 bl 0x211fa8 <_Z11Call_NormaliPdPPKcP6RValue> */
/* @0x212ce4 b 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212ce8 cmp r11, #4 */
/* @0x212cec ble 0x212cfc <_Z8DLL_CalliiP6RValueS0_+0x1ec> */
/* @0x212cf0 mov r2, r3 */
/* @0x212cf4 bl 0x21012c <_Z13Call_Real_stdiPdP6RValue> */
/* @0x212cf8 b 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212cfc add r2, sp, #20 */
/* @0x212d00 bl 0x210ab8 <_Z15Call_Normal_stdiPdPPKcP6RValue> */
/* @0x212d04 b 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* ── 段 4 · 字面池：0x001de878 → GOT[0x3f13bc]=.bss 0x755270；0x001de854 → GOT[0x3f13b8]=0x755274 ── */
/* @0x212d10 andseq lr, sp, r8, ror r8 */
/* @0x212d14 andseq lr, sp, r4, asr r8 */
