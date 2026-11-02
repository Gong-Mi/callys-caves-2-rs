# Atlas 解析：父级修缮后的原生 C 候选

样本 SHA256：3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a。
本轮只读原 ELF，未执行/加载原件、ART、Unicorn 或游戏。
原始两份子线产物留在 ~/cally-work/native-atlas-parser-20261102/ 和
~/cally-work/native-atlas-helper-repair-20261102/；其报告不认证当前正文。

## 原件身份与 ABI

| 入口 | 范围字节 | 参数/结果 |
| --- | ---: | --- |
| spAtlas_create 0x284174 | 1824 | r0=data,r1=i32 length,r2=dir,r3=renderer；r0=atlas/0/故障 |
| spAtlasPage_create 0x284058 | 96 | r0=atlas,r1=name；r0=page |
| spAtlasRegion_create 0x2840d8 | 28 | 无参数；r0=region |
| helper@0x283d14，角色 trim | 212 | r0=8B Str，原位写；调用者不消费返回寄存器 |
| helper@0x283de8，角色 readLine | 148 | r0=cursor首字槽地址,r1=end,r2=out Str；r0=0/1 |
| helper@0x283e7c，角色 readValue | 84 | 同上，Str为输入输出；r0=0/1或故障 |
| helper@0x283ed0，角色 readTuple | 248 | r0=cursor槽地址,r1=end,r2=四个Str；r0=0..4或故障 |
| helper@0x283fc8，角色 mallocString | 72 | r0=Str；r0=memcpy返回的指针 |
| helper@0x284010，角色 indexOf | 72 | 只有两个参数：r0=8项表,r1=Str；r0=0..7 |

六个helper没有dynsym名字；上表名称是已恢复的角色标签，不伪造原符号。
入口由直接bl和相邻真实入口/返回/字面量池共同约束，范围字节不全是指令。
Str为begin指针+可变char* end，两槽各4B。toInt把原end槽地址交给strtol，
不以临时变量或char**/const char**类型双关代替。
共同atlas/page/region布局只来自 ../spine_atlas_layout.h，分别12/44/80字节。

## 已驳回：扫描器条件码与 EOF

两份子线都把CMP后的ADD当成更新条件码，导致“最后有效字节不比较”的错误。
修缮子线更声称空区间不读取；该结论和对应host selfcheck不能接收。

原件0x283ea0 CMP -> ea4 MOV -> ea8 LDRB -> eac ADD -> eb0 BNE，
只有CMP设置NZCV，后三条非S指令不改标志。0x283f08..f18和f54..f64同构。
故循环是：先保存k!=end+1的判断，始终读取*(k-1)，k自增，再用旧判断分支。
所有有效字节均参与delimiter比较；未命中时额外读取*end并丢弃。
空区间也读取一次；readTuple的局部Str被清零，EOF因此可以读取0地址并故障。
正文用小型ARM32 LDRB原语保留此读取，不用C的NULL解引用UB或额外安全判断代替。

parent-falsifiers中的late_flag_test只使具名最后delimiter用例失败；
skip_terminal_load使本应SIGSEGV的EOF探针返回99，单列为故障形状控制，
不计原件差分或普通语义变异。

## 逐函数控制、字段与全局

- trim：0x283d24缓存一次_ctype_指针；d28先读begin，d2c再取end。
  原始字节与分类字节均按LDRB读；仅测试table[c+1]&8，不硬编码host分类。
  前向每轮先写begin再读下一字节，可能读取逻辑end；相等即返回。
  后向保留中间end写、无符号边界与逐字节次序。原生不初始化的槽不偷偷清零。
- readLine：EOF不写out；写out.begin后重读cursor，trim后再次重读cursor。
  行末LF不属于Str区间；cursor跳过LF，但已等于end时不推进。
- readValue：不判断readLine结果，所以EOF可能继续消费陈旧Str。
- readTuple：仅初始化自己的局部Str为0，不清调用方四格。非末字段end=comma-1；
  第四字段直接用剩余区间。仅写已返回的格，保留陈旧/未初始化槽的原始字。
  Str取值使用单字LDR原语，避免将原件未初始化字读取变成LLVM pointer poison。
  未初始化字仍是隐式初态，未声称译文栈字节等于任一原版运行现场。
- mallocString：长度在分配前按u32差冻结；分配后重取begin；使用memcpy实际返回值，
  再STRB写该返回基址+长度。失败不增加NULL检查。
- indexOf：原件r1直接解引用，根本不是count。固定倒扫8项，缓存begin/长度；
  strncmp(entry,begin,u32(end-begin))；0既表示第0项也表示未命中，空值会先匹配第7项。
- 两个初始格式/过滤表位于原件.data 0x3f7750/0x3f7770，各8个R_ARM_RELATIVE槽。
  已逐槽读原字/串核对。译文保留可写、逐槽可观测加载，不改成不可变rodata常量表。
- Page_create深拷贝name，calloc44行37、name行39；Region_create calloc80行52。
- Atlas_create calloc12行182；按位置而非字段名解析。可选页size由tuple计数2判定；
  format/filter均为前缀匹配；repeat的none/x/y/xy比较也保留原长度规则。
  rotate也是strncmp前缀语义，空值可匹配true，不能写成“只有完整true接受”。
  region链、page链、split/pad可选16B数组、orig/offset/index和未检查的返回值保持原顺序。
- path在行190分配。部分abort在path尚未发布/释放时直接清理atlas，仍会泄漏path；
  译文和具名消费者保留该原件行为，没有安全化补free。

## 数值与 FPSCR

原件0x284368..0x2843d8/0x284490..0x2844b4使用有符号i32转F32与VDIV。
两个整数和先u32回绕再解释i32，不能用C signed-overflow或先转float相加。
原件首次VDIV之后才写region.height；普通分支V2计算/写入先于U2，旋转分支相反。
正文按这些顺序恢复，少量显式VCVT/VDIV原语在真实soft调用ABI下使用VFPv3-D16；
不伪造__SOFTFP__，不以软件默认最近舍入代替，也不归一化生产FPSCR。
qemu运行重建C核过nearest、toward-zero、inexact与divide-by-zero累计标志；
换成真实compiler-rt软件除法的控制只被对应三个具名用例拒绝。
这仍不是原件对拍、真机FPU或全trap组合认证。

## 真实构建/消费者与证据边界

入口 ../check-native-spine.sh 已实际构建运行8个ARM32重建程序。
本模块helper/数值16项、text->Atlas->真实五路attachment->真实销毁37项均通过，
所有用例ID唯一；factory另有35项。另核page尺寸在provider填默认值前已发布：
删除width写回的相同错误正文过旧35项、被新37项仅以具名转发断言拒绝。
图形仅是有名provider，无真实GPU创建。
新atlas_parse_chain不使用原有native_chain的合成atlas接口；两条证据不能混报。
执行日志、具名控制和源哈希位于 ~/.hermes/reports/cally-native-atlas-20261102/。

## 尚未闭合

_spAtlasPage_createTexture@0xbd6e4/304B是库内未恢复方法，不是永久库外依赖；
当前provider只验证page/path/尺寸/整数id接口。真实JSON解析、owner字段生产者、
其它attachment/timeline/renderer消费者与全库匿名边界仍未闭合。
库外libc和_ctype_表的实现/现场内容没有被本批恢复或认证。
九入口已过独立逐函数静态字节审查，且审查的正文/ABI头与当前字节一致；
编译与消费者证据由父级native-entry-r5另行绑定，不混作审查人的运行结论。
九入口仍保留phase_complete=false，原件运行等价和全库完成率均不主张。
