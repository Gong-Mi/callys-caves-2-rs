/* cally 逆向卡：F_JS_ToInt32（原版 libyoyo.so，armv7）
 * @func 0x24d5c8 0x24d730  size 360  90 条（0x24d71c 是对齐 nop，0x24d720/0x24d728 起是 2^31、2^32 两枚 double 常量，
 *       objdump 把数据字译成指令，按规矩保留原写法）
 * 级别: 正文（90 条全覆盖；mod-2^32 的实现机制、int64 截断与 2^31 折叠全部钉死；1 条 open 见文末）
 * 符号: _Z12F_JS_ToInt32R6RValueS0_ → int32 F_JS_ToInt32(RValue& out, RValue& in)
 *
 * ── 它不写 int32，写的是"再 vcvt 一次就等于 ToInt32 的 double" ──────────────────
 *   out 上只有 8 字节 double + tag 0 的写点（0x24d634/0x24d638/0x24d63c 清零，0x24d6e8 与 0x24d70c 的 stm r4,{r2,r3}），
 *   全函数没有一处 `str rX,[r4,#0x?]`（4 字节）把整数写进 out。
 *   真正的整数化在调用者那边：DoNot 0xd7b24、DoAnd 0xdf5c0 用 vcvt.s32.f64；
 *   DoShr 对 ToUint32 的结果用 vcvt.u32.f64（0xe1e68）。
 *   11 个调用点：DoNot 0xd7b08、DoAnd 0xdf03c/0xdf59c、DoOr 0xdf8d0/0xdfe60、DoXor 0xe01a4/0xe0704、
 *   DoShl 0xe0db8/0xe12fc、DoShr 0xe1648、JS_Global_parseInt 0x254f04 —— 全是 JS 位运算/parseInt 的入口。
 *
 * ── 骨架 ─────────────────────────────────────────────────────
 *   0x24d5c8 push {r4,r5,r6,lr} + 0x24d5cc vpush {d8}（d8 callee-saved，用来存符号）+ sub sp,#16
 *   r4 = out；r1 = in 原样交给 ToNumber；sp 上是 16 字节临时 RValue，预置 {0,0,0,0x00FFFFFF}
 *     （0x24d5e8 strd 0 0、0x24d5ec str 0、0x24d5f0 mvn r3,#-16777216 → 0x24d5f4 str 到 [sp+0xc]）
 *   0x24d5f8 bl F_JS_ToNumber(&tmp=sp, in)
 *   返回非 0 → 0x24d5fc 起：按 (tag-1)&0x00FFFFFC==0（即 tag∈{1,2,3,4}）判临时是否要释放，
 *     命中走 0x24d67c FREE_RValue__Pre(&tmp)；两条路都把返回码本身交回去（0x24d618 movne r0,r5 / 0x24d680 mov r0,r5）。
 *     当前 ToNumber 返回非 0 时 tmp.tag 仍是 0x00FFFFFF，所以释放分支实际不可达，属防御代码（TOI32-009）。
 *   返回 0 → 0x24d62c 起：先把 out 清零（tag 0 + 8 字节 0），再三条早退，全部落 0x24d668 的 mov r0,#0
 *     （"成功 + 0.0"，不是错误码）：
 *       NaN   0x24d630 vcmp.f64 d7,d7 → 0x24d644 bvs（自比较 unordered 置 V）
 *       ±Inf  0x24d648/0x24d64c yyisinf(&tmp)：判据 (hi & 0x7FF00000)==0x7FF00000（0x240990/0x240994 的
 *             and/cmp/cmpeq），NaN 也满足但已被上一关挡掉
 *       零    0x24d65c vcmpe.f64 d7,#0 → 相等即 0.0（-0.0 的符号一并丢掉）
 *
 * ── 主路 0x24d690..0x24d718：向零截断 → int64 → **只留低 32 位** → 无符号回 double → 2^31 折叠 ──
 *   ① 符号与截断（0x24d690..0x24d6b8）
 *      d6=+1.0、d8=-1.0、d5=|x|（vabs）、vcmpe d7,#0 后 vmovpl d8,d6 → sign = x<0 ? -1 : +1
 *      floor(|x|)（0x24d6ac）→ vmul d6 = sign*floor(|x|) = **trunc(x)（向零）**
 *   ② int64 截断（0x24d6bc __fixdfdi）→ 得到 trunc(x) 的 64 位二进制补码；
 *      |t| ≥ 2^64 时 __fixunsdfsi 内部饱和（0x31b114 mvn r0,#0，即 0xFFFFFFFF）
 *   ③ **取模就在这一条**：0x24d6c0 mov r1,#0 —— 把 64 位结果的高 32 位清掉，
 *      只留低 32 位并零扩展，于是 0x24d6c4 __floatdidf 拿到的是一个 **无符号** 的
 *      u = trunc(x) mod 2^32 ∈ [0, 2^32)。不是 and 掩码、不是循环、也不在 double 域上做 fmod。
 *      （__floatdidf 0x319164 确实读 r1：orrs r2,r0,r1 与 ands r5,r1,#-2147483648 都用高字，
 *        所以这条 mov 不是死写，它就是取模。）
 *   ④ 2^31 折叠（0x24d6c8 vldr d7 = 0x24d720 = 2^31 = 0x00000000_41e00000；
 *      0x24d6d8 vcmpe d5,d7；0x24d6e0 **bgt** 0x24d6f8）
 *      u > 2^31 → 0x24d6fc vldr d7 = 0x24d728 = 2^32 = 4294967296.0 → 0x24d704 vsub d5 = u - 2^32 → 落 (-2^31, 0)
 *      否则原样 stm → 落 [0, 2^31]
 *      ⇒ 结果域 = (-2^31, 2^31]，这就是"双重取模"：先 mod 2^32（寄存器截断），再减一次 2^32 折进有符号区间。
 *   ⑤ 唯一的破口：比较用 bgt（**严格**大于），u == 2^31 时不折，输出 +2147483648.0；
 *      而 u == 2^31 ⇔ trunc(x) ≡ 2^31 (mod 2^32)，即 x = ±2^31、±(2^31+2^32)… 一整族。
 *      调用者的 vcvt.s32.f64 把这个 +2^31 饱和成 0x7FFFFFFF，ECMA 给的是 -2^31 —— 所以 +2^31 与 -2^31
 *      两个输入都错（-2^31 的 trunc 低 32 位同样是 0x80000000，一样不折），差 2^32-1（claims TOI32-006）。
 *   ⑥ 另一处非 JS 行为在 |x| ≥ 2^64 的饱和带：int64 那步先饱和，u 又只取饱和值的低 32 位，
 *      x ≥ +2^64 → __fixunsdfdi 给 0xFFFFFFFF_FFFFFFFF → 低 32 位全 1 → 输出 -1.0；
 *      x ≤ -2^64 → __fixdfdi 走"取 |x| 再 rsb/rsc 取负"→ 得 1 → 输出 +1.0。
 *      与 JS 的 mod 2^32 不一致（claims TOI32-007）。
 *      除此之外（|x| < 2^64 且 u != 2^31）与 JS ToInt32 逐值一致，已按本卡实现复核：
 *      -1.5 → -1、-0.5 → 0、1.9 → 1、3e9 → -1294967296、7e9 → -1589934592、2^32 → 0、
 *      -2^31-1 → 2147483647、-2^63 → 0、1e19 → -1981284352。
 *
 * 结论：
 *   1. F_JS_ToInt32 = ToNumber + "向零截断 + 取低 32 位（mod 2^32）+ 超过 2^31 减 2^32"，输出仍是 tag 0 的
 *      double，整数化交给调用者的 vcvt.s32.f64 —— 除 u==2^31 一族与 |x|≥2^64 的饱和带外，与 JS ToInt32 逐值等价。
 *   2. 取模是"寄存器丢弃高 32 位"实现的（0x24d6c0 mov r1,#0），不是掩码也不是循环；全函数只有
 *      1 条 vsub.f64（0x24d704）与 1 条 bgt（0x24d6e0），没有第二级取模。
 *   3. NaN / ±Inf / ±0 三条早退把脏值压成 0.0 —— 顺带保证 __fixdfdi 不会收到 NaN/Inf（否则实现是未定义的）。
 * open:
 *   1. 严格 bgt 让 u == 2^31 这一族（x = ±2^31、±(2^31+2^32)…）落到 +2^31，调用者 vcvt.s32.f64 再饱和成
 *      0x7FFFFFFF；ECMA 在这里给的是 -2^31，两者差 2^32-1。原版是否有意靠 vcvt 饱和兜住，无法从本函数单独判定。
 */
