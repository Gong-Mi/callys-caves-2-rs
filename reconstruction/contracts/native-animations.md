# Animations 段入口（B1/B2）与 readCurve 公共前置

## 身份与范围

原件 libyoyo ARM32 SHA256：
`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
按 METHOD 静态前置：原件只读，无原件执行。执行对象仅为重建 ARM32 C（qemu-arm）。
母函数 `spSkeletonJson_readSkeletonData@0x28b84c`（13044B，终点 0x28eb40）；
animations/events 段 `0x28d19c..0x28eb40`，普查见
`reconstruction/reverse-v1/asm/animations_segment_map.md`（31 分块表）。

本批两模块（子代理施工、父代理独立复跑核验）：

- `c/spine_read_animations/` —— 分块表 B1（骨架级 events 数组 + EventData 循环，
  0x28d19c..0x28d290，61 insn，malloc 1028/1034）+ B2（animations 数组分配，
  0x28d290..0x28d2d4，17 insn，malloc 1043）
- `c/spine_read_curve/` —— 匿名叶函数 `readCurve@0x28b34c..0x28b3fc`（44 insn），
  animations 段 8 个时间线块的公共前置

## B1 / B2 恢复语义（要点）

**B1**：`Json_getItem(tree,"events")` 缺失 → 不写任何字段直接跳 B2。
命中：**先**写 `data+0x2c = count`（0x28d1c0）**再** `_malloc(count<<2, tag, 1028)`
**再** `data+0x30 = array`（0x28d1d8）；`child = events->child` 在 malloc 之后读。
循环（头 0x28d20c）逐项：**事件名取 `child->name`（Json+0x1c 成员键），不是
`getString("name")`**（0x28d20c `ldr r0,[r4,#0x1c]` 实证）；`spEventData_create(name)`
（合成边界，0x285b94 本体未恢复）；`Json_getInt("int",0)→+0x04`；
`Json_getFloat("float",0)→+0x08`（softfp 原始位）；`Json_getString("string",0)` 非空才
`strlen+1 → _malloc(…,1034) → strcpy → +0x0c`（指针先写后 strcpy）。每项重读
`data->events` 基址，字节游标 `+=4` 发布；`child = child->next`。
循环只由 child 链驱动、不信 count；本块无错误路径（无 setError/dispose，creator
返回值不判空）。

**B2**：`Json_getItem(tree,"animations")` 缺失 → 跳 0x28e7a4（Json_dispose + 返回）。
命中：`_malloc(count<<2, tag, 1043)`；`data+0x38 = array`（child==NULL 也发布）；
返回 `child`。**`data+0x34 (animationsCount)` 本块不写**——计数与数组元素在
循环尾 0x28e784/0x28e78c 写（B18 尚未恢复）。

## readCurve 恢复语义（普查 open #2 已钉死）

ABI：`readCurve(Json* frame, void* curveTimeline, int frameIndex) → void`；
r0=**该帧的 Json 对象**（非动画根）、r1=刚传给 `<Type>Timeline_setFrame` 的同一
时间线指针、r2=0 基帧号；**8/8 调用点都不读返回值**（调用点：0x28d7d0 translate、
0x28d9b0 color、0x28daf0 rotate、0x28dc48 ik、0x28de0c transform、0x28dff4
path-position、0x28e2a8 deform、0x28e9b0 path-mix）。

语义：
- 键查找走 `Json_getItem`（casecmp）读 `"curve"`；缺省 → 无操作（不写不分配）。
- 值为字符串：`strcmp`（区分大小写）**仅精确 `"stepped"`** 命中 → 尾调用
  `spCurveTimeline_setStepped@0x2817c0`（0x28b3b4 `b`，夹具按
  `curves[frame*19+0]=1.0f` 精确建模）。
- 值为数组：**实现完全不读 Json+0x0c 的声明计数**，无条件沿 `->next` 取 4 个
  节点；元素 0..3 原样传 `spCurveTimeline_setCurve@0x2817d8`
  （6 个 AAPCS 字：r0,r1,r2,r3,[sp],[sp,#4]）。**少于 4 个元素 = 原件空指针
  解引用**（0x28b3b8 与 0x28b3c8 之间无检查，独立探针实测 qemu SIGSEGV，已作为
  PROBE 钉进验收）；多于 4 个尾部忽略；null/true/false/number/object 全 no-op。
- 帧下标与 +0/-0/NaN/-inf 等浮点位**原样透传**（位精确断言）。

## 验收

- `tools/check_animations.py`：O0/O2/O3/UBSan × 9 测试全绿、9 具名变异全拒、
  缺本体编译拒绝门、26 word pin + 7 键字面量 + 符号 pin；
  **父代理独立复跑 RESULT PASS**（wl_animP_verify）。
  回执 `harness/receipts/animations_entry_check-20261108T103440.json`。
- `tools/check_curve.py`：O0/O2/O3/UBSan × 9 测试全绿、8 具名变异全拒、缺本体
  拒绝门、29 word pin（含 0x28b3fc=0xe92d4ff0 作下界证明）+ 10 个 Json 类型
  常量 pin + `curve@0x357aec`/`stepped@0x357af4` 字面量 pin + 「0x28b34c 无符号」
  断言 + 0 元素数组 SIGSEGV probe；
  **父代理独立复跑 RESULT PASS**（wl_curveP_verify）。
  回执 `harness/receipts/curve_check-20261108T103809.json`。

## 第三批：B3/B4/B3b + slots 时间线家族（B5/B8/B8b/E1）

**B3/B4/B3b**（`c/spine_read_animations/` 扩展，子代理施工、父代理复跑
`RESULT PASS`，4 配置×20 测试、13 变异、2 编译拒绝门含 shadow 布局断言门）：

- B3 拆两半：`animationFrameInit`（0x28d2d4..0x28d314，每 animations 数组一次：
  4 个键字面量入栈槽 + **movw 0x5556/movt 0x5555 → str [sp,#0x60]** 即
  0x55555556 魔数（有符号 /3，唯一读点在未恢复的 deform 块））与
  `animationKeys`（0x28d318..0x28d3b0，每动画一次：8 次 getItem，按地址序
  落槽 bones/slots(r4 无槽)/ik/transform/paths/deform/drawOrder/events）。
- B4 求和（非 stock 形状）：bones/slots/paths 逐子累加 `child->unk_0c`；
  **ik/transform 各只加节点自身 +0x0c 一次**；deform 双层 skins×slots；
  drawOrder/events 各 +1；name=**动画节点的 Json 成员键**；spAnimation_create
  (name,count) 合成边界（0x2812b4..0x281324：calloc(1,16,tag,38)，+0x00 name、
  +0x08=count、+0x0c=malloc(count<<2,tag,41)）；返回后 +0x08 清零。
- B3b：'draworder' 键 getItem 后**无条件**写 drawOrder 槽（无 NULL 复检）。
- **普查更正（已证）**：`Json_getItem` 内部是 **strcasecmp**（0x287414 →
  strcasecmp@plt 0xb66d0，父代理核对 .rel.plt）——'drawOrder'/'draworder'
  是**同一个查询**，双键 fallback 行为上无效（命中子链表先出现者），
  §2.9 的"新键优先"说法作废。

**slots 时间线家族**（`c/spine_read_tl_slots/` 新模块，子代理施工、父代理
复跑 `RESULT PASS`，4 配置×11 测试、10 变异、**3 编译拒绝门**：缺本体 /
去 readCurve 源 / 去 toColor 源——证明跨模块真实链接非桩）：

- B5（attachment）：每槽 findSlotIndex（**真实** skeleton_find）→ `cmn r0,#1`
  未命中跳块外；时间线按 `timelineJson->name(+0x1c)` 两级 strcmp 分派
  color/attachment/其它→E1。attachment：create(Json+0x0c)→**timeline+0x10=slotIndex**→
  帧循环 getItem("name")+getFloat("time")，`kind=name_node+0x08`，
  `name=(kind==2)?NULL:+0x10`（**与 stock 的 name?valueString:0 形状不同**）→
  setFrame(t,i,time,name)；循环由子链驱动。尾：timelines[count++]=t、
  duration=max(duration,frames[declared-1])（frames +0x0c、帧距 1 float）。
- B8（color hex 通道）：create→**timeline+0x14=slotIndex（与 B5 的 +0x10 不同）**
  →每帧 getString("color")（hex 字符串）→ **真实 toColor ×4** →
  setFrame 7 参（r0..r3,[sp],[sp+4],[sp+8]）→ **真实 readCurve(frame,t,i)**
  （0x28d9b0）。无任何校验：缺 color → toColor(NULL,·)，非法串四分量 -1.0f。
  **color +0x08 不是 frameCount 而是 (frameCount-1)*19 的 curves 数组**
  （attachment +0x08 才是 frameCount）。
- B8b：timelines[count++]=t；last=frames[(declared-1)*5]（**+0x10、帧距 5**：
  time,r,g,b,a）；duration 取 max；回 B5 分派。**普查更正：B8b 不是
  "color/attachment 公共尾"**——B5 在 0x28d5e8 有自己的一份内联尾；且
  readCurve 调用点 0x28d9b0 在 B8 区间内。
- E1：`spAnimation_dispose(anim)` → `setError(parser, **NULL**,
  "Invalid timeline type for a slot: ", type)`（0x28da38 `mov r1,#0`——
  **json 实参是 NULL，根树不 dispose**，与 slots 段错误路径不同）→
  `spSkeletonData_dispose(data)` → 返回 0。
- 帧下标来源：B5/B8 内无 `mov r5,#0`——分派用 strcmp 返回值 r5，两分支
  只在 ==0 进入，帧循环天然从 0 起、跨时间线不携带。

回执：`animations_b3b4_check-20261108T110203.json` /
`tl_slots_check-20261108T110414.json`。

## 合成边界与欠账（累计）

- 合成边界：`spEventData_create@0x285b94`（本体未恢复）、
  `spCurveTimeline_setStepped@0x2817c0`（24B）、`spCurveTimeline_setCurve@0x2817d8`
  （264B，66 insn）——夹具只记录 ABI 字；`setCurve` 本体是后续批次的候选。
- 事件名取成员键意味着 events 是「按名对象」形态；仓内无 skeleton JSON 资产可
  独立佐证，译文只按 0x28d20c 字面执行（open，登记在模块 functions.json）。
- B3/B4（单动画前置 + timelineCount/spAnimation_create）及 B5 起时间线块族未恢复。

## 普查更正（本批实测）

1. `animations_segment_map.md` §7 open #10 表述不精确：animations **数组基址在
   B2 的 0x28d2cc 就写入**，循环尾（0x28e784/0x28e78c）只写 count 与元素；
   §3.1 的 `0x28d2bc→[r9,#0x38]` 本身正确。
2. `asm/functions.tsv` 的 `anon_28b34c` 记为 944B（0x28b34c..0x28b6fc，237 insns）
   ——把 readCurve（0x28b34c..0x28b3fc）、_readVertices（0x28b3fc 起，已恢复）、
   toColor（0x28b680 起，已恢复）三个匿名函数并成了一条。恢复/引用时以
   0x28b3fc=0xe92d4ff0（push {r4-r11,lr}）字钉为界；**不要拿 functions.tsv 的
   944B 当 readCurve 的范围**。此条为索引口径缺陷，登记不动表（表是生成物）。
