/* cally 逆向卡：实例 / 运动类内建 9 个（原版 libyoyo.so，armv7）
 * 节: 9 个 @func 小节，顺序 = instance_activate_region / instance_place / instance_destroy /
 *     instance_exists / instance_number / mp_potential_step / move_towards_point /
 *     point_direction / sign
 * 级别: 正文（249/249 逐条落锚 = 247 条指令 + 2 个池字；9 个函数的入参下标、闸门方向、分支目标、
 *       返回值编码全部逐条解出；被调方只到调用边界，库内未展开的部分逐条列进 open）
 * 索引: asm/index-builtins_motion_all.tsv（9 个函数按地址合并，249 行）
 * 重叠: 节 3（instance_destroy）与既存 cards/F_InstanceDestroy.c 同 24 条锚点（0x10b190..0x10b1ec）。该函数早有专卡，
 *       本卡仍按批次口径完整覆盖 9 函数 249 锚点；verify_reverse_v1.py 会报 addresses_claimed_by_two_cards=24，
 *       属已知且只在节 3，全卡其余 225 条与任何卡无交叠。
 *
 * ── 统一签名（9 个一模一样）───────────────────────────────────────────────
 *   F_Xxx(RValue& result, CInstance* self, CInstance* other, int argc, RValue** args)
 *   r0 = &result、r1 = self、r2 = other、r3 = argc、[sp] = args。
 *   取参一律 YYGetFloat / YYGetInt32 / YYGetBool / YYGetReal(const RValue*, int index)，下标是常量，
 *   本层不校验 argc 与下标的匹配（唯一例外 instance_destroy：先看 argc 决定要不要读 args[1]）。
 *   本卡 9 个里 r3 被当 scratch 的 8 个，读 argc 的只有 1 个 —— 0x10b190 的 cmp r3,#1，且在 push 之前。
 *   帧量与取参槽互证（push 寄存器数×4 + vpush + sub = args 的栈槽）：
 *     ActivateRegion 4×4+8 = 0x18（0x10c258）｜InstancePlace 6×4 = 0x18（0x109520）｜
 *     InstanceDestroy 6×4 = 0x18（0x10b1a0）｜InstanceExists 4×4 = 0x10（0x10afa8）｜
 *     InstanceNumber 4×4 = 0x10（0x10b058）｜MpPotentialStep 8×4+8 = 0x28（0x108a44）｜
 *     MoveTowardsPoint 6×4 = 0x18（0x1081a4）｜PointDirection 6×4 = 0x18（0x111a58）｜
 *     Sign 2×4 = 0x8（0x10de78）。
 *   ⇒ 9 个函数共 29 条 bl（YYGetBool/Float/Int32/Real 24 条 + Command_*/YYGML_*/Motion_* 5 条）与 4 条 b，
 *     其中 3 条 b 是尾跳（0x10c2d8 / 0x10b1d8 / 0x1081e8），1 条是 argc==1 档的内部回跳（0x10b1ec）。
 *
 * ── RValue 侧（本卡用到的两个位置）────────────────────────────────────────
 *   载荷 +0x00..+0x07（双精度）；tag 在 +0x0c，0 = REAL。6 个写 result 的函数都**先无条件**把 tag
 *   清 0（str #0,[result,#0xc]），位置各不相同：0x10956c 在调用之后、0x10afa0/0x10b070/0x108a4c/
 *   0x111a60/0x10de84 在取参或调用之前。全卡 0 条 tag≠0 的写 ⇒ 没有字符串/指针型返回。
 *   载荷 5 个用 stm 两字（0x109590 / 0x10afdc / 0x10b094 / 0x111ac4 / 0x10deb4+0x10dec8），
 *   mp_potential_step 用两条 str（0x108ac0 / 0x108ac4）。低字的取法有两种：借 vcvt 后的 d7={s14,s15}
 *   直接读 s14（0x10afd4 / 0x10b08c / 0x111abc），或从整数寄存器 str（0x108ac0 的 r6）。
 *
 * ── 返回值精确编码（RESULT EXACT）────────────────────────────────────────
 *   instance_activate_region : **不写** result（尾跳 GetDeactiveList，0x10c2d8）
 *   instance_place           : 命中 = (double)inst->[0x78]（s32→f64，tag 0）；未命中 = -4.0（高字 0xc0100000 = noone）
 *   instance_destroy         : **不写** result（尾跳 DoInstanceDestroy，0x10b1d8）
 *   instance_exists          : 0.0 / 1.0（vcvt.f64.**u32**，0x10afcc）
 *   instance_number          : (double)(int)（vcvt.f64.**s32**，0x10b084）
 *   mp_potential_step        : 0.0 / 1.0（0x108abc 拼 0x3ff00000 位模式）
 *   move_towards_point       : **不写** result（尾跳 Command_MoveTowards，0x1081e8）
 *   point_direction          : (double)(**float**)（vcvt.f64.f32，0x111ab4）
 *   sign                     : -1.0 / 0.0 / +1.0（0x10dec4 / 0x10dea0 / 0x10dea4）
 *   ⇒ 四种量纲：id-or-noone、bool 0/1、计数、(float) 角度；三个函数完全不碰 result。
 *
 * ── 跨卡链（本卡 0 写点，只读）───────────────────────────────────────────
 *   A 链（活动）room+0x84 头 / +0x80 尾 / +0x88 计数；B 链（失活）room+0x90 头 / +0x8c 尾 / +0x94 计数；
 *   节点链接域 inst+0x178 prev / +0x17c next（同 cards/Builtins_Instance.c 头部）。
 *   本卡 9 个函数**没有一个**写 room+0x80..0x94 或 inst+0x178/+0x17c：只读三处——
 *     instance_number(-3) 从 room+0x80 沿 +0x178 数（0x1c9000/0x1c9014）
 *     instance_place(-3)  从 room+0x80 沿 +0x178 逐个试碰撞（0x1ca8f0/0x1ca900）
 *     instance_activate_region → GetDeactiveList 从 +0x80 与 +0x8c 各沿 +0x178 扫一遍（0x10bb2c/0x10bba0）
 *   销毁真身 DoInstanceDestroy 0x10b12c → DoDestroy 0x10b0c4（已有专卡），本卡只到调用边界 + 衔接段。
 *
 * ── 注册形态（9 个同一形状，已扫描证实）──────────────────────────────────
 *   对 .text 全量扫 B/BL：9 个入口地址**没有任何一条 b/bl 指向**；对 .got(0x3ed718..0x3f2000) 扫 4 字节值：
 *   每个入口恰有 1 个槽命中 —— MoveTowardsPoint 0x3ee0e8｜MpPotentialStep 0x3ee138｜InstanceExists 0x3ee190｜
 *   InstanceNumber 0x3ee194｜InstancePlace 0x3ee1a4｜InstanceDestroy 0x3ee1bc｜ActivateRegion 0x3ee1ec｜
 *   Sign 0x3ee2f4｜PointDirection 0x3ee3f8。⇒ 9 条都是经函数指针表（GOT 注册）被 VM 间接调用。
 *
 * ── 逐条锚点（9 节）─────────────────────────────────────────────────────
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 1 · F_InstanceActivateRegion（instance_activate_region）
 * @func 0x10c24c 0x10c2e0  size 152  38 条（36 条指令 + 2 个池字 0x10c2dc/0x10c2e0）
 * 符号: _Z24F_InstanceActivateRegionR6RValueP9CInstanceS2_iPS_
 * 一句话: 把 (left,top,w,h,inside) 写进 .bss 静态区 0x4836e0（right=left+w、bottom=top+h），再以
 * InstanceRegionActivate(0x10a390) 为回调尾跳 GetDeactiveList；真正搬状态全在回调里 ——
 * 本函数不写 result，也不碰任何 CInstance。GML 形态 instance_activate_region(left,top,w,h,inside)。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 1.1 帧 24 字节 + 静态区基址 0x4836e0（0x10c24c..0x10c264）─────────────────
 *   push {r3,r4,r5,lr}(16) + vpush {d8}(8) ⇒ args 在 [sp,#0x18]（0x10c258）。r5 = args。
 *   0x10c25c 取池字 0x377474（池在 0x10c2dc），0x10c264 `add r4,pc,r4` ⇒
 *   r4 = 0x10c26c + 0x377474 = **0x4836e0**（.bss，无符号静态；.text 是 0xb6fd0..0x31bb7c，
 *   0x4836e0 落在 .bss 0x479a90 之内）。字段与回调的读点逐一对应：
 *     r4+0x0c bool  inside            → 绝对 0x4836ec（1.2 写 / 回调 0x10a424 读）
 *     r4+0x10 float left              → 0x4836f0（1.2 写 / 0x10a3cc 读）
 *     r4+0x14 float top               → 0x4836f4（1.2 写 / 0x10a3f8 读）
 *     r4+0x18 float right = left + w  → 0x4836f8（1.3 写 / 0x10a3c8 读）
 *     r4+0x1c float bottom = top + h  → 0x4836fc（1.3 写 / 0x10a3fc 读）
 *   三次 `add rX,pc,rX`（0x10a3c4 / 0x10a3f4 / 0x10a420）在回调里都落 0x4836e0 —— 同一块，地址已核。
 *   r1/r2（self/other）与 r3（argc）**一次都没读**。 */
/* @0x10c24c push {r3, r4, r5, lr} */
/* @0x10c250 vpush {d8} */
/* @0x10c254 mov r1, #4 */
/* @0x10c258 ldr r5, [sp, #0x18] */
/* @0x10c25c ldr r4, [pc, #0x78] */
/* @0x10c260 mov r0, r5 */
/* @0x10c264 add r4, pc, r4 */
/* ── 1.2 inside = YYGetBool(args,**4**) + 前两个 float（0x10c268..0x10c294）─────────
 *   注意 r1=#4 早在 0x10c254 就置好，0x10c268 才调用 ⇒ bool 取第 **5** 个实参（inside），不是第 1 个；
 *   紧接着 0x10c26c mov r1,#0 才切到下标 0。落位：strb → +0x0c（inside）、args[0] → +0x10（left）、
 *   args[1] → +0x14（top）。0x10c290 在存 top 的同时把 left 装进 s17，为 1.3 的加法备料。 */
/* @0x10c268 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10c26c mov r1, #0 */
/* @0x10c270 strb r0, [r4, #0xc] */
/* @0x10c274 mov r0, r5 */
/* @0x10c278 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c27c mov r1, #1 */
/* @0x10c280 str r0, [r4, #0x10] */
/* @0x10c284 mov r0, r5 */
/* @0x10c288 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c28c mov r1, #2 */
/* @0x10c290 vldr s17, [r4, #16] */
/* @0x10c294 str r0, [r4, #0x14] */
/* ── 1.3 w/h 换成绝对右下角 + 取回调指针（0x10c298..0x10c2cc）─────────────────
 *   args[2] = w（下标 2）→ s15；s17 = left + w（0x10c2b0 vadd.f32）→ +0x18（右边界）。
 *   args[3] = h（下标 3）→ s15；s16 是 +0x14 的 top（0x10c2a4 装入）→ s16 = top + h → +0x1c（下边界）。
 *   ⇒ 第 3/4 实参是**宽高**而不是右下角坐标，函数自己加。
 *   0x10c2bc 取池字 0x002e1e00（池在 0x10c2e0），0x10c2c4 `ldr r0,[pc,r3]` ⇒
 *   [0x10c2cc + 0x2e1e00] = GOT 槽 **0x3ee0cc**，槽内存的 4 字节（R_ARM_RELATIVE，addend 在位）
 *   = **0x10a390** = InstanceRegionActivate。⇒ 尾跳前 r0 就是回调函数指针，GetDeactiveList 的 fn 非 0。 */
/* @0x10c298 mov r0, r5 */
/* @0x10c29c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c2a0 mov r1, #3 */
/* @0x10c2a4 vldr s16, [r4, #20] */
/* @0x10c2a8 vmov s15, r0 */
/* @0x10c2ac mov r0, r5 */
/* @0x10c2b0 vadd.f32 s17, s17, s15 */
/* @0x10c2b4 vstr s17, [r4, #24] */
/* @0x10c2b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c2bc ldr r3, [pc, #0x1c] */
/* @0x10c2c0 vmov s15, r0 */
/* @0x10c2c4 ldr r0, [pc, r3] */
/* @0x10c2c8 vadd.f32 s16, s16, s15 */
/* @0x10c2cc vstr s16, [r4, #28] */
/* ── 1.4 复原帧后尾跳 GetDeactiveList（0x10c2d0..0x10c2d8）─────────────────
 *   vpop {d8} + pop {r3,r4,r5,lr} 把 1.1 的帧全部拆掉，最后 `b 0x10baf8` —— 本函数不留返回路径。
 *   ⇒ 返回值寄存器里是 GetDeactiveList 的 List*（VM 不用）；**result 一个字都没写**。
 *   回调侧（0x10a390）才是真动作：先比 bbox/点与本静态区，再要求「区内/区外」与 inside 不同，
 *   过 +0x68==0 且 +0x69!=0 才把实例追加进 g_InstanceActivateDeactive(0x542a4c) 并 SetDeactivated(inst,false)。
 *   0x10a390 在 .text 里**没有任何 b/bl 指向**它 —— 只经 GOT 槽 0x3ee0cc 当函数指针传进来（本卡唯一一处）。 */
/* @0x10c2d0 vpop {d8} */
/* @0x10c2d4 pop {r3, r4, r5, lr} */
/* @0x10c2d8 b 0x10baf8 <_Z15GetDeactiveListPFvP9CInstanceE> */
/* ── 1.5 两个池字（0x10c2dc / 0x10c2e0，非指令）──────────────────────────────
 *   0x10c2dc = 0x377474 是 0x10c25c 的 ldr 字面（→ r4 = 0x4836e0）；
 *   0x10c2e0 = 0x002e1e00 是 0x10c2bc 的 ldr 字面（→ GOT 槽 0x3ee0cc）。
 *   objdump 按 ARM 译成 eorseq/eoreq，按规矩保留原写法、只标注它不是指令。 */
/* @0x10c2dc eorseq r7, r7, r4, ror r4 —— 非指令（字面池） */
/* @0x10c2e0 eoreq r1, lr, r0, lsl #28 —— 非指令（字面池） */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 2 · F_InstancePlace（instance_place）
 * @func 0x109518 0x109594  size 128  32 条（无池字）
 * 符号: _Z15F_InstancePlaceR6RValueP9CInstanceS2_iPS_
 * 一句话: x=YYGetFloat(args,0)、y=YYGetFloat(args,1)、obj=YYGetInt32(args,2) → Command_InstancePlace(self,x,y,obj)；
 * 返回指针非 0 → result = (double)inst->[0x78]（tag 0）；为 0 → result = -4.0（noone，tag 0）。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 2.1 帧 24 字节 + 三个实参（0x109518..0x109550）────────────────────────────
 *   push {r4,r5,r6,r7,r8,lr}(24) ⇒ args 在 [sp,#0x18]。result→r5、args→r4、self→r8（r1 只读这一次）；
 *   x→r7（下标 0，YYGetFloat）、y→r6（下标 1，YYGetFloat）、obj→r3（下标 2，**YYGetInt32**）。
 *   ⇒ 前两个参数走 single（GML 里是实数）、第三个参数走 int32（对象索引/实例 id 都是整数）；
 *     传实数对象号时由 YYGetInt32 截断，本函数不做取整纠正。**other（r2）一次都没读**。 */
/* @0x109518 push {r4, r5, r6, r7, r8, lr} */
/* @0x10951c mov r5, r0 */
/* @0x109520 ldr r4, [sp, #0x18] */
/* @0x109524 mov r8, r1 */
/* @0x109528 mov r1, #0 */
/* @0x10952c mov r0, r4 */
/* @0x109530 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109534 mov r1, #1 */
/* @0x109538 mov r7, r0 */
/* @0x10953c mov r0, r4 */
/* @0x109540 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109544 mov r1, #2 */
/* @0x109548 mov r6, r0 */
/* @0x10954c mov r0, r4 */
/* @0x109550 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* ── 2.2 调 Command_InstancePlace(self,x,y,obj)（0x109554..0x109564）────────────
 *   装参序 = r0=self、r1=x、r2=y、r3=obj，与符号 _Z21Command_InstancePlaceP9CInstanceffi 完全一致。
 *   Command_InstancePlace(0x1ca6d8) 内部（旁证、无锚点、地址已核）：先问 ShouldUseFastCollision 三路分流
 *     -1（对象不存在）→ 直接返回 0，**不移位**；1（快路）→ UpdateTree + RTree::Search；
 *     其它（慢路）→ 0x1ca72c/0x1ca730 先把 self 的旧 x/y 存进 r7/r8，0x1ca734 SetPosition(self,x,y)，
 *     再按 obj 分三档试碰撞（objgm+0xd0 节点链 / room+0x80 链 / ms_ID2Instance 表），
 *     命中与未命中两条出口都汇到 0x1ca7ac..0x1ca7b8 把 self **还原**到旧坐标，最后 0x1ca7bc 返回实例指针
 *     （未命中在 0x1ca818 置 r4=0）。⇒ instance_place 会临时搬动 self、但一定还原，且返回 0 表示未命中。
 *   指向 0x1ca6d8 的分支全 .text 共 2 处：0x109564（本函数）与 0x1caa0c —— 命令层被两个内建共用。 */
/* @0x109554 mov r2, r6 */
/* @0x109558 mov r1, r7 */
/* @0x10955c mov r3, r0 */
/* @0x109560 mov r0, r8 */
/* @0x109564 bl 0x1ca6d8 <_Z21Command_InstancePlaceP9CInstanceffi> */
/* ── 2.3 result 精确编码：id 或 -4.0（0x109568..0x109594）─────────────────────
 *   0x109568 mov r3,#0 + 0x10956c str r3,[r5,#0xc] ⇒ **tag 先清 0**（在调用之后、取值之前，命中/未命中都清）。
 *   0x109570 cmp r0,#0：
 *     非 0 → 0x109574 ldrne r2,[r0,#0x78]（实例 id，int）；vmovne s15,r2 → vcvtne.f64.**s32** → vmovne r2,r3,d7
 *            ⇒ r2 = 低字、r3 = 高字 = (double)id；
 *     为 0 → moveq r3,#0 / moveq r2,#0 / movteq r3,#0xc010 ⇒ r3 = 0xC0100000、r2 = 0 ⇒ **-4.0**（noone）。
 *   0x109590 stm r5,{r2,r3} 一次写两个字；此后不再改 result。⇒ 只有两个输出值：正 id 或 -4.0。 */
/* @0x109568 mov r3, #0 */
/* @0x10956c str r3, [r5, #0xc] */
/* @0x109570 cmp r0, #0 */
/* @0x109574 ldrne r2, [r0, #0x78] */
/* @0x109578 moveq r3, #0 */
/* @0x10957c moveq r2, #0 */
/* @0x109580 movteq r3, #0xc010 */
/* @0x109584 vmovne s15, r2 */
/* @0x109588 vcvtne.f64.s32 d7, s15 */
/* @0x10958c vmovne r2, r3, d7 */
/* @0x109590 stm r5, {r2, r3} */
/* @0x109594 pop {r4, r5, r6, r7, r8, pc} */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 3 · F_InstanceDestroy（instance_destroy）
 * @func 0x10b190 0x10b1ec  size 96  24 条（无池字）
 * 符号: _Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_
 * 一句话: 按 argc 三档摊成 DoInstanceDestroy(self,other,id,hard)：argc≥2 → (args[0], args[1])；
 * argc==1 → (args[0], true)；argc≤0 → (-1, true)。result 一个字都不写。
 * 备注: 本函数已有专卡 cards/F_InstanceDestroy.c（24 条同锚）；本节只补「与 DoInstanceDestroy 的衔接」，
 *       入参位置的推导不重复。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 3.1 唯一的 argc 读取 + 帧（0x10b190..0x10b1a4）──────────────────────────
 *   0x10b190 `cmp r3,#1` 在 **push 之前**；push/mov/ldr 都不改 flags，0x10b1a4 的 ble 用的仍是这一组 ⇒
 *   argc≤1 走 0x10b1dc。这是本卡 9 个函数里唯一一次读 argc（也是唯一一次读 r3 的语义值）。
 *   帧 24 字节 ⇒ args 在 [sp,#0x18]；self→r5、other→r6 之后再没从栈上取。 */
/* @0x10b190 cmp r3, #1 */
/* @0x10b194 push {r4, r5, r6, r7, r8, lr} */
/* @0x10b198 mov r5, r1 */
/* @0x10b19c mov r6, r2 */
/* @0x10b1a0 ldr r4, [sp, #0x18] */
/* @0x10b1a4 ble 0x10b1dc <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x4c> */
/* ── 3.2 argc≥2：hard=YYGetBool(args,1)、id=YYGetInt32(args,0)（0x10b1a8..0x10b1c4）──
 *   源码顺序是先 bool 后 int（0x10b1ac 的 #1 在 0x10b1bc 的 #0 之前），与最终实参顺序无关。
 *   ⇒ 第 2 实参是 bool（DoDestroy 的 hard），不是 id 的补充位。 */
/* @0x10b1a8 mov r0, r4 */
/* @0x10b1ac mov r1, #1 */
/* @0x10b1b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b1b4 mov r7, r0 */
/* @0x10b1b8 mov r0, r4 */
/* @0x10b1bc mov r1, #0 */
/* @0x10b1c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10b1c4 mov r2, r0 */
/* ── 3.3 尾跳 DoInstanceDestroy(self,other,id,hard)（0x10b1c8..0x10b1d8）─────────
 *   r0=self、r1=other、r2=id、r3=hard；pop 掉全部 6 个被保存寄存器后 `b 0x10b12c` ⇒ 不留帧、无返回处理。
 *   ⇒ 本包装器对 result **既不读也不写**（r0 在 0x10b1c8 就被 self 覆盖）。 */
/* @0x10b1c8 mov r0, r5 */
/* @0x10b1cc mov r1, r6 */
/* @0x10b1d0 mov r3, r7 */
/* @0x10b1d4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x10b1d8 b 0x10b12c <_Z17DoInstanceDestroyP9CInstanceS0_ib> */
/* ── 3.4 argc≤1 的缺省档（0x10b1dc..0x10b1ec）──────────────────────────────
 *   argc==0（含负数；Z=0 ⇒ movne/mvnne 生效）：r7=1（hard=true）、r2=~0=**-1**、bne 0x10b1c8 直接尾跳，
 *     连 YYGetInt32 都不调。
 *   argc==1（Z=1）：movne/mvnne 不执行，0x10b1e8 `mov r7,r3` 把 argc 本身（=1）当 hard=true，
 *     再 b 0x10b1b8 去取 id。⇒ 少了 YYGetBool 那一次调用，结果与传 true 等价。 */
/* @0x10b1dc movne r7, #1 */
/* @0x10b1e0 mvnne r2, #0 */
/* @0x10b1e4 bne 0x10b1c8 <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x10b1e8 mov r7, r3 */
/* @0x10b1ec b 0x10b1b8 <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x28> */
/* ── 3.5 衔接：DoInstanceDestroy / DoDestroy 里到底发生什么（跨卡旁证，无锚点）──────
 *   DoInstanceDestroy(self,other,id,hard) 0x10b12c → WithObjIterator it(id,self,other,false) 0x19d060
 *     → do { DoDestroy(it.de(), hard); it.Next(); } while (it.de())（0x10b160/0x10b168/0x10b174..0x10b184）。
 *   DoDestroy(inst,hard) 0x10b0c4 的两道闸在 hard 判断**之前**：inst==0 / inst+0x68!=0 / inst+0x69!=0 任一成立
 *     就 pop 返回 ⇒ **已失活（+0x69）的实例 instance_destroy 无效，hard=1 也救不回**。
 *   hard 分流：hard!=0 → 尾跳 Command_Destroy 0x1c9b54（事件 1 + 事件 12、置 +0x6a、置 +0x68、全局计数器++）；
 *     hard==0 → 只 Perform_Event(inst,inst,12,0) + 置 +0x68 + 计数器++（逐条见 cards/DoDestroy.c）。
 *   ⇒ 缺省 argc≤0 → id=-1 **不是「销毁全部」而是「销毁 self」**：WithObjIterator 的 id==-1 档只取 self；
 *     id 的五档（-1 self / -2 other / -3 全活动链 / ≤0x1869F 对象索引+继承 / >0x1869F 实例表）见
 *     cards/DoInstanceDestroy.c §5。self 为空（无实例作用域）时 DoDestroy 首闸直接返回。
 *   ⇒ 这一层的「谁被销毁」完全由 id 决定，与 hard 无关；hard 只决定跑几个事件。 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 4 · F_InstanceExists（instance_exists）
 * @func 0x10af94 0x10afe0  size 80  20 条（无池字）
 * 符号: _Z16F_InstanceExistsR6RValueP9CInstanceS2_iPS_
 * 一句话: obj=YYGetInt32(args,0) → YYGML_instance_exists(self,other,obj)；返回 0/1 再按 **u32** 转 double。
 * ⇒ result 恒为 0.0 或 1.0（tag 0），是布尔 double，不是 id。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 4.1 帧 16 字节 + tag 先清 0（0x10af94..0x10afb4）───────────────────────
 *   push {r4,r5,r6,lr}(16) ⇒ args 在 [sp,#0x10]；result→r4、self→r5、other→r6。
 *   0x10af98 mov r3,#0 之后 0x10afa0 `str r3,[r0,#0xc]` ⇒ **tag 在取参前就清 0**（r3 复用作 0 常量，
 *   0x10afac 又用它当 YYGetInt32 的下标 0）。这与节 5 的顺序相反（5 节先取参后清 tag），差别只是调度，
 *   但说明两者是不同模板展开的。 */
/* @0x10af94 push {r4, r5, r6, lr} */
/* @0x10af98 mov r3, #0 */
/* @0x10af9c mov r4, r0 */
/* @0x10afa0 str r3, [r0, #0xc] */
/* @0x10afa4 mov r5, r1 */
/* @0x10afa8 ldr r0, [sp, #0x10] */
/* @0x10afac mov r1, r3 */
/* @0x10afb0 mov r6, r2 */
/* @0x10afb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* ── 4.2 调用 + 转 double（0x10afb8..0x10afe0）──────────────────────────────
 *   装参 r0=self、r1=other、r2=obj 后 bl 0x10af14；返回值在 r0。
 *   0x10afc8 vmov s15,r0 → 0x10afcc vcvt.f64.**u32** d7,s15 ⇒ 按**无符号**32 位转 double
 *   （对照节 5 的 s32）—— 若 YYGML 返回负数，这里会变成 4.29e9 量级；本函数实际只返回 0/1，故不可达。
 *   0x10afd0 vmov r0,r1,d7 把高字放进 r1；0x10afd4 `vmov r2,s14` 取 d7 的低半（s14 = 低字，vcvt 后天然同步）
 *   ⇒ 低字从 s14、高字从 r1，最后 0x10afdc stm r4,{r2,r3}（r3 = r1，0x10afd8）。
 *   这不是笔误：本卡另两处 vcvt 后的取低字都是这个写法（0x10b08c / 0x111abc）。 */
/* @0x10afb8 mov r1, r6 */
/* @0x10afbc mov r2, r0 */
/* @0x10afc0 mov r0, r5 */
/* @0x10afc4 bl 0x10af14 <_Z21YYGML_instance_existsP9CInstanceS0_i> */
/* @0x10afc8 vmov s15, r0 */
/* @0x10afcc vcvt.f64.u32 d7, s15 */
/* @0x10afd0 vmov r0, r1, d7 */
/* @0x10afd4 vmov r2, s14 */
/* @0x10afd8 mov r3, r1 */
/* @0x10afdc stm r4, {r2, r3} */
/* @0x10afe0 pop {r4, r5, r6, pc} */
/* ── 4.3 「存在」的口径（旁证，无锚点，地址已核）──────────────────────────────
 *   YYGML_instance_exists 0x10af14：WithObjIterator it(obj,self,other,false) → 循环里 de() 调两次（条件 + 体）
 *   + Next() 一次，逐个过 +0x68（skip，0x10af64）与 +0x69（deactivated，0x10af70）两闸；
 *   第一个两闸都放行的实例即 0x10af7c 返回 1；迭代耗尽走 0x10af88 返回 0（r3 来自 subs 的 0）。
 *   ⇒ instance_exists 的真实含义是「存在**且已激活**」：实例还在链上但 +0x69=1 时返回 false。
 *   ⇒ -1/-2/-3 的解析本层不特判，全部交给迭代器（-1=self、-2=other、-3=全活动链，见 cards/DoInstanceDestroy.c §5）。 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 5 · F_InstanceNumber（instance_number）
 * @func 0x10b04c 0x10b098  size 80  20 条（无池字）
 * 符号: _Z16F_InstanceNumberR6RValueP9CInstanceS2_iPS_
 * 一句话: obj=YYGetInt32(args,0) → YYGML_instance_number(self,other,obj)；返回 int 按 **s32** 转 double。
 * ⇒ result = (double)计数，tag 0。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 5.1 帧 + 先取参（0x10b04c..0x10b064）─────────────────────────────────
 *   push {r4,r5,r6,lr}(16) ⇒ args 在 [sp,#0x10]；result→r4、self→r5、other→r6。
 *   与节 4 相反：本函数**先** bl YYGetInt32(args,0)，之后 5.2 才清 tag。 */
/* @0x10b04c push {r4, r5, r6, lr} */
/* @0x10b050 mov r4, r0 */
/* @0x10b054 mov r5, r1 */
/* @0x10b058 ldr r0, [sp, #0x10] */
/* @0x10b05c mov r1, #0 */
/* @0x10b060 mov r6, r2 */
/* @0x10b064 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* ── 5.2 清 tag、调用、s32→f64（0x10b068..0x10b098）────────────────────────
 *   0x10b068 mov r3,#0 + 0x10b070 str r3,[r4,#0xc] ⇒ tag=0；装参 r0=self、r1=other、r2=计数。
 *   0x10b080 vmov s15,r0 → 0x10b084 vcvt.f64.**s32**（signed！与节 4 的 u32 不同）→ 0x10b088 vmov r0,r1,d7
 *   0x10b08c vmov r2,s14（低字）→ 0x10b090 mov r3,r1（高字）→ 0x10b094 stm r4,{r2,r3}。 */
/* @0x10b068 mov r3, #0 */
/* @0x10b06c mov r1, r6 */
/* @0x10b070 str r3, [r4, #0xc] */
/* @0x10b074 mov r2, r0 */
/* @0x10b078 mov r0, r5 */
/* @0x10b07c bl 0x10afe4 <_Z21YYGML_instance_numberP9CInstanceS0_i> */
/* @0x10b080 vmov s15, r0 */
/* @0x10b084 vcvt.f64.s32 d7, s15 */
/* @0x10b088 vmov r0, r1, d7 */
/* @0x10b08c vmov r2, s14 */
/* @0x10b090 mov r3, r1 */
/* @0x10b094 stm r4, {r2, r3} */
/* @0x10b098 pop {r4, r5, r6, pc} */
/* ── 5.3 数数口径（旁证，无锚点，地址已核；本节最容易被抄错的一段）──────────────
 *   YYGML_instance_number 0x10afe4 先特判两个负数，**都不是计数**：
 *     obj==-1（0x10afec cmn r2,#1）→ self 为空返回 0；self->[0x68]!=0 返回 0；否则返回 !self->[0x69]
 *                    （0x10affc..0x10b010，全是 0/1）
 *     obj==-2（0x10afe4 cmn r2,#2）→ 对 other 同样处理（0x10b024..0x10b040；other 为空时 0x10b044 直接返回 0）
 *     其余（含 -3）→ 尾跳 Command_InstanceNumber(obj) 0x1c8ed0
 *   Command_InstanceNumber 三条路（r3 是累加器）：
 *     -3（0x1c8ed4 cmn r0,#3）→ r3=&Run_Room(0x54298c) → room+0x80 起、沿 inst+0x178 走完整条链，
 *        只数 +0x68==0 且 +0x69==0 的（0x1c9010..0x1c9028）；**不按对象过滤、不清零**
 *     obj≤0x1869F（0x1c8ee4 以 movw/movt 拼 99999）→ ① 在 g_ObjectHash(0x542374) 的桶链按 entry[+8]==obj
 *        找到 entry，取 entry[+0xc] = CObjectGM*，再走 objgm+0xd0 的实例链（8 字节节点 {next@0, inst@8}）计数；
 *        ② **紧接着**扫全局列表 0x542a64（12 字节 {ptr,+4,count@+8}），按 inst+0x7c==obj 过滤后再计数；
 *        ②接在①的循环尾（0x1c8f9c 紧跟 0x1c8f68 的 bne），r3 **不清零** ⇒ 两处是**相加**，不是二选一
 *     obj>0x1869F（0x1c8ef0 bgt）→ 走 CInstance::ms_ID2Instance(0x536f28) 表，命中取 value 当 CInstance*，
 *        返回 0 或 1（0x1c9090..0x1c90a0）—— 同样不是计数
 *   ⇒ 正确口径：**只有对象索引是计数**；-1/-2/实例 id 都是 0/1。
 *   ⇒ 若某实例同时挂在 objgm+0xd0 链和 0x542a64 列表里，会被数两次；两边何时同时非空未证（见 open）。
 *   指向 0x1c8ed0 的分支全 .text 共 3 处：0x10b018（本函数尾跳）、0x13ee48、0x141cb8。 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 6 · F_MpPotentialStep（mp_potential_step）
 * @func 0x108a34 0x108acc  size 156  39 条（无池字）
 * 符号: _Z17F_MpPotentialStepR6RValueP9CInstanceS2_iPS_
 * 一句话: x=YYGetFloat(0)、y=YYGetFloat(1)、step=YYGetFloat(2)、checkall=YYGetBool(3) →
 * Motion_Potential_Step(self,x,y,step,**-3**,checkall)（第 5 实参硬编码 -3）；
 * 返回非 0 → result = 1.0，否则 0.0（tag 0）。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 6.1 帧 40 字节 + tag 清 0（0x108a34..0x108a58）─────────────────────────
 *   push 8 字(32) + sub sp,#8 ⇒ args 在 [sp,#0x28]；result→r5、self→r7、args→r4（other 未读）。
 *   r6=0 先当常量：0x108a4c `str r6,[r0,#0xc]` 清 tag，之后 r6 又当返回值暂存（6.4 复用）。 */
/* @0x108a34 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x108a38 sub sp, sp, #8 */
/* @0x108a3c mov r6, #0 */
/* @0x108a40 mov r5, r0 */
/* @0x108a44 ldr r4, [sp, #0x28] */
/* @0x108a48 mov r7, r1 */
/* @0x108a4c str r6, [r0, #0xc] */
/* @0x108a50 mov r1, r6 */
/* @0x108a54 mov r0, r4 */
/* @0x108a58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* ── 6.2 四个实参（0x108a5c..0x108a88）──────────────────────────────────
 *   args[0]→r10（x）、args[1]→r9（y）、args[2]→r8（step），三个都走 YYGetFloat；
 *   args[3]→r0 走 **YYGetBool**（checkall）。⇒ GML 形态 mp_potential_step(x, y, step, checkall)。 */
/* @0x108a5c mov r1, #1 */
/* @0x108a60 mov r10, r0 */
/* @0x108a64 mov r0, r4 */
/* @0x108a68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108a6c mov r1, #2 */
/* @0x108a70 mov r9, r0 */
/* @0x108a74 mov r0, r4 */
/* @0x108a78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108a7c mov r1, #3 */
/* @0x108a80 mov r8, r0 */
/* @0x108a84 mov r0, r4 */
/* @0x108a88 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* ── 6.3 组两个栈参后调用（0x108a8c..0x108aa8）──────────────────────────────
 *   0x108a90 `mvn r12,#2` = **-3** → 0x108a9c str 到 [sp]（第 5 实参 obj，恒 -3）；
 *   checkall 写 [sp,#0x4]（第 6 实参，bool）。r0=self、r1=x、r2=y、r3=step。
 *   ⇒ 调用者**没有**给 GML 暴露 obj 参数：mp_potential_step 永远针对全活动实例做避障，
 *     与 Command_InstancePlace / Command_InstanceNumber 的 -3 是同一哨兵值。 */
/* @0x108a8c mov r3, r8 */
/* @0x108a90 mvn r12, #2 */
/* @0x108a94 mov r1, r10 */
/* @0x108a98 mov r2, r9 */
/* @0x108a9c str r12, [sp] */
/* @0x108aa0 str r0, [sp, #0x4] */
/* @0x108aa4 mov r0, r7 */
/* @0x108aa8 bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib> */
/* ── 6.4 返回值：0.0 / 1.0（0x108aac..0x108acc）───────────────────────────
 *   cmp r0,#0 后靠条件指令拼两个字：
 *     r0!=0 → movne r3,r6(=0) + movtne r3,#0x3ff0 ⇒ 高字 0x3FF00000、低字 r6=0 ⇒ **1.0**；
 *     r0==0 → movne 跳过、moveq r3,r6 ⇒ 0 ⇒ **0.0**。
 *   0x108ac0/0x108ac4 两条 str 分别写 [result]（低字 r6=0）与 [result+4]（高字 r3）。
 *   ⇒ 是布尔 double，不含方向/距离信息。 */
/* @0x108aac cmp r0, #0 */
/* @0x108ab0 moveq r6, r0 */
/* @0x108ab4 movne r3, r6 */
/* @0x108ab8 moveq r3, r6 */
/* @0x108abc movtne r3, #0x3ff0 */
/* @0x108ac0 str r6, [r5] */
/* @0x108ac4 str r3, [r5, #0x4] */
/* @0x108ac8 add sp, sp, #8 */
/* @0x108acc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ── 6.5 Motion_Potential_Step 的入口语义（旁证，无锚点，地址已核）────────────────
 *   0x19ccc8 先比较 (inst+0xb4, inst+0xb8) 与 (x,y)：两者都相等就直接 0x19cd0c `mov r0,#1` 返回 ——
 *   「已经在目标点上」算成功，这时 step 一步都不走（所以返回 1 不代表走满了 step）。
 *   否则 dist = sqrt(dx²+dy²)（0x19cd1c..0x19cd2c），dist ≤ step 走 0x19cde0 的贴近分支，
 *   否则 ComputeDir(inst->x,inst->y,x,y)（0x19c740）→ TryDir(dir, inst, step, obj, checkall)（0x19cba8）。
 *   TryDir 失败后的扫描：s16 从 **0.0** 起（0x19ce80 = 0x00000000），每轮先试 dir+s16（0x19cd6c vadd）、
 *   再试 dir-s16（0x19cda0 vsub），偏移量累加的是一个**全局 float 步长**（0x19cd88 经 GOT 偏移 0x253944 取值），
 *   累到 ≥ **180.0f**（0x19ce84 = 0x43340000）就放弃（0x19cd9c bpl）。
 *   避障采样的具体上限、checkall 改变哪一支未逐条展开（见 open）。
 *   指向 0x19ccc8 的分支全 .text 共 5 处：0x108aa8（本函数）、0x108b40（mp_potential_step_object）、
 *   0x13e2e4 / 0x13e31c（action 族）、0x19cf7c（内部）。 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 7 · F_MoveTowardsPoint（move_towards_point）
 * @func 0x10819c 0x1081e8  size 80  20 条（无池字）
 * 符号: _Z18F_MoveTowardsPointR6RValueP9CInstanceS2_iPS_
 * 一句话: x=YYGetFloat(0)、y=YYGetFloat(1)、spd=YYGetFloat(2) → 尾跳 Command_MoveTowards(self,x,y,spd)；
 * result **不写**（全函数 0 条 str 到 [result]）。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 7.1 帧 + 前两个实参（0x10819c..0x1081c8）──────────────────────────────
 *   push 6 字(24) ⇒ args 在 [sp,#0x18]；self→r7（r1 直接搬过去，之后不再用 r1；other 未读）；
 *   args[0]→r6（x）、args[1]→r5（y），都是 YYGetFloat。 */
/* @0x10819c push {r4, r5, r6, r7, r8, lr} */
/* @0x1081a0 mov r7, r1 */
/* @0x1081a4 ldr r4, [sp, #0x18] */
/* @0x1081a8 mov r1, #0 */
/* @0x1081ac mov r0, r4 */
/* @0x1081b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1081b4 mov r1, #1 */
/* @0x1081b8 mov r6, r0 */
/* @0x1081bc mov r0, r4 */
/* @0x1081c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1081c4 mov r1, #2 */
/* @0x1081c8 mov r5, r0 */
/* ── 7.2 第三实参 + 尾跳（0x1081cc..0x1081e8）─────────────────────────────
 *   args[2]→r0（spd，YYGetFloat）；装参 r1=x、r2=y、r3=spd、r0=self，pop 掉 6 字后 `b 0x1c97ec`。
 *   ⇒ 不留帧、无返回；result 原封不动（GML 侧得到 undefined）。 */
/* @0x1081cc mov r0, r4 */
/* @0x1081d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1081d4 mov r1, r6 */
/* @0x1081d8 mov r2, r5 */
/* @0x1081dc mov r3, r0 */
/* @0x1081e0 mov r0, r7 */
/* @0x1081e4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1081e8 b 0x1c97ec <_Z19Command_MoveTowardsP9CInstancefff> */
/* ── 7.3 Command_MoveTowards 干的三件事（旁证，无锚点，地址已核）────────────────
 *   0x1c97ec：hspeed = x - inst->[0xb4]（0x1c97f0 vldr s15,[r0,#180] + 0x1c97fc vsub）
 *             → CInstance::SetHspeed(0x1930f4)（0x1c9810）
 *             vspeed = y - inst->[0xb8]（0x1c9814/0x1c9818）→ SetVspeed(0x193114)（0x1c9824）
 *             → 尾跳 CInstance::SetSpeed(spd)（0x1930d4，0x1c9838）
 *   ⇒ 写的是 hspeed/vspeed 再由 SetSpeed 归一化到 spd，**不直接改坐标**；方向由 (x,y) 定，速率由第 3 参定。
 *   ⇒ 该命令层共 3 个调用点（0x1081e8 本函数、0x14160c、0x14162c），move_towards_point 只是其中一个入口。 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 8 · F_PointDirection（point_direction）
 * @func 0x111a50 0x111ac8  size 124  31 条（无池字）
 * 符号: _Z16F_PointDirectionR6RValueP9CInstanceS2_iPS_
 * 一句话: 四个 float 实参 → YYGML_point_direction(x1,y1,x2,y2) 返回 **float**，再 vcvt.f64.f32 扩宽成 double。
 * ⇒ result = (double)(float 角度)，单位度、量程 [0,360)（见 8.3）。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 8.1 帧 + tag 清 0 + 前三个实参（0x111a50..0x111a98）────────────────────
 *   push 6 字(24) ⇒ args 在 [sp,#0x18]；result→r5、args→r4。
 *   0x111a54 mov r1,#0 随后 0x111a60 `str r1,[r0,#0xc]` ⇒ tag 先清 0（r1 同时兼任第一个下标）。
 *   args[0]→r8（x1）、args[1]→r7（y1）、args[2]→r6（x2），三个 YYGetFloat。 */
/* @0x111a50 push {r4, r5, r6, r7, r8, lr} */
/* @0x111a54 mov r1, #0 */
/* @0x111a58 ldr r4, [sp, #0x18] */
/* @0x111a5c mov r5, r0 */
/* @0x111a60 str r1, [r0, #0xc] */
/* @0x111a64 mov r0, r4 */
/* @0x111a68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111a6c mov r1, #1 */
/* @0x111a70 mov r8, r0 */
/* @0x111a74 mov r0, r4 */
/* @0x111a78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111a7c mov r1, #2 */
/* @0x111a80 mov r7, r0 */
/* @0x111a84 mov r0, r4 */
/* @0x111a88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111a8c mov r1, #3 */
/* @0x111a90 mov r6, r0 */
/* @0x111a94 mov r0, r4 */
/* @0x111a98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* ── 8.2 第四实参 + 调用 + f32→f64（0x111a9c..0x111ac8）────────────────────
 *   args[3]→r0（y2）；装参 r1=y1、r2=x2、r3=y2、r0=x1 ⇒ 实参序 (x1,y1,x2,y2) 与符号一致。
 *   返回 float 在 s0 → 0x111ab0 vmov s15,r0 → 0x111ab4 vcvt.f64.**f32** d7,s15
 *   → 0x111ab8 vmov r0,r1,d7（高字进 r1）→ 0x111abc `vmov r2,s14`（低字）→ 0x111ac0 mov r3,r1
 *   → 0x111ac4 stm r5,{r2,r3}。
 *   ⇒ 精度只到 single：大坐标/小角度差在 YYGML 里就已经丢掉了，扩宽不补回来（见 8.3）。 */
/* @0x111a9c mov r1, r7 */
/* @0x111aa0 mov r2, r6 */
/* @0x111aa4 mov r3, r0 */
/* @0x111aa8 mov r0, r8 */
/* @0x111aac bl 0x1119a4 <_Z21YYGML_point_directionffff> */
/* @0x111ab0 vmov s15, r0 */
/* @0x111ab4 vcvt.f64.f32 d7, s15 */
/* @0x111ab8 vmov r0, r1, d7 */
/* @0x111abc vmov r2, s14 */
/* @0x111ac0 mov r3, r1 */
/* @0x111ac4 stm r5, {r2, r3} */
/* @0x111ac8 pop {r4, r5, r6, r7, r8, pc} */
/* ── 8.3 角度约定（旁证，无锚点，地址与常数已核；本卡最需要钉住的一条）────────────
 *   YYGML_point_direction 0x1119a4 全部在 float 里算：
 *     dx = x2 - x1（s15 = s12(r2=x2) - s13(r0=x1)，0x1119a8..0x1119b0）
 *     dy = y2 - y1（s14 = s12(r3=y2) - s13(r1=y1)，0x1119b4..0x1119c0）
 *     dx != 0 → atan2f(**dy, dx**)（r0=dy、r1=dx；0x1119f4..0x1119fc）
 *                × 180.0f（0x43340000，0x111a40）÷ π（0x40490fdb，0x111a44）（0x111a00..0x111a10）
 *                θ > 0  → **360 - θ**（hi 分支：0x111a1c vldrhi 360.0f@0x43b40000 / 0x111a20 vsubhi）
 *                θ ≤ 0  → **-θ**（ls 分支：0x111a24 vnegls）
 *     dx == 0 → 三分支：dy > 0 → **270**（0x43870000，0x1119d8）；dy == 0 → **0**（0x111a3c = 0x00000000）；
 *                dy < 0 → **90**（0x42b40000，0x111a30）
 *   对四象限抽样核过（dy>0,dx>0 → 315；dy>0,dx<0 → 225；dy<0,dx>0 → 45；dy<0,dx<0 → 135），与 GM 一致。
 *   ⇒ 单位是**度**、量程 [0,360)、**0 = 正右、90 = 正上、180 = 正左、270 = 正下**
 *     —— y 轴向下（+0xb8 越大越靠下），所以 dy>0 指向 270 而不是 90，这不是数学极角。
 *   ⇒ 两条边界：θ 恰为 +0.0（dx>0, dy==0）时走 vnegls，返回的是 **-0.0**（符号位 1 的零）；
 *     该 -0.0 扩宽成 double 仍是 -0.0，与 +0.0 相等但位模式不同。
 *   ⇒ 中间量是 single：θ 的有效位数只有 24 位（180.0f/π 各带一次舍入），
 *     与 sign 用 YYGetReal（8 字节）形成对照。 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 9 · F_Sign（sign）
 * @func 0x10de6c 0x10decc  size 100  25 条（无池字）
 * 符号: _Z6F_SignR6RValueP9CInstanceS2_iPS_
 * 一句话: v = YYGetReal(args,0)（**双精度**，本批唯一用 YYGetReal 的）→ v<0 → -1.0；v==0 → 0.0；否则 1.0。
 * 三种都 tag 0。result 恒为 {-1.0, 0.0, +1.0}。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* ── 9.1 帧 8 字节 + 取 double（0x10de6c..0x10de88）──────────────────────
 *   push {r4,lr}(8) ⇒ args 在 [sp,#0x8]；result→r4。r1=#0 是 YYGetReal 的下标。
 *   返回值 r0/r1 = double 两字：0x10de88 `vmov d7,r0,r1` 拼回 d7。
 *   tag 在 0x10de80/0x10de84 清 0（mov r3,#0 在调用之后、比较之前）。
 *   ⇒ 只有 sign 走 YYGetReal：输入不做 single 截断，与 point_direction（8 节）相反。
 *   比较是紧跟的 0x10de8c vcmpe.f64 d7,#0（与 +0.0 比，锚点落在 9.2 段首），0x10de94 的 blt 据此分流。 */
/* @0x10de6c push {r4, lr} */
/* @0x10de70 mov r1, #0 */
/* @0x10de74 mov r4, r0 */
/* @0x10de78 ldr r0, [sp, #0x8] */
/* @0x10de7c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10de80 mov r3, #0 */
/* @0x10de84 str r3, [r4, #0xc] */
/* @0x10de88 vmov d7, r0, r1 */
/* ── 9.2 非负路：判零后 0.0 / 1.0（0x10de90..0x10deb8）────────────────────
 *   0x10de94 blt 已把负数分走（9.3），这里只剩 v>=0：
 *   0x10de98 vcmp.f64 d7,#0（注意这里是 **vcmp**，9.1 用的是 vcmpe）+ vmrs
 *   0x10dea0 moveq r2,#0 / 0x10dea4 movne r2,#1 ⇒ 只有 0 与 1 两种整数；
 *   0x10dea8 vmov s15,r2 → 0x10deac vcvt.f64.s32 → 0x10deb0 vmov r2,r3,d7 → 0x10deb4 stm r4,{r2,r3}。
 *   ⇒ +0.0 与 **-0.0** 都走 eq（vcmp 与 +0.0 比），返回 +0.0 而不是 -0.0。 */
/* @0x10de8c vcmpe.f64 d7, #0 */
/* @0x10de90 vmrs APSR_nzcv, fpscr */
/* @0x10de94 blt 0x10debc <_Z6F_SignR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x10de98 vcmp.f64 d7, #0 */
/* @0x10de9c vmrs APSR_nzcv, fpscr */
/* @0x10dea0 moveq r2, #0 */
/* @0x10dea4 movne r2, #1 */
/* @0x10dea8 vmov s15, r2 */
/* @0x10deac vcvt.f64.s32 d7, s15 */
/* @0x10deb0 vmov r2, r3, d7 */
/* @0x10deb4 stm r4, {r2, r3} */
/* @0x10deb8 pop {r4, pc} */
/* ── 9.3 负路：直接拼 -1.0（0x10debc..0x10decc）──────────────────────────
 *   mov r2,#0 + mov r3,#0 + movt r3,#0xbff0 ⇒ 高字 0xBFF00000、低字 0 ⇒ **-1.0**，stm 两字后 pop。
 *   两条出口都各自 stm，没有共用尾；两条都不再动 tag（9.1 已清）。 */
/* @0x10debc mov r2, #0 */
/* @0x10dec0 mov r3, #0 */
/* @0x10dec4 movt r3, #0xbff0 */
/* @0x10dec8 stm r4, {r2, r3} */
/* @0x10decc pop {r4, pc} */
/* ── 9.4 三个边界（指令已落锚，语义按 ARM VFP 规则推出，未实测）────────────────
 *   · vcmpe.f64 d7,#0 与 **+0.0** 比 ⇒ -0.0 走「非负」路，得 +0.0。
 *   · NaN：VCMP 置 N=0,Z=0,C=1,V=1，`blt`（LT = N!=V）成立 ⇒ NaN 返回 **-1.0**。
 *   · 0x10de8c 用 vcmpe（signaling，对 quiet NaN 置 FPSCR.IOC）、0x10de98 用 vcmp
 *     —— 同函数两种比较混用，是编译器对 `<` 与 `==` 的默认展开，不是手写。
 *   ⇒ 上述两条（-0.0 → +0.0、NaN → -1.0）都是 ISA 规则推的，没有运行期对照（open）。 */
/* ── 跨函数已证事实（9 节合并；括号里是节号与地址）───────────────────────────
 *  1. result 的写与不写：6 个写（Place/Exists/Number/MpStep/PointDir/Sign），**3 个完全不写**
 *     —— ActivateRegion 0x10c2d8、InstanceDestroy 0x10b1d8、MoveTowardsPoint 0x1081e8 都是尾跳，
 *     全函数没有一条 str 落到 [result]。⇒ 这三个内建在 GML 里得到 undefined，不是 0。
 *  2. tag 先行且只有一个值：6 个写 result 的函数都无条件 `str #0,[result,#0xc]`
 *     （0x10956c 在调用后、0x10afb4 / 0x10b070 / 0x108a4c / 0x111a60 / 0x10de84 在取参或调用前），
 *     全卡 0 条 tag≠0 的写 ⇒ 本批没有字符串/指针型返回，VM 端不必做释放。
 *  3. 「返回 0/1」有**三种不同实现**：instance_exists 用 vcvt.f64.**u32**（0x10afcc）、
 *     instance_number 用 vcvt.f64.**s32**（0x10b084）、mp_potential_step 直接拼 0x3ff00000 位模式
 *     （0x108abc）。前两者只在「负数」上不同，本批实际输出都非负，故不可达差异。
 *  4. +0x68（skip）/ +0x69（deactivated）是本批的通用闸，出现在：instance_exists（0x10af64 / 0x10af70）、
 *     instance_number 的三条路（0x1c8f7c / 0x1c8fe8 / 0x1c9010 / 0x1c9090）、instance_destroy 的 DoDestroy
 *     （0x10b0d0..0x10b0e4）、instance_place 的两条慢路（0x1ca77c..0x1ca790 / 0x1ca8fc..0x1ca914）、
 *     activate_region 的回调（0x10a430..0x10a444）。**唯一不看 +0x69 的入口**是 instance_activate_region
 *     本体：它的筛选完全交给 GetDeactiveList（要求 +0x69!=0 才回调）。
 *  5. 遍历源一共四处，互不相同：① WithObjIterator（exists / destroy）；② room+0x80 沿 +0x178（number(-3)、
 *     place(-3)）；③ objgm+0xd0 的 8 字节节点链 {next@0, inst@8}（number(obj)、place(obj)）；
 *     ④ 两张哈希表 g_ObjectHash(0x542374) 与 ms_ID2Instance(0x536f28)。⇒「按对象」与「按实例 id」
 *     在运行期是两套表，不是同一套过滤；本卡没有任何函数同时用两者做同一件事。
 *  6. 三个哨兵值的含义：-3 = 全活动实例（number 计数 / place 试碰撞 / mp_potential_step 硬编码）；
 *     -1 = **self**、-2 = other（destroy 的缺省、exists/number 的分支）；instance_number(-1/-2) 返回 0/1
 *     而不是计数 —— 全批最容易抄错的一处。
 *  7. 调用点普查（全 .text 扫 B/BL）：Command_InstancePlace 0x1ca6d8 有 2 处（0x109564 本卡、0x1caa0c）；
 *     Command_InstanceNumber 0x1c8ed0 有 3 处（0x10b018 本卡、0x13ee48、0x141cb8）；
 *     Command_MoveTowards 0x1c97ec 有 3 处（0x1081e8 本卡、0x14160c、0x14162c）；
 *     Motion_Potential_Step 0x19ccc8 有 5 处（0x108aa8 本卡、0x108b40、0x13e2e4、0x13e31c、0x19cf7c）；
 *     InstanceRegionActivate 0x10a390 **0 处**（只经 GOT 槽 0x3ee0cc 当函数指针传）。
 *     ⇒ 本卡的 9 个包装器都只是各自命令层的其中一个入口，命令层还被 action 族复用。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. GetDeactiveList(0x10baf8) 只用到边界：先把缓存表（GOT 0x3ee0c0 → .bss 0x483708 指向的 12 字节 List）
 *     的 count 清 0（0x10bb20），再从 room+0x80、room+0x8c 各沿 +0x178 扫一遍（0x10bb48 / 0x10bbbc 两段同构），
 *     对 +0x68==0 且 +0x69!=0 的实例**先 blx fn 再追加**（0x10bb68..0x10bb8c）。回调版与收集版并存，
 *     两张表（0x483708 缓存表 / 0x542a4c 待办表）的消费时序未钉；ProcessActivateDeactveLists(0x1d3074) 之后
 *     待办表 count 归零，与本卡无交集。
 *  2. InstanceRegionActivate(0x10a390) 只到「与静态区比较」这一步：先 Sprite_Exists(inst+0x8c)，
 *     失败再试 Sprite_Exists(inst+0xac)；两者都不存在时走 0x10a49c 分支，改用 inst+0xb4/+0xb8 的点判定，
 *     并读 0x4836dc（= 静态区 base-4）的一个字段 —— 该字段是什么没定。bbox 侧还看 inst+0x64（脏位）决定
 *     要不要先重算，两分支的判据没有逐条核。
 *  3. instance_number 的「相加」：objgm+0xd0 链计完数后 r3 **不清零**就扫全局列表 0x542a64（按 +0x7c 过滤），
 *     两处相加。0x542a64 何时被填、两边会不会同时命中同一实例（重复计数）未证；该列表在
 *     cards/Variable_GetValue.c 里也只到「退化扫描列表 1」。
 *  4. mp_potential_step 的避障语义（TryDir 0x19cba8 / ComputeDir 0x19c740）未逐条展开：
 *     采样角步长、checkall 改变哪一支、失败返回 0 的判据都只到调用边界（6.5 已给出入口分叉）。
 *  5. instance_destroy 的 hard=false 语义按 cards/DoDestroy.c 记（只跑事件 12 + 置 +0x68 + 计数器++），
 *     与 GM 文档里第 2 参（execute_event）是否同名同义没做运行期对照。
 *  6. sign 的 NaN → -1.0、-0.0 → +0.0 是按 VCMP/blt 的 ISA 规则推的（9.4），未实测。
 *  7. 9 个入口的注册表结构未证：只知各自恰有 1 个 GOT 槽（0x3ee0e8..0x3ee3f8 一段内），且在 .text 里
 *     没有任何 b/bl 指向它们；表是按内建编号还是按名字哈希索引未核。
 */
