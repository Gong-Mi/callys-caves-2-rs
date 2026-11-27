# animations/events 段静态普查（spSkeletonJson_readSkeletonData @0x28b84c）

只读静态普查，**原件未执行**，全部结论属 `bytecode_anchored`。本文件只新建，不改任何既有文件。

| 项 | 值 |
|---|---|
| 对象 | `/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so` |
| SHA256 | `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`（已校验，与任务给定一致） |
| 函数 | `spSkeletonJson_readSkeletonData` 0x28b84c，size 13044 → 终点 0x28eb40，ARM（非 Thumb） |
| 段 | **0x28d19c .. 0x28eb40（end 排他）** |
| 反汇编 | `reconstruction/reverse-v1/asm/animations_census.tsv`（`scripts/asm_index.py` 产出） |
| 条目数 | 1641（其中 40 条是 literal pool 字，实际指令位 1601） |
| 可达指令 | 1579（从 0x28d19c 走分支/回溯可达；另 22 条落在段内但属附件的离位块，见 §1.3） |
| pc 相对键 | 73 次载入 / 46 个唯一字符串（1641 条范围内；其中 2 次载入属附件离位块 → 本段可达 71 次 / 44 个唯一串） |
| malloc 锚 | 段内 7 个（全函数 25 个） |
| bl | 149 次调用 / 52 个唯一目标 |
| 基本块 | 209（可达图）/ 31 个功能块（§6） |
| 探针 | `~/.hermes/cache/scratch/wl_animB_{strs,cfg,reach,blocks,malloc,rodata,syms,calls2,partition,final}.py` |

---

## 1. 段边界

### 1.1 结论

```
start = 0x28d19c   （ldr r1,[pc,#-0x7cc] → "events"；Json_getItem(root,"events") 的第一条）
end   = 0x28eb40   （排他；最后一条指令 0x28eb3c = b 0x28d3b4）
```

### 1.2 判定依据（三条独立证据）

1. **前驱唯一性**：全函数里指向 0x28d19c 的分支只有两条 —— `0x28ccc8: b 0x28d19c` 与 `0x28cd08: ble 0x28d19c`，都在 linked-mesh 后处理循环里（循环体调用 `spSkin_getAttachment` → `spMeshAttachment_setParentMesh` → `spMeshAttachment_updateUVs` → `spAttachmentLoader_configureAttachment`）。也就是说这块代码只从「skins/attachments 段收尾」进入。
2. **前一段以无条件跳转结束**：地址上紧邻的前一条指令是 `0x28d198: b 0x28bdcc`（"Target slot not found: " 错误路径），不存在顺序落入 0x28d19c 的可能 → 天然段界，不靠估算。
3. **段尾由符号 size 定死**：`0x28b84c + 13044 = 0x28eb40`；末尾 0x28eb3c 的 `b 0x28d3b4` 是 legacy `"draworder"` 兜底取键块回跳到动画主体（0x28d3b4 是 dispatch 链入口），仍属本段。

> 与任务给出的提示不一致处（以实测为准）：预设的「linked-mesh queue writer 在 0x28cc2c..0x28cc64 之后收尾」不成立。该 writer 的实际循环出口在 0x28ccc8 / 0x28cd08，0x28cc2c 一带仍在附件段的 mesh 读法里。段尾也不是「由 linked-mesh 后处理收尾」，而是 animations 的 `Json_dispose`(0x28e7a8) + `b 0x28bdcc`，且 0x28e7a4 之后还有一段附件段的离位错误块。

### 1.3 段内不属于本段的地址（恢复时不要吞）

| 区间 | 条数 | 归属 | 证据 |
|---|---|---|---|
| 0x28e7f4..0x28e820 | 11 | 附件段 | 块尾 `setError("Unknown attachment type: ")` + `spSkeletonData_dispose` + `b 0x28bdcc`；从 0x28d19c 不可达 |
| 0x28e880..0x28e8ac | 11 | 附件段 | `setError("Parent mesh not found: ")`；从 0x28d19c 不可达 |
| 0x28ea88..0x28eb28 | 40 | literal pool | 全部被段内 `ldr rX,[pc,#imm]` 引用（0x28eb28 前的 10 个字即 0x28eaf4..0x28eb24 那批 `andeq/muleq` 假指令） |

1601 = 1579（可达）+ 22（上表前两行）；40 个池字是数据不是指令。asm_index 把这些池字解码成 `andeq/muleq/strheq` 等，引用时不要当控制流。

---

## 2. pc 相对字符串键（73 次载入 / 46 个唯一串）

解析方法：`ldr rX,[pc,#imm]` → `pool = load_site+8+imm`；配对的 `add rY,pc,rX` → `va = add_site+8+word`；从 va 读 C 串。全部 73 次配对本段内 100% 命中（无未解析的 pooled load）。

### 2.1 B1 骨架级 events（行 1028/1034）

