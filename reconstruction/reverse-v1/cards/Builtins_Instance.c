/* cally 逆向卡：实例激活/失活 + 碰撞类内建 9 个（原版 libyoyo.so，armv7）
 * 节: 9 个 @func 小节，顺序 = instance_activate_all / instance_activate_object /
 *     instance_deactivate_all / instance_deactivate_object / instance_create /
 *     distance_to_object / place_meeting / collision_line / collision_point
 * 级别: 正文（721/721 逐条落锚 = 702 条指令 + 19 个池字；9 个函数的入参索引、闸门方向、
 *       分支目标、返回值编码全部逐条解出；RTree / Command_* 侧只到调用边界与已证的四道闸，
 *       库函数内部（RTree::Search 的剪枝、WithObjIterator 的模式机）未逐档解开，见 open）
 * 索引: asm/index-builtins_instance_all.tsv（9 个函数按地址合并，721 行）
 *
 * ── 统一签名（9 个一模一样）───────────────────────────────────────────────
 *   F_Xxx(RValue& result, CInstance* self, CInstance* other, int argc, RValue** args)
 *   r0 = &result、r1 = self、r2 = other、r3 = argc、[sp] = args（RValue**）
 *   argc 在这 9 个函数里**一次都没被读过**（r3 全部被当临时寄存器）；入参只从 args 取。
 *   帧量与取参位置逐条互证（push 的寄存器数×4 + sub 立即数 = args 的栈槽）：
 *     ActAll 6×4+8=0x20（不取参）、ActObj 9×4+12=0x30（0x10bec0 ldr r0,[sp,#0x30]）、
 *     DeactAll 8×4+8=0x28（0x10b490）、DeactObj 8×4+48=0x50（0x10a590）、
 *     InstCreate 6×4=0x18（0x1095a0）、DistToObj 7×4+52=0x50（0x10adb8）、
 *     PlaceMeeting 6×4=0x18（0x107fbc）、CollPoint 8×4+8=0x28（0x108f90）、
 *     CollLine 9×4+28=0x40（0x1092e0）。
 *
 * ── CInstance 侧字段（本卡用到并逐处引用的）────────────────────────────────
 *   +0x64  bbox 脏位（FindDist 0x10acd8/0x10acec、Command_InstancePlace 0x1ca83c 读它决定重算）
 *   +0x68  skip：本卡的硬闸；非 0 则 activate/deactivate/查询一律跳过，连 activate_object(-1) 也不碰
 *   +0x69  deactivated：本卡 9 个函数里**没有一处**直接写（0 条 strb #0x69），状态写一律经
 *          CInstance::SetDeactivated（0x192310 strb r1,[r0,#0x69]）；全 .text 另有 4 处直接写
 *          （0x1976e0 DeSerialise｜0x198bf8 Assign｜0x199614+0x199734 ctor），本卡不展开
 *   +0x78  实例 id（>0x1869F 走 ms_ID2Instance；也是 instance_create 与两个碰撞函数的返回值来源）
 *   +0x7c  对象索引（activate_object 的匹配键；DoPushEnv 卡同）
 *   +0x80  CObjectGM*（IsDecendentOf 的 this、CollisionUpdate 读它的 flags bit4）
 *   +0xe8/+0xec/+0xf0/+0xf4  bbox left/top/right/bottom，int32
 *   +0x178 prev / +0x17c next（A/B 两链共用同一对链接域）
 *
 * ── 两条链（跨卡事实，本卡 0 写点）─────────────────────────────────────────
 *   A 链（活动）room+0x84 头 / room+0x80 尾 / room+0x88 计数，depth 降序
 *   B 链（失活）room+0x90 头 / room+0x8c 尾 / room+0x94 计数，头插无序
 *   ⇒ 本卡 9 个函数**没有一个**写 room+0x80..0x94，也**没有一个**写 inst+0x178/+0x17c：
 *      它们只写 inst+0x69（经 SetDeactivated）并把实例追加进待办表。
 *      真正搬链的是 CRoom::UpdateActive（见 CRoom_UpdateActive 卡）与 CLayerManager::
 *      UpdateInstanceActivation（g_isZeus != 0 时 SetDeactivated 尾调 0x1b8a28）。
 *
 * ── 待办表 g_InstanceActivateDeactive（0x542a4c，4 个开关函数都往里追加）─────
 *   List<CInstance*>：{ptr=[0], cap=[+4], count=[+8]}，12 字节。
 *   Alloc/ReAlloc 的 file 串：List.h 的 0x338700 "jni/../jni/yoyo/../../../Platform/List.h"（行 50）、
 *   MemoryManager.h 的 0x331038（行 74）；初始 Alloc(128) = 32 槽，满了 cap*2、字节 = cap*4。
 *   消费端（跨卡）：ProcessActivateDeactveLists 0x1d3074 调 CRoom::UpdateActive() 后把 count 清 0。
 *
 * ── 返回值编码（9 个里只有 5 个写 result）────────────────────────────────
 *   instance_create      : 成功 = (double)inst->[0x78]（tag 0）；失败 = -1.0（高字 0xbff00000）；
 *                          若 g_fJSGarbageCollection(0x47f295) != 0 → [result] = inst 指针、tag = 6
 *   distance_to_object   : double，初值 1e6（0x412e848000000000），全表取最小
 *   place_meeting        : double 0.0 / 1.0（高字 0x3ff00000）
 *   collision_point/line : 命中 = (double)inst->[0x78]，否则 -4.0（高字 0xc0100000 = noone）
 *   四个开关函数        : **完全不写 result**（槽位保持调用方原值）
 *
 * ── 碰撞侧怎么用 RTree（本卡只到调用边界；Command_* 内部为旁证，无锚点）──────
 *   1. 全局 g_tree（0x5429a8，4 字节）**懒建**：CollisionUpdate 0x1cdc7c 读它，为 0 时
 *      0x1cdd48 new(24) + RTree::RTree(1024) 再写回；此后 Remove/InsertRect 都在这一棵树上。
 *   2. 唯一插桩点是 CollisionUpdate(inst, tagYYRECT&) 0x1cdc1c，由 CInstance::Compute_BoundingBox
 *      (updateRTree=true) 尾调 0x19265c：先 RTree::Remove(旧盒 min/max 角) 0x1cdcd8，
 *      再按 inst+0xe8..+0xf4 新盒 RTree::InsertRect 0x1cdd3c。四道闸（任一不过就只返回）：
 *      option_use_fast_collision(0x542379) == 0 → 退；inst+0x68；inst+0x69；[inst+0x80]->[0] & 0x10 == 0。
 *   3. 延迟刷树：UpdateTree() 0x1cc24c 遍历脏表 s_dirty_list(0x5429ac)，对 +0x68/+0x69 都为 0 的
 *      实例调 Compute_BoundingBox(inst,1)，边算边摘链（脏表清空）。
 *   4. place_meeting 的快路：Command_InstancePlace 0x1ca6d8 先问 ShouldUseFastCollision(objint,&obj)
 *      0x1c8df8：objint > 0x1869F → 2；option_use_fast_collision == 0 → 2；objint == -3 → 1；
 *      对象不存在 → -1；否则 obj->[0xd8] >= *(g_tree->[0x10]+4) → 1 否则 2。只有 1 走树：
 *      UpdateTree() → 组 lo/hi 两角（inst+0xe8..+0xf4 的 min/max）→ 目标槽 0x3f50e8 = objint、
 *      结果槽 s_instancePtr(0x5428b8) 清 0 → RTree::Search(lo, hi, 回调 0x1c8648, self) 0x10d720
 *      → 从 s_instancePtr 取命中实例。
 *   5. collision_line 的快路：Command_CollisionLine 0x1cb390 的 0x1cb5b8 块同样 UpdateTree()，
 *      组 Line（float→double→int 混排）后 SearchLine(g_tree, g_tree->[0x10], &line, &count,
 *      回调 0x1c8504, self) 0x1cb234，结果仍从 s_instancePtr 读。
 *   6. collision_point **不进树**：Command_CollisionPoint 0x1c89a4 全程没有 UpdateTree/Search，
 *      只按三条路逐实例调 CInstance::Collision_Point(x,y,precise) 0x1944b0：
 *      objint == -3 → Run_Room(0x54298c)->[0x80] 链（沿 +0x178 走）；> 0x1869F → ms_ID2Instance 查表；
 *      否则 g_ObjectHash(0x542374) → obj->[0xd0] 的节点链 {next, inst}。
 *
 * ── 逐条锚点（9 节）─────────────────────────────────────────────────────
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 1 · F_InstanceActivateAll（instance_activate_all）
 * @func 0x10bde4 0x10beac  size 204  51 条（49 条指令 + 2 个池字 0x10bea8/0x10beac）
 * 符号: _Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_
 * 一句话: 把 GetDeactiveList(0) 里「+0x68 == 0 且 +0x69 != 0」的实例逐个 SetDeactivated(inst,false)，
 *         并把指针追加进 g_InstanceActivateDeactive；self/other/args 一个都不用，result 不写。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 1.1 拿表（0x10bde4..0x10bdfc）─────────────────────────────────────
 *   GetDeactiveList(0)：实参 0 = 不传回调（该函数按 fn 是否为 0 决定「逐个回调」还是「收进 List」）。
 *   返回值是 12 字节 List<CInstance*>：ptr=[r0]、cap=[r0+4]、count=[r0+8]（后两者在第 1.3 段用到）。
 *   本函数不需要 self/other/args —— 这也是它唯一一次 bl。 */
/* @0x10bde4 push {r4, r5, r6, r7, r8, lr} */
/* @0x10bde8 mov r0, #0 */
/* @0x10bdec sub sp, sp, #8 */
/* @0x10bdf0 bl 0x10baf8 <_Z15GetDeactiveListPFvP9CInstanceE> */
/* @0x10bdf4 ldr r1, [r0, #0x8] */
/* @0x10bdf8 mov r7, r0 */
/* @0x10bdfc cmp r1, #0 */
/* ── 1.2 循环头 + 两道闸（0x10be00..0x10be34）──────────────────────────
 *   下标遍历：0x10be10 取 ptr、0x10be14 取 ptr[i]；count 在 0x10be60 每次回读（本函数不改 count 的来源表）。
 *   闸 1（0x10be18/0x10be20）：inst+0x68 != 0 → 跳过。
 *   闸 2（0x10be24/0x10be30）：inst+0x69 == 0 → 跳过 ⇒ 只捞「已标记失活」的，已活动的不重复处理。
 *   0x10be28 的 r6 是 GOT 偏移（0x2e1e14），0x10be34 用它解出 g_InstanceActivateDeactive 的绝对地址。 */
