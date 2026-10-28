/* cally 逆向卡：anon_batch5 —— 匿名段第 5 批（10 段 / 6 个静态库，全部 ARM）
 *（原版 libyoyo.so，ELF32 ARM，armeabi-v7a，stripped）
 *
 * @card  10 段互不相邻，合计 16,276 B / 4,065 条锚点：
 *        0x25e350..0x25ed60   2,576 B   0x28677c..0x2872b4   2,872 B
 *        0x2670bc..0x2679bc   2,304 B   0x25b5c4..0x25bba8   1,516 B
 *        0x25c788..0x25c988     512 B   0x265c10..0x266564   2,388 B
 *        0x222040..0x2225c8   1,416 B   0x2bb8b4..0x2bbd94   1,248 B
 *        0x230b68..0x230eb8     856 B   0x2de214..0x2de460     588 B
 * 来源:  libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        （4,689,844 B，.text 0xb6fd0..0x31bb7c）
 * 锚表:  asm/index-anon_{25e350,28677c,2670bc,25b5c4,25c788,265c10,222040,2bb8b4,230b68,2de214}.tsv
 *        全部由 scripts/asm_index.py --so libyoyo.so --start --end 生成（ARM triple，未加 --thumb）。
 *        为什么判 ARM：对这 10 段各取前 100 条指令做双模式解码，ARM 解码的 .word / <unknown> 计数
 *        全是 0，Thumb 解码分别是 3/7/9/1/9/1/15/2/11/8 条；十段首条都是 `push {r4..r11, lr}`
 *        或其同族 ARM 序言，段内没有一条 Thumb-2 32 位对；十段地址也都不在
 *        asm/thumb_symbols.tsv 里，与规则一致。另外 0x2bb8b4 的 1,504 B 栈帧 + `sub sp,#4`
 *        配对、0x2de214 的 `vpush {d8, d9}` 都只在 ARM 下自洽。
 * 级别:  骨架（锚点全覆盖、逐字一致；语义钉到"段属于哪个库、入口契约、出口族、调用面、
 *        跳转表尺寸、关键字段偏移与常量、段内函数边界"；函数体按 objdump 原文逐条列出，
 *        不逐条解释）
 *
 * ══ 一句话结论 ═══════════════════════════════════════════════════════
 *   十段全是**静态链接进 libyoyo.so 的第三方库代码**，没有一段是游戏逻辑。六个库、十条证据链
 *   互相独立（库身份靠四类证据：版本串/源码路径串 + 邻接具名符号 + 调用面 + 常量表）：
 *
 *     段         大小   指令  in-deg  身份                                          置信
 *     25e350    2576    644     5    libpcre 8.x   pcre_study.c 静态递归遍历器      库 proven / 函数名 narrowed
 *     28677c    2872    718     3    spine-c       spine-c/src/spine/Json.c 解析器  库 proven / 文件 proven
 *     2670bc    2304    576     4    libpcre 8.x   pcre_compile.c 区 opcode 遍历器  库 proven / 函数名 narrowed
 *     25b5c4    1516    377     4    libpcre 8.x   同区 opcode 分派体（组头 +3）     库 proven / 函数名 narrowed
 *     25c788     512    128     4    libpcre 8.x   同区小型 opcode 过滤例程          库 proven / 函数名 narrowed
 *     265c10    2388    597     3    libpcre 8.x   pcre_study.c 第二个递归遍历器    库 proven / 函数名 narrowed
 *     222040    1416    354     2    freealut      WAV(RIFF)/AU(.snd) 载入器        库 proven / 函数名 narrowed
 *     2bb8b4    1248    312     2    libjpeg(IJG)  量化器区静态像素步进（叶子）     库 proven / 函数名 narrowed
 *     230b68     856    212     2    vorbisfile    _fetch_and_process_packet        库 proven / 函数名 narrowed
 *     2de214     588    147     2    Box2D         b2CollidePolygons 内浮点辅助     库 proven / 函数名 narrowed
 *
 *   —— 库级 proven = 能指出该库独有、不可伪造的字节特征（下节逐条给地址）；
 *      函数级 narrowed = 能钉住"该库哪个 TU 的哪种例程"，但不宣称与上游源码逐行等价。
 *      没有一节是 test_anchored / host_authored；也没有一节有运行期对照（见全局 open 1）。
 *
 * ══ 六库的识别证据（每条都可在二进制里复核）═══════════════════════════
 *   libpcre 8.x（§1 / §3 / §4 / §5 / §6）
 *     ① 版本串指纹：pcre_version（0x266c9c，12 B）是 `ldr r0,[pc,#4]; add r0,pc,r0; bx lr`，
 *        池字 0x000f03c8 @0x266ca8 → 0x266cac + 0xf03c8 = 0x357074，读出的字符串是
 *        "@PCRE_MAJOR@.@PCRE_MINOR@@PCRE_PRERELEASE@ @PCRE_DATE@" —— 未展开的 PCRE 版本宏模板。
 *        这段字面量只有 PCRE 的构建会产生，是这个二进制里最硬的 pcre 指纹。
 *     ② 具名邻居：pcre_compile2 0x2679c0(5,576 B)、pcre_compile 0x268f88(44 B)、
 *        pcre_study 0x2665e0(752 B)、pcre_exec 0x279390、pcre_dfa_exec 0x26e568、
 *        pcre_fullinfo / pcre_config / pcre_refcount / pcre_version，以及内部件
 *        _pcre_xclass 0x266cac、_pcre_find_bracket 0x25e0fc、_pcre_ord2utf 0x25fd98、
 *        _pcre_is_newline 0x25f9fc、_pcre_OP_lengths 0x38ba04、_pcre_default_tables 0x38baa8。
 *     ③ opcode 表：_pcre_OP_lengths（0x38ba04，162 B）；本卡读表复核了两条硬约束 ——
 *        [118]=6（§3 的 `addeq r4,r4,#6` 与之逐字对上）、[123]=3、[133]=[134]=[138]=[139]=5
 *        （§1 / §5 的 +3/+5 判定与之逐字对上）。§1 / §4 / §6 里还各有一条
 *        `cmp #161` + `addls pc,pc,rX,lsl #2` 的 162 项操作码跳转表 —— pcre 8.x 的操作码总数
 *        就是 162。
 *     ④ 选项位：§1 入口 0x25e358 `ubfx r10,r3,#0xb,#1` 取 bit11 = 0x800 = pcre.h 的 PCRE_UTF8。
 *   spine-c（§2）
 *     ① 源码路径串：0x2867f8 `ldr r10,[pc,#0x2fc]` → 池字 @0x286b00 = 0x001057ac，
 *        add 后 = 0x3578e0 → `jni/../jni/yoyo/../../../spine-c/src/spine/Json.c`。
 *     ② JSON 语法常量：'"'=0x22 @0x286794、'\\'=0x5c @0x2867b8、90 项首字符表（34..123）
 *        @0x286b24；0x3578e0 之后同一片 rodata 里还有 `%4x` / `ull` / `alse` / `rue`
 *        （\uXXXX 的 sscanf 格式串 + null/true/false 的共享尾串）。
 *     ③ 具名邻居：spIkConstraintData_create 0x2866f0 / _dispose 0x286758（前）、
 *        Json_getError 0x2872b8 / Json_dispose 0x2872c8（后）；调用面是 malloc / calloc /
 *        strtod / sscanf / strncmp。
 *   freealut（§7）
 *     ① 4CC 常量：0x22210c+0x222110 → 0x52494646（"RIFF"）；0x22211c+0x222120 → 0x2e736e64
 *        （".snd"，Sun/NeXT AU 魔数）；0x2222e8+0x2222ec → 0x57415645（"WAVE"）；
 *        0x222304..0x222314 → 0x666d7420（"fmt "）与 0x64617461（"data"）。
 *     ② 调用面全是 freealut 的 InputStream 层具名件：_alutInputStreamReadInt32BE ×8 /
 *        ReadUInt32LE ×4 / ReadUInt16LE ×4 / Skip ×4 / Read ×2 / EOF / GetRemainingLength ×2 /
 *        GetFileName、_alutSetError ×3、_alutCodecLinear、_alutInputGetData。
 *     ③ 调用者是 _alutCreateBufferFromInputStream（0x2225cc）与 _alutLoadMemoryFromInputStream。
 *   libjpeg / IJG（§8）
 *     ① 具名邻居：jinit_1pass_quantizer 0x2bad30(968 B)、jinit_2pass_quantizer 0x2bc654(408 B)、
 *        jdiv_round_up 0x2bc7ec；更左边的 jinit_* / jpeg_alloc_* / jpeg_make_d_derived_tbl
 *        全在 0x2b3xxx..0x2bexxx 这一片（anon_batch4 已把 jdhuff / jdphuff / jdmarker /
 *        jdinput / jdmerge / jdsample 六个 TU 定名）。
 *     ② 结构偏移：两处 `str rX,[cinfo,#0x1a8]`（0x2bad74 / 0x2bc68c）就是 jpeglib 的
 *        cinfo->cquantize；方法槽写在 [r0] / [r0+8] / [r0+0xc]。
 *   vorbisfile（§9）
 *     ① 调用面就是 vorbisfile 的固定组合：vorbis_synthesis / _blockin / _pcmout ×4 /
 *        _block_clear / _dsp_clear / _info_clear / _comment_clear + ogg_stream_pagein /
 *        _packetout / ogg_page_bos / ogg_page_serialno ×2 / ogg_stream_reset_serialno。
 *     ② 调用者只有 ov_read+0x34 与 ov_pcm_seek+0x310 两处；状态字段在 OggVorbis_File+0x58。
 *   Box2D（§10）
 *     ① 调用者具名：b2CollidePolygons（0x2de464）的两条 bl（+0x40 / +0x78）；同区还有
 *        b2CollideEdgeAndPolygon 0x2de0bc、b2EPCollider::Collide 0x2dd360、b2DynamicTree。
 *     ② 形态：vpush {d8,d9} + vmul.f32 / vmla.f32 / vsub.f32 的连续投影计算，读多边形顶点数。
 *
 * ══ 选段口径（写死，便于复核）═══════════════════════════════════════
 *   分母：asm/anon_splits.tsv 521 段 / 399,240 B；其中 ≥512 B 的 137 段 / 342,112 B。
 *   热度：静态 in-degree = 全库 bl/blx 落点计数，**ARM 与 Thumb-2 两种编码一起扫**
 *        （ARM: 0xEB/0xFA 立即数型；Thumb-2: 0xF0xx/0xDxxx 双半字型），共 46,204 个调用点、
 *        10,183 个不同目标；没有任何运行期计数（见全局 open 2）。
 *   候选：本卡写入时刻未被任何手写卡锚点覆盖、≥512 B、in-degree ≥2 的 ARM 段。
 *   排序：in-degree 降序、同分按 size 降序；本批 10 段占第 1..10 名
 *        （in-degree 5/5/4/4/4/3/2/2/2/2）。
 *   排除 A（Thumb-2，14 段）：候选集里 in-degree 最高的两段其实是 Thumb-2 ——
 *        0x2f8e0a（1,170 B，in=51）、0x317798（684 B，in=7）；其后还有 0x2e8c38(4)、
 *        0x2fa06c(3)、0x2fb894(3)、0x2e90fc(3)、0x2fb68c(3)、0x317ba8(3)、0x2fec70(2)、
 *        0x309b08(2)、0x2f0444(2)、0x2f9ab6(2)、0x2f08c6(2)、0x2f1142(2)。
 *        全部留给单独的 Thumb 批：asm/instructions.jsonl 对**无符号** Thumb 段按 ARM 解码
 *        （例如 0x2e8c38 在全局索引里是 `svcmi`），混进本卡会让 verify_reverse_v1 的助记符
 *        比对整体失真；anon_batch2 已用同一理由跳过 5 段 Thumb-2，本卡沿用。这 14 段的
 *        地址与 in-degree 已列在此处，下一批可直接取用。
 *   排除 B（单函数过大）：0x25ff54（23,556 B，in=3）是 pcre 的 compile_branch 主体
 *        （体内 42 处 '?'、33 处 '0'、20 处 ')'、13 处 '\\' 的**模式字符**立即数，444 B 帧，
 *        pcre_compile2 两处 bl + 一处自递归），它和 26,424 B 的父标签 0x25fe2c 属于
 *        "一个函数一张卡"的量级，本批不出窗口。
 *   排除 C（重叠）：0x286b08（1,964 B，in=5）整体落在 0x28677c..0x2872b4 之内；本卡用 §2
 *        一个窗口把它连同 0x28677c 一起锚掉（两行 split 一起覆盖），不另开节。
 *
 * ══ 计数口径（写死）═══════════════════════════════════════════════════
 *   段        [start,end)      index 行  pop{..,pc}  跳转表  分支跳出  段尾非指令
 *   25e350    25e350..25ed60     644        2          1(162)      0     1 池字
 *   28677c    28677c..2872b4     718       10          2(90/90)    0     1 池字 + 4 误译
 *   2670bc    2670bc..2679bc     576        3          1(111)      0     2 误译
 *   25b5c4    25b5c4..25bba8     377        3          1(162)      0     1 误译
 *   25c788    25c788..25c988     128        3          0           0     1 误译
 *   265c10    265c10..266564     597        3          2(162/162)  0     0
 *   222040    222040..2225c8     354        2          1           0     4 池字
 *   2bb8b4    2bb8b4..2bbd94     312        1          0           0     1 误译
 *   230b68    230b68..230eb8     212        1          0           1 尾续 0
 *   2de214    2de214..2de460     147        2          0           0     0
 *   合计                        4,065      30          8           1     —
 *   —— index 行 = asm_index.py 对 [start,end) 的 4 B 栅格输出；"误译" = objdump 把池字或下一
 *      函数的预序言译成带条件后缀的"指令"（andeq / andseq / subeq 之类），按 README 规矩 3
 *      保留原文并就地标注。
 *
 * ══ 与其它卡的分工（2026-10-28 19:0x 复核）════════════════════════════
 *   anon_batch2 覆盖 25bbb0 / 25c2f8 / 25ceac / 25db38（都在 0x25b524 簇内）与 2b3f58 /
 *     2bb3c4 / 2bdb14 / 230048 / 230334 / 28b3fc；anon_batch3 覆盖 21362c / 153710 组 /
 *     230674 / 2d49b8 组；anon_batch4 覆盖 2b3bac..2bf198 十个 libjpeg 段；anon_26f1e8
 *     覆盖 pcre 的 match() 前 3,524 B；anon_268fb4 覆盖 0x268fb4 大块。本卡与它们零地址交集。
 *   本卡未收的同族待办：pcre 的 compile_branch 主体 0x25ff54（23,556 B）、0x25b524 簇首函数
 *     （10,856 B，被簇内 6 处调用）、0x265b58（184 B）、0x25fe2c（328 B），以及排除 A 的
 *     14 段 Thumb-2。
 *
 * ══ 匿名段覆盖账（本卡落盘后）═════════════════════════════════════
 *   asm/anon_splits.tsv 521 段 / 399,240 B；≥512 B 的 137 段 / 342,112 B
 *   落盘前已覆盖 41 段 / 93,656 B（anon_batch2 10 / anon_batch3 15 / anon_batch4 10 /
 *     anon_268fb4 1 / anon_26f1e8 1 / anon_319414 2 / 其余 2 段靠 anchor 命中）
 *   本卡 +11 行 / +16,276 B（§2 一个窗口覆盖 0x28677c 与 0x286b08 两行）
 *     →  52 段 / 109,932 B = 10.0% 段数 / 27.5% 字节数
 *   ≥512 B 的未覆盖段：112 → 101
 *
 * ══ 全局 open（本卡级别，不是逐节 open）═════════════════════════════
 *   1. 全部 10 节只有静态字节证据（指令锚 + 字段偏移 + 常量表 + 调用点），没有一条
 *      oracle_anchored / device_anchored；没跑行为差分，也没碰设备。
 *   2. 热度只有静态 in-degree；经函数指针槽 / 跳转表间接到达的次数不在分母里。已知偏差：
 *      pcre 的静态例程多由结构体方法槽分派，§2 也只暴露一个外部入口 —— in-degree 低的段
 *      不代表不热。
 *   3. 库身份 proven 到"哪个库 / 哪个源文件"；**函数级名字一律 narrowed**：pcre 的 5 节、
 *      freealut 的载入器、libjpeg 的量化器、Box2D 的分离辅助都没与上游源码逐行对照。
 *   4. §1/§3/§4/§5/§6 共享 libpcre；它们之间的 bl 关系已在各节"调用面"写清，但没有画出
 *      整条编译/研究流水线。
 *   5. 本卡只新增 cards/anon_batch5.c、claims-batchBZ.jsonl 与 10 个 asm/index-anon_*.tsv
 *      （其中 index-anon_28677c.tsv 由原来只覆盖 908 B 的版本重生成为全函数 2,872 B）；
 *      没有改名、没有改别人的卡、没有碰设备、没有 git 操作。
 *
 * ══ 校验（每节单独切出来跑，脚本原样未改）═════════════════════════════
 *   check_card_anchors.py --card <本节切片> --index asm/index-anon_<起址>.tsv
 *     → 10/10 节 RESULT EXACT，合计 4,065 条，missing / extra / mismatch 全 0
 *   跨卡：与 cards/*.c 其余卡片的 @0x 地址交集为 0。
 *
 * ══ claims 对照 ═══════════════════════════════════════════════════════
 *   claims-batchBZ.jsonl: BZ5-001..BZ5-018
 * ════════════════════════════════════════════════════════════════════ */


/* ═══════════════════════════════════════════════════════════════════════
 * §1  anon_25e350  0x25e350..0x25ed60  2,576 B / 644 条  in-degree 5
 * libpcre 8.x —— pcre_study.c 的静态递归遍历例程（162 项 opcode 表 + 1000 次预算闸门）
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 存 [sp+0x10]（结构基址，本窗口内未解引用，见 open 1）；r1 = 编译后码流指针（唯一
 *      用法是 0x25e38c 的 ldrb 取 opcode）；r2 → r7（未定）；r3 = 选项字（bit11 = PCRE_UTF8）；
 *      第 5 参 [sp+0x58] → r6（未定）；第 6 参 [sp+0x5c] → r12（指针，指向一个计数器）。
 *
 * 身份证据（五条，均可复核）
 *   ① 调用面：全库唯一外部 bl 落在本段入口，来自 0x266704 = pcre_study+0x124
 *      （pcre_study 0x2665e0，752 B，.dynsym 具名）。段内另有 4 处 bl 落回自身
 *      （0x25e6c8 / 0x25e820 / 0x25e93c / 0x25ed10，全部指向 0x25e350）⇒ 递归；
 *      2 处 bl 到 _pcre_find_bracket（0x25e0fc，596 B，具名导出）。
 *   ② 162 项操作码分派：0x25e3d8 的 cmp r3,#161 + 0x25e3dc 的 addls pc,pc,r3,lsl #2，
 *      表体 0x25e3e0 起 162 条 b（多数落 0x25e684 / 0x25e69c，个别落 0x25ea10 等实质分支）。
 *      pcre 8.x 的操作码总数 = 162（_pcre_OP_lengths 表长 162 B，0x38ba04）。
 *   ③ opcode 头长判定：0x25e398..0x25e3c0 把 opcode 归一到 {133,134,138,139} 时判成 +5
 *      （addls r4,r1,#5），其余 +3（addhi r4,r1,#3），随后从 r4 取体内 opcode。与
 *      _pcre_OP_lengths 逐码对齐：该表 [133]=[134]=[138]=[139]=5、[123]=3（本卡读 0x38ba04
 *      的 162 B 复核过）。
 *   ④ UTF-8 位：0x25e358 的 ubfx r10,r3,#0xb,#1 只取第 4 参 bit11；pcre.h 的 PCRE_UTF8 =
 *      0x00000800，正是 bit11。该位在 0x25e708 的 cmp r10,#0 处决定正常返回还是失败返回。
 *   ⑤ 预算闸门：0x25e374..0x25e388 读 [r12]、cmp #1000、自增、写回，bgt 0x25e710（mvn r0,#0）
 *      —— 每次进入自增，超过 1000 直接返回 -1。这是 study 期防指数爆炸的粗上限。
 *
 * 出口：2 个 —— 0x25e704（add sp,#52 + pop {r4..r11,pc}，r0 来自 [sp+0x18]）与 0x25e718
 *       （同一 pop，r0 = -1，预算/失败路径）。窗口内 0 条分支跳出。
 * 边界：段尾 0x25ed5c 是池字 0xfffffb8c（GOT 相对偏移），objdump 译成 andseq，非指令。
 * open：1. r0 的结构基址在本窗口内没有任何解引用 —— 只能证"传进来、存栈、不碰"。
 *       2. 与 pcre_study.c 的 set_start_bits / find_firstassertedchar 二选一未定。线索：本段
 *          调 _pcre_find_bracket（取 class/组的边界）并写 0x25e3d0 处的 12 B 本地缓冲，更像
 *          "扫描起始位图"一侧；另一侧是 §6（0x265c10，带 32/16 步长）。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x25e350 0x25ed60 anon_25e350 pcre_study_startbit_walker */

