/* cally 逆向卡：BuildRoomLayers + InitLayerFunctions（原版 libyoyo.so，armv7）
 * @func 0x1c6070 0x1c6c74  size 3076  766 条  _ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers
 * @func 0x1c1540 0x1c2a90  size 5456  1364 条  _ZN13CLayerManager18InitLayerFunctionsEv
 * 级别: 骨架 —— 两节共 2130 条指令逐条落锚；第 2 节「名字 → handler → 形参个数」151 条三元组
 *       是完整的（可直接当注册表查），第 1 节的 层记录 → CLayer 字段映射被 7 个 GML handler
 *       反读坐实（depth/x/y/hspeed/vspeed/visible/name 全部对上）。
 *       未钉：层类型 2/3 元素在 GML 侧的名字、AddNewElement 第 4 实参语义、Function_Add 第 4
 *       实参（151 处恒 1）、记录 +0x0c..+0x1c 的原始类型（整字搬运，handler 按 float 读）、
 *       60 字节元素的 +0x34 所有权（本函数是借用房间文件，DuplicateRoomLayers 是自有）。
 * 符号: CLayerManager::BuildRoomLayers(CRoom*, YYRoomLayers*)
 *       CLayerManager::InitLayerFunctions()
 * 同层: Init 0x1b6f00、CleanRoomLayers 0x1b93c8、InsertLayerIntoActiveList 0x1c30f8、
 *       AddNewElement 0x1c5ff0、AddElementToLayer 0x1c451c、DuplicateRoomLayers 0x1c47e0、
 *       DeSerializeLayer 0x1c74d0、SetLayerIndexWatermark 0x1b79f0、GetLayerFromID 0x1b8868、
 *       GetLayerFromName 0x1b897c、GetTargetRoomObj 0x1ba730、Function_Add 0xcdf84、
 *       MemoryManager::Alloc 0x27ce78、CTimingSource::Reset 0x214728
 *
 * ── 一句话 ─────────────────────────────────────────────────────────────
 *   第 1 节把「房间文件里的层表」翻译成运行时层链：YYRoomLayers 块头给层数，随后每层一个
 *   32 位偏移指向层记录；记录头 9 个字段原样搬进新 CLayer（池弹出、112 字节、
 *   Room_Layers.h 行 63），记录 +0x08 的层类型不进 CLayer，只决定往这层里塞哪几类元素；
 *   元素全部经 AddNewElement 挂链，最后 InsertLayerIntoActiveList + 抬高 layer id 水位。
 *   名字、瓦片像素都不复制 —— 直接指向数据块。
 *   第 2 节是同一族的另一头：把 151 个 layer_/tilemap_/tile_ 内建挂进 GML 函数表。
 *
 * ── 第 1 节：YYRoomLayers 块 → CLayer 字段（本卡的核心表）──────────────────
 *   块（r1 进来；调用点 CRoom::LoadFromChunk 0x1af0cc 取 YYRoom+0x58 的偏移换算成指针）：
 *     +0x00 int   层数 N
 *     +0x04 int[N] 层记录偏移（相对房间数据基址 = [[0x544c44]]）
 *   层记录：
 *     +0x00 int   名字偏移（0 → 名字留 NULL）            → CLayer+0x1c  （浅引用，不 strdup）
 *     +0x04 int                                          → CLayer+0x00  id
 *     +0x08 int   层类型 1..4                            → ★ 不进 CLayer，只做 4 路开关
 *     +0x0c int                                          → CLayer+0x04  depth
 *     +0x10 整字                                         → CLayer+0x08  x
 *     +0x14 整字                                         → CLayer+0x0c  y
 *     +0x18 整字                                         → CLayer+0x10  hspeed
 *     +0x1c 整字                                         → CLayer+0x14  vspeed
 *     +0x20 int   非 0 即 1                              → CLayer+0x18  visible
 *     +0x24..     按层类型解释（见下表）
 *   ⇒ 记录里没有「动态层筛子」(+0x19)、没有 +0x20/+0x24/+0x28(=ctor 的 -1)、
 *     没有 +0x64 —— 这些位置全部停在 ctor 值。
 *
 * ── 层类型 → 元素集（同一份 CLayer，元素用 AddNewElement 挂上）───────────────
 *   1  背景：1 个 32B 元素(type 1, 池 0x54268c) + 1 个 44B 子对象
 *            子对象 = Alloc(44, Room_Layers.cpp, 240, 1)（唯一非池对象）
 *            元素+0x1c = 子对象；元素+0x0c = CLayer+0x1c（层名）
 *   2  阵列：n 个 36B 元素(type 2, 池 0x542678)；n = 记录+0x24，值数组从 +0x28 起
 *            每个元素只写 +0x1c ← 数组里的裸字（不做基址换算）
 *   3  两组：记录+0x24 → 子块{个数; 偏移[]} → n 个 80B 元素(type 7, 池 0x542614)
 *            记录+0x28 → 子块{个数; 偏移[]} → m 个 72B 元素(type 4, 池 0x542650)
 *   4  瓦片图：1 个 60B 元素(type 5, 池 0x54263c)
 *            记录+0x24→元素+0x1c、+0x28→+0x28、+0x2c→+0x2c、+0x30→+0x34（= &记录+0x30）
 *            元素+0x38 = 0x7fffffff
 *   0 或 >4：不建元素，只挂层
 *
 * ── CLayer（112 字节，池 0x5426a0）—— 与本卡两个函数都相关的偏移 ─────────────
 *   +0x00 id        +0x04 depth      +0x08 x     +0x0c y     +0x10 hspeed  +0x14 vspeed
 *   +0x18 byte 可见  +0x19 byte 动态层筛子（本函数不写，保持 0）  +0x1c name（char*）
 *   +0x20/+0x24/+0x28 = -1（ctor 值，本函数不写）
 *   +0x30..+0x57 CTimingSource（40 字节，ctor 只 Reset）
 *   +0x58 元素链头（AddNewElement 维护）  +0x5c/+0x60 = 0  +0x64 = 1
 *   +0x68 next  +0x6c prev（层链 / 池自由链同一对偏移）
 *
 * ── 池协议（层池与 6 个元素池共用，池头 20 字节）───────────────────────────
 *   +0x00 链头  +0x04 链尾  +0x08 可用数  +0x10 容量
 *   取用 = 链路头弹出；用完 = 压回同一个链头（LIFO）；可用数 0 时一次 Alloc「容量」个再压链，容量翻倍。
 *   元素池的链接字段是 +0x14(next)/+0x18(prev)，层的链接字段是 +0x68/+0x6c。
 *
 * ── 第 2 节：InitLayerFunctions 的注册表模板 ────────────────────────────────
 *   ldr r1,[pc,#imm] → 负的 GOT 槽偏移（槽 = 0x3f1c58 + 偏移，槽里是 handler 地址）
 *   ldr r0,[pc,#imm] → 名字串相对偏移；add r0,pc,r0 → .rodata 里的名字
 *   mov r2,#argc ; mov r3,r2 或 mov r3,#1 ; ldr r1,[r4,r1] ; bl Function_Add
 *   第 4 实参 151 处全是 1。argc=1 的块用 mov r3,r2（两个立即数同值，编译器复用寄存器），
 *   argc>=2 的块用 mov r3,#1 —— 不能把 mov r3,r2 读成「r3 = argc」。
 *   调用点：InitGMLFunctions 0x2a2bb4（唯一），排在 InitPushFunctions / InitYoYoFunctions /
 *   InitMetroFunctions 之后。
 *
 * ── 151 条注册表总览 ──────────────────────────────────────────────────
 *   分组：layer_* 通用 39、layer_background_* 27、layer_sprite_* 24、tilemap_* 22、
 *         layer_tile_* 21、tile_* 10、layer_tilemap_* 4、instance_*_layer 2、draw_* 2
 *   argc：0×6 1×74 2×59 3×5 4×3 5×2 6×1 8×1
 *   151 个名字互不重复，handler 只有 149 个：
 *     layer_background_sprite 与 layer_background_change 共用 F_LayerBackgroundSprite 0x1bc980
 *   字面量池 0x1c2548..0x1c29fc = 302 字 = 1 个 GOT 基址偏移 + 151 对(槽偏移, 名字偏移)；
 *   objdump 把名字偏移那半边译成 andseq / ldrsb 之类的伪指令，是数据不是指令。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────
 */


/* ══════════════════════════════════════════════════════════════════════════
 * 第 1 节  CLayerManager::BuildRoomLayers  0x1c6070 .. 0x1c6c70（3076 B / 766 条）
 * 唯一调用点 CRoom::LoadFromChunk 0x1af0cc：
 *     mov r0, r4                  ; r4 = this(CRoom*)
 *     bl  BuildRoomLayers         ; r1 = 数据基址 + [YYRoom+0x58]
 *   [YYRoom+0x58] == 0 时 r1 = 0，进来就被判空挡掉
 * ══════════════════════════════════════════════════════════════════════════ */

/* ── 帧与形参：r0 = CRoom*（也当 CLayerManager* 用），r1 = YYRoomLayers* ─────────
 *   push {r4-r11,lr} + vpush {d8,d9} + sub sp,#60 → 15 个栈槽（下条注释列表）
 *   r0 == 0 或 r1 == 0 都跳到 0x1c6a84 撤帧返回
 *   ★ 符号写的是 CLayerManager 的成员函数，但全函数没有 this 语义：r0 就是房间，
 *     既被传给 AddNewElement(CRoom*,CLayer*,CLayerElementBase*,bool) 的 r0，
 *     也被传给 InsertLayerIntoActiveList(CRoom*,CLayer*) 的 r0。
 *     这一族接口按「静态成员 + 显式 CRoom*」实现（CleanRoomLayers / DuplicateRoomLayers 同样形状），
 *     所以形参就是 r0/r1 两个，没有第三个。
 */
/* @0x1c6070 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c6074 vpush {d8, d9} */
/* @0x1c6078 sub sp, sp, #60 */
/* ── 判空 + 取 GOT 基址 ─────────────────────────────────────────────────
 *   0x1c6088 ldr r0,[pc,#0x3c0] → 0x0022bbc4；0x1c608c add r0,pc,r0 → 0x3f1c58（.got 段内）
 *   ⇒ sp+0x10 = GOT 基址；本函数所有全局都从它 + 负偏移取
 *   栈槽全景：
 *     +0x04 this(CRoom*)      +0x08 当前 CLayer*        +0x0c 已建层数 i
 *     +0x10 GOT 基址 0x3f1c58 +0x14 块游标（每层 +4）    +0x18 暂存记录指针
 *     +0x1c 层数 N            +0x20 &数据基址持有者 0x544c44
 *     +0x24 水位全局地址 0x5425f8
 *     +0x28 / +0x30 / +0x34 三个 "Room_Layers.h" 串副本（不同分配点各用一份）
 */
/* @0x1c607c cmp r0, #0 */
/* @0x1c6080 mov r4, r1 */
/* @0x1c6084 str r0, [sp, #0x4] */
/* @0x1c6088 ldr r0, [pc, #0x3c0] */
/* @0x1c608c add r0, pc, r0 */
/* @0x1c6090 str r0, [sp, #0x10] */
/* @0x1c6094 beq 0x1c6a84 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa14> */
/* @0x1c6098 cmp r1, #0 */
/* @0x1c609c beq 0x1c6a84 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa14> */
/* ── 一次性初始化闸门：静态字节 0x5425ed ─────────────────────────────────
 *   GOT+0xffffec08 → 槽 0x3f0860 → 0x5425ed（池簇前面一个 char，地址是奇数）
 *   ldrb == 0 → 0x1c6c6c: bl CLayerManager::Init()，返回后 b 0x1c60b4 重新读块头
 *   Init 0x1b6f00 自己开头也读同一个字节（0x1b6f20），末尾 0x1b76f0..0x1b76f8 把它置 1
 *   ⇒ 0x5425ed = 「CLayerManager 已初始化」，本函数是它的第二个消费者
 *   ★ 第一次进来时 Init() 会建池，然后本函数从头再走一遍。
 *     注意别把 Init 里 0x1b6f2c-0x1b6f38 那句「写 0x7fffffff」当成 layer 水位：
 *     那个 GOT 槽是 0xffffebc8 → 0x3f0820 → .data 静态块 0x3f50e0（邻近 1.0f/-1.0f/0xfeeedead
 *     的默认值块），跟本函数读的 0x5425f8 不是一个全局；0x5425f8 只由
 *     SetLayerIndexWatermark 0x1b79f0 写，.bss 初值 0 就够用（max(0, id)）。
 */
/* @0x1c60a0 ldr r3, [pc, #0x3ac] */
/* @0x1c60a4 ldr r3, [r0, r3] */
/* @0x1c60a8 ldrb r3, [r3] */
/* @0x1c60ac cmp r3, #0 */
/* @0x1c60b0 beq 0x1c6c6c <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xbfc> */
/* ── 块头：N = [block+0x00]，<= 0 直接返回 ───────────────────────────────
 *   r4 = YYRoomLayers*；N 存 sp+0x1c；i（sp+0xc）清 0
 *   循环条件在 0x1c6a7c：i != N 就回 0x1c6118 取下一层
 *   ⇒ 块 = { int 层数; int 层记录偏移[N]; }，层记录偏移相对房间数据基址
 */
/* @0x1c60b4 ldr r1, [r4] */
/* @0x1c60b8 cmp r1, #0 */
/* @0x1c60bc str r1, [sp, #0x1c] */
/* @0x1c60c0 ble 0x1c6a84 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa14> */
/* @0x1c60c4 str r4, [sp, #0x14] */
/* @0x1c60c8 mov r4, #0 */
/* @0x1c60cc str r4, [sp, #0xc] */
/* ── 常量与全局 ─────────────────────────────────────────────────────────
 *   s18（0x1c60d0）= 0.0f    s19（0x1c60e0）= 255.0f    d8（0x1c60d8）= 0.0（双精度）
 *   0x1c60d4 / 0x1c60fc / 0x1c6108 三处 add r4,pc,r4 都落在同一串
 *     "jni/../jni/yoyo/../../../Files/Room/Room_Layers.h"（0x34d69c）
 *   GOT 槽（槽地址 = 0x3f1c58 + 负偏移；槽里存的是全局的地址）：
 *     +0xffffec0c → 0x3f0864 → 0x5426a0   CLayer 池
 *     +0xffffec30 → 0x3f0888 → 0x5425f8   layer id 水位（int，SetLayerIndexWatermark 直写）
 *   池簇（.bss 里连排的 20 字节池头，步长 0x14）：
 *     0x5425fc 0x542614 0x542628 0x54263c 0x542650 0x542664 0x542678 0x54268c 0x5426a0
 *   本函数用到其中 6 个：
 *     0x5426a0 CLayer(112)   0x54268c type1(32)   0x542678 type2(36)
 *     0x54263c type5(60)     0x542614 type7(80)   0x542650 type4(72)
 */
/* @0x1c60d0 vldr s18, [pc, #880] */
/* @0x1c60d4 ldr r4, [pc, #0x37c] */
/* @0x1c60d8 vldr d8, [pc, #864] */
/* @0x1c60dc ldr r2, [pc, #0x378] */
/* @0x1c60e0 vldr s19, [pc, #868] */
/* @0x1c60e4 add r4, pc, r4 */
/* @0x1c60e8 ldr r3, [pc, #0x370] */
/* @0x1c60ec str r4, [sp, #0x28] */
/* @0x1c60f0 ldr r4, [sp, #0x10] */
/* @0x1c60f4 ldr r10, [r4, r2] */
/* @0x1c60f8 ldr r3, [r4, r3] */
/* @0x1c60fc ldr r4, [pc, #0x360] */
/* @0x1c6100 add r4, pc, r4 */
/* @0x1c6104 str r4, [sp, #0x34] */
/* @0x1c6108 ldr r4, [pc, #0x358] */
/* @0x1c610c str r3, [sp, #0x24] */
/* @0x1c6110 add r4, pc, r4 */
/* @0x1c6114 str r4, [sp, #0x30] */
/* ── 层池扩容：可用数为 0 时一次分配「容量」个 112 字节 CLayer ──────────────
 *   池头：+0x00 链头  +0x04 链尾  +0x08 可用数  +0x10 容量（+0x0c 本函数不读）
 *   Alloc(112, Room_Layers.h, 63, 1)：r0=112、r1=串、r2=63(行号)、r3=1
 *   压链是「插链头」：新.next(+0x68)=旧头、旧头.prev(+0x6c)=新、新.prev=0、池头=新；
 *   链空时额外把链尾也指向新（0x1c61b0..0x1c61e8）。空表取用/回收都在同一个头 → LIFO。
 *   ★ 同一段压链序列在 DuplicateRoomLayers 是 0x1c4ad4..0x1c4b0c，逐字相同，
 *     两个函数的池协议没有差别（注意字段方向：+0x68 是 next、+0x6c 是 prev，
 *     依据是 0x1c6214/0x1c6224 的弹出路径：prev==0 的那端才是链头）
 *   0x1c61fc/0x1c6200 补齐后容量翻倍（lsl #1）
 *   新对象初值（.h 行 63 的内联 ctor）：
 *     +0x00=-1  +0x04=0  +0x08/+0x0c/+0x10/+0x14=0.0f  +0x18 字节=1  +0x19 字节=0
 *     +0x1c=0   +0x20/+0x24/+0x28=-1  +0x48..0x4f=0.0（d8）
 *     CTimingSource::Reset(this+0x30) → +0x30..+0x57 是 40 字节计时器
 *     +0x58=0  +0x5c=0  +0x60=0  +0x64=1  +0x68=0  +0x6c=0
 */
/* @0x1c6118 ldr r4, [r10, #0x8] */
/* @0x1c611c cmp r4, #0 */
/* @0x1c6120 bne 0x1c6204 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x194> */
/* @0x1c6124 ldr r3, [r10, #0x10] */
/* @0x1c6128 cmp r3, #0 */
/* @0x1c612c ble 0x1c61fc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x18c> */
/* @0x1c6130 ldr r8, [sp, #0x28] */
/* @0x1c6134 mov r5, #1 */
/* @0x1c6138 mov r3, #1 */
/* @0x1c613c mov r0, #112 */
/* @0x1c6140 mov r1, r8 */
/* @0x1c6144 mov r2, #63 */
/* @0x1c6148 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c614c mov r7, #0 */
/* @0x1c6150 mvn r3, #0 */
/* @0x1c6154 subs r6, r0, #0 */
/* @0x1c6158 add r0, r6, #48 */
/* @0x1c615c beq 0x1c61b0 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x140> */
/* @0x1c6160 str r3, [r6] */
/* @0x1c6164 vstr s18, [r6, #8] */
/* @0x1c6168 str r7, [r6, #0x4] */
/* @0x1c616c vstr s18, [r6, #12] */
/* @0x1c6170 vstr s18, [r6, #16] */
/* @0x1c6174 vstr s18, [r6, #20] */
/* @0x1c6178 strb r5, [r6, #0x18] */
/* @0x1c617c vstr d8, [r6, #72] */
/* @0x1c6180 strb r7, [r6, #0x19] */
/* @0x1c6184 str r7, [r6, #0x1c] */
/* @0x1c6188 str r3, [r6, #0x20] */
/* @0x1c618c str r3, [r6, #0x24] */
/* @0x1c6190 str r3, [r6, #0x28] */
/* @0x1c6194 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c6198 str r7, [r6, #0x5c] */
/* @0x1c619c str r7, [r6, #0x58] */
/* @0x1c61a0 str r7, [r6, #0x60] */
/* @0x1c61a4 str r5, [r6, #0x64] */
/* @0x1c61a8 str r7, [r6, #0x68] */
/* @0x1c61ac str r7, [r6, #0x6c] */
/* @0x1c61b0 ldr r3, [r10] */
/* @0x1c61b4 mov r1, #0 */
/* @0x1c61b8 add r4, r4, #1 */
/* @0x1c61bc ldr r2, [r10, #0x8] */
/* @0x1c61c0 cmp r3, r1 */
/* @0x1c61c4 streq r6, [r10, #0x4] */
/* @0x1c61c8 strne r6, [r3, #0x6c] */
/* @0x1c61cc add r2, r2, #1 */
/* @0x1c61d0 streq r3, [r6, #0x6c] */
/* @0x1c61d4 streq r3, [r6, #0x68] */
/* @0x1c61d8 strne r3, [r6, #0x68] */
/* @0x1c61dc ldr r3, [r10, #0x10] */
/* @0x1c61e0 streq r6, [r10] */
/* @0x1c61e4 strne r6, [r10] */
/* @0x1c61e8 strne r1, [r6, #0x6c] */
/* @0x1c61ec cmp r4, r3 */
/* @0x1c61f0 str r2, [r10, #0x8] */
/* @0x1c61f4 blt 0x1c6138 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xc8> */
/* @0x1c61f8 ldr r4, [r10, #0x8] */
/* @0x1c61fc lsl r3, r3, #1 */
/* @0x1c6200 str r3, [r10, #0x10] */
/* ── 弹池 + 取本层记录 ──────────────────────────────────────────────────
 *   0x1c6204 r7 = 链头 = 新 CLayer；0x1c6208/0x1c620c 可用数 -1
 *   0x1c6214..0x1c623c 把 r7 从双向链摘掉（+0x68 next / +0x6c prev）
 *   0x1c621c ldr r11,[r4,#0x4]! → 块游标 +4，读出本层的「记录偏移」；游标存回 sp+0x14
 *   0x1c6248 偏移 == 0 → r11 保持 0；否则
 *     GOT+0xffffbcf4 → 槽 0x3ed94c → 0x544c44，再 ldr 一次 = 房间数据基址
 *     r11 = 基址 + 偏移  ⇒ r11 = 层记录指针
 *   ★ 0x544c44 是「持有数据基址指针」的全局；YYRoomLayers 里所有偏移都相对它
 */