| load | pool | add | va | 字符串 |
|---|---|---|---|---|
| 0x28d19c | 0x28c9d8 | 0x28d1a4 | 0x357d94 | `events` |
| 0x28d1bc | 0x28c9dc | 0x28d1c4 | 0x357b08 | `jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c`（malloc tag） |
| 0x28d1e0 | 0x28c9e0 | 0x28d1f0 | 0x357e58 | `int` |
| 0x28d1e8 | 0x28c9e4 | 0x28d1f4 | 0x330830 | `string` |
| 0x28d1ec | 0x28c9e8 | 0x28d1fc | 0x357b08 | malloc tag（第二次） |
| 0x28d200 | 0x28c9ec | 0x28d204 | 0x330828 | `float` |

### 2.2 B2/B3 animations 数组与单动画前置

| load | pool | add | va | 字符串 |
|---|---|---|---|---|
| 0x28d290 | 0x28c9f0 | 0x28d298 | 0x357e4c | `animations` |
| 0x28d2b0 | 0x28c9f4 | 0x28d2b8 | 0x357b08 | malloc tag |
| 0x28d2d4 | 0x28c9f8 | 0x28d2e4 | 0x357b88 | `bones` |
| 0x28d2dc | 0x28c9fc | 0x28d2f0 | 0x357b90 | `slots` |
| 0x28d2e8 | 0x28ca00 | 0x28d2f8 | 0x357bfc | `ik` |
| 0x28d2f4 | 0x28ca04 | 0x28d300 | 0x357c48 | `transform` |
| 0x28d354 | 0x28ca08 | 0x28d358 | 0x357e5c | `paths` |
| 0x28d368 | 0x28ca0c | 0x28d36c | 0x357de4 | `deform` |
| 0x28d37c | 0x28ca10 | 0x28d380 | 0x357e64 | `drawOrder`（新键） |
| 0x28d390 | 0x28ca14 | 0x28d394 | 0x357d94 | `events`（动画级） |
| 0x28eb28 | 0x28eb24 | 0x28eb30 | 0x357e70 | `draworder`（legacy 兜底键，离位块） |

### 2.3 B5 slots 时间线（attachment / color）

| load | pool | add | va | 字符串 |
|---|---|---|---|---|
| 0x28d4ec | 0x28ca18 | 0x28d4f8 | 0x330810 | `name` |
| 0x28d4f0 | 0x28ca1c | 0x28d500 | 0x34c1d4 | `time` |
| 0x28d4f4 | 0x28ca20 | 0x28d508 | 0x357c18 | `color` |
| 0x28d4fc | 0x28ca24 | 0x28d50c | 0x330944 | `attachment` |
| 0x28d504 | 0x28ca28 | 0x28d514 | 0x357c18 | `color`（第二份，颜色帧用） |
| 0x28d8fc | 0x28ca54 | 0x28d908 | 0x34c1d4 | `time`（颜色帧） |
| 0x28da2c | 0x28ca58 | 0x28da3c | 0x357e90 | `Invalid timeline type for a slot: ` |

### 2.4 B6 bones 时间线（rotate/translate/scale/shear）

| load | pool | add | va | 字符串 |
|---|---|---|---|---|
| 0x28d65c | 0x28ca2c | 0x28d664 | 0x357ec8 | `rotate` |
| 0x28d660 | 0x28ca30 | 0x28d670 | 0x357ed0 | `scale` |
| 0x28d668 | 0x28ca34 | 0x28d678 | 0x357ed8 | `translate` |
| 0x28d674 | 0x28ca38 | 0x28d680 | 0x357ee4 | `shear` |
| 0x28d67c | 0x28ca3c | 0x28d688 | 0x34c1d4 | `time` |
| 0x28d750 | 0x28ca40 | 0x28d75c | 0x33087c | `x` |
| 0x28d758 | 0x28ca44 | 0x28d760 | 0x330880 | `y` |
| 0x28da90 | 0x28ea88 | 0x28da9c | 0x34c1d4 | `time`（rotate） |
| 0x28da98 | 0x28ea8c | 0x28daa0 | 0x330884 | `angle`（rotate 专用） |
| 0x28db6c | 0x28ea90 | 0x28db7c | 0x357eb4 | `Bone not found: ` |
| 0x28db98 | 0x28ea94 | 0x28dba8 | 0x357eec | `Invalid timeline type for a bone: ` |

### 2.5 B7 ik 约束

| load | pool | add | va | 字符串 |
|---|---|---|---|---|
| 0x28d85c | 0x28ca48 | 0x28d868 | 0x34c1d4 | `time` |
| 0x28d860 | 0x28ca4c | 0x28d86c | 0x357c98 | `mix` |
| 0x28d864 | 0x28ca50 | 0x28d874 | 0x357c88 | `bendPositive` |

### 2.6 B12 transform / B13 path

