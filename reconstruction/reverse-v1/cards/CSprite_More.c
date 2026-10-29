/* cally 逆向卡：CSprite 碰撞掩码 + 精灵表管理（原版 libyoyo.so，armv7）
 * @func 0x1e3d88 0x1e42a8  size 1312  328 条  CSprite::ComputeMask
 * @func 0x1e4298 0x1e4a30  size 1944  486 条  CSprite::PreciseCollision
 * @func 0x1eebbc 0x1eed4c  size 400  100 条  Sprite_Init
 * @func 0x1eed3c 0x1eede0  size 164  41 条  Sprite_Free
 * @func 0x1eedd0 0x1eee40  size 112  28 条  Sprite_InitTextures
 * @func 0x1eee30 0x1eee94  size 100  25 条  Sprite_FreeTextures
 * @func 0x1eee84 0x1eeea8  size 36  9 条  Sprite_Number
 * @func 0x1eee98 0x1eeef0  size 88  22 条  Sprite_Exists
 * @func 0x1eeee0 0x1eef74  size 148  37 条  Sprite_Name
 * @func 0x1eef64 0x1ef03c  size 216  54 条  Sprite_Find
 * @func 0x1ef454 0x1ef514  size 192  48 条  Sprite_Assign
 * 级别: 正文（1146/1146 逐条落锚，check_card_anchors.py 合并索引口径 EXACT；
 *             两张大函数形参落位表、CMask/TPE/哈希表三套结构布局、四条全局的 .dynsym 定名、
 *             掩码三档包围盒、碰撞三路径（整数/缩放/旋转）全部证到指令；
 *             未钉：CSprite 字段官方名、TMaskCreate 内部形状语义、g_spriteLookup 的填充方、
 *                   ComputeMask 第 1 参的官方名）
 * 符号: _ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii
 *         → void CSprite::ComputeMask(bool bAll, int mode, tagYYRECT const& r, int shapeMode, int alphaThreshold)
 *       _ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff
 *         → int CSprite::PreciseCollision(int subA, tagYYRECT* rectA, int xA, int yA,
 *                                         float sxA, float syA, float rotA,
 *                                         CSprite* other, int subB, tagYYRECT* rectB, int xB, int yB,
 *                                         float sxB, float syB, float rotB)
 *       _Z11Sprite_Initv / _Z11Sprite_Freev / _Z19Sprite_InitTexturesv / _Z19Sprite_FreeTexturesv
 *       _Z13Sprite_Numberv / _Z13Sprite_Existsi / _Z11Sprite_Namei / _Z11Sprite_FindPKc / _Z13Sprite_Assignii
 * 同层: Sprite_Data 0x1ef03c（精灵号→CSprite* 唯一取数口，已有卡）、Sprite_Delete 0x1ef1ec、
 *       Sprite_AddEmpty 0x1ef890、Sprite_Add 0x1f114c、Sprite_Replace 0x1ef5a8、Sprite_Duplicate 0x1f07f0
 *       （这五个是**写**精灵表/哈希表的一侧，本卡不展开，见 open）；
 *       CSprite::CreateMask 0x1e3bcc（整图 0/1 掩码，比本卡的 ComputeMask 早一代）、
 *       CSprite::FreeMask 0x1e3b58、CSprite::UnpackWADMask 0x1e3994（+0x64/+0x68 的 WAD 解包）、
 *       CSprite::TMaskCreate 0x1e35e4、CSprite::InitTexture 0x1e5748、CSprite::FreeTexture 0x1e56fc、
 *       CSprite::InitLocalTPE 0x1e5854、CSprite::GetTexture 0x1e57f4、
 *       CSprite::ctor 0x1e761c、CSprite::Assign 0x1e76e8、CSprite::D0 0x1e76cc、
 *       CSkeletonInstance::SpriteCollision 0xbf0fc、MemoryManager::Alloc 0x27ce78 /
 *       SetLength 0x27d068 / Free 0x27c2d0、CHashMapCalculateHash<char const*> 0x1eeb88、
 *       CProfiler::Push 0x2a0738 / Pop 0x2a08ac、sinf/cosf @plt 0xb6580 / 0xb658c
 *
 * ── 一句话 ─────────────────────────────────────────────────────────────
 *   ComputeMask 是"把一个 CSprite 的每个子图压成 1 字节/像素的碰撞掩码"的唯一入口：
 *   它先按 image_number 铺 CMask 数组（this+0x40，元素 {int size; u8* bits} 共 8 字节），
 *   再用三档办法算包围盒（调用方给 / 整图 / 逐像素扫 alpha），最后逐子图调 TMaskCreate 填位。
 *   PreciseCollision 是掩码的消费口：先把两个精灵的屏幕矩形求交，再在交区里逐像素
 *   反算两边的局部坐标、各查一次掩码，两边都非 0 就算碰。三条路径按 scale==1 与 rot==0 分：
 *   整数直读 → 逆缩放 → 逆旋转+逆缩放。
 *   Sprite_* 九个函数是精灵表本身：一张 CSprite** 表 + 一张名字表 + 一张 name→index 哈希表。
 *
 * ── 精灵表三件套（本卡最重要的一组布局）──────────────────────────────
 *   0x7530d0  g_SpriteItems      8 B  DWORD24   { +0x0 ?（本组只被 Sprite_Free 清零，从不读）;
 *                                                 +0x4 CSprite** items }   ← 唯一被读的字段
 *   0x7530d8  g_NumberOfSprites  4 B  int        精灵数（= sprite_get_number）
 *   0x7530dc  g_SpriteNames      4 B  char**     名字数组指针（不是内联数组：所有读点都 ldr 一次再 [base+i*4]）
 *   0x7530e0  g_spriteLookup    20 B  { int size@0; int used@4; u32 mask@8; int thr@0xc; Bucket* tab@0x10 }
 *                                    Bucket = 12 B { ?@0（本卡所有读点都不读，疑为键指针）;
 *                                                    int value@4（精灵号）; u32 hash@8（0 = 空桶） }
 *   四个全局的 GOT 槽都在 0x3f0e10..0x3f0e1c，四个槽全是 R_ARM_RELATIVE（llvm-readelf -r 逐条核过），
 *   槽内容 = 上表地址，名字全部来自 .dynsym（非推断）。
 *   Sprite_Init / Sprite_Free 的 GOT 基址是 0x3f1c58（r9 = pc + 0x203088），
 *   PreciseCollision 是 0x3f1c58（r7 = pc + 0x20d99c），Draw 卡记的同一基址，三处互证。
 *
 * ── CSprite 字段（本卡读/写的偏移；官方名未证，理由见 open）────────────
 *   0x00  vptr → _ZTV7CSprite+8（ctor 1e7638/1e7644 写入；vtable 在 0x3ebe60，
 *         [0]=0(offset-to-top) [4]=typeinfo 0x3ebe58 [8]=D1 0x1e76a4 [0xc]=D0 0x1e76cc
 *         ⇒ 对象 vptr 指向 0x3ebe68，vptr[0]=D1、vptr[1]=D0（删除析构））
 *   0x04  int    ?（Assign 直接搬）
 *   0x08..0x14  4×int 包围盒 minX/minY/maxX/maxY（ComputeMask 唯一写它；mode 0 空时全 0）
 *   0x18  int    image_number（子图数；<=0 ⇒ 不画、不建掩码、不碰）
 *   0x1c  int    width（掩码行长，也是碰撞列上界）
 *   0x20  int    height
 *   0x24  int    originX（碰撞/绘制都拿它做 x 偏移）
 *   0x28  int    originY
 *   0x2c  int    半径/半边长（Draw 的剔除半径）
 *   0x30..0x35 6×byte 开关（0x30 碰撞检查、0x31 掩码有效、0x32/0x33/0x34 各一个 bool、0x35 ctor 置 1）
 *   0x36  byte   本地 TPE 已建（InitLocalTPE 1e597c 唯一置 1；ctor 清 0；ComputeMask 的第三闸）
 *   0x38  int    本地 TPE 条数（InitLocalTPE 1e5978 写入）
 *   0x3c  int    CMask 数组长度（ComputeMask/FreeMask/UnpackWADMask 写）
 *   0x40  CMask* CMask 数组（8 B/项 {int size; u8* bits}，bits 为 width*height 字节）
 *   0x44  int    位图数（Assign 按它克隆 this+0x48 的每一项；InitLocalTPE 按它铺 TPE）
 *   0x48  CBitmap32** 每子图/每帧的位图数组（掩码与本地 TPE 都从它算）
 *   0x4c  int    纹理数（InitTexture 写 = image_number）
 *   0x50  GR 纹理句柄数组（int*，GR_Texture_Create_Direct 的返回值）
 *   0x54  void** 本地 TPE 数组（元素 22 B，InitLocalTPE malloc(22)；ComputeMask 会就地改页内矩形）
 *   0x58  CSkeletonSprite*（kind==2 时当 this）
 *   0x5c  char*  精灵名字符串（Draw 错误串的 %s；Sprite_Assign 写入）
 *   0x60  int    自己的精灵号（Sprite_Assign 1e4bc 写入）
 *   0x64  int    WAD 掩码条数；0x68 void* WAD 掩码数据（UnpackWADMask 用它懒解包）
 *   0x6c  float  30.0f（ctor 1e7660 写入的唯一非零初值）
 *   0x74  int    后端档位 0=纹理 1=SWF 2=骨骼（ComputeMask 第一闸、InitTexture/GetTexture 同判据）
 *   0x78/0x7c/0x80/0x84 各 1 字段（ctor 清 0）
 *   sizeof(CSprite) = 0x88 = 136（Sprite_Assign 的 _Znwj 实参 136 直接证）
 *
 * ── 已证事实（每条都能指到指令）────────────────────────────────────
 *   1. 掩码是 1 字节/像素、按行主序存整幅图（width*height），不是包围盒裁剪版：
 *      CreateMask 逐行 strb（1e3d20）、UnpackWADMask 按 width*height 铺（1e3a34/1e3a60）、
 *      PreciseCollision 的索引用 mla width*row+col（1e44fc / 1e4560 / 1e46c0）。
 *   2. 掩码的"真值"只有 0/1 两档：CreateMask 的 alpha 测试是 tst #0xFF000000 → moveq 0/movne 1
 *      （1e3d14..1e3d20），ComputeMask 的扫描用 alpha > threshold 判"实心"（1e4100..1e4108）。
 *   3. ComputeMask 一条全局都不碰：全函数只有 1 个池字（源码文件名字符串），零 GOT 访问。
 *   4. 三档包围盒来源 mode=1/2/0 与"不动包围盒"的默认档，落点固定 this+8..+0x14；
 *      空包围盒（0x7FFFFFFF 未命中）在 1e41c0..1e41dc 被写成 4 个 0。
 *   5. PreciseCollision 的三路径判据是 (1/scaleX==1 && 1/scaleY==1) 与 (rotA==0 && rotB==0)：
 *      1e43d0..1e43f4 与 1e4400..1e4420 两组 vcmp/movne/moveq/andeq 把两个布尔 AND 起来，
 *      1e4428..1e4458 再对两侧 rot 做一次；任一为假就走 1e45cc（缩放）或 1e47a8（旋转）。
 *   6. 掩码缺失（this+0x31 == 0）时该侧视为"全实心"：A 侧 1e44e8 beq 跳过掩码读，
 *      B 侧 1e454c beq 直接判碰（1e459c 返回 [sp+0x14]=1）⇒ 只按包围盒相交。
 *   7. 精灵销毁走 vptr[1]（删除析构 D0），不是直接调 operator delete：
 *      Sprite_Init 1eec20..1eec28、Sprite_Free 1eed80..1eed88 都是 ldr vptr / ldr [vptr+4] / blx。
 *   8. Sprite_Free 与 Sprite_Init 不对称：Free 只释放 items（+0x4）并把 count/items/+0 清零，
 *      **不动 g_SpriteNames**；Init 连 names 数组一起 Free 并把 g_SpriteNames 清 0（1eec6c..1eec74）。
 *   9. Sprite_Find 是 Robin-Hood 线性探测：桶里存的是**哈希值本身**（+8）而不是链，
 *      空桶判据 hash==0；探针距离 = (桶号+size-(hash&mask)) & mask（1eefa4..1eefb0、1eeff4..1eeffc）。
 *      查找**只比哈希、不比字符串** ⇒ 撞哈希的不同名字会互相命中（原版行为，不是本卡的推断）。
 *   10. Sprite_Assign(a,b) 是"把 b 拷进 a"：a 的槽为空时先 new(136) + CSprite::CSprite()（1ef4e0..1ef4f4），
 *       再 CSprite::Assign（会 Clear、克隆每张位图、重建纹理/本地 TPE/掩码），最后回填 +0x60=a、+0x5c=names[a]。
 *
 * ── open（本卡没钉住的）──────────────────────────────────────────────
 *  1. CSprite 字段的官方名：本卡全部按偏移记。可用的语义锚点只有 ctor 的清零表、
 *     Assign 的逐字段搬运表和这里的用法；头文件不在 .so 里（只有 .dynsym 的少量全局名）。
 *  2. TMaskCreate 内部的 shapeMode 分派（0=扫 alpha / 1,2,3=三种几何形状 / 其它=从 src 拷贝）：
 *     本卡只证"ComputeMask 把 mode、shapeMode、threshold 原样下传"，形状算法本身不在此卡。
 *  3. g_spriteLookup 的填充方（谁写 value(+4)/hash(+8)、+4 的 used 何时加）：本组九个函数一个都不写它，
 *     只 Sprite_Init 重建空表；候选在 Sprite_AddEmpty/Sprite_Add/Sprite_Delete/Sprite_Replace（0x1ef890/
 *     0x1f114c/0x1ef1ec/0x1ef5a8），未逐条证。
 *  4. ComputeMask 第 1 参的官方名（本卡记 bAll）：结论只到"非 0 走全量子图循环、为 0 走
 *     '先建子图 0 再补 1..n-1' 的另一条循环"，两条路径的调用实参等价，看不出更强语义。
 *  5. 谁在运行时调 ComputeMask/PreciseCollision（房间层 broadphase、CInstance 侧的调点）：
 *     本卡只覆盖被调方；调用方属 CInstance/RTree 那一层，未查。
 *  6. +0x44 与 +0x18 的关系（位图数 vs 子图数）：Assign 分别搬 +0x44（克隆位图用）与 +0x18（子图数），
 *     InitLocalTPE 用 +0x44 铺 TPE、InitTexture 用 +0x18 铺纹理；两者是不同的量，何时相等没有证据。
 *
 * ── 逐条锚点 ────────────────────────────────────────────────────────
 */

/* ── 段 A · CSprite::ComputeMask 0x1e3d88 —— 掩码生成的总入口 ────────────────
 *  签名 _ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii
 *    → void CSprite::ComputeMask(bool bAll, int mode, tagYYRECT const& r,
 *                                int shapeMode, int alphaThreshold)
 *  返回类型：三个出口都不设 r0（返回的是该路径的残留寄存器），没有任何一条把 r0 写成 0/1
 *    ⇒ 记 void；二进制里没有 bool 返回的证据。
 *  帧 88 = push {r4-r11,lr}(36) + sub sp,#52 ⇒ 栈形参 [sp+0x58]=shapeMode、[sp+0x5c]=阈值。
 *  落位：this=r11、rect*=r6、bAll=[sp+0x28]、mode=[sp+0x24]、阈值=r10。
 *  全局：只有 1 个池字（1e4294 = 0x16e640 → 0x35242c
 *        "jni/../jni/yoyo/../../../Files/Sprite/Sprite_Class.cpp"），零 GOT 访问
 *        ⇒ 不读不写任何全局，全部状态在 this。
 *
 *  一图流：三闸 → 铺 CMask 数组 → 三档包围盒 → 逐子图 TMaskCreate → this+0x31 = 1
 *
 *  三闸（命中即原样返回，一个字节都不写）：
 *    ① this+0x74 != 0       只有纹理后端(0)有掩码；SWF(1)/骨骼(2) 直接退。
 *    ② this+0x31 != 0       已有掩码先 FreeMask() 再重建（1e3db0 的 ldrb 就是这条）。
 *    ③ this+0x54 != 0 且 this+0x36 == 0   有 TPE 表但不是本地 TPE（共享页）⇒ 退；
 *       +0x36 由 InitLocalTPE 末尾置 1（1e597c），InitTexture/CreateMask/GetTexture 同判据互证。
 *
 *  输出（本段唯一的写回面）：
 *    this+0x40 = CMask 数组（SetLength(&this[0x40], image_number*8, "Sprite_Class.cpp", 400)）
 *    this+0x3c = 数组长度 = image_number
 *    每项 CMask = 8 B { int size@+0 = width*height ; u8* bits@+4（同尺寸位图，1 B/像素）}
 *    this+0x8..0x14 = 包围盒 4×int（minX/minY/maxX/maxY）
 *    this+0x54[k] 的页内矩形（仅 mode==0 且 +0x36 != 0 时）
 *    this+0x31 = 1
 *
 *  TMaskCreate 契约（形参名取自 _ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii）：
 *    TMaskCreate(CMask* src, CMask* dst, CBitmap32* bmp, int mode, int shapeMode, int threshold)
 *    本段三处调用：src = 0（从位图重算）、dst = &this[0x40][k]、bmp = this[0x48][k]，
 *    (mode, shapeMode, threshold) 原样压栈。内部形状算法不在本卡。
 */

