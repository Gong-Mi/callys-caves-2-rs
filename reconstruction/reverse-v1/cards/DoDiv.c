/* cally 逆向卡：DoDiv（原版 libyoyo.so，armv7）
 * @func 0xddd68 0xde5e4  size 2172  543 条指令（含 literal 词）
 * 级别: 骨架（arg 位域 / 双格式码分派 / 9 条内核 + 整数除零检查 / 全部错误分支已证；返回值口径未定，不升正文）
 * 符号: _Z5DoDivjPhPKhP6VMExec → uchar* DoDiv(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   慢路径开关 = bits[11:8] 恰等于 1：@0xddd68 ubfx r2, r0, #0x8, #0x4 —— bits[11:8]；@0xddd70 cmp r2, #1 —— 与 1 比；@0xddd88 beq 0xde2b4 <_Z5DoDivjPhPKhP6VMExec+0x54c> —— 相等跳 0xde2b4
 *   byte=(arg>>16)&0xFF=(Afmt<<4)|Bfmt（高 nibble=A）：@0xddd6c lsr r0, r0, #16 —— arg>>16；@0xddd84 uxtb r4, r0 —— uxtb
 *   表1 按 B 的格式码定 A 的地址：B 8 字节(0/3)→A=arg2+8，4 字节(1/2/4)→A=arg2+4：@0xddd8c and r3, r4, #15 —— 取低 nibble；@0xddd94 addls pc, pc, r3, lsl #2 —— 7 项表；@0xde0d4 add r7, r1, #8 —— A=arg2+8
 *   表2 按 A 的格式码算 r6=A+4 / A+8：@0xdddd8 addls pc, pc, r3, lsl #2 —— 第二级表；@0xde0c4 add r6, r7, #4 —— r6=A+4
 *   B 从 [arg2] 读（r10=arg2 的副本）、A 从 arg2+4/arg2+8 读：@0xde144 vldr d7, [r10] —— vldr d7,[r10]=除数
 *   表3 按整字节（0..85）→ dest，逐项等价于 dest=A+size(A)−max(size(A),size(B))：@0xdde10 cmp r4, #85 —— 上界 85；@0xdde14 addls pc, pc, r4, lsl #2 —— 86 项表
 *   表4 按同一字节（0..51）→ 9 条内核；带字符串 1 的组合 → VMError：@0xddf80 cmp r5, #51 —— 上界 51；@0xddf84 addls pc, pc, r5, lsl #2 —— 52 项表
 *   结果 tag：0=double、7=int32、10=int64，只在 r4≠0 时写 [r4+0xc]：@0xde160 str r3, [r4, #0xc] —— 条件写 tag
 *   实数路径**没有除零检查**（IEEE ±inf/NaN）：@0xde148 vdiv.f64 d7, d6, d7 —— vdiv.f64 之前无任何比较
 *   整数除零检查 1（int64 内核，orrs 两字）：@0xde170 orrs r1, r2, r3 —— 判零；@0xde174 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> —— 为零跳 0xde3dc
 *   整数除零检查 2（int32 内核，单字 cmp）：@0xde190 cmp r1, #0 —— 判零；@0xde194 beq 0xde53c <_Z5DoDivjPhPKhP6VMExec+0x7d4> —— 为零跳 0xde53c
 *   除零落地只写 tag 不写值：@0xde3dc ldr r1, [pc, #0x1c4] —— VMError('DoDiv :: Divide by zero') 后 tag=10；0xde53c 同句后 tag=7
 *   三档除法内核：real 走 @0xde148 vdiv.f64 d7, d6, d7 —— 不判零；int32 走 @0xde19c bl 0x318d10 <__divsi3> —— 判零后调用；int64 走 @0xde17c bl 0x319414 <__aeabi_ldivmod> —— 判零后调用
 *   慢路径用 F_JS_ToNumber（不是 ToInt32）：@0xde330 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> —— box 后的第一次强制转换
 *
 * 结论（新增 4 条硬事实）：
 *   1. DoDiv 的 arg 位域与 DoSub 完全同构（bits[11:8]==1 开慢路径、(Afmt<<4)|Bfmt 两段格式码、[B][A] 背靠背排布），
 *      差别只在内核与零检查——同一模板的两份实例。
 *   2. 整数除零是**软错误**：VMError 记一条消息，然后把结果 tag 写成 7/10 就返回，结果值槽不动，执行继续。
 *      实数除零完全不判，直接拿 IEEE 的 ±inf / NaN。
 *   3. 混合宽度除法一律先升档：int32÷int64、int64÷int32 都走 __aeabi_ldivmod，较窄一侧用 asr #31 造高半字符号扩展；
 *      real 参与则 __fixdfdi/__floatdidf 往返，最后按被提升到的档位写 tag。
 *   4. 整数除法是 C 语义截断（__divsi3 / __aeabi_ldivmod 的商），余数留在 r2:r3 被丢弃。
 * 备注：本卡把**高 nibble**(bits[23:20]) 记为 A（左操作数）、低 nibble(bits[19:16]) 记为 B。这个左右顺序不是猜的——
 *   减法用 rsb/subs 取 A−B、除法用 vdiv 取 A/B、取余用 __divsi3(A,B)、移位用 lsl 把 A 当被移位值，四处非对称指令
 *   一起把方向钉死；同批 DoShr/DoMul/DoMod/DoOr 的卡因运算符可交换而把低位 nibble 记作 opA，两者描述的是同一组槽位。
 * open：
 *   · 0xde284/0xde568 两条 JS 文案写的是 "'*' operator"（复制粘贴自乘法），与本函数名不符；运行时以 VMError 文本为准，未做运行期核对。
 *   · 返回值是"新 sp"还是"新 ip"未定（本函数不读 arg3(base)；快路径读 4/8 字节裸值，慢路径才 box 成 16 字节 RValue）。
 *   · 尾部 0xde598..0xde5e0 是 literal pool（objdump 译成 eoreq/mla），逐字保留。
 */
