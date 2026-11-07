# Skin 原生四入口及 linked 后处理合同

样本SHA256：3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a。
原件只读；本轮不使用原件执行、ART、Unicorn。逐函数身份见functions.json。

## 四个新入口

- _Entry_create@0x28ebb8：104B含4B池；calloc(1,16,Skin.c,36)，先写slot，再strlen/malloc(line38)，
  name指针写入先于strcpy，attachment写入晚于strcpy。没有NULL或失败返回保护。
- spSkin_create@0x28ec44：88B含4B池；calloc(1,8,line52)，名字复制malloc(line53)。
- spSkin_addAttachment@0x28ecd8：40B；真正调用noinline Entry_create后才读取现有head并头插。
  重复(slot,name)不替换旧项，所以查找按最新同名项胜出。构造回调若改head，新项接到新head前。
- spSkin_getAttachment@0x28ed00：88B；只对slot相等项调用strcmp；返回attachment或读next发生在比较回调后。
  case-sensitive，未添加对象/名字NULL检查或类型检查。

新skin8B、entry16B有唯一完整共享类型；spSkin_dispose/_Entry_dispose仍使用已有原生raw-ABI本体，
不重复定义。借用完整spAttachment指针；重复插入同一attachment的销毁风险按原件保留，没有引用计数修复。
分配tag字节统一是原0x357f90处的完整jni/.../Skin.c路径，行号不是宿主源行号。

## 三个既有find入口的canonical修缮

原件findBone/findSlotIndex都明确读取对象+4名字，旧候选的局部struct却将name放在+0；本批改为
共享完整84B spSkeletonData，并令Bone/Slot保持opaque，通过原生32位字读取已证字段，不伪造完整对象。
findSkin读取+0名字。三个入口都先snapshot signed count，非正直接返回；正数才取table快照。
strcmp可以改变原对象/全局状态，但原件count/base/object指针均不重取，只逐项读同一表的下一槽。
findSlotIndex返回0-based索引或-1，另两者返回已加载的对象指针或NULL。
所有地址加法/索引移位按32位回绕，不构造C的before-array指针。

## 后处理caller块，不是额外原函数

0x28ccb8..0x28cd6c + 0x28e880..0x28e8ac：

1. signed linked count非正，直接到events后继，不读queue/data。
2. 每轮重取queue，按index<<4取一项。skin名字NULL取data+0x28 defaultSkin，不是数组第一项；否则findSkin。
3. skin查找之后再从原entry读parent/slot；缺skin或parent先dispose整份data，再从entry读extra传setError。
4. parent查找成功，setParentMesh→重读entry.mesh给updateUVs→再次重读entry.mesh与parser.loader给configure。
   不把合法的late-NULL configure参数写成&NULL->member；该加载只做指针转换，不额外解引用。
5. configure之后重取signed count决定回边；下一轮也重取queue。成功既不清count，也不释放queue。

API返回1仅表示到达0x28d19c后继，0表示原件NULL返回路径且data已被释放；不是完整loader接口。
新函数及已修find都只是可编译候选，原版等价、全库闭合、任意畸形指针/故障/FPSCR域不由这些合同证明。
