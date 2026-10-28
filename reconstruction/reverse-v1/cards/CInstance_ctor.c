/* cally 逆向卡：CInstance::CInstance(float, float, int, int, bool)（原版 libyoyo.so，armv7）
 * @func 0x1994dc 0x1998e0  size 1028  257 条（249 条指令 + 末 8 字 0x1998c0..0x1998dc 为 literal pool）
 * 级别: 正文（257/257 逐条落锚。本函数 109 条针对实例的存储指令（107 条直接 + 2 条循环，循环各 12 次
 *       ⇒ 131 次写）的偏移与初值逐条解出；基类调用、SetObjectIndex 副作用、全局实例表插槽、
 *       内建属性注册四条外部路径全钉。
 *       未钉的只是十来个槽位的语义名与 +0x48 的标志含义，不是控制流、初值或调用契约）
 * 符号: _ZN9CInstanceC1Effiib / _ZN9CInstanceC2Effiib → CInstance::CInstance(float,float,int,int,bool)
 * 位置: CInstance::SetID(0x1958cc) 之后；~CInstance 两个入口 0x199320(D1/D2) / 0x1993f8(D0) 之前
 * 调用点: 全图唯一 CRoom::AddInstance(float,float,int) 0x1ab194 —— 之前 `mov r0,#432` + operator new
 *         ⇒ sizeof(CInstance) = 0x1B0；实参 (r1=x, r2=y, r3=++room_maxid, [sp]=objindex, [sp+4]=1)
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   432 字节的实例对象：先交给基类 YYObjectBase(int,int) 铺底，再挂 CInstance 的 vtable，然后按
 *   「三段自环链表哨兵 → 12 个 alarm=-1 → 图像/位置/运动学默认值 → 路径/时间线/layer →
 *   全局实例表插槽 → 内建属性注册」逐段写死，最后置 +0x48=1 并清掉创建栈两字段。
 *   没有任何输入校验，也没有「分配失败」以外的分支。
 *
 * ── 语义草案 ──────────────────────────────────────────────────────────────
 *   CInstance* CInstance::CInstance(float x, float y, int id, int objindex, bool addToObject) {
 *     YYObjectBase::YYObjectBase(*(int*)0x544b48, 0x00FFFFFF);     // 0x19188c，见段 2
 *     this->[0x00] = 0x3EBAF8;                                     // vtable
 *     this->[0x188] = -1;                                          // 碰撞网格槽号
 *     this->[0x18c] = this->[0x190] = this+0x18c;                  // 三段自环（空链）
 *     this->[0x198] = this->[0x19c] = this+0x198;
 *     this->[0x1a4] = this->[0x1a8] = this+0x1a4;
 *     this->[0x194] = this->[0x1a0] = this->[0x1ac] = 0;
 *     this->[0x70..0x77] = *(uint64*)0x536f20;                     // ms_CurrentCreateCounter
 *     ...0x78 ~ 0xf4 逐条清零（见字段表）...
 *     for (i=0;i<12;i++) this->alarm[i] = 0;                        // 0xf8..0x124
 *     ...0x128 ~ 0x88 的默认值（见字段表）...
 *     SetObjectIndex(objindex, addToObject);                        // 0x19324c，见段 7
 *     this->image_speed = image_xscale = image_yscale = image_alpha = 1.0f;
 *     this->image_index = image_angle = 0;  this->image_blend = 0x00FFFFFF;
 *     this->x = this->xstart = this->xprevious = x;
 *     this->y = this->ystart = this->yprevious = y;
 *     this->id = id;  this->gravity_direction = 270.0f;
 *     for (i=0;i<12;i++) this->alarm[i] = -1;                        // 第二遍覆盖
 *     this->path_scale = this->timeline_speed = 1.0f;  this->layer = -1;  this->[0x16c] = 2;
 *     slot = InstanceTable_Insert(this);                            // 0x536f0c，见段 10
 *     this->[0x44] = slot;
 *     if (*(char*)0x47f295) { for each builtin-prop entry: maybe YYObjectBase::Add(...); }  // 段 11
 *     this->[0x48] = 1;  this->[0x10] = 0;  this->[0x14] = 0;
 *     return this;
 *   }
 *
 * ── 前提：new 已经整块清零 ────────────────────────────────────────────────
 *   operator new 0x27c524 转 MemoryManager::Alloc(size, file, line, 1)，第 4 参 = 1 时
 *   0x27cecc 调 memset(ptr,0,size) ⇒ 构造入口处 432 字节全是 0。
 *   所以本函数每一条零写都是「覆盖零」，而它**没写**的槽位（0x144/0x148/0x178/0x17c 等）也确定是 0，
 *   不是 malloc 垃圾。真正带信息量的写只有：vtable、-1、1、1.0f、270.0f、0x00FFFFFF、id/x/y、
 *   计数快照、三段自环指针、+0x16c=2、槽号、+0x48=1。
 *
 * ── 字段初始化表（77 行 = 70 个不同偏移 + 1 个 12 元区间；覆盖 107 条直接存储 + 2 条循环）──
 *   说明：一处被写两次的，写点列按「先→后」给；最终初值取后者。
 *
 *   0x000         4   0x3EBAF8            199550                                      vtable（*(GOT 0x3F0694)=0x3EBAF0，+8）
 *   0x010         4   0                   19986c                                      创建栈①（基类按全局开关填 GetStackTrace，本函数收尾清零）
 *   0x014         4   0                   199870                                      创建栈②（基类填 vmGetCallStack，同上清零）
 *   0x044         4   槽号 / -1           1997cc                                      全局实例表（0x536f0c）槽号；析构 0x1993c0 用它在 base 数组清槽
 *   0x048         4   1                   199868                                      基类构造置 0、这里置 1；语义未定（形似「本对象是实例」标记）
 *   0x068         1   0                   199610 / 199730                             skip（DoDestroy 第 2 道闸）
 *   0x069         1   0                   199614 / 199734                             deactivated（DoDestroy 第 3 道闸）
 *   0x06a         1   0                   1995a0                                      硬销毁标记（Command_Destroy 0x1c9b70 置 1，见 DoDestroy 卡）
 *   0x06b         1   0                   19958c                                      未定
 *   0x06c         1   0                   199598                                      未定
 *   0x070         8   *(u64*)0x536f20     1995b0 (strd)                               ms_CurrentCreateCounter 快照：lo→+0x70、hi→+0x74
 *   0x078         4   id（实参 3）        1996b4                                      GV_Id 同址读取
 *   0x07c         4   objindex（实参 4）  （SetObjectIndex 0x193260 写）              GV_ObjectIndex 同址
 *   0x080         4   0 → CObjectGM*      19964c（清零）/ 0x1932f0（覆写）            先清零让 SetObjectIndex 的 RemoveInstance 分支不跑
 *   0x084         4   0                   199654                                      CPhysicsObject*（析构 0x199344 释放；CreatePhysicsBody 0x192cd4 填）
 *   0x088         4   0                   19965c                                      CSkeletonInstance*（析构 0x199388 释放；SkeletonAnimation 0x1931b8 填）
 *   0x08c         4   0                   （SetObjectIndex→SetSpriteIndex 0x1931c0）  sprite_index（GV_SpriteIndex 同址）
 *   0x090         4   0                   19959c / 19968c                             image_index
 *   0x094         4   1.0f                1995a4 / 199674                             image_speed
 *   0x098         4   1.0f                1995ac / 199678                             image_xscale
 *   0x09c         4   1.0f                1995b4 / 199680                             image_yscale
 *   0x0a0         4   0                   1995b8 / 199690                             image_angle
 *   0x0a4         4   1.0f                1995bc / 199684                             image_alpha
 *   0x0a8         4   0x00FFFFFF          1995a8 / 1996c8                             image_blend（白）
 *   0x0ac         4   0                   （SetObjectIndex 0x19331c = obj+0x10）      mask index（GV_MaskIndex 同址）
 *   0x0b4         4   x（实参 1）         19957c / 1996ac                             x
 *   0x0b8         4   y（实参 2）         199588 / 1996b0                             y
 *   0x0bc         4   x                   1995c0 / 1996b8                             xstart
 *   0x0c0         4   y                   1995c4 / 1996bc                             ystart
 *   0x0c4         4   x                   1995c8 / 1996c0                             xprevious（DoAStep 0x1d33ac 每步覆写）
 *   0x0c8         4   y                   1995cc / 1996c4                             yprevious（DoAStep 0x1d33a4 每步覆写）
 *   0x0cc         4   0                   1995d4 / 199694                             direction
 *   0x0d0         4   0                   1995d8 / 199698                             speed
 *   0x0d4         4   0                   1995e4 / 1996a4                             friction
 *   0x0d8         4   270.0f              1995e8 / 1996cc                             gravity_direction（全部初值里唯一的非零默认）
 *   0x0dc         4   0                   1995ec / 1996a8                             gravity
 *   0x0e0         4   0                   1995dc / 19969c                             hspeed
 *   0x0e4         4   0                   1995e0 / 1996a0                             vspeed
 *   0x0e8         4   0                   199724                                      未定
 *   0x0ec         4   0                   19972c                                      未定
 *   0x0f0         4   0                   199728                                      未定
 *   0x0f4         4   0                   199720                                      未定
 *   0x0f8..0x124  48  -1（12 项）         1995f4（先 0）→ 1996d4（后 -1）             alarm[0..11]（GetTimer/SetTimer 0x193134/0x193148 证明基址/项宽/上界）
 *   0x128         4   -1                  199624 / 199714                             path_index
 *   0x12c         4   0                   199620 / 1996f8                             path_position
 *   0x130         4   0                   199628 / 1996fc                             path_positionprevious
 *   0x134         4   0                   199630 / 199700                             path_speed
 *   0x138         4   1.0f                199638 / 199738                             path_scale
 *   0x13c         4   0                   199640 / 199704                             path_orientation
 *   0x140         4   0                   19962c / 199740                             path_endaction
 *   0x144         4   （不写，恒 0）      —                                           疑似 CPath*；new 已清零，本函数与基类都不碰
 *   0x148         4   （不写，恒 0）      —                                           疑似 CTimeline*；同上
 *   0x14c         4   -1                  199634 / 199718                             timeline_index
 *   0x150         4   0                   199648 / 199708                             未定（与 timeline 区相邻）
 *   0x154         4   0                   199650 / 19970c                             timeline_position
 *   0x158         4   1.0f                199658 / 19973c                             timeline_speed
 *   0x15c         1   0                   19963c                                      timeline_running
 *   0x15d         1   0                   199644                                      timeline_loop
 *   0x15e         1   0                   199750                                      未定
 *   0x160         4   0                   199618 / 199744                             未定（CInstance::Assign/Serialise 处理）
 *   0x164         4   0                   19961c / 199748                             未定（同上）
 *   0x168         4   0                   19974c                                      未定（ChangeObjectIndex/RelinkObjectTypes 读写）
 *   0x16c         4   2                   199758                                      未定（本函数唯一一处写 2；HandleEnter 读）
 *   0x170         4   -1                  19971c                                      layer（GV_Layer；-1 = 按 depth 归层）
 *   0x174         1   0                   199754                                      未定（GV_Layer 先读它，形似「显式层号有效」）
 *   0x180         4   0 → 对象深度        199590（清零）/ 0x193334（覆写）            depth（GV_Depth；SetObjectIndex 用 (float)(int)obj+8）
 *   0x184         4   0                   199594                                      未定（CRoom::AddInstance/RelinkObjectTypes 读）
 *   0x188         4   -1                  199538                                      碰撞相关标量（collisionResult 0x1cbf64 / HandleCollision 0x1cc948 读写；-1 形似「未入表」哨兵，语义未定）
 *   0x18c         4   this+0x18c          199540                                      碰撞测试链表 link.next（自环 = 空链；链上存的是 link 字段地址 this+0x18c）
 *   0x190         4   this+0x18c          199548                                      碰撞测试链表 link.prev（同上）
 *   0x194         4   0                   199564                                      所属碰撞测试链表头（0 = 未挂链；CollisionMarkTest 0x1cbfdc..0x1cc024 摘/挂链）
 *   0x198         4   this+0x198          199558                                      碰撞脏表 link.next（CollisionMarkDirty/UpdateTree）
 *   0x19c         4   this+0x198          19955c                                      碰撞脏表 link.prev
 *   0x1a0         4   0                   199568                                      所属碰撞脏表链表头（0 = 未挂链；CollisionMarkDirty 0x1cc1ec 起同构）
 *   0x1a4         4   this+0x1a4          199570                                      句柄链 link.next（HandleInstance/InstanceHandled/IterateInstances）
 *   0x1a8         4   this+0x1a4          199574                                      句柄链 link.prev
 *   0x1ac         4   0                   19956c                                      所属句柄链表头（0 = 未挂链；HandleInstance 0xd3fd8..0xd401c 同构）
 *   合计覆盖 0x00..0x1ac；sizeof=0x1B0（+0x1b0 起是下一个对象）。
 *   本函数不写：0x04/0x08/0x0c/0x18/0x1c/0x20/0x24/0x28/0x2c/0x30/0x34/0x38/0x3c/0x40/0x4c/0x50..0x60
 *   （基类写区，见下）、0x64/0x65/0x66/0x67/0x7c/0x8c/0xac（SetObjectIndex 写，见下）、
 *   0x144/0x148/0x178/0x17c（谁都不写 ⇒ 保持 0；0x178/0x17c 是房间步进/绘制链的 next，由 CRoom 挂链时填）。
 *
 * ── 基类 YYObjectBase::YYObjectBase(int,int) 0x19188c 的写区（不在本卡锚点内）─────────
 *   本函数传 (r1 = *(int*)0x544b48, r2 = 0x00FFFFFF)：
 *     +0x00 = 基类 vtable（随后被本函数覆盖成 0x3EBAF8）
 *     +0x04 = 0；+0x18 = 0；+0x1c = 0；+0x20 = 0；+0x24 = arg1；+0x28 = 1；+0x2c = arg1；
 *     +0x30 = 0；+0x34 = 全局指针；+0x38 = 0；+0x3c = 同一全局指针；+0x44 = -1（本函数随后改成槽号）；
 *     +0x48 = 0（本函数收尾改成 1）；+0x4c = 0；+0x58 = arg2（0x00FFFFFF）；+0x60 = 0
 *     +0x10/+0x14 = 0 或 {MemoryManager::GetStackTrace(), vmGetCallStack()}（取决于一个全局字节）
 *   ⇒ +0x24 就是任务里说的 count；它与 +0x2c 同源，属基类哈希/变量容器的字段，语义归 YYObjectBase 专卡。
 *
 * ── SetObjectIndex(int,bool) 0x19324c 的副作用（本函数 0x199660 唯一的 bl）──────────
 *   本函数传 (objindex = [sp+0x30], addToObject = [sp+0x34])：
 *     0x7c ← objindex（0x193260）；objindex == -1 时改存 0（0x19328c）
 *     0x80 ← 0（0x193280 先清，之后查表）；查到 → CObjectGM*（0x1932f0）；查不到 → 0（0x1932e0）
 *     查到对象时（0x193300 起）：0xac ← obj+0x10；0x65 ← objflags bit1（visible）；
 *       0x66 ← bit0（solid）；0x67 ← bit2（persistent）；0x180 ← (float)(int)obj+0x08（depth）；
 *       0x8c ← SetSpriteIndex(obj+0x04)；0x64 ← 1；尾调 CollisionMarkDirty
 *     addToObject != 0 → 先 CObjectGM::AddInstance(this)（0x193350..0x193358）
 *   因为 0x80 已被本函数在 0x19964c 清零，SetObjectIndex 里的 RemoveInstance 分支必然不跑。
 *   ★ 构造契约：objindex 必须能在全局对象表里查到。查不到时 0x64/0x65/0x66/0x67/0x8c/0xac/0x180
 *     这条链一次都不写（保持 new 的 0）—— 实例会"不可见/无精灵/无深度"，且不报错。
 *
 * ── 四张全局表/常量（literal pool 0x1998c0..0x1998dc 逐字解出）────────────────────
 *   0x1998c0 0x0025875c → 0x1994fc + 该值 = 0x3F1C58  GOT 基址（本函数所有 [r8,rX] 的基）
 *   0x1998c4 0xffffc0c4 → 0x3EDD1C → 0x544b48        基类第 1 实参来源（.bss 无符号名）
 *   0x1998c8 0xffffdeb4 → 0x3EFB0C → 0x536f20        ms_CurrentCreateCounter（8B，.dynsym 无名，按 live-oracle §3.3 记）
 *   0x1998cc 0xffffea3c → 0x3F0694 → 0x3EBAF0        vtable 头；+8 = 0x3EBAF8 才是 this[0]
 *   0x1998d0 0xffffc014 → 0x3EDC6C → 0x536f0c        全局实例表 {base, cap, count, next_free}
 *   0x1998d4 0xffffbf68 → 0x3EDBC0 → 0x47f295        内建属性注册开关（byte）
 *   0x1998d8 0xffffbfe4 → 0x3EDC3C → 0x753108        内建属性表 count
 *   0x1998dc 0xffffbfe8 → 0x3EDC40 → 0x75310c        内建属性表基址（16B 项）
 *
 * ── 已证（指令级，每条都能落到锚点）──────────────────────────────────────
 *  1. vtable = 0x3EBAF8：该地址起依次 0x199320（~CInstance D1/D2）、0x1993f8（D0）、
 *     0x197fac（YYObjectBase::InternalGetYYVarRef）、0、0x3ED068、0x35DD00（文件内实测字）。
 *  2. alarm 就是 0xf8 起的 12 个 int：GetTimer 0x193134 = `i<=11 ? [this+ (i+62)*4] : -1`，
 *     SetTimer 0x193148 同址写；本函数用两个 12 次循环先清 0 再填 -1。
 *  3. 运动学默认值唯一非零是 +0xd8 = 0x43870000 = 270.0f（gravity_direction）。GV_* 逐字段同址：
 *     direction 0xcc / speed 0xd0 / friction 0xd4 / gravity_direction 0xd8 / gravity 0xdc /
 *     hspeed 0xe0 / vspeed 0xe4；位置组 x 0xb4 / y 0xb8 / xstart 0xbc / ystart 0xc0 /
 *     xprevious 0xc4 / yprevious 0xc8；图像组 image_index 0x90 / speed 0x94 / xscale 0x98 /
 *     yscale 0x9c / angle 0xa0 / alpha 0xa4 / blend 0xa8。
 *  4. 实参落位：r11=x、r9=y、r10=id → +0xb4/+0xb8/+0x78；[sp+0x30]=objindex 与 [sp+0x34]=bool
 *     进 SetObjectIndex。CRoom::AddInstance 0x1ab16c 把 ++room_maxid 放 r3 ⇒ 第 3 实参是 id。
 *     （live-oracle-registrations §3.3 的 "CInstance(x,y,objindex,id,true)" 是行文顺序；寄存器落位以本卡为准）
 *  5. 全局实例表 0x536f0c：+0x00 base、+0x04 cap、+0x08 count、+0x0c next_free。
 *     插入 = 从 next_free 起环形找第一个 0 槽（最多 cap 次，槽内写 this），count++，槽号进 +0x44；
 *     count >= cap 时走冷路径 0x19987c：newcap = cap*3/2（(3*cap + 进位) >> 1），
 *     YYRealloc(base, newcap*4) + memset(新段) + 写回 base/cap，再回 0x199770 重扫。
 *     cap<=0 时槽号 = -1（仍 count++）—— 这是唯一"入表失败"的分支。
 *  6. 析构反向证据：0x1993a4 读 +0x44 当 base 数组下标清 0，0x1993c4 写回 -1，0x1993cc/0x1993d4
 *     把 next_free 退到 min(next_free, slot)，count--。
 *  7. 三段自环：0x18c/0x190、0x198/0x19c、0x1a4/0x1a8 都写成 this+自身（空链）；三个"属主"字段
 *     0x194/0x1a0/0x1ac 写 0。跨函数看得很清楚：CollisionMarkTest 0x1cbfdc..0x1cc024 先比
 *     [this+0x194] 与全局链表头、相等才摘链，再把 this+0x18c 挂到表头并把 [this+0x194] 置成表头；
 *     CollisionMarkDirty 0x1cc1ec 对 0x198/0x19c/0x1a0 做同一套；HandleInstance 0xd3fd8 对
 *     0x1a4/0x1a8/0x1ac 做同一套 ⇒ 三段都是「侵入式双链 + 属主指针」，构造期自环即空链。
 *     链上存的是 link 字段地址（表头 next 指向 this+0x18c，而不是 this）。
 *  8. 内建属性注册：开关 byte 0x47f295；count = *(int*)0x753108；项 = 0x75310c + 16*i，
 *     布局 {+0 name, +4 getter, +8 setter, +0xc 本循环不读}。跳过 isGlobalBuiltinVar(name) 为真的项，
 *     其余 JS_SetupBuiltinProperty(getter,setter) → YYObjectBase::Add(name, PS, 1)。
 *     循环游标 r4 = 项+8：ldr r0,[r4,#-8] 取 name；ldmda r4,{r0,r1}（W=0，不回写）读 +4/+8；
 *     add r4,#16 后 ldr r1,[r4,#-0x18] 恰好又落在本项 +0 的 name 上。
 *  9. 收尾：0x199864 mov r0,r6（返回 this）、+0x48=1、+0x10=0、+0x14=0；
 *     0x199878 pop {r4-r11,pc} 一次性返回。
 * 10. 全函数 7 个 bl：基类 0x19188c、SetObjectIndex 0x19324c、isGlobalBuiltinVar 0x23f8f0、
 *     JS_SetupBuiltinProperty 0x23ffac、YYObjectBase::Add 0x19946c、YYRealloc 0xcef64、memset@plt 0xb65b0；
 *     无 blx/虚调用、无异常表引用。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. +0x48：基类置 0、本函数置 1，本卡与相邻的构造/析构路径都找不到读取点（可能只被 GC/反射用）。语义未定。
 *  2. +0x6b / +0x6c 两个 byte、+0xe8..+0xf4 四个 float：本函数清零后无人读，用途未定。
 *  3. +0x150 / +0x15e / +0x160 / +0x164 / +0x168 / +0x174 / +0x184：CInstance::Serialise(0x197284)/
 *     DeSerialise(0x197c80)/Assign(0x198bb8) 会访问这些偏移，但语义名未定；+0x16c 被写成 2
 *     （全函数唯一的 2），HandleEnter 读它，含义未定。
 *  4. +0x144 / +0x148：夹在 path_endaction 与 timeline_index 之间，形似 CPath*/CTimeline*，
 *     但本函数与基类都不写 ⇒ 构造后恒 0；谁在何时赋值未证。
 *  5. 基类第 1 实参 *(int*)0x544b48 的名字与用途，以及 ms_CurrentCreateCounter 的计数语义（创建序号/时间戳），
 *     都要在 YYObjectBase/CRoom 侧另开卡。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────────────────
 */

