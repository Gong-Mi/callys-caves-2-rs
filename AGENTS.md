# AGENTS.md — cally 逆向施工纪律

本文件是给在这台设备上工作的 agent 的硬约束。目标是**考古**（把原件的行为一条条取证还原），
不是**做演示模型再往上加砖**。两者最大的区别：演示模型的进度用"能跑"衡量，考古的进度只用
"每条主张都有证据身份"衡量。

## 0. 一句话规则

任何一条写进代码或文档的"原件是这样做的"，必须同时给出三样东西：
**tier（证据档位）+ anchor（可复核锚点）+ gap（还不知道的部分）**。
三样缺一样，这条就只能算假设，不能进主线。

## 1. 禁止倒置：先有模型再补证据

错的做法（本仓库已经发生过）：先写一个能跑的 Rust/GML 行为模型，再用测试把它钉住，
然后不断在这个模型上加功能。这样得到的"覆盖率"和"通过数"全部是自证的。

正确顺序：

1. 先固定**字节与索引**：CODE body 的源区间、指令流、常量、字符串表，全部可重算、带 sha。
2. 再写**能回指到指令**的实现：每条语句旁边能写出它对应的 offset。
3. 再拿**原版**做对照（live-mem oracle 或 CI 探针），对照结果必须带 BINDING。
4. 最后才谈"覆盖率/完成度"，而且分母固定、口径写死。

## 2. 三档证据，不许混报

| 档位 | 含义 | 能不能算"还原" |
|---|---|---|
| `bytecode_anchored` | 由 shipped CODE body 决定，逐条锚点 | 可以 |
| `oracle_anchored` | 在原版二进制/活体进程上量出来 | 可以（要写清量了什么） |
| `device_anchored` | 在真机上观测到 | 可以（只能当状态证据） |
| `test_anchored` | 只有本仓库自己的测试 | **不可以**，这是自洽 |
| `host_authored` | 原版没有、我们造的 | **不可以**，且必须写 original_gap |
| `unverified` | 还没证据 | 不可以 |

对应 `reconstruction/db/schema.sql` 的 `card.tier`。写卡时按这张表选，不许四舍五入。

## 3. BINDING：任何"通过"都必须能回答"测的是哪份字节"

一条差分级通过（C == VM、C == 原件、帧一致……）在日志里必须自带：

```
BINDING v1 code=<id> body_sha256=<sha> fixture_sha256=<sha> impl_sha256=<sha> entry=<fn>
```

任一 sha 漂移，这条通过作废。**没有 BINDING 的绿灯不算证据**，只算"今天跑过一次"。
现状：`c-recon/tests` 四个文件里零个 sha 常量，`scripts/c_vm_diff.py` 不钉 body sha —— 这是待补的第一件事。

## 4. host_authored 必须显式标注

`c-recon/src/host.c / objects.c / rooms.c / collision.c / draw.c / builtins2.c` 是手写的引擎语义
（实例、创建、碰撞、房间、绘制队列）。这些是**重建**，不是原件。
每个文件头必须写：

```
/* host_authored: 原版由 <CODE id 或引擎模块> 提供；本实现为重建。
 * original_gap: <原版行为里还没取证的部分>
 * tier: host_authored（不计入 bytecode 覆盖）
 */
```

## 5. capacity ≠ delivery

README 写「generator 1354/1354 bodies」时，必须同时写「committed: 15」。
生成器能产出多少 ≠ 仓库里有多少。所有进度数字都要标明是**能力面**还是**交付面**，
分母写清、口径写死，禁止一个百分比包打天下。

## 6. 锚点粒度

生成物必须逐条可回指：现在是文件级 `source start/end` + 少数地址型变量名，
差分不等时无法定位。`scripts/ir_to_c.py` 已经拿得到 offset，输出里每条语句前加
`/* @<offset> */` 即可。锚点粒度是能不能查错的分水岭。

## 7. 负控与变异

任何"相等"断言都要配一个**必然会失败**的负控（改一个字节、改一个指针、改一个边界值，
由同一条断言抓出来）。现在只有 collision/env 有负控，draw/rooms 没有——补。

## 8. 收尾：每轮留下可续接的交接面

每轮结束必须在 `reconstruction/contracts/` 下留一条记录：本轮做了什么、
哪些主张升了档、哪些仍是 unverified、下轮从哪条开始。
不写交接面 = 下一轮只能靠猜，历史已经证明会重复劳动。

## 9. 这张表是唯一进度口径

`select tier, count(*) from card group by tier`。
在 cards 为空之前，任何"完成度"都不是数据，是说法。

## 10. 像素不是等价判据（项目曾经因此空转）

渲染产物只能当**回归基线**，永远不能当"与原版等价"的证据。三条硬规矩：

- **先把数据链排出来，再谈判据。** 链条是单向的：
  `字节码/IR → VM 状态(instance/field/global) → 原生调用与事件 → 绘制命令 → 像素`。
  **像素是链条最后一个环节，定位是"消费"**——它消费前面所有环节的产物。
  消费端跑通只能说明"这一路没崩"，**不能反推上游语义正确**；反过来，上游语义错误
  经常在像素上表现为"看起来差不多"。所以判据必须落在链条上游（状态与调用），
  下游只做端到端冒烟。

- **像素由中间层完成，不在像素上判等。** 像素的上游是**绘制命令流**（引擎侧 draw list：
  实例 id / 对象名 / x,y / depth / 链表序；本仓库侧 `ordered_draw_commands` 的
  sprite/text/healthbar/background 四队列 + GUI 相位）。这一层两边都能**逐条读出**：
  原版走 `room_census.py` 的 draw 链（CInstance +0x80/+0x180/+0x17C），本方走
  `draw_order_ir` / `draw.c`。所以渲染正确的判据是**命令序列相等**（含 depth 排序与
  tie-break），不是帧缓冲相等；只有命令层一致、还想验光栅化，才去开真 surface 看像素。

- **`nonZeroPx=0` 时，像素轴记 N/A，不许写成"一致"**。空画布对空画布当然相等。
- **任何常量哈希先复算再引用**。实测：`dcde318742a40325` 就是 727,040 个零 int 的
  FNV-1a（`h = h ^ 0; h *= 0x100000001b3`，迭代 727040 次）——2026-10-28 两条腿报告
  "6 个相位哈希逐字节相等"，实际是同一个空画布常量自证了六次。
- **差分轴固定为四域**，像素不在其中：① 调用序（surfaceCreated→nativeSetSurface→
  nativeInit→nativeSetClockPaused）② 返回值语义（present / setSurface / paused）
  ③ 事件域（audio 队列、haptic、save 文件状态）④ 状态快照（instance/field/global，
  走 `c_vm_diff` 的 state dump，不走帧缓冲）。

WHY：把 headless 环境里拿不到的像素当成判据，会让"一致性"永远看起来差一点，于是每一轮都在
调渲染通道，而不是推进逆向本来要拿的语义证据。2026-10-28 那次 `restored_true=0/1`
在 java 与 rust 两条腿上同时出现，根因是这台机器 headless 下压根拿不到 surface，
不是 presenter 的缺陷。