/* @0x25e350 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言：9 寄存器 + 52 B 帧（0x58 = 首个栈参数偏移） */
/* @0x25e354 sub sp, sp, #52 —— 帧 52 B，与 [sp+0x58]/[sp+0x5c] 两个栈参数对齐 */
/* @0x25e358 ubfx r10, r3, #0xb, #0x1 —— 取第 4 参 bit11 = PCRE_UTF8(0x800) */
/* @0x25e35c ldr r8, [pc, #0x9f4] */
/* @0x25e360 ldr r12, [sp, #0x5c] */
/* @0x25e364 mov r7, r2 */
/* @0x25e368 str r3, [sp, #0xc] */
/* @0x25e36c add r8, pc, r8 */
/* @0x25e370 str r0, [sp, #0x10] */
/* @0x25e374 ldr r3, [r12] */
/* @0x25e378 ldr r6, [sp, #0x58] */
/* @0x25e37c cmp r3, #1000 —— 预算闸门：计数器 > 1000 就放弃 */
/* @0x25e380 add r3, r3, #1 */
/* @0x25e384 str r3, [r12] */
/* @0x25e388 bgt 0x25e710 <_pcre_find_bracket+0x614> —— bgt → 0x25e710（返回 -1） */
/* @0x25e38c ldrb r3, [r1] —— 读编译后码流的第一个 opcode */
/* @0x25e390 mov r5, #0 */
/* @0x25e394 ldr r12, [sp, #0xc] */
/* @0x25e398 add r2, r3, #123 —— opcode + 123 / + 118 归一化，判 +3 还是 +5 头长 */
/* @0x25e39c add r3, r3, #118 */
/* @0x25e3a0 and r12, r12, #33554432 */
/* @0x25e3a4 str r5, [sp, #0x14] */
/* @0x25e3a8 uxtb r3, r3 */
/* @0x25e3ac uxtb r2, r2 */
/* @0x25e3b0 cmp r3, #1 */
/* @0x25e3b4 cmphi r2, #1 */
/* @0x25e3b8 str r12, [sp, #0x20] */
/* @0x25e3bc addhi r4, r1, #3 */
/* @0x25e3c0 addls r4, r1, #5 */
/* @0x25e3c4 mvn r12, #0 */
/* @0x25e3c8 str r12, [sp, #0x18] */
/* @0x25e3cc ldrb r3, [r4] */
/* @0x25e3d0 add r12, sp, #40 */
/* @0x25e3d4 str r12, [sp, #0x1c] */
/* @0x25e3d8 cmp r3, #161 —— 162 项 opcode 表：cmp #161 + 索引跳转 */
/* @0x25e3dc addls pc, pc, r3, lsl #2 —— addls pc,pc,r3,lsl #2 —— 表体从下一条开始 */
/* @0x25e3e0 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e3e4 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e3e8 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3ec b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3f0 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3f4 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3f8 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3fc b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e400 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e404 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e408 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e40c b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e410 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e414 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e418 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e41c b 0x25e708 <_pcre_find_bracket+0x60c> */
/* @0x25e420 b 0x25e698 <_pcre_find_bracket+0x59c> */
/* @0x25e424 b 0x25e698 <_pcre_find_bracket+0x59c> */
/* @0x25e428 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e42c b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e430 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e434 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e438 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e43c b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e440 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e444 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e448 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e44c b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e450 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e454 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e458 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e45c b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e460 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e464 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e468 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e46c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e470 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e474 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e478 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e47c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e480 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e484 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e488 b 0x25e964 <_pcre_find_bracket+0x868> */
/* @0x25e48c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e490 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e494 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e498 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e49c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4a0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4a4 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4a8 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4ac b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4b0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4b4 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4b8 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4bc b 0x25e964 <_pcre_find_bracket+0x868> */
/* @0x25e4c0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4c4 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4c8 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4cc b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4d0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4d4 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4d8 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4dc b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4e0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4e4 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4e8 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4ec b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4f0 b 0x25e964 <_pcre_find_bracket+0x868> */
/* @0x25e4f4 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4f8 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4fc b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e500 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e504 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e508 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e50c b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e510 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e514 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e518 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e51c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e520 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e524 b 0x25e964 <_pcre_find_bracket+0x868> */
/* @0x25e528 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e52c b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e530 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e534 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e538 b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e53c b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e540 b 0x25eb64 <_pcre_find_bracket+0xa68> */
/* @0x25e544 b 0x25eb64 <_pcre_find_bracket+0xa68> */
/* @0x25e548 b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e54c b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e550 b 0x25eb84 <_pcre_find_bracket+0xa88> */
/* @0x25e554 b 0x25eb84 <_pcre_find_bracket+0xa88> */
/* @0x25e558 b 0x25e9e4 <_pcre_find_bracket+0x8e8> */
/* @0x25e55c b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e560 b 0x25eb64 <_pcre_find_bracket+0xa68> */
/* @0x25e564 b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e568 b 0x25eb84 <_pcre_find_bracket+0xa88> */
/* @0x25e56c b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e570 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e574 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e578 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e57c b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e580 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e584 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e588 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e58c b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e590 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e594 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e598 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e59c b 0x25eb08 <_pcre_find_bracket+0xa0c> */
/* @0x25e5a0 b 0x25eb08 <_pcre_find_bracket+0xa0c> */
/* @0x25e5a4 b 0x25eb08 <_pcre_find_bracket+0xa0c> */
/* @0x25e5a8 b 0x25eaa4 <_pcre_find_bracket+0x9a8> */
/* @0x25e5ac b 0x25eaa4 <_pcre_find_bracket+0x9a8> */
/* @0x25e5b0 b 0x25e830 <_pcre_find_bracket+0x734> */
/* @0x25e5b4 b 0x25e830 <_pcre_find_bracket+0x734> */
/* @0x25e5b8 b 0x25e778 <_pcre_find_bracket+0x67c> */
/* @0x25e5bc b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e5c0 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5c4 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5c8 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5cc b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5d0 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5d4 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e5d8 b 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e5dc b 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e5e0 b 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e5e4 b 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e5e8 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5ec b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5f0 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5f4 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5f8 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5fc b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e600 b 0x25e750 <_pcre_find_bracket+0x654> */
/* @0x25e604 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e608 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e60c b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e610 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e614 b 0x25e750 <_pcre_find_bracket+0x654> */
/* @0x25e618 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e61c b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e620 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e624 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e628 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e62c b 0x25e71c <_pcre_find_bracket+0x620> */
/* @0x25e630 b 0x25e71c <_pcre_find_bracket+0x620> */
/* @0x25e634 b 0x25e71c <_pcre_find_bracket+0x620> */
/* @0x25e638 b 0x25ea88 <_pcre_find_bracket+0x98c> */
/* @0x25e63c b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e640 b 0x25ea88 <_pcre_find_bracket+0x98c> */
/* @0x25e644 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e648 b 0x25ea88 <_pcre_find_bracket+0x98c> */
/* @0x25e64c b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e650 b 0x25ea88 <_pcre_find_bracket+0x98c> */
/* @0x25e654 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e658 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e65c b 0x25e710 <_pcre_find_bracket+0x614> */
/* @0x25e660 b 0x25e710 <_pcre_find_bracket+0x614> */
/* @0x25e664 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e668 b 0x25e71c <_pcre_find_bracket+0x620> */
/* @0x25e66c ldrb r2, [r4, #0x1] */
/* @0x25e670 ldrb r3, [r4, #0x2] */
/* @0x25e674 orr r3, r3, r2, lsl #8 */
/* @0x25e678 ldrb r3, [r4, r3]! */
/* @0x25e67c cmp r3, #119 */
/* @0x25e680 beq 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e684 ldr r2, [pc, #0x6d0] */
/* @0x25e688 ldr r2, [r8, r2] */
/* @0x25e68c ldrb r3, [r2, r3] */
/* @0x25e690 ldrb r3, [r4, r3]! */
/* @0x25e694 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e698 add r4, r4, #2 */
/* @0x25e69c ldrb r3, [r4, #0x1] */
/* @0x25e6a0 add r5, r5, #1 */
/* @0x25e6a4 add r4, r4, #1 */
/* @0x25e6a8 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e6ac ldr r12, [sp, #0x5c] */
/* @0x25e6b0 mov r1, r4 */
/* @0x25e6b4 str r6, [sp] */
/* @0x25e6b8 mov r2, r7 */
/* @0x25e6bc ldr r0, [sp, #0x10] */
/* @0x25e6c0 str r12, [sp, #0x4] */
/* @0x25e6c4 ldr r3, [sp, #0xc] */
/* @0x25e6c8 bl 0x25e350 <_pcre_find_bracket+0x254> */
/* @0x25e6cc cmp r0, #0 */
/* @0x25e6d0 blt 0x25e700 <_pcre_find_bracket+0x604> */
/* @0x25e6d4 add r5, r5, r0 */
/* @0x25e6d8 ldrb r2, [r4, #0x1] */
/* @0x25e6dc ldrb r3, [r4, #0x2] */
/* @0x25e6e0 orr r3, r3, r2, lsl #8 */
/* @0x25e6e4 ldrb r3, [r4, r3]! */
/* @0x25e6e8 cmp r3, #119 */
/* @0x25e6ec beq 0x25e6d8 <_pcre_find_bracket+0x5dc> */
/* @0x25e6f0 ldrb r3, [r4, #0x3] */
/* @0x25e6f4 add r4, r4, #3 */
/* @0x25e6f8 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e6fc mvn r0, #2 */
/* @0x25e700 add sp, sp, #52 */
/* @0x25e704 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1：正常返回（r0 = [sp+0x18]） */
/* @0x25e708 cmp r10, #0 —— 按 bit11（UTF-8）决定返回路径 */
/* @0x25e70c beq 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e710 mvn r0, #0 —— 出口 2 的返回值 -1 */
/* @0x25e714 add sp, sp, #52 */
/* @0x25e718 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2：预算/失败返回 */
/* @0x25e71c ldr r2, [pc, #0x638] */
/* @0x25e720 ldr r2, [r8, r2] */
/* @0x25e724 ldrb r3, [r2, r3] */
/* @0x25e728 add r3, r4, r3 */
/* @0x25e72c ldrb r1, [r3, #0x1] */
/* @0x25e730 ldrb r2, [r3, #0x2] */
/* @0x25e734 orr r2, r2, r1, lsl #8 */
/* @0x25e738 ldrb r2, [r3, r2]! */
/* @0x25e73c cmp r2, #119 */
/* @0x25e740 beq 0x25e72c <_pcre_find_bracket+0x630> */
/* @0x25e744 add r4, r3, #3 */
/* @0x25e748 ldrb r3, [r3, #0x3] */
/* @0x25e74c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e750 ldrb r2, [r4, #0x1] */
/* @0x25e754 ldrb r3, [r4, #0x2] */
/* @0x25e758 orr r3, r3, r2, lsl #8 */
/* @0x25e75c add r2, r4, r3 */
/* @0x25e760 ldrb r3, [r4, r3] */
/* @0x25e764 cmp r3, #119 */
/* @0x25e768 beq 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e76c add r4, r2, #3 */
/* @0x25e770 ldrb r3, [r2, #0x3] */
/* @0x25e774 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e778 ldrb r12, [r4, #0x1] */
/* @0x25e77c ldrb r3, [r4, #0x2] */
/* @0x25e780 orr r12, r3, r12, lsl #8 */
/* @0x25e784 add r12, r7, r12 */
/* @0x25e788 mov r3, r12 */
/* @0x25e78c ldrb r1, [r3, #0x1] */
/* @0x25e790 ldrb r2, [r3, #0x2] */
/* @0x25e794 orr r2, r2, r1, lsl #8 */
/* @0x25e798 ldrb r2, [r3, r2]! */
/* @0x25e79c cmp r2, #119 */
/* @0x25e7a0 beq 0x25e78c <_pcre_find_bracket+0x690> */
/* @0x25e7a4 cmp r4, r3 */
/* @0x25e7a8 movhs r3, #0 */
/* @0x25e7ac movlo r3, #1 */
/* @0x25e7b0 cmp r4, r12 */
/* @0x25e7b4 movls r3, #0 */
/* @0x25e7b8 cmp r3, #0 */
/* @0x25e7bc bne 0x25ebe4 <_pcre_find_bracket+0xae8> */
/* @0x25e7c0 cmp r6, #0 */
/* @0x25e7c4 beq 0x25e7f4 <_pcre_find_bracket+0x6f8> */
/* @0x25e7c8 ldr r3, [r6, #0x4] */
/* @0x25e7cc cmp r12, r3 */
/* @0x25e7d0 beq 0x25ebe4 <_pcre_find_bracket+0xae8> */
/* @0x25e7d4 mov r3, r6 */
/* @0x25e7d8 b 0x25e7e8 <_pcre_find_bracket+0x6ec> */
/* @0x25e7dc ldr r2, [r3, #0x4] */
/* @0x25e7e0 cmp r12, r2 */
/* @0x25e7e4 beq 0x25ebe4 <_pcre_find_bracket+0xae8> */
/* @0x25e7e8 ldr r3, [r3] */
/* @0x25e7ec cmp r3, #0 */
/* @0x25e7f0 bne 0x25e7dc <_pcre_find_bracket+0x6e0> */
/* @0x25e7f4 ldr r0, [sp, #0x5c] */
/* @0x25e7f8 add r3, sp, #40 */
/* @0x25e7fc mov r1, r12 */
/* @0x25e800 str r3, [sp] */
/* @0x25e804 mov r2, r7 */
/* @0x25e808 ldr r3, [sp, #0xc] */
/* @0x25e80c str r0, [sp, #0x4] */
/* @0x25e810 add r4, r4, #3 */
/* @0x25e814 ldr r0, [sp, #0x10] */
/* @0x25e818 str r6, [sp, #0x28] */
/* @0x25e81c str r12, [sp, #0x2c] */
/* @0x25e820 bl 0x25e350 <_pcre_find_bracket+0x254> */
/* @0x25e824 ldrb r3, [r4] */
/* @0x25e828 add r5, r5, r0 */
/* @0x25e82c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e830 ldr r12, [sp, #0x20] */
/* @0x25e834 cmp r12, #0 */
/* @0x25e838 bne 0x25ec10 <_pcre_find_bracket+0xb14> */
/* @0x25e83c ldr r12, [sp, #0x10] */
/* @0x25e840 ldrb r1, [r4, #0x1] */
/* @0x25e844 ldrb r3, [r4, #0x2] */
/* @0x25e848 ldrh r9, [r12, #36] */
/* @0x25e84c ldrh r2, [r12, #34] */
/* @0x25e850 orr r1, r3, r1, lsl #8 */
/* @0x25e854 ldrb r11, [r4, #0x3] */
/* @0x25e858 ldrb r3, [r4, #0x4] */
/* @0x25e85c mla r9, r9, r1, r2 */
/* @0x25e860 orr r11, r3, r11, lsl #8 */
/* @0x25e864 cmp r11, #0 */
/* @0x25e868 ldr r0, [sp, #0x10] */
/* @0x25e86c sub r12, r11, #1 */
/* @0x25e870 mvn r11, #-2147483648 */
/* @0x25e874 add r9, r0, r9 */
/* @0x25e878 beq 0x25ec08 <_pcre_find_bracket+0xb0c> */
/* @0x25e87c str r5, [sp, #0x24] */
/* @0x25e880 mov r5, r12 */
/* @0x25e884 ldrb r2, [r9] */
/* @0x25e888 mov r0, r7 */
/* @0x25e88c ldrb r3, [r9, #0x1] */
/* @0x25e890 mov r1, r10 */
/* @0x25e894 orr r2, r3, r2, lsl #8 */
/* @0x25e898 bl 0x25e0fc <_pcre_find_bracket> */
/* @0x25e89c subs r12, r0, #0 */
/* @0x25e8a0 beq 0x25ed2c <_pcre_find_bracket+0xc30> */
/* @0x25e8a4 mov r3, r12 */
/* @0x25e8a8 ldrb r1, [r3, #0x1] */
/* @0x25e8ac ldrb r2, [r3, #0x2] */
/* @0x25e8b0 orr r2, r2, r1, lsl #8 */
/* @0x25e8b4 ldrb r2, [r3, r2]! */
/* @0x25e8b8 cmp r2, #119 */
/* @0x25e8bc beq 0x25e8a8 <_pcre_find_bracket+0x7ac> */
/* @0x25e8c0 cmp r4, r3 */
/* @0x25e8c4 movhs r3, #0 */
/* @0x25e8c8 movlo r3, #1 */
/* @0x25e8cc cmp r4, r12 */
/* @0x25e8d0 movls r3, #0 */
/* @0x25e8d4 cmp r3, #0 */
/* @0x25e8d8 bne 0x25ebf8 <_pcre_find_bracket+0xafc> */
/* @0x25e8dc cmp r6, #0 */
/* @0x25e8e0 beq 0x25e910 <_pcre_find_bracket+0x814> */
/* @0x25e8e4 ldr r2, [r6, #0x4] */
/* @0x25e8e8 cmp r2, r12 */
/* @0x25e8ec beq 0x25ebf8 <_pcre_find_bracket+0xafc> */
/* @0x25e8f0 mov r3, r6 */
/* @0x25e8f4 b 0x25e904 <_pcre_find_bracket+0x808> */
/* @0x25e8f8 ldr r2, [r3, #0x4] */
/* @0x25e8fc cmp r2, r12 */
/* @0x25e900 beq 0x25ebf8 <_pcre_find_bracket+0xafc> */
/* @0x25e904 ldr r3, [r3] */
/* @0x25e908 cmp r3, #0 */
/* @0x25e90c bne 0x25e8f8 <_pcre_find_bracket+0x7fc> */
/* @0x25e910 ldr r2, [sp, #0x5c] */
/* @0x25e914 add r0, sp, #40 */
/* @0x25e918 mov r1, r12 */
/* @0x25e91c str r0, [sp] */
/* @0x25e920 ldr r3, [sp, #0xc] */
/* @0x25e924 sub r5, r5, #1 */
/* @0x25e928 str r2, [sp, #0x4] */
/* @0x25e92c mov r2, r7 */
/* @0x25e930 ldr r0, [sp, #0x10] */
/* @0x25e934 str r12, [sp, #0x2c] */
/* @0x25e938 str r6, [sp, #0x28] */
/* @0x25e93c bl 0x25e350 <_pcre_find_bracket+0x254> */
/* @0x25e940 ldr r12, [sp, #0x10] */
/* @0x25e944 ldrh r3, [r12, #36] */
/* @0x25e948 add r9, r9, r3 */
/* @0x25e94c cmp r11, r0 */
/* @0x25e950 movge r11, r0 */
/* @0x25e954 cmn r5, #1 */
/* @0x25e958 bne 0x25e884 <_pcre_find_bracket+0x788> */
/* @0x25e95c ldr r5, [sp, #0x24] */
/* @0x25e960 b 0x25ec08 <_pcre_find_bracket+0xb0c> */
/* @0x25e964 ldrb r1, [r4, #0x1] */
/* @0x25e968 cmp r10, #0 */
/* @0x25e96c ldrb r3, [r4, #0x2] */
/* @0x25e970 add r2, r4, #4 */
/* @0x25e974 orr r3, r3, r1, lsl #8 */
/* @0x25e978 add r5, r3, r5 */
/* @0x25e97c beq 0x25ebd8 <_pcre_find_bracket+0xadc> */
/* @0x25e980 ldrb r3, [r4, #0x3] */
/* @0x25e984 cmp r3, #191 */
/* @0x25e988 bls 0x25ebd8 <_pcre_find_bracket+0xadc> */
/* @0x25e98c ldr r1, [pc, #0x3cc] */
/* @0x25e990 and r3, r3, #63 */
/* @0x25e994 ldr r1, [r8, r1] */
/* @0x25e998 ldrb r3, [r1, r3] */
/* @0x25e99c add r4, r2, r3 */
/* @0x25e9a0 ldrb r3, [r2, r3] */
/* @0x25e9a4 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e9a8 ldr r2, [pc, #0x3ac] */
/* @0x25e9ac cmp r10, #0 */
/* @0x25e9b0 ldr r2, [r8, r2] */
/* @0x25e9b4 ldrb r3, [r2, r3] */
/* @0x25e9b8 add r4, r4, r3 */
/* @0x25e9bc beq 0x25ebd0 <_pcre_find_bracket+0xad4> */
/* @0x25e9c0 ldrb r3, [r4, #-0x1] */
/* @0x25e9c4 cmp r3, #191 */
/* @0x25e9c8 bls 0x25ebd0 <_pcre_find_bracket+0xad4> */
/* @0x25e9cc ldr r2, [pc, #0x38c] */
/* @0x25e9d0 and r3, r3, #63 */
/* @0x25e9d4 ldr r2, [r8, r2] */
/* @0x25e9d8 ldrb r3, [r2, r3] */
/* @0x25e9dc ldrb r3, [r4, r3]! */
/* @0x25e9e0 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e9e4 ldrb r1, [r4, #0x3] */
/* @0x25e9e8 ldrb r2, [r4, #0x1] */
/* @0x25e9ec sub r1, r1, #15 */
/* @0x25e9f0 ldrb r3, [r4, #0x2] */
/* @0x25e9f4 cmp r1, #1 */
/* @0x25e9f8 orr r2, r3, r2, lsl #8 */
/* @0x25e9fc movhi r1, #4 */
/* @0x25ea00 movls r1, #6 */
/* @0x25ea04 ldrb r3, [r4, r1]! */
/* @0x25ea08 add r5, r2, r5 */
/* @0x25ea0c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ea10 ldr r12, [sp, #0x18] */
/* @0x25ea14 cmp r12, #0 */
/* @0x25ea18 strlt r5, [sp, #0x18] */
/* @0x25ea1c blt 0x25ea44 <_pcre_find_bracket+0x948> */
/* @0x25ea20 ldr r12, [sp, #0x14] */
/* @0x25ea24 eor r2, r12, #1 */
/* @0x25ea28 ldr r12, [sp, #0x18] */
/* @0x25ea2c cmp r5, r12 */
/* @0x25ea30 movge r2, #0 */
/* @0x25ea34 andlt r2, r2, #1 */
/* @0x25ea38 cmp r2, #0 */
/* @0x25ea3c movne r12, r5 */
/* @0x25ea40 str r12, [sp, #0x18] */
/* @0x25ea44 cmp r3, #119 */
/* @0x25ea48 bne 0x25ed50 <_pcre_find_bracket+0xc54> */
/* @0x25ea4c mov r5, #0 */
/* @0x25ea50 ldrb r3, [r4, #0x3] */
/* @0x25ea54 str r5, [sp, #0x14] */
/* @0x25ea58 add r4, r4, #3 */
/* @0x25ea5c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ea60 cmp r10, #0 */
/* @0x25ea64 add r5, r5, #1 */
/* @0x25ea68 add r2, r4, #2 */
/* @0x25ea6c beq 0x25ea7c <_pcre_find_bracket+0x980> */
/* @0x25ea70 ldrb r3, [r4, #0x1] */
/* @0x25ea74 cmp r3, #191 */
/* @0x25ea78 bhi 0x25e98c <_pcre_find_bracket+0x890> */
/* @0x25ea7c ldrb r3, [r4, #0x2] */
/* @0x25ea80 mov r4, r2 */
/* @0x25ea84 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ea88 ldr r1, [pc, #0x2cc] */
/* @0x25ea8c ldrb r2, [r4, #0x1] */
/* @0x25ea90 ldr r1, [r8, r1] */
/* @0x25ea94 ldrb r3, [r1, r3] */
/* @0x25ea98 add r3, r3, r2 */
/* @0x25ea9c ldrb r3, [r4, r3]! */
/* @0x25eaa0 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25eaa4 ldr r12, [sp, #0x20] */
/* @0x25eaa8 cmp r12, #0 */
/* @0x25eaac movne r11, #0 */
/* @0x25eab0 beq 0x25ec5c <_pcre_find_bracket+0xb60> */
/* @0x25eab4 add r4, r4, #3 */
/* @0x25eab8 ldrb r3, [r4] */
/* @0x25eabc sub r2, r3, #98 */
/* @0x25eac0 uxtb r2, r2 */
/* @0x25eac4 cmp r2, #11 */
/* @0x25eac8 movhi r2, r11 */
/* @0x25eacc bhi 0x25eb00 <_pcre_find_bracket+0xa04> */
/* @0x25ead0 mov r0, #1 */
/* @0x25ead4 movw r1, #0x533 */
/* @0x25ead8 lsl r2, r0, r2 */
/* @0x25eadc and r1, r2, r1 */
/* @0x25eae0 cmp r1, #0 */
/* @0x25eae4 bne 0x25ec18 <_pcre_find_bracket+0xb1c> */
/* @0x25eae8 tst r2, #2240 */
/* @0x25eaec bne 0x25ec3c <_pcre_find_bracket+0xb40> */
/* @0x25eaf0 tst r2, #524 */
/* @0x25eaf4 mov r2, r11 */
/* @0x25eaf8 ldrbne r3, [r4, #0x1] */
/* @0x25eafc addne r4, r4, #1 */
/* @0x25eb00 add r5, r5, r2 */
/* @0x25eb04 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25eb08 cmp r3, #112 */
/* @0x25eb0c addne r4, r4, #33 */
/* @0x25eb10 ldrbeq r2, [r4, #0x1] */
/* @0x25eb14 ldrbeq r3, [r4, #0x2] */
/* @0x25eb18 orreq r3, r3, r2, lsl #8 */
/* @0x25eb1c addeq r4, r4, r3 */
/* @0x25eb20 ldrb r3, [r4] */
/* @0x25eb24 sub r2, r3, #98 */
/* @0x25eb28 uxtb r2, r2 */
/* @0x25eb2c cmp r2, #11 */
/* @0x25eb30 bhi 0x25eb5c <_pcre_find_bracket+0xa60> */
/* @0x25eb34 mov r0, #1 */
/* @0x25eb38 movw r1, #0x533 */
/* @0x25eb3c lsl r2, r0, r2 */
/* @0x25eb40 and r1, r2, r1 */
/* @0x25eb44 cmp r1, #0 */
/* @0x25eb48 bne 0x25ec30 <_pcre_find_bracket+0xb34> */
/* @0x25eb4c tst r2, #2240 */
/* @0x25eb50 bne 0x25ed34 <_pcre_find_bracket+0xc38> */
/* @0x25eb54 tst r2, #524 */
/* @0x25eb58 bne 0x25ec2c <_pcre_find_bracket+0xb30> */
/* @0x25eb5c add r5, r5, #1 */
/* @0x25eb60 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25eb64 ldrb r3, [r4, #0x1] */
/* @0x25eb68 add r5, r5, #1 */
/* @0x25eb6c sub r3, r3, #15 */
/* @0x25eb70 cmp r3, #1 */
/* @0x25eb74 movhi r3, #2 */
/* @0x25eb78 movls r3, #4 */
/* @0x25eb7c ldrb r3, [r4, r3]! */
/* @0x25eb80 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25eb84 ldrb r2, [r4, #0x3] */
/* @0x25eb88 sub r2, r2, #15 */
/* @0x25eb8c cmp r2, #1 */
/* @0x25eb90 bhi 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25eb94 ldr r2, [pc, #0x1c0] */
/* @0x25eb98 add r4, r4, #2 */
/* @0x25eb9c ldr r2, [r8, r2] */
/* @0x25eba0 ldrb r3, [r2, r3] */
/* @0x25eba4 ldrb r3, [r4, r3]! */
/* @0x25eba8 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebac ldrb r2, [r4, #0x1] */
/* @0x25ebb0 sub r2, r2, #15 */
/* @0x25ebb4 cmp r2, #1 */
/* @0x25ebb8 bls 0x25eb94 <_pcre_find_bracket+0xa98> */
/* @0x25ebbc ldr r2, [pc, #0x198] */
/* @0x25ebc0 ldr r2, [r8, r2] */
/* @0x25ebc4 ldrb r3, [r2, r3] */
/* @0x25ebc8 ldrb r3, [r4, r3]! */
/* @0x25ebcc b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebd0 ldrb r3, [r4] */
/* @0x25ebd4 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebd8 ldrb r3, [r4, #0x4] */
/* @0x25ebdc mov r4, r2 */
/* @0x25ebe0 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebe4 mov r12, #1 */
/* @0x25ebe8 add r4, r4, #3 */
/* @0x25ebec str r12, [sp, #0x14] */
/* @0x25ebf0 ldrb r3, [r4] */
/* @0x25ebf4 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebf8 ldr r5, [sp, #0x24] */
/* @0x25ebfc mov r11, #0 */
/* @0x25ec00 mov r12, #1 */
/* @0x25ec04 str r12, [sp, #0x14] */
/* @0x25ec08 add r4, r4, #5 */
/* @0x25ec0c b 0x25eab8 <_pcre_find_bracket+0x9bc> */
/* @0x25ec10 mov r11, #0 */
/* @0x25ec14 b 0x25ec08 <_pcre_find_bracket+0xb0c> */
/* @0x25ec18 ldrb r3, [r4, #0x1] */
/* @0x25ec1c mov r2, #0 */
/* @0x25ec20 add r4, r4, #1 */
/* @0x25ec24 add r5, r5, r2 */
/* @0x25ec28 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ec2c add r5, r5, r0 */
/* @0x25ec30 ldrb r3, [r4, #0x1] */
/* @0x25ec34 add r4, r4, #1 */
/* @0x25ec38 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ec3c ldrb r1, [r4, #0x1] */
/* @0x25ec40 add r4, r4, #5 */
/* @0x25ec44 ldrb r2, [r4, #-0x3] */
/* @0x25ec48 ldrb r3, [r4] */
/* @0x25ec4c orr r2, r2, r1, lsl #8 */
/* @0x25ec50 mul r2, r2, r11 */
/* @0x25ec54 add r5, r5, r2 */
/* @0x25ec58 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ec5c ldrb r2, [r4, #0x1] */
/* @0x25ec60 mov r0, r7 */
/* @0x25ec64 ldrb r3, [r4, #0x2] */
/* @0x25ec68 mov r1, r10 */
/* @0x25ec6c orr r2, r3, r2, lsl #8 */
/* @0x25ec70 bl 0x25e0fc <_pcre_find_bracket> */
/* @0x25ec74 subs r12, r0, #0 */
/* @0x25ec78 beq 0x25ed2c <_pcre_find_bracket+0xc30> */
/* @0x25ec7c mov r3, r12 */
/* @0x25ec80 ldrb r1, [r3, #0x1] */
/* @0x25ec84 ldrb r2, [r3, #0x2] */
/* @0x25ec88 orr r2, r2, r1, lsl #8 */
/* @0x25ec8c ldrb r2, [r3, r2]! */
/* @0x25ec90 cmp r2, #119 */
/* @0x25ec94 beq 0x25ec80 <_pcre_find_bracket+0xb84> */
/* @0x25ec98 cmp r4, r3 */
/* @0x25ec9c movhs r3, #0 */
/* @0x25eca0 movlo r3, #1 */
/* @0x25eca4 cmp r4, r12 */
/* @0x25eca8 movls r3, #0 */
/* @0x25ecac cmp r3, #0 */
/* @0x25ecb0 bne 0x25ed1c <_pcre_find_bracket+0xc20> */
/* @0x25ecb4 cmp r6, #0 */
/* @0x25ecb8 beq 0x25ece8 <_pcre_find_bracket+0xbec> */
/* @0x25ecbc ldr r2, [r6, #0x4] */
/* @0x25ecc0 cmp r2, r12 */
/* @0x25ecc4 beq 0x25ed1c <_pcre_find_bracket+0xc20> */
/* @0x25ecc8 mov r3, r6 */
/* @0x25eccc b 0x25ecdc <_pcre_find_bracket+0xbe0> */
/* @0x25ecd0 ldr r2, [r3, #0x4] */
/* @0x25ecd4 cmp r2, r12 */
/* @0x25ecd8 beq 0x25ed1c <_pcre_find_bracket+0xc20> */
/* @0x25ecdc ldr r3, [r3] */
/* @0x25ece0 cmp r3, #0 */
/* @0x25ece4 bne 0x25ecd0 <_pcre_find_bracket+0xbd4> */
/* @0x25ece8 ldr r2, [sp, #0x5c] */
/* @0x25ecec add r0, sp, #40 */
/* @0x25ecf0 mov r1, r12 */
/* @0x25ecf4 str r0, [sp] */
/* @0x25ecf8 ldr r3, [sp, #0xc] */
/* @0x25ecfc str r2, [sp, #0x4] */
/* @0x25ed00 mov r2, r7 */
/* @0x25ed04 ldr r0, [sp, #0x10] */
/* @0x25ed08 str r6, [sp, #0x28] */
/* @0x25ed0c str r12, [sp, #0x2c] */
/* @0x25ed10 bl 0x25e350 <_pcre_find_bracket+0x254> */
/* @0x25ed14 mov r11, r0 */
/* @0x25ed18 b 0x25eab4 <_pcre_find_bracket+0x9b8> */
/* @0x25ed1c mov r12, #1 */
/* @0x25ed20 mov r11, #0 */
/* @0x25ed24 str r12, [sp, #0x14] */
/* @0x25ed28 b 0x25eab4 <_pcre_find_bracket+0x9b8> */
/* @0x25ed2c mvn r0, #1 */
/* @0x25ed30 b 0x25e700 <_pcre_find_bracket+0x604> */
/* @0x25ed34 ldrb r1, [r4, #0x1] */
/* @0x25ed38 add r4, r4, #5 */
/* @0x25ed3c ldrb r2, [r4, #-0x3] */
/* @0x25ed40 ldrb r3, [r4] */
/* @0x25ed44 orr r2, r2, r1, lsl #8 */
/* @0x25ed48 add r5, r2, r5 */
/* @0x25ed4c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ed50 ldr r0, [sp, #0x18] */
/* @0x25ed54 b 0x25e700 <_pcre_find_bracket+0x604> */
/* @0x25ed58 andseq r3, r9, r4, ror #17 */
/* @0x25ed5c .word 0xfffffb8c —— 池字 0xfffffb8c（GOT 相对偏移），非指令 */


/* ═══════════════════════════════════════════════════════════════════════
 * §2  anon_28677c  0x28677c..0x2872b4  2,872 B / 718 条  in-degree 3
 * spine-c（Esoteric Software Spine 运行时）spine-c/src/spine/Json.c 的递归下降解析器：字符串扫描器 + Json_parse
 * ─────────────────────────────────────────────────────────────────────
 * 身份证据（三条独立）
 *   ① 源码路径串（决定性）：0x2867f8 的 ldr r10,[pc,#0x2fc] 取池字 @0x286b00 = 0x001057ac，
 *      0x286800 的 add r10,pc,r10（pc = 0x286808）⇒ 0x3578e0，读出
 *      jni/../jni/yoyo/../../../spine-c/src/spine/Json.c —— 编译单元路径经 __FILE__ 留在 .rodata。
 *      同一片 rodata（0x3578b4 起）还并排放着 spIkConstraintData.c 的尾串，以及 0x3578e0 之后的
 *      %4x / ull / alse / rue（\uXXXX 的 sscanf 格式串 + null/true/false 的共享尾串）。
 *   ② 邻接具名件：前 spIkConstraintData_create 0x2866f0(104 B) / _dispose 0x286758(36 B)；
 *      后 Json_getError 0x2872b8(16 B) / Json_dispose 0x2872c8(88 B) —— 同一 spine-c 目标的
 *      相邻 TU。
 *   ③ 调用面：strncmp@plt(0xb65e0) ×3、strtod@plt(0xb6658) ×1、sscanf@plt(0xb68f8) ×2、
 *      malloc(0x285c10) ×1、calloc(0x285c4c) ×4 —— 只有 JSON 词法分析会同时要"三次定长比串
 *      + 一次 strtod + 两次 %4x 的 sscanf"。
 *
 * 段内两个函数（本卡一并锚，边界由序言/出口确定）
 *   0x28677c..0x286b08（908 B / 227 条）= 字符串/引号扫描器：入口 0x286788 的 sub sp,#20，
 *     0x286794 的 cmp r3,#34（'"'）必须在引号上，主循环 0x2867a8..0x2867d8 处理 '\\'（0x5c）
 *     转义（add r1,r1,#2 跳过被转义字符）；0x286858 有 90 项跳转表；只被 0x286d38 / 0x286e78 /
 *     0x286f64 三处调用（都在后半段内），自身不递归。
 *   0x286b08..0x2872b4（1,964 B / 491 条）= Json_parse 本体：入口 0x286b08 的 push {r4..r9,lr}，
 *     0x286b1c 的 sub r3,r3,#34 + 0x286b24 的 addls pc,pc,r3,lsl #2 = 按首字符 '"'(34)..'{'(123)
 *     的 90 项分派表；4 处自递归（0x286dc4 / 0x286f00 / 0x287050 / 0x2870fc 都 bl 0x286b08，
 *     即解析 object/array 的成员值）；外部入口是 Json_create+0x70（0x287390）直接 bl 0x286b08。
 *     ⇒ 0x28677c 是子例程、0x286b08 是入口。本卡窗口 [0x28677c,0x2872b4) 同时覆盖
 *       asm/anon_splits.tsv 的两行（28677c 908 B + 286b08 1964 B），两行一起销账。
 *
 * 出口：10 个 pop {r4..r11,pc}（0x2868d4 / 0x286a00 / 0x286f6c / 0x286fac / 0x28717c /
 *       0x2871ac / 0x2871e0 / 0x2871f8 / 0x287204 / 0x287210）；窗口内 0 条分支跳出。
 * 边界：0x2872a0 是池字 0x004cf9d4；0x2872a4..0x2872b0 四条是下一段指令流被 objdump 误译
 *       （umaaleq / subeq 带 pc 写回），按规矩 3 保留原文。
 * open：1. 两个静态例程在 Json.c 里的原名未证（本卡按形态记为 string_scanner / Json_parse）。
 *       2. Json 节点结构只证到 +0x1 / +0x14 / +0x1c 有 strb 写，字段语义未对齐。
 *       3. 数字解析（strtod 那一处）的精度语义未与本仓的 GML 数值语义对照。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x28677c 0x2872b4 anon_28677c spine_json_parse */

