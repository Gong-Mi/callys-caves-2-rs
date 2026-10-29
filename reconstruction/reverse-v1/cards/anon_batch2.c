/* cally 逆向卡：匿名段第 2 批（10 段 / 4 个模块）—— anon_batch2
 * 原版 libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        （4,689,844 B，ELF32 ARM，stripped；.text 0xb6fd0..0x31bb7c，627,423 条指令）
 * @card 0x230048 .. 0x2bb8b4（10 个互不相邻的区间，11,988 B / 2,997 条；每节一个 @func 小节，地址各只出现一次）
 * 锚表 asm/index-anon_{25bbb0,25c2f8,25ceac,25db38,230048,230334,28b3fc,2b3f58,2bdb14,2bb3c4}.tsv
 * 级别: 骨架 ——  每节的边界 / 入口契约 / 出口族 / 被调 / 调用点 / 结构偏移 已逐条钉；
 *      块体只钉关键块（循环头、派发表、间接调用、特例块），逐条语义未钉（见每节 open）。
 * 符号 **本卡不取任何符号名**：全部用 anon_<起址>。文中出现的 pcre / vorbis / ogg / spine / jpeg 以及
 *      被调地址旁边的具名符号，一律只作**定位证据**（调用点 + 常数表 + 邻接符号），不是把名字认给它。
 *
 * ══ 选段口径（写死）══════════════════════════════════════════════════════
 * 分母：asm/anon_splits.tsv 共 752 行 = 371 个匿名父区间的切分。其中 142 行 ≤4 B（切分残段，无指令意义），
 *      实段 610 行；≥512 B 的 182 行。
 * 热度：静态 in-degree = bl/blx 落点计数（源段 ≠ 目标段），来自 asm/instructions.jsonl.xz 全量 627,423 条扫描。
 *      没有任何运行期计数（见全局 open 2）。
 * 候选：本卡写入时刻**未被任何卡锚点覆盖**且 ≥512 B 的段共 175 个。按 (in-degree, size) 降序，本批 10 段占
 *      第 1 / 3 / 5 / 7 / 9 / 10 / 13 / 14 / 15 / 21 名（in-degree：5 / 3 / 3 / 3 / 3 / 3 / 3 / 3 / 2 / 3）。
 * 排除：题面点名的 5 段（0x26f1e8 / 0x2a7e2c 组 / 0x268fb4 / 0x2a804c / 0x2a6ff0）在候选集之外。
 * 并发：本卡落盘时同仓库已有别的 agent 写入 cards/anon_batch3.c 等卡。原选段首位 0x21362c（2732 B / 683 条，
 *      MD5 形）已被 anon_batch3.c 锚走同一段 683 条 ⇒ 本卡改为 0x2b3f58，以保持"跨卡共享地址 = 0"。
 * 另刻意跳过 5 个 in-degree 3..4 的 **Thumb-2** 段（0x2a7448 1016 B in=4、0x2e8bdc 1978 B in=3、0x2a7840 1516 B
 *      in=3、0x2e7564 1128 B in=3、0x2e59bc 1032 B in=3）：它们要 asm_index.py --thumb 的另一套解码口径
 *      （README 已记 563 个 Thumb-2 函数曾被 ARM 误解码），留作单独一批，避免同卡混口径。
 * 为何不是"最大的 10 段"：最大的几段（0x26ffac 37860 B、0x25ff54 23556 B…）in-degree 全是 0，是父函数体内的
 *      续段（anon_26f1e8 卡已专门讲过这种情况），把它们当独立函数出卡会重复上一次的错。
 *
 * ══ 分节总表 ═══════════════════════════════════════════════════════════
 *  §   地址        区间               B     条   in-deg  调用点  形态
 *  1   0x25bbb0   0x25bbb0..0x25c26c  1724   431     3      5     完整函数（150 项表 + 2 处自递归）
 *  2   0x25c2f8   0x25c2f8..0x25c5dc   740   185     5      5     完整函数（71 项表 + 16 位大端加数）
 *  3   0x25ceac   0x25ceac..0x25da18  2924   731     3      3     完整函数（73 项表 + 9 条 add pc 取表）
 *  4   0x25db38   0x25db38..0x25df90  1112   278     3      3     完整函数（1..6 字节解码、5 个返回点）
 *  5   0x230048   0x230048..0x230294   588   147     3      3     完整函数 + 1 个段尾独立薄封装
 *  6   0x230334   0x230334..0x230674   832   208     3      3     完整函数（6 参状态机、4 个返回码）
 *  7   0x28b3fc   0x28b3fc..0x28b680   644   161     3      3     完整函数（3 次 malloc + 尾调 free）
 *  8   0x2b3f58   0x2b3f58..0x2b4374  1052   263     3      3     完整函数（17 条间接回调 + 84 B/组件分配）
 *  9   0x2bdb14   0x2bdb14..0x2bdf68  1108   277     2      2     段内 6 个静态函数（5 序言 + 1 自建帧）
 *  10  0x2bb3c4   0x2bb3c4..0x2bb8b4  1264   316     3      3     段内窗口（序言在 +4，首条是 ldr）
 *  合计                             11,988 2,997
 *
 * ══ 进度口径（数字带时刻；仓库里有并发写卡，会漂）══════════════════════════
 *  口径：逐段检查 [start, start+size) 的每条指令是否被 cards/*.c 的 @0x 锚点覆盖。
 *  asm/anon_splits.tsv 共 752 行。本卡落盘时刻：已覆盖 32 行（本卡 10 + 其他卡 22）→ 未处理 720；
 *  最后复核（本卡 10 节校验完成后）：33 / 719 —— 期间又有一张别的卡落盘。
 *      拆开（以 33 那次计）：实段（>4 B）610 行 → 覆盖 31 / 未处理 579；
 *      残段（≤4 B）142 行 → 覆盖 2 / 未处理 140；≥512 B 的 182 行 → 覆盖 18 / 未处理 164。
 *  父区间 371 个：被完整覆盖的仍只有 2 个（0x268fb4、0x319414）；本卡 10 段分属 6 个父区间
 *      （0x25b524 ×4 / 0x22fd0c ×2 / 0x28b34c / 0x2b3f58 / 0x2bdb14 / 0x2bb0f8）。
 *
 * ══ 全局 open ══════════════════════════════════════════════════════════
 *  1. 本批 10 节全部只有静态字节证据（指令锚 + 字段偏移 + 常数表），没有 oracle_anchored / device_anchored 的
 *     运行期对照；一条行为差分都没跑。
 *  2. 热度只有静态 in-degree；经函数指针表间接调用的次数不在分母里（§8 的 17 条 blx、§9 的 [[r0+4]] 四次
 *     间接调用都是例子），所以 in-degree 低的段也可能很热 —— 这是选段口径的已知偏差，不是"不热"的证据。
 *  3. 库身份全部按「调用点 + 常数表 + 邻接符号」三方定位，没有与任何上游源码逐行对照。
 *  4. 本卡没有改名、没有改别人的卡、没有碰设备；只新增本文件与 claims-batchBP.jsonl。
 *
 * ══ 校验（每节单独切出来跑，脚本原样未改）═════════════════════════════════
 *  check_card_anchors.py --card <本节切片> --index asm/index-anon_<起址>.tsv → RESULT EXACT（10/10 节）
 *  合计 2,997 条锚，missing / extra / mismatch 全 0；与其余卡片的 @0x 地址交集为空。
 */


/* ════════════════════════════════════════════════════════════════════
 * §1  anon_25bbb0   0x25bbb0 .. 0x25c26c   1,724 B / 431 条   in-degree 3，调用点 5
 * 按操作码长度表前进的递归扫描循环（150 项跳转表、2 处自递归）
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段是**完整函数**（0x25bbb0 push 带 lr，2 个 pop 返回点），窗口内 0 条分支跳出。
 * 入口：r0 = 码流指针（0x25bbcc ldrb r12,[r0]），r1 = 上限（0x25bbe8 cmp r0,r7），r2 = 0/1 标志（r9），
 *   r3 = 上下文指针（r8）。
 * GOT 相对取表：0x25bbb8 / 0x25bbc0 两条 `ldr rX,[pc,#imm]` + 0x25bbc8 `add r10,pc,r10` 物化表基；
 *   0x25bbd8 `ldr r6,[r10,lr]` 取长度表，0x25bbdc `ldrb r3,[r6,r12]` 按当前字节取操作码长度，
 *   0x25bbe0 `add r0,r0,r3` 前进 —— 与 anon_26f1e8 卡里 _pcre_OP_lengths 的用法同构。
 * 出口：2 个（0x25bd1c、0x25bf1c，都是 pop {r4..r11,pc}）。
 * 递归：0x25bcc8 / 0x25be9c 两次 bl 自身；0x25bbe4 / 0x25bd04 两次 bl 0x25b524（同父区间首函数）。
 * 跳转表：0x25bf28 `sub r2,r3,#6` + 0x25bf2c `cmp r2,#149` + 0x25bf30 `addls pc,pc,r2,lsl #2`
 *   ⇒ 150 项，表在 0x25bf38..0x25c188（表项 in-line，绝大多数直接回 0x25bf14）。
 * 字面量池：0x25c264 = 0xfffffb8c、0x25c268 = 0xfffffb90（objdump 译成 andseq，实为 GOT 槽偏移，非指令）。
 * 热块：0x25c1bc（60 条入边）/ 0x25bf14（45）/ 0x25c230（24）—— 循环头与「回退重扫」入口。
 * 被调合计 4 条 bl：自身 ×2、0x25b524 ×2；无 blx / 无函数指针。
 * 谁调它：5 处 —— 3 处外部（0x263298、0x2648b8 都在 anon_25fe2c 体内；0x268884 在 pcre_compile2 体内）
 *   + 2 处自递归（0x25bcc8、0x25be9c）。「5 处引用」里 40% 是自递归，不能当热度用。
 *   0x268884（pcre_compile2 体内），另 2 处 0x25bcc8/0x25be9c 是自递归。
 * open：
 *   1. 递归进入的「组/分支」语义未逐块钉：只知道递归点在 0x25bcc8 与 0x25be9c，且递归前重算了 r4/r7/r9。
 *   2. 150 项目标块里只钉了 4 个（回循环头 / 两条特殊字节 '}' 'u' / 一处 3 字节跳过），其余未逐个解释。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x25bbb0 0x25c26c anon_25bbb0 */
/* @0x25bbb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言（保存 9 个寄存器） */
/* @0x25bbb4 mov r8, r3 */
/* @0x25bbb8 ldr r10, [pc, #0x6a0] */
/* @0x25bbbc sub sp, sp, #28 */
/* @0x25bbc0 ldr lr, [pc, #0x69c] */
/* @0x25bbc4 mov r7, r1 */
/* @0x25bbc8 add r10, pc, r10 —— 跳转表派发（表项 in-line） */
/* @0x25bbcc ldrb r12, [r0] */
/* @0x25bbd0 mov r1, #1 */
/* @0x25bbd4 mov r9, r2 */
/* @0x25bbd8 ldr r6, [r10, lr] */
/* @0x25bbdc ldrb r3, [r6, r12] */
/* @0x25bbe0 add r0, r0, r3 */
/* @0x25bbe4 bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> —— 调 anon_25b524 */
/* @0x25bbe8 cmp r0, r7 */
/* @0x25bbec mov r4, r0 */
/* @0x25bbf0 addlo r1, sp, #16 */
/* @0x25bbf4 strlo r10, [sp, #0xc] */
/* @0x25bbf8 strlo r1, [sp, #0x8] */
/* @0x25bbfc bhs 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bc00 ldrb r3, [r4] */
/* @0x25bc04 cmp r3, #125 */
/* @0x25bc08 beq 0x25bd20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbf8> */
/* @0x25bc0c cmp r3, #117 */
/* @0x25bc10 beq 0x25bd7c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc54> */
/* @0x25bc14 add r2, r3, #110 */
/* @0x25bc18 uxtb r2, r2 */
/* @0x25bc1c cmp r3, #161 */
/* @0x25bc20 cmpne r2, #2 */
/* @0x25bc24 bls 0x25bd58 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc30> */
/* @0x25bc28 add r2, r3, #120 */
/* @0x25bc2c uxtb r2, r2 */
/* @0x25bc30 cmp r2, #3 */
/* @0x25bc34 bls 0x25bd3c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc14> */
/* @0x25bc38 add r2, r3, #127 */
/* @0x25bc3c uxtb r2, r2 */
/* @0x25bc40 cmp r2, #6 */
/* @0x25bc44 bhi 0x25bf20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdf8> */
/* @0x25bc48 ldrb r5, [r4, #0x1] */
/* @0x25bc4c ldrb r11, [r4, #0x2] */
/* @0x25bc50 orrs r2, r11, r5, lsl #8 */
/* @0x25bc54 beq 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bc58 cmp r3, #135 */
/* @0x25bc5c beq 0x25c190 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1068> */
/* @0x25bc60 ldrb r10, [r4, r2] */
/* @0x25bc64 mov r3, r6 */
/* @0x25bc68 lsl r5, r5, #8 */
/* @0x25bc6c mov r6, r10 */
/* @0x25bc70 mov r0, #0 */
/* @0x25bc74 mov r10, r3 */
/* @0x25bc78 b 0x25bca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb78> */
/* @0x25bc7c cmp r6, #119 */
/* @0x25bc80 orr r11, r5, r11 */
/* @0x25bc84 add r4, r4, r11 */
/* @0x25bc88 bne 0x25bce0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbb8> */
/* @0x25bc8c ldrb r5, [r4, #0x1] */
/* @0x25bc90 ldrb r11, [r4, #0x2] */
/* @0x25bc94 lsl r5, r5, #8 */
/* @0x25bc98 orr r3, r5, r11 */
/* @0x25bc9c ldrb r6, [r4, r3] */
/* @0x25bca0 cmp r0, #0 */
/* @0x25bca4 mov r0, #1 */
/* @0x25bca8 bne 0x25bc7c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb54> */
/* @0x25bcac ldr r2, [sp, #0x40] —— 栈槽 */
/* @0x25bcb0 mov r0, r4 */
/* @0x25bcb4 mov r1, r7 */
/* @0x25bcb8 mov r3, r8 */
/* @0x25bcbc orr r11, r5, r11 */
/* @0x25bcc0 str r2, [sp] —— 栈槽 */
/* @0x25bcc4 mov r2, r9 */
/* @0x25bcc8 bl 0x25bbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa88> —— 调 anon_25bbb0 */
/* @0x25bccc add r4, r4, r11 */
/* @0x25bcd0 adds r0, r0, #0 */
/* @0x25bcd4 movne r0, #1 */
/* @0x25bcd8 cmp r6, #119 */
/* @0x25bcdc beq 0x25bc8c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb64> */
/* @0x25bce0 cmp r0, #0 */
/* @0x25bce4 mov r3, r10 */
/* @0x25bce8 mov r10, r6 */
/* @0x25bcec mov r6, r3 */
/* @0x25bcf0 beq 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bcf4 mov r12, r10 */
/* @0x25bcf8 ldrb r0, [r6, r12] */
/* @0x25bcfc mov r1, #1 */
/* @0x25bd00 add r0, r4, r0 */
/* @0x25bd04 bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> —— 调 anon_25b524 */
/* @0x25bd08 cmp r7, r0 */
/* @0x25bd0c mov r4, r0 */
/* @0x25bd10 bhi 0x25bc00 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xad8> */
/* @0x25bd14 mov r0, #1 */
/* @0x25bd18 add sp, sp, #28 */
/* @0x25bd1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 拆帧/返回 */
/* @0x25bd20 ldrb r2, [r4, #0x1] */
/* @0x25bd24 ldrb r3, [r4, #0x2] */
/* @0x25bd28 orr r3, r3, r2, lsl #8 */
/* @0x25bd2c ldrb r12, [r4, r3]! */
/* @0x25bd30 cmp r12, #119 */
/* @0x25bd34 beq 0x25bd20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbf8> */
/* @0x25bd38 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25bd3c ldrb r2, [r4, #0x1] */
/* @0x25bd40 ldrb r3, [r4, #0x2] */
/* @0x25bd44 orr r3, r3, r2, lsl #8 */
/* @0x25bd48 ldrb r12, [r4, r3]! */
/* @0x25bd4c cmp r12, #119 */
/* @0x25bd50 beq 0x25bd3c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc14> */
/* @0x25bd54 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25bd58 ldrb r3, [r6, r3] */
/* @0x25bd5c add r4, r4, r3 */
/* @0x25bd60 ldrb r2, [r4, #0x1] */
/* @0x25bd64 ldrb r3, [r4, #0x2] */
/* @0x25bd68 orr r3, r3, r2, lsl #8 */
/* @0x25bd6c ldrb r12, [r4, r3]! */
/* @0x25bd70 cmp r12, #119 */
/* @0x25bd74 beq 0x25bd60 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc38> */
/* @0x25bd78 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25bd7c ldrb r11, [r4, #0x1] */
/* @0x25bd80 ldr r12, [r8, #0x10] */
/* @0x25bd84 ldrb r2, [r4, #0x2] */
/* @0x25bd88 ldr r3, [r8, #0x14] */
/* @0x25bd8c cmp r12, #0 */
/* @0x25bd90 orr r11, r2, r11, lsl #8 */
/* @0x25bd94 add r11, r3, r11 */
/* @0x25bd98 beq 0x25beb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd88> */
/* @0x25bd9c ldr r5, [r8, #0x20] */
/* @0x25bda0 cmp r12, r5 */
/* @0x25bda4 bhs 0x25bde8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xcc0> */
/* @0x25bda8 ldrb r1, [r12] */
/* @0x25bdac add r0, r4, #1 */
/* @0x25bdb0 ldrb r2, [r12, #0x1] */
/* @0x25bdb4 rsb r3, r3, r0 */
/* @0x25bdb8 orr r2, r2, r1, lsl #8 */
/* @0x25bdbc cmp r2, r3 */
/* @0x25bdc0 bne 0x25bddc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xcb4> */
/* @0x25bdc4 b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bdc8 ldrb r1, [r12] */
/* @0x25bdcc ldrb r2, [r12, #0x1] */
/* @0x25bdd0 orr r2, r2, r1, lsl #8 */
/* @0x25bdd4 cmp r2, r3 */
/* @0x25bdd8 beq 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bddc add r12, r12, #2 */
/* @0x25bde0 cmp r12, r5 */
/* @0x25bde4 blo 0x25bdc8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xca0> */
/* @0x25bde8 ldrb r2, [r11, #0x1] */
/* @0x25bdec ldrb r1, [r11, #0x2] */
/* @0x25bdf0 orrs r3, r1, r2, lsl #8 */
/* @0x25bdf4 beq 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bdf8 mov r3, r11 */
/* @0x25bdfc b 0x25be08 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xce0> */
/* @0x25be00 ldrb r2, [r3, #0x1] */
/* @0x25be04 ldrb r1, [r3, #0x2] */
/* @0x25be08 orr r2, r1, r2, lsl #8 */
/* @0x25be0c ldrb r2, [r3, r2]! */
/* @0x25be10 cmp r2, #119 */
/* @0x25be14 beq 0x25be00 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xcd8> */
/* @0x25be18 cmp r3, r4 */
/* @0x25be1c cmphs r4, r11 */
/* @0x25be20 bhs 0x25bea8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd80> */
/* @0x25be24 ldr r1, [sp, #0x40] —— 栈槽 */
/* @0x25be28 cmp r1, #0 */
/* @0x25be2c beq 0x25be5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd34> */
/* @0x25be30 ldr r3, [r1, #0x4] */
/* @0x25be34 cmp r3, r11 */
/* @0x25be38 beq 0x25bea8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd80> */
/* @0x25be3c mov r3, r1 */
/* @0x25be40 b 0x25be50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd28> */
/* @0x25be44 ldr r2, [r3, #0x4] */
/* @0x25be48 cmp r2, r11 */
/* @0x25be4c beq 0x25bea8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd80> */
/* @0x25be50 ldr r3, [r3] */
/* @0x25be54 cmp r3, #0 */
/* @0x25be58 bne 0x25be44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd1c> */
/* @0x25be5c ldr r2, [sp, #0x40] —— 栈槽 */
/* @0x25be60 add r5, sp, #16 */
/* @0x25be64 str r11, [sp, #0x14] —— 栈槽 */
/* @0x25be68 str r2, [sp, #0x10] —— 栈槽 */
/* @0x25be6c b 0x25be88 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd60> */
/* @0x25be70 ldrb r2, [r11, #0x1] */
/* @0x25be74 ldrb r3, [r11, #0x2] */
/* @0x25be78 orr r3, r3, r2, lsl #8 */
/* @0x25be7c ldrb r0, [r11, r3]! */
/* @0x25be80 cmp r0, #119 */
/* @0x25be84 bne 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25be88 str r5, [sp] —— 栈槽 */
/* @0x25be8c mov r0, r11 */
/* @0x25be90 mov r1, r7 */
/* @0x25be94 mov r2, r9 */
/* @0x25be98 mov r3, r8 */
/* @0x25be9c bl 0x25bbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa88> —— 调 anon_25bbb0 */
/* @0x25bea0 cmp r0, #0 */
/* @0x25bea4 beq 0x25be70 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd48> */
/* @0x25bea8 mov r12, #117 */
/* @0x25beac b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25beb0 ldrb r2, [r11, #0x1] */
/* @0x25beb4 ldrb r1, [r11, #0x2] */
/* @0x25beb8 b 0x25bdf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xcd0> */
/* @0x25bebc ldrb r1, [r4, #0x1] */
/* @0x25bec0 ldrb r2, [r4, #0x2] */
/* @0x25bec4 orr r2, r2, r1, lsl #8 */
/* @0x25bec8 add r4, r4, r2 */
/* @0x25becc mov r2, r4 */
/* @0x25bed0 ldrb r0, [r2] */
/* @0x25bed4 sub r0, r0, #98 */
/* @0x25bed8 uxtb r0, r0 */
/* @0x25bedc cmp r0, #11 */
/* @0x25bee0 bhi 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bee4 mov r1, #1 */
/* @0x25bee8 lsl r0, r1, r0 */
/* @0x25beec movw r1, #0x533 —— 32 位常数半字 */
/* @0x25bef0 and r1, r0, r1 */
/* @0x25bef4 cmp r1, #0 */
/* @0x25bef8 bne 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25befc tst r0, #2240 */
/* @0x25bf00 beq 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf04 ldrb r1, [r2, #0x1] */
/* @0x25bf08 ldrb r2, [r2, #0x2] */
/* @0x25bf0c orrs r2, r2, r1, lsl #8 */
/* @0x25bf10 beq 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf14 mov r0, #0 */
/* @0x25bf18 add sp, sp, #28 */
/* @0x25bf1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 拆帧/返回 */
/* @0x25bf20 cmp r3, #140 */
/* @0x25bf24 beq 0x25c248 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1120> */
/* @0x25bf28 sub r2, r3, #6 */
/* @0x25bf2c cmp r2, #149 */
/* @0x25bf30 addls pc, pc, r2, lsl #2 —— 跳转表派发（表项 in-line） */
/* @0x25bf34 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf38 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf3c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf40 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf44 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf48 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf4c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf50 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf54 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf58 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf5c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf60 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf64 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf68 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf6c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf70 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf74 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf78 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf7c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf80 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf84 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf88 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf8c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf90 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf94 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf98 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf9c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfa0 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfa4 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfa8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfac b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfb0 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfb4 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfb8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfbc b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bfc0 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bfc4 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfc8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfcc b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfd0 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfd4 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bfd8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfdc b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfe0 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfe4 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfe8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfec b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bff0 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bff4 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bff8 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bffc b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c000 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c004 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c008 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c00c b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c010 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c014 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c018 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c01c b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c020 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c024 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c028 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c02c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c030 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c034 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c038 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c03c b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c040 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c044 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c048 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c04c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c050 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c054 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c058 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c05c b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c060 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c064 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c068 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c06c b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c070 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c074 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c078 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c07c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c080 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c084 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c088 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c08c b 0x25c1dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10b4> */
/* @0x25c090 b 0x25c1dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10b4> */
/* @0x25c094 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c098 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c09c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c0a0 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c0a4 b 0x25c1dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10b4> */
/* @0x25c0a8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0ac b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0b0 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0b4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0b8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0bc b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0c0 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0c4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0c8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0cc b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0d0 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0d4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0d8 b 0x25c1d4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10ac> */
/* @0x25c0dc b 0x25c1d4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10ac> */
/* @0x25c0e0 b 0x25bebc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd94> */
/* @0x25c0e4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0e8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0ec b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0f0 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0f4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0f8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0fc b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c100 b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c104 b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c108 b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c10c b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c110 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c114 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c118 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c11c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c120 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c124 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c128 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c12c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c130 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c134 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c138 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c13c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c140 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c144 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c148 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c14c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c150 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c154 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c158 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c15c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c160 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c164 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c168 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c16c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c170 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c174 b 0x25c1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x109c> */
/* @0x25c178 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c17c b 0x25c1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x109c> */
/* @0x25c180 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c184 b 0x25c1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x109c> */
/* @0x25c188 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c18c b 0x25c1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x109c> */
/* @0x25c190 ldrb r12, [r4, r2] */
/* @0x25c194 add r2, r4, r2 */
/* @0x25c198 cmp r12, #119 */
/* @0x25c19c mov r10, r12 */
/* @0x25c1a0 movne r4, r2 */
/* @0x25c1a4 bne 0x25bcf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbcc> */
/* @0x25c1a8 b 0x25bc64 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb3c> */
/* @0x25c1ac ldrb r2, [r4, #0x1] */
/* @0x25c1b0 sub r2, r2, #15 */
/* @0x25c1b4 cmp r2, #1 */
/* @0x25c1b8 bls 0x25c1ec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10c4> */
/* @0x25c1bc mov r12, r3 */
/* @0x25c1c0 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25c1c4 ldrb r2, [r4, #0x1] */
/* @0x25c1c8 mov r12, r3 */
/* @0x25c1cc add r4, r4, r2 */
/* @0x25c1d0 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25c1d4 add r2, r4, #33 */
/* @0x25c1d8 b 0x25bed0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xda8> */
/* @0x25c1dc ldrb r2, [r4, #0x3] */
/* @0x25c1e0 sub r2, r2, #15 */
/* @0x25c1e4 cmp r2, #1 */
/* @0x25c1e8 bhi 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c1ec add r4, r4, #2 */
/* @0x25c1f0 mov r12, r3 */
/* @0x25c1f4 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25c1f8 cmp r9, #0 */
/* @0x25c1fc beq 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c200 ldrb r2, [r4, #0x3] */
/* @0x25c204 cmp r2, #191 */
/* @0x25c208 bls 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c20c ldr r1, [pc, #0x54] */
/* @0x25c210 mov r12, r3 */
/* @0x25c214 and r2, r2, #63 */
/* @0x25c218 mov r3, r1 */
/* @0x25c21c ldr r1, [sp, #0xc] —— 栈槽 */
/* @0x25c220 ldr r3, [r1, r3] */
/* @0x25c224 ldrb r3, [r3, r2] */
/* @0x25c228 add r4, r4, r3 */
/* @0x25c22c b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25c230 cmp r9, #0 */
/* @0x25c234 beq 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c238 ldrb r2, [r4, #0x1] */
/* @0x25c23c cmp r2, #191 */
/* @0x25c240 bhi 0x25c20c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10e4> */
/* @0x25c244 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c248 ldrb r5, [r4, #0x1] */
/* @0x25c24c ldrb r11, [r4, #0x2] */
/* @0x25c250 orrs r3, r11, r5, lsl #8 */
/* @0x25c254 beq 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c258 ldrb r10, [r4, r3] */
/* @0x25c25c b 0x25bc64 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb3c> */
/* @0x25c260 andseq r6, r9, r8, lsl #1 */
/* @0x25c264 .word 0xfffffb8c —— 非指令：字面量池/表项 */
/* @0x25c268 .word 0xfffffb90 —— 非指令：字面量池/表项 */