| load | pool | add | va | 字符串 |
|---|---|---|---|---|
| 0x28dcc4 | 0x28ea98 | 0x28dccc | 0x34c1d4 | `time` |
| 0x28dcc8 | 0x28ea9c | 0x28dcd8 | 0x357cc0 | `rotateMix` |
| 0x28dcd0 | 0x28eaa0 | 0x28dce0 | 0x357ccc | `translateMix` |
| 0x28dcdc | 0x28eaa4 | 0x28dce8 | 0x357cdc | `scaleMix` |
| 0x28dce4 | 0x28eaa8 | 0x28dcf0 | 0x357ce8 | `shearMix` |
| 0x28de90 | 0x28eaac | 0x28de9c | 0x357d80 | `position` |
| 0x28de98 | 0x28eab0 | 0x28dea8 | 0x34c1d4 | `time` |
| 0x28deac | 0x28eab4 | 0x28deb8 | 0x357d8c | `spacing` |
| 0x28deb0 | 0x28eab8 | 0x28debc | 0x357d8c | `spacing`（第二份） |
| 0x28deb4 | 0x28eabc | 0x28dec4 | 0x357c98 | `mix` |
| 0x28ea58 | 0x28eb20 | 0x28ea68 | 0x357f10 | `Path constraint not found: ` |

### 2.7 B14 deform / B15 drawOrder

| load | pool | add | va | 字符串 |
|---|---|---|---|---|
| 0x28e080 | 0x28eac0 | 0x28e090 | 0x357b08 | malloc tag |
| 0x28e088 | 0x28eac4 | 0x28e098 | 0x357afc | `vertices` |
| 0x28e08c | 0x28eac8 | 0x28e09c | 0x357f44 | `offset` |
| 0x28e094 | 0x28eacc | 0x28e0a4 | 0x34c1d4 | `time` |
| 0x28e36c | 0x28ead0 | 0x28e378 | 0x357f4c | `offsets` |
| 0x28e37c | 0x28ead4 | 0x28e388 | 0x357b08 | malloc tag |
| 0x28e384 | 0x28ead8 | 0x28e394 | 0x357f54 | `slot` |
| 0x28e38c | 0x28eadc | 0x28e398 | 0x357f44 | `offset` |
| 0x28e390 | 0x28eae0 | 0x28e3a0 | 0x34c1d4 | `time` |
| 0x28e574 | 0x28eae4 | 0x28e584 | 0x357f2c | `Attachment not found: ` |
| 0x28e8d0 | 0x28eb0c | 0x28e8d8 | 0x357e7c | `Slot not found: `（drawOrder 内） |
| 0x28ea30 | 0x28eb1c | 0x28ea34 | 0x357e7c | `Slot not found: `（slot 循环内） |

### 2.8 B16 event 时间线

| load | pool | add | va | 字符串 |
|---|---|---|---|---|
| 0x28e63c | 0x28eae8 | 0x28e648 | 0x34c1d4 | `time` |
| 0x28e644 | 0x28eaec | 0x28e654 | 0x330810 | `name` |
| 0x28e64c | 0x28eaf0 | 0x28e65c | 0x357e58 | `int` |
| 0x28e658 | 0x28eaf4 | 0x28e660 | 0x330828 | `float` |
| 0x28e668 | 0x28eaf8 | 0x28e66c | 0x330830 | `string` |
| 0x28e6f8 | 0x28eafc | 0x28e700 | 0x357b08 | malloc tag |
| 0x28e7d8 | 0x28eb00 | 0x28e7e0 | 0x357f5c | `Event not found: ` |

### 2.9 键面观察

- **`drawOrder` 有新旧两个键**：先取 `"drawOrder"`(0x28d380)，为 NULL 时跳到离位块 0x28eb28 取 legacy `"draworder"`(0x28eb30)，再回到 0x28d3b4。两键都在时新键优先。C 恢复必须保留这个 fallback。
- **`color` 走 hex 字符串通道**，不是数组：0x28d92c `Json_getString(frame,"color")` → 0x28b680(char*, idx) ×4（idx=0..3）→ float。段内没有 `"rgba"`/`"color"` 数组读法（`Json_getFloat` 在这条路上只用于 `time`）。这与 stock spine-c 3.x 的 `"color":[r,g,b,a]` 形状不同，是版本分歧的直接证据。
- **`time` 被载入 11 次**（每个时间线族各一份），`color` 与 `spacing` 各 2 份、`offset` 2 份、`offsets` 1 份 —— 说明编译器没有做字符串常量合并到单一寄存器的复用，按块恢复时每块各自带一份字面量是对的。
- **曲线键 `"curve"` 不在本段**：全函数 198 次 pooled load 里没有任何 `"curve"`；它由同文件的匿名 helper **0x28b34c** 读取（该函数内 `"curve"`@0x357aec、`"stepped"`@0x357af4），段内 8 次 `bl 0x28b34c`（每个可插值时间线的帧循环一次）。
- 46 个唯一串的构成：36 个 JSON 键 + 1 个 malloc tag 串 + 7 条本段错误文案 + 2 条附件段错误文案（`Unknown attachment type: `@0x28e800、`Parent mesh not found: `@0x28e88c`，落在 §1.3 的离位块里，其 2 次载入已算在 73 内）。

---

## 3. malloc 锚

### 3.1 段内 7 个（`_malloc(size, tag, line)`，r2=line）

| call site | line | 归属块 | 观察到的 size 表达式 |
|---|---|---|---|
| 0x28d1cc | 1028 | B1 | `eventsCount * 4`（Json size，`lsl #2`）→ `data->events`（存 `[r9,#0x30]`，count 存 `[r9,#0x2c]`） |
| 0x28d268 | 1034 | B1 | `strlen(name)+1`（EventData 的 `string` 字段深拷贝） |
| 0x28d2bc | 1043 | B2 | `animationsCount * 4` → `data->animations`（存 `[r9,#0x38]`） |
| 0x28e154 | 388 | B14 | `r11*4`，`r11 = 2*(vertexCount/3)`（0x55555556 magic + `smull`/`asr#31`，signed /3） |
| 0x28e3e0 | 442 | B15 | `(slotsCount - jsonOffsetsSize) * 4`（`rsb r0,r3,r0` + `lsl #2`） |
| 0x28e3f8 | 445 | B15 | `slotsCount * 4`，随后整块填 `-1`（`mvn r0,#0`，循环 0x28e414） |
| 0x28e708 | 494 | B16 | `strlen(name)+1`（事件帧 name 深拷贝，存 `[r4,#0x10]`） |