/* @0x28677c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 字符串扫描器入口（908 B 子例程） */
/* @0x286780 mov r4, r2 */
/* @0x286784 ldrb r3, [r2] —— r2 = JSON 文本指针 */
/* @0x286788 sub sp, sp, #20 */
/* @0x28678c mov r8, r0 */
/* @0x286790 mov r9, r1 */
/* @0x286794 cmp r3, #34 —— 首字符必须是 '"'(0x22) */
/* @0x286798 add r5, r2, #1 */
/* @0x28679c bne 0x2869ec <spIkConstraintData_dispose+0x294> */
/* @0x2867a0 mov r1, r5 */
/* @0x2867a4 mov r0, #0 */
/* @0x2867a8 ldrb r3, [r1] */
/* @0x2867ac cmp r3, #0 */
/* @0x2867b0 cmpne r3, #34 */
/* @0x2867b4 beq 0x2867dc <spIkConstraintData_dispose+0x84> */
/* @0x2867b8 cmp r3, #92 —— 转义符 '\\'(0x5c) 分支 */
/* @0x2867bc add r0, r0, #1 */
/* @0x2867c0 addne r1, r1, #1 */
/* @0x2867c4 bne 0x2867a8 <spIkConstraintData_dispose+0x50> */
/* @0x2867c8 add r1, r1, #2 */
/* @0x2867cc ldrb r3, [r1] */
/* @0x2867d0 cmp r3, #0 */
/* @0x2867d4 cmpne r3, #34 */
/* @0x2867d8 bne 0x2867b8 <spIkConstraintData_dispose+0x60> */
/* @0x2867dc ldr r1, [pc, #0x314] —— 取 __FILE__ 串（…/spine-c/src/spine/Json.c） */
/* @0x2867e0 add r0, r0, #1 */
/* @0x2867e4 mov r2, #141 */
/* @0x2867e8 add r1, pc, r1 */
/* @0x2867ec bl 0x285c10 <_malloc> */
/* @0x2867f0 subs r7, r0, #0 */
/* @0x2867f4 beq 0x286ac4 <spIkConstraintData_dispose+0x36c> */
/* @0x2867f8 ldr r10, [pc, #0x2fc] —— 池字 0x001057ac → 0x3578e0 的 Json.c 路径串 */
/* @0x2867fc add r3, sp, #8 */
/* @0x286800 ldr r12, [pc, #0x2f8] */
/* @0x286804 mov r6, r7 */
/* @0x286808 ldrb r4, [r4, #0x1] */
/* @0x28680c add r10, pc, r10 */
/* @0x286810 add r12, pc, r12 */
/* @0x286814 movw r11, #0x3ff */
/* @0x286818 cmp r4, #0 */
/* @0x28681c cmpne r4, #34 */
/* @0x286820 moveq r2, #0 */
/* @0x286824 movne r2, #1 */
/* @0x286828 beq 0x2868b0 <spIkConstraintData_dispose+0x158> */
/* @0x28682c cmp r4, #92 */
/* @0x286830 beq 0x286848 <spIkConstraintData_dispose+0xf0> */
/* @0x286834 strb r4, [r6] */
/* @0x286838 add r5, r5, #1 */
/* @0x28683c ldrb r4, [r5] */
/* @0x286840 add r6, r6, #1 */
/* @0x286844 b 0x286818 <spIkConstraintData_dispose+0xc0> */
/* @0x286848 ldrb r0, [r5, #0x1] */
/* @0x28684c add r2, r5, #1 */
/* @0x286850 sub r1, r0, #98 */
/* @0x286854 cmp r1, #19 */
/* @0x286858 addls pc, pc, r1, lsl #2 —— 90 项跳转表（addls pc,pc,r1,lsl #2） */
/* @0x28685c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286860 b 0x2869c8 <spIkConstraintData_dispose+0x270> */
/* @0x286864 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286868 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x28686c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286870 b 0x2869b4 <spIkConstraintData_dispose+0x25c> */
/* @0x286874 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286878 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x28687c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286880 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286884 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286888 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x28688c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286890 b 0x2869a0 <spIkConstraintData_dispose+0x248> */
/* @0x286894 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286898 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x28689c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x2868a0 b 0x28698c <spIkConstraintData_dispose+0x234> */
/* @0x2868a4 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x2868a8 b 0x286974 <spIkConstraintData_dispose+0x21c> */
/* @0x2868ac b 0x2868d8 <spIkConstraintData_dispose+0x180> */
/* @0x2868b0 strb r2, [r6] */
/* @0x2868b4 ldrb r3, [r5] */
/* @0x2868b8 str r7, [r9] */
/* @0x2868bc cmp r3, #34 */
/* @0x2868c0 mov r3, #4 */
/* @0x2868c4 addeq r5, r5, #1 */
/* @0x2868c8 str r3, [r8] */
/* @0x2868cc mov r0, r5 */
/* @0x2868d0 add sp, sp, #20 */
/* @0x2868d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2868d8 mov r2, r3 */
/* @0x2868dc mov r1, r10 */
/* @0x2868e0 add r0, r5, #2 */
/* @0x2868e4 str r3, [sp, #0x4] */
/* @0x2868e8 str r12, [sp] */
/* @0x2868ec bl 0xb68f8 <sscanf@plt> */
/* @0x2868f0 ldr r1, [sp, #0x8] */
/* @0x2868f4 add r2, r5, #5 */
/* @0x2868f8 ldr r3, [sp, #0x4] */
/* @0x2868fc sub r0, r1, #56320 */
/* @0x286900 ldr r12, [sp] */
/* @0x286904 cmp r1, #0 */
/* @0x286908 cmpne r0, r11 */
/* @0x28690c bls 0x286a04 <spIkConstraintData_dispose+0x2ac> */
/* @0x286910 sub r0, r1, #55296 */
/* @0x286914 cmp r0, #1024 */
/* @0x286918 bhs 0x286a0c <spIkConstraintData_dispose+0x2b4> */
/* @0x28691c ldrb r1, [r5, #0x6] */
/* @0x286920 cmp r1, #92 */
/* @0x286924 movne r4, r1 */
/* @0x286928 bne 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x28692c ldrb r1, [r5, #0x7] */
/* @0x286930 cmp r1, #117 */
/* @0x286934 bne 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x286938 mov r1, r10 */
/* @0x28693c add r2, sp, #12 */
/* @0x286940 add r0, r5, #8 */
/* @0x286944 str r3, [sp, #0x4] */
/* @0x286948 str r12, [sp] */
/* @0x28694c bl 0xb68f8 <sscanf@plt> */
/* @0x286950 ldr r1, [sp, #0xc] */
/* @0x286954 add r2, r5, #11 */
/* @0x286958 ldr r3, [sp, #0x4] */
/* @0x28695c sub r0, r1, #56320 */
/* @0x286960 ldr r12, [sp] */
/* @0x286964 cmp r0, #1024 */
/* @0x286968 blo 0x286a24 <spIkConstraintData_dispose+0x2cc> */
/* @0x28696c ldrb r4, [r5, #0xc] */
/* @0x286970 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x286974 mov r1, #9 */
/* @0x286978 strb r1, [r6] */
/* @0x28697c ldrb r4, [r5, #0x2] */
/* @0x286980 add r6, r6, #1 */
/* @0x286984 add r5, r2, #1 */
/* @0x286988 b 0x286818 <spIkConstraintData_dispose+0xc0> */
/* @0x28698c mov r1, #13 */
/* @0x286990 add r6, r6, #1 */
/* @0x286994 strb r1, [r6, #-0x1] */
/* @0x286998 ldrb r4, [r5, #0x2] */
/* @0x28699c b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869a0 mov r1, #10 */
/* @0x2869a4 add r6, r6, #1 */
/* @0x2869a8 strb r1, [r6, #-0x1] */
/* @0x2869ac ldrb r4, [r5, #0x2] */
/* @0x2869b0 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869b4 mov r1, #12 */
/* @0x2869b8 add r6, r6, #1 */
/* @0x2869bc strb r1, [r6, #-0x1] */
/* @0x2869c0 ldrb r4, [r5, #0x2] */
/* @0x2869c4 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869c8 mov r1, #8 */
/* @0x2869cc add r6, r6, #1 */
/* @0x2869d0 strb r1, [r6, #-0x1] */
/* @0x2869d4 ldrb r4, [r5, #0x2] */
/* @0x2869d8 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869dc strb r0, [r6] */
/* @0x2869e0 add r6, r6, #1 */
/* @0x2869e4 ldrb r4, [r5, #0x2] */
/* @0x2869e8 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869ec ldr r3, [pc, #0x110] */
/* @0x2869f0 mov r0, #0 */
/* @0x2869f4 add r3, pc, r3 */
/* @0x2869f8 str r2, [r3] */
/* @0x2869fc add sp, sp, #20 */
/* @0x286a00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x286a04 ldrb r4, [r5, #0x6] */
/* @0x286a08 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x286a0c cmp r1, #127 */
/* @0x286a10 bhi 0x286a3c <spIkConstraintData_dispose+0x2e4> */
/* @0x286a14 mov r0, #1 */
/* @0x286a18 add r4, r6, r0 */
/* @0x286a1c mov r5, r0 */
/* @0x286a20 b 0x286a98 <spIkConstraintData_dispose+0x340> */
/* @0x286a24 ldr r0, [sp, #0x8] */
/* @0x286a28 ubfx r1, r1, #0x0, #0xa */
/* @0x286a2c ubfx r0, r0, #0x0, #0xa */
/* @0x286a30 orr r1, r1, r0, lsl #10 */
/* @0x286a34 add r1, r1, #65536 */
/* @0x286a38 str r1, [sp, #0x8] */
/* @0x286a3c cmp r1, #2048 */
/* @0x286a40 blo 0x286ab4 <spIkConstraintData_dispose+0x35c> */
/* @0x286a44 cmp r1, #65536 */
/* @0x286a48 bhs 0x286acc <spIkConstraintData_dispose+0x374> */
/* @0x286a4c mov r0, #3 */
/* @0x286a50 add r4, r6, r0 */
/* @0x286a54 mov r5, r0 */
/* @0x286a58 and r1, r1, #63 */
/* @0x286a5c sub r6, r4, #1 */
/* @0x286a60 mvn r1, r1, lsl #25 */
/* @0x286a64 mvn r1, r1, lsr #25 */
/* @0x286a68 strb r1, [r4, #-0x1] */
/* @0x286a6c ldr r1, [sp, #0x8] */
/* @0x286a70 lsr r1, r1, #6 */
/* @0x286a74 str r1, [sp, #0x8] */
/* @0x286a78 and r1, r1, #63 */
/* @0x286a7c sub r4, r6, #1 */
/* @0x286a80 mvn r1, r1, lsl #25 */
/* @0x286a84 mvn r1, r1, lsr #25 */
/* @0x286a88 strb r1, [r6, #-0x1] */
/* @0x286a8c ldr r1, [sp, #0x8] */
/* @0x286a90 lsr r1, r1, #6 */
/* @0x286a94 str r1, [sp, #0x8] */
/* @0x286a98 ldrb r5, [r12, r5] */
/* @0x286a9c sub r6, r4, #1 */
/* @0x286aa0 add r6, r6, r0 */
/* @0x286aa4 orr r1, r1, r5 */
/* @0x286aa8 strb r1, [r4, #-0x1] */
/* @0x286aac ldrb r4, [r2, #0x1] */
/* @0x286ab0 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x286ab4 mov r0, #2 */
/* @0x286ab8 add r6, r6, r0 */
/* @0x286abc mov r5, r0 */
/* @0x286ac0 b 0x286a78 <spIkConstraintData_dispose+0x320> */
/* @0x286ac4 mov r0, r7 */
/* @0x286ac8 b 0x2868d0 <spIkConstraintData_dispose+0x178> */
/* @0x286acc and r1, r1, #63 */
/* @0x286ad0 mov r0, #4 */
/* @0x286ad4 add r4, r6, #3 */
/* @0x286ad8 mov r5, r0 */
/* @0x286adc mvn r1, r1, lsl #25 */
/* @0x286ae0 mvn r1, r1, lsr #25 */
/* @0x286ae4 strb r1, [r6, #0x3] */
/* @0x286ae8 ldr r1, [sp, #0x8] */
/* @0x286aec lsr r1, r1, #6 */
/* @0x286af0 str r1, [sp, #0x8] */
/* @0x286af4 b 0x286a58 <spIkConstraintData_dispose+0x300> */
/* @0x286af8 ldrdeq r1, r2, [sp], -r0 */
/* @0x286afc andeq r1, sp, r0, ror #1 */
/* @0x286b00 andseq r5, r0, r12, lsr #15 */
/* @0x286b04 subeq r0, sp, r12, asr #3 */
/* @0x286b08 push {r4, r5, r6, r7, r8, r9, lr} —— Json_parse 入口（真正的外部入口：Json_create+0x70 直接调它） */
/* @0x286b0c mov r6, r1 */
/* @0x286b10 ldrb r3, [r1] */
/* @0x286b14 sub sp, sp, #12 */
/* @0x286b18 mov r5, r0 */
/* @0x286b1c sub r3, r3, #34 —— 首字符 - 34（'"'） */
/* @0x286b20 cmp r3, #89 */
/* @0x286b24 addls pc, pc, r3, lsl #2 —— 90 项分派表，覆盖 '"'..'{' 的 90 个字符 */
/* @0x286b28 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b2c b 0x286f58 <spIkConstraintData_dispose+0x800> */
/* @0x286b30 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b34 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b38 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b3c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b40 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b44 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b48 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b4c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b50 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b54 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b58 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b5c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b60 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b64 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b68 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b6c b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b70 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b74 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b78 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b7c b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b80 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b84 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b88 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b8c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b90 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b94 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b98 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b9c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286ba0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286ba4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286ba8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bac b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bb0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bb4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bb8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bbc b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bc0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bc4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bc8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bcc b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bd0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bd4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bd8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bdc b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286be0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286be4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286be8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bec b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bf0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bf4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bf8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bfc b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c00 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c04 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c08 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c0c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c10 b 0x286fb0 <spIkConstraintData_dispose+0x858> */
/* @0x286c14 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c18 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c1c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c20 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c24 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c28 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c2c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c30 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c34 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c38 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c3c b 0x287154 <spIkConstraintData_dispose+0x9fc> */
/* @0x286c40 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c44 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c48 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c4c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c50 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c54 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c58 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c5c b 0x287180 <spIkConstraintData_dispose+0xa28> */
/* @0x286c60 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c64 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c68 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c6c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c70 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c74 b 0x2871b0 <spIkConstraintData_dispose+0xa58> */
/* @0x286c78 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c7c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c80 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c84 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c88 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c8c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c90 b 0x286c94 <spIkConstraintData_dispose+0x53c> */
/* @0x286c94 adds r4, r1, #1 */
/* @0x286c98 mov r3, #6 */
/* @0x286c9c str r3, [r0, #0x8] */
/* @0x286ca0 ldrb r3, [r1, #0x1] */
/* @0x286ca4 beq 0x286cd0 <spIkConstraintData_dispose+0x578> */
/* @0x286ca8 sub r2, r3, #1 */
/* @0x286cac cmp r2, #31 */
/* @0x286cb0 bhi 0x286cd0 <spIkConstraintData_dispose+0x578> */
/* @0x286cb4 add r6, r1, #2 */
/* @0x286cb8 mov r4, r6 */
/* @0x286cbc add r6, r6, #1 */
/* @0x286cc0 ldrb r3, [r4] */
/* @0x286cc4 sub r2, r3, #1 */
/* @0x286cc8 cmp r2, #31 */
/* @0x286ccc bls 0x286cb8 <spIkConstraintData_dispose+0x560> */
/* @0x286cd0 cmp r3, #125 */
/* @0x286cd4 beq 0x287208 <spIkConstraintData_dispose+0xab0> */
/* @0x286cd8 ldr r2, [pc, #0x5a4] */
/* @0x286cdc mov r0, #1 */
/* @0x286ce0 mov r1, #32 */
/* @0x286ce4 mov r3, #77 */
/* @0x286ce8 add r2, pc, r2 */
/* @0x286cec bl 0x285c4c <_calloc> */
/* @0x286cf0 cmp r0, #0 */
/* @0x286cf4 mov r9, r0 */
/* @0x286cf8 str r0, [r5, #0x4] */
/* @0x286cfc beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286d00 ldrb r3, [r4] */
/* @0x286d04 sub r3, r3, #1 */
/* @0x286d08 cmp r3, #31 */
/* @0x286d0c bhi 0x286d2c <spIkConstraintData_dispose+0x5d4> */
/* @0x286d10 add r3, r4, #1 */
/* @0x286d14 mov r4, r3 */
/* @0x286d18 add r3, r3, #1 */
/* @0x286d1c ldrb r2, [r4] */
/* @0x286d20 sub r2, r2, #1 */
/* @0x286d24 cmp r2, #31 */
/* @0x286d28 bls 0x286d14 <spIkConstraintData_dispose+0x5bc> */
/* @0x286d2c mov r2, r4 */
/* @0x286d30 add r0, r9, #8 */
/* @0x286d34 add r1, r9, #16 */
/* @0x286d38 bl 0x28677c <spIkConstraintData_dispose+0x24> */
/* @0x286d3c subs r2, r0, #0 */
/* @0x286d40 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286d44 ldrb r3, [r2] */
/* @0x286d48 sub r3, r3, #1 */
/* @0x286d4c cmp r3, #31 */
/* @0x286d50 bhi 0x286d70 <spIkConstraintData_dispose+0x618> */
/* @0x286d54 add r3, r2, #1 */
/* @0x286d58 mov r2, r3 */
/* @0x286d5c add r3, r3, #1 */
/* @0x286d60 ldrb r1, [r2] */
/* @0x286d64 sub r1, r1, #1 */
/* @0x286d68 cmp r1, #31 */
/* @0x286d6c bls 0x286d58 <spIkConstraintData_dispose+0x600> */
/* @0x286d70 ldr r3, [r9, #0x10] */
/* @0x286d74 mov r0, #0 */
/* @0x286d78 str r0, [r9, #0x10] */
/* @0x286d7c str r3, [r9, #0x1c] */
/* @0x286d80 ldrb r3, [r2] */
/* @0x286d84 cmp r3, #58 */
/* @0x286d88 bne 0x287230 <spIkConstraintData_dispose+0xad8> */
/* @0x286d8c adds r1, r2, #1 */
/* @0x286d90 beq 0x286dc0 <spIkConstraintData_dispose+0x668> */
/* @0x286d94 ldrb r3, [r2, #0x1] */
/* @0x286d98 sub r3, r3, #1 */
/* @0x286d9c cmp r3, #31 */
/* @0x286da0 bhi 0x286dc0 <spIkConstraintData_dispose+0x668> */
/* @0x286da4 add r2, r2, #2 */
/* @0x286da8 mov r1, r2 */
/* @0x286dac add r2, r2, #1 */
/* @0x286db0 ldrb r3, [r1] */
/* @0x286db4 sub r3, r3, #1 */
/* @0x286db8 cmp r3, #31 */
/* @0x286dbc bls 0x286da8 <spIkConstraintData_dispose+0x650> */
/* @0x286dc0 mov r0, r9 */
/* @0x286dc4 bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x286dc8 subs r4, r0, #0 */
/* @0x286dcc beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286dd0 ldrb r3, [r4] */
/* @0x286dd4 sub r3, r3, #1 */
/* @0x286dd8 cmp r3, #31 */
/* @0x286ddc bhi 0x286dfc <spIkConstraintData_dispose+0x6a4> */
/* @0x286de0 add r3, r4, #1 */
/* @0x286de4 mov r4, r3 */
/* @0x286de8 add r3, r3, #1 */
/* @0x286dec ldrb r2, [r4] */
/* @0x286df0 sub r2, r2, #1 */
/* @0x286df4 cmp r2, #31 */
/* @0x286df8 bls 0x286de4 <spIkConstraintData_dispose+0x68c> */
/* @0x286dfc mov r3, #1 */
/* @0x286e00 str r3, [r5, #0xc] */
/* @0x286e04 ldrb r3, [r4] */
/* @0x286e08 mov r7, #0 */
/* @0x286e0c ldr r6, [pc, #0x474] */
/* @0x286e10 cmp r3, #44 */
/* @0x286e14 add r6, pc, r6 */
/* @0x286e18 bne 0x287240 <spIkConstraintData_dispose+0xae8> */
/* @0x286e1c mov r0, #1 */
/* @0x286e20 mov r1, #32 */
/* @0x286e24 mov r2, r6 */
/* @0x286e28 mov r3, #77 */
/* @0x286e2c bl 0x285c4c <_calloc> */
/* @0x286e30 subs r8, r0, #0 */
/* @0x286e34 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286e38 adds r2, r4, #1 */
/* @0x286e3c str r8, [r9] */
/* @0x286e40 beq 0x286e70 <spIkConstraintData_dispose+0x718> */
/* @0x286e44 ldrb r3, [r4, #0x1] */
/* @0x286e48 sub r3, r3, #1 */
/* @0x286e4c cmp r3, #31 */
/* @0x286e50 bhi 0x286e70 <spIkConstraintData_dispose+0x718> */
/* @0x286e54 add r4, r4, #2 */
/* @0x286e58 mov r2, r4 */
/* @0x286e5c add r4, r4, #1 */
/* @0x286e60 ldrb r3, [r2] */
/* @0x286e64 sub r3, r3, #1 */
/* @0x286e68 cmp r3, #31 */
/* @0x286e6c bls 0x286e58 <spIkConstraintData_dispose+0x700> */
/* @0x286e70 add r0, r8, #8 */
/* @0x286e74 add r1, r8, #16 */
/* @0x286e78 bl 0x28677c <spIkConstraintData_dispose+0x24> */
/* @0x286e7c subs r12, r0, #0 */
/* @0x286e80 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286e84 ldrb r3, [r12] */
/* @0x286e88 sub r3, r3, #1 */
/* @0x286e8c cmp r3, #31 */
/* @0x286e90 bhi 0x286eb0 <spIkConstraintData_dispose+0x758> */
/* @0x286e94 add r3, r12, #1 */
/* @0x286e98 mov r12, r3 */
/* @0x286e9c add r3, r3, #1 */
/* @0x286ea0 ldrb r2, [r12] */
/* @0x286ea4 sub r2, r2, #1 */
/* @0x286ea8 cmp r2, #31 */
/* @0x286eac bls 0x286e98 <spIkConstraintData_dispose+0x740> */
/* @0x286eb0 ldr r3, [r8, #0x10] */
/* @0x286eb4 str r7, [r8, #0x10] */
/* @0x286eb8 str r3, [r8, #0x1c] */
/* @0x286ebc ldrb r3, [r12] */
/* @0x286ec0 cmp r3, #58 */
/* @0x286ec4 bne 0x28725c <spIkConstraintData_dispose+0xb04> */
/* @0x286ec8 adds r1, r12, #1 */
/* @0x286ecc beq 0x286efc <spIkConstraintData_dispose+0x7a4> */
/* @0x286ed0 ldrb r3, [r12, #0x1] */
/* @0x286ed4 sub r3, r3, #1 */
/* @0x286ed8 cmp r3, #31 */
/* @0x286edc bhi 0x286efc <spIkConstraintData_dispose+0x7a4> */
/* @0x286ee0 add r12, r12, #2 */
/* @0x286ee4 mov r1, r12 */
/* @0x286ee8 add r12, r12, #1 */
/* @0x286eec ldrb r3, [r1] */
/* @0x286ef0 sub r3, r3, #1 */
/* @0x286ef4 cmp r3, #31 */
/* @0x286ef8 bls 0x286ee4 <spIkConstraintData_dispose+0x78c> */
/* @0x286efc mov r0, r8 */
/* @0x286f00 bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x286f04 subs r4, r0, #0 */
/* @0x286f08 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286f0c ldrb r3, [r4] */
/* @0x286f10 sub r3, r3, #1 */
/* @0x286f14 cmp r3, #31 */
/* @0x286f18 bhi 0x286f38 <spIkConstraintData_dispose+0x7e0> */
/* @0x286f1c add r3, r4, #1 */
/* @0x286f20 mov r4, r3 */
/* @0x286f24 add r3, r3, #1 */
/* @0x286f28 ldrb r2, [r4] */
/* @0x286f2c sub r2, r2, #1 */
/* @0x286f30 cmp r2, #31 */
/* @0x286f34 bls 0x286f20 <spIkConstraintData_dispose+0x7c8> */
/* @0x286f38 ldr r3, [r5, #0xc] */
/* @0x286f3c add r3, r3, #1 */
/* @0x286f40 str r3, [r5, #0xc] */
/* @0x286f44 ldrb r3, [r4] */
/* @0x286f48 cmp r3, #44 */
/* @0x286f4c bne 0x287240 <spIkConstraintData_dispose+0xae8> */
/* @0x286f50 mov r9, r8 */
/* @0x286f54 b 0x286e1c <spIkConstraintData_dispose+0x6c4> */
/* @0x286f58 mov r2, r1 */
/* @0x286f5c add r0, r0, #8 */
/* @0x286f60 add r1, r5, #16 */
/* @0x286f64 bl 0x28677c <spIkConstraintData_dispose+0x24> */
/* @0x286f68 add sp, sp, #12 */
/* @0x286f6c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x286f70 mov r0, r1 */
/* @0x286f74 add r1, sp, #4 */
/* @0x286f78 bl 0xb6658 <strtod@plt> */
/* @0x286f7c ldr r4, [sp, #0x4] */
/* @0x286f80 cmp r6, r4 */
/* @0x286f84 vmov d6, r0, r1 */
/* @0x286f88 vcvt.f32.f64 s15, d6 */
/* @0x286f8c beq 0x287270 <spIkConstraintData_dispose+0xb18> */
/* @0x286f90 vstr s15, [r5, #24] */
/* @0x286f94 mov r0, r4 */
/* @0x286f98 mov r3, #3 */
/* @0x286f9c str r3, [r5, #0x8] */
/* @0x286fa0 vcvt.s32.f32 s15, s15 */
/* @0x286fa4 vstr s15, [r5, #20] */
/* @0x286fa8 add sp, sp, #12 */
/* @0x286fac pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x286fb0 adds r4, r1, #1 */
/* @0x286fb4 mov r3, #5 */
/* @0x286fb8 str r3, [r0, #0x8] */
/* @0x286fbc ldrb r3, [r1, #0x1] */
/* @0x286fc0 beq 0x286fec <spIkConstraintData_dispose+0x894> */
/* @0x286fc4 sub r2, r3, #1 */
/* @0x286fc8 cmp r2, #31 */
/* @0x286fcc bhi 0x286fec <spIkConstraintData_dispose+0x894> */
/* @0x286fd0 add r6, r1, #2 */
/* @0x286fd4 mov r4, r6 */
/* @0x286fd8 add r6, r6, #1 */
/* @0x286fdc ldrb r3, [r4] */
/* @0x286fe0 sub r2, r3, #1 */
/* @0x286fe4 cmp r2, #31 */
/* @0x286fe8 bls 0x286fd4 <spIkConstraintData_dispose+0x87c> */
/* @0x286fec cmp r3, #93 */
/* @0x286ff0 beq 0x287208 <spIkConstraintData_dispose+0xab0> */
/* @0x286ff4 ldr r2, [pc, #0x290] */
/* @0x286ff8 mov r0, #1 */
/* @0x286ffc mov r1, #32 */
/* @0x287000 mov r3, #77 */
/* @0x287004 add r2, pc, r2 */
/* @0x287008 bl 0x285c4c <_calloc> */
/* @0x28700c cmp r0, #0 */
/* @0x287010 mov r8, r0 */
/* @0x287014 str r0, [r5, #0x4] */
/* @0x287018 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x28701c ldrb r3, [r4] */
/* @0x287020 sub r3, r3, #1 */
/* @0x287024 cmp r3, #31 */
/* @0x287028 bhi 0x287048 <spIkConstraintData_dispose+0x8f0> */
/* @0x28702c add r3, r4, #1 */
/* @0x287030 mov r4, r3 */
/* @0x287034 add r3, r3, #1 */
/* @0x287038 ldrb r2, [r4] */
/* @0x28703c sub r2, r2, #1 */
/* @0x287040 cmp r2, #31 */
/* @0x287044 bls 0x287030 <spIkConstraintData_dispose+0x8d8> */
/* @0x287048 mov r1, r4 */
/* @0x28704c mov r0, r8 */
/* @0x287050 bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x287054 subs r4, r0, #0 */
/* @0x287058 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x28705c ldrb r3, [r4] */
/* @0x287060 sub r3, r3, #1 */
/* @0x287064 cmp r3, #31 */
/* @0x287068 bhi 0x287088 <spIkConstraintData_dispose+0x930> */
/* @0x28706c add r3, r4, #1 */
/* @0x287070 mov r4, r3 */
/* @0x287074 add r3, r3, #1 */
/* @0x287078 ldrb r2, [r4] */
/* @0x28707c sub r2, r2, #1 */
/* @0x287080 cmp r2, #31 */
/* @0x287084 bls 0x287070 <spIkConstraintData_dispose+0x918> */
/* @0x287088 mov r3, #1 */
/* @0x28708c str r3, [r5, #0xc] */
/* @0x287090 ldrb r3, [r4] */
/* @0x287094 ldr r6, [pc, #0x1f4] */
/* @0x287098 cmp r3, #44 */
/* @0x28709c add r6, pc, r6 */
/* @0x2870a0 bne 0x287214 <spIkConstraintData_dispose+0xabc> */
/* @0x2870a4 mov r0, #1 */
/* @0x2870a8 mov r1, #32 */
/* @0x2870ac mov r2, r6 */
/* @0x2870b0 mov r3, #77 */
/* @0x2870b4 bl 0x285c4c <_calloc> */
/* @0x2870b8 subs r7, r0, #0 */
/* @0x2870bc beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x2870c0 adds r1, r4, #1 */
/* @0x2870c4 str r7, [r8] */
/* @0x2870c8 beq 0x2870f8 <spIkConstraintData_dispose+0x9a0> */
/* @0x2870cc ldrb r3, [r4, #0x1] */
/* @0x2870d0 sub r3, r3, #1 */
/* @0x2870d4 cmp r3, #31 */
/* @0x2870d8 bhi 0x2870f8 <spIkConstraintData_dispose+0x9a0> */
/* @0x2870dc add r4, r4, #2 */
/* @0x2870e0 mov r1, r4 */
/* @0x2870e4 add r4, r4, #1 */
/* @0x2870e8 ldrb r3, [r1] */
/* @0x2870ec sub r3, r3, #1 */
/* @0x2870f0 cmp r3, #31 */
/* @0x2870f4 bls 0x2870e0 <spIkConstraintData_dispose+0x988> */
/* @0x2870f8 mov r0, r7 */
/* @0x2870fc bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x287100 subs r4, r0, #0 */
/* @0x287104 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x287108 ldrb r3, [r4] */
/* @0x28710c sub r3, r3, #1 */
/* @0x287110 cmp r3, #31 */
/* @0x287114 bhi 0x287134 <spIkConstraintData_dispose+0x9dc> */
/* @0x287118 add r3, r4, #1 */
/* @0x28711c mov r4, r3 */
/* @0x287120 add r3, r3, #1 */
/* @0x287124 ldrb r1, [r4] */
/* @0x287128 sub r1, r1, #1 */
/* @0x28712c cmp r1, #31 */
/* @0x287130 bls 0x28711c <spIkConstraintData_dispose+0x9c4> */
/* @0x287134 ldr r3, [r5, #0xc] */
/* @0x287138 add r3, r3, #1 */
/* @0x28713c str r3, [r5, #0xc] */
/* @0x287140 ldrb r3, [r4] */
/* @0x287144 cmp r3, #44 */
/* @0x287148 bne 0x287214 <spIkConstraintData_dispose+0xabc> */
/* @0x28714c mov r8, r7 */
/* @0x287150 b 0x2870a4 <spIkConstraintData_dispose+0x94c> */
/* @0x287154 add r0, r1, #1 */
/* @0x287158 ldr r1, [pc, #0x134] */
/* @0x28715c mov r2, #4 */
/* @0x287160 add r1, pc, r1 */
/* @0x287164 bl 0xb65e0 <strncmp@plt> */
/* @0x287168 cmp r0, #0 */
/* @0x28716c bne 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x287170 str r0, [r5, #0x8] */
/* @0x287174 add r0, r6, #5 */
/* @0x287178 add sp, sp, #12 */
/* @0x28717c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x287180 add r0, r1, #1 */
/* @0x287184 ldr r1, [pc, #0x10c] */
/* @0x287188 mov r2, #3 */
/* @0x28718c add r1, pc, r1 */
/* @0x287190 bl 0xb65e0 <strncmp@plt> */
/* @0x287194 cmp r0, #0 */
/* @0x287198 bne 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x28719c add r0, r6, #4 */
/* @0x2871a0 mov r3, #2 */
/* @0x2871a4 str r3, [r5, #0x8] */
/* @0x2871a8 add sp, sp, #12 */
/* @0x2871ac pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2871b0 add r0, r1, #1 */
/* @0x2871b4 ldr r1, [pc, #0xe0] */
/* @0x2871b8 mov r2, #3 */
/* @0x2871bc add r1, pc, r1 */
/* @0x2871c0 bl 0xb65e0 <strncmp@plt> */
/* @0x2871c4 cmp r0, #0 */
/* @0x2871c8 bne 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x2871cc mov r3, #1 */
/* @0x2871d0 add r0, r6, #4 */
/* @0x2871d4 str r3, [r5, #0x8] */
/* @0x2871d8 str r3, [r5, #0x14] */
/* @0x2871dc add sp, sp, #12 */
/* @0x2871e0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2871e4 ldr r3, [pc, #0xb4] */
/* @0x2871e8 mov r0, #0 */
/* @0x2871ec add r3, pc, r3 */
/* @0x2871f0 str r6, [r3] */
/* @0x2871f4 add sp, sp, #12 */
/* @0x2871f8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2871fc mov r0, #0 */
/* @0x287200 add sp, sp, #12 */
/* @0x287204 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x287208 add r0, r4, #1 */
/* @0x28720c add sp, sp, #12 */
/* @0x287210 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x287214 cmp r3, #93 */
/* @0x287218 beq 0x287208 <spIkConstraintData_dispose+0xab0> */
/* @0x28721c ldr r3, [pc, #0x80] */
/* @0x287220 mov r0, #0 */
/* @0x287224 add r3, pc, r3 */
/* @0x287228 str r4, [r3] */
/* @0x28722c b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x287230 ldr r3, [pc, #0x70] */
/* @0x287234 add r3, pc, r3 */
/* @0x287238 str r2, [r3] */
/* @0x28723c b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x287240 cmp r3, #125 */
/* @0x287244 beq 0x287208 <spIkConstraintData_dispose+0xab0> */
/* @0x287248 ldr r3, [pc, #0x5c] */
/* @0x28724c mov r0, #0 */
/* @0x287250 add r3, pc, r3 */
/* @0x287254 str r4, [r3] */
/* @0x287258 b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x28725c ldr r3, [pc, #0x4c] */
/* @0x287260 mov r0, #0 */
/* @0x287264 add r3, pc, r3 */
/* @0x287268 str r12, [r3] */
/* @0x28726c b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x287270 ldr r3, [pc, #0x3c] */
/* @0x287274 mov r0, #0 */
/* @0x287278 add r3, pc, r3 */
/* @0x28727c str r6, [r3] */
/* @0x287280 b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x287284 ldrdeq r0, r1, [sp], -r0 */
/* @0x287288 andeq r0, sp, r4, lsr #21 */
/* @0x28728c strheq r0, [sp], -r4 */
/* @0x287290 andeq r0, sp, r12, lsl r8 */
/* @0x287294 muleq sp, r4, r7 */
/* @0x287298 andeq r0, sp, r4, ror #14 */
/* @0x28729c andeq r0, sp, r0, asr #14 */
/* @0x2872a0 .word 0x004cf9d4 —— 池字 0x004cf9d4（非指令） */
/* @0x2872a4 umaaleq pc, r12, r12, r9 */
/* @0x2872a8 subeq pc, r12, r12, lsl #19 */
/* @0x2872ac subeq pc, r12, r0, ror r9 */
/* @0x2872b0 subeq pc, r12, r12, asr r9 */


