/* cally 逆向卡：DoReplace（原版 libyoyo.so，armv7）
 * @func 0x24a99c 0x24b934  size 3992  998 条（0x24b924..0x24b930 四个字是 literal pool，非指令）
 * 级别: 正文（两路替换、$ 模板六类展开、YYStrBuilder 两条增长算式、SEntry 释放收尾全部逐条锚定；
 *            只剩「回调路的 self 全局符号名」「$nn 两位组号的一处越位读取」进 open）
 * 符号: _Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii
 *   → void DoReplace(YYStrBuilder& out, CInstance* self, bool isFunc, RValue* repl,
 *                    RValue* subject, int startOffset, SMatches** matches, int matchCount, int endPos)
 * 调用者: 全库唯一 JS_String_prototype_replace_RegEx（0x258e3c）：0x25903c（单匹配，matchCount=1）
 *         与 0x259220（g 标志多匹配，matchCount≤99）。DoReplace 不含 pcre_exec，只消费外面算好的 SMatches。
 *
 * ── 帧与实参 ─────────────────────────────────────────────────
 *   push 9 regs + vpush {d8}，再 0x24a9a4 add r11,sp,#40、0x24a9ac sub sp,sp,#140 ⇒ r11 = 入口 sp-4
 *   [r11+0x04]=subject(RValue*)  [r11+0x08]=startOffset  [r11+0x0c]=matches(SMatches**)
 *   [r11+0x10]=matchCount        [r11+0x14]=endPos
 *   0x24a9b0 存 arg4(repl RValue*)；0x24a9b4 mov r1,#0 直接把 CInstance* 实参打掉 ——
 *   self 只是签名占位，全函数不再使用（见 open 1：回调路用的是另一个全局 self）。
 *   局部： [r11-0x50]=subject 串  [r11-0x98]=subject 长度  [r11-0x30]=__stack_chk_guard 影子
 *          [r11-0x58]=匹配下标 i  [r11-0x5c]=当前 SMatches*  [r11-0x64]=指针数组游标
 *          [r11-0x60]=matchStart  [r11-0x54]=matchEnd  [r11-0x68]=段尾 segmentEnd
 *          [r11-0x48]/[r11-0x44]/[r11-0x4c]=STRING_RValue 的 start/end/cap
 *          [r11-0x84]=模板拷贝（模板路）  [r11-0x78]=模板长度（模板路）/ &self 全局（回调路）
 *          [r11-0xa0]=subject+startOffset  [r11-0xa4]=matches-4（指针数组游标的起点）
 *   结构体（本卡实证）：
 *     YYStrBuilder{char* buf; int cap; int len;}  —— +0/+4/+8，见下方增长算式
 *     SMatches{int count; SEntry* entries;}；SEntry 12B{int start; int end; char* str;}
 *     （0x24b428 的 add r6,r6,r6,lsl #1 再 lsl #2 就是 idx*12；str 在 +8，0x24ab2c / 0x24b434）
 *
 * ── 顶部：取串 + 唯一分叉 ───────────────────────────────────
 *   0x24a9ec YYGetString(subject,0) → [r11-0x50]；0x24a9f4 strlen → [r11-0x98]
 *   0x24a9f8 cmp r4,#0（arg3=isFunc）→ 0x24aa00 beq 0x24af24：isFunc==0 走模板路，非 0 直落 0x24aa04 走回调路
 *   matchCount<=0：回调路 0x24aa0c ble 0x24af04（直接尾声）；模板路 0x24afc4 ble 0x24ae84（先清理）
 *
 * ── 回调路（isFunc!=0，0x24aa04..0x24ae68）───────────────────
 *   每轮取 matches[i]：0x24aab0 ldr r5,[r7,#0x4]!（游标 [r11-0x64] 前进 4 字节，取一个 SMatches*）
 *   s16 = entries[0].start（0x24aac0 vldr s16,[r1]），段尾 segmentEnd：
 *     i<matchCount 时 = matches[i+1]->entries[0].start（0x24aae8/0x24aaec），否则 = subjectLen（0x24aad8）
 *   实参数组在栈上现开：0x24aaf0 lsl r3,lr,#4 + 0x24aaf4 add r3,r3,#40 + 0x24aafc sub sp,sp,r3，
 *     r6 = sp+8 指向 argv[0]
 *   argv[i] = YYCreateString(entries[i].str)（0x24ab18..0x24ab40 的循环，步长 16 / 12）
 *   argv[count]   = RValue{(double)entries[0].start, tag 0}（0x24ab48 vcvt.f64.s32、0x24ab74 vstr、0x24ab78 tag）
 *   argv[count+1] = *subject 的 16 字节拷贝（0x24ab5c..0x24ab7c stm r12!,{r0,r1,r2,r3}）
 *   ⇒ 实参形态就是 JS String.replace(fn) 的 (match, p1..pn, offset, string)，个数 count+2（0x24aba8 add r3,r3,#2）
 *   ret 先写成 {0.0, tag 0}（0x24ab80 str / 0x24ab94..0x24abac），再 Call_RValue(self, &ret, repl, count+2, argv)
 *     self 来自 0x24aa10 的 ldr r7,[pc,#0xf10] → GOT 0x3edcb0 → R_ARM_RELATIVE 指向的 .bss 全局 0x544bdc，
 *     0x24aba0 ldr r0,[r7] 取它的当前值（符号名未定，open 1）
 *   调用后释放 argv 的 count 个 RValue：tag 减 1、清 bits31..24、清 bits1..0 后为 0（即 tag 1..4）才
 *     FREE_RValue__Pre，随后 value=0、+8=0、tag=5（0x24abe4..0x24ac08）—— 与 DoCall 的实参释放同构
 *   首个匹配前补 [startOffset, matchStart)（0x24ac18..0x24acc8；条件 startOffset<matchStart，
 *     拷贝用逐字节 + 增长，0x24ac40 ldrb r5,[r7],#1）；拷贝完从 0x24acd0 起把 ret 转成字符串追加
 *   0x24acfc STRING_RValue(&ret, ...) 取串 → 0x24ad90 strcpy 追加 → 0x24ada4 YYFree 临时缓冲
 *   再补 [matchEnd, segmentEnd)（0x24adb8..0x24ae64）；0x24ae68 i==matchCount 才跳出，否则 0x24ae78 清「首轮」标记
 *
 * ── 模板路（isFunc==0，0x24af24..0x24b5dc）───────────────────
 *   0x24af3c YYAlloc(256) 建临时缓冲，cap 存 [r11-0x4c]，start/end 同址（0x24af4c/0x24af54）
 *   0x24af60 STRING_RValue(&end,&start,&cap,repl) 把 repl RValue 渲染成 C 串（这个函数是「追加式」增长缓冲，
 *     见 0x0ce388：*start 是缓冲基址、*end 是写位置、*cap 是容量，返回后 *end-*start 才是长度）
 *   0x24af6c rsb r2,r3,r2 ⇒ 长度 = end-start；0x24af90 按 1.5*(len+1) 再分配一块拷贝，0x24afa8 strcpy，
 *     0x24afb8 YYFree 临时缓冲 ⇒ 后面只用拷贝，长度留 [r11-0x78]
 *   0x24b060 长度 0 时 r4 指向 [r11-0x38] 那个零字，等价空串
 *   循环 0x24b004：游标取 matches[i]（0x24b014），段尾同回调路（0x24b028..0x24b048），
 *     matchStart/matchEnd 取自 entries[0]（0x24b058/0x24b05c），首轮补 [startOffset,matchStart)（0x24b078..0x24b144）
 *   0x24b148 起逐字符扫模板（r6=[r4]），只有 '$' 特殊（0x24b20c cmp r6,#36）
 *
 * ── $ 展开：跳表在 0x24b220 addls pc,pc,r3,lsl #2，基址 0x24b228（=该指令+8），索引 = c-'$'，0..60 即 '$'..'`'
 *   '$' 0x24b228 → 0x24b760：输出单个 '$'（0x24b7dc ldrh 从字面量 "$" 0x355e64 取两字节，长度 +1）
 *   '&' 0x24b230 → 0x24b5d0：entries[0].str 整段匹配（0x24b5d4 取 entries，0x24b5d8 取 +8）
 *   '\'' 0x24b234 → 0x24b694：匹配之后的文本 [matchEnd, subjectLen)
 *   '0'..'9' 0x24b258..0x24b27c → 0x24b3dc：第 n 组
 *   '`' (0x60) 0x24b318 → 0x24b31c：匹配之前的文本 [startOffset, matchStart)
 *   其余（含 '%'、'('、'A' 等）0x24b22c/0x24b238.. → 0x24b7f4 默认：原样输出 '$' 和该字符两个字节
 *   $n 细节：n = 该字符-'0'；n >= matches[i]->count（0x24b41c）或 entries[n].str==NULL（0x24b438）时
 *     什么都不输出，只把游标推过 '$'+该字符；正常则 strlen+strcpy 追加（0x24b444..0x24b4d8）
 *   两位组号：仅当 count>9（0x24b3ec cmp r3,#9）且 isdigit 探针通过（0x24b3f4 ldr [pc,#0x534] → GOT 0x3ed988
 *     = _ctype_，0x24b40c tst r2,#4）才升级；探针读的是 repl[i+3]（0x24b3f8 ldrb r1,[r4,#0x3]），
 *     组号也取它（0x24b414 sub r6,r1,#48），游标推到 repl[i+3]（0x24b418 add r5,r4,#2）—— 比 JS 的 $nn 错一位（open 2）
 *   一轮模板展开完，0x24b4f8..0x24b5b0 补 [prevEnd, segmentEnd)，0x24b5b8 判 i==matchCount 收工
 *
 * ── YYStrBuilder 两条增长算式（逐条锚定）─────────────────────
 *   追加 1 字符（0x24ac38..0x24acc8 与 0x24b168../0x24b0a4.. 共 8 处同构）：
 *     若 cap-len-1 > 1（0x24ac48 cmp r1,#1）则不增长；否则 newcap = cap ? cap*3/2 : 3（0x24ac68 asrne r6,r3,#1），
 *     再与 1.5*(len+2) 取大（0x24ac6c..0x24ac78）；YYAlloc → memcpy(旧 cap 字节) → 释放旧块
 *     追加写法固定为 buf[len]=ch; buf[len+1]=0; len++（0x24acb8/0x24acbc/0x24acc8）
 *   追加整串（0x24b448..0x24b4d8 与 0x24b5e4../0x24b6a4.. 同构）：
 *     若 strlen+1 > cap-len-1 才增长；newcap = max(1.5*base, 1.5*(len+slen+1))，base = cap ? cap : slen+1
 *     然后 strcpy(buf+len, s)、len += slen —— 注意长度按 strlen 记，不按拷贝长度
 *   ⇒ builder 任何时刻都是带 NUL 的 C 串，调用者可以直接对它 YYCreateString
 *
 * ── 收尾、所有权、栈保护 ────────────────────────────────────
 *   0x24ae84 只释放模板拷贝 [r11-0x84]（模板路）；回调路的 [r11-0x84] 是栈地址，故它绕开这段
 *   0x24aeb0..0x24af00：对每个匹配的每个 SEntry 调 pcre_free_substring(entry->str)（含 entry[0]）
 *     ⇒ pcre_get_substring 的分配在 DoReplace 里统一释放（所有权在此转移），调用者不再碰 SEntry.str
 *   canary：0x24a9a8/0x24a9d4 经 GOT 0x3ed958 取 __stack_chk_guard 存 [r11-0x30]，
 *     0x24af04..0x24af14 比对，0x24b920 失败跳 __stack_chk_fail
 *   全函数 16 次 YYAlloc / 16 次 YYFree，全部是 builder 与模板拷贝的扩容/释放；不含任何 pcre_exec
 *
 * ── 与调用者的契约（0x258e3c 里两处）────────────────────────
 *   0x25903c：out=r11-900、self、isFunc、repl、subject、startOffset=0、matches=&单个 SMatches*、matchCount=1、
 *             endPos=DoRegExpExec 的返回值（这个位置 DoReplace 从不读）
 *   0x259220：matchCount=[r11-0x390]（收集上限 99，0x2591bc cmp lr,#99）、endPos=0
 *   ⇒ 匹配（pcre_exec / pcre_get_substring）在外面，替换策略（函数回调 or $ 模板）由 arg3 一句话选
 *
 * 结论（新增五条硬事实）:
 *   1. 两路只由 arg3 选：0 = $ 模板展开（每匹配展开一遍模板），非 0 = 每匹配调一次 Call_RValue。
 *      同一个 RValue* repl 在两路里含义不同（模板串 vs 可调用值），DoReplace 不检查它的 tag。
 *   2. 回调实参固定 count+2 个：count 个捕获串（新建 string RValue）+ (double)matchStart + 整串 RValue 拷贝，
 *      与 JS String.replace(fn) 的 (match,p1..pn,offset,string) 完全对齐；回调返回的 RValue 被 STRING_RValue 取串后追加。
 *   3. 段拼接顺序：首轮补 [startOffset,matchStart)，每轮补 [matchEnd,segmentEnd)（segmentEnd = 下一匹配的
 *      start 或 subjectLen），因此两路都不需要额外处理「末段尾巴」。
 *   4. $ 规则集 = JS 那五种（$$/$&/$`/$'/ $n）；越界组号或空组不输出字面量（JS 会保留 "$1" 原文），
 *      两位组号读的是 repl[i+3] 而不是 repl[i+2] —— 这两点与 JS 语义有偏差。
 *   5. SEntry.str（pcre_get_substring 分配）无条件由 DoReplace 释放，且整块替换结果写进调用者的 YYStrBuilder，
 *      函数本身返回 void、也不产出新 RValue。
 * open:
 *   1. 回调路的 self：GOT 0x3edcb0（R_ARM_RELATIVE）→ .bss 0x544bdc 的全局指针，符号名未定；
 *      传进来的 CInstance* 在 0x24a9b4 被清零丢弃。
 *   2. $nn 的越位读取（repl[i+3]）：行为已证，是否为原版 bug 未证；同时 $n 越界时静默不输出也偏离 JS。
 *   3. 模板以 '$' 结尾时走默认分支：先输出 '$' 再把 0x00 当字符写一次并 len++，随后读 repl[i+2] 判循环
 *      （越过终止符读一字节，结果依赖缓冲残留）。
 *   4. matchCount 与 matches 数组实际长度不一致时无任何校验（调用者保证 ≤99，且只在 g 路生效）。
 *   5. SEntry 的 start/end 只被用作偏移与区间端点，未验证与 subject 长度的一致性（越界匹配会直接越界拷贝）。
 */

