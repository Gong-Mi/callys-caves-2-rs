# attachment-loader 四入口：静态合同与接入边界

样本 SHA256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
原件未加载/执行。原始字节、符号和解码已冻结在父级 attachment-original.json。

| 入口 | VA/字节 | ABI、完整局部顺序 |
|---|---|---|
| spAtlasAttachmentLoader_create | 0x284bb4/100 | (spAtlas*)→spAttachmentLoader*；calloc(1,16,tag,93)→init(self,deinit,create,0,0)→写atlas@+0xc→返回self |
| _spAttachmentLoader_init | 0x284cc8/76 | (self,dispose,create,configure,disposeAttachment[栈])；calloc(1,16,tag,51)；先发布self+8，再按+0xc,+0,+4,+8写vtable |
| _spAttachmentLoader_deinit | 0x284d14/36 | (self)→void；free(+8)，重新读free(+0)，再次读free(+4)，不清字段 |
| spAttachmentLoader_dispose | 0x284d38/32 | (self)→void；无条件取vtable+0xc调(self)，然后free(self)；不另外free(vtable) |

四个本体均无数据条件分支或NULL防护。init的第五参在保存24字节寄存器后从sp+0x18读取。
返回时r0的残留不是void函数的业务返回合同。调用/尾调用的物理形状与逻辑合同分开记。

## 字段与函数指针

loader共16字节：+0/+4为拥有的错误字段，+8是独立vtable指针，+0xc为atlas指针。
vtable也是16字节：+0=create(loader,skin,type,name,path)，+4=configure(loader,attachment)，
+8=disposeAttachment(loader,attachment)，+0xc=dispose(loader)。
五参形状由0x284d58的转发与0x284a08的消费者共同确定；不因skin在某体未读就删参数。

tag逐字节来自原件：

- create：0x357618 的 jni/../jni/yoyo/../../../spine-c/src/spine/AtlasAttachmentLoader.c，行93。
- init：0x357694 的 jni/../jni/yoyo/../../../spine-c/src/spine/AttachmentLoader.c，行51。

GOT 0x3f18fc 以R_ARM_RELATIVE指向deinit@0x284d14；0x3f1900指向
_spAtlasAttachmentLoader_createAttachment@0x284a08。取函数地址对应同一静态符号合同，
但不是保持原版VA/ASLR的承诺。不能凭这两处命中推出全库绝无其它间接调用者。

父级接入时统一了JSON调用者与本实现的spAttachmentLoader*类型；没有以“指针同宽”
放行互不相容的C声明。self+8发布和四槽写入均用volatile访问保持源级次序；deinit两错误
字段在前一个free之后重读。init不改self的+0/+4/+0xc，create只在init返回后改+0xc。
该顺序忠实保留原件先发布表指针再填槽的行为，不认证多线程初始化安全或“表已就绪”；
本轮不擅自改成原子发布、重排写入或增加锁。

## 验证与缺口

fixture/check.c在ARM32编译与qemu-arm下有15个具名检查，包含实际vtable派发与free(error1)
回调改写error2后的重读。父级修缮后重新编译运行；缺少allocator或createAttachment符号
必须链接失败，不使用weak、静默成功或原VA替代。

_calloc/_free的本体来自同批allocation模块，不再作为恢复工程的永久空实现。
_spAtlasAttachmentLoader_createAttachment@0x284a08/428B仍是明确的库内本体缺口；生命周期
只取其地址，夹具要求它不被执行。Atlas/JSON实际解析、具体Attachment构造与完整对象图
也未因此恢复。四个C本体和合成检查不代表全库静态闭合或原版等价。