/* @0x1c6204 ldr r7, [r10] */
/* @0x1c6208 sub r4, r4, #1 */
/* @0x1c620c str r4, [r10, #0x8] */
/* @0x1c6210 ldr r4, [sp, #0x14] */
/* @0x1c6214 ldr r3, [r7, #0x6c] */
/* @0x1c6218 ldr r2, [r7, #0x68] */
/* @0x1c621c cmp r3, #0 */
/* @0x1c6220 ldr r11, [r4, #0x4]! */
/* @0x1c6224 strne r2, [r3, #0x68] */
/* @0x1c6228 ldrne r2, [r7, #0x68] */
/* @0x1c622c ldrne r3, [r7, #0x6c] */
/* @0x1c6230 streq r2, [r10] */
/* @0x1c6234 cmp r2, #0 */
/* @0x1c6238 streq r3, [r10, #0x4] */
/* @0x1c623c strne r3, [r2, #0x6c] */
/* @0x1c6240 cmp r11, #0 */
/* @0x1c6244 str r4, [sp, #0x14] */
/* @0x1c6248 beq 0x1c6260 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x1f0> */
/* ── 层名：记录 +0x00 是名字偏移，同样按数据基址换算；0 则名字留 NULL ────────
 *   0x1c625c / 0x1c627c 两处 add 用的是同一对（基址持有者, 基址）
 *   ★ 不 strdup：CLayer+0x1c 直接指向数据块里的字符串（浅引用）。
 *     与 DuplicateRoomLayers 里「MemoryInWad(name)==0 才深拷贝」的分支正好互补
 */
/* @0x1c624c ldr r3, [pc, #0x220] */
/* @0x1c6250 ldr r4, [sp, #0x10] */
/* @0x1c6254 ldr r3, [r4, r3] */
/* @0x1c6258 ldr r3, [r3] */
/* @0x1c625c add r11, r3, r11 */
/* @0x1c6260 ldr r3, [r11] */
/* @0x1c6264 cmp r3, #0 */
/* @0x1c6268 beq 0x1c6280 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x210> */
/* @0x1c626c ldr r2, [pc, #0x200] */
/* @0x1c6270 ldr r4, [sp, #0x10] */
/* @0x1c6274 ldr r2, [r4, r2] */
/* @0x1c6278 ldr r2, [r2] */
/* @0x1c627c add r3, r2, r3 */
/* ── 公共面：层记录 → CLayer（9 个字段；开关量归一成 0/1）─────────────────
 *   记录 +0x00 名字偏移 → CLayer+0x1c name（浅引用）
 *   记录 +0x04          → CLayer+0x00 id
 *   记录 +0x08 层类型   → ★ 不进 CLayer，只给下面 4 路开关用
 *   记录 +0x0c          → CLayer+0x04 depth
 *   记录 +0x10          → CLayer+0x08 x        （整字搬运，handler 按 float 读）
 *   记录 +0x14          → CLayer+0x0c y
 *   记录 +0x18          → CLayer+0x10 hspeed
 *   记录 +0x1c          → CLayer+0x14 vspeed
 *   记录 +0x20          → CLayer+0x18 visible  （adds 定标志 + movne → 非 0 即 1）
 *   ★ 字段语义由 7 个 GML handler 反读坐实（都是 GetLayerFromID/Name 之后读字段）：
 *     F_LayerGetDepth 0x1bab4c ldr [r0,#4]      F_LayerGetX       0x1bb1f8 vldr [r0,#8]
 *     F_LayerGetY     0x1bb29c vldr [r0,#12]    F_LayerGetHspeed  0x1bb4a0 vldr [r0,#16]
 *     F_LayerGetVspeed 0x1bb544 vldr [r0,#20]   F_LayerGetVisible 0x1baf1c ldrb [r0,#0x18]
 *     F_LayerGetName  0x1bbe7c ldr [r0,#0x1c]
 *   ★ ctor 写了但本函数不再碰：+0x19（动态层筛子，保持 0）、+0x20/+0x24/+0x28（-1）、
 *     +0x58（元素链头，交给 AddNewElement）、+0x5c/+0x60、+0x64（1）、+0x68/+0x6c
 */
/* @0x1c6280 ldr r2, [r11, #0x10] */
/* @0x1c6284 ldr r1, [r11, #0xc] */
/* @0x1c6288 ldr r0, [r11, #0x4] */
/* @0x1c628c ldr r12, [r11, #0x8] */
/* @0x1c6290 str r2, [r7, #0x8] */
/* @0x1c6294 ldr r2, [r11, #0x20] */
/* @0x1c6298 str r1, [r7, #0x4] */
/* @0x1c629c ldr r1, [r11, #0x14] */
/* @0x1c62a0 adds r2, r2, #0 */
/* @0x1c62a4 str r3, [r7, #0x1c] */
/* @0x1c62a8 sub r3, r12, #1 */
/* @0x1c62ac movne r2, #1 */
/* @0x1c62b0 str r0, [r7] */
/* @0x1c62b4 str r1, [r7, #0xc] */
/* @0x1c62b8 ldr r1, [r11, #0x18] */
/* @0x1c62bc str r1, [r7, #0x10] */
/* @0x1c62c0 ldr r1, [r11, #0x1c] */
/* @0x1c62c4 strb r2, [r7, #0x18] */
/* @0x1c62c8 str r1, [r7, #0x14] */
/* ── 4 路开关：r3 = 层类型 - 1；表基址 = 0x1c62d8（add pc,pc,r3,lsl#2 的 pc）────
 *   类型 1 → 0x1c6a90   32B 元素(type1) + 44B 子对象        ← 背景层
 *   类型 2 → 0x1c68fc   36B 元素(type2) × n
 *   类型 3 → 0x1c6494   80B 元素(type7) × n + 72B 元素(type4) × m
 *   类型 4 → 0x1c62e8   60B 元素(type5) × 1                  ← 瓦片图层
 *   类型 0 或 > 4 → 0x1c6a48：只把层挂上去，不建元素
 */
/* @0x1c62cc cmp r3, #3 */
/* @0x1c62d0 addls pc, pc, r3, lsl #2 */
/* @0x1c62d4 b 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c62d8 b 0x1c6a90 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa20> */
/* @0x1c62dc b 0x1c68fc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x88c> */
/* @0x1c62e0 b 0x1c6494 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x424> */
/* @0x1c62e4 b 0x1c62e8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x278> */
/* ── 层类型 4：一个 60 字节元素（type=5，瓦片图）────────────────────────────
 *   池 0x54263c；Alloc(60, Room_Layers.h, 63, 1)
 *   初值：+0x00=5  +0x04=-1  +0x08 字节=0  +0x0c/+0x10/+0x14/+0x18=0  +0x1c=-1
 *         +0x20/+0x24/+0x30=0.0f  +0x28/+0x2c/+0x34=0  +0x38=0x7fffffff
 *   记录 → 元素：+0x24→+0x1c  +0x28→+0x28  +0x2c→+0x2c  +0x30→+0x34
 *                CLayer+0x1c（层名）→ 元素+0x0c
 *   ★ 瓦片数据不复制：元素 +0x34 直接 = &记录+0x30，等于把房间文件当只读底图用。
 *     DuplicateRoomLayers 的同类元素反而会新分配 w*h*4 再 memcpy ⇒ 同一类元素的
 *     +0x34 有两种所有权（借用 / 自有），谁释放记 open
 */
/* @0x1c62e8 ldr r3, [pc, #0x17c] */
/* @0x1c62ec ldr r4, [sp, #0x10] */
/* @0x1c62f0 ldr r5, [r4, r3] */
/* @0x1c62f4 ldr r6, [r5, #0x8] */
/* @0x1c62f8 cmp r6, #0 */
/* @0x1c62fc bne 0x1c63c8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x358> */
/* @0x1c6300 ldr r3, [r5, #0x10] */
/* @0x1c6304 cmp r3, #0 */
/* @0x1c6308 ble 0x1c63c0 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x350> */
/* @0x1c630c ldr r8, [sp, #0x34] */
/* @0x1c6310 mov r4, r6 */
/* @0x1c6314 mov r1, r8 */
/* @0x1c6318 mov r2, #63 */
/* @0x1c631c mov r3, #1 */
/* @0x1c6320 mov r0, #60 */
/* @0x1c6324 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6328 ldr r3, [r5] */
/* @0x1c632c mvn r2, #0 */
/* @0x1c6330 mvn r12, #-2147483648 */
/* @0x1c6334 mov r1, #5 */
/* @0x1c6338 cmp r0, #0 */
/* @0x1c633c beq 0x1c637c <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x30c> */
/* @0x1c6340 strb r4, [r0, #0x8] */
/* @0x1c6344 vstr s18, [r0, #32] */
/* @0x1c6348 str r4, [r0, #0xc] */
/* @0x1c634c vstr s18, [r0, #36] */
/* @0x1c6350 str r4, [r0, #0x10] */
/* @0x1c6354 vstr s18, [r0, #48] */
/* @0x1c6358 str r4, [r0, #0x14] */
/* @0x1c635c str r4, [r0, #0x18] */
/* @0x1c6360 str r2, [r0, #0x4] */
/* @0x1c6364 str r2, [r0, #0x1c] */
/* @0x1c6368 str r4, [r0, #0x28] */
/* @0x1c636c str r4, [r0, #0x2c] */
/* @0x1c6370 str r4, [r0, #0x34] */
/* @0x1c6374 str r12, [r0, #0x38] */
/* @0x1c6378 str r1, [r0] */
/* @0x1c637c cmp r3, #0 */
/* @0x1c6380 strne r0, [r3, #0x18] */
/* @0x1c6384 streq r3, [r0, #0x18] */
/* @0x1c6388 add r6, r6, #1 */
/* @0x1c638c streq r3, [r0, #0x14] */
/* @0x1c6390 strne r3, [r0, #0x14] */
/* @0x1c6394 ldr r3, [r5, #0x10] */
/* @0x1c6398 ldr r2, [r5, #0x8] */
/* @0x1c639c streq r0, [r5, #0x4] */
/* @0x1c63a0 streq r0, [r5] */
/* @0x1c63a4 add r2, r2, #1 */
/* @0x1c63a8 strne r0, [r5] */
/* @0x1c63ac strne r4, [r0, #0x18] */
/* @0x1c63b0 cmp r6, r3 */
/* @0x1c63b4 str r2, [r5, #0x8] */
/* @0x1c63b8 blt 0x1c6314 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x2a4> */
/* @0x1c63bc ldr r6, [r5, #0x8] */
/* @0x1c63c0 lsl r3, r3, #1 */
/* @0x1c63c4 str r3, [r5, #0x10] */
/* @0x1c63c8 ldr r3, [r5] */
/* @0x1c63cc sub r6, r6, #1 */
/* @0x1c63d0 ldr r0, [r11, #0x2c] */
/* @0x1c63d4 ldr r12, [r11, #0x24] */
/* @0x1c63d8 ldr r2, [r3, #0x18] */
/* @0x1c63dc ldr r1, [r3, #0x14] */
/* @0x1c63e0 cmp r2, #0 */
/* @0x1c63e4 str r6, [r5, #0x8] */
/* @0x1c63e8 strne r1, [r2, #0x14] */
/* @0x1c63ec ldrne r1, [r3, #0x14] */
/* @0x1c63f0 ldrne r2, [r3, #0x18] */
/* @0x1c63f4 streq r1, [r5] */
/* @0x1c63f8 cmp r1, #0 */
/* @0x1c63fc streq r2, [r5, #0x4] */
/* @0x1c6400 strne r2, [r1, #0x18] */
/* @0x1c6404 add r1, r11, #48 */
/* @0x1c6408 ldr r2, [r11, #0x28] */
/* @0x1c640c ldr lr, [r7, #0x1c] */
/* @0x1c6410 str r12, [r3, #0x1c] */
/* @0x1c6414 str r2, [r3, #0x28] */
/* @0x1c6418 mov r2, r3 */
/* @0x1c641c str r0, [r3, #0x2c] */
/* @0x1c6420 str r1, [r3, #0x34] */
/* @0x1c6424 mov r1, r7 */
/* @0x1c6428 str lr, [r3, #0xc] */
/* @0x1c642c mov r3, #0 */
/* @0x1c6430 ldr r0, [sp, #0x4] */
/* @0x1c6434 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6438 b 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* ── 0x1c6440..0x1c6490 是字面量池，不是指令 ───────────────────────────────
 *   0x1c6440 d8 = 0.0（双精度）    0x1c6448 s18 = 0.0f    0x1c644c s19 = 255.0f
 *   0x1c6450 GOT 基址偏移 0x22bbc4 其余是负的 GOT 槽偏移与名字偏移
 *   objdump 把负偏移那半边按 ARM 译码显示成 cmnmi / eoreq / ldrsbeq / mulseq，实际是数据
 */
/* @0x1c643c nop */
/* @0x1c644c cmnmi pc, #0 */
/* @0x1c6450 eoreq r11, r2, r4, asr #23 */
/* @0x1c6454 .word 0xffffec08 */
/* @0x1c6458 ldrheq r7, [r8], -r0 */
/* @0x1c645c .word 0xffffec0c */
/* @0x1c6460 .word 0xffffec30 */
/* @0x1c6464 mulseq r8, r4, r5 */
/* @0x1c6468 andseq r7, r8, r4, lsl #11 */
/* @0x1c646c .word 0xffffec20 */
/* @0x1c6470 .word 0xffffec28 */
/* @0x1c6474 .word 0xffffbcf4 */
/* @0x1c6478 .word 0xffffec1c */
/* @0x1c647c andseq r6, r8, r12, ror pc */
/* @0x1c6480 andseq r6, r8, r4, ror sp */
/* @0x1c6484 .word 0xffffec14 */
/* @0x1c6488 .word 0xffffec10 */
/* @0x1c648c ldrsbeq r6, [r8], -r0 */
/* @0x1c6490 ldrsheq r6, [r8], -r12 */
/* ── 层类型 3 第一段：记录 +0x24 是子块偏移 → 子块 { int 个数; int 偏移[]; } ─────
 *   子块首字 = 个数；元素偏移从 +0x04 起、步长 4，逐个用数据基址换算成指针
 *   元素：80 字节、type=7、池 0x542614、Alloc(80, Room_Layers.h, 63, 1)
 *   初值：+0x00=7  +0x04=-1  +0x20=-1  +0x40=-1  +0x08 字节=0
 *         +0x0c/+0x10/+0x14/+0x18/+0x2c/+0x30/+0x48/+0x4c=0
 *         +0x24/+0x28/+0x3c=0.0f   +0x34/+0x38/+0x44=1.0f   +0x1c 字节=1
 *   子记录 → 元素（整字搬运；两个 vldr 先按 int 读再 vcvt.f32.s32 转 float）：
 *     +0x00 → +0x24(float)   +0x04 → +0x28(float)   +0x08 → +0x20   +0x0c → +0x48
 *     +0x10 → +0x4c          +0x14 → +0x2c          +0x18 → +0x30   +0x24 → +0x34
 *     +0x28 → +0x38          +0x2c → +0x40(去高 8 位) / +0x44((>>24)/255.0f)
 *   ★ 元素 +0x0c = 0（不是层名：这段 r4 被清零）；+0x3c 保持 0.0f
 */