/* ── 锚点（逐条对应 asm/index-DoReplace.tsv，脚本生成，勿手改）── */
/* @0x24a99c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24a9a0 vpush {d8} */
/* @0x24a9a4 add r11, sp, #40 */
/* @0x24a9a8 ldr r7, [pc, #0xf74] */
/* @0x24a9ac sub sp, sp, #140 */
/* @0x24a9b0 str r3, [r11, #-0x7c] */
/* @0x24a9b4 mov r1, #0 */
/* @0x24a9b8 mov r8, r0 */
/* @0x24a9bc str r7, [r11, #-0x9c] */
/* @0x24a9c0 mov r4, r2 */
/* @0x24a9c4 ldr r7, [r11, #0x4] */
/* @0x24a9c8 str r7, [r11, #-0x54] */
/* @0x24a9cc ldr r7, [r11, #-0x9c] */
/* @0x24a9d0 ldr r0, [r11, #-0x54] */
/* @0x24a9d4 ldr r7, [pc, r7] */
/* @0x24a9d8 str r7, [r11, #-0x9c] */
/* @0x24a9dc ldr r3, [r7] */
/* @0x24a9e0 ldr r7, [r11, #0xc] */
/* @0x24a9e4 str r3, [r11, #-0x30] */
/* @0x24a9e8 str r7, [r11, #-0x88] */
/* @0x24a9ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x24a9f0 str r0, [r11, #-0x50] */
/* @0x24a9f4 bl 0xb6538 <strlen@plt> */
/* @0x24a9f8 cmp r4, #0 */
/* @0x24a9fc str r0, [r11, #-0x98] */
/* @0x24aa00 beq 0x24af24 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x588> */
/* @0x24aa04 ldr r7, [r11, #0x10] */
/* @0x24aa08 cmp r7, #0 */
/* @0x24aa0c ble 0x24af04 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x568> */
/* @0x24aa10 ldr r7, [pc, #0xf10] */
/* @0x24aa14 mov r4, #0 */
/* @0x24aa18 ldr lr, [r11, #0x8] */
/* @0x24aa1c str r7, [r11, #-0x78] */
/* @0x24aa20 ldr r7, [r11, #-0x88] */
/* @0x24aa24 sub r7, r7, #4 */
/* @0x24aa28 str r7, [r11, #-0xa4] */
/* @0x24aa2c sub r7, r11, #64 */
/* @0x24aa30 str r7, [r11, #-0x70] */
/* @0x24aa34 mov r7, #0 */
/* @0x24aa38 str r7, [r11, #-0x58] */
/* @0x24aa3c ldr r7, [r11, #-0x78] */
/* @0x24aa40 ldr r7, [pc, r7] */
/* @0x24aa44 str r7, [r11, #-0x78] */
/* @0x24aa48 sub r7, r11, #60 */
/* @0x24aa4c str r7, [r11, #-0x8c] */
/* @0x24aa50 sub r7, r11, #56 */
/* @0x24aa54 str r7, [r11, #-0x90] */
/* @0x24aa58 sub r7, r11, #52 */
/* @0x24aa5c str r7, [r11, #-0x94] */
/* @0x24aa60 sub r7, r11, #68 */
/* @0x24aa64 str r7, [r11, #-0x88] */
/* @0x24aa68 sub r7, r11, #72 */
/* @0x24aa6c str r7, [r11, #-0x84] */
/* @0x24aa70 sub r7, r11, #76 */
/* @0x24aa74 str r7, [r11, #-0x80] */
/* @0x24aa78 ldr r7, [r11, #-0x50] */
/* @0x24aa7c add r7, r7, lr */
/* @0x24aa80 str r7, [r11, #-0xa0] */
/* @0x24aa84 ldr r7, [r11, #-0xa4] */
/* @0x24aa88 str r7, [r11, #-0x5c] */
/* @0x24aa8c ldr r7, [r11, #-0x70] */
/* @0x24aa90 str r7, [r11, #-0x60] */
/* @0x24aa94 mov r7, #1 */
/* @0x24aa98 str r7, [r11, #-0x74] */
/* @0x24aa9c ldr r7, [r11, #-0x58] */
/* @0x24aaa0 add r7, r7, #1 */
/* @0x24aaa4 str r7, [r11, #-0x58] */
/* @0x24aaa8 ldr r7, [r11, #-0x5c] */
/* @0x24aaac ldr lr, [r11, #-0x58] */
/* @0x24aab0 ldr r5, [r7, #0x4]! */
/* @0x24aab4 str r7, [r11, #-0x5c] */
/* @0x24aab8 ldr r7, [r11, #0x10] */
/* @0x24aabc ldr r1, [r5, #0x4] */
/* @0x24aac0 vldr s16, [r1] */
/* @0x24aac4 cmp r7, lr */
/* @0x24aac8 ldr lr, [r5] */
/* @0x24aacc ldrgt r7, [r11, #-0x5c] */
/* @0x24aad0 ldrle r7, [r11, #-0x98] */
/* @0x24aad4 ldrgt r3, [r7, #0x4] */
/* @0x24aad8 strle r7, [r11, #-0x64] */
/* @0x24aadc ldr r7, [r1, #0x4] */
/* @0x24aae0 ldrgt r3, [r3, #0x4] */
/* @0x24aae4 str r7, [r11, #-0x68] */
/* @0x24aae8 ldrgt r3, [r3] */
/* @0x24aaec strgt r3, [r11, #-0x64] */
/* @0x24aaf0 lsl r3, lr, #4 */
/* @0x24aaf4 add r3, r3, #40 */
/* @0x24aaf8 cmp lr, #0 */
/* @0x24aafc sub sp, sp, r3 */
/* @0x24ab00 add r6, sp, #8 */
/* @0x24ab04 ble 0x24ab44 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x1a8> */
/* @0x24ab08 mov r9, #0 */
/* @0x24ab0c mov r7, r6 */
/* @0x24ab10 mov r10, r9 */
/* @0x24ab14 b 0x24ab1c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x180> */
/* @0x24ab18 ldr r1, [r5, #0x4] */
/* @0x24ab1c add r1, r1, r9 */
/* @0x24ab20 mov r0, r7 */
/* @0x24ab24 add r10, r10, #1 */
/* @0x24ab28 add r9, r9, #12 */
/* @0x24ab2c ldr r1, [r1, #0x8] */
/* @0x24ab30 add r7, r7, #16 */
/* @0x24ab34 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x24ab38 ldr lr, [r5] */
/* @0x24ab3c cmp lr, r10 */
/* @0x24ab40 bgt 0x24ab18 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x17c> */
/* @0x24ab44 ldr r7, [r11, #-0x54] */
/* @0x24ab48 vcvt.f64.s32 d7, s16 */
/* @0x24ab4c lsl lr, lr, #4 */
/* @0x24ab50 str r4, [r11, #-0x3c] */
/* @0x24ab54 add r12, lr, #16 */
/* @0x24ab58 add lr, r6, lr */
/* @0x24ab5c ldr r0, [r7] */
/* @0x24ab60 add r12, r6, r12 */
/* @0x24ab64 ldr r1, [r7, #0x4] */
/* @0x24ab68 ldr r2, [r7, #0x8] */
/* @0x24ab6c ldr r3, [r7, #0xc] */
/* @0x24ab70 ldr r7, [r11, #-0x70] */
/* @0x24ab74 vstr d7, [lr] */
/* @0x24ab78 str r4, [lr, #0xc] */
/* @0x24ab7c stm r12!, {r0, r1, r2, r3} */
/* @0x24ab80 str r4, [r7] */
/* @0x24ab84 sub r7, r11, #64 */
/* @0x24ab88 str r7, [r11, #-0x70] */
/* @0x24ab8c mov r1, r7 */
/* @0x24ab90 ldr r7, [r11, #-0x78] */
/* @0x24ab94 str r4, [r11, #-0x38] */
/* @0x24ab98 str r4, [r11, #-0x34] */
/* @0x24ab9c ldr r3, [r5] */
/* @0x24aba0 ldr r0, [r7] */
/* @0x24aba4 ldr r2, [r11, #-0x7c] */
/* @0x24aba8 add r3, r3, #2 */
/* @0x24abac str r6, [sp] */
/* @0x24abb0 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x24abb4 ldr r1, [r5] */
/* @0x24abb8 cmp r1, #0 */
/* @0x24abbc movgt r7, #0 */
/* @0x24abc0 bgt 0x24abe4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x248> */
/* @0x24abc4 b 0x24ac0c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x270> */
/* @0x24abc8 add r7, r7, #1 */
/* @0x24abcc str r4, [r6, #0x8] */
/* @0x24abd0 cmp r1, r7 */
/* @0x24abd4 mov lr, #5 */
/* @0x24abd8 str lr, [r6, #0xc] */
/* @0x24abdc str r4, [r6], #16 */
/* @0x24abe0 ble 0x24ac0c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x270> */
/* @0x24abe4 ldr r3, [r6, #0xc] */
/* @0x24abe8 sub r3, r3, #1 */
/* @0x24abec bic r3, r3, #-16777216 */
/* @0x24abf0 bic r3, r3, #3 */
/* @0x24abf4 cmp r3, #0 */
/* @0x24abf8 bne 0x24abc8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x22c> */
/* @0x24abfc mov r0, r6 */
/* @0x24ac00 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24ac04 ldr r1, [r5] */
/* @0x24ac08 b 0x24abc8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x22c> */
/* @0x24ac0c ldr r7, [r11, #-0x74] */
/* @0x24ac10 cmp r7, #0 */
/* @0x24ac14 beq 0x24acd0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x334> */
/* @0x24ac18 vmov r0, s16 */
/* @0x24ac1c ldr r7, [r11, #0x8] */
/* @0x24ac20 cmp r0, r7 */
/* @0x24ac24 ble 0x24acd0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x334> */
/* @0x24ac28 ldr r7, [r11, #-0x50] */
/* @0x24ac2c ldr r2, [r8, #0x8] */
/* @0x24ac30 add r10, r7, r0 */
/* @0x24ac34 ldr r7, [r11, #-0xa0] */
/* @0x24ac38 ldr r3, [r8, #0x4] */
/* @0x24ac3c mvn r1, r2 */
/* @0x24ac40 ldrb r5, [r7], #1 */
/* @0x24ac44 add r1, r3, r1 */
/* @0x24ac48 cmp r1, #1 */
/* @0x24ac4c bgt 0x24acac <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x310> */
/* @0x24ac50 cmp r3, #0 */
/* @0x24ac54 add r2, r2, #2 */
/* @0x24ac58 addne r3, r3, r3, lsl #1 */
/* @0x24ac5c ldr r9, [r8] */
/* @0x24ac60 moveq r6, #3 */
/* @0x24ac64 addne r3, r3, r3, lsr #31 */
/* @0x24ac68 asrne r6, r3, #1 */
/* @0x24ac6c cmp r2, r6 */
/* @0x24ac70 addgt r2, r2, r2, lsl #1 */
/* @0x24ac74 addgt r2, r2, r2, lsr #31 */
/* @0x24ac78 asrgt r6, r2, #1 */
/* @0x24ac7c mov r0, r6 */
/* @0x24ac80 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24ac84 ldr r2, [r8, #0x4] */
/* @0x24ac88 mov r1, r9 */
/* @0x24ac8c str r0, [r8] */
/* @0x24ac90 bl 0xb65bc <memcpy@plt> */
/* @0x24ac94 cmp r9, #0 */
/* @0x24ac98 str r6, [r8, #0x4] */
/* @0x24ac9c beq 0x24aca8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x30c> */
/* @0x24aca0 mov r0, r9 */
/* @0x24aca4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24aca8 ldr r2, [r8, #0x8] */
/* @0x24acac ldr r3, [r8] */
/* @0x24acb0 cmp r7, r10 */
/* @0x24acb4 add r1, r3, r2 */
/* @0x24acb8 strb r5, [r3, r2] */
/* @0x24acbc strb r4, [r1, #0x1] */
/* @0x24acc0 ldr r2, [r8, #0x8] */
/* @0x24acc4 add r2, r2, #1 */
/* @0x24acc8 str r2, [r8, #0x8] */
/* @0x24accc bne 0x24ac38 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x29c> */
/* @0x24acd0 mov r0, #256 */
/* @0x24acd4 str r0, [r11, #-0x4c] */
/* @0x24acd8 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24acdc sub r1, r11, #72 */
/* @0x24ace0 sub r2, r11, #76 */
/* @0x24ace4 mov r3, r0 */
/* @0x24ace8 str r0, [r11, #-0x48] */
/* @0x24acec str r0, [r11, #-0x44] */
/* @0x24acf0 sub r0, r11, #68 */
/* @0x24acf4 strb r4, [r3] */
/* @0x24acf8 sub r3, r11, #64 */
/* @0x24acfc bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x24ad00 ldr r1, [r11, #-0x48] */
/* @0x24ad04 ldr r5, [r11, #-0x44] */
/* @0x24ad08 ldr r2, [r8, #0x8] */
/* @0x24ad0c ldr r3, [r8, #0x4] */
/* @0x24ad10 rsb r5, r1, r5 */
/* @0x24ad14 add r0, r5, #1 */
/* @0x24ad18 mvn r12, r2 */
/* @0x24ad1c add r12, r3, r12 */
/* @0x24ad20 cmp r0, r12 */
/* @0x24ad24 ble 0x24ad88 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x3ec> */
/* @0x24ad28 cmp r3, #0 */
/* @0x24ad2c add r2, r0, r2 */
/* @0x24ad30 ldr r6, [r8] */
/* @0x24ad34 moveq r3, r0 */
/* @0x24ad38 add r3, r3, r3, lsl #1 */
/* @0x24ad3c add r3, r3, r3, lsr #31 */
/* @0x24ad40 asr r10, r3, #1 */
/* @0x24ad44 cmp r10, r2 */
/* @0x24ad48 addlt r2, r2, r2, lsl #1 */
/* @0x24ad4c addlt r2, r2, r2, lsr #31 */
/* @0x24ad50 asrlt r10, r2, #1 */
/* @0x24ad54 mov r0, r10 */
/* @0x24ad58 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24ad5c ldr r2, [r8, #0x4] */
/* @0x24ad60 mov r1, r6 */
/* @0x24ad64 str r0, [r8] */
/* @0x24ad68 bl 0xb65bc <memcpy@plt> */
/* @0x24ad6c cmp r6, #0 */
/* @0x24ad70 str r10, [r8, #0x4] */
/* @0x24ad74 beq 0x24ad80 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x3e4> */
/* @0x24ad78 mov r0, r6 */
/* @0x24ad7c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ad80 ldr r1, [r11, #-0x48] */
/* @0x24ad84 ldr r2, [r8, #0x8] */
/* @0x24ad88 ldr r0, [r8] */
/* @0x24ad8c add r0, r0, r2 */
/* @0x24ad90 bl 0xb65a4 <strcpy@plt> */
/* @0x24ad94 ldr r3, [r8, #0x8] */
/* @0x24ad98 ldr r0, [r11, #-0x48] */
/* @0x24ad9c add r5, r3, r5 */
/* @0x24ada0 str r5, [r8, #0x8] */
/* @0x24ada4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ada8 ldr r7, [r11, #-0x64] */
/* @0x24adac ldr r0, [r11, #-0x68] */
/* @0x24adb0 cmp r7, r0 */
/* @0x24adb4 ble 0x24ae68 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4cc> */
/* @0x24adb8 ldr r1, [r11, #-0x50] */
/* @0x24adbc ldr r3, [r11, #-0x68] */
/* @0x24adc0 ldr r0, [r11, #-0x64] */
/* @0x24adc4 ldr r2, [r8, #0x8] */
/* @0x24adc8 add r7, r1, r3 */
/* @0x24adcc add r10, r1, r0 */
/* @0x24add0 ldr r3, [r8, #0x4] */
/* @0x24add4 mvn r1, r2 */
/* @0x24add8 ldrb r5, [r7], #1 */
/* @0x24addc add r1, r3, r1 */
/* @0x24ade0 cmp r1, #1 */
/* @0x24ade4 bgt 0x24ae44 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4a8> */
/* @0x24ade8 cmp r3, #0 */
/* @0x24adec add r2, r2, #2 */
/* @0x24adf0 addne r3, r3, r3, lsl #1 */
/* @0x24adf4 ldr r9, [r8] */
/* @0x24adf8 moveq r6, #3 */
/* @0x24adfc addne r3, r3, r3, lsr #31 */
/* @0x24ae00 asrne r6, r3, #1 */
/* @0x24ae04 cmp r2, r6 */
/* @0x24ae08 addgt r2, r2, r2, lsl #1 */
/* @0x24ae0c addgt r2, r2, r2, lsr #31 */
/* @0x24ae10 asrgt r6, r2, #1 */
/* @0x24ae14 mov r0, r6 */
/* @0x24ae18 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24ae1c ldr r2, [r8, #0x4] */
/* @0x24ae20 mov r1, r9 */
/* @0x24ae24 str r0, [r8] */
/* @0x24ae28 bl 0xb65bc <memcpy@plt> */
/* @0x24ae2c cmp r9, #0 */
/* @0x24ae30 str r6, [r8, #0x4] */
/* @0x24ae34 beq 0x24ae40 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4a4> */
/* @0x24ae38 mov r0, r9 */
/* @0x24ae3c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ae40 ldr r2, [r8, #0x8] */
/* @0x24ae44 ldr r3, [r8] */
/* @0x24ae48 cmp r7, r10 */
/* @0x24ae4c add r1, r3, r2 */
/* @0x24ae50 strb r5, [r3, r2] */
/* @0x24ae54 strb r4, [r1, #0x1] */
/* @0x24ae58 ldr r2, [r8, #0x8] */
/* @0x24ae5c add r2, r2, #1 */
/* @0x24ae60 str r2, [r8, #0x8] */
/* @0x24ae64 bne 0x24add0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x434> */
/* @0x24ae68 ldr r7, [r11, #-0x58] */
/* @0x24ae6c ldr r0, [r11, #0x10] */
/* @0x24ae70 cmp r7, r0 */
/* @0x24ae74 beq 0x24aeb0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x514> */
/* @0x24ae78 mov r7, #0 */
/* @0x24ae7c str r7, [r11, #-0x74] */
/* @0x24ae80 b 0x24aa9c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x100> */
/* @0x24ae84 ldr r3, [r11, #-0x84] */
/* @0x24ae88 cmp r3, #0 */
/* @0x24ae8c beq 0x24ae98 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4fc> */
/* @0x24ae90 ldr r0, [r11, #-0x84] */
/* @0x24ae94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ae98 ldr r7, [r11, #0x10] */
/* @0x24ae9c cmp r7, #0 */
/* @0x24aea0 ble 0x24af04 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x568> */
/* @0x24aea4 ldr r7, [r11, #-0x88] */
/* @0x24aea8 sub r7, r7, #4 */
/* @0x24aeac str r7, [r11, #-0xa4] */
/* @0x24aeb0 ldr r8, [r11, #-0xa4] */
/* @0x24aeb4 mov r7, #0 */
/* @0x24aeb8 ldr r9, [r11, #0x10] */
/* @0x24aebc ldr r6, [r8, #0x4]! */
/* @0x24aec0 ldr r3, [r6] */
/* @0x24aec4 cmp r3, #0 */
/* @0x24aec8 movgt r4, #0 */
/* @0x24aecc movgt r5, r4 */
/* @0x24aed0 ble 0x24aef8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x55c> */
/* @0x24aed4 ldr r3, [r6, #0x4] */
/* @0x24aed8 add r5, r5, #1 */
/* @0x24aedc add r3, r3, r4 */
/* @0x24aee0 add r4, r4, #12 */
/* @0x24aee4 ldr r0, [r3, #0x8] */
/* @0x24aee8 bl 0x25f6ac <pcre_free_substring> */
/* @0x24aeec ldr r3, [r6] */
/* @0x24aef0 cmp r3, r5 */
/* @0x24aef4 bgt 0x24aed4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x538> */
/* @0x24aef8 add r7, r7, #1 */
/* @0x24aefc cmp r9, r7 */
/* @0x24af00 bgt 0x24aebc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x520> */
/* @0x24af04 ldr r7, [r11, #-0x9c] */
/* @0x24af08 ldr r2, [r11, #-0x30] */
/* @0x24af0c ldr r3, [r7] */
/* @0x24af10 cmp r2, r3 */
/* @0x24af14 bne 0x24b920 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xf84> */
/* @0x24af18 sub sp, r11, #40 */
/* @0x24af1c vpop {d8} */
/* @0x24af20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24af24 mov r3, #256 */
/* @0x24af28 str r4, [r11, #-0x40] */
/* @0x24af2c mov r0, r3 */
/* @0x24af30 str r3, [r11, #-0x4c] */
/* @0x24af34 str r4, [r11, #-0x3c] */
/* @0x24af38 str r4, [r11, #-0x38] */
/* @0x24af3c bl 0xcef4c <_Z7YYAlloci> */
/* @0x24af40 ldr r3, [r11, #-0x7c] */
/* @0x24af44 sub r1, r11, #72 */
/* @0x24af48 mov r2, r0 */
/* @0x24af4c str r0, [r11, #-0x48] */
/* @0x24af50 sub r0, r11, #44 */
/* @0x24af54 str r2, [r0, #-0x18]! */
/* @0x24af58 strb r4, [r2] */
/* @0x24af5c sub r2, r11, #76 */
/* @0x24af60 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x24af64 ldr r3, [r11, #-0x48] */
/* @0x24af68 ldr r2, [r11, #-0x44] */
/* @0x24af6c rsb r2, r3, r2 */
/* @0x24af70 str r2, [r11, #-0x78] */
/* @0x24af74 adds r2, r2, #1 */
/* @0x24af78 strmi r4, [r11, #-0x84] */
/* @0x24af7c movmi r1, r3 */
/* @0x24af80 bmi 0x24afa4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x608> */
/* @0x24af84 add r2, r2, r2, lsl #1 */
/* @0x24af88 asr r4, r2, #1 */
/* @0x24af8c mov r0, r4 */
/* @0x24af90 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24af94 ldr r1, [r11, #-0x48] */
/* @0x24af98 str r4, [r11, #-0x3c] */
/* @0x24af9c str r0, [r11, #-0x84] */
/* @0x24afa0 str r0, [r11, #-0x40] */
/* @0x24afa4 ldr r0, [r11, #-0x84] */
/* @0x24afa8 bl 0xb65a4 <strcpy@plt> */
/* @0x24afac ldr r3, [r11, #-0x78] */
/* @0x24afb0 ldr r0, [r11, #-0x48] */
/* @0x24afb4 str r3, [r11, #-0x38] */
/* @0x24afb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24afbc ldr r7, [r11, #0x10] */
/* @0x24afc0 cmp r7, #0 */
/* @0x24afc4 ble 0x24ae84 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4e8> */
/* @0x24afc8 ldr r7, [pc, #0x95c] */
/* @0x24afcc mov r3, #0 */
/* @0x24afd0 str r3, [r11, #-0x58] */
/* @0x24afd4 mov r9, #0 */
/* @0x24afd8 add r7, pc, r7 */
/* @0x24afdc str r7, [r11, #-0x7c] */
/* @0x24afe0 ldr r7, [r11, #-0x88] */
/* @0x24afe4 mov r2, #1 */
/* @0x24afe8 ldr r3, [r11, #-0x50] */
/* @0x24afec sub r7, r7, #4 */
/* @0x24aff0 str r7, [r11, #-0x64] */
/* @0x24aff4 ldr r7, [r11, #0x8] */
/* @0x24aff8 add r3, r3, r7 */
/* @0x24affc str r3, [r11, #-0x80] */
/* @0x24b000 str r7, [r11, #-0x74] */
/* @0x24b004 ldr r3, [r11, #-0x58] */
/* @0x24b008 add r3, r3, #1 */
/* @0x24b00c str r3, [r11, #-0x58] */
/* @0x24b010 ldr r3, [r11, #-0x64] */
/* @0x24b014 ldr r7, [r3, #0x4]! */
/* @0x24b018 str r3, [r11, #-0x64] */
/* @0x24b01c str r7, [r11, #-0x5c] */
/* @0x24b020 ldr r3, [r11, #-0x58] */
/* @0x24b024 ldr r7, [r11, #0x10] */
/* @0x24b028 cmp r7, r3 */
/* @0x24b02c ldrgt r7, [r11, #-0x64] */
/* @0x24b030 ldrle r7, [r11, #-0x98] */
/* @0x24b034 ldrgt r3, [r7, #0x4] */
/* @0x24b038 strle r7, [r11, #-0x68] */
/* @0x24b03c ldr r7, [r11, #-0x5c] */
/* @0x24b040 ldrgt r3, [r3, #0x4] */
/* @0x24b044 ldrgt r3, [r3] */
/* @0x24b048 strgt r3, [r11, #-0x68] */
/* @0x24b04c ldr r3, [r7, #0x4] */
/* @0x24b050 ldr r7, [r11, #-0x78] */
/* @0x24b054 cmp r7, #0 */
/* @0x24b058 ldr r7, [r3] */
/* @0x24b05c ldr r3, [r3, #0x4] */
/* @0x24b060 subeq r4, r11, #56 */
/* @0x24b064 ldrne r4, [r11, #-0x84] */
/* @0x24b068 cmp r2, #0 */
/* @0x24b06c str r7, [r11, #-0x60] */
/* @0x24b070 str r3, [r11, #-0x54] */
/* @0x24b074 beq 0x24b148 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x7ac> */
/* @0x24b078 ldr r3, [r11, #-0x60] */
/* @0x24b07c ldr r7, [r11, #-0x74] */
/* @0x24b080 cmp r3, r7 */
/* @0x24b084 ble 0x24b914 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xf78> */
/* @0x24b088 ldr r0, [r11, #-0x50] */
/* @0x24b08c ldr r2, [r8, #0x8] */
/* @0x24b090 add r10, r0, r7 */
/* @0x24b094 add r3, r0, r3 */
/* @0x24b098 str r4, [r11, #-0x70] */
/* @0x24b09c mov r4, r10 */
/* @0x24b0a0 mov r10, r3 */
/* @0x24b0a4 ldr r12, [r8, #0x4] */
/* @0x24b0a8 mvn r1, r2 */
/* @0x24b0ac ldrb r6, [r4], #1 */
/* @0x24b0b0 add r1, r12, r1 */
/* @0x24b0b4 cmp r1, #1 */
/* @0x24b0b8 bgt 0x24b118 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x77c> */
/* @0x24b0bc cmp r12, #0 */
/* @0x24b0c0 add r2, r2, #2 */
/* @0x24b0c4 addne r12, r12, r12, lsl #1 */
/* @0x24b0c8 ldr r5, [r8] */
/* @0x24b0cc moveq r7, #3 */
/* @0x24b0d0 addne r12, r12, r12, lsr #31 */
/* @0x24b0d4 asrne r7, r12, #1 */
/* @0x24b0d8 cmp r2, r7 */
/* @0x24b0dc addgt r2, r2, r2, lsl #1 */
/* @0x24b0e0 addgt r2, r2, r2, lsr #31 */
/* @0x24b0e4 asrgt r7, r2, #1 */
/* @0x24b0e8 mov r0, r7 */
/* @0x24b0ec bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b0f0 ldr r2, [r8, #0x4] */
/* @0x24b0f4 mov r1, r5 */
/* @0x24b0f8 str r0, [r8] */
/* @0x24b0fc bl 0xb65bc <memcpy@plt> */
/* @0x24b100 cmp r5, #0 */
/* @0x24b104 str r7, [r8, #0x4] */
/* @0x24b108 beq 0x24b114 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x778> */
/* @0x24b10c mov r0, r5 */
/* @0x24b110 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b114 ldr r2, [r8, #0x8] */
/* @0x24b118 ldr r1, [r8] */
/* @0x24b11c cmp r4, r10 */
/* @0x24b120 add r0, r1, r2 */
/* @0x24b124 strb r6, [r1, r2] */
/* @0x24b128 strb r9, [r0, #0x1] */
/* @0x24b12c ldr r2, [r8, #0x8] */
/* @0x24b130 add r2, r2, #1 */
/* @0x24b134 str r2, [r8, #0x8] */
/* @0x24b138 bne 0x24b0a4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x708> */
/* @0x24b13c ldr r7, [r11, #-0x54] */
/* @0x24b140 ldr r4, [r11, #-0x70] */
/* @0x24b144 str r7, [r11, #-0x74] */
/* @0x24b148 ldrb r6, [r4] */
/* @0x24b14c cmp r6, #0 */
/* @0x24b150 beq 0x24b4f8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb5c> */
/* @0x24b154 ldr r3, [r11, #-0x50] */
/* @0x24b158 ldr r7, [r11, #-0x60] */
/* @0x24b15c add r3, r3, r7 */
/* @0x24b160 str r3, [r11, #-0x70] */
/* @0x24b164 b 0x24b20c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x870> */
/* @0x24b168 ldr r2, [r8, #0x8] */
/* @0x24b16c ldr r3, [r8, #0x4] */
/* @0x24b170 mvn r1, r2 */
/* @0x24b174 add r1, r3, r1 */
/* @0x24b178 cmp r1, #1 */
/* @0x24b17c bgt 0x24b1dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x840> */
/* @0x24b180 cmp r3, #0 */
/* @0x24b184 add r2, r2, #2 */
/* @0x24b188 addne r3, r3, r3, lsl #1 */
/* @0x24b18c ldr r5, [r8] */
/* @0x24b190 moveq r10, #3 */
/* @0x24b194 addne r3, r3, r3, lsr #31 */
/* @0x24b198 asrne r10, r3, #1 */
/* @0x24b19c cmp r2, r10 */
/* @0x24b1a0 addgt r2, r2, r2, lsl #1 */
/* @0x24b1a4 addgt r2, r2, r2, lsr #31 */
/* @0x24b1a8 asrgt r10, r2, #1 */
/* @0x24b1ac mov r0, r10 */
/* @0x24b1b0 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b1b4 ldr r2, [r8, #0x4] */
/* @0x24b1b8 mov r1, r5 */
/* @0x24b1bc str r0, [r8] */
/* @0x24b1c0 bl 0xb65bc <memcpy@plt> */
/* @0x24b1c4 cmp r5, #0 */
/* @0x24b1c8 str r10, [r8, #0x4] */
/* @0x24b1cc beq 0x24b1d8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x83c> */
/* @0x24b1d0 mov r0, r5 */
/* @0x24b1d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b1d8 ldr r2, [r8, #0x8] */
/* @0x24b1dc ldr r3, [r8] */
/* @0x24b1e0 mov r5, r4 */
/* @0x24b1e4 add r1, r2, r3 */
/* @0x24b1e8 strb r6, [r2, r3] */
/* @0x24b1ec strb r9, [r1, #0x1] */
/* @0x24b1f0 ldr r3, [r8, #0x8] */
/* @0x24b1f4 add r3, r3, #1 */
/* @0x24b1f8 str r3, [r8, #0x8] */
/* @0x24b1fc ldrb r6, [r5, #0x1] */
/* @0x24b200 add r4, r5, #1 */
/* @0x24b204 cmp r6, #0 */
/* @0x24b208 beq 0x24b4f8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb5c> */
/* @0x24b20c cmp r6, #36 */
/* @0x24b210 bne 0x24b168 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x7cc> */
/* @0x24b214 ldrb r6, [r4, #0x1] */
/* @0x24b218 sub r3, r6, #36 */
/* @0x24b21c cmp r3, #60 */
/* @0x24b220 addls pc, pc, r3, lsl #2 */
/* @0x24b224 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b228 b 0x24b760 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xdc4> */
/* @0x24b22c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b230 b 0x24b5d0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xc34> */
/* @0x24b234 b 0x24b694 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf8> */
/* @0x24b238 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b23c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b240 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b244 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b248 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b24c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b250 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b254 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b258 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b25c b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b260 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b264 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b268 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b26c b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b270 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b274 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b278 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b27c b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b280 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b284 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b288 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b28c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b290 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b294 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b298 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b29c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2a0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2a4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2a8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2ac b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2b0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2b4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2b8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2bc b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2c0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2c4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2c8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2cc b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2d0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2d4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2d8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2dc b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2e0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2e4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2e8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2ec b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2f0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2f4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2f8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2fc b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b300 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b304 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b308 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b30c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b310 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b314 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b318 b 0x24b31c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x980> */
/* @0x24b31c ldr r7, [r11, #0x8] */
/* @0x24b320 ldr r3, [r11, #-0x60] */
/* @0x24b324 cmp r7, r3 */
/* @0x24b328 bge 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b32c ldr r2, [r8, #0x8] */
/* @0x24b330 ldr r10, [r11, #-0x80] */
/* @0x24b334 ldr r6, [r11, #-0x70] */
/* @0x24b338 str r4, [r11, #-0x6c] */
/* @0x24b33c ldr r3, [r8, #0x4] */
/* @0x24b340 mvn r1, r2 */
/* @0x24b344 ldrb r5, [r10], #1 */
/* @0x24b348 add r1, r3, r1 */
/* @0x24b34c cmp r1, #1 */
/* @0x24b350 bgt 0x24b3b0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa14> */
/* @0x24b354 cmp r3, #0 */
/* @0x24b358 add r2, r2, #2 */
/* @0x24b35c addne r3, r3, r3, lsl #1 */
/* @0x24b360 ldr r7, [r8] */
/* @0x24b364 moveq r4, #3 */
/* @0x24b368 addne r3, r3, r3, lsr #31 */
/* @0x24b36c asrne r4, r3, #1 */
/* @0x24b370 cmp r2, r4 */
/* @0x24b374 addgt r2, r2, r2, lsl #1 */
/* @0x24b378 addgt r2, r2, r2, lsr #31 */
/* @0x24b37c asrgt r4, r2, #1 */
/* @0x24b380 mov r0, r4 */
/* @0x24b384 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b388 ldr r2, [r8, #0x4] */
/* @0x24b38c mov r1, r7 */
/* @0x24b390 str r0, [r8] */
/* @0x24b394 bl 0xb65bc <memcpy@plt> */
/* @0x24b398 cmp r7, #0 */
/* @0x24b39c str r4, [r8, #0x4] */
/* @0x24b3a0 beq 0x24b3ac <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa10> */
/* @0x24b3a4 mov r0, r7 */
/* @0x24b3a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b3ac ldr r2, [r8, #0x8] */
/* @0x24b3b0 ldr r3, [r8] */
/* @0x24b3b4 cmp r10, r6 */
/* @0x24b3b8 add r1, r3, r2 */
/* @0x24b3bc strb r5, [r3, r2] */
/* @0x24b3c0 strb r9, [r1, #0x1] */
/* @0x24b3c4 ldr r2, [r8, #0x8] */
/* @0x24b3c8 add r2, r2, #1 */
/* @0x24b3cc str r2, [r8, #0x8] */
/* @0x24b3d0 bne 0x24b33c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x9a0> */
/* @0x24b3d4 ldr r4, [r11, #-0x6c] */
/* @0x24b3d8 b 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b3dc ldr r7, [r11, #-0x5c] */
/* @0x24b3e0 sub r6, r6, #48 */
/* @0x24b3e4 add r5, r4, #1 */
/* @0x24b3e8 ldr r3, [r7] */
/* @0x24b3ec cmp r3, #9 */
/* @0x24b3f0 ble 0x24b41c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa80> */
/* @0x24b3f4 ldr r2, [pc, #0x534] */
/* @0x24b3f8 ldrb r1, [r4, #0x3] */
/* @0x24b3fc ldr r2, [pc, r2] */
/* @0x24b400 ldr r2, [r2] */
/* @0x24b404 add r2, r2, r1 */
/* @0x24b408 ldrb r2, [r2, #0x1] */
/* @0x24b40c tst r2, #4 */
/* @0x24b410 beq 0x24b424 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa88> */
/* @0x24b414 sub r6, r1, #48 */
/* @0x24b418 add r5, r4, #2 */
/* @0x24b41c cmp r6, r3 */
/* @0x24b420 bge 0x24b1fc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x860> */
/* @0x24b424 ldr r7, [r11, #-0x5c] */
/* @0x24b428 add r6, r6, r6, lsl #1 */
/* @0x24b42c ldr r3, [r7, #0x4] */
/* @0x24b430 add r3, r3, r6, lsl #2 */
/* @0x24b434 ldr r6, [r3, #0x8] */
/* @0x24b438 cmp r6, #0 */
/* @0x24b43c beq 0x24b1fc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x860> */
/* @0x24b440 mov r0, r6 */
/* @0x24b444 bl 0xb6538 <strlen@plt> */
/* @0x24b448 ldr r2, [r8, #0x8] */
/* @0x24b44c ldr r3, [r8, #0x4] */
/* @0x24b450 add r1, r0, #1 */
/* @0x24b454 mov r4, r0 */
/* @0x24b458 mvn r0, r2 */
/* @0x24b45c add r0, r3, r0 */
/* @0x24b460 cmp r1, r0 */
/* @0x24b464 ble 0x24b4cc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb30> */
/* @0x24b468 cmp r3, #0 */
/* @0x24b46c add r2, r1, r2 */
/* @0x24b470 ldr r7, [r8] */
/* @0x24b474 moveq r3, r1 */
/* @0x24b478 add r3, r3, r3, lsl #1 */
/* @0x24b47c add r3, r3, r3, lsr #31 */
/* @0x24b480 asr r3, r3, #1 */
/* @0x24b484 cmp r3, r2 */
/* @0x24b488 addlt r2, r2, r2, lsl #1 */
/* @0x24b48c addlt r2, r2, r2, lsr #31 */
/* @0x24b490 asrlt r3, r2, #1 */
/* @0x24b494 str r3, [r11, #-0xa8] */
/* @0x24b498 mov r0, r3 */
/* @0x24b49c bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b4a0 ldr r2, [r8, #0x4] */
/* @0x24b4a4 mov r1, r7 */
/* @0x24b4a8 str r0, [r8] */
/* @0x24b4ac bl 0xb65bc <memcpy@plt> */
/* @0x24b4b0 ldr r3, [r11, #-0xa8] */
/* @0x24b4b4 cmp r7, #0 */
/* @0x24b4b8 str r3, [r8, #0x4] */
/* @0x24b4bc beq 0x24b4c8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb2c> */
/* @0x24b4c0 mov r0, r7 */
/* @0x24b4c4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b4c8 ldr r2, [r8, #0x8] */
/* @0x24b4cc ldr r0, [r8] */
/* @0x24b4d0 mov r1, r6 */
/* @0x24b4d4 add r0, r0, r2 */
/* @0x24b4d8 bl 0xb65a4 <strcpy@plt> */
/* @0x24b4dc ldr r3, [r8, #0x8] */
/* @0x24b4e0 add r3, r3, r4 */
/* @0x24b4e4 str r3, [r8, #0x8] */
/* @0x24b4e8 ldrb r6, [r5, #0x1] */
/* @0x24b4ec add r4, r5, #1 */
/* @0x24b4f0 cmp r6, #0 */
/* @0x24b4f4 bne 0x24b20c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x870> */
/* @0x24b4f8 ldr r3, [r11, #-0x68] */
/* @0x24b4fc ldr r7, [r11, #-0x54] */
/* @0x24b500 cmp r3, r7 */
/* @0x24b504 ble 0x24b5b8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xc1c> */
/* @0x24b508 ldr r7, [r11, #-0x50] */
/* @0x24b50c ldr r3, [r11, #-0x54] */
/* @0x24b510 ldr r2, [r8, #0x8] */
/* @0x24b514 add r10, r7, r3 */
/* @0x24b518 ldr r3, [r11, #-0x68] */
/* @0x24b51c add r5, r7, r3 */
/* @0x24b520 ldr r3, [r8, #0x4] */
/* @0x24b524 mvn r1, r2 */
/* @0x24b528 ldrb r4, [r10], #1 */
/* @0x24b52c add r1, r3, r1 */
/* @0x24b530 cmp r1, #1 */
/* @0x24b534 bgt 0x24b594 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xbf8> */
/* @0x24b538 cmp r3, #0 */
/* @0x24b53c add r2, r2, #2 */
/* @0x24b540 addne r3, r3, r3, lsl #1 */
/* @0x24b544 ldr r6, [r8] */
/* @0x24b548 moveq r7, #3 */
/* @0x24b54c addne r3, r3, r3, lsr #31 */
/* @0x24b550 asrne r7, r3, #1 */
/* @0x24b554 cmp r2, r7 */
/* @0x24b558 addgt r2, r2, r2, lsl #1 */
/* @0x24b55c addgt r2, r2, r2, lsr #31 */
/* @0x24b560 asrgt r7, r2, #1 */
/* @0x24b564 mov r0, r7 */
/* @0x24b568 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b56c ldr r2, [r8, #0x4] */
/* @0x24b570 mov r1, r6 */
/* @0x24b574 str r0, [r8] */
/* @0x24b578 bl 0xb65bc <memcpy@plt> */
/* @0x24b57c cmp r6, #0 */
/* @0x24b580 str r7, [r8, #0x4] */
/* @0x24b584 beq 0x24b590 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xbf4> */
/* @0x24b588 mov r0, r6 */
/* @0x24b58c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b590 ldr r2, [r8, #0x8] */
/* @0x24b594 ldr r3, [r8] */
/* @0x24b598 cmp r10, r5 */
/* @0x24b59c add r1, r3, r2 */
/* @0x24b5a0 strb r4, [r3, r2] */
/* @0x24b5a4 strb r9, [r1, #0x1] */
/* @0x24b5a8 ldr r2, [r8, #0x8] */
/* @0x24b5ac add r2, r2, #1 */
/* @0x24b5b0 str r2, [r8, #0x8] */
/* @0x24b5b4 bne 0x24b520 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb84> */
/* @0x24b5b8 ldr r3, [r11, #-0x58] */
/* @0x24b5bc ldr r7, [r11, #0x10] */
/* @0x24b5c0 cmp r3, r7 */
/* @0x24b5c4 beq 0x24ae84 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4e8> */
/* @0x24b5c8 mov r2, #0 */
/* @0x24b5cc b 0x24b004 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x668> */
/* @0x24b5d0 ldr r7, [r11, #-0x5c] */
/* @0x24b5d4 ldr r3, [r7, #0x4] */
/* @0x24b5d8 ldr r10, [r3, #0x8] */
/* @0x24b5dc cmp r10, #0 */
/* @0x24b5e0 beq 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b5e4 mov r0, r10 */
/* @0x24b5e8 bl 0xb6538 <strlen@plt> */
/* @0x24b5ec ldr r2, [r8, #0x4] */
/* @0x24b5f0 mov r5, r0 */
/* @0x24b5f4 ldr r0, [r8, #0x8] */
/* @0x24b5f8 add r1, r5, #1 */
/* @0x24b5fc mvn r12, r0 */
/* @0x24b600 add r12, r2, r12 */
/* @0x24b604 cmp r1, r12 */
/* @0x24b608 ble 0x24b670 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcd4> */
/* @0x24b60c cmp r2, #0 */
/* @0x24b610 ldr r6, [r8] */
/* @0x24b614 moveq r2, r1 */
/* @0x24b618 add r1, r1, r0 */
/* @0x24b61c add r2, r2, r2, lsl #1 */
/* @0x24b620 add r2, r2, r2, lsr #31 */
/* @0x24b624 asr r12, r2, #1 */
/* @0x24b628 cmp r12, r1 */
/* @0x24b62c addlt r1, r1, r1, lsl #1 */
/* @0x24b630 addlt r1, r1, r1, lsr #31 */
/* @0x24b634 asrlt r12, r1, #1 */
/* @0x24b638 str r12, [r11, #-0xa8] */
/* @0x24b63c mov r0, r12 */
/* @0x24b640 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b644 ldr r2, [r8, #0x4] */
/* @0x24b648 mov r1, r6 */
/* @0x24b64c str r0, [r8] */
/* @0x24b650 bl 0xb65bc <memcpy@plt> */
/* @0x24b654 ldr r12, [r11, #-0xa8] */
/* @0x24b658 cmp r6, #0 */
/* @0x24b65c str r12, [r8, #0x4] */
/* @0x24b660 beq 0x24b66c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcd0> */
/* @0x24b664 mov r0, r6 */
/* @0x24b668 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b66c ldr r0, [r8, #0x8] */
/* @0x24b670 ldr r2, [r8] */
/* @0x24b674 mov r1, r10 */
/* @0x24b678 add r0, r2, r0 */
/* @0x24b67c bl 0xb65a4 <strcpy@plt> */
/* @0x24b680 ldr r3, [r8, #0x8] */
/* @0x24b684 add r5, r3, r5 */
/* @0x24b688 str r5, [r8, #0x8] */
/* @0x24b68c add r5, r4, #1 */
/* @0x24b690 b 0x24b1fc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x860> */
/* @0x24b694 ldr r7, [r11, #-0x98] */
/* @0x24b698 ldr r3, [r11, #-0x54] */
/* @0x24b69c cmp r7, r3 */
/* @0x24b6a0 ble 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b6a4 ldr r10, [r11, #-0x54] */
/* @0x24b6a8 str r4, [r11, #-0x6c] */
/* @0x24b6ac ldr r2, [r8, #0x8] */
/* @0x24b6b0 mov r4, r10 */
/* @0x24b6b4 ldr r10, [r11, #-0x98] */
/* @0x24b6b8 ldr r12, [r8, #0x4] */
/* @0x24b6bc mvn r1, r2 */
/* @0x24b6c0 ldr r7, [r11, #-0x50] */
/* @0x24b6c4 add r1, r12, r1 */
/* @0x24b6c8 cmp r1, #1 */
/* @0x24b6cc ldrb r6, [r7, r4] */
/* @0x24b6d0 bgt 0x24b730 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xd94> */
/* @0x24b6d4 cmp r12, #0 */
/* @0x24b6d8 add r2, r2, #2 */
/* @0x24b6dc addne r12, r12, r12, lsl #1 */
/* @0x24b6e0 ldr r5, [r8] */
/* @0x24b6e4 moveq r7, #3 */
/* @0x24b6e8 addne r12, r12, r12, lsr #31 */
/* @0x24b6ec asrne r7, r12, #1 */
/* @0x24b6f0 cmp r2, r7 */
/* @0x24b6f4 addgt r2, r2, r2, lsl #1 */
/* @0x24b6f8 addgt r2, r2, r2, lsr #31 */
/* @0x24b6fc asrgt r7, r2, #1 */
/* @0x24b700 mov r0, r7 */
/* @0x24b704 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b708 ldr r2, [r8, #0x4] */
/* @0x24b70c mov r1, r5 */
/* @0x24b710 str r0, [r8] */
/* @0x24b714 bl 0xb65bc <memcpy@plt> */
/* @0x24b718 cmp r5, #0 */
/* @0x24b71c str r7, [r8, #0x4] */
/* @0x24b720 beq 0x24b72c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xd90> */
/* @0x24b724 mov r0, r5 */
/* @0x24b728 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b72c ldr r2, [r8, #0x8] */
/* @0x24b730 ldr r1, [r8] */
/* @0x24b734 add r4, r4, #1 */
/* @0x24b738 cmp r10, r4 */
/* @0x24b73c add r0, r1, r2 */
/* @0x24b740 strb r6, [r1, r2] */
/* @0x24b744 strb r9, [r0, #0x1] */
/* @0x24b748 ldr r2, [r8, #0x8] */
/* @0x24b74c add r2, r2, #1 */
/* @0x24b750 str r2, [r8, #0x8] */
/* @0x24b754 bne 0x24b6b8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xd1c> */
/* @0x24b758 ldr r4, [r11, #-0x6c] */
/* @0x24b75c b 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b760 ldmib r8, {r2, r3} */
/* @0x24b764 mvn r1, r3 */
/* @0x24b768 add r1, r2, r1 */
/* @0x24b76c cmp r1, #1 */
/* @0x24b770 bgt 0x24b7d0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe34> */
/* @0x24b774 cmp r2, #0 */
/* @0x24b778 add r3, r3, #2 */
/* @0x24b77c addne r2, r2, r2, lsl #1 */
/* @0x24b780 ldr r5, [r8] */
/* @0x24b784 moveq r6, #3 */
/* @0x24b788 addne r2, r2, r2, lsr #31 */
/* @0x24b78c asrne r6, r2, #1 */
/* @0x24b790 cmp r3, r6 */
/* @0x24b794 addgt r3, r3, r3, lsl #1 */
/* @0x24b798 addgt r3, r3, r3, lsr #31 */
/* @0x24b79c asrgt r6, r3, #1 */
/* @0x24b7a0 mov r0, r6 */
/* @0x24b7a4 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b7a8 ldr r2, [r8, #0x4] */
/* @0x24b7ac mov r1, r5 */
/* @0x24b7b0 str r0, [r8] */
/* @0x24b7b4 bl 0xb65bc <memcpy@plt> */
/* @0x24b7b8 cmp r5, #0 */
/* @0x24b7bc str r6, [r8, #0x4] */
/* @0x24b7c0 beq 0x24b7cc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe30> */
/* @0x24b7c4 mov r0, r5 */
/* @0x24b7c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b7cc ldr r3, [r8, #0x8] */
/* @0x24b7d0 ldr r7, [r11, #-0x7c] */
/* @0x24b7d4 add r5, r4, #1 */
/* @0x24b7d8 ldr r2, [r8] */
/* @0x24b7dc ldrh r1, [r7] */
/* @0x24b7e0 strh r1, [r2, r3] */
/* @0x24b7e4 ldr r3, [r8, #0x8] */
/* @0x24b7e8 add r3, r3, #1 */
/* @0x24b7ec str r3, [r8, #0x8] */
/* @0x24b7f0 b 0x24b1fc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x860> */
/* @0x24b7f4 ldr r2, [r8, #0x8] */
/* @0x24b7f8 ldr r3, [r8, #0x4] */
/* @0x24b7fc mvn r1, r2 */
/* @0x24b800 add r1, r3, r1 */
/* @0x24b804 cmp r1, #1 */
/* @0x24b808 bgt 0x24b870 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xed4> */
/* @0x24b80c cmp r3, #0 */
/* @0x24b810 add r2, r2, #2 */
/* @0x24b814 addne r3, r3, r3, lsl #1 */
/* @0x24b818 ldr r5, [r8] */
/* @0x24b81c moveq r3, #3 */
/* @0x24b820 addne r3, r3, r3, lsr #31 */
/* @0x24b824 asrne r3, r3, #1 */
/* @0x24b828 cmp r2, r3 */
/* @0x24b82c addgt r2, r2, r2, lsl #1 */
/* @0x24b830 addgt r2, r2, r2, lsr #31 */
/* @0x24b834 asrgt r3, r2, #1 */
/* @0x24b838 str r3, [r11, #-0xa8] */
/* @0x24b83c mov r0, r3 */
/* @0x24b840 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b844 ldr r2, [r8, #0x4] */
/* @0x24b848 mov r1, r5 */
/* @0x24b84c str r0, [r8] */
/* @0x24b850 bl 0xb65bc <memcpy@plt> */
/* @0x24b854 ldr r3, [r11, #-0xa8] */
/* @0x24b858 cmp r5, #0 */
/* @0x24b85c str r3, [r8, #0x4] */
/* @0x24b860 beq 0x24b86c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xed0> */
/* @0x24b864 mov r0, r5 */
/* @0x24b868 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b86c ldr r2, [r8, #0x8] */
/* @0x24b870 ldr r3, [r8] */
/* @0x24b874 mov r0, #36 */
/* @0x24b878 add r1, r3, r2 */
/* @0x24b87c strb r0, [r3, r2] */
/* @0x24b880 strb r9, [r1, #0x1] */
/* @0x24b884 ldr r1, [r8, #0x8] */
/* @0x24b888 ldr r2, [r8, #0x4] */
/* @0x24b88c add r3, r1, #1 */
/* @0x24b890 str r3, [r8, #0x8] */
/* @0x24b894 mvn r0, r3 */
/* @0x24b898 add r0, r2, r0 */
/* @0x24b89c cmp r0, #1 */
/* @0x24b8a0 bgt 0x24b908 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xf6c> */
/* @0x24b8a4 cmp r2, #0 */
/* @0x24b8a8 add r1, r1, #3 */
/* @0x24b8ac addne r2, r2, r2, lsl #1 */
/* @0x24b8b0 ldr r5, [r8] */
/* @0x24b8b4 moveq r3, #3 */
/* @0x24b8b8 addne r2, r2, r2, lsr #31 */
/* @0x24b8bc asrne r3, r2, #1 */
/* @0x24b8c0 cmp r1, r3 */
/* @0x24b8c4 addgt r1, r1, r1, lsl #1 */
/* @0x24b8c8 addgt r1, r1, r1, lsr #31 */
/* @0x24b8cc asrgt r3, r1, #1 */
/* @0x24b8d0 str r3, [r11, #-0xa8] */
/* @0x24b8d4 mov r0, r3 */
/* @0x24b8d8 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b8dc ldr r2, [r8, #0x4] */
/* @0x24b8e0 mov r1, r5 */
/* @0x24b8e4 str r0, [r8] */
/* @0x24b8e8 bl 0xb65bc <memcpy@plt> */
/* @0x24b8ec ldr r3, [r11, #-0xa8] */
/* @0x24b8f0 cmp r5, #0 */
/* @0x24b8f4 str r3, [r8, #0x4] */
/* @0x24b8f8 beq 0x24b904 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xf68> */
/* @0x24b8fc mov r0, r5 */
/* @0x24b900 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b904 ldr r3, [r8, #0x8] */
/* @0x24b908 ldr r2, [r8] */
/* @0x24b90c add r5, r4, #1 */
/* @0x24b910 b 0x24b1e4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x848> */
/* @0x24b914 ldr r3, [r11, #-0x54] */
/* @0x24b918 str r3, [r11, #-0x74] */
/* @0x24b91c b 0x24b148 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x7ac> */
/* @0x24b920 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24b924 andseq r2, r10, r12, ror pc */
/* @0x24b928 andseq r3, r10, r8, ror #4 */
/* @0x24b92c andseq r10, r0, r4, lsl #29 */
/* @0x24b930 andseq r2, r10, r4, lsl #11 */