/* ── 1. 入口：5 个实参落位 + GOT 基址/常量（x→r11、y→r9、id→r10、objindex→[sp+0x30]、bool→[sp+0x34]）（0x1994dc..0x19951c）── */
/* @0x1994dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1994e0 mov r11, r1 */
/* @0x1994e4 ldr r8, [pc, #0x3d4] */
/* @0x1994e8 sub sp, sp, #12 */
/* @0x1994ec ldr r1, [pc, #0x3d0] */
/* @0x1994f0 mov r10, r3 */
/* @0x1994f4 add r8, pc, r8 */
/* @0x1994f8 ldrb r3, [sp, #0x34] */
/* @0x1994fc mov r9, r2 */
/* @0x199500 mvn r2, #-16777216 */
/* @0x199504 ldr r1, [r8, r1] */
/* @0x199508 mov r6, r0 */
/* @0x19950c ldr r5, [pc, #0x3b4] */
/* @0x199510 mvn r4, #0 */
/* @0x199514 mov r7, #12 */
/* @0x199518 ldr r1, [r1] */
/* @0x19951c str r3, [sp, #0x4] */
/* ── 2. 基类 YYObjectBase(int,int)：r1 = *(0x544b48)、r2 = 0x00FFFFFF（0x199520）────────────── */
/* @0x199520 bl 0x19188c <_ZN12YYObjectBaseC2Eii> */
/* ── 3. vtable + 三段自环链表哨兵 + 三个配套标量（0x199524..0x199574）────────────────── */
/* @0x199524 ldr r1, [pc, #0x3a0] */
/* @0x199528 mov lr, #0 */
/* @0x19952c add r2, r6, #396 */
/* @0x199530 ldr r0, [r8, r1] */
/* @0x199534 add r1, r6, #408 */
/* @0x199538 str r4, [r6, #0x188] */
/* @0x19953c add r4, r6, #420 */
/* @0x199540 str r2, [r6, #0x18c] */
/* @0x199544 add r0, r0, #8 */
/* @0x199548 str r2, [r6, #0x190] */
/* @0x19954c mov r2, r6 */
/* @0x199550 str r0, [r6] */
/* @0x199554 mov r0, lr */
/* @0x199558 str r1, [r6, #0x198] */
/* @0x19955c str r1, [r6, #0x19c] */
/* @0x199560 mov r1, #0 */
/* @0x199564 str lr, [r6, #0x194] */
/* @0x199568 str lr, [r6, #0x1a0] */
/* @0x19956c str lr, [r6, #0x1ac] */
/* @0x199570 str r4, [r6, #0x1a4] */
/* @0x199574 str r4, [r6, #0x1a8] */
/* ── 4. 创建计数快照（ldrd/strd 8 字节）+ 第一批清零：位置/图像/运动学/链指针（0x199578..0x1995ec）── */
/* @0x199578 ldr r4, [r8, r5] */
/* @0x19957c str r1, [r6, #0xb4] */
/* @0x199580 str lr, [r6, #0x78] */
/* @0x199584 ldrd r4, r5, [r4] */
/* @0x199588 str r1, [r6, #0xb8] */
/* @0x19958c strb lr, [r6, #0x6b] */
/* @0x199590 str r1, [r6, #0x180] */
/* @0x199594 str r1, [r6, #0x184] */
/* @0x199598 strb lr, [r6, #0x6c] */
/* @0x19959c str r1, [r6, #0x90] */
/* @0x1995a0 strb lr, [r6, #0x6a] */
/* @0x1995a4 str r1, [r6, #0x94] */
/* @0x1995a8 str lr, [r6, #0xa8] */
/* @0x1995ac str r1, [r6, #0x98] */
/* @0x1995b0 strd r4, r5, [r6, #112] */
/* @0x1995b4 str r1, [r6, #0x9c] */
/* @0x1995b8 str r1, [r6, #0xa0] */
/* @0x1995bc str r1, [r6, #0xa4] */
/* @0x1995c0 str r1, [r6, #0xbc] */
/* @0x1995c4 str r1, [r6, #0xc0] */
/* @0x1995c8 str r1, [r6, #0xc4] */
/* @0x1995cc str r1, [r6, #0xc8] */
/* @0x1995d0 ldr r3, [sp, #0x4] */
/* @0x1995d4 str r1, [r6, #0xcc] */
/* @0x1995d8 str r1, [r6, #0xd0] */
/* @0x1995dc str r1, [r6, #0xe0] */
/* @0x1995e0 str r1, [r6, #0xe4] */
/* @0x1995e4 str r1, [r6, #0xd4] */
/* @0x1995e8 str r1, [r6, #0xd8] */
/* @0x1995ec str r1, [r6, #0xdc] */
/* ── 5. alarm 第一遍：12 个槽清 0（r7 从 12 递减，游标 r2 从 this 起每轮 +4）（0x1995f0..0x1995fc）── */
/* @0x1995f0 subs r7, r7, #1 */
/* @0x1995f4 str r0, [r2, #0xf8] */
/* @0x1995f8 add r2, r2, #4 */
/* @0x1995fc bne 0x1995f0 <_ZN9CInstanceC2Effiib+0x114> */
/* ── 6. 第二批：闸门字节/路径/时间线/对象指针清零，并把 (objindex,bool) 排到 SetObjectIndex 的 r1/r2（0x199600..0x19965c）── */
/* @0x199600 mov r4, #0 */
/* @0x199604 mov r2, r3 */
/* @0x199608 ldr r1, [sp, #0x30] */
/* @0x19960c mov r0, r6 */
/* @0x199610 strb r7, [r6, #0x68] */
/* @0x199614 strb r7, [r6, #0x69] */
/* @0x199618 str r7, [r6, #0x160] */
/* @0x19961c str r7, [r6, #0x164] */
/* @0x199620 str r4, [r6, #0x12c] */
/* @0x199624 str r7, [r6, #0x128] */
/* @0x199628 str r4, [r6, #0x130] */
/* @0x19962c str r7, [r6, #0x140] */
/* @0x199630 str r4, [r6, #0x134] */
/* @0x199634 str r7, [r6, #0x14c] */
/* @0x199638 str r4, [r6, #0x138] */
/* @0x19963c strb r7, [r6, #0x15c] */
/* @0x199640 str r4, [r6, #0x13c] */
/* @0x199644 strb r7, [r6, #0x15d] */
/* @0x199648 str r4, [r6, #0x150] */
/* @0x19964c str r7, [r6, #0x80] */
/* @0x199650 str r4, [r6, #0x154] */
/* @0x199654 str r7, [r6, #0x84] */
/* @0x199658 str r4, [r6, #0x158] */
/* @0x19965c str r7, [r6, #0x88] */
/* ── 7. SetObjectIndex(objindex, addToObject)：唯一的对象解析调用（0x199660）─────────────── */
/* @0x199660 bl 0x19324c <_ZN9CInstance14SetObjectIndexEib> */
/* ── 8. 图像/位置/id/start/previous/blend/gravity_direction + alarm 第二遍 -1（0x199664..0x1996e4）── */
/* @0x199664 mov r3, r6 */
/* @0x199668 mvn r1, #0 */
/* @0x19966c mov r2, #1065353216 */
/* @0x199670 mov r0, #0 */
/* @0x199674 str r2, [r6, #0x94] */
/* @0x199678 str r2, [r6, #0x98] */
/* @0x19967c movt r0, #0x4387 */
/* @0x199680 str r2, [r6, #0x9c] */
/* @0x199684 str r2, [r6, #0xa4] */
/* @0x199688 mvn r2, #-16777216 */
/* @0x19968c str r4, [r6, #0x90] */
/* @0x199690 str r4, [r6, #0xa0] */
/* @0x199694 str r4, [r6, #0xcc] */
/* @0x199698 str r4, [r6, #0xd0] */
/* @0x19969c str r4, [r6, #0xe0] */
/* @0x1996a0 str r4, [r6, #0xe4] */
/* @0x1996a4 str r4, [r6, #0xd4] */
/* @0x1996a8 str r4, [r6, #0xdc] */
/* @0x1996ac str r11, [r6, #0xb4] */
/* @0x1996b0 str r9, [r6, #0xb8] */
/* @0x1996b4 str r10, [r6, #0x78] */
/* @0x1996b8 str r11, [r6, #0xbc] */
/* @0x1996bc str r9, [r6, #0xc0] */
/* @0x1996c0 str r11, [r6, #0xc4] */
/* @0x1996c4 str r9, [r6, #0xc8] */
/* @0x1996c8 str r2, [r6, #0xa8] */
/* @0x1996cc str r0, [r6, #0xd8] */
/* @0x1996d0 add r7, r7, #1 */
/* @0x1996d4 str r1, [r3, #0xf8] */
/* @0x1996d8 cmp r7, #12 */
/* @0x1996dc add r3, r3, #4 */
/* @0x1996e0 mvn r2, #0 */
/* @0x1996e4 bne 0x1996d0 <_ZN9CInstanceC2Effiib+0x1f4> */
/* ── 9. 第三批：path/timeline/layer 终值（含 1.0f 两处、-1 三处、+0x16c=2）（0x1996e8..0x199758）── */
/* @0x1996e8 ldr r0, [pc, #0x1e0] */
/* @0x1996ec mov r4, #0 */
/* @0x1996f0 mov r3, #0 */
/* @0x1996f4 mov r1, #1065353216 */
/* @0x1996f8 str r3, [r6, #0x12c] */
/* @0x1996fc str r3, [r6, #0x130] */
/* @0x199700 str r3, [r6, #0x134] */
/* @0x199704 str r3, [r6, #0x13c] */
/* @0x199708 str r3, [r6, #0x150] */
/* @0x19970c str r3, [r6, #0x154] */
/* @0x199710 mov r3, #2 */
/* @0x199714 str r2, [r6, #0x128] */
/* @0x199718 str r2, [r6, #0x14c] */
/* @0x19971c str r2, [r6, #0x170] */
/* @0x199720 str r4, [r6, #0xf4] */
/* @0x199724 str r4, [r6, #0xe8] */
/* @0x199728 str r4, [r6, #0xf0] */
/* @0x19972c str r4, [r6, #0xec] */
/* @0x199730 strb r4, [r6, #0x68] */
/* @0x199734 strb r4, [r6, #0x69] */
/* @0x199738 str r1, [r6, #0x138] */
/* @0x19973c str r1, [r6, #0x158] */
/* @0x199740 str r4, [r6, #0x140] */
/* @0x199744 str r4, [r6, #0x160] */
/* @0x199748 str r4, [r6, #0x164] */
/* @0x19974c str r4, [r6, #0x168] */
/* @0x199750 strb r4, [r6, #0x15e] */
/* @0x199754 strb r4, [r6, #0x174] */
/* @0x199758 str r3, [r6, #0x16c] */
/* ── 10. 全局实例表插入：count>=cap 走冷路径；否则从 next_free 环形找空槽（0x19975c..0x1997d0）──
 *    表 = 0x536f0c：+0 base、+4 cap、+8 count、+0xc next_free；找到后 table[slot]=this、next_free=slot、
 *    count++、this+0x44=slot。cap<=0 时 slot=-1（0x1997c0），count 照样 ++。
 */
