# 状态与定性

## 当前断点：MemoryManager分配与调试记录/源码行解析

`memory_manager/memory_alloc.cpp` 恢复_Alloc/Alloc，`vm_exec/vm_debug_info.cpp`恢复
DebugInfo/DebugLineNumber，四完整原入口/236原字（8池字），闭合上一批的真实直接调用。
_Alloc保留bucket→标准分配、64位size+16门、头词/计数写序和live mutex解锁；Alloc保留
原bool清零、logLocation和held指针。调试记录按8B扫有符号PC，源码行按原逆UTF扫描、
#line字面量与真实_ctype_指针表分类，文件名分配先发out、copy后live回读out再写NUL。

父级修掉原稿自造memcpy返回NULL早退，恢复无条件终结符写；补volatile raw-word读取，
O2原稿count0会跳过code字段读而修后无条件保留；同一cursor生命周期、ctype字节地址与
普通换行读序已复核。O0/O2各36TU/74原名字组合通过；独立复核的别名错报经冻结头与全量重编反证核销，源码无变更；本地收口仍
phase_complete=false。bucketAlloc、UTF helper本体/原语言、记录生产者、Ctor/继承链、
map Insert/FreePre及所有LR/坏域/unwind/并发等价仍欠。仍不执行目标、不安装、不推送。

## 已提交基础：值池/map生产者与调试执行（8bb884b）

GetRValue/AllocVars/ExecDebug三入口/341原字已收口，34TU/70原名字，22路径/75输入
逐提交blob一致。0x78池链/真F32阈值、调试单步伪指令及独有locals清理均保留。父修
GetRValue立即数fff00→ff000；复核报告“缺VFP”“70产物数”“错误GOT值”经原件/头/ELF
独立核销未采用。两个配置全部fresh通过；只有server分支注释修订，不是运行等价证明。

## 已提交基础：重分配与对象变量（92fe8dc）

ReAlloc/bucketSize、ObjectAlloc/InternalGetYYVar、普通int hash/YYRealloc六入口/327原字
已收口；32TU/67名字，25路径/73输入逐blob对齐，hash O2八字节等于原件。独立复核未有
正文缺陷；LDMIB注释已修。ReAlloc mutex槽经父级复算为3f1824，复核报告3f1828口误未采用。

## 已提交基础：VM入口与profiler节点（3ec96e4）

VM::Exec、FindNode、WEAK refdec、YYFree和三个原no-op七入口/522原字已收口；30TU/61名字。
父级修原稿池fill/对齐、spill前后与回调重读、BFI等；独立复核定位VMEXEC-01，sp+64对应
frameDepth+4c而非nextSlot+48，已按原字修复、fresh两档重编和旧偏移ABI负控拒绝。23路径/
67输入逐commit blob一致。原no-op O2各BX LR，弱覆盖只核静态链接选择，未执行目标。

## 已提交基础：ScriptRef 与 profiler 压帧（e60233c）

Call_ScriptRef、GetCode、YYAllocLocalStackNew、Profiler Push四入口/271原字已静态复核后
收口，21路径/59输入逐blob对齐，O0/O2各27TU/54导出；GetCode O2八字节与原件一致。
参数共享+1c两路清零后第五bool恒false，先前count→bool假设已否证；24B profile frame
只初始化前三word，尾部按raw搬运。保留未认证栈垃圾值、完整类/FP trap/unwind等边界。

## 已提交基础：页池与 JS 助手（ff753ce）

FreeRValue页池和五个JS属性/可调用性/Call_RValue助手已收口；六入口/114原字，两池字。
父级O0/O2各24TU/50导出，四个JS调用边核过；独立静态复核未发现正文缺陷，提交15路径/
48输入逐blob对齐。只证这批源码、ABI和编译范围，不升级原件执行或全库语义完成。

## 已提交基础：对象回收与 unsigned32 叶（46ce675）

YYObjectBase::Free/FreeVars 的 slot registry、dispose 探针、dense/hash 清理、pool push 和
两处 live pcre_free 调用均有完整静态成员正文；不实例化名义 YYObjectBase/RValue 类型。
fixunsdfsi.c 保留 carry/sign/register-LSR 的位图分域以及同址 __aeabi_d2uiz 别名，不用 cast。
本批三原入口、四名字、238原字；O0/O2 各22TU/44导出，独立源审后本地提交并逐blob核对。
这是源码/目标编译证据，不含原件执行、对象寿命/异常认证或整游戏等价。

## 已提交基础：页边界查找与软件整数转换包装（8b59819）

已落 `globalPageListFindAddr` C++ 正文，以及 `c/compiler_conversions/` 中 __fixdfdi /
__fixunsdfdi 的 C 正文和各自同址 EABI 别名。三原入口、五导出名字、86 原索引字，别名不加入口。
父级修正了查找内环的一个具体错译：BNE 使用 SUBS 的旧 step，后面的 ASR 不置旗标；
old step=1 必须再读一次 step=0 的 pivot，否则第一桶内地址会误返回空。反例是静态 CFG
推导，不是执行原件或新 C++ 的回执。尾部保留 signed remainder 形状，不改成 index&1。

转换包装保留软件比较/乘/减/转换 helper，没以本机 cast 或 native FP 算术替代；两对别名
在 O0/O2 中各自同节同址、GLOBAL，size 也实测而非假定为零。O0/O2 各 18 TU、40 个原
导出名字齐全，Lookup 和 __fixdfdi 已真正填入上一批调用边。旧方法正文未改，类级清单随
新成员扩展。NaN/失败/异常与完整软件 FP 尚未认证；仍不运行目标、不安装、不推送。

下一断口为软件比较/乘减/32 位转换、页表生产者/具体桶实现，以及对象和值的释放。

## 已提交基础：内存释放与单调时钟依赖（817fc72）

用户已要求“循环工作”：本批源审/目标编译/本地提交后直接接下一批，不再等待重复“继续”。
外置控制状态在 `~/.hermes/worklines/cally-native-loop.json`；是会话内回调驱动，不是脱离会话的守护进程。

`cpp/memory_manager/` 已落 MemoryManager::Free、Mutex::Init/Lock/Unlock、桶 Free 派发、
真实 no-op logLocation，以及匿名 lazy-init 调用目标；`cpp/timing/` 落 Timing_Time/Init。
本批分账为 8 个有定义符号的原入口＋1 个匿名直接调用候选，175 个原索引字；不把匿名候选
和原 no-op 混成新增业务函数。字段与 global/GOT/字符串位置均绑定原件，未定义默认运行状态。
父级保留 lazy init 的 malloc 返回接收者（发布后不多读全局），头偏移按 ARM32 整数回绕，
计数器/短路/解锁重读顺序不改。时钟保留 VMLA、VDIV 和原 __fixdfdi 调用，非整数近似替换。

O0/O2 各 16 TU 组合，35 个原导出符号齐全；真实 MemoryManager::Free/Timing_Time 已填入
既有 VMBuffer、VMExec、Profiler 的调用边。globalPageListFindAddr 和 __fixdfdi 仍仅声明，
尚未闭合；下一批先接这两处，再推进对象/值释放与上层 VM 调用者。
仍只做静态可读源码与目标对象，原件/重建件均未运行、不安装、不推送；失败/FP trap、
并发双字传输、坏头和异常展开不认证。旧 C 与已提交 C++ 候选未改。

## 已提交基础：VMExec 执行、退帧与 profiler（30a83ed）

`cpp/vm_exec/` 已落 `VM::ExecRelease(VMExec&,RValue*)`、C++ 自由函数 `PerformReturn` 与
直接依赖 `CProfiler::Pop()`。不是旧 C 换后缀：保留类静态/成员调用、RValue 不完整类型指针，
真实组合已有 VMBuffer 转换方法、退帧与 profiler 正文；没有默认全局或被调桩。
本批 3 个原 ABI 入口、334 个原索引字（含 16 池字）。旧 C 的同址方法不重复计新增原函数。

VMExec 已把调用者可观测字段恢复到 +0x5c（0x60 前缀），控制帧步长 60 字节。+0x40 从
VM::Exec 的立即数写入和退帧算术互证为 0x4000 字节跨度，不是旧 C 的 frame_top 指针语义。
state30、全类范围和原对象 API 仍未闭合；RValue 保持不完整类型，不编造构造/赋值/持有规则。
父级修正了 buffer/locals 读写序，以及 profiler 使用“减前 count 的 GT 标志”选帧的错译；
原 count=1 必须选择第零帧。时间累计只加入差值的低 32 位，未按常识扩大到完整 64 位。

ARM32 O0/O2 各编译 11 个 TU（本批 4 个、既有 buffer 4 个、CCode 3 个），27 个组合原符号
无缺失，三个 16 字节 vtable 保持。`cpp/vm_buffer/`（2e66337）、`cpp/ccode/`（3651a7b）
和旧 C 原样保留。详见 [装载与派发合同](../contracts/vm-buffer-dispatch.md) 和各 functions.json/
validation.json。仅静态与目标编译，未运行原件或重建件、做 64 位替换或游戏接入。