/* @0x10be00 ble 0x10be70 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x10be04 ldr r8, [pc, #0x9c] */
/* @0x10be08 mov r4, #0 */
/* @0x10be0c add r8, pc, r8 */
/* @0x10be10 ldr r3, [r7] */
/* @0x10be14 ldr r5, [r3, r4, lsl #2] */
/* @0x10be18 ldrb r3, [r5, #0x68] */
/* @0x10be1c cmp r3, #0 */
/* @0x10be20 bne 0x10be64 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x10be24 ldrb r2, [r5, #0x69] */
/* @0x10be28 ldr r6, [pc, #0x7c] */
/* @0x10be2c cmp r2, #0 */
/* @0x10be30 beq 0x10be64 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x10be34 ldr r6, [pc, r6] */
/* ── 1.3 追加 + 改状态（0x10be38..0x10be5c）───────────────────────────
 *   ldmib（0x10be38）取 {r2 = [g+4] = cap, r3 = [g+8] = count}；cap == count → 走 0x10be78 翻倍。
 *   0x10be48 起的 r1 = 0 是 SetDeactivated 的实参；先写 list[count]、count+1，再 bl SetDeactivated
 *   ⇒ 顺序是「先记账、后写 +0x69」，四个开关函数里三个是这个顺序（唯一例外见节 4）。 */
/* @0x10be38 ldmib r6, {r1, r2} */
/* @0x10be3c cmp r2, r1 */
/* @0x10be40 beq 0x10be78 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x10be44 ldr r12, [r6] */
/* @0x10be48 mov r1, #0 */
/* @0x10be4c str r5, [r12, r2, lsl #2] */
/* @0x10be50 mov r0, r5 */
/* @0x10be54 add r3, r2, #1 */
/* @0x10be58 str r3, [r6, #0x8] */
/* @0x10be5c bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* ── 1.4 循环尾与出口（0x10be60..0x10be74）────────────────────────────
 *   回读 count 后自增下标，`bgt` 回 0x10be10；出循环只 add sp/pop。
 *   ⇒ 全函数没有一条写 result（r0 在入口就是 &result，之后只当 scratch）。 */
/* @0x10be60 ldr r1, [r7, #0x8] */
/* @0x10be64 add r4, r4, #1 */
/* @0x10be68 cmp r1, r4 */
/* @0x10be6c bgt 0x10be10 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x10be70 add sp, sp, #8 */
/* @0x10be74 pop {r4, r5, r6, r7, r8, pc} */
/* ── 1.5 满容翻倍（0x10be78..0x10bea4）──────────────────────────────
 *   新 cap = count*2（0x10be78 lsl #1）、字节数 = count*8 = 新 cap*4（0x10be84）、
 *   ReAlloc(ptr, 字节, "Platform/MemoryManager.h"(0x331038), 74) 后回 0x10be48 写。
 *   同一模板在本卡另外 4 处内联出现（0x10c130 / 0x10c178 / 0x10c1ac / 0x10c1f8，见节 2.10）。 */
/* @0x10be78 lsl r12, r2, #1 */
/* @0x10be7c ldr r0, [r6] */
/* @0x10be80 str r12, [r6, #0x4] */
/* @0x10be84 lsl r1, r2, #3 */
/* @0x10be88 str r3, [sp] */
/* @0x10be8c mov r2, r8 */
/* @0x10be90 mov r3, #74 */
/* @0x10be94 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10be98 ldr r2, [r6, #0x8] */
/* @0x10be9c mov r12, r0 */
/* @0x10bea0 str r0, [r6] */
/* @0x10bea4 b 0x10be48 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x64> */
/* ── 1.6 池字（0x10bea8/0x10beac，非指令）─────────────────────────────
 *   0x10bea8 是 0x10be04 的 ldr 字面（GOT 偏移 0x225224），0x10beac 是 0x10be28 的字面（0x2e1e14）；
 *   objdump 按 ARM 译成 eoreq，按规矩保留原写法、只标注它不是指令。 */
