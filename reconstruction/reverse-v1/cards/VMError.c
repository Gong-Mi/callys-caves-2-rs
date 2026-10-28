/* cally 逆向卡：VMError（原版 libyoyo.so，armv7）
 * @func 0xd4210 0xd4304  size 244  56 条指令 + 5 字 literal pool（0xd42f0..0xd4300，索引共 61 行）
 * 级别: 正文（61/61 逐条落锚；变参栈布局、4 个全局槽、3 条出口全解；被调函数内部语义只用
 *       符号名 + 重定位 + 调用约定判定，不外推）
 * 符号: _Z7VMErrorP6VMExecPKcz → void VMError(VMExec* exec, const char* fmt, ...)
 *
 * ── 一句话结论（回答「错误路径是否 abort / 长跳转」）────────────────────────
 *   都不是。VMError 是**普通返回**的 variadic 函数：唯一常规出口是收尾的 bx lr（0xd4290），
 *   没有任何 setjmp/longjmp 语义（.dynsym 里与 longjmp 有关的只有 png_set_longjmp_fn 这一个
 *   libpng 自带的 setjmp 抽象，没有 setjmp/sigsetjmp/longjmp 的 C 库导入），也不碰 JS 异常栈三件套
 *   （g_exceptionVar / g_pExceptionSP / g_fDoExceptionUnwind —— 那是 JSThrow* 用的，见另两张卡）。
 *   传播靠两样东西：① 全局字节 Code_Error_Occured = 1（进函数就置，无分支）
 *                  ② 调用者自己的返回码/出口跳转（见「调用面」一节的实测）。
 *   唯一会终止进程的是 exit(-1)，条件为 g_bLaunchedFromPlayer == 0（在编辑器/预览里跑）；
 *   播放器里跑则走 YYGML_game_end() 后照常返回。
 *
 * ── 签名与帧（算术可复核）──────────────────────────────────────────
 *   r0 = exec(VMExec*)   r1 = fmt   r2,r3 = 前两个可变参数，其余在栈上
 *   入口 S：push {r1,r2,r3} → S-12；push {r4..r8,lr} → S-36；sub 1024 → S-1060；sub 12 → S-1072 = sp
 *   fmt      = [sp+0x424] = S-12  = 入口 push 的 r1
 *   va_list  = sp+1064    = S-8   = 入口 push 的 r2（栈上第一个可变参数）
 *   buffer   = sp+4，长 1024（sp 只用来存 va_list 指针）
 *   canary   = __stack_chk_guard，GOT 槽 0x3ed958（R_ARM_GLOB_DAT），槽偏移 = GOT-0x4300
 *
 * ── GOT 基址与四个槽（r4 = 0x3f1c58，由 0xd422c 的 pc 相对加法算出）──────────
 *   GOT-0x4300 → __stack_chk_guard            0x3ed958  R_ARM_GLOB_DAT（来自 libc）
 *   GOT-0x40EC → Code_Error_Occured           0x47f3c4  1 字节，R_ARM_RELATIVE
 *   GOT-0x4024 → g_fSuppressErrors            0x47b238  1 字节
 *   GOT-0x4020 → g_bLaunchedFromPlayer        0x7590d2  1 字节
 *   （三个符号名取自本件符号表，语义由本函数的使用方式独立印证：抑制→跳过格式化与弹窗、
 *     置 1→错误标志、0→exit(-1)）
 *
 * ── 三条路径（互斥，全部落锚）──────────────────────────────────────
 *   A 抑制路径：g_fSuppressErrors != 0（0xd425c 早退）
 *       不格式化、不弹窗、不退出；**复位 exec（0x44/0x4c）**；canary 校验后返回。
 *   B1 格式化后仍抑制：vsprintf 之后再读一次标志（0xd42b0），被置位 → 跳过弹窗，
 *       直接 canary + 返回（**不复位 exec**）。说明这个标志可以在格式化期间被 hook 改掉。
 *   B2 正常：vsprintf → Error_Show_Action(buf, 1) → g_bLaunchedFromPlayer
 *       ==0 → exit(-1)（0xd42e8/0xd42ec，进程终止，不复位 exec）
 *       !=0 → YYGML_game_end() → canary + 返回（不复位 exec）
 *
 * ── exec 复位块（0xd4260..0xd426c）与 DoRet/DoExit 的关系 ──────────────
 *   exec->[0x50] → r3；exec->[0x4c] = 0；exec->[0x44] = r3。
 *   DoRet.c / DoExit.c 已证同一组字段：0x44 = 取指位置、0x4c = 帧深度、0x50 = 帧代码基址、
 *   0x48 = 解码表项。此处＝「帧深度清零 + 取指退回本帧起点」。
 *   差别（本卡实测）：VMError **不写 exec->[0x48]**（DoRet/DoExit 的深度 0 出口三字段都写），
 *   而且这个复位块位于 A 路径上——弹窗/game_end 的主路径不会执行它。
 *
 * ── 调用面（可核对的实测，回答「DoCallScript/Do* 的失败分支依赖什么」）────────
 *   · .text 内 ARM `bl 0xd4210` 共 177 处，**全部**落在 Do* 指令处理器里（177/177），无 tail-b 形式；
 *     全件只有一个可执行段 .text，不存在漏扫的第二代码段。
 *   · 上下文给的「244 处调用」与本机实测 177 不一致，差异来源未定 → 列入 open，本卡只认 177。
 *   · DoAdd 0xdcd60 调用后：mov r12,#0; b 0xdc8e4 —— 直接走自己的出口，不读返回值（也没有返回值）。
 *   · DoCallScript 0xe89cc 是它在 DoCallScript 里的**唯一**一处，fmt = "call to non-existent script\n"，
 *     调用后 b 0xe85ac 走出口。
 *   · Code_Error_Occured 在 ExecuteIt 入口被清零（0xcf948：同一 GOT 槽 GOT-0x40EC 上的 strb 0），
 *     说明它是「一次 ExecuteIt 期间」的错误标志；Code_Execute 0xcfc60 用 ExecuteIt 的**返回码**
 *     判成败，返回 0 时以 Code_Error_String（GOT 槽 0x3edb78 → 0x47f3c0，两次解引用取到
 *     char*）作第 1 参调 Error_Show_Action(…, 0)。
 *     ⇒ 全链是「全局标志 + 返回码」，没有长跳转；任何 Do* 只要不想继续，就得自己跳出口。
 *
 * open（本卡未闭合）：
 *   1. 「244 处」的统计口径未解（本件实测 177 条 bl；若那份数字来自别的构建或别的计数方式，
 *      需要给出处才能对账）。
 *   2. vsprintf 写固定 1024 字节栈缓冲、无长度钳制（只记事实，不推断触发条件）。
 *   3. Code_Error_Occured 的逐指令消费点未在本卡范围钉死（ExecuteIt 入口清零这一处已证）。
 *   4. Error_Show_Action / YYGML_game_end 的内部语义未解，本卡只用它们的可证调用约定
 *      （前者 (const char*, bool)，后者无参无返回）。
 */

