# 顶层段链静态普查（spSkeletonJson_readSkeletonData @0x28b84c，animations 之外）

只读静态普查，**原件未执行**，全部结论属 `bytecode_anchored`。本文件与同批 TSV 均为新建，未改动任何既有文件，未运行任何 git 命令。

| 项 | 值 |
|---|---|
| 对象 | `/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so` |
| SHA256 | `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`（已校验，与任务给定一致） |
| 函数 | `spSkeletonJson_readSkeletonData` 0x28b84c，size 13044 → 0x28eb40，ARM（非 Thumb） |
| 本段 | **0x28b84c..0x28d19c（end 排他，6480B）**；0x28d19c 起为已恢复的 animations 段 |
| 反汇编 | `reconstruction/reverse-v1/asm/segment_chain_census.tsv`（`scripts/asm_index.py` 产出） |
| 条目数 | 1620 行；其中 **158 字是 literal pool**（0x28c7e4..0x28ca5c，632B），实际指令 **1462** |
| 调用 | 205 个 `bl` 站点 / 38 个唯一目标 |
| pc 相对 | 125 次 `ldr rX,[pc,#imm]`，解析出 74 个唯一字符串 VA（全部命中，无未解析池载入） |
| malloc 锚 | 18 个（全函数 25 个；另 7 个在 animations 段） |
| 探针 | `~/.hermes/cache/scratch/wl_chainP_{cfg,plt,syms,malloc,blocks,dump,cov,cov2,reach,ranges,final}.py` |

---

## 0. 结论摘要

1. **段序是单链、无分叉**：entry/meta → bones → slots → ik → transform → path → skins（attachments 内联在 skins 的三层循环里，没有自己的顶层键）→ linkedmesh 后处理 → animations → 公共收尾 0x28bdcc。每个顶层段都以 `Json_getItem(root, key)` 开头，键缺失即跳到下一段（例外与空数组语义见 §1.4）。
2. **root 只被两个地方释放**：`_spSkeletonJson_setError` 内部（0x28b824，仅当第 2 实参非 0）与成功路径 animations 段末尾 0x28e7a8。11 个 setError 站点里 10 个从 `[sp,#0x24]` 取第 2 参（含 1 处槽值为 0 的 Json_create 失败站），1 个（linkedmesh "Skin not found"）直接传 0 → **该路径 root 泄漏**，属原版行为，不要"修"。
3. **返回值只有 3 个 `pop {...,pc}` 出口**：0x28bdd4（公共收尾）、0x28bf24、0x28bf54；成功返回 data（r9），所有错误返回 NULL（多数是失败查找留下的 0）。
4. **物理缺口 8 块 / 368B / 92 insn（占本段 5.7%）**，全部集中在三类胶水：createAttachment 五参调用+类型跳转表、skins 三层循环推进、四条离位错误尾。逐块见 §5。
5. **两处 ABI 会在总装时咬人**：`attach_type_e` 枚举顺序与二进制不符；`_spSkeletonJson_setError` 是 **4 参**（json, root, fmt, arg），而 `spine_read_entry.c` 里声明成 5 参。详见 §2.3。

---

## 1. 段调用顺序链（地址证据）

### 1.1 总链

```
0x28b84c prologue  push{r4-r11,lr}; vpush{d8}; r8=json; r5=path; sub sp,#124
0x28b85c free(json->error @+0x8); 0x28b874 json->error=0; 0x28b878 json->unk_10=0
0x28b87c setlocale(LC_NUMERIC,NULL)
   ├─ 非 NULL：0x28b888 strdup → 0x28b89c setlocale("C") → 0x28b8a4 Json_create(path)
   │            → 0x28b8ac root=[sp,#0x24] → 0x28b8b4 setlocale(saved) → 0x28b8c4 free(copy)
   └─ NULL   ：0x28bf58 setlocale("C") → 0x28bf6c Json_create(path)
                → 0x28bf74 root=[sp,#0x24] → 0x28bf7c setlocale(NULL) → 0x28b8c8（不恢复，原版怪癖）
0x28b8c8 if(!root) → 0x28c3b4  Json_getError → setError(json,root,"Invalid skeleton JSON: ",err) → 返回 0
0x28b8d4 data = spSkeletonData_create(); r9 = data
0x28b8e8 skeleton = getItem(root,"skeleton")           ; NULL → 0x28b9cc
0x28b8f4 meta：hash(malloc 607→data+4)、"spine"=version(malloc 608→data+0)、width、height
0x28b9c8 → 落入 0x28b9cc
0x28b9cc bones = getItem(root,"bones")                 ; **不判空**（见 §1.4）
0x28b9f4 malloc 615 → data+0x14；child==0 → 0x28bbcc
0x28ba44 逐骨循环 … 0x28bb94 ldr r4,[r4] ; 0x28bba0 beq 0x28bbcc
0x28bbcc slots = getItem(root,"slots")                 ; NULL → 0x28bddc
0x28bbf0 data+0x18 = slots->size ; 0x28bbfc malloc 651 → data+0x1c ; child==0 → 0x28bddc
0x28bd7c 条件（getString "bone"→findBone）→ 0x28bc5c 体 … 0x28bd78 beq 0x28bdd8
0x28bdd8 r8 = json（从 [sp,#0x28] 恢复）
0x28bddc ik = getItem(root,"ik")                       ; NULL → 0x28bff8
0x28be04 data+0x3c = size ; 0x28be10 malloc 697 → data+0x40 ; child==0 → 0x28bff8
0x28be68 逐约束 … 0x28bff4 bne 0x28be68 ; 落入 0x28bff8
0x28bff8 transform = getItem(root,"transform")         ; NULL → 0x28c274
0x28c020 data+0x44 = size ; 0x28c02c malloc 735 → +0x48 ; child==0 → 0x28c274
0x28c078 逐约束 … 0x28c270 bne 0x28c078 ; 落入 0x28c274
0x28c274 path = getItem(root,"path")                   ; NULL → 0x28c5ec
0x28c29c data+0x4c = size ; 0x28c2a8 malloc 782 → +0x50 ; child==0 → 0x28c5ec
0x28c2f4 逐约束 … 0x28c5e8 bne 0x28c2f4 ; 落入 0x28c5ec
0x28c5ec skins = getItem(root,"skins")                 ; NULL → 0x28ccb8
0x28c618 malloc 839 → data+0x24 ; child==0 → 0x28ccb8
0x28c664 逐 skin：spSkin_create；"default"→data+0x28；逐 slot：findSlotIndex；
         逐 attachment：name/path/type → createAttachment → switch(type) → spSkin_addAttachment
0x28ccb8 linkedmesh 后处理（若 json->unk_10<=0 → 0x28d19c；否则 0x28cccc 循环，0x28cd00 ble 0x28d19c）
0x28d19c animations 段入口（已恢复）：getItem(root,"events") …
0x28e7a4 Json_dispose(root) ; 0x28e7ac r0=r9(data) ; 0x28e7b0 b 0x28bdcc
0x28bdcc 公共收尾 add sp,#124; vpop{d8}; pop{r4-r11,pc}
```