/* @0x1e3d88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e3d8c sub sp, sp, #52 */
/* @0x1e3d90 mov r11, r0 */
/* ── 序言：r11=this、r6=rect*、bAll 与 mode 落栈、阈值进 r10 ─────────────────
 * 取参被编译器打散：1e3d9c 先读 kind 再落 mode（1e3da0），1e3da8 才把 [sp+0x5c] 读进 r10。
 * 1e3d94 r6 = r3 = rect*：整个函数只通过 r6 读矩形 4 个 int。 */
/* @0x1e3d94 mov r6, r3 */
/* @0x1e3d98 str r1, [sp, #0x28] */
/* ── 第一闸：this+0x74（后端档位）非 0 ⇒ 直接返回 ─────────────────────────────
 * 1e3da4 cmp r1,#0 / 1e3dac bne 1e3ecc（尾声）。
 * 判据与 Draw/InitTexture/GetTexture 完全一致：只有 kind==0（纹理）这条后端有 CSprite 自己的掩码。 */
/* @0x1e3d9c ldr r1, [r0, #0x74] */
/* @0x1e3da0 str r2, [sp, #0x24] */
/* @0x1e3da4 cmp r1, #0 */
/* @0x1e3da8 ldr r10, [sp, #0x5c] */
/* @0x1e3dac bne 0x1e3ecc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x144> */
/* ── 第二闸：this+0x31（掩码有效位）非 0 ⇒ FreeMask() 后重建 ─────────────────
 * 1e3db8 bne 1e3ed4 → 1e3ed4 bl FreeMask(0x1e3b58) → 1e3ed8 b 1e3dbc。
 * FreeMask 自己会判 +0x31、逐项 Free(bits) 并把 +0x40/+0x3c/+0x31 清 0（0x1e3b58..0x1e3bc8），
 * 所以这里等价于"先拆旧掩码再全量重建"。 */
/* @0x1e3db0 ldrb r3, [r0, #0x31] */
/* @0x1e3db4 cmp r3, #0 */
/* @0x1e3db8 bne 0x1e3ed4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x14c> */
/* ── 第三闸：有 TPE 表但不是本地 TPE ⇒ 不做掩码 ──────────────────────────────
 * +0x54 == 0 → 1e3dd4 照建；非 0 再读 +0x36：0 ⇒ 1e3ecc 返回，1 ⇒ 继续。
 * +0x36 的唯一置 1 点是 InitLocalTPE 末尾（1e597c strb r3,[r5,#0x36]，r3=1），
 * ctor 1e766c 清 0 ⇒ 这一闸的含义是"TPE 是共享页、不是本地自建"。 */
/* @0x1e3dbc ldr r3, [r11, #0x54] */
/* @0x1e3dc0 cmp r3, #0 */
/* @0x1e3dc4 beq 0x1e3dd4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4c> */
/* @0x1e3dc8 ldrb r3, [r11, #0x36] */
/* @0x1e3dcc cmp r3, #0 */
/* @0x1e3dd0 beq 0x1e3ecc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x144> */
/* ── 铺 CMask 数组：SetLength(&this+0x40, image_number*8, Sprite_Class.cpp:400) ──
 * 1e3dd4 取池字 0x16e640，1e3de4 add r5,pc → 0x35242c（源码文件名，逐字节核过）。
 * 1e3de8 r1 = image_number << 3（8 B/子图）；1e3de0 r0 = this+0x40（&数组指针）；
 * 1e3dd8 r3 = 400（行号）；1e3dec r2 = 文件名。SetLength 语义 = 重设动态数组长度。 */
/* @0x1e3dd4 ldr r5, [pc, #0x4b8] */
/* @0x1e3dd8 mov r3, #400 */
/* @0x1e3ddc ldr r1, [r11, #0x18] */
/* @0x1e3de0 add r0, r11, #64 */
/* @0x1e3de4 add r5, pc, r5 */
/* @0x1e3de8 lsl r1, r1, #3 */
/* @0x1e3dec mov r2, r5 */
/* @0x1e3df0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* ── 数组长度回填 + 逐子图分配位图（循环体 1e3e04..1e3e50）──────────────
 * 1e3dfc str this+0x3c = image_number（这就是段 B 里做 % 的那个 maskCount）。
 * 循环：r1 = width(this+0x1c) * height(this+0x20)；r0 = &CMask[k].bits（数组 + k*8 + 4）；
 *       SetLength(&elem+4, w*h, file, 404)；再 elem.size = w*h。
 * ⇒ 8 字节头 + w*h 字节位图，两层都由 SetLength 分配（不是 malloc，可被 MemoryManager 记账）。 */
/* @0x1e3df4 ldr r3, [r11, #0x18] */
/* @0x1e3df8 cmp r3, #0 */
/* @0x1e3dfc str r3, [r11, #0x3c] */
/* @0x1e3e00 ble 0x1e3e54 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xcc> */
/* @0x1e3e04 ldr r1, [r11, #0x1c] */
/* @0x1e3e08 mov r4, #0 */
/* @0x1e3e0c ldr r3, [r11, #0x20] */
/* @0x1e3e10 ldr r2, [r11, #0x40] */
/* @0x1e3e14 mul r1, r1, r3 */
/* @0x1e3e18 mov r0, r2 */
/* @0x1e3e1c add r0, r0, r4, lsl #3 */
/* @0x1e3e20 mov r2, r5 */
/* @0x1e3e24 add r0, r0, #4 */
/* @0x1e3e28 mov r3, #404 */
/* @0x1e3e2c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e3e30 ldr r2, [r11, #0x1c] */
/* @0x1e3e34 ldr r1, [r11, #0x20] */
/* @0x1e3e38 ldr r0, [r11, #0x40] */
/* @0x1e3e3c ldr r3, [r11, #0x18] */
/* @0x1e3e40 mul r1, r1, r2 */
/* @0x1e3e44 str r1, [r0, r4, lsl #3] */
/* @0x1e3e48 add r4, r4, #1 */
/* @0x1e3e4c cmp r3, r4 */
/* @0x1e3e50 bgt 0x1e3e1c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x94> */
/* ── mode 三档分派（除 this 外唯一的输入选择器）───────────────────────────────
 * mode==1 → 1e4258 整图矩形 (0,0)-(w-1,h-1)
 * mode==2 → 1e3edc 用调用方 rect，并夹到 [0,w-1]×[0,h-1]
 * mode==0 → 1e3ff0 逐像素扫 alpha 求包围盒（唯一会读位图的档）
 * 其它   → 不动 this+8..0x14，直接去建掩码
 * 三档只改 4 个 int，别的什么都不碰。 */
/* @0x1e3e54 ldr r4, [sp, #0x24] */
/* @0x1e3e58 cmp r4, #1 */
/* @0x1e3e5c beq 0x1e4258 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4d0> */
/* @0x1e3e60 cmp r4, #2 */
/* @0x1e3e64 beq 0x1e3edc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x154> */
/* @0x1e3e68 cmp r4, #0 */
/* @0x1e3e6c beq 0x1e3ff0 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x268> */
/* ── bAll 决定走哪条建掩码的循环 ────────────────────────────────────────────
 * bAll==0 → 1e3f74（先建子图 0，再补 1..n-1）；bAll!=0 → 1e3e7c..（一次循环建 0..n-1）。
 * 两条循环的实参等价（src 都是 0、dst/bmp 都是同一个下标），差别只在代码形状，
 * 所以本卡只把 bAll 记成"全量/首帧"选择器，不硬派语义（见 open 4）。 */
/* @0x1e3e70 ldr r4, [sp, #0x28] */
/* @0x1e3e74 cmp r4, #0 */
/* @0x1e3e78 beq 0x1e3f74 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x1ec> */
/* @0x1e3e7c cmp r3, #0 */
/* @0x1e3e80 ble 0x1e3ec4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x13c> */
/* @0x1e3e84 ldr r5, [sp, #0x24] */
/* @0x1e3e88 mov r4, #0 */
/* @0x1e3e8c ldr r6, [sp, #0x58] */
/* ── 逐子图 TMaskCreate（全量分支）───────────────────────────────────────────
 * r0=this、r1=0（src 空）、r2=&CMask[k]、r3=CBitmap32*[k]；
 * 1e3ea8 str r5,[sp]（mode）、1e3eb0 stmib sp,{r6,r10}（shapeMode、threshold）。
 * 返回值不检查：建完一律 this+0x31 = 1（1e3ec4）。 */
/* @0x1e3e90 ldr r3, [r11, #0x48] */
/* @0x1e3e94 mov r0, r11 */
/* @0x1e3e98 ldr r2, [r11, #0x40] */
/* @0x1e3e9c mov r1, #0 */
/* @0x1e3ea0 ldr r3, [r3, r4, lsl #2] */
/* @0x1e3ea4 add r2, r2, r4, lsl #3 */
/* @0x1e3ea8 str r5, [sp] */
/* @0x1e3eac add r4, r4, #1 */
/* @0x1e3eb0 stmib sp, {r6, r10} */
/* @0x1e3eb4 bl 0x1e35e4 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii> */
/* @0x1e3eb8 ldr r3, [r11, #0x18] */
/* @0x1e3ebc cmp r3, r4 */
/* @0x1e3ec0 bgt 0x1e3e90 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x108> */
/* ── 收尾：this+0x31 = 1，唯一尾声 1e3ecc（add sp,#52 / pop r4-r11,pc）─────────
 * 三个出口（1e3ec4 正常、1e3ed4 拆旧、1e3ecc 早退）都汇到同一条 add sp。 */
/* @0x1e3ec4 mov r3, #1 */
/* @0x1e3ec8 strb r3, [r11, #0x31] */
/* @0x1e3ecc add sp, sp, #52 */
/* @0x1e3ed0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3ed4 bl 0x1e3b58 <_ZN7CSprite8FreeMaskEv> */
/* @0x1e3ed8 b 0x1e3dbc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x34> */
/* ── mode 2：把调用方 rect 夹进 [0,width-1]×[0,height-1] ────────────────────
 * tagYYRECT 实测布局（本段 4 次取字段互证）：
 *   +0x0 int x1   +0x4 int y1   +0x8 int x2   +0xc int y2
 * 四次夹取同一个模板：<0 ⇒ 0；>=extent ⇒ extent-1；否则原值（1e3ee4/1e3ef4、1e3f08/1e3f18…）。
 * 落点：x1→this+0x8、x2→this+0x10、y1→this+0xc、y2→this+0x14；
 * x 用 this+0x1c(width)、y 用 this+0x20(height)，两个上界不同，可反证宽度/高度字段位置。 */
/* @0x1e3edc ldr r2, [r6] */
/* @0x1e3ee0 cmp r2, #0 */
/* @0x1e3ee4 movlt r1, #0 */
/* @0x1e3ee8 blt 0x1e3efc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x174> */
/* @0x1e3eec ldr r1, [r11, #0x1c] */
/* @0x1e3ef0 cmp r2, r1 */
/* @0x1e3ef4 subge r1, r1, #1 */
/* @0x1e3ef8 movlt r1, r2 */
/* @0x1e3efc ldr r2, [r6, #0x8] */
/* @0x1e3f00 str r1, [r11, #0x8] */
/* @0x1e3f04 cmp r2, #0 */
/* @0x1e3f08 movlt r1, #0 */
/* @0x1e3f0c blt 0x1e3f20 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x198> */
/* @0x1e3f10 ldr r1, [r11, #0x1c] */
/* @0x1e3f14 cmp r2, r1 */
/* @0x1e3f18 subge r1, r1, #1 */
/* @0x1e3f1c movlt r1, r2 */
/* @0x1e3f20 ldr r2, [r6, #0x4] */
/* @0x1e3f24 str r1, [r11, #0x10] */
/* @0x1e3f28 cmp r2, #0 */
/* @0x1e3f2c movlt r1, #0 */
/* @0x1e3f30 blt 0x1e3f44 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x1bc> */
/* @0x1e3f34 ldr r1, [r11, #0x20] */
/* @0x1e3f38 cmp r2, r1 */
/* @0x1e3f3c subge r1, r1, #1 */
/* @0x1e3f40 movlt r1, r2 */
/* @0x1e3f44 ldr r2, [r6, #0xc] */
/* @0x1e3f48 str r1, [r11, #0xc] */
/* @0x1e3f4c cmp r2, #0 */
/* @0x1e3f50 movlt r2, #0 */
/* @0x1e3f54 blt 0x1e3f64 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x1dc> */
/* @0x1e3f58 ldr r1, [r11, #0x20] */
/* @0x1e3f5c cmp r2, r1 */
/* @0x1e3f60 subge r2, r1, #1 */
/* @0x1e3f64 ldr r4, [sp, #0x28] */
/* @0x1e3f68 str r2, [r11, #0x14] */
/* @0x1e3f6c cmp r4, #0 */
/* @0x1e3f70 bne 0x1e3e7c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xf4> */
/* ── bAll==0：先建子图 0，再补 1..n-1 ───────────────────────────────────────
 * r1 = bAll（此处必 0 ⇒ src 形参为 0）、r2 = this+0x40（&CMask[0]）、r3 = this[0x48][0]。
 * 1e3fa0 闸：image_number <= 1 就收尾；否则 1e3fb4 起 k=1..n-1 补建。
 * ⚠ 补建那次 r1 由 1e3fbc 装成 this+0x40 的值（不是 0）——照实记录：
 *   在 shapeMode==0 时 TMaskCreate 不读 src（其 1e3604 先判 0 档走扫描），
 *   但 shapeMode>=4 的"从 src 拷贝"档会读到这个非空指针，属原版自身边界（见 open 2）。 */
/* @0x1e3f74 ldr r3, [r11, #0x48] */
/* @0x1e3f78 mov r0, r11 */
/* @0x1e3f7c ldr r12, [sp, #0x24] */
/* @0x1e3f80 ldr r4, [sp, #0x58] */
/* @0x1e3f84 ldr r3, [r3] */
/* @0x1e3f88 ldr r2, [r11, #0x40] */
/* @0x1e3f8c ldr r1, [sp, #0x28] */
/* @0x1e3f90 str r12, [sp] */
/* @0x1e3f94 stmib sp, {r4, r10} */
/* @0x1e3f98 bl 0x1e35e4 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii> */
/* @0x1e3f9c ldr r3, [r11, #0x18] */
/* @0x1e3fa0 cmp r3, #1 */
/* @0x1e3fa4 ble 0x1e3ec4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x13c> */
/* @0x1e3fa8 ldr r5, [sp, #0x24] */
/* @0x1e3fac mov r4, #1 */
/* @0x1e3fb0 ldr r6, [sp, #0x58] */
/* @0x1e3fb4 ldr r3, [r11, #0x48] */
/* @0x1e3fb8 mov r0, r11 */
/* @0x1e3fbc ldr r1, [r11, #0x40] */
/* @0x1e3fc0 ldr r3, [r3, r4, lsl #2] */
/* @0x1e3fc4 add r2, r1, r4, lsl #3 */
/* @0x1e3fc8 stm sp, {r5, r6} */
/* @0x1e3fcc add r4, r4, #1 */
/* @0x1e3fd0 str r10, [sp, #0x8] */
/* @0x1e3fd4 bl 0x1e35e4 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii> */
/* @0x1e3fd8 ldr r3, [r11, #0x18] */
/* @0x1e3fdc cmp r3, r4 */
/* @0x1e3fe0 bgt 0x1e3fb4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x22c> */
/* @0x1e3fe4 mov r3, #1 */
/* @0x1e3fe8 strb r3, [r11, #0x31] */
/* @0x1e3fec b 0x1e3ecc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x144> */
/* ── mode 0：包围盒初值 (±0x7FFFFFFF) + 读 +0x36 ────────────────────────────
 * 1e3ff4 mvn r1,#0x80000000 → 0x7FFFFFFF；1e3ff8 mov r2,#0x80000000。
 * 写 this+8/+0xc = 0x7FFFFFFF、this+0x10/+0x14 = 0x80000000（min 用最大、max 用最小）。
 * 1e400c 读 +0x36：为 0 时走 1e41e4 的"只算包围盒"循环，为 1 时走 1e408c 的"包围盒+TPE 双累加"循环。 */
/* @0x1e3ff0 cmp r3, #0 */
/* @0x1e3ff4 mvn r1, #-2147483648 */
/* @0x1e3ff8 mov r2, #-2147483648 */
/* @0x1e3ffc str r1, [r11, #0x8] */
/* @0x1e4000 str r1, [r11, #0xc] */
/* @0x1e4004 str r2, [r11, #0x10] */
/* @0x1e4008 str r2, [r11, #0x14] */
/* @0x1e400c ldrb r4, [r11, #0x36] */
/* @0x1e4010 ble 0x1e41cc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x444> */
/* @0x1e4014 ldr r12, [sp, #0x24] */
/* @0x1e4018 str r12, [sp, #0x20] */
/* ── mode 0 的逐子图扫描：准备 ───────────────────────────────────────────────
 * 1e401c r3 = this[0x48]（位图数组）；1e4028 r5 = CBitmap32*[k]；
 * 1e4038/1e4040 连调两次 GetData()（1e4034/1e403c mov r0,r5）——原版就是这么写的，
 * 第二次的返回值被采用：1e4050 r5 = [r0+4] = 位图像素基址。
 * 1e4044 r2 = this+0x20（height）；1e4058 r0 = this+0x1c（width）；1e4074 [sp+0x1c] = width*4（行跨距）。 */
