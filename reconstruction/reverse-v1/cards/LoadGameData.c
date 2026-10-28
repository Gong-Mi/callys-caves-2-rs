/* cally 逆向卡：LoadGameData（原版 libyoyo.so，armv7）
 * @func 0x1ddce4 0x1de74c  size 2668  667 条（646 条指令 + 0x1de6fc..0x1de74c 内联 literal pool 21 字，
 *       池字被 objdump 译成 andseq/eoreq/… 不是指令，卡内按 objdump 原文保留并标注）
 * 级别: 正文（顶层六段的控制流、31 个 tag 的分发表、5 条失败路径、尾部的「名字→id」解析、返回值语义
 *             全部逐条钉住；未钉的是初始化段里三个全局对象的**身份**与 GEN7/GENL 写 700 的用途，
 *             见文末 open —— 它们不改变本函数的控制流，但改变对「谁是谁」的命名）
 * 符号: _Z12LoadGameDataPvj → int LoadGameData(void* pWAD, unsigned int size)
 * ABI : softfp；两个入参只落栈（sp+0xc = pWAD，sp+0x18 = size），全函数无 vpush/无浮点
 * 返回: int。0 = 有未知块或 pWAD == NULL；1 = 全部块都认识（**尺寸不符也返回 1**，见「失败路径」第 3 条）
 * 调用者: RunnerLoadWad 0x1df59c（唯一；尾跳，见 RunnerLoadWad 卡）← DoTheWork 0x2a16dc 的启动序
 * 同层: Header_Load 0x1dcf94、Option_Load 0x19f534、Extension_Load 0xf5eb8、Language_Load(CLangMan) 0x27a4c8、
 *       Sound_Load 0x21f630 / Audio_Load 0x219048、Sound_WAVs 0x21f9d4 / Audio_WAVs 0x219680、
 *       AudioGroup_Load 0x218c94、Sprite_Load 0x1effbc、Background_Load 0xc3350、Path_Load 0x1a7e74、
 *       Script_Load 0x1e01e4、GLOB_Load 0x1dcf64、Shader_Load 0x1e1cd8、Font_Load 0xfa0d4、
 *       TimeLine_Load 0x1f2770、Object_Load 0x19ea7c、Room_Load 0x1b4cd8、Code_Patch 0x1dc8c4、
 *       FUNC_Load 0x1dcdf0、Texture_Load 0x1dda28、EmbeddedImages_Load 0x176830、
 *       Part_SetupEmbeddedImages 0x1a58d8、Code_Variable_Init 0xd1d80、Code_Variable_Find_Set 0xd2f20、
 *       Code_Variable_Find 0xd1d60、Code_Function_Find 0xce158、Variable_BuiltIn_Find 0x1f3a5c、
 *       YYStrDup 0xdb8c8、YYObjectBase::Alloc 0x19198c、MemoryManager::ReAlloc 0x27cedc /
 *       Free 0x27c2d0、CCameraManager::Clean 0x16dd34、CreateDefaultCamera 0x1afef0、JS_ResourceSetup 0x23f93c、
 *       memLogPushContext 0x27b948 / memLogPopContext 0x27b94c、Console::Output（虚表 +0xc）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────
 *   把整份 game.droid（FORM + 24 个块）交给它：先打一行 "initialise everything!"、把 10 个子系统 Init 一遍、
 *   重建代码表的名字索引，然后从 +8 开始**扫块链**——每块 8 字节头（4 字节块名 + 4 字节块长）+
 *   裸负载、无对齐无 padding——按块名一路 if/else 分发到 22 个装载器（外加 TPAG 只存指针），
 *   最后把变量/函数表里的名字解析成 id，并把「有没有不认识的块」当返回值。
 *
 * ── 入参从哪来（唯一的喂法）───────────────────────────────────────
 *   RunnerLoadWad 0x1df59c 里两条 GOT 取指给出全部答案（见该卡，逐条已钉）：
 *       r0 = *(void**)0x544b78   ← WAD 基址
 *       r1 = *(u32*)0x544b74     ← WAD 字节数（与上一个全局紧邻，形如 {u32 size; void* data;}）
 *   也就是说本函数**不打开文件、不做 IO、不知道文件名**：内存映像早已在别处就位，
 *   本函数只负责「解析 + 装配」。
 *
 * ── 顶层六段（地址即锚点）──────────────────────────────────────────
 *   §1 0x1ddd24..0x1ddd48  10 个 Init：Sound / Sprite / Background / Path / Script / Font / TimeLine /
 *                          Object / Room / Option —— 顺序固定，全在解析之前
 *   §2 0x1ddd4c..0x1ddd5c  门：*(u8*)0x5428e8 非 0 → CCameraManager::Clean + CreateDefaultCamera（重载路径）
 *   §3 0x1ddd60..0x1dddbc  代码表闸：*(0x544be0)（为 0 → 变体 0x1de488）→ *(0x544c64) → code->+0xc
 *                          变量数 → Code_Variable_Init(条数, 变量数, 0)。**两条路都要过 *(0x544c64)**
 *   §4 0x1dddc0..0x1ddf18  名字索引：变量逐条 Code_Variable_Find_Set(name,-1,i) → 函数名逐条 YYStrDup
 *                          去重进 0x47a19c 的可增长指针数组 → 「id == -1」的项用 Variable_BuiltIn_Find 补
 *                          ★ 本二进制里 §4 不可达：0x544c64 全库无写者（见硬事实 9）
 *   §5 0x1ddf1c..0x1ddfa4  全局实例：静态结构 0x536da8 预置 1/2/0/3 → YYObjectBase::Alloc →
 *                          *(0x544be0) 与 *(0x544bdc) 同指该对象、+0x38=3、+0xc=0；*(0x544c60) 是回调，非空则调
 *   §6 0x1ddfa8..0x1de244  **块链**：头校验（size-8 == [pWAD+4]）→ 循环 → 分发 → 直至 size 用完
 *   §7 0x1ddfcc..0x1de058  收尾：变量表 Code_Variable_Find、函数表 Code_Function_Find 回填 id，返回 r10
 *   另 0x1de060..0x1de0b0 是 §4 数组扩容的辅助块；0x1de488/0x1de4c0/0x1de6a4 是 §3 的三个入口变体。
 *
 * ── §6 的分发表：31 个 tag（块名按 LE 读成 u32 进 r6，块长进 r5）────────────────
 *   tag   u32         处理点      动作                                                      game.droid
 *   ----  ----------  ----------  --------------------------------------------------------  ----------
 *   GEN8  0x384e4547  0x1de618    Header_Load(payload,size,base)                             588 B
 *   GEN7  0x374e4547  0x1de5c8    先 *(u32*)0x544bd4 = 700，再 Header_Load                    无
 *   GENL  0x4c4e4547  0x1de5c8    同 GEN7                                                    无
 *   OPTN  0x4e54504f  0x1de604    Option_Load 0x19f534                                       80 B
 *   LANG  0x474e414c  0x1de358    CLangMan::Language_Load 0x27a4c8                            12 B
 *   EXTN  0x4e545845  0x1de5f0    Extension_Load 0xf5eb8                                     224 B
 *   SOND  0x444e4f53  0x1de568    *(u8*)0x755314==0 ? Sound_Load 0x21f630 : Audio_Load 0x219048   2164 B（54 条）
 *   AGRP  0x50524741  0x1de3e8    *(u8*)0x755314!=0 ? AudioGroup_Load 0x218c94 : 忽略          4 B（0 条）
 *   SPRT  0x54525053  0x1de4d8    Sprite_Load 0x1effbc                                       360676 B（178）
 *   BGND  0x444e4742  0x1de444    Background_Load 0xc3350                                    196 B（8）
 *   PATH  0x48544150  0x1de594    Path_Load 0x1a7e74                                         4 B（0）
 *   SCPT  0x54504353  0x1de4ec    Script_Load 0x1e01e4                                       4 B（0）
 *   GLOB  0x424f4c47  0x1de38c    GLOB_Load 0x1dcf64                                         4 B（0）
 *   SHDR  0x52444853  0x1de52c    Shader_Load 0x1e1cd8                                       4 B（0）
 *   FONT  0x4e544f46  0x1de2f0    Font_Load 0xfa0d4                                          12324 B（6）
 *   TMLN  0x4e4c4d54  0x1de2a8    TimeLine_Load 0x1f2770                                     4 B（0）
 *   OBJT  0x544a424f  0x1de540    Object_Load 0x19ea7c                                       97244 B（191）
 *   ROOM  0x4d4f4f52  0x1de62c    Room_Load 0x1b4cd8（→ CRoom::LoadFromChunk，见该卡）        3237708 B（114）
 *   TPAG  0x47415054  0x1de654    **不解析**：*(void**)0x544bc4 = payload                     46572 B（1791）
 *   CODE  0x45444f43  0x1de554    Code_Patch 0x1dc8c4（逐条就地改 code 字节）                 1337380 B（1354）
 *   VARI  0x49524156  ——          忽略（变量表由 CODE 片自带）                               41772 B（691）
 *   FUNC  0x434e5546  0x1de640    FUNC_Load 0x1dcdf0                                         22972 B（99）
 *   STRG  0x47525453  ——          忽略（字符串表）                                           99144 B（3210）
 *   TXTR  0x52545854  0x1de3c4    Texture_Load 0x1dda28                                      1882924 B（4）
 *   AUDO  0x4f445541  0x1de500    *(u8*)0x755314==0 ? Sound_WAVs : Audio_WAVs(…,0)            20956772 B（29）
 *   EMBI  0x49424d45  0x1de42c    EmbeddedImages_Load 0x176830 + Part_SetupEmbeddedImages     无
 *   DAFL  0x4c464144  ——          忽略（包内长度 0，连分发都进不去，见失败路径 5）             0 B
 *   PSPS  0x53505350  ——          忽略（PSP 遗留）                                            无
 *   STAT  0x54415453  ——          忽略                                                       无
 *   RASP  0x50534152  ——          忽略（名字未钉，game.droid 里没有）                          无
 *   HELP  0x504c4548  ——          忽略                                                       无
 *   其他  ——          0x1de1f8    错误控制台 "unknown Chunk %s:%d" + 清 sp+0x2c（返回值变 0）
 *
 *   判据来源：31 处 cmp r6 / movw+movt 常量对（0x1de194..0x1de6e8），u32 = 四字符按文件字节序读，
 *   例：'G','E','N','8' → 0x384e4547；'S','H','D','R' → 0x52444853。块名同时以 4 字节写进 [sp+0x30]
 *   并在 [sp+0x34] 补 NUL，所以打印出来的就是文件里的四个字符。
 *
 * ── game.droid 实测（assets/game.droid，28,098,976 B，sha256 见 apk/identity.md）──────────
 *   0x000000  "FORM" + u32 28,098,968（= 文件长 - 8）
 *   0x000008  GEN8 588 / 0x00025c OPTN 80 / 0x0002b4 LANG 12 / 0x0002c8 EXTN 224 /
 *   0x0003b0  SOND 2164 / 0x000c2c AGRP 4 / 0x000c38 SPRT 360676 / 0x00058d24 BGND 196 /
 *   0x00058df0 PATH 4 / 0x00058dfc SCPT 4 / 0x00058e08 GLOB 4 / 0x00058e14 SHDR 4 /
 *   0x00058e20 FONT 12324 / 0x0005be4c TMLN 4 / 0x0005be58 OBJT 97244 / 0x00073a3c ROOM 3237708 /
 *   0x0038a190 DAFL 0 / 0x0038a198 TPAG 46572 / 0x0039578c CODE 1337380 / 0x004dbfb8 VARI 41772 /
 *   0x004e62ec FUNC 22972 / 0x004ebcb0 STRG 99144 / 0x00504000 TXTR 1882924 / 0x006cfb34 AUDO 20956772
 *   ⇒ 24 块，末块结束地址 = 28,098,976 = 文件长，**恰好铺满、无尾块、无对齐空档**；每块长度都是 4 的倍数，
 *     所以「r7 += 块长，不做 4 字节对齐」这条在本包上不会踩坑（换包可能踩）。
 *   ⇒ 头部只有 8 字节：4 字节 "FORM" + 4 字节长度，**没有 IFF 的 form-type 字段**；GEN8 本身就是第一个块。
 *     本函数从不校验 "FORM" 魔数（全函数没有 0x4d524f46 常量），只校验 data[4] == size-8。
 *
 * ── 「哪些资源进哪张表」（每个 *_Load 内部形状一致：payload[0] = 条数 → 全局条数 + 4 B/条指针表）──
 *   SPRT → 精灵表：0x1effe0 ldr r12,[payload] 读条数 → 0x1f0008 str r12,[r4] 写全局条数；随后按条数开表
 *          （0x1effcc mov r3,#228 疑为记录长度，未展开）
 *   OBJT → 对象表：0x19ea84 ldr r3,[payload] 读条数 → 0x19ea98 str r3,[r8] 写全局条数；循环里
 *          0x19eab8 mov r0,#220 → 0x19ead8 operator new（每条记录 220 B）
 *   BGND → 背景表：0xc3358 读条数 → 0xc3394 写全局；MemoryManager::SetLength(&表, 条数*4, 文件, 92) 两张
 *   TXTR → 纹理页表：0x1dda30 读条数（带 532676608 溢出闸）→ new[](条数*4) → 0x1dda60 写全局指针
 *   ROOM → 房间表：Room_Load 0x1b4cd8 里 new(292) + CRoom::LoadFromChunk，CRoom 卡已钉「两张平行数组：
 *          CRoom* 与房间路径串」
 *   TPAG 不进表：只把 payload 基址存进 0x544bc4（1791 条 page 记录留给纹理侧按需取）；
 *          真正的像素数据在 TXTR 块（4 张页）→ Texture_Load
 *   CODE 不进表：Code_Patch 逐条把 code 段就地打补丁（0x1dc914 → Code_Patch(ptr,len,base)）
 *   VARI 不进表（忽略）；FUNC → FUNC_Load 自己的函数名表；STRG/DAFL/PSPS/STAT/RASP/HELP 全忽略
 *   ⇒ 一句话：**资源表 = SPRT/OBJT/BGND/TXTR/ROOM/FONT/SOND/AUDO/PATH/SCPT/TMLN/SHDR/EXTN 各自的
 *     count+指针数组；TPAG 只是指针，CODE 是就地补丁，VARI/STRG 不参与装载。**
 *
 * ── 失败路径（全部 5 条，逐条有锚）────────────────────────────────
 *   1. pWAD == NULL → 0x1ddfb0 beq 0x1de4cc → r0 = [sp+0xc] = 0，**唯一直接返回 0 的闸**
 *   2. size <= 8 → 0x1de0dc bls 0x1ddfc8 → 跳过整条块链，返回值仍是 1
 *   3. data[4] != size-8 → 0x1ddfc4 beq 不成立 → 0x1ddfc8，同上，**不打印任何错误**
 *   4. 单个块不认识 → 0x1de1f8：错误控制台 "unknown Chunk %s:%d"（槽 0x3ed71c → 0x3eb70c，与 DoTheWork
 *      失败路同一个对象）+ sp+0x2c = 0；**循环继续**，装载其它块，最后返回 0
 *   5. 块长 == 0 → 0x1de190 beq 0x1de22c：连 tag 都不判（game.droid 的 DAFL 走这条）
 *   ★ 2/3 与 4 的语义互斥：非 IFF 包返回 1（"成功"），只有 NULL 与未知块才 0。所以 DoTheWork 的
 *     `RunnerLoadWad()==0` 判据抓不住「包根本不是 WAD」——那种情况会带着空表继续跑。
 *
 * ── 已证硬事实（可直接引用）──────────────────────────────────────
 *   1. 顺序固定：10 个 Init（Sound→Sprite→Background→Path→Script→Font→TimeLine→Object→Room→Option）
 *      →（§3/§4 代码表名字索引：本二进制不可达，见第 9 条）→ 全局实例 → 块链 → §7 名字回填。
 *      任何块装载器都在 Init 之后才被调用。
 *   2. 块链零校验：不认识 "FORM"、不校验块名合法性、不校验块长是否越过 size（只有循环条件 size > offset），
 *      不校验块长是否 4 对齐。唯一的头校验是 data[4] == size-8。
 *   3. 每块三件套：Console::Output("Process Chunk: %s   %d\n", 块名, 块长) → memLogPushContext(块名) →
 *      分发 → memLogPopContext()。日志与内存记账一一对应，所以「哪块吃掉了内存」可对账。
 *   4. 块名比较是 32 位整数比较（LE），不是 strcmp；块名缓冲 4 字节 + NUL 在 [sp+0x34]。
 *   5. 音源走哪套由 *(u8*)0x755314 决定：0 = Sound_/Sound_WAVs（旧 libopenal 路），非 0 = Audio_/Audio_WAVs
 *      （新路）；AGRP 只在非 0 时才调 AudioGroup_Load，否则整块丢掉。
 *   6. GEN7/GENL 是旧头，处理点与 GEN8 共用 Header_Load，但先把常量 700 写进 *(u32*)0x544bd4。
 *   7. 返回值只表达「块名都认识」：r10 初始 1（0x1de0e4），任一未知块清 0（0x1de200），
 *      正常从 0x1de23c 取出、0x1de054 返回。
 *   8. 尾部的名字解析是**无条件**的（除 pWAD == NULL）：所以「非 IFF 包」那条路也会跑完变量/函数回填。
 *   9. §3/§4 在这份 .so 里是**死代码**：两条路的闸都是 *(0x544c64)，而全库没有任何指令写 0x544c64
 *      （rel.dyn 13,432 条里指向它的 GOT 槽只有 0x3edb48 一个，本函数只用它读），所以它恒 0：
 *      *0x544be0==0 → 0x1de488 → *(0x544c64)==0 → 0x1de6a4 → §5；
 *      *0x544be0!=0 → 0x1ddd8c → *(0x544c64)==0 → 0x1de4c0 → §5。
 *      ⇒ Code_Variable_Init / Find_Set / YYStrDup 去重 / Variable_BuiltIn_Find 补丁（含 0x1de060..0x1de0b0
 *      的数组扩容）在启动路径上一次都不跑，真正干活的只有 §7 的 Code_Variable_Find / Code_Function_Find。
 *
 * ── open（不影响控制流，影响命名）────────────────────────────────
 *   1. §3/§5 的三个全局指针（0x544c64 = 代码表对象、0x544be0 = 「全局对象」、0x544bdc 同指）到底是
 *      CCode / CCodeGM / YYObjectBase 哪种类型：只钉到字段用法（+0xc 变量数、+0x14 变量数组、
 *      +0x18 函数数组、+0x38=3、+0xc=0）与 Alloc 的三个实参（条数, 0x00ffffff, false）。
 *   2. *(u32*)0x544bd4 = 700 的用途：只在 GEN7/GENL 写，怀疑是「WAD 版本 7.00」，但全库没有第二个读者被认出。
 *   3. 静态结构 0x536da8 的四个字段（+0x68=1、+0xc0=2、+0x10=0、+0x118=3）语义未钉。
 *   4. 可增长数组 0x47a19c 的字段名（条数@0、容量@4、增量@8、数据@0xc）；扩容用的文件串是
 *      "jni/../jni/yoyo/../../../Files/Platform/cARRAY_CLASS.h"、行号 0x11b=283。
 *   5. 块名 RASP / PSPS / STAT / HELP 的原始含义（本包没有这些块，只能证「认识且不处理」）。
 *   6. 0x544b74/0x544b78 这对全局的写入方（全 .so 只有 RunnerLoadWad 读，见该卡 open）。
 *
 * ── 段注 ────────────────────────────────────────────────────────
 */