/* ════════════════════════════════════════════════════════════════════
 * §2  anon_25c2f8   0x25c2f8 .. 0x25c5dc   740 B / 185 条   in-degree 5，调用点 5
 * 编译后模式上的 16 位大端偏移加数器（71 项分派 + 3 张扫描块）
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段是**完整函数**（0x25c2f8 push 不带 lr ⇒ 无调用；0x25c4fc pop + 0x25c500 bx lr）。窗口内 0 条外跳。
 * 入口（5 参，第 5 个在栈上）：r0 = 模式字节流指针（r4），r1 = 要加的 16 位增量（0x25c4bc uxtb r5,r1 取低字节），
 *   r2 = UTF-8 标志（0x25c464 cmp r2,#0 决定是否走续字节映射），r3 = 只读描述符
 *   {+0x10 游标起点、+0x14 二段扫描基址、+0x20 游标终点}，[sp+0x20] = 加到 +0x10 上的偏移（r7，5 参）。
 * 两个阶段：
 *   阶段 A（0x25c310..0x25c4ac）按字符步进：`ldrb r12,[r4]` → 0 结束；'u'(117) / 'p'(112) 走特例块；
 *     其余先 `sub r5,r12,#85` + `cmp r5,#70` + 0x25c334 `addls pc,pc,r5,lsl #2` 做 71 项分派；
 *     0x25c460 用 GOT 基址表 + `ldrb r5,[r5,r12]` 取每字符字节数并 `add r4,r4,r5`；UTF-8 模式下再补
 *     续字节修正（0x25c484 取 [r4,#-1]，>191 时用 &63 表，0x25c49c）。
 *   阶段 B（0x25c4b4..0x25c4fc）把 [r8,r6) 里每个 16 位**大端**字加上 r1：
 *     0x25c4c4/0x25c4cc 取两字节 → 0x25c4d0 orr 拼大端 → 0x25c4d4 add 增量 → 0x25c4dc asr #8 →
 *     0x25c4e0/0x25c4e4 两字节写回，r8 每次 +2，直到 r8 >= [r3+0x20]。
 * 第三块：0x25c540..0x25c5c8 只在首字节 == 'u' 时走：以 [r3+0x14] 为基址线性扫描 16 位大端键
 *   （0x25c574..0x25c594：ldrb 两字节 → orr 拼大端 → add base → cmp r10）；命中则 0x25c5cc 直接 r4 += 3；
  未命中则在 0x25c598 把 r4+1 处的 16 位大端值加 r1 写回（0x25c5b0/0x25c5bc），并从 [r3+0x10] 重算游标。
 * 出口：唯一 0x25c4fc pop / 0x25c500 bx lr；返回值未设置（r0 在阶段 B 里是临时指针）。
 * 被调：0 条。谁调它：5 处，全部在 anon_25fe2c 体内（0x2611d0 / 0x2618b0 / 0x261b34 / 0x264910 / 0x264ed4）。
 * open：
 *   1. 增量 r1 的来源与量纲（字节数？字符数？）未钉；只证它被加进 16 位大端字段。
 *   2. 71 项分派表里各分支只钉了 4 类（'u' 特例、'p' 特例、两处 2 字节跳过、默认），其余未逐个解释。
 *   3. [r3+0x14] 那段键表装的是什么（偏移表？分支表？）未钉。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x25c2f8 0x25c5dc anon_25c2f8 */
/* @0x25c2f8 push {r4, r5, r6, r7, r8, r9, r10, r11} —— 序言（保存 8 个寄存器） */
/* @0x25c2fc mov r4, r0 */
/* @0x25c300 ldr r7, [sp, #0x20] —— 栈槽 */
/* @0x25c304 ldr r8, [r3, #0x10] */
/* @0x25c308 ldr r6, [r3, #0x20] */
/* @0x25c30c add r8, r8, r7 */
/* @0x25c310 ldrb r12, [r4] */
/* @0x25c314 cmp r12, #0 */
/* @0x25c318 beq 0x25c4b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1388> */
/* @0x25c31c cmp r12, #117 */
/* @0x25c320 beq 0x25c540 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1418> */
/* @0x25c324 cmp r12, #112 */
/* @0x25c328 beq 0x25c52c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1404> */
/* @0x25c32c sub r5, r12, #85 */
/* @0x25c330 cmp r5, #70 */
/* @0x25c334 addls pc, pc, r5, lsl #2 —— 跳转表派发（表项 in-line） */
/* @0x25c338 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c33c b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c340 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c344 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c348 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c34c b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c350 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c354 b 0x25c504 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13dc> */
/* @0x25c358 b 0x25c504 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13dc> */
/* @0x25c35c b 0x25c504 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13dc> */
/* @0x25c360 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c364 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c368 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c36c b 0x25c504 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13dc> */
/* @0x25c370 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c374 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c378 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c37c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c380 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c384 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c388 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c38c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c390 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c394 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c398 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c39c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3a0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3a4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3a8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3ac b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3b0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3b4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3b8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3bc b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3c0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3c4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3c8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3cc b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3d0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3d4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3d8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3dc b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3e0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3e4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3e8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3ec b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3f0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3f4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3f8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3fc b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c400 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c404 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c408 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c40c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c410 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c414 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c418 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c41c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c420 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c424 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c428 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c42c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c430 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c434 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c438 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c43c b 0x25c458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1330> */
/* @0x25c440 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c444 b 0x25c458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1330> */
/* @0x25c448 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c44c b 0x25c458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1330> */
/* @0x25c450 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c454 b 0x25c458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1330> */
/* @0x25c458 ldrb r5, [r4, #0x1] */
/* @0x25c45c add r4, r4, r5 */
/* @0x25c460 ldr r5, [pc, #0x16c] */
/* @0x25c464 cmp r2, #0 */
/* @0x25c468 ldr r5, [pc, r5] */
/* @0x25c46c ldrb r5, [r5, r12] */
/* @0x25c470 add r4, r4, r5 */
/* @0x25c474 beq 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c478 sub r12, r12, #29 */
/* @0x25c47c cmp r12, #55 */
/* @0x25c480 bhi 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c484 ldrb r12, [r4, #-0x1] */
/* @0x25c488 cmp r12, #191 */
/* @0x25c48c bls 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c490 ldr r5, [pc, #0x140] */
/* @0x25c494 and r12, r12, #63 */
/* @0x25c498 ldr r5, [pc, r5] */
/* @0x25c49c ldrb r12, [r5, r12] */
/* @0x25c4a0 add r4, r4, r12 */
/* @0x25c4a4 ldrb r12, [r4] */
/* @0x25c4a8 cmp r12, #0 */
/* @0x25c4ac bne 0x25c31c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11f4> */
/* @0x25c4b0 cmp r8, r6 */
/* @0x25c4b4 bhs 0x25c4fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13d4> */
/* @0x25c4b8 add r2, r8, #2 */
/* @0x25c4bc uxtb r5, r1 */
/* @0x25c4c0 mov r0, r2 */
/* @0x25c4c4 ldrb r4, [r0, #-0x2] */
/* @0x25c4c8 add r0, r0, #2 */
/* @0x25c4cc ldrb r12, [r8, #0x1] */
/* @0x25c4d0 orr r12, r12, r4, lsl #8 */
/* @0x25c4d4 add r4, r12, r1 */
/* @0x25c4d8 add r12, r5, r12 */
/* @0x25c4dc asr r4, r4, #8 */
/* @0x25c4e0 strb r4, [r0, #-0x4] */
/* @0x25c4e4 strb r12, [r8, #0x1] */
/* @0x25c4e8 mov r8, r2 */
/* @0x25c4ec ldr r12, [r3, #0x20] */
/* @0x25c4f0 cmp r12, r2 */
/* @0x25c4f4 add r2, r2, #2 */
/* @0x25c4f8 bhi 0x25c4c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x139c> */
/* @0x25c4fc pop {r4, r5, r6, r7, r8, r9, r10, r11} —— 拆帧（随后 bx lr） */
/* @0x25c500 bx lr —— 返回 */
/* @0x25c504 ldrb r5, [r4, #0x3] */
/* @0x25c508 sub r5, r5, #15 */
/* @0x25c50c cmp r5, #1 */
/* @0x25c510 addls r4, r4, #2 */
/* @0x25c514 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c518 ldrb r5, [r4, #0x1] */
/* @0x25c51c sub r5, r5, #15 */
/* @0x25c520 cmp r5, #1 */
/* @0x25c524 addls r4, r4, #2 */
/* @0x25c528 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c52c ldrb r5, [r4, #0x1] */
/* @0x25c530 ldrb r12, [r4, #0x2] */
/* @0x25c534 orr r12, r12, r5, lsl #8 */
/* @0x25c538 add r4, r4, r12 */
/* @0x25c53c b 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c540 cmp r8, r6 */
/* @0x25c544 mov r12, r8 */
/* @0x25c548 ldrhs r9, [r3, #0x14] */
/* @0x25c54c bhs 0x25c598 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1470> */
/* @0x25c550 ldrb r11, [r8] */
/* @0x25c554 add r10, r4, #1 */
/* @0x25c558 ldrb r5, [r8, #0x1] */
/* @0x25c55c ldr r9, [r3, #0x14] */
/* @0x25c560 orr r5, r5, r11, lsl #8 */
/* @0x25c564 add r5, r9, r5 */
/* @0x25c568 cmp r10, r5 */
/* @0x25c56c bne 0x25c58c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1464> */
/* @0x25c570 b 0x25c5cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14a4> */
/* @0x25c574 ldrb r11, [r12] */
/* @0x25c578 ldrb r5, [r12, #0x1] */
/* @0x25c57c orr r5, r5, r11, lsl #8 */
/* @0x25c580 add r5, r9, r5 */
/* @0x25c584 cmp r10, r5 */
/* @0x25c588 beq 0x25c5cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14a4> */
/* @0x25c58c add r12, r12, #2 */
/* @0x25c590 cmp r12, r6 */
/* @0x25c594 blo 0x25c574 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x144c> */
/* @0x25c598 ldrb r5, [r4, #0x1] */
/* @0x25c59c ldrb r12, [r4, #0x2] */
/* @0x25c5a0 orr r12, r12, r5, lsl #8 */
/* @0x25c5a4 add r9, r9, r12 */
/* @0x25c5a8 cmp r0, r9 */
/* @0x25c5ac bhi 0x25c5cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14a4> */
/* @0x25c5b0 add r12, r12, r1 */
/* @0x25c5b4 strb r12, [r4, #0x2] */
/* @0x25c5b8 asr r12, r12, #8 */
/* @0x25c5bc strb r12, [r4, #0x1] */
/* @0x25c5c0 ldr r8, [r3, #0x10] */
/* @0x25c5c4 ldr r6, [r3, #0x20] */
/* @0x25c5c8 add r8, r8, r7 */
/* @0x25c5cc add r4, r4, #3 */
/* @0x25c5d0 b 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c5d4 andseq r5, r9, r4, ror r3 */
/* @0x25c5d8 andseq r5, r9, r8, asr #6 */

/* ════════════════════════════════════════════════════════════════════
 * §3  anon_25ceac   0x25ceac .. 0x25da18   2,924 B / 731 条   in-degree 3，调用点 3
 * 反斜杠转义项解码器（73 项分派、+0x98 类型位表、三出参）
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段是**完整函数**（0x25ceac 序言带 lr，唯一返回点 0x25cf3c pop {r4..r11,pc}），0 条外跳。
 * 入口：r0 = &游标（0x25ceb8 先解引用一次），r1 = *value 出参，r2 = *errcode 出参，r3 在本窗口内未见读取，
 *   第 7 参 [sp+0x38] = flags：bit11 = UTF-8（0x25cec4 ubfx r12,r6,#11,#1），
 *   bit29 = 0x20000000（0x25cf18 tst r6,#536870912）决定 6..11 号码点是否 +23（0x25cf20..0x25cf28）。
 * 出参写回：*[r7] = 新游标（0x25cf2c）、*r1 = 值（0x25cf34）、*r2 = 错误码（0x25cf14 写 1）；
 *   返回 r0 = 值（早退路径 r0 = 0）。
 * 派发：0x25cfb8 `cmp r10,#72` + 0x25cfbc `addls pc,pc,r10,lsl #2` ⇒ 73 项；另有 8 处
 *   `add rX,pc,rX` 的 GOT 相对表基（0x25cf9c / 0x25d1dc / 0x25d254 / 0x25d550 / 0x25d58c / 0x25d708 / 0x25d8d0 / 0x25d984），
 *   每处随后都是 `ldrb r3,[r3,#0x98]` + `and #8`（同一张 256 项类型表的 +0x98 段）。
 * 字符解码：2 字节在 0x25cee8（`tst #32`）+ 0x25cf54（`tst #16`/`#8` 分出 4/5/6 字节）；3 字节在 0x25cf64 起；
  数码/转义表在 0x25cf94（`ldrsh`，2 B/项，索引 = 转义字符-48，`cmp #74` ⇒ 75 项）；\x{..} 形态的
 *   十六进制聚合在 0x25d750 起，掩码 0x0000ffff/0x100000 由 0x25d704..0x25d710 的 movw/movt 拼出。
 * 出口族：唯一 pop 返回点，但前置 setjmp 式早退有 9 个（0x25cf28 前后、0x25cfb8、0x25d1f0、0x25d264、
 *   0x25d560、0x25d680、0x25d978、0x25d994、0x25da10 一带），全部落到 0x25cf18 或 0x25cf40 的公共收尾。
 * 被调：唯一 bl 0x25d528 → 0x25ce14（同父区间的前一函数，未出卡）。
 * 谁调它：3 处，全部在 anon_25fe2c 体内（0x260a8c / 0x2625a0 / 0x264438）。
 * open：
 *   1. 73 项派发里只有 '}'(125) / 'u'(117) / 0x8F.. 三类被单独钉住，其余 case 体只做结构标注。
 *   2. r3 实参在窗口内没有被读过（既没存栈也没解引用）—— 第 4 参是否被用、还是调用约定留位，未钉。
 *   3. *r2 只证「写 1」，错误码其余取值空间未枚举。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x25ceac 0x25da18 anon_25ceac */