/* ── 序言：压参 → 建帧 → 装 canary → 无条件置错误标志 ───────────────── */
/* @0xd4210 push {r1, r2, r3} */  —— 先把 r1(fmt)/r2/r3 三个寄存器参数原样压栈，后面靠内存连续构造 va_list
/* @0xd4214 push {r4, r5, r6, r7, r8, lr} */  —— 保存 r4..r8 与 lr
/* @0xd4218 sub sp, sp, #1024 */  —— 1024 字节消息缓冲
/* @0xd421c ldr r4, [pc, #0xcc] */  —— 字面量 0x0031da24（GOT 相对偏移，供 0xd422c 用）
/* @0xd4220 sub sp, sp, #12 */  —— 再减 12：与开头压的 r1/r2/r3 对齐，va_list 才能从 sp+1064 直接指到 S-8
/* @0xd4224 ldr r3, [pc, #0xc8] */  —— 0xffffbd00 = -0x4300 → __stack_chk_guard 的 GOT 槽偏移
/* @0xd4228 mov r7, #1 */  —— 常数 1：既当 Code_Error_Occured 的写入值，也当 Error_Show_Action 第 2 参
/* @0xd422c add r4, pc, r4 */  —— r4 = 0x3f1c58 = GOT 基址（本函数唯一地址基准）
/* @0xd4230 ldr r12, [pc, #0xc0] */  —— 0xffffbf14 = -0x40EC → Code_Error_Occured 槽
/* @0xd4234 ldr r2, [pc, #0xc0] */  —— 0xffffbfdc = -0x4024 → g_fSuppressErrors 槽
/* @0xd4238 ldr r5, [r4, r3] */  —— r5 = &__stack_chk_guard（该槽是 R_ARM_GLOB_DAT，取自 libc）
/* @0xd423c ldr r1, [sp, #0x424] */  —— 取回 fmt：0x424 = 1060 = S-12，正是入口 push 的 r1
/* @0xd4240 ldr r3, [r5] */  —— 读 canary 现值
/* @0xd4244 str r3, [sp, #0x404] */  —— canary 落栈 [sp+0x404]
/* @0xd4248 ldr r3, [r4, r12] */  —— r3 = &Code_Error_Occured（0x47f3c4，1 字节）
/* @0xd424c strb r7, [r3] */  —— ★ Code_Error_Occured = 1 —— 错误标志位在**任何分支之前**无条件置位