### 3.2 全函数 25 个锚的补全

`cards/malloc-line-anchors-readSkeletonData.json` 里有 3 个 site 的 line 是 `None`，原因是编译器用了 `mov r2,#imm` 而不是 `movw r2,#imm`（卡片提取只认 movw）。本次从指令流补出：

| call site | 卡片 | 实测 |
|---|---|---|
| 0x28b974 | line = null | **608**（`0x28b96c: mov r2,#608`） |
| 0x28cfd4 | line = null | **136**（`0x28cfcc: mov r2,#136`） |
| 0x28e154 | line = null | **388**（`0x28e150: mov r2,#388`） |

其余 22 个与卡片逐字一致（607 615 651 697 705 735 743 782 791 839 985 917 891 935 941 954 1028 1034 1043 442 445 494）。

**语义提示**：行号 < 600 的 4 个锚（136 / 388 / 442 / 445 / 494 中的前四个）落在 `readSkeletonData` 之前的同文件 helper 里，说明这些 helper 被内联进了本函数、且内联副本被放在函数尾部/离位处。605 以下的锚点**不能**用来给 readSkeletonData 分段（只有 607..1043 是本体的行号区间）。

---

## 4. bl 被调清单（52 unique / 149 次）

| 目标 | 符号 | 次数 | 站点 |
|---|---|---|---|
| 0x287444 | Json_getFloat | 24 | 28d238 28d5b4 28d774 28d788 28d7a0 28d940 28dab8 28dacc 28dbec 28dc00 28dd8c 28dda0 28ddb4 28ddc8 28dddc 28dfb4 28dfc8 28e284 28e5a0 28e6a4 28e6d4 28e958 28e970 28e984 |
| 0x2873c4 | Json_getItem | 14 | 28d1a8 28d29c 28d320 28d330 28d340 28d350 28d364 28d378 28d38c 28d3a0 28d5a0 28e1a4 28e3bc 28eb34 |
| 0xb6574 | strcmp@plt | 10 | 28d558 28d56c 28d6cc 28d6e0 28d6f4 28d708 28df48 28df5c 28e530 28e8f4 |
| 0x28b784 | _spSkeletonJson_setError | 10 | 28da40 28db80 28dbac 28e588 28e7ec 28e814 28e8a0 28e8e4 28ea38 28ea6c |
| 0x28147c | spAnimation_dispose | 8 | 28da28 28db68 28db94 28e570 28e7c4 28e8bc 28ea1c 28ea54 |
| 0x28b34c | **匿名：readCurve**（"curve"/"stepped"） | 8 | 28d7d0 28d9b0 28daf0 28dc48 28de0c 28dff4 28e2a8 28e9b0 |
| 0x285c10 | _malloc | 7 | 28d1cc 28d268 28d2bc 28e154 28e3e0 28e3f8 28e708 |
| 0x287428 | Json_getString | 7 | 28d24c 28d92c 28e44c 28e680 28e6e8 28e7d4 28e8cc |
| 0x287460 | Json_getInt | 5 | 28d224 28dc14 28e1c0 28e4a8 28e6c0 |
| 0x28b680 | **匿名：hex 颜色分量读**（char*,idx）→float | 4 | 28d950 28d960 28d970 28d980 |
| 0xb65b0 | memset@plt | 3 | 28e1dc 28e238 28e840 |
| 0x285c80 | _free | 3 | 28e2c8 28e524 28e5c0 |
| 0x28adf8 | spSkeletonData_dispose | 3 | 28da48 28e7fc 28e888 |
| 0x28b0cc | spSkeletonData_findSlotIndex | 3 | 28d52c 28e0e4 28e458 |
| 0xb6538 | strlen@plt | 2 | 28d258 28e6f4 |
| 0xb65a4 | strcpy@plt | 2 | 28d274 28e714 |
| 0x2812b4 | spAnimation_create | 1 | 28d4c4 |
| 0x285b94 | spEventData_create | 1 | 28d210 |
| 0x285b44 | spEvent_create | 1 | 28e6ac |
| 0x282b94 | spAttachmentTimeline_create | 1 | 28d57c |
| 0x282c1c | spAttachmentTimeline_setFrame | 1 | 28d5d8 |
| 0x282b3c | spColorTimeline_create | 1 | 28d8e0 |
| 0x282b54 | spColorTimeline_setFrame | 1 | 28d9a0 |
| 0x282abc | spTranslateTimeline_create | 1 | 28da68 |
| 0x282ad4 | spTranslateTimeline_setFrame | 1 | 28d7c0 |
| 0x282a90 | spRotateTimeline_create | 1 | 28da78 |
| 0x282aa8 | spRotateTimeline_setFrame | 1 | 28dae0 |
| 0x282b04 | spScaleTimeline_create | 1 | 28db50 |
| 0x282b20 | spShearTimeline_create | 1 | 28dbbc |
| 0x282f74 | spIkConstraintTimeline_create | 1 | 28d890 |
| 0x282f8c | spIkConstraintTimeline_setFrame | 1 | 28dc38 |
| 0x282fb8 | spTransformConstraintTimeline_create | 1 | 28dd14 |
| 0x282fd0 | spTransformConstraintTimeline_setFrame | 1 | 28ddfc |
| 0x283010 | spPathConstraintPositionTimeline_create | 1 | 28df6c |
| 0x283028 | spPathConstraintPositionTimeline_setFrame | 1 | 28dfe4 |
| 0x28303c | spPathConstraintSpacingTimeline_create | 1 | 28e540 |
| 0x283068 | spPathConstraintMixTimeline_create | 1 | 28e904 |
| 0x283080 | spPathConstraintMixTimeline_setFrame | 1 | 28e9a0 |
| 0x282e58 | spDeformTimeline_create | 1 | 28e164 |
| 0x282ef8 | spDeformTimeline_setFrame | 1 | 28e298 |
| 0x282d4c | spDrawOrderTimeline_create | 1 | 28e354 |
| 0x282ddc | spDrawOrderTimeline_setFrame | 1 | 28e5b8 |
| 0x282c8c | spEventTimeline_create | 1 | 28e624 |
| 0x282d14 | spEventTimeline_setFrame | 1 | 28e728 |
| 0x28b018 | spSkeletonData_findBoneIndex | 1 | 28d6a0 |
| 0x28b124 | spSkeletonData_findSkin | 1 | 28e0c0 |
| 0x28b180 | spSkeletonData_findEvent | 1 | 28e68c |
| 0x28b238 | spSkeletonData_findIkConstraint | 1 | 28d884 |
| 0x28b294 | spSkeletonData_findTransformConstraint | 1 | 28dd08 |
| 0x28b2f0 | spSkeletonData_findPathConstraint | 1 | 28dedc |
| 0x28ed00 | spSkin_getAttachment | 1 | 28e108 |
| 0x2872c8 | Json_dispose | 1 | 28e7a8 |

