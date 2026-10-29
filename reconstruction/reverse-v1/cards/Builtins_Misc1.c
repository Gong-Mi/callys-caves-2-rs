/*
 * cally 逆向卡：游戏内建 API 第一批 14 个（原版 libyoyo.so，armv7）
 * 节: 14 个 @func 小节，顺序 = motion_set / object_exists / action_bounce / part_type_create /
 *     part_type_shape / part_type_alpha1 / part_system_create / display_get_width / display_get_height /
 *     window_get_width / window_get_height / audio_stop_sound / ini_close / ini_open
 * 级别: 正文（174/174 逐条落锚 = 173 条指令 + 1 个池字；14 个函数的入参下标、result 编码、门、尾跳
 *       全部逐条解出；被调方只到调用边界，库内未展开的部分逐条列进 open）
 * 索引: asm/index-builtins_misc1_all.tsv（14 个函数按地址合并，174 行）
 *       逐函数索引 asm/index-F_*.tsv 也在库里（同 14 个函数，各是本文件的子集）；本卡只用合并索引校验。
 * 重叠: 0 —— 本卡 14 个区间与 cards/ 下任何既存卡无共享地址；本批不存在 F_InstanceDestroy 式的同址重复。
 *
 * ── 统一签名（14 个一模一样）───────────────────────────────────────────────
 *   F_Xxx(RValue& result, CInstance* self, CInstance* other, int argc, RValue** args)
 *   r0 = &result、r1 = self、r2 = other、r3 = argc、[sp] = args。
 *   取参一律 YYGetFloat / YYGetInt32 / YYGetString(const RValue*, int index)，下标是常量；
 *   **14 个里没有一个读 argc**，也没有一个读 other(r2)；self(r1) 只有 2 个读（motion_set、action_bounce）。
 *   帧量与 args 槽互证（push 寄存器数×4 = args 的栈偏移）：
 *     MotionSet 4×4=0x10｜ObjectExists 0x10｜ActionBounce 0x10｜PartTypeCreate 0x8（不取参）｜
 *     PartTypeShape 0x10｜PartTypeAlpha1 0x10｜PartSystemCreate 0x8（不取参）｜DisplayGetWidth/Height 0x8（不取参）｜
 *     WindowGetWidth/Height 0x8（不取参）｜AudioStopSound 0x8｜IniClose 0x8（不取参）｜IniOpen 0x8。
 *   ⇒ 14 个函数共 **21 条 bl**（YYGetFloat 3 + YYGetInt32 5 + YYGetBool 2 + YYGetString 1 + 被调方 10）
 *     与 7 条 b —— 7 条 b 全是尾跳（0x10855c / 0x12900c / 0x129654 / 0x13e024 / 0x134dfc / 0x13ba04 / 0x13bb30）。
 *
 * ── RValue 侧 ─────────────────────────────────────────────────────────────
 *   载荷 +0x00..+0x07（双精度），tag 在 +0x0c。7 个写数值结果的函数都**先无条件**把 tag 清 0
 *   （str #0,[result,#0xc]）；ini_close 例外：结果交给 YYCreateString，tag 最终是 **1（string）**。
 *   6 个 s32→f64 的取字写法完全一致：vmov s15,r0 → vcvt.f64.s32 d7,s15 → vmov r0,r1,d7（高字进 r1）
 *   → vmov r2,s14（低字）→ mov r3,r1 → stm r4,{r2,r3}。object_exists 不用 vcvt，直接拼 0x3FF00000。
 *
 * ── 返回值精确编码（RESULT EXACT）──────────────────────────────────────────
 *   motion_set         : **不写** result（result 地址在第 2 条指令即被丢弃）
 *   object_exists      : 0.0 / 1.0（movtne r3,#0x3ff0，0x12e0fc；低字恒 0）
 *   action_bounce      : **不写** result（尾跳 Command_Bounce）
 *   part_type_create   : (double)(int) 新槽号（vcvt.f64.s32，0x128f58）
 *   part_type_shape    : **不写** result（尾跳 ParticleType_Shape）
 *   part_type_alpha1   : **不写** result（尾跳 ParticleType_Alpha1）
 *   part_system_create : (double)(int) 系统槽号；失败时 -1.0（vcvt.f64.s32，0x129750）
 *   display_get_width  : (double)(int) g_DeviceWidth（0x119bdc）
 *   display_get_height : (double)(int) g_DeviceHeight（0x119c0c）
 *   window_get_width   : (double)(int) g_DeviceWidth（0x11a5b4）
 *   window_get_height  : (double)(int) g_DeviceHeight（0x11a5e4）
 *   audio_stop_sound   : **不写** result（尾跳 Audio_StopSound）
 *   ini_close          : **字符串**（YYCreateString → tag 1，0x13b9f8）
 *   ini_open           : **不写** result（尾跳 YYGML_ini_open）
 *   ⇒ 8 写 / 6 不写；8 个里 6 个是 int→double、1 个是 0/1 double、1 个是 string。
 *
 * ── 全局与表（全部由池字/GOT 两级解析 + .dynsym 实测）──────────────────────────
 *   g_ObjectHash   0x3edc44 → 0x542374（指针变量 → {+0 桶数组, +4 掩码}）  object_exists
 *   ptcount        0x542468（4 B 计数）、parttypes 0x54246c（{+0 len, +4 items=0x542470}）
 *                  particle 三函数；与 cards/Builtins_AudioPart.c 的 cARRAY 记法同源
 *   g_fNoAudio     0x755363（GOT 0x3ef054）  audio_stop_sound 的门
 *   g_IniFile      0x483720（GOT 0x3ef29c）  ini_close / ini_open 共用
 *   g_DeviceWidth  0x3f26c0（初值 0x400=1024）、g_DeviceHeight 0x3f26bc（初值 0x300=768）
 *                  GOT 0x3efea4 / 0x3efea8 —— display 与 window 四个 wrapper 只有这两个槽
 *
 * ── 注册形态（14 个同一形状，已扫描证实）──────────────────────────────────
 *   对 .text 全量扫 B/BL：14 个入口地址**没有任何一条 b/bl 指向**；对 .got(0x3ed718..0x3f2000) 扫 4 字节值：
 *   每个入口恰有 1 个槽命中 —— MotionSet 0x3ee10c｜ObjectExists 0x3eef68｜ActionBounce 0x3ef440｜
 *   PartTypeCreate 0x3eec60｜PartTypeShape 0x3eec70｜PartTypeAlpha1 0x3eecb4｜PartSystemCreate 0x3eecc4｜
 *   DisplayGetWidth 0x3ee5f0｜DisplayGetHeight 0x3ee5f4｜WindowGetWidth 0x3ee6c4｜WindowGetHeight 0x3ee6c8｜
 *   AudioStopSound 0x3ef134｜IniClose 0x3ef394｜IniOpen 0x3ef390。
 *   ⇒ 14 条都是经函数指针表（GOT 注册）被 VM 间接调用；同族槽位相邻，但 ini 两个槽的顺序与地址顺序相反
 *     （ini_open 0x3ef390 在 ini_close 0x3ef394 之前）—— 表项顺序由注册顺序决定，不是地址顺序。
 *
 * ── 逐条锚点（14 节）─────────────────────────────────────────────────────
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 1 · F_MotionSet（motion_set）
 * @func 0x108520 0x108560  size 64  16 条（无池字）
 * 符号: _Z11F_MotionSetR6RValueP9CInstanceS2_iPS_
 * 一句话: dir=YYGetFloat(args,0) → CInstance::SetDirection(self,dir)；spd=YYGetFloat(args,1)
 *         → 尾跳 CInstance::SetSpeed(self,spd)。result 一个字都不写，连它的地址都在第 2 条指令被丢弃。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 1.1 帧 16 字节 + 第一实参 → SetDirection（0x108520..0x108540）─────────────
 *   push {r3,r4,r5,lr}(16) ⇒ args 在 [sp,#0x10]（0x108528）。r4=self（r1 只在这一条被读）；
 *   0x108530 `mov r0,r5` 把入口的 result 指针覆盖掉 ⇒ **本函数此后没有任何一条指令能碰到 result**。
 *   0x10852c mov r1,#0 兼作 YYGetFloat 的下标；返回的 float 直接搬进 r1，r0=self 再 bl SetDirection。
 */