/* @0x1e401c ldr r3, [r11, #0x48] */
/* @0x1e4020 ldr r12, [sp, #0x20] */
/* @0x1e4024 ldr r2, [sp, #0x20] */
/* @0x1e4028 ldr r5, [r3, r12, lsl #2] */
/* @0x1e402c lsl r2, r2, #2 */
/* @0x1e4030 str r2, [sp, #0x2c] */
/* @0x1e4034 mov r0, r5 */
/* @0x1e4038 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1e403c mov r0, r5 */
/* @0x1e4040 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1e4044 ldr r2, [r11, #0x20] */
/* @0x1e4048 cmp r2, #0 */
/* @0x1e404c str r2, [sp, #0x18] */
/* @0x1e4050 ldr r5, [r0, #0x4] */
/* @0x1e4054 ble 0x1e4280 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4f8> */
/* @0x1e4058 ldr r0, [r11, #0x1c] */
/* @0x1e405c mov r7, #-2147483648 */
/* @0x1e4060 mvn r6, #-2147483648 */
/* @0x1e4064 sub r5, r5, #4 */
/* @0x1e4068 mov r9, r7 */
/* @0x1e406c mov r8, r6 */
/* @0x1e4070 mov r2, #0 */
/* @0x1e4074 lsl r3, r0, #2 */
/* @0x1e4078 str r3, [sp, #0x1c] */
/* ── 行循环（r2 = row，r5 = 当前行像素指针）──────────────────────────────────
 * 1e407c/1e4080：height<=0 直接跳到收尾；1e4084 按 +0x36 二选一进入像素循环。
 * 1e408c..1e4098：r12 = 像素游标，r3 = 列号 0，[sp+0x14] 暂存 +0x36。
 * 行尾 1e4124..1e4138：row++、游标 += width*4、row<height 继续。 */
/* @0x1e407c cmp r0, #0 */
/* @0x1e4080 ble 0x1e4124 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x39c> */
/* @0x1e4084 cmp r4, #0 */
/* @0x1e4088 beq 0x1e41e4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x45c> */
/* @0x1e408c mov r12, r5 */
/* @0x1e4090 mov r3, #0 */
/* @0x1e4094 str r4, [sp, #0x14] */
/* @0x1e4098 b 0x1e40fc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x374> */
/* ── 包围盒更新（alpha > threshold 的像素才算实心）────────────────────────────
 * 1e4100 and r1,r1,#0xFF000000 → 取 ARGB 的 alpha 字节；
 * 1e4104 cmp r1,r10 / 1e4108 bhi 1e409c ⇒ alpha > threshold 才进这里；
 * 1e409c/1e40a8：this+8 = min(minX, col)；1e40ac/1e40b4：this+0x10 = max(maxX, col)；
 * 1e40b8/1e40c0：this+0xc = min(minY, row)；1e40c4/1e40cc：this+0x14 = max(maxY, row)。
 * ⇒ 字段次序从这 4 组 cmp/strgt/strlt 直接读出，不是猜的。 */
/* @0x1e409c ldr r4, [r11, #0x8] */
/* @0x1e40a0 cmp r4, r3 */
/* @0x1e40a4 ldr r4, [r11, #0x10] */
/* @0x1e40a8 strgt r3, [r11, #0x8] */
/* @0x1e40ac cmp r4, r3 */
/* @0x1e40b0 ldr r4, [r11, #0xc] */
/* @0x1e40b4 strlt r3, [r11, #0x10] */
/* @0x1e40b8 cmp r4, r2 */
/* @0x1e40bc ldr r4, [r11, #0x14] */
/* @0x1e40c0 strgt r2, [r11, #0xc] */
/* @0x1e40c4 cmp r4, r2 */
/* @0x1e40c8 bge 0x1e410c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x384> */
/* @0x1e40cc str r2, [r11, #0x14] */
/* @0x1e40d0 cmp r8, r3 */
/* @0x1e40d4 movge r8, r3 */
/* @0x1e40d8 cmp r9, r3 */
/* @0x1e40dc movlt r9, r3 */
/* @0x1e40e0 add r3, r3, #1 */
/* @0x1e40e4 cmp r6, r2 */
/* @0x1e40e8 movge r6, r2 */
/* @0x1e40ec cmp r7, r2 */
/* @0x1e40f0 movlt r7, r2 */
/* @0x1e40f4 cmp r3, r0 */
/* @0x1e40f8 beq 0x1e4120 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x398> */
/* ── 像素循环：ldr r1,[r12,#4]! 前索引取下一个像素 ───────────────────────────
 * 因为 1e4064 预先 sub r5,#4、这里又是前索引，两者抵消（入口 r12 = 像素基址-4 的效果）。
 * 1e410c：alpha 非 0 但 <= 阈值 ⇒ 不参与包围盒，只更新 r6..r9 这组局部极值（TPE 用）。 */
/* @0x1e40fc ldr r1, [r12, #0x4]! */
/* @0x1e4100 and r1, r1, #-16777216 */
/* @0x1e4104 cmp r1, r10 */
/* @0x1e4108 bhi 0x1e409c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x314> */
/* @0x1e410c cmp r1, #0 */
/* @0x1e4110 bne 0x1e40d0 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x348> */
/* @0x1e4114 add r3, r3, #1 */
/* @0x1e4118 cmp r3, r0 */
/* @0x1e411c bne 0x1e40fc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x374> */
/* @0x1e4120 ldr r4, [sp, #0x14] */
/* @0x1e4124 ldr r3, [sp, #0x18] */
/* @0x1e4128 add r2, r2, #1 */
/* @0x1e412c ldr r12, [sp, #0x1c] */
/* @0x1e4130 cmp r2, r3 */
/* @0x1e4134 add r5, r5, r12 */
/* @0x1e4138 bne 0x1e407c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x2f4> */
/* ── 子图扫完：本地 TPE 的页内矩形结算（仅 +0x36 != 0）───────────────────────
 * 1e4140 beq 1e41a8 ⇒ 没有本地 TPE 就跳过整段。
 * 1e4144 r3 = this[0x54][k]（22 B 的 TPE 条目）；1e4148 用 cmn r8,#-(2^31-1) 判
 * 局部 minX 是否仍是 0x7FFFFFFF（一像素都没命中）。
 * 1e4158..1e41a4 一次写满 8 个 halfword：
 *   +0 = 旧 +0 + 相对 minX(=r8)     +2 = 旧 +2 + 相对 minY(=r6)
 *   +4 = 宽 = (maxX+1) - minX       +6 = 高 = (maxY+1) - minY
 *   +8 = 相对 minX                  +0xa = 相对 minY
 *   +0xc = 宽                       +0xe = 高
 * ⇒ +0/+2 是"页内绝对左上（增量式累加）"，+8/+10 是"相对精灵左上"，宽度/高度各存两份。
 * 1e423c：一像素都没命中时写 +8=0、+0xa=0、+0xc=1、+0xe=1（1×1 空矩形标记）。 */
/* @0x1e413c cmp r4, #0 */
/* @0x1e4140 beq 0x1e41a8 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x420> */
/* @0x1e4144 ldr r3, [r11, #0x54] */
/* @0x1e4148 cmn r8, #-2147483647 */
/* @0x1e414c ldr r12, [sp, #0x2c] */
/* @0x1e4150 ldr r3, [r3, r12] */
/* @0x1e4154 beq 0x1e423c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4b4> */
/* @0x1e4158 uxth r1, r6 */
/* @0x1e415c uxth r12, r8 */
/* @0x1e4160 add r0, r9, #1 */
/* @0x1e4164 add r2, r7, #1 */
/* @0x1e4168 rsb r0, r12, r0 */
/* @0x1e416c rsb r2, r1, r2 */
/* @0x1e4170 ldrh r5, [r3] */
/* @0x1e4174 strh r6, [r3, #10] */
/* @0x1e4178 uxth r0, r0 */
/* @0x1e417c ldrh r6, [r3, #2] */
/* @0x1e4180 uxth r2, r2 */
/* @0x1e4184 add r12, r12, r5 */
/* @0x1e4188 strh r8, [r3, #8] */
/* @0x1e418c add r1, r1, r6 */
/* @0x1e4190 strh r0, [r3, #12] */
/* @0x1e4194 strh r0, [r3, #4] */
/* @0x1e4198 strh r2, [r3, #14] */
/* @0x1e419c strh r2, [r3, #6] */
/* @0x1e41a0 strh r12, [r3] */
/* @0x1e41a4 strh r1, [r3, #2] */
/* ── 下一个子图（1e41a8..1e41bc）──────────────────────────────────────────────
 * 1e41b0 k++、1e41b8 与 image_number 比；1e41c0 收尾判 this+8 是否仍 0x7FFFFFFF，
 * 是则 1e41cc 把 4 个包围盒字段清 0，然后统一去 1e3e70（建掩码）。 */
/* @0x1e41a8 ldr r2, [sp, #0x20] */
/* @0x1e41ac ldr r3, [r11, #0x18] */
/* @0x1e41b0 add r2, r2, #1 */
/* @0x1e41b4 str r2, [sp, #0x20] */
/* @0x1e41b8 cmp r3, r2 */
/* @0x1e41bc bgt 0x1e401c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x294> */
/* @0x1e41c0 ldr r2, [r11, #0x8] */
/* @0x1e41c4 cmn r2, #-2147483647 */
/* @0x1e41c8 bne 0x1e3e70 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xe8> */
/* @0x1e41cc mov r2, #0 */
/* @0x1e41d0 str r2, [r11, #0x8] */
/* @0x1e41d4 str r2, [r11, #0x10] */
/* @0x1e41d8 str r2, [r11, #0xc] */
/* @0x1e41dc str r2, [r11, #0x14] */
/* @0x1e41e0 b 0x1e3e70 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xe8> */
/* @0x1e41e4 mov r1, r5 */
/* @0x1e41e8 mov r3, r4 */
/* @0x1e41ec ldr r12, [r1, #0x4]! */
/* @0x1e41f0 and r12, r12, #-16777216 */
/* @0x1e41f4 cmp r10, r12 */
/* @0x1e41f8 bhs 0x1e422c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4a4> */
/* @0x1e41fc ldr r12, [r11, #0x8] */
/* @0x1e4200 cmp r3, r12 */
/* @0x1e4204 ldr r12, [r11, #0x10] */
/* @0x1e4208 strlt r3, [r11, #0x8] */
/* @0x1e420c cmp r3, r12 */
/* @0x1e4210 ldr r12, [r11, #0xc] */
/* @0x1e4214 strgt r3, [r11, #0x10] */
/* @0x1e4218 cmp r12, r2 */
/* @0x1e421c ldr r12, [r11, #0x14] */
/* @0x1e4220 strgt r2, [r11, #0xc] */
/* @0x1e4224 cmp r12, r2 */
/* @0x1e4228 strlt r2, [r11, #0x14] */
/* @0x1e422c add r3, r3, #1 */
/* @0x1e4230 cmp r3, r0 */
/* @0x1e4234 bne 0x1e41ec <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x464> */
/* @0x1e4238 b 0x1e4124 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x39c> */
/* @0x1e423c mov r2, #0 */
/* @0x1e4240 mov r12, #1 */
/* @0x1e4244 strh r2, [r3, #8] */
/* @0x1e4248 strh r2, [r3, #10] */
/* @0x1e424c strh r12, [r3, #12] */
/* @0x1e4250 strh r12, [r3, #14] */
/* @0x1e4254 b 0x1e41a8 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x420> */
/* ── mode 1：整图矩形 ───────────────────────────────────────────────────────
 * this+8 = 0、this+0xc = 0、this+0x10 = width-1、this+0x14 = height-1
 * （1e4260/1e4264/1e426c/1e4270 四次 sub #1）。不需读位图，是最省的档。 */
/* @0x1e4258 ldr r0, [r11, #0x1c] */
/* @0x1e425c mov r2, #0 */
/* @0x1e4260 ldr r1, [r11, #0x20] */
/* @0x1e4264 sub r0, r0, #1 */
/* @0x1e4268 str r2, [r11, #0x8] */
/* @0x1e426c sub r1, r1, #1 */
/* @0x1e4270 str r0, [r11, #0x10] */
/* @0x1e4274 str r2, [r11, #0xc] */
/* @0x1e4278 str r1, [r11, #0x14] */
/* @0x1e427c b 0x1e3e70 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xe8> */
/* ── mode 0 且 height<=0：只有局部极值初始化，然后直接去结算 ──────────────────
 * r7 = 0x80000000、r6 = 0x7FFFFFFF、r9 = r7、r8 = r6，再 b 1e413c。 */
/* @0x1e4280 mov r7, #-2147483648 */
/* @0x1e4284 mvn r6, #-2147483648 */
/* @0x1e4288 mov r9, r7 */
/* @0x1e428c mov r8, r6 */
/* @0x1e4290 b 0x1e413c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x3b4> */
/* @0x1e4294 andseq lr, r6, r0, asr #12 */
/* ── 段 B · CSprite::PreciseCollision 0x1e4298 —— 掩码消费口（逐像素判碰）────
 *  签名 _ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff → 15 个形参：
 *    int CSprite::PreciseCollision(int subA, tagYYRECT* rectA, int xA, int yA,
 *                                  float sxA, float syA, float rotA,
 *                                  CSprite* other, int subB, tagYYRECT* rectB, int xB, int yB,
 *                                  float sxB, float syB, float rotB)
 *  帧 120 = push {r4-r11,lr}(36) + vpush {d8-d12}(40) + sub sp,#44 ⇒ 栈形参从 [sp+0x78] 起。
 *
 *  形参落位表（逐条来自本函数的取参指令；寄存器 4 个 + 栈 11 个 = 15 个显式形参 + this）
 *    this = r0        subA = r1        rectA = r2        xA = r3   [1e42b8 str→sp+0xc]
 *    yA           = [sp+0x78]   [1e42c8 → r9]
 *    sxA          = [sp+0x7c]   [1e4360 vldr s5]
 *    syA          = [sp+0x80]   [1e4370 vldr s11]
 *    rotA         = [sp+0x84]   [1e4428 vldr s14]
 *    other        = [sp+0x88]   [1e42cc → r6]
 *    subB         = [sp+0x8c]   [1e4314 / 1e4350 / 1e4464]
 *    rectB        = [sp+0x90]   [1e4384 → r12]
 *    xB           = [sp+0x94]   [1e44a0 → r9]
 *    yB           = [sp+0x98]   [1e42dc → r11]
 *    sxB          = [sp+0x9c]   [1e4364 vldr s8]
 *    syB          = [sp+0xa0]   [1e4388 vldr s13]
 *    rotB         = [sp+0xa4]   [1e4430 vldr s15]
 *  ⚠ 与 Draw 卡不同，这里的 float 形参与 int 形参交替压栈（i,f,f,f,ptr,i,ptr,i,i,f,f,f），
 *    完全按 mangled 的类型序对账过，不是"先 3 个 float"的常见排法。
 *
 *  返回：int，1 = 碰、0 = 不碰。结果变量就是 [sp+0x14]：
 *    1e4454 在"无旋转"路径把它设成 1（候选相交为真），1e4594 的任何范围失败把它清 0；
 *    命中时 1e4a14 / 1e4a0c 把该侧掩码字节（=1）写进去，1e4a00 在"B 无掩码"时直接写 1。
 *
 *  前置（任一失败返回 0，1e4594）：
 *    other==0、this->image_number<=0、other->image_number<=0。
 *    然后 UnpackWADMask(this, subA) / UnpackWADMask(other, subB)（0x1e3994，懒解包 WAD 掩码），
 *    再把两个子图号对**解包后**的掩码条数 this+0x3c / other+0x3c 取模（负余数补正）。
 *
 *  三条路径（判据见 1e43d0..1e4458）：
 *    (a) 无缩放（1/sx==1 且 1/sy==1）且无旋转 → 整数直读（1e445c..1e4590）
 *    (b) 有缩放、无旋转 → 逐像素逆缩放（1e45cc..1e4788）
 *    (c) 任一侧有旋转 → 逐像素逆旋转+逆缩放（1e47a8..1e49f0），角度→弧度用 π/180
 *
 *  掩码读法（三路径同一口径）：bits[ row*width + col ]，width = 该精灵 this+0x1c，
 *  局部坐标 col = (x - 精灵屏幕x)*1/sx + this+0x24，row = (y - 精灵屏幕y)*1/sy + this+0x28，
 *  取整用 vcvt.s32.f32（向零截断），越界一律跳过该像素。
 *  掩码缺失（+0x31==0）⇒ 该侧视为全实心（A 侧跳过读、B 侧直接判碰）。
 *
 *  开销：交区面积 × 两侧各一次 ldrb；没有任何加速结构、没有早退优化（除范围检查）。
 *  这是 RTree 之前的碰撞形态：调用方已经用矩形把范围收窄，函数内部纯像素级判定。
 */

