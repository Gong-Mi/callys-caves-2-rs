/* cally 逆向卡：F_JS_ToNumber（原版 libyoyo.so，armv7）
 * @func 0x24cfac 0x24d4f4  size 1352  338 条（0x24d4e4..0x24d4f0 是 4 字 literal pool，objdump 译成指令，按规矩保留原写法）
 * 级别: 正文（14 路 tag 分派 + 字符串解析的全部 11 个出口 + 7 类数值叶子逐条解码；3 条 open 见文末）
 * 符号: _Z13F_JS_ToNumberR6RValueS0_ → int32 F_JS_ToNumber(RValue& out, RValue& in)
 *
 * ── 签名与返回约定（由 5 个同族调用者 + 自身递归互证，不是按名字猜的）──────────────
 *   第 1 参 r0 = **输出** RValue：入口 mov r6, r0（0x24cfbc），此后只往 r6 写；
 *   第 2 参 r1 = 输入：只在 0x24cfac / 0x24d004 / 0x24d200 / 0x24d2d0 / 0x24d2fc 读 [r1]、[r1+4]、[r1+0xc]，
 *   全函数没有一条 str [r1]（后半程 r1 被当暂存器重用：0x24d29c mov r1,r7、0x24d2fc ldm r1,{r0,r1}）。
 *   返回 int32：0 = 成功（out 里是 8 字节 double、tag 0）；1 = 失败（调用者转 JSThrowTypeError）；
 *              2 = F_JS_ToPrimitive 的返回码原样透传（DoConv 只判 0/1，2 落在"其它"分支）。
 *   互证：F_JS_ToInt32 0x24d5f8 / F_JS_ToUint32 0x24d520 / F_JS_ToInteger 0x24d760 /
 *         JS_ToUint16 0x24d91c 全部是 r0=&栈上 16B 临时、r1=源；
 *         DoConv 的 flag2 路 0xeb72c 是 r0=sp+36（输出槽）、r1=sp+20（boxType 装好的源）。
 *         递归调用点 0x24d2a0 是 r0=r6（外层 out）、r1=sp+8（ToPrimitive 的产物）—— 位置对调就崩，
 *         所以"第 1 参是输出"是硬约束，不是约定俗成。
 *
 * ── tag 分派（0x24cfc0..0x24d000）────────────────────────────────────
 *   tag = [in+0xc] & 0x00FFFFFF      0x24cfac ldr r3,[r1,#0xc] / 0x24cfb4 bic r3,r3,#-16777216
 *   cmp r3,#13 后 addls pc,pc,r3,lsl #2；表体起点 = addls 地址+8 = 0x24cfcc，14 项：
 *     0  real    → 0x24d200   1  string  → 0x24d004   2  数组 → 默认   3  指针 → 默认
 *     4          → 默认       5  undefined→ 0x24d224  6  对象 → 0x24d258
 *     7  int32   → 0x24d2d0   8/9       → 默认        10 int64 → 0x24d2fc
 *     11         → 默认       12 null   → 0x24d1e0    13 bool  → 0x24d200
 *   tag>13（含未解析变量引用 0x00FFFFFF）走 addls 不成立后的 b 0x24d1d0。
 *   → 本函数的表把 5=undefined、12=null 钉死了（DoConv 的动态表把 5 与 12 都归到 bool 桶，
 *     与此冲突，见 claims TONUM-004/005）。
 *
 * ── 默认项 0x24d1d0：return 0 且**一个字节都不写 out** ────────────────────────
 *   0x24d1d0 mov r12,#0 / 0x24d1d4 mov r0,r12 / 收栈返回。数组、指针、tag 4/8/9/11、
 *   0x00FFFFFF 全部落这里：调用者拿到"成功"，但 out 仍是调之前的内容（连 tag 都没写）。
 *   这是本函数最容易踩的洞：F_JS_ToInt32 的输出临时槽初值是 {0,0,0,0x00FFFFFF}，
 *   所以数组喂进 ToInt32 会得到 0.0；而 DoConv 的 flag2 输出槽 sp+36 没有预置，会读到栈上残值。
 *
 * ── 数值叶子（都写 tag 0）──────────────────────────────────────────
 *   real/bool 0x24d200: 8 字节原样复制（ldr/ldr/str/stm），bool 在 RValue 里也是 double 0.0/1.0，同一条路。
 *   null      0x24d1e0: {0,0,tag 0} —— 显式 0.0（JS Number(null) === 0）。
 *   int32     0x24d2d0: vmov s15,r2 → **vcvt.f64.s32**（有符号）→ stm。tag 7 的 4 字节按 signed 解释。
 *   int64     0x24d2fc: ldm r1,{r0,r1} → __floatdidf → stm。tag 10 的 8 字节按 signed 64 位解释。
 *   undefined 0x24d224: 不是现场构造，而是从 .bss 复制 16 字节常量：
 *             base = 0x24d22c+8 + mem32[0x24d4e4]=0x508874 → 0x755aa8；0x24d230 add #0x930、0x24d234 add #0xc
 *             → 源地址 0x7563e4，ldm r4!,{r0,r1,r2,r3} 后逐字 str 到 out。
 *             该地址落在 .bss（0x479a90..0x7594c8）的零填区，全库既无重定位也无第二处地址计算，
 *             静态内容就是 {0,0,0,0} = +0.0/tag 0。**"undefined→NaN" 因此没被证实**（open 1）。
 *
 * ── 对象叶子 0x24d258（tag 6）──────────────────────────────────────
 *   先在 sp+8 造临时 {0,0,0,0x00FFFFFF}（0x24d264/0x24d278/0x24d27c），
 *   再 F_JS_ToPrimitive(&tmp=sp+8, in, hint=0)（0x24d280，r2=0 —— 不是 1）。
 *   r0==2 → 0x24d374（判临时是否可释放 → 释放/不释放 → return 2）；r0==1 → 0x24d320（同样判 → return 1）；
 *   r0==0 → 递归 F_JS_ToNumber(out, &tmp)（0x24d2a0）。
 *   递归返回只判 ==1（0x24d2a4）：返回 2 会被当成成功吞掉，然后按 (tag-1)&0x00FFFFFC 释放临时，
 *   一路 b 0x24d1d0 返回 0 —— 这是与"2=错误"约定不一致的一处（见 open 侧 claims）。
 *
 * ── 字符串叶子 0x24d004（tag 1）：RValue [0] = _RefThing<const char>*，[obj] 才是 char* ──
 *   0x24d004 ldr r2,[r1] → 0x24d00c ldr r4,[r2]；out.tag 先被写成 0（0x24d010）。
 *   ① text==NULL（0x24d01c）或 *text==0（0x24d028）→ 0x24d350 写 out.lo=out.hi=0 → return 0。
 *   ② 前导空白循环 0x24d034..0x24d0a8（utf8_extract_char 逐码点，游标在 [sp]）：
 *        (cp & 0xFF7F) == 0x20  → 空格与 U+00A0（0x24d044/0x24d04c，掩掉 bit7 后同值）
 *        (cp-9) & 0xFFFF <= 2   → 0x09/0x0A/0x0B（0x24d040/0x24d048/0x24d050/0x24d054）
 *        cp == 12、13、0x2028（r8=0x2028，0x24d058/0x24d060/0x24d064）
 *        cp > 160 → utf8proc_get_property(cp) 返回结构 +0 处的 16 位字段减 7（记作 k），
 *                   k ≤ 22 且 (1<<k) & 0x007F0001 非零才算空白（k∈{0}∪[16,22]；字段名未在卡内确认，
 *                   utf8proc 的 category 编号里 23..29 是 ZS/ZL/ZP/CC/CF/CS/CO，与掩码位置吻合）
 *                   0x24d078/0x24d07c/0x24d094/0x24d098/0x24d09c/0x24d0a0
 *        注意 0x00..0x08、0x0E..0x1F 都**不算**空白（cmpne 覆盖了前一条 flags）。
 *   ③ 全空白 → 0x24d350 → 0.0。
 *   ④ 首个非空白字符（0x24d0c8 解码，r5=[sp] 是它的地址）按序分派：
 *        '0'（0x24d0dc）→ 0x24d3b8 把 text[1]&0xDF 与 'X' 比 → 0x24d3c4 十六进制
 *        任意首字符但 text[1]=='X'(0x58)（0x24d0d0/0x24d0e0）→ 直接进 0x24d3c4（见 open 2）
 *        'I'（0x24d0e8）→ strncmp(text,"Infinity",8)（0x24d450/0x24d458 字符串 0x3553f4）
 *        '-'（0x24d0f0）→ strncmp(text,"-Infinity",9)（0x24d488/0x24d490，0x355ec4）
 *        '+'（0x24d0f8）→ strncmp(text,"+Infinity",9)（0x24d4c0/0x24d4c8，0x355ed0）
 *        只有大写 I；小写 "infinity"/"nan"/"inf" 一律走 0x24d120 → 尾部垃圾 → NaN。
 *   ⑤ ±Inf：out.lo=0、out.hi=0x7FF00000 / 0xFFF00000（0x24d474/0x24d478、0x24d4b0/0x24d4b4），
 *        游标 += 8 / 9（0x24d468、0x24d4a4、0x24d4dc）。
 *   ⑥ 十六进制 0x24d3c4：isValidRadixChar(text[2],16) 为 0 直接 NaN（0x24d3cc/0x24d3d8）；
 *        否则 acc = digit + acc*16（0x24d438 add r7,r0,r7,lsl #4）在 32 位里**回绕**，
 *        结尾 vcvt.f64.s32（有符号！0x24d440/0x24d444）→ "0xFFFFFFFF" = -1.0、"0x80000000" = -2147483648.0。
 *   ⑦ 其余（'+'、'-'、数字）→ 0x24d3a0 strtod(text, &end) 直接取 double（0x24d3a8），游标 = end。
 *   ⑧ 尾部检查 0x24d124/0x24d130：从游标继续跳空白；遇到非空白 → 0x24d1c4 写 NaN
 *        {lo 0xFFFFFFFF, hi 0x7FFFFFFF}（mvn/mvn/stm，0x24d1c4..0x24d1cc）；到结尾 → 保留已解析值。
 *        所以 "12 " = 12、"12x" = NaN、"1e" = NaN、"0b101" = NaN（strtod 停在 'b'）。
 *
 * ── out 的写点分布（逐条列出，避免"哪条路都写"的误读）──────────────────────
 *   tag 单独写：0x24d010（字符串路入口预置 0）、0x24d210（real/bool）、0x24d2dc（int32）、0x24d30c（int64）、
 *   0x24d1f0（null）
 *   8 字节一起写：0x24d1e4+0x24d1ec（null 的 0.0）、0x24d23c..0x24d24c（undefined 复制的 4 字）、
 *   0x24d2ec（int32）、0x24d310（int64）、0x24d214（real/bool 复制）、0x24d354+0x24d358（空串/全空白 0.0）、
 *   0x24d1cc（NaN）、0x24d3b0（strtod）、0x24d3f0（hex 游标）+0x24d3f4（hex 值）、
 *   0x24d478+0x24d480（+Inf）、0x24d4b4+0x24d4b8（-Inf）
 *   默认项与 tag 6 的失败路：0 条 —— 这就是"静默成功但不写 out"的证据面。
 *
 * 结论（本卡新增的硬事实）：
 *   1. 这是 JS 语义的 ToNumber，但**只认 8 个 tag**（0/1/5/6/7/10/12/13）；数组/指针/tag 4/8/9/11
 *      与未解析引用一律"静默成功 + 不写 out"，与 DoConv 对这些 tag 一律 VMError 的严格态度相反。
 *   2. tag 5 → 复制 .bss 常量（静态零 = 0.0），tag 12 → 显式 0.0：把 5/12 分别钉成 undefined/null，
 *      与 DoConv 的"标签 5、12 都算 bool"的粗粒度表冲突，DoConv 那张表的 5/12 需要按本卡修正。
 *   3. 字符串解析是"手写空白剥离 + C 库 strtod + 尾部垃圾否决"三段式，十六进制单独一条 32 位回绕通路；
 *      NaN 常量是 {0xFFFFFFFF, 0x7FFFFFFF}，与 ±Inf 的 {0,0x7FF00000} 区分开。
 * open:
 *   1. tag 5 的 16 字节常量在 .bss 0x7563e4，文件里无内容、无重定位、全库无第二处地址计算 →
 *      按静态映像只能读成 +0.0，没有任何证据支持"undefined→NaN"；若存在本批未发现的运行期
 *      写入者（例如 memset/memcpy 整块初始化）则另当别论，故 claims 记 narrowed 而非 proven。
 *   2. text[1]=='X' 的十六进制判定不校验首字符：首字符不是 '0' 也会进 0x24d3c4 并从 text+2 起解析
 *      （"aX10" → 16）。是否为原版 bug 未判定。
 *   3. 0x24d3e8..0x24d3f4 的"0x 后面为空 → 0.0"分支不可达（text[2]==0 时 isValidRadixChar 已先返 0 走 NaN）；
 *      0x24d1c0 的 beq 0x24d1d0 同理基本不可达。按死代码记录，未删除。
 */