/* ═══════════════════════════════════════════════════════════════════════
 * §3  anon_2670bc  0x2670bc..0x2679bc  2,304 B / 576 条  in-degree 4
 * libpcre 8.x —— pcre_compile.c 区内的静态 opcode 遍历器（111 项 case 表 + 一次 _pcre_xclass）
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 = 码流指针（0x2670ec 的 ldrb r5,[r4] 取 opcode）；r1 → r8；r2 → r7（0x267134 读
 *       [r7+0x4]，是编译数据指针）；r3 → r6（输出槽，0x267148 读 [r6]）。
 *
 * 身份证据（三条）
 *   ① 调用面：pcre_compile2（0x2679c0，5,576 B，具名）两处直接 bl —— 0x268c4c（+0x128c）与
 *      0x268e1c（+0x145c）；段内 2 处自递归（0x267284 / 0x2677f0）。另有 1 处 bl 到
 *      _pcre_xclass（0x266cac，1,040 B，具名）与 1 处 bl 到 0x25db38（0x25b524 簇内）。
 *   ② opcode 头长：0x2670f0 的 cmp r5,#118 + 0x2670f4 的 addeq r4,r4,#6 —— 与
 *      _pcre_OP_lengths[118] = 6 逐字对上（本卡读 0x38ba04 复核）；随后按 118 / 119 / 129 /
 *      131 / 120 / 123 逐码分流，129 以上走 0x2672ec，131 以上走 0x2671f0。
 *   ③ 111 项 case 表：0x267354 的 addls pc,pc,r2,lsl #2（索引 = opcode - 29，表体 0x267358 起）。
 *      0x2670e0 的 movw r10,#0x180e 是入口常驻的掩码/常量（见 open 2）。
 *
 * 出口：3 个 pop {r4..r11,pc}（0x267230 / 0x2672b4 / 0x267328）；窗口内 0 条分支跳出。
 * 边界：0x2679b4 / 0x2679b8 是池字/误译（andseq），非本函数指令。
 * open：1. pcre_compile.c 中对应函数名未定（形态是"按 opcode 走一遍编译后码流"的例程；
 *          该 TU 里符合条件的静态函数不止一个，本卡不钉）。
 *       2. 0x180e 的语义未定（可能是 opcode 位掩码或 recsize 组合）。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x2670bc 0x2679bc anon_2670bc pcre_compile_opcode_walker */

/* @0x2670bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言（9 寄存器 + 52 B 帧） */
/* @0x2670c0 sub sp, sp, #52 */
/* @0x2670c4 mov r4, r0 */
/* @0x2670c8 add r9, sp, #16 */
/* @0x2670cc ldr r0, [pc, #0x8e0] */
/* @0x2670d0 mov r8, r1 */
/* @0x2670d4 mov r7, r2 */
/* @0x2670d8 mov r6, r3 */
/* @0x2670dc mov r11, #0 */
/* @0x2670e0 movw r10, #0x180e —— 入口常驻常量 0x180e（语义见 open 2） */
/* @0x2670e4 add r0, pc, r0 */
/* @0x2670e8 str r0, [sp, #0xc] */
/* @0x2670ec ldrb r5, [r4] —— 读当前 opcode */
/* @0x2670f0 cmp r5, #118 —— cmp #118 = OP_lengths[118] */
/* @0x2670f4 addeq r4, r4, #6 —— opcode 118 的头长 6 —— 与 _pcre_OP_lengths[118]=6 一致 */
/* @0x2670f8 beq 0x2670ec <_pcre_xclass+0x440> */
/* @0x2670fc cmp r5, #119 */
/* @0x267100 beq 0x2671d4 <_pcre_xclass+0x528> */
/* @0x267104 cmp r5, #131 */
/* @0x267108 bhi 0x2671f0 <_pcre_xclass+0x544> */
/* @0x26710c cmp r5, #129 */
/* @0x267110 bhs 0x2672ec <_pcre_xclass+0x640> */
/* @0x267114 cmp r5, #120 */
/* @0x267118 beq 0x2672b8 <_pcre_xclass+0x60c> */
/* @0x26711c cmp r5, #123 */
/* @0x267120 beq 0x2672a4 <_pcre_xclass+0x5f8> */
/* @0x267124 cmp r5, #0 */
/* @0x267128 beq 0x2672a4 <_pcre_xclass+0x5f8> */
/* @0x26712c mov r0, r4 */
/* @0x267130 mov r1, r8 */
/* @0x267134 ldr r2, [r7, #0x4] */
/* @0x267138 mov r3, r9 */
/* @0x26713c bl 0x25db38 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a10> —— bl 0x25db38（0x25b524 簇内的子例程） */
/* @0x267140 subs r4, r0, #0 */
/* @0x267144 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x267148 ldr r2, [r6] */
/* @0x26714c cmp r2, #29 */
/* @0x267150 beq 0x26732c <_pcre_xclass+0x680> */
/* @0x267154 ldr r1, [sp, #0x10] */
/* @0x267158 cmp r1, #29 */
/* @0x26715c beq 0x2677a4 <_pcre_xclass+0xaf8> */
/* @0x267160 cmp r2, #110 */
/* @0x267164 beq 0x267830 <_pcre_xclass+0xb84> */
/* @0x267168 cmp r1, #110 */
/* @0x26716c beq 0x267720 <_pcre_xclass+0xa74> */
/* @0x267170 cmp r8, #0 */
/* @0x267174 bne 0x267188 <_pcre_xclass+0x4dc> */
/* @0x267178 cmp r2, #111 */
/* @0x26717c beq 0x267830 <_pcre_xclass+0xb84> */
/* @0x267180 cmp r1, #111 */
/* @0x267184 beq 0x267728 <_pcre_xclass+0xa7c> */
/* @0x267188 sub r2, r2, #6 */
/* @0x26718c cmp r2, #16 */
/* @0x267190 bhi 0x267228 <_pcre_xclass+0x57c> */
/* @0x267194 sub r1, r1, #6 */
/* @0x267198 cmp r1, #20 */
/* @0x26719c bhi 0x267228 <_pcre_xclass+0x57c> */
/* @0x2671a0 add r2, r2, r2, lsl #1 */
/* @0x2671a4 ldr r0, [sp, #0xc] */
/* @0x2671a8 rsb r2, r2, r2, lsl #3 */
/* @0x2671ac add r3, r0, r2 */
/* @0x2671b0 add r1, r3, r1 */
/* @0x2671b4 ldrb r3, [r1, #0x3d8] */
/* @0x2671b8 cmp r3, #0 */
/* @0x2671bc beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x2671c0 ldr r3, [sp, #0x14] */
/* @0x2671c4 cmp r3, #0 */
/* @0x2671c8 bne 0x2670ec <_pcre_xclass+0x440> */
/* @0x2671cc mov r0, #1 */
/* @0x2671d0 b 0x2672b0 <_pcre_xclass+0x604> */
/* @0x2671d4 ldrb r2, [r4, #0x1] */
/* @0x2671d8 ldrb r3, [r4, #0x2] */
/* @0x2671dc orr r3, r3, r2, lsl #8 */
/* @0x2671e0 ldrb r5, [r4, r3]! */
/* @0x2671e4 cmp r5, #119 */
/* @0x2671e8 beq 0x2671d4 <_pcre_xclass+0x528> */
/* @0x2671ec b 0x267104 <_pcre_xclass+0x458> */
/* @0x2671f0 cmp r5, #133 */
/* @0x2671f4 beq 0x2672ec <_pcre_xclass+0x640> */
/* @0x2671f8 blo 0x26712c <_pcre_xclass+0x480> */
/* @0x2671fc sub r3, r5, #146 */
/* @0x267200 cmp r3, #1 */
/* @0x267204 bhi 0x26712c <_pcre_xclass+0x480> */
/* @0x267208 ldrb r3, [r4, #0x1] */
/* @0x26720c add r0, r4, #1 */
/* @0x267210 cmp r3, #133 */
/* @0x267214 beq 0x267234 <_pcre_xclass+0x588> */
/* @0x267218 add r3, r3, #127 */
/* @0x26721c uxtb r3, r3 */
/* @0x267220 cmp r3, #2 */
/* @0x267224 bls 0x267234 <_pcre_xclass+0x588> */
/* @0x267228 mov r0, #0 */
/* @0x26722c add sp, sp, #52 */
/* @0x267230 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1 */
/* @0x267234 ldrb r2, [r0, #0x1] */
/* @0x267238 ldrb r3, [r0, #0x2] */
/* @0x26723c orr r3, r3, r2, lsl #8 */
/* @0x267240 ldrb r3, [r0, r3]! */
/* @0x267244 cmp r3, #119 */
/* @0x267248 beq 0x267234 <_pcre_xclass+0x588> */
/* @0x26724c ldr r2, [sp, #0x5c] */
/* @0x267250 ldr r3, [r2] */
/* @0x267254 cmp r3, #0 */
/* @0x267258 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x26725c ldr r2, [sp, #0x58] */
/* @0x267260 sub r3, r3, #1 */
/* @0x267264 add r0, r0, #3 */
/* @0x267268 mov r1, r8 */
/* @0x26726c str r2, [sp] */
/* @0x267270 ldr r2, [sp, #0x5c] */
/* @0x267274 str r3, [r2] */
/* @0x267278 mov r3, r6 */
/* @0x26727c str r2, [sp, #0x4] */
/* @0x267280 mov r2, r7 */
/* @0x267284 bl 0x2670bc <_pcre_xclass+0x410> */
/* @0x267288 cmp r0, #0 */
/* @0x26728c beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x267290 ldr r3, [pc, #0x720] */
/* @0x267294 ldr r3, [pc, r3] */
/* @0x267298 ldrb r3, [r3, r5] */
/* @0x26729c add r4, r4, r3 */
/* @0x2672a0 b 0x2670ec <_pcre_xclass+0x440> */
/* @0x2672a4 ldr r0, [r6, #0x4] */
/* @0x2672a8 adds r0, r0, #0 */
/* @0x2672ac movne r0, #1 */
/* @0x2672b0 add sp, sp, #52 */
/* @0x2672b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2 */
/* @0x2672b8 ldr r3, [r6, #0x4] */
/* @0x2672bc cmp r3, #0 */
/* @0x2672c0 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x2672c4 ldrb r2, [r4, #0x1] */
/* @0x2672c8 ldrb r3, [r4, #0x2] */
/* @0x2672cc orr r3, r3, r2, lsl #8 */
/* @0x2672d0 rsb r3, r3, r4 */
/* @0x2672d4 ldrb r3, [r3] */
/* @0x2672d8 sub r3, r3, #125 */
/* @0x2672dc cmp r3, #5 */
/* @0x2672e0 bls 0x267320 <_pcre_xclass+0x674> */
/* @0x2672e4 add r4, r4, #3 */
/* @0x2672e8 b 0x2670ec <_pcre_xclass+0x440> */
/* @0x2672ec ldrb r11, [r4, #0x1] */
/* @0x2672f0 ldrb r2, [r4, #0x2] */
/* @0x2672f4 ldr r3, [pc, #0x6c0] */
/* @0x2672f8 orr r11, r2, r11, lsl #8 */
/* @0x2672fc add r11, r4, r11 */
/* @0x267300 ldr r3, [pc, r3] */
/* @0x267304 ldrb r2, [r11] */
/* @0x267308 ldrb r3, [r3, r5] */
/* @0x26730c cmp r2, #119 */
/* @0x267310 add r4, r4, r3 */
/* @0x267314 beq 0x2677b0 <_pcre_xclass+0xb04> */
/* @0x267318 mov r11, #1 */
/* @0x26731c b 0x2670ec <_pcre_xclass+0x440> */
/* @0x267320 eor r0, r11, #1 */
/* @0x267324 add sp, sp, #52 */
/* @0x267328 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 3 */
/* @0x26732c ldr r2, [sp, #0x10] */
/* @0x267330 add r5, r6, #8 */
/* @0x267334 mov r3, r9 */
/* @0x267338 ldr r0, [r5] */
/* @0x26733c mov r1, r6 */
/* @0x267340 mov r6, r4 */
/* @0x267344 mov r4, r3 */
/* @0x267348 mov r3, r1 */
/* @0x26734c sub r2, r2, #6 */
/* @0x267350 cmp r2, #106 */
/* @0x267354 addls pc, pc, r2, lsl #2 —— 111 项 case 表（索引 = opcode - 29） */
/* @0x267358 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26735c b 0x2676d0 <_pcre_xclass+0xa24> */
/* @0x267360 b 0x2676b4 <_pcre_xclass+0xa08> */
/* @0x267364 b 0x267698 <_pcre_xclass+0x9ec> */
/* @0x267368 b 0x26767c <_pcre_xclass+0x9d0> */
/* @0x26736c b 0x267660 <_pcre_xclass+0x9b4> */
/* @0x267370 b 0x267644 <_pcre_xclass+0x998> */
/* @0x267374 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267378 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26737c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267380 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267384 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267388 b 0x267508 <_pcre_xclass+0x85c> */
/* @0x26738c b 0x26756c <_pcre_xclass+0x8c0> */
/* @0x267390 b 0x267540 <_pcre_xclass+0x894> */
/* @0x267394 b 0x2675a0 <_pcre_xclass+0x8f4> */
/* @0x267398 b 0x267508 <_pcre_xclass+0x85c> */
/* @0x26739c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673a0 b 0x267508 <_pcre_xclass+0x85c> */
/* @0x2673a4 b 0x267520 <_pcre_xclass+0x874> */
/* @0x2673a8 b 0x267508 <_pcre_xclass+0x85c> */
/* @0x2673ac b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673b0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673b4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673b8 b 0x2675ec <_pcre_xclass+0x940> */
/* @0x2673bc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673c0 b 0x2675c0 <_pcre_xclass+0x914> */
/* @0x2673c4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673c8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673cc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673d0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673d4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673d8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673dc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673e0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673e4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673e8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673ec b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673f0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673f4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673f8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2673fc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267400 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267404 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267408 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26740c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267410 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267414 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267418 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26741c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267420 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267424 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267428 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26742c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267430 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267434 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267438 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26743c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267440 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267444 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267448 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26744c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267450 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267454 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267458 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26745c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267460 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267464 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267468 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26746c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267470 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267474 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267478 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26747c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267480 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267484 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267488 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26748c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267490 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267494 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267498 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26749c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674a0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674a4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674a8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674ac b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674b0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674b4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674b8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674bc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674c0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674c4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674c8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674cc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674d0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674d4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674d8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674dc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674e0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674e4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674e8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674ec b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674f0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674f4 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674f8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2674fc b 0x267534 <_pcre_xclass+0x888> */
/* @0x267500 b 0x2676ec <_pcre_xclass+0xa40> */
/* @0x267504 b 0x267610 <_pcre_xclass+0x964> */
/* @0x267508 cmp r0, #133 */
/* @0x26750c beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x267510 bhi 0x267790 <_pcre_xclass+0xae4> */
/* @0x267514 sub r0, r0, #10 */
/* @0x267518 cmp r0, #3 */
/* @0x26751c bls 0x267228 <_pcre_xclass+0x57c> */
/* @0x267520 ldr r0, [r5, #0x4]! */
/* @0x267524 cmn r0, #1 */
/* @0x267528 beq 0x2678e4 <_pcre_xclass+0xc38> */
/* @0x26752c ldr r2, [r4] */
/* @0x267530 b 0x26734c <_pcre_xclass+0x6a0> */
/* @0x267534 cmp r0, #255 */
/* @0x267538 bhi 0x267520 <_pcre_xclass+0x874> */
/* @0x26753c b 0x2676f4 <_pcre_xclass+0xa48> */
/* @0x267540 cmp r0, r10 */
/* @0x267544 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x267548 bls 0x267864 <_pcre_xclass+0xbb8> */
/* @0x26754c movw r2, #0x202f */
/* @0x267550 cmp r0, r2 */
/* @0x267554 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x267558 bhi 0x267904 <_pcre_xclass+0xc58> */
/* @0x26755c sub r0, r0, #8192 */
/* @0x267560 cmp r0, #10 */
/* @0x267564 bhi 0x267520 <_pcre_xclass+0x874> */
/* @0x267568 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26756c cmp r0, r10 */
/* @0x267570 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267574 bls 0x26787c <_pcre_xclass+0xbd0> */
/* @0x267578 movw r2, #0x202f */
/* @0x26757c cmp r0, r2 */
/* @0x267580 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267584 bls 0x2679a4 <_pcre_xclass+0xcf8> */
/* @0x267588 movw r2, #0x205f */
/* @0x26758c cmp r0, r2 */
/* @0x267590 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267594 cmp r0, #12288 */
/* @0x267598 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x26759c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2675a0 cmp r0, #133 */
/* @0x2675a4 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x2675a8 bls 0x26789c <_pcre_xclass+0xbf0> */
/* @0x2675ac sub r2, r0, #8192 */
/* @0x2675b0 sub r2, r2, #40 */
/* @0x2675b4 cmp r2, #1 */
/* @0x2675b8 bls 0x267520 <_pcre_xclass+0x874> */
/* @0x2675bc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2675c0 mov r1, r4 */
/* @0x2675c4 ldr r2, [r1, #0x8]! */
/* @0x2675c8 b 0x2675d8 <_pcre_xclass+0x92c> */
/* @0x2675cc ldr r2, [r1, #0x4]! */
/* @0x2675d0 cmn r2, #1 */
/* @0x2675d4 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x2675d8 cmp r0, r2 */
/* @0x2675dc bne 0x2675cc <_pcre_xclass+0x920> */
/* @0x2675e0 cmn r0, #1 */
/* @0x2675e4 bne 0x267520 <_pcre_xclass+0x874> */
/* @0x2675e8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2675ec mov r1, r4 */
/* @0x2675f0 ldr r2, [r1, #0x8]! */
/* @0x2675f4 b 0x267604 <_pcre_xclass+0x958> */
/* @0x2675f8 ldr r2, [r1, #0x4]! */
/* @0x2675fc cmn r2, #1 */
/* @0x267600 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267604 cmp r0, r2 */
/* @0x267608 bne 0x2675f8 <_pcre_xclass+0x94c> */
/* @0x26760c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267610 ldr r1, [r4, #0x8] */
/* @0x267614 cmp r4, r9 */
/* @0x267618 ldr r12, [sp, #0x58] */
/* @0x26761c mov r2, r8 */
/* @0x267620 rsb r1, r1, #2 */
/* @0x267624 moveq r12, r6 */
/* @0x267628 add r1, r12, r1 */
/* @0x26762c str r3, [sp, #0x8] */
/* @0x267630 bl 0x266cac <_pcre_xclass> */
/* @0x267634 ldr r3, [sp, #0x8] */
/* @0x267638 cmp r0, #0 */
/* @0x26763c beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267640 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267644 cmp r0, #254 */
/* @0x267648 bhi 0x267520 <_pcre_xclass+0x874> */
/* @0x26764c ldr r2, [r7, #0xc] */
/* @0x267650 ldrb r2, [r2, r0] */
/* @0x267654 tst r2, #16 */
/* @0x267658 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x26765c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267660 cmp r0, #255 */
/* @0x267664 bhi 0x267228 <_pcre_xclass+0x57c> */
/* @0x267668 ldr r2, [r7, #0xc] */
/* @0x26766c ldrb r2, [r2, r0] */
/* @0x267670 tst r2, #16 */
/* @0x267674 bne 0x267520 <_pcre_xclass+0x874> */
/* @0x267678 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26767c cmp r0, #255 */
/* @0x267680 bhi 0x267520 <_pcre_xclass+0x874> */
/* @0x267684 ldr r2, [r7, #0xc] */
/* @0x267688 ldrb r2, [r2, r0] */
/* @0x26768c tst r2, #1 */
/* @0x267690 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267694 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267698 cmp r0, #255 */
/* @0x26769c bhi 0x267228 <_pcre_xclass+0x57c> */
/* @0x2676a0 ldr r2, [r7, #0xc] */
/* @0x2676a4 ldrb r2, [r2, r0] */
/* @0x2676a8 tst r2, #1 */
/* @0x2676ac bne 0x267520 <_pcre_xclass+0x874> */
/* @0x2676b0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2676b4 cmp r0, #255 */
/* @0x2676b8 bhi 0x267520 <_pcre_xclass+0x874> */
/* @0x2676bc ldr r2, [r7, #0xc] */
/* @0x2676c0 ldrb r2, [r2, r0] */
/* @0x2676c4 tst r2, #4 */
/* @0x2676c8 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x2676cc b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2676d0 cmp r0, #255 */
/* @0x2676d4 bhi 0x267228 <_pcre_xclass+0x57c> */
/* @0x2676d8 ldr r2, [r7, #0xc] */
/* @0x2676dc ldrb r2, [r2, r0] */
/* @0x2676e0 tst r2, #4 */
/* @0x2676e4 bne 0x267520 <_pcre_xclass+0x874> */
/* @0x2676e8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2676ec cmp r0, #255 */
/* @0x2676f0 bhi 0x267228 <_pcre_xclass+0x57c> */
/* @0x2676f4 ldr r12, [sp, #0x58] */
/* @0x2676f8 cmp r4, r9 */
/* @0x2676fc ldr r1, [r4, #0x8] */
/* @0x267700 and r2, r0, #7 */
/* @0x267704 moveq r12, r6 */
/* @0x267708 rsb r1, r1, r12 */
/* @0x26770c ldrb r1, [r1, r0, lsr #3] */
/* @0x267710 asr r2, r1, r2 */
/* @0x267714 tst r2, #1 */
/* @0x267718 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x26771c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267720 cmp r8, #0 */
/* @0x267724 beq 0x267828 <_pcre_xclass+0xb7c> */
/* @0x267728 ldr r3, [sp, #0x18] */
/* @0x26772c mov r1, r6 */
/* @0x267730 rsb r3, r3, r4 */
/* @0x267734 cmp r2, #10 */
/* @0x267738 beq 0x267988 <_pcre_xclass+0xcdc> */
/* @0x26773c bhi 0x2678bc <_pcre_xclass+0xc10> */
/* @0x267740 cmp r2, #7 */
/* @0x267744 beq 0x2678ac <_pcre_xclass+0xc00> */
/* @0x267748 bls 0x26791c <_pcre_xclass+0xc70> */
/* @0x26774c cmp r2, #8 */
/* @0x267750 beq 0x267990 <_pcre_xclass+0xce4> */
/* @0x267754 cmp r2, #9 */
/* @0x267758 bne 0x267228 <_pcre_xclass+0x57c> */
/* @0x26775c mov r1, #0 */
/* @0x267760 ldr r2, [r7, #0x8] */
/* @0x267764 cmp r1, #0 */
/* @0x267768 add r1, r3, #32 */
/* @0x26776c bne 0x26777c <_pcre_xclass+0xad0> */
/* @0x267770 b 0x267850 <_pcre_xclass+0xba4> */
/* @0x267774 cmp r1, r3 */
/* @0x267778 beq 0x2671c0 <_pcre_xclass+0x514> */
/* @0x26777c ldrb r12, [r2], #1 */
/* @0x267780 ldrb r0, [r3], #1 */
/* @0x267784 bics r0, r0, r12 */
/* @0x267788 beq 0x267774 <_pcre_xclass+0xac8> */
/* @0x26778c b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267790 sub r2, r0, #8192 */
/* @0x267794 sub r2, r2, #40 */
/* @0x267798 cmp r2, #1 */
/* @0x26779c bhi 0x267520 <_pcre_xclass+0x874> */
/* @0x2677a0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2677a4 add r5, sp, #24 */
/* @0x2677a8 mov r3, r6 */
/* @0x2677ac b 0x267338 <_pcre_xclass+0x68c> */
/* @0x2677b0 ldr r2, [sp, #0x5c] */
/* @0x2677b4 ldr r3, [r2] */
/* @0x2677b8 cmp r3, #0 */
/* @0x2677bc beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x2677c0 ldr r2, [sp, #0x58] */
/* @0x2677c4 sub r3, r3, #1 */
/* @0x2677c8 ldr r0, [sp, #0x5c] */
/* @0x2677cc mov r1, r8 */
/* @0x2677d0 str r2, [sp] */
/* @0x2677d4 ldr r2, [sp, #0x5c] */
/* @0x2677d8 str r3, [r0] */
/* @0x2677dc mov r0, r4 */
/* @0x2677e0 mov r3, r6 */
/* @0x2677e4 add r4, r11, #3 */
/* @0x2677e8 str r2, [sp, #0x4] */
/* @0x2677ec mov r2, r7 */
/* @0x2677f0 bl 0x2670bc <_pcre_xclass+0x410> */
/* @0x2677f4 cmp r0, #0 */
/* @0x2677f8 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x2677fc ldrb r5, [r11, #0x1] */
/* @0x267800 ldrb r12, [r11, #0x2] */
/* @0x267804 orr r12, r12, r5, lsl #8 */
/* @0x267808 ldrb r12, [r11, r12]! */
/* @0x26780c cmp r12, #119 */
/* @0x267810 bne 0x267318 <_pcre_xclass+0x66c> */
/* @0x267814 ldr r0, [sp, #0x5c] */
/* @0x267818 ldr r3, [r0] */
/* @0x26781c cmp r3, #0 */
/* @0x267820 bne 0x2677c0 <_pcre_xclass+0xb14> */
/* @0x267824 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267828 cmp r2, #111 */
/* @0x26782c bne 0x267728 <_pcre_xclass+0xa7c> */
/* @0x267830 ldr r3, [r6, #0x8] */
/* @0x267834 mov r2, r1 */
/* @0x267838 ldr r0, [sp, #0x58] */
/* @0x26783c mov r1, r9 */
/* @0x267840 rsb r3, r3, r0 */
/* @0x267844 b 0x267734 <_pcre_xclass+0xa88> */
/* @0x267848 cmp r3, r1 */
/* @0x26784c bhs 0x2671c0 <_pcre_xclass+0x514> */
/* @0x267850 ldrb r12, [r2], #1 */
/* @0x267854 ldrb r0, [r3], #1 */
/* @0x267858 tst r12, r0 */
/* @0x26785c beq 0x267848 <_pcre_xclass+0xb9c> */
/* @0x267860 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267864 cmp r0, #32 */
/* @0x267868 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x26786c bhi 0x2678f0 <_pcre_xclass+0xc44> */
/* @0x267870 cmp r0, #9 */
/* @0x267874 bne 0x267520 <_pcre_xclass+0x874> */
/* @0x267878 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26787c cmp r0, #32 */
/* @0x267880 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267884 bls 0x267998 <_pcre_xclass+0xcec> */
/* @0x267888 cmp r0, #160 */
/* @0x26788c beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267890 cmp r0, #5760 */
/* @0x267894 beq 0x267520 <_pcre_xclass+0x874> */
/* @0x267898 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26789c sub r0, r0, #10 */
/* @0x2678a0 cmp r0, #3 */
/* @0x2678a4 bls 0x267520 <_pcre_xclass+0x874> */
/* @0x2678a8 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2678ac mov r1, #0 */
/* @0x2678b0 ldr r2, [r7, #0x8] */
/* @0x2678b4 add r2, r2, #64 */
/* @0x2678b8 b 0x267764 <_pcre_xclass+0xab8> */
/* @0x2678bc cmp r2, #111 */
/* @0x2678c0 bhi 0x26792c <_pcre_xclass+0xc80> */
/* @0x2678c4 cmp r2, #110 */
/* @0x2678c8 bhs 0x267970 <_pcre_xclass+0xcc4> */
/* @0x2678cc cmp r2, #11 */
/* @0x2678d0 bne 0x267228 <_pcre_xclass+0x57c> */
/* @0x2678d4 mov r1, #0 */
/* @0x2678d8 ldr r2, [r7, #0x8] */
/* @0x2678dc add r2, r2, #160 */
/* @0x2678e0 b 0x267764 <_pcre_xclass+0xab8> */
/* @0x2678e4 mov r4, r6 */
/* @0x2678e8 mov r6, r3 */
/* @0x2678ec b 0x2671c0 <_pcre_xclass+0x514> */
/* @0x2678f0 cmp r0, #160 */
/* @0x2678f4 beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x2678f8 cmp r0, #5760 */
/* @0x2678fc bne 0x267520 <_pcre_xclass+0x874> */
/* @0x267900 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x267904 movw r2, #0x205f */
/* @0x267908 cmp r0, r2 */
/* @0x26790c beq 0x267228 <_pcre_xclass+0x57c> */
/* @0x267910 cmp r0, #12288 */
/* @0x267914 bne 0x267520 <_pcre_xclass+0x874> */
/* @0x267918 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x26791c cmp r2, #6 */
/* @0x267920 bne 0x267228 <_pcre_xclass+0x57c> */
/* @0x267924 mov r1, #1 */
/* @0x267928 b 0x2678b0 <_pcre_xclass+0xc04> */
/* @0x26792c cmp r2, #112 */
/* @0x267930 bne 0x267228 <_pcre_xclass+0x57c> */
/* @0x267934 ldr r2, [sp, #0x58] */
/* @0x267938 cmp r1, r9 */
/* @0x26793c ldr r0, [r1, #0x8] */
/* @0x267940 moveq r2, r4 */
/* @0x267944 rsb r0, r0, #2 */
/* @0x267948 mov r1, r2 */
/* @0x26794c add r2, r2, r0 */
/* @0x267950 ldrb r1, [r1, r0] */
/* @0x267954 tst r1, #4 */
/* @0x267958 bne 0x267228 <_pcre_xclass+0x57c> */
/* @0x26795c tst r1, #2 */
/* @0x267960 beq 0x2671c0 <_pcre_xclass+0x514> */
/* @0x267964 add r2, r2, #1 */
/* @0x267968 add r1, r3, #32 */
/* @0x26796c b 0x267850 <_pcre_xclass+0xba4> */
/* @0x267970 ldr r0, [sp, #0x58] */
/* @0x267974 cmp r1, r9 */
/* @0x267978 ldr r2, [r1, #0x8] */
/* @0x26797c moveq r0, r4 */
/* @0x267980 rsb r2, r2, r0 */
/* @0x267984 b 0x267968 <_pcre_xclass+0xcbc> */
/* @0x267988 mov r1, #1 */
/* @0x26798c b 0x2678d8 <_pcre_xclass+0xc2c> */
/* @0x267990 mov r1, #1 */
/* @0x267994 b 0x267760 <_pcre_xclass+0xab4> */
/* @0x267998 cmp r0, #9 */
/* @0x26799c beq 0x267520 <_pcre_xclass+0x874> */
/* @0x2679a0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2679a4 sub r0, r0, #8192 */
/* @0x2679a8 cmp r0, #10 */
/* @0x2679ac bls 0x267520 <_pcre_xclass+0x874> */
/* @0x2679b0 b 0x267228 <_pcre_xclass+0x57c> */
/* @0x2679b4 andseq r2, r2, r12, ror #20 */
/* @0x2679b8 andseq r10, r8, r8, asr #10 */


/* ═══════════════════════════════════════════════════════════════════════
 * §4  anon_25b5c4  0x25b5c4..0x25bba8  1,516 B / 377 条  in-degree 4
 * libpcre 8.x —— pcre_compile.c 区的 opcode 分派体（入口指向组头，opcode 在 +3）
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 = 指向"组头"的指针（0x25b5cc 的 ldrb r3,[r0,#0x3] + 0x25b5d8 的 add r4,r0,#3
 *       ⇒ opcode 在 +3，r4 是体内游标）；r1 → r7；r2 → r8；r3 → r9（第 4 参，存 r9）。
 *
 * 身份证据（三条）
 *   ① 调用面共 4 处落点：pcre_compile2+0x10bc（0x268a7c）、0x25b524 簇内两处（0x25b95c /
 *      0x25ba40）、0x262b20（0x25fe2c 簇内）。本窗口内另有 2 处 bl 落回自身
 *      （0x25b5c4 → 0x25b5c4），即递归；窗口内 0 条 blx、0 条外部 bl。
 *   ② 162 项 opcode 表：0x25b5fc 的 cmp r3,#161 + 0x25b600 的 addls pc,pc,r3,lsl #2，
 *      表体 0x25b604 起 162 条 b（0x25b8e0 / 0x25b8b8 / 0x25b8f4 三个汇合点）。
 *   ③ +3 头长与 §1 同一约定：组头的本体从 opcode 后第 3 字节开始（注释 ③ 的 3/5 判定在
 *      0x25b5cc 处已由调用方算好）。
 *
 * 出口：3 个 pop {r4..r11,pc}（0x25b8d0 / 0x25b8dc / 0x25bb74）；窗口内 0 条分支跳出。
 * 边界：0x25bba4 是池字/误译（andseq），非指令。
 * open：1. 入参结构未定（r0 的 +3 是 opcode 还是一个 4 字节记录的第三字节）。
 *       2. 与 0x25b524（10,856 B 簇首，被簇内 6 处调用）的从属关系未定：本段既被它调用，
 *          也自递归，像"簇内的一台状态机"。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x25b5c4 0x25bba8 anon_25b5c4 pcre_compile_dispatch */

