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

## 第四批：bones 时间线全家族 + ik 时间线家族（open #6 关闭）

**bones 家族**（`c/spine_read_tl_bones/` 新模块，子代理施工、父代理复跑
`RESULT PASS`，4 配置×18 测试、12 变异、3 拒绝门含去 readCurve/json 门）：

- B6 分派：每骨时间线 `findBoneIndex` → `cmn r0,#1` 未命中→E2；strcmp 链
  rotate→translate→scale→shear，全不中→E3。5 键缓存；'time' 键覆盖 bones
  溢出槽（0x28d694）——循环只用寄存器游标。
- **骨索引来自独立符号 `spSkeletonData_findBoneIndex@0x28b018`（88B）**：
  count=[data+0x10]（有符号 ≤0→-1）、strcmp([table[i]+4],name) **首个匹配**
  返回 i、未命中 `mvn r0,#0`；与 findBone(0x28afbc/92B) 相邻不可混用。
  该函数体本批在模块内恢复为真链（暂驻副本：若 skeleton_find 后续收编
  需删副本——已记 open）。
- B6b（translate/scale/shear 共用帧循环）：`timeline+0x14=boneIndex`（先于
  空帧判断）；键 time/x/y；`s17=x*s16`、`s15=s16*y`——**translate 的乘数是
  parser->scale（spSkeletonJson+0x00 binary32），scale/shear 强制 s16=1.0**；
  setFrame(t,i,time,x*s16,y*s16)；readCurve@0x28d7d0；尾 (declared-1)*3
  字索引、frames +0x10、duration=max。
- B10 rotate：键 time/**angle**；setFrame(t,i,time,angle)；帧距 **2**
  （`frames[declared*2-2]`）；readCurve@0x28daf0。
- **`spScaleTimeline_setFrame@0x282b1c` 与 `spShearTimeline_setFrame@0x282b38`
  都是 4 字节 `b` thunk，同指 0x282ad4**（translate 的 setFrame；父代理
  逐字核对）——全族只有一个真实 setFrame 调用点。
- E2（Bone not found）：`spAnimation_dispose` → **setError(parser,
  [sp,#0x1c]=当前 animation JSON 节点, "Bone not found: ", bone->name)**
  ——json 实参是**动画节点**（连带其兄弟被 Json_dispose），非 NULL 非根
  （父代理核对 0x28db70 `ldr r1,[sp,#0x1c]`）；E3：json 实参 NULL。
  三种错误路径的 json 实参三种形态（根树/NULL/动画节点），逐块验证不默认。

**ik 家族**（`c/spine_read_tl_ik/` 新模块，子代理施工、父代理复跑
`RESULT PASS`，4 配置×13 测试、11 变异、3 拒绝门）——**普查 open #6 关闭**：

- B7 指针扫描（逐指令钉死）：count=[data+0x3c] **只读一次快照** →
  `ble` 有符号 ≤0 **直接跳（连 +0x40 都不读）** → array=[data+0x40] →
  e=array[0] → 命中→`mov r3,#0`(0x28dbc8，r3 是元素指针必须清)+
  `str r3,[r6,#0x14]`(0x28dbcc)；未中→`ldr r0,[r2,#0x4]!`（**前索引写回，
  逐元素重读**）、index++、`bne` 只判等；未命中**不写 +0x14**。
  create 后 +0x14 = calloc 零填 = **0 不是 -1**（静态推断：_spBaseTimeline_
  create 尾调 calloc(1,24,tag,233)，init 链不写 +0x14；推断待 create 本体
  恢复后升证明）。
- B7b 帧循环：键 time/**mix（默认 1.0f=0x3f800000）**/bendPositive
  （getInt 默认 1；**0→-1、非 0→+1** 枚举压栈）；setFrame ABI r0..r3+[sp]
  （bend int32）；体内帧步长 **3 浮点**（与 bone 1/2、color 5 都不同）；
  readCurve 在 setFrame 后；尾 next 载入夹在 frames 读与 duration 比较之间，
  `vstr duration` 无条件（末轮也写）。
