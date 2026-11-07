# 原生顶点解析：本体与真实重建调用方

## 身份与交付边界

- 原件：ARM32 `libyoyo.so`，SHA256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
- 本轮新增原版入口只有 `_readVertices@0x28b3fc` 一个；`0x28b670..0x28b680` 为四词 literal pool，代码范围 `[0x28b3fc,0x28b670)`，628B/157 ARM words。
- 原始调用点：path `0x28cab4`、boundingbox `0x28cd94`、mesh `0x28d0c0`。nearest-symbol 的 `findPathConstraint+...` 不代表函数归属。
- 交付：`reverse-v1/c/spine_read_vertices/{src,fixture,tools,functions.json}`。`s32/at/load_f32/cvt_i32/scale_equal_one/mul_f32` 是数值/ABI 适配助手，不计作新增原版方法。
- 语义证据 `bytecode_anchored`；运行验收为重建 C 的 `test_anchored`。原件只作为文件读取，未执行原件、ART 或 Unicorn；不增 L5/oracle 臂计数。

## 已从原件核定的机制

| 路径 | 原件锚 | 合同 |
|---|---|---|
| 入口与复制 | 28b414–28b464 | 先写 +0x20，再查 vertices；快照 JSON+0x0c；malloc 行513；分配返回后读 child，按 next 链复制原 float bits |
| 非加权 | 28b468/28b5e0–28b638 | 唯一门为 size==verticesCount；总是读/比较 scale；scale==1 时不算术，保留 sNaN payload；其它正 count 逐元素重读 scale 并 binary32 相乘；数组转移所有权、不 free |
| 加权计数 | 28b470–28b4bc | VCVT.s32.f32；32位回绕与有符号比较；骨流 sum(1+n)、float 流 sum(3*n) |
| 分配与重读 | 28b4c8–28b508 | 先发布计数；行537分配顶点；回调后重新读 +0x10，且在写 +0x1c 前读；行538分配骨流 |
| 加权发射 | 28b50c–28b5dc | 每组写 n 与整数骨索引；x/y 分别乘实时 scale；weight 原字拷贝；零骨组消费一个计数词；保留 post-loop unsigned LSR 公式 |
| 非正 size 与释放 | 28b63c–28b66c/28b5c4–28b5d0 | unequal 且 signed size<=0 仍做两次分配，再释放临时数组；不凭常识加入安全返回 |

共享布局修正：`spVertexAttachment` 的完整公共基类是 0x24B，含 +0x20 worldVerticesLength；原来 0x20B 只是 lifetime 已知前缀。具体 bbox/path/mesh 的总尺寸和后续字段偏移不变，未复制另一套临时结构。

## 两条真实重建消费链

1. `spBoundingBoxAttachment_create → Json_getInt/_readVertices → configureAttachment → _spBoundingBoxAttachment_dispose`。
   原件 `0x28cd98` 真写 +0x18，故会覆盖加权 helper 刚算出的 float count；保留这个行为，不擅改成 +0x20。
2. `spPathAttachment_create → closed/constantSpeed/vertexCount → _readVertices → lengths → _spPathAttachment_dispose`。
   修复旧包装的实际偏差：+0x24 的 count 写在 malloc 行985之前；逐 child 读取当前 parser scale；原件不对缺失 lengths key 判空；next 在结果写入之前取出。

这些是 readSkeletonData 内的 caller BLOCK API，不是两个新增独立原函数；全 loader 总装仍未完成。

## 可重跑验收

在项目根运行（out 必须是新目录）：

    python -B reconstruction/reverse-v1/c/spine_read_vertices/tools/check_read_vertices.py --so /data/data/com.termux/files/home/cally-oracle/libyoyo.so --out "$TMPDIR/cally-vertices-new-run"

真实 target：armv7a-none-eabi / armv7-a / VFPv3 / softfp，未伪造 __SOFTFP__。allocator 的整数/指针接口允许真实 core-register soft/softfp，仍拒绝 hard-float。

- O0、O2、O3、UBSan-trap：各 11 个具名合同通过；转换、零组、空/非正 size、回调重读、所有权及两条消费链均有断言。
- 9 个单决策变异均以具名 FAIL 捕获：加权门、误缩放 weight、缓存 count、缓存 child、跳过零组、unit-scale 强乘、空数组省掉 scale 比较、bbox 写错字段、length count 延后写。
- 比较必须保留，即使 count<=0：普通 C 浮点 `&&` 被优化成先检查 count、跳掉 sNaN 比较；已改成显式 VFP VCMP/VMRS，小夹具与反例认证的是重建侧该合同。
- 既有 `c/check-native-spine.sh` 八个 ARM32 重建程序仍通过；全库索引检查仍为 246 cards / 649229 anchors / 跨卡重复0，仅证明锚点索引对应。
- 每次回执绑定 compiler -MM 导出的 C/头闭包、checker、完整链接 binary SHA、构建参数及编译器/QEMU版本。变异只落独占输出目录，不改工作树。

## 最近历史成果的采用判定

已回读 Cally 会话 `20261107_075846_c4c961` 的 `935486` 断点，以及 Shamiko `939903/940885`、MMD `940836` 等实际消息，并打开对应共享 ABI/回执工具；完整只读调查归档在 `~/.hermes/reports/cally-readvertices-20261107/recent-reuse-audit/`。

- 采用：逐槽/总大小断言、单一共享类型、全输入闭包与完整链接物 SHA 绑定、具名决策变异。本批给 Json 补齐 ARM32 消费偏移断言；checker 在构建后、执行前打印 BINDING，验收前后核源/链接物未漂移。
- 不搬：Shamiko 的大规模块缓存、MMD 简单叶子的形状族生成器、momo live/ART 环境。当前对象是有循环/分配/数值状态的解析 helper，这些装置不能替它恢复语义。
- 类型复用受限：旧 skeleton_find 与 skeleton_data 的同名记录定义尚未统一，未借本批顺带宣布该链闭合；只修本批直接依赖的顶点完整基类。
- 本轮额外编译负控：hard-float、软件浮点目标、Json+0x0c 被移动分别具名拒绝；它们是 ABI/布局门，不混进9个运行期语义变异。

独立静态复核绑定 C 源 `39f1d66959fd9ee451a3395777f7cee12e441c8827c4d9b6113482184dfb36e0`；父级另从原 ELF 的 `.ARM.exidx` 独立复算 0x28b34c/0x28b3fc/0x28b680 边界，未采信最近符号当边界。审阅时“缺 manifest/状态仍 NOT RECOVERED”的时点观察已由本批补齐，不当作最终残留。

持久回执：`/data/data/com.termux/files/home/.hermes/reports/cally-readvertices-20261107/accepted-final/receipt.json`。旧 `accepted/` 是前一轮候选，checker/Json头后续变化后不再代表最终源。

## 尚未覆盖与下一步

不主张全部畸形指针/数组/重叠分配器输入的 fault signal/PC 等价；超大申请的合成 provider 只验证请求位宽及控制流，不认证真实分配可行性。完整 FPSCR 舍入/flush/default-NaN/trap 矩阵、硬件和原件同输入对照尚未验。

推进图：已恢复顶点 helper → mesh/linkedmesh 解析体 `0x28cb20` 及其直接依赖 → linkedmesh 后处理/region color 尾部 → readAnimation → readSkeletonData 全函数装配 → 依照现行阶段授权安排原件对照。不能因本轮局部自测绿就宣布 loader 或全库完成。
