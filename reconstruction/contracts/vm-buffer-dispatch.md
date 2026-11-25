# ARMv7 CCode / VMBuffer → ExecRelease 装载与派发表合同

输入：Cally's Caves 2 2.1.9 `lib/armeabi-v7a/libyoyo.so`，SHA256
`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
证据档位 `bytecode_anchored`（原件 ARM-state 机器字静态推导）；不含原件执行、玩法等价或 Rust 接入结论。
原始锚点在 `../reverse-v1/cards/Reach_05.c` §9、`Reach_13.c` §283、`VM_Exec.c`、
`DoCallScript.c`、`PerformReturn.c`、`VM_ExecRelease.c`，本批不再复制锚点所有权。

## 三张表的索引不能混用

| 表 | 索引 → 值 | 原件锚点 |
|---|---|---|
| `g_instructions` `.data` `0x3f20b4..0x3f2134`（右开） | opcode `[28:24]` → 默认处理器地址；32 个四字节槽，30/31 同址 | `.dynsym` 对象大小 `0x80`，32 条 `R_ARM_RELATIVE`；`0xecb1c` → GOT `0x3edcf8` → 对象；`0xec908` 查表 |
| `VMBuffer+0x18` → `VMExec+0x5c` | 字节 PC 除以 4（向零舍入）→ 密集处理器槽号 | `0xec954..0xec96c` 写槽号；`0xe4598..0xe45c0` 读出 |
| `VMBuffer+0x14` → `VMExec+0x58` | 密集槽号 → 该 CODE 的处理器地址 | `0xec900..0xec90c` 默认路写；`0xe45cc` 取第一次的目标，`0xe4640` 预取下一目标 |

**谁装两张逐 CODE 表**：`VM::Exec` 在 `0xe80b4` 以 `sp+0x18` 建 VMExec 基址，`0xe8164` 转换 `CCode+0x50` 指向的 VMBuffer，`0xe8174..0xe8184` 把 buffer 的 `+0x18/+0x14` 存到栈的 `+0x74/+0x70`，也就是 exec 的 `+0x5c/+0x58`。`DoCallScript` 在 `0xe86d8..0xe8714` 进子帧时安装同一布局；`PerformReturn` 在 `0xe43c0..0xe43f4` 用保存的 VMBuffer 恢复。两条帧切换边也重算 `+0x48`。`DoBreak` 的调试单步路径另从 `g_instructions` 按 opcode 直接取项（`0xd8510..0xd8528`），不代表 Release 走同一条路。

## `VMBuffer::convertBuffer`（`0xec750..0xecb34`，239 指令 + 10 池字）

- `r0` 是 VMBuffer `this`；上述三个调用站点取回的是结构字段，不消费 r0 返回值。`+0x04` 为有符号字节跨度，`+0x10` 是字节码。`+0x14` 非空即返回（`0xec758..0xec774`）。空时先查 `0x47f3a0` 的缓存：`0xec748` 对字节码指针原始值加 1，`0xec790` 清 bit31；桶步长 12，匹配其 `+8` 的 hash 后只读取 `+4` 并写 VMBuffer `+0x14`，**不写 +0x18**（`0xec9b4..0xec9cc`）。未证明缓存何时填充或为什么命中支路不安装第二张表。
- 冷转换先用 `0xec83c..0xec868` 计数，后用 `0xec928..0xec950` 再读字推进。步长是 `4 + (bit30 ? g_paramSize[bits19:16] : 0)`；`g_paramSize` 的 16 个原字在 `0x3f2018`：`8,4,4,8,4,4,4,4,0,0,0,0,0,0,0,0`。`0xecb14` 经 `0x3edcf4` 绑定该对象。
- 正跨度有 N 个指令头时，`0xec870..0xec8e4` 用 `MemoryManager::Alloc(bytes,file,line,1)` 先分配并发布 `4*(N+1)` 字节到 `+0x14`（`VMBuffer.cpp:126`），再分配并发布 `4*(trunc(len/4)+1)` 字节到 `+0x18`（同文件 127）。非正跨度 `0xecac0..0xecb08` 的第一块固定 4 字节，两次分配后直接退出；不读指令。
- 生成第二遍只在每条真实指令的起始字写 `offset_to_slot[pc/4]=slot`，载荷字及终端余槽不会写入编号（`0xec96c/0xec910..0xec920`）。处理器从默认表或下列分支选出，按密集槽顺序写入。不要据此把每个字都当 opcode，也不把 buffer 字节总数当处理器总数。

| opcode | 专用选择（不命中即默认表） | 证据 |
|---|---|---|
| 7 | `[23:16]==0x52` 且 `[11:8]==0` → `DoConvIntToVariable` | `0xec974..0xec9a8`；GOT `0x3edd7c` → `0xd773c` |
| 5 | 两个类型半字节都为 5、低 16 位为 `0xfff9`、且 bit30 置位 → `DoPopLocalVariable` | `0xec9d0..0xeca04`、`0xeca6c..0xeca84`；GOT `0x3edd84` → `0xe1f5c` |
| 25 | `[19:16]==2` 才读紧接的四字节 id。`((uint32_t)id - 100000u) <= 400000u && id != 499999` → `DoCallGML`；否则有符号 id `<=99999` → `DoCallLibrary`。余下走 `g_instructions[25]` | `0xeca08..0xeca50`、`0xeca88..0xecabc`；GOT `0x3edd80/0x3edd88` → `0xe8b00/0xe3e58` |

### 转换缓存的构造与退出边

`.init_array[VA 0x3eb5f0]` 的 `R_ARM_RELATIVE` 槽指向 ARM 入口 `0xb95dc`（`cards/All_17.c`）。它不是从转换函数名猜出的写方：`0xb95e4` 读池 `0xb9694`，`0xb95f4 + 8 + word = 0x47f3a0`，正是转换读端 `0xec784` 算出的对象。`0xb9608..0xb966c` 设容量 8、掩码 7，先清桶指针再分配并发布 96 字节（8×12 字节），清零桶/计数；阈值为 `(int)(capacity * 0.6f)`，初始正常值为 4。

`0xb9670..0xb968c` 向 `__aeabi_atexit` 交 `object=0x47f3a0`、`dtor=0xec47c`（GOT `0x3edd8c`）、`dso=0x3f2000`。目标的动态符号是 `CHashMap<unsigned char*, void**, 3>::~CHashMap`；`0xec484..0xec498` 非空才 `Free(+0x10)` 并清该字段（`cards/All_67.c`）。这是桶数组的析构，不是逐桶释放处理器表。独立的 `VMBuffer::~VMBuffer` 在 `0xce444..0xce480` 分别释放自身非空的 `+0x14/+0x18` 并清零（`cards/All_60.c`）。缓存的插入、运行期失效、缓存命中后的索引表来源和处理器表所有权仍待证；已找到构造/析构不能代替这几条边。

## `VM_ExecRelease` C 译文与证据边界

本体候选在 `../reverse-v1/c/vm_exec_release/`，登记按 `0xe4540 + ARM-state + image_sha256`。
`VM::Exec` 的 `0xe8324` 调用以 `r0=exec/r1=out` 进入（`0xe81b0/0xe81b4`），共同返回尾不消费 r0。
本体开头增加 `g_execCount`、发布 `g_pCurrentExec` 后才保存 `g_ArgumentCount`（`0xe4560..0xe4594`）；
顶层退出恢复的是实参数，不在这里恢复 `g_pCurrentExec`（`0xe46ac..0xe46c4`）。

| 阶段 | 本体可见副作用 | 原件锚点 |
|---|---|---|
| 帧入口/回边 | 入口先查表并写下一槽，再判断有符号字节 PC 是否到 `+0x50`；回边重读游标、表、字节 PC 与上限 | `0xe4598..0xe45d0`, `0xe4624..0xe469c` |
| 异常 | 按实时 `g_pCurrentExec == g_caughtExec` 决定是否搬 `g_exceptionVar` 四字到 `g_pExceptionSP-16`、清 `g_fDoExceptionUnwind`；不匹配则离开当前帧且不清标志 | `0xe4624..0xe4688`; 池 `0xe47ac/0xe47b0/0xe47b8..0xe47c0` |
| 退帧/结果 | `+0x4c > 0` 调 `PerformReturn`；在返回值栈地址减 16 后清 +0/+4/+12，**保留 +8**，从恢复的字节 PC 查表重入。顶层只在 out 非空且重读的 `+0x28` 无符号高于 SP 时复制四字，全部读完才写 | `0xe4734..0xe4750`, `0xe46a0..0xe46c4`, `0xe477c..0xe479c` |
| 清理 | `stackPages+4` 链扫半开区间 `[page+8,page+0x100008)`；命中则头插到 `+8`，`+0x10` 加一、`+0xc` 减一。未命中走 `MemoryManager::Free`；清理后重读 locals 模式 | `0xe46c8..0xe4730`, `0xe4754..0xe4778` |

复跑（只静态读取原件，qemu-arm 只跑由新 C 编译出的 ARM32 夹具）：

```sh
python3 -B reconstruction/reverse-v1/c/vm_exec_release/tools/check.py --so /path/to/libyoyo_armv7.so
```

工作树内尚未提交的 C 候选，其最后一次合成门绑定四个入口：Release 162 个索引字、PerformReturn 127 个、
convertBuffer 249 个和指针哈希 2 个（均包含各自池字）。O0/O2 通过，18 个具名语义负控、
2 个真实调用者缺 TU 链接负控命中；这是本会话先前的执行回执，本轮 C++ 恢复未重跑它。
两类 Free 等具名提供者仍是夹具模型。不升级为 C++ 行为验收、原件差分或游戏等价。

## `PerformReturn` 的退帧合同

- `0xe42f4..0xe4310` 增加 `g_retCount`，`g_bProfile` 非零则先 `CProfiler::Pop(&g_Profiler)`，随后才读帧与深度；输入 SP 不消费。空 `frame+0x18` 路减深度后直接返回 `frame+60`，不改实参状态（`0xe4314..0xe4330/0xe4490`）。
- `frame[+0x0c]` 非负时旧帧指针为 `exec[+0x08] + exec[+0x40] - distance`，负时是 NULL；写侧 `DoCallScript` `0xe8634..0xe8668` 逆向互证。`+0x08` 是保存的 `g_ArgumentCount`，`+0x38` 是旧 `Argument` 相对分配基址的偏移；不是两个旧栈顶。
- `0xe44ac..0xe44b8` 必要时释放当前 locals 后重读 `exec+0x2c`。之后调用转换；`0xe43c4..0xe43f4` 处理器表仍取转换实参 `buffer+0x14`，索引表取重读对象 `exec[+0x2c][+0x18]`，不能合成一个固定接收者。
- `0xe43f8` 通过 `operator delete`（`0x27d1d0` 仅尾跳 `0x27c2d0`）释放帧中 `+0x28`。遍历最初实参数；位型谓词 `((tag-1) & 0x00fffffc)==0` 才调用 `FREE_RValue__Pre`。所有遍历到的槽保留 `+4`，清 `+0/+8`、写 `+0xc=5`；遍历结束后重读实时实参数算返回 SP，再恢复旧 `Argument` 与参数个数（`0xe4410..0xe4498`）。

上述未提交 C 候选中的 `src/perform_return.c` 与 `src/vm_buffer.c` 已被同一 ARM32 C 合成门
真实链接，转换不再是桩；这些改动不随本次 C++ 源码批次提交。
提供者仍可改变消费者的对象/PC 以检查重读合同。`CProfiler::Pop`、`FREE_RValue__Pre` 与两类
Free 仍未在该门接原件本体。C 清册的头/夹具哈希更新尚未收口，不把门绿等同于登记完成。

## 同语言 C++ 源码恢复

源码入口为 `../reverse-v1/cpp/vm_buffer/vm_buffer.hpp`：恢复 `VMBuffer` 的虚析构、转换方法，
以及真实继承它的 `VMWriteBuffer` 构造/析构、Reserve、Add 和五个 AddVal 重载；
`wad_memory.cpp` 恢复直接依赖 `MemoryInWad`，不是只把旧 `.c` 改后缀。

- 布局：原 vtable `0x3eb8a8` 与派生 RTTI `0x3eb948`；CCode 的 `0xcf10c` 确认 base 分配
  28 字节，`0xcf1fc..0xcf20c` 填 +4/+8/+c/+10；派生构造 `0xec5b4` 使用 +0x1c 游标。
  `metadata08/metadata0c` 的用途及未观测派生尾部仍不猜名。字段/访问级别不是原源码逐字还原。
- 析构：`0xce43c/0xce4c0`、`0xec4a4/0xec528` 的虚析构与 deleting 变体由 C++ ABI 表达。
  表先 Free 再清；借用 WAD 的 code 不 delete[]、也不清。`MemoryInWad` `0x1aad50` 对 base/end
  两端都是包含比较，读取 end 后读 base，不能凭惯例改成半开区间。
- 写入：`Reserve` `0xec604` 保留扩容后容量重读、先发布 cursor 再发布 code 的顺序；
  原方法没有释放旧块，不据此臆测分配器全局回收策略。`Add` 逐个 STR 四字节字，不增加每字
  libc 调用。`AddVal(float)` `0xec6fc` 保留先转 double、只写低四字节的原件行为。
- CALL2 排除值由原字 `0xec8c4=e30a211f` 与 `0xec8cc=e3402007` 确定为 `0x7a11f=499999`。
  子代理将它误读成 500000 的改判已拒绝；旧 C 在此处原本正确，不改旧 C 迎合误判。
- 静态边界：`functions.json` 按原件入口+ISA登记 15 个唯一 ABI 入口、18 个含别名符号，
  对应 13 个 C++ 方法/自由函数。与既有 C 同址的译文不重复计新增原函数。
  `original-words.tsv` 的每个原字均从固定 ELF 重新提取并核字节；不是新增卡片锚点所有权。

本批仅作 ARM32 O0/O2 目标对象编译、类布局/原符号/vtable 尺寸核对及静态源审查，不运行
原件或重建件。编译参数与输入哈希见该目录 `validation.json`；C++ 重编译不承接 C 合成门的
行为结论。匿名缓存绑定、分配/释放器和处理器正文仍有内部依赖欠账，异常展开与产品接入未验。

## CCode 的同语言构造与生命周期

源码在 `../reverse-v1/cpp/ccode/`：`ccode_construct.cpp` 恢复构造（0xcefc8，C1/C2 同址），
`ccode_lifetime.cpp` 恢复虚析构（0xce2b8 的 D1/D2、0xce36c 的 deleting 变体）与
GetText（0xcf470，读 +0x10 而非 +0x58）。观察字段与原字绑定见该目录头和 functions.json。

- `g_fYYC` 分支从 `g_pLLVMVars[+0x1c]` 的 8 字节表取 name/entry，不分配 VMBuffer，也不新增
  index 检查。非 YYC 的无效 index 仍走空文本/null name 与共同尾，不伪装成构造失败。
- 有效 CODE 路径先 new/发布主 VMBuffer，再作 WAD-relative name/record 与 DEBUG-relative
  text/info 解析。新布局保留 record+12+relative 字节码关系；旧布局 code=record+8，仍复制
  两个半字但 locals/recordOffset/argumentCount 写零，不能拿新格式去“修复”该支路。
- text 捕获在原装载边界；初始状态按 +0x58、+0x0c、+0x08 顺序发布，再作 44 字节和
  16 字节两次独立 memset。登记读取 memset 后的 index 字段，而非预缓存构造参数。
- 析构 skip 字节只跳过 unlink/计数，仍虚删除主 buffer。不论 head 空、匹配或未找到，
  skip==0 的计数均减一；不加“找到才减”或环检测。debugBuffer 和文本不在此析构释放，
  不从这一条方法推断其他所有权生产者。空/无效 offset 保留无守卫源码读，但不认证 fault 等价。

静态回指原件的链为 CODE/YYC/DEBUG → CCode → VMBuffer → convertBuffer → VMExec；
此图不是重建游戏已接通的证明。本批构建把三个 CCode TU 与已提交的四个 buffer TU 组合，
核到 6 个新增 CCode 符号及 24 个组合原符号；不把 ABI 别名或 deleting 变体重复算方法。
在盘 CODE 范围交叉核对与已有 Rust 解析器对应记录关系，不能替代运行时分支观测。
全局表生产者、opaque 字段、异常展开、完整 VMExec 和游戏装配仍未闭合。

## VMExec 的执行与退帧 C++ 接线

源码入口 `../reverse-v1/cpp/vm_exec/vm_exec.hpp`，正文为 `vm_exec_release.cpp`、
`perform_return.cpp`、`profiler_pop.cpp`。分别保持原静态成员、C++ 自由函数、普通成员形状；
同址旧 C 仅作语义参照，不混入组合对象或重复计新增原函数。字段与 GOT 重定位见
`layout-evidence.json`；本批三个原入口合计 334 个索引字，含 16 个 literal-pool 字。

- VMExec 的 parent/child、实参数组、name/debugBuffer/sourceText 从 `VM::Exec`
  `0xe804c..0xe8194` 和 `DoCallScript 0xe8614..0xe8714` 的生产端恢复。+0x40 是
  字节跨度：`0xe8048` mov 0x4000 → `0xe8058` str 到 exec+0x40；退帧 `0xe4360/0xe436c/
  0xe4378` 按 allocation + span − distance 重建指针。不能按旧 C 字段名把它扩大成 64 位指针。
- Release 保留初次和每轮 handler 预取早于 PC/异常判断、live current/caught 比较、
  异常/可选结果四字全读后才写，以及退帧清三字但保留 +8。不代替外层调用者恢复 current。
- Return 的 locals 双字段先快照再发布；convert 后 handlers 取 held buffer，map 取另行
  重读的 exec.buffer，顺序不合并；无条件调用原 operator delete 符号。实参循环测试是
  wrapped(argc−1) 的符号，0 与 0x80000001..0xffffffff 跳过，而 0x80000000 进入；
  Argument 仍在测试前读取，只有循环走过才重读实参数。不把它“修成”signed argc>0。
- Pop `0x2a08ac..0x2a0960` 先 Timing_Time 再读 receiver。`0x2a08d4` 的 SUBGT 不置旗标，
  后续取帧地址沿用减前 count 的 CMP；count=1 应取 data[0]，不是 null。这是父级回原字
  推翻 worker 的具体错译，目标编译绿不能发现它。`0x2a0900` 覆盖差值高字，
  `0x2a0918/0x2a091c` 累计的是零扩展 LOW32，仍保留 base/excluded 两个高字的读取。

原件调用关系（不表示重建游戏已经接通）：

    CCode → VMBuffer::convertBuffer → VMExec 两张表
                                       ↓
                                VM::ExecRelease
                                       ↕
                                 PerformReturn → CProfiler::Pop → Timing_Time〔本体未恢复〕

本批 O0/O2 各 11 TU 组合，27 个已恢复原符号齐全；实际包含转换、退帧和 Pop 的定义，
不是把三者都留成声明/桩。MemoryManager/YYObjectBase/RValue 释放、Timing_Time、完整
调用者、全局生产者与异常展开仍是内部欠账；未认证空栈 fault 或原 paired transfer 并发原子性。
所有结果是静态源码和目标编译，不承接旧 C 合成门，不升级为原件运行或游戏等价。

## 循环批次：MemoryManager::Free 与 Timing 的直接依赖

`cpp/memory_manager/` 保留已恢复的 MemoryManager 类声明，以真实 mangled 数据别名连接
m_InUse/m_Total/m_StandardCount/m_StandardSize。Free 的分支顺序从 `0x27c2d0..0x27c42c`
恢复：先锁、log、桶派发；标准双魔数命中才减四计数器并 free(p−16)；负 back-reference
偏移小于 8192 且双魔数命中时原件反而仅跳过 free，不为“修内存泄漏”改行为。
头/偏移全部按 ARM32 地址回绕；尾部 Unlock 仍重读 live g_MemoryMutex，不用 RAII 代换。

匿名 `0x27b918..0x27b948` 由直接 BL、序言与下一定义符号定界，保留为匿名候选；不采用
objdump 最近的 CBucket 标签作为名字。malloc(8)→发布→用 held malloc 结果 Init；原字符串
在 `0x34c5e4`，ADD 站点 `0x27b930`，不是 worker 摘要里的 `0x34c5dc`。
Mutex 嵌入 pthread 字的偏移为 +4，不补 attr_destroy 或失败 guard。logLocation 原件只有
BX LR，所以空正文是原 no-op；独立 TU/无 LTO 编译保留 Free 的显式调用，不声称全程序优化不删除。

`cpp/timing/` 的 C 链接表面恢复 `Timing_Time 0x215148..0x2151b4` 与 `Timing_Init
0x2151b8..0x2151f0`。clock_gettime(1) 的两个 signed32 字经 VFP 转 double，原非融合
VMLA(ns, sec, 1e9) 后 VDIV 1000，再调用原 __fixdfdi；不换 C++ 越界 cast 或整数公式。
转换后才读匿名 epoch 的两字并模 2^64 相减。匿名基址 `0x755290` 与真正 g_TimingStart
`0x755280` 分开绑定。Init 清 epoch→调用 Time→同一快照先写 epoch、后写 TimingStart。

本批 O0/O2 各 16 TU，35 个已恢复原导出符号；另列匿名候选，不自动抬阶段。
globalPageListFindAddr、__fixdfdi、桶的完整 API、pthread/clock 失败域及异常/并发仍未认证。
循环控制状态在用户私有 worklines 目录，验收后直接补下一批；不会把源码批次交付变成原件执行或推送授权。

## 循环批次：页边界查找与 soft conversion 包装

`memory_manager/page_lookup.cpp` 恢复 `0x27be34..0x27bee0`，先读 count 后读数组指针，
按 unsigned 地址做 lower-bound。入口 count×2 仍为 ARM32 回绕后 signed 长度；结束时保留
cursor−base 的带符号奇偶表达式，只有正奇数结果才读前一边界及其 +4 owner，不补判空。
正常有序表上的相等边界向左，不能按惯例重写成 [begin,end) 范围。

父级回原字纠正内环旗标：`0x27bea0=e2531000` SUBS，随后 `0x27bea4=e1a030c3` ASR
没有 S，BNE 用旧 step 非零而非移位后的 step。边界 [0x1000,0x2000,0x3000,0x4000]、
查询 0x1800 的静态反例，worker 错体停在 index0，正确控制流进入 index1；未执行目标。

`c/compiler_conversions/src/conversions.c` 恢复 signed/unsigned 两个 double→64 包装。
__fixdfdi 先调用 __aeabi_dcmplt；负支翻高字 sign bit，调用 unsigned helper 后 u64 取负；
非负支保留原输入。__fixunsdfdi 仍按 __muldf3(2^-32)→fixunsdfsi→floatunsidf→muldf3(2^32)
→subdf3→fixunsdfsi 的链组合 upper:lower，不擅自改 NaN/越界为饱和 cast。
__aeabi_d2lz / __aeabi_d2ulz 分别为同址 GLOBAL alias，而非转发函数；原两入口不重复计数。
父级实测候选 alias 的 size 非零，拒绝 worker 的“常态为零”口述。

18 TU 在 O0/O2 中组合、40 个原导出齐全，转换对象无 native FP 算术；保留五类软件 helper
作为内部欠账。源级 ABI/调用链候选不认证原 LR/尾调用栈可见性、完整浮点行为或游戏等价。

## 循环批次：YYObjectBase 回收与 unsigned32 叶

`object_base/object_free.cpp` 与 `object_free_vars.cpp` 恢复 0x198f88/0x198dac 的静态成员，
不是空 YYObjectBase 上的 delete 表达式。kind3 从实际 vptr+4 调 deleting entry；普通分支
移除 slot、按 signed min 更新 firstFree、清字段后才可选执行 "dispose" 属性。探针使用
同一 16B 原位图，sentinel 00ffffff，无新增 RValue ctor/dtor。FreeVars 后先发 pool head，
再写 object+8 的旧 head；没有把原发布顺序“修正”为常见链表做法。

FreeVars 的 dense 非空才读 count，count<=0 与正数遍历结束的释放指针来源不同；tag 窗
仍清 +8/+c/+0 并留 +4。hash 走原 index/scan/counter CFG，callback 后既保留 captured
RValue 的清零，也重读 bucket.value 作 FreeRValue 实参，再重取 live map/capacity/table；
不使用标准 foreach 覆盖原重入/读取点。map 的 raw operator delete 无条件保留。
两处 regex 数据各自读 live pcre_free（同 slot 0x3f0690 → 0x3f76dc），callback 后才清字段。

原 g_slotObjects 是 16B inline registry，类 freeList 是四字节指针变量，g_ShouldDispose
是 0x3f5050 的 byte，不混成 VM 的 JSGC。属性字面量 "dispose" 在 0x3327b4。字段与
源 API 仍仅观测前缀；不能把 wire view 或 raw local image 当完整原 C++ 类型。

`__fixunsdfsi` / `__aeabi_d2uiz` 在 0x31b0d0 共用 84B 叶。源码保留 LSLS 的 sign carry、
ADDS 的 exponent carry、BPL/BMI 与 ARM register-LSR 规则；负数/NaN 为零，+inf 与
正溢出为全一，非一个标准 C cast 的定义域。candidate 无 native FP 算术和任何外调，
两个名称同址同 GLOBAL、尺寸按对象核验，不因此声称全位图执行差分已做。

本批 238 原字，22 TU 的 O0/O2 组合含 44 个原导出。JS/value helpers、实际析构目标、
delete trampoline 及 fault/concurrency/unwind 等仍是内部欠账；未执行原件或重建件。


## 页池回收与 JS dispose 助手的真实正文

`object_base/value_pool.cpp` 恢复 FreeRValue@0x190e84：_rvalue 是 0x536d88 的20B inline对象，
不是指针变量；pageHead/freeHead/count0c/count10 偏移4/8/12/16。逐页使用两次uint32边界
比较，不用减基址折叠跨界范围；未命中仅继续查页，命中先快照freeHead/count10/count0c，
再写 value 首字→发布freeHead→增加count10→减少count0c。后两RValue**参数未消费。

`js_helpers.cpp` 恢复 JS_GetOwnProperty@0x241890、JS_GetProperty@0x2418dc、
JS_IsCallable_Object@0x240758、JS_IsCallable@0x24076c 与 Call_RValue@0x249860。
OwnProperty沿+0x18查+0x4c getter，但传给getter的仍是输入object，不是提供getter的祖先；
无getter只写 out.kind=00ffffff。GetProperty在每次真实getter返回后读out.kind低24位，
仍为哨兵才从当前object重读prototype，保留两层搜索，不做合并/环检测/额外空值guard。

Callable的object路只比较+0x48==3；RValue路低24位tag=6才读low pointer，其余八类直接0，
未处理类调用原变参YYError。格式串在0x355538，%d参数是0x240770/774产生并一直保留的r1，
不是因调用前没有MOV而省掉。Call_RValue拒绝路明确返回word 1；合法路原样转交receiver/
out/refObj/argc/argv并返回Call_ScriptRef的word。现有Free忽略返回值不构成void返回证据。

本增量六入口/114原字（两池字）；O0/O2各24TU/50个原导出，OwnProperty/CallableObject/
YYError/Call_ScriptRef四条实际调用或尾跳均核过。目标对象生成与调用形状检查不认证原LR、
异常展开、callback真实实现或游戏接入；Call_ScriptRef、FREE_RValue__Pre及getter目标仍欠正文。


## ScriptRef 完整调用与 profiler 压帧

`cpp/scripting/script_runtime.cpp` 恢复 Call_ScriptRef@0x249590、CScript::GetCode@0x1dfba8
和YYAllocLocalStackNew@0xd41e4。ScriptRef首读+88完整tag→+64 script，再可选读+7c替换
receiver；另一+78完整tag==6时，局部对象+0xc取+6c。length_slot只读一次，-1才查名字并
发布；随后LIVE读dense+4，不存在才InternalGetYYVar。length值不经tag/ToNumber，直接
按原VCMPE.F64及条件VCVT.S32.F64分流；共享VFP原语保留原操作，不用越界C浮转cast。

参数补齐的尺寸和指针按uint32回绕，memcpy返回r0作为新base，填尾do/while至少一次。
shared+1c临时存expected后恢复argc；padding跳到249634仍经过+20低字与+1c清零，因此
CreateArgumentsObject第五bool为false。这里父级早期的非规范bool假设已被原分支推翻，
不能把临时sp槽的上一个生命周期当作消费时定义。同一+20 image随后供VM第九参数读取。
三次GetCode保留，profile与VM各自LIVE取script+8；VM前后独立读g_bProfile，padding才
释放参数，GetCode bit1与下一次bit0分别守卫局部对象释放。native callback走原Push/
callback/Pop，不改成RAII；共同返回g_fDoExceptionUnwind非零为2、否则0。

`vm_exec/profiler_push.cpp` 恢复Push@0x2a0738。FindOrCreateNode返回的是NODE INDEX，
由Pop的index*40消费证明，不从名字猜成对象指针。count==cap才扩容，Alloc后读live cap/
data，Free前再读data、之后再读count，先发cap后data；插入用held allocation。24B帧仅
kind/id/index前三word初始化，raw LDM4/STR2/LDM2/STR4搬运保留尾部未初始化字。随后先
捕获live header再发held count，选中frame后才第二次Timing_Time，base在该调用后读取：
delta=base_afterSecond-firstTime，this.base=secondTime+delta，frame+16=0-delta，u64回绕。

四新入口/271原字，O0/O2各27TU/54导出；GetCode在两档保持三次实际调用，其O2八字节
恰与原件相同。Call_RValue、Profiler Push/Pop与既有释放/时钟正文真实组合，但VM::Exec、
arguments创建、对象Alloc/getter/context及FindNode仍欠库内正文。fault、原始栈垃圾数值、
完整FP trap/unwind与paired atomicity均未认证，目标均未执行。


## VM::Exec 入口与 profiler 节点恢复

`vm_exec_entry.cpp` 恢复0xe7fd0九参静态方法，第八int不消费，第九对象供GC槽写回。
匿名guard字节0x47a1d0与20B stackPages分开，只置guard/清pool+4,+8,+c。空池new大小
0x108008，payload从base+8填0x78/0x108000字节；首节点对齐按base+0x8008清低15位，
0x8000步长do/while链，选最后+0xf0000块。空池join跳过非空路的head读取，用寄存器
留存链接值；不能把worker的+0x40000或清零填充当成原件，也不补失败guard。

VMEntryPrivateImage的exec从+0x18发布，前缀00/04/08仍是converter/ref-release的同一
spill存储。memcpy返回地址决定argumentValues/frameBase；先发Argument再argc，清60B
控制帧后LIVE重读frameBase。转换后map与handler分别从exec.buffer和prefix.word00指针
读，两接收者不能合并。GC的PushContextStack后再读live locals；字符串路径每层YYFree
前spill、返回后reload，最深WEAK refdec及重复delete/unlock尾链保留，不替成一次释放。
退出按live parent清child→读localsMode→恢复current→held argc/Argument→必要locals Free。
独立审查VMEXEC-01纠正e8138的零写：sp+64减exec基址18等于4c（frameDepth），不是48
（nextSlot）。源码与ABI断言已修，旧nextSlot对位的编译负控拒绝，修后两档30TU重编通过。

`vm_value_helpers.cpp` 还原YYFree的真实MMFree尾包装及三个原BX LR函数，不把LOCK名字
解释为真实锁。_RefThing<const char*>::dec保持原WEAK DEFAULT和双递减/递归/删除路径；
默认弱符号与独立强provider的静态链接选择已核，未执行覆盖调用，不称动态验证。

`profiler_node.cpp` 恢复0x2a04f4/476B。查找比较原始kind/id，创建才mask4/28位；id不匹配
跳过byte3读取，BFI必须替换旧高nibble。stats header为capacity0/count4/data8，和Push
header不同；grow前发cap、ReAlloc后live this.currentIndex/this.stats与held count/data
发布分立。新count先发布，再逐byte初始化记录，仅原写点，+4..7/+0x24..27不填；+A的
零写在packed+3之前。最后signed parent.firstChild决定首链或held last-sibling链接。

七新增入口/522原字，O0/O2各30TU/61导出，所有原三no-op O2为4B BX LR。编译/静态修缮
不证明坏域、原私有栈/LR、异常或并发；匿名guard、Debug/FreePre、ReAlloc及对象/context
生产者仍未闭合，目标均未执行。


## ReAlloc 与对象/变量存储的实际正文

`memory_realloc.cpp` 还原0x27cedc与bucketSize@0x27c1e4。bucketSize仅以bucket receiver
调用vptr+8，不把查找指针再传一次。ReAlloc第五bool未消费，NULL和grow两路Alloc固定true；
持锁头读顺序为ptr-12 magic→ptr-16 size→比较，第二cookie失败再查负backref。验证过的
backref路径oldSize仍取原ptr-4负位图，不替为合理容量；unsigned oldSize>=newSize先返回
原指针，所以requested0不按标准realloc释放。grow清尾→copy→Free后LIVE读mutex再Unlock。

`object_allocation.cpp` 还原Alloc@0x19198c、InternalGetYYVar@0x196a70、int hash@0x1b6e44
及YYRealloc@0xcef64。hash是普通重载add1，不是template；YYRealloc传Code_Main.cpp/1298/
false。回收对象先快照capacity/next再发freeList；fresh分支new100→真实C1 raw ABI，直接
ensure-dense，不重复回收reset。capacity/slot扫描使用signed门、unsigned回绕及原朝零ASR
增长；零capacity不补最小值。registry先发布指针再按live旧cap清新尾，memset后读count。

GetVar仅按bucket hash/state命中，不添加key比较；mask/data在hash调用后从held map读。
新RValue由GetRValue取回，live默认kind先读、low/high写零、kind写回，+8保持；Insert receiver
由live对象+60读取。Ctor/AllocVars/GetRValue/Insert仍是真实内部欠账，不被raw声明隐藏。
六入口/327原字，O0/O2各32TU/67导出，当前是源码与静态编译证据，目标未执行。


## 值池/map生产者与调试执行入口

GetRValue@0x190dc0保留new0x100018、payload+8填0x78/0x100010，first=(base+24)&~15，
首偏移ADD为0xff000而不是0xfff00；loop end=first+0xffff0，返回first+0xfffe0。空池join
使用末次寄存器next值，不补头读取，正常freeCount净加0xfffe；原node未清理/无RValue构造。
AllocVars@0x1917dc先清object+5c，new20 raw header，cap8/mask7/null buckets，Alloc96后
先发buckets再清96B；live capacity经真实VCVT.F32/VMUL.F32/VCVT.S32计算growThreshold，
factor3f19999a；signed cap>0才live取buckets逐12B只清hash，最后发object.map。

ExecDebug@0xe47c8不在entry发currentExec，保持私有20B payload/argc/bool槽；解码使用原
inline opcode表而非Release密集表。单步用ff0f0000/op31/type15同表分发，clear byte0→
current→stepType=-1，PC与paramSize读取顺序分立；DebugInfo/LineNumber后live全局决策和
parent-depth求和不缓存。异常四字先读再取异常SP/写回，退帧保留aux；顶层restore argc再
处理out/页回收；locals只在第三bool且signed mode>0时Free并置空。不同于Release规则。
三入口/341原字，O0/O2各34TU/70导出，F32原语有实际目标指令；DebugInfo/LineNumber及
handler内部仍欠，未认证原LR/完整FP trap/unwind或游戏等价，所有目标均未运行。


## 分配器生产者与调试记录消费

MemoryManager::_Alloc@27cd54保留原bool给bucketAlloc，初始化后/解锁前均live取mutex；
桶失败后uint64(size)+16<=fffffffe才malloc，标准头按0/c/4/8写原词，total→inUse→
standardCount→standardSize独立更新。Alloc@27ce78的size0跳过所有调用；非空才按原bool
清零并调用真实logLocation(0,NULL,held,size)，返回held，不消费memset返回。
DebugInfo@ec144先size4后无条件code10读，logical>>3计记录，signed PC比较返回held
最后record；DebugLineNumber@ec2b8真strlen后读record4、signed缩短，逆向UTF游标独立于
helper更新槽，#line +_ctype_实际pointer-cell分类；文件名malloc→发out→无条件memcpy→
live*out→NUL。原稿额外NULL早退和非volatile省读已父修，O2反汇编证实code读未再被跳过。
四完整方法236原字、O0/O2各36TU/74原名，未执行任何目标；未知bucket/UTF生产者与原LR/
故障unwind/并发不认证，静态整合不升游戏等价。

## 七桶分配与 GC Context Stack

`bucketAlloc@0x27c53c` 先读匿名 BYTE `0x756699`，为零才查实际 `bucketsShouldInit`；启用时
`pagedata_size=16`、真实 `malloc(128)` 发布 `g_pages`，只清桶 +4/+8/+c，原 +0/+10 保留；
先置 initialized，后清最后一个 16K 桶。unsigned 准入是 `size<=256 || size==16384`。
每案 fresh 页以 `base+8` 开始填 `0x78`；原页头 next 早于池头发布，回调收到原
`[base,base+newBytes-1]` 实参，随后重读 +8/+10 才写页 owner。回边 predecessor
保持旧寄存器角色，fresh 合流不补非空路径的 node[0] 读取，activeCount 在合流后才读。
8B 清零为逐 byte 八写；其余保留真实 memset，参数是桶 stride，O2 六入口共用尾块非省调用。
无可达的默认诊断块仍保留源码，未承诺其故障行为或目标编译保留块。

`PushContextStack@0xd3968` 的 GC BYTE 零门在读取任何 Top/Max 前，Top==Max 才增长；
双倍回绕后为零（含原 Top=0x80000000）时发 Max=1/bytes=4，否则发布 doubled 并取
Top<<3 字节。实际 ReAlloc 的 tag@0x331038、line=74、第五位 false 与原调用点相同。
回调后原 d3a0c 先读 live Top，d3a14 再发布返回指针；随后发布 Top+1，最后写元素。
Pop/Get 无 GC 门，对原 Top 作 signed 判断，不补清槽/判空/对齐校验。

四入口/592原字含23池字；当前源码和累计目标 O0/O2 各38TU，78个原符号名核齐，未执行
原件/重建。继续沿 `addPageToGlobalPageList@0x27bcf8` 与实际普通分配/释放包装补生产者；
完整 CBucket 虚表、初始全局提供者、原LR/unwind、坏域及并发未证。

## 页边界表生产者与普通分配/释放运算符

原 `addPageToGlobalPageList@0x27bcf8` 从相同 `g_pages` / `g_bucketNumPages` / `pagedata_size`
三槽工作。signed `(count+1)>=cap` 走扩容，先按原 wrap32 tripling/偏置/ASR1 发布 cap，后取
旧指针传 libc realloc；返回先读 live count，再发返回地址，继续用 held 返回值，不回读 cell。
扫描使用8B stride、unsigned 地址比较、零哨兵和原索引终点。需要插入搬移时实际 memmove
使用 held array/index/count；回后按 0x27bdc4/0x27bdc8 先读 live array，再读 live count，
按 held index 定位，先写起止两个原字再发布 count+1。不另添清零/失败guard或容器语义。

`_Znwj@0x27c524` 与 `_Znaj@0x27d14c` 原 r0 字宽透传给 MemoryManager::Alloc；共享
`MemoryManager.cpp` 字面量从 PC 的实际 add 站点各自解到 0x3571e8，标量行1317、数组
行1323、第四 bool true。`_ZdlPv@0x27d1d0`/`_ZdaPv@0x27d1d4` 都直接调用已恢复 Free，
不经 delete 表达式或额外判空。只在此 TU 的目标编译禁 exceptions，保留原尾边而不把共享
Free 声明改作 `noexcept`。O2 四个 JUMP24；O0 四个 CALL；这是静态对象形状，不证异常展开。

五入口、93原字（6池字）。O0/O2各40TU/83原名字齐全，原件与对象15项ABI核对通过；
去掉指定的真实 TU 即缺少绑定过的原名。原件、重建件均未运行，完整分配器状态/类和坏域未证。

## 循环批次：具体 CBucket(true) 虚方法

7 个 true-mode 实例（8/131072、16/262144、32/262144、64/524288、128/524288、256/1048576、
16384/262144）各恢复 Init/Check/GetSize/Free 四方法，28 体 364 原字（7 池字）。虚表 24B
四槽（Init/Check/GetSize/Free@+8/+c/+10/+14），VMI RTTI 六字 [ZTVvmi, ZTS, 0, 1, ZTI11CBucketBase, 0]；
CBucketBase 为纯虚接口（0x3eb8f0，四 Thumb 纯虚槽）。派生类 20B：vptr+pageHead(+4)+freeHead(+8)+
activeCount(+c)+freeCount(+10)。Check 的 checkCounter 经 GOT 0x3edbcc（R_ARM_RELATIVE，
文件字 0x7566ac==符号值）；Free 是纯 freelist 头推入（三快照→写旧头→发布），false 模式的
120B 归属查找版本属下一批。单独实例化 TU `memory_bucket_members.cpp` 只实例化真实方法，
不伪造全局或运行期对象。

## 循环批次：false-mode CBucket 虚方法

两个 false 实例（16/1048576、32768/1048576）各恢复四方法，8 体 136 原字（2 池字），
单独 TU `memory_bucket_false_members.cpp` 实例化。Check 的两级 PC 链两实例均解到
GOT 0x3edbcc（与 true 批同一计数器）；Free 是页链归属查找——空链头/链耗尽返回 0
且零写入，命中 [page+8,page+1048576+8) 才走共享三快照/发布尾返 1。独立复核推翻
首次冻结的构建判据（新 TU 无 -O、对象命名碰撞）后重建，复审逐条实证。至此九个
CBucket 实例 36 个虚方法全部恢复；真实构造/初始化提供者仍是欠账。

## 内存管理器冷启动与真实桶对象接线

`Init@0x27c23c` 先取匿名 `0x756698` 旧 BYTE、发 `bucketsShouldInit=1`，旧值非零即返回。
冷路径先发 guard，后重读 `g_MemoryMutex`，空才尾转真实 `0x27b918`。桶 lazy guard 是
独立的 `0x756699`。`Quit` 是真实 `bx lr`；`DumpMemory` 不消费 FILE*，从 `dbg_csol`/`m_Total`
取两个活快照，`blx` 虚槽 +0xc 收到 console、原格式串和两次同一寄存器字。

`.init_array[29]`（0x3eb654）经 R_ARM_RELATIVE 到 `0xba3e4`。到 `0xba494` 为止 map 先后做：
capacity/mask/entries 三写 → `Alloc(96, MemoryManager.h, 70, true)` → 发 held entries →
`memset(held, 0, 96)` → LIVE capacity → count=0 → f32 阈值 → signed gate 后 LIVE entries
及 12B 步长清 hash → `__aeabi_atexit(map, D1, __dso_handle)`。D1/D2 是一个原入口；只在
entries 非空时调用真实 Free，返回后清 entries。原种子将桶与消费者拆成了两个对象群；实际
0xba3fc 与 0x27c558 都复算出 0x3f1c58，随后两边解析到完全相同的七个对象槽
0x3f1840..54/0x3f1860。安装地址点为各真实虚表 +8，按 8/16/32/64/128/256/16K 排列，
这段不调用 Init，不清 payload，不注册桶析构。页头的 owner 指向偏移零的实际 CBucketBase，
查页结果经 GetSize/Free 的 +8/+c 虚槽使用同一个类型，不再把类型不同的布局视图互转。

五入口 155 原字（26 池字），O0/O2 各 44 TU，171 项原件与目标 ABI 检查。静态候选不声称
完整启动/退出等价；O0 允许编译器物化基类构造中的中间 vptr，O2 查实七个最终写入。
两个 false 模式启动入口仍欠：`0xb959c` 是具名 stackPages 与旁边的三字头，`0xb9814` 在
Hash/YYSlot/CGCGeneration 之后才写具名 `_rvalue`。这两条都不是七个 true 桶的替身。

## VM 栈桶镜像初始化（0xb959c）

原槽 `0x3eb5ec` 的 R_ARM_RELATIVE 加数是 `0xb959c`，下一个入口为 `0xb95dc`。两级 PC 链
`0xb95ac → GOT 0x3edd3c → stackPages @0x47a1e0` 与
`0xb95b4 → GOT 0x3edd74 → _ZTV7CBucketILj32768ELj1048576ELb0EE @0x3eb908`，
`0xb95b8 ADD #8` 才是装入对象的地址点。对匿名头 0x47a1bc，顺序钉在 `0xb95bc..0xb95c8`：
+0 写本地址、栈桶写 vptr、+4 写本地址、+8 写 420。相邻不证明头就是堆页或栈桶字段，
不命名链表用途。栈桶 payload 未触碰，独立 guard 0x47a1d0 的置位仍归 VM::Exec。