/* @0x25ceac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言（保存 9 个寄存器） */
/* @0x25ceb0 mov r7, r0 */
/* @0x25ceb4 sub sp, sp, #20 */
/* @0x25ceb8 ldr r0, [r0] */
/* @0x25cebc ldr r6, [sp, #0x38] —— 栈槽 */
/* @0x25cec0 ldrb r4, [r0, #0x1] */
/* @0x25cec4 ubfx r12, r6, #0xb, #0x1 */
/* @0x25cec8 cmp r4, #191 */
/* @0x25cecc movls r5, #0 */
/* @0x25ced0 andhi r5, r12, #1 */
/* @0x25ced4 cmp r5, #0 */
/* @0x25ced8 addeq r9, r0, #2 */
/* @0x25cedc beq 0x25cefc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1dd4> */
/* @0x25cee0 tst r4, #32 */
/* @0x25cee4 bne 0x25cf54 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e2c> */
/* @0x25cee8 ldrb r5, [r0, #0x2] */
/* @0x25ceec and r4, r4, #31 */
/* @0x25cef0 add r9, r0, #3 */
/* @0x25cef4 and r0, r5, #63 */
/* @0x25cef8 orr r4, r0, r4, lsl #6 */
/* @0x25cefc sub r5, r9, #1 */
/* @0x25cf00 cmp r4, #0 */
/* @0x25cf04 mov r11, r5 */
/* @0x25cf08 bne 0x25cf40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e18> */
/* @0x25cf0c mov r8, r4 */
/* @0x25cf10 mov r3, #1 */
/* @0x25cf14 str r3, [r2] */
/* @0x25cf18 tst r6, #536870912 */
/* @0x25cf1c beq 0x25cf2c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e04> */
/* @0x25cf20 sub r3, r8, #6 */
/* @0x25cf24 cmp r3, #5 */
/* @0x25cf28 addls r8, r8, #23 */
/* @0x25cf2c str r5, [r7] */
/* @0x25cf30 mov r0, r8 */
/* @0x25cf34 str r4, [r1] */
/* @0x25cf38 add sp, sp, #20 */
/* @0x25cf3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 拆帧/返回 */
/* @0x25cf40 sub r10, r4, #48 */
/* @0x25cf44 cmp r10, #74 */
/* @0x25cf48 bls 0x25cf94 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e6c> */
/* @0x25cf4c mov r8, #0 */
/* @0x25cf50 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25cf54 tst r4, #16 */
/* @0x25cf58 beq 0x25d0e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1fc0> */
/* @0x25cf5c tst r4, #8 */
/* @0x25cf60 bne 0x25d110 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1fe8> */
/* @0x25cf64 ldrb r8, [r0, #0x4] */
/* @0x25cf68 and r10, r4, #7 */
/* @0x25cf6c ldrb r5, [r0, #0x2] */
/* @0x25cf70 add r9, r0, #5 */
/* @0x25cf74 ldrb r4, [r0, #0x3] */
/* @0x25cf78 and r8, r8, #63 */
/* @0x25cf7c and r5, r5, #63 */
/* @0x25cf80 orr r0, r8, r10, lsl #18 */
/* @0x25cf84 and r4, r4, #63 */
/* @0x25cf88 orr r0, r0, r5, lsl #12 */
/* @0x25cf8c orr r4, r0, r4, lsl #6 */
/* @0x25cf90 b 0x25cefc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1dd4> */
/* @0x25cf94 ldr r8, [pc, #0xa5c] */
/* @0x25cf98 lsl r0, r10, #1 */
/* @0x25cf9c add r8, pc, r8 —— 跳转表派发（表项 in-line） */
/* @0x25cfa0 ldrsh r8, [r8, r0] */
/* @0x25cfa4 cmp r8, #0 */
/* @0x25cfa8 beq 0x25cfb8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e90> */
/* @0x25cfac ble 0x25d4f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23cc> */
/* @0x25cfb0 mov r4, r8 */
/* @0x25cfb4 b 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25cfb8 cmp r10, #72 */
/* @0x25cfbc addls pc, pc, r10, lsl #2 —— 跳转表派发（表项 in-line） */
/* @0x25cfc0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cfc4 b 0x25d170 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2048> */
/* @0x25cfc8 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfcc b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfd0 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfd4 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfd8 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfdc b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfe0 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfe4 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfe8 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfec b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cff0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cff4 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cff8 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cffc b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d000 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d004 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d008 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d00c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d010 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d014 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d018 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d01c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d020 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d024 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d028 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d02c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d030 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d034 b 0x25d314 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21ec> */
/* @0x25d038 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d03c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d040 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d044 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d048 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d04c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d050 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d054 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d058 b 0x25d4b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x238c> */
/* @0x25d05c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d060 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d064 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d068 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d06c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d070 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d074 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d078 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d07c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d080 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d084 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d088 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d08c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d090 b 0x25d3e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x22b8> */
/* @0x25d094 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d098 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d09c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0a0 b 0x25d400 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x22d8> */
/* @0x25d0a4 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0a8 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0ac b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0b0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0b4 b 0x25d314 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21ec> */
/* @0x25d0b8 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0bc b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0c0 b 0x25d3c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x229c> */
/* @0x25d0c4 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0c8 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0cc b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0d0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0d4 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0d8 b 0x25d244 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x211c> */
/* @0x25d0dc b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0e0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0e4 b 0x25d1cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x20a4> */
/* @0x25d0e8 ldrb r5, [r0, #0x3] */
/* @0x25d0ec lsl r4, r4, #12 */
/* @0x25d0f0 ldrb r8, [r0, #0x2] */
/* @0x25d0f4 add r9, r0, #4 */
/* @0x25d0f8 uxth r4, r4 */
/* @0x25d0fc and r5, r5, #63 */
/* @0x25d100 and r0, r8, #63 */
/* @0x25d104 orr r4, r4, r5 */
/* @0x25d108 orr r4, r4, r0, lsl #6 */
/* @0x25d10c b 0x25cefc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1dd4> */
/* @0x25d110 tst r4, #4 */
/* @0x25d114 beq 0x25d14c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2024> */
/* @0x25d118 ldrb r8, [r0, #0x6] */
/* @0x25d11c and r4, r4, #1 */
/* @0x25d120 ldrb r11, [r0, #0x2] */
/* @0x25d124 add r9, r0, #7 */
/* @0x25d128 ldrb r10, [r0, #0x3] */
/* @0x25d12c and r8, r8, #63 */
/* @0x25d130 orr r8, r8, r4, lsl #30 */
/* @0x25d134 ldrb r5, [r0, #0x4] */
/* @0x25d138 ldrb r4, [r0, #0x5] */
/* @0x25d13c and r11, r11, #63 */
/* @0x25d140 and r10, r10, #63 */
/* @0x25d144 orr r8, r8, r11, lsl #24 */
/* @0x25d148 b 0x25cf7c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e54> */
/* @0x25d14c ldrb r8, [r0, #0x5] */
/* @0x25d150 and r11, r4, #3 */
/* @0x25d154 ldrb r10, [r0, #0x2] */
/* @0x25d158 add r9, r0, #6 */
/* @0x25d15c ldrb r5, [r0, #0x3] */
/* @0x25d160 and r8, r8, #63 */
/* @0x25d164 and r10, r10, #63 */
/* @0x25d168 ldrb r4, [r0, #0x4] */
/* @0x25d16c b 0x25d144 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x201c> */
/* @0x25d170 mov r4, #0 */
/* @0x25d174 ldrb r0, [r11, #0x1] */
/* @0x25d178 sub r3, r0, #48 */
/* @0x25d17c cmp r3, #7 */
/* @0x25d180 bhi 0x25d1a8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2080> */
/* @0x25d184 ldrb r3, [r11, #0x2] */
/* @0x25d188 add r4, r0, r4, lsl #3 */
/* @0x25d18c sub r4, r4, #48 */
/* @0x25d190 add r5, r11, #1 */
/* @0x25d194 sub r3, r3, #48 */
/* @0x25d198 uxtb r0, r3 */
/* @0x25d19c cmp r0, #7 */
/* @0x25d1a0 addls r5, r11, #2 */
/* @0x25d1a4 addls r4, r3, r4, lsl #3 */
/* @0x25d1a8 eor r8, r12, #1 */
/* @0x25d1ac cmp r4, #255 */
/* @0x25d1b0 movls r8, #0 */
/* @0x25d1b4 andhi r8, r8, #1 */
/* @0x25d1b8 cmp r8, #0 */
/* @0x25d1bc movne r3, #51 */
/* @0x25d1c0 movne r8, #0 */
/* @0x25d1c4 strne r3, [r2] */
/* @0x25d1c8 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d1cc ands r8, r6, #33554432 */
/* @0x25d1d0 beq 0x25d540 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2418> */
/* @0x25d1d4 ldr r12, [pc, #0x820] */
/* @0x25d1d8 ldrb r2, [r9] */
/* @0x25d1dc add r12, pc, r12 —— 跳转表派发（表项 in-line） */
/* @0x25d1e0 add r3, r12, r2 */
/* @0x25d1e4 ldrb r3, [r3, #0x98] */
/* @0x25d1e8 and r3, r3, #8 */
/* @0x25d1ec ands r8, r3, #255 */
/* @0x25d1f0 beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d1f4 ldrb r3, [r9, #0x1] */
/* @0x25d1f8 add r12, r12, r3 */
/* @0x25d1fc ldrb r0, [r12, #0x98] */
/* @0x25d200 and r0, r0, #8 */
/* @0x25d204 ands r0, r0, #255 */
/* @0x25d208 beq 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d20c cmp r2, #96 */
/* @0x25d210 bls 0x25d8b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x278c> */
/* @0x25d214 sub r2, r2, #32 */
/* @0x25d218 mov r0, #55 */
/* @0x25d21c cmp r3, #96 */
/* @0x25d220 rsb r2, r0, r2 */
/* @0x25d224 bls 0x25d860 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2738> */
/* @0x25d228 sub r3, r3, #32 */
/* @0x25d22c add r3, r3, r2, lsl #4 */
/* @0x25d230 mov r0, #55 */
/* @0x25d234 rsb r4, r0, r3 */
/* @0x25d238 add r5, r9, #1 */
/* @0x25d23c mov r8, #0 */
/* @0x25d240 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d244 ands r8, r6, #33554432 */
/* @0x25d248 beq 0x25d4bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2394> */
/* @0x25d24c ldr r10, [pc, #0x7ac] */
/* @0x25d250 ldrb r3, [r9] */
/* @0x25d254 add r10, pc, r10 —— 跳转表派发（表项 in-line） */
/* @0x25d258 add r3, r10, r3 */
/* @0x25d25c ldrb r3, [r3, #0x98] */
/* @0x25d260 and r3, r3, #8 */
/* @0x25d264 ands r8, r3, #255 */
/* @0x25d268 beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d26c ldrb r3, [r9, #0x1] */
/* @0x25d270 add r3, r10, r3 */
/* @0x25d274 ldrb r3, [r3, #0x98] */
/* @0x25d278 and r3, r3, #8 */
/* @0x25d27c ands r3, r3, #255 */
/* @0x25d280 beq 0x25d684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x255c> */
/* @0x25d284 ldrb r3, [r9, #0x2] */
/* @0x25d288 add r3, r10, r3 */
/* @0x25d28c ldrb r3, [r3, #0x98] */
/* @0x25d290 and r3, r3, #8 */
/* @0x25d294 ands r3, r3, #255 */
/* @0x25d298 beq 0x25d684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x255c> */
/* @0x25d29c ldrb r3, [r9, #0x3] */
/* @0x25d2a0 add r10, r10, r3 */
/* @0x25d2a4 ldrb r3, [r10, #0x98] */
/* @0x25d2a8 and r3, r3, #8 */
/* @0x25d2ac ands r3, r3, #255 */
/* @0x25d2b0 beq 0x25d684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x255c> */
/* @0x25d2b4 add r9, r9, #3 */
/* @0x25d2b8 mov r4, #0 */
/* @0x25d2bc ldrb r3, [r5, #0x1]! */
/* @0x25d2c0 mov r0, #48 */
/* @0x25d2c4 cmp r3, #96 */
/* @0x25d2c8 sub r8, r3, #32 */
/* @0x25d2cc add r8, r8, r4, lsl #4 */
/* @0x25d2d0 bhi 0x25d858 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2730> */
/* @0x25d2d4 cmp r3, #64 */
/* @0x25d2d8 add r8, r3, r4, lsl #4 */
/* @0x25d2dc bhi 0x25d858 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2730> */
/* @0x25d2e0 cmp r5, r9 */
/* @0x25d2e4 rsb r4, r0, r8 */
/* @0x25d2e8 bne 0x25d2bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2194> */
/* @0x25d2ec cmp r12, #0 */
/* @0x25d2f0 movw r3, #0xffff —— 32 位常数半字 */
/* @0x25d2f4 movt r3, #0x10 —— 32 位常数半字 */
/* @0x25d2f8 moveq r3, #255 */
/* @0x25d2fc cmp r3, r4 */
/* @0x25d300 bhs 0x25d9d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28a8> */
/* @0x25d304 mov r3, #76 */
/* @0x25d308 mov r8, #0 */
/* @0x25d30c str r3, [r2] */
/* @0x25d310 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d314 mov r3, #37 */
/* @0x25d318 mov r8, #0 */
/* @0x25d31c str r3, [r2] */
/* @0x25d320 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d324 ldr r0, [sp, #0x3c] —— 栈槽 */
/* @0x25d328 cmp r0, #0 */
/* @0x25d32c bne 0x25d38c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2264> */
/* @0x25d330 ldrb r0, [r9] */
/* @0x25d334 sub r0, r0, #48 */
/* @0x25d338 uxtb r8, r0 */
/* @0x25d33c cmp r8, #9 */
/* @0x25d340 bhi 0x25d378 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2250> */
/* @0x25d344 movw r9, #0xcccb —— 32 位常数半字 */
/* @0x25d348 movt r9, #0xccc —— 32 位常数半字 */
/* @0x25d34c b 0x25d358 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2230> */
/* @0x25d350 cmp r10, r9 */
/* @0x25d354 bgt 0x25d3a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2278> */
/* @0x25d358 add r5, r5, #1 */
/* @0x25d35c add r10, r10, r10, lsl #2 */
/* @0x25d360 ldrb r8, [r5, #0x1] */
/* @0x25d364 add r10, r0, r10, lsl #1 */
/* @0x25d368 sub r0, r8, #48 */
/* @0x25d36c uxtb r8, r0 */
/* @0x25d370 cmp r8, #9 */
/* @0x25d374 bls 0x25d350 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2228> */
/* @0x25d378 cmp r10, #7 */
/* @0x25d37c cmpgt r10, r3 */
/* @0x25d380 rsble r8, r10, #0 */
/* @0x25d384 ble 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d388 mov r5, r11 */
/* @0x25d38c ldrb r4, [r11] */
/* @0x25d390 cmp r4, #55 */
/* @0x25d394 subls r4, r4, #48 */
/* @0x25d398 bls 0x25d174 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x204c> */
/* @0x25d39c b 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d3a0 add r5, r5, #1 */
/* @0x25d3a4 ldrb r3, [r5, #0x1] */
/* @0x25d3a8 sub r3, r3, #48 */
/* @0x25d3ac cmp r3, #9 */
/* @0x25d3b0 bls 0x25d3a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2278> */
/* @0x25d3b4 mov r3, #61 */
/* @0x25d3b8 mov r8, #0 */
/* @0x25d3bc str r3, [r2] */
/* @0x25d3c0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d3c4 ldrb r3, [r9] */
/* @0x25d3c8 cmp r3, #123 */
/* @0x25d3cc beq 0x25d5f0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x24c8> */
/* @0x25d3d0 mov r3, #81 */
/* @0x25d3d4 mov r8, #0 */
/* @0x25d3d8 str r3, [r2] */
/* @0x25d3dc b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d3e0 ldrb r4, [r9] */
/* @0x25d3e4 cmp r4, #0 */
/* @0x25d3e8 bne 0x25d5d4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x24ac> */
/* @0x25d3ec mov r3, #2 */
/* @0x25d3f0 mov r5, r9 */
/* @0x25d3f4 mov r8, r4 */
/* @0x25d3f8 str r3, [r2] */
/* @0x25d3fc b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d400 ldr r0, [sp, #0x3c] —— 栈槽 */
/* @0x25d404 cmp r0, #0 */
/* @0x25d408 bne 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d40c ldrb r8, [r9] */
/* @0x25d410 cmp r8, #60 */
/* @0x25d414 cmpne r8, #39 */
/* @0x25d418 moveq r8, #27 */
/* @0x25d41c beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d420 cmp r8, #123 */
/* @0x25d424 ldrne r11, [sp, #0x3c] */
/* @0x25d428 beq 0x25d7e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26c0> */
/* @0x25d42c cmp r8, #45 */
/* @0x25d430 ldrbeq r8, [r5, #0x2] */
/* @0x25d434 moveq r12, #1 */
/* @0x25d438 streq r12, [sp, #0xc] */
/* @0x25d43c addeq r5, r5, r12 */
/* @0x25d440 sub r12, r8, #48 */
/* @0x25d444 movne r0, #0 */
/* @0x25d448 strne r0, [sp, #0xc] */
/* @0x25d44c uxtb r0, r12 */
/* @0x25d450 cmp r0, #9 */
/* @0x25d454 bhi 0x25d9f0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28c8> */
/* @0x25d458 movw r10, #0xcccb —— 32 位常数半字 */
/* @0x25d45c mov r0, #0 */
/* @0x25d460 movt r10, #0xccc —— 32 位常数半字 */
/* @0x25d464 b 0x25d470 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2348> */
/* @0x25d468 cmp r0, r10 */
/* @0x25d46c bgt 0x25d4c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23a0> */
/* @0x25d470 add r5, r5, #1 */
/* @0x25d474 add r0, r0, r0, lsl #2 */
/* @0x25d478 ldrb r8, [r5, #0x1] */
/* @0x25d47c add r0, r12, r0, lsl #1 */
/* @0x25d480 sub r12, r8, #48 */
/* @0x25d484 uxtb r9, r12 */
/* @0x25d488 cmp r9, #9 */
/* @0x25d48c bls 0x25d468 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2340> */
/* @0x25d490 cmp r11, #0 */
/* @0x25d494 beq 0x25d840 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2718> */
/* @0x25d498 cmp r8, #125 */
/* @0x25d49c add r5, r5, #1 */
/* @0x25d4a0 beq 0x25d840 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2718> */
/* @0x25d4a4 mov r3, #57 */
/* @0x25d4a8 mov r8, #0 */
/* @0x25d4ac str r3, [r2] */
/* @0x25d4b0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d4b4 ands r8, r6, #33554432 */
/* @0x25d4b8 bne 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d4bc mov r3, #37 */
/* @0x25d4c0 str r3, [r2] */
/* @0x25d4c4 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d4c8 add r5, r5, #1 */
/* @0x25d4cc ldrb r3, [r5, #0x1] */
/* @0x25d4d0 sub r3, r3, #48 */
/* @0x25d4d4 cmp r3, #9 */
/* @0x25d4d8 bls 0x25d4c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23a0> */
/* @0x25d4dc b 0x25d3b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x228c> */
/* @0x25d4e0 ands r8, r6, #64 */
/* @0x25d4e4 movne r3, #3 */
/* @0x25d4e8 movne r8, #0 */
/* @0x25d4ec strne r3, [r2] */
/* @0x25d4f0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d4f4 rsb r8, r8, #0 */
/* @0x25d4f8 cmp r8, #12 */
/* @0x25d4fc bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d500 ldrb r3, [r5, #0x1] */
/* @0x25d504 cmp r3, #123 */
/* @0x25d508 bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d50c ldrb r3, [r5, #0x2] */
/* @0x25d510 sub r3, r3, #48 */
/* @0x25d514 cmp r3, #9 */
/* @0x25d518 bhi 0x25d4bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2394> */
/* @0x25d51c add r0, r5, #2 */
/* @0x25d520 str r1, [sp, #0x8] —— 栈槽 */
/* @0x25d524 str r2, [sp, #0x4] —— 栈槽 */
/* @0x25d528 bl 0x25ce14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cec> —— 调 anon_25ce14 */
/* @0x25d52c ldr r1, [sp, #0x8] —— 栈槽 */
/* @0x25d530 ldr r2, [sp, #0x4] —— 栈槽 */
/* @0x25d534 cmp r0, #0 */
/* @0x25d538 bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d53c b 0x25d4bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2394> */
/* @0x25d540 ldrb r3, [r9] */
/* @0x25d544 cmp r3, #123 */
/* @0x25d548 beq 0x25d6e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x25b8> */
/* @0x25d54c ldr r2, [pc, #0x4b0] */
/* @0x25d550 add r2, pc, r2 —— 跳转表派发（表项 in-line） */
/* @0x25d554 add r2, r2, r3 */
/* @0x25d558 ldrb r2, [r2, #0x98] */
/* @0x25d55c and r2, r2, #8 */
/* @0x25d560 ands r2, r2, #255 */
/* @0x25d564 moveq r4, r2 */
/* @0x25d568 moveq r8, r4 */
/* @0x25d56c beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d570 cmp r3, #96 */
/* @0x25d574 bls 0x25d68c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2564> */
/* @0x25d578 sub r3, r3, #32 */
/* @0x25d57c mov r4, #55 */
/* @0x25d580 rsb r4, r4, r3 */
/* @0x25d584 ldr r3, [pc, #0x47c] */
/* @0x25d588 ldrb r2, [r9, #0x1] */
/* @0x25d58c add r3, pc, r3 —— 跳转表派发（表项 in-line） */
/* @0x25d590 add r3, r3, r2 */
/* @0x25d594 ldrb r3, [r3, #0x98] */
/* @0x25d598 and r3, r3, #8 */
/* @0x25d59c ands r3, r3, #255 */
/* @0x25d5a0 beq 0x25d680 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2558> */
/* @0x25d5a4 cmp r2, #96 */
/* @0x25d5a8 add r5, r9, #1 */
/* @0x25d5ac addhi r4, r2, r4, lsl #4 */
/* @0x25d5b0 subhi r4, r4, #32 */
/* @0x25d5b4 bhi 0x25d69c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2574> */
/* @0x25d5b8 cmp r2, #64 */
/* @0x25d5bc add r4, r2, r4, lsl #4 */
/* @0x25d5c0 movls r3, #48 */
/* @0x25d5c4 bhi 0x25d69c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2574> */
/* @0x25d5c8 rsb r4, r3, r4 */
/* @0x25d5cc mov r8, #0 */
/* @0x25d5d0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d5d4 cmp r4, #127 */
/* @0x25d5d8 bls 0x25d664 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x253c> */
/* @0x25d5dc mov r3, #68 */
/* @0x25d5e0 mov r5, r9 */
/* @0x25d5e4 mov r8, #0 */
/* @0x25d5e8 str r3, [r2] */
/* @0x25d5ec b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d5f0 ldrb r3, [r9, #0x1] */
/* @0x25d5f4 cmp r3, #125 */
/* @0x25d5f8 moveq r3, #86 */
/* @0x25d5fc moveq r8, #0 */
/* @0x25d600 streq r3, [r2] */
/* @0x25d604 beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d608 cmp r12, #0 */
/* @0x25d60c add r0, r9, #1 */
/* @0x25d610 beq 0x25d788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2660> */
/* @0x25d614 movw r10, #0xffff —— 32 位常数半字 */
/* @0x25d618 mov r4, #0 */
/* @0x25d61c movt r10, #0x10 —— 32 位常数半字 */
/* @0x25d620 b 0x25d634 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x250c> */
/* @0x25d624 cmp r4, r10 */
/* @0x25d628 bhi 0x25d874 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x274c> */
/* @0x25d62c ldrb r3, [r0, #0x1] */
/* @0x25d630 mov r0, r8 */
/* @0x25d634 sub r5, r3, #48 */
/* @0x25d638 add r9, r3, r4, lsl #3 */
/* @0x25d63c cmp r5, #7 */
/* @0x25d640 add r8, r0, #1 */
/* @0x25d644 mov r5, r0 */
/* @0x25d648 bhi 0x25d6a4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x257c> */
/* @0x25d64c cmp r3, #48 */
/* @0x25d650 cmpeq r4, #0 */
/* @0x25d654 sub r4, r9, #48 */
/* @0x25d658 bne 0x25d624 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x24fc> */
/* @0x25d65c mov r4, #0 */
/* @0x25d660 b 0x25d62c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2504> */
/* @0x25d664 sub r3, r4, #97 */
/* @0x25d668 mov r5, r9 */
/* @0x25d66c cmp r3, #25 */
/* @0x25d670 mov r8, #0 */
/* @0x25d674 subls r4, r4, #32 */
/* @0x25d678 eor r4, r4, #64 */
/* @0x25d67c b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d680 mov r5, r9 */
/* @0x25d684 mov r8, r3 */
/* @0x25d688 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d68c cmp r3, #64 */
/* @0x25d690 movls r4, #48 */
/* @0x25d694 bls 0x25d580 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2458> */
/* @0x25d698 b 0x25d57c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2454> */
/* @0x25d69c mov r3, #55 */
/* @0x25d6a0 b 0x25d5c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x24a0> */
/* @0x25d6a4 cmp r3, #125 */
/* @0x25d6a8 movne r3, #80 */
/* @0x25d6ac movne r8, #0 */
/* @0x25d6b0 strne r3, [r2] */
/* @0x25d6b4 bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d6b8 sub r3, r4, #55296 */
/* @0x25d6bc cmp r3, #2048 */
/* @0x25d6c0 movhs r12, #0 */
/* @0x25d6c4 andlo r12, r12, #1 */
/* @0x25d6c8 cmp r12, #0 */
/* @0x25d6cc beq 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d6d0 mov r3, #73 */
/* @0x25d6d4 mov r8, #0 */
/* @0x25d6d8 str r3, [r2] */
/* @0x25d6dc b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d6e0 ldrb r3, [r9, #0x1] */
/* @0x25d6e4 add r5, r9, #1 */
/* @0x25d6e8 cmp r3, #125 */
/* @0x25d6ec beq 0x25d944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x281c> */
/* @0x25d6f0 cmp r12, #0 */
/* @0x25d6f4 beq 0x25d8c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x279c> */
/* @0x25d6f8 ldr r11, [pc, #0x30c] */
/* @0x25d6fc mov r0, r5 */
/* @0x25d700 mov r4, r8 */
/* @0x25d704 movw r5, #0xffff —— 32 位常数半字 */
/* @0x25d708 add r11, pc, r11 —— 跳转表派发（表项 in-line） */
/* @0x25d70c movt r5, #0x10 —— 32 位常数半字 */
/* @0x25d710 str r5, [sp, #0xc] —— 栈槽 */
/* @0x25d714 b 0x25d750 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2628> */
/* @0x25d718 cmp r3, #96 */
/* @0x25d71c add r10, r3, r4, lsl #4 */
/* @0x25d720 sub r10, r10, #32 */
/* @0x25d724 mov r5, #48 */
/* @0x25d728 bhi 0x25d780 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2658> */
/* @0x25d72c cmp r3, #64 */
/* @0x25d730 add r10, r3, r4, lsl #4 */
/* @0x25d734 bhi 0x25d780 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2658> */
/* @0x25d738 ldr r3, [sp, #0xc] —— 栈槽 */
/* @0x25d73c rsb r4, r5, r10 */
/* @0x25d740 cmp r4, r3 */
/* @0x25d744 bhi 0x25d97c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2854> */
/* @0x25d748 ldrb r3, [r0, #0x1] */
/* @0x25d74c mov r0, r9 */
/* @0x25d750 add r8, r11, r3 */
/* @0x25d754 add r9, r0, #1 */
/* @0x25d758 mov r5, r0 */
/* @0x25d75c ldrb r10, [r8, #0x98] */
/* @0x25d760 mov r8, r9 */
/* @0x25d764 tst r10, #8 */
/* @0x25d768 beq 0x25d7d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26a8> */
/* @0x25d76c cmp r3, #48 */
/* @0x25d770 cmpeq r4, #0 */
/* @0x25d774 bne 0x25d718 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x25f0> */
/* @0x25d778 mov r4, #0 */
/* @0x25d77c b 0x25d748 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2620> */
/* @0x25d780 mov r5, #55 */
/* @0x25d784 b 0x25d738 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2610> */
/* @0x25d788 mov r4, r12 */
/* @0x25d78c b 0x25d7a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2678> */
/* @0x25d790 cmp r4, #255 */
/* @0x25d794 bhi 0x25d874 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x274c> */
/* @0x25d798 ldrb r3, [r0, #0x1] */
/* @0x25d79c mov r0, r8 */
/* @0x25d7a0 sub r5, r3, #48 */
/* @0x25d7a4 add r9, r3, r4, lsl #3 */
/* @0x25d7a8 cmp r5, #7 */
/* @0x25d7ac add r8, r0, #1 */
/* @0x25d7b0 mov r5, r0 */
/* @0x25d7b4 bhi 0x25d6a4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x257c> */
/* @0x25d7b8 cmp r3, #48 */
/* @0x25d7bc cmpeq r4, #0 */
/* @0x25d7c0 sub r4, r9, #48 */
/* @0x25d7c4 bne 0x25d790 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2668> */
/* @0x25d7c8 mov r4, #0 */
/* @0x25d7cc b 0x25d798 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2670> */
/* @0x25d7d0 cmp r3, #125 */
/* @0x25d7d4 movne r3, #79 */
/* @0x25d7d8 movne r8, #0 */
/* @0x25d7dc strne r3, [r2] */
/* @0x25d7e0 bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d7e4 b 0x25d6b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2590> */
/* @0x25d7e8 ldrb r10, [r9, #0x1] */
/* @0x25d7ec add r12, r9, #1 */
/* @0x25d7f0 cmp r10, #0 */
/* @0x25d7f4 cmpne r10, #125 */
/* @0x25d7f8 beq 0x25d830 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2708> */
/* @0x25d7fc sub r0, r10, #48 */
/* @0x25d800 cmp r10, #45 */
/* @0x25d804 cmpne r0, #9 */
/* @0x25d808 bls 0x25d81c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26f4> */
/* @0x25d80c b 0x25d974 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x284c> */
/* @0x25d810 cmp r0, #45 */
/* @0x25d814 cmpne r8, #9 */
/* @0x25d818 bhi 0x25d974 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x284c> */
/* @0x25d81c ldrb r0, [r12, #0x1]! */
/* @0x25d820 cmp r0, #125 */
/* @0x25d824 cmpne r0, #0 */
/* @0x25d828 sub r8, r0, #48 */
/* @0x25d82c bne 0x25d810 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26e8> */
/* @0x25d830 mov r8, r10 */
/* @0x25d834 mov r5, r9 */
/* @0x25d838 mov r11, #1 */
/* @0x25d83c b 0x25d42c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2304> */
/* @0x25d840 cmp r0, #0 */
/* @0x25d844 bne 0x25d950 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2828> */
/* @0x25d848 mov r3, #58 */
/* @0x25d84c mov r8, r0 */
/* @0x25d850 str r3, [r2] */
/* @0x25d854 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d858 mov r0, #55 */
/* @0x25d85c b 0x25d2e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21b8> */
/* @0x25d860 cmp r3, #64 */
/* @0x25d864 add r3, r3, r2, lsl #4 */
/* @0x25d868 movls r0, #48 */
/* @0x25d86c bls 0x25d234 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x210c> */
/* @0x25d870 b 0x25d230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2108> */
/* @0x25d874 ldrb r3, [r8] */
/* @0x25d878 mov r5, r8 */
/* @0x25d87c sub r3, r3, #48 */
/* @0x25d880 cmp r3, #7 */
/* @0x25d884 bhi 0x25d8a4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x277c> */
/* @0x25d888 add r3, r8, #1 */
/* @0x25d88c mov r5, r3 */
/* @0x25d890 add r3, r3, #1 */
/* @0x25d894 ldrb r0, [r5] */
/* @0x25d898 sub r0, r0, #48 */
/* @0x25d89c cmp r0, #7 */
/* @0x25d8a0 bls 0x25d88c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2764> */
/* @0x25d8a4 mov r3, #34 */
/* @0x25d8a8 mov r8, #0 */
/* @0x25d8ac str r3, [r2] */
/* @0x25d8b0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d8b4 cmp r2, #64 */
/* @0x25d8b8 movls r0, #48 */
/* @0x25d8bc bls 0x25d21c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x20f4> */
/* @0x25d8c0 b 0x25d218 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x20f0> */
/* @0x25d8c4 ldr r9, [pc, #0x144] */
/* @0x25d8c8 mov r0, r5 */
/* @0x25d8cc mov r4, r12 */
/* @0x25d8d0 add r9, pc, r9 —— 跳转表派发（表项 in-line） */
/* @0x25d8d4 b 0x25d900 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27d8> */
/* @0x25d8d8 cmp r3, #96 */
/* @0x25d8dc bls 0x25d930 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2808> */
/* @0x25d8e0 add r3, r3, r4, lsl #4 */
/* @0x25d8e4 sub r3, r3, #32 */
/* @0x25d8e8 mov r4, #55 */
/* @0x25d8ec rsb r4, r4, r3 */
/* @0x25d8f0 cmp r4, #255 */
/* @0x25d8f4 bhi 0x25d97c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2854> */
/* @0x25d8f8 ldrb r3, [r0, #0x1] */
/* @0x25d8fc mov r0, r5 */
/* @0x25d900 add r8, r9, r3 */
/* @0x25d904 mov r5, r0 */
/* @0x25d908 ldrb r8, [r8, #0x98] */
/* @0x25d90c tst r8, #8 */
/* @0x25d910 beq 0x25d7d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26a8> */
/* @0x25d914 add r5, r0, #1 */
/* @0x25d918 cmp r3, #48 */
/* @0x25d91c cmpeq r4, #0 */
/* @0x25d920 mov r8, r5 */
/* @0x25d924 bne 0x25d8d8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27b0> */
/* @0x25d928 mov r4, #0 */
/* @0x25d92c b 0x25d8f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27d0> */
/* @0x25d930 cmp r3, #64 */
/* @0x25d934 add r3, r3, r4, lsl #4 */
/* @0x25d938 movls r4, #48 */
/* @0x25d93c bls 0x25d8ec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27c4> */
/* @0x25d940 b 0x25d8e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27c0> */
/* @0x25d944 mov r3, #86 */
/* @0x25d948 str r3, [r2] */
/* @0x25d94c b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d950 ldr r12, [sp, #0xc] —— 栈槽 */
/* @0x25d954 cmp r12, #0 */
/* @0x25d958 beq 0x25d9c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28a0> */
/* @0x25d95c cmp r3, r0 */
/* @0x25d960 bge 0x25d9c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2898> */
/* @0x25d964 mov r3, #15 */
/* @0x25d968 mov r8, #0 */
/* @0x25d96c str r3, [r2] */
/* @0x25d970 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d974 mov r8, #28 */
/* @0x25d978 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d97c ldr r12, [pc, #0x90] */
/* @0x25d980 ldrb r3, [r8] */
/* @0x25d984 add r12, pc, r12 —— 跳转表派发（表项 in-line） */
/* @0x25d988 add r3, r12, r3 */
/* @0x25d98c ldrb r3, [r3, #0x98] */
/* @0x25d990 tst r3, #8 */
/* @0x25d994 beq 0x25d9b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2890> */
/* @0x25d998 add r3, r8, #1 */
/* @0x25d99c mov r8, r3 */
/* @0x25d9a0 add r3, r3, #1 */
/* @0x25d9a4 ldrb r0, [r8] */
/* @0x25d9a8 add r0, r12, r0 */
/* @0x25d9ac ldrb r0, [r0, #0x98] */
/* @0x25d9b0 tst r0, #8 */
/* @0x25d9b4 bne 0x25d99c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2874> */
/* @0x25d9b8 mov r5, r8 */
/* @0x25d9bc b 0x25d8a4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x277c> */
/* @0x25d9c0 rsb r0, r0, #1 */
/* @0x25d9c4 add r0, r0, r3 */
/* @0x25d9c8 rsb r8, r0, #0 */
/* @0x25d9cc b 0x25d4f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23d0> */
/* @0x25d9d0 sub r3, r4, #55296 */
/* @0x25d9d4 cmp r3, #2048 */
/* @0x25d9d8 movhs r12, #0 */
/* @0x25d9dc andlo r12, r12, #1 */
/* @0x25d9e0 cmp r12, #0 */
/* @0x25d9e4 moveq r8, r12 */
/* @0x25d9e8 beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d9ec b 0x25d6d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x25a8> */
/* @0x25d9f0 mov r0, #0 */
/* @0x25d9f4 b 0x25d490 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2368> */
/* @0x25d9f8 ldrheq r12, [r2], -r4 */
/* @0x25d9fc andseq r12, r2, r4, ror r9 */
/* @0x25da00 ldrsheq r12, [r2], -r12 */
/* @0x25da04 andseq r12, r2, r0, lsl #12 */
/* @0x25da08 andseq r12, r2, r4, asr #11 */
/* @0x25da0c andseq r12, r2, r8, asr #8 */
/* @0x25da10 andseq r12, r2, r0, lsl #5 */
/* @0x25da14 andseq r12, r2, r12, asr #3 */

