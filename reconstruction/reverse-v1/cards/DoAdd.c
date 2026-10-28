/* cally 逆向卡：DoAdd（原版 libyoyo.so，armv7）
 * @func 0xdc524 0xdd500  size 4060  1015 条指令（含尾部 literal 词）
 * 级别: 骨架（mode 三档、10 种裸类型组合的算术、两条字符串拼接、三条强制转换链已证；
 *           class 1/4/5 的用途与 boxType 的字节流细节未展开）
 * 符号: _Z5DoAddjPhPKhP6VMExec → uchar* DoAdd(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   mode = (arg>>8)&0xF，type = (arg>>16)&0xFF；arg 的 bit7..0 与 bit31..24 本函数一次也没读
 *       dc524 ubfx r2,r0,#0x8,#0x4     dc528 lsr r0,r0,#16     dc53c uxtb r9,r0
 *   switch(mode)：0→dc554；1→dc9f8；2→dcb30；3..15 落到 dc554（同 mode0 路径）   dc540/dc548/dc550
 *   帧 124 B，六个 16 B 临时 RValue：sp+24 / +40 / +56 / +72 / +88 / +104                dc538
 *   type 拆两半：[3:0] = 栈顶（右）操作数存储类，[7:4] = 次栈顶（左）操作数存储类
 *       T1 dc55c 按 type&15 选 r7（右操作数之后的位置）：0/3→sp+8，1/2/4/6→sp+4，
 *           5→读 [sp+0xc] 的 tag 走 T5 再定，>6→r7=sp（dd4a0）
 *       T2 dc590 按 type>>4 选 r8=r7+左宽度：0/3→+8，1/2/4/6→+4，5→+16（先走 T4 归一化），>6→r8=r7（dd4ac）
 *       非对称互证：0x23 走 dcccc（[r7]=int32、[r10]=int64）；0x32 走 dcd20（[r7]=int64、[r10]=int32）
 *   存储类→宽度：0=8B double、2=4B int32、3=8B int64、6=4B string(YYString*)、5=16B RValue、
 *       1/4=4B（本函数只在 T1 里给宽度，算术分派一律报错）
 *       跨函数互证：DoDup 的 dup 尺寸表（0/3→lsl#3、1/2/4→lsl#2、5→16B、6→lsl#2）
 *       与 DoPopNull 的 sp+8 / sp+4 / sp+16 是同一张表
 *   结果落点（全函数统一）：off = sp + 右宽度 + 左宽度（= r8）；结果宽 w 由 T3 定；结果写 [off-w, off)；
 *       返回 sp_new = off - w，即结果恰好成为新的栈顶（栈向下长，sp 是顶，活跃值在 [sp,...)）。
 *       该规则在 mode0 与 mode1/2 的成功路径上都成立（mode1/2 返回的是 r8-16，见 dccb8/dccc8/dd374/dd384）；
 *       出错路径（dcb1c/dcb2c/dd3bc 等）只释放临时 RValue 并返回 r8，不写结果
 *       T3 dc5bc 按 type 全字节选 w：0x00/0x02/0x03/0x20/0x23/0x30/0x32/0x33 → dc8a0(w=8)；
 *           0x22/0x66 → dc760(w=4)；0x05/0x25/0x35/0x50/0x52/0x53/0x55/0x56/0x65 → dc890(w=16)；
 *           其余 → dc9cc（r5=r4=0）后必落 VMError
 *   算术体：
 *       0x22 int32+int32（dcd3c）32 位 add，结果 tag 7（dcd40 mov r12,#7）
 *       0x33/0x32/0x23（dcd04/dcd20/dcccc）adds+adc 64 位，tag 10；0x32/0x23 里 32 位那侧按 asr #31 符号扩展
 *       含 double 的组合（dc9d8=0x00、dcce8=0x02、dcd6c=0x03、dc8cc=0x20、dc9ac=0x30）
 *           走 vcvt.f64.s32 / __floatdidf / vadd.f64，tag 0
 *       0x66 string+string → YYString 结果，tag 1（dc7f8 mov r12,#1）
 *   只有 w=16 的那一路 r4≠0，才在 dc8e4 把 tag 写回结果 +0xc；裸 4/8 B 槽不写 tag（槽里是裸类型数据，不是 RValue）
 *   tag = +12 字的低 24 位（每次比较前 bic #0xFF000000，高 8 位是标志）；0x00FFFFFF = 未解析变量占位
 *       释放判定 (tag-1)&0x00FFFFFC==0（dcab4..dcac0）→ 只有 tag 1..4 带引用计数，才调 FREE_RValue__Pre（dcb24 等）
 *
 * 已证（语义级，靠 .rodata 消息字符串定名）：
 *   0x66 拼接：YYString = {+0 buf, +4 refcount, +8 len}，12 B：operator new(12) dc7e4、stm {buf,1} dc808、len 写 +8 dc7fc；
 *       buf = YYAlloc(lenL+lenR+1) dc7f0；先 strcpy 左串（dc810，源 [sp+4]）再 strcpy 右串（dc82c，目的 buf+左长）；
 *       末尾 NUL dc830；随后对两个源串各做一次 "YYFree(buf)→清 +0/+8→LOCK→--[+4]→归零则
 *       YYFree+_RefThing<const char*>::dec+operator delete"：右串（r9=[sp]）从 dc844 起、销毁体 dcea0..dcef4；
 *       左串（r6=[r7]）从 dc86c 起、销毁体 dcef8..dcf4c
 *   mode1（dc9f8）：boxType(&sp+40, type&15, sp) → boxType(&sp+24, type>>4, 上次返回值)，先解右后解左
 *       （dca38/dca48，r8 = 第二次 boxType 的返回 = 操作数区末尾）；
 *       tag&0x00FFFFFF==0x00FFFFFF → JSThrowReferenceError "could not find variable before '+'"（dd064）
 *       或 "…after '+'"（dcf50）；F_JS_ToPrimitive 左（dca9c，失败 dd15c TypeError "…to a primitive"）、
 *       右（dcfc4，失败 dd0a4）；两边 tag 都不是 1(string) → F_JS_ToNumber 两次（dd02c / dd424）+ vadd.f64，结果 tag 0；
 *       任一是 string → F_JS_ToString 两次（dd1c0/dd1cc）+ 拼接（dd21c..dd294），结果 tag 1（dd1e0）
 *   mode2（dcb30）：同样 boxType（dcb6c/dcb7c）+ 同样的未解析检查（dd090/dcf64），但直接 F_JS_ToNumber
 *       （dcbc8/dcbe8）+ vadd.f64，结果 tag 0；失败消息带 "# 2"（dd16c/dd480/dd490）
 *       → mode1 与 mode2 是两条不同的强制链（先 ToPrimitive 再分派 / 直接 ToNumber）
 *   非法操作数按 tag 报不同 VMError（T5 走左、T4 走右）：tag2 数组 → "illegal array use"（dcddc/dce70）；
 *       tag3 指针 → "illegal pointer use"（dcdbc/dce54）；tag5 undefined → "undefined value"（dcd9c/dce38）；
 *       其余（4/6/8/9/11/12 及 >13）→ "Malformed variable"（dcf94/dcf78）
 *       → 0..13 里只有 0/13(double)、1(string)、7(int32)、10(int64) 能进加法
 *   类型组合落空 → VMError "DoAdd :: Execution Error"（dcd54，由 dc76c 的 bne 到达）
 *
 * 结论（新增四条硬事实）：
 *   1. DoAdd 把**两个操作数的存储类**塞进 opcode 参数的一个字节：高 nibble 左、低 nibble 右；
 *      这与 DoDup/DoPopNull 的"一个 nibble 一个存储类"是同一张表（0/2/3/6 与 5/1/4）。
 *   2. 栈向下长：右操作数在 [sp]，左操作数在 [sp+右宽度]；算子把结果写在操作数区的**高端**，
 *      返回 off-w —— 于是"结果即新栈顶"，三种 mode 完全一致。
 *   3. 字符串加法只在"两边都是 string"（静态 0x66 或运行时 tag1）时发生，绝不把数字隐式转成字符串再拼；
 *      混合类型一定走 ToPrimitive→ToNumber，结果必然是 double（tag 0）。
 *   4. YYString（+0 buf / +4 count / +8 len，12 B）与 _RefThing<const char*>（+0 count / +8 回指）是两种对象，
 *      DoAdd 只在前者上做拼接，销毁体里却能见到后者 —— 两种串容器的分工仍待钉。
 *
 * 尾部 dd4b4..dd4fc 是 literal pool（objdump 译成 eoreq/mla 之类），非指令；锚点按 objdump 原样保留。
 *
 * open：
 *   · 存储类 1 / 4 的含义（只在 T1 给宽度，算术分派一律 VMError）；
 *   · 存储类 5（boxed RValue）为何在 T3 里被拆成 9 个条目、且统一产出 16 B RValue 结果；
 *   · boxType（0xd7784）按 eVM_Type 从 sp 读值的字节数与返回指针推进量（本卡只见 4 个调用点）；
 *   · mode1 里 ToPrimitive 的 hint 实参（两处都传 [sp+4]=0）与"hint 非 0"的分支；
 *   · mode ≥3 是否真被 VM 发出（当前与 mode0 合流）；
 *   · tag 13 的类型名（T4/T5 都把它归进 double 类）；
 *   · 0x00FFFFFF 占位在 mode0 里不查（落到 "Malformed variable"），只有 mode1/2 显式查 —— 占位是否只出现在 boxed 操作数里；
 *   · 空串/null 串（[sp+8]=0 或 [sp+0xc]=0）跳过 strcpy 的所有权约定；
 *   · 拼接后两个源串的释放顺序（先右串 r9 后左串 r6）与所有权转移。
 */
