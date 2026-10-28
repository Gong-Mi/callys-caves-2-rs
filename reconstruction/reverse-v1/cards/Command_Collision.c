/* cally 逆向卡：碰撞/放置三命令（原版 libyoyo.so，armv7）—— 一卡三节
 * @func 三节 = index 的三个分组，逐节自带 @func 头与逐条锚点：
 *   §1 0x1cb390 Command_CollisionLine       size 996  249 锚点（241 条指令 + 8 个池字）
 *   §2 0x1ca350 Command_CollisionRectangle  size 904  226 锚点（218 条指令 + 8 个池字）
 *   §3 0x1ca6d8 Command_InstancePlace       size 800  200 锚点（192 条指令 + 8 个池字）
 * 总账: 675 锚点 = 651 条指令 + 24 个池字，与 asm/index-Command_Collision_all.tsv 逐字一致
 *       （自校验：index=675 card=675 missing=0 extra=0 mismatch=0 duplicates=0 RESULT EXACT；
 *        卡内锚点顺序 = index 文件行序 Line→Rect→Place，**不是**地址升序 —— 三节地址互不重叠，
 *        这样任意一行 index 都能与卡内同序号锚点直接对拍）
 * 级别: 正文（三节都逐条解到控制流/实参/全局槽；三条慢路的链遍历、快路的 RTree 调用边界、
 *       precise/notme 的完整流向、结果回传槽全部逐条定位。RTree 内部（Search/SearchLine/盒测试）
 *       与三个回调函数不属本索引，只给地址与调用边界，见各节 open）
 * 锚点来源: asm_index.py 从二进制直出，本卡未手写转录；池字保留 objdump 的「像指令」写法
 *       （1cb754/1cb764/1ca6c8/1ca9d8/1ca9e4 五处 objdump 印成 eoreq 之类），逐处标「非指令」。
 *
 * ── 三个命令 ↔ 三个 GML 内建的参数对应（本卡正面回答）──────────────────────────────
 *   三节的签名（软浮点 ABI：float 占核心寄存器/栈，不进 s0..s3）：
 *     Command_CollisionLine     (inst, f x1, f y1, f x2, f y2, i obj, b precise, b notme)
 *     Command_CollisionRectangle(inst, f x1, f y1, f x2, f y2, i obj, b precise, b notme)
 *     Command_InstancePlace     (inst, f x,  f y,  i obj)                    ← 只有 4 个参数
 *
 *   collision_line(x1,y1,x2,y2,obj,prec,notme)   F_CollisionLine 0x1092d0，bl 在 0x109378（全 .text 唯一）
 *       传入：r0=inst r1=x1 r2=y1 r3=x2 [sp]=y2 [sp+4]=obj [sp+8]=prec [sp+0xc]=notme
 *       节 1 收到：r11=inst r9=x1 r8=y1 r7=x2 s16=y2(栈) r5=obj r10=precise r6=notme
 *       （1cb39c vldr s16,[sp,#128] / 1cb3a8 ldr r5,[sp,#0x84] / 1cb3c8 ldrb r10,[sp,#0x88] /
 *         1cb3cc ldrb r6,[sp,#0x8c]；帧 9×4+8+84=128）
 *
 *   collision_rectangle(x1,y1,x2,y2,obj,prec,notme)  F_CollisionRectangle 0x109030，bl 在 0x1090d8（唯一）
 *       传入排布与 collision_line 逐字相同（0x109038..0x1090d4：args[0..3]=YYGetFloat、
 *       args[4]=YYGetInt32、args[5..6]=YYGetBool，r1..r3=x1,y1,x2、[sp]=y2、[sp+4]=obj、
 *       [sp+8]=prec、[sp+0xc]=notme）
 *       节 2 收到：r7=inst s17=x1 s18=y1 s16=x2 s19=y2(栈) r4=obj r8=precise r6=notme
 *       （1ca35c vldr s19,[sp,#120] / 1ca368 ldr r4,[sp,#0x7c] / 1ca388 ldrb r8,[sp,#0x80] /
 *         1ca38c ldrb r6,[sp,#0x84]；帧 8×4+16+72=120）
 *
 *   place_meeting(x,y,obj)                        F_PlaceMeeting 0x107fb4
 *       → Command_IsMeeting(inst,obj,x,y) 0x1ca9f8（bl 在 0x108044）
 *       → 重排成 Command_InstancePlace(inst,x,y,obj) 0x1ca6d8（bl 在 0x1caa0c）
 *       节 3 收到：r6=inst r7=x r8=y r5=obj（帧 8×4+32=64，**无栈实参**）
 *       ⇒ 这一层没有 precise/notme：place_meeting 只有 3 个参数。
 *
 *   obj 的三个特殊值在**内建层**就被消耗掉一部分（Builtins_Instance 卡 §7）：
 *       place_meeting 把 -1/-2 换成 self/other 的 +0x78（实例 id）、-4 直接返回 0.0（连命令层都不进）；
 *       命令层只剩三种情况要判：-3(all) / >0x1869F(实例 id) / 其它(对象号)。
 *   ⇒ 三个命令的返回值都是 **CInstance***（0 = 没命中），不是 id：
 *       collision_* 内建再取命中实例的 +0x78 当 double 返回，没命中返回 -4.0(noone)；
 *       Command_IsMeeting 把指针归一成 1/0（0x1caa10 adds / 0x1caa14 movne #1）。
 *
 * ── 三节共用骨架（逐条同构，只有窄相函数与快路查询形态不同）──────────────────────
 *   g = ShouldUseFastCollision(obj, &objptr) 0x1c8df8（跨卡旁证，无锚点）：
 *       -1 → 立刻返回 0（目标对象不存在：实例不动、链不遍历、树不查）
 *        1 → 走树（UpdateTree → RTree 查询 → 回调窄相）
 *        2 → 不走树（沿链逐个调窄相）
 *   判决顺序（0x1c8df8 实测）：obj > 0x1869F → 2；option_use_fast_collision(0x542379)==0 → 2；
 *       obj == -3 → 1；否则查对象表：查不到 → -1；查到 → obj->[0xd8] >= *(*(*g_tree)->[0x10]+0x4)
 *       ? 1 : 2（阈值比较，字段名未证）。
 *   ⇒ 于是三条慢路的可达条件互不相同（本卡逐条可验）：
 *       -3(all) 的 room 链：**只在 option 关掉时**（option 开时 -3 被判 1，走树）
 *       >0x1869F 的 id 表：恒走慢路（ShouldUseFastCollision 对它恒返 2）
 *       对象号的 obj 链：option 关，或 obj->[0xd8] 没到树阈值
 *   ⇒ 也解释了慢路里那段「自己再查一遍对象表」的代码（Line 1cb6c0 / Rect 1ca658 / Place 1ca7c8）：
 *       ShouldUseFastCollision 在 option==0 那一档 **直接 return 2 且不写 *out**，命令层看到 objptr==0，
 *       只好自己查一次 → 而那一次查到的对象链就在 objptr->[0xd0]。
 *
 * ── precise / notme 的完整流向（本卡重点）──────────────────────────────────────
 *   precise：命令层**只往下传，从不据此判分支**。
 *       慢路 → 窄相第 5 实参：CInstance::Collision_Line 0x194f28 / Collision_Rectangle 0x1946f4
 *              （Line 1cb460 str r10,[sp,#4]；Rect 1ca420 str r8,[sp,#4]）
 *       快路 → 存上下文 +0x20，回调整字节取出再当第 5 实参（0x1c8504/0x1c83c0 的
 *              ldrb r3,[ctx,#0x20] + str r3,[sp,#4]）
 *       ⇒ 它只影响窄相判定的精度，不影响遍历范围。
 *   notme：两种用法，语义都是「跳过调用者自己」。
 *       慢路（obj 链 / room 链）：每个候选判 (inst == cand) && (notme & 1) → 跳过
 *              （Line 1cb430..1cb440、Rect 1ca3f0..1ca400；`andeq r3, r6, #1` 只取最低位）
 *       id 表路：候选只有一个，改在入口先判 obj == inst->[0x78] → 直接返回 0
 *              （Line 1cb5a8、Rect 1ca568；Place 无此参数故没有这段）
 *       快路：存上下文 +0x21、self 指针 +0x24，回调判 (ctx[+0x21]) && (ctx[+0x24] == cand) → 跳过
 *       Line/Rect 的快路在查树**之前**还有一条短路：notme && obj == inst->[0x78] → 返回 0
 *              （Line 1cb590..1cb598、Rect 1ca590..1ca598，注意它们**先**清了 s_instancePtr）
 *       InstancePlace 没有 notme：它的回调 0x1c8648 **无条件**跳过 ctx（=正在搬动的那个实例），
 *              因为 place_meeting 是「先搬再测」，不排除自己就必然命中。
 *
 * ── 全局坐标（本轮直接读 libyoyo.so 的重定位与数据段实测，不是从字符串猜的）────────────
 *   PIC 锚   0x3f1c58（三节都用 add rX,pc,rX 算出同一个基址；Compute_BoundingBox 卡同值）
 *   GOT 槽      目标        说明
 *   0x3ed930 → 0x54298c   Run_Room（CRoom*，4 B）
 *   0x3edc44 → 0x542374   g_ObjectHash（4 B **指针**，再解引用一次才得哈希对象本体）
 *   0x3edc4c → 0x536f28   实例 id→CInstance* 哈希**对象本体**（.bss 静态，不再解引用）
 *   0x3ee24c → 0x5429a8   g_tree（RTree<CInstance*,int,float,6,2>*，4 B）
 *   0x3f0b10 → 0x5428b8   s_instancePtr（命中实例槽，4 B 全局；快路靠它回传结果）
 *   0x3f50e4 / 0x3f50e8   .data 里相邻的两个 int（初值都是 -1）：快路回调的「目标 obj」槽 ——
 *                         Line/Rect 写 0x3f50e4，InstancePlace 写 0x3f50e8（**不是同一个槽**）
 *   ⚠ 两种哈希共用一套布局：{+0x00 桶表、+0x04 掩码、桶步长 8、节点 {+0x04 next, +0x08 key,
 *     +0x0c value}}；对象表 key=对象号、value=CObjectGM*；id 表 key=实例 id、value=CInstance*。
 *     两处都**没有空指针闸**（map 本体为空就直接解引用）。
 *
 * ── CInstance / CObjectGM 侧本卡读到的字段 ──────────────────────────────────────
 *   CInstance：+0x48(int，回调要求 ==1)  +0x64 bbox 脏位  +0x68 skip/已销毁  +0x69 deactivated
 *              +0x78 id  +0x80 CObjectGM*  +0xb4 x(float)  +0xb8 y(float)  +0xd8 ?（树阈值比较用）
 *              +0xe8/+0xec/+0xf0/+0xf4 bbox(left/top/right/bottom, int)  +0x178 prev
 *   CObjectGM：+0xd0 实例节点链头 {next@+0x0, inst@+0x8}
 *   ⇒ +0x178 是 prev（Builtins_Instance 卡：+0x178 prev / +0x17c next）。本卡从 room->[0x80]
 *      （A 链**尾**）出发沿 +0x178 走 ⇒ -3 的扫描顺序是「尾→头」，与绘制顺序（+0x17c 正走）相反。
 *
 * ── 三处最容易读错的地方（自查记录，留给后来者）──────────────────────────────────
 *  1) 软浮点：float 走 r1..r3 与栈，不进 s0..s3。三节入参索引只能由「vldr sN,[sp,#帧量]」+
 *     「ldrb 两个 bool」反推；结论与 Builtins_Instance §8 的实参排布逐字吻合（见上表）。
 *  2) 快路的 Line 是**量化**的（节 1）：4 个字 = {(float)(int)x起点, (float)(int)y起点,
 *     (float)dx, (float)dy}，起点取 (int)x 较小的一端（1cb644 的 cmp r9,r7 比的是**转换后的整数**）。
 *     不是原始 float —— 一版把 r9/r7 当 float 看，会得出「位模式相减」的错误结论。
 *  3) 快路的结果不经过 r0：命中实例写进全局 s_instancePtr（先清 0 → 查 → 回读）；
 *     慢路才用 r5/r4 直接带回来。两条路最终返回的都是同一个 CInstance*。
 *
 * ── 逐条锚点（3 节，675 条）────────────────────────────────────────────────────
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 1 · Command_CollisionLine（collision_line 的命令层）
 * @func 0x1cb390 0x1cb774  size 996  249 锚点（241 条指令 + 8 个池字 0x1cb754..0x1cb770）
 * 符号: _Z21Command_CollisionLineP9CInstanceffffibb
 *       → CInstance* Command_CollisionLine(CInstance* inst, float x1, float y1, float x2, float y2,
 *                                          int obj, bool precise, bool notme)
 * 位置: index 第 1 组（地址上排在另两节之后）。函数体 0x1cb390..0x1cb750 + 池字 8 个
 * 调用者: 全 .text 精确 1 处 bl、无 b 尾跳 —— F_CollisionLine 0x1092d0 的 0x109378
 * 同层: RTree::SearchLine 0x1cb234（唯一快路查询）、UpdateTree 0x1cc24c、
 *       ShouldUseFastCollision 0x1c8df8、CInstance::Collision_Line 0x194f28、回调 0x1c8504
 * 一句话: 线段 (x1,y1)-(x2,y2) 撞 obj 指定的实例集合，命中返回该实例指针、否则 0。
 *         三条慢路（-3 扫房间链 / >99999 查 id 表 / 对象号走 obj->[0xd0] 链）以外，走
 *         UpdateTree → 把线段量化成 4 个 float → RTree::SearchLine，命中实例由全局 s_instancePtr 带回。
 * ═══════════════════════════════════════════════════════════════════════════
 */