/* @0x1ddce4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 帧：68 B 局部 + 9 个 callee-saved */
/* @0x1ddce8 sub sp, sp, #68 */
/* @0x1ddcec ldr r7, [pc, #0xa08] —— 池字 0x213f5c → r7 = 0x3f1c58（本函数的 GOT 锚） */
/* @0x1ddcf0 ldr r3, [pc, #0xa08] */
/* @0x1ddcf4 add r7, pc, r7 */
/* @0x1ddcf8 str r0, [sp, #0xc] —— [sp+0xc] = arg0 = WAD 基址（0x1de4cc 用它返回 0） */
/* @0x1ddcfc str r1, [sp, #0x18] —— [sp+0x18] = arg1 = WAD 字节数 */
/* @0x1ddd00 ldr r3, [r7, r3] —— GOT 0x3efb24 → 0x3eb6b8（控制台指针槽） */
/* @0x1ddd04 ldr r1, [pc, #0x9f8] —— 池字 0x173aa0（配合 0x1ddd0c 的 add） */
/* @0x1ddd08 ldr r3, [r3] */
/* @0x1ddd0c add r1, pc, r1 —— 串址 = 0x1ddd14 + 0x173aa0 = 0x3517b4 */
/* @0x1ddd10 str r3, [sp, #0x14] —— [sp+0x14] = 控制台对象 */
/* @0x1ddd14 ldr r3, [r3] —— obj->[0] 取虚表 */
/* @0x1ddd18 ldr r0, [sp, #0x14] */
/* @0x1ddd1c ldr r3, [r3, #0xc] —— [vtable+0xc] = Console::Output */
/* @0x1ddd20 blx r3 —— Output("initialise everything!\n")：进入函数第一件事就是这行 trace */

/* ── §1 十个子系统 Init（0x1ddd24..0x1ddd48，10 条 bl）────────────────────────
 *   Sound → Sprite → Background → Path → Script → Font → TimeLine → Object → Room → Option。
 *   顺序是硬编码的调用序，不是表驱动；每个都无参数、返回 void。这段跑在**任何**块装载之前，
 *   所以任何 *_Load 都能假定自己的子系统已就绪。Room_Init 0x1b4bc4 紧邻 Room_Load 0x1b4cd8
 *   （同一函数群，CRoom 卡已钉 Room_Load 的行为）。若 §2 的相机门成立，Clean/CreateDefaultCamera 也在这一段里
 *   跟着跑（见 0x1de0b4），但仍在块链之前。
 */