### 1.2 段尾→段首转移表（逐块证据）

| 段 | 段尾 | 最后一条指令 | 如何进入下一段 |
|---|---|---|---|
| entry | 0x28b8f0 | `beq 0x28b9cc`（skeleton 缺键）| 不缺键则顺序落入 0x28b8f4 |
| meta | 0x28b9c8 | `str r0,[r9,#0xc]`（height）| 顺序落入 0x28b9cc |
| bones | 0x28bba0 / 0x28bbc8 | `beq 0x28bbcc`；`b 0x28ba50`（回边）| 0x28bbcc 取 `slots` 键 |
| slots | 0x28bd78 | `beq 0x28bdd8`（前置 `ldr r4,[r4]` @0x28bd70）| 0x28bdd8 `ldr r8,[sp,#0x28]` → 0x28bddc 取 `ik` |
| ik | 0x28bff4 | `bne 0x28be68`（回边）| 落空到 0x28bff8 取 `transform` |
| transform | 0x28c270 | `bne 0x28c078`（回边）| 落空到 0x28c274 取 `path` |
| path | 0x28c5e8 | `bne 0x28c2f4`（回边）| 落空到 0x28c5ec 取 `skins` |
| skins | 0x28cc98 / 0x28ccb0 | `bne 0x28c6c4`（下一 slot）；`bne 0x28c664`（下一 skin）| 落空到 0x28ccb4 `mov r9,r11` → 0x28ccb8 |
| linkedmesh | 0x28ccc8 / 0x28cd00 | `b 0x28d19c`；`ble 0x28d19c` | animations 段 0x28d19c |
| animations | 0x28e7b0 | `b 0x28bdcc`（前置 0x28e7a4 dispose root、0x28e7ac `mov r0,r9`）| 公共收尾 0x28bdcc |

### 1.3 顶层 getItem 键序列（8 站，含 animations 入口）

| # | 键 | 载入/加址 | va | 调用 | NULL 跳转 | 备注 |
|---|---|---|---|---|---|---|
| 1 | `skeleton` | 0x28b8dc / 0x28b8e0 | 0x357b5c | 0x28b8e8 | 0x28b9cc | 缺键=整段 meta 跳过 |
| 2 | `bones` | 0x28b9d4 | 0x357b88 | 0x28b9d8 | **无** | 直接 `ldr r0,[r0,#0xc]`（0x28b9ec）→ 缺键即空指针 |
| 3 | `slots` | 0x28bbd4 | 0x357b90 | 0x28bbd8 | 0x28bddc | 缺键 count/array 都不写 |
| 4 | `ik` | 0x28bde4 | 0x357bfc | 0x28bde8 | 0x28bff8 | |
| 5 | `transform` | 0x28c000 | 0x357c48 | 0x28c004 | 0x28c274 | |
| 6 | `path` | 0x28c27c | 0x357c9c | 0x28c280 | 0x28c5ec | 与 attachment 的 `path` 键同串 |
| 7 | `skins` | 0x28c5f4 | 0x357cf4 | 0x28c5f8 | 0x28ccb8 | 缺键直接进 linkedmesh 后处理 |
| 8 | `events` | 0x28d19c | 0x357d94 | 0x28d1a8 | 0x28d290 | animations 段，已恢复 |