/* ── 语义草案 ─────────────────────────────────────────────────────────────
 *   CInstance* Command_CollisionLine(CInstance* inst, float x1,float y1,float x2,float y2,
 *                                    int obj, bool precise, bool notme) {
 *     CObjectGM* o = NULL;                              // 1cb3b4 清
 *     int g = ShouldUseFastCollision(obj, &o);          // 1cb3d0
 *     if (g == -1) return NULL;                         // 1cb3dc..1cb3e0
 *     if (g == 1) {                                     // 1cb3e4..1cb3e8
 *        UpdateTree();                                   // 1cb5bc
 *        s_instancePtr = NULL;                           // 1cb5f0
 *        if (notme && obj == inst->[0x78]) return NULL;  // 1cb58c..1cb598
 *        LineF l = { xa_i, ya_i, dx_i, dy_i };           // 1cb614..1cb684（a = (int)x 较小端）
 *        g_objLine = obj;                                // 1cb604 → 0x3f50e4
 *        Ctx c = { (double)x1,(double)y1,(double)x2,(double)y2, precise,notme,inst };  // 1cb5c0..1cb600
 *        int count = 0;                                  // 1cb6ac
 *        RTree::SearchLine(*g_tree, (*g_tree)->[0x10], &l, &count, 0x1c8504, &c);      // 1cb6b0
 *        return s_instancePtr;                           // 1cb6b4..1cb6b8
 *     }
 *     if (obj == -3) {                                  // 1cb3ec..1cb3f0 → 1cb52c
 *        for (p = Run_Room->[0x80]; p; p = p->[0x178])   // 尾→头（+0x178 = prev）
 *           if (!(p == inst && (notme & 1)) && !p->[0x68] && !p->[0x69]
 *               && p->Collision_Line(x1,y1,x2,y2,precise)) return p;
 *        return NULL;                                    // 1cb5a4
 *     }
 *     if (obj > 99999) {                                // 1cb3f4..1cb400 → 1cb49c
 *        if (notme && obj == inst->[0x78]) return NULL;  // 1cb4a0 → 1cb5a8
 *        CInstance* p = IdMap.find(obj);                 // 1cb4a4..1cb4e0
 *        if (!p || p->[0x68] || p->[0x69]) return NULL;
 *        return p->Collision_Line(x1,y1,x2,y2,precise) ? p : NULL;
 *     }
 *     if (!o) o = ObjMap.find(obj);                      // 1cb404 / 1cb6c0（option 关时）
 *     for (n = o->[0xd0]; n; n = n->[0x0]) {              // 1cb410..1cb484
 *        CInstance* p = n->[0x8];
 *        if (p == inst && (notme & 1)) continue;
 *        if (p->[0x68] || p->[0x69]) continue;
 *        if (p->Collision_Line(x1,y1,x2,y2,precise)) return p;
 *     }
 *     return NULL;                                       // 1cb488
 *   }
 *
 * ── 门表（按执行顺序；本卡全部实测）──────────────────────────────────────
 *   ① g = ShouldUseFastCollision(obj,&o)：-1/1/2                 1cb3d0..1cb3e8
 *   ② obj == -3（cmn r5,#3）                                     1cb3ec..1cb3f0
 *   ③ obj > 0x1869F（movw/movt + bgt）                           1cb3f4..1cb400
 *   ④ 慢路：o == 0 → 自己查对象表                                 1cb404..1cb40c / 1cb6c0
 *   ⑤ 链节点非空 → node->[0x8] 非空                               1cb410..1cb424
 *   ⑥ notme 短路：(inst == cand) && (notme & 1)                   1cb430..1cb440
 *   ⑦ +0x68 != 0 → 跳过                                          1cb444..1cb44c
 *   ⑧ +0x69 != 0 → 跳过                                          1cb450..1cb458
 *   ⑨ 窄相返回 0 → 下一个；非 0 → 返回该 cand                      1cb478..1cb484
 *   快路侧：ⓐ notme && obj == inst->[0x78] → 返回 0               1cb58c..1cb598
 *          ⓑ 回调 0x1c8504 内部另有 +0x68 / +0x69 / +0x48!=1 三道闸 + 对象匹配（跨卡）
 *   ⇒ ⑤..⑨ 任何一闸只决定「换下一个候选」，不会提前返回 1；唯一的提前返回是 ①(-1) 与 ⓐ。
 *
 * ── 字段表（本函数真正读写的）─────────────────────────────────────────────
 *   CInstance：+0x68(byte) +0x69(byte) 闸  +0x78(int) 自己的 id（1cb5b0 比）
 *              +0xd0 经 CObjectGM（见下）  +0x178 房间活动链的 prev（1cb550 取、1cb5a0 前移）
 *   CObjectGM：+0xd0 实例节点链头 {next@+0x0, inst@+0x8}（1cb410/1cb41c/1cb42c）
 *   全局：s_instancePtr 0x5428b8（清 1cb5f0 / 读 1cb6b8）、0x3f50e4（写 1cb604）、
 *         g_tree 0x5429a8、g_ObjectHash 0x542374、Run_Room 0x54298c、id 表 0x536f28
 *   写集：只写 3 个全局（0x5428b8、0x3f50e4、栈上局部）+ 无实例字段写 ⇒ 本命令不改任何实例状态。
 *
 * ── 已证（指令级）───────────────────────────────────────────────────────
 *  1. 帧 128 B 与实参索引（1cb390..1cb3cc）：9 push + vpush {d8} + 84 = 128；vldr s16,[sp,#128] 取 y2、
 *     ldr r5,[sp,#0x84] 取 obj、ldrb r10,[sp,#0x88]/ldrb r6,[sp,#0x8c] 取两个 bool ⇒ 与
 *     Builtins_Instance §8 的排布（r1..r3=x1,y1,x2；[sp]=y2；[sp+4]=obj；[sp+8]=prec；[sp+0xc]=notme）
 *     逐字吻合，软浮点（float 不进 s0..s3）由此确认。
 *  2. 三值分流（1cb3dc..1cb3e8）：-1 → 1cb488(返回 0)、1 → 1cb5b8(树)、其它 → 1cb3ec(慢路)。
 *  3. 两个特殊值用两种比较判：cmn r5,#3（== -3，1cb3ec）、movw/movt 0x1869f + bgt（>99999，1cb3f4..1cb400）。
 *  4. 对象链遍历（1cb410..1cb484）：CObjectGM+0xd0 → 节点 {next@0x0, inst@0x8}；1cb42c 先取 next 再判候选，
 *     候选指针不会被链指针覆盖；notme 只取最低位（1cb438 andeq r3,r6,#1）。
 *  5. 快路的线段是**量化**的（1cb614..1cb684）：w0/w1 = (float)(int) 起点坐标、w2/w3 = (float) 整数差；
 *     起点按 (int)x 较小的一端选（1cb644 cmp r9,r7 比的是已转换的整数），dx 恒 ≥ 0。
 *  6. 快路实参（1cb688..1cb6b0）：r0=*g_tree、r1=[*g_tree+0x10]、r2=&Line(sp+24)、r3=&count(sp+20，先清 0)、
 *     [sp]=0x1c8504、[sp+4]=&ctx(sp+40)；ctx = {double x1,y1,x2,y2 @+0..0x1f, precise@0x20, notme@0x21,
 *     self@0x24}，与回调 0x1c8504 的 ldrb [r6,#0x20]/[r6,#0x21]、ldr r3,[r6,#0x24] 三处吻合。
 *  7. 目标 obj 不进参数：写全局 0x3f50e4（1cb604），回调 0x1c8548..0x1c8550 从该槽回读 ⇒ 树查询本身
 *     不带对象过滤，obj 由回调在命中候选上再判一次。
 *  8. 结果不走 r0：清 0（1cb5f0）→ 查（1cb6b0）→ 回读全局（1cb6b4/1cb6b8）⇒ 快路与慢路返回同一个
 *     CInstance*，但快路是「全局槽里最后被写入的那个」。
 *  9. 控制转移：bl 共 6 处（ShouldUseFastCollision 1cb3d0、UpdateTree 1cb5bc、Collision_Line 三处
 *     1cb474/1cb51c/1cb58c、SearchLine 1cb6b0），其余全是 b/b<cond>；两个出口（1cb488 / 1cb48c 同一收尾）
 *     都先弹干净再走。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *  · RTree::SearchLine 0x1cb234 内部只证到「回调返回 0 才停、每个被访问的 payload 让 count+1」
 *    （1cb314..1cb330），剪枝与盒测试 0x1c8870 未逐条解。
 *  · 回调 0x1c8504 不属本索引：目标 obj 的读法、对象号/父子匹配（CObjectGM+0x18 + IsDecendentOf）、
 *    +0x48==1 那道闸，本卡只给地址与三处与 ctx 的对接，不落锚点。
 *  · 回调**所有**出口都返回 1（跳过分支 1c852c 也返回 1）⇒ 按 SearchLine「返回 0 才停」的语义，
 *    遍历不会提前结束，s_instancePtr 会被后一次命中覆盖 = **最后命中者胜**。这是否等于 GML 官方
 *    语义（通常期望「任一命中」）未证；对「返回哪个实例」的影响是实的。
 *  · 量化线段的 dx=0（x1、x2 落进同一整数格）时，0x1c8870 的板测试行为未解；可能整条竖线的候选
 *    被提前拒绝 —— 属**可能漏判**的方向，未证，列为 open 而不是结论。
 *  · g_tree 为空时 ShouldUseFastCollision 会直接解引用（0x1c8e84..0x1c8e90 无闸）；g_tree 何时必建
 *    （CollisionUpdate 懒建）不在本卡。
 *  · obj->[0xd8] 与 *(*(*g_tree)->[0x10]+0x4) 的字段名与含义未证（只证比较方向：>= → 用树）。
 */
/* ── 1.1 入口：帧 128 B、软浮点实参落位、objptr 局部清 0（0x1cb390..0x1cb3d0） ──────────────────────────────────────
 * push 9 寄存器(36) + vpush {d8}(8) + sub 84 = 128 ⇒ 栈实参从 [sp+128] 起（1cb39c 的 vldr 就是 y2）。
 * r11=inst、r9=x1、r8=y1、r7=x2、s16=y2、r5=obj([sp+0x84])、r10=precise([sp+0x88] byte)、
 * r6=notme([sp+0x8c] byte) —— 与 Builtins_Instance §8 记录的实参排布逐字吻合。
 * 1cb3a0 add lr,sp,#80；1cb3b4 str r4,[lr,#-0x40]! ⇒ 落址 sp+16（=sp+0x10），这就是
 * ShouldUseFastCollision 的 CObjectGM** 出参槽，**先清 0**：obj==-3 或 option 关时它保持 0，
 * 后面 1cb404 的「objptr==0」分支完全靠这个 0 才成立。
 * 1cb3b0 mov r4,#0 的这个 0 后面只用两处：清出参槽（1cb3b4）与清结果槽（1cb5f0）。
 */
/* @0x1cb390 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cb394 vpush {d8} */
/* @0x1cb398 sub sp, sp, #84 */
/* @0x1cb39c vldr s16, [sp, #128] */
/* @0x1cb3a0 add lr, sp, #80 */
/* @0x1cb3a4 mov r11, r0 */
/* @0x1cb3a8 ldr r5, [sp, #0x84] */
/* @0x1cb3ac mov r9, r1 */
/* @0x1cb3b0 mov r4, #0 */
/* @0x1cb3b4 str r4, [lr, #-0x40]! */
/* @0x1cb3b8 mov r1, lr */
/* @0x1cb3bc mov r7, r3 */
/* @0x1cb3c0 mov r0, r5 */
/* @0x1cb3c4 mov r8, r2 */
/* @0x1cb3c8 ldrb r10, [sp, #0x88] */
/* @0x1cb3cc ldrb r6, [sp, #0x8c] */
/* ── 1.2 判决：ShouldUseFastCollision 的三值分流 + PIC 锚（0x1cb3d0..0x1cb3ec） ──────────────────────────────
 * 1cb3d4/1cb3d8：ldr r3,[pc,#0x378]（池字 1cb754=0x00226878）+ add r3,pc,r3（PC=1cb3e0）
 * ⇒ r3 = 0x3f1c58，本函数后续所有全局槽都用这个基址 + 负偏移（池字区那 8 个字全是它）。
 * cmn r0,#1 → r0 == -1（对象不存在）→ 1cb488 返回 0；cmp r0,#1 → 1 → 1cb5b8 快路；
 * 其余（正常只有 2）落到 1cb3ec 慢路。⇒ 慢路不是「树没建好」的兜底，而是 ShouldUseFastCollision
 * 明确判定的「不值得用树」/「option 关掉」两档（见头部骨架表）。
 */
/* @0x1cb3d0 bl 0x1c8df8 <_Z22ShouldUseFastCollisioniPP9CObjectGM> */
/* @0x1cb3d4 ldr r3, [pc, #0x378] */
/* @0x1cb3d8 add r3, pc, r3 */
/* @0x1cb3dc cmn r0, #1 */
/* @0x1cb3e0 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb3e4 cmp r0, #1 */
/* @0x1cb3e8 beq 0x1cb5b8 <_Z21Command_CollisionLineP9CInstanceffffibb+0x228> */
/* ── 1.3 慢路分流：-3(all) / >0x1869F(id) / 对象号（0x1cb3ec..0x1cb40c） ────────────────────────────────────
 * cmn r5,#3 → obj == -3 → 1cb52c（房间活动链）。注意 option 开时 -3 在 1.2 就被判 1 走树了，
 * 所以这块只在 option_use_fast_collision == 0 时可达。
 * movw/movt 拼 0x1869f（99999）+ bgt → 1cb49c（实例 id 表）；这是 GM 的 id 下界。
 * 剩下的才是对象号：1cb404 看 objptr 是否为空——为空说明 ShouldUseFastCollision 走了 option==0
 * 那一档（它不写 *out），于是自己再查一次对象表（1cb6c0）。
 */
/* @0x1cb3ec cmn r5, #3 */
/* @0x1cb3f0 beq 0x1cb52c <_Z21Command_CollisionLineP9CInstanceffffibb+0x19c> */
/* @0x1cb3f4 movw r2, #0x869f */
/* @0x1cb3f8 movt r2, #0x1 */
/* @0x1cb3fc cmp r5, r2 */
/* @0x1cb400 bgt 0x1cb49c <_Z21Command_CollisionLineP9CInstanceffffibb+0x10c> */
/* ── 1.4 对象号慢路：obj->[0xd0] 的实例节点链（0x1cb404..1cb488） ───────────────────────────────────────────────
 * 链结构（与 Builtins_Instance 卡 §9 一致）：CObjectGM+0xd0 = 节点头，节点 {next@+0x0, inst@+0x8}。
 * 每轮：1cb41c 取 node->[0x8] 当候选、1cb42c 先把 node->[0x0] 存进 r4 当 next（所以候选指针不会被覆盖）。
 * 1cb430..1cb440 notme 短路：r3 = (inst==cand) ? (notme & 1) : 0，非 0 就跳下一个（1cb414）。
 * 1cb444/1cb450 两道字节闸：cand->[0x68] 或 cand->[0x69] 非 0 就跳。
 * 1cb45c..1cb474 组窄相实参：vstr s16,[sp]（y2，Line 的 y2 在 s16）、str r10,[sp,#4]（precise）、
 *   r0=cand、r1..r3=x1,y1,x2（1cb464..1cb470 四条 mov）。
 * 1cb478 命中（非 0）就 1cb48c 返回 r5；1cb480 用 r4(=next) 继续，为 0 则 1cb488 返回 0。
 */