/* ---- 段1：入口（out=r4，临时槽预置 {0,0,0,0x00FFFFFF}） ---- */
/* @0x24d5c8 push {r4, r5, r6, lr} */
/* @0x24d5cc vpush {d8} */
/* @0x24d5d0 sub sp, sp, #16 */
/* @0x24d5d4 mov r4, r0 */
/* @0x24d5d8 mov r2, #0 */
/* @0x24d5dc mov r0, sp */
/* @0x24d5e0 mov r3, #0 */
/* @0x24d5e4 mov r12, #0 */
/* @0x24d5e8 strd r2, r3, [sp] */
/* @0x24d5ec str r12, [sp, #0x8] */
/* @0x24d5f0 mvn r3, #-16777216 */
/* @0x24d5f4 str r3, [sp, #0xc] */
/* ---- 段2：转发给 F_JS_ToNumber（out=&tmp，in 原样） ---- */
/* @0x24d5f8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x24d5fc subs r5, r0, #0 */
/* @0x24d600 beq 0x24d62c <_Z12F_JS_ToInt32R6RValueS0_+0x64> —— r0==0 → 成功路 */
/* ---- 段3：错误返回 —— 按 (tag-1)&0x00FFFFFC 判临时是否释放，两条路都返回原码 ---- */
/* @0x24d604 ldr r3, [sp, #0xc] */
/* @0x24d608 sub r3, r3, #1 */
/* @0x24d60c bic r3, r3, #-16777216 */
/* @0x24d610 bic r3, r3, #3 */
/* @0x24d614 cmp r3, #0 */
/* @0x24d618 movne r0, r5 */
/* @0x24d61c beq 0x24d678 <_Z12F_JS_ToInt32R6RValueS0_+0xb0> */
/* @0x24d620 add sp, sp, #16 */
/* @0x24d624 vpop {d8} */
/* @0x24d628 pop {r4, r5, r6, pc} */
/* ---- 段4：成功 —— 先把 out 清成 {0.0, tag 0} ---- */
/* @0x24d62c vldr d7, [sp] */
/* @0x24d630 vcmp.f64 d7, d7 */
/* @0x24d634 str r5, [r4, #0xc] */
/* @0x24d638 str r5, [r4] */
/* @0x24d63c str r5, [r4, #0x4] */
/* @0x24d640 vmrs APSR_nzcv, fpscr */
/* ---- 段5：三条早退（NaN / ±Inf / 0）共用 0x24d668 ---- */
/* @0x24d644 bvs 0x24d668 <_Z12F_JS_ToInt32R6RValueS0_+0xa0> —— NaN(无序) → 0.0 */
/* @0x24d648 mov r0, sp */
/* @0x24d64c bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x24d650 subs r5, r0, #0 */
/* @0x24d654 bne 0x24d668 <_Z12F_JS_ToInt32R6RValueS0_+0xa0> —— 是 ±Inf → 0.0 */
/* @0x24d658 vldr d7, [sp] */
/* @0x24d65c vcmp.f64 d7, #0 */
/* @0x24d660 vmrs APSR_nzcv, fpscr */
/* @0x24d664 bne 0x24d690 <_Z12F_JS_ToInt32R6RValueS0_+0xc8> —— x!=0 才进主路，否则 0.0 */
/* @0x24d668 mov r0, #0 */
/* @0x24d66c add sp, sp, #16 */
/* @0x24d670 vpop {d8} */
/* @0x24d674 pop {r4, r5, r6, pc} */
/* ---- 段6：释放临时后返回原码 ---- */
/* @0x24d678 mov r0, sp */
/* @0x24d67c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24d680 mov r0, r5 */
/* @0x24d684 add sp, sp, #16 */
/* @0x24d688 vpop {d8} */
/* @0x24d68c pop {r4, r5, r6, pc} */
/* ---- 段7：主路 —— 符号 + 向零截断 ---- */
/* @0x24d690 vmov.f64 d6, #1.000000e+00 */
/* @0x24d694 vmov.f64 d8, #-1.000000e+00 */
/* @0x24d698 vabs.f64 d5, d7 */
/* @0x24d69c vcmpe.f64 d7, #0 */
/* @0x24d6a0 vmov r0, r1, d5 */
/* @0x24d6a4 vmrs APSR_nzcv, fpscr */
/* @0x24d6a8 vmovpl.f64 d8, d6 */
/* @0x24d6ac bl 0xb6598 <floor@plt> —— floor(|x|) */
/* @0x24d6b0 vmov d6, r0, r1 */
/* @0x24d6b4 vmul.f64 d6, d8, d6 */
/* @0x24d6b8 vmov r0, r1, d6 */
/* ---- 段8：int64 往返：__fixdfdi → mov r1,#0（只留低 32 位 = mod 2^32）→ __floatdidf ---- */
/* @0x24d6bc bl 0x3194a0 <__fixdfdi> —— trunc → int64 */
/* @0x24d6c0 mov r1, #0 —— 取模点：高 32 位清零 */
/* @0x24d6c4 bl 0x319164 <__floatdidf> —— 无符号低 32 位 → double */
/* ---- 段9：2^31 折叠（常量 0x24d720 = 2^31、0x24d728 = 2^32） ---- */
/* @0x24d6c8 vldr d7, [pc, #80] */
/* @0x24d6cc mov r2, r0 */
/* @0x24d6d0 mov r3, r1 */
/* @0x24d6d4 vmov d5, r2, r3 */
/* @0x24d6d8 vcmpe.f64 d5, d7 */
/* @0x24d6dc vmrs APSR_nzcv, fpscr */
/* @0x24d6e0 bgt 0x24d6f8 <_Z12F_JS_ToInt32R6RValueS0_+0x130> —— u > 2^31（严格）→ 减 2^32 */
/* @0x24d6e4 mov r0, r5 */
/* @0x24d6e8 stm r4, {r2, r3} */
/* @0x24d6ec add sp, sp, #16 */
/* @0x24d6f0 vpop {d8} */
/* @0x24d6f4 pop {r4, r5, r6, pc} */
/* @0x24d6f8 vmov d5, r2, r3 */
/* @0x24d6fc vldr d7, [pc, #36] */
/* @0x24d700 mov r0, r5 */
/* @0x24d704 vsub.f64 d5, d5, d7 —— 唯一的一条 vsub（无第二级取模） */
/* @0x24d708 vmov r2, r3, d5 */
/* @0x24d70c stm r4, {r2, r3} */
/* @0x24d710 add sp, sp, #16 */
/* @0x24d714 vpop {d8} */
/* @0x24d718 pop {r4, r5, r6, pc} */
/* ---- 段10：对齐 nop + literal pool（非指令，按规矩保留 objdump 写法）
 *   0x24d720/0x24d724 = 0x00000000/0x41e00000 → 2147483648.0 = 2^31（0x24d6c8 vldr d7,[pc,#80]）
 *   0x24d728/0x24d72c = 0x00000000/0x41f00000 → 4294967296.0 = 2^32（0x24d6fc vldr d7,[pc,#36]） ---- */
/* @0x24d71c nop  */
/* @0x24d720 andeq r0, r0, r0 */
/* @0x24d724 mvnmi r0, r0 */
/* @0x24d728 andeq r0, r0, r0 */
/* @0x24d72c mvnsmi r0, r0 */
