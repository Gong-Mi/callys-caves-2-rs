/* cally 逆向卡：FREE_RValue__Pre（原版 libyoyo.so，armv7）
 * @func 0xc0a7c 0xc1348  size 2256  564 条（函数体内无 literal pool、无栈 canary）
 * 级别: 正文（tag 1/2/3 三条释放链、数组容器布局、4 层内联 + 第 5 层真递归、
 *            与 _RefThing<char const*>::dec 的内联/调用关系全部解出；
 *            61 条静态死代码已定位；open 3 条见文末）
 * 符号: _Z16FREE_RValue__PreP6RValue → void FREE_RValue__Pre(RValue* rv)
 *
 * ── 调用契约 ────────────────────────────────────────────────────────
 *   rv 是任意 RValue 槽（不要求是栈顶）：全函数只碰 *rv、rv->tag，没有任何入参栈算术
 *   入口唯一的读：tag = [rv+0xc] & 0x00FFFFFF（ldr + bic，0xc0a7c / 0xc0a84）
 *   三分支：tag==2 → 数组（beq → 0xc0b20）、tag==3 → 指针/对象（→ 0xc0af0）、tag==1 → 字符串（→ 0xc0ab0）
 *   其余 tag（4/5/6/7/8/9/10/11/12/13/14）一条指令都不走，直接 add sp/pop 返回（0xc0aa8）
 *   ⇒ 调用方那套 (tag-1)&0x00FFFFFC==0 的门（DoPop/DoPush/DoAdd…）会把 tag 4 也放进来，
 *     但 tag 4 在顶层是纯 no-op：rv 一个字节都不动（与数组元素里的 tag 4 不同，见 段2）
 *
 * ── 段1 tag 1（字符串）：_RefThing<char const*> ──────────────────────
 *   rv->ptr = RefThing*（12 B：+0 char* text、+4 int count、+8 int len）
 *   A 路径（0xc0ab0）：ptr==0 → 只把 *rv 清 0（0xc0ae4）后返回
 *   B 路径：LOCK；n=--[rt+4]；n!=0 → UNLOCK，*rv 清 0，返回（0xc0ad8 / 0xc0ae4）
 *   C 路径（n==0 → 0xc0b78）：YYFree(rt->text)；text=0；len=0；
 *           LOCK；再 --[rt+4]（此时必然是 0，见 段5）；UNLOCK；operator delete(rt)；
 *           再 UNLOCK；*rv=0；返回
 *   ⇒ 不论引用是否仍在，tag 1 都把 *rv 清 0（与 tag 2 / tag 3 相反）
 *   ⇒ text 缓冲走 YYFree(0xcef90)，RefThing 本体走 operator delete(0x27d1d0)
 *
 * ── 段2 tag 2（数组）：容器对象 + chunk 表 ───────────────────────────
 *   rv->ptr = 容器对象（字段由本函数的读写宽度钉死，+0x08 与 +0 的语义与 DoDup 卡互证）：
 *     +0x00 int      refcount     （本函数 --；DoDup 拷贝时 ++）
 *     +0x04 Chunk*   chunks       （8 B 一项：{+0 int n; +4 RValue* elems}）
 *     +0x08 RValue*  holder       （回指持有它的那个 RValue 槽；DoDup「+8 空则回指」）
 *     +0x10 int      chunk_count  （chunk 表循环上界）
 *     +0x0c          本函数从未读（open 2）
 *   A 路径（ptr==0）：直接返回，*rv 不动
 *   B 路径（0xc0b34）：LOCK；n=--[c+0]；若 [c+8]==rv 则 [c+8]=0（只清指向自己的回指）；
 *           n>0 → add sp/pop 后尾跳 UNLOCK 返回，*rv 不动（0xc0b6c..0xc0b74 没有 str）
 *   C 路径（n<=0 → 0xc0bb0）：销毁全部内容，容器自己那把锁不再解开：
 *           对 i<[c+0x10]：n=[chunks[i]]、base=[chunks[i]+4]、end=base+n*16
 *             每个元素 RValue 按 tag 递归释放（tag 1/2/3 各自内联，tag 4 只清空不放）
 *             然后无条件把元素写成 {+0=0, +8=0, tag=5}（0xc0c2c..0xc0c38）
 *             YYStrFree(base)；[chunks[i]+4]=0
 *           YYStrFree(chunks)；[c+4]=0；YYStrFree(c)；*rv=0；解锁返回（0xc0cec..0xc0d14）
 *   ⇒ 数组的三处释放（元素块 / chunk 表 / 容器本体）全走 YYStrFree(0xdc414)，没有一处 delete
 *   ⇒ 元素门：((tag-1)&0x00FFFFFF)&~3==0 即 tag∈1..4（0xc0c54..0xc0c60），
 *     内层再按 tag 1/2/3 分，tag 4 落到「只清空」那一路
 *
 * ── 段3 tag 3（指针/对象）：条件性虚删除 ─────────────────────────────
 *   条件：([rv+8] & 8) != 0 且 rv->ptr != 0（0xc0af4..0xc0b08）
 *   动作：vt=*ptr；vt[1](ptr)（0xc0b0c..0xc0b14）——Itanium vtable 的 slot 1
 *   实证 slot1=D0（deleting destructor）：vtable 0x3eb728（typeinfo 0x3eb710 = "11Buffer_Fast"）
 *        的 [0]=0xc4bcc=_ZN11Buffer_FastD1Ev、[1]=0xc4bf4=_ZN11Buffer_FastD0Ev
 *   ⇒ 语义上等价 delete (obj*)ptr，但只在 +8 的 bit3 置位时发生
 *   ⇒ 不清 *rv、不清 bit3、不改 tag：同一槽再调一次就是第二次 delete（本函数不自保护）
 *   ⇒ 不参与引用计数：tag 3 的「计数」在对象自己身上，本函数完全不碰
 *   +8 的 bit3 由谁写、tag 3 装的是哪一类对象：open 1
 *
 * ── 段4 内联结构：4 层数组 + 第 5 层真递归 ───────────────────────────
 *   编译器把「数组 → 元素 → 元素的数组 → …」展开了 4 层，每层都是同一份模板：
 *     L0 本函数体                       tag1 0xc0ab0 / tag3 0xc0af0 / tag2 0xc0b20
 *     L1 0xc0b20..0xc0d14               元素 tag1 0xc0c80 / tag3 0xc0d18 / tag2 0xc0d48
 *     L2 0xc0d48..0xc0f20               元素 tag1 0xc0e98 / tag3 0xc0f24 / tag2 0xc0f4c
 *     L3 0xc0f4c..0xc1124               元素 tag1 0xc1094 / tag3 0xc1128 / tag2 0xc1150
 *     L4 0xc1150..0xc1274               元素不再展开：tag∈1..4 直接 bl 0xc0a7c（0xc122c）
 *   ⇒ 第 5 层数组重新进本函数：静态展开到此为止，递归深度只受调用栈限制
 *   ⇒ 每层都完整重做一遍「--refcount / 清 holder 回指 / 逐 chunk 逐元素释放 / 释放 chunk 表与容器」
 *     收尾分别 0xc0cec(L1)、0xc0efc(L2)、0xc10f8(L3)、0xc125c(L4)，指令同构
 *   寄存器约定：r10 恒 0（清载荷用）、r11 恒 5（写 tag=undefined），两者只在 0xc0bbc..0xc0bc8 设一次
 *
 * ── 段5 与 _RefThing<char const*>::dec(0xc09f8, 132 B) 的关系 ────────
 *   dec 本体：LOCK；if(--[this+4]) {UNLOCK; ret;} else {YYFree([this]); [this]=0; [this+8]=0;
 *             LOCK；--[this+4]（此时恒为 -1）；UNLOCK；delete this；UNLOCK；}
 *   本函数里它的两种形态：
 *     ① 顶层 tag1 归零链 0xc0b78..0xc0bac 是 dec 的逐指令内联副本（与 0xc0a20..0xc0a70 同构，
 *        只把 dec 第二次递减的 beq 目标换成本文件的死块 0xc12bc）
 *     ② out-of-line 调用还剩 4 条（0xc0dd0 / 0xc0fcc / 0xc129c / 0xc1330），但它们全部落在
 *        「二级递减」死块里，一条都到不了 —— 见 段6
 *   ⇒ 两者是同一份引用计数协议的两个编译产物；本函数把 dec 的字符串分支整段抄了进来，
 *     调用方（DoPop/DoPush/DoAdd…）看到的「tag1 走 _RefThing 计数 + YYFree + delete」就是这条链
 *   ⇒ 可达路径上一次也不调用 dec（4 条 bl dec 全在死块），生效的只有内联副本
 *
 * ── 段6 两个静态事实（可直接用反汇编/符号表复核）────────────────────
 *   ① LOCK_RVALUE_MUTEX(0x190f2c) 与 UNLOCK_RVALUE_MUTEX(0x190f30) 各 4 B、单条 bx lr
 *      ⇒ 本构建里 RVALUE 锁是空操作：本函数 14 处 LOCK / 14 处 UNLOCK 不产生任何同步，
 *        「持锁期间递归释放」也就没有递归锁问题；DoOperation 卡里「LOCK 保护」的措辞按此读
 *   ② 61 条指令（10.8%）静态不可达，四组「二级递减 ==0」分支：
 *        0xc0dbc..0xc0dd8（8）   0xc0fb8..0xc0fd4（8）
 *        0xc1288..0xc12a8（9）   0xc12bc..0xc1348（36）
 *      证法：每组的入口都是「首级递减先 str 0 到 [rt+4]（0xc0acc / 0xc0c9c / 0xc0eb0 / 0xc10ac）
 *      再 cmp → 进销毁块」，销毁块里重新 ldr [rt+4] 得 0，sub 后恒为 -1，
 *      故四个岔口的跳转方向恒定：0xc0b9c / 0xc11ac 的 beq 恒不成立，
 *      0xc0db8 / 0xc0fb4 的 bne 恒成立（两组等价的写法）
 *      ⇒ 副作用：RefThing 的 +4 在 delete 前被写成 -1，不是 0
 *
 * ── 已证（每条都指到指令）──────────────────────────────────────────
 *   1. 入口 (tag-1) 不分：只有 2/3/1 三条分支，其余 tag 直返且不碰 rv
 *      @0xc0a7c 取 tag、@0xc0a84 掩码、@0xc0a8c..@0xc0aa4 三条 beq、@0xc0aa8 直返
 *   2. tag1 的计数在 RefThing+4，归零才 YYFree(text)+delete；*rv 恒清 0
 *      @0xc0ac4..@0xc0ad4、@0xc0b78..@0xc0bac、@0xc0ae4（n!=0 路）与 @0xc0adc（ptr==0 路）
 *   3. tag2 容器字段：+0 计数、+4 chunk 表、+8 holder 回指、+0x10 chunk 数
 *      @0xc0b40..@0xc0b60、@0xc0bb4、@0xc0bd8..@0xc0bf4
 *   4. tag2 三处释放全走 YYStrFree：@0xc0ccc（元素块）、@0xc0cf8（chunk 表）、@0xc0d08（容器）
 *   5. 元素先释放、再无条件写 {+0=0,+8=0,tag=5}：@0xc0c2c / @0xc0c34 / @0xc0c38；门 @0xc0c54..@0xc0c60
 *   6. tag3 = (+8 bit3) && ptr → vt[1](ptr)，slot1=D0（0xc4bf4）由 vtable 0x3eb728 实证
 *      @0xc0af4..@0xc0b14
 *   7. 四层内联后改真递归：@0xc122c 唯一自调用；L2/L3/L4 入口 @0xc0d48 / @0xc0f4c / @0xc1150
 *   8. 61 条死代码、4 条 bl dec 全在死块：见 段6 的四组地址
 *   9. LOCK/UNLOCK 是单条 bx lr（0x190f2c / 0x190f30，functions.tsv 4119/4120 行 size=4）
 *
 * ── 结论 ────────────────────────────────────────────────────────────
 *   FREE_RValue__Pre 就是「按 tag 的引用释放」：1=RefThing 减计数、归零则 YYFree(text)+delete；
 *   2=数组容器减计数、归零则逐 chunk 逐元素递归释放再用 YYStrFree 拆三块；
 *   3=带 +8:bit3 许可的虚删除（vt[1]=D0）；其余 tag 一律 no-op。
 *   字符串分支是 _RefThing::dec 的内联副本，且可达路径上 dec 一次都没被调用。
 *   tag 1 恒清 *rv，tag 2 只在容器销毁时清，tag 3 从不清 —— 三种收尾不一致，调用方必须自己改 tag。
 *
 * ── open ────────────────────────────────────────────────────────────
 *   1. tag 3 的 rv+8 bit3 由谁置位、装的是哪一类对象没钉死（本函数只按 D0 删、不看类型）；
 *      重复调用造成二次 delete 是否原版 bug，静态侧无法判定（要靠运行期/调用方审计）。
 *   2. tag 2 容器的 +0x0c 字段本函数从未读；rv+8 除「tag2 当 holder 回指、tag3 的 bit3」之外
 *      其余位的语义未钉。
 *   3. tag 4 被所有调用方的门放进本函数却是纯 no-op（数组元素里还会被清成 tag5）——
 *      tag 4 的引用语义在哪里处理，未钉。
 */