/* @0x1cb404 ldr r2, [sp, #0x10] */
/* @0x1cb408 cmp r2, #0 */
/* @0x1cb40c beq 0x1cb6c0 <_Z21Command_CollisionLineP9CInstanceffffibb+0x330> */
/* @0x1cb410 ldr r4, [r2, #0xd0] */
/* @0x1cb414 cmp r4, #0 */
/* @0x1cb418 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb41c ldr r3, [r4, #0x8] */
/* @0x1cb420 cmp r3, #0 */
/* @0x1cb424 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb428 ldr r5, [r4, #0x8] */
/* @0x1cb42c ldr r4, [r4] */
/* @0x1cb430 cmp r11, r5 */
/* @0x1cb434 movne r3, #0 */
/* @0x1cb438 andeq r3, r6, #1 */
/* @0x1cb43c cmp r3, #0 */
/* @0x1cb440 bne 0x1cb414 <_Z21Command_CollisionLineP9CInstanceffffibb+0x84> */
/* @0x1cb444 ldrb r3, [r5, #0x68] */
/* @0x1cb448 cmp r3, #0 */
/* @0x1cb44c bne 0x1cb414 <_Z21Command_CollisionLineP9CInstanceffffibb+0x84> */
/* @0x1cb450 ldrb r3, [r5, #0x69] */
/* @0x1cb454 cmp r3, #0 */
/* @0x1cb458 bne 0x1cb414 <_Z21Command_CollisionLineP9CInstanceffffibb+0x84> */
/* @0x1cb45c vstr s16, [sp] */
/* @0x1cb460 str r10, [sp, #0x4] */
/* @0x1cb464 mov r0, r5 */
/* @0x1cb468 mov r1, r9 */
/* @0x1cb46c mov r2, r8 */
/* @0x1cb470 mov r3, r7 */
/* @0x1cb474 bl 0x194f28 <_ZN9CInstance14Collision_LineEffffb> */
/* @0x1cb478 cmp r0, #0 */
/* @0x1cb47c bne 0x1cb48c <_Z21Command_CollisionLineP9CInstanceffffibb+0xfc> */
/* @0x1cb480 cmp r4, #0 */
/* @0x1cb484 bne 0x1cb41c <_Z21Command_CollisionLineP9CInstanceffffibb+0x8c> */
/* ── 1.5 统一出口：r5 就是返回值（0x1cb488..1cb498） ──────────────────────────────────────────────────────────
 * 1cb488 mov r5,#0 是「没命中」的唯一写法；1cb48c mov r0,r5 让命中/没命中走同一条收尾。
 * 收尾只弹自己压的 9 个寄存器 + d8，没有半开栈帧；三条慢路与快路全都汇到这里。
 */
/* @0x1cb488 mov r5, #0 */
/* @0x1cb48c mov r0, r5 */
/* @0x1cb490 add sp, sp, #84 */
/* @0x1cb494 vpop {d8} */
/* @0x1cb498 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 1.6 实例 id 慢路：id 表查一条，单点窄相（0x1cb49c..1cb528） ──────────────────────────────────────────────────
 * 1cb49c cmp r6,#0 / 1cb4a0 bne 1cb5a8：notme 非 0 时**先**去 1.8 比 obj == inst->[0x78]，相等直接返回 0。
 * 1cb4a4..1cb4e0 查表：槽 0x3edc4c → 0x536f28（哈希对象本体，**只解引用一次**），掩码在 +0x4、
 * 桶表在 +0x0、桶步长 8；节点 {+0x4 next, +0x8 key, +0xc value}，key 比的是实例 id（1cb4d8）。
 * 1cb4e0 取 value 当候选（只有一个，没有 next 链）→ 1cb4e4 空则返回 0。
 * 1cb4ec/1cb4f8 两道 0x68/0x69 闸后直接窄相（1cb51c），命中返回该实例、否则 0。
 * ⚠ 这条路上**没有** notme 的逐候选比较——候选唯一，等价性由 1cb5a8 那条前置短路负责。
 */
/* @0x1cb49c cmp r6, #0 */
/* @0x1cb4a0 bne 0x1cb5a8 <_Z21Command_CollisionLineP9CInstanceffffibb+0x218> */
/* @0x1cb4a4 ldr r2, [pc, #0x2ac] */
/* @0x1cb4a8 ldr r3, [r3, r2] */
/* @0x1cb4ac ldr r2, [r3, #0x4] */
/* @0x1cb4b0 ldr r3, [r3] */
/* @0x1cb4b4 and r2, r5, r2 */
/* @0x1cb4b8 ldr r3, [r3, r2, lsl #3] */
/* @0x1cb4bc cmp r3, #0 */
/* @0x1cb4c0 bne 0x1cb4d4 <_Z21Command_CollisionLineP9CInstanceffffibb+0x144> */
/* @0x1cb4c4 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb4c8 ldr r3, [r3, #0x4] */
/* @0x1cb4cc cmp r3, #0 */
/* @0x1cb4d0 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb4d4 ldr r2, [r3, #0x8] */
/* @0x1cb4d8 cmp r5, r2 */
/* @0x1cb4dc bne 0x1cb4c8 <_Z21Command_CollisionLineP9CInstanceffffibb+0x138> */
/* @0x1cb4e0 ldr r5, [r3, #0xc] */
/* @0x1cb4e4 cmp r5, #0 */
/* @0x1cb4e8 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb4ec ldrb r3, [r5, #0x68] */
/* @0x1cb4f0 cmp r3, #0 */
/* @0x1cb4f4 bne 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb4f8 ldrb r3, [r5, #0x69] */
/* @0x1cb4fc cmp r3, #0 */
/* @0x1cb500 bne 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb504 vstr s16, [sp] */
/* @0x1cb508 str r10, [sp, #0x4] */
/* @0x1cb50c mov r1, r9 */
/* @0x1cb510 mov r0, r5 */
/* @0x1cb514 mov r2, r8 */
/* @0x1cb518 mov r3, r7 */
/* @0x1cb51c bl 0x194f28 <_ZN9CInstance14Collision_LineEffffb> */
/* @0x1cb520 cmp r0, #0 */
/* @0x1cb524 bne 0x1cb48c <_Z21Command_CollisionLineP9CInstanceffffibb+0xfc> */
/* @0x1cb528 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* ── 1.7 obj == -3 慢路：房间活动链（0x1cb52c..1cb5a4） ─────────────────────────────────────────────────────
 * 1cb52c..1cb538：槽 0x3ed930 → 0x54298c(Run_Room) → *(Run_Room) 得房间 → room->[0x80] 取链头。
 * 按 Builtins_Instance 卡，room+0x80 是 A 链（活动链）的**尾**、+0x84 才是头；本块沿 +0x178（prev）
 * 前进 ⇒ 扫描顺序是「尾→头」，与绘制用 +0x17c 的顺序相反。这点会影响「多个实例同时命中时返回谁」。
 * 逐候选同样过 notme 短路（1cb544..1cb558）与 0x68/0x69 双闸，然后窄相（1cb58c）。
 * 1cb598..1cb5a0：cmp r4,#0 / mov r5,r4 / bne 1cb544 —— 这里的 r5 被复用成游标，命中时 r5 已指向候选。
 */
/* @0x1cb52c ldr r2, [pc, #0x228] */
/* @0x1cb530 ldr r3, [r3, r2] */
/* @0x1cb534 ldr r3, [r3] */
/* @0x1cb538 ldr r5, [r3, #0x80] */
/* @0x1cb53c cmp r5, #0 */
/* @0x1cb540 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb544 cmp r11, r5 */
/* @0x1cb548 movne r3, #0 */
/* @0x1cb54c andeq r3, r6, #1 */
/* @0x1cb550 ldr r4, [r5, #0x178] */
/* @0x1cb554 cmp r3, #0 */
/* @0x1cb558 bne 0x1cb598 <_Z21Command_CollisionLineP9CInstanceffffibb+0x208> */
/* @0x1cb55c ldrb r3, [r5, #0x68] */
/* @0x1cb560 cmp r3, #0 */
/* @0x1cb564 bne 0x1cb598 <_Z21Command_CollisionLineP9CInstanceffffibb+0x208> */
/* @0x1cb568 ldrb r3, [r5, #0x69] */
/* @0x1cb56c cmp r3, #0 */
/* @0x1cb570 bne 0x1cb598 <_Z21Command_CollisionLineP9CInstanceffffibb+0x208> */
/* @0x1cb574 vstr s16, [sp] */
/* @0x1cb578 str r10, [sp, #0x4] */
/* @0x1cb57c mov r0, r5 */
/* @0x1cb580 mov r1, r9 */
/* @0x1cb584 mov r2, r8 */
/* @0x1cb588 mov r3, r7 */
/* @0x1cb58c bl 0x194f28 <_ZN9CInstance14Collision_LineEffffb> */
/* @0x1cb590 cmp r0, #0 */
/* @0x1cb594 bne 0x1cb48c <_Z21Command_CollisionLineP9CInstanceffffibb+0xfc> */
/* @0x1cb598 cmp r4, #0 */
/* @0x1cb59c mov r5, r4 */
/* @0x1cb5a0 bne 0x1cb544 <_Z21Command_CollisionLineP9CInstanceffffibb+0x1b4> */
/* @0x1cb5a4 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* ── 1.8 notme 的唯一前置短路（0x1cb5a8..1cb5b4） ──────────────────────────────────────────────────────────
 * ldr r2,[r11,#0x78] / cmp r5,r2 / bne：obj（此时必 >0x1869F，即一个实例 id）等于调用者自己的 id →
 * 直接返回 0（1cb5b4 → 1cb488）。语义：notme 时「用 id 查自己」恒为假，连表都不查。
 * ⇒ 快路侧 1cb590..1cb598 是同一判断的另一份拷贝（那边查树前判，这边查表前判）。
 */
/* @0x1cb5a8 ldr r2, [r11, #0x78] */
/* @0x1cb5ac cmp r5, r2 */
/* @0x1cb5b0 bne 0x1cb4a4 <_Z21Command_CollisionLineP9CInstanceffffibb+0x114> */
/* @0x1cb5b4 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* ── 1.9 快路 A：UpdateTree → 清结果槽 → 组上下文 → 组量化线段（0x1cb5b8..1cb644） ──────────────────────────────────
 * 1cb5b8 先把 PIC 锚 0x3f1c58 存到 [sp,#8]（1cb5c4 再取回，因为 UpdateTree 会破坏 r3）。
 * 1cb5bc bl UpdateTree()：把脏表（s_dirty_list 0x5429ac）里 +0x68/+0x69 都为 0 的实例重算 bbox 并
 * 重插树 —— 命令层查树前**先补账**，保证树是最新的（UpdateTree 本体见 LayerHelpers 卡旁证）。
 * 1cb5c8/1cb5dc 从槽 0x3f0b10 取到 0x5428b8（= &s_instancePtr）；1cb5ec str 到 [sp,#0xc] 存地址，
 * 1cb5f0 str r4,[r0] 把 *(&s_instancePtr) 清 0 —— 这是快路唯一的「结果初始化」。
 * 1cb5e4/1cb5e8/1cb600：上下文三小块 precise(+0x20)、notme(+0x21)、self(+0x24) 先落地，
 * 上下文基址 = sp+40（4 个 double 紧接着写在下一条）。
 * 1cb604 str r5,[r1]：目标 obj **无条件**写全局 0x3f50e4（-3 也照写），这是回调的对象过滤依据。
 * 1cb5c0..1cb62c：4 个 double 依次是 x1,y1,x2,y2（vcvt.f64.f32 + vstr 到 sp+40/48/56/64），
 * 直接从原始 float 转来 ⇒ 回调里窄相用的是**未量化**的坐标，与下面的量化线段不是同一组数。
 */
/* @0x1cb5b8 str r3, [sp, #0x8] */
/* @0x1cb5bc bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1cb5c0 vmov s11, r9 */
/* @0x1cb5c4 ldr r3, [sp, #0x8] */
/* @0x1cb5c8 ldr r0, [pc, #0x190] */
/* @0x1cb5cc vcvt.f64.f32 d6, s11 */
/* @0x1cb5d0 ldr r1, [pc, #0x18c] */
/* @0x1cb5d4 vmov s11, r8 */
/* @0x1cb5d8 ldr r2, [pc, #0x188] */
/* @0x1cb5dc ldr r0, [r3, r0] */
/* @0x1cb5e0 add r1, pc, r1 */
/* @0x1cb5e4 strb r10, [sp, #0x48] */
/* @0x1cb5e8 strb r6, [sp, #0x49] */
/* @0x1cb5ec str r0, [sp, #0xc] */
/* @0x1cb5f0 str r4, [r0] */
/* @0x1cb5f4 vcvt.f64.f32 d7, s11 */
/* @0x1cb5f8 vstr d6, [sp, #40] */
/* @0x1cb5fc vmov s11, r7 */
/* @0x1cb600 str r11, [sp, #0x4c] */
/* @0x1cb604 str r5, [r1] */
/* @0x1cb608 vcvt.f64.f32 d6, s11 */
/* @0x1cb60c vstr d7, [sp, #48] */
/* @0x1cb610 vstr d6, [sp, #56] */
/* ── 1.10 量化：4 个 float = {起点x, 起点y, dx, dy}，全按 (int) 量化（0x1cb614..1cb644） ─────────────────────────
 * 1cb614/1cb61c：s13=x1 → (int)x1；1cb618：s11=x2（1cb5fc 刚放进去）→ (int)x2；
 * 1cb620/1cb624：r7 = (int)x2、r9 = (int)x1 —— **从这里起 r9/r7 不再是 float 位模式**。
 * 1cb628/1cb638：y2 → double 存 [sp+64]，同时 s16 = (int)y2；1cb634/1cb640：s14=y1 → s15=(int)y1。
 * 1cb644 cmp r9,r7 比的就是这两个整数 ⇒ 支路选择由**量化后**的 x 决定，与原始 float 的先后可能不同。
 * w0/w1 是起点（(int) 后再 vcvt.f32.s32 转回 float），w2/w3 是两个整数差 —— 见 1.11/1.15 两支。
 */
/* @0x1cb614 vmov s13, r9 */
/* @0x1cb618 vcvt.s32.f32 s11, s11 */
/* @0x1cb61c vcvt.s32.f32 s13, s13 */
/* @0x1cb620 vmov r7, s11 */
/* @0x1cb624 vmov r9, s13 */
/* @0x1cb628 vcvt.f64.f32 d7, s16 */
/* @0x1cb62c vstr d7, [sp, #64] */
/* @0x1cb630 ldr r3, [r3, r2] */
/* @0x1cb634 vmov s14, r8 */
/* @0x1cb638 vcvt.s32.f32 s16, s16 */
/* @0x1cb63c ldr r0, [r3] */
/* @0x1cb640 vcvt.s32.f32 s15, s14 */
/* ── 1.11 支路 B：x1 >= x2（取 x2 端为起点，0x1cb64c..1cb684） ───────────────────────────────────────────────
 * 1cb64c r2=(int)y1、1cb650 rsb r9,r7,r9 ⇒ r9 = (int)x1-(int)x2 = dx ≥ 0（两个整数相减，不是位模式）。
 * 1cb654 r3=(int)y2、1cb658 s11=dx、1cb660 (float)dx → [sp+32]=w2。
 * 1cb65c (float)(int)y2 → [sp+28]=w1（起点 y）。
 * 1cb66c s13=(int)x2、1cb67c (float) → [sp+24]=w0（起点 x）。
 * 1cb670 rsb r2,r3,r2 ⇒ r2 = (int)y1-(int)y2 = dy → 1cb678 (float)dy → [sp+36]=w3。
 * ⇒ Line = {x2_i, y2_i, dx, dy}，dx ≥ 0，dy 带符号。
 */
