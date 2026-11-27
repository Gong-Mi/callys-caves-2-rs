/* cally 逆向卡：DoFrameTiming（原版 libyoyo.so，armv7）
 * @func 0x2903f8 0x290614  size 540  135 条（2905e8..0x290610 为 literal pool，11 字）
 * 级别: 正文（限速公式、四个 int64/float/int 全局、JNI 静态回调、±1 帧债务夹紧、返回值语义
 *             全部逐条锚定；未钉：被回调的那个 Java 静态方法的身份（jmethodID 只在 0x756C0C
 *             这个 .bss 槽里），以及 g_debt 在别处怎么累积）
 * 符号: _Z13DoFrameTimingv → int DoFrameTiming(void)（r7 是返回值；mangled 不编码返回类型）
 * 位置: 紧跟 PackageManagerHasSystemFeature 之后、getJNIEnv 之后；调用方是每帧循环
 *       （Timing_Time 0x215148 / Timing_Wait 0x212da4 / getJNIEnv 0x290274 / CallStaticVoidMethod 0xc4ad4）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   一帧的「睡眠预算」结算器：算出到下一帧还差多少微秒，睡掉（上限 1 秒），
 *   睡完回调一次 Java 静态方法并给帧计数器 +1，最后把「欠账」夹到 ±1 帧。
 *
 * ── 四个全局（GOT 槽 → 目标，值都是实测）─────────────────────────
 *   0x3F1930 → 0x3F77B0 (.data) int64 = -1   本帧时间戳（r8）  ← 首帧靠 -1 哨兵初始化
 *   0x3F1934 → 0x3F77A8 (.data) int64 = -1   上一帧快照（r9）  ← 每次进来先 = *g_now
 *   0x3F0BB4 → 0x3F5120 (.data) float = 60.0  帧率（浮点表示），算 usec/frame 用
 *   0x3F0B9C → 0x3F5124 (.data) int   = 60    帧率（整数表示），算每帧预算用（同址相邻）
 *   0x3F0BB0 → 0x5429D4 (.bss)  int          运行时门：<=0 → 整段睡眠跳过，返回 1
 *   0x3F1938 → 0x756BF8 (.bss)  int64        债务/欠账（本函数读作修正项，末尾夹到 ±F）
 *   0x3ED9AC → 0x756D44 (.bss)  jclass       0x3F193C → 0x756C0C (.bss) jmethodID
 *   0x3F1940 → 0x756C00 (.bss)  int          帧计数器
 *
 * ── 常量 ───────────────────────────────────────────────────────
 *   s16 = 1e6f（字面量 0x49742400）：一秒钟的微秒数，也是睡眠上限
 *
 * ── 公式（按指令顺序成立）────────────────────────────────────────
 *   usecPerFrame  F = 1e6 / 60.0f                       （vdiv s17）
 *   预算 budget = (float)(int64)(1e6 / (float)fpsInt)    （290488 __fixsfdi → 29048c __floatdisf）
 *               - 0.5f * F                              （vmls，半帧提前量）
 *               - (float)(t - *g_now)                   （本帧已耗时）
 *               + (float)g_debt                         （上一轮欠账）
 *   wait = clamp((int64)budget, 0, 1000000)             （负 → 0；>= 1e6 → 0xf4240）
 *   Timing_Wait(wait)；随后 ++*(int*)0x756C00
 *   收尾债务：F' = (int64)F；g_debt = max(-F', min(F', g_debt))   （夹到 ±1 帧）
 *
 * ── 返回值 ─────────────────────────────────────────────────────
 *   r7 = 1 只在「fps 门 <= 0、整段睡眠跳过」时成立；正常睡过一帧返回 0
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 装载：1e6f、GOT 基址、两个 int64 时间戳 ─────────────────────
 *   s16 = 1e6f（字面量 2905e8）
 *   r6 = GOT 基址 0x3F1C58（字面量 2905ec = 0x00161844 与 pc 相加）
 *   r8 = [GOT 0x3F1930] = 0x3F77B0（本帧时间戳的地址，.data，初值 -1）
 *   r9 = [GOT 0x3F1934] = 0x3F77A8（上一帧快照的地址，.data，初值 -1）
 */

