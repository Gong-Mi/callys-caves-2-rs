/* cally 逆向卡：DeSerializeLayer（原版 libyoyo.so，armv7）
 * @func 0x1c74d0 0x1c8380  size 3760  937 条（940 字 - 1c78f0/1c78f4/1c78f8 三个常数字；
 *       1c78f0..1c791c 是 8 字常量/字面量区，objdump 按 ARM 指令译码显示，不是指令）
 * 级别: 骨架（读流协议（虚表槽 3 + kind 5/6/8 + YYGet*）、CLayer 12 个头部字段的读序与偏移、
 *       4 个元素组的顺序与逐字段偏移、tilemap 像素矩阵的分配/清零/嵌套读、3 个工厂与
 *       1 处就地构造（80 字节类型 7）全部逐条落锚；未钉：kind 在 IBuffer 侧的确切语义、
 *       AddNewElement 第 4 实参的来源、类型 2/3/6 为何无序列化、CLayer 的
 *       +0x2c/+0x5c/+0x60/+0x64 —— 故不升正文）
 * 符号: _ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer
 *       → CLayerManager::DeSerializeLayer(CRoom*, IBuffer*)
 * 同层: DuplicateRoomLayers 0x1c47e0、InsertLayerIntoActiveList 0x1c30f8、AddNewElement 0x1c5ff0、
 *       AddElementToLayer 0x1c451c、GetNewBackgroundElement 0x1c0bd8、GetNewSpriteElement 0x1c0f00、
 *       GetNewTilemapElement 0x1c1034、IBuffer::ReadString 0xcde74、
 *       YYGetInt32 0xce870 / YYGetFloat 0xcec84 / YYGetBool 0xce768 / YYGetUint32 0xce950
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   从 IBuffer 顺序读出一条层记录并挂进房间：12 个头部字段 → InsertLayerIntoActiveList →
 *   再按 4 个计数字段各读一组元素（background 44 字节子对象 / tilemap 含像素矩阵 / sprite /
 *   80 字节类型 7），每读完一个元素就 AddNewElement（前三组）或 AddElementToLayer（第四组）
 *   追加进层。
 *
 * ── 读流协议：三层，且没有类型自描述 ──────────────────────────────
 *   1) 取值：r7 = buf+0x2c（buffer 内嵌的 RValue 临时区），每读一个值都是
 *        r3 = [buf]（虚表）→ r3 = [r3+0xc]（槽 3）→ blx r3，实参 (buf, kind, r7)
 *      kind 只出现三个值，且与取值函数严格配对：
 *        kind 5 → 紧接 YYGetUint32       kind 6 → 紧接 YYGetInt32 或 YYGetBool
 *        kind 8 → 紧接 YYGetFloat
 *      ⇒ 流里没有类型标签，kind 是调用方按字段类型选定的；同一 kind 6 既读 int 也读 bool
 *   2) 字符串：直调 IBuffer::ReadString()（不是虚函数），返回值原样存进对象，没有二次复制
 *   3) 一条记录 = 头部 12 字段 + 4 个 (计数, 计数×元素) 段，全部顺序读，没有长度或魔数
 *
 * ── CLayer 头部 12 字段（偏移实测；与 DuplicateRoomLayers 的拷贝清单互相坐实）──
 *   1  +0x00 int  id            kind6/Int32      ← 层链与 map 的键
 *   2  +0x1c str  name          ReadString      ← 唯一一次字符串读
 *   3  +0x04 int                kind6/Int32
 *   4  +0x08 float              kind8/Float
 *   5  +0x0c float
 *   6  +0x10 float
 *   7  +0x14 float
 *   8  +0x18 byte bool          kind6/Bool
 *   9  +0x19 byte bool          kind6/Bool       ★ DuplicateRoomLayers 不拷这一个字节
 *   10 +0x20 int                kind6/Int32
 *   11 +0x24 int
 *   12 +0x28 int
 *   → InsertLayerIntoActiveList(房间, 层)；本函数不自己维护 room+0xd4/0xd8/0xdc
 *   未进流：+0x2c、+0x30..0x57（CTimingSource）、+0x58..0x60（元素链）、+0x64
 *
 * ── 四组元素 ───────────────────────────────────────────────────
 *   组A background（工厂）：GetNewBackgroundElement() = Alloc(32)/type 1，再 Alloc(44) 子对象
 *       挂到 元素+0x1c。子对象 13 字段：
 *         +0x00 b +0x01 b +0x04 i +0x08 b +0x09 b +0x0c f +0x10 f +0x14 b
 *         +0x18 i +0x1c f +0x20 f +0x24 f +0x28 i
 *       收：AddNewElement(房间, 层, 元素, 假)
 *   组B tilemap（工厂）：GetNewTilemapElement() = Alloc(60)/type 5
 *       +0x1c i、+0x0c str、+0x20 f、+0x24 f、+0x28 i(w)、+0x2c i(h)、+0x30 f、
 *       +0x34 像素块（Alloc(w*h*4) + memset 0 + 逐像素 YYGetUint32）、+0x38 u32
 *       收：AddNewElement
 *   组C sprite（工厂）：GetNewSpriteElement() = Alloc(72)/type 4
 *       +0x1c i、+0x24 f、+0x28 i、+0x2c f、+0x30 f、+0x34 f、+0x38 i、+0x3c f、+0x40 f、+0x44 f（10 个）
 *       收：AddNewElement
 *   组D type 7（就地构造，无工厂）：Alloc(80)/type 7，初值与 DuplicateRoomLayers 的 case 7 逐项相同
 *       +0x1c b、+0x20 i、+0x24 f、+0x28 f、+0x2c i、+0x30 i、+0x34 f、+0x38 f、+0x3c f、
 *       +0x40 u32、+0x44 f、+0x48 i、+0x4c i
 *       收：AddElementToLayer(房间, 层, 元素, false)
 *
 * ── 与 DuplicateRoomLayers 的互相印证（本卡的交叉证据）───────────────
 *   · 层一律 112 字节、同一个池协议：本函数 1c759c..1c75e0 的压链与 1c75f0..1c7650 的弹出，
 *     与 Duplicate 的 1c4a3c..1c4b74 逐指令同构（池头 {+0 链头,+4 链尾,+8 可用数,+0x10 容量}，
 *     节点 +0x68 next / +0x6c prev，ctor 里 CTimingSource::Reset 也在同一处 +0x30）
 *   · 头部字段集：本函数读 12 个（含 +0x19），Duplicate 只搬 11 个 → +0x19 是被 Duplicate 丢掉的
 *   · 组 D 的 80 字节构造 == Duplicate 的 case 7（同尺寸、+0x00 = 7、+0x34/+0x38/+0x44 = 1.0f、
 *     +0x04/+0x20/+0x40 = -1），两处独立构造同一类，可互相校验
 *   · 组 A/C 的 13/10 个字段 ⊂ Duplicate 的 case 1（13 字段）/case 4（13 字段）：
 *     sprite 多出的 +0x04/+0x0c/+0x20 是运行期字段，不进流
 *   · 反过来 tilemap 的 +0x38 进了流，Duplicate 的 case 5 却不拷 → 两处不对称（各自记 open）
 *   · 类型 2/3/6 在本函数里完全不出现（既没有工厂也没有就地构造）→ 它们只能由别的路径产生
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */


/* @0x1c74d0 ldr r12, [pc, #0x424] */
/* @0x1c74d4 ldr r3, [pc, #0x424] */
/* ── 帧与形参：r0 当 CRoom*，r1 当 IBuffer* ──────────────────────────
 *   push {r4-r11,lr} + vpush {d8,d9} + sub sp,#36
 *   r6 = r1（buffer）；sp+0xc = r0（房间）；r12 = GOT 基址（1c74d0 的字面量 0x0022a770 + pc）
 *   r8 = [GOT-0x13f4] = 层池对象 —— 与 DuplicateRoomLayers 是同一个槽（0xffffec0c）
 *   ⇒ 和 Duplicate 一样，this 被直接当房间用（r0 原样进 InsertLayerIntoActiveList /
 *     AddNewElement / AddElementToLayer），CLayerManager 自身没有任何字段被读。
 */

