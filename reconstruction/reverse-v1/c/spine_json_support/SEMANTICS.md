# Spine 错误处理与 Json 释放合同

原件 libyoyo ARM32 SHA256：
`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
层级 bytecode_anchored；原件只读，没有原件执行/ART/Unicorn。本体与源/头哈希见两个模块functions.json。

## 方法与原生边界

- `_spSkeletonJson_setError@0x28b784`：200B（192B代码+8B池），四个核心寄存器参数。
- `spSkeletonJson_readSkeletonDataFile@0x28eb40`：120B（116B代码+4B池）。
- `Json_dispose@0x2872c8`：88B，无池。
- `ReportSpineError@0xc4404`：52B（44B代码+8B池）。

setError/filewrapper是修正既有本体，Json_dispose/Report是新恢复本体。四者均为候选，phase_complete=false，
不以合成provider通过替代全库/原版等价。

## setError完整调用次序

1. 取旧error并保存global canary，真实_free（NULL也转发）。
2. strcpy(buffer,message)。
3. 无条件strlen(message)，即使extra为NULL也调用。extra非NULL时，按ARM32回绕计算buffer+length，
   调用strncat(buffer+length,extra,255-length)，不是strncat(buffer,...)，也不是strlen(buffer)。
4. strlen(buffer)+1→_malloc(size,完整SkeletonJson.c路径tag,90)。发布error，再用malloc返回指针strcpy。
5. ReportSpineError(buffer)，然后可选Json_dispose(json)。
6. 最后global canary比较，失败走__stack_chk_fail。强制真实stack-protector-strong/global与disable_tail_calls，
   不能将检查移到最后Json_dispose之前；实际原栈帧偏移/溢出故障不在本轮认证范围。

完整tag为 `jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c`（原0x357b08），line90。
旧短tag spine_json_err和有条件strlen/错误strncat起点均已修正。

## 文件包装器

保留未初始化size槽（原件只分配sp+4，不写零）；有效测试provider会写out_size。
先检查size==0，再检查data==NULL；错误前缀是 `Unable to read skeleton file: `，含结尾空格。
size==0即使data非NULL也不free；成功先调loader，再free(data)，返回缓存结果。

_readFile@0x285cd8与完整readSkeletonData@0x28b84c仍是显式库内缺口，fixture只作合成输入边界，
不计方法恢复。_spUtil_readFile@0xbd83c只是一条跳转，不宣称已恢复真实I/O。
ReadSkeletonData外部声明与既有宿主接口统一为const char*文本参数。

## Json_dispose

每节点先读child，再缓存next；递归child后才重读string_value并free，再重读name并free，最后free节点，
继续缓存的next。NULL节点/字符串/名字的跳过路径保留。全部释放走真实恢复的_free，不加入额外观察调用。
任意循环图、畸形指针、故障PC与真实分配器释放后的内存可见性未认证。

## ReportSpineError与平台输入

    GOT0x3ed71c → &dbg_csol@0x3eb70c → &_dbg_csol@0x47a118
    对象vptr（Itanium address point）→ +0xc → DummyConsole::Output@0xc4390

GOT和指针槽均核R_ARM_RELATIVE，format是原0x330afc的 `Spine Error:%s\n`（实际含换行）。
目标符号 `_ZN12DummyConsole6OutputEPKcz` 中z表示变参；共享头使用
`void (*)(SpineErrorConsole *self,const char *format,...)`，传入唯一message参数在r2。
fixture用stdarg接收，不能将三固定形参的另一函数类型伪称同一C接口。
Report保留调用帧（disable_tail_calls放在首次声明），不是尾跳直接把上游LR交给sink。

support拥有原同名_dbg_csol/dbg_csol存储，fixture只安装具型object/vtable，不替换ReportSpineError。
全局构造器/vptr生产者尚未恢复；未初始化平台对象的精确故障不作等价承诺。
父级实际适配器在 `c/spine_linked_postpass/fixture/reporter_adapter.c`。

## 最终验收

独立错误套件：

    python -B reconstruction/reverse-v1/c/spine_json_support/tools/check_error.py --out /new/exclusive/output

最终回执：`~/.hermes/reports/cally-linked-postpass-20261108/error-final/receipt.json`。
O0/O2/O3/UBSan-minimal各25项，10个变异具名拒绝；记录构建后执行前BINDING、完整二进制哈希、
编译器发现的源码/头闭包与checker，结束时核无漂移。_readFile和loader provider仍明确为合成。

父级linked消费链另对错误路径的无条件strlen/strncat实参作具名检查，并在O0/O2/O3让
Json_dispose内的free回调改变canary，要求setError返回前由__stack_chk_fail拒绝；
关闭该方法栈保护的负控必须命中另一具名断言，避免单看exit1误认证。
见 `~/.hermes/reports/cally-linked-postpass-20261108/run-03/receipt.json`。
