# spine_mesh — spMeshAttachment_updateUVs / spMeshAttachment_setParentMesh

样本：`/data/data/com.termux/files/home/cally-oracle/libyoyo.so`
SHA256：`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`
层级：`bytecode_anchored`。本批未执行原件，不报原版等价。

| 函数 | VA | ISA | .dynsym size | 代码区间 | 指令 | 代码 sha256 | 含池 body sha256 |
|---|---|---|---|---|---|---|---|
| `spMeshAttachment_updateUVs` | `0x287538` | ARM（bit0=0） | 280 | `0x287538..0x28764c`（276 B） | 69 | `ede322ba7cdb26f6c85d99dde4e800097779e67528f9bc233a730109d355d4d8` | `ef93e5c25c8a74774304115e40e7290eac577bbda9683eb3438ae2884fab2696` |
| `spMeshAttachment_setParentMesh` | `0x287654` | ARM（bit0=0） | 128 | `0x287654..0x2876d4`（128 B） | 32 | `d7233033a5457e501dc029c1844ed477108b322d44e8afbd7ffcaf3c35f89557` | 同左 |

`updateUVs` 的 280 B 末尾 4 B 是 literal pool：`0x28764c = 0x000d038c`
（`0x287568 ldr r1,[pc,#0xdc]` → `0x28764c`；`0x287574 add r1,pc,r1`，
PC=0x28757c，得 `0x357908`，即 `.rodata` 中的
`"jni/../jni/yoyo/../../../spine-c/src/spine/MeshAttachment.c"`，逐字节核对）。
分配行号是 64（`0x287570 mov r2,#0x40`）。下一入口 `0x287650` 是 4 B thunk
（`b 0x28fa08 <spVertexAttachment_computeWorldVertices>`），不属于本函数。

边界证据：`0x287538 push {r3,r4,r5,lr}` / `vpush {d8}`；两条返回块
`0x2875e4 vpop {d8}; 0x2875e8 pop {r3,r4,r5,pc}` 与 `0x287644/0x287648`；
`0x2875ec` 是 rotate 分支入口；`0x287640 bne 0x287610` 是第二循环回边。
`setParentMesh`：`0x287654 cmp r1,#0`（store 前）、`0x287658 str r1,[r0,#0x7c]`、
`0x28765c push {r4..r11}`、`0x287660 beq 0x2876cc`、`0x2876d0 bx lr`；
下一符号 `_spPathAttachment_dispose` 起于 `0x2876d4`。

## 1. ABI

两个函数都是 `void`，ARM AAPCS32（softfp，浮点实参/返回走核心寄存器；本函数根本没有
浮点形参/返回值）。调用点核对：
`0x28cce8 bl setParentMesh`（`r0=[r4,#0xc]`，`r1=0x28ed00` 返回的父附件）、
`0x28ccf0 bl updateUVs`（`r0=[r4,#0xc]`）、`0x28d0c8 bl updateUVs`
（`r0=r6`，紧随 `_readVertices`，见 `0x28d0c0`）。

- `updateUVs(self)`：`r0` 唯一输入。返回时 `r0` 无合同值：原版留下 malloc 结果或
  已被 `+8/次` 推进的输出游标（`count<=0` 时就是新 `+0x5c` 指针）。
- `setParentMesh(self,parent)`：`r0=self`、`r1=parent`。原版全程不回写 `r0`，
  返回时 `r0==self` 只是副产物，不构成返回值合同。
- 两者都不保存/恢复 VFP 调用者寄存器以外的状态；原版 `updateUVs` 只 `vpush {d8}`
  （保住 s16/s17），译文由编译器按 AAPCS 保存实际使用的 callee-saved 寄存器；未据此声明运行等价。
- 回调 ABI：`_malloc(uint32 size r0, const char *tag r1, uint32 line r2)`；
  `_free(void *r0)`，NULL 也照传。两者都是可替换的 provider（`spine_alloc.h`）。