/* @0xddd68 ubfx r2, r0, #0x8, #0x4 */
/* @0xddd6c lsr r0, r0, #16 */
/* @0xddd70 cmp r2, #1 */
/* @0xddd74 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xddd78 mov r10, r1 */
/* @0xddd7c sub sp, sp, #64 */
/* @0xddd80 mov r9, r3 */
/* @0xddd84 uxtb r4, r0 */
/* @0xddd88 beq 0xde2b4 <_Z5DoDivjPhPKhP6VMExec+0x54c> */
/* @0xddd8c and r3, r4, #15   ——取 B 的 nibble */
/* @0xddd90 cmp r3, #6 */
/* @0xddd94 addls pc, pc, r3, lsl #2   ——表1：Bfmt→A 指针 */
/* @0xddd98 b 0xde584 <_Z5DoDivjPhPKhP6VMExec+0x81c> */
/* @0xddd9c b 0xde0d4 <_Z5DoDivjPhPKhP6VMExec+0x36c> */
/* @0xddda0 b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xddda4 b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xddda8 b 0xde0d4 <_Z5DoDivjPhPKhP6VMExec+0x36c> */
/* @0xdddac b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xdddb0 b 0xde0ec <_Z5DoDivjPhPKhP6VMExec+0x384> */
/* @0xdddb4 b 0xdddb8 <_Z5DoDivjPhPKhP6VMExec+0x50>   ——Bfmt=6（内联字符串常量）→ VMError */
/* @0xdddb8 ldr r1, [pc, #0x7d8]   ——VMError/JSThrow 文案：'DoDiv :: Execution Engine - Cannot operate on string type' */
/* @0xdddbc mov r0, r9 */
/* @0xdddc0 mov r5, r4 */
/* @0xdddc4 mov r7, r10 */
/* @0xdddc8 add r1, pc, r1 */
/* @0xdddcc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdddd0 asr r3, r5, #4 */
/* @0xdddd4 cmp r3, #6 */
/* @0xdddd8 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xde0cc, 1-2→0xde0c4, 3→0xde0cc, 4→0xde0c4, 5→0xde07c, 6→0xdddfc */
/* @0xddddc b 0xde590 <_Z5DoDivjPhPKhP6VMExec+0x828> */
/* @0xddde0 b 0xde0cc <_Z5DoDivjPhPKhP6VMExec+0x364> */
/* @0xddde4 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xddde8 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xdddec b 0xde0cc <_Z5DoDivjPhPKhP6VMExec+0x364> */
/* @0xdddf0 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xdddf4 b 0xde07c <_Z5DoDivjPhPKhP6VMExec+0x314> */
/* @0xdddf8 b 0xdddfc <_Z5DoDivjPhPKhP6VMExec+0x94>   ——Afmt=6 → VMError */
/* @0xdddfc ldr r1, [pc, #0x798]   ——VMError/JSThrow 文案：'DoDiv :: Execution Engine - Cannot operate on string type' */
/* @0xdde00 mov r0, r9 */
/* @0xdde04 mov r6, r7 */
/* @0xdde08 add r1, pc, r1 */
/* @0xdde0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdde10 cmp r4, #85 */
/* @0xdde14 addls pc, pc, r4, lsl #2   ——表：按 r4 0→0xde06c, 1→0xde134, 2-3→0xde06c, 4→0xde134, 5→0xde05c, 6-31→0xde134, 32→0xde06c, 33→0xde134, 34→0xddf74, 35→0xde06c, 36→0xde134, 37→0xde05c, 38-47→0xde134, 48→0xde06c, 49→0xde134, 50-51→0xde06c, 52→0xde134, 53→0xde05c, 54-79→0xde134, 80→0xde05c, 81→0xde134, 82-83→0xde05c, 84→0xde134, 85→0xde05c */
/* @0xdde18 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde1c b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde20 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde24 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde28 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde2c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde30 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xdde34 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde38 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde3c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde40 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde44 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde48 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde4c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde50 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde54 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde58 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde5c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde60 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde64 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde68 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde6c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde70 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde74 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde78 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde7c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde80 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde84 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde88 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde8c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde90 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde94 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde98 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde9c b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddea0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddea4 b 0xddf74 <_Z5DoDivjPhPKhP6VMExec+0x20c> */
/* @0xddea8 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddeac b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddeb0 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddeb4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddeb8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddebc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddecc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddedc b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddee0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddee4 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddee8 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddeec b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddef0 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddef4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddef8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddefc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf00 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf04 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf08 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf0c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf10 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf14 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf18 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf1c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf20 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf24 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf28 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf2c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf30 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf34 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf38 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf3c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf40 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf44 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf48 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf4c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf50 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf54 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf58 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf5c b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf60 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf64 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf68 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf6c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf70 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf74 sub r6, r6, #4 */
/* @0xddf78 mov r4, #0 */
/* @0xddf7c mov r8, r6 */
/* @0xddf80 cmp r5, #51 */
/* @0xddf84 addls pc, pc, r5, lsl #2   ——表：按 r5 0→0xde140, 1→0xde26c, 2→0xde234, 3→0xde214, 4-31→0xde26c, 32→0xde250, 33→0xde26c, 34→0xde18c, 35→0xde1cc, 36-47→0xde26c, 48→0xde1ac, 49→0xde26c, 50→0xde1f0, 51→0xde16c */
/* @0xddf88 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddf8c b 0xde140 <_Z5DoDivjPhPKhP6VMExec+0x3d8> */
/* @0xddf90 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddf94 b 0xde234 <_Z5DoDivjPhPKhP6VMExec+0x4cc> */
/* @0xddf98 b 0xde214 <_Z5DoDivjPhPKhP6VMExec+0x4ac> */
/* @0xddf9c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfac b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfbc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfcc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfdc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfec b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddffc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde000 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde004 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde008 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde00c b 0xde250 <_Z5DoDivjPhPKhP6VMExec+0x4e8> */
/* @0xde010 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde014 b 0xde18c <_Z5DoDivjPhPKhP6VMExec+0x424> */
/* @0xde018 b 0xde1cc <_Z5DoDivjPhPKhP6VMExec+0x464> */
/* @0xde01c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde020 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde024 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde028 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde02c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde030 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde034 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde038 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde03c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde040 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde044 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde048 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde04c b 0xde1ac <_Z5DoDivjPhPKhP6VMExec+0x444> */
/* @0xde050 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde054 b 0xde1f0 <_Z5DoDivjPhPKhP6VMExec+0x488> */
/* @0xde058 b 0xde16c <_Z5DoDivjPhPKhP6VMExec+0x404> */
/* @0xde05c sub r4, r6, #16 */
/* @0xde060 mov r8, r4 */
/* @0xde064 mov r6, r4 */
/* @0xde068 b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde06c sub r6, r6, #8 */
/* @0xde070 mov r4, #0 */
/* @0xde074 mov r8, r6 */
/* @0xde078 b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde07c ldr r3, [r7, #0xc]   ——Afmt 5：读 [A+0xc] 的 tag */
/* @0xde080 cmp r3, #13 */
/* @0xde084 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xde4e4, 1→0xde4d0, 2→0xde4bc, 3→0xde4a8, 4→0xde514, 5→0xde494, 6→0xde514, 7→0xde488, 8-9→0xde514, 10→0xde478, 11-12→0xde514, 13→0xde4e4 */
/* @0xde088 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde08c b 0xde4e4 <_Z5DoDivjPhPKhP6VMExec+0x77c> */
/* @0xde090 b 0xde4d0 <_Z5DoDivjPhPKhP6VMExec+0x768> */
/* @0xde094 b 0xde4bc <_Z5DoDivjPhPKhP6VMExec+0x754> */
/* @0xde098 b 0xde4a8 <_Z5DoDivjPhPKhP6VMExec+0x740> */
/* @0xde09c b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0a0 b 0xde494 <_Z5DoDivjPhPKhP6VMExec+0x72c> */
/* @0xde0a4 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0a8 b 0xde488 <_Z5DoDivjPhPKhP6VMExec+0x720> */
/* @0xde0ac b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0b0 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0b4 b 0xde478 <_Z5DoDivjPhPKhP6VMExec+0x710> */
/* @0xde0b8 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0bc b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0c0 b 0xde4e4 <_Z5DoDivjPhPKhP6VMExec+0x77c> */
/* @0xde0c4 add r6, r7, #4   ——Afmt 1/2/4 → r6=A+4 */
/* @0xde0c8 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde0cc add r6, r7, #8   ——Afmt 0/3 → r6=A+8 */
/* @0xde0d0 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde0d4 add r7, r1, #8   ——Bfmt 0/3 → A=arg2+8 */
/* @0xde0d8 mov r5, r4 */
/* @0xde0dc b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde0e0 add r7, r1, #4   ——Bfmt 1/2/4 → A=arg2+4 */
/* @0xde0e4 mov r5, r4 */
/* @0xde0e8 b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde0ec ldr r3, [r1, #0xc]   ——Bfmt 5：读 [arg2+0xc] 的 tag */
/* @0xde0f0 cmp r3, #13 */
/* @0xde0f4 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xde470, 1→0xde458, 2→0xde440, 3→0xde428, 4→0xde4fc, 5→0xde410, 6→0xde4fc, 7→0xde404, 8-9→0xde4fc, 10→0xde3f4, 11-12→0xde4fc, 13→0xde470 */
/* @0xde0f8 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde0fc b 0xde470 <_Z5DoDivjPhPKhP6VMExec+0x708> */
/* @0xde100 b 0xde458 <_Z5DoDivjPhPKhP6VMExec+0x6f0> */
/* @0xde104 b 0xde440 <_Z5DoDivjPhPKhP6VMExec+0x6d8> */
/* @0xde108 b 0xde428 <_Z5DoDivjPhPKhP6VMExec+0x6c0> */
/* @0xde10c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde110 b 0xde410 <_Z5DoDivjPhPKhP6VMExec+0x6a8> */
/* @0xde114 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde118 b 0xde404 <_Z5DoDivjPhPKhP6VMExec+0x69c> */
/* @0xde11c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde120 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde124 b 0xde3f4 <_Z5DoDivjPhPKhP6VMExec+0x68c> */
/* @0xde128 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde12c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde130 b 0xde470 <_Z5DoDivjPhPKhP6VMExec+0x708> */
/* @0xde134 mov r8, #0 */
/* @0xde138 mov r4, r8 */
/* @0xde13c b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde140 vldr d6, [r7] */
/* @0xde144 vldr d7, [r10] */
/* @0xde148 vdiv.f64 d7, d6, d7 */
/* @0xde14c mov r3, #0 */
/* @0xde150 vstr d7, [r8] */
/* @0xde154 cmp r4, #0 */
/* @0xde158 beq 0xde2a8 <_Z5DoDivjPhPKhP6VMExec+0x540> */
/* @0xde15c mov r0, r6 */
/* @0xde160 str r3, [r4, #0xc] */
/* @0xde164 add sp, sp, #64 */
/* @0xde168 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xde16c ldrd r2, r3, [r10] */
/* @0xde170 orrs r1, r2, r3 */
/* @0xde174 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde178 ldrd r0, r1, [r7] */
/* @0xde17c bl 0x319414 <__aeabi_ldivmod> */
/* @0xde180 mov r3, #10 */
/* @0xde184 strd r0, r1, [r8] */
/* @0xde188 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde18c ldr r1, [r10] */
/* @0xde190 cmp r1, #0 */
/* @0xde194 beq 0xde53c <_Z5DoDivjPhPKhP6VMExec+0x7d4> */
/* @0xde198 ldr r0, [r7] */
/* @0xde19c bl 0x318d10 <__divsi3> */
/* @0xde1a0 mov r3, #7 */
/* @0xde1a4 str r0, [r8] */
/* @0xde1a8 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1ac ldrd r0, r1, [r7] */
/* @0xde1b0 bl 0x319164 <__floatdidf> */
/* @0xde1b4 vldr d7, [r10] */
/* @0xde1b8 mov r3, #0 */
/* @0xde1bc vmov d6, r0, r1 */
/* @0xde1c0 vdiv.f64 d7, d6, d7 */
/* @0xde1c4 vstr d7, [r8] */
/* @0xde1c8 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1cc ldrd r2, r3, [r10] */
/* @0xde1d0 orrs r1, r2, r3 */
/* @0xde1d4 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde1d8 ldr r0, [r7] */
/* @0xde1dc asr r1, r0, #31 */
/* @0xde1e0 bl 0x319414 <__aeabi_ldivmod> */
/* @0xde1e4 mov r3, #10 */
/* @0xde1e8 strd r0, r1, [r8] */
/* @0xde1ec b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1f0 ldr r2, [r10] */
/* @0xde1f4 cmp r2, #0 */
/* @0xde1f8 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde1fc ldrd r0, r1, [r7] */
/* @0xde200 asr r3, r2, #31 */
/* @0xde204 bl 0x319414 <__aeabi_ldivmod> */
/* @0xde208 mov r3, #10 */
/* @0xde20c strd r0, r1, [r8] */
/* @0xde210 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde214 ldrd r0, r1, [r10] */
/* @0xde218 bl 0x319164 <__floatdidf> */
/* @0xde21c vldr d7, [r7] */
/* @0xde220 mov r3, #0 */
/* @0xde224 vmov d5, r0, r1 */
/* @0xde228 vdiv.f64 d7, d7, d5 */
/* @0xde22c vstr d7, [r8] */
/* @0xde230 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde234 vldr s14, [r10] */
/* @0xde238 vcvt.f64.s32 d7, s14 */
/* @0xde23c vldr d6, [r7] */
/* @0xde240 mov r3, #0 */
/* @0xde244 vdiv.f64 d7, d6, d7 */
/* @0xde248 vstr d7, [r8] */
/* @0xde24c b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde250 vldr s14, [r7] */
/* @0xde254 vcvt.f64.s32 d7, s14 */
/* @0xde258 vldr d6, [r10] */
/* @0xde25c mov r3, #0 */
/* @0xde260 vdiv.f64 d7, d7, d6 */
/* @0xde264 vstr d7, [r8] */
/* @0xde268 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde26c ldr r1, [pc, #0x32c]   ——VMError/JSThrow 文案：'DoDiv :: Execution Error' */
/* @0xde270 mov r0, r9 */
/* @0xde274 add r1, pc, r1 */
/* @0xde278 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde27c mov r3, #0 */
/* @0xde280 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde284 ldr r0, [pc, #0x318]   ——VMError/JSThrow 文案："Could not convert right-hand-side of '*' operator to a number" */
/* @0xde288 add r0, pc, r0 */
/* @0xde28c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xde290 ldr r3, [sp, #0x2c] */
/* @0xde294 sub r3, r3, #1 */
/* @0xde298 bic r3, r3, #-16777216 */
/* @0xde29c bic r3, r3, #3 */
/* @0xde2a0 cmp r3, #0 */
/* @0xde2a4 beq 0xde4ec <_Z5DoDivjPhPKhP6VMExec+0x784> */
/* @0xde2a8 mov r0, r6 */
/* @0xde2ac add sp, sp, #64 */
/* @0xde2b0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xde2b4 add r5, sp, #16 */
/* @0xde2b8 mov r2, r1 */
/* @0xde2bc and r1, r4, #15 */
/* @0xde2c0 mov r0, r5 */
/* @0xde2c4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xde2c8 lsr r1, r4, #4 */
/* @0xde2cc mov r2, r0 */
/* @0xde2d0 mov r0, sp */
/* @0xde2d4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xde2d8 ldr r3, [sp, #0xc] */
/* @0xde2dc mvn r12, #-16777216 */
/* @0xde2e0 and r3, r3, r12 */
/* @0xde2e4 cmp r3, r12 */
/* @0xde2e8 mov r6, r0 */
/* @0xde2ec beq 0xde554 <_Z5DoDivjPhPKhP6VMExec+0x7ec> */
/* @0xde2f0 ldr r3, [sp, #0x1c] */
/* @0xde2f4 bic r3, r3, #-16777216 */
/* @0xde2f8 cmp r3, r12 */
/* @0xde2fc beq 0xde528 <_Z5DoDivjPhPKhP6VMExec+0x7c0> */
/* @0xde300 add r4, sp, #32 */
/* @0xde304 mov r1, sp */
/* @0xde308 mov r2, #0 */
/* @0xde30c mov r3, #0 */
/* @0xde310 mov r0, r4 */
/* @0xde314 str r12, [sp, #0x2c] */
/* @0xde318 str r12, [sp, #0x3c] */
/* @0xde31c mov r12, #0 */
/* @0xde320 strd r2, r3, [sp, #32] */
/* @0xde324 strd r2, r3, [sp, #48] */
/* @0xde328 str r12, [sp, #0x28] */
/* @0xde32c str r12, [sp, #0x38] */
/* @0xde330 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xde334 cmp r0, #1 */
/* @0xde338 beq 0xde568 <_Z5DoDivjPhPKhP6VMExec+0x800> */
/* @0xde33c cmp r0, #0 */
/* @0xde340 bne 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde344 add r7, sp, #48 */
/* @0xde348 mov r1, r5 */
/* @0xde34c mov r0, r7 */
/* @0xde350 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xde354 cmp r0, #1 */
/* @0xde358 beq 0xde284 <_Z5DoDivjPhPKhP6VMExec+0x51c> */
/* @0xde35c cmp r0, #0 */
/* @0xde360 bne 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde364 str r0, [r6, #-0x4] */
/* @0xde368 sub r5, r6, #16 */
/* @0xde36c vldr d6, [sp, #32] */
/* @0xde370 vldr d7, [sp, #48] */
/* @0xde374 vdiv.f64 d5, d6, d7 */
/* @0xde378 ldr r1, [sp, #0x2c] */
/* @0xde37c sub r1, r1, #1 */
/* @0xde380 bic r1, r1, #-16777216 */
/* @0xde384 bic r1, r1, #3 */
/* @0xde388 cmp r1, #0 */
/* @0xde38c vmov r2, r3, d5 */
/* @0xde390 vstr s10, [r6, #-16] */
/* @0xde394 str r3, [r6, #-0xc] */
/* @0xde398 beq 0xde578 <_Z5DoDivjPhPKhP6VMExec+0x810> */
/* @0xde39c ldr r1, [sp, #0x3c] */
/* @0xde3a0 mov r3, #0 */
/* @0xde3a4 str r3, [sp, #0x28] */
/* @0xde3a8 mov r2, #5 */
/* @0xde3ac sub r1, r1, #1 */
/* @0xde3b0 str r3, [sp, #0x20] */
/* @0xde3b4 bic r3, r1, #-16777216 */
/* @0xde3b8 str r2, [sp, #0x2c] */
/* @0xde3bc bic r3, r3, #3 */
/* @0xde3c0 cmp r3, #0 */
/* @0xde3c4 movne r0, r5 */
/* @0xde3c8 bne 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde3cc mov r0, r7 */
/* @0xde3d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde3d4 mov r0, r5 */
/* @0xde3d8 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde3dc ldr r1, [pc, #0x1c4]   ——VMError/JSThrow 文案：'DoDiv :: Divide by zero' */
/* @0xde3e0 mov r0, r9 */
/* @0xde3e4 add r1, pc, r1 */
/* @0xde3e8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde3ec mov r3, #10 */
/* @0xde3f0 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde3f4 and r0, r0, #240 */
/* @0xde3f8 orr r5, r0, #3 */
/* @0xde3fc add r7, r10, #16   ——Bfmt=5 时 A=arg2+16 */
/* @0xde400 b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde404 and r0, r0, #240 */
/* @0xde408 orr r5, r0, #2 */
/* @0xde40c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde410 ldr r1, [pc, #0x194]   ——VMError/JSThrow 文案：'DoDiv :1: undefined value' */
/* @0xde414 mov r0, r9 */
/* @0xde418 mov r5, r4 */
/* @0xde41c add r1, pc, r1 */
/* @0xde420 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde424 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde428 ldr r1, [pc, #0x180]   ——VMError/JSThrow 文案：'DoDiv :1: illegal pointer use' */
/* @0xde42c mov r0, r9 */
/* @0xde430 mov r5, r4 */
/* @0xde434 add r1, pc, r1 */
/* @0xde438 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde43c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde440 ldr r1, [pc, #0x16c]   ——VMError/JSThrow 文案：'DoDiv :1: illegal array use' */
/* @0xde444 mov r0, r9 */
/* @0xde448 mov r5, r4 */
/* @0xde44c add r1, pc, r1 */
/* @0xde450 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde454 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde458 ldr r1, [pc, #0x158]   ——VMError/JSThrow 文案：'DoDiv :1: Execution Engine - Cannot operate on string type' */
/* @0xde45c mov r0, r9 */
/* @0xde460 mov r5, r4 */
/* @0xde464 add r1, pc, r1 */
/* @0xde468 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde46c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde470 and r5, r4, #240 */
/* @0xde474 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde478 and r5, r5, #15 */
/* @0xde47c orr r5, r5, #48 */
/* @0xde480 add r6, r7, #16 */
/* @0xde484 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde488 and r5, r5, #15 */
/* @0xde48c orr r5, r5, #32 */
/* @0xde490 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde494 ldr r1, [pc, #0x120]   ——VMError/JSThrow 文案：'DoDiv :2: undefined value' */
/* @0xde498 mov r0, r9 */
/* @0xde49c add r1, pc, r1 */
/* @0xde4a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4a4 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4a8 ldr r1, [pc, #0x110]   ——VMError/JSThrow 文案：'DoDiv :2: illegal pointer use' */
/* @0xde4ac mov r0, r9 */
/* @0xde4b0 add r1, pc, r1 */
/* @0xde4b4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4b8 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4bc ldr r1, [pc, #0x100]   ——VMError/JSThrow 文案：'DoDiv :2: illegal array use' */
/* @0xde4c0 mov r0, r9 */
/* @0xde4c4 add r1, pc, r1 */
/* @0xde4c8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4cc b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4d0 ldr r1, [pc, #0xf0]   ——VMError/JSThrow 文案：'DoDiv :: Execution Engine - Cannot operate on string type' */
/* @0xde4d4 mov r0, r9 */
/* @0xde4d8 add r1, pc, r1 */
/* @0xde4dc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4e0 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4e4 and r5, r5, #15 */
/* @0xde4e8 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4ec mov r0, r4 */
/* @0xde4f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde4f4 mov r0, r6 */
/* @0xde4f8 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde4fc ldr r1, [pc, #0xc8]   ——VMError/JSThrow 文案：'DoDiv :1: Malformed variable' */
/* @0xde500 mov r0, r9 */
/* @0xde504 mov r5, r4 */
/* @0xde508 add r1, pc, r1 */
/* @0xde50c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde510 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde514 ldr r1, [pc, #0xb4]   ——VMError/JSThrow 文案：'DoDiv :2: Malformed variable' */
/* @0xde518 mov r0, r9 */
/* @0xde51c add r1, pc, r1 */
/* @0xde520 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde524 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde528 ldr r0, [pc, #0xa4]   ——VMError/JSThrow 文案：'could not find lhs variable on div' */
/* @0xde52c add r0, pc, r0 */
/* @0xde530 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xde534 mov r0, r6 */
/* @0xde538 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde53c ldr r1, [pc, #0x94]   ——VMError/JSThrow 文案：'DoDiv :: Divide by zero' */
/* @0xde540 mov r0, r9 */
/* @0xde544 add r1, pc, r1 */
/* @0xde548 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde54c mov r3, #7 */
/* @0xde550 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde554 ldr r0, [pc, #0x80]   ——VMError/JSThrow 文案：'could not find lhs variable on div' */
/* @0xde558 add r0, pc, r0 */
/* @0xde55c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xde560 mov r0, r6 */
/* @0xde564 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde568 ldr r0, [pc, #0x70]   ——VMError/JSThrow 文案："Could not convert left-hand-side of '*' operator to a number" */
/* @0xde56c add r0, pc, r0 */
/* @0xde570 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xde574 b 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde578 mov r0, r4 */
/* @0xde57c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde580 b 0xde39c <_Z5DoDivjPhPKhP6VMExec+0x634> */
/* @0xde584 mov r5, r4 */
/* @0xde588 mov r7, r1 */
/* @0xde58c b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde590 mov r6, r7 */
/* @0xde594 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde598 eoreq r5, r5, r12, asr #9   ——literal pool：+0x2554cc → 0x33329c (非指令) 'DoDiv :: Execution Engine - Cannot operate on string type' */
/* @0xde59c eoreq r5, r5, r12, lsl #9   ——literal pool：+0x25548c → 0x33329c (非指令) 'DoDiv :: Execution Engine - Cannot operate on string type' */
/* @0xde5a0 eoreq r5, r5, r0, lsr #3   ——literal pool：+0x2551a0 → 0x33341c (非指令) 'DoDiv :: Execution Error' */
/* @0xde5a4 eoreq r4, r5, r12, asr #31   ——literal pool：+0x254fcc → 0x33325c (非指令) "Could not convert right-hand-side of '*' operator to a number" */
/* @0xde5a8 eoreq r5, r5, r8, lsl r0   ——literal pool：+0x255018 → 0x333404 (非指令) 'DoDiv :: Divide by zero' */
/* @0xde5ac .word 0x00254ed4   ——literal pool：+0x254ed4 → 0x3332f8 (非指令) 'DoDiv :1: undefined value' */
/* @0xde5b0 mlaeq r5, r12, lr, r4   ——literal pool：+0x254e9c → 0x3332d8 (非指令) 'DoDiv :1: illegal pointer use' */
/* @0xde5b4 .word 0x00254efc   ——literal pool：+0x254efc → 0x333350 (非指令) 'DoDiv :1: illegal array use' */
/* @0xde5b8 eoreq r4, r5, r8, lsr #29   ——literal pool：+0x254ea8 → 0x333314 (非指令) 'DoDiv :1: Execution Engine - Cannot operate on string type' */
/* @0xde5bc eoreq r4, r5, r8, lsl #30   ——literal pool：+0x254f08 → 0x3333ac (非指令) 'DoDiv :2: undefined value' */
/* @0xde5c0 .word 0x00254ed4   ——literal pool：+0x254ed4 → 0x33338c (非指令) 'DoDiv :2: illegal pointer use' */
/* @0xde5c4 .word 0x00254efc   ——literal pool：+0x254efc → 0x3333c8 (非指令) 'DoDiv :2: illegal array use' */
/* @0xde5c8 .word 0x00254dbc   ——literal pool：+0x254dbc → 0x33329c (非指令) 'DoDiv :: Execution Engine - Cannot operate on string type' */
/* @0xde5cc eoreq r4, r5, r12, asr lr   ——literal pool：+0x254e5c → 0x33336c (非指令) 'DoDiv :1: Malformed variable' */
/* @0xde5d0 eoreq r4, r5, r0, asr #29   ——literal pool：+0x254ec0 → 0x3333e4 (非指令) 'DoDiv :2: Malformed variable' */
/* @0xde5d4 eoreq r4, r5, r4, asr #25   ——literal pool：+0x254cc4 → 0x3331f8 (非指令) 'could not find lhs variable on div' */
/* @0xde5d8 .word 0x00254eb8   ——literal pool：+0x254eb8 → 0x333404 (非指令) 'DoDiv :: Divide by zero' */
/* @0xde5dc mlaeq r5, r8, r12, r4   ——literal pool：+0x254c98 → 0x3331f8 (非指令) 'could not find lhs variable on div' */
/* @0xde5e0 eoreq r4, r5, r8, lsr #25   ——literal pool：+0x254ca8 → 0x33321c (非指令) "Could not convert left-hand-side of '*' operator to a number" */