/* @0x108520 push {r3, r4, r5, lr} */
/* @0x108524 mov r4, r1 */
/* @0x108528 ldr r5, [sp, #0x10] */
/* @0x10852c mov r1, #0 */
/* @0x108530 mov r0, r5 */
/* @0x108534 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108538 mov r1, r0 */
/* @0x10853c mov r0, r4 */
/* @0x108540 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/*
 * ── 1.2 第二实参 + 尾跳 SetSpeed（0x108544..0x10855c）───────────────────────
 *   args[1]（下标 1）→ r0；0x108550 mov r1,r0、0x108554 mov r0,r4 摆成 (self, spd)；
 *   0x108558 pop 掉 4 个寄存器后 0x10855c `b` —— 不留帧、无返回后处理 ⇒ result 原封不动。
 */
/* @0x108544 mov r0, r5 */
/* @0x108548 mov r1, #1 */
/* @0x10854c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108550 mov r1, r0 */
/* @0x108554 mov r0, r4 */
/* @0x108558 pop {r3, r4, r5, lr} */
/* @0x10855c b 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/*
 * ── 1.3 两个被调方的写点（旁证，无锚点，地址已核）──────────────────────────
 *   CInstance::SetDirection(0x193064, 112 B) 写 inst+0xcc，并把角度归一化到 [0,360)
 *     （两条 while ±360.0f + fmodf 兜底，见 cards/CInstance_Setters.c §3/E），随后尾调 Compute_Speed2。
 *   CInstance::Compute_Speed2(0x192aa0, 264 B) 读 +0xcc(direction)/+0xd0(speed)，
 *     写 +0xe0(hspeed)=speed·cos(dir·π/180)、+0xe4(vspeed)=-speed·sin(…)（0x192aac..0x192af0），
 *     并对接近整数的分量做 lrint 修正。
 *   CInstance::SetSpeed(0x1930d4, 32 B) 先比 +0xd0 与新值：**相等就 bx lr**（0x1930e8），
 *     不等才写 +0xd0 并尾调 Compute_Speed2。
 *   ⇒ motion_set 的四个落点只有 (+0xcc, +0xd0, +0xe0, +0xe4)，不碰坐标；
 *     第二个 SetSpeed 在「新旧速度相等」时直接返回，此时 hspeed/vspeed 已由 SetDirection 那次重算过，
 *     所以 (dir, speed) 的调用顺序不影响最终值。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 2 · F_ObjectExists（object_exists）
 * @func 0x12e0cc 0x12e10c  size 64  16 条（无池字）
 * 符号: _Z14F_ObjectExistsR6RValueP9CInstanceS2_iPS_
 * 一句话: obj=YYGetInt32(args,0) → Object_Exists(obj)；非 0 ⇒ result=1.0，否则 0.0（tag 0）。
 *         不读 self / other / argc。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 2.1 帧 + tag 先清 0（0x12e0cc..0x12e0e4）─────────────────────────────
 *   push {r3,r4,r5,lr}(16) ⇒ args [sp,#0x10]。r5=0 是常量兼返回值低字；r4=result；
 *   0x12e0dc `str r5,[r0,#0xc]` 在**取参之前**就把 tag 清 0（r0 此时还是 &result）。
 *   0x12e0d8 mov r1,r5 把下标也置 0 —— 同一个寄存器先当 0 常量、再当下标。
 */