恢复件统一 VM Stack 进入/释放/调试三个真实消费者与 false-mode CBucket；`activeCount`
对应旧 +0xc、`freeCount` 对应旧 +0x10。O2 核对四存储列和三个 VM 对象的反汇编/重定位
不变（其中 Exec 的对象符号表顺序可异），O0/O2 各45 TU、20 项本批 ABI；无原件/重建件
执行。`_rvalue` 的 0xb9814 仍独立未恢复。

## GC 启动与 `_rvalue` 的真实对象（0xb9814）

原槽 0x3eb60c 的 REL 加数是 0xb9814；下一槽 0xb9944。前两次 __aeabi_atexit 的 receiver 分别
是 CInstance::ms_ID2Instance 和 g_slotObjects。二者都在真实分配返回后先发布指针再 memset；
对象槽另经 YYAlloc(512) 间接调用 Alloc，Code_Main.cpp / 1293 / false，并按 +8/+c/+4 写 0/0/128。
随后 0xb98cc..dc 按 +88 构造四项；第三次登记为 (NULL,0x1910b4,0x3f2000)，回调按 3→2→1→0
销毁。最后 0xb990c 只向 `_rvalue` 写 0x3ebab0（虚表 +8）。这些是真实的静态 C++ 类型与直接
调用接线；最终程序的跨 TU 退出次序没有跑过。

