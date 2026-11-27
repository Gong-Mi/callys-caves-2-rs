/* cally 逆向卡：MarkAndSweepGen(int, int, bool) —— 分代 GC 的标记/清扫驱动（原版 libyoyo.so，armv7）
 * @func 0xd5ba8 0xd66e0  size 2872  718 条
 * 级别: 正文（阶段划分、门、每个阶段调用什么、根链走向都逐条落锚；sweep 段内部与四个根的语义仍 open）
 * 符号 _Z15MarkAndSweepGeniib（arg0 = 代数，实测受 cmp #3 限制；arg1/arg2 语义 open）
 *
 * ── 门与早退（0xd5bd0..0xd5bf0）────────────────────────────────────────────
 *   0xd5bd0 ldr r3,[r12,r3] / 0xd5bd4 ldrb r3,[r3] / 0xd5bd8 cmp #0 / 0xd5bdc beq 0xd5be8
 *     ⇒ 全局字节（经 GOT 槽取址）= 0 时跳过整段准备（0xd5be8..0xd5bf4 直接进 0xd5f40 之后的路径）
 *   0xd5be0 cmp r0,#3 / 0xd5be4 bls 0xd5bf4
 *     ⇒ **arg0 > 3 直接返回**（0xd5bec vpop / 0xd5bf0 pop pc）；只有 0..3 进入主体
 *
 * ── 阶段（地址即锚点）────────────────────────────────────────────────────
 *   P1 时间戳   0xd5c1c bl Timing_Time()
 *   P2 数组扩容 0xd5c90 bl MemoryManager::ReAlloc（size 来自 [sp,#0x30]/[sp,#0x38] 两个字段）
 *   P3 清零     0xd5cc4 bl memset@plt
 *   P4 复位根集 0xd5ccc bl CGCGeneration::ResetDynamicRoots()
 *   P5 挂动态根 4 处 bl CGCGeneration::AddDynamicRoot(obj,bool)：
 *       0xd5d08 链头 = [obj+0x80]，next = [cur+0x178]（尾随遍历）
 *       0xd5d34 链头 = [obj+0x8c]，next = [cur+0x178]
 *       0xd5d64 单对象   [obj+0x00]
 *       0xd5d88 单对象   [obj+0x08]
 *       ⇒ 前两条是房间实例两条链（与 CRoom 两链方向一致：+0x80 尾 / next +0x178）
 *   P6 互斥     0xd5d94 DS_AutoMutex ctor … 0xd5f3c dtor（区间内做 P7）
 *   P7 六族容器登记 每组先 GetThe*(&count) 再按索引遍历数组、元素非空才 Add4GC：
 *       CDS_Map::Add4GC 0xd5dd8（GetThe* → 0x2037b4）、CDS_List::Add4GC 0xd5e28、CDS_Stack::Add4GC 0xd5e68、
 *       CDS_Queue::Add4GC 0xd5ea8、CDS_Grid::Add4GC 0xd5ee8、CDS_Priority::Add4GC 0xd5f28
 *       ⇒ 六族容器的 GC 可达性由「注册到当前代」保证，不是每次扫描数据
 *   P8 标记     0xd6008 bl YYObjectBase::Mark4GC(unsigned int*, int)，循环遍历 [r11+0x4] 数组、[r11+0x8] 计数，
 *       每个非空元素先 0xd6004 strb 写标记字节再 Mark4GC
 *   P9 清扫     0xd60b8 之后（[sp,#0x24] 游标 vs 上限，r11+0x28 写回），本卡只到「进入清扫循环」为止
 *
 * ── open（本卡不猜）──────────────────────────────────────────────────────
 *   1 门字节的具体全局地址与写入者（同 0x5428e8/0x755363 那类，需 gate_census 逐个查）
 *   2 arg0 的「代数」语义只由 cmp #3 支撑；arg1/arg2 用途未定
 *   3 P9 清扫段的回收判据（哪些对象被释放、世代晋升怎么算）未读
 *   4 四个根的语义（+0x80 / +0x8c 两链是否分别为 active 与非 active 实例）**未证**，只证链方向与 next 偏移
 */