/* @0x2903f8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2903fc vpush {d8, d9} */
/* @0x290400 vldr s16, [pc, #480] */
/* @0x290404 ldr r6, [pc, #0x1e0] */
/* @0x290408 ldr r2, [pc, #0x1e0] */
/* @0x29040c add r6, pc, r6 */
/* @0x290410 ldr r3, [pc, #0x1dc] */
/* @0x290414 ldr r8, [r6, r2] */
/* @0x290418 ldr r9, [r6, r3] */
/* ── 快照 + 取时 → 首帧用 -1 哨兵初始化 ─────────────────────────
 *   *g_prev = *g_now（ldrd/strd 直接两字拷贝）
 *   t = Timing_Time()（int64 微秒，r0:r1）
 *   if (*g_now == -1LL) *g_now = t（mvn r0/r1 造 -1，cmp/cmpeq 后 strdeq）
 */

/* @0x29041c ldrd r2, r3, [r8] */
/* @0x290420 strd r2, r3, [r9] */
/* @0x290424 bl 0x215148 <Timing_Time> */
/* @0x290428 ldrd r2, r3, [r8] */
/* @0x29042c mov r4, r0 */
/* @0x290430 mov r5, r1 */
/* @0x290434 mvn r0, #0 */
/* @0x290438 mvn r1, #0 */
/* @0x29043c cmp r3, r1 */
/* @0x290440 cmpeq r2, r0 */
/* ── 读 fps（浮点 + 整数两份）与运行时门 ────────────────────────
 *   r3 = [GOT 0x3F0BB0] = 0x5429D4（门）；r2 = [GOT 0x3F0BB4] = 0x3F5120（float 60.0）
 *   s17 = *(float*)0x3F5120 = 60.0 → vdiv s17 = 1e6/60 = 16666.67（每帧微秒）
 *   r3 = *(int*)0x5429D4（运行时 fps 门）
 */

/* @0x290444 ldr r3, [pc, #0x1ac] */
/* @0x290448 strdeq r4, r5, [r8] */
/* @0x29044c ldr r2, [pc, #0x1a8] */
/* @0x290450 ldr r3, [r6, r3] */
/* @0x290454 ldr r2, [r6, r2] */
/* @0x290458 vldr s17, [r2] */
/* @0x29045c ldr r3, [r3] */
/* @0x290460 vdiv.f32 s17, s16, s17 */
/* ── 门判定：fps <= 0 → 跳过整段睡眠，r7 = 1，直接去收尾 ────────── */

/* @0x290464 cmp r3, #0 */
/* @0x290468 movle r7, #1 */
/* @0x29046c ble 0x290558 <_Z13DoFrameTimingv+0x160> */
/* ── 整数 fps → 每帧预算（先整型后浮点两次转换）─────────────────
 *   vldr s15,[0x3F5124]（按 s32 取）+ vcvt.f32.s32 → (float)60
 *   vdiv s15 = 1e6 / 60；__fixsfdi 截成 int64；__floatdisf 再转回 float → s18
 *   ⇒ s18 = (float)(int64)(1e6/fpsInt)，与 s17 = 1e6/fpsFloat 是同一量的两条路径，
 *     差别只在 int 截断（fps 非整除时两者会差零点几微秒）
 */

/* @0x290470 ldr r3, [pc, #0x188] */
/* @0x290474 ldr r3, [r6, r3] */
/* @0x290478 vldr s15, [r3] */
/* @0x29047c vcvt.f32.s32 s15, s15 */
/* @0x290480 vdiv.f32 s15, s16, s15 */
/* @0x290484 vmov r0, s15 */
/* @0x290488 bl 0x319468 <__fixsfdi> */
/* @0x29048c bl 0x319398 <__floatdisf> */
/* ── 预算合成：半帧提前量 - 已耗时 + 欠账 ───────────────────────
 *   s18 -= 0.5 * s17（vmls）
 *   elapsed = t - *g_now（ldrd 拿 *g_now，subs/sbc 64 位减）
 *   s18 -= (float)elapsed（__floatdisf + vsub）
 *   s18 += (float)*(int64*)0x756BF8（g_debt，__floatdisf + vadd）
 */