/* @0x1c6494 ldr r3, [r11, #0x24] */
/* @0x1c6498 cmp r3, #0 */
/* @0x1c649c beq 0x1c66cc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x65c> */
/* @0x1c64a0 ldr r2, [pc, #-0x34] */
/* @0x1c64a4 ldr r4, [sp, #0x10] */
/* @0x1c64a8 ldr r2, [r4, r2] */
/* @0x1c64ac str r2, [sp, #0x20] */
/* @0x1c64b0 ldr r2, [r2] */
/* @0x1c64b4 adds r12, r2, r3 */
/* @0x1c64b8 beq 0x1c66cc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x65c> */
/* @0x1c64bc ldr r3, [r2, r3] */
/* @0x1c64c0 cmp r3, #0 */
/* @0x1c64c4 ble 0x1c66cc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x65c> */
/* @0x1c64c8 ldr r3, [pc, #-0x60] */
/* @0x1c64cc mov r6, #0 */
/* @0x1c64d0 ldr r0, [sp, #0x10] */
/* @0x1c64d4 mov r4, r6 */
/* @0x1c64d8 ldr r8, [sp, #0x30] */
/* @0x1c64dc mov r9, r12 */
/* @0x1c64e0 ldr r5, [r0, r3] */
/* @0x1c64e4 str r10, [sp, #0x2c] */
/* @0x1c64e8 mov r10, r12 */
/* @0x1c64ec str r11, [sp, #0x18] */
/* @0x1c64f0 str r7, [sp, #0x8] */
/* @0x1c64f4 ldr r11, [r9, #0x4]! */
/* @0x1c64f8 ldr r2, [r5, #0x8] */
/* @0x1c64fc cmp r11, #0 */
/* @0x1c6500 ldrne r1, [sp, #0x20] */
/* @0x1c6504 ldrne r3, [r1] */
/* @0x1c6508 addne r11, r3, r11 */
/* @0x1c650c cmp r2, #0 */
/* @0x1c6510 bne 0x1c65e8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x578> */
/* @0x1c6514 ldr r3, [r5, #0x10] */
/* @0x1c6518 cmp r3, #0 */
/* @0x1c651c ble 0x1c65e0 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x570> */
/* @0x1c6520 mov r7, r2 */
/* @0x1c6524 mov r1, r8 */
/* @0x1c6528 mov r3, #1 */
/* @0x1c652c mov r0, #80 */
/* @0x1c6530 mov r2, #63 */
/* @0x1c6534 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6538 mvn r3, #0 */
/* @0x1c653c mov r1, #7 */
/* @0x1c6540 cmp r0, #0 */
/* @0x1c6544 beq 0x1c6598 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x528> */
/* @0x1c6548 mov r2, #1065353216 */
/* @0x1c654c strb r4, [r0, #0x8] */
/* @0x1c6550 str r4, [r0, #0xc] */
/* @0x1c6554 vstr s18, [r0, #36] */
/* @0x1c6558 str r4, [r0, #0x10] */
/* @0x1c655c vstr s18, [r0, #40] */
/* @0x1c6560 str r4, [r0, #0x14] */
/* @0x1c6564 vstr s18, [r0, #60] */
/* @0x1c6568 str r4, [r0, #0x18] */
/* @0x1c656c str r3, [r0, #0x4] */
/* @0x1c6570 str r3, [r0, #0x20] */
/* @0x1c6574 str r4, [r0, #0x2c] */
/* @0x1c6578 str r4, [r0, #0x30] */
/* @0x1c657c str r3, [r0, #0x40] */
/* @0x1c6580 str r4, [r0, #0x48] */
/* @0x1c6584 str r2, [r0, #0x34] */
/* @0x1c6588 str r4, [r0, #0x4c] */
/* @0x1c658c str r2, [r0, #0x38] */
/* @0x1c6590 str r1, [r0] */
/* @0x1c6594 str r2, [r0, #0x44] */
/* @0x1c6598 ldr r3, [r5] */
/* @0x1c659c add r7, r7, #1 */
/* @0x1c65a0 ldr r2, [r5, #0x8] */
/* @0x1c65a4 cmp r3, #0 */
/* @0x1c65a8 streq r0, [r5, #0x4] */
/* @0x1c65ac strne r0, [r3, #0x18] */
/* @0x1c65b0 add r2, r2, #1 */
/* @0x1c65b4 streq r3, [r0, #0x18] */
/* @0x1c65b8 streq r3, [r0, #0x14] */
/* @0x1c65bc strne r3, [r0, #0x14] */
/* @0x1c65c0 ldr r3, [r5, #0x10] */
/* @0x1c65c4 streq r0, [r5] */
/* @0x1c65c8 strne r0, [r5] */
/* @0x1c65cc strne r4, [r0, #0x18] */
/* @0x1c65d0 cmp r7, r3 */
/* @0x1c65d4 str r2, [r5, #0x8] */
/* @0x1c65d8 blt 0x1c6524 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x4b4> */
/* @0x1c65dc ldr r2, [r5, #0x8] */
/* @0x1c65e0 lsl r3, r3, #1 */
/* @0x1c65e4 str r3, [r5, #0x10] */
/* @0x1c65e8 ldr r12, [r5] */
/* @0x1c65ec vldr s14, [r11] */
/* @0x1c65f0 ldr r0, [r11, #0x24] */
/* @0x1c65f4 sub r2, r2, #1 */
/* @0x1c65f8 vldr s15, [r11, #4] */
/* @0x1c65fc vcvt.f32.s32 s14, s14 */
/* @0x1c6600 ldr r3, [r12, #0x18] */
/* @0x1c6604 mov lr, #1 */
/* @0x1c6608 ldr r1, [r12, #0x14] */
/* @0x1c660c add r6, r6, lr */
/* @0x1c6610 cmp r3, #0 */
/* @0x1c6614 strne r1, [r3, #0x14] */
/* @0x1c6618 ldrne r1, [r12, #0x14] */
/* @0x1c661c ldrne r3, [r12, #0x18] */
/* @0x1c6620 vcvt.f32.s32 s15, s15 */
/* @0x1c6624 streq r1, [r5] */
/* @0x1c6628 cmp r1, #0 */
/* @0x1c662c streq r3, [r5, #0x4] */
/* @0x1c6630 strne r3, [r1, #0x18] */
/* @0x1c6634 ldr r3, [r11, #0x2c] */
/* @0x1c6638 ldr r1, [r11, #0x8] */
/* @0x1c663c str r0, [r12, #0x34] */
/* @0x1c6640 lsr r0, r3, #24 */
/* @0x1c6644 str r2, [r5, #0x8] */
/* @0x1c6648 bic r3, r3, #-16777216 */
/* @0x1c664c ldr r2, [r11, #0x28] */
/* @0x1c6650 vmov s13, r0 */
/* @0x1c6654 str r3, [r12, #0x40] */
/* @0x1c6658 ldr r3, [r11, #0xc] */
/* @0x1c665c vcvt.f32.s32 s13, s13 */
/* @0x1c6660 str r1, [r12, #0x20] */
/* @0x1c6664 ldr r1, [r11, #0x14] */
/* @0x1c6668 str r3, [r12, #0x48] */
/* @0x1c666c ldr r3, [r11, #0x10] */
/* @0x1c6670 str r2, [r12, #0x38] */
/* @0x1c6674 mov r2, r12 */
/* @0x1c6678 ldr r0, [sp, #0x4] */
/* @0x1c667c str r3, [r12, #0x4c] */
/* @0x1c6680 vdiv.f32 s13, s13, s19 */
/* @0x1c6684 ldr r3, [r11, #0x18] */
/* @0x1c6688 str r1, [r12, #0x2c] */
/* @0x1c668c vstr s14, [r12, #36] */
/* @0x1c6690 vstr s18, [r12, #60] */
/* @0x1c6694 str r4, [r12, #0xc] */
/* @0x1c6698 ldr r1, [sp, #0x8] */
/* @0x1c669c vstr s13, [r12, #68] */
/* @0x1c66a0 str r3, [r12, #0x30] */
/* @0x1c66a4 mov r3, #0 */
/* @0x1c66a8 strb lr, [r12, #0x1c] */
/* @0x1c66ac vstr s15, [r12, #40] */
/* @0x1c66b0 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c66b4 ldr r3, [r10] */
/* @0x1c66b8 cmp r3, r6 */
/* @0x1c66bc bgt 0x1c64f4 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x484> */
/* @0x1c66c0 ldr r11, [sp, #0x18] */
/* @0x1c66c4 ldr r7, [sp, #0x8] */
/* @0x1c66c8 ldr r10, [sp, #0x2c] */
/* ── 层类型 3 第二段：记录 +0x28 也是子块偏移 → 72 字节元素（type=4，sprite）──
 *   同样 { int 个数; int 偏移[]; }；池 0x542650；Alloc(72, Room_Layers.h, 63, 1)
 *   初值：+0x00=4  +0x04=-1  +0x1c=-1  +0x38=-1  +0x20/+0x34/+0x40/+0x44=0.0f
 *         +0x24/+0x2c/+0x30/+0x3c=1.0f
 *   子记录 → 元素：
 *     +0x04 → +0x1c    +0x08 → +0x40(float)   +0x0c → +0x44(float)   +0x10 → +0x2c
 *     +0x14 → +0x30    +0x18 → 颜色 → +0x38(RGB) / +0x3c(alpha/255.0f)
 *     +0x1c → +0x24    +0x20 → +0x28          +0x24 → +0x20          +0x28 → +0x34
 *     +0x00 名字偏移 → +0x0c（这条会做基址换算；与上面 80B 元素的 +0x0c=0 不同）
 */
/* @0x1c66cc ldr r3, [r11, #0x28] */
/* @0x1c66d0 cmp r3, #0 */
/* @0x1c66d4 beq 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c66d8 ldr r2, [pc, #-0x26c] */
/* @0x1c66dc ldr r4, [sp, #0x10] */
/* @0x1c66e0 ldr r2, [r4, r2] */
/* @0x1c66e4 str r2, [sp, #0x20] */
/* @0x1c66e8 ldr r2, [r2] */
/* @0x1c66ec adds r11, r2, r3 */
/* @0x1c66f0 beq 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c66f4 ldr r2, [r2, r3] */
/* @0x1c66f8 cmp r2, #0 */
/* @0x1c66fc str r2, [sp, #0x8] */
/* @0x1c6700 ble 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c6704 ldr r3, [pc, #-0x294] */
/* @0x1c6708 mov r9, #0 */
/* @0x1c670c ldr r8, [pc, #-0x298] */
/* @0x1c6710 mov r5, r9 */
/* @0x1c6714 ldr r4, [r4, r3] */
/* @0x1c6718 add r8, pc, r8 */
/* @0x1c671c str r10, [sp, #0x2c] */
/* @0x1c6720 mov r10, r11 */
/* @0x1c6724 ldr r11, [sp, #0x20] */
/* @0x1c6728 str r7, [sp, #0x18] */
/* @0x1c672c ldr r12, [r10, #0x4]! */
/* @0x1c6730 ldr r6, [r4, #0x8] */
/* @0x1c6734 cmp r12, #0 */
/* @0x1c6738 ldrne r3, [r11] */
/* @0x1c673c moveq r7, r12 */
/* @0x1c6740 addne r7, r3, r12 */
/* @0x1c6744 cmp r6, #0 */
/* @0x1c6748 bne 0x1c6818 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x7a8> */
/* @0x1c674c ldr r3, [r4, #0x10] */
/* @0x1c6750 cmp r3, #0 */
/* @0x1c6754 ble 0x1c6810 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x7a0> */
/* @0x1c6758 mov r1, r8 */
/* @0x1c675c mov r2, #63 */
/* @0x1c6760 mov r0, #72 */
/* @0x1c6764 mov r3, #1 */
/* @0x1c6768 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c676c mvn r2, #0 */
/* @0x1c6770 mov r1, #4 */
/* @0x1c6774 cmp r0, #0 */
/* @0x1c6778 beq 0x1c67c8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x758> */
/* @0x1c677c mov r3, #1065353216 */
/* @0x1c6780 strb r5, [r0, #0x8] */
/* @0x1c6784 str r5, [r0, #0xc] */
/* @0x1c6788 vstr s18, [r0, #32] */
/* @0x1c678c str r5, [r0, #0x10] */
/* @0x1c6790 vstr s18, [r0, #52] */
/* @0x1c6794 str r5, [r0, #0x14] */
/* @0x1c6798 vstr s18, [r0, #64] */
/* @0x1c679c str r5, [r0, #0x18] */
/* @0x1c67a0 vstr s18, [r0, #68] */
/* @0x1c67a4 str r2, [r0, #0x4] */
/* @0x1c67a8 str r2, [r0, #0x1c] */
/* @0x1c67ac str r5, [r0, #0x28] */
/* @0x1c67b0 str r2, [r0, #0x38] */
/* @0x1c67b4 str r1, [r0] */
/* @0x1c67b8 str r3, [r0, #0x24] */
/* @0x1c67bc str r3, [r0, #0x2c] */
/* @0x1c67c0 str r3, [r0, #0x30] */
/* @0x1c67c4 str r3, [r0, #0x3c] */
/* @0x1c67c8 ldr r3, [r4] */
/* @0x1c67cc add r6, r6, #1 */
/* @0x1c67d0 ldr r2, [r4, #0x8] */
/* @0x1c67d4 cmp r3, #0 */
/* @0x1c67d8 streq r0, [r4, #0x4] */
/* @0x1c67dc strne r0, [r3, #0x18] */
/* @0x1c67e0 add r2, r2, #1 */
/* @0x1c67e4 streq r3, [r0, #0x18] */
/* @0x1c67e8 streq r3, [r0, #0x14] */
/* @0x1c67ec strne r3, [r0, #0x14] */
/* @0x1c67f0 ldr r3, [r4, #0x10] */
/* @0x1c67f4 streq r0, [r4] */
/* @0x1c67f8 strne r0, [r4] */
/* @0x1c67fc strne r5, [r0, #0x18] */
/* @0x1c6800 cmp r6, r3 */
/* @0x1c6804 str r2, [r4, #0x8] */
/* @0x1c6808 blt 0x1c6758 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x6e8> */
/* @0x1c680c ldr r6, [r4, #0x8] */
/* @0x1c6810 lsl r3, r3, #1 */
/* @0x1c6814 str r3, [r4, #0x10] */
/* @0x1c6818 ldr r2, [r4] */
/* @0x1c681c vldr s14, [r7, #8] */
/* @0x1c6820 ldr r0, [r7, #0x4] */
/* @0x1c6824 vldr s15, [r7, #12] */
/* @0x1c6828 vcvt.f32.s32 s14, s14 */
/* @0x1c682c sub r6, r6, #1 */
/* @0x1c6830 ldr r3, [r2, #0x18] */
/* @0x1c6834 add r9, r9, #1 */
/* @0x1c6838 ldr r1, [r2, #0x14] */
/* @0x1c683c cmp r3, #0 */
/* @0x1c6840 str r6, [r4, #0x8] */
/* @0x1c6844 strne r1, [r3, #0x14] */
/* @0x1c6848 ldrne r1, [r2, #0x14] */
/* @0x1c684c ldrne r3, [r2, #0x18] */
/* @0x1c6850 vcvt.f32.s32 s15, s15 */
/* @0x1c6854 streq r1, [r4] */
/* @0x1c6858 cmp r1, #0 */
/* @0x1c685c streq r3, [r4, #0x4] */
/* @0x1c6860 strne r3, [r1, #0x18] */
/* @0x1c6864 ldr r3, [r7, #0x18] */
/* @0x1c6868 ldr r1, [r7, #0x24] */
/* @0x1c686c str r1, [r2, #0x20] */
/* @0x1c6870 lsr r1, r3, #24 */
/* @0x1c6874 bic r3, r3, #-16777216 */
/* @0x1c6878 vmov s13, r1 */
/* @0x1c687c ldr r1, [r7, #0x20] */
/* @0x1c6880 str r0, [r2, #0x1c] */
/* @0x1c6884 vcvt.f32.s32 s13, s13 */
/* @0x1c6888 ldr r0, [r7, #0x1c] */
/* @0x1c688c str r0, [r2, #0x24] */
/* @0x1c6890 ldr r0, [r7, #0x10] */
/* @0x1c6894 str r1, [r2, #0x28] */
/* @0x1c6898 ldr r1, [r7, #0x14] */
/* @0x1c689c vdiv.f32 s13, s13, s19 */
/* @0x1c68a0 str r0, [r2, #0x2c] */
/* @0x1c68a4 ldr r0, [r7, #0x28] */
/* @0x1c68a8 str r1, [r2, #0x30] */
/* @0x1c68ac ldr r1, [r7] */
/* @0x1c68b0 vstr s14, [r2, #64] */
/* @0x1c68b4 str r3, [r2, #0x38] */
/* @0x1c68b8 vstr s15, [r2, #68] */
/* @0x1c68bc cmp r1, #0 */
/* @0x1c68c0 str r0, [r2, #0x34] */
/* @0x1c68c4 ldrne r3, [r11] */
/* @0x1c68c8 addne r1, r3, r1 */
/* @0x1c68cc mov r3, #0 */
/* @0x1c68d0 vstr s13, [r2, #60] */
/* @0x1c68d4 str r1, [r2, #0xc] */
/* @0x1c68d8 ldr r0, [sp, #0x4] */
/* @0x1c68dc ldr r1, [sp, #0x18] */
/* @0x1c68e0 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c68e4 ldr r2, [sp, #0x8] */
/* @0x1c68e8 cmp r9, r2 */
/* @0x1c68ec bne 0x1c672c <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x6bc> */
/* @0x1c68f0 ldr r7, [sp, #0x18] */
/* @0x1c68f4 ldr r10, [sp, #0x2c] */
/* @0x1c68f8 b 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* ── 层类型 2：记录 +0x24 = 个数，+0x28 起是裸字数组（步长 4）────────────────
 *   元素：36 字节、type=2、池 0x542678、Alloc(36, Room_Layers.h, 63, 1)
 *   初值：+0x00=2  +0x04=-1  +0x1c=-1  +0x08/+0x0c/+0x10/+0x14/+0x18/+0x20=0
 *   只写一个字段：元素 +0x1c ← 数组里的字（★ 原样存，不做基址换算）
 */
/* @0x1c68fc ldr r4, [r11, #0x24] */
/* @0x1c6900 cmp r4, #0 */
/* @0x1c6904 str r4, [sp, #0x8] */
/* @0x1c6908 ble 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c690c ldr r8, [pc, #-0x494] */
/* @0x1c6910 mov r9, #0 */
/* @0x1c6914 ldr r3, [pc, #-0x498] */
/* @0x1c6918 add r11, r11, #36 */
/* @0x1c691c ldr r0, [sp, #0x10] */
/* @0x1c6920 add r8, pc, r8 */
/* @0x1c6924 mov r5, r9 */
/* @0x1c6928 mvn r6, #0 */
/* @0x1c692c ldr r4, [r0, r3] */
/* @0x1c6930 str r10, [sp, #0x18] */
/* @0x1c6934 ldr r12, [r4, #0x8] */
/* @0x1c6938 cmp r12, #0 */
/* @0x1c693c bne 0x1c69e4 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x974> */
/* @0x1c6940 ldr r3, [r4, #0x10] */
/* @0x1c6944 cmp r3, #0 */
/* @0x1c6948 ble 0x1c69dc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x96c> */
/* @0x1c694c mov r10, r12 */
/* @0x1c6950 mov r3, #1 */
/* @0x1c6954 mov r0, #36 */
/* @0x1c6958 mov r1, r8 */
/* @0x1c695c mov r2, #63 */
/* @0x1c6960 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6964 mov r3, #2 */
/* @0x1c6968 cmp r0, #0 */
/* @0x1c696c beq 0x1c6994 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x924> */
/* @0x1c6970 strb r5, [r0, #0x8] */
/* @0x1c6974 str r5, [r0, #0xc] */
/* @0x1c6978 str r5, [r0, #0x10] */
/* @0x1c697c str r5, [r0, #0x14] */
/* @0x1c6980 str r5, [r0, #0x18] */
/* @0x1c6984 str r6, [r0, #0x4] */
/* @0x1c6988 str r6, [r0, #0x1c] */
/* @0x1c698c str r5, [r0, #0x20] */
/* @0x1c6990 str r3, [r0] */
/* @0x1c6994 ldr r3, [r4] */
/* @0x1c6998 add r10, r10, #1 */
/* @0x1c699c ldr r2, [r4, #0x8] */
/* @0x1c69a0 cmp r3, #0 */
/* @0x1c69a4 streq r0, [r4, #0x4] */
/* @0x1c69a8 strne r0, [r3, #0x18] */
/* @0x1c69ac add r2, r2, #1 */
/* @0x1c69b0 streq r3, [r0, #0x18] */
/* @0x1c69b4 streq r3, [r0, #0x14] */
/* @0x1c69b8 strne r3, [r0, #0x14] */
/* @0x1c69bc ldr r3, [r4, #0x10] */
/* @0x1c69c0 streq r0, [r4] */
/* @0x1c69c4 strne r0, [r4] */
/* @0x1c69c8 strne r5, [r0, #0x18] */
/* @0x1c69cc cmp r10, r3 */
/* @0x1c69d0 str r2, [r4, #0x8] */
/* @0x1c69d4 blt 0x1c6950 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x8e0> */
/* @0x1c69d8 ldr r12, [r4, #0x8] */
/* @0x1c69dc lsl r3, r3, #1 */
/* @0x1c69e0 str r3, [r4, #0x10] */
/* @0x1c69e4 ldr r3, [r4] */
/* @0x1c69e8 sub r12, r12, #1 */
/* @0x1c69ec str r12, [r4, #0x8] */
/* @0x1c69f0 add r9, r9, #1 */
/* @0x1c69f4 ldr r12, [r11, #0x4]! */
/* @0x1c69f8 ldr r2, [r3, #0x18] */
/* @0x1c69fc ldr r1, [r3, #0x14] */
/* @0x1c6a00 cmp r2, #0 */
/* @0x1c6a04 ldr r0, [sp, #0x4] */
/* @0x1c6a08 strne r1, [r2, #0x14] */
/* @0x1c6a0c ldrne r1, [r3, #0x14] */
/* @0x1c6a10 ldrne r2, [r3, #0x18] */
/* @0x1c6a14 streq r1, [r4] */
/* @0x1c6a18 cmp r1, #0 */
/* @0x1c6a1c streq r2, [r4, #0x4] */
/* @0x1c6a20 strne r2, [r1, #0x18] */
/* @0x1c6a24 mov r2, r3 */
/* @0x1c6a28 mov r1, r7 */
/* @0x1c6a2c str r12, [r3, #0x1c] */
/* @0x1c6a30 mov r3, #0 */
/* @0x1c6a34 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6a38 ldr r1, [sp, #0x8] */
/* @0x1c6a3c cmp r9, r1 */
/* @0x1c6a40 bne 0x1c6934 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x8c4> */
/* @0x1c6a44 ldr r10, [sp, #0x18] */
/* ── 每层收尾：挂进活动层链 + 抬高 layer id 水位 ──────────────────────────
 *   0x1c6a50 InsertLayerIntoActiveList(room, new_layer)
 *   0x1c6a54..0x1c6a74：水位 = max([0x5425f8], new_layer->id) → SetLayerIndexWatermark
 *   （0x1b79f0 的实现就是 ldr GOT; str r0,[0x5425f8]; bx lr）
 *   ★ 水位比的是 id（CLayer+0x00），不是层数
 */