/* @0x12e0cc push {r3, r4, r5, lr} */
/* @0x12e0d0 mov r5, #0 */
/* @0x12e0d4 mov r4, r0 */
/* @0x12e0d8 mov r1, r5 */
/* @0x12e0dc str r5, [r0, #0xc] */
/* @0x12e0e0 ldr r0, [sp, #0x10] */
/* @0x12e0e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/*
 * ── 2.2 调用 + 1.0 的位模式（0x12e0e8..0x12e108）──────────────────────────
 *   YYGetInt32 的返回值直接在 r0 进 Object_Exists（中间不落栈）。cmp r0,#0 之后：
 *     r0!=0 → movne r3,r5(=0) + movtne r3,#0x3ff0 ⇒ 高字 0x3FF00000、低字 0 = **1.0**；
 *     r0==0 → moveq r3,r5 ⇒ 0 = **0.0**。
 *   0x12e100/0x12e104 两条 str 分别写 [result] 与 [result+4]。
 *   ⇒ 与 Builtins_Motion §6 的 mp_potential_step 是同一套「拼 0x3ff0」模板，不是 vcvt；
 *     低字恒 0 ⇒ 不会出现 -0.0。
 */
/* @0x12e0e8 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x12e0ec cmp r0, #0 */
/* @0x12e0f0 moveq r5, r0 */
/* @0x12e0f4 movne r3, r5 */
/* @0x12e0f8 moveq r3, r5 */
/* @0x12e0fc movtne r3, #0x3ff0 */
/* @0x12e100 str r5, [r4] */
/* @0x12e104 str r3, [r4, #0x4] */
/* @0x12e108 pop {r3, r4, r5, pc} */
/*
 * ── 2.3 Object_Exists 的口径（旁证 0x19ecf8, 92 B）──────────────────────────
 *   g_ObjectHash 是**指针变量**：ldr r3,[GOT 0x3edc44] → r3=&g_ObjectHash；[r3]=桶数组、[r3+4]=掩码
 *   （0x19ed00..0x19ed10）。桶槽 8 B，首字是链头；节点 {+4 next, +8 key, +0xc CObjectGM*}。
 *   循环按 key 比对，命中后取 +0xc，`adds r0,r0,#0` + `movne r0,#1` ⇒ 返回 **(CObjectGM != 0)**。
 *   ⇒ object_exists(obj) 问的是「对象号是否已注册且挂着对象管理器」，**不是**「有没有实例」；
 *     与 instance_exists（+0x68/+0x69 过滤）和 instance_number（计数）是三套不同口径。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 3 · F_ActionBounce（action_bounce）
 * @func 0x13dfec 0x13e028  size 60  15 条（无池字）
 * 符号: _Z14F_ActionBounceR6RValueP9CInstanceS2_iPS_
 * 一句话: 两个 bool 实参原样转发 → 尾跳 Command_Bounce(self, args[0], args[1])；
 *         args[0] = advanced（角度扫描开关），args[1] = 碰撞谓词（0=IsFree / 1=IsEmpty）。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 3.1 帧 + 两个 bool（0x13dfec..0x13e010）──────────────────────────────
 *   push {r4,r5,r6,lr}(16) ⇒ args [sp,#0x10]；r6=self（r1 只读这一次）。
 *   args[0]→r5、args[1]→r0，两次都走 YYGetBool（下标 0 然后 1）⇒ 两个实参都是 bool，不取整/不取 float。
 */
/* @0x13dfec push {r4, r5, r6, lr} */
/* @0x13dff0 mov r6, r1 */
/* @0x13dff4 ldr r4, [sp, #0x10] */
/* @0x13dff8 mov r1, #0 */
/* @0x13dffc mov r0, r4 */
/* @0x13e000 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x13e004 mov r1, #1 */
/* @0x13e008 mov r5, r0 */
/* @0x13e00c mov r0, r4 */
/* @0x13e010 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/*
 * ── 3.2 尾跳 Command_Bounce(self,a0,a1)（0x13e014..0x13e024）───────────────
 *   装参序 r1=a0、r2=a1、r0=self（0x13e014/18/1c）；pop 掉 4 字后 `b 0x1cafa0`。result 一个字都不写。
 */
/* @0x13e014 mov r1, r5 */
/* @0x13e018 mov r2, r0 */
/* @0x13e01c mov r0, r6 */
/* @0x13e020 pop {r4, r5, r6, lr} */
/* @0x13e024 b 0x1cafa0 <_Z14Command_BounceP9CInstancebb> */
/*
 * ── 3.3 Command_Bounce 的调用边界（0x1cafa0, 660 B / 165 条；本卡只到边界）──────
 *   r1→r5(adv)、r2→r6(solid)（0x1cafa8/0x1cafb0）。第一次探测
 *   Bounce_Test(inst, inst->[0xb4], inst->[0xb8], **r3=solid**)（0x1cafb4..0x1cafc0）。
 *   Bounce_Test(0x1caf90, 4 条) 只做谓词选择：solid!=0 → Command_IsEmpty(0x1caa1c)；
 *     solid==0 → Command_IsFree(0x1cab94) ⇒ 第三实参是「用哪个碰撞谓词」，不是 advanced。
 *   adv==0 → 0x1cb104 的四向翻转段：分别试 (x+hspeed, y)、(x, y+vspeed)、(x+hspeed, y+vspeed)，
 *     按命中组合翻转 +0xe0/+0xe4，或走 0x1cb1f0 用 SetDirection 重定方向；
 *   adv!=0 → 0x1cafe0 起的 35 次角度扫描（r5=#35，cosf/sinf@plt 按 +0xcc/+0xd0 采样 +0xe0/+0xe4），
 *     找到可行方向后同样在 0x1cb1f0 收口。
 *   ⇒ 三个 move_bounce 入口的唯一差别就是第三实参：solid 固定 0、all 固定 1、action_bounce 由 GML 给。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 4 · F_PartTypeCreate（part_type_create）
 * @func 0x128f40 0x128f70  size 48  12 条（无池字）
 * 符号: _Z16F_PartTypeCreateR6RValueP9CInstanceS2_iPS_
 * 一句话: 无实参；ParticleType_Create() 返回新槽号（int）→ result = (double)(int)。tag 先清 0。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 4.1 帧 + tag 先清 0（0x128f40..0x128f4c）──────────────────────────────
 *   push {r4,lr}(8)。**不读 args**（ParticleType_Create 无参）；r0 只在 0x128f48 被用来写 tag。
 */