工作树中尚未提交的 `c/vm_exec_release/` 候选已将 ExecRelease、PerformReturn、convertBuffer
与指针哈希真实链接合成门；此前 O0/O2、18 项语义负控和 2 项链接负控通过，本轮未重跑。
这些 C 候选改动不随本次 C++ 源码批次提交，清册头/夹具哈希仍待收口；不以其合成绿灯
认证已提交 C 版本或新 C++ 行为。

下一处源码断口是 VM::Exec/ExecDebug/DoCallScript 的同语言调用者，以及 MemoryManager::Free、
YYObjectBase::Free、FREE_RValue__Pre/RValue、Timing_Time 与全局生产者。缓存插入/失效/命中
第二张表来源与所有权仍未闭合；CCode opaque 状态、无效表项/空 profile 栈 fault、原双字
传输的并发原子性和异常展开也仍未认证，不猜未知字段。

## 2026-11-16（续六）：VM 算术处理器 + 房间激活链，并修掉一处我自己模块里的 NaN 误译

**A. `c/do_add/` + `harness/do_add_diff.py`**：`DoAdd`(0xdc524) 523 例 identical、census 996/996、
pair 表 103/103 项真被执行、15 个牙齿全 PASS（全部 `mode=compare`，无崩溃型）。
**`c/do_sub/` + `harness/do_sub_diff.py`**：`DoSub` 481 例 identical、census 521/521、14 个牙齿全 PASS。
两臂都用 armv7a-none-eabi + qemu-arm（DoAdd 的 string 路径把 `char*` 存进 4 字节 RValue 槽，
宿主 64 位会整体挪位）。`boxType` 真实链接；`F_JS_ToNumber` / `F_JS_ToPrimitive` 是**具名模型**并由差分判死。
回执 `do_add_diff-20261116T193217` / `do_sub_diff-20261116T193224`。
对卡的更正：
1. `cards/DoAdd.c` 的 "1015 条指令" 错——实际 **996 指令 + 19 池字**（把池当指令读了）。DoSub 的 538 = 521+17 是对的。
2. **表 3 用调用方给的 cls 原始字节索引**，不是解析后的 pair：装箱操作数解出类型后算术按解析 pair 走，
   但结果槽位仍按原始 cls 选。卡里没有这条，是这函数最容易译错的结构。
3. DoAdd 的 string+string(pair 0x66) 真的工作：结果 = 「第二操作数 + 第一操作数」，并递减两个输入的 refcount。
4. **DoSub 只有 mode 1**（入口只 `cmp r2,#1`），mode 0 与 2..15 全走强类型臂；且**第二操作数是被减数**
   （`vsub d7,d6,d7`、d6=[r10]），U==6 桩里还有一条 `mov r6,r10`，漏了返回栈指针整排错。

**B. `c/room_update/` + `harness/room_update_diff.py`**：`CRoom_UpdateActive`(116)、`UpdateActiveLists`(42+6)、
`ProcessActivateDeactveLists`(10+2，补齐它是为了让"队列计数→链重写"两臂都真实)。
38 例 identical、census 168/168、60 项覆盖全 yes、21 个牙齿全 PASS。回执 `room_update_diff-20261116T193237`。
新事实：计数测试是**非零**不是正数（−1 与 0x80000000 都会 flush）；`UpdateActiveLists` 出口**重读** profile 字节；
深度变化**不**重排激活链（排序键是只在插入时刷新的快照 +0x184）；两个计数器只是无条件 ±1，不追踪链长；
0x542a4c=激活队列、0x542a64=对象类型队列、0x542a58=depth（与变量卡 narrowed 命名一致）。

**C. 修掉一处已提交模块里的真误译（我自己复核并补了门）**
`c/room_add/src/CRoom_AddInstance.c` 把 `vcmpe.f32 + bls` 写成 `!(a > b)`（注释还写着"<= 或 unordered"）。
VFP 在这条指令对上的实测标志：equal `0110`、greater `0010`、less `1000`、**unordered `0011`**；
`bls` 是 `C==0 || Z==1`，因此它**只在有序的 `a <= b` 时成立**，NaN 时不跳——NaN 深度会沉到链尾。
`!(a > b)` 在 NaN 时为真，是错的。已改为 `a <= b`、注释重写并撤回旧说法；
`room_add_diff.py` 新增用例 `F1-m`（snapshot = 0x7fc00000）+ 变异体 `f1_nan_ordered_compare`，
实测该变异体**只被这 1 例抓到**——也就是说修之前这条路径没有任何用例覆盖，绿是假的。
room_add 现在 49 例 identical、24 个牙齿全 PASS（回执 `room_add_diff-20261116T193427`）。

## 2026-11-16（续五）：实例登记链与实例身份链（父代理复跑）

**A. `c/room_add/` + `harness/room_add_diff.py`** —— `CRoom_AddInstance`(79 指令+2 池字)、
`CLayerManager_AddInstance`(40+1)、`CLayerManager_AddInstanceToLayer`(179+5)。
父代理复跑：`RESULT PASS cases=48 identical=48 binding=ok repeat=ok census=298/298 selftest=ok`，
覆盖 61 项全 yes，变异体 23 项全 PASS、**零崩溃型**。回执 `room_add_diff-20261116T183544`。
binding 不硬编码：五个 GOT 槽与三条 rodata 串都由 `ldr/add pc` 算术从字节重新推导。

对卡的更正（两处都会让原件直接跑飞）：
1. F3 报错宿主槽是 **0x3ed71c**（`0x1c5ca4 + 0x00227a78`），不是卡写的 0x3ed718；
   两者指向不同 .bss，差 4 字节。照卡 staging 原件会在 0x1c5cb4 `blx` 进垃圾。
2. F3 的报错串是 `0x350864 "Attempting to add instance %d multiple times to a layer"`，
   不是卡写的 " ERROR: Adding too many variables"（后者是另一条 `INTERNAL ERROR:` 的尾巴）。
   这也是修正前唯一的 identity diff。
3. 卡说"幂等"只对 F2/F3 的 `+0x174` 门成立；**F1 完全不看 `+0x174`** —— 重复登记会让
   `inst->next = inst` 自环、`room+0x88` 1→2、id 表插第二个同键节点（case F1-i 实跑确认）。

**B. `c/instance_ctor/` + `harness/instance_ctor_diff.py`** —— `CInstance::SetObjectIndex`(70+1)、
`CInstance` 构造函数(249+8)。父代理复跑：`RESULT PASS cases=38 identical=38 binding=ok
census=319/319 census-self=ok got=ok tail=ok`，覆盖 44 项全 yes，变异体 34 项全 PASS
（两条 `mismatch+driver-abort`，都另有字段级命中，回执写明"无 teeth 仅靠 abort"）。
回执 `instance_ctor_diff-20261116T183617`。两臂堆模型一致并写进回执：bump @IC_HEAP、16 对齐、填充 0x5B、块尾守卫 0xDEADBEEF。

新事实（卡上无）：
- `SetObjectIndex` 在 `RemoveInstance` 之后**从内存重读 +0x7c**（0x193278）、在 `AddInstance` 之后
  重读 +0x80（0x19335c）——所以 RemoveInstance 若写了 +0x7c，`-1` 归一会被跳过。
- ctor 在 0x19964c 预清 +0x80，使 RemoveInstance 分支**从构造路径不可达**（即使块是回收的）。
- `cap==0` 不是"什么都不做"：`count>=cap` 成立 ⇒ 走一次 grow，`YYRealloc(base,0)` 与 `memset(p,0,0)`
  都被调用，cap 仍 0，最后给 slot=-1。实例表扫描是**钳位**不是取模。
- `+0x64..+0x67` 共处同一个字（bbox 脏位/visible/solid/persistent），按字读会一次读到四个。
- ctor 卡 open 项加深：`cap<0` 时是**无限循环**（count>=cap 恒真、newcap<=cap、0x1998bc 跳过测试），
  不是"失败退出"；未当 case 跑，只记 card_deltas。

**累计**：本线现有 **17 个已恢复且带差分臂的函数体**；语义核心 ★ 尚未动的仍是
VM_Exec（骨架卡）/ 事件命令族 / builtin F_ 直系，以及 CRoom_UpdateActive、collision 一系。

## 2026-11-16（续四）：语义核心第四批——变量家族与指令侧收口（父代理复跑）