/* @0x1cb644 cmp r9, r7 */
/* @0x1cb648 blt 0x1cb714 <_Z21Command_CollisionLineP9CInstanceffffibb+0x384> */
/* @0x1cb64c vmov r2, s15 */
/* @0x1cb650 rsb r9, r7, r9 */
/* @0x1cb654 vmov r3, s16 */
/* @0x1cb658 vmov s11, r9 */
/* @0x1cb65c vcvt.f32.s32 s16, s16 */
/* @0x1cb660 vcvt.f32.s32 s13, s11 */
/* @0x1cb664 vstr s16, [sp, #28] */
/* @0x1cb668 vstr s13, [sp, #32] */
/* @0x1cb66c vmov s13, r7 */
/* @0x1cb670 rsb r2, r3, r2 */
/* @0x1cb674 vmov s15, r2 */
/* @0x1cb678 vcvt.f32.s32 s14, s15 */
/* @0x1cb67c vcvt.f32.s32 s15, s13 */
/* @0x1cb680 vstr s14, [sp, #36] */
/* @0x1cb684 vstr s15, [sp, #24] */
/* ── 1.12 快路 B：SearchLine 的 6 个实参（0x1cb688..0x1cb6b4） ─────────────────────────────────────────────
 * 1cb688/1cb698：ldr r12,[pc,#0xdc]（池字 1cb76c=0xffffce64）+ add r12,pc,r12（PC=1cb6a0）
 * ⇒ r12 = 0x1c8504 = 回调地址（**绝对代码地址**，不是 GOT 读）。
 * 实参（按 RTree<...>::SearchLine(Node*,Line*,int&,cb,void*) 的 this 调用约定）：
 *   r0 = *g_tree（1cb63c 先取 *(0x3ee24c)=g_tree，再 ldr r0,[r3] 解一次）
 *   r1 = [r0,#0x10]（树对象的 +0x10，当 Node* 传）
 *   r2 = sp+24（&Line，4 个 float）  r3 = sp+20（&count，1cb6ac 先写 0）
 *   [sp] = 0x1c8504（回调）          [sp+4] = sp+40（&context，即 1.9 的 0x28 字节块）
 * ⇒ 树查询**只带线段，不带 obj**：对象过滤全在回调里（回调读全局 0x3f50e4 再比）。
 * 1cb6b0 bl 0x1cb234；1cb6b4 ldr r0,[sp,#0xc] 取回 &s_instancePtr、1cb6b8 ldr r5,[r0] 读结果。
 * ⇒ 结果不经过 r0 返回，靠全局槽；1cb6bc 直接跳 1cb48c（mov r0,r5）。
 */
/* @0x1cb688 ldr r12, [pc, #0xdc] */
/* @0x1cb68c add r3, sp, #40 */
/* @0x1cb690 ldr r1, [r0, #0x10] */
/* @0x1cb694 add r2, sp, #24 */
/* @0x1cb698 add r12, pc, r12 */
/* @0x1cb69c str r3, [sp, #0x4] */
/* @0x1cb6a0 str r12, [sp] */
/* @0x1cb6a4 add r3, sp, #20 */
/* @0x1cb6a8 mov r12, #0 */
/* @0x1cb6ac str r12, [sp, #0x14] */
/* @0x1cb6b0 bl 0x1cb234 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_> */
/* @0x1cb6b4 ldr r0, [sp, #0xc] */
/* @0x1cb6b8 ldr r5, [r0] */
/* @0x1cb6bc b 0x1cb48c <_Z21Command_CollisionLineP9CInstanceffffibb+0xfc> */
/* ── 1.13 自备对象表查找（objptr==0 时；0x1cb6c0..1cb710） ───────────────────────────────────────────────────
 * 槽 0x3edc44 → 0x542374 = g_ObjectHash，**再解引用一次**（1cb6c8 ldr r3,[r3]）才得哈希对象本体；
 * 这与 id 表（0x536f28 直接是对象本体）差一层间接，是本卡最容易搞混的地方。
 * 布局同 id 表：掩码 +0x4、桶表 +0x0、桶步长 8、节点 {+0x4 next, +0x8 key, +0xc value}。
 * 查到后 1cb704/1cb708 把 value 存进 [sp,#0x10]（复用 objptr 槽），1cb70c 跳回 1cb410 走 1.4 的链遍历；
 * 查不到 1cb710 返回 0。⇒ 这一段与 ShouldUseFastCollision 内部的查表是同一张表的第二次查。
 */
/* @0x1cb6c0 ldr r2, [pc, #0xa8] */
/* @0x1cb6c4 ldr r3, [r3, r2] */
/* @0x1cb6c8 ldr r3, [r3] */
/* @0x1cb6cc ldr r2, [r3, #0x4] */
/* @0x1cb6d0 ldr r3, [r3] */
/* @0x1cb6d4 and r2, r5, r2 */
/* @0x1cb6d8 ldr r3, [r3, r2, lsl #3] */
/* @0x1cb6dc cmp r3, #0 */
/* @0x1cb6e0 bne 0x1cb6f4 <_Z21Command_CollisionLineP9CInstanceffffibb+0x364> */
/* @0x1cb6e4 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb6e8 ldr r3, [r3, #0x4] */
/* @0x1cb6ec cmp r3, #0 */
/* @0x1cb6f0 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb6f4 ldr r2, [r3, #0x8] */
/* @0x1cb6f8 cmp r5, r2 */
/* @0x1cb6fc bne 0x1cb6e8 <_Z21Command_CollisionLineP9CInstanceffffibb+0x358> */
/* @0x1cb700 ldr r2, [r3, #0xc] */
/* @0x1cb704 cmp r2, #0 */
/* @0x1cb708 str r2, [sp, #0x10] */
/* @0x1cb70c bne 0x1cb410 <_Z21Command_CollisionLineP9CInstanceffffibb+0x80> */
/* @0x1cb710 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* ── 1.14 支路 A：x1 < x2（取 x1 端为起点，0x1cb714..1cb750） ────────────────────────────────────────────────
 * 1cb718 rsb r7,r9,r7 ⇒ r7 = (int)x2-(int)x1 = dx ≥ 0；1cb720 s11=dx → 1cb728 (float) → [sp+32]=w2。
 * 1cb714 r2=(int)y2、1cb724 (float)(int)y1 → [sp+28]=w1；1cb734/1cb738 (float)(int)x1 → [sp+24]=w0。
 * 1cb73c rsb r2,r3,r2 ⇒ (int)y2-(int)y1 = dy；1cb744 (float) → [sp+36]=w3。
 * ⇒ 与 1.11 完全同构，只是起点换成 x1 端；两支汇合于 1cb688（SearchLine 实参）。
 * ⚠ 量化后果：dx/dy 是整数差，x1/x2 落进同一整数格时 dx=0；此时「线段」在树里退化成一条竖线，
 * 盒测试（0x1c8870，跨卡）对 dx=0 的行为未在本卡解开，见 open。
 */
/* @0x1cb714 vmov r2, s16 */
/* @0x1cb718 rsb r7, r9, r7 */
/* @0x1cb71c vmov r3, s15 */
/* @0x1cb720 vmov s11, r7 */
/* @0x1cb724 vcvt.f32.s32 s15, s15 */
/* @0x1cb728 vcvt.f32.s32 s13, s11 */
/* @0x1cb72c vstr s15, [sp, #28] */
/* @0x1cb730 vstr s13, [sp, #32] */
/* @0x1cb734 vmov s13, r9 */
/* @0x1cb738 vcvt.f32.s32 s15, s13 */
/* @0x1cb73c rsb r2, r3, r2 */
/* @0x1cb740 vmov s16, r2 */
/* @0x1cb744 vcvt.f32.s32 s14, s16 */
/* @0x1cb748 vstr s15, [sp, #24] */
/* @0x1cb74c vstr s14, [sp, #36] */
/* @0x1cb750 b 0x1cb688 <_Z21Command_CollisionLineP9CInstanceffffibb+0x2f8> */
/* ── 1.15 池字 8 个（0x1cb754..0x1cb770，非指令） ──────────────────────────────────────────────────────────
 * objdump 把 1cb754/1cb764 印成 eoreq 之类，实际是数据字；逐字含义如下（PC 基准一律 +8）。
 * 1cb754 0x00226878 → 1cb3e0+0x226878 = 0x3f1c58（PIC 锚）
 * 1cb758 0xffffbff4 → 0x3f1c58-0x400c = 0x3edc4c（id 表槽）
 * 1cb75c 0xffffbcd8 → 0x3f1c58-0x4328 = 0x3ed930（Run_Room 槽）
 * 1cb760 0xffffeeb8 → 0x3f1c58-0x1148 = 0x3f0b10（&s_instancePtr 槽）
 * 1cb764 0x00229b00 → 1cb5e4+0x229b00 = 0x3f50e4（目标 obj 槽）
 * 1cb768 0xffffc5f4 → 0x3ee24c（g_tree 槽）
 * 1cb76c 0xffffce64 → 1cb6a0-0x319c = 0x1c8504（回调地址）
 * 1cb770 0xffffbfec → 0x3f1c58-0x4014 = 0x3edc44（g_ObjectHash 槽）
 */
/* ↑ 非指令：池字 0x00226878（PIC 锚加数，1cb3d8 的 add r3,pc,r3 → 0x3f1c58），objdump 误译为 eoreq */
/* @0x1cb754 eoreq r6, r2, r8, ror r8 */
/* @0x1cb758 .word 0xffffbff4 */
/* @0x1cb75c .word 0xffffbcd8 */
/* @0x1cb760 .word 0xffffeeb8 */
/* ↑ 非指令：池字 0x00229b00（1cb5e4 的 add r1,pc,r1 → 0x3f50e4 目标 obj 槽），objdump 误译为 eoreq */
/* @0x1cb764 eoreq r9, r2, r0, lsl #22 */
/* @0x1cb768 .word 0xffffc5f4 */
/* @0x1cb76c .word 0xffffce64 */
/* @0x1cb770 .word 0xffffbfec */

/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 2 · Command_CollisionRectangle（collision_rectangle 的命令层）
 * @func 0x1ca350 0x1ca6d8  size 904  226 锚点（218 条指令 + 8 个池字 0x1ca6b8..0x1ca6d4）
 * 符号: _Z26Command_CollisionRectangleP9CInstanceffffibb
 *       → CInstance* Command_CollisionRectangle(CInstance* inst, float x1, float y1, float x2, float y2,
 *                                              int obj, bool precise, bool notme)
 * 位置: index 第 2 组。池字区末尾就是 Command_InstancePlace 0x1ca6d8 的第一条指令（两函数首尾相接）
 * 调用者: 全 .text 精确 1 处 bl、无 b 尾跳 —— F_CollisionRectangle 0x109030 的 0x1090d8
 * 同层: RTree::Search 0x10d720（快路唯一查询）、UpdateTree 0x1cc24c、ShouldUseFastCollision 0x1c8df8、
 *       CInstance::Collision_Rectangle 0x1946f4、回调 0x1c83c0
 * 一句话: 矩形 (x1,y1)-(x2,y2) 撞 obj 指定的实例集合，命中返回实例指针、否则 0；三条慢路与 Line 同构，
 *         快路把矩形截断成两个整数角后调 RTree::Search，命中实例由全局 s_instancePtr 带回。
 * ═══════════════════════════════════════════════════════════════════════════
 */

/* ── 语义草案 ─────────────────────────────────────────────────────────────
 *   CInstance* Command_CollisionRectangle(CInstance* inst, float x1,float y1,float x2,float y2,
 *                                         int obj, bool precise, bool notme) {
 *     CObjectGM* o = NULL;                              // 1ca374 清
 *     int g = ShouldUseFastCollision(obj, &o);          // 1ca390
 *     if (g == -1) return NULL;                         // 1ca39c..1ca3a0
 *     if (g == 1) {                                     // 1ca3a4..1ca3a8 → 1ca578
 *        UpdateTree();                                   // 1ca578
 *        s_instancePtr = NULL;                           // 1ca588
 *        if (notme && obj == inst->[0x78]) return NULL;  // 1ca58c..1ca598
 *        c.precise = precise; c.notme = notme; c.self = inst;   // 1ca5a4/1ca5ac/1ca5b0（存，不判）
 *        g_objRect = obj;                                // 1ca5b4 → 0x3f50e4
 *        int lo[2] = { min((int)x1,(int)x2), min((int)y1,(int)y2) };   // 1ca5d0..1ca620（向零截断）
 *        int hi[2] = { max((int)x1,(int)x2), max((int)y1,(int)y2) };   // 1ca624..1ca63c
 *        Ctx c = { (double)x1,(double)y1,(double)x2,(double)y2, precise,notme,inst };
 *        RTree::Search(*g_tree, lo, hi, 0x1c83c0, &c);    // 1ca64c
 *        return s_instancePtr;                           // 1ca650
 *     }
 *     if (obj == -3) { for (p = Run_Room->[0x80]; p; p = p->[0x178]) ... }   // 1ca4ec
 *     if (obj > 99999) { ...id 表查一条... }                                  // 1ca45c
 *     if (!o) o = ObjMap.find(obj);                      // 1ca658
 *     for (n = o->[0xd0]; n; n = n->[0x0]) { ...p = n->[0x8] ... }           // 1ca3c4..1ca444
 *     return NULL;                                       // 1ca448
 *   }
 *
 * ── 门表（按执行顺序）────────────────────────────────────────────────────
 *   ① g：-1 / 1 / 2                                       1ca390..1ca3a8
 *   ② obj == -3                                           1ca3ac..1ca3b0
 *   ③ obj > 0x1869F                                       1ca3b4..1ca3c0
 *   ④ o == 0 → 自备查表                                    1ca3c4..1ca3cc / 1ca658
 *   ⑤ 节点非空 → node->[0x8] 非空                          1ca3d4..1ca3e4
 *   ⑥ notme 短路 (inst==cand) && (notme&1)                 1ca3f0..1ca400
 *   ⑦ +0x68 != 0 → 跳过                                   1ca404..1ca40c
 *   ⑧ +0x69 != 0 → 跳过                                   1ca410..1ca418
 *   ⑨ 窄相返回 0 → 下一个；非 0 → 返回该 cand               1ca438..1ca444
 *   快路侧：ⓐ notme && obj == inst->[0x78] → 0              1ca58c..1ca598
 *          ⓑ 回调 0x1c83c0 内部三道闸 + 对象匹配（跨卡）
 *   ⇒ 与 Line 的门表逐条同位，**唯一差别**是 ⑨ 的窄相换成 Collision_Rectangle、快路查询换成 Rect 版 Search。
 *
 * ── 字段表 ───────────────────────────────────────────────────────────────
 *   CInstance：+0x68/+0x69 闸、+0x78 id、+0x178 prev（1ca510 取）
 *   CObjectGM：+0xd0 节点链头 {next@+0x0, inst@+0x8}（1ca3d0/1ca3e8/1ca3ec）
 *   全局：s_instancePtr 0x5428b8（清 1ca588 / 读 1ca650）、0x3f50e4（写 1ca5b4）、g_tree、g_ObjectHash、
 *         Run_Room、id 表 0x536f28
 *   写集：同样只有两个全局（结果槽、目标槽）⇒ 不改任何实例状态。
 *
 * ── 已证（指令级）───────────────────────────────────────────────────────
 *  1. 帧 120 B 与实参：8 push + vpush {d8,d9} + 72 = 120；1ca35c vldr s19,[sp,#120] 取 y2、
 *     1ca368 ldr r4,[sp,#0x7c] 取 obj、ldrb r8/[sp,#0x80]、ldrb r6/[sp,#0x84] 取两个 bool。
 *     ⚠ s 寄存器分配与 Line **不同**（这里 s16=x2、s19=y2），逐条比对时不能照抄 Line。
 *  2. 分流（1ca39c/1ca3a0/1ca3a8）：-1 → 1ca448；1 → 1ca578；其余 → 1ca3ac。
 *  3. 两个特殊值：cmn r4,#3（1ca3ac）；movw/movt 0x1869f + bgt（1ca3b4..1ca3c0）。
 *  4. 对象链（1ca3d0..1ca444）：节点 {next@0x0, inst@0x8}；1ca3ec 先取 next 再判候选；notme 只取最低位。
 *  5. 快路上下文（1ca59c..1ca5b4）：基址 sp+32，4 个 double + precise@+0x20 + notme@+0x21 + self@+0x24，
 *     与回调 0x1c83c0 的 ldrb [r6,#0x20]/[r6,#0x21]、ldr r3,[r6,#0x24] 吻合；obj 无条件写 0x3f50e4。
 *  6. 快路两角是**向零截断**的整数（1ca5e0/1ca610/1ca614/1ca624/1ca628/1ca630/1ca638 共 7 条 vcvt.s32），
 *     min/max 由「条件 vcvt」而不是 cmov 合成；两个角分别落在 sp+16（lo）与 sp+24（hi）。
 *  7. Search 实参（1ca640..1ca64c）：r0=*g_tree、r1=lo、r2=hi、r3=0x1c83c0、[sp]=&ctx；结果读 s_instancePtr。
 *     0x10d720 自身把 [this+0x10] 当根节点传下去（10d728 ldr r4,[r0,#0x10] + 10d744 mov r1,r4）⇒
 *     「RTree 对象 +0x10 = 根节点」在本卡有两处独立证据（这里与 1.12 的 SearchLine 实参）。
 *  8. 返回值同 Line：命中 = 候选指针、没命中 = 0，两条路共用 1ca44c 收尾。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *  · RTree::Search（0x10d720 薄壳 + 0x10d558 递归）内部的盒子比较/剪枝未解；本卡只证 lo/hi 是截断整数、
 *    以及薄壳把它们原样塞进 Rect{+0x10..+0x1c}、count 初值 0、返回 count。
 *  · 截断的后果：hi 角向下取整 ⇒ 快路查询盒在「max 一侧」可能比精确矩形小（亚像素差的实例可能被漏），
 *    lo 角同样向下取整 ⇒ 在「min 一侧」可能更大（只多不漏）。回调会用 double 精确矩形再判一次，
 *    所以「多」不会出错、**「漏」会**。是否真的漏取决于 0x10d558 的盒测试，未证 ⇒ 列 open。
 *  · 回调 0x1c83c0 不属本索引（同 Line 的 open：对象匹配、+0x48 闸、最后命中者胜）。
 *  · g_tree 空指针无闸（ShouldUseFastCollision 内），同 Line。
 */