/* @0x128f40 push {r4, lr} */
/* @0x128f44 mov r3, #0 */
/* @0x128f48 str r3, [r0, #0xc] */
/* @0x128f4c mov r4, r0 */
/*
 * ── 4.2 调用 + s32→f64（0x128f50..0x128f6c）───────────────────────────────
 *   bl ParticleType_Create() → r0 = 新槽号（int）；vmov s15,r0 + vcvt.f64.**s32** + stm 两字。
 */
/* @0x128f50 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x128f54 vmov s15, r0 */
/* @0x128f58 vcvt.f64.s32 d7, s15 */
/* @0x128f5c vmov r0, r1, d7 */
/* @0x128f60 vmov r2, s14 */
/* @0x128f64 mov r3, r1 */
/* @0x128f68 stm r4, {r2, r3} */
/* @0x128f6c pop {r4, pc} */
/*
 * ── 4.3 槽位分配与描述符（旁证 0x1a3068, 248 B）───────────────────────────
 *   count=*ptcount(0x542468)；count>0 时先在 parttypes.items(0x542470) 里扫第一个 ==0 的空槽
 *   （4 B 步长，0x1a3094..0x1a30c8）；扫不到就在末尾扩容 SetLength(&items,(count+1)*4)（0x1a30ec）。
 *   Alloc(164)（0x1a310c mov r0,#0xa4）后调 ParticleType_Clear(index) 填默认值
 *   （字段表与默认值见 cards/Builtins_AudioPart.c「重点 2」）。
 *   ⇒ 返回的是**槽号**而不是指针；被释放的槽（items[i]==0）会被下一次 Create 复用。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 5 · F_PartTypeShape（part_type_shape）
 * @func 0x128fdc 0x129010  size 52  13 条（无池字）
 * 符号: _Z15F_PartTypeShapeR6RValueP9CInstanceS2_iPS_
 * 一句话: ind=YYGetInt32(args,0)、shape=YYGetInt32(args,1) → 尾跳 ParticleType_Shape(ind,shape)。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 5.1 帧 + 两个 int（0x128fdc..0x128ffc）───────────────────────────────
 *   push {r3,r4,r5,lr}(16) ⇒ args [sp,#0x10]。args[0]→r5（类型号）、args[1]→r0（shape），两次 YYGetInt32。
 */
/* @0x128fdc push {r3, r4, r5, lr} */
/* @0x128fe0 mov r1, #0 */
/* @0x128fe4 ldr r4, [sp, #0x10] */
/* @0x128fe8 mov r0, r4 */
/* @0x128fec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x128ff0 mov r1, #1 */
/* @0x128ff4 mov r5, r0 */
/* @0x128ff8 mov r0, r4 */
/* @0x128ffc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/*
 * ── 5.2 尾跳 ParticleType_Shape(ind,shape)（0x129000..0x12900c）───────────
 *   r1=shape、r0=ind，pop 后 `b 0x1a31a4`；result 不写。
 */
/* @0x129000 mov r1, r0 */
/* @0x129004 mov r0, r5 */
/* @0x129008 pop {r3, r4, r5, lr} */
/* @0x12900c b 0x1a31a4 <_Z18ParticleType_Shapeii> */
/*
 * ── 5.3 写点（旁证 0x1a31a4, 60 B）────────────────────────────────────────
 *   先 ParticleType_Exists(ind)（0x1a31b0..0x1a31b8：不存在就 `popeq` 直接返回，**不报错**）；
 *   然后把 desc+0x08 写 shape（0x1a31d0），再把 desc+0x00 写 -1（0x1a31d4）。
 *   ⇒ 改形状会同时把 sprite 解绑（+0x00 的 -1 哨兵，见 Builtins_AudioPart 的字段表）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 6 · F_PartTypeAlpha1（part_type_alpha1）
 * @func 0x129624 0x129658  size 52  13 条（无池字）
 * 符号: _Z16F_PartTypeAlpha1R6RValueP9CInstanceS2_iPS_
 * 一句话: ind=YYGetInt32(args,0)、a=YYGetFloat(args,1) → 尾跳 ParticleType_Alpha1(ind,a)。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 6.1 帧 + int + float（0x129624..0x129644）────────────────────────────
 *   push {r3,r4,r5,lr}(16) ⇒ args [sp,#0x10]。args[0] 走 **YYGetInt32**（槽号）、args[1] 走 **YYGetFloat**
 *   （alpha）—— 同一函数里两种取参混用，与 Builtins_AudioPart 记的 setter 惯例一致。
 */
/* @0x129624 push {r3, r4, r5, lr} */
/* @0x129628 mov r1, #0 */
/* @0x12962c ldr r4, [sp, #0x10] */
/* @0x129630 mov r0, r4 */
/* @0x129634 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129638 mov r1, #1 */
/* @0x12963c mov r5, r0 */
/* @0x129640 mov r0, r4 */
/* @0x129644 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/*
 * ── 6.2 尾跳 ParticleType_Alpha1(ind,a)（0x129648..0x129654）──────────────
 *   r1=a（float 原样进 r1）、r0=ind，pop 后 `b 0x1a3668`；result 不写。
 */
