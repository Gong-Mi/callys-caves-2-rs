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
| DoNot | 0xd7908 | mode 0（cls 0..15）+ mode 3..15 落空；333 例 identical | mode 1（`!`）/ mode 2（`~`，需 boxType + JS_ToBoolean + F_JS_ToInt32） |
| boxType | 0xd7784 | 类型 0..9 与越界；97 例 identical | 调用方怎么选类型；k6 对真实字符串对象（只验了指针拷贝） |
| DoNeg | 0xe096c | 另加 mode 1 / mode 2（经 boxType + F_JS_ToNumber 的 C 模型）；合计 378 例 identical | tag 1 字符串、tag 6 对象、tag 字 0x00FFFFFF 的未解析分支 |

第三条臂（boxType）格外值得先做：所有通用路径都要过它，而它的 k7/8/>9「一个字节都不写」、
k9「只清 [0]/[4]」、k4「bool 不归一化」三处都是"看起来该写点什么"的陷阱。装置做法是把目标槽
预填 0xEE 毒值，于是「没写」变成可观测量。

## 装置自身的边界（读到 identical 之前先读这一节）

- **Unicorn 不建模 FPSCR 的舍入模式。** 把 RMode 设成 RN/RP/RM/RZ 四种，`vcvt.s32.f32`
  的结果完全相同（都按截断）。真机 VFP 按 FPSCR.RMode（默认 RN）舍入，所以凡是走
  「浮点→整型」的臂（DoNot cls 1 就是），**本装置不能判**：它只能证明「C 与 Unicorn 一致」，
  不能证明「与真机一致」。这类项一律记 `narrowed`，并在卡头写明要设备证据。
- 原版对 `~`/取负这类运算并不使用「看起来合理」的饱和转换：它调用的是本构建自带的
  `__fixdfdi`/`__fixunsdfdi`（0x3194a0 / 0x319550），其越界行为是 ±Inf → ∓1、DBL_MAX → -1。
  需要时直接把 helper 当被测函数单独 probe，再回到 handler 差分。

## 接下一个处理器时要做什么

1. `handler_oracle.py` 只管装载 ELF、开 VFP、把 VMError/JSThrow*/FREE_RValue__Pre 记一笔再返回；
   处理器语义写进各自的 `*_diff.py`，别让模型藏进公共管道。
2. 用例必须覆盖「每个 tag、每个 cls、每个错误分支」，并至少留一条**边界探针**给每处回绕/符号/取整决策。
3. 变异体按决策写，不按行数写；一个变异体抓到 0 例就说明用例漏了那格，补用例而不是删变异体。
4. 回执里的 `scope.not_covered` 必须诚实：没接线的臂就写没接线，不许用「其余路径看起来一致」代替。