/* @0x1ddd24 bl 0x21f2e4 <_Z10Sound_Initv> —— Sound_Init() */
/* @0x1ddd28 bl 0x1eebbc <_Z11Sprite_Initv> —— Sprite_Init() */
/* @0x1ddd2c bl 0xc329c <_Z15Background_Initv> —— Background_Init() */
/* @0x1ddd30 bl 0x1a7ca8 <_Z9Path_Initv> —— Path_Init() */
/* @0x1ddd34 bl 0x1dff7c <_Z11Script_Initv> —— Script_Init() */
/* @0x1ddd38 bl 0xf9fb4 <_Z9Font_Initv> —— Font_Init() */
/* @0x1ddd3c bl 0x1f25b4 <_Z13TimeLine_Initv> —— TimeLine_Init() */
/* @0x1ddd40 bl 0x19e908 <_Z11Object_Initv> —— Object_Init() */
/* @0x1ddd44 bl 0x1b4bc4 <_Z9Room_Initv> —— Room_Init() */
/* @0x1ddd48 bl 0x19f2d0 <_Z11Option_Initv> —— Option_Init()（第 10 个） */

/* ── §2 重载门：*(u8*)0x5428e8（GOT 0x3ed92c）──────────────────────────────
 *   非 0 → 0x1de0b4：CCameraManager::Clean(*(0x48f78c)) + CreateDefaultCamera()，然后落回 0x1ddd60。
 *   即「已经不是第一次装载」时先把相机管理器清干净再建默认相机，避免房间相机残留。
 *   这个字节谁置位未钉（open）；本函数只读一次。
 */
/* @0x1ddd4c ldr r3, [pc, #0x9b4] —— GOT 0x3ed92c → 0x5428e8（重载门字节） */
/* @0x1ddd50 ldr r3, [r7, r3] */
/* @0x1ddd54 ldrb r3, [r3] —— ldrb：0 = 首次装载 */
/* @0x1ddd58 cmp r3, #0 */
/* @0x1ddd5c bne 0x1de0b4 <_Z12LoadGameDataPvj+0x3d0> —— 非 0 → 0x1de0b4 相机重载 */

/* ── §3 代码表与变量数（三个入口变体：0x1ddd60 / 0x1de488 / 0x1de4c0）────────────
 *   主线：&0x544be0（全局对象指针槽）→ 若 *(&) == 0 走 0x1de488；
 *         否则 &0x544c64（代码表对象槽）→ [sp+8]，&0x544b4c（计数）→ r9，
 *         code = *(0x544c64)，code->+0xc = 变量条数；条数 <= 0 → 0x1de2f8（只取计数不走 Init）。
 *   0x1de488（*0x544be0 == 0）：改用 *(0x544c64) 的 +0x8 当条数；两个都空 → 0x1de6a4 直接去 §5。
 *   共同出口 0x1ddd9c：r3 = code->+0xc（变量条数）→ 写进 *(0x544b48) → Code_Variable_Init(条数, 变量数, 0)。
 *
 *   ★ 这段在本二进制里**跑不到干活的那一半**：两个变体都要先解 *(0x544c64)，而 0x544c64 全库无写者
 *     （唯一指向它的 GOT 槽 0x3edb48 只被本函数读），所以恒 0 →
 *       变体 A（*0x544be0 != 0，0x1ddd8c）→ 0x1de4c0 → §5
 *       变体 B（*0x544be0 == 0，0x1de498）→ 0x1de6a4 → §5
 *     0x544be0 唯一的写入点也在本函数 §5（0x1ddf6c），所以首次调用时它同样是 0 → 走变体 B。
 *     ⇒ Code_Variable_Init / Find_Set / YYStrDup / Variable_BuiltIn_Find 这一整套（§4）是遗留路径，
 *       启动装载时一次都不执行；名字→id 的实际工作全在 §7（块链之后）。
 */
/* @0x1ddd60 ldr r3, [pc, #0x9a4] —— &0x544be0（全局对象指针槽） */
/* @0x1ddd64 ldr r3, [r7, r3] */
/* @0x1ddd68 str r3, [sp, #0x10] */
/* @0x1ddd6c ldr r3, [r3] */
/* @0x1ddd70 cmp r3, #0 —— *(0x544be0) == 0 → 0x1de488 */
/* @0x1ddd74 beq 0x1de488 <_Z12LoadGameDataPvj+0x7a4> */
/* @0x1ddd78 ldr r2, [pc, #0x990] —— GOT 0x3edb48 → &0x544c64（代码表对象槽）→ [sp+8] */
/* @0x1ddd7c ldr r3, [pc, #0x990] */
/* @0x1ddd80 ldr r2, [r7, r2] */
/* @0x1ddd84 str r2, [sp, #0x8] */
/* @0x1ddd88 ldr r9, [r7, r3] —— r9 = &0x544b4c（计数 1） */
/* @0x1ddd8c ldr r3, [r2] —— r3 = *(0x544c64) = 代码表对象 */
/* @0x1ddd90 cmp r3, #0 */
/* @0x1ddd94 ldr r0, [r9] —— r0 = *(0x544b4c) */
/* @0x1ddd98 beq 0x1de4c0 <_Z12LoadGameDataPvj+0x7dc> */
/* @0x1ddd9c ldr r3, [r3, #0xc] —— code->+0xc = 变量条数 */
/* @0x1ddda0 cmp r3, #0 */
/* @0x1ddda4 ble 0x1de2f8 <_Z12LoadGameDataPvj+0x614> —— 条数 <= 0 → 0x1de2f8 */
/* @0x1ddda8 ldr r2, [pc, #0x968] —— GOT 0x3edd1c → &0x544b48（计数 2） */
/* @0x1dddac mov r1, r3 */
/* @0x1dddb0 ldr r8, [r7, r2] */
/* @0x1dddb4 str r3, [r8] —— *(0x544b48) = 变量条数 */
/* @0x1dddb8 mov r2, #0 */
/* @0x1dddbc bl 0xd1d80 <_Z18Code_Variable_Initiii> —— Code_Variable_Init(条数, 变量数, 0) */

/* ── §4a 变量名 → 槽位（逐条 Code_Variable_Find_Set(name, -1, i)）—— 死代码，见 §3 末尾 ★ ───────
 *   r5 = code->+0x14（变量记录数组，4 B/条）；i = 0..条数-1；记录 +0 = 名字指针，
 *   Find_Set 的第 3 实参就是 i，返回后由被调函数把 +4 写成槽号。
 *   0x1de6f4 是内层「同名槽已存在」的收尾（r1 = 记录指针）。
 */
/* @0x1dddc0 ldr r12, [sp, #0x8] */
/* @0x1dddc4 ldr r2, [r8] */
/* @0x1dddc8 ldr r3, [r12] */
/* @0x1dddcc cmp r2, #0 —— r5 = code->+0x14（变量记录数组） */
/* @0x1dddd0 ldr r5, [r3, #0x14] */
/* @0x1dddd4 ble 0x1dde10 <_Z12LoadGameDataPvj+0x12c> */
/* @0x1dddd8 sub r5, r5, #4 */
/* @0x1ddddc mov r4, #0 */
/* @0x1ddde0 ldr r3, [r5, #0x4]! —— 逐条取记录 */
/* @0x1ddde4 mov r2, r4 */
/* @0x1ddde8 mvn r1, #0 */
/* @0x1dddec add r4, r4, #1 */
/* @0x1dddf0 ldr r0, [r3] */
/* @0x1dddf4 bl 0xd2f20 <_Z22Code_Variable_Find_SetPKcii> —— Code_Variable_Find_Set(名字, -1, i) */
/* @0x1dddf8 ldr r3, [r8] */
/* @0x1dddfc cmp r3, r4 */
/* @0x1dde00 bgt 0x1ddde0 <_Z12LoadGameDataPvj+0xfc> */
/* @0x1dde04 ldr r12, [sp, #0x8] */
/* @0x1dde08 ldr r3, [r12] */
/* @0x1dde0c ldr r5, [r3, #0x14] */

/* ── §4b 函数名去重 + 拷贝进可增长数组 0x47a19c ─────────────────────────────
 *   数组头：+0 条数、+4 容量、+8 增量、+0xc 数据指针（4 B/条）。
 *   每条：名字 → YYStrDup（复制一份自有串），再看表里有没有同指针/同名（0x1dde80..0x1ddea4 的
 *   线性扫描），没有就追加；容量不够走 0x1de07c..0x1de0b0 的扩容（容量 += 增量 → ReAlloc）。
 *   扩容失败（ReAlloc 返回 0）走 0x1de414：Free 旧块、条数/容量清零。
 */
/* @0x1dde10 ldr r3, [r9] */
/* @0x1dde14 cmp r3, #0 */
/* @0x1dde18 ble 0x1ddecc <_Z12LoadGameDataPvj+0x1e8> */
/* @0x1dde1c ldr r3, [pc, #0x8f8] —— GOT 0x3edba4 → &0x47a19c（可增长指针数组） */
/* @0x1dde20 sub r6, r5, #4 */
/* @0x1dde24 ldr r12, [pc, #0x8f4] —— 池字 0x16f4c4 → 配合 0x1dde2c 得文件串 0x34d2f8 */
/* @0x1dde28 mov r5, #0 */
/* @0x1dde2c add r12, pc, r12 */
/* @0x1dde30 str r12, [sp, #0x1c] —— [sp+0x1c] = "…/Platform/cARRAY_CLASS.h"（ReAlloc 的文件实参） */
/* @0x1dde34 ldr r4, [r7, r3] */
/* @0x1dde38 ldr r3, [r6, #0x4]! */
/* @0x1dde3c ldr r0, [r3] —— 名字指针 */
/* @0x1dde40 bl 0xdb8c8 <_Z8YYStrDupPKc> —— YYStrDup(名字) → 自有副本 */
/* @0x1dde44 ldm r4, {r11, lr} */
/* @0x1dde48 cmp lr, #0 */
/* @0x1dde4c mov r10, r0 */
/* @0x1dde50 ldrle r0, [r4, #0xc] —— 数组条数 <= 0 → 直接放第 0 格 */
/* @0x1dde54 ble 0x1de060 <_Z12LoadGameDataPvj+0x37c> */
/* @0x1dde58 cmp r11, #0 —— 容量 <= 0 → 0x1ddeac 直接写 */
/* @0x1dde5c ldrle r1, [r4, #0xc] */
/* @0x1dde60 ble 0x1ddeac <_Z12LoadGameDataPvj+0x1c8> */
/* @0x1dde64 ldr r0, [r4, #0xc] */
/* @0x1dde68 ldr r3, [r0] */
/* @0x1dde6c cmp r3, #0 */
/* @0x1dde70 addne r2, r0, #4 */
/* @0x1dde74 movne r3, #0 */
/* @0x1dde78 bne 0x1dde8c <_Z12LoadGameDataPvj+0x1a8> */
/* @0x1dde7c b 0x1de6f4 <_Z12LoadGameDataPvj+0xa10> —— 首格为空 → 0x1de6f4（r1 = r0） */
/* @0x1dde80 ldr r12, [r1] */
/* @0x1dde84 cmp r12, #0 */
/* @0x1dde88 beq 0x1ddeac <_Z12LoadGameDataPvj+0x1c8> */
/* @0x1dde8c add r3, r3, #1 */
/* @0x1dde90 mov r1, r2 */
/* @0x1dde94 cmp r3, lr */
/* @0x1dde98 add r2, r2, #4 */
/* @0x1dde9c beq 0x1de060 <_Z12LoadGameDataPvj+0x37c> */
/* @0x1ddea0 cmp r3, r11 */
/* @0x1ddea4 bne 0x1dde80 <_Z12LoadGameDataPvj+0x19c> */
/* @0x1ddea8 add r1, r0, r3, lsl #2 */
/* @0x1ddeac str r10, [r1] —— 写入槽位 */
/* @0x1ddeb0 ldr r3, [r9] —— 条数 +1 */
/* @0x1ddeb4 add r5, r5, #1 */
/* @0x1ddeb8 cmp r3, r5 */
/* @0x1ddebc bgt 0x1dde38 <_Z12LoadGameDataPvj+0x154> */
/* @0x1ddec0 ldr r12, [sp, #0x8] */
/* @0x1ddec4 ldr r3, [r12] */
/* @0x1ddec8 ldr r5, [r3, #0x14] */

