/* cally 逆向卡：Variable_SetValue（原版 libyoyo.so，armv7）
 * @func 0x1f4348 0x1f476c  size 1060  265 条（末条 0x1f4768；其中 255 条可达指令 + 10 个 literal pool 字，
 *       无跳转表、无栈 canary、无 blx，栈帧 12 字节）
 * 级别: 正文（五路分派 / 四个解析源 / 六个出口 / 返回值契约 / 与 Variable_SetValue_Direct 的实参改名
 *            全部逐条解出；本函数不写任何 RValue、不调 FREE_RValue__Pre、不调 SET_RValue 已证；
 *            两个后备容器的身份、元素 +0x80 指向的类型、YYError 是否必然终止进程见 open）
 * 符号: _Z17Variable_SetValueiiiP6RValue → int Variable_SetValue(int sel, int var, int index, RValue* value)
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   本函数是「这次写要落到哪些实例上」的解析器 + 派发器，不是赋值本体：按 sel 解析出 0..N 个实例，
 *   对每个实例调用 Variable_SetValue_Direct(obj, var, index, value)（0x1f3c28），自己一个 RValue
 *   字节都不碰。旧值释放、按 tag 的拷贝与引用计数、数组下标与越界，全部在下游
 *   SET_RValue(0xd0b24) / SET_RValue_Array(0xcfcb4) 里发生（段8，函数体外，已注明）。
 *   硬证据：全函数 4 条 str 全部落在自己的 12 字节栈帧（@0x1f43d0 / @0x1f446c / @0x1f4530 / @0x1f4690），
 *   0 条 strb，只有 2 个被调用者（Direct：4 bl + 1 尾 b；YYError：3 bl）；没有任何一条指令落在
 *   某个 RValue 的 +0xc 上（全函数不读任何 tag）。
 *
 * ── 段1 调用契约 ──────────────────────────────────────────────────────────
 *   唯一调用者：DoPop @0xe6760（扫全 .text 的 bl/b/blx-imm 只此一处；全文件也没有任何指向
 *   0x1f4348 的 4 字节函数指针——该常量唯一出现是 .dynsym 的 st_value，文件偏移 0x4b2c）：
 *     r0 = r9（sel）、r1 = r10（var）、r2 = [r11,#-0x88c]（index）、r3 = r8（value RValue*）
 *     0xe6764 cmp r0,#0 / 0xe6768 beq 0xe677c → 返回 0 时 DoPop 走回退（Code_Variable_Find_Name
 *     + FindOrAllocValue / JS_Object_Put），返回非 0 时视为「已处理」。
 *   ⇒ 返回值语义 = 「有没有人接手这次写」，不是「写成功/失败」。
 *   实参改名后不再回写：r4 = sel（@0x1f4358）、r8 = var（@0x1f435c）、r7 = index（@0x1f4360）、
 *   r6 = value（@0x1f4364）；r9 自 @0x1f4368 起是 GOT 锚 0x3f1c58（字面量 @0x1f4744 = 0x001fd8e8，
 *   pc 0x1f4370 + 偏移），与 DoSet 卡的 GOT 锚同值。
 *   栈帧只有 12 字节：[sp] 存对象表命中项（只用于错误消息里的 name，@0x1f43d0 / @0x1f4690），
 *   [sp+4] 是循环里倒寄存器的溢出槽（@0x1f446c 存 GOT 锚、@0x1f4530 存 var）。
 *
 * ── 段2 五路分派（入口三条判据，@0x1f434c / @0x1f4370 / @0x1f4380）────────
 *   @0x1f434c cmn r0,#3 → sel == -3  → @0x1f436c 跳 0x1f4600（全体活动实例）
 *   @0x1f4370 cmp r0,#0  → sel <  0  → @0x1f4374 跳 0x1f4684（return 0，没有任何错误消息）
 *   @0x1f4378 movw/movt r3 → 0x1869f = 99999 → @0x1f4384 bgt 0x1f46a0（sel > 99999 = 实例 id 路）
 *   其余（0 <= sel <= 99999）= 对象下标路，从 @0x1f4388 的对象表开始，最后落到 0x1f4450。
 *   ⇒ 99999 = 100000 - 1，与「变量 id 基址 100000」「实例 id 基址 100000」同一个分界常数；
 *     WithObjIterator 构造函数（0x19d060）用的是同一条 movw #0x869f / movt #0x1 与同一条 bgt
 *     （0x19d0a8 / 0x19d0b0 / 0x19d0b4）。
 *   ⇒ sel = -1/-2/-4/-5… 一律 return 0（self/other/noone/global 都不在本函数职责内）。
 *
 * ── 段3 解析源 S1：sel == -3（全体活动实例，0x1f4600..0x1f4664）────────────
 *   g = *(GOT 0x3ed930 → .bss 0x54298c)（@0x1f4600/@0x1f4604/@0x1f4608）；head = *(g+0x80)（@0x1f460c）；
 *   沿 +0x178 遍历（@0x1f4624 先取 next 再动当前节点，允许当前节点在回调里被摘链），跳过
 *   byte+0x68 != 0（@0x1f4620/@0x1f4628）与 byte+0x69 != 0（@0x1f4630/@0x1f4640）的实例，
 *   其余逐个 Direct（@0x1f4648）。r5 = 「至少命中一个」标志（@0x1f4618 清 0、@0x1f464c 置 1），
 *   r10 = 最后一个 Direct 的返回值（@0x1f4650）。一个都没命中 → @0x1f4664 跳 0x1f4710 →
 *   YYError("%d", -3)（@0x1f4714 mvn r1,#2）。
 *   交叉证据：+0x68 = 已销毁（DoDestroy 卡 段2）、+0x69 = 已 deactivate、+0x80 = 活动实例链头、
 *   +0x178 = 链 next —— DoInstanceDestroy 卡 §5 用同一组字段描述 WithObjIterator 的 id==-3 分支
 *   （0x19d198..0x19d1a8 三条指令与本路逐字同构）。
 *
 * ── 段4 解析源 S2：0 <= sel <= 99999（对象表 → 该对象的实例链，0x1f4388..0x1f4450）──
 *   表 M1 = *(GOT 0x3edc44 → .bss 0x542374)，结构 {+0 桶数组, +4 掩码}（@0x1f4390..@0x1f4398）；
 *   桶数组按 8 字节/项寻址、取 +0 处的链头（@0x1f439c and r2,r0,r2 / @0x1f43a0 ldr r3,[r3,r2,lsl #3]）；
 *   节点 {+4 next, +8 key(int), +0xc value}（@0x1f43b0 / @0x1f43bc / @0x1f43c8），+0 本函数未读。
 *   命中项 value 存到 [sp]（@0x1f43d0）；空桶 → @0x1f43ac 跳 0x1f4690、链尽 → @0x1f43b8 跳 0x1f4690、
 *   命中但 value 为空 → @0x1f43d4 跳 0x1f4694：三路都归一到 r12 = r10 = 0 再跳 0x1f4450。
 *   命中且非空：链头 = *(value+0xd0)（@0x1f43d8/@0x1f43dc），节点 {+0 next, +8 instance}
 *   （@0x1f4414 / @0x1f4410），跳过 +0x68（@0x1f4418）与 +0x69（@0x1f4424）后逐个 Direct
 *   （@0x1f443c），成功后 r12 = 1（@0x1f4440）、r10 = 返回值（@0x1f4444）。
 *   ⇒ value 是「对象定义」（CObjectGM），+0xd0 是它的实例链 —— 与 WithObjIterator 0x19d10c
 *     （ldr r3,[r3,#0xd0] 取实例链）和 0x19d11c（ldr r3,[r3,#8] 取链首实例）同构互证。
 *
 * ── 段5 解析源 S3 / S4：两个后备容器（无论 S2 是否命中都会跑）─────────────
 *   C1 = *(GOT 0x3edc48 → .bss 0x542a64)（@0x1f4450/@0x1f4454），C2 = *(GOT 0x3edc50 → .bss 0x542a4c)
 *   （@0x1f4514/@0x1f4518）。两者同一形状：{+0 指针数组, +8 计数}（计数判定 @0x1f4458 / @0x1f451c，
 *   元素取 @0x1f4484..@0x1f4488 / @0x1f4548..@0x1f454c）。对每个元素 x：
 *     沿 *(x+0x80) 的链（节点 {+0x18 key, +0x48 next}，@0x1f4498/@0x1f449c、@0x1f455c/@0x1f4560）
 *       找 key == sel（比较：subs/rsbs/adcs 把「差为 0」布尔化，@0x1f44a0..@0x1f44b8；C2 用
 *       @0x1f4564..@0x1f457c 的同一写法）；
 *     找到且 x 的 +0x68 / +0x69 都为 0（@0x1f44c0..@0x1f44d4 / @0x1f4584..@0x1f4598）→ Direct(x)
 *       （@0x1f44e8 / @0x1f45ac），并把「已处理」标志置 1（@0x1f44ec r1=1 / @0x1f45b0 r2=1）。
 *   两趟各自倒寄存器（@0x1f4458..@0x1f4480 / @0x1f452c..@0x1f4544），结束时还原（@0x1f4500..@0x1f4510 /
 *   @0x1f45c4..@0x1f45c8）。C1 的返回值累积在 r10，C2 结束由 @0x1f45c4 mov r10,r0 覆盖。
 *   ⇒ 静态上无法排除「同一实例被 S2 和 S3/S4 各写一次」（见 open 3）。
 *
 * ── 段6 解析源 S5：sel > 99999（实例表，0x1f46a0..0x1f4708）────────────────
 *   表 M2 = *(GOT 0x3edc4c → .bss 0x536f28)（@0x1f46a0/@0x1f46a4），哈希形状与 M1 完全相同
 *   （@0x1f46a8..@0x1f46d8）。命中项 value = 实例指针；只检查 byte+0x68（@0x1f46e8/@0x1f46f0），
 *   不检查 +0x69；通过则恢复本帧后尾跳 Direct（@0x1f4700..@0x1f4708），返回值直接透传给调用方。
 *   未命中 / +0x68 非 0 → @0x1f46c0 或 @0x1f46e0 跳 0x1f4674 → YYError("%d", sel)（@0x1f4678 mov r1,r4）
 *   再落进 @0x1f4684 return 0。
 *   ⇒ 与 DoInstanceDestroy 卡 §5「id>99999 走同一查表」的措辞相比，实测是另一张表（GOT 0x3edc4c
 *     vs 0x3edc44），只是形状相同；WithObjIterator 0x19d130 起的 id>99999 分支用的也是这对槽
 *     （0x19d1c0 → 0x3edc4c、0x19d1bc → 0x3edc44），可独立复核。
 *
 * ── 段7 出口与返回值 ──────────────────────────────────────────────────────
 *   E1 @0x1f4374 → 0x1f4684：sel < 0 且 != -3 → return 0，无消息。
 *   E2 @0x1f4668 → pop：正常返回 r10（S1 或 [S2,S3,S4] 至少命中一次）。
 *   E3 @0x1f4674 → YYError → @0x1f4684 return 0：sel > 99999 未命中或被 +0x68 挡住。
 *      注意 r10 在 S5 路上从未被写：全函数 12 个 r10 写点是 @0x1f43f0 / @0x1f43fc / @0x1f4444 /
 *      @0x1f4470（倒寄存器，暂存 value 指针）/ @0x1f4510 / @0x1f453c（同上）/ @0x1f45c4 / @0x1f461c /
 *      @0x1f4650 / @0x1f4698 / @0x1f470c / @0x1f473c，全部落在 S1/S2/S3/S4 路，所以 E3 返回的是
 *      未初始化寄存器值。
 *   E4 @0x1f4710 → YYError("%d",-3) → @0x1f4720 return r10(=0)：sel == -3 但一个实例都没写。
 *   E5 @0x1f45d4..@0x1f45f0：S2/S3/S4 全空 → YYError("…'%d' name '%s'", sel, obj ? *(obj+0x14) : "(null)")
 *      → @0x1f45f4 mov r0,r10(=0) → 返回 0。两条 %s 来源：对象非空取 *(obj+0x14)（@0x1f45e0 对象名），
 *      对象为空时 @0x1f45dc 跳 0x1f472c 换成 "(null)"（@0x1f4730 pc 相对 → 0x3527f8）。
 *      消息正文 0x334928 = "Unable to find any instance for object index '%d' name '%s'"；
 *      E3/E4 用 0x352800 = "Unable to find any instance for object index '%d'"。
 *   E6 @0x1f4708：sel > 99999 命中 → 尾跳 Direct，返回值就是 Direct 的返回值（唯一的单实例路）。
 *
 * ── 段8 下游语义（函数体外，用于回答「旧值释放 / tag 拷贝 / 越界」；此处地址不是本卡锚点）──
 *   Variable_SetValue_Direct(0x1f3c28, 184 B / 46 条)：
 *     var <= 9999（0x270f）：内置变量表 base = *(GOT 0x3edc40)（.bss 0x75310c），槽 = base + var*16；
 *       [slot+0xc] != 0 才调 setter：r0 = obj、r1 = index、r2 = value → blx *(slot+8)（0x1f3cb0），
 *       返回值原样传出；[slot+0xc] == 0 → 直接返回 0（什么都没写）。
 *     var > 9999：[obj+0x24] == 0 → 直接返回 1 且不写任何东西（0x1f3c6c/0x1f3c70）；
 *       否则 dst = [obj+4] + (var-100000)*16（0x1f3c74..0x1f3c88；[obj+4] 为空时先 InternalGetYYVar
 *       求槽，0x1f3ccc），再 SET_RValue(dst, value, index)（0x1f3c90），返回 1。
 *   ⇒ 门是 9999 而不是 99999：var ∈ [10000, 99999] 会走 user 路径并算出负槽下标（基址 100000），
 *     静态上是越界写风险；实际能否发生取决于变量 id 分配（本构建变量 id 基址 100000）。
 *   SET_RValue(0xd0b24)：index == 0x80000000 → 整值赋值：先 (dst.tag-1)&0x00FFFFFC == 0 则
 *     FREE_RValue__Pre(dst)（0xd0c38），再 dst.tag=5（0xd0b90）→ 拷 src 的 +8 与 tag（0xd0bb4）
 *     → 按 src.tag 走 15 路表；index 为其它值 → dst 不是数组就先 dst.tag=2 + ARRAY_RefAlloc
 *     （0xd0b54..0xd0b68），再尾跳 SET_RValue_Array(0xcfcb4)。
 *   15 路表实测（0xd0bc4 起 15 项，逐项落点）：0/10/13 → 8 字节裸拷（0xd0c40 ldm/stm）；
 *     1 → [RefThing+4]++，共享不复制文本（0xd0ca4）；2 → 数组容器 [c+0]++ 且 [c+8]==0 时回指 dst
 *     （0xd0c78）；3/7/14 → 4 字节裸拷（0xd0c00 单字 ldr/str）；6 → 裸拷 + DeterminePotentialRoot
 *     (GetContextStackTop(), ptr) 的 GC root 登记（0xd0c50）；4/5/8/9/11/12 → 只写 tag，不动载荷
 *     （0xd0c08 直接返回）。
 *   ⇒ 写路径上没有深拷贝：tag 1/2 都是引用计数 +1 共享；只有 +8 那个字（tag 3 的 bit3 删除许可）
 *     随拷贝一起搬过去（0xd0bb4），所以拷出来的 tag 3 仍带着同样的删除许可。
 *   SET_RValue_Array(0xcfcb4)：ldiv(index, 32000) 拆 chunk/offset（0xcfcec）；chunk 数不够 →
 *     MemoryManager::SetLength 扩容（0xcfe48）→ 正向越界是自动扩容，不报错、不抛异常；元素
 *     tag ∈ 1..4 时同样先 FREE_RValue__Pre(元素)（0xcff4c）再内联拷贝；index 为负（chunk<0 且
 *     offset<0）→ 不写元素，只把一个布尔标志和 (chunk, offset, 元素数, -1) 记进 5 个全局诊断槽
 *     （0xcfdc4..0xcfe08）。
 *   ARRAY_LVAL_RValue(0xd0d38)：旧值不是数组时先 FREE_RValue__Pre(0xd0e60) 再 ARRAY_RefAlloc。
 *   ⇒ 与 FREE_RValue__Pre 的调用关系：本函数 0 次；Direct 不直接调；真正的「写前先放旧值」只在
 *     SET_RValue（0xd0c38）、SET_RValue_Array（0xcff4c）、ARRAY_LVAL_RValue（0xd0e60）三处。
 *
 * ── 已证（每条指到指令）───────────────────────────────────────────────────
 *   1. 入口三分派：sel==-3 / sel<0 / sel>99999 / 其余 —— @0x1f434c、@0x1f4370、@0x1f4378、@0x1f4384
 *   2. S1 用活动实例链 *(*(0x54298c)+0x80)，next 在 +0x178，跳过 +0x68/+0x69 @0x1f4600..@0x1f4648
 *   3. S2 表结构 {+0 桶, +4 掩码}、8 字节桶步长、节点 {+4 next, +8 key, +0xc value} @0x1f4390..@0x1f43c8
 *   4. S2 命中后取 *(CObjectGM+0xd0) 作实例链，节点 {+0 next, +8 instance} @0x1f43dc、@0x1f4410、@0x1f4414
 *   5. S3/S4 容器 {+0 数组, +8 计数} + 元素 +0x80 链 {+0x18 key, +0x48 next} 与 sel 比较
 *      @0x1f4484..@0x1f44b8、@0x1f4548..@0x1f457c
 *   6. S5 用另一张表 *(0x536f28)，只挡 +0x68，尾跳 Direct @0x1f46a0..@0x1f4708
 *   7. 四条 Direct 边 + 一条尾跳 + 三条 YYError 边是全部外呼 @0x1f443c / @0x1f44e8 / @0x1f45ac /
 *      @0x1f4648 / @0x1f4708；@0x1f45f0 / @0x1f4680 / @0x1f471c
 *   8. 全函数 4 条 str 全在本帧、0 条 strb、不读任何 tag ⇒ 不释放、不拷贝旧值
 *      @0x1f43d0 / @0x1f446c / @0x1f4530 / @0x1f4690
 *   9. 三条错误消息：0x334928（带 name）、0x352800（纯 %d）、"(null)" 0x3527f8
 *      @0x1f45e0/@0x1f45e4、@0x1f472c/@0x1f4730、@0x1f4674/@0x1f4684
 *   10. GOT 槽与 .bss 全局：0x3edc44→0x542374、0x3edc48→0x542a64、0x3edc4c→0x536f28、0x3edc50→0x542a4c、
 *      0x3ed930→0x54298c（前四条相邻 16 B，都在 .data.rel.ro；目标都在 .bss）
 *   11. 255 条可达 + 10 个池字，零死代码（自 0x1f4348 走全部分支，除池字外每条都被走到）
 *   12. 返回值 = 最后一个 Direct 的返回值；只有 S5 是单实例直通尾跳 @0x1f4650、@0x1f45c4、@0x1f4708
 *
 * ── 结论 ──────────────────────────────────────────────────────────────────
 *   Variable_SetValue = 「按 sel 解析实例集合」+「逐个 Variable_SetValue_Direct」。它自己既不放旧值、
 *   也不做 tag 拷贝、也不看数组下标：这些全在 SET_RValue 家族里。sel 的语义由三条判据钉死：
 *   -3 = 全体活动实例（沿 +0x178 全链）、0..99999 = 对象下标（对象表 → +0xd0 实例链，再叠两个后备容器）、
 *   >99999 = 单实例 id（实例表 → 尾跳）、其余负数 = 直接 return 0。
 *   写路径的「先释放旧值再拷」纪律由 SET_RValue（0xd0c38）/ SET_RValue_Array（0xcff4c）/
 *   ARRAY_LVAL_RValue（0xd0e60）三处执行；tag 1/2 是引用计数共享而非深拷贝；正向越界自动扩容。
 *
 * ── open ──────────────────────────────────────────────────────────────────
 *   1. C1 / C2（GOT 0x3edc48 → .bss 0x542a64、0x3edc50 → .bss 0x542a4c）的身份未钉：只知道是
 *      {+0 指针数组, +8 计数} 的容器，元素带 +0x80 链。Variable_GetValue(0x1f3ce0) 有完全同构的两趟
 *      （0x1f3d78 / 0x1f3df0），说明不是写路径专有；至于是「房间实例 / 动态实例 / 其它清单」，
 *      本函数没有任何字符串或类型检查可判。
 *   2. 元素 +0x80 指向什么未钉：链上按 +0x18 与 sel（对象下标）比较、+0x48 作 next。自洽的读法是
 *      「实例 → CObjectGM（+0x18 = 对象下标、+0x48 = 父对象）」即按对象继承匹配，但本函数只读这两个
 *      字段、不看类型，缺一条独立证据（例如 CObjectGM 构造点会写 +0x18/+0x48/+0xd0）。
 *   3. S2 命中后 S3/S4 仍会跑：若某实例同时出现在对象实例链和 C1/C2 里，它会被写两次（第二次是
 *      「释放刚写入的值再写同样的值」）。静态无法排除；实际是否发生取决于 C1/C2 的构造。
 *   4. YYError(0xd547c) 是否必然终止：它 vsprintf 后调 Error_Show_Action(msg,1)，再按一个全局字节
 *      决定 exit(1)（0xd5544）还是 YYGML_game_end() 后返回（0xd5538→0xd54cc）。两条都静态可见，
 *      线上走哪条取决于该全局，故 E3 的「返回未初始化 r10」是否可观测未定。
 *   5. 本卡不重定义 tag 表，但下游 15 路表里只有 tag 6 走 DeterminePotentialRoot（GC root），
 *      tag 3 只是单字拷贝；而 FREE_RValue__Pre 的 tag 3 是「+8:bit3 许可下的虚删除」。两者合起来看
 *      tag 3 与 tag 6 是两类指针（非 GC / GC），「tag 3 = pointer」的表述需要这一限定。
 *   6. 本函数对 value(r3→r6) 不判空，也不校验 index（原样透传）；index = 0x80000000 这个「非数组元素」
 *      哨兵完全由 SET_RValue 解释，本函数既不生成也不检查它。

/* @0x1f4348 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言：9 个寄存器入栈；r4=sel r8=var r7=index r6=value */
/* @0x1f434c cmn r0, #3 —— cmn r0,#3 → 判 sel == -3（第一条判据） */
/* @0x1f4350 ldr r9, [pc, #0x3ec] —— 字面量 @0x1f4744 = 0x001fd8e8（GOT 锚相对偏移） */
/* @0x1f4354 sub sp, sp, #12 —— 栈帧 12 B：只用 [sp] 和 [sp+4] */
/* @0x1f4358 mov r4, r0 —— r4 = sel（第 1 个 int） */
/* @0x1f435c mov r8, r1 —— r8 = var（第 2 个 int） */
/* @0x1f4360 mov r7, r2 —— r7 = index（第 3 个 int） */
/* @0x1f4364 mov r6, r3 —— r6 = value（第 4 个实参，RValue*） */
/* @0x1f4368 add r9, pc, r9 —— r9 = 0x1f4370 + 0x1fd8e8 = 0x3f1c58（GOT 锚，与 DoSet 同值） */
/* @0x1f436c beq 0x1f4600 <_Z17Variable_SetValueiiiP6RValue+0x2b8> —— sel == -3 → S1 全体活动实例 */
/* @0x1f4370 cmp r0, #0 —— 判 sel < 0 */
/* @0x1f4374 blt 0x1f4684 <_Z17Variable_SetValueiiiP6RValue+0x33c> —— sel < 0 且非 -3 → return 0（E1，无消息） */
/* @0x1f4378 movw r3, #0x869f —— 0x869f */
/* @0x1f437c movt r3, #0x1 —— movt → r3 = 0x1869f = 99999 = 100000-1 */
/* @0x1f4380 cmp r0, r3 —— 判 sel > 99999 */
/* @0x1f4384 bgt 0x1f46a0 <_Z17Variable_SetValueiiiP6RValue+0x358> —— sel > 99999 → S5 实例 id 路 */
/* @0x1f4388 ldr r3, [pc, #0x3b8] —— GOT 偏移 0xffffbfec → 槽 0x3edc44 → .bss 0x542374（对象表指针） */
/* @0x1f438c ldr r3, [r9, r3] —— M1 = *(0x542374) */
/* @0x1f4390 ldr r3, [r3] —— r3 = *M1 = 桶数组 */
/* @0x1f4394 ldr r2, [r3, #0x4] —— r2 = *(M1+4) = 掩码 */
/* @0x1f4398 ldr r3, [r3] —— r3 = 桶数组基址 */
/* @0x1f439c and r2, r0, r2 —— 桶下标 = sel & mask */
/* @0x1f43a0 ldr r3, [r3, r2, lsl #3] —— 8 字节/项，取 +0 处链头 */
/* @0x1f43a4 cmp r3, #0 —— 空桶？ */
/* @0x1f43a8 bne 0x1f43bc <_Z17Variable_SetValueiiiP6RValue+0x74> —— 非空 → 先比首个节点 */
/* @0x1f43ac b 0x1f4690 <_Z17Variable_SetValueiiiP6RValue+0x348> —— 空桶 → 归一 0x1f4690 */
/* @0x1f43b0 ldr r3, [r3, #0x4] —— 节点 +4 = next */
/* @0x1f43b4 cmp r3, #0 —— next 为空？ */
/* @0x1f43b8 beq 0x1f4690 <_Z17Variable_SetValueiiiP6RValue+0x348> —— 链尽 → 归一 0x1f4690 */
/* @0x1f43bc ldr r2, [r3, #0x8] —— 节点 +8 = key(int) */
/* @0x1f43c0 cmp r4, r2 —— key == sel ？ */
/* @0x1f43c4 bne 0x1f43b0 <_Z17Variable_SetValueiiiP6RValue+0x68> —— 不等 → 下一节点 */
/* @0x1f43c8 ldr r3, [r3, #0xc] —— 节点 +0xc = value（+0 本函数未读） */
/* @0x1f43cc cmp r3, #0 —— value 为空？ */
/* @0x1f43d0 str r3, [sp] —— [sp] = 对象指针（错误消息的 name 来源） */
/* @0x1f43d4 beq 0x1f4694 <_Z17Variable_SetValueiiiP6RValue+0x34c> —— 为空 → 0x1f4694（r12=r10=0） */
/* @0x1f43d8 ldr r3, [sp] —— 取对象指针 */
/* @0x1f43dc ldr r5, [r3, #0xd0] —— CObjectGM+0xd0 = 该对象的实例链头 */
/* @0x1f43e0 cmp r5, #0 —— 链头为空？ */
/* @0x1f43e4 beq 0x1f4738 <_Z17Variable_SetValueiiiP6RValue+0x3f0> */
/* @0x1f43e8 ldr r12, [r5, #0x8] —— 链首节点的 +8 */
/* @0x1f43ec cmp r12, #0 —— 为空 → r12=r10=0，跳 S3 */
/* @0x1f43f0 moveq r10, r12 */
/* @0x1f43f4 beq 0x1f4450 <_Z17Variable_SetValueiiiP6RValue+0x108> */
/* @0x1f43f8 mov r12, #0 —— r12 = 0（尚未命中） */
/* @0x1f43fc mov r10, r12 —— r10 = 0（返回值累加器） */
/* @0x1f4400 b 0x1f4410 <_Z17Variable_SetValueiiiP6RValue+0xc8> */
/* @0x1f4404 ldr r3, [r5, #0x8] —— 循环尾：再看 next 节点 +8 */
/* @0x1f4408 cmp r3, #0 —— 空 → 退出到 S3 */
/* @0x1f440c beq 0x1f4450 <_Z17Variable_SetValueiiiP6RValue+0x108> */
/* @0x1f4410 ldr r0, [r5, #0x8] —— r0 = 节点 +8 = 实例指针 */
/* @0x1f4414 ldr r5, [r5] —— r5 = 节点 +0 = next */
/* @0x1f4418 ldrb r3, [r0, #0x68] —— 实例 +0x68 = 已销毁？ */
/* @0x1f441c cmp r3, #0 */
/* @0x1f4420 bne 0x1f4448 <_Z17Variable_SetValueiiiP6RValue+0x100> */
/* @0x1f4424 ldrb r11, [r0, #0x69] —— 实例 +0x69 = 已 deactivate？ */
/* @0x1f4428 mov r1, r8 —— Direct 的第 2/3/4 实参：var / index / value */
/* @0x1f442c mov r2, r7 */
/* @0x1f4430 mov r3, r6 */
/* @0x1f4434 cmp r11, #0 */
/* @0x1f4438 bne 0x1f4448 <_Z17Variable_SetValueiiiP6RValue+0x100> */
/* @0x1f443c bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> —— → Variable_SetValue_Direct(inst, var, index, value) */
/* @0x1f4440 mov r12, #1 —— 命中标志 r12 = 1 */
/* @0x1f4444 mov r10, r0 —— r10 = Direct 返回值 */
/* @0x1f4448 cmp r5, #0 —— 还有实例？ */
/* @0x1f444c bne 0x1f4404 <_Z17Variable_SetValueiiiP6RValue+0xbc> */
/* @0x1f4450 ldr r3, [pc, #0x2f4] —— GOT 0xffffbff0 → 槽 0x3edc48 → .bss 0x542a64（后备容器 C1） */
/* @0x1f4454 ldr r11, [r9, r3] —— C1 = *(0x542a64) */
/* @0x1f4458 ldr r3, [r11, #0x8] —— C1+8 = 元素计数 */
/* @0x1f445c cmp r3, #0 —— 计数 <= 0 → 跳过 C1 */
/* @0x1f4460 ble 0x1f4514 <_Z17Variable_SetValueiiiP6RValue+0x1cc> */
/* @0x1f4464 mov r5, #0 —— r5 = 0（元素下标） */
/* @0x1f4468 mov r0, r10 */
/* @0x1f446c str r9, [sp, #0x4] —— [sp+4] 暂存 GOT 锚（下方倒寄存器） */
/* @0x1f4470 mov r10, r6 —— r10 = value 指针（倒寄存器，退出时由 0x1f4508 还原 r6） */
/* @0x1f4474 mov r9, r7 */
/* @0x1f4478 mov r1, r12 —— r1 = r12（已命中标志进 r1） */
/* @0x1f447c mov r6, r5 */
/* @0x1f4480 mov r7, r11 */
/* @0x1f4484 ldr r3, [r7] —— C1+0 = 指针数组 */
/* @0x1f4488 ldr r2, [r3, r6, lsl #2] —— x = array[i] */
/* @0x1f448c ldr r5, [r2, #0x80] —— x+0x80 = 链头 */
/* @0x1f4490 cmp r5, #0 —— 链头为空 → 下一个元素 */
/* @0x1f4494 beq 0x1f44f0 <_Z17Variable_SetValueiiiP6RValue+0x1a8> */
/* @0x1f4498 ldr r12, [r5, #0x18] —— 节点 +0x18 = key */
/* @0x1f449c ldr r5, [r5, #0x48] —— 节点 +0x48 = next */
/* @0x1f44a0 subs r11, r4, r12 —— subs/rsbs/adcs 把 (sel - key) == 0 布尔化到 r3 */
/* @0x1f44a4 rsbs r3, r11, #0 */
/* @0x1f44a8 adcs r3, r3, r11 */
/* @0x1f44ac cmp r4, r12 */
/* @0x1f44b0 cmpne r5, #0 */
/* @0x1f44b4 bne 0x1f4498 <_Z17Variable_SetValueiiiP6RValue+0x150> */
/* @0x1f44b8 cmp r3, #0 —— r3 == 0 即命中 → 否则下一个元素 */
/* @0x1f44bc beq 0x1f44f0 <_Z17Variable_SetValueiiiP6RValue+0x1a8> */
/* @0x1f44c0 ldrb r3, [r2, #0x68] —— x 的 +0x68 = 已销毁？ */
/* @0x1f44c4 cmp r3, #0 */
/* @0x1f44c8 bne 0x1f44f0 <_Z17Variable_SetValueiiiP6RValue+0x1a8> */
/* @0x1f44cc ldrb r3, [r2, #0x69] —— x 的 +0x69 = 已 deactivate？ */
/* @0x1f44d0 cmp r3, #0 */
/* @0x1f44d4 bne 0x1f44f0 <_Z17Variable_SetValueiiiP6RValue+0x1a8> */
/* @0x1f44d8 mov r0, r2 —— Direct(x, var, index, value) */
/* @0x1f44dc mov r1, r8 */
/* @0x1f44e0 mov r2, r9 */
/* @0x1f44e4 mov r3, r10 */
/* @0x1f44e8 bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> —— → Variable_SetValue_Direct（C1 的唯一边） */
/* @0x1f44ec mov r1, #1 —— 命中标志 = 1 */
/* @0x1f44f0 ldr r3, [r7, #0x8] —— 下一个元素 / 退出 */
/* @0x1f44f4 add r6, r6, #1 */
/* @0x1f44f8 cmp r3, r6 */
/* @0x1f44fc bgt 0x1f4484 <_Z17Variable_SetValueiiiP6RValue+0x13c> */
/* @0x1f4500 mov r7, r9 */
/* @0x1f4504 ldr r9, [sp, #0x4] */
/* @0x1f4508 mov r6, r10 */
/* @0x1f450c mov r12, r1 */
/* @0x1f4510 mov r10, r0 */
/* @0x1f4514 ldr r3, [pc, #0x234] —— GOT 0xffffbff8 → 槽 0x3edc50 → .bss 0x542a4c（后备容器 C2） */
/* @0x1f4518 ldr r9, [r9, r3] —— C2 = *(0x542a4c) */
/* @0x1f451c ldr r3, [r9, #0x8] —— C2+8 = 元素计数 */
/* @0x1f4520 cmp r3, #0 */
/* @0x1f4524 ble 0x1f45cc <_Z17Variable_SetValueiiiP6RValue+0x284> */
/* @0x1f4528 mov r5, #0 */
/* @0x1f452c mov r0, r10 */
/* @0x1f4530 str r8, [sp, #0x4] —— [sp+4] 暂存 var */
/* @0x1f4534 mov r2, r12 —— r2 = r12（已命中标志进 r2） */
/* @0x1f4538 mov r8, r9 */
/* @0x1f453c mov r10, r6 —— r10 = value 指针（C2 路倒寄存器） */
/* @0x1f4540 mov r9, r7 */
/* @0x1f4544 mov r7, r5 */
/* @0x1f4548 ldr r3, [r8] —— C2+0 = 指针数组 */
/* @0x1f454c ldr r3, [r3, r7, lsl #2] —— x = array[i] */
/* @0x1f4550 ldr r11, [r3, #0x80] —— x+0x80 = 链头 */
/* @0x1f4554 cmp r11, #0 */
/* @0x1f4558 beq 0x1f45b4 <_Z17Variable_SetValueiiiP6RValue+0x26c> */
/* @0x1f455c ldr r5, [r11, #0x18] —— 节点 +0x18 = key */
/* @0x1f4560 ldr r11, [r11, #0x48] —— 节点 +0x48 = next */
/* @0x1f4564 subs r1, r4, r5 —— 同 C1 的相等布尔化 */
/* @0x1f4568 rsbs r6, r1, #0 */
/* @0x1f456c adcs r6, r6, r1 */
/* @0x1f4570 cmp r4, r5 */
/* @0x1f4574 cmpne r11, #0 */
/* @0x1f4578 bne 0x1f455c <_Z17Variable_SetValueiiiP6RValue+0x214> */
/* @0x1f457c cmp r6, #0 —— 命中判据 */
/* @0x1f4580 beq 0x1f45b4 <_Z17Variable_SetValueiiiP6RValue+0x26c> */
/* @0x1f4584 ldrb r1, [r3, #0x68] —— x 的 +0x68 */
/* @0x1f4588 cmp r1, #0 */
/* @0x1f458c bne 0x1f45b4 <_Z17Variable_SetValueiiiP6RValue+0x26c> */
/* @0x1f4590 ldrb r1, [r3, #0x69] —— x 的 +0x69 */
/* @0x1f4594 cmp r1, #0 */
/* @0x1f4598 bne 0x1f45b4 <_Z17Variable_SetValueiiiP6RValue+0x26c> */
/* @0x1f459c mov r0, r3 —— Direct(x, [sp+4]=var, r9=index, r10=value) */
/* @0x1f45a0 mov r2, r9 */
/* @0x1f45a4 ldr r1, [sp, #0x4] */
/* @0x1f45a8 mov r3, r10 */
/* @0x1f45ac bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> —— → Variable_SetValue_Direct（C2 的唯一边） */
/* @0x1f45b0 mov r2, #1 —— 命中标志 = 1 */
/* @0x1f45b4 ldr r3, [r8, #0x8] —— 下一个元素 / 退出 */
/* @0x1f45b8 add r7, r7, #1 */
/* @0x1f45bc cmp r3, r7 */
/* @0x1f45c0 bgt 0x1f4548 <_Z17Variable_SetValueiiiP6RValue+0x200> */
/* @0x1f45c4 mov r10, r0 —— r10 = r0（C2 的返回值覆盖累加器） */
/* @0x1f45c8 mov r12, r2 —— r12 = r2（命中标志） */
/* @0x1f45cc cmp r12, #0 —— 命中过 → 直接返回 */
/* @0x1f45d0 bne 0x1f4668 <_Z17Variable_SetValueiiiP6RValue+0x320> */
/* @0x1f45d4 ldr r3, [sp] —— [sp] = S2 命中的对象指针 */
/* @0x1f45d8 cmp r3, #0 —— 对象为空？ */
/* @0x1f45dc beq 0x1f472c <_Z17Variable_SetValueiiiP6RValue+0x3e4> —— 空 → 换成 (null) */
/* @0x1f45e0 ldr r2, [r3, #0x14] —— r2 = *(obj+0x14) = 对象名 */
/* @0x1f45e4 ldr r0, [pc, #0x168] —— 字面量 @0x1f4754 = 0x00140334 → 消息 0x334928 */
/* @0x1f45e8 mov r1, r4 */
/* @0x1f45ec add r0, pc, r0 —— r0 = 0x1f45f4 + 0x140334 = 0x334928（带 name 的 %d/%s 消息） */
/* @0x1f45f0 bl 0xd547c <_Z7YYErrorPKcz> —— YYError：S2/S3/S4 全空的唯一出口（E5） */
/* @0x1f45f4 mov r0, r10 —— 返回 r10（此路径恒 0） */
/* @0x1f45f8 add sp, sp, #12 */
/* @0x1f45fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f4600 ldr r3, [pc, #0x150] —— GOT 偏移 0xffffbcd8 → 槽 0x3ed930 → .bss 0x54298c（运行时全局 g） */
/* @0x1f4604 ldr r3, [r9, r3] —— 取 .bss 0x54298c 的地址 */
/* @0x1f4608 ldr r3, [r3] —— g = *(0x54298c) */
/* @0x1f460c ldr r0, [r3, #0x80] —— head = *(g+0x80) = 活动实例链头 */
/* @0x1f4610 cmp r0, #0 —— 链空？ */
/* @0x1f4614 beq 0x1f470c <_Z17Variable_SetValueiiiP6RValue+0x3c4> */
/* @0x1f4618 mov r5, #0 —— r5 = 0（至少命中一个的标志） */
/* @0x1f461c mov r10, r5 —— r10 = 0 */
/* @0x1f4620 ldrb r12, [r0, #0x68] —— 实例 +0x68 = 已销毁？ */
/* @0x1f4624 ldr r4, [r0, #0x178] —— 先取 next 到 r4，再动当前节点 */
/* @0x1f4628 cmp r12, #0 —— 已销毁 → 跳过 */
/* @0x1f462c bne 0x1f4654 <_Z17Variable_SetValueiiiP6RValue+0x30c> */
/* @0x1f4630 ldrb r12, [r0, #0x69] —— 实例 +0x69 = 已 deactivate？ */
/* @0x1f4634 mov r1, r8 —— Direct 的第 2/3/4 实参 */
/* @0x1f4638 mov r2, r7 */
/* @0x1f463c mov r3, r6 */
/* @0x1f4640 cmp r12, #0 —— 已 deactivate → 跳过 */
/* @0x1f4644 bne 0x1f4654 <_Z17Variable_SetValueiiiP6RValue+0x30c> */
/* @0x1f4648 bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> —— → Variable_SetValue_Direct（S1 的唯一边） */
/* @0x1f464c mov r5, #1 —— 标志 = 1 */
/* @0x1f4650 mov r10, r0 —— r10 = Direct 返回值（最后一个） */
/* @0x1f4654 cmp r4, #0 —— next 非空 → 继续 */
/* @0x1f4658 mov r0, r4 —— r0 = next（下一轮） */
/* @0x1f465c bne 0x1f4620 <_Z17Variable_SetValueiiiP6RValue+0x2d8> */
/* @0x1f4660 cmp r5, #0 —— 一个都没命中？ */
/* @0x1f4664 beq 0x1f4710 <_Z17Variable_SetValueiiiP6RValue+0x3c8> —— 全空 → 0x1f4710 报错 */
/* @0x1f4668 mov r0, r10 —— 正常返回 r10（E2） */
/* @0x1f466c add sp, sp, #12 */
/* @0x1f4670 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f4674 ldr r0, [pc, #0xe0] —— 字面量 @0x1f475c = 0x0015e17c → 消息 0x352800 */
/* @0x1f4678 mov r1, r4 —— r1 = sel（%d） */
/* @0x1f467c add r0, pc, r0 —— r0 = 0x1f4684 + 0x15e17c = 0x352800 */
/* @0x1f4680 bl 0xd547c <_Z7YYErrorPKcz> —— YYError：S5 未命中 / 被 +0x68 挡住（E3） */
/* @0x1f4684 mov r0, #0 —— return 0（E1 与 E3 共用；此时 r10 在 S5 路上从未初始化） */
/* @0x1f4688 add sp, sp, #12 */
/* @0x1f468c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f4690 str r3, [sp] —— S2 空桶归一：[sp] = 0，r12 = r10 = 0 */
/* @0x1f4694 mov r12, r3 —— S2 命中但 value 为空/链空：r12 = r10 = 0（不改 [sp]） */
/* @0x1f4698 mov r10, r3 */
/* @0x1f469c b 0x1f4450 <_Z17Variable_SetValueiiiP6RValue+0x108> —— → S3 */
/* @0x1f46a0 ldr r3, [pc, #0xb8] —— GOT 偏移 0xffffbff4 → 槽 0x3edc4c → .bss 0x536f28（实例表） */
/* @0x1f46a4 ldr r3, [r9, r3] —— M2 = *(0x536f28) */
/* @0x1f46a8 ldr r2, [r3, #0x4] —— 与 M1 同一哈希形状 */
/* @0x1f46ac ldr r3, [r3] —— 桶数组 */
/* @0x1f46b0 and r2, r0, r2 —— 桶下标 = sel & mask */
/* @0x1f46b4 ldr r3, [r3, r2, lsl #3] —— 8 字节/项 */
/* @0x1f46b8 cmp r3, #0 —— 空桶？ */
/* @0x1f46bc bne 0x1f46d0 <_Z17Variable_SetValueiiiP6RValue+0x388> —— 非空 → 比首个节点 */
/* @0x1f46c0 b 0x1f4674 <_Z17Variable_SetValueiiiP6RValue+0x32c> —— 未命中 → 0x1f4674 报错 */
/* @0x1f46c4 ldr r3, [r3, #0x4] —— next */
/* @0x1f46c8 cmp r3, #0 —— next 空？ */
/* @0x1f46cc beq 0x1f4674 <_Z17Variable_SetValueiiiP6RValue+0x32c> —— 链尽 → 报错 */
/* @0x1f46d0 ldr r2, [r3, #0x8] —— key */
/* @0x1f46d4 cmp r4, r2 —— key == sel ？ */
/* @0x1f46d8 bne 0x1f46c4 <_Z17Variable_SetValueiiiP6RValue+0x37c> —— 不等 → 下一节点 */
/* @0x1f46dc ldr r0, [r3, #0xc] —— value = 实例指针 */
/* @0x1f46e0 cmp r0, #0 —— 空 → 报错 */
/* @0x1f46e4 beq 0x1f4674 <_Z17Variable_SetValueiiiP6RValue+0x32c> */
/* @0x1f46e8 ldrb r3, [r0, #0x68] —— 实例 +0x68 = 已销毁？（只查这一个，不查 +0x69） */
/* @0x1f46ec cmp r3, #0 */
/* @0x1f46f0 bne 0x1f4674 <_Z17Variable_SetValueiiiP6RValue+0x32c> —— 已销毁 → 报错 */
/* @0x1f46f4 mov r1, r8 —— 尾跳的 2/3/4 实参 */
/* @0x1f46f8 mov r2, r7 */
/* @0x1f46fc mov r3, r6 */
/* @0x1f4700 add sp, sp, #12 —— 先恢复本帧 */
/* @0x1f4704 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f4708 b 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> —— 尾跳 Direct（S5 单实例，返回值直通；E6） */
/* @0x1f470c mov r10, r0 —— r10 = 0（S1 链空的返回值） */
/* @0x1f4710 ldr r0, [pc, #0x4c] —— 字面量 @0x1f4764 = 0x0015e0e0 → 0x352800 */
/* @0x1f4714 mvn r1, #2 —— r1 = -3（mvn r1,#2） */
/* @0x1f4718 add r0, pc, r0 —— r0 = 0x1f4720 + 0x15e0e0 = 0x352800 */
/* @0x1f471c bl 0xd547c <_Z7YYErrorPKcz> —— YYError：sel==-3 但零命中（E4） */
/* @0x1f4720 mov r0, r10 —— return r10（=0） */
/* @0x1f4724 add sp, sp, #12 */
/* @0x1f4728 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f472c ldr r2, [pc, #0x34] —— 字面量 @0x1f4768 = 0x0015e0c0 → (null) */
/* @0x1f4730 add r2, pc, r2 —— r2 = 0x1f4738 + 0x15e0c0 = 0x3527f8 → (null) */
/* @0x1f4734 b 0x1f45e4 <_Z17Variable_SetValueiiiP6RValue+0x29c> —— → 0x1f45e4 用 %s 打印 (null) */
/* @0x1f4738 mov r12, r5 —— r12 = 0（S2 无实例链） */
/* @0x1f473c mov r10, r5 —— r10 = 0 */
/* @0x1f4740 b 0x1f4450 <_Z17Variable_SetValueiiiP6RValue+0x108> —— → S3 */
/* @0x1f4744 andseq sp, pc, r8, ror #17 —— 池字 0x001fd8e8：GOT 锚相对偏移（objdump 按指令译，实为字面量） */
/* @0x1f4748 .word 0xffffbfec —— 池字 0xffffbfec = -0x4014 → GOT 槽 0x3edc44（对象表） */
/* @0x1f474c .word 0xffffbff0 —— 池字 0xffffbff0 = -0x4010 → GOT 槽 0x3edc48（C1） */
/* @0x1f4750 .word 0xffffbff8 —— 池字 0xffffbff8 = -0x4008 → GOT 槽 0x3edc50（C2） */
/* @0x1f4754 andseq r0, r4, r4, lsr r3 —— 池字 0x00140334 → 消息串 0x334928 */
/* @0x1f4758 .word 0xffffbcd8 —— 池字 0xffffbcd8 = -0x4328 → GOT 槽 0x3ed930（运行时 g） */
/* @0x1f475c andseq lr, r5, r12, ror r1 —— 池字 0x0015e17c → 消息串 0x352800 */
/* @0x1f4760 .word 0xffffbff4 —— 池字 0xffffbff4 = -0x400c → GOT 槽 0x3edc4c（实例表） */
/* @0x1f4764 andseq lr, r5, r0, ror #1 —— 池字 0x0015e0e0 → 消息串 0x352800 */
/* @0x1f4768 andseq lr, r5, r0, asr #1 —— 池字 0x0015e0c0 → (null) 0x3527f8 */