**A. `c/variable_misc/` + `harness/var_misc_diff.py`** —— 四件：`Variable_Global_Init`(24 指令+2 池字)、
`DoVariableInstanceExists`(33)、`Variable_GetName_Scope`(158+13)、`Variable_BuiltIn_Add`(164+6)。
父代理复跑：`RESULT PASS cases=74 identical=74 binding=ok census=379/379 selftest=ok`，
覆盖 84 项全 yes，变异体 30 项全 PASS 且**零崩溃型**。回执 `var_misc_diff-20261116T180011`。
(`Variable_GetName_Scope` / `Variable_BuiltIn_Add` 是我没点名的两件，工人按调用链一并做了，
回执里已把它们与被点名的三件分账。)
`Variable_GetValue_Direct` 与 `Code_Variable_Find_Slot_From_Name` 走**真实链接**，其余被调方同桩并列明。

**B. `c/variable_ops/` + `harness/var_ops_diff.py`** —— 三件：`Code_Variable_Find_Name`(7 条/28 B)、
`DoConvIntToVariable`(9/36 B)、`DoPopLocalVariable`(46/184 B)，三者 GOT-free、pool-free。
父代理复跑：`RESULT PASS cases=53 identical=53 binding=ok census=62/62 census-self=ok`，
覆盖 41 项全 yes，变异体 29 项全 PASS 且零崩溃型。回执 `var_ops_diff-20261116T175942`。

**这一批对卡的更正与新事实（都以字节/对拍为准）**：
1. `DoConvIntToVariable`：卡正文的 `vldr s15,[sp] / vstr s14,[sp,#-12]` 与它自己的注释块矛盾，字节是 `[r1]`；
   且 `s14` 不是残值——`0xd7740 vcvt.f64.s32 d7,s15` 写出的 d7 低半字就是 s14（预置 0x3f800000 实测被覆盖），
   `r1-12` 的 8 字节恒等于 `struct.pack("<d", v)`；对象是 **16 B 槽**（+0 低字、+4 高字、**+8 从不写**、+0xc tag=0），
   返回值 `r1-12` 来自 `str r12,[r0],#-12` 的后索引写回。
2. `Code_Variable_Find_Name`：`bgt` 是**有符号**，一切负 id（含 INT_MIN）都走丢弃 name 的内置分支。
3. `DoPopLocalVariable`：卡"sp 净下移 0"不准确——body 只动自己的 frame，返回相对入参 r1 的增量恒为
   `16 + 4*[bit31 clear] + 4*[bit29 clear]`（16/20/24 三档都有案例）。
4. `FREE_RValue__Pre` 的闸不是 `tag != 0`：原件是 `0xc0a84 bic r3,r3,#0xff000000` 后分别 `cmp #2 / #3 / #1`
   （已由本人反汇编复核），所以 tag 0x40000001 / 0x80000001 会被释放，tag 5 / 0x105 不会。
5. 新事实（卡上没有）：`Variable_GetName_Scope` 的实例 map 反查内层**没有边界**（0xd236c 只按 `i` 与 `hash>0`
   推进游标），若 `map->count` 大于实际占用项数会走过 entries 读野内存；fixture 因此恒令 count==占用项数。
6. `Variable_BuiltIn_Add` 的 500 上限是 `beq`（相等），count>500 会越界追加（staging 到不了该状态，记 not_applicable）。

**统计口径**：本线现在有 12 个已恢复且带差分臂的函数体（GetValue/Direct、SetValue 家族、
Find_Slot_From_Name、GetObjectName、Global_Init、VariableInstanceExists、GetName_Scope、
BuiltIn_Add、Find_Name、ConvIntToVariable、PopLocalVariable）。**语义核心 ★ 仍有 CRoom/CLayer 的
Add*/Remove*、事件/命令（VM_Exec 仍是骨架卡）、builtin F_ 直系未动。**

## 2026-11-16（续三）：语义核心第三批——GetValue 解析器 + 名称侧两件（父代理复跑）

**A. `Variable_GetValue` 解析器（`c/variable_resolve/`，`harness/var_resolve_diff.py`）**
父代理复跑：`RESULT PASS cases=54 identical=54`，覆盖 48 项全 yes，变异体 21 项全 PASS
（无纯崩溃型；两个 `mismatch+driver-abort` 是"字段级已抓到 + 另有用例崩"）。
回执 `var_resolve_diff-20261116T172029`。判据每例比 `RET` / `OUT` 16 B / 失败标志
`0x75505c` / 有序调用流（slot delta 以 region 为基准，负槽号也成立）；
`Variable_GetValue_Direct` 已有译文 → **真实链接**（body sha 与 var_direct 回执同值），
`GET_RValue` / `InternalGetYYVar` / builtin getter 仍同桩并在 scope 写明。
两条值得一提的过程事实：
- 工人初版给房间路径多插了一层解引用，差分立刻红出 5 个房间用例（原件 ret=0/flag=1，译文本可解析）。
  卡是对的、译文是错的 —— **staging 双侧对称也救不了译文错**。
- 卡里"段 3 与段 4 的 r5 语义相反"这句文字错：两段都是 `(sel==索引)?1:0`，
  段 3 用 `movne/moveq`、段 4 用 `subs/rsbs/adcs`（`C2=(d==0)`），行为一致。

**B. 名称侧两件（`c/variable_names/`，`harness/var_names_diff.py`）**
父代理复跑：`RESULT PASS cases=42（Find_Slot_From_Name 16 + GetObjectName 26）identical=42`，
覆盖 31 项全 yes，变异体 17 项全 PASS，census 84/84。回执 `var_names_diff-20261116T172045`。
与静态卡**无偏差**（行号、指令数 13+2 / 71+9、池大小、三处 GOT→.bss、节点/桶偏移、六个失败出口同址全部逐字对上）。
`Object_Name` / `Local_Name` / `Global_Name` 三个被调方仍是同桩：绿的只是这两个函数体的
分派、字段偏移与返回管线，**不是设备等价**。

**本线剩余（语义核心 145 函数里尚未动的）**：CRoom/CLayer 的 Add*/Remove* 一族、
事件/命令（VM_Exec 仍只有 366 锚点的骨架卡）、builtin F_ 直系，
以及 `Code_Variable_Find_Name` 与 `DoConvIntToVariable`/`DoPopLocalVariable` 等待接。

## 2026-11-16（续二）：语义核心第二批——SetValue 家族 + Get 臂补边界，两臂都复跑过

**A. Variable_SetValue 家族译文与差分臂（新模块 `c/variable_set/`，`harness/var_set_diff.py`）**

父代理复跑：`RESULT PASS cases=40 identical=40`，覆盖 54 项全 yes，19 个变异体全被抓
（18 个字段级 mismatch + 1 个 `c1_extra_indirection` 只能靠崩溃抓到，已标 `mode=driver-abort`）。
回执 `var_set_diff-20261116T170027`。另有三道非字段门：census 255/255（每条指令注释与
llvm-objdump 逐字机检）、repeat（新建 Oracle 与第二个 qemu 进程重跑，记录流逐字相同）、
binding（镜像 SHA + 三处 .rodata 消息串逐字节比对）。

对静态卡 `cards/Variable_SetValue.c` 的更正（都已用反汇编独立复核）：
1. **被调 Direct 是 0x1f3c28**，不是 0x1f3e70（后者是 GetValue 里的 `strb r3,[r7]`）。
2. **S2 比 S5 多一层解引用**：S2 是 .bss 0x542374 里存指针→指向 {+0 buckets,+4 mask}；
   S5 的 0x536f28 本身就是那个结构。卡说两者"哈希形状完全相同"只对字段布局成立。
3. **C1/C2 是指向 .bss 的对象**（`ldr r11,[r9,r3]` = &0x542a64），不是指针变量本身。
4. **E3 恒返回 0**：0x1f4674 `bl YYError` 后直接落到 0x1f4684 `mov r0,#0`。
   卡的 open 4"返回未初始化寄存器值"不成立；r10 在 S5 路上确实是死的，但没被返回。
5. 循环内累加器是 **r0**（0x1f4468 进 / 0x1f4510 出），r10 在循环中装的是 value 指针。

**B. Variable_GetValue_Direct 臂扩展（父代理复跑 `var_direct_diff.py`：19 例 identical，
9 个覆盖项全 yes，6 个变异体全抓，`get_rvalue_args_swapped` 已从"只靠崩溃"升级为
字段级 mismatch，11 例命中 / 4 例仍崩已单列 aborted_cases）**

- **一条我自己造成的缺陷（记录在案）**：上一批的用例标签写错了——标成 "slot 0/7/50" 的
  三条，varid 是 10000/10007/10050，真实槽号是 **-90000/-89993/-89950**。也就是说旧 case
  集从未命中表内 16 B 槽，这正是 swap 变异体只能靠崩溃抓到的原因。标签已改，输入与算术一字未动。
- 空档区间实测：flag≠0 + table≠NULL + varid 50000/99998 → 原版把 `table−800000` / `table−32`
  直接交给 GET_RValue，不校验也不拒绝，已用 delta 钉死（对应卡 open 2）。