/* ── §4c 内置变量 id 补丁 ────────────────────────────────────────────
 *   遍历一段记录链（记录 +0 = 名字、+4 = id），id == 0xffffffff 的项用 Variable_BuiltIn_Find(名字)
 *   换成内置变量槽号。这一段与 §4a 的区别：4a 走 code 表（自定义变量），4c 走「内置变量」链。
 */
/* @0x1ddecc cmp r5, #0 —— 记录 +0 = 名字、+4 = id */
/* @0x1dded0 beq 0x1ddf1c <_Z12LoadGameDataPvj+0x238> */
/* @0x1dded4 ldr r4, [r5] */
/* @0x1dded8 cmp r4, #0 */
/* @0x1ddedc beq 0x1ddf1c <_Z12LoadGameDataPvj+0x238> */
/* @0x1ddee0 add r5, r5, #4 */
/* @0x1ddee4 b 0x1ddefc <_Z12LoadGameDataPvj+0x218> */
/* @0x1ddee8 cmp r5, #0 */
/* @0x1ddeec beq 0x1ddf1c <_Z12LoadGameDataPvj+0x238> */
/* @0x1ddef0 ldr r4, [r5], #4 */
/* @0x1ddef4 cmp r4, #0 */
/* @0x1ddef8 beq 0x1ddf1c <_Z12LoadGameDataPvj+0x238> */
/* @0x1ddefc ldr r3, [r4, #0x4] */
/* @0x1ddf00 cmn r3, #1 */
/* @0x1ddf04 bne 0x1ddee8 <_Z12LoadGameDataPvj+0x204> */
/* @0x1ddf08 ldr r0, [r4] —— Variable_BuiltIn_Find(名字) */
/* @0x1ddf0c bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x1ddf10 cmp r5, #0 —— 回写 id（覆盖 -1） */
/* @0x1ddf14 str r0, [r4, #0x4] */
/* @0x1ddf18 bne 0x1ddef0 <_Z12LoadGameDataPvj+0x20c> */

/* ── §5 全局实例（YYObjectBase）─────────────────────────────────────
 *   静态结构 0x536da8（GOT 0x3edc68）先预置四格：+0x68=1、+0xc0=2、+0x10=0、+0x118=3；
 *   然后 YYObjectBase::Alloc(r0=max(条数,*(r8)), 0x00ffffff, false)（r1 由 mvn #-16777216 得 0x00ffffff）。
 *   新对象：*(0x544be0) = obj、*(0x544bdc) = obj、obj+0x38 = 3、obj+0xc = 0；
 *   最后 *(0x544c60) 若不是 0 就当回调调一次：callback(0, &obj)（实参在 [sp+0x30]）。
 */
/* @0x1ddf1c ldr r0, [r9] */
/* @0x1ddf20 ldr r3, [pc, #0x7fc] */
/* @0x1ddf24 mov r5, #0 —— r5 = 0 */
/* @0x1ddf28 ldr lr, [r8] —— lr = *(r8) = 条数 */
/* @0x1ddf2c mov r12, #1 */
/* @0x1ddf30 mov r2, r5 */
/* @0x1ddf34 mvn r1, #-16777216 */
/* @0x1ddf38 ldr r3, [r7, r3] */
/* @0x1ddf3c cmp r0, lr —— r0 = max(r0, 条数) */
/* @0x1ddf40 movlt r0, lr */
/* @0x1ddf44 mov r4, #3 */
/* @0x1ddf48 mov lr, #2 */
/* @0x1ddf4c str r12, [r3, #0x68] —— 静态结构 +0x68 = 1 */
/* @0x1ddf50 str lr, [r3, #0xc0] —— +0xc0 = 2 */
/* @0x1ddf54 str r5, [r3, #0x10] —— +0x10 = 0 */
/* @0x1ddf58 str r4, [r3, #0x118] —— +0x118 = 3 */
/* @0x1ddf5c bl 0x19198c <_ZN12YYObjectBase5AllocEjib> —— YYObjectBase::Alloc(条数, 0x00ffffff, false) */
/* @0x1ddf60 ldr r12, [sp, #0x10] */
/* @0x1ddf64 ldr r1, [pc, #0x7bc] */
/* @0x1ddf68 ldr r2, [pc, #0x7bc] */
/* @0x1ddf6c str r0, [r12] —— *(0x544be0) = 新对象 */
/* @0x1ddf70 mov r3, r0 */
/* @0x1ddf74 str r4, [r0, #0x38] —— obj+0x38 = 3 */
/* @0x1ddf78 ldr r1, [r7, r1] —— GOT 0x3edcb0 → &0x544bdc */
/* @0x1ddf7c str r5, [r0, #0xc] —— obj+0xc = 0 */
/* @0x1ddf80 str r0, [r1] —— *(0x544bdc) = 同一对象 */
/* @0x1ddf84 ldr r2, [r7, r2] —— GOT 0x3ee250 → &0x544c60（回调指针槽） */
/* @0x1ddf88 ldr r2, [r2] */
/* @0x1ddf8c cmp r2, r5 —— 回调为空 → 0x1ddfa8 */
/* @0x1ddf90 beq 0x1ddfa8 <_Z12LoadGameDataPvj+0x2c4> */
/* @0x1ddf94 add r4, sp, #64 */
/* @0x1ddf98 mov r0, r5 */
/* @0x1ddf9c str r3, [r4, #-0x10]! —— 实参放到 [sp+0x30] */
/* @0x1ddfa0 mov r1, r4 */
/* @0x1ddfa4 blx r2 —— callback(0, &obj) */

/* ── §6.0 头校验与 chunk 循环入口 ─────────────────────────────────────
 *   r12 = [sp+0xc] = pWAD：NULL → 0x1de4cc（返回 0）。
 *   r3 = [pWAD+4]（FORM 长度字段）；r12 = size；r2 = size-8；相等才进循环（0x1de0d0）。
 *   不等 → 0x1ddfc8：r10 = 1、走 §7 尾部，**一块都不装**（失败路径 3）。
 *   0x1de0d0..0x1de0dc：size <= 8 → 0x1ddfc8；否则 [sp+0x34] = 0（块名缓冲的 NUL）。
 */
/* @0x1ddfa8 ldr r12, [sp, #0xc] —— r12 = pWAD */
/* @0x1ddfac cmp r12, #0 */
/* @0x1ddfb0 beq 0x1de4cc <_Z12LoadGameDataPvj+0x7e8> —— pWAD == NULL → 0x1de4cc 返回 0 */
/* @0x1ddfb4 ldr r3, [r12, #0x4] —— r3 = [pWAD+4] = FORM 长度字段 */
/* @0x1ddfb8 ldr r12, [sp, #0x18] */
/* @0x1ddfbc sub r2, r12, #8 —— r12 = size */
/* @0x1ddfc0 cmp r2, r3 —— r2 = size-8 */
/* @0x1ddfc4 beq 0x1de0d0 <_Z12LoadGameDataPvj+0x3ec> —— 相等 → 0x1de0d0 进块链 */
/* @0x1ddfc8 mov r10, #1 —— 非 IFF 包/尺寸不符：r10 = 1，跳过块链 */
/* @0x1ddfcc ldr r3, [pc, #0x75c] —— GOT 0x3edbc0 → 0x47f295（verbose 字节） */
/* @0x1ddfd0 ldr r3, [r7, r3] */
/* @0x1ddfd4 ldrb r3, [r3] */
/* @0x1ddfd8 cmp r3, #0 */
/* @0x1ddfdc bne 0x1de0c8 <_Z12LoadGameDataPvj+0x3e4> */

/* ── §7 收尾：名字 → id 回填（两条路共用：正常装载完 0x1de244 与「非 IFF 包」0x1ddfc8）──
 *   若 *(sp+8) 非空：r5 = obj+0x14（变量记录数组），逐条 Code_Variable_Find(名字) → 记录 +4；
 *   再 r6 = obj+0x18（函数记录数组），逐条 Code_Function_Find(名字, &id) → 记录 +4。
 *   之后 0x1de054：r0 = r10，add sp,#68，pop 返回。r10 = 1 表示「块名全认识」。
 *   0x1ddfcc..0x1ddfdc 的 verbose 闸：*(u8*)0x47f295 非 0 才调 0x1de0c8 JS_ResourceSetup()，否则直落 §7。
 */
/* @0x1ddfe0 ldr r12, [sp, #0x8] —— &0x544c64（代码表对象槽） */
/* @0x1ddfe4 ldr r3, [r12] */
/* @0x1ddfe8 cmp r3, #0 */
/* @0x1ddfec beq 0x1de054 <_Z12LoadGameDataPvj+0x370> —— 对象为空 → 0x1de054 直接返回 */
/* @0x1ddff0 ldr r5, [r3, #0x14] —— r5 = obj+0x14（变量记录数组） */
/* @0x1ddff4 ldr r4, [r5] */
/* @0x1ddff8 cmp r4, #0 */
/* @0x1ddffc beq 0x1de020 <_Z12LoadGameDataPvj+0x33c> */
/* @0x1de000 ldr r0, [r4] */
/* @0x1de004 bl 0xd1d60 <_Z18Code_Variable_FindPKc> —— Code_Variable_Find(名字) */
/* @0x1de008 str r0, [r4, #0x4] —— 回填槽号 +4 */
/* @0x1de00c ldr r4, [r5, #0x4]! */
/* @0x1de010 cmp r4, #0 */
/* @0x1de014 bne 0x1de000 <_Z12LoadGameDataPvj+0x31c> */
/* @0x1de018 ldr r12, [sp, #0x8] */
/* @0x1de01c ldr r3, [r12] */
/* @0x1de020 ldr r6, [r3, #0x18] —— r6 = obj+0x18（函数记录数组） */
/* @0x1de024 ldr r5, [r6] */
/* @0x1de028 cmp r5, #0 */
/* @0x1de02c beq 0x1de054 <_Z12LoadGameDataPvj+0x370> */
/* @0x1de030 add r4, sp, #48 */
/* @0x1de034 ldr r0, [r5] —— Code_Function_Find(名字, &id) */
/* @0x1de038 mov r1, r4 */
/* @0x1de03c bl 0xce158 <_Z18Code_Function_FindPKcPi> */
/* @0x1de040 ldr r3, [sp, #0x30] */
/* @0x1de044 str r3, [r5, #0x4] —— 回填函数 id +4 */
/* @0x1de048 ldr r5, [r6, #0x4]! */
/* @0x1de04c cmp r5, #0 */
/* @0x1de050 bne 0x1de034 <_Z12LoadGameDataPvj+0x350> */
/* @0x1de054 mov r0, r10 —— 返回 r0 = r10 */
/* @0x1de058 add sp, sp, #68 */
/* @0x1de05c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── §4b 辅助：数组扩容（0x1de060..0x1de0b0）──────────────────────────
 *   lr = 当前条数、r11 = 新容量（lr + 增量）；容量不变就直接写；变大就
 *   MemoryManager::ReAlloc(data, 新容量*4, "…/Platform/cARRAY_CLASS.h", 0x11b, false)。
 *   返回 0（0x1de414）→ Free 旧数据、条数/容量归零，函数继续（不报错、不返回失败）。
 */