/* @0x1e4298 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e429c vpush {d8, d9, d10, d11, d12} */
/* @0x1e42a0 mov r4, r0 */
/* ── GOT 基址 0x3f1c58（r7 = pc + 0x20d99c），与 Draw 卡同一基址 ───────────────
 * 1e42ac 取 0xffffbf18 = -0x40E8 ⇒ 0x3edb70 = g_bProfile（1 B）；
 * 1e4790/1e45ac 取 0xffffbf1c = -0x40E4 ⇒ 0x3edb74 = g_Profiler（128 B）。
 * 两个槽都是 R_ARM_RELATIVE，名字来自 .dynsym。 */
/* @0x1e42a4 ldr r7, [pc, #0x778] */
/* @0x1e42a8 sub sp, sp, #44 */
/* @0x1e42ac ldr r0, [pc, #0x774] */
/* @0x1e42b0 mov r10, r1 */
/* @0x1e42b4 add r7, pc, r7 */
/* @0x1e42b8 str r3, [sp, #0xc] */
/* @0x1e42bc str r7, [sp, #0x1c] */
/* @0x1e42c0 mov r5, r2 */
/* ── 剖析闸：*(g_bProfile) != 0 ⇒ CProfiler::Push(&g_Profiler, 6, 3) ──────────
 * 只有这一处全局读；尾声 1e45a0 再读同一个字节决定是否 Pop（成对，不含早退路径）。 */
/* @0x1e42c4 ldr r0, [r7, r0] */
/* @0x1e42c8 ldr r9, [sp, #0x78] */
/* @0x1e42cc ldr r6, [sp, #0x88] */
/* @0x1e42d0 ldrb r3, [r0] */
/* @0x1e42d4 str r0, [sp, #0x20] */
/* @0x1e42d8 cmp r3, #0 */
/* @0x1e42dc ldr r11, [sp, #0x98] */
/* @0x1e42e0 bne 0x1e4790 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4f8> */
/* ── 三道前置闸 ─────────────────────────────────────────────────────────────
 * other==0（1e42e4/1e42e8）→ 1e4594 结果 0；
 * this+0x18 <= 0（1e42ec..1e42f4）→ 0；other+0x18 <= 0（1e42f8..1e4300）→ 0。
 * 注意判的是 image_number 而不是掩码条数：掩码条数在后面才解包出来。 */
/* @0x1e42e4 cmp r6, #0 */
/* @0x1e42e8 beq 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e42ec ldr r3, [r4, #0x18] */
/* @0x1e42f0 cmp r3, #0 */
/* @0x1e42f4 ble 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e42f8 ldr r3, [r6, #0x18] */
/* @0x1e42fc cmp r3, #0 */
/* @0x1e4300 ble 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* ── UnpackWADMask 两侧各一次（0x1e3994）────────────────────────────────────
 * (this, subA) 与 (other, [sp+0x8c])；该函数内部若 +0x31 已置就立刻返回，
 * 否则用 +0x64（条数）/+0x68（压缩数据）现铺 CMask 数组 —— 所以本函数必须在取模之前调。 */
/* @0x1e4304 mov r0, r4 */
/* @0x1e4308 mov r1, r10 */
/* @0x1e430c bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* @0x1e4310 mov r0, r6 */
/* @0x1e4314 ldr r1, [sp, #0x8c] */
/* @0x1e4318 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* ── 子图号归一化：subA %= this+0x3c（负余数 +count）────────────────────────
 * 1e432c __aeabi_idivmod(r10, r7)，余数在 r1；1e4338/1e433c 负则加回 count。
 * 1e4340..1e4358 对 other+0x3c 做同一件事，结果写回 [sp+0x8c]。
 * ⇒ this+0x3c 是"掩码条数"，可能就是 image_number（ComputeMask 1e3dfc 写的就是它），
 *    但两者在 WAD 精灵上可以不同（UnpackWADMask 用 +0x64 写 +0x3c）。 */
/* @0x1e431c ldr r7, [r4, #0x3c] */
/* @0x1e4320 cmp r7, #0 */
/* @0x1e4324 ble 0x1e4338 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0xa0> */
/* @0x1e4328 mov r0, r10 */
/* @0x1e432c mov r1, r7 */
/* @0x1e4330 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e4334 mov r10, r1 */
/* @0x1e4338 cmp r10, #0 */
/* @0x1e433c addlt r10, r10, r7 */
/* @0x1e4340 ldr r7, [r6, #0x3c] */
/* @0x1e4344 cmp r7, #0 */
/* @0x1e4348 ble 0x1e435c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0xc4> */
/* @0x1e434c ldr r0, [sp, #0x8c] */
/* @0x1e4350 mov r1, r7 */
/* @0x1e4354 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e4358 str r1, [sp, #0x8c] */
/* ── 常量与倒数：1.0、1/sxA、1/syA、1/sxB、1/syB ─────────────────────────────
 * 1e435c vmov.f32 s15,#1.0；1e4398 s16 = 1/s5(sxA)；1e43cc s20 = 1/s8(sxB)；
 * 1e43f4 s18 = 1/s11(syA)；1e43f8 s21 = 1/s13(syB)。
 * 后两条路径全程只用倒数乘法（没有逐像素除法）。 */
/* @0x1e435c vmov.f32 s15, #1.000000e+00 */
/* @0x1e4360 vldr s5, [sp, #124] */
/* @0x1e4364 vldr s8, [sp, #156] */
/* @0x1e4368 ldr r12, [sp, #0x8c] */
/* ── 交区：对两个 tagYYRECT 逐边取 max/min ───────────────────────────────────
 * rectA 在 r5：r3 = [r5]（x1）、r1 = [r5+8]（x2）、r2 = [r5+4]（y1）、[r5+0xc]（y2）；
 * rectB 在 r12：[r12] / [r12+4] / [r12+8] / [r12+0xc]。
 * 1e439c r7 = max(x1A, x1B)；1e43a8 r0 = min(x2A, x2B)；1e43b8 r8 = max(y1A, y1B)；
 * 1e43c4 r5 = min(y2A, y2B)；[sp+0x18] = minX2（列循环上界）。
 * ⇒ 交区完全由调用方传来的两个矩形决定，函数**不**用 sprite 尺寸再收一次边。 */
/* @0x1e436c ldr r3, [r5] */
/* @0x1e4370 vldr s11, [sp, #128] */
/* @0x1e4374 cmp r12, #0 */
/* @0x1e4378 ldr r1, [r5, #0x8] */
/* @0x1e437c addlt r12, r12, r7 */
/* @0x1e4380 strlt r12, [sp, #0x8c] */
/* @0x1e4384 ldr r12, [sp, #0x90] */
/* @0x1e4388 vldr s13, [sp, #160] */
/* @0x1e438c ldr r2, [r5, #0x4] */
/* @0x1e4390 ldr r7, [r12] */
/* @0x1e4394 ldr r0, [r12, #0x8] */
/* @0x1e4398 vdiv.f32 s16, s15, s5 */
/* @0x1e439c cmp r7, r3 */
/* @0x1e43a0 movlt r7, r3 */
/* @0x1e43a4 ldr r8, [r12, #0x4] */
/* @0x1e43a8 cmp r0, r1 */
/* @0x1e43ac movge r0, r1 */
/* @0x1e43b0 ldr r3, [r5, #0xc] */
/* @0x1e43b4 ldr r5, [r12, #0xc] */
/* @0x1e43b8 cmp r8, r2 */
/* @0x1e43bc movlt r8, r2 */
/* @0x1e43c0 str r0, [sp, #0x18] */
/* @0x1e43c4 cmp r5, r3 */
/* @0x1e43c8 movge r5, r3 */
/* @0x1e43cc vdiv.f32 s20, s15, s8 */
/* ── 缩放判据：先比 1/sxA 与 1/syA，再比 1/sxB 与 1/syB，四个都 ==1.0 才算"无缩放" ──
 * 每条都是 vcmp + movne r3,#0 + moveq r3,#1 + vmrs + 再一条 vcmp + andeq r3,r3,#1
 * ⇒ r3 = (1/sxA==1) && (1/syA==1) && (1/sxB==1) && (1/syB==1)。
 * 为 0 → 1e45cc（缩放路径）。用倒数判等而不是直接比 scale，是编译器把 1/scale 提前算好的结果。 */
/* @0x1e43d0 vcmp.f32 s16, s15 */
/* @0x1e43d4 vmrs APSR_nzcv, fpscr */
/* @0x1e43d8 vcmp.f32 s20, s15 */
/* @0x1e43dc movne r3, #0 */
/* @0x1e43e0 moveq r3, #1 */
/* @0x1e43e4 vmrs APSR_nzcv, fpscr */
/* @0x1e43e8 movne r3, #0 */
/* @0x1e43ec andeq r3, r3, #1 */
/* @0x1e43f0 cmp r3, #0 */
/* @0x1e43f4 vdiv.f32 s18, s15, s11 */
/* @0x1e43f8 vdiv.f32 s21, s15, s13 */
/* @0x1e43fc beq 0x1e45cc <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x334> */
/* @0x1e4400 vcmp.f32 s18, s15 */
/* @0x1e4404 vmrs APSR_nzcv, fpscr */
/* @0x1e4408 vcmp.f32 s21, s15 */
/* @0x1e440c movne r3, #0 */
/* @0x1e4410 moveq r3, #1 */
/* @0x1e4414 vmrs APSR_nzcv, fpscr */
/* @0x1e4418 movne r3, #0 */
/* @0x1e441c andeq r3, r3, #1 */
/* @0x1e4420 cmp r3, #0 */
/* @0x1e4424 beq 0x1e45cc <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x334> */
/* ── 旋转判据：rotA==0 && rotB==0（同样两条 vcmp 的与）──────────────────────
 * 1e4428 s14 = rotA、1e4430 s15 = rotB；结果写 [sp+0x14]（也是返回值初值）。
 * 为 0 → 1e47a8（旋转路径）。到这里四条判据都过 ⇒ 整数快路径。 */

/* ── 快路径的列范围闸：minX2 < maxX1 ⇒ 直接返回 0 ───────────────────────────
 * 1e445c cmp r0,r7 / 1e4460 blt 1e4594。行范围闸在 1e4484（maxY1 > minY2 ⇒ 1e4584 收尾）。 */
/* @0x1e4428 vldr s14, [sp, #132] */
/* @0x1e442c vcmp.f32 s14, #0 */
/* @0x1e4430 vldr s15, [sp, #164] */
/* @0x1e4434 vmrs APSR_nzcv, fpscr */
/* @0x1e4438 vcmp.f32 s15, #0 */
/* @0x1e443c movne r3, #0 */
/* @0x1e4440 moveq r3, #1 */
/* @0x1e4444 vmrs APSR_nzcv, fpscr */
/* @0x1e4448 movne r3, #0 */
/* @0x1e444c andeq r3, r3, #1 */
/* @0x1e4450 cmp r3, #0 */
/* @0x1e4454 str r3, [sp, #0x14] */
/* @0x1e4458 beq 0x1e47a8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x510> */
/* @0x1e445c cmp r0, r7 */
/* @0x1e4460 blt 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e4464 ldr r0, [sp, #0x8c] */
/* @0x1e4468 lsl r10, r10, #3 */
/* ── 快路径准备：行偏移、subB*8、返回值暂存 ─────────────────────────────────
 * 1e446c r9 = maxY1 - yA ⇒ A 侧起始行（相对精灵左上，未加原点）。
 * 1e4478 r0 = subB << 3（后面 &CMask[subB] 用）；[sp+0x24] = 同一值。
 * 1e447c [sp+0x4] = yB；1e44b0 [sp] = 当前列（r7 在循环里被复用，故压栈保存）。 */
/* @0x1e446c rsb r9, r9, r8 */
/* @0x1e4470 str r10, [sp, #0x8] */
/* @0x1e4474 str r9, [sp, #0x10] */
/* @0x1e4478 lsl r0, r0, #3 */
/* @0x1e447c str r11, [sp, #0x4] */
/* @0x1e4480 str r0, [sp, #0x24] */
/* ── 外层 = 列（r7 从 maxX1 到 minX2），内层 = 行（r3 从 maxY1 到 minY2）─────
 * 1e4484 cmp r8,r5 / 1e4488 bgt 1e4584 ⇒ 行区间空就整段跳过。
 * 1e4490 r3 = r8（行起点）、1e4494 r10 = [sp+0xc]（xA）。 */
/* @0x1e4484 cmp r8, r5 */
/* @0x1e4488 bgt 0x1e4584 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2ec> */
/* @0x1e448c ldr r10, [sp, #0xc] */
/* @0x1e4490 mov r3, r8 */
/* ── A 侧局部坐标 ───────────────────────────────────────────────────────────
 * 列：1e4498 rsb r1,r10,r7（= x - xA）→ 1e44a4 add r1,r1,this+0x24（+originX）
 * 行：1e44b4 r2 = [sp+0x10]（= maxY1 - yA）→ 1e44b4 add r2,r10,r12 之前 r10=[sp+0x10]、
 *     r12 = this+0x28（+originY）⇒ r2 = 行 + originY
 * 越界闸：0 <= col < this+0x1c（1e44b8..1e44c8）、0 <= row < this+0x20（1e44cc..1e44dc）。
 * ⇒ 原点 (this+0x24/+0x28) 是"精灵图内左上到锚点的位移"，与 Draw 的 ox/oy 同一对字段。 */
/* @0x1e4494 ldr r2, [r4, #0x24] */
/* @0x1e4498 rsb r1, r10, r7 */
/* @0x1e449c ldr r12, [r4, #0x28] */
/* @0x1e44a0 ldr r9, [sp, #0x94] */
/* @0x1e44a4 add r1, r1, r2 */
/* @0x1e44a8 ldr r10, [sp, #0x10] */
/* @0x1e44ac rsb r0, r9, r7 */
/* @0x1e44b0 str r7, [sp] */
/* @0x1e44b4 add r2, r10, r12 */
/* @0x1e44b8 cmp r1, #0 */
/* @0x1e44bc blt 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e44c0 ldr r12, [r4, #0x1c] */
/* @0x1e44c4 cmp r12, r1 */
/* @0x1e44c8 ble 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e44cc cmp r2, #0 */
/* @0x1e44d0 blt 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e44d4 ldr r9, [r4, #0x20] */
/* @0x1e44d8 cmp r2, r9 */
/* @0x1e44dc bge 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* ── A 侧掩码读：bits[row*width + col] ──────────────────────────────────────
 * 1e44e8 若 this+0x31 == 0 → 1e450c（跳过掩码，视为实心）；
 * 否则 1e44fc mla r12, width, row, bits；1e4500 ldrb；为 0 → 1e4570 下一个像素。 */
/* @0x1e44e0 ldrb r9, [r4, #0x31] */
/* @0x1e44e4 cmp r9, #0 */
/* @0x1e44e8 beq 0x1e450c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x274> */
/* @0x1e44ec ldr r9, [r4, #0x40] */
/* @0x1e44f0 ldr r7, [sp, #0x8] */
/* @0x1e44f4 add r9, r9, r7 */
/* @0x1e44f8 ldr r9, [r9, #0x4] */
/* @0x1e44fc mla r12, r12, r2, r9 */
/* @0x1e4500 ldrb r12, [r12, r1] */
/* @0x1e4504 cmp r12, #0 */
/* @0x1e4508 beq 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* ── B 侧局部坐标 + 掩码读 ──────────────────────────────────────────────────
 * 列：1e4514 r12 = (x - xB) + other+0x24；行：1e452c rsb r11,r7,r3（x/y 交换后）= y - yB，
 *     1e4530 r9 = other+0x28 + 该值。
 * 越界闸与 A 侧同构（1e4518..1e4540）。
 * 1e454c 若 other+0x31 == 0 → 1e459c 直接返回 [sp+0x14]=1（只按矩形判碰）；
 * 否则 1e4560 mla、1e4564 ldrb，非 0 ⇒ 1e4a14 写结果并返回。 */
/* @0x1e450c ldr r12, [r6, #0x24] */
/* @0x1e4510 ldr r9, [r6, #0x28] */
/* @0x1e4514 adds r12, r0, r12 */
/* @0x1e4518 bmi 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e451c ldr r10, [r6, #0x1c] */
/* @0x1e4520 cmp r12, r10 */
/* @0x1e4524 bge 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e4528 ldr r7, [sp, #0x4] */
/* @0x1e452c rsb r11, r7, r3 */
/* @0x1e4530 adds r9, r9, r11 */
/* @0x1e4534 bmi 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e4538 ldr r11, [r6, #0x20] */
/* @0x1e453c cmp r9, r11 */
/* @0x1e4540 bge 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e4544 ldrb r11, [r6, #0x31] */
/* @0x1e4548 cmp r11, #0 */
/* @0x1e454c beq 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4550 ldr r11, [r6, #0x40] */
/* @0x1e4554 ldr r7, [sp, #0x24] */
/* @0x1e4558 add r11, r11, r7 */
/* @0x1e455c ldr r11, [r11, #0x4] */
/* @0x1e4560 mla r9, r10, r9, r11 */
/* @0x1e4564 ldrb r12, [r9, r12] */
/* @0x1e4568 cmp r12, #0 */
/* @0x1e456c bne 0x1e4a14 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x77c> */
/* @0x1e4570 add r3, r3, #1 */
/* @0x1e4574 add r2, r2, #1 */
/* @0x1e4578 cmp r5, r3 */
/* @0x1e457c bge 0x1e44b8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x220> */
/* @0x1e4580 ldr r7, [sp] */
/* @0x1e4584 ldr r9, [sp, #0x18] */
/* @0x1e4588 add r7, r7, #1 */
/* @0x1e458c cmp r7, r9 */
/* @0x1e4590 ble 0x1e4484 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x1ec> */
/* ── 失败口：结果 = 0；命中口在 1e4a14/1e4a0c/1e4a00 ───────────────────────
 * 1e459c 之后是统一的剖面收尾：g_bProfile 非 0 才 Pop，然后 r0 = [sp+0x14] 返回。 */