**关键结构事实**：attachments 不是顶层段——它完全内联在 `skins` 的 skin→slot→attachment 三层循环里（0x28c6e8..0x28cc68），没有自己的 getItem 入口。把 attachments 当作 skins 的兄弟段去接线会漏掉 skin 上下文（`spSkin_addAttachment` 需要 skin 指针与 slotIndex）。

### 1.4 判空跳过语义（两类，别混）

**A. 段键缺失**（6 处，见 §1.3；bones 完全不判空，见 C）。`skeleton` 缺失只跳过 meta，data 仍被创建并继续；其余缺失都只跳过本段，链继续。

**B. 段键存在但数组 child==0**（6 处）：**先完成 count/array 写入与 malloc，再跳过循环**——空数组也会照做 malloc，只是不进循环：

| 段 | child==0 分支 | 已写入 |
|---|---|---|
| bones | 0x28ba04 beq 0x28bbcc | data+0x14=malloc(size*4)（count 不预写，循环内递增） |
| slots | 0x28bc0c beq 0x28bddc | data+0x18=size, data+0x1c=malloc(size*4) |
| ik | 0x28be20 beq 0x28bff8 | data+0x3c=size, data+0x40=malloc |
| transform | 0x28c03c beq 0x28c274 | data+0x44=size, data+0x48=malloc |
| path | 0x28c2b8 beq 0x28c5ec | data+0x4c=size, data+0x50=malloc |
| skins | 0x28c62c beq 0x28ccb8 | data+0x24=malloc（count 由循环递增） |

**C. bones 的缺键空指针**：0x28b9d8 getItem 后无 `cmp/beq`，0x28b9ec 直接 `ldr r0,[r0,#0xc]`。`spine_read_meta.c:readSkeletonData_bonesArray` 忠实保留了这一点（`bones->unk_0c` 无判空），总装时不要补 guard，否则与原件行为分叉。

### 1.5 每段嵌套键（按控制流顺序，字符串 VA 已实测）

| 段 | 键序列 |
|---|---|
| meta | hash → spine(=version) → width → height |
| bones | parent → name → length → x → y → rotation → scaleX → scaleY → shearX → shearY → inheritRotation(int) → inheritScale(int) |
| slots | bone(条件) → name → color(hex 串) → attachment → blend(additive/multiply/screen) |
| ik | name → bones → target → bendPositive(int) → mix(float) |
| transform | name → bones → target → rotation → x → y → scaleX → scaleY → shearY → rotateMix → translateMix → scaleMix → shearMix |
| path | name → bones → target(slot!) → positionMode → spacingMode → rotateMode → rotation → position → spacing → rotateMix → translateMix |
| skins | JSON 键名即 skin 名 → `default` 比较 → slot 名即 `spSkeletonData_findSlotIndex` 入参 → attachment: name/path/type |
| attachments | region: x/y/scaleX/scaleY/rotation/width/height/color；bbox: vertexCount；mesh: parent/skin/deform/triangles/uvs/hull/edges；path: closed/constantSpeed/vertexCount/lengths |

---

## 2. 每段入口/出口 ABI 对照

### 2.1 寄存器与栈槽约定（本函数内，实测）

| 位置 | 含义 | 写点 | 读点 |
|---|---|---|---|
| r8 | `spSkeletonJson* json`（段边界） | 0x28b854 | 段内 `vldr s15,[r8]` 取 scale；`ldr r0,[r8,#4]` 取 loader |
| r9 | `spSkeletonData* data` | 0x28b8e0 | 各段写入 data 字段 |
| `[sp,#0x24]` | `Json* root` | 0x28b8ac, 0x28bf74 | 8 个 getItem + 10 个 setError |
| `[sp,#0x28]` | slots 段的 json 备份（r8 被借作字符串指针，0x28bc54） | 0x28bc48 | 0x28bda4, 0x28bdd8 |
| `[sp,#0x34]` | skins 段的 data 备份（r9 被借作 skin 指针） | 0x28c6b8 | 0x28cc9c, 0x28cf78 |
| `[sp,#0x18]` | skins 段当前 skinMap | 0x28c624 | 0x28c664/0x28cca0 |
| `[sp,#0x1c]` | skins 段当前 slotMap | 0x28c6a0 | 0x28c6c4/0x28cc88 |
| `[sp,#0x28]` | **skins 段复用**为 slotIndex | 0x28c6e0 | 0x28cc74（addAttachment 的 r1） |
| `[sp,#0x2c]`/`[sp,#0x30]`/`[sp,#0x20]`/`[sp,#0x4c]` | skins 段 "type"/"name"/"path"/"default" 串指针 | 0x28c6c0/0x28c658/0x28c660/0x28c654 | dispatch |
| `[sp,#0x38]` | 0x55555556（signed /3） | 0x28c65c | 0x28cab8 |
| `[sp]` | createAttachment 第 5 参 `path` | 0x28c7ac | 被调方 |

> 同一帧被各段复用，`[sp,#0x28]` 在 slots 段是 json、在 skins 段是 slotIndex —— 这正是原版把 json 挪到 `[sp,#0x28]` 又复用同一槽的原因，写 C 胶水时必须按段语义区分。