- 普查更正：0x28dbc8 是 `mov r3,#0` 而非命中写点（唯一 store 是 0x28dbcc）；
  B11b 行把 0x28dbc8/0x28dbcc 误并入 shear 块地址跨度（语义属 B7 的离位
  命中岛，shear 5 条真指令以 `b 0x28d740` 收尾）；transform 命中 store
  0x28dd64 与 0x28dbcc **指令字同为 0xe5863014**（同一源句编译两次）。

回执：`tl_bones_check-20261108T113000.json` / `tl_ik_check-20261108T112242.json`。

## 第五批：transform 时间线（B12）+ path 时间线（B13，与 B17 分界实测）

**transform**（`c/spine_read_tl_transform/`，子代理施工、父代理复跑
`RESULT PASS`，4 配置×14 测试、14 变异、3 拒绝门）：

- B12（0x28dca8..0x28de74）：5 键（time/rotateMix/translateMix/scaleMix/
  shearMix）**每帧无条件全读**，缺键用默认（time→0.0f、四个 mix→1.0f）。
- 指针扫描与 ik 同构（count 快照 +0x44、ble 有符号、前索引写回、首命中
  行内 store `0x28dd64=0xe5863014`、未命中不写），但**命中岛在行内**非离岛。
- **setFrame 7 实参**：r1=idx/r2=time/r3=rotateMix，translate/scale/shear
  三参走栈（父代理核对 0x28ddec/0x28ddf0/0x28ddf4 三条 str）；体内
  `frames[i*5+0..4]`；**帧距 5 浮点**；create type=10。
- **B12 无任何错误路径**（父代理扫全区间 bl 目标：create/setFrame/
  getFloat/findTransformConstraint/readCurve 五类，无 setError）——bones 的
  json 实参三形态先例在此不适用。

**path**（`c/spine_read_tl_path/`，子代理施工、父代理复跑 `RESULT PASS`，
4 配置×18 测试、15 变异、4 拒绝门含"spacing setFrame 非调用点"负控门）：

- **B13 只做 position/spacing 两路分派**——`0x28e538 bne 0x28e8ec` 把其余
  子键整个交给 B17；**普查 §6 标题的 mix 不在 B13**（mix 字面量唯一读者
  是 B17 的 0x28e8f0）。**值键不是字面量**：`timelineNode->name(+0x1c)`
  直接当值键（同一循环体服务 position 与 spacing）。
- **path 有判空与错误路径**（0x28dee0 `subs` + "Path constraint not found: "
  @0x357f10）——**普查 open #6（不判空）不能外推到 path**。