GC C1 用 `new(20)`、Alloc(192)、memset、live 容量与 entries，保持有符号门和 F32 向零；
在写 +0xc 与 +8 之间读 g_GCinitialcollectionefficiency，一次原字复制到 +0x2c。其出厂 .data
字为 0x45800000。析构按原 held map、live +4、Free 边及清零顺序恢复。readelf 复核 C1、D1 与
数组回调均有 compact inline EHABI，不能从无 landing pad 推断没有 unwind 记录。

## GC 根查找与动态根消费者

0x1910e8 在真实 hash 外调前持有 map；回后分序读 +8/+0x10。只有槽 hash +8 被读，
首槽命中不走碰撞后的 index=-1 门；0x191144 TST 后是 BMI，不能改作任意非零；
命中按 value 地址而非 value 内容返回。0x190f34 的指针 hash 为 ASR #8 后加 1。

0x19135c 保留 NULL/强制/代际门、32 位回绕容量与 signed 扩容判定、ReAlloc 后重读旧 count，
两路都先写新 count 再按旧 index 发布 pointer。O2 实际指令次序过门，原稿优化件反序被拒。
`UpdateRange` 两读在两写之前，`ResetClassStats` 按每次外调后的 live unsigned count 循环，
释放的是 entry+0 payload，不是表。`ResetDynamicRoots` 仅清 +8。当前仍无运行及 GC 全流程等价。