/* @0x1c6a48 ldr r0, [sp, #0x4] */
/* @0x1c6a4c mov r1, r7 */
/* @0x1c6a50 bl 0x1c30f8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer> */
/* @0x1c6a54 ldr r4, [sp, #0x24] */
/* @0x1c6a58 ldr r3, [r7] */
/* @0x1c6a5c ldr r0, [r4] */
/* @0x1c6a60 ldr r4, [sp, #0xc] */
/* @0x1c6a64 cmp r0, r3 */
/* @0x1c6a68 movlt r0, r3 */
/* @0x1c6a6c add r4, r4, #1 */
/* @0x1c6a70 str r4, [sp, #0xc] */
/* @0x1c6a74 bl 0x1b79f0 <_ZN13CLayerManager22SetLayerIndexWatermarkEi> */
/* @0x1c6a78 ldr r0, [sp, #0x1c] */
/* @0x1c6a7c cmp r4, r0 */
/* @0x1c6a80 bne 0x1c6118 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa8> */
/* ── 正常出口 ─────────────────────────────────────────────────────────── */
/* @0x1c6a84 add sp, sp, #60 */
/* @0x1c6a88 vpop {d8, d9} */
/* @0x1c6a8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 层类型 1：一个 32 字节元素（type=1，背景）+ 一个 44 字节子对象 ───────────
 *   元素池 0x54268c、Alloc(32, Room_Layers.h, 63, 1)：
 *     +0x00=1  +0x04=-1  +0x08 字节=0  +0x0c/+0x10/+0x14/+0x18=0  +0x1c=0（随后换成子对象）
 *   子对象不在池里：Alloc(44, Room_Layers.cpp, 240, 1)
 *     ★ 全函数唯一报 .cpp 的分配点；DuplicateRoomLayers 的 44 字节子对象同样报 .cpp（行 608）
 *   记录 +0x24..+0x48 → 子对象 13 个字段（4 个开关归一、颜色拆 RGB + alpha）：
 *     +0x24 → +0x00(bool)  +0x28 → +0x01(bool)  +0x2c → +0x04
 *     +0x30 → +0x08(bool)  +0x34 → +0x09(bool)  +0x38 → +0x14(bool)
 *     +0x3c → +0x18(RGB) / +0x1c(alpha/255.0f)  +0x40 → +0x20
 *     +0x44 → +0x24        +0x48 → +0x28
 *     子对象 +0x0c / +0x10 恒写 1.0f（不受记录影响）
 *   元素 +0x0c = CLayer+0x1c（层名，浅引用）；元素 +0x1c = 子对象
 *   ⇒ 这 13 个字段的偏移集合与 DuplicateRoomLayers 的 44 字节深拷贝逐条一致
 */
/* @0x1c6a90 ldr r3, [pc, #-0x610] */
/* @0x1c6a94 ldr r0, [sp, #0x10] */
/* @0x1c6a98 ldr r4, [r0, r3] */
/* @0x1c6a9c ldr r12, [r4, #0x8] */
/* @0x1c6aa0 cmp r12, #0 */
/* @0x1c6aa4 bne 0x1c6b58 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xae8> */
/* @0x1c6aa8 ldr r3, [r4, #0x10] */
/* @0x1c6aac cmp r3, #0 */
/* @0x1c6ab0 ble 0x1c6b50 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xae0> */
/* @0x1c6ab4 ldr r6, [pc, #-0x630] */
/* @0x1c6ab8 mov r8, r12 */
/* @0x1c6abc mov r5, r12 */
/* @0x1c6ac0 mov r9, #1 */
/* @0x1c6ac4 add r6, pc, r6 */
/* @0x1c6ac8 mov r3, #1 */
/* @0x1c6acc mov r0, #32 */
/* @0x1c6ad0 mov r1, r6 */
/* @0x1c6ad4 mov r2, #63 */
/* @0x1c6ad8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6adc ldr r3, [r4] */
/* @0x1c6ae0 cmp r0, #0 */
/* @0x1c6ae4 beq 0x1c6b0c <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa9c> */
/* @0x1c6ae8 mvn r1, #0 */
/* @0x1c6aec strb r5, [r0, #0x8] */
/* @0x1c6af0 str r5, [r0, #0xc] */
/* @0x1c6af4 str r5, [r0, #0x10] */
/* @0x1c6af8 str r5, [r0, #0x14] */
/* @0x1c6afc str r5, [r0, #0x18] */
/* @0x1c6b00 str r1, [r0, #0x4] */
/* @0x1c6b04 str r5, [r0, #0x1c] */
/* @0x1c6b08 str r9, [r0] */
/* @0x1c6b0c cmp r3, #0 */
/* @0x1c6b10 strne r0, [r3, #0x18] */
/* @0x1c6b14 streq r3, [r0, #0x18] */
/* @0x1c6b18 add r8, r8, #1 */
/* @0x1c6b1c streq r3, [r0, #0x14] */
/* @0x1c6b20 strne r3, [r0, #0x14] */
/* @0x1c6b24 ldr r3, [r4, #0x10] */
/* @0x1c6b28 ldr r2, [r4, #0x8] */
/* @0x1c6b2c streq r0, [r4, #0x4] */
/* @0x1c6b30 streq r0, [r4] */
/* @0x1c6b34 add r2, r2, #1 */
/* @0x1c6b38 strne r0, [r4] */
/* @0x1c6b3c strne r5, [r0, #0x18] */
/* @0x1c6b40 cmp r8, r3 */
/* @0x1c6b44 str r2, [r4, #0x8] */
/* @0x1c6b48 blt 0x1c6ac8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa58> */
/* @0x1c6b4c ldr r12, [r4, #0x8] */
/* @0x1c6b50 lsl r3, r3, #1 */
/* @0x1c6b54 str r3, [r4, #0x10] */
/* @0x1c6b58 ldr r5, [r4] */
/* @0x1c6b5c sub r12, r12, #1 */
/* @0x1c6b60 ldr r1, [pc, #-0x6d8] */
/* @0x1c6b64 mov r0, #44 */
/* @0x1c6b68 str r12, [r4, #0x8] */
/* @0x1c6b6c ldr r3, [r5, #0x18] */
/* @0x1c6b70 add r1, pc, r1 */
/* @0x1c6b74 ldr r2, [r5, #0x14] */
/* @0x1c6b78 cmp r3, #0 */
/* @0x1c6b7c strne r2, [r3, #0x14] */
/* @0x1c6b80 ldrne r2, [r5, #0x14] */
/* @0x1c6b84 ldrne r3, [r5, #0x18] */
/* @0x1c6b88 streq r2, [r4] */
/* @0x1c6b8c cmp r2, #0 */
/* @0x1c6b90 streq r3, [r4, #0x4] */
/* @0x1c6b94 strne r3, [r2, #0x18] */
/* @0x1c6b98 mov r2, #240 */
/* @0x1c6b9c mov r3, #1 */
/* @0x1c6ba0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6ba4 ldr r3, [r11, #0x3c] */
/* @0x1c6ba8 ldr r1, [r11, #0x24] */
/* @0x1c6bac mov r12, #0 */
/* @0x1c6bb0 ldr r2, [r11, #0x28] */
/* @0x1c6bb4 mov lr, #1065353216 */
/* @0x1c6bb8 lsr r4, r3, #24 */
/* @0x1c6bbc subs r1, r1, r12 */
/* @0x1c6bc0 bic r3, r3, #-16777216 */
/* @0x1c6bc4 vmov s15, r4 */
/* @0x1c6bc8 movne r1, #1 */
/* @0x1c6bcc subs r2, r2, r12 */
/* @0x1c6bd0 vcvt.f32.s32 s15, s15 */
/* @0x1c6bd4 movne r2, #1 */
/* @0x1c6bd8 vdiv.f32 s15, s15, s19 */
/* @0x1c6bdc str r0, [r5, #0x1c] */
/* @0x1c6be0 strb r2, [r0, #0x1] */
/* @0x1c6be4 ldr r2, [r11, #0x2c] */
/* @0x1c6be8 strb r12, [r0, #0x14] */
/* @0x1c6bec ldr r12, [r11, #0x40] */
/* @0x1c6bf0 str r2, [r0, #0x4] */
/* @0x1c6bf4 ldr r2, [r11, #0x30] */
/* @0x1c6bf8 strb r1, [r0] */
/* @0x1c6bfc adds r2, r2, #0 */
/* @0x1c6c00 ldr r1, [r11, #0x34] */
/* @0x1c6c04 str r12, [r0, #0x20] */
/* @0x1c6c08 movne r2, #1 */
/* @0x1c6c0c ldr r12, [r11, #0x38] */
/* @0x1c6c10 adds r1, r1, #0 */
/* @0x1c6c14 str lr, [r0, #0xc] */
/* @0x1c6c18 str lr, [r0, #0x10] */
/* @0x1c6c1c str r3, [r0, #0x18] */
/* @0x1c6c20 movne r1, #1 */
/* @0x1c6c24 ldr r3, [r7, #0x1c] */
/* @0x1c6c28 cmp r12, #0 */
/* @0x1c6c2c ldr lr, [r11, #0x44] */
/* @0x1c6c30 strb r2, [r0, #0x8] */
/* @0x1c6c34 ldr r2, [r11, #0x48] */
/* @0x1c6c38 strb r1, [r0, #0x9] */
/* @0x1c6c3c mov r1, r7 */
/* @0x1c6c40 str lr, [r0, #0x24] */
/* @0x1c6c44 vstr s15, [r0, #28] */
/* @0x1c6c48 str r2, [r0, #0x28] */
/* @0x1c6c4c mov r2, r5 */
/* @0x1c6c50 str r3, [r5, #0xc] */
/* @0x1c6c54 movne r3, #1 */
/* @0x1c6c58 strbne r3, [r0, #0x14] */
/* @0x1c6c5c mov r3, #0 */
/* @0x1c6c60 ldr r0, [sp, #0x4] */
/* @0x1c6c64 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6c68 b 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* ── 闸门为 0 的入口：Init() 一次，再回 0x1c60b4 重新读块头 ────────────────── */
/* @0x1c6c6c bl 0x1b6f00 <_ZN13CLayerManager4InitEv> */
/* @0x1c6c70 b 0x1c60b4 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x44> */

/* ══════════════════════════════════════════════════════════════════════════
 * 第 2 节  CLayerManager::InitLayerFunctions  0x1c1540 .. 0x1c2a8c（5456 B / 1364 条）
 * 151 条注册 = 150 个 bl + 1 个尾调用 b（最后那条）
 * ══════════════════════════════════════════════════════════════════════════ */

/* ── 帧：push {r4,r5,r6,lr}；无栈帧、无溢出槽 ───────────────────────────────
 *   r4 = GOT 基址（0x1c1548 ldr / 0x1c1554 add r4,pc,r4 → 0x3f1c58）
 *   每个注册块只用 r0/r1/r2/r3；r5 只在别名块出现，r6 全程未用
 *   模板（151 份逐字同形，只有 4 个立即数不同）：
 *     ldr r1,[pc,#imm]  ; 负的 GOT 槽偏移 → 槽里是 handler 地址
 *     ldr r0,[pc,#imm]  ; 名字偏移
 *     mov r2,#argc
 *     mov r3,r2 / mov r3,#1
 *     ldr r1,[r4,r1]
 *     add r0,pc,r0
 *     bl 0xcdf84 Function_Add(name, handler, argc, true)
 *//* ── layer_*（通用层接口） ─────────────────────────────────────────────── */