/* ---- 入口：tag = [rv+0xc] & 0x00FFFFFF，三条 beq 分派 ---- */
/* @0xc0a7c ldr r3, [r0, #0xc] */
/* @0xc0a80 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc0a84 bic r3, r3, #-16777216 */
/* @0xc0a88 sub sp, sp, #92 */
/* @0xc0a8c cmp r3, #2 */
/* @0xc0a90 str r0, [sp, #0x2c] */
/* @0xc0a94 beq 0xc0b20 <_Z16FREE_RValue__PreP6RValue+0xa4> */
/* @0xc0a98 cmp r3, #3 */
/* @0xc0a9c beq 0xc0af0 <_Z16FREE_RValue__PreP6RValue+0x74> */
/* @0xc0aa0 cmp r3, #1 */
/* @0xc0aa4 beq 0xc0ab0 <_Z16FREE_RValue__PreP6RValue+0x34> */
/* @0xc0aa8 add sp, sp, #92 */
/* @0xc0aac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ---- tag1 字符串：RefThing 首级减计数（+4） ---- */
/* @0xc0ab0 ldr r2, [sp, #0x2c] */
/* @0xc0ab4 ldr r4, [r2] */
/* @0xc0ab8 cmp r4, #0 */
/* @0xc0abc beq 0xc0adc <_Z16FREE_RValue__PreP6RValue+0x60> */
/* @0xc0ac0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0ac4 ldr r5, [r4, #0x4] */
/* @0xc0ac8 sub r5, r5, #1 */
/* @0xc0acc str r5, [r4, #0x4] */
/* @0xc0ad0 cmp r5, #0 */
/* @0xc0ad4 beq 0xc0b78 <_Z16FREE_RValue__PreP6RValue+0xfc> */
/* @0xc0ad8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0adc ldr r1, [sp, #0x2c] */
/* @0xc0ae0 mov r3, #0 */
/* @0xc0ae4 str r3, [r1] */
/* @0xc0ae8 add sp, sp, #92 */
/* @0xc0aec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ---- tag3 指针：(+8 & 8) 门 + vtable[1] 删除 ---- */
/* @0xc0af0 ldr r1, [sp, #0x2c] */
/* @0xc0af4 ldr r3, [r1, #0x8] */
/* @0xc0af8 tst r3, #8 */
/* @0xc0afc beq 0xc0aa8 <_Z16FREE_RValue__PreP6RValue+0x2c> */
/* @0xc0b00 ldr r0, [r1] */
/* @0xc0b04 cmp r0, #0 */
/* @0xc0b08 beq 0xc0aa8 <_Z16FREE_RValue__PreP6RValue+0x2c> */
/* @0xc0b0c ldr r3, [r0] */
/* @0xc0b10 ldr r3, [r3, #0x4] */
/* @0xc0b14 blx r3 */
/* @0xc0b18 add sp, sp, #92 */
/* @0xc0b1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ---- tag2 数组：容器减计数 + holder 回指清除 ---- */
/* @0xc0b20 ldr r2, [sp, #0x2c] */
/* @0xc0b24 ldr r2, [r2] */
/* @0xc0b28 cmp r2, #0 */
/* @0xc0b2c str r2, [sp, #0x38] */
/* @0xc0b30 beq 0xc0aa8 <_Z16FREE_RValue__PreP6RValue+0x2c> */
/* @0xc0b34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0b38 ldr r3, [sp, #0x38] */
/* @0xc0b3c ldr r1, [sp, #0x2c] */
/* @0xc0b40 ldr r2, [r3, #0x8] */
/* @0xc0b44 ldr r3, [r3] */
/* @0xc0b48 cmp r2, r1 */
/* @0xc0b4c ldr r2, [sp, #0x38] */
/* @0xc0b50 sub r3, r3, #1 */
/* @0xc0b54 ldreq r1, [sp, #0x38] */
/* @0xc0b58 str r3, [r2] */
/* @0xc0b5c moveq r2, #0 */
/* @0xc0b60 streq r2, [r1, #0x8] */
/* @0xc0b64 cmp r3, #0 */
/* @0xc0b68 ble 0xc0bb0 <_Z16FREE_RValue__PreP6RValue+0x134> */
/* @0xc0b6c add sp, sp, #92 */
/* @0xc0b70 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc0b74 b 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* ---- tag1 归零链 = dec() 的逐指令内联副本（0xc0b9c 的 beq 目标 0xc12bc 是死块） ---- */
/* @0xc0b78 ldr r0, [r4] */
/* @0xc0b7c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0b80 str r5, [r4] */
/* @0xc0b84 str r5, [r4, #0x8] */
/* @0xc0b88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0b8c ldr r5, [r4, #0x4] */
/* @0xc0b90 sub r5, r5, #1 */
/* @0xc0b94 str r5, [r4, #0x4] */
/* @0xc0b98 cmp r5, #0 */
/* @0xc0b9c beq 0xc12bc <_Z16FREE_RValue__PreP6RValue+0x840> */
/* @0xc0ba0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0ba4 mov r0, r4 */
/* @0xc0ba8 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0bac b 0xc0ad8 <_Z16FREE_RValue__PreP6RValue+0x5c> */
/* ---- L1 容器销毁：chunk 表遍历起点 ---- */
/* @0xc0bb0 ldr r2, [sp, #0x38] */
/* @0xc0bb4 ldr r3, [r2, #0x10] */
/* @0xc0bb8 cmp r3, #0 */
/* @0xc0bbc movgt r3, #0 */
/* @0xc0bc0 movgt r11, #5 */
/* @0xc0bc4 strgt r3, [sp, #0x34] */
/* @0xc0bc8 movgt r10, r3 */
/* @0xc0bcc ble 0xc0cec <_Z16FREE_RValue__PreP6RValue+0x270> */
/* @0xc0bd0 ldr r1, [sp, #0x38] */
/* @0xc0bd4 ldr r2, [sp, #0x34] */
/* @0xc0bd8 ldr r3, [r1, #0x4] */
/* @0xc0bdc ldr r1, [sp, #0x34] */
/* @0xc0be0 add r2, r3, r2, lsl #3 */
/* @0xc0be4 str r2, [sp, #0x3c] */
/* @0xc0be8 ldr r3, [r3, r1, lsl #3] */
/* @0xc0bec ldr r2, [r2, #0x4] */
/* @0xc0bf0 add r3, r2, r3, lsl #4 */
/* @0xc0bf4 str r3, [sp, #0x18] */
/* @0xc0bf8 cmp r2, r3 */
/* @0xc0bfc str r2, [sp, #0x4] */
/* @0xc0c00 bhs 0xc12b4 <_Z16FREE_RValue__PreP6RValue+0x838> */
/* @0xc0c04 add r3, r2, #16 */
/* @0xc0c08 str r3, [sp, #0x8] */
/* @0xc0c0c str r3, [sp, #0xc] */
/* @0xc0c10 b 0xc0c4c <_Z16FREE_RValue__PreP6RValue+0x1d0> */
/* ---- L1 元素收尾：{+0=0,+8=0,tag=5} 后推进游标 ---- */
/* @0xc0c14 ldr r3, [sp, #0x18] */
/* @0xc0c18 ldr r1, [sp, #0x8] */
/* @0xc0c1c ldr r2, [sp, #0x4] */
/* @0xc0c20 cmp r3, r1 */
/* @0xc0c24 ldr r3, [sp, #0xc] */
/* @0xc0c28 str r1, [sp, #0x4] */
/* @0xc0c2c str r10, [r2, #0x8] */
/* @0xc0c30 add r3, r3, #16 */
/* @0xc0c34 str r11, [r2, #0xc] */
/* @0xc0c38 str r10, [r3, #-0x20] */
/* @0xc0c3c str r3, [sp, #0xc] */
/* @0xc0c40 bls 0xc0cb8 <_Z16FREE_RValue__PreP6RValue+0x23c> */
/* @0xc0c44 add r1, r1, #16 */
/* @0xc0c48 str r1, [sp, #0x8] */
/* ---- L1 元素 tag 门：((tag-1)&0x00FFFFFF)&~3 == 0 ---- */
/* @0xc0c4c ldr r1, [sp, #0x4] */
/* @0xc0c50 ldr r2, [r1, #0xc] */
/* @0xc0c54 sub r3, r2, #1 */
/* @0xc0c58 bic r3, r3, #-16777216 */
/* @0xc0c5c bics r4, r3, #3 */
/* @0xc0c60 bne 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0c64 bic r2, r2, #-16777216 */
/* @0xc0c68 cmp r2, #2 */
/* @0xc0c6c beq 0xc0d48 <_Z16FREE_RValue__PreP6RValue+0x2cc> */
/* @0xc0c70 cmp r2, #3 */
/* @0xc0c74 beq 0xc0d18 <_Z16FREE_RValue__PreP6RValue+0x29c> */
/* @0xc0c78 cmp r2, #1 */
/* @0xc0c7c bne 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* ---- L1 元素 tag1：RefThing 首级减计数 ---- */
/* @0xc0c80 ldr r1, [sp, #0xc] */
/* @0xc0c84 ldr r4, [r1, #-0x10] */
/* @0xc0c88 cmp r4, #0 */
/* @0xc0c8c beq 0xc0cac <_Z16FREE_RValue__PreP6RValue+0x230> */
/* @0xc0c90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0c94 ldr r5, [r4, #0x4] */
/* @0xc0c98 sub r5, r5, #1 */
/* @0xc0c9c str r5, [r4, #0x4] */
/* @0xc0ca0 cmp r5, #0 */
/* @0xc0ca4 beq 0xc0d94 <_Z16FREE_RValue__PreP6RValue+0x318> */
/* @0xc0ca8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0cac ldr r2, [sp, #0xc] */
/* @0xc0cb0 str r10, [r2, #-0x10] */
/* @0xc0cb4 b 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* ---- L1 chunk 收尾：YYStrFree(elems)，desc+4=0 ---- */
/* @0xc0cb8 ldr r2, [sp, #0x3c] */
/* @0xc0cbc ldr r0, [r2, #0x4] */
/* @0xc0cc0 ldr r3, [sp, #0x34] */
/* @0xc0cc4 add r3, r3, #1 */
/* @0xc0cc8 str r3, [sp, #0x34] */
/* @0xc0ccc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0cd0 ldr r1, [sp, #0x38] */
/* @0xc0cd4 ldr r2, [sp, #0x3c] */
/* @0xc0cd8 ldr r3, [r1, #0x10] */
/* @0xc0cdc ldr r1, [sp, #0x34] */
/* @0xc0ce0 str r10, [r2, #0x4] */
/* @0xc0ce4 cmp r3, r1 */
/* @0xc0ce8 bgt 0xc0bd0 <_Z16FREE_RValue__PreP6RValue+0x154> */
/* ---- L1 容器收尾：YYStrFree(chunk 表)、YYStrFree(容器)、*rv=0 ---- */
/* @0xc0cec ldr r3, [sp, #0x38] */
/* @0xc0cf0 mov r4, #0 */
/* @0xc0cf4 ldr r0, [r3, #0x4] */
/* @0xc0cf8 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0cfc ldr r1, [sp, #0x38] */
/* @0xc0d00 str r4, [r1, #0x4] */
/* @0xc0d04 mov r0, r1 */
/* @0xc0d08 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0d0c ldr r2, [sp, #0x2c] */
/* @0xc0d10 str r4, [r2] */
/* @0xc0d14 b 0xc0b6c <_Z16FREE_RValue__PreP6RValue+0xf0> */
/* ---- L1 元素 tag3：虚删除 ---- */
/* @0xc0d18 ldr r2, [sp, #0x4] */
/* @0xc0d1c ldr r3, [r2, #0x8] */
/* @0xc0d20 tst r3, #8 */
/* @0xc0d24 beq 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0d28 ldr r3, [sp, #0xc] */
/* @0xc0d2c ldr r0, [r3, #-0x10] */
/* @0xc0d30 cmp r0, #0 */
/* @0xc0d34 beq 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0d38 ldr r3, [r0] */
/* @0xc0d3c ldr r3, [r3, #0x4] */
/* @0xc0d40 blx r3 */
/* @0xc0d44 b 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* ---- L1 元素 tag2 → L2 容器 ---- */
/* @0xc0d48 ldr r3, [sp, #0xc] */
/* @0xc0d4c ldr r3, [r3, #-0x10] */
/* @0xc0d50 cmp r3, #0 */
/* @0xc0d54 str r3, [sp, #0x28] */
/* @0xc0d58 beq 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0d5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0d60 ldr r1, [sp, #0x28] */
/* @0xc0d64 ldr r2, [r1, #0x8] */
/* @0xc0d68 ldr r3, [r1] */
/* @0xc0d6c ldr r1, [sp, #0x4] */
/* @0xc0d70 sub r3, r3, #1 */
/* @0xc0d74 cmp r1, r2 */
/* @0xc0d78 ldr r2, [sp, #0x28] */
/* @0xc0d7c streq r4, [r2, #0x8] */
/* @0xc0d80 cmp r3, #0 */
/* @0xc0d84 str r3, [r2] */
/* @0xc0d88 ble 0xc0dec <_Z16FREE_RValue__PreP6RValue+0x370> */
/* @0xc0d8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0d90 b 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* ---- L1 元素 tag1 归零链（0xc0dbc..0xc0dd8 为死块，含 bl dec 0xc0dd0） ---- */
/* @0xc0d94 ldr r0, [r4] */
/* @0xc0d98 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0d9c str r5, [r4] */
/* @0xc0da0 str r5, [r4, #0x8] */
/* @0xc0da4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0da8 ldr r5, [r4, #0x4] */
/* @0xc0dac sub r5, r5, #1 */
/* @0xc0db0 str r5, [r4, #0x4] */
/* @0xc0db4 cmp r5, #0 */
/* @0xc0db8 bne 0xc0ddc <_Z16FREE_RValue__PreP6RValue+0x360> */
/* @0xc0dbc ldr r0, [r4] */
/* @0xc0dc0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0dc4 mov r0, r4 */
/* @0xc0dc8 str r5, [r4] */
/* @0xc0dcc str r5, [r4, #0x8] */
/* @0xc0dd0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc0dd4 mov r0, r4 */
/* @0xc0dd8 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0ddc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0de0 mov r0, r4 */
/* @0xc0de4 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0de8 b 0xc0ca8 <_Z16FREE_RValue__PreP6RValue+0x22c> */
/* ---- L2 容器销毁：chunk 遍历 ---- */
/* @0xc0dec ldr r1, [sp, #0x28] */
/* @0xc0df0 ldr r3, [r1, #0x10] */
/* @0xc0df4 cmp r3, #0 */
/* @0xc0df8 movgt r2, #0 */
/* @0xc0dfc strgt r2, [sp, #0x24] */
/* @0xc0e00 ble 0xc0efc <_Z16FREE_RValue__PreP6RValue+0x480> */
/* @0xc0e04 ldr r1, [sp, #0x28] */
/* @0xc0e08 ldr r2, [sp, #0x24] */
/* @0xc0e0c ldr r3, [r1, #0x4] */
/* @0xc0e10 ldr r1, [sp, #0x24] */
/* @0xc0e14 add r2, r3, r2, lsl #3 */
/* @0xc0e18 str r2, [sp, #0x30] */
/* @0xc0e1c ldr r3, [r3, r1, lsl #3] */
/* @0xc0e20 ldr r8, [r2, #0x4] */
/* @0xc0e24 add r3, r8, r3, lsl #4 */
/* @0xc0e28 str r3, [sp, #0x10] */
/* @0xc0e2c cmp r8, r3 */
/* @0xc0e30 bhs 0xc12ac <_Z16FREE_RValue__PreP6RValue+0x830> */
/* @0xc0e34 add r7, r8, #16 */
/* @0xc0e38 mov r9, r8 */
/* @0xc0e3c mov r8, r7 */
/* @0xc0e40 b 0xc0e68 <_Z16FREE_RValue__PreP6RValue+0x3ec> */
/* ---- L2 元素收尾 + 游标推进 ---- */
/* @0xc0e44 ldr r2, [sp, #0x10] */
/* @0xc0e48 add r8, r8, #16 */
/* @0xc0e4c str r10, [r9, #0x8] */
/* @0xc0e50 cmp r2, r7 */
/* @0xc0e54 str r11, [r9, #0xc] */
/* @0xc0e58 str r10, [r8, #-0x20] */
/* @0xc0e5c mov r9, r7 */
/* @0xc0e60 bls 0xc0ec8 <_Z16FREE_RValue__PreP6RValue+0x44c> */
/* @0xc0e64 add r7, r7, #16 */
/* @0xc0e68 ldr r2, [r9, #0xc] */
/* @0xc0e6c sub r3, r2, #1 */
/* @0xc0e70 bic r3, r3, #-16777216 */
/* @0xc0e74 bics r4, r3, #3 */
/* @0xc0e78 bne 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* ---- L2 元素 tag 分派 ---- */
/* @0xc0e7c bic r2, r2, #-16777216 */
/* @0xc0e80 cmp r2, #2 */
/* @0xc0e84 beq 0xc0f4c <_Z16FREE_RValue__PreP6RValue+0x4d0> */
/* @0xc0e88 cmp r2, #3 */
/* @0xc0e8c beq 0xc0f24 <_Z16FREE_RValue__PreP6RValue+0x4a8> */
/* @0xc0e90 cmp r2, #1 */
/* @0xc0e94 bne 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* ---- L2 元素 tag1 ---- */
/* @0xc0e98 ldr r4, [r8, #-0x10] */
/* @0xc0e9c cmp r4, #0 */
/* @0xc0ea0 beq 0xc0ec0 <_Z16FREE_RValue__PreP6RValue+0x444> */
/* @0xc0ea4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0ea8 ldr r5, [r4, #0x4] */
/* @0xc0eac sub r5, r5, #1 */
/* @0xc0eb0 str r5, [r4, #0x4] */
/* @0xc0eb4 cmp r5, #0 */
/* @0xc0eb8 beq 0xc0f90 <_Z16FREE_RValue__PreP6RValue+0x514> */
/* @0xc0ebc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0ec0 str r10, [r8, #-0x10] */
/* @0xc0ec4 b 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* ---- L2 chunk 收尾 ---- */
/* @0xc0ec8 ldr r3, [sp, #0x30] */
/* @0xc0ecc ldr r0, [r3, #0x4] */
/* @0xc0ed0 ldr r1, [sp, #0x24] */
/* @0xc0ed4 add r1, r1, #1 */
/* @0xc0ed8 str r1, [sp, #0x24] */
/* @0xc0edc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0ee0 ldr r2, [sp, #0x28] */
/* @0xc0ee4 ldr r1, [sp, #0x30] */
/* @0xc0ee8 ldr r3, [r2, #0x10] */
/* @0xc0eec ldr r2, [sp, #0x24] */
/* @0xc0ef0 str r10, [r1, #0x4] */
/* @0xc0ef4 cmp r2, r3 */
/* @0xc0ef8 blt 0xc0e04 <_Z16FREE_RValue__PreP6RValue+0x388> */
/* ---- L2 容器收尾 ---- */
/* @0xc0efc ldr r2, [sp, #0x28] */
/* @0xc0f00 ldr r0, [r2, #0x4] */
/* @0xc0f04 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0f08 ldr r3, [sp, #0x28] */
/* @0xc0f0c str r10, [r3, #0x4] */
/* @0xc0f10 mov r0, r3 */
/* @0xc0f14 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0f18 ldr r1, [sp, #0xc] */
/* @0xc0f1c str r10, [r1, #-0x10] */
/* @0xc0f20 b 0xc0d8c <_Z16FREE_RValue__PreP6RValue+0x310> */
/* ---- L2 元素 tag3 ---- */
/* @0xc0f24 ldr r3, [r9, #0x8] */
/* @0xc0f28 tst r3, #8 */
/* @0xc0f2c beq 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0f30 ldr r0, [r8, #-0x10] */
/* @0xc0f34 cmp r0, #0 */
/* @0xc0f38 beq 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0f3c ldr r3, [r0] */
/* @0xc0f40 ldr r3, [r3, #0x4] */
/* @0xc0f44 blx r3 */
/* @0xc0f48 b 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* ---- L2 元素 tag2 → L3 容器 ---- */
/* @0xc0f4c ldr r2, [r8, #-0x10] */
/* @0xc0f50 cmp r2, #0 */
/* @0xc0f54 str r2, [sp, #0x1c] */
/* @0xc0f58 beq 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0f5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0f60 ldr r3, [sp, #0x1c] */
/* @0xc0f64 ldr r1, [sp, #0x1c] */
/* @0xc0f68 ldr r2, [r3, #0x8] */
/* @0xc0f6c ldr r3, [r3] */
/* @0xc0f70 cmp r9, r2 */
/* @0xc0f74 streq r4, [r1, #0x8] */
/* @0xc0f78 sub r3, r3, #1 */
/* @0xc0f7c str r3, [r1] */
/* @0xc0f80 cmp r3, #0 */
/* @0xc0f84 ble 0xc0fe8 <_Z16FREE_RValue__PreP6RValue+0x56c> */
/* @0xc0f88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0f8c b 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* ---- L2 元素 tag1 归零链（死块 0xc0fb8..0xc0fd4，含 bl dec 0xc0fcc） ---- */
/* @0xc0f90 ldr r0, [r4] */
/* @0xc0f94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0f98 str r5, [r4] */
/* @0xc0f9c str r5, [r4, #0x8] */
/* @0xc0fa0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0fa4 ldr r5, [r4, #0x4] */
/* @0xc0fa8 sub r5, r5, #1 */
/* @0xc0fac str r5, [r4, #0x4] */
/* @0xc0fb0 cmp r5, #0 */
/* @0xc0fb4 bne 0xc0fd8 <_Z16FREE_RValue__PreP6RValue+0x55c> */
/* @0xc0fb8 ldr r0, [r4] */
/* @0xc0fbc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0fc0 mov r0, r4 */
/* @0xc0fc4 str r5, [r4] */
/* @0xc0fc8 str r5, [r4, #0x8] */
/* @0xc0fcc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc0fd0 mov r0, r4 */
/* @0xc0fd4 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0fd8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0fdc mov r0, r4 */
/* @0xc0fe0 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0fe4 b 0xc0ebc <_Z16FREE_RValue__PreP6RValue+0x440> */
/* ---- L3 容器销毁 ---- */
/* @0xc0fe8 ldr r2, [sp, #0x1c] */
/* @0xc0fec ldr r3, [r2, #0x10] */
/* @0xc0ff0 cmp r3, #0 */
/* @0xc0ff4 ble 0xc1104 <_Z16FREE_RValue__PreP6RValue+0x688> */
/* @0xc0ff8 mov r2, #0 */
/* @0xc0ffc str r9, [sp, #0x4c] */
/* @0xc1000 str r2, [sp, #0x14] */
/* @0xc1004 str r8, [sp, #0x50] */
/* @0xc1008 str r7, [sp, #0x54] */
/* @0xc100c ldr r1, [sp, #0x1c] */
/* @0xc1010 ldr r2, [sp, #0x14] */
/* @0xc1014 ldr r3, [r1, #0x4] */
/* @0xc1018 ldr r1, [sp, #0x14] */
/* @0xc101c add r2, r3, r2, lsl #3 */
/* @0xc1020 str r2, [sp, #0x20] */
/* @0xc1024 ldr r5, [r3, r1, lsl #3] */
/* @0xc1028 ldr r9, [r2, #0x4] */
/* @0xc102c add r5, r9, r5, lsl #4 */
/* @0xc1030 cmp r9, r5 */
/* @0xc1034 bhs 0xc1280 <_Z16FREE_RValue__PreP6RValue+0x804> */
/* @0xc1038 add r7, r9, #16 */
/* @0xc103c mov r8, r7 */
/* @0xc1040 b 0xc1064 <_Z16FREE_RValue__PreP6RValue+0x5e8> */
/* ---- L3 元素收尾 ---- */
/* @0xc1044 cmp r5, r7 */
/* @0xc1048 str r10, [r9, #0x8] */
/* @0xc104c str r11, [r9, #0xc] */
/* @0xc1050 add r8, r8, #16 */
/* @0xc1054 str r10, [r8, #-0x20] */
/* @0xc1058 mov r9, r7 */
/* @0xc105c bls 0xc10c4 <_Z16FREE_RValue__PreP6RValue+0x648> */
/* @0xc1060 add r7, r7, #16 */
/* @0xc1064 ldr r0, [r9, #0xc] */
/* @0xc1068 sub r1, r0, #1 */
/* @0xc106c bic r1, r1, #-16777216 */
/* @0xc1070 bics r4, r1, #3 */
/* @0xc1074 bne 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* ---- L3 元素 tag 分派 ---- */
/* @0xc1078 bic r0, r0, #-16777216 */
/* @0xc107c cmp r0, #2 */
/* @0xc1080 beq 0xc1150 <_Z16FREE_RValue__PreP6RValue+0x6d4> */
/* @0xc1084 cmp r0, #3 */
/* @0xc1088 beq 0xc1128 <_Z16FREE_RValue__PreP6RValue+0x6ac> */
/* @0xc108c cmp r0, #1 */
/* @0xc1090 bne 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* ---- L3 元素 tag1 ---- */
/* @0xc1094 ldr r4, [r8, #-0x10] */
/* @0xc1098 cmp r4, #0 */
/* @0xc109c beq 0xc10bc <_Z16FREE_RValue__PreP6RValue+0x640> */
/* @0xc10a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc10a4 ldr r6, [r4, #0x4] */
/* @0xc10a8 sub r6, r6, #1 */
/* @0xc10ac str r6, [r4, #0x4] */
/* @0xc10b0 cmp r6, #0 */
/* @0xc10b4 beq 0xc1188 <_Z16FREE_RValue__PreP6RValue+0x70c> */
/* @0xc10b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc10bc str r10, [r8, #-0x10] */
/* @0xc10c0 b 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* ---- L3 chunk 收尾 ---- */
/* @0xc10c4 ldr r2, [sp, #0x20] */
/* @0xc10c8 ldr r0, [r2, #0x4] */
/* @0xc10cc ldr r3, [sp, #0x14] */
/* @0xc10d0 add r3, r3, #1 */
/* @0xc10d4 str r3, [sp, #0x14] */
/* @0xc10d8 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc10dc ldr r1, [sp, #0x1c] */
/* @0xc10e0 ldr r2, [sp, #0x20] */
/* @0xc10e4 ldr r3, [r1, #0x10] */
/* @0xc10e8 ldr r1, [sp, #0x14] */
/* @0xc10ec str r10, [r2, #0x4] */
/* @0xc10f0 cmp r1, r3 */
/* @0xc10f4 blt 0xc100c <_Z16FREE_RValue__PreP6RValue+0x590> */
/* ---- L3 容器收尾（恢复 r9/r8/r7 溢出槽） ---- */
/* @0xc10f8 ldr r9, [sp, #0x4c] */
/* @0xc10fc ldr r8, [sp, #0x50] */
/* @0xc1100 ldr r7, [sp, #0x54] */
/* @0xc1104 ldr r3, [sp, #0x1c] */
/* @0xc1108 ldr r0, [r3, #0x4] */
/* @0xc110c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1110 ldr r1, [sp, #0x1c] */
/* @0xc1114 str r10, [r1, #0x4] */
/* @0xc1118 mov r0, r1 */
/* @0xc111c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1120 str r10, [r8, #-0x10] */
/* @0xc1124 b 0xc0f88 <_Z16FREE_RValue__PreP6RValue+0x50c> */
/* ---- L3 元素 tag3 ---- */
/* @0xc1128 ldr r1, [r9, #0x8] */
/* @0xc112c tst r1, #8 */
/* @0xc1130 beq 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1134 ldr r0, [r8, #-0x10] */
/* @0xc1138 cmp r0, #0 */
/* @0xc113c beq 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1140 ldr r1, [r0] */
/* @0xc1144 ldr r1, [r1, #0x4] */
/* @0xc1148 blx r1 */
/* @0xc114c b 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* ---- L3 元素 tag2 → L4 容器 ---- */
/* @0xc1150 ldr r6, [r8, #-0x10] */
/* @0xc1154 cmp r6, #0 */
/* @0xc1158 beq 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc115c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1160 ldr r1, [r6] */
/* @0xc1164 ldr r0, [r6, #0x8] */
/* @0xc1168 sub r1, r1, #1 */
/* @0xc116c str r1, [r6] */
/* @0xc1170 cmp r9, r0 */
/* @0xc1174 streq r4, [r6, #0x8] */
/* @0xc1178 cmp r1, #0 */
/* @0xc117c ble 0xc11c0 <_Z16FREE_RValue__PreP6RValue+0x744> */
/* @0xc1180 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1184 b 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1188 ldr r0, [r4] */
/* @0xc118c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1190 str r6, [r4] */
/* @0xc1194 str r6, [r4, #0x8] */
/* @0xc1198 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc119c ldr r6, [r4, #0x4] */
/* @0xc11a0 sub r6, r6, #1 */
/* @0xc11a4 str r6, [r4, #0x4] */
/* @0xc11a8 cmp r6, #0 */
/* @0xc11ac beq 0xc1288 <_Z16FREE_RValue__PreP6RValue+0x80c> */
/* @0xc11b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc11b4 mov r0, r4 */
/* @0xc11b8 bl 0x27d1d0 <_ZdlPv> */
/* @0xc11bc b 0xc10b8 <_Z16FREE_RValue__PreP6RValue+0x63c> */
/* ---- L4 容器销毁：元素不再展开 ---- */
/* @0xc11c0 ldr r1, [r6, #0x10] */
/* @0xc11c4 cmp r1, #0 */
/* @0xc11c8 strgt r5, [sp, #0x40] */
/* @0xc11cc strgt r8, [sp, #0x44] */
/* @0xc11d0 movgt r4, #0 */
/* @0xc11d4 strgt r7, [sp, #0x48] */
/* @0xc11d8 ble 0xc125c <_Z16FREE_RValue__PreP6RValue+0x7e0> */
/* @0xc11dc ldr r3, [r6, #0x4] */
/* @0xc11e0 add r5, r3, r4, lsl #3 */
/* @0xc11e4 ldr r1, [r3, r4, lsl #3] */
/* @0xc11e8 ldr r7, [r5, #0x4] */
/* @0xc11ec add r8, r7, r1, lsl #4 */
/* @0xc11f0 cmp r7, r8 */
/* @0xc11f4 blo 0xc1210 <_Z16FREE_RValue__PreP6RValue+0x794> */
/* @0xc11f8 b 0xc1278 <_Z16FREE_RValue__PreP6RValue+0x7fc> */
/* @0xc11fc str r10, [r7, #0x8] */
/* @0xc1200 str r11, [r7, #0xc] */
/* @0xc1204 str r10, [r7], #16 */
/* @0xc1208 cmp r8, r7 */
/* @0xc120c bls 0xc1234 <_Z16FREE_RValue__PreP6RValue+0x7b8> */
/* ---- L4 元素：tag∈1..4 → bl FREE_RValue__Pre（全函数唯一自调用） ---- */
/* @0xc1210 ldr r3, [r7, #0xc] */
/* @0xc1214 sub r3, r3, #1 */
/* @0xc1218 bic r3, r3, #-16777216 */
/* @0xc121c bic r3, r3, #3 */
/* @0xc1220 cmp r3, #0 */
/* @0xc1224 bne 0xc11fc <_Z16FREE_RValue__PreP6RValue+0x780> */
/* @0xc1228 mov r0, r7 */
/* @0xc122c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1230 b 0xc11fc <_Z16FREE_RValue__PreP6RValue+0x780> */
/* ---- L4 chunk 收尾 ---- */
/* @0xc1234 ldr r0, [r5, #0x4] */
/* @0xc1238 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc123c ldr r3, [r6, #0x10] */
/* @0xc1240 add r4, r4, #1 */
/* @0xc1244 str r10, [r5, #0x4] */
/* @0xc1248 cmp r4, r3 */
/* @0xc124c blt 0xc11dc <_Z16FREE_RValue__PreP6RValue+0x760> */
/* @0xc1250 ldr r5, [sp, #0x40] */
/* @0xc1254 ldr r8, [sp, #0x44] */
/* @0xc1258 ldr r7, [sp, #0x48] */
/* ---- L4 容器收尾 ---- */
/* @0xc125c ldr r0, [r6, #0x4] */
/* @0xc1260 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1264 str r10, [r6, #0x4] */
/* @0xc1268 mov r0, r6 */
/* @0xc126c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1270 str r10, [r8, #-0x10] */
/* @0xc1274 b 0xc1180 <_Z16FREE_RValue__PreP6RValue+0x704> */
/* ---- L4 空 chunk 跳板 ---- */
/* @0xc1278 mov r0, r7 */
/* @0xc127c b 0xc1238 <_Z16FREE_RValue__PreP6RValue+0x7bc> */
/* @0xc1280 mov r0, r9 */
/* @0xc1284 b 0xc10cc <_Z16FREE_RValue__PreP6RValue+0x650> */
/* ---- 死块：L3 二级递减的 ==0 分支（入口 0xc11ac 恒不成立，含 bl dec 0xc129c） ---- */
/* @0xc1288 ldr r0, [r4] */
/* @0xc128c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1290 mov r0, r4 */
/* @0xc1294 str r6, [r4] */
/* @0xc1298 str r6, [r4, #0x8] */
/* @0xc129c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc12a0 mov r0, r4 */
/* @0xc12a4 bl 0x27d1d0 <_ZdlPv> */
/* @0xc12a8 b 0xc11b0 <_Z16FREE_RValue__PreP6RValue+0x734> */
/* ---- 空 chunk 跳板（L1/L2 共用） ---- */
/* @0xc12ac mov r0, r8 */
/* @0xc12b0 b 0xc0ed0 <_Z16FREE_RValue__PreP6RValue+0x454> */
/* @0xc12b4 ldr r0, [sp, #0x4] */
/* @0xc12b8 b 0xc0cc0 <_Z16FREE_RValue__PreP6RValue+0x244> */
/* ---- 死块：L0 二级递减 + dec 自递归残留，共 36 条（含 bl dec 0xc1330） ---- */
/* @0xc12bc ldr r0, [r4] */
/* @0xc12c0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc12c4 str r5, [r4] */
/* @0xc12c8 str r5, [r4, #0x8] */
/* @0xc12cc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc12d0 ldr r5, [r4, #0x4] */
/* @0xc12d4 sub r5, r5, #1 */
/* @0xc12d8 str r5, [r4, #0x4] */
/* @0xc12dc cmp r5, #0 */
/* @0xc12e0 beq 0xc12f4 <_Z16FREE_RValue__PreP6RValue+0x878> */
/* @0xc12e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc12e8 mov r0, r4 */
/* @0xc12ec bl 0x27d1d0 <_ZdlPv> */
/* @0xc12f0 b 0xc0ba0 <_Z16FREE_RValue__PreP6RValue+0x124> */
/* @0xc12f4 ldr r0, [r4] */
/* @0xc12f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc12fc str r5, [r4] */
/* @0xc1300 str r5, [r4, #0x8] */
/* @0xc1304 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1308 ldr r5, [r4, #0x4] */
/* @0xc130c sub r5, r5, #1 */
/* @0xc1310 str r5, [r4, #0x4] */
/* @0xc1314 cmp r5, #0 */
/* @0xc1318 bne 0xc133c <_Z16FREE_RValue__PreP6RValue+0x8c0> */
/* @0xc131c ldr r0, [r4] */
/* @0xc1320 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1324 mov r0, r4 */
/* @0xc1328 str r5, [r4] */
/* @0xc132c str r5, [r4, #0x8] */
/* @0xc1330 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc1334 mov r0, r4 */
/* @0xc1338 bl 0x27d1d0 <_ZdlPv> */
/* @0xc133c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1340 mov r0, r4 */
/* @0xc1344 bl 0x27d1d0 <_ZdlPv> */
/* @0xc1348 b 0xc12e4 <_Z16FREE_RValue__PreP6RValue+0x868> */