/* @0x1c74d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c74dc vpush {d8, d9} */
/* @0x1c74e0 add r12, pc, r12 */
/* @0x1c74e4 sub sp, sp, #36 */
/* @0x1c74e8 mov r6, r1 */
/* @0x1c74ec str r12, [sp, #0x1c] */
/* @0x1c74f0 str r0, [sp, #0xc] */
/* @0x1c74f4 ldr r8, [r12, r3] */
/* ── 层池：可用数为 0 就补「容量」个 112 字节对象，然后把容量翻倍 ──────────
 *   1c74f8 r10 = [r8+0x08]（可用数）；非 0 → 1c75f0 直接弹
 *   1c7504/1c7508 容量；<=0 → 1c75e8（只翻倍，不分配）
 *   1c7510..1c7520 取 Alloc 站点串（1c7904 → Room_Layers.h）；1c7528 r0 = 112
 *   1c7540..1c7598 初值：+0x00 = -1、+0x04 = 0、+0x08/+0x0c/+0x10/+0x14 = 0.0f、+0x18 字节 = 1、
 *     +0x48..0x4f = 0.0 双精度（d9）、+0x19 = 0、+0x1c = 0、+0x20/+0x24/+0x28 = -1、
 *     CTimingSource::Reset(+0x30)、+0x5c/+0x58/+0x60 = 0、+0x64 = 1、+0x68 = 0、+0x6c = 0
 *   ⇒ 与 Duplicate 的 1c4a5c..1c4ad0 逐项相同 → CLayer 的 ctor 语义由两处独立坐实
 */

/* @0x1c74f8 ldr r10, [r8, #0x8] */
/* @0x1c74fc cmp r10, #0 */
/* @0x1c7500 bne 0x1c75f0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x120> */
/* @0x1c7504 ldr r3, [r8, #0x10] */
/* @0x1c7508 cmp r3, #0 */
/* @0x1c750c ble 0x1c75e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x118> */
/* @0x1c7510 ldr r9, [pc, #0x3ec] */
/* @0x1c7514 mov r7, #1 */
/* @0x1c7518 vldr s16, [pc, #984] */
/* @0x1c751c vldr d9, [pc, #972] */
/* @0x1c7520 add r9, pc, r9 */
/* @0x1c7524 mov r3, #1 */
/* @0x1c7528 mov r0, #112 */
/* @0x1c752c mov r1, r9 */
/* @0x1c7530 mov r2, #63 */
/* @0x1c7534 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c7538 mov r5, #0 */
/* @0x1c753c mvn r3, #0 */
/* @0x1c7540 subs r4, r0, #0 */
/* @0x1c7544 add r0, r4, #48 */
/* @0x1c7548 beq 0x1c759c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xcc> */
/* @0x1c754c str r3, [r4] */
/* @0x1c7550 vstr s16, [r4, #8] */
/* @0x1c7554 str r5, [r4, #0x4] */
/* @0x1c7558 vstr s16, [r4, #12] */
/* @0x1c755c vstr s16, [r4, #16] */
/* @0x1c7560 vstr s16, [r4, #20] */
/* @0x1c7564 strb r7, [r4, #0x18] */
/* @0x1c7568 vstr d9, [r4, #72] */
/* @0x1c756c strb r5, [r4, #0x19] */
/* @0x1c7570 str r5, [r4, #0x1c] */
/* @0x1c7574 str r3, [r4, #0x20] */
/* @0x1c7578 str r3, [r4, #0x24] */
/* @0x1c757c str r3, [r4, #0x28] */
/* @0x1c7580 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c7584 str r5, [r4, #0x5c] */
/* @0x1c7588 str r5, [r4, #0x58] */
/* @0x1c758c str r5, [r4, #0x60] */
/* @0x1c7590 str r7, [r4, #0x64] */
/* @0x1c7594 str r5, [r4, #0x68] */
/* @0x1c7598 str r5, [r4, #0x6c] */
/* @0x1c759c ldr r3, [r8] */
/* @0x1c75a0 mov r1, #0 */
/* @0x1c75a4 add r10, r10, #1 */
/* @0x1c75a8 ldr r2, [r8, #0x8] */
/* @0x1c75ac cmp r3, r1 */
/* @0x1c75b0 streq r4, [r8, #0x4] */
/* @0x1c75b4 strne r4, [r3, #0x6c] */
/* @0x1c75b8 add r2, r2, #1 */
/* @0x1c75bc streq r3, [r4, #0x6c] */
/* @0x1c75c0 streq r3, [r4, #0x68] */
/* @0x1c75c4 strne r3, [r4, #0x68] */
/* @0x1c75c8 ldr r3, [r8, #0x10] */
/* @0x1c75cc streq r4, [r8] */
/* @0x1c75d0 strne r4, [r8] */
/* @0x1c75d4 strne r1, [r4, #0x6c] */
/* @0x1c75d8 cmp r10, r3 */
/* @0x1c75dc str r2, [r8, #0x8] */
/* @0x1c75e0 blt 0x1c7524 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x54> */
/* @0x1c75e4 ldr r10, [r8, #0x8] */
/* @0x1c75e8 lsl r3, r3, #1 */
/* @0x1c75ec str r3, [r8, #0x10] */
/* ── 弹一个 CLayer，开始读头部 ──────────────────────────────────────
 *   1c75f0 r12 = 池头；1c7604..1c7634 用 +0x6c/+0x68 做链头摘除（prev==0 → 池头 = next，
 *     否则 prev.next = next；next==0 → 池尾 = prev，否则 next.prev = prev）
 *   1c75f4 r7 = buf+0x2c —— 内嵌 RValue 临时区，后面每次取值都往这里读
 *   1c7644 r3 = [buf] → r3 = [r3+0xc] → 1c7648 blx r3，实参 (buf, 6, r7)
 *   1c7650/1c7654 YYGetInt32(rv, 0) → 1c765c 写 层+0x00（id）
 */

/* @0x1c75f0 ldr r12, [r8] */
/* @0x1c75f4 add r7, r6, #44 */
/* @0x1c75f8 sub r10, r10, #1 */
/* @0x1c75fc mov r1, #6 */
/* @0x1c7600 mov r0, r6 */
/* @0x1c7604 ldr r3, [r12, #0x6c] */
/* @0x1c7608 str r12, [sp, #0x4] */
/* @0x1c760c cmp r3, #0 */
/* @0x1c7610 ldrne r12, [sp, #0x4] */
/* @0x1c7614 ldreq r2, [r12, #0x68] */
/* @0x1c7618 ldrne r2, [r12, #0x68] */
/* @0x1c761c streq r2, [r8] */
/* @0x1c7620 strne r2, [r3, #0x68] */
/* @0x1c7624 ldrne r2, [r12, #0x68] */
/* @0x1c7628 ldrne r3, [r12, #0x6c] */
/* @0x1c762c cmp r2, #0 */
/* @0x1c7630 streq r3, [r8, #0x4] */
/* @0x1c7634 strne r3, [r2, #0x6c] */
/* @0x1c7638 mov r2, r7 */
/* @0x1c763c ldr r3, [r6] */
/* @0x1c7640 str r10, [r8, #0x8] */
/* @0x1c7644 ldr r3, [r3, #0xc] */
/* @0x1c7648 blx r3 */
/* @0x1c764c mov r1, #0 */
/* @0x1c7650 mov r0, r7 */
/* @0x1c7654 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7658 ldr r12, [sp, #0x4] */
/* @0x1c765c str r0, [r12] */
/* ── 第 2 字段：名字，直调 IBuffer::ReadString ─────────────────────────
 *   1c7660 bl 0xcde74；1c7678 写 层+0x1c。返回值原样存（没有长度前缀、没有再复制一次）。
 */

/* @0x1c7660 mov r0, r6 */
/* @0x1c7664 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1c7668 ldr r12, [sp, #0x4] */
/* ── 第 3..12 字段：kind 只有 6(int/bool) 与 8(float) 两种 ─────────────
 *   「虚表槽 3 + YYGet*」12 连发，落位：
 *     +0x04 i  +0x08 f  +0x0c f  +0x10 f  +0x14 f  +0x18 b  +0x19 b  +0x20 i  +0x24 i  +0x28 i
 *   ⇒ 头部读序 = id, name, int, 4×float, 2×bool, 3×int
 *   ★ +0x19 这个 bool：DuplicateRoomLayers 复制层时不搬它，是两函数对照出来的明确丢字段。
 */