## GC 根表写入与回填

`AddRoot@0x196210` 按 signed count>threshold 选择扩容；真实重插调用 0x1963c8 确认根 map 是
`CHashMap<YYObjectBase*,YYObjectBase*,4>`，12B 槽的 +0/+4 是 key/value，+8 为 hash。
Free 旧表后 0x1963e0 先读 live capacity、0x1963ec 后读 live count，再写 F32 向零阈值，
并持 count 回 fast path。原稿反序在编译件被拒。0x195ba8 是真实调用；下节的源码补上其提供者。

`RemoveRoot@0x1911c8` 与 `IsRoot` 不同：hash 命中须经原 `CompareKeys@0x190f48`，只在
该调用返回 false 时走 0x191274 的 mask 重读，再继续探测。回填按 hash/key/value 写序；
尾端 live count 先取，清槽 hash 后写回 count-1。不推断运行等价或完整 GC 寿命周期。

## GC 根表真重插提供者和代际重置

`Insert@0x195ba8`（弱定义）由 `gc_root_map_insert.cpp` 提供。三处增长的 call sites 是
0x195d1c/0x195f6c/0x196158；末级扫描 0x1961dc 才回调同一个弱符号。0x195cc0/0x195f1c
的空槽先写 hash；0x19610c 先写键值对再写 hash。置换将被替出的 key/value/hash 继续推进，
替换回读 count 后写 key/value/hash、再撤回预增。组合对象删去提供者即恢复 UND，未采用桩。