/* @0xd5ba8 ldr r12, [pc, #0xad8] */
/* @0xd5bac ldr r3, [pc, #0xad8] */
/* @0xd5bb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd5bb4 vpush {d8} */
/* @0xd5bb8 add r12, pc, r12 */
/* @0xd5bbc sub sp, sp, #116 */
/* @0xd5bc0 mov r6, r2 */
/* @0xd5bc4 str r12, [sp, #0x1c] */
/* @0xd5bc8 str r0, [sp, #0x14] */
/* @0xd5bcc str r1, [sp, #0x48] */
/* @0xd5bd0 ldr r3, [r12, r3] */
/* @0xd5bd4 ldrb r3, [r3] */
/* @0xd5bd8 cmp r3, #0 */
/* @0xd5bdc beq 0xd5be8 <_Z15MarkAndSweepGeniib+0x40> */
/* @0xd5be0 cmp r0, #3 */
/* @0xd5be4 bls 0xd5bf4 <_Z15MarkAndSweepGeniib+0x4c> */
/* @0xd5be8 add sp, sp, #116 */
/* @0xd5bec vpop {d8} */
/* @0xd5bf0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd5bf4 ldr r1, [pc, #0xa94] */
/* @0xd5bf8 mov r3, #88 */
/* @0xd5bfc ldr r2, [pc, #0xa90] */
/* @0xd5c00 ldr r8, [r12, r1] */
/* @0xd5c04 ldr r1, [r8] */
/* @0xd5c08 add r1, r1, #1 */
/* @0xd5c0c str r1, [r8] */
/* @0xd5c10 ldr r2, [r12, r2] */
/* @0xd5c14 mla r11, r3, r0, r2 */
/* @0xd5c18 str r2, [sp, #0x18] */
/* @0xd5c1c bl 0x215148 <Timing_Time> */
/* @0xd5c20 ldr r12, [sp, #0x1c] */
/* @0xd5c24 ldr r2, [pc, #0xa6c] */
/* @0xd5c28 ldr r3, [pc, #0xa6c] */
/* @0xd5c2c strd r0, r1, [sp, #80] */
/* @0xd5c30 ldr r10, [r12, r2] */
/* @0xd5c34 ldr r9, [r12, r3] */
/* @0xd5c38 ldr r12, [r10, #0x4] */
/* @0xd5c3c ldr r3, [r9] */
/* @0xd5c40 adds r5, r12, #31 */
/* @0xd5c44 str r12, [sp, #0x30] */
/* @0xd5c48 ldr r12, [r10, #0x8] */
/* @0xd5c4c str r12, [sp, #0x38] */
/* @0xd5c50 ldr r12, [sp, #0x30] */
/* @0xd5c54 addmi r5, r12, #62 */
/* @0xd5c58 asr r5, r5, #5 */
/* @0xd5c5c cmp r5, r3 */
/* @0xd5c60 beq 0xd5ca4 <_Z15MarkAndSweepGeniib+0xfc> */
/* @0xd5c64 ldr r0, [pc, #0xa34] */
/* @0xd5c68 lsl r7, r5, #2 */
/* @0xd5c6c ldr lr, [sp, #0x1c] */
/* @0xd5c70 mov r12, #0 */
/* @0xd5c74 ldr r2, [pc, #0xa28] */
/* @0xd5c78 mov r3, #74 */
/* @0xd5c7c mov r1, r7 */
/* @0xd5c80 ldr r4, [lr, r0] */
/* @0xd5c84 add r2, pc, r2 */
/* @0xd5c88 ldr r0, [r4] */
/* @0xd5c8c str r12, [sp] */
/* @0xd5c90 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd5c94 str r5, [r9] */
/* @0xd5c98 mov r3, r0 */
/* @0xd5c9c str r0, [r4] */
/* @0xd5ca0 b 0xd5cb8 <_Z15MarkAndSweepGeniib+0x110> */
/* @0xd5ca4 ldr r3, [pc, #0x9f4] */
/* @0xd5ca8 lsl r7, r5, #2 */
/* @0xd5cac ldr r12, [sp, #0x1c] */
/* @0xd5cb0 ldr r4, [r12, r3] */
/* @0xd5cb4 ldr r3, [r4] */
/* @0xd5cb8 mov r0, r3 */
/* @0xd5cbc mov r2, r7 */
/* @0xd5cc0 mov r1, #0 */
/* @0xd5cc4 bl 0xb65b0 <memset@plt> */
/* @0xd5cc8 mov r0, r11 */
/* @0xd5ccc bl 0x191400 <_ZN13CGCGeneration17ResetDynamicRootsEv> */
/* @0xd5cd0 cmp r6, #0 */
/* @0xd5cd4 beq 0xd5f40 <_Z15MarkAndSweepGeniib+0x398> */
/* @0xd5cd8 ldr r3, [pc, #0x9c8] */
/* @0xd5cdc ldr r12, [sp, #0x1c] */
/* @0xd5ce0 ldr r5, [r12, r3] */
/* @0xd5ce4 ldr r3, [r5] */
/* @0xd5ce8 cmp r3, #0 */
/* @0xd5cec beq 0xd5f40 <_Z15MarkAndSweepGeniib+0x398> */
/* @0xd5cf0 ldr r1, [r3, #0x80] */
/* @0xd5cf4 cmp r1, #0 */
/* @0xd5cf8 beq 0xd5d1c <_Z15MarkAndSweepGeniib+0x174> */
/* @0xd5cfc ldr r6, [r1, #0x178] */
/* @0xd5d00 mov r0, r11 */
/* @0xd5d04 mov r2, #1 */
/* @0xd5d08 bl 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */
/* @0xd5d0c cmp r6, #0 */
/* @0xd5d10 mov r1, r6 */
/* @0xd5d14 bne 0xd5cfc <_Z15MarkAndSweepGeniib+0x154> */
/* @0xd5d18 ldr r3, [r5] */
/* @0xd5d1c ldr r1, [r3, #0x8c] */
/* @0xd5d20 cmp r1, #0 */
/* @0xd5d24 beq 0xd5d44 <_Z15MarkAndSweepGeniib+0x19c> */
/* @0xd5d28 ldr r5, [r1, #0x178] */
/* @0xd5d2c mov r0, r11 */
/* @0xd5d30 mov r2, #1 */
/* @0xd5d34 bl 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */
/* @0xd5d38 cmp r5, #0 */
/* @0xd5d3c mov r1, r5 */
/* @0xd5d40 bne 0xd5d28 <_Z15MarkAndSweepGeniib+0x180> */
/* @0xd5d44 ldr r3, [pc, #0x960] */
/* @0xd5d48 ldr r12, [sp, #0x1c] */
/* @0xd5d4c ldr r3, [r12, r3] */
/* @0xd5d50 ldr r1, [r3] */
/* @0xd5d54 cmp r1, #0 */
/* @0xd5d58 beq 0xd5d68 <_Z15MarkAndSweepGeniib+0x1c0> */
/* @0xd5d5c mov r0, r11 */
/* @0xd5d60 mov r2, #1 */
/* @0xd5d64 bl 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */
/* @0xd5d68 ldr r3, [pc, #0x940] */
/* @0xd5d6c ldr r12, [sp, #0x1c] */
/* @0xd5d70 ldr r3, [r12, r3] */
/* @0xd5d74 ldr r1, [r3, #0x8] */
/* @0xd5d78 cmp r1, #0 */
/* @0xd5d7c beq 0xd5d8c <_Z15MarkAndSweepGeniib+0x1e4> */
/* @0xd5d80 mov r0, r11 */
/* @0xd5d84 mov r2, #1 */
/* @0xd5d88 bl 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */
/* @0xd5d8c add r5, sp, #92 */
/* @0xd5d90 mov r0, r5 */
/* @0xd5d94 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xd5d98 ldr r3, [pc, #0x914] */
/* @0xd5d9c ldr r12, [sp, #0x1c] */
/* @0xd5da0 ldr r7, [r12, r3] */
/* @0xd5da4 ldr r3, [r7] */
/* @0xd5da8 cmp r3, #0 */
/* @0xd5dac ble 0xd5de8 <_Z15MarkAndSweepGeniib+0x240> */
/* @0xd5db0 ldr r3, [pc, #0x900] */
/* @0xd5db4 mov r6, #0 */
/* @0xd5db8 ldr r12, [sp, #0x1c] */
/* @0xd5dbc ldr r9, [r12, r3] */
/* @0xd5dc0 ldr r3, [r9, #0x4] */
/* @0xd5dc4 mov r1, r11 */
/* @0xd5dc8 ldr r0, [r3, r6, lsl #2] */
/* @0xd5dcc add r6, r6, #1 */
/* @0xd5dd0 cmp r0, #0 */
/* @0xd5dd4 beq 0xd5ddc <_Z15MarkAndSweepGeniib+0x234> */
/* @0xd5dd8 bl 0x2037b4 <_ZN7CDS_Map6Add4GCEP13CGCGeneration> */
/* @0xd5ddc ldr r3, [r7] */
/* @0xd5de0 cmp r3, r6 */
/* @0xd5de4 bgt 0xd5dc0 <_Z15MarkAndSweepGeniib+0x218> */
/* @0xd5de8 ldr r3, [pc, #0x8cc] */
/* @0xd5dec ldr r12, [sp, #0x1c] */
/* @0xd5df0 ldr r7, [r12, r3] */
/* @0xd5df4 ldr r3, [r7] */
/* @0xd5df8 cmp r3, #0 */
/* @0xd5dfc ble 0xd5e38 <_Z15MarkAndSweepGeniib+0x290> */
/* @0xd5e00 ldr r3, [pc, #0x8b8] */
/* @0xd5e04 mov r6, #0 */
/* @0xd5e08 ldr r12, [sp, #0x1c] */
/* @0xd5e0c ldr r9, [r12, r3] */
/* @0xd5e10 ldr r3, [r9, #0x4] */
/* @0xd5e14 mov r1, r11 */
/* @0xd5e18 ldr r0, [r3, r6, lsl #2] */
/* @0xd5e1c add r6, r6, #1 */
/* @0xd5e20 cmp r0, #0 */
/* @0xd5e24 beq 0xd5e2c <_Z15MarkAndSweepGeniib+0x284> */
/* @0xd5e28 bl 0x2030f4 <_ZN8CDS_List6Add4GCEP13CGCGeneration> */
/* @0xd5e2c ldr r3, [r7] */
/* @0xd5e30 cmp r3, r6 */
/* @0xd5e34 bgt 0xd5e10 <_Z15MarkAndSweepGeniib+0x268> */
/* @0xd5e38 add r0, sp, #96 */
/* @0xd5e3c bl 0xffc9c <_Z12GetTheStacksRi> */
/* @0xd5e40 ldr r3, [sp, #0x60] */
/* @0xd5e44 cmp r3, #0 */
/* @0xd5e48 movgt r6, #0 */
/* @0xd5e4c subgt r7, r0, #4 */
/* @0xd5e50 ble 0xd5e78 <_Z15MarkAndSweepGeniib+0x2d0> */
/* @0xd5e54 ldr r0, [r7, #0x4]! */
/* @0xd5e58 mov r1, r11 */
/* @0xd5e5c add r6, r6, #1 */
/* @0xd5e60 cmp r0, #0 */
/* @0xd5e64 beq 0xd5e70 <_Z15MarkAndSweepGeniib+0x2c8> */
/* @0xd5e68 bl 0x202d98 <_ZN9CDS_Stack6Add4GCEP13CGCGeneration> */
/* @0xd5e6c ldr r3, [sp, #0x60] */
/* @0xd5e70 cmp r3, r6 */
/* @0xd5e74 bgt 0xd5e54 <_Z15MarkAndSweepGeniib+0x2ac> */
/* @0xd5e78 add r0, sp, #100 */
/* @0xd5e7c bl 0xffee8 <_Z12GetTheQueuesRi> */
/* @0xd5e80 ldr r3, [sp, #0x64] */
/* @0xd5e84 cmp r3, #0 */
/* @0xd5e88 movgt r6, #0 */
/* @0xd5e8c subgt r7, r0, #4 */
/* @0xd5e90 ble 0xd5eb8 <_Z15MarkAndSweepGeniib+0x310> */
/* @0xd5e94 ldr r0, [r7, #0x4]! */
/* @0xd5e98 mov r1, r11 */
/* @0xd5e9c add r6, r6, #1 */
/* @0xd5ea0 cmp r0, #0 */
/* @0xd5ea4 beq 0xd5eb0 <_Z15MarkAndSweepGeniib+0x308> */
/* @0xd5ea8 bl 0x202f20 <_ZN9CDS_Queue6Add4GCEP13CGCGeneration> */
/* @0xd5eac ldr r3, [sp, #0x64] */
/* @0xd5eb0 cmp r3, r6 */
/* @0xd5eb4 bgt 0xd5e94 <_Z15MarkAndSweepGeniib+0x2ec> */
/* @0xd5eb8 add r0, sp, #104 */
/* @0xd5ebc bl 0x10026c <_Z11GetTheGridsRi> */
/* @0xd5ec0 ldr r3, [sp, #0x68] */
/* @0xd5ec4 cmp r3, #0 */
/* @0xd5ec8 movgt r6, #0 */
/* @0xd5ecc subgt r7, r0, #4 */
/* @0xd5ed0 ble 0xd5ef8 <_Z15MarkAndSweepGeniib+0x350> */
/* @0xd5ed4 ldr r0, [r7, #0x4]! */
/* @0xd5ed8 mov r1, r11 */
/* @0xd5edc add r6, r6, #1 */
/* @0xd5ee0 cmp r0, #0 */
/* @0xd5ee4 beq 0xd5ef0 <_Z15MarkAndSweepGeniib+0x348> */
/* @0xd5ee8 bl 0x2051dc <_ZN8CDS_Grid6Add4GCEP13CGCGeneration> */
/* @0xd5eec ldr r3, [sp, #0x68] */
/* @0xd5ef0 cmp r3, r6 */
/* @0xd5ef4 bgt 0xd5ed4 <_Z15MarkAndSweepGeniib+0x32c> */
/* @0xd5ef8 add r0, sp, #108 */
/* @0xd5efc bl 0x100244 <_Z20GetThePriorityQueuesRi> */
/* @0xd5f00 ldr r3, [sp, #0x6c] */
/* @0xd5f04 cmp r3, #0 */
/* @0xd5f08 movgt r6, #0 */
/* @0xd5f0c subgt r7, r0, #4 */
/* @0xd5f10 ble 0xd5f38 <_Z15MarkAndSweepGeniib+0x390> */
/* @0xd5f14 ldr r0, [r7, #0x4]! */
/* @0xd5f18 mov r1, r11 */
/* @0xd5f1c add r6, r6, #1 */
/* @0xd5f20 cmp r0, #0 */
/* @0xd5f24 beq 0xd5f30 <_Z15MarkAndSweepGeniib+0x388> */
/* @0xd5f28 bl 0x203ea4 <_ZN12CDS_Priority6Add4GCEP13CGCGeneration> */
/* @0xd5f2c ldr r3, [sp, #0x6c] */
/* @0xd5f30 cmp r3, r6 */
/* @0xd5f34 bgt 0xd5f14 <_Z15MarkAndSweepGeniib+0x36c> */
/* @0xd5f38 mov r0, r5 */
/* @0xd5f3c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xd5f40 ldr r12, [sp, #0x1c] */
/* @0xd5f44 mov r3, #0 */
/* @0xd5f48 ldr r1, [pc, #0x774] */
/* @0xd5f4c mov r9, r11 */
/* @0xd5f50 str r3, [sp, #0x40] */
/* @0xd5f54 mov r7, r3 */
/* @0xd5f58 ldr r2, [pc, #0x768] */
/* @0xd5f5c mov r5, #1 */
/* @0xd5f60 ldr r1, [r12, r1] */
/* @0xd5f64 str r1, [sp, #0x4c] */
/* @0xd5f68 str r3, [r1] */
/* @0xd5f6c ldr r6, [r12, r2] */
/* @0xd5f70 ldr r12, [sp, #0x14] */
/* @0xd5f74 mov r11, r6 */
/* @0xd5f78 str r12, [r6] */
/* @0xd5f7c mov r6, r8 */
/* @0xd5f80 ldr r8, [sp, #0x1c] */
/* @0xd5f84 ldr r2, [r9] */
/* @0xd5f88 add r3, r7, r7, lsl #1 */
/* @0xd5f8c ldr r1, [r2, #0x10] */
/* @0xd5f90 ldr r0, [r2] */
/* @0xd5f94 add r3, r1, r3, lsl #2 */
/* @0xd5f98 b 0xd5fa8 <_Z15MarkAndSweepGeniib+0x400> */
/* @0xd5f9c ldr r1, [r2, #0x8] */
/* @0xd5fa0 cmp r1, #0 */
/* @0xd5fa4 bgt 0xd65b4 <_Z15MarkAndSweepGeniib+0xa0c> */
/* @0xd5fa8 add r7, r7, #1 */
/* @0xd5fac mov r2, r3 */
/* @0xd5fb0 cmp r0, r7 */
/* @0xd5fb4 add r3, r3, #12 */
/* @0xd5fb8 bge 0xd5f9c <_Z15MarkAndSweepGeniib+0x3f4> */
/* @0xd5fbc ldr r3, [r9, #0x8] */
/* @0xd5fc0 mov r6, r11 */
/* @0xd5fc4 mov r11, r9 */
/* @0xd5fc8 cmp r3, #0 */
/* @0xd5fcc ble 0xd6018 <_Z15MarkAndSweepGeniib+0x470> */
/* @0xd5fd0 ldr r8, [sp, #0x30] */
/* @0xd5fd4 mov r7, #0 */
/* @0xd5fd8 ldr r9, [sp, #0x1c] */
/* @0xd5fdc mov r5, #1 */
/* @0xd5fe0 ldr r1, [r11, #0x4] */
/* @0xd5fe4 mov r2, r8 */
/* @0xd5fe8 ldr r12, [pc, #0x6dc] */
/* @0xd5fec ldr r0, [r1, r7, lsl #2] */
/* @0xd5ff0 add r7, r7, #1 */
/* @0xd5ff4 cmp r0, #0 */
/* @0xd5ff8 beq 0xd6010 <_Z15MarkAndSweepGeniib+0x468> */
/* @0xd5ffc ldr r3, [r9, r12] */
/* @0xd6000 ldr r1, [r4] */
/* @0xd6004 strb r5, [r3] */
/* @0xd6008 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd600c ldr r3, [r11, #0x8] */
/* @0xd6010 cmp r3, r7 */
/* @0xd6014 bgt 0xd5fe0 <_Z15MarkAndSweepGeniib+0x438> */
/* @0xd6018 ldr r12, [sp, #0x14] */
/* @0xd601c mov r3, #4 */
/* @0xd6020 ldr r10, [r10] */
/* @0xd6024 cmp r12, #0 */
/* @0xd6028 ldr r12, [r11, #0x18] */
/* @0xd602c str r3, [r6] */
/* @0xd6030 str r10, [sp, #0x44] */
/* @0xd6034 ldr r2, [r11, #0x14] */
/* @0xd6038 str r12, [sp, #0x3c] */
/* @0xd603c beq 0xd607c <_Z15MarkAndSweepGeniib+0x4d4> */
/* @0xd6040 ldr r3, [sp, #0x18] */
/* @0xd6044 mov r12, #88 */
/* @0xd6048 ldr lr, [sp, #0x14] */
/* @0xd604c ldr r1, [sp, #0x3c] */
/* @0xd6050 mla r12, r12, lr, r3 */
/* @0xd6054 ldr lr, [r3, #0x14] */
/* @0xd6058 add r3, r3, #88 */
/* @0xd605c ldr r0, [r3, #-0x40] */
/* @0xd6060 cmp r2, lr */
/* @0xd6064 movge r2, lr */
/* @0xd6068 cmp r1, r0 */
/* @0xd606c movlt r1, r0 */
/* @0xd6070 cmp r3, r12 */
/* @0xd6074 bne 0xd6054 <_Z15MarkAndSweepGeniib+0x4ac> */
/* @0xd6078 str r1, [sp, #0x3c] */
/* @0xd607c add r1, r2, #31 */
/* @0xd6080 cmp r2, #0 */
/* @0xd6084 ldr r12, [sp, #0x3c] */
/* @0xd6088 mov r7, #0 */
/* @0xd608c movlt r2, r1 */
/* @0xd6090 ldr r3, [r4] */
/* @0xd6094 adds r1, r12, #32 */
/* @0xd6098 asr r2, r2, #5 */
/* @0xd609c addmi r1, r12, #63 */
/* @0xd60a0 str r2, [sp, #0x24] */
/* @0xd60a4 ldr r12, [sp, #0x24] */
/* @0xd60a8 asr r2, r1, #5 */
/* @0xd60ac str r7, [r11, #0x28] */
/* @0xd60b0 sub r2, r2, #1 */
/* @0xd60b4 str r2, [sp, #0x34] */
/* @0xd60b8 cmp r12, r2 */
/* @0xd60bc add r3, r3, r12, lsl #2 */
/* @0xd60c0 str r3, [sp, #0x2c] */
/* @0xd60c4 bge 0xd667c <_Z15MarkAndSweepGeniib+0xad4> */
/* @0xd60c8 ldr r12, [pc, #0x600] */
/* @0xd60cc ldr lr, [sp, #0x24] */
/* @0xd60d0 add r12, pc, r12 */
/* @0xd60d4 str r12, [sp, #0x28] */
/* @0xd60d8 ldr r12, [sp, #0x24] */
/* @0xd60dc str r3, [sp, #0x20] */
/* @0xd60e0 lsl r12, r12, #5 */
/* @0xd60e4 str r12, [sp, #0x10] */
/* @0xd60e8 ldr r12, [sp, #0x44] */
/* @0xd60ec add r12, r12, lr, lsl #7 */
/* @0xd60f0 str r12, [sp, #0xc] */
/* @0xd60f4 ldr r12, [sp, #0x14] */
/* @0xd60f8 add r6, r12, #1 */
/* @0xd60fc ldr r12, [sp, #0x20] */
/* @0xd6100 str r12, [sp, #0x2c] */
/* @0xd6104 ldr r8, [r12], #4 */
/* @0xd6108 cmn r8, #1 */
/* @0xd610c str r12, [sp, #0x20] */
/* @0xd6110 addeq r7, r7, #32 */
/* @0xd6114 beq 0xd61d0 <_Z15MarkAndSweepGeniib+0x628> */
/* @0xd6118 mov r4, #0 */
/* @0xd611c mov lr, #1 */
/* @0xd6120 ands lr, r8, lr, lsl r4 */
/* @0xd6124 bne 0xd61b4 <_Z15MarkAndSweepGeniib+0x60c> */
/* @0xd6128 ldr r12, [sp, #0xc] */
/* @0xd612c ldr r5, [r12, r4, lsl #2] */
/* @0xd6130 ldr r12, [sp, #0x10] */
/* @0xd6134 cmp r5, #0 */
/* @0xd6138 add r3, r12, r4 */
/* @0xd613c beq 0xd61b8 <_Z15MarkAndSweepGeniib+0x610> */
/* @0xd6140 ldr r2, [r5, #0x38] */
/* @0xd6144 ldr r12, [sp, #0x14] */
/* @0xd6148 cmp r12, r2 */
/* @0xd614c blt 0xd61b4 <_Z15MarkAndSweepGeniib+0x60c> */
/* @0xd6150 ldr r2, [r5, #0x44] */
/* @0xd6154 cmp r3, r2 */
/* @0xd6158 beq 0xd617c <_Z15MarkAndSweepGeniib+0x5d4> */
/* @0xd615c ldr r12, [sp, #0x1c] */
/* @0xd6160 ldr r0, [pc, #0x56c] */
/* @0xd6164 ldr r1, [sp, #0x28] */
/* @0xd6168 ldr r0, [r12, r0] */
/* @0xd616c ldr r0, [r0] */
/* @0xd6170 ldr r12, [r0] */
/* @0xd6174 ldr r12, [r12, #0xc] */
/* @0xd6178 blx r12 */
/* @0xd617c ldr r10, [sp, #0x18] */
/* @0xd6180 mov r9, #0 */
/* @0xd6184 mov r0, r10 */
/* @0xd6188 add r9, r9, #1 */
/* @0xd618c mov r1, r5 */
/* @0xd6190 add r10, r10, #88 */
/* @0xd6194 bl 0x1911c8 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase> */
/* @0xd6198 cmp r9, r6 */
/* @0xd619c bne 0xd6184 <_Z15MarkAndSweepGeniib+0x5dc> */
/* @0xd61a0 mov r0, r5 */
/* @0xd61a4 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xd61a8 ldr r3, [r11, #0x28] */
/* @0xd61ac add r3, r3, #1 */
/* @0xd61b0 str r3, [r11, #0x28] */
/* @0xd61b4 add r7, r7, #1 */
/* @0xd61b8 add r4, r4, #1 */
/* @0xd61bc cmp r4, #32 */
/* @0xd61c0 bne 0xd611c <_Z15MarkAndSweepGeniib+0x574> */
/* @0xd61c4 ldr r12, [sp, #0x38] */
/* @0xd61c8 cmp r12, r7 */
/* @0xd61cc ble 0xd6210 <_Z15MarkAndSweepGeniib+0x668> */
/* @0xd61d0 ldr r12, [sp, #0x24] */
/* @0xd61d4 ldr lr, [sp, #0x34] */
/* @0xd61d8 add r12, r12, #1 */
/* @0xd61dc str r12, [sp, #0x24] */
/* @0xd61e0 ldr r12, [sp, #0x10] */
/* @0xd61e4 add r12, r12, #32 */
/* @0xd61e8 str r12, [sp, #0x10] */
/* @0xd61ec ldr r12, [sp, #0x24] */
/* @0xd61f0 cmp r12, lr */
/* @0xd61f4 ldr r12, [sp, #0xc] */
/* @0xd61f8 add r12, r12, #128 */
/* @0xd61fc str r12, [sp, #0xc] */
/* @0xd6200 ldr r12, [sp, #0x20] */
/* @0xd6204 str r12, [sp, #0x2c] */
/* @0xd6208 bne 0xd60fc <_Z15MarkAndSweepGeniib+0x554> */
/* @0xd620c mov r4, #0 */
/* @0xd6210 ldr r12, [sp, #0x24] */
/* @0xd6214 lsl r3, r12, #5 */
/* @0xd6218 ldr r12, [sp, #0x3c] */
/* @0xd621c cmp r3, r12 */
/* @0xd6220 bgt 0xd62e8 <_Z15MarkAndSweepGeniib+0x740> */
/* @0xd6224 ldr r12, [sp, #0x38] */
/* @0xd6228 cmp r7, r12 */
/* @0xd622c bge 0xd62e8 <_Z15MarkAndSweepGeniib+0x740> */
/* @0xd6230 ldr r12, [sp, #0x3c] */
/* @0xd6234 mov r7, #0 */
/* @0xd6238 ldr lr, [sp, #0x24] */
/* @0xd623c mov r10, #1 */
/* @0xd6240 add r9, r12, #1 */
/* @0xd6244 ldr r2, [sp, #0x2c] */
/* @0xd6248 ldr r12, [sp, #0x44] */
/* @0xd624c add r9, r9, r4 */
/* @0xd6250 rsb r9, r3, r9 */
/* @0xd6254 str r9, [sp, #0x10] */
/* @0xd6258 add r12, r12, lr, lsl #7 */
/* @0xd625c str r12, [sp, #0x20] */
/* @0xd6260 ldr r12, [sp, #0x14] */
/* @0xd6264 ldr r2, [r2] */
/* @0xd6268 add r6, r12, #1 */
/* @0xd626c str r2, [sp, #0xc] */
/* @0xd6270 ldr r3, [sp, #0xc] */
/* @0xd6274 ands r2, r3, r10, lsl r4 */
/* @0xd6278 bne 0xd62d4 <_Z15MarkAndSweepGeniib+0x72c> */
/* @0xd627c ldr r12, [sp, #0x20] */
/* @0xd6280 ldr r5, [r12, r7] */
/* @0xd6284 cmp r5, #0 */
/* @0xd6288 beq 0xd62d4 <_Z15MarkAndSweepGeniib+0x72c> */
/* @0xd628c ldr r3, [r5, #0x38] */
/* @0xd6290 ldr r12, [sp, #0x14] */
/* @0xd6294 cmp r12, r3 */
/* @0xd6298 blt 0xd62d4 <_Z15MarkAndSweepGeniib+0x72c> */
/* @0xd629c ldr r8, [sp, #0x18] */
/* @0xd62a0 mov r9, r2 */
/* @0xd62a4 mov r0, r8 */
/* @0xd62a8 add r9, r9, #1 */
/* @0xd62ac mov r1, r5 */
/* @0xd62b0 add r8, r8, #88 */
/* @0xd62b4 bl 0x1911c8 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase> */
/* @0xd62b8 cmp r9, r6 */
/* @0xd62bc bne 0xd62a4 <_Z15MarkAndSweepGeniib+0x6fc> */
/* @0xd62c0 mov r0, r5 */
/* @0xd62c4 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xd62c8 ldr r3, [r11, #0x28] */
/* @0xd62cc add r3, r3, #1 */
/* @0xd62d0 str r3, [r11, #0x28] */
/* @0xd62d4 ldr r2, [sp, #0x10] */
/* @0xd62d8 add r4, r4, #1 */
/* @0xd62dc add r7, r7, #4 */
/* @0xd62e0 cmp r4, r2 */
/* @0xd62e4 bne 0xd6270 <_Z15MarkAndSweepGeniib+0x6c8> */
/* @0xd62e8 ldr r12, [sp, #0x14] */
/* @0xd62ec subs r6, r12, #2 */
/* @0xd62f0 bmi 0xd63f0 <_Z15MarkAndSweepGeniib+0x848> */
/* @0xd62f4 ldr r12, [sp, #0x14] */
/* @0xd62f8 mov r7, #88 */
/* @0xd62fc ldr r9, [pc, #0x3d4] */
/* @0xd6300 mov r5, #0 */
/* @0xd6304 sub r3, r12, #1 */
/* @0xd6308 ldr r12, [sp, #0x18] */
/* @0xd630c add r9, pc, r9 */
/* @0xd6310 vldr s16, [pc, #876] */
/* @0xd6314 mla r7, r7, r3, r12 */
/* @0xd6318 ldr r8, [r7, #-0x58] */
/* @0xd631c mov r4, #0 */
/* @0xd6320 ldr lr, [r8] */
/* @0xd6324 ldr r0, [r8, #0x10] */
/* @0xd6328 add r3, r4, r4, lsl #1 */
/* @0xd632c add r3, r0, r3, lsl #2 */
/* @0xd6330 b 0xd6340 <_Z15MarkAndSweepGeniib+0x798> */
/* @0xd6334 ldr r1, [r2, #0x8] */
/* @0xd6338 cmp r1, #0 */
/* @0xd633c bgt 0xd6590 <_Z15MarkAndSweepGeniib+0x9e8> */
/* @0xd6340 add r4, r4, #1 */
/* @0xd6344 mov r2, r3 */
/* @0xd6348 cmp r4, lr */
/* @0xd634c add r3, r3, #12 */
/* @0xd6350 ble 0xd6334 <_Z15MarkAndSweepGeniib+0x78c> */
/* @0xd6354 cmp r0, #0 */
/* @0xd6358 beq 0xd6360 <_Z15MarkAndSweepGeniib+0x7b8> */
/* @0xd635c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd6360 str r5, [r8, #0x10] */
/* @0xd6364 mov r1, r9 */
/* @0xd6368 ldr r4, [r7, #-0x58] */
/* @0xd636c mov r2, #70 */
/* @0xd6370 mov r3, #1 */
/* @0xd6374 ldr r0, [r4] */
/* @0xd6378 sub r12, r0, #1 */
/* @0xd637c str r12, [r4, #0x8] */
/* @0xd6380 add r0, r0, r0, lsl #1 */
/* @0xd6384 lsl r8, r0, #2 */
/* @0xd6388 mov r0, r8 */
/* @0xd638c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd6390 mov r2, r8 */
/* @0xd6394 mov r1, #0 */
/* @0xd6398 str r0, [r4, #0x10] */
/* @0xd639c bl 0xb65b0 <memset@plt> */
/* @0xd63a0 ldr r2, [r4] */
/* @0xd63a4 str r5, [r4, #0x4] */
/* @0xd63a8 cmp r2, #0 */
/* @0xd63ac vmov s13, r2 */
/* @0xd63b0 vcvt.f32.s32 s15, s13 */
/* @0xd63b4 vmul.f32 s15, s15, s16 */
/* @0xd63b8 vcvt.s32.f32 s15, s15 */
/* @0xd63bc vstr s15, [r4, #12] */
/* @0xd63c0 ble 0xd63e0 <_Z15MarkAndSweepGeniib+0x838> */
/* @0xd63c4 ldr r3, [r4, #0x10] */
/* @0xd63c8 add r2, r2, r2, lsl #1 */
/* @0xd63cc add r2, r3, r2, lsl #2 */
/* @0xd63d0 str r5, [r3, #0x8] */
/* @0xd63d4 add r3, r3, #12 */
/* @0xd63d8 cmp r3, r2 */
/* @0xd63dc bne 0xd63d0 <_Z15MarkAndSweepGeniib+0x828> */
/* @0xd63e0 sub r6, r6, #1 */
/* @0xd63e4 sub r7, r7, #88 */
/* @0xd63e8 cmn r6, #1 */
/* @0xd63ec bne 0xd6318 <_Z15MarkAndSweepGeniib+0x770> */
/* @0xd63f0 ldr r12, [sp, #0x14] */
/* @0xd63f4 cmp r12, #1 */
/* @0xd63f8 ble 0xd64bc <_Z15MarkAndSweepGeniib+0x914> */
/* @0xd63fc ldr r12, [sp, #0x30] */
/* @0xd6400 mvn r3, #-2147483648 */
/* @0xd6404 mvn r4, #0 */
/* @0xd6408 cmp r12, #0 */
/* @0xd640c ldr r12, [sp, #0x18] */
/* @0xd6410 str r3, [r12, #0x14] */
/* @0xd6414 str r3, [r12, #0x6c] */
/* @0xd6418 str r3, [r12, #0xc4] */
/* @0xd641c str r3, [r12, #0x11c] */
/* @0xd6420 str r4, [r12, #0x18] */
/* @0xd6424 str r4, [r12, #0x70] */
/* @0xd6428 str r4, [r12, #0xc8] */
/* @0xd642c str r4, [r12, #0x120] */
/* @0xd6430 ble 0xd64bc <_Z15MarkAndSweepGeniib+0x914> */
/* @0xd6434 ldr r6, [sp, #0x44] */
/* @0xd6438 mov r5, #0 */
/* @0xd643c ldr r12, [sp, #0x14] */
/* @0xd6440 mov r8, #88 */
/* @0xd6444 ldr r9, [sp, #0x30] */
/* @0xd6448 mov r10, r6 */
/* @0xd644c add r7, r12, r4 */
/* @0xd6450 mov r6, r5 */
/* @0xd6454 mov r5, r10 */
/* @0xd6458 ldr lr, [r5], #4 */
/* @0xd645c cmp lr, #0 */
/* @0xd6460 beq 0xd64b0 <_Z15MarkAndSweepGeniib+0x908> */
/* @0xd6464 ldr r3, [lr, #0x38] */
/* @0xd6468 cmp r3, r7 */
/* @0xd646c addlt r3, r3, #1 */
/* @0xd6470 strlt r3, [lr, #0x38] */
/* @0xd6474 add r3, r10, r4, lsl #2 */
/* @0xd6478 b 0xd648c <_Z15MarkAndSweepGeniib+0x8e4> */
/* @0xd647c ldr r0, [r3, #0x4] */
/* @0xd6480 mov r3, r2 */
/* @0xd6484 cmp r0, #0 */
/* @0xd6488 beq 0xd6600 <_Z15MarkAndSweepGeniib+0xa58> */
/* @0xd648c add r4, r4, #1 */
/* @0xd6490 add r2, r3, #4 */
/* @0xd6494 cmp r6, r4 */
/* @0xd6498 bgt 0xd647c <_Z15MarkAndSweepGeniib+0x8d4> */
/* @0xd649c mov r1, r6 */
/* @0xd64a0 ldr r0, [lr, #0x38] */
/* @0xd64a4 ldr r12, [sp, #0x18] */
/* @0xd64a8 mla r0, r8, r0, r12 */
/* @0xd64ac bl 0x19150c <_ZN13CGCGeneration11UpdateRangeEi> */
/* @0xd64b0 add r6, r6, #1 */
/* @0xd64b4 cmp r6, r9 */
/* @0xd64b8 bne 0xd6458 <_Z15MarkAndSweepGeniib+0x8b0> */
/* @0xd64bc ldr r0, [r11, #0x1c] */
/* @0xd64c0 cmn r0, #1 */
/* @0xd64c4 beq 0xd6628 <_Z15MarkAndSweepGeniib+0xa80> */
/* @0xd64c8 ldr r12, [sp, #0x48] */
/* @0xd64cc add r3, r0, #1 */
/* @0xd64d0 cmp r3, r12 */
/* @0xd64d4 bge 0xd661c <_Z15MarkAndSweepGeniib+0xa74> */
/* @0xd64d8 ldr r12, [sp, #0x14] */
/* @0xd64dc add r2, r12, #1 */
/* @0xd64e0 cmp r2, #4 */
/* @0xd64e4 str r12, [r11, #0x38] */
/* @0xd64e8 beq 0xd661c <_Z15MarkAndSweepGeniib+0xa74> */
/* @0xd64ec ldr r12, [sp, #0x4c] */
/* @0xd64f0 ldr r1, [pc, #0x1e4] */
/* @0xd64f4 ldr r3, [r12] */
/* @0xd64f8 ldr r12, [sp, #0x1c] */
/* @0xd64fc cmp r3, #0 */
/* @0xd6500 ldr r1, [r12, r1] */
/* @0xd6504 ldr r4, [r1] */
/* @0xd6508 ble 0xd6640 <_Z15MarkAndSweepGeniib+0xa98> */
/* @0xd650c ldr r1, [sp, #0x18] */
/* @0xd6510 add r12, r1, #264 */
/* @0xd6514 mov r1, r11 */
/* @0xd6518 ldr lr, [r1, #0x74] */
/* @0xd651c add r1, r1, #88 */
/* @0xd6520 cmp r0, lr */
/* @0xd6524 bge 0xd6550 <_Z15MarkAndSweepGeniib+0x9a8> */
/* @0xd6528 vldr s13, [r11, #40] */
/* @0xd652c vcvt.f32.s32 s14, s13 */
/* @0xd6530 vmov s13, r3 */
/* @0xd6534 ldr lr, [r11, #0x34] */
/* @0xd6538 str r3, [r11, #0x20] */
/* @0xd653c str r2, [r11, #0x38] */
/* @0xd6540 str lr, [r11, #0x30] */
/* @0xd6544 vcvt.f32.s32 s15, s13 */
/* @0xd6548 vdiv.f32 s15, s14, s15 */
/* @0xd654c vstr s15, [r11, #44] */
/* @0xd6550 cmp r1, r12 */
/* @0xd6554 add r2, r2, #1 */
/* @0xd6558 bne 0xd6518 <_Z15MarkAndSweepGeniib+0x970> */
/* @0xd655c ldr r12, [sp, #0x40] */
/* @0xd6560 str r3, [r11, #0x24] */
/* @0xd6564 str r12, [r11, #0x34] */
/* @0xd6568 ldr r12, [sp, #0x48] */
/* @0xd656c str r12, [r11, #0x1c] */
/* @0xd6570 bl 0x215148 <Timing_Time> */
/* @0xd6574 ldrd r2, r3, [sp, #80] */
/* @0xd6578 subs r0, r0, r2 */
/* @0xd657c sbc r1, r1, r3 */
/* @0xd6580 strd r0, r1, [r11, #64] */
/* @0xd6584 add sp, sp, #116 */
/* @0xd6588 vpop {d8} */
/* @0xd658c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd6590 ldr r1, [r2, #0x4] */
/* @0xd6594 cmp r1, #0 */
/* @0xd6598 beq 0xd6328 <_Z15MarkAndSweepGeniib+0x780> */
/* @0xd659c mov r0, r7 */
/* @0xd65a0 bl 0x196210 <_ZN13CGCGeneration7AddRootEP12YYObjectBase> */
/* @0xd65a4 ldr r8, [r7, #-0x58] */
/* @0xd65a8 ldr lr, [r8] */
/* @0xd65ac ldr r0, [r8, #0x10] */
/* @0xd65b0 b 0xd6328 <_Z15MarkAndSweepGeniib+0x780> */
/* @0xd65b4 ldr r0, [r2, #0x4] */
/* @0xd65b8 ldr r3, [pc, #0x10c] */
/* @0xd65bc ldr r12, [sp, #0x14] */
/* @0xd65c0 ldr r2, [r0, #0x38] */
/* @0xd65c4 ldr r3, [r8, r3] */
/* @0xd65c8 cmp r2, r12 */
/* @0xd65cc strb r5, [r3] */
/* @0xd65d0 bne 0xd65f0 <_Z15MarkAndSweepGeniib+0xa48> */
/* @0xd65d4 ldr r2, [r6] */
/* @0xd65d8 ldr r3, [r0, #0x3c] */
/* @0xd65dc ldr r12, [sp, #0x40] */
/* @0xd65e0 rsb r3, r3, r2 */
/* @0xd65e4 cmp r12, r3 */
/* @0xd65e8 movlo r12, r3 */
/* @0xd65ec str r12, [sp, #0x40] */
/* @0xd65f0 ldr r1, [r4] */
/* @0xd65f4 ldr r2, [sp, #0x30] */
/* @0xd65f8 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd65fc b 0xd5f84 <_Z15MarkAndSweepGeniib+0x3dc> */
/* @0xd6600 ldr r3, [r5, #-0x4] */
/* @0xd6604 mov r1, r4 */
/* @0xd6608 str r3, [r2] */
/* @0xd660c str r0, [r5, #-0x4] */
/* @0xd6610 ldr lr, [r2] */
/* @0xd6614 str r4, [lr, #0x44] */
/* @0xd6618 b 0xd64a0 <_Z15MarkAndSweepGeniib+0x8f8> */
/* @0xd661c ldr r12, [sp, #0x4c] */
/* @0xd6620 ldr r3, [r12] */
/* @0xd6624 b 0xd655c <_Z15MarkAndSweepGeniib+0x9b4> */
/* @0xd6628 ldr r12, [sp, #0x4c] */
/* @0xd662c ldr r3, [r12] */
/* @0xd6630 ldr r12, [sp, #0x14] */
/* @0xd6634 str r3, [r11, #0x20] */
/* @0xd6638 str r12, [r11, #0x38] */
/* @0xd663c b 0xd655c <_Z15MarkAndSweepGeniib+0x9b4> */
/* @0xd6640 ldr lr, [sp, #0x18] */
/* @0xd6644 mov r1, r11 */
/* @0xd6648 add r12, lr, #264 */
/* @0xd664c ldr lr, [r1, #0x74] */
/* @0xd6650 add r1, r1, #88 */
/* @0xd6654 cmp r0, lr */
/* @0xd6658 strlt r2, [r11, #0x38] */
/* @0xd665c strlt r4, [r11, #0x2c] */
/* @0xd6660 add r2, r2, #1 */
/* @0xd6664 ldrlt lr, [r11, #0x34] */
/* @0xd6668 strlt r3, [r11, #0x20] */
/* @0xd666c strlt lr, [r11, #0x30] */
/* @0xd6670 cmp r1, r12 */
/* @0xd6674 bne 0xd664c <_Z15MarkAndSweepGeniib+0xaa4> */
/* @0xd6678 b 0xd655c <_Z15MarkAndSweepGeniib+0x9b4> */
/* @0xd667c mov r4, r7 */
/* @0xd6680 b 0xd6210 <_Z15MarkAndSweepGeniib+0x668> */
/* @0xd6684 svclo #0x19999a */
/* @0xd6688 mlaseq r1, r8, r0, r12 */
/* @0xd668c .word 0xffffbf68 */
/* @0xd6690 .word 0xffffbffc */
/* @0xd6694 .word 0xffffc010 */
/* @0xd6698 .word 0xffffc014 */
/* @0xd669c .word 0xffffc018 */
/* @0xd66a0 .word 0xffffc01c */
/* @0xd66a4 eoreq r11, r5, r12, lsr #7 */
/* @0xd66a8 .word 0xffffbcd8 */
/* @0xd66ac .word 0xffffc020 */
/* @0xd66b0 .word 0xffffc024 */
/* @0xd66b4 .word 0xffffc028 */
/* @0xd66b8 .word 0xffffbcec */
/* @0xd66bc .word 0xffffc02c */
/* @0xd66c0 .word 0xffffc030 */
/* @0xd66c4 .word 0xffffc034 */
/* @0xd66c8 .word 0xffffc038 */
/* @0xd66cc .word 0xffffc03c */
/* @0xd66d0 eoreq r12, r5, r8, lsl #20 */
/* @0xd66d4 .word 0xffffbac4 */
/* @0xd66d8 eoreq r10, r5, r4, lsr #26 */
/* @0xd66dc .word 0xffffc040 */