/* @0x1c766c ldr r3, [r6] */
/* @0x1c7670 mov r2, r7 */
/* @0x1c7674 mov r1, #6 */
/* @0x1c7678 str r0, [r12, #0x1c] */
/* @0x1c767c mov r0, r6 */
/* @0x1c7680 ldr r3, [r3, #0xc] */
/* @0x1c7684 blx r3 */
/* @0x1c7688 mov r1, #0 */
/* @0x1c768c mov r0, r7 */
/* @0x1c7690 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7694 ldr r12, [sp, #0x4] */
/* @0x1c7698 ldr r3, [r6] */
/* @0x1c769c mov r2, r7 */
/* @0x1c76a0 mov r1, #8 */
/* @0x1c76a4 ldr r3, [r3, #0xc] */
/* @0x1c76a8 str r0, [r12, #0x4] */
/* @0x1c76ac mov r0, r6 */
/* @0x1c76b0 blx r3 */
/* @0x1c76b4 mov r1, #0 */
/* @0x1c76b8 mov r0, r7 */
/* @0x1c76bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c76c0 ldr r12, [sp, #0x4] */
/* @0x1c76c4 ldr r3, [r6] */
/* @0x1c76c8 mov r2, r7 */
/* @0x1c76cc mov r1, #8 */
/* @0x1c76d0 ldr r3, [r3, #0xc] */
/* @0x1c76d4 str r0, [r12, #0x8] */
/* @0x1c76d8 mov r0, r6 */
/* @0x1c76dc blx r3 */
/* @0x1c76e0 mov r1, #0 */
/* @0x1c76e4 mov r0, r7 */
/* @0x1c76e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c76ec ldr r12, [sp, #0x4] */
/* @0x1c76f0 ldr r3, [r6] */
/* @0x1c76f4 mov r2, r7 */
/* @0x1c76f8 mov r1, #8 */
/* @0x1c76fc ldr r3, [r3, #0xc] */
/* @0x1c7700 str r0, [r12, #0xc] */
/* @0x1c7704 mov r0, r6 */
/* @0x1c7708 blx r3 */
/* @0x1c770c mov r1, #0 */
/* @0x1c7710 mov r0, r7 */
/* @0x1c7714 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7718 ldr r12, [sp, #0x4] */
/* @0x1c771c ldr r3, [r6] */
/* @0x1c7720 mov r2, r7 */
/* @0x1c7724 mov r1, #8 */
/* @0x1c7728 ldr r3, [r3, #0xc] */
/* @0x1c772c str r0, [r12, #0x10] */
/* @0x1c7730 mov r0, r6 */
/* @0x1c7734 blx r3 */
/* @0x1c7738 mov r1, #0 */
/* @0x1c773c mov r0, r7 */
/* @0x1c7740 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7744 ldr r12, [sp, #0x4] */
/* @0x1c7748 ldr r3, [r6] */
/* @0x1c774c mov r2, r7 */
/* @0x1c7750 mov r1, #6 */
/* @0x1c7754 ldr r3, [r3, #0xc] */
/* @0x1c7758 str r0, [r12, #0x14] */
/* @0x1c775c mov r0, r6 */
/* @0x1c7760 blx r3 */
/* @0x1c7764 mov r1, #0 */
/* @0x1c7768 mov r0, r7 */
/* @0x1c776c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c7770 ldr r12, [sp, #0x4] */
/* @0x1c7774 ldr r3, [r6] */
/* @0x1c7778 mov r2, r7 */
/* @0x1c777c mov r1, #6 */
/* @0x1c7780 ldr r3, [r3, #0xc] */
/* @0x1c7784 strb r0, [r12, #0x18] */
/* @0x1c7788 mov r0, r6 */
/* @0x1c778c blx r3 */
/* @0x1c7790 mov r1, #0 */
/* @0x1c7794 mov r0, r7 */
/* @0x1c7798 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c779c ldr r12, [sp, #0x4] */
/* @0x1c77a0 ldr r3, [r6] */
/* @0x1c77a4 mov r2, r7 */
/* @0x1c77a8 mov r1, #6 */
/* @0x1c77ac ldr r3, [r3, #0xc] */
/* @0x1c77b0 strb r0, [r12, #0x19] */
/* @0x1c77b4 mov r0, r6 */
/* @0x1c77b8 blx r3 */
/* @0x1c77bc mov r1, #0 */
/* @0x1c77c0 mov r0, r7 */
/* @0x1c77c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c77c8 ldr r12, [sp, #0x4] */
/* @0x1c77cc ldr r3, [r6] */
/* @0x1c77d0 mov r2, r7 */
/* @0x1c77d4 mov r1, #6 */
/* @0x1c77d8 ldr r3, [r3, #0xc] */
/* @0x1c77dc str r0, [r12, #0x20] */
/* @0x1c77e0 mov r0, r6 */
/* @0x1c77e4 blx r3 */
/* @0x1c77e8 mov r1, #0 */
/* @0x1c77ec mov r0, r7 */
/* @0x1c77f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c77f4 ldr r12, [sp, #0x4] */
/* @0x1c77f8 ldr r3, [r6] */
/* @0x1c77fc mov r2, r7 */
/* @0x1c7800 mov r1, #6 */
/* @0x1c7804 ldr r3, [r3, #0xc] */
/* @0x1c7808 str r0, [r12, #0x24] */
/* @0x1c780c mov r0, r6 */
/* @0x1c7810 blx r3 */
/* @0x1c7814 mov r1, #0 */
/* @0x1c7818 mov r0, r7 */
/* @0x1c781c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7820 ldr r1, [sp, #0x4] */
/* @0x1c7824 str r0, [r1, #0x28] */
/* ── 挂进房间：InsertLayerIntoActiveList(房间, 层) ────────────────────
 *   r0 = sp+0xc（房间）、r1 = sp+4（新层）。注意本函数完全不自己维护 room+0xd4/0xd8/0xdc，
 *   全交给这个函数 —— 与 DuplicateRoomLayers 自己尾插 + 插 map 形成两种风格。
 */

/* @0x1c7828 ldr r0, [sp, #0xc] */
/* @0x1c782c bl 0x1c30f8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer> */
/* @0x1c7830 ldr r3, [r6] */
/* @0x1c7834 mov r2, r7 */
/* @0x1c7838 mov r1, #6 */
/* @0x1c783c mov r0, r6 */
/* @0x1c7840 ldr r3, [r3, #0xc] */
/* @0x1c7844 blx r3 */
/* @0x1c7848 mov r0, r7 */
/* ── 组 A 前的计数：kind6/Int32；<=0 → 1c7b5c 跳到组 B ────────────────
 *   r10 = 个数；循环体 1c7894..1c7b54（每轮重取池/站点槽，与 Duplicate 的元素循环同构）
 */

/* @0x1c784c mov r1, #0 */
/* @0x1c7850 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7854 subs r10, r0, #0 */
/* @0x1c7858 ble 0x1c7b5c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x68c> */
/* @0x1c785c ldr r3, [pc, #0xac] */
/* @0x1c7860 mov r5, #0 */
/* @0x1c7864 ldr r12, [sp, #0x1c] */
/* @0x1c7868 mov r9, r5 */
/* @0x1c786c ldr r11, [pc, #0x94] */
/* @0x1c7870 vldr s16, [pc, #128] */
/* @0x1c7874 ldr r3, [r12, r3] */
/* @0x1c7878 add r11, pc, r11 */
/* @0x1c787c str r10, [sp, #0x8] */
/* @0x1c7880 ldr r10, [sp, #0xc] */
/* @0x1c7884 str r11, [sp, #0x10] */
/* @0x1c7888 mov r11, r6 */
/* @0x1c788c mov r6, r3 */
/* @0x1c7890 str r3, [sp, #0x14] */
/* ── 组 A：工厂 + 44 字节子对象 ──────────────────────────────────────
 *   1c7894 GetNewBackgroundElement() → r8 = 元素（32 字节、type 1，见 0x1c0bd8 的 Alloc(32)+type 1）
 *   1c78a8/1c78ac Alloc(44, Room_Layers.cpp, 0x47c, 1) → 1c7924 元素+0x1c = 子对象
 *   1c78b8..1c78e8 子对象初值：+0x00/+0x01/+0x08/+0x09/+0x14 字节 = 0、+0x04 = 0、
 *     +0x0c/+0x10/+0x1c/+0x20/+0x24 = 0.0f、+0x18 = 0、+0x28 = 0
 *   ⇒ 与 Duplicate 的 case 1（1c5928..1c5968）是同一套初值
 */

