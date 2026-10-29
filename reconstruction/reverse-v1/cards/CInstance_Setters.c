/* cally 逆向卡：CInstance 六个写/读入口（原版 libyoyo.so，armv7）—— 一卡六节
 * @func 六节按 asm/index-CInstance_Setters_all.tsv 的顺序，逐节自带 @func 头与逐条锚点：
 *   §1 0x1931c0 CInstance::SetSpriteIndex(int)        size 140   35 条
 *   §2 0x1958cc CInstance::SetID(int, bool)           size 296   74 条（72 指令 + 2 池字）
 *   §3 0x193064 CInstance::SetDirection(float)        size 112   28 条（27 指令 + 1 池字）
 *   §4 0x193e7c CInstance::SetPosition(float,float)   size  68   17 条
 *   §5 0x19357c CInstance::GetImageNumber()           size  72   18 条
 *   §6 0x193134 CInstance::GetTimer(int)              size  20    5 条
 * 总账: 177 锚点 = 174 条指令 + 3 个池字（1959ec/1959f0 是 §2 的两个 pc 相对字，
 *       1930d0 = 0x43B40000 是 §3 的 360.0f），与 index 逐字一致
 *       （scripts/check_card_anchors.py → index=177 card=177 missing=0 extra=0 mismatch=0 RESULT EXACT）。
 * 级别: 正文（177/177 逐条落锚。六节的控制流、算式、字段偏移、被调方契约、三张全局表的身份
 *       全部钉死；未钉的是运行期可达性与少数形参/枚举名 —— 每节末尾单列本节 open）。
 *       tier = bytecode_anchored
 * 锚点来源: 全部由 asm_index.py 从二进制生成，本卡未手写转录；池字保留 objdump 的「像指令」写法，
 *       并在锚点注释里逐字标出「非指令」。
 * 读法: 各节「调用点 / 引用点」里跟的地址都是**指令地址**（bl 指令地址，或 pc 相对的装载点），
 *       不是被引函数的入口；被引函数的入口在注释里另行写出（如 CollisionMarkDirty 0x1cc1d0）。
 * 符号/尺寸: .dynsym 直读 —— _ZN9CInstance14SetSpriteIndexEi(0x1931c0,140)、
 *       _ZN9CInstance5SetIDEib(0x1958cc,296)、_ZN9CInstance12SetDirectionEf(0x193064,112)、
 *       _ZN9CInstance11SetPositionEff(0x193e7c,68)、_ZN9CInstance14GetImageNumberEv(0x19357c,72)、
 *       _ZN9CInstance8GetTimerEi(0x193134,20)，全部 FUNC GLOBAL DEFAULT。
 * 位置（.dynsym 按地址排序后的左右邻居，六个入口分属五个方法群）：
 *   SetImageAngle 19303c → **SetDirection 193064** → SetSpeed 1930d4
 *   SetVspeed 193114 → **GetTimer 193134** → SetTimer 193148
 *   SkeletonAnimation 193158 → **SetSpriteIndex 1931c0** → SetObjectIndex 19324c
 *   ChangeObjectIndex 193368 → **GetImageNumber 19357c** → SetPathPosition 1935c4
 *   Dump 19363c → **SetPosition 193e7c** → AddTo_Speed 193ec0
 *   Collision_Instance 195558 → **SetID 1958cc** → FINALIZE_Instance_Class 1959f4
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   六个入口都薄：四个写、两个读。写侧只有 SetID 维护一张全局表（ms_ID2Instance），
 *   其余三个把字段落盘后都走同一条尾巴「+0x64 置 1 + 尾调 CollisionMarkDirty」；
 *   读侧两个一次字段都不写（GetImageNumber 最多 new 一个 CSkeletonInstance）。
 *   SetPosition 只动 x/y、**不动前值与起点**；GetTimer 是唯一用无符号界判的入口。
 *
 * ── 六节一览（副作用是这张卡的主线）──────────────────────────────────────────
 *   节  地址      函数                   入口写点                              全局副作用
 *   §1  1931c0    SetSpriteIndex(int)    +0x8c（无条件）/ +0x90（条件归零）    置 +0x64；尾调 CollisionMarkDirty；
 *                                                                            析构+重建 +0x88 的 CSkeletonInstance
 *   §2  1958cc    SetID(int,bool)        +0x78（两路都写）                    ms_ID2Instance 摘旧键/插新键（bool 闸）
 *   §3  193064    SetDirection(float)    +0xcc                                Compute_Speed2 重算 +0xe0/+0xe4（尾跳）
 *   §4  193e7c    SetPosition(float,fl)  +0xb4/+0xb8                         置 +0x64；尾调 CollisionMarkDirty
 *   §5  19357c    GetImageNumber()       无                                    可能 new CSkeletonInstance 到 +0x88
 *   §6  193134    GetTimer(int)          无                                    无（20 B 纯读）
 *
 * ── 跨节结论（本卡新增，每条都能落到锚点）──────────────────────────────────
 *   A. 本卡六节里只有两个「置脏」写方：§1（0x193204，两条路径共用）与 §4（0x193eb8）；
 *      §2/§3/§5/§6 的 177 条锚点范围内 +0x64 一次都不出现。加上已出卡的 SetObjectIndex
 *      （0x193344），三处都是「strb 1 → 尾跳 CollisionMarkDirty 0x1cc1d0（b，不是 bl）」；
 *      §1 与 SetObjectIndex 还各带一次 pop 掉帧，§4 无栈帧（无 push/pop）直接 b。
 *      ⇒ 脏链的维护是逐函数决定的，不是统一 setter 模板；+0x64 在别处还有没有写方，本卡未扫全库。
 *   B. 「帧数」只有一个来源：sprite 基址 +0x18。§1 用它当上界（0x193220），§5 非骨架路直接返回它
 *      （0x1935a8）；骨架精灵两处都改走 sprite+0x74 == 2 → CSkeletonInstance::FrameCount(0)。
 *      ⇒ 换精灵时的回绕与 image_number 查询是同一字段，不会有两套不一致的口径。
 *   C. 位置的分工：+0xb4/+0xb8 由 §4 写；+0xbc/+0xc0（xstart/ystart）只有 ctor 写；
 *      +0xc4/+0xc8（xprevious/yprevious）只有 DoAStep 每步在移动前刷新（DoAStep 卡 ASTEP-005，
 *      0x1d3394..0x1d33d8）。⇒ SetPosition 是「瞬移」：不产生位移账，下一步的 prev 仍是瞬移前的旧值。
 *   D. SetID 维护的是第三张表：CInstance::ms_ID2Instance（.bss 0x536f28，12 B）。它既不是
 *      g_ObjectHash（0x542374，.bss 里是**指针变量**，还要再解一层），也不是构造期实例槽表
 *      （0x536f0c，{base,cap,count,next_free}）。§2 的三条指令流把三者分得很干净：整节只有
 *      GOT 0x3edc4c 一个全局表引用（唯一另一个池字是 Alloc 的源文件名）。
 *   E. SetDirection 是唯一「先两次归一化、再一次 fmodf」的写入口：两条 while 循环用 360.0f 加减，
 *      再 fmodf(d,360.0f) 兜底 ⇒ 双保险，结果恒在 [0,360)。它不置脏、不碰 bbox ——方向不进包围盒。
 *   F. 两个读入口零字段写：GetImageNumber 的副作用上界是「+0x88 可能被 new 出来」（经 SkeletonAnimation），
 *      GetTimer 连一个 bl 都没有（5 条指令直线）。
 *
 * ── 汇总 open（各节还有细项）──
 *   1. SetID 在本 .so 内**零调用点**（无 bl/b/blx，也无数据指针 —— 整个文件里 0x1958cc 只出现在
 *      .dynsym 的 st_value 一处）。它是导出符号却没有链接期调用者：谁在运行期改 id、为什么留这个入口，
 *      本卡给不出证据（见 §2 open 1）。
 *   2. §2 假定 ms_ID2Instance 的桶数组已建（0x1958fc 直接以 buckets 基址寻址，不判空）：
 *      桶数/掩码的初值来源不在本卡（候选是 CRoom::AddInstance 的首插路径与 FINALIZE 之前的初始化）。
 *      同理 g_ObjectHash 的指针变量由谁赋值，见 Variable_GetValue 卡，本卡不涉及。
 *   3. +0xc4/+0xc8 的**读方**没有枚举：本卡只证 SetPosition 不写它们、DoAStep 写它们。
 *   4. sprite+0x74 的类型枚举：==2 是骨架（§1 0x193180/0x19318c、§5 0x19359c/0x1935a0 两处独立同判），
 *      其余取值与名字未定（Instance_Animate 另用 sprite+0x70 == 1 走「按 FPS 的动画」，那是第三个数）。
 *   5. CSkeletonInstance::FrameCount(int) 的第 1 实参在 §5 恒传 0（0x1935b8）；该形参叫什么、0 是
 *      「第 0 条动画」还是「全部帧」，要在 CSkeletonInstance 侧另开卡。
 *   6. ±inf / NaN 进 SetDirection 的行为是按指令推的（inf 在第二条 while 里永不收敛、NaN 两个循环都不进），
 *      未在原件上验证过可达性，记在 §3 open。
 */

