# Atlas attachment 创建分派 + 生命周期链静态恢复（本批）

原件：`/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so`
sha256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`
（只读；本批没有执行/装载原件，没有 ART、Unicorn、游戏进程；只用 `llvm-objdump`、`llvm-readelf`、`llvm-nm`、`llvm-size` 读文件）

## 0. 父级接入状态与证据边界

本目录是父级修缮后的主树候选，不是子线原始工作目录。
原始子线报告与源码仍保留在 `~/cally-work/native-attachment-factory-20261102/`；其32项、源哈希与目标triple不得替代当前字节的验收。

当前构建入口为 `c/check-native-spine.sh`：Clang `--target=armv7a-none-eabi -march=armv7-a -marm -mfloat-abi=soft`。
factory正文单独使用 `-fstack-protector-strong -mstack-protector-guard=global`；夹具与其他模块不因该要求自动开启栈保护。
`_spAttachmentLoader_setUnknownTypeError` 禁止尾调用，保证 canary 检查仍在 `setError` 返回之后。
不能靠 `-D__SOFTFP__` 让 softfp 通过 soft-float 准入。

父级已接入的修缮：

- parser/factory共用 `../spine_atlas_layout.h` 的完整12/44/80字节 atlas/page/region；region +4是x，不是page指针。
- mesh包含真实 `spVertexAttachment` 基类子对象，非仅靠相同偏移强转另一种C结构体。
- `strlen(name)-1` 按u32回绕；字段的传统scale/colour等标签不认证其未恢复消费者中的语义角色。
- 手工销毁夹具改为完整bbox对象，避免把16字节base传给会读更远字段的具体销毁器。
- 夹具整型格式化覆盖INT32_MIN，IEEE比较器不再误判正负零；新增UV原始NaN/Inf/负零位模式检查。

父级实际执行：当前factory 35项合成依赖检查通过；生产构建入口的8个ARM32重建程序通过。
另做compiler-guard控制：改变外部canary后，保留保护的正文退出2并报告STACK SMASH；相同夹具配无保护正文退出99。
这两项是编译器保护路径控制，不计作原件语义变异或原件对拍。
旧两个raw-word读取器改为may_alias后，与HEAD基线的ARM32 `.text`逐字节相同。

独立审查F1已复现并由父级修缮：Clang在较早引用处已创建disposeAttachment符号，
仅在后来定义上写disable_tail_calls没有生效，生成BX尾跳。现在属性也放在首次声明；
同一真实回调探针修前LR在wrapper外，修后在wrapper内。新增构建内消费者模式和
精确ELF符号/LR检查器，旧对象仍正常返回但被具名CALL_FRAME拒绝；不是以崩溃杀变异。
其余十九本体的原始审查结论不因该控制差异直接作废；F1修缮差异复审现已通过。


记录位置：`~/.hermes/reports/cally-native-atlas-20261102/` 中的factory-ssp-receipt.json、raw-word-alias-proof.json、native-entry-r1.log。
当前19函数均保留 `phase_complete=false`；独立字节审查及F1窄修缮复审均已核销，原件/ART/Unicorn/GPU均未执行。
下文是逐函数静态数据流；“无（闭包内）”不是全库完成或原件运行等价结论。

## 1. 符号与分发事实

`.dynsym`（`llvm-readelf --dyn-syms`）直接给出本批符号、VA、size，全部 `GLOBAL FUNC`：

```
00284a08 428 _spAtlasAttachmentLoader_createAttachment
00284958 176 spAtlas_findRegion
00284c18 108 _spAttachment_init
00284c84  48 _spAttachment_deinit
00284cb4  20 spAttachment_dispose        （已由 spine_skeleton_data 批恢复，本批不重复定义）
00284d58  96 spAttachmentLoader_createAttachment
00284db8  28 spAttachmentLoader_configureAttachment
00284dd4  28 spAttachmentLoader_disposeAttachment
00284df0 120 _spAttachmentLoader_setError
00284e68 112 _spAttachmentLoader_setUnknownTypeError
00285ae0  24 _spBoundingBoxAttachment_dispose
00285af8  72 spBoundingBoxAttachment_create
0028747c  96 _spMeshAttachment_dispose
002874dc  92 spMeshAttachment_create
002876d4  32 _spPathAttachment_dispose
002876f4  72 spPathAttachment_create
00288f58 32 _spRegionAttachment_dispose
00288f78 100 spRegionAttachment_create
00288fdc 100 spRegionAttachment_setUVs
0028f62c  32 _spVertexAttachment_deinit
```

### 1.1 跳表（不是上游枚举表）

`_spAtlasAttachmentLoader_createAttachment` 入口：

```
284a18  cmp r2,#4
284a1c  addls pc,pc,r2,lsl #2      ; pc = 0x284a24
284a20  b 0x284b60                 ; 落空 / type>4 / 负数
284a24  b 0x284ae0                 ; type 0
284a28  b 0x284ad0                 ; type 1
284a2c  b 0x284a48                 ; type 2
284a30  b 0x284a48                 ; type 3
284a34  b 0x284a38                 ; type 4
284a38  mov r0,r3; bl 0x2876f4     ; path
```

所以真实分派是：

| type | 目标 | 证据 |
|---|---|---|
| 0 | region：`findRegion` + `spRegionAttachment_create` + `setUVs` + 几何字段 | 0x284ae0，跳表项 0x284a24 |
| 1 | `spBoundingBoxAttachment_create` | 0x284ad0，跳表项 0x284a28 |
| 2 | mesh：`findRegion` + `spMeshAttachment_create` + 字段拷贝 | 0x284a48，跳表项 0x284a2c |
| 3 | linked mesh：与 type 2 **同一分支**（构造出的 attachment->type=2） | 0x284a48，跳表项 0x284a30 |
| 4 | `spPathAttachment_create` | 0x284a38，跳表项 0x284a34 |
| 其它 | `_spAttachmentLoader_setUnknownTypeError(loader, type)`，返回 0 | 0x284a20 -> 0x284b60 |

这是从机器跳表和每个目标的实际调用体读出的映射；没有按上游 `spAttachmentType` 名称猜。`r1`（skin）在整个 428 B 内没有被读。

## 2. 32 位布局（字节钉死，头文件有 `_Static_assert`）

### 2.1 `spAttachment`：16 B

```
+0x00 char *name         _spAttachment_init 里 _malloc(strlen+1)+strcpy；deinit free
+0x04 int32_t type       构造器立即数 0/1/2/4；_spAttachment_init 最后写
+0x08 spAttachmentVtable*  _spAttachment_init 用 calloc(1,4,...:43) 单独分配
+0x0c spAttachmentLoader* _spAttachment_deinit 只做非空测试；本批所有写点都不写它
```

`spAttachmentVtable` 只有 1 个槽：`+0x00 void (*dispose)(spAttachment*)`。证据：
`spAttachment_dispose`（0x284cb4）`ldr r3,[r0,#8]; ldr r3,[r3]; blx r3`；
`_spAttachment_deinit`（0x284c84）`ldr r0,[r0,#0xc]; cmp; beq; mov r1,r4; bl 0x284dd4`。

### 2.2 构造器 calloc 字节

| 对象 | calloc | 文件串 | 行 | 构造器立即数 type |
|---|---|---|---|---|
| `spRegionAttachment` | `calloc(1,0x9c)` | `.../RegionAttachment.c` | 43 (0x2b) | 0 |
| `spBoundingBoxAttachment` | `calloc(1,0x24)` | `.../BoundingBoxAttachment.c` | 44 (0x2c) | 1 |
| `spMeshAttachment` | `calloc(1,0x94)` | `.../MeshAttachment.c` | 50 (0x32) | 2 |
| `spPathAttachment` | `calloc(1,0x34)` | `.../PathAttachment.c` | 45 (0x2d) | 4 |
| attachment vtable | `calloc(1,4)` | `.../Attachment.c` | 43 (0x2b) | — |
| name copy | `_malloc(len+1)` | `.../Attachment.c` | 46 (0x2e) | — |
| error1/error2 | `_malloc(len+1)` | `.../AttachmentLoader.c` | 91/92 (0x5b/0x5c) | — |

文件串原文（ELF `.rodata` 计算，非猜）：

```
jni/../jni/yoyo/../../../spine-c/src/spine/AtlasAttachmentLoader.c
jni/../jni/yoyo/../../../spine-c/src/spine/Attachment.c
jni/../jni/yoyo/../../../spine-c/src/spine/AttachmentLoader.c
jni/../jni/yoyo/../../../spine-c/src/spine/RegionAttachment.c
jni/../jni/yoyo/../../../spine-c/src/spine/BoundingBoxAttachment.c
jni/../jni/yoyo/../../../spine-c/src/spine/MeshAttachment.c
jni/../jni/yoyo/../../../spine-c/src/spine/PathAttachment.c
```

### 2.3 `spRegionAttachment` 0x9c

构造器写点：`+0x1c/+0x20 = 1.0f`，`+0x30/+0x34/+0x38/+0x3c = 1.0f`；`_spAttachment_init` 写 `+0x00/+0x04/+0x08`。
dispatcher region 分支写：`+0x40 = region`，`+0x44..+0x58` 六个 int32（region+0x24/0x28/0x0c/0x10/0x2c/0x30），`setUVs` 写 `+0x7c..+0x98`（8 个 4 B）。
dispose 释放 `+0x10`，再释放对象本身。`+0x10` 在构造器里保持 calloc 零；本批没有写它的路径，因此 atlas 创建的 region attachment 该槽为 NULL（dispose 对 NULL 调 `_free`，原件的 `_free` 转发到 libc free）。

### 2.4 `spMeshAttachment` 0x94

dispatcher mesh/linkedmesh 分支写：

```
+0x24 = region
+0x28 = region+0x24   +0x2c = region+0x28
+0x30 = region+0x0c   +0x34 = region+0x10
+0x38 = region+0x2c   +0x3c = region+0x30
+0x40 = region+0x14 (u)  +0x44 = +0x18 (v)
+0x48 = +0x1c (u2)       +0x4c = +0x20 (v2)
+0x50 = +0x38 (整数 rotate 标志)
```

构造器写 `+0x68/+0x6c/+0x70/+0x74 = 1.0f`。dispose 释放 `+0x54`、`+0x5c`；然后按 `+0x7c` 分支：非空（有 parent mesh，`spMeshAttachment_setParentMesh` 0x287654 写 `str r1,[r0,#0x7c]`）只做 `_spAttachment_deinit`；为空则 `_spVertexAttachment_deinit` 后再释放 `+0x58/+0x64/+0x88`；最后释放对象。`+0x14/+0x1c` 由 `_spVertexAttachment_deinit` 释放，角色未在本闭包内钉死，头文件用 `owned_14/owned_1c`。

### 2.5 `spBoundingBoxAttachment` 0x24 / `spPathAttachment` 0x34

两者都以 `spVertexAttachment`（0x20 B，`+0x14/+0x1c` 两个 owned 指针）为前缀：
bbox 多 4 B `+0x20`；path 多 `+0x20/+0x24` 与 `+0x28`（dispose 释放 `+0x28`）。
`spVertexAttachment` 没有 init 体：构造器直接 `_spAttachment_init`，依赖 calloc 把 `+0x14/+0x1c` 清零。

### 2.6 `spAtlas` / `spAtlasRegion` 本闭包消费的槽

`findRegion` 只读 `atlas+0x04`（链表头）与 `region+0x00`（name）、`region+0x4c`（next）。
dispatcher 读 `region+0x0c/0x10/0x14/0x18/0x1c/0x20/0x24/0x28/0x2c/0x30/0x38`。
其余槽（0x08、0x34、0x3c..0x48）本批没有读写，头文件标 `opaque_NN`，不猜。

## 3. 逐函数

### 3.1 `_spAtlasAttachmentLoader_createAttachment` — 0x284a08 / 428 B

ABI：`spAttachment *f(loader r0, skin r1, type r2, name r3, path [sp])`；AAPCS32，第 5 参在入口 `[sp]`。`push {r4,r5,r6,r7,r8,lr}` + `sub sp,#8` 后 path 在 `[sp,#0x20]`（0x284a4c、0x284ae4、0x284b98 都是 `ldr r1,[sp,#0x20]`）。

全部路径：
1. type 0（0x284ae0）：`findRegion(loader->atlas, path)`；NULL -> `setError(loader,"Region not found: ",path)`，返回 0；否则 `create(name)`，`+0x40=region`，`setUVs(region u,v,u2,v2,region+0x38)`，写 `+0x44..+0x58`，返回 attachment。
2. type 1（0x284ad0）：`spBoundingBoxAttachment_create(name)`，直接返回。
3. type 2/3（0x284a48）：`findRegion`；NULL -> 同一 "Region not found: " 错误并返回 0；否则 `spMeshAttachment_create(name)`，写 `+0x24..+0x50`，返回。
4. type 4（0x284a38）：`spPathAttachment_create(name)`，返回。
5. 其它（0x284b60）：`setUnknownTypeError(loader, type)`，返回 0。

错误串只有一个：两条 `add r1,pc` 都落在 `0x357604 "Region not found: "`（0x284b80/0x284b88 与 0x284b9c/0x284ba4 的算术均已复核）。成功路径不清 error（清 error 是外层 `spAttachmentLoader_createAttachment` 的职责）。

已定：type→分支映射、五参 ABI、两处 region 查找、全部字段偏移、错误返回、skin 未用。
未知：无（函数体内没有未恢复调用）。

### 3.2 `spAtlas_findRegion` — 0x284958 / 176 B

ABI：`spAtlasRegion *f(const spAtlas *atlas r0, const char *name r1)`。

```
region = atlas->regions (+4)
while (region) {
    if (strcmp(region->name, name)==0) return region;      // 全路径优先
    if (name) {
        i = strlen(name)-1;
        if (i>=0 && name[i] != '/') {
            scan i downward for '/';                       // 只扫 len-2..0
            if found && strcmp(region->name, name+i+1)==0) return region;
        }
    }
    region = region->next;                                  // +0x4c
}
return 0;
```

细节：`name` 的 NULL 检查在第一次 `strcmp` **之后**（0x284984），所以 name=NULL 时原函数会在 strcmp 先崩；本实现保留同样顺序。末尾字符是 `/` 时不做 basename 匹配（0x2849a0/0x2849ac）；空串/无斜杠走 0x2849bc 的递减退出。`strlen` 0xb6538、`strcmp` 0xb6574 是 PLT 导入。

已定：链表偏移、全路径/基名两轮比较、边界空串/末尾斜杠、返回 0。
未知：无。

### 3.3 `spRegionAttachment_create` — 0x288f78 / 100 B

ABI：`spRegionAttachment *f(const char *name r0)`。

顺序：`calloc(1,0x9c,".../RegionAttachment.c",43)`（无 NULL 检查）→ 六个 `1.0f`（+0x1c,+0x20,+0x30,+0x34,+0x38,+0x3c）→ `_spAttachment_init(self,name,0,_spRegionAttachment_dispose)` → 返回 self。
dispose 地址来自 GOT `0x3f1910 -> 0x288f58`（`R_ARM_RELATIVE`）；C 里直接取函数地址等价。

已定：size、行号、六个 1.0 写点、type=0、dispose 目标。
未知：+0x10 的字符串身份（dispose 只证明它是 owned 指针；atlas 路径不写它）。

### 3.4 `spRegionAttachment_setUVs` — 0x288fdc / 100 B

ABI：`void f(self r0, u r1, v r2, u2 r3, v2 [sp], rotate [sp+4])`；第 6 参按非零整数判断。

```
rotate==0: uvs = {u, v2, u, v, u2, v, u2, v2}
rotate!=0: uvs = {u2, v2, u, v2, u, v, u2, v}
```

写点 `+0x7c..+0x98`。这是 dispatcher 直接调用的函数，必须在本批；其两条路径全部保留。

### 3.5 `spBoundingBoxAttachment_create` — 0x285af8 / 72 B

`calloc(1,0x24,".../BoundingBoxAttachment.c",44)` → `_spAttachment_init(self,name,1,_spBoundingBoxAttachment_dispose)` → self。无其它写点、无检查。

### 3.6 `spMeshAttachment_create` — 0x2874dc / 92 B

`calloc(1,0x94,".../MeshAttachment.c",50)` → `+0x68/+0x6c/+0x70/+0x74 = 1.0f` → `_spAttachment_init(self,name,2,_spMeshAttachment_dispose)` → self。

### 3.7 `spPathAttachment_create` — 0x2876f4 / 72 B

`calloc(1,0x34,".../PathAttachment.c",45)` → `_spAttachment_init(self,name,4,_spPathAttachment_dispose)` → self。

### 3.8 `_spAttachment_init` — 0x284c18 / 108 B

ABI：`void f(self r0, name r1, type r2, dispose r3)`。

```
vtable = _calloc(1,4,".../Attachment.c",43)
self->+8 = vtable
vtable->+0 = dispose
self->+0 = _malloc(strlen(name)+1,".../Attachment.c",46)
strcpy(self->+0, name)
self->+4 = type
```

`+0x0c` 不写。无 NULL 检查、无分配失败检查。注意 store 顺序：vtable/`self+8` 在 strlen 之前；`self+0` 在 strcpy 之前；`self+4` 最后。

### 3.9 `_spAttachment_deinit` — 0x284c84 / 48 B

```
if (self->+0x0c != 0) spAttachmentLoader_disposeAttachment(self->+0x0c, self);
_free(self->+0x08);
_free(self->+0x00);      // 原件是 tail b _free
```

只测 NULL；不测 vtable/name；不清字段；不释放 self。`+0xc` 的写入点不在本闭包内，因此 atlas 直接创建的 attachment 不会进入 disposeAttachment 回调。

### 3.10 `_spAttachmentLoader_setError` — 0x284df0 / 120 B

```
_free(self->+0x00);
_free(self->+0x04);
self->+0x00 = _malloc(strlen(error1)+1,".../AttachmentLoader.c",91);
strcpy(self->+0x00,error1);
self->+0x04 = _malloc(strlen(error2)+1,".../AttachmentLoader.c",92);
strcpy(self->+0x04,error2);
```

两次 free 都在两次 malloc 之前；槽不先置空；分配失败不检查。错误串是堆拷贝，不是借用指针。

### 3.11 `_spAttachmentLoader_setUnknownTypeError` — 0x284e68 / 112 B

```
char buffer[16];
sprintf(buffer,"%d",type);
_spAttachmentLoader_setError(self,"Unknown attachment type: ",buffer);
```

原件有栈保护：`sub sp,#0x18`，buffer `sp+4..sp+0x13`，canary `sp+0x14`，guard 经 GOT `0x3ed958` 读；本批对象用 `-fstack-protector-strong -mstack-protector-guard=global` 复现同尺寸帧（反汇编可见 `sub sp,#0x18`、canary 存 `[sp,#0x14]`、`__stack_chk_fail` 调用）。`"%d"` 在 0x332514；错误前缀在 0x3576d4。

### 3.12 `spAttachmentLoader_createAttachment` — 0x284d58 / 96 B

ABI 与 vtable 槽一致：`spAttachment *f(loader r0, skin r1, type r2, name r3, path [sp])`。

```
_free(loader->error1);  _free(loader->error2);
loader->error1 = 0;     loader->error2 = 0;
return loader->vtable->createAttachment(loader,skin,type,name,path);
```

错误槽在间接调用**之前**清空；槽指针不测 NULL。原件保留帧（`push {r4,r5,r6,r7,r8,lr}` + `sub sp,#8`，`blx` 后 `add sp; pop`），本实现用 `disable_tail_calls` 保持同一调用边界。

### 3.13 `spAttachmentLoader_configureAttachment` / `disposeAttachment` — 0x284db8 / 0x284dd4，各 28 B

```
fn = loader->vtable->+0x04 / +0x08;
if (fn) fn(loader, attachment);
```

两个槽都做 NULL 测试；空槽直接返回。`disposeAttachment` 是 `_spAttachment_deinit` 的调用目标。

### 3.14 `_spRegionAttachment_dispose` — 0x288f58 / 32 B

`_spAttachment_deinit(self)` → `_free(self->+0x10)` → `_free(self)`（尾调用）。

### 3.15 `_spBoundingBoxAttachment_dispose` — 0x285ae0 / 24 B

`_spVertexAttachment_deinit(self)` → `_free(self)`。

### 3.16 `_spPathAttachment_dispose` — 0x2876d4 / 32 B

`_spVertexAttachment_deinit(self)` → `_free(self->+0x28)` → `_free(self)`。

### 3.17 `_spMeshAttachment_dispose` — 0x28747c / 96 B

```
_free(self->+0x54); _free(self->+0x5c);
if (self->+0x7c != 0) { _spAttachment_deinit(self); }
else { _spVertexAttachment_deinit(self); _free(+0x58); _free(+0x64); _free(+0x88); }
_free(self);
```

`+0x7c` 是 parent-mesh 槽（0x287654 `str r1,[r0,#0x7c]`），不是类型标签。父链存在时数组共享，所以只做基类 deinit。

### 3.18 `_spVertexAttachment_deinit` — 0x28f62c / 32 B

`_spAttachment_deinit(self)` → `_free(self->+0x14)` → `_free(self->+0x1c)`（尾调用）。无 init 体；依赖 calloc 清零。

### 3.19 `spAttachment_dispose` — 0x284cb4 / 20 B（外部，已有）

已由主树 `c/spine_skeleton_data/src/spine_skeleton_data.c` 恢复（`vtable=self+8; fn=[vtable]; fn(self)`）。本批**不重复定义**，fixture 直接链接该文件验证真实行为；避免集成时重复符号。

## 4. 每函数已定/未知

| 函数 | 已定 | 未知 / 明确 gap |
|---|---|---|
| `_spAtlasAttachmentLoader_createAttachment` | 五参 ABI；跳表 0/1/2/3/4/其它；两个 region 查找；错误串；全部写点；skin 未读 | 无（闭包内） |
| `spAtlas_findRegion` | 链表 +0x4c、name +0、全路径/基名两轮、空串/末尾斜杠 | `spAtlas` 其它字段语义（本函数不读） |
| `spRegionAttachment_create` | 0x9c、行 43、六个 1.0f、type 0、dispose | `+0x10` 具体字符串身份；`+0x14/0x18/0x24/0x28/0x2c` 语义角色（本闭包不读写，仅按 4 B 占位） |
| `spRegionAttachment_setUVs` | 6 参、两条 UV 顺序、+0x7c..+0x98 | 无 |
| `spBoundingBoxAttachment_create` | 0x24、行 44、type 1 | `+0x20` 及 vertex 区角色未在本闭包出现 |
| `spMeshAttachment_create` | 0x94、行 50、四个 1.0f、type 2 | `+0x10/+0x18/+0x20/+0x60/+0x78/+0x80/+0x84/+0x8c/+0x90` 语义（本闭包不读写） |
| `spPathAttachment_create` | 0x34、行 45、type 4 | `+0x20/+0x24/+0x2c/+0x30` 语义 |
| `_spAttachment_init` | vtable 4 B、+8/+0/+4 写序、行 43/46 | `+0xc` 的写者不在本闭包（deinit 只读） |
| `_spAttachment_deinit` | 判 +0xc、调用槽 +8、free +8/+0 顺序 | `+0xc` 由谁写未定 |
| `_spAttachmentLoader_setError` | 双 free→双 malloc/strcpy、行 91/92 | 无 |
| `_spAttachmentLoader_setUnknownTypeError` | buffer[16]、sprintf "%d"、前缀串、canary 帧 | 无 |
| `spAttachmentLoader_createAttachment` | 双 error 清空后派发、5 参转发、无 NULL 槽检查 | 无 |
| `configureAttachment`/`disposeAttachment` | 槽 +4/+8、NULL 测试 | 无 |
| `_spRegionAttachment_dispose` | deinit→free +0x10→free self | +0x10 的语义名 |
| `_spBoundingBoxAttachment_dispose` | vertex deinit→free self | 无 |
| `_spPathAttachment_dispose` | vertex deinit→free +0x28→free self | +0x28 的语义名 |
| `_spMeshAttachment_dispose` | +0x54/+0x5c 先 free；+0x7c 父链分支；+0x58/+0x64/+0x88 条件 free | 这些 owned 槽的具体语义 |
| `_spVertexAttachment_deinit` | base deinit→free +0x14→free +0x1c | +0x14/+0x1c 的语义名 |

## 5. 本批没有闭合的依赖（不冒充全库）

* `spAtlas_create`（0x284174 / 1824 B）、`spAtlasPage_create`（0x284058）、`spAtlasRegion_create`（0x2840d8）仍在冻结 JSON 中，属于 atlas 解析线，不在 createAttachment 的直接闭包内；本批未恢复。
* `spRegionAttachment_updateOffset`（0x289040）、`spRegionAttachment_computeWorldVertices`（0x289174）、`spMeshAttachment_updateUVs`/`setParentMesh`、`spVertexAttachment_computeWorldVertices*` 等消费者未恢复；本批只用 `setParentMesh` 的写点证明 mesh `+0x7c` 是 parent 槽。
* `spAttachment` `+0x0c`（loader 槽）在本闭包内没有写者；`_spAttachment_deinit` 的 disposeAttachment 分支只能由本闭包外的代码触发（fixture 手工写入以验证该分支）。
* 所有 `opaque_*`/`owned_*` 槽都只钉了宽度/偏移/所有权，没有按上游结构名反推语义。
* libc 导入：`strlen`、`strcpy`、`strcmp`、`sprintf`；分配器导入：`_malloc`、`_calloc`、`_free`（来自只读 `spine_alloc.h`，本批没有复制/重定义）。
* 本批不是全库完成；只覆盖 createAttachment 及其直接闭包 + attachment 生命周期链中此前未恢复的库内本体。`spAtlasAttachmentLoader_create`、`_spAttachmentLoader_init/deinit`、`spAttachmentLoader_dispose` 属于前批，未在本批重复。