- `bvar_entry_stride_16_to_4` 做不到字段级：10000 个 entry 装同一桩，落错 entry 仍是可调用的
  fn 指针，只有砸到 name 字段（varid 9999 → base+39996）才崩；回执 `why_not_field_level` 记了原因。

## 2026-11-16（续）：语义核心第一件——Variable_GetValue_Direct 的 C 译文 + 差分臂

从动画族转到 ROADMAP 的语义核心，先做最小自洽的一件：`Variable_GetValue_Direct`
（0x1f3b8c，156 B / 39 指令）。它与 resolver `Variable_GetValue`(0x1f3ce0) 分工明确：
resolver 只解析「读哪个实例」，Direct 才是取值 —— 内建变量号走 16 B 表项 +4 的 fn，
变量 id 走 `table + (varid-100000)*16`，`[obj+0x24]==0` 时直接返回 0 且不碰 out，
`table==0` 时改由 `InternalGetYYVar` 返回槽地址（**不做** base+index*16 的算术）。

- 译文：`c/variable_direct/src/variable_direct.c`，逐条锚点写在注释里（含 `bls` 是
  **无符号**比较这条：负 varid 不进内建表，而是走槽路径并按负数下标算出表下方的地址）。
- 差分臂：`harness/var_direct_diff.py`，原件在 Unicorn 跑 0x1f3b8c、译文在 qemu-arm 跑
  （armv7 自由站立编译，指针 4 B，表项 fn 才真的落在 +4；host 编译会把它挪到 +8）。
  2026-11-16 实测 **11/11 例 identical**，6 个覆盖项全命中，6 个变异体全被抓
  （其中 2 个是 driver 崩溃型，回执里显式标 `mode=driver-abort` 并注明这比字段级不等弱）。
- **范围声明（不许外推）**：`GET_RValue`(0xd13bc)、`InternalGetYYVar`(0x196a70) 与内建表
  fn **都未恢复**，两臂跑的是同一份桩。所以这次只钉住 Direct 自己的分派、调用序与槽算术；
  它不证明那三个被调方，也不是设备等价。回执 `var_direct_diff-20261116T163442`。

## 2026-11-16：Level A 门矩阵改造的复跑结论（A 门 26/27，B 门被分配器约定挡住）

11-08 会话末尾未提交的 415 行改造（`gate_a_modules` / `gate_b_error_trees` /
`gate_c_perturbations`）在本日被独立复跑，结论分三条，按证据分层记：

1. **A 门（点名单模块 → 改坏它 → 必须动到归因字段）实测 26/27。**
   `level_a_stage_a_20261116T154432.json`，回执 `status` 只覆盖 stage a。
   唯一失败 `tl_path_mix_rotate_key`：**不是链错，是输入域缺口**——B17 的
   0x28e8ec..0x28e8fc 在子键名恰好等于 `"mix"` 时直接跳回 0x28e048（模块头已把
   "没人处理 mix" 从指令流定死），所以契约那棵树根本走不到 B17 的主体。
   要让它可测，得新增一棵"path 约束下带非 position/spacing/mix 子键"的树变体，
   不是改模块、更不是把门改成绿。**本批已补齐**：树变体 `path_mix_alt`
   （`level_a_trees.py`，path 约束下带 `mixAlt` 子键），`gate_a_modules` 改成
   变异体可各自钉一棵树、基线按树取（`A_MUTANT_VARIANT`）。重跑 A 门
   **27/27**（`level_a_stage_a_20261116T155155.json`），该门 diff=2 命中
   `animations[0].timelines[10].frames[1]/[4]` 并归因到 `spine_read_tl_path_mix`。
   这同时是原件侧的一条语义事实：**原版对"非 position/spacing/mix"的未知子键
   也会建 path-mix 时间线**（两臂同帧比对通过）。

2. **两个变异体是设计错，已修（`level_a_diff.py`）。**
   `ik_bend_positive_key` / `path_position_mode_key` 原来只改大小写
   （`bendPositive`→`bendpositive`、`positionMode`→`positionmode`），而原件
   `Json_getItem` 在 0x287414 调的就是 `strcasecmp`——大小写不敏感的查找下这种
   "错键"照样命中，变异体天生咬不到任何字段。改成 `bendPositiveZ` /
   `positionModeZ` 后两门实测 PASS。**规则：键类变异体必须过 strcasecmp 这一关，
   只改大小写的变异体不算判别性反例。**

3. **B 门（19 棵错误树：两臂都必须 NULL + 同 error 文本 + 同 root_dispose）
   卡在分配器约定，不是语义。** `err_slot_bone` / `err_ik_bone` / `err_tr_bone`
   三棵在 `m3 pre-chain` 后 SIGSEGV；`qemu-arm -d in_asm` 最后落点是
   `spSkeletonData_dispose`。根因：错误路径的 dispose 会遍历 `slotsCount` 条
   **尚未填过的** slots 指针表，而两臂的分配器填充不同——
   重建臂夹具 `reserve()` 每个分配都 `memset(0xee)`（`c/spine_read_mesh/fixture/check.c`），
   原件臂 Unicorn `alloc()` 每块都零填（`tools/level_a_oracle.py`）。
   于是 0xEEEEEEEE 被当指针解引用。`err_parent` 不崩，因为它在发布 slots 计数前就失败了。
   结论：**在分配器约定统一并写进契约之前，B 门的任何"绿"都无效**；两个方向
   （两侧都毒填 / 两侧都零填）会给不同答案，且原件在这条路径上依赖 malloc 数组为 0
   这一前提本身就是待定性的语义事实，不能只挑一个让门变绿。

   **本批已定性并落地**（`level_a_stage_b_20261116T160246.json`：12 通过、0 失败、7 不可测）：
   - 用一份临时 0xEE 填充的 oracle 副本实测：毒填下**原件自己**也 UC_ERR_READ_UNMAPPED
     （同一批 slot/ik/transform/path 的 bone/target 找不到）。零填下原件能返回错误文案，
     只因为合成镜像把 ELF 的 vaddr 0 那页也映射了，NULL 解引用被读成功而不是 fault。
     设备上地址 0 不可映射 → 这条路径是**原件自带的 latent crash**，不是重建链的错。
   - 原件字节佐证：`0x28ae48 ldr r0,[r3,r5,lsl#2]` / `0x28ae50 bl spSlotData_dispose`
     **没有判空**，即拿未填表的元素直接 dispose。
   - 因此 B 门把 7 棵（err_slot_bone / err_ik_bone / err_tr_bone / err_path_bone /
     err_ik_target / err_tr_target / err_path_target）记为 `UB_ADDRESS0_LD` /
     PASS=None（不可测），不记 FAIL 也不记 PASS；分配器约定统一为**两臂都零填**
     （`build_c(..., zero_fill=True)` 走 `level_a_dump_zero.c`），模块门仍用 0xEE 毒填
     以保持"没写"可观测。
   - **契约假设被实测推翻**：B 门原来要求非 leak 树 `root_dispose>=1`（setError 释放根树）。
     实测 8 条路径两臂都是 rd=0——setError 收到的是子节点，根树不释放。判据已改成
     "两臂必须一致"，`rd==0` 另记 note；一致性要求不放水（不一致仍 FAIL）。

## 当前断点：Level A 首份对拍报告落定（④轴已测：267 字段 diff=0）

`c/spine_level_a/`（子代理 S，父代理两次独立复跑 RESULT PASS）：**④轴从
「未有测量」变为「已测量」**——Unicorn oracle 跑原版 readSkeletonData
（hook Json_create 返回同一棵 150 节点合成树、分配器/libc/libm/console/
setlocale 全套 hook、两侧 cos/sin 同 prescribed 值）vs 重建链（qemu-arm
调总装模块）：main（scale 2.0/1.0）+err_parent（双侧 NULL+同文案）+perturb
四轮 **267 字段 diff=0**；三负控全过（打坏段命中归属/扰动双侧 25 字段
同步/存档 3879 字节重放一致）。**收据 tier=oracle_anchored、
original_executed=true**（scope=合成内存 oracle，非设备）。回执
`level_a_diff-20261108T160156.json` + 逐字段报告。合同已裁定两类收据
纪律（test_anchored vs oracle_anchored 不得混用）。见
`contracts/native-equivalence-gate.md`。

**口径**：①可反汇编/②自比/③夹具执行 全绿；④与原版等价=合成内存 oracle
层已测，差异 0（输入域：本合同输入集）——**不是全输入域等价，不是设备
等价**。harness 自坑清单（PLT0 逐项 guard/QEMU CPACR/setEvent 3 参 ABI/
free roster 溢出/解码流错位）已记入交接与 README。