/* @0x129648 mov r1, r0 */
/* @0x12964c mov r0, r5 */
/* @0x129650 pop {r3, r4, r5, lr} */
/* @0x129654 b 0x1a3668 <_Z19ParticleType_Alpha1if> */
/*
 * ── 6.3 写点（旁证 0x1a3668, 60 B）────────────────────────────────────────
 *   同样先过 ParticleType_Exists 闸（不存在静默返回）；然后把同一个 float 写进
 *   +0x94 / +0x98 / +0x9c 三个字段（0x1a3690/0x1a3694/0x1a3698）—— 三档生命期透明度一次性拉平。
 *   ⇒ 只有 Alpha2 的 setter 会算中点，Alpha1 不做插值。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 7 · F_PartSystemCreate（part_system_create）
 * @func 0x129730 0x129768  size 56  14 条（无池字）
 * 符号: _Z18F_PartSystemCreateR6RValueP9CInstanceS2_iPS_
 * 一句话: 常量调用 ParticleSystem_Create(**-1**, **true**) → result = (double)(int) 系统槽号（失败 -1）。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 7.1 帧 + 两个常量实参（0x129730..0x129748）────────────────────────────
 *   push {r4,lr}(8)；r4=result；tag 先清 0；0x129744 `mvn r0,#0` = **-1**、0x12973c mov r1,#1 = **true**
 *   ⇒ 调用恒为 ParticleSystem_Create(-1, true)，两个实参都不是从 GML 取的（GML 侧只暴露 0 个参数）。
 */
/* @0x129730 push {r4, lr} */
/* @0x129734 mov r4, r0 */
/* @0x129738 mov r3, #0 */
/* @0x12973c mov r1, #1 */
/* @0x129740 str r3, [r4, #0xc] */
/* @0x129744 mvn r0, #0 */
/* @0x129748 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/*
 * ── 7.2 s32→f64（0x12974c..0x129764）────────────────────────────────────
 *   返回槽号按 s32 扩宽；失败路径下 -1（0x1a44f4 mvn r0,#0）会原样变成 -1.0。
 */
/* @0x12974c vmov s15, r0 */
/* @0x129750 vcvt.f64.s32 d7, s15 */
/* @0x129754 vmov r0, r1, d7 */
/* @0x129758 vmov r2, s14 */
/* @0x12975c mov r3, r1 */
/* @0x129760 stm r4, {r2, r3} */
/* @0x129764 pop {r4, pc} */
/*
 * ── 7.3 边界（旁证 0x1a42dc, 624 B）───────────────────────────────────────
 *   g_isZeus(0x5428e8，GOT 0x3ed92c) 是这段的分水岭（0x1a42f8/0x1a42fc）：
 *     ==0 → 只做「注册表扩容 + Alloc(56) + ParticleSystem_Clear」；
 *     !=0 → 先 GetNewParticleElement + AddNewElementAtDepth 把系统挂进层元素，再
 *            ps+0x2c = element+4、ps+0x34 = !bool（0x1a4458..0x1a4460）；
 *            只有 layerID != -1 才继续写 ps+0x30 = layerID 与 ps+0x1c = 层 depth（0x1a4478/0x1a447c）。
 *   ⇒ 本包传 layerID=-1，所以 +0x30 恒不被写；bool=true 被取反成 +0x34=0。
 *   系统描述符 56 B（0x1a4404 mov r0,#0x38），注册表 0x54245c（见 Builtins_AudioPart）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 8 · F_DisplayGetWidth（display_get_width）
 * @func 0x119bc4 0x119c04  size 64  16 条（无池字）
 * 符号: _Z17F_DisplayGetWidthR6RValueP9CInstanceS2_iPS_
 * 一句话: 无实参；Graphics_DisplayWidth() → g_DeviceWidth（int）→ result = (double)(int)。tag 先清 0。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 8.1 帧 + tag 先清 0（0x119bc4..0x119bd8）──────────────────────────────
 *   push {r4,lr}(8)。**不读 args**（display_get_width 无参）；r4=result，0x119bcc 先清 tag。
 */
/* @0x119bc4 push {r4, lr} */
/* @0x119bc8 mov r3, #0 */
/* @0x119bcc str r3, [r0, #0xc] */
/* @0x119bd0 mov r4, r0 */
/* @0x119bd4 bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x119bd8 vmov s15, r0 */
/*
 * ── 8.2 取值 + s32→f64（0x119bdc..0x119bf0）───────────────────────────────
 *   bl Graphics_DisplayWidth()（0x17db24, 20 B）：`ldr r3,[GOT 0x3efea4] → ldr r0,[r3]`，
 *   槽内 addend = 0x3f26c0 = **g_DeviceWidth**（.data，初值 0x400 = 1024）；返回 int → vcvt.f64.s32。
 */
/* @0x119bdc vcvt.f64.s32 d7, s15 */
/* @0x119be0 vmov r0, r1, d7 */
/* @0x119be4 vmov r2, s14 */
/* @0x119be8 mov r3, r1 */
/* @0x119bec stm r4, {r2, r3} */
/* @0x119bf0 pop {r4, pc} */
/*
 * ── 8.3 与 window_get_* 同源（本卡最值得钉的一条）────────────────────────────
 *   四个 wrapper 只碰两个全局：g_DeviceWidth 0x3f26c0（GOT 0x3efea4）、g_DeviceHeight 0x3f26bc（GOT 0x3efea8）。
 *   Graphics_DisplayWidth 0x17db2c 与 GR_Window_Get_Width 0x17af58 是同一条 `ldr r0,[r3]`；
 *   DisplayHeight 0x17db40 与 Window_Get_Height 0x17af6c 亦然（四个函数体各 20 B，只有池字不同）。
 *   ⇒ 本 build 里 display_get_width == window_get_width、display_get_height == window_get_height；
 *     初值 1024×768 来自 .data，不是现场查询设备。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 9 · F_DisplayGetHeight（display_get_height）
 * @func 0x119bf4 0x119c24  size 48  12 条（无池字）
 * 符号: _Z18F_DisplayGetHeightR6RValueP9CInstanceS2_iPS_
 * 一句话: 无实参；Graphics_DisplayHeight() → g_DeviceHeight（int）→ result = (double)(int)。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 9.1 帧 + tag 先清 0（0x119bf4..0x119c08）──────────────────────────────
 *   与节 8 逐指令同构，只有调用目标（0x17db38 Graphics_DisplayHeight）与地址不同。
 */