/* @0x19975c ldr r5, [r8, r0] */
/* @0x199760 ldr r7, [r5, #0x8] */
/* @0x199764 ldr r12, [r5, #0x4] */
/* @0x199768 cmp r7, r12 */
/* @0x19976c bge 0x19987c <_ZN9CInstanceC2Effiib+0x3a0> */
/* @0x199770 cmp r12, #0 */
/* @0x199774 ldr r3, [r5, #0xc] */
/* @0x199778 ble 0x1997c0 <_ZN9CInstanceC2Effiib+0x2e4> */
/* @0x19977c ldr r0, [r5] */
/* @0x199780 mov r1, r12 */
/* @0x199784 b 0x199794 <_ZN9CInstanceC2Effiib+0x2b8> */
/* @0x199788 subs r1, r1, #1 */
/* @0x19978c add r3, r3, #1 */
/* @0x199790 beq 0x1997c0 <_ZN9CInstanceC2Effiib+0x2e4> */
/* @0x199794 cmp r12, r3 */
/* @0x199798 lsl r2, r3, #2 */
/* @0x19979c movle r3, #0 */
/* @0x1997a0 movle r2, r3 */
/* @0x1997a4 add r4, r0, r2 */
/* @0x1997a8 ldr r2, [r0, r2] */
/* @0x1997ac cmp r2, #0 */
/* @0x1997b0 bne 0x199788 <_ZN9CInstanceC2Effiib+0x2ac> */
/* @0x1997b4 str r6, [r4] */
/* @0x1997b8 str r3, [r5, #0xc] */
/* @0x1997bc b 0x1997c4 <_ZN9CInstanceC2Effiib+0x2e8> */
/* @0x1997c0 mvn r3, #0 */
/* @0x1997c4 ldr r2, [pc, #0x108] */
/* @0x1997c8 add r7, r7, #1 */
/* @0x1997cc str r3, [r6, #0x44] */
/* @0x1997d0 str r7, [r5, #0x8] */
/* ── 11. 内建属性注册（开关 0x47f295 / count 0x753108 / 项 0x75310c 起 16B）（0x1997d4..0x199858）──
 *    每项：+0 name、+4 getter、+8 setter；跳过 isGlobalBuiltinVar(name) 为真的项，其余
 *    JS_SetupBuiltinProperty(getter,setter) → YYObjectBase::Add(name, PS, 1)。
 *    游标 r4 = 项+8；ldmda 是 W=0（不回写），所以 add r4,#16 后 [r4-0x18] 正好是本项 +0 的 name。
 */