/* ════════════════════════════════════════════════════════════════════
 * §4  anon_25db38   0x25db38 .. 0x25df90   1,112 B / 278 条   in-degree 3，调用点 3
 * 单字符 UTF-8 解码器：1..6 字节 5 条路径、5 个返回点、0 调用
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段是**完整函数**（0x25db38 push {r4..r7}，5 个 pop 返回点），0 条外跳、0 条 bl。
 * 入口：r0 = 字符流指针（r4），r1 = UTF-8 开关（0x25dc74 cmp r1,#0），r2 在窗口内只当临时量，
 *   r3 = 输出结构：+0x0 首字节/类型、+0x4 标志、+0x8 码点、+0xC 值/错误、+0x10 附加错误槽。
 * 主流程：0x25db40 `ldrb r12,[r4],#1` 取首字节 → 0x25db44 `sub r5,r12,#33` + `cmp #64` 做范围闸门
 *   （首字节先无条件写进 *[r3]（0x25db4c）；超界 → 0x25db50 movhi r0,#0 + 0x25db54 strhi r0,[r3,#0x4]，再走 0x25dc68）
  → 0x25db68 归一化（r5/r6 两种基）→
 *   0x25dc68 按 `cmp r12,#29` 分岔：< / = / > 三条。
 * 分支：'H'(72) / 'U'(85) / '.'(46) / '!'(33) 有专块；0x25dbc4..0x25dcb4 处理 29/30/31 三个控制码点。
 * UTF-8 五档都在本段（手写、非库调用）：1 字节（0x25dca0 直接写码点）、2 字节（0x25dc8c `and #31`）、
 *   3 字节（0x25de48 `lsl #12` + `uxth`）、4 字节（0x25ddd8 `and #7` + lsl #18）、5/6 字节（0x25deb8 /
 *   0x25df2c，`and #3` / `and #1` + lsl #24/#30）；续字节一律 `and #63` + 移位 orr。
 * 返回：r0 = 新指针；失败路径（0x25dcc4）r0 = 0；每档写完都 `mvn r2,#0; str r2,[r3,#0xc]` 打 -1 哨兵。
 * 被调：0 条。谁调它：3 处 —— 0x26713c（anon_2670bc 体内）、0x268bec 与 0x268de4（pcre_compile2 体内）。
 * open：
 *   1. [r3+0x10] 只在 0x25dda8 写一次 -1，它的读方/语义未钉。
 *   2. 0x25db44 的 `sub #33 / cmp #64` 闸门只证「33..97 走主流程」，闸门两侧的语义差别未钉。
 *   3. 5/6 字节分支在 UTF-8 规范外，是否被调用方用 UCS-2 路径避让，未钉。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x25db38 0x25df90 anon_25db38 */
/* @0x25db38 push {r4, r5, r6, r7} —— 序言（保存 4 个寄存器） */
/* @0x25db3c mov r4, r0 */
/* @0x25db40 ldrb r12, [r4], #1 */
/* @0x25db44 sub r5, r12, #33 */
/* @0x25db48 cmp r5, #64 */
/* @0x25db4c str r12, [r3] */
/* @0x25db50 movhi r0, #0 */
/* @0x25db54 strhi r0, [r3, #0x4] */
/* @0x25db58 bhi 0x25dc68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b40> */
/* @0x25db5c cmp r12, #84 */
/* @0x25db60 movhi r6, #85 */
/* @0x25db64 bls 0x25dcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bd0> */
/* @0x25db68 rsb r5, r6, r12 */
/* @0x25db6c uxtb r5, r5 */
/* @0x25db70 sub r7, r5, #6 */
/* @0x25db74 cmp r5, #12 */
/* @0x25db78 cmpne r7, #2 */
/* @0x25db7c addls r4, r0, #3 */
/* @0x25db80 and r0, r5, #253 */
/* @0x25db84 sub r5, r5, #2 */
/* @0x25db88 cmp r0, #8 */
/* @0x25db8c cmpne r5, #1 */
/* @0x25db90 movls r5, #0 */
/* @0x25db94 movhi r5, #1 */
/* @0x25db98 cmp r6, #59 */
/* @0x25db9c str r5, [r3, #0x4] */
/* @0x25dba0 beq 0x25ddb8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c90> */
/* @0x25dba4 bhi 0x25dc50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b28> */
/* @0x25dba8 cmp r6, #33 */
/* @0x25dbac beq 0x25dd6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c44> */
/* @0x25dbb0 cmp r6, #46 */
/* @0x25dbb4 bne 0x25dc68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b40> */
/* @0x25dbb8 mov r12, #30 */
/* @0x25dbbc cmp r12, #29 */
/* @0x25dbc0 str r12, [r3] */
/* @0x25dbc4 bls 0x25dcd0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2ba8> */
/* @0x25dbc8 cmp r12, #32 */
/* @0x25dbcc beq 0x25dd88 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c60> */
/* @0x25dbd0 bls 0x25dcb4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b8c> */
/* @0x25dbd4 sub r2, r12, #110 */
/* @0x25dbd8 cmp r2, #2 */
/* @0x25dbdc bhi 0x25dcc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b9c> */
/* @0x25dbe0 cmp r12, #112 */
/* @0x25dbe4 addne r0, r4, #32 */
/* @0x25dbe8 ldrbeq r0, [r4] */
/* @0x25dbec ldrbeq r2, [r4, #0x1] */
/* @0x25dbf0 orreq r0, r2, r0, lsl #8 */
/* @0x25dbf4 subeq r0, r0, #1 */
/* @0x25dbf8 addeq r0, r4, r0 */
/* @0x25dbfc ldrb r2, [r0] */
/* @0x25dc00 sub r2, r2, #98 */
/* @0x25dc04 uxtb r2, r2 */
/* @0x25dc08 cmp r2, #11 */
/* @0x25dc0c bhi 0x25dc40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b18> */
/* @0x25dc10 mov r12, #1 */
/* @0x25dc14 movw r1, #0x533 —— 32 位常数半字 */
/* @0x25dc18 lsl r2, r12, r2 */
/* @0x25dc1c and r1, r2, r1 */
/* @0x25dc20 cmp r1, #0 */
/* @0x25dc24 strne r12, [r3, #0x4] */
/* @0x25dc28 addne r0, r0, #1 */
/* @0x25dc2c bne 0x25dc40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b18> */
/* @0x25dc30 tst r2, #2240 */
/* @0x25dc34 bne 0x25de98 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d70> */
/* @0x25dc38 tst r2, #524 */
/* @0x25dc3c addne r0, r0, #1 */
/* @0x25dc40 rsb r4, r4, r0 */
/* @0x25dc44 str r4, [r3, #0x8] */
/* @0x25dc48 pop {r4, r5, r6, r7} —— 拆帧（随后 bx lr） */
/* @0x25dc4c bx lr —— 返回 */
/* @0x25dc50 cmp r6, #72 */
/* @0x25dc54 beq 0x25dd78 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c50> */
/* @0x25dc58 cmp r6, #85 */
/* @0x25dc5c ldrbeq r0, [r4], #1 */
/* @0x25dc60 moveq r12, r0 */
/* @0x25dc64 streq r0, [r3] */
/* @0x25dc68 cmp r12, #29 */
/* @0x25dc6c bne 0x25dbc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a9c> */
/* @0x25dc70 ldrb r2, [r4] */
/* @0x25dc74 cmp r1, #0 */
/* @0x25dc78 cmpne r2, #191 */
/* @0x25dc7c addls r0, r4, #1 */
/* @0x25dc80 bls 0x25dca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b78> */
/* @0x25dc84 tst r2, #32 */
/* @0x25dc88 bne 0x25ddc8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2ca0> */
/* @0x25dc8c ldrb r1, [r4, #0x1] */
/* @0x25dc90 and r2, r2, #31 */
/* @0x25dc94 add r0, r4, #2 */
/* @0x25dc98 and r1, r1, #63 */
/* @0x25dc9c orr r2, r1, r2, lsl #6 */
/* @0x25dca0 str r2, [r3, #0x8] */
/* @0x25dca4 mvn r2, #0 —— 按位取反 */
/* @0x25dca8 pop {r4, r5, r6, r7} —— 拆帧（随后 bx lr） */
/* @0x25dcac str r2, [r3, #0xc] */
/* @0x25dcb0 bx lr —— 返回 */
/* @0x25dcb4 cmp r12, #30 */
/* @0x25dcb8 beq 0x25dd20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bf8> */
/* @0x25dcbc cmp r12, #31 */
/* @0x25dcc0 beq 0x25dc70 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b48> */
/* @0x25dcc4 mov r0, #0 */
/* @0x25dcc8 pop {r4, r5, r6, r7} —— 拆帧（随后 bx lr） */
/* @0x25dccc bx lr —— 返回 */
/* @0x25dcd0 cmp r12, #6 */
/* @0x25dcd4 blo 0x25dcc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b9c> */
/* @0x25dcd8 cmp r12, #13 */
/* @0x25dcdc bls 0x25dcec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bc4> */
/* @0x25dce0 sub r12, r12, #17 */
/* @0x25dce4 cmp r12, #9 */
/* @0x25dce8 bhi 0x25dcc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b9c> */
/* @0x25dcec mov r0, r4 */
/* @0x25dcf0 pop {r4, r5, r6, r7} —— 拆帧（随后 bx lr） */
/* @0x25dcf4 bx lr —— 返回 */
/* @0x25dcf8 cmp r12, #71 */
/* @0x25dcfc movhi r6, #72 */
/* @0x25dd00 bhi 0x25db68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a40> */
/* @0x25dd04 cmp r12, #58 */
/* @0x25dd08 movhi r6, #59 */
/* @0x25dd0c bhi 0x25db68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a40> */
/* @0x25dd10 cmp r12, #45 */
/* @0x25dd14 movls r6, #33 */
/* @0x25dd18 movhi r6, #46 */
/* @0x25dd1c b 0x25db68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a40> */
/* @0x25dd20 mov r0, #29 */
/* @0x25dd24 str r0, [r3] */
/* @0x25dd28 ldrb r12, [r4] */
/* @0x25dd2c cmp r1, #0 */
/* @0x25dd30 cmpne r12, #191 */
/* @0x25dd34 bls 0x25dd90 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c68> */
/* @0x25dd38 tst r12, #32 */
/* @0x25dd3c bne 0x25de08 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2ce0> */
/* @0x25dd40 ldrb r1, [r4, #0x1] */
/* @0x25dd44 and r12, r12, #31 */
/* @0x25dd48 add r0, r4, #2 */
/* @0x25dd4c and r1, r1, #63 */
/* @0x25dd50 orr r12, r1, r12, lsl #6 */
/* @0x25dd54 cmp r12, #255 */
/* @0x25dd58 str r12, [r3, #0x8] */
/* @0x25dd5c bls 0x25dd98 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c70> */
/* @0x25dd60 mvn r2, #0 —— 按位取反 */
/* @0x25dd64 str r2, [r3, #0xc] */
/* @0x25dd68 b 0x25dc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b20> */
/* @0x25dd6c mov r2, #29 */
/* @0x25dd70 str r2, [r3] */
/* @0x25dd74 b 0x25dc70 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b48> */
/* @0x25dd78 mov r12, #32 */
/* @0x25dd7c str r12, [r3] */
/* @0x25dd80 cmp r12, #29 */
/* @0x25dd84 b 0x25dbc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a9c> */
/* @0x25dd88 mov r0, #31 */
/* @0x25dd8c b 0x25dd24 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bfc> */
/* @0x25dd90 add r0, r4, #1 */
/* @0x25dd94 str r12, [r3, #0x8] */
/* @0x25dd98 ldrb r2, [r2, r12] */
/* @0x25dd9c cmp r2, r12 */
/* @0x25dda0 str r2, [r3, #0xc] */
/* @0x25dda4 mvnne r2, #0 */
/* @0x25dda8 strne r2, [r3, #0x10] */
/* @0x25ddac beq 0x25dd60 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c38> */
/* @0x25ddb0 pop {r4, r5, r6, r7} —— 拆帧（随后 bx lr） */
/* @0x25ddb4 bx lr —— 返回 */
/* @0x25ddb8 mov r12, #31 */
/* @0x25ddbc str r12, [r3] */
/* @0x25ddc0 cmp r12, #29 */
/* @0x25ddc4 b 0x25dbc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a9c> */
/* @0x25ddc8 tst r2, #16 */
/* @0x25ddcc beq 0x25de48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d20> */
/* @0x25ddd0 tst r2, #8 */
/* @0x25ddd4 bne 0x25deb8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d90> */
/* @0x25ddd8 ldrb r12, [r4, #0x1] */
/* @0x25dddc and r2, r2, #7 */
/* @0x25dde0 ldrb r5, [r4, #0x3] */
/* @0x25dde4 add r0, r4, #4 */
/* @0x25dde8 ldrb r1, [r4, #0x2] */
/* @0x25ddec and r12, r12, #63 */
/* @0x25ddf0 and r4, r5, #63 */
/* @0x25ddf4 orr r2, r4, r2, lsl #18 */
/* @0x25ddf8 and r1, r1, #63 */
/* @0x25ddfc orr r2, r2, r12, lsl #12 */
/* @0x25de00 orr r2, r2, r1, lsl #6 */
/* @0x25de04 b 0x25dca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b78> */
/* @0x25de08 tst r12, #16 */
/* @0x25de0c beq 0x25de70 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d48> */
/* @0x25de10 tst r12, #8 */
/* @0x25de14 bne 0x25defc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2dd4> */
/* @0x25de18 ldrb r1, [r4, #0x3] */
/* @0x25de1c and r5, r12, #7 */
/* @0x25de20 ldrb r6, [r4, #0x1] */
/* @0x25de24 add r0, r4, #4 */
/* @0x25de28 ldrb r12, [r4, #0x2] */
/* @0x25de2c and r1, r1, #63 */
/* @0x25de30 and r4, r6, #63 */
/* @0x25de34 orr r1, r1, r5, lsl #18 */
/* @0x25de38 and r12, r12, #63 */
/* @0x25de3c orr r1, r1, r4, lsl #12 */
/* @0x25de40 orr r12, r1, r12, lsl #6 */
/* @0x25de44 b 0x25dd54 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c2c> */
/* @0x25de48 lsl r2, r2, #12 */
/* @0x25de4c ldrb r12, [r4, #0x2] */
/* @0x25de50 ldrb r1, [r4, #0x1] */
/* @0x25de54 add r0, r4, #3 */
/* @0x25de58 uxth r2, r2 */
/* @0x25de5c and r12, r12, #63 */
/* @0x25de60 and r1, r1, #63 */
/* @0x25de64 orr r2, r2, r12 */
/* @0x25de68 orr r2, r2, r1, lsl #6 */
/* @0x25de6c b 0x25dca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b78> */
/* @0x25de70 lsl r5, r12, #12 */
/* @0x25de74 ldrb r1, [r4, #0x2] */
/* @0x25de78 ldrb r12, [r4, #0x1] */
/* @0x25de7c add r0, r4, #3 */
/* @0x25de80 and r1, r1, #63 */
/* @0x25de84 uxth r4, r5 */
/* @0x25de88 and r12, r12, #63 */
/* @0x25de8c orr r1, r4, r1 */
/* @0x25de90 orr r12, r1, r12, lsl #6 */
/* @0x25de94 b 0x25dd54 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c2c> */
/* @0x25de98 ldrb r2, [r0, #0x2] */
/* @0x25de9c add r0, r0, #5 */
/* @0x25dea0 ldrb r1, [r0, #-0x4] */
/* @0x25dea4 orrs r2, r2, r1, lsl #8 */
/* @0x25dea8 movne r2, #0 */
/* @0x25deac moveq r2, #1 */
/* @0x25deb0 str r2, [r3, #0x4] */
/* @0x25deb4 b 0x25dc40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b18> */
/* @0x25deb8 tst r2, #4 */
/* @0x25debc bne 0x25df2c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2e04> */
/* @0x25dec0 ldrb r6, [r4, #0x4] */
/* @0x25dec4 and r2, r2, #3 */
/* @0x25dec8 ldrb r5, [r4, #0x1] */
/* @0x25decc add r0, r4, #5 */
/* @0x25ded0 and r6, r6, #63 */
/* @0x25ded4 ldrb r12, [r4, #0x2] */
/* @0x25ded8 ldrb r1, [r4, #0x3] */
/* @0x25dedc and r5, r5, #63 */
/* @0x25dee0 orr r2, r6, r2, lsl #24 */
/* @0x25dee4 and r12, r12, #63 */
/* @0x25dee8 orr r2, r2, r5, lsl #18 */
/* @0x25deec and r1, r1, #63 */
/* @0x25def0 orr r2, r2, r12, lsl #12 */
/* @0x25def4 orr r2, r2, r1, lsl #6 */
/* @0x25def8 b 0x25dca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b78> */
/* @0x25defc tst r12, #4 */
/* @0x25df00 bne 0x25df60 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2e38> */
/* @0x25df04 ldrb r1, [r4, #0x4] */
/* @0x25df08 and r7, r12, #3 */
/* @0x25df0c ldrb r5, [r4, #0x1] */
/* @0x25df10 add r0, r4, #5 */
/* @0x25df14 ldrb r6, [r4, #0x2] */
/* @0x25df18 and r1, r1, #63 */
/* @0x25df1c ldrb r12, [r4, #0x3] */
/* @0x25df20 and r5, r5, #63 */
/* @0x25df24 orr r1, r1, r7, lsl #24 */
/* @0x25df28 b 0x25de30 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d08> */
/* @0x25df2c ldrb r1, [r4, #0x5] */
/* @0x25df30 and r2, r2, #1 */
/* @0x25df34 ldrb r6, [r4, #0x1] */
/* @0x25df38 add r0, r4, #6 */
/* @0x25df3c and r1, r1, #63 */
/* @0x25df40 ldrb r5, [r4, #0x2] */
/* @0x25df44 and r6, r6, #63 */
/* @0x25df48 orr r2, r1, r2, lsl #30 */
/* @0x25df4c ldrb r12, [r4, #0x3] */
/* @0x25df50 and r5, r5, #63 */
/* @0x25df54 ldrb r1, [r4, #0x4] */
/* @0x25df58 orr r2, r2, r6, lsl #24 */
/* @0x25df5c b 0x25dee4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2dbc> */
/* @0x25df60 ldrb r1, [r4, #0x5] */
/* @0x25df64 and r12, r12, #1 */
/* @0x25df68 ldrb r7, [r4, #0x1] */
/* @0x25df6c add r0, r4, #6 */
/* @0x25df70 ldrb r5, [r4, #0x2] */
/* @0x25df74 and r1, r1, #63 */
/* @0x25df78 orr r1, r1, r12, lsl #30 */
/* @0x25df7c and r7, r7, #63 */
/* @0x25df80 ldrb r6, [r4, #0x3] */
/* @0x25df84 and r5, r5, #63 */
/* @0x25df88 ldrb r12, [r4, #0x4] */
/* @0x25df8c b 0x25df24 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2dfc> */

/* ════════════════════════════════════════════════════════════════════
 * §5  anon_230048   0x230048 .. 0x230294   588 B / 147 条   in-degree 3，调用点 3
 * 64 位偏移的 ogg 页扫描/对齐例程（ldrd/strd、-1 哨兵、尾调 fseek 的孤立薄封装）
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段主函数 0x230048..0x230238 是**完整函数**；段尾 0x230274..0x230290 是**另一个独立小函数**
 *   （段内 0 条分支指向它，它读自己的 [sp] 当第 5 参 ⇒ 无 own prologue 的薄封装）。0 条外跳。
 * 入口（至少 7 参）：r0 = 会话结构（+0x8 是一对 64 位偏移，函数里读改写回），r1 = 串号数组指针，
 *   r2 = 数量（0x23005c add r9,r2,#-1 ⇒ 末尾下标），r3 = 出参结构（r11），
 *   第 7 参 [sp+0x78] = 出参指针（0x230178 / 0x230264 两处写 *[7th] 与 *([7th]+4)）。
 * 栈帧：push {r4..r11,lr}(36 B) + sub sp,#84 ⇒ 120 B（=0x78，正是第 7 参的落位）；7 个 64 位槽统一初始化 -1
 *   （0x230074..0x230090，共 7 条 `str r10,#-1`）。
 * 主循环：0x230094 把 64 位偏移减 0x8000 并下溢钳 0（subs/sbc + movlt #0）→ 0x2300c0 调同区 0x22ffe0
 *   → 0x2300f0 调同区 0x22fd0c（拿下一页，返回 64 位；-127/-1 组合被当成 EOF 识别：0x230110..0x230120）
 *   → 0x23013c ogg_page_serialno / 0x230154 ogg_page_granulepos → 0x230170 与首串号比较 →
 *   0x2301a8 起在串号数组里线性扫描（步长 4，上限 r9）→ 命中记 [sp+0x20]/[sp+0x24]，未命中回 0x230094 继续。
 * 返回：r0:r1 = 64 位值（0x230230 从 [sp+0x20]/[sp+0x24] 取出；正常路径 r4:r5，未设置时是 -1:-1）。
 * 被调 4 条：0x22ffe0 ×1、0x22fd0c ×1、ogg_page_serialno ×1、ogg_page_granulepos ×1。
 * 谁调它：3 处 —— 0x230880 / 0x230a50（anon_22fd0c 体内）、0x231b6c（anon_231ac4 体内）。
 * 段尾独立函数 0x230274..0x230290（8 条）：cmp r0,#0 → r3=[sp] → beq 返回 -1；否则 `b fseek@plt`（0xb68d4）
 *   ⇒ 形状是 fseek(stream, r2, *(int*)sp) 的薄封装（r1 ← r2、r2 ← [sp]）。
 * open：
 *   1. 64 位返回值的语义（采样位置？字节偏移？）未钉，只证它是 64 位且用 -1 当未设置。
 *   2. 0x22ffe0 的契约未钉（它在本窗口里被当成「定位到偏移」的调用，返回 0 才算成功）。
 *   3. 段尾薄封装在段内无入边，是否为同族某一处 tail-call 目标，未钉。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x230048 0x230294 anon_230048 */