/* ── 2.1 入口：帧 120 B、实参落位、objptr 局部清 0（0x1ca350..0x1ca390） ─────────────────────────────────────────
 * push 8 寄存器(32) + vpush {d8,d9}(16) + sub 72 = 120 ⇒ 栈实参从 [sp+120] 起。
 * r7=inst、s17=x1([r1])、s18=y1([r2])、s16=x2([r3])、s19=y2([sp+120])、r4=obj([sp+0x7c])、
 * r8=precise([sp+0x80] byte)、r6=notme([sp+0x84] byte) —— 与 collision_line 同排布（软浮点）。
 * 1ca360 add r12,sp,#72；1ca374 str r5,[r12,#-0x3c]! ⇒ 落址 sp+12 = ShouldUseFastCollision 的出参槽，
 * 先清 0。r5 这一个 0 后面还当「没命中」的返回值用（1ca448 mov r5,#0 是另一处）。
 * ⚠ s16/s19 的分配与 Line 不同（Line 把 y2 放 s16、x2 放 r7）：这里 x2 在 s16、y2 在 s19，读实参时别照抄。
 */
/* @0x1ca350 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ca354 vpush {d8, d9} */
/* @0x1ca358 sub sp, sp, #72 */
/* @0x1ca35c vldr s19, [sp, #120] */
/* @0x1ca360 add r12, sp, #72 */
/* @0x1ca364 mov r7, r0 */
/* @0x1ca368 ldr r4, [sp, #0x7c] */
/* @0x1ca36c mov r5, #0 */
/* @0x1ca370 vmov s17, r1 */
/* @0x1ca374 str r5, [r12, #-0x3c]! */
/* @0x1ca378 mov r1, r12 */
/* @0x1ca37c vmov s18, r2 */
/* @0x1ca380 mov r0, r4 */
/* @0x1ca384 vmov s16, r3 */
/* @0x1ca388 ldrb r8, [sp, #0x80] */
/* @0x1ca38c ldrb r6, [sp, #0x84] */
/* ── 2.2 判决：三值分流 + PIC 锚（0x1ca390..0x1ca3ac） ──────────────────────────────────────────────────────
 * 1ca394/1ca398：ldr r9,[pc,#0x31c]（池字 1ca6b8=0x002278b8）+ add r9,pc,r9（PC=1ca3a0）
 * ⇒ r9 = 0x3f1c58，与 Line/Place 同一个 PIC 锚（三节可互证）。
 * cmn r0,#1 → -1 → 1ca448(返回 0)；cmp r0,#1 → 1 → 1ca578(树)；其余 → 1ca3ac(慢路)。
 * 本函数把 rect 的两个 float 一直留在 s16..s19 里，直到组窄相/组上下文才转格式 ⇒ 慢路与快路用的是
 * 同一组**未量化**的 float（快路只在 RTree 查询那一侧另做整数量化，见 2.10）。
 */
/* @0x1ca390 bl 0x1c8df8 <_Z22ShouldUseFastCollisioniPP9CObjectGM> */
/* @0x1ca394 ldr r9, [pc, #0x31c] */
/* @0x1ca398 add r9, pc, r9 */
/* @0x1ca39c cmn r0, #1 */
/* @0x1ca3a0 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca3a4 cmp r0, #1 */
/* @0x1ca3a8 beq 0x1ca578 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x228> */
/* ── 2.3 慢路分流：-3 / >0x1869F / 对象号（0x1ca3ac..0x1ca3c4） ─────────────────────────────────────────────
 * cmn r4,#3 → obj == -3 → 1ca4ec（房间活动链，只在 option 关时可达）；
 * movw/movt 0x1869f + bgt → 1ca45c（实例 id 表）；其余走对象号：1ca3c4 看 objptr(=sp+12) 是否为空。
 * objptr 为空说明 ShouldUseFastCollision 走的是 option==0 那档（return 2 且不写 *out）⇒ 落到 1ca658 自备查表。
 */
/* @0x1ca3ac cmn r4, #3 */
/* @0x1ca3b0 beq 0x1ca4ec <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x19c> */
/* @0x1ca3b4 movw r3, #0x869f */
/* @0x1ca3b8 movt r3, #0x1 */
/* @0x1ca3bc cmp r4, r3 */
/* @0x1ca3c0 bgt 0x1ca45c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x10c> */
/* ── 2.4 对象号慢路：obj->[0xd0] 的实例节点链（0x1ca3c4..1ca444） ───────────────────────────────────────────────
 * 1ca3d0 r4 = objptr->[0xd0]（节点链头）；1ca3dc/1ca3e8 取 node->[0x8] 当候选，1ca3ec 先把 node->[0x0]
 * 存进 r4 当 next，所以候选指针不会被覆盖（与 Line 1cb428/1cb42c 同构）。
 * 1ca3f0..1ca400 notme 短路（andeq r3,r6,#1 只取最低位）；1ca404/1ca410 两道 0x68/0x69 闸。
 * 1ca41c/1ca420 组窄相实参：vstr s19,[sp]（y2）、str r8,[sp,#4]（precise）；r1..r3 由 s17/s18/s16 转来。
 * 1ca434 bl Collision_Rectangle 0x1946f4；1ca438 命中 → 1ca44c 返回 r5(=候选)；1ca440 否则用 r4(=next) 续。
 */
/* @0x1ca3c4 ldr r3, [sp, #0xc] */
/* @0x1ca3c8 cmp r3, #0 */
/* @0x1ca3cc beq 0x1ca658 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x308> */
/* @0x1ca3d0 ldr r4, [r3, #0xd0] */
/* @0x1ca3d4 cmp r4, #0 */
/* @0x1ca3d8 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca3dc ldr r3, [r4, #0x8] */
/* @0x1ca3e0 cmp r3, #0 */
/* @0x1ca3e4 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca3e8 ldr r5, [r4, #0x8] */
/* @0x1ca3ec ldr r4, [r4] */
/* @0x1ca3f0 cmp r7, r5 */
/* @0x1ca3f4 movne r3, #0 */
/* @0x1ca3f8 andeq r3, r6, #1 */
/* @0x1ca3fc cmp r3, #0 */
/* @0x1ca400 bne 0x1ca3d4 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x84> */
/* @0x1ca404 ldrb r3, [r5, #0x68] */
/* @0x1ca408 cmp r3, #0 */
/* @0x1ca40c bne 0x1ca3d4 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x84> */
/* @0x1ca410 ldrb r3, [r5, #0x69] */
/* @0x1ca414 cmp r3, #0 */
/* @0x1ca418 bne 0x1ca3d4 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x84> */
/* @0x1ca41c vstr s19, [sp] */
/* @0x1ca420 str r8, [sp, #0x4] */
/* @0x1ca424 mov r0, r5 */
/* @0x1ca428 vmov r1, s17 */
/* @0x1ca42c vmov r2, s18 */
/* @0x1ca430 vmov r3, s16 */
/* @0x1ca434 bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x1ca438 cmp r0, #0 */
/* @0x1ca43c bne 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca440 cmp r4, #0 */
/* @0x1ca444 bne 0x1ca3dc <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x8c> */
/* ── 2.5 统一出口（0x1ca448..0x1ca458） ─────────────────────────────────────────────────────────────────
 * 1ca448 mov r5,#0 是「没命中」；1ca44c mov r0,r5 让命中/没命中共用收尾（与 Line 1cb488/1cb48c 同构）。
 * 收尾 add sp,#72 + vpop {d8,d9} + pop 8 个寄存器，三条慢路与快路都汇到这里。
 */
/* @0x1ca448 mov r5, #0 */
/* @0x1ca44c mov r0, r5 */
/* @0x1ca450 add sp, sp, #72 */
/* @0x1ca454 vpop {d8, d9} */
/* @0x1ca458 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ── 2.6 实例 id 慢路：查 id 表，单点窄相（0x1ca45c..1ca4e8） ───────────────────────────────────────────────────
 * 1ca45c/1ca460 cmp r6,#0 / bne 1ca568：notme 非 0 时先去 2.8 比 obj == inst->[0x78]。
 * 槽 0x3edc4c → 0x536f28（哈希对象本体，只解引用一次）：掩码 +0x4、桶表 +0x0、桶步长 8、
 * 节点 {+0x4 next, +0x8 key, +0xc value}，key 比实例 id（1ca498）。
 * 1ca4a0 取 value 当候选；1ca4a4 空 → 返回 0；1ca4ac/1ca4b8 两道 0x68/0x69 闸；1ca4dc 窄相；
 * 命中 1ca4e0 → 1ca44c，否则 1ca4e8 → 返回 0。这条路上**没有**逐候选 notme 比较（候选唯一）。
 */
/* @0x1ca45c cmp r6, #0 */
/* @0x1ca460 bne 0x1ca568 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x218> */
/* @0x1ca464 ldr r3, [pc, #0x250] */
/* @0x1ca468 ldr r3, [r9, r3] */
/* @0x1ca46c ldr r2, [r3, #0x4] */
/* @0x1ca470 ldr r3, [r3] */
/* @0x1ca474 and r2, r4, r2 */
/* @0x1ca478 ldr r3, [r3, r2, lsl #3] */
/* @0x1ca47c cmp r3, #0 */
/* @0x1ca480 bne 0x1ca494 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x144> */
/* @0x1ca484 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca488 ldr r3, [r3, #0x4] */
/* @0x1ca48c cmp r3, #0 */
/* @0x1ca490 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca494 ldr r2, [r3, #0x8] */
/* @0x1ca498 cmp r4, r2 */
/* @0x1ca49c bne 0x1ca488 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x138> */
/* @0x1ca4a0 ldr r5, [r3, #0xc] */
/* @0x1ca4a4 cmp r5, #0 */
/* @0x1ca4a8 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca4ac ldrb r3, [r5, #0x68] */
/* @0x1ca4b0 cmp r3, #0 */
/* @0x1ca4b4 bne 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca4b8 ldrb r3, [r5, #0x69] */
/* @0x1ca4bc cmp r3, #0 */
/* @0x1ca4c0 bne 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca4c4 vstr s19, [sp] */
/* @0x1ca4c8 str r8, [sp, #0x4] */
/* @0x1ca4cc mov r0, r5 */
/* @0x1ca4d0 vmov r1, s17 */
/* @0x1ca4d4 vmov r2, s18 */
/* @0x1ca4d8 vmov r3, s16 */
/* @0x1ca4dc bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x1ca4e0 cmp r0, #0 */
/* @0x1ca4e4 bne 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca4e8 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* ── 2.7 obj == -3 慢路：房间活动链（0x1ca4ec..1ca564） ─────────────────────────────────────────────────────
 * 槽 0x3ed930 → 0x54298c(Run_Room) → *(Run_Room) = 房间 → room->[0x80]（A 链**尾**）。
 * 沿 +0x178（prev）前进 ⇒ 顺序是「尾→头」，与绘制（+0x17c）相反（见头部字段表）。
 * 每轮同样过 notme 短路（1ca504..1ca514）与 0x68/0x69 双闸，再窄相（1ca54c）。
 * 1ca558/1ca55c/1ca560：cmp r4,#0 / mov r5,r4 / bne 1ca504 —— 游标也用 r5。
 */
/* @0x1ca4ec ldr r3, [pc, #0x1cc] */
/* @0x1ca4f0 ldr r3, [r9, r3] */
/* @0x1ca4f4 ldr r3, [r3] */
/* @0x1ca4f8 ldr r5, [r3, #0x80] */
/* @0x1ca4fc cmp r5, #0 */
/* @0x1ca500 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca504 cmp r7, r5 */
/* @0x1ca508 movne r3, #0 */
/* @0x1ca50c andeq r3, r6, #1 */
/* @0x1ca510 ldr r4, [r5, #0x178] */
/* @0x1ca514 cmp r3, #0 */
/* @0x1ca518 bne 0x1ca558 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x208> */
/* @0x1ca51c ldrb r3, [r5, #0x68] */
/* @0x1ca520 cmp r3, #0 */
/* @0x1ca524 bne 0x1ca558 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x208> */
/* @0x1ca528 ldrb r3, [r5, #0x69] */
/* @0x1ca52c cmp r3, #0 */
/* @0x1ca530 bne 0x1ca558 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x208> */
/* @0x1ca534 vstr s19, [sp] */
/* @0x1ca538 str r8, [sp, #0x4] */
/* @0x1ca53c mov r0, r5 */
/* @0x1ca540 vmov r1, s17 */
/* @0x1ca544 vmov r2, s18 */
/* @0x1ca548 vmov r3, s16 */
/* @0x1ca54c bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x1ca550 cmp r0, #0 */
/* @0x1ca554 bne 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca558 cmp r4, #0 */
/* @0x1ca55c mov r5, r4 */
/* @0x1ca560 bne 0x1ca504 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x1b4> */
/* @0x1ca564 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* ── 2.8 notme 的唯一前置短路（0x1ca568..0x1ca574） ────────────────────────────────────────────────────────
 * ldr r3,[r7,#0x78] / cmp r4,r3 / bne 1ca464：obj 等于调用者自己的 id → 返回 0（1ca574 → 1ca448）。
 * 与 Line 1cb5a8..1cb5b4 同构；快路侧 1ca590..1ca598 是同一判断的第二份。
 */
