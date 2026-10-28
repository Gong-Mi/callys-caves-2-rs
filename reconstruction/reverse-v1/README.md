# reverse-v1 — 原版 libyoyo.so 的 C 化逆向

目标不是"再写一个解释器"，而是把**原版 GameMaker runner** 逐函数还原成 C，
每一行都锚到二进制里的某条指令，再用**离线**手段（ART / javam 跑我们自己的实现）做行为差分。

**不做实时操作 app 的差分**：一遍遍驱动原版 app 在速度上不可行，也不可复现。
原版只作为静态字节来源；运行期对照一律在我们自己的 harness 里完成。

## 二进制

    libyoyo.so   ELF32 ARM (armeabi-v7a)，4,689,844 B，stripped
    sha256 3bbedd09ad0cc60f3f3cad86a257275f…（取自 APK 的 lib/armeabi-v7a/libyoyo.so）
    .text  0x000b6fd0..0x0031bb7c，2,509,740 B

## 覆盖账（"逆向完全部"的唯一口径）

    instructions        627,423      .text 里每一条 32 位指令
    attributed          627,423      100.00%，无未归属
    functions           9,623        含 371 个匿名区间（stripped 的静态函数/跳转表）
    有指令的函数        8,722
    零指令符号          562          别名/重叠符号，锚点记在拥有该地址的那一个上
    地址别名            337          同一地址多个符号名，只发一次锚点

    校验 scripts/check_bank_coverage.py → anchors=627,423 / duplicates=0 / missing=0
         / orphan=0 / mnemonic_mismatch=0 / RESULT TOTAL

## 目录

    asm/census.json           总量与归属统计
    asm/functions.tsv         9,623 行：addr / size / demangled / mangled / 首末指令 / 指令数
    asm/instructions.jsonl.xz 全部指令（a/w/m/o/f），45 MB → 3.8 MB
    asm/index-<func>.tsv      单函数索引（核心函数用）
    asm/<func>_0x<va>.asm     llvm-objdump 原始反汇编快照
    cards/<func>.c            人工逆向卡：级别 + 语义 + 逐条锚点
    cards/auto/bank_*.c       301 个自动覆盖卡组，含全部 9,623 个函数的逐条锚点
    claims.jsonl              主张账本：proven / narrowed / refuted / open

## 级别

    正文      逐行锚到指令，语义已从 asm 推出，可编译（Code_Execute）
    骨架      锚点全覆盖，语义只钉了顶部几条（ExecuteIt / VM::Exec / VM::ExecRelease）
    原始覆盖  锚点全覆盖，语义未钉（cards/auto 全部）

## 规矩

1. 锚点不接受手写转录：`asm_index.py` / `libyoyo_census.py` 从二进制生成，
   `check_card_anchors.py`（单卡）与 `check_bank_coverage.py`（全库）逐地址比对。
2. 只有 `RESULT EXACT` / `RESULT TOTAL` 才允许往上加语义。
3. objdump 把 literal pool 数据字译成指令时（如 `0031deec` → `eorseq`），
   卡里保留 objdump 写法，同时在注释里标"非指令"。
4. 主张状态四选一进 claims.jsonl；`narrowed` 必须写 narrowed 到什么程度。
5. 覆盖度 ≠ 语义等价：627,423 个锚点只证明"每条指令都被指到"，不证明"理解对了"。