`Reset@0x19140c` 先清动态根计数，非空才 Free，0x191430 清 held map.entries，0x191434
重新取 map。发布新 allocation 后才 memset；0x191474/0x19149c 在后续路径各自重读
capacity 和 entries。最后按原字拷贝 0x3f504c 的效率词并写范围等状态，不重置类统计表。
真实上层 `ResetGC@0xd66e0` 对同一 `g_GCGens` 的四个 88B 元素有三条 BL、一条尾 B；
上层正文见下一节。静态目标对象不认证原版执行、动态链接或并发语义。

## GC 上层重置与类统计表所有权

`ResetGC@0xd66e0` 先读 `g_fJSGarbageCollection`（1B，0xd66f4），非零才从 0xd6714、
0xd671c 按序清两个 4B 状态，再用同一 `g_GCGens` 的 +0/+88/+176/+264 调真实 Reset。
原版为三 BL 加一尾 B；候选 O2 同形，O0 为四 BL。原 GOT 目标与候选绝对符号重定位分开。

`AddClassStat@0x191578` 写 `+0x48` 所指 8B 槽（+0 名称指针、+4 计数），原 `ResetClassStats`
在 0x191554/0x191558 读回同一 +0 并调 Free，保留表块。正名路径在 0x19161c 存 Alloc 返回值
到 held 槽，再按 0x191620 的 live 表/索引取 `strcpy` 目的指针；追加尾按 0x19163c/0x191640
先写槽计数，再写总数。候选 O2 的编译反序未通过该有序写入判据。未认证异常、并发、最终
动态装载或原版执行；ResetGC 的 guard 仍无恢复的写方。