/* @0x1e4594 mov r1, #0 */
/* @0x1e4598 str r1, [sp, #0x14] */
/* @0x1e459c ldr r7, [sp, #0x20] */
/* @0x1e45a0 ldrb r3, [r7] */
/* @0x1e45a4 cmp r3, #0 */
/* @0x1e45a8 beq 0x1e45bc <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x324> */
/* @0x1e45ac ldr r3, [pc, #0x478] */
/* @0x1e45b0 ldr r9, [sp, #0x1c] */
/* @0x1e45b4 ldr r0, [r9, r3] */
/* @0x1e45b8 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1e45bc ldr r0, [sp, #0x14] */
/* @0x1e45c0 add sp, sp, #44 */
/* @0x1e45c4 vpop {d8, d9, d10, d11, d12} */
/* @0x1e45c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 缩放路径入口：再确认两侧 rot==0（否则去旋转路径）────────────────────────
 * 1e45cc/1e45d4 重读 rotA/rotB、1e45f8 把同一个布尔写回 [sp+0x14]；
 * 双轴缩放下界还要判 !=0（vcmp #0 的 or 项），为 0 说明缩放退化，直接 1e47a8 交给旋转路径。 */
/* @0x1e45cc vldr s5, [sp, #132] */
/* @0x1e45d0 vcmp.f32 s5, #0 */
/* @0x1e45d4 vldr s8, [sp, #164] */
/* @0x1e45d8 vmrs APSR_nzcv, fpscr */
/* @0x1e45dc vcmp.f32 s8, #0 */
/* @0x1e45e0 movne r3, #0 */
/* @0x1e45e4 moveq r3, #1 */
/* @0x1e45e8 vmrs APSR_nzcv, fpscr */
/* @0x1e45ec movne r3, #0 */
/* @0x1e45f0 andeq r3, r3, #1 */
/* @0x1e45f4 cmp r3, #0 */
/* @0x1e45f8 str r3, [sp, #0x14] */
/* @0x1e45fc beq 0x1e47a8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x510> */
/* @0x1e4600 ldr r1, [sp, #0x18] */
/* @0x1e4604 cmp r1, r7 */
/* @0x1e4608 blt 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e460c ldr r2, [sp, #0x8c] */
/* @0x1e4610 lsl r12, r10, #3 */
/* @0x1e4614 str r11, [sp, #0x10] */
/* @0x1e4618 lsl r2, r2, #3 */
/* @0x1e461c str r2, [sp, #0x24] */
/* @0x1e4620 cmp r8, r5 */
/* @0x1e4624 bgt 0x1e477c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4e4> */
/* @0x1e4628 ldr r10, [sp, #0xc] */
/* ── 缩放路径：A 侧逆映射（两轴都用 vmla，乘子 s16=1/sxA、s18=1/syA）────────────
 * 1e462c vldr s8,[this+0x24] → s15 = (float)originX；1e4634 vldr s11,[this+0x28] = originY。
 * 列：1e4638 dx = x - xA（r3）；1e4650 vcvt s14=(float)dx；1e4654 vmla s15 = originX + s16*dx
 *     ⇒ col = (int)(originX + (x-xA)/sxA)（1e4658 vcvt.s32 向零截断）；闸 1e4664..1e4674。
 * 行：1e467c..1e4688 s5 = originY + s18*dy ⇒ row = (int)(originY + (y-yA)/syA)；闸 1e4694..1e46a4。
 * 1e46a8..1e46cc：A 掩码读（this+0x31==0 则整段跳过）。
 * B 侧 1e46d0..1e476c 完全同构（originX/originY 换成 other 的 +0x24/+0x28，乘子换 s20/s21）。
 * 取整是 vcvt.s32.f32（向零）而不是 floor ⇒ 负坐标侧不对称，这是原版实测口径，不是笔误。 */
/* @0x1e462c vldr s8, [r4, #36] */
/* @0x1e4630 vcvt.f32.s32 s15, s8 */
/* @0x1e4634 vldr s11, [r4, #40] */
/* @0x1e4638 rsb r3, r10, r7 */
/* @0x1e463c ldr r10, [sp, #0x94] */
/* @0x1e4640 vmov s5, r3 */
/* @0x1e4644 rsb r10, r10, r7 */
/* @0x1e4648 mov r3, r8 */
/* @0x1e464c vmov s12, r10 */
/* @0x1e4650 vcvt.f32.s32 s14, s5 */
/* @0x1e4654 vmla.f32 s15, s16, s14 */
/* @0x1e4658 vcvt.s32.f32 s15, s15 */
/* @0x1e465c vmov r2, s15 */
/* @0x1e4660 vcvt.f32.s32 s14, s11 */
/* @0x1e4664 cmp r2, #0 */
/* @0x1e4668 blt 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e466c ldr r1, [r4, #0x1c] */
/* @0x1e4670 cmp r1, r2 */
/* @0x1e4674 ble 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e4678 rsb r10, r9, r3 */
/* @0x1e467c vmov.f32 s5, s14 */
/* @0x1e4680 vmov s15, r10 */
/* @0x1e4684 vcvt.f32.s32 s15, s15 */
/* @0x1e4688 vmla.f32 s5, s15, s18 */
/* @0x1e468c vcvt.s32.f32 s15, s5 */
/* @0x1e4690 vmov r0, s15 */
/* @0x1e4694 cmp r0, #0 */
/* @0x1e4698 blt 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e469c ldr r10, [r4, #0x20] */
/* @0x1e46a0 cmp r0, r10 */
/* @0x1e46a4 bge 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e46a8 ldrb r10, [r4, #0x31] */
/* @0x1e46ac cmp r10, #0 */
/* @0x1e46b0 beq 0x1e46d0 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x438> */
/* @0x1e46b4 ldr r10, [r4, #0x40] */
/* @0x1e46b8 add r10, r10, r12 */
/* @0x1e46bc ldr r10, [r10, #0x4] */
/* @0x1e46c0 mla r1, r1, r0, r10 */
/* @0x1e46c4 ldrb r1, [r1, r2] */
/* @0x1e46c8 cmp r1, #0 */
/* @0x1e46cc beq 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e46d0 vcvt.f32.s32 s13, s12 */
/* @0x1e46d4 vldr s8, [r6, #36] */
/* @0x1e46d8 ldr r10, [r6, #0x28] */
/* @0x1e46dc vcvt.f32.s32 s15, s8 */
/* @0x1e46e0 vmla.f32 s15, s13, s20 */
/* @0x1e46e4 vcvt.s32.f32 s15, s15 */
/* @0x1e46e8 vmov r1, s15 */
/* @0x1e46ec cmp r1, #0 */
/* @0x1e46f0 blt 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e46f4 ldr r0, [r6, #0x1c] */
/* @0x1e46f8 cmp r1, r0 */
/* @0x1e46fc bge 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e4700 ldr r11, [sp, #0x10] */
/* @0x1e4704 vmov s5, r10 */
/* @0x1e4708 rsb r11, r11, r3 */
/* @0x1e470c vcvt.f32.s32 s13, s5 */
/* @0x1e4710 vmov s11, r11 */
/* @0x1e4714 vcvt.f32.s32 s11, s11 */
/* @0x1e4718 vmla.f32 s13, s11, s21 */
/* @0x1e471c vcvt.s32.f32 s13, s13 */
/* @0x1e4720 vmov r10, s13 */
/* @0x1e4724 vstr s13, [sp, #8] */
/* @0x1e4728 cmp r10, #0 */
/* @0x1e472c blt 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e4730 ldr r11, [r6, #0x20] */
/* @0x1e4734 cmp r10, r11 */
/* @0x1e4738 bge 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e473c ldrb r11, [r6, #0x31] */
/* @0x1e4740 cmp r11, #0 */
/* @0x1e4744 beq 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4748 ldr r10, [sp, #0x24] */
/* @0x1e474c ldr r11, [r6, #0x40] */
/* @0x1e4750 add r11, r11, r10 */
/* @0x1e4754 vmov r10, s13 */
/* @0x1e4758 str r11, [sp, #0x4] */
/* @0x1e475c ldr r11, [r11, #0x4] */
/* @0x1e4760 mla r0, r0, r10, r11 */
/* @0x1e4764 ldrb r1, [r0, r1] */
/* @0x1e4768 cmp r1, #0 */
/* @0x1e476c bne 0x1e4a0c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x774> */
/* @0x1e4770 add r3, r3, #1 */
/* @0x1e4774 cmp r5, r3 */
/* @0x1e4778 bge 0x1e4664 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x3cc> */
/* @0x1e477c ldr r1, [sp, #0x18] */
/* @0x1e4780 add r7, r7, #1 */
/* @0x1e4784 cmp r7, r1 */
/* @0x1e4788 ble 0x1e4620 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x388> */
/* @0x1e478c b 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* ── Push(6, 3)：类别 6 / 编号 3（Draw 用 6/15、DrawSimple 6/16，同族不同号）───
 * 1e4790 取 g_Profiler 槽、1e47a0 bl Push；随后 b 1e42e4 回到主流程。 */
/* @0x1e4790 ldr r3, [pc, #0x294] */
/* @0x1e4794 mov r1, #6 */
/* @0x1e4798 mov r2, #3 */
/* @0x1e479c ldr r0, [r7, r3] */
/* @0x1e47a0 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1e47a4 b 0x1e42e4 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4c> */
/* ── 旋转路径：把角度换成弧度再 sinf/cosf ───────────────────────────────────
 * 池字 1e4a1c = 0x40490fdb = π、1e4a20 = 0x43340000 = 180.0（两个常量只在这里用）。
 * 1e47b0 vnmul s15 = -(rotA * π)；1e47b8 vdiv /180；1e47c0 sinf → s17；
 * 1e47c8/1e47d4 再算 +rotA*π/180 → cosf → s19；rotB 同样一套 → s22(sin)、s7(cos)。
 * ⇒ 半径 2 的旋转矩阵四元素全部现算，每像素只做 4 次 vmla/vnmls 的逆变换。 */
/* @0x1e47a8 vldr s13, [sp, #132] */
/* @0x1e47ac vldr s24, [pc, #616] */
/* @0x1e47b0 vnmul.f32 s15, s13, s24 */
/* @0x1e47b4 vldr s23, [pc, #612] */
/* @0x1e47b8 vdiv.f32 s15, s15, s23 */
/* @0x1e47bc vmov r0, s15 */
/* @0x1e47c0 bl 0xb6580 <sinf@plt> */
/* @0x1e47c4 vldr s14, [sp, #132] */
/* @0x1e47c8 vmul.f32 s15, s14, s24 */
/* @0x1e47cc vdiv.f32 s15, s15, s23 */
/* @0x1e47d0 vmov s17, r0 */
/* @0x1e47d4 vmov r0, s15 */
/* @0x1e47d8 bl 0xb658c <cosf@plt> */
/* @0x1e47dc vldr s5, [sp, #164] */
/* @0x1e47e0 vnmul.f32 s15, s5, s24 */
/* @0x1e47e4 vdiv.f32 s15, s15, s23 */
/* @0x1e47e8 vmov s19, r0 */
/* @0x1e47ec vmov r0, s15 */
/* @0x1e47f0 bl 0xb6580 <sinf@plt> */
/* @0x1e47f4 vldr s8, [sp, #164] */
/* @0x1e47f8 vmul.f32 s24, s8, s24 */
/* @0x1e47fc vdiv.f32 s24, s24, s23 */
/* @0x1e4800 vmov s22, r0 */
/* @0x1e4804 vmov r0, s24 */
/* @0x1e4808 bl 0xb658c <cosf@plt> */
/* @0x1e480c ldr r1, [sp, #0x18] */
/* @0x1e4810 cmp r1, r7 */
/* @0x1e4814 vmov s7, r0 */
/* @0x1e4818 blt 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e481c ldr r3, [sp, #0x8c] */
/* @0x1e4820 lsl r10, r10, #3 */
/* @0x1e4824 ldr r12, [sp, #0x94] */
/* @0x1e4828 lsl r0, r3, #3 */
/* @0x1e482c str r0, [sp, #0x10] */
/* @0x1e4830 cmp r8, r5 */
/* @0x1e4834 bgt 0x1e49e8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x750> */
/* ── 旋转路径：A 侧逆旋转+逆缩放（逐像素），公式可从指令直接读回 ──────────────
 * 记住 s17 = sin(-rotA_rad) = -sinθ（1e47b0 的 vnmul 先取负）、s19 = cosθ。
 * 1e4848 dx = x - xA（r3）、1e4870 dy = y - yA（r0），各 vcvt 成 s9/s14。
 * 列：1e4864 s11 = cosθ*dx；1e4868 s9 = (-sinθ)*dx；1e4880 vmla s15 = cosθ*dx + (-sinθ)*dy；
 *     1e4888 vmla s5 = originX + s15/sxA ⇒ col = originX + (cosθ*dx - sinθ*dy)/sxA
 * 行：1e48b4 s13 = -sinθ*dx；1e48b8 vnmls s13 = (-sinθ*dx) - cosθ*dy；
 *     1e48c0 vmla s5 = originY + s13/syA ⇒ row = originY - (sinθ*dx + cosθ*dy)/syA
 * 界闸：列 0..width-1（1e488c/1e48b0）、行 0..height-1（1e48cc/1e48e0），与另两条路径同口径。
 * 1e48e4..1e4918 A 掩码读；1e491c..1e49d0 B 侧同构（s22 = -sinφ、s7 = cosφ）。
 * ⇒ 三条路径的掩码索引完全相同（row*width+col + 越界跳过），只是局部坐标来源不同。 */