/* @0x25b5c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（递归状态机） */
/* @0x25b5c8 mov r9, r3 */
/* @0x25b5cc ldrb r3, [r0, #0x3] —— opcode 在 r0+3 */
/* @0x25b5d0 sub sp, sp, #28 */
/* @0x25b5d4 ldr r6, [pc, #0x5c8] */
/* @0x25b5d8 add r4, r0, #3 —— 体内游标 = 组头 + 3 */
/* @0x25b5dc mov r7, r1 */
/* @0x25b5e0 mov r5, #0 */
/* @0x25b5e4 mvn r10, #0 */
/* @0x25b5e8 mov r11, #1 */
/* @0x25b5ec mov r8, r2 */
/* @0x25b5f0 add r6, pc, r6 */
/* @0x25b5f4 add r2, sp, #16 */
/* @0x25b5f8 str r2, [sp, #0xc] */
/* @0x25b5fc cmp r3, #161 —— 162 项 opcode 表：cmp #161 */
/* @0x25b600 addls pc, pc, r3, lsl #2 —— addls pc,pc,r3,lsl #2 —— 表体从下一条开始 */
/* @0x25b604 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b608 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b60c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b610 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b614 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b618 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b61c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b620 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b624 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b628 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b62c b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b630 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b634 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b638 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b63c b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b640 b 0x25b8d4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7ac> */
/* @0x25b644 b 0x25b8b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x78c> */
/* @0x25b648 b 0x25b8b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x78c> */
/* @0x25b64c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b650 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b654 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b658 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b65c b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b660 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b664 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b668 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b66c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b670 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b674 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b678 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b67c b 0x25bb34 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa0c> */
/* @0x25b680 b 0x25bb34 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa0c> */
/* @0x25b684 b 0x25bb34 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa0c> */
/* @0x25b688 b 0x25bb34 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa0c> */
/* @0x25b68c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b690 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b694 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b698 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b69c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6a0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6a4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6a8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6ac b 0x25bad4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9ac> */
/* @0x25b6b0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6b4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6b8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6bc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6c0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6c4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6c8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6cc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6d0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6d4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6d8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6dc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6e0 b 0x25bad4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9ac> */
/* @0x25b6e4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6e8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6ec b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6f0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6f4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6f8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6fc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b700 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b704 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b708 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b70c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b710 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b714 b 0x25bad4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9ac> */
/* @0x25b718 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b71c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b720 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b724 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b728 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b72c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b730 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b734 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b738 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b73c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b740 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b744 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b748 b 0x25bad4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9ac> */
/* @0x25b74c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b750 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b754 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b758 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b75c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b760 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b764 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b768 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b76c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b770 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b774 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b778 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b77c b 0x25bb08 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9e0> */
/* @0x25b780 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b784 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b788 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b78c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b790 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b794 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b798 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b79c b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7a0 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7a4 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7a8 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7ac b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7b0 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7b4 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7b8 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7bc b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7c0 b 0x25ba5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x934> */
/* @0x25b7c4 b 0x25ba5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x934> */
/* @0x25b7c8 b 0x25ba5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x934> */
/* @0x25b7cc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7d0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7d4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7d8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7dc b 0x25b990 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x868> */
/* @0x25b7e0 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b7e4 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b7e8 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b7ec b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7f0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7f4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7f8 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b7fc b 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b800 b 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b804 b 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b808 b 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b80c b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b810 b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b814 b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b818 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b81c b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b820 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b824 b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b828 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b82c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b830 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b834 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b838 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b83c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b840 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b844 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b848 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b84c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b850 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b854 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b858 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b85c b 0x25b91c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7f4> */
/* @0x25b860 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b864 b 0x25b91c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7f4> */
/* @0x25b868 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b86c b 0x25b91c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7f4> */
/* @0x25b870 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b874 b 0x25b91c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7f4> */
/* @0x25b878 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b87c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b880 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b884 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b888 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b88c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b890 ldrb r2, [r4, #0x1] */
/* @0x25b894 ldrb r3, [r4, #0x2] */
/* @0x25b898 orr r3, r3, r2, lsl #8 */
/* @0x25b89c ldrb r3, [r4, r3]! */
/* @0x25b8a0 cmp r3, #119 */
/* @0x25b8a4 beq 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b8a8 ldrb r3, [r4, #0x3] */
/* @0x25b8ac add r4, r4, #3 */
/* @0x25b8b0 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b8b4 add r4, r4, #2 */
/* @0x25b8b8 ldrb r3, [r4, #0x1] */
/* @0x25b8bc add r5, r5, #1 */
/* @0x25b8c0 add r4, r4, #1 */
/* @0x25b8c4 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b8c8 mvn r0, #0 */
/* @0x25b8cc add sp, sp, #28 */
/* @0x25b8d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1 */
/* @0x25b8d4 mvn r0, #1 */
/* @0x25b8d8 add sp, sp, #28 */
/* @0x25b8dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2 */
/* @0x25b8e0 ldr r2, [pc, #0x2c0] */
/* @0x25b8e4 ldr r2, [r6, r2] */
/* @0x25b8e8 ldrb r3, [r2, r3] */
/* @0x25b8ec ldrb r3, [r4, r3]! */
/* @0x25b8f0 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b8f4 cmp r10, #0 */
/* @0x25b8f8 blt 0x25bb8c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa64> */
/* @0x25b8fc cmp r10, r5 */
/* @0x25b900 bne 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b904 cmp r3, #119 */
/* @0x25b908 bne 0x25bb9c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa74> */
/* @0x25b90c ldrb r3, [r4, #0x3] */
/* @0x25b910 mov r5, #0 */
/* @0x25b914 add r4, r4, #3 */
/* @0x25b918 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b91c ldr r1, [pc, #0x284] */
/* @0x25b920 ldrb r2, [r4, #0x1] */
/* @0x25b924 ldr r1, [r6, r1] */
/* @0x25b928 ldrb r3, [r1, r3] */
/* @0x25b92c add r3, r2, r3 */
/* @0x25b930 ldrb r3, [r4, r3]! */
/* @0x25b934 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b938 cmp r3, #133 */
/* @0x25b93c ldr r3, [sp, #0x40] */
/* @0x25b940 mov r1, r7 */
/* @0x25b944 mov r2, r8 */
/* @0x25b948 moveq r0, #2 */
/* @0x25b94c movne r0, #0 */
/* @0x25b950 str r3, [sp] */
/* @0x25b954 add r0, r4, r0 */
/* @0x25b958 mov r3, r9 */
/* @0x25b95c bl 0x25b5c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x25b960 cmp r0, #0 */
/* @0x25b964 blt 0x25b8cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a4> */
/* @0x25b968 add r5, r5, r0 */
/* @0x25b96c ldrb r2, [r4, #0x1] */
/* @0x25b970 ldrb r3, [r4, #0x2] */
/* @0x25b974 orr r3, r3, r2, lsl #8 */
/* @0x25b978 ldrb r3, [r4, r3]! */
/* @0x25b97c cmp r3, #119 */
/* @0x25b980 beq 0x25b96c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x844> */
/* @0x25b984 ldrb r3, [r4, #0x3] */
/* @0x25b988 add r4, r4, #3 */
/* @0x25b98c b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b990 cmp r8, #0 */
/* @0x25b994 beq 0x25bb94 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa6c> */
/* @0x25b998 ldrb r12, [r4, #0x1] */
/* @0x25b99c ldrb r2, [r4, #0x2] */
/* @0x25b9a0 ldr r3, [r9, #0x14] */
/* @0x25b9a4 orr r12, r2, r12, lsl #8 */
/* @0x25b9a8 add r12, r3, r12 */
/* @0x25b9ac mov r3, r12 */
/* @0x25b9b0 ldrb r1, [r3, #0x1] */
/* @0x25b9b4 ldrb r2, [r3, #0x2] */
/* @0x25b9b8 orr r2, r2, r1, lsl #8 */
/* @0x25b9bc ldrb r2, [r3, r2]! */
/* @0x25b9c0 cmp r2, #119 */
/* @0x25b9c4 beq 0x25b9b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x888> */
/* @0x25b9c8 cmp r4, r3 */
/* @0x25b9cc movhs r3, #0 */
/* @0x25b9d0 movlo r3, #1 */
/* @0x25b9d4 cmp r4, r12 */
/* @0x25b9d8 movls r3, #0 */
/* @0x25b9dc cmp r3, #0 */
/* @0x25b9e0 bne 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b9e4 ldr r2, [sp, #0x40] */
/* @0x25b9e8 cmp r2, #0 */
/* @0x25b9ec beq 0x25ba1c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x8f4> */
/* @0x25b9f0 ldr r3, [r2, #0x4] */
/* @0x25b9f4 cmp r12, r3 */
/* @0x25b9f8 beq 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b9fc mov r3, r2 */
/* @0x25ba00 b 0x25ba10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x8e8> */
/* @0x25ba04 ldr r2, [r3, #0x4] */
/* @0x25ba08 cmp r12, r2 */
/* @0x25ba0c beq 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25ba10 ldr r3, [r3] */
/* @0x25ba14 cmp r3, #0 */
/* @0x25ba18 bne 0x25ba04 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x8dc> */
/* @0x25ba1c ldr lr, [sp, #0x40] */
/* @0x25ba20 add r3, sp, #16 */
/* @0x25ba24 add r0, r12, #2 */
/* @0x25ba28 str r3, [sp] */
/* @0x25ba2c mov r1, r7 */
/* @0x25ba30 mov r2, r8 */
/* @0x25ba34 mov r3, r9 */
/* @0x25ba38 str lr, [sp, #0x10] */
/* @0x25ba3c str r12, [sp, #0x14] */
/* @0x25ba40 bl 0x25b5c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x25ba44 cmp r0, #0 */
/* @0x25ba48 blt 0x25b8cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a4> */
/* @0x25ba4c ldrb r3, [r4, #0x3] */
/* @0x25ba50 add r5, r5, r0 */
/* @0x25ba54 add r4, r4, #3 */
/* @0x25ba58 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25ba5c cmp r3, #112 */
/* @0x25ba60 addne r4, r4, #33 */
/* @0x25ba64 ldrbeq r2, [r4, #0x1] */
/* @0x25ba68 ldrbeq r3, [r4, #0x2] */
/* @0x25ba6c orreq r3, r3, r2, lsl #8 */
/* @0x25ba70 addeq r4, r4, r3 */
/* @0x25ba74 ldrb r3, [r4] */
/* @0x25ba78 sub r2, r3, #98 */
/* @0x25ba7c uxtb r2, r2 */
/* @0x25ba80 cmp r2, #11 */
/* @0x25ba84 bhi 0x25bb84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa5c> */
/* @0x25ba88 lsl r2, r11, r2 */
/* @0x25ba8c movw r1, #0x73f */
/* @0x25ba90 and r1, r2, r1 */
/* @0x25ba94 cmp r1, #0 */
/* @0x25ba98 bne 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25ba9c tst r2, #2240 */
/* @0x25baa0 beq 0x25bb84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa5c> */
/* @0x25baa4 ldrb r0, [r4, #0x1] */
/* @0x25baa8 ldrb r1, [r4, #0x3] */
/* @0x25baac ldrb r3, [r4, #0x2] */
/* @0x25bab0 ldrb r2, [r4, #0x4] */
/* @0x25bab4 orr r3, r3, r0, lsl #8 */
/* @0x25bab8 orr r2, r2, r1, lsl #8 */
/* @0x25babc cmp r3, r2 */
/* @0x25bac0 bne 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25bac4 add r5, r5, r3 */
/* @0x25bac8 add r4, r4, #5 */
/* @0x25bacc ldrb r3, [r4] */
/* @0x25bad0 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bad4 ldrb r1, [r4, #0x1] */
/* @0x25bad8 cmp r7, #0 */
/* @0x25badc ldrb r3, [r4, #0x2] */
/* @0x25bae0 add r2, r4, #4 */
/* @0x25bae4 orr r3, r3, r1, lsl #8 */
/* @0x25bae8 add r5, r5, r3 */
/* @0x25baec beq 0x25bafc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9d4> */
/* @0x25baf0 ldrb r3, [r4, #0x3] */
/* @0x25baf4 cmp r3, #191 */
/* @0x25baf8 bhi 0x25bb50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa28> */
/* @0x25bafc ldrb r3, [r4, #0x4] */
/* @0x25bb00 mov r4, r2 */
/* @0x25bb04 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb08 ldrb r1, [r4, #0x3] */
/* @0x25bb0c ldrb r2, [r4, #0x1] */
/* @0x25bb10 sub r1, r1, #15 */
/* @0x25bb14 ldrb r3, [r4, #0x2] */
/* @0x25bb18 cmp r1, #1 */
/* @0x25bb1c addls r4, r4, #2 */
/* @0x25bb20 orr r3, r3, r2, lsl #8 */
/* @0x25bb24 add r5, r3, r5 */
/* @0x25bb28 add r4, r4, #4 */
/* @0x25bb2c ldrb r3, [r4] */
/* @0x25bb30 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb34 cmp r7, #0 */
/* @0x25bb38 add r5, r5, #1 */
/* @0x25bb3c add r2, r4, #2 */
/* @0x25bb40 beq 0x25bb78 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa50> */
/* @0x25bb44 ldrb r3, [r4, #0x1] */
/* @0x25bb48 cmp r3, #191 */
/* @0x25bb4c bls 0x25bb78 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa50> */
/* @0x25bb50 ldr r1, [pc, #0x54] */
/* @0x25bb54 and r3, r3, #63 */
/* @0x25bb58 ldr r1, [r6, r1] */
/* @0x25bb5c ldrb r3, [r1, r3] */
/* @0x25bb60 add r4, r2, r3 */
/* @0x25bb64 ldrb r3, [r2, r3] */
/* @0x25bb68 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb6c mvn r0, #3 */
/* @0x25bb70 add sp, sp, #28 */
/* @0x25bb74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 3 */
/* @0x25bb78 ldrb r3, [r4, #0x2] */
/* @0x25bb7c mov r4, r2 */
/* @0x25bb80 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb84 add r5, r5, #1 */
/* @0x25bb88 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb8c mov r10, r5 */
/* @0x25bb90 b 0x25b904 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7dc> */
/* @0x25bb94 mvn r0, #2 */
/* @0x25bb98 b 0x25b8cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a4> */
/* @0x25bb9c mov r0, r10 */
/* @0x25bba0 b 0x25b8cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a4> */
/* @0x25bba4 andseq r6, r9, r0, ror #12 */


/* ═══════════════════════════════════════════════════════════════════════
 * §5  anon_25c788  0x25c788..0x25c988  512 B / 128 条  in-degree 4
 * libpcre 8.x —— 同簇的小型 opcode 过滤/跳过例程（512 B，3 个出口）
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 = 码流指针（0x25c79c 的 ldrb r0,[r0] 取 opcode）；r1 → r5；r2 → r6；
 *       r3 → r7（0x25c7a0 的 add r3,r3,#1 把某个索引前移）；第 7 参 [sp+0x38] → r9。
 *
 * 身份证据（三条）
 *   ① 调用面共 4 处落点：pcre_compile2+0x14a4（0x268e64）、本簇内 0x25c880 / 0x25c900 /
 *      0x25c968；窗口内另有 2 处 bl 到 0x25b524（簇首）与 3 处自递归。
 *   ② 与 §1 同一套 +5 族判定：0x25c7c0 的 sub r1,r3,#133 + 0x25c7c4 的 sub r2,r3,#138 +
 *      0x25c7c8 的 cmp r2,#1 + 0x25c7cc 的 cmphi r1,#1 → 命中 {133,134,138,139} 走 0x25c894；
 *      _pcre_OP_lengths 在这四码取 5（0x38ba04 已读表复核）。
 *   ③ 逐码分流：0x25c7d4 的 cmp #125、0x25c7dc 的 cmp #129（{129,130} 走 0x25c958）、
 *      0x25c7e8 的 cmp #85 / #94 一组；0x25c7f8 的 ldrb r3,[r0,#0x1] 读次字节。
 *
 * 出口：3 个 pop {r4..r11,pc}（0x25c890 / 0x25c94c / 0x25c980）；窗口内 0 条分支跳出。
 * 边界：0x25c984 是池字/误译（andseq），非指令。
 * open：1. 具体语义（过滤/跳过哪几类 opcode）未与源码对齐 —— 本卡只钉"按 opcode 分类、
 *          对 133/134/138/139 特殊处理、会回跳 0x25b524 取子结构"。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x25c788 0x25c988 anon_25c788 pcre_compile_filter */

/* @0x25c788 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（9 寄存器 + 20 B 帧） */
/* @0x25c78c sub sp, sp, #20 */
/* @0x25c790 ldr r8, [pc, #0x1ec] */
/* @0x25c794 mov r11, r0 */
/* @0x25c798 mov r7, r3 */
/* @0x25c79c ldrb r0, [r0] —— 读 opcode */
/* @0x25c7a0 add r3, r3, #1 */
/* @0x25c7a4 ldr r9, [sp, #0x38] */
/* @0x25c7a8 str r3, [sp, #0xc] */
/* @0x25c7ac ldr r8, [pc, r8] */
/* @0x25c7b0 mov r5, r1 */
/* @0x25c7b4 mov r6, r2 */
/* @0x25c7b8 mov r10, #1 */
/* @0x25c7bc b 0x25c840 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1718> */
/* @0x25c7c0 sub r1, r3, #133 —— sub #133 / #138 → 判 {133,134,138,139} */
/* @0x25c7c4 sub r2, r3, #138 */
/* @0x25c7c8 cmp r2, #1 */
/* @0x25c7cc cmphi r1, #1 —— cmphi —— 命中则走 0x25c894 */
/* @0x25c7d0 bls 0x25c894 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x176c> */
/* @0x25c7d4 cmp r3, #125 */
/* @0x25c7d8 beq 0x25c950 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1828> */
/* @0x25c7dc sub r1, r3, #129 */
/* @0x25c7e0 cmp r1, #1 */
/* @0x25c7e4 bls 0x25c958 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1830> */
/* @0x25c7e8 sub r1, r3, #85 */
/* @0x25c7ec cmp r3, #94 */
/* @0x25c7f0 cmpne r1, #1 */
/* @0x25c7f4 bhi 0x25c938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1810> */
/* @0x25c7f8 ldrb r3, [r0, #0x1] */
/* @0x25c7fc cmp r3, #12 */
/* @0x25c800 bne 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c804 ldr r3, [r6, #0x50] */
/* @0x25c808 ands r3, r5, r3 */
/* @0x25c80c bne 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c810 cmp r7, #0 */
/* @0x25c814 bgt 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c818 ldr r2, [r6, #0x70] */
/* @0x25c81c orrs r2, r9, r2 */
/* @0x25c820 bne 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c824 ldrb r2, [r11, #0x1] */
/* @0x25c828 ldrb r3, [r11, #0x2] */
/* @0x25c82c orr r3, r3, r2, lsl #8 */
/* @0x25c830 ldrb r3, [r11, r3]! */
/* @0x25c834 cmp r3, #119 */
/* @0x25c838 bne 0x25c978 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1850> */
/* @0x25c83c mov r0, r3 */
/* @0x25c840 ldrb r0, [r8, r0] */
/* @0x25c844 mov r1, #0 */
/* @0x25c848 add r0, r11, r0 */
/* @0x25c84c bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25c850 ldrb r3, [r0] */
/* @0x25c854 cmp r3, #135 */
/* @0x25c858 beq 0x25c8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1790> */
/* @0x25c85c sub r1, r3, #136 */
/* @0x25c860 sub r2, r3, #131 */
/* @0x25c864 cmp r2, #1 */
/* @0x25c868 cmphi r1, #1 */
/* @0x25c86c strls r9, [sp] */
/* @0x25c870 bhi 0x25c7c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1698> */
/* @0x25c874 mov r1, r5 */
/* @0x25c878 mov r2, r6 */
/* @0x25c87c mov r3, r7 */
/* @0x25c880 bl 0x25c788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1660> */
/* @0x25c884 cmp r0, #0 */
/* @0x25c888 bne 0x25c824 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16fc> */
/* @0x25c88c add sp, sp, #20 */
/* @0x25c890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1 */
/* @0x25c894 ldrb r2, [r0, #0x3] */
/* @0x25c898 ldrb r3, [r0, #0x4] */
/* @0x25c89c str r9, [sp] */
/* @0x25c8a0 orr r3, r3, r2, lsl #8 */
/* @0x25c8a4 cmp r3, #31 */
/* @0x25c8a8 lslle r1, r10, r3 */
/* @0x25c8ac movgt r1, #1 */
/* @0x25c8b0 orr r1, r1, r5 */
/* @0x25c8b4 b 0x25c878 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1750> */
/* @0x25c8b8 ldrb r3, [r0, #0x3] */
/* @0x25c8bc cmp r3, #118 */
/* @0x25c8c0 addne r4, r0, #3 */
/* @0x25c8c4 addeq r4, r0, #9 */
/* @0x25c8c8 ldrbeq r3, [r0, #0x9] */
/* @0x25c8cc add r3, r3, #115 */
/* @0x25c8d0 uxtb r3, r3 */
/* @0x25c8d4 cmp r3, #16 */
/* @0x25c8d8 bhi 0x25c8ec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x17c4> */
/* @0x25c8dc mov r2, #31 */
/* @0x25c8e0 movt r2, #0x1 */
/* @0x25c8e4 ands r2, r2, r10, lsl r3 */
/* @0x25c8e8 bne 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c8ec str r10, [sp] */
/* @0x25c8f0 mov r0, r4 */
/* @0x25c8f4 mov r1, r5 */
/* @0x25c8f8 mov r2, r6 */
/* @0x25c8fc mov r3, r7 */
/* @0x25c900 bl 0x25c788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1660> */
/* @0x25c904 cmp r0, #0 */
/* @0x25c908 beq 0x25c88c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1764> */
/* @0x25c90c ldrb r2, [r4, #0x1] */
/* @0x25c910 ldrb r3, [r4, #0x2] */
/* @0x25c914 orr r3, r3, r2, lsl #8 */
/* @0x25c918 ldrb r3, [r4, r3]! */
/* @0x25c91c cmp r3, #119 */
/* @0x25c920 beq 0x25c90c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x17e4> */
/* @0x25c924 add r0, r4, #3 */
/* @0x25c928 mov r1, #0 */
/* @0x25c92c bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25c930 ldrb r3, [r0] */
/* @0x25c934 b 0x25c85c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1734> */
/* @0x25c938 sub r3, r3, #27 */
/* @0x25c93c cmp r3, #1 */
/* @0x25c940 bls 0x25c824 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16fc> */
/* @0x25c944 mov r0, #0 */
/* @0x25c948 add sp, sp, #20 */
/* @0x25c94c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2 */
/* @0x25c950 str r10, [sp] */
/* @0x25c954 b 0x25c874 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174c> */
/* @0x25c958 str r9, [sp] */
/* @0x25c95c mov r1, r5 */
/* @0x25c960 mov r2, r6 */
/* @0x25c964 ldr r3, [sp, #0xc] */
/* @0x25c968 bl 0x25c788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1660> */
/* @0x25c96c cmp r0, #0 */
/* @0x25c970 bne 0x25c824 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16fc> */
/* @0x25c974 b 0x25c88c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1764> */
/* @0x25c978 mov r0, #1 */
/* @0x25c97c add sp, sp, #20 */
/* @0x25c980 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 3 */
/* @0x25c984 andseq r5, r9, r0, lsr r0 */


/* ═══════════════════════════════════════════════════════════════════════
 * §6  anon_265c10  0x265c10..0x266564  2,388 B / 597 条  in-degree 3
 * libpcre 8.x —— pcre_study.c 第二个递归遍历器（32/16 步长 + 两张 162 项 opcode 表）
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 = 码流指针（0x265c20 的 ldrb r1,[r0] 取 opcode）；r1 → r4（写回的结构：
 *       +0x1 / +0x14 / +0x1c 有 strb）；r2 → r6（决定 32 还是 16 的步长）；r3 → r5。
 *
 * 身份证据（四条）
 *   ① 调用面：pcre_study+0xec（0x2666cc，pcre_study 0x2665e0 具名）bl 到本段；段内 2 处
 *      bl 落回自身（0x26617c / 0x2661f8）⇒ 递归。
 *   ② 两张 162 项 opcode 表：0x265c70 的 cmp r3,#161 + 0x265c74 的 addls pc,pc,r3,lsl #2，
 *      以及 0x266088 的第二张 addls pc,pc,r3,lsl #2 —— 同一函数里出现两个满表分派点。
 *   ③ 32/16 步长：0x265c24 的 cmp r6,#0 后，0x265c38 的 moveq r9,#32 / 0x265c3c 的
 *      movne r9,#16 —— pcre 的 class 位图宽度按 8 位/16 位字符域二选一。
 *   ④ 与 UTF-8/UTF-16 相关的外部件：bl _pcre_ord2utf（0x25fd98，148 B，具名）×1、
 *      memset@plt(0xb65b0) ×1、0x265b58 ×6（紧邻的前一个函数，184 B）、0x25da18 ×4 /
 *      0x25dad0 ×6（都在 0x25b524 簇内）。
 *
 * 出口：3 个 pop {r4..r11,pc}（0x266124 / 0x2661bc / 0x266448）；窗口内 0 条分支跳出。
 * 边界：段尾 0x266560 是 b 0x266120（回主循环），无池字。
 * open：1. 与 §1 的一一对应（谁是 set_start_bits、谁是 find_firstassertedchar）未定；
 *          本段带 32/16 步长更像"按字符域宽度处理 class 位图"的一侧。
 *       2. r4 结构的 +0x1/+0x14/+0x1c 三个标志字节语义未定。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x265c10 0x266564 anon_265c10 pcre_study_second_walker */

