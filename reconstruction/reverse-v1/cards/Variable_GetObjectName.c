/* cally 逆向卡：Variable_GetObjectName（原版 libyoyo.so，armv7）
 * @func 0x1f3f8c 0x1f40cc  size 320  80 条（71 条指令 + 9 条字面量池字，池 0x1f40a8..0x1f40c8）
 * 级别: 正文（80/80 逐条锚定；四段分派、六个出口、三个 .bss 全局全落地；"第二参是死参"与
 *            "失败一律返回同一字面量"两条结论都是逐指令扫出来的；open 3 条见文末）
 * 符号: _Z22Variable_GetObjectNameii → const char* Variable_GetObjectName(int id, int varid)
 *
 * ── 一句话 ──────────────────────────────────────────────────────────
 *   「给一个 GML 实例号/对象索引，回答它属于哪个**对象**（返回对象名字符串）」。
 *   它是 Variable_GetValue 的姊妹函数：共用同一张 ms_ID2InstanceE、同一条房间实例链、同一个 Run_Room、
 *   同一个失败标志字节 0x75505c —— 但**只回答名字**，一个 RValue 都不碰，也不写任何表。
 *
 * ── 两个 int 的角色 ────────────────────────────────────────────────
 *   p1 = id    ：与 Variable_GetValue 的 p1 完全同域（-3 all｜0..99999 对象索引｜>99999 实例 id｜其余负数失败）
 *   p2 = varid ：★ **死参**。0x1f3f8c..0x1f3fb4 之间没有任何指令读 r1；0x1f3fb8 `ldr r1,[r3,#4]` 直接把它覆盖成
 *                哈希 mask。DoPush 0xea5d4 确实按 (id, 变量号) 两参调用，但第二参在本构建里一次都用不上。
 *
 * ── 四段分派（与 Variable_GetValue 的 p1 分派逐条同构）────────────────
 *   id == -3        0x1f4010..0x1f4054  Run_Room→[0x80] 实例链，沿 +0x178 找第一个 +0x68/+0x69 皆 0 的实例，
 *                                       取它的 +0x7c（对象索引）→ Object_Name
 *   id < 0（≠-3）   0x1f4084            → "<unknown_object>"，**不置失败标志**
 *   id > 99999      0x1f3fb0..0x1f400c  ms_ID2InstanceE 按完整 32 位 id 命中 → 若 +0x68 != 0 直接占位串；
 *                                       否则 Object_Name([inst+0x7c])
 *   0 ≤ id ≤ 99999  0x1f4058            **不查表**，直接把 id 当对象索引交给 Object_Name
 *                                       （r0 一路没被动过；0x1f3fac 的 ble 直接跳到那条 `b Object_Name`）
 *   ⇒ 注意 0x1f4054 与 0x1f4058 是两条相邻指令：只有「查到实例」的两条路会先执行 `ldr r0,[r3,#0x7c]`，
 *     「id 就是对象索引」那条路跳过它直接尾跳 —— 这是本函数唯一一个把三个分支合流在同一处的设计。
 *
 * ── 返回值约定 ────────────────────────────────────────────────────
 *   返回 const char*，**永不返回 NULL**，也永不返回栈上缓冲：
 *     成功 = Object_Name(...) 的返回值（尾跳）：对象名串 = CObjectGM+0x14（Object_Name 0x19eda8 `ldr r0,[r3,#0x14]`）
 *     失败 = 六个出口全部指向同一个 .rodata 字面量 0x3527e4 = "<unknown_object>"
 *            （0x1f4004 / 0x1f405c / 0x1f4068 / 0x1f4084 / 0x1f4090 / 0x1f409c 六处 pc 相对加法；
 *              池 9 个字里 3 个是 GOT 槽偏移（0x001f9c90 / 0x001f9914 / 0x001f9cec，配各自 pc 得
 *              0x3edc4c / 0x3ed930 / 0x3edd68），6 个是字符串偏移（0x0015e7d4 / 0x0015e77c / 0x0015e764 /
 *              0x0015e754 / 0x0015e748 / 0x0015e73c），配各自 pc 后**全部落 0x3527e4**；六条都逐个复算过）
 *   ⇒ 失败与成功的**唯一**可区分信号是字符串内容，外加 0x75505c 这一个字节：本函数只在
 *     「id == -3 且房间链上无活实例」这一条路置 0x75505c = 1（0x1f407c），其余五条失败路**不置**。
 *     调用方若只看标志，会把「id<0」「实例已销毁」「id 不在表里」当成"没出错"。
 *   ⇒ Object_Name 自己还有一层兜底：g_ObjectHash 未命中时返回 0x330ac8 = "<undefined>"（0x19edb0/0x19edbc/0x19edc8
 *     三个出口同址），所以本函数的返回值域实际是 {对象名, "<undefined>", "<unknown_object>"}。
 *
 * ── 调用点（7 处 bl，全部当 %s 用）────────────────────────────────
 *   DoPop 0xe6df8（id 传 -10，即 `mvn r0,#9`：故意走「负数 → 占位串」快路）、DoPop 0xe7978；
 *   DoPush 0xe9fd4 / 0xea5d4 / 0xeb05c / 0xeb0d8 / 0xeb258。
 *   其中 0xea5d4 已逐指令确认：返回值进 VMError 的第二个变参，格式串 0x334964
 *   "Variable %s.%s(%d, %d) not set before reading it." —— 即「对象名.变量名」里的**对象名**。
 *   这也是判断本函数语义最硬的一条：它不是"取变量的对象"，而是"给报错文案提供对象名"。
 *
 * ── 全局寻址：GOT 0x3f1c58 家族（三处 pc 相对取址，全部 R_ARM_RELATIVE）──
 *   0x1f3fb4 (pc 0x1f3fbc + 0x001f9c90) → 槽 0x3edc4c → 0x536f28  ms_ID2InstanceE（结构体本体）
 *   0x1f4014 (pc 0x1f401c + 0x001f9914) → 槽 0x3ed930 → 0x54298c  Run_Room（指针变量）
 *   0x1f4074 (pc 0x1f407c + 0x001f9cec) → 槽 0x3edd68 → 0x75505c  1 B 失败标志（与 Variable_GetValue 同一个字节）
 *
 * ── 已证（每条都指到指令）──────────────────────────────────────────
 *   1. 第二参 varid 一次都没被读（0x1f3f90 只保存 r0；0x1f3fb8 起 r1 全是临时量）。
 *   2. id == -3 走房间实例链：Run_Room→+0x80（0x1f4018/0x1f401c），next 在 +0x178（0x1f403c，先取后判）。
 *   3. id > 99999 走 ms_ID2InstanceE：mask@+4、桶 8 B、节点 {next@+4, id@+8, inst@+0xc}（0x1f3fb8..0x1f3fec）。
 *   4. 0..99999 不查表，直接把 id 当对象索引（0x1f3fac → 0x1f4058，r0 未被改写）。
 *   5. 六个失败出口同一字面量 0x3527e4 "<unknown_object>"；只有 0x1f4068 那条置 0x75505c = 1（0x1f407c）。
 *   6. 成功路径恒为尾跳 Object_Name(0x19ed54)，参数是 inst->[0x7c]（对象索引，SetObjectIndex 0x193260 写的就是它）。
 *
 * ── open ───────────────────────────────────────────────────────────
 *   1. varid 为什么保留：静态侧只能证"本构建不读"，不能证"原版设计上无用"（可能是早期签名残留，或给
 *      将来的「按变量名反查对象」留的位）。DoPush 传的是变量号，DoPop 两处传的第 2 参未逐一解码。
 *   2. 失败时六个出口只有一个置标志，「标志 = 失败」这个等式**只在 id==-3 那条路上成立**；
 *      其余五条路要调用方自己比字符串。这是否是原版有意为之（占位串本身可比较）未证。
 *   3. Object_Name 的三条 "<undefined>" 出口判据（表未命中 / 值为空 / 索引 -1？）属 Object_Name 的范围，本卡未展开。
 */