## 对象清扫与根移除调用者

`FreeAllObjects@0xd675c` 由 `gc_free_all_objects.cpp` 提供：开关字节一次读、零即返回；先清
`g_ShouldDispose`，再按 held count 扫 `g_slotObjects` 活槽、每轮取 live capacity、对非空槽调真实
`YYObjectBase::Free@0x198f88`，整轮扫完才 live 重读 count（cap<=0 边只重测 held count，不重读）。
随后按指令序清 `g_pGlobal`、`g_YYJSStandardBuiltInObjectPrototype`、
`JS_Standard_Builtin_Function_Prototype`、`g_pScopeHead` 四个裸字，写 `g_ShouldDispose=1`、
`length_slot=-1`。本 TU 补上两个此前 UND 的 .data 初值对象（`g_ShouldDispose` 01 @0x3f5050、
`length_slot` ffffffff @0x3f7420）。原件真实调用者 `Quit@0x2a2804` 在本切片之外，不在此接线。

`RemoveGCRoot@0xd5b60` 由 `gc_remove_root_caller.cpp` 提供：push 前先裸读 object+0x38，
signed 负值即返回，原件无 NULL 门（不补造）；入口一次双装载定 `&g_GCGens[0]`，do-while 先对
cursor 代际调真实 `RemoveRoot@0x1911c8`，再回读 object+0x38、index+1、cursor+88，live 回读
>= index 继续；无四实例钳制，bound>=4 走出 352B 数组的后效未证。组合对象去掉对应 TU 即恢复
UND，未采用桩。