/* @0x1997d4 ldr r3, [r8, r2] */
/* @0x1997d8 ldrb r3, [r3] */
/* @0x1997dc cmp r3, #0 */
/* @0x1997e0 beq 0x19985c <_ZN9CInstanceC2Effiib+0x380> */
/* @0x1997e4 ldr r3, [pc, #0xec] */
/* @0x1997e8 ldr r7, [r8, r3] */
/* @0x1997ec ldr r3, [r7] */
/* @0x1997f0 cmp r3, #0 */
/* @0x1997f4 ble 0x19985c <_ZN9CInstanceC2Effiib+0x380> */
/* @0x1997f8 ldr r3, [pc, #0xdc] */
/* @0x1997fc mov r5, #0 */
/* @0x199800 ldr r4, [r8, r3] */
/* @0x199804 add r4, r4, #8 */
/* @0x199808 b 0x19981c <_ZN9CInstanceC2Effiib+0x340> */
/* @0x19980c ldr r3, [r7] */
/* @0x199810 add r4, r4, #16 */
/* @0x199814 cmp r3, r5 */
/* @0x199818 ble 0x19985c <_ZN9CInstanceC2Effiib+0x380> */
/* @0x19981c ldr r0, [r4, #-0x8] */
/* @0x199820 add r5, r5, #1 */
/* @0x199824 bl 0x23f8f0 <_Z18isGlobalBuiltinVarPKc> */
/* @0x199828 cmp r0, #0 */
/* @0x19982c bne 0x19980c <_ZN9CInstanceC2Effiib+0x330> */
/* @0x199830 ldmda r4, {r0, r1} */
/* @0x199834 add r4, r4, #16 */
/* @0x199838 bl 0x23ffac <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_> */
/* @0x19983c ldr r1, [r4, #-0x18] */
/* @0x199840 mov r3, #1 */
/* @0x199844 mov r2, r0 */
/* @0x199848 mov r0, r6 */
/* @0x19984c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x199850 ldr r3, [r7] */
/* @0x199854 cmp r3, r5 */
/* @0x199858 bgt 0x19981c <_ZN9CInstanceC2Effiib+0x340> */
/* ── 12. 收尾：+0x48=1、创建栈 +0x10/+0x14 清零、r0=this、pop 返回（0x19985c..0x199878）────────── */
/* @0x19985c mov r3, #0 */
/* @0x199860 mov r2, #1 */
/* @0x199864 mov r0, r6 */
/* @0x199868 str r2, [r6, #0x48] */
/* @0x19986c str r3, [r6, #0x10] */
/* @0x199870 str r3, [r6, #0x14] */
/* @0x199874 add sp, sp, #12 */
/* @0x199878 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 13. 冷路径：实例表扩容（cap*3/2 + YYRealloc + memset 新段），跳回 0x199770 重扫（0x19987c..0x1998bc）──
 *    0x19987c 是 0x19976c bge 的目标；0x1998bc b 0x199770。这段在函数体末尾、主流程 ret 之后，
 *    只有 count>=cap 时才进来，所以读代码时必须先看 0x19976c 的条件。
 */
