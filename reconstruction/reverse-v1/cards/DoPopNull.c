/* cally 逆向卡：DoPopNull（原版 libyoyo.so，armv7）
 * @func 0xe61b4 0xe6364  size 432  108 条指令（含尾部 literal 词）
 * 级别: 正文（分派、三种宽度、null 填充、两条引用释放链已证；kind6 的对象归属与重复 UNLOCK 未钉）
 * 符号: _Z9DoPopNulljPhPKhP6VMExec → uchar* DoPopNull(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   r4 = sp，r5 = base；kind = (arg>>16)&0xF；(arg>>24)==0xFF → 转
 *       DoBreak(arg, (uchar)(arg>>16), sp, base, exec, true) 并把它返回的 r0 当新 sp（e61bc..e62a4）
 *   kind 表 T1（e61dc addls，limit 6，base=e61e4）：
 *       0→e6234 sp+8；1→e6228 sp+4；2→e6228 sp+4；3→e6234 sp+8；4→e6228 sp+4；
 *       5→e6240（写 null RValue 后 sp+16）；6→e6200（释放 *(void**)sp 后 sp+4）；
 *       7..15 → e6358 返回 sp 不变
 *   宽度表与 DoAdd/DoDup 的存储类表一致：0/3=8 B、1/2/4=4 B、5=16 B RValue、6=4 B 串指针
 *   kind5（e6240）：tag = [sp+0xc]；tag&0x00FFFFFF==0xFFFFFF → JSThrowReferenceError
 *       "DoPopNull : Could not find variable"（e62ec，之后重读 tag 继续）；
 *       (tag-1)&0x00FFFFFC==0 → 先 FREE_RValue__Pre(sp)（e62a8）；然后 +0=0、+8=0、+12=5，str [r0],#16，返回 sp+16
 *       （e626c..e6284）——注意 +4 不清
 *   kind6（e6200）：p = *(void**)sp；p==0 直接 sp+4；否则 LOCK_RVALUE_MUTEX → --[p+4] → 归零则
 *       YYFree([p]) + 清 p+0/p+8 + _RefThing<const char*>::dec + operator delete；非零则 UNLOCK 后 sp+4
 *       （e620c..e62e8；销毁链里 UNLOCK/delete 出现重复调用，是内联引用释放模板的产物）
 *
 * 结论（新增两条硬事实）：
 *   1. DoPopNull 的 kind 就是 DoAdd/DoDup 那张存储类表：0/3=8 B、1/2/4=4 B、5=16 B RValue、6=4 B 带引用计数串；
 *      >6 一律当"无需动作"，原样返回 sp。
 *   2. 只有 kind5 会真的"填 null"：把 +12 的 tag 换成 5（undefined）、清 +0/+8 后返回 sp+16，
 *      即被弹出的那个 16 B RValue 槽留下一个 undefined —— 这就是 PopNull 的字面行为；
 *      1/2/4/6 只是把 sp 抬高（6 顺带减引用），不写任何值。
 *
 * 尾部 e6360 是 literal pool（objdump 译成 eoreq），非指令；按 objdump 原样保留。
 *
 * open：
 *   · 为什么 4/8 B 的 kind 只挪 sp 不清理（裸类型槽没有 tag，本来就没东西可清）；
 *   · kind6 释放的对象到底是 YYString（+0 buf / +4 count / +8 len）还是 _RefThing<const char*>（+0 count / +8 回指）：
 *     销毁链同时出现 YYFree([p])、_RefThing::dec 与两次 operator delete，两种布局都能对上；
 *   · 销毁链里 UNLOCK/delete 重复出现（e62dc/e62e8/e6348/e6354）是否说明部分块与相邻函数共享；
 *   · DoBreak 的返回约定（这里直接把 DoBreak 的 r0 当新 sp 交回调用者）；
 *   · 8 B / 4 B 返回值的栈语义：是"弹掉若干个值"还是"跳过 N 字节参数区"。
 *
 * ── 本批补证：弹出并判空（逐条锚在下方）──
 *   YYFree ×3 / operator delete ×3 释放栈顶；LOCK/UNLOCK ×3 空桩；内含 bl DoBreak ×1
 *   open 1 判空的判据（tag 还是指针）
 *   open 2 为何这里会触发 DoBreak
 */