/* ══ §1 CInstance::SetSpriteIndex(int) 0x1931c0 ══════════════════════════════
 * @func 0x1931c0 0x19324c  size 140  35 条（35 指令，无池字；下一个符号 SetObjectIndex 0x19324c）
 * 级别: 正文（35/35。两条路径、三处外部调用、一个共用尾巴，全部解出）
 * 符号: _ZN9CInstance14SetSpriteIndexEi → void CInstance::SetSpriteIndex(int sprite)
 * 位置: CInstance::SkeletonAnimation 0x193158 之后、CInstance::SetObjectIndex 0x19324c 之前
 * 调用点: bl 直调 3 处 —— SetObjectIndex 0x193338（obj+0x04）、ChangeObjectIndex 0x19344c、
 *         SV_SpriteIndex 0x1faa28（GML 的 sprite_index 赋值）
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   先无条件把新精灵号写进 +0x8c，再判精灵是否存在：不存在就只把 +0x90 按「上界 0」回绕一次；
 *   存在就把旧骨架实例析构+free 掉、交 SkeletonAnimation 重建，再按新精灵的帧数回绕 image_index；
 *   两条路径共用尾巴「+0x64 = 1 → 尾调 CollisionMarkDirty」。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   void CInstance::SetSpriteIndex(int sprite) {
 *     this->sprite_index = sprite;                       // +0x8c（0x1931c8，先存后校验）
 *     int bound = 0;                                     // r5：回绕上界
 *     if (Sprite_Exists(sprite)) {                        // 0x1eee98
 *       CSkeletonInstance* sk = this->skeleton;           // +0x88（0x193218）
 *       bound = Sprite_Data(sprite)->count;               // +0x18（0x193214/0x193220）
 *       if (sk) {                                         // 0x193224
 *         CSkeletonInstance::~CSkeletonInstance(sk);      // 0xbe194（D2）
 *         operator delete(sk);                            // 0x27d1d0
 *         this->skeleton = 0;                             // +0x88（0x19323c）
 *       }
 *       SkeletonAnimation(this);                          // 0x193158，见下
 *     }
 *     if (bound <= (int)this->image_index)                // 0x1931f4（cmp r5,r3 = 上界 vs 截断值）
 *       this->image_index = 0.0f;                         // +0x90（0x1931fc，movle/strle）
 *     this->[0x64] = 1;                                   // 0x193204
 *     CollisionMarkDirty(this);                            // 尾调 0x1cc1d0（0x19320c，b）
 *   }
 *
 * ── 已证（指令级）──────────────────────────────────────────────────────
 *  1. +0x8c 是**先写后判**：0x1931c8 在任何 Sprite_Exists 之前落盘。所以传入非法/不存在的精灵号时，
 *     字段里留下的是那个非法值本身（没有 -1 归一、没有回退到旧值），只是 image_index 被归零、置脏。
 *     这条与 CInstance_DeSerialise 卡 CIDS-012（存档直写 +0x8c、不经本函数）合起来说明：
 *     「+0x8c 里可能是任意 int」是原版允许的状态，不是脏数据。
 *  2. 存在性判定与数据取用是两个独立调用：Sprite_Exists(int) 0x1eee98 → Sprite_Data(int) 0x1ef03c；
 *     后者返回 CSprite*，+0x18 就是帧数（§5 的非骨架路径直接返回同一字段，两节互证）。
 *  3. 回绕只有上界：0x1931e4 vldr s15,[+0x90] → 0x1931e8 vcvt.s32.f32（**截断**，不是四舍五入）
 *     → 0x1931f4 cmp r5,r3 → 0x1931f8 movle r3,#0 → 0x1931fc strle r3,[+0x90]。
 *     不存在路径里上界=0（0x1931dc moveq r5,r0 且 r0==0），于是「image_index >= 0 就归零」；
 *     负的 image_index 在这一步**不被纠正**（负回绕由 Instance_Animate 0x1d3284..0x1d32a8 处理）。
 *  4. 骨架实例的换血是全函数最重的副作用，顺序固定：读 +0x88（0x193218）→ 非空才析构
 *     （0x19322c D2 0xbe194）→ operator delete（0x193234）→ 清 +0x88（0x19323c）→
 *     SkeletonAnimation(this)（0x193244）。判存在之前不碰 +0x88。
 *  5. SkeletonAnimation 0x193158 的契约（旁证，本卡外）：Sprite_Exists 失败 → 直接返回现 +0x88；
 *     Sprite_Data()->[0x74] != 2 → 直接返回现 +0x88；== 2 且 +0x88 == 0 → operator new(0x34)
 *     + CSkeletonInstance(sprite+0x58) 写入 +0x88。⇒「换精灵即换骨架」，但骨架只对 type==2 建。
 *  6. 两条路径共用同一个尾巴（0x1931e4..0x19320c）：都置 +0x64 = 1 并以 b（不是 bl）尾调
 *     CollisionMarkDirty —— 与 SetObjectIndex 卡 0x193344/0x19334c 的尾巴逐字同构。
 *  7. 全节 5 个 bl，都在本函数体内：Sprite_Exists 0x1931d4、Sprite_Data 0x193214、
 *     CSkeletonInstance::~CSkeletonInstance 0x19322c、operator delete 0x193234、SkeletonAnimation 0x193244；
 *     一次 vtable/blx 调用都没有。.ARM.exidx 里查不到 0x1931c0 的条目（与 §6 相同）
 *     ⇒ 没有 C++ 展开区间/LSDA，出口只有 0x193208 的 pop 与 0x19320c 的 b 两条。
 *
 * ── open（本节）──────────────────────────────────────────────────────────
 *   · sprite+0x18 的「帧数」对**非骨架**精灵成立；骨架精灵的 +0x18 是什么语义（0？总帧？）未证 ——
 *     骨架路径先把 +0x18 当上界用（0x193220），再让 SkeletonAnimation 决定骨架，两者不冲突但也不互证。
 *   · Sprite_Exists 的判定范围（是否按 0..174 的 SPRT 数、是否另查已释放位）不在本卡。
 *   · 本函数不改 +0xac（mask index）、不改 +0x65（visible）—— 换精灵不会顺带换掩码/可见性；
 *     谁负责 mask 与 sprite 的一致性（SetObjectIndex、Set_MaskIndex 0x192ba8）另卡。
 */