归类：Json_* 50 次；timeline `*_create` 14 个符号，加 `spAnimation_create` 与 `spEvent_create`/`spEventData_create` 共 17 次 create；`*_setFrame` 11 个符号；`spSkeletonData_find*` 7 个；错误/清理 13 次（setError 10 + spSkeletonData_dispose 3），另有 spAnimation_dispose 8 次（错误路径回收）。
**0x28b34c / 0x28b680 没有符号**（0x28b2f0 `spSkeletonData_findPathConstraint` size=92 之后、0x28b700 `spSkeletonJson_createWithLoader` 之前的匿名函数），objdump 只能标成 `findPathConstraint+0x5c/+0x390`。这两个必须单独立项，不能当既有库函数。该空隙里还有第三个匿名函数 **0x28b3fc**（`push {r4-r11,lr}`，读 `"vertices"`@0x357afc，内有两个 malloc tag 载入），**本段不调用它**，不应算进本批依赖。

---

## 5. 控制流骨架

### 5.1 没有 switch 跳表

段内 `add pc,pc,rX,lsl#2` = **0**，`ldr pc,[pc,...]` = **0**，`tbb/tbh` = **0**（对整个 1641 条条目统计）。
类型分派全部是 **strcmp 链**：`strcmp@plt` ×10（slot 2 + bone 4 + 3 处改判定），判定结果落 `beq/bne` 到各组 reader。所以「表项落点」问题在本段不存在；恢复时不存在跳表边界要维护。

### 5.2 段级流水线（地址顺序＝源序）

```
B1 events 数组 ──beq(空)──► B2
B2 animations 数组 ──beq(空)──► B18 收尾
B3 每动画前置(8 key) ─► B3b(legacy draworder 兜底) ─► B4 timelineCount 求和 + spAnimation_create
   └─► 槽循环 B5(attachment) / B8(color) ─► bones B6/B6b ─► ik B7/B7b ─► transform B12
        ─► paths B13 ─► deform B14/B14b ─► drawOrder B15/B15b ─► event B16 ─► B18
B18: Json_dispose(0x28e7a8) + b 0x28bdcc   ← 与骨骼/IK 段共用同一收尾
```