### 2.2 模块对照表

| 模块 / 函数（.h 声明） | 二进制边界 | 入口/出口 | 已覆盖胶水 | 仍缺 |
|---|---|---|---|---|
| `spine_read_entry` / `Json* readSkeletonData_entry(spSkeletonJson*, const char* path, spSkeletonData** out)` | 0x28b84c–0x28b8f0（.c 文件头写 0x28b9cc，函数体注释与 .h 写 0x28b8f0） | r0=json, r1=path → r0=root；data 经 out | locale guard、Json_create、skeleton getItem、spSkeletonData_create | ① 0x28bf58 起 locale==NULL 分支未实现（模块直接跳过 setlocale("C")）② 0x28c3b4 Json_create 失败尾未实现（模块只 `return 0`，未 setError）③ setError 原型 5 参，二进制 4 参 |
| `spine_read_meta` / `void readSkeletonData_metadata(Json*, void*)`；`Json* readSkeletonData_bonesArray(Json*, void*, int* out_count)` | 0x28b8f4–0x28ba40 | r0=skeleton/bones 节点；data 在 r9 | meta 4 键、bones 数组 malloc 615、缺键空指针 | 无（out_count 是恢复便利参数：二进制 count 只在循环内递增，data+0x10 无初值写点） |
| `spine_read_bones` / `spSkeletonData* readSkeletonData_oneBone(Json*, void*, float, int*)`；`int readSkeletonData_boneLoop(Json*, void*, float)` | 0x28ba40–0x28bbcc | r0=首骨节点, r9=data；r0=1/0 | 骨循环、parent 查找、字段写、数组发布 | parent-not-found 尾 0x28bf28–0x28bf58（dispose+setError+返回 0）未发射 |
| `spine_read_slots` / `int readSkeletonData_slotsSegment(Json*, void*, void* parser)` | 0x28bbcc–0x28bdd8 | r0=root, r9=data, r8=json；r0=1/0 | **完整**：数组 malloc 651、条件在循环头、错误尾 dispose+setError、返回 0 | 0x28bdcc..0x28bdd4 是公共收尾（slots 错误路径只负责 0x28bdc8 的 `mov r0,r7`），需只发射一次 |
| `spine_read_ik` / `int readSkeletonData_ikSection(Json*, void*, int* which, const char** name)` | 0x28bdd8–0x28bff8 | r0=root, r9=data；r0=1/0 | 约束循环、两条 findBone、bendPositive/mix | 两条错误尾都没发射：0x28bf00（ik bone，在声明区间内）与 0x28cf3c（target，离位）；且模块只回填 which/name，setError 由谁发未定义 |
| `spine_read_transform` / `int ...transformSection(Json*, void*, float, int*, const char**)` | 0x28bff8–0x28c270 | 同上 | 约束循环、9 个 float、bones 数组 743 | 错误尾 0x28c104（bone）与 0x28d144（target）|
| `spine_read_path` / `int ...pathSection(Json*, void*, float, int*, const char**)` | 0x28c274–0x28c5e8 | 同上 | 约束循环、模式 strcmp 链、findSlot target、5 个 float | 错误尾 0x28c384（bone）与 0x28d170（target slot）|
| `spine_read_skins` / `Json* ...skinsArray(Json*, void*)`；`void* ...oneSkin(Json*, void*, int*)` | 0x28c5ec–0x28c6b0 | r0=root/skinMap；r0=child/skin | skins 数组 malloc 839、default 判定、计数递增 | 三层循环推进 + addAttachment（0x28cc68..0x28ccb8）|
| `spine_read_attach_dispatch` / `attach_type_e ...classifyAttachment(Json*, void*, const char**, const char**, const char**)` | 0x28c6b4–0x28c79c | r0=attachmentMap → 枚举 | name/path/type 取值、5 条 strcmp | ① 枚举序错（见 §2.3）② createAttachment 调用+类型跳转表 0x28c7a0..0x28c7e4 未覆盖 |
| `spine_read_region` / `void ...regionFields(Json*, spRegionAttachment*, const char* path, const spSkeletonJson*)` | 0x28cdac–0x28cf20（case 0） | r4=map, r6=att, r5=path, r8=json | 全部 region 字段 | 无 |
| `spine_read_bbox_path` / `...boundingBoxFields`；`...pathAttachmentFields` | 0x28cd6c–0x28cda4（case 1）；0x28ca5c–0x28cb18（case 4） | r4=map, r6=att | 全部字段 + configure | 无 |
| `spine_read_mesh` / `int ...meshFields(Json*, spMeshAttachment*, const char* path, spSkeletonJson*, uint32_t slotIndex)` | 0x28cb20–0x28cc64（case 2/3）；0x28cfa8–0x28d140（增长块） | 返回 1=已入 linkedmesh 队列 / 0=可直接 add | path 深拷贝 917、color、uvs/triangles/hull/edges、队列增长 136 | ① createAttachment 失败分流 0x28cf68/0x28cf78 ② 队列外层的 addAttachment 0x28cc68 |
| `spine_linked_postpass` / `int ...resolveLinkedMeshes(spSkeletonJson*, spSkeletonData*)` | 0x28ccb8–0x28cd68 | r0=1 继续 events / 0 返回 NULL | 后处理全链 + 两条错误尾（含 setError 传 root=0） | 无 |