/* @0x265c10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（9 寄存器 + 28 B 帧） */
/* @0x265c14 sub sp, sp, #28 */
/* @0x265c18 mov r4, r1 */
/* @0x265c1c mov r6, r2 */
/* @0x265c20 ldrb r1, [r0] —— 读 opcode */
/* @0x265c24 cmp r6, #0 */
/* @0x265c28 add r2, r4, #25 */
/* @0x265c2c str r2, [sp, #0xc] */
/* @0x265c30 mov r2, #1 */
/* @0x265c34 mov r8, r0 */
/* @0x265c38 moveq r9, #32 —— 按第 3 参选步长：32 */
/* @0x265c3c movne r9, #16 */
/* @0x265c40 mov r5, r3 */
/* @0x265c44 mov r7, r2 */
/* @0x265c48 str r2, [sp, #0x8] */
/* @0x265c4c add r3, r1, #123 —— opcode + 123 归一化（与 §1 同族判定） */
/* @0x265c50 add r1, r1, #118 */
/* @0x265c54 uxtb r3, r3 */
/* @0x265c58 uxtb r1, r1 */
/* @0x265c5c cmp r1, #1 */
/* @0x265c60 cmphi r3, #1 */
/* @0x265c64 addhi r10, r8, #3 */
/* @0x265c68 addls r10, r8, #5 */
/* @0x265c6c ldrb r3, [r10] */
/* @0x265c70 cmp r3, #161 —— 第一张 162 项表：cmp #161 */
/* @0x265c74 addls pc, pc, r3, lsl #2 —— addls pc,pc,r3,lsl #2 */
/* @0x265c78 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265c7c b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265c80 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265c84 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265c88 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265c8c b 0x265f24 <_pcre_ord2utf+0x618c> */
/* @0x265c90 b 0x265f24 <_pcre_ord2utf+0x618c> */
/* @0x265c94 b 0x26614c <_pcre_ord2utf+0x63b4> */
/* @0x265c98 b 0x266134 <_pcre_ord2utf+0x639c> */
/* @0x265c9c b 0x266270 <_pcre_ord2utf+0x64d8> */
/* @0x265ca0 b 0x266258 <_pcre_ord2utf+0x64c0> */
/* @0x265ca4 b 0x266240 <_pcre_ord2utf+0x64a8> */
/* @0x265ca8 b 0x266228 <_pcre_ord2utf+0x6490> */
/* @0x265cac b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cb0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cb4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cb8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cbc b 0x26636c <_pcre_ord2utf+0x65d4> */
/* @0x265cc0 b 0x266334 <_pcre_ord2utf+0x659c> */
/* @0x265cc4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cc8 b 0x2662f0 <_pcre_ord2utf+0x6558> */
/* @0x265ccc b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cd0 b 0x266334 <_pcre_ord2utf+0x659c> */
/* @0x265cd4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cd8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cdc b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ce0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ce4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ce8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cec b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cf0 b 0x266038 <_pcre_ord2utf+0x62a0> */
/* @0x265cf4 b 0x2660d4 <_pcre_ord2utf+0x633c> */
/* @0x265cf8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265cfc b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d00 b 0x2662e4 <_pcre_ord2utf+0x654c> */
/* @0x265d04 b 0x2662e4 <_pcre_ord2utf+0x654c> */
/* @0x265d08 b 0x266038 <_pcre_ord2utf+0x62a0> */
/* @0x265d0c b 0x266038 <_pcre_ord2utf+0x62a0> */
/* @0x265d10 b 0x2662e4 <_pcre_ord2utf+0x654c> */
/* @0x265d14 b 0x2662e4 <_pcre_ord2utf+0x654c> */
/* @0x265d18 b 0x2662bc <_pcre_ord2utf+0x6524> */
/* @0x265d1c b 0x2662bc <_pcre_ord2utf+0x6524> */
/* @0x265d20 b 0x266034 <_pcre_ord2utf+0x629c> */
/* @0x265d24 b 0x2662e4 <_pcre_ord2utf+0x654c> */
/* @0x265d28 b 0x266038 <_pcre_ord2utf+0x62a0> */
/* @0x265d2c b 0x2662e4 <_pcre_ord2utf+0x654c> */
/* @0x265d30 b 0x2662bc <_pcre_ord2utf+0x6524> */
/* @0x265d34 b 0x2662b0 <_pcre_ord2utf+0x6518> */
/* @0x265d38 b 0x2662b0 <_pcre_ord2utf+0x6518> */
/* @0x265d3c b 0x2660d4 <_pcre_ord2utf+0x633c> */
/* @0x265d40 b 0x2660d4 <_pcre_ord2utf+0x633c> */
/* @0x265d44 b 0x2662b0 <_pcre_ord2utf+0x6518> */
/* @0x265d48 b 0x2662b0 <_pcre_ord2utf+0x6518> */
/* @0x265d4c b 0x266288 <_pcre_ord2utf+0x64f0> */
/* @0x265d50 b 0x266288 <_pcre_ord2utf+0x64f0> */
/* @0x265d54 b 0x2660d0 <_pcre_ord2utf+0x6338> */
/* @0x265d58 b 0x2662b0 <_pcre_ord2utf+0x6518> */
/* @0x265d5c b 0x2660d4 <_pcre_ord2utf+0x633c> */
/* @0x265d60 b 0x2662b0 <_pcre_ord2utf+0x6518> */
/* @0x265d64 b 0x266288 <_pcre_ord2utf+0x64f0> */
/* @0x265d68 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d6c b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d70 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d74 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d78 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d7c b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d80 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d84 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d88 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d8c b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d90 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d94 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d98 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265d9c b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265da0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265da4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265da8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265dac b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265db0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265db4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265db8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265dbc b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265dc0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265dc4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265dc8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265dcc b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265dd0 b 0x26607c <_pcre_ord2utf+0x62e4> */
/* @0x265dd4 b 0x26607c <_pcre_ord2utf+0x62e4> */
/* @0x265dd8 b 0x265f24 <_pcre_ord2utf+0x618c> */
/* @0x265ddc b 0x265f24 <_pcre_ord2utf+0x618c> */
/* @0x265de0 b 0x26607c <_pcre_ord2utf+0x62e4> */
/* @0x265de4 b 0x26607c <_pcre_ord2utf+0x62e4> */
/* @0x265de8 b 0x266078 <_pcre_ord2utf+0x62e0> */
/* @0x265dec b 0x266078 <_pcre_ord2utf+0x62e0> */
/* @0x265df0 b 0x265f1c <_pcre_ord2utf+0x6184> */
/* @0x265df4 b 0x26607c <_pcre_ord2utf+0x62e4> */
/* @0x265df8 b 0x265f24 <_pcre_ord2utf+0x618c> */
/* @0x265dfc b 0x26607c <_pcre_ord2utf+0x62e4> */
/* @0x265e00 b 0x266078 <_pcre_ord2utf+0x62e0> */
/* @0x265e04 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e08 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e0c b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e10 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e14 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e18 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e1c b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e20 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e24 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e28 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e2c b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e30 b 0x266440 <_pcre_ord2utf+0x66a8> */
/* @0x265e34 b 0x265f7c <_pcre_ord2utf+0x61e4> */
/* @0x265e38 b 0x265f48 <_pcre_ord2utf+0x61b0> */
/* @0x265e3c b 0x265f2c <_pcre_ord2utf+0x6194> */
/* @0x265e40 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265e44 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265e48 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265e4c b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265e50 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265e54 b 0x266164 <_pcre_ord2utf+0x63cc> */
/* @0x265e58 b 0x266128 <_pcre_ord2utf+0x6390> */
/* @0x265e5c b 0x2661b4 <_pcre_ord2utf+0x641c> */
/* @0x265e60 b 0x2661b4 <_pcre_ord2utf+0x641c> */
/* @0x265e64 b 0x2661b4 <_pcre_ord2utf+0x641c> */
/* @0x265e68 b 0x2661b4 <_pcre_ord2utf+0x641c> */
/* @0x265e6c b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265e70 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265e74 b 0x265f04 <_pcre_ord2utf+0x616c> */
/* @0x265e78 b 0x265f04 <_pcre_ord2utf+0x616c> */
/* @0x265e7c b 0x265f04 <_pcre_ord2utf+0x616c> */
/* @0x265e80 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265e84 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265e88 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265e8c b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265e90 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265e94 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265e98 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265e9c b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265ea0 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265ea4 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265ea8 b 0x26616c <_pcre_ord2utf+0x63d4> */
/* @0x265eac b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265eb0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265eb4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265eb8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ebc b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ec0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ec4 b 0x2661e4 <_pcre_ord2utf+0x644c> */
/* @0x265ec8 b 0x2661e4 <_pcre_ord2utf+0x644c> */
/* @0x265ecc b 0x2661e4 <_pcre_ord2utf+0x644c> */
/* @0x265ed0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ed4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ed8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265edc b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ee0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ee4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ee8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265eec b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ef0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ef4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265ef8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265efc b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265f00 b 0x2661c0 <_pcre_ord2utf+0x6428> */
/* @0x265f04 ldrb r2, [r10, #0x1] */
/* @0x265f08 ldrb r3, [r10, #0x2] */
/* @0x265f0c orr r3, r3, r2, lsl #8 */
/* @0x265f10 ldrb r3, [r10, r3]! */
/* @0x265f14 cmp r3, #119 */
/* @0x265f18 beq 0x265f04 <_pcre_ord2utf+0x616c> */
/* @0x265f1c add r10, r10, #3 */
/* @0x265f20 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x265f24 add r10, r10, #1 */
/* @0x265f28 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x265f2c ldrb r1, [r10, #0x3] */
/* @0x265f30 and r2, r1, #4 */
/* @0x265f34 ands r2, r2, #255 */
/* @0x265f38 bne 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x265f3c and r1, r1, #3 */
/* @0x265f40 cmp r1, #1 */
/* @0x265f44 beq 0x26655c <_pcre_ord2utf+0x67c4> */
/* @0x265f48 cmp r6, #0 */
/* @0x265f4c beq 0x265f74 <_pcre_ord2utf+0x61dc> */
/* @0x265f50 ldrb r3, [r4, #0x18] */
/* @0x265f54 mov r1, #255 */
/* @0x265f58 ldr r0, [sp, #0xc] */
/* @0x265f5c mov r2, #7 */
/* @0x265f60 mvn r3, r3, lsl #28 */
/* @0x265f64 mvn r3, r3, lsr #28 */
/* @0x265f68 strb r3, [r4, #0x18] */
/* @0x265f6c bl 0xb65b0 <memset@plt> */
/* @0x265f70 ldrb r3, [r10] */
/* @0x265f74 cmp r3, #112 */
/* @0x265f78 beq 0x26641c <_pcre_ord2utf+0x6684> */
/* @0x265f7c add r2, r10, #1 */
/* @0x265f80 add r10, r10, #33 */
/* @0x265f84 cmp r2, #0 */
/* @0x265f88 beq 0x265fec <_pcre_ord2utf+0x6254> */
/* @0x265f8c cmp r6, #0 */
/* @0x265f90 beq 0x2660f8 <_pcre_ord2utf+0x6360> */
/* @0x265f94 mov r1, #0 */
/* @0x265f98 ldrb r0, [r2, r1] */
/* @0x265f9c ldrb r3, [r4, r1] */
/* @0x265fa0 orr r3, r0, r3 */
/* @0x265fa4 strb r3, [r4, r1] */
/* @0x265fa8 add r1, r1, #1 */
/* @0x265fac cmp r1, #16 */
/* @0x265fb0 bne 0x265f98 <_pcre_ord2utf+0x6200> */
/* @0x265fb4 mov r3, #128 */
/* @0x265fb8 ldrb r11, [r2, r3, lsr #3] */
/* @0x265fbc and r1, r3, #7 */
/* @0x265fc0 and r12, r3, #192 */
/* @0x265fc4 ubfx r0, r3, #0x6, #0x3 */
/* @0x265fc8 asr r1, r11, r1 */
/* @0x265fcc tst r1, #1 */
/* @0x265fd0 addne r3, r12, #63 */
/* @0x265fd4 ldrbne r1, [r4, #0x18] */
/* @0x265fd8 add r3, r3, #1 */
/* @0x265fdc orrne r0, r1, r7, lsl r0 */
/* @0x265fe0 strbne r0, [r4, #0x18] */
/* @0x265fe4 cmp r3, #255 */
/* @0x265fe8 bls 0x265fb8 <_pcre_ord2utf+0x6220> */
/* @0x265fec ldrb r3, [r10] */
/* @0x265ff0 sub r3, r3, #98 */
/* @0x265ff4 uxtb r3, r3 */
/* @0x265ff8 cmp r3, #11 */
/* @0x265ffc bhi 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266000 lsl r3, r7, r3 */
/* @0x266004 movw r2, #0x533 */
/* @0x266008 and r2, r3, r2 */
/* @0x26600c cmp r2, #0 */
/* @0x266010 bne 0x265f24 <_pcre_ord2utf+0x618c> */
/* @0x266014 tst r3, #2240 */
/* @0x266018 beq 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x26601c ldrb r2, [r10, #0x1] */
/* @0x266020 ldrb r3, [r10, #0x2] */
/* @0x266024 orrs r3, r3, r2, lsl #8 */
/* @0x266028 bne 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x26602c add r10, r10, #5 */
/* @0x266030 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x266034 add r10, r10, #2 */
/* @0x266038 add r3, r5, #12 */
/* @0x26603c str r6, [sp, #0x4] */
/* @0x266040 str r3, [sp] */
/* @0x266044 add r1, r10, #1 */
/* @0x266048 mov r0, r4 */
/* @0x26604c mov r2, #0 */
/* @0x266050 add r3, r5, #4 */
/* @0x266054 bl 0x25da18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28f0> */
/* @0x266058 ldrb r2, [r8, #0x1] */
/* @0x26605c ldrb r3, [r8, #0x2] */
/* @0x266060 orr r3, r3, r2, lsl #8 */
/* @0x266064 ldrb r1, [r8, r3]! */
/* @0x266068 cmp r1, #119 */
/* @0x26606c beq 0x265c4c <_pcre_ord2utf+0x5eb4> */
/* @0x266070 ldr r0, [sp, #0x8] */
/* @0x266074 b 0x266120 <_pcre_ord2utf+0x6388> */
/* @0x266078 add r10, r10, #2 */
/* @0x26607c ldrb r3, [r10, #0x1] */
/* @0x266080 sub r3, r3, #6 */
/* @0x266084 cmp r3, #15 */
/* @0x266088 addls pc, pc, r3, lsl #2 —— 第二张 162 项 opcode 表 */
/* @0x26608c b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x266090 b 0x26644c <_pcre_ord2utf+0x66b4> */
/* @0x266094 b 0x266468 <_pcre_ord2utf+0x66d0> */
/* @0x266098 b 0x266480 <_pcre_ord2utf+0x66e8> */
/* @0x26609c b 0x266498 <_pcre_ord2utf+0x6700> */
/* @0x2660a0 b 0x2664b0 <_pcre_ord2utf+0x6718> */
/* @0x2660a4 b 0x2664c8 <_pcre_ord2utf+0x6730> */
/* @0x2660a8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x2660ac b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x2660b0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x2660b4 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x2660b8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x2660bc b 0x2664e0 <_pcre_ord2utf+0x6748> */
/* @0x2660c0 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x2660c4 b 0x266518 <_pcre_ord2utf+0x6780> */
/* @0x2660c8 b 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x2660cc b 0x2664e0 <_pcre_ord2utf+0x6748> */
/* @0x2660d0 add r10, r10, #2 */
/* @0x2660d4 add r3, r5, #12 */
/* @0x2660d8 str r6, [sp, #0x4] */
/* @0x2660dc str r3, [sp] */
/* @0x2660e0 add r1, r10, #1 */
/* @0x2660e4 mov r0, r4 */
/* @0x2660e8 mov r2, #1 */
/* @0x2660ec add r3, r5, #4 */
/* @0x2660f0 bl 0x25da18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28f0> */
/* @0x2660f4 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x2660f8 mov r12, r6 */
/* @0x2660fc ldrb r1, [r2, r12] */
/* @0x266100 ldrb r3, [r4, r12] */
/* @0x266104 orr r3, r1, r3 */
/* @0x266108 strb r3, [r4, r12] */
/* @0x26610c add r12, r12, #1 */
/* @0x266110 cmp r12, #32 */
/* @0x266114 bne 0x2660fc <_pcre_ord2utf+0x6364> */
/* @0x266118 b 0x265fec <_pcre_ord2utf+0x6254> */
/* @0x26611c mov r0, #0 */
/* @0x266120 add sp, sp, #28 */
/* @0x266124 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1 */
/* @0x266128 mov r3, #2 */
/* @0x26612c str r3, [sp, #0x8] */
/* @0x266130 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266134 mov r0, r4 */
/* @0x266138 mov r1, #64 */
/* @0x26613c mov r2, r9 */
/* @0x266140 add r3, r5, #8 */
/* @0x266144 bl 0x265b58 <_pcre_ord2utf+0x5dc0> */
/* @0x266148 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x26614c mov r0, r4 */
/* @0x266150 mov r1, #64 */
/* @0x266154 mov r2, r9 */
/* @0x266158 add r3, r5, #8 */
/* @0x26615c bl 0x25dad0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29a8> */
/* @0x266160 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266164 add r10, r10, #6 */
/* @0x266168 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x26616c mov r0, r10 */
/* @0x266170 mov r1, r4 */
/* @0x266174 mov r2, r6 */
/* @0x266178 mov r3, r5 */
/* @0x26617c bl 0x265c10 <_pcre_ord2utf+0x5e78> */
/* @0x266180 cmp r0, #0 */
/* @0x266184 cmpne r0, #3 */
/* @0x266188 beq 0x266120 <_pcre_ord2utf+0x6388> */
/* @0x26618c cmp r0, #1 */
/* @0x266190 beq 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266194 ldrb r2, [r10, #0x1] */
/* @0x266198 ldrb r3, [r10, #0x2] */
/* @0x26619c orr r3, r3, r2, lsl #8 */
/* @0x2661a0 ldrb r3, [r10, r3]! */
/* @0x2661a4 cmp r3, #119 */
/* @0x2661a8 beq 0x266194 <_pcre_ord2utf+0x63fc> */
/* @0x2661ac add r10, r10, #3 */
/* @0x2661b0 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x2661b4 mov r0, #2 */
/* @0x2661b8 add sp, sp, #28 */
/* @0x2661bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2 */
/* @0x2661c0 add r10, r10, #1 */
/* @0x2661c4 ldrb r2, [r10, #0x1] */
/* @0x2661c8 ldrb r3, [r10, #0x2] */
/* @0x2661cc orr r3, r3, r2, lsl #8 */
/* @0x2661d0 ldrb r3, [r10, r3]! */
/* @0x2661d4 cmp r3, #119 */
/* @0x2661d8 beq 0x2661c4 <_pcre_ord2utf+0x642c> */
/* @0x2661dc add r10, r10, #3 */
/* @0x2661e0 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x2661e4 add r10, r10, #1 */
/* @0x2661e8 mov r1, r4 */
/* @0x2661ec mov r2, r6 */
/* @0x2661f0 mov r3, r5 */
/* @0x2661f4 mov r0, r10 */
/* @0x2661f8 bl 0x265c10 <_pcre_ord2utf+0x5e78> */
/* @0x2661fc cmp r0, #0 */
/* @0x266200 cmpne r0, #3 */
/* @0x266204 beq 0x266120 <_pcre_ord2utf+0x6388> */
/* @0x266208 ldrb r2, [r10, #0x1] */
/* @0x26620c ldrb r3, [r10, #0x2] */
/* @0x266210 orr r3, r3, r2, lsl #8 */
/* @0x266214 ldrb r3, [r10, r3]! */
/* @0x266218 cmp r3, #119 */
/* @0x26621c beq 0x266208 <_pcre_ord2utf+0x6470> */
/* @0x266220 add r10, r10, #3 */
/* @0x266224 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x266228 mov r0, r4 */
/* @0x26622c mov r1, #160 */
/* @0x266230 mov r2, r9 */
/* @0x266234 add r3, r5, #8 */
/* @0x266238 bl 0x265b58 <_pcre_ord2utf+0x5dc0> */
/* @0x26623c b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266240 mov r0, r4 */
/* @0x266244 mov r1, #160 */
/* @0x266248 mov r2, r9 */
/* @0x26624c add r3, r5, #8 */
/* @0x266250 bl 0x25dad0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29a8> */
/* @0x266254 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266258 mov r0, r4 */
/* @0x26625c mov r1, #0 */
/* @0x266260 mov r2, r9 */
/* @0x266264 add r3, r5, #8 */
/* @0x266268 bl 0x265b58 <_pcre_ord2utf+0x5dc0> */
/* @0x26626c b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266270 mov r0, r4 */
/* @0x266274 mov r1, #0 */
/* @0x266278 mov r2, r9 */
/* @0x26627c add r3, r5, #8 */
/* @0x266280 bl 0x25dad0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29a8> */
/* @0x266284 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266288 add r1, r10, #3 */
/* @0x26628c str r6, [sp, #0x4] */
/* @0x266290 add r3, r5, #12 */
/* @0x266294 mov r0, r4 */
/* @0x266298 str r3, [sp] */
/* @0x26629c mov r2, #1 */
/* @0x2662a0 add r3, r5, #4 */
/* @0x2662a4 bl 0x25da18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28f0> */
/* @0x2662a8 mov r10, r0 */
/* @0x2662ac b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x2662b0 str r6, [sp, #0x4] */
/* @0x2662b4 add r1, r10, #1 */
/* @0x2662b8 b 0x266290 <_pcre_ord2utf+0x64f8> */
/* @0x2662bc add r1, r10, #3 */
/* @0x2662c0 str r6, [sp, #0x4] */
/* @0x2662c4 add r3, r5, #12 */
/* @0x2662c8 mov r0, r4 */
/* @0x2662cc str r3, [sp] */
/* @0x2662d0 mov r2, #0 */
/* @0x2662d4 add r3, r5, #4 */
/* @0x2662d8 bl 0x25da18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28f0> */
/* @0x2662dc mov r10, r0 */
/* @0x2662e0 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x2662e4 str r6, [sp, #0x4] */
/* @0x2662e8 add r1, r10, #1 */
/* @0x2662ec b 0x2662c4 <_pcre_ord2utf+0x652c> */
/* @0x2662f0 cmp r6, #0 */
/* @0x2662f4 ldrb r2, [r4, #0x1] */
/* @0x2662f8 ldrb r3, [r4, #0x4] */
/* @0x2662fc orr r2, r2, #2 */
/* @0x266300 strb r2, [r4, #0x1] */
/* @0x266304 orr r3, r3, #1 */
/* @0x266308 ldrbne r2, [r4, #0x18] */
/* @0x26630c strb r3, [r4, #0x4] */
/* @0x266310 ldrbne r3, [r4, #0x1c] */
/* @0x266314 orrne r2, r2, #4 */
/* @0x266318 ldrbeq r3, [r4, #0x14] */
/* @0x26631c orrne r3, r3, #14 */
/* @0x266320 strbne r2, [r4, #0x18] */
/* @0x266324 orreq r3, r3, #1 */
/* @0x266328 strbne r3, [r4, #0x1c] */
/* @0x26632c strbeq r3, [r4, #0x14] */
/* @0x266330 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x266334 cmp r6, #0 */
/* @0x266338 ldrb r3, [r4, #0x1] */
/* @0x26633c ldrbne r2, [r4, #0x18] */
/* @0x266340 orr r3, r3, #60 */
/* @0x266344 strb r3, [r4, #0x1] */
/* @0x266348 ldrbne r3, [r4, #0x1c] */
/* @0x26634c orrne r2, r2, #4 */
/* @0x266350 ldrbeq r3, [r4, #0x10] */
/* @0x266354 orrne r3, r3, #4 */
/* @0x266358 strbne r2, [r4, #0x18] */
/* @0x26635c orreq r3, r3, #32 */
/* @0x266360 strbne r3, [r4, #0x1c] */
/* @0x266364 strbeq r3, [r4, #0x10] */
/* @0x266368 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x26636c ldrb r3, [r10, #0x1] */
/* @0x266370 cmp r3, #9 */
/* @0x266374 bne 0x26611c <_pcre_ord2utf+0x6384> */
/* @0x266378 ldrb r10, [r10, #0x2] */
/* @0x26637c cmp r6, #0 */
/* @0x266380 ldr r3, [pc, #0x1dc] */
/* @0x266384 addne r11, sp, #16 */
/* @0x266388 ldr r3, [pc, r3] */
/* @0x26638c add r10, r3, r10, lsl #2 */
/* @0x266390 bne 0x2663e0 <_pcre_ord2utf+0x6648> */
/* @0x266394 ldr r3, [r10], #4 */
/* @0x266398 cmn r3, #1 */
/* @0x26639c beq 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x2663a0 cmp r3, #255 */
/* @0x2663a4 bls 0x2663cc <_pcre_ord2utf+0x6634> */
/* @0x2663a8 ldrb r3, [r4, #0x1f] */
/* @0x2663ac mvn r3, r3, lsl #25 */
/* @0x2663b0 mvn r3, r3, lsr #25 */
/* @0x2663b4 strb r3, [r4, #0x1f] */
/* @0x2663b8 ldr r3, [r10], #4 */
/* @0x2663bc cmn r3, #1 */
/* @0x2663c0 beq 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x2663c4 cmp r3, #255 */
/* @0x2663c8 bhi 0x2663a8 <_pcre_ord2utf+0x6610> */
/* @0x2663cc ldrb r2, [r4, r3, lsr #3] */
/* @0x2663d0 and r1, r3, #7 */
/* @0x2663d4 orr r2, r2, r7, lsl r1 */
/* @0x2663d8 strb r2, [r4, r3, lsr #3] */
/* @0x2663dc b 0x266394 <_pcre_ord2utf+0x65fc> */
/* @0x2663e0 ldr r0, [r10], #4 */
/* @0x2663e4 mov r1, r11 */
/* @0x2663e8 cmn r0, #1 */
/* @0x2663ec beq 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x2663f0 bl 0x25fd98 <_pcre_ord2utf> */
/* @0x2663f4 ldrb r3, [sp, #0x10] */
/* @0x2663f8 and r1, r3, #7 */
/* @0x2663fc ldrb r2, [r4, r3, lsr #3] */
/* @0x266400 orr r2, r2, r7, lsl r1 */
/* @0x266404 strb r2, [r4, r3, lsr #3] */
/* @0x266408 ldr r0, [r10], #4 */
/* @0x26640c mov r1, r11 */
/* @0x266410 cmn r0, #1 */
/* @0x266414 bne 0x2663f0 <_pcre_ord2utf+0x6658> */
/* @0x266418 b 0x266058 <_pcre_ord2utf+0x62c0> */
/* @0x26641c ldrb r2, [r10, #0x3] */
/* @0x266420 ldrb r1, [r10, #0x1] */
/* @0x266424 ldrb r3, [r10, #0x2] */
/* @0x266428 and r2, r2, #2 */
/* @0x26642c ands r2, r2, #255 */
/* @0x266430 orr r3, r3, r1, lsl #8 */
/* @0x266434 addne r2, r10, #4 */
/* @0x266438 add r10, r10, r3 */
/* @0x26643c b 0x265f84 <_pcre_ord2utf+0x61ec> */
/* @0x266440 mov r0, #3 */
/* @0x266444 add sp, sp, #28 */
/* @0x266448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 3 */
/* @0x26644c mov r0, r4 */
/* @0x266450 mov r1, #64 */
/* @0x266454 mov r2, r9 */
/* @0x266458 add r3, r5, #8 */
/* @0x26645c bl 0x25dad0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29a8> */
/* @0x266460 add r10, r10, #2 */
/* @0x266464 b 0x265c6c <_pcre_ord2utf+0x5ed4> */
/* @0x266468 mov r0, r4 */
/* @0x26646c mov r1, #64 */
/* @0x266470 mov r2, r9 */
/* @0x266474 add r3, r5, #8 */
/* @0x266478 bl 0x265b58 <_pcre_ord2utf+0x5dc0> */
/* @0x26647c b 0x266460 <_pcre_ord2utf+0x66c8> */
/* @0x266480 mov r0, r4 */
/* @0x266484 mov r1, #0 */
/* @0x266488 mov r2, r9 */
/* @0x26648c add r3, r5, #8 */
/* @0x266490 bl 0x25dad0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29a8> */
/* @0x266494 b 0x266460 <_pcre_ord2utf+0x66c8> */
/* @0x266498 mov r0, r4 */
/* @0x26649c mov r1, #0 */
/* @0x2664a0 mov r2, r9 */
/* @0x2664a4 add r3, r5, #8 */
/* @0x2664a8 bl 0x265b58 <_pcre_ord2utf+0x5dc0> */
/* @0x2664ac b 0x266460 <_pcre_ord2utf+0x66c8> */
/* @0x2664b0 mov r0, r4 */
/* @0x2664b4 mov r1, #160 */
/* @0x2664b8 mov r2, r9 */
/* @0x2664bc add r3, r5, #8 */
/* @0x2664c0 bl 0x25dad0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29a8> */
/* @0x2664c4 b 0x266460 <_pcre_ord2utf+0x66c8> */
/* @0x2664c8 mov r0, r4 */
/* @0x2664cc mov r1, #160 */
/* @0x2664d0 mov r2, r9 */
/* @0x2664d4 add r3, r5, #8 */
/* @0x2664d8 bl 0x265b58 <_pcre_ord2utf+0x5dc0> */
/* @0x2664dc b 0x266460 <_pcre_ord2utf+0x66c8> */
/* @0x2664e0 cmp r6, #0 */
/* @0x2664e4 ldrb r3, [r4, #0x1] */
/* @0x2664e8 ldrbne r2, [r4, #0x18] */
/* @0x2664ec orr r3, r3, #60 */
/* @0x2664f0 strb r3, [r4, #0x1] */
/* @0x2664f4 ldrbne r3, [r4, #0x1c] */
/* @0x2664f8 orrne r2, r2, #4 */
/* @0x2664fc ldrbeq r3, [r4, #0x10] */
/* @0x266500 orrne r3, r3, #4 */
/* @0x266504 strbne r2, [r4, #0x18] */
/* @0x266508 orreq r3, r3, #32 */
/* @0x26650c strbne r3, [r4, #0x1c] */
/* @0x266510 strbeq r3, [r4, #0x10] */
/* @0x266514 b 0x266460 <_pcre_ord2utf+0x66c8> */
/* @0x266518 cmp r6, #0 */
/* @0x26651c ldrb r2, [r4, #0x1] */
/* @0x266520 ldrb r3, [r4, #0x4] */
/* @0x266524 orr r2, r2, #2 */
/* @0x266528 strb r2, [r4, #0x1] */
/* @0x26652c orr r3, r3, #1 */
/* @0x266530 ldrbne r2, [r4, #0x18] */
/* @0x266534 strb r3, [r4, #0x4] */
/* @0x266538 ldrbne r3, [r4, #0x1c] */
/* @0x26653c orrne r2, r2, #4 */
/* @0x266540 ldrbeq r3, [r4, #0x14] */
/* @0x266544 orrne r3, r3, #14 */
/* @0x266548 strbne r2, [r4, #0x18] */
/* @0x26654c orreq r3, r3, #1 */
/* @0x266550 strbne r3, [r4, #0x1c] */
/* @0x266554 strbeq r3, [r4, #0x14] */
/* @0x266558 b 0x266460 <_pcre_ord2utf+0x66c8> */
/* @0x26655c mov r0, r2 */
/* @0x266560 b 0x266120 <_pcre_ord2utf+0x6388> —— 尾跳回主循环（0x266120） */


/* ═══════════════════════════════════════════════════════════════════════
 * §7  anon_222040  0x222040..0x2225c8  1,416 B / 354 条  in-degree 2
 * freealut（OpenAL Utility Toolkit）的 WAV(RIFF)/AU(.snd) 载入器
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 = freealut 的 InputStream*（0x222048 存 r4，之后每个 *_alutInputStream* 调用都传 r4）。
 *
 * 身份证据（三条，互相独立）
 *   ① 4CC 魔数（全部在段内，逐条可比）：
 *      0x22210c movw r3,#0x4646 + 0x222110 movt r3,#0x5249 ⇒ 0x52494646 = "RIFF"，
 *        0x222114 cmp r2,r3 后 beq 走 RIFF 分支；
 *      0x22211c/0x222120 ⇒ 0x2e736e64 = ".snd"（Sun/NeXT AU 魔数），0x222124 cmp 后 bne 报错；
 *      0x2222e8/0x2222ec ⇒ 0x57415645 = "WAVE"，0x2222f0 cmp；
 *      0x222304..0x222314 ⇒ 0x666d7420 = "fmt " 与 0x64617461 = "data"，用于逐 chunk 扫描。
 *   ② 调用面全是 freealut 的 InputStream 层具名件：_alutInputStreamReadInt32BE(0x221f54) ×8、
 *      ReadUInt32LE(0x221fa4) ×4、ReadUInt16LE(0x221f1c) ×4、Skip(0x221ec8) ×4、
 *      Read(0x221e78) ×2、GetRemainingLength(0x221e20) ×2、EOF(0x221e28) ×1、
 *      GetFileName(0x221e18) ×1；再加 _alutSetError(0x221940) ×3（错误码）、
 *      _alutCodecLinear(0x221508) ×1（PCM codec）、_alutInputGetData(0x221dc4) ×1。
 *   ③ 调用者：_alutCreateBufferFromInputStream+0xc（0x2225d8）与
 *      _alutLoadMemoryFromInputStream+0x1c（0x222680）—— 两条公共入口都先 bl 本段，符合
 *      "先从流里认出容器格式再解码"的位置。
 *
 * 形态：0x22204c 先 _alutInputStreamGetFileName 取文件名；0x22210c 起比 4CC；RIFF 分支在
 *       0x2222b4 读 "WAVE"，再按 chunk 读 "fmt "/"data"；0x2221e8 有一个 addls pc,pc,r3,lsl #2
 *       的 switch（按 chunk/状态分派），表体在段内。
 * 出口：2 个 pop {r4..r11,pc}（0x22226c / 0x2222b0）；窗口内 0 条分支跳出。
 * 边界：0x2225b8..0x2225c4 是 4 个 GOT 相对池字（0xfffff7f8 / f7fc / f800 / f804），非指令。
 * open：1. freealut 里该静态例程的原名未证（alutLoader.c 的 loadWAV / loadAU 之一）。
 *       2. AU 分支的样本格式（8/16 位、单/双声道）未逐条读。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x222040 0x2225c8 anon_222040 freealut_wav_au_loader */

