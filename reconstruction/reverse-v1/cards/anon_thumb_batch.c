/* cally 逆向卡：anon_thumb_batch —— 匿名段 Thumb-2 批（14 段 / 20,858 B / 7,971 条锚点）
 *（原版 libyoyo.so，ELF32 ARM，armeabi-v7a，stripped）
 *
 * @card  14 段互不相邻。asm/anon_splits.tsv 给每段登记的尺寸是「到下一个 Thumb bl 目标的距离」，
 *        所以一个「段」里通常装着 1 个 bl 入口函数 + 若干只经指针进入的邻接函数 + 池字/表。
 *        本卡按段把窗口内每一字节都锚掉，并逐段给出「入口可达 / 段内 bl 入口 / 可打印岛」的划分。
 * 来源:  libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        （4,689,844 B，.text 0xb6fd0..0x31bb7c）
 * 锚表:  asm/index-anonT_{2f8e0a,317798,2e8c38,2fa06c,2fb894,2e90fc,2fb68c,317ba8,2fec70,309b08,2f0444,2f9ab6,2f08c6,2f1142}.tsv × 14
 *        全部由 scripts/asm_index.py --so libyoyo.so --start .. --end .. --thumb 生成（thumbv7 triple）。
 *        与既有 40 个 index-anon_*.tsv 的区别就是那三个字母：那批是 ARM triple，本批是 Thumb-2。
 * 级别:  骨架（每字节一条锚、逐字与 index 一致；语义只钉到「段属于哪个库、入口契约、调用面、
 *        段内 bl 入口表、可打印岛」；函数体不逐条解释，函数名一律 narrowed）
 *
 * ══ 这张卡存在的理由：ISA-004 / ISA-005 的负结果被调用点证据绕开了 ═════════
 *   ISA-004 当时说「无名 Thumb-2 无法自动识别」，ISA-005 说「0x2f8e0a 的 ISA 无法只靠解码判定」。
 *   这两条都没错 —— 它们的口径是**看被调方的长相**（ARM 视图里 svc/undefined/.word 的比例）。
 *   本卡换口径：**只看谁在调它、用什么编码调**。结论：14 段全部 Thumb-2，每段 2~51 条清一色同族命中。
 *
 * ══ 判定方法（不看被调方长相，只看调用点编码）═══════════════════════════
 *   ARM  `bl`   = 0xEB|imm24            → target = pc+8+imm24<<2   （只落在 4 的倍数上）
 *   ARM  `blx`  = 0xFA/0xFB|imm24:H:00  → target = pc+8+…，H=bit24 （可落到 2 的倍数；ARM→Thumb 只能走它）
 *   Thumb`bl`   = 32 位 11110 S imm10 | 11 J1 1 J2 imm11          （首半字 F0xx..F7xx，次半字 D8..DF/F8..FF）
 *   Thumb`blx`  = 次半字 C8..CF / E8..EF                          （Thumb→ARM 只能走它）
 *   —— `bl`/`blx` 都是**状态保持**的：Thumb 的 `bl` 只能进 Thumb 代码。所以「一条已确认的 Thumb
 *      `bl T`」这一件事，就把 T 钉成 Thumb，与 T 处字节长什么样无关。
 *
 *   ① 对每段起始 T 扫全 .text（2,509,740 B）：4 B 栅格找 0xEB/0xFA/0xFB 型 → **0 条命中**；
 *      2 B 栅格找 F0xx+F8xx 型 → 命中数 = 该段 in-degree（51/7/4/3/3/3/3/3/2/2/2/2/2/2），
 *      与 anon_batch5.c「排除 A」记的 in-degree 逐字相同，一条不多一条不少。
 *   ② 每个命中点再用 llvm-objdump --triple=thumbv7 解**调用者所在函数**，确认该地址上确实是一条
 *      `bl T`（是真指令边界，不是半字巧合）：89 处命中、89 处成立。
 *   ③ 反向查「段内 bl 指向谁」：指向具名 Thumb 符号（奇数 st_value）214 处，指向具名 ARM 符号 0 处。
 *   ④ 于是 14 段每段至少双向之一成立 —— 被具名 Thumb 函数 bl 进来，或自己 bl 到具名 Thumb 函数。
 *      只有 3 段（0x2e90fc / 0x2fec70 / 0x309b08）没有具名调用者，全靠 ③ 立住；这也解释了它们
 *      过去为什么看起来「没有调用面」。
 *
 *   校准（同一套扫描器跑已知答案，各取 60 个 ≥24 B 的符号）：
 *     偶数 st_value（ARM）×60   → Thumb `bl` 命中 0 处、ARM `bl` 命中 19 处、41 处无直接调用（叶/纯间接）
 *     奇数 st_value（Thumb）×60 → Thumb `bl` 命中 37 处、ARM `bl` 命中 4 处
 *     全库：4,452 个 Thumb 目标里 85 个同时是 ARM 目标（跨族碰撞 1.9%）
 *   —— 单条命中确实不可靠（那 6.7% 正是 ISA-004 踩的坑）。本批每段是 2..51 条**同族**命中 + 0 条
 *      **异族**命中；按 0.019 的碰撞率，2 条的那几段全错概率 < 4e-4，51 条那段 < 1e-40。
 *
 * ══ 14 段判定表（本卡的核心产出）═══════════════════════════════════════
 *   段        [start,end)        B     锚  in  反向bl  正向bl  异族   判决
 *   —— 反向bl = 全 .text 内指向该段起始的 Thumb `bl` 条数；正向bl = 段内指向具名 Thumb 符号的
 *      `bl` 条数；异族 = 指向该段起始的 ARM `bl`/`blx` 条数（全 14 段都是 0）。
 *   2f8e0a    2f8e0a..2f929c  1,170   455  51     51      0     0    Thumb-2
 *   317798    317798..317a44    684   281   7      7      2     0    Thumb-2
 *   2e8c38    2e8c38..2e90d4  1,180   483   4      4     16     0    Thumb-2
 *   2fa06c    2fa06c..2fa330    708   271   3      3     32     0    Thumb-2
 *   2fb894    2fb894..2fc4e8  3,156  1211   3      3     51     0    Thumb-2
 *   2e90fc    2e90fc..2e9396    666   280   3      3     20     0    Thumb-2
 *   2fb68c    2fb68c..2fb892    518   182   3      3      1     0    Thumb-2
 *   317ba8    317ba8..317e5c    692   279   3      3      0     0    Thumb-2
 *   2fec70    2fec70..300004  5,012  1832   2      2     43     0    Thumb-2
 *   309b08    309b08..30a6bc  2,996  1143   2      2     27     0    Thumb-2
 *   2f0444    2f0444..2f08c6  1,154   445   2      2      3     0    Thumb-2
 *   2f9ab6    2f9ab6..2f9f0e  1,112   424   2      2     11     0    Thumb-2
 *   2f08c6    2f08c6..2f0d1c  1,110   410   2      2      8     0    Thumb-2
 *   2f1142    2f1142..2f13fe    700   275   2      2      0     0    Thumb-2
 *   合计                     20,858  7,971
 *
 * ══ 与 anon_splits.tsv 的两处 2 B 修正 ═══════════════════════════════════
 *   0x2fb68c：split 记 520 B，但 0x2fb892 起的 2 B 是链接器 0xffff 填充（Thumb 未定义指令），
 *        不是任何函数的指令；本卡窗口收到 0x2fb892（518 B），段内最后一条是 0x2fb890 的 `b 0x2fb2ca`。
 *   0x2f1142：split 记 698 B，切在最后一条 `pop.w {r4-r11, pc}`（0x2f13fa..0x2f13fe）中间，会把出口丢掉；
 *        本卡窗口放到 0x2f13fe（700 B）。
 *   其余 12 段按 split 原值，零改动。两类修正都只动窗口边界，不动任何一条锚的文本。
 *
 * ══ 口径（写死，便于复核）══════════════════════════════════════════════
 *   · 锚 = asm_index.py 对 [start,end) 的 Thumb 解码，每行一条；本卡逐行照抄，不改助记符、不合并、
 *     不删「误译」（窗口里混进池字/数据时 objdump 照样给出可读助记符，本卡保留原文并在该节注明）。
 *   · 「入口可达」= 从该段起始做 Thumb 指令级可达性（跟 b/bcc/cbz/tbb、bl 走 fallthrough、bx/pop…pc 收口），
 *     取可达集合的最大末地址。它不是函数边界证明，只是一个可复算的下界；窗口里超出它的字节多为只经
 *     指针/表进入的邻接函数（首字节常见 push/push.w 序言）与池字。
 *   · 「正向」= bl 目标正好等于具名符号起始地址的条数（落在具名符号内部的命中不计，故 0 只代表取不到名字）。
 *   · 「段内 bl 入口」= 段内被 bl 指向的地址（把窗口当函数库看时的函数边界候选），与「入口可达」互相印证。
 *   · 「可打印岛」= 连续 ≥16 B 全落在 0x20..0x7e 的字节段；只有 2 处够长，其余 4~14 B 的打印串多半是
 *     指令字节的巧合，不单列。
 *
 * ══ 与其它卡的分工 ═══════════════════════════════════════════════════════
 *   anon_batch5.c 的「排除 A（Thumb-2，14 段）」就是本卡的输入清单：它把这 14 段留给单独一批，
 *   理由是 asm/instructions.jsonl 对无符号 Thumb 段按 ARM 解码（0x2e8c38 在全局索引里是 svcmi）。
 *   本卡与 cards/ 下既有任何卡零地址交集（这 14 段此前没有任何 index-anon_*.tsv）。
 *   上一批 anon_batch2 用同一理由跳过 5 段 Thumb-2，仍在待办里（本卡不含）。
 *
 * ══ 全局 open（本卡级别，不是逐节 open）═════════════════════════════
 *   1. 只有静态字节证据（调用点编码 + 锚 + 常量 + 字段偏移），没有一条 oracle_anchored / device_anchored；
 *      没跑行为差分，没碰设备。ISA 判决本身是「编码级」证明，不是运行期观测。
 *   2. in-degree 只数直接 `bl`；经函数指针槽、跳转表、`blx rN` 间接进入的次数不在分母里。已知偏差：
 *      0x2e90fc / 0x2fec70 / 0x309b08 三段一个具名调用者都没有，说明间接调用面确实存在（见各节）。
 *   3. 库级 proven（FreeType / libpng 邻接 / libsupc++，靠具名邻居与调用面）；**函数级名字一律 narrowed**，
 *      没有与上游源码逐行对照。写「FT_MulFix 同构」时指的是指令形态与常数，不是符号身份。
 *   4. 窗口里混着邻接函数与数据（本批 14 段只有 3 段是「一段一函数」：0x2e8c38 / 0x317ba8 / 0x2f1142（入口可达占比 99% / 96% / 100%））。
 *      本卡按字节全覆盖，但「哪一段是函数、哪一段是邻接函数」只到可达性下界，未逐函数切卡。
 *   5. 本卡只新增 cards/anon_thumb_batch.c、claims-batchCD.jsonl 与 14 个 asm/index-anonT_*.tsv；
 *      没改别人的卡、没改 scripts/、没 git、没碰设备。
 *
 * ══ 校验（脚本原样未改，每节单独切出来跑）═════════════════════════════
 *   python3 scripts/check_card_anchors.py --card <本节切片> --index asm/index-anonT_<起址>.tsv
 *     → 14/14 节 RESULT EXACT，合计 7,971 条，missing / extra / mismatch 全 0。
 *   索引侧：14 个 index 文件零空洞、零重复地址、零 <unknown>；.word 只剩 3 条（0x309b08 两条、0x2f0444 一条，
 *     都是真池字）。ARM 解码同窗口的对照会给出成片的 .word/<unknown> —— 这也是 Thumb 判定的旁证，但本卡不拿它当证据。
 *
 * ══ claims 对照 ═══════════════════════════════════════════════════════
 *   claims-batchCD.jsonl: CD-001..CD-012
 * ════════════════════════════════════════════════════════════════════ */
/* ═══════════════════════════════════════════════════════════════════════
 * §1  anon_thumb_2f8e0a   0x2f8e0a..0x2f929c   1,170 B / 455 条   in-degree 51
 * FreeType 定点算术叶例程（(a*b+0x8000)>>16 形态）+ 3 个邻接函数 + 107 B 可打印串
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 51 条 Thumb `bl` 指向本段起始：TT_RunIns×9 / anon_2fec70 区×22 / anon_2f1de8 区×13 / anon_300274 区×6 / anon_b6fd0 区×1；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 0 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 smull r3, r2, r1, r0 / asr.w r0, r2, #0x1f / add.w r0, r0, #0x8000（帧：无（叶例程，不建栈帧））；窗口内出口 45 个
 * 结构：入口可达 28 B / 8 条（2%）；段内 bl 入口 4 个：0x2f8e26(102 B/39 条) / 0x2f8e8c(86 B/36 条) / 0x2f8f3a(120 B/46 条) / 0x2f8fb4(640 B/226 条)
 *      可打印岛：0x2f9231..0x2f929c（107 B）
 *      未达字节：104 B（各入口可达集的补集；多为只经指针/表进入的邻接函数与池字，本卡不判其身份）
 * 入口就是 32×32→16.16 的 64 位写法：smull r3,r2,r1,r0 → asr.w r0,r2,#31 → add.w r0,r0,#0x8000
 *      → adds r3,r3,r0 → adc r2,r2,#0 → lsr.w r0,r3,#16 → orr.w r0,r0,r2,lsl #16 → bx lr（28 B 收工）。
 *      同段 0x2f929c 起是同族第二个叶（常数换 #0x2000、右移 14）。in=51 是全库最高，说明它是被
 *      base / psaux / truetype 三处共用的公共算子，不是游戏逻辑。
 *
 * 锚点：455 条（= asm/index-anonT_2f8e0a.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2f8e0a smull r3, r2, r1, r0
 *   @0x2f8e0e asr.w r0, r2, #0x1f
 *   @0x2f8e12 add.w r0, r0, #0x8000
 *   @0x2f8e16 adds r3, r3, r0
 *   @0x2f8e18 adc r2, r2, #0x0
 *   @0x2f8e1c lsr.w r0, r3, #0x10
 *   @0x2f8e20 orr.w r0, r0, r2, lsl #16
 *   @0x2f8e24 bx lr
 *   @0x2f8e26 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2f8e28 mov r7, r1
 *   @0x2f8e2a ldrb.w r1, [r0, #0x124]
 *   @0x2f8e2e mov r6, r3
 *   @0x2f8e30 ldr r5, [sp, #0x20]
 *   @0x2f8e32 cbz r1, 0x2f8e44 <ps_hints_apply+0x7a44>
 *   @0x2f8e34 ldr.w r2, [r0, #0x21c]
 *   @0x2f8e38 movs r1, #0x1
 *   @0x2f8e3a str r5, [sp]
 *   @0x2f8e3c ldr r4, [r2, #0x70]
 *   @0x2f8e3e mov r2, r7
 *   @0x2f8e40 blx r4
 *   @0x2f8e42 b 0x2f8e88 <ps_hints_apply+0x7a88>
 *   @0x2f8e44 ldrh.w r1, [r0, #0x174]
 *   @0x2f8e48 movw r3, #0xffff
 *   @0x2f8e4c cmp r1, r3
 *   @0x2f8e4e beq 0x2f8e62 <ps_hints_apply+0x7a62>
 *   @0x2f8e50 ldrh.w r3, [r0, #0x1ba]
 *   @0x2f8e54 subs r2, r3, r2
 *   @0x2f8e56 strh r2, [r6]
 *   @0x2f8e58 ldrh.w r2, [r0, #0x1ba]
 *   @0x2f8e5c ldrh.w r3, [r0, #0x1bc]
 *   @0x2f8e60 b 0x2f8e72 <ps_hints_apply+0x7a72>
 *   @0x2f8e62 ldrh.w r3, [r0, #0xdc]
 *   @0x2f8e66 subs r2, r3, r2
 *   @0x2f8e68 strh r2, [r6]
 *   @0x2f8e6a ldrh.w r2, [r0, #0xdc]
 *   @0x2f8e6e ldrh.w r3, [r0, #0xde]
 *   @0x2f8e72 sxth r1, r3
 *   @0x2f8e74 sxth r0, r2
 *   @0x2f8e76 subs r1, r0, r1
 *   @0x2f8e78 cmp r1, #0x0
 *   @0x2f8e7a ite lt
 *   @0x2f8e7c rsblt r3, r2, r3
 *   @0x2f8e80 rsbge r3, r3, r2
 *   @0x2f8e84 uxth r3, r3
 *   @0x2f8e86 strh r3, [r5]
 *   @0x2f8e88 add sp, #0xc
 *   @0x2f8e8a pop {r4, r5, r6, r7, pc}
 *   @0x2f8e8c push {r4, r5, lr}
 *   @0x2f8e8e mov r4, r0
 *   @0x2f8e90 ldr r3, [r0]
 *   @0x2f8e92 sub sp, #0x14
 *   @0x2f8e94 ldr.w r3, [r3, #0x80]
 *   @0x2f8e98 ldr r3, [r3, #0x34]
 *   @0x2f8e9a cbz r3, 0x2f8ede <ps_hints_apply+0x7ade>
 *   @0x2f8e9c ldr r2, [r3]
 *   @0x2f8e9e ldr r2, [r2, #0x8]
 *   @0x2f8ea0 cbz r2, 0x2f8ede <ps_hints_apply+0x7ade>
 *   @0x2f8ea2 ldr r2, [r0, #0x34]
 *   @0x2f8ea4 ldr r0, [r0, #0x38]
 *   @0x2f8ea6 str r2, [sp]
 *   @0x2f8ea8 movs r2, #0x0
 *   @0x2f8eaa str r0, [sp, #0x8]
 *   @0x2f8eac str r2, [sp, #0xc]
 *   @0x2f8eae str r2, [sp, #0x4]
 *   @0x2f8eb0 ldr r0, [r3]
 *   @0x2f8eb2 ldr r5, [r0, #0x8]
 *   @0x2f8eb4 ldr r0, [r3, #0x4]
 *   @0x2f8eb6 mov r3, sp
 *   @0x2f8eb8 blx r5
 *   @0x2f8eba cbnz r0, 0x2f8ede <ps_hints_apply+0x7ade>
 *   @0x2f8ebc ldrsh.w r3, [sp]
 *   @0x2f8ec0 ldrb.w r2, [r4, #0x40]
 *   @0x2f8ec4 str.w r0, [r4, #0xac]
 *   @0x2f8ec8 str r3, [r4, #0x34]
 *   @0x2f8eca ldrh.w r3, [sp, #0x8]
 *   @0x2f8ece str.w r0, [r4, #0xb0]
 *   @0x2f8ed2 str r3, [r4, #0x38]
 *   @0x2f8ed4 cbnz r2, 0x2f8ede <ps_hints_apply+0x7ade>
 *   @0x2f8ed6 movs r2, #0x1
 *   @0x2f8ed8 str r3, [r4, #0x3c]
 *   @0x2f8eda strb.w r2, [r4, #0x40]
 *   @0x2f8ede add sp, #0x14
 *   @0x2f8ee0 pop {r4, r5, pc}
 *   @0x2f8ee2 push {r4, lr}
 *   @0x2f8ee4 ldr.w r3, [r0, #0xc4]
 *   @0x2f8ee8 ldr.w r1, [r0, #0xc8]
 *   @0x2f8eec add.w r2, r3, #0xa
 *   @0x2f8ef0 cmp r1, r2
 *   @0x2f8ef2 blo 0x2f8f36 <ps_hints_apply+0x7b36>
 *   @0x2f8ef4 ldrb r4, [r3]
 *   @0x2f8ef6 ldrb r1, [r3, #0x1]
 *   @0x2f8ef8 orr.w r1, r1, r4, lsl #8
 *   @0x2f8efc strh r1, [r0, #0x20]
 *   @0x2f8efe ldrb r4, [r3, #0x2]
 *   @0x2f8f00 ldrb r1, [r3, #0x3]
 *   @0x2f8f02 orr.w r1, r1, r4, lsl #8
 *   @0x2f8f06 sxth r1, r1
 *   @0x2f8f08 str r1, [r0, #0x24]
 *   @0x2f8f0a ldrb r4, [r3, #0x4]
 *   @0x2f8f0c ldrb r1, [r3, #0x5]
 *   @0x2f8f0e orr.w r1, r1, r4, lsl #8
 *   @0x2f8f12 sxth r1, r1
 *   @0x2f8f14 str r1, [r0, #0x28]
 *   @0x2f8f16 ldrb r4, [r3, #0x6]
 *   @0x2f8f18 ldrb r1, [r3, #0x7]
 *   @0x2f8f1a orr.w r1, r1, r4, lsl #8
 *   @0x2f8f1e sxth r1, r1
 *   @0x2f8f20 str r1, [r0, #0x2c]
 *   @0x2f8f22 ldrb r1, [r3, #0x8]
 *   @0x2f8f24 ldrb r3, [r3, #0x9]
 *   @0x2f8f26 str.w r2, [r0, #0xc4]
 *   @0x2f8f2a orr.w r3, r3, r1, lsl #8
 *   @0x2f8f2e sxth r3, r3
 *   @0x2f8f30 str r3, [r0, #0x30]
 *   @0x2f8f32 movs r0, #0x0
 *   @0x2f8f34 pop {r4, pc}
 *   @0x2f8f36 movs r0, #0x14
 *   @0x2f8f38 pop {r4, pc}
 *   @0x2f8f3a ldr r3, [r0]
 *   @0x2f8f3c push {r4, lr}
 *   @0x2f8f3e ldr r3, [r3, #0x60]
 *   @0x2f8f40 ldr r3, [r3, #0x40]
 *   @0x2f8f42 cmp r3, #0x28
 *   @0x2f8f44 bne 0x2f8f5e <ps_hints_apply+0x7b5e>
 *   @0x2f8f46 ldr.w r2, [r0, #0x9c]
 *   @0x2f8f4a cbz r2, 0x2f8f60 <ps_hints_apply+0x7b60>
 *   @0x2f8f4c ldrb.w r3, [r2, #0x26a]
 *   @0x2f8f50 ldrb.w r2, [r2, #0x265]
 *   @0x2f8f54 cbz r2, 0x2f8f60 <ps_hints_apply+0x7b60>
 *   @0x2f8f56 adds r2, r3, #0x0
 *   @0x2f8f58 it ne
 *   @0x2f8f5a movne r2, #0x1
 *   @0x2f8f5c b 0x2f8f60 <ps_hints_apply+0x7b60>
 *   @0x2f8f5e movs r2, #0x0
 *   @0x2f8f60 ldr r3, [r0, #0x34]
 *   @0x2f8f62 ands r2, r2, #0xff
 *   @0x2f8f66 ldr r4, [r0, #0x24]
 *   @0x2f8f68 mov.w r1, #0x0
 *   @0x2f8f6c str r1, [r0, #0x48]
 *   @0x2f8f6e rsb r4, r3, r4
 *   @0x2f8f72 ldr r3, [r0, #0x38]
 *   @0x2f8f74 str r1, [r0, #0x50]
 *   @0x2f8f76 it eq
 *   @0x2f8f78 moveq r1, r2
 *   @0x2f8f7a str r4, [r0, #0x44]
 *   @0x2f8f7c add r4, r3
 *   @0x2f8f7e it ne
 *   @0x2f8f80 addne.w r1, r3, r3, lsr #31
 *   @0x2f8f84 str r4, [r0, #0x4c]
 *   @0x2f8f86 ldr r4, [r0, #0x30]
 *   @0x2f8f88 it ne
 *   @0x2f8f8a asrne r1, r1, #0x1
 *   @0x2f8f8c str.w r1, [r0, #0xb4]
 *   @0x2f8f90 ldr.w r1, [r0, #0xac]
 *   @0x2f8f94 add r1, r4
 *   @0x2f8f96 str.w r1, [r0, #0xb8]
 *   @0x2f8f9a cbz r2, 0x2f8fa2 <ps_hints_apply+0x7ba2>
 *   @0x2f8f9c add.w r3, r3, r3, lsr #31
 *   @0x2f8fa0 asrs r2, r3, #0x1
 *   @0x2f8fa2 ldr.w r3, [r0, #0xb0]
 *   @0x2f8fa6 str.w r2, [r0, #0xbc]
 *   @0x2f8faa subs r1, r1, r3
 *   @0x2f8fac str.w r1, [r0, #0xc0]
 *   @0x2f8fb0 pop {r4, pc}
 *   @0x2f8fb2 movs r0, r0
 *   @0x2f8fb4 ldr r3, [pc, #0x27c]
 *   @0x2f8fb6 cmp r1, r3
 *   @0x2f8fb8 beq.w 0x2f91e8 <ps_hints_apply+0x7de8>
 *   @0x2f8fbc bhi 0x2f9064 <ps_hints_apply+0x7c64>
 *   @0x2f8fbe ldr r3, [pc, #0x278]
 *   @0x2f8fc0 cmp r1, r3
 *   @0x2f8fc2 beq.w 0x2f91a4 <ps_hints_apply+0x7da4>
 *   @0x2f8fc6 bhi 0x2f900a <ps_hints_apply+0x7c0a>
 *   @0x2f8fc8 subs r3, #0x5
 *   @0x2f8fca cmp r1, r3
 *   @0x2f8fcc beq.w 0x2f9154 <ps_hints_apply+0x7d54>
 *   @0x2f8fd0 bhi 0x2f8fec <ps_hints_apply+0x7bec>
 *   @0x2f8fd2 subs r3, #0x2
 *   @0x2f8fd4 cmp r1, r3
 *   @0x2f8fd6 beq.w 0x2f9136 <ps_hints_apply+0x7d36>
 *   @0x2f8fda bhi.w 0x2f9144 <ps_hints_apply+0x7d44>
 *   @0x2f8fde ldr r3, [pc, #0x25c]
 *   @0x2f8fe0 cmp r1, r3
 *   @0x2f8fe2 bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f8fe6 add.w r0, r0, #0x1ce
 *   @0x2f8fea bx lr
 *   @0x2f8fec ldr r3, [pc, #0x250]
 *   @0x2f8fee cmp r1, r3
 *   @0x2f8ff0 beq.w 0x2f9174 <ps_hints_apply+0x7d74>
 *   @0x2f8ff4 blo.w 0x2f9164 <ps_hints_apply+0x7d64>
 *   @0x2f8ff8 adds r3, #0x1
 *   @0x2f8ffa cmp r1, r3
 *   @0x2f8ffc beq.w 0x2f9184 <ps_hints_apply+0x7d84>
 *   @0x2f9000 adds r3, #0x1
 *   @0x2f9002 cmp r1, r3
 *   @0x2f9004 beq.w 0x2f9194 <ps_hints_apply+0x7d94>
 *   @0x2f9008 b 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f900a ldr r3, [pc, #0x238]
 *   @0x2f900c cmp r1, r3
 *   @0x2f900e beq.w 0x2f91da <ps_hints_apply+0x7dda>
 *   @0x2f9012 bhi 0x2f9036 <ps_hints_apply+0x7c36>
 *   @0x2f9014 ldr r3, [pc, #0x230]
 *   @0x2f9016 cmp r1, r3
 *   @0x2f9018 beq.w 0x2f91c4 <ps_hints_apply+0x7dc4>
 *   @0x2f901c blo.w 0x2f91b4 <ps_hints_apply+0x7db4>
 *   @0x2f9020 ldr r3, [pc, #0x228]
 *   @0x2f9022 cmp r1, r3
 *   @0x2f9024 beq.w 0x2f91d4 <ps_hints_apply+0x7dd4>
 *   @0x2f9028 ldr r3, [pc, #0x224]
 *   @0x2f902a cmp r1, r3
 *   @0x2f902c bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f9030 add.w r0, r0, #0x1c0
 *   @0x2f9034 bx lr
 *   @0x2f9036 ldr r3, [pc, #0x21c]
 *   @0x2f9038 cmp r1, r3
 *   @0x2f903a beq.w 0x2f91e0 <ps_hints_apply+0x7de0>
 *   @0x2f903e bhi 0x2f904e <ps_hints_apply+0x7c4e>
 *   @0x2f9040 sub.w r3, r3, #0x308
 *   @0x2f9044 cmp r1, r3
 *   @0x2f9046 bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f904a adds r0, #0xee
 *   @0x2f904c bx lr
 *   @0x2f904e ldr r3, [pc, #0x208]
 *   @0x2f9050 cmp r1, r3
 *   @0x2f9052 beq.w 0x2f91e4 <ps_hints_apply+0x7de4>
 *   @0x2f9056 ldr r3, [pc, #0x204]
 *   @0x2f9058 cmp r1, r3
 *   @0x2f905a bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f905e add.w r0, r0, #0x1bc
 *   @0x2f9062 bx lr
 *   @0x2f9064 ldr r3, [pc, #0x1f8]
 *   @0x2f9066 cmp r1, r3
 *   @0x2f9068 beq.w 0x2f920c <ps_hints_apply+0x7e0c>
 *   @0x2f906c bhi 0x2f90d4 <ps_hints_apply+0x7cd4>
 *   @0x2f906e ldr r3, [pc, #0x1f4]
 *   @0x2f9070 cmp r1, r3
 *   @0x2f9072 beq.w 0x2f91fa <ps_hints_apply+0x7dfa>
 *   @0x2f9076 bhi 0x2f90a6 <ps_hints_apply+0x7ca6>
 *   @0x2f9078 ldr r3, [pc, #0x1ec]
 *   @0x2f907a cmp r1, r3
 *   @0x2f907c beq.w 0x2f91ee <ps_hints_apply+0x7dee>
 *   @0x2f9080 bhi 0x2f9090 <ps_hints_apply+0x7c90>
 *   @0x2f9082 subs r3, #0x4
 *   @0x2f9084 cmp r1, r3
 *   @0x2f9086 bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f908a add.w r0, r0, #0x182
 *   @0x2f908e bx lr
 *   @0x2f9090 ldr r3, [pc, #0x1d8]
 *   @0x2f9092 cmp r1, r3
 *   @0x2f9094 beq.w 0x2f91f4 <ps_hints_apply+0x7df4>
 *   @0x2f9098 adds r3, #0x4
 *   @0x2f909a cmp r1, r3
 *   @0x2f909c bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f90a0 add.w r0, r0, #0x180
 *   @0x2f90a4 bx lr
 *   @0x2f90a6 ldr r3, [pc, #0x1c8]
 *   @0x2f90a8 cmp r1, r3
 *   @0x2f90aa beq.w 0x2f9200 <ps_hints_apply+0x7e00>
 *   @0x2f90ae bhi 0x2f90be <ps_hints_apply+0x7cbe>
 *   @0x2f90b0 subs r3, #0xfc
 *   @0x2f90b2 cmp r1, r3
 *   @0x2f90b4 bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f90b8 add.w r0, r0, #0x186
 *   @0x2f90bc bx lr
 *   @0x2f90be ldr r3, [pc, #0x1b4]
 *   @0x2f90c0 cmp r1, r3
 *   @0x2f90c2 beq.w 0x2f9206 <ps_hints_apply+0x7e06>
 *   @0x2f90c6 ldr r3, [pc, #0x1b0]
 *   @0x2f90c8 cmp r1, r3
 *   @0x2f90ca bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f90ce add.w r0, r0, #0x190
 *   @0x2f90d2 bx lr
 *   @0x2f90d4 ldr r3, [pc, #0x1a4]
 *   @0x2f90d6 cmp r1, r3
 *   @0x2f90d8 beq.w 0x2f921e <ps_hints_apply+0x7e1e>
 *   @0x2f90dc bhi 0x2f910c <ps_hints_apply+0x7d0c>
 *   @0x2f90de ldr r3, [pc, #0x1a0]
 *   @0x2f90e0 cmp r1, r3
 *   @0x2f90e2 beq.w 0x2f9212 <ps_hints_apply+0x7e12>
 *   @0x2f90e6 bhi 0x2f90f6 <ps_hints_apply+0x7cf6>
 *   @0x2f90e8 subs r3, #0x4
 *   @0x2f90ea cmp r1, r3
 *   @0x2f90ec bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f90f0 add.w r0, r0, #0x1e4
 *   @0x2f90f4 bx lr
 *   @0x2f90f6 ldr r3, [pc, #0x18c]
 *   @0x2f90f8 cmp r1, r3
 *   @0x2f90fa beq.w 0x2f9218 <ps_hints_apply+0x7e18>
 *   @0x2f90fe ldr r3, [pc, #0x188]
 *   @0x2f9100 cmp r1, r3
 *   @0x2f9102 bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f9106 add.w r0, r0, #0x13e
 *   @0x2f910a bx lr
 *   @0x2f910c ldr r3, [pc, #0x17c]
 *   @0x2f910e cmp r1, r3
 *   @0x2f9110 beq.w 0x2f9224 <ps_hints_apply+0x7e24>
 *   @0x2f9114 bhi 0x2f9124 <ps_hints_apply+0x7d24>
 *   @0x2f9116 ldr r3, [pc, #0x178]
 *   @0x2f9118 cmp r1, r3
 *   @0x2f911a bne.w 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f911e add.w r0, r0, #0x13a
 *   @0x2f9122 bx lr
 *   @0x2f9124 ldr r3, [pc, #0x16c]
 *   @0x2f9126 cmp r1, r3
 *   @0x2f9128 beq 0x2f922a <ps_hints_apply+0x7e2a>
 *   @0x2f912a ldr r3, [pc, #0x16c]
 *   @0x2f912c cmp r1, r3
 *   @0x2f912e bne 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f9130 add.w r0, r0, #0x1cc
 *   @0x2f9134 bx lr
 *   @0x2f9136 ldrh.w r3, [r0, #0x22e]
 *   @0x2f913a cmp r3, #0x1
 *   @0x2f913c ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f913e ldr.w r0, [r0, #0x230]
 *   @0x2f9142 bx lr
 *   @0x2f9144 ldrh.w r3, [r0, #0x22e]
 *   @0x2f9148 cmp r3, #0x2
 *   @0x2f914a ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f914c ldr.w r0, [r0, #0x230]
 *   @0x2f9150 adds r0, #0x4
 *   @0x2f9152 bx lr
 *   @0x2f9154 ldrh.w r3, [r0, #0x22e]
 *   @0x2f9158 cmp r3, #0x3
 *   @0x2f915a ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f915c ldr.w r0, [r0, #0x230]
 *   @0x2f9160 adds r0, #0x8
 *   @0x2f9162 bx lr
 *   @0x2f9164 ldrh.w r3, [r0, #0x22e]
 *   @0x2f9168 cmp r3, #0x4
 *   @0x2f916a ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f916c ldr.w r0, [r0, #0x230]
 *   @0x2f9170 adds r0, #0xc
 *   @0x2f9172 bx lr
 *   @0x2f9174 ldrh.w r3, [r0, #0x22e]
 *   @0x2f9178 cmp r3, #0x5
 *   @0x2f917a ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f917c ldr.w r0, [r0, #0x230]
 *   @0x2f9180 adds r0, #0x10
 *   @0x2f9182 bx lr
 *   @0x2f9184 ldrh.w r3, [r0, #0x22e]
 *   @0x2f9188 cmp r3, #0x6
 *   @0x2f918a ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f918c ldr.w r0, [r0, #0x230]
 *   @0x2f9190 adds r0, #0x14
 *   @0x2f9192 bx lr
 *   @0x2f9194 ldrh.w r3, [r0, #0x22e]
 *   @0x2f9198 cmp r3, #0x7
 *   @0x2f919a ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f919c ldr.w r0, [r0, #0x230]
 *   @0x2f91a0 adds r0, #0x18
 *   @0x2f91a2 bx lr
 *   @0x2f91a4 ldrh.w r3, [r0, #0x22e]
 *   @0x2f91a8 cmp r3, #0x8
 *   @0x2f91aa ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f91ac ldr.w r0, [r0, #0x230]
 *   @0x2f91b0 adds r0, #0x1c
 *   @0x2f91b2 bx lr
 *   @0x2f91b4 ldrh.w r3, [r0, #0x22e]
 *   @0x2f91b8 cmp r3, #0x9
 *   @0x2f91ba ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f91bc ldr.w r0, [r0, #0x230]
 *   @0x2f91c0 adds r0, #0x20
 *   @0x2f91c2 bx lr
 *   @0x2f91c4 ldrh.w r3, [r0, #0x22e]
 *   @0x2f91c8 cmp r3, #0xa
 *   @0x2f91ca ble 0x2f9230 <ps_hints_apply+0x7e30>
 *   @0x2f91cc ldr.w r0, [r0, #0x230]
 *   @0x2f91d0 adds r0, #0x24
 *   @0x2f91d2 bx lr
 *   @0x2f91d4 add.w r0, r0, #0x1ba
 *   @0x2f91d8 bx lr
 *   @0x2f91da add.w r0, r0, #0x1c2
 *   @0x2f91de bx lr
 *   @0x2f91e0 adds r0, #0xec
 *   @0x2f91e2 bx lr
 *   @0x2f91e4 adds r0, #0xea
 *   @0x2f91e6 bx lr
 *   @0x2f91e8 add.w r0, r0, #0x1be
 *   @0x2f91ec bx lr
 *   @0x2f91ee add.w r0, r0, #0x17e
 *   @0x2f91f2 bx lr
 *   @0x2f91f4 add.w r0, r0, #0x184
 *   @0x2f91f8 bx lr
 *   @0x2f91fa add.w r0, r0, #0x18a
 *   @0x2f91fe bx lr
 *   @0x2f9200 add.w r0, r0, #0x18c
 *   @0x2f9204 bx lr
 *   @0x2f9206 add.w r0, r0, #0x188
 *   @0x2f920a bx lr
 *   @0x2f920c add.w r0, r0, #0x18e
 *   @0x2f9210 bx lr
 *   @0x2f9212 add.w r0, r0, #0x1e6
 *   @0x2f9216 bx lr
 *   @0x2f9218 add.w r0, r0, #0x12c
 *   @0x2f921c bx lr
 *   @0x2f921e add.w r0, r0, #0x13c
 *   @0x2f9222 bx lr
 *   @0x2f9224 add.w r0, r0, #0x12e
 *   @0x2f9228 bx lr
 *   @0x2f922a add.w r0, r0, #0x130
 *   @0x2f922e bx lr
 *   @0x2f9230 movs r0, #0x0
 *   @0x2f9232 bx lr
 *   @0x2f9234 str r0, [r6, #0x74]
 *   @0x2f9236 ldr r4, [r5, #0x4]
 *   @0x2f9238 strb r7, [r6]
 *   @0x2f923a str r3, [r6, #0x74]
 *   @0x2f923c ldr r4, [r6, #0x4]
 *   @0x2f923e str r0, [r6, #0x34]
 *   @0x2f9240 strb r4, [r6]
 *   @0x2f9242 str r3, [r6, #0x74]
 *   @0x2f9244 ldr r4, [r4, #0x44]
 *   @0x2f9246 ldr r3, [r4, #0x4]
 *   @0x2f9248 strb r1, [r7]
 *   @0x2f924a str r3, [r6, #0x74]
 *   @0x2f924c strb r3, [r4, #0xd]
 *   @0x2f924e ldr r1, [r4, #0x4]
 *   @0x2f9250 ldr r1, [r4, #0x44]
 *   @0x2f9252 ldr r3, [r4, #0x4]
 *   @0x2f9254 strb r6, [r5, #0x9]
 *   @0x2f9256 ldr r3, [r4, #0x4]
 *   @0x2f9258 strb r3, [r6, #0x9]
 *   @0x2f925a ldr r3, [r4, #0x4]
 *   @0x2f925c strb r3, [r4, #0xd]
 *   @0x2f925e ldr r4, [r4, #0x4]
 *   @0x2f9260 strb r3, [r6, #0x9]
 *   @0x2f9262 strb r4, [r6, #0xd]
 *   @0x2f9264 ldrb r7, [r5, #0x1]
 *   @0x2f9266 strb r0, [r6, #0xd]
 *   @0x2f9268 ldrb r3, [r6, #0x1]
 *   @0x2f926a strb r2, [r4, #0xd]
 *   @0x2f926c ldrb r7, [r5, #0x5]
 *   @0x2f926e strb r2, [r4, #0xd]
 *   @0x2f9270 ldrb r7, [r5, #0x5]
 *   @0x2f9272 strb r0, [r6, #0xd]
 *   @0x2f9274 ldrb r3, [r6, #0x5]
 *   @0x2f9276 strb r0, [r6, #0xd]
 *   @0x2f9278 strb r7, [r5, #0x9]
 *   @0x2f927a strb r4, [r6, #0xd]
 *   @0x2f927c strb r6, [r5, #0x9]
 *   @0x2f927e strb r3, [r4, #0x19]
 *   @0x2f9280 str r3, [r6, #0x44]
 *   @0x2f9282 strb r6, [r5, #0x15]
 *   @0x2f9284 strb r3, [r4, #0xd]
 *   @0x2f9286 strb r1, [r4, #0x19]
 *   @0x2f9288 ldr r6, [r4, #0x74]
 *   @0x2f928a strb r3, [r4, #0x19]
 *   @0x2f928c strb r3, [r4, #0xd]
 *   @0x2f928e strb r4, [r4, #0x19]
 *   @0x2f9290 strb r3, [r6, #0x9]
 *   @0x2f9292 strb r3, [r4, #0x19]
 *   @0x2f9294 str r0, [r6, #0x74]
 *   @0x2f9296 strb r4, [r5, #0x19]
 *   @0x2f9298 str r4, [r6, #0x74]
 *   @0x2f929a ldrb r0, [r5, #0x1]
/* ═══════════════════════════════════════════════════════════════════════
 * §2  anon_thumb_317798   0x317798..0x317a44   684 B / 281 条   in-degree 7
 * C++ 展开/cleanup 运行时（libsupc++），夹在 libpng LZW 与 __gxx_personality_v0 之间
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 7 条 Thumb `bl` 指向本段起始：__cxa_call_unexpected×5 / anon_317210 区×1 / anon_3180e8 区×1；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 2 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push {r3, r4, r5, lr} / bl 0x317604 <ft_lzwstate_io+0x650> / ldr r1, [r0]（帧：push {r3, r4, r5, lr}）；窗口内出口 15 个
 * 结构：入口可达 120 B / 45 条（17%）；段内 bl 入口 2 个：0x31788c(206 B/88 条) / 0x317968(208 B/85 条)
 *      可打印岛：无 ≥16 B 的
 * 段内 3 个 bl 入口：0x317798（120 B / 45 条）、0x31788c（206 B / 88 条）、0x317968（208 B / 85 条）。
 *      入口被 __cxa_call_unexpected bl 5 次；自己 bl 到 __cxa_end_cleanup 与 __cxa_call_unexpected，
 *      另有 3 处落进 0x317604 / 0x3174e0 / 0x317adc —— 那三个地址在 ft_lzwstate_io(0x316fb4,602 B) 之内，
 *      是 libpng 的 LZW 解码器，objdump 借名不代表同库。
 *
 * 锚点：281 条（= asm/index-anonT_317798.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x317798 push {r3, r4, r5, lr}
 *   @0x31779a bl 0x317604 <ft_lzwstate_io+0x650>
 *   @0x31779e ldr r1, [r0]
 *   @0x3177a0 cbz r1, 0x3177c4 <ft_lzwstate_io+0x810>
 *   @0x3177a2 ldrd r4, r5, [r1, #56]
 *   @0x3177a6 adr r3, #96 <ft_lzwstate_io+0x80e>
 *   @0x3177a8 ldrd r2, r3, [r3]
 *   @0x3177ac eors r2, r4
 *   @0x3177ae eors r3, r5
 *   @0x3177b0 orrs.w r4, r2, r3
 *   @0x3177b4 beq 0x3177c6 <ft_lzwstate_io+0x812>
 *   @0x3177b6 adds r1, #0x38
 *   @0x3177b8 movs r3, #0x0
 *   @0x3177ba str r3, [r0]
 *   @0x3177bc mov r0, r1
 *   @0x3177be blx 0x319bc4 <_Unwind_DeleteException>
 *   @0x3177c2 pop {r3, r4, r5, pc}
 *   @0x3177c4 pop {r3, r4, r5, pc}
 *   @0x3177c6 ldr r3, [r1, #0x18]
 *   @0x3177c8 cmp r3, #0x0
 *   @0x3177ca blt 0x3177d8 <ft_lzwstate_io+0x824>
 *   @0x3177cc subs r3, #0x1
 *   @0x3177ce beq 0x3177e2 <ft_lzwstate_io+0x82e>
 *   @0x3177d0 adds r2, r3, #0x1
 *   @0x3177d2 beq 0x3177f2 <ft_lzwstate_io+0x83e>
 *   @0x3177d4 str r3, [r1, #0x18]
 *   @0x3177d6 pop {r3, r4, r5, pc}
 *   @0x3177d8 adds r3, #0x1
 *   @0x3177da bne 0x3177d4 <ft_lzwstate_io+0x820>
 *   @0x3177dc ldr r2, [r1, #0x14]
 *   @0x3177de str r2, [r0]
 *   @0x3177e0 b 0x3177d4 <ft_lzwstate_io+0x820>
 *   @0x3177e2 ldr r3, [r1, #0x14]
 *   @0x3177e4 adds r1, #0x90
 *   @0x3177e6 str r3, [r0]
 *   @0x3177e8 mov r0, r1
 *   @0x3177ea pop.w {r3, r4, r5, lr}
 *   @0x3177ee b.w 0x317658 <ft_lzwstate_io+0x6a4>
 *   @0x3177f2 ldr r0, [pc, #0x1c]
 *   @0x3177f4 add r0, pc
 *   @0x3177f6 bl 0x317adc <ft_lzwstate_io+0xb28>
 *   @0x3177fa adds r1, #0x1
 *   @0x3177fc beq 0x317802 <ft_lzwstate_io+0x84e>
 *   @0x3177fe bl 0x3185a4 <__cxa_end_cleanup>
 *   @0x317802 bl 0x3186c8 <__cxa_call_unexpected>
 *   @0x317806 nop
 *   @0x317808 cmp r3, #0x0
 *   @0x31780a orrs r3, r5
 *   @0x31780c strb r3, [r0, r5]
 *   @0x31780e bx r9
 *   @0x317810 ldr r5, [pc, #0xb0]
 *   @0x317812 movs r4, r0
 *   @0x317814 nop.w
 *   @0x317818 ldr r0, [r0, #-4]
 *   @0x31781c bx lr
 *   @0x31781e nop
 *   @0x317820 push {r3, lr}
 *   @0x317822 bl 0x3174e0 <ft_lzwstate_io+0x52c>
 *   @0x317826 cbz r0, 0x317832 <ft_lzwstate_io+0x87e>
 *   @0x317828 ldr r0, [r0, #0x4]
 *   @0x31782a rsbs.w r0, r0, #0x1
 *   @0x31782e it lo
 *   @0x317830 movlo r0, #0x0
 *   @0x317832 pop {r3, pc}
 *   @0x317834 push {r4}
 *   @0x317836 cbz r0, 0x31785a <ft_lzwstate_io+0x8a6>
 *   @0x317838 sub.w r3, r0, #0x90
 *   @0x31783c mov.w r2, #0xffffffff
 *   @0x317840 dmb sy
 *   @0x317844 ldrex r1, [r3]
 *   @0x317848 add r1, r2
 *   @0x31784a strex r4, r1, [r3]
 *   @0x31784e teq.w r4, #0x0
 *   @0x317852 bne 0x317844 <ft_lzwstate_io+0x890>
 *   @0x317854 dmb sy
 *   @0x317858 cbz r1, 0x31785e <ft_lzwstate_io+0x8aa>
 *   @0x31785a pop {r4}
 *   @0x31785c bx lr
 *   @0x31785e pop {r4}
 *   @0x317860 b.w 0x317658 <ft_lzwstate_io+0x6a4>
 *   @0x317864 cbz r0, 0x317882 <ft_lzwstate_io+0x8ce>
 *   @0x317866 subs r0, #0x90
 *   @0x317868 movs r3, #0x1
 *   @0x31786a dmb sy
 *   @0x31786e ldrex r2, [r0]
 *   @0x317872 add r2, r3
 *   @0x317874 strex r1, r2, [r0]
 *   @0x317878 teq.w r1, #0x0
 *   @0x31787c bne 0x31786e <ft_lzwstate_io+0x8ba>
 *   @0x31787e dmb sy
 *   @0x317882 bx lr
 *   @0x317884 bx lr
 *   @0x317886 nop
 *   @0x317888 movs r0, #0x0
 *   @0x31788a bx lr
 *   @0x31788c push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x317890 mov r7, r0
 *   @0x317892 mov r5, r1
 *   @0x317894 mov r10, r2
 *   @0x317896 mov r9, r3
 *   @0x317898 mov r1, r9
 *   @0x31789a mov r0, r5
 *   @0x31789c bl 0x318368 <__gxx_personality_v0+0x3e8>
 *   @0x3178a0 mov r4, r0
 *   @0x3178a2 mov r0, r5
 *   @0x3178a4 cmp r4, #0x0
 *   @0x3178a6 bne 0x31793a <ft_lzwstate_io+0x986>
 *   @0x3178a8 ldr r3, [r5]
 *   @0x3178aa ldr r3, [r3, #0xc]
 *   @0x3178ac blx r3
 *   @0x3178ae cmp r0, #0x1
 *   @0x3178b0 beq 0x317930 <ft_lzwstate_io+0x97c>
 *   @0x3178b2 cmp r0, #0x2
 *   @0x3178b4 beq 0x3178da <ft_lzwstate_io+0x926>
 *   @0x3178b6 cbnz r0, 0x3178c0 <ft_lzwstate_io+0x90c>
 *   @0x3178b8 mov r7, r0
 *   @0x3178ba mov r0, r7
 *   @0x3178bc pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x3178c0 ldr r0, [pc, #0x98]
 *   @0x3178c2 movs r1, #0xad
 *   @0x3178c4 ldr r2, [pc, #0x98]
 *   @0x3178c6 mov r7, r4
 *   @0x3178c8 ldr r3, [pc, #0x98]
 *   @0x3178ca add r0, pc
 *   @0x3178cc add r2, pc
 *   @0x3178ce add r3, pc
 *   @0x3178d0 blx 0xb6fac <__assert2@plt>
 *   @0x3178d4 mov r0, r7
 *   @0x3178d6 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x3178da ldr r2, [r5, #0xc]
 *   @0x3178dc ldr.w r11, [r7]
 *   @0x3178e0 cmp r2, #0x0
 *   @0x3178e2 beq 0x317956 <ft_lzwstate_io+0x9a2>
 *   @0x3178e4 mov r6, r5
 *   @0x3178e6 mov r8, r4
 *   @0x3178e8 add.w r3, r5, r4, lsl #3
 *   @0x3178ec ldr r3, [r3, #0x14]
 *   @0x3178ee lsls r1, r3, #0x1e
 *   @0x3178f0 bpl 0x31791a <ft_lzwstate_io+0x966>
 *   @0x3178f2 asrs r0, r3, #0x8
 *   @0x3178f4 lsls r2, r3, #0x1f
 *   @0x3178f6 ldr r1, [r6, #0x10]
 *   @0x3178f8 mov r3, r9
 *   @0x3178fa it mi
 *   @0x3178fc ldrmi.w r0, [r11, r0]
 *   @0x317900 mov r2, r10
 *   @0x317902 adds r0, r7, r0
 *   @0x317904 bl 0x31788c <ft_lzwstate_io+0x8d8>
 *   @0x317908 adds r3, r0, #0x1
 *   @0x31790a beq 0x3178b8 <ft_lzwstate_io+0x904>
 *   @0x31790c cbz r0, 0x317918 <ft_lzwstate_io+0x964>
 *   @0x31790e cmp.w r8, #0x0
 *   @0x317912 beq 0x31792a <ft_lzwstate_io+0x976>
 *   @0x317914 cmp r8, r0
 *   @0x317916 bne 0x317934 <ft_lzwstate_io+0x980>
 *   @0x317918 ldr r2, [r5, #0xc]
 *   @0x31791a adds r4, #0x1
 *   @0x31791c adds r6, #0x8
 *   @0x31791e cmp r2, r4
 *   @0x317920 bhi 0x3178e8 <ft_lzwstate_io+0x934>
 *   @0x317922 mov r7, r8
 *   @0x317924 mov r0, r7
 *   @0x317926 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x31792a ldr r2, [r5, #0xc]
 *   @0x31792c mov r8, r0
 *   @0x31792e b 0x31791a <ft_lzwstate_io+0x966>
 *   @0x317930 ldr r5, [r5, #0x8]
 *   @0x317932 b 0x317898 <ft_lzwstate_io+0x8e4>
 *   @0x317934 mov.w r7, #0xffffffff
 *   @0x317938 b 0x3178ba <ft_lzwstate_io+0x906>
 *   @0x31793a rsbs.w r3, r10, #0x1
 *   @0x31793e it lo
 *   @0x317940 movlo r3, #0x0
 *   @0x317942 cmp r10, r7
 *   @0x317944 ite ne
 *   @0x317946 movne r10, r3
 *   @0x317948 orreq r10, r3, #0x1
 *   @0x31794c cmp.w r10, #0x0
 *   @0x317950 it eq
 *   @0x317952 moveq r7, #0x0
 *   @0x317954 b 0x3178ba <ft_lzwstate_io+0x906>
 *   @0x317956 mov r7, r2
 *   @0x317958 b 0x3178ba <ft_lzwstate_io+0x906>
 *   @0x31795a nop
 *   @0x31795c ldr r4, [pc, #0x2b8]
 *   @0x31795e movs r4, r0
 *   @0x317960 blt 0x3179dc <ft_lzwstate_io+0xa28>
 *   @0x317962 movs r0, r1
 *   @0x317964 add r4, sp, #0x88
 *   @0x317966 movs r1, r0
 *   @0x317968 push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x31796c mov r6, r1
 *   @0x31796e mov r8, r0
 *   @0x317970 ldr r1, [r2, #0x8]
 *   @0x317972 mov r0, r6
 *   @0x317974 mov r4, r2
 *   @0x317976 ldr r5, [r2, #0x10]
 *   @0x317978 bl 0x318368 <__gxx_personality_v0+0x3e8>
 *   @0x31797c cbz r0, 0x317982 <ft_lzwstate_io+0x9ce>
 *   @0x31797e str.w r8, [r4, #0x10]
 *   @0x317982 ldr r3, [r4]
 *   @0x317984 cmp r8, r3
 *   @0x317986 beq 0x3179fa <ft_lzwstate_io+0xa46>
 *   @0x317988 ldr r3, [r6]
 *   @0x31798a mov r0, r6
 *   @0x31798c ldr r3, [r3, #0xc]
 *   @0x31798e blx r3
 *   @0x317990 cmp r0, #0x1
 *   @0x317992 beq 0x317a2c <ft_lzwstate_io+0xa78>
 *   @0x317994 cmp r0, #0x2
 *   @0x317996 beq 0x3179b4 <ft_lzwstate_io+0xa00>
 *   @0x317998 cbz r0, 0x3179ae <ft_lzwstate_io+0x9fa>
 *   @0x31799a ldr r0, [pc, #0x9c]
 *   @0x31799c movw r1, #0x105
 *   @0x3179a0 ldr r2, [pc, #0x98]
 *   @0x3179a2 ldr r3, [pc, #0x9c]
 *   @0x3179a4 add r0, pc
 *   @0x3179a6 add r2, pc
 *   @0x3179a8 add r3, pc
 *   @0x3179aa blx 0xb6fac <__assert2@plt>
 *   @0x3179ae str r5, [r4, #0x10]
 *   @0x3179b0 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x3179b4 ldr r1, [r6, #0xc]
 *   @0x3179b6 ldr.w r10, [r8]
 *   @0x3179ba cmp r1, #0x0
 *   @0x3179bc beq 0x3179ae <ft_lzwstate_io+0x9fa>
 *   @0x3179be movs r7, #0x0
 *   @0x3179c0 mov r9, r6
 *   @0x3179c2 add.w r3, r6, r7, lsl #3
 *   @0x3179c6 adds r7, #0x1
 *   @0x3179c8 mov r2, r4
 *   @0x3179ca ldr r3, [r3, #0x14]
 *   @0x3179cc tst.w r3, #0x2
 *   @0x3179d0 asr.w r0, r3, #0x8
 *   @0x3179d4 beq 0x3179f0 <ft_lzwstate_io+0xa3c>
 *   @0x3179d6 lsls r3, r3, #0x1f
 *   @0x3179d8 ldr.w r1, [r9, #0x10]
 *   @0x3179dc it mi
 *   @0x3179de ldrmi.w r0, [r10, r0]
 *   @0x3179e2 add r0, r8
 *   @0x3179e4 bl 0x317968 <ft_lzwstate_io+0x9b4>
 *   @0x3179e8 ldr r3, [r4, #0x14]
 *   @0x3179ea adds r3, #0x1
 *   @0x3179ec beq 0x3179ae <ft_lzwstate_io+0x9fa>
 *   @0x3179ee ldr r1, [r6, #0xc]
 *   @0x3179f0 cmp r7, r1
 *   @0x3179f2 add.w r9, r9, #0x8
 *   @0x3179f6 blo 0x3179c2 <ft_lzwstate_io+0xa0e>
 *   @0x3179f8 b 0x3179ae <ft_lzwstate_io+0x9fa>
 *   @0x3179fa ldr r3, [r4, #0x10]
 *   @0x3179fc cmp r3, #0x0
 *   @0x3179fe beq 0x317988 <ft_lzwstate_io+0x9d4>
 *   @0x317a00 ldr r1, [r4, #0x4]
 *   @0x317a02 mov r0, r6
 *   @0x317a04 bl 0x318368 <__gxx_personality_v0+0x3e8>
 *   @0x317a08 cmp r0, #0x0
 *   @0x317a0a beq 0x317988 <ft_lzwstate_io+0x9d4>
 *   @0x317a0c ldr r2, [r4, #0x14]
 *   @0x317a0e cbz r2, 0x317a22 <ft_lzwstate_io+0xa6e>
 *   @0x317a10 ldr r3, [r4, #0x10]
 *   @0x317a12 str r5, [r4, #0x10]
 *   @0x317a14 cmp r2, r3
 *   @0x317a16 itt ne
 *   @0x317a18 movne.w r3, #0xffffffff
 *   @0x317a1c strne r3, [r4, #0x14]
 *   @0x317a1e pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x317a22 ldr r3, [r4, #0x10]
 *   @0x317a24 str r5, [r4, #0x10]
 *   @0x317a26 str r3, [r4, #0x14]
 *   @0x317a28 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x317a2c ldr r1, [r6, #0x8]
 *   @0x317a2e mov r0, r8
 *   @0x317a30 mov r2, r4
 *   @0x317a32 bl 0x317968 <ft_lzwstate_io+0x9b4>
 *   @0x317a36 b 0x3179ae <ft_lzwstate_io+0x9fa>
 *   @0x317a38 ldr r3, [pc, #0x350]
 *   @0x317a3a movs r4, r0
 *   @0x317a3c bge 0x317a34 <ft_lzwstate_io+0xa80>
 *   @0x317a3e movs r0, r1
 *   @0x317a40 add r3, sp, #0x120
 *   @0x317a42 movs r1, r0
/* ═══════════════════════════════════════════════════════════════════════
 * §3  anon_thumb_2e8c38   0x2e8c38..0x2e90d4   1,180 B / 483 条   in-degree 4
 * FreeType ftobjs.c 的 open_face（narrowed）—— 本批唯一 100% 单函数段
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 4 条 Thumb `bl` 指向本段起始：FT_New_Face×1 / FT_New_Memory_Face×1 / FT_Open_Face×1 / anon_2e90fc 区×1；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 16 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} / sub sp, #0x15c / mov r7, r2（帧：sub sp, 0x15c）；窗口内出口 1 个（唯一出口 0x2e90c6）
 * 结构：入口可达 1170 B / 478 条（99%）；段内 bl 入口 0 个：无（本段只有入口函数）
 *      可打印岛：无 ≥16 B 的
 * 1,180 B 里 478 条入口可达（0x2e8c38..0x2e90ca = 1,170 B，99%），全段只有 1 个出口（0x2e90cc 的
 *      pop.w {r4-r11, pc}），零 bl 入口。调用面 16 处具名 Thumb：FT_Stream_New/Seek/Read/Free、
 *      ft_mem_alloc/free、FT_New_GlyphSlot、FT_Raccess_Guess…；反向被 FT_New_Face / FT_New_Memory_Face /
 *      FT_Open_Face 各 bl 1 次 —— 与 ftobjs.c 里 static open_face 的三个调用者逐一对应。
 *
 * 锚点：483 条（= asm/index-anonT_2e8c38.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2e8c38 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e8c3c sub sp, #0x15c
 *   @0x2e8c3e mov r7, r2
 *   @0x2e8c40 ldr.w r2, [pc, #0x488]
 *   @0x2e8c44 mov r4, r1
 *   @0x2e8c46 ldrb.w r1, [sp, #0x180]
 *   @0x2e8c4a add r2, pc
 *   @0x2e8c4c ldr r2, [r2]
 *   @0x2e8c4e add.w r8, sp, #0x3c
 *   @0x2e8c52 add.w r9, sp, #0x40
 *   @0x2e8c56 mov r5, r0
 *   @0x2e8c58 str r1, [sp, #0x1c]
 *   @0x2e8c5a ldr r1, [r2]
 *   @0x2e8c5c str r3, [sp, #0x14]
 *   @0x2e8c5e str r2, [sp, #0x30]
 *   @0x2e8c60 str r1, [sp, #0x154]
 *   @0x2e8c62 movs r1, #0x0
 *   @0x2e8c64 str.w r1, [r8]
 *   @0x2e8c68 str.w r1, [r9]
 *   @0x2e8c6c cbnz r3, 0x2e8c74 <FT_Done_Face+0x98>
 *   @0x2e8c6e cmp r7, r1
 *   @0x2e8c70 bge.w 0x2e90b4 <FT_Done_Face+0x4d8>
 *   @0x2e8c74 cmp r4, #0x0
 *   @0x2e8c76 beq.w 0x2e90b4 <FT_Done_Face+0x4d8>
 *   @0x2e8c7a ldr r3, [r4]
 *   @0x2e8c7c ands r3, r3, #0x2
 *   @0x2e8c80 beq 0x2e8c90 <FT_Done_Face+0xb4>
 *   @0x2e8c82 ldr r3, [r4, #0x10]
 *   @0x2e8c84 adds.w r11, r3, #0x0
 *   @0x2e8c88 it ne
 *   @0x2e8c8a movne.w r11, #0x1
 *   @0x2e8c8e b 0x2e8c92 <FT_Done_Face+0xb6>
 *   @0x2e8c90 mov r11, r3
 *   @0x2e8c92 mov r0, r5
 *   @0x2e8c94 mov r1, r4
 *   @0x2e8c96 mov r2, r8
 *   @0x2e8c98 bl 0x2e73dc <FT_Stream_New>
 *   @0x2e8c9c add r3, sp, #0x38
 *   @0x2e8c9e str r0, [r3]
 *   @0x2e8ca0 cmp r0, #0x0
 *   @0x2e8ca2 bne.w 0x2e8db2 <FT_Done_Face+0x1d6>
 *   @0x2e8ca6 uxtb.w r2, r11
 *   @0x2e8caa str r2, [sp, #0x18]
 *   @0x2e8cac ldr r2, [r4]
 *   @0x2e8cae ldr r1, [r5]
 *   @0x2e8cb0 lsls r6, r2, #0x1c
 *   @0x2e8cb2 str r1, [sp, #0x20]
 *   @0x2e8cb4 bpl 0x2e8cf2 <FT_Done_Face+0x116>
 *   @0x2e8cb6 ldr r6, [r4, #0x14]
 *   @0x2e8cb8 cbz r6, 0x2e8cf2 <FT_Done_Face+0x116>
 *   @0x2e8cba ldr r1, [r6]
 *   @0x2e8cbc ldr r1, [r1]
 *   @0x2e8cbe lsls r5, r1, #0x1f
 *   @0x2e8cc0 bpl 0x2e8ce8 <FT_Done_Face+0x10c>
 *   @0x2e8cc2 ands r3, r2, #0x10
 *   @0x2e8cc6 mov r0, r6
 *   @0x2e8cc8 mov r1, r8
 *   @0x2e8cca itet ne
 *   @0x2e8ccc ldrne r2, [r4, #0x18]
 *   @0x2e8cce moveq r2, r3
 *   @0x2e8cd0 ldrne r3, [r4, #0x1c]
 *   @0x2e8cd2 stm.w sp, {r2, r3, r9}
 *   @0x2e8cd6 mov r3, r7
 *   @0x2e8cd8 ldr r2, [sp, #0x18]
 *   @0x2e8cda bl 0x2e7bb0 <FT_Done_GlyphSlot+0x96>
 *   @0x2e8cde str r0, [sp, #0x38]
 *   @0x2e8ce0 cmp r0, #0x0
 *   @0x2e8ce2 beq.w 0x2e8fa8 <FT_Done_Face+0x3cc>
 *   @0x2e8ce6 b 0x2e8cec <FT_Done_Face+0x110>
 *   @0x2e8ce8 movs r2, #0x20
 *   @0x2e8cea str r2, [r3]
 *   @0x2e8cec ldr.w r0, [r8]
 *   @0x2e8cf0 b 0x2e8fa0 <FT_Done_Face+0x3c4>
 *   @0x2e8cf2 movs r2, #0xb
 *   @0x2e8cf4 str r2, [r3]
 *   @0x2e8cf6 ldr r3, [r5, #0x10]
 *   @0x2e8cf8 add.w r8, r5, #0x14
 *   @0x2e8cfc ldr r1, [pc, #0x3d0]
 *   @0x2e8cfe add.w r9, sp, #0x3c
 *   @0x2e8d02 add r2, sp, #0x40
 *   @0x2e8d04 str r2, [sp, #0x28]
 *   @0x2e8d06 add.w r3, r8, r3, lsl #2
 *   @0x2e8d0a str r3, [sp, #0x24]
 *   @0x2e8d0c movs r3, #0x0
 *   @0x2e8d0e add r1, pc
 *   @0x2e8d10 str r1, [sp, #0x2c]
 *   @0x2e8d12 ldr r2, [sp, #0x24]
 *   @0x2e8d14 cmp r8, r2
 *   @0x2e8d16 bhs 0x2e8db6 <FT_Done_Face+0x1da>
 *   @0x2e8d18 ldr r6, [r8], #4
 *   @0x2e8d1c ldr r2, [r6]
 *   @0x2e8d1e ldr r2, [r2]
 *   @0x2e8d20 lsls r0, r2, #0x1f
 *   @0x2e8d22 bpl 0x2e8d12 <FT_Done_Face+0x136>
 *   @0x2e8d24 ldr r3, [r4]
 *   @0x2e8d26 mov r0, r6
 *   @0x2e8d28 mov r1, r9
 *   @0x2e8d2a add.w r10, sp, #0x38
 *   @0x2e8d2e ands r3, r3, #0x10
 *   @0x2e8d32 itet ne
 *   @0x2e8d34 ldrne r2, [r4, #0x18]
 *   @0x2e8d36 moveq r2, r3
 *   @0x2e8d38 ldrne r3, [r4, #0x1c]
 *   @0x2e8d3a stm.w sp, {r2, r3}
 *   @0x2e8d3e add r2, sp, #0x40
 *   @0x2e8d40 mov r3, r7
 *   @0x2e8d42 str r2, [sp, #0x8]
 *   @0x2e8d44 ldr r2, [sp, #0x18]
 *   @0x2e8d46 bl 0x2e7bb0 <FT_Done_GlyphSlot+0x96>
 *   @0x2e8d4a mov r3, r0
 *   @0x2e8d4c str r0, [sp, #0x38]
 *   @0x2e8d4e cmp r0, #0x0
 *   @0x2e8d50 beq.w 0x2e8fa8 <FT_Done_Face+0x3cc>
 *   @0x2e8d54 ldr r1, [sp, #0x1c]
 *   @0x2e8d56 cbz r1, 0x2e8da6 <FT_Done_Face+0x1ca>
 *   @0x2e8d58 ldr r2, [r8, #-4]
 *   @0x2e8d5c ldr r1, [sp, #0x2c]
 *   @0x2e8d5e ldr r2, [r2]
 *   @0x2e8d60 ldr r0, [r2, #0x8]
 *   @0x2e8d62 str r3, [sp, #0x10]
 *   @0x2e8d64 blx 0xb6574 <strcmp@plt>
 *   @0x2e8d68 ldr r3, [sp, #0x10]
 *   @0x2e8d6a mov r1, r0
 *   @0x2e8d6c cbnz r0, 0x2e8da6 <FT_Done_Face+0x1ca>
 *   @0x2e8d6e uxtb r3, r3
 *   @0x2e8d70 cmp r3, #0x8e
 *   @0x2e8d72 bne 0x2e8da6 <FT_Done_Face+0x1ca>
 *   @0x2e8d74 ldr.w r0, [r9]
 *   @0x2e8d78 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e8d7c str.w r0, [r10]
 *   @0x2e8d80 cbnz r0, 0x2e8db8 <FT_Done_Face+0x1dc>
 *   @0x2e8d82 mov r0, r5
 *   @0x2e8d84 ldr.w r1, [r9]
 *   @0x2e8d88 mov r2, r7
 *   @0x2e8d8a ldr r3, [sp, #0x14]
 *   @0x2e8d8c bl 0x2e91a4 <FT_New_Face+0xcc>
 *   @0x2e8d90 str.w r0, [r10]
 *   @0x2e8d94 cbnz r0, 0x2e8da6 <FT_Done_Face+0x1ca>
 *   @0x2e8d96 ldr.w r0, [r9]
 *   @0x2e8d9a mov r1, r11
 *   @0x2e8d9c bl 0x2e745e <FT_Stream_Free>
 *   @0x2e8da0 ldr.w r0, [r10]
 *   @0x2e8da4 b 0x2e90b6 <FT_Done_Face+0x4da>
 *   @0x2e8da6 ldrb.w r3, [sp, #0x38]
 *   @0x2e8daa cmp r3, #0x2
 *   @0x2e8dac bne 0x2e8db8 <FT_Done_Face+0x1dc>
 *   @0x2e8dae mov r3, r6
 *   @0x2e8db0 b 0x2e8d12 <FT_Done_Face+0x136>
 *   @0x2e8db2 movs r3, #0x0
 *   @0x2e8db4 str r3, [sp, #0x20]
 *   @0x2e8db6 mov r6, r3
 *   @0x2e8db8 ldr r3, [sp, #0x38]
 *   @0x2e8dba and r2, r3, #0xfb
 *   @0x2e8dbe cmp r2, #0x51
 *   @0x2e8dc0 beq 0x2e8dca <FT_Done_Face+0x1ee>
 *   @0x2e8dc2 uxtb r3, r3
 *   @0x2e8dc4 cmp r3, #0x2
 *   @0x2e8dc6 bne.w 0x2e8f9e <FT_Done_Face+0x3c2>
 *   @0x2e8dca ldr r1, [sp, #0x1c]
 *   @0x2e8dcc cmp r1, #0x0
 *   @0x2e8dce beq.w 0x2e8f94 <FT_Done_Face+0x3b8>
 *   @0x2e8dd2 ldr.w r9, [sp, #0x3c]
 *   @0x2e8dd6 cmp.w r9, #0x0
 *   @0x2e8dda beq 0x2e8e5e <FT_Done_Face+0x282>
 *   @0x2e8ddc mov r0, r9
 *   @0x2e8dde movs r1, #0x0
 *   @0x2e8de0 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e8de4 mov r3, r0
 *   @0x2e8de6 cmp r0, #0x0
 *   @0x2e8de8 bne 0x2e8e64 <FT_Done_Face+0x288>
 *   @0x2e8dea mov r0, r9
 *   @0x2e8dec add r1, sp, #0xd4
 *   @0x2e8dee movs r2, #0x80
 *   @0x2e8df0 bl 0x2e698e <FT_Stream_Read>
 *   @0x2e8df4 mov r3, r0
 *   @0x2e8df6 cbnz r0, 0x2e8e64 <FT_Done_Face+0x288>
 *   @0x2e8df8 ldrb.w r3, [sp, #0xd4]
 *   @0x2e8dfc cbnz r3, 0x2e8e62 <FT_Done_Face+0x286>
 *   @0x2e8dfe ldrb.w r3, [sp, #0x11e]
 *   @0x2e8e02 cbnz r3, 0x2e8e62 <FT_Done_Face+0x286>
 *   @0x2e8e04 ldrb.w r3, [sp, #0x126]
 *   @0x2e8e08 cbnz r3, 0x2e8e62 <FT_Done_Face+0x286>
 *   @0x2e8e0a ldrb.w r3, [sp, #0xd5]
 *   @0x2e8e0e subs r2, r3, #0x1
 *   @0x2e8e10 cmp r2, #0x20
 *   @0x2e8e12 bhi 0x2e8e62 <FT_Done_Face+0x286>
 *   @0x2e8e14 ldrb.w r2, [sp, #0x113]
 *   @0x2e8e18 cbnz r2, 0x2e8e62 <FT_Done_Face+0x286>
 *   @0x2e8e1a add r2, sp, #0x158
 *   @0x2e8e1c add r3, r2
 *   @0x2e8e1e ldrb r3, [r3, #-130]
 *   @0x2e8e22 cbnz r3, 0x2e8e62 <FT_Done_Face+0x286>
 *   @0x2e8e24 ldrb.w r3, [sp, #0x127]
 *   @0x2e8e28 lsls r1, r3, #0x18
 *   @0x2e8e2a bmi 0x2e8e62 <FT_Done_Face+0x286>
 *   @0x2e8e2c ldrb.w r2, [sp, #0x128]
 *   @0x2e8e30 mov r0, r5
 *   @0x2e8e32 ldrb.w r1, [sp, #0x12a]
 *   @0x2e8e36 lsls r2, r2, #0x10
 *   @0x2e8e38 orr.w r3, r2, r3, lsl #24
 *   @0x2e8e3c ldrb.w r2, [sp, #0x129]
 *   @0x2e8e40 orrs r3, r1
 *   @0x2e8e42 mov r1, r9
 *   @0x2e8e44 orr.w r2, r3, r2, lsl #8
 *   @0x2e8e48 ldr r3, [sp, #0x14]
 *   @0x2e8e4a adds r2, #0x7f
 *   @0x2e8e4c bic r2, r2, #0x7f
 *   @0x2e8e50 str r3, [sp]
 *   @0x2e8e52 adds r2, #0x80
 *   @0x2e8e54 mov r3, r7
 *   @0x2e8e56 bl 0x2e935c <FT_New_Face+0x284>
 *   @0x2e8e5a mov r3, r0
 *   @0x2e8e5c b 0x2e8e64 <FT_Done_Face+0x288>
 *   @0x2e8e5e movs r3, #0x55
 *   @0x2e8e60 b 0x2e8e64 <FT_Done_Face+0x288>
 *   @0x2e8e62 movs r3, #0x2
 *   @0x2e8e64 uxtb r2, r3
 *   @0x2e8e66 cmp r2, #0x2
 *   @0x2e8e68 bne 0x2e8e7c <FT_Done_Face+0x2a0>
 *   @0x2e8e6a ldr r1, [sp, #0x14]
 *   @0x2e8e6c mov r3, r7
 *   @0x2e8e6e mov r0, r5
 *   @0x2e8e70 movs r2, #0x0
 *   @0x2e8e72 str r1, [sp]
 *   @0x2e8e74 mov r1, r9
 *   @0x2e8e76 bl 0x2e935c <FT_New_Face+0x284>
 *   @0x2e8e7a mov r3, r0
 *   @0x2e8e7c uxtb r2, r3
 *   @0x2e8e7e cmp r2, #0x2
 *   @0x2e8e80 beq 0x2e8e86 <FT_Done_Face+0x2aa>
 *   @0x2e8e82 cmp r2, #0x55
 *   @0x2e8e84 bne 0x2e8f82 <FT_Done_Face+0x3a6>
 *   @0x2e8e86 ldr r2, [r4]
 *   @0x2e8e88 lsls r2, r2, #0x1d
 *   @0x2e8e8a bpl 0x2e8f82 <FT_Done_Face+0x3a6>
 *   @0x2e8e8c ldr r2, [r5]
 *   @0x2e8e8e add.w r10, sp, #0x68
 *   @0x2e8e92 add r3, sp, #0x8c
 *   @0x2e8e94 add r1, sp, #0xb0
 *   @0x2e8e96 str r3, [sp]
 *   @0x2e8e98 mov r0, r5
 *   @0x2e8e9a str r1, [sp, #0x4]
 *   @0x2e8e9c mov.w r8, #0x0
 *   @0x2e8ea0 str r2, [sp, #0x2c]
 *   @0x2e8ea2 str r3, [sp, #0x24]
 *   @0x2e8ea4 mov r3, r10
 *   @0x2e8ea6 str r1, [sp, #0x28]
 *   @0x2e8ea8 mov r1, r9
 *   @0x2e8eaa ldr r2, [r4, #0xc]
 *   @0x2e8eac mov r9, r8
 *   @0x2e8eae str.w r8, [sp, #0x44]
 *   @0x2e8eb2 bl 0x2e68cc <FT_Raccess_Guess>
 *   @0x2e8eb6 ldr r2, [pc, #0x21c]
 *   @0x2e8eb8 movs r3, #0x2
 *   @0x2e8eba add r1, sp, #0x48
 *   @0x2e8ebc str r1, [sp, #0x1c]
 *   @0x2e8ebe add r2, pc
 *   @0x2e8ec0 str r2, [sp, #0x34]
 *   @0x2e8ec2 ldr r1, [sp, #0x34]
 *   @0x2e8ec4 add.w r2, r1, r8, lsl #1
 *   @0x2e8ec8 ldr r2, [r2, #0x4]
 *   @0x2e8eca subs r2, #0x3
 *   @0x2e8ecc cmp r2, #0x1
 *   @0x2e8ece bhi 0x2e8edc <FT_Done_Face+0x300>
 *   @0x2e8ed0 cmp.w r9, #0x0
 *   @0x2e8ed4 bne 0x2e8f4e <FT_Done_Face+0x372>
 *   @0x2e8ed6 movs r2, #0x1
 *   @0x2e8ed8 str r2, [sp, #0x18]
 *   @0x2e8eda b 0x2e8ee0 <FT_Done_Face+0x304>
 *   @0x2e8edc movs r1, #0x0
 *   @0x2e8ede str r1, [sp, #0x18]
 *   @0x2e8ee0 add r1, sp, #0xb0
 *   @0x2e8ee2 ldr.w r2, [r1, r8]
 *   @0x2e8ee6 cmp r2, #0x0
 *   @0x2e8ee8 bne 0x2e8f52 <FT_Done_Face+0x376>
 *   @0x2e8eea movs r3, #0x4
 *   @0x2e8eec str r3, [sp, #0x48]
 *   @0x2e8eee ldr.w r3, [r10, r8]
 *   @0x2e8ef2 cbnz r3, 0x2e8ef6 <FT_Done_Face+0x31a>
 *   @0x2e8ef4 ldr r3, [r4, #0xc]
 *   @0x2e8ef6 add r2, sp, #0x44
 *   @0x2e8ef8 mov r0, r5
 *   @0x2e8efa add r1, sp, #0x48
 *   @0x2e8efc str r3, [sp, #0x54]
 *   @0x2e8efe bl 0x2e73dc <FT_Stream_New>
 *   @0x2e8f02 ldr r2, [sp, #0x18]
 *   @0x2e8f04 mov r3, r0
 *   @0x2e8f06 cbz r2, 0x2e8f0e <FT_Done_Face+0x332>
 *   @0x2e8f08 uxtb r2, r0
 *   @0x2e8f0a cmp r2, #0x51
 *   @0x2e8f0c beq 0x2e8f4e <FT_Done_Face+0x372>
 *   @0x2e8f0e cbnz r3, 0x2e8f52 <FT_Done_Face+0x376>
 *   @0x2e8f10 ldr r3, [sp, #0x14]
 *   @0x2e8f12 mov r0, r5
 *   @0x2e8f14 ldr r1, [sp, #0x44]
 *   @0x2e8f16 add.w r12, sp, #0x44
 *   @0x2e8f1a str r3, [sp]
 *   @0x2e8f1c add r3, sp, #0x8c
 *   @0x2e8f1e ldr.w r2, [r3, r8]
 *   @0x2e8f22 mov r3, r7
 *   @0x2e8f24 str.w r12, [sp, #0x10]
 *   @0x2e8f28 bl 0x2e935c <FT_New_Face+0x284>
 *   @0x2e8f2c ldr.w r12, [sp, #0x10]
 *   @0x2e8f30 movs r1, #0x0
 *   @0x2e8f32 mov r3, r0
 *   @0x2e8f34 ldr.w r0, [r12]
 *   @0x2e8f38 str r3, [sp, #0x10]
 *   @0x2e8f3a bl 0x2e745e <FT_Stream_Free>
 *   @0x2e8f3e ldr r3, [sp, #0x10]
 *   @0x2e8f40 cbz r3, 0x2e8f5c <FT_Done_Face+0x380>
 *   @0x2e8f42 ldr r1, [sp, #0x18]
 *   @0x2e8f44 cmp r1, #0x0
 *   @0x2e8f46 it ne
 *   @0x2e8f48 movne.w r9, #0x1
 *   @0x2e8f4c b 0x2e8f52 <FT_Done_Face+0x376>
 *   @0x2e8f4e mov.w r9, #0x1
 *   @0x2e8f52 add.w r8, r8, #0x4
 *   @0x2e8f56 cmp.w r8, #0x24
 *   @0x2e8f5a bne 0x2e8ec2 <FT_Done_Face+0x2e6>
 *   @0x2e8f5c movs r4, #0x0
 *   @0x2e8f5e mov r5, r4
 *   @0x2e8f60 ldr.w r1, [r10, r4]
 *   @0x2e8f64 cbz r1, 0x2e8f74 <FT_Done_Face+0x398>
 *   @0x2e8f66 ldr r0, [sp, #0x2c]
 *   @0x2e8f68 str r3, [sp, #0x10]
 *   @0x2e8f6a bl 0x2e7336 <ft_mem_free>
 *   @0x2e8f6e str.w r5, [r10, r4]
 *   @0x2e8f72 ldr r3, [sp, #0x10]
 *   @0x2e8f74 adds r4, #0x4
 *   @0x2e8f76 cmp r4, #0x24
 *   @0x2e8f78 bne 0x2e8f60 <FT_Done_Face+0x384>
 *   @0x2e8f7a cmp r3, #0x0
 *   @0x2e8f7c ite ne
 *   @0x2e8f7e movne r3, #0x2
 *   @0x2e8f80 moveq r3, #0x0
 *   @0x2e8f82 add r4, sp, #0x38
 *   @0x2e8f84 str r3, [sp, #0x38]
 *   @0x2e8f86 cbnz r3, 0x2e8f94 <FT_Done_Face+0x3b8>
 *   @0x2e8f88 ldr r0, [sp, #0x3c]
 *   @0x2e8f8a mov r1, r11
 *   @0x2e8f8c bl 0x2e745e <FT_Stream_Free>
 *   @0x2e8f90 ldr r0, [r4]
 *   @0x2e8f92 b 0x2e90b6 <FT_Done_Face+0x4da>
 *   @0x2e8f94 ldrb.w r2, [sp, #0x38]
 *   @0x2e8f98 cmp r2, #0x2
 *   @0x2e8f9a it eq
 *   @0x2e8f9c streq r2, [sp, #0x38]
 *   @0x2e8f9e ldr r0, [sp, #0x3c]
 *   @0x2e8fa0 mov r1, r11
 *   @0x2e8fa2 bl 0x2e745e <FT_Stream_Free>
 *   @0x2e8fa6 b 0x2e90a4 <FT_Done_Face+0x4c8>
 *   @0x2e8fa8 add r5, sp, #0x38
 *   @0x2e8faa movs r1, #0xc
 *   @0x2e8fac ldr r0, [sp, #0x20]
 *   @0x2e8fae add r4, sp, #0x40
 *   @0x2e8fb0 mov r2, r5
 *   @0x2e8fb2 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e8fb6 ldr.w r8, [r5]
 *   @0x2e8fba mov r1, r0
 *   @0x2e8fbc cmp.w r8, #0x0
 *   @0x2e8fc0 bne 0x2e909a <FT_Done_Face+0x4be>
 *   @0x2e8fc2 ldr r2, [r4]
 *   @0x2e8fc4 str r2, [r0, #0x8]
 *   @0x2e8fc6 ldr r0, [r2, #0x60]
 *   @0x2e8fc8 adds r0, #0x10
 *   @0x2e8fca bl 0x2e8920 <FT_List_Add>
 *   @0x2e8fce cmp r7, #0x0
 *   @0x2e8fd0 blt 0x2e8ff4 <FT_Done_Face+0x418>
 *   @0x2e8fd2 ldr r0, [r4]
 *   @0x2e8fd4 mov r1, r8
 *   @0x2e8fd6 bl 0x2e7a70 <FT_New_GlyphSlot>
 *   @0x2e8fda str r0, [r5]
 *   @0x2e8fdc cmp r0, #0x0
 *   @0x2e8fde bne 0x2e909c <FT_Done_Face+0x4c0>
 *   @0x2e8fe0 ldr r0, [r4]
 *   @0x2e8fe2 add r1, sp, #0xb0
 *   @0x2e8fe4 bl 0x2e8938 <FT_New_Size>
 *   @0x2e8fe8 str r0, [r5]
 *   @0x2e8fea cmp r0, #0x0
 *   @0x2e8fec bne 0x2e909c <FT_Done_Face+0x4c0>
 *   @0x2e8fee ldr r3, [r4]
 *   @0x2e8ff0 ldr r2, [sp, #0xb0]
 *   @0x2e8ff2 str r2, [r3, #0x58]
 *   @0x2e8ff4 ldr r3, [r4]
 *   @0x2e8ff6 ldr r2, [r3, #0x8]
 *   @0x2e8ff8 lsls r5, r2, #0x1f
 *   @0x2e8ffa bpl 0x2e9016 <FT_Done_Face+0x43a>
 *   @0x2e8ffc ldrh.w r1, [r3, #0x4a]
 *   @0x2e9000 lsls r0, r1, #0x10
 *   @0x2e9002 itt mi
 *   @0x2e9004 rsbmi r1, r1, #0
 *   @0x2e9006 strhmi.w r1, [r3, #0x4a]
 *   @0x2e900a lsls r1, r2, #0x1a
 *   @0x2e900c itt pl
 *   @0x2e900e ldrhpl.w r1, [r3, #0x4a]
 *   @0x2e9012 strhpl.w r1, [r3, #0x4e]
 *   @0x2e9016 lsls r3, r2, #0x1e
 *   @0x2e9018 bmi 0x2e904a <FT_Done_Face+0x46e>
 *   @0x2e901a ldr r3, [r4]
 *   @0x2e901c movs r2, #0x0
 *   @0x2e901e mov.w r1, #0x10000
 *   @0x2e9022 ldr.w r3, [r3, #0x80]
 *   @0x2e9026 stm.w r3, {r1, r2}
 *   @0x2e902a str r2, [r3, #0x8]
 *   @0x2e902c str r2, [r3, #0x10]
 *   @0x2e902e str r2, [r3, #0x14]
 *   @0x2e9030 movs r2, #0x1
 *   @0x2e9032 str r2, [r3, #0x40]
 *   @0x2e9034 movs r2, #0xff
 *   @0x2e9036 strb.w r2, [r3, #0x38]
 *   @0x2e903a ldr r2, [sp, #0x14]
 *   @0x2e903c str r1, [r3, #0xc]
 *   @0x2e903e cmp r2, #0x0
 *   @0x2e9040 beq 0x2e909c <FT_Done_Face+0x4c0>
 *   @0x2e9042 ldr r3, [r4]
 *   @0x2e9044 ldr r1, [sp, #0x14]
 *   @0x2e9046 str r3, [r1]
 *   @0x2e9048 b 0x2e90b0 <FT_Done_Face+0x4d4>
 *   @0x2e904a movs r2, #0x0
 *   @0x2e904c mov r1, r2
 *   @0x2e904e ldr r3, [r4]
 *   @0x2e9050 ldr r0, [r3, #0x1c]
 *   @0x2e9052 cmp r2, r0
 *   @0x2e9054 bge 0x2e901a <FT_Done_Face+0x43e>
 *   @0x2e9056 ldr r6, [r3, #0x20]
 *   @0x2e9058 lsls r0, r2, #0x4
 *   @0x2e905a adds r3, r6, r0
 *   @0x2e905c ldrh r5, [r6, r0]
 *   @0x2e905e lsls r7, r5, #0x10
 *   @0x2e9060 itt mi
 *   @0x2e9062 rsbmi r5, r5, #0
 *   @0x2e9064 strhmi r5, [r6, r0]
 *   @0x2e9066 ldr r5, [r3, #0x8]
 *   @0x2e9068 cmp r5, #0x0
 *   @0x2e906a itt lt
 *   @0x2e906c rsblt r5, r5, #0
 *   @0x2e906e strlt r5, [r3, #0x8]
 *   @0x2e9070 ldr r5, [r3, #0xc]
 *   @0x2e9072 cmp r5, #0x0
 *   @0x2e9074 itt lt
 *   @0x2e9076 rsblt r5, r5, #0
 *   @0x2e9078 strlt r5, [r3, #0xc]
 *   @0x2e907a ldrsh r5, [r6, r0]
 *   @0x2e907c cmp r5, #0x0
 *   @0x2e907e blt 0x2e908c <FT_Done_Face+0x4b0>
 *   @0x2e9080 ldr r5, [r3, #0x8]
 *   @0x2e9082 cmp r5, #0x0
 *   @0x2e9084 blt 0x2e908c <FT_Done_Face+0x4b0>
 *   @0x2e9086 ldr r5, [r3, #0xc]
 *   @0x2e9088 cmp r5, #0x0
 *   @0x2e908a bge 0x2e9096 <FT_Done_Face+0x4ba>
 *   @0x2e908c strh r1, [r3, #0x2]
 *   @0x2e908e strh r1, [r6, r0]
 *   @0x2e9090 str r1, [r3, #0x4]
 *   @0x2e9092 str r1, [r3, #0x8]
 *   @0x2e9094 str r1, [r3, #0xc]
 *   @0x2e9096 adds r2, #0x1
 *   @0x2e9098 b 0x2e904e <FT_Done_Face+0x472>
 *   @0x2e909a cbz r0, 0x2e90a4 <FT_Done_Face+0x4c8>
 *   @0x2e909c ldr r0, [r4]
 *   @0x2e909e bl 0x2e8bdc <FT_Done_Face>
 *   @0x2e90a2 b 0x2e90b0 <FT_Done_Face+0x4d4>
 *   @0x2e90a4 ldr r1, [sp, #0x40]
 *   @0x2e90a6 cbz r1, 0x2e90b0 <FT_Done_Face+0x4d4>
 *   @0x2e90a8 ldr r0, [sp, #0x20]
 *   @0x2e90aa mov r2, r6
 *   @0x2e90ac bl 0x2e8b5c <FT_List_Finalize+0x38>
 *   @0x2e90b0 ldr r0, [sp, #0x38]
 *   @0x2e90b2 b 0x2e90b6 <FT_Done_Face+0x4da>
 *   @0x2e90b4 movs r0, #0x6
 *   @0x2e90b6 ldr r1, [sp, #0x30]
 *   @0x2e90b8 ldr r2, [sp, #0x154]
 *   @0x2e90ba ldr r3, [r1]
 *   @0x2e90bc cmp r2, r3
 *   @0x2e90be beq 0x2e90c4 <FT_Done_Face+0x4e8>
 *   @0x2e90c0 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2e90c4 add sp, #0x15c
 *   @0x2e90c6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e90ca nop
 *   @0x2e90cc ldr r5, [pc, #0x28]
 *   @0x2e90ce movs r0, r2
 *   @0x2e90d0 ldrh r2, [r2, r0]
 *   @0x2e90d2 movs r2, r1
/* ═══════════════════════════════════════════════════════════════════════
 * §4  anon_thumb_2fa06c   0x2fa06c..0x2fa330   708 B / 271 条   in-degree 3
 * TrueType 解释器带的 6 个小函数（708 B / 6 个 bl 入口）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 3 条 Thumb `bl` 指向本段起始：TT_New_Context×1 / anon_2f1de8 区×1 / anon_300274 区×1；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 32 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push {r4, r5, r6, lr} / mov r4, r0 / ldr r6, [r0, #0x8]（帧：push {r4, r5, r6, lr}）；窗口内出口 4 个
 * 结构：入口可达 84 B / 28 条（11%）；段内 bl 入口 5 个：0x2fa0c0(72 B/31 条) / 0x2fa108(134 B/40 条) / 0x2fa156(56 B/16 条) / 0x2fa19e(132 B/55 条) / 0x2fa222(292 B/111 条)
 *      可打印岛：无 ≥16 B 的
 * 入口 28 条 / 84 B；32 处 bl 全打向 ft_mem_free，是一族「分配失败 → 归还 → 回 0」的收尾路径。
 *      段内 5 个 bl 入口：0x2fa0c0(72 B) / 0x2fa108(134 B) / 0x2fa156(56 B) / 0x2fa19e(132 B) /
 *      0x2fa222(292 B)。反向被 TT_New_Context bl 1 次。
 *
 * 锚点：271 条（= asm/index-anonT_2fa06c.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2fa06c push {r4, r5, r6, lr}
 *   @0x2fa06e mov r4, r0
 *   @0x2fa070 ldr r6, [r0, #0x8]
 *   @0x2fa072 movs r5, #0x0
 *   @0x2fa074 strh.w r5, [r0, #0x1bc]
 *   @0x2fa078 strh.w r5, [r0, #0x1be]
 *   @0x2fa07c mov r0, r6
 *   @0x2fa07e ldr r1, [r4, #0x18]
 *   @0x2fa080 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa084 mov r0, r6
 *   @0x2fa086 ldr.w r1, [r4, #0x1b8]
 *   @0x2fa08a str r5, [r4, #0x18]
 *   @0x2fa08c str r5, [r4, #0x14]
 *   @0x2fa08e bl 0x2e7336 <ft_mem_free>
 *   @0x2fa092 mov r0, r6
 *   @0x2fa094 ldr.w r1, [r4, #0x18c]
 *   @0x2fa098 str.w r5, [r4, #0x1b8]
 *   @0x2fa09c str.w r5, [r4, #0x1b4]
 *   @0x2fa0a0 str.w r5, [r4, #0x1b0]
 *   @0x2fa0a4 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa0a8 str.w r5, [r4, #0x18c]
 *   @0x2fa0ac str.w r5, [r4, #0x188]
 *   @0x2fa0b0 mov r0, r6
 *   @0x2fa0b2 str r5, [r4, #0x4]
 *   @0x2fa0b4 mov r1, r4
 *   @0x2fa0b6 str r5, [r4]
 *   @0x2fa0b8 pop.w {r4, r5, r6, lr}
 *   @0x2fa0bc b.w 0x2e7336 <ft_mem_free>
 *   @0x2fa0c0 push {r4, r5, r6, lr}
 *   @0x2fa0c2 mov r4, r0
 *   @0x2fa0c4 ldr r6, [r0]
 *   @0x2fa0c6 cbz r6, 0x2fa106 <ps_hints_apply+0x8d06>
 *   @0x2fa0c8 mov r0, r6
 *   @0x2fa0ca ldr r1, [r4, #0x1c]
 *   @0x2fa0cc movs r5, #0x0
 *   @0x2fa0ce bl 0x2e7336 <ft_mem_free>
 *   @0x2fa0d2 mov r0, r6
 *   @0x2fa0d4 ldr r1, [r4, #0x18]
 *   @0x2fa0d6 str r5, [r4, #0x1c]
 *   @0x2fa0d8 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa0dc mov r0, r6
 *   @0x2fa0de ldr r1, [r4, #0x10]
 *   @0x2fa0e0 str r5, [r4, #0x18]
 *   @0x2fa0e2 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa0e6 mov r0, r6
 *   @0x2fa0e8 ldr r1, [r4, #0xc]
 *   @0x2fa0ea str r5, [r4, #0x10]
 *   @0x2fa0ec bl 0x2e7336 <ft_mem_free>
 *   @0x2fa0f0 str r5, [r4, #0xc]
 *   @0x2fa0f2 mov r0, r6
 *   @0x2fa0f4 ldr r1, [r4, #0x14]
 *   @0x2fa0f6 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa0fa str r5, [r4, #0x14]
 *   @0x2fa0fc strh r5, [r4, #0x8]
 *   @0x2fa0fe strh r5, [r4, #0x4]
 *   @0x2fa100 strh r5, [r4, #0xa]
 *   @0x2fa102 strh r5, [r4, #0x6]
 *   @0x2fa104 str r5, [r4]
 *   @0x2fa106 pop {r4, r5, r6, pc}
 *   @0x2fa108 push {r4, r5, r6, lr}
 *   @0x2fa10a mov r4, r0
 *   @0x2fa10c ldr r3, [r0]
 *   @0x2fa10e ldr.w r0, [r0, #0x12c]
 *   @0x2fa112 ldr r6, [r3, #0x64]
 *   @0x2fa114 cbz r0, 0x2fa120 <ps_hints_apply+0x8d20>
 *   @0x2fa116 bl 0x2fa06c <ps_hints_apply+0x8c6c>
 *   @0x2fa11a movs r3, #0x0
 *   @0x2fa11c str.w r3, [r4, #0x12c]
 *   @0x2fa120 mov r0, r6
 *   @0x2fa122 ldr.w r1, [r4, #0xfc]
 *   @0x2fa126 movs r5, #0x0
 *   @0x2fa128 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa12c ldr.w r1, [r4, #0x104]
 *   @0x2fa130 mov r0, r6
 *   @0x2fa132 str.w r5, [r4, #0xfc]
 *   @0x2fa136 str.w r5, [r4, #0xf8]
 *   @0x2fa13a bl 0x2e7336 <ft_mem_free>
 *   @0x2fa13e add.w r0, r4, #0x108
 *   @0x2fa142 str.w r5, [r4, #0x104]
 *   @0x2fa146 strh.w r5, [r4, #0x100]
 *   @0x2fa14a bl 0x2fa0c0 <ps_hints_apply+0x8cc0>
 *   @0x2fa14e mov r0, r6
 *   @0x2fa150 ldr.w r1, [r4, #0x84]
 *   @0x2fa154 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa158 str.w r5, [r4, #0x84]
 *   @0x2fa15c mov r0, r6
 *   @0x2fa15e ldr.w r1, [r4, #0x90]
 *   @0x2fa162 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa166 mov.w r3, #0xffffffff
 *   @0x2fa16a str.w r5, [r4, #0x90]
 *   @0x2fa16e str r5, [r4, #0x7c]
 *   @0x2fa170 str.w r5, [r4, #0x80]
 *   @0x2fa174 str.w r5, [r4, #0x88]
 *   @0x2fa178 str.w r5, [r4, #0x8c]
 *   @0x2fa17c str.w r5, [r4, #0x94]
 *   @0x2fa180 str.w r5, [r4, #0x98]
 *   @0x2fa184 str.w r3, [r4, #0x130]
 *   @0x2fa188 str.w r3, [r4, #0x134]
 *   @0x2fa18c pop {r4, r5, r6, pc}
 *   @0x2fa18e push {r4, lr}
 *   @0x2fa190 mov r4, r0
 *   @0x2fa192 bl 0x2fa108 <ps_hints_apply+0x8d08>
 *   @0x2fa196 movs r3, #0x0
 *   @0x2fa198 strb.w r3, [r4, #0x70]
 *   @0x2fa19c pop {r4, pc}
 *   @0x2fa19e push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2fa1a2 mov r4, r1
 *   @0x2fa1a4 ldr r3, [r1, #0x4]
 *   @0x2fa1a6 ldr r6, [r0, #0x64]
 *   @0x2fa1a8 cbz r3, 0x2fa1ee <ps_hints_apply+0x8dee>
 *   @0x2fa1aa movs r5, #0x0
 *   @0x2fa1ac mov r8, r5
 *   @0x2fa1ae ldr r3, [r4]
 *   @0x2fa1b0 cmp r5, r3
 *   @0x2fa1b2 bhs 0x2fa1e2 <ps_hints_apply+0x8de2>
 *   @0x2fa1b4 ldr r3, [r4, #0x4]
 *   @0x2fa1b6 lsls r7, r5, #0x4
 *   @0x2fa1b8 mov r0, r6
 *   @0x2fa1ba adds r5, #0x1
 *   @0x2fa1bc add r3, r7
 *   @0x2fa1be ldr r1, [r3, #0x8]
 *   @0x2fa1c0 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa1c4 ldr r3, [r4, #0x4]
 *   @0x2fa1c6 mov r0, r6
 *   @0x2fa1c8 add r3, r7
 *   @0x2fa1ca str.w r8, [r3, #0x8]
 *   @0x2fa1ce ldr r3, [r4, #0x4]
 *   @0x2fa1d0 add r3, r7
 *   @0x2fa1d2 ldr r1, [r3, #0xc]
 *   @0x2fa1d4 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa1d8 ldr r3, [r4, #0x4]
 *   @0x2fa1da add r7, r3
 *   @0x2fa1dc str.w r8, [r7, #0xc]
 *   @0x2fa1e0 b 0x2fa1ae <ps_hints_apply+0x8dae>
 *   @0x2fa1e2 mov r0, r6
 *   @0x2fa1e4 ldr r1, [r4, #0x4]
 *   @0x2fa1e6 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa1ea movs r3, #0x0
 *   @0x2fa1ec str r3, [r4, #0x4]
 *   @0x2fa1ee ldr r3, [r4, #0x10]
 *   @0x2fa1f0 cbz r3, 0x2fa21e <ps_hints_apply+0x8e1e>
 *   @0x2fa1f2 movs r5, #0x0
 *   @0x2fa1f4 mov r7, r5
 *   @0x2fa1f6 ldr r3, [r4, #0xc]
 *   @0x2fa1f8 cmp r5, r3
 *   @0x2fa1fa bhs 0x2fa212 <ps_hints_apply+0x8e12>
 *   @0x2fa1fc ldr r3, [r4, #0x10]
 *   @0x2fa1fe mov r0, r6
 *   @0x2fa200 ldr.w r1, [r3, r5, lsl #2]
 *   @0x2fa204 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa208 ldr r3, [r4, #0x10]
 *   @0x2fa20a str.w r7, [r3, r5, lsl #2]
 *   @0x2fa20e adds r5, #0x1
 *   @0x2fa210 b 0x2fa1f6 <ps_hints_apply+0x8df6>
 *   @0x2fa212 mov r0, r6
 *   @0x2fa214 ldr r1, [r4, #0x10]
 *   @0x2fa216 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa21a movs r3, #0x0
 *   @0x2fa21c str r3, [r4, #0x10]
 *   @0x2fa21e pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2fa222 push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2fa226 mov r6, r0
 *   @0x2fa228 ldr.w r4, [r0, #0x2b8]
 *   @0x2fa22c ldr r5, [r0, #0x64]
 *   @0x2fa22e cmp r4, #0x0
 *   @0x2fa230 beq.w 0x2fa342 <ps_hints_apply+0x8f42>
 *   @0x2fa234 ldr r3, [r4, #0xc]
 *   @0x2fa236 mov r0, r5
 *   @0x2fa238 ldr r1, [r4, #0x4]
 *   @0x2fa23a movs r7, #0x0
 *   @0x2fa23c ldr.w r9, [r3]
 *   @0x2fa240 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa244 mov r0, r5
 *   @0x2fa246 ldr r1, [r4, #0x8]
 *   @0x2fa248 str r7, [r4, #0x4]
 *   @0x2fa24a bl 0x2e7336 <ft_mem_free>
 *   @0x2fa24e mov r0, r5
 *   @0x2fa250 ldr r1, [r4, #0x14]
 *   @0x2fa252 str r7, [r4, #0x8]
 *   @0x2fa254 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa258 str r7, [r4, #0x14]
 *   @0x2fa25a mov r0, r5
 *   @0x2fa25c ldr r1, [r4, #0xc]
 *   @0x2fa25e bl 0x2e7336 <ft_mem_free>
 *   @0x2fa262 ldr r3, [r4, #0x1c]
 *   @0x2fa264 str r7, [r4, #0xc]
 *   @0x2fa266 cbz r3, 0x2fa296 <ps_hints_apply+0x8e96>
 *   @0x2fa268 mov r10, r7
 *   @0x2fa26a cmp r7, r9
 *   @0x2fa26c beq 0x2fa28a <ps_hints_apply+0x8e8a>
 *   @0x2fa26e ldr r3, [r4, #0x1c]
 *   @0x2fa270 lsl.w r8, r7, #0x3
 *   @0x2fa274 mov r0, r5
 *   @0x2fa276 adds r7, #0x1
 *   @0x2fa278 add r3, r8
 *   @0x2fa27a ldr r1, [r3, #0x4]
 *   @0x2fa27c bl 0x2e7336 <ft_mem_free>
 *   @0x2fa280 ldr r3, [r4, #0x1c]
 *   @0x2fa282 add r3, r8
 *   @0x2fa284 str.w r10, [r3, #0x4]
 *   @0x2fa288 b 0x2fa26a <ps_hints_apply+0x8e6a>
 *   @0x2fa28a mov r0, r5
 *   @0x2fa28c ldr r1, [r4, #0x1c]
 *   @0x2fa28e bl 0x2e7336 <ft_mem_free>
 *   @0x2fa292 movs r3, #0x0
 *   @0x2fa294 str r3, [r4, #0x1c]
 *   @0x2fa296 ldr r1, [r4, #0x28]
 *   @0x2fa298 cbz r1, 0x2fa2c8 <ps_hints_apply+0x8ec8>
 *   @0x2fa29a mov r0, r6
 *   @0x2fa29c movs r7, #0x0
 *   @0x2fa29e bl 0x2fa19e <ps_hints_apply+0x8d9e>
 *   @0x2fa2a2 ldr r3, [r4, #0x28]
 *   @0x2fa2a4 mov r0, r5
 *   @0x2fa2a6 ldr r1, [r3, #0x1c]
 *   @0x2fa2a8 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa2ac ldr r3, [r4, #0x28]
 *   @0x2fa2ae mov r0, r5
 *   @0x2fa2b0 str r7, [r3, #0x1c]
 *   @0x2fa2b2 ldr r3, [r4, #0x28]
 *   @0x2fa2b4 ldr r1, [r3, #0x18]
 *   @0x2fa2b6 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa2ba ldr r3, [r4, #0x28]
 *   @0x2fa2bc mov r0, r5
 *   @0x2fa2be str r7, [r3, #0x18]
 *   @0x2fa2c0 ldr r1, [r4, #0x28]
 *   @0x2fa2c2 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa2c6 str r7, [r4, #0x28]
 *   @0x2fa2c8 ldr r1, [r4, #0x34]
 *   @0x2fa2ca cbz r1, 0x2fa2fa <ps_hints_apply+0x8efa>
 *   @0x2fa2cc mov r0, r6
 *   @0x2fa2ce movs r7, #0x0
 *   @0x2fa2d0 bl 0x2fa19e <ps_hints_apply+0x8d9e>
 *   @0x2fa2d4 ldr r3, [r4, #0x34]
 *   @0x2fa2d6 mov r0, r5
 *   @0x2fa2d8 ldr r1, [r3, #0x1c]
 *   @0x2fa2da bl 0x2e7336 <ft_mem_free>
 *   @0x2fa2de ldr r3, [r4, #0x34]
 *   @0x2fa2e0 mov r0, r5
 *   @0x2fa2e2 str r7, [r3, #0x1c]
 *   @0x2fa2e4 ldr r3, [r4, #0x34]
 *   @0x2fa2e6 ldr r1, [r3, #0x18]
 *   @0x2fa2e8 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa2ec ldr r3, [r4, #0x34]
 *   @0x2fa2ee mov r0, r5
 *   @0x2fa2f0 str r7, [r3, #0x18]
 *   @0x2fa2f2 ldr r1, [r4, #0x34]
 *   @0x2fa2f4 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa2f8 str r7, [r4, #0x34]
 *   @0x2fa2fa ldr r1, [r4, #0x38]
 *   @0x2fa2fc cbz r1, 0x2fa320 <ps_hints_apply+0x8f20>
 *   @0x2fa2fe mov r0, r6
 *   @0x2fa300 adds r1, #0x4
 *   @0x2fa302 bl 0x2fa19e <ps_hints_apply+0x8d9e>
 *   @0x2fa306 ldr r3, [r4, #0x38]
 *   @0x2fa308 mov r0, r5
 *   @0x2fa30a movs r6, #0x0
 *   @0x2fa30c ldr r1, [r3, #0x18]
 *   @0x2fa30e bl 0x2e7336 <ft_mem_free>
 *   @0x2fa312 ldr r3, [r4, #0x38]
 *   @0x2fa314 mov r0, r5
 *   @0x2fa316 str r6, [r3, #0x18]
 *   @0x2fa318 ldr r1, [r4, #0x38]
 *   @0x2fa31a bl 0x2e7336 <ft_mem_free>
 *   @0x2fa31e str r6, [r4, #0x38]
 *   @0x2fa320 mov r0, r5
 *   @0x2fa322 ldr r1, [r4, #0x40]
 *   @0x2fa324 bl 0x2e7336 <ft_mem_free>
 *   @0x2fa328 movs r6, #0x0
 *   @0x2fa32a mov r0, r5
 *   @0x2fa32c ldr r1, [r4, #0x48]
 *   @0x2fa32e str r6, [r4, #0x40]
/* ═══════════════════════════════════════════════════════════════════════
 * §5  anon_thumb_2fb894   0x2fb894..0x2fc4e8   3,156 B / 1211 条   in-degree 3
 * TrueType 解释器带的大块（3,156 B / 5 个 bl 入口 / 1,211 条）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 3 条 Thumb `bl` 指向本段起始：TT_RunIns×3；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 51 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} / mov r5, r1 / sub sp, #0x1c（帧：sub sp, 0x1c）；窗口内出口 3 个
 * 结构：入口可达 230 B / 83 条（7%）；段内 bl 入口 4 个：0x2fb97a(254 B/95 条) / 0x2fba78(1500 B/545 条) / 0x2fc078(1148 B/434 条) / 0x2fc3e2(60 B/19 条)
 *      可打印岛：0x2fc054..0x2fc06a（22 B）
 * 入口 230 B / 83 条，被 TT_RunIns bl 3 次；51 处 bl 打向 FT_DivFix / FT_MulDiv / FT_Stream_*，
 *      是「取字、定标、搬轮廓」的混合体。段内 4 个 bl 入口：0x2fb97a(254 B) / 0x2fba78(1,500 B) /
 *      0x2fc078(1,148 B) / 0x2fc3e2(60 B)。0x2fbd6c 与 0x2fc054 各有一小段可打印串。
 *
 * 锚点：1211 条（= asm/index-anonT_2fb894.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2fb894 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2fb898 mov r5, r1
 *   @0x2fb89a sub sp, #0x1c
 *   @0x2fb89c cmp r5, r2
 *   @0x2fb89e mov r4, r0
 *   @0x2fb8a0 mov r9, r2
 *   @0x2fb8a2 ldr r1, [sp, #0x40]
 *   @0x2fb8a4 bhi 0x2fb974 <ps_hints_apply+0xa574>
 *   @0x2fb8a6 ldr r2, [r0, #0xc]
 *   @0x2fb8a8 cmp r3, r2
 *   @0x2fb8aa bhs 0x2fb974 <ps_hints_apply+0xa574>
 *   @0x2fb8ac cmp r1, r2
 *   @0x2fb8ae bhs 0x2fb974 <ps_hints_apply+0xa574>
 *   @0x2fb8b0 ldr r2, [r0, #0x8]
 *   @0x2fb8b2 ldr.w r0, [r2, r3, lsl #3]
 *   @0x2fb8b6 ldr.w r6, [r2, r1, lsl #3]
 *   @0x2fb8ba cmp r0, r6
 *   @0x2fb8bc bgt 0x2fb8c6 <ps_hints_apply+0xa4c6>
 *   @0x2fb8be mov r2, r6
 *   @0x2fb8c0 mov r6, r0
 *   @0x2fb8c2 mov r0, r2
 *   @0x2fb8c4 b 0x2fb8cc <ps_hints_apply+0xa4cc>
 *   @0x2fb8c6 mov r2, r3
 *   @0x2fb8c8 mov r3, r1
 *   @0x2fb8ca mov r1, r2
 *   @0x2fb8cc ldr r2, [r4]
 *   @0x2fb8ce ldr r7, [r4, #0x4]
 *   @0x2fb8d0 ldr.w r11, [r2, r1, lsl #3]
 *   @0x2fb8d4 ldr.w r8, [r7, r3, lsl #3]
 *   @0x2fb8d8 ldr.w r1, [r7, r1, lsl #3]
 *   @0x2fb8dc lsls r7, r5, #0x3
 *   @0x2fb8de ldr.w r10, [r2, r3, lsl #3]
 *   @0x2fb8e2 cmp r8, r1
 *   @0x2fb8e4 rsb r3, r11, r1
 *   @0x2fb8e8 rsb r2, r10, r8
 *   @0x2fb8ec str r3, [sp, #0xc]
 *   @0x2fb8ee str r2, [sp, #0x8]
 *   @0x2fb8f0 beq 0x2fb8f6 <ps_hints_apply+0xa4f6>
 *   @0x2fb8f2 cmp r6, r0
 *   @0x2fb8f4 bne 0x2fb91e <ps_hints_apply+0xa51e>
 *   @0x2fb8f6 ldr r3, [r4]
 *   @0x2fb8f8 ldr r3, [r3, r7]
 *   @0x2fb8fa cmp r3, r10
 *   @0x2fb8fc bgt 0x2fb902 <ps_hints_apply+0xa502>
 *   @0x2fb8fe ldr r2, [sp, #0x8]
 *   @0x2fb900 b 0x2fb908 <ps_hints_apply+0xa508>
 *   @0x2fb902 cmp r3, r11
 *   @0x2fb904 blt 0x2fb90c <ps_hints_apply+0xa50c>
 *   @0x2fb906 ldr r2, [sp, #0xc]
 *   @0x2fb908 add r3, r2
 *   @0x2fb90a b 0x2fb90e <ps_hints_apply+0xa50e>
 *   @0x2fb90c mov r3, r8
 *   @0x2fb90e ldr r1, [r4, #0x4]
 *   @0x2fb910 adds r5, #0x1
 *   @0x2fb912 cmp r5, r9
 *   @0x2fb914 str r3, [r1, r7]
 *   @0x2fb916 add.w r7, r7, #0x8
 *   @0x2fb91a bls 0x2fb8f6 <ps_hints_apply+0xa4f6>
 *   @0x2fb91c b 0x2fb974 <ps_hints_apply+0xa574>
 *   @0x2fb91e movs r3, #0x0
 *   @0x2fb920 rsb r1, r8, r1
 *   @0x2fb924 mov r2, r3
 *   @0x2fb926 subs r0, r0, r6
 *   @0x2fb928 str r1, [sp, #0x10]
 *   @0x2fb92a str r0, [sp, #0x14]
 *   @0x2fb92c ldr r1, [r4]
 *   @0x2fb92e ldr r0, [r1, r7]
 *   @0x2fb930 cmp r0, r10
 *   @0x2fb932 bgt 0x2fb938 <ps_hints_apply+0xa538>
 *   @0x2fb934 ldr r1, [sp, #0x8]
 *   @0x2fb936 b 0x2fb93e <ps_hints_apply+0xa53e>
 *   @0x2fb938 cmp r0, r11
 *   @0x2fb93a blt 0x2fb942 <ps_hints_apply+0xa542>
 *   @0x2fb93c ldr r1, [sp, #0xc]
 *   @0x2fb93e add r0, r1
 *   @0x2fb940 b 0x2fb966 <ps_hints_apply+0xa566>
 *   @0x2fb942 cbnz r2, 0x2fb950 <ps_hints_apply+0xa550>
 *   @0x2fb944 ldr r0, [sp, #0x10]
 *   @0x2fb946 ldr r1, [sp, #0x14]
 *   @0x2fb948 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2fb94c movs r2, #0x1
 *   @0x2fb94e mov r3, r0
 *   @0x2fb950 ldr r1, [r4, #0x8]
 *   @0x2fb952 ldr r0, [r1, r7]
 *   @0x2fb954 mov r1, r3
 *   @0x2fb956 stm.w sp, {r2, r3}
 *   @0x2fb95a subs r0, r0, r6
 *   @0x2fb95c bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fb960 ldm.w sp, {r2, r3}
 *   @0x2fb964 add r0, r8
 *   @0x2fb966 ldr r1, [r4, #0x4]
 *   @0x2fb968 adds r5, #0x1
 *   @0x2fb96a cmp r5, r9
 *   @0x2fb96c str r0, [r1, r7]
 *   @0x2fb96e add.w r7, r7, #0x8
 *   @0x2fb972 bls 0x2fb92c <ps_hints_apply+0xa52c>
 *   @0x2fb974 add sp, #0x1c
 *   @0x2fb976 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2fb97a push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2fb97e movs r4, #0x0
 *   @0x2fb980 ldr.w r10, [r0, #0xc]
 *   @0x2fb984 mov r8, r0
 *   @0x2fb986 mov r6, r3
 *   @0x2fb988 mov r9, r4
 *   @0x2fb98a str r2, [sp, #0x4]
 *   @0x2fb98c ldr.w r7, [r10]
 *   @0x2fb990 ldr.w r5, [r10, #0xc]
 *   @0x2fb994 cmp r1, r7
 *   @0x2fb996 it lo
 *   @0x2fb998 movlo r7, r1
 *   @0x2fb99a adds r5, #0x18
 *   @0x2fb99c cmp r4, r7
 *   @0x2fb99e beq 0x2fb9f4 <ps_hints_apply+0xa5f4>
 *   @0x2fb9a0 ldr r3, [sp, #0x4]
 *   @0x2fb9a2 lsl.w r11, r4, #0x2
 *   @0x2fb9a6 ldr r1, [r5, #-12]
 *   @0x2fb9aa ldr.w r0, [r3, r4, lsl #2]
 *   @0x2fb9ae cmp r0, r1
 *   @0x2fb9b0 bgt 0x2fb9c0 <ps_hints_apply+0xa5c0>
 *   @0x2fb9b2 ldr r3, [r5, #-20]
 *   @0x2fb9b6 cmp r0, r3
 *   @0x2fb9b8 ite ge
 *   @0x2fb9ba movge r2, r0
 *   @0x2fb9bc movlt r2, r3
 *   @0x2fb9be b 0x2fb9c2 <ps_hints_apply+0xa5c2>
 *   @0x2fb9c0 mov r2, r1
 *   @0x2fb9c2 ldr r3, [r5, #-16]
 *   @0x2fb9c6 cmp r2, r3
 *   @0x2fb9c8 bge 0x2fb9da <ps_hints_apply+0xa5da>
 *   @0x2fb9ca ldr r1, [r5, #-20]
 *   @0x2fb9ce subs r0, r0, r3
 *   @0x2fb9d0 subs r1, r1, r3
 *   @0x2fb9d2 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2fb9d6 rsbs r0, r0, #0
 *   @0x2fb9d8 b 0x2fb9e4 <ps_hints_apply+0xa5e4>
 *   @0x2fb9da ble 0x2fb9ea <ps_hints_apply+0xa5ea>
 *   @0x2fb9dc subs r0, r0, r3
 *   @0x2fb9de subs r1, r1, r3
 *   @0x2fb9e0 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2fb9e4 str.w r0, [r6, r11]
 *   @0x2fb9e8 b 0x2fb9ee <ps_hints_apply+0xa5ee>
 *   @0x2fb9ea str.w r9, [r6, r11]
 *   @0x2fb9ee adds r4, #0x1
 *   @0x2fb9f0 adds r5, #0x18
 *   @0x2fb9f2 b 0x2fb99c <ps_hints_apply+0xa59c>
 *   @0x2fb9f4 movs r2, #0x0
 *   @0x2fb9f6 ldr.w r3, [r10]
 *   @0x2fb9fa cmp r7, r3
 *   @0x2fb9fc bhs 0x2fba06 <ps_hints_apply+0xa606>
 *   @0x2fb9fe str.w r2, [r6, r7, lsl #2]
 *   @0x2fba02 adds r7, #0x1
 *   @0x2fba04 b 0x2fb9f6 <ps_hints_apply+0xa5f6>
 *   @0x2fba06 ldr.w r4, [r8, #0x1c]
 *   @0x2fba0a cbz r4, 0x2fba72 <ps_hints_apply+0xa672>
 *   @0x2fba0c adds r4, #0x8
 *   @0x2fba0e movs r5, #0x0
 *   @0x2fba10 ldr.w r3, [r10]
 *   @0x2fba14 cmp r5, r3
 *   @0x2fba16 bhs 0x2fba72 <ps_hints_apply+0xa672>
 *   @0x2fba18 ldrh r7, [r4, #-8]
 *   @0x2fba1c movs r3, #0x1
 *   @0x2fba1e cmp r3, r7
 *   @0x2fba20 bhs 0x2fba6a <ps_hints_apply+0xa66a>
 *   @0x2fba22 ldr r1, [r4, #-4]
 *   @0x2fba26 ldr r0, [r6]
 *   @0x2fba28 add.w r12, r1, r3, lsl #3
 *   @0x2fba2c ldr.w r2, [r1, r3, lsl #3]
 *   @0x2fba30 cmp r0, r2
 *   @0x2fba32 bge 0x2fba66 <ps_hints_apply+0xa666>
 *   @0x2fba34 add.w r3, r3, #0x20000000
 *   @0x2fba38 ldr.w lr, [r12, #0x4]
 *   @0x2fba3c subs r3, #0x1
 *   @0x2fba3e lsls r7, r3, #0x3
 *   @0x2fba40 ldr.w r3, [r1, r3, lsl #3]
 *   @0x2fba44 add.w r8, r1, r7
 *   @0x2fba48 subs r0, r0, r3
 *   @0x2fba4a subs r2, r2, r3
 *   @0x2fba4c ldr.w r1, [r8, #0x4]
 *   @0x2fba50 rsb r1, r1, lr
 *   @0x2fba54 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fba58 ldr r3, [r4, #-4]
 *   @0x2fba5c add r7, r3
 *   @0x2fba5e ldr r3, [r7, #0x4]
 *   @0x2fba60 add r0, r3
 *   @0x2fba62 str r0, [r6]
 *   @0x2fba64 b 0x2fba6a <ps_hints_apply+0xa66a>
 *   @0x2fba66 adds r3, #0x1
 *   @0x2fba68 b 0x2fba1e <ps_hints_apply+0xa61e>
 *   @0x2fba6a adds r5, #0x1
 *   @0x2fba6c adds r4, #0x8
 *   @0x2fba6e adds r6, #0x4
 *   @0x2fba70 b 0x2fba10 <ps_hints_apply+0xa610>
 *   @0x2fba72 add sp, #0xc
 *   @0x2fba74 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2fba78 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2fba7c sub sp, #0x54
 *   @0x2fba7e ldr r3, [r0, #0x64]
 *   @0x2fba80 mov r4, r0
 *   @0x2fba82 str r1, [sp, #0x14]
 *   @0x2fba84 ldr r6, [r0, #0x68]
 *   @0x2fba86 str r3, [sp, #0x10]
 *   @0x2fba88 movs r3, #0x0
 *   @0x2fba8a str r3, [sp, #0x24]
 *   @0x2fba8c ldr.w r3, [r0, #0x2b8]
 *   @0x2fba90 cmp r3, #0x0
 *   @0x2fba92 bne.w 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fba96 add r7, sp, #0x20
 *   @0x2fba98 ldr.w r5, [r0, #0x204]
 *   @0x2fba9c ldr r1, [pc, #0x2cc]
 *   @0x2fba9e mov r2, r6
 *   @0x2fbaa0 mov r3, r7
 *   @0x2fbaa2 blx r5
 *   @0x2fbaa4 str r0, [sp, #0x24]
 *   @0x2fbaa6 cbnz r0, 0x2fbac0 <ps_hints_apply+0xa6c0>
 *   @0x2fbaa8 ldr.w r5, [r4, #0x204]
 *   @0x2fbaac mov r0, r4
 *   @0x2fbaae ldr r1, [pc, #0x2c0]
 *   @0x2fbab0 mov r2, r6
 *   @0x2fbab2 mov r3, r7
 *   @0x2fbab4 blx r5
 *   @0x2fbab6 str r0, [sp, #0x24]
 *   @0x2fbab8 cmp r0, #0x0
 *   @0x2fbaba bne.w 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbabe b 0x2fbad6 <ps_hints_apply+0xa6d6>
 *   @0x2fbac0 ldr.w r5, [r4, #0x204]
 *   @0x2fbac4 mov r0, r4
 *   @0x2fbac6 ldr r1, [pc, #0x2ac]
 *   @0x2fbac8 mov r2, r6
 *   @0x2fbaca mov r3, r7
 *   @0x2fbacc blx r5
 *   @0x2fbace str r0, [sp, #0x24]
 *   @0x2fbad0 cmp r0, #0x0
 *   @0x2fbad2 beq 0x2fbaa8 <ps_hints_apply+0xa6a8>
 *   @0x2fbad4 b 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbad6 mov r0, r6
 *   @0x2fbad8 bl 0x2e6940 <FT_Stream_Pos>
 *   @0x2fbadc ldr r1, [pc, #0x298]
 *   @0x2fbade add r2, sp, #0x2c
 *   @0x2fbae0 add r1, pc
 *   @0x2fbae2 add.w r1, r1, #0x100
 *   @0x2fbae6 mov r9, r0
 *   @0x2fbae8 mov r0, r6
 *   @0x2fbaea bl 0x2e7ed4 <FT_Stream_ReadFields>
 *   @0x2fbaee str r0, [sp, #0x24]
 *   @0x2fbaf0 cmp r0, #0x0
 *   @0x2fbaf2 bne.w 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbaf6 ldrh.w r3, [sp, #0x38]
 *   @0x2fbafa add.w r8, sp, #0x24
 *   @0x2fbafe ldr r0, [sp, #0x10]
 *   @0x2fbb00 movs r1, #0x50
 *   @0x2fbb02 mov r2, r8
 *   @0x2fbb04 str r3, [sp, #0x18]
 *   @0x2fbb06 ldrh.w r3, [sp, #0x32]
 *   @0x2fbb0a str r3, [sp, #0x1c]
 *   @0x2fbb0c bl 0x2e7126 <ft_mem_alloc>
 *   @0x2fbb10 ldr r3, [sp, #0x24]
 *   @0x2fbb12 str.w r0, [r4, #0x2b8]
 *   @0x2fbb16 cmp r3, #0x0
 *   @0x2fbb18 bne.w 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbb1c ldrsh.w r7, [r4, #0xe]
 *   @0x2fbb20 mov.w r10, #0xc
 *   @0x2fbb24 ldrh.w r3, [sp, #0x32]
 *   @0x2fbb28 movs r2, #0x5
 *   @0x2fbb2a mul r11, r10, r7
 *   @0x2fbb2e lsls r1, r7, #0x2
 *   @0x2fbb30 mla r2, r2, r3, r11
 *   @0x2fbb34 adds r1, #0x18
 *   @0x2fbb36 adds r2, #0x14
 *   @0x2fbb38 mla r3, r3, r1, r2
 *   @0x2fbb3c mov r2, r8
 *   @0x2fbb3e str r3, [r0, #0x10]
 *   @0x2fbb40 ldr.w r3, [r4, #0x2b8]
 *   @0x2fbb44 ldr r0, [sp, #0x10]
 *   @0x2fbb46 ldr r1, [r3, #0x10]
 *   @0x2fbb48 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2fbb4c ldr r3, [sp, #0x24]
 *   @0x2fbb4e mov r5, r0
 *   @0x2fbb50 cmp r3, #0x0
 *   @0x2fbb52 bne.w 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbb56 ldr.w r2, [r4, #0x2b8]
 *   @0x2fbb5a add.w r1, r0, #0x14
 *   @0x2fbb5e str r0, [r2, #0xc]
 *   @0x2fbb60 ldrh.w r2, [sp, #0x32]
 *   @0x2fbb64 str r7, [r0, #0x8]
 *   @0x2fbb66 str r1, [r0, #0xc]
 *   @0x2fbb68 str r2, [r0]
 *   @0x2fbb6a mov.w r2, #0xffffffff
 *   @0x2fbb6e str r2, [r0, #0x4]
 *   @0x2fbb70 movs r0, #0x18
 *   @0x2fbb72 ldrh.w r2, [sp, #0x32]
 *   @0x2fbb76 mla r2, r0, r2, r1
 *   @0x2fbb7a str r2, [r5, #0x10]
 *   @0x2fbb7c add r2, r11
 *   @0x2fbb7e cmp r3, r7
 *   @0x2fbb80 beq 0x2fbb96 <ps_hints_apply+0xa796>
 *   @0x2fbb82 mul r0, r10, r3
 *   @0x2fbb86 ldr r1, [r5, #0x10]
 *   @0x2fbb88 adds r3, #0x1
 *   @0x2fbb8a str r2, [r1, r0]
 *   @0x2fbb8c ldrh.w r1, [sp, #0x32]
 *   @0x2fbb90 add.w r2, r2, r1, lsl #2
 *   @0x2fbb94 b 0x2fbb7e <ps_hints_apply+0xa77e>
 *   @0x2fbb96 movs r3, #0x0
 *   @0x2fbb98 mov.w lr, #0x5
 *   @0x2fbb9c mov.w r12, #0x18
 *   @0x2fbba0 ldrh.w r1, [sp, #0x32]
 *   @0x2fbba4 mla r0, lr, r3, r2
 *   @0x2fbba8 cmp r3, r1
 *   @0x2fbbaa bhs 0x2fbbba <ps_hints_apply+0xa7ba>
 *   @0x2fbbac mul r10, r12, r3
 *   @0x2fbbb0 ldr r1, [r5, #0xc]
 *   @0x2fbbb2 adds r3, #0x1
 *   @0x2fbbb4 str.w r0, [r1, r10]
 *   @0x2fbbb8 b 0x2fbba0 <ps_hints_apply+0xa7a0>
 *   @0x2fbbba ldrh.w r1, [sp, #0x30]
 *   @0x2fbbbe mov r0, r6
 *   @0x2fbbc0 add r1, r9
 *   @0x2fbbc2 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2fbbc6 str r0, [sp, #0x24]
 *   @0x2fbbc8 cmp r0, #0x0
 *   @0x2fbbca bne.w 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbbce ldr.w r10, [pc, #0x1ac]
 *   @0x2fbbd2 add.w r11, sp, #0x3c
 *   @0x2fbbd6 ldr r3, [r5, #0xc]
 *   @0x2fbbd8 mov r9, r0
 *   @0x2fbbda add r10, pc
 *   @0x2fbbdc adds r3, #0x18
 *   @0x2fbbde add.w r10, r10, #0x124
 *   @0x2fbbe2 ldrh.w lr, [sp, #0x32]
 *   @0x2fbbe6 cmp r9, lr
 *   @0x2fbbe8 bhs 0x2fbc72 <ps_hints_apply+0xa872>
 *   @0x2fbbea mov r0, r6
 *   @0x2fbbec mov r1, r10
 *   @0x2fbbee mov r2, r11
 *   @0x2fbbf0 str r3, [sp, #0x8]
 *   @0x2fbbf2 bl 0x2e7ed4 <FT_Stream_ReadFields>
 *   @0x2fbbf6 ldr r3, [sp, #0x8]
 *   @0x2fbbf8 str r0, [sp, #0x24]
 *   @0x2fbbfa cmp r0, #0x0
 *   @0x2fbbfc bne.w 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbc00 ldr r2, [sp, #0x3c]
 *   @0x2fbc02 str r2, [r3, #-8]
 *   @0x2fbc06 lsrs r2, r2, #0x18
 *   @0x2fbc08 ldr r1, [sp, #0x40]
 *   @0x2fbc0a str r1, [r3, #-20]
 *   @0x2fbc0e ldr r1, [sp, #0x44]
 *   @0x2fbc10 str r1, [r3, #-16]
 *   @0x2fbc14 ldr r1, [sp, #0x48]
 *   @0x2fbc16 str r1, [r3, #-12]
 *   @0x2fbc1a ldrh.w r1, [sp, #0x4e]
 *   @0x2fbc1e str r1, [r3, #-4]
 *   @0x2fbc22 ldr r1, [r3, #-24]
 *   @0x2fbc26 strb r2, [r1]
 *   @0x2fbc28 ldr r2, [r3, #-24]
 *   @0x2fbc2c ldrh r1, [r3, #-6]
 *   @0x2fbc30 strb r1, [r2, #0x1]
 *   @0x2fbc32 ldr r2, [r3, #-24]
 *   @0x2fbc36 ldr r1, [r3, #-8]
 *   @0x2fbc3a lsrs r1, r1, #0x8
 *   @0x2fbc3c strb r1, [r2, #0x2]
 *   @0x2fbc3e ldr r2, [r3, #-24]
 *   @0x2fbc42 ldr r1, [r3, #-8]
 *   @0x2fbc46 strb r1, [r2, #0x3]
 *   @0x2fbc48 ldr r2, [r3, #-24]
 *   @0x2fbc4c strb r0, [r2, #0x4]
 *   @0x2fbc4e ldr r2, [r3, #-16]
 *   @0x2fbc52 ldr r1, [r3, #-20]
 *   @0x2fbc56 cmp r1, r2
 *   @0x2fbc58 bgt 0x2fbc62 <ps_hints_apply+0xa862>
 *   @0x2fbc5a ldr r1, [r3, #-12]
 *   @0x2fbc5e cmp r2, r1
 *   @0x2fbc60 ble 0x2fbc6a <ps_hints_apply+0xa86a>
 *   @0x2fbc62 str r2, [r3, #-20]
 *   @0x2fbc66 str r2, [r3, #-12]
 *   @0x2fbc6a add.w r9, r9, #0x1
 *   @0x2fbc6e adds r3, #0x18
 *   @0x2fbc70 b 0x2fbbe2 <ps_hints_apply+0xa7e2>
 *   @0x2fbc72 ldr.w r9, [r4, #0x2b8]
 *   @0x2fbc76 movs r2, #0x0
 *   @0x2fbc78 mul r3, r7, lr
 *   @0x2fbc7c stm.w sp, {r2, r8}
 *   @0x2fbc80 ldr r0, [sp, #0x10]
 *   @0x2fbc82 movs r1, #0x4
 *   @0x2fbc84 bl 0x2e808e <ft_mem_realloc>
 *   @0x2fbc88 ldr r3, [sp, #0x24]
 *   @0x2fbc8a str.w r0, [r9, #0x14]
 *   @0x2fbc8e cmp r3, #0x0
 *   @0x2fbc90 bne.w 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbc94 ldrh.w r3, [sp, #0x36]
 *   @0x2fbc98 cbz r3, 0x2fbca8 <ps_hints_apply+0xa8a8>
 *   @0x2fbc9a ldr.w r3, [r4, #0x2b8]
 *   @0x2fbc9e ldrb r3, [r3, #0x18]
 *   @0x2fbca0 cbnz r3, 0x2fbca8 <ps_hints_apply+0xa8a8>
 *   @0x2fbca2 mov r0, r4
 *   @0x2fbca4 bl 0x2fad48 <ps_hints_apply+0x9948>
 *   @0x2fbca8 ldr r3, [sp, #0x1c]
 *   @0x2fbcaa mov.w r9, #0x0
 *   @0x2fbcae lsl.w r11, r3, #0x2
 *   @0x2fbcb2 ldr r3, [sp, #0x18]
 *   @0x2fbcb4 add.w r11, r11, #0x6
 *   @0x2fbcb8 subs.w r3, r3, r11
 *   @0x2fbcbc rsbs.w r11, r3, #0x0
 *   @0x2fbcc0 adcs.w r11, r11, r3
 *   @0x2fbcc4 ldr.w r3, [r4, #0x2b8]
 *   @0x2fbcc8 ldr.w r10, [r3, #0x14]
 *   @0x2fbccc ldr r3, [r5, #0x10]
 *   @0x2fbcce add.w r8, r3, #0xc
 *   @0x2fbcd2 ldrh.w r3, [sp, #0x36]
 *   @0x2fbcd6 cmp r9, r3
 *   @0x2fbcd8 bhs 0x2fbd80 <ps_hints_apply+0xa980>
 *   @0x2fbcda ldrh.w r1, [sp, #0x32]
 *   @0x2fbcde cmp.w r11, #0x0
 *   @0x2fbce2 ite eq
 *   @0x2fbce4 moveq r3, #0x4
 *   @0x2fbce6 movne r3, #0x6
 *   @0x2fbce8 mov r0, r6
 *   @0x2fbcea add.w r1, r3, r1, lsl #2
 *   @0x2fbcee bl 0x2e7e22 <FT_Stream_EnterFrame>
 *   @0x2fbcf2 mov r3, r0
 *   @0x2fbcf4 str r0, [sp, #0x24]
 *   @0x2fbcf6 cmp r0, #0x0
 *   @0x2fbcf8 bne.w 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbcfc mov r0, r6
 *   @0x2fbcfe str r3, [sp, #0x8]
 *   @0x2fbd00 bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2fbd04 str r0, [r8, #-8]
 *   @0x2fbd08 mov r0, r6
 *   @0x2fbd0a bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2fbd0e ldr r2, [r8, #-12]
 *   @0x2fbd12 ldr r3, [sp, #0x8]
 *   @0x2fbd14 ldrh.w r1, [sp, #0x32]
 *   @0x2fbd18 cmp r3, r1
 *   @0x2fbd1a bhs 0x2fbd32 <ps_hints_apply+0xa932>
 *   @0x2fbd1c mov r0, r6
 *   @0x2fbd1e str r2, [sp, #0xc]
 *   @0x2fbd20 str r3, [sp, #0x8]
 *   @0x2fbd22 bl 0x2e6a5a <FT_Stream_GetULong>
 *   @0x2fbd26 ldr r3, [sp, #0x8]
 *   @0x2fbd28 ldr r2, [sp, #0xc]
 *   @0x2fbd2a str.w r0, [r2, r3, lsl #2]
 *   @0x2fbd2e adds r3, #0x1
 *   @0x2fbd30 b 0x2fbd14 <ps_hints_apply+0xa914>
 *   @0x2fbd32 cmp.w r11, #0x0
 *   @0x2fbd36 beq 0x2fbd42 <ps_hints_apply+0xa942>
 *   @0x2fbd38 mov r0, r6
 *   @0x2fbd3a bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2fbd3e str r0, [r8, #-4]
 *   @0x2fbd42 ldr r2, [r8, #-12]
 *   @0x2fbd46 mov r3, r10
 *   @0x2fbd48 ldr.w r0, [r4, #0x2b8]
 *   @0x2fbd4c add.w r9, r9, #0x1
 *   @0x2fbd50 ldrh.w r1, [sp, #0x32]
 *   @0x2fbd54 add.w r8, r8, #0xc
 *   @0x2fbd58 bl 0x2fb97a <ps_hints_apply+0xa57a>
 *   @0x2fbd5c ldrh.w r3, [sp, #0x32]
 *   @0x2fbd60 mov r0, r6
 *   @0x2fbd62 add.w r10, r10, r3, lsl #2
 *   @0x2fbd66 bl 0x2e7eb8 <FT_Stream_ExitFrame>
 *   @0x2fbd6a b 0x2fbcd2 <ps_hints_apply+0xa8d2>
 *   @0x2fbd6c str r2, [r6, #0x14]
 *   @0x2fbd6e str r6, [r6, #0x74]
 *   @0x2fbd70 str r2, [r6, #0x14]
 *   @0x2fbd72 str r6, [r6, #0x64]
 *   @0x2fbd74 mov r2, r6
 *   @0x2fbd76 muls r6, r0, r6
 *   @0x2fbd78 add r4, r4
 *   @0x2fbd7a movs r2, r1
 *   @0x2fbd7c orrs r2, r5
 *   @0x2fbd7e movs r2, r1
 *   @0x2fbd80 cmp r7, r3
 *   @0x2fbd82 add r7, sp, #0x3c
 *   @0x2fbd84 beq 0x2fbdb6 <ps_hints_apply+0xa9b6>
 *   @0x2fbd86 ldr.w r9, [r4, #0x21c]
 *   @0x2fbd8a add.w r8, sp, #0x28
 *   @0x2fbd8e mov r0, r4
 *   @0x2fbd90 movs r1, #0x11
 *   @0x2fbd92 mov r2, r8
 *   @0x2fbd94 mov r3, r7
 *   @0x2fbd96 ldr.w r6, [r9, #0x78]
 *   @0x2fbd9a blx r6
 *   @0x2fbd9c cmp r0, #0x0
 *   @0x2fbd9e bne.w 0x2fc00c <ps_hints_apply+0xac0c>
 *   @0x2fbda2 ldr.w r6, [r9, #0x78]
 *   @0x2fbda6 mov r0, r4
 *   @0x2fbda8 movs r1, #0x2
 *   @0x2fbdaa mov r2, r8
 *   @0x2fbdac mov r3, r7
 *   @0x2fbdae blx r6
 *   @0x2fbdb0 cmp r0, #0x0
 *   @0x2fbdb2 bne.w 0x2fc010 <ps_hints_apply+0xac10>
 *   @0x2fbdb6 ldr r5, [r4, #0x68]
 *   @0x2fbdb8 mov r0, r4
 *   @0x2fbdba ldr.w r6, [r4, #0x204]
 *   @0x2fbdbe mov r3, r7
 *   @0x2fbdc0 ldr r1, [pc, #0x290]
 *   @0x2fbdc2 mov r2, r5
 *   @0x2fbdc4 ldr.w r9, [r5, #0x1c]
 *   @0x2fbdc8 ldr.w r8, [r4, #0x2b8]
 *   @0x2fbdcc blx r6
 *   @0x2fbdce str r0, [sp, #0x28]
 *   @0x2fbdd0 cmp r0, #0x0
 *   @0x2fbdd2 bne.w 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbdd6 mov r0, r5
 *   @0x2fbdd8 add r6, sp, #0x28
 *   @0x2fbdda bl 0x2e6940 <FT_Stream_Pos>
 *   @0x2fbdde mov r1, r6
 *   @0x2fbde0 mov r10, r0
 *   @0x2fbde2 mov r0, r5
 *   @0x2fbde4 bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2fbde8 ldr r3, [sp, #0x28]
 *   @0x2fbdea mov r7, r0
 *   @0x2fbdec cmp r3, #0x0
 *   @0x2fbdee bne.w 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbdf2 mov r0, r5
 *   @0x2fbdf4 movs r1, #0x2
 *   @0x2fbdf6 bl 0x2e6930 <FT_Stream_Skip>
 *   @0x2fbdfa str r0, [sp, #0x28]
 *   @0x2fbdfc cmp r0, #0x0
 *   @0x2fbdfe bne.w 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe02 cmp r7, #0x1
 *   @0x2fbe04 bne.w 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe08 mov r0, r9
 *   @0x2fbe0a movs r1, #0x1c
 *   @0x2fbe0c mov r2, r6
 *   @0x2fbe0e bl 0x2e7126 <ft_mem_alloc>
 *   @0x2fbe12 str.w r0, [r8, #0x38]
 *   @0x2fbe16 ldr r3, [sp, #0x28]
 *   @0x2fbe18 cmp r3, #0x0
 *   @0x2fbe1a bne.w 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe1e mov r0, r5
 *   @0x2fbe20 movs r1, #0x4
 *   @0x2fbe22 bl 0x2e6930 <FT_Stream_Skip>
 *   @0x2fbe26 str r0, [sp, #0x28]
 *   @0x2fbe28 cmp r0, #0x0
 *   @0x2fbe2a bne.w 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe2e mov r0, r5
 *   @0x2fbe30 mov r1, r6
 *   @0x2fbe32 ldr.w r7, [r8, #0x38]
 *   @0x2fbe36 bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2fbe3a strh r0, [r7]
 *   @0x2fbe3c ldr r3, [sp, #0x28]
 *   @0x2fbe3e cmp r3, #0x0
 *   @0x2fbe40 bne 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe42 mov r0, r5
 *   @0x2fbe44 mov r1, r6
 *   @0x2fbe46 bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2fbe4a ldr r3, [sp, #0x28]
 *   @0x2fbe4c mov r11, r0
 *   @0x2fbe4e cmp r3, #0x0
 *   @0x2fbe50 bne 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe52 mov r0, r5
 *   @0x2fbe54 bl 0x2e6940 <FT_Stream_Pos>
 *   @0x2fbe58 ldr.w r2, [r8, #0x38]
 *   @0x2fbe5c add.w r1, r11, r10
 *   @0x2fbe60 adds r2, #0x4
 *   @0x2fbe62 mov r7, r0
 *   @0x2fbe64 mov r0, r4
 *   @0x2fbe66 bl 0xb84be <.text+0x14ee>
 *   @0x2fbe6a mov r2, r0
 *   @0x2fbe6c str r0, [sp, #0x28]
 *   @0x2fbe6e cmp r0, #0x0
 *   @0x2fbe70 bne 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe72 ldr.w r10, [r8, #0x38]
 *   @0x2fbe76 mov r0, r9
 *   @0x2fbe78 movs r1, #0xc
 *   @0x2fbe7a ldrh.w r3, [r10]
 *   @0x2fbe7e stm.w sp, {r2, r6}
 *   @0x2fbe82 bl 0x2e808e <ft_mem_realloc>
 *   @0x2fbe86 str.w r0, [r10, #0x18]
 *   @0x2fbe8a ldr r3, [sp, #0x28]
 *   @0x2fbe8c cmp r3, #0x0
 *   @0x2fbe8e bne 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe90 mov r0, r5
 *   @0x2fbe92 mov r1, r7
 *   @0x2fbe94 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2fbe98 str r0, [sp, #0x28]
 *   @0x2fbe9a cmp r0, #0x0
 *   @0x2fbe9c bne 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbe9e ldr.w r3, [r8, #0x38]
 *   @0x2fbea2 mov r0, r5
 *   @0x2fbea4 ldrh r1, [r3]
 *   @0x2fbea6 lsls r1, r1, #0x3
 *   @0x2fbea8 bl 0x2e7e22 <FT_Stream_EnterFrame>
 *   @0x2fbeac str r0, [sp, #0x28]
 *   @0x2fbeae cmp r0, #0x0
 *   @0x2fbeb0 bne 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbeb2 ldr.w r7, [r8, #0x38]
 *   @0x2fbeb6 mov.w r9, #0xc
 *   @0x2fbeba ldr r6, [r7, #0x18]
 *   @0x2fbebc ldrh r3, [r7]
 *   @0x2fbebe mla r9, r9, r3, r6
 *   @0x2fbec2 adds r6, #0xc
 *   @0x2fbec4 sub.w r3, r6, #0xc
 *   @0x2fbec8 cmp r9, r3
 *   @0x2fbeca bls 0x2fbf04 <ps_hints_apply+0xab04>
 *   @0x2fbecc mov r0, r5
 *   @0x2fbece bl 0x2e6a5a <FT_Stream_GetULong>
 *   @0x2fbed2 str r0, [r6, #-12]
 *   @0x2fbed6 mov r0, r5
 *   @0x2fbed8 bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2fbedc strh r0, [r6, #-8]
 *   @0x2fbee0 mov r0, r5
 *   @0x2fbee2 bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2fbee6 ldrh r2, [r6, #-8]
 *   @0x2fbeea strh r0, [r6, #-6]
 *   @0x2fbeee ldr r3, [r7, #0x4]
 *   @0x2fbef0 cmp r2, r3
 *   @0x2fbef2 bhs 0x2fbf00 <ps_hints_apply+0xab00>
 *   @0x2fbef4 ldr r3, [r7, #0x8]
 *   @0x2fbef6 lsls r2, r2, #0x4
 *   @0x2fbef8 adds r6, #0xc
 *   @0x2fbefa ldr r3, [r3, r2]
 *   @0x2fbefc cmp r0, r3
 *   @0x2fbefe blo 0x2fbec4 <ps_hints_apply+0xaac4>
 *   @0x2fbf00 movs r3, #0x8
 *   @0x2fbf02 str r3, [sp, #0x28]
 *   @0x2fbf04 mov r0, r5
 *   @0x2fbf06 bl 0x2e7eb8 <FT_Stream_ExitFrame>
 *   @0x2fbf0a ldr r3, [sp, #0x28]
 *   @0x2fbf0c cbnz r3, 0x2fbf3e <ps_hints_apply+0xab3e>
 *   @0x2fbf0e ldr.w r3, [r8, #0x38]
 *   @0x2fbf12 movs r6, #0xc
 *   @0x2fbf14 ldr r5, [r3, #0x18]
 *   @0x2fbf16 ldrh r3, [r3]
 *   @0x2fbf18 mla r6, r6, r3, r5
 *   @0x2fbf1c cmp r5, r6
 *   @0x2fbf1e bhs 0x2fbf32 <ps_hints_apply+0xab32>
 *   @0x2fbf20 mov r0, r4
 *   @0x2fbf22 ldr r1, [r5]
 *   @0x2fbf24 bl 0x2f8fb4 <ps_hints_apply+0x7bb4>
 *   @0x2fbf28 cbz r0, 0x2fbf2e <ps_hints_apply+0xab2e>
 *   @0x2fbf2a ldrh r3, [r0]
 *   @0x2fbf2c strh r3, [r5, #0x8]
 *   @0x2fbf2e adds r5, #0xc
 *   @0x2fbf30 b 0x2fbf1c <ps_hints_apply+0xab1c>
 *   @0x2fbf32 ldr.w r3, [r4, #0x2c0]
 *   @0x2fbf36 orr r3, r3, #0x100
 *   @0x2fbf3a str.w r3, [r4, #0x2c0]
 *   @0x2fbf3e ldr r3, [sp, #0x14]
 *   @0x2fbf40 cmp r3, #0x0
 *   @0x2fbf42 beq 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbf44 ldr.w r3, [r4, #0x2b8]
 *   @0x2fbf48 add r2, sp, #0x24
 *   @0x2fbf4a ldr r0, [sp, #0x10]
 *   @0x2fbf4c ldr r1, [r3, #0x10]
 *   @0x2fbf4e bl 0x2e7126 <ft_mem_alloc>
 *   @0x2fbf52 ldr r6, [sp, #0x24]
 *   @0x2fbf54 mov r5, r0
 *   @0x2fbf56 cmp r6, #0x0
 *   @0x2fbf58 bne 0x2fc004 <ps_hints_apply+0xac04>
 *   @0x2fbf5a ldr.w r3, [r4, #0x2b8]
 *   @0x2fbf5e ldr r1, [r3, #0xc]
 *   @0x2fbf60 ldr r2, [r3, #0x10]
 *   @0x2fbf62 blx 0xb65bc <memcpy@plt>
 *   @0x2fbf66 ldr r2, [r5]
 *   @0x2fbf68 add.w r3, r5, #0x14
 *   @0x2fbf6c movs r1, #0x18
 *   @0x2fbf6e str r3, [r5, #0xc]
 *   @0x2fbf70 mla r1, r1, r2, r3
 *   @0x2fbf74 ldr r3, [r5, #0x8]
 *   @0x2fbf76 movs r2, #0xc
 *   @0x2fbf78 str r1, [r5, #0x10]
 *   @0x2fbf7a mla r1, r2, r3, r1
 *   @0x2fbf7e mov r3, r6
 *   @0x2fbf80 ldr r0, [r5, #0x8]
 *   @0x2fbf82 cmp r3, r0
 *   @0x2fbf84 bhs 0x2fbf98 <ps_hints_apply+0xab98>
 *   @0x2fbf86 mul r4, r2, r3
 *   @0x2fbf8a ldr r0, [r5, #0x10]
 *   @0x2fbf8c adds r3, #0x1
 *   @0x2fbf8e str r1, [r0, r4]
 *   @0x2fbf90 ldr r0, [r5]
 *   @0x2fbf92 add.w r1, r1, r0, lsl #2
 *   @0x2fbf96 b 0x2fbf80 <ps_hints_apply+0xab80>
 *   @0x2fbf98 ldr r3, [r5, #0xc]
 *   @0x2fbf9a movs r2, #0x0
 *   @0x2fbf9c ldr.w r8, [pc, #0xc8]
 *   @0x2fbfa0 mov.w r12, #0x5
 *   @0x2fbfa4 ldr.w r9, [pc, #0xc4]
 *   @0x2fbfa8 adds r3, #0x18
 *   @0x2fbfaa ldr.w r10, [pc, #0xc4]
 *   @0x2fbfae add r8, pc
 *   @0x2fbfb0 ldr.w r11, [pc, #0xc0]
 *   @0x2fbfb4 add r9, pc
 *   @0x2fbfb6 ldr r6, [pc, #0xa0]
 *   @0x2fbfb8 add r10, pc
 *   @0x2fbfba ldr r7, [pc, #0xa0]
 *   @0x2fbfbc add r11, pc
 *   @0x2fbfbe ldr r0, [r5]
 *   @0x2fbfc0 mla r4, r12, r2, r1
 *   @0x2fbfc4 cmp r2, r0
 *   @0x2fbfc6 bhs 0x2fc000 <ps_hints_apply+0xac00>
 *   @0x2fbfc8 str r4, [r3, #-24]
 *   @0x2fbfcc ldr r0, [r3, #-8]
 *   @0x2fbfd0 ldr r4, [pc, #0x8c]
 *   @0x2fbfd2 cmp r0, r4
 *   @0x2fbfd4 bne 0x2fbfdc <ps_hints_apply+0xabdc>
 *   @0x2fbfd6 str r11, [r3, #-24]
 *   @0x2fbfda b 0x2fbffa <ps_hints_apply+0xabfa>
 *   @0x2fbfdc cmp r0, r6
 *   @0x2fbfde bne 0x2fbfe6 <ps_hints_apply+0xabe6>
 *   @0x2fbfe0 str r10, [r3, #-24]
 *   @0x2fbfe4 b 0x2fbffa <ps_hints_apply+0xabfa>
 *   @0x2fbfe6 cmp r0, r7
 *   @0x2fbfe8 bne 0x2fbff0 <ps_hints_apply+0xabf0>
 *   @0x2fbfea str r9, [r3, #-24]
 *   @0x2fbfee b 0x2fbffa <ps_hints_apply+0xabfa>
 *   @0x2fbff0 ldr r4, [pc, #0x70]
 *   @0x2fbff2 cmp r0, r4
 *   @0x2fbff4 it eq
 *   @0x2fbff6 streq r8, [r3, #-24]
 *   @0x2fbffa adds r2, #0x1
 *   @0x2fbffc adds r3, #0x18
 *   @0x2fbffe b 0x2fbfbe <ps_hints_apply+0xabbe>
 *   @0x2fc000 ldr r4, [sp, #0x14]
 *   @0x2fc002 str r5, [r4]
 *   @0x2fc004 ldr r0, [sp, #0x24]
 *   @0x2fc006 add sp, #0x54
 *   @0x2fc008 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2fc00c movs r6, #0x11
 *   @0x2fc00e b 0x2fc012 <ps_hints_apply+0xac12>
 *   @0x2fc010 movs r6, #0x2
 *   @0x2fc012 ldr.w r12, [r9, #0x78]
 *   @0x2fc016 mov r0, r4
 *   @0x2fc018 movs r1, #0x6
 *   @0x2fc01a mov r2, r8
 *   @0x2fc01c mov r3, r7
 *   @0x2fc01e blx r12
 *   @0x2fc020 cmp r0, #0x0
 *   @0x2fc022 beq.w 0x2fbdb6 <ps_hints_apply+0xa9b6>
 *   @0x2fc026 ldrh.w r3, [sp, #0x36]
 *   @0x2fc02a movs r2, #0xc
 *   @0x2fc02c ldr r1, [r5, #0x10]
 *   @0x2fc02e movs r0, #0x6
 *   @0x2fc030 muls r3, r2, r3
 *   @0x2fc032 adds r2, r1, r3
 *   @0x2fc034 str r6, [r2, #0x4]
 *   @0x2fc036 str r0, [r2, #0x8]
 *   @0x2fc038 ldr r2, [r5, #0xc]
 *   @0x2fc03a ldr r0, [r1, r3]
 *   @0x2fc03c movs r3, #0x0
 *   @0x2fc03e ldrh.w r1, [sp, #0x32]
 *   @0x2fc042 cmp r3, r1
 *   @0x2fc044 bhs.w 0x2fbdb6 <ps_hints_apply+0xa9b6>
 *   @0x2fc048 ldr r1, [r2, #0x8]
 *   @0x2fc04a adds r2, #0x18
 *   @0x2fc04c str.w r1, [r0, r3, lsl #2]
 *   @0x2fc050 adds r3, #0x1
 *   @0x2fc052 b 0x2fc03e <ps_hints_apply+0xac3e>
 *   @0x2fc054 adcs r2, r2
 *   @0x2fc056 ldr r5, [pc, #0x158]
 *   @0x2fc058 strb r0, [r5, #0x11]
 *   @0x2fc05a strb r4, [r4, #0x1d]
 *   @0x2fc05c strb r2, [r7, #0xd]
 *   @0x2fc05e ldr r0, [r6, #0x74]
 *   @0x2fc060 ldr r4, [r6, #0x4]
 *   @0x2fc062 strb r7, [r4, #0x1d]
 *   @0x2fc064 ldr r4, [r6, #0x64]
 *   @0x2fc066 strb r4, [r5, #0xd]
 *   @0x2fc068 cmp r4, #0x4d
 *   @0x2fc06a movs r1, r1
 *   @0x2fc06c cmp r4, #0x3b
 *   @0x2fc06e movs r1, r1
 *   @0x2fc070 cmp r4, #0x31
 *   @0x2fc072 movs r1, r1
 *   @0x2fc074 cmp r3, #0xbe
 *   @0x2fc076 movs r1, r1
 *   @0x2fc078 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2fc07c mov r8, r1
 *   @0x2fc07e ldr r7, [r0, #0x64]
 *   @0x2fc080 sub sp, #0x4c
 *   @0x2fc082 ldr.w r1, [r0, #0x2b8]
 *   @0x2fc086 mov r5, r0
 *   @0x2fc088 str r3, [sp, #0x24]
 *   @0x2fc08a mov r10, r2
 *   @0x2fc08c movs r3, #0x0
 *   @0x2fc08e str r7, [sp, #0x18]
 *   @0x2fc090 str r3, [sp, #0x28]
 *   @0x2fc092 strb.w r3, [r0, #0x2b5]
 *   @0x2fc096 cbz r1, 0x2fc0b2 <ps_hints_apply+0xacb2>
 *   @0x2fc098 ldr.w r4, [r5, #0x2b8]
 *   @0x2fc09c movs r7, #0x1
 *   @0x2fc09e str r7, [sp, #0x20]
 *   @0x2fc0a0 ldr.w r9, [r4, #0xc]
 *   @0x2fc0a4 ldr.w r3, [r9]
 *   @0x2fc0a8 cmp r8, r3
 *   @0x2fc0aa it hs
 *   @0x2fc0ac movhs r8, r3
 *   @0x2fc0ae movs r3, #0x0
 *   @0x2fc0b0 b 0x2fc0ca <ps_hints_apply+0xacca>
 *   @0x2fc0b2 bl 0x2fba78 <ps_hints_apply+0xa678>
 *   @0x2fc0b6 str r0, [sp, #0x28]
 *   @0x2fc0b8 cmp r0, #0x0
 *   @0x2fc0ba beq 0x2fc098 <ps_hints_apply+0xac98>
 *   @0x2fc0bc b 0x2fc4ec <ps_hints_apply+0xb0ec>
 *   @0x2fc0be ldr r7, [sp, #0x20]
 *   @0x2fc0c0 adds r3, #0x1
 *   @0x2fc0c2 cmp r2, #0x0
 *   @0x2fc0c4 it ne
 *   @0x2fc0c6 movne r7, #0x0
 *   @0x2fc0c8 str r7, [sp, #0x20]
 *   @0x2fc0ca cmp r3, r8
 *   @0x2fc0cc beq 0x2fc0e2 <ps_hints_apply+0xace2>
 *   @0x2fc0ce ldr.w r2, [r10, r3, lsl #2]
 *   @0x2fc0d2 add.w r1, r2, #0x10000
 *   @0x2fc0d6 cmp.w r1, #0x20000
 *   @0x2fc0da bls 0x2fc0be <ps_hints_apply+0xacbe>
 *   @0x2fc0dc movs r3, #0x6
 *   @0x2fc0de str r3, [sp, #0x28]
 *   @0x2fc0e0 b 0x2fc4ec <ps_hints_apply+0xb0ec>
 *   @0x2fc0e2 ldrb.w r3, [r5, #0x2b4]
 *   @0x2fc0e6 cbz r3, 0x2fc0f2 <ps_hints_apply+0xacf2>
 *   @0x2fc0e8 ldr r2, [r4, #0x4]
 *   @0x2fc0ea cmp r2, #0x0
 *   @0x2fc0ec bne.w 0x2fc2c0 <ps_hints_apply+0xaec0>
 *   @0x2fc0f0 b 0x2fc2a4 <ps_hints_apply+0xaea4>
 *   @0x2fc0f2 ldr r3, [r4, #0x48]
 *   @0x2fc0f4 cmp r3, #0x0
 *   @0x2fc0f6 bne 0x2fc0e8 <ps_hints_apply+0xace8>
 *   @0x2fc0f8 ldr r7, [r5, #0x68]
 *   @0x2fc0fa mov r0, r5
 *   @0x2fc0fc ldr.w r6, [r5, #0x204]
 *   @0x2fc100 add r3, sp, #0x30
 *   @0x2fc102 ldr r1, [r7, #0x1c]
 *   @0x2fc104 mov r2, r7
 *   @0x2fc106 str r1, [sp, #0x14]
 *   @0x2fc108 ldr r1, [pc, #0x28c]
 *   @0x2fc10a blx r6
 *   @0x2fc10c str r0, [sp, #0x2c]
 *   @0x2fc10e cmp r0, #0x0
 *   @0x2fc110 bne.w 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc114 mov r0, r7
 *   @0x2fc116 bl 0x2e6940 <FT_Stream_Pos>
 *   @0x2fc11a ldr r1, [pc, #0x280]
 *   @0x2fc11c add r2, sp, #0x34
 *   @0x2fc11e add r1, pc
 *   @0x2fc120 add.w r1, r1, #0x144
 *   @0x2fc124 str r0, [sp, #0x1c]
 *   @0x2fc126 mov r0, r7
 *   @0x2fc128 bl 0x2e7ed4 <FT_Stream_ReadFields>
 *   @0x2fc12c mov r2, r0
 *   @0x2fc12e str r0, [sp, #0x2c]
 *   @0x2fc130 cmp r0, #0x0
 *   @0x2fc132 bne.w 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc136 ldr r3, [sp, #0x34]
 *   @0x2fc138 cmp.w r3, #0x10000
 *   @0x2fc13c beq 0x2fc144 <ps_hints_apply+0xad44>
 *   @0x2fc13e movs r3, #0x8
 *   @0x2fc140 str r3, [sp, #0x2c]
 *   @0x2fc142 b 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc144 ldr r1, [r4, #0xc]
 *   @0x2fc146 ldrh.w r3, [sp, #0x38]
 *   @0x2fc14a ldrh r1, [r1]
 *   @0x2fc14c cmp r3, r1
 *   @0x2fc14e bne 0x2fc13e <ps_hints_apply+0xad3e>
 *   @0x2fc150 ldrh.w r0, [sp, #0x3a]
 *   @0x2fc154 ldr r1, [sp, #0x30]
 *   @0x2fc156 muls r3, r0, r3
 *   @0x2fc158 cmp.w r3, r1, lsr #1
 *   @0x2fc15c bhi 0x2fc13e <ps_hints_apply+0xad3e>
 *   @0x2fc15e ldrh.w r6, [sp, #0x42]
 *   @0x2fc162 ldrh.w r3, [sp, #0x40]
 *   @0x2fc166 tst.w r6, #0x1
 *   @0x2fc16a ite eq
 *   @0x2fc16c moveq r6, #0x2
 *   @0x2fc16e movne r6, #0x4
 *   @0x2fc170 muls r6, r3, r6
 *   @0x2fc172 cmp r6, r1
 *   @0x2fc174 bhi 0x2fc13e <ps_hints_apply+0xad3e>
 *   @0x2fc176 str r1, [r4, #0x4c]
 *   @0x2fc178 add r6, sp, #0x2c
 *   @0x2fc17a ldr r1, [sp, #0x44]
 *   @0x2fc17c ldr.w r11, [sp, #0x1c]
 *   @0x2fc180 str r0, [r4, #0x3c]
 *   @0x2fc182 str r3, [r4, #0x44]
 *   @0x2fc184 add r11, r1
 *   @0x2fc186 adds r3, #0x1
 *   @0x2fc188 str r2, [sp]
 *   @0x2fc18a str r6, [sp, #0x4]
 *   @0x2fc18c movs r1, #0x4
 *   @0x2fc18e ldr r0, [sp, #0x14]
 *   @0x2fc190 bl 0x2e808e <ft_mem_realloc>
 *   @0x2fc194 ldr r3, [sp, #0x2c]
 *   @0x2fc196 str r0, [r4, #0x48]
 *   @0x2fc198 cmp r3, #0x0
 *   @0x2fc19a bne 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc19c ldrh.w r3, [sp, #0x42]
 *   @0x2fc1a0 mov r0, r7
 *   @0x2fc1a2 ldr r1, [r4, #0x44]
 *   @0x2fc1a4 tst.w r3, #0x1
 *   @0x2fc1a8 add.w r1, r1, #0x1
 *   @0x2fc1ac beq 0x2fc1dc <ps_hints_apply+0xaddc>
 *   @0x2fc1ae lsls r1, r1, #0x2
 *   @0x2fc1b0 bl 0x2e7e22 <FT_Stream_EnterFrame>
 *   @0x2fc1b4 str r0, [sp, #0x2c]
 *   @0x2fc1b6 cmp r0, #0x0
 *   @0x2fc1b8 bne 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc1ba mov r3, r0
 *   @0x2fc1bc ldr r2, [r4, #0x44]
 *   @0x2fc1be cmp r3, r2
 *   @0x2fc1c0 bhi 0x2fc20c <ps_hints_apply+0xae0c>
 *   @0x2fc1c2 ldr r2, [r4, #0x48]
 *   @0x2fc1c4 mov r0, r7
 *   @0x2fc1c6 str r3, [sp, #0xc]
 *   @0x2fc1c8 str r2, [sp, #0x10]
 *   @0x2fc1ca bl 0x2e6a5a <FT_Stream_GetULong>
 *   @0x2fc1ce ldr r3, [sp, #0xc]
 *   @0x2fc1d0 ldr r2, [sp, #0x10]
 *   @0x2fc1d2 add r0, r11
 *   @0x2fc1d4 str.w r0, [r2, r3, lsl #2]
 *   @0x2fc1d8 adds r3, #0x1
 *   @0x2fc1da b 0x2fc1bc <ps_hints_apply+0xadbc>
 *   @0x2fc1dc lsls r1, r1, #0x1
 *   @0x2fc1de bl 0x2e7e22 <FT_Stream_EnterFrame>
 *   @0x2fc1e2 str r0, [sp, #0x2c]
 *   @0x2fc1e4 cmp r0, #0x0
 *   @0x2fc1e6 bne 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc1e8 mov r3, r0
 *   @0x2fc1ea ldr r2, [r4, #0x44]
 *   @0x2fc1ec cmp r3, r2
 *   @0x2fc1ee bhi 0x2fc20c <ps_hints_apply+0xae0c>
 *   @0x2fc1f0 ldr r2, [r4, #0x48]
 *   @0x2fc1f2 mov r0, r7
 *   @0x2fc1f4 str r3, [sp, #0xc]
 *   @0x2fc1f6 str r2, [sp, #0x10]
 *   @0x2fc1f8 bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2fc1fc ldr r3, [sp, #0xc]
 *   @0x2fc1fe ldr r2, [sp, #0x10]
 *   @0x2fc200 add.w r0, r11, r0, lsl #1
 *   @0x2fc204 str.w r0, [r2, r3, lsl #2]
 *   @0x2fc208 adds r3, #0x1
 *   @0x2fc20a b 0x2fc1ea <ps_hints_apply+0xadea>
 *   @0x2fc20c mov r0, r7
 *   @0x2fc20e bl 0x2e7eb8 <FT_Stream_ExitFrame>
 *   @0x2fc212 ldr r3, [r4, #0x3c]
 *   @0x2fc214 cmp r3, #0x0
 *   @0x2fc216 beq 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc218 ldrh.w lr, [sp, #0x38]
 *   @0x2fc21c movs r2, #0x0
 *   @0x2fc21e ldr r0, [sp, #0x14]
 *   @0x2fc220 movs r1, #0x4
 *   @0x2fc222 stm.w sp, {r2, r6}
 *   @0x2fc226 mul r3, r3, lr
 *   @0x2fc22a bl 0x2e808e <ft_mem_realloc>
 *   @0x2fc22e ldr r3, [sp, #0x2c]
 *   @0x2fc230 str r0, [r4, #0x40]
 *   @0x2fc232 cmp r3, #0x0
 *   @0x2fc234 bne 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc236 ldr r1, [sp, #0x3c]
 *   @0x2fc238 mov r0, r7
 *   @0x2fc23a ldr r2, [sp, #0x1c]
 *   @0x2fc23c add r1, r2
 *   @0x2fc23e bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2fc242 str r0, [sp, #0x2c]
 *   @0x2fc244 cbnz r0, 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc246 ldr r1, [r4, #0x3c]
 *   @0x2fc248 mov r0, r7
 *   @0x2fc24a ldrh.w r3, [sp, #0x38]
 *   @0x2fc24e lsls r1, r1, #0x1
 *   @0x2fc250 muls r1, r3, r1
 *   @0x2fc252 bl 0x2e7e22 <FT_Stream_EnterFrame>
 *   @0x2fc256 str r0, [sp, #0x2c]
 *   @0x2fc258 cbnz r0, 0x2fc298 <ps_hints_apply+0xae98>
 *   @0x2fc25a mov r11, r0
 *   @0x2fc25c ldr r3, [r4, #0x3c]
 *   @0x2fc25e cmp r11, r3
 *   @0x2fc260 bhs 0x2fc292 <ps_hints_apply+0xae92>
 *   @0x2fc262 movs r6, #0x0
 *   @0x2fc264 ldrh.w r3, [sp, #0x38]
 *   @0x2fc268 cmp r6, r3
 *   @0x2fc26a bhs 0x2fc28c <ps_hints_apply+0xae8c>
 *   @0x2fc26c mla r3, r3, r11, r6
 *   @0x2fc270 ldr r2, [r4, #0x40]
 *   @0x2fc272 mov r0, r7
 *   @0x2fc274 adds r6, #0x1
 *   @0x2fc276 str r2, [sp, #0x10]
 *   @0x2fc278 str r3, [sp, #0xc]
 *   @0x2fc27a bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2fc27e ldr r2, [sp, #0x10]
 *   @0x2fc280 ldr r3, [sp, #0xc]
 *   @0x2fc282 sxth r0, r0
 *   @0x2fc284 lsls r0, r0, #0x2
 *   @0x2fc286 str.w r0, [r2, r3, lsl #2]
 *   @0x2fc28a b 0x2fc264 <ps_hints_apply+0xae64>
 *   @0x2fc28c add.w r11, r11, #0x1
 *   @0x2fc290 b 0x2fc25c <ps_hints_apply+0xae5c>
 *   @0x2fc292 mov r0, r7
 *   @0x2fc294 bl 0x2e7eb8 <FT_Stream_ExitFrame>
 *   @0x2fc298 ldr r3, [sp, #0x2c]
 *   @0x2fc29a str r3, [sp, #0x28]
 *   @0x2fc29c cmp r3, #0x0
 *   @0x2fc29e beq.w 0x2fc0e8 <ps_hints_apply+0xace8>
 *   @0x2fc2a2 b 0x2fc4ec <ps_hints_apply+0xb0ec>
 *   @0x2fc2a4 str r2, [sp]
 *   @0x2fc2a6 add r3, sp, #0x28
 *   @0x2fc2a8 ldr r0, [sp, #0x18]
 *   @0x2fc2aa movs r1, #0x4
 *   @0x2fc2ac str r3, [sp, #0x4]
 *   @0x2fc2ae ldr.w r3, [r9]
 *   @0x2fc2b2 bl 0x2e808e <ft_mem_realloc>
 *   @0x2fc2b6 ldr r3, [sp, #0x28]
 *   @0x2fc2b8 str r0, [r4, #0x4]
 *   @0x2fc2ba cmp r3, #0x0
 *   @0x2fc2bc bne.w 0x2fc4ec <ps_hints_apply+0xb0ec>
 *   @0x2fc2c0 ldr r2, [r4, #0x8]
 *   @0x2fc2c2 movs r3, #0x0
 *   @0x2fc2c4 cbnz r2, 0x2fc2f4 <ps_hints_apply+0xaef4>
 *   @0x2fc2c6 str r2, [sp]
 *   @0x2fc2c8 add r3, sp, #0x28
 *   @0x2fc2ca ldr r0, [sp, #0x18]
 *   @0x2fc2cc movs r1, #0x4
 *   @0x2fc2ce str r3, [sp, #0x4]
 *   @0x2fc2d0 ldr.w r3, [r9]
 *   @0x2fc2d4 bl 0x2e808e <ft_mem_realloc>
 *   @0x2fc2d8 ldr r3, [sp, #0x28]
 *   @0x2fc2da str r0, [r4, #0x8]
 *   @0x2fc2dc cmp r3, #0x0
 *   @0x2fc2de bne.w 0x2fc4ec <ps_hints_apply+0xb0ec>
 *   @0x2fc2e2 movs r6, #0x1
 *   @0x2fc2e4 b 0x2fc312 <ps_hints_apply+0xaf12>
 *   @0x2fc2e6 ldr.w r0, [r2, r3, lsl #2]
 *   @0x2fc2ea ldr.w r1, [r10, r3, lsl #2]
 *   @0x2fc2ee cmp r0, r1
 *   @0x2fc2f0 bne 0x2fc2fc <ps_hints_apply+0xaefc>
 *   @0x2fc2f2 adds r3, #0x1
 *   @0x2fc2f4 cmp r3, r8
 *   @0x2fc2f6 bne 0x2fc2e6 <ps_hints_apply+0xaee6>
 *   @0x2fc2f8 movs r6, #0x0
 *   @0x2fc2fa b 0x2fc2fe <ps_hints_apply+0xaefe>
 *   @0x2fc2fc movs r6, #0x2
 *   @0x2fc2fe ldr.w r0, [r9]
 *   @0x2fc302 cmp r3, r0
 *   @0x2fc304 bhs 0x2fc312 <ps_hints_apply+0xaf12>
 *   @0x2fc306 ldr.w r1, [r2, r3, lsl #2]
 *   @0x2fc30a cbnz r1, 0x2fc310 <ps_hints_apply+0xaf10>
 *   @0x2fc30c adds r3, #0x1
 *   @0x2fc30e b 0x2fc302 <ps_hints_apply+0xaf02>
 *   @0x2fc310 movs r6, #0x2
 *   @0x2fc312 ldr.w r3, [r9]
 *   @0x2fc316 mov r1, r10
 *   @0x2fc318 ldr r0, [r4, #0x8]
 *   @0x2fc31a lsl.w r2, r8, #0x2
 *   @0x2fc31e str r3, [r4]
 *   @0x2fc320 blx 0xb65bc <memcpy@plt>
 *   @0x2fc324 ldr r7, [sp, #0x24]
 *   @0x2fc326 cbnz r7, 0x2fc33a <ps_hints_apply+0xaf3a>
 *   @0x2fc328 ldr.w r1, [r5, #0x298]
 *   @0x2fc32c movs r3, #0x1
 *   @0x2fc32e strb.w r3, [r5, #0x2b5]
 *   @0x2fc332 cmp r1, #0x0
 *   @0x2fc334 bne.w 0x2fc464 <ps_hints_apply+0xb064>
 *   @0x2fc338 b 0x2fc48c <ps_hints_apply+0xb08c>
 *   @0x2fc33a ldr.w r3, [r5, #0x2b8]
 *   @0x2fc33e ldrb.w r2, [r5, #0x2b5]
 *   @0x2fc342 ldr r0, [r4, #0x8]
 *   @0x2fc344 ldr r7, [r3]
 *   @0x2fc346 ldr.w r9, [r4, #0x4]
 *   @0x2fc34a cmp r8, r7
 *   @0x2fc34c it lo
 *   @0x2fc34e movlo r7, r8
 *   @0x2fc350 cbnz r2, 0x2fc356 <ps_hints_apply+0xaf56>
 *   @0x2fc352 mov r1, r2
 *   @0x2fc354 b 0x2fc36a <ps_hints_apply+0xaf6a>
 *   @0x2fc356 lsl.w lr, r7, #0x2
 *   @0x2fc35a movs r2, #0x0
 *   @0x2fc35c cmp r2, lr
 *   @0x2fc35e beq 0x2fc376 <ps_hints_apply+0xaf76>
 *   @0x2fc360 ldr r1, [r0, r2]
 *   @0x2fc362 str.w r1, [r9, r2]
 *   @0x2fc366 adds r2, #0x4
 *   @0x2fc368 b 0x2fc35c <ps_hints_apply+0xaf5c>
 *   @0x2fc36a cmp r2, r7
 *   @0x2fc36c beq 0x2fc376 <ps_hints_apply+0xaf76>
 *   @0x2fc36e str.w r1, [r9, r2, lsl #2]
 *   @0x2fc372 adds r2, #0x1
 *   @0x2fc374 b 0x2fc36a <ps_hints_apply+0xaf6a>
 *   @0x2fc376 mov r2, r7
 *   @0x2fc378 movs r1, #0x0
 *   @0x2fc37a cmp r2, r8
 *   @0x2fc37c bhs 0x2fc386 <ps_hints_apply+0xaf86>
 *   @0x2fc37e str.w r1, [r9, r2, lsl #2]
 *   @0x2fc382 adds r2, #0x1
 *   @0x2fc384 b 0x2fc37a <ps_hints_apply+0xaf7a>
 *   @0x2fc386 ldr r2, [r3, #0x1c]
 *   @0x2fc388 cbnz r2, 0x2fc3a0 <ps_hints_apply+0xafa0>
 *   @0x2fc38a ldr r3, [r3, #0xc]
 *   @0x2fc38c mov.w r10, #0x0
 *   @0x2fc390 ldr r3, [r3, #0xc]
 *   @0x2fc392 add.w r8, r3, #0x18
 *   @0x2fc396 b 0x2fc444 <ps_hints_apply+0xb044>
 *   @0x2fc398 str r2, [r6, #0x14]
 *   @0x2fc39a str r6, [r6, #0x74]
 *   @0x2fc39c subs r5, #0xe6
 *   @0x2fc39e movs r2, r1
 *   @0x2fc3a0 add.w r8, r2, #0x8
 *   @0x2fc3a4 mov r11, r9
 *   @0x2fc3a6 movs r1, #0x0
 *   @0x2fc3a8 str r1, [sp, #0x14]
 *   @0x2fc3aa ldr r1, [sp, #0x14]
 *   @0x2fc3ac cmp r1, r7
 *   @0x2fc3ae beq 0x2fc38a <ps_hints_apply+0xaf8a>
 *   @0x2fc3b0 ldrh r2, [r8, #-8]
 *   @0x2fc3b4 mov.w r10, #0x1
 *   @0x2fc3b8 cmp r10, r2
 *   @0x2fc3ba bhs 0x2fc40e <ps_hints_apply+0xb00e>
 *   @0x2fc3bc ldr r1, [r8, #-4]
 *   @0x2fc3c0 ldr.w r0, [r11]
 *   @0x2fc3c4 add.w lr, r1, r10, lsl #3
 *   @0x2fc3c8 ldr.w r12, [lr, #0x4]
 *   @0x2fc3cc cmp r0, r12
 *   @0x2fc3ce bge 0x2fc408 <ps_hints_apply+0xb008>
 *   @0x2fc3d0 add.w r10, r10, #0x20000000
 *   @0x2fc3d4 ldr.w lr, [lr]
 *   @0x2fc3d8 add.w r10, r10, #0xffffffff
 *   @0x2fc3dc add.w r2, r1, r10, lsl #3
 *   @0x2fc3e0 ldr.w r1, [r1, r10, lsl #3]
 *   @0x2fc3e4 ldr r2, [r2, #0x4]
 *   @0x2fc3e6 rsb r1, r1, lr
 *   @0x2fc3ea str r3, [sp, #0xc]
 *   @0x2fc3ec subs r0, r0, r2
 *   @0x2fc3ee rsb r2, r2, r12
 *   @0x2fc3f2 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fc3f6 ldr r2, [r8, #-4]
 *   @0x2fc3fa ldr.w r2, [r2, r10, lsl #3]
 *   @0x2fc3fe add r0, r2
 *   @0x2fc400 str.w r0, [r11]
 *   @0x2fc404 ldr r3, [sp, #0xc]
 *   @0x2fc406 b 0x2fc40e <ps_hints_apply+0xb00e>
 *   @0x2fc408 add.w r10, r10, #0x1
 *   @0x2fc40c b 0x2fc3b8 <ps_hints_apply+0xafb8>
 *   @0x2fc40e ldr r2, [sp, #0x14]
 *   @0x2fc410 add.w r8, r8, #0x8
 *   @0x2fc414 add.w r11, r11, #0x4
 *   @0x2fc418 adds r2, #0x1
 *   @0x2fc41a str r2, [sp, #0x14]
 *   @0x2fc41c b 0x2fc3aa <ps_hints_apply+0xafaa>
 *   @0x2fc41e ldr r0, [r9], #4
 *   @0x2fc422 cmp r0, #0x0
 *   @0x2fc424 bge 0x2fc44a <ps_hints_apply+0xb04a>
 *   @0x2fc426 ldr r11, [r8, #-16]
 *   @0x2fc42a ldr r1, [r8, #-20]
 *   @0x2fc42e rsb r1, r1, r11
 *   @0x2fc432 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fc436 add r0, r11
 *   @0x2fc438 str r0, [r9, #-4]
 *   @0x2fc43c add.w r10, r10, #0x1
 *   @0x2fc440 add.w r8, r8, #0x18
 *   @0x2fc444 cmp r10, r7
 *   @0x2fc446 bne 0x2fc41e <ps_hints_apply+0xb01e>
 *   @0x2fc448 b 0x2fc328 <ps_hints_apply+0xaf28>
 *   @0x2fc44a beq 0x2fc45a <ps_hints_apply+0xb05a>
 *   @0x2fc44c ldr r11, [r8, #-16]
 *   @0x2fc450 ldr r1, [r8, #-12]
 *   @0x2fc454 rsb r1, r11, r1
 *   @0x2fc458 b 0x2fc432 <ps_hints_apply+0xb032>
 *   @0x2fc45a ldr r3, [r8, #-16]
 *   @0x2fc45e str r3, [r9, #-4]
 *   @0x2fc462 b 0x2fc43c <ps_hints_apply+0xb03c>
 *   @0x2fc464 cmp r6, #0x1
 *   @0x2fc466 beq 0x2fc482 <ps_hints_apply+0xb082>
 *   @0x2fc468 cmp r6, #0x2
 *   @0x2fc46a bne 0x2fc48c <ps_hints_apply+0xb08c>
 *   @0x2fc46c ldr r0, [sp, #0x18]
 *   @0x2fc46e bl 0x2e7336 <ft_mem_free>
 *   @0x2fc472 movs r3, #0x0
 *   @0x2fc474 mov r0, r5
 *   @0x2fc476 str.w r3, [r5, #0x298]
 *   @0x2fc47a ldr r1, [r5, #0x68]
 *   @0x2fc47c bl 0x2facb4 <ps_hints_apply+0x98b4>
 *   @0x2fc480 b 0x2fc48a <ps_hints_apply+0xb08a>
 *   @0x2fc482 mov r0, r5
 *   @0x2fc484 ldr r1, [r5, #0x68]
 *   @0x2fc486 bl 0x2fa9d8 <ps_hints_apply+0x95d8>
 *   @0x2fc48a str r0, [sp, #0x28]
 *   @0x2fc48c ldr r3, [r4, #0xc]
 *   @0x2fc48e ldr.w r12, [r3, #0x8]
 *   @0x2fc492 movs r3, #0x0
 *   @0x2fc494 cmp r3, r12
 *   @0x2fc496 beq 0x2fc4bc <ps_hints_apply+0xb0bc>
 *   @0x2fc498 ldr r6, [r4]
 *   @0x2fc49a ldr r2, [r4, #0x14]
 *   @0x2fc49c ldr r0, [r4, #0x8]
 *   @0x2fc49e lsl.w lr, r6, #0x2
 *   @0x2fc4a2 mla lr, r3, lr, r2
 *   @0x2fc4a6 movs r2, #0x0
 *   @0x2fc4a8 cmp r2, r6
 *   @0x2fc4aa beq 0x2fc4bc <ps_hints_apply+0xb0bc>
 *   @0x2fc4ac ldr.w r7, [lr, r2, lsl #2]
 *   @0x2fc4b0 ldr.w r1, [r0, r2, lsl #2]
 *   @0x2fc4b4 cmp r7, r1
 *   @0x2fc4b6 bne 0x2fc4d2 <ps_hints_apply+0xb0d2>
 *   @0x2fc4b8 adds r2, #0x1
 *   @0x2fc4ba b 0x2fc4a8 <ps_hints_apply+0xb0a8>
 *   @0x2fc4bc ldrh r2, [r5, #0x4]
 *   @0x2fc4be str r2, [r5, #0x4]
 *   @0x2fc4c0 ldr r1, [r4, #0xc]
 *   @0x2fc4c2 ldr r1, [r1, #0x8]
 *   @0x2fc4c4 cmp r3, r1
 *   @0x2fc4c6 bhs 0x2fc4d6 <ps_hints_apply+0xb0d6>
 *   @0x2fc4c8 adds r3, #0x1
 *   @0x2fc4ca orr.w r2, r2, r3, lsl #16
 *   @0x2fc4ce str r2, [r5, #0x4]
 *   @0x2fc4d0 b 0x2fc4d6 <ps_hints_apply+0xb0d6>
 *   @0x2fc4d2 adds r3, #0x1
 *   @0x2fc4d4 b 0x2fc494 <ps_hints_apply+0xb094>
 *   @0x2fc4d6 ldr r7, [sp, #0x20]
 *   @0x2fc4d8 ldr r0, [sp, #0x18]
 *   @0x2fc4da ldr.w r1, [r5, #0x2a8]
 *   @0x2fc4de strb.w r7, [r5, #0x2bc]
 *   @0x2fc4e2 bl 0x2e7336 <ft_mem_free>
 *   @0x2fc4e6 movs r3, #0x0
/* ═══════════════════════════════════════════════════════════════════════
 * §6  anon_thumb_2e90fc   0x2e90fc..0x2e9396   666 B / 280 条   in-degree 3
 * FreeType ftobjs.c 的 open_face 下家（666 B / 3 个 bl 入口）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 3 条 Thumb `bl` 指向本段起始：anon_2e90fc 父区×3（0x2e9322 在窗口内，0x2e958a / 0x2e96ac 在窗口外）；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 20 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} / sub sp, #0x2c / mov r7, r0（帧：sub sp, 0x2c）；窗口内出口 2 个
 * 结构：入口可达 162 B / 68 条（24%）；段内 bl 入口 2 个：0x2e91a4(418 B/134 条) / 0x2e935c(898 B/22 条)
 *      可打印岛：无 ≥16 B 的
 * 反向的 3 处 bl 都在父区 0x2e90fc+1,520 B 的范围内：0x2e9322 落在本卡窗口内（第 2 个 bl 入口
 *      0x2e91a4 的体内），0x2e958a / 0x2e96ac 在窗口外；本段的锚是**正向**：20 处 bl 打向具名 Thumb（ft_mem_alloc、FT_Stream_OpenMemory、
 *      FT_Stream_Seek/Close、FT_Get_Module…）。段内 2 个 bl 入口：0x2e91a4(418 B) / 0x2e935c(898 B)。
 *
 * 锚点：280 条（= asm/index-anonT_2e90fc.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2e90fc push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e9100 sub sp, #0x2c
 *   @0x2e9102 mov r7, r0
 *   @0x2e9104 mov r5, r2
 *   @0x2e9106 mov r11, r3
 *   @0x2e9108 ldr.w r10, [sp, #0x50]
 *   @0x2e910c ldr r6, [r0]
 *   @0x2e910e mov r8, r1
 *   @0x2e9110 cbz r1, 0x2e913e <FT_New_Face+0x66>
 *   @0x2e9112 add.w r9, sp, #0x8
 *   @0x2e9116 mov r0, r6
 *   @0x2e9118 movs r1, #0x28
 *   @0x2e911a mov r2, r9
 *   @0x2e911c bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e9120 ldr r2, [sp, #0x8]
 *   @0x2e9122 mov r4, r0
 *   @0x2e9124 cbnz r2, 0x2e9136 <FT_New_Face+0x5e>
 *   @0x2e9126 mov r2, r5
 *   @0x2e9128 mov r1, r8
 *   @0x2e912a bl 0x2e688a <FT_Stream_OpenMemory>
 *   @0x2e912e ldr r2, [pc, #0x70]
 *   @0x2e9130 add r2, pc
 *   @0x2e9132 str r2, [r4, #0x18]
 *   @0x2e9134 b 0x2e9138 <FT_New_Face+0x60>
 *   @0x2e9136 movs r4, #0x0
 *   @0x2e9138 ldr r5, [sp, #0x8]
 *   @0x2e913a cbz r5, 0x2e914a <FT_New_Face+0x72>
 *   @0x2e913c b 0x2e9140 <FT_New_Face+0x68>
 *   @0x2e913e movs r5, #0x6
 *   @0x2e9140 mov r0, r6
 *   @0x2e9142 mov r1, r8
 *   @0x2e9144 bl 0x2e7336 <ft_mem_free>
 *   @0x2e9148 b 0x2e9196 <FT_New_Face+0xbe>
 *   @0x2e914a movs r3, #0x2
 *   @0x2e914c str r4, [sp, #0x18]
 *   @0x2e914e str r3, [sp, #0x8]
 *   @0x2e9150 cmp.w r10, #0x0
 *   @0x2e9154 beq 0x2e9164 <FT_New_Face+0x8c>
 *   @0x2e9156 mov r0, r7
 *   @0x2e9158 mov r1, r10
 *   @0x2e915a movs r3, #0xa
 *   @0x2e915c str r3, [sp, #0x8]
 *   @0x2e915e bl 0x2e5ef0 <FT_Get_Module>
 *   @0x2e9162 str r0, [sp, #0x1c]
 *   @0x2e9164 movs r3, #0x0
 *   @0x2e9166 mov r0, r7
 *   @0x2e9168 str r3, [sp]
 *   @0x2e916a mov r1, r9
 *   @0x2e916c mov r2, r11
 *   @0x2e916e ldr r3, [sp, #0x54]
 *   @0x2e9170 bl 0x2e8c38 <FT_Done_Face+0x5c>
 *   @0x2e9174 mov r7, r0
 *   @0x2e9176 cbnz r0, 0x2e9186 <FT_New_Face+0xae>
 *   @0x2e9178 ldr r2, [sp, #0x54]
 *   @0x2e917a ldr r3, [r2]
 *   @0x2e917c ldr r2, [r3, #0x8]
 *   @0x2e917e bic r2, r2, #0x400
 *   @0x2e9182 str r2, [r3, #0x8]
 *   @0x2e9184 b 0x2e9196 <FT_New_Face+0xbe>
 *   @0x2e9186 mov r0, r4
 *   @0x2e9188 mov r5, r7
 *   @0x2e918a bl 0x2e689a <FT_Stream_Close>
 *   @0x2e918e mov r0, r6
 *   @0x2e9190 mov r1, r4
 *   @0x2e9192 bl 0x2e7336 <ft_mem_free>
 *   @0x2e9196 mov r0, r5
 *   @0x2e9198 add sp, #0x2c
 *   @0x2e919a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e919e nop
 *   @0x2e91a0 sbcs.w pc, sp, pc, ror #31
 *   @0x2e91a4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e91a8 sub sp, #0x2c
 *   @0x2e91aa subs r5, r2, #0x0
 *   @0x2e91ac mov r4, r1
 *   @0x2e91ae str r3, [sp, #0x1c]
 *   @0x2e91b0 it gt
 *   @0x2e91b2 uxthgt r5, r5
 *   @0x2e91b4 ldr r3, [r0]
 *   @0x2e91b6 add r6, sp, #0x24
 *   @0x2e91b8 str r0, [sp, #0x14]
 *   @0x2e91ba mov r0, r1
 *   @0x2e91bc str r3, [sp, #0x8]
 *   @0x2e91be bl 0x2e6940 <FT_Stream_Pos>
 *   @0x2e91c2 mov r1, r6
 *   @0x2e91c4 str r0, [sp, #0xc]
 *   @0x2e91c6 mov r0, r4
 *   @0x2e91c8 bl 0x2e6dc4 <FT_Stream_ReadULong>
 *   @0x2e91cc ldr r7, [sp, #0x24]
 *   @0x2e91ce cmp r7, #0x0
 *   @0x2e91d0 bne 0x2e9292 <FT_New_Face+0x1ba>
 *   @0x2e91d2 ldr r3, [pc, #0x174]
 *   @0x2e91d4 cmp r0, r3
 *   @0x2e91d6 bne 0x2e929e <FT_New_Face+0x1c6>
 *   @0x2e91d8 mov r0, r4
 *   @0x2e91da mov r1, r6
 *   @0x2e91dc bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2e91e0 ldr.w r8, [sp, #0x24]
 *   @0x2e91e4 str r0, [sp, #0x18]
 *   @0x2e91e6 cmp.w r8, #0x0
 *   @0x2e91ea bne 0x2e92a8 <FT_New_Face+0x1d0>
 *   @0x2e91ec mov r0, r4
 *   @0x2e91ee movs r1, #0x6
 *   @0x2e91f0 bl 0x2e6930 <FT_Stream_Skip>
 *   @0x2e91f4 str r0, [sp, #0x24]
 *   @0x2e91f6 cmp r0, #0x0
 *   @0x2e91f8 bne 0x2e9294 <FT_New_Face+0x1bc>
 *   @0x2e91fa mov r9, r0
 *   @0x2e91fc mov r10, r0
 *   @0x2e91fe mov r11, r0
 *   @0x2e9200 mov r8, r0
 *   @0x2e9202 mov.w r7, #0xffffffff
 *   @0x2e9206 ldr r2, [sp, #0x18]
 *   @0x2e9208 cmp r8, r2
 *   @0x2e920a bge 0x2e928e <FT_New_Face+0x1b6>
 *   @0x2e920c mov r1, r6
 *   @0x2e920e mov r0, r4
 *   @0x2e9210 bl 0x2e6dc4 <FT_Stream_ReadULong>
 *   @0x2e9214 ldr r1, [sp, #0x24]
 *   @0x2e9216 str r0, [sp, #0x10]
 *   @0x2e9218 cbnz r1, 0x2e9242 <FT_New_Face+0x16a>
 *   @0x2e921a mov r0, r4
 *   @0x2e921c movs r1, #0x4
 *   @0x2e921e bl 0x2e6930 <FT_Stream_Skip>
 *   @0x2e9222 str r0, [sp, #0x24]
 *   @0x2e9224 cbnz r0, 0x2e9242 <FT_New_Face+0x16a>
 *   @0x2e9226 mov r1, r6
 *   @0x2e9228 mov r0, r4
 *   @0x2e922a bl 0x2e6dc4 <FT_Stream_ReadULong>
 *   @0x2e922e ldr r1, [sp, #0x24]
 *   @0x2e9230 mov r11, r0
 *   @0x2e9232 cbnz r1, 0x2e9242 <FT_New_Face+0x16a>
 *   @0x2e9234 mov r0, r4
 *   @0x2e9236 mov r1, r6
 *   @0x2e9238 bl 0x2e6dc4 <FT_Stream_ReadULong>
 *   @0x2e923c mov r10, r0
 *   @0x2e923e ldr r0, [sp, #0x24]
 *   @0x2e9240 cbz r0, 0x2e9246 <FT_New_Face+0x16e>
 *   @0x2e9242 ldr r0, [sp, #0x24]
 *   @0x2e9244 b 0x2e92b0 <FT_New_Face+0x1d8>
 *   @0x2e9246 ldr r2, [sp, #0x10]
 *   @0x2e9248 ldr r3, [pc, #0x100]
 *   @0x2e924a cmp r2, r3
 *   @0x2e924c bne 0x2e9264 <FT_New_Face+0x18c>
 *   @0x2e924e cmp r5, #0x0
 *   @0x2e9250 add.w r7, r7, #0x1
 *   @0x2e9254 add.w r11, r11, #0x16
 *   @0x2e9258 sub.w r10, r10, #0x16
 *   @0x2e925c mov.w r9, #0x1
 *   @0x2e9260 bge 0x2e9284 <FT_New_Face+0x1ac>
 *   @0x2e9262 b 0x2e92b0 <FT_New_Face+0x1d8>
 *   @0x2e9264 ldr r2, [sp, #0x10]
 *   @0x2e9266 ldr r3, [pc, #0xe8]
 *   @0x2e9268 cmp r2, r3
 *   @0x2e926a bne 0x2e9280 <FT_New_Face+0x1a8>
 *   @0x2e926c cmp r5, #0x0
 *   @0x2e926e add.w r7, r7, #0x1
 *   @0x2e9272 add.w r11, r11, #0x18
 *   @0x2e9276 sub.w r10, r10, #0x18
 *   @0x2e927a mov r9, r0
 *   @0x2e927c bge 0x2e9284 <FT_New_Face+0x1ac>
 *   @0x2e927e b 0x2e92ac <FT_New_Face+0x1d4>
 *   @0x2e9280 cmp r5, #0x0
 *   @0x2e9282 blt 0x2e9288 <FT_New_Face+0x1b0>
 *   @0x2e9284 cmp r7, r5
 *   @0x2e9286 beq 0x2e92ae <FT_New_Face+0x1d6>
 *   @0x2e9288 add.w r8, r8, #0x1
 *   @0x2e928c b 0x2e9206 <FT_New_Face+0x12e>
 *   @0x2e928e movs r0, #0x8e
 *   @0x2e9290 b 0x2e92b0 <FT_New_Face+0x1d8>
 *   @0x2e9292 mov r0, r7
 *   @0x2e9294 mov.w r9, #0x0
 *   @0x2e9298 mov r10, r9
 *   @0x2e929a mov r11, r9
 *   @0x2e929c b 0x2e92b0 <FT_New_Face+0x1d8>
 *   @0x2e929e mov r9, r7
 *   @0x2e92a0 mov r10, r7
 *   @0x2e92a2 mov r11, r7
 *   @0x2e92a4 movs r0, #0x2
 *   @0x2e92a6 b 0x2e92b0 <FT_New_Face+0x1d8>
 *   @0x2e92a8 mov r0, r8
 *   @0x2e92aa b 0x2e9294 <FT_New_Face+0x1bc>
 *   @0x2e92ac b 0x2e92b0 <FT_New_Face+0x1d8>
 *   @0x2e92ae movs r0, #0x0
 *   @0x2e92b0 str r0, [sp, #0x24]
 *   @0x2e92b2 cmp r0, #0x0
 *   @0x2e92b4 bne 0x2e9328 <FT_New_Face+0x250>
 *   @0x2e92b6 ldr r1, [r4, #0x4]
 *   @0x2e92b8 cmp r11, r1
 *   @0x2e92ba bls 0x2e92c2 <FT_New_Face+0x1ea>
 *   @0x2e92bc movs r3, #0x8
 *   @0x2e92be str r3, [sp, #0x24]
 *   @0x2e92c0 b 0x2e9328 <FT_New_Face+0x250>
 *   @0x2e92c2 rsb r1, r11, r1
 *   @0x2e92c6 cmp r10, r1
 *   @0x2e92c8 bhi 0x2e92bc <FT_New_Face+0x1e4>
 *   @0x2e92ca ldr r1, [sp, #0xc]
 *   @0x2e92cc mov r0, r4
 *   @0x2e92ce add r1, r11
 *   @0x2e92d0 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e92d4 str r0, [sp, #0x24]
 *   @0x2e92d6 cbnz r0, 0x2e9328 <FT_New_Face+0x250>
 *   @0x2e92d8 mov r2, r6
 *   @0x2e92da ldr r0, [sp, #0x8]
 *   @0x2e92dc mov r1, r10
 *   @0x2e92de bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e92e2 ldr r2, [sp, #0x24]
 *   @0x2e92e4 mov r6, r0
 *   @0x2e92e6 cbnz r2, 0x2e9328 <FT_New_Face+0x250>
 *   @0x2e92e8 mov r0, r4
 *   @0x2e92ea mov r1, r6
 *   @0x2e92ec mov r2, r10
 *   @0x2e92ee bl 0x2e698e <FT_Stream_Read>
 *   @0x2e92f2 str r0, [sp, #0x24]
 *   @0x2e92f4 cbz r0, 0x2e9300 <FT_New_Face+0x228>
 *   @0x2e92f6 ldr r0, [sp, #0x8]
 *   @0x2e92f8 mov r1, r6
 *   @0x2e92fa bl 0x2e7336 <ft_mem_free>
 *   @0x2e92fe b 0x2e9328 <FT_New_Face+0x250>
 *   @0x2e9300 and.w r5, r5, r5, asr #31
 *   @0x2e9304 cmp.w r9, #0x0
 *   @0x2e9308 beq 0x2e9310 <FT_New_Face+0x238>
 *   @0x2e930a ldr r2, [pc, #0x48]
 *   @0x2e930c add r2, pc
 *   @0x2e930e b 0x2e9314 <FT_New_Face+0x23c>
 *   @0x2e9310 ldr r2, [pc, #0x44]
 *   @0x2e9312 add r2, pc
 *   @0x2e9314 ldr r3, [sp, #0x1c]
 *   @0x2e9316 mov r1, r6
 *   @0x2e9318 str r2, [sp]
 *   @0x2e931a mov r2, r10
 *   @0x2e931c ldr r0, [sp, #0x14]
 *   @0x2e931e str r3, [sp, #0x4]
 *   @0x2e9320 mov r3, r5
 *   @0x2e9322 bl 0x2e90fc <FT_New_Face+0x24>
 *   @0x2e9326 str r0, [sp, #0x24]
 *   @0x2e9328 ldrb.w r3, [sp, #0x24]
 *   @0x2e932c cmp r3, #0x2
 *   @0x2e932e beq 0x2e9334 <FT_New_Face+0x25c>
 *   @0x2e9330 ldr r0, [sp, #0x24]
 *   @0x2e9332 b 0x2e9340 <FT_New_Face+0x268>
 *   @0x2e9334 mov r0, r4
 *   @0x2e9336 ldr r1, [sp, #0xc]
 *   @0x2e9338 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e933c cmp r0, #0x0
 *   @0x2e933e beq 0x2e9330 <FT_New_Face+0x258>
 *   @0x2e9340 add sp, #0x2c
 *   @0x2e9342 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e9346 nop
 *   @0x2e9348 strb r1, [r6]
 *   @0x2e934a strb r1, [r7, #0x11]
 *   @0x2e934c add r0, r4
 *   @0x2e934e muls r1, r1, r1
 *   @0x2e9350 str r1, [r6, r0]
 *   @0x2e9352 strb r1, [r3, r1]
 *   @0x2e9354 strb r1, [r6, r1]
 *   @0x2e9356 movs r2, r1
 *   @0x2e9358 strb r7, [r5, r1]
 *   @0x2e935a movs r2, r1
 *   @0x2e935c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e9360 mov r6, r3
 *   @0x2e9362 ldr r3, [r0]
 *   @0x2e9364 sub sp, #0x4c
 *   @0x2e9366 mov r8, r0
 *   @0x2e9368 mov r5, r1
 *   @0x2e936a str r3, [sp, #0x20]
 *   @0x2e936c add r3, sp, #0x38
 *   @0x2e936e str r3, [sp]
 *   @0x2e9370 add r3, sp, #0x34
 *   @0x2e9372 bl 0x2e6b50 <FT_Raccess_Get_HeaderInfo>
 *   @0x2e9376 mov r7, r0
 *   @0x2e9378 cmp r0, #0x0
 *   @0x2e937a bne.w 0x2e96d0 <FT_New_Face+0x5f8>
 *   @0x2e937e ldr r3, [pc, #0x278]
 *   @0x2e9380 movs r4, #0x1
 *   @0x2e9382 add.w r11, sp, #0x3c
 *   @0x2e9386 add.w r10, sp, #0x40
 *   @0x2e938a str.w r11, [sp, #0x8]
 *   @0x2e938e mov r0, r8
 *   @0x2e9390 stm.w sp, {r3, r4}
 *   @0x2e9394 mov r1, r5
/* ═══════════════════════════════════════════════════════════════════════
 * §7  anon_thumb_2fb68c   0x2fb68c..0x2fb892   518 B / 182 条   in-degree 3
 * TrueType 解释器带的小件（518 B 窗口 / 3 个 bl 入口）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 3 条 Thumb `bl` 指向本段起始：TT_RunIns×3；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 1 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 ldr r3, [r1] / push {r4, lr} / cbnz r3, 0x2fb696 <ps_hints_apply+0xa296>（帧：push {r4, lr}）；窗口内出口 3 个
 * 结构：入口可达 90 B / 23 条（17%）；段内 bl 入口 2 个：0x2fb6e6(212 B/76 条) / 0x2fb7bc(212 B/33 条)
 *      可打印岛：无 ≥16 B 的
 * 入口 90 B / 23 条，被 TT_RunIns bl 3 次。末条是 `b 0x2fb2ca` 的尾跳而不是 pop —— 它和 0x2fb2ca
 *      共用出口，所以本段不是自足函数。0x2fb892 起的 2 B 是链接器 0xffff 填充（不是指令），
 *      本卡窗口因此收到 0x2fb892（split 原记 520 B）。
 *
 * 锚点：182 条（= asm/index-anonT_2fb68c.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2fb68c ldr r3, [r1]
 *   @0x2fb68e push {r4, lr}
 *   @0x2fb690 cbnz r3, 0x2fb696 <ps_hints_apply+0xa296>
 *   @0x2fb692 ldr r2, [r0, #0x1c]
 *   @0x2fb694 cbz r2, 0x2fb6be <ps_hints_apply+0xa2be>
 *   @0x2fb696 ldr.w r2, [r0, #0x16c]
 *   @0x2fb69a add r3, r2
 *   @0x2fb69c str.w r3, [r0, #0x16c]
 *   @0x2fb6a0 cmp r3, #0x0
 *   @0x2fb6a2 blt 0x2fb6be <ps_hints_apply+0xa2be>
 *   @0x2fb6a4 ldr.w r2, [r0, #0x1b0]
 *   @0x2fb6a8 cmp r2, #0x0
 *   @0x2fb6aa ble 0x2fb6c2 <ps_hints_apply+0xa2c2>
 *   @0x2fb6ac ldr.w r4, [r0, #0x1b8]
 *   @0x2fb6b0 add.w r2, r4, r2, lsl #4
 *   @0x2fb6b4 ldr r2, [r2, #-4]
 *   @0x2fb6b8 ldr r2, [r2, #0x8]
 *   @0x2fb6ba cmp r3, r2
 *   @0x2fb6bc ble 0x2fb6c2 <ps_hints_apply+0xa2c2>
 *   @0x2fb6be movs r3, #0x84
 *   @0x2fb6c0 b 0x2fb6e2 <ps_hints_apply+0xa2e2>
 *   @0x2fb6c2 movs r3, #0x0
 *   @0x2fb6c4 strb.w r3, [r0, #0x17c]
 *   @0x2fb6c8 ldr r3, [r1]
 *   @0x2fb6ca cmp r3, #0x0
 *   @0x2fb6cc bge 0x2fb6e4 <ps_hints_apply+0xa2e4>
 *   @0x2fb6ce ldr.w r3, [r0, #0x274]
 *   @0x2fb6d2 ldr.w r2, [r0, #0x278]
 *   @0x2fb6d6 adds r3, #0x1
 *   @0x2fb6d8 str.w r3, [r0, #0x274]
 *   @0x2fb6dc cmp r3, r2
 *   @0x2fb6de bls 0x2fb6e4 <ps_hints_apply+0xa2e4>
 *   @0x2fb6e0 movs r3, #0x8b
 *   @0x2fb6e2 str r3, [r0, #0xc]
 *   @0x2fb6e4 pop {r4, pc}
 *   @0x2fb6e6 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2fb6ea mov r8, r1
 *   @0x2fb6ec ldr r1, [r1, #0x4]
 *   @0x2fb6ee movs r6, #0x0
 *   @0x2fb6f0 mov r5, r6
 *   @0x2fb6f2 str r0, [sp, #0x4]
 *   @0x2fb6f4 add.w r11, r1, r2, lsl #4
 *   @0x2fb6f8 ldr.w r2, [r11, #0x4]
 *   @0x2fb6fc lsl.w r9, r2, #0x1
 *   @0x2fb700 ldr.w r2, [r11, #0xc]
 *   @0x2fb704 mla r2, r3, r9, r2
 *   @0x2fb708 str r2, [sp]
 *   @0x2fb70a ldr.w r3, [r11, #0x4]
 *   @0x2fb70e cmp r5, r3
 *   @0x2fb710 bhs 0x2fb7ae <ps_hints_apply+0xa3ae>
 *   @0x2fb712 ldr.w r3, [r11, #0x8]
 *   @0x2fb716 mov.w r9, #0x10000
 *   @0x2fb71a movs r7, #0x0
 *   @0x2fb71c ldr.w r2, [r3, r5, lsl #2]
 *   @0x2fb720 ldr.w r3, [r8, #0x10]
 *   @0x2fb724 ldr.w r3, [r3, r2, lsl #2]
 *   @0x2fb728 add.w r10, r3, #0xc
 *   @0x2fb72c ldrh.w r1, [r8, #0x8]
 *   @0x2fb730 cmp r7, r1
 *   @0x2fb732 bhs 0x2fb79a <ps_hints_apply+0xa39a>
 *   @0x2fb734 ldr r3, [r10, #-12]
 *   @0x2fb738 ldr r4, [r10, #-8]
 *   @0x2fb73c cmp r3, r4
 *   @0x2fb73e bgt 0x2fb786 <ps_hints_apply+0xa386>
 *   @0x2fb740 ldr r1, [r10, #-4]
 *   @0x2fb744 cmp r4, r1
 *   @0x2fb746 bgt 0x2fb786 <ps_hints_apply+0xa386>
 *   @0x2fb748 cmp r3, #0x0
 *   @0x2fb74a bge 0x2fb750 <ps_hints_apply+0xa350>
 *   @0x2fb74c cmp r1, #0x0
 *   @0x2fb74e bgt 0x2fb786 <ps_hints_apply+0xa386>
 *   @0x2fb750 cbz r4, 0x2fb786 <ps_hints_apply+0xa386>
 *   @0x2fb752 ldr r2, [sp, #0x4]
 *   @0x2fb754 ldr r0, [r2]
 *   @0x2fb756 ldr r0, [r0, #0x8]
 *   @0x2fb758 ldr.w r0, [r0, r7, lsl #2]
 *   @0x2fb75c cmp r0, r3
 *   @0x2fb75e blt 0x2fb782 <ps_hints_apply+0xa382>
 *   @0x2fb760 cmp r0, r1
 *   @0x2fb762 bgt 0x2fb782 <ps_hints_apply+0xa382>
 *   @0x2fb764 cmp r0, r4
 *   @0x2fb766 beq 0x2fb786 <ps_hints_apply+0xa386>
 *   @0x2fb768 itete ge
 *   @0x2fb76a rsbge r0, r0, r1
 *   @0x2fb76e rsblt r1, r3, r4
 *   @0x2fb772 rsbge r1, r4, r1
 *   @0x2fb776 rsblt r0, r3, r0
 *   @0x2fb77a bl 0x2e4eb6 <FT_DivFix>
 *   @0x2fb77e mov r1, r0
 *   @0x2fb780 b 0x2fb78a <ps_hints_apply+0xa38a>
 *   @0x2fb782 movs r1, #0x0
 *   @0x2fb784 b 0x2fb78a <ps_hints_apply+0xa38a>
 *   @0x2fb786 mov.w r1, #0x10000
 *   @0x2fb78a mov r0, r9
 *   @0x2fb78c adds r7, #0x1
 *   @0x2fb78e bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fb792 add.w r10, r10, #0xc
 *   @0x2fb796 mov r9, r0
 *   @0x2fb798 b 0x2fb72c <ps_hints_apply+0xa32c>
 *   @0x2fb79a ldr r3, [sp]
 *   @0x2fb79c mov r0, r9
 *   @0x2fb79e ldrsh.w r1, [r3, r5, lsl #1]
 *   @0x2fb7a2 adds r5, #0x1
 *   @0x2fb7a4 lsls r1, r1, #0x10
 *   @0x2fb7a6 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fb7aa add r6, r0
 *   @0x2fb7ac b 0x2fb70a <ps_hints_apply+0xa30a>
 *   @0x2fb7ae add.w r0, r6, #0x8000
 *   @0x2fb7b2 asrs r0, r0, #0x10
 *   @0x2fb7b4 add sp, #0xc
 *   @0x2fb7b6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2fb7ba movs r0, r0
 *   @0x2fb7bc push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2fb7c0 mov r4, r0
 *   @0x2fb7c2 ldr.w r3, [r0, #0x2c0]
 *   @0x2fb7c6 ldr.w r6, [r0, #0x2b8]
 *   @0x2fb7ca lsls r3, r3, #0x17
 *   @0x2fb7cc bpl 0x2fb88c <ps_hints_apply+0xa48c>
 *   @0x2fb7ce ldr r3, [r6, #0x38]
 *   @0x2fb7d0 mov.w r9, #0xc
 *   @0x2fb7d4 add.w r8, r0, #0x2b8
 *   @0x2fb7d8 ldr r5, [r3, #0x18]
 *   @0x2fb7da ldrh r3, [r3]
 *   @0x2fb7dc mla r9, r9, r3, r5
 *   @0x2fb7e0 adds r5, #0xc
 *   @0x2fb7e2 sub.w r3, r5, #0xc
 *   @0x2fb7e6 cmp r9, r3
 *   @0x2fb7e8 bls 0x2fb816 <ps_hints_apply+0xa416>
 *   @0x2fb7ea ldr r1, [r5, #-12]
 *   @0x2fb7ee mov r0, r4
 *   @0x2fb7f0 bl 0x2f8fb4 <ps_hints_apply+0x7bb4>
 *   @0x2fb7f4 ldr r1, [r6, #0x38]
 *   @0x2fb7f6 ldrh r2, [r5, #-8]
 *   @0x2fb7fa adds r1, #0x4
 *   @0x2fb7fc ldrh r3, [r5, #-6]
 *   @0x2fb800 mov r7, r0
 *   @0x2fb802 mov r0, r8
 *   @0x2fb804 bl 0x2fb6e6 <ps_hints_apply+0xa2e6>
 *   @0x2fb808 cbz r7, 0x2fb812 <ps_hints_apply+0xa412>
 *   @0x2fb80a ldrh r3, [r5, #-4]
 *   @0x2fb80e add r0, r3
 *   @0x2fb810 strh r0, [r7]
 *   @0x2fb812 adds r5, #0xc
 *   @0x2fb814 b 0x2fb7e2 <ps_hints_apply+0xa3e2>
 *   @0x2fb816 ldrh.w r2, [r4, #0x174]
 *   @0x2fb81a movw r3, #0xffff
 *   @0x2fb81e cmp r2, r3
 *   @0x2fb820 beq 0x2fb860 <ps_hints_apply+0xa460>
 *   @0x2fb822 ldrh.w r3, [r4, #0x1ba]
 *   @0x2fb826 cbnz r3, 0x2fb82e <ps_hints_apply+0xa42e>
 *   @0x2fb828 ldrsh.w r2, [r4, #0x1bc]
 *   @0x2fb82c cbz r2, 0x2fb848 <ps_hints_apply+0xa448>
 *   @0x2fb82e ldrh.w r2, [r4, #0x1bc]
 *   @0x2fb832 ldrh.w r1, [r4, #0x1be]
 *   @0x2fb836 strh.w r3, [r4, #0x46]
 *   @0x2fb83a add r3, r1
 *   @0x2fb83c strh.w r2, [r4, #0x48]
 *   @0x2fb840 subs r2, r3, r2
 *   @0x2fb842 strh.w r2, [r4, #0x4a]
 *   @0x2fb846 b 0x2fb860 <ps_hints_apply+0xa460>
 *   @0x2fb848 ldrh.w r3, [r4, #0x1c0]
 *   @0x2fb84c ldrh.w r2, [r4, #0x1c2]
 *   @0x2fb850 strh.w r3, [r4, #0x46]
 *   @0x2fb854 rsbs r1, r2, #0
 *   @0x2fb856 add r3, r2
 *   @0x2fb858 strh.w r1, [r4, #0x48]
 *   @0x2fb85c strh.w r3, [r4, #0x4a]
 *   @0x2fb860 ldrh.w r3, [r4, #0x1e6]
 *   @0x2fb864 add.w r0, r4, #0x6c
 *   @0x2fb868 ldrh.w r1, [r4, #0x1e4]
 *   @0x2fb86c sxth r2, r3
 *   @0x2fb86e strh.w r3, [r4, #0x52]
 *   @0x2fb872 add.w r2, r2, r2, lsr #31
 *   @0x2fb876 sub.w r2, r1, r2, asr #1
 *   @0x2fb87a ldr r1, [pc, #0x14]
 *   @0x2fb87c strh.w r2, [r4, #0x50]
 *   @0x2fb880 movs r2, #0x0
 *   @0x2fb882 add r1, pc
 *   @0x2fb884 pop.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2fb888 b.w 0x2e8b04 <FT_List_Iterate>
 *   @0x2fb88c pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2fb890 b 0x2fb2ca <ps_hints_apply+0x9eca>
/* ═══════════════════════════════════════════════════════════════════════
 * §8  anon_thumb_317ba8   0x317ba8..0x317e5c   692 B / 279 条   in-degree 3
 * C++ 展开运行时的 662 B 单函数（按 CFI 恢复寄存器/跳转）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 3 条 Thumb `bl` 指向本段起始：__gxx_personality_v0×3；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 0 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} / sub sp, #0x4c / mov r6, r0（帧：sub sp, 0x4c）；窗口内出口 1 个（唯一出口 0x317d8e）
 * 结构：入口可达 662 B / 222 条（95%）；段内 bl 入口 0 个：无（本段只有入口函数）
 *      可打印岛：无 ≥16 B 的
 *      未达字节：30 B（各入口可达集的补集；多为只经指针/表进入的邻接函数与池字，本卡不判其身份）
 * 入口 662 B / 222 条、只有 1 个出口；反向被 __gxx_personality_v0 bl 3 次；正向 bl 打向
 *      __cxa_call_unexpected（3 处）、_Unwind_VRS_Get、_Unwind_GetRegionStart —— 是 personality
 *      例程调用的「按 CFI 恢复上下文」件（narrowed）。0x317d0a 有 8 B 可打印串。
 *
 * 锚点：279 条（= asm/index-anonT_317ba8.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x317ba8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x317bac sub sp, #0x4c
 *   @0x317bae mov r6, r0
 *   @0x317bb0 movs r4, #0x0
 *   @0x317bb2 movs r0, #0x0
 *   @0x317bb4 movs r5, #0x0
 *   @0x317bb6 str r2, [sp, #0x18]
 *   @0x317bb8 movs r2, #0x3
 *   @0x317bba strd r4, r5, [r6]
 *   @0x317bbe ands r5, r1, #0x1
 *   @0x317bc2 str r0, [r6, #0x8]
 *   @0x317bc4 mov r8, r3
 *   @0x317bc6 str r0, [r6, #0xc]
 *   @0x317bc8 str r0, [r6, #0x10]
 *   @0x317bca str r1, [sp, #0x14]
 *   @0x317bcc str r0, [r6, #0x14]
 *   @0x317bce str r2, [r6, #0x18]
 *   @0x317bd0 ldr r4, [sp, #0x70]
 *   @0x317bd2 str r5, [sp, #0x24]
 *   @0x317bd4 beq.w 0x317d92 <ft_lzwstate_io+0xdde>
 *   @0x317bd8 tst.w r1, #0xe
 *   @0x317bdc bne.w 0x317d8c <ft_lzwstate_io+0xdd8>
 *   @0x317be0 mov r0, r4
 *   @0x317be2 blx 0x31ab08 <_Unwind_GetLanguageSpecificData>
 *   @0x317be6 str r0, [sp, #0x30]
 *   @0x317be8 cmp r0, #0x0
 *   @0x317bea beq.w 0x317daa <ft_lzwstate_io+0xdf6>
 *   @0x317bee movs r3, #0x0
 *   @0x317bf0 movs r2, #0xf
 *   @0x317bf2 str r0, [r6, #0xc]
 *   @0x317bf4 mov r0, r4
 *   @0x317bf6 mov r1, r3
 *   @0x317bf8 add r5, sp, #0x44
 *   @0x317bfa str r5, [sp]
 *   @0x317bfc blx 0x319be4 <_Unwind_VRS_Get>
 *   @0x317c00 ldr r3, [sp, #0x44]
 *   @0x317c02 mov r0, r4
 *   @0x317c04 add r4, sp, #0x48
 *   @0x317c06 bic r10, r3, #0x1
 *   @0x317c0a blx 0x31aaf8 <_Unwind_GetRegionStart>
 *   @0x317c0e ldr r3, [sp, #0x30]
 *   @0x317c10 add.w r10, r10, #0xffffffff
 *   @0x317c14 ldrb r1, [r3], #1
 *   @0x317c18 str r3, [r4, #-24]!
 *   @0x317c1c mov r5, r0
 *   @0x317c1e rsb r10, r0, r10
 *   @0x317c22 mov r0, r4
 *   @0x317c24 bl 0x318834 <__cxa_call_unexpected+0x16c>
 *   @0x317c28 ldr r3, [sp, #0x30]
 *   @0x317c2a mov r2, r0
 *   @0x317c2c cmp r0, #0x0
 *   @0x317c2e it eq
 *   @0x317c30 moveq r2, r5
 *   @0x317c32 ldrb r5, [r3], #1
 *   @0x317c36 str r2, [sp, #0x1c]
 *   @0x317c38 cmp r5, #0xff
 *   @0x317c3a str r5, [sp, #0x28]
 *   @0x317c3c str r3, [sp, #0x30]
 *   @0x317c3e beq.w 0x317dbc <ft_lzwstate_io+0xe08>
 *   @0x317c42 mov r0, r4
 *   @0x317c44 bl 0x3187d0 <__cxa_call_unexpected+0x108>
 *   @0x317c48 ldr r3, [sp, #0x30]
 *   @0x317c4a adds r0, r3, r0
 *   @0x317c4c str r0, [sp, #0x20]
 *   @0x317c4e ldrb r5, [r3], #1
 *   @0x317c52 mov r0, r4
 *   @0x317c54 add r4, sp, #0x48
 *   @0x317c56 str r3, [sp, #0x30]
 *   @0x317c58 bl 0x3187d0 <__cxa_call_unexpected+0x108>
 *   @0x317c5c ldr r3, [sp, #0x30]
 *   @0x317c5e str r3, [r4, #-20]!
 *   @0x317c62 adds r7, r3, r0
 *   @0x317c64 cmp r7, r3
 *   @0x317c66 bls 0x317c92 <ft_lzwstate_io+0xcde>
 *   @0x317c68 mov r1, r5
 *   @0x317c6a mov r0, r4
 *   @0x317c6c bl 0x318834 <__cxa_call_unexpected+0x16c>
 *   @0x317c70 mov r1, r5
 *   @0x317c72 mov r9, r0
 *   @0x317c74 mov r0, r4
 *   @0x317c76 bl 0x318834 <__cxa_call_unexpected+0x16c>
 *   @0x317c7a mov r1, r5
 *   @0x317c7c mov r11, r0
 *   @0x317c7e mov r0, r4
 *   @0x317c80 bl 0x318834 <__cxa_call_unexpected+0x16c>
 *   @0x317c84 str r0, [sp, #0x10]
 *   @0x317c86 mov r0, r4
 *   @0x317c88 bl 0x3187d0 <__cxa_call_unexpected+0x108>
 *   @0x317c8c cmp r10, r9
 *   @0x317c8e bhs.w 0x317db0 <ft_lzwstate_io+0xdfc>
 *   @0x317c92 mov r0, r8
 *   @0x317c94 bl 0x317b38 <ft_lzwstate_io+0xb84>
 *   @0x317c98 ldr r1, [sp, #0x10]
 *   @0x317c9a cmp r1, #0x0
 *   @0x317c9c beq.w 0x317daa <ft_lzwstate_io+0xdf6>
 *   @0x317ca0 ldr r4, [sp, #0x1c]
 *   @0x317ca2 ldr r5, [sp, #0x10]
 *   @0x317ca4 adds r4, r4, r5
 *   @0x317ca6 str r4, [sp, #0x2c]
 *   @0x317ca8 cmp r0, #0x0
 *   @0x317caa beq.w 0x317dc2 <ft_lzwstate_io+0xe0e>
 *   @0x317cae ldr r5, [sp, #0x14]
 *   @0x317cb0 add.w r10, sp, #0x48
 *   @0x317cb4 ldr r4, [sp, #0x14]
 *   @0x317cb6 subs r0, #0x1
 *   @0x317cb8 and r5, r5, #0x6
 *   @0x317cbc adds r7, r7, r0
 *   @0x317cbe and r4, r4, #0x5
 *   @0x317cc2 ldr.w r11, [sp, #0x28]
 *   @0x317cc6 str r5, [sp, #0x10]
 *   @0x317cc8 str r4, [sp, #0x1c]
 *   @0x317cca str r7, [r10, #-16]!
 *   @0x317cce str r6, [sp, #0x28]
 *   @0x317cd0 b 0x317d56 <ft_lzwstate_io+0xda2>
 *   @0x317cd2 mov r1, r5
 *   @0x317cd4 ldr r2, [sp, #0x20]
 *   @0x317cd6 mov r3, r11
 *   @0x317cd8 str.w r8, [sp]
 *   @0x317cdc bl 0x317b50 <ft_lzwstate_io+0xb9c>
 *   @0x317ce0 mov r6, r0
 *   @0x317ce2 cmp r0, #0x0
 *   @0x317ce4 beq 0x317dde <ft_lzwstate_io+0xe2a>
 *   @0x317ce6 ldr r1, [sp, #0x18]
 *   @0x317ce8 cbz r1, 0x317d40 <ft_lzwstate_io+0xd8c>
 *   @0x317cea ldr r9, [r8, #-52]
 *   @0x317cee add.w r3, r8, #0x58
 *   @0x317cf2 str r3, [sp, #0x3c]
 *   @0x317cf4 rsbs.w r2, r9, #0x1
 *   @0x317cf8 it lo
 *   @0x317cfa movlo r2, #0x0
 *   @0x317cfc cmp r3, #0x0
 *   @0x317cfe ite ne
 *   @0x317d00 movne r3, r2
 *   @0x317d02 orreq r3, r2, #0x1
 *   @0x317d06 cmp r3, #0x0
 *   @0x317d08 bne 0x317c92 <ft_lzwstate_io+0xcde>
 *   @0x317d0a ldr r1, [pc, #0x148]
 *   @0x317d0c mov r0, r9
 *   @0x317d0e ldr r2, [pc, #0x148]
 *   @0x317d10 add r1, pc
 *   @0x317d12 ldr r1, [r1]
 *   @0x317d14 add r2, pc
 *   @0x317d16 ldr r2, [r2]
 *   @0x317d18 bl 0x317a44 <ft_lzwstate_io+0xa90>
 *   @0x317d1c cbz r0, 0x317d24 <ft_lzwstate_io+0xd70>
 *   @0x317d1e ldr.w r3, [r8, #0x58]
 *   @0x317d22 str r3, [sp, #0x3c]
 *   @0x317d24 ldr r3, [r6]
 *   @0x317d26 mov r0, r6
 *   @0x317d28 mov r1, r9
 *   @0x317d2a add r2, sp, #0x3c
 *   @0x317d2c ldr r3, [r3, #0x8]
 *   @0x317d2e blx r3
 *   @0x317d30 cbz r0, 0x317d40 <ft_lzwstate_io+0xd8c>
 *   @0x317d32 ldr r2, [sp, #0x24]
 *   @0x317d34 cmp r2, #0x0
 *   @0x317d36 bne.w 0x317e3e <ft_lzwstate_io+0xe8a>
 *   @0x317d3a ldr r5, [sp, #0x14]
 *   @0x317d3c lsls r3, r5, #0x1c
 *   @0x317d3e bpl 0x317c92 <ft_lzwstate_io+0xcde>
 *   @0x317d40 ldr r3, [sp, #0x38]
 *   @0x317d42 add r0, sp, #0x48
 *   @0x317d44 str r3, [r0, #-8]!
 *   @0x317d48 bl 0x3187f4 <__cxa_call_unexpected+0x12c>
 *   @0x317d4c cmp r0, #0x0
 *   @0x317d4e beq 0x317da8 <ft_lzwstate_io+0xdf4>
 *   @0x317d50 ldr r7, [sp, #0x38]
 *   @0x317d52 adds r7, r7, r0
 *   @0x317d54 str r7, [sp, #0x38]
 *   @0x317d56 mov r0, r10
 *   @0x317d58 bl 0x3187f4 <__cxa_call_unexpected+0x12c>
 *   @0x317d5c movs r2, #0x0
 *   @0x317d5e movs r3, #0x0
 *   @0x317d60 asrs r5, r0, #0x1f
 *   @0x317d62 mov r4, r0
 *   @0x317d64 cmp r2, r4
 *   @0x317d66 sbcs r3, r5
 *   @0x317d68 blt 0x317cd2 <ft_lzwstate_io+0xd1e>
 *   @0x317d6a orrs.w r1, r4, r5
 *   @0x317d6e bne 0x317de6 <ft_lzwstate_io+0xe32>
 *   @0x317d70 ldr r1, [sp, #0x10]
 *   @0x317d72 cmp r1, #0x2
 *   @0x317d74 bne 0x317d40 <ft_lzwstate_io+0xd8c>
 *   @0x317d76 ldr r6, [sp, #0x28]
 *   @0x317d78 add.w r3, r8, #0x58
 *   @0x317d7c strd r4, r5, [r6]
 *   @0x317d80 ldr r4, [sp, #0x2c]
 *   @0x317d82 str r3, [r6, #0x14]
 *   @0x317d84 movs r3, #0x6
 *   @0x317d86 str r7, [r6, #0x8]
 *   @0x317d88 str r4, [r6, #0x10]
 *   @0x317d8a str r3, [r6, #0x18]
 *   @0x317d8c add sp, #0x4c
 *   @0x317d8e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x317d92 ldr r5, [sp, #0x14]
 *   @0x317d94 lsls r2, r5, #0x1e
 *   @0x317d96 bpl 0x317d8c <ft_lzwstate_io+0xdd8>
 *   @0x317d98 and r3, r5, #0xc
 *   @0x317d9c cmp r3, #0xc
 *   @0x317d9e bne.w 0x317be0 <ft_lzwstate_io+0xc2c>
 *   @0x317da2 movs r3, #0x2
 *   @0x317da4 str r3, [r6, #0x18]
 *   @0x317da6 b 0x317d8c <ft_lzwstate_io+0xdd8>
 *   @0x317da8 ldr r6, [sp, #0x28]
 *   @0x317daa movs r3, #0x8
 *   @0x317dac str r3, [r6, #0x18]
 *   @0x317dae b 0x317d8c <ft_lzwstate_io+0xdd8>
 *   @0x317db0 add r9, r11
 *   @0x317db2 cmp r10, r9
 *   @0x317db4 blo.w 0x317c98 <ft_lzwstate_io+0xce4>
 *   @0x317db8 ldr r3, [sp, #0x34]
 *   @0x317dba b 0x317c64 <ft_lzwstate_io+0xcb0>
 *   @0x317dbc movs r5, #0x0
 *   @0x317dbe str r5, [sp, #0x20]
 *   @0x317dc0 b 0x317c4e <ft_lzwstate_io+0xc9a>
 *   @0x317dc2 ldr r4, [sp, #0x14]
 *   @0x317dc4 and r3, r4, #0x6
 *   @0x317dc8 cmp r3, #0x2
 *   @0x317dca bne 0x317daa <ft_lzwstate_io+0xdf6>
 *   @0x317dcc ldr r4, [sp, #0x2c]
 *   @0x317dce movs r3, #0x0
 *   @0x317dd0 movs r2, #0x0
 *   @0x317dd2 strd r2, r3, [r6]
 *   @0x317dd6 movs r3, #0x6
 *   @0x317dd8 str r3, [r6, #0x18]
 *   @0x317dda str r4, [r6, #0x10]
 *   @0x317ddc b 0x317d8c <ft_lzwstate_io+0xdd8>
 *   @0x317dde ldr r1, [sp, #0x1c]
 *   @0x317de0 cmp r1, #0x0
 *   @0x317de2 beq 0x317d3a <ft_lzwstate_io+0xd86>
 *   @0x317de4 b 0x317d76 <ft_lzwstate_io+0xdc2>
 *   @0x317de6 ldr r2, [sp, #0x18]
 *   @0x317de8 cmp r2, #0x0
 *   @0x317dea beq 0x317dde <ft_lzwstate_io+0xe2a>
 *   @0x317dec cmn.w r8, #0x58
 *   @0x317df0 ldr r6, [r8, #-52]
 *   @0x317df4 add.w r9, r8, #0x58
 *   @0x317df8 ite ne
 *   @0x317dfa movne r3, #0x0
 *   @0x317dfc moveq r3, #0x1
 *   @0x317dfe cmp r6, #0x0
 *   @0x317e00 it eq
 *   @0x317e02 orreq r3, r3, #0x1
 *   @0x317e06 cmp r3, #0x0
 *   @0x317e08 bne.w 0x317c92 <ft_lzwstate_io+0xcde>
 *   @0x317e0c mov r1, r5
 *   @0x317e0e ldr r2, [sp, #0x20]
 *   @0x317e10 mov r3, r11
 *   @0x317e12 stm.w sp, {r6, r9}
 *   @0x317e16 str.w r8, [sp, #0x8]
 *   @0x317e1a bl 0x317b6c <ft_lzwstate_io+0xbb8>
 *   @0x317e1e cmp r0, #0x0
 *   @0x317e20 beq 0x317d40 <ft_lzwstate_io+0xd8c>
 *   @0x317e22 ldr r3, [sp, #0x24]
 *   @0x317e24 cmp r3, #0x0
 *   @0x317e26 beq 0x317d3a <ft_lzwstate_io+0xd86>
 *   @0x317e28 ldr r6, [sp, #0x28]
 *   @0x317e2a movs r3, #0x6
 *   @0x317e2c strd r4, r5, [r6]
 *   @0x317e30 ldr r4, [sp, #0x2c]
 *   @0x317e32 str r7, [r6, #0x8]
 *   @0x317e34 str.w r9, [r6, #0x14]
 *   @0x317e38 str r4, [r6, #0x10]
 *   @0x317e3a str r3, [r6, #0x18]
 *   @0x317e3c b 0x317d8c <ft_lzwstate_io+0xdd8>
 *   @0x317e3e ldr r6, [sp, #0x28]
 *   @0x317e40 ldr r3, [sp, #0x3c]
 *   @0x317e42 strd r4, r5, [r6]
 *   @0x317e46 ldr r4, [sp, #0x2c]
 *   @0x317e48 str r3, [r6, #0x14]
 *   @0x317e4a movs r3, #0x6
 *   @0x317e4c str r7, [r6, #0x8]
 *   @0x317e4e str r4, [r6, #0x10]
 *   @0x317e50 str r3, [r6, #0x18]
 *   @0x317e52 b 0x317d8c <ft_lzwstate_io+0xdd8>
 *   @0x317e54 ldr r6, [sp, #0x3d0]
 *   @0x317e56 movs r5, r1
 *   @0x317e58 ldr r6, [sp, #0x3e0]
 *   @0x317e5a movs r5, r1
/* ═══════════════════════════════════════════════════════════════════════
 * §9  anon_thumb_2fec70   0x2fec70..0x300004   5,012 B / 1832 条   in-degree 2
 * ttgload.c 带（5,012 B / 5 个 bl 入口 / 1,832 条）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 2 条 Thumb `bl` 指向本段起始：anon_2fec70 自递归×2（本段内 0x2ffaac / 0x3001d0）；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 43 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r3, r4, r5, r6, r7, r8, r9, lr} / mov r4, r0 / ldr r3, [r0]（帧：push {r3, r4, r5, r6, r7, r8, r9, lr}）；窗口内出口 6 个
 * 结构：入口可达 602 B / 182 条（12%）；段内 bl 入口 4 个：0x2fef9c(240 B/73 条) / 0x2ff08c(1520 B/166 条) / 0x2ff392(122 B/46 条) / 0x2ff67c(2956 B/381 条)
 *      可打印岛：无 ≥16 B 的
 *      未达字节：1344 B（各入口可达集的补集；多为只经指针/表进入的邻接函数与池字，本卡不判其身份）
 * 紧跟 TT_RunIns 的 7,804 B 之后（0x2fcdf4 + 0x1e7c = 0x2fec70），到 TT_New_Context(0x300208) 之前。
 *      入口 602 B / 182 条，反向只有自己 bl 2 次；正向 43 处 bl 打向具名 Thumb：ft_mem_realloc、
 *      FT_GlyphLoader_Add、FT_Outline_Translate/Transform、FT_Stream_*、FT_MulDiv —— 字形装载的公共件。
 *      段内 4 个 bl 入口：0x2fef9c(240 B) / 0x2ff08c(1,520 B) / 0x2ff392(122 B) / 0x2ff67c(2,956 B)。
 *
 * 锚点：1832 条（= asm/index-anonT_2fec70.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2fec70 push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2fec74 mov r4, r0
 *   @0x2fec76 ldr r3, [r0]
 *   @0x2fec78 mov r6, r1
 *   @0x2fec7a ldr.w r8, [r3, #0x60]
 *   @0x2fec7e ldr r3, [r0, #0x8]
 *   @0x2fec80 ldr.w r5, [r3, #0x8c]
 *   @0x2fec84 cmp r5, #0x0
 *   @0x2fec86 ble 0x2fec9a <TT_RunIns+0x1ea6>
 *   @0x2fec88 ldrh.w r2, [r0, #0x80]
 *   @0x2fec8c ldr.w r1, [r4, #0x88]
 *   @0x2fec90 ldr.w r0, [r0, #0x84]
 *   @0x2fec94 lsls r2, r2, #0x3
 *   @0x2fec96 blx 0xb65bc <memcpy@plt>
 *   @0x2fec9a ldr.w r0, [r4, #0x9c]
 *   @0x2fec9e movs r2, #0x44
 *   @0x2feca0 ldr r1, [r4, #0x4]
 *   @0x2feca2 add.w r0, r0, #0x120
 *   @0x2feca6 adds r1, #0xb4
 *   @0x2feca8 blx 0xb65bc <memcpy@plt>
 *   @0x2fecac ldr.w r3, [r4, #0x9c]
 *   @0x2fecb0 cbz r6, 0x2fecd6 <TT_RunIns+0x1ee2>
 *   @0x2fecb2 mov.w r2, #0x10000
 *   @0x2fecb6 str.w r2, [r3, #0xe0]
 *   @0x2fecba ldr.w r3, [r4, #0x9c]
 *   @0x2fecbe str.w r2, [r3, #0xe4]
 *   @0x2fecc2 ldrh.w r2, [r4, #0x80]
 *   @0x2fecc6 ldr.w r0, [r4, #0x8c]
 *   @0x2fecca ldr.w r1, [r4, #0x88]
 *   @0x2fecce lsls r2, r2, #0x3
 *   @0x2fecd0 blx 0xb65bc <memcpy@plt>
 *   @0x2fecd4 b 0x2fecee <TT_RunIns+0x1efa>
 *   @0x2fecd6 ldr r2, [r4, #0x4]
 *   @0x2fecd8 ldr r2, [r2, #0x2c]
 *   @0x2fecda ldr r2, [r2, #0x4]
 *   @0x2fecdc str.w r2, [r3, #0xe0]
 *   @0x2fece0 ldr r2, [r4, #0x4]
 *   @0x2fece2 ldr.w r3, [r4, #0x9c]
 *   @0x2fece6 ldr r2, [r2, #0x2c]
 *   @0x2fece8 ldr r2, [r2, #0x8]
 *   @0x2fecea str.w r2, [r3, #0xe4]
 *   @0x2fecee ldrh.w r3, [r4, #0x80]
 *   @0x2fecf2 cmp r5, #0x0
 *   @0x2fecf4 ldr.w r2, [r4, #0x88]
 *   @0x2fecf8 add.w r3, r3, #0x20000000
 *   @0x2fecfc sub.w r3, r3, #0x4
 *   @0x2fed00 ldr.w r1, [r2, r3, lsl #3]
 *   @0x2fed04 add.w r1, r1, #0x20
 *   @0x2fed08 bic r1, r1, #0x3f
 *   @0x2fed0c str.w r1, [r2, r3, lsl #3]
 *   @0x2fed10 ldrh.w r3, [r4, #0x80]
 *   @0x2fed14 ldr.w r2, [r4, #0x88]
 *   @0x2fed18 add.w r3, r3, #0x20000000
 *   @0x2fed1c sub.w r3, r3, #0x3
 *   @0x2fed20 ldr.w r1, [r2, r3, lsl #3]
 *   @0x2fed24 add.w r1, r1, #0x20
 *   @0x2fed28 bic r1, r1, #0x3f
 *   @0x2fed2c str.w r1, [r2, r3, lsl #3]
 *   @0x2fed30 ldrh.w r3, [r4, #0x80]
 *   @0x2fed34 ldr.w r2, [r4, #0x88]
 *   @0x2fed38 add.w r3, r3, #0x20000000
 *   @0x2fed3c sub.w r3, r3, #0x2
 *   @0x2fed40 add.w r3, r2, r3, lsl #3
 *   @0x2fed44 ldr r2, [r3, #0x4]
 *   @0x2fed46 add.w r2, r2, #0x20
 *   @0x2fed4a bic r2, r2, #0x3f
 *   @0x2fed4e str r2, [r3, #0x4]
 *   @0x2fed50 ldrh.w r3, [r4, #0x80]
 *   @0x2fed54 ldr.w r2, [r4, #0x88]
 *   @0x2fed58 add.w r3, r3, #0x20000000
 *   @0x2fed5c add.w r3, r3, #0xffffffff
 *   @0x2fed60 add.w r3, r2, r3, lsl #3
 *   @0x2fed64 ldr r2, [r3, #0x4]
 *   @0x2fed66 add.w r2, r2, #0x20
 *   @0x2fed6a bic r2, r2, #0x3f
 *   @0x2fed6e str r2, [r3, #0x4]
 *   @0x2fed70 ble 0x2fee6c <TT_RunIns+0x2078>
 *   @0x2fed72 ldr r3, [r4, #0xc]
 *   @0x2fed74 mov.w r12, #0x0
 *   @0x2fed78 ldr.w r9, [r3, #0x40]
 *   @0x2fed7c ldr.w r3, [r4, #0x9c]
 *   @0x2fed80 ldr.w r2, [r3, #0x18c]
 *   @0x2fed84 str.w r5, [r3, #0x1d4]
 *   @0x2fed88 str.w r2, [r3, #0x1d0]
 *   @0x2fed8c ldr.w r3, [r4, #0x9c]
 *   @0x2fed90 strb.w r6, [r3, #0x234]
 *   @0x2fed94 add.w r6, r4, #0x78
 *   @0x2fed98 ldr.w r5, [r4, #0x9c]
 *   @0x2fed9c ldm r6!, {r0, r1, r2, r3}
 *   @0x2fed9e adds r5, #0x90
 *   @0x2feda0 stm r5!, {r0, r1, r2, r3}
 *   @0x2feda2 ldm r6!, {r0, r1, r2, r3}
 *   @0x2feda4 stm r5!, {r0, r1, r2, r3}
 *   @0x2feda6 ldr r3, [r6]
 *   @0x2feda8 str r3, [r5]
 *   @0x2fedaa ldr.w r5, [r4, #0x9c]
 *   @0x2fedae add.w r6, r5, #0x90
 *   @0x2fedb2 add.w r7, r5, #0x24
 *   @0x2fedb6 ldr.w r3, [r5, #0x1d0]
 *   @0x2fedba add.w lr, r5, #0x90
 *   @0x2fedbe str.w r12, [r5, #0x16c]
 *   @0x2fedc2 str.w r3, [r5, #0x168]
 *   @0x2fedc6 ldr.w r3, [r5, #0x1d4]
 *   @0x2fedca str.w r3, [r5, #0x170]
 *   @0x2fedce movs r3, #0x3
 *   @0x2fedd0 str.w r3, [r5, #0x164]
 *   @0x2fedd4 ldm r6!, {r0, r1, r2, r3}
 *   @0x2fedd6 stm r7!, {r0, r1, r2, r3}
 *   @0x2fedd8 ldm r6!, {r0, r1, r2, r3}
 *   @0x2fedda stm r7!, {r0, r1, r2, r3}
 *   @0x2feddc ldr r3, [r6]
 *   @0x2fedde str r3, [r7]
 *   @0x2fede0 add.w r7, r5, #0x48
 *   @0x2fede4 ldm.w lr!, {r0, r1, r2, r3}
 *   @0x2fede8 stm r7!, {r0, r1, r2, r3}
 *   @0x2fedea ldm.w lr!, {r0, r1, r2, r3}
 *   @0x2fedee add.w lr, r5, #0x90
 *   @0x2fedf2 stm r7!, {r0, r1, r2, r3}
 *   @0x2fedf4 ldr r3, [r6]
 *   @0x2fedf6 str r3, [r7]
 *   @0x2fedf8 add.w r7, r5, #0x6c
 *   @0x2fedfc ldm.w lr!, {r0, r1, r2, r3}
 *   @0x2fee00 stm r7!, {r0, r1, r2, r3}
 *   @0x2fee02 ldm.w lr!, {r0, r1, r2, r3}
 *   @0x2fee06 stm r7!, {r0, r1, r2, r3}
 *   @0x2fee08 mov.w r2, #0x4000
 *   @0x2fee0c ldr r3, [r6]
 *   @0x2fee0e mov r0, r5
 *   @0x2fee10 str r3, [r7]
 *   @0x2fee12 movs r3, #0x1
 *   @0x2fee14 strh.w r2, [r5, #0x12a]
 *   @0x2fee18 strh.w r3, [r5, #0x15c]
 *   @0x2fee1c strh.w r3, [r5, #0x15e]
 *   @0x2fee20 strh.w r3, [r5, #0x160]
 *   @0x2fee24 strh.w r12, [r5, #0x12c]
 *   @0x2fee28 str.w r3, [r5, #0x13c]
 *   @0x2fee2c ldr.w r1, [r5, #0x12a]
 *   @0x2fee30 str.w r3, [r5, #0x134]
 *   @0x2fee34 ldr r3, [r5]
 *   @0x2fee36 str.w r1, [r5, #0x12e]
 *   @0x2fee3a str.w r1, [r5, #0x126]
 *   @0x2fee3e str.w r12, [r5, #0x10]
 *   @0x2fee42 str.w r12, [r5, #0x1b0]
 *   @0x2fee46 ldr.w r3, [r3, #0x29c]
 *   @0x2fee4a blx r3
 *   @0x2fee4c ldr.w r3, [r4, #0x9c]
 *   @0x2fee50 cbz r0, 0x2fee58 <TT_RunIns+0x2064>
 *   @0x2fee52 ldrb.w r2, [r3, #0x235]
 *   @0x2fee56 cbnz r2, 0x2feec6 <TT_RunIns+0x20d2>
 *   @0x2fee58 ldr.w r2, [r3, #0x158]
 *   @0x2fee5c ldrb.w r3, [r9]
 *   @0x2fee60 orr.w r3, r3, r2, lsl #5
 *   @0x2fee64 orr r3, r3, #0x4
 *   @0x2fee68 strb.w r3, [r9]
 *   @0x2fee6c ldr.w r3, [r8, #0x40]
 *   @0x2fee70 cmp r3, #0x28
 *   @0x2fee72 bne 0x2fee7e <TT_RunIns+0x208a>
 *   @0x2fee74 ldr.w r3, [r4, #0x9c]
 *   @0x2fee78 ldrb.w r0, [r3, #0x267]
 *   @0x2fee7c cbz r0, 0x2feec6 <TT_RunIns+0x20d2>
 *   @0x2fee7e ldrh.w r3, [r4, #0x80]
 *   @0x2fee82 add.w r2, r4, #0x44
 *   @0x2fee86 ldr.w r1, [r4, #0x88]
 *   @0x2fee8a add.w r3, r3, #0x20000000
 *   @0x2fee8e subs r3, #0x4
 *   @0x2fee90 add.w r3, r1, r3, lsl #3
 *   @0x2fee94 ldm.w r3, {r0, r1}
 *   @0x2fee98 stm.w r2, {r0, r1}
 *   @0x2fee9c add.w r1, r3, #0x8
 *   @0x2feea0 add.w r2, r4, #0x4c
 *   @0x2feea4 ldm r1, {r0, r1}
 *   @0x2feea6 stm.w r2, {r0, r1}
 *   @0x2feeaa add.w r1, r3, #0x10
 *   @0x2feeae add.w r2, r4, #0xb4
 *   @0x2feeb2 adds r3, #0x18
 *   @0x2feeb4 ldm r1, {r0, r1}
 *   @0x2feeb6 adds r4, #0xbc
 *   @0x2feeb8 stm.w r2, {r0, r1}
 *   @0x2feebc ldm.w r3, {r0, r1}
 *   @0x2feec0 stm.w r4, {r0, r1}
 *   @0x2feec4 movs r0, #0x0
 *   @0x2feec6 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2feeca push {r4, lr}
 *   @0x2feecc ldrsh.w r3, [r0, #0x12c]
 *   @0x2feed0 ldrsh.w r4, [r0, #0x12a]
 *   @0x2feed4 smull r2, r3, r2, r3
 *   @0x2feed8 smlal r2, r3, r4, r1
 *   @0x2feedc asrs r0, r3, #0x1f
 *   @0x2feede mov r1, r0
 *   @0x2feee0 adds.w r0, r0, #0x2000
 *   @0x2feee4 adc r1, r1, #0x0
 *   @0x2feee8 adds r2, r2, r0
 *   @0x2feeea adc.w r3, r3, r1
 *   @0x2feeee lsrs r0, r2, #0xe
 *   @0x2feef0 orr.w r0, r0, r3, lsl #18
 *   @0x2feef4 pop {r4, pc}
 *   @0x2feef6 ldrb.w r3, [r0, #0x2b5]
 *   @0x2feefa cbz r3, 0x2fef02 <TT_RunIns+0x210e>
 *   @0x2feefc movs r3, #0x1
 *   @0x2feefe b.w 0x2fccd0 <ps_hints_apply+0xb8d0>
 *   @0x2fef02 mov r0, r3
 *   @0x2fef04 bx lr
 *   @0x2fef06 tst.w r3, #0x10
 *   @0x2fef0a push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2fef0e mov r4, r0
 *   @0x2fef10 mov r7, r1
 *   @0x2fef12 mov r6, r2
 *   @0x2fef14 ldr.w r8, [sp, #0x30]
 *   @0x2fef18 ldrb.w r3, [r0, #0x2bc]
 *   @0x2fef1c beq 0x2fef56 <TT_RunIns+0x2162>
 *   @0x2fef1e cbz r3, 0x2fef2c <TT_RunIns+0x2138>
 *   @0x2fef20 movs r5, #0x0
 *   @0x2fef22 add.w r10, sp, #0xc
 *   @0x2fef26 add.w r9, sp, #0xe
 *   @0x2fef2a b 0x2fef36 <TT_RunIns+0x2142>
 *   @0x2fef2c ldr.w r3, [r0, #0x2c0]
 *   @0x2fef30 lsls r2, r3, #0x1b
 *   @0x2fef32 bpl 0x2fef94 <TT_RunIns+0x21a0>
 *   @0x2fef34 b 0x2fef20 <TT_RunIns+0x212c>
 *   @0x2fef36 cmp r5, r6
 *   @0x2fef38 beq 0x2fef90 <TT_RunIns+0x219c>
 *   @0x2fef3a adds r1, r5, r7
 *   @0x2fef3c mov r3, r10
 *   @0x2fef3e str.w r9, [sp]
 *   @0x2fef42 mov r0, r4
 *   @0x2fef44 movs r2, #0x0
 *   @0x2fef46 bl 0x2f8e26 <ps_hints_apply+0x7a26>
 *   @0x2fef4a ldrh.w r3, [sp, #0xe]
 *   @0x2fef4e str.w r3, [r8, r5, lsl #2]
 *   @0x2fef52 adds r5, #0x1
 *   @0x2fef54 b 0x2fef36 <TT_RunIns+0x2142>
 *   @0x2fef56 cbnz r3, 0x2fef60 <TT_RunIns+0x216c>
 *   @0x2fef58 ldr.w r3, [r0, #0x2c0]
 *   @0x2fef5c lsls r3, r3, #0x1e
 *   @0x2fef5e bpl 0x2fef94 <TT_RunIns+0x21a0>
 *   @0x2fef60 add.w r10, sp, #0xc
 *   @0x2fef64 add.w r9, sp, #0xe
 *   @0x2fef68 movs r5, #0x0
 *   @0x2fef6a cmp r5, r6
 *   @0x2fef6c beq 0x2fef90 <TT_RunIns+0x219c>
 *   @0x2fef6e ldr.w r2, [r4, #0x21c]
 *   @0x2fef72 mov r3, r10
 *   @0x2fef74 str.w r9, [sp]
 *   @0x2fef78 mov r0, r4
 *   @0x2fef7a movs r1, #0x0
 *   @0x2fef7c ldr.w r12, [r2, #0x70]
 *   @0x2fef80 adds r2, r5, r7
 *   @0x2fef82 blx r12
 *   @0x2fef84 ldrh.w r3, [sp, #0xe]
 *   @0x2fef88 str.w r3, [r8, r5, lsl #2]
 *   @0x2fef8c adds r5, #0x1
 *   @0x2fef8e b 0x2fef6a <TT_RunIns+0x2176>
 *   @0x2fef90 movs r0, #0x0
 *   @0x2fef92 b 0x2fef96 <TT_RunIns+0x21a2>
 *   @0x2fef94 movs r0, #0x7
 *   @0x2fef96 add sp, #0x10
 *   @0x2fef98 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2fef9c push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2fefa0 mov r6, r0
 *   @0x2fefa2 ldr r7, [r0]
 *   @0x2fefa4 mov r8, r1
 *   @0x2fefa6 ldr.w r4, [r0, #0x12c]
 *   @0x2fefaa mov r2, r6
 *   @0x2fefac mov r1, r7
 *   @0x2fefae mov r0, r4
 *   @0x2fefb0 bl 0x2fa37c <ps_hints_apply+0x8f7c>
 *   @0x2fefb4 mov r5, r0
 *   @0x2fefb6 cmp r0, #0x0
 *   @0x2fefb8 bne 0x2ff086 <TT_RunIns+0x2292>
 *   @0x2fefba str.w r0, [r4, #0x1b0]
 *   @0x2fefbe str r0, [r4, #0x10]
 *   @0x2fefc0 strb.w r0, [r4, #0x1ec]
 *   @0x2fefc4 strb.w r8, [r4, #0x235]
 *   @0x2fefc8 ldr.w r2, [r7, #0x290]
 *   @0x2fefcc ldr.w r3, [r7, #0x28c]
 *   @0x2fefd0 str.w r0, [r4, #0x1d0]
 *   @0x2fefd4 str.w r2, [r4, #0x1c8]
 *   @0x2fefd8 str.w r3, [r4, #0x1cc]
 *   @0x2fefdc str.w r0, [r4, #0x1d4]
 *   @0x2fefe0 ldr.w r1, [r7, #0x28c]
 *   @0x2fefe4 cbz r1, 0x2ff002 <TT_RunIns+0x220e>
 *   @0x2fefe6 str.w r3, [r4, #0x170]
 *   @0x2fefea movs r3, #0x2
 *   @0x2fefec str.w r0, [r4, #0x16c]
 *   @0x2feff0 mov r0, r4
 *   @0x2feff2 str.w r2, [r4, #0x168]
 *   @0x2feff6 str.w r3, [r4, #0x164]
 *   @0x2feffa ldr.w r3, [r7, #0x29c]
 *   @0x2feffe blx r3
 *   @0x2ff000 mov r5, r0
 *   @0x2ff002 str.w r5, [r6, #0x134]
 *   @0x2ff006 movs r7, #0x0
 *   @0x2ff008 mov.w r3, #0x4000
 *   @0x2ff00c strh.w r7, [r4, #0x128]
 *   @0x2ff010 strh.w r3, [r4, #0x126]
 *   @0x2ff014 add.w r0, r6, #0xb4
 *   @0x2ff018 strh.w r3, [r4, #0x12a]
 *   @0x2ff01c add.w r1, r4, #0x120
 *   @0x2ff020 strh.w r3, [r4, #0x12e]
 *   @0x2ff024 movs r2, #0x44
 *   @0x2ff026 movs r3, #0x1
 *   @0x2ff028 strh.w r7, [r4, #0x12c]
 *   @0x2ff02c strh.w r3, [r4, #0x15c]
 *   @0x2ff030 strh.w r3, [r4, #0x15e]
 *   @0x2ff034 strh.w r3, [r4, #0x160]
 *   @0x2ff038 str.w r3, [r4, #0x134]
 *   @0x2ff03c strh.w r7, [r4, #0x130]
 *   @0x2ff040 strh.w r7, [r4, #0x120]
 *   @0x2ff044 strh.w r7, [r4, #0x122]
 *   @0x2ff048 strh.w r7, [r4, #0x124]
 *   @0x2ff04c blx 0xb65bc <memcpy@plt>
 *   @0x2ff050 ldr.w r3, [r4, #0x190]
 *   @0x2ff054 str r3, [r6, #0x7c]
 *   @0x2ff056 ldr.w r3, [r4, #0x19c]
 *   @0x2ff05a str.w r3, [r6, #0x88]
 *   @0x2ff05e ldr.w r3, [r4, #0x1a8]
 *   @0x2ff062 str.w r3, [r6, #0x94]
 *   @0x2ff066 ldr.w r3, [r4, #0x1ac]
 *   @0x2ff06a str.w r3, [r6, #0x98]
 *   @0x2ff06e adds r2, r4, r7
 *   @0x2ff070 adds r3, r6, r7
 *   @0x2ff072 add.w r2, r2, #0x1c0
 *   @0x2ff076 adds r7, #0x8
 *   @0x2ff078 adds r3, #0x9c
 *   @0x2ff07a cmp r7, #0x18
 *   @0x2ff07c ldm.w r2, {r0, r1}
 *   @0x2ff080 stm.w r3, {r0, r1}
 *   @0x2ff084 bne 0x2ff06e <TT_RunIns+0x227a>
 *   @0x2ff086 mov r0, r5
 *   @0x2ff088 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2ff08c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ff090 sub sp, #0x74
 *   @0x2ff092 ldr r4, [r0, #0x68]
 *   @0x2ff094 mov r7, r1
 *   @0x2ff096 str r0, [sp, #0x30]
 *   @0x2ff098 mov r8, r2
 *   @0x2ff09a ldr r1, [sp, #0x30]
 *   @0x2ff09c mov.w r11, #0x0
 *   @0x2ff0a0 ldr r0, [r4, #0x1c]
 *   @0x2ff0a2 str r3, [sp, #0x14]
 *   @0x2ff0a4 ldrb.w r2, [r1, #0x2b5]
 *   @0x2ff0a8 str r0, [sp, #0x10]
 *   @0x2ff0aa ldr.w r5, [r1, #0x2b8]
 *   @0x2ff0ae str.w r11, [sp, #0x6c]
 *   @0x2ff0b2 cmp r2, #0x0
 *   @0x2ff0b4 beq.w 0x2ff65c <TT_RunIns+0x2868>
 *   @0x2ff0b8 cmp r5, #0x0
 *   @0x2ff0ba beq.w 0x2ff65c <TT_RunIns+0x2868>
 *   @0x2ff0be ldr r2, [r5, #0x44]
 *   @0x2ff0c0 cmp r7, r2
 *   @0x2ff0c2 bhs.w 0x2ff660 <TT_RunIns+0x286c>
 *   @0x2ff0c6 ldr r2, [r5, #0x48]
 *   @0x2ff0c8 lsl.w r9, r7, #0x2
 *   @0x2ff0cc add.w r9, r9, #0x4
 *   @0x2ff0d0 ldr.w r1, [r2, r7, lsl #2]
 *   @0x2ff0d4 ldr.w r2, [r2, r9]
 *   @0x2ff0d8 cmp r1, r2
 *   @0x2ff0da beq.w 0x2ff660 <TT_RunIns+0x286c>
 *   @0x2ff0de str.w r11, [sp]
 *   @0x2ff0e2 add r6, sp, #0x64
 *   @0x2ff0e4 movs r1, #0x8
 *   @0x2ff0e6 str r6, [sp, #0x4]
 *   @0x2ff0e8 mov r2, r11
 *   @0x2ff0ea bl 0x2e808e <ft_mem_realloc>
 *   @0x2ff0ee ldr.w r10, [sp, #0x64]
 *   @0x2ff0f2 str r0, [sp, #0x18]
 *   @0x2ff0f4 cmp.w r10, #0x0
 *   @0x2ff0f8 bne.w 0x2ff636 <TT_RunIns+0x2842>
 *   @0x2ff0fc mov r2, r10
 *   @0x2ff0fe str.w r10, [sp]
 *   @0x2ff102 str r6, [sp, #0x4]
 *   @0x2ff104 movs r1, #0x8
 *   @0x2ff106 ldr r0, [sp, #0x10]
 *   @0x2ff108 ldr r3, [sp, #0x14]
 *   @0x2ff10a bl 0x2e808e <ft_mem_realloc>
 *   @0x2ff10e ldr r2, [sp, #0x64]
 *   @0x2ff110 mov r11, r0
 *   @0x2ff112 cmp r2, #0x0
 *   @0x2ff114 bne.w 0x2ff63c <TT_RunIns+0x2848>
 *   @0x2ff118 ldr r3, [sp, #0x14]
 *   @0x2ff11a movs r1, #0x1
 *   @0x2ff11c stm.w sp, {r2, r6}
 *   @0x2ff120 ldr r0, [sp, #0x10]
 *   @0x2ff122 bl 0x2e808e <ft_mem_realloc>
 *   @0x2ff126 ldr r3, [sp, #0x64]
 *   @0x2ff128 str r0, [sp, #0x1c]
 *   @0x2ff12a cmp r3, #0x0
 *   @0x2ff12c bne.w 0x2ff640 <TT_RunIns+0x284c>
 *   @0x2ff130 ldr r3, [r5, #0x48]
 *   @0x2ff132 mov r0, r4
 *   @0x2ff134 ldr.w r1, [r3, r7, lsl #2]
 *   @0x2ff138 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2ff13c str r0, [sp, #0x64]
 *   @0x2ff13e cmp r0, #0x0
 *   @0x2ff140 bne.w 0x2ff640 <TT_RunIns+0x284c>
 *   @0x2ff144 ldr r3, [r5, #0x48]
 *   @0x2ff146 mov r0, r4
 *   @0x2ff148 ldr.w r1, [r3, r9]
 *   @0x2ff14c ldr.w r3, [r3, r7, lsl #2]
 *   @0x2ff150 subs r1, r1, r3
 *   @0x2ff152 bl 0x2e7e22 <FT_Stream_EnterFrame>
 *   @0x2ff156 mov r10, r0
 *   @0x2ff158 str r0, [sp, #0x64]
 *   @0x2ff15a cmp r0, #0x0
 *   @0x2ff15c bne.w 0x2ff640 <TT_RunIns+0x284c>
 *   @0x2ff160 ldr.w r9, [r4, #0x20]
 *   @0x2ff164 mov r2, r10
 *   @0x2ff166 ldr r7, [r4]
 *   @0x2ff168 movs r1, #0x4
 *   @0x2ff16a str r0, [sp]
 *   @0x2ff16c str r6, [sp, #0x4]
 *   @0x2ff16e ldr r0, [sp, #0x10]
 *   @0x2ff170 ldr r3, [r5]
 *   @0x2ff172 bl 0x2e808e <ft_mem_realloc>
 *   @0x2ff176 ldr r3, [sp, #0x64]
 *   @0x2ff178 mov r2, r10
 *   @0x2ff17a str r0, [sp, #0x38]
 *   @0x2ff17c cmp r3, #0x0
 *   @0x2ff17e bne.w 0x2ff664 <TT_RunIns+0x2870>
 *   @0x2ff182 stm.w sp, {r2, r6}
 *   @0x2ff186 movs r1, #0x4
 *   @0x2ff188 ldr r0, [sp, #0x10]
 *   @0x2ff18a ldr r3, [r5]
 *   @0x2ff18c bl 0x2e808e <ft_mem_realloc>
 *   @0x2ff190 ldr r2, [sp, #0x64]
 *   @0x2ff192 str r0, [sp, #0x3c]
 *   @0x2ff194 cmp r2, #0x0
 *   @0x2ff196 bne.w 0x2ff66c <TT_RunIns+0x2878>
 *   @0x2ff19a stm.w sp, {r2, r6}
 *   @0x2ff19e movs r1, #0x4
 *   @0x2ff1a0 ldr r3, [r5]
 *   @0x2ff1a2 ldr r0, [sp, #0x10]
 *   @0x2ff1a4 bl 0x2e808e <ft_mem_realloc>
 *   @0x2ff1a8 ldr r3, [sp, #0x64]
 *   @0x2ff1aa str r0, [sp, #0x2c]
 *   @0x2ff1ac cmp r3, #0x0
 *   @0x2ff1ae bne.w 0x2ff670 <TT_RunIns+0x287c>
 *   @0x2ff1b2 mov r0, r4
 *   @0x2ff1b4 bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2ff1b8 mov r6, r0
 *   @0x2ff1ba mov r0, r4
 *   @0x2ff1bc bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2ff1c0 ubfx r3, r6, #0x0, #0xc
 *   @0x2ff1c4 uxth r3, r3
 *   @0x2ff1c6 str r3, [sp, #0x4c]
 *   @0x2ff1c8 add.w r2, r0, r3, lsl #2
 *   @0x2ff1cc ldr r3, [r5, #0x4c]
 *   @0x2ff1ce cmp r2, r3
 *   @0x2ff1d0 bls 0x2ff1d8 <TT_RunIns+0x23e4>
 *   @0x2ff1d2 movs r3, #0x8
 *   @0x2ff1d4 str r3, [sp, #0x64]
 *   @0x2ff1d6 b 0x2ff670 <TT_RunIns+0x287c>
 *   @0x2ff1d8 rsb r7, r7, r9
 *   @0x2ff1dc adds r7, r0, r7
 *   @0x2ff1de bic r0, r6, #0x7f80
 *   @0x2ff1e2 bic r0, r0, #0x7f
 *   @0x2ff1e6 str r7, [sp, #0x24]
 *   @0x2ff1e8 uxth r0, r0
 *   @0x2ff1ea cbz r0, 0x2ff212 <TT_RunIns+0x241e>
 *   @0x2ff1ec ldr r7, [r4]
 *   @0x2ff1ee mov r0, r4
 *   @0x2ff1f0 ldr r6, [r4, #0x20]
 *   @0x2ff1f2 ldr r2, [sp, #0x24]
 *   @0x2ff1f4 subs r6, r6, r7
 *   @0x2ff1f6 add r7, r2
 *   @0x2ff1f8 add r2, sp, #0x6c
 *   @0x2ff1fa str r7, [r4, #0x20]
 *   @0x2ff1fc ldr r1, [r5, #0x4c]
 *   @0x2ff1fe bl 0xb82f2 <.text+0x1322>
 *   @0x2ff202 ldr r3, [r4]
 *   @0x2ff204 ldr r7, [r4, #0x20]
 *   @0x2ff206 subs r7, r7, r3
 *   @0x2ff208 add r3, r6
 *   @0x2ff20a str r7, [sp, #0x24]
 *   @0x2ff20c str r3, [r4, #0x20]
 *   @0x2ff20e str r0, [sp, #0x34]
 *   @0x2ff210 b 0x2ff214 <TT_RunIns+0x2420>
 *   @0x2ff212 str r0, [sp, #0x34]
 *   @0x2ff214 movs r3, #0x0
 *   @0x2ff216 ldr r7, [sp, #0x14]
 *   @0x2ff218 cmp r3, r7
 *   @0x2ff21a beq 0x2ff232 <TT_RunIns+0x243e>
 *   @0x2ff21c ldr.w r0, [r8, #0x4]
 *   @0x2ff220 lsls r1, r3, #0x3
 *   @0x2ff222 ldr r2, [sp, #0x18]
 *   @0x2ff224 adds r3, #0x1
 *   @0x2ff226 add r2, r1
 *   @0x2ff228 add r1, r0
 *   @0x2ff22a ldm r1, {r0, r1}
 *   @0x2ff22c stm.w r2, {r0, r1}
 *   @0x2ff230 b 0x2ff216 <TT_RunIns+0x2422>
 *   @0x2ff232 movs r7, #0x0
 *   @0x2ff234 str r7, [sp, #0x28]
 *   @0x2ff236 str r7, [sp, #0x48]
 *   @0x2ff238 ldr r7, [sp, #0x14]
 *   @0x2ff23a subs r7, #0x3
 *   @0x2ff23c str r7, [sp, #0x58]
 *   @0x2ff23e ldr r7, [sp, #0x14]
 *   @0x2ff240 subs r7, #0x2
 *   @0x2ff242 str r7, [sp, #0x5c]
 *   @0x2ff244 ldr r7, [sp, #0x48]
 *   @0x2ff246 ldr r0, [sp, #0x4c]
 *   @0x2ff248 cmp r7, r0
 *   @0x2ff24a bhs.w 0x2ff608 <TT_RunIns+0x2814>
 *   @0x2ff24e mov r0, r4
 *   @0x2ff250 bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2ff254 str r0, [sp, #0x50]
 *   @0x2ff256 mov r0, r4
 *   @0x2ff258 bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2ff25c lsls r3, r0, #0x10
 *   @0x2ff25e mov r6, r0
 *   @0x2ff260 bpl 0x2ff27e <TT_RunIns+0x248a>
 *   @0x2ff262 movs r7, #0x0
 *   @0x2ff264 ldr r3, [r5]
 *   @0x2ff266 cmp r7, r3
 *   @0x2ff268 bhs 0x2ff2a0 <TT_RunIns+0x24ac>
 *   @0x2ff26a mov r0, r4
 *   @0x2ff26c bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2ff270 ldr r1, [sp, #0x38]
 *   @0x2ff272 sxth r0, r0
 *   @0x2ff274 lsls r0, r0, #0x2
 *   @0x2ff276 str.w r0, [r1, r7, lsl #2]
 *   @0x2ff27a adds r7, #0x1
 *   @0x2ff27c b 0x2ff264 <TT_RunIns+0x2470>
 *   @0x2ff27e ubfx r3, r0, #0x0, #0xc
 *   @0x2ff282 ldr r2, [r5, #0x3c]
 *   @0x2ff284 uxth r3, r3
 *   @0x2ff286 cmp r3, r2
 *   @0x2ff288 blo 0x2ff290 <TT_RunIns+0x249c>
 *   @0x2ff28a movs r3, #0x8
 *   @0x2ff28c str r3, [sp, #0x64]
 *   @0x2ff28e b 0x2ff608 <TT_RunIns+0x2814>
 *   @0x2ff290 ldr r2, [r5]
 *   @0x2ff292 ldr r1, [r5, #0x40]
 *   @0x2ff294 ldr r0, [sp, #0x38]
 *   @0x2ff296 lsls r2, r2, #0x2
 *   @0x2ff298 mla r1, r2, r3, r1
 *   @0x2ff29c blx 0xb65bc <memcpy@plt>
 *   @0x2ff2a0 lsls r7, r6, #0x11
 *   @0x2ff2a2 bmi 0x2ff2c2 <TT_RunIns+0x24ce>
 *   @0x2ff2a4 ldr r7, [sp, #0x2c]
 *   @0x2ff2a6 mov r0, r5
 *   @0x2ff2a8 mov r1, r6
 *   @0x2ff2aa ldr r2, [sp, #0x38]
 *   @0x2ff2ac ldr r3, [sp, #0x3c]
 *   @0x2ff2ae str r7, [sp]
 *   @0x2ff2b0 bl 0xb8262 <.text+0x1292>
 *   @0x2ff2b4 mov r7, r0
 *   @0x2ff2b6 cbnz r0, 0x2ff2fa <TT_RunIns+0x2506>
 *   @0x2ff2b8 ldr r7, [sp, #0x24]
 *   @0x2ff2ba ldr r0, [sp, #0x50]
 *   @0x2ff2bc add r7, r0
 *   @0x2ff2be str r7, [sp, #0x24]
 *   @0x2ff2c0 b 0x2ff600 <TT_RunIns+0x280c>
 *   @0x2ff2c2 movs r7, #0x0
 *   @0x2ff2c4 ldr r3, [r5]
 *   @0x2ff2c6 cmp r7, r3
 *   @0x2ff2c8 bhs 0x2ff2de <TT_RunIns+0x24ea>
 *   @0x2ff2ca mov r0, r4
 *   @0x2ff2cc bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2ff2d0 ldr r1, [sp, #0x3c]
 *   @0x2ff2d2 sxth r0, r0
 *   @0x2ff2d4 lsls r0, r0, #0x2
 *   @0x2ff2d6 str.w r0, [r1, r7, lsl #2]
 *   @0x2ff2da adds r7, #0x1
 *   @0x2ff2dc b 0x2ff2c4 <TT_RunIns+0x24d0>
 *   @0x2ff2de movs r7, #0x0
 *   @0x2ff2e0 ldr r3, [r5]
 *   @0x2ff2e2 cmp r7, r3
 *   @0x2ff2e4 bhs 0x2ff2a4 <TT_RunIns+0x24b0>
 *   @0x2ff2e6 mov r0, r4
 *   @0x2ff2e8 bl 0x2e69f2 <FT_Stream_GetUShort>
 *   @0x2ff2ec ldr r2, [sp, #0x2c]
 *   @0x2ff2ee sxth r0, r0
 *   @0x2ff2f0 lsls r0, r0, #0x2
 *   @0x2ff2f2 str.w r0, [r2, r7, lsl #2]
 *   @0x2ff2f6 adds r7, #0x1
 *   @0x2ff2f8 b 0x2ff2e0 <TT_RunIns+0x24ec>
 *   @0x2ff2fa ldr r3, [r4]
 *   @0x2ff2fc lsls r0, r6, #0x12
 *   @0x2ff2fe ldr r2, [r4, #0x20]
 *   @0x2ff300 ldr r1, [sp, #0x24]
 *   @0x2ff302 rsb r2, r3, r2
 *   @0x2ff306 str r2, [sp, #0x54]
 *   @0x2ff308 add r3, r1
 *   @0x2ff30a str r3, [r4, #0x20]
 *   @0x2ff30c bpl 0x2ff31e <TT_RunIns+0x252a>
 *   @0x2ff30e mov r0, r4
 *   @0x2ff310 ldr r1, [r5, #0x4c]
 *   @0x2ff312 add r2, sp, #0x68
 *   @0x2ff314 bl 0xb82f2 <.text+0x1322>
 *   @0x2ff318 str r0, [sp, #0x28]
 *   @0x2ff31a mov r10, r0
 *   @0x2ff31c b 0x2ff326 <TT_RunIns+0x2532>
 *   @0x2ff31e ldr r3, [sp, #0x6c]
 *   @0x2ff320 ldr.w r10, [sp, #0x34]
 *   @0x2ff324 str r3, [sp, #0x68]
 *   @0x2ff326 ldr r3, [sp, #0x14]
 *   @0x2ff328 mov r0, r4
 *   @0x2ff32a ldr r2, [sp, #0x68]
 *   @0x2ff32c ldr r1, [r5, #0x4c]
 *   @0x2ff32e cmp r2, #0x0
 *   @0x2ff330 it eq
 *   @0x2ff332 moveq r2, r3
 *   @0x2ff334 bl 0xb83fa <.text+0x142a>
 *   @0x2ff338 ldr r2, [sp, #0x68]
 *   @0x2ff33a ldr r3, [sp, #0x14]
 *   @0x2ff33c ldr r1, [r5, #0x4c]
 *   @0x2ff33e cmp r2, #0x0
 *   @0x2ff340 it eq
 *   @0x2ff342 moveq r2, r3
 *   @0x2ff344 str r0, [sp, #0x40]
 *   @0x2ff346 mov r0, r4
 *   @0x2ff348 bl 0xb83fa <.text+0x142a>
 *   @0x2ff34c str r0, [sp, #0x44]
 *   @0x2ff34e cmp.w r10, #0x0
 *   @0x2ff352 bne 0x2ff36a <TT_RunIns+0x2576>
 *   @0x2ff354 ldr r7, [sp, #0x28]
 *   @0x2ff356 adds r7, #0x1
 *   @0x2ff358 beq.w 0x2ff5e0 <TT_RunIns+0x27ec>
 *   @0x2ff35c ldr r0, [sp, #0x10]
 *   @0x2ff35e movs r7, #0x0
 *   @0x2ff360 ldr r1, [sp, #0x28]
 *   @0x2ff362 bl 0x2e7336 <ft_mem_free>
 *   @0x2ff366 str r7, [sp, #0x28]
 *   @0x2ff368 b 0x2ff5e0 <TT_RunIns+0x27ec>
 *   @0x2ff36a ldr r0, [sp, #0x44]
 *   @0x2ff36c cmp r0, #0x0
 *   @0x2ff36e beq 0x2ff354 <TT_RunIns+0x2560>
 *   @0x2ff370 ldr r1, [sp, #0x40]
 *   @0x2ff372 cmp r1, #0x0
 *   @0x2ff374 beq 0x2ff354 <TT_RunIns+0x2560>
 *   @0x2ff376 cmp.w r10, #0xffffffff
 *   @0x2ff37a beq 0x2ff382 <TT_RunIns+0x258e>
 *   @0x2ff37c movs r3, #0x0
 *   @0x2ff37e mov r6, r3
 *   @0x2ff380 b 0x2ff40c <TT_RunIns+0x2618>
 *   @0x2ff382 ldr r2, [sp, #0x14]
 *   @0x2ff384 movs r6, #0x0
 *   @0x2ff386 add.w r10, r2, #0xffffffff
 *   @0x2ff38a ldr r3, [sp, #0x14]
 *   @0x2ff38c cmp r6, r3
 *   @0x2ff38e beq 0x2ff354 <TT_RunIns+0x2560>
 *   @0x2ff390 ldr r3, [sp, #0x40]
 *   @0x2ff392 mov r1, r7
 *   @0x2ff394 ldrsh.w r0, [r3, r6, lsl #1]
 *   @0x2ff398 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff39c ldr r1, [sp, #0x44]
 *   @0x2ff39e mov r9, r0
 *   @0x2ff3a0 ldrsh.w r0, [r1, r6, lsl #1]
 *   @0x2ff3a4 mov r1, r7
 *   @0x2ff3a6 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff3aa ldr r2, [sp, #0x58]
 *   @0x2ff3ac cmp r6, r2
 *   @0x2ff3ae bhs 0x2ff3c0 <TT_RunIns+0x25cc>
 *   @0x2ff3b0 ldr.w r2, [r8, #0x4]
 *   @0x2ff3b4 ldr.w r3, [r2, r6, lsl #3]
 *   @0x2ff3b8 add r3, r9
 *   @0x2ff3ba str.w r3, [r2, r6, lsl #3]
 *   @0x2ff3be b 0x2ff3fa <TT_RunIns+0x2606>
 *   @0x2ff3c0 bne 0x2ff3cc <TT_RunIns+0x25d8>
 *   @0x2ff3c2 ldr r1, [sp, #0x30]
 *   @0x2ff3c4 ldr.w r3, [r1, #0x2c0]
 *   @0x2ff3c8 lsls r1, r3, #0x1e
 *   @0x2ff3ca bpl 0x2ff3dc <TT_RunIns+0x25e8>
 *   @0x2ff3cc ldr r2, [sp, #0x5c]
 *   @0x2ff3ce cmp r6, r2
 *   @0x2ff3d0 bne 0x2ff3ec <TT_RunIns+0x25f8>
 *   @0x2ff3d2 ldr r1, [sp, #0x30]
 *   @0x2ff3d4 ldr.w r3, [r1, #0x2c0]
 *   @0x2ff3d8 lsls r2, r3, #0x1d
 *   @0x2ff3da bmi 0x2ff3ec <TT_RunIns+0x25f8>
 *   @0x2ff3dc ldr.w r3, [r8, #0x4]
 *   @0x2ff3e0 ldr.w r2, [r3, r6, lsl #3]
 *   @0x2ff3e4 add r2, r9
 *   @0x2ff3e6 str.w r2, [r3, r6, lsl #3]
 *   @0x2ff3ea b 0x2ff408 <TT_RunIns+0x2614>
 *   @0x2ff3ec cmp r6, r10
 *   @0x2ff3ee bne 0x2ff408 <TT_RunIns+0x2614>
 *   @0x2ff3f0 ldr r2, [sp, #0x30]
 *   @0x2ff3f2 ldr.w r3, [r2, #0x2c0]
 *   @0x2ff3f6 lsls r3, r3, #0x1b
 *   @0x2ff3f8 bmi 0x2ff408 <TT_RunIns+0x2614>
 *   @0x2ff3fa ldr.w r3, [r8, #0x4]
 *   @0x2ff3fe add.w r3, r3, r6, lsl #3
 *   @0x2ff402 ldr r2, [r3, #0x4]
 *   @0x2ff404 add r2, r0
 *   @0x2ff406 str r2, [r3, #0x4]
 *   @0x2ff408 adds r6, #0x1
 *   @0x2ff40a b 0x2ff38a <TT_RunIns+0x2596>
 *   @0x2ff40c ldr r1, [sp, #0x14]
 *   @0x2ff40e cmp r3, r1
 *   @0x2ff410 beq 0x2ff42a <TT_RunIns+0x2636>
 *   @0x2ff412 ldr r0, [sp, #0x1c]
 *   @0x2ff414 lsls r1, r3, #0x3
 *   @0x2ff416 add.w r2, r11, r1
 *   @0x2ff41a strb r6, [r0, r3]
 *   @0x2ff41c adds r3, #0x1
 *   @0x2ff41e ldr r0, [sp, #0x18]
 *   @0x2ff420 add r1, r0
 *   @0x2ff422 ldm r1, {r0, r1}
 *   @0x2ff424 stm.w r2, {r0, r1}
 *   @0x2ff428 b 0x2ff40c <TT_RunIns+0x2618>
 *   @0x2ff42a movs r6, #0x0
 *   @0x2ff42c movs r2, #0x1
 *   @0x2ff42e ldr r3, [sp, #0x68]
 *   @0x2ff430 cmp r6, r3
 *   @0x2ff432 bhs 0x2ff484 <TT_RunIns+0x2690>
 *   @0x2ff434 ldrh.w r9, [r10, r6, lsl #1]
 *   @0x2ff438 ldr r3, [sp, #0x14]
 *   @0x2ff43a cmp r9, r3
 *   @0x2ff43c bhs 0x2ff480 <TT_RunIns+0x268c>
 *   @0x2ff43e ldr r0, [sp, #0x1c]
 *   @0x2ff440 add.w r3, r11, r9, lsl #3
 *   @0x2ff444 ldr r1, [sp, #0x40]
 *   @0x2ff446 str r3, [sp, #0x20]
 *   @0x2ff448 strb.w r2, [r0, r9]
 *   @0x2ff44c ldr.w r3, [r11, r9, lsl #3]
 *   @0x2ff450 ldrsh.w r0, [r1, r6, lsl #1]
 *   @0x2ff454 mov r1, r7
 *   @0x2ff456 str r2, [sp, #0x8]
 *   @0x2ff458 str r3, [sp, #0xc]
 *   @0x2ff45a bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff45e ldr r3, [sp, #0xc]
 *   @0x2ff460 ldr r1, [sp, #0x44]
 *   @0x2ff462 add r0, r3
 *   @0x2ff464 ldr r3, [sp, #0x20]
 *   @0x2ff466 str.w r0, [r11, r9, lsl #3]
 *   @0x2ff46a ldrsh.w r0, [r1, r6, lsl #1]
 *   @0x2ff46e mov r1, r7
 *   @0x2ff470 ldr.w r9, [r3, #0x4]
 *   @0x2ff474 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff478 ldr r3, [sp, #0x20]
 *   @0x2ff47a add r0, r9
 *   @0x2ff47c str r0, [r3, #0x4]
 *   @0x2ff47e ldr r2, [sp, #0x8]
 *   @0x2ff480 adds r6, #0x1
 *   @0x2ff482 b 0x2ff42e <TT_RunIns+0x263a>
 *   @0x2ff484 ldrsh.w r3, [r8]
 *   @0x2ff488 cbnz r3, 0x2ff490 <TT_RunIns+0x269c>
 *   @0x2ff48a movs r3, #0x0
 *   @0x2ff48c mov r2, r3
 *   @0x2ff48e b 0x2ff5a2 <TT_RunIns+0x27ae>
 *   @0x2ff490 movs r7, #0x0
 *   @0x2ff492 str r7, [sp, #0x20]
 *   @0x2ff494 mov r9, r7
 *   @0x2ff496 ldr r7, [sp, #0x20]
 *   @0x2ff498 mov r6, r9
 *   @0x2ff49a ldr.w r3, [r8, #0xc]
 *   @0x2ff49e sxth r2, r7
 *   @0x2ff4a0 ldrsh.w r12, [r3, r2, lsl #1]
 *   @0x2ff4a4 cmp r6, r12
 *   @0x2ff4a6 bgt 0x2ff58a <TT_RunIns+0x2796>
 *   @0x2ff4a8 ldr r7, [sp, #0x1c]
 *   @0x2ff4aa adds r3, r6, #0x1
 *   @0x2ff4ac ldrb r2, [r7, r6]
 *   @0x2ff4ae cbnz r2, 0x2ff4b4 <TT_RunIns+0x26c0>
 *   @0x2ff4b0 mov r6, r3
 *   @0x2ff4b2 b 0x2ff4a4 <TT_RunIns+0x26b0>
 *   @0x2ff4b4 mov r10, r6
 *   @0x2ff4b6 mov r7, r6
 *   @0x2ff4b8 mov r6, r3
 *   @0x2ff4ba cmp r6, r12
 *   @0x2ff4bc bgt 0x2ff4ec <TT_RunIns+0x26f8>
 *   @0x2ff4be ldr r0, [sp, #0x1c]
 *   @0x2ff4c0 ldrb r3, [r0, r6]
 *   @0x2ff4c2 cbz r3, 0x2ff4e8 <TT_RunIns+0x26f4>
 *   @0x2ff4c4 adds r0, r7, #0x1
 *   @0x2ff4c6 subs r1, r6, #0x1
 *   @0x2ff4c8 cmp r0, r1
 *   @0x2ff4ca bgt 0x2ff4e6 <TT_RunIns+0x26f2>
 *   @0x2ff4cc ldr r2, [sp, #0x18]
 *   @0x2ff4ce mov r3, r6
 *   @0x2ff4d0 str.w r12, [sp, #0xc]
 *   @0x2ff4d4 stm.w sp, {r2, r11}
 *   @0x2ff4d8 mov r2, r7
 *   @0x2ff4da bl 0xb87e8 <.text+0x1818>
 *   @0x2ff4de mov r7, r6
 *   @0x2ff4e0 ldr.w r12, [sp, #0xc]
 *   @0x2ff4e4 b 0x2ff4e8 <TT_RunIns+0x26f4>
 *   @0x2ff4e6 mov r7, r6
 *   @0x2ff4e8 adds r6, #0x1
 *   @0x2ff4ea b 0x2ff4ba <TT_RunIns+0x26c6>
 *   @0x2ff4ec cmp r7, r10
 *   @0x2ff4ee bne 0x2ff556 <TT_RunIns+0x2762>
 *   @0x2ff4f0 ldr r2, [sp, #0x18]
 *   @0x2ff4f2 lsls r3, r7, #0x3
 *   @0x2ff4f4 ldr r0, [sp, #0x18]
 *   @0x2ff4f6 add.w lr, r11, r3
 *   @0x2ff4fa ldr.w r1, [r11, r7, lsl #3]
 *   @0x2ff4fe add r0, r3
 *   @0x2ff500 ldr.w r3, [r2, r7, lsl #3]
 *   @0x2ff504 ldr.w r2, [lr, #0x4]
 *   @0x2ff508 ldr r0, [r0, #0x4]
 *   @0x2ff50a subs r1, r1, r3
 *   @0x2ff50c rsb r2, r0, r2
 *   @0x2ff510 bne 0x2ff516 <TT_RunIns+0x2722>
 *   @0x2ff512 cmp r2, #0x0
 *   @0x2ff514 beq 0x2ff58a <TT_RunIns+0x2796>
 *   @0x2ff516 add.w r3, r11, r9, lsl #3
 *   @0x2ff51a cmp r9, r7
 *   @0x2ff51c add.w r3, r3, #0x8
 *   @0x2ff520 bge 0x2ff53c <TT_RunIns+0x2748>
 *   @0x2ff522 ldr r0, [r3, #-8]
 *   @0x2ff526 add.w r9, r9, #0x1
 *   @0x2ff52a add r0, r1
 *   @0x2ff52c str r0, [r3, #-8]
 *   @0x2ff530 ldr r0, [r3, #-4]
 *   @0x2ff534 add r0, r2
 *   @0x2ff536 str r0, [r3, #-4]
 *   @0x2ff53a b 0x2ff51a <TT_RunIns+0x2726>
 *   @0x2ff53c adds r7, #0x1
 *   @0x2ff53e mov r0, lr
 *   @0x2ff540 cmp r7, r12
 *   @0x2ff542 bgt 0x2ff58a <TT_RunIns+0x2796>
 *   @0x2ff544 ldr r3, [r0, #0x8]
 *   @0x2ff546 adds r7, #0x1
 *   @0x2ff548 adds r0, #0x8
 *   @0x2ff54a add r3, r1
 *   @0x2ff54c str r3, [r0]
 *   @0x2ff54e ldr r3, [r0, #0x4]
 *   @0x2ff550 add r3, r2
 *   @0x2ff552 str r3, [r0, #0x4]
 *   @0x2ff554 b 0x2ff540 <TT_RunIns+0x274c>
 *   @0x2ff556 adds r0, r7, #0x1
 *   @0x2ff558 cmp r0, r12
 *   @0x2ff55a bgt 0x2ff56c <TT_RunIns+0x2778>
 *   @0x2ff55c ldr r3, [sp, #0x18]
 *   @0x2ff55e mov r1, r12
 *   @0x2ff560 mov r2, r7
 *   @0x2ff562 stm.w sp, {r3, r11}
 *   @0x2ff566 mov r3, r10
 *   @0x2ff568 bl 0xb87e8 <.text+0x1818>
 *   @0x2ff56c cmp.w r10, #0x0
 *   @0x2ff570 ble 0x2ff58a <TT_RunIns+0x2796>
 *   @0x2ff572 add.w r1, r10, #0xffffffff
 *   @0x2ff576 cmp r9, r1
 *   @0x2ff578 bgt 0x2ff58a <TT_RunIns+0x2796>
 *   @0x2ff57a ldr r0, [sp, #0x18]
 *   @0x2ff57c mov r2, r7
 *   @0x2ff57e mov r3, r10
 *   @0x2ff580 stm.w sp, {r0, r11}
 *   @0x2ff584 mov r0, r9
 *   @0x2ff586 bl 0xb87e8 <.text+0x1818>
 *   @0x2ff58a ldr r7, [sp, #0x20]
 *   @0x2ff58c ldrsh.w r2, [r8]
 *   @0x2ff590 adds r3, r7, #0x1
 *   @0x2ff592 uxth r3, r3
 *   @0x2ff594 str r3, [sp, #0x20]
 *   @0x2ff596 sxth r3, r3
 *   @0x2ff598 cmp r2, r3
 *   @0x2ff59a ble.w 0x2ff48a <TT_RunIns+0x2696>
 *   @0x2ff59e mov r9, r6
 *   @0x2ff5a0 b 0x2ff496 <TT_RunIns+0x26a2>
 *   @0x2ff5a2 ldr r7, [sp, #0x14]
 *   @0x2ff5a4 cmp r2, r7
 *   @0x2ff5a6 beq.w 0x2ff354 <TT_RunIns+0x2560>
 *   @0x2ff5aa ldr r1, [sp, #0x18]
 *   @0x2ff5ac add.w r0, r11, r3
 *   @0x2ff5b0 ldr r7, [sp, #0x18]
 *   @0x2ff5b2 adds r2, #0x1
 *   @0x2ff5b4 add r1, r3
 *   @0x2ff5b6 ldr r0, [r0, #0x4]
 *   @0x2ff5b8 ldr.w r6, [r8, #0x4]
 *   @0x2ff5bc ldr r1, [r1, #0x4]
 *   @0x2ff5be rsb lr, r1, r0
 *   @0x2ff5c2 ldr.w r0, [r11, r3]
 *   @0x2ff5c6 ldr r1, [r7, r3]
 *   @0x2ff5c8 ldr r7, [r6, r3]
 *   @0x2ff5ca subs r1, r0, r1
 *   @0x2ff5cc add r7, r1
 *   @0x2ff5ce str r7, [r6, r3]
 *   @0x2ff5d0 ldr.w r0, [r8, #0x4]
 *   @0x2ff5d4 add r0, r3
 *   @0x2ff5d6 adds r3, #0x8
 *   @0x2ff5d8 ldr r1, [r0, #0x4]
 *   @0x2ff5da add r1, lr
 *   @0x2ff5dc str r1, [r0, #0x4]
 *   @0x2ff5de b 0x2ff5a2 <TT_RunIns+0x27ae>
 *   @0x2ff5e0 ldr r0, [sp, #0x10]
 *   @0x2ff5e2 ldr r1, [sp, #0x40]
 *   @0x2ff5e4 bl 0x2e7336 <ft_mem_free>
 *   @0x2ff5e8 ldr r0, [sp, #0x10]
 *   @0x2ff5ea ldr r1, [sp, #0x44]
 *   @0x2ff5ec bl 0x2e7336 <ft_mem_free>
 *   @0x2ff5f0 ldr r7, [sp, #0x24]
 *   @0x2ff5f2 ldr r0, [sp, #0x50]
 *   @0x2ff5f4 ldr r3, [r4]
 *   @0x2ff5f6 add r7, r0
 *   @0x2ff5f8 str r7, [sp, #0x24]
 *   @0x2ff5fa ldr r7, [sp, #0x54]
 *   @0x2ff5fc add r3, r7
 *   @0x2ff5fe str r3, [r4, #0x20]
 *   @0x2ff600 ldr r7, [sp, #0x48]
 *   @0x2ff602 adds r7, #0x1
 *   @0x2ff604 str r7, [sp, #0x48]
 *   @0x2ff606 b 0x2ff244 <TT_RunIns+0x2450>
 *   @0x2ff608 ldr r7, [sp, #0x34]
 *   @0x2ff60a adds r7, #0x1
 *   @0x2ff60c beq 0x2ff616 <TT_RunIns+0x2822>
 *   @0x2ff60e ldr r0, [sp, #0x10]
 *   @0x2ff610 ldr r1, [sp, #0x34]
 *   @0x2ff612 bl 0x2e7336 <ft_mem_free>
 *   @0x2ff616 ldr r0, [sp, #0x10]
 *   @0x2ff618 ldr r1, [sp, #0x38]
 *   @0x2ff61a bl 0x2e7336 <ft_mem_free>
 *   @0x2ff61e ldr r0, [sp, #0x10]
 *   @0x2ff620 ldr r1, [sp, #0x3c]
 *   @0x2ff622 bl 0x2e7336 <ft_mem_free>
 *   @0x2ff626 ldr r0, [sp, #0x10]
 *   @0x2ff628 ldr r1, [sp, #0x2c]
 *   @0x2ff62a bl 0x2e7336 <ft_mem_free>
 *   @0x2ff62e mov r0, r4
 *   @0x2ff630 bl 0x2e7eb8 <FT_Stream_ExitFrame>
 *   @0x2ff634 b 0x2ff640 <TT_RunIns+0x284c>
 *   @0x2ff636 str.w r11, [sp, #0x1c]
 *   @0x2ff63a b 0x2ff640 <TT_RunIns+0x284c>
 *   @0x2ff63c str.w r10, [sp, #0x1c]
 *   @0x2ff640 ldr r0, [sp, #0x10]
 *   @0x2ff642 ldr r1, [sp, #0x18]
 *   @0x2ff644 bl 0x2e7336 <ft_mem_free>
 *   @0x2ff648 ldr r0, [sp, #0x10]
 *   @0x2ff64a mov r1, r11
 *   @0x2ff64c bl 0x2e7336 <ft_mem_free>
 *   @0x2ff650 ldr r0, [sp, #0x10]
 *   @0x2ff652 ldr r1, [sp, #0x1c]
 *   @0x2ff654 bl 0x2e7336 <ft_mem_free>
 *   @0x2ff658 ldr r0, [sp, #0x64]
 *   @0x2ff65a b 0x2ff676 <TT_RunIns+0x2882>
 *   @0x2ff65c movs r0, #0x6
 *   @0x2ff65e b 0x2ff676 <TT_RunIns+0x2882>
 *   @0x2ff660 mov r0, r11
 *   @0x2ff662 b 0x2ff676 <TT_RunIns+0x2882>
 *   @0x2ff664 movs r7, #0x0
 *   @0x2ff666 str r7, [sp, #0x2c]
 *   @0x2ff668 str r7, [sp, #0x3c]
 *   @0x2ff66a b 0x2ff670 <TT_RunIns+0x287c>
 *   @0x2ff66c movs r7, #0x0
 *   @0x2ff66e str r7, [sp, #0x2c]
 *   @0x2ff670 movs r7, #0x0
 *   @0x2ff672 str r7, [sp, #0x34]
 *   @0x2ff674 b 0x2ff60e <TT_RunIns+0x281a>
 *   @0x2ff676 add sp, #0x74
 *   @0x2ff678 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ff67c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ff680 sub sp, #0xd4
 *   @0x2ff682 ldr.w r11, [r0]
 *   @0x2ff686 mov r8, r3
 *   @0x2ff688 movs r3, #0x0
 *   @0x2ff68a str r3, [sp, #0x5c]
 *   @0x2ff68c mov r4, r0
 *   @0x2ff68e ldr r5, [r0, #0xc]
 *   @0x2ff690 ldrh.w r3, [r11, #0x122]
 *   @0x2ff694 mov r6, r1
 *   @0x2ff696 str r2, [sp, #0x20]
 *   @0x2ff698 cmp r2, r3
 *   @0x2ff69a it hi
 *   @0x2ff69c strhhi.w r2, [r11, #0x122]
 *   @0x2ff6a0 str r1, [r4, #0x14]
 *   @0x2ff6a2 ldr r3, [r0, #0x10]
 *   @0x2ff6a4 str r5, [sp, #0x14]
 *   @0x2ff6a6 lsls r7, r3, #0x1f
 *   @0x2ff6a8 bmi 0x2ff6b6 <TT_RunIns+0x28c2>
 *   @0x2ff6aa ldr r3, [r0, #0x4]
 *   @0x2ff6ac ldr r3, [r3, #0x2c]
 *   @0x2ff6ae ldr r7, [r3, #0x4]
 *   @0x2ff6b0 ldr r3, [r3, #0x8]
 *   @0x2ff6b2 str r3, [sp, #0x18]
 *   @0x2ff6b4 b 0x2ff6be <TT_RunIns+0x28ca>
 *   @0x2ff6b6 mov.w r5, #0x10000
 *   @0x2ff6ba str r5, [sp, #0x18]
 *   @0x2ff6bc mov r7, r5
 *   @0x2ff6be ldr.w r3, [r11, #0x80]
 *   @0x2ff6c2 ldr r5, [r3, #0x34]
 *   @0x2ff6c4 cbz r5, 0x2ff708 <TT_RunIns+0x2914>
 *   @0x2ff6c6 ldr r3, [r5]
 *   @0x2ff6c8 mov r1, r6
 *   @0x2ff6ca ldr r0, [r5, #0x4]
 *   @0x2ff6cc add r2, sp, #0x64
 *   @0x2ff6ce ldr r3, [r3]
 *   @0x2ff6d0 blx r3
 *   @0x2ff6d2 mov r5, r0
 *   @0x2ff6d4 str r0, [sp, #0x5c]
 *   @0x2ff6d6 cmp r0, #0x0
 *   @0x2ff6d8 bne.w 0x300200 <TT_RunIns+0x340c>
 *   @0x2ff6dc ldr.w r10, [sp, #0x68]
 *   @0x2ff6e0 add.w r9, sp, #0xa8
 *   @0x2ff6e4 mov r1, r5
 *   @0x2ff6e6 movs r2, #0x28
 *   @0x2ff6e8 mov r0, r9
 *   @0x2ff6ea str.w r10, [r4, #0x1c]
 *   @0x2ff6ee blx 0xb65b0 <memset@plt>
 *   @0x2ff6f2 mov r0, r9
 *   @0x2ff6f4 ldr r1, [sp, #0x64]
 *   @0x2ff6f6 mov r2, r10
 *   @0x2ff6f8 bl 0x2e688a <FT_Stream_OpenMemory>
 *   @0x2ff6fc movs r0, #0x1
 *   @0x2ff6fe str.w r9, [r4, #0x18]
 *   @0x2ff702 mov r12, r5
 *   @0x2ff704 str r0, [sp, #0x28]
 *   @0x2ff706 b 0x2ff718 <TT_RunIns+0x2924>
 *   @0x2ff708 mov r0, r11
 *   @0x2ff70a mov r1, r6
 *   @0x2ff70c add.w r2, r4, #0x1c
 *   @0x2ff710 bl 0x2f9bb2 <ps_hints_apply+0x87b2>
 *   @0x2ff714 str r5, [sp, #0x28]
 *   @0x2ff716 mov r12, r0
 *   @0x2ff718 ldr r3, [r4, #0x1c]
 *   @0x2ff71a cmp r3, #0x0
 *   @0x2ff71c ble 0x2ff774 <TT_RunIns+0x2980>
 *   @0x2ff71e ldr.w r2, [r11, #0x2b0]
 *   @0x2ff722 cbnz r2, 0x2ff734 <TT_RunIns+0x2940>
 *   @0x2ff724 ldr.w r1, [r11, #0x80]
 *   @0x2ff728 ldr r1, [r1, #0x34]
 *   @0x2ff72a cbnz r1, 0x2ff734 <TT_RunIns+0x2940>
 *   @0x2ff72c movs r3, #0x8
 *   @0x2ff72e str r3, [sp, #0x5c]
 *   @0x2ff730 b.w 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2ff734 ldr.w r5, [r11, #0x208]
 *   @0x2ff738 mov r0, r4
 *   @0x2ff73a mov r1, r6
 *   @0x2ff73c add r2, r12
 *   @0x2ff73e blx r5
 *   @0x2ff740 str r0, [sp, #0x5c]
 *   @0x2ff742 cmp r0, #0x0
 *   @0x2ff744 bne.w 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2ff748 ldr.w r3, [r11, #0x210]
 *   @0x2ff74c mov r0, r4
 *   @0x2ff74e blx r3
 *   @0x2ff750 str r0, [sp, #0x5c]
 *   @0x2ff752 cmp r0, #0x0
 *   @0x2ff754 bne.w 0x3001e4 <TT_RunIns+0x33f0>
 *   @0x2ff758 mov r0, r4
 *   @0x2ff75a mov r1, r6
 *   @0x2ff75c bl 0x2fa522 <ps_hints_apply+0x9122>
 *   @0x2ff760 str r0, [sp, #0x5c]
 *   @0x2ff762 cmp r0, #0x0
 *   @0x2ff764 bne.w 0x3001e4 <TT_RunIns+0x33f0>
 *   @0x2ff768 cmp.w r8, #0x0
 *   @0x2ff76c bne.w 0x3001e4 <TT_RunIns+0x33f0>
 *   @0x2ff770 movs r5, #0x1
 *   @0x2ff772 b 0x2ff776 <TT_RunIns+0x2982>
 *   @0x2ff774 movs r5, #0x0
 *   @0x2ff776 ldr r3, [r4, #0x1c]
 *   @0x2ff778 str r5, [sp, #0x10]
 *   @0x2ff77a cbz r3, 0x2ff786 <TT_RunIns+0x2992>
 *   @0x2ff77c ldrsh.w r3, [r4, #0x20]
 *   @0x2ff780 cmp r3, #0x0
 *   @0x2ff782 bne.w 0x2ff8c8 <TT_RunIns+0x2ad4>
 *   @0x2ff786 movs r3, #0x0
 *   @0x2ff788 mov r0, r4
 *   @0x2ff78a str r3, [r4, #0x24]
 *   @0x2ff78c mov r1, r6
 *   @0x2ff78e str r3, [r4, #0x2c]
 *   @0x2ff790 str r3, [r4, #0x28]
 *   @0x2ff792 str r3, [r4, #0x30]
 *   @0x2ff794 bl 0x2fa522 <ps_hints_apply+0x9122>
 *   @0x2ff798 str r0, [sp, #0x5c]
 *   @0x2ff79a cmp r0, #0x0
 *   @0x2ff79c bne.w 0x3001e0 <TT_RunIns+0x33ec>
 *   @0x2ff7a0 cmp.w r8, #0x0
 *   @0x2ff7a4 bne.w 0x3001e0 <TT_RunIns+0x33ec>
 *   @0x2ff7a8 mov r0, r4
 *   @0x2ff7aa bl 0x2f8f3a <ps_hints_apply+0x7b3a>
 *   @0x2ff7ae mov r0, r4
 *   @0x2ff7b0 mov r1, r6
 *   @0x2ff7b2 bl 0x2f8e8c <ps_hints_apply+0x7a8c>
 *   @0x2ff7b6 ldr r2, [r4]
 *   @0x2ff7b8 ldrb.w r3, [r2, #0x2bc]
 *   @0x2ff7bc cmp r3, #0x0
 *   @0x2ff7be bne 0x2ff870 <TT_RunIns+0x2a7c>
 *   @0x2ff7c0 ldr.w r1, [pc, #0x874]
 *   @0x2ff7c4 add r3, sp, #0x6c
 *   @0x2ff7c6 add r1, pc
 *   @0x2ff7c8 addw r1, r1, #0x59c
 *   @0x2ff7cc ldr r0, [r1, #-4]
 *   @0x2ff7d0 str r0, [sp, #0x60]
 *   @0x2ff7d2 ldr r0, [r1]
 *   @0x2ff7d4 ldr r1, [r1, #0x4]
 *   @0x2ff7d6 stm r3!, {r0, r1}
 *   @0x2ff7d8 add r1, sp, #0x88
 *   @0x2ff7da ldr r3, [r4, #0x44]
 *   @0x2ff7dc mov r0, r2
 *   @0x2ff7de str r1, [sp, #0x78]
 *   @0x2ff7e0 add r2, sp, #0x74
 *   @0x2ff7e2 add r1, sp, #0x60
 *   @0x2ff7e4 str r1, [sp, #0x7c]
 *   @0x2ff7e6 str r3, [sp, #0x88]
 *   @0x2ff7e8 add r1, sp, #0x6c
 *   @0x2ff7ea ldr r3, [r4, #0x48]
 *   @0x2ff7ec str r1, [sp, #0x80]
 *   @0x2ff7ee mov r1, r6
 *   @0x2ff7f0 str r3, [sp, #0x8c]
 *   @0x2ff7f2 ldr r3, [r4, #0x4c]
 *   @0x2ff7f4 str r3, [sp, #0x90]
 *   @0x2ff7f6 ldr r3, [r4, #0x50]
 *   @0x2ff7f8 str r3, [sp, #0x94]
 *   @0x2ff7fa ldr.w r3, [r4, #0xb4]
 *   @0x2ff7fe str r3, [sp, #0x98]
 *   @0x2ff800 ldr.w r3, [r4, #0xb8]
 *   @0x2ff804 str r3, [sp, #0x9c]
 *   @0x2ff806 ldr.w r3, [r4, #0xbc]
 *   @0x2ff80a str r3, [sp, #0xa0]
 *   @0x2ff80c ldr.w r3, [r4, #0xc0]
 *   @0x2ff810 str r3, [sp, #0xa4]
 *   @0x2ff812 movs r3, #0x4
 *   @0x2ff814 strh.w r3, [sp, #0x76]
 *   @0x2ff818 strh.w r3, [sp, #0x74]
 *   @0x2ff81c bl 0x2ff08c <TT_RunIns+0x2298>
 *   @0x2ff820 str r0, [sp, #0x5c]
 *   @0x2ff822 cmp r0, #0x0
 *   @0x2ff824 bne.w 0x3001e0 <TT_RunIns+0x33ec>
 *   @0x2ff828 ldr r3, [sp, #0x8c]
 *   @0x2ff82a ldr r2, [sp, #0x9c]
 *   @0x2ff82c ldr r1, [sp, #0xa4]
 *   @0x2ff82e str r3, [r4, #0x48]
 *   @0x2ff830 ldr r3, [sp, #0x94]
 *   @0x2ff832 ldr r6, [sp, #0x88]
 *   @0x2ff834 str.w r2, [r4, #0xb8]
 *   @0x2ff838 str r3, [r4, #0x50]
 *   @0x2ff83a str.w r1, [r4, #0xc0]
 *   @0x2ff83e ldr r3, [sp, #0x98]
 *   @0x2ff840 ldr r0, [sp, #0x90]
 *   @0x2ff842 ldr r2, [sp, #0xa0]
 *   @0x2ff844 ldr r1, [r4]
 *   @0x2ff846 str r6, [r4, #0x44]
 *   @0x2ff848 str.w r3, [r4, #0xb4]
 *   @0x2ff84c str r0, [r4, #0x4c]
 *   @0x2ff84e str.w r2, [r4, #0xbc]
 *   @0x2ff852 ldr.w r5, [r1, #0x2c0]
 *   @0x2ff856 lsls r5, r5, #0x1e
 *   @0x2ff858 itt pl
 *   @0x2ff85a rsbpl r6, r6, r0
 *   @0x2ff85e strpl r6, [r4, #0x3c]
 *   @0x2ff860 ldr.w r1, [r1, #0x2c0]
 *   @0x2ff864 lsls r1, r1, #0x1b
 *   @0x2ff866 itt pl
 *   @0x2ff868 rsbpl r3, r3, r2
 *   @0x2ff86c strpl.w r3, [r4, #0xb0]
 *   @0x2ff870 ldr r3, [r4, #0x10]
 *   @0x2ff872 lsls r3, r3, #0x1f
 *   @0x2ff874 bmi 0x2ff8c2 <TT_RunIns+0x2ace>
 *   @0x2ff876 mov r1, r7
 *   @0x2ff878 ldr r0, [r4, #0x44]
 *   @0x2ff87a bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff87e mov r1, r7
 *   @0x2ff880 str r0, [r4, #0x44]
 *   @0x2ff882 ldr r0, [r4, #0x4c]
 *   @0x2ff884 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff888 mov r1, r7
 *   @0x2ff88a str r0, [r4, #0x4c]
 *   @0x2ff88c ldr.w r0, [r4, #0xb4]
 *   @0x2ff890 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff894 ldr r1, [sp, #0x18]
 *   @0x2ff896 str.w r0, [r4, #0xb4]
 *   @0x2ff89a ldr.w r0, [r4, #0xb8]
 *   @0x2ff89e bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff8a2 mov r1, r7
 *   @0x2ff8a4 str.w r0, [r4, #0xb8]
 *   @0x2ff8a8 ldr.w r0, [r4, #0xbc]
 *   @0x2ff8ac bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff8b0 ldr r1, [sp, #0x18]
 *   @0x2ff8b2 str.w r0, [r4, #0xbc]
 *   @0x2ff8b6 ldr.w r0, [r4, #0xc0]
 *   @0x2ff8ba bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ff8be str.w r0, [r4, #0xc0]
 *   @0x2ff8c2 movs r3, #0x0
 *   @0x2ff8c4 b.w 0x3001de <TT_RunIns+0x33ea>
 *   @0x2ff8c8 mov r0, r4
 *   @0x2ff8ca bl 0x2f8f3a <ps_hints_apply+0x7b3a>
 *   @0x2ff8ce mov r0, r4
 *   @0x2ff8d0 mov r1, r6
 *   @0x2ff8d2 bl 0x2f8e8c <ps_hints_apply+0x7a8c>
 *   @0x2ff8d6 ldrsh.w r3, [r4, #0x20]
 *   @0x2ff8da cmp r3, #0x0
 *   @0x2ff8dc ble.w 0x2ffac4 <TT_RunIns+0x2cd0>
 *   @0x2ff8e0 ldr.w r3, [r11, #0x214]
 *   @0x2ff8e4 mov r0, r4
 *   @0x2ff8e6 blx r3
 *   @0x2ff8e8 mov r8, r0
 *   @0x2ff8ea str r0, [sp, #0x5c]
 *   @0x2ff8ec cmp r0, #0x0
 *   @0x2ff8ee bne.w 0x3001e0 <TT_RunIns+0x33ec>
 *   @0x2ff8f2 ldr.w r3, [r11, #0x20c]
 *   @0x2ff8f6 mov r0, r4
 *   @0x2ff8f8 blx r3
 *   @0x2ff8fa ldr r5, [r4, #0xc]
 *   @0x2ff8fc add.w r0, r4, #0x44
 *   @0x2ff900 str r0, [sp, #0x18]
 *   @0x2ff902 add.w r10, r4, #0x4c
 *   @0x2ff906 ldrh r6, [r5, #0x3a]
 *   @0x2ff908 ldr r3, [r5, #0x3c]
 *   @0x2ff90a ldm r0, {r0, r1}
 *   @0x2ff90c sxth r7, r6
 *   @0x2ff90e lsl.w r9, r7, #0x3
 *   @0x2ff912 add r3, r9
 *   @0x2ff914 stm.w r3, {r0, r1}
 *   @0x2ff918 movs r3, #0x8
 *   @0x2ff91a smlabb r12, r6, r3, r3
 *   @0x2ff91e ldr r2, [r5, #0x3c]
 *   @0x2ff920 ldm.w r10, {r0, r1}
 *   @0x2ff924 add r2, r12
 *   @0x2ff926 stm.w r2, {r0, r1}
 *   @0x2ff92a movs r2, #0x10
 *   @0x2ff92c smlabb r2, r6, r3, r2
 *   @0x2ff930 ldr r1, [r5, #0x3c]
 *   @0x2ff932 add r2, r1
 *   @0x2ff934 add.w r1, r4, #0xb4
 *   @0x2ff938 ldm r1, {r0, r1}
 *   @0x2ff93a stm.w r2, {r0, r1}
 *   @0x2ff93e movs r2, #0x18
 *   @0x2ff940 smlabb r3, r6, r3, r2
 *   @0x2ff944 ldr r2, [r5, #0x3c]
 *   @0x2ff946 add r3, r2
 *   @0x2ff948 add.w r2, r4, #0xbc
 *   @0x2ff94c ldm.w r2, {r0, r1}
 *   @0x2ff950 stm.w r3, {r0, r1}
 *   @0x2ff954 ldr r3, [r5, #0x40]
 *   @0x2ff956 strb.w r8, [r3, r7]
 *   @0x2ff95a ldr r3, [r5, #0x40]
 *   @0x2ff95c add r3, r7
 *   @0x2ff95e strb.w r8, [r3, #0x1]
 *   @0x2ff962 ldr r3, [r5, #0x40]
 *   @0x2ff964 add r3, r7
 *   @0x2ff966 strb.w r8, [r3, #0x2]
 *   @0x2ff96a ldr r3, [r5, #0x40]
 *   @0x2ff96c add r3, r7
 *   @0x2ff96e strb.w r8, [r3, #0x3]
 *   @0x2ff972 adds r3, r7, #0x4
 *   @0x2ff974 ldr r0, [r4]
 *   @0x2ff976 ldrb.w r2, [r0, #0x2bc]
 *   @0x2ff97a cbz r2, 0x2ff9bc <TT_RunIns+0x2bc8>
 *   @0x2ff97c ldr r7, [r4, #0x10]
 *   @0x2ff97e ands r7, r7, #0x2
 *   @0x2ff982 bne 0x2ffa10 <TT_RunIns+0x2c1c>
 *   @0x2ff984 ldrh r2, [r5, #0x3a]
 *   @0x2ff986 strh.w r2, [r4, #0x80]
 *   @0x2ff98a adds r2, #0x4
 *   @0x2ff98c ldrh r3, [r5, #0x38]
 *   @0x2ff98e lsls r2, r2, #0x3
 *   @0x2ff990 strh.w r3, [r4, #0x82]
 *   @0x2ff994 ldr r3, [r5, #0x4c]
 *   @0x2ff996 str.w r3, [r4, #0x84]
 *   @0x2ff99a ldr r1, [r5, #0x3c]
 *   @0x2ff99c str.w r1, [r4, #0x88]
 *   @0x2ff9a0 ldr r0, [r5, #0x50]
 *   @0x2ff9a2 str.w r0, [r4, #0x8c]
 *   @0x2ff9a6 ldr r3, [r5, #0x40]
 *   @0x2ff9a8 str.w r3, [r4, #0x90]
 *   @0x2ff9ac ldr r3, [r5, #0x44]
 *   @0x2ff9ae strh.w r7, [r4, #0x98]
 *   @0x2ff9b2 str.w r3, [r4, #0x94]
 *   @0x2ff9b6 blx 0xb65bc <memcpy@plt>
 *   @0x2ff9ba b 0x2ffa10 <TT_RunIns+0x2c1c>
 *   @0x2ff9bc add.w r2, r5, #0x38
 *   @0x2ff9c0 ldr r1, [r4, #0x14]
 *   @0x2ff9c2 str.w r12, [sp, #0xc]
 *   @0x2ff9c6 bl 0x2ff08c <TT_RunIns+0x2298>
 *   @0x2ff9ca ldr r3, [r4]
 *   @0x2ff9cc ldr.w r12, [sp, #0xc]
 *   @0x2ff9d0 ldr.w r2, [r3, #0x2c0]
 *   @0x2ff9d4 tst.w r2, #0x2
 *   @0x2ff9d8 bne 0x2ff9e8 <TT_RunIns+0x2bf4>
 *   @0x2ff9da ldr r2, [r5, #0x3c]
 *   @0x2ff9dc ldr.w r1, [r2, r12]
 *   @0x2ff9e0 ldr.w r2, [r2, r7, lsl #3]
 *   @0x2ff9e4 subs r2, r1, r2
 *   @0x2ff9e6 str r2, [r4, #0x3c]
 *   @0x2ff9e8 ldr.w r3, [r3, #0x2c0]
 *   @0x2ff9ec lsls r7, r3, #0x1b
 *   @0x2ff9ee bmi 0x2ffa0a <TT_RunIns+0x2c16>
 *   @0x2ff9f0 movs r2, #0x8
 *   @0x2ff9f2 movs r1, #0x18
 *   @0x2ff9f4 movs r7, #0x10
 *   @0x2ff9f6 ldr r3, [r5, #0x3c]
 *   @0x2ff9f8 smlabb r1, r6, r2, r1
 *   @0x2ff9fc smlabb r2, r6, r2, r7
 *   @0x2ffa00 ldr r1, [r3, r1]
 *   @0x2ffa02 ldr r3, [r3, r2]
 *   @0x2ffa04 subs r3, r1, r3
 *   @0x2ffa06 str.w r3, [r4, #0xb0]
 *   @0x2ffa0a cmp r0, #0x0
 *   @0x2ffa0c beq 0x2ff97c <TT_RunIns+0x2b88>
 *   @0x2ffa0e b 0x2ffab4 <TT_RunIns+0x2cc0>
 *   @0x2ffa10 ldr r3, [r4, #0x10]
 *   @0x2ffa12 ldr r2, [r5, #0x3c]
 *   @0x2ffa14 lsls r1, r3, #0x1f
 *   @0x2ffa16 bmi 0x2ffa98 <TT_RunIns+0x2ca4>
 *   @0x2ffa18 ldr r3, [r4, #0x4]
 *   @0x2ffa1a ldr r3, [r3, #0x2c]
 *   @0x2ffa1c ldr r1, [r3, #0x4]
 *   @0x2ffa1e ldr r7, [r3, #0x8]
 *   @0x2ffa20 movs r3, #0x20
 *   @0x2ffa22 str r1, [sp, #0x20]
 *   @0x2ffa24 movs r1, #0x8
 *   @0x2ffa26 smlabb r6, r6, r1, r3
 *   @0x2ffa2a add.w r8, r2, r6
 *   @0x2ffa2e cmp r8, r2
 *   @0x2ffa30 add.w r6, r2, #0x8
 *   @0x2ffa34 bls 0x2ffa56 <TT_RunIns+0x2c62>
 *   @0x2ffa36 ldr r1, [sp, #0x20]
 *   @0x2ffa38 ldr r0, [r6, #-8]
 *   @0x2ffa3c bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ffa40 mov r1, r7
 *   @0x2ffa42 str r0, [r6, #-8]
 *   @0x2ffa46 ldr r0, [r6, #-4]
 *   @0x2ffa4a bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ffa4e mov r2, r6
 *   @0x2ffa50 str r0, [r6, #-4]
 *   @0x2ffa54 b 0x2ffa2e <TT_RunIns+0x2c3a>
 *   @0x2ffa56 ldr r3, [r5, #0x3c]
 *   @0x2ffa58 ldr r2, [sp, #0x18]
 *   @0x2ffa5a add r3, r9
 *   @0x2ffa5c ldm.w r3, {r0, r1}
 *   @0x2ffa60 stm.w r2, {r0, r1}
 *   @0x2ffa64 ldr r3, [r5, #0x3c]
 *   @0x2ffa66 add r3, r9
 *   @0x2ffa68 adds r3, #0x8
 *   @0x2ffa6a ldm.w r3, {r0, r1}
 *   @0x2ffa6e add.w r3, r4, #0xb4
 *   @0x2ffa72 stm.w r10, {r0, r1}
 *   @0x2ffa76 ldr r2, [r5, #0x3c]
 *   @0x2ffa78 add r2, r9
 *   @0x2ffa7a adds r2, #0x10
 *   @0x2ffa7c ldm.w r2, {r0, r1}
 *   @0x2ffa80 stm.w r3, {r0, r1}
 *   @0x2ffa84 ldr r3, [r5, #0x3c]
 *   @0x2ffa86 add r9, r3
 *   @0x2ffa88 add.w r3, r4, #0xbc
 *   @0x2ffa8c add.w r9, r9, #0x18
 *   @0x2ffa90 ldm.w r9, {r0, r1}
 *   @0x2ffa94 stm.w r3, {r0, r1}
 *   @0x2ffa98 ldr r1, [r4, #0x10]
 *   @0x2ffa9a ands r1, r1, #0x2
 *   @0x2ffa9e bne 0x2ffab2 <TT_RunIns+0x2cbe>
 *   @0x2ffaa0 ldrh.w r3, [r4, #0x80]
 *   @0x2ffaa4 mov r0, r4
 *   @0x2ffaa6 adds r3, #0x4
 *   @0x2ffaa8 strh.w r3, [r4, #0x80]
 *   @0x2ffaac bl 0x2fec70 <TT_RunIns+0x1e7c>
 *   @0x2ffab0 b 0x2ffab4 <TT_RunIns+0x2cc0>
 *   @0x2ffab2 movs r0, #0x0
 *   @0x2ffab4 str r0, [sp, #0x5c]
 *   @0x2ffab6 cmp r0, #0x0
 *   @0x2ffab8 bne.w 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2ffabc ldr r0, [sp, #0x14]
 *   @0x2ffabe bl 0x2e52f8 <FT_GlyphLoader_Add>
 *   @0x2ffac2 b 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2ffac4 adds r3, #0x1
 *   @0x2ffac6 bne.w 0x3001dc <TT_RunIns+0x33e8>
 *   @0x2ffaca ldr.w r10, [r11, #0x64]
 *   @0x2fface add.w r8, r4, #0xcc
 *   @0x2ffad2 ldr.w r9, [r4, #0xcc]
 *   @0x2ffad6 ldr r3, [sp, #0x20]
 *   @0x2ffad8 cmp.w r9, #0x0
 *   @0x2ffadc beq 0x2ffae8 <TT_RunIns+0x2cf4>
 *   @0x2ffade cbz r3, 0x2ffae8 <TT_RunIns+0x2cf4>
 *   @0x2ffae0 subs r3, #0x1
 *   @0x2ffae2 ldr.w r9, [r9, #0x4]
 *   @0x2ffae6 b 0x2ffad8 <TT_RunIns+0x2ce4>
 *   @0x2ffae8 mov r3, r9
 *   @0x2ffaea mov.w r2, #0xffffffff
 *   @0x2ffaee cbz r3, 0x2ffaf6 <TT_RunIns+0x2d02>
 *   @0x2ffaf0 str r2, [r3, #0x8]
 *   @0x2ffaf2 ldr r3, [r3, #0x4]
 *   @0x2ffaf4 b 0x2ffaee <TT_RunIns+0x2cfa>
 *   @0x2ffaf6 mov r0, r8
 *   @0x2ffaf8 mov r1, r6
 *   @0x2ffafa bl 0x2e890e <FT_List_Find>
 *   @0x2ffafe cbz r0, 0x2ffb04 <TT_RunIns+0x2d10>
 *   @0x2ffb00 movs r3, #0x15
 *   @0x2ffb02 b 0x3001de <TT_RunIns+0x33ea>
 *   @0x2ffb04 cmp.w r9, #0x0
 *   @0x2ffb08 beq 0x2ffb10 <TT_RunIns+0x2d1c>
 *   @0x2ffb0a str.w r6, [r9, #0x8]
 *   @0x2ffb0e b 0x2ffb2c <TT_RunIns+0x2d38>
 *   @0x2ffb10 movs r1, #0xc
 *   @0x2ffb12 mov r0, r10
 *   @0x2ffb14 add r2, sp, #0x5c
 *   @0x2ffb16 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2ffb1a ldr r3, [sp, #0x5c]
 *   @0x2ffb1c mov r1, r0
 *   @0x2ffb1e cmp r3, #0x0
 *   @0x2ffb20 bne.w 0x3001e0 <TT_RunIns+0x33ec>
 *   @0x2ffb24 str r6, [r0, #0x8]
 *   @0x2ffb26 mov r0, r8
 *   @0x2ffb28 bl 0x2e8920 <FT_List_Add>
 *   @0x2ffb2c ldr r5, [sp, #0x14]
 *   @0x2ffb2e mov r0, r4
 *   @0x2ffb30 ldr.w r3, [r11, #0x218]
 *   @0x2ffb34 ldrh r5, [r5, #0x16]
 *   @0x2ffb36 str r5, [sp, #0x2c]
 *   @0x2ffb38 ldr r5, [sp, #0x14]
 *   @0x2ffb3a ldrh r5, [r5, #0x14]
 *   @0x2ffb3c str r5, [sp, #0x34]
 *   @0x2ffb3e blx r3
 *   @0x2ffb40 str r0, [sp, #0x5c]
 *   @0x2ffb42 cmp r0, #0x0
 *   @0x2ffb44 bne.w 0x3001e0 <TT_RunIns+0x33ec>
 *   @0x2ffb48 ldr.w r5, [r4, #0xa4]
 *   @0x2ffb4c mov r0, r4
 *   @0x2ffb4e ldr.w r3, [r11, #0x20c]
 *   @0x2ffb52 str r5, [sp, #0x38]
 *   @0x2ffb54 blx r3
 *   @0x2ffb56 ldrb.w r2, [r11, #0x2bc]
 *   @0x2ffb5a cmp r2, #0x0
 *   @0x2ffb5c bne.w 0x2ffd7e <TT_RunIns+0x2f8a>
 *   @0x2ffb60 ldr r5, [sp, #0x14]
 *   @0x2ffb62 add.w r9, sp, #0x5c
 *   @0x2ffb66 mov r0, r10
 *   @0x2ffb68 movs r1, #0x8
 *   @0x2ffb6a ldr r3, [r5, #0x54]
 *   @0x2ffb6c str r2, [sp]
 *   @0x2ffb6e str.w r9, [sp, #0x4]
 *   @0x2ffb72 uxth r5, r3
 *   @0x2ffb74 adds r3, #0x4
 *   @0x2ffb76 str r5, [sp, #0x1c]
 *   @0x2ffb78 uxth r3, r3
 *   @0x2ffb7a strh.w r3, [sp, #0x8a]
 *   @0x2ffb7e strh.w r3, [sp, #0x88]
 *   @0x2ffb82 sxth r3, r3
 *   @0x2ffb84 str r2, [sp, #0x8c]
 *   @0x2ffb86 str r2, [sp, #0x90]
 *   @0x2ffb88 str r2, [sp, #0x94]
 *   @0x2ffb8a bl 0x2e808e <ft_mem_realloc>
 *   @0x2ffb8e ldr r2, [sp, #0x5c]
 *   @0x2ffb90 mov r5, r0
 *   @0x2ffb92 cmp r2, #0x0
 *   @0x2ffb94 bne.w 0x2ffd56 <TT_RunIns+0x2f62>
 *   @0x2ffb98 stm.w sp, {r2, r9}
 *   @0x2ffb9c mov r0, r10
 *   @0x2ffb9e ldrsh.w r3, [sp, #0x8a]
 *   @0x2ffba2 movs r1, #0x1
 *   @0x2ffba4 bl 0x2e808e <ft_mem_realloc>
 *   @0x2ffba8 ldr r2, [sp, #0x5c]
 *   @0x2ffbaa mov r8, r0
 *   @0x2ffbac cmp r2, #0x0
 *   @0x2ffbae bne.w 0x2ffd56 <TT_RunIns+0x2f62>
 *   @0x2ffbb2 stm.w sp, {r2, r9}
 *   @0x2ffbb6 mov r0, r10
 *   @0x2ffbb8 ldrsh.w r3, [sp, #0x8a]
 *   @0x2ffbbc movs r1, #0x2
 *   @0x2ffbbe bl 0x2e808e <ft_mem_realloc>
 *   @0x2ffbc2 ldr r2, [sp, #0x5c]
 *   @0x2ffbc4 cmp r2, #0x0
 *   @0x2ffbc6 bne.w 0x2ffd56 <TT_RunIns+0x2f62>
 *   @0x2ffbca ldr r1, [sp, #0x14]
 *   @0x2ffbcc mov lr, r5
 *   @0x2ffbce ldr r3, [sp, #0x1c]
 *   @0x2ffbd0 ldr.w r12, [r1, #0x58]
 *   @0x2ffbd4 sxth.w r9, r3
 *   @0x2ffbd8 uxth r1, r2
 *   @0x2ffbda add.w lr, lr, #0x8
 *   @0x2ffbde sxth r3, r1
 *   @0x2ffbe0 cmp r3, r9
 *   @0x2ffbe2 bge 0x2ffc08 <TT_RunIns+0x2e14>
 *   @0x2ffbe4 ldr.w r3, [r12, #0x8]
 *   @0x2ffbe8 add.w r12, r12, #0x20
 *   @0x2ffbec str r3, [lr, #-8]
 *   @0x2ffbf0 ldr r3, [r12, #-20]
 *   @0x2ffbf4 str r3, [lr, #-4]
 *   @0x2ffbf8 mov.w r3, #0x1
 *   @0x2ffbfc strb.w r3, [r8, r2]
 *   @0x2ffc00 strh.w r1, [r0, r2, lsl #1]
 *   @0x2ffc04 adds r2, #0x1
 *   @0x2ffc06 b 0x2ffbd8 <TT_RunIns+0x2de4>
 *   @0x2ffc08 ldr r2, [r4, #0x44]
 *   @0x2ffc0a add.w lr, r5, r3, lsl #3
 *   @0x2ffc0e uxth.w r9, r1
 *   @0x2ffc12 str.w r2, [r5, r3, lsl #3]
 *   @0x2ffc16 ldr r2, [r4, #0x48]
 *   @0x2ffc18 str.w r2, [lr, #0x4]
 *   @0x2ffc1c movs r2, #0x1
 *   @0x2ffc1e add.w lr, r9, r2
 *   @0x2ffc22 strb.w r2, [r8, r3]
 *   @0x2ffc26 strh.w r1, [r0, r3, lsl #1]
 *   @0x2ffc2a uxth.w lr, lr
 *   @0x2ffc2e ldr r1, [r4, #0x4c]
 *   @0x2ffc30 sxth.w r3, lr
 *   @0x2ffc34 str.w r1, [r5, r3, lsl #3]
 *   @0x2ffc38 add.w r12, r5, r3, lsl #3
 *   @0x2ffc3c ldr r1, [r4, #0x50]
 *   @0x2ffc3e str.w r1, [r12, #0x4]
 *   @0x2ffc42 strb.w r2, [r8, r3]
 *   @0x2ffc46 strh.w lr, [r0, r3, lsl #1]
 *   @0x2ffc4a add.w lr, r9, #0x2
 *   @0x2ffc4e ldr.w r1, [r4, #0xb4]
 *   @0x2ffc52 uxth.w lr, lr
 *   @0x2ffc56 sxth.w r3, lr
 *   @0x2ffc5a str.w r1, [r5, r3, lsl #3]
 *   @0x2ffc5e add.w r12, r5, r3, lsl #3
 *   @0x2ffc62 ldr.w r1, [r4, #0xb8]
 *   @0x2ffc66 str.w r1, [r12, #0x4]
 *   @0x2ffc6a add.w r1, r9, #0x3
 *   @0x2ffc6e strb.w r2, [r8, r3]
 *   @0x2ffc72 uxth.w r12, r1
 *   @0x2ffc76 strh.w lr, [r0, r3, lsl #1]
 *   @0x2ffc7a ldr.w r1, [r4, #0xbc]
 *   @0x2ffc7e sxth.w r3, r12
 *   @0x2ffc82 str.w r1, [r5, r3, lsl #3]
 *   @0x2ffc86 add.w lr, r5, r3, lsl #3
 *   @0x2ffc8a ldr.w r1, [r4, #0xc0]
 *   @0x2ffc8e str.w r1, [lr, #0x4]
 *   @0x2ffc92 mov r1, r6
 *   @0x2ffc94 strb.w r2, [r8, r3]
 *   @0x2ffc98 add r2, sp, #0x88
 *   @0x2ffc9a strh.w r12, [r0, r3, lsl #1]
 *   @0x2ffc9e str r0, [sp, #0x94]
 *   @0x2ffca0 mov r0, r11
 *   @0x2ffca2 ldrsh.w r3, [sp, #0x8a]
 *   @0x2ffca6 str r5, [sp, #0x8c]
 *   @0x2ffca8 str.w r8, [sp, #0x90]
 *   @0x2ffcac bl 0x2ff08c <TT_RunIns+0x2298>
 *   @0x2ffcb0 str r0, [sp, #0x5c]
 *   @0x2ffcb2 cmp r0, #0x0
 *   @0x2ffcb4 bne 0x2ffd56 <TT_RunIns+0x2f62>
 *   @0x2ffcb6 ldr r2, [sp, #0x14]
 *   @0x2ffcb8 ldr r1, [sp, #0x1c]
 *   @0x2ffcba ldr r3, [r2, #0x58]
 *   @0x2ffcbc sxth r6, r1
 *   @0x2ffcbe adds r3, #0x20
 *   @0x2ffcc0 uxth r2, r0
 *   @0x2ffcc2 sxth r1, r2
 *   @0x2ffcc4 cmp r1, r6
 *   @0x2ffcc6 bge 0x2ffcea <TT_RunIns+0x2ef6>
 *   @0x2ffcc8 ldrh r2, [r3, #-28]
 *   @0x2ffccc lsls r2, r2, #0x1e
 *   @0x2ffcce bpl 0x2ffce4 <TT_RunIns+0x2ef0>
 *   @0x2ffcd0 ldrsh.w r2, [r5, r0, lsl #3]
 *   @0x2ffcd4 str r2, [r3, #-24]
 *   @0x2ffcd8 add.w r2, r5, r0, lsl #3
 *   @0x2ffcdc ldrsh.w r2, [r2, #0x4]
 *   @0x2ffce0 str r2, [r3, #-20]
 *   @0x2ffce4 adds r0, #0x1
 *   @0x2ffce6 adds r3, #0x20
 *   @0x2ffce8 b 0x2ffcc0 <TT_RunIns+0x2ecc>
 *   @0x2ffcea ldr.w r12, [r5, r1, lsl #3]
 *   @0x2ffcee add.w r3, r5, r1, lsl #3
 *   @0x2ffcf2 str.w r12, [r4, #0x44]
 *   @0x2ffcf6 ldr r3, [r3, #0x4]
 *   @0x2ffcf8 str r3, [r4, #0x48]
 *   @0x2ffcfa movs r3, #0x8
 *   @0x2ffcfc smlabb r6, r2, r3, r3
 *   @0x2ffd00 adds r1, r5, r6
 *   @0x2ffd02 ldr r6, [r5, r6]
 *   @0x2ffd04 str r6, [r4, #0x4c]
 *   @0x2ffd06 ldr r1, [r1, #0x4]
 *   @0x2ffd08 str r1, [r4, #0x50]
 *   @0x2ffd0a movs r1, #0x10
 *   @0x2ffd0c smlabb r1, r2, r3, r1
 *   @0x2ffd10 add.w lr, r5, r1
 *   @0x2ffd14 ldr r1, [r5, r1]
 *   @0x2ffd16 str.w r1, [r4, #0xb4]
 *   @0x2ffd1a ldr.w r0, [lr, #0x4]
 *   @0x2ffd1e mov.w lr, #0x18
 *   @0x2ffd22 smlabb r2, r2, r3, lr
 *   @0x2ffd26 str.w r0, [r4, #0xb8]
 *   @0x2ffd2a adds r3, r5, r2
 *   @0x2ffd2c ldr r2, [r5, r2]
 *   @0x2ffd2e str.w r2, [r4, #0xbc]
 *   @0x2ffd32 ldr r3, [r3, #0x4]
 *   @0x2ffd34 str.w r3, [r4, #0xc0]
 *   @0x2ffd38 ldr.w r3, [r11, #0x2c0]
 *   @0x2ffd3c lsls r3, r3, #0x1e
 *   @0x2ffd3e itt pl
 *   @0x2ffd40 rsbpl r0, r12, r6
 *   @0x2ffd44 strpl r0, [r4, #0x3c]
 *   @0x2ffd46 ldr.w r3, [r11, #0x2c0]
 *   @0x2ffd4a lsls r5, r3, #0x1b
 *   @0x2ffd4c itt pl
 *   @0x2ffd4e rsbpl r1, r1, r2
 *   @0x2ffd52 strpl.w r1, [r4, #0xb0]
 *   @0x2ffd56 mov r0, r10
 *   @0x2ffd58 ldr r1, [sp, #0x8c]
 *   @0x2ffd5a bl 0x2e7336 <ft_mem_free>
 *   @0x2ffd5e mov r0, r10
 *   @0x2ffd60 ldr r1, [sp, #0x90]
 *   @0x2ffd62 movs r5, #0x0
 *   @0x2ffd64 str r5, [sp, #0x8c]
 *   @0x2ffd66 bl 0x2e7336 <ft_mem_free>
 *   @0x2ffd6a mov r0, r10
 *   @0x2ffd6c ldr r1, [sp, #0x94]
 *   @0x2ffd6e str r5, [sp, #0x90]
 *   @0x2ffd70 bl 0x2e7336 <ft_mem_free>
 *   @0x2ffd74 ldr r3, [sp, #0x5c]
 *   @0x2ffd76 str r5, [sp, #0x94]
 *   @0x2ffd78 cmp r3, #0x0
 *   @0x2ffd7a bne.w 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2ffd7e ldr r3, [r4, #0x10]
 *   @0x2ffd80 lsls r0, r3, #0x1f
 *   @0x2ffd82 bmi 0x2ffdd0 <TT_RunIns+0x2fdc>
 *   @0x2ffd84 mov r1, r7
 *   @0x2ffd86 ldr r0, [r4, #0x44]
 *   @0x2ffd88 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ffd8c mov r1, r7
 *   @0x2ffd8e str r0, [r4, #0x44]
 *   @0x2ffd90 ldr r0, [r4, #0x4c]
 *   @0x2ffd92 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ffd96 mov r1, r7
 *   @0x2ffd98 str r0, [r4, #0x4c]
 *   @0x2ffd9a ldr.w r0, [r4, #0xb4]
 *   @0x2ffd9e bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ffda2 ldr r1, [sp, #0x18]
 *   @0x2ffda4 str.w r0, [r4, #0xb4]
 *   @0x2ffda8 ldr.w r0, [r4, #0xb8]
 *   @0x2ffdac bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ffdb0 mov r1, r7
 *   @0x2ffdb2 str.w r0, [r4, #0xb8]
 *   @0x2ffdb6 ldr.w r0, [r4, #0xbc]
 *   @0x2ffdba bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ffdbe ldr r1, [sp, #0x18]
 *   @0x2ffdc0 str.w r0, [r4, #0xbc]
 *   @0x2ffdc4 ldr.w r0, [r4, #0xc0]
 *   @0x2ffdc8 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2ffdcc str.w r0, [r4, #0xc0]
 *   @0x2ffdd0 ldr r3, [r4, #0x10]
 *   @0x2ffdd2 ands r5, r3, #0x400
 *   @0x2ffdd6 beq 0x2ffde6 <TT_RunIns+0x2ff2>
 *   @0x2ffdd8 ldr r0, [sp, #0x14]
 *   @0x2ffdda bl 0x2e52f8 <FT_GlyphLoader_Add>
 *   @0x2ffdde ldr r3, [r4, #0x8]
 *   @0x2ffde0 ldr r2, [pc, #0x250]
 *   @0x2ffde2 str r2, [r3, #0x48]
 *   @0x2ffde4 b 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2ffde6 ldr r1, [sp, #0x2c]
 *   @0x2ffde8 mov r6, r5
 *   @0x2ffdea ldr r2, [sp, #0x14]
 *   @0x2ffdec ldr r3, [sp, #0x14]
 *   @0x2ffdee ldr r0, [r4, #0x18]
 *   @0x2ffdf0 sxth.w r9, r1
 *   @0x2ffdf4 ldr r2, [r2, #0x54]
 *   @0x2ffdf6 ldr r3, [r3, #0x30]
 *   @0x2ffdf8 ldr r1, [r4, #0x1c]
 *   @0x2ffdfa str r0, [sp, #0x44]
 *   @0x2ffdfc ldr r0, [sp, #0x14]
 *   @0x2ffdfe str r2, [sp, #0x3c]
 *   @0x2ffe00 str r3, [sp, #0x40]
 *   @0x2ffe02 str r1, [sp, #0x48]
 *   @0x2ffe04 bl 0x2e52f8 <FT_GlyphLoader_Add>
 *   @0x2ffe08 str r5, [sp, #0x18]
 *   @0x2ffe0a ldr r5, [sp, #0x20]
 *   @0x2ffe0c str.w r9, [sp, #0x1c]
 *   @0x2ffe10 adds r5, #0x1
 *   @0x2ffe12 str r5, [sp, #0x54]
 *   @0x2ffe14 add r5, sp, #0x74
 *   @0x2ffe16 str r5, [sp, #0x30]
 *   @0x2ffe18 ldr r0, [sp, #0x18]
 *   @0x2ffe1a ldr r5, [sp, #0x3c]
 *   @0x2ffe1c cmp r0, r5
 *   @0x2ffe1e beq.w 0x2fffe4 <TT_RunIns+0x31f0>
 *   @0x2ffe22 ldr r5, [sp, #0x40]
 *   @0x2ffe24 add.w r10, r4, #0x4c
 *   @0x2ffe28 ldr.w r12, [sp, #0x18]
 *   @0x2ffe2c add.w r8, r4, #0xb4
 *   @0x2ffe30 add r7, sp, #0xa0
 *   @0x2ffe32 ldr r2, [sp, #0x54]
 *   @0x2ffe34 add r12, r5
 *   @0x2ffe36 ldr r5, [sp, #0x14]
 *   @0x2ffe38 lsl.w r6, r12, #0x5
 *   @0x2ffe3c add.w r12, r4, #0xbc
 *   @0x2ffe40 ldr r3, [r5, #0x34]
 *   @0x2ffe42 add r5, sp, #0x88
 *   @0x2ffe44 str r5, [sp, #0x20]
 *   @0x2ffe46 add.w r5, r4, #0x44
 *   @0x2ffe4a str r5, [sp, #0x1c]
 *   @0x2ffe4c ldm.w r5, {r0, r1}
 *   @0x2ffe50 ldr r5, [sp, #0x20]
 *   @0x2ffe52 stm.w r5, {r0, r1}
 *   @0x2ffe56 add r5, sp, #0x90
 *   @0x2ffe58 ldm.w r10, {r0, r1}
 *   @0x2ffe5c str r5, [sp, #0x10]
 *   @0x2ffe5e stm.w r5, {r0, r1}
 *   @0x2ffe62 add r5, sp, #0x98
 *   @0x2ffe64 ldm.w r8, {r0, r1}
 *   @0x2ffe68 str r5, [sp, #0x24]
 *   @0x2ffe6a stm.w r5, {r0, r1}
 *   @0x2ffe6e ldm.w r12, {r0, r1}
 *   @0x2ffe72 ldr r5, [r4, #0x3c]
 *   @0x2ffe74 stm.w r7, {r0, r1}
 *   @0x2ffe78 str r5, [sp, #0x4c]
 *   @0x2ffe7a ldr r0, [sp, #0x14]
 *   @0x2ffe7c ldr.w r5, [r4, #0xb0]
 *   @0x2ffe80 ldr r1, [r3, r6]
 *   @0x2ffe82 movs r3, #0x0
 *   @0x2ffe84 str r5, [sp, #0x50]
 *   @0x2ffe86 ldrsh.w r5, [r0, #0x16]
 *   @0x2ffe8a mov r0, r4
 *   @0x2ffe8c str.w r12, [sp, #0xc]
 *   @0x2ffe90 bl 0x2ff67c <TT_RunIns+0x2888>
 *   @0x2ffe94 ldr.w r12, [sp, #0xc]
 *   @0x2ffe98 str r0, [sp, #0x5c]
 *   @0x2ffe9a cmp r0, #0x0
 *   @0x2ffe9c bne.w 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2ffea0 ldr r1, [sp, #0x14]
 *   @0x2ffea2 ldr r3, [r1, #0x34]
 *   @0x2ffea4 add r6, r3
 *   @0x2ffea6 ldrh r2, [r6, #0x4]
 *   @0x2ffea8 lsls r1, r2, #0x16
 *   @0x2ffeaa bmi 0x2ffede <TT_RunIns+0x30ea>
 *   @0x2ffeac ldr r2, [sp, #0x20]
 *   @0x2ffeae ldr r3, [sp, #0x1c]
 *   @0x2ffeb0 ldm.w r2, {r0, r1}
 *   @0x2ffeb4 ldr r2, [sp, #0x10]
 *   @0x2ffeb6 stm.w r3, {r0, r1}
 *   @0x2ffeba ldm.w r2, {r0, r1}
 *   @0x2ffebe ldr r3, [sp, #0x24]
 *   @0x2ffec0 stm.w r10, {r0, r1}
 *   @0x2ffec4 ldm.w r3, {r0, r1}
 *   @0x2ffec8 stm.w r8, {r0, r1}
 *   @0x2ffecc ldm.w r7, {r0, r1}
 *   @0x2ffed0 stm.w r12, {r0, r1}
 *   @0x2ffed4 ldr r0, [sp, #0x4c]
 *   @0x2ffed6 ldr r1, [sp, #0x50]
 *   @0x2ffed8 str r0, [r4, #0x3c]
 *   @0x2ffeda str.w r1, [r4, #0xb0]
 *   @0x2ffede ldr r2, [sp, #0x14]
 *   @0x2ffee0 ldrsh.w r2, [r2, #0x16]
 *   @0x2ffee4 cmp r2, r5
 *   @0x2ffee6 str r2, [sp, #0x1c]
 *   @0x2ffee8 beq 0x2fffdc <TT_RunIns+0x31e8>
 *   @0x2ffeea ldr r7, [r4, #0xc]
 *   @0x2ffeec ldr r2, [r7, #0x18]
 *   @0x2ffeee add.w r2, r2, r5, lsl #3
 *   @0x2ffef2 str r2, [sp, #0x78]
 *   @0x2ffef4 ldrh r2, [r7, #0x16]
 *   @0x2ffef6 subs r2, r2, r5
 *   @0x2ffef8 strh.w r2, [sp, #0x76]
 *   @0x2ffefc ldrb r3, [r6, #0x4]
 *   @0x2ffefe ands r3, r3, #0xc8
 *   @0x2fff02 beq 0x2fff12 <TT_RunIns+0x311e>
 *   @0x2fff04 add r0, sp, #0x74
 *   @0x2fff06 add.w r1, r6, #0x10
 *   @0x2fff0a str r3, [sp, #0xc]
 *   @0x2fff0c bl 0x2e6580 <FT_Outline_Transform>
 *   @0x2fff10 ldr r3, [sp, #0xc]
 *   @0x2fff12 ldrh r2, [r6, #0x4]
 *   @0x2fff14 ldr.w r10, [r6, #0x8]
 *   @0x2fff18 tst.w r2, #0x2
 *   @0x2fff1c ldr.w r8, [r6, #0xc]
 *   @0x2fff20 bne 0x2fff4e <TT_RunIns+0x315a>
 *   @0x2fff22 add r10, r9
 *   @0x2fff24 ldrh r2, [r7, #0x16]
 *   @0x2fff26 cmp r10, r5
 *   @0x2fff28 bhs 0x2fffd2 <TT_RunIns+0x31de>
 *   @0x2fff2a add r8, r5
 *   @0x2fff2c sxth r2, r2
 *   @0x2fff2e cmp r8, r2
 *   @0x2fff30 bhs 0x2fffd2 <TT_RunIns+0x31de>
 *   @0x2fff32 ldr r0, [r7, #0x18]
 *   @0x2fff34 add.w r1, r0, r10, lsl #3
 *   @0x2fff38 add.w r2, r0, r8, lsl #3
 *   @0x2fff3c ldr.w r5, [r0, r10, lsl #3]
 *   @0x2fff40 ldr r1, [r1, #0x4]
 *   @0x2fff42 ldr.w r0, [r0, r8, lsl #3]
 *   @0x2fff46 ldr r7, [r2, #0x4]
 *   @0x2fff48 subs r5, r5, r0
 *   @0x2fff4a subs r7, r1, r7
 *   @0x2fff4c b 0x2fffc0 <TT_RunIns+0x31cc>
 *   @0x2fff4e mov r5, r10
 *   @0x2fff50 mov r7, r8
 *   @0x2fff52 cmp.w r10, #0x0
 *   @0x2fff56 bne 0x2fff5e <TT_RunIns+0x316a>
 *   @0x2fff58 cmp.w r8, #0x0
 *   @0x2fff5c beq 0x2fffce <TT_RunIns+0x31da>
 *   @0x2fff5e cbz r3, 0x2fff8c <TT_RunIns+0x3198>
 *   @0x2fff60 lsls r2, r2, #0x14
 *   @0x2fff62 bpl 0x2fff8c <TT_RunIns+0x3198>
 *   @0x2fff64 ldr r1, [r6, #0x14]
 *   @0x2fff66 ldr r0, [r6, #0x10]
 *   @0x2fff68 bl 0x2e707a <FT_Hypot>
 *   @0x2fff6c ldr r1, [r6, #0x18]
 *   @0x2fff6e mov r5, r0
 *   @0x2fff70 ldr r0, [r6, #0x1c]
 *   @0x2fff72 bl 0x2e707a <FT_Hypot>
 *   @0x2fff76 mov r1, r5
 *   @0x2fff78 mov r7, r0
 *   @0x2fff7a mov r0, r10
 *   @0x2fff7c bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fff80 mov r1, r7
 *   @0x2fff82 mov r5, r0
 *   @0x2fff84 mov r0, r8
 *   @0x2fff86 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fff8a mov r7, r0
 *   @0x2fff8c ldr r2, [r4, #0x10]
 *   @0x2fff8e lsls r3, r2, #0x1f
 *   @0x2fff90 bmi 0x2fffc0 <TT_RunIns+0x31cc>
 *   @0x2fff92 ldr r2, [r4, #0x4]
 *   @0x2fff94 mov r0, r5
 *   @0x2fff96 ldr r2, [r2, #0x2c]
 *   @0x2fff98 ldr r1, [r2, #0x4]
 *   @0x2fff9a ldr.w r8, [r2, #0x8]
 *   @0x2fff9e bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fffa2 mov r1, r8
 *   @0x2fffa4 mov r5, r0
 *   @0x2fffa6 mov r0, r7
 *   @0x2fffa8 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fffac ldrh r2, [r6, #0x4]
 *   @0x2fffae mov r7, r0
 *   @0x2fffb0 lsls r0, r2, #0x1d
 *   @0x2fffb2 bpl 0x2fffc0 <TT_RunIns+0x31cc>
 *   @0x2fffb4 adds r5, #0x20
 *   @0x2fffb6 adds r7, #0x20
 *   @0x2fffb8 bic r5, r5, #0x3f
 *   @0x2fffbc bic r7, r7, #0x3f
 *   @0x2fffc0 cbnz r5, 0x2fffc4 <TT_RunIns+0x31d0>
 *   @0x2fffc2 cbz r7, 0x2fffce <TT_RunIns+0x31da>
 *   @0x2fffc4 add r0, sp, #0x74
 *   @0x2fffc6 mov r1, r5
 *   @0x2fffc8 mov r2, r7
 *   @0x2fffca bl 0x2e6424 <FT_Outline_Translate>
 *   @0x2fffce movs r2, #0x0
 *   @0x2fffd0 b 0x2fffd4 <TT_RunIns+0x31e0>
 *   @0x2fffd2 movs r2, #0x15
 *   @0x2fffd4 str r2, [sp, #0x5c]
 *   @0x2fffd6 cmp r2, #0x0
 *   @0x2fffd8 bne.w 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2fffdc ldr r5, [sp, #0x18]
 *   @0x2fffde adds r5, #0x1
 *   @0x2fffe0 str r5, [sp, #0x18]
 *   @0x2fffe2 b 0x2ffe18 <TT_RunIns+0x3024>
 *   @0x2fffe4 ldr r5, [sp, #0x44]
 *   @0x2fffe6 ldr r2, [r4, #0x10]
 *   @0x2fffe8 str r5, [r4, #0x18]
 *   @0x2fffea ands r2, r2, #0x2
 *   @0x2fffee ldr r5, [sp, #0x48]
 *   @0x2ffff0 str r5, [r4, #0x1c]
 *   @0x2ffff2 ldr r5, [sp, #0x38]
 *   @0x2ffff4 str.w r5, [r4, #0xa4]
 *   @0x2ffff8 bne.w 0x3001ec <TT_RunIns+0x33f8>
 *   @0x2ffffc ldrh r3, [r6, #0x4]
 *   @0x2ffffe lsls r1, r3, #0x17
 *   @0x300000 bpl.w 0x3001ec <TT_RunIns+0x33f8>
/* ═══════════════════════════════════════════════════════════════════════
 * §10  anon_thumb_309b08   0x309b08..0x30a6bc   2,996 B / 1143 条   in-degree 2
 * autofit afshaper.c 带（2,996 B / 2 个 bl 入口 / 1,143 条）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 2 条 Thumb `bl` 指向本段起始：anon_309b08 自递归×2（本段内 0x309e50 / 0x30a3e4）；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 27 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} / sub sp, #0x1c / mov r5, r0（帧：sub sp, 0x1c）；窗口内出口 5 个
 * 结构：入口可达 596 B / 213 条（19%）；段内 bl 入口 1 个：0x30a3d4(48 B/23 条)
 *      可打印岛：无 ≥16 B 的
 *      未达字节：696 B（各入口可达集的补集；多为只经指针/表进入的邻接函数与池字，本卡不判其身份）
 * 前一条符号 af_shaper_get_coverage(0x309b05，4 B) 是 `movs r0,#0 ; bx lr` 的空实现（本 build 关掉了
 *      shaper），本段紧跟其后；后一条符号是 af_shaper_buf_create(0x30a6c0)。入口 596 B / 213 条，
 *      反向只有自己 bl 2 次；正向 27 处 bl 打向具名 Thumb：ft_mem_alloc、FT_Select_Charmap、
 *      FT_Get_Char_Index、FT_Get_Next_Char、FT_Outline_Get_CBox… 段内另 1 个 bl 入口 0x30a3d4(48 B)。
 *
 * 锚点：1143 条（= asm/index-anonT_309b08.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x309b08 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x309b0c sub sp, #0x1c
 *   @0x309b0e mov r5, r0
 *   @0x309b10 mov r6, r2
 *   @0x309b12 str r1, [sp, #0xc]
 *   @0x309b14 add r2, sp, #0x10
 *   @0x309b16 ldr r1, [r0, #0x10]
 *   @0x309b18 ldr r0, [r0, #0x64]
 *   @0x309b1a adds r1, #0xbe
 *   @0x309b1c lsls r1, r1, #0x1
 *   @0x309b1e bl 0x2e7126 <ft_mem_alloc>
 *   @0x309b22 ldr r3, [sp, #0x10]
 *   @0x309b24 mov r7, r0
 *   @0x309b26 cmp r3, #0x0
 *   @0x309b28 bne.w 0x309d50 <af_shaper_get_coverage+0x24c>
 *   @0x309b2c str r5, [r0]
 *   @0x309b2e add.w r4, r0, #0x17c
 *   @0x309b32 ldr r1, [r5, #0x10]
 *   @0x309b34 str r4, [r0, #0x8]
 *   @0x309b36 str.w r6, [r0, #0x178]
 *   @0x309b3a str r1, [r0, #0x4]
 *   @0x309b3c movw r1, #0x3fff
 *   @0x309b40 strh.w r3, [r0, #0x160]
 *   @0x309b44 str.w r3, [r0, #0x16c]
 *   @0x309b48 str.w r3, [r0, #0x170]
 *   @0x309b4c str.w r3, [r0, #0x164]
 *   @0x309b50 str.w r3, [r0, #0x168]
 *   @0x309b54 str.w r3, [r0, #0x174]
 *   @0x309b58 ldr r0, [r5, #0x5c]
 *   @0x309b5a str r0, [sp, #0x8]
 *   @0x309b5c ldr r2, [r7, #0x4]
 *   @0x309b5e cmp r3, r2
 *   @0x309b60 bhs 0x309b6e <af_shaper_get_coverage+0x6a>
 *   @0x309b62 add.w r2, r7, r3, lsl #1
 *   @0x309b66 adds r3, #0x1
 *   @0x309b68 strh.w r1, [r2, #0x17c]
 *   @0x309b6c b 0x309b5c <af_shaper_get_coverage+0x58>
 *   @0x309b6e mov r0, r5
 *   @0x309b70 ldr r1, [pc, #0x1e8]
 *   @0x309b72 bl 0x2e58f4 <FT_Select_Charmap>
 *   @0x309b76 cbnz r0, 0x309bd8 <af_shaper_get_coverage+0xd4>
 *   @0x309b78 mov.w r11, #0xffffffff
 *   @0x309b7c mov r6, r0
 *   @0x309b7e add.w r8, sp, #0x14
 *   @0x309b82 b 0x309b98 <af_shaper_get_coverage+0x94>
 *   @0x309b84 ldr r3, [pc, #0x1d8]
 *   @0x309b86 ldr r2, [r1, #0x8]
 *   @0x309b88 add r3, pc
 *   @0x309b8a ldr r3, [r3]
 *   @0x309b8c ldr.w r3, [r3, r2, lsl #2]
 *   @0x309b90 str r3, [sp, #0x4]
 *   @0x309b92 ldr r3, [r3, #0x4]
 *   @0x309b94 cbnz r3, 0x309bec <af_shaper_get_coverage+0xe8>
 *   @0x309b96 adds r6, #0x1
 *   @0x309b98 ldr r3, [pc, #0x1c8]
 *   @0x309b9a add r3, pc
 *   @0x309b9c ldr r3, [r3]
 *   @0x309b9e ldr.w r1, [r3, r6, lsl #2]
 *   @0x309ba2 mov r9, r3
 *   @0x309ba4 cmp r1, #0x0
 *   @0x309ba6 bne 0x309b84 <af_shaper_get_coverage+0x80>
 *   @0x309ba8 subs r6, r3, #0x4
 *   @0x309baa ldr r1, [r6, #4]!
 *   @0x309bae cmp r1, #0x0
 *   @0x309bb0 bne.w 0x309ce6 <af_shaper_get_coverage+0x1e2>
 *   @0x309bb4 mov r0, r7
 *   @0x309bb6 ldr.w r1, [r9, r11, lsl #2]
 *   @0x309bba mov r2, r4
 *   @0x309bbc movs r3, #0x1
 *   @0x309bbe bl 0x309b04 <af_shaper_get_coverage>
 *   @0x309bc2 movs r6, #0x30
 *   @0x309bc4 mov r0, r5
 *   @0x309bc6 mov r1, r6
 *   @0x309bc8 bl 0x2e5960 <FT_Get_Char_Index>
 *   @0x309bcc cmp r0, #0x0
 *   @0x309bce bne.w 0x309cfa <af_shaper_get_coverage+0x1f6>
 *   @0x309bd2 adds r6, #0x1
 *   @0x309bd4 cmp r6, #0x3a
 *   @0x309bd6 bne 0x309bc4 <af_shaper_get_coverage+0xc0>
 *   @0x309bd8 ldr.w r2, [r7, #0x178]
 *   @0x309bdc movw r3, #0x3fff
 *   @0x309be0 mov r0, r3
 *   @0x309be2 ldr r2, [r2, #0xc]
 *   @0x309be4 cmp r2, r3
 *   @0x309be6 bne.w 0x309d14 <af_shaper_get_coverage+0x210>
 *   @0x309bea b 0x309d1c <af_shaper_get_coverage+0x218>
 *   @0x309bec ldr r0, [r1, #0x10]
 *   @0x309bee cmp r0, #0xa
 *   @0x309bf0 bne 0x309cda <af_shaper_get_coverage+0x1d6>
 *   @0x309bf2 ldr.w r1, [r7, #0x178]
 *   @0x309bf6 add.w r9, r3, #0x8
 *   @0x309bfa movw r10, #0x3fff
 *   @0x309bfe ldr r1, [r1, #0x10]
 *   @0x309c00 cmp r2, r1
 *   @0x309c02 it eq
 *   @0x309c04 moveq r11, r6
 *   @0x309c06 ldr r2, [r9, #-8]
 *   @0x309c0a cbz r2, 0x309c68 <af_shaper_get_coverage+0x164>
 *   @0x309c0c mov r1, r2
 *   @0x309c0e mov r0, r5
 *   @0x309c10 str r2, [sp]
 *   @0x309c12 bl 0x2e5960 <FT_Get_Char_Index>
 *   @0x309c16 ldr r2, [sp]
 *   @0x309c18 str r0, [sp, #0x14]
 *   @0x309c1a cbz r0, 0x309c32 <af_shaper_get_coverage+0x12e>
 *   @0x309c1c ldr r1, [r7, #0x4]
 *   @0x309c1e cmp r0, r1
 *   @0x309c20 bhs 0x309c32 <af_shaper_get_coverage+0x12e>
 *   @0x309c22 ldrh.w r1, [r4, r0, lsl #1]
 *   @0x309c26 ubfx r1, r1, #0x0, #0xe
 *   @0x309c2a cmp r1, r10
 *   @0x309c2c it eq
 *   @0x309c2e strheq.w r6, [r4, r0, lsl #1]
 *   @0x309c32 mov r1, r2
 *   @0x309c34 mov r0, r5
 *   @0x309c36 mov r2, r8
 *   @0x309c38 bl 0x2e597e <FT_Get_Next_Char>
 *   @0x309c3c ldr r1, [sp, #0x14]
 *   @0x309c3e mov r2, r0
 *   @0x309c40 cbz r1, 0x309c62 <af_shaper_get_coverage+0x15e>
 *   @0x309c42 ldr r0, [r9, #-4]
 *   @0x309c46 cmp r2, r0
 *   @0x309c48 bhi 0x309c62 <af_shaper_get_coverage+0x15e>
 *   @0x309c4a ldr r0, [r7, #0x4]
 *   @0x309c4c cmp r1, r0
 *   @0x309c4e bhs 0x309c32 <af_shaper_get_coverage+0x12e>
 *   @0x309c50 ldrh.w r0, [r4, r1, lsl #1]
 *   @0x309c54 ubfx r0, r0, #0x0, #0xe
 *   @0x309c58 cmp r0, r10
 *   @0x309c5a bne 0x309c32 <af_shaper_get_coverage+0x12e>
 *   @0x309c5c strh.w r6, [r4, r1, lsl #1]
 *   @0x309c60 b 0x309c32 <af_shaper_get_coverage+0x12e>
 *   @0x309c62 add.w r9, r9, #0x8
 *   @0x309c66 b 0x309c06 <af_shaper_get_coverage+0x102>
 *   @0x309c68 ldr r2, [sp, #0x4]
 *   @0x309c6a ldr r3, [r2, #0x8]
 *   @0x309c6c add.w r10, r3, #0x8
 *   @0x309c70 ldr r9, [r10, #-8]
 *   @0x309c74 cmp.w r9, #0x0
 *   @0x309c78 beq 0x309b96 <af_shaper_get_coverage+0x92>
 *   @0x309c7a mov r0, r5
 *   @0x309c7c mov r1, r9
 *   @0x309c7e bl 0x2e5960 <FT_Get_Char_Index>
 *   @0x309c82 str r0, [sp, #0x14]
 *   @0x309c84 cbz r0, 0x309ca0 <af_shaper_get_coverage+0x19c>
 *   @0x309c86 ldr r3, [r7, #0x4]
 *   @0x309c88 cmp r0, r3
 *   @0x309c8a bhs 0x309ca0 <af_shaper_get_coverage+0x19c>
 *   @0x309c8c ldrh.w r3, [r4, r0, lsl #1]
 *   @0x309c90 ubfx r2, r3, #0x0, #0xe
 *   @0x309c94 cmp r2, r6
 *   @0x309c96 itt eq
 *   @0x309c98 orreq r3, r3, #0x4000
 *   @0x309c9c strheq.w r3, [r4, r0, lsl #1]
 *   @0x309ca0 mov r1, r9
 *   @0x309ca2 mov r0, r5
 *   @0x309ca4 mov r2, r8
 *   @0x309ca6 bl 0x2e597e <FT_Get_Next_Char>
 *   @0x309caa ldr r3, [sp, #0x14]
 *   @0x309cac mov r9, r0
 *   @0x309cae cbz r3, 0x309cd4 <af_shaper_get_coverage+0x1d0>
 *   @0x309cb0 ldr r2, [r10, #-4]
 *   @0x309cb4 cmp r0, r2
 *   @0x309cb6 bhi 0x309cd4 <af_shaper_get_coverage+0x1d0>
 *   @0x309cb8 ldr r2, [r7, #0x4]
 *   @0x309cba cmp r3, r2
 *   @0x309cbc bhs 0x309ca0 <af_shaper_get_coverage+0x19c>
 *   @0x309cbe ldrh.w r2, [r4, r3, lsl #1]
 *   @0x309cc2 ubfx r1, r2, #0x0, #0xe
 *   @0x309cc6 cmp r1, r6
 *   @0x309cc8 bne 0x309ca0 <af_shaper_get_coverage+0x19c>
 *   @0x309cca orr r2, r2, #0x4000
 *   @0x309cce strh.w r2, [r4, r3, lsl #1]
 *   @0x309cd2 b 0x309ca0 <af_shaper_get_coverage+0x19c>
 *   @0x309cd4 add.w r10, r10, #0x8
 *   @0x309cd8 b 0x309c70 <af_shaper_get_coverage+0x16c>
 *   @0x309cda mov r0, r7
 *   @0x309cdc mov r2, r4
 *   @0x309cde movs r3, #0x0
 *   @0x309ce0 bl 0x309b04 <af_shaper_get_coverage>
 *   @0x309ce4 b 0x309b96 <af_shaper_get_coverage+0x92>
 *   @0x309ce6 ldr r3, [r1, #0x10]
 *   @0x309ce8 cmp r3, #0xa
 *   @0x309cea bne.w 0x309baa <af_shaper_get_coverage+0xa6>
 *   @0x309cee mov r0, r7
 *   @0x309cf0 mov r2, r4
 *   @0x309cf2 movs r3, #0x0
 *   @0x309cf4 bl 0x309b04 <af_shaper_get_coverage>
 *   @0x309cf8 b 0x309baa <af_shaper_get_coverage+0xa6>
 *   @0x309cfa ldr r3, [r7, #0x4]
 *   @0x309cfc cmp r0, r3
 *   @0x309cfe bhs.w 0x309bd2 <af_shaper_get_coverage+0xce>
 *   @0x309d02 ldrh.w r3, [r4, r0, lsl #1]
 *   @0x309d06 mvn.w r3, r3, lsl #17
 *   @0x309d0a mvn.w r3, r3, lsr #17
 *   @0x309d0e strh.w r3, [r4, r0, lsl #1]
 *   @0x309d12 b 0x309bd2 <af_shaper_get_coverage+0xce>
 *   @0x309d14 movs r3, #0x0
 *   @0x309d16 ldr r2, [r7, #0x4]
 *   @0x309d18 cmp r3, r2
 *   @0x309d1a blt 0x309d2c <af_shaper_get_coverage+0x228>
 *   @0x309d1c mov r0, r5
 *   @0x309d1e ldr r1, [sp, #0x8]
 *   @0x309d20 bl 0x2e5cfc <FT_Set_Charmap>
 *   @0x309d24 movs r3, #0x0
 *   @0x309d26 str r3, [sp, #0x10]
 *   @0x309d28 str r3, [r7, #0xc]
 *   @0x309d2a b 0x309d50 <af_shaper_get_coverage+0x24c>
 *   @0x309d2c ldrh r2, [r4], #2
 *   @0x309d30 ubfx r1, r2, #0x0, #0xe
 *   @0x309d34 cmp r1, r0
 *   @0x309d36 bne 0x309d4c <af_shaper_get_coverage+0x248>
 *   @0x309d38 and r2, r2, #0xc000
 *   @0x309d3c strh r2, [r4, #-2]
 *   @0x309d40 ldr.w r1, [r7, #0x178]
 *   @0x309d44 ldr r1, [r1, #0xc]
 *   @0x309d46 orrs r2, r1
 *   @0x309d48 strh r2, [r4, #-2]
 *   @0x309d4c adds r3, #0x1
 *   @0x309d4e b 0x309d16 <af_shaper_get_coverage+0x212>
 *   @0x309d50 ldr r3, [sp, #0xc]
 *   @0x309d52 ldr r0, [sp, #0x10]
 *   @0x309d54 str r7, [r3]
 *   @0x309d56 add sp, #0x1c
 *   @0x309d58 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x309d5c ldr r3, [r4, #0x14]
 *   @0x309d5e strb r6, [r5, #0x15]
 *   @0x309d60 strh r4, [r3, #0x2]
 *   @0x309d62 movs r6, r1
 *   @0x309d64 strh r6, [r1, #0x2]
 *   @0x309d66 movs r6, r1
 *   @0x309d68 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x309d6c sub.w sp, sp, #0x1aa0
 *   @0x309d70 sub sp, #0xc
 *   @0x309d72 ldr.w r7, [pc, #0x64c]
 *   @0x309d76 add.w r11, sp, #0xc0
 *   @0x309d7a add r5, sp, #0xc8
 *   @0x309d7c str r3, [sp, #0x2c]
 *   @0x309d7e mov r4, r1
 *   @0x309d80 ldr r3, [r0, #0x4]
 *   @0x309d82 movs r1, #0x0
 *   @0x309d84 str r0, [sp, #0x18]
 *   @0x309d86 movw r2, #0xac8
 *   @0x309d8a add.w r9, sp, #0x88
 *   @0x309d8e mov r0, r11
 *   @0x309d90 ldr r6, [r3]
 *   @0x309d92 add r7, pc
 *   @0x309d94 str r7, [sp, #0x10]
 *   @0x309d96 blx 0xb65b0 <memset@plt>
 *   @0x309d9a movs r1, #0x0
 *   @0x309d9c movs r2, #0x3c
 *   @0x309d9e str r6, [r5, #-8]
 *   @0x309da2 sub.w r5, r9, #0x4
 *   @0x309da6 mov r0, r5
 *   @0x309da8 blx 0xb65b0 <memset@plt>
 *   @0x309dac ldr r4, [r4, #0x4]
 *   @0x309dae str.w r11, [r5, #0x8]
 *   @0x309db2 movs r1, #0x0
 *   @0x309db4 movs r2, #0x1c
 *   @0x309db6 ldr r6, [r4, #0x54]
 *   @0x309db8 ldr.w r12, [r4, #0x58]
 *   @0x309dbc str r4, [sp, #0x4]
 *   @0x309dbe add r4, sp, #0x68
 *   @0x309dc0 ldr.w r7, [r6, #0x9c]
 *   @0x309dc4 mov r0, r4
 *   @0x309dc6 ldr.w r8, [r12, #0x28]
 *   @0x309dca str r7, [sp, #0x28]
 *   @0x309dcc ldr r7, [r7]
 *   @0x309dce str.w r12, [sp, #0x8]
 *   @0x309dd2 str r7, [sp, #0x3c]
 *   @0x309dd4 blx 0xb65b0 <memset@plt>
 *   @0x309dd8 add.w r1, sp, #0x1ac0
 *   @0x309ddc ldr.w r3, [r8, #0xc]
 *   @0x309de0 adds r1, #0x10
 *   @0x309de2 ldr.w r12, [sp, #0x8]
 *   @0x309de6 ldr r1, [r1]
 *   @0x309de8 asr.w r10, r1, #0x10
 *   @0x309dec cbz r3, 0x309dfa <af_shaper_get_coverage+0x2f6>
 *   @0x309dee ldr.w r3, [r8, #0x4]
 *   @0x309df2 and r2, r10, #0xf
 *   @0x309df6 cmp r3, r2
 *   @0x309df8 beq 0x309e1a <af_shaper_get_coverage+0x316>
 *   @0x309dfa add.w r12, r12, #0xc
 *   @0x309dfe and r3, r10, #0xf
 *   @0x309e02 str.w r3, [r8, #0x4]
 *   @0x309e06 add.w lr, r8, #0x8
 *   @0x309e0a ldm.w r12!, {r0, r1, r2, r3}
 *   @0x309e0e stm.w lr!, {r0, r1, r2, r3}
 *   @0x309e12 ldm.w r12, {r0, r1, r2}
 *   @0x309e16 stm.w lr, {r0, r1, r2}
 *   @0x309e1a ldr.w r3, [r8, #0xc]
 *   @0x309e1e ldr r7, [sp, #0x4]
 *   @0x309e20 ldr.w r2, [r8, #0x10]
 *   @0x309e24 str r3, [r4, #0x4]
 *   @0x309e26 movs r3, #0x0
 *   @0x309e28 str r3, [r4, #0xc]
 *   @0x309e2a str r3, [r4, #0x10]
 *   @0x309e2c str r3, [r4, #0x18]
 *   @0x309e2e ldr r3, [r7, #0x74]
 *   @0x309e30 str r7, [r4]
 *   @0x309e32 str r2, [r4, #0x8]
 *   @0x309e34 and r2, r10, #0xf
 *   @0x309e38 str r7, [r9, #-4]
 *   @0x309e3c add r7, sp, #0xc8
 *   @0x309e3e str r2, [r4, #0x14]
 *   @0x309e40 str r7, [sp, #0x34]
 *   @0x309e42 add r7, sp, #0x88
 *   @0x309e44 str r3, [r5, #0x4]
 *   @0x309e46 str r7, [sp, #0x30]
 *   @0x309e48 cbnz r3, 0x309e66 <af_shaper_get_coverage+0x362>
 *   @0x309e4a ldr r0, [sp, #0x4]
 *   @0x309e4c mov r1, r9
 *   @0x309e4e ldr r2, [sp, #0x18]
 *   @0x309e50 bl 0x309b08 <af_shaper_get_coverage+0x4>
 *   @0x309e54 cmp r0, #0x0
 *   @0x309e56 bne 0x309ecc <af_shaper_get_coverage+0x3c8>
 *   @0x309e58 ldr r3, [r5, #0x4]
 *   @0x309e5a ldr r7, [sp, #0x4]
 *   @0x309e5c str r3, [r7, #0x74]
 *   @0x309e5e ldr.w r3, [pc, #0x564]
 *   @0x309e62 add r3, pc
 *   @0x309e64 str r3, [r7, #0x78]
 *   @0x309e66 ldr.w r8, [r5, #0x4]
 *   @0x309e6a sub.w r7, r4, #0x10
 *   @0x309e6e movs r3, #0x0
 *   @0x309e70 str r7, [sp, #0xc]
 *   @0x309e72 str r3, [r4, #-16]
 *   @0x309e76 ldr r7, [sp, #0x2c]
 *   @0x309e78 ldr.w r2, [r8, #0x4]
 *   @0x309e7c cmp r7, r2
 *   @0x309e7e blo 0x309ed0 <af_shaper_get_coverage+0x3cc>
 *   @0x309e80 mov r10, r3
 *   @0x309e82 movs r2, #0x6
 *   @0x309e84 str r2, [r4, #-16]
 *   @0x309e88 ldr r8, [r4, #-16]
 *   @0x309e8c cmp.w r8, #0x0
 *   @0x309e90 bne.w 0x30a3a0 <af_shaper_get_coverage+0x89c>
 *   @0x309e94 ldr.w r3, [pc, #0x530]
 *   @0x309e98 ldr r7, [sp, #0x10]
 *   @0x309e9a ldr r2, [r7, r3]
 *   @0x309e9c ldr.w r3, [r10]
 *   @0x309ea0 str r2, [sp, #0x44]
 *   @0x309ea2 ldr r3, [r3, #0x4]
 *   @0x309ea4 str.w r10, [r5, #0xc]
 *   @0x309ea8 ldr.w r3, [r2, r3, lsl #2]
 *   @0x309eac str r3, [sp, #0x14]
 *   @0x309eae ldr r3, [r3, #0xc]
 *   @0x309eb0 cmp r3, #0x0
 *   @0x309eb2 beq 0x309f5e <af_shaper_get_coverage+0x45a>
 *   @0x309eb4 mov r0, r10
 *   @0x309eb6 mov r1, r4
 *   @0x309eb8 blx r3
 *   @0x309eba ldr r7, [sp, #0x14]
 *   @0x309ebc ldr r3, [r7, #0x18]
 *   @0x309ebe cmp r3, #0x0
 *   @0x309ec0 beq 0x309f76 <af_shaper_get_coverage+0x472>
 *   @0x309ec2 mov r0, r11
 *   @0x309ec4 mov r1, r10
 *   @0x309ec6 blx r3
 *   @0x309ec8 cmp r0, #0x0
 *   @0x309eca beq 0x309f76 <af_shaper_get_coverage+0x472>
 *   @0x309ecc mov r8, r0
 *   @0x309ece b 0x30a3a0 <af_shaper_get_coverage+0x89c>
 *   @0x309ed0 ldr.w r3, [r8, #0x8]
 *   @0x309ed4 ldr r7, [sp, #0x2c]
 *   @0x309ed6 ldrh.w r10, [r3, r7, lsl #1]
 *   @0x309eda ldr r7, [sp, #0x10]
 *   @0x309edc ldr.w r3, [pc, #0x4ec]
 *   @0x309ee0 ubfx r10, r10, #0x0, #0xe
 *   @0x309ee4 uxth.w r10, r10
 *   @0x309ee8 ldr r3, [r7, r3]
 *   @0x309eea ldr.w r12, [r3, r10, lsl #2]
 *   @0x309eee ldr.w r3, [pc, #0x4d8]
 *   @0x309ef2 ldr.w r2, [r12, #0x4]
 *   @0x309ef6 ldr r3, [r7, r3]
 *   @0x309ef8 ldr.w r7, [r3, r2, lsl #2]
 *   @0x309efc add.w r3, r8, r10, lsl #2
 *   @0x309f00 str r3, [sp, #0x20]
 *   @0x309f02 ldr.w r10, [r3, #0x10]
 *   @0x309f06 cmp.w r10, #0x0
 *   @0x309f0a bne 0x309e88 <af_shaper_get_coverage+0x384>
 *   @0x309f0c ldr.w r3, [r8]
 *   @0x309f10 add r2, sp, #0x58
 *   @0x309f12 ldr r1, [r7, #0x4]
 *   @0x309f14 ldr r3, [r3, #0x64]
 *   @0x309f16 str.w r12, [sp, #0x8]
 *   @0x309f1a mov r0, r3
 *   @0x309f1c str r3, [sp, #0x1c]
 *   @0x309f1e bl 0x2e7126 <ft_mem_alloc>
 *   @0x309f22 ldr r3, [sp, #0x58]
 *   @0x309f24 ldr.w r12, [sp, #0x8]
 *   @0x309f28 mov r9, r0
 *   @0x309f2a cbnz r3, 0x309f5a <af_shaper_get_coverage+0x456>
 *   @0x309f2c str.w r12, [r0]
 *   @0x309f30 str.w r8, [r0, #0x24]
 *   @0x309f34 ldr r3, [r7, #0x8]
 *   @0x309f36 cbz r3, 0x309f54 <af_shaper_get_coverage+0x450>
 *   @0x309f38 ldr.w r1, [r8]
 *   @0x309f3c blx r3
 *   @0x309f3e str r0, [sp, #0x58]
 *   @0x309f40 cbz r0, 0x309f54 <af_shaper_get_coverage+0x450>
 *   @0x309f42 ldr r3, [r7, #0x10]
 *   @0x309f44 cbz r3, 0x309f4a <af_shaper_get_coverage+0x446>
 *   @0x309f46 mov r0, r9
 *   @0x309f48 blx r3
 *   @0x309f4a ldr r0, [sp, #0x1c]
 *   @0x309f4c mov r1, r9
 *   @0x309f4e bl 0x2e7336 <ft_mem_free>
 *   @0x309f52 b 0x309e88 <af_shaper_get_coverage+0x384>
 *   @0x309f54 ldr r7, [sp, #0x20]
 *   @0x309f56 str.w r9, [r7, #0x10]
 *   @0x309f5a mov r10, r9
 *   @0x309f5c b 0x309e88 <af_shaper_get_coverage+0x384>
 *   @0x309f5e mov r12, r4
 *   @0x309f60 add.w lr, r10, #0x4
 *   @0x309f64 ldm.w r12!, {r0, r1, r2, r3}
 *   @0x309f68 stm.w lr!, {r0, r1, r2, r3}
 *   @0x309f6c ldm.w r12, {r0, r1, r2}
 *   @0x309f70 stm.w lr, {r0, r1, r2}
 *   @0x309f74 b 0x309eba <af_shaper_get_coverage+0x3b6>
 *   @0x309f76 add.w r1, sp, #0x1ac0
 *   @0x309f7a ldr r0, [sp, #0x4]
 *   @0x309f7c adds r1, #0x10
 *   @0x309f7e ldr r1, [r1]
 *   @0x309f80 bic r2, r1, #0x4
 *   @0x309f84 ldr r1, [sp, #0x2c]
 *   @0x309f86 orr r2, r2, #0x2800
 *   @0x309f8a orr r2, r2, #0x1
 *   @0x309f8e bl 0x2e7564 <FT_Load_Glyph>
 *   @0x309f92 str r0, [sp, #0x10]
 *   @0x309f94 cmp r0, #0x0
 *   @0x309f96 bne.w 0x30a39c <af_shaper_get_coverage+0x898>
 *   @0x309f9a ldr r3, [r4, #0x14]
 *   @0x309f9c add r7, sp, #0x50
 *   @0x309f9e str r7, [sp, #0x38]
 *   @0x309fa0 cmp r3, #0x1
 *   @0x309fa2 bne.w 0x30a11a <af_shaper_get_coverage+0x616>
 *   @0x309fa6 ldr r7, [sp, #0x4]
 *   @0x309fa8 ldr.w r3, [r7, #0x80]
 *   @0x309fac ldrb.w r3, [r3, #0x38]
 *   @0x309fb0 cbz r3, 0x309fc2 <af_shaper_get_coverage+0x4be>
 *   @0x309fb2 lsls r0, r3, #0x18
 *   @0x309fb4 bpl.w 0x30a11a <af_shaper_get_coverage+0x616>
 *   @0x309fb8 ldr r7, [sp, #0x18]
 *   @0x309fba ldrb r3, [r7, #0x15]
 *   @0x309fbc cmp r3, #0x0
 *   @0x309fbe bne.w 0x30a11a <af_shaper_get_coverage+0x616>
 *   @0x309fc2 ldr r7, [sp, #0x4]
 *   @0x309fc4 mov.w r0, #0x3e80000
 *   @0x309fc8 ldr.w r8, [r5, #0x4]
 *   @0x309fcc ldr r7, [r7, #0x54]
 *   @0x309fce str r7, [sp, #0x40]
 *   @0x309fd0 ldr r7, [sp, #0x4]
 *   @0x309fd2 ldr r3, [r7, #0x58]
 *   @0x309fd4 sub.w r7, r4, #0x1c
 *   @0x309fd8 str r7, [sp, #0x24]
 *   @0x309fda ldr.w r9, [r3, #0x28]
 *   @0x309fde movs r3, #0x0
 *   @0x309fe0 str r3, [r4, #-24]
 *   @0x309fe4 ldrh.w r7, [r8, #0x160]
 *   @0x309fe8 str r3, [r4, #-28]
 *   @0x309fec ldrh.w r12, [r9, #0x8]
 *   @0x309ff0 str r7, [sp, #0x1c]
 *   @0x309ff2 ldr r7, [sp, #0x4]
 *   @0x309ff4 ldrh.w r3, [r7, #0x44]
 *   @0x309ff8 str.w r12, [sp, #0x8]
 *   @0x309ffc lsls r3, r3, #0x10
 *   @0x309ffe str r3, [sp, #0x18]
 *   @0x30a000 mov r1, r3
 *   @0x30a002 bl 0x2e4eb6 <FT_DivFix>
 *   @0x30a006 ldr r3, [pc, #0x3c8]
 *   @0x30a008 ldr r7, [sp, #0xc]
 *   @0x30a00a add r3, pc
 *   @0x30a00c add.w r3, r3, #0x100
 *   @0x30a010 str r0, [sp, #0x20]
 *   @0x30a012 ldm r3, {r0, r1, r2, r3}
 *   @0x30a014 stm.w r7, {r0, r1, r2, r3}
 *   @0x30a018 ldr r7, [sp, #0x4]
 *   @0x30a01a ldr.w r12, [sp, #0x8]
 *   @0x30a01e ldrh.w r3, [r7, #0x44]
 *   @0x30a022 cmp r3, #0x0
 *   @0x30a024 beq 0x30a11a <af_shaper_get_coverage+0x616>
 *   @0x30a026 ldr.w r3, [r10]
 *   @0x30a02a ldr r7, [sp, #0x44]
 *   @0x30a02c ldr r3, [r3, #0x4]
 *   @0x30a02e ldr.w r3, [r7, r3, lsl #2]
 *   @0x30a032 ldr r3, [r3, #0x14]
 *   @0x30a034 cmp r3, #0x0
 *   @0x30a036 beq 0x30a11a <af_shaper_get_coverage+0x616>
 *   @0x30a038 ldr r1, [sp, #0x1c]
 *   @0x30a03a mov r0, r10
 *   @0x30a03c add r2, sp, #0x4c
 *   @0x30a03e subs.w r7, r12, r1
 *   @0x30a042 add r1, sp, #0x50
 *   @0x30a044 it ne
 *   @0x30a046 movne r7, #0x1
 *   @0x30a048 blx r3
 *   @0x30a04a cbnz r7, 0x30a064 <af_shaper_get_coverage+0x560>
 *   @0x30a04c ldr r3, [sp, #0x4c]
 *   @0x30a04e cmp r3, #0x0
 *   @0x30a050 bgt 0x30a05c <af_shaper_get_coverage+0x558>
 *   @0x30a052 ldr r3, [r4, #-24]
 *   @0x30a056 cmp r3, #0x0
 *   @0x30a058 bgt 0x30a0ee <af_shaper_get_coverage+0x5ea>
 *   @0x30a05a b 0x30a0f6 <af_shaper_get_coverage+0x5f2>
 *   @0x30a05c ldr.w r2, [r8, #0x164]
 *   @0x30a060 cmp r3, r2
 *   @0x30a062 beq 0x30a052 <af_shaper_get_coverage+0x54e>
 *   @0x30a064 ldr r2, [r4, #-28]
 *   @0x30a068 ldr r1, [sp, #0x4]
 *   @0x30a06a ldr r0, [r5, #0x4]
 *   @0x30a06c bl 0x308d50 <TT_New_Context+0x8b48>
 *   @0x30a070 ldr.w r1, [r9, #0xc]
 *   @0x30a074 lsls r0, r0, #0x10
 *   @0x30a076 bl 0x3072ac <TT_New_Context+0x70a4>
 *   @0x30a07a ldr r1, [sp, #0x20]
 *   @0x30a07c bl 0x2e4eb6 <FT_DivFix>
 *   @0x30a080 ldr r3, [r4, #-28]
 *   @0x30a084 str.w r3, [r8, #0x164]
 *   @0x30a088 ldrh.w r3, [r9, #0x8]
 *   @0x30a08c strh.w r3, [r8, #0x160]
 *   @0x30a090 add.w r0, r0, #0x8000
 *   @0x30a094 asrs r0, r0, #0x10
 *   @0x30a096 str.w r0, [r8, #0x16c]
 *   @0x30a09a cmp r7, #0x0
 *   @0x30a09c beq 0x30a052 <af_shaper_get_coverage+0x54e>
 *   @0x30a09e ldr r2, [r4, #-24]
 *   @0x30a0a2 ldr r1, [sp, #0x4]
 *   @0x30a0a4 ldr r0, [r5, #0x4]
 *   @0x30a0a6 bl 0x308d50 <TT_New_Context+0x8b48>
 *   @0x30a0aa ldr.w r1, [r9, #0x10]
 *   @0x30a0ae lsls r7, r0, #0x10
 *   @0x30a0b0 mov r0, r7
 *   @0x30a0b2 bl 0x3072ac <TT_New_Context+0x70a4>
 *   @0x30a0b6 ldr r1, [sp, #0x20]
 *   @0x30a0b8 bl 0x2e4eb6 <FT_DivFix>
 *   @0x30a0bc ldr r3, [r4, #-24]
 *   @0x30a0c0 str.w r3, [r8, #0x168]
 *   @0x30a0c4 ldrh.w r3, [r9, #0x8]
 *   @0x30a0c8 strh.w r3, [r8, #0x160]
 *   @0x30a0cc add.w r0, r0, #0x8000
 *   @0x30a0d0 asrs r0, r0, #0x10
 *   @0x30a0d2 str.w r0, [r8, #0x170]
 *   @0x30a0d6 rsb.w r0, r7, #0xff000000
 *   @0x30a0da ldr r7, [sp, #0x18]
 *   @0x30a0dc add.w r0, r0, #0xf80000
 *   @0x30a0e0 add r0, r7
 *   @0x30a0e2 mov r1, r7
 *   @0x30a0e4 bl 0x2e4eb6 <FT_DivFix>
 *   @0x30a0e8 str.w r0, [r8, #0x174]
 *   @0x30a0ec b 0x30a0f6 <af_shaper_get_coverage+0x5f2>
 *   @0x30a0ee ldr.w r2, [r8, #0x168]
 *   @0x30a0f2 cmp r3, r2
 *   @0x30a0f4 bne 0x30a09e <af_shaper_get_coverage+0x59a>
 *   @0x30a0f6 ldr r1, [sp, #0x40]
 *   @0x30a0f8 ldr.w r2, [r8, #0x170]
 *   @0x30a0fc add.w r7, r1, #0x6c
 *   @0x30a100 ldr.w r1, [r8, #0x16c]
 *   @0x30a104 mov r0, r7
 *   @0x30a106 bl 0x2e6670 <FT_Outline_EmboldenXY>
 *   @0x30a10a ldr.w r3, [r8, #0x174]
 *   @0x30a10e mov r0, r7
 *   @0x30a110 add r1, sp, #0x58
 *   @0x30a112 str r3, [r4, #-4]
 *   @0x30a116 bl 0x2e6580 <FT_Outline_Transform>
 *   @0x30a11a ldr r7, [sp, #0x28]
 *   @0x30a11c ldrb r3, [r7, #0x8]
 *   @0x30a11e strb r3, [r5, #0x10]
 *   @0x30a120 cbz r3, 0x30a15a <af_shaper_get_coverage+0x656>
 *   @0x30a122 add.w r3, r7, #0xc
 *   @0x30a126 add.w lr, sp, #0x98
 *   @0x30a12a add.w r8, sp, #0xa8
 *   @0x30a12e ldm r3, {r0, r1, r2, r3}
 *   @0x30a130 stm.w lr, {r0, r1, r2, r3}
 *   @0x30a134 add.w r3, r7, #0x1c
 *   @0x30a138 ldr r7, [sp, #0xc]
 *   @0x30a13a ldm.w r3, {r0, r1}
 *   @0x30a13e stm.w r8, {r0, r1}
 *   @0x30a142 ldm.w lr, {r0, r1, r2, r3}
 *   @0x30a146 stm.w r7, {r0, r1, r2, r3}
 *   @0x30a14a add r0, sp, #0x58
 *   @0x30a14c bl 0x2e4f7c <FT_Matrix_Invert>
 *   @0x30a150 cbnz r0, 0x30a15a <af_shaper_get_coverage+0x656>
 *   @0x30a152 mov r0, r8
 *   @0x30a154 add r1, sp, #0x58
 *   @0x30a156 bl 0x2e6548 <FT_Vector_Transform>
 *   @0x30a15a ldr r2, [r6, #0x48]
 *   @0x30a15c ldr r3, [pc, #0x25c]
 *   @0x30a15e ldr r1, [sp, #0x3c]
 *   @0x30a160 cmp r2, r3
 *   @0x30a162 add.w r7, r1, #0x14
 *   @0x30a166 bne.w 0x30a290 <af_shaper_get_coverage+0x78c>
 *   @0x30a16a ldrb r3, [r5, #0x10]
 *   @0x30a16c cbz r3, 0x30a17a <af_shaper_get_coverage+0x676>
 *   @0x30a16e add.w r0, r6, #0x6c
 *   @0x30a172 ldr r1, [r5, #0x24]
 *   @0x30a174 ldr r2, [r5, #0x28]
 *   @0x30a176 bl 0x2e6424 <FT_Outline_Translate>
 *   @0x30a17a ldr.w r3, [r11, #0x8]
 *   @0x30a17e ldr r1, [sp, #0xc4]
 *   @0x30a180 str r3, [r5, #0x2c]
 *   @0x30a182 ldr.w r3, [r11, #0x10]
 *   @0x30a186 str r3, [r5, #0x30]
 *   @0x30a188 ldr r0, [r6, #0x28]
 *   @0x30a18a bl 0x3072ac <TT_New_Context+0x70a4>
 *   @0x30a18e ldr.w r3, [r11, #0x8]
 *   @0x30a192 add r0, r3
 *   @0x30a194 ldr.w r3, [r11, #0x10]
 *   @0x30a198 str r0, [r5, #0x34]
 *   @0x30a19a str r3, [r5, #0x38]
 *   @0x30a19c ldrsh.w r3, [r6, #0x6e]
 *   @0x30a1a0 cmp r3, #0x0
 *   @0x30a1a2 beq 0x30a294 <af_shaper_get_coverage+0x790>
 *   @0x30a1a4 ldr r2, [sp, #0x14]
 *   @0x30a1a6 ldr.w r12, [r2, #0x1c]
 *   @0x30a1aa cmp.w r12, #0x0
 *   @0x30a1ae beq 0x30a1ba <af_shaper_get_coverage+0x6b6>
 *   @0x30a1b0 ldr r0, [sp, #0x2c]
 *   @0x30a1b2 mov r1, r11
 *   @0x30a1b4 mov r2, r7
 *   @0x30a1b6 mov r3, r10
 *   @0x30a1b8 blx r12
 *   @0x30a1ba ldr r3, [r4, #0x14]
 *   @0x30a1bc cmp r3, #0x1
 *   @0x30a1be beq 0x30a262 <af_shaper_get_coverage+0x75e>
 *   @0x30a1c0 ldr.w r2, [r11, #0x38]
 *   @0x30a1c4 ldr.w r3, [r11, #0x40]
 *   @0x30a1c8 cmp r2, #0x1
 *   @0x30a1ca ble 0x30a24e <af_shaper_get_coverage+0x74a>
 *   @0x30a1cc ldr.w r1, [r11, #0xab4]
 *   @0x30a1d0 lsls r1, r1, #0x1d
 *   @0x30a1d2 bmi 0x30a24e <af_shaper_get_coverage+0x74a>
 *   @0x30a1d4 mov.w lr, #0x2c
 *   @0x30a1d8 ldr.w r12, [r3, #0x4]
 *   @0x30a1dc mla lr, lr, r2, r3
 *   @0x30a1e0 ldr.w r8, [r3, #0x8]
 *   @0x30a1e4 ldr r0, [r5, #0x34]
 *   @0x30a1e6 cmp.w r12, #0x17
 *   @0x30a1ea sub.w lr, lr, #0x2c
 *   @0x30a1ee ldr.w r2, [lr, #0x4]
 *   @0x30a1f2 ldr.w r3, [lr, #0x8]
 *   @0x30a1f6 rsb r0, r2, r0
 *   @0x30a1fa rsb r2, r12, r8
 *   @0x30a1fe it le
 *   @0x30a200 suble r2, #0x8
 *   @0x30a202 add r3, r0
 *   @0x30a204 add.w r9, r2, #0x20
 *   @0x30a208 cmp r0, #0x17
 *   @0x30a20a bic r9, r9, #0x3f
 *   @0x30a20e it le
 *   @0x30a210 addle r3, #0x8
 *   @0x30a212 cmp r9, r8
 *   @0x30a214 add.w r1, r3, #0x20
 *   @0x30a218 bic r1, r1, #0x3f
 *   @0x30a21c str.w r9, [r5, #0x2c]
 *   @0x30a220 str r1, [r5, #0x34]
 *   @0x30a222 blt 0x30a232 <af_shaper_get_coverage+0x72e>
 *   @0x30a224 cmp.w r12, #0x0
 *   @0x30a228 itt gt
 *   @0x30a22a subgt.w r9, r9, #0x40
 *   @0x30a22e strgt.w r9, [r5, #0x2c]
 *   @0x30a232 ldr.w lr, [lr, #0x8]
 *   @0x30a236 cmp r1, lr
 *   @0x30a238 bgt 0x30a242 <af_shaper_get_coverage+0x73e>
 *   @0x30a23a cmp r0, #0x0
 *   @0x30a23c itt gt
 *   @0x30a23e addgt r1, #0x40
 *   @0x30a240 strgt r1, [r5, #0x34]
 *   @0x30a242 ldr r1, [r5, #0x2c]
 *   @0x30a244 subs r2, r1, r2
 *   @0x30a246 str.w r2, [r6, #0x90]
 *   @0x30a24a ldr r2, [r5, #0x34]
 *   @0x30a24c b 0x30a288 <af_shaper_get_coverage+0x784>
 *   @0x30a24e ldr r1, [r5, #0x2c]
 *   @0x30a250 ldr r3, [r5, #0x34]
 *   @0x30a252 add.w r0, r1, #0x20
 *   @0x30a256 bic r0, r0, #0x3f
 *   @0x30a25a add.w r2, r3, #0x20
 *   @0x30a25e str r0, [r5, #0x2c]
 *   @0x30a260 b 0x30a27c <af_shaper_get_coverage+0x778>
 *   @0x30a262 ldr r3, [r5, #0x34]
 *   @0x30a264 ldr.w r2, [r11, #0xac4]
 *   @0x30a268 ldr r1, [r5, #0x2c]
 *   @0x30a26a ldr.w r0, [sp, #0xb80]
 *   @0x30a26e add r2, r3
 *   @0x30a270 adds r2, #0x20
 *   @0x30a272 add r0, r1
 *   @0x30a274 adds r0, #0x20
 *   @0x30a276 bic r0, r0, #0x3f
 *   @0x30a27a str r0, [r5, #0x2c]
 *   @0x30a27c bic r2, r2, #0x3f
 *   @0x30a280 subs r1, r0, r1
 *   @0x30a282 str r2, [r5, #0x34]
 *   @0x30a284 str.w r1, [r6, #0x90]
 *   @0x30a288 subs r3, r2, r3
 *   @0x30a28a str.w r3, [r6, #0x94]
 *   @0x30a28e b 0x30a294 <af_shaper_get_coverage+0x790>
 *   @0x30a290 movs r3, #0x7
 *   @0x30a292 str r3, [sp, #0x10]
 *   @0x30a294 ldr r3, [r6, #0x20]
 *   @0x30a296 ldr r0, [r6, #0x2c]
 *   @0x30a298 subs r0, r0, r3
 *   @0x30a29a str r0, [r4, #-24]
 *   @0x30a29e ldr r2, [r6, #0x30]
 *   @0x30a2a0 ldr r3, [r6, #0x24]
 *   @0x30a2a2 subs r3, r2, r3
 *   @0x30a2a4 str r3, [r4, #-20]
 *   @0x30a2a8 ldr.w r1, [r10, #0x8]
 *   @0x30a2ac bl 0x3072ac <TT_New_Context+0x70a4>
 *   @0x30a2b0 str r0, [r4, #-24]
 *   @0x30a2b4 ldr r0, [r4, #-20]
 *   @0x30a2b8 ldr.w r1, [r10, #0xc]
 *   @0x30a2bc bl 0x3072ac <TT_New_Context+0x70a4>
 *   @0x30a2c0 ldrb r3, [r5, #0x10]
 *   @0x30a2c2 str r0, [r4, #-20]
 *   @0x30a2c6 cbz r3, 0x30a2dc <af_shaper_get_coverage+0x7d8>
 *   @0x30a2c8 add.w r8, sp, #0x98
 *   @0x30a2cc mov r0, r7
 *   @0x30a2ce mov r1, r8
 *   @0x30a2d0 bl 0x2e6580 <FT_Outline_Transform>
 *   @0x30a2d4 add r0, sp, #0x50
 *   @0x30a2d6 mov r1, r8
 *   @0x30a2d8 bl 0x2e6548 <FT_Vector_Transform>
 *   @0x30a2dc ldr r1, [r5, #0x2c]
 *   @0x30a2de cbz r1, 0x30a2ea <af_shaper_get_coverage+0x7e6>
 *   @0x30a2e0 mov r0, r7
 *   @0x30a2e2 rsbs r1, r1, #0
 *   @0x30a2e4 movs r2, #0x0
 *   @0x30a2e6 bl 0x2e6424 <FT_Outline_Translate>
 *   @0x30a2ea mov r0, r7
 *   @0x30a2ec add r1, sp, #0x58
 *   @0x30a2ee bl 0x2e63cc <FT_Outline_Get_CBox>
 *   @0x30a2f2 ldr r0, [r4, #-8]
 *   @0x30a2f6 ldr r3, [r4, #-4]
 *   @0x30a2fa ldr r2, [r4, #-16]
 *   @0x30a2fe adds r0, #0x3f
 *   @0x30a300 ldr r1, [r4, #-12]
 *   @0x30a304 adds r3, #0x3f
 *   @0x30a306 bic r2, r2, #0x3f
 *   @0x30a30a bic r3, r3, #0x3f
 *   @0x30a30e bic r1, r1, #0x3f
 *   @0x30a312 bic r0, r0, #0x3f
 *   @0x30a316 str r2, [r4, #-16]
 *   @0x30a31a str r1, [r4, #-12]
 *   @0x30a31e subs r1, r3, r1
 *   @0x30a320 str r0, [r4, #-8]
 *   @0x30a324 subs r0, r0, r2
 *   @0x30a326 str r3, [r4, #-4]
 *   @0x30a32a str r2, [r6, #0x20]
 *   @0x30a32c str r3, [r6, #0x24]
 *   @0x30a32e str r0, [r6, #0x18]
 *   @0x30a330 str r1, [r6, #0x1c]
 *   @0x30a332 ldr r1, [r4, #-24]
 *   @0x30a336 add r2, r1
 *   @0x30a338 bic r2, r2, #0x3f
 *   @0x30a33c str r2, [r6, #0x2c]
 *   @0x30a33e ldr r2, [r4, #-20]
 *   @0x30a342 add r3, r2
 *   @0x30a344 bic r3, r3, #0x3f
 *   @0x30a348 str r3, [r6, #0x30]
 *   @0x30a34a ldr r3, [r4, #0x14]
 *   @0x30a34c cmp r3, #0x1
 *   @0x30a34e beq 0x30a370 <af_shaper_get_coverage+0x86c>
 *   @0x30a350 ldr r3, [r6, #0x4]
 *   @0x30a352 ldr r3, [r3, #0x8]
 *   @0x30a354 lsls r3, r3, #0x1d
 *   @0x30a356 bpl 0x30a370 <af_shaper_get_coverage+0x86c>
 *   @0x30a358 ldr r0, [r6, #0x28]
 *   @0x30a35a ldr.w r1, [r10, #0x8]
 *   @0x30a35e bl 0x3072ac <TT_New_Context+0x70a4>
 *   @0x30a362 movs r3, #0x0
 *   @0x30a364 str.w r3, [r6, #0x90]
 *   @0x30a368 str.w r3, [r6, #0x94]
 *   @0x30a36c str r0, [r6, #0x28]
 *   @0x30a36e b 0x30a37c <af_shaper_get_coverage+0x878>
 *   @0x30a370 ldr r3, [r6, #0x28]
 *   @0x30a372 cbz r3, 0x30a37c <af_shaper_get_coverage+0x878>
 *   @0x30a374 ldr r2, [r5, #0x34]
 *   @0x30a376 ldr r3, [r5, #0x2c]
 *   @0x30a378 subs r3, r2, r3
 *   @0x30a37a str r3, [r6, #0x28]
 *   @0x30a37c ldr r0, [r6, #0x34]
 *   @0x30a37e ldr.w r1, [r10, #0xc]
 *   @0x30a382 bl 0x3072ac <TT_New_Context+0x70a4>
 *   @0x30a386 ldr r3, [r6, #0x28]
 *   @0x30a388 ldr r2, [pc, #0x30]
 *   @0x30a38a adds r3, #0x20
 *   @0x30a38c bic r3, r3, #0x3f
 *   @0x30a390 str r3, [r6, #0x28]
 *   @0x30a392 str r2, [r6, #0x48]
 *   @0x30a394 adds r0, #0x20
 *   @0x30a396 bic r0, r0, #0x3f
 *   @0x30a39a str r0, [r6, #0x34]
 *   @0x30a39c ldr.w r8, [sp, #0x10]
 *   @0x30a3a0 movs r3, #0x0
 *   @0x30a3a2 mov r0, r11
 *   @0x30a3a4 str r3, [r5, #0x4]
 *   @0x30a3a6 str r3, [r5, #0x8]
 *   @0x30a3a8 str r3, [sp, #0x84]
 *   @0x30a3aa bl 0x3087c0 <TT_New_Context+0x85b8>
 *   @0x30a3ae mov r0, r8
 *   @0x30a3b0 add.w sp, sp, #0x1aa0
 *   @0x30a3b4 add sp, #0xc
 *   @0x30a3b6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x30a3ba nop
 *   @0x30a3bc strb r4, [r5, #0x11]
 *   @0x30a3be ldr r5, [r6, #0x74]
 *   @0x30a3c0 ldrb r2, [r0, #0x1b]
 *   @0x30a3c2 movs r6, r1
 *   @0x30a3c4 strd pc, pc, [pc, #1020]!
 *   @0x30a3c8 .word 0xff98ffff
 *   @0x30a3cc .word 0xff94ffff
 *   @0x30a3d0 str r6, [r1, #0x64]
 *   @0x30a3d2 movs r1, r1
 *   @0x30a3d4 push {r0, r1, r2, r4, r5, lr}
 *   @0x30a3d6 mov r5, r1
 *   @0x30a3d8 mov r4, r0
 *   @0x30a3da cbz r0, 0x30a3f6 <af_shaper_get_coverage+0x8f2>
 *   @0x30a3dc ldr r3, [r0, #0x74]
 *   @0x30a3de str r3, [sp, #0x4]
 *   @0x30a3e0 cbnz r3, 0x30a3fa <af_shaper_get_coverage+0x8f6>
 *   @0x30a3e2 add r1, sp, #0x4
 *   @0x30a3e4 bl 0x309b08 <af_shaper_get_coverage+0x4>
 *   @0x30a3e8 cbnz r0, 0x30a400 <af_shaper_get_coverage+0x8fc>
 *   @0x30a3ea ldr r3, [sp, #0x4]
 *   @0x30a3ec str r3, [r4, #0x74]
 *   @0x30a3ee ldr r3, [pc, #0x14]
 *   @0x30a3f0 add r3, pc
 *   @0x30a3f2 str r3, [r4, #0x78]
 *   @0x30a3f4 b 0x30a3fa <af_shaper_get_coverage+0x8f6>
 *   @0x30a3f6 movs r0, #0x23
 *   @0x30a3f8 b 0x30a400 <af_shaper_get_coverage+0x8fc>
 *   @0x30a3fa ldr r3, [sp, #0x4]
 *   @0x30a3fc movs r0, #0x0
 *   @0x30a3fe str r3, [r5]
 *   @0x30a400 add sp, #0xc
 *   @0x30a402 pop {r4, r5, pc}
 *   @0x30a404 b 0x309cca <af_shaper_get_coverage+0x1c6>
 *   @0x30a406 vtbl.8 d30, {d15, d16}, d29
 *   @0x30a40a mvns r7, r6
 *   @0x30a40c mov r5, r0
 *   @0x30a40e mov r6, r1
 *   @0x30a410 ldr.w r9, [r0, #0xc]
 *   @0x30a414 ldr.w r8, [r0, #0x10]
 *   @0x30a418 mov r4, r2
 *   @0x30a41a ldrb r7, [r0, #0x14]
 *   @0x30a41c mov r0, r1
 *   @0x30a41e ldr r1, [pc, #0xc4]
 *   @0x30a420 add r1, pc
 *   @0x30a422 blx 0xb6574 <strcmp@plt>
 *   @0x30a426 cbnz r0, 0x30a43c <af_shaper_get_coverage+0x938>
 *   @0x30a428 ldr r0, [r4]
 *   @0x30a42a add r1, sp, #0x4
 *   @0x30a42c mov r2, r5
 *   @0x30a42e bl 0x30a3d4 <af_shaper_get_coverage+0x8d0>
 *   @0x30a432 cmp r0, #0x0
 *   @0x30a434 bne 0x30a4de <af_shaper_get_coverage+0x9da>
 *   @0x30a436 ldr r3, [sp, #0x4]
 *   @0x30a438 ldr r3, [r3, #0x8]
 *   @0x30a43a b 0x30a488 <af_shaper_get_coverage+0x984>
 *   @0x30a43c ldr r1, [pc, #0xa8]
 *   @0x30a43e mov r0, r6
 *   @0x30a440 add r1, pc
 *   @0x30a442 blx 0xb6574 <strcmp@plt>
 *   @0x30a446 cbnz r0, 0x30a458 <af_shaper_get_coverage+0x954>
 *   @0x30a448 ldr r3, [pc, #0xa0]
 *   @0x30a44a add r3, pc
 *   @0x30a44c ldr r3, [r3]
 *   @0x30a44e ldr.w r3, [r3, r9, lsl #2]
 *   @0x30a452 ldr r3, [r3, #0x8]
 *   @0x30a454 str r3, [r4]
 *   @0x30a456 b 0x30a4de <af_shaper_get_coverage+0x9da>
 *   @0x30a458 ldr r1, [pc, #0x94]
 *   @0x30a45a mov r0, r6
 *   @0x30a45c add r1, pc
 *   @0x30a45e blx 0xb6574 <strcmp@plt>
 *   @0x30a462 cbnz r0, 0x30a46a <af_shaper_get_coverage+0x966>
 *   @0x30a464 str.w r8, [r4]
 *   @0x30a468 b 0x30a4de <af_shaper_get_coverage+0x9da>
 *   @0x30a46a ldr r1, [pc, #0x88]
 *   @0x30a46c mov r0, r6
 *   @0x30a46e add r1, pc
 *   @0x30a470 blx 0xb6574 <strcmp@plt>
 *   @0x30a474 cbnz r0, 0x30a48c <af_shaper_get_coverage+0x988>
 *   @0x30a476 ldr r0, [r4]
 *   @0x30a478 add r1, sp, #0x4
 *   @0x30a47a mov r2, r5
 *   @0x30a47c bl 0x30a3d4 <af_shaper_get_coverage+0x8d0>
 *   @0x30a480 cmp r0, #0x0
 *   @0x30a482 bne 0x30a4de <af_shaper_get_coverage+0x9da>
 *   @0x30a484 ldr r3, [sp, #0x4]
 *   @0x30a486 ldr r3, [r3, #0xc]
 *   @0x30a488 str r3, [r4, #0x4]
 *   @0x30a48a b 0x30a4de <af_shaper_get_coverage+0x9da>
 *   @0x30a48c ldr r1, [pc, #0x68]
 *   @0x30a48e mov r0, r6
 *   @0x30a490 add r1, pc
 *   @0x30a492 blx 0xb6574 <strcmp@plt>
 *   @0x30a496 cbnz r0, 0x30a49c <af_shaper_get_coverage+0x998>
 *   @0x30a498 strb r7, [r4]
 *   @0x30a49a b 0x30a4de <af_shaper_get_coverage+0x9da>
 *   @0x30a49c ldr r1, [pc, #0x5c]
 *   @0x30a49e mov r0, r6
 *   @0x30a4a0 add r1, pc
 *   @0x30a4a2 blx 0xb6574 <strcmp@plt>
 *   @0x30a4a6 cbnz r0, 0x30a4ca <af_shaper_get_coverage+0x9c6>
 *   @0x30a4a8 ldr r3, [r5, #0x18]
 *   @0x30a4aa str r3, [r4]
 *   @0x30a4ac ldr r3, [r5, #0x1c]
 *   @0x30a4ae str r3, [r4, #0x4]
 *   @0x30a4b0 ldr r3, [r5, #0x20]
 *   @0x30a4b2 str r3, [r4, #0x8]
 *   @0x30a4b4 ldr r3, [r5, #0x24]
 *   @0x30a4b6 str r3, [r4, #0xc]
 *   @0x30a4b8 ldr r3, [r5, #0x28]
 *   @0x30a4ba str r3, [r4, #0x10]
 *   @0x30a4bc ldr r3, [r5, #0x2c]
 *   @0x30a4be str r3, [r4, #0x14]
 *   @0x30a4c0 ldr r3, [r5, #0x30]
 *   @0x30a4c2 str r3, [r4, #0x18]
 *   @0x30a4c4 ldr r3, [r5, #0x34]
 *   @0x30a4c6 str r3, [r4, #0x1c]
 *   @0x30a4c8 b 0x30a4de <af_shaper_get_coverage+0x9da>
 *   @0x30a4ca ldr r1, [pc, #0x34]
 *   @0x30a4cc mov r0, r6
 *   @0x30a4ce add r1, pc
 *   @0x30a4d0 blx 0xb6574 <strcmp@plt>
 *   @0x30a4d4 cbnz r0, 0x30a4dc <af_shaper_get_coverage+0x9d8>
 *   @0x30a4d6 ldrb r3, [r5, #0x15]
 *   @0x30a4d8 strb r3, [r4]
 *   @0x30a4da b 0x30a4de <af_shaper_get_coverage+0x9da>
 *   @0x30a4dc movs r0, #0xc
 *   @0x30a4de add sp, #0xc
 *   @0x30a4e0 pop.w {r4, r5, r6, r7, r8, r9, pc}
 *   @0x30a4e4 ldr r3, [pc, #0xa4]
 *   @0x30a4e6 movs r0, r1
 *   @0x30a4e8 ldr r3, [pc, #0x74]
 *   @0x30a4ea movs r0, r1
 *   @0x30a4ec strb r6, [r3, #0x1e]
 *   @0x30a4ee movs r6, r1
 *   @0x30a4f0 ldr r3, [pc, #0x44]
 *   @0x30a4f2 movs r0, r1
 *   @0x30a4f4 ldr r3, [pc, #0x38]
 *   @0x30a4f6 movs r0, r1
 *   @0x30a4f8 ldr r2, [pc, #0x3f8]
 *   @0x30a4fa movs r0, r1
 *   @0x30a4fc ldr r2, [pc, #0x3d8]
 *   @0x30a4fe movs r0, r1
 *   @0x30a500 ldr r2, [pc, #0x374]
 *   @0x30a502 movs r0, r1
 *   @0x30a504 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x30a508 mov r5, r0
 *   @0x30a50a mov r7, r1
 *   @0x30a50c mov r0, r1
 *   @0x30a50e ldr r1, [pc, #0x194]
 *   @0x30a510 sub sp, #0x28
 *   @0x30a512 mov r4, r2
 *   @0x30a514 mov r6, r3
 *   @0x30a516 add r1, pc
 *   @0x30a518 blx 0xb6574 <strcmp@plt>
 *   @0x30a51c cbnz r0, 0x30a54c <af_shaper_get_coverage+0xa48>
 *   @0x30a51e cmp r6, #0x0
 *   @0x30a520 bne.w 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a524 ldr r2, [pc, #0x180]
 *   @0x30a526 add r2, pc
 *   @0x30a528 ldr r2, [r2]
 *   @0x30a52a ldr.w r3, [r2, r6, lsl #2]
 *   @0x30a52e cmp r3, #0x0
 *   @0x30a530 beq.w 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a534 ldr r0, [r3, #0x8]
 *   @0x30a536 ldr r1, [r4]
 *   @0x30a538 cmp r0, r1
 *   @0x30a53a bne 0x30a548 <af_shaper_get_coverage+0xa44>
 *   @0x30a53c ldr r3, [r3, #0x10]
 *   @0x30a53e cmp r3, #0xa
 *   @0x30a540 bne 0x30a548 <af_shaper_get_coverage+0xa44>
 *   @0x30a542 str r6, [r5, #0xc]
 *   @0x30a544 movs r0, #0x0
 *   @0x30a546 b 0x30a69c <af_shaper_get_coverage+0xb98>
 *   @0x30a548 adds r6, #0x1
 *   @0x30a54a b 0x30a52a <af_shaper_get_coverage+0xa26>
 *   @0x30a54c ldr r1, [pc, #0x15c]
 *   @0x30a54e mov r0, r7
 *   @0x30a550 add r1, pc
 *   @0x30a552 blx 0xb6574 <strcmp@plt>
 *   @0x30a556 cbnz r0, 0x30a564 <af_shaper_get_coverage+0xa60>
 *   @0x30a558 cmp r6, #0x0
 *   @0x30a55a bne.w 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a55e ldr r3, [r4]
 *   @0x30a560 str r3, [r5, #0x10]
 *   @0x30a562 b 0x30a5bc <af_shaper_get_coverage+0xab8>
 *   @0x30a564 ldr r1, [pc, #0x148]
 *   @0x30a566 mov r0, r7
 *   @0x30a568 add r1, pc
 *   @0x30a56a blx 0xb6574 <strcmp@plt>
 *   @0x30a56e cbnz r0, 0x30a58e <af_shaper_get_coverage+0xa8a>
 *   @0x30a570 cmp r6, #0x0
 *   @0x30a572 bne.w 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a576 ldr r0, [r4]
 *   @0x30a578 add r1, sp, #0x8
 *   @0x30a57a mov r2, r5
 *   @0x30a57c bl 0x30a3d4 <af_shaper_get_coverage+0x8d0>
 *   @0x30a580 cmp r0, #0x0
 *   @0x30a582 bne.w 0x30a69c <af_shaper_get_coverage+0xb98>
 *   @0x30a586 ldr r2, [r4, #0x4]
 *   @0x30a588 ldr r3, [sp, #0x8]
 *   @0x30a58a str r2, [r3, #0xc]
 *   @0x30a58c b 0x30a69c <af_shaper_get_coverage+0xb98>
 *   @0x30a58e ldr r1, [pc, #0x124]
 *   @0x30a590 mov r0, r7
 *   @0x30a592 add r1, pc
 *   @0x30a594 blx 0xb6574 <strcmp@plt>
 *   @0x30a598 mov r8, r0
 *   @0x30a59a cbnz r0, 0x30a5c0 <af_shaper_get_coverage+0xabc>
 *   @0x30a59c cbz r6, 0x30a5b8 <af_shaper_get_coverage+0xab4>
 *   @0x30a59e mov r0, r4
 *   @0x30a5a0 mov r1, r8
 *   @0x30a5a2 movs r2, #0xa
 *   @0x30a5a4 blx 0xb6670 <strtol@plt>
 *   @0x30a5a8 cbnz r0, 0x30a5ae <af_shaper_get_coverage+0xaaa>
 *   @0x30a5aa strb r0, [r5, #0x14]
 *   @0x30a5ac b 0x30a69c <af_shaper_get_coverage+0xb98>
 *   @0x30a5ae cmp r0, #0x1
 *   @0x30a5b0 bne 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a5b2 strb r0, [r5, #0x14]
 *   @0x30a5b4 mov r0, r8
 *   @0x30a5b6 b 0x30a69c <af_shaper_get_coverage+0xb98>
 *   @0x30a5b8 ldrb r3, [r4]
 *   @0x30a5ba strb r3, [r5, #0x14]
 *   @0x30a5bc mov r0, r6
 *   @0x30a5be b 0x30a69c <af_shaper_get_coverage+0xb98>
 *   @0x30a5c0 ldr r1, [pc, #0xf4]
 *   @0x30a5c2 mov r0, r7
 *   @0x30a5c4 add r1, pc
 *   @0x30a5c6 blx 0xb6574 <strcmp@plt>
 *   @0x30a5ca cmp r0, #0x0
 *   @0x30a5cc bne 0x30a66c <af_shaper_get_coverage+0xb68>
 *   @0x30a5ce cbz r6, 0x30a614 <af_shaper_get_coverage+0xb10>
 *   @0x30a5d0 add.w r8, sp, #0x4
 *   @0x30a5d4 mov r6, r0
 *   @0x30a5d6 movs r2, #0xa
 *   @0x30a5d8 mov r0, r4
 *   @0x30a5da mov r1, r8
 *   @0x30a5dc add r7, sp, #0x8
 *   @0x30a5de blx 0xb6670 <strtol@plt>
 *   @0x30a5e2 ldr r3, [sp, #0x4]
 *   @0x30a5e4 str r0, [r7, r6]
 *   @0x30a5e6 ldrb r2, [r3]
 *   @0x30a5e8 cmp r2, #0x2c
 *   @0x30a5ea bne 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a5ec cmp r4, r3
 *   @0x30a5ee beq 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a5f0 adds r6, #0x4
 *   @0x30a5f2 adds r4, r3, #0x1
 *   @0x30a5f4 cmp r6, #0x1c
 *   @0x30a5f6 bne 0x30a5d6 <af_shaper_get_coverage+0xad2>
 *   @0x30a5f8 movs r2, #0xa
 *   @0x30a5fa mov r0, r4
 *   @0x30a5fc mov r1, r8
 *   @0x30a5fe blx 0xb6670 <strtol@plt>
 *   @0x30a602 ldr r3, [sp, #0x4]
 *   @0x30a604 str r0, [sp, #0x24]
 *   @0x30a606 ldrb r2, [r3]
 *   @0x30a608 tst.w r2, #0xdf
 *   @0x30a60c bne 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a60e cmp r4, r3
 *   @0x30a610 beq 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a612 mov r4, r7
 *   @0x30a614 ldm.w r4, {r0, r12}
 *   @0x30a618 ldr r2, [r4, #0x8]
 *   @0x30a61a cmp r0, #0x0
 *   @0x30a61c ldr r7, [r4, #0xc]
 *   @0x30a61e ldr r3, [r4, #0x10]
 *   @0x30a620 ldr r6, [r4, #0x14]
 *   @0x30a622 ldr r1, [r4, #0x18]
 *   @0x30a624 ldr r4, [r4, #0x1c]
 *   @0x30a626 blt 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a628 cmp r2, #0x0
 *   @0x30a62a blt 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a62c cmp r3, #0x0
 *   @0x30a62e blt 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a630 cmp r1, #0x0
 *   @0x30a632 blt 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a634 cmp r0, r2
 *   @0x30a636 bgt 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a638 cmp r2, r3
 *   @0x30a63a bgt 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a63c cmp r3, r1
 *   @0x30a63e bgt 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a640 cmp.w r12, #0x1f4
 *   @0x30a644 bhi 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a646 cmp.w r7, #0x1f4
 *   @0x30a64a bhi 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a64c cmp.w r6, #0x1f4
 *   @0x30a650 bhi 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a652 cmp.w r4, #0x1f4
 *   @0x30a656 bhi 0x30a69a <af_shaper_get_coverage+0xb96>
 *   @0x30a658 str r0, [r5, #0x18]
 *   @0x30a65a str.w r12, [r5, #0x1c]
 *   @0x30a65e str r2, [r5, #0x20]
 *   @0x30a660 str r7, [r5, #0x24]
 *   @0x30a662 str r3, [r5, #0x28]
 *   @0x30a664 str r6, [r5, #0x2c]
 *   @0x30a666 str r1, [r5, #0x30]
 *   @0x30a668 str r4, [r5, #0x34]
 *   @0x30a66a b 0x30a544 <af_shaper_get_coverage+0xa40>
 *   @0x30a66c ldr r1, [pc, #0x4c]
 *   @0x30a66e mov r0, r7
 *   @0x30a670 add r1, pc
 *   @0x30a672 blx 0xb6574 <strcmp@plt>
 *   @0x30a676 mov r7, r0
 *   @0x30a678 cbnz r0, 0x30a696 <af_shaper_get_coverage+0xb92>
 *   @0x30a67a cbz r6, 0x30a690 <af_shaper_get_coverage+0xb8c>
 *   @0x30a67c mov r0, r4
 *   @0x30a67e mov r1, r7
 *   @0x30a680 movs r2, #0xa
 *   @0x30a682 blx 0xb6670 <strtol@plt>
 *   @0x30a686 cbnz r0, 0x30a68c <af_shaper_get_coverage+0xb88>
 *   @0x30a688 strb r0, [r5, #0x15]
 *   @0x30a68a b 0x30a69c <af_shaper_get_coverage+0xb98>
 *   @0x30a68c movs r3, #0x1
 *   @0x30a68e b 0x30a692 <af_shaper_get_coverage+0xb8e>
 *   @0x30a690 ldrb r3, [r4]
 *   @0x30a692 strb r3, [r5, #0x15]
 *   @0x30a694 b 0x30a544 <af_shaper_get_coverage+0xa40>
 *   @0x30a696 movs r0, #0xc
 *   @0x30a698 b 0x30a69c <af_shaper_get_coverage+0xb98>
 *   @0x30a69a movs r0, #0x6
 *   @0x30a69c add sp, #0x28
 *   @0x30a69e pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x30a6a2 nop
 *   @0x30a6a4 ldr r2, [pc, #0x11c]
 *   @0x30a6a6 movs r0, r1
 *   @0x30a6a8 strb r2, [r0, #0x1b]
 *   @0x30a6aa movs r6, r1
 *   @0x30a6ac ldr r2, [pc, #0x74]
 *   @0x30a6ae movs r0, r1
 *   @0x30a6b0 ldr r2, [pc, #0x50]
 *   @0x30a6b2 movs r0, r1
 *   @0x30a6b4 ldr r1, [pc, #0x3f0]
 *   @0x30a6b6 movs r0, r1
 *   @0x30a6b8 ldr r1, [pc, #0x348]
 *   @0x30a6ba movs r0, r1
/* ═══════════════════════════════════════════════════════════════════════
 * §11  anon_thumb_2f0444   0x2f0444..0x2f08c6   1,154 B / 445 条   in-degree 2
 * psaux/pshints.c 带（1,154 B / 7 个 bl 入口 / 445 条）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 2 条 Thumb `bl` 指向本段起始：ps_hints_apply×2；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 3 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} / mov r6, r2 / ldr.w r2, [r0, #0xc8]（帧：push {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}）；窗口内出口 11 个
 * 结构：入口可达 424 B / 136 条（36%）；段内 bl 入口 6 个：0x2f05fc(16 B/6 条) / 0x2f06f2(108 B/43 条) / 0x2f0700(94 B/36 条) / 0x2f075e(64 B/30 条) / 0x2f079e(48 B/21 条) / 0x2f07ce(248 B/98 条)
 *      可打印岛：无 ≥16 B 的
 * 入口 424 B / 136 条，被 ps_hints_apply bl 2 次；3 处 bl 打向 ft_mem_realloc。段内 6 个 bl 入口：
 *      0x2f05fc(16 B) / 0x2f06f2(108 B) / 0x2f0700(94 B) / 0x2f075e(64 B) / 0x2f079e(48 B) / 0x2f07ce(248 B)。
 *
 * 锚点：445 条（= asm/index-anonT_2f0444.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2f0444 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2f0448 mov r6, r2
 *   @0x2f044a ldr.w r2, [r0, #0xc8]
 *   @0x2f044e mov r4, r0
 *   @0x2f0450 ldr r7, [sp, #0x30]
 *   @0x2f0452 cmp r1, r2
 *   @0x2f0454 bne 0x2f045e <FT_Done_Memory+0x67ea>
 *   @0x2f0456 ldr.w r2, [r0, #0xcc]
 *   @0x2f045a cmp r3, r2
 *   @0x2f045c beq 0x2f046e <FT_Done_Memory+0x67fa>
 *   @0x2f045e str.w r1, [r4, #0xc8]
 *   @0x2f0462 mov r0, r4
 *   @0x2f0464 str.w r3, [r4, #0xcc]
 *   @0x2f0468 movs r1, #0x0
 *   @0x2f046a bl 0x2f03c2 <FT_Done_Memory+0x674e>
 *   @0x2f046e ldr.w r3, [r4, #0x194]
 *   @0x2f0472 cmp r6, r3
 *   @0x2f0474 bne 0x2f0480 <FT_Done_Memory+0x680c>
 *   @0x2f0476 ldr.w r3, [r4, #0x198]
 *   @0x2f047a cmp r7, r3
 *   @0x2f047c beq.w 0x2f05e6 <FT_Done_Memory+0x6972>
 *   @0x2f0480 str.w r6, [r4, #0x194]
 *   @0x2f0484 mov r0, r4
 *   @0x2f0486 str.w r7, [r4, #0x198]
 *   @0x2f048a movs r1, #0x1
 *   @0x2f048c bl 0x2f03c2 <FT_Done_Memory+0x674e>
 *   @0x2f0490 ldr r3, [pc, #0x158]
 *   @0x2f0492 cmp r6, r3
 *   @0x2f0494 ble 0x2f049a <FT_Done_Memory+0x6826>
 *   @0x2f0496 movs r3, #0x0
 *   @0x2f0498 b 0x2f04ac <FT_Done_Memory+0x6838>
 *   @0x2f049a movs r2, #0x7d
 *   @0x2f049c ldr.w r3, [r4, #0x9ac]
 *   @0x2f04a0 muls r2, r6, r2
 *   @0x2f04a2 cmp.w r2, r3, lsl #3
 *   @0x2f04a6 ite ge
 *   @0x2f04a8 movge r3, #0x0
 *   @0x2f04aa movlt r3, #0x1
 *   @0x2f04ac ldr.w r5, [r4, #0x9b0]
 *   @0x2f04b0 strb.w r3, [r4, #0x9bc]
 *   @0x2f04b4 cmp r5, #0x0
 *   @0x2f04b6 bgt 0x2f04c2 <FT_Done_Memory+0x684e>
 *   @0x2f04b8 str.w r5, [r4, #0x9b4]
 *   @0x2f04bc mov.w r8, #0x0
 *   @0x2f04c0 b 0x2f04d2 <FT_Done_Memory+0x685e>
 *   @0x2f04c2 mov r0, r5
 *   @0x2f04c4 mov r1, r6
 *   @0x2f04c6 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f04ca cmp r0, #0x20
 *   @0x2f04cc ble 0x2f04b8 <FT_Done_Memory+0x6844>
 *   @0x2f04ce subs r5, #0x1
 *   @0x2f04d0 b 0x2f04b4 <FT_Done_Memory+0x6840>
 *   @0x2f04d2 cmp.w r8, #0x1
 *   @0x2f04d6 beq 0x2f04f0 <FT_Done_Memory+0x687c>
 *   @0x2f04d8 blo 0x2f04ea <FT_Done_Memory+0x6876>
 *   @0x2f04da cmp.w r8, #0x2
 *   @0x2f04de bne 0x2f04f6 <FT_Done_Memory+0x6882>
 *   @0x2f04e0 add.w r5, r4, #0x19c
 *   @0x2f04e4 add.w r5, r5, #0x408
 *   @0x2f04e8 b 0x2f04fa <FT_Done_Memory+0x6886>
 *   @0x2f04ea add.w r5, r4, #0x19c
 *   @0x2f04ee b 0x2f04fa <FT_Done_Memory+0x6886>
 *   @0x2f04f0 add.w r5, r4, #0x3a0
 *   @0x2f04f4 b 0x2f04fa <FT_Done_Memory+0x6886>
 *   @0x2f04f6 add.w r5, r4, #0x7a8
 *   @0x2f04fa ldr r9, [r5], #4
 *   @0x2f04fe adds r5, #0x20
 *   @0x2f0500 cmp.w r9, #0x0
 *   @0x2f0504 beq 0x2f0558 <FT_Done_Memory+0x68e4>
 *   @0x2f0506 mov r1, r6
 *   @0x2f0508 ldr r0, [r5, #-24]
 *   @0x2f050c bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f0510 mov r1, r6
 *   @0x2f0512 add.w r9, r9, #0xffffffff
 *   @0x2f0516 add r0, r7
 *   @0x2f0518 str r0, [r5, #-4]
 *   @0x2f051c ldr r0, [r5, #-20]
 *   @0x2f0520 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f0524 mov r1, r6
 *   @0x2f0526 add r0, r7
 *   @0x2f0528 str r0, [r5, #-8]
 *   @0x2f052c ldr r0, [r5, #-32]
 *   @0x2f0530 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f0534 mov r1, r6
 *   @0x2f0536 add r0, r7
 *   @0x2f0538 str r0, [r5, #-16]
 *   @0x2f053c ldr r0, [r5, #-28]
 *   @0x2f0540 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f0544 ldr r3, [r5, #-16]
 *   @0x2f0548 adds r3, #0x20
 *   @0x2f054a bic r3, r3, #0x3f
 *   @0x2f054e str r3, [r5, #-16]
 *   @0x2f0552 str r0, [r5, #-12]
 *   @0x2f0556 b 0x2f04fe <FT_Done_Memory+0x688a>
 *   @0x2f0558 add.w r8, r8, #0x1
 *   @0x2f055c cmp.w r8, #0x4
 *   @0x2f0560 bne 0x2f04d2 <FT_Done_Memory+0x685e>
 *   @0x2f0562 add.w r3, r4, #0x19c
 *   @0x2f0566 mov r8, r9
 *   @0x2f0568 cmp.w r8, #0x0
 *   @0x2f056c bne 0x2f0576 <FT_Done_Memory+0x6902>
 *   @0x2f056e mov r5, r3
 *   @0x2f0570 add.w r10, r3, #0x408
 *   @0x2f0574 b 0x2f057e <FT_Done_Memory+0x690a>
 *   @0x2f0576 add.w r5, r4, #0x3a0
 *   @0x2f057a add.w r10, r4, #0x7a8
 *   @0x2f057e ldr r9, [r5], #36
 *   @0x2f0582 cmp.w r9, #0x0
 *   @0x2f0586 beq 0x2f05dc <FT_Done_Memory+0x6968>
 *   @0x2f0588 ldr.w r11, [r10]
 *   @0x2f058c add.w r7, r10, #0x4
 *   @0x2f0590 cmp.w r11, #0x0
 *   @0x2f0594 beq 0x2f05d4 <FT_Done_Memory+0x6960>
 *   @0x2f0596 ldr r0, [r5, #-32]
 *   @0x2f059a mov r1, r6
 *   @0x2f059c ldr r2, [r7]
 *   @0x2f059e str r3, [sp, #0x4]
 *   @0x2f05a0 subs r0, r0, r2
 *   @0x2f05a2 cmp r0, #0x0
 *   @0x2f05a4 it lt
 *   @0x2f05a6 rsblt r0, r0, #0
 *   @0x2f05a8 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f05ac ldr r3, [sp, #0x4]
 *   @0x2f05ae cmp r0, #0x3f
 *   @0x2f05b0 bgt 0x2f05cc <FT_Done_Memory+0x6958>
 *   @0x2f05b2 ldr r2, [r7, #0x1c]
 *   @0x2f05b4 str r2, [r5, #-4]
 *   @0x2f05b8 ldr r2, [r7, #0x18]
 *   @0x2f05ba str r2, [r5, #-8]
 *   @0x2f05be ldr r2, [r7, #0x10]
 *   @0x2f05c0 str r2, [r5, #-16]
 *   @0x2f05c4 ldr r2, [r7, #0x14]
 *   @0x2f05c6 str r2, [r5, #-12]
 *   @0x2f05ca b 0x2f05d4 <FT_Done_Memory+0x6960>
 *   @0x2f05cc add.w r11, r11, #0xffffffff
 *   @0x2f05d0 adds r7, #0x20
 *   @0x2f05d2 b 0x2f0590 <FT_Done_Memory+0x691c>
 *   @0x2f05d4 add.w r9, r9, #0xffffffff
 *   @0x2f05d8 adds r5, #0x20
 *   @0x2f05da b 0x2f0582 <FT_Done_Memory+0x690e>
 *   @0x2f05dc add.w r8, r8, #0x1
 *   @0x2f05e0 cmp.w r8, #0x2
 *   @0x2f05e4 bne 0x2f0568 <FT_Done_Memory+0x68f4>
 *   @0x2f05e6 add sp, #0xc
 *   @0x2f05e8 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f05ec ldr r1, [pc, #0x2e4]
 *   @0x2f05ee lsls r4, r1, #0x8
 *   @0x2f05f0 adds r0, #0x64
 *   @0x2f05f2 bx lr
 *   @0x2f05f4 adds r0, #0x70
 *   @0x2f05f6 bx lr
 *   @0x2f05f8 adds r0, #0x8c
 *   @0x2f05fa bx lr
 *   @0x2f05fc ldr r3, [r0, #0xc]
 *   @0x2f05fe cbz r3, 0x2f060a <FT_Done_Memory+0x6996>
 *   @0x2f0600 ldr r2, [r0, #0x14]
 *   @0x2f0602 add.w r3, r2, r3, lsl #4
 *   @0x2f0606 str r1, [r3, #-4]
 *   @0x2f060a bx lr
 *   @0x2f060c movs r3, #0x0
 *   @0x2f060e movs r2, #0x1
 *   @0x2f0610 str r3, [r0, #0x4]
 *   @0x2f0612 str r2, [r0, #0xc]
 *   @0x2f0614 str r3, [r0, #0x10]
 *   @0x2f0616 str r3, [r0, #0x1c]
 *   @0x2f0618 str r3, [r0, #0x28]
 *   @0x2f061a str r3, [r0, #0x34]
 *   @0x2f061c str r3, [r0, #0x40]
 *   @0x2f061e str r3, [r0, #0x4c]
 *   @0x2f0620 bx lr
 *   @0x2f0622 movs r0, r0
 *   @0x2f0624 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2f0628 add.w r6, r0, #0xc
 *   @0x2f062c mov r4, r0
 *   @0x2f062e ldr r5, [r0, #0x8]
 *   @0x2f0630 movs r1, #0x0
 *   @0x2f0632 mov r0, r6
 *   @0x2f0634 movs r2, #0x58
 *   @0x2f0636 mov.w r8, #0x1c
 *   @0x2f063a blx 0xb65b0 <memset@plt>
 *   @0x2f063e ldr r3, [pc, #0x8c]
 *   @0x2f0640 str r5, [r4, #0xc]
 *   @0x2f0642 mov r2, r8
 *   @0x2f0644 add r3, pc
 *   @0x2f0646 str r3, [r4, #0x64]
 *   @0x2f0648 ldr r3, [pc, #0x84]
 *   @0x2f064a add.w r0, r4, #0x70
 *   @0x2f064e movs r1, #0x0
 *   @0x2f0650 ldr r7, [pc, #0x80]
 *   @0x2f0652 add r3, pc
 *   @0x2f0654 str r3, [r4, #0x68]
 *   @0x2f0656 ldr r3, [pc, #0x80]
 *   @0x2f0658 add r7, pc
 *   @0x2f065a ldr r5, [pc, #0x80]
 *   @0x2f065c add r3, pc
 *   @0x2f065e str r3, [r4, #0x6c]
 *   @0x2f0660 blx 0xb65b0 <memset@plt>
 *   @0x2f0664 ldr r3, [pc, #0x78]
 *   @0x2f0666 add r5, pc
 *   @0x2f0668 ldr r5, [r5]
 *   @0x2f066a str r7, [r4, #0x78]
 *   @0x2f066c add r3, pc
 *   @0x2f066e str r3, [r4, #0x74]
 *   @0x2f0670 ldr r3, [pc, #0x70]
 *   @0x2f0672 add.w r0, r4, #0x8c
 *   @0x2f0676 str.w r5, [r4, #0x88]
 *   @0x2f067a movs r1, #0x0
 *   @0x2f067c add r3, pc
 *   @0x2f067e str r3, [r4, #0x7c]
 *   @0x2f0680 ldr r3, [pc, #0x64]
 *   @0x2f0682 mov r2, r8
 *   @0x2f0684 str r6, [r4, #0x70]
 *   @0x2f0686 add r3, pc
 *   @0x2f0688 str.w r3, [r4, #0x80]
 *   @0x2f068c ldr r3, [pc, #0x5c]
 *   @0x2f068e add r3, pc
 *   @0x2f0690 str.w r3, [r4, #0x84]
 *   @0x2f0694 blx 0xb65b0 <memset@plt>
 *   @0x2f0698 ldr r3, [pc, #0x54]
 *   @0x2f069a str.w r7, [r4, #0x94]
 *   @0x2f069e movs r0, #0x0
 *   @0x2f06a0 add r3, pc
 *   @0x2f06a2 str.w r3, [r4, #0x90]
 *   @0x2f06a6 ldr r3, [pc, #0x4c]
 *   @0x2f06a8 str.w r5, [r4, #0xa4]
 *   @0x2f06ac add r3, pc
 *   @0x2f06ae str.w r3, [r4, #0x98]
 *   @0x2f06b2 ldr r3, [pc, #0x44]
 *   @0x2f06b4 str.w r6, [r4, #0x8c]
 *   @0x2f06b8 add r3, pc
 *   @0x2f06ba str.w r3, [r4, #0x9c]
 *   @0x2f06be ldr r3, [pc, #0x3c]
 *   @0x2f06c0 add r3, pc
 *   @0x2f06c2 str.w r3, [r4, #0xa0]
 *   @0x2f06c6 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2f06ca nop
 *   @0x2f06cc lsls r3, r7, #0x15
 *   @0x2f06ce movs r0, r0
 *   @0x2f06d0 stc2l p15, c15, [pc, #1020]!
 *   @0x2f06d4 asrs r3, r4, #0x1e
 *   @0x2f06d6 movs r0, r0
 *   @0x2f06d8 lsls r5, r4, #0xc
 *   @0x2f06da movs r0, r0
 *   @0x2f06dc asrs r2, r4, #0x15
 *   @0x2f06de movs r0, r2
 *   @0x2f06e0 .word 0xff9dffff
 *   @0x2f06e4 asrs r1, r7, #0x1e
 *   @0x2f06e6 movs r0, r0
 *   @0x2f06e8 lsrs r3, r0, #0x7
 *   @0x2f06ea movs r0, r0
 *   @0x2f06ec asrs r7, r2, #0x1f
 *   @0x2f06ee movs r0, r0
 *   @0x2f06f0 asrs r5, r0, #0x1d
 *   @0x2f06f2 movs r0, r0
 *   @0x2f06f4 lsrs r3, r4, #0x4
 *   @0x2f06f6 movs r0, r0
 *   @0x2f06f8 adds r1, r2, r3
 *   @0x2f06fa movs r0, r0
 *   @0x2f06fc adds r3, r0, r2
 *   @0x2f06fe movs r0, r0
 *   @0x2f0700 push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2f0704 mov r8, r2
 *   @0x2f0706 ldr r5, [r0]
 *   @0x2f0708 mov r4, r0
 *   @0x2f070a ldr r2, [r0, #0x4]
 *   @0x2f070c add.w r9, r5, #0x1
 *   @0x2f0710 cmp r9, r2
 *   @0x2f0712 bhi 0x2f0726 <FT_Done_Memory+0x6ab2>
 *   @0x2f0714 ldr r2, [r4, #0x8]
 *   @0x2f0716 lsls r5, r5, #0x4
 *   @0x2f0718 movs r0, #0x0
 *   @0x2f071a adds r3, r2, r5
 *   @0x2f071c str r0, [r2, r5]
 *   @0x2f071e str r0, [r3, #0xc]
 *   @0x2f0720 str.w r9, [r4]
 *   @0x2f0724 b 0x2f0754 <FT_Done_Memory+0x6ae0>
 *   @0x2f0726 ldr r3, [r0, #0x8]
 *   @0x2f0728 add.w r10, r5, #0x8
 *   @0x2f072c add r6, sp, #0x10
 *   @0x2f072e bic r10, r10, #0x7
 *   @0x2f0732 mov r0, r1
 *   @0x2f0734 movs r7, #0x0
 *   @0x2f0736 movs r1, #0x10
 *   @0x2f0738 str r7, [r6, #-4]!
 *   @0x2f073c stm.w sp, {r3, r6}
 *   @0x2f0740 mov r3, r10
 *   @0x2f0742 bl 0x2e808e <ft_mem_realloc>
 *   @0x2f0746 str r0, [r4, #0x8]
 *   @0x2f0748 ldr r0, [sp, #0xc]
 *   @0x2f074a cbnz r0, 0x2f0752 <FT_Done_Memory+0x6ade>
 *   @0x2f074c str.w r10, [r4, #0x4]
 *   @0x2f0750 b 0x2f0714 <FT_Done_Memory+0x6aa0>
 *   @0x2f0752 mov r3, r7
 *   @0x2f0754 str.w r3, [r8]
 *   @0x2f0758 add sp, #0x10
 *   @0x2f075a pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2f075e push {r4, r5, lr}
 *   @0x2f0760 mov r4, r0
 *   @0x2f0762 ldr r3, [r4, #0x4]
 *   @0x2f0764 mov r0, r2
 *   @0x2f0766 adds r1, #0x7
 *   @0x2f0768 sub sp, #0x14
 *   @0x2f076a adds r2, r3, #0x7
 *   @0x2f076c movs r3, #0x0
 *   @0x2f076e lsrs r5, r1, #0x3
 *   @0x2f0770 str r3, [sp, #0xc]
 *   @0x2f0772 lsrs r2, r2, #0x3
 *   @0x2f0774 cmp r5, r2
 *   @0x2f0776 bls 0x2f0798 <FT_Done_Memory+0x6b24>
 *   @0x2f0778 ldr r3, [r4, #0x8]
 *   @0x2f077a adds r5, #0x7
 *   @0x2f077c bic r5, r5, #0x7
 *   @0x2f0780 movs r1, #0x1
 *   @0x2f0782 str r3, [sp]
 *   @0x2f0784 add r3, sp, #0xc
 *   @0x2f0786 str r3, [sp, #0x4]
 *   @0x2f0788 mov r3, r5
 *   @0x2f078a bl 0x2e808e <ft_mem_realloc>
 *   @0x2f078e ldr r3, [sp, #0xc]
 *   @0x2f0790 str r0, [r4, #0x8]
 *   @0x2f0792 cbnz r3, 0x2f0798 <FT_Done_Memory+0x6b24>
 *   @0x2f0794 lsls r5, r5, #0x3
 *   @0x2f0796 str r5, [r4, #0x4]
 *   @0x2f0798 ldr r0, [sp, #0xc]
 *   @0x2f079a add sp, #0x14
 *   @0x2f079c pop {r4, r5, pc}
 *   @0x2f079e push {r4, r5, r6, lr}
 *   @0x2f07a0 mov r5, r0
 *   @0x2f07a2 ldr r3, [r0]
 *   @0x2f07a4 mov r4, r1
 *   @0x2f07a6 cmp r1, r3
 *   @0x2f07a8 blo 0x2f07b6 <FT_Done_Memory+0x6b42>
 *   @0x2f07aa adds r6, r1, #0x1
 *   @0x2f07ac mov r1, r6
 *   @0x2f07ae bl 0x2f075e <FT_Done_Memory+0x6aea>
 *   @0x2f07b2 cbnz r0, 0x2f07cc <FT_Done_Memory+0x6b58>
 *   @0x2f07b4 str r6, [r5]
 *   @0x2f07b6 ldr r2, [r5, #0x8]
 *   @0x2f07b8 lsrs r3, r4, #0x3
 *   @0x2f07ba movs r1, #0x80
 *   @0x2f07bc and r4, r4, #0x7
 *   @0x2f07c0 asr.w r4, r1, r4
 *   @0x2f07c4 movs r0, #0x0
 *   @0x2f07c6 ldrb r1, [r2, r3]
 *   @0x2f07c8 orrs r4, r1
 *   @0x2f07ca strb r4, [r2, r3]
 *   @0x2f07cc pop {r4, r5, r6, pc}
 *   @0x2f07ce push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2f07d2 subs r6, r2, #0x0
 *   @0x2f07d4 sub sp, #0x1c
 *   @0x2f07d6 mov r4, r0
 *   @0x2f07d8 mov r8, r1
 *   @0x2f07da mov r9, r3
 *   @0x2f07dc ldr r7, [sp, #0x40]
 *   @0x2f07de bge 0x2f07ee <FT_Done_Memory+0x6b7a>
 *   @0x2f07e0 adds r6, #0x15
 *   @0x2f07e2 bne 0x2f07f4 <FT_Done_Memory+0x6b80>
 *   @0x2f07e4 sub.w r8, r1, #0x15
 *   @0x2f07e8 mov.w r10, #0x3
 *   @0x2f07ec b 0x2f07f8 <FT_Done_Memory+0x6b84>
 *   @0x2f07ee mov.w r10, #0x0
 *   @0x2f07f2 b 0x2f07fa <FT_Done_Memory+0x6b86>
 *   @0x2f07f4 mov.w r10, #0x1
 *   @0x2f07f8 movs r6, #0x0
 *   @0x2f07fa cbz r7, 0x2f0802 <FT_Done_Memory+0x6b8e>
 *   @0x2f07fc mov.w r3, #0xffffffff
 *   @0x2f0800 str r3, [r7]
 *   @0x2f0802 ldr r1, [r4, #0x8]
 *   @0x2f0804 movs r5, #0x0
 *   @0x2f0806 ldr r3, [r4]
 *   @0x2f0808 add.w r2, r1, #0xc
 *   @0x2f080c cmp r5, r3
 *   @0x2f080e beq 0x2f082a <FT_Done_Memory+0x6bb6>
 *   @0x2f0810 ldr r0, [r2, #-12]
 *   @0x2f0814 cmp r0, r8
 *   @0x2f0816 bne 0x2f0820 <FT_Done_Memory+0x6bac>
 *   @0x2f0818 ldr r0, [r2, #-8]
 *   @0x2f081c cmp r0, r6
 *   @0x2f081e beq 0x2f0826 <FT_Done_Memory+0x6bb2>
 *   @0x2f0820 adds r5, #0x1
 *   @0x2f0822 adds r2, #0xc
 *   @0x2f0824 b 0x2f080c <FT_Done_Memory+0x6b98>
 *   @0x2f0826 cmp r5, r3
 *   @0x2f0828 blo 0x2f088a <FT_Done_Memory+0x6c16>
 *   @0x2f082a ldr r2, [r4, #0x4]
 *   @0x2f082c add.w r11, r3, #0x1
 *   @0x2f0830 cmp r11, r2
 *   @0x2f0832 blo 0x2f0842 <FT_Done_Memory+0x6bce>
 *   @0x2f0834 mov.w r0, #0x0
 *   @0x2f0838 str r0, [sp, #0x14]
 *   @0x2f083a bhi 0x2f085e <FT_Done_Memory+0x6bea>
 *   @0x2f083c ldr r0, [sp, #0x14]
 *   @0x2f083e cmp r0, #0x0
 *   @0x2f0840 bne 0x2f08c0 <FT_Done_Memory+0x6c4c>
 *   @0x2f0842 movs r2, #0xc
 *   @0x2f0844 ldr r1, [r4, #0x8]
 *   @0x2f0846 mul r2, r2, r11
 *   @0x2f084a str.w r11, [r4]
 *   @0x2f084e subs r2, #0xc
 *   @0x2f0850 adds r3, r1, r2
 *   @0x2f0852 str.w r8, [r1, r2]
 *   @0x2f0856 str r6, [r3, #0x4]
 *   @0x2f0858 str.w r10, [r3, #0x8]
 *   @0x2f085c b 0x2f088a <FT_Done_Memory+0x6c16>
 *   @0x2f085e adds r3, #0x8
 *   @0x2f0860 str r1, [sp]
 *   @0x2f0862 bic r12, r3, #0x7
 *   @0x2f0866 mov r0, r9
 *   @0x2f0868 add r3, sp, #0x14
 *   @0x2f086a movs r1, #0xc
 *   @0x2f086c str r3, [sp, #0x4]
 *   @0x2f086e mov r3, r12
 *   @0x2f0870 str.w r12, [sp, #0xc]
 *   @0x2f0874 bl 0x2e808e <ft_mem_realloc>
 *   @0x2f0878 ldr r3, [sp, #0x14]
 *   @0x2f087a ldr.w r12, [sp, #0xc]
 *   @0x2f087e str r0, [r4, #0x8]
 *   @0x2f0880 cmp r3, #0x0
 *   @0x2f0882 bne 0x2f083c <FT_Done_Memory+0x6bc8>
 *   @0x2f0884 str.w r12, [r4, #0x4]
 *   @0x2f0888 b 0x2f083c <FT_Done_Memory+0x6bc8>
 *   @0x2f088a ldr r3, [r4, #0xc]
 *   @0x2f088c cbnz r3, 0x2f089c <FT_Done_Memory+0x6c28>
 *   @0x2f088e add.w r0, r4, #0xc
 *   @0x2f0892 mov r1, r9
 *   @0x2f0894 add r2, sp, #0x14
 *   @0x2f0896 bl 0x2f0700 <FT_Done_Memory+0x6a8c>
 *   @0x2f089a b 0x2f08ac <FT_Done_Memory+0x6c38>
 *   @0x2f089c add.w r3, r3, #0x10000000
 *   @0x2f08a0 ldr r2, [r4, #0x14]
 *   @0x2f08a2 subs r3, #0x1
 *   @0x2f08a4 movs r0, #0x0
 *   @0x2f08a6 add.w r3, r2, r3, lsl #4
 *   @0x2f08aa str r3, [sp, #0x14]
 *   @0x2f08ac ldr r3, [sp, #0x14]
 *   @0x2f08ae cbnz r0, 0x2f08c0 <FT_Done_Memory+0x6c4c>
 *   @0x2f08b0 mov r0, r3
 *   @0x2f08b2 mov r1, r5
 *   @0x2f08b4 mov r2, r9
 *   @0x2f08b6 bl 0x2f079e <FT_Done_Memory+0x6b2a>
 *   @0x2f08ba cbnz r0, 0x2f08c0 <FT_Done_Memory+0x6c4c>
 *   @0x2f08bc cbz r7, 0x2f08c0 <FT_Done_Memory+0x6c4c>
 *   @0x2f08be str r5, [r7]
 *   @0x2f08c0 add sp, #0x1c
 *   @0x2f08c2 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
/* ═══════════════════════════════════════════════════════════════════════
 * §12  anon_thumb_2f9ab6   0x2f9ab6..0x2f9f0e   1,112 B / 424 条   in-degree 2
 * TrueType 字节码解释器带（1,112 B / 4 个 bl 入口 / 424 条）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 2 条 Thumb `bl` 指向本段起始：TT_RunIns×2；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 11 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r4, r5, r6, r7, r8, r9, r10, lr} / mov r4, r0 / ldr.w r3, [r0, #0x254]（帧：push {r4, r5, r6, r7, r8, r9, r10, lr}）；窗口内出口 13 个
 * 结构：入口可达 218 B / 81 条（19%）；段内 bl 入口 3 个：0x2f9bb2(178 B/57 条) / 0x2f9c64(264 B/85 条) / 0x2f9d6c(52 B/21 条)
 *      可打印岛：无 ≥16 B 的
 *      未达字节：366 B（各入口可达集的补集；多为只经指针/表进入的邻接函数与池字，本卡不判其身份）
 * 入口 218 B / 81 条，被 TT_RunIns bl 2 次；11 处 bl 打向 FT_DivFix / FT_MulDiv / FT_Select_Metrics /
 *      FT_Request_Metrics。段内 3 个 bl 入口：0x2f9bb2(178 B) / 0x2f9c64(264 B) / 0x2f9d6c(52 B)。
 *
 * 锚点：424 条（= asm/index-anonT_2f9ab6.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2f9ab6 push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2f9aba mov r4, r0
 *   @0x2f9abc ldr.w r3, [r0, #0x254]
 *   @0x2f9ac0 mov r5, r1
 *   @0x2f9ac2 blx r3
 *   @0x2f9ac4 ldr r7, [r5]
 *   @0x2f9ac6 add.w r6, r4, #0x24
 *   @0x2f9aca mov.w r10, #0x1
 *   @0x2f9ace mov.w r9, #0x86
 *   @0x2f9ad2 mov r8, r0
 *   @0x2f9ad4 cmp r10, r7
 *   @0x2f9ad6 bhi 0x2f9b88 <ps_hints_apply+0x8788>
 *   @0x2f9ad8 ldr r3, [r4, #0x1c]
 *   @0x2f9ada cmp r3, #0x1
 *   @0x2f9adc bgt 0x2f9aee <ps_hints_apply+0x86ee>
 *   @0x2f9ade ldrb.w r3, [r4, #0x235]
 *   @0x2f9ae2 cbz r3, 0x2f9ae8 <ps_hints_apply+0x86e8>
 *   @0x2f9ae4 movs r3, #0x81
 *   @0x2f9ae6 str r3, [r4, #0xc]
 *   @0x2f9ae8 movs r3, #0x0
 *   @0x2f9aea str r3, [r4, #0x1c]
 *   @0x2f9aec b 0x2f9b88 <ps_hints_apply+0x8788>
 *   @0x2f9aee ldr r1, [r4, #0x18]
 *   @0x2f9af0 subs r2, r3, #0x2
 *   @0x2f9af2 subs r3, #0x1
 *   @0x2f9af4 str r2, [r4, #0x1c]
 *   @0x2f9af6 ldrh.w r2, [r1, r3, lsl #2]
 *   @0x2f9afa add.w r3, r1, r3, lsl #2
 *   @0x2f9afe ldrh r1, [r4, #0x2c]
 *   @0x2f9b00 ldr r3, [r3, #-4]
 *   @0x2f9b04 cmp r1, r2
 *   @0x2f9b06 bls 0x2f9b78 <ps_hints_apply+0x8778>
 *   @0x2f9b08 ldrb.w r1, [r4, #0x174]
 *   @0x2f9b0c ubfx r5, r3, #0x4, #0x4
 *   @0x2f9b10 cmp r1, #0x71
 *   @0x2f9b12 beq 0x2f9b1c <ps_hints_apply+0x871c>
 *   @0x2f9b14 cmp r1, #0x72
 *   @0x2f9b16 bne 0x2f9b1e <ps_hints_apply+0x871e>
 *   @0x2f9b18 adds r5, #0x20
 *   @0x2f9b1a b 0x2f9b1e <ps_hints_apply+0x871e>
 *   @0x2f9b1c adds r5, #0x10
 *   @0x2f9b1e ldrh.w r1, [r4, #0x150]
 *   @0x2f9b22 add r5, r1
 *   @0x2f9b24 cmp r8, r5
 *   @0x2f9b26 bne 0x2f9b82 <ps_hints_apply+0x8782>
 *   @0x2f9b28 and r3, r3, #0xf
 *   @0x2f9b2c ldrh.w r1, [r4, #0x152]
 *   @0x2f9b30 subs r3, #0x8
 *   @0x2f9b32 it pl
 *   @0x2f9b34 addpl r3, #0x1
 *   @0x2f9b36 rsb.w r1, r1, #0x6
 *   @0x2f9b3a lsls r3, r1
 *   @0x2f9b3c ldr r1, [r4]
 *   @0x2f9b3e ldr r1, [r1, #0x60]
 *   @0x2f9b40 ldr r1, [r1, #0x40]
 *   @0x2f9b42 cmp r1, #0x28
 *   @0x2f9b44 bne 0x2f9b6c <ps_hints_apply+0x876c>
 *   @0x2f9b46 ldrb.w r1, [r4, #0x267]
 *   @0x2f9b4a cbz r1, 0x2f9b6c <ps_hints_apply+0x876c>
 *   @0x2f9b4c ldrb.w r1, [r4, #0x268]
 *   @0x2f9b50 cbz r1, 0x2f9b58 <ps_hints_apply+0x8758>
 *   @0x2f9b52 ldrb.w r1, [r4, #0x269]
 *   @0x2f9b56 cbnz r1, 0x2f9b82 <ps_hints_apply+0x8782>
 *   @0x2f9b58 ldrb.w r1, [r4, #0x234]
 *   @0x2f9b5c cbz r1, 0x2f9b64 <ps_hints_apply+0x8764>
 *   @0x2f9b5e ldrsh.w r1, [r4, #0x130]
 *   @0x2f9b62 cbnz r1, 0x2f9b6c <ps_hints_apply+0x876c>
 *   @0x2f9b64 ldr r1, [r4, #0x3c]
 *   @0x2f9b66 ldrb r1, [r1, r2]
 *   @0x2f9b68 lsls r1, r1, #0x1b
 *   @0x2f9b6a bpl 0x2f9b82 <ps_hints_apply+0x8782>
 *   @0x2f9b6c ldr.w r5, [r4, #0x24c]
 *   @0x2f9b70 mov r0, r4
 *   @0x2f9b72 mov r1, r6
 *   @0x2f9b74 blx r5
 *   @0x2f9b76 b 0x2f9b82 <ps_hints_apply+0x8782>
 *   @0x2f9b78 ldrb.w r3, [r4, #0x235]
 *   @0x2f9b7c cbz r3, 0x2f9b82 <ps_hints_apply+0x8782>
 *   @0x2f9b7e str.w r9, [r4, #0xc]
 *   @0x2f9b82 add.w r10, r10, #0x1
 *   @0x2f9b86 b 0x2f9ad4 <ps_hints_apply+0x86d4>
 *   @0x2f9b88 ldr r3, [r4, #0x1c]
 *   @0x2f9b8a str r3, [r4, #0x20]
 *   @0x2f9b8c pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2f9b90 mov r3, r0
 *   @0x2f9b92 mov.w r2, #0xffffffff
 *   @0x2f9b96 str.w r2, [r0, #0x130]
 *   @0x2f9b9a str.w r2, [r0, #0x134]
 *   @0x2f9b9e movs r0, #0x0
 *   @0x2f9ba0 str r2, [r3, #0x74]
 *   @0x2f9ba2 strb.w r0, [r3, #0x70]
 *   @0x2f9ba6 bx lr
 *   @0x2f9ba8 movs r3, #0x28
 *   @0x2f9baa str r3, [r0, #0x40]
 *   @0x2f9bac movs r0, #0x0
 *   @0x2f9bae bx lr
 *   @0x2f9bb0 bx lr
 *   @0x2f9bb2 push {r4, r5, r6, r7, lr}
 *   @0x2f9bb4 ldr.w r6, [r0, #0x2d4]
 *   @0x2f9bb8 cmp r1, r6
 *   @0x2f9bba bhs 0x2f9c2e <ps_hints_apply+0x882e>
 *   @0x2f9bbc ldrsh.w r3, [r0, #0xd2]
 *   @0x2f9bc0 ldr.w r4, [r0, #0x2d8]
 *   @0x2f9bc4 cbz r3, 0x2f9c02 <ps_hints_apply+0x8802>
 *   @0x2f9bc6 add.w r5, r4, r1, lsl #2
 *   @0x2f9bca ldrb.w r7, [r4, r1, lsl #2]
 *   @0x2f9bce add.w r4, r4, r6, lsl #2
 *   @0x2f9bd2 ldrb r3, [r5, #0x1]
 *   @0x2f9bd4 lsls r3, r3, #0x10
 *   @0x2f9bd6 orr.w r3, r3, r7, lsl #24
 *   @0x2f9bda ldrb r7, [r5, #0x3]
 *   @0x2f9bdc orrs r3, r7
 *   @0x2f9bde ldrb r7, [r5, #0x2]
 *   @0x2f9be0 orr.w r3, r3, r7, lsl #8
 *   @0x2f9be4 add.w r7, r5, #0x8
 *   @0x2f9be8 cmp r7, r4
 *   @0x2f9bea bhi 0x2f9c34 <ps_hints_apply+0x8834>
 *   @0x2f9bec ldrb r4, [r5, #0x5]
 *   @0x2f9bee ldrb r7, [r5, #0x4]
 *   @0x2f9bf0 lsls r4, r4, #0x10
 *   @0x2f9bf2 orr.w r4, r4, r7, lsl #24
 *   @0x2f9bf6 ldrb r7, [r5, #0x7]
 *   @0x2f9bf8 ldrb r5, [r5, #0x6]
 *   @0x2f9bfa orrs r4, r7
 *   @0x2f9bfc orr.w r4, r4, r5, lsl #8
 *   @0x2f9c00 b 0x2f9c36 <ps_hints_apply+0x8836>
 *   @0x2f9c02 add.w r5, r4, r1, lsl #1
 *   @0x2f9c06 ldrb.w r7, [r4, r1, lsl #1]
 *   @0x2f9c0a add.w r4, r4, r6, lsl #1
 *   @0x2f9c0e ldrb r3, [r5, #0x1]
 *   @0x2f9c10 orr.w r3, r3, r7, lsl #8
 *   @0x2f9c14 adds r7, r5, #0x4
 *   @0x2f9c16 cmp r7, r4
 *   @0x2f9c18 itet ls
 *   @0x2f9c1a ldrbls r7, [r5, #0x2]
 *   @0x2f9c1c movhi r4, r3
 *   @0x2f9c1e ldrbls r4, [r5, #0x3]
 *   @0x2f9c20 lsl.w r3, r3, #0x1
 *   @0x2f9c24 it ls
 *   @0x2f9c26 orrls.w r4, r4, r7, lsl #8
 *   @0x2f9c2a lsls r4, r4, #0x1
 *   @0x2f9c2c b 0x2f9c36 <ps_hints_apply+0x8836>
 *   @0x2f9c2e movs r4, #0x0
 *   @0x2f9c30 mov r3, r4
 *   @0x2f9c32 b 0x2f9c36 <ps_hints_apply+0x8836>
 *   @0x2f9c34 mov r4, r3
 *   @0x2f9c36 ldr.w r0, [r0, #0x2ac]
 *   @0x2f9c3a cmp r3, r0
 *   @0x2f9c3c bls 0x2f9c44 <ps_hints_apply+0x8844>
 *   @0x2f9c3e movs r3, #0x0
 *   @0x2f9c40 str r3, [r2]
 *   @0x2f9c42 b 0x2f9c60 <ps_hints_apply+0x8860>
 *   @0x2f9c44 cmp r4, r0
 *   @0x2f9c46 bls 0x2f9c52 <ps_hints_apply+0x8852>
 *   @0x2f9c48 subs r6, #0x1
 *   @0x2f9c4a cmp r1, r6
 *   @0x2f9c4c bne 0x2f9c3e <ps_hints_apply+0x883e>
 *   @0x2f9c4e mov r4, r0
 *   @0x2f9c50 b 0x2f9c56 <ps_hints_apply+0x8856>
 *   @0x2f9c52 cmp r4, r3
 *   @0x2f9c54 blo 0x2f9c5c <ps_hints_apply+0x885c>
 *   @0x2f9c56 subs r4, r4, r3
 *   @0x2f9c58 str r4, [r2]
 *   @0x2f9c5a b 0x2f9c60 <ps_hints_apply+0x8860>
 *   @0x2f9c5c subs r0, r0, r3
 *   @0x2f9c5e str r0, [r2]
 *   @0x2f9c60 mov r0, r3
 *   @0x2f9c62 pop {r4, r5, r6, r7, pc}
 *   @0x2f9c64 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2f9c68 mov r4, r0
 *   @0x2f9c6a ldr r5, [r0]
 *   @0x2f9c6c mov r8, r1
 *   @0x2f9c6e ldrb.w r3, [r5, #0x2b4]
 *   @0x2f9c72 cmp r3, #0x0
 *   @0x2f9c74 bne 0x2f9d60 <ps_hints_apply+0x8960>
 *   @0x2f9c76 add.w r7, r0, #0xc
 *   @0x2f9c7a strb.w r3, [r0, #0x70]
 *   @0x2f9c7e add.w r6, r0, #0x30
 *   @0x2f9c82 ldm r7!, {r0, r1, r2, r3}
 *   @0x2f9c84 stm r6!, {r0, r1, r2, r3}
 *   @0x2f9c86 ldm.w r7, {r0, r1, r2}
 *   @0x2f9c8a stm.w r6, {r0, r1, r2}
 *   @0x2f9c8e mov r6, r4
 *   @0x2f9c90 ldrh r3, [r6, #48]!
 *   @0x2f9c94 cmp r3, #0x0
 *   @0x2f9c96 beq 0x2f9d66 <ps_hints_apply+0x8966>
 *   @0x2f9c98 ldrh r3, [r4, #0x32]
 *   @0x2f9c9a cmp r3, #0x0
 *   @0x2f9c9c beq 0x2f9d66 <ps_hints_apply+0x8966>
 *   @0x2f9c9e ldrh.w r3, [r5, #0xb0]
 *   @0x2f9ca2 lsls r2, r3, #0x1c
 *   @0x2f9ca4 bpl 0x2f9cdc <ps_hints_apply+0x88dc>
 *   @0x2f9ca6 ldr r1, [r4, #0x38]
 *   @0x2f9ca8 ldrsh.w r0, [r5, #0x46]
 *   @0x2f9cac bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2f9cb0 ldr r1, [r4, #0x38]
 *   @0x2f9cb2 adds r0, #0x20
 *   @0x2f9cb4 bic r0, r0, #0x3f
 *   @0x2f9cb8 str r0, [r4, #0x3c]
 *   @0x2f9cba ldrsh.w r0, [r5, #0x48]
 *   @0x2f9cbe bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2f9cc2 ldr r1, [r4, #0x38]
 *   @0x2f9cc4 adds r0, #0x20
 *   @0x2f9cc6 bic r0, r0, #0x3f
 *   @0x2f9cca str r0, [r4, #0x40]
 *   @0x2f9ccc ldrsh.w r0, [r5, #0x4a]
 *   @0x2f9cd0 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2f9cd4 adds r0, #0x20
 *   @0x2f9cd6 bic r0, r0, #0x3f
 *   @0x2f9cda str r0, [r4, #0x44]
 *   @0x2f9cdc movs r3, #0x1
 *   @0x2f9cde strb.w r3, [r4, #0x70]
 *   @0x2f9ce2 cmp.w r8, #0x0
 *   @0x2f9ce6 bne 0x2f9d60 <ps_hints_apply+0x8960>
 *   @0x2f9ce8 ldrh.w r3, [r5, #0xb0]
 *   @0x2f9cec lsls r3, r3, #0x1c
 *   @0x2f9cee bpl 0x2f9d1e <ps_hints_apply+0x891e>
 *   @0x2f9cf0 ldrh r0, [r4, #0x30]
 *   @0x2f9cf2 ldrh.w r1, [r5, #0x44]
 *   @0x2f9cf6 lsls r0, r0, #0x6
 *   @0x2f9cf8 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2f9cfc str r0, [r4, #0x34]
 *   @0x2f9cfe ldrh r0, [r4, #0x32]
 *   @0x2f9d00 ldrh.w r1, [r5, #0x44]
 *   @0x2f9d04 lsls r0, r0, #0x6
 *   @0x2f9d06 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2f9d0a ldr r1, [r4, #0x34]
 *   @0x2f9d0c str r0, [r4, #0x38]
 *   @0x2f9d0e ldrsh.w r0, [r5, #0x4c]
 *   @0x2f9d12 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2f9d16 adds r0, #0x20
 *   @0x2f9d18 bic r0, r0, #0x3f
 *   @0x2f9d1c str r0, [r4, #0x48]
 *   @0x2f9d1e ldrh r1, [r4, #0x30]
 *   @0x2f9d20 ldrh r3, [r4, #0x32]
 *   @0x2f9d22 cmp r1, r3
 *   @0x2f9d24 blo 0x2f9d3e <ps_hints_apply+0x893e>
 *   @0x2f9d26 ldr r2, [r4, #0x34]
 *   @0x2f9d28 mov r0, r3
 *   @0x2f9d2a strh.w r1, [r4, #0x54]
 *   @0x2f9d2e str r2, [r4, #0x5c]
 *   @0x2f9d30 mov.w r2, #0x10000
 *   @0x2f9d34 str r2, [r4, #0x4c]
 *   @0x2f9d36 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2f9d3a str r0, [r4, #0x50]
 *   @0x2f9d3c b 0x2f9d56 <ps_hints_apply+0x8956>
 *   @0x2f9d3e ldr r2, [r4, #0x38]
 *   @0x2f9d40 mov r0, r1
 *   @0x2f9d42 strh.w r3, [r4, #0x54]
 *   @0x2f9d46 mov r1, r3
 *   @0x2f9d48 str r2, [r4, #0x5c]
 *   @0x2f9d4a bl 0x2e4eb6 <FT_DivFix>
 *   @0x2f9d4e mov.w r3, #0x10000
 *   @0x2f9d52 str r3, [r4, #0x50]
 *   @0x2f9d54 str r0, [r4, #0x4c]
 *   @0x2f9d56 mov.w r3, #0xffffffff
 *   @0x2f9d5a str r6, [r4, #0x2c]
 *   @0x2f9d5c str.w r3, [r4, #0x134]
 *   @0x2f9d60 movs r0, #0x0
 *   @0x2f9d62 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2f9d66 movs r0, #0x97
 *   @0x2f9d68 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2f9d6c push {r4, lr}
 *   @0x2f9d6e mov r4, r0
 *   @0x2f9d70 ldr r0, [r0]
 *   @0x2f9d72 str r1, [r4, #0x74]
 *   @0x2f9d74 ldr r3, [r0, #0x8]
 *   @0x2f9d76 lsls r3, r3, #0x1f
 *   @0x2f9d78 bpl 0x2f9d8a <ps_hints_apply+0x898a>
 *   @0x2f9d7a bl 0x2e5524 <FT_Select_Metrics>
 *   @0x2f9d7e mov r0, r4
 *   @0x2f9d80 movs r1, #0x0
 *   @0x2f9d82 bl 0x2f9c64 <ps_hints_apply+0x8864>
 *   @0x2f9d86 movs r0, #0x0
 *   @0x2f9d88 pop {r4, pc}
 *   @0x2f9d8a ldr.w r3, [r0, #0x21c]
 *   @0x2f9d8e add.w r2, r4, #0xc
 *   @0x2f9d92 ldr r3, [r3, #0x6c]
 *   @0x2f9d94 blx r3
 *   @0x2f9d96 cbz r0, 0x2f9d9e <ps_hints_apply+0x899e>
 *   @0x2f9d98 mov.w r3, #0xffffffff
 *   @0x2f9d9c str r3, [r4, #0x74]
 *   @0x2f9d9e pop {r4, pc}
 *   @0x2f9da0 push {r3, lr}
 *   @0x2f9da2 movs r1, #0x1
 *   @0x2f9da4 ldr r0, [r0, #0x8]
 *   @0x2f9da6 bl 0x2f9c64 <ps_hints_apply+0x8864>
 *   @0x2f9daa movs r0, #0x0
 *   @0x2f9dac pop {r3, pc}
 *   @0x2f9dae push {r0, r1, r4, r5, r6, lr}
 *   @0x2f9db0 mov r4, r0
 *   @0x2f9db2 ldr r0, [r0]
 *   @0x2f9db4 mov r5, r1
 *   @0x2f9db6 ldr r6, [r0, #0x8]
 *   @0x2f9db8 ands r6, r6, #0x2
 *   @0x2f9dbc beq 0x2f9dde <ps_hints_apply+0x89de>
 *   @0x2f9dbe ldr.w r3, [r0, #0x21c]
 *   @0x2f9dc2 add r2, sp, #0x4
 *   @0x2f9dc4 ldr r3, [r3, #0x68]
 *   @0x2f9dc6 blx r3
 *   @0x2f9dc8 mov r6, r0
 *   @0x2f9dca cbz r0, 0x2f9dd4 <ps_hints_apply+0x89d4>
 *   @0x2f9dcc mov.w r3, #0xffffffff
 *   @0x2f9dd0 str r3, [r4, #0x74]
 *   @0x2f9dd2 b 0x2f9dde <ps_hints_apply+0x89de>
 *   @0x2f9dd4 mov r0, r4
 *   @0x2f9dd6 ldr r1, [sp, #0x4]
 *   @0x2f9dd8 bl 0x2f9d6c <ps_hints_apply+0x896c>
 *   @0x2f9ddc b 0x2f9e2c <ps_hints_apply+0x8a2c>
 *   @0x2f9dde ldr r0, [r4]
 *   @0x2f9de0 mov r1, r5
 *   @0x2f9de2 bl 0x2e5588 <FT_Request_Metrics>
 *   @0x2f9de6 ldr r3, [r4]
 *   @0x2f9de8 ldr r3, [r3, #0x8]
 *   @0x2f9dea lsls r3, r3, #0x1f
 *   @0x2f9dec bpl 0x2f9e2a <ps_hints_apply+0x8a2a>
 *   @0x2f9dee mov r0, r4
 *   @0x2f9df0 movs r1, #0x0
 *   @0x2f9df2 bl 0x2f9c64 <ps_hints_apply+0x8864>
 *   @0x2f9df6 cbnz r0, 0x2f9e2c <ps_hints_apply+0x8a2c>
 *   @0x2f9df8 ldr r3, [r4, #0x2c]
 *   @0x2f9dfa ldr r1, [r5, #0xc]
 *   @0x2f9dfc ldr r2, [r5, #0x10]
 *   @0x2f9dfe ldrh r0, [r3]
 *   @0x2f9e00 ldrh r3, [r3, #0x2]
 *   @0x2f9e02 cmp r0, r3
 *   @0x2f9e04 it hi
 *   @0x2f9e06 movhi r2, r1
 *   @0x2f9e08 ldr r3, [r5]
 *   @0x2f9e0a cmp r3, #0x4
 *   @0x2f9e0c beq 0x2f9e16 <ps_hints_apply+0x8a16>
 *   @0x2f9e0e cmp r2, #0x0
 *   @0x2f9e10 it eq
 *   @0x2f9e12 moveq r2, #0x48
 *   @0x2f9e14 b 0x2f9e18 <ps_hints_apply+0x8a18>
 *   @0x2f9e16 movs r2, #0x48
 *   @0x2f9e18 ldrh.w r0, [r4, #0x54]
 *   @0x2f9e1c mov.w r1, #0x1200
 *   @0x2f9e20 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2f9e24 str r0, [r4, #0x78]
 *   @0x2f9e26 movs r0, #0x0
 *   @0x2f9e28 b 0x2f9e2c <ps_hints_apply+0x8a2c>
 *   @0x2f9e2a mov r0, r6
 *   @0x2f9e2c add sp, #0x8
 *   @0x2f9e2e pop {r4, r5, r6, pc}
 *   @0x2f9e30 push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2f9e34 mov r6, r1
 *   @0x2f9e36 ldrsh.w r1, [r0, #0x12e]
 *   @0x2f9e3a mov r4, r0
 *   @0x2f9e3c mov r5, r2
 *   @0x2f9e3e mov r7, r3
 *   @0x2f9e40 cbz r1, 0x2f9e5a <ps_hints_apply+0x8a5a>
 *   @0x2f9e42 ldr.w r8, [r6, #0xc]
 *   @0x2f9e46 mov r0, r3
 *   @0x2f9e48 ldr.w r9, [r8, r2, lsl #3]
 *   @0x2f9e4c ldr.w r2, [r4, #0x238]
 *   @0x2f9e50 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2f9e54 add r0, r9
 *   @0x2f9e56 str.w r0, [r8, r5, lsl #3]
 *   @0x2f9e5a ldrsh.w r1, [r4, #0x130]
 *   @0x2f9e5e cbz r1, 0x2f9e76 <ps_hints_apply+0x8a76>
 *   @0x2f9e60 ldr r3, [r6, #0xc]
 *   @0x2f9e62 mov r0, r7
 *   @0x2f9e64 ldr.w r2, [r4, #0x238]
 *   @0x2f9e68 add.w r5, r3, r5, lsl #3
 *   @0x2f9e6c ldr r6, [r5, #0x4]
 *   @0x2f9e6e bl 0x2e4d3c <FT_MulDiv>
 *   @0x2f9e72 add r0, r6
 *   @0x2f9e74 str r0, [r5, #0x4]
 *   @0x2f9e76 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2f9e7a push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2f9e7e mov r6, r1
 *   @0x2f9e80 ldrsh.w r1, [r0, #0x12e]
 *   @0x2f9e84 mov r4, r0
 *   @0x2f9e86 mov r5, r2
 *   @0x2f9e88 mov r7, r3
 *   @0x2f9e8a cbz r1, 0x2f9ec4 <ps_hints_apply+0x8ac4>
 *   @0x2f9e8c ldr r3, [r0]
 *   @0x2f9e8e ldr r3, [r3, #0x60]
 *   @0x2f9e90 ldr r3, [r3, #0x40]
 *   @0x2f9e92 cmp r3, #0x28
 *   @0x2f9e94 bne 0x2f9e9e <ps_hints_apply+0x8a9e>
 *   @0x2f9e96 ldrb.w r3, [r0, #0x267]
 *   @0x2f9e9a cbnz r3, 0x2f9eba <ps_hints_apply+0x8aba>
 *   @0x2f9e9c b 0x2f9ea2 <ps_hints_apply+0x8aa2>
 *   @0x2f9e9e cmp r3, #0x23
 *   @0x2f9ea0 bne 0x2f9eba <ps_hints_apply+0x8aba>
 *   @0x2f9ea2 ldr.w r8, [r6, #0x10]
 *   @0x2f9ea6 mov r0, r7
 *   @0x2f9ea8 ldr.w r2, [r4, #0x238]
 *   @0x2f9eac ldr.w r9, [r8, r5, lsl #3]
 *   @0x2f9eb0 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2f9eb4 add r0, r9
 *   @0x2f9eb6 str.w r0, [r8, r5, lsl #3]
 *   @0x2f9eba ldr r3, [r6, #0x18]
 *   @0x2f9ebc ldrb r2, [r3, r5]
 *   @0x2f9ebe orr r2, r2, #0x8
 *   @0x2f9ec2 strb r2, [r3, r5]
 *   @0x2f9ec4 ldrsh.w r1, [r4, #0x130]
 *   @0x2f9ec8 cbz r1, 0x2f9f0a <ps_hints_apply+0x8b0a>
 *   @0x2f9eca ldr r3, [r4]
 *   @0x2f9ecc ldr r3, [r3, #0x60]
 *   @0x2f9ece ldr r3, [r3, #0x40]
 *   @0x2f9ed0 cmp r3, #0x28
 *   @0x2f9ed2 bne 0x2f9ee6 <ps_hints_apply+0x8ae6>
 *   @0x2f9ed4 ldrb.w r3, [r4, #0x267]
 *   @0x2f9ed8 cbz r3, 0x2f9ee6 <ps_hints_apply+0x8ae6>
 *   @0x2f9eda ldrb.w r3, [r4, #0x268]
 *   @0x2f9ede cbz r3, 0x2f9ee6 <ps_hints_apply+0x8ae6>
 *   @0x2f9ee0 ldrb.w r3, [r4, #0x269]
 *   @0x2f9ee4 cbnz r3, 0x2f9f00 <ps_hints_apply+0x8b00>
 *   @0x2f9ee6 ldr r3, [r6, #0x10]
 *   @0x2f9ee8 mov r0, r7
 *   @0x2f9eea ldr.w r2, [r4, #0x238]
 *   @0x2f9eee add.w r8, r3, r5, lsl #3
 *   @0x2f9ef2 ldr.w r9, [r8, #0x4]
 *   @0x2f9ef6 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2f9efa add r0, r9
 *   @0x2f9efc str.w r0, [r8, #0x4]
 *   @0x2f9f00 ldr r3, [r6, #0x18]
 *   @0x2f9f02 ldrb r2, [r3, r5]
 *   @0x2f9f04 orr r2, r2, #0x10
 *   @0x2f9f08 strb r2, [r3, r5]
 *   @0x2f9f0a pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
/* ═══════════════════════════════════════════════════════════════════════
 * §13  anon_thumb_2f08c6   0x2f08c6..0x2f0d1c   1,110 B / 410 条   in-degree 2
 * psaux/pshints.c 带（1,110 B / 6 个 bl 入口 / 410 条）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 2 条 Thumb `bl` 指向本段起始：ps_hints_apply×2；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 8 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push {r4, r5, r6, lr} / mov r4, r0 / mov r6, r1（帧：push {r4, r5, r6, lr}）；窗口内出口 9 个
 * 结构：入口可达 50 B / 22 条（4%）；段内 bl 入口 5 个：0x2f08f8(64 B/23 条) / 0x2f0938(40 B/16 条) / 0x2f09a8(190 B/76 条) / 0x2f0a78(330 B/117 条) / 0x2f0d00(30 B/12 条)
 *      可打印岛：无 ≥16 B 的
 * 入口 50 B / 22 条，被 ps_hints_apply bl 2 次；8 处 bl 打向 ft_mem_free / ft_mem_alloc / FT_DivFix。
 *      段内 5 个 bl 入口：0x2f08f8(64 B) / 0x2f0938(40 B) / 0x2f09a8(190 B) / 0x2f0a78(330 B) / 0x2f0d00(30 B)。
 *
 * 锚点：410 条（= asm/index-anonT_2f08c6.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2f08c6 push {r4, r5, r6, lr}
 *   @0x2f08c8 mov r4, r0
 *   @0x2f08ca mov r6, r1
 *   @0x2f08cc mov r0, r1
 *   @0x2f08ce ldr r1, [r4, #0x18]
 *   @0x2f08d0 movs r5, #0x0
 *   @0x2f08d2 bl 0x2e7336 <ft_mem_free>
 *   @0x2f08d6 mov r0, r6
 *   @0x2f08d8 ldr r1, [r4, #0xc]
 *   @0x2f08da str r5, [r4, #0x18]
 *   @0x2f08dc str r5, [r4, #0x14]
 *   @0x2f08de str r5, [r4, #0x1c]
 *   @0x2f08e0 bl 0x2e7336 <ft_mem_free>
 *   @0x2f08e4 str r5, [r4, #0xc]
 *   @0x2f08e6 mov r0, r6
 *   @0x2f08e8 ldr r1, [r4, #0x8]
 *   @0x2f08ea bl 0x2e7336 <ft_mem_free>
 *   @0x2f08ee str r5, [r4, #0x8]
 *   @0x2f08f0 str r5, [r4, #0x4]
 *   @0x2f08f2 str r5, [r4]
 *   @0x2f08f4 str r5, [r4, #0x10]
 *   @0x2f08f6 pop {r4, r5, r6, pc}
 *   @0x2f08f8 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2f08fc mov r5, r0
 *   @0x2f08fe ldr r6, [r0, #0x4]
 *   @0x2f0900 mov r8, r1
 *   @0x2f0902 ldr r4, [r0, #0x8]
 *   @0x2f0904 movs r7, #0x0
 *   @0x2f0906 adds r4, #0x10
 *   @0x2f0908 mov r0, r8
 *   @0x2f090a cbz r6, 0x2f0928 <FT_Done_Memory+0x6cb4>
 *   @0x2f090c ldr r1, [r4, #-8]
 *   @0x2f0910 subs r6, #0x1
 *   @0x2f0912 bl 0x2e7336 <ft_mem_free>
 *   @0x2f0916 str r7, [r4, #-8]
 *   @0x2f091a str r7, [r4, #-16]
 *   @0x2f091e str r7, [r4, #-12]
 *   @0x2f0922 str r7, [r4, #-4]
 *   @0x2f0926 b 0x2f0906 <FT_Done_Memory+0x6c92>
 *   @0x2f0928 ldr r1, [r5, #0x8]
 *   @0x2f092a bl 0x2e7336 <ft_mem_free>
 *   @0x2f092e str r6, [r5, #0x8]
 *   @0x2f0930 str r6, [r5]
 *   @0x2f0932 str r6, [r5, #0x4]
 *   @0x2f0934 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2f0938 push {r3, r4, r5, lr}
 *   @0x2f093a mov r4, r0
 *   @0x2f093c mov r5, r1
 *   @0x2f093e adds r0, #0x18
 *   @0x2f0940 bl 0x2f08f8 <FT_Done_Memory+0x6c84>
 *   @0x2f0944 add.w r0, r4, #0xc
 *   @0x2f0948 mov r1, r5
 *   @0x2f094a bl 0x2f08f8 <FT_Done_Memory+0x6c84>
 *   @0x2f094e mov r0, r5
 *   @0x2f0950 ldr r1, [r4, #0x8]
 *   @0x2f0952 bl 0x2e7336 <ft_mem_free>
 *   @0x2f0956 movs r3, #0x0
 *   @0x2f0958 str r3, [r4, #0x8]
 *   @0x2f095a str r3, [r4]
 *   @0x2f095c str r3, [r4, #0x4]
 *   @0x2f095e pop {r3, r4, r5, pc}
 *   @0x2f0960 push {r4, r5, r6, lr}
 *   @0x2f0962 mov r4, r0
 *   @0x2f0964 ldr r6, [r0, #0xc]
 *   @0x2f0966 movs r5, #0x0
 *   @0x2f0968 adds r0, #0x1c
 *   @0x2f096a str r5, [r0, #0x54]
 *   @0x2f096c str r5, [r0, #0x70]
 *   @0x2f096e mov r1, r6
 *   @0x2f0970 bl 0x2f0938 <FT_Done_Memory+0x6cc4>
 *   @0x2f0974 add.w r0, r4, #0x40
 *   @0x2f0978 mov r1, r6
 *   @0x2f097a bl 0x2f0938 <FT_Done_Memory+0x6cc4>
 *   @0x2f097e str r5, [r4, #0x10]
 *   @0x2f0980 str r5, [r4, #0xc]
 *   @0x2f0982 pop {r4, r5, r6, pc}
 *   @0x2f0984 mov r1, r0
 *   @0x2f0986 cbz r0, 0x2f09a6 <FT_Done_Memory+0x6d32>
 *   @0x2f0988 ldr r0, [r0]
 *   @0x2f098a movs r3, #0x0
 *   @0x2f098c str r3, [r1, #0x4]
 *   @0x2f098e str.w r3, [r1, #0xd0]
 *   @0x2f0992 str.w r3, [r1, #0x19c]
 *   @0x2f0996 str.w r3, [r1, #0x3a0]
 *   @0x2f099a str.w r3, [r1, #0x5a4]
 *   @0x2f099e str.w r3, [r1, #0x7a8]
 *   @0x2f09a2 b.w 0x2e7336 <ft_mem_free>
 *   @0x2f09a6 bx lr
 *   @0x2f09a8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2f09ac sub sp, #0x1c
 *   @0x2f09ae add.w r8, r2, #0x4
 *   @0x2f09b2 str r3, [sp, #0xc]
 *   @0x2f09b4 ldr r3, [r3]
 *   @0x2f09b6 str r0, [sp, #0x14]
 *   @0x2f09b8 str r1, [sp, #0x8]
 *   @0x2f09ba str r3, [sp, #0x4]
 *   @0x2f09bc ldr r3, [sp, #0x40]
 *   @0x2f09be ldr.w r11, [r3]
 *   @0x2f09c2 movs r3, #0x1
 *   @0x2f09c4 ldr r2, [sp, #0x8]
 *   @0x2f09c6 cmp r2, #0x1
 *   @0x2f09c8 bls 0x2f0a66 <FT_Done_Memory+0x6df2>
 *   @0x2f09ca cbnz r3, 0x2f09d0 <FT_Done_Memory+0x6d5c>
 *   @0x2f09cc ldr r2, [sp, #0x14]
 *   @0x2f09ce cbz r2, 0x2f09e6 <FT_Done_Memory+0x6d72>
 *   @0x2f09d0 ldrsh r9, [r8, #-2]
 *   @0x2f09d4 mov r7, r11
 *   @0x2f09d6 ldrsh r12, [r8, #-4]
 *   @0x2f09da movs r2, #0x0
 *   @0x2f09dc ldr r3, [sp, #0x40]
 *   @0x2f09de rsb r12, r9, r12
 *   @0x2f09e2 adds r4, r3, #0x4
 *   @0x2f09e4 b 0x2f09fa <FT_Done_Memory+0x6d86>
 *   @0x2f09e6 ldrsh r9, [r8, #-4]
 *   @0x2f09ea movs r2, #0x1
 *   @0x2f09ec ldrsh r12, [r8, #-2]
 *   @0x2f09f0 ldr r3, [sp, #0xc]
 *   @0x2f09f2 ldr r7, [sp, #0x4]
 *   @0x2f09f4 rsb r12, r9, r12
 *   @0x2f09f8 adds r4, r3, #0x4
 *   @0x2f09fa str r2, [sp, #0x10]
 *   @0x2f09fc cbz r7, 0x2f0a24 <FT_Done_Memory+0x6db0>
 *   @0x2f09fe ldr r3, [r4]
 *   @0x2f0a00 cmp r9, r3
 *   @0x2f0a02 blt 0x2f0a24 <FT_Done_Memory+0x6db0>
 *   @0x2f0a04 bne 0x2f0a1e <FT_Done_Memory+0x6daa>
 *   @0x2f0a06 cmp.w r12, #0x0
 *   @0x2f0a0a ldr r3, [r4, #0x4]
 *   @0x2f0a0c bge 0x2f0a14 <FT_Done_Memory+0x6da0>
 *   @0x2f0a0e cmp r12, r3
 *   @0x2f0a10 bge 0x2f0a58 <FT_Done_Memory+0x6de4>
 *   @0x2f0a12 b 0x2f0a18 <FT_Done_Memory+0x6da4>
 *   @0x2f0a14 cmp r12, r3
 *   @0x2f0a16 ble 0x2f0a58 <FT_Done_Memory+0x6de4>
 *   @0x2f0a18 str.w r12, [r4, #0x4]
 *   @0x2f0a1c b 0x2f0a58 <FT_Done_Memory+0x6de4>
 *   @0x2f0a1e subs r7, #0x1
 *   @0x2f0a20 adds r4, #0x20
 *   @0x2f0a22 b 0x2f09fc <FT_Done_Memory+0x6d88>
 *   @0x2f0a24 add.w r10, r4, r7, lsl #5
 *   @0x2f0a28 sub.w r10, r10, #0x20
 *   @0x2f0a2c cbz r7, 0x2f0a44 <FT_Done_Memory+0x6dd0>
 *   @0x2f0a2e mov r6, r10
 *   @0x2f0a30 add.w r5, r10, #0x20
 *   @0x2f0a34 ldm r6!, {r0, r1, r2, r3}
 *   @0x2f0a36 subs r7, #0x1
 *   @0x2f0a38 stm r5!, {r0, r1, r2, r3}
 *   @0x2f0a3a ldm.w r6, {r0, r1, r2, r3}
 *   @0x2f0a3e stm.w r5, {r0, r1, r2, r3}
 *   @0x2f0a42 b 0x2f0a28 <FT_Done_Memory+0x6db4>
 *   @0x2f0a44 ldr r3, [sp, #0x10]
 *   @0x2f0a46 stm.w r4, {r9, r12}
 *   @0x2f0a4a cbz r3, 0x2f0a54 <FT_Done_Memory+0x6de0>
 *   @0x2f0a4c ldr r2, [sp, #0x4]
 *   @0x2f0a4e adds r2, #0x1
 *   @0x2f0a50 str r2, [sp, #0x4]
 *   @0x2f0a52 b 0x2f0a58 <FT_Done_Memory+0x6de4>
 *   @0x2f0a54 add.w r11, r11, #0x1
 *   @0x2f0a58 ldr r3, [sp, #0x8]
 *   @0x2f0a5a add.w r8, r8, #0x4
 *   @0x2f0a5e subs r3, #0x2
 *   @0x2f0a60 str r3, [sp, #0x8]
 *   @0x2f0a62 movs r3, #0x0
 *   @0x2f0a64 b 0x2f09c4 <FT_Done_Memory+0x6d50>
 *   @0x2f0a66 ldr r3, [sp, #0x4]
 *   @0x2f0a68 ldr r2, [sp, #0xc]
 *   @0x2f0a6a str r3, [r2]
 *   @0x2f0a6c ldr r3, [sp, #0x40]
 *   @0x2f0a6e str.w r11, [r3]
 *   @0x2f0a72 add sp, #0x1c
 *   @0x2f0a74 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f0a78 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2f0a7c mov r7, r3
 *   @0x2f0a7e ldr r4, [sp, #0x38]
 *   @0x2f0a80 ldr r6, [sp, #0x34]
 *   @0x2f0a82 cbz r4, 0x2f0a8e <FT_Done_Memory+0x6e1a>
 *   @0x2f0a84 add.w r4, r0, #0x408
 *   @0x2f0a88 addw r5, r0, #0x60c
 *   @0x2f0a8c b 0x2f0a94 <FT_Done_Memory+0x6e20>
 *   @0x2f0a8e add.w r5, r0, #0x204
 *   @0x2f0a92 mov r4, r0
 *   @0x2f0a94 movs r0, #0x0
 *   @0x2f0a96 mov r3, r4
 *   @0x2f0a98 str r0, [r4]
 *   @0x2f0a9a str r0, [r5]
 *   @0x2f0a9c str r5, [sp]
 *   @0x2f0a9e bl 0x2f09a8 <FT_Done_Memory+0x6d34>
 *   @0x2f0aa2 movs r0, #0x1
 *   @0x2f0aa4 ldr r2, [sp, #0x30]
 *   @0x2f0aa6 mov r1, r7
 *   @0x2f0aa8 str r5, [sp]
 *   @0x2f0aaa mov r3, r4
 *   @0x2f0aac bl 0x2f09a8 <FT_Done_Memory+0x6d34>
 *   @0x2f0ab0 ldr r2, [r4]
 *   @0x2f0ab2 ldr r0, [r5]
 *   @0x2f0ab4 cbnz r2, 0x2f0aba <FT_Done_Memory+0x6e46>
 *   @0x2f0ab6 cbnz r0, 0x2f0b04 <FT_Done_Memory+0x6e90>
 *   @0x2f0ab8 b 0x2f0b4c <FT_Done_Memory+0x6ed8>
 *   @0x2f0aba add.w r3, r4, #0x24
 *   @0x2f0abe add.w r8, r4, #0x4
 *   @0x2f0ac2 mov r1, r2
 *   @0x2f0ac4 mov r9, r3
 *   @0x2f0ac6 cmp r1, #0x1
 *   @0x2f0ac8 bls 0x2f0ae8 <FT_Done_Memory+0x6e74>
 *   @0x2f0aca rsb r7, r8, r3
 *   @0x2f0ace add r7, r9
 *   @0x2f0ad0 ldr r12, [r7, #-32]
 *   @0x2f0ad4 ldr r7, [r3, #-32]
 *   @0x2f0ad8 rsb r12, r7, r12
 *   @0x2f0adc ldr r7, [r3, #-28]
 *   @0x2f0ae0 cmp r7, r12
 *   @0x2f0ae2 it gt
 *   @0x2f0ae4 strgt r12, [r3, #-28]
 *   @0x2f0ae8 ldr r12, [r3, #-32]
 *   @0x2f0aec subs r1, #0x1
 *   @0x2f0aee ldr r7, [r3, #-28]
 *   @0x2f0af2 add.w r3, r3, #0x20
 *   @0x2f0af6 str r12, [r3, #-52]
 *   @0x2f0afa add r12, r7
 *   @0x2f0afc str r12, [r3, #-56]
 *   @0x2f0b00 bne 0x2f0ac6 <FT_Done_Memory+0x6e52>
 *   @0x2f0b02 b 0x2f0ab6 <FT_Done_Memory+0x6e42>
 *   @0x2f0b04 add.w r3, r5, #0x24
 *   @0x2f0b08 add.w r8, r5, #0x4
 *   @0x2f0b0c mov r1, r0
 *   @0x2f0b0e mov r9, r3
 *   @0x2f0b10 cmp r1, #0x1
 *   @0x2f0b12 bls 0x2f0b32 <FT_Done_Memory+0x6ebe>
 *   @0x2f0b14 rsb r12, r8, r3
 *   @0x2f0b18 ldr r7, [r3, #-32]
 *   @0x2f0b1c add r12, r9
 *   @0x2f0b1e ldr r12, [r12, #-32]
 *   @0x2f0b22 rsb r12, r12, r7
 *   @0x2f0b26 ldr r7, [r3, #-28]
 *   @0x2f0b2a cmp r7, r12
 *   @0x2f0b2c it lt
 *   @0x2f0b2e strlt r12, [r3, #-28]
 *   @0x2f0b32 ldr r12, [r3, #-32]
 *   @0x2f0b36 subs r1, #0x1
 *   @0x2f0b38 ldr r7, [r3, #-28]
 *   @0x2f0b3c add.w r3, r3, #0x20
 *   @0x2f0b40 str r12, [r3, #-56]
 *   @0x2f0b44 add r12, r7
 *   @0x2f0b46 str r12, [r3, #-52]
 *   @0x2f0b4a bne 0x2f0b10 <FT_Done_Memory+0x6e9c>
 *   @0x2f0b4c adds r4, #0x4
 *   @0x2f0b4e movs r7, #0x2
 *   @0x2f0b50 b 0x2f0b96 <FT_Done_Memory+0x6f22>
 *   @0x2f0b52 rsb r8, r4, r3
 *   @0x2f0b56 add r8, r10
 *   @0x2f0b58 ldr.w r9, [r8, #0xc]
 *   @0x2f0b5c rsb r11, r1, r9
 *   @0x2f0b60 add.w r11, r11, r11, lsr #31
 *   @0x2f0b64 asr.w r11, r11, #0x1
 *   @0x2f0b68 cmp r11, r6
 *   @0x2f0b6a bge 0x2f0bae <FT_Done_Memory+0x6f3a>
 *   @0x2f0b6c add r1, r11
 *   @0x2f0b6e str.w r1, [r8, #0xc]
 *   @0x2f0b72 str r1, [r3, #0x8]
 *   @0x2f0b74 adds r3, #0x20
 *   @0x2f0b76 ldr r1, [r3, #0x8]
 *   @0x2f0b78 add.w r12, r12, #0xffffffff
 *   @0x2f0b7c cmp.w r12, #0x0
 *   @0x2f0b80 bne 0x2f0b52 <FT_Done_Memory+0x6ede>
 *   @0x2f0b82 add.w r4, r4, r2, lsl #5
 *   @0x2f0b86 add r1, r6
 *   @0x2f0b88 str r1, [r4, #-24]
 *   @0x2f0b8c subs r7, #0x1
 *   @0x2f0b8e add.w r4, r5, #0x4
 *   @0x2f0b92 beq 0x2f0bbc <FT_Done_Memory+0x6f48>
 *   @0x2f0b94 mov r2, r0
 *   @0x2f0b96 cmp r2, #0x0
 *   @0x2f0b98 beq 0x2f0b8c <FT_Done_Memory+0x6f18>
 *   @0x2f0b9a ldr r3, [r4, #0xc]
 *   @0x2f0b9c add.w r12, r2, #0xffffffff
 *   @0x2f0ba0 ldr r1, [r4, #0x8]
 *   @0x2f0ba2 add.w r10, r4, #0x20
 *   @0x2f0ba6 subs r3, r3, r6
 *   @0x2f0ba8 str r3, [r4, #0xc]
 *   @0x2f0baa mov r3, r4
 *   @0x2f0bac b 0x2f0b7c <FT_Done_Memory+0x6f08>
 *   @0x2f0bae add r1, r6
 *   @0x2f0bb0 str r1, [r3, #0x8]
 *   @0x2f0bb2 rsb r1, r6, r9
 *   @0x2f0bb6 str.w r1, [r8, #0xc]
 *   @0x2f0bba b 0x2f0b74 <FT_Done_Memory+0x6f00>
 *   @0x2f0bbc add sp, #0xc
 *   @0x2f0bbe pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f0bc2 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2f0bc6 sub sp, #0x24
 *   @0x2f0bc8 mov r4, r1
 *   @0x2f0bca mov.w r1, #0x9c0
 *   @0x2f0bce str r2, [sp, #0x14]
 *   @0x2f0bd0 add r2, sp, #0x1c
 *   @0x2f0bd2 mov r6, r0
 *   @0x2f0bd4 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2f0bd8 ldr r3, [sp, #0x1c]
 *   @0x2f0bda mov r5, r0
 *   @0x2f0bdc cmp r3, #0x0
 *   @0x2f0bde bne.w 0x2f0cf4 <FT_Done_Memory+0x7080>
 *   @0x2f0be2 str r6, [r0]
 *   @0x2f0be4 add.w r1, r0, #0xe0
 *   @0x2f0be8 ldrh.w r2, [r4, #0x78]
 *   @0x2f0bec movs r6, #0xc
 *   @0x2f0bee str.w r2, [r0, #0xd4]
 *   @0x2f0bf2 add.w r0, r4, #0x80
 *   @0x2f0bf6 ldrb.w r2, [r4, #0x7c]
 *   @0x2f0bfa cmp r2, r3
 *   @0x2f0bfc beq 0x2f0c0e <FT_Done_Memory+0x6f9a>
 *   @0x2f0bfe mul r7, r6, r3
 *   @0x2f0c02 ldrsh.w lr, [r0, r3, lsl #1]
 *   @0x2f0c06 adds r3, #0x1
 *   @0x2f0c08 str.w lr, [r1, r7]
 *   @0x2f0c0c b 0x2f0bfa <FT_Done_Memory+0x6f86>
 *   @0x2f0c0e ldrb.w r3, [r4, #0x7c]
 *   @0x2f0c12 add.w r1, r5, #0x14
 *   @0x2f0c16 add.w r0, r4, #0x9a
 *   @0x2f0c1a movs r6, #0xc
 *   @0x2f0c1c adds r3, #0x1
 *   @0x2f0c1e str.w r3, [r5, #0xd0]
 *   @0x2f0c22 ldrh.w r3, [r4, #0x7a]
 *   @0x2f0c26 str r3, [r5, #0x8]
 *   @0x2f0c28 movs r3, #0x0
 *   @0x2f0c2a ldrb.w r2, [r4, #0x7d]
 *   @0x2f0c2e cmp r2, r3
 *   @0x2f0c30 beq 0x2f0c42 <FT_Done_Memory+0x6fce>
 *   @0x2f0c32 mul r7, r6, r3
 *   @0x2f0c36 ldrsh.w lr, [r0, r3, lsl #1]
 *   @0x2f0c3a adds r3, #0x1
 *   @0x2f0c3c str.w lr, [r1, r7]
 *   @0x2f0c40 b 0x2f0c2e <FT_Done_Memory+0x6fba>
 *   @0x2f0c42 ldrb.w r3, [r4, #0x7d]
 *   @0x2f0c46 add.w r12, r5, #0x19c
 *   @0x2f0c4a add.w r11, r4, #0xc
 *   @0x2f0c4e movs r6, #0x0
 *   @0x2f0c50 adds r3, #0x1
 *   @0x2f0c52 str r3, [r5, #0x4]
 *   @0x2f0c54 ldr r2, [r4, #0x74]
 *   @0x2f0c56 mov r0, r12
 *   @0x2f0c58 add.w r9, r4, #0x28
 *   @0x2f0c5c ldrb r1, [r4, #0x8]
 *   @0x2f0c5e ldrb r3, [r4, #0x9]
 *   @0x2f0c60 add.w r8, r4, #0x3c
 *   @0x2f0c64 str r2, [sp, #0x4]
 *   @0x2f0c66 mov r2, r11
 *   @0x2f0c68 str.w r9, [sp]
 *   @0x2f0c6c add.w r7, r4, #0x58
 *   @0x2f0c70 str r6, [sp, #0x8]
 *   @0x2f0c72 mov.w r10, #0x1
 *   @0x2f0c76 str.w r12, [sp, #0x10]
 *   @0x2f0c7a bl 0x2f0a78 <FT_Done_Memory+0x6e04>
 *   @0x2f0c7e ldr.w r12, [sp, #0x10]
 *   @0x2f0c82 ldr r2, [r4, #0x74]
 *   @0x2f0c84 ldrb r3, [r4, #0xb]
 *   @0x2f0c86 mov r0, r12
 *   @0x2f0c88 ldrb r1, [r4, #0xa]
 *   @0x2f0c8a str r2, [sp, #0x4]
 *   @0x2f0c8c mov r2, r8
 *   @0x2f0c8e str r7, [sp]
 *   @0x2f0c90 str.w r10, [sp, #0x8]
 *   @0x2f0c94 bl 0x2f0a78 <FT_Done_Memory+0x6e04>
 *   @0x2f0c98 ldrb r0, [r4, #0x8]
 *   @0x2f0c9a mov r1, r11
 *   @0x2f0c9c mov r2, r10
 *   @0x2f0c9e bl 0x2f041c <FT_Done_Memory+0x67a8>
 *   @0x2f0ca2 mov r1, r9
 *   @0x2f0ca4 mov r2, r0
 *   @0x2f0ca6 ldrb r0, [r4, #0x9]
 *   @0x2f0ca8 bl 0x2f041c <FT_Done_Memory+0x67a8>
 *   @0x2f0cac mov r1, r8
 *   @0x2f0cae mov r2, r0
 *   @0x2f0cb0 ldrb r0, [r4, #0xa]
 *   @0x2f0cb2 bl 0x2f041c <FT_Done_Memory+0x67a8>
 *   @0x2f0cb6 mov r1, r7
 *   @0x2f0cb8 mov r2, r0
 *   @0x2f0cba ldrb r0, [r4, #0xb]
 *   @0x2f0cbc bl 0x2f041c <FT_Done_Memory+0x67a8>
 *   @0x2f0cc0 mov r1, r0
 *   @0x2f0cc2 mov.w r0, #0x3e8
 *   @0x2f0cc6 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2f0cca ldr r3, [r4, #0x6c]
 *   @0x2f0ccc cmp r0, r3
 *   @0x2f0cce ite le
 *   @0x2f0cd0 strle.w r0, [r5, #0x9ac]
 *   @0x2f0cd4 strgt.w r3, [r5, #0x9ac]
 *   @0x2f0cd8 ldr r3, [r4, #0x70]
 *   @0x2f0cda str.w r3, [r5, #0x9b0]
 *   @0x2f0cde ldr r3, [r4, #0x74]
 *   @0x2f0ce0 str.w r6, [r5, #0xc8]
 *   @0x2f0ce4 str.w r6, [r5, #0xcc]
 *   @0x2f0ce8 str.w r3, [r5, #0x9b8]
 *   @0x2f0cec str.w r6, [r5, #0x194]
 *   @0x2f0cf0 str.w r6, [r5, #0x198]
 *   @0x2f0cf4 ldr r3, [sp, #0x14]
 *   @0x2f0cf6 ldr r0, [sp, #0x1c]
 *   @0x2f0cf8 str r5, [r3]
 *   @0x2f0cfa add sp, #0x24
 *   @0x2f0cfc pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f0d00 ldr r3, [r0]
 *   @0x2f0d02 cmp r1, r3
 *   @0x2f0d04 bhs 0x2f0d1a <FT_Done_Memory+0x70a6>
 *   @0x2f0d06 ldr r2, [r0, #0x8]
 *   @0x2f0d08 asrs r3, r1, #0x3
 *   @0x2f0d0a and r1, r1, #0x7
 *   @0x2f0d0e ldrb r0, [r2, r3]
 *   @0x2f0d10 movs r3, #0x80
 *   @0x2f0d12 asr.w r1, r3, r1
 *   @0x2f0d16 ands r0, r1
 *   @0x2f0d18 bx lr
 *   @0x2f0d1a movs r0, #0x0
/* ═══════════════════════════════════════════════════════════════════════
 * §14  anon_thumb_2f1142   0x2f1142..0x2f13fe   700 B / 275 条   in-degree 2
 * psaux 带 700 B 单函数（本批唯一与 split 尺寸差 2 B 的段）
 * ─────────────────────────────────────────────────────────────────────
 * ISA：Thumb-2（证明级）。反向 2 条 Thumb `bl` 指向本段起始：ps_hints_apply×1 / anon_2e9c78 区×1；
 *      异族（ARM `bl`/`blx` 指向本段）0 条。正向 0 条 `bl` 指向具名 Thumb 符号、0 条指向具名 ARM 符号。
 * 契约：入口 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} / mov r10, r3 / movs r3, #0xcc（帧：sub sp, 0x24）；窗口内出口 1 个（唯一出口 0x2f13fa）
 * 结构：入口可达 700 B / 245 条（100%）；段内 bl 入口 0 个：无（本段只有入口函数）
 *      可打印岛：无 ≥16 B 的
 * 入口 700 B / 245 条、1 个出口（0x2f13fa 的 pop.w {r4-r11, pc}）；被 ps_hints_apply 与 0x2e9c78 区
 *      各 bl 1 次；正向只 bl 到 0x2f00dc（区内匿名），没有具名 Thumb 被调 —— 本段靠反向立住。
 *      split 表记 698 B 是因为切在 pop.w 中间，本卡放到 0x2f13fe。
 *
 * 锚点：275 条（= asm/index-anonT_2f1142.tsv 全表，地址序）
 * ───────────────────────────────────────────────────────────────────── */
 *   @0x2f1142 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2f1146 mov r10, r3
 *   @0x2f1148 movs r3, #0xcc
 *   @0x2f114a sub sp, #0x24
 *   @0x2f114c mla r3, r3, r2, r1
 *   @0x2f1150 mov r8, r1
 *   @0x2f1152 mov r4, r0
 *   @0x2f1154 str r2, [sp, #0xc]
 *   @0x2f1156 adds r3, #0x4
 *   @0x2f1158 str r3, [sp, #0x14]
 *   @0x2f115a ldr.w r1, [r3, #0xc4]
 *   @0x2f115e ldr.w r6, [r3, #0xc8]
 *   @0x2f1162 ldr r3, [r0, #0x10]
 *   @0x2f1164 str r1, [sp, #0x18]
 *   @0x2f1166 ands r7, r3, #0x8
 *   @0x2f116a bne.w 0x2f13f8 <FT_Done_Memory+0x7784>
 *   @0x2f116e ldr r0, [r0]
 *   @0x2f1170 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f1174 ldr r1, [sp, #0x18]
 *   @0x2f1176 add r6, r0
 *   @0x2f1178 ldr r0, [r4, #0x4]
 *   @0x2f117a bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f117e ldr r2, [sp, #0xc]
 *   @0x2f1180 mov r5, r0
 *   @0x2f1182 cbnz r2, 0x2f118c <FT_Done_Memory+0x7518>
 *   @0x2f1184 ldrb.w r3, [r10, #0x78]
 *   @0x2f1188 cbnz r3, 0x2f119e <FT_Done_Memory+0x752a>
 *   @0x2f118a b 0x2f1198 <FT_Done_Memory+0x7524>
 *   @0x2f118c ldr r2, [sp, #0xc]
 *   @0x2f118e cmp r2, #0x1
 *   @0x2f1190 bne 0x2f11b2 <FT_Done_Memory+0x753e>
 *   @0x2f1192 ldrb.w r3, [r10, #0x79]
 *   @0x2f1196 cbnz r3, 0x2f11a4 <FT_Done_Memory+0x7530>
 *   @0x2f1198 str r6, [r4, #0x8]
 *   @0x2f119a str r5, [r4, #0xc]
 *   @0x2f119c b 0x2f13f0 <FT_Done_Memory+0x777c>
 *   @0x2f119e ldrb.w r3, [r10, #0x7a]
 *   @0x2f11a2 b 0x2f11a8 <FT_Done_Memory+0x7534>
 *   @0x2f11a4 ldrb.w r3, [r10, #0x7b]
 *   @0x2f11a8 adds r3, #0x0
 *   @0x2f11aa it ne
 *   @0x2f11ac movne r3, #0x1
 *   @0x2f11ae str r3, [sp, #0x10]
 *   @0x2f11b0 b 0x2f11b4 <FT_Done_Memory+0x7540>
 *   @0x2f11b2 str r7, [sp, #0x10]
 *   @0x2f11b4 ldr r2, [sp, #0xc]
 *   @0x2f11b6 str r5, [r4, #0xc]
 *   @0x2f11b8 cmp r2, #0x1
 *   @0x2f11ba bne 0x2f128c <FT_Done_Memory+0x7618>
 *   @0x2f11bc ldr.w r11, [r4]
 *   @0x2f11c0 add.w r1, r8, #0x1a0
 *   @0x2f11c4 ldr r7, [r4, #0x4]
 *   @0x2f11c6 ldrb.w r3, [r8, #0x9bc]
 *   @0x2f11ca ldr.w r0, [r8, #0x19c]
 *   @0x2f11ce add r7, r11
 *   @0x2f11d0 str r3, [sp]
 *   @0x2f11d2 cbz r0, 0x2f1208 <FT_Done_Memory+0x7594>
 *   @0x2f11d4 ldr r2, [r1, #0xc]
 *   @0x2f11d6 ldr.w r9, [r8, #0x9b8]
 *   @0x2f11da rsb r12, r2, r7
 *   @0x2f11de rsb.w r2, r9, #0x0
 *   @0x2f11e2 cmp r12, r2
 *   @0x2f11e4 blt 0x2f120c <FT_Done_Memory+0x7598>
 *   @0x2f11e6 ldr r2, [r1, #0x8]
 *   @0x2f11e8 add r2, r9
 *   @0x2f11ea cmp r7, r2
 *   @0x2f11ec bgt 0x2f1202 <FT_Done_Memory+0x758e>
 *   @0x2f11ee ldr r2, [sp]
 *   @0x2f11f0 cbnz r2, 0x2f11fa <FT_Done_Memory+0x7586>
 *   @0x2f11f2 ldr.w r2, [r8, #0x9b4]
 *   @0x2f11f6 cmp r12, r2
 *   @0x2f11f8 bgt 0x2f1212 <FT_Done_Memory+0x759e>
 *   @0x2f11fa ldr.w r9, [r1, #0x10]
 *   @0x2f11fe movs r7, #0x1
 *   @0x2f1200 b 0x2f1218 <FT_Done_Memory+0x75a4>
 *   @0x2f1202 subs r0, #0x1
 *   @0x2f1204 adds r1, #0x20
 *   @0x2f1206 b 0x2f11d2 <FT_Done_Memory+0x755e>
 *   @0x2f1208 mov r9, r0
 *   @0x2f120a b 0x2f1216 <FT_Done_Memory+0x75a2>
 *   @0x2f120c mov.w r9, #0x0
 *   @0x2f1210 b 0x2f1216 <FT_Done_Memory+0x75a2>
 *   @0x2f1212 ldr.w r9, [sp]
 *   @0x2f1216 mov r7, r9
 *   @0x2f1218 ldr.w r2, [r8, #0x3a0]
 *   @0x2f121c add.w r0, r8, r2, lsl #5
 *   @0x2f1220 add.w r0, r0, #0x384
 *   @0x2f1224 cbz r2, 0x2f1260 <FT_Done_Memory+0x75ec>
 *   @0x2f1226 ldr r1, [r0, #0x8]
 *   @0x2f1228 ldr.w r12, [r8, #0x9b8]
 *   @0x2f122c rsb r1, r11, r1
 *   @0x2f1230 str r1, [sp, #0x8]
 *   @0x2f1232 rsb.w r3, r12, #0x0
 *   @0x2f1236 cmp r1, r3
 *   @0x2f1238 blt 0x2f1264 <FT_Done_Memory+0x75f0>
 *   @0x2f123a ldr r3, [r0, #0xc]
 *   @0x2f123c rsb r12, r12, r3
 *   @0x2f1240 cmp r11, r12
 *   @0x2f1242 blt 0x2f125a <FT_Done_Memory+0x75e6>
 *   @0x2f1244 ldr r1, [sp]
 *   @0x2f1246 cbnz r1, 0x2f1252 <FT_Done_Memory+0x75de>
 *   @0x2f1248 ldr.w r2, [r8, #0x9b4]
 *   @0x2f124c ldr r3, [sp, #0x8]
 *   @0x2f124e cmp r3, r2
 *   @0x2f1250 bge 0x2f1268 <FT_Done_Memory+0x75f4>
 *   @0x2f1252 orr r7, r7, #0x2
 *   @0x2f1256 ldr r3, [r0, #0x10]
 *   @0x2f1258 b 0x2f126a <FT_Done_Memory+0x75f6>
 *   @0x2f125a subs r2, #0x1
 *   @0x2f125c subs r0, #0x20
 *   @0x2f125e b 0x2f1224 <FT_Done_Memory+0x75b0>
 *   @0x2f1260 mov r3, r2
 *   @0x2f1262 b 0x2f126a <FT_Done_Memory+0x75f6>
 *   @0x2f1264 movs r3, #0x0
 *   @0x2f1266 b 0x2f126a <FT_Done_Memory+0x75f6>
 *   @0x2f1268 ldr r3, [sp]
 *   @0x2f126a cmp r7, #0x2
 *   @0x2f126c beq 0x2f127e <FT_Done_Memory+0x760a>
 *   @0x2f126e cmp r7, #0x3
 *   @0x2f1270 beq 0x2f1282 <FT_Done_Memory+0x760e>
 *   @0x2f1272 cmp r7, #0x1
 *   @0x2f1274 bne 0x2f1290 <FT_Done_Memory+0x761c>
 *   @0x2f1276 rsb r5, r5, r9
 *   @0x2f127a str r5, [r4, #0x8]
 *   @0x2f127c b 0x2f13a8 <FT_Done_Memory+0x7734>
 *   @0x2f127e str r3, [r4, #0x8]
 *   @0x2f1280 b 0x2f13a8 <FT_Done_Memory+0x7734>
 *   @0x2f1282 str r3, [r4, #0x8]
 *   @0x2f1284 rsb r3, r3, r9
 *   @0x2f1288 str r3, [r4, #0xc]
 *   @0x2f128a b 0x2f13a8 <FT_Done_Memory+0x7734>
 *   @0x2f128c movs r7, #0x0
 *   @0x2f128e mov r9, r7
 *   @0x2f1290 ldr.w r11, [r4, #0x14]
 *   @0x2f1294 cmp.w r11, #0x0
 *   @0x2f1298 beq 0x2f12dc <FT_Done_Memory+0x7668>
 *   @0x2f129a ldr.w r3, [r11, #0x10]
 *   @0x2f129e lsls r3, r3, #0x1c
 *   @0x2f12a0 bmi 0x2f12ae <FT_Done_Memory+0x763a>
 *   @0x2f12a2 mov r0, r11
 *   @0x2f12a4 mov r1, r8
 *   @0x2f12a6 ldr r2, [sp, #0xc]
 *   @0x2f12a8 mov r3, r10
 *   @0x2f12aa bl 0x2f1142 <FT_Done_Memory+0x74ce>
 *   @0x2f12ae ldr.w r6, [r11, #0xc]
 *   @0x2f12b2 ldr.w r3, [r11, #0x8]
 *   @0x2f12b6 ldr r0, [r4, #0x4]
 *   @0x2f12b8 add.w r6, r3, r6, asr #1
 *   @0x2f12bc ldr r3, [r4]
 *   @0x2f12be ldr.w r2, [r11, #0x4]
 *   @0x2f12c2 add.w r0, r3, r0, asr #1
 *   @0x2f12c6 ldr.w r3, [r11]
 *   @0x2f12ca ldr r1, [sp, #0x18]
 *   @0x2f12cc add.w r2, r3, r2, asr #1
 *   @0x2f12d0 subs r0, r0, r2
 *   @0x2f12d2 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f12d6 add r0, r6
 *   @0x2f12d8 sub.w r6, r0, r5, asr #1
 *   @0x2f12dc str r6, [r4, #0x8]
 *   @0x2f12de str r5, [r4, #0xc]
 *   @0x2f12e0 ldrb.w r3, [r10, #0x7c]
 *   @0x2f12e4 cmp r3, #0x0
 *   @0x2f12e6 beq 0x2f1376 <FT_Done_Memory+0x7702>
 *   @0x2f12e8 cmp r5, #0x40
 *   @0x2f12ea bgt 0x2f1332 <FT_Done_Memory+0x76be>
 *   @0x2f12ec cmp r5, #0x1f
 *   @0x2f12ee ble 0x2f12fc <FT_Done_Memory+0x7688>
 *   @0x2f12f0 add.w r6, r6, r5, asr #1
 *   @0x2f12f4 movs r5, #0x40
 *   @0x2f12f6 bic r6, r6, #0x3f
 *   @0x2f12fa b 0x2f1376 <FT_Done_Memory+0x7702>
 *   @0x2f12fc cmp r5, #0x0
 *   @0x2f12fe add.w r3, r6, #0x20
 *   @0x2f1302 ble 0x2f132c <FT_Done_Memory+0x76b8>
 *   @0x2f1304 adds r1, r6, r5
 *   @0x2f1306 bic r3, r3, #0x3f
 *   @0x2f130a add.w r2, r1, #0x20
 *   @0x2f130e subs r6, r3, r6
 *   @0x2f1310 bic r2, r2, #0x3f
 *   @0x2f1314 cmp r6, #0x0
 *   @0x2f1316 it lt
 *   @0x2f1318 rsblt r6, r6, #0
 *   @0x2f131a subs r1, r2, r1
 *   @0x2f131c cmp r1, #0x0
 *   @0x2f131e it lt
 *   @0x2f1320 rsblt r1, r1, #0
 *   @0x2f1322 cmp r6, r1
 *   @0x2f1324 ite gt
 *   @0x2f1326 movgt r6, r2
 *   @0x2f1328 movle r6, r3
 *   @0x2f132a b 0x2f1376 <FT_Done_Memory+0x7702>
 *   @0x2f132c bic r6, r3, #0x3f
 *   @0x2f1330 b 0x2f1376 <FT_Done_Memory+0x7702>
 *   @0x2f1332 ldr r1, [sp, #0x14]
 *   @0x2f1334 ldr r3, [r1, #0x8]
 *   @0x2f1336 subs r2, r5, r3
 *   @0x2f1338 cmp r2, #0x0
 *   @0x2f133a it lt
 *   @0x2f133c rsblt r2, r2, #0
 *   @0x2f133e cmp r2, #0x27
 *   @0x2f1340 bgt 0x2f1348 <FT_Done_Memory+0x76d4>
 *   @0x2f1342 cmp r3, #0x2f
 *   @0x2f1344 ble 0x2f134e <FT_Done_Memory+0x76da>
 *   @0x2f1346 mov r5, r3
 *   @0x2f1348 cmp r5, #0xbf
 *   @0x2f134a bgt 0x2f1370 <FT_Done_Memory+0x76fc>
 *   @0x2f134c b 0x2f1350 <FT_Done_Memory+0x76dc>
 *   @0x2f134e movs r5, #0x30
 *   @0x2f1350 and r3, r5, #0x3f
 *   @0x2f1354 cmp r3, #0x9
 *   @0x2f1356 ble 0x2f1376 <FT_Done_Memory+0x7702>
 *   @0x2f1358 cmp r3, #0x1f
 *   @0x2f135a bic r2, r5, #0x3f
 *   @0x2f135e bgt 0x2f1366 <FT_Done_Memory+0x76f2>
 *   @0x2f1360 add.w r5, r2, #0xa
 *   @0x2f1364 b 0x2f1376 <FT_Done_Memory+0x7702>
 *   @0x2f1366 cmp r3, #0x35
 *   @0x2f1368 bgt 0x2f1376 <FT_Done_Memory+0x7702>
 *   @0x2f136a add.w r5, r2, #0x36
 *   @0x2f136e b 0x2f1376 <FT_Done_Memory+0x7702>
 *   @0x2f1370 adds r5, #0x20
 *   @0x2f1372 bic r5, r5, #0x3f
 *   @0x2f1376 adds r2, r6, r5
 *   @0x2f1378 add.w r3, r6, #0x20
 *   @0x2f137c adds r2, #0x20
 *   @0x2f137e bic r3, r3, #0x3f
 *   @0x2f1382 bic r2, r2, #0x3f
 *   @0x2f1386 subs r3, r3, r6
 *   @0x2f1388 subs r2, r2, r6
 *   @0x2f138a eor.w r0, r3, r3, asr #31
 *   @0x2f138e sub.w r0, r0, r3, asr #31
 *   @0x2f1392 subs r2, r2, r5
 *   @0x2f1394 str r5, [r4, #0xc]
 *   @0x2f1396 eor.w r1, r2, r2, asr #31
 *   @0x2f139a sub.w r1, r1, r2, asr #31
 *   @0x2f139e cmp r0, r1
 *   @0x2f13a0 it gt
 *   @0x2f13a2 movgt r3, r2
 *   @0x2f13a4 add r6, r3
 *   @0x2f13a6 str r6, [r4, #0x8]
 *   @0x2f13a8 ldr r2, [sp, #0x10]
 *   @0x2f13aa cbz r2, 0x2f13f0 <FT_Done_Memory+0x777c>
 *   @0x2f13ac ldr r3, [r4, #0xc]
 *   @0x2f13ae ldr r2, [r4, #0x8]
 *   @0x2f13b0 cmp r3, #0x3f
 *   @0x2f13b2 itte gt
 *   @0x2f13b4 addgt r3, #0x20
 *   @0x2f13b6 bicgt r3, r3, #0x3f
 *   @0x2f13ba movle r3, #0x40
 *   @0x2f13bc cmp r7, #0x2
 *   @0x2f13be beq 0x2f13ce <FT_Done_Memory+0x775a>
 *   @0x2f13c0 cmp r7, #0x3
 *   @0x2f13c2 beq 0x2f13f0 <FT_Done_Memory+0x777c>
 *   @0x2f13c4 cmp r7, #0x1
 *   @0x2f13c6 bne 0x2f13d2 <FT_Done_Memory+0x775e>
 *   @0x2f13c8 rsb r2, r3, r9
 *   @0x2f13cc str r2, [r4, #0x8]
 *   @0x2f13ce str r3, [r4, #0xc]
 *   @0x2f13d0 b 0x2f13f0 <FT_Done_Memory+0x777c>
 *   @0x2f13d2 tst.w r3, #0x40
 *   @0x2f13d6 str r3, [r4, #0xc]
 *   @0x2f13d8 asr.w r3, r3, #0x1
 *   @0x2f13dc add r2, r3
 *   @0x2f13de itete ne
 *   @0x2f13e0 bicne r2, r2, #0x3f
 *   @0x2f13e4 addeq r2, #0x20
 *   @0x2f13e6 addne r2, #0x20
 *   @0x2f13e8 biceq r2, r2, #0x3f
 *   @0x2f13ec subs r3, r2, r3
 *   @0x2f13ee str r3, [r4, #0x8]
 *   @0x2f13f0 ldr r3, [r4, #0x10]
 *   @0x2f13f2 orr r3, r3, #0x8
 *   @0x2f13f6 str r3, [r4, #0x10]
 *   @0x2f13f8 add sp, #0x24
 *   @0x2f13fa pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
