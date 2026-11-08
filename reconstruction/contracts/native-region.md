# Region 字段、颜色与局部四角几何

## 身份与范围

原件 libyoyo ARM32 SHA256：
`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
按METHOD静态前置：原件只读，无原件执行、ART、Unicorn或前台操作。执行对象仅为重建ARM32 C。

新增一个完整原方法候选：`spRegionAttachment_updateOffset@0x289040`。
.dynsym与exidx边界到`0x289174`；304B代码/76个ARM字、4B literal pool。
本体SHA256 `7249ae07ef34dd4f9252bb8164c9d66770c28b725779211037bc5a58e99b8573`。

既有`readSkeletonData_regionFields`扩至`0x28cdac..0x28cf24`（376B/94个ARM字），
补齐color/updateOffset/configure尾部。它是readSkeletonData里的caller BLOCK，不计另一个原函数。
区块SHA256 `7101003a2e3dea32b5fdc93926a9fc18274a05fa81d1f0dc9afbb16eded0f56b`。
函数身份、源/头哈希、共享记录和缺口分别在两个模块functions.json；phase_complete仍false。

## 已接通的重建消费者

实际spAttachmentLoader_createAttachment→实际atlas工厂按名字找region→构造与UV填充→
实际Json getter→path复制与全部region字段→实际toColor→实际updateOffset→
当前loader的configure回调→实际spAttachment_dispose/_spRegionAttachment_dispose。
fixture提供完整canonical atlas/Json输入对象、分配器/libc边界与typed loader sink，不直接喂四角结果给生产方法。
metadata.region身份、工厂UV不被parser/geometry改写，path由真实析构只释放一次。

旧reader的float scale快照API改为canonical parser指针；x/y/w/h每次均在Json_getFloat之后重读scale。
去掉源内不兼容的_malloc声明与未接入的_strlen/_strcpy别名，统一真实生产接口。
原默认width/height仍32.0f，不改成0；scaleX/Y默认1、rotation默认0。

## 数值与调用边界

- 使用唯一0x9c字节spRegionAttachment与28B parser，不新增局部假结构。
- 尺寸/trim原字段按signed32执行VCVT；除法后再乘scale，保留VNMUL和非融合VMLA，不作代数改写。
- 度转弧度literal为float32 `0x3c8efa35`。先VMUL.F32，再VCVT.F64.F32。
- 原导入是libm.so的`cos(double)@PLT0xb67e4`、`sin(double)@PLT0xb67d8`，不是cosf/sinf。
  实参/返回走core-register DOUBLE AAPCS；两次传入同一外调前angle快照。
- cos返回先转float32，再调sin。sin后才读x/y；两个x VMLA在sin返回值转float32之前执行。
  几何尺寸、trim、scale与rotation在外调前缓存；不因回调改变记录而重算。
- 只写offset[8]，保留原X列0/2/4/6与Y列1/3/5/7的算术/写入交错；不改UV和其它字段。
- 原方法没有canary。只对该方法的首次声明保留no_stack_protector，未全局关闭套件强保护。
  实测cos provider改变global guard后，方法仍返回，调用方随即恢复guard。
- path非NULL才调用strlen/分配/strcpy；先发布owned_10再copy，不free旧path。
  color可缺省；存在时按0/1/2/3调用原s0-return toColor，短串保留原-1结果。
- updateOffset之后才重读parser.loader并configure，不能在math回调前缓存loader。

## 最终实跑

    python -B reconstruction/reverse-v1/c/spine_region_geometry/tools/check_region.py --so /path/to/libyoyo.so --out /new/exclusive/output

最终回执：`~/.hermes/reports/cally-region-20261108/run-03/receipt.json`。
SHA256 `293f6c1f47fc1a1640f5ab57879cae565754fd7ebd7d2f17fc459646d3da964c`。
O0/O2/O3/UBSan-trap各14项，19个语义变异均由预先登记的具名用例拒绝。
四个编译拒绝门：缺updateOffset本体、缺cos/sin imports、软件浮点、hardfloat PCS。
32项源码/头/夹具/checker绑定在执行前后无漂移；各执行二进制SHA及编译命令已登记。

逐配置解码重建ELF精确方法范围与$a/$d映射，算术原语数量与原件一致：
6 signed-VCVT、2 VDIV、9 VMUL、2 VNMUL、8 VMLA、1 widen、2 narrow、4 VSUB、4 VADD。
这证明检查到的opcode类别/数量，不独自证明操作数或全部语义；操作数/边界另由原字节推导、具名向量及静态复核负责。

libm在fixture里返回明确预置double值，用于隔离调用ABI/转换顺序/几何运算；这些不是原版运行输出，
也不是对真实libm三角算法的恢复或正确性认证。最近舍入、FZ/DN/trap关闭的声明域内有FPSCR断言，
不外推全部舍入模式、trap时序、NaN payload或硬件行为。

首个smoke缺工厂其它类型分支引用的sprintf，已补严格拒绝型fixture provider：有效type0不得走到它。
首轮矩阵的double乘法变异因widen不再使用被Werror拒编，未计为语义击杀；保留原widen读取后，
重新编译并由精确double参数断言拒绝。最终回执不是这两份失败记录。

linked四档15项/17变异、mesh四档16项/16变异、native-spine旧链与索引/卡门已重验。
独立只读静态复核无阻塞发现，父级核对四份冻结源/头SHA，并独立从PLT指令回解GOT槽与JUMP_SLOT名称；
见 `~/.hermes/reports/cally-region-20261108/static-review.json`。
原块末尾分支是回到0x28cc68；C helper返回是装配接口，不能据此宣称公共外循环已经等价接通。

## 未闭合

这是局部几何数据和重建消费者的交付，不是已显示sprite或完整游戏能力。
公共skin/slot外循环、events/animations、完整readSkeletonData与真实_readFile仍缺；
原有slots blend枚举F1、多余NULL返回F4及console构造缺口不因本批绿灯而消失。
原件同输入对照、任意坏指针/故障PC、异步观察与完整FPSCR矩阵未认证。