- 扫描结果写**共享栈槽 [sp,#0x2c]**（0x28df2c），不是 timeline；timeline
  的 `+0x14` 在 0x28df94 **无条件写**（连无帧分支也写）→ **miss 会把上一
  约束的索引带进来（stale-index）**——与 ik/transform 最大差异。
- scale 选择不对称：position `mode!=0→1.0f / ==0→parser->scale`；spacing
  `(uint)mode<=1→scale`（**bls 无符号，mode=-1 不缩放**）/否则 1.0f。
- setFrame 4 参、`frames[i*2]`、帧距 2、create type 11/12。
- **B13 两个岛落在别块地址区间**（0x28e52c..0x28e558 在 B15 区间、
  0x28ea74..0x28ea7c 在 B17 区间）——按岛翻译不重复计数。
- B17 首两条反直觉（`strcmp(name,"mix")` 后 **beq 跳过**——名字恰是
  "mix" 反而不建 mix 时间线）：只记字节，留 B17 批定因。

回执：`tl_transform_check-20261108T114620.json` / `tl_path_check-20261108T120113.json`。

## 第六批：deform 时间线家族（open #5/#8 关闭）+ drawOrder（open #4 关闭）

**deform**（`c/spine_read_tl_deform/`，子代理施工、父代理复跑 `RESULT PASS`，
4 配置×21 测试、19 变异、5 拒绝门）：

- B14（0x28e060..0x28e338，182 insn）：三层循环 skin→slot→attachment 名→
  frames；`findSkin/findSlotIndex` **都不判空**（-1 也直接传 getAttachment）。
  **weighted 门 = attachment+0x14（bones 指针）非 NULL**；魔数
  `[sp,#0x60]` 在 0x28e128 `ldrne`（父代理核对：全函数恰好两处 [sp,#0x60]
  ——0x28d304 写、0x28e128 读，B13/B17 不碰）。**open #8 关闭**：
  `smull+asr#31+lsl#1` = 有符号 /3 截零再 ×2（25 例恒等式链含 INT_MIN）。
- **open #5 关闭**：`2*(vc/3)` 是每帧**浮点个数**——写 `timeline+0x14`，
  setFrame 用 `+0x14*4` 做 malloc+memcpy（0x282f3c/4c/60）；同一 r11 也是
  malloc 尺寸与 base 加法循环边界。
- 帧内顶点分支：'vertices' 缺失走 B14b（weighted→memset 全 floatCount；
  非 weighted→src=attachment+0x1c 不初始化）；'vertices' 存在从
  `buf+offset*4` 拷贝、`scale==1.0f` 原样否则逐元素 vmul，再 memset 尾段；
  非 weighted 且 floatCount>0 对整个缓冲加 base 顶点。**B14b 两半都属它**
  （缺键分支+scale 拷贝）。**_readVertices@0x28b3fc 未被调用**（父代理扫
  BL 目标核实：13 个目标无 0x28b3fc；帧内 vertices 是 getItem+child 链
  内联读，值在 Json+0x18）。
- **E6 归属修正**：实测唯一前驱是 **drawOrder offsets 循环**（0x28e464），
  B14 从不判 slotIndex==-1——普查 §6 标题"deform 路径"作废（§2.7 本就写
  drawOrder 内）。E6 的 setError json 实参 **NULL**。
- 错误块交叉：E4（drawOrder 地址区间）唯一入边来自 **deform 块的
  spSkin_getAttachment 返回 NULL**（0x28e10c/0x28e110）；E6（deform 地址
  区间）唯一入边来自 drawOrder——**错误块与触发块跨族交叉**，按入边
  归属不按地址归属。

**drawOrder**（`c/spine_read_tl_draworder/`，子代理施工、父代理复跑
`RESULT PASS`，4 配置×15 测试、15 变异、4 拒绝门）——**open #4 关闭**：

- 两次 malloc 所有权链（逐指令钉死）：**A(行442, (slotsCount-
  jsonOffsetsSize)*4) 从不交给 setFrame**——builder 内 0x28e524 调用前
  就 free（父代理核对 bl→_free）；**B(行445, slotsCount*4 填 -1) 交给
  setFrame（0x28e5b8）后立刻 0x28e5c0 free**；setFrame 也不留——先 free
  该槽上一份，再 malloc(690)+memcpy 存**私有副本**。free 序列
  A→NULL 槽→B 被 fixture 断言、四个 free 类变异反向验。
- B 填充/合并算法：条目 `getString("slot")→findSlotIndex`（==-1 → E6，
  **A/B 双泄漏照实复现不修**）；slotIndex≠original 时顺写 A；`offset=
  getInt("offset",0)`；**B[slotIndex+offset]=slotIndex**；尾填+从 B 末倒扫
  用 A[--unmoved] 补 -1（保升序）。`data->slotsCount` 被读 5 次，译文逐点
  重读（fixture 用 line-442 回调改写该字证明）。
- B15b：`setFrame(t,i,time,order)`→`_free(order)`（无 offsets 帧 free(NULL)
  照发）→发布尾 `times[declared-1]`（**4 字节步长**，与 path 8 字节不同）。
- create/setFrame 按真实体建模（合成边界）：type=7、calloc(1,24,tag,672)、
  +0x08/+0x0c/+0x10/+0x14；setFrame 先 free 旧再 malloc(690)+memcpy。
- E4：json 实参 NULL（`mov r1,r5`，r8 必 0）、文案 "Attachment not found: "
  @0x357f2c、extra=timelineNode->name。
- **普查勘误**：drawOrder 循环回边是 **0x28e5cc**（0x1affff78），§5.3 写的
  0x28e594 实为后半段入口。
- 32 位回绕如实：`jsonOffsetsSize>slotsCount` 时 442 请求值 0xfffffffc
  （不夹紧）。

回执：`tl_deform_check-20261108T122759.json` / `tl_draworder_check-20261108T122831.json`。

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