## 已钉的语义

    汇总：158 张卡、79,234 条锚点全部 EXACT（verify_reverse_v1.py），跨卡共享地址 0
          claims 1,620 条；指令基线 645,282；函数 9,517 / 匿名块 265 → 切分 636 段
          真实进度（上限估计）：400 个函数/段，289,716 / 593,104 B = 48.8%（可达集）
          匿名段已覆盖 37/636；剩余 Thumb 段 14 个待单独批次

    入口链
      Code_Execute    0x0cfc60   21 条  正文   纯转发 ExecuteIt；返回 0 → Error_Show_Action + 全局字节 0
      ExecuteIt       0x0cf914  211 条  骨架   code->type([+8])：<1/>3 返回 1；1..2 调 [code+0x64]+4；==3 才执行
      VM::Exec        0x0e7fd0  366 条  骨架   按 debug 全局二选一 → ExecDebug(992 B) / ExecRelease(648 B)
      VM::ExecRelease 0x0e4540  162 条  骨架   线程化派发：[VMExec+0x58][pc] → blx；+0x48 是 pc
      PerformReturn   0xe42d8   127 条  骨架   exec+0x28 帧指针、exec+0x4c 帧深度（返回自减）

    栈与变量
      DoPushImmediate 0xd3244     4 条  正文   sxth 后 str [sp,#-4]!（立即数入栈）
      DoPushBuiltin   0xd4d74    34 条  正文   索引=base&0x0FFFFFFF；表项 16B、fn 在 +4；越界 VMError
      DoPushLocal     0xd4a34   105 条  骨架   槽 = id-100000，步长 16；栈顶 tag 0x00FFFFFF
      DoPushGlobal    0xd4bd8   103 条  骨架   与局部同构，基址换成 GOT 单例 +4
      DoPushEnv       0xd4dfc   416 条  骨架   with 压栈：位域 w0∈[-7,-1] 六类标记；>99999 走 ms_ID2Instance
      DoPopEnv        0xd3840    74 条  骨架   码指针回填 (exec+0x44-4)+arg*4，再 exec+0x5c[code/4] → +0x48
      DoPopLocalVariable 0xe1f5c 46 条  正文   dst=self+4+idx*16；写回的是空结果 {0,0,tag5}
      DoPop           0xe65e4  1530 条  骨架   只收 kind 2/5/15；[15:0] count、[19:16] kind、位30 带 base
      DoPopNull       0xe61b4   108 条  骨架   kind5 才填 null；0xFF 前缀转 DoBreak
      DoDup           0xd5560   182 条  正文   dup / swap 双模式；16B 拷贝按 tag 分引用计数

    取值与运算
      DoPush          0xe9e88  1372 条  骨架   kind 0..15；8/4/16 三档载荷；**负 id 是第二级 opcode**（-1..-14）
      DoRet           0xe3fe8   188 条  正文   sub=(arg>>16)&0xFF 定 memcpy 0/4/8/16；返回值进 frame+0x2c+n*16
      DoExit          0xe44d4    27 条  正文   depth≤0 复位取指；depth>0 走 PerformReturn 后压 16B tag0
      DoConv          0xeb3f8   832 条  正文   src/dst 类型码 + 103 项预解析表 → 44 个叶子
      DoAdd           0xdc524  1015 条  骨架   mode=(arg>>8)&0xF；type 字节高位=左、低位=右；tag0 double/7 int32/10 int64/1 string
      DoSub/DoDiv/DoXor/DoAnd/DoShl/DoRem/DoMul/DoMod/DoShr/DoOr  各 460–637 条，全部 骨架
                                             统一：消费表定结果槽 → 算术表（9~12 条内核）→ 压回
      DoNeg/DoNot     0xe096c/0xd7908    骨架   mode1/mode2 两条语义（DoNot 的 ! 与 ~ 栈效应不同）

    调用与比较
      DoCall          0xe8b48   786 条  骨架   id 四分流：<100000 内建 / +100000 脚本 / 499999 间接 / >500000 扩展
      DoCallGML       0xe8b00    18 条  正文   DoCall 路径 A 的特化
      DoCallLibrary   0xe3e58   100 条  正文   desc=table+idx*0x50、fn=desc[0x40]、5 参协议
      DoSet           0xe2014  1863 条  骨架   **不是赋值，是比较算子**：K=(arg>>8)&0xF，实数比较带 1e-05 容差

## 第二轮（并行子代理）补上的关键结论

    DoCallScript 0xe8588  350 条  骨架   帧格式闭合：frame=sp-60，15 字写 14 个（+0x34 空槽）；
                                         frame+0 存 pc/返回地址（不是旧 sp）、+0x08 旧 Argument、+0x38 旧 sp 偏移；
                                         进码十件套：exec[0x24]=blob[0x10]、[0x44]=code[0x6c]、[0x48]=blob[0x18][pc/4]
    DoBreak      0xd8434  140 条  骨架   断点补丁字 0xFFFF0000、表 256×16 B；uxth(arg) 三态（0 单步 / 0xFFFF 下标守卫 / 其它直返）
    DoReplace    0x24a99c 998 条  正文   $ 模板五规则 + 回调路 count+2 个实参（JS replace(fn) 语义）；
                                         两位组号读 repl[i+3] 是原版错位
    DoRegExpExec 0x24f2b0 130 条  正文   成功返回末捕获结束偏移并写 lastIndex；NOMATCH 自行线性续搜
    DoSlowDrawRoom 0x1b06a0 281 条 骨架   三股流合并（层项数组步长 56 B / 绘制链 +0x17c / 粒子 depth 游标）；
                                         可见性 = +0x65!=0 && +0x68==0 && +0x69==0；深度上限 11000.0f
    DoAStep      0x1d32c0 230 条  正文   整帧 step 驱动：UpdateLayers→Step(1)→…→Step(2)→Particles；
                                         五段 profiler 段名实取；「退出码闸门 0x542954==-1」重复 13 次
    DoFrameTiming 0x2903f8 135 条 正文   60 fps 预算：budget=(1e6/fps)−0.5·(1e6/60)−(t−now)+debt，clamp 0..1e6 后 Timing_Wait
    DoOperation  0x207a0c 196 条  正文   op 1/2/3（Grid/Add/Multiply）；kind=tag&0x00FFFFFF 的 15 路表在 0x207ab0
    DoGenerationalGC 0xd6850 151 条 正文   开关 0x47f295；MarkAndSweepGen 后按 200/30/2.0/1.1/0.5/4.0 决定下一代
    DoTheWork    0x2a16dc  46 条  正文   srand48(2101988) → RunnerLoadWad → PrepareGame → Run_Start
    DoDestroy    0x10b0c4  26 条  正文   +0x68/+0x69 双闸门先于 hard 判断；软路只置 +0x68，硬路 Command_Destroy 另置 +0x6A
    DoInstanceDestroy 0x10b12c 25 条 骨架   WithObjIterator(id,self,other) + do/while（每实例 2 次 de() + 1 次 Next()）

    补一条纠正：DoDestroy/DoInstanceDestroy **与 DoPop/DoPush 没有调用边**（tag 释放走 FREE_RValue__Pre），
    耦合只在数据位——DoPushEnv 的 with 遍历按 +0x68/+0x69 跳过，而置这两个字节的正是 DoDestroy。

## 第三轮（按调用图派工的依赖环）

`scripts/call_graph.py` 把已出卡函数指向未出卡函数的边算出来（17,168 条内部边，未覆盖被调方 154 个），
第三轮按被调次数派工 14 个：

    FREE_RValue__Pre 0xc0a7c 564 条 正文   入口只按 tag&0x00FFFFFF 分三支：1 字符串 / 2 数组 / 3 指针（条件虚删除）
                                           tag1 归零链是 dec() 的逐指令内联；4 条 bl dec 全在静态死块
                                           数组三处释放全走 YYStrFree（无 delete）；61 条指令（10.8%）静态不可达
    boxType        0xd7784  97 条 正文   返回值 = 数据指针 + 消费字节数；eVM_Type 0/1/2/3/4/5/6/9，7-8 空档
    InternalGetYYVar 0x196a70 69 条 正文 变量表 +0 size/+4 count/+8 mask/+0xc threshold/+0x10 nodes(12B)；
                                           hash=key+1 且只比 hash；未命中读时惰性创建，默认 tag 来自 this+0x58
    Find_Slot_From_Name 0xd21ec 15 条 正文 全局名走线性 strcmp（声明顺序即 id）；0 是合法槽、-1 才是未找到
    VMError        0xd4210  56 条 正文   不是 abort/setjmp：置 Code_Error_Occured=1 后正常返回；
                                           只有 g_bLaunchedFromPlayer==0 才 exit(-1)；.text 里 177 处 bl
    JSThrowType/ReferenceError 各 71 条 正文  深拷贝异常值进 g_exceptionVar(0x75645c)、置 g_fThrownExceptionUnwinding=1
                                           后尾跳 UnwindExceptionStack（逐帧 PerformReturn）
    F_JS_ToNumber  0x24cfac 338 条 正文   真签名 (RValue& out, RValue& in)；只认 8 个 tag；十六进制有符号 vcvt；
                                           尾部垃圾 → NaN {0xFFFFFFFF,0x7FFFFFFF}
    F_JS_ToInt32   0x24d5c8  90 条 正文   输出是 tag0 double；取模靠 mov r1,#0 丢高字（不是掩码），再严格 bgt 2^31 折符号
    UpdateActiveLists 0x1d30a4 48 条 正文 三个待办队列 0x542a4c/0x542a64/0x542a58，判据 [list+8]!=0
    MemoryManager::Alloc 0x27ce78 25 条 正文 file/line 不落地（logLocation 是空桩）；16B 头 {size,0xDEADC0DE,0xBAADB00B,0}
    _RefThing::dec  0xc09f8  33 条 正文   非零只减计数；归零 YYFree→清字段→LOCK/decr→UNLOCK→delete；0xc0a48 段静态不可达
    YYAlloc         0xcef4c   6 条 正文   尾跳 Alloc(size,"…/Code_Main.cpp",1293,false)，不清零
    Code_Variable_Find_Name 0xd25fc 7 条 正文  id>=100000 走全局/内建表，<100000 返回 "<unknown built-in variable>"

    两条被推翻的旧说法（都当场回改到原卡里）：
    · 「tag 5/12 = bool」→ 5 是 .bss 零常量（+0.0）、12 是显式 0.0（null）
    · 「LOCK_RVALUE_MUTEX 提供保护」→ 本构建两个锁函数都是单条 `bx lr` 空操作

## 第四轮（变量系统与上下文栈）

    Variable_GetValue  0x1f3ce0 171 条 正文  p1=域(-3 全体/0..99999 对象/>99999 实例)、p2=≤9999 内建序号 | ≥10000 变量 id、
                                              p3=INT_MIN 标量 | 数组下标(ldiv 32000)；返回 0 时 out 一字节不写，0x00FFFFFF 占位保留
    Variable_SetValue  0x1f4348 265 条 正文  只做「解析实例集合」的派发，不释放旧值、不做 tag 拷贝、不处理下标；
                                              释放与写回在 SET_RValue(0xd0c38)/SET_RValue_Array(0xcff4c)/ARRAY_LVAL_RValue(0xd0e60)
                                              写路径无深拷贝：tag1 ++[+4]、tag2 ++[容器+0] 并回指 holder
    Variable_GetObjectName 0x1f3f8c 80 条 正文 第二参是死参；六个失败出口统一 "<unknown_object>"，只有 id==-3 且无活实例才置 0x75505c=1
    PushContextStack   0xd3968 51 条 正文    .bss 0x47f27c cap / 0x47f280 count / 0x47f284 data，门字节 0x47f295；
                                              无深度上限、按需倍增、永不回收；溢出无错误分支（cap 先翻倍再写元素）
    PopContextStack    0xd3a34   8 条 正文    只 --count 且防下溢；不清槽、不释放
    GetContextStackTop 0xd3a54  15 条 正文    栈顶 = GC 写屏障的 parent：157 个调用点里 127 个紧跟 bl DeterminePotentialRoot
    _RefThing::assign  0xdc418   5 条 正文    if(p) ++p->[+4]; return p —— 纯 retain，不读第二参
    F_InstanceDestroy  0x10b190 24 条 正文    参数解析后尾跳 DoInstanceDestroy，返回值既不读也不写
    anon_319414        0x319414 17 条 正文    就是 __aeabi_ldivmod：除零 → 按被除符号夹逼后 raise(SIGFPE)
    Stubs_TailJumps    （合并卡） 27 条 桩    YYFree ≡ YYStrFree ≡ b MemoryManager::Free；唯一走 libc free 的是
                                              operator delete(void*,char const*,int)；LOCK/UNLOCK/DeterminePotentialRoot 都是 bx lr

    又改了两张旧卡：DoPushEnv 的 +0xd0 是实例**节点链** {+0 next,+8 inst}（不是 inst+0x178 串起来）；
    DoInstanceDestroy 的 id>99999 走**另一张表**（GOT 0x3edc4c ≠ 0x3edc44），不是同一查表。

## 第五轮（对象/房间/事件/调用层）

    CRoom::DeSerialise  0x1ac33c 841 条 正文  12 段流序无版本号；tile 表 +0xb8/+0xbc/+0xc0；
                                              实例表 A(+0x84 头/+0x80 尾/+0x88 计数，depth 降序) 与 B(+0x90/+0x8c/+0x94)；
                                              room_maxtileid 往返净不变
    StartRoom           0x1d38e0 732 条 骨架  0x542954=-1 → IO_Clear → Effect_Clear → 房间表扩容 → Run_Room_Set；
                                              持久房间只重挂不重建；事件 14/0 → 7/2 → 房间创建码 → 7/4
    Draw_Room           0x1b3e98 740 条 骨架  自己不选路；DrawTheRoom(0x1b3b10) 按 room+0xb8 / +0x88 选慢/快；
                                              离屏表面 0x3f5110、回贴闸 0x3f50fc、方式 0x3f50b0
    HandleOther         0x1ce594 1736 条 骨架  只跑 Other 事件四趟（0/1/40+i/50+i）；候选来自事件→对象 id 数组；
                                              每趟创建计数快照跳过本趟新建实例
    CLayerManager*      Duplicate 1171 / DeSerialize 937 条 骨架  CLayer = 112 B 池对象（56 B 是绘制侧层项记录）
    Call_Normal(_std)   各 729 条 正文  与 DoCall 家族零调用边；62 个十进制位编码 case；std 与非 std 仅 3 字不同
    CInstance::CInstance 257 条 正文  sizeof=432、整块清零、字段初始化表（+0xd8=270.0、alarm 全 -1…）
    Perform_Event / Perform_Event_Object / Object_Name  正文

    一处跨卡冲突已实证裁定：早期卡把 room+0x80 当链头、+0x178 当 next，是反的。
    真值：room+0x84 头 / +0x80 尾 / +0x17c next / +0x178 prev（DeSerialise 0x1acd58..0x1acda4 的尾插现场）。
    四张卡已回改（DoSlowDrawRoom、DoAStep、DoPushEnv、StartRoom），claims ROOMCHAIN-001/002/003。

## 第六轮（序列化/加载/绘制选路/实例链）

    CRoom::Serialise      714 条 正文  与 DeSerialise 段级严格互逆（55 写点 vs 55 读点、类型码同分布、
                                      四条遍历方向对偶）；物理房间只打错误不阻止保存；24 个字段不入流
    CRoom::Assign         827 条 正文  Clear + 8 段；深拷贝两条串/物理世界/层/每实例/RTile/两张表/id 数组；
                                      8 背景与 8 视野记录不重分配只覆盖；无别名检查
    CInstance::DeSerialise 592 条 正文 54 项覆盖 64 槽；object_index 第二实参 = bRegister && !deactivated；
                                      +0x160/+0x164 不入流，读档后恒 0
    CInstance::Assign     432 条 正文 只搬状态不建身份；变量哈希表与骨架深拷、CObjectGM/object_index 浅拷；
                                      完全不碰 +0x084 物理体
    CRoom::LoadFromChunk  544 条 正文 WAD 块启动装载（唯一调用链 Room_Load←LoadGameData←RunnerLoadWad）；
                                      tile 只收指针表不调 AddTile；不建任何 CInstance
    CRoom::LoadFromStream 401 条 正文 2.1.9 死代码（零调用者），magic 0x21d
    DrawTheRoom           226 条 骨架 完整条件树：+0xdc>0 → 层绘制 + 事件 73 直接返回；否则 +0xb8(tile 数)
                                      与 +0x88(实例数) 决定慢/快；快路径按 LargestDepth 与 -1e9 二分
    DrawInstancesOnly     118 条 骨架 快路径仅实例；Set_Depth 被 3D 字节门控；帧号 floorf
    DrawInstancesParticlesOnly 275 条 骨架 粒子归并（bpl 比较）、-1e8 空哨兵、11000 深度上限
    Compute_BoundingBox   357 条 正文 bbox 是 int32 tagYYRECT；取整真值表 A/B 两字节；
                                      right 以已取整的 left 为基准（1px 怪癖）
    CRoom::UpdateActive   116 条 正文 两链按 +0x69 四分支搬运；两趟都从尾沿 +0x178 往头
    CInstance::SetObjectIndex 71 条 正文 摘旧→查 g_ObjectHash→写 +0x80→可选 AddInstance→复制六字段→标记脏
    Command_Change        53 条 正文 四门四出口；事件序 1→12→ChangeObjectIndex→14→0
    Perform_Event_All     39 条 正文 批量版，不经过 Perform_Event；从链尾沿 +0x178；多两道门

    三处旧说法被本轮推翻并回改：
    · 「room+0x80 是链头」→ 头 +0x84 / 尾 +0x80 / next +0x17c / prev +0x178（两处尾插现场一致）
    · 「bbox 字段是 float」→ int32 tagYYRECT
    · 「room+0xb8/+0xc0 是层项数组」→ 是 tile 表（56 B 记录 = 14 字段）

## 第七轮（资源装载 / 房间表 / 层 / 实例插入 / 内建 API）

    LoadGameData       667 条 正文  10 个 Init → 代码表 → 全局实例 → 31 tag 块链 → 回填 id；
                                    头部只校验 pWAD[4]==size-8；**非 WAD 静默返回 1**
    RunnerLoadWad       21 条 正文  打 "LoadGameData()" 后尾跳 LoadGameData(*0x544b78, *0x544b74)
    Room_Load          219 条 正文  五段；n!=0 重装泄漏旧 CRoom（名字表存前必 Free，两表不对称）
    Room_LoadOrder      90 条 正文  七档 bytecode version 分支（本包 GEN8[1]=16 → >=14 档）
    CRoom::CRoom       272 条 正文  建三图 → 标量/8 背景/8 视野 → Clear 释放并改 30/640/480/0x00C0C0C0/1 → 重建三图
    DrawRoomLayers     118 条 骨架  从链尾 +0xd8 沿 +0x6c 反向；层升序 ⇒ depth 大的先画
    CLayerManager::AddInstance 41 / AddInstanceToLayer 184 条 骨架  四道门 + 三级归层；36 B 池造 type 2 元素
    CRoom::AddInstance 520 条 正文  5 节（含 ToStorage）：4 个改活房间 + 1 个暂存；A 链排序键是 +0x184 快照
    CRoom::AddTile     162 条 正文  cap=count+10 扩容、++room_maxtileid 覆写 +0x20
    Variable_Global_Init 26 条 正文  globdecl={cap,data}，ReAlloc(10000) 后逐字节清零
    Builtins_Instance  721 条 正文  9 个：activate/deactivate 不碰链；deactivate_all(notme)=先全灭再点亮自己
    Builtins_Draw      331 条 正文  5 个：都不读 argc、都不写 ret；CSprite::Draw 九参表两处互证
    Builtins_DsString 1230 条 正文  11 个：ds_map 键是 **RValue 不是 string**（CRC32 六路分派）

    又改了两处旧说法：房间表在 0x5425d0（0x542990 是 Run_Room_List）；
    CInstance 读写不对称是三处而非一处（object_index / bbox 前置重算 / 变量块计数取全局）

## 第八轮（剩余游戏内建 API + 层/碰撞辅助）

    Builtins_Motion     249 条 正文  instance_activate_region/place/destroy/exists/number、
                                     mp_potential_step、move_towards_point、point_direction、sign
                                     · point_direction = atan2f×180/π 归一化 ⇒ 度 [0,360)、0=右/90=上/270=下；θ=+0 返回 −0.0
                                     · instance_number(-1/-2) 返回 0/1 不是计数；对象索引是「objgm+0xd0 链计数 + 全局表按 +0x7c 过滤」两处相加
    Builtins_IO         223 条 正文  · YYRandom = 16 字滞后 Fibonacci（state@0x479a88 + idx@0x479a84），InitRandom 用 MSVC 0x343fd/0x269ec3
                                     · irandom_range=[min,max] 闭；random_range=[min,max) 开；random(n)=[0,n)
                                     · ini 写侧 "%f"（6 位小数）、格式 [section]\r\nkey="value"\r\n；未开时读写共用同一条错误串
    Builtins_AudioPart  278 条 正文  · 两道门 0x755314（后端 Sound_/Audio_）与 0x755363（总开关）
                                     · 粒子类型描述符 164 B，字段表全解，默认 grav_y=270.0f
    Builtins_Draw2      208 条 正文  · draw_sprite 走 GetSpriteIndices + CSprite::DrawSimple（四参，不是九参 Draw）
                                     · IAP 内建不碰 JNI；真 JNI 在三跳后的 IAP_AcquireM
    LayerHelpers        329 条 正文  7 节：RemoveInstanceElement / GetLayerWithDepth / AddDynamicLayer /
                                     CollisionInsert / CollisionRemove / SetDeactivated / RebuildPhysicsBody
                                     · Add↔Remove 完全互逆，唯一不对称是 +0x180 depth 只由 Add 覆写
                                     · SetDeactivated：g_isZeus==0 只改字节，!=0 取 *(Run_Room) 尾调 UpdateInstanceActivation

    两处回改：CLayerManager::AddInstance 的第一道门是「0x5428e8 == 0 就返回」（1c5d34 popeq），早先写反了；
    F_InstanceDestroy.c 退役（与 Builtins_Motion §3 同 24 条锚点重复，语义已并入后者）

## 第九轮（游戏内建 API 收尾 + 绘制/命令/层删除）

    **87 个游戏实际调用的 builtin 到这里全部有正文卡。** 本轮补完最后 28 个（总 1,020 B）：
    Builtins_Misc1(14) + Builtins_Misc2(14)：motion_set、object_exists、action_bounce、
      part_type_create/shape/alpha1、part_system_create、display/window 尺寸、audio_stop_sound、
      ini_open/close、move_bounce_solid/all、room_goto/restart、audio_pause/resume/stop_all、
      draw_set_alpha/color/font、action_current_room/kill_object、draw_self、game_restart
      · room 链接口唯一：Command_GotoRoom(0x1c9e08) 写 New_Room，第二实参是死参
      · New_Room 六档消费在 SingleStep：-1/-200(RestartGame)/-300(LoadGame)/-100|-400(清 Run_Running)/其余 SwitchRoom
      · draw_set_color/alpha 是三个互不重叠的全局写点（0x3f23d0 / 0x3f23cc / 0x3f2410）
    CSprite_Draw      550 条 正文  Draw 九参 / DrawSimple 四参 / DrawTiled **十三参**（不是 12）；
                                    三函数零全局写、零深度设置（深度由调用方设）；剔除用 g_transRoomExtents 四边
    CInstance_Setters 177 条 正文  SetSpriteIndex 先写后校验；SetID 维护第三张表 ms_ID2Instance(0x536f28)；
                                    SetPosition 只在位精确不等时写 +0xb4/+0xb8；GetTimer 越界返回 -1
    Command_Collision 675 条 正文  collision_line/rectangle/place_meeting 三命令；
                                    ShouldUseFastCollision 三值分流（-1 直接 0 / 1 走树 / 2 走链）；
                                    快路不带 obj 过滤，过滤在回调里重做；慢路不排除候选==inst 而快路无条件排除（不等价，已记）
    LayerRemove       796 条 正文  删一层 = N 次元素销号（表 2/表 3）+ 1 次层销号（表 1）；
                                    bDestroy=1 时 type 2 走 DoInstanceDestroy ⇒ **删层会硬销毁层内实例**
    CollisionUpdate_Room 237 条 正文 g_tree 懒建在四道闸之后；旧盒 = 入参 rect、新盒 = +0xe8..+0xf4；
                                    UpdateLayers 只认 type 1/4/5，type 2 停用会断整层遍历

    一处账本纠正：claims CEG-003 说 Command_RestartGame 是 208 B 写 -201 —— 实测 **88 B 写 -200**，
    Command_EndGame 才是 4 B `bx lr`；已按 refuted 改写。

## 第十轮（存档 / 层构建 / 房间与对象操作 / 变量名域）

    Command_SaveGame    388 条 正文  18 段；实参是 IBuffer 句柄号；19 个写点里 18 个类型码 6、1 个码 9
    Command_Unzip       196 条 正文  短读仍按 stat.size 落盘；size==0 的 entry 只开不关（漏句柄）；返回 entry 数
    Command_Bounce      165 条 正文  四向命中组合；35 步扫描 base=lrint(dir/10)*10，两侧各 350°
    CLayerManager::BuildRoomLayers 766 条 骨架  层数据块 → CLayer 字段映射；层类型 4 路决定元素类
    CLayerManager::InitLayerFunctions 1364 条 骨架  **151 条注册三元组**（名字→handler→argc），149 个 handler
    Room_Free / Add / Duplicate  617 条 正文  Free 释放 CRoom 并清名字表、先置 Run_Room=0；
                                     Add/Duplicate 只追加不覆盖；**Duplicate 是 CRoom+0xd0 的唯一置 1 者**
    Object_Add/Prepare/Load/GetInstance 299 条 正文  OBJT payload={count,offsets} 相对 g_pWADBaseAddress；
                                     对象号 = 记录序号（装完 g_ObjectNumber=191）；GetInstance 的 id 四分流
    Variable_GetName_Scope / BuiltIn_Add 341 条 正文  四张名字域表；BuiltIn_Add 的 16 B 项四字段、
                                     第 4 实参死参、表固定 500 项不扩容（满则 ShowMessage）

    一处措辞回改：池压链是**插回链头 LIFO**，不是尾插（DuplicateRoomLayers 卡已改）。

## 结构结论

**opcode 表已定位**（`asm/handler_table.tsv`，由 `scripts/find_handler_table.py` 从 .data 指针扫描得出）：
.data 0x3f20b4 起 32 项、每项 4 字节，就是 `VM::ExecRelease` 里 `[VMExec+0x58][pc]` 的落点：

    0 Push   1 PushLocal   2 PushGlobal  3 PushBuiltin  4 PushImmediate
    5 Pop    6 Dup         7 Conv
    8 Mul    9 Div        10 Rem        11 Mod         12 Add   13 Sub
   14 And   15 Or         16 Xor       17 Neg         18 Not   19 Shl   20 Shr
   21 Set  22 Branch     23 BranchTrue 24 BranchFalse
   25 Call 26 PushEnv    27 PopEnv     28 Ret         29 Exit  30 PopNull  31 PopNull(重复)

DoSet 落在 21（Shr 与 Branch 之间），与「它是比较算子而非赋值」互相印证；
slot 31 与 30 同值、DoBreak 不在表内，仍是 open（OPCODE-002）。

原版没有 opcode 比较链：`VMExec+0x58` 是一张**预解析的处理器指针表**，主循环取表项后 `blx`。
语义全在 48 个 `DoXxx(uint32 arg, uchar* sp, const uchar* base, VMExec*)` 里（返回新的值栈顶），
合计 70,532 B ≈ 17,633 条指令。

三条贯穿全库的事实（都已锚到指令）：

    RValue      栈上 16 字节，类型 tag 在 +12 的高字节，取值 0..14
                0/13 real、1 string、2 array、3 pointer、5 undefined、7 int32、10 int64
                0x00FFFFFF 是「尚未解析的变量引用」占位
    id 分区     基址 100000：脚本 id、局部槽、全局槽都用 id-100000；槽步长 16 字节
    opcode 参数 位域：[15:0] 有符号 count（sxth）、[19:16] 子种类（ubfx #0x10,#4）、
                位 30 = 附带变量基址（ands #0x40000000），位 29 = id 内嵌于 arg

两条方法学教训（写进库里，避免再犯）：

    · ARM `add pc,pc,rX,lsl #2` 的基址是**该指令地址 + 8**，紧跟其后的 `b` 是越界 default 而非 case 0。
      早先 DoPushGlobal 的 tag 落点表整表错一位，已按此修正并作废（claims RVALUE-003）。
    · 函数名不可信：`DoSet` 名字像赋值，实际是比较算子；`DoRem` 写回的是**商**；
      DoDiv/DoAnd/DoShl 的错误串分别写成 `'*' operator`/`DoAdd`/`DoOr`（原版复制粘贴错位）。

## 下一步

    · 32 张骨架里挑「调用链主干」升级正文：DoPush（负 id 二级 opcode 的 14 条）、DoCall、DoPop
    · 补齐尚未出卡的 Do* 剩余函数（见 functions.tsv 里 _Z*Do* 且签名不同的那批）
    · 在 javam/ART harness 里跑同一段 GML 字节码，比对"我们的 VM 状态轨迹"与"按 C 卡实现的轨迹"
      ——两边都在我们手里，不碰原版 app