/* @0x1ca568 ldr r3, [r7, #0x78] */
/* @0x1ca56c cmp r4, r3 */
/* @0x1ca570 bne 0x1ca464 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x114> */
/* @0x1ca574 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* ── 2.9 快路 A：UpdateTree → 清结果槽 → notme 短路 → 上下文落地（0x1ca578..0x1ca5d0） ────────────────────────────
 * 1ca578 bl UpdateTree()（补脏表再查树，同 Line 1cb5bc）。
 * 1ca57c..1ca588：槽 0x3f0b10 → 0x5428b8 = &s_instancePtr；r10 存这个地址，str r5,[r10] 清 0 ——
 * 注意 r5 此刻 = 0（入口 1ca36c），因为 -1 已经在 2.2 返回了。
 * 1ca58c..1ca598 notme 前置短路：notme != 0 且 obj == inst->[0x78] → 1ca44c 返回 0（结果槽已清）。
 * 1ca59c..1ca5d4 组上下文（基址 sp+32）：4 个 double 依次 x1,y1,x2,y2；
 * 1ca5a4/1ca5ac/1ca5b0 三小块：precise@+0x20、notme@+0x21、self@+0x24；
 * 1ca5b4 把 obj **无条件**写全局 0x3f50e4（回调靠它做对象过滤，树查询不带 obj）。
 */
/* @0x1ca578 bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1ca57c ldr r3, [pc, #0x140] */
/* @0x1ca580 cmp r6, #0 */
/* @0x1ca584 ldr r10, [r9, r3] */
/* @0x1ca588 str r5, [r10] */
/* @0x1ca58c beq 0x1ca59c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x24c> */
/* @0x1ca590 ldr r3, [r7, #0x78] */
/* @0x1ca594 cmp r4, r3 */
/* @0x1ca598 beq 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca59c vcvt.f64.f32 d6, s17 */
/* @0x1ca5a0 ldr r3, [pc, #0x120] */
/* @0x1ca5a4 strb r8, [sp, #0x40] */
/* @0x1ca5a8 add r3, pc, r3 */
/* @0x1ca5ac strb r6, [sp, #0x41] */
/* @0x1ca5b0 str r7, [sp, #0x44] */
/* @0x1ca5b4 str r4, [r3] */
/* @0x1ca5b8 vcvt.f64.f32 d7, s18 */
/* @0x1ca5bc vstr d6, [sp, #32] */
/* @0x1ca5c0 vstr d7, [sp, #40] */
/* @0x1ca5c4 vcvt.f64.f32 d6, s16 */
/* @0x1ca5c8 vcvt.f64.f32 d7, s19 */
/* @0x1ca5cc vstr d6, [sp, #48] */
/* ── 2.10 快路 B：lo/hi 两角 = (int) 截断后的 min/max（0x1ca5d0..0x1ca63c） ──────────────────────────────────
 * 1ca5d0 vcmpe s17,s16（x1 vs x2）+ 1ca5dc bpl 1ca6ac：x1 >= x2 时先去 2.13 取 (int)x2 当 lo.x，
 * 否则 1ca5e0 vcvt.s32.f32 s15,s17 → 1ca5f0 str 到 [sp,#0x10]（= lo.x）。
 * 1ca5e8 vcmpe s18,s19（y1 vs y2）→ 1ca610 vcvtmi / 1ca614 vcvtpl 两条**条件转换**合成 min → [sp,#0x14] = lo.y。
 * 1ca608 vcmpe s17,s16 → 1ca624 vcvtgt s16,s17 / 1ca628 vcvtle s16,s16 合成 max → [sp,#0x18] = hi.x。
 * 1ca61c vcmpe s18,s19 → 1ca630 vcvtgt s18,s18 / 1ca638 vcvtle s18,s19 合成 max → [sp,#0x1c] = hi.y。
 * ⇒ 两角都是 vcvt.s32.f32 的**向零截断**整数，与回调里 double 的精确矩形不是同一组数（见 open）。
 * 1ca5ec 先取 g_tree（0x3ee24c），1ca640/1ca648 取 *g_tree 当 this。
 */
/* @0x1ca5d0 vcmpe.f32 s17, s16 */
/* @0x1ca5d4 vstr d7, [sp, #56] */
/* @0x1ca5d8 vmrs APSR_nzcv, fpscr */
/* @0x1ca5dc bpl 0x1ca6ac <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x35c> */
/* @0x1ca5e0 vcvt.s32.f32 s15, s17 */
/* @0x1ca5e4 vmov r3, s15 */
/* @0x1ca5e8 vcmpe.f32 s18, s19 */
/* @0x1ca5ec ldr r0, [pc, #0xd8] */
/* @0x1ca5f0 str r3, [sp, #0x10] */
/* @0x1ca5f4 add r12, sp, #32 */
/* @0x1ca5f8 ldr r3, [pc, #0xd0] */
/* @0x1ca5fc add r1, sp, #16 */
/* @0x1ca600 add r2, sp, #24 */
/* @0x1ca604 vmrs APSR_nzcv, fpscr */
/* @0x1ca608 vcmpe.f32 s17, s16 */
/* @0x1ca60c add r3, pc, r3 */
/* @0x1ca610 vcvtmi.s32.f32 s15, s18 */
/* @0x1ca614 vcvtpl.s32.f32 s15, s19 */
/* @0x1ca618 vmrs APSR_nzcv, fpscr */
/* @0x1ca61c vcmpe.f32 s18, s19 */
/* @0x1ca620 vstr s15, [sp, #20] */
/* @0x1ca624 vcvtgt.s32.f32 s16, s17 */
/* @0x1ca628 vcvtle.s32.f32 s16, s16 */
/* @0x1ca62c vmrs APSR_nzcv, fpscr */
/* @0x1ca630 vcvtgt.s32.f32 s18, s18 */
/* @0x1ca634 vstr s16, [sp, #24] */
/* @0x1ca638 vcvtle.s32.f32 s18, s19 */
/* @0x1ca63c vstr s18, [sp, #28] */
/* ── 2.11 快路 C：Search 的实参与结果回读（0x1ca640..0x1ca654） ────────────────────────────────────────────────
 * r0 = *g_tree（1ca640 取指针、1ca648 解一次）；r1 = sp+16（lo 的地址，两个 int）；
 * r2 = sp+24（hi）；r3 = 0x1c83c0（回调，1ca5f8 池字 + 1ca60c add pc）；[sp] = &ctx（sp+32，1ca644）。
 * 1ca64c bl 0x10d720 RTree::Search；1ca650 ldr r5,[r10] 从 s_instancePtr 读命中实例；1ca654 → 1ca44c。
 * ⇒ 树查询只带盒子，对象过滤与精确矩形都在回调 0x1c83c0 里（跨卡）；Search 内部把 lo/hi 原样塞进
 * Rect{+0x10..+0x1c} 再递归（0x10d720 实测：ldm r12,{r4,r12} 取 hi 两字、str 到 sp+0x10..0x1c）。
 */
/* @0x1ca640 ldr r0, [r9, r0] */
/* @0x1ca644 str r12, [sp] */
/* @0x1ca648 ldr r0, [r0] */
/* @0x1ca64c bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_> */
/* @0x1ca650 ldr r5, [r10] */
/* @0x1ca654 b 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* ── 2.12 自备对象表查找（objptr==0 时；0x1ca658..0x1ca6a8） ─────────────────────────────────────────────────
 * 槽 0x3edc44 → 0x542374 = g_ObjectHash，**再解引用一次**（1ca660 ldr r3,[r3]）才得对象本体；
 * 与 id 表（0x536f28 直接是本体）差一层间接。布局同 id 表：掩码 +0x4、桶表 +0x0、节点 {next@+0x4,
 * key@+0x8, value@+0xc}。查到后 1ca69c/1ca6a0 把 value 写回 [sp,#0xc]（复用 objptr 槽），
 * 1ca6a4 跳回 1ca3d0 走 2.4 的链；查不到 1ca6a8 返回 0。
 */
/* @0x1ca658 ldr r3, [pc, #0x74] */
/* @0x1ca65c ldr r3, [r9, r3] */
/* @0x1ca660 ldr r3, [r3] */
/* @0x1ca664 ldr r2, [r3, #0x4] */
/* @0x1ca668 ldr r3, [r3] */
/* @0x1ca66c and r2, r4, r2 */
/* @0x1ca670 ldr r3, [r3, r2, lsl #3] */
/* @0x1ca674 cmp r3, #0 */
/* @0x1ca678 bne 0x1ca68c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x33c> */
/* @0x1ca67c b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca680 ldr r3, [r3, #0x4] */
/* @0x1ca684 cmp r3, #0 */
/* @0x1ca688 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca68c ldr r2, [r3, #0x8] */
/* @0x1ca690 cmp r4, r2 */
/* @0x1ca694 bne 0x1ca680 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x330> */
/* @0x1ca698 ldr r3, [r3, #0xc] */
/* @0x1ca69c cmp r3, #0 */
/* @0x1ca6a0 str r3, [sp, #0xc] */
/* @0x1ca6a4 bne 0x1ca3d0 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x80> */
/* @0x1ca6a8 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* ── 2.13 x 方向的交换支（0x1ca6ac..0x1ca6b4） ────────────────────────────────────────────────────────────
 * x1 >= x2 时才走：1ca6ac vcvt.s32.f32 s15,s16（x2）→ 1ca6b0 vmov r3,s15 → 1ca6b4 b 1ca5e8，
 * 回到 2.10 的 y 比较处，于是 lo.x 取到 (int)x2。⇒ min 是在两支里各算一半，不是 cmov 一条。
 */
/* @0x1ca6ac vcvt.s32.f32 s15, s16 */
/* @0x1ca6b0 vmov r3, s15 */
/* @0x1ca6b4 b 0x1ca5e8 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x298> */
/* ── 2.14 池字 8 个（0x1ca6b8..0x1ca6d4，非指令） ──────────────────────────────────────────────────────────
 * 1ca6b8 0x002278b8 → 1ca3a0+0x2278b8 = 0x3f1c58（PIC 锚）
 * 1ca6bc 0xffffbff4 → 0x3edc4c（id 表槽，用于 2.6 的 1ca468）
 * 1ca6c0 0xffffbcd8 → 0x3ed930（Run_Room 槽，用于 2.7 的 1ca4f0）
 * 1ca6c4 0xffffeeb8 → 0x3f0b10（&s_instancePtr 槽，用于 2.9 的 1ca584）
 * 1ca6c8 0x0022ab38 → 1ca5ac+0x22ab38 = 0x3f50e4（目标 obj 槽，2.9 的 1ca5b4）
 * 1ca6cc 0xffffc5f4 → 0x3ee24c（g_tree 槽，2.10/2.11）
 * 1ca6d0 0xffffddac → 1ca614-0x2254 = 0x1c83c0（回调地址）
 * 1ca6d4 0xffffbfec → 0x3edc44（g_ObjectHash 槽，2.12 的 1ca65c）
 */
/* @0x1ca6b8 .word 0x002278b8 */
/* @0x1ca6bc .word 0xffffbff4 */
/* @0x1ca6c0 .word 0xffffbcd8 */
/* @0x1ca6c4 .word 0xffffeeb8 */
/* ↑ 非指令：池字 0x0022ab38（1ca5a8 的 add r3,pc,r3 → 0x3f50e4 目标 obj 槽），objdump 误译为 eoreq */
/* @0x1ca6c8 eoreq r10, r2, r8, lsr r11 */
/* @0x1ca6cc .word 0xffffc5f4 */
/* @0x1ca6d0 .word 0xffffddac */
/* @0x1ca6d4 .word 0xffffbfec */

/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 3 · Command_InstancePlace（place_meeting 的命令层）
 * @func 0x1ca6d8 0x1ca9f8  size 800  200 锚点（192 条指令 + 8 个池字 0x1ca9d8..0x1ca9f4）
 * 符号: _Z21Command_InstancePlaceP9CInstanceffi
 *       → CInstance* Command_InstancePlace(CInstance* inst, float x, float y, int obj)
 * 位置: index 第 3 组。后一条指令 0x1ca9fc 起是 Command_IsMeeting（不属本卡）
 * 调用者: 全 .text 精确 2 处 bl、无 b 尾跳 ——
 *     F_InstancePlace 0x109518 的 0x109564（instance_place 内建，直接拿返回的实例指针）
 *     Command_IsMeeting 0x1ca9f8 的 0x1caa0c（place_meeting 走这条：重排 (inst,obj,x,y)→(inst,x,y,obj)，
 *       再把指针归一成 1/0 —— 0x1caa10 adds / 0x1caa14 movne #1）
 * 同层: RTree::Search 0x10d720、UpdateTree 0x1cc24c、CInstance::SetPosition 0x193e7c、
 *       CInstance::Compute_BoundingBox 0x192340、CInstance::Collision_Instance 0x195558、回调 0x1c8648
 * 一句话: 把实例**临时搬**到 (x,y)（旧坐标先存寄存器），拿它的 bbox 去撞 obj 指定的实例集合；
 *         命中返回该实例，然后无条件搬回原处。obj==-3 扫房间链、>99999 查 id 表、对象号走 obj->[0xd0] 链。
 * ═══════════════════════════════════════════════════════════════════════════
 */