## Quit 拆除编排器

`Quit@0x2a27fc` 由 `host_lifecycle/quit.cpp` 提供，顺序为：CleanGestures、真实
`FreeAllObjects@0xd675c`、FreeAllDataStructures、真实 `ResetGC@0xd66e0`、QuitYoYoFunctions、
QuitNetworkingFunctions、26 个 FINALIZE_*、`g_Profiler.Clean()`（0x2a2894/0x2a2898 经 GOT
0x3edb74 取 128B 内联对象地址作 this）、GR_D3D_End；0x2a28a4 经 GOT 0x3f07fc 取
`g_pMainWindow`，0x2a28a8 读、0x2a28ac 测、0x2a28b0 beq 0x2a28d0——NULL 跳过销毁与两次存储；
非零则 `yyDestroyWindow` 后按序字存清 `g_pMainWindow`（0x2a28c8）、字节存置
`g_fDoFirstShow=1`（0x2a28cc，GOT 0x3f1a80）。`FINALIZE_PlatformSpecific`（0x2a28d0）与静态
`VM::Quit`（0x2a28d4）无条件执行；0x2a28d8 pop 后 0x2a28dc 尾支 `FreeAllBuffers`。vm_exec.hpp
补 `CProfiler::Clean`/`VM::Quit` 两处声明；38 个被调方保持 extern_only 无桩，组合对象去 TU 即
恢复 `_Z4Quitv` 缺失。