/* ═══ 段 1 · 序言 + 三条比较（0x1f3f8c..0x1f3fac）═══ */
/* @0x1f3f8c cmn r0, #3 */  —— r0+3==0 ⇔ id == -3（all）
/* @0x1f3f90 mov r2, r0 */  —— ★ 保存 id 副本到 r2；此后所有比较都用 r2，r0 留作返回值用
/* @0x1f3f94 beq 0x1f4010 <_Z22Variable_GetObjectNameii+0x84> */  —— → all 分支
/* @0x1f3f98 cmp r0, #0 */
/* @0x1f3f9c blt 0x1f4084 <_Z22Variable_GetObjectNameii+0xf8> */  —— id < 0 且 ≠ -3 → 占位串（不置标志）
/* @0x1f3fa0 movw r3, #0x869f */  —— r3 = 0x1869f
/* @0x1f3fa4 movt r3, #0x1 */  —— 99999：对象索引 / 实例 id 分界
/* @0x1f3fa8 cmp r0, r3 */
/* @0x1f3fac ble 0x1f4058 <_Z22Variable_GetObjectNameii+0xcc> */  —— id ≤ 99999 → 0x1f4058 的 `b Object_Name`（r0 仍是 id）
/* ═══ 段 2 · 实例 id 分支（id > 99999）：ms_ID2InstanceE（0x1f3fb0..0x1f400c）═══
 *   与 Variable_GetValue 段 2 同构，唯一差别：命中后只判 +0x68（skip），不判 +0x69。 */
