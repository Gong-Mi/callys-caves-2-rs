# 原生 mesh/link caller 与 UV/共享几何

## 身份与交付边界

原件 libyoyo ARM32 SHA256：
`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
方法仍是 reverse-v1/METHOD.md §0：先静态语义和可编译 C，本轮不执行原件、ART、Unicorn或游戏。

本批新增两个独立原版入口的可编译候选：

| 入口 | 代码 | literal | 译文 |
|---|---|---|---|
| spMeshAttachment_updateUVs@0x287538 | 276 B / 69 ARM words | 4 B，到0x287650 | c/spine_mesh/src/spine_mesh.c |
| spMeshAttachment_setParentMesh@0x287654 | 128 B / 32 ARM words | 无，到0x2876d4 | 同上 |

另修复并提取此前已有的 `toColor@0x28b680` 为唯一共享本体（124 B / 31 ARM words + 4 B literal），
位于 `c/spine_color/`。它不是新增第三个原版函数；旧 `spine_read_slots` 不再重复登记或定义它。

`c/spine_read_mesh/` 是 readSkeletonData 原函数内的 caller BLOCK，不是新的原版函数：
0x28cb20..0x28cc68、0x28cfa8..0x28d008、0x28d008..0x28d144，复用 configure
出口0x28cd9c..0x28cda8。API返回0/1只表示普通/延后绑定两个原控制流后继，不冒充原版返回值。

所有主体仍标 complete compiled candidate，phase_complete=false；原版/全库等价未验。
逐路径合同、原件体SHA与译文SHA在各模块 functions.json，不以卡数或通过数替代语义完成率。

## 原件决定的语义

- updateUVs在free之前缓存count、u2-u和v2-v；free(NULL)照传，size=count<<2按32位回绕。
  malloc后才读rotate和source；循环每次再读u/v，输出u在第二个source读取之前落盘。
- 普通映射：u+width*x、v+height*y；旋转映射：u+width*y、(height+实时v)-height*x。
  VFPv3 VMLA/VMLS是非融合操作，乘积先舍入；不能改成融合FMA。旋转VADD保留原操作数顺序。
- signed count<=0也照样free/allocate/发布新指针，但不读source；奇数count写完整最后一对，
  会超过所请求count*4的4字节。本批保留原行为，未把它修成安全裁剪。
- setParentMesh先写parent指针，再判NULL；非NULL时先读13槽再写13槽。
  vertices/bones/sourceUVs/triangles/edges共享；path、颜色和derived UV仍由子对象持有。
  实际析构链因此避免子对象重复释放父数组。
- mesh路径字符串无region分支的NULL守卫；width/height默认32.0f，再读当前scale乘法。
  triangles按uint16截断，edges按int32复制，三种数组跟child链而非声明size结束。
- `_readVertices`接收分配UV前缓存的UV词数，随后调用真实updateUVs。
  hull原值直存，不乘2；optional edges缺席时保持字段。普通分支最后才configure。
- parent分派看Json节点是否存在，不看string_value是否非空。linked分支先登记deform(default1)、
  skin和parent借用字符串，再入16字节队列；此时不解析vertices、不updateUVs、不configure。
- 队列容量相等时signed doubled>7取翻倍，否则最小8项；容量先发布，再malloc(line136)。
  malloc后重读count/base供memcpy，memcpy后重读旧base供free，free后再读count并发布新base。
  append地址按32位base+(count<<4)回绕，count先增，再按skin/mesh/slot/parent次序写记录。
- toColor不是手写hex循环：原件调用strtoul，故两字符`+1`、` 1`可接受；`-1`的结果按
  SIGNED VCVT.f32.s32解释再除255。NULL和index越界守卫在原件不存在。
  原静态helper用r0/r1入参、s0返回，本体和全部槽模块声明用per-function aapcs-vfp一致绑定。

## 共享记录与旧行为保持

`c/spine_json_layout.h`提供唯一完整28字节parser与16字节linked项。
parser地址槽明确是原生uint32 pointer-word，保留既有LP64诊断接口，不用宿主8字节指针扩宽记录。
creation/dispose、error、reader共享该定义；mesh/vertex共用既有0x94/0x24完整记录，不改字段名。

parser lifetime与error只因共享记录调整了表示。ARM32 O2的text/rodata与规范化relocation，
已与8fdbe61对应旧模块逐字节对账相同：
`~/.hermes/reports/cally-mesh-20261108/layout-preservation/receipt.json`。
旧slots和entry两TU均另作真实ARM32 O2 -Wall -Wextra -Werror编译；不是只编新consumer。

## 实跑与证据

验收命令（在活树根，输出目录必须不存在）：

    python -B reconstruction/reverse-v1/c/spine_read_mesh/tools/check_mesh.py --so /path/to/libyoyo.so --out /new/private/output

最终回执：`~/.hermes/reports/cally-mesh-20261108/run-04/receipt.json`。
SHA256：`7cd2811e22a6384fd20c5ac965daebe445bda2be29ff3479970080e8a306fee5`。

- 新构建O0/O2/O3/UBSan各16项具名合同通过；16个运行期变异均以exit1和FAIL断言被捕获。
  编译失败、signal崩溃不计入语义击杀。缺spine_mesh本体的链接被拒绝，另账而非第17个变异。
- consumer实跑实际allocator、Json accessor、_readVertices、UV、configure转发及附件析构C本体。
  底层malloc/free/libc与loader配置回调是明确的合成provider。
- 覆盖包括旋转/普通UV、free前快照与malloc后重读、重叠source/output读写序、负/零/奇数count、
  非融合舍入抵消例、空输入sNaN标志、父项共享/NULL、optional edges、child与UV count缓存、
  两次队列增长和回调修改队列。不是全部输入域或全函数等价证明。
- 旧native-spine入口8个重建程序通过；既有_readVertices O0/O2/O3/UBSan各11项与9变异重过。
  旧parser生命周期及释放消费链的host/ARM32具名用例、原有变异与no-op阳性均通过。
- 初跑缺fixture的__aeabi_memcpy4，补齐后继续；第二轮parent-truth变异落入缺数组的故障而非
  命名断言，已把该输入补成两后继都合法，最终不再以崩溃充当击杀。

这些都是重建C/具名合成边界证据，不是原版运行证据；旧oracle回执不迁移给新本体。

## 独立审查与相邻旧缺陷裁决

独立审查报告：`~/.hermes/reports/cally-mesh-20261108/review/review.json`，
SHA256 `3f28ae8e9b6ee685a94f6038387eed08128fdb53cc5a85843e01a19d3ba38d01`。
父级逐项回读原字节与8fdbe61，确认新三方法/caller未发现已证缺陷，27项执行绑定仍一致。

发现的四项均在8fdbe61已存在，本批未改变这些语义，不是本轮新增回归：

| ID | 原件锚点 | 已确认旧偏差 | 本批裁决 |
|---|---|---|---|
| F1 | 0x28bd1c/3c/5c | slots additive/multiply/screen应为1/2/3，旧C为3/1/2；未匹配时旧C额外写0 | 未修，阻止slot语义完成声明 |
| F2 | 0x28b7f0/7f8→0x357b08 | setError malloc tag应为SkeletonJson.c路径，旧C为spine_json_err | 未修，错误路径仍有差异 |
| F3 | 0x28eb98/eba4→0x357f70 | 文件失败文案应为Unable to read skeleton file，旧C为Error reading skeleton file | 未修，错误路径仍有差异 |
| F4 | 0x28bc78..bc94 | slotData创建后旧C多加NULL提前返回，原件没有 | 未修，故障行为仍未恢复 |

本批接入旧slots仅为共用toColor；parser error仅统一记录表示。其运行逻辑不在mesh验收范围，
不能因对应文件编译或O2文本保持就声称这些旧路径已还原。父级裁决另存同目录parent-adjudication.json。
后续应按slots/error两个独立失败域恢复及验收，不混进mesh提交冒充本批闭合。

## 尚未恢复与下一入口

本批只接到原0x28cc68后继前；`spSkin_addAttachment`公共插入与skin/slot外循环未总装。
linked parent/skin名称解析后处理仍在0x28ccb8..0x28cd6c（含0x28e880错误出口）；
下一完整方法及直接依赖是 `spSkin_getAttachment@0x28ed00` 与队列后处理的查找/失败清理。
随后回到region color/updateOffset尾部、events/animations和完整loader装配。

全FPSCR模式/硬件/trap、精确非法指针/真实分配失败故障、极大地址回绕域、渲染消费者及
与原件同输入对照均未认证。linked共享夹具是显式选择父对象，不冒充原名称后处理已完成。