/* ── 语义草案 ─────────────────────────────────────────────────────────────
 *   CInstance* Command_InstancePlace(CInstance* inst, float x, float y, int obj) {
 *     CObjectGM* o = NULL;
 *     int g = ShouldUseFastCollision(obj, &o);            // 1ca704
 *     if (g == -1) return NULL;                           // 1ca710 → 1ca9d0（**不搬**）
 *     float ox = inst->[0xb4], oy = inst->[0xb8];         // 1ca72c/1ca730（慢路）
 *     if (g == 1) {                                       // 1ca718 → 1ca820
 *        UpdateTree();                                    // 1ca820
 *        ox = inst->[0xb4]; oy = inst->[0xb8];            // 1ca830/1ca834（读在 bl 之前）
 *        SetPosition(inst, x, y);                         // 1ca838
 *        if (inst->[0x64]) Compute_BoundingBox(inst, false);   // 1ca83c → 1ca944（不碰树）
 *        int lo[2] = { min(left,right), min(top,bottom) };     // 1ca868..1ca898
 *        int hi[2] = { max(left,right), max(top,bottom) };
 *        g_objPlace = obj;                                // 1ca8a8 → 0x3f50e8
 *        s_instancePtr = NULL;                            // 1ca8ac
 *        RTree::Search(*g_tree, lo, hi, 0x1c8648, inst);  // 1ca8c4（ctx = 实例指针，不是结构体）
 *        SetPosition(inst, ox, oy);                       // 1ca8c8..1ca8d4
 *        return s_instancePtr;                            // 1ca8d8
 *     }
 *     SetPosition(inst, x, y);                            // 1ca734（慢路：先搬再测）
 *     if (obj == -3) {                                    // 1ca738 → 1ca8e4
 *        for (p = Run_Room->[0x80]; p; p = p->[0x178])
 *           if (!p->[0x68] && !p->[0x69] && p->Collision_Instance(inst, true)) { 复位; return p; }
 *     } else if (obj > 99999) {                           // 1ca740..1ca74c → 1ca954
 *        CInstance* p = IdMap.find(obj);
 *        if (p && !p->[0x68] && !p->[0x69] && p->Collision_Instance(inst,true)) { 复位; return p; }
 *     } else {                                            // 1ca750
 *        if (!o) o = ObjMap.find(obj);                    // 1ca758 → 1ca7c8
 *        for (n = o->[0xd0]; n; n = n->[0x0]) { ...n->[0x8]->Collision_Instance(inst,true)... }
 *     }
 *     SetPosition(inst, ox, oy); return NULL;             // 1ca818 → 1ca7ac
 *   }
 *
 * ── 门表（按执行顺序）────────────────────────────────────────────────────
 *   ① g：-1 / 1 / 2                                        1ca710..1ca71c
 *   ② obj == -3                                            1ca738..1ca73c
 *   ③ obj > 0x1869F                                        1ca740..1ca74c
 *   ④ o == 0 → 自备查表                                     1ca750..1ca758 / 1ca7c8
 *   ⑤ 节点 / 候选非空                                       1ca75c..1ca770
 *   ⑥ +0x68 != 0 → 跳过                                    1ca77c..1ca784
 *   ⑦ +0x69 != 0 → 跳过                                    1ca788..1ca790
 *   ⑧ Collision_Instance 非 0 → 复位 + 返回                 1ca7a4..1ca7ac
 *   快路侧：ⓐ +0x64 脏 → Compute_BoundingBox(inst,0)        1ca83c..1ca844
 *          ⓑ 回调 0x1c8648：cand == ctx(=inst) → 跳过（**无条件**），再 +0x68/+0x69/+0x48!=1 三道闸（跨卡）
 *   ⇒ 本函数**没有 notme / precise 门**（参数里就没有）；「排除自己」只存在于快路回调里，慢路没有。
 *
 * ── 字段表 ───────────────────────────────────────────────────────────────
 *   CInstance：+0x64 bbox 脏位（1ca83c）  +0x68/+0x69 闸  +0x78 id（id 路匹配）
 *              +0xb4 x / +0xb8 y（float，搬动与复位都靠它）  +0xe8/+0xec/+0xf0/+0xf4 bbox int
 *              +0x178 prev（房间链）  +0xd0 经 CObjectGM（节点链）
 *   CObjectGM：+0xd0 节点链头 {next@+0x0, inst@+0x8}
 *   全局：s_instancePtr 0x5428b8、0x3f50e8（目标 obj，**与另两节不同槽**）、g_tree、g_ObjectHash、Run_Room、id 表
 *   写集：两个全局 + 实例的 x/y（搬去再搬回）+ 隐式脏位/脏表（经 SetPosition）⇒ 本命令**会**留下
 *         「+0x64 被置 1、实例进了 s_dirty_list」的痕迹，虽然位置看起来没变。
 *
 * ── 已证（指令级）───────────────────────────────────────────────────────
 *  1. 帧 64 B、四个实参（r6=inst、r7=x、r8=y、r5=obj），**无栈实参** ⇒ 与 place_meeting(x,y,obj) 三个
 *     参数一一对应，没有 precise/notme（1ca6d8..1ca700）。
 *  2. 三条出口的副作用不同：-1 → 1ca9d0 → 1ca7c0（**不搬、不复位**）；慢路 1ca734 先搬、所有出口经
 *     1ca7ac 复位；快路 1ca838 搬、1ca8c8..1ca8d4 复位。唯一「搬走不回」的路径不存在。
 *  3. 旧坐标的取法：慢路 1ca72c/1ca730、快路 1ca830/1ca834 都在 SetPosition 的 bl **之前**读
 *     inst+0xb4/+0xb8 ⇒ 拿到的是旧值（这两处是复位正确性的唯一依据）。
 *  4. bbox 链：SetPosition 0x193e7c 实测「坐标变了才写 +0xb4/+0xb8、strb #1 到 +0x64、尾跳
 *     CollisionMarkDirty 0x1cc1d0」⇒ 搬动后 +0x64 必为 1（除坐标未变），快路因此必走 3.11 重算；
 *     重算用 Compute_BoundingBox(inst, **0**) = updateRTree false ⇒ **不动树**。
 *  5. 快路 ctx 就是实例指针本身（1ca8b8 str r6,[sp]），回调 0x1c8648 头两条 cmp r1,r0 / beq 即「跳过自己」；
 *     与 Line/Rect 的 0x28 字节结构体上下文完全不同 ⇒ 同一个 RTree::Search 被两种回调复用。
 *  6. 目标 obj 写 0x3f50e8（1ca8a0/1ca89c/1ca8a8），与 Line/Rect 的 0x3f50e4 相邻但**不同槽**
 *     （两处 .data 初值都是 -1，实测）。
 *  7. 三条慢路都是「先搬再测」：-3 扫 room->[0x80] 沿 +0x178、id 表单点、对象链 {next@0x0,inst@0x8}；
 *     三处都没 notme/self 判断（1ca77c、1ca8fc、1ca99c 三组闸只有 0x68/0x69）。
 *  8. 返回值：命中 = 候选指针、没命中 = 0；快路从 s_instancePtr 读（1ca8d8），慢路用 r4 带回来（1ca7bc）。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *  · 慢路**不排除候选 == inst**，而快路回调**无条件排除** ⇒ obj 含自己时两路可能给出不同结果
 *    （快路必不返回自己，慢路可能返回自己）。这是本卡能证实的**行为差**；哪一路符合原版 GML 语义未证。
 *  · RTree::Search 0x10d720 / 0x10d558 与回调 0x1c8648 内部（对象匹配、+0x48==1 闸、最后命中者胜）未落锚点。
 *  · Collision_Instance 0x195558 的第三实参恒 1（1ca794 / 1ca91c / 1ca9bc 三处都是 mov r2,#1），
 *    语义名（precise？solid？）未证。
 *  · +0x48 的含义（回调要求 ==1）未证。
 *  · 快路盒是「搬动后重算」的盒：若坐标与旧值完全相同（SetPosition 提前返回、+0x64 不置位）则不重算，
 *    此时盒仍是当前值，逻辑自洽；但「帧内别处把实例挪了却没更新盒」的组合不在本卡范围。
 *  · Command_IsMeeting 0x1ca9f8 只证到「重排实参 + 归一 1/0」（0x1ca9f8..0x1caa18），不属本索引。
 */
/* ── 3.1 入口：帧 64 B、四个实参、objptr 局部清 0（0x1ca6d8..0x1ca704） ──────────────────────────────────────────
 * push 8 寄存器(32) + sub 32 = 64，**没有栈实参**（只有 4 个参数）⇒ 帧里全是局部。
 * r6=inst、r7=x([r1])、r8=y([r2])、r5=obj([r3])；1ca6e4/1ca6f8 把 sp+12 清 0 当出参槽。
 * ⇒ 与 place_meeting(x,y,obj) 的三个实参一一对应，**没有 precise/notme**：所以本函数没有 Line/Rect
 * 那种「notme && obj == inst->[0x78]」前置短路；与之一致的是它的回调无条件跳过 ctx（见 3.9）。
 */
/* @0x1ca6d8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ca6dc sub sp, sp, #32 */
/* @0x1ca6e0 mov r5, r3 */
/* @0x1ca6e4 add r3, sp, #32 */
/* @0x1ca6e8 mov r6, r0 */
/* @0x1ca6ec mov r7, r1 */
/* @0x1ca6f0 mov r4, #0 */
/* @0x1ca6f4 mov r0, r5 */
/* @0x1ca6f8 str r4, [r3, #-0x14]! */
/* @0x1ca6fc mov r1, r3 */
/* @0x1ca700 mov r8, r2 */
/* ── 3.2 判决：三值分流（0x1ca704..0x1ca720） ──────────────────────────────────────────────────────────────
 * 1ca708/1ca70c：ldr r9,[pc,#0x2c8]（池字 1ca9d8=0x00227544）+ add r9,pc,r9（PC=1ca714）
 * ⇒ r9 = 0x3f1c58（同一个 PIC 锚）。
 * cmn r0,#1 → -1 → 1ca9d0（返回 0，**连位置都不动**）；cmp r0,#1 → 1 → 1ca820（快路）；其余 → 1ca720（慢路）。
 * ⚠ 慢路会先把实例搬走再测（3.3），所以「-1 立即返回」这条是唯一不产生任何副作用的出口 —— 也正是
 * 「目标对象不存在」时 place_meeting 不该动实例的地方。
 */
/* @0x1ca704 bl 0x1c8df8 <_Z22ShouldUseFastCollisioniPP9CObjectGM> */
/* @0x1ca708 ldr r9, [pc, #0x2c8] */
/* @0x1ca70c add r9, pc, r9 */
/* @0x1ca710 cmn r0, #1 */
/* @0x1ca714 beq 0x1ca9d0 <_Z21Command_InstancePlaceP9CInstanceffi+0x2f8> */
/* @0x1ca718 cmp r0, #1 */
/* @0x1ca71c beq 0x1ca820 <_Z21Command_InstancePlaceP9CInstanceffi+0x148> */
/* ── 3.3 慢路：先搬再测，旧坐标先存寄存器（0x1ca720..0x1ca738） ─────────────────────────────────────────────────────
 * 1ca720..1ca72c 先把 r1/r2 设成 (x,y)、**再**用 1ca72c/1ca730 从 inst+0xb4/+0xb8 读旧坐标进 r7/r8
 * （读在 SetPosition 之前 ⇒ 拿到的是旧值），1ca734 bl SetPosition。
 * SetPosition 0x193e7c 实测：坐标真变了才写 +0xb4/+0xb8、置 +0x64=1、尾跳 CollisionMarkDirty
 * ⇒ 搬动之后实例的 bbox 一定是脏的（除非坐标没变）。
 * ⇒ 这就是 place_meeting 的实现方式：把实例临时搬过去测，1ca7ac 再搬回来。
 */
/* @0x1ca720 mov r1, r7 */
/* @0x1ca724 mov r2, r8 */
/* @0x1ca728 mov r0, r6 */
/* @0x1ca72c ldr r7, [r6, #0xb4] */
/* @0x1ca730 ldr r8, [r6, #0xb8] */
/* @0x1ca734 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* ── 3.4 慢路分流：-3 / >0x1869F / 对象号（0x1ca738..0x1ca750） ─────────────────────────────────────────────
 * cmn r5,#3 → -3 → 1ca8e4（房间活动链，option 关时才可达）；movw/movt 0x1869f + bgt → 1ca954（id 表）；
 * 否则 1ca750 看 objptr(=sp+12)：为空 → 1ca7c8 自备查对象表。
 */
/* @0x1ca738 cmn r5, #3 */
/* @0x1ca73c beq 0x1ca8e4 <_Z21Command_InstancePlaceP9CInstanceffi+0x20c> */
/* @0x1ca740 movw r3, #0x869f */
/* @0x1ca744 movt r3, #0x1 */
/* @0x1ca748 cmp r5, r3 */
/* @0x1ca74c bgt 0x1ca954 <_Z21Command_InstancePlaceP9CInstanceffi+0x27c> */
/* ── 3.5 对象号慢路：obj->[0xd0] 的实例节点链（0x1ca750..0x1ca7c8） ─────────────────────────────────────────────
 * 1ca75c r5 = objptr->[0xd0]；1ca768 判 node->[0x8] 非空；1ca774 r4 = node->[0x8] 当候选、1ca778 r5 = node->[0x0] 当 next。
 * 1ca77c/1ca788 两道 0x68/0x69 闸 —— **没有 notme 判断**（没有这个参数，也没法判 self，见 open）。
 * 1ca794/1ca798/1ca79c：r2=1（第三实参恒 1）、r0=候选、r1=inst，bl Collision_Instance 0x195558。
 * 1ca7a4 beq 回 1ca760 续；命中落到 1ca7ac 复位并返回 r4。
 * ⚠ 与快路回调（无条件跳过 inst）不同，这条慢路**不排除候选 == inst** ⇒ 若 obj 包含自己，慢路可能返回
 * 自己、快路不会。两路行为在此不等价，列 open。
 */
/* @0x1ca750 ldr r3, [sp, #0xc] */
/* @0x1ca754 cmp r3, #0 */
/* @0x1ca758 beq 0x1ca7c8 <_Z21Command_InstancePlaceP9CInstanceffi+0xf0> */
/* @0x1ca75c ldr r5, [r3, #0xd0] */
/* @0x1ca760 cmp r5, #0 */
/* @0x1ca764 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca768 ldr r3, [r5, #0x8] */
/* @0x1ca76c cmp r3, #0 */
/* @0x1ca770 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca774 ldr r4, [r5, #0x8] */
/* @0x1ca778 ldr r5, [r5] */
/* @0x1ca77c ldrb r3, [r4, #0x68] */
/* @0x1ca780 cmp r3, #0 */
/* @0x1ca784 bne 0x1ca760 <_Z21Command_InstancePlaceP9CInstanceffi+0x88> */
/* @0x1ca788 ldrb r3, [r4, #0x69] */
/* @0x1ca78c cmp r3, #0 */
/* @0x1ca790 bne 0x1ca760 <_Z21Command_InstancePlaceP9CInstanceffi+0x88> */
/* @0x1ca794 mov r2, #1 */
/* @0x1ca798 mov r0, r4 */
/* @0x1ca79c mov r1, r6 */
/* @0x1ca7a0 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1ca7a4 cmp r0, #0 */
/* @0x1ca7a8 beq 0x1ca760 <_Z21Command_InstancePlaceP9CInstanceffi+0x88> */
/* ── 3.6 复位出口：先 SetPosition(旧x,旧y) 再返回（0x1ca7ac..0x1ca7c4） ────────────────────────────────────────
 * 1ca7ac..1ca7b8：r0=inst、r1=r7（旧 x）、r2=r8（旧 y），bl SetPosition ⇒ 位置复位。
 * 1ca7bc mov r0,r4 —— 返回候选（命中）或 0（1ca818 把 r4 置 0 后也跳到这）。
 * ⇒ 三条慢路的所有出口都经过这里：命中/没命中都会复位位置，没有「搬走不回」的路径。
 */
/* @0x1ca7ac mov r0, r6 */
/* @0x1ca7b0 mov r1, r7 */
/* @0x1ca7b4 mov r2, r8 */
/* @0x1ca7b8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1ca7bc mov r0, r4 */
/* @0x1ca7c0 add sp, sp, #32 */
/* @0x1ca7c4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ── 3.7 自备对象表查找（objptr==0 时；0x1ca7c8..0x1ca814） ──────────────────────────────────────────────────
 * 槽 0x3edc44 → 0x542374（g_ObjectHash），**再解引用一次**（1ca7d0）得对象本体；掩码 +0x4、桶表 +0x0、
 * 桶步长 8、节点 {+0x4 next, +0x8 key, +0xc value}。查到后 1ca80c/1ca810 写回 [sp,#0xc]，
 * 1ca814 跳回 1ca75c 走 3.5 的链；查不到 1ca818（r4=0）→ 3.6 复位返回 0。
 */