/* @0x1931c0 push {r4, r5, r6, lr} —— 入口。r4 = this、r5 = sprite（两个都先存寄存器） */
/* @0x1931c4 mov r4, r0 */
/* @0x1931c8 str r1, [r4, #0x8c] —— +0x8c = sprite；先写后校验，非法号照样落盘（本函数最容易被误读的一步） */
/* @0x1931cc mov r0, r1 */
/* @0x1931d0 mov r5, r1 */
/* @0x1931d4 bl 0x1eee98 <_Z13Sprite_Existsi> —— Sprite_Exists(sprite) 0x1eee98 */
/* @0x1931d8 cmp r0, #0 */
/* @0x1931dc moveq r5, r0 —— 不存在 → 回绕上界 r5 = 0（moveq r5,r0，此时 r0==0） */
/* @0x1931e0 bne 0x193210 <_ZN9CInstance14SetSpriteIndexEi+0x50> —— 存在 → 走骨架换血（0x193210），不存在 → 落进共用的回绕尾巴 */
/* @0x1931e4 vldr s15, [r4, #144] —— 共用尾巴①：读 +0x90 image_index（float） */
/* @0x1931e8 vcvt.s32.f32 s15, s15 —— vcvt.s32.f32 = 截断取整（不是四舍五入） */
/* @0x1931ec mov r0, r4 */
/* @0x1931f0 vmov r3, s15 */
/* @0x1931f4 cmp r5, r3 —— 上界 vs 截断后的 image_index（r5 上界、r3 当前帧，别按直觉读反） */
/* @0x1931f8 movle r3, #0 */
/* @0x1931fc strle r3, [r4, #0x90] —— strle：上界 <= 当前帧 → image_index = 0（只纠上越界，负值不在这里纠） */
/* @0x193200 mov r3, #1 */
/* @0x193204 strb r3, [r4, #0x64] —— +0x64 = 1（bbox 脏），两条路径共用 */
/* @0x193208 pop {r4, r5, r6, lr} */
/* @0x19320c b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> —— 尾调：先 pop 掉帧再 b，返回值直接透传 */
/* @0x193210 mov r0, r5 —— 存在路径：r0 = sprite（r5 == r1） */
/* @0x193214 bl 0x1ef03c <_Z11Sprite_Datai> —— Sprite_Data(sprite) 0x1ef03c → CSprite* */
/* @0x193218 ldr r6, [r4, #0x88] —— 读旧骨架实例 +0x88 */
/* @0x19321c cmp r6, #0 */
/* @0x193220 ldr r5, [r0, #0x18] —— 上界 = CSprite+0x18（帧数；§5 非骨架路返回同一字段） */
/* @0x193224 beq 0x193240 <_ZN9CInstance14SetSpriteIndexEi+0x80> —— 旧骨架为空 → 跳过析构/释放 */
/* @0x193228 mov r0, r6 */
/* @0x19322c bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> —— CSkeletonInstance::~CSkeletonInstance 0xbe194（D2） */
/* @0x193230 mov r0, r6 */
/* @0x193234 bl 0x27d1d0 <_ZdlPv> —— operator delete 0x27d1d0 */
/* @0x193238 mov r3, #0 */
/* @0x19323c str r3, [r4, #0x88] —— +0x88 = 0（先清干净再交给 SkeletonAnimation 重建） */
/* @0x193240 mov r0, r4 */
/* @0x193244 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> —— SkeletonAnimation(this) 0x193158：仅 type==2 且 +0x88==0 时 new 0x34 */
/* @0x193248 b 0x1931e4 <_ZN9CInstance14SetSpriteIndexEi+0x24> —— 回到 0x1931e4 的回绕尾巴（上界 r5 已换成帧数） */
/* ══ §2 CInstance::SetID(int, bool) 0x1958cc ═════════════════════════════════
 * @func 0x1958cc 0x1959f4  size 296  74 条（72 指令 + 末两字 1959ec/1959f0 为 literal pool；
 *       下一个符号 FINALIZE_Instance_Class 0x1959f4）
 * 级别: 正文（74/74。两条路径、哈希摘/插的每个分支、Alloc/Free 契约、池字双解全钉；
 *       未钉的只是运行期可达性 —— 本函数在本二进制里没有任何调用者）
 * 符号: _ZN9CInstance5SetIDEib → void CInstance::SetID(int id, bool bSyncHash)
 * 位置: CInstance::Collision_Instance 0x195558 之后、FINALIZE_Instance_Class 0x1959f4 之前
 *       （与 §1 的 SetSpriteIndex 0x1931c0 相隔约 10 KB，不属于同一方法群）
 * 调用点: **零**。全 .text 无 bl/b/blx 指向 0x1958cc，.rodata/.data.rel.ro/.data 里也无指针
 *         （整个 4,689,844 B 文件里 0x1958cc 只出现 1 次 = .dynsym 的 st_value，文件偏移 0x186fc）。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   改实例 id：第二实参为 0 时只把新 id 写进 +0x78 就走人；非 0 时先在 ms_ID2Instance 里
 *   按**旧** id 找到节点摘掉（Free 回 MemoryManager），再写 +0x78，然后 Alloc 一个新节点
 *   以新 id 为键挂到对应桶的**尾部**，最后 count++。插入前不查重。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   void CInstance::SetID(int id, bool bSyncHash) {
 *     if (!bSyncHash) { this->id = id; return; }              // 0x1958dc streq / 0x1958e0 popeq
 *     uint32_t old = this->id;                                // +0x78（0x1958e8）
 *     HashTable* t = &CInstance::ms_ID2Instance;              // .bss 0x536f28（GOT 0x3edc4c）
 *     uint32_t idx = old & t->mask;                           // 0x1958f8
 *     Node* bucket = &t->buckets[idx];                        // 桶 8 B（0x195900 add lr, r7, idx<<3）
 *     for (Node* n = bucket->head; n; n = n->next)            // 0x195904..0x195930
 *       if (n->key == old) {                                  // 0x195910/0x195920
 *         unlink(n, bucket);                                  // 0x195994..0x1959b8 四分支
 *         MemoryManager::Free(n);                             // 0x27c2d0
 *         t->count--;                                         // 0x1959d0
 *         break;
 *       }
 *     this->id = id;                                          // +0x78（0x195944）
 *     Node* n = MemoryManager::Alloc(16, "jni/../jni/yoyo/../../../Platform/Hash.h", 306, 1);
 *     n->key = id; n->value = this;                           // 0x195960/0x195964
 *     PushBack(&t->buckets[id & t->mask], n);                 // 0x19596c..0x195980（非空）/ 0x1959d8（空桶）
 *     t->count++;                                             // 0x195984..0x19598c
 *   }
 *
 * ── 字段与全局（本卡读写的全部地址）────────────────────────────────────────
 *   this+0x078 int           id（两路都写；非 0 路是在摘旧之后写）
 *   ms_ID2Instance .bss 0x536f28  12 B 表头 {+0x00 桶数组, +0x04 掩码, +0x08 计数}
 *                              GOT 槽 0x3edc4c（ldr r4,[pc,#0x100] 池 0x1959ec = 0x00258358 + pc）
 *   桶 8 B                  {+0x00 head, +0x04 tail}
 *   节点 16 B               {+0x00 prev, +0x04 next, +0x08 key=id, +0x0c value=CInstance*}
 *   Alloc 源文件名          "jni/../jni/yoyo/../../../Platform/Hash.h"（池 0x1959f0 = 0x001b7360 +
 *                          0x195954 = 0x34ccb4，文件内实测该地址正是这串），行号 0x132 = 306，第 4 实参 1
 *
 * ── 已证（指令级）──────────────────────────────────────────────────────
 *  1. bool 闸门（极性已证，名字是推断）：0x1958cc cmp r2,#0 → 0x1958dc streq r1,[r0,#0x78] →
 *     0x1958e0 popeq {r4,r5,r6,r7,r8,pc}。r2 == 0 = 只写 +0x78 就返回，哈希一个字节都不碰；
 *     r2 != 0 = 走完整摘/插。注意 cmp 在 push **之前**，这是编译器的「早退优先」排布，不是两个入口。
 *  2. 表身份三层定死：池字 0x1959ec(0x00258358) → 0x1958ec 的 `ldr r4,[pc,r4]`（pc = 0x1958f4）
 *     = 0x3edc4c → .got 里该槽内容 = 0x536f28 = .dynsym 的 _ZN9CInstance14ms_ID2InstanceE
 *     （12 B OBJECT）。所以这里是「GOT 槽直接装着表结构地址」，与 g_ObjectHash 的
 *     「GOT → 0x542374（指针变量）→ 表结构」差一层解引用，两张表不可能混。
 *  3. 与另外两张表互不相同：g_ObjectHash 在 0x542374（GOT 0x3edc44，SetObjectIndex 0x193290 用），
 *     构造期实例槽表在 0x536f0c（{base,cap,count,next_free}，ctor 卡段 10 用）。本函数只碰 0x536f28，
 *     两个池字一个是 GOT 偏移、一个是 .rodata 源文件名，没有第三个全局。
 *  4. 摘旧键用**旧** id：0x1958e8 ldr r12,[r0,#0x78] 早于 0x195944 的写入；桶号 = old & mask（0x1958f8），
 *     链上比的是 key（0x195910 ldr r0,[r3,#0x8] / 0x195920）。摘除是标准四分支：
 *     prev!=0 → prev->next = next（0x1959a4）；prev==0 → bucket.head = next（0x1959ac）；
 *     next==0 → bucket.tail = prev（0x1959b4）；next!=0 → next->prev = prev（0x1959b8）。
 *  5. Free 之后**重读表**：0x1959c4 ldmib r4,{r1,r3} 取回 mask/count、0x1959c8 ldr r7,[r4] 取回桶基址，
 *     再 count--（0x1959cc/0x1959d0）。表结构指针 r4 是 callee-saved 所以不重载 —— 这说明重载是为了
 *     被 bl 打烂的 caller-saved 寄存器，不是表被 Free 改动过。
 *  6. 写 +0x78 的位置在「摘旧之后、Alloc 之前」（0x195944）。⇒ 只要 0x195950 的 Alloc 不返回，
 *     实例就处于「旧键已摘、新键未插、+0x78 已是新值」的中间态；本函数**不判** Alloc 返回值
 *     （0x195960 直接 str r6,[r0,#0x8] —— r0 就是 Alloc 的结果）。
 *  7. 插入是**桶尾追加**，空桶与非空桶两条收尾：非空 0x19596c..0x195980（tail->next = n、bucket.tail = n、
 *     n->next = 0、n->prev = 旧 tail）；空桶 0x1959d8..0x1959e4（bucket.tail = n、bucket.head = n、
 *     n->next = 0、n->prev = 0，r3==0 复用）。两条都汇到 0x195984 的 count++。
 *  8. 不查重：新 id 的桶只做了定位与追加，没有一次 key 比较（比较只发生在旧 id 那一段）。
 *      ⇒ 同一 id 可以挂多个节点，不同实例可以共享 id。查表方沿桶链找**第一个** key 命中
 *     （同构走法见 Variable_GetValue 卡 VGV-003）；本卡只证插入侧不查重，查表侧的取用顺序未逐点复核。
 *  9. 同 id 也照摘照插：old == id 时先摘掉再追加，节点的桶内位置会移到尾部（链序变化，语义等价）。
 * 10. 两个池字都不是指令：0x1959ec = 0x00258358、0x1959f0 = 0x001b7360（objdump 译成 eoreq/andseq，
 *     本卡保留其写法并在此标注）。Alloc 的四个实参由此定死：16 / 源文件名 / 306 / true。
 * 11. 这张表就是「实例 id → CInstance*」索引：按 GOT 0x3edc4c 的引用点扫描（pc 相对两条 idiom：
 *     ldr[pc,#imm]+ldr[pc,rX] 与 add pc,#imm）共 23 处，含 WithObjIterator::WithObjIterator 0x19d130、
 *     Object_GetInstance 0x14ecb4、Command_InstancePosition 0x1c91fc、F_VariableInstanceGet 0x1169d8 /
 *     Set 0x116ae0 / GetNames 0x1198a4、Variable_GetObjectName 0x1f3fb0、CRoom::AddInstance 四个重载
 *     (0x1ab1f4/0x1ab3a4/0x1ab558/0x1ab6b0)、FINALIZE_Instance_Class 0x1959fc。
 *     ⇒ AddInstance 家族是**内联**插同构表（不调本函数），本函数是「改 id」的那条路。
 *     ⚠ 该计数来自 idiom 扫描，不含 blx/虚调用/其它寻址形态，是下界不是全量。
 *
 * ── open（本节）──────────────────────────────────────────────────────────
 *  1. 零调用点（0x1958cc 只在 .dynsym 出现一次）。可能原因：① 只被外部 dylib/JNI 按符号名取用；
 *     ② 原引擎里 id 只在 CRoom::AddInstance 阶段定一次，运行期改 id 的功能被裁掉了；③ 死在死代码里。
 *     三条都无证据，本卡不选。**不要**照「看起来像 setter」就假设 GML 的 id 赋值会走到这里。
 *  2. 桶数组与掩码的初值来源不在本卡：0x1958fc/0x195938 都以 t->buckets 直接寻址，不判空，
 *     所以调用前表必须已建。谁建桶未证 —— 紧接着的 FINALIZE_Instance_Class 0x1959f4 是**拆**表的方向
 *     （遍历桶、按 key 复核节点），建表方（本卡未展开）不在这里。
 *  3. bool 形参的正式名与调用方语义未定（极性已证）；同族证据：CRoom::DeSerialise 卡 CDS-010 把
 *     同名行为的开关叫 bRegister，本卡取 bSyncHash 只是描述性的。
 *  4. Alloc 失败（返回 0）时的实际行为取决于 MemoryManager::Alloc 是否 abort；本卡只证「无条件解引用」。
 *  5. 异常面：本函数在 .ARM.exidx 里有一条（0x325328，personality 0x80acb0b0），说明它带展开区间/LSDA；
 *     而 §1 与 §6 在 .ARM.exidx 里**没有**条目（确实没有 C++ 展开区间），§3/§4/§5 各有一条。
 *     展开区间具体包住哪几条指令、清理什么（是否只为 Alloc/Free 的 unwinding 兜底），未解。
 */