/* @0x1f3fb0 ldr r3, [pc, #0xf0] */  —— 池 0x1f40a8 = 0x001f9c90
/* @0x1f3fb4 ldr r3, [pc, r3] */  —— pc 0x1f3fbc + 0x1f9c90 = 0x3edc4c → 槽内 0x536f28（ms_ID2InstanceE 本体，一次解引用）
/* @0x1f3fb8 ldr r1, [r3, #0x4] */  —— ★ mask —— 第二参 r1 在这里被覆盖，此前一次都没被读
/* @0x1f3fbc ldr r3, [r3] */  —— buckets
/* @0x1f3fc0 and r1, r0, r1 */  —— idx = id & mask
/* @0x1f3fc4 ldr r3, [r3, r1, lsl #3] */  —— bucket 8 B {head@0, tail@4} → head
/* @0x1f3fc8 cmp r3, #0 */
/* @0x1f3fcc bne 0x1f3fe0 <_Z22Variable_GetObjectNameii+0x54> */  —— 非空 → 比 key
/* @0x1f3fd0 b 0x1f4090 <_Z22Variable_GetObjectNameii+0x104> */  —— 空桶 → 0x1f4090 占位串
/* @0x1f3fd4 ldr r3, [r3, #0x4] */  —— next（+4）
/* @0x1f3fd8 cmp r3, #0 */
/* @0x1f3fdc beq 0x1f405c <_Z22Variable_GetObjectNameii+0xd0> */  —— 链尾 → 0x1f405c 占位串
/* @0x1f3fe0 ldr r1, [r3, #0x8] */  —— node->id
/* @0x1f3fe4 cmp r2, r1 */  —— 用保存的副本 r2 比（r0 得留着当返回值）
/* @0x1f3fe8 bne 0x1f3fd4 <_Z22Variable_GetObjectNameii+0x48> */  —— 撞桶 → 继续
/* @0x1f3fec ldr r3, [r3, #0xc] */  —— node->instance
/* @0x1f3ff0 cmp r3, #0 */
/* @0x1f3ff4 beq 0x1f409c <_Z22Variable_GetObjectNameii+0x110> */  —— 空值 → 0x1f409c 占位串
/* @0x1f3ff8 ldrb r2, [r3, #0x68] */  —— ★ r2 被复用（id 到此已无用）
/* @0x1f3ffc cmp r2, #0 */
/* @0x1f4000 beq 0x1f4054 <_Z22Variable_GetObjectNameii+0xc8> */  —— 活实例 → 0x1f4054 取 +0x7c
/* @0x1f4004 ldr r0, [pc, #0xa0] */  —— 池 0x1f40ac = 0x0015e7d4
/* @0x1f4008 add r0, pc, r0 */  —— pc 0x1f4010 + 0x15e7d4 = 0x3527e4 "<unknown_object>"
/* @0x1f400c bx lr */  —— 已销毁（+0x68≠0）→ 占位串，不置标志
/* ═══ 段 3 · all 分支（id == -3）：房间实例链第一个活实例（0x1f4010..0x1f4054）═══ */
/* @0x1f4010 ldr r3, [pc, #0x98] */  —— 池 0x1f40b0 = 0x001f9914
/* @0x1f4014 ldr r3, [pc, r3] */  —— pc 0x1f401c + 0x1f9914 = 0x3ed930 → Run_Room（指针变量）
/* @0x1f4018 ldr r3, [r3] */  —— CRoom*
/* @0x1f401c ldr r3, [r3, #0x80] */  —— 房间实例链头（与 Variable_GetValue 0x1f3f18 同一字段）
/* @0x1f4020 cmp r3, #0 */
/* @0x1f4024 bne 0x1f4038 <_Z22Variable_GetObjectNameii+0xac> */  —— 非空 → 进判定
/* @0x1f4028 b 0x1f4068 <_Z22Variable_GetObjectNameii+0xdc> */  —— 空房间 → 0x1f4068（置标志 + 占位串）
/* @0x1f402c cmp r2, #0 */  —— r2 = 上一条取的 next，测空
/* @0x1f4030 mov r3, r2 */  —— r3 = next
/* @0x1f4034 beq 0x1f4068 <_Z22Variable_GetObjectNameii+0xdc> */  —— 链尾 → 0x1f4068
/* @0x1f4038 ldrb r1, [r3, #0x68] */
/* @0x1f403c ldr r2, [r3, #0x178] */  —— ★ 先取 next 再判存活
/* @0x1f4040 cmp r1, #0 */
/* @0x1f4044 bne 0x1f402c <_Z22Variable_GetObjectNameii+0xa0> */  —— skip → 前进
/* @0x1f4048 ldrb r1, [r3, #0x69] */
/* @0x1f404c cmp r1, #0 */
/* @0x1f4050 bne 0x1f402c <_Z22Variable_GetObjectNameii+0xa0> */  —— deactivated → 前进
/* @0x1f4054 ldr r0, [r3, #0x7c] */  —— ★ inst->[0x7c] = 对象索引（SetObjectIndex 0x193260 写的就是这个字段）
/* ═══ 段 4 · 合流点：尾跳 Object_Name（0x1f4058）═══ */
/* @0x1f4058 b 0x19ed54 <_Z11Object_Namei> */  —— 尾跳 Object_Name(int)；「id 就是对象索引」那条路也从 0x1f3fac 跳到这里，此时 r0 == id
/* ═══ 段 5 · 五个「占位串」出口（0x1f405c..0x1f40a4）═══
 *   0x1f405c 哈希链走空 / 0x1f4068 all 无活实例（唯一置标志）/ 0x1f4084 id<0 /
 *   0x1f4090 值为空 / 0x1f409c 实例已销毁。五段代码形状完全一样：ldr 偏移 → add pc → bx lr。 */
