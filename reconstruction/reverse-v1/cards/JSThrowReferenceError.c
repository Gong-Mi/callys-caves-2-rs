/* cally 逆向卡：JSThrowReferenceError（原版 libyoyo.so，armv7）
 * @func 0x254b04 0x254c20  size 284  71 条指令（无 literal pool）
 * 级别: 正文（71/71 逐条落锚；三个 RValue 槽、两级构造、三段清理全部解码；
 *       F_JSThrow 只用「写哪个全局 + 调用约定」级证据，不重建其内部）
 * 符号: _Z21JSThrowReferenceErrorPKc → JSThrowReferenceError(const char* msg)
 *
 * ── 一句话结论（错误路径：abort / 长跳转 / 标志位？）────────────────────────
 *   是**标志位 + 手写栈展开**：不是 abort，也不是 setjmp/longjmp。
 *   本函数自身不碰任何全局，只做「消息串 → ReferenceError 对象 → throw」两跳；真正抛出的是
 *   F_JSThrow(0x24e33c)，三件事（本卡按写入点与符号名判定，不逐条重建其内部）：
 *     ① 把第 5 参（&B）按 tag 深拷贝进全局 g_exceptionVar（0x75645c，16 字节 RValue，
 *        GOT-0x3F28 槽 = 0x3edd30），拷贝前先按 tag==1 / tag==2 分派释放旧值；
 *     ② 置 g_fThrownExceptionUnwinding = 1（0x756471，GOT 槽 0x3f14fc；strb 在 0x24e404）；
 *     ③ pop 后 tail-b 进 UnwindExceptionStack()（0x24e0b4）：**逐帧 PerformReturn 的手写展开
 *        循环**，并维护 g_pExceptionSP(0x75646c) / g_fDoExceptionUnwind(0x756470) /
 *        g_caughtExec(0x756458)。全库没有 C 库 setjmp/longjmp 导入（符号表里与 longjmp 有关的
 *        只有 png_set_longjmp_fn 这个 libpng 自带包装），所以「异常」= 全局标志 + 显式展开。
 *   ⇒ 对调用点而言是「调用即离开」：DoSet 0xe24e4 处 bl 之后立刻 mov r0,r8 / add sp,#68 /
 *     pop{...,pc}，不检查任何标志 —— 展开已在 F_JSThrow 内部完成。
 *
 * ── 三个 RValue 槽（60 字节帧的切分，全部实测）────────────────────────────
 *   A = sp+8  ：消息串（YYCreateString 输出，tag=1）
 *   B = sp+24 ：ReferenceError 对象（构造函数输出）
 *   C = sp+40 ：F_JSThrow 的第 1 参；F_JSThrow 体内 r0 第一次出现就是「被写」，
 *               从不读它 → C 只是占位实参（据此断言第 1 参无效，不猜它是不是 out）
 *   RValue 布局（由写入位置定死）：+0/+4 = 值，+8 = 附加字（串/对象指针），+0xc = tag
 *   释放判据：(tag-1) & 0x00FFFFFF & ~3 == 0 ⇔ tag ∈ {1,2,3,4}，与 DoRet.c / PerformReturn 同判据
 *   清空顺序：释放 A → A 写成 {+0=0,+8=0,tag=5} → 释放 B → B 写成同形 → 释放 C（C 不再清）
 *
 * ── 与 JSThrowTypeError 的关系（实测差分）──────────────────────────────────
 *   两函数 71 条指令逐条同构：把绝对分支目标换算成相对位移后，只有 0x254b5c 一条不同
 *   （F_JSReferenceErrorCall 0x244094 ↔ F_JSTypeErrorCall 0x244134），其余 70 条形同；
 *   另 5 处文本差异全部是「同一位移落在不同基址」的必然结果（0x254b9c/0x254bc8/0x254bf4/
 *   0x254c10/0x254c1c ↔ 0x24e624/0x24e650/0x24e67c/0x24e698/0x24e6a4）。
 *   ⇒ 两者只差「用哪个构造函数造错误对象」，抛出、清理、展开路径完全共用。
 *
 * ── 调用面 ───────────────────────────────────────────────────────
 *   .text 内 bl 0x254b04 共 42 处，**全部**落在 Do* 处理器里（DoSet 8、DoAdd 4、DoNot 2、
 *   DoSub/DoDiv/DoMod/DoAnd/DoOr 各 2…），且都在「未解析引用 tag == 0x00FFFFFF」这类分支上
 *   本函数同样不含文案：DoSet 的第一个调用点 0xe24dc/0xe24e0 传入的是 .rodata 0x33433c
 *   「could not find lhs variable on assignment」。
 *   （DoSet.c 已把它的 8 个调用点逐条列出）。
 *   F_JSThrow 全库只有 4 个调用者 = 四个 JSThrow* 包装，本函数是其中之一。
 *
 * open：
 *   1. YYCreateString(0xe5258) / F_JSReferenceErrorCall(0x244094) 的内部语义未重建。
 *   2. tag=5 的语义名（清空/undefined）来自清理写法，未由类型分发表证明。
 *   3. F_JSThrow 的 tag 分派表未逐项解码（同 TypeError 卡 open 3）。
 */