## 2. updateUVs 逐路径

### 2.1 第一层快照（全部在 `_free` 之前）

```
0x28753c vldr s15,[r0,#0x40]   u
0x287548 ldr  r5,[r0,#0x20]    worldVerticesLength（原文里就是 region-UV float 数）
0x28754c vldr s17,[r0,#0x48]   u2
0x287550 ldr  r0,[r0,#0x5c]    旧 output 数组指针
0x287554 vldr s16,[r4,#0x4c]   v2
0x287558 vsub.f32 s17,s17,s15  width = u2 - u
0x28755c vldr s15,[r4,#0x44]   v
0x287560 vsub.f32 s16,s16,s15  height = v2 - v
0x287564 bl   _free
```

这 5 个值 + 旧指针是 **free 前快照**：free provider 之后怎样改结构体都不影响
`width/height/count/尺寸`；循环中的 `u/v` 会重新读取；`u2/v2` 不再读取。

### 2.2 分配与第二层快照（`_malloc` 之后）

```
0x287568..0x287578  _malloc(r5<<2, "…/MeshAttachment.c", 64)
0x28757c ldr r3,[r4,#0x50]   rotate —— malloc 之后才读
0x287580 cmp r3,#0
0x287584 str r0,[r4,#0x5c]   新指针无条件先写回，count<=0 也写
0x287588 bne 0x2875ec
```

`r5<<2` 是 32 位 `lsl`：高位移出、按 2^32 回绕；`cmp r5,#0` 是 **有符号**判断。
`+0x58`（源 region-UV 数组）在 malloc 之后、循环初始化时才读
（`0x287598` / `0x2875f8`），`count<=0` 时根本不读。

### 2.3 普通路径（`rotate==0`，`0x28758c..0x2875e0`）

计数门：`count > 0`。`pairs=(count-1)>>1`；原循环将 `r3` 从 `src+4`
每次加8，与 `src+12+8*pairs` 比较，两端均按32位回绕。译文比较
`(i<<3)==(pairs<<3)` 保留字节地址的模32语义，不用无界整数迭代数替代。
在不回绕的有效地址域才可简记为 `ceil(count/2)` 次；极大域未动态执行。

每次迭代（严格按指令顺序）：

1. `x = src[2i]`（`0x2875b0 vldr s14,[r3,#-4]`）
2. `u_local = self->u`（`0x2875b4`，**每次重读**）
3. `u_out = vmla(u_local, width, x)`（`0x2875b8`；VFPv3 先舍入乘积再舍入累加）
4. `uvs[2i] = u_out`（`0x2875c8 vstr`）
5. **在写完之后**才读 `y = src[2i+1]`（`0x2875cc vldr s14,[r1]`）
6. `v_local = self->v`（`0x2875d0`，每次重读）
7. `v_out = vmla(v_local, height, y)`（`0x2875d4`）
8. `uvs[2i+1] = bits(v_out)`（`0x2875d8 vmov r1,s15; 0x2875dc str r1,[r0],#8`）

### 2.4 旋转路径（`rotate!=0`，`0x2875ec..0x287640`）

同样 `count>0`、同样模32字节终止比较。每次迭代：

1. `sv = src[2i+1]`（`0x287610 vldr s14,[r3]`）
2. `u_local = self->u`（`0x287614`，每次重读）
3. `u_out = vmla(u_local, width, sv)`（`0x287618`）
4. `uvs[2i] = u_out`（`0x287620 vstr`）
5. `base_v = self->v`（`0x287624`，写完之后重读）
6. `t = vadd(height, base_v)`（`0x287628`，操作数顺序是 s16+s15）
7. **在写完之后**才读 `su = src[2i]`（`0x28762c vldr s14,[r3,#-12]`，此时 r3 已 +8）
8. `v_out = vmls(t, height, su)`（`0x287634`；t - round(height*su)，再舍入结果，非融合）
9. `uvs[2i+1] = bits(v_out)`（`0x287638/0x28763c`）

