/* cally 逆向卡：INITIALIZE_Code_Constant（命名常量表装填）+ VM::WriteInstanceBuiltInVariables（实例内建变量写盘）
 * @func 0xee01c 0xf1748  size 14124  3531 条（513 bl AddRealConstant / 6 b / 5 条件 / 348 字名字偏移池）
 * @func 0xd96f0 0xdadc8  size 5848   1462 条（110 blx Write / 25 bl / 12 b）
 * 级别: 正文 · bytecode_anchored（两节都逐条落锚：3531/3531 与 1462/1462）
 *       节 1 钉住：表身份（命名常量表，不是 CCode）、物理结构（names[4B] / values[16B] 双平行数组 + 名字哈希）、
 *                  条数（513 调用点 / 501 个不同名字 / 7 段 475 条 + 5 门 38 条）、
 *                  每一条的名字与 double 值（名字取自同版本 .so 的 .rodata，值由 r2:r3 逐条解出）。
 *                  未钉：5 个门控字节的语义、12 条 audio_* 重名在表里是否留两条。
 *       节 2 钉住：写协议（(type, double) 进 buf 内嵌 RValue，**不写名字**）、80 条主序列的字段/类型/来源、
 *                  30 条回退、尾部转发 GetInstanceVariables。
 *                  未钉：phy_* 各 bit 的语义名、0xe8..0xf4 四个 int 的名字、消费端如何按位置还原名字。
 * 符号: _Z24INITIALIZE_Code_Constantv → void INITIALIZE_Code_Constant()
 *       _ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance
 *         → void VM::WriteInstanceBuiltInVariables(Buffer_Standard*, CInstance*)
 * ABI : softfp —— double 一律走 r2:r3 整数寄存器对；节 2 的 RValue 低/高字也是这套（vstr s12 / str r5）。
 * 同层: AddConstant 0xedd00 / AddRealConstant 0xedff4 / AddStringConstant 0xf1748 /
 *       Code_Constant_Find 0xf1770 / Code_Constant_Find_IgnoreCase 0xedc8c /
 *       Code_Constant_Add 0xf1a10 / Code_Constant_Prepare 0xf1b44 / FINALIZE_Code_Constant 0xf1bb0 /
 *       InitYoYoFunctionConstants 0x15d0f8 / CInstance::GetTimer 0x193134 / GetImageNumber 0x19357c /
 *       Sprite_Data 0x1ef03c / GV_Physics* 8 个 / GV_Layer 0x1fadd4 / VM::GetInstanceVariables 0xd9548 /
 *       CInstance::Compute_BoundingBox 0x192340
 * 调用点: 节 1 —— 全 .text 扫 bl，唯一调用点 Init() 0x2a2938（0x2a2910 那段静态初始化序列里，
 *         前接 0x1a86ac/0x2151b8/0x27de00/0x28fe6c/0x214e10/0x16c2c0，后接 0x179d3c）；
 *         节 1 末尾 tail-call InitYoYoFunctionConstants（0xf1138 pop / 0xf113c b 0x15d0f8）。
 *         节 2 —— 两个调用点：VM::GetRuntimeState 0xdb044、Debug_GetInstances 0x29ad2c。
 *
 * ══════════════════════════════════════════════════════════════════════════
 * 节 1 · INITIALIZE_Code_Constant —— 到底在初始化哪张表
 * ══════════════════════════════════════════════════════════════════════════
 *
 * ── 一句话 ───────────────────────────────────────────────────────────────
 *   把引擎内置的那批 GML **命名常量**（self/other/all/noone/global/local、true/false、pi、c_* 颜色、
 *   bm_* 混合、ev_* 事件、vk_* 按键、fa_*、os_*、pr_*、tf_*/mip_*、phy_*、buffer_* …）逐条塞进一张
 *   全局的「名字 → RValue」表；收尾再 tail-jump 到 InitYoYoFunctionConstants 补 93 条 os_*/ds_type_*/fb_login_*。
 *   它**不是** CCode 表，也**不是**每个游戏自己的常量：本函数一条 CCode 都不碰，全部走 AddRealConstant。
 *
 * ── 表身份（三条独立证据，缺一不算）─────────────────────────────────────
 *   1. 调用面：全函数 513 个 bl 无一例外打向 0xedff4 = AddRealConstant(char const*, double)。
 *      没有一条打向 CCode / Code_Execute / DoCallGML 那侧；也没有一条 AddStringConstant（0xf1748）。
 *   2. 落库面：AddRealConstant 0xedff4 只有一条 bl，其余全是 RValue 组装 ——
 *        strd r2, r3, [r1, #-0x10]!   ; double 落到栈上 RValue 的 +0/+4
 *        mov  ip, #0 / str ip, [sp, #0xc]  ; tag = 0（VT_REAL）落到 +0xc
 *        bl   0xedd00                  ; AddConstant(name, &rv)
 *      ⇒ 16 B RValue = {+0 double, +0xc tag}，这是节 2 里 buf+0x2c/+0x30/+0x38 的同一套布局。
 *   3. 存储面：AddConstant 0xedd00 维护**两个平行数组 + 一个计数器**：
 *        count 在 GOT 全局里；每次先 YYRealloc(names, (count+1)*4) 与 (values, (count+1)*16)，
 *        然后 names[count] = strdup(name)（0xdb8c8）、values[count] = *rv（按 tag 走 0..0xe 的引用计数分支），
 *        count++，最后尾调 0xd3a34 做**名字哈希插入**（删除侧 0xd3a54）。
 *      查询侧同源：Code_Constant_Find 0xf1770 / Code_Constant_Find_IgnoreCase 0xedc8c。
 *   4. 旁证：AddStringConstant 0xf1748 是同一张表的「字符串值」入口（BString 0xdc308 → RValue → AddConstant），
 *      Code_Constant_Add 0xf1a10 / Code_Constant_Prepare 0xf1b44 是「从游戏数据灌入」的入口
 *      （Prepare 逐项取 names[i] / values[i] 两个并行 char* 数组）。本函数一条都不用 —— 它只装引擎自带的实数常量。
 *
 *   ⇒ 结论：**是 GML 常量池**（引擎侧 name→RValue 符号表），**不是 CCode 表**。
 *      CCode/字节码表在 DoCallGML/Code_Execute 那侧，本卡不覆盖。
 *
 * ── 条数（三个口径，别混）────────────────────────────────────────────────
 *   · 调用点：**513** 个 `bl 0xedff4`（本卡 513 行表逐条给出地址/名字/值）。
 *   · 不同名字：**501**（12 个 audio_* 各出现两次，见下）。
 *   · 运行期实际条数：**475 ~ 513**，取决于 5 个门控字节；门全开 513。
 *   · 启动期总量：513 + InitYoYoFunctionConstants 的 **93** = **606** 次 AddRealConstant。
 *
 * ── 七个无条件段（执行序，门全不开 = 475 条）────────────────────────────
 *   段1  0xee01c..0xee4e4   52 条  self..bm_src_alpha_sat（实例关键字 / true-false / pi / pr_* / c_* / bm_*）
 *   段2  0xee508..0xeef3c  112 条  audio_falloff_none..ev_trigger（audio / 图形 / ugc / gp / 文件 …）
 *   段3  0xeef5c..0xef000    8 条  ev_left_button..ev_left_release
 *   段4  0xef58c..0xefc0c   71 条  ev_right_release..ev_step_end
 *   段5  0xefc30..0xefd7c   15 条  ev_async..ty_string
 *   段6  0xefda8..0xf0478   77 条  fa_readonly..os_macosx
 *   段7  0xf04b0..0xf1134  140 条  os_ios..buffer_seek_end
 *   （52+112+8+71+15+77+140 = 475；段7 在表里显示 141，因为门5 的 os_psp 是**内联**插在它前面）
 *
 * ── 五个门（合计 +38，全开 513）───────────────────────────────────────────
 *   门址            取则   条数  内容
 *   0xee4f4 bne     加      6   tf_point / tf_linear / tf_anisotropic / mip_off / mip_on / mip_markedonly
 *   0xeef48 bne     加      3   ev_cleanup / ev_gesture / ev_pre_create
 *   0xefc18 bne     加     26   ev_gesture_* 全族
 *   0xefd90 beq     加      2   dll_cdecl / dll_stdcall
 *   0xf0484 bne     减      1   os_psp（取则**跳过**）
 *   五个门读的是同一套 `ldrb r3,[r4]`（r4 只在 0xee048 取一次，= *(GOT 0x3ee92c)），
 *   其中一个门（0xefd90）走另一条 GOT：0xefd80 ldr r3,[pc,#-0x960] → 0xefd84 ldr r3,[pc,r3] → *(GOT 0x3eddd8)。
 *
 * ── 值的形状（可用来交叉验算）──────────────────────────────────────────
 *   self=-1  other=-2  all=-3  noone=-4  global=-5  local=-7   ← **-6 空缺**（GM 一贯如此）
 *   true=1  false=0
 *   pi = 3.1415927410125732 = (double)(float)π   ← 不是 3.141592653589793；这条最能说明值是按 float 装的
 *   c_black=0  c_red=255  c_white=16777215  c_aqua=16776960  c_orange=4235519   ← BGR 整数
 *   ev_step=3  vk_nokey=0
 *   其余整数常量的值即枚举序；非整数只有 pi 一条。
 *
 * ── 12 条重名（audio_*，两套一模一样，两套相隔 0x2388 B）──────────────────
 *   audio_falloff_none / inverse_distance / inverse_distance_clamped / linear_distance /
 *   linear_distance_clamped / exponent_distance / exponent_distance_clamped /
 *   audio_old_system / audio_new_system / audio_mono / audio_stereo / audio_3d
 *   第一套 0xee508..0xee600（段2 开头），第二套 0xf0890..0xf0988（段7 内）。两套值完全相同。
 *
 * ── 代码布局（读索引时容易误判的地方）──────────────────────────────────
 *   0xef018 有一条 `b 0xef58c`，它跳过 0xef01c..0xef58c 的 **348 字名字偏移池**（每字是
 *   「相对 add r0,pc,r0 的偏移」，不是地址）。池之后的代码用**负** pc 偏移回指（如 0xefc1c
 *   `ldr r0,[pc,#-0x838]`）。所以索引里 0xef01c..0xef58c 那 348 行显示成 eoreq/mlaeq/.word 的
 *   全是数据，不是指令；本卡照样逐字落锚，但不计入控制流。
 *   同理尾部 0xf14ac..0xf1744 是另一段偏移池。
 *
 * ── 已证事实（节 1）────────────────────────────────────────────────────
 *   1. 513 个调用点全部 `bl 0xedff4`，实参形状固定：r0 = 名字串（`ldr r0,[pc,#imm]` + `add r0,pc,r0`），
 *      double 在 r2:r3（mov/movt 拼，softfp）。513/513 条的名字都能从 .rodata 解出可打印 ASCII，
 *      无一条落到非串地址 —— 这同时验证了 pc 相对寻址的解码没跑偏。
 *   2. 501 个不同名字；12 个 audio_* 各两次且**值完全相同**（0..6、0/1、0/1/2）。
 *   3. 7 段 475 条无条件 + 5 门 38 条；对 5 个门做 32 组取值穷举，实测计数区间恰为 475..513，
 *      与「门条数相加」一致（6+3+26+2+1 = 38）。
 *   4. 段1 的 52 条顺序与 GM 语义表一致：实例关键字 6 条 → true/false → pi → pr_* 6 条 →
 *      c_* 颜色 19 条 → bm_* 混合 18 条，末条 bm_src_alpha_sat。
 *   5. pi 的值是 float 精度：3.1415927410125732（0x400921FB60000000 → 若按 double 写应为 0x400921FB54442D18）。
 *   6. 函数末尾不是 return 而是 tail-call：0xf1138 `pop {r4, lr}` + 0xf113c `b 0x15d0f8`；
 *      InitYoYoFunctionConstants 里 93 个 bl 全打 AddRealConstant，首条 os_unknown=-1。
 *
 * ── open（节 1）────────────────────────────────────────────────────────
 *   1. 5 个门控字节的语义。r4 = *(GOT 0x3ee92c)；该槽是 R_ARM_RELATIVE（type 23），加数 0x11c470，
 *      而 0x11c470 正是 .dynsym 里 F_TileLayerShow 的值 —— 即静态看，这里读的是「某函数入口的首字节」。
 *      这不合理，只能是「加载期 GOT 被别的地址占位」或「该 addend 语义另有所指」；无符号可证，记 open。
 *   2. 12 条 audio_* 重名是否在表里留两条（取决于 0xd3a34 的插入语义：命中则覆盖还是追加），未展开。
 *   3. os_psp（0xf0498）在段6/段7 之间，门 0xf0484 取则跳过；为何单独摘出来未证。
 *   4. InitYoYoFunctionConstants 的 93 条只给到计数与前缀，未逐条落锚（它有自己的 index）。
 *   5. 各常量的版本归属（哪些是 GM:S 1.4 新增、哪些是 YYC/移动端专有）未做版本对照。
 *
 * ── 节 1 常量表：513 个调用点（地址 = bl 指令地址；名字取自 .rodata；值 = r2:r3 解出的 double）──
 *
 *   地址      名字                                       值
 *  [段1] n=52  0xee034..0xee4e4   self .. bm_src_alpha_sat
 *   0ee034  self                                     -1
 *   0ee04c  other                                    -2
 *   0ee064  all                                      -3
 *   0ee07c  noone                                    -4
 *   0ee094  global                                   -5
 *   0ee0ac  local                                    -7
 *   0ee0c4  true                                     1
 *   0ee0d8  false                                    0
 *   0ee0f0  pi                                       3.1415927410125732
 *   0ee108  pr_pointlist                             1
 *   0ee11c  pr_linelist                              2
 *   0ee134  pr_linestrip                             3
 *   0ee14c  pr_trianglelist                          4
 *   0ee164  pr_trianglestrip                         5
 *   0ee17c  pr_trianglefan                           6
 *   0ee194  c_aqua                                   16776960
 *   0ee1a8  c_black                                  0
 *   0ee1c0  c_blue                                   16711680
 *   0ee1d8  c_dkgray                                 4210752
 *   0ee1f0  c_fuchsia                                16711935
 *   0ee208  c_gray                                   8421504
 *   0ee220  c_green                                  32768
 *   0ee238  c_lime                                   65280
 *   0ee250  c_ltgray                                 12632256
 *   0ee268  c_maroon                                 128
 *   0ee280  c_navy                                   8388608
 *   0ee298  c_olive                                  32896
 *   0ee2b0  c_purple                                 8388736
 *   0ee2c8  c_red                                    255
 *   0ee2e0  c_silver                                 12632256
 *   0ee2f8  c_teal                                   8421376
 *   0ee310  c_white                                  16777215
 *   0ee328  c_yellow                                 65535
 *   0ee340  c_orange                                 4235519
 *   0ee354  bm_normal                                0
 *   0ee36c  bm_add                                   1
 *   0ee380  bm_max                                   2
 *   0ee398  bm_subtract                              3
 *   0ee3b0  bm_zero                                  1
 *   0ee3c4  bm_one                                   2
 *   0ee3dc  bm_src_color                             3
 *   0ee3f4  bm_src_colour                            3
 *   0ee40c  bm_inv_src_color                         4
 *   0ee424  bm_inv_src_colour                        4
 *   0ee43c  bm_src_alpha                             5
 *   0ee454  bm_inv_src_alpha                         6
 *   0ee46c  bm_dest_alpha                            7
 *   0ee484  bm_inv_dest_alpha                        8
 *   0ee49c  bm_dest_color                            9
 *   0ee4b4  bm_dest_colour                           9
 *   0ee4cc  bm_inv_dest_colour                       10
 *   0ee4e4  bm_src_alpha_sat                         11
 *  [门1] n=6  0xf1438..0xf14a4   tf_point .. mip_markedonly
 *   0f1438  tf_point                                 0
 *   0f1450  tf_linear                                1
 *   0f1464  tf_anisotropic                           2
 *   0f1478  mip_off                                  0
 *   0f1490  mip_on                                   1
 *   0f14a4  mip_markedonly                           2
 *  [段2] n=112  0xee508..0xeef3c   audio_falloff_none .. ev_trigger
 *   0ee508  audio_falloff_none                       0
 *   0ee520  audio_falloff_inverse_distance           1
 *   0ee534  audio_falloff_inverse_distance_clamped   2
 *   0ee54c  audio_falloff_linear_distance            3
 *   0ee564  audio_falloff_linear_distance_clamped    4
 *   0ee57c  audio_falloff_exponent_distance          5
 *   0ee594  audio_falloff_exponent_distance_clamped  6
 *   0ee5a8  audio_old_system                         0
 *   0ee5c0  audio_new_system                         1
 *   0ee5d4  audio_mono                               0
 *   0ee5ec  audio_stereo                             1
 *   0ee600  audio_3d                                 2
 *   0ee614  fa_left                                  0
 *   0ee62c  fa_center                                1
 *   0ee640  fa_right                                 2
 *   0ee654  fa_top                                   0
 *   0ee66c  fa_middle                                1
 *   0ee680  fa_bottom                                2
 *   0ee698  mb_any                                   -1
 *   0ee6ac  mb_none                                  0
 *   0ee6c4  mb_left                                  1
 *   0ee6d8  mb_right                                 2
 *   0ee6f0  mb_middle                                3
 *   0ee704  vk_nokey                                 0
 *   0ee71c  vk_anykey                                1
 *   0ee734  vk_enter                                 13
 *   0ee74c  vk_return                                13
 *   0ee764  vk_shift                                 16
 *   0ee77c  vk_control                               17
 *   0ee794  vk_alt                                   18
 *   0ee7ac  vk_escape                                27
 *   0ee7c4  vk_space                                 32
 *   0ee7dc  vk_backspace                             8
 *   0ee7f4  vk_tab                                   9
 *   0ee80c  vk_pause                                 19
 *   0ee824  vk_printscreen                           44
 *   0ee83c  vk_left                                  37
 *   0ee854  vk_right                                 39
 *   0ee86c  vk_up                                    38
 *   0ee884  vk_down                                  40
 *   0ee89c  vk_home                                  36
 *   0ee8b4  vk_end                                   35
 *   0ee8cc  vk_delete                                46
 *   0ee8e4  vk_insert                                45
 *   0ee8fc  vk_pageup                                33
 *   0ee914  vk_pagedown                              34
 *   0ee92c  vk_f1                                    112
 *   0ee944  vk_f2                                    113
 *   0ee95c  vk_f3                                    114
 *   0ee974  vk_f4                                    115
 *   0ee98c  vk_f5                                    116
 *   0ee9a4  vk_f6                                    117
 *   0ee9bc  vk_f7                                    118
 *   0ee9d4  vk_f8                                    119
 *   0ee9ec  vk_f9                                    120
 *   0eea04  vk_f10                                   121
 *   0eea1c  vk_f11                                   128
 *   0eea34  vk_f12                                   129
 *   0eea4c  vk_numpad0                               96
 *   0eea64  vk_numpad1                               97
 *   0eea7c  vk_numpad2                               98
 *   0eea94  vk_numpad3                               99
 *   0eeaac  vk_numpad4                               100
 *   0eeac4  vk_numpad5                               101
 *   0eeadc  vk_numpad6                               102
 *   0eeaf4  vk_numpad7                               103
 *   0eeb0c  vk_numpad8                               104
 *   0eeb24  vk_numpad9                               105
 *   0eeb3c  vk_divide                                111
 *   0eeb54  vk_multiply                              106
 *   0eeb6c  vk_subtract                              109
 *   0eeb84  vk_add                                   107
 *   0eeb9c  vk_decimal                               110
 *   0eebb4  vk_lshift                                160
 *   0eebcc  vk_lcontrol                              162
 *   0eebe4  vk_lalt                                  164
 *   0eebfc  vk_rshift                                161
 *   0eec14  vk_rcontrol                              163
 *   0eec2c  vk_ralt                                  165
 *   0eec44  gp_face1                                 32769
 *   0eec5c  gp_face2                                 32770
 *   0eec74  gp_face3                                 32771
 *   0eec8c  gp_face4                                 32772
 *   0eeca4  gp_shoulderl                             32773
 *   0eecbc  gp_shoulderr                             32774
 *   0eecd4  gp_shoulderlb                            32775
 *   0eecec  gp_shoulderrb                            32776
 *   0eed04  gp_select                                32777
 *   0eed1c  gp_start                                 32778
 *   0eed34  gp_stickl                                32779
 *   0eed4c  gp_stickr                                32780
 *   0eed64  gp_padu                                  32781
 *   0eed7c  gp_padd                                  32782
 *   0eed94  gp_padl                                  32783
 *   0eedac  gp_padr                                  32784
 *   0eedc4  gp_axislh                                32785
 *   0eeddc  gp_axislv                                32786
 *   0eedf4  gp_axisrh                                32787
 *   0eee0c  gp_axisrv                                32788
 *   0eee20  ev_create                                0
 *   0eee38  ev_destroy                               1
 *   0eee50  ev_clean_up                              12
 *   0eee68  ev_step                                  3
 *   0eee7c  ev_alarm                                 2
 *   0eee94  ev_keyboard                              5
 *   0eeeac  ev_mouse                                 6
 *   0eeec4  ev_collision                             4
 *   0eeedc  ev_other                                 7
 *   0eeef4  ev_draw                                  8
 *   0eef0c  ev_keypress                              9
 *   0eef24  ev_keyrelease                            10
 *   0eef3c  ev_trigger                               11
 *  [门2] n=3  0xf13f0..0xf1420   ev_cleanup .. ev_pre_create
 *   0f13f0  ev_cleanup                               12
 *   0f1408  ev_gesture                               13
 *   0f1420  ev_pre_create                            14
 *  [段3] n=8  0xeef5c..0xef000   ev_left_button .. ev_left_release
 *   0eef5c  ev_left_button                           0
 *   0eef74  ev_right_button                          1
 *   0eef88  ev_middle_button                         2
 *   0eefa0  ev_no_button                             3
 *   0eefb8  ev_left_press                            4
 *   0eefd0  ev_right_press                           5
 *   0eefe8  ev_middle_press                          6
 *   0ef000  ev_left_release                          7
 *  [段4] n=71  0xef58c..0xefc0c   ev_right_release .. ev_step_end
 *   0ef58c  ev_right_release                         8
 *   0ef5a4  ev_middle_release                        9
 *   0ef5bc  ev_mouse_enter                           10
 *   0ef5d4  ev_mouse_leave                           11
 *   0ef5ec  ev_global_press                          12
 *   0ef604  ev_global_release                        13
 *   0ef61c  ev_joystick1_left                        16
 *   0ef634  ev_joystick1_right                       17
 *   0ef64c  ev_joystick1_up                          18
 *   0ef664  ev_joystick1_down                        19
 *   0ef67c  ev_joystick1_button1                     21
 *   0ef694  ev_joystick1_button2                     22
 *   0ef6ac  ev_joystick1_button3                     23
 *   0ef6c4  ev_joystick1_button4                     24
 *   0ef6dc  ev_joystick1_button5                     25
 *   0ef6f4  ev_joystick1_button6                     26
 *   0ef70c  ev_joystick1_button7                     27
 *   0ef724  ev_joystick1_button8                     28
 *   0ef73c  ev_joystick2_left                        31
 *   0ef754  ev_joystick2_right                       32
 *   0ef76c  ev_joystick2_up                          33
 *   0ef784  ev_joystick2_down                        34
 *   0ef79c  ev_joystick2_button1                     36
 *   0ef7b4  ev_joystick2_button2                     37
 *   0ef7cc  ev_joystick2_button3                     38
 *   0ef7e4  ev_joystick2_button4                     39
 *   0ef7fc  ev_joystick2_button5                     40
 *   0ef814  ev_joystick2_button6                     41
 *   0ef82c  ev_joystick2_button7                     42
 *   0ef844  ev_joystick2_button8                     43
 *   0ef85c  ev_global_left_button                    50
 *   0ef874  ev_global_right_button                   51
 *   0ef88c  ev_global_middle_button                  52
 *   0ef8a4  ev_global_left_press                     53
 *   0ef8bc  ev_global_right_press                    54
 *   0ef8d4  ev_global_middle_press                   55
 *   0ef8ec  ev_global_left_release                   56
 *   0ef904  ev_global_right_release                  57
 *   0ef91c  ev_global_middle_release                 58
 *   0ef934  ev_mouse_wheel_up                        60
 *   0ef94c  ev_mouse_wheel_down                      61
 *   0ef960  ev_outside                               0
 *   0ef978  ev_boundary                              1
 *   0ef98c  ev_game_start                            2
 *   0ef9a4  ev_game_end                              3
 *   0ef9bc  ev_room_start                            4
 *   0ef9d4  ev_room_end                              5
 *   0ef9ec  ev_no_more_lives                         6
 *   0efa04  ev_animation_end                         7
 *   0efa1c  ev_end_of_path                           8
 *   0efa34  ev_no_more_health                        9
 *   0efa4c  ev_user0                                 10
 *   0efa64  ev_user1                                 11
 *   0efa7c  ev_user2                                 12
 *   0efa94  ev_user3                                 13
 *   0efaac  ev_user4                                 14
 *   0efac4  ev_user5                                 15
 *   0efadc  ev_user6                                 16
 *   0efaf4  ev_user7                                 17
 *   0efb0c  ev_user8                                 18
 *   0efb24  ev_user9                                 19
 *   0efb3c  ev_user10                                20
 *   0efb54  ev_user11                                21
 *   0efb6c  ev_user12                                22
 *   0efb84  ev_user13                                23
 *   0efb9c  ev_user14                                24
 *   0efbb4  ev_user15                                25
 *   0efbcc  ev_close_button                          30
 *   0efbe0  ev_step_normal                           0
 *   0efbf8  ev_step_begin                            1
 *   0efc0c  ev_step_end                              2
 *  [门3] n=26  0xf1180..0xf13d4   ev_gesture_tap .. ev_global_gesture_rotate_end
 *   0f1180  ev_gesture_tap                           0
 *   0f1198  ev_gesture_double_tap                    1
 *   0f11ac  ev_gesture_drag_start                    2
 *   0f11c4  ev_gesture_dragging                      3
 *   0f11dc  ev_gesture_drag_end                      4
 *   0f11f4  ev_gesture_flick                         5
 *   0f120c  ev_gesture_pinch_start                   6
 *   0f1224  ev_gesture_pinch_in                      7
 *   0f123c  ev_gesture_pinch_out                     8
 *   0f1254  ev_gesture_pinch_end                     9
 *   0f126c  ev_gesture_rotate_start                  10
 *   0f1284  ev_gesture_rotating                      11
 *   0f129c  ev_gesture_rotate_end                    12
 *   0f12b4  ev_global_gesture_tap                    64
 *   0f12cc  ev_global_gesture_double_tap             65
 *   0f12e4  ev_global_gesture_drag_start             66
 *   0f12fc  ev_global_gesture_dragging               67
 *   0f1314  ev_global_gesture_drag_end               68
 *   0f132c  ev_global_gesture_flick                  69
 *   0f1344  ev_global_gesture_pinch_start            70
 *   0f135c  ev_global_gesture_pinch_in               71
 *   0f1374  ev_global_gesture_pinch_out              72
 *   0f138c  ev_global_gesture_pinch_end              73
 *   0f13a4  ev_global_gesture_rotate_start           74
 *   0f13bc  ev_global_gesture_rotating               75
 *   0f13d4  ev_global_gesture_rotate_end             76
 *  [段5] n=15  0xefc30..0xefd7c   ev_async .. ty_string
 *   0efc30  ev_async                                 62
 *   0efc48  ev_dialog                                63
 *   0efc60  ev_gui                                   64
 *   0efc78  ev_iap                                   66
 *   0efc90  ev_cloud                                 67
 *   0efca8  ev_networking                            68
 *   0efcc0  ev_steam                                 69
 *   0efcd8  ev_social                                70
 *   0efcf0  ev_push_notification                     71
 *   0efd08  ev_save_load                             72
 *   0efd20  ev_audio_recording                       73
 *   0efd38  ev_audio_playback                        74
 *   0efd50  ev_system_event                          75
 *   0efd64  ty_real                                  0
 *   0efd7c  ty_string                                1
 *  [门4] n=2  0xf1150..0xf1168   dll_cdecl .. dll_stdcall
 *   0f1150  dll_cdecl                                0
 *   0f1168  dll_stdcall                              1
 *  [段6] n=77  0xefda8..0xf0478   fa_readonly .. os_macosx
 *   0efda8  fa_readonly                              1
 *   0efdbc  fa_hidden                                2
 *   0efdd4  fa_sysfile                               4
 *   0efdec  fa_volumeid                              8
 *   0efe04  fa_directory                             16
 *   0efe1c  fa_archive                               32
 *   0efe30  cr_default                               0
 *   0efe48  cr_none                                  -1
 *   0efe5c  cr_arrow                                 -2
 *   0efe74  cr_cross                                 -3
 *   0efe8c  cr_beam                                  -4
 *   0efea4  cr_size_nesw                             -6
 *   0efebc  cr_size_ns                               -7
 *   0efed4  cr_size_nwse                             -8
 *   0efeec  cr_size_we                               -9
 *   0eff04  cr_uparrow                               -10
 *   0eff1c  cr_hourglass                             -11
 *   0eff34  cr_drag                                  -12
 *   0eff4c  cr_nodrop                                -13
 *   0eff64  cr_hsplit                                -14
 *   0eff7c  cr_vsplit                                -15
 *   0eff94  cr_multidrag                             -16
 *   0effac  cr_sqlwait                               -17
 *   0effc4  cr_no                                    -18
 *   0effdc  cr_appstart                              -19
 *   0efff4  cr_help                                  -20
 *   0f000c  cr_handpoint                             -21
 *   0f0024  cr_size_all                              -22
 *   0f0038  pt_shape_pixel                           0
 *   0f0050  pt_shape_disk                            1
 *   0f0064  pt_shape_square                          2
 *   0f007c  pt_shape_line                            3
 *   0f0094  pt_shape_star                            4
 *   0f00ac  pt_shape_circle                          5
 *   0f00c4  pt_shape_ring                            6
 *   0f00dc  pt_shape_sphere                          7
 *   0f00f4  pt_shape_flare                           8
 *   0f010c  pt_shape_spark                           9
 *   0f0124  pt_shape_explosion                       10
 *   0f013c  pt_shape_cloud                           11
 *   0f0154  pt_shape_smoke                           12
 *   0f016c  pt_shape_snow                            13
 *   0f0180  ps_distr_linear                          0
 *   0f0198  ps_distr_gaussian                        1
 *   0f01ac  ps_distr_invgaussian                     2
 *   0f01c0  ps_shape_rectangle                       0
 *   0f01d8  ps_shape_ellipse                         1
 *   0f01ec  ps_shape_diamond                         2
 *   0f0204  ps_shape_line                            3
 *   0f0218  ps_force_constant                        0
 *   0f0230  ps_force_linear                          1
 *   0f0244  ps_force_quadratic                       2
 *   0f0258  ps_deflect_vertical                      0
 *   0f0270  ps_deflect_horizontal                    1
 *   0f0284  ps_change_all                            0
 *   0f029c  ps_change_shape                          1
 *   0f02b0  ps_change_motion                         2
 *   0f02c4  ef_explosion                             0
 *   0f02dc  ef_ring                                  1
 *   0f02f0  ef_ellipse                               2
 *   0f0308  ef_firework                              3
 *   0f0320  ef_smoke                                 4
 *   0f0338  ef_smokeup                               5
 *   0f0350  ef_star                                  6
 *   0f0368  ef_spark                                 7
 *   0f0380  ef_flare                                 8
 *   0f0398  ef_cloud                                 9
 *   0f03b0  ef_rain                                  10
 *   0f03c8  ef_snow                                  11
 *   0f03dc  display_landscape                        0
 *   0f03f4  display_portrait                         1
 *   0f0408  display_landscape_flipped                2
 *   0f0420  display_portrait_flipped                 3
 *   0f0438  os_unknown                               -1
 *   0f044c  os_win32                                 0
 *   0f0460  os_windows                               0
 *   0f0478  os_macosx                                1
 *  [段7（含门5 的 os_psp 1 条）] n=141  0xf0498..0xf1134   os_psp .. buffer_seek_end
 *   0f0498  os_psp                                   2
 *   0f04b0  os_ios                                   3
 *   0f04c8  os_android                               4
 *   0f04e0  os_symbian                               5
 *   0f04f8  os_linux                                 6
 *   0f0510  os_winphone                              7
 *   0f0528  os_tizen                                 8
 *   0f0540  os_win8native                            9
 *   0f0558  os_wiiu                                  10
 *   0f0570  os_3ds                                   11
 *   0f0588  os_psvita                                12
 *   0f05a0  os_bb10                                  13
 *   0f05b8  os_ps4                                   14
 *   0f05d0  os_xboxone                               15
 *   0f05e8  os_ps3                                   16
 *   0f0600  os_xbox360                               17
 *   0f0618  os_uwp                                   18
 *   0f062c  phy_joint_anchor_1_x                     0
 *   0f0644  phy_joint_anchor_1_y                     1
 *   0f0658  phy_joint_anchor_2_x                     2
 *   0f0670  phy_joint_anchor_2_y                     3
 *   0f0688  phy_joint_reaction_force_x               4
 *   0f06a0  phy_joint_reaction_force_y               5
 *   0f06b8  phy_joint_reaction_torque                6
 *   0f06d0  phy_joint_angle                          8
 *   0f06e8  phy_joint_motor_speed                    7
 *   0f0700  phy_joint_motor_torque                   9
 *   0f0718  phy_joint_max_motor_torque               10
 *   0f0730  phy_joint_translation                    11
 *   0f0748  phy_joint_speed                          12
 *   0f0760  phy_joint_motor_force                    13
 *   0f0778  phy_joint_max_motor_force                14
 *   0f0790  phy_joint_length_1                       15
 *   0f07a8  phy_joint_length_2                       16
 *   0f07c0  phy_joint_damping_ratio                  17
 *   0f07d8  phy_joint_frequency                      18
 *   0f07f0  phy_debug_render_shapes                  1
 *   0f0804  phy_debug_render_joints                  2
 *   0f081c  phy_debug_render_coms                    4
 *   0f0834  phy_debug_render_aabb                    8
 *   0f084c  phy_debug_render_obb                     16
 *   0f0864  phy_debug_render_core_shapes             32
 *   0f087c  phy_debug_render_collision_pairs         64
 *   0f0890  audio_falloff_none                       0
 *   0f08a8  audio_falloff_inverse_distance           1
 *   0f08bc  audio_falloff_inverse_distance_clamped   2
 *   0f08d4  audio_falloff_linear_distance            3
 *   0f08ec  audio_falloff_linear_distance_clamped    4
 *   0f0904  audio_falloff_exponent_distance          5
 *   0f091c  audio_falloff_exponent_distance_clamped  6
 *   0f0930  audio_old_system                         0
 *   0f0948  audio_new_system                         1
 *   0f095c  audio_mono                               0
 *   0f0974  audio_stereo                             1
 *   0f0988  audio_3d                                 2
 *   0f099c  matrix_view                              0
 *   0f09b4  matrix_projection                        1
 *   0f09c8  matrix_world                             2
 *   0f09dc  ov_friends                               0
 *   0f09f4  ov_community                             1
 *   0f0a08  ov_players                               2
 *   0f0a20  ov_settings                              3
 *   0f0a38  ov_gamegroup                             4
 *   0f0a50  ov_achievements                          5
 *   0f0a64  lb_sort_none                             0
 *   0f0a7c  lb_sort_ascending                        1
 *   0f0a90  lb_sort_descending                       2
 *   0f0aa4  lb_disp_none                             0
 *   0f0abc  lb_disp_numeric                          1
 *   0f0ad0  lb_disp_time_sec                         2
 *   0f0ae8  lb_disp_time_ms                          3
 *   0f0b00  ugc_result_success                       1
 *   0f0b14  ugc_filetype_community                   0
 *   0f0b2c  ugc_filetype_microtrans                  1
 *   0f0b40  ugc_visibility_public                    0
 *   0f0b58  ugc_visibility_friends_only              1
 *   0f0b6c  ugc_visibility_private                   2
 *   0f0b80  ugc_query_RankedByVote                   0
 *   0f0b98  ugc_query_RankedByPublicationDate        1
 *   0f0bac  ugc_query_AcceptedForGameRankedByAcceptanceDate 2
 *   0f0bc4  ugc_query_RankedByTrend                  3
 *   0f0bdc  ugc_query_FavoritedByFriendsRankedByPublicationDate 4
 *   0f0bf4  ugc_query_CreatedByFriendsRankedByPublicationDate 5
 *   0f0c0c  ugc_query_RankedByNumTimesReported       6
 *   0f0c24  ugc_query_CreatedByFollowedUsersRankedByPublicationDate 7
 *   0f0c3c  ugc_query_NotYetRated                    8
 *   0f0c54  ugc_query_RankedByTotalVotesAsc          9
 *   0f0c6c  ugc_query_RankedByVotesUp                10
 *   0f0c84  ugc_query_RankedByTextSearch             11
 *   0f0c98  ugc_sortorder_CreationOrderDesc          0
 *   0f0cb0  ugc_sortorder_CreationOrderAsc           1
 *   0f0cc4  ugc_sortorder_TitleAsc                   2
 *   0f0cdc  ugc_sortorder_LastUpdatedDesc            3
 *   0f0cf4  ugc_sortorder_SubscriptionDateDesc       4
 *   0f0d0c  ugc_sortorder_VoteScoreDesc              5
 *   0f0d24  ugc_sortorder_ForModeration              6
 *   0f0d38  ugc_list_Published                       0
 *   0f0d50  ugc_list_VotedOn                         1
 *   0f0d64  ugc_list_VotedUp                         2
 *   0f0d7c  ugc_list_VotedDown                       3
 *   0f0d94  ugc_list_WillVoteLater                   4
 *   0f0dac  ugc_list_Favorited                       5
 *   0f0dc4  ugc_list_Subscribed                      6
 *   0f0ddc  ugc_list_UsedOrPlayed                    7
 *   0f0df4  ugc_list_Followed                        8
 *   0f0e08  ugc_match_Items                          0
 *   0f0e20  ugc_match_Items_Mtx                      1
 *   0f0e34  ugc_match_Items_ReadyToUse               2
 *   0f0e4c  ugc_match_Collections                    3
 *   0f0e64  ugc_match_Artwork                        4
 *   0f0e7c  ugc_match_Videos                         5
 *   0f0e94  ugc_match_Screenshots                    6
 *   0f0eac  ugc_match_AllGuides                      7
 *   0f0ec4  ugc_match_WebGuides                      8
 *   0f0edc  ugc_match_IntegratedGuides               9
 *   0f0ef4  ugc_match_UsableInGame                   10
 *   0f0f0c  ugc_match_ControllerBindings             11
 *   0f0f20  timezone_local                           0
 *   0f0f38  timezone_utc                             1
 *   0f0f4c  buffer_fixed                             0
 *   0f0f64  buffer_grow                              1
 *   0f0f78  buffer_wrap                              2
 *   0f0f90  buffer_fast                              3
 *   0f0fa8  buffer_vbuffer                           4
 *   0f0fc0  buffer_network                           5
 *   0f0fd8  buffer_u8                                1
 *   0f0fec  buffer_s8                                2
 *   0f1004  buffer_u16                               3
 *   0f101c  buffer_s16                               4
 *   0f1034  buffer_u32                               5
 *   0f104c  buffer_s32                               6
 *   0f1064  buffer_f16                               7
 *   0f107c  buffer_f32                               8
 *   0f1094  buffer_f64                               9
 *   0f10ac  buffer_bool                              10
 *   0f10c4  buffer_string                            11
 *   0f10dc  buffer_u64                               12
 *   0f10f4  buffer_text                              13
 *   0f1108  buffer_seek_start                        0
 *   0f1120  buffer_seek_relative                     1
 *   0f1134  buffer_seek_end                          2
 *
 *   合计 513 条（不同名字 501，重名 12 组）。
 *
 * ── 节 1 逐条锚点（3531/3531；0xef01c..0xef58c 与 0xf14ac..0xf1744 是偏移池，同样逐字落锚）──
 */

/* @0xee01c ldr r0, [pc, #0xff8] */
/* @0xee020 mov r2, #0 */
/* @0xee024 push {r4, lr} */
/* @0xee028 add r0, pc, r0 */
/* @0xee02c mov r3, #0 */
/* @0xee030 movt r3, #0xbff0 */
/* @0xee034 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee038 ldr r0, [pc, #0xfe0] */
/* @0xee03c mov r2, #0 */
/* @0xee040 mov r3, #-1073741824 */
/* @0xee044 add r0, pc, r0 */
/* @0xee048 ldr r4, [pc, #0xfd4] */
/* @0xee04c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee050 ldr r0, [pc, #0xfd0] */
/* @0xee054 mov r2, #0 */
/* @0xee058 mov r3, #0 */
/* @0xee05c add r0, pc, r0 */
/* @0xee060 movt r3, #0xc008 */
/* @0xee064 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee068 ldr r0, [pc, #0xfbc] */
/* @0xee06c mov r2, #0 */
/* @0xee070 mov r3, #0 */
/* @0xee074 add r0, pc, r0 */
/* @0xee078 movt r3, #0xc010 */
/* @0xee07c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee080 ldr r0, [pc, #0xfa8] */
/* @0xee084 mov r2, #0 */
/* @0xee088 mov r3, #0 */
/* @0xee08c add r0, pc, r0 */
/* @0xee090 movt r3, #0xc014 */
/* @0xee094 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee098 ldr r0, [pc, #0xf94] */
/* @0xee09c mov r2, #0 */
/* @0xee0a0 mov r3, #0 */
/* @0xee0a4 add r0, pc, r0 */
/* @0xee0a8 movt r3, #0xc01c */
/* @0xee0ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee0b0 ldr r0, [pc, #0xf80] */
/* @0xee0b4 mov r2, #0 */
/* @0xee0b8 mov r3, #0 */
/* @0xee0bc add r0, pc, r0 */
/* @0xee0c0 movt r3, #0x3ff0 */
/* @0xee0c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee0c8 ldr r0, [pc, #0xf6c] */
/* @0xee0cc mov r2, #0 */
/* @0xee0d0 mov r3, #0 */
/* @0xee0d4 add r0, pc, r0 */
/* @0xee0d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee0dc ldr r0, [pc, #0xf5c] */
/* @0xee0e0 mov r2, #1610612736 */
/* @0xee0e4 movw r3, #0x21fb */
/* @0xee0e8 add r0, pc, r0 */
/* @0xee0ec movt r3, #0x4009 */
/* @0xee0f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee0f4 ldr r0, [pc, #0xf48] */
/* @0xee0f8 mov r2, #0 */
/* @0xee0fc mov r3, #0 */
/* @0xee100 add r0, pc, r0 */
/* @0xee104 movt r3, #0x3ff0 */
/* @0xee108 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee10c ldr r0, [pc, #0xf34] */
/* @0xee110 mov r2, #0 */
/* @0xee114 mov r3, #1073741824 */
/* @0xee118 add r0, pc, r0 */
/* @0xee11c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee120 ldr r0, [pc, #0xf24] */
/* @0xee124 mov r2, #0 */
/* @0xee128 mov r3, #0 */
/* @0xee12c add r0, pc, r0 */
/* @0xee130 movt r3, #0x4008 */
/* @0xee134 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee138 ldr r0, [pc, #0xf10] */
/* @0xee13c mov r2, #0 */
/* @0xee140 mov r3, #0 */
/* @0xee144 add r0, pc, r0 */
/* @0xee148 movt r3, #0x4010 */
/* @0xee14c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee150 ldr r0, [pc, #0xefc] */
/* @0xee154 mov r2, #0 */
/* @0xee158 mov r3, #0 */
/* @0xee15c add r0, pc, r0 */
/* @0xee160 movt r3, #0x4014 */
/* @0xee164 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee168 ldr r0, [pc, #0xee8] */
/* @0xee16c mov r2, #0 */
/* @0xee170 mov r3, #0 */
/* @0xee174 add r0, pc, r0 */
/* @0xee178 movt r3, #0x4018 */
/* @0xee17c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee180 ldr r0, [pc, #0xed4] */
/* @0xee184 mov r2, #0 */
/* @0xee188 movw r3, #0xffe0 */
/* @0xee18c add r0, pc, r0 */
/* @0xee190 movt r3, #0x416f */
/* @0xee194 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee198 ldr r0, [pc, #0xec0] */
/* @0xee19c mov r2, #0 */
/* @0xee1a0 mov r3, #0 */
/* @0xee1a4 add r0, pc, r0 */
/* @0xee1a8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee1ac ldr r0, [pc, #0xeb0] */
/* @0xee1b0 mov r2, #0 */
/* @0xee1b4 mov r3, #57344 */
/* @0xee1b8 add r0, pc, r0 */
/* @0xee1bc movt r3, #0x416f */
/* @0xee1c0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee1c4 ldr r0, [pc, #0xe9c] */
/* @0xee1c8 mov r2, #0 */
/* @0xee1cc movw r3, #0x1010 */
/* @0xee1d0 add r0, pc, r0 */
/* @0xee1d4 movt r3, #0x4150 */
/* @0xee1d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee1dc ldr r0, [pc, #0xe88] */
/* @0xee1e0 mov r2, #-536870912 */
/* @0xee1e4 movw r3, #0xe01f */
/* @0xee1e8 add r0, pc, r0 */
/* @0xee1ec movt r3, #0x416f */
/* @0xee1f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee1f4 ldr r0, [pc, #0xe74] */
/* @0xee1f8 mov r2, #0 */
/* @0xee1fc movw r3, #0x1010 */
/* @0xee200 add r0, pc, r0 */
/* @0xee204 movt r3, #0x4160 */
/* @0xee208 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee20c ldr r0, [pc, #0xe60] */
/* @0xee210 mov r2, #0 */
/* @0xee214 mov r3, #0 */
/* @0xee218 add r0, pc, r0 */
/* @0xee21c movt r3, #0x40e0 */
/* @0xee220 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee224 ldr r0, [pc, #0xe4c] */
/* @0xee228 mov r2, #0 */
/* @0xee22c mov r3, #57344 */
/* @0xee230 add r0, pc, r0 */
/* @0xee234 movt r3, #0x40ef */
/* @0xee238 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee23c ldr r0, [pc, #0xe38] */
/* @0xee240 mov r2, #0 */
/* @0xee244 movw r3, #0x1818 */
/* @0xee248 add r0, pc, r0 */
/* @0xee24c movt r3, #0x4168 */
/* @0xee250 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee254 ldr r0, [pc, #0xe24] */
/* @0xee258 mov r2, #0 */
/* @0xee25c mov r3, #0 */
/* @0xee260 add r0, pc, r0 */
/* @0xee264 movt r3, #0x4060 */
/* @0xee268 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee26c ldr r0, [pc, #0xe10] */
/* @0xee270 mov r2, #0 */
/* @0xee274 mov r3, #0 */
/* @0xee278 add r0, pc, r0 */
/* @0xee27c movt r3, #0x4160 */
/* @0xee280 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee284 ldr r0, [pc, #0xdfc] */
/* @0xee288 mov r2, #0 */
/* @0xee28c mov r3, #4096 */
/* @0xee290 add r0, pc, r0 */
/* @0xee294 movt r3, #0x40e0 */
/* @0xee298 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee29c ldr r0, [pc, #0xde8] */
/* @0xee2a0 mov r2, #0 */
/* @0xee2a4 mov r3, #16 */
/* @0xee2a8 add r0, pc, r0 */
/* @0xee2ac movt r3, #0x4160 */
/* @0xee2b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee2b4 ldr r0, [pc, #0xdd4] */
/* @0xee2b8 mov r2, #0 */
/* @0xee2bc mov r3, #57344 */
/* @0xee2c0 add r0, pc, r0 */
/* @0xee2c4 movt r3, #0x406f */
/* @0xee2c8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee2cc ldr r0, [pc, #0xdc0] */
/* @0xee2d0 mov r2, #0 */
/* @0xee2d4 movw r3, #0x1818 */
/* @0xee2d8 add r0, pc, r0 */
/* @0xee2dc movt r3, #0x4168 */
/* @0xee2e0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee2e4 ldr r0, [pc, #0xdac] */
/* @0xee2e8 mov r2, #0 */
/* @0xee2ec mov r3, #4096 */
/* @0xee2f0 add r0, pc, r0 */
/* @0xee2f4 movt r3, #0x4160 */
/* @0xee2f8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee2fc ldr r0, [pc, #0xd98] */
/* @0xee300 mov r2, #-536870912 */
/* @0xee304 movw r3, #0xffff */
/* @0xee308 add r0, pc, r0 */
/* @0xee30c movt r3, #0x416f */
/* @0xee310 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee314 ldr r0, [pc, #0xd84] */
/* @0xee318 mov r2, #0 */
/* @0xee31c movw r3, #0xffe0 */
/* @0xee320 add r0, pc, r0 */
/* @0xee324 movt r3, #0x40ef */
/* @0xee328 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee32c ldr r0, [pc, #0xd70] */
/* @0xee330 mov r2, #-1073741824 */
/* @0xee334 movw r3, #0x283f */
/* @0xee338 add r0, pc, r0 */
/* @0xee33c movt r3, #0x4150 */
/* @0xee340 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee344 ldr r0, [pc, #0xd5c] */
/* @0xee348 mov r2, #0 */
/* @0xee34c mov r3, #0 */
/* @0xee350 add r0, pc, r0 */
/* @0xee354 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee358 ldr r0, [pc, #0xd4c] */
/* @0xee35c mov r2, #0 */
/* @0xee360 mov r3, #0 */
/* @0xee364 add r0, pc, r0 */
/* @0xee368 movt r3, #0x3ff0 */
/* @0xee36c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee370 ldr r0, [pc, #0xd38] */
/* @0xee374 mov r2, #0 */
/* @0xee378 mov r3, #1073741824 */
/* @0xee37c add r0, pc, r0 */
/* @0xee380 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee384 ldr r0, [pc, #0xd28] */
/* @0xee388 mov r2, #0 */
/* @0xee38c mov r3, #0 */
/* @0xee390 add r0, pc, r0 */
/* @0xee394 movt r3, #0x4008 */
/* @0xee398 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee39c ldr r0, [pc, #0xd14] */
/* @0xee3a0 mov r2, #0 */
/* @0xee3a4 mov r3, #0 */
/* @0xee3a8 add r0, pc, r0 */
/* @0xee3ac movt r3, #0x3ff0 */
/* @0xee3b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee3b4 ldr r0, [pc, #0xd00] */
/* @0xee3b8 mov r2, #0 */
/* @0xee3bc mov r3, #1073741824 */
/* @0xee3c0 add r0, pc, r0 */
/* @0xee3c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee3c8 ldr r0, [pc, #0xcf0] */
/* @0xee3cc mov r2, #0 */
/* @0xee3d0 mov r3, #0 */
/* @0xee3d4 add r0, pc, r0 */
/* @0xee3d8 movt r3, #0x4008 */
/* @0xee3dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee3e0 ldr r0, [pc, #0xcdc] */
/* @0xee3e4 mov r2, #0 */
/* @0xee3e8 mov r3, #0 */
/* @0xee3ec add r0, pc, r0 */
/* @0xee3f0 movt r3, #0x4008 */
/* @0xee3f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee3f8 ldr r0, [pc, #0xcc8] */
/* @0xee3fc mov r2, #0 */
/* @0xee400 mov r3, #0 */
/* @0xee404 add r0, pc, r0 */
/* @0xee408 movt r3, #0x4010 */
/* @0xee40c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee410 ldr r0, [pc, #0xcb4] */
/* @0xee414 mov r2, #0 */
/* @0xee418 mov r3, #0 */
/* @0xee41c add r0, pc, r0 */
/* @0xee420 movt r3, #0x4010 */
/* @0xee424 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee428 ldr r0, [pc, #0xca0] */
/* @0xee42c mov r2, #0 */
/* @0xee430 mov r3, #0 */
/* @0xee434 add r0, pc, r0 */
/* @0xee438 movt r3, #0x4014 */
/* @0xee43c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee440 ldr r0, [pc, #0xc8c] */
/* @0xee444 mov r2, #0 */
/* @0xee448 mov r3, #0 */
/* @0xee44c add r0, pc, r0 */
/* @0xee450 movt r3, #0x4018 */
/* @0xee454 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee458 ldr r0, [pc, #0xc78] */
/* @0xee45c mov r2, #0 */
/* @0xee460 mov r3, #0 */
/* @0xee464 add r0, pc, r0 */
/* @0xee468 movt r3, #0x401c */
/* @0xee46c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee470 ldr r0, [pc, #0xc64] */
/* @0xee474 mov r2, #0 */
/* @0xee478 mov r3, #0 */
/* @0xee47c add r0, pc, r0 */
/* @0xee480 movt r3, #0x4020 */
/* @0xee484 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee488 ldr r0, [pc, #0xc50] */
/* @0xee48c mov r2, #0 */
/* @0xee490 mov r3, #0 */
/* @0xee494 add r0, pc, r0 */
/* @0xee498 movt r3, #0x4022 */
/* @0xee49c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee4a0 ldr r0, [pc, #0xc3c] */
/* @0xee4a4 mov r2, #0 */
/* @0xee4a8 mov r3, #0 */
/* @0xee4ac add r0, pc, r0 */
/* @0xee4b0 movt r3, #0x4022 */
/* @0xee4b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee4b8 ldr r0, [pc, #0xc28] */
/* @0xee4bc mov r2, #0 */
/* @0xee4c0 mov r3, #0 */
/* @0xee4c4 add r0, pc, r0 */
/* @0xee4c8 movt r3, #0x4024 */
/* @0xee4cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee4d0 ldr r0, [pc, #0xc14] */
/* @0xee4d4 mov r2, #0 */
/* @0xee4d8 mov r3, #0 */
/* @0xee4dc add r0, pc, r0 */
/* @0xee4e0 movt r3, #0x4026 */
/* @0xee4e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee4e8 ldr r4, [pc, r4] */
/* @0xee4ec ldrb r3, [r4] */
/* @0xee4f0 cmp r3, #0 */
/* @0xee4f4 bne 0xf1428 <_Z24INITIALIZE_Code_Constantv+0x340c> */
/* @0xee4f8 ldr r0, [pc, #0xbf0] */
/* @0xee4fc mov r2, #0 */
/* @0xee500 mov r3, #0 */
/* @0xee504 add r0, pc, r0 */
/* @0xee508 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee50c ldr r0, [pc, #0xbe0] */
/* @0xee510 mov r2, #0 */
/* @0xee514 mov r3, #0 */
/* @0xee518 add r0, pc, r0 */
/* @0xee51c movt r3, #0x3ff0 */
/* @0xee520 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee524 ldr r0, [pc, #0xbcc] */
/* @0xee528 mov r2, #0 */
/* @0xee52c mov r3, #1073741824 */
/* @0xee530 add r0, pc, r0 */
/* @0xee534 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee538 ldr r0, [pc, #0xbbc] */
/* @0xee53c mov r2, #0 */
/* @0xee540 mov r3, #0 */
/* @0xee544 add r0, pc, r0 */
/* @0xee548 movt r3, #0x4008 */
/* @0xee54c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee550 ldr r0, [pc, #0xba8] */
/* @0xee554 mov r2, #0 */
/* @0xee558 mov r3, #0 */
/* @0xee55c add r0, pc, r0 */
/* @0xee560 movt r3, #0x4010 */
/* @0xee564 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee568 ldr r0, [pc, #0xb94] */
/* @0xee56c mov r2, #0 */
/* @0xee570 mov r3, #0 */
/* @0xee574 add r0, pc, r0 */
/* @0xee578 movt r3, #0x4014 */
/* @0xee57c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee580 ldr r0, [pc, #0xb80] */
/* @0xee584 mov r2, #0 */
/* @0xee588 mov r3, #0 */
/* @0xee58c add r0, pc, r0 */
/* @0xee590 movt r3, #0x4018 */
/* @0xee594 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee598 ldr r0, [pc, #0xb6c] */
/* @0xee59c mov r2, #0 */
/* @0xee5a0 mov r3, #0 */
/* @0xee5a4 add r0, pc, r0 */
/* @0xee5a8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee5ac ldr r0, [pc, #0xb5c] */
/* @0xee5b0 mov r2, #0 */
/* @0xee5b4 mov r3, #0 */
/* @0xee5b8 add r0, pc, r0 */
/* @0xee5bc movt r3, #0x3ff0 */
/* @0xee5c0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee5c4 ldr r0, [pc, #0xb48] */
/* @0xee5c8 mov r2, #0 */
/* @0xee5cc mov r3, #0 */
/* @0xee5d0 add r0, pc, r0 */
/* @0xee5d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee5d8 ldr r0, [pc, #0xb38] */
/* @0xee5dc mov r2, #0 */
/* @0xee5e0 mov r3, #0 */
/* @0xee5e4 add r0, pc, r0 */
/* @0xee5e8 movt r3, #0x3ff0 */
/* @0xee5ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee5f0 ldr r0, [pc, #0xb24] */
/* @0xee5f4 mov r2, #0 */
/* @0xee5f8 mov r3, #1073741824 */
/* @0xee5fc add r0, pc, r0 */
/* @0xee600 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee604 ldr r0, [pc, #0xb14] */
/* @0xee608 mov r2, #0 */
/* @0xee60c mov r3, #0 */
/* @0xee610 add r0, pc, r0 */
/* @0xee614 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee618 ldr r0, [pc, #0xb04] */
/* @0xee61c mov r2, #0 */
/* @0xee620 mov r3, #0 */
/* @0xee624 add r0, pc, r0 */
/* @0xee628 movt r3, #0x3ff0 */
/* @0xee62c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee630 ldr r0, [pc, #0xaf0] */
/* @0xee634 mov r2, #0 */
/* @0xee638 mov r3, #1073741824 */
/* @0xee63c add r0, pc, r0 */
/* @0xee640 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee644 ldr r0, [pc, #0xae0] */
/* @0xee648 mov r2, #0 */
/* @0xee64c mov r3, #0 */
/* @0xee650 add r0, pc, r0 */
/* @0xee654 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee658 ldr r0, [pc, #0xad0] */
/* @0xee65c mov r2, #0 */
/* @0xee660 mov r3, #0 */
/* @0xee664 add r0, pc, r0 */
/* @0xee668 movt r3, #0x3ff0 */
/* @0xee66c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee670 ldr r0, [pc, #0xabc] */
/* @0xee674 mov r2, #0 */
/* @0xee678 mov r3, #1073741824 */
/* @0xee67c add r0, pc, r0 */
/* @0xee680 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee684 ldr r0, [pc, #0xaac] */
/* @0xee688 mov r2, #0 */
/* @0xee68c mov r3, #0 */
/* @0xee690 add r0, pc, r0 */
/* @0xee694 movt r3, #0xbff0 */
/* @0xee698 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee69c ldr r0, [pc, #0xa98] */
/* @0xee6a0 mov r2, #0 */
/* @0xee6a4 mov r3, #0 */
/* @0xee6a8 add r0, pc, r0 */
/* @0xee6ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee6b0 ldr r0, [pc, #0xa88] */
/* @0xee6b4 mov r2, #0 */
/* @0xee6b8 mov r3, #0 */
/* @0xee6bc add r0, pc, r0 */
/* @0xee6c0 movt r3, #0x3ff0 */
/* @0xee6c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee6c8 ldr r0, [pc, #0xa74] */
/* @0xee6cc mov r2, #0 */
/* @0xee6d0 mov r3, #1073741824 */
/* @0xee6d4 add r0, pc, r0 */
/* @0xee6d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee6dc ldr r0, [pc, #0xa64] */
/* @0xee6e0 mov r2, #0 */
/* @0xee6e4 mov r3, #0 */
/* @0xee6e8 add r0, pc, r0 */
/* @0xee6ec movt r3, #0x4008 */
/* @0xee6f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee6f4 ldr r0, [pc, #0xa50] */
/* @0xee6f8 mov r2, #0 */
/* @0xee6fc mov r3, #0 */
/* @0xee700 add r0, pc, r0 */
/* @0xee704 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee708 ldr r0, [pc, #0xa40] */
/* @0xee70c mov r2, #0 */
/* @0xee710 mov r3, #0 */
/* @0xee714 add r0, pc, r0 */
/* @0xee718 movt r3, #0x3ff0 */
/* @0xee71c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee720 ldr r0, [pc, #0xa2c] */
/* @0xee724 mov r2, #0 */
/* @0xee728 mov r3, #0 */
/* @0xee72c add r0, pc, r0 */
/* @0xee730 movt r3, #0x402a */
/* @0xee734 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee738 ldr r0, [pc, #0xa18] */
/* @0xee73c mov r2, #0 */
/* @0xee740 mov r3, #0 */
/* @0xee744 add r0, pc, r0 */
/* @0xee748 movt r3, #0x402a */
/* @0xee74c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee750 ldr r0, [pc, #0xa04] */
/* @0xee754 mov r2, #0 */
/* @0xee758 mov r3, #0 */
/* @0xee75c add r0, pc, r0 */
/* @0xee760 movt r3, #0x4030 */
/* @0xee764 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee768 ldr r0, [pc, #0x9f0] */
/* @0xee76c mov r2, #0 */
/* @0xee770 mov r3, #0 */
/* @0xee774 add r0, pc, r0 */
/* @0xee778 movt r3, #0x4031 */
/* @0xee77c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee780 ldr r0, [pc, #0x9dc] */
/* @0xee784 mov r2, #0 */
/* @0xee788 mov r3, #0 */
/* @0xee78c add r0, pc, r0 */
/* @0xee790 movt r3, #0x4032 */
/* @0xee794 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee798 ldr r0, [pc, #0x9c8] */
/* @0xee79c mov r2, #0 */
/* @0xee7a0 mov r3, #0 */
/* @0xee7a4 add r0, pc, r0 */
/* @0xee7a8 movt r3, #0x403b */
/* @0xee7ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee7b0 ldr r0, [pc, #0x9b4] */
/* @0xee7b4 mov r2, #0 */
/* @0xee7b8 mov r3, #0 */
/* @0xee7bc add r0, pc, r0 */
/* @0xee7c0 movt r3, #0x4040 */
/* @0xee7c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee7c8 ldr r0, [pc, #0x9a0] */
/* @0xee7cc mov r2, #0 */
/* @0xee7d0 mov r3, #0 */
/* @0xee7d4 add r0, pc, r0 */
/* @0xee7d8 movt r3, #0x4020 */
/* @0xee7dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee7e0 ldr r0, [pc, #0x98c] */
/* @0xee7e4 mov r2, #0 */
/* @0xee7e8 mov r3, #0 */
/* @0xee7ec add r0, pc, r0 */
/* @0xee7f0 movt r3, #0x4022 */
/* @0xee7f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee7f8 ldr r0, [pc, #0x978] */
/* @0xee7fc mov r2, #0 */
/* @0xee800 mov r3, #0 */
/* @0xee804 add r0, pc, r0 */
/* @0xee808 movt r3, #0x4033 */
/* @0xee80c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee810 ldr r0, [pc, #0x964] */
/* @0xee814 mov r2, #0 */
/* @0xee818 mov r3, #0 */
/* @0xee81c add r0, pc, r0 */
/* @0xee820 movt r3, #0x4046 */
/* @0xee824 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee828 ldr r0, [pc, #0x950] */
/* @0xee82c mov r2, #0 */
/* @0xee830 mov r3, #32768 */
/* @0xee834 add r0, pc, r0 */
/* @0xee838 movt r3, #0x4042 */
/* @0xee83c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee840 ldr r0, [pc, #0x93c] */
/* @0xee844 mov r2, #0 */
/* @0xee848 mov r3, #32768 */
/* @0xee84c add r0, pc, r0 */
/* @0xee850 movt r3, #0x4043 */
/* @0xee854 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee858 ldr r0, [pc, #0x928] */
/* @0xee85c mov r2, #0 */
/* @0xee860 mov r3, #0 */
/* @0xee864 add r0, pc, r0 */
/* @0xee868 movt r3, #0x4043 */
/* @0xee86c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee870 ldr r0, [pc, #0x914] */
/* @0xee874 mov r2, #0 */
/* @0xee878 mov r3, #0 */
/* @0xee87c add r0, pc, r0 */
/* @0xee880 movt r3, #0x4044 */
/* @0xee884 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee888 ldr r0, [pc, #0x900] */
/* @0xee88c mov r2, #0 */
/* @0xee890 mov r3, #0 */
/* @0xee894 add r0, pc, r0 */
/* @0xee898 movt r3, #0x4042 */
/* @0xee89c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee8a0 ldr r0, [pc, #0x8ec] */
/* @0xee8a4 mov r2, #0 */
/* @0xee8a8 mov r3, #32768 */
/* @0xee8ac add r0, pc, r0 */
/* @0xee8b0 movt r3, #0x4041 */
/* @0xee8b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee8b8 ldr r0, [pc, #0x8d8] */
/* @0xee8bc mov r2, #0 */
/* @0xee8c0 mov r3, #0 */
/* @0xee8c4 add r0, pc, r0 */
/* @0xee8c8 movt r3, #0x4047 */
/* @0xee8cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee8d0 ldr r0, [pc, #0x8c4] */
/* @0xee8d4 mov r2, #0 */
/* @0xee8d8 mov r3, #32768 */
/* @0xee8dc add r0, pc, r0 */
/* @0xee8e0 movt r3, #0x4046 */
/* @0xee8e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee8e8 ldr r0, [pc, #0x8b0] */
/* @0xee8ec mov r2, #0 */
/* @0xee8f0 mov r3, #32768 */
/* @0xee8f4 add r0, pc, r0 */
/* @0xee8f8 movt r3, #0x4040 */
/* @0xee8fc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee900 ldr r0, [pc, #0x89c] */
/* @0xee904 mov r2, #0 */
/* @0xee908 mov r3, #0 */
/* @0xee90c add r0, pc, r0 */
/* @0xee910 movt r3, #0x4041 */
/* @0xee914 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee918 ldr r0, [pc, #0x888] */
/* @0xee91c mov r2, #0 */
/* @0xee920 mov r3, #0 */
/* @0xee924 add r0, pc, r0 */
/* @0xee928 movt r3, #0x405c */
/* @0xee92c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee930 ldr r0, [pc, #0x874] */
/* @0xee934 mov r2, #0 */
/* @0xee938 mov r3, #16384 */
/* @0xee93c add r0, pc, r0 */
/* @0xee940 movt r3, #0x405c */
/* @0xee944 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee948 ldr r0, [pc, #0x860] */
/* @0xee94c mov r2, #0 */
/* @0xee950 mov r3, #32768 */
/* @0xee954 add r0, pc, r0 */
/* @0xee958 movt r3, #0x405c */
/* @0xee95c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee960 ldr r0, [pc, #0x84c] */
/* @0xee964 mov r2, #0 */
/* @0xee968 mov r3, #49152 */
/* @0xee96c add r0, pc, r0 */
/* @0xee970 movt r3, #0x405c */
/* @0xee974 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee978 ldr r0, [pc, #0x838] */
/* @0xee97c mov r2, #0 */
/* @0xee980 mov r3, #0 */
/* @0xee984 add r0, pc, r0 */
/* @0xee988 movt r3, #0x405d */
/* @0xee98c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee990 ldr r0, [pc, #0x824] */
/* @0xee994 mov r2, #0 */
/* @0xee998 mov r3, #16384 */
/* @0xee99c add r0, pc, r0 */
/* @0xee9a0 movt r3, #0x405d */
/* @0xee9a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee9a8 ldr r0, [pc, #0x810] */
/* @0xee9ac mov r2, #0 */
/* @0xee9b0 mov r3, #32768 */
/* @0xee9b4 add r0, pc, r0 */
/* @0xee9b8 movt r3, #0x405d */
/* @0xee9bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee9c0 ldr r0, [pc, #0x7fc] */
/* @0xee9c4 mov r2, #0 */
/* @0xee9c8 mov r3, #49152 */
/* @0xee9cc add r0, pc, r0 */
/* @0xee9d0 movt r3, #0x405d */
/* @0xee9d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee9d8 ldr r0, [pc, #0x7e8] */
/* @0xee9dc mov r2, #0 */
/* @0xee9e0 mov r3, #0 */
/* @0xee9e4 add r0, pc, r0 */
/* @0xee9e8 movt r3, #0x405e */
/* @0xee9ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee9f0 ldr r0, [pc, #0x7d4] */
/* @0xee9f4 mov r2, #0 */
/* @0xee9f8 mov r3, #16384 */
/* @0xee9fc add r0, pc, r0 */
/* @0xeea00 movt r3, #0x405e */
/* @0xeea04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea08 ldr r0, [pc, #0x7c0] */
/* @0xeea0c mov r2, #0 */
/* @0xeea10 mov r3, #0 */
/* @0xeea14 add r0, pc, r0 */
/* @0xeea18 movt r3, #0x4060 */
/* @0xeea1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea20 ldr r0, [pc, #0x7ac] */
/* @0xeea24 mov r2, #0 */
/* @0xeea28 mov r3, #8192 */
/* @0xeea2c add r0, pc, r0 */
/* @0xeea30 movt r3, #0x4060 */
/* @0xeea34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea38 ldr r0, [pc, #0x798] */
/* @0xeea3c mov r2, #0 */
/* @0xeea40 mov r3, #0 */
/* @0xeea44 add r0, pc, r0 */
/* @0xeea48 movt r3, #0x4058 */
/* @0xeea4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea50 ldr r0, [pc, #0x784] */
/* @0xeea54 mov r2, #0 */
/* @0xeea58 mov r3, #16384 */
/* @0xeea5c add r0, pc, r0 */
/* @0xeea60 movt r3, #0x4058 */
/* @0xeea64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea68 ldr r0, [pc, #0x770] */
/* @0xeea6c mov r2, #0 */
/* @0xeea70 mov r3, #32768 */
/* @0xeea74 add r0, pc, r0 */
/* @0xeea78 movt r3, #0x4058 */
/* @0xeea7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea80 ldr r0, [pc, #0x75c] */
/* @0xeea84 mov r2, #0 */
/* @0xeea88 mov r3, #49152 */
/* @0xeea8c add r0, pc, r0 */
/* @0xeea90 movt r3, #0x4058 */
/* @0xeea94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea98 ldr r0, [pc, #0x748] */
/* @0xeea9c mov r2, #0 */
/* @0xeeaa0 mov r3, #0 */
/* @0xeeaa4 add r0, pc, r0 */
/* @0xeeaa8 movt r3, #0x4059 */
/* @0xeeaac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeab0 ldr r0, [pc, #0x734] */
/* @0xeeab4 mov r2, #0 */
/* @0xeeab8 mov r3, #16384 */
/* @0xeeabc add r0, pc, r0 */
/* @0xeeac0 movt r3, #0x4059 */
/* @0xeeac4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeac8 ldr r0, [pc, #0x720] */
/* @0xeeacc mov r2, #0 */
/* @0xeead0 mov r3, #32768 */
/* @0xeead4 add r0, pc, r0 */
/* @0xeead8 movt r3, #0x4059 */
/* @0xeeadc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeae0 ldr r0, [pc, #0x70c] */
/* @0xeeae4 mov r2, #0 */
/* @0xeeae8 mov r3, #49152 */
/* @0xeeaec add r0, pc, r0 */
/* @0xeeaf0 movt r3, #0x4059 */
/* @0xeeaf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeaf8 ldr r0, [pc, #0x6f8] */
/* @0xeeafc mov r2, #0 */
/* @0xeeb00 mov r3, #0 */
/* @0xeeb04 add r0, pc, r0 */
/* @0xeeb08 movt r3, #0x405a */
/* @0xeeb0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb10 ldr r0, [pc, #0x6e4] */
/* @0xeeb14 mov r2, #0 */
/* @0xeeb18 mov r3, #16384 */
/* @0xeeb1c add r0, pc, r0 */
/* @0xeeb20 movt r3, #0x405a */
/* @0xeeb24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb28 ldr r0, [pc, #0x6d0] */
/* @0xeeb2c mov r2, #0 */
/* @0xeeb30 mov r3, #49152 */
/* @0xeeb34 add r0, pc, r0 */
/* @0xeeb38 movt r3, #0x405b */
/* @0xeeb3c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb40 ldr r0, [pc, #0x6bc] */
/* @0xeeb44 mov r2, #0 */
/* @0xeeb48 mov r3, #32768 */
/* @0xeeb4c add r0, pc, r0 */
/* @0xeeb50 movt r3, #0x405a */
/* @0xeeb54 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb58 ldr r0, [pc, #0x6a8] */
/* @0xeeb5c mov r2, #0 */
/* @0xeeb60 mov r3, #16384 */
/* @0xeeb64 add r0, pc, r0 */
/* @0xeeb68 movt r3, #0x405b */
/* @0xeeb6c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb70 ldr r0, [pc, #0x694] */
/* @0xeeb74 mov r2, #0 */
/* @0xeeb78 mov r3, #49152 */
/* @0xeeb7c add r0, pc, r0 */
/* @0xeeb80 movt r3, #0x405a */
/* @0xeeb84 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb88 ldr r0, [pc, #0x680] */
/* @0xeeb8c mov r2, #0 */
/* @0xeeb90 mov r3, #32768 */
/* @0xeeb94 add r0, pc, r0 */
/* @0xeeb98 movt r3, #0x405b */
/* @0xeeb9c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeba0 ldr r0, [pc, #0x66c] */
/* @0xeeba4 mov r2, #0 */
/* @0xeeba8 mov r3, #0 */
/* @0xeebac add r0, pc, r0 */
/* @0xeebb0 movt r3, #0x4064 */
/* @0xeebb4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeebb8 ldr r0, [pc, #0x658] */
/* @0xeebbc mov r2, #0 */
/* @0xeebc0 mov r3, #16384 */
/* @0xeebc4 add r0, pc, r0 */
/* @0xeebc8 movt r3, #0x4064 */
/* @0xeebcc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeebd0 ldr r0, [pc, #0x644] */
/* @0xeebd4 mov r2, #0 */
/* @0xeebd8 mov r3, #32768 */
/* @0xeebdc add r0, pc, r0 */
/* @0xeebe0 movt r3, #0x4064 */
/* @0xeebe4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeebe8 ldr r0, [pc, #0x630] */
/* @0xeebec mov r2, #0 */
/* @0xeebf0 mov r3, #8192 */
/* @0xeebf4 add r0, pc, r0 */
/* @0xeebf8 movt r3, #0x4064 */
/* @0xeebfc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec00 ldr r0, [pc, #0x61c] */
/* @0xeec04 mov r2, #0 */
/* @0xeec08 mov r3, #24576 */
/* @0xeec0c add r0, pc, r0 */
/* @0xeec10 movt r3, #0x4064 */
/* @0xeec14 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec18 ldr r0, [pc, #0x608] */
/* @0xeec1c mov r2, #0 */
/* @0xeec20 mov r3, #40960 */
/* @0xeec24 add r0, pc, r0 */
/* @0xeec28 movt r3, #0x4064 */
/* @0xeec2c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec30 ldr r0, [pc, #0x5f4] */
/* @0xeec34 mov r2, #0 */
/* @0xeec38 mov r3, #32 */
/* @0xeec3c add r0, pc, r0 */
/* @0xeec40 movt r3, #0x40e0 */
/* @0xeec44 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec48 ldr r0, [pc, #0x5e0] */
/* @0xeec4c mov r2, #0 */
/* @0xeec50 mov r3, #64 */
/* @0xeec54 add r0, pc, r0 */
/* @0xeec58 movt r3, #0x40e0 */
/* @0xeec5c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec60 ldr r0, [pc, #0x5cc] */
/* @0xeec64 mov r2, #0 */
/* @0xeec68 mov r3, #96 */
/* @0xeec6c add r0, pc, r0 */
/* @0xeec70 movt r3, #0x40e0 */
/* @0xeec74 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec78 ldr r0, [pc, #0x5b8] */
/* @0xeec7c mov r2, #0 */
/* @0xeec80 mov r3, #128 */
/* @0xeec84 add r0, pc, r0 */
/* @0xeec88 movt r3, #0x40e0 */
/* @0xeec8c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec90 ldr r0, [pc, #0x5a4] */
/* @0xeec94 mov r2, #0 */
/* @0xeec98 mov r3, #160 */
/* @0xeec9c add r0, pc, r0 */
/* @0xeeca0 movt r3, #0x40e0 */
/* @0xeeca4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeca8 ldr r0, [pc, #0x590] */
/* @0xeecac mov r2, #0 */
/* @0xeecb0 mov r3, #192 */
/* @0xeecb4 add r0, pc, r0 */
/* @0xeecb8 movt r3, #0x40e0 */
/* @0xeecbc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeecc0 ldr r0, [pc, #0x57c] */
/* @0xeecc4 mov r2, #0 */
/* @0xeecc8 mov r3, #224 */
/* @0xeeccc add r0, pc, r0 */
/* @0xeecd0 movt r3, #0x40e0 */
/* @0xeecd4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeecd8 ldr r0, [pc, #0x568] */
/* @0xeecdc mov r2, #0 */
/* @0xeece0 mov r3, #256 */
/* @0xeece4 add r0, pc, r0 */
/* @0xeece8 movt r3, #0x40e0 */
/* @0xeecec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeecf0 ldr r0, [pc, #0x554] */
/* @0xeecf4 mov r2, #0 */
/* @0xeecf8 mov r3, #288 */
/* @0xeecfc add r0, pc, r0 */
/* @0xeed00 movt r3, #0x40e0 */
/* @0xeed04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed08 ldr r0, [pc, #0x540] */
/* @0xeed0c mov r2, #0 */
/* @0xeed10 mov r3, #320 */
/* @0xeed14 add r0, pc, r0 */
/* @0xeed18 movt r3, #0x40e0 */
/* @0xeed1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed20 ldr r0, [pc, #0x52c] */
/* @0xeed24 mov r2, #0 */
/* @0xeed28 mov r3, #352 */
/* @0xeed2c add r0, pc, r0 */
/* @0xeed30 movt r3, #0x40e0 */
/* @0xeed34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed38 ldr r0, [pc, #0x518] */
/* @0xeed3c mov r2, #0 */
/* @0xeed40 mov r3, #384 */
/* @0xeed44 add r0, pc, r0 */
/* @0xeed48 movt r3, #0x40e0 */
/* @0xeed4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed50 ldr r0, [pc, #0x504] */
/* @0xeed54 mov r2, #0 */
/* @0xeed58 mov r3, #416 */
/* @0xeed5c add r0, pc, r0 */
/* @0xeed60 movt r3, #0x40e0 */
/* @0xeed64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed68 ldr r0, [pc, #0x4f0] */
/* @0xeed6c mov r2, #0 */
/* @0xeed70 mov r3, #448 */
/* @0xeed74 add r0, pc, r0 */
/* @0xeed78 movt r3, #0x40e0 */
/* @0xeed7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed80 ldr r0, [pc, #0x4dc] */
/* @0xeed84 mov r2, #0 */
/* @0xeed88 mov r3, #480 */
/* @0xeed8c add r0, pc, r0 */
/* @0xeed90 movt r3, #0x40e0 */
/* @0xeed94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed98 ldr r0, [pc, #0x4c8] */
/* @0xeed9c mov r2, #0 */
/* @0xeeda0 mov r3, #512 */
/* @0xeeda4 add r0, pc, r0 */
/* @0xeeda8 movt r3, #0x40e0 */
/* @0xeedac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeedb0 ldr r0, [pc, #0x4b4] */
/* @0xeedb4 mov r2, #0 */
/* @0xeedb8 mov r3, #544 */
/* @0xeedbc add r0, pc, r0 */
/* @0xeedc0 movt r3, #0x40e0 */
/* @0xeedc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeedc8 ldr r0, [pc, #0x4a0] */
/* @0xeedcc mov r2, #0 */
/* @0xeedd0 mov r3, #576 */
/* @0xeedd4 add r0, pc, r0 */
/* @0xeedd8 movt r3, #0x40e0 */
/* @0xeeddc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeede0 ldr r0, [pc, #0x48c] */
/* @0xeede4 mov r2, #0 */
/* @0xeede8 mov r3, #608 */
/* @0xeedec add r0, pc, r0 */
/* @0xeedf0 movt r3, #0x40e0 */
/* @0xeedf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeedf8 ldr r0, [pc, #0x478] */
/* @0xeedfc mov r2, #0 */
/* @0xeee00 mov r3, #640 */
/* @0xeee04 add r0, pc, r0 */
/* @0xeee08 movt r3, #0x40e0 */
/* @0xeee0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee10 ldr r0, [pc, #0x464] */
/* @0xeee14 mov r2, #0 */
/* @0xeee18 mov r3, #0 */
/* @0xeee1c add r0, pc, r0 */
/* @0xeee20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee24 ldr r0, [pc, #0x454] */
/* @0xeee28 mov r2, #0 */
/* @0xeee2c mov r3, #0 */
/* @0xeee30 add r0, pc, r0 */
/* @0xeee34 movt r3, #0x3ff0 */
/* @0xeee38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee3c ldr r0, [pc, #0x440] */
/* @0xeee40 mov r2, #0 */
/* @0xeee44 mov r3, #0 */
/* @0xeee48 add r0, pc, r0 */
/* @0xeee4c movt r3, #0x4028 */
/* @0xeee50 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee54 ldr r0, [pc, #0x42c] */
/* @0xeee58 mov r2, #0 */
/* @0xeee5c mov r3, #0 */
/* @0xeee60 add r0, pc, r0 */
/* @0xeee64 movt r3, #0x4008 */
/* @0xeee68 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee6c ldr r0, [pc, #0x418] */
/* @0xeee70 mov r2, #0 */
/* @0xeee74 mov r3, #1073741824 */
/* @0xeee78 add r0, pc, r0 */
/* @0xeee7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee80 ldr r0, [pc, #0x408] */
/* @0xeee84 mov r2, #0 */
/* @0xeee88 mov r3, #0 */
/* @0xeee8c add r0, pc, r0 */
/* @0xeee90 movt r3, #0x4014 */
/* @0xeee94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee98 ldr r0, [pc, #0x3f4] */
/* @0xeee9c mov r2, #0 */
/* @0xeeea0 mov r3, #0 */
/* @0xeeea4 add r0, pc, r0 */
/* @0xeeea8 movt r3, #0x4018 */
/* @0xeeeac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeeb0 ldr r0, [pc, #0x3e0] */
/* @0xeeeb4 mov r2, #0 */
/* @0xeeeb8 mov r3, #0 */
/* @0xeeebc add r0, pc, r0 */
/* @0xeeec0 movt r3, #0x4010 */
/* @0xeeec4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeec8 ldr r0, [pc, #0x3cc] */
/* @0xeeecc mov r2, #0 */
/* @0xeeed0 mov r3, #0 */
/* @0xeeed4 add r0, pc, r0 */
/* @0xeeed8 movt r3, #0x401c */
/* @0xeeedc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeee0 ldr r0, [pc, #0x3b8] */
/* @0xeeee4 mov r2, #0 */
/* @0xeeee8 mov r3, #0 */
/* @0xeeeec add r0, pc, r0 */
/* @0xeeef0 movt r3, #0x4020 */
/* @0xeeef4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeef8 ldr r0, [pc, #0x3a4] */
/* @0xeeefc mov r2, #0 */
/* @0xeef00 mov r3, #0 */
/* @0xeef04 add r0, pc, r0 */
/* @0xeef08 movt r3, #0x4022 */
/* @0xeef0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef10 ldr r0, [pc, #0x390] */
/* @0xeef14 mov r2, #0 */
/* @0xeef18 mov r3, #0 */
/* @0xeef1c add r0, pc, r0 */
/* @0xeef20 movt r3, #0x4024 */
/* @0xeef24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef28 ldr r0, [pc, #0x37c] */
/* @0xeef2c mov r2, #0 */
/* @0xeef30 mov r3, #0 */
/* @0xeef34 add r0, pc, r0 */
/* @0xeef38 movt r3, #0x4026 */
/* @0xeef3c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef40 ldrb r3, [r4] */
/* @0xeef44 cmp r3, #0 */
/* @0xeef48 bne 0xf13dc <_Z24INITIALIZE_Code_Constantv+0x33c0> */
/* @0xeef4c ldr r0, [pc, #0x35c] */
/* @0xeef50 mov r2, #0 */
/* @0xeef54 mov r3, #0 */
/* @0xeef58 add r0, pc, r0 */
/* @0xeef5c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef60 ldr r0, [pc, #0x34c] */
/* @0xeef64 mov r2, #0 */
/* @0xeef68 mov r3, #0 */
/* @0xeef6c add r0, pc, r0 */
/* @0xeef70 movt r3, #0x3ff0 */
/* @0xeef74 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef78 ldr r0, [pc, #0x338] */
/* @0xeef7c mov r2, #0 */
/* @0xeef80 mov r3, #1073741824 */
/* @0xeef84 add r0, pc, r0 */
/* @0xeef88 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef8c ldr r0, [pc, #0x328] */
/* @0xeef90 mov r2, #0 */
/* @0xeef94 mov r3, #0 */
/* @0xeef98 add r0, pc, r0 */
/* @0xeef9c movt r3, #0x4008 */
/* @0xeefa0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeefa4 ldr r0, [pc, #0x314] */
/* @0xeefa8 mov r2, #0 */
/* @0xeefac mov r3, #0 */
/* @0xeefb0 add r0, pc, r0 */
/* @0xeefb4 movt r3, #0x4010 */
/* @0xeefb8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeefbc ldr r0, [pc, #0x300] */
/* @0xeefc0 mov r2, #0 */
/* @0xeefc4 mov r3, #0 */
/* @0xeefc8 add r0, pc, r0 */
/* @0xeefcc movt r3, #0x4014 */
/* @0xeefd0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeefd4 ldr r0, [pc, #0x2ec] */
/* @0xeefd8 mov r2, #0 */
/* @0xeefdc mov r3, #0 */
/* @0xeefe0 add r0, pc, r0 */
/* @0xeefe4 movt r3, #0x4018 */
/* @0xeefe8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeefec ldr r0, [pc, #0x2d8] */
/* @0xeeff0 mov r2, #0 */
/* @0xeeff4 mov r3, #0 */
/* @0xeeff8 add r0, pc, r0 */
/* @0xeeffc movt r3, #0x401c */
/* @0xef000 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef004 ldr r0, [pc, #0x2c4] */
/* @0xef008 mov r2, #0 */
/* @0xef00c mov r3, #0 */
/* @0xef010 add r0, pc, r0 */
/* @0xef014 movt r3, #0x4020 */
/* @0xef018 b 0xef58c <_Z24INITIALIZE_Code_Constantv+0x1570> */
/* @0xef01c mlaeq r4, r4, lr, r6 */
/* @0xef020 eoreq r6, r4, r0, lsl #29 */
/* @0xef024 eoreq pc, pc, r12, lsr r4 */
/* @0xef028 eoreq r6, r4, r0, ror lr */
/* @0xef02c eoreq r6, r4, r12, asr lr */
/* @0xef030 eoreq r6, r4, r12, asr #28 */
/* @0xef034 eoreq r6, r4, r12, lsr lr */
/* @0xef038 eoreq r6, r4, r4, ror #18 */
/* @0xef03c eoreq r6, r4, r4, asr r9 */
/* @0xef040 eoreq r6, r4, r0, lsl #28 */
/* @0xef044 eoreq r6, r4, r12, ror #27 */
/* @0xef048 eoreq r6, r4, r4, ror #27 */
/* @0xef04c .word 0x00246ddc */
/* @0xef050 .word 0x00246dd4 */
/* @0xef054 eoreq r6, r4, r12, asr #27 */
/* @0xef058 eoreq r6, r4, r8, asr #27 */
/* @0xef05c eoreq r6, r4, r0, asr #27 */
/* @0xef060 .word 0x00246db0 */
/* @0xef064 eoreq r6, r4, r4, lsr #27 */
/* @0xef068 mlaeq r4, r4, sp, r6 */
/* @0xef06c eoreq r6, r4, r8, lsl #27 */
/* @0xef070 eoreq r6, r4, r12, ror sp */
/* @0xef074 eoreq r6, r4, r12, ror #26 */
/* @0xef078 eoreq r6, r4, r12, asr sp */
/* @0xef07c eoreq r6, r4, r12, asr #26 */
/* @0xef080 eoreq r6, r4, r0, asr #26 */
/* @0xef084 eoreq r6, r4, r4, lsr sp */
/* @0xef088 eoreq r6, r4, r4, lsr #26 */
/* @0xef08c eoreq r6, r4, r4, lsl sp */
/* @0xef090 eoreq r6, r4, r8, lsl #26 */
/* @0xef094 .word 0x00246cf8 */
/* @0xef098 eoreq r6, r4, r12, ror #25 */
/* @0xef09c .word 0x00246cdc */
/* @0xef0a0 eoreq r6, r4, r12, asr #25 */
/* @0xef0a4 eoreq r6, r4, r0, asr #25 */
/* @0xef0a8 .word 0x00246cb4 */
/* @0xef0ac eoreq r6, r4, r12, lsr #25 */
/* @0xef0b0 mlaeq r4, r12, r12, r6 */
/* @0xef0b4 mlaeq r4, r0, r12, r6 */
/* @0xef0b8 eoreq r6, r4, r4, lsl #25 */
/* @0xef0bc eoreq r6, r4, r4, ror r12 */
/* @0xef0c0 eoreq r6, r4, r8, ror #24 */
/* @0xef0c4 eoreq r6, r4, r0, ror #24 */
/* @0xef0c8 eoreq r6, r4, r8, asr r12 */
/* @0xef0cc eoreq r6, r4, r4, asr r12 */
/* @0xef0d0 eoreq r6, r4, r0, asr r12 */
/* @0xef0d4 eoreq r6, r4, r8, asr #24 */
/* @0xef0d8 eoreq r6, r4, r4, asr #24 */
/* @0xef0dc eoreq r6, r4, r12, lsr r12 */
/* @0xef0e0 eoreq r6, r4, r8, lsr r12 */
/* @0xef0e4 eoreq r6, r4, r0, lsr r12 */
/* @0xef0e8 eoreq r6, r4, r8, lsr #24 */
/* @0xef0ec eoreq r6, r4, r4, lsr #24 */
/* @0xef0f0 eoreq r6, r4, r8, asr r12 */
/* @0xef0f4 eoreq r6, r4, r8, asr r12 */
/* @0xef0f8 eoreq r6, r4, r0, ror #24 */
/* @0xef0fc eoreq r6, r4, r4, ror r12 */
/* @0xef100 eoreq r6, r4, r12, ror r12 */
/* @0xef104 eoreq r6, r4, r12, lsl #25 */
/* @0xef108 mlaeq r4, r4, r12, r6 */
/* @0xef10c eoreq r6, r4, r4, lsr #25 */
/* @0xef110 eoreq r6, r4, r4, lsr #25 */
/* @0xef114 eoreq r6, r4, r0, lsr #25 */
/* @0xef118 mlaeq r4, r8, r12, r6 */
/* @0xef11c mlaeq r4, r0, r12, r6 */
/* @0xef120 eoreq r6, r4, r8, lsl #25 */
/* @0xef124 eoreq r6, r4, r12, ror r12 */
/* @0xef128 eoreq r6, r4, r0, ror r12 */
/* @0xef12c eoreq r6, r4, r8, ror #24 */
/* @0xef130 eoreq r6, r4, r12, asr r12 */
/* @0xef134 eoreq r6, r4, r0, asr r12 */
/* @0xef138 eoreq r6, r4, r8, asr #24 */
/* @0xef13c eoreq r6, r4, r8, lsr r12 */
/* @0xef140 eoreq r6, r4, r12, lsr #24 */
/* @0xef144 eoreq r6, r4, r12, lsl r12 */
/* @0xef148 eoreq r6, r4, r4, lsl r12 */
/* @0xef14c eoreq r6, r4, r8, lsl #24 */
/* @0xef150 eoreq r6, r4, r0, lsl #24 */
/* @0xef154 .word 0x00246bf4 */
/* @0xef158 eoreq r6, r4, r8, ror #23 */
/* @0xef15c .word 0x00246bdc */
/* @0xef160 .word 0x00246bd0 */
/* @0xef164 eoreq r6, r4, r4, asr #23 */
/* @0xef168 .word 0x00246bb4 */
/* @0xef16c eoreq r6, r4, r8, lsr #23 */
/* @0xef170 mlaeq r4, r12, r11, r6 */
/* @0xef174 mlaeq r4, r4, r11, r6 */
/* @0xef178 eoreq r6, r4, r4, lsl #23 */
/* @0xef17c eoreq r6, r4, r8, ror r11 */
/* @0xef180 eoreq r6, r4, r0, ror r11 */
/* @0xef184 eoreq r6, r4, r0, ror #22 */
/* @0xef188 eoreq r6, r4, r4, asr r11 */
/* @0xef18c eoreq r6, r4, r4, asr #22 */
/* @0xef190 eoreq r6, r4, r4, lsr r11 */
/* @0xef194 eoreq r6, r4, r4, lsr #22 */
/* @0xef198 eoreq r6, r4, r4, lsl r11 */
/* @0xef19c eoreq r6, r4, r8, lsl #22 */
/* @0xef1a0 .word 0x00246afc */
/* @0xef1a4 .word 0x00246af0 */
/* @0xef1a8 eoreq r6, r4, r4, ror #21 */
/* @0xef1ac .word 0x00246ad4 */
/* @0xef1b0 eoreq r6, r4, r4, asr #21 */
/* @0xef1b4 .word 0x00246ab4 */
/* @0xef1b8 eoreq r6, r4, r4, lsr #21 */
/* @0xef1bc mlaeq r4, r4, r10, r6 */
/* @0xef1c0 eoreq r6, r4, r4, lsl #21 */
/* @0xef1c4 eoreq r6, r4, r4, ror r10 */
/* @0xef1c8 eoreq r6, r4, r4, ror #20 */
/* @0xef1cc eoreq r6, r4, r4, asr r10 */
/* @0xef1d0 eoreq r6, r4, r4, asr #20 */
/* @0xef1d4 eoreq r6, r4, r4, lsr r10 */
/* @0xef1d8 eoreq r6, r4, r4, lsr #20 */
/* @0xef1dc eoreq r6, r4, r8, lsl r10 */
/* @0xef1e0 eoreq r6, r4, r12, lsl #20 */
/* @0xef1e4 eoreq r6, r4, r0, lsl #20 */
/* @0xef1e8 .word 0x002469f4 */
/* @0xef1ec eoreq r6, r4, r8, ror #19 */
/* @0xef1f0 .word 0x002469dc */
/* @0xef1f4 .word 0x002469d0 */
/* @0xef1f8 eoreq r6, r4, r4, asr #19 */
/* @0xef1fc .word 0x002469b8 */
/* @0xef200 eoreq r6, r4, r12, lsr #19 */
/* @0xef204 eoreq r6, r4, r0, lsr #19 */
/* @0xef208 mlaeq r4, r4, r9, r6 */
/* @0xef20c eoreq r6, r4, r8, lsl #19 */
/* @0xef210 eoreq r6, r4, r8, ror r9 */
/* @0xef214 eoreq r6, r4, r12, ror #18 */
/* @0xef218 eoreq r6, r4, r0, ror #18 */
/* @0xef21c eoreq r6, r4, r4, asr r9 */
/* @0xef220 eoreq r6, r4, r4, asr #18 */
/* @0xef224 eoreq r6, r4, r8, lsr r9 */
/* @0xef228 eoreq r6, r4, r12, lsr #18 */
/* @0xef22c eoreq r6, r4, r12, lsl r9 */
/* @0xef230 eoreq r6, r4, r0, lsl r9 */
/* @0xef234 eoreq r6, r4, r4, lsl #18 */
/* @0xef238 .word 0x002468f8 */
/* @0xef23c eoreq r6, r4, r12, ror #17 */
/* @0xef240 eoreq r6, r4, r4, ror #17 */
/* @0xef244 .word 0x002468dc */
/* @0xef248 .word 0x002468d4 */
/* @0xef24c eoreq r6, r4, r12, asr #17 */
/* @0xef250 eoreq r6, r4, r0, asr #17 */
/* @0xef254 .word 0x002468b4 */
/* @0xef258 eoreq r6, r4, r8, lsr #17 */
/* @0xef25c mlaeq r4, r12, r8, r6 */
/* @0xef260 eoreq r6, r4, r12, lsl #17 */
/* @0xef264 eoreq r6, r4, r12, ror r8 */
/* @0xef268 eoreq r6, r4, r12, ror #16 */
/* @0xef26c eoreq r6, r4, r12, asr r8 */
/* @0xef270 eoreq r6, r4, r0, asr r8 */
/* @0xef274 eoreq r6, r4, r4, asr #16 */
/* @0xef278 eoreq r6, r4, r8, lsr r8 */
/* @0xef27c eoreq r6, r4, r12, lsr #16 */
/* @0xef280 eoreq r6, r4, r4, lsr #16 */
/* @0xef284 eoreq r6, r4, r8, lsl r8 */
/* @0xef288 eoreq r6, r4, r12, lsl #16 */
/* @0xef28c .word 0x002467fc */
/* @0xef290 .word 0x002467f4 */
/* @0xef294 eoreq r6, r4, r8, ror #15 */
/* @0xef298 .word 0x002467dc */
/* @0xef29c .word 0x002467d4 */
/* @0xef2a0 eoreq r6, r4, r8, asr #15 */
/* @0xef2a4 .word 0x002467b8 */
/* @0xef2a8 eoreq r6, r4, r12, lsr #15 */
/* @0xef2ac eoreq r6, r4, r4, lsr #15 */
/* @0xef2b0 .word 0x002467b4 */
/* @0xef2b4 .word 0x002467b0 */
/* @0xef2b8 eoreq r6, r4, r8, lsr #15 */
/* @0xef2bc eoreq r6, r4, r8, lsr #15 */
/* @0xef2c0 eoreq r6, r4, r0, lsr #15 */
/* @0xef2c4 mlaeq r4, r8, r7, r6 */
/* @0xef2c8 mlaeq r4, r0, r7, r6 */
/* @0xef2cc eoreq r6, r4, r8, lsl #15 */
/* @0xef2d0 eoreq r6, r4, r0, lsl #15 */
/* @0xef2d4 eoreq r6, r4, r8, lsl #4 */
/* @0xef2d8 eoreq r6, r4, r4, lsl #4 */
/* @0xef2dc .word 0x002461fc */
/* @0xef2e0 .word 0x002461f4 */
/* @0xef2e4 eoreq r6, r4, r12, ror #3 */
/* @0xef2e8 eoreq r6, r4, r8, ror #3 */
/* @0xef2ec eoreq r6, r4, r4, ror #3 */
/* @0xef2f0 eoreq r6, r4, r0, ror #3 */
/* @0xef2f4 .word 0x002461d8 */
/* @0xef2f8 .word 0x002461d4 */
/* @0xef2fc .word 0x002461d4 */
/* @0xef300 .word 0x002461d4 */
/* @0xef304 .word 0x002461d4 */
/* @0xef308 .word 0x002461d4 */
/* @0xef30c .word 0x002461d4 */
/* @0xef310 .word 0x002461d4 */
/* @0xef314 .word 0x002461d4 */
/* @0xef318 .word 0x002461d4 */
/* @0xef31c .word 0x002461d0 */
/* @0xef320 eoreq r6, r4, r12, asr #3 */
/* @0xef324 eoreq r6, r4, r4, asr #3 */
/* @0xef328 eoreq r6, r4, r0, asr #3 */
/* @0xef32c eoreq r6, r4, r0, asr #3 */
/* @0xef330 eoreq r6, r4, r0, asr #3 */
/* @0xef334 eoreq r6, r4, r0, asr #3 */
/* @0xef338 eoreq r6, r4, r0, asr #3 */
/* @0xef33c eoreq r6, r4, r0, asr #3 */
/* @0xef340 eoreq r6, r4, r0, asr #3 */
/* @0xef344 eoreq r6, r4, r0, asr #3 */
/* @0xef348 eoreq r6, r4, r0, asr #3 */
/* @0xef34c eoreq r6, r4, r0, asr #3 */
/* @0xef350 eoreq r6, r4, r0, asr #3 */
/* @0xef354 eoreq r6, r4, r0, asr #3 */
/* @0xef358 eoreq r6, r4, r0, asr #3 */
/* @0xef35c eoreq r6, r4, r0, asr #3 */
/* @0xef360 eoreq r6, r4, r0, asr #3 */
/* @0xef364 eoreq r6, r4, r0, asr #3 */
/* @0xef368 eoreq r6, r4, r0, asr #3 */
/* @0xef36c eoreq r6, r4, r4, asr #3 */
/* @0xef370 eoreq r6, r4, r0, asr #3 */
/* @0xef374 .word 0x002461bc */
/* @0xef378 .word 0x002461b4 */
/* @0xef37c eoreq r6, r4, r8, lsr #3 */
/* @0xef380 eoreq r6, r4, r4, lsr #3 */
/* @0xef384 mlaeq r4, r8, r1, r6 */
/* @0xef388 mlaeq r4, r0, r1, r6 */
/* @0xef38c eoreq r6, r4, r4, lsl #3 */
/* @0xef390 eoreq r6, r4, r0, lsl #3 */
/* @0xef394 eoreq r6, r4, r12, ror r1 */
/* @0xef398 eoreq r6, r4, r4, ror r1 */
/* @0xef39c eoreq r6, r4, r0, ror r1 */
/* @0xef3a0 eoreq r6, r4, r4, ror #2 */
/* @0xef3a4 eoreq r6, r4, r8, asr r1 */
/* @0xef3a8 eoreq r6, r4, r12, asr #2 */
/* @0xef3ac eoreq r6, r4, r0, asr #2 */
/* @0xef3b0 eoreq r6, r4, r4, lsr r1 */
/* @0xef3b4 eoreq r6, r4, r8, lsr #2 */
/* @0xef3b8 eoreq r6, r4, r12, lsl r1 */
/* @0xef3bc eoreq r6, r4, r0, lsl r1 */
/* @0xef3c0 eoreq r6, r4, r4, lsl #2 */
/* @0xef3c4 .word 0x002460f8 */
/* @0xef3c8 eoreq r6, r4, r12, ror #1 */
/* @0xef3cc eoreq r6, r4, r0, ror #1 */
/* @0xef3d0 .word 0x002460d4 */
/* @0xef3d4 eoreq r6, r4, r8, asr #1 */
/* @0xef3d8 strhteq r6, [r4], -r12 */
/* @0xef3dc strhteq r6, [r4], -r0 */
/* @0xef3e0 eoreq r6, r4, r8, lsr #1 */
/* @0xef3e4 eoreq r6, r4, r4, lsr #1 */
/* @0xef3e8 mlaeq r4, r12, r0, r6 */
/* @0xef3ec eoreq r6, r4, r8, lsl r3 */
/* @0xef3f0 eoreq r6, r4, r0, lsl r3 */
/* @0xef3f4 eoreq r6, r4, r4, lsl #6 */
/* @0xef3f8 .word 0x002462f4 */
/* @0xef3fc eoreq r6, r4, r4, ror #5 */
/* @0xef400 .word 0x002462d8 */
/* @0xef404 .word 0x002462d0 */
/* @0xef408 eoreq r6, r4, r4, asr #5 */
/* @0xef40c .word 0x002462b8 */
/* @0xef410 .word 0x002462b8 */
/* @0xef414 .word 0x002462b0 */
/* @0xef418 eoreq r6, r4, r12, lsr #5 */
/* @0xef41c eoreq r6, r4, r8, lsr #5 */
/* @0xef420 eoreq r6, r4, r0, lsr #5 */
/* @0xef424 mlaeq r4, r4, r2, r6 */
/* @0xef428 eoreq lr, pc, r12, asr #32 */
/* @0xef42c eoreq r6, r4, r8, lsl #5 */
/* @0xef430 eoreq r6, r4, r0, lsl #5 */
/* @0xef434 eoreq r6, r4, r8, ror r2 */
/* @0xef438 eoreq r6, r4, r12, ror #4 */
/* @0xef43c eoreq r6, r4, r0, ror #4 */
/* @0xef440 eoreq r6, r4, r8, asr r2 */
/* @0xef444 eoreq r6, r4, r12, asr #4 */
/* @0xef448 eoreq r6, r4, r4, asr #4 */
/* @0xef44c eoreq r6, r4, r4, lsr r2 */
/* @0xef450 eoreq r6, r4, r12, lsr #4 */
/* @0xef454 eoreq r6, r4, r0, lsr #4 */
/* @0xef458 eoreq r6, r4, r0, lsl r2 */
/* @0xef45c eoreq r6, r4, r8, lsl #4 */
/* @0xef460 .word 0x002461fc */
/* @0xef464 .word 0x002461f4 */
/* @0xef468 eoreq r6, r4, r8, ror #3 */
/* @0xef46c .word 0x002461dc */
/* @0xef470 .word 0x002461d4 */
/* @0xef474 eoreq r6, r4, r4, asr #3 */
/* @0xef478 .word 0x002461b8 */
/* @0xef47c eoreq r6, r4, r12, lsr #3 */
/* @0xef480 eoreq r6, r4, r0, lsr #3 */
/* @0xef484 mlaeq r4, r8, r1, r6 */
/* @0xef488 eoreq r6, r4, r12, lsl #3 */
/* @0xef48c eoreq r6, r4, r12, ror r1 */
/* @0xef490 eoreq r6, r4, r0, ror r1 */
/* @0xef494 eoreq r6, r4, r0, ror #2 */
/* @0xef498 eoreq r6, r4, r8, asr r1 */
/* @0xef49c eoreq r6, r4, r12, asr #2 */
/* @0xef4a0 eoreq r6, r4, r8, asr #2 */
/* @0xef4a4 eoreq r6, r4, r0, asr #2 */
/* @0xef4a8 eoreq r6, r4, r12, lsr r1 */
/* @0xef4ac eoreq r6, r4, r4, lsr r1 */
/* @0xef4b0 eoreq r6, r4, r12, lsr #2 */
/* @0xef4b4 eoreq r6, r4, r4, lsr #2 */
/* @0xef4b8 eoreq r6, r4, r12, lsl r1 */
/* @0xef4bc eoreq r6, r4, r4, lsl r1 */
/* @0xef4c0 eoreq r6, r4, r12, lsl #2 */
/* @0xef4c4 eoreq r6, r4, r4, lsl #2 */
/* @0xef4c8 eoreq r6, r4, r0, lsl #2 */
/* @0xef4cc .word 0x002460f8 */
/* @0xef4d0 .word 0x002460f0 */
/* @0xef4d4 eoreq r6, r4, r8, ror #1 */
/* @0xef4d8 eoreq r6, r4, r4, ror #1 */
/* @0xef4dc eoreq r6, r4, r0, ror #1 */
/* @0xef4e0 eoreq r6, r4, r4, ror #1 */
/* @0xef4e4 eoreq r6, r4, r4, ror #1 */
/* @0xef4e8 eoreq r6, r4, r0, ror #1 */
/* @0xef4ec eoreq r6, r4, r0, ror #1 */
/* @0xef4f0 .word 0x002460d8 */
/* @0xef4f4 .word 0x002460d8 */
/* @0xef4f8 .word 0x002460d0 */
/* @0xef4fc .word 0x002460d0 */
/* @0xef500 .word 0x002460d0 */
/* @0xef504 .word 0x002460d0 */
/* @0xef508 eoreq r6, r4, r12, asr #1 */
/* @0xef50c eoreq r6, r4, r4, asr #1 */
/* @0xef510 eoreq r6, r4, r4, asr #1 */
/* @0xef514 eoreq r6, r4, r0, asr #1 */
/* @0xef518 strhteq r6, [r4], -r0 */
/* @0xef51c eoreq r6, r4, r8, lsr #1 */
/* @0xef520 mlaeq r4, r12, r0, r6 */
/* @0xef524 mlaeq r4, r0, r0, r6 */
/* @0xef528 eoreq r6, r4, r4, lsl #1 */
/* @0xef52c eoreq r6, r4, r4, ror r0 */
/* @0xef530 eoreq r6, r4, r8, rrx */
/* @0xef534 eoreq r6, r4, r12, asr r0 */
/* @0xef538 eoreq r6, r4, r0, asr r0 */
/* @0xef53c eoreq r6, r4, r0, asr #32 */
/* @0xef540 eoreq r6, r4, r0, lsr r0 */
/* @0xef544 eoreq r6, r4, r0, lsr r0 */
/* @0xef548 eoreq r6, r4, r12, lsr #32 */
/* @0xef54c eoreq r6, r4, r4, lsr r0 */
/* @0xef550 eoreq r6, r4, r8, lsr r0 */
/* @0xef554 eoreq r6, r4, r12, lsr #32 */
/* @0xef558 eoreq r6, r4, r4, lsr #32 */
/* @0xef55c eoreq r6, r4, r12, lsl r0 */
/* @0xef560 eoreq r6, r4, r4 */
/* @0xef564 .word 0x00245ff4 */
/* @0xef568 eoreq r5, r4, r8, ror #31 */
/* @0xef56c .word 0x00245fdc */
/* @0xef570 .word 0x00245fd0 */
/* @0xef574 eoreq r5, r4, r4, asr #31 */
/* @0xef578 .word 0x00245fb8 */
/* @0xef57c eoreq r5, r4, r12, lsr #31 */
/* @0xef580 eoreq r5, r4, r4, lsr #31 */
/* @0xef584 mlaeq r4, r4, pc, r5 */
/* @0xef588 eoreq r5, r4, r4, lsl #31 */
/* @0xef58c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef590 ldr r0, [pc, #-0x2c4] */
/* @0xef594 mov r2, #0 */
/* @0xef598 mov r3, #0 */
/* @0xef59c add r0, pc, r0 */
/* @0xef5a0 movt r3, #0x4022 */
/* @0xef5a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef5a8 ldr r0, [pc, #-0x2d8] */
/* @0xef5ac mov r2, #0 */
/* @0xef5b0 mov r3, #0 */
/* @0xef5b4 add r0, pc, r0 */
/* @0xef5b8 movt r3, #0x4024 */
/* @0xef5bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef5c0 ldr r0, [pc, #-0x2ec] */
/* @0xef5c4 mov r2, #0 */
/* @0xef5c8 mov r3, #0 */
/* @0xef5cc add r0, pc, r0 */
/* @0xef5d0 movt r3, #0x4026 */
/* @0xef5d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef5d8 ldr r0, [pc, #-0x300] */
/* @0xef5dc mov r2, #0 */
/* @0xef5e0 mov r3, #0 */
/* @0xef5e4 add r0, pc, r0 */
/* @0xef5e8 movt r3, #0x4028 */
/* @0xef5ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef5f0 ldr r0, [pc, #-0x314] */
/* @0xef5f4 mov r2, #0 */
/* @0xef5f8 mov r3, #0 */
/* @0xef5fc add r0, pc, r0 */
/* @0xef600 movt r3, #0x402a */
/* @0xef604 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef608 ldr r0, [pc, #-0x328] */
/* @0xef60c mov r2, #0 */
/* @0xef610 mov r3, #0 */
/* @0xef614 add r0, pc, r0 */
/* @0xef618 movt r3, #0x4030 */
/* @0xef61c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef620 ldr r0, [pc, #-0x33c] */
/* @0xef624 mov r2, #0 */
/* @0xef628 mov r3, #0 */
/* @0xef62c add r0, pc, r0 */
/* @0xef630 movt r3, #0x4031 */
/* @0xef634 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef638 ldr r0, [pc, #-0x350] */
/* @0xef63c mov r2, #0 */
/* @0xef640 mov r3, #0 */
/* @0xef644 add r0, pc, r0 */
/* @0xef648 movt r3, #0x4032 */
/* @0xef64c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef650 ldr r0, [pc, #-0x364] */
/* @0xef654 mov r2, #0 */
/* @0xef658 mov r3, #0 */
/* @0xef65c add r0, pc, r0 */
/* @0xef660 movt r3, #0x4033 */
/* @0xef664 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef668 ldr r0, [pc, #-0x378] */
/* @0xef66c mov r2, #0 */
/* @0xef670 mov r3, #0 */
/* @0xef674 add r0, pc, r0 */
/* @0xef678 movt r3, #0x4035 */
/* @0xef67c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef680 ldr r0, [pc, #-0x38c] */
/* @0xef684 mov r2, #0 */
/* @0xef688 mov r3, #0 */
/* @0xef68c add r0, pc, r0 */
/* @0xef690 movt r3, #0x4036 */
/* @0xef694 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef698 ldr r0, [pc, #-0x3a0] */
/* @0xef69c mov r2, #0 */
/* @0xef6a0 mov r3, #0 */
/* @0xef6a4 add r0, pc, r0 */
/* @0xef6a8 movt r3, #0x4037 */
/* @0xef6ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef6b0 ldr r0, [pc, #-0x3b4] */
/* @0xef6b4 mov r2, #0 */
/* @0xef6b8 mov r3, #0 */
/* @0xef6bc add r0, pc, r0 */
/* @0xef6c0 movt r3, #0x4038 */
/* @0xef6c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef6c8 ldr r0, [pc, #-0x3c8] */
/* @0xef6cc mov r2, #0 */
/* @0xef6d0 mov r3, #0 */
/* @0xef6d4 add r0, pc, r0 */
/* @0xef6d8 movt r3, #0x4039 */
/* @0xef6dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef6e0 ldr r0, [pc, #-0x3dc] */
/* @0xef6e4 mov r2, #0 */
/* @0xef6e8 mov r3, #0 */
/* @0xef6ec add r0, pc, r0 */
/* @0xef6f0 movt r3, #0x403a */
/* @0xef6f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef6f8 ldr r0, [pc, #-0x3f0] */
/* @0xef6fc mov r2, #0 */
/* @0xef700 mov r3, #0 */
/* @0xef704 add r0, pc, r0 */
/* @0xef708 movt r3, #0x403b */
/* @0xef70c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef710 ldr r0, [pc, #-0x404] */
/* @0xef714 mov r2, #0 */
/* @0xef718 mov r3, #0 */
/* @0xef71c add r0, pc, r0 */
/* @0xef720 movt r3, #0x403c */
/* @0xef724 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef728 ldr r0, [pc, #-0x418] */
/* @0xef72c mov r2, #0 */
/* @0xef730 mov r3, #0 */
/* @0xef734 add r0, pc, r0 */
/* @0xef738 movt r3, #0x403f */
/* @0xef73c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef740 ldr r0, [pc, #-0x42c] */
/* @0xef744 mov r2, #0 */
/* @0xef748 mov r3, #0 */
/* @0xef74c add r0, pc, r0 */
/* @0xef750 movt r3, #0x4040 */
/* @0xef754 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef758 ldr r0, [pc, #-0x440] */
/* @0xef75c mov r2, #0 */
/* @0xef760 mov r3, #32768 */
/* @0xef764 add r0, pc, r0 */
/* @0xef768 movt r3, #0x4040 */
/* @0xef76c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef770 ldr r0, [pc, #-0x454] */
/* @0xef774 mov r2, #0 */
/* @0xef778 mov r3, #0 */
/* @0xef77c add r0, pc, r0 */
/* @0xef780 movt r3, #0x4041 */
/* @0xef784 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef788 ldr r0, [pc, #-0x468] */
/* @0xef78c mov r2, #0 */
/* @0xef790 mov r3, #0 */
/* @0xef794 add r0, pc, r0 */
/* @0xef798 movt r3, #0x4042 */
/* @0xef79c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef7a0 ldr r0, [pc, #-0x47c] */
/* @0xef7a4 mov r2, #0 */
/* @0xef7a8 mov r3, #32768 */
/* @0xef7ac add r0, pc, r0 */
/* @0xef7b0 movt r3, #0x4042 */
/* @0xef7b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef7b8 ldr r0, [pc, #-0x490] */
/* @0xef7bc mov r2, #0 */
/* @0xef7c0 mov r3, #0 */
/* @0xef7c4 add r0, pc, r0 */
/* @0xef7c8 movt r3, #0x4043 */
/* @0xef7cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef7d0 ldr r0, [pc, #-0x4a4] */
/* @0xef7d4 mov r2, #0 */
/* @0xef7d8 mov r3, #32768 */
/* @0xef7dc add r0, pc, r0 */
/* @0xef7e0 movt r3, #0x4043 */
/* @0xef7e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef7e8 ldr r0, [pc, #-0x4b8] */
/* @0xef7ec mov r2, #0 */
/* @0xef7f0 mov r3, #0 */
/* @0xef7f4 add r0, pc, r0 */
/* @0xef7f8 movt r3, #0x4044 */
/* @0xef7fc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef800 ldr r0, [pc, #-0x4cc] */
/* @0xef804 mov r2, #0 */
/* @0xef808 mov r3, #32768 */
/* @0xef80c add r0, pc, r0 */
/* @0xef810 movt r3, #0x4044 */
/* @0xef814 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef818 ldr r0, [pc, #-0x4e0] */
/* @0xef81c mov r2, #0 */
/* @0xef820 mov r3, #0 */
/* @0xef824 add r0, pc, r0 */
/* @0xef828 movt r3, #0x4045 */
/* @0xef82c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef830 ldr r0, [pc, #-0x4f4] */
/* @0xef834 mov r2, #0 */
/* @0xef838 mov r3, #32768 */
/* @0xef83c add r0, pc, r0 */
/* @0xef840 movt r3, #0x4045 */
/* @0xef844 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef848 ldr r0, [pc, #-0x508] */
/* @0xef84c mov r2, #0 */
/* @0xef850 mov r3, #0 */
/* @0xef854 add r0, pc, r0 */
/* @0xef858 movt r3, #0x4049 */
/* @0xef85c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef860 ldr r0, [pc, #-0x51c] */
/* @0xef864 mov r2, #0 */
/* @0xef868 mov r3, #32768 */
/* @0xef86c add r0, pc, r0 */
/* @0xef870 movt r3, #0x4049 */
/* @0xef874 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef878 ldr r0, [pc, #-0x530] */
/* @0xef87c mov r2, #0 */
/* @0xef880 mov r3, #0 */
/* @0xef884 add r0, pc, r0 */
/* @0xef888 movt r3, #0x404a */
/* @0xef88c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef890 ldr r0, [pc, #-0x544] */
/* @0xef894 mov r2, #0 */
/* @0xef898 mov r3, #32768 */
/* @0xef89c add r0, pc, r0 */
/* @0xef8a0 movt r3, #0x404a */
/* @0xef8a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef8a8 ldr r0, [pc, #-0x558] */
/* @0xef8ac mov r2, #0 */
/* @0xef8b0 mov r3, #0 */
/* @0xef8b4 add r0, pc, r0 */
/* @0xef8b8 movt r3, #0x404b */
/* @0xef8bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef8c0 ldr r0, [pc, #-0x56c] */
/* @0xef8c4 mov r2, #0 */
/* @0xef8c8 mov r3, #32768 */
/* @0xef8cc add r0, pc, r0 */
/* @0xef8d0 movt r3, #0x404b */
/* @0xef8d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef8d8 ldr r0, [pc, #-0x580] */
/* @0xef8dc mov r2, #0 */
/* @0xef8e0 mov r3, #0 */
/* @0xef8e4 add r0, pc, r0 */
/* @0xef8e8 movt r3, #0x404c */
/* @0xef8ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef8f0 ldr r0, [pc, #-0x594] */
/* @0xef8f4 mov r2, #0 */
/* @0xef8f8 mov r3, #32768 */
/* @0xef8fc add r0, pc, r0 */
/* @0xef900 movt r3, #0x404c */
/* @0xef904 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef908 ldr r0, [pc, #-0x5a8] */
/* @0xef90c mov r2, #0 */
/* @0xef910 mov r3, #0 */
/* @0xef914 add r0, pc, r0 */
/* @0xef918 movt r3, #0x404d */
/* @0xef91c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef920 ldr r0, [pc, #-0x5bc] */
/* @0xef924 mov r2, #0 */
/* @0xef928 mov r3, #0 */
/* @0xef92c add r0, pc, r0 */
/* @0xef930 movt r3, #0x404e */
/* @0xef934 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef938 ldr r0, [pc, #-0x5d0] */
/* @0xef93c mov r2, #0 */
/* @0xef940 mov r3, #32768 */
/* @0xef944 add r0, pc, r0 */
/* @0xef948 movt r3, #0x404e */
/* @0xef94c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef950 ldr r0, [pc, #-0x5e4] */
/* @0xef954 mov r2, #0 */
/* @0xef958 mov r3, #0 */
/* @0xef95c add r0, pc, r0 */
/* @0xef960 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef964 ldr r0, [pc, #-0x5f4] */
/* @0xef968 mov r2, #0 */
/* @0xef96c mov r3, #0 */
/* @0xef970 add r0, pc, r0 */
/* @0xef974 movt r3, #0x3ff0 */
/* @0xef978 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef97c ldr r0, [pc, #-0x608] */
/* @0xef980 mov r2, #0 */
/* @0xef984 mov r3, #1073741824 */
/* @0xef988 add r0, pc, r0 */
/* @0xef98c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef990 ldr r0, [pc, #-0x618] */
/* @0xef994 mov r2, #0 */
/* @0xef998 mov r3, #0 */
/* @0xef99c add r0, pc, r0 */
/* @0xef9a0 movt r3, #0x4008 */
/* @0xef9a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef9a8 ldr r0, [pc, #-0x62c] */
/* @0xef9ac mov r2, #0 */
/* @0xef9b0 mov r3, #0 */
/* @0xef9b4 add r0, pc, r0 */
/* @0xef9b8 movt r3, #0x4010 */
/* @0xef9bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef9c0 ldr r0, [pc, #-0x640] */
/* @0xef9c4 mov r2, #0 */
/* @0xef9c8 mov r3, #0 */
/* @0xef9cc add r0, pc, r0 */
/* @0xef9d0 movt r3, #0x4014 */
/* @0xef9d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef9d8 ldr r0, [pc, #-0x654] */
/* @0xef9dc mov r2, #0 */
/* @0xef9e0 mov r3, #0 */
/* @0xef9e4 add r0, pc, r0 */
/* @0xef9e8 movt r3, #0x4018 */
/* @0xef9ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef9f0 ldr r0, [pc, #-0x668] */
/* @0xef9f4 mov r2, #0 */
/* @0xef9f8 mov r3, #0 */
/* @0xef9fc add r0, pc, r0 */
/* @0xefa00 movt r3, #0x401c */
/* @0xefa04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa08 ldr r0, [pc, #-0x67c] */
/* @0xefa0c mov r2, #0 */
/* @0xefa10 mov r3, #0 */
/* @0xefa14 add r0, pc, r0 */
/* @0xefa18 movt r3, #0x4020 */
/* @0xefa1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa20 ldr r0, [pc, #-0x690] */
/* @0xefa24 mov r2, #0 */
/* @0xefa28 mov r3, #0 */
/* @0xefa2c add r0, pc, r0 */
/* @0xefa30 movt r3, #0x4022 */
/* @0xefa34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa38 ldr r0, [pc, #-0x6a4] */
/* @0xefa3c mov r2, #0 */
/* @0xefa40 mov r3, #0 */
/* @0xefa44 add r0, pc, r0 */
/* @0xefa48 movt r3, #0x4024 */
/* @0xefa4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa50 ldr r0, [pc, #-0x6b8] */
/* @0xefa54 mov r2, #0 */
/* @0xefa58 mov r3, #0 */
/* @0xefa5c add r0, pc, r0 */
/* @0xefa60 movt r3, #0x4026 */
/* @0xefa64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa68 ldr r0, [pc, #-0x6cc] */
/* @0xefa6c mov r2, #0 */
/* @0xefa70 mov r3, #0 */
/* @0xefa74 add r0, pc, r0 */
/* @0xefa78 movt r3, #0x4028 */
/* @0xefa7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa80 ldr r0, [pc, #-0x6e0] */
/* @0xefa84 mov r2, #0 */
/* @0xefa88 mov r3, #0 */
/* @0xefa8c add r0, pc, r0 */
/* @0xefa90 movt r3, #0x402a */
/* @0xefa94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa98 ldr r0, [pc, #-0x6f4] */
/* @0xefa9c mov r2, #0 */
/* @0xefaa0 mov r3, #0 */
/* @0xefaa4 add r0, pc, r0 */
/* @0xefaa8 movt r3, #0x402c */
/* @0xefaac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefab0 ldr r0, [pc, #-0x708] */
/* @0xefab4 mov r2, #0 */
/* @0xefab8 mov r3, #0 */
/* @0xefabc add r0, pc, r0 */
/* @0xefac0 movt r3, #0x402e */
/* @0xefac4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefac8 ldr r0, [pc, #-0x71c] */
/* @0xefacc mov r2, #0 */
/* @0xefad0 mov r3, #0 */
/* @0xefad4 add r0, pc, r0 */
/* @0xefad8 movt r3, #0x4030 */
/* @0xefadc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefae0 ldr r0, [pc, #-0x730] */
/* @0xefae4 mov r2, #0 */
/* @0xefae8 mov r3, #0 */
/* @0xefaec add r0, pc, r0 */
/* @0xefaf0 movt r3, #0x4031 */
/* @0xefaf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefaf8 ldr r0, [pc, #-0x744] */
/* @0xefafc mov r2, #0 */
/* @0xefb00 mov r3, #0 */
/* @0xefb04 add r0, pc, r0 */
/* @0xefb08 movt r3, #0x4032 */
/* @0xefb0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb10 ldr r0, [pc, #-0x758] */
/* @0xefb14 mov r2, #0 */
/* @0xefb18 mov r3, #0 */
/* @0xefb1c add r0, pc, r0 */
/* @0xefb20 movt r3, #0x4033 */
/* @0xefb24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb28 ldr r0, [pc, #-0x76c] */
/* @0xefb2c mov r2, #0 */
/* @0xefb30 mov r3, #0 */
/* @0xefb34 add r0, pc, r0 */
/* @0xefb38 movt r3, #0x4034 */
/* @0xefb3c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb40 ldr r0, [pc, #-0x780] */
/* @0xefb44 mov r2, #0 */
/* @0xefb48 mov r3, #0 */
/* @0xefb4c add r0, pc, r0 */
/* @0xefb50 movt r3, #0x4035 */
/* @0xefb54 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb58 ldr r0, [pc, #-0x794] */
/* @0xefb5c mov r2, #0 */
/* @0xefb60 mov r3, #0 */
/* @0xefb64 add r0, pc, r0 */
/* @0xefb68 movt r3, #0x4036 */
/* @0xefb6c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb70 ldr r0, [pc, #-0x7a8] */
/* @0xefb74 mov r2, #0 */
/* @0xefb78 mov r3, #0 */
/* @0xefb7c add r0, pc, r0 */
/* @0xefb80 movt r3, #0x4037 */
/* @0xefb84 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb88 ldr r0, [pc, #-0x7bc] */
/* @0xefb8c mov r2, #0 */
/* @0xefb90 mov r3, #0 */
/* @0xefb94 add r0, pc, r0 */
/* @0xefb98 movt r3, #0x4038 */
/* @0xefb9c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefba0 ldr r0, [pc, #-0x7d0] */
/* @0xefba4 mov r2, #0 */
/* @0xefba8 mov r3, #0 */
/* @0xefbac add r0, pc, r0 */
/* @0xefbb0 movt r3, #0x4039 */
/* @0xefbb4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefbb8 ldr r0, [pc, #-0x7e4] */
/* @0xefbbc mov r2, #0 */
/* @0xefbc0 mov r3, #0 */
/* @0xefbc4 add r0, pc, r0 */
/* @0xefbc8 movt r3, #0x403e */
/* @0xefbcc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefbd0 ldr r0, [pc, #-0x7f8] */
/* @0xefbd4 mov r2, #0 */
/* @0xefbd8 mov r3, #0 */
/* @0xefbdc add r0, pc, r0 */
/* @0xefbe0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefbe4 ldr r0, [pc, #-0x808] */
/* @0xefbe8 mov r2, #0 */
/* @0xefbec mov r3, #0 */
/* @0xefbf0 add r0, pc, r0 */
/* @0xefbf4 movt r3, #0x3ff0 */
/* @0xefbf8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefbfc ldr r0, [pc, #-0x81c] */
/* @0xefc00 mov r3, #1073741824 */
/* @0xefc04 mov r2, #0 */
/* @0xefc08 add r0, pc, r0 */
/* @0xefc0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc10 ldrb r3, [r4] */
/* @0xefc14 cmp r3, #0 */
/* @0xefc18 bne 0xf1170 <_Z24INITIALIZE_Code_Constantv+0x3154> */
/* @0xefc1c ldr r0, [pc, #-0x838] */
/* @0xefc20 mov r2, #0 */
/* @0xefc24 mov r3, #0 */
/* @0xefc28 movt r3, #0x404f */
/* @0xefc2c add r0, pc, r0 */
/* @0xefc30 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc34 ldr r0, [pc, #-0x84c] */
/* @0xefc38 mov r2, #0 */
/* @0xefc3c mov r3, #32768 */
/* @0xefc40 add r0, pc, r0 */
/* @0xefc44 movt r3, #0x404f */
/* @0xefc48 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc4c ldr r0, [pc, #-0x860] */
/* @0xefc50 mov r2, #0 */
/* @0xefc54 mov r3, #0 */
/* @0xefc58 add r0, pc, r0 */
/* @0xefc5c movt r3, #0x4050 */
/* @0xefc60 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc64 ldr r0, [pc, #-0x874] */
/* @0xefc68 mov r2, #0 */
/* @0xefc6c mov r3, #32768 */
/* @0xefc70 add r0, pc, r0 */
/* @0xefc74 movt r3, #0x4050 */
/* @0xefc78 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc7c ldr r0, [pc, #-0x888] */
/* @0xefc80 mov r2, #0 */
/* @0xefc84 mov r3, #49152 */
/* @0xefc88 add r0, pc, r0 */
/* @0xefc8c movt r3, #0x4050 */
/* @0xefc90 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc94 ldr r0, [pc, #-0x89c] */
/* @0xefc98 mov r2, #0 */
/* @0xefc9c mov r3, #0 */
/* @0xefca0 add r0, pc, r0 */
/* @0xefca4 movt r3, #0x4051 */
/* @0xefca8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefcac ldr r0, [pc, #-0x8b0] */
/* @0xefcb0 mov r2, #0 */
/* @0xefcb4 mov r3, #16384 */
/* @0xefcb8 add r0, pc, r0 */
/* @0xefcbc movt r3, #0x4051 */
/* @0xefcc0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefcc4 ldr r0, [pc, #-0x8c4] */
/* @0xefcc8 mov r2, #0 */
/* @0xefccc mov r3, #32768 */
/* @0xefcd0 add r0, pc, r0 */
/* @0xefcd4 movt r3, #0x4051 */
/* @0xefcd8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefcdc ldr r0, [pc, #-0x8d8] */
/* @0xefce0 mov r2, #0 */
/* @0xefce4 mov r3, #49152 */
/* @0xefce8 add r0, pc, r0 */
/* @0xefcec movt r3, #0x4051 */
/* @0xefcf0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefcf4 ldr r0, [pc, #-0x8ec] */
/* @0xefcf8 mov r2, #0 */
/* @0xefcfc mov r3, #0 */
/* @0xefd00 add r0, pc, r0 */
/* @0xefd04 movt r3, #0x4052 */
/* @0xefd08 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd0c ldr r0, [pc, #-0x900] */
/* @0xefd10 mov r2, #0 */
/* @0xefd14 mov r3, #16384 */
/* @0xefd18 add r0, pc, r0 */
/* @0xefd1c movt r3, #0x4052 */
/* @0xefd20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd24 ldr r0, [pc, #-0x914] */
/* @0xefd28 mov r2, #0 */
/* @0xefd2c mov r3, #32768 */
/* @0xefd30 add r0, pc, r0 */
/* @0xefd34 movt r3, #0x4052 */
/* @0xefd38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd3c ldr r0, [pc, #-0x928] */
/* @0xefd40 mov r2, #0 */
/* @0xefd44 mov r3, #49152 */
/* @0xefd48 add r0, pc, r0 */
/* @0xefd4c movt r3, #0x4052 */
/* @0xefd50 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd54 ldr r0, [pc, #-0x93c] */
/* @0xefd58 mov r2, #0 */
/* @0xefd5c mov r3, #0 */
/* @0xefd60 add r0, pc, r0 */
/* @0xefd64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd68 ldr r0, [pc, #-0x94c] */
/* @0xefd6c mov r2, #0 */
/* @0xefd70 mov r3, #0 */
/* @0xefd74 add r0, pc, r0 */
/* @0xefd78 movt r3, #0x3ff0 */
/* @0xefd7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd80 ldr r3, [pc, #-0x960] */
/* @0xefd84 ldr r3, [pc, r3] */
/* @0xefd88 ldrb r3, [r3] */
/* @0xefd8c cmp r3, #0 */
/* @0xefd90 beq 0xf1140 <_Z24INITIALIZE_Code_Constantv+0x3124> */
/* @0xefd94 ldr r0, [pc, #-0x970] */
/* @0xefd98 mov r2, #0 */
/* @0xefd9c mov r3, #0 */
/* @0xefda0 movt r3, #0x3ff0 */
/* @0xefda4 add r0, pc, r0 */
/* @0xefda8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefdac ldr r0, [pc, #-0x984] */
/* @0xefdb0 mov r2, #0 */
/* @0xefdb4 mov r3, #1073741824 */
/* @0xefdb8 add r0, pc, r0 */
/* @0xefdbc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefdc0 ldr r0, [pc, #-0x994] */
/* @0xefdc4 mov r2, #0 */
/* @0xefdc8 mov r3, #0 */
/* @0xefdcc add r0, pc, r0 */
/* @0xefdd0 movt r3, #0x4010 */
/* @0xefdd4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefdd8 ldr r0, [pc, #-0x9a8] */
/* @0xefddc mov r2, #0 */
/* @0xefde0 mov r3, #0 */
/* @0xefde4 add r0, pc, r0 */
/* @0xefde8 movt r3, #0x4020 */
/* @0xefdec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefdf0 ldr r0, [pc, #-0x9bc] */
/* @0xefdf4 mov r2, #0 */
/* @0xefdf8 mov r3, #0 */
/* @0xefdfc add r0, pc, r0 */
/* @0xefe00 movt r3, #0x4030 */
/* @0xefe04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe08 ldr r0, [pc, #-0x9d0] */
/* @0xefe0c mov r2, #0 */
/* @0xefe10 mov r3, #0 */
/* @0xefe14 add r0, pc, r0 */
/* @0xefe18 movt r3, #0x4040 */
/* @0xefe1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe20 ldr r0, [pc, #-0x9e4] */
/* @0xefe24 mov r2, #0 */
/* @0xefe28 mov r3, #0 */
/* @0xefe2c add r0, pc, r0 */
/* @0xefe30 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe34 ldr r0, [pc, #-0x9f4] */
/* @0xefe38 mov r2, #0 */
/* @0xefe3c mov r3, #0 */
/* @0xefe40 add r0, pc, r0 */
/* @0xefe44 movt r3, #0xbff0 */
/* @0xefe48 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe4c ldr r0, [pc, #-0xa08] */
/* @0xefe50 mov r2, #0 */
/* @0xefe54 mov r3, #-1073741824 */
/* @0xefe58 add r0, pc, r0 */
/* @0xefe5c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe60 ldr r0, [pc, #-0xa18] */
/* @0xefe64 mov r2, #0 */
/* @0xefe68 mov r3, #0 */
/* @0xefe6c add r0, pc, r0 */
/* @0xefe70 movt r3, #0xc008 */
/* @0xefe74 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe78 ldr r0, [pc, #-0xa2c] */
/* @0xefe7c mov r2, #0 */
/* @0xefe80 mov r3, #0 */
/* @0xefe84 add r0, pc, r0 */
/* @0xefe88 movt r3, #0xc010 */
/* @0xefe8c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe90 ldr r0, [pc, #-0xa40] */
/* @0xefe94 mov r2, #0 */
/* @0xefe98 mov r3, #0 */
/* @0xefe9c add r0, pc, r0 */
/* @0xefea0 movt r3, #0xc018 */
/* @0xefea4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefea8 ldr r0, [pc, #-0xa54] */
/* @0xefeac mov r2, #0 */
/* @0xefeb0 mov r3, #0 */
/* @0xefeb4 add r0, pc, r0 */
/* @0xefeb8 movt r3, #0xc01c */
/* @0xefebc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefec0 ldr r0, [pc, #-0xa68] */
/* @0xefec4 mov r2, #0 */
/* @0xefec8 mov r3, #0 */
/* @0xefecc add r0, pc, r0 */
/* @0xefed0 movt r3, #0xc020 */
/* @0xefed4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefed8 ldr r0, [pc, #-0xa7c] */
/* @0xefedc mov r2, #0 */
/* @0xefee0 mov r3, #0 */
/* @0xefee4 add r0, pc, r0 */
/* @0xefee8 movt r3, #0xc022 */
/* @0xefeec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefef0 ldr r0, [pc, #-0xa90] */
/* @0xefef4 mov r2, #0 */
/* @0xefef8 mov r3, #0 */
/* @0xefefc add r0, pc, r0 */
/* @0xeff00 movt r3, #0xc024 */
/* @0xeff04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff08 ldr r0, [pc, #-0xaa4] */
/* @0xeff0c mov r2, #0 */
/* @0xeff10 mov r3, #0 */
/* @0xeff14 add r0, pc, r0 */
/* @0xeff18 movt r3, #0xc026 */
/* @0xeff1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff20 ldr r0, [pc, #-0xab8] */
/* @0xeff24 mov r2, #0 */
/* @0xeff28 mov r3, #0 */
/* @0xeff2c add r0, pc, r0 */
/* @0xeff30 movt r3, #0xc028 */
/* @0xeff34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff38 ldr r0, [pc, #-0xacc] */
/* @0xeff3c mov r2, #0 */
/* @0xeff40 mov r3, #0 */
/* @0xeff44 add r0, pc, r0 */
/* @0xeff48 movt r3, #0xc02a */
/* @0xeff4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff50 ldr r0, [pc, #-0xae0] */
/* @0xeff54 mov r2, #0 */
/* @0xeff58 mov r3, #0 */
/* @0xeff5c add r0, pc, r0 */
/* @0xeff60 movt r3, #0xc02c */
/* @0xeff64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff68 ldr r0, [pc, #-0xaf4] */
/* @0xeff6c mov r2, #0 */
/* @0xeff70 mov r3, #0 */
/* @0xeff74 add r0, pc, r0 */
/* @0xeff78 movt r3, #0xc02e */
/* @0xeff7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff80 ldr r0, [pc, #-0xb08] */
/* @0xeff84 mov r2, #0 */
/* @0xeff88 mov r3, #0 */
/* @0xeff8c add r0, pc, r0 */
/* @0xeff90 movt r3, #0xc030 */
/* @0xeff94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff98 ldr r0, [pc, #-0xb1c] */
/* @0xeff9c mov r2, #0 */
/* @0xeffa0 mov r3, #0 */
/* @0xeffa4 add r0, pc, r0 */
/* @0xeffa8 movt r3, #0xc031 */
/* @0xeffac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeffb0 ldr r0, [pc, #-0xb30] */
/* @0xeffb4 mov r2, #0 */
/* @0xeffb8 mov r3, #0 */
/* @0xeffbc add r0, pc, r0 */
/* @0xeffc0 movt r3, #0xc032 */
/* @0xeffc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeffc8 ldr r0, [pc, #-0xb44] */
/* @0xeffcc mov r2, #0 */
/* @0xeffd0 mov r3, #0 */
/* @0xeffd4 add r0, pc, r0 */
/* @0xeffd8 movt r3, #0xc033 */
/* @0xeffdc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeffe0 ldr r0, [pc, #-0xb58] */
/* @0xeffe4 mov r2, #0 */
/* @0xeffe8 mov r3, #0 */
/* @0xeffec add r0, pc, r0 */
/* @0xefff0 movt r3, #0xc034 */
/* @0xefff4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefff8 ldr r0, [pc, #-0xb6c] */
/* @0xefffc mov r2, #0 */
/* @0xf0000 mov r3, #0 */
/* @0xf0004 add r0, pc, r0 */
/* @0xf0008 movt r3, #0xc035 */
/* @0xf000c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0010 ldr r0, [pc, #-0xb80] */
/* @0xf0014 mov r2, #0 */
/* @0xf0018 mov r3, #0 */
/* @0xf001c add r0, pc, r0 */
/* @0xf0020 movt r3, #0xc036 */
/* @0xf0024 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0028 ldr r0, [pc, #-0xb94] */
/* @0xf002c mov r2, #0 */
/* @0xf0030 mov r3, #0 */
/* @0xf0034 add r0, pc, r0 */
/* @0xf0038 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf003c ldr r0, [pc, #-0xba4] */
/* @0xf0040 mov r2, #0 */
/* @0xf0044 mov r3, #0 */
/* @0xf0048 add r0, pc, r0 */
/* @0xf004c movt r3, #0x3ff0 */
/* @0xf0050 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0054 ldr r0, [pc, #-0xbb8] */
/* @0xf0058 mov r2, #0 */
/* @0xf005c mov r3, #1073741824 */
/* @0xf0060 add r0, pc, r0 */
/* @0xf0064 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0068 ldr r0, [pc, #-0xbc8] */
/* @0xf006c mov r2, #0 */
/* @0xf0070 mov r3, #0 */
/* @0xf0074 add r0, pc, r0 */
/* @0xf0078 movt r3, #0x4008 */
/* @0xf007c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0080 ldr r0, [pc, #-0xbdc] */
/* @0xf0084 mov r2, #0 */
/* @0xf0088 mov r3, #0 */
/* @0xf008c add r0, pc, r0 */
/* @0xf0090 movt r3, #0x4010 */
/* @0xf0094 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0098 ldr r0, [pc, #-0xbf0] */
/* @0xf009c mov r2, #0 */
/* @0xf00a0 mov r3, #0 */
/* @0xf00a4 add r0, pc, r0 */
/* @0xf00a8 movt r3, #0x4014 */
/* @0xf00ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf00b0 ldr r0, [pc, #-0xc04] */
/* @0xf00b4 mov r2, #0 */
/* @0xf00b8 mov r3, #0 */
/* @0xf00bc add r0, pc, r0 */
/* @0xf00c0 movt r3, #0x4018 */
/* @0xf00c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf00c8 ldr r0, [pc, #-0xc18] */
/* @0xf00cc mov r2, #0 */
/* @0xf00d0 mov r3, #0 */
/* @0xf00d4 add r0, pc, r0 */
/* @0xf00d8 movt r3, #0x401c */
/* @0xf00dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf00e0 ldr r0, [pc, #-0xc2c] */
/* @0xf00e4 mov r2, #0 */
/* @0xf00e8 mov r3, #0 */
/* @0xf00ec add r0, pc, r0 */
/* @0xf00f0 movt r3, #0x4020 */
/* @0xf00f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf00f8 ldr r0, [pc, #-0xc40] */
/* @0xf00fc mov r2, #0 */
/* @0xf0100 mov r3, #0 */
/* @0xf0104 add r0, pc, r0 */
/* @0xf0108 movt r3, #0x4022 */
/* @0xf010c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0110 ldr r0, [pc, #-0xc54] */
/* @0xf0114 mov r2, #0 */
/* @0xf0118 mov r3, #0 */
/* @0xf011c add r0, pc, r0 */
/* @0xf0120 movt r3, #0x4024 */
/* @0xf0124 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0128 ldr r0, [pc, #-0xc68] */
/* @0xf012c mov r2, #0 */
/* @0xf0130 mov r3, #0 */
/* @0xf0134 add r0, pc, r0 */
/* @0xf0138 movt r3, #0x4026 */
/* @0xf013c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0140 ldr r0, [pc, #-0xc7c] */
/* @0xf0144 mov r2, #0 */
/* @0xf0148 mov r3, #0 */
/* @0xf014c add r0, pc, r0 */
/* @0xf0150 movt r3, #0x4028 */
/* @0xf0154 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0158 ldr r0, [pc, #-0xc90] */
/* @0xf015c mov r2, #0 */
/* @0xf0160 mov r3, #0 */
/* @0xf0164 add r0, pc, r0 */
/* @0xf0168 movt r3, #0x402a */
/* @0xf016c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0170 ldr r0, [pc, #-0xca4] */
/* @0xf0174 mov r2, #0 */
/* @0xf0178 mov r3, #0 */
/* @0xf017c add r0, pc, r0 */
/* @0xf0180 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0184 ldr r0, [pc, #-0xcb4] */
/* @0xf0188 mov r2, #0 */
/* @0xf018c mov r3, #0 */
/* @0xf0190 add r0, pc, r0 */
/* @0xf0194 movt r3, #0x3ff0 */
/* @0xf0198 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf019c ldr r0, [pc, #-0xcc8] */
/* @0xf01a0 mov r2, #0 */
/* @0xf01a4 mov r3, #1073741824 */
/* @0xf01a8 add r0, pc, r0 */
/* @0xf01ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf01b0 ldr r0, [pc, #-0xcd8] */
/* @0xf01b4 mov r2, #0 */
/* @0xf01b8 mov r3, #0 */
/* @0xf01bc add r0, pc, r0 */
/* @0xf01c0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf01c4 ldr r0, [pc, #-0xce8] */
/* @0xf01c8 mov r2, #0 */
/* @0xf01cc mov r3, #0 */
/* @0xf01d0 add r0, pc, r0 */
/* @0xf01d4 movt r3, #0x3ff0 */
/* @0xf01d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf01dc ldr r0, [pc, #-0xcfc] */
/* @0xf01e0 mov r2, #0 */
/* @0xf01e4 mov r3, #1073741824 */
/* @0xf01e8 add r0, pc, r0 */
/* @0xf01ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf01f0 ldr r0, [pc, #-0xd0c] */
/* @0xf01f4 mov r2, #0 */
/* @0xf01f8 mov r3, #0 */
/* @0xf01fc add r0, pc, r0 */
/* @0xf0200 movt r3, #0x4008 */
/* @0xf0204 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0208 ldr r0, [pc, #-0xd20] */
/* @0xf020c mov r2, #0 */
/* @0xf0210 mov r3, #0 */
/* @0xf0214 add r0, pc, r0 */
/* @0xf0218 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf021c ldr r0, [pc, #-0xd30] */
/* @0xf0220 mov r2, #0 */
/* @0xf0224 mov r3, #0 */
/* @0xf0228 add r0, pc, r0 */
/* @0xf022c movt r3, #0x3ff0 */
/* @0xf0230 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0234 ldr r0, [pc, #-0xd44] */
/* @0xf0238 mov r2, #0 */
/* @0xf023c mov r3, #1073741824 */
/* @0xf0240 add r0, pc, r0 */
/* @0xf0244 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0248 ldr r0, [pc, #-0xd54] */
/* @0xf024c mov r2, #0 */
/* @0xf0250 mov r3, #0 */
/* @0xf0254 add r0, pc, r0 */
/* @0xf0258 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf025c ldr r0, [pc, #-0xd64] */
/* @0xf0260 mov r2, #0 */
/* @0xf0264 mov r3, #0 */
/* @0xf0268 add r0, pc, r0 */
/* @0xf026c movt r3, #0x3ff0 */
/* @0xf0270 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0274 ldr r0, [pc, #-0xd78] */
/* @0xf0278 mov r2, #0 */
/* @0xf027c mov r3, #0 */
/* @0xf0280 add r0, pc, r0 */
/* @0xf0284 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0288 ldr r0, [pc, #-0xd88] */
/* @0xf028c mov r2, #0 */
/* @0xf0290 mov r3, #0 */
/* @0xf0294 add r0, pc, r0 */
/* @0xf0298 movt r3, #0x3ff0 */
/* @0xf029c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02a0 ldr r0, [pc, #-0xd9c] */
/* @0xf02a4 mov r2, #0 */
/* @0xf02a8 mov r3, #1073741824 */
/* @0xf02ac add r0, pc, r0 */
/* @0xf02b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02b4 ldr r0, [pc, #-0xdac] */
/* @0xf02b8 mov r2, #0 */
/* @0xf02bc mov r3, #0 */
/* @0xf02c0 add r0, pc, r0 */
/* @0xf02c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02c8 ldr r0, [pc, #-0xdbc] */
/* @0xf02cc mov r2, #0 */
/* @0xf02d0 mov r3, #0 */
/* @0xf02d4 add r0, pc, r0 */
/* @0xf02d8 movt r3, #0x3ff0 */
/* @0xf02dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02e0 ldr r0, [pc, #-0xdd0] */
/* @0xf02e4 mov r2, #0 */
/* @0xf02e8 mov r3, #1073741824 */
/* @0xf02ec add r0, pc, r0 */
/* @0xf02f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02f4 ldr r0, [pc, #-0xde0] */
/* @0xf02f8 mov r2, #0 */
/* @0xf02fc mov r3, #0 */
/* @0xf0300 add r0, pc, r0 */
/* @0xf0304 movt r3, #0x4008 */
/* @0xf0308 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf030c ldr r0, [pc, #-0xdf4] */
/* @0xf0310 mov r2, #0 */
/* @0xf0314 mov r3, #0 */
/* @0xf0318 add r0, pc, r0 */
/* @0xf031c movt r3, #0x4010 */
/* @0xf0320 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0324 ldr r0, [pc, #-0xe08] */
/* @0xf0328 mov r2, #0 */
/* @0xf032c mov r3, #0 */
/* @0xf0330 add r0, pc, r0 */
/* @0xf0334 movt r3, #0x4014 */
/* @0xf0338 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf033c ldr r0, [pc, #-0xe1c] */
/* @0xf0340 mov r2, #0 */
/* @0xf0344 mov r3, #0 */
/* @0xf0348 add r0, pc, r0 */
/* @0xf034c movt r3, #0x4018 */
/* @0xf0350 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0354 ldr r0, [pc, #-0xe30] */
/* @0xf0358 mov r2, #0 */
/* @0xf035c mov r3, #0 */
/* @0xf0360 add r0, pc, r0 */
/* @0xf0364 movt r3, #0x401c */
/* @0xf0368 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf036c ldr r0, [pc, #-0xe44] */
/* @0xf0370 mov r2, #0 */
/* @0xf0374 mov r3, #0 */
/* @0xf0378 add r0, pc, r0 */
/* @0xf037c movt r3, #0x4020 */
/* @0xf0380 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0384 ldr r0, [pc, #-0xe58] */
/* @0xf0388 mov r2, #0 */
/* @0xf038c mov r3, #0 */
/* @0xf0390 add r0, pc, r0 */
/* @0xf0394 movt r3, #0x4022 */
/* @0xf0398 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf039c ldr r0, [pc, #-0xe6c] */
/* @0xf03a0 mov r2, #0 */
/* @0xf03a4 mov r3, #0 */
/* @0xf03a8 add r0, pc, r0 */
/* @0xf03ac movt r3, #0x4024 */
/* @0xf03b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf03b4 ldr r0, [pc, #-0xe80] */
/* @0xf03b8 mov r2, #0 */
/* @0xf03bc mov r3, #0 */
/* @0xf03c0 add r0, pc, r0 */
/* @0xf03c4 movt r3, #0x4026 */
/* @0xf03c8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf03cc ldr r0, [pc, #-0xe94] */
/* @0xf03d0 mov r2, #0 */
/* @0xf03d4 mov r3, #0 */
/* @0xf03d8 add r0, pc, r0 */
/* @0xf03dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf03e0 ldr r0, [pc, #-0xea4] */
/* @0xf03e4 mov r2, #0 */
/* @0xf03e8 mov r3, #0 */
/* @0xf03ec add r0, pc, r0 */
/* @0xf03f0 movt r3, #0x3ff0 */
/* @0xf03f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf03f8 ldr r0, [pc, #-0xeb8] */
/* @0xf03fc mov r2, #0 */
/* @0xf0400 mov r3, #1073741824 */
/* @0xf0404 add r0, pc, r0 */
/* @0xf0408 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf040c ldr r0, [pc, #-0xec8] */
/* @0xf0410 mov r2, #0 */
/* @0xf0414 mov r3, #0 */
/* @0xf0418 add r0, pc, r0 */
/* @0xf041c movt r3, #0x4008 */
/* @0xf0420 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0424 ldr r0, [pc, #-0xedc] */
/* @0xf0428 mov r2, #0 */
/* @0xf042c mov r3, #0 */
/* @0xf0430 add r0, pc, r0 */
/* @0xf0434 movt r3, #0xbff0 */
/* @0xf0438 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf043c ldr r0, [pc, #-0xef0] */
/* @0xf0440 mov r2, #0 */
/* @0xf0444 mov r3, #0 */
/* @0xf0448 add r0, pc, r0 */
/* @0xf044c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0450 ldr r0, [pc, #-0xf00] */
/* @0xf0454 mov r2, #0 */
/* @0xf0458 mov r3, #0 */
/* @0xf045c add r0, pc, r0 */
/* @0xf0460 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0464 ldr r0, [pc, #-0xf10] */
/* @0xf0468 mov r2, #0 */
/* @0xf046c mov r3, #0 */
/* @0xf0470 add r0, pc, r0 */
/* @0xf0474 movt r3, #0x3ff0 */
/* @0xf0478 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf047c ldrb r3, [r4] */
/* @0xf0480 cmp r3, #0 */
/* @0xf0484 bne 0xf049c <_Z24INITIALIZE_Code_Constantv+0x2480> */
/* @0xf0488 ldr r0, [pc, #-0xf30] */
/* @0xf048c mov r2, #0 */
/* @0xf0490 mov r3, #1073741824 */
/* @0xf0494 add r0, pc, r0 */
/* @0xf0498 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf049c ldr r0, [pc, #-0xf40] */
/* @0xf04a0 mov r2, #0 */
/* @0xf04a4 mov r3, #0 */
/* @0xf04a8 movt r3, #0x4008 */
/* @0xf04ac add r0, pc, r0 */
/* @0xf04b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf04b4 ldr r0, [pc, #-0xf54] */
/* @0xf04b8 mov r2, #0 */
/* @0xf04bc mov r3, #0 */
/* @0xf04c0 add r0, pc, r0 */
/* @0xf04c4 movt r3, #0x4010 */
/* @0xf04c8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf04cc ldr r0, [pc, #-0xf68] */
/* @0xf04d0 mov r2, #0 */
/* @0xf04d4 mov r3, #0 */
/* @0xf04d8 add r0, pc, r0 */
/* @0xf04dc movt r3, #0x4014 */
/* @0xf04e0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf04e4 ldr r0, [pc, #-0xf7c] */
/* @0xf04e8 mov r2, #0 */
/* @0xf04ec mov r3, #0 */
/* @0xf04f0 add r0, pc, r0 */
/* @0xf04f4 movt r3, #0x4018 */
/* @0xf04f8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf04fc ldr r0, [pc, #-0xf90] */
/* @0xf0500 mov r2, #0 */
/* @0xf0504 mov r3, #0 */
/* @0xf0508 add r0, pc, r0 */
/* @0xf050c movt r3, #0x401c */
/* @0xf0510 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0514 ldr r0, [pc, #-0xfa4] */
/* @0xf0518 mov r2, #0 */
/* @0xf051c mov r3, #0 */
/* @0xf0520 add r0, pc, r0 */
/* @0xf0524 movt r3, #0x4020 */
/* @0xf0528 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf052c ldr r0, [pc, #-0xfb8] */
/* @0xf0530 mov r2, #0 */
/* @0xf0534 mov r3, #0 */
/* @0xf0538 add r0, pc, r0 */
/* @0xf053c movt r3, #0x4022 */
/* @0xf0540 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0544 ldr r0, [pc, #-0xfcc] */
/* @0xf0548 mov r2, #0 */
/* @0xf054c mov r3, #0 */
/* @0xf0550 add r0, pc, r0 */
/* @0xf0554 movt r3, #0x4024 */
/* @0xf0558 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf055c ldr r0, [pc, #-0xfe0] */
/* @0xf0560 mov r2, #0 */
/* @0xf0564 mov r3, #0 */
/* @0xf0568 add r0, pc, r0 */
/* @0xf056c movt r3, #0x4026 */
/* @0xf0570 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0574 ldr r0, [pc, #-0xff4] */
/* @0xf0578 mov r2, #0 */
/* @0xf057c mov r3, #0 */
/* @0xf0580 add r0, pc, r0 */
/* @0xf0584 movt r3, #0x4028 */
/* @0xf0588 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf058c ldr r0, [pc, #0xf18] */
/* @0xf0590 mov r2, #0 */
/* @0xf0594 mov r3, #0 */
/* @0xf0598 add r0, pc, r0 */
/* @0xf059c movt r3, #0x402a */
/* @0xf05a0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf05a4 ldr r0, [pc, #0xf04] */
/* @0xf05a8 mov r2, #0 */
/* @0xf05ac mov r3, #0 */
/* @0xf05b0 add r0, pc, r0 */
/* @0xf05b4 movt r3, #0x402c */
/* @0xf05b8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf05bc ldr r0, [pc, #0xef0] */
/* @0xf05c0 mov r2, #0 */
/* @0xf05c4 mov r3, #0 */
/* @0xf05c8 add r0, pc, r0 */
/* @0xf05cc movt r3, #0x402e */
/* @0xf05d0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf05d4 ldr r0, [pc, #0xedc] */
/* @0xf05d8 mov r2, #0 */
/* @0xf05dc mov r3, #0 */
/* @0xf05e0 add r0, pc, r0 */
/* @0xf05e4 movt r3, #0x4030 */
/* @0xf05e8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf05ec ldr r0, [pc, #0xec8] */
/* @0xf05f0 mov r2, #0 */
/* @0xf05f4 mov r3, #0 */
/* @0xf05f8 add r0, pc, r0 */
/* @0xf05fc movt r3, #0x4031 */
/* @0xf0600 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0604 ldr r0, [pc, #0xeb4] */
/* @0xf0608 mov r2, #0 */
/* @0xf060c mov r3, #0 */
/* @0xf0610 add r0, pc, r0 */
/* @0xf0614 movt r3, #0x4032 */
/* @0xf0618 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf061c ldr r0, [pc, #0xea0] */
/* @0xf0620 mov r2, #0 */
/* @0xf0624 mov r3, #0 */
/* @0xf0628 add r0, pc, r0 */
/* @0xf062c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0630 ldr r0, [pc, #0xe90] */
/* @0xf0634 mov r2, #0 */
/* @0xf0638 mov r3, #0 */
/* @0xf063c add r0, pc, r0 */
/* @0xf0640 movt r3, #0x3ff0 */
/* @0xf0644 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0648 ldr r0, [pc, #0xe7c] */
/* @0xf064c mov r2, #0 */
/* @0xf0650 mov r3, #1073741824 */
/* @0xf0654 add r0, pc, r0 */
/* @0xf0658 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf065c ldr r0, [pc, #0xe6c] */
/* @0xf0660 mov r2, #0 */
/* @0xf0664 mov r3, #0 */
/* @0xf0668 add r0, pc, r0 */
/* @0xf066c movt r3, #0x4008 */
/* @0xf0670 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0674 ldr r0, [pc, #0xe58] */
/* @0xf0678 mov r2, #0 */
/* @0xf067c mov r3, #0 */
/* @0xf0680 add r0, pc, r0 */
/* @0xf0684 movt r3, #0x4010 */
/* @0xf0688 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf068c ldr r0, [pc, #0xe44] */
/* @0xf0690 mov r2, #0 */
/* @0xf0694 mov r3, #0 */
/* @0xf0698 add r0, pc, r0 */
/* @0xf069c movt r3, #0x4014 */
/* @0xf06a0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf06a4 ldr r0, [pc, #0xe30] */
/* @0xf06a8 mov r2, #0 */
/* @0xf06ac mov r3, #0 */
/* @0xf06b0 add r0, pc, r0 */
/* @0xf06b4 movt r3, #0x4018 */
/* @0xf06b8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf06bc ldr r0, [pc, #0xe1c] */
/* @0xf06c0 mov r2, #0 */
/* @0xf06c4 mov r3, #0 */
/* @0xf06c8 add r0, pc, r0 */
/* @0xf06cc movt r3, #0x4020 */
/* @0xf06d0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf06d4 ldr r0, [pc, #0xe08] */
/* @0xf06d8 mov r2, #0 */
/* @0xf06dc mov r3, #0 */
/* @0xf06e0 add r0, pc, r0 */
/* @0xf06e4 movt r3, #0x401c */
/* @0xf06e8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf06ec ldr r0, [pc, #0xdf4] */
/* @0xf06f0 mov r2, #0 */
/* @0xf06f4 mov r3, #0 */
/* @0xf06f8 add r0, pc, r0 */
/* @0xf06fc movt r3, #0x4022 */
/* @0xf0700 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0704 ldr r0, [pc, #0xde0] */
/* @0xf0708 mov r2, #0 */
/* @0xf070c mov r3, #0 */
/* @0xf0710 add r0, pc, r0 */
/* @0xf0714 movt r3, #0x4024 */
/* @0xf0718 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf071c ldr r0, [pc, #0xdcc] */
/* @0xf0720 mov r2, #0 */
/* @0xf0724 mov r3, #0 */
/* @0xf0728 add r0, pc, r0 */
/* @0xf072c movt r3, #0x4026 */
/* @0xf0730 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0734 ldr r0, [pc, #0xdb8] */
/* @0xf0738 mov r2, #0 */
/* @0xf073c mov r3, #0 */
/* @0xf0740 add r0, pc, r0 */
/* @0xf0744 movt r3, #0x4028 */
/* @0xf0748 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf074c ldr r0, [pc, #0xda4] */
/* @0xf0750 mov r2, #0 */
/* @0xf0754 mov r3, #0 */
/* @0xf0758 add r0, pc, r0 */
/* @0xf075c movt r3, #0x402a */
/* @0xf0760 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0764 ldr r0, [pc, #0xd90] */
/* @0xf0768 mov r2, #0 */
/* @0xf076c mov r3, #0 */
/* @0xf0770 add r0, pc, r0 */
/* @0xf0774 movt r3, #0x402c */
/* @0xf0778 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf077c ldr r0, [pc, #0xd7c] */
/* @0xf0780 mov r2, #0 */
/* @0xf0784 mov r3, #0 */
/* @0xf0788 add r0, pc, r0 */
/* @0xf078c movt r3, #0x402e */
/* @0xf0790 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0794 ldr r0, [pc, #0xd68] */
/* @0xf0798 mov r2, #0 */
/* @0xf079c mov r3, #0 */
/* @0xf07a0 add r0, pc, r0 */
/* @0xf07a4 movt r3, #0x4030 */
/* @0xf07a8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf07ac ldr r0, [pc, #0xd54] */
/* @0xf07b0 mov r2, #0 */
/* @0xf07b4 mov r3, #0 */
/* @0xf07b8 add r0, pc, r0 */
/* @0xf07bc movt r3, #0x4031 */
/* @0xf07c0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf07c4 ldr r0, [pc, #0xd40] */
/* @0xf07c8 mov r2, #0 */
/* @0xf07cc mov r3, #0 */
/* @0xf07d0 add r0, pc, r0 */
/* @0xf07d4 movt r3, #0x4032 */
/* @0xf07d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf07dc ldr r0, [pc, #0xd2c] */
/* @0xf07e0 mov r2, #0 */
/* @0xf07e4 mov r3, #0 */
/* @0xf07e8 add r0, pc, r0 */
/* @0xf07ec movt r3, #0x3ff0 */
/* @0xf07f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf07f4 ldr r0, [pc, #0xd18] */
/* @0xf07f8 mov r2, #0 */
/* @0xf07fc mov r3, #1073741824 */
/* @0xf0800 add r0, pc, r0 */
/* @0xf0804 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0808 ldr r0, [pc, #0xd08] */
/* @0xf080c mov r2, #0 */
/* @0xf0810 mov r3, #0 */
/* @0xf0814 add r0, pc, r0 */
/* @0xf0818 movt r3, #0x4010 */
/* @0xf081c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0820 ldr r0, [pc, #0xcf4] */
/* @0xf0824 mov r2, #0 */
/* @0xf0828 mov r3, #0 */
/* @0xf082c add r0, pc, r0 */
/* @0xf0830 movt r3, #0x4020 */
/* @0xf0834 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0838 ldr r0, [pc, #0xce0] */
/* @0xf083c mov r2, #0 */
/* @0xf0840 mov r3, #0 */
/* @0xf0844 add r0, pc, r0 */
/* @0xf0848 movt r3, #0x4030 */
/* @0xf084c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0850 ldr r0, [pc, #0xccc] */
/* @0xf0854 mov r2, #0 */
/* @0xf0858 mov r3, #0 */
/* @0xf085c add r0, pc, r0 */
/* @0xf0860 movt r3, #0x4040 */
/* @0xf0864 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0868 ldr r0, [pc, #0xcb8] */
/* @0xf086c mov r2, #0 */
/* @0xf0870 mov r3, #0 */
/* @0xf0874 add r0, pc, r0 */
/* @0xf0878 movt r3, #0x4050 */
/* @0xf087c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0880 ldr r0, [pc, #0xca4] */
/* @0xf0884 mov r2, #0 */
/* @0xf0888 mov r3, #0 */
/* @0xf088c add r0, pc, r0 */
/* @0xf0890 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0894 ldr r0, [pc, #0xc94] */
/* @0xf0898 mov r2, #0 */
/* @0xf089c mov r3, #0 */
/* @0xf08a0 add r0, pc, r0 */
/* @0xf08a4 movt r3, #0x3ff0 */
/* @0xf08a8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf08ac ldr r0, [pc, #0xc80] */
/* @0xf08b0 mov r2, #0 */
/* @0xf08b4 mov r3, #1073741824 */
/* @0xf08b8 add r0, pc, r0 */
/* @0xf08bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf08c0 ldr r0, [pc, #0xc70] */
/* @0xf08c4 mov r2, #0 */
/* @0xf08c8 mov r3, #0 */
/* @0xf08cc add r0, pc, r0 */
/* @0xf08d0 movt r3, #0x4008 */
/* @0xf08d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf08d8 ldr r0, [pc, #0xc5c] */
/* @0xf08dc mov r2, #0 */
/* @0xf08e0 mov r3, #0 */
/* @0xf08e4 add r0, pc, r0 */
/* @0xf08e8 movt r3, #0x4010 */
/* @0xf08ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf08f0 ldr r0, [pc, #0xc48] */
/* @0xf08f4 mov r2, #0 */
/* @0xf08f8 mov r3, #0 */
/* @0xf08fc add r0, pc, r0 */
/* @0xf0900 movt r3, #0x4014 */
/* @0xf0904 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0908 ldr r0, [pc, #0xc34] */
/* @0xf090c mov r2, #0 */
/* @0xf0910 mov r3, #0 */
/* @0xf0914 add r0, pc, r0 */
/* @0xf0918 movt r3, #0x4018 */
/* @0xf091c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0920 ldr r0, [pc, #0xc20] */
/* @0xf0924 mov r2, #0 */
/* @0xf0928 mov r3, #0 */
/* @0xf092c add r0, pc, r0 */
/* @0xf0930 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0934 ldr r0, [pc, #0xc10] */
/* @0xf0938 mov r2, #0 */
/* @0xf093c mov r3, #0 */
/* @0xf0940 add r0, pc, r0 */
/* @0xf0944 movt r3, #0x3ff0 */
/* @0xf0948 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf094c ldr r0, [pc, #0xbfc] */
/* @0xf0950 mov r2, #0 */
/* @0xf0954 mov r3, #0 */
/* @0xf0958 add r0, pc, r0 */
/* @0xf095c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0960 ldr r0, [pc, #0xbec] */
/* @0xf0964 mov r2, #0 */
/* @0xf0968 mov r3, #0 */
/* @0xf096c add r0, pc, r0 */
/* @0xf0970 movt r3, #0x3ff0 */
/* @0xf0974 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0978 ldr r0, [pc, #0xbd8] */
/* @0xf097c mov r2, #0 */
/* @0xf0980 mov r3, #1073741824 */
/* @0xf0984 add r0, pc, r0 */
/* @0xf0988 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf098c ldr r0, [pc, #0xbc8] */
/* @0xf0990 mov r2, #0 */
/* @0xf0994 mov r3, #0 */
/* @0xf0998 add r0, pc, r0 */
/* @0xf099c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09a0 ldr r0, [pc, #0xbb8] */
/* @0xf09a4 mov r2, #0 */
/* @0xf09a8 mov r3, #0 */
/* @0xf09ac add r0, pc, r0 */
/* @0xf09b0 movt r3, #0x3ff0 */
/* @0xf09b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09b8 ldr r0, [pc, #0xba4] */
/* @0xf09bc mov r2, #0 */
/* @0xf09c0 mov r3, #1073741824 */
/* @0xf09c4 add r0, pc, r0 */
/* @0xf09c8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09cc ldr r0, [pc, #0xb94] */
/* @0xf09d0 mov r2, #0 */
/* @0xf09d4 mov r3, #0 */
/* @0xf09d8 add r0, pc, r0 */
/* @0xf09dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09e0 ldr r0, [pc, #0xb84] */
/* @0xf09e4 mov r2, #0 */
/* @0xf09e8 mov r3, #0 */
/* @0xf09ec add r0, pc, r0 */
/* @0xf09f0 movt r3, #0x3ff0 */
/* @0xf09f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09f8 ldr r0, [pc, #0xb70] */
/* @0xf09fc mov r2, #0 */
/* @0xf0a00 mov r3, #1073741824 */
/* @0xf0a04 add r0, pc, r0 */
/* @0xf0a08 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a0c ldr r0, [pc, #0xb60] */
/* @0xf0a10 mov r2, #0 */
/* @0xf0a14 mov r3, #0 */
/* @0xf0a18 add r0, pc, r0 */
/* @0xf0a1c movt r3, #0x4008 */
/* @0xf0a20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a24 ldr r0, [pc, #0xb4c] */
/* @0xf0a28 mov r2, #0 */
/* @0xf0a2c mov r3, #0 */
/* @0xf0a30 add r0, pc, r0 */
/* @0xf0a34 movt r3, #0x4010 */
/* @0xf0a38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a3c ldr r0, [pc, #0xb38] */
/* @0xf0a40 mov r2, #0 */
/* @0xf0a44 mov r3, #0 */
/* @0xf0a48 add r0, pc, r0 */
/* @0xf0a4c movt r3, #0x4014 */
/* @0xf0a50 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a54 ldr r0, [pc, #0xb24] */
/* @0xf0a58 mov r2, #0 */
/* @0xf0a5c mov r3, #0 */
/* @0xf0a60 add r0, pc, r0 */
/* @0xf0a64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a68 ldr r0, [pc, #0xb14] */
/* @0xf0a6c mov r2, #0 */
/* @0xf0a70 mov r3, #0 */
/* @0xf0a74 add r0, pc, r0 */
/* @0xf0a78 movt r3, #0x3ff0 */
/* @0xf0a7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a80 ldr r0, [pc, #0xb00] */
/* @0xf0a84 mov r2, #0 */
/* @0xf0a88 mov r3, #1073741824 */
/* @0xf0a8c add r0, pc, r0 */
/* @0xf0a90 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a94 ldr r0, [pc, #0xaf0] */
/* @0xf0a98 mov r2, #0 */
/* @0xf0a9c mov r3, #0 */
/* @0xf0aa0 add r0, pc, r0 */
/* @0xf0aa4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0aa8 ldr r0, [pc, #0xae0] */
/* @0xf0aac mov r2, #0 */
/* @0xf0ab0 mov r3, #0 */
/* @0xf0ab4 add r0, pc, r0 */
/* @0xf0ab8 movt r3, #0x3ff0 */
/* @0xf0abc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ac0 ldr r0, [pc, #0xacc] */
/* @0xf0ac4 mov r2, #0 */
/* @0xf0ac8 mov r3, #1073741824 */
/* @0xf0acc add r0, pc, r0 */
/* @0xf0ad0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ad4 ldr r0, [pc, #0xabc] */
/* @0xf0ad8 mov r2, #0 */
/* @0xf0adc mov r3, #0 */
/* @0xf0ae0 add r0, pc, r0 */
/* @0xf0ae4 movt r3, #0x4008 */
/* @0xf0ae8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0aec ldr r0, [pc, #0xaa8] */
/* @0xf0af0 mov r2, #0 */
/* @0xf0af4 mov r3, #0 */
/* @0xf0af8 add r0, pc, r0 */
/* @0xf0afc movt r3, #0x3ff0 */
/* @0xf0b00 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b04 ldr r0, [pc, #0xa94] */
/* @0xf0b08 mov r2, #0 */
/* @0xf0b0c mov r3, #0 */
/* @0xf0b10 add r0, pc, r0 */
/* @0xf0b14 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b18 ldr r0, [pc, #0xa84] */
/* @0xf0b1c mov r2, #0 */
/* @0xf0b20 mov r3, #0 */
/* @0xf0b24 add r0, pc, r0 */
/* @0xf0b28 movt r3, #0x3ff0 */
/* @0xf0b2c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b30 ldr r0, [pc, #0xa70] */
/* @0xf0b34 mov r2, #0 */
/* @0xf0b38 mov r3, #0 */
/* @0xf0b3c add r0, pc, r0 */
/* @0xf0b40 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b44 ldr r0, [pc, #0xa60] */
/* @0xf0b48 mov r2, #0 */
/* @0xf0b4c mov r3, #0 */
/* @0xf0b50 add r0, pc, r0 */
/* @0xf0b54 movt r3, #0x3ff0 */
/* @0xf0b58 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b5c ldr r0, [pc, #0xa4c] */
/* @0xf0b60 mov r2, #0 */
/* @0xf0b64 mov r3, #1073741824 */
/* @0xf0b68 add r0, pc, r0 */
/* @0xf0b6c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b70 ldr r0, [pc, #0xa3c] */
/* @0xf0b74 mov r2, #0 */
/* @0xf0b78 mov r3, #0 */
/* @0xf0b7c add r0, pc, r0 */
/* @0xf0b80 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b84 ldr r0, [pc, #0xa2c] */
/* @0xf0b88 mov r2, #0 */
/* @0xf0b8c mov r3, #0 */
/* @0xf0b90 add r0, pc, r0 */
/* @0xf0b94 movt r3, #0x3ff0 */
/* @0xf0b98 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b9c ldr r0, [pc, #0xa18] */
/* @0xf0ba0 mov r2, #0 */
/* @0xf0ba4 mov r3, #1073741824 */
/* @0xf0ba8 add r0, pc, r0 */
/* @0xf0bac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0bb0 ldr r0, [pc, #0xa08] */
/* @0xf0bb4 mov r2, #0 */
/* @0xf0bb8 mov r3, #0 */
/* @0xf0bbc add r0, pc, r0 */
/* @0xf0bc0 movt r3, #0x4008 */
/* @0xf0bc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0bc8 ldr r0, [pc, #0x9f4] */
/* @0xf0bcc mov r2, #0 */
/* @0xf0bd0 mov r3, #0 */
/* @0xf0bd4 add r0, pc, r0 */
/* @0xf0bd8 movt r3, #0x4010 */
/* @0xf0bdc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0be0 ldr r0, [pc, #0x9e0] */
/* @0xf0be4 mov r2, #0 */
/* @0xf0be8 mov r3, #0 */
/* @0xf0bec add r0, pc, r0 */
/* @0xf0bf0 movt r3, #0x4014 */
/* @0xf0bf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0bf8 ldr r0, [pc, #0x9cc] */
/* @0xf0bfc mov r2, #0 */
/* @0xf0c00 mov r3, #0 */
/* @0xf0c04 add r0, pc, r0 */
/* @0xf0c08 movt r3, #0x4018 */
/* @0xf0c0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c10 ldr r0, [pc, #0x9b8] */
/* @0xf0c14 mov r2, #0 */
/* @0xf0c18 mov r3, #0 */
/* @0xf0c1c add r0, pc, r0 */
/* @0xf0c20 movt r3, #0x401c */
/* @0xf0c24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c28 ldr r0, [pc, #0x9a4] */
/* @0xf0c2c mov r2, #0 */
/* @0xf0c30 mov r3, #0 */
/* @0xf0c34 add r0, pc, r0 */
/* @0xf0c38 movt r3, #0x4020 */
/* @0xf0c3c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c40 ldr r0, [pc, #0x990] */
/* @0xf0c44 mov r2, #0 */
/* @0xf0c48 mov r3, #0 */
/* @0xf0c4c add r0, pc, r0 */
/* @0xf0c50 movt r3, #0x4022 */
/* @0xf0c54 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c58 ldr r0, [pc, #0x97c] */
/* @0xf0c5c mov r2, #0 */
/* @0xf0c60 mov r3, #0 */
/* @0xf0c64 add r0, pc, r0 */
/* @0xf0c68 movt r3, #0x4024 */
/* @0xf0c6c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c70 ldr r0, [pc, #0x968] */
/* @0xf0c74 mov r2, #0 */
/* @0xf0c78 mov r3, #0 */
/* @0xf0c7c add r0, pc, r0 */
/* @0xf0c80 movt r3, #0x4026 */
/* @0xf0c84 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c88 ldr r0, [pc, #0x954] */
/* @0xf0c8c mov r2, #0 */
/* @0xf0c90 mov r3, #0 */
/* @0xf0c94 add r0, pc, r0 */
/* @0xf0c98 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c9c ldr r0, [pc, #0x944] */
/* @0xf0ca0 mov r2, #0 */
/* @0xf0ca4 mov r3, #0 */
/* @0xf0ca8 add r0, pc, r0 */
/* @0xf0cac movt r3, #0x3ff0 */
/* @0xf0cb0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0cb4 ldr r0, [pc, #0x930] */
/* @0xf0cb8 mov r2, #0 */
/* @0xf0cbc mov r3, #1073741824 */
/* @0xf0cc0 add r0, pc, r0 */
/* @0xf0cc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0cc8 ldr r0, [pc, #0x920] */
/* @0xf0ccc mov r2, #0 */
/* @0xf0cd0 mov r3, #0 */
/* @0xf0cd4 add r0, pc, r0 */
/* @0xf0cd8 movt r3, #0x4008 */
/* @0xf0cdc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ce0 ldr r0, [pc, #0x90c] */
/* @0xf0ce4 mov r2, #0 */
/* @0xf0ce8 mov r3, #0 */
/* @0xf0cec add r0, pc, r0 */
/* @0xf0cf0 movt r3, #0x4010 */
/* @0xf0cf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0cf8 ldr r0, [pc, #0x8f8] */
/* @0xf0cfc mov r2, #0 */
/* @0xf0d00 mov r3, #0 */
/* @0xf0d04 add r0, pc, r0 */
/* @0xf0d08 movt r3, #0x4014 */
/* @0xf0d0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d10 ldr r0, [pc, #0x8e4] */
/* @0xf0d14 mov r2, #0 */
/* @0xf0d18 mov r3, #0 */
/* @0xf0d1c add r0, pc, r0 */
/* @0xf0d20 movt r3, #0x4018 */
/* @0xf0d24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d28 ldr r0, [pc, #0x8d0] */
/* @0xf0d2c mov r2, #0 */
/* @0xf0d30 mov r3, #0 */
/* @0xf0d34 add r0, pc, r0 */
/* @0xf0d38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d3c ldr r0, [pc, #0x8c0] */
/* @0xf0d40 mov r2, #0 */
/* @0xf0d44 mov r3, #0 */
/* @0xf0d48 add r0, pc, r0 */
/* @0xf0d4c movt r3, #0x3ff0 */
/* @0xf0d50 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d54 ldr r0, [pc, #0x8ac] */
/* @0xf0d58 mov r2, #0 */
/* @0xf0d5c mov r3, #1073741824 */
/* @0xf0d60 add r0, pc, r0 */
/* @0xf0d64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d68 ldr r0, [pc, #0x89c] */
/* @0xf0d6c mov r2, #0 */
/* @0xf0d70 mov r3, #0 */
/* @0xf0d74 add r0, pc, r0 */
/* @0xf0d78 movt r3, #0x4008 */
/* @0xf0d7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d80 ldr r0, [pc, #0x888] */
/* @0xf0d84 mov r2, #0 */
/* @0xf0d88 mov r3, #0 */
/* @0xf0d8c add r0, pc, r0 */
/* @0xf0d90 movt r3, #0x4010 */
/* @0xf0d94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d98 ldr r0, [pc, #0x874] */
/* @0xf0d9c mov r2, #0 */
/* @0xf0da0 mov r3, #0 */
/* @0xf0da4 add r0, pc, r0 */
/* @0xf0da8 movt r3, #0x4014 */
/* @0xf0dac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0db0 ldr r0, [pc, #0x860] */
/* @0xf0db4 mov r2, #0 */
/* @0xf0db8 mov r3, #0 */
/* @0xf0dbc add r0, pc, r0 */
/* @0xf0dc0 movt r3, #0x4018 */
/* @0xf0dc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0dc8 ldr r0, [pc, #0x84c] */
/* @0xf0dcc mov r2, #0 */
/* @0xf0dd0 mov r3, #0 */
/* @0xf0dd4 add r0, pc, r0 */
/* @0xf0dd8 movt r3, #0x401c */
/* @0xf0ddc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0de0 ldr r0, [pc, #0x838] */
/* @0xf0de4 mov r2, #0 */
/* @0xf0de8 mov r3, #0 */
/* @0xf0dec add r0, pc, r0 */
/* @0xf0df0 movt r3, #0x4020 */
/* @0xf0df4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0df8 ldr r0, [pc, #0x824] */
/* @0xf0dfc mov r2, #0 */
/* @0xf0e00 mov r3, #0 */
/* @0xf0e04 add r0, pc, r0 */
/* @0xf0e08 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e0c ldr r0, [pc, #0x814] */
/* @0xf0e10 mov r2, #0 */
/* @0xf0e14 mov r3, #0 */
/* @0xf0e18 add r0, pc, r0 */
/* @0xf0e1c movt r3, #0x3ff0 */
/* @0xf0e20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e24 ldr r0, [pc, #0x800] */
/* @0xf0e28 mov r2, #0 */
/* @0xf0e2c mov r3, #1073741824 */
/* @0xf0e30 add r0, pc, r0 */
/* @0xf0e34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e38 ldr r0, [pc, #0x7f0] */
/* @0xf0e3c mov r2, #0 */
/* @0xf0e40 mov r3, #0 */
/* @0xf0e44 add r0, pc, r0 */
/* @0xf0e48 movt r3, #0x4008 */
/* @0xf0e4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e50 ldr r0, [pc, #0x7dc] */
/* @0xf0e54 mov r2, #0 */
/* @0xf0e58 mov r3, #0 */
/* @0xf0e5c add r0, pc, r0 */
/* @0xf0e60 movt r3, #0x4010 */
/* @0xf0e64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e68 ldr r0, [pc, #0x7c8] */
/* @0xf0e6c mov r2, #0 */
/* @0xf0e70 mov r3, #0 */
/* @0xf0e74 add r0, pc, r0 */
/* @0xf0e78 movt r3, #0x4014 */
/* @0xf0e7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e80 ldr r0, [pc, #0x7b4] */
/* @0xf0e84 mov r2, #0 */
/* @0xf0e88 mov r3, #0 */
/* @0xf0e8c add r0, pc, r0 */
/* @0xf0e90 movt r3, #0x4018 */
/* @0xf0e94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e98 ldr r0, [pc, #0x7a0] */
/* @0xf0e9c mov r2, #0 */
/* @0xf0ea0 mov r3, #0 */
/* @0xf0ea4 add r0, pc, r0 */
/* @0xf0ea8 movt r3, #0x401c */
/* @0xf0eac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0eb0 ldr r0, [pc, #0x78c] */
/* @0xf0eb4 mov r2, #0 */
/* @0xf0eb8 mov r3, #0 */
/* @0xf0ebc add r0, pc, r0 */
/* @0xf0ec0 movt r3, #0x4020 */
/* @0xf0ec4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ec8 ldr r0, [pc, #0x778] */
/* @0xf0ecc mov r2, #0 */
/* @0xf0ed0 mov r3, #0 */
/* @0xf0ed4 add r0, pc, r0 */
/* @0xf0ed8 movt r3, #0x4022 */
/* @0xf0edc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ee0 ldr r0, [pc, #0x764] */
/* @0xf0ee4 mov r2, #0 */
/* @0xf0ee8 mov r3, #0 */
/* @0xf0eec add r0, pc, r0 */
/* @0xf0ef0 movt r3, #0x4024 */
/* @0xf0ef4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ef8 ldr r0, [pc, #0x750] */
/* @0xf0efc mov r2, #0 */
/* @0xf0f00 mov r3, #0 */
/* @0xf0f04 add r0, pc, r0 */
/* @0xf0f08 movt r3, #0x4026 */
/* @0xf0f0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f10 ldr r0, [pc, #0x73c] */
/* @0xf0f14 mov r2, #0 */
/* @0xf0f18 mov r3, #0 */
/* @0xf0f1c add r0, pc, r0 */
/* @0xf0f20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f24 ldr r0, [pc, #0x72c] */
/* @0xf0f28 mov r2, #0 */
/* @0xf0f2c mov r3, #0 */
/* @0xf0f30 add r0, pc, r0 */
/* @0xf0f34 movt r3, #0x3ff0 */
/* @0xf0f38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f3c ldr r0, [pc, #0x718] */
/* @0xf0f40 mov r2, #0 */
/* @0xf0f44 mov r3, #0 */
/* @0xf0f48 add r0, pc, r0 */
/* @0xf0f4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f50 ldr r0, [pc, #0x708] */
/* @0xf0f54 mov r2, #0 */
/* @0xf0f58 mov r3, #0 */
/* @0xf0f5c add r0, pc, r0 */
/* @0xf0f60 movt r3, #0x3ff0 */
/* @0xf0f64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f68 ldr r0, [pc, #0x6f4] */
/* @0xf0f6c mov r2, #0 */
/* @0xf0f70 mov r3, #1073741824 */
/* @0xf0f74 add r0, pc, r0 */
/* @0xf0f78 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f7c ldr r0, [pc, #0x6e4] */
/* @0xf0f80 mov r2, #0 */
/* @0xf0f84 mov r3, #0 */
/* @0xf0f88 add r0, pc, r0 */
/* @0xf0f8c movt r3, #0x4008 */
/* @0xf0f90 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f94 ldr r0, [pc, #0x6d0] */
/* @0xf0f98 mov r2, #0 */
/* @0xf0f9c mov r3, #0 */
/* @0xf0fa0 add r0, pc, r0 */
/* @0xf0fa4 movt r3, #0x4010 */
/* @0xf0fa8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0fac ldr r0, [pc, #0x6bc] */
/* @0xf0fb0 mov r2, #0 */
/* @0xf0fb4 mov r3, #0 */
/* @0xf0fb8 add r0, pc, r0 */
/* @0xf0fbc movt r3, #0x4014 */
/* @0xf0fc0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0fc4 ldr r0, [pc, #0x6a8] */
/* @0xf0fc8 mov r2, #0 */
/* @0xf0fcc mov r3, #0 */
/* @0xf0fd0 add r0, pc, r0 */
/* @0xf0fd4 movt r3, #0x3ff0 */
/* @0xf0fd8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0fdc ldr r0, [pc, #0x694] */
/* @0xf0fe0 mov r2, #0 */
/* @0xf0fe4 mov r3, #1073741824 */
/* @0xf0fe8 add r0, pc, r0 */
/* @0xf0fec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ff0 ldr r0, [pc, #0x684] */
/* @0xf0ff4 mov r2, #0 */
/* @0xf0ff8 mov r3, #0 */
/* @0xf0ffc add r0, pc, r0 */
/* @0xf1000 movt r3, #0x4008 */
/* @0xf1004 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1008 ldr r0, [pc, #0x670] */
/* @0xf100c mov r2, #0 */
/* @0xf1010 mov r3, #0 */
/* @0xf1014 add r0, pc, r0 */
/* @0xf1018 movt r3, #0x4010 */
/* @0xf101c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1020 ldr r0, [pc, #0x65c] */
/* @0xf1024 mov r2, #0 */
/* @0xf1028 mov r3, #0 */
/* @0xf102c add r0, pc, r0 */
/* @0xf1030 movt r3, #0x4014 */
/* @0xf1034 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1038 ldr r0, [pc, #0x648] */
/* @0xf103c mov r2, #0 */
/* @0xf1040 mov r3, #0 */
/* @0xf1044 add r0, pc, r0 */
/* @0xf1048 movt r3, #0x4018 */
/* @0xf104c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1050 ldr r0, [pc, #0x634] */
/* @0xf1054 mov r2, #0 */
/* @0xf1058 mov r3, #0 */
/* @0xf105c add r0, pc, r0 */
/* @0xf1060 movt r3, #0x401c */
/* @0xf1064 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1068 ldr r0, [pc, #0x620] */
/* @0xf106c mov r2, #0 */
/* @0xf1070 mov r3, #0 */
/* @0xf1074 add r0, pc, r0 */
/* @0xf1078 movt r3, #0x4020 */
/* @0xf107c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1080 ldr r0, [pc, #0x60c] */
/* @0xf1084 mov r2, #0 */
/* @0xf1088 mov r3, #0 */
/* @0xf108c add r0, pc, r0 */
/* @0xf1090 movt r3, #0x4022 */
/* @0xf1094 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1098 ldr r0, [pc, #0x5f8] */
/* @0xf109c mov r2, #0 */
/* @0xf10a0 mov r3, #0 */
/* @0xf10a4 add r0, pc, r0 */
/* @0xf10a8 movt r3, #0x4024 */
/* @0xf10ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf10b0 ldr r0, [pc, #0x5e4] */
/* @0xf10b4 mov r2, #0 */
/* @0xf10b8 mov r3, #0 */
/* @0xf10bc add r0, pc, r0 */
/* @0xf10c0 movt r3, #0x4026 */
/* @0xf10c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf10c8 ldr r0, [pc, #0x5d0] */
/* @0xf10cc mov r2, #0 */
/* @0xf10d0 mov r3, #0 */
/* @0xf10d4 add r0, pc, r0 */
/* @0xf10d8 movt r3, #0x4028 */
/* @0xf10dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf10e0 ldr r0, [pc, #0x5bc] */
/* @0xf10e4 mov r2, #0 */
/* @0xf10e8 mov r3, #0 */
/* @0xf10ec add r0, pc, r0 */
/* @0xf10f0 movt r3, #0x402a */
/* @0xf10f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf10f8 ldr r0, [pc, #0x5a8] */
/* @0xf10fc mov r2, #0 */
/* @0xf1100 mov r3, #0 */
/* @0xf1104 add r0, pc, r0 */
/* @0xf1108 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf110c ldr r0, [pc, #0x598] */
/* @0xf1110 mov r2, #0 */
/* @0xf1114 mov r3, #0 */
/* @0xf1118 add r0, pc, r0 */
/* @0xf111c movt r3, #0x3ff0 */
/* @0xf1120 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1124 ldr r0, [pc, #0x584] */
/* @0xf1128 mov r2, #0 */
/* @0xf112c mov r3, #1073741824 */
/* @0xf1130 add r0, pc, r0 */
/* @0xf1134 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1138 pop {r4, lr} */
/* @0xf113c b 0x15d0f8 <_Z25InitYoYoFunctionConstantsv> */
/* @0xf1140 ldr r0, [pc, #0x56c] */
/* @0xf1144 mov r2, #0 */
/* @0xf1148 mov r3, #0 */
/* @0xf114c add r0, pc, r0 */
/* @0xf1150 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1154 ldr r0, [pc, #0x55c] */
/* @0xf1158 mov r2, #0 */
/* @0xf115c mov r3, #0 */
/* @0xf1160 add r0, pc, r0 */
/* @0xf1164 movt r3, #0x3ff0 */
/* @0xf1168 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf116c b 0xefd94 <_Z24INITIALIZE_Code_Constantv+0x1d78> */
/* @0xf1170 ldr r0, [pc, #0x544] */
/* @0xf1174 mov r2, #0 */
/* @0xf1178 mov r3, #0 */
/* @0xf117c add r0, pc, r0 */
/* @0xf1180 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1184 ldr r0, [pc, #0x534] */
/* @0xf1188 mov r2, #0 */
/* @0xf118c mov r3, #0 */
/* @0xf1190 add r0, pc, r0 */
/* @0xf1194 movt r3, #0x3ff0 */
/* @0xf1198 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf119c ldr r0, [pc, #0x520] */
/* @0xf11a0 mov r2, #0 */
/* @0xf11a4 mov r3, #1073741824 */
/* @0xf11a8 add r0, pc, r0 */
/* @0xf11ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf11b0 ldr r0, [pc, #0x510] */
/* @0xf11b4 mov r2, #0 */
/* @0xf11b8 mov r3, #0 */
/* @0xf11bc add r0, pc, r0 */
/* @0xf11c0 movt r3, #0x4008 */
/* @0xf11c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf11c8 ldr r0, [pc, #0x4fc] */
/* @0xf11cc mov r2, #0 */
/* @0xf11d0 mov r3, #0 */
/* @0xf11d4 add r0, pc, r0 */
/* @0xf11d8 movt r3, #0x4010 */
/* @0xf11dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf11e0 ldr r0, [pc, #0x4e8] */
/* @0xf11e4 mov r2, #0 */
/* @0xf11e8 mov r3, #0 */
/* @0xf11ec add r0, pc, r0 */
/* @0xf11f0 movt r3, #0x4014 */
/* @0xf11f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf11f8 ldr r0, [pc, #0x4d4] */
/* @0xf11fc mov r2, #0 */
/* @0xf1200 mov r3, #0 */
/* @0xf1204 add r0, pc, r0 */
/* @0xf1208 movt r3, #0x4018 */
/* @0xf120c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1210 ldr r0, [pc, #0x4c0] */
/* @0xf1214 mov r2, #0 */
/* @0xf1218 mov r3, #0 */
/* @0xf121c add r0, pc, r0 */
/* @0xf1220 movt r3, #0x401c */
/* @0xf1224 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1228 ldr r0, [pc, #0x4ac] */
/* @0xf122c mov r2, #0 */
/* @0xf1230 mov r3, #0 */
/* @0xf1234 add r0, pc, r0 */
/* @0xf1238 movt r3, #0x4020 */
/* @0xf123c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1240 ldr r0, [pc, #0x498] */
/* @0xf1244 mov r2, #0 */
/* @0xf1248 mov r3, #0 */
/* @0xf124c add r0, pc, r0 */
/* @0xf1250 movt r3, #0x4022 */
/* @0xf1254 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1258 ldr r0, [pc, #0x484] */
/* @0xf125c mov r2, #0 */
/* @0xf1260 mov r3, #0 */
/* @0xf1264 add r0, pc, r0 */
/* @0xf1268 movt r3, #0x4024 */
/* @0xf126c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1270 ldr r0, [pc, #0x470] */
/* @0xf1274 mov r2, #0 */
/* @0xf1278 mov r3, #0 */
/* @0xf127c add r0, pc, r0 */
/* @0xf1280 movt r3, #0x4026 */
/* @0xf1284 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1288 ldr r0, [pc, #0x45c] */
/* @0xf128c mov r2, #0 */
/* @0xf1290 mov r3, #0 */
/* @0xf1294 add r0, pc, r0 */
/* @0xf1298 movt r3, #0x4028 */
/* @0xf129c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf12a0 ldr r0, [pc, #0x448] */
/* @0xf12a4 mov r2, #0 */
/* @0xf12a8 mov r3, #0 */
/* @0xf12ac add r0, pc, r0 */
/* @0xf12b0 movt r3, #0x4050 */
/* @0xf12b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf12b8 ldr r0, [pc, #0x434] */
/* @0xf12bc mov r2, #0 */
/* @0xf12c0 mov r3, #16384 */
/* @0xf12c4 add r0, pc, r0 */
/* @0xf12c8 movt r3, #0x4050 */
/* @0xf12cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf12d0 ldr r0, [pc, #0x420] */
/* @0xf12d4 mov r2, #0 */
/* @0xf12d8 mov r3, #32768 */
/* @0xf12dc add r0, pc, r0 */
/* @0xf12e0 movt r3, #0x4050 */
/* @0xf12e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf12e8 ldr r0, [pc, #0x40c] */
/* @0xf12ec mov r2, #0 */
/* @0xf12f0 mov r3, #49152 */
/* @0xf12f4 add r0, pc, r0 */
/* @0xf12f8 movt r3, #0x4050 */
/* @0xf12fc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1300 ldr r0, [pc, #0x3f8] */
/* @0xf1304 mov r2, #0 */
/* @0xf1308 mov r3, #0 */
/* @0xf130c add r0, pc, r0 */
/* @0xf1310 movt r3, #0x4051 */
/* @0xf1314 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1318 ldr r0, [pc, #0x3e4] */
/* @0xf131c mov r2, #0 */
/* @0xf1320 mov r3, #16384 */
/* @0xf1324 add r0, pc, r0 */
/* @0xf1328 movt r3, #0x4051 */
/* @0xf132c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1330 ldr r0, [pc, #0x3d0] */
/* @0xf1334 mov r2, #0 */
/* @0xf1338 mov r3, #32768 */
/* @0xf133c add r0, pc, r0 */
/* @0xf1340 movt r3, #0x4051 */
/* @0xf1344 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1348 ldr r0, [pc, #0x3bc] */
/* @0xf134c mov r2, #0 */
/* @0xf1350 mov r3, #49152 */
/* @0xf1354 add r0, pc, r0 */
/* @0xf1358 movt r3, #0x4051 */
/* @0xf135c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1360 ldr r0, [pc, #0x3a8] */
/* @0xf1364 mov r2, #0 */
/* @0xf1368 mov r3, #0 */
/* @0xf136c add r0, pc, r0 */
/* @0xf1370 movt r3, #0x4052 */
/* @0xf1374 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1378 ldr r0, [pc, #0x394] */
/* @0xf137c mov r2, #0 */
/* @0xf1380 mov r3, #16384 */
/* @0xf1384 add r0, pc, r0 */
/* @0xf1388 movt r3, #0x4052 */
/* @0xf138c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1390 ldr r0, [pc, #0x380] */
/* @0xf1394 mov r2, #0 */
/* @0xf1398 mov r3, #32768 */
/* @0xf139c add r0, pc, r0 */
/* @0xf13a0 movt r3, #0x4052 */
/* @0xf13a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf13a8 ldr r0, [pc, #0x36c] */
/* @0xf13ac mov r2, #0 */
/* @0xf13b0 mov r3, #49152 */
/* @0xf13b4 add r0, pc, r0 */
/* @0xf13b8 movt r3, #0x4052 */
/* @0xf13bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf13c0 ldr r0, [pc, #0x358] */
/* @0xf13c4 mov r2, #0 */
/* @0xf13c8 mov r3, #0 */
/* @0xf13cc add r0, pc, r0 */
/* @0xf13d0 movt r3, #0x4053 */
/* @0xf13d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf13d8 b 0xefc1c <_Z24INITIALIZE_Code_Constantv+0x1c00> */
/* @0xf13dc ldr r0, [pc, #0x340] */
/* @0xf13e0 mov r2, #0 */
/* @0xf13e4 mov r3, #0 */
/* @0xf13e8 movt r3, #0x4028 */
/* @0xf13ec add r0, pc, r0 */
/* @0xf13f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf13f4 ldr r0, [pc, #0x32c] */
/* @0xf13f8 mov r2, #0 */
/* @0xf13fc mov r3, #0 */
/* @0xf1400 add r0, pc, r0 */
/* @0xf1404 movt r3, #0x402a */
/* @0xf1408 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf140c ldr r0, [pc, #0x318] */
/* @0xf1410 mov r2, #0 */
/* @0xf1414 mov r3, #0 */
/* @0xf1418 add r0, pc, r0 */
/* @0xf141c movt r3, #0x402c */
/* @0xf1420 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1424 b 0xeef4c <_Z24INITIALIZE_Code_Constantv+0xf30> */
/* @0xf1428 ldr r0, [pc, #0x300] */
/* @0xf142c mov r2, #0 */
/* @0xf1430 mov r3, #0 */
/* @0xf1434 add r0, pc, r0 */
/* @0xf1438 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf143c ldr r0, [pc, #0x2f0] */
/* @0xf1440 mov r2, #0 */
/* @0xf1444 mov r3, #0 */
/* @0xf1448 add r0, pc, r0 */
/* @0xf144c movt r3, #0x3ff0 */
/* @0xf1450 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1454 ldr r0, [pc, #0x2dc] */
/* @0xf1458 mov r2, #0 */
/* @0xf145c mov r3, #1073741824 */
/* @0xf1460 add r0, pc, r0 */
/* @0xf1464 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1468 ldr r0, [pc, #0x2cc] */
/* @0xf146c mov r2, #0 */
/* @0xf1470 mov r3, #0 */
/* @0xf1474 add r0, pc, r0 */
/* @0xf1478 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf147c ldr r0, [pc, #0x2bc] */
/* @0xf1480 mov r2, #0 */
/* @0xf1484 mov r3, #0 */
/* @0xf1488 add r0, pc, r0 */
/* @0xf148c movt r3, #0x3ff0 */
/* @0xf1490 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1494 ldr r0, [pc, #0x2a8] */
/* @0xf1498 mov r2, #0 */
/* @0xf149c mov r3, #1073741824 */
/* @0xf14a0 add r0, pc, r0 */
/* @0xf14a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf14a8 b 0xee4f8 <_Z24INITIALIZE_Code_Constantv+0x4dc> */
/* @0xf14ac eoreq r5, r4, r8, ror pc */
/* @0xf14b0 eoreq r5, r4, r8, ror #30 */
/* @0xf14b4 eoreq r5, r4, r8, asr pc */
/* @0xf14b8 eoreq r5, r4, r12, asr #30 */
/* @0xf14bc eoreq r5, r4, r12, lsr pc */
/* @0xf14c0 eoreq r5, r4, r0, lsr pc */
/* @0xf14c4 eoreq r5, r4, r0, lsr #30 */
/* @0xf14c8 eoreq r5, r4, r4, lsr #30 */
/* @0xf14cc eoreq r5, r4, r4, lsr #30 */
/* @0xf14d0 eoreq r5, r4, r8, lsr #30 */
/* @0xf14d4 eoreq r5, r4, r8, lsr #30 */
/* @0xf14d8 eoreq r5, r4, r12, lsr #30 */
/* @0xf14dc eoreq r5, r4, r0, lsr pc */
/* @0xf14e0 eoreq r5, r4, r4, lsr pc */
/* @0xf14e4 eoreq r5, r4, r12, lsr #30 */
/* @0xf14e8 eoreq r5, r4, r12, lsr #30 */
/* @0xf14ec eoreq r5, r4, r12, lsr #30 */
/* @0xf14f0 eoreq r5, r4, r0, lsr pc */
/* @0xf14f4 eoreq r5, r4, r0, lsr pc */
/* @0xf14f8 eoreq r5, r4, r8, lsr #30 */
/* @0xf14fc eoreq r5, r4, r8, lsr #30 */
/* @0xf1500 eoreq r5, r4, r12, lsr #30 */
/* @0xf1504 eoreq r5, r4, r8, lsr #30 */
/* @0xf1508 eoreq r5, r4, r4, lsr #30 */
/* @0xf150c eoreq r5, r4, r4, lsr #30 */
/* @0xf1510 eoreq r5, r4, r0, lsr #30 */
/* @0xf1514 eoreq r5, r4, r0, lsr #30 */
/* @0xf1518 eoreq r5, r4, r4, lsr #30 */
/* @0xf151c eoreq r5, r4, r4, lsr #30 */
/* @0xf1520 eoreq r5, r4, r4, lsr #30 */
/* @0xf1524 eoreq r5, r4, r4, lsr #30 */
/* @0xf1528 eoreq r5, r4, r12, lsr #30 */
/* @0xf152c .word 0x002448d0 */
/* @0xf1530 .word 0x002448d0 */
/* @0xf1534 .word 0x002448d8 */
/* @0xf1538 eoreq r4, r4, r12, ror #17 */
/* @0xf153c .word 0x002448f4 */
/* @0xf1540 eoreq r4, r4, r4, lsl #18 */
/* @0xf1544 eoreq r4, r4, r12, lsl #18 */
/* @0xf1548 eoreq r4, r4, r12, lsl r9 */
/* @0xf154c eoreq r4, r4, r12, lsl r9 */
/* @0xf1550 eoreq r4, r4, r8, lsl r9 */
/* @0xf1554 eoreq r4, r4, r0, lsl r9 */
/* @0xf1558 eoreq r4, r4, r8, lsl #18 */
/* @0xf155c eoreq r5, r4, r12, lsr #28 */
/* @0xf1560 eoreq r5, r4, r4, lsr #28 */
/* @0xf1564 eoreq r5, r4, r0, lsr #28 */
/* @0xf1568 eoreq r5, r4, r12, lsl lr */
/* @0xf156c eoreq r5, r4, r4, lsl lr */
/* @0xf1570 eoreq r5, r4, r12, lsl #28 */
/* @0xf1574 eoreq r5, r4, r4, lsl #28 */
/* @0xf1578 .word 0x00245df8 */
/* @0xf157c .word 0x00245df0 */
/* @0xf1580 eoreq r5, r4, r8, ror #27 */
/* @0xf1584 eoreq r5, r4, r4, ror #27 */
/* @0xf1588 eoreq r5, r4, r0, ror #27 */
/* @0xf158c eoreq r5, r4, r0, ror #27 */
/* @0xf1590 .word 0x00245ddc */
/* @0xf1594 .word 0x00245dd4 */
/* @0xf1598 .word 0x00245dd4 */
/* @0xf159c eoreq r5, r4, r12, asr #27 */
/* @0xf15a0 eoreq r5, r4, r8, asr #27 */
/* @0xf15a4 eoreq r5, r4, r12, asr #27 */
/* @0xf15a8 eoreq r5, r4, r12, asr #27 */
/* @0xf15ac .word 0x00245dd0 */
/* @0xf15b0 .word 0x00245dd4 */
/* @0xf15b4 .word 0x00245dd8 */
/* @0xf15b8 .word 0x00245ddc */
/* @0xf15bc eoreq r5, r4, r8, ror #27 */
/* @0xf15c0 eoreq r5, r4, r4, lsl #28 */
/* @0xf15c4 eoreq r5, r4, r4, lsl #28 */
/* @0xf15c8 eoreq r5, r4, r0, lsr #28 */
/* @0xf15cc eoreq r5, r4, r12, lsr lr */
/* @0xf15d0 eoreq r5, r4, r8, asr #28 */
/* @0xf15d4 eoreq r5, r4, r8, ror #28 */
/* @0xf15d8 eoreq r5, r4, r8, ror #28 */
/* @0xf15dc eoreq r5, r4, r0, ror lr */
/* @0xf15e0 eoreq r5, r4, r4, ror lr */
/* @0xf15e4 eoreq r5, r4, r12, ror lr */
/* @0xf15e8 eoreq r5, r4, r8, lsl #29 */
/* @0xf15ec mlaeq r4, r0, lr, r5 */
/* @0xf15f0 mlaeq r4, r4, lr, r5 */
/* @0xf15f4 mlaeq r4, r12, lr, r5 */
/* @0xf15f8 eoreq r5, r4, r8, lsr #29 */
/* @0xf15fc eoreq r5, r4, r12, lsr #29 */
/* @0xf1600 .word 0x00245eb0 */
/* @0xf1604 .word 0x00245eb0 */
/* @0xf1608 eoreq r5, r4, r12, lsr #29 */
/* @0xf160c eoreq r5, r4, r12, lsr #29 */
/* @0xf1610 eoreq r5, r4, r8, lsr #29 */
/* @0xf1614 eoreq r5, r4, r8, lsr #29 */
/* @0xf1618 eoreq r5, r4, r4, lsr #29 */
/* @0xf161c eoreq r5, r4, r0, lsr #29 */
/* @0xf1620 eoreq r5, r4, r0, lsr #29 */
/* @0xf1624 mlaeq r4, r12, lr, r5 */
/* @0xf1628 mlaeq r4, r8, lr, r5 */
/* @0xf162c mlaeq r4, r4, lr, r5 */
/* @0xf1630 mlaeq r4, r12, lr, r5 */
/* @0xf1634 mlaeq r4, r12, lr, r5 */
/* @0xf1638 mlaeq r4, r8, lr, r5 */
/* @0xf163c mlaeq r4, r4, lr, r5 */
/* @0xf1640 mlaeq r4, r4, lr, r5 */
/* @0xf1644 mlaeq r4, r0, lr, r5 */
/* @0xf1648 eoreq r5, r4, r12, lsl #29 */
/* @0xf164c mlaeq r4, r0, lr, r5 */
/* @0xf1650 mlaeq r4, r0, lr, r5 */
/* @0xf1654 mlaeq r4, r8, lr, r5 */
/* @0xf1658 mlaeq r4, r4, lr, r5 */
/* @0xf165c eoreq r5, r4, r12, lsl #29 */
/* @0xf1660 eoreq r5, r4, r8, lsl #29 */
/* @0xf1664 eoreq r5, r4, r12, ror lr */
/* @0xf1668 eoreq r5, r4, r4, ror lr */
/* @0xf166c eoreq r5, r4, r8, ror #28 */
/* @0xf1670 eoreq r5, r4, r0, ror #28 */
/* @0xf1674 eoreq r5, r4, r8, asr lr */
/* @0xf1678 eoreq r5, r4, r12, asr #28 */
/* @0xf167c eoreq r5, r4, r4, asr #28 */
/* @0xf1680 eoreq r5, r4, r8, lsr lr */
/* @0xf1684 eoreq r5, r4, r12, lsr #28 */
/* @0xf1688 eoreq r5, r4, r0, lsr #28 */
/* @0xf168c eoreq r5, r4, r4, lsl lr */
/* @0xf1690 eoreq r5, r4, r8, lsl #28 */
/* @0xf1694 .word 0x00245dfc */
/* @0xf1698 .word 0x00245df0 */
/* @0xf169c eoreq r5, r4, r4, ror #27 */
/* @0xf16a0 .word 0x00245ddc */
/* @0xf16a4 .word 0x00245dd0 */
/* @0xf16a8 eoreq r5, r4, r4, asr #27 */
/* @0xf16ac eoreq r5, r4, r4, asr #27 */
/* @0xf16b0 eoreq r5, r4, r4, asr #27 */
/* @0xf16b4 eoreq r4, r4, r8, asr #29 */
/* @0xf16b8 eoreq r4, r4, r0, asr #29 */
/* @0xf16bc eoreq r4, r4, r4, lsr r11 */
/* @0xf16c0 eoreq r4, r4, r0, lsr r11 */
/* @0xf16c4 eoreq r4, r4, r0, lsr r11 */
/* @0xf16c8 eoreq r4, r4, r4, lsr r11 */
/* @0xf16cc eoreq r4, r4, r0, lsr r11 */
/* @0xf16d0 eoreq r4, r4, r12, lsr #22 */
/* @0xf16d4 eoreq r4, r4, r8, lsr #22 */
/* @0xf16d8 eoreq r4, r4, r8, lsr #22 */
/* @0xf16dc eoreq r4, r4, r4, lsr #22 */
/* @0xf16e0 eoreq r4, r4, r4, lsr #22 */
/* @0xf16e4 eoreq r4, r4, r4, lsr #22 */
/* @0xf16e8 eoreq r4, r4, r4, lsr #22 */
/* @0xf16ec eoreq r4, r4, r0, lsr #22 */
/* @0xf16f0 eoreq r4, r4, r0, lsr #22 */
/* @0xf16f4 eoreq r4, r4, r0, lsr #22 */
/* @0xf16f8 eoreq r4, r4, r8, lsr #22 */
/* @0xf16fc eoreq r4, r4, r0, lsr r11 */
/* @0xf1700 eoreq r4, r4, r4, lsr r11 */
/* @0xf1704 eoreq r4, r4, r8, lsr r11 */
/* @0xf1708 eoreq r4, r4, r8, lsr r11 */
/* @0xf170c eoreq r4, r4, r0, asr #22 */
/* @0xf1710 eoreq r4, r4, r4, asr #22 */
/* @0xf1714 eoreq r4, r4, r8, asr #22 */
/* @0xf1718 eoreq r4, r4, r12, asr #22 */
/* @0xf171c eoreq r4, r4, r4, asr r11 */
/* @0xf1720 eoreq r4, r4, r8, asr r11 */
/* @0xf1724 .word 0x002442f8 */
/* @0xf1728 .word 0x002442f0 */
/* @0xf172c eoreq r4, r4, r4, ror #5 */
/* @0xf1730 eoreq r3, r4, r0, ror #25 */
/* @0xf1734 .word 0x00243cd8 */
/* @0xf1738 eoreq r3, r4, r12, asr #25 */
/* @0xf173c eoreq r3, r4, r8, asr #25 */
/* @0xf1740 .word 0x00243cbc */
/* @0xf1744 eoreq r3, r4, r12, lsr #25 */

/* 
 * ══════════════════════════════════════════════════════════════════════════
 * 节 2 · VM::WriteInstanceBuiltInVariables —— 把哪些实例字段写成 RValue
 * ══════════════════════════════════════════════════════════════════════════
 *
 * ── 一句话 ───────────────────────────────────────────────────────────────
 *   把一个 CInstance 的内建变量**按固定顺序**逐条写成 (类型码, double) 塞进 Buffer_Standard，
 *   **不写名字**；写完内建量再转发 VM::GetInstanceVariables 把用户自定义变量也灌进同一个 buffer。
 *   名字→位置的对应关系在消费端，不在这个函数里。
 *
 * ── 写协议（全函数 110 个 blx 同一套）──────────────────────────────────
 *   r9 = buf（Buffer_Standard*，实参 1）、r7 = inst（CInstance*，实参 2）、r6 = buf + 0x2c（内嵌 RValue 槽）
 *   每一次写 = 5 步：
 *     str  r8, [r9, #0x38]     ; tag = 0（VT_REAL），永远是 0
 *     vstr s12/s14, [r9, #44]  ; RValue 低 32 位 → buf+0x2c
 *     str  r5,  [r9, #0x30]    ; RValue 高 32 位 → buf+0x30
 *     mov  r1, #type ; mov r2, r6 ; mov r0, r9
 *     ldr  r3, [r9] ; ldr r3, [r3, #0x8] ; blx r3     ; buf->vtable[+8](buf, type, &rv)
 *   type 实见三种：**5 = uint32**、**6 = int32**、**8 = real**。payload 一律是 double：
 *   u32/byte 走 vcvt.f64.u32，float 走 vcvt.f64.f32（所以 0xac 与 0xe8..0xf4 那几个 int 字段是
 *   "先转 double 再按 type 6 编 4 字节"）。tag 恒 0 —— 与 AddRealConstant 造 RValue 的手势完全一致。
 *
 * ── 主序列 80 条（成功路径的执行序；逐条地址见下表）────────────────────
 *   #1..#2    id / object_index（type 5）
 *   #3..#13   x y direction friction gravity gravity_direction hspeed vspeed speed xprevious yprevious
 *   #14..#22  sprite_index image_alpha image_angle image_blend image_index image_number image_speed
 *             image_xscale image_yscale
 *   #23..#34  **alarm[0..11]**（12 条，值取自 CInstance::GetTimer(i)，type 5）
 *   #35..#43  path_index path_position path_positionprevious path_endaction path_scale path_speed
 *             path_orientation xstart ystart
 *   #44..#48  persistent depth visible mask_index(type 6) solid
 *   #49..#52  0x0ec / 0x0f4 / 0x0e8 / 0x0f0 四个 int（type 6，名字未定）
 *   #53..#56  bbox 四条：Sprite_Data(inst+0x8c) 的 +0x1c/+0x20/+0x24/+0x28，
 *             依次 × image_xscale / image_yscale / image_xscale / image_yscale
 *   #57..#74  物理 18 条（q = *(void**)(inst+0x84)，即 CPhysicsObject 的首字）
 *   #75..#79  timeline_index / timeline_running / timeline_speed / timeline_position / timeline_loop
 *   #80       layer（GV_Layer，受一个全局字节门控：该字节为 0 时整条跳过）
 *
 * ── 12 个 alarm 的确切位置 ─────────────────────────────────────────────
 *   inst+0xf8+4*i，i=0..11，共 48 B。本函数没有用循环，而是**展开成 12 段**：
 *   每段 `mov r1,#i` + `bl CInstance::GetTimer` + 一次 type 5 写（r0 = inst）。
 *   0xd9b74/0xd9bb0/0xd9bec/0xd9c28/0xd9c64/0xd9ca0/0xd9cdc/0xd9d18/0xd9d54/0xd9d90/0xd9dcc/0xd9e08
 *   ↑ 这 12 个写点与 0xd9b44..0xd9e08 的 12 个 bl 一一对应，间距恒 0x3c。
 *   ★ 但写进去的值**不是**直接读 inst+0xf8+4i，而是过 GetTimer(i)：GetTimer 对 i>11 返回 -1，
 *     所以这 12 条在语义上等于「alarm[0..11]」，用 GetTimer 只是复用它的边界检查。
 *
 * ── bbox 四条（#53..#56）────────────────────────────────────────────────
 *   r10 = Sprite_Data(inst->sprite_index)；r10 == 0 → 跳 0xdad34 写 4 个 0.0 再回 0xda2a4。
 *   非空时： (float)(s32)[r10+0x1c] * [inst+0x98]   (image_xscale)
 *            (float)(s32)[r10+0x20] * [inst+0x9c]   (image_yscale)
 *            (float)(s32)[r10+0x24] * [inst+0x98]
 *            (float)(s32)[r10+0x28] * [inst+0x9c]
 *   配对方式（xscale/xscale、yscale/yscale ×2）说明这四个是 sprite 的 bbox 四边；
 *   具体谁是 left/top/right/bottom 由 +0x1c/+0x20/+0x24/+0x28 的顺序推断（open）。
 *
 * ── 物理 18 条（#57..#74）───────────────────────────────────────────────
 *   inst+0x84 为空 → 跳 0xdaaa8 写 **18 个 0**（前 17 个类型与主序列逐一相同，第 18 个是 8 而主序列是 5）
 *   再 `b 0xda7a8` 接 timeline 段。
 *   inst+0x84 非空时 q = *(void**)(inst+0x84)，读 q+0x00（枚举）、q+0x04（半字 flags）、
 *   q+0x2c/q+0x30（质心偏移）、q+0x48（角速度）、q+0x58（角度）、q+0x84（质量）、q+0x8c（基准惯量）。
 *   其中 8 条走 GV_Physics* 访问器（每个都有「成功→外挂块写值 / 失败→就地写 0.0」两条路），
 *   8 个 GV 成功块在 0xda930/0xda968/0xda990/0xda9bc/0xda9e8/0xdaa14/0xdaa40/0xdaa6c，
 *   8 个就地 0 写在 0xda3ac/0xda3f8/0xda444/0xda490/0xda4dc/0xda528/0xda5f8/0xda644。
 *   两条角度都做 (rad * 180.0f) / pi —— 即对外暴露**度**、内部存**弧度**。
 *
 * ── 收尾 ────────────────────────────────────────────────────────────────
 *   0xda900..0xda924：GetInstanceVariables(buf, inst, 1, 0x186a0, *(int*)GOT)，随后 0xda92c 直接 pop 返回。
 *   ⇒ 一次调用产出的流 = 80 条内建量 + 全部用户变量；**全程没有名字串**，位置即协议。
 *
 * ── 中间那个岔口（容易漏）──────────────────────────────────────────────
 *   0xda0c8 `cmp r3, r8` / 0xda0cc `bne 0xdaa98`：r3 = inst+0x64 的字节（SetObjectIndex 在查表命中时置 1）。
 *   非 0 → 0xdaa98 调 Compute_BoundingBox(inst, true)，再 `b 0xda0d0` 回到主序列。
 *   所以 0x64 是「有 CObjectGM」的标记，不是被写的字段。
 *
 * ── 已证事实（节 2）────────────────────────────────────────────────────
 *   1. 110 个 blx 全是 [buf->vt+8] 的 Write；110 = 80 主序列（其中 8 条是 GV 失败的 0.0）+ 8 个 GV 成功写点
 *      + 18 个 phy 零 + 4 个 bbox 零。
 *   2. 写序列里 type 只有 5/6/8；5 与 6 的区别是实证的：mask_index(0xac) 用 6、sprite_index(0x8c) 用 5，
 *      两个字段在同一段代码里紧邻出现，不可能是巧合。
 *   3. alarm 就是 inst+0xf8+4*i 的 12 个 int，写点 12 个、间距恒 0x3c，值经 GetTimer(i) 取。
 *   4. 除 alarm 外还写 68 条内建量（80-12），外加尾部整批用户变量；bbox 4 条与 phy 18 条是**派生量**，
 *      不是字段直读（bbox 由 sprite bbox × image scale 现算，phy 由 q 现算/走访问器）。
 *   5. 两条角度（q+0x58、q+0x48）都乘 180.0f 再除 pi：对外是度。
 *   6. layer 的写被一个全局 byte 门控（0xda8b0 ldrb），为 0 时该条整个不出现 —— 流长会随它变 1 条。
 *
 * ── open（节 2）────────────────────────────────────────────────────────
 *   1. phy_* 18 条与 GM 名字表（.rodata 0x3534cc.. 那串 phy_rotation/phy_mass/…）的对应只能按值与语义配对，
 *      顺序并不相同 ⇒ 「q+4 的 bit5/bit4/bit3/bit1 分别是 bullet/fixed_rotation/active/sleeping 的哪一个」未证。
 *   2. 无 physics 回退写 18 个 0，但第 18 个类型是 8、主序列同位是 5，两者未对齐（可能在 i 上错开一条）。
 *   3. 0xe8/0xec/0xf0/0xf4 四个 int（type 6）在 CInstance_ctor 卡里也标未定，这里同样只证到「按序写 4 个 int」。
 *   4. 消费端（Debug_GetInstances / GetRuntimeState 的读侧）如何把这 80 个位置还原成名字，未展开。
 *   5. GetInstanceVariables 第 5 实参是 *(int*)GOT（无符号名），语义未定。
 *   6. 为什么 objindex 与 id 用 type 5 而 mask_index 用 type 6，是否等价于「无符号 vs 有符号」未证。
 *
 *
 * ── 节 2 主序列 80 条（执行序；写点 = blx 指令地址，不是字段地址）──
 *
 *   #   写点       type  字段/来源                                   备注
 *   1  0d9734   5   0x078 id                                   u32→f64
 *   2  0d9768   5   0x07c object_index                         u32→f64
 *   3  0d9798   8   0x0b4 x                                    f32
 *   4  0d97c8   8   0x0b8 y                                    f32
 *   5  0d97f8   8   0x0cc direction                            f32
 *   6  0d9828   8   0x0d4 friction                             f32
 *   7  0d9858   8   0x0dc gravity                              f32
 *   8  0d9888   8   0x0d8 gravity_direction                    f32
 *   9  0d98b8   8   0x0e0 hspeed                               f32
 *  10  0d98e8   8   0x0e4 vspeed                               f32
 *  11  0d9918   8   0x0d0 speed                                f32
 *  12  0d9948   8   0x0c4 xprevious                            f32
 *  13  0d9978   8   0x0c8 yprevious                            f32
 *  14  0d99ac   5   0x08c sprite_index                         u32→f64
 *  15  0d99dc   8   0x0a4 image_alpha                          f32
 *  16  0d9a0c   8   0x0a0 image_angle                          f32
 *  17  0d9a40   5   0x0a8 image_blend                          u32→f64
 *  18  0d9a70   8   0x090 image_index                          f32
 *  19  0d9aa8   5   GetImageNumber() image_number              CInstance::GetImageNumber 0x19357c
 *  20  0d9ad8   8   0x094 image_speed                          f32
 *  21  0d9b08   8   0x098 image_xscale                         f32
 *  22  0d9b38   8   0x09c image_yscale                         f32
 *  23  0d9b74   5   0x0f8+4*0 alarm[0]                         CInstance::GetTimer(0)
 *  24  0d9bb0   5   0x0f8+4*1 alarm[1]                         CInstance::GetTimer(1)
 *  25  0d9bec   5   0x0f8+4*2 alarm[2]                         CInstance::GetTimer(2)
 *  26  0d9c28   5   0x0f8+4*3 alarm[3]                         CInstance::GetTimer(3)
 *  27  0d9c64   5   0x0f8+4*4 alarm[4]                         CInstance::GetTimer(4)
 *  28  0d9ca0   5   0x0f8+4*5 alarm[5]                         CInstance::GetTimer(5)
 *  29  0d9cdc   5   0x0f8+4*6 alarm[6]                         CInstance::GetTimer(6)
 *  30  0d9d18   5   0x0f8+4*7 alarm[7]                         CInstance::GetTimer(7)
 *  31  0d9d54   5   0x0f8+4*8 alarm[8]                         CInstance::GetTimer(8)
 *  32  0d9d90   5   0x0f8+4*9 alarm[9]                         CInstance::GetTimer(9)
 *  33  0d9dcc   5   0x0f8+4*10 alarm[10]                       CInstance::GetTimer(10)
 *  34  0d9e08   5   0x0f8+4*11 alarm[11]                       CInstance::GetTimer(11)
 *  35  0d9e3c   5   0x128 path_index                           u32→f64
 *  36  0d9e6c   8   0x12c path_position                        f32
 *  37  0d9e9c   8   0x130 path_positionprevious                f32
 *  38  0d9ed0   5   0x140 path_endaction                       u32→f64
 *  39  0d9f00   8   0x138 path_scale                           f32
 *  40  0d9f30   8   0x134 path_speed                           f32
 *  41  0d9f60   8   0x13c path_orientation                     f32
 *  42  0d9f90   8   0x0bc xstart                               f32
 *  43  0d9fc0   8   0x0c0 ystart                               f32
 *  44  0d9ff4   5   0x067 persistent                           byte→f64
 *  45  0da024   8   0x180 depth                                f32
 *  46  0da058   5   0x065 visible                              byte→f64
 *  47  0da08c   6   0x0ac mask_index                           **type 6（int）**
 *  48  0da0c0   5   0x066 solid                                byte→f64
 *  49  0da104   6   0x0ec 未定 int                               **type 6**
 *  50  0da138   6   0x0f4 未定 int                               **type 6**
 *  51  0da16c   6   0x0e8 未定 int                               **type 6**
 *  52  0da1a0   6   0x0f0 未定 int                               **type 6**
 *  53  0da1ec   8   sprite+0x1c × 0x098 bbox_left?             (float)(s32)sprite+0x1c * image_xscale
 *  54  0da228   8   sprite+0x20 × 0x09c bbox_top?              (float)(s32)sprite+0x20 * image_yscale
 *  55  0da264   8   sprite+0x24 × 0x098 bbox_right?            (float)(s32)sprite+0x24 * image_xscale
 *  56  0da2a0   8   sprite+0x28 × 0x09c bbox_bottom?           (float)(s32)sprite+0x28 * image_yscale
 *  57  0da2f0   5   q+4 bit5 未定 bool（phy_*）                    ubfx #5,#1
 *  58  0da32c   5   q+4 bit4 未定 bool（phy_*）                    ubfx #4,#1
 *  59  0da370   8   q+0x58 phy_rotation?                       f * 180.0f / pi
 *  60  0da3ac   8   GV_PhysicsLinearVelocityX phy_linear_velocity_x 成功→0xda960 写值；失败→就地 0.0
 *  61  0da3f8   8   GV_PhysicsLinearVelocityY phy_linear_velocity_y 成功→0xda988；失败→就地 0.0
 *  62  0da444   8   GV_PhysicsSpeedX phy_speed_x               成功→0xda9b4；失败→就地 0.0
 *  63  0da490   8   GV_PhysicsSpeedY phy_speed_y               成功→0xda9e0；失败→就地 0.0
 *  64  0da4dc   8   GV_PhysicsPositionX phy_position_x         成功→0xdaa0c；失败→就地 0.0
 *  65  0da528   8   GV_PhysicsPositionY phy_position_y         成功→0xdaa38；失败→就地 0.0
 *  66  0da570   8   q+0x48 phy_angular_velocity?               f * 180.0f / pi
 *  67  0da5ac   5   q+4 bit3 未定 bool（phy_*）                    ubfx #3,#1
 *  68  0da5f8   8   GV_PhysicsCOM_X phy_com_x                  成功→0xdaa64；失败→就地 0.0
 *  69  0da644   8   GV_PhysicsCOM_Y phy_com_y                  成功→0xdaa90；失败→就地 0.0
 *  70  0da6a0   5   q+0x00 == 2 未定 bool（phy_*）                 subs/rsbs/adcs 归一成 0/1
 *  71  0da6e4   5   q+0x00 == 1 未定 bool（phy_*）                 同上
 *  72  0da730   8   q+0x8c + (q+0x30²+q+0x2c²)*q+0x84 phy_inertia? vmla 合成
 *  73  0da764   8   q+0x84 phy_mass?                           f32
 *  74  0da7a4   5   q+4 bit1 未定 bool（phy_*）                    ubfx #1,#1
 *  75  0da7dc   5   0x14c timeline_index                       u32→f64
 *  76  0da810   5   0x15c timeline_running                     byte→f64
 *  77  0da840   8   0x158 timeline_speed                       f32
 *  78  0da870   8   0x154 timeline_position                    f32
 *  79  0da8a4   5   0x15d timeline_loop                        byte→f64
 *  80  0da8fc   8   GV_Layer layer                             全局字节 0 时整条跳过
 *
 * ── 节 2 回退/外挂写点 30 条 ──
 *
 *   8 个 GV 成功写点（块首 da930/da968/da990/da9bc/da9e8/daa14/daa40/daa6c）：da960, da988, da9b4, da9e0, daa0c, daa38, daa64, daa90
 *   8 个 GV 就地 0.0：da3ac da3f8 da444 da490 da4dc da528 da5f8 da644
 *   18 个 phy 零（无 physics 对象，0xdaaa8..0xdad2c，末 b 0xda7a8）：
 *     daac8 daaec dab10 dab34 dab58 dab7c daba0 dabc4 dabe8 dac0c dac30 dac54
 *     dac78 dac9c dacc0 dace4 dad08 dad2c
 *   4 个 bbox 零（sprite 为空，0xdad34..0xdadc0，末 b 0xda2a4）：
 *     dad54 dad78 dad9c dadc0
 *
 * ── 节 2 逐条锚点（1462/1462）──
 */

/* @0xd96f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd96f4 add r6, r0, #44 */
/* @0xd96f8 ldr r4, [r1, #0x78] */
/* @0xd96fc mov r9, r0 */
/* @0xd9700 ldr r3, [r0] */
/* @0xd9704 sub sp, sp, #28 */
/* @0xd9708 mov r8, #0 */
/* @0xd970c mov r7, r1 */
/* @0xd9710 vmov s13, r4 */
/* @0xd9714 str r8, [r0, #0x38] */
/* @0xd9718 mov r2, r6 */
/* @0xd971c mov r1, #5 */
/* @0xd9720 vcvt.f64.u32 d6, s13 */
/* @0xd9724 vmov r4, r5, d6 */
/* @0xd9728 vstr s12, [r9, #44] */
/* @0xd972c str r5, [r9, #0x30] */
/* @0xd9730 ldr r3, [r3, #0x8] */
/* @0xd9734 blx r3 */
/* @0xd9738 ldr r4, [r7, #0x7c] */
/* @0xd973c ldr r3, [r9] */
/* @0xd9740 mov r2, r6 */
/* @0xd9744 mov r1, #5 */
/* @0xd9748 str r8, [r9, #0x38] */
/* @0xd974c vmov s15, r4 */
/* @0xd9750 mov r0, r9 */
/* @0xd9754 vcvt.f64.u32 d7, s15 */
/* @0xd9758 vmov r4, r5, d7 */
/* @0xd975c vstr s14, [r9, #44] */
/* @0xd9760 str r5, [r9, #0x30] */
/* @0xd9764 ldr r3, [r3, #0x8] */
/* @0xd9768 blx r3 */
/* @0xd976c vldr s15, [r7, #180] */
/* @0xd9770 vcvt.f64.f32 d6, s15 */
/* @0xd9774 ldr r3, [r9] */
/* @0xd9778 mov r2, r6 */
/* @0xd977c mov r1, #8 */
/* @0xd9780 str r8, [r9, #0x38] */
/* @0xd9784 mov r0, r9 */
/* @0xd9788 vmov r4, r5, d6 */
/* @0xd978c vstr s12, [r9, #44] */
/* @0xd9790 str r5, [r9, #0x30] */
/* @0xd9794 ldr r3, [r3, #0x8] */
/* @0xd9798 blx r3 */
/* @0xd979c vldr s15, [r7, #184] */
/* @0xd97a0 vcvt.f64.f32 d6, s15 */
/* @0xd97a4 ldr r3, [r9] */
/* @0xd97a8 mov r2, r6 */
/* @0xd97ac mov r1, #8 */
/* @0xd97b0 str r8, [r9, #0x38] */
/* @0xd97b4 mov r0, r9 */
/* @0xd97b8 vmov r4, r5, d6 */
/* @0xd97bc vstr s12, [r9, #44] */
/* @0xd97c0 str r5, [r9, #0x30] */
/* @0xd97c4 ldr r3, [r3, #0x8] */
/* @0xd97c8 blx r3 */
/* @0xd97cc vldr s15, [r7, #204] */
/* @0xd97d0 vcvt.f64.f32 d6, s15 */
/* @0xd97d4 ldr r3, [r9] */
/* @0xd97d8 mov r2, r6 */
/* @0xd97dc mov r1, #8 */
/* @0xd97e0 str r8, [r9, #0x38] */
/* @0xd97e4 mov r0, r9 */
/* @0xd97e8 vmov r4, r5, d6 */
/* @0xd97ec vstr s12, [r9, #44] */
/* @0xd97f0 str r5, [r9, #0x30] */
/* @0xd97f4 ldr r3, [r3, #0x8] */
/* @0xd97f8 blx r3 */
/* @0xd97fc vldr s15, [r7, #212] */
/* @0xd9800 vcvt.f64.f32 d6, s15 */
/* @0xd9804 ldr r3, [r9] */
/* @0xd9808 mov r2, r6 */
/* @0xd980c mov r1, #8 */
/* @0xd9810 str r8, [r9, #0x38] */
/* @0xd9814 mov r0, r9 */
/* @0xd9818 vmov r4, r5, d6 */
/* @0xd981c vstr s12, [r9, #44] */
/* @0xd9820 str r5, [r9, #0x30] */
/* @0xd9824 ldr r3, [r3, #0x8] */
/* @0xd9828 blx r3 */
/* @0xd982c vldr s15, [r7, #220] */
/* @0xd9830 vcvt.f64.f32 d6, s15 */
/* @0xd9834 ldr r3, [r9] */
/* @0xd9838 mov r2, r6 */
/* @0xd983c mov r1, #8 */
/* @0xd9840 str r8, [r9, #0x38] */
/* @0xd9844 mov r0, r9 */
/* @0xd9848 vmov r4, r5, d6 */
/* @0xd984c vstr s12, [r9, #44] */
/* @0xd9850 str r5, [r9, #0x30] */
/* @0xd9854 ldr r3, [r3, #0x8] */
/* @0xd9858 blx r3 */
/* @0xd985c vldr s15, [r7, #216] */
/* @0xd9860 vcvt.f64.f32 d6, s15 */
/* @0xd9864 ldr r3, [r9] */
/* @0xd9868 mov r2, r6 */
/* @0xd986c mov r1, #8 */
/* @0xd9870 str r8, [r9, #0x38] */
/* @0xd9874 mov r0, r9 */
/* @0xd9878 vmov r4, r5, d6 */
/* @0xd987c vstr s12, [r9, #44] */
/* @0xd9880 str r5, [r9, #0x30] */
/* @0xd9884 ldr r3, [r3, #0x8] */
/* @0xd9888 blx r3 */
/* @0xd988c vldr s15, [r7, #224] */
/* @0xd9890 vcvt.f64.f32 d6, s15 */
/* @0xd9894 ldr r3, [r9] */
/* @0xd9898 mov r2, r6 */
/* @0xd989c mov r1, #8 */
/* @0xd98a0 str r8, [r9, #0x38] */
/* @0xd98a4 mov r0, r9 */
/* @0xd98a8 vmov r4, r5, d6 */
/* @0xd98ac vstr s12, [r9, #44] */
/* @0xd98b0 str r5, [r9, #0x30] */
/* @0xd98b4 ldr r3, [r3, #0x8] */
/* @0xd98b8 blx r3 */
/* @0xd98bc vldr s15, [r7, #228] */
/* @0xd98c0 vcvt.f64.f32 d6, s15 */
/* @0xd98c4 ldr r3, [r9] */
/* @0xd98c8 mov r2, r6 */
/* @0xd98cc mov r1, #8 */
/* @0xd98d0 str r8, [r9, #0x38] */
/* @0xd98d4 mov r0, r9 */
/* @0xd98d8 vmov r4, r5, d6 */
/* @0xd98dc vstr s12, [r9, #44] */
/* @0xd98e0 str r5, [r9, #0x30] */
/* @0xd98e4 ldr r3, [r3, #0x8] */
/* @0xd98e8 blx r3 */
/* @0xd98ec vldr s15, [r7, #208] */
/* @0xd98f0 vcvt.f64.f32 d6, s15 */
/* @0xd98f4 ldr r3, [r9] */
/* @0xd98f8 mov r2, r6 */
/* @0xd98fc mov r1, #8 */
/* @0xd9900 str r8, [r9, #0x38] */
/* @0xd9904 mov r0, r9 */
/* @0xd9908 vmov r4, r5, d6 */
/* @0xd990c vstr s12, [r9, #44] */
/* @0xd9910 str r5, [r9, #0x30] */
/* @0xd9914 ldr r3, [r3, #0x8] */
/* @0xd9918 blx r3 */
/* @0xd991c vldr s15, [r7, #196] */
/* @0xd9920 vcvt.f64.f32 d6, s15 */
/* @0xd9924 ldr r3, [r9] */
/* @0xd9928 mov r2, r6 */
/* @0xd992c mov r1, #8 */
/* @0xd9930 str r8, [r9, #0x38] */
/* @0xd9934 mov r0, r9 */
/* @0xd9938 vmov r4, r5, d6 */
/* @0xd993c vstr s12, [r9, #44] */
/* @0xd9940 str r5, [r9, #0x30] */
/* @0xd9944 ldr r3, [r3, #0x8] */
/* @0xd9948 blx r3 */
/* @0xd994c vldr s15, [r7, #200] */
/* @0xd9950 vcvt.f64.f32 d6, s15 */
/* @0xd9954 ldr r3, [r9] */
/* @0xd9958 mov r2, r6 */
/* @0xd995c mov r1, #8 */
/* @0xd9960 str r8, [r9, #0x38] */
/* @0xd9964 mov r0, r9 */
/* @0xd9968 vmov r4, r5, d6 */
/* @0xd996c vstr s12, [r9, #44] */
/* @0xd9970 str r5, [r9, #0x30] */
/* @0xd9974 ldr r3, [r3, #0x8] */
/* @0xd9978 blx r3 */
/* @0xd997c ldr r4, [r7, #0x8c] */
/* @0xd9980 ldr r3, [r9] */
/* @0xd9984 mov r2, r6 */
/* @0xd9988 mov r1, #5 */
/* @0xd998c str r8, [r9, #0x38] */
/* @0xd9990 vmov s15, r4 */
/* @0xd9994 mov r0, r9 */
/* @0xd9998 vcvt.f64.u32 d7, s15 */
/* @0xd999c vmov r4, r5, d7 */
/* @0xd99a0 vstr s14, [r9, #44] */
/* @0xd99a4 str r5, [r9, #0x30] */
/* @0xd99a8 ldr r3, [r3, #0x8] */
/* @0xd99ac blx r3 */
/* @0xd99b0 vldr s15, [r7, #164] */
/* @0xd99b4 vcvt.f64.f32 d6, s15 */
/* @0xd99b8 ldr r3, [r9] */
/* @0xd99bc mov r2, r6 */
/* @0xd99c0 mov r1, #8 */
/* @0xd99c4 str r8, [r9, #0x38] */
/* @0xd99c8 mov r0, r9 */
/* @0xd99cc vmov r4, r5, d6 */
/* @0xd99d0 vstr s12, [r9, #44] */
/* @0xd99d4 str r5, [r9, #0x30] */
/* @0xd99d8 ldr r3, [r3, #0x8] */
/* @0xd99dc blx r3 */
/* @0xd99e0 vldr s15, [r7, #160] */
/* @0xd99e4 vcvt.f64.f32 d6, s15 */
/* @0xd99e8 ldr r3, [r9] */
/* @0xd99ec mov r2, r6 */
/* @0xd99f0 mov r1, #8 */
/* @0xd99f4 str r8, [r9, #0x38] */
/* @0xd99f8 mov r0, r9 */
/* @0xd99fc vmov r4, r5, d6 */
/* @0xd9a00 vstr s12, [r9, #44] */
/* @0xd9a04 str r5, [r9, #0x30] */
/* @0xd9a08 ldr r3, [r3, #0x8] */
/* @0xd9a0c blx r3 */
/* @0xd9a10 ldr r4, [r7, #0xa8] */
/* @0xd9a14 ldr r3, [r9] */
/* @0xd9a18 mov r2, r6 */
/* @0xd9a1c mov r1, #5 */
/* @0xd9a20 str r8, [r9, #0x38] */
/* @0xd9a24 vmov s15, r4 */
/* @0xd9a28 mov r0, r9 */
/* @0xd9a2c vcvt.f64.u32 d7, s15 */
/* @0xd9a30 vmov r4, r5, d7 */
/* @0xd9a34 vstr s14, [r9, #44] */
/* @0xd9a38 str r5, [r9, #0x30] */
/* @0xd9a3c ldr r3, [r3, #0x8] */
/* @0xd9a40 blx r3 */
/* @0xd9a44 vldr s15, [r7, #144] */
/* @0xd9a48 vcvt.f64.f32 d6, s15 */
/* @0xd9a4c ldr r3, [r9] */
/* @0xd9a50 mov r2, r6 */
/* @0xd9a54 mov r1, #8 */
/* @0xd9a58 str r8, [r9, #0x38] */
/* @0xd9a5c mov r0, r9 */
/* @0xd9a60 vmov r4, r5, d6 */
/* @0xd9a64 vstr s12, [r9, #44] */
/* @0xd9a68 str r5, [r9, #0x30] */
/* @0xd9a6c ldr r3, [r3, #0x8] */
/* @0xd9a70 blx r3 */
/* @0xd9a74 mov r0, r7 */
/* @0xd9a78 bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0xd9a7c ldr r3, [r9] */
/* @0xd9a80 mov r2, r6 */
/* @0xd9a84 mov r1, #5 */
/* @0xd9a88 str r8, [r9, #0x38] */
/* @0xd9a8c vmov s15, r0 */
/* @0xd9a90 mov r0, r9 */
/* @0xd9a94 vcvt.f64.u32 d7, s15 */
/* @0xd9a98 vmov r4, r5, d7 */
/* @0xd9a9c vstr s14, [r9, #44] */
/* @0xd9aa0 str r5, [r9, #0x30] */
/* @0xd9aa4 ldr r3, [r3, #0x8] */
/* @0xd9aa8 blx r3 */
/* @0xd9aac vldr s15, [r7, #148] */
/* @0xd9ab0 vcvt.f64.f32 d6, s15 */
/* @0xd9ab4 ldr r3, [r9] */
/* @0xd9ab8 mov r2, r6 */
/* @0xd9abc mov r1, #8 */
/* @0xd9ac0 str r8, [r9, #0x38] */
/* @0xd9ac4 mov r0, r9 */
/* @0xd9ac8 vmov r4, r5, d6 */
/* @0xd9acc vstr s12, [r9, #44] */
/* @0xd9ad0 str r5, [r9, #0x30] */
/* @0xd9ad4 ldr r3, [r3, #0x8] */
/* @0xd9ad8 blx r3 */
/* @0xd9adc vldr s15, [r7, #152] */
/* @0xd9ae0 vcvt.f64.f32 d6, s15 */
/* @0xd9ae4 ldr r3, [r9] */
/* @0xd9ae8 mov r2, r6 */
/* @0xd9aec mov r1, #8 */
/* @0xd9af0 str r8, [r9, #0x38] */
/* @0xd9af4 mov r0, r9 */
/* @0xd9af8 vmov r4, r5, d6 */
/* @0xd9afc vstr s12, [r9, #44] */
/* @0xd9b00 str r5, [r9, #0x30] */
/* @0xd9b04 ldr r3, [r3, #0x8] */
/* @0xd9b08 blx r3 */
/* @0xd9b0c vldr s15, [r7, #156] */
/* @0xd9b10 vcvt.f64.f32 d6, s15 */
/* @0xd9b14 ldr r3, [r9] */
/* @0xd9b18 mov r2, r6 */
/* @0xd9b1c mov r1, #8 */
/* @0xd9b20 str r8, [r9, #0x38] */
/* @0xd9b24 mov r0, r9 */
/* @0xd9b28 vmov r4, r5, d6 */
/* @0xd9b2c vstr s12, [r9, #44] */
/* @0xd9b30 str r5, [r9, #0x30] */
/* @0xd9b34 ldr r3, [r3, #0x8] */
/* @0xd9b38 blx r3 */
/* @0xd9b3c mov r1, r8 */
/* @0xd9b40 mov r0, r7 */
/* @0xd9b44 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9b48 ldr r3, [r9] */
/* @0xd9b4c mov r2, r6 */
/* @0xd9b50 mov r1, #5 */
/* @0xd9b54 str r8, [r9, #0x38] */
/* @0xd9b58 vmov s15, r0 */
/* @0xd9b5c mov r0, r9 */
/* @0xd9b60 vcvt.f64.u32 d7, s15 */
/* @0xd9b64 vmov r4, r5, d7 */
/* @0xd9b68 vstr s14, [r9, #44] */
/* @0xd9b6c str r5, [r9, #0x30] */
/* @0xd9b70 ldr r3, [r3, #0x8] */
/* @0xd9b74 blx r3 */
/* @0xd9b78 mov r1, #1 */
/* @0xd9b7c mov r0, r7 */
/* @0xd9b80 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9b84 ldr r3, [r9] */
/* @0xd9b88 mov r2, r6 */
/* @0xd9b8c mov r1, #5 */
/* @0xd9b90 str r8, [r9, #0x38] */
/* @0xd9b94 vmov s13, r0 */
/* @0xd9b98 mov r0, r9 */
/* @0xd9b9c vcvt.f64.u32 d6, s13 */
/* @0xd9ba0 vmov r4, r5, d6 */
/* @0xd9ba4 vstr s12, [r9, #44] */
/* @0xd9ba8 str r5, [r9, #0x30] */
/* @0xd9bac ldr r3, [r3, #0x8] */
/* @0xd9bb0 blx r3 */
/* @0xd9bb4 mov r1, #2 */
/* @0xd9bb8 mov r0, r7 */
/* @0xd9bbc bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9bc0 ldr r3, [r9] */
/* @0xd9bc4 mov r2, r6 */
/* @0xd9bc8 mov r1, #5 */
/* @0xd9bcc str r8, [r9, #0x38] */
/* @0xd9bd0 vmov s15, r0 */
/* @0xd9bd4 mov r0, r9 */
/* @0xd9bd8 vcvt.f64.u32 d7, s15 */
/* @0xd9bdc vmov r4, r5, d7 */
/* @0xd9be0 vstr s14, [r9, #44] */
/* @0xd9be4 str r5, [r9, #0x30] */
/* @0xd9be8 ldr r3, [r3, #0x8] */
/* @0xd9bec blx r3 */
/* @0xd9bf0 mov r1, #3 */
/* @0xd9bf4 mov r0, r7 */
/* @0xd9bf8 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9bfc ldr r3, [r9] */
/* @0xd9c00 mov r2, r6 */
/* @0xd9c04 mov r1, #5 */
/* @0xd9c08 str r8, [r9, #0x38] */
/* @0xd9c0c vmov s13, r0 */
/* @0xd9c10 mov r0, r9 */
/* @0xd9c14 vcvt.f64.u32 d6, s13 */
/* @0xd9c18 vmov r4, r5, d6 */
/* @0xd9c1c vstr s12, [r9, #44] */
/* @0xd9c20 str r5, [r9, #0x30] */
/* @0xd9c24 ldr r3, [r3, #0x8] */
/* @0xd9c28 blx r3 */
/* @0xd9c2c mov r1, #4 */
/* @0xd9c30 mov r0, r7 */
/* @0xd9c34 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9c38 ldr r3, [r9] */
/* @0xd9c3c mov r2, r6 */
/* @0xd9c40 mov r1, #5 */
/* @0xd9c44 str r8, [r9, #0x38] */
/* @0xd9c48 vmov s15, r0 */
/* @0xd9c4c mov r0, r9 */
/* @0xd9c50 vcvt.f64.u32 d7, s15 */
/* @0xd9c54 vmov r4, r5, d7 */
/* @0xd9c58 vstr s14, [r9, #44] */
/* @0xd9c5c str r5, [r9, #0x30] */
/* @0xd9c60 ldr r3, [r3, #0x8] */
/* @0xd9c64 blx r3 */
/* @0xd9c68 mov r1, #5 */
/* @0xd9c6c mov r0, r7 */
/* @0xd9c70 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9c74 ldr r3, [r9] */
/* @0xd9c78 mov r2, r6 */
/* @0xd9c7c mov r1, #5 */
/* @0xd9c80 str r8, [r9, #0x38] */
/* @0xd9c84 vmov s13, r0 */
/* @0xd9c88 mov r0, r9 */
/* @0xd9c8c vcvt.f64.u32 d6, s13 */
/* @0xd9c90 vmov r4, r5, d6 */
/* @0xd9c94 vstr s12, [r9, #44] */
/* @0xd9c98 str r5, [r9, #0x30] */
/* @0xd9c9c ldr r3, [r3, #0x8] */
/* @0xd9ca0 blx r3 */
/* @0xd9ca4 mov r1, #6 */
/* @0xd9ca8 mov r0, r7 */
/* @0xd9cac bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9cb0 ldr r3, [r9] */
/* @0xd9cb4 mov r2, r6 */
/* @0xd9cb8 mov r1, #5 */
/* @0xd9cbc str r8, [r9, #0x38] */
/* @0xd9cc0 vmov s15, r0 */
/* @0xd9cc4 mov r0, r9 */
/* @0xd9cc8 vcvt.f64.u32 d7, s15 */
/* @0xd9ccc vmov r4, r5, d7 */
/* @0xd9cd0 vstr s14, [r9, #44] */
/* @0xd9cd4 str r5, [r9, #0x30] */
/* @0xd9cd8 ldr r3, [r3, #0x8] */
/* @0xd9cdc blx r3 */
/* @0xd9ce0 mov r1, #7 */
/* @0xd9ce4 mov r0, r7 */
/* @0xd9ce8 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9cec ldr r3, [r9] */
/* @0xd9cf0 mov r2, r6 */
/* @0xd9cf4 mov r1, #5 */
/* @0xd9cf8 str r8, [r9, #0x38] */
/* @0xd9cfc vmov s13, r0 */
/* @0xd9d00 mov r0, r9 */
/* @0xd9d04 vcvt.f64.u32 d6, s13 */
/* @0xd9d08 vmov r4, r5, d6 */
/* @0xd9d0c vstr s12, [r9, #44] */
/* @0xd9d10 str r5, [r9, #0x30] */
/* @0xd9d14 ldr r3, [r3, #0x8] */
/* @0xd9d18 blx r3 */
/* @0xd9d1c mov r1, #8 */
/* @0xd9d20 mov r0, r7 */
/* @0xd9d24 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9d28 ldr r3, [r9] */
/* @0xd9d2c mov r2, r6 */
/* @0xd9d30 mov r1, #5 */
/* @0xd9d34 str r8, [r9, #0x38] */
/* @0xd9d38 vmov s15, r0 */
/* @0xd9d3c mov r0, r9 */
/* @0xd9d40 vcvt.f64.u32 d7, s15 */
/* @0xd9d44 vmov r4, r5, d7 */
/* @0xd9d48 vstr s14, [r9, #44] */
/* @0xd9d4c str r5, [r9, #0x30] */
/* @0xd9d50 ldr r3, [r3, #0x8] */
/* @0xd9d54 blx r3 */
/* @0xd9d58 mov r1, #9 */
/* @0xd9d5c mov r0, r7 */
/* @0xd9d60 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9d64 ldr r3, [r9] */
/* @0xd9d68 mov r2, r6 */
/* @0xd9d6c mov r1, #5 */
/* @0xd9d70 str r8, [r9, #0x38] */
/* @0xd9d74 vmov s13, r0 */
/* @0xd9d78 mov r0, r9 */
/* @0xd9d7c vcvt.f64.u32 d6, s13 */
/* @0xd9d80 vmov r4, r5, d6 */
/* @0xd9d84 vstr s12, [r9, #44] */
/* @0xd9d88 str r5, [r9, #0x30] */
/* @0xd9d8c ldr r3, [r3, #0x8] */
/* @0xd9d90 blx r3 */
/* @0xd9d94 mov r1, #10 */
/* @0xd9d98 mov r0, r7 */
/* @0xd9d9c bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9da0 ldr r3, [r9] */
/* @0xd9da4 mov r2, r6 */
/* @0xd9da8 mov r1, #5 */
/* @0xd9dac str r8, [r9, #0x38] */
/* @0xd9db0 vmov s15, r0 */
/* @0xd9db4 mov r0, r9 */
/* @0xd9db8 vcvt.f64.u32 d7, s15 */
/* @0xd9dbc vmov r4, r5, d7 */
/* @0xd9dc0 vstr s14, [r9, #44] */
/* @0xd9dc4 str r5, [r9, #0x30] */
/* @0xd9dc8 ldr r3, [r3, #0x8] */
/* @0xd9dcc blx r3 */
/* @0xd9dd0 mov r1, #11 */
/* @0xd9dd4 mov r0, r7 */
/* @0xd9dd8 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9ddc ldr r3, [r9] */
/* @0xd9de0 mov r2, r6 */
/* @0xd9de4 mov r1, #5 */
/* @0xd9de8 str r8, [r9, #0x38] */
/* @0xd9dec vmov s13, r0 */
/* @0xd9df0 mov r0, r9 */
/* @0xd9df4 vcvt.f64.u32 d6, s13 */
/* @0xd9df8 vmov r4, r5, d6 */
/* @0xd9dfc vstr s12, [r9, #44] */
/* @0xd9e00 str r5, [r9, #0x30] */
/* @0xd9e04 ldr r3, [r3, #0x8] */
/* @0xd9e08 blx r3 */
/* @0xd9e0c ldr r4, [r7, #0x128] */
/* @0xd9e10 ldr r3, [r9] */
/* @0xd9e14 mov r2, r6 */
/* @0xd9e18 mov r1, #5 */
/* @0xd9e1c str r8, [r9, #0x38] */
/* @0xd9e20 vmov s15, r4 */
/* @0xd9e24 mov r0, r9 */
/* @0xd9e28 vcvt.f64.u32 d7, s15 */
/* @0xd9e2c vmov r4, r5, d7 */
/* @0xd9e30 vstr s14, [r9, #44] */
/* @0xd9e34 str r5, [r9, #0x30] */
/* @0xd9e38 ldr r3, [r3, #0x8] */
/* @0xd9e3c blx r3 */
/* @0xd9e40 vldr s15, [r7, #300] */
/* @0xd9e44 vcvt.f64.f32 d6, s15 */
/* @0xd9e48 ldr r3, [r9] */
/* @0xd9e4c mov r2, r6 */
/* @0xd9e50 mov r1, #8 */
/* @0xd9e54 str r8, [r9, #0x38] */
/* @0xd9e58 mov r0, r9 */
/* @0xd9e5c vmov r4, r5, d6 */
/* @0xd9e60 vstr s12, [r9, #44] */
/* @0xd9e64 str r5, [r9, #0x30] */
/* @0xd9e68 ldr r3, [r3, #0x8] */
/* @0xd9e6c blx r3 */
/* @0xd9e70 vldr s15, [r7, #304] */
/* @0xd9e74 vcvt.f64.f32 d6, s15 */
/* @0xd9e78 ldr r3, [r9] */
/* @0xd9e7c mov r2, r6 */
/* @0xd9e80 mov r1, #8 */
/* @0xd9e84 str r8, [r9, #0x38] */
/* @0xd9e88 mov r0, r9 */
/* @0xd9e8c vmov r4, r5, d6 */
/* @0xd9e90 vstr s12, [r9, #44] */
/* @0xd9e94 str r5, [r9, #0x30] */
/* @0xd9e98 ldr r3, [r3, #0x8] */
/* @0xd9e9c blx r3 */
/* @0xd9ea0 ldr r4, [r7, #0x140] */
/* @0xd9ea4 ldr r3, [r9] */
/* @0xd9ea8 mov r2, r6 */
/* @0xd9eac mov r1, #5 */
/* @0xd9eb0 str r8, [r9, #0x38] */
/* @0xd9eb4 vmov s15, r4 */
/* @0xd9eb8 mov r0, r9 */
/* @0xd9ebc vcvt.f64.u32 d7, s15 */
/* @0xd9ec0 vmov r4, r5, d7 */
/* @0xd9ec4 vstr s14, [r9, #44] */
/* @0xd9ec8 str r5, [r9, #0x30] */
/* @0xd9ecc ldr r3, [r3, #0x8] */
/* @0xd9ed0 blx r3 */
/* @0xd9ed4 vldr s15, [r7, #312] */
/* @0xd9ed8 vcvt.f64.f32 d6, s15 */
/* @0xd9edc ldr r3, [r9] */
/* @0xd9ee0 mov r2, r6 */
/* @0xd9ee4 mov r1, #8 */
/* @0xd9ee8 str r8, [r9, #0x38] */
/* @0xd9eec mov r0, r9 */
/* @0xd9ef0 vmov r4, r5, d6 */
/* @0xd9ef4 vstr s12, [r9, #44] */
/* @0xd9ef8 str r5, [r9, #0x30] */
/* @0xd9efc ldr r3, [r3, #0x8] */
/* @0xd9f00 blx r3 */
/* @0xd9f04 vldr s15, [r7, #308] */
/* @0xd9f08 vcvt.f64.f32 d6, s15 */
/* @0xd9f0c ldr r3, [r9] */
/* @0xd9f10 mov r2, r6 */
/* @0xd9f14 mov r1, #8 */
/* @0xd9f18 str r8, [r9, #0x38] */
/* @0xd9f1c mov r0, r9 */
/* @0xd9f20 vmov r4, r5, d6 */
/* @0xd9f24 vstr s12, [r9, #44] */
/* @0xd9f28 str r5, [r9, #0x30] */
/* @0xd9f2c ldr r3, [r3, #0x8] */
/* @0xd9f30 blx r3 */
/* @0xd9f34 vldr s15, [r7, #316] */
/* @0xd9f38 vcvt.f64.f32 d6, s15 */
/* @0xd9f3c ldr r3, [r9] */
/* @0xd9f40 mov r2, r6 */
/* @0xd9f44 mov r1, #8 */
/* @0xd9f48 str r8, [r9, #0x38] */
/* @0xd9f4c mov r0, r9 */
/* @0xd9f50 vmov r4, r5, d6 */
/* @0xd9f54 vstr s12, [r9, #44] */
/* @0xd9f58 str r5, [r9, #0x30] */
/* @0xd9f5c ldr r3, [r3, #0x8] */
/* @0xd9f60 blx r3 */
/* @0xd9f64 vldr s15, [r7, #188] */
/* @0xd9f68 vcvt.f64.f32 d6, s15 */
/* @0xd9f6c ldr r3, [r9] */
/* @0xd9f70 mov r2, r6 */
/* @0xd9f74 mov r1, #8 */
/* @0xd9f78 str r8, [r9, #0x38] */
/* @0xd9f7c mov r0, r9 */
/* @0xd9f80 vmov r4, r5, d6 */
/* @0xd9f84 vstr s12, [r9, #44] */
/* @0xd9f88 str r5, [r9, #0x30] */
/* @0xd9f8c ldr r3, [r3, #0x8] */
/* @0xd9f90 blx r3 */
/* @0xd9f94 vldr s15, [r7, #192] */
/* @0xd9f98 vcvt.f64.f32 d6, s15 */
/* @0xd9f9c ldr r3, [r9] */
/* @0xd9fa0 mov r2, r6 */
/* @0xd9fa4 mov r1, #8 */
/* @0xd9fa8 str r8, [r9, #0x38] */
/* @0xd9fac mov r0, r9 */
/* @0xd9fb0 vmov r4, r5, d6 */
/* @0xd9fb4 vstr s12, [r9, #44] */
/* @0xd9fb8 str r5, [r9, #0x30] */
/* @0xd9fbc ldr r3, [r3, #0x8] */
/* @0xd9fc0 blx r3 */
/* @0xd9fc4 ldrb r4, [r7, #0x67] */
/* @0xd9fc8 ldr r3, [r9] */
/* @0xd9fcc mov r2, r6 */
/* @0xd9fd0 mov r1, #5 */
/* @0xd9fd4 str r8, [r9, #0x38] */
/* @0xd9fd8 vmov s15, r4 */
/* @0xd9fdc mov r0, r9 */
/* @0xd9fe0 vcvt.f64.u32 d7, s15 */
/* @0xd9fe4 vmov r4, r5, d7 */
/* @0xd9fe8 vstr s14, [r9, #44] */
/* @0xd9fec str r5, [r9, #0x30] */
/* @0xd9ff0 ldr r3, [r3, #0x8] */
/* @0xd9ff4 blx r3 */
/* @0xd9ff8 vldr s15, [r7, #384] */
/* @0xd9ffc vcvt.f64.f32 d6, s15 */
/* @0xda000 ldr r3, [r9] */
/* @0xda004 mov r2, r6 */
/* @0xda008 mov r1, #8 */
/* @0xda00c str r8, [r9, #0x38] */
/* @0xda010 mov r0, r9 */
/* @0xda014 vmov r4, r5, d6 */
/* @0xda018 vstr s12, [r9, #44] */
/* @0xda01c str r5, [r9, #0x30] */
/* @0xda020 ldr r3, [r3, #0x8] */
/* @0xda024 blx r3 */
/* @0xda028 ldrb r4, [r7, #0x65] */
/* @0xda02c ldr r3, [r9] */
/* @0xda030 mov r2, r6 */
/* @0xda034 mov r1, #5 */
/* @0xda038 str r8, [r9, #0x38] */
/* @0xda03c vmov s15, r4 */
/* @0xda040 mov r0, r9 */
/* @0xda044 vcvt.f64.u32 d7, s15 */
/* @0xda048 vmov r4, r5, d7 */
/* @0xda04c vstr s14, [r9, #44] */
/* @0xda050 str r5, [r9, #0x30] */
/* @0xda054 ldr r3, [r3, #0x8] */
/* @0xda058 blx r3 */
/* @0xda05c ldr r4, [r7, #0xac] */
/* @0xda060 ldr r3, [r9] */
/* @0xda064 mov r2, r6 */
/* @0xda068 mov r1, #6 */
/* @0xda06c str r8, [r9, #0x38] */
/* @0xda070 vmov s13, r4 */
/* @0xda074 mov r0, r9 */
/* @0xda078 vcvt.f64.s32 d6, s13 */
/* @0xda07c vmov r4, r5, d6 */
/* @0xda080 vstr s12, [r9, #44] */
/* @0xda084 str r5, [r9, #0x30] */
/* @0xda088 ldr r3, [r3, #0x8] */
/* @0xda08c blx r3 */
/* @0xda090 ldrb r4, [r7, #0x66] */
/* @0xda094 ldr r3, [r9] */
/* @0xda098 mov r2, r6 */
/* @0xda09c str r8, [r9, #0x38] */
/* @0xda0a0 mov r0, r9 */
/* @0xda0a4 vmov s15, r4 */
/* @0xda0a8 mov r1, #5 */
/* @0xda0ac vcvt.f64.u32 d7, s15 */
/* @0xda0b0 vmov r4, r5, d7 */
/* @0xda0b4 vstr s14, [r9, #44] */
/* @0xda0b8 str r5, [r9, #0x30] */
/* @0xda0bc ldr r3, [r3, #0x8] */
/* @0xda0c0 blx r3 */
/* @0xda0c4 ldrb r3, [r7, #0x64] */
/* @0xda0c8 cmp r3, r8 */
/* @0xda0cc bne 0xdaa98 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x13a8> */
/* @0xda0d0 ldr r4, [r7, #0xec] */
/* @0xda0d4 mov r8, #0 */
/* @0xda0d8 ldr r3, [r9] */
/* @0xda0dc mov r1, #6 */
/* @0xda0e0 mov r2, r6 */
/* @0xda0e4 mov r0, r9 */
/* @0xda0e8 vmov s13, r4 */
/* @0xda0ec str r8, [r9, #0x38] */
/* @0xda0f0 vcvt.f64.s32 d6, s13 */
/* @0xda0f4 vmov r4, r5, d6 */
/* @0xda0f8 vstr s12, [r9, #44] */
/* @0xda0fc str r5, [r9, #0x30] */
/* @0xda100 ldr r3, [r3, #0x8] */
/* @0xda104 blx r3 */
/* @0xda108 ldr r4, [r7, #0xf4] */
/* @0xda10c ldr r3, [r9] */
/* @0xda110 mov r1, #6 */
/* @0xda114 mov r2, r6 */
/* @0xda118 mov r0, r9 */
/* @0xda11c vmov s15, r4 */
/* @0xda120 str r8, [r9, #0x38] */
/* @0xda124 vcvt.f64.s32 d7, s15 */
/* @0xda128 vmov r4, r5, d7 */
/* @0xda12c vstr s14, [r9, #44] */
/* @0xda130 str r5, [r9, #0x30] */
/* @0xda134 ldr r3, [r3, #0x8] */
/* @0xda138 blx r3 */
/* @0xda13c ldr r4, [r7, #0xe8] */
/* @0xda140 ldr r3, [r9] */
/* @0xda144 mov r1, #6 */
/* @0xda148 mov r2, r6 */
/* @0xda14c mov r0, r9 */
/* @0xda150 vmov s13, r4 */
/* @0xda154 str r8, [r9, #0x38] */
/* @0xda158 vcvt.f64.s32 d6, s13 */
/* @0xda15c vmov r4, r5, d6 */
/* @0xda160 vstr s12, [r9, #44] */
/* @0xda164 str r5, [r9, #0x30] */
/* @0xda168 ldr r3, [r3, #0x8] */
/* @0xda16c blx r3 */
/* @0xda170 ldr r4, [r7, #0xf0] */
/* @0xda174 ldr r3, [r9] */
/* @0xda178 mov r1, #6 */
/* @0xda17c mov r2, r6 */
/* @0xda180 mov r0, r9 */
/* @0xda184 vmov s15, r4 */
/* @0xda188 str r8, [r9, #0x38] */
/* @0xda18c vcvt.f64.s32 d7, s15 */
/* @0xda190 vmov r4, r5, d7 */
/* @0xda194 vstr s14, [r9, #44] */
/* @0xda198 str r5, [r9, #0x30] */
/* @0xda19c ldr r3, [r3, #0x8] */
/* @0xda1a0 blx r3 */
/* @0xda1a4 ldr r0, [r7, #0x8c] */
/* @0xda1a8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xda1ac subs r10, r0, #0 */
/* @0xda1b0 beq 0xdad34 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1644> */
/* @0xda1b4 vldr s15, [r10, #28] */
/* @0xda1b8 vcvt.f32.s32 s15, s15 */
/* @0xda1bc vldr s14, [r7, #152] */
/* @0xda1c0 ldr r3, [r9] */
/* @0xda1c4 mov r1, #8 */
/* @0xda1c8 mov r2, r6 */
/* @0xda1cc mov r0, r9 */
/* @0xda1d0 str r8, [r9, #0x38] */
/* @0xda1d4 vmul.f32 s15, s15, s14 */
/* @0xda1d8 vcvt.f64.f32 d6, s15 */
/* @0xda1dc vmov r4, r5, d6 */
/* @0xda1e0 vstr s12, [r9, #44] */
/* @0xda1e4 str r5, [r9, #0x30] */
/* @0xda1e8 ldr r3, [r3, #0x8] */
/* @0xda1ec blx r3 */
/* @0xda1f0 vldr s15, [r10, #32] */
/* @0xda1f4 vcvt.f32.s32 s15, s15 */
/* @0xda1f8 vldr s14, [r7, #156] */
/* @0xda1fc ldr r3, [r9] */
/* @0xda200 mov r1, #8 */
/* @0xda204 mov r2, r6 */
/* @0xda208 str r8, [r9, #0x38] */
/* @0xda20c mov r0, r9 */
/* @0xda210 vmul.f32 s15, s15, s14 */
/* @0xda214 vcvt.f64.f32 d6, s15 */
/* @0xda218 vmov r4, r5, d6 */
/* @0xda21c vstr s12, [r9, #44] */
/* @0xda220 str r5, [r9, #0x30] */
/* @0xda224 ldr r3, [r3, #0x8] */
/* @0xda228 blx r3 */
/* @0xda22c vldr s15, [r10, #36] */
/* @0xda230 vcvt.f32.s32 s15, s15 */
/* @0xda234 vldr s14, [r7, #152] */
/* @0xda238 ldr r3, [r9] */
/* @0xda23c mov r1, #8 */
/* @0xda240 mov r2, r6 */
/* @0xda244 str r8, [r9, #0x38] */
/* @0xda248 mov r0, r9 */
/* @0xda24c vmul.f32 s15, s15, s14 */
/* @0xda250 vcvt.f64.f32 d6, s15 */
/* @0xda254 vmov r4, r5, d6 */
/* @0xda258 vstr s12, [r9, #44] */
/* @0xda25c str r5, [r9, #0x30] */
/* @0xda260 ldr r3, [r3, #0x8] */
/* @0xda264 blx r3 */
/* @0xda268 vldr s15, [r10, #40] */
/* @0xda26c vcvt.f32.s32 s15, s15 */
/* @0xda270 vldr s14, [r7, #156] */
/* @0xda274 ldr r3, [r9] */
/* @0xda278 mov r0, r9 */
/* @0xda27c str r8, [r9, #0x38] */
/* @0xda280 mov r1, #8 */
/* @0xda284 mov r2, r6 */
/* @0xda288 vmul.f32 s15, s15, s14 */
/* @0xda28c vcvt.f64.f32 d6, s15 */
/* @0xda290 vmov r4, r5, d6 */
/* @0xda294 vstr s12, [r9, #44] */
/* @0xda298 str r5, [r9, #0x30] */
/* @0xda29c ldr r3, [r3, #0x8] */
/* @0xda2a0 blx r3 */
/* @0xda2a4 ldr r8, [r7, #0x84] */
/* @0xda2a8 cmp r8, #0 */
/* @0xda2ac beq 0xdaaa8 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x13b8> */
/* @0xda2b0 ldr r12, [r8] */
/* @0xda2b4 mov r11, #0 */
/* @0xda2b8 ldr r3, [r9] */
/* @0xda2bc mov r1, #5 */
/* @0xda2c0 mov r2, r6 */
/* @0xda2c4 mov r0, r9 */
/* @0xda2c8 ldrh r4, [r12, #4] */
/* @0xda2cc add r10, sp, #8 */
/* @0xda2d0 str r11, [r9, #0x38] */
/* @0xda2d4 ubfx r4, r4, #0x5, #0x1 */
/* @0xda2d8 vmov s15, r4 */
/* @0xda2dc vcvt.f64.u32 d7, s15 */
/* @0xda2e0 vmov r4, r5, d7 */
/* @0xda2e4 vstr s14, [r9, #44] */
/* @0xda2e8 str r5, [r9, #0x30] */
/* @0xda2ec ldr r3, [r3, #0x8] */
/* @0xda2f0 blx r3 */
/* @0xda2f4 ldr r12, [r8] */
/* @0xda2f8 ldr r3, [r9] */
/* @0xda2fc mov r1, #5 */
/* @0xda300 mov r2, r6 */
/* @0xda304 mov r0, r9 */
/* @0xda308 ldrh r4, [r12, #4] */
/* @0xda30c str r11, [r9, #0x38] */
/* @0xda310 ubfx r4, r4, #0x4, #0x1 */
/* @0xda314 vmov s13, r4 */
/* @0xda318 vcvt.f64.u32 d6, s13 */
/* @0xda31c vmov r4, r5, d6 */
/* @0xda320 vstr s12, [r9, #44] */
/* @0xda324 str r5, [r9, #0x30] */
/* @0xda328 ldr r3, [r3, #0x8] */
/* @0xda32c blx r3 */
/* @0xda330 ldr r3, [r8] */
/* @0xda334 vldr s15, [pc, #784] */
/* @0xda338 vldr s14, [r3, #88] */
/* @0xda33c vmul.f32 s15, s14, s15 */
/* @0xda340 vldr s14, [pc, #776] */
/* @0xda344 ldr r3, [r9] */
/* @0xda348 mov r1, #8 */
/* @0xda34c mov r2, r6 */
/* @0xda350 mov r0, r9 */
/* @0xda354 str r11, [r9, #0x38] */
/* @0xda358 vdiv.f32 s15, s15, s14 */
/* @0xda35c vcvt.f64.f32 d6, s15 */
/* @0xda360 vmov r4, r5, d6 */
/* @0xda364 vstr s12, [r9, #44] */
/* @0xda368 str r5, [r9, #0x30] */
/* @0xda36c ldr r3, [r3, #0x8] */
/* @0xda370 blx r3 */
/* @0xda374 mov r1, r11 */
/* @0xda378 mov r2, r10 */
/* @0xda37c mov r0, r7 */
/* @0xda380 bl 0x1f9684 <_Z25GV_PhysicsLinearVelocityXP9CInstanceiP6RValue> */
/* @0xda384 subs r3, r0, #0 */
/* @0xda388 beq 0xda930 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1240> */
/* @0xda38c ldr r3, [r9] */
/* @0xda390 mov r0, r9 */
/* @0xda394 str r11, [r9, #0x2c] */
/* @0xda398 mov r1, #8 */
/* @0xda39c str r11, [r9, #0x30] */
/* @0xda3a0 mov r2, r6 */
/* @0xda3a4 str r11, [r9, #0x38] */
/* @0xda3a8 ldr r3, [r3, #0x8] */
/* @0xda3ac blx r3 */
/* @0xda3b0 mov r0, r7 */
/* @0xda3b4 mov r1, #0 */
/* @0xda3b8 mov r2, r10 */
/* @0xda3bc bl 0x1f96e8 <_Z25GV_PhysicsLinearVelocityYP9CInstanceiP6RValue> */
/* @0xda3c0 subs r3, r0, #0 */
/* @0xda3c4 bne 0xdaa6c <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x137c> */
/* @0xda3c8 vldr d7, [sp, #8] */
/* @0xda3cc vcvt.f32.f64 s14, d7 */
/* @0xda3d0 ldr r12, [r9] */
/* @0xda3d4 mov r0, r9 */
/* @0xda3d8 str r3, [r9, #0x38] */
/* @0xda3dc mov r1, #8 */
/* @0xda3e0 mov r2, r6 */
/* @0xda3e4 vcvt.f64.f32 d6, s14 */
/* @0xda3e8 vmov r4, r5, d6 */
/* @0xda3ec vstr s12, [r9, #44] */
/* @0xda3f0 str r5, [r9, #0x30] */
/* @0xda3f4 ldr r3, [r12, #0x8] */
/* @0xda3f8 blx r3 */
/* @0xda3fc mov r0, r7 */
/* @0xda400 mov r1, #0 */
/* @0xda404 mov r2, r10 */
/* @0xda408 bl 0x1f9d58 <_Z16GV_PhysicsSpeedXP9CInstanceiP6RValue> */
/* @0xda40c subs r3, r0, #0 */
/* @0xda410 bne 0xdaa40 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1350> */
/* @0xda414 vldr d7, [sp, #8] */
/* @0xda418 vcvt.f32.f64 s14, d7 */
/* @0xda41c ldr r12, [r9] */
/* @0xda420 mov r0, r9 */
/* @0xda424 str r3, [r9, #0x38] */
/* @0xda428 mov r1, #8 */
/* @0xda42c mov r2, r6 */
/* @0xda430 vcvt.f64.f32 d6, s14 */
/* @0xda434 vmov r4, r5, d6 */
/* @0xda438 vstr s12, [r9, #44] */
/* @0xda43c str r5, [r9, #0x30] */
/* @0xda440 ldr r3, [r12, #0x8] */
/* @0xda444 blx r3 */
/* @0xda448 mov r0, r7 */
/* @0xda44c mov r1, #0 */
/* @0xda450 mov r2, r10 */
/* @0xda454 bl 0x1f9e3c <_Z16GV_PhysicsSpeedYP9CInstanceiP6RValue> */
/* @0xda458 subs r3, r0, #0 */
/* @0xda45c bne 0xdaa14 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1324> */
/* @0xda460 vldr d7, [sp, #8] */
/* @0xda464 vcvt.f32.f64 s14, d7 */
/* @0xda468 ldr r12, [r9] */
/* @0xda46c mov r0, r9 */
/* @0xda470 str r3, [r9, #0x38] */
/* @0xda474 mov r1, #8 */
/* @0xda478 mov r2, r6 */
/* @0xda47c vcvt.f64.f32 d6, s14 */
/* @0xda480 vmov r4, r5, d6 */
/* @0xda484 vstr s12, [r9, #44] */
/* @0xda488 str r5, [r9, #0x30] */
/* @0xda48c ldr r3, [r12, #0x8] */
/* @0xda490 blx r3 */
/* @0xda494 mov r0, r7 */
/* @0xda498 mov r1, #0 */
/* @0xda49c mov r2, r10 */
/* @0xda4a0 bl 0x1f95bc <_Z19GV_PhysicsPositionXP9CInstanceiP6RValue> */
/* @0xda4a4 subs r3, r0, #0 */
/* @0xda4a8 bne 0xda9e8 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x12f8> */
/* @0xda4ac vldr d7, [sp, #8] */
/* @0xda4b0 vcvt.f32.f64 s14, d7 */
/* @0xda4b4 ldr r12, [r9] */
/* @0xda4b8 mov r0, r9 */
/* @0xda4bc str r3, [r9, #0x38] */
/* @0xda4c0 mov r1, #8 */
/* @0xda4c4 mov r2, r6 */
/* @0xda4c8 vcvt.f64.f32 d6, s14 */
/* @0xda4cc vmov r4, r5, d6 */
/* @0xda4d0 vstr s12, [r9, #44] */
/* @0xda4d4 str r5, [r9, #0x30] */
/* @0xda4d8 ldr r3, [r12, #0x8] */
/* @0xda4dc blx r3 */
/* @0xda4e0 mov r0, r7 */
/* @0xda4e4 mov r1, #0 */
/* @0xda4e8 mov r2, r10 */
/* @0xda4ec bl 0x1f9620 <_Z19GV_PhysicsPositionYP9CInstanceiP6RValue> */
/* @0xda4f0 subs r3, r0, #0 */
/* @0xda4f4 bne 0xda990 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x12a0> */
/* @0xda4f8 vldr d7, [sp, #8] */
/* @0xda4fc vcvt.f32.f64 s14, d7 */
/* @0xda500 ldr r12, [r9] */
/* @0xda504 mov r0, r9 */
/* @0xda508 str r3, [r9, #0x38] */
/* @0xda50c mov r1, #8 */
/* @0xda510 mov r2, r6 */
/* @0xda514 vcvt.f64.f32 d6, s14 */
/* @0xda518 vmov r4, r5, d6 */
/* @0xda51c vstr s12, [r9, #44] */
/* @0xda520 str r5, [r9, #0x30] */
/* @0xda524 ldr r3, [r12, #0x8] */
/* @0xda528 blx r3 */
/* @0xda52c ldr r3, [r8] */
/* @0xda530 vldr s15, [pc, #276] */
/* @0xda534 vldr s14, [r3, #72] */
/* @0xda538 vmul.f32 s15, s14, s15 */
/* @0xda53c vldr s14, [pc, #268] */
/* @0xda540 ldr r3, [r9] */
/* @0xda544 mov r11, #0 */
/* @0xda548 mov r1, #8 */
/* @0xda54c mov r2, r6 */
/* @0xda550 mov r0, r9 */
/* @0xda554 str r11, [r9, #0x38] */
/* @0xda558 vdiv.f32 s15, s15, s14 */
/* @0xda55c vcvt.f64.f32 d6, s15 */
/* @0xda560 vmov r4, r5, d6 */
/* @0xda564 vstr s12, [r9, #44] */
/* @0xda568 str r5, [r9, #0x30] */
/* @0xda56c ldr r3, [r3, #0x8] */
/* @0xda570 blx r3 */
/* @0xda574 ldr r12, [r8] */
/* @0xda578 ldr r3, [r9] */
/* @0xda57c mov r1, #5 */
/* @0xda580 mov r2, r6 */
/* @0xda584 mov r0, r9 */
/* @0xda588 ldrh r4, [r12, #4] */
/* @0xda58c str r11, [r9, #0x38] */
/* @0xda590 ubfx r4, r4, #0x3, #0x1 */
/* @0xda594 vmov s15, r4 */
/* @0xda598 vcvt.f64.u32 d7, s15 */
/* @0xda59c vmov r4, r5, d7 */
/* @0xda5a0 vstr s14, [r9, #44] */
/* @0xda5a4 str r5, [r9, #0x30] */
/* @0xda5a8 ldr r3, [r3, #0x8] */
/* @0xda5ac blx r3 */
/* @0xda5b0 mov r0, r7 */
/* @0xda5b4 mov r1, r11 */
/* @0xda5b8 mov r2, r10 */
/* @0xda5bc bl 0x1f97cc <_Z15GV_PhysicsCOM_XP9CInstanceiP6RValue> */
/* @0xda5c0 subs r3, r0, #0 */
/* @0xda5c4 bne 0xda968 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1278> */
/* @0xda5c8 vldr d7, [sp, #8] */
/* @0xda5cc vcvt.f32.f64 s14, d7 */
/* @0xda5d0 ldr r12, [r9] */
/* @0xda5d4 mov r0, r9 */
/* @0xda5d8 str r3, [r9, #0x38] */
/* @0xda5dc mov r1, #8 */
/* @0xda5e0 mov r2, r6 */
/* @0xda5e4 vcvt.f64.f32 d6, s14 */
/* @0xda5e8 vmov r4, r5, d6 */
/* @0xda5ec vstr s12, [r9, #44] */
/* @0xda5f0 str r5, [r9, #0x30] */
/* @0xda5f4 ldr r3, [r12, #0x8] */
/* @0xda5f8 blx r3 */
/* @0xda5fc mov r2, r10 */
/* @0xda600 mov r0, r7 */
/* @0xda604 mov r1, #0 */
/* @0xda608 bl 0x1f9830 <_Z15GV_PhysicsCOM_YP9CInstanceiP6RValue> */
/* @0xda60c subs r3, r0, #0 */
/* @0xda610 bne 0xda9bc <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x12cc> */
/* @0xda614 vldr d7, [sp, #8] */
/* @0xda618 vcvt.f32.f64 s14, d7 */
/* @0xda61c ldr r12, [r9] */
/* @0xda620 mov r0, r9 */
/* @0xda624 str r3, [r9, #0x38] */
/* @0xda628 mov r1, #8 */
/* @0xda62c mov r2, r6 */
/* @0xda630 vcvt.f64.f32 d6, s14 */
/* @0xda634 vmov r4, r5, d6 */
/* @0xda638 vstr s12, [r9, #44] */
/* @0xda63c str r5, [r9, #0x30] */
/* @0xda640 ldr r3, [r12, #0x8] */
/* @0xda644 blx r3 */
/* @0xda648 b 0xda65c <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xf6c> */
/* @0xda64c teqmi r4, #0 */
/* @0xda650 ldrdmi r0, r1, [r9], #-251 */
/* @0xda654 eorseq r3, r1, r8, ror r0 */
/* @0xda658 eorseq r3, r1, r4, lsl #8 */
/* @0xda65c ldr r12, [r8] */
/* @0xda660 mov r10, #0 */
/* @0xda664 ldr r3, [r9] */
/* @0xda668 mov r1, #5 */
/* @0xda66c mov r2, r6 */
/* @0xda670 mov r0, r9 */
/* @0xda674 ldr r4, [r12] */
/* @0xda678 str r10, [r9, #0x38] */
/* @0xda67c subs r12, r4, #2 */
/* @0xda680 rsbs r4, r12, #0 */
/* @0xda684 adcs r4, r4, r12 */
/* @0xda688 vmov s15, r4 */
/* @0xda68c vcvt.f64.u32 d7, s15 */
/* @0xda690 vmov r4, r5, d7 */
/* @0xda694 vstr s14, [r9, #44] */
/* @0xda698 str r5, [r9, #0x30] */
/* @0xda69c ldr r3, [r3, #0x8] */
/* @0xda6a0 blx r3 */
/* @0xda6a4 ldr r12, [r8] */
/* @0xda6a8 ldr r3, [r9] */
/* @0xda6ac mov r1, #5 */
/* @0xda6b0 mov r2, r6 */
/* @0xda6b4 mov r0, r9 */
/* @0xda6b8 ldr r4, [r12] */
/* @0xda6bc str r10, [r9, #0x38] */
/* @0xda6c0 subs lr, r4, #1 */
/* @0xda6c4 rsbs r4, lr, #0 */
/* @0xda6c8 adcs r4, r4, lr */
/* @0xda6cc vmov s13, r4 */
/* @0xda6d0 vcvt.f64.u32 d6, s13 */
/* @0xda6d4 vmov r4, r5, d6 */
/* @0xda6d8 vstr s12, [r9, #44] */
/* @0xda6dc str r5, [r9, #0x30] */
/* @0xda6e0 ldr r3, [r3, #0x8] */
/* @0xda6e4 blx r3 */
/* @0xda6e8 ldr r3, [r8] */
/* @0xda6ec vldr s14, [r3, #48] */
/* @0xda6f0 vmul.f32 s14, s14, s14 */
/* @0xda6f4 vldr s13, [r3, #44] */
/* @0xda6f8 vldr s12, [r3, #132] */
/* @0xda6fc vldr s15, [r3, #140] */
/* @0xda700 ldr r3, [r9] */
/* @0xda704 mov r1, #8 */
/* @0xda708 mov r2, r6 */
/* @0xda70c str r10, [r9, #0x38] */
/* @0xda710 mov r0, r9 */
/* @0xda714 vmla.f32 s14, s13, s13 */
/* @0xda718 vmla.f32 s15, s14, s12 */
/* @0xda71c vcvt.f64.f32 d6, s15 */
/* @0xda720 vmov r4, r5, d6 */
/* @0xda724 vstr s12, [r9, #44] */
/* @0xda728 str r5, [r9, #0x30] */
/* @0xda72c ldr r3, [r3, #0x8] */
/* @0xda730 blx r3 */
/* @0xda734 ldr r3, [r8] */
/* @0xda738 vldr s15, [r3, #132] */
/* @0xda73c vcvt.f64.f32 d6, s15 */
/* @0xda740 ldr r3, [r9] */
/* @0xda744 mov r1, #8 */
/* @0xda748 mov r2, r6 */
/* @0xda74c mov r0, r9 */
/* @0xda750 str r10, [r9, #0x38] */
/* @0xda754 vmov r4, r5, d6 */
/* @0xda758 vstr s12, [r9, #44] */
/* @0xda75c str r5, [r9, #0x30] */
/* @0xda760 ldr r3, [r3, #0x8] */
/* @0xda764 blx r3 */
/* @0xda768 ldr r12, [r8] */
/* @0xda76c ldr r3, [r9] */
/* @0xda770 mov r0, r9 */
/* @0xda774 mov r1, #5 */
/* @0xda778 mov r2, r6 */
/* @0xda77c ldrh r4, [r12, #4] */
/* @0xda780 str r10, [r9, #0x38] */
/* @0xda784 eor r4, r4, #2 */
/* @0xda788 ubfx r4, r4, #0x1, #0x1 */
/* @0xda78c vmov s15, r4 */
/* @0xda790 vcvt.f64.u32 d7, s15 */
/* @0xda794 vmov r4, r5, d7 */
/* @0xda798 vstr s14, [r9, #44] */
/* @0xda79c str r5, [r9, #0x30] */
/* @0xda7a0 ldr r3, [r3, #0x8] */
/* @0xda7a4 blx r3 */
/* @0xda7a8 ldr r4, [r7, #0x14c] */
/* @0xda7ac mov r8, #0 */
/* @0xda7b0 ldr r3, [r9] */
/* @0xda7b4 mov r1, #5 */
/* @0xda7b8 mov r2, r6 */
/* @0xda7bc mov r0, r9 */
/* @0xda7c0 vmov s13, r4 */
/* @0xda7c4 str r8, [r9, #0x38] */
/* @0xda7c8 vcvt.f64.u32 d6, s13 */
/* @0xda7cc vmov r4, r5, d6 */
/* @0xda7d0 vstr s12, [r9, #44] */
/* @0xda7d4 str r5, [r9, #0x30] */
/* @0xda7d8 ldr r3, [r3, #0x8] */
/* @0xda7dc blx r3 */
/* @0xda7e0 ldrb r4, [r7, #0x15c] */
/* @0xda7e4 ldr r3, [r9] */
/* @0xda7e8 mov r1, #5 */
/* @0xda7ec mov r2, r6 */
/* @0xda7f0 mov r0, r9 */
/* @0xda7f4 vmov s15, r4 */
/* @0xda7f8 str r8, [r9, #0x38] */
/* @0xda7fc vcvt.f64.u32 d7, s15 */
/* @0xda800 vmov r4, r5, d7 */
/* @0xda804 vstr s14, [r9, #44] */
/* @0xda808 str r5, [r9, #0x30] */
/* @0xda80c ldr r3, [r3, #0x8] */
/* @0xda810 blx r3 */
/* @0xda814 vldr s15, [r7, #344] */
/* @0xda818 vcvt.f64.f32 d6, s15 */
/* @0xda81c ldr r3, [r9] */
/* @0xda820 mov r1, #8 */
/* @0xda824 mov r2, r6 */
/* @0xda828 str r8, [r9, #0x38] */
/* @0xda82c mov r0, r9 */
/* @0xda830 vmov r4, r5, d6 */
/* @0xda834 vstr s12, [r9, #44] */
/* @0xda838 str r5, [r9, #0x30] */
/* @0xda83c ldr r3, [r3, #0x8] */
/* @0xda840 blx r3 */
/* @0xda844 vldr s15, [r7, #340] */
/* @0xda848 vcvt.f64.f32 d6, s15 */
/* @0xda84c ldr r3, [r9] */
/* @0xda850 mov r1, #8 */
/* @0xda854 mov r2, r6 */
/* @0xda858 str r8, [r9, #0x38] */
/* @0xda85c mov r0, r9 */
/* @0xda860 vmov r4, r5, d6 */
/* @0xda864 vstr s12, [r9, #44] */
/* @0xda868 str r5, [r9, #0x30] */
/* @0xda86c ldr r3, [r3, #0x8] */
/* @0xda870 blx r3 */
/* @0xda874 ldrb r4, [r7, #0x15d] */
/* @0xda878 ldr r3, [r9] */
/* @0xda87c mov r0, r9 */
/* @0xda880 str r8, [r9, #0x38] */
/* @0xda884 mov r1, #5 */
/* @0xda888 vmov s15, r4 */
/* @0xda88c mov r2, r6 */
/* @0xda890 vcvt.f64.u32 d7, s15 */
/* @0xda894 vmov r4, r5, d7 */
/* @0xda898 vstr s14, [r9, #44] */
/* @0xda89c str r5, [r9, #0x30] */
/* @0xda8a0 ldr r3, [r3, #0x8] */
/* @0xda8a4 blx r3 */
/* @0xda8a8 ldr r3, [pc, #-0x25c] */
/* @0xda8ac ldr r3, [pc, r3] */
/* @0xda8b0 ldrb r3, [r3] */
/* @0xda8b4 cmp r3, r8 */
/* @0xda8b8 beq 0xda900 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1210> */
/* @0xda8bc mov r1, r8 */
/* @0xda8c0 add r2, sp, #8 */
/* @0xda8c4 mov r0, r7 */
/* @0xda8c8 bl 0x1fadd4 <_Z8GV_LayerP9CInstanceiP6RValue> */
/* @0xda8cc vldr d7, [sp, #8] */
/* @0xda8d0 vcvt.f32.f64 s14, d7 */
/* @0xda8d4 ldr r3, [r9] */
/* @0xda8d8 mov r2, r6 */
/* @0xda8dc str r8, [r9, #0x38] */
/* @0xda8e0 mov r0, r9 */
/* @0xda8e4 mov r1, #8 */
/* @0xda8e8 vcvt.f64.f32 d6, s14 */
/* @0xda8ec vmov r4, r5, d6 */
/* @0xda8f0 vstr s12, [r9, #44] */
/* @0xda8f4 str r5, [r9, #0x30] */
/* @0xda8f8 ldr r3, [r3, #0x8] */
/* @0xda8fc blx r3 */
/* @0xda900 ldr r12, [pc, #-0x2b0] */
/* @0xda904 mov r0, r9 */
/* @0xda908 mov r1, r7 */
/* @0xda90c mov r2, #1 */
/* @0xda910 ldr r12, [pc, r12] */
/* @0xda914 movw r3, #0x86a0 */
/* @0xda918 movt r3, #0x1 */
/* @0xda91c ldr r12, [r12] */
/* @0xda920 str r12, [sp] */
/* @0xda924 bl 0xd9548 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii> */
/* @0xda928 add sp, sp, #28 */
/* @0xda92c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xda930 vldr d7, [sp, #8] */
/* @0xda934 vcvt.f32.f64 s14, d7 */
/* @0xda938 ldr r12, [r9] */
/* @0xda93c mov r0, r9 */
/* @0xda940 str r3, [r9, #0x38] */
/* @0xda944 mov r1, #8 */
/* @0xda948 mov r2, r6 */
/* @0xda94c vcvt.f64.f32 d6, s14 */
/* @0xda950 vmov r4, r5, d6 */
/* @0xda954 vstr s12, [r9, #44] */
/* @0xda958 str r5, [r9, #0x30] */
/* @0xda95c ldr r3, [r12, #0x8] */
/* @0xda960 blx r3 */
/* @0xda964 b 0xda3b0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xcc0> */
/* @0xda968 ldr r3, [r9] */
/* @0xda96c mov r0, r9 */
/* @0xda970 str r11, [r9, #0x2c] */
/* @0xda974 mov r1, #8 */
/* @0xda978 str r11, [r9, #0x30] */
/* @0xda97c mov r2, r6 */
/* @0xda980 str r11, [r9, #0x38] */
/* @0xda984 ldr r3, [r3, #0x8] */
/* @0xda988 blx r3 */
/* @0xda98c b 0xda5fc <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xf0c> */
/* @0xda990 ldr r12, [r9] */
/* @0xda994 mov r3, #0 */
/* @0xda998 mov r0, r9 */
/* @0xda99c str r3, [r9, #0x2c] */
/* @0xda9a0 str r3, [r9, #0x30] */
/* @0xda9a4 mov r1, #8 */
/* @0xda9a8 str r3, [r9, #0x38] */
/* @0xda9ac mov r2, r6 */
/* @0xda9b0 ldr r3, [r12, #0x8] */
/* @0xda9b4 blx r3 */
/* @0xda9b8 b 0xda52c <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xe3c> */
/* @0xda9bc ldr r12, [r9] */
/* @0xda9c0 mov r3, #0 */
/* @0xda9c4 mov r0, r9 */
/* @0xda9c8 str r3, [r9, #0x2c] */
/* @0xda9cc str r3, [r9, #0x30] */
/* @0xda9d0 mov r1, #8 */
/* @0xda9d4 str r3, [r9, #0x38] */
/* @0xda9d8 mov r2, r6 */
/* @0xda9dc ldr r3, [r12, #0x8] */
/* @0xda9e0 blx r3 */
/* @0xda9e4 b 0xda65c <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xf6c> */
/* @0xda9e8 ldr r12, [r9] */
/* @0xda9ec mov r3, #0 */
/* @0xda9f0 mov r0, r9 */
/* @0xda9f4 str r3, [r9, #0x2c] */
/* @0xda9f8 str r3, [r9, #0x30] */
/* @0xda9fc mov r1, #8 */
/* @0xdaa00 str r3, [r9, #0x38] */
/* @0xdaa04 mov r2, r6 */
/* @0xdaa08 ldr r3, [r12, #0x8] */
/* @0xdaa0c blx r3 */
/* @0xdaa10 b 0xda4e0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xdf0> */
/* @0xdaa14 ldr r12, [r9] */
/* @0xdaa18 mov r3, #0 */
/* @0xdaa1c mov r0, r9 */
/* @0xdaa20 str r3, [r9, #0x2c] */
/* @0xdaa24 str r3, [r9, #0x30] */
/* @0xdaa28 mov r1, #8 */
/* @0xdaa2c str r3, [r9, #0x38] */
/* @0xdaa30 mov r2, r6 */
/* @0xdaa34 ldr r3, [r12, #0x8] */
/* @0xdaa38 blx r3 */
/* @0xdaa3c b 0xda494 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xda4> */
/* @0xdaa40 ldr r12, [r9] */
/* @0xdaa44 mov r3, #0 */
/* @0xdaa48 mov r0, r9 */
/* @0xdaa4c str r3, [r9, #0x2c] */
/* @0xdaa50 str r3, [r9, #0x30] */
/* @0xdaa54 mov r1, #8 */
/* @0xdaa58 str r3, [r9, #0x38] */
/* @0xdaa5c mov r2, r6 */
/* @0xdaa60 ldr r3, [r12, #0x8] */
/* @0xdaa64 blx r3 */
/* @0xdaa68 b 0xda448 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xd58> */
/* @0xdaa6c ldr r12, [r9] */
/* @0xdaa70 mov r3, #0 */
/* @0xdaa74 mov r0, r9 */
/* @0xdaa78 str r3, [r9, #0x2c] */
/* @0xdaa7c str r3, [r9, #0x30] */
/* @0xdaa80 mov r1, #8 */
/* @0xdaa84 str r3, [r9, #0x38] */
/* @0xdaa88 mov r2, r6 */
/* @0xdaa8c ldr r3, [r12, #0x8] */
/* @0xdaa90 blx r3 */
/* @0xdaa94 b 0xda3fc <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xd0c> */
/* @0xdaa98 mov r0, r7 */
/* @0xdaa9c mov r1, #1 */
/* @0xdaaa0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0xdaaa4 b 0xda0d0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x9e0> */
/* @0xdaaa8 ldr r3, [r9] */
/* @0xdaaac mov r2, r6 */
/* @0xdaab0 str r8, [r9, #0x2c] */
/* @0xdaab4 mov r0, r9 */
/* @0xdaab8 str r8, [r9, #0x30] */
/* @0xdaabc mov r1, #5 */
/* @0xdaac0 str r8, [r9, #0x38] */
/* @0xdaac4 ldr r3, [r3, #0x8] */
/* @0xdaac8 blx r3 */
/* @0xdaacc ldr r3, [r9] */
/* @0xdaad0 str r8, [r9, #0x2c] */
/* @0xdaad4 mov r2, r6 */
/* @0xdaad8 str r8, [r9, #0x30] */
/* @0xdaadc mov r0, r9 */
/* @0xdaae0 mov r1, #5 */
/* @0xdaae4 str r8, [r9, #0x38] */
/* @0xdaae8 ldr r3, [r3, #0x8] */
/* @0xdaaec blx r3 */
/* @0xdaaf0 ldr r3, [r9] */
/* @0xdaaf4 str r8, [r9, #0x2c] */
/* @0xdaaf8 mov r2, r6 */
/* @0xdaafc str r8, [r9, #0x30] */
/* @0xdab00 mov r0, r9 */
/* @0xdab04 mov r1, #8 */
/* @0xdab08 str r8, [r9, #0x38] */
/* @0xdab0c ldr r3, [r3, #0x8] */
/* @0xdab10 blx r3 */
/* @0xdab14 ldr r3, [r9] */
/* @0xdab18 str r8, [r9, #0x2c] */
/* @0xdab1c mov r2, r6 */
/* @0xdab20 str r8, [r9, #0x30] */
/* @0xdab24 mov r0, r9 */
/* @0xdab28 mov r1, #8 */
/* @0xdab2c str r8, [r9, #0x38] */
/* @0xdab30 ldr r3, [r3, #0x8] */
/* @0xdab34 blx r3 */
/* @0xdab38 ldr r3, [r9] */
/* @0xdab3c str r8, [r9, #0x2c] */
/* @0xdab40 mov r2, r6 */
/* @0xdab44 str r8, [r9, #0x30] */
/* @0xdab48 mov r0, r9 */
/* @0xdab4c mov r1, #8 */
/* @0xdab50 str r8, [r9, #0x38] */
/* @0xdab54 ldr r3, [r3, #0x8] */
/* @0xdab58 blx r3 */
/* @0xdab5c ldr r3, [r9] */
/* @0xdab60 str r8, [r9, #0x2c] */
/* @0xdab64 mov r2, r6 */
/* @0xdab68 str r8, [r9, #0x30] */
/* @0xdab6c mov r0, r9 */
/* @0xdab70 mov r1, #8 */
/* @0xdab74 str r8, [r9, #0x38] */
/* @0xdab78 ldr r3, [r3, #0x8] */
/* @0xdab7c blx r3 */
/* @0xdab80 ldr r3, [r9] */
/* @0xdab84 str r8, [r9, #0x2c] */
/* @0xdab88 mov r2, r6 */
/* @0xdab8c str r8, [r9, #0x30] */
/* @0xdab90 mov r0, r9 */
/* @0xdab94 mov r1, #8 */
/* @0xdab98 str r8, [r9, #0x38] */
/* @0xdab9c ldr r3, [r3, #0x8] */
/* @0xdaba0 blx r3 */
/* @0xdaba4 ldr r3, [r9] */
/* @0xdaba8 str r8, [r9, #0x2c] */
/* @0xdabac mov r2, r6 */
/* @0xdabb0 str r8, [r9, #0x30] */
/* @0xdabb4 mov r0, r9 */
/* @0xdabb8 mov r1, #8 */
/* @0xdabbc str r8, [r9, #0x38] */
/* @0xdabc0 ldr r3, [r3, #0x8] */
/* @0xdabc4 blx r3 */
/* @0xdabc8 ldr r3, [r9] */
/* @0xdabcc str r8, [r9, #0x2c] */
/* @0xdabd0 mov r2, r6 */
/* @0xdabd4 str r8, [r9, #0x30] */
/* @0xdabd8 mov r0, r9 */
/* @0xdabdc mov r1, #8 */
/* @0xdabe0 str r8, [r9, #0x38] */
/* @0xdabe4 ldr r3, [r3, #0x8] */
/* @0xdabe8 blx r3 */
/* @0xdabec ldr r3, [r9] */
/* @0xdabf0 str r8, [r9, #0x2c] */
/* @0xdabf4 mov r2, r6 */
/* @0xdabf8 str r8, [r9, #0x30] */
/* @0xdabfc mov r0, r9 */
/* @0xdac00 mov r1, #8 */
/* @0xdac04 str r8, [r9, #0x38] */
/* @0xdac08 ldr r3, [r3, #0x8] */
/* @0xdac0c blx r3 */
/* @0xdac10 ldr r3, [r9] */
/* @0xdac14 str r8, [r9, #0x2c] */
/* @0xdac18 mov r2, r6 */
/* @0xdac1c str r8, [r9, #0x30] */
/* @0xdac20 mov r0, r9 */
/* @0xdac24 mov r1, #5 */
/* @0xdac28 str r8, [r9, #0x38] */
/* @0xdac2c ldr r3, [r3, #0x8] */
/* @0xdac30 blx r3 */
/* @0xdac34 ldr r3, [r9] */
/* @0xdac38 str r8, [r9, #0x2c] */
/* @0xdac3c mov r2, r6 */
/* @0xdac40 str r8, [r9, #0x30] */
/* @0xdac44 mov r0, r9 */
/* @0xdac48 mov r1, #8 */
/* @0xdac4c str r8, [r9, #0x38] */
/* @0xdac50 ldr r3, [r3, #0x8] */
/* @0xdac54 blx r3 */
/* @0xdac58 ldr r3, [r9] */
/* @0xdac5c str r8, [r9, #0x2c] */
/* @0xdac60 mov r2, r6 */
/* @0xdac64 str r8, [r9, #0x30] */
/* @0xdac68 mov r0, r9 */
/* @0xdac6c mov r1, #8 */
/* @0xdac70 str r8, [r9, #0x38] */
/* @0xdac74 ldr r3, [r3, #0x8] */
/* @0xdac78 blx r3 */
/* @0xdac7c ldr r3, [r9] */
/* @0xdac80 str r8, [r9, #0x2c] */
/* @0xdac84 mov r2, r6 */
/* @0xdac88 str r8, [r9, #0x30] */
/* @0xdac8c mov r0, r9 */
/* @0xdac90 mov r1, #5 */
/* @0xdac94 str r8, [r9, #0x38] */
/* @0xdac98 ldr r3, [r3, #0x8] */
/* @0xdac9c blx r3 */
/* @0xdaca0 ldr r3, [r9] */
/* @0xdaca4 str r8, [r9, #0x2c] */
/* @0xdaca8 mov r2, r6 */
/* @0xdacac str r8, [r9, #0x30] */
/* @0xdacb0 mov r0, r9 */
/* @0xdacb4 mov r1, #5 */
/* @0xdacb8 str r8, [r9, #0x38] */
/* @0xdacbc ldr r3, [r3, #0x8] */
/* @0xdacc0 blx r3 */
/* @0xdacc4 ldr r3, [r9] */
/* @0xdacc8 str r8, [r9, #0x2c] */
/* @0xdaccc mov r2, r6 */
/* @0xdacd0 str r8, [r9, #0x30] */
/* @0xdacd4 mov r0, r9 */
/* @0xdacd8 mov r1, #8 */
/* @0xdacdc str r8, [r9, #0x38] */
/* @0xdace0 ldr r3, [r3, #0x8] */
/* @0xdace4 blx r3 */
/* @0xdace8 ldr r3, [r9] */
/* @0xdacec str r8, [r9, #0x2c] */
/* @0xdacf0 mov r2, r6 */
/* @0xdacf4 str r8, [r9, #0x30] */
/* @0xdacf8 mov r0, r9 */
/* @0xdacfc mov r1, #8 */
/* @0xdad00 str r8, [r9, #0x38] */
/* @0xdad04 ldr r3, [r3, #0x8] */
/* @0xdad08 blx r3 */
/* @0xdad0c ldr r3, [r9] */
/* @0xdad10 str r8, [r9, #0x2c] */
/* @0xdad14 mov r0, r9 */
/* @0xdad18 str r8, [r9, #0x30] */
/* @0xdad1c mov r1, #8 */
/* @0xdad20 str r8, [r9, #0x38] */
/* @0xdad24 mov r2, r6 */
/* @0xdad28 ldr r3, [r3, #0x8] */
/* @0xdad2c blx r3 */
/* @0xdad30 b 0xda7a8 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x10b8> */
/* @0xdad34 ldr r3, [r9] */
/* @0xdad38 mov r2, r6 */
/* @0xdad3c str r10, [r9, #0x2c] */
/* @0xdad40 mov r0, r9 */
/* @0xdad44 str r10, [r9, #0x30] */
/* @0xdad48 mov r1, #8 */
/* @0xdad4c str r10, [r9, #0x38] */
/* @0xdad50 ldr r3, [r3, #0x8] */
/* @0xdad54 blx r3 */
/* @0xdad58 ldr r3, [r9] */
/* @0xdad5c str r10, [r9, #0x2c] */
/* @0xdad60 mov r2, r6 */
/* @0xdad64 str r10, [r9, #0x30] */
/* @0xdad68 mov r0, r9 */
/* @0xdad6c mov r1, #8 */
/* @0xdad70 str r10, [r9, #0x38] */
/* @0xdad74 ldr r3, [r3, #0x8] */
/* @0xdad78 blx r3 */
/* @0xdad7c ldr r3, [r9] */
/* @0xdad80 str r10, [r9, #0x2c] */
/* @0xdad84 mov r2, r6 */
/* @0xdad88 str r10, [r9, #0x30] */
/* @0xdad8c mov r0, r9 */
/* @0xdad90 mov r1, #8 */
/* @0xdad94 str r10, [r9, #0x38] */
/* @0xdad98 ldr r3, [r3, #0x8] */
/* @0xdad9c blx r3 */
/* @0xdada0 ldr r3, [r9] */
/* @0xdada4 str r10, [r9, #0x2c] */
/* @0xdada8 mov r0, r9 */
/* @0xdadac str r10, [r9, #0x30] */
/* @0xdadb0 mov r1, #8 */
/* @0xdadb4 str r10, [r9, #0x38] */
/* @0xdadb8 mov r2, r6 */
/* @0xdadbc ldr r3, [r3, #0x8] */
/* @0xdadc0 blx r3 */
/* @0xdadc4 b 0xda2a4 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xbb4> */