## FINALIZE 核心切片

`FINALIZE_All@0xc47f8` 与 `FINALIZE_Code_Main@0xcf478` 原件各为单条 `bx lr`，空体如实记录。
`FINALIZE_Code_Function@0xce274`：0xce278/0xce27c 经 GOT 0x3edb20 取 0x47a14c 字值作
`MemoryManager::Free` 实参（0xce284 真实调用边），随后按序清 0x47a14c（0xce298）、0x47a148
（0xce2a0，GOT 0x3edb1c）、0x48a148（0xce2a4，add 直达 0xce2a8+8+0x003abea0，无 GOT），pop
返回。三个匿名目标按未定义 extern 数组表示，终链须落位到记名地址；不造符号名、不给存储。
组合对象去 TU 即三个 `_Z*FINALIZE*` 缺失。

## Quit 支撑切片

`QuitYoYoFunctions@0x15a0c0`：调 `FlushAchievementCache`（0x159640）后 pop，尾支
`QuitYoYoFunctionsM`（0x15e2a0）——源码按尾语句记录，O0 降为 bl+epilogue 已记偏差。
`QuitNetworkingFunctions@0x2998b8`：`FreeSocket` 恰 64 次、实参 0..63；原件寄存器序是取参、
自增、再调用（0x2998c0/0xc4/0xc8），语义上与 for 循环等价，已记偏差注释。
`FINALIZE_Background@0xc42f4`：经 GOT 0x3ed954/0x3ed950 取具名静态成员
`Background_Main::names`（0x479cbc）与 `::number`（0x479cb8，各 4B .bss，R_ARM_RELATIVE 已核）；
names 非零才进入循环：逐项 `MemoryManager::Free` + 置空，0xc4330/0xc4334/0xc4344 每次 live
重读，0xc4340/0xc4348 符号 bgt；循环外无条件 Free 数组本体（0xc434c，number<=0 的 ble 也落
此），0xc4354/0xc4358 两条路径都清零；尾接 `Background_FreeTextures`（0xc435c）与
`Background_Free`（0xc4364 尾支）。两个静态成员以未定义类静态引用表示并记录落位义务；
五个 extern callee 无桩，组合对象去 TU 即三符号缺失。

## 对象族 FINALIZE

`FINALIZE_Object_Lists@0x19e884`：0x53ab70 块表（GOT 0x3efb14）15 块 x 2048B，每块 256x8B
描述符 {+0 signed count, +4 ptr}，count>0 才释放 ptr（signed ble 0x19e8b4）；随后 0x536f68
（GOT 0x3f06e8）仅 +4 释放并清零，+0 不动。`FINALIZE_Object_Main@0x19f0c0`：0x542374
（GOT 0x3edc44）容器 C={桶数组,signed count,live}，两遍结构相同的排水（第二遍重读通常空；
负数 blt 直入排水），逐节点 `CObjectGM` 析构（0x19f128/0x19f1b4，精确 D2 重整名 extern "C"
边——原件 D1/D2 折叠于 0x19d558）、`::operator delete(obj)`、`Free(N)`、--C[+8]；尾程
`Free(桶数组)`、`delete 容器`、经 0x542374 写零；0x542370（GOT 0x3f06ec）旗标字在函数头清零。
`FINALIZE_Instance_Class@0x1959f4`：表指针在 0x3f3c4c——.data 字、无重定位、文件内容是打包
字符串，指针由未识别生产者运行时写入（GOT-delta 配对 0x1959fc/0x195a00：0x195a08+0x00258244
== 0x3f3c4c，父级复算一致）；哈希表 T={buckets,mask,live} 以不摊平的四边/两边/r8=-1 哨兵与
前向槽重入遍历，逐节点 blx [vtable+4]（0x195ac4/0x195b64，目标不解析）、Free、live--。
`FINALIZE_Object_Class@0x19e1c8` 单条 bx lr 空体。组合对象去 TU 即四符号缺失；终链须按登记
落位五个匿名字。

## Room/Run 拆除切片

`FINALIZE_Room_Main@0x1b5e54`：调 `Room_Free`（0x1b5044，dynsym 已定义但未恢复，extern-only
无桩），随后经 GOT 0x3edbc0 对 `g_fJSGarbageCollection`（0x47f295）写零（0x1b5e68）——guard
首个已证写者；pop {r3,pc} 返回，与 Run_Main 无边。`FINALIZE_Run_Main@0x1d37cc`：persinst
（GOT 0x3f0b50）中 persnumb（0x3f0b4c）计数条目逐项 Free + blx 析构（0x1d384c，目标不解析）
+ 置空，live 重载保序；0x1d38c8 以 NULL 实参调 Free；尾程清两个静态。`FINALIZE_Motion_Grid
@0x19c2cc`：gridstruct（0x3f06b8）/gridcount（0x3f06b4）逐网格 Free + blx 析构（0x19c318）。
`FINALIZE_Code_Variable@0xd2618` 单条 bx lr 空体。组合对象去 TU 即四符号缺失；六个具名全局
按落位记录以 extern 引用。

## 精灵/字体 FINALIZE 切片

`FINALIZE_Sprite_Class@0x1ee76c` 单条 bx lr 空体。`FINALIZE_Sprite_Main@0x1ef514`：add r3,pc
得 GOT 基 0x3f1c58，索引 -0xe40/-0xe44 取 `g_NumberOfSprites`（0x3f0e18）与 `g_SpriteNames`
（0x3f0e14）；count 符号门内逐项 Free+置空（live 重载），数组本体 Free 后指针清零；
`Sprite_FreeTextures` 后尾支 `Sprite_Free`。`FINALIZE_Font_Main@0xface8`：`Font_FreeTextures`
后尾支 `Font_Init`（拆除名下重入初始化器，映像如实记录）。`FINALIZE_VertexFormats@0x1e3180`：
`Graphics::Flush` 后走 `g_vertexformats`（0x3f0da4，12B 三槽）链表：`FreeVertexFormat` 逐链、
节点按 census 无空测直接 `operator delete` 裸字（0x1e3250）+ `Free` 节点 + live--、链槽置空；
终经 0x3f0da0 清 `g_lastVF`；0x1e3298 为 beq 落点指令非池字。四槽均 R_ARM_RELATIVE（worker
COPY 误标已更正入档）；extern callee 无桩，组合对象去 TU 即四符号缺失。

## Graphics FINALIZE 切片（父级直接施工）

`FINALIZE_Graphics_Display@0x17dbb8`：`DisplayReset`、`InvalidateOGLResources` 两个 extern 边，
pop 后尾支 `DeleteOGLResources`。`FINALIZE_Graphics_Texture@0x1767cc` 整体一条尾支进
`GR_Texture_End`（4B 非空体，非 bx lr，如实记录）。`FINALIZE_Graphics_Text@0x1738fc`：
GOT-delta 配对（0x173904/0x17393c 与 0x173908/0x173940，同 delta 0x0027c988，父级复算
0x173914/0x173918 + 0x0027c988 == 0x3f029c/0x3f02a0）取 `Graphics_Text::deffont`（0x48ffd8）
与 `g_pDebugFont`（0x499330）；先无条件清 `g_pDebugFont`，`deffont` 读值非零才 [vtable+4]
blx 间接析构（0x17392c，目标不解析）并清 `deffont`；pop 后尾支 `GR_Text_ResetToDefault`。
五条 extern callee 无桩；组合对象去 TU 即三符号缺失。