/* ── 第一步：把 msg 做成字符串 RValue（序言 + 清零 + YYCreateString）──────── */
/* @0x254b04 push {r4, r5, r6, r7, lr} */  —— 保存 r4..r7 与 lr
/* @0x254b08 sub sp, sp, #60 */  —— 60 字节帧：A(sp+8) / B(sp+24) / C(sp+40) 三个 16 字节 RValue + [sp] 出参槽
/* @0x254b0c add r6, sp, #8 */  —— r6 = A = sp+8 —— 消息串 RValue
/* @0x254b10 add r5, sp, #24 */  —— r5 = B = sp+24 —— 构造出的 ReferenceError 对象
/* @0x254b14 mov r4, #0 */  —— r4 = 0：常数 0，同时当后面 self/other 的 NULL
/* @0x254b18 mov r1, r0 */  —— r1 = msg（YYCreateString 第 2 参）
/* @0x254b1c add r7, sp, #40 */  —— r7 = C = sp+40 —— F_JSThrow 的第 1 参（实测被调方从不读它）
/* @0x254b20 mov r0, r6 */  —— r0 = &A
/* @0x254b24 str r4, [sp, #0x8] */  —— A/B 清零起点：8 个 str 覆盖 32 字节（A 的 +0x8..+0x18 与 B 的 +0x18..+0x28）
/* @0x254b28 str r4, [sp, #0xc] */
/* @0x254b2c str r4, [sp, #0x10] */
/* @0x254b30 str r4, [sp, #0x14] */
/* @0x254b34 str r4, [sp, #0x18] */
/* @0x254b38 str r4, [sp, #0x1c] */
/* @0x254b3c str r4, [sp, #0x20] */
/* @0x254b40 str r4, [sp, #0x24] */
/* @0x254b44 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */  —— ★ YYCreateString(&A, msg)：把消息串做成 tag=1 的字符串 RValue

/* ── 第二步：把消息串造成 Error 对象（写进 B）───────────────── */
/* @0x254b48 mov r1, r4 */  —— self = NULL
/* @0x254b4c mov r2, r4 */  —— other = NULL
/* @0x254b50 mov r0, r5 */  —— out = &B
/* @0x254b54 mov r3, #1 */  —— argc = 1
/* @0x254b58 str r6, [sp] */  —— args = &A（数组里只有那个消息串）
/* @0x254b5c bl 0x244094 <_Z22F_JSReferenceErrorCallR6RValueP9CInstanceS2_iPS_> */  —— ★ F_JSReferenceErrorCall(&B, NULL, NULL, 1, &A)：造 ReferenceError 对象写进 B
/* @0x254b60 mov r3, #1 */  —— argc = 1（给下面的 throw 用）

/* ── 第三步：throw —— 先清 C，再调 F_JSThrow ─────────────────── */
/* @0x254b64 mov r1, r4 */  —— r1 = NULL
/* @0x254b68 str r5, [sp] */  —— args = &B
/* @0x254b6c mov r2, r4 */  —— r2 = NULL
/* @0x254b70 mov r0, r7 */  —— r0 = &C
/* @0x254b74 str r4, [sp, #0x28] */  —— C 清零起点（4 个 str，C 的 +0x28..+0x34）
/* @0x254b78 str r4, [sp, #0x2c] */
/* @0x254b7c str r4, [sp, #0x30] */
/* @0x254b80 str r4, [sp, #0x34] */
/* @0x254b84 bl 0x24e33c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_> */  —— ★★ F_JSThrow(&C, NULL, NULL, 1, &B)：写 g_exceptionVar + 置 g_fThrownExceptionUnwinding=1 + tail-b 进 UnwindExceptionStack