/* @0x1f405c ldr r0, [pc, #0x50] */  —— 池 0x1f40b4 = 0x0015e77c
/* @0x1f4060 add r0, pc, r0 */  —— pc 0x1f4068 + 0x15e77c = 0x3527e4（哈希链走空）
/* @0x1f4064 bx lr */
/* @0x1f4068 ldr r3, [pc, #0x48] */  —— 池 0x1f40b8 = 0x001f9cec
/* @0x1f406c mov r2, #1 */  —— 1：失败标志值
/* @0x1f4070 ldr r0, [pc, #0x44] */  —— 池 0x1f40bc = 0x0015e764
/* @0x1f4074 ldr r3, [pc, r3] */  —— pc 0x1f407c + 0x1f9cec = 0x3edd68 → &0x75505c
/* @0x1f4078 add r0, pc, r0 */  —— pc 0x1f4080 + 0x15e764 = 0x3527e4
/* @0x1f407c strb r2, [r3] */  —— ★ 0x75505c = 1 —— 全函数唯一置失败标志的出口（id==-3 且无活实例）
/* @0x1f4080 bx lr */
/* @0x1f4084 ldr r0, [pc, #0x34] */  —— 池 0x1f40c0 = 0x0015e754
/* @0x1f4088 add r0, pc, r0 */  —— pc 0x1f4090 + 0x15e754 = 0x3527e4（id < 0，不置标志）
/* @0x1f408c bx lr */
/* @0x1f4090 ldr r0, [pc, #0x2c] */  —— 池 0x1f40c4 = 0x0015e748
/* @0x1f4094 add r0, pc, r0 */  —— pc 0x1f409c + 0x15e748 = 0x3527e4（空桶）
/* @0x1f4098 bx lr */
/* @0x1f409c ldr r0, [pc, #0x24] */  —— 池 0x1f40c8 = 0x0015e73c
/* @0x1f40a0 add r0, pc, r0 */  —— pc 0x1f40a8 + 0x15e73c = 0x3527e4（值为空）
/* @0x1f40a4 bx lr */
/* ═══ 段 6 · 字面量池（0x1f40a8..0x1f40c8，9 个字）═══ */
/* @0x1f40a8 mulseq pc, r0, r12 */  —— 池：0x001f9c90（配 0x1f3fb4 的 pc 0x1f3fbc → 0x3edc4c）
/* @0x1f40ac ldrsbeq lr, [r5], -r4 */  —— 池：0x0015e7d4（0x1f4008 → 0x3527e4）
/* @0x1f40b0 andseq r9, pc, r4, lsl r9 */  —— 池：0x001f9914（配 0x1f4014 的 pc 0x1f401c → 0x3ed930）
/* @0x1f40b4 andseq lr, r5, r12, ror r7 */  —— 池：0x0015e77c（0x1f4060 → 0x3527e4）
/* @0x1f40b8 andseq r9, pc, r12, ror #25 */  —— 池：0x001f9cec（配 0x1f4074 的 pc 0x1f407c → 0x3edd68）
/* @0x1f40bc andseq lr, r5, r4, ror #14 */  —— 池：0x0015e764（0x1f4078 → 0x3527e4）
/* @0x1f40c0 andseq lr, r5, r4, asr r7 */  —— 池：0x0015e754（0x1f4088 → 0x3527e4）
/* @0x1f40c4 andseq lr, r5, r8, asr #14 */  —— 池：0x0015e748（0x1f4094 → 0x3527e4）
/* @0x1f40c8 andseq lr, r5, r12, lsr r7 */  —— 池：0x0015e73c（0x1f40a0 → 0x3527e4）