注意旋转路径**不是** `v2 - u*height`：它用快照的 `height`，但 `base_v` 每次重读，
先做 `vadd(height, base_v)` 再做 `vmls`。两次舍入顺序是原版语义的一部分。

### 2.5 其它路径

- `count <= 0`：free → malloc → 写 `+0x5c` → 直接返回；不读 `+0x58`、不读写 UV。
- `count` 为奇数：循环 `ceil(count/2)` 次，最后一次会读 `src[count]`、写
  `uvs[count]`，越出 `count*4` 字节的分配 4 B。原版没有偶数校验，本译文也不加。
- `_malloc` 返回 NULL：照样写 `+0x5c`，`count>0` 时照样按上述地址写，在重建进程产生访存失败；精确 signal/PC 及 C/原件故障等价未认证。
- provider 返回与 `self` 或 `+0x58` 重叠的缓冲：所有 `uvs[...]` 写都用 `str`/`vstr`
  落在原位置，源的第二分量与 `self->u/self->v` 的重读点均在第一次写之后，因此重叠
  造成的可见性变化被保留。代码**没有** `restrict`，也没有把一对源 float 一次缓存。

## 3. setParentMesh 逐路径

```
0x287654 cmp r1,#0
0x287658 str r1,[r0,#0x7c]    parentMesh 无条件先写
0x287660 beq 0x2876cc         parent==NULL：只写 +0x7c，直接返回
```

`parent != NULL`：先把 13 个槽全部读进寄存器，再按原顺序写回 `self`：

| 读锚点 | 源偏移 | 写锚点 | 目标偏移 | canonical 名 |
|---|---|---|---|---|
| `0x287664` | `+0x20` | `0x28769c` | `+0x20` | `super.worldVerticesLength` |
| `0x287668` | `+0x8c` (vldr) | `0x287698` | `+0x8c` (vstr) | `opaque_8c` |
| `0x28766c` | `+0x14` | `0x2876a4` | `+0x14` | `super.owned_14` |
| `0x287670` | `+0x90` (vldr) | `0x2876a0` | `+0x90` (vstr) | `opaque_90` |
| `0x287674` | `+0x10` | `0x2876a8` | `+0x10` | `super.opaque_10` |
| `0x287678` | `+0x1c` | `0x2876ac` | `+0x1c` | `super.owned_1c` |
| `0x28767c` | `+0x18` | `0x2876b0` | `+0x18` | `super.opaque_18` |
| `0x287680` | `+0x58` | `0x2876b4` | `+0x58` | `owned_58` |
| `0x287684` | `+0x64` | `0x2876b8` | `+0x64` | `owned_64` |
| `0x287688` | `+0x60` | `0x2876bc` | `+0x60` | `opaque_60` |
| `0x28768c` | `+0x78` | `0x2876c0` | `+0x78` | `opaque_78` |
| `0x287690` | `+0x88` | `0x2876c4` | `+0x88` | `owned_88` |
| `0x287694` | `+0x84` | `0x2876c8` | `+0x84` | `opaque_84` |

- 指针槽（`+0x14/+0x1c/+0x58/+0x64/+0x88`）是**共享引用**：不复制内容、不 free、
  不引用计数。计数/长度槽 `+0x10/+0x18/+0x20/+0x60/+0x78/+0x84` 按值复制。
- `+0x8c/+0x90` 用 `vldr`/`vstr` 复制 32 位位型；这两个指令不改位、不动 FPSCR，
  所以 canonical 的 `uint32_t` 字段经 VFP 原语搬运是逐位相同的。
- **不复制**：`+0x24..+0x54`（region 指针/偏移/尺寸/UV 矩形等）、`+0x5c`（自己的
  输出 UV）、`+0x68..+0x74`（颜色）、`+0x80`。`+0x7c` 写的是 `parent` 本身。