每级「sub-node 为 NULL 就跳到下一级」的链：`0x28d648→0x28d840→0x28dca8→0x28de74→0x28e060→0x28e338→0x28e614→0x28e774`。

### 5.3 循环（回边实测）

| 循环头 | 回边来源 | 职责 |
|---|---|---|
| 0x28d20c | 0x28d28c | 骨架 events 数组遍历（spEventData_create 每项） |
| 0x28d318 | 0x28e79c | 每个 animation（外层；计数写 `[r9,#0x34]`、元素写 `[r9,#0x38]` 在 0x28e778） |
| 0x28d3d0 / 0x28d3f8 / 0x28d44c / 0x28d484 / 0x28d478 | 0x28d3e0 / 0x28d408 / 0x28d45c / 0x28d494 / 0x28d4a0 | timelineCount 五次求和（bones/slots/ik/transform/paths/deform/drawOrder/events 的子表大小累加） |
| 0x28d520 | 0x28d63c | slots 子节点遍历（findSlotIndex；-1 → "Slot not found"） |
| 0x28d54c | 0x28d628 | 每个 slot 下的时间线（color/attachment 分派） |
| 0x28d598 | 0x28d5e4 | attachment 帧（`time` + 附件名） |
| 0x28d698 | 0x28d834 | bones 子节点遍历（findBoneIndex；-1 → "Bone not found"） |
| 0x28d6c0 | 0x28d824 | 每骨下的时间线（rotate/translate/scale/shear） |
| 0x28d768 | 0x28d7e0 | bone 帧（x/y/time），scale/shear 复用同一 setFrame |
| 0x28d920 | 0x28d9c0 | color 帧（time + 4 次 hex 分量） |
| 0x28daa8 | 0x28db04 | rotate 帧（time + angle） |
| 0x28dbe0 | 0x28dc58 | ik 帧（time + mix + bendPositive） |
| 0x28dd00 / 0x28dd44 / 0x28dd7c | 0x28de70 / 0x28dd58 / 0x28de20 | transform 约束（类型判定 + 5 值帧） |
| 0x28ded4 / 0x28df10 / 0x28df3c / 0x28dfa4 | 0x28e05c / 0x28df24 / 0x28e050 / 0x28e008 | path 约束（position/spacing/mix 三条帧循环） |
| 0x28e0fc / 0x28e19c / 0x28e20c / 0x28e258 | 0x28e30c / 0x28e2c0 / 0x28e220 / 0x28e270 | deform（skin→slot→attachment→帧→顶点） |
| 0x28e3b4 / 0x28e440 / 0x28e47c / 0x28e4d8 / 0x28e500 / 0x28e414 | 0x28e594 / 0x28e4c0 / 0x28e48c / 0x28e4f0 / 0x28e51c / 0x28e420 | drawOrder（帧→offsets→slot 索引→填 -1） |
| 0x28e674 | 0x28e734 | event 帧（time + name/int/float/string） |
| 0x28e948 | 0x28e9c4 | path mix 帧（time + rotateMix/translateMix） |

### 5.4 错误块（全部以 `spAnimation_dispose` + `spSkeletonData_dispose` + `setError` + `b 0x28da44`/`b 0x28bdcc` 收束）

| 块 | 文案 | 收束 |
|---|---|---|
| 0x28da18 | `Invalid timeline type for a slot: ` | dispose(0x28da28) → setError(0x28da40) → b 0x28bdcc |
| 0x28db5c | `Bone not found: ` | dispose(0x28db68) → setError(0x28db80) → b 0x28da44 |
| 0x28db88 | `Invalid timeline type for a bone: ` | dispose(0x28db94) → setError(0x28dbac) → b 0x28da44 |
| 0x28e55c | `Attachment not found: ` | dispose(0x28e570) → setError(0x28e588) → b 0x28da44 |
| 0x28e7b4 | `Event not found: ` | dispose(0x28e7c4) → getString → setError(0x28e7ec) → b 0x28da44 |
| 0x28e8ac | `Slot not found: ` | dispose(0x28e8bc) → getString → setError(0x28e8e4) → b 0x28da44 |
| 0x28ea10 | `Slot not found: ` | dispose(0x28ea1c) → setError(0x28ea38) → b 0x28da44 |
| 0x28ea48 | `Path constraint not found: ` | dispose(0x28ea54) → setError(0x28ea6c) → b 0x28da44 |

`0x28da44` 是错误公共尾：`spSkeletonData_dispose(0x28da48)` + `b 0x28bdcc`（返回 NULL）。
段内**没有** `Ik constraint not found` / `Transform constraint not found` / `Skin not found` 文案（后两条属附件段），这直接说明 IK/transform 查找结果在该 build 里不判空（见 §7）。

---

## 6. 可独立恢复分块表（31 块，1579 条可达指令，逐块不重叠，合计对上）