/* @0x290490 vmov.f32 s15, #5.000000e-01 */
/* @0x290494 ldrd r2, r3, [r8] */
/* @0x290498 mov r1, r5 */
/* @0x29049c vmov s18, r0 */
/* @0x2904a0 mov r0, r4 */
/* @0x2904a4 subs r0, r0, r2 */
/* @0x2904a8 sbc r1, r1, r3 */
/* @0x2904ac vmls.f32 s18, s17, s15 */
/* @0x2904b0 bl 0x319398 <__floatdisf> */
/* @0x2904b4 ldr r3, [pc, #0x148] */
/* @0x2904b8 ldr r3, [r6, r3] */
/* @0x2904bc vmov s15, r0 */
/* @0x2904c0 ldrd r0, r1, [r3] */
/* @0x2904c4 vsub.f32 s18, s18, s15 */
/* @0x2904c8 bl 0x319398 <__floatdisf> */
/* @0x2904cc vmov s15, r0 */
/* @0x2904d0 vadd.f32 s15, s18, s15 */
/* ── 夹紧到 [0, 1e6] 微秒 ───────────────────────────────────────
 *   __fixsfdi/__floatdisf 做一次 int64 往返后比较：
 *     < 0        → r0:r1 = 0（2905dc）
 *     >= 1e6     → r0:r1 = 0xf4240 = 1000000（movw/movt 立即数）
 *     其余       → (int64) 原值
 */

/* @0x2904d4 vmov r0, s15 */
/* @0x2904d8 bl 0x319468 <__fixsfdi> */
/* @0x2904dc bl 0x319398 <__floatdisf> */
/* @0x2904e0 vmov s15, r0 */
/* @0x2904e4 vcmpe.f32 s15, #0 */
/* @0x2904e8 vmrs APSR_nzcv, fpscr */
/* @0x2904ec bmi 0x2905dc <_Z13DoFrameTimingv+0x1e4> */
/* @0x2904f0 bl 0x319468 <__fixsfdi> */
/* @0x2904f4 bl 0x319398 <__floatdisf> */
/* @0x2904f8 vmov s15, r0 */
/* @0x2904fc vcmpe.f32 s15, s16 */
/* @0x290500 vmrs APSR_nzcv, fpscr */
/* @0x290504 movwpl r0, #0x4240 */
/* @0x290508 movpl r1, #0 */
/* @0x29050c movtpl r0, #0xf */
/* @0x290510 bmi 0x2905d4 <_Z13DoFrameTimingv+0x1dc> */
/* ── 睡 → 回调 Java 静态方法 → 帧计数 +1 ─────────────────────────
 *   Timing_Wait(wait)（int64 微秒）
 *   r7 = 0（正常路径）
 *   Timing_Time() → getJNIEnv() → CallStaticVoidMethod(env, *(jclass*)0x756D44, *(jmethodID*)0x756C0C)
 *       无实参的静态 void 调用，即每帧一次的 Java 侧「帧回调」
 *   Timing_Time() → ++*(int*)0x756C00
 */

/* @0x290514 bl 0x212da4 <Timing_Wait> */
/* @0x290518 mov r7, #0 */
/* @0x29051c bl 0x215148 <Timing_Time> */
/* @0x290520 bl 0x290274 <getJNIEnv> */
/* @0x290524 ldr r2, [pc, #0xdc] */
/* @0x290528 ldr r3, [pc, #0xdc] */
/* @0x29052c ldr r2, [r6, r2] */
/* @0x290530 ldr r3, [r6, r3] */
/* @0x290534 ldr r1, [r2] */
/* @0x290538 ldr r2, [r3] */
/* @0x29053c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x290540 bl 0x215148 <Timing_Time> */
/* @0x290544 ldr r3, [pc, #0xc4] */
/* @0x290548 ldr r3, [r6, r3] */
/* @0x29054c ldr r2, [r3] */
/* @0x290550 add r2, r2, #1 */
/* @0x290554 str r2, [r3] */
/* ── 收尾：t2 = Timing_Time()；*g_now = t2；上一帧快照为 -1 就直接返回 ──
 *   *g_now 的写入在 beq 之前，两条路都会写
 */