/* @0x1e4838 ldr r2, [sp, #0xc] */
/* @0x1e483c vldr s8, [r4, #36] */
/* @0x1e4840 vldr s13, [r4, #40] */
/* @0x1e4844 vcvt.f32.s32 s12, s8 */
/* @0x1e4848 rsb r3, r2, r7 */
/* @0x1e484c rsb r0, r12, r7 */
/* @0x1e4850 str r1, [sp, #0x4] */
/* @0x1e4854 vmov s5, r3 */
/* @0x1e4858 mov r3, r8 */
/* @0x1e485c vmov s6, r0 */
/* @0x1e4860 vcvt.f32.s32 s9, s5 */
/* @0x1e4864 vmul.f32 s11, s19, s9 */
/* @0x1e4868 vmul.f32 s9, s17, s9 */
/* @0x1e486c vcvt.f32.s32 s10, s13 */
/* @0x1e4870 rsb r0, r9, r3 */
/* @0x1e4874 vmov s14, r0 */
/* @0x1e4878 vcvt.f32.s32 s14, s14 */
/* @0x1e487c vmov.f32 s15, s11 */
/* @0x1e4880 vmla.f32 s15, s14, s17 */
/* @0x1e4884 vmov.f32 s5, s12 */
/* @0x1e4888 vmla.f32 s5, s15, s16 */
/* @0x1e488c vcmpe.f32 s5, #0 */
/* @0x1e4890 vmov.f32 s15, s5 */
/* @0x1e4894 vmrs APSR_nzcv, fpscr */
/* @0x1e4898 bmi 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e489c ldr r2, [r4, #0x1c] */
/* @0x1e48a0 vmov s8, r2 */
/* @0x1e48a4 vcvt.f32.s32 s13, s8 */
/* @0x1e48a8 vcmpe.f32 s5, s13 */
/* @0x1e48ac vmrs APSR_nzcv, fpscr */
/* @0x1e48b0 bge 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e48b4 vmov.f32 s13, s9 */
/* @0x1e48b8 vnmls.f32 s13, s19, s14 */
/* @0x1e48bc vmov.f32 s5, s10 */
/* @0x1e48c0 vmla.f32 s5, s13, s18 */
/* @0x1e48c4 vcmpe.f32 s5, #0 */
/* @0x1e48c8 vmrs APSR_nzcv, fpscr */
/* @0x1e48cc bmi 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e48d0 vldr s8, [r4, #32] */
/* @0x1e48d4 vcvt.f32.s32 s13, s8 */
/* @0x1e48d8 vcmpe.f32 s5, s13 */
/* @0x1e48dc vmrs APSR_nzcv, fpscr */
/* @0x1e48e0 bge 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e48e4 ldrb r0, [r4, #0x31] */
/* @0x1e48e8 cmp r0, #0 */
/* @0x1e48ec beq 0x1e491c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x684> */
/* @0x1e48f0 vcvt.s32.f32 s14, s5 */
/* @0x1e48f4 ldr r0, [r4, #0x40] */
/* @0x1e48f8 add r0, r0, r10 */
/* @0x1e48fc ldr r0, [r0, #0x4] */
/* @0x1e4900 vmov r1, s14 */
/* @0x1e4904 vcvt.s32.f32 s15, s15 */
/* @0x1e4908 mla r2, r1, r2, r0 */
/* @0x1e490c vmov r0, s15 */
/* @0x1e4910 ldrb r2, [r2, r0] */
/* @0x1e4914 cmp r2, #0 */
/* @0x1e4918 beq 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e491c rsb r1, r11, r3 */
/* @0x1e4920 vcvt.f32.s32 s8, s6 */
/* @0x1e4924 vldr s5, [r6, #36] */
/* @0x1e4928 ldr r0, [r6, #0x28] */
/* @0x1e492c vmov s13, r1 */
/* @0x1e4930 vcvt.f32.s32 s13, s13 */
/* @0x1e4934 vmul.f32 s14, s13, s22 */
/* @0x1e4938 vmla.f32 s14, s8, s7 */
/* @0x1e493c vcvt.f32.s32 s15, s5 */
/* @0x1e4940 vmla.f32 s15, s14, s20 */
/* @0x1e4944 vcmpe.f32 s15, #0 */
/* @0x1e4948 vmrs APSR_nzcv, fpscr */
/* @0x1e494c bmi 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e4950 ldr r2, [r6, #0x1c] */
/* @0x1e4954 vmov s5, r2 */
/* @0x1e4958 vcvt.f32.s32 s14, s5 */
/* @0x1e495c vcmpe.f32 s15, s14 */
/* @0x1e4960 vmrs APSR_nzcv, fpscr */
/* @0x1e4964 bge 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e4968 vmul.f32 s8, s22, s8 */
/* @0x1e496c vnmls.f32 s8, s7, s13 */
/* @0x1e4970 vmov s13, r0 */
/* @0x1e4974 vcvt.f32.s32 s14, s13 */
/* @0x1e4978 vmla.f32 s14, s8, s21 */
/* @0x1e497c vcmpe.f32 s14, #0 */
/* @0x1e4980 vmrs APSR_nzcv, fpscr */
/* @0x1e4984 bmi 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e4988 vldr s5, [r6, #32] */
/* @0x1e498c vcvt.f32.s32 s13, s5 */
/* @0x1e4990 vcmpe.f32 s14, s13 */
/* @0x1e4994 vmrs APSR_nzcv, fpscr */
/* @0x1e4998 bge 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e499c ldrb r0, [r6, #0x31] */
/* @0x1e49a0 cmp r0, #0 */
/* @0x1e49a4 beq 0x1e4a00 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x768> */
/* @0x1e49a8 vcvt.s32.f32 s14, s14 */
/* @0x1e49ac ldr r1, [sp, #0x10] */
/* @0x1e49b0 ldr r0, [r6, #0x40] */
/* @0x1e49b4 add r0, r0, r1 */
/* @0x1e49b8 ldr r0, [r0, #0x4] */
/* @0x1e49bc vmov r1, s14 */
/* @0x1e49c0 vcvt.s32.f32 s15, s15 */
/* @0x1e49c4 mla r2, r1, r2, r0 */
/* @0x1e49c8 vmov r0, s15 */
/* @0x1e49cc ldrb r2, [r2, r0] */
/* @0x1e49d0 cmp r2, #0 */
/* @0x1e49d4 bne 0x1e49f8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x760> */
/* @0x1e49d8 add r3, r3, #1 */
/* @0x1e49dc cmp r5, r3 */
/* @0x1e49e0 bge 0x1e4870 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x5d8> */
/* @0x1e49e4 ldr r1, [sp, #0x4] */
/* @0x1e49e8 add r7, r7, #1 */
/* @0x1e49ec cmp r7, r1 */
/* @0x1e49f0 ble 0x1e4830 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x598> */
/* @0x1e49f4 b 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* ── 三个命中口 ─────────────────────────────────────────────────────────────
 * 1e49f8/1e4a0c：把该侧掩码字节（=1）写进 [sp+0x14]；
 * 1e4a00：B 侧无掩码（+0x31==0）⇒ 直接写 1；
 * 1e4a0c/1e4a14：A/B 掩码都非 0 ⇒ 写 1。
 * 之后统一 b 1e459c（Pop + 返回 [sp+0x14]），没有任何路径返回非 0/1 的值。 */

/* ── literal pool 4 字（非指令）────────────────────────────────────────────
 * 1e4a1c = π、1e4a20 = 180.0、1e4a24/1e4a28/1e4a2c = GOT 基址与两个槽偏移（见段首）。 */
/* @0x1e49f8 str r2, [sp, #0x14] */
/* @0x1e49fc b 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4a00 mov r2, #1 */
/* @0x1e4a04 str r2, [sp, #0x14] */
/* @0x1e4a08 b 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4a0c str r1, [sp, #0x14] */
/* @0x1e4a10 b 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4a14 str r12, [sp, #0x14] */
/* @0x1e4a18 b 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4a1c ldrdmi r0, r1, [r9], #-251 */
/* @0x1e4a20 teqmi r4, #0 */
/* @0x1e4a24 mlaeq r0, r12, r9, sp */
/* @0x1e4a28 .word 0xffffbf18 */
/* @0x1e4a2c .word 0xffffbf1c */
/* ── 段 C · Sprite_Init 0x1eebbc —— 把精灵表整个拆掉，再重建空的哈希表 ───────
 *  签名 _Z11Sprite_Initv → void Sprite_Init()
 *  帧 40（push {r4-r10,lr}），无栈形参；GOT 基址 0x3f1c58（r9 = pc + 0x203088）。
 *  三个全局的地址一次算好：r7 = &g_SpriteItems(0x7530d0)、r8 = &g_NumberOfSprites(0x7530d8)、
 *  r10 = &g_SpriteNames(0x7530dc)。
 *  两段：
 *    ① 拆：items 非空时，对每个 i<count 调 items[i] 的删除析构（vptr[1]）、把 items[i] 与
 *       names[i] 置 0 并 Free(names[i])；然后 Free(items)、Free(names)，count = 0、两个指针清 0。
 *       ⚠ items 为空时**整段跳过**（包括 Free(names)）⇒ 名字表只在 items 非空时才被回收。
 *    ② 建：按 g_spriteLookup.size（+0）重建空表：Free 旧表 → mask = size-1 →
 *       Alloc(size*12, MemoryManager.h:70, true) → memset 0 → used(+4) = 0 →
 *       thr(+0xc) = (int)(size*0.6f)（池字 0x3f19999a，1eed20）→ 逐桶把 +8(hash) 清 0。
 *  ⚠ 第 ② 段的 size 来自 g_spriteLookup 自身（1eec90 ldr r0,[r4]），本函数**不写** +0
 *    ⇒ "名字总数"由别处（Sprite_Add/AddEmpty）设定；精灵表被清空后 size 保留、内容全空。
 */

/* @0x1eebbc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* ── GOT 基址 + 三个全局地址 ─────────────────────────────────────────────────
 * 1eebc0/1eebc4 两个池字（1eed24 = 0x203088 是基址偏移，1eed28/1eed2c/1eed30 是负偏移）：
 *   0xfffff1b8 = -0xE48 → 0x3f0e10 g_SpriteItems
 *   0xfffff1c0 = -0xE40 → 0x3f0e18 g_NumberOfSprites
 *   0xfffff1bc = -0xE44 → 0x3f0e14 g_SpriteNames
 * 三个槽都 R_ARM_RELATIVE；名字取自 .dynsym（不是推断）。 */
/* @0x1eebc0 ldr r9, [pc, #0x15c] */
/* @0x1eebc4 ldr r3, [pc, #0x15c] */
/* @0x1eebc8 add r9, pc, r9 */
/* @0x1eebcc ldr r7, [r9, r3] */
/* ── ① 拆表入口：items(+4) 为 0 就整段跳过，直接去 1eec78 重建哈希表 ──────────
 * 1eebd4 cmp r0,#0 / 1e3... 1eebd8 beq 1eec78。
 * 注意跳过的代价：names 数组不会被释放（只有 items 非空才走到 1eec6c）。 */
/* @0x1eebd0 ldr r0, [r7, #0x4] */
/* @0x1eebd4 cmp r0, #0 */
/* @0x1eebd8 beq 0x1eec78 <_Z11Sprite_Initv+0xbc> */
/* @0x1eebdc ldr r3, [pc, #0x148] */
/* @0x1eebe0 ldr r8, [r9, r3] */
/* ── count 与 names 的取址；count<=0 时用谓词指令补一条 ldrle ────────────────
 * 1eebe4 r3 = [r8] = count；1eebec 取 g_SpriteNames 槽；
 * 1eebf0 ldrle r10,[r9,r3] + 1eebf4 ble 1eec5c ⇒ count<=0 时 r10 也已被填好，
 * 直接进"只释放两个数组"的收尾。 */
/* @0x1eebe4 ldr r3, [r8] */
/* @0x1eebe8 cmp r3, #0 */
/* @0x1eebec ldr r3, [pc, #0x13c] */
/* @0x1eebf0 ldrle r10, [r9, r3] */
/* @0x1eebf4 ble 0x1eec5c <_Z11Sprite_Initv+0xa0> */
/* @0x1eebf8 ldr r10, [r9, r3] */
/* @0x1eebfc mov r4, #0 */
/* ── ① 循环体：销毁每个 CSprite ─────────────────────────────────────────────
 * 1eec00 r6 = 0（哨兵）、1eec04 r3 = items[i]、1eec08 r5 = i*4、1eec0c r2 = &items[i]、
 * 1eec10 i++、1eec14/1eec18 非空则 r0 = 该对象；
 * 1eec20 r3 = [obj] = vptr、1eec24 r3 = [vptr+4] = **D0（删除析构）**、1eec28 blx r3。
 * 证据：_ZTV7CSprite(0x3ebe60) = [0, typeinfo 0x3ebe58, D1 0x1e76a4, D0 0x1e76cc]，
 * 对象 vptr 指向 0x3ebe68 ⇒ vptr[0]=D1、vptr[1]=D0。所以这条间接调用是 delete 精灵，
 * 对象释放由 D0 自己做，本函数只负责把槽清掉。 */
/* @0x1eec00 mov r6, r4 */
/* @0x1eec04 ldr r3, [r0, r4, lsl #2] */
/* @0x1eec08 lsl r5, r4, #2 */
/* @0x1eec0c add r2, r0, r5 */
/* @0x1eec10 add r4, r4, #1 */
/* @0x1eec14 cmp r3, #0 */
/* @0x1eec18 mov r0, r3 */
/* @0x1eec1c beq 0x1eec34 <_Z11Sprite_Initv+0x78> */
/* @0x1eec20 ldr r3, [r3] */
/* @0x1eec24 ldr r3, [r3, #0x4] */
/* @0x1eec28 blx r3 */
/* ── 销毁后回填：items[i] = 0、Free(names[i])、names[i] = 0 ──────────────────
 * 1eec2c/1eec30 重新取 items+i*4（虚拟调用后重载，防止别名）；
 * 1eec38 r3 = [r10] = names 数组；1eec3c r0 = names[i]；1eec40 MemoryManager::Free；
 * 1eec50 str 0 → names[i]。
 * 顺序上先清 items 再 Free 名字，最后 names[i]=0（Free 之后再用 r5 索引，说明 r5 是 i*4 缓存）。 */
/* @0x1eec2c ldr r2, [r7, #0x4] */
/* @0x1eec30 add r2, r2, r5 */
/* @0x1eec34 str r6, [r2] */
/* @0x1eec38 ldr r3, [r10] */
/* @0x1eec3c ldr r0, [r3, r5] */
/* @0x1eec40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eec44 ldr r2, [r8] */
/* @0x1eec48 ldr r3, [r10] */
/* @0x1eec4c cmp r2, r4 */
/* @0x1eec50 str r6, [r3, r5] */
/* @0x1eec54 ldr r0, [r7, #0x4] */
/* @0x1eec58 bgt 0x1eec04 <_Z11Sprite_Initv+0x48> */
/* ── ① 收尾：Free(items)、Free(names)，count/items/names 全清 ────────────────
 * 1eec5c bl Free(r0=items)（r0 来自 1eebd0 或 1eec54 的重载）；
 * 1eec60 r0 = [r10] = names；1eec68 items = 0；1eec6c bl Free(names)；
 * 1eec70 count = 0；1eec74 names = 0。
 * ⇒ 与段 D（Sprite_Free）的差别就在这两条 names 处理：Free 不管名字表。 */
/* @0x1eec5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eec60 ldr r0, [r10] */
/* @0x1eec64 mov r4, #0 */
/* @0x1eec68 str r4, [r7, #0x4] */
/* @0x1eec6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eec70 str r4, [r8] */
/* @0x1eec74 str r4, [r10] */
/* ── ② 重建哈希表：先 Free 旧 tab(+0x10) ────────────────────────────────────
 * r4 = &g_spriteLookup（0x7530e0，20 B）。1eec80 r0 = [r4+0x10]；非 0 才 Free。
 * 注意 1eec90 的 ldr r0,[r4] 读的是 +0 = size（下面用它算 mask/长度/阈值）。 */
/* @0x1eec78 ldr r3, [pc, #0xb4] */
/* @0x1eec7c ldr r4, [r9, r3] */
/* @0x1eec80 ldr r0, [r4, #0x10] */
/* @0x1eec84 cmp r0, #0 */
/* @0x1eec88 beq 0x1eec90 <_Z11Sprite_Initv+0xd4> */
/* @0x1eec8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* ── ② 关键 8 条：size → mask、12*size、Alloc、memset、used=0、thr=0.6*size ───
 * 1eeca0 r12 = size-1；1eeca8 r0 = size*3；1eecb4 r6 = size*12；1eecb8 mask(+8) = size-1；
 * 1eecc0 Alloc(12*size, "…/Platform/MemoryManager.h", 70, true)；1eecc8 r1 = 0；1eeccc tab(+0x10) = 新块；
 * 1eecd0 memset(tab, 0, 12*size)；1eecdc used(+4) = 0；
 * 1eece4..1eecf0 s15 = (float)size * 0.6；1eecf4 vcvt.s32 → 存成 int 到 thr(+0xc)。
 * ⇒ 0.6 是扩容阈值（负载因子），存的是**条目数**而不是比例；size 必须是 2 的幂
 *    才能让 mask=size-1 成立（这一点本函数不校验，属调用方契约）。 */
/* @0x1eec90 ldr r0, [r4] */
/* @0x1eec94 mov r5, #0 */
/* @0x1eec98 ldr r1, [pc, #0x98] */
/* @0x1eec9c mov r2, #70 */
/* @0x1eeca0 sub r12, r0, #1 */
/* @0x1eeca4 mov r3, #1 */
/* @0x1eeca8 add r0, r0, r0, lsl #1 */
/* @0x1eecac add r1, pc, r1 */
/* @0x1eecb0 str r5, [r4, #0x10] */
/* @0x1eecb4 lsl r6, r0, #2 */
/* @0x1eecb8 str r12, [r4, #0x8] */
/* @0x1eecbc mov r0, r6 */
/* @0x1eecc0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1eecc4 mov r2, r6 */
/* @0x1eecc8 mov r1, r5 */
/* @0x1eeccc str r0, [r4, #0x10] */
/* @0x1eecd0 bl 0xb65b0 <memset@plt> */
/* @0x1eecd4 ldr r2, [r4] */
/* @0x1eecd8 vldr s15, [pc, #64] */
/* @0x1eecdc str r5, [r4, #0x4] */
/* @0x1eece0 cmp r2, r5 */
/* @0x1eece4 vmov s13, r2 */
/* @0x1eece8 vcvt.f32.s32 s14, s13 */
/* @0x1eecec vmul.f32 s15, s14, s15 */
/* @0x1eecf0 vcvt.s32.f32 s15, s15 */
/* @0x1eecf4 vstr s15, [r4, #12] */
/* ── ② size==0 直接返回；否则逐桶把 +8(hash) 清 0 ───────────────────────────
 * 1eecfc r3 = tab；1eed00/1eed08 上界 = tab + 12*size；1eed0c str 0,[r3,#8]；r3 += 12。
 * memset 已经把整块清 0，这里再写一遍 +8 —— 说明桶的"空"判据就是 hash == 0（段 J 对账）。 */
/* @0x1eecf8 pople {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1eecfc ldr r3, [r4, #0x10] */
/* @0x1eed00 add r2, r2, r2, lsl #1 */
/* @0x1eed04 mov r1, r5 */
/* @0x1eed08 add r2, r3, r2, lsl #2 */
/* @0x1eed0c str r1, [r3, #0x8] */
/* @0x1eed10 add r3, r3, #12 */
/* @0x1eed14 cmp r3, r2 */
/* @0x1eed18 bne 0x1eed0c <_Z11Sprite_Initv+0x150> */
/* @0x1eed1c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1eed20 svclo #0x19999a */
/* @0x1eed24 eoreq r3, r0, r8, lsl #1 */
/* @0x1eed28 .word 0xfffff1b8 */
/* @0x1eed2c .word 0xfffff1c0 */
/* @0x1eed30 .word 0xfffff1bc */
/* @0x1eed34 .word 0xfffff1c4 */
/* @0x1eed38 andseq r2, r4, r4, lsl #7 */
/* ── 段 D · Sprite_Free 0x1eed3c —— 只拆精灵对象与 items 数组，不动名字表 ─────
 *  签名 _Z11Sprite_Freev → void Sprite_Free()
 *  帧 16（push {r4-r6,lr}）；GOT 基址 0x3f1c58；r5 = &g_NumberOfSprites、r6 = &g_SpriteItems。
 *  与段 C 的差异（本卡最重要的一条非对称）：
 *    - 只 Free(items)（+4），**不 Free g_SpriteNames**；
 *    - 额外把 g_SpriteItems+0 清 0（1eedb0），段 C 不动这个字段。
 *  count<=0 时仍然会走到 1eedb8→1eed9c 的释放段（不跳过），只是不跑销毁循环。
 */