/* @0x230048 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言（保存 9 个寄存器） */
/* @0x23004c sub sp, sp, #84 */
/* @0x230050 ldrd r4, r5, [r0, #8] —— 64 位栈/结构体访问 */
/* @0x230054 mvn r10, #0 —— 按位取反 */
/* @0x230058 add r6, sp, #64 */
/* @0x23005c add r9, r2, r10 */
/* @0x230060 mov r8, r0 */
/* @0x230064 mov r7, r1 */
/* @0x230068 mov r11, r3 */
/* @0x23006c strd r4, r5, [sp, #16] —— 64 位栈/结构体访问 */
/* @0x230070 str r2, [sp, #0x2c] —— 栈槽 */
/* @0x230074 str r10, [sp, #0x18] —— 栈槽 */
/* @0x230078 str r10, [sp, #0x20] —— 栈槽 */
/* @0x23007c str r10, [sp, #0x38] —— 栈槽 */
/* @0x230080 strd r4, r5, [sp, #48] —— 64 位栈/结构体访问 */
/* @0x230084 str r10, [sp, #0x28] —— 栈槽 */
/* @0x230088 str r10, [sp, #0x1c] —— 栈槽 */
/* @0x23008c str r10, [sp, #0x24] —— 栈槽 */
/* @0x230090 str r10, [sp, #0x3c] —— 栈槽 */
/* @0x230094 ldrd r4, r5, [sp, #48] —— 64 位栈/结构体访问 */
/* @0x230098 mov r0, r8 */
/* @0x23009c subs r4, r4, #32768 */
/* @0x2300a0 sbc r5, r5, #0 */
/* @0x2300a4 strd r4, r5, [sp, #48] —— 64 位栈/结构体访问 */
/* @0x2300a8 cmp r4, #0 */
/* @0x2300ac sbcs r5, r5, #0 */
/* @0x2300b0 movlt r4, #0 */
/* @0x2300b4 movlt r5, #0 */
/* @0x2300b8 strdlt r4, r5, [sp, #48] */
/* @0x2300bc ldrd r2, r3, [sp, #48] —— 64 位栈/结构体访问 */
/* @0x2300c0 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> —— 调 anon_22ffe0 */
/* @0x2300c4 asr r1, r0, #31 */
/* @0x2300c8 orrs r5, r0, r1 */
/* @0x2300cc bne 0x230238 <vorbis_packet_blocksize+0x5bc> */
/* @0x2300d0 mvn r4, #0 —— 按位取反 */
/* @0x2300d4 mvn r5, #0 —— 按位取反 */
/* @0x2300d8 str r11, [sp, #0x4] —— 栈槽 */
/* @0x2300dc ldrd r2, r3, [r8, #8] —— 64 位栈/结构体访问 */
/* @0x2300e0 ldrd r0, r1, [sp, #16] —— 64 位栈/结构体访问 */
/* @0x2300e4 cmp r2, r0 */
/* @0x2300e8 sbcs r1, r3, r1 */
/* @0x2300ec bge 0x230204 <vorbis_packet_blocksize+0x588> */
/* @0x2300f0 ldrd r0, r1, [sp, #16] —— 64 位栈/结构体访问 */
/* @0x2300f4 subs r2, r0, r2 */
/* @0x2300f8 sbc r3, r1, r3 */
/* @0x2300fc mov r0, r8 */
/* @0x230100 mov r1, r6 */
/* @0x230104 bl 0x22fd0c <vorbis_packet_blocksize+0x90> —— 调 anon_22fd0c */
/* @0x230108 mov r2, r0 */
/* @0x23010c mov r3, r1 */
/* @0x230110 mvn r0, #127 —— 按位取反 */
/* @0x230114 mvn r1, #0 —— 按位取反 */
/* @0x230118 cmp r3, r1 */
/* @0x23011c cmpeq r2, r0 */
/* @0x230120 beq 0x230240 <vorbis_packet_blocksize+0x5c4> */
/* @0x230124 cmp r2, #0 */
/* @0x230128 sbcs r1, r3, #0 */
/* @0x23012c blt 0x230204 <vorbis_packet_blocksize+0x588> */
/* @0x230130 mov r0, r6 */
/* @0x230134 str r2, [sp, #0xc] —— 栈槽 */
/* @0x230138 str r3, [sp, #0x8] —— 栈槽 */
/* @0x23013c bl 0x23409c <ogg_page_serialno> —— 调 ogg_page_serialno */
/* @0x230140 mov r4, r0 */
/* @0x230144 mov r0, r6 */
/* @0x230148 asr r11, r4, #31 */
/* @0x23014c mov r10, r4 */
/* @0x230150 strd r10, r11, [sp, #24] —— 64 位栈/结构体访问 */
/* @0x230154 bl 0x233fb0 <ogg_page_granulepos> —— 调 ogg_page_granulepos */
/* @0x230158 ldr r5, [sp, #0x4] —— 栈槽 */
/* @0x23015c ldr r2, [sp, #0xc] —— 栈槽 */
/* @0x230160 ldr r3, [sp, #0x8] —— 栈槽 */
/* @0x230164 str r1, [sp, #0x28] —— 栈槽 */
/* @0x230168 mov r10, r0 */
/* @0x23016c ldr r1, [r5] */
/* @0x230170 cmp r4, r1 */
/* @0x230174 strdeq r2, r3, [sp, #32] */
/* @0x230178 ldreq r11, [sp, #0x78] */
/* @0x23017c ldreq r5, [sp, #0x28] */
/* @0x230180 streq r10, [r11] */
/* @0x230184 streq r5, [r11, #0x4] */
/* @0x230188 cmp r7, #0 */
/* @0x23018c beq 0x2301f4 <vorbis_packet_blocksize+0x578> */
/* @0x230190 ldr r11, [sp, #0x2c] —— 栈槽 */
/* @0x230194 cmp r11, #0 */
/* @0x230198 beq 0x2301f4 <vorbis_packet_blocksize+0x578> */
/* @0x23019c ldr r1, [r7] */
/* @0x2301a0 cmp r4, r1 */
/* @0x2301a4 beq 0x2301e0 <vorbis_packet_blocksize+0x564> */
/* @0x2301a8 mov r0, r7 */
/* @0x2301ac mov r1, #0 */
/* @0x2301b0 ldr r11, [sp, #0x4] —— 栈槽 */
/* @0x2301b4 b 0x2301c4 <vorbis_packet_blocksize+0x548> */
/* @0x2301b8 ldr r12, [r0, #0x4]! */
/* @0x2301bc cmp r4, r12 */
/* @0x2301c0 beq 0x2301ec <vorbis_packet_blocksize+0x570> */
/* @0x2301c4 cmp r1, r9 */
/* @0x2301c8 add r1, r1, #1 */
/* @0x2301cc bne 0x2301b8 <vorbis_packet_blocksize+0x53c> */
/* @0x2301d0 mvn r4, #0 —— 按位取反 */
/* @0x2301d4 mvn r5, #0 —— 按位取反 */
/* @0x2301d8 str r11, [sp, #0x4] —— 栈槽 */
/* @0x2301dc strd r4, r5, [sp, #32] —— 64 位栈/结构体访问 */
/* @0x2301e0 mov r4, r2 */
/* @0x2301e4 mov r5, r3 */
/* @0x2301e8 b 0x2300dc <vorbis_packet_blocksize+0x460> */
/* @0x2301ec str r11, [sp, #0x4] —— 栈槽 */
/* @0x2301f0 b 0x2301e0 <vorbis_packet_blocksize+0x564> */
/* @0x2301f4 mvn r4, #0 —— 按位取反 */
/* @0x2301f8 mvn r5, #0 —— 按位取反 */
/* @0x2301fc strd r4, r5, [sp, #32] —— 64 位栈/结构体访问 */
/* @0x230200 b 0x2301e0 <vorbis_packet_blocksize+0x564> */
/* @0x230204 ldrd r2, r3, [sp, #56] —— 64 位栈/结构体访问 */
/* @0x230208 ldr r11, [sp, #0x4] —— 栈槽 */
/* @0x23020c cmp r5, r3 */
/* @0x230210 cmpeq r4, r2 */
/* @0x230214 mvn r2, #0 —— 按位取反 */
/* @0x230218 mvn r3, #0 —— 按位取反 */
/* @0x23021c beq 0x230094 <vorbis_packet_blocksize+0x418> */
/* @0x230220 ldrd r0, r1, [sp, #32] —— 64 位栈/结构体访问 */
/* @0x230224 cmp r1, r3 */
/* @0x230228 cmpeq r0, r2 */
/* @0x23022c beq 0x230250 <vorbis_packet_blocksize+0x5d4> */
/* @0x230230 ldr r0, [sp, #0x20] —— 栈槽 */
/* @0x230234 ldr r1, [sp, #0x24] —— 栈槽 */
/* @0x230238 add sp, sp, #84 */
/* @0x23023c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 拆帧/返回 */
/* @0x230240 mov r0, r2 */
/* @0x230244 mov r1, r3 */
/* @0x230248 add sp, sp, #84 */
/* @0x23024c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 拆帧/返回 */
/* @0x230250 ldr r2, [sp, #0x18] —— 栈槽 */
/* @0x230254 mov r0, r4 */
/* @0x230258 ldr r4, [sp, #0x28] —— 栈槽 */
/* @0x23025c mov r1, r5 */
/* @0x230260 str r2, [r11] */
/* @0x230264 ldr r11, [sp, #0x78] —— 栈槽 */
/* @0x230268 str r10, [r11] */
/* @0x23026c str r4, [r11, #0x4] */
/* @0x230270 b 0x230238 <vorbis_packet_blocksize+0x5bc> */
/* @0x230274 cmp r0, #0 */
/* @0x230278 ldr r3, [sp] —— 栈槽 */
/* @0x23027c beq 0x23028c <vorbis_packet_blocksize+0x610> */
/* @0x230280 mov r1, r2 */
/* @0x230284 mov r2, r3 */
/* @0x230288 b 0xb68d4 <fseek@plt> */
/* @0x23028c mvn r0, #0 —— 按位取反 */
/* @0x230290 bx lr —— 返回 */

/* ════════════════════════════════════════════════════════════════════
 * §6  anon_230334   0x230334 .. 0x230674   832 B / 208 条   in-degree 3，调用点 3
 * ogg/vorbis 头部装配状态机：6 参 + 状态字 2→3，4 个返回码
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段是**完整函数**（0x230334 序言，唯一返回点 0x230504 pop {r4..r11,pc}），0 条外跳。
 * 入口（6 参：4 寄存器 + 2 栈）：r0 = 会话结构（+0x58 = 状态字，+0x78 起是 ogg_stream_state，+0x1c8 是当前串号），
 *   r1 = 头部信息结构（0x230358 传给初始化调用），r2 = 注释结构（0x23036c），r3 = 页结构（r7），
 *   [sp+0x60] = &串号计数（r8），[sp+0x64] = 页缓冲（r4，6 参）。
 * 状态机：0x230370 `mov r3,#2` → [r6+0x58]=2（起始态）；0x230540 `mov r3,#3` → 写 3（成功态）；
 *   0x2304f8 又把状态复位成 2（所有失败路径共用）。
 * 主链：vorbis_info_init → vorbis_comment_init → 0x230378 ogg_page_bos 判定 → 串号匹配（0x2303a8 起线性扫）→
 *   0x230400 realloc 串号表（每次 +1，0x23052c 首次 malloc(4)）→ 0x230430 ogg_stream_reset_serialno +
 *   ogg_stream_pagein + ogg_stream_packetout → 0x230464 vorbis_synthesis_idheader → 0x230550 vorbis_synthesis_headerin
 *   → 0x2304a8 状态 ==3 时收尾：0x2304c8 ogg_stream_pagein 把当前页塞进流。
 * 返回码（r11 走公共收尾 / r0 走早退）：0 = 成功（0x23064c）、-128（mvn #127，0x230564 与 0x23066c）、
 *   -132（mvn #131，0x2304e0 与 0x230664）、-133（mvn #132，0x230518 与 0x23055c）。
 * 失败清理：0x2304e4 vorbis_info_clear + 0x2304f0 vorbis_comment_clear；0x230508 先 free 串号表再清两次结构。
 * 被调 26 条 / 10 个不同目标：ogg_page_serialno ×5、ogg_stream_pagein ×3、0x22fd0c（同区取页）×3、
 *   ogg_page_bos ×2、ogg_stream_packetout ×2、vorbis_synthesis_headerin ×2、vorbis_info_init / vorbis_comment_init /
 *   ogg_stream_reset_serialno / vorbis_synthesis_idheader / vorbis_info_clear / vorbis_comment_clear / realloc / free 各 1..2。
 * 谁调它：3 处 —— 0x2308dc / 0x230d4c（anon_22fd0c 体内）、0x2310c4（anon_230fbc 体内）。
 * open：
 *   1. 状态字取值只证 2 与 3 两个，其余取值（以及 ==3 之后谁推进）未钉。
 *   2. 串号表元素宽度 4 B 已证（lsl #2 索引），但表长与容量的关系只证「每次 +1 就 realloc 到 n*4」。
 *   3. -128/-132/-133 的语义只按「负常数 + 清理路径」定位，没有调用方解释的旁证。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x230334 0x230674 anon_230334 */
/* @0x230334 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言（保存 9 个寄存器） */
/* @0x230338 sub sp, sp, #60 */
/* @0x23033c mov r7, r3 */
/* @0x230340 mov r6, r0 */
/* @0x230344 ldr r4, [sp, #0x64] —— 栈槽 */
/* @0x230348 stm sp, {r1, r2} */
/* @0x23034c cmp r4, #0 */
/* @0x230350 ldr r8, [sp, #0x60] —— 栈槽 */
/* @0x230354 beq 0x230610 <vorbis_packet_blocksize+0x994> */
/* @0x230358 ldr r0, [sp] —— 栈槽 */
/* @0x23035c add r5, r6, #120 */
/* @0x230360 add r11, sp, #24 */
/* @0x230364 bl 0x22ace8 <vorbis_info_init> —— 调 vorbis_info_init */
/* @0x230368 ldr r0, [sp, #0x4] —— 栈槽 */
/* @0x23036c bl 0x22aa80 <vorbis_comment_init> —— 调 vorbis_comment_init */
/* @0x230370 mov r3, #2 */
/* @0x230374 str r3, [r6, #0x58] */
/* @0x230378 mov r0, r4 */
/* @0x23037c bl 0x233f90 <ogg_page_bos> —— 调 ogg_page_bos */
/* @0x230380 cmp r0, #0 */
/* @0x230384 beq 0x2304d4 <vorbis_packet_blocksize+0x858> */
/* @0x230388 cmp r7, #0 */
/* @0x23038c beq 0x230424 <vorbis_packet_blocksize+0x7a8> */
/* @0x230390 ldr r10, [r7] */
/* @0x230394 mov r0, r4 */
/* @0x230398 ldr r9, [r8] */
/* @0x23039c bl 0x23409c <ogg_page_serialno> —— 调 ogg_page_serialno */
/* @0x2303a0 cmp r10, #0 */
/* @0x2303a4 beq 0x2303e4 <vorbis_packet_blocksize+0x768> */
/* @0x2303a8 cmp r9, #0 */
/* @0x2303ac beq 0x2303e4 <vorbis_packet_blocksize+0x768> */
/* @0x2303b0 ldr r3, [r10] */
/* @0x2303b4 cmp r0, r3 */
/* @0x2303b8 beq 0x230508 <vorbis_packet_blocksize+0x88c> */
/* @0x2303bc mov r2, r10 */
/* @0x2303c0 sub r12, r9, #1 */
/* @0x2303c4 mov r3, #0 */
/* @0x2303c8 b 0x2303d8 <vorbis_packet_blocksize+0x75c> */
/* @0x2303cc ldr r1, [r2, #0x4]! */
/* @0x2303d0 cmp r0, r1 */
/* @0x2303d4 beq 0x230508 <vorbis_packet_blocksize+0x88c> */
/* @0x2303d8 cmp r3, r12 */
/* @0x2303dc add r3, r3, #1 */
/* @0x2303e0 bne 0x2303cc <vorbis_packet_blocksize+0x750> */
/* @0x2303e4 mov r0, r4 */
/* @0x2303e8 bl 0x23409c <ogg_page_serialno> —— 调 ogg_page_serialno */
/* @0x2303ec ldr r1, [r8] */
/* @0x2303f0 add r1, r1, #1 */
/* @0x2303f4 mov r10, r0 */
/* @0x2303f8 ldr r0, [r7] */
/* @0x2303fc str r1, [r8] */
/* @0x230400 cmp r0, #0 */
/* @0x230404 beq 0x23052c <vorbis_packet_blocksize+0x8b0> */
/* @0x230408 lsl r1, r1, #2 */
/* @0x23040c bl 0xb6c28 <realloc@plt> —— 调 anon_b6c28 */
/* @0x230410 mov r3, r0 */
/* @0x230414 str r0, [r7] */
/* @0x230418 ldr r2, [r8] */
/* @0x23041c sub r2, r2, #-1073741823 */
/* @0x230420 str r10, [r3, r2, lsl #2] */
/* @0x230424 ldr r3, [r6, #0x58] */
/* @0x230428 cmp r3, #2 */
/* @0x23042c bgt 0x230474 <vorbis_packet_blocksize+0x7f8> */
/* @0x230430 mov r0, r4 */
/* @0x230434 bl 0x23409c <ogg_page_serialno> —— 调 ogg_page_serialno */
/* @0x230438 mov r1, r0 */
/* @0x23043c mov r0, r5 */
/* @0x230440 bl 0x2352f4 <ogg_stream_reset_serialno> —— 调 ogg_stream_reset_serialno */
/* @0x230444 mov r1, r4 */
/* @0x230448 mov r0, r5 */
/* @0x23044c bl 0x234eac <ogg_stream_pagein> —— 调 ogg_stream_pagein */
/* @0x230450 mov r0, r5 */
/* @0x230454 mov r1, r11 */
/* @0x230458 bl 0x235328 <ogg_stream_packetout> —— 调 ogg_stream_packetout */
/* @0x23045c cmp r0, #0 */
/* @0x230460 ble 0x230474 <vorbis_packet_blocksize+0x7f8> */
/* @0x230464 mov r0, r11 */
/* @0x230468 bl 0x22aec4 <vorbis_synthesis_idheader> —— 调 vorbis_synthesis_idheader */
/* @0x23046c cmp r0, #0 */
/* @0x230470 bne 0x230540 <vorbis_packet_blocksize+0x8c4> */
/* @0x230474 mov r2, #32768 */
/* @0x230478 mov r3, #0 */
/* @0x23047c mov r0, r6 */
/* @0x230480 mov r1, r4 */
/* @0x230484 bl 0x22fd0c <vorbis_packet_blocksize+0x90> —— 调 anon_22fd0c */
/* @0x230488 mvn r2, #127 —— 按位取反 */
/* @0x23048c mvn r3, #0 —— 按位取反 */
/* @0x230490 cmp r1, r3 */
/* @0x230494 cmpeq r0, r2 */
/* @0x230498 beq 0x230564 <vorbis_packet_blocksize+0x8e8> */
/* @0x23049c cmp r0, #0 */
/* @0x2304a0 sbcs r3, r1, #0 */
/* @0x2304a4 blt 0x2304e0 <vorbis_packet_blocksize+0x864> */
/* @0x2304a8 ldr r3, [r6, #0x58] */
/* @0x2304ac cmp r3, #3 */
/* @0x2304b0 bne 0x230378 <vorbis_packet_blocksize+0x6fc> */
/* @0x2304b4 mov r0, r4 */
/* @0x2304b8 ldr r10, [r6, #0x1c8] */
/* @0x2304bc bl 0x23409c <ogg_page_serialno> —— 调 ogg_page_serialno */
/* @0x2304c0 cmp r10, r0 */
/* @0x2304c4 bne 0x230378 <vorbis_packet_blocksize+0x6fc> */
/* @0x2304c8 add r0, r6, #120 */
/* @0x2304cc mov r1, r4 */
/* @0x2304d0 bl 0x234eac <ogg_stream_pagein> —— 调 ogg_stream_pagein */
/* @0x2304d4 ldr r3, [r6, #0x58] */
/* @0x2304d8 cmp r3, #3 */
/* @0x2304dc beq 0x23056c <vorbis_packet_blocksize+0x8f0> */
/* @0x2304e0 mvn r11, #131 —— 按位取反 */
/* @0x2304e4 ldr r0, [sp] —— 栈槽 */
/* @0x2304e8 bl 0x22ad10 <vorbis_info_clear> —— 调 vorbis_info_clear */
/* @0x2304ec ldr r0, [sp, #0x4] —— 栈槽 */
/* @0x2304f0 bl 0x22ac4c <vorbis_comment_clear> —— 调 vorbis_comment_clear */
/* @0x2304f4 mov r0, r11 */
/* @0x2304f8 mov r3, #2 */
/* @0x2304fc str r3, [r6, #0x58] */
/* @0x230500 add sp, sp, #60 */
/* @0x230504 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 拆帧/返回 */
/* @0x230508 ldr r0, [r7] */
/* @0x23050c cmp r0, #0 */
/* @0x230510 beq 0x230518 <vorbis_packet_blocksize+0x89c> */
/* @0x230514 bl 0xb655c <free@plt> —— 调 anon_b655c */
/* @0x230518 mov r3, #0 */
/* @0x23051c mvn r11, #132 —— 按位取反 */
/* @0x230520 str r3, [r7] */
/* @0x230524 str r3, [r8] */
/* @0x230528 b 0x2304e4 <vorbis_packet_blocksize+0x868> */
/* @0x23052c mov r0, #4 */
/* @0x230530 bl 0xb6544 <malloc@plt> —— 调 anon_b6544 */
/* @0x230534 mov r3, r0 */
/* @0x230538 str r0, [r7] */
/* @0x23053c b 0x230418 <vorbis_packet_blocksize+0x79c> */
/* @0x230540 mov r3, #3 */
/* @0x230544 ldm sp, {r0, r1} */
/* @0x230548 str r3, [r6, #0x58] */
/* @0x23054c mov r2, r11 */
/* @0x230550 bl 0x22af64 <vorbis_synthesis_headerin> —— 调 vorbis_synthesis_headerin */
/* @0x230554 cmp r0, #0 */
/* @0x230558 beq 0x230474 <vorbis_packet_blocksize+0x7f8> */
/* @0x23055c mvn r11, #132 —— 按位取反 */
/* @0x230560 b 0x2304e4 <vorbis_packet_blocksize+0x868> */
/* @0x230564 mvn r11, #127 —— 按位取反 */
/* @0x230568 b 0x2304e4 <vorbis_packet_blocksize+0x868> */
/* @0x23056c mov r10, #0 */
/* @0x230570 add r8, r6, #120 */
/* @0x230574 mov r7, r10 */
/* @0x230578 add r5, sp, #24 */
/* @0x23057c b 0x2305a8 <vorbis_packet_blocksize+0x92c> */
/* @0x230580 cmn r0, #1 */
/* @0x230584 beq 0x23055c <vorbis_packet_blocksize+0x8e0> */
/* @0x230588 ldm sp, {r0, r1} */
/* @0x23058c mov r2, r5 */
/* @0x230590 bl 0x22af64 <vorbis_synthesis_headerin> —— 调 vorbis_synthesis_headerin */
/* @0x230594 subs r11, r0, #0 */
/* @0x230598 bne 0x2304e4 <vorbis_packet_blocksize+0x868> */
/* @0x23059c cmp r7, #0 */
/* @0x2305a0 bne 0x23064c <vorbis_packet_blocksize+0x9d0> */
/* @0x2305a4 mov r7, #1 */
/* @0x2305a8 mov r0, r8 */
/* @0x2305ac mov r1, r5 */
/* @0x2305b0 bl 0x235328 <ogg_stream_packetout> —— 调 ogg_stream_packetout */
/* @0x2305b4 cmp r0, #0 */
/* @0x2305b8 bne 0x230580 <vorbis_packet_blocksize+0x904> */
/* @0x2305bc mov r3, #0 */
/* @0x2305c0 mov r0, r6 */
/* @0x2305c4 mov r1, r4 */
/* @0x2305c8 mov r2, #32768 */
/* @0x2305cc bl 0x22fd0c <vorbis_packet_blocksize+0x90> —— 调 anon_22fd0c */
/* @0x2305d0 cmp r0, #0 */
/* @0x2305d4 sbcs r3, r1, #0 */
/* @0x2305d8 mov r0, r4 */
/* @0x2305dc blt 0x23055c <vorbis_packet_blocksize+0x8e0> */
/* @0x2305e0 ldr r11, [r6, #0x1c8] */
/* @0x2305e4 bl 0x23409c <ogg_page_serialno> —— 调 ogg_page_serialno */
/* @0x2305e8 cmp r11, r0 */
/* @0x2305ec mov r0, r4 */
/* @0x2305f0 beq 0x230654 <vorbis_packet_blocksize+0x9d8> */
/* @0x2305f4 bl 0x233f90 <ogg_page_bos> —— 调 ogg_page_bos */
/* @0x2305f8 cmp r0, #0 */
/* @0x2305fc beq 0x2305bc <vorbis_packet_blocksize+0x940> */
/* @0x230600 cmp r10, #0 */
/* @0x230604 mov r10, #1 */
/* @0x230608 beq 0x2305bc <vorbis_packet_blocksize+0x940> */
/* @0x23060c b 0x23055c <vorbis_packet_blocksize+0x8e0> */
/* @0x230610 add r10, sp, #8 */
/* @0x230614 mov r2, #32768 */
/* @0x230618 mov r3, #0 */
/* @0x23061c mvn r4, #127 —— 按位取反 */
/* @0x230620 mov r1, r10 */
/* @0x230624 mvn r5, #0 —— 按位取反 */
/* @0x230628 bl 0x22fd0c <vorbis_packet_blocksize+0x90> —— 调 anon_22fd0c */
/* @0x23062c cmp r1, r5 */
/* @0x230630 cmpeq r0, r4 */
/* @0x230634 beq 0x23066c <vorbis_packet_blocksize+0x9f0> */
/* @0x230638 cmp r0, #0 */
/* @0x23063c sbcs r3, r1, #0 */
/* @0x230640 blt 0x230664 <vorbis_packet_blocksize+0x9e8> */
/* @0x230644 mov r4, r10 */
/* @0x230648 b 0x230358 <vorbis_packet_blocksize+0x6dc> */
/* @0x23064c mov r0, #0 */
/* @0x230650 b 0x230500 <vorbis_packet_blocksize+0x884> */
/* @0x230654 mov r0, r8 */
/* @0x230658 mov r1, r4 */
/* @0x23065c bl 0x234eac <ogg_stream_pagein> —— 调 ogg_stream_pagein */
/* @0x230660 b 0x2305a8 <vorbis_packet_blocksize+0x92c> */
/* @0x230664 mvn r0, #131 —— 按位取反 */
/* @0x230668 b 0x230500 <vorbis_packet_blocksize+0x884> */
/* @0x23066c mvn r0, #127 —— 按位取反 */
/* @0x230670 b 0x230500 <vorbis_packet_blocksize+0x884> */

/* ════════════════════════════════════════════════════════════════════
 * §7  anon_28b3fc   0x28b3fc .. 0x28b680   644 B / 161 条   in-degree 3，调用点 3
 * JSON 浮点数组 → 两条 int/float 数组的转换器（Json_getItem + 3 次 malloc + 尾调 free）
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段是**完整函数**（0x28b3fc 序言，两个返回点：0x28b5cc 拆帧后尾调 free、0x28b638 pop 返回），0 条外跳。
 * 入口：r0 = 缩放系数指针（0x28b54c 起 ldr [r5] 当乘数），r1 = JSON 项名（0x28b404 mov r0,r1 后调 Json_getItem），
 *   r2 = 输出结构（r9），r3 = 某个整数（0x28b414 `str r3,[r9,#0x20]` 直接写进输出）。
 * 输出字段：+0x10 = 一维项数、+0x14 = 数组 A（malloc(sizeof(int)*n)）、+0x18 = 二维项数、
 *   +0x1c = 数组 B（malloc 4×项数）、+0x20 = 入参 r3。
 * 流程：0x28b420 Json_getItem(父, 名) → 0x28b430 取 [项+0xc] 当长度 r8 → 0x28b43c malloc(4*r8, tag 0x201) →
 *   0x28b454 把 [项+4] 链表（next 在 +0）逐个搬到临时数组（每项取 +0x18）→ 0x28b490 第一遍遍历：
 *   vcvt.s32 取整后累加三个量（r2 += 1+4*v、lr += v+1、r12 += 3*v）→ 0x28b4dc/0x28b4f4 两次 malloc（tag 0x219/0x21a）
 *   → 0x28b50c 第二遍：按 4 float/顶点读，写 3 个 float（其中两个乘 [r5] 缩放）＋1 个 int。
 *   0x28b5e0 特例：当 v8 == 1.0 且项数 > 0 时，只把数组逐项乘 [r5]；否则走 0x28b63c 的第三组 malloc。
 * 调用面 6 条 bl：malloc ×5（0x285c10，3 个不同行号 tag 0x201/0x219/0x21a）、Json_getItem ×1（0x2873c4）；
 *   尾部 `b 0x285c80` = 尾调 free(r10)。
 * 谁调它：3 处，全部在 spSkeletonJson_readSkeletonData 体内（0x28cab4 / 0x28cd94 / 0x28d0c0）。
 * open：
 *   1. 输出结构的类型身份（哪一族 spine 数据）未钉：只证 5 个偏移与 3 张 malloc 数组。
 *   2. 第一遍里的 `+0xc` 到底是数组长度还是别的计数，只按后续 malloc 规模反推。
 *   3. 3 个 malloc tag（0x201/0x219/0x21a）对应源码行号，未与上游源码核对。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x28b3fc 0x28b680 anon_28b3fc */