/* @0x290558 bl 0x215148 <Timing_Time> */
/* @0x29055c ldrd r4, r5, [r9] */
/* @0x290560 mvn r2, #0 */
/* @0x290564 mvn r3, #0 */
/* @0x290568 cmp r5, r3 */
/* @0x29056c cmpeq r4, r2 */
/* @0x290570 strd r0, r1, [r8] */
/* @0x290574 beq 0x2905c8 <_Z13DoFrameTimingv+0x1d0> */
/* ── 债务夹到 ±1 帧 ────────────────────────────────────────────
 *   F = (int64)s17（每帧微秒）；-F 用 rsbs/rsc 造
 *   cur = *(int64*)0x756BF8；min = (cur < F) ? cur : F；g_debt = (-F < min) ? min : -F
 *   ⇒ g_debt = max(-F, min(F, g_debt))，两次 cmp+sbcs+movlt 就是有符号 64 位 min/max
 */

/* @0x290578 vmov r0, s17 */
/* @0x29057c bl 0x319468 <__fixsfdi> */
/* @0x290580 mov r5, r1 */
/* @0x290584 ldr r1, [pc, #0x78] */
/* @0x290588 mov r4, r0 */
/* @0x29058c mov r3, r5 */
/* @0x290590 mov r2, r4 */
/* @0x290594 rsbs r4, r4, #0 */
/* @0x290598 rsc r5, r5, #0 */
/* @0x29059c ldr r12, [r6, r1] */
/* @0x2905a0 ldrd r0, r1, [r12] */
/* @0x2905a4 cmp r0, r2 */
/* @0x2905a8 sbcs r6, r1, r3 */
/* @0x2905ac movlt r2, r0 */
/* @0x2905b0 movlt r3, r1 */
/* @0x2905b4 cmp r4, r2 */
/* @0x2905b8 sbcs r1, r5, r3 */
/* @0x2905bc movlt r4, r2 */
/* @0x2905c0 movlt r5, r3 */
/* @0x2905c4 strd r4, r5, [r12] */
/* ── 返回 r7（1 = 没睡，0 = 睡过）─────────────────────────────── */

/* @0x2905c8 vpop {d8, d9} */
/* @0x2905cc mov r0, r7 */
/* @0x2905d0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* ── 夹紧辅助：预算落在 [0,1e6) 时在这里做 (int64) 转换再回 290514 ── */

/* @0x2905d4 bl 0x319468 <__fixsfdi> */
/* @0x2905d8 b 0x290514 <_Z13DoFrameTimingv+0x11c> */
/* ── 负数分支：wait = 0 ──────────────────────────────────────── */

/* @0x2905dc mov r0, #0 */
/* @0x2905e0 mov r1, #0 */
/* @0x2905e4 b 0x290514 <_Z13DoFrameTimingv+0x11c> */
/* ── literal pool（2905e8..0x290610，11 字；头两条被 objdump 译成指令，非指令）──
 *   2905e8 = 0x49742400 = 1e6f                         2905ec = 0x00161844（GOT 基址差）
 *   2905f0 = 0xfffffcd8 → 0x3F77B0（本帧时间戳）        2905f4 = 0xfffffcdc → 0x3F77A8（上一帧）
 *   2905f8 = 0xffffef58 → 0x5429D4（fps 门）            2905fc = 0xffffef5c → 0x3F5120（float 60.0）
 *   290600 = 0xffffef44 → 0x3F5124（int 60）            290604 = 0xfffffce0 → 0x756BF8（债务）
 *   290608 = 0xffffbd54 → 0x756D44（jclass）            29060c = 0xfffffce4 → 0x756C0C（jmethodID）
 *   290610 = 0xfffffce8 → 0x756C00（帧计数）
 */

/* @0x2905e8 ldmdbmi r4!, {r10, sp} ^ */
/* @0x2905ec andseq r1, r6, r4, asr #16 */
/* @0x2905f0 .word 0xfffffcd8 */
/* @0x2905f4 .word 0xfffffcdc */
/* @0x2905f8 .word 0xffffef58 */
/* @0x2905fc .word 0xffffef5c */
/* @0x290600 .word 0xffffef44 */
/* @0x290604 .word 0xfffffce0 */
/* @0x290608 .word 0xffffbd54 */
/* @0x29060c .word 0xfffffce4 */
/* @0x290610 .word 0xfffffce8 */