/* @0x10bea8 eoreq r5, r2, r4, lsr #4 —— 非指令（字面池） */
/* @0x10beac eoreq r1, lr, r4, lsl lr —— 非指令（字面池） */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 2 · F_InstanceActivateObject（instance_activate_object）
 * @func 0x10beb0 0x10c248  size 924  231 条（223 条指令 + 8 个池字 0x10c22c..0x10c248）
 * 符号: _Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_
 * 一句话: 按 objint 五路分派（-1 self / -2 other / -3 整表 / >0x1869F 实例 id / 对象索引+继承），
 *         把命中实例追加进 g_InstanceActivateDeactive 并 SetDeactivated(inst,false)；result 不写。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 2.1 入口（0x10beb0..0x10bed0）─────────────────────────────────────
 *   self→r4、other→r5、objint = YYGetInt32(args,0)→r6（args 在 [sp,#0x30]）。
 *   0x10becc 取字面、0x10bed0 `add r8, pc, r8` ⇒ r8 = GOT 基址 **0x3f1c58**；
 *   之后所有全局都用 `ldr rX, [r8, 负偏移]` 取（负偏移写在池里，见 2.11）。 */
/* @0x10beb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10beb4 sub sp, sp, #12 */
/* @0x10beb8 mov r4, r1 */
/* @0x10bebc mov r1, #0 */
/* @0x10bec0 ldr r0, [sp, #0x30] */
/* @0x10bec4 mov r5, r2 */
/* @0x10bec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10becc ldr r8, [pc, #0x358] */
/* @0x10bed0 add r8, pc, r8 */
/* ── 2.2 五路分派（0x10bed4..0x10befc）────────────────────────────────
 *   `cmn r0,#1/#2/#3`（即 r0 == -1/-2/-3）分别跳 0x10c018 / 0x10c058 / 0x10c0a8。
 *   0x1869F（= 99999）由 movw+movt 拼出，`bgt` 走 0x10bfb0 的实例 id 路径；否则落对象索引路径。
 *   ⇒ 分派顺序 = 三个特殊负数 → id 区 → 对象索引，没有第七种。 */
/* @0x10bed4 cmn r0, #1 */
/* @0x10bed8 mov r6, r0 */
/* @0x10bedc beq 0x10c018 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x10bee0 cmn r0, #2 */
/* @0x10bee4 beq 0x10c058 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x10bee8 cmn r0, #3 */
/* @0x10beec beq 0x10c0a8 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x10bef0 movw r3, #0x869f */
/* @0x10bef4 movt r3, #0x1 */
/* @0x10bef8 cmp r0, r3 */
/* @0x10befc bgt 0x10bfb0 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x100> */
/* ── 2.3 对象索引路径：取表、置游标（0x10bf00..0x10bf28）─────────────────
 *   同样 GetDeactiveList(0)（0x10bf00 的 r0 = 0 = NULL 回调）；空表直接 0x10c010 出口。
 *   r10 = "Platform/MemoryManager.h" 串（扩容时给 ReAlloc 的 file），r4 = 下标，r9 = 0（ReAlloc 第 5 参）。
 *   0x10bf28 直接跳进循环尾 0x10bf6c —— 先判条件再进体。 */
/* @0x10bf00 mov r0, #0 */
/* @0x10bf04 bl 0x10baf8 <_Z15GetDeactiveListPFvP9CInstanceE> */
/* @0x10bf08 ldr r2, [r0, #0x8] */
/* @0x10bf0c mov r11, r0 */
/* @0x10bf10 cmp r2, #0 */
/* @0x10bf14 ble 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bf18 ldr r10, [pc, #0x310] */
/* @0x10bf1c mov r4, #0 */
/* @0x10bf20 mov r9, r4 */
/* @0x10bf24 add r10, pc, r10 */
/* @0x10bf28 b 0x10bf6c <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0xbc> */
/* ── 2.4 追加尾（0x10bf2c..0x10bf5c）───────────────────────────────────
 *   0x10bf2c 的偏移 0xffffbff8 = -0x4008 ⇒ [r8-0x4008] = GOT 槽 0x3edc50 = &g_InstanceActivateDeactive。
 *   ldmib 取 {cap=[g+4], count=[g+8]}；满 → 0x10c130；否则写 list[count]、count+1、
 *   再 SetDeactivated(inst, r1=0)（0x10bf48 的 r1 = 0）。
 *   这一段只服务**对象索引路径**（实例在 r5）；id 路径另有自己的一份（0x10c160..0x10c1a8，实例在 r4），
 *   -1/-2 路径用 0x10c044 / 0x10c088 两处。 */
/* @0x10bf2c ldr r3, [pc, #0x300] */
/* @0x10bf30 ldr r7, [r8, r3] */
/* @0x10bf34 ldmib r7, {r2, r3} */
/* @0x10bf38 cmp r3, r2 */
/* @0x10bf3c ldrne r2, [r7] */
/* @0x10bf40 beq 0x10c130 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x280> */
/* @0x10bf44 str r5, [r2, r3, lsl #2] */
/* @0x10bf48 mov r0, r5 */
/* @0x10bf4c mov r1, #0 */
/* @0x10bf50 add r3, r3, #1 */
/* @0x10bf54 str r3, [r7, #0x8] */
/* @0x10bf58 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10bf5c ldr r2, [r11, #0x8] */
/* ── 2.5 循环尾 + 对象匹配（0x10bf60..0x10bfac）────────────────────────
 *   回读 count、自增下标、`ble` 出口。
 *   两道闸：0x10bf74/0x10bf7c（+0x68 != 0 → 跳）、0x10bf80/0x10bf88（+0x69 == 0 → 跳）。
 *   匹配（0x10bf8c）：inst+0x7c == objint → 命中；否则 0x10bf98 取 inst+0x80（CObjectGM*）当 this，
 *   调 IsDecendentOf(objint)——非 0 也命中 ⇒ 子对象一并激活，且判据是对象表的继承链，不是比类型。 */
/* @0x10bf60 add r4, r4, #1 */
/* @0x10bf64 cmp r2, r4 */
/* @0x10bf68 ble 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bf6c ldr r3, [r11] */
/* @0x10bf70 ldr r5, [r3, r4, lsl #2] */
/* @0x10bf74 ldrb r3, [r5, #0x68] */
/* @0x10bf78 cmp r3, #0 */
/* @0x10bf7c bne 0x10bf60 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10bf80 ldrb r3, [r5, #0x69] */
/* @0x10bf84 cmp r3, #0 */
/* @0x10bf88 beq 0x10bf60 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10bf8c ldr r3, [r5, #0x7c] */
/* @0x10bf90 cmp r6, r3 */
/* @0x10bf94 beq 0x10bf2c <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x10bf98 ldr r0, [r5, #0x80] */
/* @0x10bf9c mov r1, r6 */
/* @0x10bfa0 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x10bfa4 cmp r0, #0 */
/* @0x10bfa8 bne 0x10bf2c <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x10bfac b 0x10bf5c <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0xac> */
/* ── 2.6 实例 id 路径（0x10bfb0..0x10c00c）────────────────────────────
 *   0x10bfb0 的偏移 0xffffbff4 = -0x400c ⇒ GOT 槽 0x3edc4c = &CInstance::ms_ID2Instance（0x536f28）。
 *   表布局与 g_ObjectHash 同构：mask=[map+4]、ptr=[map]、桶地址 = ptr + (id & mask)*8，
 *   节点 {next=[+4], key=[+8], value=[+0xc]}；只有 key 命中才取 value，value 再当 CInstance* 用。
 *   取到实例后仍要过 +0x68/+0x69 两闸（0x10bff8/0x10c004），过了才 0x10c160 追加。 */
/* @0x10bfb0 ldr r3, [pc, #0x280] */
/* @0x10bfb4 ldr r3, [r8, r3] */
/* @0x10bfb8 ldr r2, [r3, #0x4] */
/* @0x10bfbc ldr r3, [r3] */
/* @0x10bfc0 and r2, r0, r2 */
/* @0x10bfc4 ldr r3, [r3, r2, lsl #3] */
/* @0x10bfc8 cmp r3, #0 */
/* @0x10bfcc bne 0x10bfe0 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x10bfd0 b 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bfd4 ldr r3, [r3, #0x4] */
/* @0x10bfd8 cmp r3, #0 */
/* @0x10bfdc beq 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bfe0 ldr r2, [r3, #0x8] */
/* @0x10bfe4 cmp r6, r2 */
/* @0x10bfe8 bne 0x10bfd4 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x10bfec ldr r4, [r3, #0xc] */
/* @0x10bff0 cmp r4, #0 */
/* @0x10bff4 beq 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bff8 ldrb r12, [r4, #0x68] */
/* @0x10bffc cmp r12, #0 */
/* @0x10c000 bne 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c004 ldrb r3, [r4, #0x69] */
/* @0x10c008 cmp r3, #0 */
/* @0x10c00c bne 0x10c160 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* ── 2.7 出口 + -1 路径（0x10c010..0x10c054）──────────────────────────
 *   出口只有 add sp/pop（0x10c010/0x10c014）。
 *   -1：self(r4) != 0 且 self+0x68 == 0 → 追加 self、尾调 SetDeactivated(self,0)；
 *       满容 → 0x10c1dc。0x10c044 是「写 list[count]」的共用点（id 路径也跳回这里，实例都在 r4）。
 *   ⚠ 这一路**不看 +0x69**：对已失活实例是直接激活，对已活动实例是「再记一次账」⇒ 表里可能出现重复项。 */
/* @0x10c010 add sp, sp, #12 */
/* @0x10c014 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10c018 cmp r4, #0 */
/* @0x10c01c beq 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c020 ldrb r12, [r4, #0x68] */
/* @0x10c024 cmp r12, #0 */
/* @0x10c028 bne 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c02c ldr r3, [pc, #0x200] */
/* @0x10c030 ldr r7, [r8, r3] */
/* @0x10c034 ldr r1, [r7, #0x8] */
/* @0x10c038 ldr r3, [r7, #0x4] */
/* @0x10c03c cmp r1, r3 */
/* @0x10c040 beq 0x10c1dc <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x32c> */
/* @0x10c044 ldr r3, [r7] */
/* @0x10c048 str r4, [r3, r1, lsl #2] */
/* @0x10c04c mov r0, r4 */
/* @0x10c050 add r3, r1, #1 */
/* @0x10c054 b 0x10c094 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* ── 2.8 -2 路径（0x10c058..0x10c0a4）─────────────────────────────────
 *   与 -1 同构，对象换成 other(r5)：只判 +0x68；满容 → 0x10c1f8；追加点 0x10c088。
 *   0x10c094 起是 -1/-2 共用的收尾（写 count、pop、尾调 SetDeactivated）。 */
/* @0x10c058 cmp r5, #0 */
/* @0x10c05c beq 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c060 ldrb r12, [r5, #0x68] */
/* @0x10c064 cmp r12, #0 */
/* @0x10c068 bne 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c06c ldr r3, [pc, #0x1c0] */
/* @0x10c070 ldr r7, [r8, r3] */
/* @0x10c074 ldr r1, [r7, #0x8] */
/* @0x10c078 ldr r3, [r7, #0x4] */
/* @0x10c07c cmp r1, r3 */
/* @0x10c080 beq 0x10c1f8 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x348> */
/* @0x10c084 ldr r3, [r7] */
/* @0x10c088 str r5, [r3, r1, lsl #2] */
/* @0x10c08c add r3, r1, #1 */
/* @0x10c090 mov r0, r5 */
/* @0x10c094 mov r1, #0 */
/* @0x10c098 str r3, [r7, #0x8] */
/* @0x10c09c add sp, sp, #12 */
/* @0x10c0a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10c0a4 b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* ── 2.9 -3 路径：整张失活表（0x10c0a8..0x10c12c）───────────────────────
 *   与 instance_activate_all 同一份逻辑：GetDeactiveList(0) → 下标遍历 → +0x68==0 且 +0x69!=0
 *   → 追加 + SetDeactivated(inst,0)；满容 → 0x10c1ac。
 *   注意 0x10c0b4 `mov r6, r0` 把 objint 覆盖成表指针（此后不再需要 objint）。 */
/* @0x10c0a8 mov r0, #0 */
/* @0x10c0ac bl 0x10baf8 <_Z15GetDeactiveListPFvP9CInstanceE> */
/* @0x10c0b0 ldr r2, [r0, #0x8] */
/* @0x10c0b4 mov r6, r0 */
/* @0x10c0b8 cmp r2, #0 */
/* @0x10c0bc ble 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c0c0 ldr r9, [pc, #0x174] */
/* @0x10c0c4 mov r4, #0 */
/* @0x10c0c8 add r9, pc, r9 */
/* @0x10c0cc ldr r3, [r6] */
/* @0x10c0d0 ldr r5, [r3, r4, lsl #2] */
/* @0x10c0d4 ldrb r3, [r5, #0x68] */
/* @0x10c0d8 cmp r3, #0 */
/* @0x10c0dc bne 0x10c120 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x270> */
/* @0x10c0e0 ldrb r1, [r5, #0x69] */
/* @0x10c0e4 ldr r0, [pc, #0x148] */
/* @0x10c0e8 cmp r1, #0 */
/* @0x10c0ec beq 0x10c120 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x270> */
/* @0x10c0f0 ldr r7, [r8, r0] */
/* @0x10c0f4 ldmib r7, {r1, r2} */
/* @0x10c0f8 cmp r2, r1 */
/* @0x10c0fc beq 0x10c1ac <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x10c100 ldr r12, [r7] */
/* @0x10c104 str r5, [r12, r2, lsl #2] */
/* @0x10c108 mov r1, #0 */
/* @0x10c10c mov r0, r5 */
/* @0x10c110 add r3, r2, #1 */
/* @0x10c114 str r3, [r7, #0x8] */
/* @0x10c118 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10c11c ldr r2, [r6, #0x8] */
/* @0x10c120 add r4, r4, #1 */
/* @0x10c124 cmp r2, r4 */
/* @0x10c128 bgt 0x10c0cc <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x10c12c b 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* ── 2.10 满容翻倍：4 份完整拷贝 + 1 份借尾（0x10c130..0x10c228）─────────
 *   0x10c130 对象索引（回 0x10bf44）｜0x10c178 id 路径（回 0x10c048）｜0x10c1ac -3 路径（回 0x10c104）
 *   ｜0x10c1dc -1 路径（借 0x10c190 的尾部，回 0x10c048）｜0x10c1f8 -2 路径（回 0x10c088）。
 *   五处都是「新 cap = count*2、字节数 = count*8、ReAlloc(...,"Platform/MemoryManager.h",74)」的一遍内联。 */
/* @0x10c130 lsl r2, r3, #1 */
/* @0x10c134 ldr r0, [r7] */
/* @0x10c138 str r2, [r7, #0x4] */
/* @0x10c13c lsl r1, r3, #3 */
/* @0x10c140 mov r2, r10 */
/* @0x10c144 mov r3, #74 */
/* @0x10c148 str r9, [sp] */
/* @0x10c14c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10c150 ldr r3, [r7, #0x8] */
/* @0x10c154 mov r2, r0 */
/* @0x10c158 str r0, [r7] */
/* @0x10c15c b 0x10bf44 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x10c160 ldr r3, [pc, #0xcc] */
/* @0x10c164 ldr r7, [r8, r3] */
/* @0x10c168 ldr r1, [r7, #0x8] */
/* @0x10c16c ldr r3, [r7, #0x4] */
/* @0x10c170 cmp r1, r3 */
/* @0x10c174 bne 0x10c044 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x10c178 ldr r2, [pc, #0xc0] */
/* @0x10c17c lsl r3, r1, #1 */
/* @0x10c180 ldr r0, [r7] */
/* @0x10c184 lsl r1, r1, #3 */
/* @0x10c188 add r2, pc, r2 */
/* @0x10c18c str r3, [r7, #0x4] */
/* @0x10c190 mov r3, #74 */
/* @0x10c194 str r12, [sp] */
/* @0x10c198 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10c19c ldr r1, [r7, #0x8] */
/* @0x10c1a0 mov r3, r0 */
/* @0x10c1a4 str r0, [r7] */
/* @0x10c1a8 b 0x10c048 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x10c1ac lsl r12, r2, #1 */
/* @0x10c1b0 ldr r0, [r7] */
/* @0x10c1b4 str r12, [r7, #0x4] */
/* @0x10c1b8 lsl r1, r2, #3 */
/* @0x10c1bc str r3, [sp] */
/* @0x10c1c0 mov r2, r9 */
/* @0x10c1c4 mov r3, #74 */
/* @0x10c1c8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10c1cc ldr r2, [r7, #0x8] */
/* @0x10c1d0 mov r12, r0 */
/* @0x10c1d4 str r0, [r7] */
/* @0x10c1d8 b 0x10c104 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x10c1dc ldr r2, [pc, #0x60] */
/* @0x10c1e0 lsl r3, r1, #1 */
/* @0x10c1e4 ldr r0, [r7] */
/* @0x10c1e8 lsl r1, r1, #3 */
/* @0x10c1ec str r3, [r7, #0x4] */
/* @0x10c1f0 add r2, pc, r2 */
/* @0x10c1f4 b 0x10c190 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x2e0> */
/* @0x10c1f8 ldr r2, [pc, #0x48] */
/* @0x10c1fc lsl r3, r1, #1 */
/* @0x10c200 ldr r0, [r7] */
/* @0x10c204 lsl r1, r1, #3 */
/* @0x10c208 str r3, [r7, #0x4] */
/* @0x10c20c add r2, pc, r2 */
/* @0x10c210 mov r3, #74 */
/* @0x10c214 str r12, [sp] */
/* @0x10c218 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10c21c ldr r1, [r7, #0x8] */
/* @0x10c220 mov r3, r0 */
/* @0x10c224 str r0, [r7] */
/* @0x10c228 b 0x10c088 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* ── 2.11 池字（0x10c22c..0x10c248，非指令）─────────────────────────────
 *   依次是：0x2e5d80（0x10becc → GOT 基址）、0x22510c、0xffffbff8、0xffffbff4、
 *   0x224f68、0x224ea8、0x224e40、0x224e24 —— 全部被 ldr 当字面读，objdump 译成 eoreq/未识别。 */
/* @0x10c22c eoreq r5, lr, r0, lsl #27 —— 非指令（字面池） */
/* @0x10c230 eoreq r5, r2, r12, lsl #2 —— 非指令（字面池） */
/* @0x10c234 .word 0xffffbff8 —— 非指令（字面池） */
/* @0x10c238 .word 0xffffbff4 —— 非指令（字面池） */
/* @0x10c23c eoreq r4, r2, r8, ror #30 —— 非指令（字面池） */
/* @0x10c240 eoreq r4, r2, r8, lsr #29 —— 非指令（字面池） */
/* @0x10c244 eoreq r4, r2, r0, asr #28 —— 非指令（字面池） */
/* @0x10c248 eoreq r4, r2, r4, lsr #28 —— 非指令（字面池） */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 3 · F_InstanceDeactivateAll（instance_deactivate_all）
 * @func 0x10b480 0x10b5f0  size 372  93 条（89 条指令 + 4 个池字 0x10b5e4..0x10b5f0）
 * 符号: _Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_
 * 一句话: 遍历 GetActiveList(0) 的快照，把「+0x68==0 且 +0x69==0」的实例逐个 SetDeactivated(inst,true)；
 *         若 self != 0 且 args[0]（notme）为真，最后再把 self 追加进表并 SetDeactivated(self,**false**)。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 3.1 入口 + 取活动表（0x10b480..0x10b4b0）───────────────────────────
 *   self→r7、args→r8（[sp,#0x28]）；GetActiveList(0) 在 0x10b494，返回 12 字节 List。
 *   与 GetDeactiveList 的差别只在返回哪张表：GetActiveList 内部走 room+0x80 与 room+0x8c 两条链的**尾**，
 *   沿 +0x178（prev）向头走，只收「+0x68==0 且 +0x69==0」的实例（0x10b294/0x10b2dc 两处同样的闸）。 */
/* @0x10b480 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10b484 sub sp, sp, #8 */
/* @0x10b488 mov r0, #0 */
/* @0x10b48c mov r7, r1 */
/* @0x10b490 ldr r8, [sp, #0x28] */
/* @0x10b494 bl 0x10b24c <_Z13GetActiveListPFvP9CInstanceE> */
/* @0x10b498 ldr r9, [pc, #0x144] */
/* @0x10b49c mov r4, #0 */
/* @0x10b4a0 add r9, pc, r9 */
/* @0x10b4a4 ldr r2, [r0, #0x8] */
/* @0x10b4a8 mov r10, r0 */
/* @0x10b4ac cmp r2, #0 */
/* @0x10b4b0 ble 0x10b514 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x94> */
/* ── 3.2 循环：双闸 + 追加 + 灭活（0x10b4b4..0x10b510）────────────────────
 *   闸 1（0x10b4bc/0x10b4c4）：+0x68 != 0 → 跳过。闸 2（0x10b4c8/0x10b4d0）：+0x69 != 0 → 跳过。
 *   ⇒ 只捞活动实例；已经失活的不会被二次处理（第二次调用 instance_deactivate_all 是空转）。
 *   0x10b4d4 的偏移 0x2e2770 ⇒ GOT 槽 0x3edc50 = &g_InstanceActivateDeactive（与节 1/2 同一张表）。
 *   0x10b4ec 的 r1 = 1 是 SetDeactivated 的实参（灭活）；顺序仍是「先记账、后写 +0x69」。 */
/* @0x10b4b4 ldr r3, [r10] */
/* @0x10b4b8 ldr r5, [r3, r4, lsl #2] */
/* @0x10b4bc ldrb r3, [r5, #0x68] */
/* @0x10b4c0 cmp r3, #0 */
/* @0x10b4c4 bne 0x10b508 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x10b4c8 ldrb r12, [r5, #0x69] */
/* @0x10b4cc cmp r12, #0 */
/* @0x10b4d0 bne 0x10b508 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x10b4d4 ldr r6, [pc, #0x10c] */
/* @0x10b4d8 ldr r6, [pc, r6] */
/* @0x10b4dc ldmib r6, {r2, r3} */
/* @0x10b4e0 cmp r3, r2 */
/* @0x10b4e4 beq 0x10b544 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x10b4e8 ldr r12, [r6] */
/* @0x10b4ec mov r1, #1 */
/* @0x10b4f0 str r5, [r12, r3, lsl #2] */
/* @0x10b4f4 mov r0, r5 */
/* @0x10b4f8 add r2, r3, r1 */
/* @0x10b4fc str r2, [r6, #0x8] */
/* @0x10b500 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10b504 ldr r2, [r10, #0x8] */
/* @0x10b508 add r4, r4, #1 */
/* @0x10b50c cmp r2, r4 */
/* @0x10b510 bgt 0x10b4b4 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x34> */
/* ── 3.3 notme 块（0x10b514..0x10b540）────────────────────────────────
 *   三个条件：self(r7) != 0、YYGetBool(args,0) != 0、self+0x68 == 0 → 才去 0x10b574。
 *   ⚠ 这里**不看 +0x69**：循环刚把 self 的 +0x69 置 1，全靠这一点实现「全灭后再点亮自己」；
 *     反过来说，若调用前 self 本来就是失活态（循环跳过了它），这一块会把它静默激活 —— 代码事实，动机见 open。 */
/* @0x10b514 cmp r7, #0 */
/* @0x10b518 beq 0x10b53c <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x10b51c mov r0, r8 */
/* @0x10b520 mov r1, #0 */
/* @0x10b524 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b528 cmp r0, #0 */
/* @0x10b52c beq 0x10b53c <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x10b530 ldrb r12, [r7, #0x68] */
/* @0x10b534 cmp r12, #0 */
/* @0x10b538 beq 0x10b574 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x10b53c add sp, sp, #8 */
/* @0x10b540 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ── 3.4 满容翻倍（0x10b544..0x10b570）────────────────────────────────
 *   与节 1.5 同一模板；r9 是 "Platform/MemoryManager.h" 串，回 0x10b4ec 写 list[count]。 */
/* @0x10b544 lsl r2, r3, #1 */
/* @0x10b548 ldr r0, [r6] */
/* @0x10b54c str r2, [r6, #0x4] */
/* @0x10b550 lsl r1, r3, #3 */
/* @0x10b554 str r12, [sp] */
/* @0x10b558 mov r3, #74 */
/* @0x10b55c mov r2, r9 */
/* @0x10b560 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10b564 ldr r3, [r6, #0x8] */
/* @0x10b568 mov r12, r0 */
/* @0x10b56c str r0, [r6] */
/* @0x10b570 b 0x10b4ec <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x6c> */
/* ── 3.5 点亮 self（0x10b574..0x10b5e0）───────────────────────────────
 *   0x10b574 的偏移 0x2e26d0 ⇒ 同一张 g_InstanceActivateDeactive；写 list[count] = self、
 *   count+1，然后 `mov r1, #0` + `b SetDeactivated`（尾调，没有第二个 bl）
 *   ⇒ notme 的实现是「先全灭（含自己）、再把自己写回活动」，不是「跳过自己」。
 *   满容分支在本段尾部（0x10b5b0..0x10b5e0），同样借 MemoryManager.h / 74。 */
/* @0x10b574 ldr r6, [pc, #0x70] */
/* @0x10b578 ldr r6, [pc, r6] */
/* @0x10b57c ldr r1, [r6, #0x8] */
/* @0x10b580 ldr r3, [r6, #0x4] */
/* @0x10b584 cmp r1, r3 */
/* @0x10b588 beq 0x10b5b0 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x10b58c ldr r3, [r6] */
/* @0x10b590 str r7, [r3, r1, lsl #2] */
/* @0x10b594 mov r0, r7 */
/* @0x10b598 add r3, r1, #1 */
/* @0x10b59c mov r1, #0 */
/* @0x10b5a0 str r3, [r6, #0x8] */
/* @0x10b5a4 add sp, sp, #8 */
/* @0x10b5a8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10b5ac b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10b5b0 ldr r2, [pc, #0x38] */
/* @0x10b5b4 lsl r3, r1, #1 */
/* @0x10b5b8 ldr r0, [r6] */
/* @0x10b5bc lsl r1, r1, #3 */
/* @0x10b5c0 str r3, [r6, #0x4] */
/* @0x10b5c4 add r2, pc, r2 */
/* @0x10b5c8 mov r3, #74 */
/* @0x10b5cc str r12, [sp] */
/* @0x10b5d0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10b5d4 ldr r1, [r6, #0x8] */
/* @0x10b5d8 mov r3, r0 */
/* @0x10b5dc str r0, [r6] */
/* @0x10b5e0 b 0x10b590 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x110> */
/* ── 3.6 池字（0x10b5e4..0x10b5f0，非指令）──────────────────────────────
 *   4 个字面：0x225b90（0x10b498 → MemoryManager.h 串）、0x2e2770（0x10b4d4 → 待办表 GOT）、
 *   0x2e26d0（0x10b574）、0x225a6c（0x10b5b0）。objdump 把它们译成 mlaeq/eoreq/.word。 */
/* @0x10b5e4 mlaeq r2, r0, r11, r5 —— 非指令（字面池） */
/* @0x10b5e8 eoreq r2, lr, r0, ror r7 —— 非指令（字面池） */
/* @0x10b5ec .word 0x002e26d0 —— 非指令（字面池） */
/* @0x10b5f0 eoreq r5, r2, r12, ror #20 —— 非指令（字面池） */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 4 · F_InstanceDeactivateObject（instance_deactivate_object）
 * @func 0x10a580 0x10a704  size 392  98 条（94 条指令 + 4 个池字 0x10a6f8..0x10a704）
 * 符号: _Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_
 * 一句话: 用 WithObjIterator(objint, self, other, false) 枚举目标实例，把「+0x68==0 且 +0x69==0」的
 *         收集进一个临时 List 并**立刻** SetDeactivated(inst,true)，循环结束后再整表追加到待办表。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 4.1 入口：临时 List + 迭代器（0x10a580..0x10a5e8）───────────────────
 *   objint = YYGetInt32(args,0)（args 在 [sp,#0x50]）→ r9；self→r7、other→r4。
 *   MemoryManager::Alloc(128, "Platform/List.h"(0x338700), 50, 1) ⇒ 32 槽的 List<CInstance*>（r8 = ptr）。
 *   0x10a5d4 才把 r7 改成 32（容量），此前 0x10a5c8/0x10a5cc 已把 self/other 读进 r2/r3 交给迭代器。
 *   WithObjIterator 拿 (objint, self, other, false)：-1 → self、-2 → other、-3 → room+0x80 链、
 *   >0x1869F → ms_ID2Instance、否则对象索引（g_ObjectHash → obj+0xd0 的节点链）；
 *   第 4 参 0 = 不含 B 链（de() 0x19dfd0 判 [it+0x20] 非 0 才会补一趟 room+0x8c）。 */
/* @0x10a580 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10a584 sub sp, sp, #48 */
/* @0x10a588 mov r7, r1 */
/* @0x10a58c mov r1, #0 */
/* @0x10a590 ldr r0, [sp, #0x50] */
/* @0x10a594 mov r4, r2 */
/* @0x10a598 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10a59c ldr r1, [pc, #0x154] */
/* @0x10a5a0 mov r2, #50 */
/* @0x10a5a4 mov r3, #1 */
/* @0x10a5a8 add r1, pc, r1 */
/* @0x10a5ac add r5, sp, #12 */
/* @0x10a5b0 mov r6, #0 */
/* @0x10a5b4 mov r9, r0 */
/* @0x10a5b8 mov r0, #128 */
/* @0x10a5bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10a5c0 mov r1, r9 */
/* @0x10a5c4 ldr r9, [pc, #0x130] */
/* @0x10a5c8 mov r2, r7 */
/* @0x10a5cc mov r3, r4 */
/* @0x10a5d0 str r6, [sp] */
/* @0x10a5d4 mov r7, #32 */
/* @0x10a5d8 add r9, pc, r9 */
/* @0x10a5dc mov r8, r0 */
/* @0x10a5e0 mov r0, r5 */
/* @0x10a5e4 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x10a5e8 b 0x10a630 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xb0> */
/* ── 4.2 枚举循环（0x10a5ec..0x10a640）───────────────────────────────
 *   de() → inst；闸 1（0x10a5f0/0x10a5fc）+0x68 != 0 → 跳；闸 2（0x10a600/0x10a608）+0x69 != 0 → 跳。
 *   收集：0x10a614 写 tmp[count]；满（count == cap）→ 0x10a6d4 把临时表翻倍。
 *   SetDeactivated(inst, r1=1) 在**循环内**（0x10a624），随后 Next() 推进。
 *   ⇒ 与另外三个开关函数的差别：这里先改状态、后记账（记账要等循环结束）。 */
/* @0x10a5ec bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10a5f0 ldrb r3, [r0, #0x68] */
/* @0x10a5f4 mov r4, r0 */
/* @0x10a5f8 cmp r3, #0 */
/* @0x10a5fc bne 0x10a628 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x10a600 ldrb r3, [r0, #0x69] */
/* @0x10a604 cmp r3, #0 */
/* @0x10a608 bne 0x10a628 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x10a60c cmp r6, r7 */
/* @0x10a610 beq 0x10a6d4 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x10a614 str r4, [r8, r6, lsl #2] */
/* @0x10a618 mov r1, #1 */
/* @0x10a61c mov r0, r4 */
/* @0x10a620 add r6, r6, r1 */
/* @0x10a624 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10a628 mov r0, r5 */
/* @0x10a62c bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x10a630 mov r0, r5 */
/* @0x10a634 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10a638 subs r4, r0, #0 */
/* @0x10a63c mov r0, r5 */
/* @0x10a640 bne 0x10a5ec <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x6c> */
/* ── 4.3 记账准备（0x10a644..0x10a660）────────────────────────────────
 *   count == 0 → 0x10a6c4 直接 Free 退出。
 *   0x10a64c 的 0x2e35f0 ⇒ GOT 槽 0x3edc50 = &g_InstanceActivateDeactive；r10 = MemoryManager.h 串。 */
/* @0x10a644 cmp r6, #0 */
/* @0x10a648 beq 0x10a6c4 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10a64c ldr r5, [pc, #0xac] */
/* @0x10a650 mov r9, r4 */
/* @0x10a654 ldr r10, [pc, #0xa8] */
/* @0x10a658 ldr r5, [pc, r5] */
/* @0x10a65c add r10, pc, r10 */
/* @0x10a660 ldr r1, [r5, #0x8] */
/* ── 4.4 整表追加（0x10a664..0x10a690）───────────────────────────────
 *   逐个把 tmp[i] 写进 g_InstanceActivateDeactive（下标 = 目标表自己的 count），满则翻倍（0x10a694 块）。 */
/* @0x10a664 b 0x10a684 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x10a668 ldr r3, [r5] */
/* @0x10a66c add r4, r4, #1 */
/* @0x10a670 str r7, [r3, r1, lsl #2] */
/* @0x10a674 cmp r4, r6 */
/* @0x10a678 add r1, r1, #1 */
/* @0x10a67c str r1, [r5, #0x8] */
/* @0x10a680 beq 0x10a6c4 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10a684 ldr r3, [r5, #0x4] */
/* @0x10a688 ldr r7, [r8, r4, lsl #2] */
/* @0x10a68c cmp r1, r3 */
/* @0x10a690 bne 0x10a668 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xe8> */
/* ── 4.5 目标表翻倍（0x10a694..0x10a6c0）───────────────────────────────
 *   与节 1.5 同模板，回 0x10a66c 写 list[count]。 */
/* @0x10a694 lsl r3, r1, #1 */
/* @0x10a698 ldr r0, [r5] */
/* @0x10a69c str r3, [r5, #0x4] */
/* @0x10a6a0 lsl r1, r1, #3 */
/* @0x10a6a4 mov r3, #74 */
/* @0x10a6a8 mov r2, r10 */
/* @0x10a6ac str r9, [sp] */
/* @0x10a6b0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10a6b4 ldr r1, [r5, #0x8] */
/* @0x10a6b8 mov r3, r0 */
/* @0x10a6bc str r0, [r5] */
/* @0x10a6c0 b 0x10a66c <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xec> */
/* ── 4.6 Free 出口 + 临时表翻倍（0x10a6c4..0x10a6f4）─────────────────────
 *   0x10a6c4/0x10a6c8 Free(临时表)，0x10a6cc/0x10a6d0 收帧。
 *   0x10a6d4..0x10a6f4 是 4.2 的满容分支：ReAlloc(r8, count*8（= 新 cap*4）, "…/MemoryManager.h", 74)，回 0x10a614。
 *   ⇒ 全函数两条 Free/ReAlloc 路径都用 MemoryManager，没有裸 malloc。 */
/* @0x10a6c4 mov r0, r8 */
/* @0x10a6c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x10a6cc add sp, sp, #48 */
/* @0x10a6d0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x10a6d4 str r3, [sp] */
/* @0x10a6d8 mov r0, r8 */
/* @0x10a6dc lsl r1, r6, #3 */
/* @0x10a6e0 mov r2, r9 */
/* @0x10a6e4 mov r3, #74 */
/* @0x10a6e8 lsl r7, r6, #1 */
/* @0x10a6ec bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10a6f0 mov r8, r0 */
/* @0x10a6f4 b 0x10a614 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x94> */
/* ── 4.7 池字（0x10a6f8..0x10a704，非指令）─────────────────────────────
 *   0x22e150（0x10a59c → List.h 串）、0x226a58（0x10a5c4）、0x2e35f0（0x10a64c）、
 *   0x2269d4（0x10a654）。后两个字被 ldr 读成 GOT 偏移，objdump 译成 eoreq/.word。 */
/* @0x10a6f8 eoreq lr, r2, r0, asr r1 —— 非指令（字面池） */
/* @0x10a6fc eoreq r6, r2, r8, asr r10 —— 非指令（字面池） */
/* @0x10a700 .word 0x002e35f0 —— 非指令（字面池） */
/* @0x10a704 .word 0x002269d4 —— 非指令（字面池） */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 5 · F_InstanceCreate（instance_create）
 * @func 0x109598 0x109630  size 156  39 条（38 条指令 + 1 个池字 0x109630）
 * 符号: _Z16F_InstanceCreateR6RValueP9CInstanceS2_iPS_
 * 一句话: 读 args[2]=obj、args[0]=x、args[1]=y 调 Command_Create，把结果按
 *         g_fJSGarbageCollection 分成「(double)inst->[0x78]」与「裸指针 + tag 6」两种编码返回。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 5.1 取参与创建（0x109598..0x1095dc）─────────────────────────────
 *   注意读参次序：**先 obj（args[2]）**，再 x（args[0]）、y（args[1]）—— 与 GML 的
 *   instance_create(x,y,obj) 的参数位置一致，但和 distance_to_object（obj 在 args[0]）不同。
 *   Command_Create 0x1c983c 内部：Object_Exists 闸（不存在走 Error_Show_Action 并返回 0）
 *   → CRoom::AddInstance(x,y,obj) 0x1ab144 → Perform_Event(inst,inst,14,0) 再 (…,0,0)
 *   → inst+0x6c = 1。 */
/* @0x109598 push {r3, r4, r5, r6, r7, lr} */
/* @0x10959c mov r1, #2 */
/* @0x1095a0 ldr r4, [sp, #0x18] */
/* @0x1095a4 mov r5, r0 */
/* @0x1095a8 mov r0, r4 */
/* @0x1095ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1095b0 mov r1, #0 */
/* @0x1095b4 mov r7, r0 */
/* @0x1095b8 mov r0, r4 */
/* @0x1095bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1095c0 mov r1, #1 */
/* @0x1095c4 mov r6, r0 */
/* @0x1095c8 mov r0, r4 */
/* @0x1095cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1095d0 mov r1, r6 */
/* @0x1095d4 mov r2, r0 */
/* @0x1095d8 mov r0, r7 */
/* @0x1095dc bl 0x1c983c <_Z14Command_Createiff> */
/* ── 5.2 g_fJSGarbageCollection 分支（0x1095e0..0x10961c）────────────────
 *   0x1095e0 的字面 ⇒ GOT 槽 0x3edbc0 → 0x47f295（1 字节）＝ g_fJSGarbageCollection。
 *   == 0（本作默认路径）：tag=0（0x1095f8），值 = inst ? (double)inst->[0x78] : -1.0
 *   （inst 为 0 时高字 0xbff00000、低字 0 = -1.0），stm 一次写两字。
 *   != 0：0x109620 走 tag = 6、[result] = inst 指针，且**不动** [result+4]。
 *   ⇒ +0x78 在这条路上被当「实例 id」用（与 place_meeting 的 -1/-2 代入同源）。 */
/* @0x1095e0 ldr r3, [pc, #0x48] */
/* @0x1095e4 ldr r3, [pc, r3] */
/* @0x1095e8 ldrb r3, [r3] */
/* @0x1095ec cmp r3, #0 */
/* @0x1095f0 bne 0x109620 <_Z16F_InstanceCreateR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1095f4 cmp r0, #0 */
/* @0x1095f8 str r3, [r5, #0xc] */
/* @0x1095fc ldrne r2, [r0, #0x78] */
/* @0x109600 moveq r3, #0 */
/* @0x109604 moveq r2, #0 */
/* @0x109608 movteq r3, #0xbff0 */
/* @0x10960c vmovne s15, r2 */
/* @0x109610 vcvtne.f64.s32 d7, s15 */
/* @0x109614 vmovne r2, r3, d7 */
/* @0x109618 stm r5, {r2, r3} */
/* @0x10961c pop {r3, r4, r5, r6, r7, pc} */
/* ── 5.3 tag 6 出口（0x109620..0x10962c）─────────────────────────────
 *   mov r3,#6 → [result+0xc] = 6；str r0,[result] = 裸指针；pop。
 *   ⚠ 与 DoConv 卡的类型表有张力：那边把运行期 tag 6 归进「Malformed variable」组 —— 记为 open。 */
/* @0x109620 mov r3, #6 */
/* @0x109624 str r0, [r5] */
/* @0x109628 str r3, [r5, #0xc] */
/* @0x10962c pop {r3, r4, r5, r6, r7, pc} */
/* ── 5.4 池字（0x109630，非指令）───────────────────────────────────────
 *   0x2e45d4 是 0x1095e0 的 ldr 字面（指向 g_fJSGarbageCollection 的 GOT 槽 0x3edbc0）。 */
/* @0x109630 .word 0x002e45d4 —— 非指令（字面池） */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 6 · F_DistanceToObject（distance_to_object）
 * @func 0x10ad88 0x10ae78  size 244  61 条（61 条指令，无池、无栈帧外扩）
 * 符号: _Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_
 * 一句话: result 先写 1e6，再用 WithObjIterator(obj,self,other,false) 枚举实例，取 FindDist(inst,self)
 *         的最小值写回 result；跳过 +0x68/+0x69 非 0 的实例。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 6.1 结果初值 1e6 + 迭代器（0x10ad88..0x10add8）─────────────────────
 *   三条写：0x10ad98 tag=0、0x10ada0 低字 0、0x10adb0 高字 0x412e8480
 *   ⇒ 0x412e848000000000 = **1000000.0**（不是 0，也不是 -1）。
 *   obj = YYGetInt32(args,0)，第 4 参 0（不含 B 链）。 */
/* @0x10ad88 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x10ad8c sub sp, sp, #52 */
/* @0x10ad90 mov r4, #0 */
/* @0x10ad94 mov r9, r1 */
/* @0x10ad98 str r4, [r0, #0xc] */
/* @0x10ad9c mov r1, r4 */
/* @0x10ada0 str r4, [r0] */
/* @0x10ada4 mov r8, r0 */
/* @0x10ada8 movw r3, #0x8480 */
/* @0x10adac movt r3, #0x412e */
/* @0x10adb0 str r3, [r0, #0x4] */
/* @0x10adb4 mov r5, r2 */
/* @0x10adb8 ldr r0, [sp, #0x50] */
/* @0x10adbc add r6, sp, #12 */
/* @0x10adc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10adc4 str r4, [sp] */
/* @0x10adc8 mov r3, r5 */
/* @0x10adcc mov r2, r9 */
/* @0x10add0 mov r1, r0 */
/* @0x10add4 mov r0, r6 */
/* @0x10add8 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* ── 6.2 枚举 + 双闸（0x10addc..0x10ae14）──────────────────────────────
 *   空表先判一次（0x10ade4）再进循环；每轮 de()、Next() 各一次 bl。
 *   闸：+0x68 != 0 → 跳（0x10ae00/0x10ae08）；+0x69 != 0 → 跳（0x10ae0c/0x10ae14）。 */
/* @0x10addc mov r0, r6 */
/* @0x10ade0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10ade4 cmp r0, #0 */
/* @0x10ade8 mov r0, r6 */
/* @0x10adec beq 0x10ae58 <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x10adf0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10adf4 mov r7, r0 */
/* @0x10adf8 mov r0, r6 */
/* @0x10adfc bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x10ae00 ldrb r3, [r7, #0x68] */
/* @0x10ae04 cmp r3, #0 */
/* @0x10ae08 bne 0x10addc <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x10ae0c ldrb r3, [r7, #0x69] */
/* @0x10ae10 cmp r3, #0 */
/* @0x10ae14 bne 0x10addc <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0x54> */
/* ── 6.3 比最小（0x10ae18..0x10ae44）──────────────────────────────────
 *   先把当前最优的 (低,高) 两字取进 r4/r5（0x10ae20/0x10ae24），再 bl FindDist(inst,self)、
 *   float→double（vcvt.f64.f32），`vcmpe.f64 d6,d7` + `bpl`：d6 >= d7（最优 >= 新值）→ 0x10ae60 换新值。
 *   ⇒ 替换条件是「当前最优 >= 新值」（相等也替换，值不变，只是白跑一次 FindDist）；只有最优 < 新值才走 6.4 的空回写。 */
/* @0x10ae18 mov r0, r7 */
/* @0x10ae1c mov r1, r9 */
/* @0x10ae20 ldr r4, [r8] */
/* @0x10ae24 ldr r5, [r8, #0x4] */
/* @0x10ae28 bl 0x10ac9c <_Z8FindDistP9CInstanceS0_> */
/* @0x10ae2c vmov s12, r0 */
/* @0x10ae30 vcvt.f64.f32 d7, s12 */
/* @0x10ae34 vmov d6, r4, r5 */
/* @0x10ae38 vcmpe.f64 d6, d7 */
/* @0x10ae3c vmrs APSR_nzcv, fpscr */
/* @0x10ae40 bpl 0x10ae60 <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x10ae44 ldm r8, {r0, r1} */
/* ── 6.4 不换值的那一支（0x10ae48..0x10ae5c）────────────────────────────
 *   ldm r8,{r0,r1} → mov → stm r8,{r2,r3}：把刚读出来的两字又写回去（**无变化的回写**，
 *   编译器为 `best = min(best, d)` 生成的多余存取），然后回循环。
 *   0x10ae58/0x10ae5c 是正常出口（add sp/pop）。 */
/* @0x10ae48 mov r2, r0 */
/* @0x10ae4c mov r3, r1 */
/* @0x10ae50 stm r8, {r2, r3} */
/* @0x10ae54 b 0x10addc <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x10ae58 add sp, sp, #52 */
/* @0x10ae5c pop {r4, r5, r6, r7, r8, r9, pc} */
/* ── 6.5 换值分支（0x10ae60..0x10ae78）────────────────────────────────
 *   再调一次 FindDist（同一个 inst！）→ vcvt → `vmov r0,r1,d6` 把 double 拆进两字，
 *   `b 0x10ae48` 复用回写与循环尾。
 *   FindDist（0x10ac9c，旁证）语义：a == NULL 或 a == b 或 a+0x68 或 a+0x69 → 1e6f；
 *   a+0x64 脏 → Compute_BoundingBox(a,1)，b+0x64 脏 → Compute_BoundingBox(b,1)；
 *   然后按 +0xe8/+0xf0（x 向）与 +0xec/+0xf4（y 向）算各自 max(0, 间隙)，sqrtf(dx²+dy²)，
 *   vsqrt 出 NaN 时回退 libm sqrtf。⇒ 距离是**盒到盒**（重叠 = 0），不是中心距；自己永远被 a == b 挡掉。 */
/* @0x10ae60 mov r1, r9 */
/* @0x10ae64 mov r0, r7 */
/* @0x10ae68 bl 0x10ac9c <_Z8FindDistP9CInstanceS0_> */
/* @0x10ae6c vmov s13, r0 */
/* @0x10ae70 vcvt.f64.f32 d6, s13 */
/* @0x10ae74 vmov r0, r1, d6 */
/* @0x10ae78 b 0x10ae48 <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0xc0> */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 7 · F_PlaceMeeting（place_meeting）
 * @func 0x107fb4 0x108070  size 192  48 条（48 条指令，无池）
 * 符号: _Z14F_PlaceMeetingR6RValueP9CInstanceS2_iPS_
 * 一句话: obj=args[2]；-1/-2 先翻译成 self/other 的实例 id（+0x78），-4 直接 false；
 *         否则 Command_IsMeeting(self,obj,x,y)→bool，结果写 double 0.0/1.0。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 7.1 入口：tag 先置 0（0x107fb4..0x107fd8）──────────────────────────
 *   result→r5、self→r7、other→r8、args→r6（[sp,#0x18]）；0x107fc4 无条件写 tag = 0。
 *   obj 取 args[**2**]（x、y 在 0、1）。 */
/* @0x107fb4 push {r4, r5, r6, r7, r8, lr} */
/* @0x107fb8 mov r3, #0 */
/* @0x107fbc ldr r6, [sp, #0x18] */
/* @0x107fc0 mov r7, r1 */
/* @0x107fc4 str r3, [r0, #0xc] */
/* @0x107fc8 mov r5, r0 */
/* @0x107fcc mov r1, #2 */
/* @0x107fd0 mov r8, r2 */
/* @0x107fd4 mov r0, r6 */
/* @0x107fd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* ── 7.2 -1/-2/-4 三个特例（0x107fdc..0x108014）────────────────────────
 *   0x107fdc..0x107ff4：`movne r3,#1` + `cmn r0,#1` + `movne r3,#0` 拼出
 *   (self != 0 && objint == -1) ⇒ objint = self->[0x78]。
 *   0x107ff8..0x10800c：同构，(other != 0 && objint == -2) ⇒ objint = other->[0x78]。
 *   ⇒ 这里代入的是 **id**（>0x1869F 区间），不是对象号；命令层随后走 ms_ID2Instance 查这一条。
 *   0x108010 `cmn r4,#4`：objint == -4（noone）→ 0x108064 直接 0.0，连命令层都不进。 */
/* @0x107fdc adds r3, r7, #0 */
/* @0x107fe0 movne r3, #1 */
/* @0x107fe4 cmn r0, #1 */
/* @0x107fe8 mov r4, r0 */
/* @0x107fec movne r3, #0 */
/* @0x107ff0 cmp r3, #0 */
/* @0x107ff4 ldrne r4, [r7, #0x78] */
/* @0x107ff8 adds r3, r8, #0 */
/* @0x107ffc movne r3, #1 */
/* @0x108000 cmn r4, #2 */
/* @0x108004 movne r3, #0 */
/* @0x108008 cmp r3, #0 */
/* @0x10800c ldrne r4, [r8, #0x78] */
/* @0x108010 cmn r4, #4 */
/* @0x108014 beq 0x108064 <_Z14F_PlaceMeetingR6RValueP9CInstanceS2_iPS_+0xb0> */
/* ── 7.3 取 x/y 并调命令层（0x108018..0x108044）──────────────────────────
 *   x = YYGetFloat(args,0)→r8、y = YYGetFloat(args,1)→r0；
 *   Command_IsMeeting(self, objint, x, y) 0x1ca9f8 —— 后者只是把 (inst,obj,x,y) 重排成
 *   Command_InstancePlace(inst,x,y,obj) 0x1ca6d8 并把返回值归一成 1/0。 */
/* @0x108018 mov r1, #0 */
/* @0x10801c mov r0, r6 */
/* @0x108020 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108024 mov r1, #1 */
/* @0x108028 mov r8, r0 */
/* @0x10802c mov r0, r6 */
/* @0x108030 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108034 mov r1, r4 */
/* @0x108038 mov r2, r8 */
/* @0x10803c mov r3, r0 */
/* @0x108040 mov r0, r7 */
/* @0x108044 bl 0x1ca9f8 <_Z17Command_IsMeetingP9CInstanceiff> */
/* ── 7.4 结果编码（0x108048..0x108060）───────────────────────────────
 *   真：r3 高字 0x3ff00000、低字 0 ⇒ **1.0**；假：两字 0 ⇒ 0.0。
 *   与碰撞函数不同：place_meeting 返回的是布尔，不是实例 id。 */
/* @0x108048 cmp r0, #0 */
/* @0x10804c movne r3, #0 */
/* @0x108050 moveq r3, r0 */
/* @0x108054 movne r0, r3 */
/* @0x108058 movtne r3, #0x3ff0 */
/* @0x10805c stm r5, {r0, r3} */
/* @0x108060 pop {r4, r5, r6, r7, r8, pc} */
/* ── 7.5 -4 出口（0x108064..0x108070）───────────────────────────────
 *   两字写 0（tag 已在 7.1 置 0）⇒ 0.0 = false；不碰命令层、不查表。 */
/* @0x108064 mov r3, #0 */
/* @0x108068 str r3, [r5] */
/* @0x10806c str r3, [r5, #0x4] */
/* @0x108070 pop {r4, r5, r6, r7, r8, pc} */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 8 · F_CollisionLine（collision_line）
 * @func 0x1092d0 0x1093ac  size 224  56 条（56 条指令，无池）
 * 符号: _Z15F_CollisionLineR6RValueP9CInstanceS2_iPS_
 * 一句话: 读 7 个参数（x1,y1,x2,y2,obj,precise,notme）调 Command_CollisionLine，
 *         命中返回 (double)inst->[0x78]，否则 -4.0（noone）。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 8.1 前四个参数（0x1092d0..0x10931c）──────────────────────────────
 *   帧 9×4+28 = 0x40 ⇒ args 在 [sp,#0x40]。
 *   x1→r9、y1→r8、x2→r7、y2→[sp,#0x14]（0x10932c 才落地）。 */
/* @0x1092d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1092d4 sub sp, sp, #28 */
/* @0x1092d8 mov r5, r0 */
/* @0x1092dc mov r6, r1 */
/* @0x1092e0 ldr r4, [sp, #0x40] */
/* @0x1092e4 mov r1, #0 */
/* @0x1092e8 mov r0, r4 */
/* @0x1092ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1092f0 mov r1, #1 */
/* @0x1092f4 mov r9, r0 */
/* @0x1092f8 mov r0, r4 */
/* @0x1092fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109300 mov r1, #2 */
/* @0x109304 mov r8, r0 */
/* @0x109308 mov r0, r4 */
/* @0x10930c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109310 mov r1, #3 */
/* @0x109314 mov r7, r0 */
/* @0x109318 mov r0, r4 */
/* @0x10931c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* ── 8.2 后三个参数 + 调用（0x109320..0x109378）──────────────────────────
 *   args[4] = obj（int）→ r11；args[5] = precise（bool）→ r10；args[6] = notme（bool）→ r0。
 *   实参排布：r1..r3 = x1,y1,x2；[sp] = y2；[sp+4] = obj；[sp+8] = precise；[sp+0xc] = notme
 *   —— 与 _Z21Command_CollisionLineP9CInstanceffffibb 的 (inst,ffff,i,b,b) 完全对齐。 */
/* @0x109320 mov r1, #4 */
/* @0x109324 mov r3, r0 */
/* @0x109328 mov r0, r4 */
/* @0x10932c str r3, [sp, #0x14] */
/* @0x109330 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109334 mov r1, #5 */
/* @0x109338 mov r11, r0 */
/* @0x10933c mov r0, r4 */
/* @0x109340 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109344 mov r1, #6 */
/* @0x109348 mov r10, r0 */
/* @0x10934c mov r0, r4 */
/* @0x109350 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109354 ldr r3, [sp, #0x14] */
/* @0x109358 mov r2, r8 */
/* @0x10935c str r11, [sp, #0x4] */
/* @0x109360 str r10, [sp, #0x8] */
/* @0x109364 mov r1, r9 */
/* @0x109368 str r3, [sp] */
/* @0x10936c mov r3, r7 */
/* @0x109370 str r0, [sp, #0xc] */
/* @0x109374 mov r0, r6 */
/* @0x109378 bl 0x1cb390 <_Z21Command_CollisionLineP9CInstanceffffibb> */
/* ── 8.3 结果编码（0x10937c..0x1093ac）────────────────────────────────
 *   tag 先置 0；命中 → ldr [r0+0x78] → vcvt.f64.s32 → 写两字；未命中 → 高字 0xc0100000 = **-4.0**。
 *   -4 是 GML 的 noone；与 instance_create 的失败值 -1.0 不同，别混。 */
/* @0x10937c mov r3, #0 */
/* @0x109380 str r3, [r5, #0xc] */
/* @0x109384 cmp r0, #0 */
/* @0x109388 ldrne r2, [r0, #0x78] */
/* @0x10938c moveq r3, #0 */
/* @0x109390 moveq r2, #0 */
/* @0x109394 movteq r3, #0xc010 */
/* @0x109398 vmovne s15, r2 */
/* @0x10939c vcvtne.f64.s32 d7, s15 */
/* @0x1093a0 vmovne r2, r3, d7 */
/* @0x1093a4 stm r5, {r2, r3} */
/* @0x1093a8 add sp, sp, #28 */
/* @0x1093ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 9 · F_CollisionPoint（collision_point）
 * @func 0x108f80 0x10902c  size 176  44 条（44 条指令，无池）
 * 符号: _Z16F_CollisionPointR6RValueP9CInstanceS2_iPS_
 * 一句话: 读 5 个参数（x,y,obj,precise,notme）调 Command_CollisionPoint，
 *         命中返回 (double)inst->[0x78]，否则 -4.0；**这条链不进 RTree**。
 * ═══════════════════════════════════════════════════════════════════════════ */
/* ── 9.1 五个参数（0x108f80..0x108fc4）────────────────────────────────
 *   帧 8×4+8 = 0x28 ⇒ args 在 [sp,#0x28]。
 *   x→r9、y→r7、obj→r8、precise→r10（0x108fd4）、notme→r0（0x108fd4 之后）。
 *   全部走 YYGetFloat/YYGetInt32/YYGetBool 三个取值器，没有内联类型判断。 */
/* @0x108f80 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x108f84 sub sp, sp, #8 */
/* @0x108f88 mov r5, r0 */
/* @0x108f8c mov r6, r1 */
/* @0x108f90 ldr r4, [sp, #0x28] */
/* @0x108f94 mov r1, #0 */
/* @0x108f98 mov r0, r4 */
/* @0x108f9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108fa0 mov r1, #1 */
/* @0x108fa4 mov r9, r0 */
/* @0x108fa8 mov r0, r4 */
/* @0x108fac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108fb0 mov r1, #2 */
/* @0x108fb4 mov r7, r0 */
/* @0x108fb8 mov r0, r4 */
/* @0x108fbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108fc0 mov r1, #3 */
/* @0x108fc4 mov r8, r0 */
/* ── 9.2 调用（0x108fc8..0x108ff8）────────────────────────────────────
 *   r0 = self、r1 = x、r2 = y、r3 = obj；[sp] = precise、[sp+4] = notme。
 *   Command_CollisionPoint 0x1c89a4 全程没有 UpdateTree / RTree::Search（对比节 8 的命令层），
 *   三条路都是逐实例：objint == -3 → Run_Room->[0x80] 链；> 0x1869F → ms_ID2Instance；
 *   否则 g_ObjectHash → obj->[0xd0] 节点链；每路自己筛 +0x68/+0x69 并在 notme 时排除 self。 */
/* @0x108fc8 mov r0, r4 */
/* @0x108fcc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108fd0 mov r1, #4 */
/* @0x108fd4 mov r10, r0 */
/* @0x108fd8 mov r0, r4 */
/* @0x108fdc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108fe0 mov r2, r7 */
/* @0x108fe4 mov r3, r8 */
/* @0x108fe8 str r10, [sp] */
/* @0x108fec mov r1, r9 */
/* @0x108ff0 str r0, [sp, #0x4] */
/* @0x108ff4 mov r0, r6 */
/* @0x108ff8 bl 0x1c89a4 <_Z22Command_CollisionPointP9CInstanceffibb> */
/* ── 9.3 结果编码（0x108ffc..0x10902c）────────────────────────────────
 *   与 collision_line 逐指令同构：tag 0 + (double)id，未命中 -4.0；最后 add sp/pop。 */
/* @0x108ffc mov r3, #0 */
/* @0x109000 str r3, [r5, #0xc] */
/* @0x109004 cmp r0, #0 */
/* @0x109008 ldrne r2, [r0, #0x78] */
/* @0x10900c moveq r3, #0 */
/* @0x109010 moveq r2, #0 */
/* @0x109014 movteq r3, #0xc010 */
/* @0x109018 vmovne s15, r2 */
/* @0x10901c vcvtne.f64.s32 d7, s15 */
/* @0x109020 vmovne r2, r3, d7 */
/* @0x109024 stm r5, {r2, r3} */
/* @0x109028 add sp, sp, #8 */
/* @0x10902c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 跨函数结论（每条都能在本卡内找到锚点或用例）
 * ═══════════════════════════════════════════════════════════════════════════
 *  1. +0x68 是硬闸、+0x69 是状态位：9 个函数里 +0x68 被读 **10** 次
 *     （ActAll 0x10be18｜ActObj 0x10bf74/0x10bff8/0x10c020/0x10c060/0x10c0d4｜
 *      DeactAll 0x10b4bc/0x10b530｜DeactObj 0x10a5f0｜DistToObj 0x10ae00），
 *     +0x69 被读 **7** 次（ActAll 0x10be24｜ActObj 0x10bf80/0x10c004/0x10c0e0｜
 *      DeactAll 0x10b4c8｜DeactObj 0x10a600｜DistToObj 0x10ae0c），而 9 个函数里
 *     **没有任何一条 strb/str 直接写 +0x69** —— 状态写一律经 bl CInstance::SetDeactivated。
 *  2. 开关函数完全不碰两条链：62 条 str 全部落在 List 头（[g]/[g+4]/[g+8]）、栈槽或 result 槽；
 *     room+0x80..0x94 与 inst+0x178/+0x17c 一个都没出现。搬链是延迟的（CRoom::UpdateActive）或
 *     由 SetDeactivated 在 g_isZeus != 0 时立刻转给 CLayerManager::UpdateInstanceActivation。
 *  3. 记账与改状态有两种序：ActAll（0x10be4c 记账 → 0x10be5c SetDeactivated）、
 *     ActObj（0x10bf44/0x10c048/0x10c088/0x10c104 → 同段尾调）、DeactAll（0x10b4f0 → 0x10b500）
 *     都是「先记账、后改状态」；只有 DeactObj 是「循环内就 SetDeactivated(0x10a624)、
 *     循环后 0x10a670 才记账」。
 *  4. 参数位置不统一（同一批函数四种排布）：obj 在 args[0] 的只有 distance_to_object（0x10adc0）；
 *     instance_create 与 place_meeting 在 args[2]（0x1095ac / 0x107fd8）；
 *     collision_point 在 args[2]（0x108fbc）后面跟 precise/notme；
 *     collision_line 在 args[4]（0x109330），前面是四个坐标。激活/失活的 objint 也都在 args[0]。
 *  5. 三个负数 + noone 的分工：-1 = self、-2 = other、-3 = 全体、-4 = noone。
 *     开关函数自己处理 -1/-2/-3（ActObj 0x10bedc/0x10bee4/0x10beec，DeactAll 的 notme 块 0x10b514）；
 *     DeactObj 把它们整体交给 WithObjIterator（0x10a5e4 只传 objint，不自己判）；
 *     place_meeting 把 -1/-2 翻译成 self/other 的 **id**（0x107ff4 / 0x10800c），-4 直接 false（0x108014）；
 *     碰撞两个函数原样把 -1/-2/-3 交给命令层（0x108fe4 / 0x109374）。
 *  6. 四套返回值编码：布尔 double（place_meeting 0x108058 的 0x3ff00000）｜id double 或 -4.0
 *     （CollPoint 0x109014 / CollLine 0x109394 的 0xc0100000）｜id double 或 -1.0（InstCreate 0x109608 的
 *     0xbff00000）｜开关函数不写 result（全节 0 条 str）。
 *  7. 待办表 g_InstanceActivateDeactive 的写入是「append + 翻倍」模板，本卡内联 **10** 处：
 *     0x10be78（ActAll）｜0x10b544 + 0x10b5b0（DeactAll 主表 + notme 块）｜
 *     0x10a6d4 + 0x10a694（DeactObj 临时表 + 主表）｜0x10c130/0x10c178/0x10c1ac/0x10c1dc/0x10c1f8（ActObj 五路）；
 *     翻倍规则一律 cap*2 + ReAlloc(...,"Platform/MemoryManager.h",74)。
 *  8. 本卡 9 个函数里只有两条会进树（place_meeting → Command_InstancePlace，collision_line → SearchLine），
 *     进入条件 = option_use_fast_collision != 0 且 obj->[0xd8] >= *(g_tree->[0x10]+4) 且 objint 不是 id 区；
 *     collision_point 全链无 UpdateTree/Search，恒走逐实例碰撞。
 *     ⚠ 别把这条读成「全图只有两条」：UpdateTree 0x1cc24c 全图有 **8** 个调用点
 *     （0x10d864 / 0x10d984 / 0x1ca578 / 0x1ca820 / 0x1caa44 / 0x1cabbc / 0x1cb5bc / 0x1cc820），
 *     本卡外还有 Command_CollisionRectangle 0x1ca578 等 —— 树是 collision_* 家族共用的。
 *  9. 调用点普查（BL 目标扫描，全 .text）：GetDeactiveList 全图只有 3 个调用点
 *     （0x10bdf0 / 0x10bf04 / 0x10c0ac）**全部在本卡**；FindDist 只有 2 个（0x10ae28 / 0x10ae68，
 *     都在 distance_to_object 里）；CollisionUpdate 只有 1 个（0x19265c，Compute_BoundingBox）；
 *     SetDeactivated 有 7 个（本卡的 0x10a624/0x10b500/0x10be5c/0x10bf58/0x10c118 +
 *     卡外 0x1bba68/0x1bbbbc）；Command_Create 2 个（0x1095dc 本卡 + 0x10b0b0 instance_create_depth 族）。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. option_use_fast_collision(0x542379) / option_fast_collision_compatibility(0x54237a) 的**写点**不在本卡
 *     （跨卡：CInstance_Compute_BoundingBox 也只找到读点）；谁在启动时置位未证，本作真值未实测。
 *  2. g_tree(0x5429a8) 是懒建的（CollisionUpdate 0x1cdd48），但 ShouldUseFastCollision 0x1c8e84 直接
 *     `ldr r3,[g_tree]; ldr r3,[r3,#0x10]`，没有空指针保护 ⇒ 若 option 开着而树还没建会崩。
 *     二者是否永不同时发生（option 只在树建好后置位）未证。
 *  3. obj->[0xd8] 与 *(g_tree+0x10)+4 的物理含义未定：前者像「该对象的实例数」，后者像树容量/阈值，
 *     只证了「>= 就走树」这一条比较。
 *  4. WithObjIterator 的模式机未逐档解开：ctor 0x19d060 里 objint ∈ {-1,-2,-3,≤0x1869F,>0x1869F} 分派、
 *     [it+0x18] 是模式、[it+0x20] 是第 4 参；de()/Next() 是 6 档跳表（0x19de64 / 0x19d1d4）。
 *     本卡只用到入口分派与「第 4 参 0 = 不含 B 链」，每档的链表来源（room+0x80 / room+0x8c /
 *     obj+0xd0 / 两个 List 全局）没有逐条核。
 *  5. activate_object(-1/-2) 不看 +0x69 ⇒ 对已活动实例会重复记账（表里可能出现同一指针多次）；
 *     deactivate_all 的 notme 块同样不看 +0x69 ⇒ 调用前已失活的 self 会被静默激活。
 *     两处都是代码事实，但是否为设计意图（还是 1.4 runner 的旧行为）未定 —— 没有运行期对照。
 *  6. instance_create 的 tag 6 分支只在 g_fJSGarbageCollection != 0 时出现，而 DoConv 卡把运行期 tag 6
 *     归进「Malformed variable」组；tag 6 的正式名字与消费者未定（本卡只记 [result] = 裸指针）。
 *  7. 两链的 depth 排序键（inst+0x180/+0x184）与本卡无关，未复核；CRoom::UpdateActive 卡已证 +0x184 是快照。
 *  8. s_instancePtr(0x5428b8) 与目标槽(0x3f50e8) 是 collision 快路共用的两个全局，非重入安全；
 *     是否会在同一帧被嵌套调用（例如回调里再触发碰撞）未证。
 */