/* @0x1958cc cmp r2, #0 —— 本指令先于 push：早退优先的排布，不是两个入口 */
/* @0x1958d0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1958d4 mov r5, r0 */
/* @0x1958d8 mov r6, r1 */
/* @0x1958dc streq r1, [r0, #0x78] —— streq：bool == 0 → 只写 +0x78 = id */
/* @0x1958e0 popeq {r4, r5, r6, r7, r8, pc} —— 同一 eq 条件早早返回：哈希一个字节都不碰 */
/* @0x1958e4 ldr r4, [pc, #0x100] —— 池 0x1959ec = 0x00258358 → 下一步算 GOT 地址 */
/* @0x1958e8 ldr r12, [r0, #0x78] —— r12 = **旧** id（+0x78），早于 0x195944 的写入 */
/* @0x1958ec ldr r4, [pc, r4] —— pc = 0x1958f4（本条 +8）+ 0x258358 = 0x3edc4c → GOT 槽内容 = 0x536f28 */
/* @0x1958f0 ldr r1, [r4, #0x4] —— mask = t+0x4 */
/* @0x1958f4 ldr r7, [r4] —— buckets = t+0x0（表结构就地解引用，中间没有指针变量） */
/* @0x1958f8 and r2, r12, r1 —— 桶号 = 旧 id & mask */
/* @0x1958fc ldr r3, [r7, r2, lsl #3] —— 桶项 8 B：链头 */
/* @0x195900 add lr, r7, r2, lsl #3 —— lr = &bucket[idx]（后面摘链要用 head/tail） */
/* @0x195904 cmp r3, #0 —— 空桶 → 没有旧节点可摘，直接去插入 */
/* @0x195908 beq 0x195934 <_ZN9CInstance5SetIDEib+0x68> */
/* @0x19590c ldr r0, [r3, #0x8] —— 节点 key 在 +0x8 */
/* @0x195910 cmp r12, r0 —— 首节点就命中 → 0x195994 摘链 */
/* @0x195914 bne 0x195928 <_ZN9CInstance5SetIDEib+0x5c> */
/* @0x195918 b 0x195994 <_ZN9CInstance5SetIDEib+0xc8> —— 跳进摘链块 */
/* @0x19591c ldr r2, [r3, #0x8] */
/* @0x195920 cmp r12, r2 */
/* @0x195924 beq 0x195994 <_ZN9CInstance5SetIDEib+0xc8> —— 链上命中（循环体） */
/* @0x195928 ldr r3, [r3, #0x4] —— next 在 +0x4 */
/* @0x19592c cmp r3, #0 */
/* @0x195930 bne 0x19591c <_ZN9CInstance5SetIDEib+0x50> —— 非空继续走链 */
/* @0x195934 and r8, r1, r6 —— 插入段入口：r8 = mask & 新 id；r1 仍/mask 重载后可用 */
/* @0x195938 ldr r1, [pc, #0xb0] —— 池 0x1959f0 = 0x001b7360 → Alloc 的源文件名 */
/* @0x19593c movw r2, #0x132 —— 行号 0x132 = 306（Hash.h 模板的分配点） */
/* @0x195940 mov r3, #1 —— Alloc 第 4 实参 = 1（zero-init，见 MemoryManager::Alloc 契约） */
/* @0x195944 str r6, [r5, #0x78] —— +0x78 = 新 id；此刻旧键已摘、新键还没分配 */
/* @0x195948 mov r0, #16 —— size = 16 = 节点尺寸 {prev,next,key,value} */
/* @0x19594c add r1, pc, r1 —— r1 = pc(0x195954) + 0x1b7360 = 0x34ccb4 = "jni/../jni/yoyo/../../../Platform/Hash.h" */
/* @0x195950 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> —— MemoryManager::Alloc(16, file, 306, 1)；本函数不判返回值 */
/* @0x195954 ldr r3, [r7, r8, lsl #3] —— 空桶/非空桶两路的公共起点：先取新桶链头 */
/* @0x195958 add r2, r7, r8, lsl #3 —— r2 = &新桶 */
/* @0x19595c cmp r3, #0 —— 桶空？ */
/* @0x195960 str r6, [r0, #0x8] —— node.key = 新 id */
/* @0x195964 str r5, [r0, #0xc] —— node.value = this */
/* @0x195968 beq 0x1959d8 <_ZN9CInstance5SetIDEib+0x10c> —— 桶空 → 0x1959d8 初始化 head/tail */
/* @0x19596c ldr r3, [r2, #0x4] —— 非空：旧 tail（往桶尾追加，不是头插） */
/* @0x195970 mov r1, #0 */
/* @0x195974 str r3, [r0] —— node.prev = 旧 tail */
/* @0x195978 str r0, [r3, #0x4] —— 旧 tail->next = node */
/* @0x19597c str r0, [r2, #0x4] —— bucket.tail = node */
/* @0x195980 str r1, [r0, #0x4] —— node.next = 0 */
/* @0x195984 ldr r3, [r4, #0x8] —— count 在 +0x8 */
/* @0x195988 add r3, r3, #1 */
/* @0x19598c str r3, [r4, #0x8] —— count++ 后 pop 返回 */
/* @0x195990 pop {r4, r5, r6, r7, r8, pc} */
/* @0x195994 ldr r1, [r3] —— 摘链入口：先读 node.prev */
/* @0x195998 cmp r1, #0 */
/* @0x19599c ldrne r2, [r3, #0x4] —— prev != 0 → 取 next 准备改 prev->next */
/* @0x1959a0 ldreq r0, [r3, #0x4] —— prev == 0 → 取 next 准备改 bucket.head */
/* @0x1959a4 strne r2, [r1, #0x4] —— prev->next = next */
/* @0x1959a8 ldrne r0, [r3, #0x4] */
/* @0x1959ac streq r0, [lr] —— bucket.head = next（prev == 0 分支） */
/* @0x1959b0 cmp r0, #0 —— next == 0 ? */
/* @0x1959b4 streq r1, [lr, #0x4] —— bucket.tail = prev（next == 0 分支） */
/* @0x1959b8 strne r1, [r0] —— next->prev = prev（next != 0 分支） */
/* @0x1959bc mov r0, r3 */
/* @0x1959c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— MemoryManager::Free(node) 0x27c2d0 */
/* @0x1959c4 ldmib r4, {r1, r3} —— Free 之后重载 mask/count（caller-saved 已被 bl 打烂；表指针 r4 是 callee-saved 所以不重载） */
/* @0x1959c8 ldr r7, [r4] —— 重载 buckets 基址 */
/* @0x1959cc sub r3, r3, #1 */
/* @0x1959d0 str r3, [r4, #0x8] —— count-- */
/* @0x1959d4 b 0x195934 <_ZN9CInstance5SetIDEib+0x68> —— 回到插入段（旧 id 已摘干净） */
/* @0x1959d8 str r0, [r2, #0x4] —— 空桶：bucket.tail = node */
/* @0x1959dc str r0, [r7, r8, lsl #3] —— bucket.head = node */
/* @0x1959e0 str r3, [r0, #0x4] —— node.next = 0（r3 在 0x19595c 的 cmp 后为 0） */
/* @0x1959e4 str r3, [r0] —— node.prev = 0 */
/* @0x1959e8 b 0x195984 <_ZN9CInstance5SetIDEib+0xb8> —— 汇到 count++ */
/* @0x1959ec eoreq r8, r5, r8, asr r3 —— 非指令：0x00258358 = GOT 0x3edc4c 的 pc 相对偏移 */
/* @0x1959f0 andseq r7, r11, r0, ror #6 —— 非指令：0x001b7360 = 源文件名字符串的 pc 相对偏移 */
/* ══ §3 CInstance::SetDirection(float) 0x193064 ══════════════════════════════
 * @func 0x193064 0x1930d4  size 112  28 条（27 指令 + 末字 1930d0 为池字 0x43B40000；
 *       下一个符号 CInstance::SetSpeed 0x1930d4，前一符号 CInstance::SetImageAngle 0x19303c）
 * 级别: 正文（28/28。两条归一化循环 + 一次 fmodf + 一次尾跳，算式与常量全解）
 * 符号: _ZN9CInstance12SetDirectionEf → void CInstance::SetDirection(float dir)
 * 位置: 运动写入口族的正中 —— SetImageAngle 0x19303c → 本函数 → SetSpeed 0x1930d4
 * 调用点: bl 直调 12 处 —— F_MotionSet 0x108540、YYGML_motion_set 0x10ac88、
 *         F_ActionSetMotion 0x13d9fc、Motion_Linear_Step 0x19c998、Motion_Linear_Path 0x19caec、
 *         TryDir 0x19cca0、Motion_Potential_Step 0x19ce1c/0x19ce64、Motion_Potential_Path 0x19cfe8、
 *         SV_Direction 0x1fb75c 等 ⇒ 方向的所有写入口都收在这一处。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   把任意角度压到 [0,360)：先两条 while 用 360.0f 加减，再 fmodf(d,360.0f) 兜底，写进 +0xcc，
 *   最后尾跳 Compute_Speed2 重算 hspeed/vspeed。**不置 +0x64、不调 CollisionMarkDirty**。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   void CInstance::SetDirection(float d) {
 *     while (d < 0.0f)     d += 360.0f;        // 0x193078..0x19308c（bmi 回环）
 *     while (d > 360.0f)   d -= 360.0f;        // 0x19309c..0x1930ac（bgt 回环）
 *     this->direction = fmodf(d, 360.0f);      // +0xcc（0x1930c0）；fmodf 0xb6790@plt，360.0f=0x43B40000
 *     Compute_Speed2();                        // 尾跳 0x192aa0（0x1930cc 的 b）
 *   }
 *
 * ── 已证（指令级）──────────────────────────────────────────────────────
 *  1. 归一化是「双保险」：循环只处理 <0 和 >360 两侧，出循环后 d ∈ [0,360]；再 fmodf 把 =360 归成 0，
 *     所以落盘值域是 [0,360)。若只有 fmodf，负数会得到负余数（C 语义），两条循环正是为了避开这点。
 *  2. 360.0f 有两个来源：循环内的池字 0x1930d0（0x43B40000，`vldr s14,[pc,#76]`/`[pc,#56]` 两次取），
 *     以及 fmodf 的第二实参 r0:r1 = (0, 0x43B40000) 由 mov/movt 拼出（0x1930b4/0x1930b8）——
 *     常量没有被共用寄存器保存，是三条独立编码。
 *  3. 比较用 vcmpe.f32 + vmrs APSR_nzcv，分支是 bpl/bmi/ble/bgt 四个条件码；NaN 序关系为无序，
 *     两个循环都不进（bpl 见 N==0、ble 见 N!=V 都成立），直接到 fmodf(NaN) → 仍写 NaN。
 *  4. 尾跳 Compute_Speed2 0x192aa0 的取数：vldr s18,[+0xcc]（direction）、vldr s17,[+0xd0]（speed）；
 *     弧度 = dir * 池字 0x192b9c(0x40490FDB = π) / 池字 0x192ba0(0x43340000 = 180.0f)，再
 *     cos → speed*cos 写 +0xe0（hspeed，0x192ad8）、sin → -speed*sin 写 +0xe4（vspeed，0x192af0），
 *     最后用 lrint + |x - lrint(x)| < 池字 0x192ba4(0x38D1B717 = 1e-4) 把接近整数的分量吸附成整数。
 *     ⇒ 方向一改，速度分量立刻同步，调用方不需要再自己算一次。
 *  5. 本节锚点里 +0x64 一次都没出现，也没有 CollisionMarkDirty：方向不进包围盒。
 *     与 §1/§4 对照即可看出「哪些写入口必须置脏」是逐函数决定的，不是统一的 setter 模板。
 *  6. 全节只有 1 个 bl（0x1930bc fmodf@plt）+ 1 个尾跳（0x1930cc），其余全是 VFP 算术与条件分支；
 *     无分配、无表访问、无虚调用。
 *
 * ── open（本节）──────────────────────────────────────────────────────────
 *   · ±inf：第二条 while 里 inf - 360 = inf，bgt 恒真 ⇒ 死循环。这是按指令推的结论，
 *     但调用方（GML 数值/运动系统）是否会送进 inf 未证，也没有在原件上试过。
 *   · 归一化的两段用的是严格比较（d<0 / d>360），所以 d == 360.0f 会走 fmodf 得 0；
 *     d == -0.0f 满足 d<0 为假（IEEE -0 == 0），落盘 fmodf(-0)= -0 —— 负零是否被下游区分未证。
 *   · direction 的单位与坐标系（顺时针/逆时针、0 指向）不在本卡：Compute_Speed2 用
 *     +speed·cos(dir) 作 hspeed、-speed·sin(dir) 作 vspeed，可反推屏幕 y 向下，但本卡不据此下结论。
 */