/* ── 取址：1eed3c/1eed40 两个池字（1eedc4 = 0x202f0c 基址偏移、1eedc8 = -0xE40）───
 * 1eed44 add r3,pc → 0x3f1c58；1eed4c r5 = 0x3f0e18 = &g_NumberOfSprites；
 * 1eed58 取 -0xE48 → 1eed60 r6 = 0x3f0e10 = &g_SpriteItems。
 * 注意 push 在 1eed48 才做（前三条指令在帧外，不写栈）。 */
/* @0x1eed3c ldr r3, [pc, #0x80] */
/* @0x1eed40 ldr r2, [pc, #0x80] */
/* @0x1eed44 add r3, pc, r3 */
/* @0x1eed48 push {r4, r5, r6, lr} */
/* @0x1eed4c ldr r5, [r3, r2] */
/* ── count = [r5]；<=0 → 1eedb8（跳过循环但**照样**释放 items）────────────────
 * 1eedb8/1eedbc 重新取 items 到 r2，1eedc0 b 1eed9c。 */
/* @0x1eed50 ldr r2, [r5] */
/* @0x1eed54 cmp r2, #0 */
/* @0x1eed58 ldr r2, [pc, #0x6c] */
/* @0x1eed5c ble 0x1eedb8 <_Z11Sprite_Freev+0x7c> */
/* @0x1eed60 ldr r6, [r3, r2] */
/* @0x1eed64 mov r4, #0 */
/* ── 销毁循环：与段 C 同一手法（vptr[1] = D0）────────────────────────────────
 * 1eed6c r3 = items[i]；1eed78 r0 = 对象；1eed80 vptr、1eed84 [vptr+4]、1eed88 blx；
 * 1eed8c 重载 items；1eed90..1eed98 i++ 与 count 比较。
 * 与段 C 不同：这里**不**清 items[i]、也不碰 names —— 清空交给数组整体释放。 */
/* @0x1eed68 ldr r2, [r6, #0x4] */
/* @0x1eed6c ldr r3, [r2, r4, lsl #2] */
/* @0x1eed70 add r4, r4, #1 */
/* @0x1eed74 cmp r3, #0 */
/* @0x1eed78 mov r0, r3 */
/* @0x1eed7c beq 0x1eed90 <_Z11Sprite_Freev+0x54> */
/* @0x1eed80 ldr r3, [r3] */
/* @0x1eed84 ldr r3, [r3, #0x4] */
/* @0x1eed88 blx r3 */
/* @0x1eed8c ldr r2, [r6, #0x4] */
/* @0x1eed90 ldr r3, [r5] */
/* @0x1eed94 cmp r3, r4 */
/* @0x1eed98 bgt 0x1eed6c <_Z11Sprite_Freev+0x30> */
/* ── 收尾：Free(items) → count=0 → items=0 → g_SpriteItems+0=0 ────────────────
 * 1eed9c r0 = items；1eeda4 count = 0；1eeda8 MemoryManager::Free；
 * 1eedac [+4] = 0；1eedb0 [+0] = 0。
 * ⇒ 本函数是唯一写 g_SpriteItems+0 的地方（本组九函数里），且只写 0、从不读，
 *    该字段语义未证（见 open）。名字表与 g_spriteLookup 完全不动 ⇒ 调用后
 *    g_NumberOfSprites==0 但 g_SpriteNames 仍指向已分配的名字数组（悬挂/待复用的分界点）。 */
/* @0x1eed9c mov r0, r2 */
/* @0x1eeda0 mov r4, #0 */
/* @0x1eeda4 str r4, [r5] */
/* @0x1eeda8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eedac str r4, [r6, #0x4] */
/* @0x1eedb0 str r4, [r6] */
/* @0x1eedb4 pop {r4, r5, r6, pc} */
/* @0x1eedb8 ldr r6, [r3, r2] */
/* @0x1eedbc ldr r2, [r6, #0x4] */
/* @0x1eedc0 b 0x1eed9c <_Z11Sprite_Freev+0x60> */
/* @0x1eedc4 eoreq r2, r0, r12, lsl #30 */
/* @0x1eedc8 .word 0xfffff1c0 */
/* @0x1eedcc .word 0xfffff1b8 */
/* ── 段 E · Sprite_InitTextures 0x1eedd0 —— 给每个精灵重建纹理与本地 TPE ──────
 *  签名 _Z19Sprite_InitTexturesv → void Sprite_InitTextures()
 *  帧 16（push {r4-r6,lr}）；count = g_NumberOfSprites(0x7530d8)，表 = g_SpriteItems.items(0x7530d0+4)。
 *  对每个非空 CSprite 依次调 InitTexture(1e5748) 与 InitLocalTPE(1e5854)：
 *    InitTexture  : 先 FreeTexture，再按 this+0x18(image_number) 铺 this+0x50 的纹理句柄数组
 *                   （每项 = GR_Texture_Create_Direct(this+0x48[i])），this+0x4c = 条数；
 *                   this+0x34 非 0 时再对每个句柄 GR_Texture_Preload(1e57dc)。
 *    InitLocalTPE : 释放旧的 this+0x54 数组，按 this+0x44 重新 Alloc 指针数组 + 每项 malloc(22)，
 *                   用 this+0x48 的位图宽高与 this+0x50 的句柄填条目，最后 this+0x38 = 条数、+0x36 = 1。
 *  ⇒ "精灵表"在这里才真正挂上 GPU 纹理；掩码（段 A）随后才可能被建。
 *  ⚠ 两次调用之间 1eee08..1eee0c 重新装载 items[i]（虚拟/普通调用后重载，防别名）。
 */

/* @0x1eedd0 push {r4, r5, r6, lr} */
/* ── count 闸 + items 取址 ──────────────────────────────────────────────────
 * 1eedd4 池字 1eee28 = 0x202038，1eedd8 [pc,r6] → pc 1eede0 + 0x202038 = 0x3f0e18；
 * 1eeddc r3 = count；1eede4 pople（==0 则整函数直接返回）。
 * 1eede8 池字 1eee2c = 0x202018 → 1eedf0 [pc,r5] → pc 1eedf8 + 0x202018 = 0x3f0e10。 */
/* @0x1eedd4 ldr r6, [pc, #0x4c] */
/* @0x1eedd8 ldr r6, [pc, r6] */
/* @0x1eeddc ldr r3, [r6] */
/* @0x1eede0 cmp r3, #0 */
/* @0x1eede4 pople {r4, r5, r6, pc} */
/* @0x1eede8 ldr r5, [pc, #0x3c] */
/* @0x1eedec mov r4, #0 */
/* @0x1eedf0 ldr r5, [pc, r5] */
/* ── 循环体：items[i] → InitTexture → 重载 → InitLocalTPE ────────────────────
 * 1eedf4 r3 = [r5+4] = items；1eedf8 r0 = items[i]；为空跳过（1eee14）；
 * 1eee04 bl 1e5748（InitTexture）；1eee08 重载 items；1eee10 bl 1e5854（InitLocalTPE）。
 * 1eee14 重载 count、i++、1eee20 bgt 回循环头 ⇒ 用的是每次重读的 count（可在循环中被改）。 */
/* @0x1eedf4 ldr r3, [r5, #0x4] */
/* @0x1eedf8 ldr r0, [r3, r4, lsl #2] */
/* @0x1eedfc cmp r0, #0 */
/* @0x1eee00 beq 0x1eee14 <_Z19Sprite_InitTexturesv+0x44> */
/* @0x1eee04 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1eee08 ldr r3, [r5, #0x4] */
/* @0x1eee0c ldr r0, [r3, r4, lsl #2] */
/* @0x1eee10 bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1eee14 ldr r3, [r6] */
/* @0x1eee18 add r4, r4, #1 */
/* @0x1eee1c cmp r3, r4 */
/* @0x1eee20 bgt 0x1eedf4 <_Z19Sprite_InitTexturesv+0x24> */
/* @0x1eee24 pop {r4, r5, r6, pc} */
/* @0x1eee28 eoreq r2, r0, r8, lsr r0 */
/* @0x1eee2c eoreq r2, r0, r8, lsl r0 */
/* ── 段 F · Sprite_FreeTextures 0x1eee30 —— 只放纹理，不动掩码/TPE 数组 ──────
 *  签名 _Z19Sprite_FreeTexturesv → void Sprite_FreeTextures()
 *  帧 16；count = g_NumberOfSprites；对每个非空精灵调 FreeTexture(1e56fc)。
 *  FreeTexture 本体（0x1e56fc，76 B）只释放 this+0x50 的句柄数组并把 this+0x4c 清 0；
 *  this+0x54（本地 TPE）与 this+0x40（掩码）都不在这里释放 —— 它们分别由
 *  InitLocalTPE 自身与 FreeMask 管。
 */

/* @0x1eee30 push {r4, r5, r6, lr} */
/* ── count 闸 + items 取址 ──────────────────────────────────────────────────
 * 1eee34 池字 1eee7c = 0x201fd8 → 1eee38 [pc,r5] → 0x3f0e18；
 * 1eee48 池字 1eee80 = 0x201fb8 → 1eee50 [pc,r6] → 0x3f0e10。
 * 注意 1eee5c 先 i++ 再判空（与段 E 的次序相反，无副作用差异）。 */
/* @0x1eee34 ldr r5, [pc, #0x40] */
/* @0x1eee38 ldr r5, [pc, r5] */
/* @0x1eee3c ldr r3, [r5] */
/* @0x1eee40 cmp r3, #0 */
/* @0x1eee44 pople {r4, r5, r6, pc} */
/* @0x1eee48 ldr r6, [pc, #0x30] */
/* @0x1eee4c mov r4, #0 */
/* @0x1eee50 ldr r6, [pc, r6] */
/* @0x1eee54 ldr r3, [r6, #0x4] */
/* @0x1eee58 ldr r0, [r3, r4, lsl #2] */
/* @0x1eee5c add r4, r4, #1 */
/* @0x1eee60 cmp r0, #0 */
/* @0x1eee64 beq 0x1eee6c <_Z19Sprite_FreeTexturesv+0x3c> */
/* @0x1eee68 bl 0x1e56fc <_ZN7CSprite11FreeTextureEv> */
/* @0x1eee6c ldr r3, [r5] */
/* @0x1eee70 cmp r3, r4 */
/* @0x1eee74 bgt 0x1eee54 <_Z19Sprite_FreeTexturesv+0x24> */
/* @0x1eee78 pop {r4, r5, r6, pc} */
/* @0x1eee7c .word 0x00201fd8 */
/* @0x1eee80 .word 0x00201fb8 */
/* ── 段 G · Sprite_Number 0x1eee84 —— 精灵数 ─────────────────────────────────
 *  _Z13Sprite_Numberv → int Sprite_Number()   = *(int*)0x7530d8（g_NumberOfSprites）
 *  4 条真指令（2 条取址 + 1 条解引用 + 1 条 bx lr）+ 1 个池字；无分支、无帧、纯读。
 *  这是 sprite_get_number 的返回值来源（Sprite_Data 卡已从另一侧证过同一个 int）。
 */

/* ── 取址链：池字 1eee94 = 0x201f88，1eee88 [pc,r3] → pc 1eee90 + 0x201f88 = 0x3f0e18 ──
 * 1e8c ldr r0,[r3] 解引用一次得 count；1e90 bx lr。
 * ⚠ 没有判空：g_NumberOfSprites 是 .bss 里的 int 本身，不存在"指针为空"。 */
/* @0x1eee84 ldr r3, [pc, #0x8] */
/* @0x1eee88 ldr r3, [pc, r3] */
/* @0x1eee8c ldr r0, [r3] */
/* @0x1eee90 bx lr */
/* @0x1eee94 eoreq r1, r0, r8, lsl #31 */
/* ── 段 H · Sprite_Exists 0x1eee98 —— 边界 + 非空二合一 ──────────────────────
 *  _Z13Sprite_Existsi → int Sprite_Exists(int i)
 *  = (0 <= i < g_NumberOfSprites) ? (g_SpriteItems.items[i] != 0) : 0
 *  与 Sprite_Data 的差别只有最后一条：Data 直接返回指针，Exists 用 adds/movne 归一成 0/1。
 *  ⇒ sprite_exists 的语义就是"sprite_data(i) != NULL"；两者边界判据同构（各自一份 cmp/blt + cmp/bge
 *    模板，语义相同，不是共享代码）。
 */

/* ── 双向边界：i<0 → 0；i>=count → 0；否则读表判非空 ────────────────────────
 * 1e9c blt 1eeed0（mov r0,#0）；1eeea0..1eeeac 取 count（池字 1eeed8 = 0x201f6c → 0x3f0e18）；
 * 1eeeb4..1eeebc 取表（池字 1eeedc = 0x201f50 → 0x3f0e10，再 [r3+4]）；
 * 1eeec0 ldr r0,[r3, r0, lsl #2]；1eeec4 adds r0,r0,#0 置 Z；1eeec8 movne r0,#1。 */
/* @0x1eee98 cmp r0, #0 */
/* @0x1eee9c blt 0x1eeed0 <_Z13Sprite_Existsi+0x38> */
/* @0x1eeea0 ldr r3, [pc, #0x30] */
/* @0x1eeea4 ldr r3, [pc, r3] */
/* @0x1eeea8 ldr r3, [r3] */
/* @0x1eeeac cmp r0, r3 */
/* @0x1eeeb0 bge 0x1eeed0 <_Z13Sprite_Existsi+0x38> */
/* @0x1eeeb4 ldr r3, [pc, #0x20] */
/* @0x1eeeb8 ldr r3, [pc, r3] */
/* @0x1eeebc ldr r3, [r3, #0x4] */
/* @0x1eeec0 ldr r0, [r3, r0, lsl #2] */
/* @0x1eeec4 adds r0, r0, #0 */
/* @0x1eeec8 movne r0, #1 */
/* @0x1eeecc bx lr */
/* @0x1eeed0 mov r0, #0 */
/* @0x1eeed4 bx lr */
/* @0x1eeed8 eoreq r1, r0, r12, ror #30 */
/* @0x1eeedc eoreq r1, r0, r0, asr pc */
/* ── 段 I · Sprite_Name 0x1eeee0 —— 精灵号 → 名字字符串 ──────────────────────
 *  _Z11Sprite_Namei → char const* Sprite_Name(int i)
 *  三条失败路径（i<0、i>=count、items[i]==NULL）**全部**返回同一个常量 "<undefined>"
 *  （.rodata 0x330ac8，三个池字 0x141b94/0x141b88/0x141b7c + add pc 各算一次，落点相同）。
 *  数据源是 g_SpriteNames(0x7530dc) 再解引用一层：r3 = [0x7530dc]; r0 = [r3 + i*4]
 *  ⇒ 名字数组本身是 char**，与 g_SpriteItems 的 items 同类结构，但**没有**一个对象持有它。
 *  ⚠ names[i] 为 NULL 不检查：有效精灵没名字时返回 NULL，不是 "<undefined>"。
 */

/* @0x1eeee0 cmp r0, #0 */
/* @0x1eeee4 blt 0x1eef34 <_Z11Sprite_Namei+0x54> */
/* @0x1eeee8 ldr r3, [pc, #0x5c] */
/* @0x1eeeec ldr r3, [pc, r3] */
/* @0x1eeef0 ldr r3, [r3] */
/* @0x1eeef4 cmp r0, r3 */
/* @0x1eeef8 bge 0x1eef28 <_Z11Sprite_Namei+0x48> */
/* ── 取对象：先判 items[i] 是否为空（唯一的一层空判）────────────────────────
 * 1eeefc..1eef08：池字 1eef50 = 0x201f08 → 0x3f0e10（g_SpriteItems）→ [.+4] → items[i]；
 * 1eef0c/1eef10 为空 → 1eef40（第三条 "<undefined>" 出口）。 */
/* @0x1eeefc ldr r3, [pc, #0x4c] */
/* @0x1eef00 ldr r3, [pc, r3] */
/* @0x1eef04 ldr r3, [r3, #0x4] */
/* @0x1eef08 ldr r3, [r3, r0, lsl #2] */
/* @0x1eef0c cmp r3, #0 */
/* @0x1eef10 beq 0x1eef40 <_Z11Sprite_Namei+0x60> */
/* ── 取名字：g_SpriteNames 槽 → 名字数组 → names[i] ──────────────────────────
 * 1eef14 池字 1eef54 = 0x201ef4 → 1eef18 [pc,r3] → 0x3f0e14（g_SpriteNames，4 B 指针）；
 * 1eef1c ldr r3,[r3] = 名字数组；1eef20 ldr r0,[r3, r0, lsl #2]；1eef24 bx lr。 */