/* @0x1de060 cmp lr, r11 —— 容量已达上限（lr == r11） */
/* @0x1de064 beq 0x1de07c <_Z12LoadGameDataPvj+0x398> */
/* @0x1de068 add r0, r0, lr, lsl #2 */
/* @0x1de06c add lr, lr, #1 */
/* @0x1de070 str r10, [r0] */
/* @0x1de074 str lr, [r4, #0x4] */
/* @0x1de078 b 0x1ddeb0 <_Z12LoadGameDataPvj+0x1cc> */
/* @0x1de07c ldr r11, [r4, #0x8] —— r11 = 增量 */
/* @0x1de080 add r11, lr, r11 */
/* @0x1de084 cmp r11, lr */
/* @0x1de088 beq 0x1de068 <_Z12LoadGameDataPvj+0x384> */
/* @0x1de08c cmp r11, #0 —— 新容量为 0 → 走 Free 支路 */
/* @0x1de090 bne 0x1de458 <_Z12LoadGameDataPvj+0x774> */
/* @0x1de094 cmp r0, #0 */
/* @0x1de098 beq 0x1de414 <_Z12LoadGameDataPvj+0x730> */
/* @0x1de09c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— MemoryManager::Free(旧数据) */
/* @0x1de0a0 mov lr, #1 */
/* @0x1de0a4 mov r0, r11 */
/* @0x1de0a8 str r11, [r4, #0xc] */
/* @0x1de0ac str r11, [r4] */
/* @0x1de0b0 b 0x1de070 <_Z12LoadGameDataPvj+0x38c> */

/* ── §2 的落点：相机重载 ────────────────────────────────────────────
 *   CCameraManager::Clean(*(0x48f78c))：整个相机管理器清空；
 *   CreateDefaultCamera()：建默认相机（保证后面房间/视野有相机可用）。
 *   跑完 b 回 0x1ddd60，继续 §3。
 */
/* @0x1de0b4 ldr r3, [pc, #0x678] —— GOT 0x3edc7c → 0x48f78c（相机管理器） */
/* @0x1de0b8 ldr r0, [r7, r3] */
/* @0x1de0bc bl 0x16dd34 <_ZN14CCameraManager5CleanEv> —— CCameraManager::Clean */
/* @0x1de0c0 bl 0x1afef0 <_Z19CreateDefaultCamerav> —— CreateDefaultCamera() */
/* @0x1de0c4 b 0x1ddd60 <_Z12LoadGameDataPvj+0x7c> */
/* @0x1de0c8 bl 0x23f93c <_Z16JS_ResourceSetupv> —— JS_ResourceSetup() */

/* ── 0x1de0cc：verbose 开关 → JS_ResourceSetup()，然后落回 §7 的尾部 ──────────
 *   *(u8*)0x47f295（GOT 0x3edbc0）非 0 才调；本函数里没有任何其它条件依赖它。
 */
/* @0x1de0cc b 0x1ddfe0 <_Z12LoadGameDataPvj+0x2fc> */
/* @0x1de0d0 cmp r12, #8 —— r12 = size */
/* @0x1de0d4 mov r3, #0 */
/* @0x1de0d8 strb r3, [sp, #0x34] —— [sp+0x34] = 0（块名缓冲 NUL） */
/* @0x1de0dc bls 0x1ddfc8 <_Z12LoadGameDataPvj+0x2e4> —— size <= 8 → 0x1ddfc8 */

/* ── §6.1 块链初始化（0x1de0e0..0x1de150）─────────────────────────────
 *   r8 = size（上界）、r7 = 8（第一块偏移，紧跟 8 字节 FORM 头）；r10 = 1 → [sp+0x2c]（返回值种子）。
 *   分发表的常量全在这段进栈：[sp+0x10] = SHDR、[sp+0x1c] = OBJT、[sp+0x20] = SCPT、
 *   [sp+0x24] = SPRT、[sp+0x28] = FONT；r9 = ROOM、r11 = 控制台对象。
 *   编译器把这几个常量做成了 movw/movt + 栈槽，所以分发表在 asm 里是「树 + 栈比较」混排（见 §6.2）。
 *   [sp+0x18] = size（循环上界备份），[sp+0x30] = 当前块名缓冲，[sp+0xc] 从此改存 GOT 锚。
 */
/* @0x1de0e0 mov r8, #8 —— r8 = 8（此处置上界，稍后覆盖成 size） */
/* @0x1de0e4 mov r10, #1 —— r10 = 1（返回值种子） */
/* @0x1de0e8 movw r11, #0x4853 */
/* @0x1de0ec str r10, [sp, #0x2c] —— [sp+0x2c] = 1 */
/* @0x1de0f0 movt r11, #0x5244 */
/* @0x1de0f4 ldr r10, [sp, #0xc] —— r10 = pWAD */
/* @0x1de0f8 str r11, [sp, #0x10] */
/* @0x1de0fc movw r9, #0x4f52 */
/* @0x1de100 str r7, [sp, #0xc] —— [sp+0xc] = GOT 锚（自此 arg0 只活在 r10） */
/* @0x1de104 mov r7, r8 —— r7 = 8（首块偏移） */
/* @0x1de108 ldr r11, [sp, #0x14] —— r11 = 控制台对象 */
/* @0x1de10c movw r12, #0x424f */
/* @0x1de110 ldr r8, [sp, #0x18] —— r8 = size（循环上界） */
/* @0x1de114 add r12, r12, #260 */
/* @0x1de118 movt r9, #0x4d4f */
/* @0x1de11c add r4, sp, #48 */
/* @0x1de120 sub r12, r12, #260 —— 常量装配：SHDR → [sp+0x10] */
/* @0x1de124 movt r12, #0x544a */
/* @0x1de128 str r12, [sp, #0x1c] */
/* @0x1de12c movw r12, #0x4353 —— OBJT → [sp+0x1c] */
/* @0x1de130 movt r12, #0x5450 */
/* @0x1de134 str r12, [sp, #0x20] */
/* @0x1de138 movw r12, #0x5053 —— SCPT → [sp+0x20] */
/* @0x1de13c movt r12, #0x5452 */
/* @0x1de140 str r12, [sp, #0x24] */
/* @0x1de144 movw r12, #0x4f46 —— SPRT → [sp+0x24] */
/* @0x1de148 movt r12, #0x544e */
/* @0x1de14c str r12, [sp, #0x28] —— FONT → [sp+0x28] */

/* ── §6.2 循环头：读块头 + 打日志 + 记账 ────────────────────────────────
 *   r3 = pWAD + r7（前置写回），r6 = 块名（LE u32），r7 += 4，r5 = 块长（[r3+4]），r7 += 4。
 *   块名 4 字节进 [sp+0x30]（NUL 在 [sp+0x34]）→ Console::Output("Process Chunk: %s   %d
", 块名, 块长)
 *   → memLogPushContext(块名)。r0 = 控制台对象、r1 = 格式串 0x3517cc、r2 = 块名缓冲、r3 = 块长。
 *   块长 == 0 → 直接 0x1de22c（跳过分发），**连 tag 都不判**。
 */
/* @0x1de150 mov r3, r10 —— r3 = pWAD */
/* @0x1de154 ldr r12, [r11] —— r12 = 控制台 vtable */
/* @0x1de158 ldr r6, [r3, r7]! —— r6 = 块名（LE u32）；r3 = pWAD+offset */
/* @0x1de15c mov r0, r11 */
/* @0x1de160 ldr r1, [pc, #0x5d0] */
/* @0x1de164 mov r2, r4 */
/* @0x1de168 ldr r12, [r12, #0xc] */
/* @0x1de16c add r7, r7, #8 —— r7 = offset+8（负载起点） */
/* @0x1de170 ldr r5, [r3, #0x4] —— r5 = 块长 */
/* @0x1de174 add r1, pc, r1 */
/* @0x1de178 str r6, [sp, #0x30] —— 块名落栈 [sp+0x30] */
/* @0x1de17c mov r3, r5 */
/* @0x1de180 blx r12 —— Console::Output("Process Chunk: %s   %d\n", 块名, 块长) */
/* @0x1de184 mov r0, r4 —— memLogPushContext(块名) */
/* @0x1de188 bl 0x27b948 <_Z17memLogPushContextPKc> */
/* @0x1de18c cmp r5, #0 */
/* @0x1de190 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> —— 块长 == 0 → 0x1de22c（不分发） */
/* @0x1de194 cmp r6, r9 —— 树根：compare ROOM */
/* @0x1de198 beq 0x1de62c <_Z12LoadGameDataPvj+0x948> —— ROOM → 0x1de62c */
/* @0x1de19c bhi 0x1de248 <_Z12LoadGameDataPvj+0x564> */
/* @0x1de1a0 movw r3, #0x5054 —— TPAG */
/* @0x1de1a4 movt r3, #0x4741 */
/* @0x1de1a8 cmp r6, r3 */
/* @0x1de1ac beq 0x1de654 <_Z12LoadGameDataPvj+0x970> —— TPAG → 0x1de654 */
/* @0x1de1b0 bhi 0x1de308 <_Z12LoadGameDataPvj+0x624> */
/* @0x1de1b4 movw r3, #0x5546 —— FUNC */
/* @0x1de1b8 movt r3, #0x434e */
/* @0x1de1bc cmp r6, r3 */
/* @0x1de1c0 beq 0x1de640 <_Z12LoadGameDataPvj+0x95c> —— FUNC → 0x1de640 */
/* @0x1de1c4 bls 0x1de360 <_Z12LoadGameDataPvj+0x67c> */
/* @0x1de1c8 movw r3, #0x4f53 —— SOND */
/* @0x1de1cc movt r3, #0x444e */
/* @0x1de1d0 cmp r6, r3 */
/* @0x1de1d4 beq 0x1de568 <_Z12LoadGameDataPvj+0x884> —— SOND → 0x1de568 */
/* @0x1de1d8 movw r3, #0x4f43 —— CODE */
/* @0x1de1dc movt r3, #0x4544 */
/* @0x1de1e0 cmp r6, r3 */
/* @0x1de1e4 beq 0x1de554 <_Z12LoadGameDataPvj+0x870> —— CODE → 0x1de554 */
/* @0x1de1e8 movw r3, #0x4742 —— BGND */
/* @0x1de1ec movt r3, #0x444e */
/* @0x1de1f0 cmp r6, r3 */
/* @0x1de1f4 beq 0x1de444 <_Z12LoadGameDataPvj+0x760> —— BGND → 0x1de444 */

