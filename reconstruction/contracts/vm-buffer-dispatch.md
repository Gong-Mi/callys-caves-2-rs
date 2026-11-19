# ARMv7 VMBuffer → ExecRelease 派发表合同

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