/* ── 分支 1：g_fSuppressErrors（抑制路径 A：复位 exec 后返回）────────── */
/* @0xd4250 ldr r6, [r4, r2] */  —— r6 = &g_fSuppressErrors（0x47b238，1 字节）
/* @0xd4254 ldrb r3, [r6] */  —— 读 g_fSuppressErrors
/* @0xd4258 cmp r3, #0 */
/* @0xd425c beq 0xd4294 <_Z7VMErrorP6VMExecPKcz+0x84> */  —— 非 0 → 抑制路径 A（不格式化、不弹窗、不退出）
/* @0xd4260 ldr r3, [r0, #0x50] */  —— exec->[0x50] = 当前帧代码基址
/* @0xd4264 mov r2, #0 */
/* @0xd4268 str r2, [r0, #0x4c] */  —— exec->[0x4c] = 0（帧深度清零）
/* @0xd426c str r3, [r0, #0x44] */  —— exec->[0x44] = 代码基址（取指复位）★ 只有这条路径会复位 exec

/* ── 公共收尾：canary 校验 + 弹栈返回（所有路径都过这里，exit 除外）──── */
/* @0xd4270 ldr r2, [sp, #0x404] */  —— canary 比对
/* @0xd4274 ldr r3, [r5] */
/* @0xd4278 cmp r2, r3 */
/* @0xd427c bne 0xd42e4 <_Z7VMErrorP6VMExecPKcz+0xd4> */  —— ★★ canary 不符 → __stack_chk_fail（不是错误出口，是栈损坏）
/* @0xd4280 add sp, sp, #1024 */  —— 弹掉 1024 缓冲
/* @0xd4284 add sp, sp, #12 */  —— 弹掉 12
/* @0xd4288 pop {r4, r5, r6, r7, r8, lr} */  —— 恢复 r4..r8/lr
/* @0xd428c add sp, sp, #12 */  —— 跳过开头压的 r1/r2/r3
/* @0xd4290 bx lr */  —— ★ 唯一的常规返回点（另一条离开路径只有 0xd42ec 的 exit(-1)，那条不返回）