| 块 | 入口 | 大小(B) | insn | 源行线索 / 关键 |
|---|---|---|---|---|
| B1 骨架级 events 数组 + EventData 循环 | 0x0028d19c | 244 | 61 | malloc 1028/1034；循环头 0x28d20c |
| B2 animations 数组分配 | 0x0028d290 | 68 | 17 | malloc 1043 |
| B3 单动画前置：8 个 key 指针缓存 | 0x0028d2d4 | 224 | 56 | 无 malloc；0x28d2d8/0x28d2e0 magic 0x55555556 |
| B4 timelineCount 求和 + spAnimation_create | 0x0028d3b4 | 312 | 78 | 无 malloc；累加循环 0x28d3d0/0x28d3f8 |
| B5 slots 时间线循环（attachment 读法） | 0x0028d4ec | 340 | 85 | 循环头 0x28d520；帧循环 0x28d598 |
| B6 bones 时间线循环头 + 类型 strcmp 分派 | 0x0028d640 | 256 | 64 | 循环头 0x28d698 |
| B6b bone 时间线帧循环（x/y/time） | 0x0028d740 | 256 | 64 | 循环头 0x28d768 |
| B7 ik 约束时间线（构造 + 指针扫描求索引） | 0x0028d840 | 156 | 39 | 0x28d884 findIkConstraint / 0x28d890 create / 0x28d89c..0x28d8d8 在 `[data+0x3c]/[data+0x40]` 里按指针线性找索引，写 `timeline+0x14` |
| B8 slots color 时间线（hex 颜色串） | 0x0028d8dc | 248 | 62 | 循环头 0x28d920；0x28b680 ×4 |
| B8b color/attachment 公共尾（readCurve 调用） | 0x0028d9d4 | 68 | 17 | 回边 b 0x28d620 |
| E1 错误：Invalid timeline type for a slot | 0x0028da18 | 60 | 15 | 0x28da18 |
| B9 translate 时间线构造 | 0x0028da54 | 32 | 8 | 0x28da68 create |
| B10 rotate 时间线（angle 键） | 0x0028da74 | 212 | 53 | 帧循环 0x28daa8 |
| B11 scale/shear 选择 | 0x0028db48 | 20 | 5 | 0x28db48 s16=1.0 |
| E2 错误：Bone not found | 0x0028db5c | 44 | 11 | 0x28db5c |
| E3 错误：Invalid timeline type for a bone | 0x0028db88 | 44 | 11 | 0x28db88 |
| B11b shear 时间线构造 | 0x0028dbb4 | 28 | 7 | 0x28dbbc create |
| B7b ik 时间线帧循环 | 0x0028dbd0 | 216 | 54 | 循环头 0x28dbe0；0x28dc38 setFrame |
| B12 transform 约束时间线 | 0x0028dca8 | 460 | 115 | 帧循环 0x28dd7c |
| B13 path 约束时间线（position/spacing/mix） | 0x0028de74 | 492 | 123 | 帧循环 0x28dfa4 |
| B14 deform 时间线 | 0x0028e060 | 728 | 182 | malloc 388；帧循环 0x28e19c |
| B15 drawOrder 时间线（前半） | 0x0028e338 | 548 | 137 | malloc 442/445；帧循环 0x28e3b4 |
| E4 错误：Attachment not found + 公共错误尾 | 0x0028e55c | 56 | 14 | 0x28e55c |
| B15b drawOrder 帧循环尾 + setFrame | 0x0028e594 | 128 | 32 | 循环头 0x28e3b4 |
| B16 event 时间线 | 0x0028e614 | 400 | 100 | 循环头 0x28e674；malloc 494 |
| E5 错误：Event not found | 0x0028e7b4 | 64 | 16 | 0x28e7b4 |
| B14b deform vertices 分支（离位块） | 0x0028e820 | 96 | 24 | 0x28e820 memset+拷贝 |
| E6 错误：Slot not found（deform 路径） | 0x0028e8ac | 64 | 16 | 0x28e8ac |
| B17 path mix 时间线 + 错误块 | 0x0028e8ec | 412 | 103 | 循环头 0x28e948 |
| B18 结束：Json_dispose + 回公共收尾 | 0x0028e7a4 | 16 | 4 | 0x28e7a8 Json_dispose |
| B3b legacy 'draworder' 兜底取键块（离位） | 0x0028eb28 | 24 | 6 | 0x28eb30 'draworder' |

合计 1579 = 段内可达指令数（探针核对：`assigned=1579 reachable_in_segment=1579`）。
建议恢复顺序（依赖由少到多）：B1 → B2 → B3/B3b → B4 → B5/B8 → B6/B6b/B9/B10/B11/B11b → B7/B7b → B12 → B13 → B14/B14b → B15/B15b → B16 → 8 个 E 块 → B18。每块只依赖 `<type>_create/setFrame`、`Json_*`、`spSkeletonData_find*`，互不依赖，可并行；`readCurve(0x28b34c)` 与 hex 颜色读(0x28b680) 是两块的公共前置，应先做或明确桩掉。

---

## 7. Open questions（明确未闭合，不猜）

