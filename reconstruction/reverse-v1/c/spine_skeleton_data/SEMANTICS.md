# skeletonData 完整释放方法与直接依赖的静态译文

样本 SHA256：`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
交付是原件静态推导的 ARM32 C，不是照网上 spine 版本重写。
本模块不认证全库静态闭合或原版行为等价；阶段口径以 `../../METHOD.md` 第0节为准。

## 逐函数身份与 ABI

除 create 外均为单指针实参、调用者不消费返回值的清理入口；译文以 void 表示。
虚调用使用原 ARM32 函数指针槽，禁止拿 64 位 host 的宽度代入。

| 原件入口 | VA/字节 | 本体及调用合同 |
|---|---|---|
| spSkeletonData_create | 0x28addc/28 | `_calloc(1,84,原件文件串,37)`；直接转交结果，无额外检查 |
| spSkeletonData_dispose | 0x28adf8/452 | 八组 vector 的带符号计数循环、表释放、+4/+0/self 尾序 |
| spBoneData_dispose | 0x285ac4/28 | free(+4)，free(self) |
| spSlotData_dispose | 0x28efa8/36 | free(+4)，重新读 free(+0xc)，free(self) |
| spSkin_dispose | 0x28ec9c/60 | 遍历+4单链，next@+0xc 在回调前抓取；free(+0)，free(self) |
| _Entry_dispose | 0x28ec20/36 | attachment@+8 的虚析构，然后重新读 free(+4)，free(self) |
| spEventData_dispose | 0x285bec/36 | free(+0xc)，重新读 free(+0)，free(self) |
| spAnimation_dispose | 0x28147c/80 | count@+8/table@+0xc 的 timeline 循环；表、+0、自身 |
| spIkConstraintData_dispose | 0x286758/36 | free(+0)，重新读 free(+8)，free(self) |
| spTransformConstraintData_dispose | 0x28f608/36 | free(+0)，重新读 free(+8)，free(self) |
| spPathConstraintData_dispose | 0x288f34/36 | free(+0)，重新读 free(+8)，free(self) |
| spTimeline_dispose | 0x281468/20 | table=self+4，调用 table+4；本入口不另外 free |
| spAttachment_dispose | 0x284cb4/20 | table=self+8，调用 table+0；本入口不另外 free |

create 共六条指令和一个 literal（不是七条指令）；literal@0x28adf4 经 add@0x28adec
得到 0x357ab0 的 `jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonData.c`。
分配记录为84字节，但未用字段不取语义名字；本模块仅公开21个32位槽的容器布局。

## 核心循环：不能按惯常析构代码简化

skeletonData 的 count/table 对按顺序为：

    +0x10/+0x14  bone
    +0x18/+0x1c  slot
    +0x20/+0x24  skin
    +0x2c/+0x30  event
    +0x34/+0x38  animation
    +0x3c/+0x40  ikConstraint
    +0x44/+0x48  transformConstraint
    +0x4c/+0x50  pathConstraint

每组入口按 signed count > 0 决定是否进入。每一项在本次读取的表中取出，索引加一后调用；
回边在外调之后重新读取 count，再以 signed `count > index` 判定。
不能把 count/table 提到循环外。结束后还要重新读取 table 再 free；count<=0 时仍 free表。
数组地址的 shift/add 保持32位回绕，不按host pointer宽度隐式扩成64位。
最后依次读取/释放 +4、+0、自身；+8、+0xc、+0x28 不由本入口释放。
所有入口保持原件的 NULL/有效对象前提，不加原件不存在的防护或清零。

## 编译与小型合同检查

源码 `src/spine_skeleton_data.c`，头文件明确拒绝非32位构建。
`fixture/check.c` 只检查译文和具型替身，不是原件 oracle：

- 全图：从84字节 create 容器进入八族子对象与两种真实虚调用分发，核对完整事件次序。
- 非正计数：零或 INT32_MIN 不访问条目，但仍按顺序释放各表。
- 回调缩短 count：必须在第一次子对象清理后停，不缓存旧计数。
- 回调替换 table：第二次访问及最终表释放必须使用新表。
- scalar 第二字段：第一个 free 回调改字段后，必须重新读取再释放。

ARM32 使用仓库已有 `csprite_resources/fixture/fx.h`、`arm32_support.c` 和 qemu-arm；
不新增通用测试框架、不运行原件/ART/Unicorn。实际编译命令及产物身份由父级回执记录。

## 仍未闭合的内部范围

`_calloc/_free` 的真实派发本体由同批 allocation 模块提供；独立 fixture 仍用具名 provider，
累计 fixture/integration.c 则实际链接 allocation、attachment、JSON、data 和 atlas 译文，
并分别走初始 libc 地址槽与 Debug 回调，验证真实清理调用序。libc/解析/GPU仍是明确替身。
timeline/attachment 的虚调用本入口已恢复，但各具体类型的 vtable 生产者和回调函数体不因
分发器完成而自动完成；皮肤/动画创建、JSON解析和真实数据图加载也不在本模块。
所有13入口目前是“已交完整可编译本体”的候选，不能仅凭此标为全库语义闭合。