/* ── §6.3 未知块出口 ───────────────────────────────────────────────
 *   r12 = 0 → [sp+0x2c] = 0（返回值将被清 0）；控制台**换成错误对象**（GOT 0x3ed71c → 0x3eb70c，
 *   与 DoTheWork 的失败路同一个对象）："unknown Chunk %s:%d
"(0x3517e4)、实参 = 块名、块长。
 *   不 return、不跳过后续块：0x1de22c 继续下一块。
 */
/* @0x1de1f8 mov r12, #0 */
/* @0x1de1fc ldr r0, [pc, #0x538] —— GOT 0x3ed71c → 0x3eb70c（错误控制台） */
/* @0x1de200 str r12, [sp, #0x2c] */
/* @0x1de204 mov r3, r6 */
/* @0x1de208 ldr r12, [sp, #0xc] —— r12 = GOT 锚 */
/* @0x1de20c mov r2, r4 */
/* @0x1de210 ldr r1, [pc, #0x528] —— 池字 0x1735c4（配合 0x1de218 的 add） */
/* @0x1de214 ldr r0, [r12, r0] */
/* @0x1de218 add r1, pc, r1 —— 串址 = 0x1de220 + 0x1735c4 = 0x3517e4 */
/* @0x1de21c ldr r0, [r0] */
/* @0x1de220 ldr r12, [r0] —— obj->[0] 虚表 */
/* @0x1de224 ldr r12, [r12, #0xc] */
/* @0x1de228 blx r12 —— Output("unknown Chunk %s:%d\n", 块名, 块长) */

/* ── §6.4 循环尾：r7 += 块长（**无对齐/无 padding**）→ memLogPopContext() → size > r7 ? 下一块 ──
 *   0x1de23c 取回 r10 = [sp+0x2c]，0x1de244 回 §7。
 */
/* @0x1de22c add r7, r5, r7 —— r7 += 块长（无对齐） */
/* @0x1de230 bl 0x27b94c <_Z16memLogPopContextv> —— memLogPopContext() */
/* @0x1de234 cmp r8, r7 —— size > r7 → 下一块 */
/* @0x1de238 bhi 0x1de150 <_Z12LoadGameDataPvj+0x46c> —— 继续循环 */
/* @0x1de23c ldr r10, [sp, #0x2c] —— r10 = [sp+0x2c] */
/* @0x1de240 ldr r7, [sp, #0xc] */
/* @0x1de244 b 0x1ddfcc <_Z12LoadGameDataPvj+0x2e8> —— → §7 尾部 */

/* ── §6.5 分发树（二段）：0x1de248..0x1de3d4 ──────────────────────────────
 *   这半棵子树用栈槽常量：[sp+0x10]=SHDR → 0x1de52c、[sp+0x1c]=OBJT → 0x1de540、
 *   [sp+0x20]=SCPT → 0x1de4ec、[sp+0x24]=SPRT → 0x1de4d8、[sp+0x28]=FONT → 0x1de2f0；
 *   字面量树：AUDO→0x1de500、OPTN→0x1de604、EXTN→0x1de5f0、TMLN→0x1de2a8、
 *   EMBI→0x1de42c、STRG（忽略）、PATH→0x1de594、LANG→0x1de358、
 *   GEN8→0x1de618、GLOB→0x1de38c、PSPS/STAT（忽略）、TXTR→0x1de3c4、AGRP→0x1de3e8。
 *   走不到的叶子统一回 0x1de1f8（未知块）。
 */
/* @0x1de248 ldr r12, [sp, #0x10] —— cmp [sp+0x10] = SHDR */
/* @0x1de24c cmp r6, r12 */
/* @0x1de250 beq 0x1de52c <_Z12LoadGameDataPvj+0x848> —— SHDR → 0x1de52c */
/* @0x1de254 bhi 0x1de2b0 <_Z12LoadGameDataPvj+0x5cc> */
/* @0x1de258 movw r3, #0x5541 —— AUDO */
/* @0x1de25c movt r3, #0x4f44 */
/* @0x1de260 cmp r6, r3 */
/* @0x1de264 beq 0x1de500 <_Z12LoadGameDataPvj+0x81c> —— AUDO → 0x1de500 */
/* @0x1de268 bhi 0x1de3d8 <_Z12LoadGameDataPvj+0x6f4> */
/* @0x1de26c movw r3, #0x504f —— OPTN */
/* @0x1de270 movt r3, #0x4e54 */
/* @0x1de274 cmp r6, r3 */
/* @0x1de278 beq 0x1de604 <_Z12LoadGameDataPvj+0x920> —— OPTN → 0x1de604 */
/* @0x1de27c movw r3, #0x5845 —— EXTN */
/* @0x1de280 movt r3, #0x4e54 */
/* @0x1de284 cmp r6, r3 */
/* @0x1de288 beq 0x1de5f0 <_Z12LoadGameDataPvj+0x90c> —— EXTN → 0x1de5f0 */
/* @0x1de28c movw r3, #0x4d54 —— TMLN */
/* @0x1de290 movt r3, #0x4e4c */
/* @0x1de294 cmp r6, r3 */
/* @0x1de298 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> —— 不匹配 → 0x1de1f8（未知块） */
/* @0x1de29c add r0, r10, r7 */
/* @0x1de2a0 mov r1, r5 */
/* @0x1de2a4 mov r2, r10 */
/* @0x1de2a8 bl 0x1f2770 <_Z13TimeLine_LoadPhjS_> —— TimeLine_Load */
/* @0x1de2ac b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de2b0 ldr r12, [sp, #0x1c] —— cmp [sp+0x1c] = OBJT */
/* @0x1de2b4 cmp r6, r12 */
/* @0x1de2b8 beq 0x1de540 <_Z12LoadGameDataPvj+0x85c> —— OBJT → 0x1de540 */
/* @0x1de2bc bls 0x1de394 <_Z12LoadGameDataPvj+0x6b0> */
/* @0x1de2c0 ldr r12, [sp, #0x20] —— cmp [sp+0x20] = SCPT */
/* @0x1de2c4 cmp r6, r12 */
/* @0x1de2c8 beq 0x1de4ec <_Z12LoadGameDataPvj+0x808> —— SCPT → 0x1de4ec */
/* @0x1de2cc ldr r12, [sp, #0x24] */
/* @0x1de2d0 cmp r6, r12 —— cmp [sp+0x24] = SPRT */
/* @0x1de2d4 beq 0x1de4d8 <_Z12LoadGameDataPvj+0x7f4> —— SPRT → 0x1de4d8 */
/* @0x1de2d8 ldr r12, [sp, #0x28] —— cmp [sp+0x28] = FONT */
/* @0x1de2dc cmp r6, r12 */
/* @0x1de2e0 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> —— 不匹配 → 0x1de1f8 */
/* @0x1de2e4 add r0, r10, r7 */
/* @0x1de2e8 mov r1, r5 */
/* @0x1de2ec mov r2, r10 */
/* @0x1de2f0 bl 0xfa0d4 <_Z9Font_LoadPhjS_> —— Font_Load */
/* @0x1de2f4 b 0x1de22c <_Z12LoadGameDataPvj+0x548> —— → 循环尾 */

/* §3 的「条数为 0」支路（同样不可达：只有 0x1ddd9c 的 ble 会来）：r8 = &0x544b48，回 0x1dddb8。 */
/* @0x1de2f8 ldr r3, [pc, #0x418] */
/* @0x1de2fc ldr r8, [r7, r3] —— r8 = &0x544b48 */
/* @0x1de300 ldr r1, [r8] */
/* @0x1de304 b 0x1dddb8 <_Z12LoadGameDataPvj+0xd4> —— 回 0x1dddb8 */

/* ── 分发树（EMBI 子支）：EMBI → 0x1de42c（后面还有 STRG/PATH/LANG 三个叶）── */
/* @0x1de308 movw r3, #0x4d45 —— EMBI */
/* @0x1de30c movt r3, #0x4942 */
/* @0x1de310 cmp r6, r3 */
/* @0x1de314 beq 0x1de42c <_Z12LoadGameDataPvj+0x748> —— EMBI → 0x1de42c */
/* @0x1de318 bhi 0x1de5a8 <_Z12LoadGameDataPvj+0x8c4> —— 高位 → DAFL/GENL 链 */
/* @0x1de31c movw r3, #0x5453 —— STRG */
/* @0x1de320 movt r3, #0x4752 */
/* @0x1de324 cmp r6, r3 */
/* @0x1de328 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> —— STRG → 循环尾（忽略） */
/* @0x1de32c movw r3, #0x4150 —— PATH */
/* @0x1de330 movt r3, #0x4854 */
/* @0x1de334 cmp r6, r3 */
/* @0x1de338 beq 0x1de594 <_Z12LoadGameDataPvj+0x8b0> —— PATH → 0x1de594 */
/* @0x1de33c movw r3, #0x414c —— LANG */
/* @0x1de340 movt r3, #0x474e */
/* @0x1de344 cmp r6, r3 */
/* @0x1de348 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> —— 不匹配 → 未知块 */
/* @0x1de34c add r0, r10, r7 */
/* @0x1de350 mov r1, r5 */
/* @0x1de354 mov r2, r10 */
/* @0x1de358 bl 0x27a4c8 <_ZN8CLangMan13Language_LoadEPhjS0_> —— CLangMan::Language_Load */
/* @0x1de35c b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* ── 分发树（GEN8 子支）：GEN8 → 0x1de618；GLOB → 0x1de38c；不匹配 → 0x1de690（GEN7/VARI）── */
/* @0x1de360 movw r3, #0x4547 —— GEN8 */
/* @0x1de364 movt r3, #0x384e */
/* @0x1de368 cmp r6, r3 */
/* @0x1de36c beq 0x1de618 <_Z12LoadGameDataPvj+0x934> —— GEN8 → 0x1de618 */
/* @0x1de370 movw r3, #0x4c47 —— GLOB */
/* @0x1de374 movt r3, #0x424f */
/* @0x1de378 cmp r6, r3 */
/* @0x1de37c bne 0x1de690 <_Z12LoadGameDataPvj+0x9ac> —— 不匹配 → 0x1de690（GEN7） */
/* @0x1de380 add r0, r10, r7 */
/* @0x1de384 mov r1, r5 */
/* @0x1de388 mov r2, r10 */
/* @0x1de38c bl 0x1dcf64 <_Z9GLOB_LoadPhjS_> —— GLOB_Load */
/* @0x1de390 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* ── 分发树（PSPS/STAT/TXTR）：PSPS、STAT 直接回循环尾（认识但不处理）；TXTR → 0x1de3c4 ── */
/* @0x1de394 movw r3, #0x5350 —— PSPS */
/* @0x1de398 movt r3, #0x5350 */
/* @0x1de39c cmp r6, r3 */
/* @0x1de3a0 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> —— PSPS → 循环尾（忽略） */
/* @0x1de3a4 movw r3, #0x5453 —— STAT */
/* @0x1de3a8 movt r3, #0x5441 */
/* @0x1de3ac cmp r6, r3 */
/* @0x1de3b0 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> —— STAT → 循环尾（忽略） */
/* @0x1de3b4 movw r3, #0x5854 —— TXTR */
/* @0x1de3b8 movt r3, #0x5254 */
/* @0x1de3bc cmp r6, r3 */
/* @0x1de3c0 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> —— 不匹配 → 未知块 */
/* @0x1de3c4 add r0, r10, r7 */
/* @0x1de3c8 mov r1, r5 */
/* @0x1de3cc mov r2, r10 */
/* @0x1de3d0 bl 0x1dda28 <_Z12Texture_LoadPhjS_> —— Texture_Load */
/* @0x1de3d4 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* ── 分发树（AGRP）：0x755314 非 0 → AudioGroup_Load(payload,size,base)，否则整块丢掉；
 *   不匹配 → 0x1de6bc（RASP/HELP）。
 */