- 因此 linked mesh 的调用顺序（`0x28cce8/0x28ccf0`）是：先 setParentMesh 共享源数组，
  再 updateUVs 释放并重建自己的 `+0x5c`。dispose 侧：`parentMesh != NULL` 时只
  `_spAttachment_deinit`，不再 free `+0x58/+0x64/+0x88`（共享），但 `+0x54/+0x5c`
  仍无条件 free（自有）。
- `self == parent`：先全读后全写，结果幂等；没有提前别名判断。
- 若 `parent` 是非法指针：`+0x7c` 已经先写，随后 13 个读中第一个坏地址处失败；
  这个“先写后炸”的顺序被保留。

## 4. 字段语义证据（只列本闭包能证的）

| 偏移 | 语义 | 证据 |
|---|---|---|
| `+0x20` | region-UV float 数（= worldVerticesLength） | `_readVertices 0x28b414` 写入；本函数 `0x287548` 读作 malloc 大小/循环门；reader `0x28d0b0..c0` 传入 JSON `uvs` 数组长度 |
| `+0x40/+0x44/+0x48/+0x4c` | region 矩形 u/v/u2/v2 | Atlas factory `_spAtlasAttachmentLoader_createAttachment`（`spine_atlas_attachment.c`）写入；本函数快照后算 width/height |
| `+0x50` | rotate（非 0 选旋转映射） | 同上由 region->rotate 写入；本函数 malloc 后读 |
| `+0x58` | 源 region-UV float 数组 | reader `0x28d06c..0x28d090` 按 JSON `uvs` 数组 malloc+复制后写 `+0x58`；本函数只读；dispose 无父时 free |
| `+0x5c` | 输出（纹理空间）UV float 数组 | 本函数 free+重建+写入；dispose 无条件 free；setParentMesh 不复制 |
| `+0x54` | 自有 path 字符串副本 | dispose 无条件 free；两函数本身不读不写；父级 caller 已将 `0x28cb20..0x28cb44` 的 strlen+malloc+strcpy 绑定到 mesh 对象，保留既有成员名 |
| `+0x60`/`+0x64` | trianglesCount / triangles（uint16 流） | reader `0x28d020..0x28d058`：count←Json 数组大小，malloc(count*2)，`strh` 填 `child->+0x14` |
| `+0x78` | hullLength（int） | reader `0x28d0e8` 从 Json getInt 写入 |
| `+0x84`/`+0x88` | edgesCount / edges | reader `0x28d108/0x28d120` |
| `+0x8c`/`+0x90` | width / height 的 float 位型槽 | caller `0x28cbb0..0x28cbf0` 分别查 width/height，默认32.0f并乘当前scale；保留既有 opaque 成员名 |
| `+0x68..+0x74` | r/g/b/a（构造器写 1.0f） | `spMeshAttachment_create 0x287500..0x287520`；setParentMesh **不**复制 |

建议给父级的重命名（本模块不改共享头）：`+0x20` → `regionUVCount`（现名
`worldVerticesLength` 沿用了 vertex base 的别称，数值确实同源）；`+0x50` →
`regionRotate`；`+0x58` → `regionUVs`；`+0x5c` → `uvs`；`+0x60` →
`trianglesCount`；`+0x64` → `triangles`；`+0x78` → `hullLength`；`+0x84` →
`edgesCount`；`+0x88` → `edges`。本批不作公共字段改名；path与宽高角色已由父级caller写者确定，见上表。

## 5. 数值 / 顺序 / 陷阱

1. **VMLA/VMLS 是原指令**：普通路径两处、旋转路径两处都是 `vmla.f32`/`vmls.f32`
   （VFPv3 非融合，乘积先舍入，再累加/相减舍入，不是 VFMA/VFMS）。
   译文用最小 inline asm 保留原指令，防编译器换成融合操作。父级具名夹具
   已用抵消反例检查两次舍入；没有实测 FPSCR 全矩阵。
