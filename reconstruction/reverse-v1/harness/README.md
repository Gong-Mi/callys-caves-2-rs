# 处理器差分 harness（原版二进制 ↔ C 重建）

这条目录回答一个问题：**卡上写的处理器语义，原版自己同意吗？**
在此之前 reverse-v1 的证据都是静态字节（`bytecode_anchored`）；这里开始产出
`oracle_anchored`：原版函数在 Unicorn 里执行，C 重建编译成宿主二进制，两侧吃同一批输入，
逐例比对，并把结果落成可重跑的回执。

## 跑法

```sh
cd reconstruction/reverse-v1/harness
python3 do_neg_diff.py          # 编译 + 跑 282 例 + 5 个变异体 + 写回执
python3 do_neg_diff.py --no-run # 只重读最近一份回执的门结果
```

## C++ 模块静态完整性检查（不是 oracle）

```sh
python3 verify_cpp_module.py --module ../cpp/object_base --image <pinned-libyoyo-armv7.so>
python3 -B test_verify_cpp_module.py
```

该门只读校验 `cally-readable-cpp/1`：固定 ELF SHA、函数符号边界/尺寸，要求函数窗口同时落在 PF_X `PT_LOAD` 和 `SHF_EXECINSTR` 节；校验 body SHA、声明路径对应的主头/规范头/附加头和源码哈希，以及 `original-words.tsv` 的 `word` 列全覆盖并与原始 ELF 字节一致。非符号边界使用有限白名单：`init_array_relative_next_slot` 交叉核实际 `.init_array` 的目标和下一槽边界；`atexit_pointer_and_next_dynsym` 校验下一 dynsym 边界，但不验证 atexit 注册指针本身。它不校验 `mnemonic`/`operands` 文本。源码/头文件路径相对模块目录解析，允许在 `cpp/` 内引用共享兄弟模块，但不能越出 `cpp/`；所有声明的头哈希都必须有路径并匹配当前工作树，旧清单缺少 `header_path` 时会失败关闭。历史回执应在其基线快照上校验，不要用当前文件冒充旧输入。需要 `pyelftools`。它不编译、不链接、不执行原件或候选，也不证明语义等价；O0/O2、提供者闭包和行为差分仍走各自验收门。

回执落在 `receipts/do_neg_diff-<UTC时间戳>.json`，含：输入集的 sha256、C 源码 sha256、
逐门结果、变异体抓到的例数、被真实触发的错误文案。同一份 `do_neg.c` 重跑得到同一结论。

## 门（任一不过即 exit 1）

| 门 | 含义 |
| --- | --- |
| `identity` | 每例的返回栈指针 / 16 字节槽 / 错误串三面全等 |
| `coverage_cls_0_15` | cls 0..15 都真的出现过（不是抽样） |
| `coverage_tag_0_15` | RValue tag 0..15 都真的出现过 |
| `non_degenerate` | 原版在这些例子里确实改写了槽（避免「两边都不动」的假等价） |
| `teeth` | 每个 `-DMUTANT=n` 变异体至少被 1 例抓住；绿了说明用例没打到那个决策 |

`teeth` 是这套装置的命门：`c/do_neg.c` 里那五个 `M_*` 分支就是判别性反例，
它们只在 `-DMUTANT=n` 下编译，用来证明「identical」不是靠用例太软换来的。

## 已接线的处理器