/* @0x1de3d8 movw r3, #0x4741 —— AGRP */
/* @0x1de3dc movt r3, #0x5052 */
/* @0x1de3e0 cmp r6, r3 */
/* @0x1de3e4 bne 0x1de6bc <_Z12LoadGameDataPvj+0x9d8> —— 不匹配 → 0x1de6bc（RASP） */
/* @0x1de3e8 ldr r3, [pc, #0x354] —— GOT 0x3eed38 → 0x755314（音频后端开关） */
/* @0x1de3ec ldr r12, [sp, #0xc] */
/* @0x1de3f0 ldr r3, [r12, r3] */
/* @0x1de3f4 ldrb r3, [r3] */
/* @0x1de3f8 cmp r3, #0 */
/* @0x1de3fc beq 0x1de22c <_Z12LoadGameDataPvj+0x548> —— 开关为 0 → 循环尾（整块丢掉） */
/* @0x1de400 add r0, r10, r7 */
/* @0x1de404 mov r1, r5 */
/* @0x1de408 mov r2, r10 */
/* @0x1de40c bl 0x218c94 <_Z15AudioGroup_LoadPhjS_> —— AudioGroup_Load */
/* @0x1de410 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* ── §4b 扩容失败：Free 旧数据、条数/容量清零，然后回 0x1de0ac 继续（不中断装载）── */
/* @0x1de414 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— Free(旧数据) */
/* @0x1de418 mov r1, #0 */
/* @0x1de41c mov lr, #1 */
/* @0x1de420 str r1, [r4, #0xc] —— 条数清零 */
/* @0x1de424 mov r0, r1 */
/* @0x1de428 b 0x1de0ac <_Z12LoadGameDataPvj+0x3c8> */
/* @0x1de42c mov r1, r5 */
/* @0x1de430 mov r2, r10 */
/* @0x1de434 add r0, r10, r7 */
/* @0x1de438 bl 0x176830 <_Z19EmbeddedImages_LoadPhjS_> —— EmbeddedImages_Load */
/* @0x1de43c bl 0x1a58d8 <_Z24Part_SetupEmbeddedImagesv> —— Part_SetupEmbeddedImages() */
/* @0x1de440 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de444 add r0, r10, r7 */
/* @0x1de448 mov r1, r5 */
/* @0x1de44c mov r2, r10 */
/* @0x1de450 bl 0xc3350 <_Z15Background_LoadPhjS_> —— Background_Load */
/* @0x1de454 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* ── §4b 扩容：ReAlloc(data, 新容量*4, "…/cARRAY_CLASS.h", 0x11b, false) ─────────────
 *   0x1de458 lsls r1, r11, #2 = 字节数；0x1de464 movw r3, #0x11b = 283 是行号；
 *   0x1de46c r2 = [sp+0x1c] = 文件串（§4b 期间是 cARRAY_CLASS.h，块链期间该槽被 OBJT 常量覆盖，
 *   但扩容只可能在 §4b 发生）→ 新指针写回 +0xc、条数 +1。
 */
/* @0x1de458 lsls r1, r11, #2 */
/* @0x1de45c beq 0x1de414 <_Z12LoadGameDataPvj+0x730> —— 字节数 = 新容量*4 */
/* @0x1de460 mov r2, #0 */
/* @0x1de464 movw r3, #0x11b —— 行号 0x11b = 283 */
/* @0x1de468 str r2, [sp] */
/* @0x1de46c ldr r2, [sp, #0x1c] —— 文件实参 = [sp+0x1c] */
/* @0x1de470 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> —— MemoryManager::ReAlloc */
/* @0x1de474 ldr r3, [r4, #0x4] */
/* @0x1de478 add lr, r3, #1 */
/* @0x1de47c str r0, [r4, #0xc] —— 新指针写回 +0xc */
/* @0x1de480 add r0, r0, r3, lsl #2 */
/* @0x1de484 b 0x1de0ac <_Z12LoadGameDataPvj+0x3c8> */

/* ── §3 变体：*(0x544be0) == 0 时（还没有全局对象）────────────────────────
 *   取 &0x544c64 → [sp+8]；*(0x544c64) 若为 0 → 0x1de6a4（两个表都空，直接去 §5）；
 *   否则条数 = code->+0x8，> 0 就写进 *(0x544b4c) 再走 0x1ddd9c；<= 0 走 0x1de680（只取计数）。
 */
/* @0x1de488 ldr r3, [pc, #0x280] */
/* @0x1de48c ldr r3, [r7, r3] */
/* @0x1de490 str r3, [sp, #0x8] —— [sp+8] = &0x544c64 */
/* @0x1de494 ldr r3, [r3] */
/* @0x1de498 cmp r3, #0 —— *(0x544c64) == 0 → 0x1de6a4 */
/* @0x1de49c beq 0x1de6a4 <_Z12LoadGameDataPvj+0x9c0> */
/* @0x1de4a0 ldr r2, [r3, #0x8] —— 条数 = code->+0x8 */
/* @0x1de4a4 cmp r2, #0 */
/* @0x1de4a8 ble 0x1de680 <_Z12LoadGameDataPvj+0x99c> */
/* @0x1de4ac ldr r1, [pc, #0x260] —— r9 = &0x544b4c */
/* @0x1de4b0 mov r0, r2 */
/* @0x1de4b4 ldr r9, [r7, r1] */
/* @0x1de4b8 str r2, [r9] —— *(0x544b4c) = 条数 */
/* @0x1de4bc b 0x1ddd9c <_Z12LoadGameDataPvj+0xb8> */

/* §3 变体：*(0x544c64) == 0（没有代码表）→ r8 = &0x544b48，直接去 §5 建全局实例。 */
/* @0x1de4c0 ldr r3, [pc, #0x250] */
/* @0x1de4c4 ldr r8, [r7, r3] —— r8 = &0x544b48 */
/* @0x1de4c8 b 0x1ddf20 <_Z12LoadGameDataPvj+0x23c> —— → §5 */

/* ── 唯一直接返回 0 的出口：pWAD == NULL（r0 = 原 arg0 = 0）────────────────────
 *   注意这里读的是 [sp+0xc]，在当前时刻它就是入参 0（块链初始化前该槽才被改成 GOT 锚）。
 */
/* @0x1de4cc ldr r0, [sp, #0xc] */
/* @0x1de4d0 add sp, sp, #68 —— add sp,#68 */
/* @0x1de4d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— pop 返回（r0 = 0） */

/* ── 各块处理器（按 tag 分组，全部同形：payload = base+offset、size = 块长、base = pWAD）──
 *   顺序按地址：SPRT 0x1de4d8、SCPT 0x1de4ec、AUDO 0x1de500、SHDR 0x1de52c、OBJT 0x1de540、
 *   CODE 0x1de554、SOND 0x1de568、PATH 0x1de594。
 */
/* @0x1de4d8 add r0, r10, r7 —— payload */
/* @0x1de4dc mov r1, r5 */
/* @0x1de4e0 mov r2, r10 */
/* @0x1de4e4 bl 0x1effbc <_Z11Sprite_LoadPhiS_> —— Sprite_Load */
/* @0x1de4e8 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de4ec add r0, r10, r7 —— Script_Load */
/* @0x1de4f0 mov r1, r5 */
/* @0x1de4f4 mov r2, r10 */
/* @0x1de4f8 bl 0x1e01e4 <_Z11Script_LoadPhjS_> —— Script_Load(payload,size,pWAD) */
/* @0x1de4fc b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* AUDO：*(u8*)0x755314 == 0 → Sound_WAVs(payload,size,base)（旧路）；
 * 非 0 → 0x1de674 Audio_WAVs(payload,size,base,0)（新路，第 4 实参恒 0）。
 */
/* @0x1de500 ldr r3, [pc, #0x23c] —— GOT 0x3eed38 → 0x755314 */
/* @0x1de504 add r0, r10, r7 */
/* @0x1de508 ldr r12, [sp, #0xc] */
/* @0x1de50c mov r1, r5 */
/* @0x1de510 mov r2, r10 */
/* @0x1de514 ldr r3, [r12, r3] */
/* @0x1de518 ldrb r3, [r3] */
/* @0x1de51c cmp r3, #0 */
/* @0x1de520 bne 0x1de674 <_Z12LoadGameDataPvj+0x990> */
/* @0x1de524 bl 0x21f9d4 <_Z10Sound_WAVsPhjS_> —— Sound_WAVs(payload,size,pWAD) */
/* @0x1de528 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de52c add r0, r10, r7 —— Shader_Load */
/* @0x1de530 mov r1, r5 */
/* @0x1de534 mov r2, r10 */
/* @0x1de538 bl 0x1e1cd8 <_Z11Shader_LoadPhjS_> —— Shader_Load(payload,size,pWAD) */
/* @0x1de53c b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de540 add r0, r10, r7 —— Object_Load */
/* @0x1de544 mov r1, r5 */
/* @0x1de548 mov r2, r10 */
/* @0x1de54c bl 0x19ea7c <_Z11Object_LoadPhjS_> —— Object_Load(payload,size,pWAD) */
/* @0x1de550 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de554 add r0, r10, r7 —— Code_Patch */
/* @0x1de558 mov r1, r5 */
/* @0x1de55c mov r2, r10 */
/* @0x1de560 bl 0x1dc8c4 <_Z10Code_PatchPhjS_> —— Code_Patch(payload,size,pWAD) */
/* @0x1de564 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* SOND：*(u8*)0x755314 == 0 → Sound_Load(payload,size,base)；
 * 非 0 → 0x1de66c Audio_Load(payload,size,base)。两套音频后端的开关就是这一个字节。
 */