/* @0x1c1540 push {r4, r5, r6, lr} */
/* @0x1c1544 mov r2, #1 */
/* @0x1c1548 ldr r4, [pc, #0xff8] */
/* @0x1c154c mov r3, r2 */
/* @0x1c1550 ldr r1, [pc, #0xff4] */
/* @0x1c1554 add r4, pc, r4 */
/* @0x1c1558 ldr r0, [pc, #0xff0] */
/* @0x1c155c ldr r1, [r4, r1] */
/* @0x1c1560 add r0, pc, r0 */
/* → layer_get_id  F_LayerGetId 0x1ba778  argc=1 */
/* @0x1c1564 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1568 ldr r1, [pc, #0xfe4] */
/* @0x1c156c ldr r0, [pc, #0xfe4] */
/* @0x1c1570 mov r2, #1 */
/* @0x1c1574 mov r3, r2 */
/* @0x1c1578 ldr r1, [r4, r1] */
/* @0x1c157c add r0, pc, r0 */
/* → layer_get_id_at_depth  F_LayerGetIdAtDepth 0x1ba800  argc=1 */
/* @0x1c1580 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1584 ldr r1, [pc, #0xfd0] */
/* @0x1c1588 ldr r0, [pc, #0xfd0] */
/* @0x1c158c mov r2, #1 */
/* @0x1c1590 mov r3, r2 */
/* @0x1c1594 ldr r1, [r4, r1] */
/* @0x1c1598 add r0, pc, r0 */
/* → layer_get_depth  F_LayerGetDepth 0x1baad4  argc=1 */
/* @0x1c159c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c15a0 ldr r1, [pc, #0xfbc] */
/* @0x1c15a4 ldr r0, [pc, #0xfbc] */
/* @0x1c15a8 mov r2, #2 */
/* @0x1c15ac mov r3, #1 */
/* @0x1c15b0 ldr r1, [r4, r1] */
/* @0x1c15b4 add r0, pc, r0 */
/* → layer_create  F_LayerCreate 0x1c3798  argc=2 */
/* @0x1c15b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c15bc ldr r1, [pc, #0xfa8] */
/* @0x1c15c0 ldr r0, [pc, #0xfa8] */
/* @0x1c15c4 mov r2, #1 */
/* @0x1c15c8 mov r3, r2 */
/* @0x1c15cc ldr r1, [r4, r1] */
/* @0x1c15d0 add r0, pc, r0 */
/* → layer_destroy  F_LayerDestroy 0x1bc0e0  argc=1 */
/* @0x1c15d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c15d8 ldr r1, [pc, #0xf94] */
/* @0x1c15dc ldr r0, [pc, #0xf94] */
/* @0x1c15e0 mov r2, #1 */
/* @0x1c15e4 mov r3, r2 */
/* @0x1c15e8 ldr r1, [r4, r1] */
/* @0x1c15ec add r0, pc, r0 */
/* → layer_destroy_instances  F_LayerDestroyInstances 0x1c01b4  argc=1 */
/* @0x1c15f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c15f4 ldr r1, [pc, #0xf80] */
/* @0x1c15f8 ldr r0, [pc, #0xf80] */
/* @0x1c15fc mov r2, #2 */
/* @0x1c1600 mov r3, #1 */
/* @0x1c1604 ldr r1, [r4, r1] */
/* @0x1c1608 add r0, pc, r0 */
/* → layer_add_instance  F_LayerAddInstance 0x1c6cf4  argc=2 */
/* @0x1c160c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1610 ldr r1, [pc, #0xf6c] */
/* @0x1c1614 ldr r0, [pc, #0xf6c] */
/* @0x1c1618 mov r2, #2 */
/* @0x1c161c mov r3, #1 */
/* @0x1c1620 ldr r1, [r4, r1] */
/* @0x1c1624 add r0, pc, r0 */
/* → layer_has_instance  F_LayerHasInstance 0x1baba8  argc=2 */
/* @0x1c1628 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c162c ldr r1, [pc, #0xf58] */
/* @0x1c1630 ldr r0, [pc, #0xf58] */
/* @0x1c1634 mov r2, #2 */
/* @0x1c1638 mov r3, #1 */
/* @0x1c163c ldr r1, [r4, r1] */
/* @0x1c1640 add r0, pc, r0 */
/* → layer_set_visible  F_LayerSetVisible 0x1badd4  argc=2 */
/* @0x1c1644 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1648 ldr r1, [pc, #0xf44] */
/* @0x1c164c ldr r0, [pc, #0xf44] */
/* @0x1c1650 mov r2, #1 */
/* @0x1c1654 mov r3, r2 */
/* @0x1c1658 ldr r1, [r4, r1] */
/* @0x1c165c add r0, pc, r0 */
/* → layer_get_visible  F_LayerGetVisible 0x1baeac  argc=1 */
/* @0x1c1660 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1664 ldr r1, [pc, #0xf30] */
/* @0x1c1668 ldr r0, [pc, #0xf30] */
/* @0x1c166c mov r2, #1 */
/* @0x1c1670 mov r3, r2 */
/* @0x1c1674 ldr r1, [r4, r1] */
/* @0x1c1678 add r0, pc, r0 */
/* → layer_exists  F_LayerExists 0x1baf88  argc=1 */
/* @0x1c167c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1680 ldr r1, [pc, #0xf1c] */
/* @0x1c1684 ldr r0, [pc, #0xf1c] */
/* @0x1c1688 mov r2, #2 */
/* @0x1c168c mov r3, #1 */
/* @0x1c1690 ldr r1, [r4, r1] */
/* @0x1c1694 add r0, pc, r0 */
/* → layer_x  F_LayerX 0x1bb028  argc=2 */
/* @0x1c1698 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c169c ldr r1, [pc, #0xf08] */
/* @0x1c16a0 ldr r0, [pc, #0xf08] */
/* @0x1c16a4 mov r2, #2 */
/* @0x1c16a8 mov r3, #1 */
/* @0x1c16ac ldr r1, [r4, r1] */
/* @0x1c16b0 add r0, pc, r0 */
/* → layer_y  F_LayerY 0x1bb0d8  argc=2 */
/* @0x1c16b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c16b8 ldr r1, [pc, #0xef4] */
/* @0x1c16bc ldr r0, [pc, #0xef4] */
/* @0x1c16c0 mov r2, #1 */
/* @0x1c16c4 mov r3, r2 */
/* @0x1c16c8 ldr r1, [r4, r1] */
/* @0x1c16cc add r0, pc, r0 */
/* → layer_get_x  F_LayerGetX 0x1bb188  argc=1 */
/* @0x1c16d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c16d4 ldr r1, [pc, #0xee0] */
/* @0x1c16d8 ldr r0, [pc, #0xee0] */
/* @0x1c16dc mov r2, #1 */
/* @0x1c16e0 mov r3, r2 */
/* @0x1c16e4 ldr r1, [r4, r1] */
/* @0x1c16e8 add r0, pc, r0 */
/* → layer_get_y  F_LayerGetY 0x1bb22c  argc=1 */
/* @0x1c16ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c16f0 ldr r1, [pc, #0xecc] */
/* @0x1c16f4 ldr r0, [pc, #0xecc] */
/* @0x1c16f8 mov r2, #2 */
/* @0x1c16fc mov r3, #1 */
/* @0x1c1700 ldr r1, [r4, r1] */
/* @0x1c1704 add r0, pc, r0 */
/* → layer_hspeed  F_LayerHspeed 0x1bb2d0  argc=2 */
/* @0x1c1708 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c170c ldr r1, [pc, #0xeb8] */
/* @0x1c1710 ldr r0, [pc, #0xeb8] */
/* @0x1c1714 mov r2, #2 */
/* @0x1c1718 mov r3, #1 */
/* @0x1c171c ldr r1, [r4, r1] */
/* @0x1c1720 add r0, pc, r0 */
/* → layer_vspeed  F_LayerVspeed 0x1bb380  argc=2 */
/* @0x1c1724 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1728 ldr r1, [pc, #0xea4] */
/* @0x1c172c ldr r0, [pc, #0xea4] */
/* @0x1c1730 mov r2, #1 */
/* @0x1c1734 mov r3, r2 */
/* @0x1c1738 ldr r1, [r4, r1] */
/* @0x1c173c add r0, pc, r0 */
/* → layer_get_hspeed  F_LayerGetHspeed 0x1bb430  argc=1 */
/* @0x1c1740 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1744 ldr r1, [pc, #0xe90] */
/* @0x1c1748 ldr r0, [pc, #0xe90] */
/* @0x1c174c mov r2, #1 */
/* @0x1c1750 mov r3, r2 */
/* @0x1c1754 ldr r1, [r4, r1] */
/* @0x1c1758 add r0, pc, r0 */
/* → layer_get_vspeed  F_LayerGetVspeed 0x1bb4d4  argc=1 */
/* @0x1c175c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1760 ldr r1, [pc, #0xe7c] */
/* @0x1c1764 ldr r0, [pc, #0xe7c] */
/* @0x1c1768 mov r2, #2 */
/* @0x1c176c mov r3, #1 */
/* @0x1c1770 ldr r1, [r4, r1] */
/* @0x1c1774 add r0, pc, r0 */
/* → layer_script_begin  F_LayerScriptBegin 0x1bb578  argc=2 */
/* @0x1c1778 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c177c ldr r1, [pc, #0xe68] */
/* @0x1c1780 ldr r0, [pc, #0xe68] */
/* @0x1c1784 mov r2, #2 */
/* @0x1c1788 mov r3, #1 */
/* @0x1c178c ldr r1, [r4, r1] */
/* @0x1c1790 add r0, pc, r0 */
/* → layer_script_end  F_LayerScriptEnd 0x1bb628  argc=2 */
/* @0x1c1794 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1798 ldr r1, [pc, #0xe54] */
/* @0x1c179c ldr r0, [pc, #0xe54] */
/* @0x1c17a0 mov r2, #2 */
/* @0x1c17a4 mov r3, #1 */
/* @0x1c17a8 ldr r1, [r4, r1] */
/* @0x1c17ac add r0, pc, r0 */
/* → layer_shader  F_LayerShader 0x1bb6d8  argc=2 */
/* @0x1c17b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c17b4 ldr r1, [pc, #0xe40] */
/* @0x1c17b8 ldr r0, [pc, #0xe40] */
/* @0x1c17bc mov r2, #1 */
/* @0x1c17c0 mov r3, r2 */
/* @0x1c17c4 ldr r1, [r4, r1] */
/* @0x1c17c8 add r0, pc, r0 */
/* → layer_get_script_begin  F_LayerGetScriptBegin 0x1bb788  argc=1 */
/* @0x1c17cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c17d0 ldr r1, [pc, #0xe2c] */
/* @0x1c17d4 ldr r0, [pc, #0xe2c] */
/* @0x1c17d8 mov r2, #1 */
/* @0x1c17dc mov r3, r2 */
/* @0x1c17e0 ldr r1, [r4, r1] */
/* @0x1c17e4 add r0, pc, r0 */
/* → layer_get_script_end  F_LayerGetScriptEnd 0x1bb838  argc=1 */
/* @0x1c17e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c17ec ldr r1, [pc, #0xe18] */
/* @0x1c17f0 ldr r0, [pc, #0xe18] */
/* @0x1c17f4 mov r2, #1 */
/* @0x1c17f8 mov r3, r2 */
/* @0x1c17fc ldr r1, [r4, r1] */
/* @0x1c1800 add r0, pc, r0 */
/* → layer_get_shader  F_LayerGetShader 0x1bb8e8  argc=1 */
/* @0x1c1804 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1808 ldr r1, [pc, #0xe04] */
/* @0x1c180c ldr r0, [pc, #0xe04] */
/* @0x1c1810 mov r2, #1 */
/* @0x1c1814 mov r3, r2 */
/* @0x1c1818 ldr r1, [r4, r1] */
/* @0x1c181c add r0, pc, r0 */
/* → layer_set_target_room  F_LayerSetTargetRoom 0x1b6334  argc=1 */
/* @0x1c1820 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1824 ldr r1, [pc, #0xdf0] */
/* @0x1c1828 ldr r0, [pc, #0xdf0] */
/* @0x1c182c mov r2, #0 */
/* @0x1c1830 mov r3, #1 */
/* @0x1c1834 ldr r1, [r4, r1] */
/* @0x1c1838 add r0, pc, r0 */
/* → layer_get_target_room  F_LayerGetTargetRoom 0x1b5ea0  argc=0 */
/* @0x1c183c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1840 ldr r1, [pc, #0xddc] */
/* @0x1c1844 ldr r0, [pc, #0xddc] */
/* @0x1c1848 mov r2, #0 */
/* @0x1c184c mov r3, #1 */
/* @0x1c1850 ldr r1, [r4, r1] */
/* @0x1c1854 add r0, pc, r0 */
/* → layer_reset_target_room  F_LayerResetTargetRoom 0x1b5ecc  argc=0 */
/* @0x1c1858 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c185c ldr r1, [pc, #0xdc8] */
/* @0x1c1860 ldr r0, [pc, #0xdc8] */
/* @0x1c1864 mov r2, #0 */
/* @0x1c1868 mov r3, #1 */
/* @0x1c186c ldr r1, [r4, r1] */
/* @0x1c1870 add r0, pc, r0 */
/* → layer_get_all  F_LayerGetAll 0x1ba98c  argc=0 */
/* @0x1c1874 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1878 ldr r1, [pc, #0xdb4] */
/* @0x1c187c ldr r0, [pc, #0xdb4] */
/* @0x1c1880 mov r2, #1 */
/* @0x1c1884 mov r3, r2 */
/* @0x1c1888 ldr r1, [r4, r1] */
/* @0x1c188c add r0, pc, r0 */
/* → layer_get_all_elements  F_LayerGetAllElements 0x1bbc4c  argc=1 */
/* @0x1c1890 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1894 ldr r1, [pc, #0xda0] */
/* @0x1c1898 ldr r0, [pc, #0xda0] */
/* @0x1c189c mov r2, #1 */
/* @0x1c18a0 mov r3, r2 */
/* @0x1c18a4 ldr r1, [r4, r1] */
/* @0x1c18a8 add r0, pc, r0 */
/* → layer_get_name  F_LayerGetName 0x1bbe00  argc=1 */
/* @0x1c18ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c18b0 ldr r1, [pc, #0xd8c] */
/* @0x1c18b4 ldr r0, [pc, #0xd8c] */
/* @0x1c18b8 mov r2, #2 */
/* @0x1c18bc mov r3, #1 */
/* @0x1c18c0 ldr r1, [r4, r1] */
/* @0x1c18c4 add r0, pc, r0 */
/* → layer_depth  F_LayerDepth 0x1bbeec  argc=2 */
/* @0x1c18c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c18cc ldr r1, [pc, #0xd78] */
/* @0x1c18d0 ldr r0, [pc, #0xd78] */
/* @0x1c18d4 mov r2, #1 */
/* @0x1c18d8 mov r3, r2 */
/* @0x1c18dc ldr r1, [r4, r1] */
/* @0x1c18e0 add r0, pc, r0 */
/* → layer_get_element_layer  F_LayerGetElementLayer 0x1bf2dc  argc=1 */
/* @0x1c18e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c18e8 ldr r1, [pc, #0xd64] */
/* @0x1c18ec ldr r0, [pc, #0xd64] */
/* @0x1c18f0 mov r2, #1 */
/* @0x1c18f4 mov r3, r2 */
/* @0x1c18f8 ldr r1, [r4, r1] */
/* @0x1c18fc add r0, pc, r0 */
/* → layer_get_element_type  F_LayerGetElementType 0x1bf3d4  argc=1 */
/* @0x1c1900 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1904 ldr r1, [pc, #0xd50] */
/* @0x1c1908 ldr r0, [pc, #0xd50] */
/* @0x1c190c mov r2, #2 */
/* @0x1c1910 mov r3, #1 */
/* @0x1c1914 ldr r1, [r4, r1] */
/* @0x1c1918 add r0, pc, r0 */
/* → layer_element_move  F_LayerElementMove 0x1c0028  argc=2 */
/* @0x1c191c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1920 ldr r1, [pc, #0xd3c] */
/* @0x1c1924 ldr r0, [pc, #0xd3c] */
/* @0x1c1928 mov r2, #2 */
/* @0x1c192c mov r3, #1 */
/* @0x1c1930 ldr r1, [r4, r1] */
/* @0x1c1934 add r0, pc, r0 */
/* → layer_force_draw_depth  F_LayerForceDrawDepth 0x1b6864  argc=2 */
/* @0x1c1938 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c193c ldr r1, [pc, #0xd28] */
/* @0x1c1940 ldr r0, [pc, #0xd28] */
/* @0x1c1944 mov r2, #0 */
/* @0x1c1948 mov r3, #1 */
/* @0x1c194c ldr r1, [r4, r1] */
/* @0x1c1950 add r0, pc, r0 */
/* → layer_is_draw_depth_forced  F_LayerIsDrawDepthForced 0x1b5ee4  argc=0 */
/* @0x1c1954 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1958 ldr r1, [pc, #0xd14] */
/* @0x1c195c ldr r0, [pc, #0xd14] */
/* @0x1c1960 mov r2, #0 */
/* @0x1c1964 mov r3, #1 */
/* @0x1c1968 ldr r1, [r4, r1] */
/* @0x1c196c add r0, pc, r0 */
/* → layer_get_forced_depth  F_LayerGetForcedDepth 0x1b5f18  argc=0 */
/* @0x1c1970 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── layer_background_* ─────────────────────────────────────────────── */
/* @0x1c1974 ldr r1, [pc, #0xd00] */
/* @0x1c1978 ldr r0, [pc, #0xd00] */
/* @0x1c197c mov r2, #1 */
/* @0x1c1980 mov r3, r2 */
/* @0x1c1984 ldr r1, [r4, r1] */
/* @0x1c1988 add r0, pc, r0 */
/* → layer_background_get_id  F_LayerBackgroundGetID 0x1c0544  argc=1 */
/* @0x1c198c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1990 ldr r1, [pc, #0xcec] */
/* @0x1c1994 ldr r0, [pc, #0xcec] */
/* @0x1c1998 mov r2, #2 */
/* @0x1c199c mov r3, #1 */
/* @0x1c19a0 ldr r1, [r4, r1] */
/* @0x1c19a4 add r0, pc, r0 */
/* → layer_background_exists  F_LayerBackgroundExists 0x1c0828  argc=2 */
/* @0x1c19a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c19ac ldr r1, [pc, #0xcd8] */
/* @0x1c19b0 ldr r0, [pc, #0xcd8] */
/* @0x1c19b4 mov r2, #2 */
/* @0x1c19b8 mov r3, #1 */
/* @0x1c19bc ldr r1, [r4, r1] */
/* @0x1c19c0 add r0, pc, r0 */
/* → layer_background_create  F_LayerBackgroundCreate 0x1c6ea4  argc=2 */
/* @0x1c19c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c19c8 ldr r1, [pc, #0xcc4] */
/* @0x1c19cc ldr r0, [pc, #0xcc4] */
/* @0x1c19d0 mov r2, #1 */
/* @0x1c19d4 mov r3, r2 */
/* @0x1c19d8 ldr r1, [r4, r1] */
/* @0x1c19dc add r0, pc, r0 */
/* → layer_background_destroy  F_LayerBackgroundDestroy 0x1c02cc  argc=1 */
/* @0x1c19e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c19e4 ldr r1, [pc, #0xcb0] */
/* @0x1c19e8 ldr r0, [pc, #0xcb0] */
/* @0x1c19ec mov r2, #2 */
/* @0x1c19f0 mov r3, #1 */
/* @0x1c19f4 ldr r1, [r4, r1] */
/* @0x1c19f8 add r0, pc, r0 */
/* → layer_background_visible  F_LayerBackgroundVisible 0x1bc3b8  argc=2 */
/* @0x1c19fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a00 ldr r1, [pc, #0xc9c] */
/* @0x1c1a04 ldr r0, [pc, #0xc9c] */
/* @0x1c1a08 mov r2, #2 */
/* @0x1c1a0c mov r3, #1 */
/* @0x1c1a10 ldr r1, [r4, r1] */
/* @0x1c1a14 add r0, pc, r0 */
/* → layer_background_htiled  F_LayerBackgroundHtiled 0x1bc44c  argc=2 */
/* @0x1c1a18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a1c ldr r1, [pc, #0xc88] */
/* @0x1c1a20 ldr r0, [pc, #0xc88] */
/* @0x1c1a24 mov r2, #2 */
/* @0x1c1a28 mov r3, #1 */
/* @0x1c1a2c ldr r1, [r4, r1] */
/* @0x1c1a30 add r0, pc, r0 */
/* → layer_background_vtiled  F_LayerBackgroundVtiled 0x1bc4e0  argc=2 */
/* @0x1c1a34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a38 ldr r1, [pc, #0xc74] */
/* @0x1c1a3c ldr r0, [pc, #0xc74] */
/* @0x1c1a40 mov r2, #2 */
/* @0x1c1a44 mov r3, #1 */
/* @0x1c1a48 ldr r1, [r4, r1] */
/* @0x1c1a4c add r0, pc, r0 */
/* → layer_background_xscale  F_LayerBackgroundXscale 0x1bc608  argc=2 */
/* @0x1c1a50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a54 ldr r1, [pc, #0xc60] */
/* @0x1c1a58 ldr r0, [pc, #0xc60] */
/* @0x1c1a5c mov r2, #2 */
/* @0x1c1a60 mov r3, #1 */
/* @0x1c1a64 ldr r1, [r4, r1] */
/* @0x1c1a68 add r0, pc, r0 */
/* → layer_background_yscale  F_LayerBackgroundYscale 0x1bc69c  argc=2 */
/* @0x1c1a6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a70 ldr r1, [pc, #0xc4c] */
/* @0x1c1a74 ldr r0, [pc, #0xc4c] */
/* @0x1c1a78 mov r2, #2 */
/* @0x1c1a7c mov r3, #1 */
/* @0x1c1a80 ldr r1, [r4, r1] */
/* @0x1c1a84 add r0, pc, r0 */
/* → layer_background_stretch  F_LayerBackgroundStretch 0x1bc574  argc=2 */
/* @0x1c1a88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1a8c ldr r1, [pc, #0xc38] */
/* @0x1c1a90 ldr r0, [pc, #0xc38] */
/* @0x1c1a94 mov r2, #2 */
/* @0x1c1a98 mov r3, #1 */
/* @0x1c1a9c ldr r1, [r4, r1] */
/* @0x1c1aa0 add r0, pc, r0 */
/* → layer_background_blend  F_LayerBackgroundBlend 0x1bc730  argc=2 */
/* @0x1c1aa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1aa8 ldr r1, [pc, #0xc24] */
/* @0x1c1aac ldr r0, [pc, #0xc24] */
/* @0x1c1ab0 mov r2, #2 */
/* @0x1c1ab4 mov r3, #1 */
/* @0x1c1ab8 ldr r1, [r4, r1] */
/* @0x1c1abc add r0, pc, r0 */
/* → layer_background_alpha  F_LayerBackgroundAlpha 0x1bc7c4  argc=2 */
/* @0x1c1ac0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ac4 ldr r1, [pc, #0xc10] */
/* @0x1c1ac8 ldr r0, [pc, #0xc10] */
/* @0x1c1acc mov r2, #2 */
/* @0x1c1ad0 mov r3, #1 */
/* @0x1c1ad4 ldr r1, [r4, r1] */
/* @0x1c1ad8 add r0, pc, r0 */
/* → layer_background_index  F_LayerBackgroundIndex 0x1bc858  argc=2 */
/* @0x1c1adc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ae0 ldr r1, [pc, #0xbfc] */
/* @0x1c1ae4 ldr r0, [pc, #0xbfc] */
/* @0x1c1ae8 mov r2, #2 */
/* @0x1c1aec mov r3, #1 */
/* @0x1c1af0 ldr r1, [r4, r1] */
/* @0x1c1af4 add r0, pc, r0 */
/* → layer_background_speed  F_LayerBackgroundSpeed 0x1bc8ec  argc=2 */
/* @0x1c1af8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1afc ldr r1, [pc, #0xbe8] */
/* @0x1c1b00 ldr r0, [pc, #0xbe8] */
/* @0x1c1b04 mov r2, #2 */
/* @0x1c1b08 mov r3, #1 */
/* ★ 别名块：0x1c1b0c 先 ldr r5,[r4,r1] 取一次 handler，下面两个名字 mov r1,r5 复用
 *   ⇒ layer_background_sprite 与 layer_background_change 指向同一个 0x1bc980 */