/* @0x28b3fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言（保存 9 个寄存器） */
/* @0x28b400 mov r5, r0 */
/* @0x28b404 mov r0, r1 */
/* @0x28b408 ldr r1, [pc, #0x260] */
/* @0x28b40c mov r9, r2 */
/* @0x28b410 sub sp, sp, #12 */
/* @0x28b414 str r3, [r9, #0x20] */
/* @0x28b418 add r1, pc, r1 —— 跳转表派发（表项 in-line） */
/* @0x28b41c mov r4, r3 */
/* @0x28b420 bl 0x2873c4 <Json_getItem> —— 调 Json_getItem */
/* @0x28b424 ldr r1, [pc, #0x248] */
/* @0x28b428 movw r2, #0x201 —— 32 位常数半字 */
/* @0x28b42c add r1, pc, r1 —— 跳转表派发（表项 in-line） */
/* @0x28b430 ldr r8, [r0, #0xc] */
/* @0x28b434 mov r6, r0 */
/* @0x28b438 lsl r0, r8, #2 */
/* @0x28b43c bl 0x285c10 <_malloc> —— 调 _malloc */
/* @0x28b440 ldr r2, [r6, #0x4] */
/* @0x28b444 cmp r2, #0 */
/* @0x28b448 mov r10, r0 */
/* @0x28b44c movne r1, r0 */
/* @0x28b450 beq 0x28b468 <spSkeletonData_findPathConstraint+0x178> */
/* @0x28b454 ldr r3, [r2, #0x18] */
/* @0x28b458 ldr r2, [r2] */
/* @0x28b45c cmp r2, #0 */
/* @0x28b460 str r3, [r1], #4 */
/* @0x28b464 bne 0x28b454 <spSkeletonData_findPathConstraint+0x164> */
/* @0x28b468 cmp r4, r8 */
/* @0x28b46c beq 0x28b5e0 <spSkeletonData_findPathConstraint+0x2f0> */
/* @0x28b470 cmp r8, #0 */
/* @0x28b474 mov r0, #0 */
/* @0x28b478 str r0, [r9, #0x18] */
/* @0x28b47c str r0, [r9, #0x10] */
/* @0x28b480 ble 0x28b63c <spSkeletonData_findPathConstraint+0x34c> */
/* @0x28b484 mov r12, r0 */
/* @0x28b488 mov lr, r0 */
/* @0x28b48c mov r2, r0 */
/* @0x28b490 add r3, r10, r2, lsl #2 */
/* @0x28b494 vldr s15, [r3] */
/* @0x28b498 vcvt.s32.f32 s15, s15 */
/* @0x28b49c vmov r3, s15 */
/* @0x28b4a0 add r2, r2, r3, lsl #2 */
/* @0x28b4a4 add r1, r3, #1 */
/* @0x28b4a8 add r2, r2, #1 */
/* @0x28b4ac add r3, r3, r3, lsl #1 */
/* @0x28b4b0 cmp r8, r2 */
/* @0x28b4b4 add lr, lr, r1 */
/* @0x28b4b8 add r12, r12, r3 */
/* @0x28b4bc bgt 0x28b490 <spSkeletonData_findPathConstraint+0x1a0> */
/* @0x28b4c0 ldr r4, [pc, #0x1b0] */
/* @0x28b4c4 lsl r0, r12, #2 */
/* @0x28b4c8 str lr, [r9, #0x10] */
/* @0x28b4cc movw r2, #0x219 —— 32 位常数半字 */
/* @0x28b4d0 add r4, pc, r4 —— 跳转表派发（表项 in-line） */
/* @0x28b4d4 str r12, [r9, #0x18] */
/* @0x28b4d8 mov r1, r4 */
/* @0x28b4dc bl 0x285c10 <_malloc> —— 调 _malloc */
/* @0x28b4e0 ldr r3, [r9, #0x10] */
/* @0x28b4e4 movw r2, #0x21a —— 32 位常数半字 */
/* @0x28b4e8 mov r1, r4 */
/* @0x28b4ec str r0, [r9, #0x1c] */
/* @0x28b4f0 lsl r0, r3, #2 */
/* @0x28b4f4 bl 0x285c10 <_malloc> —— 调 _malloc */
/* @0x28b4f8 mov r2, #0 */
/* @0x28b4fc mov r3, r2 */
/* @0x28b500 mov r7, r2 */
/* @0x28b504 str r8, [sp, #0x4] —— 栈槽 */
/* @0x28b508 str r0, [r9, #0x14] */
/* @0x28b50c add r1, r10, r7, lsl #2 */
/* @0x28b510 vldr s15, [r1] */
/* @0x28b514 vcvt.s32.f32 s15, s15 */
/* @0x28b518 add r12, r7, #1 */
/* @0x28b51c add r11, r3, #1 */
/* @0x28b520 add r4, r0, r3, lsl #2 */
/* @0x28b524 vmov r8, s15 */
/* @0x28b528 add r6, r12, r8, lsl #2 */
/* @0x28b52c str r8, [r0, r3, lsl #2] */
/* @0x28b530 cmp r12, r6 */
/* @0x28b534 bge 0x28b5d4 <spSkeletonData_findPathConstraint+0x2e4> */
/* @0x28b538 ldr r3, [r9, #0x1c] */
/* @0x28b53c add r3, r3, r2, lsl #2 */
/* @0x28b540 vldr s14, [r1, #8] */
/* @0x28b544 vldr s15, [r5] */
/* @0x28b548 vmul.f32 s15, s14, s15 */
/* @0x28b54c vldr s14, [r1, #4] */
/* @0x28b550 add r12, r12, #4 */
/* @0x28b554 add r3, r3, #12 */
/* @0x28b558 cmp r6, r12 */
/* @0x28b55c vcvt.s32.f32 s14, s14 */
/* @0x28b560 vmov r8, s14 */
/* @0x28b564 str r8, [r4, #0x4]! */
/* @0x28b568 vstr s15, [r3, #-12] */
/* @0x28b56c vldr s14, [r1, #12] */
/* @0x28b570 vldr s15, [r5] */
/* @0x28b574 vmul.f32 s15, s14, s15 */
/* @0x28b578 vstr s15, [r3, #-8] */
/* @0x28b57c ldr r8, [r1, #0x10]! */
/* @0x28b580 str r8, [r3, #-0x4] */
/* @0x28b584 bgt 0x28b540 <spSkeletonData_findPathConstraint+0x250> */
/* @0x28b588 movw r1, #0xfffe —— 32 位常数半字 */
/* @0x28b58c movt r1, #0xffff —— 32 位常数半字 */
/* @0x28b590 rsb r1, r7, r1 */
/* @0x28b594 add r11, r11, #1 */
/* @0x28b598 add r6, r1, r6 */
/* @0x28b59c add r2, r2, #3 */
/* @0x28b5a0 add r7, r7, #5 */
/* @0x28b5a4 lsr r6, r6, #2 */
/* @0x28b5a8 add r3, r11, r6 */
/* @0x28b5ac add r1, r6, r6, lsl #1 */
/* @0x28b5b0 add r7, r7, r6, lsl #2 */
/* @0x28b5b4 add r2, r2, r1 */
/* @0x28b5b8 ldr r1, [sp, #0x4] —— 栈槽 */
/* @0x28b5bc cmp r1, r7 */
/* @0x28b5c0 bgt 0x28b50c <spSkeletonData_findPathConstraint+0x21c> */
/* @0x28b5c4 mov r0, r10 */
/* @0x28b5c8 add sp, sp, #12 */
/* @0x28b5cc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 拆帧（随后 bx lr） */
/* @0x28b5d0 b 0x285c80 <_free> */
/* @0x28b5d4 mov r7, r12 */
/* @0x28b5d8 mov r3, r11 */
/* @0x28b5dc b 0x28b5b8 <spSkeletonData_findPathConstraint+0x2c8> */
/* @0x28b5e0 vmov.f32 s14, #1.000000e+00 */
/* @0x28b5e4 vldr s15, [r5] */
/* @0x28b5e8 vcmp.f32 s15, s14 */
/* @0x28b5ec vmrs APSR_nzcv, fpscr */
/* @0x28b5f0 beq 0x28b620 <spSkeletonData_findPathConstraint+0x330> */
/* @0x28b5f4 cmp r4, #0 */
/* @0x28b5f8 ble 0x28b620 <spSkeletonData_findPathConstraint+0x330> */
/* @0x28b5fc add r3, r10, r4, lsl #2 */
/* @0x28b600 mov r2, r10 */
/* @0x28b604 b 0x28b60c <spSkeletonData_findPathConstraint+0x31c> */
/* @0x28b608 vldr s15, [r5] */
/* @0x28b60c vldr s14, [r2] */
/* @0x28b610 vmul.f32 s15, s14, s15 */
/* @0x28b614 vstmia r2!, {s15} */
/* @0x28b618 cmp r2, r3 */
/* @0x28b61c bne 0x28b608 <spSkeletonData_findPathConstraint+0x318> */
/* @0x28b620 mov r3, #0 */
/* @0x28b624 str r4, [r9, #0x18] */
/* @0x28b628 str r10, [r9, #0x1c] */
/* @0x28b62c str r3, [r9, #0x10] */
/* @0x28b630 str r3, [r9, #0x14] */
/* @0x28b634 add sp, sp, #12 */
/* @0x28b638 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 拆帧/返回 */
/* @0x28b63c ldr r4, [pc, #0x38] */
/* @0x28b640 movw r2, #0x219 —— 32 位常数半字 */
/* @0x28b644 add r4, pc, r4 —— 跳转表派发（表项 in-line） */
/* @0x28b648 mov r1, r4 */
/* @0x28b64c bl 0x285c10 <_malloc> —— 调 _malloc */
/* @0x28b650 ldr r3, [r9, #0x10] */
/* @0x28b654 mov r1, r4 */
/* @0x28b658 movw r2, #0x21a —— 32 位常数半字 */
/* @0x28b65c str r0, [r9, #0x1c] */
/* @0x28b660 lsl r0, r3, #2 */
/* @0x28b664 bl 0x285c10 <_malloc> —— 调 _malloc */
/* @0x28b668 str r0, [r9, #0x14] */
/* @0x28b66c b 0x28b5c4 <spSkeletonData_findPathConstraint+0x2d4> */
/* @0x28b670 ldrdeq r12, sp, [r12], -r12 */
/* @0x28b674 ldrdeq r12, sp, [r12], -r4 */
/* @0x28b678 andeq r12, r12, r0, lsr r6 */
/* @0x28b67c strheq r12, [r12], -r12 */

/* ════════════════════════════════════════════════════════════════════
 * §8  anon_2b3f58   0x2b3f58 .. 0x2b4374   1,052 B / 263 条   in-degree 3，调用点 3
 * 逐字节读标记段的解析器：17 条间接回调 + 3 个结构字段 + 84 B/组件的块分配
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段是**完整函数**（0x2b3f58 push {r4..r10,lr}，2 个返回点 0x2b421c / 0x2b4304），0 条外跳、0 条 bl。
 * 入口：r0 = 会话结构（r5），r1 / r2 是两个小整数，一进来就 `strb` 进结构 [r5+0xc8] / [r5+0xc9]（0x2b3f70/0x2b3f74）。
 * 取字节器：r7 = [r0+0x18]（描述符，+0 = 当前字节指针、+4 = 剩余字节数、+0xc = 一个 (cinfo)->int 回调）；
 *   每次取字节都是 `subs r3,r3,#1` + `addne r12,r12,#1` + `ldrb`，越界则
 *   `ldr r3,[r7,#0xc]; mov r0,r5; blx r3; cmp r0,#0; beq 0x2b4218` —— 回调返回 0 ⇒ 本函数返回 0（挂起）。
 * 写出去的字段：+0xc0（1 字节精度，0x2b3fa8）、+0x20（16 位高，两次写：0x2b3fc0 `lsl #8` 后 0x2b3fd8 加低字节）、
 *   +0x1c（16 位宽，0x2b3ff0 / 0x2b4010 同构）、+0xc4（组件数组指针，0x2b436c；大小 = 84 × 组件数，
 *   0x2b4348..0x2b4360 `mov r2,#84; mul r2,r2,r3` + 经 [[r5+4]] 方法表分配）。
 * 返回：r0 = 0（0x2b4218 挂起路径）或 1（0x2b42f0 `mov r3,#1` → r0 = r3，收尾块 0x2b42fc 把 r10/r6 存回 [r7]/[r7+4]）。
 * 调用面 17 条，全是间接，按来源分三类：
 *   · 11 条 `blx r3` 打 [r7+0xc]（取字节回调：0x2b4018/0x2b414c/0x2b41d0/0x2b41f0/0x2b420c/0x2b4228/0x2b4248/
 *     0x2b4274/0x2b4294/0x2b42c4/0x2b4310）；
 *   · 3 条 `blx r3` 打 [[r5]]，调用前都把码 32 / 11 / 58 写进 [*r5+0x14]（0x2b40bc / 0x2b40e4 / 0x2b4340）—— 消息发射槽；
 *   · 1 条 `blx r3` 打 [[r5+4]]（0x2b4360，r1=1、r2=84×Nf 的分配器）＋ 2 条 `blx r2` 打 [r3+4]（0x2b407c / 0x2b41ac）；
 *     两条 blx r2 之后都紧跟 `[r5+0x194]` → `ldrb [..+0xd]` → `cmp #0` 的形状。
 * 谁调它：3 处，全部在 0x2b3f58..0x2b5da0 这个 7752 B 的父区间内（0x2b4df0 / 0x2b5150 / 0x2b5284）。
 * 定位证据（不据此命名）：本段紧接 jinit_input_controller（0x2b3ee0 + 0x78）之后、jpeg_resync_to_restart（0x2b5da0）之前；
 *   84 B/组件的分配宽度与 libjpeg 的 jpeg_component_info 同宽；字段写序（精度 → 高 → 宽 → 组件表）与 SOF 段布局同构。
 * open：
 *   1. [r7+0xc] 回调的身份（补字节？重启？）未钉 —— 只证它被 (cinfo) 调用且返回 0 时整函数挂起。
 *   2. 入口 r1/r2 写进 +0xc8/+0xc9 的语义未钉（两个单字节标志？）。
 *   3. 0x2b42f0 `mov r3,#1; strb r3,[r2,#0xd]`（r2 = [r5+0x194]）写的是哪个字段、为什么只有 1，未钉。
 *   4. 「SOF 解析」是邻接 + 字段序 + 84 B 三项证据的合取，不是与上游 jdmarker.c 的逐行对照。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2b3f58 0x2b4374 anon_2b3f58 */
/* @0x2b3f58 push {r4, r5, r6, r7, r8, r9, r10, lr} —— 序言（保存 8 个寄存器） */
/* @0x2b3f5c mov r5, r0 */
/* @0x2b3f60 ldr r7, [r0, #0x18] */
/* @0x2b3f64 ldr r3, [r7, #0x4] */
/* @0x2b3f68 ldr r12, [r7] */
/* @0x2b3f6c cmp r3, #0 */
/* @0x2b3f70 strb r1, [r0, #0xc8] */
/* @0x2b3f74 strb r2, [r0, #0xc9] */
/* @0x2b3f78 beq 0x2b4208 <jinit_input_controller+0x328> */
/* @0x2b3f7c subs r3, r3, #1 */
/* @0x2b3f80 ldrb r4, [r12] */
/* @0x2b3f84 addne r12, r12, #1 */
/* @0x2b3f88 beq 0x2b4240 <jinit_input_controller+0x360> */
/* @0x2b3f8c subs r3, r3, #1 */
/* @0x2b3f90 ldrb r8, [r12] */
/* @0x2b3f94 addne r12, r12, #1 */
/* @0x2b3f98 beq 0x2b426c <jinit_input_controller+0x38c> */
/* @0x2b3f9c ldrb r2, [r12] */
/* @0x2b3fa0 subs r3, r3, #1 */
/* @0x2b3fa4 addne r12, r12, #1 */
/* @0x2b3fa8 str r2, [r5, #0xc0] */
/* @0x2b3fac beq 0x2b41e8 <jinit_input_controller+0x308> */
/* @0x2b3fb0 ldrb r2, [r12] */
/* @0x2b3fb4 subs r3, r3, #1 */
/* @0x2b3fb8 addne r12, r12, #1 */
/* @0x2b3fbc lsl r2, r2, #8 */
/* @0x2b3fc0 str r2, [r5, #0x20] */
/* @0x2b3fc4 beq 0x2b428c <jinit_input_controller+0x3ac> */
/* @0x2b3fc8 ldrb r1, [r12] */
/* @0x2b3fcc subs r3, r3, #1 */
/* @0x2b3fd0 addne r12, r12, #1 */
/* @0x2b3fd4 add r2, r1, r2 */
/* @0x2b3fd8 str r2, [r5, #0x20] */
/* @0x2b3fdc beq 0x2b42bc <jinit_input_controller+0x3dc> */
/* @0x2b3fe0 ldrb r2, [r12] */
/* @0x2b3fe4 subs r3, r3, #1 */
/* @0x2b3fe8 addne r12, r12, #1 */
/* @0x2b3fec lsl r2, r2, #8 */
/* @0x2b3ff0 str r2, [r5, #0x1c] */
/* @0x2b3ff4 beq 0x2b4308 <jinit_input_controller+0x428> */
/* @0x2b3ff8 subs r6, r3, #1 */
/* @0x2b3ffc ldrb r3, [r12] */
/* @0x2b4000 addne r10, r12, #1 */
/* @0x2b4004 add r2, r3, r2 */
/* @0x2b4008 str r2, [r5, #0x1c] */
/* @0x2b400c bne 0x2b402c <jinit_input_controller+0x14c> */
/* @0x2b4010 ldr r3, [r7, #0xc] */
/* @0x2b4014 mov r0, r5 */
/* @0x2b4018 blx r3 —— 间接调用 r3 */
/* @0x2b401c cmp r0, #0 */
/* @0x2b4020 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4024 ldr r10, [r7] */
/* @0x2b4028 ldr r6, [r7, #0x4] */
/* @0x2b402c ldrb r2, [r10] */
/* @0x2b4030 mov lr, #100 */
/* @0x2b4034 ldr r3, [r5] */
/* @0x2b4038 mov r1, #1 */
/* @0x2b403c ldr r12, [r5, #0x17c] */
/* @0x2b4040 mov r0, r5 */
/* @0x2b4044 str r2, [r5, #0x24] */
/* @0x2b4048 add r10, r10, r1 */
/* @0x2b404c ldr r2, [r3, #0x4] */
/* @0x2b4050 add r4, r8, r4, lsl #8 */
/* @0x2b4054 str r12, [r3, #0x18] */
/* @0x2b4058 sub r4, r4, #8 */
/* @0x2b405c ldr r12, [r5, #0x1c] */
/* @0x2b4060 sub r6, r6, #1 */
/* @0x2b4064 str r12, [r3, #0x1c] */
/* @0x2b4068 ldr r12, [r5, #0x20] */
/* @0x2b406c str r12, [r3, #0x20] */
/* @0x2b4070 ldr r12, [r5, #0x24] */
/* @0x2b4074 str lr, [r3, #0x14] */
/* @0x2b4078 str r12, [r3, #0x24] */
/* @0x2b407c blx r2 —— 间接调用 r2 */
/* @0x2b4080 ldr r3, [r5, #0x194] */
/* @0x2b4084 ldrb r3, [r3, #0xd] */
/* @0x2b4088 cmp r3, #0 */
/* @0x2b408c bne 0x2b432c <jinit_input_controller+0x44c> */
/* @0x2b4090 ldr r3, [r5, #0x20] */
/* @0x2b4094 cmp r3, #0 */
/* @0x2b4098 beq 0x2b40a8 <jinit_input_controller+0x1c8> */
/* @0x2b409c ldr r3, [r5, #0x1c] */
/* @0x2b40a0 cmp r3, #0 */
/* @0x2b40a4 bne 0x2b42dc <jinit_input_controller+0x3fc> */
/* @0x2b40a8 ldr r3, [r5] */
/* @0x2b40ac mov r2, #32 */
/* @0x2b40b0 mov r0, r5 */
/* @0x2b40b4 str r2, [r3, #0x14] */
/* @0x2b40b8 ldr r3, [r3] */
/* @0x2b40bc blx r3 —— 间接调用 r3 */
/* @0x2b40c0 ldr r3, [r5, #0x24] */
/* @0x2b40c4 add r2, r3, r3, lsl #1 */
/* @0x2b40c8 cmp r2, r4 */
/* @0x2b40cc beq 0x2b40ec <jinit_input_controller+0x20c> */
/* @0x2b40d0 ldr r3, [r5] */
/* @0x2b40d4 mov r2, #11 */
/* @0x2b40d8 mov r0, r5 */
/* @0x2b40dc str r2, [r3, #0x14] */
/* @0x2b40e0 ldr r3, [r3] */
/* @0x2b40e4 blx r3 —— 间接调用 r3 */
/* @0x2b40e8 ldr r3, [r5, #0x24] */
/* @0x2b40ec ldr r4, [r5, #0xc4] */
/* @0x2b40f0 cmp r4, #0 */
/* @0x2b40f4 beq 0x2b4348 <jinit_input_controller+0x468> */
/* @0x2b40f8 cmp r3, #0 */
/* @0x2b40fc ble 0x2b42ec <jinit_input_controller+0x40c> */
/* @0x2b4100 add r4, r4, #84 */
/* @0x2b4104 mov r8, #0 */
/* @0x2b4108 mov r9, #101 */
/* @0x2b410c b 0x2b41bc <jinit_input_controller+0x2dc> */
/* @0x2b4110 ldrb r3, [r10] */
/* @0x2b4114 subs r6, r6, #1 */
/* @0x2b4118 addne r10, r10, #1 */
/* @0x2b411c str r3, [r4, #-0x54] */
/* @0x2b4120 beq 0x2b4220 <jinit_input_controller+0x340> */
/* @0x2b4124 ldrb r3, [r10] */
/* @0x2b4128 subs r6, r6, #1 */
/* @0x2b412c addne r10, r10, #1 */
/* @0x2b4130 and r2, r3, #15 */
/* @0x2b4134 str r2, [r4, #-0x48] */
/* @0x2b4138 asr r3, r3, #4 */
/* @0x2b413c str r3, [r4, #-0x4c] */
/* @0x2b4140 bne 0x2b4160 <jinit_input_controller+0x280> */
/* @0x2b4144 ldr r3, [r7, #0xc] */
/* @0x2b4148 mov r0, r5 */
/* @0x2b414c blx r3 —— 间接调用 r3 */
/* @0x2b4150 cmp r0, #0 */
/* @0x2b4154 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4158 ldr r10, [r7] */
/* @0x2b415c ldr r6, [r7, #0x4] */
/* @0x2b4160 ldrb r3, [r10] */
/* @0x2b4164 mov r1, #1 */
/* @0x2b4168 ldr r2, [r4, #-0x54] */
/* @0x2b416c mov r0, r5 */
/* @0x2b4170 add r8, r8, r1 */
/* @0x2b4174 add r10, r10, r1 */
/* @0x2b4178 str r3, [r4, #-0x44] */
/* @0x2b417c sub r6, r6, #1 */
/* @0x2b4180 ldr r3, [r5] */
/* @0x2b4184 add r4, r4, #84 */
/* @0x2b4188 str r2, [r3, #0x18] */
/* @0x2b418c ldr r12, [r4, #-0xa0] */
/* @0x2b4190 ldr r2, [r3, #0x4] */
/* @0x2b4194 str r12, [r3, #0x1c] */
/* @0x2b4198 ldr r12, [r4, #-0x9c] */
/* @0x2b419c str r12, [r3, #0x20] */
/* @0x2b41a0 ldr r12, [r4, #-0x98] */
/* @0x2b41a4 str r9, [r3, #0x14] */
/* @0x2b41a8 str r12, [r3, #0x24] */
/* @0x2b41ac blx r2 —— 间接调用 r2 */
/* @0x2b41b0 ldr r3, [r5, #0x24] */
/* @0x2b41b4 cmp r3, r8 */
/* @0x2b41b8 ble 0x2b42ec <jinit_input_controller+0x40c> */
/* @0x2b41bc cmp r6, #0 */
/* @0x2b41c0 str r8, [r4, #-0x50] */
/* @0x2b41c4 bne 0x2b4110 <jinit_input_controller+0x230> */
/* @0x2b41c8 ldr r3, [r7, #0xc] */
/* @0x2b41cc mov r0, r5 */
/* @0x2b41d0 blx r3 —— 间接调用 r3 */
/* @0x2b41d4 cmp r0, #0 */
/* @0x2b41d8 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b41dc ldr r10, [r7] */
/* @0x2b41e0 ldr r6, [r7, #0x4] */
/* @0x2b41e4 b 0x2b4110 <jinit_input_controller+0x230> */
/* @0x2b41e8 ldr r3, [r7, #0xc] */
/* @0x2b41ec mov r0, r5 */
/* @0x2b41f0 blx r3 —— 间接调用 r3 */
/* @0x2b41f4 cmp r0, #0 */
/* @0x2b41f8 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b41fc ldr r12, [r7] */
/* @0x2b4200 ldr r3, [r7, #0x4] */
/* @0x2b4204 b 0x2b3fb0 <jinit_input_controller+0xd0> */
/* @0x2b4208 ldr r3, [r7, #0xc] */
/* @0x2b420c blx r3 —— 间接调用 r3 */
/* @0x2b4210 cmp r0, #0 */
/* @0x2b4214 bne 0x2b42b0 <jinit_input_controller+0x3d0> */
/* @0x2b4218 mov r0, #0 */
/* @0x2b421c pop {r4, r5, r6, r7, r8, r9, r10, pc} —— 拆帧/返回 */
/* @0x2b4220 ldr r3, [r7, #0xc] */
/* @0x2b4224 mov r0, r5 */
/* @0x2b4228 blx r3 —— 间接调用 r3 */
/* @0x2b422c cmp r0, #0 */
/* @0x2b4230 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4234 ldr r10, [r7] */
/* @0x2b4238 ldr r6, [r7, #0x4] */
/* @0x2b423c b 0x2b4124 <jinit_input_controller+0x244> */
/* @0x2b4240 ldr r3, [r7, #0xc] */
/* @0x2b4244 mov r0, r5 */
/* @0x2b4248 blx r3 —— 间接调用 r3 */
/* @0x2b424c cmp r0, #0 */
/* @0x2b4250 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4254 ldr r3, [r7, #0x4] */
/* @0x2b4258 ldr r12, [r7] */
/* @0x2b425c subs r3, r3, #1 */
/* @0x2b4260 ldrb r8, [r12] */
/* @0x2b4264 addne r12, r12, #1 */
/* @0x2b4268 bne 0x2b3f9c <jinit_input_controller+0xbc> */
/* @0x2b426c ldr r3, [r7, #0xc] */
/* @0x2b4270 mov r0, r5 */
/* @0x2b4274 blx r3 —— 间接调用 r3 */
/* @0x2b4278 cmp r0, #0 */
/* @0x2b427c beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4280 ldr r12, [r7] */
/* @0x2b4284 ldr r3, [r7, #0x4] */
/* @0x2b4288 b 0x2b3f9c <jinit_input_controller+0xbc> */
/* @0x2b428c ldr r3, [r7, #0xc] */
/* @0x2b4290 mov r0, r5 */
/* @0x2b4294 blx r3 —— 间接调用 r3 */
/* @0x2b4298 cmp r0, #0 */
/* @0x2b429c beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b42a0 ldr r12, [r7] */
/* @0x2b42a4 ldr r3, [r7, #0x4] */
/* @0x2b42a8 ldr r2, [r5, #0x20] */
/* @0x2b42ac b 0x2b3fc8 <jinit_input_controller+0xe8> */
/* @0x2b42b0 ldr r12, [r7] */
/* @0x2b42b4 ldr r3, [r7, #0x4] */
/* @0x2b42b8 b 0x2b3f7c <jinit_input_controller+0x9c> */
/* @0x2b42bc ldr r3, [r7, #0xc] */
/* @0x2b42c0 mov r0, r5 */
/* @0x2b42c4 blx r3 —— 间接调用 r3 */
/* @0x2b42c8 cmp r0, #0 */
/* @0x2b42cc beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b42d0 ldr r12, [r7] */
/* @0x2b42d4 ldr r3, [r7, #0x4] */
/* @0x2b42d8 b 0x2b3fe0 <jinit_input_controller+0x100> */
/* @0x2b42dc ldr r3, [r5, #0x24] */
/* @0x2b42e0 cmp r3, #0 */
/* @0x2b42e4 bgt 0x2b40c4 <jinit_input_controller+0x1e4> */
/* @0x2b42e8 b 0x2b40a8 <jinit_input_controller+0x1c8> */
/* @0x2b42ec ldr r2, [r5, #0x194] */
/* @0x2b42f0 mov r3, #1 */
/* @0x2b42f4 mov r0, r3 */
/* @0x2b42f8 strb r3, [r2, #0xd] */
/* @0x2b42fc str r10, [r7] */
/* @0x2b4300 str r6, [r7, #0x4] */
/* @0x2b4304 pop {r4, r5, r6, r7, r8, r9, r10, pc} —— 拆帧/返回 */
/* @0x2b4308 ldr r3, [r7, #0xc] */
/* @0x2b430c mov r0, r5 */
/* @0x2b4310 blx r3 —— 间接调用 r3 */
/* @0x2b4314 cmp r0, #0 */
/* @0x2b4318 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b431c ldr r12, [r7] */
/* @0x2b4320 ldr r3, [r7, #0x4] */
/* @0x2b4324 ldr r2, [r5, #0x1c] */
/* @0x2b4328 b 0x2b3ff8 <jinit_input_controller+0x118> */
/* @0x2b432c ldr r3, [r5] */
/* @0x2b4330 mov r2, #58 */
/* @0x2b4334 mov r0, r5 */
/* @0x2b4338 str r2, [r3, #0x14] */
/* @0x2b433c ldr r3, [r3] */
/* @0x2b4340 blx r3 —— 间接调用 r3 */
/* @0x2b4344 b 0x2b4090 <jinit_input_controller+0x1b0> */
/* @0x2b4348 ldr r1, [r5, #0x4] */
/* @0x2b434c mov r2, #84 */
/* @0x2b4350 mul r2, r2, r3 */
/* @0x2b4354 mov r0, r5 */
/* @0x2b4358 ldr r3, [r1] */
/* @0x2b435c mov r1, #1 */
/* @0x2b4360 blx r3 —— 间接调用 r3 */
/* @0x2b4364 ldr r3, [r5, #0x24] */
/* @0x2b4368 mov r4, r0 */
/* @0x2b436c str r0, [r5, #0xc4] */
/* @0x2b4370 b 0x2b40f8 <jinit_input_controller+0x218> */