/* @0xdc524 ubfx r2, r0, #0x8, #0x4 */
/* @0xdc528 lsr r0, r0, #16 */
/* @0xdc52c cmp r2, #0 */
/* @0xdc530 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdc534 mov r10, r1 */
/* @0xdc538 sub sp, sp, #124 */
/* @0xdc53c uxtb r9, r0 */
/* @0xdc540 beq 0xdc554 <_Z5DoAddjPhPKhP6VMExec+0x30> */
/* @0xdc544 cmp r2, #1 */
/* @0xdc548 beq 0xdc9f8 <_Z5DoAddjPhPKhP6VMExec+0x4d4> */
/* @0xdc54c cmp r2, #2 */
/* @0xdc550 beq 0xdcb30 <_Z5DoAddjPhPKhP6VMExec+0x60c> */
/* @0xdc554 and r2, r9, #15 */
/* @0xdc558 cmp r2, #6 */
/* @0xdc55c addls pc, pc, r2, lsl #2 */
/* @0xdc560 b 0xdd4a0 <_Z5DoAddjPhPKhP6VMExec+0xf7c> */
/* @0xdc564 b 0xdc948 <_Z5DoAddjPhPKhP6VMExec+0x424> */
/* @0xdc568 b 0xdc580 <_Z5DoAddjPhPKhP6VMExec+0x5c> */
/* @0xdc56c b 0xdc580 <_Z5DoAddjPhPKhP6VMExec+0x5c> */
/* @0xdc570 b 0xdc948 <_Z5DoAddjPhPKhP6VMExec+0x424> */
/* @0xdc574 b 0xdc580 <_Z5DoAddjPhPKhP6VMExec+0x5c> */
/* @0xdc578 b 0xdc954 <_Z5DoAddjPhPKhP6VMExec+0x430> */
/* @0xdc57c b 0xdc580 <_Z5DoAddjPhPKhP6VMExec+0x5c> */
/* @0xdc580 add r7, r10, #4 */
/* @0xdc584 mov r6, r9 */
/* @0xdc588 asr r2, r6, #4 */
/* @0xdc58c cmp r2, #6 */
/* @0xdc590 addls pc, pc, r2, lsl #2 */
/* @0xdc594 b 0xdd4ac <_Z5DoAddjPhPKhP6VMExec+0xf88> */
/* @0xdc598 b 0xdc940 <_Z5DoAddjPhPKhP6VMExec+0x41c> */
/* @0xdc59c b 0xdc5b4 <_Z5DoAddjPhPKhP6VMExec+0x90> */
/* @0xdc5a0 b 0xdc5b4 <_Z5DoAddjPhPKhP6VMExec+0x90> */
/* @0xdc5a4 b 0xdc940 <_Z5DoAddjPhPKhP6VMExec+0x41c> */
/* @0xdc5a8 b 0xdc5b4 <_Z5DoAddjPhPKhP6VMExec+0x90> */
/* @0xdc5ac b 0xdc8f8 <_Z5DoAddjPhPKhP6VMExec+0x3d4> */
/* @0xdc5b0 b 0xdc5b4 <_Z5DoAddjPhPKhP6VMExec+0x90> */
/* @0xdc5b4 add r8, r7, #4 */
/* @0xdc5b8 cmp r9, #102 */
/* @0xdc5bc addls pc, pc, r9, lsl #2 */
/* @0xdc5c0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5c4 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc5c8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5cc b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc5d0 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc5d4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5d8 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc5dc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5e0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5e4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5e8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5ec b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5f0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5f4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5f8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc5fc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc600 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc604 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc608 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc60c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc610 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc614 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc618 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc61c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc620 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc624 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc628 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc62c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc630 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc634 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc638 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc63c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc640 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc644 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc648 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc64c b 0xdc760 <_Z5DoAddjPhPKhP6VMExec+0x23c> */
/* @0xdc650 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc654 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc658 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc65c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc660 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc664 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc668 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc66c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc670 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc674 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc678 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc67c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc680 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc684 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc688 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc68c b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc690 b 0xdc8a0 <_Z5DoAddjPhPKhP6VMExec+0x37c> */
/* @0xdc694 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc698 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc69c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6a0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6a4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6a8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6ac b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6b0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6b4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6b8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6bc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6c0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6c4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6c8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6cc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6d0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6d4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6d8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6dc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6e0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6e4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6e8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6ec b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6f0 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6f4 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6f8 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc6fc b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc700 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc704 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc708 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc70c b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc710 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc714 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc718 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc71c b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc720 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc724 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc728 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc72c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc730 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc734 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc738 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc73c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc740 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc744 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc748 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc74c b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc750 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc754 b 0xdc9cc <_Z5DoAddjPhPKhP6VMExec+0x4a8> */
/* @0xdc758 b 0xdc890 <_Z5DoAddjPhPKhP6VMExec+0x36c> */
/* @0xdc75c b 0xdc760 <_Z5DoAddjPhPKhP6VMExec+0x23c> */
/* @0xdc760 sub r8, r8, #4 */
/* @0xdc764 mov r4, #0 */
/* @0xdc768 mov r5, r8 */
/* @0xdc76c cmp r6, #34 */
/* @0xdc770 beq 0xdcd3c <_Z5DoAddjPhPKhP6VMExec+0x818> */
/* @0xdc774 bls 0xdc8b0 <_Z5DoAddjPhPKhP6VMExec+0x38c> */
/* @0xdc778 cmp r6, #50 */
/* @0xdc77c beq 0xdcd20 <_Z5DoAddjPhPKhP6VMExec+0x7fc> */
/* @0xdc780 bls 0xdc99c <_Z5DoAddjPhPKhP6VMExec+0x478> */
/* @0xdc784 cmp r6, #51 */
/* @0xdc788 beq 0xdcd04 <_Z5DoAddjPhPKhP6VMExec+0x7e0> */
/* @0xdc78c cmp r6, #102 */
/* @0xdc790 bne 0xdcd54 <_Z5DoAddjPhPKhP6VMExec+0x830> */
/* @0xdc794 ldr r9, [r10] */
/* @0xdc798 mov r0, #12 */
/* @0xdc79c ldr r6, [r7] */
/* @0xdc7a0 cmp r9, #0 */
/* @0xdc7a4 streq r9, [sp, #0x8] */
/* @0xdc7a8 ldrne r2, [r9] */
/* @0xdc7ac strne r2, [sp, #0x8] */
/* @0xdc7b0 cmp r6, #0 */
/* @0xdc7b4 ldrne r1, [r6] */
/* @0xdc7b8 moveq r1, r6 */
/* @0xdc7bc cmp r9, #0 */
/* @0xdc7c0 ldrne r7, [r9, #0x8] */
/* @0xdc7c4 moveq r7, r9 */
/* @0xdc7c8 cmp r6, #0 */
/* @0xdc7cc streq r6, [sp, #0xc] */
/* @0xdc7d0 ldrne r3, [r6, #0x8] */
/* @0xdc7d4 str r1, [sp, #0x4] */
/* @0xdc7d8 strne r3, [sp, #0xc] */
/* @0xdc7dc ldr r2, [sp, #0xc] */
/* @0xdc7e0 add r7, r2, r7 */
/* @0xdc7e4 bl 0x27c524 <_Znwj> */
/* @0xdc7e8 mov r10, r0 */
/* @0xdc7ec add r0, r7, #1 */
/* @0xdc7f0 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdc7f4 ldr r1, [sp, #0x4] */
/* @0xdc7f8 mov r12, #1 */
/* @0xdc7fc str r7, [r10, #0x8] */
/* @0xdc800 cmp r1, #0 */
/* @0xdc804 mov r11, r0 */
/* @0xdc808 stm r10, {r11, r12} */
/* @0xdc80c beq 0xdc814 <_Z5DoAddjPhPKhP6VMExec+0x2f0> */
/* @0xdc810 bl 0xb65a4 <strcpy@plt> */
/* @0xdc814 ldr r3, [sp, #0x8] */
/* @0xdc818 cmp r3, #0 */
/* @0xdc81c beq 0xdc830 <_Z5DoAddjPhPKhP6VMExec+0x30c> */
/* @0xdc820 ldr r2, [sp, #0xc] */
/* @0xdc824 mov r1, r3 */
/* @0xdc828 add r0, r11, r2 */
/* @0xdc82c bl 0xb65a4 <strcpy@plt> */
/* @0xdc830 cmp r9, #0 */
/* @0xdc834 mov r1, #0 */
/* @0xdc838 strb r1, [r11, r7] */
/* @0xdc83c str r10, [r5] */
/* @0xdc840 beq 0xdc860 <_Z5DoAddjPhPKhP6VMExec+0x33c> */
/* @0xdc844 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdc848 ldr r5, [r9, #0x4] */
/* @0xdc84c sub r5, r5, #1 */
/* @0xdc850 str r5, [r9, #0x4] */
/* @0xdc854 cmp r5, #0 */
/* @0xdc858 beq 0xdcea0 <_Z5DoAddjPhPKhP6VMExec+0x97c> */
/* @0xdc85c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdc860 cmp r6, #0 */
/* @0xdc864 moveq r12, #1 */
/* @0xdc868 beq 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdc86c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdc870 ldr r5, [r6, #0x4] */
/* @0xdc874 sub r5, r5, #1 */
/* @0xdc878 str r5, [r6, #0x4] */
/* @0xdc87c cmp r5, #0 */
/* @0xdc880 beq 0xdcef8 <_Z5DoAddjPhPKhP6VMExec+0x9d4> */
/* @0xdc884 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdc888 mov r12, #1 */
/* @0xdc88c b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdc890 sub r4, r8, #16 */
/* @0xdc894 mov r5, r4 */
/* @0xdc898 mov r8, r4 */
/* @0xdc89c b 0xdc76c <_Z5DoAddjPhPKhP6VMExec+0x248> */
/* @0xdc8a0 sub r8, r8, #8 */
/* @0xdc8a4 mov r4, #0 */
/* @0xdc8a8 mov r5, r8 */
/* @0xdc8ac b 0xdc76c <_Z5DoAddjPhPKhP6VMExec+0x248> */
/* @0xdc8b0 cmp r6, #2 */
/* @0xdc8b4 beq 0xdcce8 <_Z5DoAddjPhPKhP6VMExec+0x7c4> */
/* @0xdc8b8 bls 0xdc9d8 <_Z5DoAddjPhPKhP6VMExec+0x4b4> */
/* @0xdc8bc cmp r6, #3 */
/* @0xdc8c0 beq 0xdcd6c <_Z5DoAddjPhPKhP6VMExec+0x848> */
/* @0xdc8c4 cmp r6, #32 */
/* @0xdc8c8 bne 0xdcd54 <_Z5DoAddjPhPKhP6VMExec+0x830> */
/* @0xdc8cc vldr s14, [r7] */
/* @0xdc8d0 vcvt.f64.s32 d7, s14 */
/* @0xdc8d4 vldr d6, [r10] */
/* @0xdc8d8 mov r12, #0 */
/* @0xdc8dc vadd.f64 d7, d7, d6 */
/* @0xdc8e0 vstr d7, [r5] */
/* @0xdc8e4 cmp r4, #0 */
/* @0xdc8e8 strne r12, [r4, #0xc] */
/* @0xdc8ec mov r0, r8 */
/* @0xdc8f0 add sp, sp, #124 */
/* @0xdc8f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdc8f8 ldr r2, [r7, #0xc] */
/* @0xdc8fc cmp r2, #13 */
/* @0xdc900 addls pc, pc, r2, lsl #2 */
/* @0xdc904 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc908 b 0xdce98 <_Z5DoAddjPhPKhP6VMExec+0x974> */
/* @0xdc90c b 0xdce8c <_Z5DoAddjPhPKhP6VMExec+0x968> */
/* @0xdc910 b 0xdce70 <_Z5DoAddjPhPKhP6VMExec+0x94c> */
/* @0xdc914 b 0xdce54 <_Z5DoAddjPhPKhP6VMExec+0x930> */
/* @0xdc918 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc91c b 0xdce38 <_Z5DoAddjPhPKhP6VMExec+0x914> */
/* @0xdc920 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc924 b 0xdce2c <_Z5DoAddjPhPKhP6VMExec+0x908> */
/* @0xdc928 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc92c b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc930 b 0xdce1c <_Z5DoAddjPhPKhP6VMExec+0x8f8> */
/* @0xdc934 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc938 b 0xdcf78 <_Z5DoAddjPhPKhP6VMExec+0xa54> */
/* @0xdc93c b 0xdce98 <_Z5DoAddjPhPKhP6VMExec+0x974> */
/* @0xdc940 add r8, r7, #8 */
/* @0xdc944 b 0xdc5b8 <_Z5DoAddjPhPKhP6VMExec+0x94> */
/* @0xdc948 add r7, r10, #8 */
/* @0xdc94c mov r6, r9 */
/* @0xdc950 b 0xdc588 <_Z5DoAddjPhPKhP6VMExec+0x64> */
/* @0xdc954 ldr r2, [r10, #0xc] */
/* @0xdc958 cmp r2, #13 */
/* @0xdc95c addls pc, pc, r2, lsl #2 */
/* @0xdc960 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc964 b 0xdce14 <_Z5DoAddjPhPKhP6VMExec+0x8f0> */
/* @0xdc968 b 0xdcdfc <_Z5DoAddjPhPKhP6VMExec+0x8d8> */
/* @0xdc96c b 0xdcddc <_Z5DoAddjPhPKhP6VMExec+0x8b8> */
/* @0xdc970 b 0xdcdbc <_Z5DoAddjPhPKhP6VMExec+0x898> */
/* @0xdc974 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc978 b 0xdcd9c <_Z5DoAddjPhPKhP6VMExec+0x878> */
/* @0xdc97c b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc980 b 0xdce08 <_Z5DoAddjPhPKhP6VMExec+0x8e4> */
/* @0xdc984 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc988 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc98c b 0xdcd8c <_Z5DoAddjPhPKhP6VMExec+0x868> */
/* @0xdc990 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc994 b 0xdcf94 <_Z5DoAddjPhPKhP6VMExec+0xa70> */
/* @0xdc998 b 0xdce14 <_Z5DoAddjPhPKhP6VMExec+0x8f0> */
/* @0xdc99c cmp r6, #35 */
/* @0xdc9a0 beq 0xdcccc <_Z5DoAddjPhPKhP6VMExec+0x7a8> */
/* @0xdc9a4 cmp r6, #48 */
/* @0xdc9a8 bne 0xdcd54 <_Z5DoAddjPhPKhP6VMExec+0x830> */
/* @0xdc9ac ldrd r0, r1, [r7] */
/* @0xdc9b0 bl 0x319164 <__floatdidf> */
/* @0xdc9b4 vldr d7, [r10] */
/* @0xdc9b8 mov r12, #0 */
/* @0xdc9bc vmov d6, r0, r1 */
/* @0xdc9c0 vadd.f64 d7, d6, d7 */
/* @0xdc9c4 vstr d7, [r5] */
/* @0xdc9c8 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdc9cc mov r5, #0 */
/* @0xdc9d0 mov r4, r5 */
/* @0xdc9d4 b 0xdc76c <_Z5DoAddjPhPKhP6VMExec+0x248> */
/* @0xdc9d8 cmp r6, #0 */
/* @0xdc9dc bne 0xdcd54 <_Z5DoAddjPhPKhP6VMExec+0x830> */
/* @0xdc9e0 vldr d6, [r7] */
/* @0xdc9e4 vldr d7, [r10] */
/* @0xdc9e8 vadd.f64 d7, d6, d7 */
/* @0xdc9ec mov r12, r6 */
/* @0xdc9f0 vstr d7, [r5] */
/* @0xdc9f4 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdc9f8 add r7, sp, #40 */
/* @0xdc9fc mov r2, r1 */
/* @0xdca00 and r1, r9, #15 */
/* @0xdca04 mov r3, #0 */
/* @0xdca08 mov r0, r7 */
/* @0xdca0c mvn r6, #-16777216 */
/* @0xdca10 str r3, [sp, #0x20] */
/* @0xdca14 mov r10, #0 */
/* @0xdca18 str r3, [sp, #0x30] */
/* @0xdca1c mov r11, #0 */
/* @0xdca20 str r3, [sp, #0x4] */
/* @0xdca24 add r5, sp, #24 */
/* @0xdca28 strd r10, r11, [sp, #24] */
/* @0xdca2c strd r10, r11, [sp, #40] */
/* @0xdca30 str r6, [sp, #0x24] */
/* @0xdca34 str r6, [sp, #0x34] */
/* @0xdca38 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdca3c lsr r1, r9, #4 */
/* @0xdca40 mov r2, r0 */
/* @0xdca44 mov r0, r5 */
/* @0xdca48 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdca4c ldr r2, [sp, #0x24] */
/* @0xdca50 ldr r3, [sp, #0x4] */
/* @0xdca54 and r2, r2, r6 */
/* @0xdca58 cmp r2, r6 */
/* @0xdca5c mov r8, r0 */
/* @0xdca60 beq 0xdd064 <_Z5DoAddjPhPKhP6VMExec+0xb40> */
/* @0xdca64 ldr r2, [sp, #0x34] */
/* @0xdca68 bic r2, r2, #-16777216 */
/* @0xdca6c cmp r2, r6 */
/* @0xdca70 beq 0xdcf50 <_Z5DoAddjPhPKhP6VMExec+0xa2c> */
/* @0xdca74 add r4, sp, #56 */
/* @0xdca78 mov r2, r3 */
/* @0xdca7c mov r1, r5 */
/* @0xdca80 strd r10, r11, [sp, #56] */
/* @0xdca84 mov r0, r4 */
/* @0xdca88 str r3, [sp, #0x40] */
/* @0xdca8c str r6, [sp, #0x44] */
/* @0xdca90 strd r10, r11, [sp, #72] */
/* @0xdca94 str r3, [sp, #0x50] */
/* @0xdca98 str r6, [sp, #0x54] */
/* @0xdca9c bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0xdcaa0 cmp r0, #1 */
/* @0xdcaa4 beq 0xdd15c <_Z5DoAddjPhPKhP6VMExec+0xc38> */
/* @0xdcaa8 cmp r0, #0 */
/* @0xdcaac beq 0xdcfb4 <_Z5DoAddjPhPKhP6VMExec+0xa90> */
/* @0xdcab0 ldr r3, [sp, #0x24] */
/* @0xdcab4 sub r3, r3, #1 */
/* @0xdcab8 bic r3, r3, #-16777216 */
/* @0xdcabc bic r3, r3, #3 */
/* @0xdcac0 cmp r3, #0 */
/* @0xdcac4 beq 0xdd084 <_Z5DoAddjPhPKhP6VMExec+0xb60> */
/* @0xdcac8 ldr r1, [sp, #0x34] */
/* @0xdcacc mov r3, #0 */
/* @0xdcad0 str r3, [sp, #0x20] */
/* @0xdcad4 mov r2, #5 */
/* @0xdcad8 sub r1, r1, #1 */
/* @0xdcadc str r3, [sp, #0x18] */
/* @0xdcae0 bic r3, r1, #-16777216 */
/* @0xdcae4 str r2, [sp, #0x24] */
/* @0xdcae8 bic r3, r3, #3 */
/* @0xdcaec cmp r3, #0 */
/* @0xdcaf0 beq 0xdd078 <_Z5DoAddjPhPKhP6VMExec+0xb54> */
/* @0xdcaf4 ldr r1, [sp, #0x44] */
/* @0xdcaf8 mov r3, #0 */
/* @0xdcafc str r3, [sp, #0x30] */
/* @0xdcb00 mov r2, #5 */
/* @0xdcb04 sub r1, r1, #1 */
/* @0xdcb08 str r3, [sp, #0x28] */
/* @0xdcb0c bic r3, r1, #-16777216 */
/* @0xdcb10 str r2, [sp, #0x34] */
/* @0xdcb14 bic r3, r3, #3 */
/* @0xdcb18 cmp r3, #0 */
/* @0xdcb1c bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdcb20 mov r0, r4 */
/* @0xdcb24 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdcb28 mov r0, r8 */
/* @0xdcb2c b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdcb30 add r6, sp, #72 */
/* @0xdcb34 mov r2, r1 */
/* @0xdcb38 and r1, r9, #15 */
/* @0xdcb3c mvn r5, #-16777216 */
/* @0xdcb40 mov r0, r6 */
/* @0xdcb44 mov r10, #0 */
/* @0xdcb48 mov r11, #0 */
/* @0xdcb4c mov r7, #0 */
/* @0xdcb50 strd r10, r11, [sp, #56] */
/* @0xdcb54 add r4, sp, #56 */
/* @0xdcb58 strd r10, r11, [sp, #72] */
/* @0xdcb5c str r7, [sp, #0x40] */
/* @0xdcb60 str r7, [sp, #0x50] */
/* @0xdcb64 str r5, [sp, #0x44] */
/* @0xdcb68 str r5, [sp, #0x54] */
/* @0xdcb6c bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdcb70 lsr r1, r9, #4 */
/* @0xdcb74 mov r2, r0 */
/* @0xdcb78 mov r0, r4 */
/* @0xdcb7c bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdcb80 ldr r3, [sp, #0x44] */
/* @0xdcb84 and r3, r3, r5 */
/* @0xdcb88 cmp r3, r5 */
/* @0xdcb8c mov r8, r0 */
/* @0xdcb90 beq 0xdd090 <_Z5DoAddjPhPKhP6VMExec+0xb6c> */
/* @0xdcb94 ldr r3, [sp, #0x54] */
/* @0xdcb98 bic r3, r3, #-16777216 */
/* @0xdcb9c cmp r3, r5 */
/* @0xdcba0 beq 0xdcf64 <_Z5DoAddjPhPKhP6VMExec+0xa40> */
/* @0xdcba4 add r9, sp, #88 */
/* @0xdcba8 mov r1, r4 */
/* @0xdcbac strd r10, r11, [sp, #88] */
/* @0xdcbb0 mov r0, r9 */
/* @0xdcbb4 str r7, [sp, #0x60] */
/* @0xdcbb8 str r5, [sp, #0x64] */
/* @0xdcbbc strd r10, r11, [sp, #104] */
/* @0xdcbc0 str r7, [sp, #0x70] */
/* @0xdcbc4 str r5, [sp, #0x74] */
/* @0xdcbc8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdcbcc cmp r0, #1 */
/* @0xdcbd0 beq 0xdd16c <_Z5DoAddjPhPKhP6VMExec+0xc48> */
/* @0xdcbd4 cmp r0, #0 */
/* @0xdcbd8 bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdcbdc add r10, sp, #104 */
/* @0xdcbe0 mov r1, r6 */
/* @0xdcbe4 mov r0, r10 */
/* @0xdcbe8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdcbec cmp r0, #1 */
/* @0xdcbf0 beq 0xdd3b0 <_Z5DoAddjPhPKhP6VMExec+0xe8c> */
/* @0xdcbf4 cmp r0, #0 */
/* @0xdcbf8 bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdcbfc str r0, [r8, #-0x4] */
/* @0xdcc00 sub r5, r8, #16 */
/* @0xdcc04 vldr d6, [sp, #88] */
/* @0xdcc08 vldr d7, [sp, #104] */
/* @0xdcc0c vadd.f64 d5, d6, d7 */
/* @0xdcc10 ldr r1, [sp, #0x44] */
/* @0xdcc14 sub r1, r1, #1 */
/* @0xdcc18 bic r1, r1, #-16777216 */
/* @0xdcc1c bic r1, r1, #3 */
/* @0xdcc20 cmp r1, #0 */
/* @0xdcc24 vmov r2, r3, d5 */
/* @0xdcc28 vstr s10, [r8, #-16] */
/* @0xdcc2c str r3, [r8, #-0xc] */
/* @0xdcc30 beq 0xdd398 <_Z5DoAddjPhPKhP6VMExec+0xe74> */
/* @0xdcc34 ldr r1, [sp, #0x54] */
/* @0xdcc38 mov r3, #0 */
/* @0xdcc3c str r3, [sp, #0x40] */
/* @0xdcc40 mov r2, #5 */
/* @0xdcc44 sub r1, r1, #1 */
/* @0xdcc48 str r3, [sp, #0x38] */
/* @0xdcc4c bic r3, r1, #-16777216 */
/* @0xdcc50 str r2, [sp, #0x44] */
/* @0xdcc54 bic r3, r3, #3 */
/* @0xdcc58 cmp r3, #0 */
/* @0xdcc5c beq 0xdd38c <_Z5DoAddjPhPKhP6VMExec+0xe68> */
/* @0xdcc60 ldr r1, [sp, #0x64] */
/* @0xdcc64 mov r3, #0 */
/* @0xdcc68 str r3, [sp, #0x50] */
/* @0xdcc6c mov r2, #5 */
/* @0xdcc70 sub r1, r1, #1 */
/* @0xdcc74 str r3, [sp, #0x48] */
/* @0xdcc78 bic r3, r1, #-16777216 */
/* @0xdcc7c str r2, [sp, #0x54] */
/* @0xdcc80 bic r3, r3, #3 */
/* @0xdcc84 cmp r3, #0 */
/* @0xdcc88 beq 0xdd3a4 <_Z5DoAddjPhPKhP6VMExec+0xe80> */
/* @0xdcc8c ldr r1, [sp, #0x74] */
/* @0xdcc90 mov r3, #0 */
/* @0xdcc94 str r3, [sp, #0x60] */
/* @0xdcc98 mov r2, #5 */
/* @0xdcc9c sub r1, r1, #1 */
/* @0xdcca0 str r3, [sp, #0x58] */
/* @0xdcca4 bic r3, r1, #-16777216 */
/* @0xdcca8 str r2, [sp, #0x64] */
/* @0xdccac bic r3, r3, #3 */
/* @0xdccb0 cmp r3, #0 */
/* @0xdccb4 movne r0, r5 */
/* @0xdccb8 bne 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdccbc mov r0, r10 */
/* @0xdccc0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdccc4 mov r0, r5 */
/* @0xdccc8 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdcccc ldr r1, [r7] */
/* @0xdccd0 mov r12, #10 */
/* @0xdccd4 ldrd r2, r3, [r10] */
/* @0xdccd8 adds r2, r2, r1 */
/* @0xdccdc adc r3, r3, r1, asr #31 */
/* @0xdcce0 strd r2, r3, [r5] */
/* @0xdcce4 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcce8 vldr s14, [r10] */
/* @0xdccec vcvt.f64.s32 d7, s14 */
/* @0xdccf0 vldr d6, [r7] */
/* @0xdccf4 mov r12, #0 */
/* @0xdccf8 vadd.f64 d7, d6, d7 */
/* @0xdccfc vstr d7, [r5] */
/* @0xdcd00 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd04 ldrd r0, r1, [r7] */
/* @0xdcd08 mov r12, #10 */
/* @0xdcd0c ldrd r2, r3, [r10] */
/* @0xdcd10 adds r2, r2, r0 */
/* @0xdcd14 adc r3, r3, r1 */
/* @0xdcd18 strd r2, r3, [r5] */
/* @0xdcd1c b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd20 ldr r1, [r10] */
/* @0xdcd24 mov r12, #10 */
/* @0xdcd28 ldrd r2, r3, [r7] */
/* @0xdcd2c adds r2, r2, r1 */
/* @0xdcd30 adc r3, r3, r1, asr #31 */
/* @0xdcd34 strd r2, r3, [r5] */
/* @0xdcd38 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd3c ldr r2, [r7] */
/* @0xdcd40 mov r12, #7 */
/* @0xdcd44 ldr r3, [r10] */
/* @0xdcd48 add r3, r2, r3 */
/* @0xdcd4c str r3, [r5] */
/* @0xdcd50 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd54 ldr r1, [pc, #0x758] */
/* @0xdcd58 mov r0, r3 */
/* @0xdcd5c add r1, pc, r1 */
/* @0xdcd60 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcd64 mov r12, #0 */
/* @0xdcd68 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd6c ldrd r0, r1, [r10] */
/* @0xdcd70 bl 0x319164 <__floatdidf> */
/* @0xdcd74 vldr d7, [r7] */
/* @0xdcd78 mov r12, #0 */
/* @0xdcd7c vmov d5, r0, r1 */
/* @0xdcd80 vadd.f64 d7, d7, d5 */
/* @0xdcd84 vstr d7, [r5] */
/* @0xdcd88 b 0xdc8e4 <_Z5DoAddjPhPKhP6VMExec+0x3c0> */
/* @0xdcd8c and r0, r0, #240 */
/* @0xdcd90 orr r6, r0, #3 */
/* @0xdcd94 add r7, r10, #16 */
/* @0xdcd98 b 0xdc588 <_Z5DoAddjPhPKhP6VMExec+0x64> */
/* @0xdcd9c ldr r1, [pc, #0x714] */
/* @0xdcda0 mov r0, r3 */
/* @0xdcda4 str r3, [sp, #0x4] */
/* @0xdcda8 mov r6, r9 */
/* @0xdcdac add r1, pc, r1 */
/* @0xdcdb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcdb4 ldr r3, [sp, #0x4] */
/* @0xdcdb8 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdcdbc ldr r1, [pc, #0x6f8] */
/* @0xdcdc0 mov r0, r3 */
/* @0xdcdc4 str r3, [sp, #0x4] */
/* @0xdcdc8 mov r6, r9 */
/* @0xdcdcc add r1, pc, r1 */
/* @0xdcdd0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcdd4 ldr r3, [sp, #0x4] */
/* @0xdcdd8 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdcddc ldr r1, [pc, #0x6dc] */
/* @0xdcde0 mov r0, r3 */
/* @0xdcde4 str r3, [sp, #0x4] */
/* @0xdcde8 mov r6, r9 */
/* @0xdcdec add r1, pc, r1 */
/* @0xdcdf0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcdf4 ldr r3, [sp, #0x4] */
/* @0xdcdf8 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdcdfc and r0, r0, #240 */
/* @0xdce00 orr r6, r0, #6 */
/* @0xdce04 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdce08 and r0, r0, #240 */
/* @0xdce0c orr r6, r0, #2 */
/* @0xdce10 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdce14 and r6, r9, #240 */
/* @0xdce18 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdce1c and r6, r6, #15 */
/* @0xdce20 orr r6, r6, #48 */
/* @0xdce24 add r8, r7, #16 */
/* @0xdce28 b 0xdc5b8 <_Z5DoAddjPhPKhP6VMExec+0x94> */
/* @0xdce2c and r6, r6, #15 */
/* @0xdce30 orr r6, r6, #32 */
/* @0xdce34 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce38 ldr r1, [pc, #0x684] */
/* @0xdce3c mov r0, r3 */
/* @0xdce40 str r3, [sp, #0x4] */
/* @0xdce44 add r1, pc, r1 */
/* @0xdce48 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdce4c ldr r3, [sp, #0x4] */
/* @0xdce50 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce54 ldr r1, [pc, #0x66c] */
/* @0xdce58 mov r0, r3 */
/* @0xdce5c str r3, [sp, #0x4] */
/* @0xdce60 add r1, pc, r1 */
/* @0xdce64 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdce68 ldr r3, [sp, #0x4] */
/* @0xdce6c b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce70 ldr r1, [pc, #0x654] */
/* @0xdce74 mov r0, r3 */
/* @0xdce78 str r3, [sp, #0x4] */
/* @0xdce7c add r1, pc, r1 */
/* @0xdce80 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdce84 ldr r3, [sp, #0x4] */
/* @0xdce88 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce8c and r6, r6, #15 */
/* @0xdce90 orr r6, r6, #96 */
/* @0xdce94 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdce98 and r6, r6, #15 */
/* @0xdce9c b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdcea0 ldr r0, [r9] */
/* @0xdcea4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdcea8 str r5, [r9] */
/* @0xdceac str r5, [r9, #0x8] */
/* @0xdceb0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdceb4 ldr r5, [r9, #0x4] */
/* @0xdceb8 sub r5, r5, #1 */
/* @0xdcebc str r5, [r9, #0x4] */
/* @0xdcec0 cmp r5, #0 */
/* @0xdcec4 bne 0xdcee8 <_Z5DoAddjPhPKhP6VMExec+0x9c4> */
/* @0xdcec8 ldr r0, [r9] */
/* @0xdcecc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdced0 mov r0, r9 */
/* @0xdced4 str r5, [r9] */
/* @0xdced8 str r5, [r9, #0x8] */
/* @0xdcedc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xdcee0 mov r0, r9 */
/* @0xdcee4 bl 0x27d1d0 <_ZdlPv> */
/* @0xdcee8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdceec mov r0, r9 */
/* @0xdcef0 bl 0x27d1d0 <_ZdlPv> */
/* @0xdcef4 b 0xdc85c <_Z5DoAddjPhPKhP6VMExec+0x338> */
/* @0xdcef8 ldr r0, [r6] */
/* @0xdcefc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdcf00 str r5, [r6] */
/* @0xdcf04 str r5, [r6, #0x8] */
/* @0xdcf08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xdcf0c ldr r5, [r6, #0x4] */
/* @0xdcf10 sub r5, r5, #1 */
/* @0xdcf14 str r5, [r6, #0x4] */
/* @0xdcf18 cmp r5, #0 */
/* @0xdcf1c bne 0xdcf40 <_Z5DoAddjPhPKhP6VMExec+0xa1c> */
/* @0xdcf20 ldr r0, [r6] */
/* @0xdcf24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdcf28 mov r0, r6 */
/* @0xdcf2c str r5, [r6] */
/* @0xdcf30 str r5, [r6, #0x8] */
/* @0xdcf34 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xdcf38 mov r0, r6 */
/* @0xdcf3c bl 0x27d1d0 <_ZdlPv> */
/* @0xdcf40 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xdcf44 mov r0, r6 */
/* @0xdcf48 bl 0x27d1d0 <_ZdlPv> */
/* @0xdcf4c b 0xdc884 <_Z5DoAddjPhPKhP6VMExec+0x360> */
/* @0xdcf50 ldr r0, [pc, #0x578] */
/* @0xdcf54 add r0, pc, r0 */
/* @0xdcf58 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdcf5c mov r0, r8 */
/* @0xdcf60 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdcf64 ldr r0, [pc, #0x568] */
/* @0xdcf68 add r0, pc, r0 */
/* @0xdcf6c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdcf70 mov r0, r8 */
/* @0xdcf74 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdcf78 ldr r1, [pc, #0x558] */
/* @0xdcf7c mov r0, r3 */
/* @0xdcf80 str r3, [sp, #0x4] */
/* @0xdcf84 add r1, pc, r1 */
/* @0xdcf88 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcf8c ldr r3, [sp, #0x4] */
/* @0xdcf90 b 0xdce24 <_Z5DoAddjPhPKhP6VMExec+0x900> */
/* @0xdcf94 ldr r1, [pc, #0x540] */
/* @0xdcf98 mov r0, r3 */
/* @0xdcf9c str r3, [sp, #0x4] */
/* @0xdcfa0 mov r6, r9 */
/* @0xdcfa4 add r1, pc, r1 */
/* @0xdcfa8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdcfac ldr r3, [sp, #0x4] */
/* @0xdcfb0 b 0xdcd94 <_Z5DoAddjPhPKhP6VMExec+0x870> */
/* @0xdcfb4 add r6, sp, #72 */
/* @0xdcfb8 mov r2, r0 */
/* @0xdcfbc mov r1, r7 */
/* @0xdcfc0 mov r0, r6 */
/* @0xdcfc4 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0xdcfc8 cmp r0, #1 */
/* @0xdcfcc beq 0xdd0a4 <_Z5DoAddjPhPKhP6VMExec+0xb80> */
/* @0xdcfd0 cmp r0, #0 */
/* @0xdcfd4 bne 0xdd0b0 <_Z5DoAddjPhPKhP6VMExec+0xb8c> */
/* @0xdcfd8 ldr r3, [sp, #0x44] */
/* @0xdcfdc bic r3, r3, #-16777216 */
/* @0xdcfe0 cmp r3, #1 */
/* @0xdcfe4 beq 0xdd180 <_Z5DoAddjPhPKhP6VMExec+0xc5c> */
/* @0xdcfe8 ldr r3, [sp, #0x54] */
/* @0xdcfec bic r3, r3, #-16777216 */
/* @0xdcff0 cmp r3, #1 */
/* @0xdcff4 beq 0xdd180 <_Z5DoAddjPhPKhP6VMExec+0xc5c> */
/* @0xdcff8 add r9, sp, #88 */
/* @0xdcffc mov r1, r4 */
/* @0xdd000 mov r2, #0 */
/* @0xdd004 mov r3, #0 */
/* @0xdd008 mov r0, r9 */
/* @0xdd00c mov r12, #0 */
/* @0xdd010 strd r2, r3, [sp, #88] */
/* @0xdd014 strd r2, r3, [sp, #104] */
/* @0xdd018 mvn r3, #-16777216 */
/* @0xdd01c str r12, [sp, #0x60] */
/* @0xdd020 str r12, [sp, #0x70] */
/* @0xdd024 str r3, [sp, #0x64] */
/* @0xdd028 str r3, [sp, #0x74] */
/* @0xdd02c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdd030 cmp r0, #1 */
/* @0xdd034 beq 0xdd480 <_Z5DoAddjPhPKhP6VMExec+0xf5c> */
/* @0xdd038 cmp r0, #0 */
/* @0xdd03c beq 0xdd418 <_Z5DoAddjPhPKhP6VMExec+0xef4> */
/* @0xdd040 ldr r3, [sp, #0x44] */
/* @0xdd044 sub r3, r3, #1 */
/* @0xdd048 bic r3, r3, #-16777216 */
/* @0xdd04c bic r3, r3, #3 */
/* @0xdd050 cmp r3, #0 */
/* @0xdd054 bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdd058 mov r0, r4 */
/* @0xdd05c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd060 b 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdd064 ldr r0, [pc, #0x474] */
/* @0xdd068 add r0, pc, r0 */
/* @0xdd06c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdd070 mov r0, r8 */
/* @0xdd074 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd078 mov r0, r7 */
/* @0xdd07c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd080 b 0xdcaf4 <_Z5DoAddjPhPKhP6VMExec+0x5d0> */
/* @0xdd084 mov r0, r5 */
/* @0xdd088 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd08c b 0xdcac8 <_Z5DoAddjPhPKhP6VMExec+0x5a4> */
/* @0xdd090 ldr r0, [pc, #0x44c] */
/* @0xdd094 add r0, pc, r0 */
/* @0xdd098 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdd09c mov r0, r8 */
/* @0xdd0a0 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd0a4 ldr r0, [pc, #0x43c] */
/* @0xdd0a8 add r0, pc, r0 */
/* @0xdd0ac bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd0b0 ldr r3, [sp, #0x24] */
/* @0xdd0b4 sub r3, r3, #1 */
/* @0xdd0b8 bic r3, r3, #-16777216 */
/* @0xdd0bc bic r3, r3, #3 */
/* @0xdd0c0 cmp r3, #0 */
/* @0xdd0c4 beq 0xdd3dc <_Z5DoAddjPhPKhP6VMExec+0xeb8> */
/* @0xdd0c8 ldr r1, [sp, #0x34] */
/* @0xdd0cc mov r3, #0 */
/* @0xdd0d0 str r3, [sp, #0x20] */
/* @0xdd0d4 mov r2, #5 */
/* @0xdd0d8 sub r1, r1, #1 */
/* @0xdd0dc str r3, [sp, #0x18] */
/* @0xdd0e0 bic r3, r1, #-16777216 */
/* @0xdd0e4 str r2, [sp, #0x24] */
/* @0xdd0e8 bic r3, r3, #3 */
/* @0xdd0ec cmp r3, #0 */
/* @0xdd0f0 beq 0xdd3d0 <_Z5DoAddjPhPKhP6VMExec+0xeac> */
/* @0xdd0f4 ldr r1, [sp, #0x44] */
/* @0xdd0f8 mov r3, #0 */
/* @0xdd0fc str r3, [sp, #0x30] */
/* @0xdd100 mov r2, #5 */
/* @0xdd104 sub r1, r1, #1 */
/* @0xdd108 str r3, [sp, #0x28] */
/* @0xdd10c bic r3, r1, #-16777216 */
/* @0xdd110 str r2, [sp, #0x34] */
/* @0xdd114 bic r3, r3, #3 */
/* @0xdd118 cmp r3, #0 */
/* @0xdd11c beq 0xdd3c4 <_Z5DoAddjPhPKhP6VMExec+0xea0> */
/* @0xdd120 ldr r1, [sp, #0x54] */
/* @0xdd124 mov r3, #0 */
/* @0xdd128 str r3, [sp, #0x40] */
/* @0xdd12c mov r2, #5 */
/* @0xdd130 sub r1, r1, #1 */
/* @0xdd134 str r3, [sp, #0x38] */
/* @0xdd138 bic r3, r1, #-16777216 */
/* @0xdd13c str r2, [sp, #0x44] */
/* @0xdd140 bic r3, r3, #3 */
/* @0xdd144 cmp r3, #0 */
/* @0xdd148 bne 0xdc8ec <_Z5DoAddjPhPKhP6VMExec+0x3c8> */
/* @0xdd14c mov r0, r6 */
/* @0xdd150 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd154 mov r0, r8 */
/* @0xdd158 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd15c ldr r0, [pc, #0x388] */
/* @0xdd160 add r0, pc, r0 */
/* @0xdd164 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd168 b 0xdcab0 <_Z5DoAddjPhPKhP6VMExec+0x58c> */
/* @0xdd16c ldr r0, [pc, #0x37c] */
/* @0xdd170 add r0, pc, r0 */
/* @0xdd174 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd178 mov r0, r8 */
/* @0xdd17c b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd180 add r9, sp, #88 */
/* @0xdd184 add r10, sp, #104 */
/* @0xdd188 mov r1, r4 */
/* @0xdd18c mov r2, #0 */
/* @0xdd190 mov r0, r9 */
/* @0xdd194 mov r3, #0 */
/* @0xdd198 strd r2, r3, [sp, #88] */
/* @0xdd19c strd r2, r3, [sp, #104] */
/* @0xdd1a0 mvn r3, #-16777216 */
/* @0xdd1a4 mov r2, #0 */
/* @0xdd1a8 str r3, [sp, #0x64] */
/* @0xdd1ac str r3, [sp, #0x74] */
/* @0xdd1b0 str r2, [sp, #0x60] */
/* @0xdd1b4 str r2, [sp, #0x70] */
/* @0xdd1b8 sub r2, r8, #16 */
/* @0xdd1bc str r2, [sp, #0x14] */
/* @0xdd1c0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xdd1c4 mov r1, r6 */
/* @0xdd1c8 mov r0, r10 */
/* @0xdd1cc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xdd1d0 ldr r2, [sp, #0x68] */
/* @0xdd1d4 mov r1, #1 */
/* @0xdd1d8 ldr r3, [sp, #0x58] */
/* @0xdd1dc cmp r2, #0 */
/* @0xdd1e0 str r1, [r8, #-0x4] */
/* @0xdd1e4 streq r2, [sp, #0xc] */
/* @0xdd1e8 ldrne r1, [r2] */
/* @0xdd1ec strne r1, [sp, #0xc] */
/* @0xdd1f0 cmp r3, #0 */
/* @0xdd1f4 mov r0, #12 */
/* @0xdd1f8 ldrne r1, [r3] */
/* @0xdd1fc moveq r1, r3 */
/* @0xdd200 cmp r2, #0 */
/* @0xdd204 ldrne r2, [r2, #0x8] */
/* @0xdd208 cmp r3, #0 */
/* @0xdd20c ldrne r3, [r3, #0x8] */
/* @0xdd210 str r1, [sp, #0x4] */
/* @0xdd214 str r3, [sp, #0x10] */
/* @0xdd218 ldr r3, [sp, #0x10] */
/* @0xdd21c add r2, r3, r2 */
/* @0xdd220 str r2, [sp, #0x8] */
/* @0xdd224 bl 0x27c524 <_Znwj> */
/* @0xdd228 ldr r2, [sp, #0x8] */
/* @0xdd22c mov r11, r0 */
/* @0xdd230 add r0, r2, #1 */
/* @0xdd234 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdd238 ldr r1, [sp, #0x4] */
/* @0xdd23c ldr r3, [sp, #0x8] */
/* @0xdd240 mov r12, #1 */
/* @0xdd244 cmp r1, #0 */
/* @0xdd248 str r3, [r11, #0x8] */
/* @0xdd24c mov r2, r0 */
/* @0xdd250 stm r11, {r2, r12} */
/* @0xdd254 beq 0xdd264 <_Z5DoAddjPhPKhP6VMExec+0xd40> */
/* @0xdd258 str r0, [sp, #0x4] */
/* @0xdd25c bl 0xb65a4 <strcpy@plt> */
/* @0xdd260 ldr r2, [sp, #0x4] */
/* @0xdd264 ldr r3, [sp, #0xc] */
/* @0xdd268 cmp r3, #0 */
/* @0xdd26c beq 0xdd288 <_Z5DoAddjPhPKhP6VMExec+0xd64> */
/* @0xdd270 ldr r3, [sp, #0x10] */
/* @0xdd274 ldr r1, [sp, #0xc] */
/* @0xdd278 add r0, r2, r3 */
/* @0xdd27c str r2, [sp, #0x4] */
/* @0xdd280 bl 0xb65a4 <strcpy@plt> */
/* @0xdd284 ldr r2, [sp, #0x4] */
/* @0xdd288 ldr r3, [sp, #0x8] */
/* @0xdd28c mov r1, #0 */
/* @0xdd290 strb r1, [r2, r3] */
/* @0xdd294 ldr r2, [sp, #0x64] */
/* @0xdd298 str r11, [r8, #-0x10] */
/* @0xdd29c sub r3, r2, #1 */
/* @0xdd2a0 bic r3, r3, #-16777216 */
/* @0xdd2a4 bic r3, r3, #3 */
/* @0xdd2a8 cmp r3, r1 */
/* @0xdd2ac beq 0xdd474 <_Z5DoAddjPhPKhP6VMExec+0xf50> */
/* @0xdd2b0 ldr r1, [sp, #0x74] */
/* @0xdd2b4 mov r3, #0 */
/* @0xdd2b8 str r3, [sp, #0x60] */
/* @0xdd2bc mov r2, #5 */
/* @0xdd2c0 sub r1, r1, #1 */
/* @0xdd2c4 str r3, [sp, #0x58] */
/* @0xdd2c8 bic r3, r1, #-16777216 */
/* @0xdd2cc str r2, [sp, #0x64] */
/* @0xdd2d0 bic r3, r3, #3 */
/* @0xdd2d4 cmp r3, #0 */
/* @0xdd2d8 beq 0xdd40c <_Z5DoAddjPhPKhP6VMExec+0xee8> */
/* @0xdd2dc ldr r3, [sp, #0x24] */
/* @0xdd2e0 sub r3, r3, #1 */
/* @0xdd2e4 bic r3, r3, #-16777216 */
/* @0xdd2e8 bic r3, r3, #3 */
/* @0xdd2ec cmp r3, #0 */
/* @0xdd2f0 beq 0xdd400 <_Z5DoAddjPhPKhP6VMExec+0xedc> */
/* @0xdd2f4 ldr r1, [sp, #0x34] */
/* @0xdd2f8 mov r3, #0 */
/* @0xdd2fc str r3, [sp, #0x20] */
/* @0xdd300 mov r2, #5 */
/* @0xdd304 sub r1, r1, #1 */
/* @0xdd308 str r3, [sp, #0x18] */
/* @0xdd30c bic r3, r1, #-16777216 */
/* @0xdd310 str r2, [sp, #0x24] */
/* @0xdd314 bic r3, r3, #3 */
/* @0xdd318 cmp r3, #0 */
/* @0xdd31c beq 0xdd3f4 <_Z5DoAddjPhPKhP6VMExec+0xed0> */
/* @0xdd320 ldr r1, [sp, #0x44] */
/* @0xdd324 mov r3, #0 */
/* @0xdd328 str r3, [sp, #0x30] */
/* @0xdd32c mov r2, #5 */
/* @0xdd330 sub r1, r1, #1 */
/* @0xdd334 str r3, [sp, #0x28] */
/* @0xdd338 bic r3, r1, #-16777216 */
/* @0xdd33c str r2, [sp, #0x34] */
/* @0xdd340 bic r3, r3, #3 */
/* @0xdd344 cmp r3, #0 */
/* @0xdd348 beq 0xdd3e8 <_Z5DoAddjPhPKhP6VMExec+0xec4> */
/* @0xdd34c ldr r1, [sp, #0x54] */
/* @0xdd350 mov r3, #0 */
/* @0xdd354 str r3, [sp, #0x40] */
/* @0xdd358 mov r2, #5 */
/* @0xdd35c sub r1, r1, #1 */
/* @0xdd360 str r3, [sp, #0x38] */
/* @0xdd364 bic r3, r1, #-16777216 */
/* @0xdd368 str r2, [sp, #0x44] */
/* @0xdd36c bic r3, r3, #3 */
/* @0xdd370 cmp r3, #0 */
/* @0xdd374 ldrne r0, [sp, #0x14] */
/* @0xdd378 bne 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd37c mov r0, r6 */
/* @0xdd380 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd384 ldr r0, [sp, #0x14] */
/* @0xdd388 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd38c mov r0, r6 */
/* @0xdd390 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd394 b 0xdcc60 <_Z5DoAddjPhPKhP6VMExec+0x73c> */
/* @0xdd398 mov r0, r4 */
/* @0xdd39c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3a0 b 0xdcc34 <_Z5DoAddjPhPKhP6VMExec+0x710> */
/* @0xdd3a4 mov r0, r9 */
/* @0xdd3a8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3ac b 0xdcc8c <_Z5DoAddjPhPKhP6VMExec+0x768> */
/* @0xdd3b0 ldr r0, [pc, #0x13c] */
/* @0xdd3b4 add r0, pc, r0 */
/* @0xdd3b8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd3bc mov r0, r8 */
/* @0xdd3c0 b 0xdc8f0 <_Z5DoAddjPhPKhP6VMExec+0x3cc> */
/* @0xdd3c4 mov r0, r4 */
/* @0xdd3c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3cc b 0xdd120 <_Z5DoAddjPhPKhP6VMExec+0xbfc> */
/* @0xdd3d0 mov r0, r7 */
/* @0xdd3d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3d8 b 0xdd0f4 <_Z5DoAddjPhPKhP6VMExec+0xbd0> */
/* @0xdd3dc mov r0, r5 */
/* @0xdd3e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3e4 b 0xdd0c8 <_Z5DoAddjPhPKhP6VMExec+0xba4> */
/* @0xdd3e8 mov r0, r4 */
/* @0xdd3ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3f0 b 0xdd34c <_Z5DoAddjPhPKhP6VMExec+0xe28> */
/* @0xdd3f4 mov r0, r7 */
/* @0xdd3f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd3fc b 0xdd320 <_Z5DoAddjPhPKhP6VMExec+0xdfc> */
/* @0xdd400 mov r0, r5 */
/* @0xdd404 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd408 b 0xdd2f4 <_Z5DoAddjPhPKhP6VMExec+0xdd0> */
/* @0xdd40c mov r0, r10 */
/* @0xdd410 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd414 b 0xdd2dc <_Z5DoAddjPhPKhP6VMExec+0xdb8> */
/* @0xdd418 add r10, sp, #104 */
/* @0xdd41c mov r1, r6 */
/* @0xdd420 mov r0, r10 */
/* @0xdd424 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xdd428 cmp r0, #1 */
/* @0xdd42c beq 0xdd490 <_Z5DoAddjPhPKhP6VMExec+0xf6c> */
/* @0xdd430 cmp r0, #0 */
/* @0xdd434 bne 0xdd040 <_Z5DoAddjPhPKhP6VMExec+0xb1c> */
/* @0xdd438 str r0, [r8, #-0x4] */
/* @0xdd43c sub r2, r8, #16 */
/* @0xdd440 vldr d6, [sp, #88] */
/* @0xdd444 vldr d7, [sp, #104] */
/* @0xdd448 vadd.f64 d5, d6, d7 */
/* @0xdd44c str r2, [sp, #0x14] */
/* @0xdd450 ldr r1, [sp, #0x64] */
/* @0xdd454 sub r1, r1, #1 */
/* @0xdd458 bic r1, r1, #-16777216 */
/* @0xdd45c bic r1, r1, #3 */
/* @0xdd460 cmp r1, #0 */
/* @0xdd464 vmov r2, r3, d5 */
/* @0xdd468 vstr s10, [r8, #-16] */
/* @0xdd46c str r3, [r8, #-0xc] */
/* @0xdd470 bne 0xdd2b0 <_Z5DoAddjPhPKhP6VMExec+0xd8c> */
/* @0xdd474 mov r0, r9 */
/* @0xdd478 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdd47c b 0xdd2b0 <_Z5DoAddjPhPKhP6VMExec+0xd8c> */
/* @0xdd480 ldr r0, [pc, #0x70] */
/* @0xdd484 add r0, pc, r0 */
/* @0xdd488 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd48c b 0xdd040 <_Z5DoAddjPhPKhP6VMExec+0xb1c> */
/* @0xdd490 ldr r0, [pc, #0x64] */
/* @0xdd494 add r0, pc, r0 */
/* @0xdd498 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdd49c b 0xdd040 <_Z5DoAddjPhPKhP6VMExec+0xb1c> */
/* @0xdd4a0 mov r6, r9 */
/* @0xdd4a4 mov r7, r10 */
/* @0xdd4a8 b 0xdc588 <_Z5DoAddjPhPKhP6VMExec+0x64> */
/* @0xdd4ac mov r8, r7 */
/* @0xdd4b0 b 0xdc5b8 <_Z5DoAddjPhPKhP6VMExec+0x94> */
/* @0xdd4b4 eoreq r6, r5, r12, asr r2 */
/* @0xdd4b8 eoreq r6, r5, r12, lsr r1 */
/* @0xdd4bc .word 0x002560fc */
/* @0xdd4c0 eoreq r6, r5, r8, lsl r1 */
/* @0xdd4c4 eoreq r6, r5, r12, lsl r1 */
/* @0xdd4c8 eoreq r6, r5, r0, ror #1 */
/* @0xdd4cc eoreq r6, r5, r0, lsl #2 */
/* @0xdd4d0 eoreq r5, r5, r4, ror sp */
/* @0xdd4d4 .word 0x00255eb4 */
/* @0xdd4d8 eoreq r6, r5, r4, lsl r0 */
/* @0xdd4dc eoreq r5, r5, r12, ror pc */
/* @0xdd4e0 eoreq r5, r5, r4, lsr r12 */
/* @0xdd4e4 eoreq r5, r5, r4, ror #26 */
/* @0xdd4e8 eoreq r5, r5, r12, lsl #25 */
/* @0xdd4ec mlaeq r5, r4, r11, r5 */
/* @0xdd4f0 .word 0x00255cd0 */
/* @0xdd4f4 .word 0x00255ad0 */
/* @0xdd4f8 .word 0x002558f4 */
/* @0xdd4fc eoreq r5, r5, r4, lsr #18 */