`c/spine_read_skeleton/`（子代理 R，父代理复跑 RESULT PASS）：**完整
spSkeletonJson_readSkeletonData 重建链落成**——entry→bones→slots→ik→
transform→path→skins+glue→linkedmesh 后处理→animations_loop→B18，全部
真实链接既有模块；语义缺口 6+1 块在适配层闭合（含窗外第 9 块 0x28e7f4，
父代理核对入边属实）；**两处 root 泄漏照原样**（Skin+Parent mesh）；
4 配置×20 测试、16 具名变异（含注入的**组合层三类负控**：段序错乱/
交接错配/打坏单段点名定位）、6 链接门；**receipt 显式 equivalence_axis_4:
not_measured**。回执 `skeleton_chain_check-20261108T145754.json`。
见 `reconstruction/contracts/native-animations.md` 第十批节。原件未执行。

**readSkeletonData（13,044B/3,261 insn）纯重建 C 模块链收口：31+8+1 块、
九时间线家族、全部胶水与错误尾。验收口径=test_anchored（接线正确）；
④轴（与原版等价）= 未有测量。** 下一步按
`contracts/native-equivalence-gate.md` 施工 Level A 函数级对拍工具
（Unicorn oracle 跑原函数 vs 重建链、同一棵合成树 hook Json_create、
spSkeletonData 全字段 diff+三负控）——判据已冻结，整件可下沉次模型。

`c/spine_skins_glue/`（子代理 Q，父代理复跑 RESULT PASS）：**8 个物理胶水块
全部恢复**（98 word pin 对 92 条指令逐条全覆盖）；**分派依据是 loader 存进
返回对象的 +0x04 而非请求 type**（父代理核对 0x28c7c0）；跳表 5 落点父代理
逐字核（linked 也落 mesh 0x28cb20）；**add 用 attachmentMap->name（JSON
成员键）而 createAttachment 收 "name" 属性——两者必须分开传**；loader 错误
对 ldm 透传；四错误尾 dispose(data)→setError(json,root)→返 r4。
4 配置×15 测试、15 变异、5 拒绝门。回执 `skins_glue_check-20261108T140923.json`。
见 `reconstruction/contracts/native-animations.md` 第九批节。原件未执行。

**④轴等价门已立（2026-11-08，总装收口前）**：`contracts/native-equivalence-
gate.md`——总装 PASS 只证接线；④轴在 Level A 工具（Unicorn oracle 跑原函数
vs 重建链，同输入→spSkeletonData 全字段 diff+三负控）跑出报告前一律报
「未有测量」；玩法级四条件为 Level B 另行立项。**总装批（R）已注入组合层
三类负控**（段序错乱/段间交接错配/打坏单段定位）——分块 PASS 不证明整链。
汇报口径：所有 receipt 维持 test_anchored/original_executed=false，④轴未测
期间禁称"接近原版"。

**readSkeletonData 全部构件已齐**：段链物理缺口清零；语义缺口 6 块（各段
模块只回错误码不发射 dispose/setError 尾）按 animations_loop 适配器先例在
总装层闭合。剩最后一件事：**全链总装**（entry→bones→slots→ik→transform→
path→skins+glue→linkedmesh 后处理→animations_loop→B18，含 §5.3 的
"只发射一次"约束与 root 生命周期），交付完整 spSkeletonJson_readSkeletonData
重建链。

`c/spine_animations_loop/`（子代理 O，父代理复跑 RESULT PASS）：**家族调用
顺序定案**（父代理逐分支核对 8/8）：slots→bones→ik→transform→paths(B13/B17
交错)→deform→drawOrder→events→发布（0x28e784 count 先写/0x28e78c 元素旧
游标/0x28e79c 回 B3）；**0x28ea10 块（slot index -1 错误）本批恢复**；
4 配置×17 测试、12 变异、5 链接门（去任一家族源→undefined symbol）。
回执 `animations_loop_check-20261108T134040.json`。
见 `reconstruction/contracts/native-animations.md` 第八批节。原件未执行。

顶层段链普查已落盘（`asm/segment_chain_map.md`，父代理核验三处并修复：
attach_type_e 枚举序、entry 的 setError 声明、STATUS 分段表错位）：
**总装缺口=物理 8 块/368B/92 insn**（createAttachment 五参调用+类型跳转表
0x28c7a0、addAttachment+三层循环推进 0x28cc68、四条离位错误尾）+ 语义缺口
6 块/260B。下一步：恢复 skins 胶水块 → 全链总装（entry→…→animations_loop
→B18）。

`c/spine_read_tl_event/`（子代理 M，父代理复跑 RESULT PASS）：B16 event
时间线（findEvent→spEvent_create→494 深拷贝→setFrame）；**open #7 关闭**
（event+0x10=stringValue，拷贝无条件永不别名，无双释放；存在理由=B18 返回前
Json_dispose 根树）；**open #10 关闭**（count 先写/元素用旧游标，0x28e784/78c）；
E5 json 实参 NULL（父代理核对）。4 配置×13 测试、14 变异。

`c/spine_read_tl_path_mix/`（子代理 N，父代理复跑 RESULT PASS）：**谜题定因
——name=="mix" 没有任何 handler，静默跳过**（beq 目标是节点前移，父代理核对
0x28e048=ldr r4,[r4]）；除 "mix" 外任何名字都建成 mix 时间线；B17 无扫描、
索引 +0x14 在帧判空前无条件写、帧距 3。4 配置×13 测试、13 变异。
回执 `tl_event_check-20261108T125309.json` / `tl_path_mix_check-20261108T124846.json`。
见 `reconstruction/contracts/native-animations.md` 第七批节。原件未执行。

**父代理两处修复**：①path 模块 rotateMix 键 pin 的 add 站点错（0x28e93c 是
str 非加法；正确 0x28e938→rotateMix；旧 pin 绿但错，'teMix' 是后缀巧合）——
已改并复跑全绿；②spEventData+0x00 措辞 borrowed→owned（create 会 strdup）。

**animations 段 31 分块全部恢复为 C**（B1..B18+E1..E7，1579 可达指令分块
全覆盖）。下一步：动画级总装（B3 键缓存→B4 create→按原序调九个时间线
家族→发布→B18）与顶层段链总装。

