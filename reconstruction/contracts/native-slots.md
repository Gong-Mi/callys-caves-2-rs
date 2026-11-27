# Slots 段两处旧偏差的纠正（blend 映射 / creator-NULL 早退）

## 身份与范围

原件 libyoyo ARM32 SHA256：
`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
按 METHOD 静态前置：原件只读，无原件执行、ART、Unicorn 或前台操作。执行对象仅为重建 ARM32 C。

范围：`spSkeletonJson_readSkeletonData` 的 slots 段（`0x28bbcc–0x28bdd8`，含循环条件 `0x28bd7c`）。
本批不改 `readSkeletonData_slotsArray`（malloc line 651 锚点维持）；只纠正
`readSkeletonData_oneSlot`（`0x28bc5c` body）里两处与原件不符的旧译文。

符号锚（.dynsym/.symtab 双查，value/size 全钉）：
`spSlotData_create@0x28ef2c`(124)、`spSlotData_setAttachmentName@0x28efcc`(80)、
`Json_getItem@0x2873c4`(100)、`Json_getString@0x287428`(28)、
`spSkeletonData_findBone@0x28afbc`(92)、`spSkeletonJson_readSkeletonData@0x28b84c`(13044)、
`_malloc@0x285c10`(60)。

## 偏差一（F1）：blend 模式映射反了 + 无条件默认写

旧译文把三个 strcmp 命中写成 `additive→3 / multiply→1 / screen→2`，并且声明
`blend_mode=0` 默认值后**无条件**写 `slotData+0x20`。两条都与原字相反：

- 原件第一个比较串是 `additive`（`0x28bc40 ldr r0,[pc,#0xc0c]`→pool `0x28c854`→`0x357c28`，
  溢出到 `[sp,#0x20]` 供 `0x28bd14` 第一次 strcmp），命中存 **1**
  （`0x28bd1c 03a03001 moveq r3,#1` / `0x28bd20 05853020 streq r3,[r5,#0x20]`）；
  第二串 `multiply`（pool `0x28c858`→`0x357c34`）存 **2**（`0x28bd3c/40`）；
  第三串 `screen`（pool `0x28c85c`→`0x357c40`）存 **3**（`0x28bd5c/60`）。
- 每次写都是 **条件写**（`moveq`+`streq` 成对）：串不认识就**什么都不写**，
  `+0x20` 保留 `spSlotData_create` 留下的值；键缺失时整块被 `0x28bd04 beq` 跳过。
  blendMode 枚举为 `0=normal, 1=additive, 2=multiply, 3=screen`（与 spine-c 3.8 一致，
  此处以二进制为准）。

## 偏差二（F4）：creator 返回值被旧译文早退检查

`0x28bc78 bl spSlotData_create` 之后，原件**没有任何对 r0 的测试**：
`0x28bc7c–0x28bc8c` 的指令流是 `ldr r1,[sp,#0x18]; mov r2,#0; mov r5,r0; mov r0,r4;
bl Json_getString`——直接把结果放 r5 进 color 查询。发布点
`0x28bd64 ldr r3,[r9,#0x1c]` / `0x28bd68 e7835106 str r5,[r3,r6,lsl#2]` 无守卫，
NULL 结果照样进 `data->slots[index]`；三个 blend 分支的 `beq 0x28bd64` 也都落到发布。
（若 map 同时带 color，color 写会经 NULL 指针 fault——这是忠实语义，不是本批要"修"的东西；
creator 本体不在基础树内，其分配失败行为不在此验收。）

旧译文 `if (slotData == 0) return 0;` 被删除；`readSkeletonData_oneSlot` 现在
原样返回 creator 结果，发布无条件。

## 纠正后的重建消费者

模块 `c/spine_read_slots/`：`src/spine_read_slots.c` 按上列字锚重写 blend 块并去掉早退；
夹具 `fixture/legacy_red.c`（复用 mesh 夹具的无头运行时）以 `RED_CASE 1..5` 钉住
additive→1、multiply→2、screen→3、串不认识不覆盖比较器已写的值、creator 强制 NULL
仍发布并消费后续字段。creator 为声明的 SYNTHETIC 边界（无 SlotData creator 本体），
不是对已恢复 creator 的验收。

## 最终实跑

    python -B reconstruction/reverse-v1/c/spine_read_slots/tools/check_slots.py \
      --so /path/to/libyoyo_armv7.so --out <new exclusive output dir>

最终回执：`reconstruction/reverse-v1/harness/receipts/slots_legacy_check-20261108T093601.json`。
SHA256 `1c63f0934984a843ad6613083cc896e7cf12ddc99e96a006a54e4ab2eccce69a`。
结果 `PASS`：O0/O2/O3/UBSan-trap 各 5 例全绿（20 次执行，BINDING v1 行含
original/fixture/binary SHA），5 个语义变异全部被预先登记的具名断言拒绝
（blend 三路互换各一、恢复默认写、恢复 creator-NULL 早退）；
编译拒绝门一个（缺 slots 本体 → `undefined symbol: readSkeletonData_oneSlot`）；
20 项源码/头/夹具/checker 绑定在执行前后无漂移。

静态钉扎：13 个原字 word pin（含 post-create 流五个字 `0xe59d1018,0xe3a02000,0xe1a05000,
0xe1a00004,0xebffede5`，证明 create 与 color 之间从未出现测试指令）、7 个符号 value/size、
4 个 blend 键字面量（pool/add-site/VA 全登记）。这些是静态锚，不构成原件执行或等价性证明。

## 边界与欠账

- 原件未执行；本批是重建 C 对原字锚的**语义对照**，不是运行态等价。
- slots 循环的外层（含 `0x28bd7c` 条件与 `Slot bone not found` 错误路径的 dispose/setError）
  已于第二批接通（见下节）；`spSlotData_create` 本体、真实文件读取、
  console 初始化、events/animations 段未恢复（animations 段已普查，见
  `asm/animations_segment_map.md`）。
- toColor（`0x28b680`）语义不变，沿用 `c/spine_color/` 共享实现与既有 L5 回执。

## 第二批：slots 段外循环（caller BLOCK 0x28bbe4–0x28bdd8）已接通

`readSkeletonData_slotsSegment`（src/spine_read_slots.c，本地提交）：真实链
`slotsArray`（malloc line 651 锚）→ 循环条件先行（`0x28bc58 b 0x28bd7c`；
`getString "bone"` → **真实** `spSkeletonData_findBone`）→ 命中进 body
（`oneSlot` 创建+字段+无条件发布，index++，`next` 前移）→ 未命中走
**真实** `spSkeletonData_dispose` → **真实** `_spSkeletonJson_setError(parser, tree,
"Slot bone not found: ", boneName)`（内部经真实 console vcall 上报、再
`Json_dispose` 根树）→ 返回 0（`0x28bdc8 mov r0,r7`）。两个原版怪癖钉住：
键缺失不写 count/array（`0x28bbe0 beq`）；child==0 仍发布 count+array
（`0x28bc0c beq` 只跳循环）。

检查台 `tools/check_slots_segment.py`（夹具 `fixture/segment_check.c`，
复用 mesh 无头运行时 + reporter_adapter 真实 vcall sink；合成边界仅
spSlotData_create/setAttachmentName、fixture 堆、line-651 零记录填充）：

- static：SHA + 9 符号 pin + 16 word pin + 2 键字面量（bone/错误文案）
- O0/O2/O3/UBSan 各 4 例（absent / empty_children / success / error）全绿；
  **父代理独立复跑通过**（wl_segP_verify，RESULT PASS）
- 6 个具名变异全被拒绝：跳过 dispose / 错误吞掉返 1 / 错文案 / 丢 json 实参
  / 条件极性反转 / index 从 1 起
- 缺本体编译拒绝门；BINDING v1 ×10；28 项源绑定（源码+头+checker）无漂移
- 回执 `harness/receipts/slots_segment_check-20261108T100512.json`
  （sha256 与最终 run 一致，worker 交付、父代理复跑核实）

同批落盘 animations/events 段普查（子代理只读施工、父代理抽验）：
`asm/animations_census.tsv`（1641 条，0x28d19c..0x28eb40）+
`asm/animations_segment_map.md`（段界三证、46 唯一键、7 malloc 锚、
52 唯一被调、无 switch 跳表、31 分块表 1579 可达指令、12 open questions）。
父代理抽验核实：段界分支（0x28ccc8/0x28cd08/0x28d198/0x28eb3c）、
三个 malloc 行号补正（`e3a02e26`=608、`e3a02088`=136、`e3a02f61`=388，
旋转立即数逐字核对）、0x28b34c/0x28b680 不在 .dynsym（匿名）。