1. **spTimeline 家族无虚派发证据**：段内 14 个 timeline `*_create` + 11 个 `*_setFrame` 全是直接 `bl` 符号，无函数指针表、无跳表。但 `spAnimation_dispose`(0x28147c) 如何按 `timelineType` 释放、以及 `animation->timelines[i]` 的类型标签写在哪个字段，本段只看到 `str timeline,[r1,r3,lsl#2]`（0x28e78c）与计数 `[r9,#0x34]`，未看到类型写入 → 需在 dispose 侧单独立项。
2. **curves 数据形状**：`"curve"` 只在同文件匿名函数 **0x28b34c** 内被读（另有 `"stepped"`），段内 8 次调用点。该函数 0x28b34c 起（同一 948B 空隙 0x28b34c..0x28b700 里还有匿名 0x28b3fc 与 0x28b680）本次未逐条普查；"curve" 是 4 元素数组还是字符串、与 `spCurveTimeline_setCurve` 的参数合同，均为 open。
3. **hex 颜色通道**：`color` 用 `Json_getString` + 0x28b680(char*,0..3) 取分量，与 stock spine-c 3.x 的 `[r,g,b,a]` 数组不同；0x28b680 的解析细节（十六进制、分量顺序、缺省值、非法字符处理）未展开 → open。这条直接影响 slot color / color timeline 两块。
4. **drawOrder 的两次 malloc 所有权**：行 442 `(slotsCount - jsonOffsetsSize)*4` 与行 445 `slotsCount*4`（填 -1）谁交给 `spDrawOrderTimeline_setFrame`、谁负责 free，段内只能看到 0x28e524/0x28e5c0 的 `_free` 在两个分支上，需与 setFrame 实现对照 → open。
5. **deform 的顶点数换算**：行 388 的 `r11 = 2*(vertexCount/3)`（signed /3）用途未定：weighted / 非 weighted 顶点的分支条件、以及 `spDeformTimeline_create(frameCount, r11)` 第二参语义 → open。
6. **ik / transform 查找不判空，改用指针线性扫描求索引**：0x28d884 `findIkConstraint` 返回**指针**（放 r5），随后不判空，而是在 `data->ikConstraints`（count `[data+0x3c]`、数组 `[data+0x40]`）里逐元素比指针，命中写 `timeline+0x14 = index`（0x28dbc8/0x28dbcc）；未命中则整段跳过、`+0x14` 保持 create 的初值。transform 同构（count `[data+0x44]`、数组 `[data+0x48]`，0x28dd1c..0x28dd50）。全库无对应 "not found" 文案 → 名称不存在时 `+0x14` 的取值、以及 create 是否把 `+0x14` 置 -1，仍 open（恢复时不能写成判空分支）。
7. **事件帧 name 二次拷贝**：0x28e6f4 strlen + 0x28e708 malloc(494) + 0x28e714 strcpy → 写 `[r4,#0x10]`，而 `spEvent_create` 已在 0x28e6ac 返回该对象。这是 `spEvent.stringValue` 的深拷贝还是另一字段，与 `spEvent_dispose` 是否双释放 → open。
8. **`[sp,#0x60]` 的 0x55555556 常量**：只在 0x28d304 写入、0x28e128 读取（deform 顶点除 3）。是否还被 B13/B17 复用、以及有符号性边界 → open（当前只证 signed /3）。
9. **栈槽语义未定名**：sp+0x60..sp+0x74 只在前置块写、后续按块复用（`key 指针缓存` 与 `临时` 混用），逐块恢复时要按块重新标注；本次只给了读写点，不给命名结论。
10. **animationsCount 的一致性**：计数 `[data+0x34]` 与数组 `[data+0x38]` 只在循环尾自增写入（0x28e778..0x28e78c）；中途出错走 `spSkeletonData_dispose` 整包回收，计数不回滚。错误路径的可见状态 → open。
11. **`prerequisite`：段内 22 条附件离位块**（0x28e7f4..0x28e820、0x28e880..0x28e8ac）如果按地址顺序做 C 直译会被误算进本段；恢复时必须按 §1.3 排除，否则会和附件段重复定义。
12. **版本分歧**：`drawOrder`/`draworder` 双键 + hex color + `paths`（而非 `path`）+ `bendPositive` 的组合，与 STATUS「版本混合/定制」一致；本段不能照抄任一 stock 版本，需按本表逐块落 C。

---

## 8. 复核方式（全部只读，不执行原件）

```bash
cd /data/data/com.termux/files/home/cally-worktrees/prague-db-20261027
python3 scripts/asm_index.py --so <libyoyo_armv7.so> --start 0x28d19c --end 0x28eb40 \
        --out /tmp/anim_check.tsv && wc -l /tmp/anim_check.tsv      # 1641
python3 ~/.hermes/cache/scratch/wl_animB_strs.py /tmp/anim_check.tsv   # 键/pool 解析
python3 ~/.hermes/cache/scratch/wl_animB_reach.py /tmp/anim_check.tsv reach 0x28d19c  # 可达 1582（含段外 3 条收尾）
python3 ~/.hermes/cache/scratch/wl_animB_partition.py                  # 31 块，assigned=1579
python3 ~/.hermes/cache/scratch/wl_animB_malloc.py <full-tsv>          # 25 个 malloc 行号
```

与产出 TSV 的差异应为 0（同一脚本、同一区间）。
