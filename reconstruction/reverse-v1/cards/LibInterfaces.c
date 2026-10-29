/* cally 逆向卡：库层接口卡 —— PCRE / Box2D / zlib（原版 libyoyo.so，ELF32 ARM，stripped）
 *
 * @card  三个第三方库在 libyoyo.so 里的**接口面**：入口地址、函数签名、调用边（谁调它/它调谁）、
 *        关键字段偏移、版本证据。范围只含四组入口：
 *          pcre_exec  0x279390（+ 其内部匹配核 0x26f1e8）
 *          b2World::SolveTOI 0x2c9ab4
 *          b2ParticleSystem::SolveZombie 0x2d660c
 *          inflate / deflate（本 so 内无实现，只有 PLT 桩）
 *
 * 级别: 骨架（接口级：只给入口地址/签名/调用边，本卡不含逐指令锚点）
 *        · 不贴逐条锚点表，不做全函数 CFG 复核；函数体只读到「入口 + 调用点 + 字段位移」够用为止
 *        · 已钉：入口地址与大小（.dynsym st_size 与下一符号对齐）、形参寄存器/栈落位、每一处直接
 *          bl 的目标、每一处 `ldr/str [this,#imm]` 的位移、以及三个库各自的版本证据
 *        · 未钉：函数内部状态机（除文中列出的块）、结构体字段的**名字**——凡按 Box2D 2.3.0 头文件
 *          命名的都标「推断」；位移本身是反汇编直接读到的，不是推断
 *
 * 身份:  libyoyo.so sha256 = 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        4,689,844 B；.text = 0x0b6fd0..0x31bb7c；.plt = 0xb64e8..0xb6fd0（231 个 JUMP_SLOT）
 *
 * ══ 库一览（本卡结论，逐条的出处见下文）═══════════════════════════════════
 *   库        形态            版本证据                                      入口
 *   PCRE      静态编进 .text  pcre_version() 返回**未替换模板**；符号面与     pcre_exec 0x279390
 *                             错误串指纹 = 8.34+ 谱系（精确小版本不可定）      （4408 B）
 *   Box2D     静态编进 .text  b2_version 对象 = {2,3,0}（12 B @0x479a6c）；   SolveTOI 0x2c9ab4（2980 B）
 *                             且 b2_maxTOIContacts = 32（ctor 实参 64/32/0）  SolveZombie 0x2d660c（3828 B）
 *   zlib      动态依赖        DT_NEEDED libz.so；编译期头版本 "1.2.3" 作为     inflate@plt 0xb69dc
 *             libz.so        version 实参传给 inflateInit_/deflateInit_      deflate@plt 0xb69ac
 *
 * ══ 实际读过的地址区间（本卡只对这些地址负责）══════════════════════════════
 *   头部/表：
 *     .dynsym 全表（llvm-readelf -sW，11,748 行；据此取 st_size/绑定/可见性）
 *     .rel.plt 全表（231 项，0x3f1c64 起）；.plt 0xb64e8..0xb6520、0xb69a0..0xb69f0
 *     .text 全段反汇编一次（32,436,894 B 文本），按函数区间切片统计调用点/分支：
 *       0x279390..0x27a4c8（4408 B / 1102 槽）、0x2c9ab4..0x2ca658（2980 B / 745 槽）、
 *       0x2d660c..0x2d7500（3828 B / 957 槽）
 *   PCRE：
 *     0x266c9c..0x266cac（pcre_version）、0x25ed64..0x25ee20（pcre_config）
 *     0x279390..0x2794c0（pcre_exec 序言/参数检查）、0x279700..0x279720、0x279c30..0x279cb0
 *       （内部匹配核第 2 个 bl）、0x279d90..0x279de0（pcre_free 间接调用）、
 *       0x27a200..0x27a290（pcre_malloc/pcre_free）、0x27a2e0..0x27a340（返回码/字面量池）、
 *       0x27a4b8..0x27a4c8（-6 出口）
 *     数据：0x357070（版本串）、0x3f76d4..0x3f76e0（pcre_stack_free/stack_malloc/pcre_free/
 *       pcre_malloc 四个全局函数指针槽）、GOT 0x3f0690 与 0x3f17ec
 *   Box2D：
 *     0x2c9ab4..0x2c9c60（SolveTOI 序言 + 候选链表首轮）、0x2c9ea0..0x2c9f30（b2Contact::Update 前）、
 *       0x2ca190..0x2ca270（b2Island::SolveTOI → 同步 → FindNewContacts）、
 *       0x2ca68c..0x2ca720 / 0x2ca760..0x2ca7f0（b2World::Step 里两个调用点）
 *     0x2d660c..0x2d6710（SolveZombie 序言 + 压缩循环）、0x2d71d0..0x2d7240（Free + 组清扫 + 收尾）
 *     0x2d4fbc..0x2d50c8（b2ParticleSystem ctor，抽样看字段初值）
 *     数据：0x479a6c（b2_version，12 B）
 *   zlib：
 *     0xb64e8..0xb6520（PLT0 + 头两项）、0xb69a0..0xb69f0（deflateInit_/deflate/deflateEnd/
 *       inflateInit_/inflate/inflateEnd 六个桩）
 *     0x201b90..0x201cb0（ZDecompressStream 的 inflateInit_/inflate）、
 *     0x202060..0x202120（ZCompressStream 的 deflateInit_）、0x1d28c8..0x1d2930（CheckLicense 的
 *       deflateInit_/deflate(Z_FINISH)/deflateEnd）
 *     数据：0x351028（"1.2.3"）
 *
 * ═══════════════════════════════════════════════════════════════════════
 * 一、PCRE —— pcre_exec 0x279390（4408 B，ARM，非 Thumb）
 * ═══════════════════════════════════════════════════════════════════════
 *
 * ── 版本证据（三条，互相独立）──────────────────────────────────────────
 *   V1. pcre_version（0x266c9c，16 B）是 3 条指令：
 *         0x266c9c ldr r0,[pc,#4]   → 字面量池 0x266ca8 = 0x000f03c8
 *         0x266ca0 add r0,pc,r0     → pc = 0x266ca8 ⇒ r0 = 0x357070
 *         0x266ca4 bx  lr
 *       0x357070 的内容是：
 *         "@PCRE_MAJOR@.@PCRE_MINOR@@PCRE_PRERELEASE@ @PCRE_DATE@"
 *       ⇒ 这不是版本号，是**没被 configure 替换的模板**。构建时 PCRE_MAJOR/MINOR/DATE 宏没定义，
 *         pcre_version() 会把模板原样返回给调用方。**任何靠 pcre_version() 读版本的游戏代码都会拿到
 *         这串垃圾**；靠它反推版本同样不行。
 *   V2. pcre_config（0x25ed64，188 B）的 switch 接受 selector 0..13（`cmp r0,#13; addls pc,pc,r0,lsl #2`
 *       + 14 项跳表），逐项返回值：
 *         0→1 (UTF8)  1→10 (NEWLINE=LF)  2→2 (LINK_SIZE)  3→10 (POSIX_MALLOC_THRESHOLD)
 *         4→0x989680 (MATCH_LIMIT=10,000,000)  5→1 (STACKRECURSE=1)  6→0 (UNICODE_PROPERTIES)
 *         7→0x989680 (MATCH_LIMIT_RECURSION)   8→0 (BSR)  9→0 (JIT=没有)
 *         10→返回 -3（selector 10 = PCRE_CONFIG_UTF16，pcre_config() 不接受）
 *         11→返回 0 且 *where=0（selector 11 = PCRE_CONFIG_JITTARGET，无 JIT ⇒ NULL）
 *         12→返回 -3（PCRE_CONFIG_UTF32，同上不接受）
 *         13→250（PCRE_CONFIG_PARENS_LIMIT）
 *       **selector 编号与 pcre 8.45 的 pcre.h 完全对齐**（8.45: JITTARGET=11、PARENS_LIMIT=13，
 *       10/12 是 UTF16/UTF32 槽位）；PCRE 8.34 才引入编译期括号嵌套上限。同 .rodata 有配套错误文本
 *       "parentheses are too deeply nested" 与
 *       "parentheses are too deeply nested (stack check)"。
 *   V3. 头魔数的双值检查：0x27944c..0x279474 先比 `*(u32*)code` 与 0x50435245（PCRE_MAGIC 的数值；
 *       小端存盘时字节序是 45 52 43 50，不是字面的 'PCRE'），命中走正常路径（0x2794b4 继续查 mode）；
 *       再比 0x45524350（字节序相反），命中直接 `mvn r0,#28` = -29；两者都不是则 `mvn r0,#3` = -4。
 *       这与 PCRE 8.x 的 PCRE_ERROR_BADMAGIC(-4) / PCRE_ERROR_BADENDIANNESS(-29) 一一对上。
 *   ⇒ 结论：**8.34 或更晚的 PCRE 8.x 谱系**；精确小版本在本 .so 里不可定（V1 是模板）。JIT 没编进去。
 *
 * ── 签名（AAPCS，8 个形参 = 4 寄存器 + 4 栈）────────────────────────────
 *     int pcre_exec(const pcre *code, const pcre_extra *extra,
 *                   const char *subject, int length, int startoffset,
 *                   int options, int *ovector, int ovecsize);
 *
 *   帧 = push {r4-r11,lr}(36) + sub sp,#316 ⇒ 0x160；入口栈参落在 [sp+0x160..0x16c]。
 *     r0  → code      （0x2793a4 mov r4,r0；后续 [r4] 读魔数、[r4,#0xc] 读模式位）
 *     r1  → extra     （0x279394 mov r7,r1；本卡未追它全部用途）
 *     r2  → subject   （0x2793b8 mov r6,r2）
 *     r3  → length
 *     [sp+0x160] → startoffset（0x279430 ldr r11；与 length 做上下界检查）
 *     [sp+0x164] → options    （0x2793c0 ldr r5；0x2793dc 用 0xE20F5A6F 掩码预检）
 *     [sp+0x168] → ovector    （0x279400 ldr r11）
 *     [sp+0x16c] → ovecsize   （0x279404 ldr r12）
 *
 * ── 入口校验与返回码（全部在本卡读过的块里）────────────────────────────
 *   0x27944c..0x279474：magic 检查（见 V3）→ 通过后 0x2794b4 `ldr r2,[r4,#0xc]; tst r2,#1`，
 *     模式位 bit0 为 0 ⇒ 0x27a334 `mvn r0,#27` = -28（BADMODE）。
 *   0x279400..0x27942c：
 *     · ovecsize < 0                    ⇒ 0x27a304 `mvn r0,#14` = -15（BADCOUNT）
 *     · length   < 0                    ⇒ 0x27a30c `mvn r0,#31` = -32（BADLENGTH）
 *   0x2793d0..0x2793d8 / 0x27947c..0x2794ac：**-999 魔术释放路径**
 *     subject == NULL && length == -999，且 startoffset 也 == -999 时，本函数不匹配任何东西，
 *     直接把 r1..r3 清零、栈上压 0/0/1、r0 = sp+312，bl 内部的 0x26f1e8 后返回。
 *     （PCRE 用这个入口释放递归栈；这里能证的是「进了 0x26f1e8，r0=sp+312，其余 6 个实参是常量 0/0/0/0/0/1」。）
 *   0x27970c：`mvn r0,#1` = -2（NULL，ovector/ovecsize 组合非法时）
 *   0x27a4c0：`mvn r0,#5` = -6（NOMEMORY，临时 ovector 分配失败时）
 *
 * ── 关键字段偏移（code 指针）───────────────────────────────────────────
 *     code+0x00  u32   魔数：0x50435245（正常）/ 0x45524350（字节序反 → -29）—— 0x279450/0x279460 直接比较
 *     code+0x0C  u32   模式/标志字，bit0 = PCRE_MODE —— 0x2794b8 `tst r2,#1`，为 0 返回 -28
 *     code+0x20  u16   捕获组数上限（0x279778 `ldrh r1,[r4,#32]`；决定临时工作区大小，推断 top_bracket）
 *   （本卡没有再往下拆 code 的其它字段；那属于 pcre_compile 的卡。）
 *
 * ── 它调谁（全函数 98 条分支里筛出的外部调用，逐个地址）────────────────
 *     0x2794ac  bl 0x26f1e8   匿名匹配核（-999 释放路径，见上）
 *     0x27967c  bl 0x2668f4   _pcre_valid_utf
 *     0x279b80  bl 0x25f9fc   _pcre_is_newline
 *     0x279c74  bl 0x26f1e8   匿名匹配核（主匹配路径；r3=2，第 5 参 = sp+128）
 *     0x279d38  bl 0x25f9fc   _pcre_is_newline
 *     0x279dc8  blx r3        **pcre_free**（GOT 0x3f0690 → 0x3f76dc → free）
 *     0x27a1a0  bl 0x25fbc0   _pcre_was_newline
 *     0x27a224  blx r3        **pcre_malloc**（GOT 0x3f17ec → 0x3f76e0 → malloc）
 *     0x27a278  blx r3        **pcre_free**
 *     0x27a2f4  bl 0x25f9fc   _pcre_is_newline
 *     0x27a32c  bl 0xb65bc    memcpy@plt
 *     0x27a404  bl 0x25fbc0   _pcre_was_newline
 *   函数指针链已物化：0x2793a0 `ldr r11,[pc,#0xf94]` + 0x2793b4 `add r11,pc,r11` ⇒ r11 = 0x3f1c58
 *   （= DT_PLTGOT），存 [sp+0x14]；三处 blx 都是 `ldr r3,[r12,r3]` 再 `ldr r3,[r3]` 的二级间接，
 *   即**用户可替换的 pcre_malloc/pcre_free 全局量**，不是直接调 malloc/free。
 *
 * ── 临时工作区（接口级要点）────────────────────────────────────────────
 *   入口 0x2797b0 `bge 0x27a200` 的分支上，r1 来自 0x279778 `ldrh r1,[r4,#32]` —— 即 code+0x20
 *   的 u16（推断 top_bracket，捕获组数）。0x27a200..0x27a224 把它算成
 *     r9 = top_bracket+1 → r9 = 3*r9 → r1 = 4*r9 = 12*(top_bracket+1) 字节
 *   交给 pcre_malloc，返回值存 [sp+0x8c]，为 0 直接 -6。
 *   ⇒ 临时 ovector 是按**模式自带的捕获组数**分配（3 int/组），不是按调用方 ovecsize 分配；
 *     调用方 ovecsize 只在 0x279420 做下界校验。
 *
 * ── 谁调它（全库 bl 扫描，6 个调用点 / 5 个函数）───────────────────────
 *     0x248770  JS_String_prototype_split_RegEx   (_Z31JS_String_prototype_split_RegEx...)
 *     0x248a6c  同上（同函数第二个分支）
 *     0x24f36c  DoRegExpExec                       (_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i)
 *     0x256264  JS_String_prototype_search
 *     0x2573f0  JS_RegExp_prototype_exec
 *     0x257850  JS_RegExp_prototype_test
 *   ⇒ GML 的 regexp_* 与 JS 的 String/RegExp 原型共 5 个入口落到同一个 pcre_exec。
 *
 * ── 与 0x26f1e8 的关系（只写接口层）────────────────────────────────────
 *   0x26f1e8 在 .dynsym 里**没有符号**（0x26e568 的 pcre_dfa_exec 之后、0x279390 的 pcre_exec 之前）。
 *   asm/functions.tsv 记该起点函数体 41,380 B（0x26f1e8..0x27938c）；cards/anon_26f1e8.c 只详卡了前 3524 B。
 *   pcre_exec 的两条 bl（0x2794ac / 0x279c74）都落在它的入口，说明它是 pcre_exec 的匹配核，
 *   而不是另一个导出 API。本卡不重复它的 7 参协议。
 *
 * ═══════════════════════════════════════════════════════════════════════
 * 二、Box2D —— SolveTOI 0x2c9ab4（2980 B）+ SolveZombie 0x2d660c（3828 B）
 * ═══════════════════════════════════════════════════════════════════════
 *
 * ── 版本证据 ───────────────────────────────────────────────────────────
 *   b2_version 是导出对象（.dynsym：OBJECT GLOBAL，st_size 12，st_value 0x479a6c）；
 *   .data 文件偏移 0x478a6c（第二 LOAD 段 vaddr-0x1000）读出三个 int：
 *     02 00 00 00 | 03 00 00 00 | 00 00 00 00  ⇒  {2, 3, 0}
 *   交叉证据：SolveTOI 构造 b2Island 时实参是 64 / 32 / 0（0x2c9ae8 `mov r1,#64`、
 *   0x2c9af0 `mov r2,#32`、0x2c9af4 `mov r3,#0`），正是 Box2D 源码里的
 *   `b2Island island(2 * b2_maxTOIContacts, b2_maxTOIContacts, 0, &m_stackAllocator,
 *    m_contactManager.m_contactListener)`，即 **b2_maxTOIContacts = 32**（2.3.x 默认值）。
 *   再交叉：粒子系统在册（SolveZombie 存在且被 Step 调），2.3.0 的 particles 分支特征。
 *   ⇒ **Box2D 2.3.0**（不是 2.4：2.4 已把 particles 拆出去）。
 *
 * ── SolveTOI：签名与调用边 ─────────────────────────────────────────────
 *     void b2World::SolveTOI(const b2TimeStep& step);      // r0 = this(world), r1 = &step
 *   帧：push {r4-r11,lr} + vpush {d8,d9,d10} + sub sp,#316。
 *
 *   它调谁（全函数 38 条分支里的 22 个外部调用点）：
 *     0x2c9af8  b2Island::b2Island(int,int,int,b2StackAllocator*,b2ContactListener*)  [0x2e1130]
 *                 r0=sp+128, r1=64, r2=32, r3=0, [sp]=world+0x44, [sp+4]=*(world+0x19220)
 *     0x2c9c80  b2DistanceProxy::Set(const b2Shape*,int)  [0x2c3b74]
 *     0x2c9c98  同上（B 侧）
 *     0x2c9ce0  b2TimeOfImpact(b2TOIOutput*, const b2TOIInput*)  [0x2e0930]
 *     0x2c9e08/18、0x2c9ebc/cc、0x2ca2ec/fc、0x2ca340/50、0x2ca3c0/d0、0x2ca478/88
 *               sinf@plt / cosf@plt 各 6 次（0xb6580 / 0xb658c）—— 旋转步的三角函数
 *     0x2c9f18  b2Contact::Update(b2ContactListener*)  [0x2cc1ec]
 *     0x2ca098  同上（第二处）
 *     0x2ca1d0  b2Island::SolveTOI(const b2TimeStep&,int,int)  [0x2e12c4]
 *     0x2ca218  b2Body::SynchronizeFixtures()  [0x2c72cc]
 *     0x2ca258  b2ContactManager::FindNewContacts()  [0x2c84d8]
 *     0x2ca4e0  b2Island::~b2Island()  [0x2e11d8]
 *
 *   谁调它：**唯一** 0x2ca7d8，在 b2World::Step（0x2ca68c，472 B）里；同一 Step 在 0x2ca784
 *   先调 b2ParticleSystem::Solve，再在 0x2ca7d8 调 SolveTOI，两段计时分别写
 *   world+0x1925c / world+0x19270（b2Profile 推断）。
 *
 *   关键字段偏移（位移已证；名字按 2.3.0 头文件推断）：
 *     world+0x044        b2StackAllocator —— 作为 ctor 第 4 参（&m_stackAllocator）；
 *                        SolveZombie 侧 *(this+0xD4)+0x44 再调 Allocate/Free，两处互证
 *     world+0x19214      候选链表头（0x2c9b1c `ldr r4,[lr,r3]`，r3=0x19214）
 *     节点+0x00C         next（0x2c9b84 `ldr r4,[r4,#0xc]`）—— 本卡不替它定名
 *     节点+0x004         flags（0x2c9b94 `tst r3,#4`；0x2c9ba8 `tst r3,#0x20`）
 *     节点+0x030/+0x034  两个对象指针，各 `[+0x2c]` 字节非 0 即跳过（推断 fixtureA/fixtureB）
 *     节点+0x080         int，与 8 比较（0x2c9b9c..0x2c9ba4；推断 m_toiCount）
 *     节点+0x084         float，与 1.0 取最小（0x2c9b70..0x2c9b80；推断 m_toi）
 *     world+0x19220      b2ContactListener*（ctor 第 5 参；0x2c9ef4 处又作为 Update 的 r1）
 *     world+0x19253      bool（0x2c9b08 `ldrb`，为 0 才走正常路径；推断 m_stepComplete）
 *     world+0x19274      b2ParticleSystem 基址 —— 见下节（Step 的 0x2ca6bc/0x2ca778 给出）
 *
 * ── SolveZombie：签名与调用边 ──────────────────────────────────────────
 *     void b2ParticleSystem::SolveZombie();                // r0 = this(粒子系统)
 *   帧：push {r4-r11,lr} + sub sp,#28。
 *
 *   关键字段偏移（全部是本函数直接读写到的位移）：
 *     this+0x024  int     粒子数 m_count（0x2d660c `ldr r1,[r0,#0x24]`；收尾 0x2d71e4 回写新计数）
 *     this+0x030  u32*    flags 数组（0x2d66a4），一粒子 4 B；bit 0x2 = zombie，bit 0x200 = 需要
 *                         destructionListener 回调（0x2d6664 `tst r2,#512`）
 *     this+0x038  b2Vec2* 位置数组（0x2d66c4，一粒子 8 B，`lsl #3` 索引）
 *     this+0x040  b2Vec2* 速度数组（0x2d66d4，同上）
 *     this+0x050  u32*    4 B/粒子数组（0x2d670c）
 *     this+0x05C  u32*    4 B/粒子数组（0x2d66f0）
 *     this+0x0A8  b2ParticleGroup* 组链表头（0x2d71f0）
 *     组+0x018    next 组（0x2d7210）
 *     组+0x04C    字节标志，bit 0x2 ⇒ DestroyParticleGroup（0x2d720c..0x2d7220）
 *     this+0x0D4  b2World*（0x2d6618 与 0x2d71e0 两处；前者 +0x44 = b2StackAllocator）
 *
 *   它调谁（全函数 133 条分支里只有 4 个外部调用）：
 *     0x2d6628  b2StackAllocator::Allocate(int)      [0x2e0f44]  参数 = m_count*4
 *     0x2d6688  blx r3（虚调用，vtable+0x14）        —— 只对 flags&0x200 的粒子触发：
 *                                                      r0 = *(world+0x19244)（一个带 vtable 的对象，
 *                                                      本卡**未定名**），r1 = 粒子索引 r7。
 *                                                      位掩码与 vtable 槽位已证；"SayGoodbye" 只是推断
 *     0x2d71ec  b2StackAllocator::Free(void*)        [0x2e0ffc]
 *     0x2d7220  b2ParticleSystem::DestroyParticleGroup(b2ParticleGroup*) [0x2d5874]
 *
 *   谁调它：**唯一** 0x2db5b4，在 b2ParticleSystem::Solve（0x2db370，816 B）里。
 *   Solve 自身被 b2World::Step 在 0x2ca784 调用，实参 r0 = world+0x19274
 *   （0x2ca6bc `add r8,r4,#102400` + 0x2ca778 `add r0,r8,#628`）⇒ **b2ParticleSystem 内嵌在
 *   b2World + 0x19274**，SolveZombie 的 this 就指向那里。
 *
 * ═══════════════════════════════════════════════════════════════════════
 * 三、zlib —— inflate / deflate（本 so 内无实现，只有 PLT 桩）
 * ═══════════════════════════════════════════════════════════════════════
 *
 * ── 形态 ───────────────────────────────────────────────────────────────
 *   .dynsym 里 inflate / deflate / inflateInit_ / deflateInit_ / inflateEnd / deflateEnd /
 *   inflateInit2_ / deflateInit2_ / inflateReset / deflateReset 全是 UND；
 *   DT_NEEDED 有 libz.so。⇒ 实现不在本 .so，运行时由系统 libz.so 提供；本 .so 只有跳板。
 *
 * ── 入口（PLT 桩地址 + 对应 GOT 槽，均由 .rel.plt 顺序与 .plt 反汇编核对）──
 *     deflateInit_@plt  0xb69a0   GOT 0x3f1df0
 *     deflate@plt       0xb69ac   GOT 0x3f1df4
 *     deflateEnd@plt    0xb69b8   GOT 0x3f1df8
 *     inflateInit_@plt  0xb69d0   GOT 0x3f1e00
 *     inflate@plt       0xb69dc   GOT 0x3f1e04
 *     inflateEnd@plt    0xb69e8   GOT 0x3f1e08
 *   PLT0 在 0xb64e8（`str lr,[sp,#-4]!` / `ldr lr,[pc,#4]` / `add lr,pc,lr` /
 *   `ldr pc,[lr,#8]!`），每项 12 B：`add r12,pc,#0x300000; add r12,r12,#0x3b000;
 *   ldr pc,[r12,#imm]!`。
 *
 * ── 版本证据：编译期头版本 = "1.2.3" ──────────────────────────────────
 *   zlib 的 init 宏把 ZLIB_VERSION 作为形参传进去，所以字符串常量会留在调用方：
 *     ZDecompressStream 0x201be0 `ldr r1,[pc,#0x198]`（槽 0x201d80 = 0x0014f418）
 *                       0x201c08 `add r1,pc,r1`（pc = 0x201c10）⇒ r1 = 0x351028
 *     ZCompressStream   0x2020ac `ldr r2,[pc,#0x144]`（槽 0x2021f8 = 0x0014ef58）
 *                       0x2020c8 `add r2,pc,r2`（pc = 0x2020d0）⇒ r2 = 0x351028
 *     0x351028 内容 = "1.2.3"
 *   ⇒ **本 .so 是按 zlib 1.2.3 的头编译的**（不是运行库版本；运行库版本由系统 libz.so 决定，
 *     本 .so 里读不到）。zlib 的 inflateInit_/deflateInit_ 只比较 version[0]（'1'），
 *     所以它和 Android 上任意 1.2.x 的 libz.so 都能配上——这是 zlib 的 ABI 约定，不是本 .so 的事实。
 *
 * ── sizeof(z_stream) = 56 ─────────────────────────────────────────────
 *   inflateInit_(strm, version, stream_size) 的 stream_size 用 r2 传：
 *     0x201c10 `mov r2,#56`（0x38）
 *   deflateInit_(strm, level, version, stream_size) 的 stream_size 用 r3 传：
 *     0x2020b0 `mov r3,#56`
 *   ⇒ 32 位 z_stream 是 56 B；调用方硬编码这个数，和运行库不匹配时 zlib 会返回 Z_VERSION_ERROR。
 *
 * ── 三个调用点 ─────────────────────────────────────────────────────────
 *   ZDecompressStream(CStream&, CStream&)  0x201bbc，460 B：
 *     0x201c38 bl inflateInit_@plt     （r0=z_stream@sp+12，r1="1.2.3"，r2=56）
 *     0x201cac bl inflate@plt          （r1=0，Z_NO_FLUSH）
 *     之后 0x201cb4 `cmn r0,#4` + 0x201cbc `blt 0x201d00`：r0 < -4 的错误码走错误出口，其余继续喂输入
 *   ZCompressStream(CStream&, CStream&, int)  0x20208c，368 B：
 *     0x2020e4 bl deflateInit_@plt     （r2="1.2.3"，r3=56）
 *     0x202180 bl deflate@plt
 *   CheckLicense  0x1d23a0，2816 B（许可校验里的一次性压缩）：
 *     0x1d2910 bl deflateInit_@plt
 *     0x1d291c bl deflate@plt          （r1=4，Z_FINISH）
 *     0x1d2924 bl deflateEnd@plt
 *   ⇒ 全库只有 1 个 inflate 调用点、2 个 deflate 调用点；解压只走 ZDecompressStream。
 *
 * ═══════════════════════════════════════════════════════════════════════
 * 四、三条已证事实（跨库，各给可复核的地址）
 * ═══════════════════════════════════════════════════════════════════════
 *   F1. PCRE 的版本字符串在这份 .so 里是**未替换的构建模板**，不是版本号。
 *       pcre_version 0x266c9c 三条指令解到 0x357070，内容是
 *       "@PCRE_MAJOR@.@PCRE_MINOR@@PCRE_PRERELEASE@ @PCRE_DATE@"；同一份 .rodata 里同时存在
 *       "parentheses are too deeply nested" / "...(stack check)" 两条 8.34 才有的错误文本，
 *       且 pcre_config 的 selector 13 返回 250（括号嵌套上限）⇒ 只能定到「8.34+ 的 8.x 谱系」，
 *       定不到小版本。构建时没跑 PCRE 的 configure（或没定义 PCRE_MAJOR/MINOR/DATE）。
 *
 *   F2. zlib 是**动态**依赖，编译期头版本被硬编码成 "1.2.3"，且 z_stream 按 56 B 传。
 *       证据：DT_NEEDED libz.so；inflate/deflate 均为 UND + 6 个 PLT 桩（0xb69a0..0xb69e8）；
 *       ZDecompressStream 0x201c08 与 ZCompressStream 0x2020c8 两处 pc 相对寻址都解到 0x351028
 *       的 "1.2.3"；0x201c10 `mov r2,#56` / 0x2020b0 `mov r3,#56`。
 *
 *   F3. Box2D 是 2.3.0：b2_version 三字 {2,3,0} 在 0x479a6c（12 B，.dynsym OBJECT）；
 *       SolveTOI 0x2c9ae8..0x2c9af4 给 b2Island ctor 传 64/32/0，即 b2_maxTOIContacts=32；
 *       粒子系统内嵌在 b2World+0x19274（Step 0x2ca6bc + 0x2ca778），SolveZombie 由
 *       b2ParticleSystem::Solve 0x2db5b4 唯一调用。
 *
 * ═══════════════════════════════════════════════════════════════════════
 * 五、open（本卡明确不做）
 * ═══════════════════════════════════════════════════════════════════════
 *   · pcre_exec 的内部状态机、回溯栈布局、JIT 分支：不做（0x26f1e8 已有独立卡，只覆盖前 3524 B）
 *   · pcre_compile / pcre_study / pcre_dfa_exec 的接口：不做
 *   · SolveTOI 的 TOI 求解数学（b2TimeOfImpact / b2Island::SolveTOI 内部）：不做
 *   · SolveZombie 压缩后各数组的一致性（只证「按同一索引把 5 个数组从 r7 搬到 r10」）
 *   · zlib 运行库版本：本 .so 内不可读（要设备上 zlibVersion()，本卡不碰设备）
 *   · 结构体字段名的最终确认：位移已证，名字按 Box2D 2.3.0 头文件推断，未逐字段对照 DWARF
 *     （本 .so stripped，没有 DWARF 可对）
 */