/* @0x193064 vmov s15, r1 —— 入口。s15 = dir（float 第一实参） */
/* @0x193068 push {r4, lr} */
/* @0x19306c vcmpe.f32 s15, #0 —— vcmpe.f32 dir, #0 */
/* @0x193070 mov r4, r0 */
/* @0x193074 vmrs APSR_nzcv, fpscr */
/* @0x193078 bpl 0x193090 <_ZN9CInstance12SetDirectionEf+0x2c> —— bpl：dir >= 0（NaN 无序也走这里）→ 跳过第一循环 */
/* @0x19307c vldr s14, [pc, #76] —— 池 0x1930d0 的 360.0f */
/* @0x193080 vadd.f32 s15, s15, s14 —— dir += 360.0f */
/* @0x193084 vcmpe.f32 s15, #0 */
/* @0x193088 vmrs APSR_nzcv, fpscr */
/* @0x19308c bmi 0x193080 <_ZN9CInstance12SetDirectionEf+0x1c> —— 仍为负 → 回环 */
/* @0x193090 vldr s14, [pc, #56] */
/* @0x193094 vcmpe.f32 s15, s14 —— vcmpe dir, 360.0f */
/* @0x193098 vmrs APSR_nzcv, fpscr */
/* @0x19309c ble 0x1930b0 <_ZN9CInstance12SetDirectionEf+0x4c> —— dir <= 360 → 出循环 */
/* @0x1930a0 vsub.f32 s15, s15, s14 —— dir -= 360.0f */
/* @0x1930a4 vcmpe.f32 s15, s14 */
/* @0x1930a8 vmrs APSR_nzcv, fpscr */
/* @0x1930ac bgt 0x1930a0 <_ZN9CInstance12SetDirectionEf+0x3c> —— 仍 > 360 → 回环 */
/* @0x1930b0 vmov r0, s15 —— 出循环时 dir ∈ [0,360] */
/* @0x1930b4 mov r1, #0 —— 第二实参 lo = 0 */
/* @0x1930b8 movt r1, #0x43b4 —— 第二实参 hi = 0x43b4 → 0x43B40000 = 360.0f（与池字同值，独立编码） */
/* @0x1930bc bl 0xb6790 <fmodf@plt> —— fmodf(d, 360.0f) @plt 0xb6790 */
/* @0x1930c0 str r0, [r4, #0xcc] —— +0xcc = direction（结果值域 [0,360)） */
/* @0x1930c4 mov r0, r4 —— r0 = this（尾跳的实参） */
/* @0x1930c8 pop {r4, lr} */
/* @0x1930cc b 0x192aa0 <_ZN9CInstance14Compute_Speed2Ev> —— 尾跳 Compute_Speed2 0x192aa0：+0xcc/+0xd0 → +0xe0/+0xe4 */
/* @0x1930d0 .word 0x43b40000 —— 非指令：0x43B40000 = 360.0f */
/* ══ §4 CInstance::SetPosition(float x, float y) 0x193e7c ═════════════════════
 * @func 0x193e7c 0x193ec0  size 68  17 条（17 指令，无池字；下一个符号 CInstance::AddTo_Speed 0x193ec0）
 * 级别: 正文（17/17。早退判据、两个写点、脏标记与尾调全钉；「不写哪些字段」也逐条对齐了 ctor/DoAStep 卡）
 * 符号: _ZN9CInstance11SetPositionEff → void CInstance::SetPosition(float x, float y)
 * 位置: CInstance::Dump 0x19363c 之后、CInstance::AddTo_Speed 0x193ec0 之前
 * 调用点: bl 直调 43 处 —— F_MoveWrap 0x108310/0x108334/0x108364、Command_Wrap 0x1c9750/0x1c9790/0x1c97d4、
 *         Command_InstancePlace 0x1ca734、Assign_Path 0x1940a0、Adapt_Path 0x194338、
 *         Motion_Linear_Step 0x19c9a8、Motion_Potential_* 等 ⇒ 所有「摆放/瞬移」都收在这里。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   只有当 x 或 y 与原值**位精确不等**时才落盘：写 +0xb4/+0xb8、置 +0x64 = 1、尾调 CollisionMarkDirty；
 *   两个都相等就地 bx lr 返回（不置脏）。**不写 xstart/ystart，也不写 xprevious/yprevious。**
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   void CInstance::SetPosition(float x, float y) {
 *     if (this->x == x && this->y == y) return;      // 0x193e8c..0x193ea4（vcmp + bne + bxeq lr）
 *     this->x = x;                                    // +0xb4（0x193eac）
 *     this->y = y;                                    // +0xb8（0x193eb0）
 *     this->[0x64] = 1;                               // 0x193eb8
 *     CollisionMarkDirty(this);                        // 尾调 0x1cc1d0（0x193ebc 的 b）
 *   }
 *
 * ── 已证（指令级）──────────────────────────────────────────────────────
 *  1. 早退判据是**精确相等**，没有容差：0x193e8c vcmp.f32 s13,s15（+0xb4 vs 新 x）→ bne 走写；
 *     x 相等才继续比 y（0x193e98 vldr s13,[+0xb8] → 0x193e9c vcmp → 0x193ea4 bxeq lr）。
 *     NaN 于是必然走写路径（无序 → Z=0 → bne）。
 *  2. 早退路径连 +0x64 都不置：位置没变就不标脏、不挂脏链 —— 这条让 CollisionMarkDirty 的调用次数
 *     直接等于「真实位移次数」，写同一坐标的重复调用是零成本。
 *  3. 只写两个字段：+0xb4、+0xb8。对照 ctor 卡字段表：+0xbc/+0xc0（xstart/ystart）与 +0xc4/+0xc8
 *     （xprevious/yprevious）在本函数锚点里一次都不出现 ⇒ 本函数不改变「起点」也不刷新「前值」。
 *  4. 前值的唯一维护点在 DoAStep（DoAStep 卡 ASTEP-005：0x1d3394..0x1d33d8 在每实例移动前
 *     写 [+0xc4]=[+0xb4]、[+0xc8]=[+0xb8]）。而 DoAStep 的移动本身也是调本函数
 *     （HandleInstanceMovement 0x1d1e30 SetPosition(x+hspeed, y+vspeed)）。⇒ 顺序是
 *     「prev ← 当前 → 本函数改坐标」，瞬移（Command_InstancePlace / Wrap / Assign_Path）则跳过 prev 更新。
 *  5. 尾巴与 §1 同构：mov r2,#1（0x193ea8）→ strb [+0x64]（0x193eb8）→ b 0x1cc1d0（0x193ebc）；
 *     差别是本函数**没有栈帧**（全节无 push/pop），所以没有「先 pop 再 b」那一步。
 *     CollisionMarkDirty 的返回值仍然直接回给本函数的调用者。
 *  6. 无 bl 调用（全节 0 个 bl），无表访问、无分配；17 条指令里 10 条是 VFP
 *     （vmov×2、vldr×2、vcmp×2、vmrs×2、vstr×2），其余 7 条是 mov/cmp/bne/bxeq/strb/b。
 *
 * ── open（本节）──────────────────────────────────────────────────────────
 *   · +0xc4/+0xc8 的读方没有枚举。能用指令推出「谁写」，推不出「谁读」；若某处用 (x - xprevious) 当
 *     本步位移量，瞬移后会出现一次大位移（碰撞穿透/路径偏差的候选解释）。本卡不宣称存在这种读者。
 *   · bbox 脏标记 + CollisionMarkDirty 之后，包围盒何时被重算（Compute_BoundingBox）在另一张卡；
 *     本卡只证「置脏与挂脏链」这一步。
 *   · +0x64 的语义名（bbox 脏位）取自 ctor/SetObjectIndex 卡，本卡只证写入位置与置位条件。
 */

