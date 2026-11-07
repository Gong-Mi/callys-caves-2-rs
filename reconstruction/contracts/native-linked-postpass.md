# Linkedmesh 后处理：父项查找、共享几何与失败清理

## 原件、方法与交付

原件SHA256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
执行METHOD §0：只读原件字节，只编译/执行重建C；无原件运行、ART、Unicorn或前台操作。

本批新增六个原版入口候选：

| 模块 | 方法 | 原VA / 总bytes |
|---|---|---|
| spine_skin | _Entry_create | 0x28ebb8 /104（含4B池） |
| spine_skin | spSkin_create | 0x28ec44 /88（含4B池） |
| spine_skin | spSkin_addAttachment | 0x28ecd8 /40 |
| spine_skin | spSkin_getAttachment | 0x28ed00 /88 |
| spine_json_support | Json_dispose | 0x2872c8 /88 |
| spine_json_support | ReportSpineError | 0xc4404 /52（含8B池） |

findBone/findSlotIndex/findSkin三既有方法改用canonical完整84B data；修正旧Bone/Slot局部假结构
把name放在+0而非原+4的问题，保留count/table/object快照与strcmp后逐项读取。
setError/filewrapper两既有方法修正tag、文案、原调用顺序与参数、variadic vcall与实际栈保护。
原件函数数不因此再增加五个；任何支撑C助手也不计新增原版函数。

`spine_linked_postpass`覆盖父readSkeletonData内0x28ccb8..0x28cd6c和0x28e880..0x28e8ac。
它是caller BLOCK，不是额外原函数。int返回1仅表示到events后继0x28d19c；0对应原NULL-return且data已释放。
所有逐函数身份、source/header/body哈希及缺口在各functions.json；phase_complete仍false。

## 已接通的实际链

重建JSON对象→mesh/linked字段→真实Skin头插（重复项不替换）→真实默认/具名skin与attachment查找→
setParentMesh共享数组→updateUVs生成子对象独占UV→当前loader configure→原有真实Skin/Entry/附件析构。
父项不存在或skin不存在：先原恢复的spSkeletonData_dispose，再重读借用的extra→实际setError→实际Report vcall。
平台sink、libc和底层malloc/free是具名合成provider；不是直接把期望错误或parent指针喂给后处理。

关键合同：

- 默认skin读data+0x28，不是skin数组首项；具名查找后才读parent/slot。
- getAttachment的attachment/next在strcmp后重读；head在Entry_create之后重读，重复键最新项优先。
- UV分配回调后重读entry.mesh用于configure；每次configure后读动态count，下轮再取queue。
- skin/parent错误均在销毁data后才读extra；错误成功报告后不再尝试继续解析events。
- 无额外parent附件类型检查；非正signed linked count不读queue/data。成功不清count、不free队列。
- 错误字符串处理保留无条件strlen(message)、strncat(buffer+length,extra,255-length)原实参。
- 原OutputEPKcz是变参vcall；实际strong/global canary在可选Json_dispose之后检查，不当成无关内部细节删除。

## 最终实跑

主链验收：

    python -B reconstruction/reverse-v1/c/spine_linked_postpass/tools/check_linked.py --so /path/to/libyoyo.so --out /new/exclusive/output

回执 `~/.hermes/reports/cally-linked-postpass-20261108/run-03/receipt.json`。
SHA256 `600109e9ce9ada4d802affed12b7b9c250503109bc7e581daf76ed96544d316f`。
O0/O2/O3/UBSan-trap各15项，17个语义变异均由exit1+具名FAIL捕获；40项源/头/夹具/checker绑定无漂移。
另外O0/O2/O3确认Json_dispose期间变canary会在setError拒绝；关闭guard的负控由另一具名断言识别。
缺skin本体的链接必须失败，不能由空stub代替。

独立error套件O0/O2/O3/UBSan-minimal各25项，10个变异均具名拒绝：
`~/.hermes/reports/cally-linked-postpass-20261108/error-final/receipt.json`，
SHA256 `bc9121fe63ca89a0c77f085d55f08e5ab442828f052050e2e9cae11fe99e140a`。
独立main/辅助门边界分别登记，不把重复编译档的通过数当方法覆盖率。

上一批mesh四档16项/16变异与既有native-spine八程序亦重跑通过。
父级生产源独立静态复核13项match、无阻塞发现，报告在parent-static-review/parent-static-review.json。
错误支持交接后父级又直接读原指令，纠正了原strlen/strncat调用、栈保护位置与变参回调，并用新反例验证。
首轮next-cache变异未被最终返回值区分，已补“中间strcmp是否被跳过”的精确调用数断言；未把存活变异算击杀。

## 继承缺陷与剩余入口

上一批F2（短malloc tag）/F3（错误文件前缀）在本批已修；F1 slots blend枚举和F4 slots创建后多余NULL返回
仍未修，未因新链绿灯升级旧slots。真实_readFile、完整readSkeletonData、平台console构造仍未恢复。
文件包装器测试中的_readFile/loader是合成provider，不是新增恢复方法。

后续仍需region color/updateOffset尾部、公共skin/slot外循环、events/animations与全loader总装。
原件同输入对照、任意别名/畸形指针故障PC、硬件FPSCR和真实平台初始化均未认证。
这份提交交付静态候选和可重跑的重建消费者，不声明全库/全游戏完成。