/* @0x1ca7c8 ldr r3, [pc, #0x20c] */
/* @0x1ca7cc ldr r3, [r9, r3] */
/* @0x1ca7d0 ldr r3, [r3] */
/* @0x1ca7d4 ldr r2, [r3, #0x4] */
/* @0x1ca7d8 ldr r3, [r3] */
/* @0x1ca7dc and r2, r5, r2 */
/* @0x1ca7e0 ldr r3, [r3, r2, lsl #3] */
/* @0x1ca7e4 cmp r3, #0 */
/* @0x1ca7e8 bne 0x1ca7fc <_Z21Command_InstancePlaceP9CInstanceffi+0x124> */
/* @0x1ca7ec b 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca7f0 ldr r3, [r3, #0x4] */
/* @0x1ca7f4 cmp r3, #0 */
/* @0x1ca7f8 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca7fc ldr r2, [r3, #0x8] */
/* @0x1ca800 cmp r5, r2 */
/* @0x1ca804 bne 0x1ca7f0 <_Z21Command_InstancePlaceP9CInstanceffi+0x118> */
/* @0x1ca808 ldr r3, [r3, #0xc] */
/* @0x1ca80c cmp r3, #0 */
/* @0x1ca810 str r3, [sp, #0xc] */
/* @0x1ca814 bne 0x1ca75c <_Z21Command_InstancePlaceP9CInstanceffi+0x84> */
/* @0x1ca818 mov r4, #0 */
/* @0x1ca81c b 0x1ca7ac <_Z21Command_InstancePlaceP9CInstanceffi+0xd4> */
/* ── 3.8 快路 A：UpdateTree → 搬 → 脏位 → 重算 bbox（0x1ca820..1ca848） ─────────────────────────────────────
 * 1ca820 bl UpdateTree()。1ca824..1ca838：**先**从 inst+0xb4/+0xb8 读旧坐标进 r8/r7，再 SetPosition(x,y)。
 * 1ca83c ldrb r3,[r6,#0x64]（bbox 脏位）；1ca840 cmp r3,r4(=0) / bne 1ca944 ⇒ 脏就 3.11 重算 bbox。
 * 注意 3.11 调的是 Compute_BoundingBox(inst, **false**)：只重算 +0xe8..+0xf4 并清 +0x64，**不动 RTree**
 * （该卡：第二实参 updateRTree，为 0 就跳过 CollisionUpdate）。这正是临时位置该有的行为 ——
 * 否则每次 place_meeting 都会把树改一遍。
 */
/* @0x1ca820 bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1ca824 mov r1, r7 */
/* @0x1ca828 mov r2, r8 */
/* @0x1ca82c mov r0, r6 */
/* @0x1ca830 ldr r8, [r6, #0xb4] */
/* @0x1ca834 ldr r7, [r6, #0xb8] */
/* @0x1ca838 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1ca83c ldrb r3, [r6, #0x64] */
/* @0x1ca840 cmp r3, r4 */
/* @0x1ca844 bne 0x1ca944 <_Z21Command_InstancePlaceP9CInstanceffi+0x26c> */
/* ── 3.9 快路 B：两角 = 实例自身 bbox 的 min/max，Search 后复位并读结果（0x1ca848..0x1ca8e0） ─────────────────────────
 * 1ca848..1ca860 取 +0xec(top)、+0xf4(bottom)、+0xe8(left)、+0xf0(right) 四个 int。
 * 1ca868..1ca87c：cmp + strle/strgt 组 lo.y、strge/strlt 组 hi.y（min/max 各两条条件 str）；
 * 1ca884..1ca898 同构组 lo.x / hi.x ⇒ lo=sp+16、hi=sp+24，全部是 int（bbox 本来就是 int）。
 * 1ca880/1ca89c/1ca8a8：目标 obj 写全局 **0x3f50e8**（池字 1ca9e4 取加数、add pc 算地址、str 落地；
 *   与 Line/Rect 的 0x3f50e4 **不同槽**）。
 * 1ca8a0/1ca8ac：r4 = &s_instancePtr（1ca864 取槽 0x3f0b10 的偏移、1ca8a0 解出 0x5428b8），str r10(=0) 清结果槽。
 * 1ca8b0..1ca8c4：r0 = *g_tree、r3 = 0x1c8648（回调，1ca8b4 池字 + 1ca8bc add pc）、[sp] = inst（ctx **就是实例指针**，
 * 不是结构体）→ bl RTree::Search。
 * 1ca8c8..1ca8d4 复位 SetPosition(旧x,旧y)；1ca8d8 ldr r0,[r4] 从 s_instancePtr 读结果并返回。
 * ⇒ 快路的 ctx = CInstance*（回调据此跳过自己），与 Line/Rect 的 0x28 字节上下文完全不同 —— 同一个
 * Search 接口被两种回调复用。
 */
/* @0x1ca848 ldr r3, [r6, #0xec] */
/* @0x1ca84c mov r10, #0 */
/* @0x1ca850 ldr r0, [r6, #0xf4] */
/* @0x1ca854 add r1, sp, #16 */
/* @0x1ca858 ldr r12, [r6, #0xe8] */
/* @0x1ca85c add r2, sp, #24 */
/* @0x1ca860 ldr lr, [r6, #0xf0] */
/* @0x1ca864 ldr r4, [pc, #0x174] */
/* @0x1ca868 cmp r0, r3 */
/* @0x1ca86c strle r0, [sp, #0x14] */
/* @0x1ca870 strgt r3, [sp, #0x14] */
/* @0x1ca874 cmp r0, r3 */
/* @0x1ca878 strge r0, [sp, #0x1c] */
/* @0x1ca87c strlt r3, [sp, #0x1c] */
/* @0x1ca880 ldr r0, [pc, #0x15c] */
/* @0x1ca884 cmp lr, r12 */
/* @0x1ca888 strle lr, [sp, #0x10] */
/* @0x1ca88c strgt r12, [sp, #0x10] */
/* @0x1ca890 cmp lr, r12 */
/* @0x1ca894 strge lr, [sp, #0x18] */
/* @0x1ca898 strlt r12, [sp, #0x18] */
/* @0x1ca89c add r0, pc, r0 */
/* @0x1ca8a0 ldr r4, [r9, r4] */
/* @0x1ca8a4 ldr r3, [pc, #0x13c] */
/* @0x1ca8a8 str r5, [r0] */
/* @0x1ca8ac str r10, [r4] */
/* @0x1ca8b0 ldr r0, [r9, r3] */
/* @0x1ca8b4 ldr r3, [pc, #0x130] */
/* @0x1ca8b8 str r6, [sp] */
/* @0x1ca8bc add r3, pc, r3 */
/* @0x1ca8c0 ldr r0, [r0] */
/* @0x1ca8c4 bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_> */
/* @0x1ca8c8 mov r0, r6 */
/* @0x1ca8cc mov r1, r8 */
/* @0x1ca8d0 mov r2, r7 */
/* @0x1ca8d4 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1ca8d8 ldr r0, [r4] */
/* @0x1ca8dc add sp, sp, #32 */
/* @0x1ca8e0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ── 3.10 obj == -3 慢路：房间活动链（0x1ca8e4..1ca940） ────────────────────────────────────────────────────
 * 槽 0x3ed930 → 0x54298c → *(Run_Room) → room->[0x80]（A 链尾），沿 +0x178(prev) 走。
 * 1ca8fc/1ca90c 两道 0x68/0x69 闸（无 notme）；1ca918..1ca924 组 Collision_Instance(候选, inst, 1)。
 * 1ca92c 命中 → 1ca7ac 复位返回；1ca930/1ca934/1ca938 前移游标；走完 1ca93c/1ca940（r4=0）→ 复位返回 0。
 */
/* @0x1ca8e4 ldr r3, [pc, #0x104] */
/* @0x1ca8e8 ldr r3, [r9, r3] */
/* @0x1ca8ec ldr r3, [r3] */
/* @0x1ca8f0 ldr r4, [r3, #0x80] */
/* @0x1ca8f4 cmp r4, #0 */
/* @0x1ca8f8 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca8fc ldrb r3, [r4, #0x68] */
/* @0x1ca900 ldr r5, [r4, #0x178] */
/* @0x1ca904 cmp r3, #0 */
/* @0x1ca908 bne 0x1ca930 <_Z21Command_InstancePlaceP9CInstanceffi+0x258> */
/* @0x1ca90c ldrb r3, [r4, #0x69] */
/* @0x1ca910 cmp r3, #0 */
/* @0x1ca914 bne 0x1ca930 <_Z21Command_InstancePlaceP9CInstanceffi+0x258> */
/* @0x1ca918 mov r2, #1 */
/* @0x1ca91c mov r0, r4 */
/* @0x1ca920 mov r1, r6 */
/* @0x1ca924 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1ca928 cmp r0, #0 */
/* @0x1ca92c bne 0x1ca7ac <_Z21Command_InstancePlaceP9CInstanceffi+0xd4> */
/* @0x1ca930 cmp r5, #0 */
/* @0x1ca934 mov r4, r5 */
/* @0x1ca938 bne 0x1ca8fc <_Z21Command_InstancePlaceP9CInstanceffi+0x224> */
/* @0x1ca93c mov r4, #0 */
/* @0x1ca940 b 0x1ca7ac <_Z21Command_InstancePlaceP9CInstanceffi+0xd4> */
/* ── 3.11 bbox 重算支（0x1ca944..1ca950） ──────────────────────────────────────────────────────────────
 * 1ca944 mov r1,r4（r4 = 0）、1ca948 mov r0,r6 → bl Compute_BoundingBox 0x192340；1ca950 回 1ca848。
 * ⇒ 第二实参 0 = updateRTree=false：只重算盒、清脏位，不碰树（与 3.8 的说明互证）。
 * 若 +0x64 本来就不脏（坐标没变，SetPosition 提前返回），走不到这里 —— 盒仍是当前值，逻辑自洽。
 */
/* @0x1ca944 mov r1, r4 */
/* @0x1ca948 mov r0, r6 */
/* @0x1ca94c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1ca950 b 0x1ca848 <_Z21Command_InstancePlaceP9CInstanceffi+0x170> */
/* ── 3.12 实例 id 慢路（0x1ca954..1ca9cc） ──────────────────────────────────────────────────────────────
 * 槽 0x3edc4c → 0x536f28（本体）：掩码 +0x4、桶表 +0x0、节点 {next@+0x4, key@+0x8, value@+0xc}；
 * key 比实例 id（1ca988），1ca990 取 value 当候选。
 * 1ca994 空 → 1ca818（r4=0）复位返回；1ca99c/1ca9a8 两道 0x68/0x69 闸；1ca9b4..1ca9c0 窄相；
 * 命中 1ca9c8 → 1ca7ac 复位返回候选；否则 1ca9cc → 1ca818 返回 0。
 * ⚠ 这里也**没有** notme/self 判断（place_meeting 没有该参数，语义上是「包括自己」）。
 */
/* @0x1ca954 ldr r3, [pc, #0x98] */
/* @0x1ca958 ldr r3, [r9, r3] */
/* @0x1ca95c ldr r2, [r3, #0x4] */
/* @0x1ca960 ldr r3, [r3] */
/* @0x1ca964 and r2, r5, r2 */
/* @0x1ca968 ldr r2, [r3, r2, lsl #3] */
/* @0x1ca96c cmp r2, #0 */
/* @0x1ca970 bne 0x1ca984 <_Z21Command_InstancePlaceP9CInstanceffi+0x2ac> */
/* @0x1ca974 b 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca978 ldr r2, [r2, #0x4] */
/* @0x1ca97c cmp r2, #0 */
/* @0x1ca980 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca984 ldr r3, [r2, #0x8] */
/* @0x1ca988 cmp r5, r3 */
/* @0x1ca98c bne 0x1ca978 <_Z21Command_InstancePlaceP9CInstanceffi+0x2a0> */
/* @0x1ca990 ldr r4, [r2, #0xc] */
/* @0x1ca994 cmp r4, #0 */
/* @0x1ca998 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca99c ldrb r3, [r4, #0x68] */
/* @0x1ca9a0 cmp r3, #0 */
/* @0x1ca9a4 bne 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca9a8 ldrb r3, [r4, #0x69] */
/* @0x1ca9ac cmp r3, #0 */
/* @0x1ca9b0 bne 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca9b4 mov r0, r4 */
/* @0x1ca9b8 mov r1, r6 */
/* @0x1ca9bc mov r2, #1 */
/* @0x1ca9c0 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1ca9c4 cmp r0, #0 */
/* @0x1ca9c8 bne 0x1ca7ac <_Z21Command_InstancePlaceP9CInstanceffi+0xd4> */
/* @0x1ca9cc b 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* ── 3.13 -1 出口：什么都不做（0x1ca9d0..0x1ca9d4） ─────────────────────────────────────────────────────────
 * mov r0,r4（r4 = 0）→ 1ca7c0 收尾。这条支路**不搬实例、不复位**：因为 SetPosition 在它之后。
 * 对照 Line/Rect 的 -1 出口（1cb488 / 1ca448）：那两处也没副作用，三节一致。
 */
/* @0x1ca9d0 mov r0, r4 */
/* @0x1ca9d4 b 0x1ca7c0 <_Z21Command_InstancePlaceP9CInstanceffi+0xe8> */
/* ── 3.14 池字 8 个（0x1ca9d8..0x1ca9f4，非指令） ──────────────────────────────────────────────────────────
 * 1ca9d8 0x00227544 → 1ca714+0x227544 = 0x3f1c58（PIC 锚）
 * 1ca9dc 0xffffbfec → 0x3edc44（g_ObjectHash 槽，3.7 的 1ca7cc）
 * 1ca9e0 0xffffeeb8 → 0x3f0b10（&s_instancePtr 槽，1ca864/1ca8a0）
 * 1ca9e4 0x0022a844 → 1ca8a4+0x22a844 = 0x3f50e8（**place 专用**目标 obj 槽）
 * 1ca9e8 0xffffc5f4 → 0x3ee24c（g_tree 槽）
 * 1ca9ec 0xffffdd84 → 1ca8c4-0x227c = 0x1c8648（回调地址）
 * 1ca9f0 0xffffbcd8 → 0x3ed930（Run_Room 槽，3.10 的 1ca8e8）
 * 1ca9f4 0xffffbff4 → 0x3edc4c（id 表槽，3.12 的 1ca958）
 */
/* ↑ 非指令：池字 0x00227544（PIC 锚加数，1ca70c 的 add r9,pc,r9 → 0x3f1c58），objdump 误译为 eoreq */
/* @0x1ca9d8 eoreq r7, r2, r4, asr #10 */
/* @0x1ca9dc .word 0xffffbfec */
/* @0x1ca9e0 .word 0xffffeeb8 */
/* ↑ 非指令：池字 0x0022a844（1ca8a4 的 add r0,pc,r0 → 0x3f50e8 目标 obj 槽），objdump 误译为 eoreq */
/* @0x1ca9e4 eoreq r10, r2, r4, asr #16 */
/* @0x1ca9e8 .word 0xffffc5f4 */
/* @0x1ca9ec .word 0xffffdd84 */
/* @0x1ca9f0 .word 0xffffbcd8 */
/* @0x1ca9f4 .word 0xffffbff4 */