2. **VADD 顺序**：旋转路径是 `vadd.f32 s15,s16,s15`（height + base_v），不是
   `base_v + height` 的“等价交换”——NaN 载荷选择/符号零按第一操作数，顺序保留。
3. **VSUB 顺序**：`u2-u`、`v2-v`；不要写成 `u-u2`。
4. **位搬运**：`vldr/vstr/vmov` 只搬 32 位，不改值、不改 FPSCR；`+0x8c/+0x90`
   以 VFP 原语搬运，canonical 的 `uint32_t` 字段逐位不变。
5. **两层快照**：count/u/v/u2/v2/旧 `+0x5c` 在 free 前；rotate、`+0x58` 在 malloc 后；
   每次迭代的 `self->u`、`self->v` 再重读。任何“提前缓存一对源 float”都会在
   provider 返回重叠缓冲时改变结果。
6. **32 位算术**：`n<<2` 回绕；`(n-1)>>1` 是逻辑右移；`n` 用有符号 `>0` 门；
   奇数 n 的越界读写是原版行为，不修。
7. **无 NULL/边界检查**：free(NULL) 由 `_free` 原样转发；malloc(NULL) 结果照用。
8. **FPSCR**：本函数不写 FPSCR（无 `vmrs/vmsr`），舍入模式/FZ/DN/trap 继承调用者；
   合成/宿主跑不能替代原版 FPSCR 矩阵，未测项见 remaining scope。
9. **tag 指针**：字符串字节与原版 `.rodata 0x357908` 完全相同，但重链接后地址不同；
   provider 若按指针数值比较 tag 或改写该字符串，属于本译文与原件的外部差异。
10. **不执行原件**：本层只有 bytecode 锚点，没有 oracle 对拍。

## 6. 依赖与编译

- 布局：`c/spine_atlas_attachment/src/spine_atlas_attachment.h`（canonical，0x94/0x24，
  未改）。本模块 `src/spine_mesh.h` 只追加 `_Static_assert`。
- 分配器：`c/spine_alloc` 的 `_malloc/_free`（ABI 见 `spine_alloc.h`）。
- 无其它库内调用；无 libc 调用（tag 是静态字符串）。
- 真实编译（已跑）：

```
clang --target=armv7a-none-eabi -march=armv7-a -marm -mfpu=vfpv3 \
  -mfloat-abi=softfp -std=c11 -ffreestanding -fno-builtin \
  -ffp-contract=off -Wall -Wextra -Werror \
  -I c/spine_alloc/src -I c/spine_attachment/src \
  -I c/spine_skeleton_data/src -I c/spine_atlas_attachment/src \
  -O0|-O2|-O3 -fsyntax-only c/spine_mesh/src/spine_mesh.c
```

三个优化级均 exit 0。`-c -O2` 产物核对：普通路径含 `vmla.f32`×2，旋转路径含
`vmla.f32` + `vadd.f32` + `vmls.f32`；`bl _free` 在 `bl _malloc` 之前；
`ldr [r4,#0x50]`（rotate）在 malloc 之后；循环内每次都有 `vldr` 重读 `+0x40/+0x44`。
编译守卫：`-mfloat-abi=hard` 与无 VFP（`-mfloat-abi=soft` 且无 `-mfpu`）均被
`#error` 拒绝。

## 7. remaining scope（本阶段不报等价）

- 未执行原件/oracle；未做 C↔原版运行时对拍。
- mesh/link 字段 caller 已接通；仍未装配全 loader 的公共 skin 插入/外循环与
  linked 父项/skin 名称解析及错误清理后处理。worldVertices/render消费者仍未接通。
- FPSCR 全矩阵（舍入模式、FZ、DN、trap、sNaN 载荷）未实测；只保留指令种类/顺序。
- 奇数写入足迹及重叠 source/output 已有重建夹具（provider故意提供足够后备内存）；
  这不认证真实分配越界故障、任意对象重叠或非法 parent 指针的精确失败行为。
- tag 指针数值与原版不同（字符串内容相同）。