/* @0x1de568 ldr r3, [pc, #0x1d4] —— GOT 0x3eed38 → 0x755314 */
/* @0x1de56c add r0, r10, r7 */
/* @0x1de570 ldr r12, [sp, #0xc] */
/* @0x1de574 mov r1, r5 */
/* @0x1de578 mov r2, r10 */
/* @0x1de57c ldr r3, [r12, r3] */
/* @0x1de580 ldrb r3, [r3] */
/* @0x1de584 cmp r3, #0 */
/* @0x1de588 bne 0x1de66c <_Z12LoadGameDataPvj+0x988> */
/* @0x1de58c bl 0x21f630 <_Z10Sound_LoadPhjS_> —— Sound_Load(payload,size,pWAD) */
/* @0x1de590 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de594 add r0, r10, r7 —— Path_Load */
/* @0x1de598 mov r1, r5 */
/* @0x1de59c mov r2, r10 */
/* @0x1de5a0 bl 0x1a7e74 <_Z9Path_LoadPhjS_> —— Path_Load(payload,size,pWAD) */
/* @0x1de5a4 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* ── 尾部叶：DAFL / GENL / GEN7 / VARI / RASP / HELP ────────────────────
 *   DAFL：beq 循环尾（忽略，本包长度 0 根本到不了这里）。
 *   GENL 0x1de5b8 → 0x1de5c8。
 */
/* @0x1de5a8 movw r3, #0x4144 —— DAFL */
/* @0x1de5ac movt r3, #0x4c46 */
/* @0x1de5b0 cmp r6, r3 */
/* @0x1de5b4 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> —— DAFL → 循环尾（忽略） */
/* @0x1de5b8 movw r3, #0x4547 —— GENL */
/* @0x1de5bc movt r3, #0x4c4e */
/* @0x1de5c0 cmp r6, r3 */
/* @0x1de5c4 bne 0x1de6e0 <_Z12LoadGameDataPvj+0x9fc> —— 不匹配 → 0x1de6e0（VARI） */

/* ── GEN7/GENL（旧头）与 GEN8 共用 Header_Load，但旧头先把常量 700 写进 *(u32*)0x544bd4 ──
 *   700 = 0x2BC。为什么只有旧头写、GEN8 不写：未钉（怀疑是 WAD 版本号 7.00）。
 */
/* @0x1de5c8 ldr r2, [sp, #0xc] —— r0 = payload */
/* @0x1de5cc add r0, r10, r7 */
/* @0x1de5d0 ldr r3, [pc, #0x170] */
/* @0x1de5d4 mov r1, r5 */
/* @0x1de5d8 mov r12, #700 —— 700 = 0x2BC */
/* @0x1de5dc ldr r3, [r2, r3] */
/* @0x1de5e0 mov r2, r10 */
/* @0x1de5e4 str r12, [r3] —— *(0x544bd4) = 700 */
/* @0x1de5e8 bl 0x1dcf94 <_Z11Header_LoadPhjS_> —— Header_Load(payload,size,pWAD) */
/* @0x1de5ec b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de5f0 add r0, r10, r7 —— Extension_Load */
/* @0x1de5f4 mov r1, r5 */
/* @0x1de5f8 mov r2, r10 */
/* @0x1de5fc bl 0xf5eb8 <_Z14Extension_LoadPhjS_> —— Extension_Load(payload,size,pWAD) */
/* @0x1de600 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* OPTN → Option_Load 0x19f534（payload, size, pWAD）。 */
/* @0x1de604 add r0, r10, r7 —— Option_Load */
/* @0x1de608 mov r1, r5 */
/* @0x1de60c mov r2, r10 */
/* @0x1de610 bl 0x19f534 <_Z11Option_LoadPhjS_> —— Option_Load(payload,size,pWAD) */
/* @0x1de614 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* GEN8 → Header_Load 0x1dcf94（payload, size, pWAD）：Header_Load 把 payload 基址 + [payload+1]
 * 字节 + [payload+0x14/+0x18/+0x1c/+0x20/+0x24] 五个字写进全局；本包 GEN8 = 588 B，header 首字 0x1001、
 * [1] = 0x10、+0x14 = 0x29c06、+0x18 = 0x9896f2、+0x1c = 0x2e66a261、+0x20 = 0、+0x24 = 0。
 */
/* @0x1de618 add r0, r10, r7 —— Header_Load */
/* @0x1de61c mov r1, r5 */
/* @0x1de620 mov r2, r10 */
/* @0x1de624 bl 0x1dcf94 <_Z11Header_LoadPhjS_> —— Header_Load(payload,size,pWAD) */
/* @0x1de628 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* ROOM → Room_Load 0x1b4cd8：对块内每个房间 new(292) + CRoom::LoadFromChunk(wad+房间偏移, wad)，
 *  再把 CRoom* 与房间路径串塞进两张平行数组（CRoom 卡已钉）。本包 114 个房间。
 */
/* @0x1de62c add r0, r10, r7 —— Room_Load */
/* @0x1de630 mov r1, r5 */
/* @0x1de634 mov r2, r10 */
/* @0x1de638 bl 0x1b4cd8 <_Z9Room_LoadPhjS_> —— Room_Load(payload,size,pWAD) */
/* @0x1de63c b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* FUNC → FUNC_Load 0x1dcdf0（函数名表；本包 99 条）。 */
/* @0x1de640 add r0, r10, r7 —— FUNC_Load */
/* @0x1de644 mov r1, r5 */
/* @0x1de648 mov r2, r10 */
/* @0x1de64c bl 0x1dcdf0 <_Z9FUNC_LoadPhjS_> —— FUNC_Load(payload,size,pWAD) */
/* @0x1de650 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* TPAG：**不调用任何装载器**——只把块负载的基址写进 *(void**)0x544bc4（GOT 0x3f0cec）。
 *  块内是 1791 条 texture-page 记录，纹理侧按需取；真正的像素在 TXTR 块。
 */
/* @0x1de654 ldr r3, [pc, #0xf0] —— GOT 0x3f0cec → &0x544bc4 */
/* @0x1de658 add r2, r10, r7 */
/* @0x1de65c ldr r12, [sp, #0xc] */
/* @0x1de660 ldr r3, [r12, r3] —— r3 = *(0x544bc4) */
/* @0x1de664 str r2, [r3] —— *(0x544bc4) = payload（只存指针） */
/* @0x1de668 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* SOND 的新音频路：Audio_Load(payload,size,base) → 循环尾。 */
/* @0x1de66c bl 0x219048 <_Z10Audio_LoadPhjS_> —— Audio_Load */
/* @0x1de670 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* AUDO 的新音频路：Audio_WAVs(payload,size,base,0)；r3 = 0 就是第 4 实参。 */
/* @0x1de674 mov r3, #0 —— Audio_WAVs(…, 0) */
/* @0x1de678 bl 0x219680 <_Z10Audio_WAVsPhjS_i> */
/* @0x1de67c b 0x1de22c <_Z12LoadGameDataPvj+0x548> */

/* §3 支路：r9 = &0x544b4c，r0 = *(0x544b4c)，回 0x1ddd9c。 */
/* @0x1de680 ldr r2, [pc, #0x8c] —— r9 = &0x544b4c */
/* @0x1de684 ldr r9, [r7, r2] */
/* @0x1de688 ldr r0, [r9] —— r0 = *(0x544b4c) */
/* @0x1de68c b 0x1ddd9c <_Z12LoadGameDataPvj+0xb8> —— 回 0x1ddd9c */

/* GEN7 → 0x1de5c8（与 GENL 同）；否则 0x1de6e0（VARI/RASP/HELP 链）。 */
/* @0x1de690 movw r3, #0x4547 —— GEN7 */
/* @0x1de694 movt r3, #0x374e */
/* @0x1de698 cmp r6, r3 */
/* @0x1de69c bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> —— 不匹配 → 未知块 */
/* @0x1de6a0 b 0x1de5c8 <_Z12LoadGameDataPvj+0x8e4> —— GEN7 → 0x1de5c8（同 GENL） */

/* §5 入口变体：r3 = &0x544b4c、r8 = &0x544b48、r0 = *(0x544b4c) → 直接建全局实例。 */
/* @0x1de6a4 ldr r3, [pc, #0x68] —— r3 = &0x544b4c */
/* @0x1de6a8 ldr r2, [pc, #0x68] —— r8 = &0x544b48 */
/* @0x1de6ac ldr r3, [r7, r3] */
/* @0x1de6b0 ldr r8, [r7, r2] */
/* @0x1de6b4 ldr r0, [r3] */
/* @0x1de6b8 b 0x1ddf20 <_Z12LoadGameDataPvj+0x23c> —— → §5 */

/* RASP（0x50534152）→ 循环尾：认识但不处理。HELP 同（0x1de6cc..0x1de6dc）。 */
/* @0x1de6bc movw r3, #0x4152 —— RASP */
/* @0x1de6c0 movt r3, #0x5053 */
/* @0x1de6c4 cmp r6, r3 */
/* @0x1de6c8 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> —— RASP → 循环尾（忽略） */
/* @0x1de6cc movw r3, #0x4548 —— HELP */
/* @0x1de6d0 movt r3, #0x504c */
/* @0x1de6d4 cmp r6, r3 */
/* @0x1de6d8 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> */
/* @0x1de6dc b 0x1de22c <_Z12LoadGameDataPvj+0x548> —— HELP → 循环尾（忽略） */

/* VARI（0x49524156）→ 循环尾：变量表**不在这里装**（变量随 CODE 片一起处理）。 */
/* @0x1de6e0 movw r3, #0x4156 —— VARI */
/* @0x1de6e4 movt r3, #0x4952 */
/* @0x1de6e8 cmp r6, r3 */
/* @0x1de6ec bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> —— 不匹配 → 未知块 */
/* @0x1de6f0 b 0x1de22c <_Z12LoadGameDataPvj+0x548> —— VARI → 循环尾（忽略） */

/* §4a 内层：r1 = r0（记录指针）→ 回 0x1ddeac 写槽号。 */
/* @0x1de6f4 mov r1, r0 —— r1 = r0 */
/* @0x1de6f8 b 0x1ddeac <_Z12LoadGameDataPvj+0x1c8> —— 回 0x1ddeac */

/* ── 内联 literal pool：0x1de6fc..0x1de74c 共 21 字（objdump 译成指令，非指令）──────────
 *   池字 = GOT 相对偏移（负值）或串偏移；本卡在头部已把每个池字换算成「全局地址 / 串地址」。
 */
/* @0x1de6fc eoreq r3, r1, r12, asr pc */
/* @0x1de700 .word 0xffffdecc */
/* @0x1de704 andseq r3, r7, r0, lsr #21 */
/* @0x1de708 .word 0xffffbcd4 */
/* @0x1de70c .word 0xffffbf64 */
/* @0x1de710 .word 0xffffbef0 */
/* @0x1de714 .word 0xffffc0b8 */
/* @0x1de718 .word 0xffffc0c4 */
/* @0x1de71c .word 0xffffbf4c */
/* @0x1de720 andseq pc, r6, r4, asr #9 */
/* @0x1de724 .word 0xffffc010 */
/* @0x1de728 .word 0xffffc058 */
/* @0x1de72c .word 0xffffc5f8 */
/* @0x1de730 .word 0xffffbf68 */
/* @0x1de734 .word 0xffffc024 */
/* @0x1de738 andseq r3, r7, r0, asr r6 */
/* @0x1de73c .word 0xffffbac4 */
/* @0x1de740 andseq r3, r7, r4, asr #11 */
/* @0x1de744 .word 0xffffd0e0 */
/* @0x1de748 .word 0xffffd14c */
/* @0x1de74c .word 0xfffff094 */