`c/spine_read_tl_deform/`（子代理 K，父代理复跑 RESULT PASS）：三层循环
skin→slot→attachment→frames；weighted 门=attachment+0x14；**魔数消费钉死**
（全函数恰好两处 [sp,#0x60]：0x28d304 写/0x28e128 ldrne 读；有符号 /3 截零
×2，含 INT_MIN 25 例）；**2*(vc/3)=每帧浮点数**→timeline+0x14→setFrame 的
malloc+memcpy 边界；**_readVertices 未被调用**（父代理扫 BL 核实）；**E6
实为 drawOrder 触发**（错误块与触发块跨族交叉，按入边归属）。4 配置×21
测试、19 变异、5 拒绝门。

`c/spine_read_tl_draworder/`（子代理 L，父代理复跑 RESULT PASS）：**两次
malloc 所有权钉死**——A(442) builder 内 0x28e524 先 free 不进 setFrame；
B(445 填-1) 交给 setFrame 后立即 free；setFrame 存私有副本（malloc690+memcpy）；
miss 路径 A/B 双泄漏照实复现；`slotsCount` 被读 5 次逐点重读；回边实为
0x28e5cc（普查勘误）。4 配置×15 测试、15 变异、4 拒绝门。
回执 `tl_deform_check-20261108T122759.json` / `tl_draworder_check-20261108T122831.json`。
见 `reconstruction/contracts/native-animations.md` 第六批节。原件未执行。

`c/spine_read_tl_transform/`（子代理 I，父代理复跑 RESULT PASS）：5 个 mix 键
每帧无条件全读（缺键默认 time 0.0f/mix 1.0f）；扫描与 ik 同构但命中岛行内；
setFrame **7 实参（3 走栈）**、帧距 5；**B12 无任何错误路径**（父代理扫 bl
目标核实）。4 配置×14 测试、14 变异。

`c/spine_read_tl_path/`（子代理 J，父代理复跑 RESULT PASS）：**B13 只做
position/spacing**（mix 归 B17，普查标题修正）；**值键=timelineNode->name
非字面量**；**path 有判空+错误路径**（"Path constraint not found: "，open #6
不能外推）；扫描结果进共享栈槽、timeline+0x14 **无条件写→miss 带 stale
index**（与 ik/transform 最大差异）；scale 选择不对称（spacing bls 无符号，
mode=-1 不缩放）；B13 两岛落在 B15/B17 地址区间。4 配置×18 测试、15 变异。
回执 `tl_transform_check-20261108T114620.json` / `tl_path_check-20261108T120113.json`。
见 `reconstruction/contracts/native-animations.md` 第五批节。原件未执行。

`c/spine_read_tl_bones/`（子代理 G，父代理复跑 RESULT PASS）：B6 分派链
rotate→translate→scale→shear；**骨索引来自独立符号 findBoneIndex@0x28b018**
（首个匹配、≤0→-1；模块内暂驻真链副本，skeleton_find 收编时删）；
translate 乘 parser->scale 而 scale/shear 强制 1.0；rotate 键 time/angle 帧距 2；
**scale/shear 的 setFrame 是同指 0x282ad4 的 4 字节 thunk**（父代理逐字核对）；
E2 的 setError json 实参=**动画节点**（连带兄弟被 dispose），E3=NULL——错误
路径 json 实参三种形态（根树/NULL/动画节点）逐块验证。4 配置×18 测试、12 变异。

`c/spine_read_tl_ik/`（子代理 H，父代理复跑 RESULT PASS）：**普查 open #6
关闭**——指针扫描：count 快照一次、`ble` 有符号、前索引写回逐元素重读、
首个命中写 +0x14、未命中不写；create 后 +0x14=calloc 零=0 非 -1（静态推断）；
帧键 time/mix(默认1.0f)/bendPositive(0→-1,非0→+1)；帧距 **3 浮点**；
setFrame ABI r0..r3+[sp]。4 配置×13 测试、11 变异、3 拒绝门。
回执 `tl_bones_check-20261108T113000.json` / `tl_ik_check-20261108T112242.json`。
见 `reconstruction/contracts/native-animations.md` 第四批节。原件未执行。

`c/spine_read_animations/` 扩展（子代理 E，父代理复跑 RESULT PASS）：B3 拆
`animationFrameInit`（4 键入槽 + 0x55555556 魔数→[sp,#0x60]）与
`animationKeys`（8 键getItem按地址序落槽）；B4 求和分组**不对称**
（bones/slots/paths 逐子累加，ik/transform 只加节点 +0x0c 一次，deform 双层，
drawOrder/events 各 +1），name=动画节点 Json 成员键，spAnimation_create 合成边界；
B3b 'draworder' 兜底无条件写。4 配置×20 测试、13 变异、2 拒绝门。
**普查更正**：Json_getItem 内部是 strcasecmp（0x287414→0xb66d0，父代理核对
.rel.plt）——drawOrder/draworder 是同一查询，双键 fallback 行为上无效。

`c/spine_read_tl_slots/`（子代理 F，父代理复跑 RESULT PASS）：B5 attachment
（findSlotIndex 真实链、timeline+0x10=slotIndex、kind 判别位 +0x08==2）、
B8 color hex 通道（timeline+0x14、真实 toColor×4 + 真实 readCurve、
color+0x08=(frameCount-1)*19 curves 数组）、B8b 尾（+0x10 帧距5）、
E1 错误（setError json 实参 NULL、spAnimation_dispose+dispose data）。
4 配置×11 测试、10 变异、3 拒绝门（含去 readCurve/toColor 源的**真实链接门**）。
回执 `animations_b3b4_check-20261108T110203.json` / `tl_slots_check-20261108T110414.json`。
见 `reconstruction/contracts/native-animations.md` 第三批节。原件未执行。

普查更正（累计三条）：①§7 #10 数组基址在 B2 写入；②Json_getItem=strcasecmp
（§2.9 双键优先级作废）；③B8b 非"公共尾"、readCurve 调用点在 B8 区间。

`c/spine_read_animations/`（子代理施工、父代理复跑 RESULT PASS）：B1 events 数组
+ EventData 循环（malloc 1028/1034，**事件名取 Json+0x1c 成员键**、循环不信 count、
无错误路径）；B2 animations 数组（malloc 1043，**不写 animationsCount**——计数在
循环尾 0x28e784）。9 测试×4 配置、9 变异全拒。
`c/spine_read_curve/`（同上验收）：`readCurve@0x28b34c..0x28b3fc` ABI 三参
（帧 Json/时间线指针/0 基帧号），**curve 数组无视声明计数无条件取 4 元素**，
少于 4 = 原件空指针解引用（SIGSEGV probe 钉住），"stepped" 精确 strcmp 尾调
setStepped；普查 open #2（曲线数据形状）已钉死。8 变异+probe。
回执 `animations_entry_check-20261108T103440.json` / `curve_check-20261108T103809.json`。
见 `reconstruction/contracts/native-animations.md`。原件未执行。

普查更正两条（实测）：①§7 open #10 的数组基址其实在 B2 0x28d2cc 就写入，
循环尾只写 count 与元素；②`asm/functions.tsv` 的 `anon_28b34c`（944B/237 insns）
把 readCurve/_readVertices/toColor 三个匿名函数并成一条——引用时以
0x28b3fc=0xe92d4ff0 字钉为界，索引口径缺陷登记不动表。

animations/events 段静态普查已落盘（2026-11-08，子代理施工、父代理抽验）：
段界 **0x28d19c..0x28eb40**（三证：唯一前驱 0x28ccc8/0x28cd08 都在 linked-mesh
后处理出口；0x28d198 无条件跳走；符号 size 定尾）；1641 条（1601 指令位+40 池字）、
46 唯一键、段内 7 malloc 锚（**行号补正三处**：0x28b974→608、0x28cfd4→136、
0x28e154→388，均为 `mov r2` 旋转立即数，非 movw）、52 唯一被调、**无 switch 跳表**
（类型分派全 strcmp 链 ×10）、**31 分块表**（1579 可达指令逐块对上）。
`asm/animations_census.tsv` + `asm/animations_segment_map.md`。
**注意**：段内 22 条属附件段离位块（0x28e7f4..0x28e820、0x28e880..0x28e8ac），
恢复时必须排除；drawOrder/draworder 双键、hex color 通道、IK/transform 指针扫描
求索引（不判空）等 12 条 open 已列 §7。

`c/spine_region_geometry/` 新增updateOffset原方法候选（304B代码+4B池）。
`c/spine_read_region/` caller扩至0x28cdac..0x28cf24，补齐color→updateOffset→当前loader configure；
canonical parser替代旧scale快照和源内重复声明，不改width/height原默认32.0f。

实际public create wrapper→atlas工厂→Json字段→toColor→局部offset→configure→析构已实跑。
原libm是double cos/sin：先float32角乘再widen；cos先narrow再sin，sin后读x/y；
几何快照和真实VFP非融合指令保留。libm provider是明确预置值，不是原件oracle或数学库恢复。

O0/O2/O3/UBSan各14项，19个语义变异由登记用例拒绝；缺本体/缺math/软浮点/hardfloat四拒绝门通过。
32项执行源/头/夹具/checker绑定；独立静态复核无阻塞发现，父级重解PLT/GOT；
linked四档15项/17变异、mesh四档16项/16变异与旧native-spine链重过。
见 `reconstruction/contracts/native-region.md` 与模块functions.json。原件未执行，不称原版等价或已显示sprite。

前批linked/skin与真实错误清理仍可消费；公共skin/slot外循环及events/animations尚未总装。
下一入口补公共外循环（slots 循环条件 0x28bd7c 与 "Slot bone not found" 错误路径的
dispose/setError 链在此批接入）；真实_readFile、console构造、
完整loader继续保留缺口，不将合成provider算恢复。全游戏玩法与原版差距本批未测量。

## 决定性发现：spine-c 源码行号锚（2026-11-07）

readSkeletonData 的全部 25 个 `_malloc(size, tag, line)` 调用点中，tag 均为
`jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c`，line 覆盖 442–1043。
整个 13,044B / 3,261 insn 函数来自单一源文件。JSON key 集合
（shearX/shearY/inheritRotation/inheritScale/rotateMix/translateMix/scaleMix/shearMix/
chain/chainScale/path/multiply/screen）只说明有相应特性，**不能唯一锁定 spine-c 版本**；
现有 bendPositive、五类 attachment 与 region 默认 32 等证据呈版本混合/定制分歧，不照抄 stock。

按 malloc 行号分段（每段可独立恢复+差分）：

| 段 | 行号（malloc 锚实证，2026-11-08 段链普查校正） | JSON keys | 内容 |
|---|---|---|---|
| 入口+meta | 607(+608) | hash/spine/version/width/height | locale 保护+骨架元数据 |
| bones | 615 | name/parent/x/y/rotation/scaleX/scaleY/shearX/shearY/inheritRotation/inheritScale | 骨数组+逐骨 |
| slots | 651 | bone/color/attachment | 槽数组 |
| ik | 697(+705) | bones/bendDirection/mix | IK 约束 |
| transform | 735(+743) | rotateMix/translateMix/scaleMix/shearMix/target/offset | 变换约束 |
| path | 782(+791) | path/position/spacing/rotateMix | 路径约束 |
| skins | 839 | skins 递归 | 皮肤+附件 |
| attachments | 891 | region/mesh/linkedmesh/boundingbox/type | 附件四类 |
| animations | 1028/1034/1043(+388/442/445/494) | time/offsets/events/curves | 动画+事件 |

（旧行号列 697–712/735–760/782–800/810–830 自 697 起四行各错位一段；校准证据：
各段 malloc 目标偏移与 findIkConstraint +0x3c/+0x40、findTransformConstraint
+0x44/+0x48、findPathConstraint +0x4c/+0x50、findSkin +0x20/+0x24 一一对应，
见 `asm/segment_chain_map.md` §7。）

入口段（locale guard + Json_create + "skeleton" getItem）已恢复为 ARM32 C 候选
（`c/spine_read_entry/`，0bb501a）。"C" 锚 0x3390a8、"skeleton" 锚 0x357b5c 已解析。

## 当前问题与优先级

以 `METHOD.md` 第0节为现行合同：先做原版完整 libyoyo 的逐函数静态语义/可编译 C 译文，
原件执行、ART/Unicorn、画面和整机验证后置；不以可达子集、索引满锚或自测通过替换完成。
原版 ELF 现量 9,267 条已定义可执行函数符号、8,926 个唯一地址+ISA 入口；
既有匿名切分表为 646 个候选段，边界尚未全部定案，不能直接拿来当函数分母。
当前优先收已接入链的共享内部依赖。新增 allocation 六入口、attachment-loader 四入口、
skeletonData 创建/完整释放及直接依赖十三入口的 C 本体候选；逐函数身份/源哈希/缺口分别在
`c/{spine_alloc,spine_attachment,spine_skeleton_data}/functions.json`，全库退出条件未满足。
累计重建消费者已直接链接 allocator→attachment→JSON→骨骼与data/atlas清理，
初始malloc槽和Debug两路径分开验。当前批又恢复attachment工厂/分派/具体销毁
十九入口，以及Atlas三公开入口和六个去符号helper；共享atlas/page/region仅一份12/44/80B头。
新atlas_parse_chain实际跑text→Atlas解析→五路attachment→真实销毁，区别于旧native_chain
仍有合成atlas/JSON接口；全套入口当前构建运行八个ARM32重建程序。原件未运行，两个新模块
已完成独立字节审查与F1调用帧修缮复审；不将其自测或本体数量说成全库/原版等价。
当前明确缺口为库内spSkeletonJson_readSkeletonData（0x28b84c/13044B/3261insn）主体及
其它虚类型/渲染消费者及全库匿名边界；_spAtlasPage_createTexture 已于 2026-11-06 恢复为 ARM32 C 候选（78569a4），
JSON 访问接口（Json_getItem/getString/getFloat/getInt）与 setError/readSkeletonDataFile 已恢复（0300d5f/07e7663）。

## 2026-11-01 校准：下方为历史记录，不是当前完成率

- `asm/functions.tsv` 现有 9,538 行、9,199 个去重入口；其中 272 行是 `anon_` 区间，别名、匿名切分和真实函数之间不能直接画等号。
- 当前 246 张顶层卡覆盖索引 649,229/649,229 个去重地址；跨卡重复、索引外地址及助记符不匹配均为 0。索引含 literal pool 的反汇编条目，这只说明索引和锚点对应，不等于全部是真指令，更不等于理解或翻译完成。
- 旧「正文 347 函数」与「68.7%」都不是经逐函数验收的语义完成率；全文多数 `All_*` 是明确不主张语义的结构骨架。部分卡多函数共用卡头等级，不能按首个等级机械认定每个函数已完成。
- 当前 `c/` 有 boxType、DoNeg、DoNot、CObjectGM::LoadFromChunk（记录头局部）、Sprite_Data、Sprite_Number、Sprite_Exists、CSprite::Clear、CSprite::LoadFromChunk、CSprite::FreeMask、CSprite::FreeTexture、CSprite::ClearSWFData、CSkeletonSprite 构造/析构和 SimpleDecode 的有限译文候选；另新增 spine JSON 的 createWithLoader/create/dispose、atlas/page/region 的 dispose 与 page 纹理回调七个入口，接入扩展 Loader/Clear 消费者（见 `c/spine_lifetime/README.md`）。其中部分仍未覆盖所有分支；译文目标数不等于完整等价函数数，C1/C2、D1/D2 别名不重复计数。
- 历史原件侧 Unicorn 回执针对 boxType、DoNeg、DoNot、CObjectGM::LoadFromChunk 的有限输入域；它们不是本轮实验，也不代表完整函数、设备或整个库已对拍。回执中 DoNeg/DoNot mode 1、2 和 OBJT 尾部明确未覆盖；须按各回执作用域引用。
- 本轮按用户阶段门只做静态推导和自建译文夹具，不执行原件、ART 或 Unicorn。全库逐函数语义闭合、可编译译文覆盖、跨单元 ABI 与真实原版差分均无可信全量完成率。

以下内容保留原时间的历史口径，其中数字与结论可能过时。

一句话：**引擎的语义骨架已经定性完，剩下的是外围（12 张 init 表、约 600 个匿名段、库内部）。**
方法已钉死在 `METHOD.md`，接手的人不需要重新吵怎么算数。

## 账

    cards                245 张全部已提交；多节卡按 @func 算 9,083 节 + 3 张残段卡
    anchors              **649,229 条 = census 指令基线 100%**（每条指令恰好一张卡主张），全部 RESULT EXACT
    跨卡共享地址          0
    claims               1,742 条（proven 1,469 / narrowed 117 / open 138 / refuted 11 / inferred 7；
                         权威数以 verify_reverse_v1.py 为准，claims.jsonl 是含 20 条重复的局部聚合）
    运行期证据（新）      **4 条 oracle 臂**：DoNeg 378/378（mode 0+3..15+mode 1/2）、DoNot 404/404
                         （mode 0+3..15+mode 1）、boxType 97/97（类型 0..9 与越界）、
                         **CObjectGM::LoadFromChunk 104/104（OBJT 记录头 src+0x00..0x1f）**。
                         四臂各 5 个变异体有牙。最后一条是资源加载链上的第一个臂：字段映射是从
                         原件行为单字节扫描出来的，不是从资产文档抄的。剩余 46 个 Do* 与绝大多数
                         其它函数仍只有静态字节证据
    指令基线             649,229（Thumb 双遍解码）
    函数                 9,538 具名 + 272 匿名块 → 636 段
    覆盖口径（机械账，已闭合） asm/instructions.jsonl 的 649,229 条指令 **全部落锚**；跨卡共享地址 0。
                         可达集子账：1,439 函数 / 148,233 条 = 100%（Reach_01-14 + Anon_26f1e8）。
                                                  其余：All_15-68（54 张，可达集外的库函数）+ Residue_Attributed_01-03（17,581 条 Thumb-2 半字段，按 census 归组到 812 个具名函数）。
                         ⚠ 「每条指令都指到了」≠「每条语义都读懂了」：按卡级别（锚点发生次数口径，与严格 (addr,mnem)
                         计数的 649,229）：正文 79,473 = 12.2%，骨架 571,817 = 12.2% 之外骨架占 87.8%；
                         **桩 0 / 未标 0** —— 全部 245 张卡都已到骨架及以上；残段批已从「地址级」纠正为「按函数归属」（CSprite_SWF、anon_batch2、LibInterfaces、
                         Graphics_Interface、Stubs_TailJumps、Residue_01-03 的级别行已统一成工具可读形式）。
                         按 @func 计 正文 347 个函数 / 骨架 8,736 个。语义欠账全在骨架与桩卡里。
                         ⚠ 生成器缺陷已修（RESIDUE-001）：gen_func_cards.py 原用 4 字节步进取指令，
                         Thumb-2 函数会被漏掉一半字指令；现已改为按 instructions.jsonl 的真实地址遍历。
                         ⚠ 旧口径（63.6% → 78.4% → 87.6%）作废：分子取全库 @func（含不可达库函数）、分母只算可达字节。

## 运行期证据（oracle 臂，2026-11-01 起）

本线此前全部是 `bytecode_anchored`。现在有了第一个**原版二进制 vs C 重建**的差分臂：

    装置      reconstruction/reverse-v1/harness/{handler_oracle.py,do_neg_diff.py,do_not_diff.py}
    C 重建    reconstruction/reverse-v1/c/do_neg.c（tier: bytecode_anchored 的直译）
    判据      返回栈指针 / 16 字节槽 / VMError 文案，三面逐例全等
    输入域    seed 0xCA11，282 例；cls 0..15、tag 0..15 全覆盖 + 随机尾 120
    回执      receipts/do_neg_diff-20261101T002634.json、receipts/do_not_diff-20261101T003428.json
              （各含输入 sha256 与 C 源 sha256，重跑同结果）
    门        identity / coverage×2 / non_degenerate / teeth 全 PASS
    判别性反例 5 个 -DMUTANT 变异体分别被 2/17/20/31/14 例抓住

    由它纠正的原卡错误  DoNeg.c 段 2 把 cls 6 的文案写成 "DoNeg :1: …"，实际是 "DoNeg :: …"
                        （带 :1: 的是 cls 5 tag1）→ NEG-ORA-007 refuted；DoNot.c tag1 文案写成短式
                        "Cannot operate on string type"，实际是 "DoNot :: Execution Engine - …" → DNOT-ORA-004
    由它推翻的"合理模型" DoNot cls 0 的 ~ 不是符号翻转、也不是饱和转换：原版走
                        __fixdfdi(0x3194a0, 非饱和) → NOT → __floatdidf，实测 +Inf→-1.0、-Inf→+1.0、
                        2^63→2^63、DBL_MAX→-1.0 → DNOT-ORA-002（首轮 35 条 mismatch 抓出来的）
    装置边界            Unicorn 不建模 FPSCR.RMode，浮点→整型的舍入本装置判不了 → DNOT-ORA-005 narrowed
    由它新增的语义      tag 字是**整字比较**（无掩码），高字节非零一律 Malformed；NEG-ORA-006
    仍未覆盖            mode 1 / mode 2（需 boxType + F_JS_ToNumber 真实执行）→ NEG-ORA-010 narrowed

**怎么读这条账**：这是 1 个处理器的 1 个臂，不是 48 个处理器。其余 47 个 Do* 与全部房间/实例/
变量函数仍然只有静态字节证据。接下一个处理器的流程与门定义写在 `harness/README.md`，
新臂一律先写变异体再谈 identical。

**账本对新标准的合规性**（只读审计，不改 status）：
`reconstruction/contracts/claims-standard-audit.md`，由 `scripts/claim_standard_audit.py` 生成。
1,760 条去重 claims 里，正文带装置（oracle/harness/seed/回执）的 103 条，纯静态地址的 899 条，
**正文断言运行期行为但证据只有地址的 695 条**（这批按新标准只能当 `bytecode_anchored` 引用，
不得作行为门）。审计只给分类与样本，降级动作留给账本所有者，改完须重跑 `verify_reverse_v1.py`。

## 已定性（有卡、有锚点、能指名到函数）

    VM 骨架        基础 opcode 表（.data 0x3f20b4，32 项）｜逐 CODE 线程化派发（VMExec+0x5c → +0x58 → blx）
                   48 个 Do* 处理器｜Code_Execute / ExecuteIt / VM::Exec / ExecRelease / PerformReturn
    值模型        RValue 16 B、tag 在 +12、0..14（0/13 real、1 string、2 array、3 pointer、5 undefined、
                   7 int32、10 int64、12 null、0x00FFFFFF = 未解析变量）
    变量系统      id 基址 100000、槽步长 16｜局部 self+4 / 全局 GOT 单例+4 / 实例 hash=key+1
                   Variable_GetValue/SetValue/GetObjectName/BuiltIn_Add/GetName_Scope/Global_Init
    调用帧        frame=sp-60；+0 pc、+0x08 旧 Argument、+0x38 旧 sp 偏移、+0x4c 深度
    函数表        80 B/项（name 内联 64B / fn +0x40 / argc +0x44 / flag +0x48 / +0x4c -1）；
                   InitYoYoFunctions 385 条（平台层，与游戏用的 87 个无交集）
    常量池        INITIALIZE_Code_Constant = GML 命名常量池（513 次调用→501 名，启动期 606）
    内建变量      InitGlobalVariables 120 + 5 = 125 个；实例侧 80 个字段（12 alarm + 68）
    房间/层       CRoom 292 B 字段表｜两链 +0x84 头/+0x80 尾/+0x17c next/+0x178 prev｜
                   CLayer 112 B + 三张 CHashMap｜层链按 +0x04 升序
    实例          CInstance 432 B 完整初值表｜两链搬运 UpdateActive｜bbox = int32 tagYYRECT
    事件          Perform_Event → Perform_Event_Object → Perform_Event_All 三层；Other 四趟
    绘制          DrawTheRoom 条件树（+0xdc / +0xb8 / +0x88）｜DoSlowDrawRoom 三股流｜
                   快路径二分支｜清屏 flag 只有 2 位且深度与模板同一位
    资源           game.droid 头部 8 B、31 tag 块链、24 个处理点｜WAD 地址 0x544c44
    存档          18 段（Command_SaveGame）｜CRoom/CInstance 序列化逐项互逆、丢字段清单
    JNI           JNIEnv 只存 TLS（0x756c04）、无 GetJavaVM、jclass 0x756d44、79 个方法 ID 与 DEX 79/79
    ISA           563 个 Thumb-2 具名函数 + 14 个匿名段（调用点编码证明）
    静态库        Box2D 2.3.0｜PCRE 8.34+ 的 8.x（版本串是构建模板）｜zlib 1.2.3 动态｜
                   libpng 1.4.19｜libjpeg｜spine-c｜freealut｜vorbisfile

## 未定性（按重要性）

    1  ~~12 个 Init*Functions 表~~ **已收（2026-10-28 后一批）**：26 个 Init* 函数全部出卡
       （cards/InitTables_{Core,Draw3D,Resource,InputAction,System}.c），2,434 条注册逐条解出四实参，
       游戏调用的 99 个内建里 97 个已指到注册点，另 2 个（AdColony_*）本构建无实现。
       残留 open：29 条运行期实参（14 条 joystick_* 的 flag = *(u8)0x5428e8、Init3D 13 条、InitGame 1 条、
       InitResource 1 条）与「同名双注册的查找语义」
    2  匿名段：≥512 B 共 143 段 / 226,028 B；已出骨架卡 8 段（cards/anon_batch6.c，按 in-degree 取的头部：
       anon_264c00(90)/26020c(88)/262680(61)/2636d4(19)/276e68(15)/2fc4e8(5)/300004(5)/234434(4)），
       余 97 段 / 213,116 B 未出卡（最大 anon_270108 15,156 B、anon_273c3c 12,844 B、anon_303c46 12,830 B）
    3  freetype（TT_RunIns 7.8 KB）、pcre compile_branch（23.5 KB）的内部
    4  几个反复出现的未定语义：g_isZeus(0x5428e8) —— **消费面已清（cards/GateBytes.c）**：52 个点全经槽
       0x3ed92c，唯一写点 0x1dd844 在 GetResolution 内，读点覆盖 DrawTheRoom/UpdateViews/存档/StartRoom/
       InitGame 等与 14 条 joystick_* 注册的 flag；语义（取值域、是否「Zeus/高清」开关）仍 open。
       0x755363 —— 消费面 31 点（CheckLicense/全部 Audio_*/SoundHardware::Init/ProcessCommandLine），
       **本普查未发现写点**；option_use_fast_collision(0x542379) 的写者、0x47f295 门字节、
       DoSet K=7..10 的四个 JS 抽象关系算子、Shl/Shr 的 bit15 仍 open
    5  Motion_Grid_Path 的障碍编码矛盾（入口按 <0 判失败、扩展闸门按 ≤0 判入）

## 实现侧（Rust VM）

    已完成   Vec<f64> → Vec<Value>{tag,payload}；补 Rem/Mod/Or/Xor/Shl/Shr/Neg；
             Constant 带 tag；Dup/Not 带 mode；sp 按操作数宽度记字节；放开非有限值
    差分     4,400 例：identical 4,207（95.6%），剩余 193
             剩余按 op：add 63、conv 48、sub 28、div 26、mul 24、neg 3、not 1
             按轴：ok 相反 101、错误串 25、sp+bytes+tag 28、sp 19、sp+bytes 7、bytes 13
    下一步   ① conv→string 需要 host 字符串池 + snprintf ② add/sub/div 的 pair 表与 mode1
             ③ sp 装箱 54 例（flags&2 进 Op）④ 之后才谈里程碑 2 的整段轨迹差分

## 接手顺序建议

    1  12 张 init 表（每轮 4 并发，增量落盘），把 87 个 builtin 的注册点全钉住
    2  匿名段按 in-degree 吃（≥512 B 的优先）；新遇到 Thumb 用调用点编码判
    3  差分收尾 193 例
    4  freetype/pcre 内部只做接口级，不逐指令

## 验牌（逐卡审计，2026-10-29 收口）

工具 `scripts/audit_cards.py`，账本 `reconstruction/reverse-v1/CARD-AUDIT.tsv`（每卡一行）。

    FAIL 三类  ① 无级别行 ② 锚点不在 asm/instructions.jsonl ③ @func 声明条数 ≠ 本卡在 [start,end) 里的锚点数
    不算 FAIL  partial（只覆盖函数一部分）——信息项；全库覆盖与互斥由 verify 的 anchors==649,229 / shared==0 保证
    END 约定   scripts/fix_card_metadata.py 已把所有 @func 头统一成「end 排他、size=end-start、count=本卡锚点数」

    **结果：245 张卡全部通过（244 一次过 + All_68 的一处 off-by-one 已修）**
    修的手段：150 张卡范围按自身锚点重算；68 张插入「部分覆盖: 本节 X/Y 条」；VMError 56→61；
              Reach_02 删掉已移交节的 @func；All_68 一处 10→11
    另立工具 scripts/merge_overlapping_sections.py（同函数多节可合并；本轮实测几乎无同函数重叠，未启用）
