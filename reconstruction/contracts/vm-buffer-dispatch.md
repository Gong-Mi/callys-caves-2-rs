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

门绑定 162 个索引字（含 10 池字），在 O0/O2 各跑入口、正常派发、捕获异常、异常外传、退帧、页池六组；
负控覆盖参数宽度、异常对象身份、退帧保留字、页池右开界及重叠结果写回。
`PerformReturn`、`MemoryManager::Free`、`YYObjectBase::Free` 仅由具名合成模型满足本地链接；
真实被调方、全局对象生产者及间接处理器仍要各自闭合。下一批从 `PerformReturn` 调用链恢复开始，不扩 Debug/ART，也不计入原件差分。