/* @0x1eef14 ldr r3, [pc, #0x38] */
/* @0x1eef18 ldr r3, [pc, r3] */
/* @0x1eef1c ldr r3, [r3] */
/* @0x1eef20 ldr r0, [r3, r0, lsl #2] */
/* @0x1eef24 bx lr */
/* ── 三个 "<undefined>" 出口：1eef28(i>=count)、1eef34(i<0)、1eef40(对象为空) ──
 * 三条都是 ldr r0,[pc,#imm] + add r0,pc,r0，池字分别 0x141b94 / 0x141b88 / 0x141b7c，
 * 目标全是 0x330ac8（只读一次即知是同一个 C 字符串）。 */
/* @0x1eef28 ldr r0, [pc, #0x28] */
/* @0x1eef2c add r0, pc, r0 */
/* @0x1eef30 bx lr */
/* @0x1eef34 ldr r0, [pc, #0x20] */
/* @0x1eef38 add r0, pc, r0 */
/* @0x1eef3c bx lr */
/* @0x1eef40 ldr r0, [pc, #0x18] */
/* @0x1eef44 add r0, pc, r0 */
/* @0x1eef48 bx lr */
/* @0x1eef4c eoreq r1, r0, r4, lsr #30 */
/* @0x1eef50 eoreq r1, r0, r8, lsl #30 */
/* @0x1eef54 .word 0x00201ef4 */
/* @0x1eef58 mulseq r4, r4, r11 */
/* @0x1eef5c andseq r1, r4, r8, lsl #23 */
/* @0x1eef60 andseq r1, r4, r12, ror r11 */
/* ── 段 J · Sprite_Find 0x1eef64 —— 名字 → 精灵号（哈希表）────────────────────
 *  _Z11Sprite_FindPKc → int Sprite_Find(char const* name)；未命中返回 -1。
 *
 *  表布局（本段逐条对账，配合段 C 的 size/mask/thr 写入）：
 *    g_spriteLookup @0x7530e0（20 B）
 *      +0x00 int size    桶数（也是 Robin-Hood 距离公式里的模数；Sprite_Init 用它算 mask 与 12*size）
 *      +0x04 int used    已用条目（Sprite_Init 清 0，本函数不读不写）
 *      +0x08 u32 mask    size-1
 *      +0x0c int thr     (int)(size*0.6) 扩容阈值
 *      +0x10 Bucket* tab 桶数组，12 B/桶
 *    Bucket = { ?@0x0（本函数从不读，疑似键指针）; int value@0x4（精灵号）; u32 hash@0x8 }
 *    空桶判据 = hash == 0（Sprite_Init 逐桶把 +8 清 0；本函数 1eef94 / 1eeff8 判 0 即退出）。
 *
 *  算法（Robin-Hood 线性探测，**只比哈希、不比对字符串**）：
 *    h = CHashMapCalculateHash<char const*>(name) & 0x7FFFFFFF
 *    b = h & mask
 *    if (tab[b].hash == 0) return -1
 *    if (tab[b].hash == h) return tab[b].value
 *    probes = 0
 *    loop {
 *      b = (b + 1) & mask       // 1eefd4
 *      probes++                 // 1eefd8
 *      if (tab[b].hash == 0) return -1            // 1eeff8
 *      if (tab[b].hash == h) return tab[b].value  // 1eefc4
 *      dist = ((b + size) - (tab[b].hash & mask)) & mask   // 1eeff4..1eeffc、1eefac..1eefb0
 *      if (dist < probes) return -1               // 1eefcc
 *    }
 *  ⇒ 两条硬性质：① 纯哈希比较，两个不同名字撞同一哈希时会返回对方的精灵号（原版不做二次校验）；
 *                ② 表大小必须是 2 的幂（mask = size-1），否则 b 空间有洞。
 *  1eefb4 的 tst r12,r1 / bmi 在 size < 2^31 时符号位恒 0（dist 与 mask 都 < 2^31）⇒ 该早退分支是死代码，
 *  真正生效的早退是 1eefcc 的 cmp r5,r12。
 */

/* @0x1eef64 push {r4, r5, r6, r7, r8, lr} */
/* ── 哈希：CHashMapCalculateHash<char const*>(name)（0x1eeb88）───────────────
 * 返回 r0 = 原始哈希；1eef7c bic r0,r0,#0x80000000 清掉符号位 ⇒ 表内哈希恒为正。 */
/* @0x1eef68 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* ── 取表：池字 1ef038 = 0x201ea4 → 1eef70 [pc,r2] → 0x3f0e1c（g_spriteLookup）──
 * 1eef74 r1 = mask(+8)；1eef78 r7 = tab(+0x10)。 */
/* @0x1eef6c ldr r2, [pc, #0xc4] */
/* @0x1eef70 ldr r2, [pc, r2] */
/* @0x1eef74 ldr r1, [r2, #0x8] */
/* @0x1eef78 ldr r7, [r2, #0x10] */
/* @0x1eef7c bic r0, r0, #-2147483648 */
/* ── 首桶探测：b = h & mask，桶地址 = tab + 12*b（r4=b<<1、r12=r4+b、再 <<2）──
 * 1eef90 r12 = [tab+12b+8] = 该桶 hash；1eef94 为 0 → 1ef008（返回 -1）；
 * 1eef9c 与 h 相等 → 1ef018（命中）。 */
/* @0x1eef80 and r3, r0, r1 */
/* @0x1eef84 lsl r4, r3, #1 */
/* @0x1eef88 add r12, r4, r3 */
/* @0x1eef8c add r12, r7, r12, lsl #2 */
/* @0x1eef90 ldr r12, [r12, #0x8] */
/* @0x1eef94 cmp r12, #0 */
/* @0x1eef98 beq 0x1ef008 <_Z11Sprite_FindPKc+0xa4> */
/* @0x1eef9c cmp r0, r12 */
/* @0x1eefa0 beq 0x1ef018 <_Z11Sprite_FindPKc+0xb4> */
/* ── 未命中时的距离预检 ─────────────────────────────────────────────────────
 * 1eefa4 r8 = [r2] = size；1eefa8 r12 = mask & hash = 该条目的"家"桶；
 * 1eefac r2 = b + size；1eefb0 r12 = r2 - 家桶 ⇒ 现有条目被挤出的距离；
 * 1eefb4 tst r12,r1 置 N（见段首：size<2^31 时恒 0，此 bmi 不生效）。
 * 1eefbc r12 = 0 = 探针计数；1eefc0 b 1eefd4 进循环头。 */
/* @0x1eefa4 ldr r8, [r2] */
/* @0x1eefa8 and r12, r1, r12 */
/* @0x1eefac add r2, r3, r8 */
/* @0x1eefb0 rsb r12, r12, r2 */
/* @0x1eefb4 tst r12, r1 */
/* @0x1eefb8 bmi 0x1ef008 <_Z11Sprite_FindPKc+0xa4> */
/* @0x1eefbc mov r12, #0 */
/* @0x1eefc0 b 0x1eefd4 <_Z11Sprite_FindPKc+0x70> */
/* ── 循环体：命中判据两条 + Robin-Hood 早退 ─────────────────────────────────
 * 1eefc4/1eefc8：h == 桶 hash → 1ef010（命中口）；
 * 1eefcc/1eefd0：dist(r5) < probes(r12) → 1ef008（-1），这是 Robin-Hood 的"后面不可能再有"判据；
 * 1eefd4..1eeff8：b = (b+1)&mask、重算桶地址与 hash、dist = ((b+size)-(hash&mask))&mask；
 * 1eeff8/1eeffc：hash == 0 → -1；1ef004 bne 回 1eefc4。 */
/* @0x1eefc4 cmp r0, r2 */
/* @0x1eefc8 beq 0x1ef010 <_Z11Sprite_FindPKc+0xac> */
/* @0x1eefcc cmp r5, r12 */
/* @0x1eefd0 blt 0x1ef008 <_Z11Sprite_FindPKc+0xa4> */
/* @0x1eefd4 add r3, r3, #1 */
/* @0x1eefd8 add r12, r12, #1 */
/* @0x1eefdc and r3, r3, r1 */
/* @0x1eefe0 add r6, r3, r8 */
/* @0x1eefe4 lsl r4, r3, #1 */
/* @0x1eefe8 add r2, r4, r3 */
/* @0x1eefec add r2, r7, r2, lsl #2 */
/* @0x1eeff0 ldr r2, [r2, #0x8] */
/* @0x1eeff4 and r5, r1, r2 */
/* @0x1eeff8 cmp r2, #0 */
/* @0x1eeffc rsb r5, r5, r6 */
/* @0x1ef000 and r5, r5, r1 */
/* @0x1ef004 bne 0x1eefc4 <_Z11Sprite_FindPKc+0x60> */
/* ── 未命中：mvn r0,#0 = -1，pop {r4,r5,r6,r7,r8,pc} ────────────────────────
 * 三处出口（首桶空、探针早退、循环遇空桶）都跳这里；1ef010 的 cmn r3,#1 是"b == -1"的
 * 编译器残迹（b 已被 mask 限定为非负，永不命中）。 */
/* @0x1ef008 mvn r0, #0 */
/* @0x1ef00c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1ef010 cmn r3, #1 */
/* @0x1ef014 beq 0x1ef030 <_Z11Sprite_FindPKc+0xcc> */
/* ── 命中：返回桶的 +4 ──────────────────────────────────────────────────────
 * 1ef018 r3 = 3*b、1ef01c r7 = tab + 12*b、1ef020 cmn r7,#4（== -4 的判空残迹）、
 * 1ef028 ldr r0,[r7,#4] = value（精灵号）、1ef02c bx lr 前的 pop。
 * ⚠ value 是精灵号而不是 CSprite*：本函数唯一的用途就是给 sprite_index 之类的查询。 */
/* @0x1ef018 add r3, r4, r3 */
/* @0x1ef01c add r7, r7, r3, lsl #2 */
/* @0x1ef020 cmn r7, #4 */
/* @0x1ef024 beq 0x1ef008 <_Z11Sprite_FindPKc+0xa4> */
/* @0x1ef028 ldr r0, [r7, #0x4] */
/* @0x1ef02c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1ef030 mov r0, r3 */
/* @0x1ef034 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1ef038 eoreq r1, r0, r4, lsr #29 */
/* ── 段 K · Sprite_Assign 0x1ef454 —— "把 b 拷进 a"（sprite_assign(a,b)）────────
 *  _Z13Sprite_Assignii → int Sprite_Assign(int a, int b)
 *  = 若 0<=b<count：把 items[b] 的内容拷进 items[a]（a 槽为空则先 new CSprite(136)），
 *    成功后 items[a]+0x60 = a、items[a]+0x5c = names[a]，返回 1；任何越界返回 0。
 *
 *  ⚠ 两条边界（照实记录，原版自身行为）：
 *    ① a 只在"items[b]==0"这条支路里被检查（1ef4c8..1ef4d4）；
 *       正常支路 1ef490 直接 ldr r0,[items + a*4] —— a 越界就是越界读，若为空还会越界写（1ef4f4）。
 *    ② items[b]==0 时仍会走 CSprite::Assign(src=0)，而 0x1e76e8 的第一条指令就是
 *       ldr r3,[r1,#0x74] ⇒ 原版在这里会空解引用（没有防御）。
 *  ⇒ 调用方必须先保证 b 指向一个已存在的精灵、a 在 [0,count) 内（本函数不替你做）。
 */

/* ── 序言与 b 的双向边界 ────────────────────────────────────────────────────
 * 1ef458 subs r6,r1,#0（b）；1ef45c r4 = a；1ef460 blt → 1ef4d8 返回 0；
 * 1ef464 池字 1ef508 = 0x2019a8 → 0x3f0e18（count）；1ef470 cmp/bge → 返回 0。
 * ⚠ a 在这里完全没有被检查。 */
/* @0x1ef454 push {r3, r4, r5, r6, r7, lr} */
/* @0x1ef458 subs r6, r1, #0 */
/* @0x1ef45c mov r4, r0 */
/* @0x1ef460 blt 0x1ef4d8 <_Z13Sprite_Assignii+0x84> */
/* @0x1ef464 ldr r3, [pc, #0x9c] */
/* @0x1ef468 ldr r3, [pc, r3] */
/* @0x1ef46c ldr r3, [r3] */
/* @0x1ef470 cmp r6, r3 */
/* @0x1ef474 bge 0x1ef4d8 <_Z13Sprite_Assignii+0x84> */
/* ── 取表：池字 1ef50c = 0x20198c → 0x3f0e10（g_SpriteItems）→ [+4] ───────────
 * 1ef484 r1 = items[b]（源）；1ef488/1ef48c 为空 → 1ef4c8（只在此时才检查 a）。 */
/* @0x1ef478 ldr r5, [pc, #0x8c] */
/* @0x1ef47c ldr r5, [pc, r5] */
/* @0x1ef480 ldr r2, [r5, #0x4] */
/* @0x1ef484 ldr r1, [r2, r6, lsl #2] */
/* @0x1ef488 cmp r1, #0 */
/* @0x1ef48c beq 0x1ef4c8 <_Z13Sprite_Assignii+0x74> */
/* ── 目标槽：items[a]；为空则 new(136) + ctor ───────────────────────────────
 * 1ef490 r0 = items[a]；1ef494..1ef498 为空 → 1ef4e0；
 * 1ef4e0 mov r0,#136（= sizeof(CSprite)，ctor 清 0 的那张表覆盖 0x00..0x84 也印证 0x88 上限）；
 * 1ef4e4 _Znwj → 1ef4ec CSprite::CSprite() → 1ef4f4 items[a] = 新对象 → 1ef504 b 1ef49c。
 * 非空则 1ef49c 直接 CSprite::Assign(0x1e76e8)：dst->Assign(src)。
 * Assign 内部会 Clear、克隆 this+0x48 的每张位图、重建纹理/本地 TPE、最后 CreateMask（1e784c 尾跳）。 */
/* @0x1ef490 ldr r0, [r2, r4, lsl #2] */
/* @0x1ef494 cmp r0, #0 */
/* @0x1ef498 beq 0x1ef4e0 <_Z13Sprite_Assignii+0x8c> */
/* @0x1ef49c bl 0x1e76e8 <_ZN7CSprite6AssignEPS_> */
/* ── 成功后回填自身身份：+0x60 = a、+0x5c = names[a]，返回 1 ─────────────────
 * 1ef4a0 池字 1ef510 = 0x201960 → 0x3f0e14（g_SpriteNames）；1ef4a8 r0 = 1；
 * 1ef4b0 r2 = 名字数组；1ef4b4 r3 = items[a]；1ef4b8 r2 = names[a]；
 * 1ef4bc str r4,[r3,#0x60]（= a）、1ef4c0 str r2,[r3,#0x5c]（= 名字指针）；1ef4c4 pop。
 * ⇒ 这两个字段是"拷贝后重新贴标签"，Draw 的错误串 %s 取的就是 +0x5c。 */
/* @0x1ef4a0 ldr r3, [pc, #0x68] */
/* @0x1ef4a4 ldr r1, [r5, #0x4] */
/* @0x1ef4a8 mov r0, #1 */
/* @0x1ef4ac ldr r3, [pc, r3] */
/* @0x1ef4b0 ldr r2, [r3] */
/* @0x1ef4b4 ldr r3, [r1, r4, lsl #2] */
/* @0x1ef4b8 ldr r2, [r2, r4, lsl #2] */
/* @0x1ef4bc str r4, [r3, #0x60] */
/* @0x1ef4c0 str r2, [r3, #0x5c] */
/* @0x1ef4c4 pop {r3, r4, r5, r6, r7, pc} */
/* ── items[b]==0 的支路：此时才检查 a，然后照样去 1ef490 ─────────────────────
 * 1ef4c8 cmp r0,#0（a）；1ef4cc blt → 0；1ef4d0 cmp count, a；1ef4d4 bgt 1ef490
 * ⇒ 条件实际是 0 <= a < count（两个边界都由这条支路补上）。
 * 1ef4d8/1ef4dc 是统一的失败口：r0 = 0 后 pop。 */
/* @0x1ef4c8 cmp r0, #0 */
/* @0x1ef4cc blt 0x1ef4d8 <_Z13Sprite_Assignii+0x84> */
/* @0x1ef4d0 cmp r3, r0 */
/* @0x1ef4d4 bgt 0x1ef490 <_Z13Sprite_Assignii+0x3c> */
/* @0x1ef4d8 mov r0, #0 */
/* @0x1ef4dc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1ef4e0 mov r0, #136 */
/* @0x1ef4e4 bl 0x27c524 <_Znwj> */
/* @0x1ef4e8 mov r7, r0 */
/* @0x1ef4ec bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1ef4f0 ldr r3, [r5, #0x4] */
/* @0x1ef4f4 str r7, [r3, r4, lsl #2] */
/* @0x1ef4f8 ldr r3, [r5, #0x4] */
/* @0x1ef4fc ldr r1, [r3, r6, lsl #2] */
/* @0x1ef500 ldr r0, [r3, r4, lsl #2] */
/* @0x1ef504 b 0x1ef49c <_Z13Sprite_Assignii+0x48> */
/* @0x1ef508 eoreq r1, r0, r8, lsr #19 */
/* @0x1ef50c eoreq r1, r0, r12, lsl #19 */
/* @0x1ef510 eoreq r1, r0, r0, ror #18 */

/* 末尾：本卡 11 段共 1146 条锚点，全部来自 asm_index 生成的索引，未手抄。 */