/* @0x1c7894 bl 0x1c0bd8 <_ZN13CLayerManager23GetNewBackgroundElementEv> */
/* @0x1c7898 ldr r1, [sp, #0x10] */
/* @0x1c789c movw r2, #0x47c */
/* @0x1c78a0 mov r3, #1 */
/* @0x1c78a4 mov r8, r0 */
/* @0x1c78a8 mov r0, #44 */
/* @0x1c78ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c78b0 subs r4, r0, #0 */
/* @0x1c78b4 beq 0x1c791c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x44c> */
/* @0x1c78b8 strb r9, [r4] */
/* @0x1c78bc vstr s16, [r4, #12] */
/* @0x1c78c0 strb r9, [r4, #0x1] */
/* @0x1c78c4 vstr s16, [r4, #16] */
/* @0x1c78c8 str r9, [r4, #0x4] */
/* @0x1c78cc vstr s16, [r4, #28] */
/* @0x1c78d0 strb r9, [r4, #0x8] */
/* @0x1c78d4 vstr s16, [r4, #32] */
/* @0x1c78d8 strb r9, [r4, #0x9] */
/* @0x1c78dc vstr s16, [r4, #36] */
/* @0x1c78e0 strb r9, [r4, #0x14] */
/* @0x1c78e4 str r9, [r4, #0x18] */
/* @0x1c78e8 str r9, [r4, #0x28] */
/* @0x1c78ec b 0x1c791c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x44c> */
/* @0x1c78fc eoreq r10, r2, r0, ror r7 */
/* @0x1c7900 .word 0xffffec0c */
/* @0x1c7904 andseq r6, r8, r4, ror r1 */
/* @0x1c7908 ldrsheq r5, [r8], -r4 */
/* @0x1c790c ldrsbeq r5, [r8], -r0 */
/* @0x1c7910 .word 0xffffbcd8 */
/* @0x1c7914 .word 0xffffec28 */
/* @0x1c7918 andseq r5, r8, r4, ror #12 */
/* ── 组 A：13 个字段读进子对象（顺序与 Duplicate case 1 的拷贝清单一致）────
 *   +0x00 b → +0x01 b → +0x04 i → +0x08 b → +0x09 b → +0x0c f → +0x10 f → +0x14 b →
 *   +0x18 i → +0x1c f → +0x20 f → +0x24 f → +0x28 i
 *   1c7930 每轮把已处理计数 +1（r5），1c7b50 与总数比较决定是否继续
 */

/* @0x1c791c ldr r3, [r11] */
/* @0x1c7920 mov r2, r7 */
/* @0x1c7924 str r4, [r8, #0x1c] */
/* @0x1c7928 mov r1, #6 */
/* @0x1c792c mov r0, r11 */
/* @0x1c7930 add r5, r5, #1 */
/* @0x1c7934 ldr r3, [r3, #0xc] */
/* @0x1c7938 blx r3 */
/* @0x1c793c mov r1, #0 */
/* @0x1c7940 mov r0, r7 */
/* @0x1c7944 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c7948 ldr r3, [r11] */
/* @0x1c794c mov r2, r7 */
/* @0x1c7950 mov r1, #6 */
/* @0x1c7954 ldr r3, [r3, #0xc] */
/* @0x1c7958 strb r0, [r4] */
/* @0x1c795c mov r0, r11 */
/* @0x1c7960 blx r3 */
/* @0x1c7964 mov r1, #0 */
/* @0x1c7968 mov r0, r7 */
/* @0x1c796c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c7970 ldr r3, [r11] */
/* @0x1c7974 mov r2, r7 */
/* @0x1c7978 mov r1, #6 */
/* @0x1c797c ldr r3, [r3, #0xc] */
/* @0x1c7980 strb r0, [r4, #0x1] */
/* @0x1c7984 mov r0, r11 */
/* @0x1c7988 blx r3 */
/* @0x1c798c mov r1, #0 */
/* @0x1c7990 mov r0, r7 */
/* @0x1c7994 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7998 ldr r3, [r11] */
/* @0x1c799c mov r2, r7 */
/* @0x1c79a0 mov r1, #6 */
/* @0x1c79a4 ldr r3, [r3, #0xc] */
/* @0x1c79a8 str r0, [r4, #0x4] */
/* @0x1c79ac mov r0, r11 */
/* @0x1c79b0 blx r3 */
/* @0x1c79b4 mov r1, #0 */
/* @0x1c79b8 mov r0, r7 */
/* @0x1c79bc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c79c0 ldr r3, [r11] */
/* @0x1c79c4 mov r2, r7 */
/* @0x1c79c8 mov r1, #6 */
/* @0x1c79cc ldr r3, [r3, #0xc] */
/* @0x1c79d0 strb r0, [r4, #0x8] */
/* @0x1c79d4 mov r0, r11 */
/* @0x1c79d8 blx r3 */
/* @0x1c79dc mov r1, #0 */
/* @0x1c79e0 mov r0, r7 */
/* @0x1c79e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c79e8 ldr r3, [r11] */
/* @0x1c79ec mov r2, r7 */
/* @0x1c79f0 mov r1, #8 */
/* @0x1c79f4 ldr r3, [r3, #0xc] */
/* @0x1c79f8 strb r0, [r4, #0x9] */
/* @0x1c79fc mov r0, r11 */
/* @0x1c7a00 blx r3 */
/* @0x1c7a04 mov r1, #0 */
/* @0x1c7a08 mov r0, r7 */
/* @0x1c7a0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7a10 ldr r3, [r11] */
/* @0x1c7a14 mov r2, r7 */
/* @0x1c7a18 mov r1, #8 */
/* @0x1c7a1c ldr r3, [r3, #0xc] */
/* @0x1c7a20 str r0, [r4, #0xc] */
/* @0x1c7a24 mov r0, r11 */
/* @0x1c7a28 blx r3 */
/* @0x1c7a2c mov r1, #0 */
/* @0x1c7a30 mov r0, r7 */
/* @0x1c7a34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7a38 ldr r3, [r11] */
/* @0x1c7a3c mov r2, r7 */
/* @0x1c7a40 mov r1, #6 */
/* @0x1c7a44 ldr r3, [r3, #0xc] */
/* @0x1c7a48 str r0, [r4, #0x10] */
/* @0x1c7a4c mov r0, r11 */
/* @0x1c7a50 blx r3 */
/* @0x1c7a54 mov r1, #0 */
/* @0x1c7a58 mov r0, r7 */
/* @0x1c7a5c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c7a60 ldr r3, [r11] */
/* @0x1c7a64 mov r2, r7 */
/* @0x1c7a68 mov r1, #6 */
/* @0x1c7a6c ldr r3, [r3, #0xc] */
/* @0x1c7a70 strb r0, [r4, #0x14] */
/* @0x1c7a74 mov r0, r11 */
/* @0x1c7a78 blx r3 */
/* @0x1c7a7c mov r1, #0 */
/* @0x1c7a80 mov r0, r7 */
/* @0x1c7a84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7a88 ldr r3, [r11] */
/* @0x1c7a8c mov r2, r7 */
/* @0x1c7a90 mov r1, #8 */
/* @0x1c7a94 ldr r3, [r3, #0xc] */
/* @0x1c7a98 str r0, [r4, #0x18] */
/* @0x1c7a9c mov r0, r11 */
/* @0x1c7aa0 blx r3 */
/* @0x1c7aa4 mov r1, #0 */
/* @0x1c7aa8 mov r0, r7 */
/* @0x1c7aac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7ab0 ldr r3, [r11] */
/* @0x1c7ab4 mov r2, r7 */
/* @0x1c7ab8 mov r1, #8 */
/* @0x1c7abc ldr r3, [r3, #0xc] */
/* @0x1c7ac0 str r0, [r4, #0x1c] */
/* @0x1c7ac4 mov r0, r11 */
/* @0x1c7ac8 blx r3 */
/* @0x1c7acc mov r1, #0 */
/* @0x1c7ad0 mov r0, r7 */
/* @0x1c7ad4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7ad8 ldr r3, [r11] */
/* @0x1c7adc mov r2, r7 */
/* @0x1c7ae0 mov r1, #8 */
/* @0x1c7ae4 ldr r3, [r3, #0xc] */
/* @0x1c7ae8 str r0, [r4, #0x20] */
/* @0x1c7aec mov r0, r11 */
/* @0x1c7af0 blx r3 */
/* @0x1c7af4 mov r1, #0 */
/* @0x1c7af8 mov r0, r7 */
/* @0x1c7afc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7b00 ldr r3, [r11] */
/* @0x1c7b04 mov r2, r7 */
/* @0x1c7b08 mov r1, #6 */
/* @0x1c7b0c ldr r3, [r3, #0xc] */
/* @0x1c7b10 str r0, [r4, #0x24] */
/* @0x1c7b14 mov r0, r11 */
/* @0x1c7b18 blx r3 */
/* @0x1c7b1c mov r1, #0 */
/* @0x1c7b20 mov r0, r7 */
/* @0x1c7b24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* ── 组 A 收尾：AddNewElement(房间, 层, 元素, 假) ────────────────────
 *   1c7b34..1c7b3c 的 subs/rsbs/adcs 三连算第 4 实参 = (房间 == [buf]虚表) ? 1 : 0
 *   （被减数是 r10 = 房间，减数是 r3 = buf 的虚表指针）→ 实际恒为 0
 *   ⇒ 三组都传「假」；但这个 bool 的来源明显是编译产物，语义可疑，记 open。
 */