/* ── 路径 B：格式化。va_list 由 0xd4294..0xd42a0 现搭 ─────────────── */
/* @0xd4294 add r3, sp, #1056 */  —— sp+1056 → 再 +8 = sp+1064 = S-8 = 栈上第一个可变参数（原 r2）
/* @0xd4298 add r8, sp, #4 */  —— r8 = sp+4 = 消息缓冲起点（1024 字节）
/* @0xd429c add r3, r3, #8 */  —— va_list 起点
/* @0xd42a0 str r3, [sp] */  —— va_list 指针存本地槽 [sp]（缓冲前的 4 字节）
/* @0xd42a4 mov r0, r8 */  —— vsprintf 目标 = 缓冲
/* @0xd42a8 mov r2, r3 */  —— va_list 作第 3 参（AAPCS：va_list 是 void*，走 r2）
/* @0xd42ac bl 0xb667c <vsprintf@plt> */  —— ★ vsprintf(buf, fmt, va)：无长度钳制，固定 1024 字节栈缓冲

/* ── 格式化之后的第二次抑制检查 → 弹窗 → 播放器判定 ─────────────── */
/* @0xd42b0 ldrb r3, [r6] */  —— ★ 第二次读 g_fSuppressErrors（vsprintf 之后）
/* @0xd42b4 cmp r3, #0 */
/* @0xd42b8 bne 0xd4270 <_Z7VMErrorP6VMExecPKcz+0x60> */  —— 期间被置位 → 跳过弹窗，直接走 canary+返回（**不做 exec 复位**）
/* @0xd42bc mov r0, r8 */
/* @0xd42c0 mov r1, r7 */  —— 第 2 参 = 1
/* @0xd42c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */  —— Error_Show_Action(buf, 1)
/* @0xd42c8 ldr r3, [pc, #0x30] */  —— 0xffffbfe0 = -0x4020 → g_bLaunchedFromPlayer 槽
/* @0xd42cc ldr r3, [r4, r3] */  —— r3 = &g_bLaunchedFromPlayer（0x7590d2，1 字节）
/* @0xd42d0 ldrb r3, [r3] */
/* @0xd42d4 cmp r3, #0 */
/* @0xd42d8 beq 0xd42e8 <_Z7VMErrorP6VMExecPKcz+0xd8> */  —— ==0（IDE/编辑器预览里跑）→ exit(-1)
/* @0xd42dc bl 0x10c320 <_Z14YYGML_game_endv> */  —— 播放器里跑 → game_end()
/* @0xd42e0 b 0xd4270 <_Z7VMErrorP6VMExecPKcz+0x60> */  —— 回到 canary 校验后返回（**也不做 exec 复位**）

/* ── 两个终止/保护出口 ────────────────────────────────────── */
/* @0xd42e4 bl 0xb65d4 <__stack_chk_fail@plt> */  —— 栈保护失败出口
/* @0xd42e8 mvn r0, #0 */  —— r0 = -1
/* @0xd42ec bl 0xb6688 <exit@plt> */  —— ★ 唯一的进程终止点：exit(-1)

/* ── 字面量池（objdump 把首字按指令解码，按规矩保留原写法）───────────── */
/* @0xd42f0 eorseq sp, r1, r4, lsr #20 */  —— 字面量池：0x0031da24（GOT 相对偏移，被 0xd422c 消费）
/* @0xd42f4 .word 0xffffbd00 */  —— 字面量池：0xffffbd00 = -0x4300（__stack_chk_guard 槽）
/* @0xd42f8 .word 0xffffbf14 */  —— 字面量池：0xffffbf14 = -0x40EC（Code_Error_Occured 槽）
/* @0xd42fc .word 0xffffbfdc */  —— 字面量池：0xffffbfdc = -0x4024（g_fSuppressErrors 槽）
/* @0xd4300 .word 0xffffbfe0 */  —— 字面量池：0xffffbfe0 = -0x4020（g_bLaunchedFromPlayer 槽）