/* @0x119bf4 push {r4, lr} */
/* @0x119bf8 mov r3, #0 */
/* @0x119bfc str r3, [r0, #0xc] */
/* @0x119c00 mov r4, r0 */
/* @0x119c04 bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x119c08 vmov s15, r0 */
/*
 * ── 9.2 取值 + s32→f64（0x119c0c..0x119c20）───────────────────────────────
 *   `ldr r3,[GOT 0x3efea8] → ldr r0,[r3]`，addend = 0x3f26bc = **g_DeviceHeight**（初值 0x300 = 768）。
 */
/* @0x119c0c vcvt.f64.s32 d7, s15 */
/* @0x119c10 vmov r0, r1, d7 */
/* @0x119c14 vmov r2, s14 */
/* @0x119c18 mov r3, r1 */
/* @0x119c1c stm r4, {r2, r3} */
/* @0x119c20 pop {r4, pc} */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 10 · F_WindowGetWidth（window_get_width）
 * @func 0x11a59c 0x11a5dc  size 64  16 条（无池字）
 * 符号: _Z16F_WindowGetWidthR6RValueP9CInstanceS2_iPS_
 * 一句话: 无实参；GR_Window_Get_Width() → g_DeviceWidth（与 display_get_width 同一个全局）。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 10.1 帧 + tag 先清 0 + 调用（0x11a59c..0x11a5b0）────────────────────────
 *   push {r4,lr}(8)，不读 args；r4=result；0x11a5a4 先清 tag；bl GR_Window_Get_Width(0x17af50, 20 B)。
 */
/* @0x11a59c push {r4, lr} */
/* @0x11a5a0 mov r3, #0 */
/* @0x11a5a4 str r3, [r0, #0xc] */
/* @0x11a5a8 mov r4, r0 */
/* @0x11a5ac bl 0x17af50 <_Z19GR_Window_Get_Widthv> */
/* @0x11a5b0 vmov s15, r0 */
/*
 * ── 10.2 被调方的池字 → 与节 8 同一个 GOT 槽（0x11a5b4..0x11a5c8）─────────────
 *   wrapper 自身没有池字。GR_Window_Get_Width 0x17af50 的 `ldr r3,[pc,#0x8]` 取 0x17af60 处的
 *   0x00274f48；`ldr r3,[pc,r3]` 的 PC=0x17af5c ⇒ 槽 = 0x17af5c+0x274f48 = **0x3efea4**
 *   —— 与节 8 的 Graphics_DisplayWidth 完全同一个槽（槽内 0x3f26c0 = g_DeviceWidth）。
 *   ⇒ window_get_width 不是「窗口宽」，与 display_get_width 不可区分（详见证 8.3）。
 */
/* @0x11a5b4 vcvt.f64.s32 d7, s15 */
/* @0x11a5b8 vmov r0, r1, d7 */
/* @0x11a5bc vmov r2, s14 */
/* @0x11a5c0 mov r3, r1 */
/* @0x11a5c4 stm r4, {r2, r3} */
/* @0x11a5c8 pop {r4, pc} */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 11 · F_WindowGetHeight（window_get_height）
 * @func 0x11a5cc 0x11a5fc  size 48  12 条（无池字）
 * 符号: _Z17F_WindowGetHeightR6RValueP9CInstanceS2_iPS_
 * 一句话: 无实参；GR_Window_Get_Height() → g_DeviceHeight（与 display_get_height 同一个全局）。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 11.1 帧 + tag 先清 0 + 调用（0x11a5cc..0x11a5e0）────────────────────────
 *   push {r4,lr}(8)，不读 args；r4=result；0x11a5d4 先清 tag；bl GR_Window_Get_Height(0x17af64, 20 B)。
 */
/* @0x11a5cc push {r4, lr} */
/* @0x11a5d0 mov r3, #0 */
/* @0x11a5d4 str r3, [r0, #0xc] */
/* @0x11a5d8 mov r4, r0 */
/* @0x11a5dc bl 0x17af64 <_Z20GR_Window_Get_Heightv> */
/* @0x11a5e0 vmov s15, r0 */
/*
 * ── 11.2 被调方的池字 → 同一个 GOT 槽（0x11a5e4..0x11a5f8）──────────────────
 *   GR_Window_Get_Height 0x17af64 取 0x17af74 处的 0x00274f38；PC=0x17af70 ⇒ 槽 = **0x3efea8**
 *   （槽内 0x3f26bc = g_DeviceHeight）。
 *   ⇒ 四个 display/window 内建 = 两个全局 + 两套读法（0x17af* 与 0x17db*），结果必然一致。
 */