/* @0x1c7b28 ldr r3, [r6] */
/* @0x1c7b2c mov r2, r8 */
/* @0x1c7b30 ldr r1, [sp, #0x4] */
/* @0x1c7b34 subs r8, r10, r3 */
/* @0x1c7b38 rsbs r3, r8, #0 */
/* @0x1c7b3c adcs r3, r3, r8 */
/* @0x1c7b40 str r0, [r4, #0x28] */
/* @0x1c7b44 mov r0, r10 */
/* @0x1c7b48 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c7b4c ldr r12, [sp, #0x8] */
/* @0x1c7b50 cmp r5, r12 */
/* @0x1c7b54 bne 0x1c7894 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x3c4> */
/* @0x1c7b58 mov r6, r11 */
/* ── 组 B 前的计数：<=0 → 1c7dd8（组 C）─────────────────────────────
 *   [sp+0x10] = 总数，[sp+0x8] = 已处理数（1c7d88 自增）
 */

/* @0x1c7b5c ldr r3, [r6] */
/* @0x1c7b60 mov r1, #6 */
/* @0x1c7b64 mov r2, r7 */
/* @0x1c7b68 mov r0, r6 */
/* @0x1c7b6c ldr r3, [r3, #0xc] */
/* @0x1c7b70 blx r3 */
/* @0x1c7b74 mov r0, r7 */
/* @0x1c7b78 mov r1, #0 */
/* @0x1c7b7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7b80 cmp r0, #0 */
/* @0x1c7b84 str r0, [sp, #0x10] */
/* @0x1c7b88 ble 0x1c7dd8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x908> */
/* @0x1c7b8c mov r12, #0 */
/* @0x1c7b90 str r12, [sp, #0x8] */
/* @0x1c7b94 ldr r12, [pc, #-0x290] */
/* @0x1c7b98 ldr r3, [pc, #-0x290] */
/* @0x1c7b9c add r12, pc, r12 */
/* @0x1c7ba0 str r12, [sp, #0x18] */
/* @0x1c7ba4 ldr r12, [sp, #0x1c] */
/* @0x1c7ba8 ldr r3, [r12, r3] */
/* @0x1c7bac str r3, [sp, #0x14] */
/* ── 组 B tilemap：GetNewTilemapElement()（60 字节、type 5）─────────────
 *   字段读序：+0x1c i → +0x0c str(ReadString) → +0x20 f → +0x24 f → +0x28 i(w) →
 *            +0x2c i(h) → +0x30 f → +0x34 像素块 → +0x38 u32
 *   ★ +0x38 进了流，但 Duplicate 的 case 5 不拷它（两边不对称）
 */

/* @0x1c7bb0 bl 0x1c1034 <_ZN13CLayerManager20GetNewTilemapElementEv> */
/* @0x1c7bb4 ldr r3, [r6] */
/* @0x1c7bb8 mov r2, r7 */
/* @0x1c7bbc mov r1, #6 */
/* @0x1c7bc0 ldr r3, [r3, #0xc] */
/* @0x1c7bc4 mov r8, r0 */
/* @0x1c7bc8 mov r0, r6 */
/* @0x1c7bcc blx r3 */
/* @0x1c7bd0 mov r1, #0 */
/* @0x1c7bd4 mov r0, r7 */
/* @0x1c7bd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7bdc str r0, [r8, #0x1c] */
/* @0x1c7be0 mov r0, r6 */
/* @0x1c7be4 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1c7be8 ldr r3, [r6] */
/* @0x1c7bec mov r2, r7 */
/* @0x1c7bf0 mov r1, #8 */
/* @0x1c7bf4 str r0, [r8, #0xc] */
/* @0x1c7bf8 mov r0, r6 */
/* @0x1c7bfc ldr r3, [r3, #0xc] */
/* @0x1c7c00 blx r3 */
/* @0x1c7c04 mov r1, #0 */
/* @0x1c7c08 mov r0, r7 */
/* @0x1c7c0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7c10 ldr r3, [r6] */
/* @0x1c7c14 mov r2, r7 */
/* @0x1c7c18 mov r1, #8 */
/* @0x1c7c1c ldr r3, [r3, #0xc] */
/* @0x1c7c20 str r0, [r8, #0x20] */
/* @0x1c7c24 mov r0, r6 */
/* @0x1c7c28 blx r3 */
/* @0x1c7c2c mov r1, #0 */
/* @0x1c7c30 mov r0, r7 */
/* @0x1c7c34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7c38 ldr r3, [r6] */
/* @0x1c7c3c mov r2, r7 */
/* @0x1c7c40 mov r1, #6 */
/* @0x1c7c44 ldr r3, [r3, #0xc] */
/* @0x1c7c48 str r0, [r8, #0x24] */
/* @0x1c7c4c mov r0, r6 */
/* @0x1c7c50 blx r3 */
/* @0x1c7c54 mov r1, #0 */
/* @0x1c7c58 mov r0, r7 */
/* @0x1c7c5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7c60 ldr r3, [r6] */
/* @0x1c7c64 mov r2, r7 */
/* @0x1c7c68 mov r1, #6 */
/* @0x1c7c6c ldr r3, [r3, #0xc] */
/* @0x1c7c70 str r0, [r8, #0x28] */
/* @0x1c7c74 mov r0, r6 */
/* @0x1c7c78 blx r3 */
/* @0x1c7c7c mov r1, #0 */
/* @0x1c7c80 mov r0, r7 */
/* @0x1c7c84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7c88 ldr r3, [r6] */
/* @0x1c7c8c mov r2, r7 */
/* @0x1c7c90 mov r1, #8 */
/* @0x1c7c94 ldr r3, [r3, #0xc] */
/* @0x1c7c98 str r0, [r8, #0x2c] */
/* @0x1c7c9c mov r0, r6 */
/* @0x1c7ca0 blx r3 */
/* @0x1c7ca4 mov r1, #0 */
/* @0x1c7ca8 mov r0, r7 */
/* @0x1c7cac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7cb0 ldr lr, [r8, #0x2c] */
/* @0x1c7cb4 ldr r12, [r8, #0x28] */
/* @0x1c7cb8 movw r2, #0x493 */
/* @0x1c7cbc ldr r1, [sp, #0x18] */
/* @0x1c7cc0 mov r3, #1 */
/* @0x1c7cc4 mul r12, lr, r12 */
/* @0x1c7cc8 str r0, [r8, #0x30] */
/* @0x1c7ccc lsl r0, r12, #2 */
/* ── 组 B 像素块：Alloc(w*h*4) + memset 0 + 逐像素读 ────────────────────
 *   1c7cc4 mul w*h；1c7ccc lsl #2；1c7cd0 Alloc(size, Room_Layers.cpp, 0x493, 1)
 *   1c7ce8 元素+0x34 = 块；1c7cec memset(块, 0, size)
 *   1c7cf0 外层按 +0x28 计数、1c7d00..1c7d68 内层按 +0x2c 计数；
 *   1c7d10 lsl r5,r9,#2 → 平坦字节偏移；1c7d48 str r0,[像素基址, r5]
 *   ⇒ 像素在流里就是 32 位整数序列（kind5/YYGetUint32），不是压缩块
 */