/* @0x193e7c vmov s15, r1 —— 入口。s15 = 新 x */
/* @0x193e80 vldr s13, [r0, #180] —— 读当前 +0xb4 */
/* @0x193e84 mov r3, r0 —— r3 = this */
/* @0x193e88 vmov s14, r2 —— s14 = 新 y */
/* @0x193e8c vcmp.f32 s13, s15 —— vcmp 当前 x, 新 x（精确比较，无容差） */
/* @0x193e90 vmrs APSR_nzcv, fpscr */
/* @0x193e94 bne 0x193ea8 <_ZN9CInstance11SetPositionEff+0x2c> —— x 不等 → 直接写；相等才继续比 y */
/* @0x193e98 vldr s13, [r0, #184] —— 读当前 +0xb8 */
/* @0x193e9c vcmp.f32 s13, s14 —— vcmp 当前 y, 新 y */
/* @0x193ea0 vmrs APSR_nzcv, fpscr */
/* @0x193ea4 bxeq lr —— 两个都相等 → bx lr：不置脏、不挂脏链 */
/* @0x193ea8 mov r2, #1 —— r2 = 1（脏值） */
/* @0x193eac vstr s15, [r3, #180] —— +0xb4 = x */
/* @0x193eb0 vstr s14, [r3, #184] —— +0xb8 = y */
/* @0x193eb4 mov r0, r3 —— r0 = this（尾调实参） */
/* @0x193eb8 strb r2, [r3, #0x64] —— +0x64 = 1 */
/* @0x193ebc b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> —— 尾调 CollisionMarkDirty 0x1cc1d0（与 §1 同构） */
/* ══ §5 CInstance::GetImageNumber() 0x19357c ═════════════════════════════════
 * @func 0x19357c 0x1935c4  size 72  18 条（18 指令，无池字；下一个符号 CInstance::SetPathPosition 0x1935c4）
 * 级别: 正文（18/18。三条出口（非法精灵 / 非骨架 / 骨架）与尾跳全钉）
 * 符号: _ZN9CInstance14GetImageNumberEv → int CInstance::GetImageNumber()
 * 位置: CInstance::ChangeObjectIndex 0x193368 之后、CInstance::SetPathPosition 0x1935c4 之前
 * 调用点: bl 直调 5 处 —— VM::WriteInstanceBuiltInVariables 0xd9a78（导出 image_number 内建）、
 *         Instance_Animate 0x1d31b0/0x1d323c/0x1d3288（动画回绕）、GV_ImageNumber 0x1fa9ec
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   「当前精灵有多少帧」：精灵号非法 → 0；非骨架精灵 → sprite+0x18；骨架精灵 → 取/建 +0x88 的
 *   CSkeletonInstance 后尾调 FrameCount(0)。除可能 new 一个骨架实例外，不写任何实例字段。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   int CInstance::GetImageNumber() {
 *     if (!Sprite_Exists(this->sprite_index)) return 0;      // 0x193588..0x193590（popeq 直返 r0=0）
 *     CSprite* s = Sprite_Data(this->sprite_index);           // 0x193598
 *     if (s->[0x74] != 2) return s->count;                    // +0x18（0x19359c..0x1935ac）
 *     SkeletonAnimation(this);                                // 0x193158（保证 +0x88 存在）
 *     return CSkeletonInstance::FrameCount(0);                 // 尾跳 0xbe220，r1 = 0（0x1935b8/0x1935c0）
 *   }
 *
 * ── 已证（指令级）──────────────────────────────────────────────────────
 *  1. 非法精灵返回的不是 -1 而是 **0**：0x19358c cmp r0,#0 → 0x193590 popeq {r4,pc}，返回的 r0 正是
 *     Sprite_Exists 的 0。调用方 Instance_Animate 用它做回绕（0x1d31b0 后 cmp/bge），
 *     帧数为 0 时回绕条件退化 —— 这条与 §1 的「上界 0」是同一个约定。
 *  2. 非骨架路径是**直接读字段**（0x1935a8 ldr r0,[r0,#0x18] 后 pop 返回），不调任何函数；
 *     与 §1 的 0x193220 用同一偏移当上界，两节互证 +0x18 = 帧数。
 *  3. 骨架判定用 sprite+0x74 == 2（0x19359c/0x1935a0），与 SkeletonAnimation 0x193180/0x19318c
 *     的判定逐字相同 ⇒ 「精灵类型」这一个字节同时决定「有没有骨架」和「帧数从哪来」。
 *  4. 骨架路径先调 SkeletonAnimation（0x1935b4）而不是直接读 +0x88：因为 +0x88 可能为 0
 *     （ctor 清 0、SetSpriteIndex 换精灵时也会清 0），SkeletonAnimation 负责按需 new 出来，
 *     它自己也会判存在/类型，所以这里不需要再判一次。
 *  5. 尾跳而不是 bl：0x1935bc pop {r4,lr} → 0x1935c0 b 0xbe220，FrameCount 的返回值直接回给本函数
 *     的调用者；第 1 实参 r1 = 0（0x1935b8 mov r1,#0）。
 *  6. 唯一可能的副作用是 +0x88 被 new（operator new(0x34) + CSkeletonInstance ctor，见 SkeletonAnimation），
 *     除此之外没有一次 str/strb 落在实例上。
 *
 * ── open（本节）──────────────────────────────────────────────────────────
 *   · CSkeletonInstance::FrameCount(int) 的形参语义（0 = 第 0 条动画？0 = 当前动画？）未证；
 *     本卡只证「恒传 0」。
 *   · sprite+0x74 的枚举全集未知（只有 ==2 骨架这一值被三处独立用到）。
 *   · 非骨架精灵 +0x18 是否等于 SPRT 记录里的帧数（而非 atlas 页数）由 Sprite_Data 侧决定，本卡不证。
 */

