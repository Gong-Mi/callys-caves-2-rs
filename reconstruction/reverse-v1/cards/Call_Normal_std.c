/* cally 逆向卡：Call_Normal_std（原版 libyoyo.so，armv7）
 * @func 0x210ab8 0x211618  size 2916  729 条（727 条真指令 + 尾部 2 个字面池字）
 * 级别: 正文（729/729 逐条落锚；与 Call_Normal 的逐字同构已按机器码证明：729 个字里只有 3 个不同，且 3 个都是重定位）
 * 符号: _Z15Call_Normal_stdiPdPPKcP6RValue → Call_Normal_std(int id, double* args, const char** strs, RValue* result)
 *       形参与返回口径与 Call_Normal 完全相同（返回类型未定：调用方 DLL_Call 不读 r0）。
 * 导出: .dynsym 里 GLOBAL DEFAULT；与 Call_Normal 并列成一对，供 DLL_Call 按表项 +0x10 二选一。
 * 位置: 0x210ab8..0x211610 是代码，紧跟 2 个池字；前邻 Call_Real_std(0x21012c)，后邻 Call_Real(0x21161c)。
 *       与孪生体 Call_Normal(0x211fa8) 的地址差恒为 0x14F0（下面所有「孪生体 x」都是 +0x14F0）。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────
 *   本函数是 Call_Normal 的**孪生副本**：同一段代码、不同的链接名。它承担 std 档（entry->[0x10] == 1）
 *   的 ≤4 实参调用，代码含义请直接看 Call_Normal 卡；本卡只负责证明「两者到底差什么」。
 *
 * ── 差异到底在哪（本卡的全部任务）──────────────────────────────────────
 *   逐字比对（index 与 .so 双路）：729 个字里只有 3 个不同 ——
 *     1) 0x210ea0 的 b：两边目标都是 0xe5258（YYCreateString），只因相对位移不同而编码不同
 *        （本卡 eafb50ec，孪生体 eafb4bb0，差值恰为 0x14F0）；
 *     2) 尾部池字 0x211614 = 0x001e08ec（孪生体 0x001df3fc）、0x211618 = 0x001e08cc（孪生体 0x001df3dc），
 *        每组差值都是 0x14F0 = 两函数地址差 ⇒ 解出的 GOT 槽是同一对：
 *        0x3f13b4（中止字节 .bss 0x75527c）/ 0x3f13b8（表对象 0x755274 + entries 0x755278）。
 *   ⇒ 除上述 3 个字外**逐字节相同**；本卡的键公式、62 个 case 体的装填序列、返回口径与 Call_Normal 一一对应。
 *   下表是本卡自己这一份的键 → case 底址（= 孪生体地址 - 0x14F0）：
 *   argc=0 : 1→0x211138 2→0x2110a4
 *   argc=1 : 11→0x211080 12→0x210e7c 21→0x211240 22→0x2110fc
 *   argc=2 : 111→0x21116c 112→0x210d3c 121→0x2114ec 122→0x2114d4
 *            211→0x211228 212→0x210f40 221→0x211518 222→0x211504
 *   argc=3 : 1111→0x2114b4 1112→0x210c80 1121→0x211384 1122→0x211364 1211→0x2110b4 1212→0x210f7c 1221→0x21158c 1222→0x211574
 *            2111→0x211444 2112→0x210d84 2121→0x2111e4 2122→0x2111c4 2211→0x211184 2212→0x210f10 2221→0x2115b8 2222→0x2115a4
 *   argc=4 : 11111→0x211464 11112→0x210bdc 11121→0x21141c 11122→0x2113f4 11211→0x2110d4
 *            11212→0x21100c 11221→0x211278 11222→0x211254 12111→0x21119c 12112→0x210dd8
 *            12121→0x21133c 12122→0x211314 12211→0x211148 12212→0x210ec8 12221→0x211550
 *            12222→0x21152c 21111→0x21148c 21112→0x210ce4 21121→0x2113cc 21122→0x2113a4
 *            21211→0x211110 21212→0x210fc0 21221→0x2115f4 21222→0x2115cc 22111→0x211204
 *            22112→0x210e34 22121→0x2112c4 22122→0x21129c 22211→0x210c04 22212→0x211058
 *            22221→0x211300 22222→0x2112ec
 *
 * ── std / 非 std 的语义边界 ────────────────────────────────────────────
 *   1. 选择点唯一：DLL_Call 的 0x212c54 读 entry->[0x10]，==1 → 走 _std 两支（0x212ce8 的 Call_Real_std 或
 *      0x212cfc 的 Call_Normal_std）；否则走非 std 两支（0x212cdc 的 Call_Normal / 0x212c60 的 Call_Real）。
 *   2. 因为两份代码等价，std 在这条路上**不改变任何寄存器或栈约定**，也不改变实参类型判定
 *      （类型仍来自表项 +0x18/+0x1c/+0x20/+0x24 的零/非零）。
 *   3. 所以「std」更可能是**表项/编译器档位**的标记（同一函数的两份导出），而不是两套调用协议：
 *      两份都只 blx entry->[0xc]、都不压 VM 帧、都不进 DoCallScript、都不碰 80 B 内建描述符表。
 *   4. >4 实参那一族可以当反向对照：Call_Real(0x21161c) / Call_Real_std(0x21012c) 同为 2444 B、611 条，
 *      但块顺序被重排、指令多重集只差「1 条 cmp+beq 折成 1 条 b」+ 2 个池字 ⇒ 也是同一逻辑的两次生成。
 *      （该对照只做了整体反汇对比，没有逐条卡，属旁证。）
 *
 * ── 与 DoCall / DoCallScript / DoCallLibrary 的分工（一句话）────────────
 *   DoCall/DoCallGML/DoCallLibrary/DoCallScript 属**字节码侧**：实参是 VM 栈上的 RValue 串、类型在 tag 里、
 *   内建走 80 B 描述符表（fn@+0x40）、脚本走 Script_Data、压帧只由 DoCallScript(0xe8588) 做。
 *   本函数属**C 侧**：实参已被 DLL_Call 拆成 double[] + char*[]，直接 blx 表项 +0xc，没有 VM 帧、没有 RValue tag 判定。
 *   本函数的全部外部调用只有两处：表项 +0xc（62 次）与 YYCreateString(0xe5258)（字符串返回尾调）。
 *
 * 结论：
 *   1. std 与非 std 在 argc ≤ 4 这条路上是**同一段机器码的两个名字**；差异只在表项 +0x10 的路由。
 *   2. 用「std 就少做某件事」来描述这对函数是错的 —— 它们的字面差异只有 3 个重定位字。
 * open:
 *   1. 谁把 entry->[0x10] 置 1、为什么需要两份等价导出（热补丁入口？两份独立产物？）。
 *   2. 若某天两档需要真正分道（例如 std 档改走 varargs），现有证据无法预测改动点 —— 需上游/其他构建对照。
 */
