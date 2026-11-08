# 状态与定性（2026-11-08 更新）

## 当前断点：animations 段 31 分块全部落 C，下一步动画级总装

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

| 段 | 行号 | JSON keys | 内容 |
|---|---|---|---|
| 入口+meta | 607–612 | hash/spine/version/width/height | locale 保护+骨架元数据 |
| bones | 615–660 | name/parent/x/y/rotation/scaleX/scaleY/shearX/shearY/inheritRotation/inheritScale | 骨数组+逐骨 |
| slots | 697–712 | bone/color/attachment | 槽数组 |
| ik | 735–760 | bones/bendDirection/mix | IK 约束 |
| transform | 782–800 | rotateMix/translateMix/scaleMix/shearMix/target/offset | 变换约束 |
| path | 810–830 | path/position/spacing/rotateMix | 路径约束 |
| skins | 839–890 | skins 递归 | 皮肤+附件 |
| attachments | 891–1000 | region/mesh/linkedmesh/boundingbox/type | 附件四类 |
| animations | 1000–1043+ | time/offsets/events/curves | 动画+事件 |

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

    VM 骨架        opcode 表（.data 0x3f20b4，32 项）｜线程化派发（VMExec+0x58 → blx）
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