### 2.3 三个 ABI 陷阱（总装必读）

1. **`_spSkeletonJson_setError` 是 4 参**：`(spSkeletonJson* json, Json* root, const char* fmt, const char* arg)`。
   证据 0x28b784：`r0=json, r1=root, r2=fmt, r3=arg`；内部 0x28b808 把新串写 `json->error(+8)`，0x28b818 `cmp r8(=r1),#0` → 0x28b824 `Json_dispose(root)`。
   而 `c/spine_read_entry/src/spine_read_entry.c:68` 声明为 5 参 `(json, fmt, a, b, int c)` —— **签名错误**，总装时必须改成 4 参，否则 fmt/root 错位会把格式串当 root 释放。
2. **attachment 类型枚举序**：二进制跳转表 0x28c7c8（`addls pc,pc,r3,lsl#2`）落在 0x28c7d0..0x28c7e0，配合 createAttachment 的 r2：
   `region=0`（0x28cf2c `mov r2,r0`，r0=strcmp 结果 0）、`boundingbox=1`（0x28cfa0）、`mesh=2`（0x28cf24）、`linkedmesh=3`（0x28cf34）、`path=4`（0x28c7a0）。
   这正是 spine-c 的 `spAttachmentType` 顺序；而 `spine_read_attach_dispatch.h` 自定义的 `attach_type_e` 是 REGION0/MESH1/LINKEDMESH2/BOUNDINGBOX3/PATH4 —— **mesh 与 boundingbox 互换**。接线时要么改枚举，要么在调用 createAttachment 前做映射。
3. **scale 不是入参，是 json+0 的惰性读取**：所有缩放点都是 `vldr s15,[r8]`（如 0x28ba88、0x28cdf0），模块却把 `float json_scale` 作形参。接线时按调用时刻 `*(float*)(json+0)` 传入；不要在段间缓存。

另：`spAttachmentLoader_createAttachment` 是 **5 参**，第 5 参 `path` 走栈（0x28c7ac `str r5,[sp]`，r0=json->loader, r1=skin, r2=type, r3=name）。C 调用约定会自动处理，但别把 name/path 顺序写反。

---

## 3. 根树生命周期（root = Json*）

### 3.1 创建与写入

| 事件 | 地址 | 说明 |
|---|---|---|
| Json_create #1 | 0x28b8a4 | 正常路径（已保存 locale） |
| 写 `[sp,#0x24]` #1 | 0x28b8ac | 紧接 Json_create |
| Json_create #2 | 0x28bf6c | 仅当 `setlocale(1,NULL)==NULL` 的兜底路径 |
| 写 `[sp,#0x24]` #2 | 0x28bf74 | 兜底路径重写同一槽（不会同时存在两棵树） |
| 判空 | 0x28b8c8–0x28b8d0 | `beq 0x28c3b4`（Json_getError 错误尾） |

root 槽在全函数内**只写两次**，没有清零点；函数返回前不是被 setError 释放，就是被 animations 成功路径释放。

### 3.2 root 读点（getItem 8 处）

0x28b8e4（skeleton）、0x28b9d0（bones）、0x28bbd0（slots）、0x28bde0（ik）、0x28bffc（transform）、0x28c278（path）、0x28c5f0（skins）、0x28d1a0（events）。

### 3.3 释放点

| 释放者 | 地址 | 条件 | 覆盖的站点 |
|---|---|---|---|
| `_spSkeletonJson_setError` 内部 | 0x28b824 `bl Json_dispose` | 第 2 实参 r1 != 0 | 10 个站点从 `[sp,#0x24]` 取 root（含 Json_create 失败站，该处值为 0 → 实际不释放） |
| 成功路径（animations 段尾） | 0x28e7a8 `bl Json_dispose` | 恒定 | 唯一成功出口 |
| **无** | — | r1==0 | linkedmesh "Skin not found" 0x28cd60 → **root 泄漏（原版行为）** |

### 3.4 setError 11 站点实参形态（r0=json 恒为 r8）