/* @0xe61b4 push {r4, r5, r6, lr} */
/* @0xe61b8 mov r4, r1 */
/* @0xe61bc lsr r1, r0, #24 */
/* @0xe61c0 sub sp, sp, #8 */
/* @0xe61c4 cmp r1, #255 */
/* @0xe61c8 mov r5, r2 */
/* @0xe61cc lsr r1, r0, #16 */
/* @0xe61d0 beq 0xe6288 <_Z9DoPopNulljPhPKhP6VMExec+0xd4> */
/* @0xe61d4 and r12, r1, #15 */
/* @0xe61d8 cmp r12, #6 */
/* @0xe61dc addls pc, pc, r12, lsl #2 */
/* @0xe61e0 b 0xe6358 <_Z9DoPopNulljPhPKhP6VMExec+0x1a4> */
/* @0xe61e4 b 0xe6234 <_Z9DoPopNulljPhPKhP6VMExec+0x80> */
/* @0xe61e8 b 0xe6228 <_Z9DoPopNulljPhPKhP6VMExec+0x74> */
/* @0xe61ec b 0xe6228 <_Z9DoPopNulljPhPKhP6VMExec+0x74> */
/* @0xe61f0 b 0xe6234 <_Z9DoPopNulljPhPKhP6VMExec+0x80> */
/* @0xe61f4 b 0xe6228 <_Z9DoPopNulljPhPKhP6VMExec+0x74> */
/* @0xe61f8 b 0xe6240 <_Z9DoPopNulljPhPKhP6VMExec+0x8c> */
/* @0xe61fc b 0xe6200 <_Z9DoPopNulljPhPKhP6VMExec+0x4c> */
/* @0xe6200 ldr r5, [r4] */
/* @0xe6204 cmp r5, #0 */
/* @0xe6208 beq 0xe6228 <_Z9DoPopNulljPhPKhP6VMExec+0x74> */
/* @0xe620c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe6210 ldr r6, [r5, #0x4] */
/* @0xe6214 sub r6, r6, #1 */
/* @0xe6218 str r6, [r5, #0x4] */
/* @0xe621c cmp r6, #0 */
/* @0xe6220 beq 0xe62b4 <_Z9DoPopNulljPhPKhP6VMExec+0x100> */
/* @0xe6224 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe6228 add r0, r4, #4 */
/* @0xe622c add sp, sp, #8 */
/* @0xe6230 pop {r4, r5, r6, pc} */
/* @0xe6234 add r0, r4, #8 */
/* @0xe6238 add sp, sp, #8 */
/* @0xe623c pop {r4, r5, r6, pc} */
/* @0xe6240 ldr r3, [r4, #0xc] */
/* @0xe6244 mvn r2, #-16777216 */
/* @0xe6248 and r1, r3, r2 */
/* @0xe624c cmp r1, r2 */
/* @0xe6250 beq 0xe62ec <_Z9DoPopNulljPhPKhP6VMExec+0x138> */
/* @0xe6254 sub r3, r3, #1 */
/* @0xe6258 bic r3, r3, #-16777216 */
/* @0xe625c bic r3, r3, #3 */
/* @0xe6260 cmp r3, #0 */
/* @0xe6264 beq 0xe62a8 <_Z9DoPopNulljPhPKhP6VMExec+0xf4> */
/* @0xe6268 mov r0, r4 */
/* @0xe626c mov r3, #0 */
/* @0xe6270 mov r2, #5 */
/* @0xe6274 str r3, [r4, #0x8] */
/* @0xe6278 str r2, [r4, #0xc] */
/* @0xe627c str r3, [r0], #16 */
/* @0xe6280 add sp, sp, #8 */
/* @0xe6284 pop {r4, r5, r6, pc} */
/* @0xe6288 str r3, [sp] */
/* @0xe628c mov r12, #1 */
/* @0xe6290 uxtb r1, r1 */
/* @0xe6294 mov r2, r4 */
/* @0xe6298 mov r3, r5 */
/* @0xe629c str r12, [sp, #0x4] */
/* @0xe62a0 bl 0xd8434 <_Z7DoBreakjhPhPKhP6VMExecb> */
/* @0xe62a4 b 0xe622c <_Z9DoPopNulljPhPKhP6VMExec+0x78> */
/* @0xe62a8 mov r0, r4 */
/* @0xe62ac bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe62b0 b 0xe6268 <_Z9DoPopNulljPhPKhP6VMExec+0xb4> */
/* @0xe62b4 ldr r0, [r5] */
/* @0xe62b8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe62bc str r6, [r5] */
/* @0xe62c0 str r6, [r5, #0x8] */
/* @0xe62c4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe62c8 ldr r6, [r5, #0x4] */
/* @0xe62cc sub r6, r6, #1 */
/* @0xe62d0 str r6, [r5, #0x4] */
/* @0xe62d4 cmp r6, #0 */
/* @0xe62d8 beq 0xe6300 <_Z9DoPopNulljPhPKhP6VMExec+0x14c> */
/* @0xe62dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe62e0 mov r0, r5 */
/* @0xe62e4 bl 0x27d1d0 <_ZdlPv> */
/* @0xe62e8 b 0xe6224 <_Z9DoPopNulljPhPKhP6VMExec+0x70> */
/* @0xe62ec ldr r0, [pc, #0x6c] */
/* @0xe62f0 add r0, pc, r0 */
/* @0xe62f4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe62f8 ldr r3, [r4, #0xc] */
/* @0xe62fc b 0xe6254 <_Z9DoPopNulljPhPKhP6VMExec+0xa0> */
/* @0xe6300 ldr r0, [r5] */
/* @0xe6304 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe6308 str r6, [r5] */
/* @0xe630c str r6, [r5, #0x8] */
/* @0xe6310 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe6314 ldr r6, [r5, #0x4] */
/* @0xe6318 sub r6, r6, #1 */
/* @0xe631c str r6, [r5, #0x4] */
/* @0xe6320 cmp r6, #0 */
/* @0xe6324 bne 0xe6348 <_Z9DoPopNulljPhPKhP6VMExec+0x194> */
/* @0xe6328 ldr r0, [r5] */
/* @0xe632c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe6330 mov r0, r5 */
/* @0xe6334 str r6, [r5] */
/* @0xe6338 str r6, [r5, #0x8] */
/* @0xe633c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe6340 mov r0, r5 */
/* @0xe6344 bl 0x27d1d0 <_ZdlPv> */
/* @0xe6348 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe634c mov r0, r5 */
/* @0xe6350 bl 0x27d1d0 <_ZdlPv> */
/* @0xe6354 b 0xe62dc <_Z9DoPopNulljPhPKhP6VMExec+0x128> */
/* @0xe6358 mov r0, r4 */
/* @0xe635c b 0xe622c <_Z9DoPopNulljPhPKhP6VMExec+0x78> */
/* @0xe6360 eoreq lr, r4, r12, lsr #5 */