| 处理器 | 地址 | 覆盖的臂 | 未覆盖的臂 |
| --- | --- | --- | --- |
| DoNeg | 0xe096c | mode 0（cls 0..15）+ mode 3..15 落空；282 例 identical | mode 1 / mode 2（需 boxType + F_JS_ToNumber 的真实执行） |
| DoNot | 0xd7908 | mode 0（cls 0..15）+ mode 3..15 落空 + mode 1（`!` 经 boxType + JS_ToBoolean）；404 例 identical | mode 2（`~`）：F_JS_ToInt32 数值路在 Unicorn 里 UC_ERR_INSN_INVALID（PC=0x134），不可测 |
| boxType | 0xd7784 | 类型 0..9 与越界；97 例 identical | 调用方怎么选类型；k6 对真实字符串对象（只验了指针拷贝） |
| CObjectGM::LoadFromChunk | 0x19d688 | OBJT 记录头 src+0x00..0x1f（字段映射、三个 flag、sprite 标签位）；104 例 identical | src+0x20 起的版本门与 action 列表（版本字经未重定位表读出，>8 路径会写坏内存） |
| DoNeg | 0xe096c | 另加 mode 1 / mode 2（经 boxType + F_JS_ToNumber 的 C 模型）；合计 378 例 identical | tag 1 字符串、tag 6 对象、tag 字 0x00FFFFFF 的未解析分支 |

第三条臂（boxType）格外值得先做：所有通用路径都要过它，而它的 k7/8/>9「一个字节都不写」、
k9「只清 [0]/[4]」、k4「bool 不归一化」三处都是"看起来该写点什么"的陷阱。装置做法是把目标槽
预填 0xEE 毒值，于是「没写」变成可观测量。

## 资源加载链的臂

`object_load_diff.py` 是这条目录里第一个不在 VM 处理器上的臂：它钉的是
`CObjectGM::LoadFromChunk`（OBJT 记录 → 运行时对象表）。做法是「单字节扫描」——
把记录里的某一字节置非零、跑一次原件、看目标结构哪几个字节变，字段映射由此从原件的行为里
读出来，而不是从我们的资产文档里抄。后续资源加载（WAD 块 → 各记录族 → 纹理/精灵）都靠这一步
才有共同地基。

## 装置自身的边界（读到 identical 之前先读这一节）

- **Unicorn 不建模 FPSCR 的舍入模式。** 把 RMode 设成 RN/RP/RM/RZ 四种，`vcvt.s32.f32`
  的结果完全相同（都按截断）。真机 VFP 按 FPSCR.RMode（默认 RN）舍入，所以凡是走
  「浮点→整型」的臂（DoNot cls 1 就是），**本装置不能判**：它只能证明「C 与 Unicorn 一致」，
  不能证明「与真机一致」。这类项一律记 `narrowed`，并在卡头写明要设备证据。
- 原版对 `~`/取负这类运算并不使用「看起来合理」的饱和转换：它调用的是本构建自带的
  `__fixdfdi`/`__fixunsdfdi`（0x3194a0 / 0x319550），其越界行为是 ±Inf → ∓1、DBL_MAX → -1。
  需要时直接把 helper 当被测函数单独 probe，再回到 handler 差分。

- **有的 callee 在这个模拟器里根本跑不起来**：F_JS_ToInt32(0x24d5c8) 的数值路、以及 JS_ToBoolean
  的 tag 2/3 分支，都会因未重定位的跳板落到 PC=0x134 报 UC_ERR_INSN_INVALID。这不是原版缺陷，
  是本装置的能力边界：这类处理器只能记 `narrowed` 并点名缺哪个 callee，不许把「没测」写成「一致」。
- **别按声明宽度猜真值语义**：JS_ToBoolean 对 tag 7/10 的载荷按 8 字节 double 判真，对 tag 13
  却少了 NaN 检查（NaN 判真）。这种"同一个引擎两套真值规则"只能靠 oracle 逐 tag 打出来。

## 接下一个处理器时要做什么

1. `handler_oracle.py` 只管装载 ELF、开 VFP、把 VMError/JSThrow*/FREE_RValue__Pre 记一笔再返回；
   处理器语义写进各自的 `*_diff.py`，别让模型藏进公共管道。
2. 用例必须覆盖「每个 tag、每个 cls、每个错误分支」，并至少留一条**边界探针**给每处回绕/符号/取整决策。
3. 变异体按决策写，不按行数写；一个变异体抓到 0 例就说明用例漏了那格，补用例而不是删变异体。
4. 回执里的 `scope.not_covered` 必须诚实：没接线的臂就写没接线，不许用「其余路径看起来一致」代替。