| # | 站点 | r1=root 来源 | r2 消息 | r3 参数 | 前置 dispose(data) | 返回 r0 |
|---|---|---|---|---|---|---|
| 1 | 0x28bdc4 | `[sp,#0x24]` | `Slot bone not found: ` | r5=boneName | 0x28bdac | r7=0 |
| 2 | 0x28bf14 | `[sp,#0x24]` | `IK bone not found: ` | [r4,#0x10] | 0x28befc | r10=0（0x28bef8 显式置 0） |
| 3 | 0x28bf44 | `[sp,#0x24]` | `Parent bone not found: ` | r10 | 0x28bf2c | r5=0 |
| 4 | 0x28c124 | `[sp,#0x24]` | `Transform bone not found: ` | [r4,#0x10] | 0x28c10c | r10=0 |
| 5 | 0x28c3a4 | `[sp,#0x24]` | `Path bone not found: ` | [r10,#0x10] | 0x28c38c | r12=0 |
| 6 | 0x28c3cc | `[sp,#0x24]`（此时=0） | `Invalid skeleton JSON: ` | Json_getError() | 无（data 未创建） | [sp,#0x24]=0 |
| 7 | 0x28cd60 | **r5=0** | `Skin not found: ` | [r4,#4] | 0x28cd48 | r5=0（root 泄漏） |
| 8 | 0x28cf5c | `[sp,#0x24]` | `Target bone not found: ` | [r4,#0x1c] | 0x28cf44 | r4=0 |
| 9 | 0x28cf94 | `[sp,#0x24]` | `loader->error1`（+0） | `loader->error2`（+4） | 0x28cf80 | r6=0 |
| 10 | 0x28d164 | `[sp,#0x24]` | `Target bone not found: ` | [r4,#0x1c] | 0x28d14c | r4=0 |
| 11 | 0x28d190 | `[sp,#0x24]` | `Target slot not found: ` | [r4,#0x1c] | 0x28d178 | r4=0 |

三种形态即：**(json, root, msg, arg)** 10 站（其中 Json_create 失败那站 root 值为 0）；**(json, 0, msg, arg)** linkedmesh 1 站（不释放 root）；**(json, root, loader->error1, loader->error2)** 1 站（createAttachment 失败且 loader 报了错）。注意第 9 站的消息对是从 `json->loader` 指向的结构里 `ldm` 出来的两个字，不是静态串。

### 3.5 json 自身的清理

- 入口 0x28b85c：`free(json->error)`，0x28b874 `json->error=0`，0x28b878 `json->unk_10=0`。`unk_10` 就是 linkedmesh 队列计数（0x28cfd8 `ldr r2,[r8,#0x10]`、0x28ccb8 处 `j->unk_10`）。
- `json+0x14`（容量）与 `json+0x18`（队列数组）入口**不清零**；0x28cfa8 的增长块在每次入队时重分配：count<=3 → capacity=8、128B；count>=4 → capacity=2*count、bytes=32*count，并 `free` 旧数组（0x28cfec），因此跨调用不泄漏。
- `json->error` 由 setError 每次重新 `malloc(len+1, tag, 90)`（0x28b800）。

---

## 4. 返回值契约

### 4.1 三个物理出口

| 出口 | 地址 | 进入条件 | r0 |
|---|---|---|---|
| 公共收尾 | 0x28bdd4（`add sp; vpop; pop` 在 0x28bdcc） | 所有 `b 0x28bdcc` + slots 正常落空 | 调用方设定，见 §4.2 |
| IK 专用 | 0x28bf24 | 只有 `mov r0,r10` @0x28bf18 | 0（IK bone 失败） |
| 骨骼专用 | 0x28bf54 | 只有 `mov r0,r5` @0x28bf48 | 0（parent 失败） |

### 4.2 `b 0x28bdcc` 的 r0 来源

| 来源块 | r0 赋值 | 值 |
|---|---|---|
| 0x28bdc8 | `mov r0,r7` | 0（findBone 失败） |
| 0x28c128 | `mov r0,r10` | 0 |
| 0x28c3ac | `mov r0,r12`（r12 于 0x28c388 存 [sp,#0x14]） | 0 |
| 0x28c3d0 | `ldr r0,[sp,#0x24]` | 0（该路径 root==NULL） |
| 0x28cd64 | `mov r0,r5` | 0 |
| 0x28cf60 | `mov r0,r4` | 0 |
| 0x28cf98 | `mov r0,r6` | 0 |
| 0x28d168 | `mov r0,r4` | 0 |
| 0x28d194 | `mov r0,r4` | 0 |
| 0x28e7ac | `mov r0,r9` | **data（唯一非 0）** |

结论：**成功=spSkeletonData*，失败=NULL**；失败时 data（若已创建）一定已在对应错误尾里 `spSkeletonData_dispose`（0x28adf8，10 个站点），root 由 setError 负责（例外 §3.3）。

### 4.3 所有权

- 成功：root 在返回前被 `Json_dispose`（0x28e7a8），data 归调用者。
- 失败：data（若已创建）已 dispose；root 通常已被 setError dispose；`json->error` 保存新错误串（调用者负责下一次入口 free）。
- linkedmesh "Skin not found"：data 已 dispose，root 未 dispose —— 调用者拿到的 json 仍持有 root 指针，但没有任何字段记录它，属不可回收泄漏。

---

## 5. 仍缺的胶水块清单

### 5.1 物理缺口（不在任何已恢复模块声明区间内）

| # | 地址区间 | 大小 | insn | 内容 | 为什么必须补 |
|---|---|---|---|---|---|
| 1 | 0x28c7a0..0x28c7e4 | 68B | 17 | `createAttachment(loader,skin,type,name,path)` 五参调用；NULL 分流；`addls pc,pc,r3,lsl#2` 类型跳转表 | 这是 skins→attachments 的唯一入口 |
| 2 | 0x28cc68..0x28ccb8 | 80B | 20 | `spSkin_addAttachment(skin,slotIndex,name,att)`；attachment→slot→skin 三层 `ldr r0,[r0]` 推进与回边 | 没有它 attachments 解析完不会入 skin，也不会进下一 skin |
| 3 | 0x28cf24..0x28cf3c | 24B | 6 | 三个 type 装载桩：mesh=2 / linkedmesh=3 / region=`mov r2,r0`(0) | strcmp 分派的落点 |
| 4 | 0x28cf3c..0x28cf68 | 44B | 11 | ik `Target bone not found: ` 尾：dispose+setError+返回 0 | ik 模块只回填 error_which=2 |
| 5 | 0x28cf68..0x28cf78 | 16B | 4 | createAttachment 返回 NULL 的分流：`if (!loader->error1) 静默跳过` | 原版允许 loader 无错误时跳过附件 |
| 6 | 0x28cf78..0x28cfa8 | 48B | 12 | loader 有错（`loader->error1!=0`）：dispose+`setError(json,root,loader->error1,loader->error2)`；末尾 bbox=1 桩 | 唯一的 loader 错误上报形态 |
| 7 | 0x28d144..0x28d170 | 44B | 11 | transform `Target bone not found: ` 尾 | transform 模块只回填 which=2 |
| 8 | 0x28d170..0x28d19c | 44B | 11 | path `Target slot not found: ` 尾 | path 模块只回填 which=2，且此尾无任何模块注释提及 |
| | **合计** | **368B** | **92** | 占本段 5.7% | |

### 5.2 语义缺口（地址落在某模块声明区间内，但模块函数体不发射该块的代码）

| 地址区间 | 大小 | insn | 内容 | 落在谁的声明区间 | 证据 |
|---|---|---|---|---|---|
| 0x28bf00..0x28bf28 | 40B | 10 | ik `IK bone not found` 尾 | spine_read_ik 0x28bdd8–0x28bff8 | ik.c 只 `*error_which=1; return 0`，无 dispose/setError |
| 0x28bf28..0x28bf58 | 48B | 12 | bones `Parent bone not found` 尾 | 同上（bones 声明到 0x28bbcc 为止） | bones.c 注释引用 0x28bf28 但函数只 return 0 |
| 0x28bf58..0x28bf84 | 44B | 11 | `setlocale(NULL)` 兜底：setlocale("C")→Json_create→setlocale(NULL) | 同上 | entry.c 在 saved==0 时直接跳过 guard，不设 "C" |
| 0x28c104..0x28c130 | 44B | 11 | transform bone 尾 | spine_read_transform 0x28bff8–0x28c274 | transform.c 只回填 which=1 |
| 0x28c384..0x28c3b4 | 48B | 12 | path bone 尾 | spine_read_path 0x28c274–0x28c5e8 | path.c 只回填 which=1 |
| 0x28c3b4..0x28c3d8 | 36B | 9 | Json_create 失败尾：Json_getError→setError→返回 0 | 同上 | entry.c 只 `return 0`，不 setError |
| | **260B** | **65** | | | |

### 5.3 已覆盖但必须"只发射一次"的块

| 块 | 说明 |
|---|---|
| 0x28bdcc..0x28bdd4 | 公共收尾（add sp / vpop / pop）。物理上落在 slots 声明区间 0x28bbe4–0x28bdd8 内，但它是全函数唯一收尾；按段复制会重复弹栈 |
| 0x28bdd8 `ldr r8,[sp,#0x28]` | ik 段入口的 json 恢复，属链级状态修复 |
| 0x28ccb4 `mov r9,r11` | skins 段出口的 data 恢复，属链级状态修复 |
| 0x28c630..0x28c664 | skins 循环常量装载（default/name/path/type 串、0x55555556 魔数、data→[sp,#0x34]）在 skins 模块内，但它同时初始化 dispatch 用的 `[sp,#0x20]/[sp,#0x2c]/[sp,#0x30]`，总装时不要重复装载 |

---

## 6. 对总装批的接线建议

1. **切一层 `readSkeletonData_core` 胶水模块**，只持有：`root` 槽、`data`、`json`、段序与错误尾。段函数保持现有 0/1 + `error_which/error_name` 契约，胶水按 which 选消息与参数：
   - ik: 1→`IK bone not found: `+name，2→`Target bone not found: `+name
   - transform: 1→`Transform bone not found: `+name，2→`Target bone not found: `+name
   - path: 1→`Path bone not found: `+name，2→`Target slot not found: `+name
   错误尾统一顺序必须是 **dispose(data) → setError(json,root,msg,arg) → return 0**，与 10 个站点逐一对应；不要合并成"先 setError 再 dispose"。
2. **错误尾写成 6 个小函数而不是一个泛型**：地址 0x28bf00/0x28bf28/0x28c104/0x28c384/0x28cf3c/0x28d144/0x28d170 的 r0 来源与实参各不相同（见 §4.2），泛型化会丢返回寄存器语义。
3. **type 枚举先改再用**：把 `attach_type_e` 改成二进制序（REGION0/BBOX1/MESH2/LINKEDMESH3/PATH4），或给 `classifyAttachment` 加映射层；否则 mesh 会走进 boundingbox 的字段解析。
4. **createAttachment 与 addAttachment 之间不要插逻辑**：二进制顺序是 create → 按 `a->type(+4)` 二次分派 → 字段解析/configure → 统一 `spSkin_addAttachment`。mesh 的 `parent` 分支返回 1 表示"已入队列，仍然要 addAttachment"，不是"跳过 add"。
5. **保留原版怪癖**（差分时会打脸，别修）：
   - bones 缺键空指针（0x28b9ec）；
   - bonesCount/skinsCount 是循环内递增，slots/ik/transform/path 的 count 是入口预写 size；
   - `setlocale(NULL)` 分支设了 "C" 却不恢复；
   - linkedmesh "Skin not found" 传 root=0 → root 泄漏；
   - createAttachment 失败且 `loader->error1` 为空时静默跳过附件（0x28cf74 → 0x28cc7c）。
6. **root 只释放一次**：成功路径由 animations 段尾 0x28e7a8 释放；中间任何段都不得 dispose root。总装时把 "root 已释放" 当作后置条件断言（除 linkedmesh 泄漏路径）。
7. **公共收尾只发射一处**：所有段尾 `b 0x28bdcc` 汇入；三个 `pop` 出口中另两个（0x28bf24/0x28bf54）是 bones/ik 的专用快速返回，不要合并。
8. **建议的验证锚**（静态差分，不跑原件）：给 5 个顶层键各做"缺失/空数组/单元素"三态，共 15 条用例，断言：getItem 调用序列、malloc 行号序列、setError 站点、返回值、root dispose 次数。真值可从本 TSV 的 205 个 bl 站点直接生成期望序列。

---

## 7. 与既有文档的偏差（均以实测为准）

| 既有说法 | 实测 | 证据 |
|---|---|---|
| STATUS「决定性发现」表把 697–712 标为 slots、735–760 标为 ik、782–800 标为 transform、810–830 标为 path | 数组 malloc 行号与段的对应是：**bones=615、slots=651、ik=697(+705)、transform=735(+743)、path=782(+791)、skins=839**；表中 697 起的四行各错位一段，且 810–830 无对应锚 | 0x28bbf0/0x28bbfc（getItem "slots" 之后，dest data+0x1c）；`spSkeletonData_findIkConstraint` 0x28b240/0x28b24c 读 +0x3c/+0x40、`findTransformConstraint` 0x28b29c/0x28b2a8 读 +0x44/+0x48、`findPathConstraint` 0x28b2f8/0x28b304 读 +0x4c/+0x50、`findSkin` 0x28b12c/0x28b138 读 +0x20/+0x24 —— 与各段 malloc 的 dest 一一对应 |
| `spine_read_slots.c` 头注释 "slots segment 0x28bbcc–0x28bdd8；malloc 0x28bbfc line 651" | 与实测一致（段边界与行号都对）；但 STATUS 表里的 697 属于 ik | 同上 |
| `spine_read_entry.c` 头注释区间 "0x28b84c–0x28b9cc" | 实际 entry 代码到 0x28b8f0 的 `beq` 为止，0x28b8f4–0x28b9cc 是 meta（`spine_read_meta` 已声明） | 0x28b8f0 beq 0x28b9cc；0x28b8f4 起为 hash/spine getString |
| `attach_type_e` REGION0/MESH1/LINKEDMESH2/BOUNDINGBOX3/PATH4 | 二进制 createAttachment 的 r2：REGION0/BBOX1/MESH2/LINKED3/PATH4 | 0x28cfa0 `mov r2,#1`；0x28cf24 `mov r2,#2`；0x28cf34 `mov r2,#3`；0x28cf2c `mov r2,r0`(0)；0x28c7a0 `mov r2,#4` |
| `spine_read_entry.c` 的 setError 5 参声明 | 二进制 4 参（json, root, fmt, arg），root 由 setError dispose | 0x28b784 函数体；0x28b818–0x28b824 |
| 任务提示「错误路径已知三种 json 实参形态」 | 实测为 §3.4 的 11 站：9×root、1×0（linkedmesh）、1×loader 错误对；Json_create 失败那站虽传 root 槽但值为 0 | 0x28bdc4…0x28d190 逐站 r1 来源 |

---

## 8. 复现

```bash
# 反汇编（本批产出 1）
cd /data/data/com.termux/files/home/cally-worktrees/prague-db-20261027
python3 scripts/asm_index.py \
  --so /data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so \
  --start 0x28b84c --end 0x28d19c \
  --out reconstruction/reverse-v1/asm/segment_chain_census.tsv
# → 1620 instructions, 0x28b84c..0x28d198
```

```bash
# 段序/字符串/malloc/CFG/缺口（探针，均在 scratch）
python3 ~/.hermes/cache/scratch/wl_chainP_cfg.py     # bl 目标 + pc 相对串解析（125/74）
python3 ~/.hermes/cache/scratch/wl_chainP_malloc.py  # 18 个 malloc 站点 + 行号 + dest
python3 ~/.hermes/cache/scratch/wl_chainP_blocks.py  # 340 基本块 + 后继
python3 ~/.hermes/cache/scratch/wl_chainP_cov2.py    # 覆盖/缺口（368B/92）
python3 ~/.hermes/cache/scratch/wl_chainP_final.py   # 段大小与总数复核
```

**边界声明**：本文件只证明"字节码里有什么、模块声明覆盖到哪里"，不证明 C 模块与原件语义等价；原件未执行，ART/Unicorn/整机验证均未做。