/* ── 段 1 · 序言 / 中止字节 / 表项兜取（孪生体 0x211fa8..0x211fe4）── */
/* @0x210ab8 ldr r12, [pc, #0xb54] */
/* @0x210abc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x210ac0 ldr r12, [pc, r12] */
/* @0x210ac4 sub sp, sp, #20 */
/* @0x210ac8 mov r4, r1 */
/* @0x210acc ldrb r12, [r12] */
/* @0x210ad0 mov r7, r2 */
/* @0x210ad4 mov r6, r3 */
/* @0x210ad8 cmp r12, #0 */
/* @0x210adc bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210ae0 ldr r3, [pc, #0xb30] */
/* @0x210ae4 ldr r3, [pc, r3] */
/* @0x210ae8 ldr r2, [r3] */
/* @0x210aec cmp r0, r2 */
/* @0x210af0 ldrlt r3, [r3, #0x4] */
/* @0x210af4 ldrlt r12, [r3, r0, lsl #2] */
/* ── 段 2 · 键构造：argc 截断 + 每参 real/string 十进制位（孪生体 0x211fe8..0x212060）── */
/* @0x210af8 ldr r1, [r12, #0x5c] */
/* @0x210afc ldr r2, [r12, #0x14] */
/* @0x210b00 cmp r1, #0 */
/* @0x210b04 movne r3, #2 */
/* @0x210b08 moveq r3, #1 */
/* @0x210b0c cmp r2, #0 */
/* @0x210b10 ble 0x210b74 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xbc> */
/* @0x210b14 ldr r0, [r12, #0x18] */
/* @0x210b18 cmp r0, #0 */
/* @0x210b1c addeq r3, r3, #10 */
/* @0x210b20 addne r3, r3, #20 */
/* @0x210b24 cmp r2, #1 */
/* @0x210b28 beq 0x210b74 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xbc> */
/* @0x210b2c ldr r0, [r12, #0x1c] */
/* @0x210b30 cmp r0, #0 */
/* @0x210b34 addeq r3, r3, #100 */
/* @0x210b38 addne r3, r3, #200 */
/* @0x210b3c cmp r2, #2 */
/* @0x210b40 beq 0x210b74 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xbc> */
/* @0x210b44 ldr r0, [r12, #0x20] */
/* @0x210b48 cmp r0, #0 */
/* @0x210b4c addeq r3, r3, #1000 */
/* @0x210b50 addne r3, r3, #2000 */
/* @0x210b54 cmp r2, #3 */
/* @0x210b58 beq 0x210b74 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xbc> */
/* @0x210b5c ldr r2, [r12, #0x24] */
/* @0x210b60 cmp r2, #0 */
/* @0x210b64 addeq r3, r3, #9984 */
/* @0x210b68 addne r3, r3, #19968 */
/* @0x210b6c addeq r3, r3, #16 */
/* @0x210b70 addne r3, r3, #32 */
/* ── 段 3 · 62 路二分派发：键 → case 底址（孪生体 0x212064..0x21236c）── */
/* @0x210b74 movw r2, #0x2b67 */
/* @0x210b78 cmp r3, r2 */
/* @0x210b7c str r1, [r6, #0xc] */
/* @0x210b80 beq 0x211464 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x9ac> */
/* @0x210b84 ble 0x210c28 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x170> */
/* @0x210b88 movw r2, #0x5277 */
/* @0x210b8c cmp r3, r2 */
/* @0x210b90 beq 0x21148c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x9d4> */
/* @0x210b94 bgt 0x210ca0 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x1e8> */
/* @0x210b98 movw r2, #0x2f4f */
/* @0x210b9c cmp r3, r2 */
/* @0x210ba0 beq 0x21119c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x6e4> */
/* @0x210ba4 bgt 0x210da4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x2ec> */
/* @0x210ba8 sub r2, r2, #900 */
/* @0x210bac cmp r3, r2 */
/* @0x210bb0 beq 0x2110d4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x61c> */
/* @0x210bb4 bgt 0x210fe8 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x530> */
/* @0x210bb8 movw r2, #0x2b71 */
/* @0x210bbc cmp r3, r2 */
/* @0x210bc0 beq 0x21141c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x964> */
/* @0x210bc4 add r2, r2, #1 */
/* @0x210bc8 cmp r3, r2 */
/* @0x210bcc beq 0x2113f4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x93c> */
/* @0x210bd0 movw r2, #0x2b68 */
/* @0x210bd4 cmp r3, r2 */
/* @0x210bd8 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210bdc ldrd r2, r3, [r4, #16] */
/* @0x210be0 ldrd r0, r1, [r4, #24] */
/* @0x210be4 strd r2, r3, [sp] */
/* @0x210be8 strd r0, r1, [sp, #8] */
/* @0x210bec ldrd r0, r1, [r4] */
/* @0x210bf0 ldr r12, [r12, #0xc] */
/* @0x210bf4 ldrd r2, r3, [r4, #8] */
/* @0x210bf8 blx r12 */
/* @0x210bfc mov r1, r0 */
/* @0x210c00 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210c04 ldr lr, [r7, #0xc] */
/* @0x210c08 ldrd r0, r1, [r4] */
/* @0x210c0c ldmib r7, {r2, r3} */
/* @0x210c10 str lr, [sp] */
/* @0x210c14 ldr r12, [r12, #0xc] */
/* @0x210c18 blx r12 */
/* @0x210c1c stm r6, {r0, r1} */
/* ── 段 3b · 普通返回（孪生体 0x212110）── */
/* @0x210c20 add sp, sp, #20 */
/* @0x210c24 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x210c28 movw r2, #0x457 */
/* @0x210c2c cmp r3, r2 */
/* @0x210c30 beq 0x2114b4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x9fc> */
/* @0x210c34 ble 0x210d0c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x254> */
/* @0x210c38 movw r2, #0x83f */
/* @0x210c3c cmp r3, r2 */
/* @0x210c40 beq 0x211444 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x98c> */
/* @0x210c44 cmp r3, #2112 */
/* @0x210c48 bge 0x210d54 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x29c> */
/* @0x210c4c sub r2, r2, #900 */
/* @0x210c50 cmp r3, r2 */
/* @0x210c54 beq 0x2110b4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x5fc> */
/* @0x210c58 bgt 0x210f58 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x4a0> */
/* @0x210c5c movw r2, #0x461 */
/* @0x210c60 cmp r3, r2 */
/* @0x210c64 beq 0x211384 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x8cc> */
/* @0x210c68 add r2, r2, #1 */
/* @0x210c6c cmp r3, r2 */
/* @0x210c70 beq 0x211364 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x8ac> */
/* @0x210c74 movw r2, #0x458 */
/* @0x210c78 cmp r3, r2 */
/* @0x210c7c bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210c80 ldrd r2, r3, [r4, #16] */
/* @0x210c84 ldrd r0, r1, [r4] */
/* @0x210c88 strd r2, r3, [sp] */
/* @0x210c8c ldr r12, [r12, #0xc] */
/* @0x210c90 ldrd r2, r3, [r4, #8] */
/* @0x210c94 blx r12 */
/* @0x210c98 mov r1, r0 */
/* @0x210c9c b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210ca0 movw r2, #0x565f */
/* @0x210ca4 cmp r3, r2 */
/* @0x210ca8 beq 0x211204 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x74c> */
/* @0x210cac bgt 0x210e00 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x348> */
/* @0x210cb0 sub r2, r2, #900 */
/* @0x210cb4 cmp r3, r2 */
/* @0x210cb8 beq 0x211110 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x658> */
/* @0x210cbc bgt 0x210f9c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x4e4> */
/* @0x210cc0 movw r2, #0x5281 */
/* @0x210cc4 cmp r3, r2 */
/* @0x210cc8 beq 0x2113cc <_Z15Call_Normal_stdiPdPPKcP6RValue+0x914> */
/* @0x210ccc add r2, r2, #1 */
/* @0x210cd0 cmp r3, r2 */
/* @0x210cd4 beq 0x2113a4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x8ec> */
/* @0x210cd8 movw r2, #0x5278 */
/* @0x210cdc cmp r3, r2 */
/* @0x210ce0 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210ce4 ldrd r2, r3, [r4, #16] */
/* @0x210ce8 ldr lr, [r7, #0xc] */
/* @0x210cec ldrd r0, r1, [r4] */
/* @0x210cf0 strd r2, r3, [sp] */
/* @0x210cf4 ldrd r2, r3, [r4, #8] */
/* @0x210cf8 str lr, [sp, #0x8] */
/* @0x210cfc ldr r12, [r12, #0xc] */
/* @0x210d00 blx r12 */
/* @0x210d04 mov r1, r0 */
/* @0x210d08 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210d0c cmp r3, #111 */
/* @0x210d10 beq 0x21116c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x6b4> */
/* @0x210d14 ble 0x210e58 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3a0> */
/* @0x210d18 cmp r3, #211 */
/* @0x210d1c beq 0x211228 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x770> */
/* @0x210d20 bgt 0x210f28 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x470> */
/* @0x210d24 cmp r3, #121 */
/* @0x210d28 beq 0x2114ec <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa34> */
/* @0x210d2c cmp r3, #122 */
/* @0x210d30 beq 0x2114d4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa1c> */
/* @0x210d34 cmp r3, #112 */
/* @0x210d38 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210d3c ldrd r0, r1, [r4] */
/* @0x210d40 ldr r12, [r12, #0xc] */
/* @0x210d44 ldrd r2, r3, [r4, #8] */
/* @0x210d48 blx r12 */
/* @0x210d4c mov r1, r0 */
/* @0x210d50 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210d54 movw r2, #0x8a3 */
/* @0x210d58 cmp r3, r2 */
/* @0x210d5c beq 0x211184 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x6cc> */
/* @0x210d60 bgt 0x210eec <_Z15Call_Normal_stdiPdPPKcP6RValue+0x434> */
/* @0x210d64 movw r2, #0x849 */
/* @0x210d68 cmp r3, r2 */
/* @0x210d6c beq 0x2111e4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x72c> */
/* @0x210d70 add r2, r2, #1 */
/* @0x210d74 cmp r3, r2 */
/* @0x210d78 beq 0x2111c4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x70c> */
/* @0x210d7c cmp r3, #2112 */
/* @0x210d80 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210d84 ldr lr, [r7, #0x8] */
/* @0x210d88 ldrd r0, r1, [r4] */
/* @0x210d8c ldrd r2, r3, [r4, #8] */
/* @0x210d90 str lr, [sp] */
/* @0x210d94 ldr r12, [r12, #0xc] */
/* @0x210d98 blx r12 */
/* @0x210d9c mov r1, r0 */
/* @0x210da0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210da4 movw r2, #0x2fb3 */
/* @0x210da8 cmp r3, r2 */
/* @0x210dac beq 0x211148 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x690> */
/* @0x210db0 bgt 0x210ea4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3ec> */
/* @0x210db4 movw r2, #0x2f59 */
/* @0x210db8 cmp r3, r2 */
/* @0x210dbc beq 0x21133c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x884> */
/* @0x210dc0 add r2, r2, #1 */
/* @0x210dc4 cmp r3, r2 */
/* @0x210dc8 beq 0x211314 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x85c> */
/* @0x210dcc movw r2, #0x2f50 */
/* @0x210dd0 cmp r3, r2 */
/* @0x210dd4 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210dd8 ldrd r2, r3, [r4, #24] */
/* @0x210ddc ldr lr, [r7, #0x8] */
/* @0x210de0 ldrd r0, r1, [r4] */
/* @0x210de4 strd r2, r3, [sp, #8] */
/* @0x210de8 ldrd r2, r3, [r4, #8] */
/* @0x210dec str lr, [sp] */
/* @0x210df0 ldr r12, [r12, #0xc] */
/* @0x210df4 blx r12 */
/* @0x210df8 mov r1, r0 */
/* @0x210dfc b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210e00 movw r2, #0x56c3 */
/* @0x210e04 cmp r3, r2 */
/* @0x210e08 beq 0x210c04 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x14c> */
/* @0x210e0c bgt 0x211034 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x57c> */
/* @0x210e10 movw r2, #0x5669 */
/* @0x210e14 cmp r3, r2 */
/* @0x210e18 beq 0x2112c4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x80c> */
/* @0x210e1c add r2, r2, #1 */
/* @0x210e20 cmp r3, r2 */
/* @0x210e24 beq 0x21129c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x7e4> */
/* @0x210e28 movw r2, #0x5660 */
/* @0x210e2c cmp r3, r2 */
/* @0x210e30 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210e34 ldr r5, [r7, #0x8] */
/* @0x210e38 ldr lr, [r7, #0xc] */
/* @0x210e3c ldrd r0, r1, [r4] */
/* @0x210e40 ldrd r2, r3, [r4, #8] */
/* @0x210e44 stm sp, {r5, lr} */
/* @0x210e48 ldr r12, [r12, #0xc] */
/* @0x210e4c blx r12 */
/* @0x210e50 mov r1, r0 */
/* @0x210e54 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210e58 cmp r3, #11 */
/* @0x210e5c beq 0x211080 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x5c8> */
/* @0x210e60 ble 0x211094 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x5dc> */
/* @0x210e64 cmp r3, #21 */
/* @0x210e68 beq 0x211240 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x788> */
/* @0x210e6c cmp r3, #22 */
/* @0x210e70 beq 0x2110fc <_Z15Call_Normal_stdiPdPPKcP6RValue+0x644> */
/* @0x210e74 cmp r3, #12 */
/* @0x210e78 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210e7c ldrd r0, r1, [r4] */
/* @0x210e80 ldr r3, [r12, #0xc] */
/* @0x210e84 blx r3 */
/* @0x210e88 mov r1, r0 */
/* ── 段 4 · 字符串返回尾调：NULL 静默返回，否则尾调 YYCreateString(0xe5258) ── */
/* @0x210e8c cmp r1, #0 */
/* @0x210e90 beq 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210e94 mov r0, r6 */
/* @0x210e98 add sp, sp, #20 */
/* @0x210e9c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x210ea0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* ── 段 5 · case 体群（孪生体 0x212394..0x212b00）── */
/* @0x210ea4 movw r2, #0x2fbd */
/* @0x210ea8 cmp r3, r2 */
/* @0x210eac beq 0x211550 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa98> */
/* @0x210eb0 add r2, r2, #1 */
/* @0x210eb4 cmp r3, r2 */
/* @0x210eb8 beq 0x21152c <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa74> */
/* @0x210ebc movw r2, #0x2fb4 */
/* @0x210ec0 cmp r3, r2 */
/* @0x210ec4 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210ec8 ldrd r0, r1, [r4, #24] */
/* @0x210ecc ldr r2, [r7, #0x4] */
/* @0x210ed0 ldr r3, [r7, #0x8] */
/* @0x210ed4 strd r0, r1, [sp] */
/* @0x210ed8 ldrd r0, r1, [r4] */
/* @0x210edc ldr r12, [r12, #0xc] */
/* @0x210ee0 blx r12 */
/* @0x210ee4 mov r1, r0 */
/* @0x210ee8 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210eec movw r2, #0x8ad */
/* @0x210ef0 cmp r3, r2 */
/* @0x210ef4 beq 0x2115b8 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xb00> */
/* @0x210ef8 add r2, r2, #1 */
/* @0x210efc cmp r3, r2 */
/* @0x210f00 beq 0x2115a4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xaec> */
/* @0x210f04 movw r2, #0x8a4 */
/* @0x210f08 cmp r3, r2 */
/* @0x210f0c bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210f10 ldrd r0, r1, [r4] */
/* @0x210f14 ldr r12, [r12, #0xc] */
/* @0x210f18 ldmib r7, {r2, r3} */
/* @0x210f1c blx r12 */
/* @0x210f20 mov r1, r0 */
/* @0x210f24 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210f28 cmp r3, #221 */
/* @0x210f2c beq 0x211518 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa60> */
/* @0x210f30 cmp r3, #222 */
/* @0x210f34 beq 0x211504 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa4c> */
/* @0x210f38 cmp r3, #212 */
/* @0x210f3c bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210f40 ldrd r0, r1, [r4] */
/* @0x210f44 ldr r3, [r12, #0xc] */
/* @0x210f48 ldr r2, [r7, #0x4] */
/* @0x210f4c blx r3 */
/* @0x210f50 mov r1, r0 */
/* @0x210f54 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210f58 movw r2, #0x4c5 */
/* @0x210f5c cmp r3, r2 */
/* @0x210f60 beq 0x21158c <_Z15Call_Normal_stdiPdPPKcP6RValue+0xad4> */
/* @0x210f64 add r2, r2, #1 */
/* @0x210f68 cmp r3, r2 */
/* @0x210f6c beq 0x211574 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xabc> */
/* @0x210f70 movw r2, #0x4bc */
/* @0x210f74 cmp r3, r2 */
/* @0x210f78 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210f7c ldrd r8, r9, [r4, #16] */
/* @0x210f80 ldrd r0, r1, [r4] */
/* @0x210f84 ldr r2, [r7, #0x4] */
/* @0x210f88 strd r8, r9, [sp] */
/* @0x210f8c ldr r3, [r12, #0xc] */
/* @0x210f90 blx r3 */
/* @0x210f94 mov r1, r0 */
/* @0x210f98 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210f9c movw r2, #0x52e5 */
/* @0x210fa0 cmp r3, r2 */
/* @0x210fa4 beq 0x2115f4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xb3c> */
/* @0x210fa8 add r2, r2, #1 */
/* @0x210fac cmp r3, r2 */
/* @0x210fb0 beq 0x2115cc <_Z15Call_Normal_stdiPdPPKcP6RValue+0xb14> */
/* @0x210fb4 movw r2, #0x52dc */
/* @0x210fb8 cmp r3, r2 */
/* @0x210fbc bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210fc0 ldr r3, [r7, #0xc] */
/* @0x210fc4 ldrd r0, r1, [r4, #16] */
/* @0x210fc8 ldr r2, [r7, #0x4] */
/* @0x210fcc strd r0, r1, [sp] */
/* @0x210fd0 ldrd r0, r1, [r4] */
/* @0x210fd4 str r3, [sp, #0x8] */
/* @0x210fd8 ldr r3, [r12, #0xc] */
/* @0x210fdc blx r3 */
/* @0x210fe0 mov r1, r0 */
/* @0x210fe4 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210fe8 movw r2, #0x2bd5 */
/* @0x210fec cmp r3, r2 */
/* @0x210ff0 beq 0x211278 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x7c0> */
/* @0x210ff4 add r2, r2, #1 */
/* @0x210ff8 cmp r3, r2 */
/* @0x210ffc beq 0x211254 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x79c> */
/* @0x211000 movw r2, #0x2bcc */
/* @0x211004 cmp r3, r2 */
/* @0x211008 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21100c ldrd r0, r1, [r4, #16] */
/* @0x211010 ldrd r8, r9, [r4, #24] */
/* @0x211014 ldr r2, [r7, #0x4] */
/* @0x211018 strd r0, r1, [sp] */
/* @0x21101c strd r8, r9, [sp, #8] */
/* @0x211020 ldrd r0, r1, [r4] */
/* @0x211024 ldr r3, [r12, #0xc] */
/* @0x211028 blx r3 */
/* @0x21102c mov r1, r0 */
/* @0x211030 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211034 movw r2, #0x56cd */
/* @0x211038 cmp r3, r2 */
/* @0x21103c beq 0x211300 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x848> */
/* @0x211040 add r2, r2, #1 */
/* @0x211044 cmp r3, r2 */
/* @0x211048 beq 0x2112ec <_Z15Call_Normal_stdiPdPPKcP6RValue+0x834> */
/* @0x21104c movw r2, #0x56c4 */
/* @0x211050 cmp r3, r2 */
/* @0x211054 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211058 ldrd r4, r5, [r4] */
/* @0x21105c ldr r1, [r7, #0xc] */
/* @0x211060 ldmib r7, {r2, r3} */
/* @0x211064 mov r0, r4 */
/* @0x211068 str r1, [sp] */
/* @0x21106c mov r1, r5 */
/* @0x211070 ldr r12, [r12, #0xc] */
/* @0x211074 blx r12 */
/* @0x211078 mov r1, r0 */
/* @0x21107c b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211080 ldr r3, [r12, #0xc] */
/* @0x211084 ldrd r0, r1, [r4] */
/* @0x211088 blx r3 */
/* @0x21108c stm r6, {r0, r1} */
/* @0x211090 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211094 cmp r3, #1 */
/* @0x211098 beq 0x211138 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x680> */
/* @0x21109c cmp r3, #2 */
/* @0x2110a0 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2110a4 ldr r3, [r12, #0xc] */
/* @0x2110a8 blx r3 */
/* @0x2110ac mov r1, r0 */
/* @0x2110b0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2110b4 ldrd r8, r9, [r4, #16] */
/* @0x2110b8 ldr r2, [r7, #0x4] */
/* @0x2110bc ldrd r0, r1, [r4] */
/* @0x2110c0 strd r8, r9, [sp] */
/* @0x2110c4 ldr r3, [r12, #0xc] */
/* @0x2110c8 blx r3 */
/* @0x2110cc stm r6, {r0, r1} */
/* @0x2110d0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2110d4 ldrd r0, r1, [r4, #16] */
/* @0x2110d8 ldrd r8, r9, [r4, #24] */
/* @0x2110dc ldr r2, [r7, #0x4] */
/* @0x2110e0 strd r0, r1, [sp] */
/* @0x2110e4 strd r8, r9, [sp, #8] */
/* @0x2110e8 ldrd r0, r1, [r4] */
/* @0x2110ec ldr r3, [r12, #0xc] */
/* @0x2110f0 blx r3 */
/* @0x2110f4 stm r6, {r0, r1} */
/* @0x2110f8 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2110fc ldr r3, [r12, #0xc] */
/* @0x211100 ldr r0, [r7] */
/* @0x211104 blx r3 */
/* @0x211108 mov r1, r0 */
/* @0x21110c b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211110 ldr r3, [r7, #0xc] */
/* @0x211114 ldrd r0, r1, [r4, #16] */
/* @0x211118 ldr r2, [r7, #0x4] */
/* @0x21111c strd r0, r1, [sp] */
/* @0x211120 ldrd r0, r1, [r4] */
/* @0x211124 str r3, [sp, #0x8] */
/* @0x211128 ldr r3, [r12, #0xc] */
/* @0x21112c blx r3 */
/* @0x211130 stm r6, {r0, r1} */
/* @0x211134 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211138 ldr r3, [r12, #0xc] */
/* @0x21113c blx r3 */
/* @0x211140 stm r6, {r0, r1} */
/* @0x211144 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211148 ldrd r0, r1, [r4, #24] */
/* @0x21114c ldr r2, [r7, #0x4] */
/* @0x211150 ldr r3, [r7, #0x8] */
/* @0x211154 strd r0, r1, [sp] */
/* @0x211158 ldrd r0, r1, [r4] */
/* @0x21115c ldr r12, [r12, #0xc] */
/* @0x211160 blx r12 */
/* @0x211164 stm r6, {r0, r1} */
/* @0x211168 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21116c ldr r12, [r12, #0xc] */
/* @0x211170 ldrd r0, r1, [r4] */
/* @0x211174 ldrd r2, r3, [r4, #8] */
/* @0x211178 blx r12 */
/* @0x21117c stm r6, {r0, r1} */
/* @0x211180 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211184 ldr r12, [r12, #0xc] */
/* @0x211188 ldrd r0, r1, [r4] */
/* @0x21118c ldmib r7, {r2, r3} */
/* @0x211190 blx r12 */
/* @0x211194 stm r6, {r0, r1} */
/* @0x211198 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21119c ldrd r2, r3, [r4, #24] */
/* @0x2111a0 ldr lr, [r7, #0x8] */
/* @0x2111a4 ldrd r0, r1, [r4] */
/* @0x2111a8 strd r2, r3, [sp, #8] */
/* @0x2111ac ldrd r2, r3, [r4, #8] */
/* @0x2111b0 str lr, [sp] */
/* @0x2111b4 ldr r12, [r12, #0xc] */
/* @0x2111b8 blx r12 */
/* @0x2111bc stm r6, {r0, r1} */
/* @0x2111c0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2111c4 ldr r1, [r7, #0x8] */
/* @0x2111c8 ldrd r2, r3, [r4, #8] */
/* @0x2111cc ldr r0, [r7] */
/* @0x2111d0 str r1, [sp] */
/* @0x2111d4 ldr r1, [r12, #0xc] */
/* @0x2111d8 blx r1 */
/* @0x2111dc mov r1, r0 */
/* @0x2111e0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2111e4 ldr r1, [r7, #0x8] */
/* @0x2111e8 ldrd r2, r3, [r4, #8] */
/* @0x2111ec ldr r0, [r7] */
/* @0x2111f0 str r1, [sp] */
/* @0x2111f4 ldr r1, [r12, #0xc] */
/* @0x2111f8 blx r1 */
/* @0x2111fc stm r6, {r0, r1} */
/* @0x211200 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211204 ldr r5, [r7, #0x8] */
/* @0x211208 ldr lr, [r7, #0xc] */
/* @0x21120c ldrd r0, r1, [r4] */
/* @0x211210 ldrd r2, r3, [r4, #8] */
/* @0x211214 stm sp, {r5, lr} */
/* @0x211218 ldr r12, [r12, #0xc] */
/* @0x21121c blx r12 */
/* @0x211220 stm r6, {r0, r1} */
/* @0x211224 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211228 ldr r3, [r12, #0xc] */
/* @0x21122c ldr r2, [r7, #0x4] */
/* @0x211230 ldrd r0, r1, [r4] */
/* @0x211234 blx r3 */
/* @0x211238 stm r6, {r0, r1} */
/* @0x21123c b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211240 ldr r3, [r12, #0xc] */
/* @0x211244 ldr r0, [r7] */
/* @0x211248 blx r3 */
/* @0x21124c stm r6, {r0, r1} */
/* @0x211250 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211254 ldrd r2, r3, [r4, #24] */
/* @0x211258 ldr r1, [r7, #0x4] */
/* @0x21125c ldr r0, [r7] */
/* @0x211260 strd r2, r3, [sp] */
/* @0x211264 ldrd r2, r3, [r4, #16] */
/* @0x211268 ldr r12, [r12, #0xc] */
/* @0x21126c blx r12 */
/* @0x211270 mov r1, r0 */
/* @0x211274 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211278 ldrd r2, r3, [r4, #24] */
/* @0x21127c ldr r0, [r7] */
/* @0x211280 ldr r1, [r7, #0x4] */
/* @0x211284 strd r2, r3, [sp] */
/* @0x211288 ldrd r2, r3, [r4, #16] */
/* @0x21128c ldr r12, [r12, #0xc] */
/* @0x211290 blx r12 */
/* @0x211294 stm r6, {r0, r1} */
/* @0x211298 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21129c ldr r1, [r7, #0xc] */
/* @0x2112a0 ldr lr, [r7, #0x8] */
/* @0x2112a4 ldrd r2, r3, [r4, #8] */
/* @0x2112a8 ldr r0, [r7] */
/* @0x2112ac str lr, [sp] */
/* @0x2112b0 str r1, [sp, #0x4] */
/* @0x2112b4 ldr r1, [r12, #0xc] */
/* @0x2112b8 blx r1 */
/* @0x2112bc mov r1, r0 */
/* @0x2112c0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2112c4 ldr r1, [r7, #0xc] */
/* @0x2112c8 ldr lr, [r7, #0x8] */
/* @0x2112cc ldrd r2, r3, [r4, #8] */
/* @0x2112d0 ldr r0, [r7] */
/* @0x2112d4 str lr, [sp] */
/* @0x2112d8 str r1, [sp, #0x4] */
/* @0x2112dc ldr r1, [r12, #0xc] */
/* @0x2112e0 blx r1 */
/* @0x2112e4 stm r6, {r0, r1} */
/* @0x2112e8 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2112ec ldm r7, {r0, r1, r2, r3} */
/* @0x2112f0 ldr r12, [r12, #0xc] */
/* @0x2112f4 blx r12 */
/* @0x2112f8 mov r1, r0 */
/* @0x2112fc b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211300 ldr r12, [r12, #0xc] */
/* @0x211304 ldm r7, {r0, r1, r2, r3} */
/* @0x211308 blx r12 */
/* @0x21130c stm r6, {r0, r1} */
/* @0x211310 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211314 ldr r1, [r7, #0x8] */
/* @0x211318 ldrd r2, r3, [r4, #24] */
/* @0x21131c ldr r0, [r7] */
/* @0x211320 strd r2, r3, [sp, #8] */
/* @0x211324 ldrd r2, r3, [r4, #8] */
/* @0x211328 str r1, [sp] */
/* @0x21132c ldr r1, [r12, #0xc] */
/* @0x211330 blx r1 */
/* @0x211334 mov r1, r0 */
/* @0x211338 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x21133c ldr r1, [r7, #0x8] */
/* @0x211340 ldrd r2, r3, [r4, #24] */
/* @0x211344 ldr r0, [r7] */
/* @0x211348 strd r2, r3, [sp, #8] */
/* @0x21134c ldrd r2, r3, [r4, #8] */
/* @0x211350 str r1, [sp] */
/* @0x211354 ldr r1, [r12, #0xc] */
/* @0x211358 blx r1 */
/* @0x21135c stm r6, {r0, r1} */
/* @0x211360 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211364 ldrd r8, r9, [r4, #16] */
/* @0x211368 ldr r0, [r7] */
/* @0x21136c ldrd r2, r3, [r4, #8] */
/* @0x211370 strd r8, r9, [sp] */
/* @0x211374 ldr r1, [r12, #0xc] */
/* @0x211378 blx r1 */
/* @0x21137c mov r1, r0 */
/* @0x211380 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211384 ldrd r8, r9, [r4, #16] */
/* @0x211388 ldr r0, [r7] */
/* @0x21138c ldrd r2, r3, [r4, #8] */
/* @0x211390 strd r8, r9, [sp] */
/* @0x211394 ldr r1, [r12, #0xc] */
/* @0x211398 blx r1 */
/* @0x21139c stm r6, {r0, r1} */
/* @0x2113a0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2113a4 ldr r1, [r7, #0xc] */
/* @0x2113a8 ldrd r2, r3, [r4, #16] */
/* @0x2113ac ldr r0, [r7] */
/* @0x2113b0 strd r2, r3, [sp] */
/* @0x2113b4 ldrd r2, r3, [r4, #8] */
/* @0x2113b8 str r1, [sp, #0x8] */
/* @0x2113bc ldr r1, [r12, #0xc] */
/* @0x2113c0 blx r1 */
/* @0x2113c4 mov r1, r0 */
/* @0x2113c8 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2113cc ldr r1, [r7, #0xc] */
/* @0x2113d0 ldrd r2, r3, [r4, #16] */
/* @0x2113d4 ldr r0, [r7] */
/* @0x2113d8 strd r2, r3, [sp] */
/* @0x2113dc ldrd r2, r3, [r4, #8] */
/* @0x2113e0 str r1, [sp, #0x8] */
/* @0x2113e4 ldr r1, [r12, #0xc] */
/* @0x2113e8 blx r1 */
/* @0x2113ec stm r6, {r0, r1} */
/* @0x2113f0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2113f4 ldrd r2, r3, [r4, #16] */
/* @0x2113f8 ldrd r8, r9, [r4, #24] */
/* @0x2113fc ldr r0, [r7] */
/* @0x211400 strd r2, r3, [sp] */
/* @0x211404 strd r8, r9, [sp, #8] */
/* @0x211408 ldr r1, [r12, #0xc] */
/* @0x21140c ldrd r2, r3, [r4, #8] */
/* @0x211410 blx r1 */
/* @0x211414 mov r1, r0 */
/* @0x211418 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x21141c ldrd r2, r3, [r4, #16] */
/* @0x211420 ldrd r8, r9, [r4, #24] */
/* @0x211424 ldr r0, [r7] */
/* @0x211428 strd r2, r3, [sp] */
/* @0x21142c strd r8, r9, [sp, #8] */
/* @0x211430 ldrd r2, r3, [r4, #8] */
/* @0x211434 ldr r1, [r12, #0xc] */
/* @0x211438 blx r1 */
/* @0x21143c stm r6, {r0, r1} */
/* @0x211440 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211444 ldr lr, [r7, #0x8] */
/* @0x211448 ldrd r0, r1, [r4] */
/* @0x21144c ldrd r2, r3, [r4, #8] */
/* @0x211450 str lr, [sp] */
/* @0x211454 ldr r12, [r12, #0xc] */
/* @0x211458 blx r12 */
/* @0x21145c stm r6, {r0, r1} */
/* @0x211460 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211464 ldrd r2, r3, [r4, #16] */
/* @0x211468 ldrd r0, r1, [r4, #24] */
/* @0x21146c strd r2, r3, [sp] */
/* @0x211470 strd r0, r1, [sp, #8] */
/* @0x211474 ldrd r0, r1, [r4] */
/* @0x211478 ldr r12, [r12, #0xc] */
/* @0x21147c ldrd r2, r3, [r4, #8] */
/* @0x211480 blx r12 */
/* @0x211484 stm r6, {r0, r1} */
/* @0x211488 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21148c ldrd r2, r3, [r4, #16] */
/* @0x211490 ldr lr, [r7, #0xc] */
/* @0x211494 ldrd r0, r1, [r4] */
/* @0x211498 strd r2, r3, [sp] */
/* @0x21149c ldrd r2, r3, [r4, #8] */
/* @0x2114a0 str lr, [sp, #0x8] */
/* @0x2114a4 ldr r12, [r12, #0xc] */
/* @0x2114a8 blx r12 */
/* @0x2114ac stm r6, {r0, r1} */
/* @0x2114b0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2114b4 ldrd r2, r3, [r4, #16] */
/* @0x2114b8 ldrd r0, r1, [r4] */
/* @0x2114bc strd r2, r3, [sp] */
/* @0x2114c0 ldr r12, [r12, #0xc] */
/* @0x2114c4 ldrd r2, r3, [r4, #8] */
/* @0x2114c8 blx r12 */
/* @0x2114cc stm r6, {r0, r1} */
/* @0x2114d0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2114d4 ldr r1, [r12, #0xc] */
/* @0x2114d8 ldr r0, [r7] */
/* @0x2114dc ldrd r2, r3, [r4, #8] */
/* @0x2114e0 blx r1 */
/* @0x2114e4 mov r1, r0 */
/* @0x2114e8 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2114ec ldr r1, [r12, #0xc] */
/* @0x2114f0 ldr r0, [r7] */
/* @0x2114f4 ldrd r2, r3, [r4, #8] */
/* @0x2114f8 blx r1 */
/* @0x2114fc stm r6, {r0, r1} */
/* @0x211500 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211504 ldm r7, {r0, r1} */
/* @0x211508 ldr r3, [r12, #0xc] */
/* @0x21150c blx r3 */
/* @0x211510 mov r1, r0 */
/* @0x211514 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211518 ldr r3, [r12, #0xc] */
/* @0x21151c ldm r7, {r0, r1} */
/* @0x211520 blx r3 */
/* @0x211524 stm r6, {r0, r1} */
/* @0x211528 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21152c ldrd r2, r3, [r4, #24] */
/* @0x211530 ldr r1, [r7, #0x4] */
/* @0x211534 ldr r0, [r7] */
/* @0x211538 strd r2, r3, [sp] */
/* @0x21153c ldr r2, [r7, #0x8] */
/* @0x211540 ldr r3, [r12, #0xc] */
/* @0x211544 blx r3 */
/* @0x211548 mov r1, r0 */
/* @0x21154c b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211550 ldrd r2, r3, [r4, #24] */
/* @0x211554 ldr r0, [r7] */
/* @0x211558 ldr r1, [r7, #0x4] */
/* @0x21155c strd r2, r3, [sp] */
/* @0x211560 ldr r2, [r7, #0x8] */
/* @0x211564 ldr r3, [r12, #0xc] */
/* @0x211568 blx r3 */
/* @0x21156c stm r6, {r0, r1} */
/* @0x211570 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211574 ldm r7, {r0, r1} */
/* @0x211578 ldr r12, [r12, #0xc] */
/* @0x21157c ldrd r2, r3, [r4, #16] */
/* @0x211580 blx r12 */
/* @0x211584 mov r1, r0 */
/* @0x211588 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x21158c ldr r12, [r12, #0xc] */
/* @0x211590 ldm r7, {r0, r1} */
/* @0x211594 ldrd r2, r3, [r4, #16] */
/* @0x211598 blx r12 */
/* @0x21159c stm r6, {r0, r1} */
/* @0x2115a0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2115a4 ldm r7, {r0, r1, r2} */
/* @0x2115a8 ldr r3, [r12, #0xc] */
/* @0x2115ac blx r3 */
/* @0x2115b0 mov r1, r0 */
/* @0x2115b4 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2115b8 ldr r3, [r12, #0xc] */
/* @0x2115bc ldm r7, {r0, r1, r2} */
/* @0x2115c0 blx r3 */
/* @0x2115c4 stm r6, {r0, r1} */
/* @0x2115c8 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2115cc ldrd r4, r5, [r4, #16] */
/* @0x2115d0 ldr r3, [r7, #0xc] */
/* @0x2115d4 ldm r7, {r0, r1} */
/* @0x2115d8 mov r2, r4 */
/* @0x2115dc str r3, [sp] */
/* @0x2115e0 mov r3, r5 */
/* @0x2115e4 ldr r12, [r12, #0xc] */
/* @0x2115e8 blx r12 */
/* @0x2115ec mov r1, r0 */
/* @0x2115f0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2115f4 ldr lr, [r7, #0xc] */
/* @0x2115f8 ldrd r2, r3, [r4, #16] */
/* @0x2115fc ldm r7, {r0, r1} */
/* @0x211600 str lr, [sp] */
/* @0x211604 ldr r12, [r12, #0xc] */
/* @0x211608 blx r12 */
/* @0x21160c stm r6, {r0, r1} */
/* @0x211610 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* ── 段 6 · 字面池（0x001e08ec → GOT[0x3f13b4]；0x001e08cc → GOT[0x3f13b8]）── */
/* @0x211614 andseq r0, lr, r12, ror #17 */
/* @0x211618 andseq r0, lr, r12, asr #17 */