/* ── 第四步：三段清理（释放判据 tag∈{1,2,3,4}；先释放、后清空）───── */
/* @0x254b88 ldr r3, [sp, #0x14] */  —— A.tag（A+0xc = sp+0x14）
/* @0x254b8c sub r3, r3, #1 */  —— tag-1
/* @0x254b90 bic r3, r3, #-16777216 */  —— 清高 8 位（引用标志位）
/* @0x254b94 bic r3, r3, #3 */  —— 清低 2 位
/* @0x254b98 cmp r3, r4 */  —— cmp 0 ⇔ tag ∈ {1,2,3,4}（堆值）
/* @0x254b9c beq 0x254c14 <_Z21JSThrowReferenceErrorPKc+0x110> */  —— ★ A 是堆值 → 先释放 A，再回来清空 A 槽
/* @0x254ba0 ldr r1, [sp, #0x24] */  —— B.tag（B+0xc = sp+0x24）—— 从这句起是「清空 A，再决定是否释放 B」
/* @0x254ba4 mov r3, #0 */  —— 0
/* @0x254ba8 str r3, [sp, #0x10] */  —— A+8 = 0
/* @0x254bac mov r2, #5 */  —— tag = 5（清空标记）
/* @0x254bb0 sub r1, r1, #1 */  —— B.tag-1
/* @0x254bb4 str r3, [sp, #0x8] */  —— A+0 = 0
/* @0x254bb8 bic r3, r1, #-16777216 */  —— 清高 8 位
/* @0x254bbc str r2, [sp, #0x14] */  —— ★ A.tag = 5：A 槽清空
/* @0x254bc0 bic r3, r3, #3 */  —— 清低 2 位
/* @0x254bc4 cmp r3, #0 */
/* @0x254bc8 beq 0x254c08 <_Z21JSThrowReferenceErrorPKc+0x104> */  —— ★ B 是堆值 → 先释放 B，再清空 B 槽
/* @0x254bcc ldr r1, [sp, #0x34] */  —— C.tag（C+0xc = sp+0x34）
/* @0x254bd0 mov r3, #0 */  —— 0
/* @0x254bd4 str r3, [sp, #0x20] */  —— B+8 = 0
/* @0x254bd8 mov r2, #5 */  —— tag = 5
/* @0x254bdc sub r1, r1, #1 */  —— C.tag-1
/* @0x254be0 str r3, [sp, #0x18] */  —— B+0 = 0
/* @0x254be4 bic r3, r1, #-16777216 */  —— 清高 8 位
/* @0x254be8 str r2, [sp, #0x24] */  —— ★ B.tag = 5：B 槽清空
/* @0x254bec bic r3, r3, #3 */  —— 清低 2 位
/* @0x254bf0 cmp r3, #0 */
/* @0x254bf4 bne 0x254c00 <_Z21JSThrowReferenceErrorPKc+0xfc> */  —— C 不是堆值 → 直接返回（C 槽不必清，帧马上消失）
/* @0x254bf8 mov r0, r7 */  —— r0 = &C
/* @0x254bfc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */  —— FREE_RValue__Pre(&C)
/* @0x254c00 add sp, sp, #60 */  —— 弹帧
/* @0x254c04 pop {r4, r5, r6, r7, pc} */  —— ★ 正常返回（无返回值语义：r0 已被 FREE_RValue__Pre 的返回值覆盖）
/* @0x254c08 mov r0, r5 */  —— r0 = &B

/* ── 释放分支（A/B 是堆值时才来）─────────────────────────── */
/* @0x254c0c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */  —— FREE_RValue__Pre(&B)
/* @0x254c10 b 0x254bcc <_Z21JSThrowReferenceErrorPKc+0xc8> */  —— 回到 C.tag 判定
/* @0x254c14 mov r0, r6 */  —— r0 = &A
/* @0x254c18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */  —— FREE_RValue__Pre(&A)
/* @0x254c1c b 0x254ba0 <_Z21JSThrowReferenceErrorPKc+0x9c> */  —— 回到 B.tag 判定（即「清空 A → 释放 B」）