/* @0x1c1b0c ldr r5, [r4, r1] */
/* @0x1c1b10 add r0, pc, r0 */
/* @0x1c1b14 mov r1, r5 */
/* → layer_background_sprite  F_LayerBackgroundSprite 0x1bc980  argc=2 */
/* @0x1c1b18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b1c ldr r0, [pc, #0xbd0] */
/* @0x1c1b20 mov r1, r5 */
/* @0x1c1b24 mov r2, #2 */
/* @0x1c1b28 add r0, pc, r0 */
/* @0x1c1b2c mov r3, #1 */
/* → layer_background_change  F_LayerBackgroundSprite 0x1bc980  argc=2 */
/* @0x1c1b30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b34 ldr r1, [pc, #0xbbc] */
/* @0x1c1b38 ldr r0, [pc, #0xbbc] */
/* @0x1c1b3c mov r2, #1 */
/* @0x1c1b40 mov r3, r2 */
/* @0x1c1b44 ldr r1, [r4, r1] */
/* @0x1c1b48 add r0, pc, r0 */
/* → layer_background_get_visible  F_LayerBackgroundGetVisible 0x1bca14  argc=1 */
/* @0x1c1b4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b50 ldr r1, [pc, #0xba8] */
/* @0x1c1b54 ldr r0, [pc, #0xba8] */
/* @0x1c1b58 mov r2, #1 */
/* @0x1c1b5c mov r3, r2 */
/* @0x1c1b60 ldr r1, [r4, r1] */
/* @0x1c1b64 add r0, pc, r0 */
/* → layer_background_get_sprite  F_LayerBackgroundGetSprite 0x1bcac4  argc=1 */
/* @0x1c1b68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b6c ldr r1, [pc, #0xb94] */
/* @0x1c1b70 ldr r0, [pc, #0xb94] */
/* @0x1c1b74 mov r2, #1 */
/* @0x1c1b78 mov r3, r2 */
/* @0x1c1b7c ldr r1, [r4, r1] */
/* @0x1c1b80 add r0, pc, r0 */
/* → layer_background_get_htiled  F_LayerBackgroundGetHtiled 0x1bcb64  argc=1 */
/* @0x1c1b84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1b88 ldr r1, [pc, #0xb80] */
/* @0x1c1b8c ldr r0, [pc, #0xb80] */
/* @0x1c1b90 mov r2, #1 */
/* @0x1c1b94 mov r3, r2 */
/* @0x1c1b98 ldr r1, [r4, r1] */
/* @0x1c1b9c add r0, pc, r0 */
/* → layer_background_get_vtiled  F_LayerBackgroundGetVtiled 0x1bcc0c  argc=1 */
/* @0x1c1ba0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ba4 ldr r1, [pc, #0xb6c] */
/* @0x1c1ba8 ldr r0, [pc, #0xb6c] */
/* @0x1c1bac mov r2, #1 */
/* @0x1c1bb0 mov r3, r2 */
/* @0x1c1bb4 ldr r1, [r4, r1] */
/* @0x1c1bb8 add r0, pc, r0 */
/* → layer_background_get_xscale  F_LayerBackgroundGetXscale 0x1bcd5c  argc=1 */
/* @0x1c1bbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1bc0 ldr r1, [pc, #0xb58] */
/* @0x1c1bc4 ldr r0, [pc, #0xb58] */
/* @0x1c1bc8 mov r2, #1 */
/* @0x1c1bcc mov r3, r2 */
/* @0x1c1bd0 ldr r1, [r4, r1] */
/* @0x1c1bd4 add r0, pc, r0 */
/* → layer_background_get_yscale  F_LayerBackgroundGetYscale 0x1bce08  argc=1 */
/* @0x1c1bd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1bdc ldr r1, [pc, #0xb44] */
/* @0x1c1be0 ldr r0, [pc, #0xb44] */
/* @0x1c1be4 mov r2, #1 */
/* @0x1c1be8 mov r3, r2 */
/* @0x1c1bec ldr r1, [r4, r1] */
/* @0x1c1bf0 add r0, pc, r0 */
/* → layer_background_get_stretch  F_LayerBackgroundGetStretch 0x1bccb4  argc=1 */
/* @0x1c1bf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1bf8 ldr r1, [pc, #0xb30] */
/* @0x1c1bfc ldr r0, [pc, #0xb30] */
/* @0x1c1c00 mov r2, #1 */
/* @0x1c1c04 mov r3, r2 */
/* @0x1c1c08 ldr r1, [r4, r1] */
/* @0x1c1c0c add r0, pc, r0 */
/* → layer_background_get_blend  F_LayerBackgroundGetBlend 0x1bceb4  argc=1 */
/* @0x1c1c10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c14 ldr r1, [pc, #0xb1c] */
/* @0x1c1c18 ldr r0, [pc, #0xb1c] */
/* @0x1c1c1c mov r2, #1 */
/* @0x1c1c20 mov r3, r2 */
/* @0x1c1c24 ldr r1, [r4, r1] */
/* @0x1c1c28 add r0, pc, r0 */
/* → layer_background_get_alpha  F_LayerBackgroundGetAlpha 0x1bcf5c  argc=1 */
/* @0x1c1c2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c30 ldr r1, [pc, #0xb08] */
/* @0x1c1c34 ldr r0, [pc, #0xb08] */
/* @0x1c1c38 mov r2, #1 */
/* @0x1c1c3c mov r3, r2 */
/* @0x1c1c40 ldr r1, [r4, r1] */
/* @0x1c1c44 add r0, pc, r0 */
/* → layer_background_get_index  F_LayerBackgroundGetIndex 0x1bd000  argc=1 */
/* @0x1c1c48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c4c ldr r1, [pc, #0xaf4] */
/* @0x1c1c50 ldr r0, [pc, #0xaf4] */
/* @0x1c1c54 mov r2, #1 */
/* @0x1c1c58 mov r3, r2 */
/* @0x1c1c5c ldr r1, [r4, r1] */
/* @0x1c1c60 add r0, pc, r0 */
/* → layer_background_get_speed  F_LayerBackgroundGetSpeed 0x1bd09c  argc=1 */
/* @0x1c1c64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── layer_sprite_* ─────────────────────────────────────────────── */
/* @0x1c1c68 ldr r1, [pc, #0xae0] */
/* @0x1c1c6c ldr r0, [pc, #0xae0] */
/* @0x1c1c70 mov r2, #2 */
/* @0x1c1c74 mov r3, #1 */
/* @0x1c1c78 ldr r1, [r4, r1] */
/* @0x1c1c7c add r0, pc, r0 */
/* → layer_sprite_get_id  F_LayerSpriteGetID 0x1c0610  argc=2 */
/* @0x1c1c80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1c84 ldr r1, [pc, #0xacc] */
/* @0x1c1c88 ldr r0, [pc, #0xacc] */
/* @0x1c1c8c mov r2, #2 */
/* @0x1c1c90 mov r3, #1 */
/* @0x1c1c94 ldr r1, [r4, r1] */
/* @0x1c1c98 add r0, pc, r0 */
/* → layer_sprite_exists  F_LayerSpriteExists 0x1c08fc  argc=2 */
/* @0x1c1c9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ca0 ldr r1, [pc, #0xab8] */
/* @0x1c1ca4 ldr r0, [pc, #0xab8] */
/* @0x1c1ca8 mov r2, #4 */
/* @0x1c1cac mov r3, #1 */
/* @0x1c1cb0 ldr r1, [r4, r1] */
/* @0x1c1cb4 add r0, pc, r0 */
/* → layer_sprite_create  F_LayerSpriteCreate 0x1c7058  argc=4 */
/* @0x1c1cb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1cbc ldr r1, [pc, #0xaa4] */
/* @0x1c1cc0 ldr r0, [pc, #0xaa4] */
/* @0x1c1cc4 mov r2, #1 */
/* @0x1c1cc8 mov r3, r2 */
/* @0x1c1ccc ldr r1, [r4, r1] */
/* @0x1c1cd0 add r0, pc, r0 */
/* → layer_sprite_destroy  F_LayerSpriteDestroy 0x1c033c  argc=1 */
/* @0x1c1cd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1cd8 ldr r1, [pc, #0xa90] */
/* @0x1c1cdc ldr r0, [pc, #0xa90] */
/* @0x1c1ce0 mov r2, #2 */
/* @0x1c1ce4 mov r3, #1 */
/* @0x1c1ce8 ldr r1, [r4, r1] */
/* @0x1c1cec add r0, pc, r0 */
/* → layer_sprite_change  F_LayerSpriteChange 0x1bd140  argc=2 */
/* @0x1c1cf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1cf4 ldr r1, [pc, #0xa7c] */
/* @0x1c1cf8 ldr r0, [pc, #0xa7c] */
/* @0x1c1cfc mov r2, #2 */
/* @0x1c1d00 mov r3, #1 */
/* @0x1c1d04 ldr r1, [r4, r1] */
/* @0x1c1d08 add r0, pc, r0 */
/* → layer_sprite_index  F_LayerSpriteIndex 0x1bd1cc  argc=2 */
/* @0x1c1d0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d10 ldr r1, [pc, #0xa68] */
/* @0x1c1d14 ldr r0, [pc, #0xa68] */
/* @0x1c1d18 mov r2, #2 */
/* @0x1c1d1c mov r3, #1 */
/* @0x1c1d20 ldr r1, [r4, r1] */
/* @0x1c1d24 add r0, pc, r0 */
/* → layer_sprite_speed  F_LayerSpriteSpeed 0x1bd258  argc=2 */
/* @0x1c1d28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d2c ldr r1, [pc, #0xa54] */
/* @0x1c1d30 ldr r0, [pc, #0xa54] */
/* @0x1c1d34 mov r2, #2 */
/* @0x1c1d38 mov r3, #1 */
/* @0x1c1d3c ldr r1, [r4, r1] */
/* @0x1c1d40 add r0, pc, r0 */
/* → layer_sprite_xscale  F_LayerSpriteXScale 0x1bd2e4  argc=2 */
/* @0x1c1d44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d48 ldr r1, [pc, #0xa40] */
/* @0x1c1d4c ldr r0, [pc, #0xa40] */
/* @0x1c1d50 mov r2, #2 */
/* @0x1c1d54 mov r3, #1 */
/* @0x1c1d58 ldr r1, [r4, r1] */
/* @0x1c1d5c add r0, pc, r0 */
/* → layer_sprite_yscale  F_LayerSpriteYScale 0x1bd370  argc=2 */
/* @0x1c1d60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d64 ldr r1, [pc, #0xa2c] */
/* @0x1c1d68 ldr r0, [pc, #0xa2c] */
/* @0x1c1d6c mov r2, #2 */
/* @0x1c1d70 mov r3, #1 */
/* @0x1c1d74 ldr r1, [r4, r1] */
/* @0x1c1d78 add r0, pc, r0 */
/* → layer_sprite_angle  F_LayerSpriteAngle 0x1bd3fc  argc=2 */
/* @0x1c1d7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d80 ldr r1, [pc, #0xa18] */
/* @0x1c1d84 ldr r0, [pc, #0xa18] */
/* @0x1c1d88 mov r2, #2 */
/* @0x1c1d8c mov r3, #1 */
/* @0x1c1d90 ldr r1, [r4, r1] */
/* @0x1c1d94 add r0, pc, r0 */
/* → layer_sprite_blend  F_LayerSpriteBlend 0x1bd488  argc=2 */
/* @0x1c1d98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1d9c ldr r1, [pc, #0xa04] */
/* @0x1c1da0 ldr r0, [pc, #0xa04] */
/* @0x1c1da4 mov r2, #2 */
/* @0x1c1da8 mov r3, #1 */
/* @0x1c1dac ldr r1, [r4, r1] */
/* @0x1c1db0 add r0, pc, r0 */
/* → layer_sprite_alpha  F_LayerSpriteAlpha 0x1bd514  argc=2 */
/* @0x1c1db4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1db8 ldr r1, [pc, #0x9f0] */
/* @0x1c1dbc ldr r0, [pc, #0x9f0] */
/* @0x1c1dc0 mov r2, #2 */
/* @0x1c1dc4 mov r3, #1 */
/* @0x1c1dc8 ldr r1, [r4, r1] */
/* @0x1c1dcc add r0, pc, r0 */
/* → layer_sprite_x  F_LayerSpriteX 0x1bd5a0  argc=2 */
/* @0x1c1dd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1dd4 ldr r1, [pc, #0x9dc] */
/* @0x1c1dd8 ldr r0, [pc, #0x9dc] */
/* @0x1c1ddc mov r2, #2 */
/* @0x1c1de0 mov r3, #1 */
/* @0x1c1de4 ldr r1, [r4, r1] */
/* @0x1c1de8 add r0, pc, r0 */
/* → layer_sprite_y  F_LayerSpriteY 0x1bd62c  argc=2 */
/* @0x1c1dec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1df0 ldr r1, [pc, #0x9c8] */
/* @0x1c1df4 ldr r0, [pc, #0x9c8] */
/* @0x1c1df8 mov r2, #1 */
/* @0x1c1dfc mov r3, r2 */
/* @0x1c1e00 ldr r1, [r4, r1] */
/* @0x1c1e04 add r0, pc, r0 */
/* → layer_sprite_get_sprite  F_LayerSpriteGetSprite 0x1bd6b8  argc=1 */
/* @0x1c1e08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e0c ldr r1, [pc, #0x9b4] */
/* @0x1c1e10 ldr r0, [pc, #0x9b4] */
/* @0x1c1e14 mov r2, #1 */
/* @0x1c1e18 mov r3, r2 */
/* @0x1c1e1c ldr r1, [r4, r1] */
/* @0x1c1e20 add r0, pc, r0 */
/* → layer_sprite_get_index  F_LayerSpriteGetIndex 0x1bd74c  argc=1 */
/* @0x1c1e24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e28 ldr r1, [pc, #0x9a0] */
/* @0x1c1e2c ldr r0, [pc, #0x9a0] */
/* @0x1c1e30 mov r2, #1 */
/* @0x1c1e34 mov r3, r2 */
/* @0x1c1e38 ldr r1, [r4, r1] */
/* @0x1c1e3c add r0, pc, r0 */
/* → layer_sprite_get_speed  F_LayerSpriteGetSpeed 0x1bd7dc  argc=1 */
/* @0x1c1e40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e44 ldr r1, [pc, #0x98c] */
/* @0x1c1e48 ldr r0, [pc, #0x98c] */
/* @0x1c1e4c mov r2, #1 */
/* @0x1c1e50 mov r3, r2 */
/* @0x1c1e54 ldr r1, [r4, r1] */
/* @0x1c1e58 add r0, pc, r0 */
/* → layer_sprite_get_xscale  F_LayerSpriteGetXScale 0x1bd874  argc=1 */
/* @0x1c1e5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e60 ldr r1, [pc, #0x978] */
/* @0x1c1e64 ldr r0, [pc, #0x978] */
/* @0x1c1e68 mov r2, #1 */
/* @0x1c1e6c mov r3, r2 */
/* @0x1c1e70 ldr r1, [r4, r1] */
/* @0x1c1e74 add r0, pc, r0 */
/* → layer_sprite_get_yscale  F_LayerSpriteGetYScale 0x1bd914  argc=1 */
/* @0x1c1e78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e7c ldr r1, [pc, #0x964] */
/* @0x1c1e80 ldr r0, [pc, #0x964] */
/* @0x1c1e84 mov r2, #1 */
/* @0x1c1e88 mov r3, r2 */
/* @0x1c1e8c ldr r1, [r4, r1] */
/* @0x1c1e90 add r0, pc, r0 */
/* → layer_sprite_get_angle  F_LayerSpriteGetAngle 0x1bd9b4  argc=1 */
/* @0x1c1e94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1e98 ldr r1, [pc, #0x950] */
/* @0x1c1e9c ldr r0, [pc, #0x950] */
/* @0x1c1ea0 mov r2, #1 */
/* @0x1c1ea4 mov r3, r2 */
/* @0x1c1ea8 ldr r1, [r4, r1] */
/* @0x1c1eac add r0, pc, r0 */
/* → layer_sprite_get_blend  F_LayerSpriteGetBlend 0x1bda4c  argc=1 */
/* @0x1c1eb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1eb4 ldr r1, [pc, #0x93c] */
/* @0x1c1eb8 ldr r0, [pc, #0x93c] */
/* @0x1c1ebc mov r2, #1 */
/* @0x1c1ec0 mov r3, r2 */
/* @0x1c1ec4 ldr r1, [r4, r1] */
/* @0x1c1ec8 add r0, pc, r0 */
/* → layer_sprite_get_alpha  F_LayerSpriteGetAlpha 0x1bdae8  argc=1 */
/* @0x1c1ecc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1ed0 ldr r1, [pc, #0x928] */
/* @0x1c1ed4 ldr r0, [pc, #0x928] */
/* @0x1c1ed8 mov r2, #1 */
/* @0x1c1edc mov r3, r2 */
/* @0x1c1ee0 ldr r1, [r4, r1] */
/* @0x1c1ee4 add r0, pc, r0 */
/* → layer_sprite_get_x  F_LayerSpriteGetX 0x1bdb80  argc=1 */
/* @0x1c1ee8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1eec ldr r1, [pc, #0x914] */
/* @0x1c1ef0 ldr r0, [pc, #0x914] */
/* @0x1c1ef4 mov r2, #1 */
/* @0x1c1ef8 mov r3, r2 */
/* @0x1c1efc ldr r1, [r4, r1] */
/* @0x1c1f00 add r0, pc, r0 */
/* → layer_sprite_get_y  F_LayerSpriteGetY 0x1bdc18  argc=1 */
/* @0x1c1f04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── instance_*_layer ─────────────────────────────────────────────── */
/* @0x1c1f08 ldr r1, [pc, #0x900] */
/* @0x1c1f0c ldr r0, [pc, #0x900] */
/* @0x1c1f10 mov r2, #1 */
/* @0x1c1f14 mov r3, r2 */
/* @0x1c1f18 ldr r1, [r4, r1] */
/* @0x1c1f1c add r0, pc, r0 */
/* → instance_activate_layer  F_LayerActivate 0x1bb998  argc=1 */
/* @0x1c1f20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f24 ldr r1, [pc, #0x8ec] */
/* @0x1c1f28 ldr r0, [pc, #0x8ec] */
/* @0x1c1f2c mov r2, #1 */
/* @0x1c1f30 mov r3, r2 */
/* @0x1c1f34 ldr r1, [r4, r1] */
/* @0x1c1f38 add r0, pc, r0 */
/* → instance_deactivate_layer  F_LayerDeactivate 0x1bbaf8  argc=1 */
/* @0x1c1f3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── layer_tilemap_* ─────────────────────────────────────────────── */
/* @0x1c1f40 ldr r1, [pc, #0x8d8] */
/* @0x1c1f44 ldr r0, [pc, #0x8d8] */
/* @0x1c1f48 mov r2, #1 */
/* @0x1c1f4c mov r3, r2 */
/* @0x1c1f50 ldr r1, [r4, r1] */
/* @0x1c1f54 add r0, pc, r0 */
/* → layer_tilemap_get_id  F_LayerTilemapGetID 0x1c06f4  argc=1 */
/* @0x1c1f58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f5c ldr r1, [pc, #0x8c4] */
/* @0x1c1f60 ldr r0, [pc, #0x8c4] */
/* @0x1c1f64 mov r2, #2 */
/* @0x1c1f68 mov r3, #1 */
/* @0x1c1f6c ldr r1, [r4, r1] */
/* @0x1c1f70 add r0, pc, r0 */
/* → layer_tilemap_exists  F_LayerTilemapExists 0x1c09d0  argc=2 */
/* @0x1c1f74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f78 ldr r1, [pc, #0x8b0] */
/* @0x1c1f7c ldr r0, [pc, #0x8b0] */
/* @0x1c1f80 mov r2, #6 */
/* @0x1c1f84 mov r3, #1 */
/* @0x1c1f88 ldr r1, [r4, r1] */
/* @0x1c1f8c add r0, pc, r0 */
/* → layer_tilemap_create  F_LayerTilemapCreate 0x1c719c  argc=6 */
/* @0x1c1f90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1f94 ldr r1, [pc, #0x89c] */
/* @0x1c1f98 ldr r0, [pc, #0x89c] */
/* @0x1c1f9c mov r2, #1 */
/* @0x1c1fa0 mov r3, r2 */
/* @0x1c1fa4 ldr r1, [r4, r1] */
/* @0x1c1fa8 add r0, pc, r0 */
/* → layer_tilemap_destroy  F_LayerTilemapDestroy 0x1c03ac  argc=1 */
/* @0x1c1fac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── tilemap_* ─────────────────────────────────────────────── */
/* @0x1c1fb0 ldr r1, [pc, #0x888] */
/* @0x1c1fb4 ldr r0, [pc, #0x888] */
/* @0x1c1fb8 mov r2, #2 */
/* @0x1c1fbc mov r3, #1 */
/* @0x1c1fc0 ldr r1, [r4, r1] */
/* @0x1c1fc4 add r0, pc, r0 */
/* → tilemap_tileset  F_TilemapTileset 0x1bdcb0  argc=2 */
/* @0x1c1fc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1fcc ldr r1, [pc, #0x874] */
/* @0x1c1fd0 ldr r0, [pc, #0x874] */
/* @0x1c1fd4 mov r2, #2 */
/* @0x1c1fd8 mov r3, #1 */
/* @0x1c1fdc ldr r1, [r4, r1] */
/* @0x1c1fe0 add r0, pc, r0 */
/* → tilemap_x  F_TilemapX 0x1bdd3c  argc=2 */
/* @0x1c1fe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c1fe8 ldr r1, [pc, #0x860] */
/* @0x1c1fec ldr r0, [pc, #0x860] */
/* @0x1c1ff0 mov r2, #2 */
/* @0x1c1ff4 mov r3, #1 */
/* @0x1c1ff8 ldr r1, [r4, r1] */
/* @0x1c1ffc add r0, pc, r0 */
/* → tilemap_y  F_TilemapY 0x1bddc8  argc=2 */
/* @0x1c2000 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2004 ldr r1, [pc, #0x84c] */
/* @0x1c2008 ldr r0, [pc, #0x84c] */
/* @0x1c200c mov r2, #4 */
/* @0x1c2010 mov r3, #1 */
/* @0x1c2014 ldr r1, [r4, r1] */
/* @0x1c2018 add r0, pc, r0 */
/* → tilemap_set  F_TilemapSet 0x1bde54  argc=4 */
/* @0x1c201c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2020 ldr r1, [pc, #0x838] */
/* @0x1c2024 ldr r0, [pc, #0x838] */
/* @0x1c2028 mov r2, #4 */
/* @0x1c202c mov r3, #1 */
/* @0x1c2030 ldr r1, [r4, r1] */
/* @0x1c2034 add r0, pc, r0 */
/* → tilemap_set_at_pixel  F_TilemapSetAtPixel 0x1bdff0  argc=4 */
/* @0x1c2038 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c203c ldr r1, [pc, #0x824] */
/* @0x1c2040 ldr r0, [pc, #0x824] */
/* @0x1c2044 mov r2, #1 */
/* @0x1c2048 mov r3, r2 */
/* @0x1c204c ldr r1, [r4, r1] */
/* @0x1c2050 add r0, pc, r0 */
/* → tilemap_get_tileset  F_TilemapGetTileset 0x1be2b8  argc=1 */
/* @0x1c2054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2058 ldr r1, [pc, #0x810] */
/* @0x1c205c ldr r0, [pc, #0x810] */
/* @0x1c2060 mov r2, #1 */
/* @0x1c2064 mov r3, r2 */
/* @0x1c2068 ldr r1, [r4, r1] */
/* @0x1c206c add r0, pc, r0 */
/* → tilemap_get_tile_width  F_TilemapGetTileWidth 0x1be34c  argc=1 */
/* @0x1c2070 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2074 ldr r1, [pc, #0x7fc] */
/* @0x1c2078 ldr r0, [pc, #0x7fc] */
/* @0x1c207c mov r2, #1 */
/* @0x1c2080 mov r3, r2 */
/* @0x1c2084 ldr r1, [r4, r1] */
/* @0x1c2088 add r0, pc, r0 */
/* → tilemap_get_tile_height  F_TilemapGetTileHeight 0x1be408  argc=1 */
/* @0x1c208c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2090 ldr r1, [pc, #0x7e8] */
/* @0x1c2094 ldr r0, [pc, #0x7e8] */
/* @0x1c2098 mov r2, #1 */
/* @0x1c209c mov r3, r2 */
/* @0x1c20a0 ldr r1, [r4, r1] */
/* @0x1c20a4 add r0, pc, r0 */
/* → tilemap_get_width  F_TilemapGetWidth 0x1be4c4  argc=1 */
/* @0x1c20a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c20ac ldr r1, [pc, #0x7d4] */
/* @0x1c20b0 ldr r0, [pc, #0x7d4] */
/* @0x1c20b4 mov r2, #1 */
/* @0x1c20b8 mov r3, r2 */
/* @0x1c20bc ldr r1, [r4, r1] */
/* @0x1c20c0 add r0, pc, r0 */
/* → tilemap_get_height  F_TilemapGetHeight 0x1be558  argc=1 */
/* @0x1c20c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c20c8 ldr r1, [pc, #0x7c0] */
/* @0x1c20cc ldr r0, [pc, #0x7c0] */
/* @0x1c20d0 mov r2, #1 */
/* @0x1c20d4 mov r3, r2 */
/* @0x1c20d8 ldr r1, [r4, r1] */
/* @0x1c20dc add r0, pc, r0 */
/* → tilemap_get_x  F_TilemapGetX 0x1be5ec  argc=1 */
/* @0x1c20e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c20e4 ldr r1, [pc, #0x7ac] */
/* @0x1c20e8 ldr r0, [pc, #0x7ac] */
/* @0x1c20ec mov r2, #1 */
/* @0x1c20f0 mov r3, r2 */
/* @0x1c20f4 ldr r1, [r4, r1] */
/* @0x1c20f8 add r0, pc, r0 */
/* → tilemap_get_y  F_TilemapGetY 0x1be67c  argc=1 */
/* @0x1c20fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2100 ldr r1, [pc, #0x798] */
/* @0x1c2104 ldr r0, [pc, #0x798] */
/* @0x1c2108 mov r2, #3 */
/* @0x1c210c mov r3, #1 */
/* @0x1c2110 ldr r1, [r4, r1] */
/* @0x1c2114 add r0, pc, r0 */
/* → tilemap_get  F_TilemapGet 0x1be70c  argc=3 */
/* @0x1c2118 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c211c ldr r1, [pc, #0x784] */
/* @0x1c2120 ldr r0, [pc, #0x784] */
/* @0x1c2124 mov r2, #3 */
/* @0x1c2128 mov r3, #1 */
/* @0x1c212c ldr r1, [r4, r1] */
/* @0x1c2130 add r0, pc, r0 */
/* → tilemap_get_at_pixel  F_TilemapGetAtPixel 0x1be838  argc=3 */
/* @0x1c2134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2138 ldr r1, [pc, #0x770] */
/* @0x1c213c ldr r0, [pc, #0x770] */
/* @0x1c2140 mov r2, #3 */
/* @0x1c2144 mov r3, #1 */
/* @0x1c2148 ldr r1, [r4, r1] */
/* @0x1c214c add r0, pc, r0 */
/* → tilemap_get_cell_x_at_pixel  F_TilemapGetCellXAtPixel 0x1beaa0  argc=3 */
/* @0x1c2150 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2154 ldr r1, [pc, #0x75c] */
/* @0x1c2158 ldr r0, [pc, #0x75c] */
/* @0x1c215c mov r2, #3 */
/* @0x1c2160 mov r3, #1 */
/* @0x1c2164 ldr r1, [r4, r1] */
/* @0x1c2168 add r0, pc, r0 */
/* → tilemap_get_cell_y_at_pixel  F_TilemapGetCellYAtPixel 0x1bec88  argc=3 */
/* @0x1c216c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2170 ldr r1, [pc, #0x748] */
/* @0x1c2174 ldr r0, [pc, #0x748] */
/* @0x1c2178 mov r2, #2 */
/* @0x1c217c mov r3, #1 */
/* @0x1c2180 ldr r1, [r4, r1] */
/* @0x1c2184 add r0, pc, r0 */
/* → tilemap_clear  F_TilemapClear 0x1bee70  argc=2 */
/* @0x1c2188 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── draw_* ─────────────────────────────────────────────── */
/* @0x1c218c ldr r1, [pc, #0x734] */
/* @0x1c2190 ldr r0, [pc, #0x734] */
/* @0x1c2194 mov r2, #3 */
/* @0x1c2198 mov r3, #1 */
/* @0x1c219c ldr r1, [r4, r1] */
/* @0x1c21a0 add r0, pc, r0 */
/* → draw_tilemap  F_DrawTilemap 0x1bef8c  argc=3 */
/* @0x1c21a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c21a8 ldr r1, [pc, #0x720] */
/* @0x1c21ac ldr r0, [pc, #0x720] */
/* @0x1c21b0 mov r2, #5 */
/* @0x1c21b4 mov r3, #1 */
/* @0x1c21b8 ldr r1, [r4, r1] */
/* @0x1c21bc add r0, pc, r0 */
/* → draw_tile  F_DrawTile 0x1b68c8  argc=5 */
/* @0x1c21c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── tilemap_* ─────────────────────────────────────────────── */
/* @0x1c21c4 ldr r1, [pc, #0x70c] */
/* @0x1c21c8 ldr r0, [pc, #0x70c] */
/* @0x1c21cc mov r2, #1 */
/* @0x1c21d0 mov r3, r2 */
/* @0x1c21d4 ldr r1, [r4, r1] */
/* @0x1c21d8 add r0, pc, r0 */
/* → tilemap_set_global_mask  F_TilemapSetGlobalMask 0x1b6814  argc=1 */
/* @0x1c21dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c21e0 ldr r1, [pc, #0x6f8] */
/* @0x1c21e4 ldr r0, [pc, #0x6f8] */
/* @0x1c21e8 mov r2, #0 */
/* @0x1c21ec mov r3, #1 */
/* @0x1c21f0 ldr r1, [r4, r1] */
/* @0x1c21f4 add r0, pc, r0 */
/* → tilemap_get_global_mask  F_TilemapGetGlobalMask 0x1b5e74  argc=0 */
/* @0x1c21f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c21fc ldr r1, [pc, #0x6e4] */
/* @0x1c2200 ldr r0, [pc, #0x6e4] */
/* @0x1c2204 mov r2, #2 */
/* @0x1c2208 mov r3, #1 */
/* @0x1c220c ldr r1, [r4, r1] */
/* @0x1c2210 add r0, pc, r0 */
/* → tilemap_set_mask  F_TilemapSetMask 0x1bf0a8  argc=2 */
/* @0x1c2214 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2218 ldr r1, [pc, #0x6d0] */
/* @0x1c221c ldr r0, [pc, #0x6d0] */
/* @0x1c2220 mov r2, #1 */
/* @0x1c2224 mov r3, r2 */
/* @0x1c2228 ldr r1, [r4, r1] */
/* @0x1c222c add r0, pc, r0 */
/* → tilemap_get_mask  F_TilemapGetMask 0x1bf160  argc=1 */
/* @0x1c2230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2234 ldr r1, [pc, #0x6bc] */
/* @0x1c2238 ldr r0, [pc, #0x6bc] */
/* @0x1c223c mov r2, #1 */
/* @0x1c2240 mov r3, r2 */
/* @0x1c2244 ldr r1, [r4, r1] */
/* @0x1c2248 add r0, pc, r0 */
/* → tilemap_get_frame  F_TilemapGetFrame 0x1bf220  argc=1 */
/* @0x1c224c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── tile_* ─────────────────────────────────────────────── */
/* @0x1c2250 ldr r1, [pc, #0x6a8] */
/* @0x1c2254 ldr r0, [pc, #0x6a8] */
/* @0x1c2258 mov r2, #1 */
/* @0x1c225c mov r3, r2 */
/* @0x1c2260 ldr r1, [r4, r1] */
/* @0x1c2264 add r0, pc, r0 */
/* → tile_set_empty  F_TileSetEmpty 0x1b6358  argc=1 */
/* @0x1c2268 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c226c ldr r1, [pc, #0x694] */
/* @0x1c2270 ldr r0, [pc, #0x694] */
/* @0x1c2274 mov r2, #2 */
/* @0x1c2278 mov r3, #1 */
/* @0x1c227c ldr r1, [r4, r1] */
/* @0x1c2280 add r0, pc, r0 */
/* → tile_set_index  F_TileSetIndex 0x1b63b4  argc=2 */
/* @0x1c2284 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2288 ldr r1, [pc, #0x680] */
/* @0x1c228c ldr r0, [pc, #0x680] */
/* @0x1c2290 mov r2, #2 */
/* @0x1c2294 mov r3, #1 */
/* @0x1c2298 ldr r1, [r4, r1] */
/* @0x1c229c add r0, pc, r0 */
/* → tile_set_flip  F_TileSetFlip 0x1b6424  argc=2 */
/* @0x1c22a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c22a4 ldr r1, [pc, #0x66c] */
/* @0x1c22a8 ldr r0, [pc, #0x66c] */
/* @0x1c22ac mov r2, #2 */
/* @0x1c22b0 mov r3, #1 */
/* @0x1c22b4 ldr r1, [r4, r1] */
/* @0x1c22b8 add r0, pc, r0 */
/* → tile_set_mirror  F_TileSetMirror 0x1b64b8  argc=2 */
/* @0x1c22bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c22c0 ldr r1, [pc, #0x658] */
/* @0x1c22c4 ldr r0, [pc, #0x658] */
/* @0x1c22c8 mov r2, #2 */
/* @0x1c22cc mov r3, #1 */
/* @0x1c22d0 ldr r1, [r4, r1] */
/* @0x1c22d4 add r0, pc, r0 */
/* → tile_set_rotate  F_TileSetRotate 0x1b654c  argc=2 */
/* @0x1c22d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c22dc ldr r1, [pc, #0x644] */
/* @0x1c22e0 ldr r0, [pc, #0x644] */
/* @0x1c22e4 mov r2, #1 */
/* @0x1c22e8 mov r3, r2 */
/* @0x1c22ec ldr r1, [r4, r1] */
/* @0x1c22f0 add r0, pc, r0 */
/* → tile_get_empty  F_TilemapTileGetEmpty 0x1b65e0  argc=1 */
/* @0x1c22f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c22f8 ldr r1, [pc, #0x630] */
/* @0x1c22fc ldr r0, [pc, #0x630] */
/* @0x1c2300 mov r2, #1 */
/* @0x1c2304 mov r3, r2 */
/* @0x1c2308 ldr r1, [r4, r1] */
/* @0x1c230c add r0, pc, r0 */
/* → tile_get_index  F_TilemapTileGetIndex 0x1b6658  argc=1 */
/* @0x1c2310 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2314 ldr r1, [pc, #0x61c] */
/* @0x1c2318 ldr r0, [pc, #0x61c] */
/* @0x1c231c mov r2, #1 */
/* @0x1c2320 mov r3, r2 */
/* @0x1c2324 ldr r1, [r4, r1] */
/* @0x1c2328 add r0, pc, r0 */
/* → tile_get_flip  F_TilemapTileGetFlip 0x1b66b8  argc=1 */
/* @0x1c232c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2330 ldr r1, [pc, #0x608] */
/* @0x1c2334 ldr r0, [pc, #0x608] */
/* @0x1c2338 mov r2, #1 */
/* @0x1c233c mov r3, r2 */
/* @0x1c2340 ldr r1, [r4, r1] */
/* @0x1c2344 add r0, pc, r0 */
/* → tile_get_mirror  F_TilemapTileGetMirror 0x1b672c  argc=1 */
/* @0x1c2348 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c234c ldr r1, [pc, #0x5f4] */
/* @0x1c2350 ldr r0, [pc, #0x5f4] */
/* @0x1c2354 mov r2, #1 */
/* @0x1c2358 mov r3, r2 */
/* @0x1c235c ldr r1, [r4, r1] */
/* @0x1c2360 add r0, pc, r0 */
/* → tile_get_rotate  F_TilemapTileGetRotate 0x1b67a0  argc=1 */
/* @0x1c2364 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── layer_tile_* ─────────────────────────────────────────────── */
/* @0x1c2368 ldr r1, [pc, #0x5e0] */
/* @0x1c236c ldr r0, [pc, #0x5e0] */
/* @0x1c2370 mov r2, #2 */
/* @0x1c2374 mov r3, #1 */
/* @0x1c2378 ldr r1, [r4, r1] */
/* @0x1c237c add r0, pc, r0 */
/* → layer_tile_exists  F_LayerTileExists 0x1c0ac8  argc=2 */
/* @0x1c2380 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2384 ldr r1, [pc, #0x5cc] */
/* @0x1c2388 ldr r0, [pc, #0x5cc] */
/* @0x1c238c mov r2, #8 */
/* @0x1c2390 mov r3, #1 */
/* @0x1c2394 ldr r1, [r4, r1] */
/* @0x1c2398 add r0, pc, r0 */
/* → layer_tile_create  F_LayerTileCreate 0x1c7340  argc=8 */
/* @0x1c239c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c23a0 ldr r1, [pc, #0x5b8] */
/* @0x1c23a4 ldr r0, [pc, #0x5b8] */
/* @0x1c23a8 mov r2, #1 */
/* @0x1c23ac mov r3, r2 */
/* @0x1c23b0 ldr r1, [r4, r1] */
/* @0x1c23b4 add r0, pc, r0 */
/* → layer_tile_destroy  F_LayerTileDestroy 0x1c041c  argc=1 */
/* @0x1c23b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c23bc ldr r1, [pc, #0x5a4] */
/* @0x1c23c0 ldr r0, [pc, #0x5a4] */
/* @0x1c23c4 mov r2, #2 */
/* @0x1c23c8 mov r3, #1 */
/* @0x1c23cc ldr r1, [r4, r1] */
/* @0x1c23d0 add r0, pc, r0 */
/* → layer_tile_change  F_LayerTileChange 0x1bf4b8  argc=2 */
/* @0x1c23d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c23d8 ldr r1, [pc, #0x590] */
/* @0x1c23dc ldr r0, [pc, #0x590] */
/* @0x1c23e0 mov r2, #2 */
/* @0x1c23e4 mov r3, #1 */
/* @0x1c23e8 ldr r1, [r4, r1] */
/* @0x1c23ec add r0, pc, r0 */
/* → layer_tile_xscale  F_LayerTileXScale 0x1bf544  argc=2 */
/* @0x1c23f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c23f4 ldr r1, [pc, #0x57c] */
/* @0x1c23f8 ldr r0, [pc, #0x57c] */
/* @0x1c23fc mov r2, #2 */
/* @0x1c2400 mov r3, #1 */
/* @0x1c2404 ldr r1, [r4, r1] */
/* @0x1c2408 add r0, pc, r0 */
/* → layer_tile_yscale  F_LayerTileYScale 0x1bf5d0  argc=2 */
/* @0x1c240c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2410 ldr r1, [pc, #0x568] */
/* @0x1c2414 ldr r0, [pc, #0x568] */
/* @0x1c2418 mov r2, #2 */
/* @0x1c241c mov r3, #1 */
/* @0x1c2420 ldr r1, [r4, r1] */
/* @0x1c2424 add r0, pc, r0 */
/* → layer_tile_blend  F_LayerTileBlend 0x1bf65c  argc=2 */
/* @0x1c2428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c242c ldr r1, [pc, #0x554] */
/* @0x1c2430 ldr r0, [pc, #0x554] */
/* @0x1c2434 mov r2, #2 */
/* @0x1c2438 mov r3, #1 */
/* @0x1c243c ldr r1, [r4, r1] */
/* @0x1c2440 add r0, pc, r0 */
/* → layer_tile_alpha  F_LayerTileAlpha 0x1bf6f0  argc=2 */
/* @0x1c2444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2448 ldr r1, [pc, #0x540] */
/* @0x1c244c ldr r0, [pc, #0x540] */
/* @0x1c2450 mov r2, #2 */
/* @0x1c2454 mov r3, #1 */
/* @0x1c2458 ldr r1, [r4, r1] */
/* @0x1c245c add r0, pc, r0 */
/* → layer_tile_x  F_LayerTileX 0x1bf77c  argc=2 */
/* @0x1c2460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2464 ldr r1, [pc, #0x52c] */
/* @0x1c2468 ldr r0, [pc, #0x52c] */
/* @0x1c246c mov r2, #2 */
/* @0x1c2470 mov r3, #1 */
/* @0x1c2474 ldr r1, [r4, r1] */
/* @0x1c2478 add r0, pc, r0 */
/* → layer_tile_y  F_LayerTileY 0x1bf808  argc=2 */
/* @0x1c247c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2480 ldr r1, [pc, #0x518] */
/* @0x1c2484 ldr r0, [pc, #0x518] */
/* @0x1c2488 mov r2, #5 */
/* @0x1c248c mov r3, #1 */
/* @0x1c2490 ldr r1, [r4, r1] */
/* @0x1c2494 add r0, pc, r0 */
/* → layer_tile_region  F_LayerTileRegion 0x1bfe08  argc=5 */
/* @0x1c2498 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c249c ldr r1, [pc, #0x504] */
/* @0x1c24a0 ldr r0, [pc, #0x504] */
/* @0x1c24a4 mov r2, #2 */
/* @0x1c24a8 mov r3, #1 */
/* @0x1c24ac ldr r1, [r4, r1] */
/* @0x1c24b0 add r0, pc, r0 */
/* → layer_tile_visible  F_LayerTileVisible 0x1bf894  argc=2 */
/* @0x1c24b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c24b8 ldr r1, [pc, #0x4f0] */
/* @0x1c24bc ldr r0, [pc, #0x4f0] */
/* @0x1c24c0 mov r2, #1 */
/* @0x1c24c4 mov r3, r2 */
/* @0x1c24c8 ldr r1, [r4, r1] */
/* @0x1c24cc add r0, pc, r0 */
/* → layer_tile_get_sprite  F_LayerTileGetSprite 0x1bf934  argc=1 */
/* @0x1c24d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c24d4 ldr r1, [pc, #0x4dc] */
/* @0x1c24d8 ldr r0, [pc, #0x4dc] */
/* @0x1c24dc mov r2, #1 */
/* @0x1c24e0 mov r3, r2 */
/* @0x1c24e4 ldr r1, [r4, r1] */
/* @0x1c24e8 add r0, pc, r0 */
/* → layer_tile_get_xscale  F_LayerTileGetXScale 0x1bf9c8  argc=1 */
/* @0x1c24ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c24f0 ldr r1, [pc, #0x4c8] */
/* @0x1c24f4 ldr r0, [pc, #0x4c8] */
/* @0x1c24f8 mov r2, #1 */
/* @0x1c24fc mov r3, r2 */
/* @0x1c2500 ldr r1, [r4, r1] */
/* @0x1c2504 add r0, pc, r0 */
/* → layer_tile_get_yscale  F_LayerTileGetYScale 0x1bfa68  argc=1 */
/* @0x1c2508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c250c ldr r1, [pc, #0x4b4] */
/* @0x1c2510 ldr r0, [pc, #0x4b4] */
/* @0x1c2514 mov r2, #1 */
/* @0x1c2518 mov r3, r2 */
/* @0x1c251c ldr r1, [r4, r1] */
/* @0x1c2520 add r0, pc, r0 */
/* → layer_tile_get_blend  F_LayerTileGetBlend 0x1bfb08  argc=1 */
/* @0x1c2524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2528 ldr r1, [pc, #0x4a0] */
/* @0x1c252c ldr r0, [pc, #0x4a0] */
/* @0x1c2530 mov r2, #1 */
/* @0x1c2534 mov r3, r2 */
/* @0x1c2538 ldr r1, [r4, r1] */
/* @0x1c253c add r0, pc, r0 */
/* → layer_tile_get_alpha  F_LayerTileGetAlpha 0x1bfba4  argc=1 */
/* @0x1c2540 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2544 b 0x1c2a00 <_ZN13CLayerManager18InitLayerFunctionsEv+0x14c0> */
/* ── 字面量池 0x1c2548..0x1c29fc（302 字），不是指令 ────────────────────────
 *   0x1c2548 = GOT 基址偏移 0x002306fc；之后 151 对 (GOT 槽偏移, 名字偏移)
 *   名字偏移那半边被 objdump 按 ARM 译码显示成 andseq / ldrsb，实际是数据
 *   前 146 条用正的 ldr [pc,#imm] 取池子；最后 4 条（layer_tile_get_x/y/region/visible）
 *   和末尾那条尾调用用 ldr [pc,#-0x30] 之类负偏移取同一池子
 */