/* @0x19357c push {r4, lr} */
/* @0x193580 mov r4, r0 */
/* @0x193584 ldr r0, [r0, #0x8c] —— 读 +0x8c sprite_index */
/* @0x193588 bl 0x1eee98 <_Z13Sprite_Existsi> —— Sprite_Exists 0x1eee98 */
/* @0x19358c cmp r0, #0 */
/* @0x193590 popeq {r4, pc} —— eq 分支直接弹栈返回，r0 仍是 0（非法精灵 → 0，不是 -1） */
/* @0x193594 ldr r0, [r4, #0x8c] —— 重读 sprite_index */
/* @0x193598 bl 0x1ef03c <_Z11Sprite_Datai> —— Sprite_Data 0x1ef03c */
/* @0x19359c ldr r3, [r0, #0x74] —— 精灵类型 sprite+0x74 */
/* @0x1935a0 cmp r3, #2 —— == 2 → 骨架精灵 */
/* @0x1935a4 beq 0x1935b0 <_ZN9CInstance14GetImageNumberEv+0x34> */
/* @0x1935a8 ldr r0, [r0, #0x18] —— 非骨架：直接返回 sprite+0x18（帧数，与 §1 的上界同址） */
/* @0x1935ac pop {r4, pc} */
/* @0x1935b0 mov r0, r4 —— 骨架路径：r0 = this */
/* @0x1935b4 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> —— SkeletonAnimation 0x193158（按需 new +0x88） */
/* @0x1935b8 mov r1, #0 —— FrameCount 第 1 实参 = 0 */
/* @0x1935bc pop {r4, lr} */
/* @0x1935c0 b 0xbe220 <_ZN17CSkeletonInstance10FrameCountEi> —— 尾跳 CSkeletonInstance::FrameCount 0xbe220 */
/* ══ §6 CInstance::GetTimer(int) 0x193134 ════════════════════════════════════
 * @func 0x193134 0x193148  size 20  5 条（5 指令，无池字；下一个符号 CInstance::SetTimer 0x193148，
 *       前一符号 CInstance::SetVspeed 0x193114）
 * 级别: 正文（5/5。界判、地址算式、越界返回值全部钉死 —— 这是全卡最短、也是唯一无调用的一节）
 * 符号: _ZN9CInstance8GetTimerEi → int CInstance::GetTimer(int i)
 * 位置: CInstance::SetVspeed 0x193114 之后、CInstance::SetTimer 0x193148 之前（alarm 访问对的前半）
 * 调用点: bl 直调 21 处 —— 其中 12 处在 VM::WriteInstanceBuiltInVariables 0xd9b44..0xd9dd8
 *         （逐项导出 alarm[0..11] 内建变量），另有 F_AlarmGet 0x115e6c、F_ActionSetAlarm 0x13e7c8 等
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   `i` 用**无符号**比较：0..11 命中则读 this + 0xf8 + 4·i，否则返回 -1。纯读，无写、无调用。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   int CInstance::GetTimer(int i) {
 *     if ((unsigned)i <= 11) return *(int*)((char*)this + 0xf8 + i*4);   // addls r1,r1,#62 → ldrls [r0,r1,lsl#2]
 *     return -1;                                                          // mvnhi r0,#0
 *   }
 *
 * ── 已证（指令级）──────────────────────────────────────────────────────
 *  1. 界判是**无符号**的：0x193134 cmp r1,#11 + 0x193138 addls / 0x19313c ldrls 用的是 LS
 *     （C==1 或 Z==1，即 unsigned i <= 11）。⇒ i == -1..-N 一律走越界分支返回 -1，
 *     不会因为「负索引 + 基址」读到 alarm 区之前的内存。这是本卡六个入口里唯一做无符号界判的。
 *  2. 地址算式是 (i + 62) * 4（0x193138 addls r1,r1,#62 → 0x19313c ldrls r0,[r0,r1,lsl #2]），
 *     即 0xf8 + 4i —— 与 ctor 卡「alarm 就是从 0xf8 起 12 个 int」逐字吻合。
 *  3. 越界返回 -1（0x193140 mvnhi r0,#0），不是 0、不是夹取。于是「索引非法」与「闹钟值就是 -1」
 *     在返回值上无法区分 —— 这是原版的取舍，调用方（F_AlarmGet 0x115e6c）拿不到额外信号。
 *  4. 12 项有三条独立来源：ctor 两个 12 次循环（0x1995f0 先清 0、0x1996d4 再填 -1）、本节 cmp #11 的界、
 *     VM::WriteInstanceBuiltInVariables 的 12 次调用（0xd9b44..0xd9dd8，步长 0x3c）。
 *     ⇒ 「alarm[0..11]」不是推断，是三处机器码的共识。
 *  5. 5 条指令里没有一次 str、没有一次 bl/blx、没有一次条件外跳（bx lr 是唯一出口）：
 *     读 alarm 不置脏、不触发碰撞、不改变任何状态。
 *  6. 调用方把返回值当**无符号**转 double（0xd9b58 vmov s15,r0 + 0xd9b60 vcvt.f64.u32），
 *     即导出内建变量时 -1 会变成 4294967295.0；本函数体内没有这种转换，它只返回 int。
 *
 * ── open（本节）──────────────────────────────────────────────────────────
 *   · alarm 的「-1 = 未激活」语义由 SetTimer/DoAStep 递减侧定义，本卡只证读取。
 *   · 调用方用 vcvt.f64.u32 是否在原版里造成可见的 4294967295 值（即 UI/存档里能否看到），未在原件上验证。
 */

/* @0x193134 cmp r1, #11 —— 界判：cmp i,#11 配 addls/ldrls ⇒ 无符号 i <= 11 */
/* @0x193138 addls r1, r1, #62 —— 偏移 (i + 62) * 4 = 0xf8 + 4i */
/* @0x19313c ldrls r0, [r0, r1, lsl #2] —— 读 this+0xf8+4i（alarm[i]） */
/* @0x193140 mvnhi r0, #0 —— unsigned i > 11 → 返回 -1 */
/* @0x193144 bx lr —— 唯一出口（纯读，无写无调用） */