/* ════════════════════════════════════════════════════════════════════
 * §9  anon_2bdb14   0x2bdb14 .. 0x2bdf68   1,108 B / 277 条   in-degree 2，调用点 2
 * 段内 6 个静态函数：4×1024 项表初始化 + 两对孪生扫描体 + 尾调 jcopy 的薄封装
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段**不是一个函数**，是同一父区间里的 6 段代码，共 5 个序言 + 1 个无帧薄封装：
 *   0x2bdb14（push {r3..r9,lr}）、0x2bdc0c（push {r4..r11} + 24 B）、0x2bdd1c（push {r4..r10}）、
 *   0x2bdd9c（push {r4..r7}）、0x2bddf8（push {r4..r11} + 24 B）、0x2bdf30（str lr,[sp,#-4]! 的自建帧）。
 *   对应返回点：0x2bdc08 / 0x2bdd14+bx / 0x2bdd94+bx / 0x2bddf0+bx / 0x2bdf24+bx / 0x2bdf64 ldr pc,[sp],#4。
 * 第 1 段（0x2bdb14..0x2bdc08）：4 次方法表间接调用 `[[r0+4]]`（blx r3），实参 (self, 1, 1024)，
 *   返回值依次写 [r5+0x8]/[r5+0xc]/[r5+0x10]/[r5+0x14]（r5 = [r0+0x1a4]）；随后 1024 次循环把 4 条
 *   16.16 定点递变序列填进这 4 条数组（0x2bdbbc..0x2bdc04：asr #16 后 `str`，四个常数各按固定步长加减）。
 * 第 2/5 段（0x2bdc0c / 0x2bddf8，孪生）：读 [r0+0x5c]/[r0+0x1a4]/[r0+0x120]，把 4 条数组的基址与
 *   `rsb r2,r4,r2,lsl #2` 算出的行跨度摊到栈上，再进各自的扫描体。第 3/4 段（0x2bdd1c / 0x2bdd9c）
 *   是更薄的一层：只保留 [r0+0x24]/[r0+0x5c] 与一次 [sp] 计数递减。
 * 第 6 段（0x2bdf30..0x2bdf64）：自建 4 B 帧只为一个 6 参调用 —— 0x2bdf5c bl jcopy_sample_rows（0x2bc81c），
 *   参数由 (r1→lr, r2→r1, r3→r2, [sp+0x10]→[sp], [r0+0x5c]→[sp+4]) 重排而来。
 * 调用面：bl ×1（jcopy_sample_rows）、blx r3 ×4（第 1 段的 4 次方法表调用，目标在运行期才定）。
 * 谁调它：2 处 —— 0x2be154 / 0x2be16c，都在紧接本段之后的具名函数 jinit_color_deconverter（0x2bdf68）体内；段内 0 处跨子函数调用。
 * open：
 *   1. 6 个子函数各自的参数契约没有分别钉：只有第 1 段与第 6 段能直接读出实参形状。
 *   2. 4 条 1024 项表的用途（缩放/量化/色彩换算）未钉：只证它们是 16.16 定点且按固定步长递变。
 *   3. 方法表 [[r0+4]] 的槽位索引未定（`ldr r3,[r3]` 取的是第 0 槽），4 次调用是否同一槽未钉。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2bdb14 0x2bdf68 anon_2bdb14 */
/* @0x2bdb14 push {r3, r4, r5, r6, r7, r8, r9, lr} —— 序言（保存 8 个寄存器） */
/* @0x2bdb18 mov r1, #1 */
/* @0x2bdb1c ldr r3, [r0, #0x4] */
/* @0x2bdb20 mov r2, #1024 */
/* @0x2bdb24 mov r4, r0 */
/* @0x2bdb28 ldr r5, [r0, #0x1a4] */
/* @0x2bdb2c ldr r3, [r3] */
/* @0x2bdb30 blx r3 —— 间接调用 r3 */
/* @0x2bdb34 ldr r3, [r4, #0x4] */
/* @0x2bdb38 mov r1, #1 */
/* @0x2bdb3c mov r2, #1024 */
/* @0x2bdb40 ldr r3, [r3] */
/* @0x2bdb44 str r0, [r5, #0x8] */
/* @0x2bdb48 mov r0, r4 */
/* @0x2bdb4c blx r3 —— 间接调用 r3 */
/* @0x2bdb50 ldr r3, [r4, #0x4] */
/* @0x2bdb54 mov r1, #1 */
/* @0x2bdb58 mov r2, #1024 */
/* @0x2bdb5c ldr r3, [r3] */
/* @0x2bdb60 str r0, [r5, #0xc] */
/* @0x2bdb64 mov r0, r4 */
/* @0x2bdb68 blx r3 —— 间接调用 r3 */
/* @0x2bdb6c ldr r3, [r4, #0x4] */
/* @0x2bdb70 mov r1, #1 */
/* @0x2bdb74 mov r2, #1024 */
/* @0x2bdb78 ldr r3, [r3] */
/* @0x2bdb7c str r0, [r5, #0x10] */
/* @0x2bdb80 mov r0, r4 */
/* @0x2bdb84 blx r3 —— 间接调用 r3 */
/* @0x2bdb88 ldr r9, [r5, #0x8] */
/* @0x2bdb8c ldr r8, [r5, #0xc] */
/* @0x2bdb90 mov r4, #36096 */
/* @0x2bdb94 ldr r7, [r5, #0x10] */
/* @0x2bdb98 mov r12, #26880 */
/* @0x2bdb9c mov r2, #44800 */
/* @0x2bdba0 mov r3, #2944 */
/* @0x2bdba4 movt r4, #0x2c —— 32 位常数半字 */
/* @0x2bdba8 movt r12, #0x5b —— 32 位常数半字 */
/* @0x2bdbac movt r2, #0xff1d —— 32 位常数半字 */
/* @0x2bdbb0 movt r3, #0xff4d —— 32 位常数半字 */
/* @0x2bdbb4 mov r1, #0 */
/* @0x2bdbb8 str r0, [r5, #0x14] */
/* @0x2bdbbc asr r6, r3, #16 */
/* @0x2bdbc0 asr r5, r2, #16 */
/* @0x2bdbc4 str r6, [r9, r1] */
/* @0x2bdbc8 add r3, r3, #91136 */
/* @0x2bdbcc str r5, [r8, r1] */
/* @0x2bdbd0 add r2, r2, #115712 */
/* @0x2bdbd4 str r12, [r7, r1] */
/* @0x2bdbd8 add r3, r3, #744 */
/* @0x2bdbdc str r4, [r0, r1] */
/* @0x2bdbe0 add r1, r1, #4 */
/* @0x2bdbe4 cmp r1, #1024 */
/* @0x2bdbe8 add r2, r2, #416 */
/* @0x2bdbec sub r12, r12, #46592 */
/* @0x2bdbf0 sub r4, r4, #22528 */
/* @0x2bdbf4 add r3, r3, #1 */
/* @0x2bdbf8 add r2, r2, #2 */
/* @0x2bdbfc sub r12, r12, #210 */
/* @0x2bdc00 sub r4, r4, #26 */
/* @0x2bdc04 bne 0x2bdbbc <jinit_d_coef_controller+0x21c> */
/* @0x2bdc08 pop {r3, r4, r5, r6, r7, r8, r9, pc} —— 拆帧/返回 */
/* @0x2bdc0c push {r4, r5, r6, r7, r8, r9, r10, r11} —— 序言（保存 8 个寄存器） */
/* @0x2bdc10 sub sp, sp, #24 */
/* @0x2bdc14 ldr r6, [r0, #0x5c] */
/* @0x2bdc18 str r3, [sp, #0xc] —— 栈槽 */
/* @0x2bdc1c ldr r3, [r0, #0x1a4] */
/* @0x2bdc20 ldr r0, [r0, #0x120] */
/* @0x2bdc24 ldr r4, [sp, #0xc] —— 栈槽 */
/* @0x2bdc28 ldr r11, [r3, #0xc] */
/* @0x2bdc2c ldr r12, [r3, #0x10] */
/* @0x2bdc30 rsb r2, r4, r2, lsl #2 */
/* @0x2bdc34 ldr r10, [r3, #0x8] */
/* @0x2bdc38 ldr r9, [r3, #0x14] */
/* @0x2bdc3c str r2, [sp, #0x14] —— 栈槽 */
/* @0x2bdc40 str r1, [sp, #0x10] —— 栈槽 */
/* @0x2bdc44 str r11, [sp, #0x4] —— 栈槽 */
/* @0x2bdc48 str r12, [sp, #0x8] —— 栈槽 */
/* @0x2bdc4c ldr r11, [sp, #0x38] —— 栈槽 */
/* @0x2bdc50 subs r11, r11, #1 */
/* @0x2bdc54 str r11, [sp, #0x38] —— 栈槽 */
/* @0x2bdc58 bmi 0x2bdd10 <jinit_d_coef_controller+0x370> */
/* @0x2bdc5c ldr r2, [sp, #0x10] —— 栈槽 */
/* @0x2bdc60 cmp r6, #0 */
/* @0x2bdc64 ldr r4, [sp, #0xc] —— 栈槽 */
/* @0x2bdc68 ldr r11, [sp, #0x14] —— 栈槽 */
/* @0x2bdc6c ldr r12, [r2] */
/* @0x2bdc70 ldr r1, [r2, #0x4] */
/* @0x2bdc74 add r3, r4, r11 */
/* @0x2bdc78 ldr r2, [r2, #0x8] */
/* @0x2bdc7c ldr r12, [r12, r3] */
/* @0x2bdc80 ldr r7, [r1, r3] */
/* @0x2bdc84 ldr r8, [r2, r3] */
/* @0x2bdc88 ldr r2, [r4], #4 */
/* @0x2bdc8c str r12, [sp] —— 栈槽 */
/* @0x2bdc90 str r4, [sp, #0xc] —— 栈槽 */
/* @0x2bdc94 beq 0x2bdc4c <jinit_d_coef_controller+0x2ac> */
/* @0x2bdc98 mov r3, #0 */
/* @0x2bdc9c ldrb r4, [r8, r3] */
/* @0x2bdca0 add r2, r2, #3 */
/* @0x2bdca4 ldr r12, [sp] —— 栈槽 */
/* @0x2bdca8 ldr r11, [r10, r4, lsl #2] */
/* @0x2bdcac ldrb r1, [r12, r3] */
/* @0x2bdcb0 add r11, r0, r11 */
/* @0x2bdcb4 ldrb r12, [r7, r3] */
/* @0x2bdcb8 add r5, r0, r1 */
/* @0x2bdcbc add r3, r3, #1 */
/* @0x2bdcc0 ldrb r11, [r11, r1] */
/* @0x2bdcc4 cmp r3, r6 */
/* @0x2bdcc8 sxth r12, r12 */
/* @0x2bdccc strb r11, [r2, #-0x3] */
/* @0x2bdcd0 ldr r11, [sp, #0x8] —— 栈槽 */
/* @0x2bdcd4 ldr r4, [r11, r4, lsl #2] */
/* @0x2bdcd8 ldr r11, [r9, r12, lsl #2] */
/* @0x2bdcdc add r4, r11, r4 */
/* @0x2bdce0 ldrb r4, [r5, r4, asr #16] */
/* @0x2bdce4 strb r4, [r2, #-0x2] */
/* @0x2bdce8 ldr r4, [sp, #0x4] —— 栈槽 */
/* @0x2bdcec ldr r12, [r4, r12, lsl #2] */
/* @0x2bdcf0 add r12, r0, r12 */
/* @0x2bdcf4 ldrb r1, [r12, r1] */
/* @0x2bdcf8 strb r1, [r2, #-0x1] */
/* @0x2bdcfc bne 0x2bdc9c <jinit_d_coef_controller+0x2fc> */
/* @0x2bdd00 ldr r11, [sp, #0x38] —— 栈槽 */
/* @0x2bdd04 subs r11, r11, #1 */
/* @0x2bdd08 str r11, [sp, #0x38] —— 栈槽 */
/* @0x2bdd0c bpl 0x2bdc5c <jinit_d_coef_controller+0x2bc> */
/* @0x2bdd10 add sp, sp, #24 */
/* @0x2bdd14 pop {r4, r5, r6, r7, r8, r9, r10, r11} —— 拆帧（随后 bx lr） */
/* @0x2bdd18 bx lr —— 返回 */
/* @0x2bdd1c push {r4, r5, r6, r7, r8, r9, r10} —— 序言（保存 7 个寄存器） */
/* @0x2bdd20 ldr r9, [sp, #0x1c] —— 栈槽 */
/* @0x2bdd24 ldr r8, [r0, #0x24] */
/* @0x2bdd28 subs r9, r9, #1 */
/* @0x2bdd2c ldr r7, [r0, #0x5c] */
/* @0x2bdd30 bmi 0x2bdd94 <jinit_d_coef_controller+0x3f4> */
/* @0x2bdd34 sub r10, r3, r2, lsl #2 */
/* @0x2bdd38 lsl r5, r2, #2 */
/* @0x2bdd3c cmp r8, #0 */
/* @0x2bdd40 ble 0x2bdd84 <jinit_d_coef_controller+0x3e4> */
/* @0x2bdd44 sub r6, r1, #4 */
/* @0x2bdd48 mov r4, #0 */
/* @0x2bdd4c ldr r3, [r6, #0x4]! */
/* @0x2bdd50 cmp r7, #0 */
/* @0x2bdd54 ldr r2, [r10, r5] */
/* @0x2bdd58 ldr r3, [r3, r5] */
/* @0x2bdd5c add r2, r2, r4 */
/* @0x2bdd60 addne r12, r3, r7 */
/* @0x2bdd64 beq 0x2bdd78 <jinit_d_coef_controller+0x3d8> */
/* @0x2bdd68 ldrb r0, [r3], #1 */
/* @0x2bdd6c cmp r3, r12 */
/* @0x2bdd70 strb r0, [r2], r8 */
/* @0x2bdd74 bne 0x2bdd68 <jinit_d_coef_controller+0x3c8> */
/* @0x2bdd78 add r4, r4, #1 */
/* @0x2bdd7c cmp r4, r8 */
/* @0x2bdd80 bne 0x2bdd4c <jinit_d_coef_controller+0x3ac> */
/* @0x2bdd84 sub r9, r9, #1 */
/* @0x2bdd88 add r5, r5, #4 */
/* @0x2bdd8c cmn r9, #1 */
/* @0x2bdd90 bne 0x2bdd3c <jinit_d_coef_controller+0x39c> */
/* @0x2bdd94 pop {r4, r5, r6, r7, r8, r9, r10} —— 拆帧（随后 bx lr） */
/* @0x2bdd98 bx lr —— 返回 */
/* @0x2bdd9c push {r4, r5, r6, r7} —— 序言（保存 4 个寄存器） */
/* @0x2bdda0 rsb r2, r3, r2, lsl #2 */
/* @0x2bdda4 ldr r7, [r0, #0x5c] */
/* @0x2bdda8 ldr r6, [sp, #0x10] —— 栈槽 */
/* @0x2bddac subs r6, r6, #1 */
/* @0x2bddb0 bmi 0x2bddf0 <jinit_d_coef_controller+0x450> */
/* @0x2bddb4 ldr r4, [r1] */
/* @0x2bddb8 add r12, r3, r2 */
/* @0x2bddbc cmp r7, #0 */
/* @0x2bddc0 ldr r0, [r3], #4 */
/* @0x2bddc4 ldr r4, [r4, r12] */
/* @0x2bddc8 beq 0x2bddac <jinit_d_coef_controller+0x40c> */
/* @0x2bddcc add r5, r4, r7 */
/* @0x2bddd0 ldrb r12, [r4], #1 */
/* @0x2bddd4 cmp r4, r5 */
/* @0x2bddd8 strb r12, [r0, #0x2] */
/* @0x2bdddc strb r12, [r0, #0x1] */
/* @0x2bdde0 strb r12, [r0], #3 */
/* @0x2bdde4 bne 0x2bddd0 <jinit_d_coef_controller+0x430> */
/* @0x2bdde8 subs r6, r6, #1 */
/* @0x2bddec bpl 0x2bddb4 <jinit_d_coef_controller+0x414> */
/* @0x2bddf0 pop {r4, r5, r6, r7} —— 拆帧（随后 bx lr） */
/* @0x2bddf4 bx lr —— 返回 */
/* @0x2bddf8 push {r4, r5, r6, r7, r8, r9, r10, r11} —— 序言（保存 8 个寄存器） */
/* @0x2bddfc sub sp, sp, #24 */
/* @0x2bde00 ldr r5, [r0, #0x5c] */
/* @0x2bde04 str r3, [sp, #0x10] —— 栈槽 */
/* @0x2bde08 ldr r3, [r0, #0x1a4] */
/* @0x2bde0c ldr r0, [r0, #0x120] */
/* @0x2bde10 ldr r4, [sp, #0x10] —— 栈槽 */
/* @0x2bde14 ldr r6, [r3, #0xc] */
/* @0x2bde18 ldr r11, [r3, #0x10] */
/* @0x2bde1c rsb r2, r4, r2, lsl #2 */
/* @0x2bde20 ldr r10, [r3, #0x8] */
/* @0x2bde24 ldr r9, [r3, #0x14] */
/* @0x2bde28 str r2, [sp, #0x14] —— 栈槽 */
/* @0x2bde2c str r1, [sp, #0xc] —— 栈槽 */
/* @0x2bde30 str r6, [sp, #0x4] —— 栈槽 */
/* @0x2bde34 str r11, [sp, #0x8] —— 栈槽 */
/* @0x2bde38 ldr r6, [sp, #0x38] —— 栈槽 */
/* @0x2bde3c subs r6, r6, #1 */
/* @0x2bde40 str r6, [sp, #0x38] —— 栈槽 */
/* @0x2bde44 bmi 0x2bdf20 <jinit_d_coef_controller+0x580> */
/* @0x2bde48 ldr r12, [sp, #0xc] —— 栈槽 */
/* @0x2bde4c cmp r5, #0 */
/* @0x2bde50 ldr r2, [sp, #0xc] —— 栈槽 */
/* @0x2bde54 ldr r6, [sp, #0x10] —— 栈槽 */
/* @0x2bde58 ldr r11, [sp, #0x14] —— 栈槽 */
/* @0x2bde5c ldr r4, [r12] */
/* @0x2bde60 ldr r1, [r2, #0x8] */
/* @0x2bde64 add r3, r6, r11 */
/* @0x2bde68 ldr r2, [r2, #0xc] */
/* @0x2bde6c ldr r12, [r12, #0x4] */
/* @0x2bde70 ldr r4, [r4, r3] */
/* @0x2bde74 ldr r8, [r2, r3] */
/* @0x2bde78 ldr r6, [r12, r3] */
/* @0x2bde7c ldr r7, [r1, r3] */
/* @0x2bde80 ldr r3, [sp, #0x10] —— 栈槽 */
/* @0x2bde84 str r4, [sp] —— 栈槽 */
/* @0x2bde88 ldr r2, [r3], #4 */
/* @0x2bde8c str r3, [sp, #0x10] —— 栈槽 */
/* @0x2bde90 beq 0x2bde38 <jinit_d_coef_controller+0x498> */
/* @0x2bde94 mov r3, #0 */
/* @0x2bde98 ldrb r4, [r7, r3] */
/* @0x2bde9c add r2, r2, #4 */
/* @0x2bdea0 ldr r11, [sp] —— 栈槽 */
/* @0x2bdea4 ldrb r12, [r6, r3] */
/* @0x2bdea8 ldrb r1, [r11, r3] */
/* @0x2bdeac ldr r11, [r10, r4, lsl #2] */
/* @0x2bdeb0 sxth r12, r12 */
/* @0x2bdeb4 add r11, r1, r11 */
/* @0x2bdeb8 rsb r11, r11, #255 */
/* @0x2bdebc ldrb r11, [r0, r11] */
/* @0x2bdec0 strb r11, [r2, #-0x4] */
/* @0x2bdec4 ldr r11, [sp, #0x8] —— 栈槽 */
/* @0x2bdec8 ldr r4, [r11, r4, lsl #2] */
/* @0x2bdecc ldr r11, [r9, r12, lsl #2] */
/* @0x2bded0 add r4, r11, r4 */
/* @0x2bded4 add r4, r1, r4, asr #16 */
/* @0x2bded8 rsb r4, r4, #255 */
/* @0x2bdedc ldrb r4, [r0, r4] */
/* @0x2bdee0 strb r4, [r2, #-0x3] */
/* @0x2bdee4 ldr r4, [sp, #0x4] —— 栈槽 */
/* @0x2bdee8 ldr r12, [r4, r12, lsl #2] */
/* @0x2bdeec add r1, r1, r12 */
/* @0x2bdef0 rsb r1, r1, #255 */
/* @0x2bdef4 ldrb r1, [r0, r1] */
/* @0x2bdef8 strb r1, [r2, #-0x2] */
/* @0x2bdefc ldrb r1, [r8, r3] */
/* @0x2bdf00 add r3, r3, #1 */
/* @0x2bdf04 cmp r3, r5 */
/* @0x2bdf08 strb r1, [r2, #-0x1] */
/* @0x2bdf0c bne 0x2bde98 <jinit_d_coef_controller+0x4f8> */
/* @0x2bdf10 ldr r6, [sp, #0x38] —— 栈槽 */
/* @0x2bdf14 subs r6, r6, #1 */
/* @0x2bdf18 str r6, [sp, #0x38] —— 栈槽 */
/* @0x2bdf1c bpl 0x2bde48 <jinit_d_coef_controller+0x4a8> */
/* @0x2bdf20 add sp, sp, #24 */
/* @0x2bdf24 pop {r4, r5, r6, r7, r8, r9, r10, r11} —— 拆帧（随后 bx lr） */
/* @0x2bdf28 bx lr —— 返回 */
/* @0x2bdf2c bx lr —— 返回 */
/* @0x2bdf30 str lr, [sp, #-0x4]! —— 栈槽 */
/* @0x2bdf34 sub sp, sp, #12 */
/* @0x2bdf38 ldr lr, [r1] */
/* @0x2bdf3c mov r1, r2 */
/* @0x2bdf40 ldr r12, [sp, #0x10] —— 栈槽 */
/* @0x2bdf44 mov r2, r3 */
/* @0x2bdf48 mov r3, #0 */
/* @0x2bdf4c str r12, [sp] —— 栈槽 */
/* @0x2bdf50 ldr r12, [r0, #0x5c] */
/* @0x2bdf54 mov r0, lr */
/* @0x2bdf58 str r12, [sp, #0x4] —— 栈槽 */
/* @0x2bdf5c bl 0x2bc81c <jcopy_sample_rows> —— 调 jcopy_sample_rows */
/* @0x2bdf60 add sp, sp, #12 */
/* @0x2bdf64 ldr pc, [sp], #4 —— 栈槽 */