/* @0x222040 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（9 寄存器 + 68 B 帧） */
/* @0x222044 sub sp, sp, #68 */
/* @0x222048 mov r4, r0 */
/* @0x22204c bl 0x221e18 <_alutInputStreamGetFileName> —— 先取文件名（_alutInputStreamGetFileName） */
/* @0x222050 ldr r5, [pc, #0x550] */
/* @0x222054 add r5, pc, r5 */
/* @0x222058 cmp r0, #0 */
/* @0x22205c beq 0x2220f4 <_alutInputStreamReadUInt32LE+0x150> */
/* @0x222060 ldrb r2, [r0] */
/* @0x222064 cmp r2, #0 */
/* @0x222068 beq 0x2223c0 <_alutInputStreamReadUInt32LE+0x41c> */
/* @0x22206c add r2, r0, #1 */
/* @0x222070 mov r3, r2 */
/* @0x222074 add r2, r2, #1 */
/* @0x222078 ldrb r1, [r3] */
/* @0x22207c cmp r1, #0 */
/* @0x222080 bne 0x222070 <_alutInputStreamReadUInt32LE+0xcc> */
/* @0x222084 rsb lr, r0, r3 */
/* @0x222088 ldr r2, [pc, #0x51c] */
/* @0x22208c add r2, pc, r2 */
/* @0x222090 add r2, r2, #1 */
/* @0x222094 mov r1, r2 */
/* @0x222098 add r2, r2, #1 */
/* @0x22209c ldrb r0, [r1] */
/* @0x2220a0 cmp r0, #0 */
/* @0x2220a4 bne 0x222094 <_alutInputStreamReadUInt32LE+0xf0> */
/* @0x2220a8 ldr r12, [pc, #0x500] */
/* @0x2220ac add r12, pc, r12 */
/* @0x2220b0 rsb r12, r12, r1 */
/* @0x2220b4 cmp r12, lr */
/* @0x2220b8 bgt 0x2220f4 <_alutInputStreamReadUInt32LE+0x150> */
/* @0x2220bc ldr r9, [pc, #0x4f0] */
/* @0x2220c0 mov r6, r1 */
/* @0x2220c4 mov r7, r3 */
/* @0x2220c8 add r9, pc, r9 */
/* @0x2220cc b 0x2220d8 <_alutInputStreamReadUInt32LE+0x134> */
/* @0x2220d0 cmp r6, r9 */
/* @0x2220d4 beq 0x222270 <_alutInputStreamReadUInt32LE+0x2cc> */
/* @0x2220d8 ldrb r0, [r6, #-0x1]! */
/* @0x2220dc bl 0x221ff4 <_alutInputStreamReadUInt32LE+0x50> */
/* @0x2220e0 mov r8, r0 */
/* @0x2220e4 ldrb r0, [r7, #-0x1]! */
/* @0x2220e8 bl 0x221ff4 <_alutInputStreamReadUInt32LE+0x50> */
/* @0x2220ec cmp r8, r0 */
/* @0x2220f0 beq 0x2220d0 <_alutInputStreamReadUInt32LE+0x12c> */
/* @0x2220f4 mov r0, r4 */
/* @0x2220f8 add r1, sp, #40 */
/* @0x2220fc bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222100 cmp r0, #0 */
/* @0x222104 beq 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x222108 ldr r2, [sp, #0x28] */
/* @0x22210c movw r3, #0x4646 —— movw 0x4646 … */
/* @0x222110 movt r3, #0x5249 —— … movt 0x5249 ⇒ 0x52494646 = "RIFF" */
/* @0x222114 cmp r2, r3 —— 与读到的 4CC 比较 */
/* @0x222118 beq 0x2222b4 <_alutInputStreamReadUInt32LE+0x310> */
/* @0x22211c movw r3, #0x6e64 —— movw 0x6e64 … */
/* @0x222120 movt r3, #0x2e73 —— … movt 0x2e73 ⇒ 0x2e736e64 = ".snd"（AU） */
/* @0x222124 cmp r2, r3 */
/* @0x222128 bne 0x22225c <_alutInputStreamReadUInt32LE+0x2b8> */
/* @0x22212c mov r0, r4 */
/* @0x222130 add r1, sp, #44 */
/* @0x222134 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222138 cmp r0, #0 */
/* @0x22213c beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222140 mov r0, r4 */
/* @0x222144 add r1, sp, #48 */
/* @0x222148 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x22214c cmp r0, #0 */
/* @0x222150 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222154 mov r0, r4 */
/* @0x222158 add r1, sp, #52 */
/* @0x22215c bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222160 cmp r0, #0 */
/* @0x222164 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222168 mov r0, r4 */
/* @0x22216c add r1, sp, #56 */
/* @0x222170 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222174 cmp r0, #0 */
/* @0x222178 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x22217c mov r0, r4 */
/* @0x222180 add r1, sp, #60 */
/* @0x222184 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222188 cmp r0, #0 */
/* @0x22218c beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222190 ldr r6, [sp, #0x30] */
/* @0x222194 cmn r6, #1 */
/* @0x222198 ldrne r1, [sp, #0x2c] */
/* @0x22219c beq 0x222530 <_alutInputStreamReadUInt32LE+0x58c> */
/* @0x2221a0 cmp r1, #23 */
/* @0x2221a4 ble 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x2221a8 cmp r6, #0 */
/* @0x2221ac beq 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x2221b0 ldr r3, [sp, #0x38] */
/* @0x2221b4 cmp r3, #0 */
/* @0x2221b8 ble 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x2221bc ldr r3, [sp, #0x3c] */
/* @0x2221c0 cmp r3, #0 */
/* @0x2221c4 ble 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x2221c8 sub r1, r1, #24 */
/* @0x2221cc mov r0, r4 */
/* @0x2221d0 bl 0x221ec8 <_alutInputStreamSkip> */
/* @0x2221d4 cmp r0, #0 */
/* @0x2221d8 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2221dc ldr r3, [sp, #0x34] */
/* @0x2221e0 sub r3, r3, #1 */
/* @0x2221e4 cmp r3, #26 */
/* @0x2221e8 addls pc, pc, r3, lsl #2 —— chunk/状态 switch 表 */
/* @0x2221ec b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x2221f0 b 0x22242c <_alutInputStreamReadUInt32LE+0x488> */
/* @0x2221f4 b 0x2223cc <_alutInputStreamReadUInt32LE+0x428> */
/* @0x2221f8 b 0x22240c <_alutInputStreamReadUInt32LE+0x468> */
/* @0x2221fc b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222200 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222204 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222208 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22220c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222210 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222214 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222218 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22221c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222220 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222224 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222228 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22222c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222230 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222234 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222238 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22223c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222240 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222244 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222248 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22224c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222250 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222254 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222258 b 0x22241c <_alutInputStreamReadUInt32LE+0x478> */
/* @0x22225c movw r0, #0x20f */
/* @0x222260 bl 0x221940 <_alutSetError> */
/* @0x222264 mov r0, #0 */
/* @0x222268 add sp, sp, #68 */
/* @0x22226c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1 */
/* @0x222270 mov r0, r4 */
/* @0x222274 bl 0x221e20 <_alutInputStreamGetRemainingLength> */
/* @0x222278 mov r5, r0 */
/* @0x22227c mov r0, r4 */
/* @0x222280 mov r1, r5 */
/* @0x222284 bl 0x221e78 <_alutInputStreamRead> */
/* @0x222288 subs r3, r0, #0 */
/* @0x22228c beq 0x222560 <_alutInputStreamReadUInt32LE+0x5bc> */
/* @0x222290 mov r1, r5 */
/* @0x222294 mov r2, #1 */
/* @0x222298 mov r3, #0 */
/* @0x22229c movt r3, #0x45fa */
/* @0x2222a0 str r3, [sp] */
/* @0x2222a4 mov r3, #8 */
/* @0x2222a8 bl 0x221508 <_alutCodecLinear> */
/* @0x2222ac add sp, sp, #68 */
/* @0x2222b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2 */
/* @0x2222b4 add r6, sp, #48 */
/* @0x2222b8 mov r0, r4 */
/* @0x2222bc mov r1, r6 */
/* @0x2222c0 bl 0x221fa4 <_alutInputStreamReadUInt32LE> */
/* @0x2222c4 cmp r0, #0 */
/* @0x2222c8 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2222cc add r7, sp, #52 */
/* @0x2222d0 mov r0, r4 */
/* @0x2222d4 mov r1, r7 */
/* @0x2222d8 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x2222dc cmp r0, #0 */
/* @0x2222e0 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2222e4 ldr r2, [sp, #0x34] */
/* @0x2222e8 movw r3, #0x5645 —— movw 0x5645 … */
/* @0x2222ec movt r3, #0x5741 —— … movt 0x5741 ⇒ 0x57415645 = "WAVE" */
/* @0x2222f0 cmp r2, r3 */
/* @0x2222f4 bne 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x2222f8 ldr r3, [pc, #0x2b8] */
/* @0x2222fc mov r2, #0 */
/* @0x222300 str r2, [sp, #0x18] */
/* @0x222304 movw r8, #0x7420 —— "fmt "（0x666d7420） */
/* @0x222308 movw r9, #0x7461 —— "data"（0x64617461）的低半 */
/* @0x22230c movt r8, #0x666d */
/* @0x222310 ldr r3, [r5, r3] */
/* @0x222314 movt r9, #0x6461 */
/* @0x222318 add r11, sp, #34 */
/* @0x22231c add r10, sp, #36 */
/* @0x222320 add r12, sp, #60 */
/* @0x222324 str r12, [sp, #0x14] */
/* @0x222328 str r3, [sp, #0xc] */
/* @0x22232c add r3, sp, #56 */
/* @0x222330 ldr r2, [sp, #0xc] */
/* @0x222334 str r3, [sp, #0x10] */
/* @0x222338 str r2, [sp, #0x1c] */
/* @0x22233c mov r0, r4 */
/* @0x222340 mov r1, r7 */
/* @0x222344 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222348 cmp r0, #0 */
/* @0x22234c beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222350 mov r0, r4 */
/* @0x222354 mov r1, r6 */
/* @0x222358 bl 0x221fa4 <_alutInputStreamReadUInt32LE> */
/* @0x22235c cmp r0, #0 */
/* @0x222360 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222364 ldr r3, [sp, #0x34] */
/* @0x222368 cmp r3, r8 */
/* @0x22236c beq 0x22244c <_alutInputStreamReadUInt32LE+0x4a8> */
/* @0x222370 cmp r3, r9 */
/* @0x222374 beq 0x222568 <_alutInputStreamReadUInt32LE+0x5c4> */
/* @0x222378 mov r0, r4 */
/* @0x22237c ldr r1, [sp, #0x30] */
/* @0x222380 bl 0x221ec8 <_alutInputStreamSkip> */
/* @0x222384 cmp r0, #0 */
/* @0x222388 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x22238c ldr r3, [sp, #0x30] */
/* @0x222390 tst r3, #1 */
/* @0x222394 beq 0x22233c <_alutInputStreamReadUInt32LE+0x398> */
/* @0x222398 mov r0, r4 */
/* @0x22239c bl 0x221e28 <_alutInputStreamEOF> */
/* @0x2223a0 cmp r0, #0 */
/* @0x2223a4 bne 0x22233c <_alutInputStreamReadUInt32LE+0x398> */
/* @0x2223a8 mov r0, r4 */
/* @0x2223ac mov r1, #1 */
/* @0x2223b0 bl 0x221ec8 <_alutInputStreamSkip> */
/* @0x2223b4 cmp r0, #0 */
/* @0x2223b8 bne 0x22233c <_alutInputStreamReadUInt32LE+0x398> */
/* @0x2223bc b 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2223c0 mov r3, r0 */
/* @0x2223c4 mov lr, r2 */
/* @0x2223c8 b 0x222088 <_alutInputStreamReadUInt32LE+0xe4> */
/* @0x2223cc ldr r3, [pc, #0x1e8] */
/* @0x2223d0 mov r7, #8 */
/* @0x2223d4 ldr r5, [r5, r3] */
/* @0x2223d8 mov r0, r4 */
/* @0x2223dc mov r1, r6 */
/* @0x2223e0 bl 0x221e78 <_alutInputStreamRead> */
/* @0x2223e4 cmp r0, #0 */
/* @0x2223e8 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2223ec vldr s14, [sp, #56] */
/* @0x2223f0 vcvt.f32.s32 s15, s14 */
/* @0x2223f4 mov r1, r6 */
/* @0x2223f8 ldr r2, [sp, #0x3c] */
/* @0x2223fc mov r3, r7 */
/* @0x222400 vstr s15, [sp] */
/* @0x222404 blx r5 */
/* @0x222408 b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x22240c ldr r3, [pc, #0x1ac] */
/* @0x222410 mov r7, #16 */
/* @0x222414 ldr r5, [r5, r3] */
/* @0x222418 b 0x2223d8 <_alutInputStreamReadUInt32LE+0x434> */
/* @0x22241c ldr r3, [pc, #0x1a0] */
/* @0x222420 mov r7, #16 */
/* @0x222424 ldr r5, [r5, r3] */
/* @0x222428 b 0x2223d8 <_alutInputStreamReadUInt32LE+0x434> */
/* @0x22242c ldr r3, [pc, #0x194] */
/* @0x222430 mov r7, #16 */
/* @0x222434 ldr r5, [r5, r3] */
/* @0x222438 b 0x2223d8 <_alutInputStreamReadUInt32LE+0x434> */
/* @0x22243c mov r0, #528 */
/* @0x222440 bl 0x221940 <_alutSetError> */
/* @0x222444 mov r0, #0 */
/* @0x222448 b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x22244c ldr r3, [sp, #0x30] */
/* @0x222450 cmp r3, #15 */
/* @0x222454 bls 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x222458 mov r0, r4 */
/* @0x22245c mov r1, r11 */
/* @0x222460 bl 0x221f1c <_alutInputStreamReadUInt16LE> */
/* @0x222464 cmp r0, #0 */
/* @0x222468 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x22246c mov r0, r4 */
/* @0x222470 mov r1, r10 */
/* @0x222474 bl 0x221f1c <_alutInputStreamReadUInt16LE> */
/* @0x222478 cmp r0, #0 */
/* @0x22247c beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222480 mov r0, r4 */
/* @0x222484 add r1, sp, #56 */
/* @0x222488 bl 0x221fa4 <_alutInputStreamReadUInt32LE> */
/* @0x22248c cmp r0, #0 */
/* @0x222490 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222494 mov r0, r4 */
/* @0x222498 add r1, sp, #60 */
/* @0x22249c bl 0x221fa4 <_alutInputStreamReadUInt32LE> */
/* @0x2224a0 cmp r0, #0 */
/* @0x2224a4 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2224a8 mov r0, r4 */
/* @0x2224ac add r1, sp, #38 */
/* @0x2224b0 bl 0x221f1c <_alutInputStreamReadUInt16LE> */
/* @0x2224b4 cmp r0, #0 */
/* @0x2224b8 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2224bc mov r0, r4 */
/* @0x2224c0 add r1, sp, #44 */
/* @0x2224c4 bl 0x221f1c <_alutInputStreamReadUInt16LE> */
/* @0x2224c8 cmp r0, #0 */
/* @0x2224cc beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2224d0 ldr r1, [sp, #0x30] */
/* @0x2224d4 mov r0, r4 */
/* @0x2224d8 sub r1, r1, #16 */
/* @0x2224dc bl 0x221ec8 <_alutInputStreamSkip> */
/* @0x2224e0 cmp r0, #0 */
/* @0x2224e4 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2224e8 ldrh r3, [sp, #34] */
/* @0x2224ec cmp r3, #1 */
/* @0x2224f0 beq 0x222550 <_alutInputStreamReadUInt32LE+0x5ac> */
/* @0x2224f4 cmp r3, #7 */
/* @0x2224f8 bne 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x2224fc ldrh r2, [sp, #44] */
/* @0x222500 mov r3, #1 */
/* @0x222504 str r3, [sp, #0x18] */
/* @0x222508 ldr r3, [pc, #0xb8] */
/* @0x22250c lsl r2, r2, #1 */
/* @0x222510 strh r2, [sp, #44] */
/* @0x222514 ldr r3, [r5, r3] */
/* @0x222518 str r3, [sp, #0x1c] */
/* @0x22251c b 0x22238c <_alutInputStreamReadUInt32LE+0x3e8> */
/* @0x222520 movw r0, #0x211 */
/* @0x222524 bl 0x221940 <_alutSetError> */
/* @0x222528 mov r0, #0 */
/* @0x22252c b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x222530 mov r0, r4 */
/* @0x222534 movw r6, #0xffe8 */
/* @0x222538 bl 0x221e20 <_alutInputStreamGetRemainingLength> */
/* @0x22253c ldr r1, [sp, #0x2c] */
/* @0x222540 movt r6, #0xffff */
/* @0x222544 rsb r6, r1, r6 */
/* @0x222548 add r6, r6, r0 */
/* @0x22254c b 0x2221a0 <_alutInputStreamReadUInt32LE+0x1fc> */
/* @0x222550 ldr r2, [sp, #0xc] */
/* @0x222554 str r3, [sp, #0x18] */
/* @0x222558 str r2, [sp, #0x1c] */
/* @0x22255c b 0x22238c <_alutInputStreamReadUInt32LE+0x3e8> */
/* @0x222560 mov r0, r3 */
/* @0x222564 b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x222568 ldr r12, [sp, #0x18] */
/* @0x22256c cmp r12, #0 */
/* @0x222570 beq 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x222574 mov r0, r4 */
/* @0x222578 bl 0x221dc4 <_alutInputGetData> */
/* @0x22257c cmp r0, #0 */
/* @0x222580 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222584 vldr s14, [sp, #56] */
/* @0x222588 vcvt.f32.u32 s15, s14 */
/* @0x22258c ldr r1, [sp, #0x30] */
/* @0x222590 ldrh r2, [sp, #36] */
/* @0x222594 ldrh r3, [sp, #44] */
/* @0x222598 ldr r12, [sp, #0x1c] */
/* @0x22259c vstr s15, [sp] */
/* @0x2225a0 blx r12 */
/* @0x2225a4 b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x2225a8 ldrsheq pc, [r12], -r12 */
/* @0x2225ac andseq r2, r3, r12, ror #22 */
/* @0x2225b0 andseq r2, r3, r12, asr #22 */
/* @0x2225b4 andseq r2, r3, r0, lsr r11 */
/* @0x2225b8 .word 0xfffff7f8 —— 池字 0xfffff7f8（非指令） */
/* @0x2225bc .word 0xfffff7fc */
/* @0x2225c0 .word 0xfffff800 */
/* @0x2225c4 .word 0xfffff804 */


/* ═══════════════════════════════════════════════════════════════════════
 * §8  anon_2bb8b4  0x2bb8b4..0x2bbd94  1,248 B / 312 条  in-degree 2
 * libjpeg（IJG）量化器区的静态像素步进例程：1,508 B 栈帧、叶子函数（只有 canary 失败路径）
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 = cinfo（0x2bb8d0 存 [sp+0x20]）；r1/r2/r3 = 三个尺寸参数（入口就地 asr #2 / #2 / #3）。
 *
 * 身份证据（三条）
 *   ① 邻接具名件：前 jinit_1pass_quantizer 0x2bad30(968 B)、后 jinit_2pass_quantizer
 *      0x2bc654(408 B)、jdiv_round_up 0x2bc7ec；本段在 0x2bb0f8（5,464 B 匿名簇）内部，
 *      两处调用点 0x2bbe3c / 0x2bc140 都在簇内。
 *   ② 安装面反证（说明本段不是被装进方法槽的入口）：jinit_1pass_quantizer 在 0x2bad74
 *      str r0,[r8,#0x1a8] 装 cinfo->cquantize，并把三个槽写到 [r0] / [r0+8] / [r0+0xc]；
 *      jinit_2pass_quantizer 在 0x2bc68c 同样写 cinfo+0x1a8，装 +0 与 +0xc 两个槽
 *      （池字 0x2bc7e4 / 0x2bc7e8 解出 0x2bb238 / 0x2bb228，都在 0x2bb0f8 簇内），末尾
 *      0x2bc7a8 的 b 0x2bb17c 是尾调簇内函数。⇒ cquantize 的 start_pass / color_quantize
 *      入口另有其人，本段是簇内被调两次的辅助。
 *   ③ 形态：入口 0x2bb8b8 的 sub sp,#1504 + 0x2bb8bc 的 sub sp,#4（1,508 B 帧，唯一出口
 *      0x2bbd78 有配对的 add sp,#4）；0x2bb8c0 / 0x2bb8c4 的 asr #2、0x2bb8f0 的 asr #3、
 *      0x2bb8cc / 0x2bb8e0 的 lsl #5（×32）—— 把输出宽高换算成 4 B/像素的字偏移；0x2bb904
 *      读 cinfo+0x1a8（cquantize），0x2bb914 读 cinfo+0x70。
 *
 * 出口：1 个（0x2bbd78 的 pop {r4..r11,pc}）；窗口内 0 条分支跳出。
 * 唯一 bl：0x2bbd8c 的 __stack_chk_fail@plt（canary 失败路径）⇒ 叶子函数，无外部调用。
 * 边界：0x2bbd90 是池字/误译（andseq），非指令。
 * open：1. 具体是 median_cut / pass2_no_dither / pass2_ord_dither 中的哪一个未定。
 *       2. 1,508 B 帧里的临时数组尺寸（0x5E0）未与 jdquant1/jdquant2 的上游局部变量对齐。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x2bb8b4 0x2bbd94 anon_2bb8b4 jpeg_quantizer_leaf */

/* @0x2bb8b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（9 寄存器） */
/* @0x2bb8b8 sub sp, sp, #1504 —— 1,504 B 帧 */
/* @0x2bb8bc sub sp, sp, #4 —— 再减 4（与出口 0x2bbd78 的 add sp,#4 配对） */
/* @0x2bb8c0 asr r3, r3, #2 —— 尺寸参数 → asr #2 */
/* @0x2bb8c4 asr r1, r1, #2 */
/* @0x2bb8c8 ldr r5, [pc, #0x4c0] */
/* @0x2bb8cc lsl r7, r3, #5 —— ×32（4 B/像素的字步长） */
/* @0x2bb8d0 str r0, [sp, #0x20] */
/* @0x2bb8d4 ldr r5, [pc, r5] */
/* @0x2bb8d8 str r1, [sp, #0x48] */
/* @0x2bb8dc str r5, [sp, #0x44] */
/* @0x2bb8e0 lsl r5, r1, #5 */
/* @0x2bb8e4 add r1, r7, #4 */
/* @0x2bb8e8 str r1, [sp, #0x2c] */
/* @0x2bb8ec ldr r1, [sp, #0x20] */
/* @0x2bb8f0 asr r2, r2, #3 */
/* @0x2bb8f4 add r8, r5, #4 */
/* @0x2bb8f8 str r8, [sp, #0x24] */
/* @0x2bb8fc ldr r8, [sp, #0x44] */
/* @0x2bb900 lsl r6, r2, #5 */
/* @0x2bb904 ldr r4, [r1, #0x1a8] —— 读 cinfo+0x1a8 = cinfo->cquantize */
/* @0x2bb908 add r10, r6, #2 */
/* @0x2bb90c str r10, [sp, #0x28] */
/* @0x2bb910 add r5, r5, #28 */
/* @0x2bb914 ldr r12, [r0, #0x70] */
/* @0x2bb918 add r6, r6, #30 */
/* @0x2bb91c str r2, [sp, #0x4c] */
/* @0x2bb920 add r7, r7, #28 */
/* @0x2bb924 ldr r2, [sp, #0x28] */
/* @0x2bb928 cmp r12, #0 */
/* @0x2bb92c str r3, [sp, #0x50] */
/* @0x2bb930 ldr r10, [sp, #0x24] */
/* @0x2bb934 add r1, r2, r6 */
/* @0x2bb938 ldr r3, [r8] */
/* @0x2bb93c ldr r8, [sp, #0x2c] */
/* @0x2bb940 add r0, r10, r5 */
/* @0x2bb944 ldr r4, [r4, #0x18] */
/* @0x2bb948 asr r1, r1, #1 */
/* @0x2bb94c add r2, r8, r7 */
/* @0x2bb950 asr r0, r0, #1 */
/* @0x2bb954 str r1, [sp, #0x18] */
/* @0x2bb958 asr r2, r2, #1 */
/* @0x2bb95c str r0, [sp, #0x10] */
/* @0x2bb960 str r2, [sp, #0x1c] */
/* @0x2bb964 str r3, [sp, #0x5dc] */
/* @0x2bb968 str r4, [sp, #0x54] */
/* @0x2bb96c ble 0x2bbd7c <jinit_1pass_quantizer+0x104c> */
/* @0x2bb970 ldr r10, [sp, #0x20] */
/* @0x2bb974 add r4, sp, #36 */
/* @0x2bb978 add r1, sp, #92 */
/* @0x2bb97c mvn r0, #-2147483648 */
/* @0x2bb980 str r1, [sp, #0x14] */
/* @0x2bb984 mov r3, #0 */
/* @0x2bb988 ldr r2, [r10, #0x74] */
/* @0x2bb98c ldm r4, {r4, r8, r9} */
/* @0x2bb990 ldm r2, {r10, r11} */
/* @0x2bb994 ldr r2, [r2, #0x8] */
/* @0x2bb998 str r12, [sp, #0x4] */
/* @0x2bb99c str r10, [sp, #0xc] */
/* @0x2bb9a0 str r2, [sp, #0x8] */
/* @0x2bb9a4 b 0x2bba24 <jinit_1pass_quantizer+0xcf4> */
/* @0x2bb9a8 rsb r2, r4, r1 */
/* @0x2bb9ac rsb r10, r5, r1 */
/* @0x2bb9b0 lsl r2, r2, #1 */
/* @0x2bb9b4 lsl r10, r10, #1 */
/* @0x2bb9b8 mul r2, r2, r2 */
/* @0x2bb9bc mul r10, r10, r10 */
/* @0x2bb9c0 ldrb r1, [r11, r3] */
/* @0x2bb9c4 cmp r8, r1 */
/* @0x2bb9c8 ble 0x2bba60 <jinit_1pass_quantizer+0xd30> */
/* @0x2bb9cc rsb r12, r8, r1 */
/* @0x2bb9d0 rsb r1, r6, r1 */
/* @0x2bb9d4 add r12, r12, r12, lsl #1 */
/* @0x2bb9d8 add r1, r1, r1, lsl #1 */
/* @0x2bb9dc mla r2, r12, r12, r2 */
/* @0x2bb9e0 mla r12, r1, r1, r10 */
/* @0x2bb9e4 ldr r10, [sp, #0x8] */
/* @0x2bb9e8 ldrb r1, [r10, r3] */
/* @0x2bb9ec cmp r9, r1 */
/* @0x2bb9f0 ble 0x2bba90 <jinit_1pass_quantizer+0xd60> */
/* @0x2bb9f4 rsb r10, r9, r1 */
/* @0x2bb9f8 rsb r1, r7, r1 */
/* @0x2bb9fc mla r2, r10, r10, r2 */
/* @0x2bba00 mla r1, r1, r1, r12 */
/* @0x2bba04 ldr r12, [sp, #0x14] */
/* @0x2bba08 cmp r0, r1 */
/* @0x2bba0c movge r0, r1 */
/* @0x2bba10 ldr r1, [sp, #0x4] */
/* @0x2bba14 str r2, [r12, r3, lsl #2] */
/* @0x2bba18 add r3, r3, #1 */
/* @0x2bba1c cmp r3, r1 */
/* @0x2bba20 beq 0x2bbb00 <jinit_1pass_quantizer+0xdd0> */
/* @0x2bba24 ldr r2, [sp, #0xc] */
/* @0x2bba28 ldrb r1, [r2, r3] */
/* @0x2bba2c cmp r4, r1 */
/* @0x2bba30 bgt 0x2bb9a8 <jinit_1pass_quantizer+0xc78> */
/* @0x2bba34 cmp r5, r1 */
/* @0x2bba38 bge 0x2bbaac <jinit_1pass_quantizer+0xd7c> */
/* @0x2bba3c rsb r2, r5, r1 */
/* @0x2bba40 rsb r1, r4, r1 */
/* @0x2bba44 lsl r10, r1, #1 */
/* @0x2bba48 ldrb r1, [r11, r3] */
/* @0x2bba4c lsl r2, r2, #1 */
/* @0x2bba50 cmp r8, r1 */
/* @0x2bba54 mul r2, r2, r2 */
/* @0x2bba58 mul r10, r10, r10 */
/* @0x2bba5c bgt 0x2bb9cc <jinit_1pass_quantizer+0xc9c> */
/* @0x2bba60 cmp r6, r1 */
/* @0x2bba64 bge 0x2bbae4 <jinit_1pass_quantizer+0xdb4> */
/* @0x2bba68 rsb r12, r6, r1 */
/* @0x2bba6c rsb r1, r8, r1 */
/* @0x2bba70 add r12, r12, r12, lsl #1 */
/* @0x2bba74 add r1, r1, r1, lsl #1 */
/* @0x2bba78 mla r2, r12, r12, r2 */
/* @0x2bba7c mla r12, r1, r1, r10 */
/* @0x2bba80 ldr r10, [sp, #0x8] */
/* @0x2bba84 ldrb r1, [r10, r3] */
/* @0x2bba88 cmp r9, r1 */
/* @0x2bba8c bgt 0x2bb9f4 <jinit_1pass_quantizer+0xcc4> */
/* @0x2bba90 cmp r7, r1 */
/* @0x2bba94 bge 0x2bbacc <jinit_1pass_quantizer+0xd9c> */
/* @0x2bba98 rsb r10, r7, r1 */
/* @0x2bba9c rsb r1, r9, r1 */
/* @0x2bbaa0 mla r2, r10, r10, r2 */
/* @0x2bbaa4 mla r1, r1, r1, r12 */
/* @0x2bbaa8 b 0x2bba04 <jinit_1pass_quantizer+0xcd4> */
/* @0x2bbaac ldr r10, [sp, #0x10] */
/* @0x2bbab0 mov r2, #0 */
/* @0x2bbab4 cmp r10, r1 */
/* @0x2bbab8 rsbge r1, r5, r1 */
/* @0x2bbabc rsblt r1, r4, r1 */
/* @0x2bbac0 lsl r10, r1, #1 */
/* @0x2bbac4 mul r10, r10, r10 */
/* @0x2bbac8 b 0x2bb9c0 <jinit_1pass_quantizer+0xc90> */
/* @0x2bbacc ldr r10, [sp, #0x1c] */
/* @0x2bbad0 cmp r10, r1 */
/* @0x2bbad4 rsbge r1, r7, r1 */
/* @0x2bbad8 rsblt r1, r9, r1 */
/* @0x2bbadc mla r1, r1, r1, r12 */
/* @0x2bbae0 b 0x2bba04 <jinit_1pass_quantizer+0xcd4> */
/* @0x2bbae4 ldr r12, [sp, #0x18] */
/* @0x2bbae8 cmp r12, r1 */
/* @0x2bbaec rsbge r12, r6, r1 */
/* @0x2bbaf0 rsblt r12, r8, r1 */
/* @0x2bbaf4 add r12, r12, r12, lsl #1 */
/* @0x2bbaf8 mla r12, r12, r12, r10 */
/* @0x2bbafc b 0x2bb9e4 <jinit_1pass_quantizer+0xcb4> */
/* @0x2bbb00 ldr r3, [sp, #0x14] */
/* @0x2bbb04 mov r12, r1 */
/* @0x2bbb08 mov r1, #0 */
/* @0x2bbb0c sub r2, r3, #4 */
/* @0x2bbb10 mov r3, r1 */
/* @0x2bbb14 ldr r4, [r2, #0x4]! */
/* @0x2bbb18 cmp r4, r0 */
/* @0x2bbb1c addle r5, sp, #1504 */
/* @0x2bbb20 addle r4, r5, r1 */
/* @0x2bbb24 addle r1, r1, #1 */
/* @0x2bbb28 strble r3, [r4, #-0x104] */
/* @0x2bbb2c add r3, r3, #1 */
/* @0x2bbb30 cmp r3, r12 */
/* @0x2bbb34 bne 0x2bbb14 <jinit_1pass_quantizer+0xde4> */
/* @0x2bbb38 ldr r3, [sp, #0x14] */
/* @0x2bbb3c add r0, sp, #604 */
/* @0x2bbb40 mvn r2, #-2147483648 */
/* @0x2bbb44 str r2, [r3], #4 */
/* @0x2bbb48 cmp r3, r0 */
/* @0x2bbb4c bne 0x2bbb44 <jinit_1pass_quantizer+0xe14> */
/* @0x2bbb50 cmp r1, #0 */
/* @0x2bbb54 beq 0x2bbce0 <jinit_1pass_quantizer+0xfb0> */
/* @0x2bbb58 ldr r5, [sp, #0x20] */
/* @0x2bbb5c add r8, sp, #1232 */
/* @0x2bbb60 add r8, r8, #11 */
/* @0x2bbb64 add r10, sp, #1104 */
/* @0x2bbb68 add r1, r8, r1 */
/* @0x2bbb6c str r1, [sp, #0x30] */
/* @0x2bbb70 ldr r3, [r5, #0x74] */
/* @0x2bbb74 add r10, r10, #12 */
/* @0x2bbb78 str r8, [sp, #0x20] */
/* @0x2bbb7c str r10, [sp, #0x40] */
/* @0x2bbb80 ldr r12, [r3] */
/* @0x2bbb84 ldr r1, [r3, #0x4] */
/* @0x2bbb88 ldr r3, [r3, #0x8] */
/* @0x2bbb8c str r12, [sp, #0x34] */
/* @0x2bbb90 str r1, [sp, #0x38] */
/* @0x2bbb94 str r3, [sp, #0x3c] */
/* @0x2bbb98 ldr r2, [sp, #0x20] */
/* @0x2bbb9c add r3, sp, #1104 */
/* @0x2bbba0 ldr r8, [sp, #0x38] */
/* @0x2bbba4 add r3, r3, #12 */
/* @0x2bbba8 ldr r5, [sp, #0x14] */
/* @0x2bbbac add r3, r3, #1 */
/* @0x2bbbb0 ldrb r9, [r2, #0x1]! */
/* @0x2bbbb4 ldr r10, [sp, #0x34] */
/* @0x2bbbb8 ldr r12, [sp, #0x28] */
/* @0x2bbbbc ldrb r11, [r8, r9] */
/* @0x2bbbc0 ldrb r1, [r10, r9] */
/* @0x2bbbc4 str r5, [sp, #0x10] */
/* @0x2bbbc8 rsb r11, r11, r12 */
/* @0x2bbbcc ldr r5, [sp, #0x24] */
/* @0x2bbbd0 str r2, [sp, #0x20] */
/* @0x2bbbd4 add r11, r11, r11, lsl #1 */
/* @0x2bbbd8 ldr r2, [sp, #0x3c] */
/* @0x2bbbdc rsb r1, r1, r5 */
/* @0x2bbbe0 str r3, [sp, #0x8] */
/* @0x2bbbe4 lsl r1, r1, #1 */
/* @0x2bbbe8 ldr r8, [sp, #0x2c] */
/* @0x2bbbec ldrb r3, [r2, r9] */
/* @0x2bbbf0 mul r2, r11, r11 */
/* @0x2bbbf4 rsb r3, r3, r8 */
/* @0x2bbbf8 mla r2, r1, r1, r2 */
/* @0x2bbbfc add r10, r3, #4 */
/* @0x2bbc00 add r11, r11, r11, lsl #1 */
/* @0x2bbc04 add r1, r1, #8 */
/* @0x2bbc08 lsl r10, r10, #4 */
/* @0x2bbc0c lsl r11, r11, #3 */
/* @0x2bbc10 add r5, r10, #512 */
/* @0x2bbc14 add r12, r11, #144 */
/* @0x2bbc18 add r11, r11, #2448 */
/* @0x2bbc1c mla r2, r3, r3, r2 */
/* @0x2bbc20 lsl r1, r1, #5 */
/* @0x2bbc24 str r12, [sp, #0x18] */
/* @0x2bbc28 str r1, [sp, #0x4] */
/* @0x2bbc2c add r1, r1, #2048 */
/* @0x2bbc30 str r1, [sp, #0x1c] */
/* @0x2bbc34 str r2, [sp, #0xc] */
/* @0x2bbc38 ldr r8, [sp, #0x8] */
/* @0x2bbc3c ldr r4, [sp, #0x18] */
/* @0x2bbc40 ldr r7, [sp, #0xc] */
/* @0x2bbc44 ldr r6, [sp, #0x10] */
/* @0x2bbc48 mov r0, r6 */
/* @0x2bbc4c mov r1, r8 */
/* @0x2bbc50 mov r3, r10 */
/* @0x2bbc54 mov r2, r7 */
/* @0x2bbc58 ldr r12, [r0], #4 */
/* @0x2bbc5c add r1, r1, #1 */
/* @0x2bbc60 cmp r12, r2 */
/* @0x2bbc64 strbgt r9, [r1, #-0x2] */
/* @0x2bbc68 strgt r2, [r0, #-0x4] */
/* @0x2bbc6c add r2, r2, r3 */
/* @0x2bbc70 add r3, r3, #128 */
/* @0x2bbc74 cmp r3, r5 */
/* @0x2bbc78 bne 0x2bbc58 <jinit_1pass_quantizer+0xf28> */
/* @0x2bbc7c add r7, r7, r4 */
/* @0x2bbc80 add r4, r4, #288 */
/* @0x2bbc84 cmp r4, r11 */
/* @0x2bbc88 add r6, r6, #16 */
/* @0x2bbc8c add r8, r8, #4 */
/* @0x2bbc90 bne 0x2bbc48 <jinit_1pass_quantizer+0xf18> */
/* @0x2bbc94 ldr r3, [sp, #0x4] */
/* @0x2bbc98 ldr r2, [sp, #0xc] */
/* @0x2bbc9c ldr r8, [sp, #0x1c] */
/* @0x2bbca0 add r2, r2, r3 */
/* @0x2bbca4 add r3, r3, #512 */
/* @0x2bbca8 ldr r12, [sp, #0x10] */
/* @0x2bbcac cmp r3, r8 */
/* @0x2bbcb0 ldr r1, [sp, #0x8] */
/* @0x2bbcb4 add r12, r12, #128 */
/* @0x2bbcb8 str r2, [sp, #0xc] */
/* @0x2bbcbc add r1, r1, #32 */
/* @0x2bbcc0 str r3, [sp, #0x4] */
/* @0x2bbcc4 str r12, [sp, #0x10] */
/* @0x2bbcc8 str r1, [sp, #0x8] */
/* @0x2bbccc bne 0x2bbc38 <jinit_1pass_quantizer+0xf08> */
/* @0x2bbcd0 ldr r2, [sp, #0x20] */
/* @0x2bbcd4 ldr r3, [sp, #0x30] */
/* @0x2bbcd8 cmp r2, r3 */
/* @0x2bbcdc bne 0x2bbb98 <jinit_1pass_quantizer+0xe68> */
/* @0x2bbce0 ldr r10, [sp, #0x50] */
/* @0x2bbce4 add r5, sp, #1136 */
/* @0x2bbce8 ldr r2, [sp, #0x4c] */
/* @0x2bbcec add r8, sp, #1264 */
/* @0x2bbcf0 ldr r1, [sp, #0x48] */
/* @0x2bbcf4 add r5, r5, #12 */
/* @0x2bbcf8 lsl r7, r10, #2 */
/* @0x2bbcfc ldr r12, [sp, #0x54] */
/* @0x2bbd00 add r7, r7, r2, lsl #8 */
/* @0x2bbd04 add r8, r8, #12 */
/* @0x2bbd08 add r6, r12, r1, lsl #4 */
/* @0x2bbd0c sub r6, r6, #4 */
/* @0x2bbd10 lsl r7, r7, #1 */
/* @0x2bbd14 ldr r4, [r6, #0x4]! */
/* @0x2bbd18 sub r12, r5, #32 */
/* @0x2bbd1c add r4, r4, r7 */
/* @0x2bbd20 add r0, r4, #8 */
/* @0x2bbd24 mov r3, r4 */
/* @0x2bbd28 mov r2, r12 */
/* @0x2bbd2c ldrb r1, [r2], #1 */
/* @0x2bbd30 add r1, r1, #1 */
/* @0x2bbd34 strh r1, [r3], #2 */
/* @0x2bbd38 cmp r3, r0 */
/* @0x2bbd3c bne 0x2bbd2c <jinit_1pass_quantizer+0xffc> */
/* @0x2bbd40 add r12, r12, #4 */
/* @0x2bbd44 add r4, r4, #64 */
/* @0x2bbd48 cmp r12, r5 */
/* @0x2bbd4c bne 0x2bbd20 <jinit_1pass_quantizer+0xff0> */
/* @0x2bbd50 add r5, r12, #32 */
/* @0x2bbd54 cmp r5, r8 */
/* @0x2bbd58 bne 0x2bbd14 <jinit_1pass_quantizer+0xfe4> */
/* @0x2bbd5c ldr r5, [sp, #0x44] */
/* @0x2bbd60 ldr r2, [sp, #0x5dc] */
/* @0x2bbd64 ldr r3, [r5] */
/* @0x2bbd68 cmp r2, r3 */
/* @0x2bbd6c bne 0x2bbd8c <jinit_1pass_quantizer+0x105c> */
/* @0x2bbd70 add sp, sp, #1504 */
/* @0x2bbd74 add sp, sp, #4 */
/* @0x2bbd78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 唯一出口 */
/* @0x2bbd7c add r8, sp, #92 */
/* @0x2bbd80 mov r1, #0 */
/* @0x2bbd84 str r8, [sp, #0x14] */
/* @0x2bbd88 b 0x2bbb38 <jinit_1pass_quantizer+0xe08> */
/* @0x2bbd8c bl 0xb65d4 <__stack_chk_fail@plt> —— 唯一 bl：__stack_chk_fail（canary 失败路径） */
/* @0x2bbd90 andseq r2, r3, r12, ror r0 */