/* @0x1c2548 .word 0x002306fc */
/* @0x1c254c .word 0xffffec34 */
/* @0x1c2550 andseq lr, r8, r8, lsr r6 */
/* @0x1c2554 .word 0xffffec38 */
/* @0x1c2558 andseq lr, r8, r12, lsr #12 */
/* @0x1c255c .word 0xffffec3c */
/* @0x1c2560 andseq lr, r8, r8, lsr #12 */
/* @0x1c2564 .word 0xffffec40 */
/* @0x1c2568 andseq lr, r8, r12, lsl r6 */
/* @0x1c256c .word 0xffffec44 */
/* @0x1c2570 andseq lr, r8, r0, lsl r6 */
/* @0x1c2574 .word 0xffffec48 */
/* @0x1c2578 andseq lr, r8, r4, lsl #12 */
/* @0x1c257c .word 0xffffec4c */
/* @0x1c2580 andseq lr, r8, r0, lsl #12 */
/* @0x1c2584 .word 0xffffec50 */
/* @0x1c2588 ldrsheq lr, [r8], -r8 */
/* @0x1c258c .word 0xffffec54 */
/* @0x1c2590 ldrsheq lr, [r8], -r0 */
/* @0x1c2594 .word 0xffffec58 */
/* @0x1c2598 andseq lr, r8, r8, ror #11 */
/* @0x1c259c .word 0xffffec5c */
/* @0x1c25a0 andseq lr, r8, r0, ror #11 */
/* @0x1c25a4 .word 0xffffec60 */
/* @0x1c25a8 ldrsbeq lr, [r8], -r4 */
/* @0x1c25ac .word 0xffffec64 */
/* @0x1c25b0 andseq lr, r8, r0, asr #11 */
/* @0x1c25b4 .word 0xffffec68 */
/* @0x1c25b8 andseq lr, r8, r12, lsr #11 */
/* @0x1c25bc .word 0xffffec6c */
/* @0x1c25c0 mulseq r8, r12, r5 */
/* @0x1c25c4 .word 0xffffec70 */
/* @0x1c25c8 andseq lr, r8, r12, lsl #11 */
/* @0x1c25cc .word 0xffffec74 */
/* @0x1c25d0 andseq lr, r8, r0, lsl #11 */
/* @0x1c25d4 .word 0xffffec78 */
/* @0x1c25d8 andseq lr, r8, r4, ror r5 */
/* @0x1c25dc .word 0xffffec7c */
/* @0x1c25e0 andseq lr, r8, r12, ror #10 */
/* @0x1c25e4 .word 0xffffec80 */
/* @0x1c25e8 andseq lr, r8, r4, ror #10 */
/* @0x1c25ec .word 0xffffec84 */
/* @0x1c25f0 andseq lr, r8, r12, asr r5 */
/* @0x1c25f4 .word 0xffffec88 */
/* @0x1c25f8 andseq lr, r8, r4, asr r5 */
/* @0x1c25fc .word 0xffffec8c */
/* @0x1c2600 andseq lr, r8, r8, asr #10 */
/* @0x1c2604 .word 0xffffec90 */
/* @0x1c2608 andseq lr, r8, r4, asr #10 */
/* @0x1c260c .word 0xffffec94 */
/* @0x1c2610 andseq lr, r8, r0, asr #10 */
/* @0x1c2614 .word 0xffffec98 */
/* @0x1c2618 andseq lr, r8, r8, lsr r5 */
/* @0x1c261c .word 0xffffec9c */
/* @0x1c2620 andseq lr, r8, r4, lsr r5 */
/* @0x1c2624 .word 0xffffeca0 */
/* @0x1c2628 andseq lr, r8, r0, lsr r5 */
/* @0x1c262c .word 0xffffeca4 */
/* @0x1c2630 andseq lr, r8, r12, lsr #10 */
/* @0x1c2634 .word 0xffffeca8 */
/* @0x1c2638 andseq lr, r8, r0, lsr #10 */
/* @0x1c263c .word 0xffffecac */
/* @0x1c2640 andseq lr, r8, r12, lsl r5 */
/* @0x1c2644 .word 0xffffecb0 */
/* @0x1c2648 andseq lr, r8, r0, lsl r5 */
/* @0x1c264c .word 0xffffecb4 */
/* @0x1c2650 andseq lr, r8, r0, lsl #10 */
/* @0x1c2654 .word 0xffffecb8 */
/* @0x1c2658 ldrsheq lr, [r8], -r12 */
/* @0x1c265c .word 0xffffecbc */
/* @0x1c2660 ldrsheq lr, [r8], -r8 */
/* @0x1c2664 .word 0xffffecc0 */
/* @0x1c2668 ldrsheq lr, [r8], -r0 */
/* @0x1c266c .word 0xffffecc4 */
/* @0x1c2670 andseq lr, r8, r12, ror #9 */
/* @0x1c2674 .word 0xffffecc8 */
/* @0x1c2678 andseq lr, r8, r12, ror #9 */
/* @0x1c267c .word 0xffffeccc */
/* @0x1c2680 andseq lr, r8, r8, ror #9 */
/* @0x1c2684 .word 0xffffecd0 */
/* @0x1c2688 andseq lr, r8, r4, ror #9 */
/* @0x1c268c .word 0xffffecd4 */
/* @0x1c2690 andseq lr, r8, r0, ror #9 */
/* @0x1c2694 .word 0xffffecd8 */
/* @0x1c2698 ldrsbeq lr, [r8], -r12 */
/* @0x1c269c .word 0xffffecdc */
/* @0x1c26a0 ldrsbeq lr, [r8], -r12 */
/* @0x1c26a4 .word 0xffffece0 */
/* @0x1c26a8 ldrsbeq lr, [r8], -r12 */
/* @0x1c26ac .word 0xffffece4 */
/* @0x1c26b0 ldrsbeq lr, [r8], -r8 */
/* @0x1c26b4 .word 0xffffece8 */
/* @0x1c26b8 ldrsbeq lr, [r8], -r4 */
/* @0x1c26bc .word 0xffffecec */
/* @0x1c26c0 ldrsbeq lr, [r8], -r0 */
/* @0x1c26c4 .word 0xffffecf0 */
/* @0x1c26c8 andseq lr, r8, r12, asr #9 */
/* @0x1c26cc .word 0xffffecf4 */
/* @0x1c26d0 andseq lr, r8, r12, asr #9 */
/* @0x1c26d4 .word 0xffffecf8 */
/* @0x1c26d8 andseq lr, r8, r8, asr #9 */
/* @0x1c26dc .word 0xffffecfc */
/* @0x1c26e0 andseq lr, r8, r4, asr #9 */
/* @0x1c26e4 .word 0xffffed00 */
/* @0x1c26e8 andseq lr, r8, r0, asr #9 */
/* @0x1c26ec .word 0xffffed04 */
/* @0x1c26f0 ldrheq lr, [r8], -r12 */
/* @0x1c26f4 ldrheq lr, [r8], -r12 */
/* @0x1c26f8 .word 0xffffed08 */
/* @0x1c26fc ldrheq lr, [r8], -r4 */
/* @0x1c2700 .word 0xffffed0c */
/* @0x1c2704 ldrheq lr, [r8], -r8 */
/* @0x1c2708 .word 0xffffed10 */
/* @0x1c270c ldrheq lr, [r8], -r8 */
/* @0x1c2710 .word 0xffffed14 */
/* @0x1c2714 ldrheq lr, [r8], -r8 */
/* @0x1c2718 .word 0xffffed18 */
/* @0x1c271c ldrheq lr, [r8], -r8 */
/* @0x1c2720 .word 0xffffed1c */
/* @0x1c2724 ldrheq lr, [r8], -r8 */
/* @0x1c2728 .word 0xffffed20 */
/* @0x1c272c ldrheq lr, [r8], -r8 */
/* @0x1c2730 .word 0xffffed24 */
/* @0x1c2734 ldrheq lr, [r8], -r12 */
/* @0x1c2738 .word 0xffffed28 */
/* @0x1c273c ldrheq lr, [r8], -r12 */
/* @0x1c2740 .word 0xffffed2c */
/* @0x1c2744 ldrheq lr, [r8], -r12 */
/* @0x1c2748 .word 0xffffed30 */
/* @0x1c274c ldrheq lr, [r8], -r12 */
/* @0x1c2750 .word 0xffffed34 */
/* @0x1c2754 ldrheq lr, [r8], -r12 */
/* @0x1c2758 .word 0xffffed38 */
/* @0x1c275c ldrheq lr, [r8], -r4 */
/* @0x1c2760 .word 0xffffed3c */
/* @0x1c2764 andseq lr, r8, r12, lsr #9 */
/* @0x1c2768 .word 0xffffed40 */
/* @0x1c276c andseq lr, r8, r4, lsr #9 */
/* @0x1c2770 .word 0xffffed44 */
/* @0x1c2774 andseq lr, r8, r0, lsr #9 */
/* @0x1c2778 .word 0xffffed48 */
/* @0x1c277c mulseq r8, r8, r4 */
/* @0x1c2780 .word 0xffffed4c */
/* @0x1c2784 mulseq r8, r0, r4 */
/* @0x1c2788 .word 0xffffed50 */
/* @0x1c278c andseq lr, r8, r8, lsl #9 */
/* @0x1c2790 .word 0xffffed54 */
/* @0x1c2794 andseq lr, r8, r0, lsl #9 */
/* @0x1c2798 .word 0xffffed58 */
/* @0x1c279c andseq lr, r8, r8, ror r4 */
/* @0x1c27a0 .word 0xffffed5c */
/* @0x1c27a4 andseq lr, r8, r0, ror r4 */
/* @0x1c27a8 .word 0xffffed60 */
/* @0x1c27ac andseq lr, r8, r8, ror #8 */
/* @0x1c27b0 .word 0xffffed64 */
/* @0x1c27b4 andseq lr, r8, r0, ror #8 */
/* @0x1c27b8 .word 0xffffed68 */
/* @0x1c27bc andseq lr, r8, r4, asr r4 */
/* @0x1c27c0 .word 0xffffed6c */
/* @0x1c27c4 andseq lr, r8, r8, asr #8 */
/* @0x1c27c8 .word 0xffffed70 */
/* @0x1c27cc andseq lr, r8, r4, asr #8 */
/* @0x1c27d0 .word 0xffffed74 */
/* @0x1c27d4 andseq lr, r8, r0, asr #8 */
/* @0x1c27d8 .word 0xffffed78 */
/* @0x1c27dc andseq lr, r8, r12, lsr r4 */
/* @0x1c27e0 .word 0xffffed7c */
/* @0x1c27e4 andseq lr, r8, r8, lsr r4 */
/* @0x1c27e8 .word 0xffffed80 */
/* @0x1c27ec andseq lr, r8, r4, lsr r4 */
/* @0x1c27f0 .word 0xffffed84 */
/* @0x1c27f4 andseq lr, r8, r0, lsr r4 */
/* @0x1c27f8 .word 0xffffed88 */
/* @0x1c27fc andseq lr, r8, r12, lsr #8 */
/* @0x1c2800 .word 0xffffed8c */
/* @0x1c2804 andseq lr, r8, r8, lsr #8 */
/* @0x1c2808 .word 0xffffed90 */
/* @0x1c280c andseq lr, r8, r0, lsr #8 */
/* @0x1c2810 .word 0xffffed94 */
/* @0x1c2814 andseq lr, r8, r8, lsl r4 */
/* @0x1c2818 .word 0xffffed98 */
/* @0x1c281c andseq lr, r8, r4, lsl r4 */
/* @0x1c2820 .word 0xffffed9c */
/* @0x1c2824 andseq lr, r8, r4, lsl r4 */
/* @0x1c2828 .word 0xffffeda0 */
/* @0x1c282c andseq lr, r8, r0, lsl r4 */
/* @0x1c2830 .word 0xffffeda4 */
/* @0x1c2834 andseq lr, r8, r12, lsl #8 */
/* @0x1c2838 .word 0xffffeda8 */
/* @0x1c283c andseq lr, r8, r8, lsl #8 */
/* @0x1c2840 .word 0xffffedac */
/* @0x1c2844 andseq lr, r8, r4, lsl #8 */
/* @0x1c2848 .word 0xffffedb0 */
/* @0x1c284c ldrsheq lr, [r8], -r8 */
/* @0x1c2850 .word 0xffffedb4 */
/* @0x1c2854 andseq lr, r8, r8, ror #7 */
/* @0x1c2858 .word 0xffffedb8 */
/* @0x1c285c ldrsbeq lr, [r8], -r8 */
/* @0x1c2860 .word 0xffffedbc */
/* @0x1c2864 andseq lr, r8, r8, asr #7 */
/* @0x1c2868 .word 0xffffedc0 */
/* @0x1c286c andseq lr, r8, r4, asr #7 */
/* @0x1c2870 .word 0xffffedc4 */
/* @0x1c2874 ldrheq lr, [r8], -r12 */
/* @0x1c2878 .word 0xffffedc8 */
/* @0x1c287c ldrheq lr, [r8], -r8 */
/* @0x1c2880 .word 0xffffedcc */
/* @0x1c2884 ldrheq lr, [r8], -r4 */
/* @0x1c2888 .word 0xffffedd0 */
/* @0x1c288c andseq lr, r8, r12, lsr #7 */
/* @0x1c2890 .word 0xffffedd4 */
/* @0x1c2894 andseq lr, r8, r4, lsr #7 */
/* @0x1c2898 .word 0xffffedd8 */
/* @0x1c289c mulseq r8, r8, r3 */
/* @0x1c28a0 .word 0xffffeddc */
/* @0x1c28a4 andseq lr, r8, r12, lsl #7 */
/* @0x1c28a8 .word 0xffffede0 */
/* @0x1c28ac andseq lr, r8, r12, ror r3 */
/* @0x1c28b0 .word 0xffffede4 */
/* @0x1c28b4 andseq lr, r8, r8, ror r3 */
/* @0x1c28b8 .word 0xffffede8 */
/* @0x1c28bc andseq lr, r8, r8, ror r3 */
/* @0x1c28c0 .word 0xffffedec */
/* @0x1c28c4 andseq lr, r8, r8, ror r3 */
/* @0x1c28c8 .word 0xffffedf0 */
/* @0x1c28cc andseq lr, r8, r12, ror #6 */
/* @0x1c28d0 .word 0xffffedf4 */
/* @0x1c28d4 andseq lr, r8, r0, ror #6 */
/* @0x1c28d8 .word 0xffffedf8 */
/* @0x1c28dc andseq lr, r8, r0, asr r3 */
/* @0x1c28e0 .word 0xffffedfc */
/* @0x1c28e4 andseq lr, r8, r12, asr #6 */
/* @0x1c28e8 .word 0xffffee00 */
/* @0x1c28ec andseq lr, r8, r8, asr #6 */
/* @0x1c28f0 .word 0xffffee04 */
/* @0x1c28f4 andseq lr, r8, r0, asr #6 */
/* @0x1c28f8 .word 0xffffee08 */
/* @0x1c28fc andseq lr, r8, r8, lsr r3 */
/* @0x1c2900 .word 0xffffee0c */
/* @0x1c2904 andseq lr, r8, r0, lsr r3 */
/* @0x1c2908 .word 0xffffee10 */
/* @0x1c290c andseq lr, r8, r4, lsr #6 */
/* @0x1c2910 .word 0xffffee14 */
/* @0x1c2914 andseq lr, r8, r8, lsl r3 */
/* @0x1c2918 .word 0xffffee18 */
/* @0x1c291c andseq lr, r8, r12, lsl #6 */
/* @0x1c2920 .word 0xffffee1c */
/* @0x1c2924 andseq lr, r8, r0, lsl #6 */
/* @0x1c2928 .word 0xffffee20 */
/* @0x1c292c ldrsheq lr, [r8], -r4 */
/* @0x1c2930 .word 0xffffee24 */
/* @0x1c2934 andseq lr, r8, r8, ror #5 */
/* @0x1c2938 .word 0xffffee28 */
/* @0x1c293c ldrsbeq lr, [r8], -r12 */
/* @0x1c2940 .word 0xffffee2c */
/* @0x1c2944 ldrsbeq lr, [r8], -r0 */
/* @0x1c2948 .word 0xffffee30 */
/* @0x1c294c andseq lr, r8, r4, asr #5 */
/* @0x1c2950 .word 0xffffee34 */
/* @0x1c2954 ldrheq lr, [r8], -r8 */
/* @0x1c2958 .word 0xffffee38 */
/* @0x1c295c ldrheq lr, [r8], -r0 */
/* @0x1c2960 .word 0xffffee3c */
/* @0x1c2964 andseq lr, r8, r8, lsr #5 */
/* @0x1c2968 .word 0xffffee40 */
/* @0x1c296c andseq lr, r8, r0, lsr #5 */
/* @0x1c2970 .word 0xffffee44 */
/* @0x1c2974 mulseq r8, r8, r2 */
/* @0x1c2978 .word 0xffffee48 */
/* @0x1c297c mulseq r8, r0, r2 */
/* @0x1c2980 .word 0xffffee4c */
/* @0x1c2984 andseq lr, r8, r8, lsl #5 */
/* @0x1c2988 .word 0xffffee50 */
/* @0x1c298c andseq lr, r8, r0, lsl #5 */
/* @0x1c2990 .word 0xffffee54 */
/* @0x1c2994 andseq lr, r8, r8, ror r2 */
/* @0x1c2998 .word 0xffffee58 */
/* @0x1c299c andseq lr, r8, r12, ror #4 */
/* @0x1c29a0 .word 0xffffee5c */
/* @0x1c29a4 andseq lr, r8, r0, ror #4 */
/* @0x1c29a8 .word 0xffffee60 */
/* @0x1c29ac andseq lr, r8, r8, asr r2 */
/* @0x1c29b0 .word 0xffffee64 */
/* @0x1c29b4 andseq lr, r8, r0, asr r2 */
/* @0x1c29b8 .word 0xffffee68 */
/* @0x1c29bc andseq lr, r8, r12, asr #4 */
/* @0x1c29c0 .word 0xffffee6c */
/* @0x1c29c4 andseq lr, r8, r8, asr #4 */
/* @0x1c29c8 .word 0xffffee70 */
/* @0x1c29cc andseq lr, r8, r4, asr #4 */
/* @0x1c29d0 .word 0xffffee74 */
/* @0x1c29d4 andseq lr, r8, r0, asr #4 */
/* @0x1c29d8 .word 0xffffee78 */
/* @0x1c29dc andseq sp, r8, r0, lsl #27 */
/* @0x1c29e0 .word 0xffffee7c */
/* @0x1c29e4 andseq sp, r8, r8, ror sp */
/* @0x1c29e8 .word 0xffffee80 */
/* @0x1c29ec andseq sp, r8, r0, ror sp */
/* @0x1c29f0 .word 0xffffee84 */
/* @0x1c29f4 andseq sp, r8, r12, ror #26 */
/* @0x1c29f8 .word 0xffffee88 */
/* @0x1c29fc andseq sp, r8, r8, ror #26 */
/* @0x1c2a00 ldr r1, [pc, #-0x30] */
/* @0x1c2a04 ldr r0, [pc, #-0x30] */
/* @0x1c2a08 mov r2, #1 */
/* @0x1c2a0c mov r3, r2 */
/* @0x1c2a10 ldr r1, [r4, r1] */
/* @0x1c2a14 add r0, pc, r0 */
/* → layer_tile_get_x  F_LayerTileGetX 0x1bfc3c  argc=1 */
/* @0x1c2a18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2a1c ldr r1, [pc, #-0x44] */
/* @0x1c2a20 ldr r0, [pc, #-0x44] */
/* @0x1c2a24 mov r2, #1 */
/* @0x1c2a28 mov r3, r2 */
/* @0x1c2a2c ldr r1, [r4, r1] */
/* @0x1c2a30 add r0, pc, r0 */
/* → layer_tile_get_y  F_LayerTileGetY 0x1bfcd4  argc=1 */
/* @0x1c2a34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2a38 ldr r1, [pc, #-0x58] */
/* @0x1c2a3c ldr r0, [pc, #-0x58] */
/* @0x1c2a40 mov r2, #1 */
/* @0x1c2a44 mov r3, r2 */
/* @0x1c2a48 ldr r1, [r4, r1] */
/* @0x1c2a4c add r0, pc, r0 */
/* → layer_tile_get_region  F_LayerTileGetRegion 0x1bfec4  argc=1 */
/* @0x1c2a50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1c2a54 ldr r1, [pc, #-0x6c] */
/* @0x1c2a58 ldr r0, [pc, #-0x6c] */
/* @0x1c2a5c mov r2, #1 */
/* @0x1c2a60 mov r3, r2 */
/* @0x1c2a64 ldr r1, [r4, r1] */
/* @0x1c2a68 add r0, pc, r0 */
/* → layer_tile_get_visible  F_LayerTileGetVisible 0x1bfd6c  argc=1 */
/* @0x1c2a6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* ── 第 151 条：layer_instance_get_instance → F_LayerInstanceGetInstance 0x1bff94, argc=1 ──
 *   没有 bl：pop 完寄存器后 b 0xcdf84（尾调用 Function_Add）
 *   ⇒ 数注册条数别只数 bl：150 bl + 1 尾调用 b = 151
 */
/* @0x1c2a70 ldr r1, [pc, #-0x80] */
/* @0x1c2a74 ldr r0, [pc, #-0x80] */
/* @0x1c2a78 mov r2, #1 */
/* @0x1c2a7c mov r3, r2 */
/* @0x1c2a80 ldr r1, [r4, r1] */
/* @0x1c2a84 add r0, pc, r0 */
/* @0x1c2a88 pop {r4, r5, r6, lr} */
/* @0x1c2a8c b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