/* ════════════════════════════════════════════════════════════════════
 * §10  anon_2bb3c4   0x2bb3c4 .. 0x2bb8b4   1,264 B / 316 条   in-degree 3，调用点 3
 * 16 位直方图的盒扫描：行步长 64 B、2 个嵌套内外环、无调用
 * ────────────────────────────────────────────────────────────────────
 * 边界：本段是**段内窗口**（首条 0x2bb3c4 是 `ldr r0,[r0,#0x18]` 而不是序言；序言在 0x2bb3c8），
 *   末条 0x2bb8b0 `b 0x2bb6d8` 跳回本窗口内。窗口内 0 条外跳、0 条 bl。
 * 入口：r0 = 结构（只读 [r0+0x18] 一次，当行基址），r1 = 6 字描述符 {+0/+4/+8/+0xc/+0x10/+0x14}
 *   （0x2bb3d0..0x2bb3f4 一次性摊平到寄存器），r2/r3 在本窗口内未被读取。
 * 数据形态：0x2bb400 `add r3,r5,r0,lsl #5` + 0x2bb410 `lsl r3,r3,#1` ⇒ 行索引乘 32 项、项宽 2 B；
 *   0x2bb46c `add r4,r4,#64` 是行步长，0x2bb454 `ldrh r0,[r1,#2]!` 是列扫描 —— 一张 16 位直方图。
 * 三段环：0x2bb418（外层，r12 从 r10 到 r2）、0x2bb434（中层，行 r8 从 r0 到 r11）、
 *   0x2bb460（内层，列 r3 从 r5 到 r6）；命中非零项就走 0x2bb778 的分支块，全部为零则记边界后继续。
 *   0x2bb4a4..0x2bb550 是第二轮（反向）扫描：0x2bb814 起从 r11 往下退（sub r4,#1 / sub r9,#64），
 *   两轮夹出盒的上下/左右界，写回描述符 [r1+0x4]/[r1+0x8]。
 * 出口：唯一 0x2bb6e4 pop {r4..r11} / 0x2bb6e8 bx lr（注意序言在 0x2bb3c8，与入口地址差 4）。
 * 被调：0 条。谁调它：3 处，全部在 anon_2bb0f8 体内（0x2bc25c / 0x2bc36c / 0x2bc37c）。
 * 定位证据（不据此命名）：本段紧跟在 jinit_1pass_quantizer（0x2bad30 + 0x3c8）之后、jinit_2pass_quantizer
 *   （0x2bc654）之前，与 1-pass 量化器的盒划分例程同处一段；16 位直方图 + 32 列行宽与它的数据布局同构。
 * open：
 *   1. 盒边界的 4 个字段只证被读写（+0x4/+0x8），它们与「体积/像素数」的对应关系未钉。
 *   2. 0x2bb6d8 起的公共收尾块（含 0x2bb8ac `mov r0,#0`）返回值语义未钉。
 *   3. 「这是 1-pass 量化器的盒扫描」是邻接 + 数据布局证据，不是与上游 jquant1.c 的逐行对照。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2bb3c4 0x2bb8b4 anon_2bb3c4 */
/* @0x2bb3c4 ldr r0, [r0, #0x18] */
/* @0x2bb3c8 push {r4, r5, r6, r7, r8, r9, r10, r11} —— 序言（保存 8 个寄存器） */
/* @0x2bb3cc sub sp, sp, #16 */
/* @0x2bb3d0 ldr r10, [r1] */
/* @0x2bb3d4 ldr r2, [r1, #0x4] */
/* @0x2bb3d8 str r0, [sp, #0xc] —— 栈槽 */
/* @0x2bb3dc ldr r0, [r1, #0x8] */
/* @0x2bb3e0 cmp r10, r2 */
/* @0x2bb3e4 str r1, [sp, #0x8] —— 栈槽 */
/* @0x2bb3e8 ldr r11, [r1, #0xc] */
/* @0x2bb3ec str r0, [sp] —— 栈槽 */
/* @0x2bb3f0 ldr r5, [r1, #0x10] */
/* @0x2bb3f4 ldr r6, [r1, #0x14] */
/* @0x2bb3f8 bge 0x2bb4a4 <jinit_1pass_quantizer+0x774> */
/* @0x2bb3fc ldr r1, [sp, #0xc] —— 栈槽 */
/* @0x2bb400 add r3, r5, r0, lsl #5 */
/* @0x2bb404 mov r12, r10 */
/* @0x2bb408 mov r7, #0 */
/* @0x2bb40c add r9, r1, r10, lsl #2 */
/* @0x2bb410 lsl r3, r3, #1 */
/* @0x2bb414 str r3, [sp, #0x4] —— 栈槽 */
/* @0x2bb418 ldr r0, [sp] —— 栈槽 */
/* @0x2bb41c cmp r0, r11 */
/* @0x2bb420 bgt 0x2bb47c <jinit_1pass_quantizer+0x74c> */
/* @0x2bb424 ldr r4, [r9, r7] */
/* @0x2bb428 mov r8, r0 */
/* @0x2bb42c ldr r1, [sp, #0x4] —— 栈槽 */
/* @0x2bb430 add r4, r4, r1 */
/* @0x2bb434 cmp r5, r6 */
/* @0x2bb438 bgt 0x2bb46c <jinit_1pass_quantizer+0x73c> */
/* @0x2bb43c ldrh r3, [r4] */
/* @0x2bb440 cmp r3, #0 */
/* @0x2bb444 bne 0x2bb778 <jinit_1pass_quantizer+0xa48> */
/* @0x2bb448 mov r1, r4 */
/* @0x2bb44c mov r3, r5 */
/* @0x2bb450 b 0x2bb460 <jinit_1pass_quantizer+0x730> */
/* @0x2bb454 ldrh r0, [r1, #2]! */
/* @0x2bb458 cmp r0, #0 */
/* @0x2bb45c bne 0x2bb778 <jinit_1pass_quantizer+0xa48> */
/* @0x2bb460 add r3, r3, #1 */
/* @0x2bb464 cmp r6, r3 */
/* @0x2bb468 bge 0x2bb454 <jinit_1pass_quantizer+0x724> */
/* @0x2bb46c add r8, r8, #1 */
/* @0x2bb470 add r4, r4, #64 */
/* @0x2bb474 cmp r11, r8 */
/* @0x2bb478 bge 0x2bb434 <jinit_1pass_quantizer+0x704> */
/* @0x2bb47c add r12, r12, #1 */
/* @0x2bb480 add r7, r7, #4 */
/* @0x2bb484 cmp r2, r12 */
/* @0x2bb488 bge 0x2bb418 <jinit_1pass_quantizer+0x6e8> */
/* @0x2bb48c mov r12, r10 */
/* @0x2bb490 b 0x2bb788 <jinit_1pass_quantizer+0xa58> */
/* @0x2bb494 ldr r1, [sp, #0x8] —— 栈槽 */
/* @0x2bb498 mov r10, r12 */
/* @0x2bb49c mov r2, r4 */
/* @0x2bb4a0 str r4, [r1, #0x4] */
/* @0x2bb4a4 ldr r1, [sp] —— 栈槽 */
/* @0x2bb4a8 cmp r1, r11 */
/* @0x2bb4ac bge 0x2bb550 <jinit_1pass_quantizer+0x820> */
/* @0x2bb4b0 sub r3, r10, #-1073741823 */
/* @0x2bb4b4 ldr r0, [sp, #0xc] —— 栈槽 */
/* @0x2bb4b8 lsl r8, r1, #6 */
/* @0x2bb4bc lsl r9, r5, #1 */
/* @0x2bb4c0 mov r12, r1 */
/* @0x2bb4c4 add r3, r0, r3, lsl #2 */
/* @0x2bb4c8 str r3, [sp, #0x4] —— 栈槽 */
/* @0x2bb4cc cmp r2, r10 */
/* @0x2bb4d0 blt 0x2bb528 <jinit_1pass_quantizer+0x7f8> */
/* @0x2bb4d4 ldr r7, [sp, #0x4] —— 栈槽 */
/* @0x2bb4d8 mov r4, r10 */
/* @0x2bb4dc ldr r3, [r7, #0x4]! */
/* @0x2bb4e0 cmp r5, r6 */
/* @0x2bb4e4 add r3, r3, r8 */
/* @0x2bb4e8 add r1, r3, r9 */
/* @0x2bb4ec bgt 0x2bb51c <jinit_1pass_quantizer+0x7ec> */
/* @0x2bb4f0 ldrh r3, [r3, r9] */
/* @0x2bb4f4 cmp r3, #0 */
/* @0x2bb4f8 bne 0x2bb814 <jinit_1pass_quantizer+0xae4> */
/* @0x2bb4fc mov r3, r5 */
/* @0x2bb500 b 0x2bb510 <jinit_1pass_quantizer+0x7e0> */
/* @0x2bb504 ldrh r0, [r1, #2]! */
/* @0x2bb508 cmp r0, #0 */
/* @0x2bb50c bne 0x2bb814 <jinit_1pass_quantizer+0xae4> */
/* @0x2bb510 add r3, r3, #1 */
/* @0x2bb514 cmp r6, r3 */
/* @0x2bb518 bge 0x2bb504 <jinit_1pass_quantizer+0x7d4> */
/* @0x2bb51c add r4, r4, #1 */
/* @0x2bb520 cmp r4, r2 */
/* @0x2bb524 ble 0x2bb4dc <jinit_1pass_quantizer+0x7ac> */
/* @0x2bb528 add r12, r12, #1 */
/* @0x2bb52c add r8, r8, #64 */
/* @0x2bb530 cmp r11, r12 */
/* @0x2bb534 bge 0x2bb4cc <jinit_1pass_quantizer+0x79c> */
/* @0x2bb538 ldr r12, [sp] —— 栈槽 */
/* @0x2bb53c b 0x2bb824 <jinit_1pass_quantizer+0xaf4> */
/* @0x2bb540 ldr r1, [sp, #0x8] —— 栈槽 */
/* @0x2bb544 mov r11, r4 */
/* @0x2bb548 str r12, [sp] —— 栈槽 */
/* @0x2bb54c str r4, [r1, #0xc] */
/* @0x2bb550 cmp r5, r6 */
/* @0x2bb554 bge 0x2bb5fc <jinit_1pass_quantizer+0x8cc> */
/* @0x2bb558 ldr r0, [sp] —— 栈槽 */
/* @0x2bb55c sub r3, r10, #-1073741823 */
/* @0x2bb560 ldr r1, [sp, #0xc] —— 栈槽 */
/* @0x2bb564 mov r12, r5 */
/* @0x2bb568 lsl r9, r0, #6 */
/* @0x2bb56c add r3, r1, r3, lsl #2 */
/* @0x2bb570 str r3, [sp, #0x4] —— 栈槽 */
/* @0x2bb574 cmp r2, r10 */
/* @0x2bb578 blt 0x2bb5d8 <jinit_1pass_quantizer+0x8a8> */
/* @0x2bb57c ldr r8, [sp, #0x4] —— 栈槽 */
/* @0x2bb580 lsl r7, r12, #1 */
/* @0x2bb584 mov r4, r10 */
/* @0x2bb588 ldr r0, [sp] —— 栈槽 */
/* @0x2bb58c ldr r3, [r8, #0x4]! */
/* @0x2bb590 cmp r11, r0 */
/* @0x2bb594 add r3, r3, r9 */
/* @0x2bb598 add r1, r3, r7 */
/* @0x2bb59c blt 0x2bb5cc <jinit_1pass_quantizer+0x89c> */
/* @0x2bb5a0 ldrh r3, [r3, r7] */
/* @0x2bb5a4 cmp r3, #0 */
/* @0x2bb5a8 bne 0x2bb6ec <jinit_1pass_quantizer+0x9bc> */
/* @0x2bb5ac ldr r3, [sp] —— 栈槽 */
/* @0x2bb5b0 b 0x2bb5c0 <jinit_1pass_quantizer+0x890> */
/* @0x2bb5b4 ldrh r0, [r1, #64]! */
/* @0x2bb5b8 cmp r0, #0 */
/* @0x2bb5bc bne 0x2bb6ec <jinit_1pass_quantizer+0x9bc> */
/* @0x2bb5c0 add r3, r3, #1 */
/* @0x2bb5c4 cmp r3, r11 */
/* @0x2bb5c8 ble 0x2bb5b4 <jinit_1pass_quantizer+0x884> */
/* @0x2bb5cc add r4, r4, #1 */
/* @0x2bb5d0 cmp r2, r4 */
/* @0x2bb5d4 bge 0x2bb588 <jinit_1pass_quantizer+0x858> */
/* @0x2bb5d8 add r12, r12, #1 */
/* @0x2bb5dc cmp r6, r12 */
/* @0x2bb5e0 bge 0x2bb574 <jinit_1pass_quantizer+0x844> */
/* @0x2bb5e4 mov r12, r5 */
/* @0x2bb5e8 b 0x2bb6fc <jinit_1pass_quantizer+0x9cc> */
/* @0x2bb5ec ldr r1, [sp, #0x8] —— 栈槽 */
/* @0x2bb5f0 mov r5, r12 */
/* @0x2bb5f4 mov r6, r4 */
/* @0x2bb5f8 str r4, [r1, #0x14] */
/* @0x2bb5fc ldr r0, [sp] —— 栈槽 */
/* @0x2bb600 rsb r1, r10, r2 */
/* @0x2bb604 rsb r12, r5, r6 */
/* @0x2bb608 cmp r2, r10 */
/* @0x2bb60c rsb r3, r0, r11 */
/* @0x2bb610 lsl r1, r1, #4 */
/* @0x2bb614 lsl r0, r3, #3 */
/* @0x2bb618 add r0, r0, r3, lsl #2 */
/* @0x2bb61c lsl r3, r12, #3 */
/* @0x2bb620 mul r0, r0, r0 */
/* @0x2bb624 mla r1, r1, r1, r0 */
/* @0x2bb628 mla r3, r3, r3, r1 */
/* @0x2bb62c ldr r1, [sp, #0x8] —— 栈槽 */
/* @0x2bb630 str r3, [r1, #0x18] */
/* @0x2bb634 blt 0x2bb8ac <jinit_1pass_quantizer+0xb7c> */
/* @0x2bb638 ldr r3, [sp] —— 栈槽 */
/* @0x2bb63c add r2, r2, #1 */
/* @0x2bb640 ldr r0, [sp, #0xc] —— 栈槽 */
/* @0x2bb644 mov r8, #0 */
/* @0x2bb648 add r12, r6, #1 */
/* @0x2bb64c rsb r2, r10, r2 */
/* @0x2bb650 add r9, r5, r3, lsl #5 */
/* @0x2bb654 add r3, r5, r11, lsl #5 */
/* @0x2bb658 sub r9, r9, #-2147483647 */
/* @0x2bb65c add r10, r0, r10, lsl #2 */
/* @0x2bb660 lsl r3, r3, #1 */
/* @0x2bb664 mov r0, r8 */
/* @0x2bb668 lsl r9, r9, #1 */
/* @0x2bb66c add r3, r3, #62 */
/* @0x2bb670 str r2, [sp, #0x4] —— 栈槽 */
/* @0x2bb674 str r3, [sp, #0xc] —— 栈槽 */
/* @0x2bb678 ldr r2, [sp] —— 栈槽 */
/* @0x2bb67c cmp r11, r2 */
/* @0x2bb680 blt 0x2bb6c8 <jinit_1pass_quantizer+0x998> */
/* @0x2bb684 ldr r7, [r10, r8, lsl #2] */
/* @0x2bb688 ldr r3, [sp, #0xc] —— 栈槽 */
/* @0x2bb68c add r4, r7, r9 */
/* @0x2bb690 add r7, r7, r3 */
/* @0x2bb694 cmp r6, r5 */
/* @0x2bb698 blt 0x2bb6bc <jinit_1pass_quantizer+0x98c> */
/* @0x2bb69c mov r2, r4 */
/* @0x2bb6a0 mov r3, r5 */
/* @0x2bb6a4 ldrh r1, [r2, #2]! */
/* @0x2bb6a8 add r3, r3, #1 */
/* @0x2bb6ac cmp r1, #0 */
/* @0x2bb6b0 addne r0, r0, #1 */
/* @0x2bb6b4 cmp r3, r12 */
/* @0x2bb6b8 bne 0x2bb6a4 <jinit_1pass_quantizer+0x974> */
/* @0x2bb6bc add r4, r4, #64 */
/* @0x2bb6c0 cmp r4, r7 */
/* @0x2bb6c4 bne 0x2bb694 <jinit_1pass_quantizer+0x964> */
/* @0x2bb6c8 ldr r1, [sp, #0x4] —— 栈槽 */
/* @0x2bb6cc add r8, r8, #1 */
/* @0x2bb6d0 cmp r8, r1 */
/* @0x2bb6d4 bne 0x2bb678 <jinit_1pass_quantizer+0x948> */
/* @0x2bb6d8 ldr r1, [sp, #0x8] —— 栈槽 */
/* @0x2bb6dc str r0, [r1, #0x1c] */
/* @0x2bb6e0 add sp, sp, #16 */
/* @0x2bb6e4 pop {r4, r5, r6, r7, r8, r9, r10, r11} —— 拆帧（随后 bx lr） */
/* @0x2bb6e8 bx lr —— 返回 */
/* @0x2bb6ec ldr r1, [sp, #0x8] —— 栈槽 */
/* @0x2bb6f0 cmp r6, r12 */
/* @0x2bb6f4 str r12, [r1, #0x10] */
/* @0x2bb6f8 ble 0x2bb770 <jinit_1pass_quantizer+0xa40> */
/* @0x2bb6fc mov r4, r6 */
/* @0x2bb700 cmp r2, r10 */
/* @0x2bb704 blt 0x2bb764 <jinit_1pass_quantizer+0xa34> */
/* @0x2bb708 ldr r8, [sp, #0x4] —— 栈槽 */
/* @0x2bb70c lsl r7, r4, #1 */
/* @0x2bb710 mov r5, r10 */
/* @0x2bb714 ldr r0, [sp] —— 栈槽 */
/* @0x2bb718 ldr r3, [r8, #0x4]! */
/* @0x2bb71c cmp r11, r0 */
/* @0x2bb720 add r3, r3, r9 */
/* @0x2bb724 add r1, r3, r7 */
/* @0x2bb728 blt 0x2bb758 <jinit_1pass_quantizer+0xa28> */
/* @0x2bb72c ldrh r3, [r3, r7] */
/* @0x2bb730 cmp r3, #0 */
/* @0x2bb734 bne 0x2bb5ec <jinit_1pass_quantizer+0x8bc> */
/* @0x2bb738 ldr r3, [sp] —— 栈槽 */
/* @0x2bb73c b 0x2bb74c <jinit_1pass_quantizer+0xa1c> */
/* @0x2bb740 ldrh r0, [r1, #64]! */
/* @0x2bb744 cmp r0, #0 */
/* @0x2bb748 bne 0x2bb5ec <jinit_1pass_quantizer+0x8bc> */
/* @0x2bb74c add r3, r3, #1 */
/* @0x2bb750 cmp r11, r3 */
/* @0x2bb754 bge 0x2bb740 <jinit_1pass_quantizer+0xa10> */
/* @0x2bb758 add r5, r5, #1 */
/* @0x2bb75c cmp r2, r5 */
/* @0x2bb760 bge 0x2bb714 <jinit_1pass_quantizer+0x9e4> */
/* @0x2bb764 sub r4, r4, #1 */
/* @0x2bb768 cmp r4, r12 */
/* @0x2bb76c bge 0x2bb700 <jinit_1pass_quantizer+0x9d0> */
/* @0x2bb770 mov r5, r12 */
/* @0x2bb774 b 0x2bb5fc <jinit_1pass_quantizer+0x8cc> */
/* @0x2bb778 ldr r3, [sp, #0x8] —— 栈槽 */
/* @0x2bb77c cmp r2, r12 */
/* @0x2bb780 str r12, [r3] */
/* @0x2bb784 ble 0x2bb80c <jinit_1pass_quantizer+0xadc> */
/* @0x2bb788 ldr r3, [sp, #0xc] —— 栈槽 */
/* @0x2bb78c mov r4, r2 */
/* @0x2bb790 mov r8, #0 */
/* @0x2bb794 add r10, r3, r2, lsl #2 */
/* @0x2bb798 ldr r3, [sp] —— 栈槽 */
/* @0x2bb79c cmp r3, r11 */
/* @0x2bb7a0 bgt 0x2bb7fc <jinit_1pass_quantizer+0xacc> */
/* @0x2bb7a4 ldr r7, [r10, r8] */
/* @0x2bb7a8 mov r9, r3 */
/* @0x2bb7ac ldr r0, [sp, #0x4] —— 栈槽 */
/* @0x2bb7b0 add r7, r7, r0 */
/* @0x2bb7b4 cmp r5, r6 */
/* @0x2bb7b8 bgt 0x2bb7ec <jinit_1pass_quantizer+0xabc> */
/* @0x2bb7bc ldrh r3, [r7] */
/* @0x2bb7c0 cmp r3, #0 */
/* @0x2bb7c4 bne 0x2bb494 <jinit_1pass_quantizer+0x764> */
/* @0x2bb7c8 mov r1, r7 */
/* @0x2bb7cc mov r3, r5 */
/* @0x2bb7d0 b 0x2bb7e0 <jinit_1pass_quantizer+0xab0> */
/* @0x2bb7d4 ldrh r0, [r1, #2]! */
/* @0x2bb7d8 cmp r0, #0 */
/* @0x2bb7dc bne 0x2bb494 <jinit_1pass_quantizer+0x764> */
/* @0x2bb7e0 add r3, r3, #1 */
/* @0x2bb7e4 cmp r6, r3 */
/* @0x2bb7e8 bge 0x2bb7d4 <jinit_1pass_quantizer+0xaa4> */
/* @0x2bb7ec add r9, r9, #1 */
/* @0x2bb7f0 add r7, r7, #64 */
/* @0x2bb7f4 cmp r11, r9 */
/* @0x2bb7f8 bge 0x2bb7b4 <jinit_1pass_quantizer+0xa84> */
/* @0x2bb7fc sub r4, r4, #1 */
/* @0x2bb800 sub r8, r8, #4 */
/* @0x2bb804 cmp r4, r12 */
/* @0x2bb808 bge 0x2bb798 <jinit_1pass_quantizer+0xa68> */
/* @0x2bb80c mov r10, r12 */
/* @0x2bb810 b 0x2bb4a4 <jinit_1pass_quantizer+0x774> */
/* @0x2bb814 ldr r1, [sp, #0x8] —— 栈槽 */
/* @0x2bb818 cmp r11, r12 */
/* @0x2bb81c str r12, [r1, #0x8] */
/* @0x2bb820 ble 0x2bb8a4 <jinit_1pass_quantizer+0xb74> */
/* @0x2bb824 lsl r9, r11, #6 */
/* @0x2bb828 mov r4, r11 */
/* @0x2bb82c lsl r3, r5, #1 */
/* @0x2bb830 str r3, [sp] —— 栈槽 */
/* @0x2bb834 cmp r2, r10 */
/* @0x2bb838 blt 0x2bb894 <jinit_1pass_quantizer+0xb64> */
/* @0x2bb83c ldr r8, [sp, #0x4] —— 栈槽 */
/* @0x2bb840 mov r7, r10 */
/* @0x2bb844 ldr r3, [r8, #0x4]! */
/* @0x2bb848 cmp r5, r6 */
/* @0x2bb84c ldr r0, [sp] —— 栈槽 */
/* @0x2bb850 add r3, r3, r9 */
/* @0x2bb854 add r1, r3, r0 */
/* @0x2bb858 bgt 0x2bb888 <jinit_1pass_quantizer+0xb58> */
/* @0x2bb85c ldrh r3, [r3, r0] */
/* @0x2bb860 cmp r3, #0 */
/* @0x2bb864 bne 0x2bb540 <jinit_1pass_quantizer+0x810> */
/* @0x2bb868 mov r3, r5 */
/* @0x2bb86c b 0x2bb87c <jinit_1pass_quantizer+0xb4c> */
/* @0x2bb870 ldrh r0, [r1, #2]! */
/* @0x2bb874 cmp r0, #0 */
/* @0x2bb878 bne 0x2bb540 <jinit_1pass_quantizer+0x810> */
/* @0x2bb87c add r3, r3, #1 */
/* @0x2bb880 cmp r6, r3 */
/* @0x2bb884 bge 0x2bb870 <jinit_1pass_quantizer+0xb40> */
/* @0x2bb888 add r7, r7, #1 */
/* @0x2bb88c cmp r2, r7 */
/* @0x2bb890 bge 0x2bb844 <jinit_1pass_quantizer+0xb14> */
/* @0x2bb894 sub r4, r4, #1 */
/* @0x2bb898 sub r9, r9, #64 */
/* @0x2bb89c cmp r4, r12 */
/* @0x2bb8a0 bge 0x2bb834 <jinit_1pass_quantizer+0xb04> */
/* @0x2bb8a4 str r12, [sp] —— 栈槽 */
/* @0x2bb8a8 b 0x2bb550 <jinit_1pass_quantizer+0x820> */
/* @0x2bb8ac mov r0, #0 */
/* @0x2bb8b0 b 0x2bb6d8 <jinit_1pass_quantizer+0x9a8> */

