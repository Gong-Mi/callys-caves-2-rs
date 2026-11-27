# ④轴（与原版等价）切换条件与对拍工具合同

## 为什么现在立这份合同

本合同在总装批（c/spine_read_skeleton/ 全链总装）施工期间、收口**之前**落盘。
依据的教训（2026-11-08 跨项目复盘）：终局判据要赶在施工收口前存在，不能等
收口那天才发明——否则"总装完成了，和原版像吗"的答案只能是「未有测量」，
被迫当场发明 oracle，发明期的错误会带毒进整个验收域。

## 总装通过的定义（test_anchored 层）

总装批 `RESULT PASS` 证明且仅证明：**接线正确**——段序、段间交接（ABI/
指针/所有权）、单段损坏定位（组合层三类负控）、root 生命周期、只发射一次
约束、B18 收尾。它**不证明**与原版等价。收口后 ④轴状态=「未有测量」，
直至本合同 Level A 工具跑出第一份差异报告。

汇报纪律（两类收据，不得混用）：
- **重建链收据**（分块/总装层）：`tier: test_anchored`、`original_executed: false`
  不变；④轴未测期间禁止把任何夹具绿表述为"接近原版/已还原"。
- **Level A oracle 收据**（对拍层）：`tier: oracle_anchored`、`original_executed:
  true`——执行的是**原字节**，环境是 Unicorn 合成内存 oracle（staged 树 +
  bump 堆 + hook 的 libc/libm/console/setlocale/分配器）；scope 字段必须
  照抄 evidence_layer 全文。把两类收据的字段互换（比如 oracle 收据写
  test_anchored、或重建链收据写 original_executed:true）即账目错误。

## Level A：readSkeletonData 函数级对拍（可立即施工）

### 对拍对象
- **原版臂**：Unicorn 合成内存 oracle 跑原函数 `spSkeletonJson_readSkeletonData
  @0x28b84c`（先例：`c-recon/tools/oracle/precise_oracle.py`、
  `harness/handler_oracle.py` 的 L5 臂——完整 PT_LOAD/BSS、本地 GOT 重定位、
  hook 分配器/Json_create/依赖 libm；内存 oracle 结论标注为合成内存层，
  与设备实测分层记账）。
- **重建臂**：总装链（c/spine_read_skeleton/ 及其全部真链模块），同一份
  合成 Json 树输入。

### 输入合同
- **输入形态钉死**：同一棵**合成 Json 树**（32B 节点，先例 mesh 夹具的
  node/add/string 形状）。原版臂 **hook `Json_create` 返回内存里铺好的同一棵
  树**（precise_oracle 的 hook 风格——不依赖原版 Json 解析器，也不引入
  字符串序列化往返差）；重建臂的 entry 边界直接拿同一棵树。**"同输入"=
  两侧字面上同一棵树**，BINDING v1 记逐节点 sha、两侧二进制 sha、原件 sha
  （3bbedd09…）。
- 合成 creator（spBoneData_create 等）在重建臂按已证 ABI 建真结构；原版臂
  用原件自己的 creator——**两侧对拍的是 spSkeletonData 的终态**，不是中间
  creator 调用序列。

### 可比字段（原版 oracle 可读，逐字段 diff）
spSkeletonData 21 字全量：各段 count/数组（+0x10/0x14 bones、+0x18/0x1c
slots、+0x3c/0x40 ik、+0x44/0x48 transform、+0x4c/0x50 path、+0x20/0x24
skins、+0x2c/0x30 events、+0x34/0x38 animations）；逐元素：名字串内容、
bone 父链、slot blend/color 位、attachment 类型与 name/path、animation 的
timeline 计数/每条 timeline 的帧数与帧值位型（time/mix/angle/x/y/curve
元素）、duration、event 的 int/float/string。
**不可比**（登记边界）：中间 malloc/free 序列、creator 内部布局、错误路径
的 console 输出文本（可比 parser->error 字符串）。

### 负控（证明门被消费）
1. 打坏重建臂任一段的语义常量（如 blend 映射/帧步长/duration 极性）→
   diff 必须**非零且能定位到该段**（差异报告按 spSkeletonData 字段分组，
   字段→段的归属表写进工具）。**多段共写字段（duration、错误路径下的
   count 等）允许"多段并列归属"**——定位要求放宽为"差异组命中至少一个
   归属段"；单段独占字段（如 slots 数组、blendMode）必须唯一定位。
2. 输入扰动（改一个键/删一条时间线）→ 两侧 diff 必须同步变化（证明两侧
   真在读同一输入，不是各自空转）。
3. 原版臂只跑一次并落存档（内存 oracle 不可重入的先例：`CENSUS_UNNAMED_THUMB`
   回执纪律），重跑比对存档字节。

### 判据
- Level A 通过 = 全字段 diff 为零（合成输入域内）＋三个负控全红＋BINDING
  钉死。通过后 ④轴状态升级为「合成内存 oracle 层已测，差异 0（输入域：
  本合同输入集）」——仍不是全输入域等价，也不是设备等价。
- Level A 出现非零差异 → 按字段归属表定位段→回该段模块修→复跑。
- **首份报告（2026-11-08 16:02，oracle_anchored）**：main（scale 2.0/1.0）、
  err_parent（双侧 NULL+同文案 "Parent bone not found: forearm"）、
  perturb 四轮 **267 字段 diff=0**；三负控全过（打坏 blend/scaleX/angle
  键各自命中归属段；输入扰动双侧 25 字段同步变化集合相等；原版臂单跑
  存档 3879 字节重放一致）。回执 `harness/receipts/
  level_a_diff-20261108T160156.json`，逐字段报告
  `c/spine_level_a/build/level_a_field_report_20261108T160156.json`。

### 施工档位
本合同即判据（贵模型层已定）；工具实现（oracle 驱动+diff 器+负控）为
规则内施工，判据冻结后可整件下沉次模型。

## Level B：玩法级"相同画面"四条件（项目终局门，不因总装收口而激活）

四条件（沿用项目 skill 既有定义）：连续时序（整段走路/挨打/换房/过场/
死亡，非单帧）、自然输入（真实操作序列，非坐标写到门上）、同 tick 对齐
（原版 30Hz 步进与重建 tick 一一对应）、RNG 可控（两端钉同一条随机流）。
四条缺一，画面比较退化为摆拍；单帧截图不入库不作判据。

Level B 的载体（原版侧 tick 流采集 + 重建侧同输入驱动 + 逐 tick 状态对拍）
依赖游戏级 runner（超出 readSkeletonData 范围），其工具合同**另行立项**，
在 Level A 收口、玩法链路具备时落盘。总装收口不自动触发 Level B 声明。

## 与跨项目抽象的关系

本合同的"字段→段归属表+打坏定位负控"与 shamiko/momo 线的"门对照表/
证明依赖合同"是同一抽象的两个实例：每个判据门都要被证明"被消费"
（翻转该门、判定必须变红），否则门只是自证。
