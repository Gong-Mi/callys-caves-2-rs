# spine allocation 六入口：逐函数静态合同

原件 SHA256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
原件未执行。原始逐字节解码位于父级冻结的 allocation-original.json；本体每条分支/读写
均在 src/spine_alloc.c 标 VA。原子/并发、完整调用图和全库闭合不由本模块认证。

| 入口 | VA/字节 | ABI与完整局部行为 |
|---|---|---|
| _malloc | 0x285c10/60 | (u32 size,tag*,u32 line)→ptr；先读debug，非零直接调并返回；否则才读普通槽并调用 |
| _calloc | 0x285c4c/52 | (u32 n,u32 size,tag*,u32 line)→ptr；乘积低32位回绕→_malloc；非NULL才memset；返回保存的ptr |
| _free | 0x285c80/28 | (ptr)→void；无条件读free槽并转发，包括ptr=NULL；不检查debug |
| _setDebugMalloc | 0x285c9c/20 | 一个回调地址写debug槽，无检查、无旧值返回 |
| _setMalloc | 0x285cb0/20 | 一个回调地址写普通槽，无检查，允许存零 |
| _setFree | 0x285cc4/20 | 一个free回调写free槽，无检查，允许存零 |

原件全局与初态（已从ELF直接复核）：

- 0x3f7790：4字节普通malloc地址，文件字为0，R_ARM_ABS32→导入malloc，addend=0。
- 0x3f7794：4字节free地址，同型重定位→导入free；与普通malloc槽相邻，偏移+4。
- 0x756bc4：独立4字节debug槽，NOBITS装载初值0，setter写它。
- 字面量@285c44/48/98/ac/c0/d4 是数据，不是正文指令。

普通槽的一个重要类型边界：初值是单参 libc malloc，原指令却仍把tag/line留在r1/r2。
不能将libc函数强转成三参C函数指针再调用并把关闭警告当作正确性证明。
父级保留槽里的真实4字节地址、初值重定位和setter行为，用内联AAPCS32 BLX边界保持
r0/r1/r2；libc声明仍为单参，注册回调按线级三寄存器合同定界。
该边界只负责调用ABI，不是地址解析器、弱符号或原始VA兜底；不计为新增原件函数。
_malloc保留独立调用边界，debug三参回调本身使用匹配的C类型。

calloc没有乘法溢出拒绝、没有total!=0短路；total=0且ptr非NULL时仍调用memset(ptr,0,0)。
默认槽或free槽被setter改为零后调用会进入无效回调域；本体不添加原件没有的防护。

## 验证与证据边界

fixture/check.c 是一份ARM32合成provider检查：23个具名断言，覆盖初态、默认/Debug派发、
元数据传递、乘积回绕、NULL/零长清零、free(NULL)与setter存零。父级在接入修缮后重新编译
并用qemu-arm运行，非只接受子线报告；完整argv及源码/产物哈希见父级回执。

库外malloc/free/memset保留为明确导入。六入口的调用/字段合同不认证导入库本体、外部
注册者的行为或完整库调用可达性。子线PC-add引用扫描只属于其已扫描寻址形式；本模块不采用
“绝无其他写者/绝无其他调用者”的全局否定结论。完整库尚未逆向完成。

复审补充：构建入口固定Clang/ARM32 soft-float，头文件拒绝非Clang、缺少disable_tail_calls
或非soft-float的目标，不能把已验收的调用帧结论移用到GCC/硬浮点。普通槽保持原始代码字
是ABI表示，不是安全校验；公开_setMalloc仍有三参C回调类型，父级实测单参函数直接传入
会在-Werror下编译拒绝。强转或直接伪造槽地址属于原版未校验的输入域，不承诺自动防错。