/* @0x1c7cd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c7cd4 ldr r3, [r8, #0x28] */
/* @0x1c7cd8 ldr r2, [r8, #0x2c] */
/* @0x1c7cdc mov r1, #0 */
/* @0x1c7ce0 mul r2, r2, r3 */
/* @0x1c7ce4 lsl r2, r2, #2 */
/* @0x1c7ce8 str r0, [r8, #0x34] */
/* @0x1c7cec bl 0xb65b0 <memset@plt> */
/* @0x1c7cf0 ldr r2, [r8, #0x28] */
/* @0x1c7cf4 cmp r2, #0 */
/* @0x1c7cf8 ble 0x1c7d6c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x89c> */
/* @0x1c7cfc ldr r3, [r8, #0x2c] */
/* @0x1c7d00 mov r10, #0 */
/* @0x1c7d04 mov r9, r10 */
/* @0x1c7d08 cmp r3, #0 */
/* @0x1c7d0c ble 0x1c7d60 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x890> */
/* @0x1c7d10 lsl r5, r9, #2 */
/* @0x1c7d14 mov r4, #0 */
/* @0x1c7d18 ldr r3, [r6] */
/* @0x1c7d1c mov r1, #5 */
/* @0x1c7d20 mov r2, r7 */
/* @0x1c7d24 mov r0, r6 */
/* @0x1c7d28 ldr r11, [r8, #0x34] */
/* @0x1c7d2c add r4, r4, #1 */
/* @0x1c7d30 ldr r3, [r3, #0xc] */
/* @0x1c7d34 add r9, r9, #1 */
/* @0x1c7d38 blx r3 */
/* @0x1c7d3c mov r0, r7 */
/* @0x1c7d40 mov r1, #0 */
/* @0x1c7d44 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1c7d48 str r0, [r11, r5] */
/* @0x1c7d4c add r5, r5, #4 */
/* @0x1c7d50 ldr r3, [r8, #0x2c] */
/* @0x1c7d54 cmp r3, r4 */
/* @0x1c7d58 bgt 0x1c7d18 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x848> */
/* @0x1c7d5c ldr r2, [r8, #0x28] */
/* @0x1c7d60 add r10, r10, #1 */
/* @0x1c7d64 cmp r2, r10 */
/* @0x1c7d68 bgt 0x1c7d08 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x838> */
/* ── 组 B 收尾：再读一个 u32 → +0x38，然后 AddNewElement ────────────────
 *   （工厂里 +0x38 的初值在 Duplicate 的 case 5 可见为 0x80000000，这里被流覆盖）
 */

/* @0x1c7d6c ldr r3, [r6] */
/* @0x1c7d70 mov r2, r7 */
/* @0x1c7d74 ldr r12, [sp, #0x8] */
/* @0x1c7d78 mov r1, #5 */
/* @0x1c7d7c mov r0, r6 */
/* @0x1c7d80 add r12, r12, #1 */
/* @0x1c7d84 ldr r3, [r3, #0xc] */
/* @0x1c7d88 str r12, [sp, #0x8] */
/* @0x1c7d8c blx r3 */
/* @0x1c7d90 mov r1, #0 */
/* @0x1c7d94 mov r0, r7 */
/* @0x1c7d98 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1c7d9c ldr r12, [sp, #0x14] */
/* @0x1c7da0 ldr r1, [sp, #0x4] */
/* @0x1c7da4 mov r2, r8 */
/* @0x1c7da8 ldr r3, [r12] */
/* @0x1c7dac ldr r12, [sp, #0xc] */
/* @0x1c7db0 subs lr, r12, r3 */
/* @0x1c7db4 rsbs r3, lr, #0 */
/* @0x1c7db8 adcs r3, r3, lr */
/* @0x1c7dbc str r0, [r8, #0x38] */
/* @0x1c7dc0 mov r0, r12 */
/* @0x1c7dc4 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c7dc8 ldr r12, [sp, #0x8] */
/* @0x1c7dcc ldr r1, [sp, #0x10] */
/* @0x1c7dd0 cmp r12, r1 */
/* @0x1c7dd4 bne 0x1c7bb0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x6e0> */
/* ── 组 C 前的计数 → GetNewSpriteElement()（72 字节、type 4）─────────────
 *   字段读序：+0x1c i → +0x24 f → +0x28 i → +0x2c f → +0x30 f → +0x34 f → +0x38 i →
 *            +0x3c f → +0x40 f → +0x44 f（10 个）
 *   Duplicate 的 case 4 拷 13 个（多 +0x04/+0x0c/+0x20）→ 那三个是运行期字段，不进流
 */

/* @0x1c7dd8 ldr r3, [r6] */
/* @0x1c7ddc mov r1, #6 */
/* @0x1c7de0 mov r2, r7 */
/* @0x1c7de4 mov r0, r6 */
/* @0x1c7de8 ldr r3, [r3, #0xc] */
/* @0x1c7dec blx r3 */
/* @0x1c7df0 mov r0, r7 */
/* @0x1c7df4 mov r1, #0 */
/* @0x1c7df8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7dfc subs r8, r0, #0 */
/* @0x1c7e00 ble 0x1c7fe8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xb18> */
/* @0x1c7e04 ldr r3, [pc, #-0x4fc] */
/* @0x1c7e08 mov r5, #0 */
/* @0x1c7e0c ldr r12, [sp, #0x1c] */
/* @0x1c7e10 ldr r10, [sp, #0x4] */
/* @0x1c7e14 ldr r9, [sp, #0xc] */
/* @0x1c7e18 ldr r3, [r12, r3] */
/* @0x1c7e1c mov r11, r3 */
/* @0x1c7e20 str r3, [sp, #0x14] */
/* @0x1c7e24 bl 0x1c0f00 <_ZN13CLayerManager19GetNewSpriteElementEv> */
/* @0x1c7e28 ldr r3, [r6] */
/* @0x1c7e2c mov r2, r7 */
/* @0x1c7e30 mov r1, #6 */
/* @0x1c7e34 add r5, r5, #1 */
/* @0x1c7e38 ldr r3, [r3, #0xc] */
/* @0x1c7e3c mov r4, r0 */
/* @0x1c7e40 mov r0, r6 */
/* @0x1c7e44 blx r3 */
/* @0x1c7e48 mov r1, #0 */
/* @0x1c7e4c mov r0, r7 */
/* @0x1c7e50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7e54 ldr r3, [r6] */
/* @0x1c7e58 mov r2, r7 */
/* @0x1c7e5c mov r1, #8 */
/* @0x1c7e60 ldr r3, [r3, #0xc] */
/* @0x1c7e64 str r0, [r4, #0x1c] */
/* @0x1c7e68 mov r0, r6 */
/* @0x1c7e6c blx r3 */
/* @0x1c7e70 mov r1, #0 */
/* @0x1c7e74 mov r0, r7 */
/* @0x1c7e78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7e7c ldr r3, [r6] */
/* @0x1c7e80 mov r2, r7 */
/* @0x1c7e84 mov r1, #6 */
/* @0x1c7e88 ldr r3, [r3, #0xc] */
/* @0x1c7e8c str r0, [r4, #0x24] */
/* @0x1c7e90 mov r0, r6 */
/* @0x1c7e94 blx r3 */
/* @0x1c7e98 mov r1, #0 */
/* @0x1c7e9c mov r0, r7 */
/* @0x1c7ea0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7ea4 ldr r3, [r6] */
/* @0x1c7ea8 mov r2, r7 */
/* @0x1c7eac mov r1, #8 */
/* @0x1c7eb0 ldr r3, [r3, #0xc] */
/* @0x1c7eb4 str r0, [r4, #0x28] */
/* @0x1c7eb8 mov r0, r6 */
/* @0x1c7ebc blx r3 */
/* @0x1c7ec0 mov r1, #0 */
/* @0x1c7ec4 mov r0, r7 */
/* @0x1c7ec8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7ecc ldr r3, [r6] */
/* @0x1c7ed0 mov r2, r7 */
/* @0x1c7ed4 mov r1, #8 */
/* @0x1c7ed8 ldr r3, [r3, #0xc] */
/* @0x1c7edc str r0, [r4, #0x2c] */
/* @0x1c7ee0 mov r0, r6 */
/* @0x1c7ee4 blx r3 */
/* @0x1c7ee8 mov r1, #0 */
/* @0x1c7eec mov r0, r7 */
/* @0x1c7ef0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7ef4 ldr r3, [r6] */
/* @0x1c7ef8 mov r2, r7 */
/* @0x1c7efc mov r1, #8 */
/* @0x1c7f00 ldr r3, [r3, #0xc] */
/* @0x1c7f04 str r0, [r4, #0x30] */
/* @0x1c7f08 mov r0, r6 */
/* @0x1c7f0c blx r3 */
/* @0x1c7f10 mov r1, #0 */
/* @0x1c7f14 mov r0, r7 */
/* @0x1c7f18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7f1c ldr r3, [r6] */
/* @0x1c7f20 mov r2, r7 */
/* @0x1c7f24 mov r1, #6 */
/* @0x1c7f28 ldr r3, [r3, #0xc] */
/* @0x1c7f2c str r0, [r4, #0x34] */
/* @0x1c7f30 mov r0, r6 */
/* @0x1c7f34 blx r3 */
/* @0x1c7f38 mov r1, #0 */
/* @0x1c7f3c mov r0, r7 */
/* @0x1c7f40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7f44 ldr r3, [r6] */
/* @0x1c7f48 mov r2, r7 */
/* @0x1c7f4c mov r1, #8 */
/* @0x1c7f50 ldr r3, [r3, #0xc] */
/* @0x1c7f54 str r0, [r4, #0x38] */
/* @0x1c7f58 mov r0, r6 */
/* @0x1c7f5c blx r3 */
/* @0x1c7f60 mov r1, #0 */
/* @0x1c7f64 mov r0, r7 */
/* @0x1c7f68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7f6c ldr r3, [r6] */
/* @0x1c7f70 mov r2, r7 */
/* @0x1c7f74 mov r1, #8 */
/* @0x1c7f78 ldr r3, [r3, #0xc] */
/* @0x1c7f7c str r0, [r4, #0x3c] */
/* @0x1c7f80 mov r0, r6 */
/* @0x1c7f84 blx r3 */
/* @0x1c7f88 mov r1, #0 */
/* @0x1c7f8c mov r0, r7 */
/* @0x1c7f90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7f94 ldr r3, [r6] */
/* @0x1c7f98 mov r2, r7 */
/* @0x1c7f9c mov r1, #8 */
/* @0x1c7fa0 ldr r3, [r3, #0xc] */
/* @0x1c7fa4 str r0, [r4, #0x40] */
/* @0x1c7fa8 mov r0, r6 */
/* @0x1c7fac blx r3 */
/* @0x1c7fb0 mov r1, #0 */
/* @0x1c7fb4 mov r0, r7 */
/* @0x1c7fb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7fbc ldr r3, [r11] */
/* @0x1c7fc0 mov r2, r4 */
/* @0x1c7fc4 mov r1, r10 */
/* @0x1c7fc8 subs r12, r9, r3 */
/* @0x1c7fcc rsbs r3, r12, #0 */
/* @0x1c7fd0 adcs r3, r3, r12 */
/* @0x1c7fd4 str r0, [r4, #0x44] */
/* @0x1c7fd8 mov r0, r9 */
/* @0x1c7fdc bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c7fe0 cmp r5, r8 */
/* @0x1c7fe4 bne 0x1c7e24 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x954> */
/* ── 组 D 前的计数：<=0 → 1c8370 收尾（撤帧返回）────────────────────
 */