/* @0x19987c add r12, r12, r12, lsl #1 */
/* @0x199880 ldr r0, [r5] */
/* @0x199884 add r12, r12, r12, lsr #31 */
/* @0x199888 asr r7, r12, #1 */
/* @0x19988c lsl r1, r7, #2 */
/* @0x199890 bl 0xcef64 <_Z9YYReallocPvi> */
/* @0x199894 ldr r3, [r5, #0x4] */
/* @0x199898 mov r1, r4 */
/* @0x19989c rsb r2, r3, r7 */
/* @0x1998a0 lsl r2, r2, #2 */
/* @0x1998a4 str r0, [r5] */
/* @0x1998a8 add r0, r0, r3, lsl #2 */
/* @0x1998ac bl 0xb65b0 <memset@plt> */
/* @0x1998b0 str r7, [r5, #0x4] */
/* @0x1998b4 mov r12, r7 */
/* @0x1998b8 ldr r7, [r5, #0x8] */
/* @0x1998bc b 0x199770 <_ZN9CInstanceC2Effiib+0x294> */
/* ── 14. literal pool（8 字；首字被反汇编器译成 eoreq，其余 7 字显示为 .word，全部是数据）────────
 *   0x1998c0 = 0x0025875c → GOT 基址 0x3F1C58      0x1998c4 = 0xffffc0c4 → 0x3EDD1C → 0x544b48
 *   0x1998c8 = 0xffffdeb4 → 0x3EFB0C → 0x536f20      0x1998cc = 0xffffea3c → 0x3F0694 → 0x3EBAF0
 *   0x1998d0 = 0xffffc014 → 0x3EDC6C → 0x536f0c      0x1998d4 = 0xffffbf68 → 0x3EDBC0 → 0x47f295
 *   0x1998d8 = 0xffffbfe4 → 0x3EDC3C → 0x753108      0x1998dc = 0xffffbfe8 → 0x3EDC40 → 0x75310c
 */
/* @0x1998c0 eoreq r8, r5, r12, asr r7 */
/* @0x1998c4 .word 0xffffc0c4 */
/* @0x1998c8 .word 0xffffdeb4 */
/* @0x1998cc .word 0xffffea3c */
/* @0x1998d0 .word 0xffffc014 */
/* @0x1998d4 .word 0xffffbf68 */
/* @0x1998d8 .word 0xffffbfe4 */
/* @0x1998dc .word 0xffffbfe8 */