/* ---- 段1：入口（tag 取 +12，掩掉高字节） ---- */
/* @0x24cfac ldr r3, [r1, #0xc] */
/* @0x24cfb0 push {r4, r5, r6, r7, r8, lr} */
/* @0x24cfb4 bic r3, r3, #-16777216 */
/* @0x24cfb8 sub sp, sp, #24 */
/* @0x24cfbc mov r6, r0 */
/* ---- 段2：tag 分派（cmp #13 + addls 表，表体 0x24cfcc..0x24d000） ---- */
/* @0x24cfc0 cmp r3, #13 */
/* @0x24cfc4 addls pc, pc, r3, lsl #2 */
/* @0x24cfc8 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24cfcc b 0x24d200 <_Z13F_JS_ToNumberR6RValueS0_+0x254> —— tag 0 real → 0x24d200 */
/* @0x24cfd0 b 0x24d004 <_Z13F_JS_ToNumberR6RValueS0_+0x58> —— tag 1 string → 0x24d004 */
/* @0x24cfd4 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> —— tag 2 数组 → 默认（不写 out） */
/* @0x24cfd8 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> —— tag 3 指针 → 默认 */
/* @0x24cfdc b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> —— tag 4 → 默认 */
/* @0x24cfe0 b 0x24d224 <_Z13F_JS_ToNumberR6RValueS0_+0x278> —— tag 5 undefined → 0x24d224 */
/* @0x24cfe4 b 0x24d258 <_Z13F_JS_ToNumberR6RValueS0_+0x2ac> —— tag 6 对象 → 0x24d258 */
/* @0x24cfe8 b 0x24d2d0 <_Z13F_JS_ToNumberR6RValueS0_+0x324> —— tag 7 int32 → 0x24d2d0 */
/* @0x24cfec b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> —— tag 8 → 默认 */
/* @0x24cff0 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> —— tag 9 → 默认 */
/* @0x24cff4 b 0x24d2fc <_Z13F_JS_ToNumberR6RValueS0_+0x350> —— tag 10 int64 → 0x24d2fc */
/* @0x24cff8 b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> —— tag 11 → 默认 */
/* @0x24cffc b 0x24d1e0 <_Z13F_JS_ToNumberR6RValueS0_+0x234> —— tag 12 null → 0x24d1e0 */
/* @0x24d000 b 0x24d200 <_Z13F_JS_ToNumberR6RValueS0_+0x254> —— tag 13 bool → 0x24d200 */
/* ---- 段3：tag 1 字符串 —— 取 _RefThing->text，先写 out.tag=0 ---- */
/* @0x24d004 ldr r2, [r1] */
/* @0x24d008 mov r3, #0 */
/* @0x24d00c ldr r4, [r2] */
/* @0x24d010 str r3, [r0, #0xc] */
/* @0x24d014 cmp r4, r3 */
/* @0x24d018 str r4, [sp] */
/* @0x24d01c beq 0x24d350 <_Z13F_JS_ToNumberR6RValueS0_+0x3a4> */
/* @0x24d020 ldrb r3, [r4] */
/* @0x24d024 cmp r3, #0 */
/* @0x24d028 beq 0x24d350 <_Z13F_JS_ToNumberR6RValueS0_+0x3a4> */
/* @0x24d02c movw r8, #0x2028 */
/* @0x24d030 mov r7, #1 */
/* ---- 段4：前导空白剥离（utf8 逐码点） ---- */
/* @0x24d034 mov r0, sp */
/* @0x24d038 bl 0x10fb38 <utf8_extract_char> */
/* @0x24d03c movw r3, #0xff7f */
/* @0x24d040 sub r1, r0, #9 */
/* @0x24d044 and r3, r0, r3 */
/* @0x24d048 uxth r1, r1 */
/* @0x24d04c cmp r3, #32 */
/* @0x24d050 cmpne r1, #2 */
/* @0x24d054 bls 0x24d340 <_Z13F_JS_ToNumberR6RValueS0_+0x394> */
/* @0x24d058 cmp r0, #13 */
/* @0x24d05c beq 0x24d340 <_Z13F_JS_ToNumberR6RValueS0_+0x394> */
/* @0x24d060 cmp r0, r8 */
/* @0x24d064 cmpne r0, #12 */
/* @0x24d068 beq 0x24d340 <_Z13F_JS_ToNumberR6RValueS0_+0x394> */
/* @0x24d06c cmp r0, #160 */
/* @0x24d070 ble 0x24d0ac <_Z13F_JS_ToNumberR6RValueS0_+0x100> */
/* @0x24d074 bl 0x23f854 <_Z21utf8proc_get_propertyi> */
/* @0x24d078 mov r3, #1 */
/* @0x24d07c movt r3, #0x7f */
/* @0x24d080 cmp r0, #0 */
/* @0x24d084 beq 0x24d0ac <_Z13F_JS_ToNumberR6RValueS0_+0x100> */
/* @0x24d088 ldrh r2, [r0] */
/* @0x24d08c sub r2, r2, #7 */
/* @0x24d090 uxth r2, r2 */
/* @0x24d094 cmp r2, #22 */
/* @0x24d098 lsl r1, r7, r2 */
/* @0x24d09c and r3, r1, r3 */
/* @0x24d0a0 bhi 0x24d0ac <_Z13F_JS_ToNumberR6RValueS0_+0x100> */
/* @0x24d0a4 cmp r3, #0 */
/* @0x24d0a8 bne 0x24d340 <_Z13F_JS_ToNumberR6RValueS0_+0x394> */
/* ---- 段5：首个非空白字符的五路分派 ---- */
/* @0x24d0ac str r4, [sp] */
/* @0x24d0b0 ldrb r3, [r4] */
/* @0x24d0b4 cmp r3, #0 */
/* @0x24d0b8 beq 0x24d350 <_Z13F_JS_ToNumberR6RValueS0_+0x3a4> */
/* @0x24d0bc add r0, sp, #4 */
/* @0x24d0c0 str r4, [sp, #0x4] */
/* @0x24d0c4 str r4, [sp, #0x8] */
/* @0x24d0c8 bl 0x10fb38 <utf8_extract_char> */
/* @0x24d0cc ldr r5, [sp] */
/* @0x24d0d0 ldrb r3, [r5, #0x1] */
/* @0x24d0d4 cmp r0, #48 */
/* @0x24d0d8 mov r4, r0 */
/* @0x24d0dc beq 0x24d3b8 <_Z13F_JS_ToNumberR6RValueS0_+0x40c> */
/* @0x24d0e0 cmp r3, #88 */
/* @0x24d0e4 beq 0x24d3c4 <_Z13F_JS_ToNumberR6RValueS0_+0x418> */
/* @0x24d0e8 cmp r0, #73 */
/* @0x24d0ec beq 0x24d450 <_Z13F_JS_ToNumberR6RValueS0_+0x4a4> */
/* @0x24d0f0 cmp r0, #45 */
/* @0x24d0f4 beq 0x24d488 <_Z13F_JS_ToNumberR6RValueS0_+0x4dc> */
/* @0x24d0f8 cmp r0, #43 */
/* @0x24d0fc beq 0x24d4c0 <_Z13F_JS_ToNumberR6RValueS0_+0x514> */
/* @0x24d100 sub r3, r0, #45 */
/* @0x24d104 uxth r3, r3 */
/* @0x24d108 cmp r3, #1 */
/* @0x24d10c bls 0x24d3a0 <_Z13F_JS_ToNumberR6RValueS0_+0x3f4> */
/* @0x24d110 sub r3, r4, #48 */
/* @0x24d114 uxth r3, r3 */
/* @0x24d118 cmp r3, #9 */
/* @0x24d11c bls 0x24d3a0 <_Z13F_JS_ToNumberR6RValueS0_+0x3f4> */
/* ---- 段6：尾部检查公用入口（游标 [sp+8]） ---- */
/* @0x24d120 ldr r4, [sp, #0x8] */
/* @0x24d124 add r5, sp, #8 */
/* @0x24d128 movw r8, #0x2028 */
/* @0x24d12c mov r7, #1 */
/* @0x24d130 ldrb r3, [r4] */
/* @0x24d134 mov r0, r5 */
/* @0x24d138 cmp r3, #0 */
/* @0x24d13c beq 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24d140 bl 0x10fb38 <utf8_extract_char> */
/* @0x24d144 movw r3, #0xff7f */
/* @0x24d148 sub r1, r0, #9 */
/* @0x24d14c and r3, r0, r3 */
/* @0x24d150 uxth r1, r1 */
/* @0x24d154 cmp r3, #32 */
/* @0x24d158 cmpne r1, #2 */
/* @0x24d15c bls 0x24d36c <_Z13F_JS_ToNumberR6RValueS0_+0x3c0> */
/* @0x24d160 cmp r0, #13 */
/* @0x24d164 beq 0x24d36c <_Z13F_JS_ToNumberR6RValueS0_+0x3c0> */
/* @0x24d168 cmp r0, r8 */
/* @0x24d16c cmpne r0, #12 */
/* @0x24d170 beq 0x24d36c <_Z13F_JS_ToNumberR6RValueS0_+0x3c0> */
/* @0x24d174 cmp r0, #160 */
/* @0x24d178 ble 0x24d1b4 <_Z13F_JS_ToNumberR6RValueS0_+0x208> */
/* @0x24d17c bl 0x23f854 <_Z21utf8proc_get_propertyi> */
/* @0x24d180 mov r3, #1 */
/* @0x24d184 movt r3, #0x7f */
/* @0x24d188 cmp r0, #0 */
/* @0x24d18c beq 0x24d1b4 <_Z13F_JS_ToNumberR6RValueS0_+0x208> */
/* @0x24d190 ldrh r2, [r0] */
/* @0x24d194 sub r2, r2, #7 */
/* @0x24d198 uxth r2, r2 */
/* @0x24d19c cmp r2, #22 */
/* @0x24d1a0 lsl r1, r7, r2 */
/* @0x24d1a4 and r3, r1, r3 */
/* @0x24d1a8 bhi 0x24d1b4 <_Z13F_JS_ToNumberR6RValueS0_+0x208> */
/* @0x24d1ac cmp r3, #0 */
/* @0x24d1b0 bne 0x24d36c <_Z13F_JS_ToNumberR6RValueS0_+0x3c0> */
/* @0x24d1b4 str r4, [sp, #0x8] */
/* @0x24d1b8 ldrb r3, [r4] */
/* @0x24d1bc cmp r3, #0 */
/* @0x24d1c0 beq 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* ---- 段7：NaN 常量就地构造（不取 .bss） ---- */
/* @0x24d1c4 mvn r2, #0 */
/* @0x24d1c8 mvn r3, #-2147483648 */
/* @0x24d1cc stm r6, {r2, r3} */
/* ---- 段8：默认项 —— return 0，不写 out ---- */
/* @0x24d1d0 mov r12, #0 */
/* @0x24d1d4 mov r0, r12 */
/* @0x24d1d8 add sp, sp, #24 */
/* @0x24d1dc pop {r4, r5, r6, r7, r8, pc} */
/* ---- 段9：tag 12（null）→ 0.0 ---- */
/* @0x24d1e0 mov r3, #0 */
/* @0x24d1e4 str r3, [r0] */
/* @0x24d1e8 mov r12, r3 */
/* @0x24d1ec str r3, [r0, #0x4] */
/* @0x24d1f0 str r3, [r0, #0xc] */
/* @0x24d1f4 mov r0, r12 */
/* @0x24d1f8 add sp, sp, #24 */
/* @0x24d1fc pop {r4, r5, r6, r7, r8, pc} */
/* ---- 段10：tag 0 real / tag 13 bool → 8 字节原样复制 ---- */
/* @0x24d200 ldr r0, [r1] */
/* @0x24d204 mov r3, #0 */
/* @0x24d208 ldr r2, [r1, #0x4] */
/* @0x24d20c mov r12, r3 */
/* @0x24d210 str r3, [r6, #0xc] */
/* @0x24d214 stm r6, {r0, r2} */
/* @0x24d218 mov r0, r12 */
/* @0x24d21c add sp, sp, #24 */
/* @0x24d220 pop {r4, r5, r6, r7, r8, pc} */
/* ---- 段11：tag 5（undefined）→ 从 .bss 0x7563e4 复制 16B ---- */
/* @0x24d224 ldr r4, [pc, #0x2b8] */
/* @0x24d228 mov r12, #0 */
/* @0x24d22c add r4, pc, r4 */
/* @0x24d230 add r4, r4, #2352 */
/* @0x24d234 add r4, r4, #12 */
/* @0x24d238 ldm r4!, {r0, r1, r2, r3} */
/* @0x24d23c str r0, [r6] */
/* @0x24d240 mov r0, r12 */
/* @0x24d244 str r1, [r6, #0x4] */
/* @0x24d248 str r2, [r6, #0x8] */
/* @0x24d24c str r3, [r6, #0xc] */
/* @0x24d250 add sp, sp, #24 */
/* @0x24d254 pop {r4, r5, r6, r7, r8, pc} */
/* ---- 段12：tag 6 对象 → ToPrimitive(hint 0) + 递归 ---- */
/* @0x24d258 add r7, sp, #8 */
/* @0x24d25c mov r3, #0 */
/* @0x24d260 mov r2, r3 */
/* @0x24d264 str r3, [sp, #0x10] */
/* @0x24d268 mov r0, r7 */
/* @0x24d26c mov r4, #0 */
/* @0x24d270 mvn r3, #-16777216 */
/* @0x24d274 mov r5, #0 */
/* @0x24d278 str r3, [sp, #0x14] */
/* @0x24d27c strd r4, r5, [sp, #8] */
/* @0x24d280 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x24d284 cmp r0, #2 */
/* @0x24d288 mov r4, r0 */
/* @0x24d28c beq 0x24d374 <_Z13F_JS_ToNumberR6RValueS0_+0x3c8> */
/* @0x24d290 cmp r0, #1 */
/* @0x24d294 beq 0x24d320 <_Z13F_JS_ToNumberR6RValueS0_+0x374> */
/* @0x24d298 mov r0, r6 */
/* @0x24d29c mov r1, r7 */
/* @0x24d2a0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d2a4 cmp r0, #1 */
/* @0x24d2a8 beq 0x24d320 <_Z13F_JS_ToNumberR6RValueS0_+0x374> */
/* @0x24d2ac ldr r3, [sp, #0x14] */
/* @0x24d2b0 sub r3, r3, #1 */
/* @0x24d2b4 bic r3, r3, #-16777216 */
/* @0x24d2b8 bic r3, r3, #3 */
/* @0x24d2bc cmp r3, #0 */
/* @0x24d2c0 bne 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24d2c4 mov r0, r7 */
/* @0x24d2c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d2cc b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* ---- 段13：tag 7 int32 → vcvt.f64.s32（有符号） ---- */
/* @0x24d2d0 ldr r2, [r1] */
/* @0x24d2d4 mov r3, #0 */
/* @0x24d2d8 mov r12, r3 */
/* @0x24d2dc str r3, [r0, #0xc] */
/* @0x24d2e0 vmov s15, r2 */
/* @0x24d2e4 vcvt.f64.s32 d7, s15 */
/* @0x24d2e8 vmov r2, r3, d7 */
/* @0x24d2ec stm r0, {r2, r3} */
/* @0x24d2f0 mov r0, r12 */
/* @0x24d2f4 add sp, sp, #24 */
/* @0x24d2f8 pop {r4, r5, r6, r7, r8, pc} */
/* ---- 段14：tag 10 int64 → __floatdidf ---- */
/* @0x24d2fc ldm r1, {r0, r1} */
/* @0x24d300 bl 0x319164 <__floatdidf> */
/* @0x24d304 mov r3, #0 */
/* @0x24d308 mov r12, r3 */
/* @0x24d30c str r3, [r6, #0xc] */
/* @0x24d310 stm r6, {r0, r1} */
/* @0x24d314 mov r0, r12 */
/* @0x24d318 add sp, sp, #24 */
/* @0x24d31c pop {r4, r5, r6, r7, r8, pc} */
/* ---- 段15：递归/ToPrimitive 的错码收尾（1 或 2） ---- */
/* @0x24d320 ldr r3, [sp, #0x14] */
/* @0x24d324 sub r3, r3, #1 */
/* @0x24d328 bic r3, r3, #-16777216 */
/* @0x24d32c bic r3, r3, #3 */
/* @0x24d330 cmp r3, #0 */
/* @0x24d334 beq 0x24d360 <_Z13F_JS_ToNumberR6RValueS0_+0x3b4> */
/* @0x24d338 mov r12, #1 */
/* @0x24d33c b 0x24d1d4 <_Z13F_JS_ToNumberR6RValueS0_+0x228> */
/* ---- 段16：前导空白命中 → 取下一码点 ---- */
/* @0x24d340 ldr r4, [sp] */
/* @0x24d344 ldrb r3, [r4] */
/* @0x24d348 cmp r3, #0 */
/* @0x24d34c bne 0x24d034 <_Z13F_JS_ToNumberR6RValueS0_+0x88> */
/* ---- 段17：空串/全空白 → 0.0 ---- */
/* @0x24d350 mov r3, #0 */
/* @0x24d354 str r3, [r6] */
/* @0x24d358 str r3, [r6, #0x4] */
/* @0x24d35c b 0x24d1d0 <_Z13F_JS_ToNumberR6RValueS0_+0x224> */
/* @0x24d360 mov r0, r7 */
/* @0x24d364 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d368 b 0x24d338 <_Z13F_JS_ToNumberR6RValueS0_+0x38c> */
/* ---- 段18：尾部空白命中 → 取下一码点 ---- */
/* @0x24d36c ldr r4, [sp, #0x8] */
/* @0x24d370 b 0x24d130 <_Z13F_JS_ToNumberR6RValueS0_+0x184> */
/* @0x24d374 ldr r3, [sp, #0x14] */
/* @0x24d378 sub r3, r3, #1 */
/* @0x24d37c bic r3, r3, #-16777216 */
/* @0x24d380 bic r3, r3, #3 */
/* @0x24d384 cmp r3, #0 */
/* @0x24d388 movne r12, r0 */
/* @0x24d38c bne 0x24d1d4 <_Z13F_JS_ToNumberR6RValueS0_+0x228> */
/* @0x24d390 mov r0, r7 */
/* @0x24d394 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d398 mov r12, r4 */
/* @0x24d39c b 0x24d1d4 <_Z13F_JS_ToNumberR6RValueS0_+0x228> */
/* ---- 段19：strtod 通路 ---- */
/* @0x24d3a0 mov r0, r5 */
/* @0x24d3a4 add r1, sp, #8 */
/* @0x24d3a8 bl 0xb6658 <strtod@plt> */
/* @0x24d3ac ldr r4, [sp, #0x8] */
/* @0x24d3b0 stm r6, {r0, r1} */
/* @0x24d3b4 b 0x24d124 <_Z13F_JS_ToNumberR6RValueS0_+0x178> */
/* ---- 段20：'0' 后的 X/x 判定（and #0xDF 折大寫） ---- */
/* @0x24d3b8 and r3, r3, #223 */
/* @0x24d3bc cmp r3, #88 */
/* @0x24d3c0 bne 0x24d110 <_Z13F_JS_ToNumberR6RValueS0_+0x164> */
/* ---- 段21：十六进制通路（从 text+2 起，32 位回绕累加，有符号出） ---- */
/* @0x24d3c4 ldrb r0, [r5, #0x2] */
/* @0x24d3c8 mov r1, #16 */
/* @0x24d3cc bl 0x23fe9c <_Z16isValidRadixCharci> */
/* @0x24d3d0 add r4, r5, #2 */
/* @0x24d3d4 cmp r0, #0 */
/* @0x24d3d8 beq 0x24d1c4 <_Z13F_JS_ToNumberR6RValueS0_+0x218> */
/* @0x24d3dc ldrb r3, [r5, #0x2] */
/* @0x24d3e0 cmp r3, #0 */
/* @0x24d3e4 bne 0x24d3fc <_Z13F_JS_ToNumberR6RValueS0_+0x450> */
/* @0x24d3e8 mov r2, #0 */
/* @0x24d3ec mov r3, #0 */
/* @0x24d3f0 str r4, [sp, #0x8] */
/* @0x24d3f4 stm r6, {r2, r3} */
/* @0x24d3f8 b 0x24d124 <_Z13F_JS_ToNumberR6RValueS0_+0x178> */
/* @0x24d3fc mov r5, r4 */
/* @0x24d400 mov r7, #0 */
/* @0x24d404 mov r1, #16 */
/* @0x24d408 mov r0, r3 */
/* @0x24d40c bl 0x23fe9c <_Z16isValidRadixCharci> */
/* @0x24d410 mov r4, r5 */
/* @0x24d414 mov r1, #16 */
/* @0x24d418 add r5, r5, #1 */
/* @0x24d41c cmp r0, #0 */
/* @0x24d420 beq 0x24d440 <_Z13F_JS_ToNumberR6RValueS0_+0x494> */
/* @0x24d424 ldrb r0, [r4] */
/* @0x24d428 mov r4, r5 */
/* @0x24d42c bl 0x23fe14 <_Z12getRadixCharci> */
/* @0x24d430 ldrb r3, [r5] */
/* @0x24d434 cmp r3, #0 */
/* @0x24d438 add r7, r0, r7, lsl #4 */
/* @0x24d43c bne 0x24d404 <_Z13F_JS_ToNumberR6RValueS0_+0x458> */
/* @0x24d440 vmov s15, r7 */
/* @0x24d444 vcvt.f64.s32 d7, s15 */
/* @0x24d448 vmov r2, r3, d7 */
/* @0x24d44c b 0x24d3f0 <_Z13F_JS_ToNumberR6RValueS0_+0x444> */
/* ---- 段22：Infinity / -Infinity / +Infinity 三串 strncmp ---- */
/* @0x24d450 ldr r1, [pc, #0x90] */
/* @0x24d454 mov r0, r5 */
/* @0x24d458 mov r2, #8 */
/* @0x24d45c add r1, pc, r1 */
/* @0x24d460 bl 0xb65e0 <strncmp@plt> */
/* @0x24d464 cmp r0, #0 */
/* @0x24d468 addeq r4, r5, #8 */
/* @0x24d46c bne 0x24d110 <_Z13F_JS_ToNumberR6RValueS0_+0x164> */
/* @0x24d470 str r4, [sp, #0x8] */
/* @0x24d474 mov r3, #0 */
/* @0x24d478 str r0, [r6] */
/* @0x24d47c movt r3, #0x7ff0 */
/* @0x24d480 str r3, [r6, #0x4] */
/* @0x24d484 b 0x24d124 <_Z13F_JS_ToNumberR6RValueS0_+0x178> */
/* @0x24d488 ldr r1, [pc, #0x5c] */
/* @0x24d48c mov r0, r5 */
/* @0x24d490 mov r2, #9 */
/* @0x24d494 add r1, pc, r1 */
/* @0x24d498 bl 0xb65e0 <strncmp@plt> */
/* @0x24d49c cmp r0, #0 */
/* @0x24d4a0 bne 0x24d3a0 <_Z13F_JS_ToNumberR6RValueS0_+0x3f4> */
/* @0x24d4a4 add r4, r5, #9 */
/* @0x24d4a8 mov r3, #0 */
/* @0x24d4ac str r4, [sp, #0x8] */
/* @0x24d4b0 movt r3, #0xfff0 */
/* @0x24d4b4 str r0, [r6] */
/* @0x24d4b8 str r3, [r6, #0x4] */
/* @0x24d4bc b 0x24d124 <_Z13F_JS_ToNumberR6RValueS0_+0x178> */
/* @0x24d4c0 ldr r1, [pc, #0x28] */
/* @0x24d4c4 mov r0, r5 */
/* @0x24d4c8 mov r2, #9 */
/* @0x24d4cc add r1, pc, r1 */
/* @0x24d4d0 bl 0xb65e0 <strncmp@plt> */
/* @0x24d4d4 cmp r0, #0 */
/* @0x24d4d8 bne 0x24d3a0 <_Z13F_JS_ToNumberR6RValueS0_+0x3f4> */
/* @0x24d4dc add r4, r5, #9 */
/* @0x24d4e0 b 0x24d470 <_Z13F_JS_ToNumberR6RValueS0_+0x4c4> */
/* ---- 段23：literal pool 4 字（非指令，按规矩保留 objdump 写法）
 *   0x24d4e4 = 0x508874  → 0x24d22c+8 + 0x508874 = 0x755aa8（undefined 常量基址）
 *   0x24d4e8 = 0x00107f90 → 0x24d45c+8 + 0x107f90 = 0x3553f4 "Infinity"
 *   0x24d4ec = 0x00108a28 → 0x24d494+8 + 0x108a28 = 0x355ec4 "-Infinity"
 *   0x24d4f0 = 0x001089fc → 0x24d4cc+8 + 0x1089fc = 0x355ed0 "+Infinity" ---- */
/* @0x24d4e4 subseq r8, r0, r4, ror r8 */
/* @0x24d4e8 mulseq r0, r0, pc */
/* @0x24d4ec andseq r8, r0, r8, lsr #20 */
/* @0x24d4f0 ldrsheq r8, [r0], -r12 */