/* @0x1c7fe8 ldr r3, [r6] */
/* @0x1c7fec mov r1, #6 */
/* @0x1c7ff0 mov r2, r7 */
/* @0x1c7ff4 mov r0, r6 */
/* @0x1c7ff8 ldr r3, [r3, #0xc] */
/* @0x1c7ffc blx r3 */
/* @0x1c8000 mov r0, r7 */
/* @0x1c8004 mov r1, #0 */
/* @0x1c8008 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c800c subs r11, r0, #0 */
/* @0x1c8010 ble 0x1c8370 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xea0> */
/* ── 组 D type 7（80 字节）：不走工厂，在函数内就地构造 ──────────────────
 *   1c8014 取池槽、1c8024 取 Alloc 站点串（Room_Layers.cpp）、1c8058 r0 = 80
 *   初值 1c8064..1c80c0：+0x04 = -1、+0x08 字节 = 1、+0x0c..+0x18 = 非 0、+0x1c = 0、
 *     +0x20 = -1、+0x24/+0x28 = 0.0f、+0x2c/+0x30 = 非 0、+0x34/+0x38 = 1.0f、+0x3c = 0.0f、
 *     +0x40 = -1、+0x44 = 1.0f、+0x48/+0x4c = 非 0、+0x00 = 7
 *   ⇒ 与 Duplicate 的 case 7 逐项相同，两处独立构造同一类（可互校）
 */

/* @0x1c8014 ldr r3, [pc, #-0x708] */
/* @0x1c8018 mov r9, #0 */
/* @0x1c801c ldr r12, [sp, #0x1c] */
/* @0x1c8020 mov r4, r9 */
/* @0x1c8024 ldr r8, [pc, #-0x714] */
/* @0x1c8028 vldr s16, [pc, #844] */
/* @0x1c802c ldr r10, [r12, r3] */
/* @0x1c8030 add r8, pc, r8 */
/* @0x1c8034 ldr r2, [r10, #0x8] */
/* @0x1c8038 cmp r2, #0 */
/* @0x1c803c bne 0x1c8114 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xc44> */
/* @0x1c8040 ldr r3, [r10, #0x10] */
/* @0x1c8044 cmp r3, #0 */
/* @0x1c8048 ble 0x1c810c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xc3c> */
/* @0x1c804c mov r5, r2 */
/* @0x1c8050 mov r1, r8 */
/* @0x1c8054 mov r3, #1 */
/* @0x1c8058 mov r0, #80 */
/* @0x1c805c mov r2, #63 */
/* @0x1c8060 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c8064 mvn r3, #0 */
/* @0x1c8068 mov r1, #7 */
/* @0x1c806c cmp r0, #0 */
/* @0x1c8070 beq 0x1c80c4 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xbf4> */
/* @0x1c8074 mov r2, #1065353216 */
/* @0x1c8078 strb r4, [r0, #0x8] */
/* @0x1c807c str r4, [r0, #0xc] */
/* @0x1c8080 vstr s16, [r0, #36] */
/* @0x1c8084 str r4, [r0, #0x10] */
/* @0x1c8088 vstr s16, [r0, #40] */
/* @0x1c808c str r4, [r0, #0x14] */
/* @0x1c8090 vstr s16, [r0, #60] */
/* @0x1c8094 str r4, [r0, #0x18] */
/* @0x1c8098 str r3, [r0, #0x4] */
/* @0x1c809c str r3, [r0, #0x20] */
/* @0x1c80a0 str r4, [r0, #0x2c] */
/* @0x1c80a4 str r4, [r0, #0x30] */
/* @0x1c80a8 str r3, [r0, #0x40] */
/* @0x1c80ac str r4, [r0, #0x48] */
/* @0x1c80b0 str r2, [r0, #0x34] */
/* @0x1c80b4 str r4, [r0, #0x4c] */
/* @0x1c80b8 str r2, [r0, #0x38] */
/* @0x1c80bc str r1, [r0] */
/* @0x1c80c0 str r2, [r0, #0x44] */
/* @0x1c80c4 ldr r3, [r10] */
/* @0x1c80c8 add r5, r5, #1 */
/* @0x1c80cc ldr r2, [r10, #0x8] */
/* @0x1c80d0 cmp r3, #0 */
/* @0x1c80d4 streq r0, [r10, #0x4] */
/* @0x1c80d8 strne r0, [r3, #0x18] */
/* @0x1c80dc add r2, r2, #1 */
/* @0x1c80e0 streq r3, [r0, #0x18] */
/* @0x1c80e4 streq r3, [r0, #0x14] */
/* @0x1c80e8 strne r3, [r0, #0x14] */
/* @0x1c80ec ldr r3, [r10, #0x10] */
/* @0x1c80f0 streq r0, [r10] */
/* @0x1c80f4 strne r0, [r10] */
/* @0x1c80f8 strne r4, [r0, #0x18] */
/* @0x1c80fc cmp r5, r3 */
/* @0x1c8100 str r2, [r10, #0x8] */
/* @0x1c8104 blt 0x1c8050 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xb80> */
/* @0x1c8108 ldr r2, [r10, #0x8] */
/* @0x1c810c lsl r3, r3, #1 */
/* @0x1c8110 str r3, [r10, #0x10] */
/* ── 组 D 弹池 + 13 个字段读序 ─────────────────────────────────────
 *   +0x1c b → +0x20 i → +0x24 f → +0x28 f → +0x2c i → +0x30 i → +0x34 f → +0x38 f →
 *   +0x3c f → +0x40 u32 → +0x44 f → +0x48 i → +0x4c i
 */