/* @0x11a5e4 vcvt.f64.s32 d7, s15 */
/* @0x11a5e8 vmov r0, r1, d7 */
/* @0x11a5ec vmov r2, s14 */
/* @0x11a5f0 mov r3, r1 */
/* @0x11a5f4 stm r4, {r2, r3} */
/* @0x11a5f8 pop {r4, pc} */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 12 · F_AudioStopSound（audio_stop_sound）
 * @func 0x134dd8 0x134e04  size 44  11 条（10 条指令 + 1 个池字 0x134e00）
 * 符号: _Z16F_AudioStopSoundR6RValueP9CInstanceS2_iPS_
 * 一句话: id=YYGetInt32(args,0) → 尾跳 Audio_StopSound(id)；但先过 g_fNoAudio 门，门非 0 时连实参都不取。
 *         result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 12.1 帧 + g_fNoAudio 门（0x134dd8..0x134df0）──────────────────────────
 *   push {r3,lr}(8) ⇒ args [sp,#0x8]。池字 0x134e00 = 0x002ba268；0x134de4 `ldr r3,[pc,r3]`
 *   的 PC = 0x134dec ⇒ 槽 = 0x134dec + 0x2ba268 = **0x3ef054** → 0x755363 = g_fNoAudio。
 *   ldrb + cmp + `popne {r3,pc}` ⇒ 门非 0 时**连实参都不取**，直接返回（result 不写）。
 */
/* @0x134dd8 push {r3, lr} */
/* @0x134ddc ldr r3, [pc, #0x1c] */
/* @0x134de0 ldr r0, [sp, #0x8] */
/* @0x134de4 ldr r3, [pc, r3] */
/* @0x134de8 ldrb r1, [r3] */
/* @0x134dec cmp r1, #0 */
/* @0x134df0 popne {r3, pc} */
/*
 * ── 12.2 取参 + 尾跳（0x134df4..0x134dfc）─────────────────────────────────
 *   注意 `bl YYGetInt32` 之前**没有 mov r1,#0**：r1 是 0x134de8 `ldrb r1,[r3]` 读到的门字节，
 *   走这条路它必为 0 ⇒ 下标 0 是「借来的常量」，不是显式写的。
 *   0x134df8 pop 后 `b 0x21a210 Audio_StopSound(id)`。
 */
/* @0x134df4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134df8 pop {r3, lr} */
/* @0x134dfc b 0x21a210 <_Z15Audio_StopSoundi> */
/*
 * ── 12.3 池字（0x134e00，非指令）───────────────────────────────────────────
 *   = 0x002ba268，是 0x134ddc 与 0x134de4 那一对 ldr 的字面；objdump 按 ARM 译成 eoreq，
 *   按规矩保留原写法、只标注它不是指令。
 */
/* @0x134e00 eoreq r10, r11, r8, ror #4 */
/*
 * ── 12.4 Audio_StopSound 的两道门与两条路（旁证 0x21a210, 232 B）──────────────
 *   入口再查 g_fNoAudio(0x21a21c) 与 g_UseNewAudio(0x755314, 0x21a234)：任一不满足即返回
 *   ⇒ wrapper 那道门只省了取参，真正拦截在命令层。
 *   id 与 *(int*)0x3f52d0（BASE_SOUND_INDEX，.data 实测 **400000**）比较（0x21a24c）：
 *     id < 400000 → 从 CNoise 池（0x75529c: +0x38 count / +0x3c items）线性扫
 *                   +0x18==id 且 +0xd==0 的节点，命中后 Audio_StopSoundNoise(noise,false)；
 *     id >= 400000 → Audio_GetNoiseFromID(id) → 非 0 再 Audio_StopSoundNoise（0x21a2c8..0x21a2dc）。
 *   ⇒ 音源号与活动 CNoise 实例号共用同一个 int 入口，分界是 400000。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 13 · F_IniClose（ini_close）
 * @func 0x13b9e0 0x13ba08  size 40  10 条（无池字）
 * 符号: _Z10F_IniCloseR6RValueP9CInstanceS2_iPS_
 * 一句话: 无实参；buf=YYGML_ini_close() → YYCreateString(result,buf) → 尾跳 MemoryManager::Free(buf)。
 *         ⇒ result 是 **INI 全文的字符串**（tag 1），不是 undefined。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 13.1 帧 + 调 YYGML_ini_close（0x13b9e0..0x13b9ec）─────────────────────
 *   push {r3,r4,r5,lr}(16)；r5=result，**不读 args**；bl 后 r4 = 返回的 char*（可能为 0）。
 */
/* @0x13b9e0 push {r3, r4, r5, lr} */
/* @0x13b9e4 mov r5, r0 */
/* @0x13b9e8 bl 0x13b988 <_Z15YYGML_ini_closev> */
/* @0x13b9ec mov r4, r0 */
/*
 * ── 13.2 复制进 result 再释放 C 缓冲（0x13b9f0..0x13ba04）─────────────────
 *   YYCreateString(0xe5258)：先按旧 tag 决定是否 FREE_RValue__Pre，再 tag=5 → Alloc(12) → YYStrDup → tag=1。
 *   随后 pop 并用 `b MemoryManager::Free(buf)` 释放原缓冲（尾调，不返回）。
 *   ⇒ 字符串所有权在 YYStrDup 里复制走了，C 侧缓冲必须由本函数释放。
 */
/* @0x13b9f0 mov r0, r5 */
/* @0x13b9f4 mov r1, r4 */
/* @0x13b9f8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13b9fc mov r0, r4 */
/* @0x13ba00 pop {r3, r4, r5, lr} */
/* @0x13ba04 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/*
 * ── 13.3 边界（旁证 0x13b988, 88 B）───────────────────────────────────────
 *   读 g_IniFile(0x483720，GOT 0x3ef29c)：非空 → IniFile::WriteIniFile()（0x235d3c：Alloc(size+1)，
 *   按 "[section]\r\nkey=\"value\"\r\n" 写出，格式见 cards/Builtins_IO.c）→ 返回那块堆缓冲 →
 *   析构 + operator delete + g_IniFile=0；空 → 返回 0。
 *   ⇒ ini_close 在本 build 返回 INI 全文；未打开文件时 buf=0 也会走 YYCreateString
 *     （0xe52a0 的 subs 自己判空跳过 strlen），结果应是空串而不是崩溃 —— YYStrDup(NULL) 未核（见 open）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 14 · F_IniOpen（ini_open）
 * @func 0x13bb1c 0x13bb34  size 24  6 条（无池字）
 * 符号: _Z9F_IniOpenR6RValueP9CInstanceS2_iPS_
 * 一句话: name=YYGetString(args,0) → 尾跳 YYGML_ini_open(name)。result 不写（GML 侧 undefined）。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 14.1 帧 + 取 string + 尾跳（0x13bb1c..0x13bb30）───────────────────────
 *   push {r3,lr}(8) ⇒ args [sp,#0x8]；下标 0 走 YYGetString（返回 char*），pop 后
 *   `b 0x13baac YYGML_ini_open(name)`。
 */
/* @0x13bb1c push {r3, lr} */
/* @0x13bb20 mov r1, #0 */
/* @0x13bb24 ldr r0, [sp, #0x8] */
/* @0x13bb28 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13bb2c pop {r3, lr} */
/* @0x13bb30 b 0x13baac <_Z14YYGML_ini_openPKc> */
/*
 * ── 14.2 边界（旁证 0x13baac, 112 B）──────────────────────────────────────
 *   name==0 直接返回（0x13bab4 subs + popeq）。已有 g_IniFile 时先 WriteIniFile() 再 Free 那块文本、
 *   析构旧对象并 delete，最后 new(28) IniFile(name,false) 写回 g_IniFile（0x13baf8..0x13bb10）。
 *   ⇒ 重复 ini_open 会把**旧**文件先落盘一次再丢弃；g_IniFile 是唯一句柄，没有栈式嵌套。
 */
/*
 * ── 跨函数已证事实（14 节合并；括号里是节号与地址）───────────────────────────
 *  1. result 的写与不写：8 个写（ObjectExists / PartTypeCreate / PartSystemCreate / DisplayGetWidth /
 *     DisplayGetHeight / WindowGetWidth / WindowGetHeight / IniClose），**6 个完全不写**（MotionSet、
 *     ActionBounce、PartTypeShape、PartTypeAlpha1、AudioStopSound、IniOpen）。后 6 个**全部**以 `b` 尾跳收尾，
 *     其中 5 个还带 1~2 条 bl 取参（IniOpen 是「先取串再尾跳」）⇒ 它们的 GML 返回值是 undefined，不是 0。
 *  2. 三种返回编码，各不同源：① vcvt.f64.**s32** ×6（0x128f58 / 0x129750 / 0x119bdc / 0x119c0c /
 *     0x11a5b4 / 0x11a5e4）—— 六个函数取低字的方式逐字相同（vmov r2,s14）；② `movtne r3,#0x3ff0` 拼 1.0
 *     （0x12e0fc，object_exists）；③ tag 1 字符串（0x13b9f8，ini_close 经 YYCreateString）。
 *  3. tag 纪律：7 个数值函数都在**调用被调方之前**无条件写 tag=0（0x12e0dc / 0x128f48 / 0x129740 /
 *     0x119bcc / 0x119bfc / 0x11a5a4 / 0x11a5d4）；其中 6 个函数本身不取参，object_exists 是唯一
 *     「先清 tag 再取参」的（0x12e0dc < 0x12e0e4）。ini_close 的 tag 由 YYCreateString 负责（先 5 再 1）。
 *     全卡 0 条 tag≠0/1 的写，也没有「调用返回后才清」的例子。
 *  4. wrapper 层**只有一道全局门**：audio_stop_sound 的 g_fNoAudio（0x134dec 取槽 + 0x134df0 `popne {r3,pc}`，
 *     在取参之前）；其余 13 个 wrapper 没有门。被调方内部另有闸（ParticleType_Exists、Font_Exists 式的静默返回），
 *     不在这一层。
 *  5. 表/全局一共五处，互不重叠：g_ObjectHash(0x542374) 桶链、ptcount(0x542468)+parttypes(0x54246c)、
 *     g_fNoAudio(0x755363)、g_IniFile(0x483720)、g_DeviceWidth/Height(0x3f26c0/0x3f26bc)。
 *     ⇒ particle 三函数不碰音频门、ini 两函数不碰粒子表、display/window 只读两个设备尺寸。
 *  6. 注册：14/14 各恰 1 个 GOT 槽、.text 里 0 条 b/bl 指向；同族槽相邻（display 0x3ee5f0/f4、
 *     window 0x3ee6c4/c8、ini 0x3ef390/94、particle 0x3eec60/70/b4/c4）。表项顺序 ≠ 地址顺序（ini 反例）。
 *  7. 字面池只有 1 个（0x134e00）；其余 13 个函数是纯位置无关代码 —— 它们需要的全局全部由被调方自己取，
 *     wrapper 层不解析任何地址。这也是本卡 14 个函数体总共只有 174 个字的原因。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. g_ObjectHash 的桶槽是 8 B（首字链头），后 4 B 的含义未定（既不是 next 也不是 key）；表满后的扩容/重哈希
 *     未追，object_exists 在扩容瞬间的行为因此未证。
 *  2. ParticleType_Create 的 count<=0 退化入口（0x1a312c..0x1a3148）只到「把 count 当槽号」，
 *     该路径在什么条件下可达（注册表未初始化就被调用？）未证。
 *  3. part_system_create 传 layerID=-1 时，g_isZeus!=0 仍会 GetNewParticleElement + AddNewElementAtDepth
 *     （0x1a4494..0x1a44bc）；这条路径里元素的 depth 实参是 0，但 +0x30/+0x1c 不写，
 *     「无层系统」在绘制侧如何被找到未追。
 *  4. g_isZeus(0x5428e8) 的写者未追；本卡只能证明 ParticleSystem_Create 读它、GameRestart 读它。
 *  5. ini_close 在 buf==0 时走 YYCreateString(result,0)：YYStrDup(NULL) 是返回空串还是解引用空指针未核，
 *     因此「未开文件时 ini_close 的返回值」只到「不是 undefined」这一步。
 *  6. BASE_SOUND_INDEX(0x3f52d0)=400000 与 cards/Builtins_AudioPart.c 记的「id 空间分界 0x75530c」
 *     是两个不同的阈值（一个 .data 常量、一个 .bss 计数），二者在运行期的关系未证。
 *  7. g_DeviceWidth/g_DeviceHeight 的初始化值 1024×768 在 .data 里；谁在运行期改写它们（分辨率切换？）未追。
 */