/* ═══════════════════════════════════════════════════════════════════════
 * §9  anon_230b68  0x230b68..0x230eb8  856 B / 212 条  in-degree 2
 * vorbisfile 的 _fetch_and_process_packet（vorbisfile.c 静态例程）
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 = OggVorbis_File*（0x230b80 存 r8）；0x230b74 / 0x230b78 预先算出结构内两个子对象
 *       基址（r0+120 → r9、r0+560 → r10）。
 *
 * 身份证据（三条）
 *   ① 调用面是 libvorbis / libogg 的具名 API 组合：vorbis_synthesis(0x22fc6c) ×1、
 *      vorbis_synthesis_blockin(0x227638) ×1、vorbis_synthesis_pcmout(0x227c80) ×4、
 *      vorbis_block_clear(0x227208)、vorbis_dsp_clear(0x2272ac)、vorbis_info_clear(0x22ad10)、
 *      vorbis_comment_clear(0x22ac4c)、ogg_stream_pagein(0x234eac)、ogg_stream_packetout(0x235328)、
 *      ogg_page_bos(0x233f90)、ogg_page_serialno(0x23409c) ×2、ogg_stream_reset_serialno(0x2352f4)。
 *   ② 调用者只有两处：ov_read+0x34（0x232efc）与 ov_pcm_seek+0x310（0x232a04）—— vorbisfile.c
 *      里同时被这两条公共入口调用的静态例程就是 _fetch_and_process_packet。
 *   ③ 状态机：0x230b88 读 [r8+0x58]（OggVorbis_File 的 state），按 3 / 4 / ≤1 三分支
 *      （0x230d04 / 0x230ca4 / 0x230d28）；0x230bec 读 [r8+0x5c]（当前流序号）与
 *      ogg_page_serialno 比较；错误路径 0x230df0 起连调 *_clear。
 *
 * 出口：1 个 pop {r4..r11,pc}（0x230ccc）。
 * 边界：窗口内有 1 条分支落到 0x230eb8 = 本段末尾（下一段的起点），说明尾部是共用续块、
 *       不是出口；段尾 0x230eb4 的 b 0x230cc8 回主返回路径。
 * open：1. 与 vorbisfile.c 源文件的逐行对应未做（本卡只钉调用面 + 状态机形态）。
 *       2. 0x230eb8 之后那段（下一 split 行）未出卡。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x230b68 0x230eb8 anon_230b68 vorbisfile_fetch_packet */

/* @0x230b68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（9 寄存器 + 60 B 帧） */
/* @0x230b6c sub sp, sp, #60 */
/* @0x230b70 add r6, sp, #24 */
/* @0x230b74 add r9, r0, #120 —— r9 = OggVorbis_File+120 */
/* @0x230b78 add r10, r0, #560 —— r10 = OggVorbis_File+560 */
/* @0x230b7c add r7, sp, #8 */
/* @0x230b80 mov r8, r0 */
/* @0x230b84 mov r11, #3 */
/* @0x230b88 ldr r3, [r8, #0x58] —— 读 state = [r8+0x58] */
/* @0x230b8c cmp r3, #3 —— state == 3 分支 */
/* @0x230b90 beq 0x230d04 <vorbis_packet_blocksize+0x1088> */
/* @0x230b94 cmp r3, #4 —— state == 4 分支 */
/* @0x230b98 beq 0x230ca4 <vorbis_packet_blocksize+0x1028> */
/* @0x230b9c cmp r3, #1 */
/* @0x230ba0 ble 0x230d28 <vorbis_packet_blocksize+0x10ac> */
/* @0x230ba4 mvn r3, #0 */
/* @0x230ba8 mov r0, r8 */
/* @0x230bac mov r1, r7 */
/* @0x230bb0 mvn r2, #0 */
/* @0x230bb4 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x230bb8 cmp r0, #0 */
/* @0x230bbc sbcs r3, r1, #0 */
/* @0x230bc0 mov r0, r7 */
/* @0x230bc4 blt 0x230e70 <vorbis_packet_blocksize+0x11f4> */
/* @0x230bc8 ldr r12, [sp, #0xc] */
/* @0x230bcc ldrd r2, r3, [r8, #104] */
/* @0x230bd0 ldr r1, [r8, #0x58] */
/* @0x230bd4 lsl r12, r12, #3 */
/* @0x230bd8 adds r2, r2, r12 */
/* @0x230bdc adc r3, r3, r12, asr #31 */
/* @0x230be0 cmp r1, #4 */
/* @0x230be4 strd r2, r3, [r8, #104] */
/* @0x230be8 bne 0x230ce4 <vorbis_packet_blocksize+0x1068> */
/* @0x230bec ldr r4, [r8, #0x5c] —— 流序号与 ogg_page_serialno 比较 */
/* @0x230bf0 bl 0x23409c <ogg_page_serialno> */
/* @0x230bf4 cmp r4, r0 */
/* @0x230bf8 mov r0, r7 */
/* @0x230bfc beq 0x230ce0 <vorbis_packet_blocksize+0x1064> */
/* @0x230c00 bl 0x233f90 <ogg_page_bos> */
/* @0x230c04 cmp r0, #0 */
/* @0x230c08 beq 0x230ba4 <vorbis_packet_blocksize+0xf28> */
/* @0x230c0c add r0, r8, #480 */
/* @0x230c10 bl 0x2272ac <vorbis_dsp_clear> */
/* @0x230c14 mov r0, r10 */
/* @0x230c18 bl 0x227208 <vorbis_block_clear> */
/* @0x230c1c ldr r3, [r8, #0x4] */
/* @0x230c20 mov r2, #2 */
/* @0x230c24 str r2, [r8, #0x58] */
/* @0x230c28 cmp r3, #0 */
/* @0x230c2c beq 0x230cd0 <vorbis_packet_blocksize+0x1054> */
/* @0x230c30 mov r0, r7 */
/* @0x230c34 bl 0x23409c <ogg_page_serialno> */
/* @0x230c38 ldr r1, [r8, #0x34] */
/* @0x230c3c cmp r1, #0 */
/* @0x230c40 ble 0x230eb8 <vorbis_packet_blocksize+0x123c> */
/* @0x230c44 ldr r2, [r8, #0x40] */
/* @0x230c48 ldr r3, [r2] */
/* @0x230c4c cmp r0, r3 */
/* @0x230c50 mov r3, #0 */
/* @0x230c54 beq 0x230c70 <vorbis_packet_blocksize+0xff4> */
/* @0x230c58 add r3, r3, #1 */
/* @0x230c5c cmp r3, r1 */
/* @0x230c60 beq 0x230b88 <vorbis_packet_blocksize+0xf0c> */
/* @0x230c64 ldr r12, [r2, #0x4]! */
/* @0x230c68 cmp r0, r12 */
/* @0x230c6c bne 0x230c58 <vorbis_packet_blocksize+0xfdc> */
/* @0x230c70 str r0, [r8, #0x5c] */
/* @0x230c74 mov r1, r0 */
/* @0x230c78 str r3, [r8, #0x60] */
/* @0x230c7c mov r0, r9 */
/* @0x230c80 bl 0x2352f4 <ogg_stream_reset_serialno> */
/* @0x230c84 str r11, [r8, #0x58] */
/* @0x230c88 b 0x230cec <vorbis_packet_blocksize+0x1070> */
/* @0x230c8c cmp r3, #0 */
/* @0x230c90 ble 0x230d1c <vorbis_packet_blocksize+0x10a0> */
/* @0x230c94 ldrd r4, r5, [sp, #40] */
/* @0x230c98 bl 0x22fc6c <vorbis_synthesis> */
/* @0x230c9c cmp r0, #0 */
/* @0x230ca0 beq 0x230d70 <vorbis_packet_blocksize+0x10f4> */
/* @0x230ca4 mov r1, r6 */
/* @0x230ca8 mov r0, r9 */
/* @0x230cac bl 0x235328 <ogg_stream_packetout> */
/* @0x230cb0 mov r1, r6 */
/* @0x230cb4 mov r3, r0 */
/* @0x230cb8 cmn r3, #1 */
/* @0x230cbc mov r0, r10 */
/* @0x230cc0 bne 0x230c8c <vorbis_packet_blocksize+0x1010> */
/* @0x230cc4 mvn r0, #2 */
/* @0x230cc8 add sp, sp, #60 */
/* @0x230ccc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 唯一出口 */
/* @0x230cd0 ldr r0, [r8, #0x48] */
/* @0x230cd4 bl 0x22ad10 <vorbis_info_clear> */
/* @0x230cd8 ldr r0, [r8, #0x4c] */
/* @0x230cdc bl 0x22ac4c <vorbis_comment_clear> */
/* @0x230ce0 ldr r1, [r8, #0x58] */
/* @0x230ce4 cmp r1, #2 */
/* @0x230ce8 ble 0x230d28 <vorbis_packet_blocksize+0x10ac> */
/* @0x230cec mov r0, r9 */
/* @0x230cf0 mov r1, r7 */
/* @0x230cf4 bl 0x234eac <ogg_stream_pagein> */
/* @0x230cf8 ldr r3, [r8, #0x58] */
/* @0x230cfc cmp r3, #3 */
/* @0x230d00 bne 0x230b94 <vorbis_packet_blocksize+0xf18> */
/* @0x230d04 mov r0, r8 */
/* @0x230d08 bl 0x230294 <vorbis_packet_blocksize+0x618> */
/* @0x230d0c cmp r0, #0 */
/* @0x230d10 blt 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230d14 ldr r3, [r8, #0x58] */
/* @0x230d18 b 0x230b94 <vorbis_packet_blocksize+0xf18> */
/* @0x230d1c ldr r3, [r8, #0x58] */
/* @0x230d20 cmp r3, #1 */
/* @0x230d24 bgt 0x230ba4 <vorbis_packet_blocksize+0xf28> */
/* @0x230d28 ldr r12, [r8, #0x4] */
/* @0x230d2c cmp r12, #0 */
/* @0x230d30 bne 0x230c30 <vorbis_packet_blocksize+0xfb4> */
/* @0x230d34 ldr r1, [r8, #0x48] */
/* @0x230d38 mov r3, r12 */
/* @0x230d3c ldr r2, [r8, #0x4c] */
/* @0x230d40 mov r0, r8 */
/* @0x230d44 str r12, [sp] */
/* @0x230d48 str r7, [sp, #0x4] */
/* @0x230d4c bl 0x230334 <vorbis_packet_blocksize+0x6b8> */
/* @0x230d50 cmp r0, #0 */
/* @0x230d54 bne 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230d58 ldr r2, [r8, #0x1c8] */
/* @0x230d5c ldr r3, [r8, #0x60] */
/* @0x230d60 str r2, [r8, #0x5c] */
/* @0x230d64 add r3, r3, #1 */
/* @0x230d68 str r3, [r8, #0x60] */
/* @0x230d6c b 0x230cec <vorbis_packet_blocksize+0x1070> */
/* @0x230d70 add r9, r8, #480 */
/* @0x230d74 mov r1, r0 */
/* @0x230d78 mov r0, r9 */
/* @0x230d7c bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x230d80 subs r6, r0, #0 */
/* @0x230d84 mvnne r0, #128 */
/* @0x230d88 bne 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230d8c mov r1, r10 */
/* @0x230d90 mov r0, r9 */
/* @0x230d94 bl 0x227638 <vorbis_synthesis_blockin> */
/* @0x230d98 mov r1, r6 */
/* @0x230d9c mov r0, r9 */
/* @0x230da0 ldrd r6, r7, [r8, #112] */
/* @0x230da4 bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x230da8 ldr r1, [sp, #0x1c] */
/* @0x230dac ldrd r2, r3, [r8, #104] */
/* @0x230db0 mvn r10, #0 */
/* @0x230db4 mvn r11, #0 */
/* @0x230db8 lsl r1, r1, #3 */
/* @0x230dbc adds r2, r2, r1 */
/* @0x230dc0 adc r3, r3, r1, asr #31 */
/* @0x230dc4 strd r2, r3, [r8, #104] */
/* @0x230dc8 adds r2, r6, r0 */
/* @0x230dcc adc r3, r7, r0, asr #31 */
/* @0x230dd0 cmp r5, r11 */
/* @0x230dd4 cmpeq r4, r10 */
/* @0x230dd8 mov r0, r2 */
/* @0x230ddc mov r1, r3 */
/* @0x230de0 strd r0, r1, [r8, #112] */
/* @0x230de4 beq 0x230e78 <vorbis_packet_blocksize+0x11fc> */
/* @0x230de8 ldr r3, [sp, #0x24] */
/* @0x230dec cmp r3, #0 */
/* @0x230df0 bne 0x230e78 <vorbis_packet_blocksize+0x11fc> */
/* @0x230df4 ldr r3, [r8, #0x4] */
/* @0x230df8 cmp r3, #0 */
/* @0x230dfc beq 0x230e80 <vorbis_packet_blocksize+0x1204> */
/* @0x230e00 ldr r6, [r8, #0x60] */
/* @0x230e04 cmp r6, #0 */
/* @0x230e08 ble 0x230e80 <vorbis_packet_blocksize+0x1204> */
/* @0x230e0c ldr r3, [r8, #0x44] */
/* @0x230e10 lsl r6, r6, #4 */
/* @0x230e14 mov r1, #0 */
/* @0x230e18 mov r0, r9 */
/* @0x230e1c ldrd r2, r3, [r3, r6] */
/* @0x230e20 subs r4, r4, r2 */
/* @0x230e24 sbc r5, r5, r3 */
/* @0x230e28 cmp r4, #0 */
/* @0x230e2c sbcs r3, r5, #0 */
/* @0x230e30 movlt r4, #0 */
/* @0x230e34 movlt r5, #0 */
/* @0x230e38 bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x230e3c ldr r12, [r8, #0x44] */
/* @0x230e40 add r6, r6, r12 */
/* @0x230e44 subs r2, r4, r0 */
/* @0x230e48 sbc r3, r5, r0, asr #31 */
/* @0x230e4c mov r0, r2 */
/* @0x230e50 mov r1, r3 */
/* @0x230e54 ldrd r2, r3, [r12, #8] */
/* @0x230e58 add r12, r12, #16 */
/* @0x230e5c adds r0, r0, r2 */
/* @0x230e60 adc r1, r1, r3 */
/* @0x230e64 cmp r12, r6 */
/* @0x230e68 bne 0x230e54 <vorbis_packet_blocksize+0x11d8> */
/* @0x230e6c b 0x230eac <vorbis_packet_blocksize+0x1230> */
/* @0x230e70 mvn r0, #1 */
/* @0x230e74 b 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230e78 mov r0, #1 */
/* @0x230e7c b 0x230cc8 <vorbis_packet_blocksize+0x104c> */
/* @0x230e80 cmp r4, #0 */
/* @0x230e84 sbcs r2, r5, #0 */
/* @0x230e88 mov r1, #0 */
/* @0x230e8c mov r0, r9 */
/* @0x230e90 movlt r4, #0 */
/* @0x230e94 movlt r5, #0 */
/* @0x230e98 bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x230e9c subs r2, r4, r0 */
/* @0x230ea0 sbc r3, r5, r0, asr #31 */
/* @0x230ea4 mov r0, r2 */
/* @0x230ea8 mov r1, r3 */
/* @0x230eac strd r0, r1, [r8, #80] */
/* @0x230eb0 mov r0, #1 */
/* @0x230eb4 b 0x230cc8 <vorbis_packet_blocksize+0x104c> —— 尾跳回 0x230cc8 */


/* ═══════════════════════════════════════════════════════════════════════
 * §10  anon_2de214  0x2de214..0x2de460  588 B / 147 条  in-degree 2
 * Box2D 的 b2CollidePolygons 内部静态辅助（浮点分离/入射边计算族）
 * ─────────────────────────────────────────────────────────────────────
 * 契约：r0 = 输出（0x2de26c 存 [sp+0xc]）；r1 = 多边形 A（含 +0x94 的顶点数、+0x10 起的
 *       法线/顶点）；r2/r3 = 两个 b2Transform（0x2de220..0x2de250 读 +0x4 / +0x8 / +0xC / +0x10）；
 *       第 5 参 [sp+0x48] → r7（另一个变换）。
 *
 * 身份证据（三条）
 *   ① 调用者具名且唯一：b2CollidePolygons（0x2de464，具名 _Z17b2CollidePolygons…）的两条 bl
 *      —— 0x2de4a4（+0x40）与 0x2de4dc（+0x78）。同区还有 b2CollideEdgeAndPolygon 0x2de0bc、
 *      b2EPCollider::Collide 0x2dd360、b2DynamicTree 0x2de900。
 *   ② 形态：vpush {d8, d9}（8 个单精度寄存器）+ vldr / vmul.f32 / vmla.f32 / vsub.f32 连续投影
 *      计算；0x2de258 读 [r1+0x94]（多边形顶点数）；0x2de270 的 add r12,r1,#84 是顶点数组基址。
 *   ③ 段内 6 处 bl 全部指向 0x2de0f4（876 B，同区匿名簇）—— 可能是同一个法线/边选择例程。
 *
 * 出口：2 个 pop {r4..r11,pc}（0x2de3d4 / 0x2de3f8）；窗口内 0 条分支跳出。
 * 边界：段尾 0x2de45c 的 b 0x2de324 是回主循环的尾跳，不是出口。
 * open：1. 具体是 b2FindMaxSeparation 还是 b2FindIncidentEdge 未定。线索：b2CollidePolygons
 *          里"最大分离"恰好算两次，与本段的两个调用点吻合；但 6 次内部调用 0x2de0f4 的形态
 *          需要与源码对齐才能确认。
 *       2. 顶点数在 +0x94 的结论只来自本段的读法，未与该结构体的其它使用者交叉验证。
 * ═══════════════════════════════════════════════════════════════════ */
/* @func 0x2de214 0x2de460 anon_2de214 box2d_separation_helper */

/* @0x2de214 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（9 寄存器 + vpush {d8, d9}） */
/* @0x2de218 vpush {d8, d9} */
/* @0x2de21c sub sp, sp, #20 */
/* @0x2de220 vldr s14, [r2, #12] —— 读变换的位置分量 */
/* @0x2de224 vldr s13, [r1, #16] */
/* @0x2de228 vldr s5, [r3, #16] */
/* @0x2de22c ldr r7, [sp, #0x48] */
/* @0x2de230 vmul.f32 s9, s14, s13 */
/* @0x2de234 vldr s7, [r7, #12] */
/* @0x2de238 vldr s15, [r2, #8] */
/* @0x2de23c vldr s6, [r1, #12] */
/* @0x2de240 vldr s8, [r3, #12] */
/* @0x2de244 vldr s12, [r7, #8] */
/* @0x2de248 vldr s2, [r2, #4] */
/* @0x2de24c vldr s11, [r7, #4] */
/* @0x2de250 vldr s3, [r7] */
/* @0x2de254 vldr s4, [r2] */
/* @0x2de258 ldr r4, [r1, #0x94] —— 读多边形顶点数 [r1+0x94] */
/* @0x2de25c mov r5, r1 */
/* @0x2de260 mov r6, r2 */
/* @0x2de264 cmp r4, #0 */
/* @0x2de268 mov r8, r3 */
/* @0x2de26c str r0, [sp, #0xc] */
/* @0x2de270 add r12, r1, #84 —— 顶点数组基址 = r1+84 */
/* @0x2de274 vmul.f32 s10, s7, s5 */
/* @0x2de278 vmla.f32 s9, s6, s15 */
/* @0x2de27c vmla.f32 s10, s8, s12 */
/* @0x2de280 vmul.f32 s13, s15, s13 */
/* @0x2de284 vmul.f32 s12, s12, s5 */
/* @0x2de288 vnmls.f32 s13, s14, s6 */
/* @0x2de28c vnmls.f32 s12, s7, s8 */
/* @0x2de290 vadd.f32 s11, s10, s11 */
/* @0x2de294 vadd.f32 s9, s9, s2 */
/* @0x2de298 vsub.f32 s11, s11, s9 */
/* @0x2de29c vadd.f32 s10, s12, s3 */
/* @0x2de2a0 vadd.f32 s13, s13, s4 */
/* @0x2de2a4 vmul.f32 s12, s15, s11 */
/* @0x2de2a8 vmul.f32 s11, s14, s11 */
/* @0x2de2ac vsub.f32 s13, s10, s13 */
/* @0x2de2b0 vmla.f32 s12, s14, s13 */
/* @0x2de2b4 vmls.f32 s11, s15, s13 */
/* @0x2de2b8 ble 0x2de438 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x37c> */
/* @0x2de2bc mov r10, #0 */
/* @0x2de2c0 vldr s13, [pc, #408] */
/* @0x2de2c4 mov lr, r10 */
/* @0x2de2c8 vldr s15, [r12, #4] */
/* @0x2de2cc vldr s14, [r12] */
/* @0x2de2d0 add r12, r12, #8 */
/* @0x2de2d4 vmul.f32 s15, s11, s15 */
/* @0x2de2d8 vmla.f32 s15, s12, s14 */
/* @0x2de2dc vcmpe.f32 s15, s13 */
/* @0x2de2e0 vmrs APSR_nzcv, fpscr */
/* @0x2de2e4 movgt r10, lr */
/* @0x2de2e8 add lr, lr, #1 */
/* @0x2de2ec vmovgt.f32 s13, s15 */
/* @0x2de2f0 cmp lr, r4 */
/* @0x2de2f4 bne 0x2de2c8 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x20c> */
/* @0x2de2f8 str r7, [sp] */
/* @0x2de2fc mov r0, r5 */
/* @0x2de300 mov r1, r6 */
/* @0x2de304 mov r2, r10 */
/* @0x2de308 mov r3, r8 */
/* @0x2de30c bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de310 cmp r10, #0 */
/* @0x2de314 vmov.f32 s17, s0 */
/* @0x2de318 beq 0x2de450 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x394> */
/* @0x2de31c sub r9, r10, #1 */
/* @0x2de320 add r11, r10, #1 */
/* @0x2de324 cmp r4, r11 */
/* @0x2de328 mov r0, r5 */
/* @0x2de32c mov r1, r6 */
/* @0x2de330 mov r2, r9 */
/* @0x2de334 mov r3, r8 */
/* @0x2de338 str r7, [sp] */
/* @0x2de33c movle r11, #0 */
/* @0x2de340 bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de344 str r7, [sp] */
/* @0x2de348 mov r2, r11 */
/* @0x2de34c mov r0, r5 */
/* @0x2de350 mov r1, r6 */
/* @0x2de354 mov r3, r8 */
/* @0x2de358 vmov.f32 s18, s0 */
/* @0x2de35c bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de360 vcmpe.f32 s18, s17 */
/* @0x2de364 vmrs APSR_nzcv, fpscr */
/* @0x2de368 vmov.f32 s16, s0 */
/* @0x2de36c ble 0x2de3d8 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x31c> */
/* @0x2de370 vcmpe.f32 s18, s0 */
/* @0x2de374 vmrs APSR_nzcv, fpscr */
/* @0x2de378 ble 0x2de3d8 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x31c> */
/* @0x2de37c vmov.f32 s16, s18 */
/* @0x2de380 mov r11, r9 */
/* @0x2de384 b 0x2de390 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x2d4> */
/* @0x2de388 vmov.f32 s16, s0 */
/* @0x2de38c mov r11, r10 */
/* @0x2de390 cmp r11, #0 */
/* @0x2de394 sub r10, r11, #1 */
/* @0x2de398 suble r10, r4, #1 */
/* @0x2de39c str r7, [sp] */
/* @0x2de3a0 mov r0, r5 */
/* @0x2de3a4 mov r1, r6 */
/* @0x2de3a8 mov r2, r10 */
/* @0x2de3ac mov r3, r8 */
/* @0x2de3b0 bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de3b4 vcmpe.f32 s0, s16 */
/* @0x2de3b8 vmrs APSR_nzcv, fpscr */
/* @0x2de3bc bgt 0x2de388 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x2cc> */
/* @0x2de3c0 ldr r3, [sp, #0xc] */
/* @0x2de3c4 vmov.f32 s0, s16 */
/* @0x2de3c8 str r11, [r3] */
/* @0x2de3cc add sp, sp, #20 */
/* @0x2de3d0 vpop {d8, d9} */
/* @0x2de3d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1 */
/* @0x2de3d8 vcmpe.f32 s16, s17 */
/* @0x2de3dc vmrs APSR_nzcv, fpscr */
/* @0x2de3e0 bgt 0x2de404 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x348> */
/* @0x2de3e4 ldr r3, [sp, #0xc] */
/* @0x2de3e8 vmov.f32 s0, s17 */
/* @0x2de3ec str r10, [r3] */
/* @0x2de3f0 add sp, sp, #20 */
/* @0x2de3f4 vpop {d8, d9} */
/* @0x2de3f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2 */
/* @0x2de3fc vmov.f32 s16, s0 */
/* @0x2de400 mov r11, r10 */
/* @0x2de404 add r10, r11, #1 */
/* @0x2de408 str r7, [sp] */
/* @0x2de40c cmp r4, r10 */
/* @0x2de410 mov r0, r5 */
/* @0x2de414 mov r1, r6 */
/* @0x2de418 mov r3, r8 */
/* @0x2de41c movle r10, #0 */
/* @0x2de420 mov r2, r10 */
/* @0x2de424 bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> */
/* @0x2de428 vcmpe.f32 s0, s16 */
/* @0x2de42c vmrs APSR_nzcv, fpscr */
/* @0x2de430 bgt 0x2de3fc <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x340> */
/* @0x2de434 b 0x2de3c0 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x304> */
/* @0x2de438 mov r0, r1 */
/* @0x2de43c str r7, [sp] */
/* @0x2de440 mov r1, r2 */
/* @0x2de444 mov r2, #0 */
/* @0x2de448 bl 0x2de0f4 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x38> —— bl 0x2de0f4（同区匿名簇） */
/* @0x2de44c vmov.f32 s17, s0 */
/* @0x2de450 sub r9, r4, #1 */
/* @0x2de454 mov r11, #1 */
/* @0x2de458 mov r10, #0 */
/* @0x2de45c b 0x2de324 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x268> —— 尾跳回 0x2de324（不是出口） */