/* @0x1c8114 ldr r5, [r10] */
/* @0x1c8118 sub r2, r2, #1 */
/* @0x1c811c mov r0, r6 */
/* @0x1c8120 add r9, r9, #1 */
/* @0x1c8124 ldr r3, [r5, #0x18] */
/* @0x1c8128 ldr r1, [r5, #0x14] */
/* @0x1c812c cmp r3, #0 */
/* @0x1c8130 strne r1, [r3, #0x14] */
/* @0x1c8134 ldrne r1, [r5, #0x14] */
/* @0x1c8138 ldrne r3, [r5, #0x18] */
/* @0x1c813c streq r1, [r10] */
/* @0x1c8140 cmp r1, #0 */
/* @0x1c8144 streq r3, [r10, #0x4] */
/* @0x1c8148 strne r3, [r1, #0x18] */
/* @0x1c814c mov r1, #6 */
/* @0x1c8150 ldr r3, [r6] */
/* @0x1c8154 str r2, [r10, #0x8] */
/* @0x1c8158 mov r2, r7 */
/* @0x1c815c ldr r3, [r3, #0xc] */
/* @0x1c8160 blx r3 */
/* @0x1c8164 mov r1, #0 */
/* @0x1c8168 mov r0, r7 */
/* @0x1c816c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c8170 ldr r3, [r6] */
/* @0x1c8174 mov r2, r7 */
/* @0x1c8178 mov r1, #6 */
/* @0x1c817c ldr r3, [r3, #0xc] */
/* @0x1c8180 strb r0, [r5, #0x1c] */
/* @0x1c8184 mov r0, r6 */
/* @0x1c8188 blx r3 */
/* @0x1c818c mov r1, #0 */
/* @0x1c8190 mov r0, r7 */
/* @0x1c8194 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8198 ldr r3, [r6] */
/* @0x1c819c mov r2, r7 */
/* @0x1c81a0 mov r1, #8 */
/* @0x1c81a4 ldr r3, [r3, #0xc] */
/* @0x1c81a8 str r0, [r5, #0x20] */
/* @0x1c81ac mov r0, r6 */
/* @0x1c81b0 blx r3 */
/* @0x1c81b4 mov r1, #0 */
/* @0x1c81b8 mov r0, r7 */
/* @0x1c81bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c81c0 ldr r3, [r6] */
/* @0x1c81c4 mov r2, r7 */
/* @0x1c81c8 mov r1, #8 */
/* @0x1c81cc ldr r3, [r3, #0xc] */
/* @0x1c81d0 str r0, [r5, #0x24] */
/* @0x1c81d4 mov r0, r6 */
/* @0x1c81d8 blx r3 */
/* @0x1c81dc mov r1, #0 */
/* @0x1c81e0 mov r0, r7 */
/* @0x1c81e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c81e8 ldr r3, [r6] */
/* @0x1c81ec mov r2, r7 */
/* @0x1c81f0 mov r1, #6 */
/* @0x1c81f4 ldr r3, [r3, #0xc] */
/* @0x1c81f8 str r0, [r5, #0x28] */
/* @0x1c81fc mov r0, r6 */
/* @0x1c8200 blx r3 */
/* @0x1c8204 mov r1, #0 */
/* @0x1c8208 mov r0, r7 */
/* @0x1c820c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8210 ldr r3, [r6] */
/* @0x1c8214 mov r2, r7 */
/* @0x1c8218 mov r1, #6 */
/* @0x1c821c ldr r3, [r3, #0xc] */
/* @0x1c8220 str r0, [r5, #0x2c] */
/* @0x1c8224 mov r0, r6 */
/* @0x1c8228 blx r3 */
/* @0x1c822c mov r1, #0 */
/* @0x1c8230 mov r0, r7 */
/* @0x1c8234 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8238 ldr r3, [r6] */
/* @0x1c823c mov r2, r7 */
/* @0x1c8240 mov r1, #8 */
/* @0x1c8244 ldr r3, [r3, #0xc] */
/* @0x1c8248 str r0, [r5, #0x30] */
/* @0x1c824c mov r0, r6 */
/* @0x1c8250 blx r3 */
/* @0x1c8254 mov r1, #0 */
/* @0x1c8258 mov r0, r7 */
/* @0x1c825c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c8260 ldr r3, [r6] */
/* @0x1c8264 mov r2, r7 */
/* @0x1c8268 mov r1, #8 */
/* @0x1c826c ldr r3, [r3, #0xc] */
/* @0x1c8270 str r0, [r5, #0x34] */
/* @0x1c8274 mov r0, r6 */
/* @0x1c8278 blx r3 */
/* @0x1c827c mov r1, #0 */
/* @0x1c8280 mov r0, r7 */
/* @0x1c8284 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c8288 ldr r3, [r6] */
/* @0x1c828c mov r2, r7 */
/* @0x1c8290 mov r1, #8 */
/* @0x1c8294 ldr r3, [r3, #0xc] */
/* @0x1c8298 str r0, [r5, #0x38] */
/* @0x1c829c mov r0, r6 */
/* @0x1c82a0 blx r3 */
/* @0x1c82a4 mov r1, #0 */
/* @0x1c82a8 mov r0, r7 */
/* @0x1c82ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c82b0 ldr r3, [r6] */
/* @0x1c82b4 mov r2, r7 */
/* @0x1c82b8 mov r1, #5 */
/* @0x1c82bc ldr r3, [r3, #0xc] */
/* @0x1c82c0 str r0, [r5, #0x3c] */
/* @0x1c82c4 mov r0, r6 */
/* @0x1c82c8 blx r3 */
/* @0x1c82cc mov r1, #0 */
/* @0x1c82d0 mov r0, r7 */
/* @0x1c82d4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1c82d8 ldr r3, [r6] */
/* @0x1c82dc mov r2, r7 */
/* @0x1c82e0 mov r1, #8 */
/* @0x1c82e4 ldr r3, [r3, #0xc] */
/* @0x1c82e8 str r0, [r5, #0x40] */
/* @0x1c82ec mov r0, r6 */
/* @0x1c82f0 blx r3 */
/* @0x1c82f4 mov r1, #0 */
/* @0x1c82f8 mov r0, r7 */
/* @0x1c82fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c8300 ldr r3, [r6] */
/* @0x1c8304 mov r2, r7 */
/* @0x1c8308 mov r1, #6 */
/* @0x1c830c ldr r3, [r3, #0xc] */
/* @0x1c8310 str r0, [r5, #0x44] */
/* @0x1c8314 mov r0, r6 */
/* @0x1c8318 blx r3 */
/* @0x1c831c mov r1, #0 */
/* @0x1c8320 mov r0, r7 */
/* @0x1c8324 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8328 ldr r3, [r6] */
/* @0x1c832c mov r2, r7 */
/* @0x1c8330 mov r1, #6 */
/* @0x1c8334 ldr r3, [r3, #0xc] */
/* @0x1c8338 str r0, [r5, #0x48] */
/* @0x1c833c mov r0, r6 */
/* @0x1c8340 blx r3 */
/* @0x1c8344 mov r1, #0 */
/* @0x1c8348 mov r0, r7 */
/* @0x1c834c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8350 mov r2, r5 */
/* @0x1c8354 ldr r1, [sp, #0x4] */
/* @0x1c8358 mov r3, #0 */
/* @0x1c835c str r0, [r5, #0x4c] */
/* ── 组 D 收尾：AddElementToLayer(房间, 层, 元素, false) ─────────────────
 *   前三组走 AddNewElement，第四组走 AddElementToLayer —— 两个不同入口，
 *   差别在于元素是否已经属于某个层（本卡未证其内部）。
 */

/* @0x1c8360 ldr r0, [sp, #0xc] */
/* @0x1c8364 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c8368 cmp r9, r11 */
/* @0x1c836c bne 0x1c8034 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xb64> */
/* ── 公共出口：add sp,#36 / vpop {d8,d9} / pop {r4-r11,pc}（void）──────────
 */

/* @0x1c8370 add sp, sp, #36 */
/* @0x1c8374 vpop {d8, d9} */
/* @0x1c8378 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c837c andeq r0, r0, r0 */
