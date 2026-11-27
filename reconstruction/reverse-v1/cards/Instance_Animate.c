/* cally 逆向卡：Instance_Animate（原版 libyoyo.so，armv7）
 * @func 0x1d317c 0x1d32c0  size 324  81 条（0x1d32b8 / 0x1d32bc 两字为 literal pool 数据，真指令 79）
 * 级别: 正文（三条速度前缀路径 + 唯一出口的「回绕 + 事件」全部逐条锚定；image_index 的两个比较
 *             分别落在「截断整数」与「原始浮点」上、每次调用只修正一次、修正后尾跳 Perform_Event(7,7)
 *             —— 全部由指令与 GOT 槽值钉死；open 3 条见文末）
 * 符号: _Z16Instance_AnimateP9CInstance → void Instance_Animate(CInstance* inst)
 * 位置: 全库唯一调用点 DoAStep 0x1d33b4（每实例每步一次，见 DoAStep 卡）；本函数自身只调
 *       CInstance::GetImageNumber 0x19357c、Sprite_Data 0x1ef03c、CTimingSource::GetFPS 0x214808，
 *       并以尾跳进 Perform_Event 0xf3380。无返回值（void）、无空指针检查。
 *
 * ── 一句话 ─────────────────────────────────────────────────────────────
 *   把 inst 的 image_index 往前推一步（步长由全局模式字节与精灵自带系数决定），
 *   然后做一次回绕：上界「(int)image_index >= 帧数 → 减帧数」、下界「image_index < 0.0f → 加帧数」；
 *   哪条回绕被走，就在那条分支里尾跳 Perform_Event(inst, inst, 7, 7)（7=ev_other，子事件 7=Animation End）。
 *   除 image_index 外不写任何字段。
 *
 * ── 语义草案（可编译；helper 名是约定，不是符号名）─────────────────────
 *   void Instance_Animate(CInstance* inst) {
 *     if (*(uint8_t*)0x5428e8 == 0) {                      // 默认 1:1：每步加一个 image_speed
 *       inst->image_index += inst->image_speed;            // [0x90] += [0x94]，均为 f32
 *     } else {                                             // 缩放模式（同一字节也被 DoBreak 读作 g_isZeus）
 *       CSprite* spr = Sprite_Data(inst->[0x8c]);
 *       if (!spr) goto plain;                              // 1d31e8 beq → 1d319c
 *       if (spr->[0x70] == 1) {                            // 1d31f0 cmp / beq → 1d326c
 *         inst->image_index += inst->image_speed * spr->[0x6c];
 *       } else {
 *         double fps = CTimingSource::GetFPS();             // 单例地址 0x5428c0
 *         if (fps != 0.0) inst->image_index += inst->image_speed * (spr->[0x6c] / (float)fps);
 *         // fps == 0 → image_index 一个字节都不动（vdivne / vmlane / vstrne 全被 ne 挡掉）
 *       }
 *     }
 *   plain:
 *     { int n = inst->GetImageNumber();                     // 无精灵 → 0
 *       if ((int)inst->image_index >= n) {                  // 截断向零
 *         inst->image_index -= (float)inst->GetImageNumber();  // 第二次调用取被减数
 *         Perform_Event(inst, inst, 7, 7); return;          // 尾跳
 *       }
 *       if (inst->image_index < 0.0f) {                     // 原始浮点比较
 *         inst->image_index += (float)inst->GetImageNumber();
 *         Perform_Event(inst, inst, 7, 7); return;          // 尾跳
 *       }
 *     }
 *   }
 *
 * ── 字段与全局（全部实测）──────────────────────────────────────────────
 *   CInstance  +0x90  f32  image_index（vldr/vstr [r4,#144]，唯一被写的实例字段）
 *              +0x94  f32  image_speed（vldr [r4,#148]；只读，每步加到 image_index 或被缩放）
 *              +0x8c  int  精灵号（喂 Sprite_Data；与 DoSlowDrawRoom 卡同址）
 *   .bss   0x5428e8  byte 模式开关（GOT 0x3ed92c，R_ARM_RELATIVE，槽内预置该地址）
 *          0x5428c0  CTimingSource 单例（GOT 0x3ed934；r0 直接传地址当 this）
 *   CSprite +0x6c  f32  精灵自带速度系数（本卡唯一用处：乘 image_speed 或被 FPS 除）
 *           +0x70  int  档位：==1 走「不除 FPS」分支，其余走 GetFPS
 *   （帧数不在本卡里读：GetImageNumber 0x19357c 内部才读 CSprite +0x18，且 +0x74==2 时改走骨架帧数
 *      CSkeletonInstance::FrameCount；这些只用来说明 n 的来源，锚点不落在本卡。）
 *
 * ── 回绕与事件：精确条件（本卡核心）──────────────────────────────────
 *   ① 上界：t = (int)image_index（vcvt.s32.f32，截断向零）；t >= n → image_index -= (float)n，
 *      随后尾跳 Perform_Event(inst,inst,7,7)。比较是**有符号整数**比较（1d31bc cmp / 1d31c0 bge）。
 *   ② 下界：不复用①的整数结果，而是重载 image_index 做 f32 与 0.0 的比较
 *      （vcmpe.f32 s16,#0 + vmrs + bmi），< 0.0f → image_index += (float)n，随后同样尾跳事件。
 *      ⇒ (-1.0, 0.0) 的负小数会被②抓住（①对它们给出 t==0，通常不成立），
 *        而截断向零意味着 image_index = -0.5 且 n == 0 时①也会成立。
 *   ③ 只修正一次：两条分支各只有一条 vsub/vadd，没有循环、没有取模。若 |步长| > n，
 *      修正后仍在界外 —— 下一次调用会再修一次并再抛一次 Animation End（事件不节流）。
 *   ④ 事件参数恒定 (7,7)：r2=#7、r3=r2、r1=inst、r0=inst；且都是 pop {r4,lr} + b 0xf3380 的尾跳，
 *      事件返回后不再回到本函数任何一条检查。
 *   ⑤ n == 0（无精灵 / 精灵号无效）：t >= 0 恒成立 ⇒ 每次调用都「减 0 + 抛事件」。
 *      这是纯静态推论（1d31bc/1d31c0 与 GetImageNumber 的 popeq 返回 0 两处指令确定），
 *      运行期是否真按此刷事件未在设备上验证。
 *
 * ── 已证（逐条指到指令）──────────────────────────────────────────────
 *   1. 入口只读 r0=inst，只保存 d8（s16/s17 跨调用保活）：1d317c..1d318c。
 *   2. 模式字节经 GOT 0x3ed92c 取（槽内值 0x5428e8，R_ARM_RELATIVE，.bss 零初始化）；
 *      ==0 → 1d31a4 直加；!=0 → 1d31dc 精灵路径：1d3190..1d3198。
 *   3. 默认路径两个 f32 读写：image_index(0x90) += image_speed(0x94)：1d319c..1d31a8。
 *   4. 共同出口先取 n 再做整数上界比较：1d31ac..1d31c0。
 *   5. 下界用原始浮点比较，与上界不是同一个值：1d31c4..1d31d0。
 *   6. 两界都不成立 → vpop/pop 直返，不抛事件：1d31d4..1d31d8。
 *   7. 缩放路径的精灵号取自 [inst+0x8c]，Sprite_Data 返回 0 时退回默认路径：1d31dc..1d31e8。
 *   8. 精灵分档看 [spr+0x70] == 1：1d31ec..1d31f4。
 *   9. FPS 档：s17 = [spr+0x6c]，r0 = 0x5428c0，GetFPS 返回 double 于 r0:r1（vmov d7,r0,r1）；
 *      fps != 0 时 s17 /= (float)fps、s16 += s17*s15、回写；fps == 0 时只重载不改：1d31f8..1d3230。
 *  10. 上界分支重载 image_index、二次取 n、减、回写，再置 (7,7) 尾跳：1d3234..1d3268。
 *  11. 精灵系数档：image_index += image_speed * [spr+0x6c]（vmla）：1d326c..1d3280。
 *  12. 下界分支取 n、加、回写，再置 (7,7) 尾跳：1d3284..1d32b4。
 *  13. 两个 literal 池词 = 两个 GOT 槽的 pc 相对偏移：0x1d32b8=0x0021a79c（→0x3ed92c）、
 *      0x1d32bc=0x0021a72c（→0x3ed934）；objdump 把它们译成 mlaeq/eoreq，非指令。
 *
 * ── open ─────────────────────────────────────────────────────────────
 *  1. 0x5428e8 的正式名：跨卡证据是 DoBreak 卡把同一地址读作 g_isZeus（调试器在线）。
 *     本卡只证「非 0 就切到按精灵系数 / FPS 缩放的路径」这一二值语义；全库有 38 处引用（36 个函数）
 *     （含 F_GameGetSpeed、GV/SV_RoomSpeed、CRoom::UpdateLayers、ParticleSystem_Layer），
 *     也兼容「按真实时间推进」这类更泛的解释 —— 名字不采信为定论。
 *  2. CSprite +0x6c / +0x70 的字段名未知；只知 +0x6c 是 f32 系数、+0x70==1 选「不除 FPS」。
 *  3. 事件号 7 子事件 7 = Animation End 沿用 DoAStep 卡（该卡由派发侧认定，本卡只证参数）；
 *     Perform_Event 内部是否会回头改 image_index（例如事件里 set image_index）本卡未验。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────
 */

/* ── 序：r4 = inst；vpush {d8} 保住 s16/s17；模式字节来自 GOT 0x3ed92c ───────────
 *   literal 0x0021a79c 在函数尾 0x1d32b8，pc 相对相加得 0x3ed92c，再取槽内值 0x5428e8；
 *   ldrb 只读一个字节。cmp/bne：非 0 → 0x1d31dc（缩放路径），==0 落到下段直加。
 */

/* @0x1d317c ldr r3, [pc, #0x134] */
/* @0x1d3180 push {r4, lr} */
/* @0x1d3184 vpush {d8} */
/* @0x1d3188 ldr r3, [pc, r3] */
/* @0x1d318c mov r4, r0 */
/* @0x1d3190 ldrb r3, [r3] */
/* @0x1d3194 cmp r3, #0 */
/* @0x1d3198 bne 0x1d31dc <_Z16Instance_AnimateP9CInstance+0x60> */

/* ── 默认路径（模式字节 == 0）：image_index += image_speed，两个都是 f32 ──────────
 *   [r4,#144]=0x90 image_index、[r4,#148]=0x94 image_speed；vadd.f32 后原址回写。
 */

/* @0x1d319c vldr s16, [r4, #144] */
/* @0x1d31a0 vldr s15, [r4, #148] */
/* @0x1d31a4 vadd.f32 s16, s16, s15 */
/* @0x1d31a8 vstr s16, [r4, #144] */

/* ── 汇合点 1d31ac：取帧数 n，做「截断整数」上界比较 ───────────────────────────
 *   r0 = inst → GetImageNumber()（无精灵返回 0）；s16 此刻已被下面的 vcvt 覆写成整数，
 *   所以后面两条分支都必须「重载 image_index」才能拿到浮点值。
 *   cmp 是 s32 有符号比较；bge（aa）→ 上界分支 0x1d3234。
 */

/* @0x1d31ac mov r0, r4 */
/* @0x1d31b0 bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0x1d31b4 vcvt.s32.f32 s16, s16 */
/* @0x1d31b8 vmov r3, s16 */
/* @0x1d31bc cmp r3, r0 */
/* @0x1d31c0 bge 0x1d3234 <_Z16Instance_AnimateP9CInstance+0xb8> */

/* ── 下界：重载 image_index，与 0.0f 直接比较（不是整型）───────────────────────
 *   vcmpe.f32 s16,#0 把结果放 fpscr，vmrs 搬到 APSR_nzcv，bmi 取「小于 0」。
 *   ⇒ 上界用截断整数、下界用原始浮点：(-1,0) 的负小数在上界分支里给出 t==0，通常判不出来。
 */

/* @0x1d31c4 vldr s16, [r4, #144] */
/* @0x1d31c8 vcmpe.f32 s16, #0 */
/* @0x1d31cc vmrs APSR_nzcv, fpscr */
/* @0x1d31d0 bmi 0x1d3284 <_Z16Instance_AnimateP9CInstance+0x108> */

/* ── 两界都不成立：vpop {d8} + pop {r4,pc}，不抛事件，返回值无意义 ─────────────── */

/* @0x1d31d4 vpop {d8} */
/* @0x1d31d8 pop {r4, pc} */

/* ── 缩放路径入口：精灵号 [inst+0x8c] → Sprite_Data，失败退回默认路径 ───────────
 *   注意 1d31dc 的 r0 仍等于入口的 inst（此路径从未改写 r0）。
 *   cmp/beq：Sprite_Data 返回 0 → 0x1d319c（直加一个 image_speed）。
 */

/* @0x1d31dc ldr r0, [r0, #0x8c] */
/* @0x1d31e0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1d31e4 cmp r0, #0 */
/* @0x1d31e8 beq 0x1d319c <_Z16Instance_AnimateP9CInstance+0x20> */

/* ── 精灵分档：[spr+0x70] == 1 走「乘系数、不除 FPS」，否则走 FPS 档 ───────────── */

/* @0x1d31ec ldr r3, [r0, #0x70] */
/* @0x1d31f0 cmp r3, #1 */
/* @0x1d31f4 beq 0x1d326c <_Z16Instance_AnimateP9CInstance+0xf0> */

/* ── FPS 档：image_index += image_speed * (spr[0x6c] / fps)；fps==0 时整段不生效 ──
 *   1d31f8 literal 0x0021a72c → 0x3ed934 → 0x5428c0（CTimingSource 单例，直接当 this）；
 *   GetFPS 返回 double 在 r0:r1，vmov d7,r0,r1 拼成 d7；vcmp.f64 d7,#0 + vmrs。
 *   ne 组：s14=(float)fps、重载 s16/s15、s17/=s14、s16+=s17*s15、回写；
 *   eq 组只有 vldreq s16（供后面的 vcvt 用），既不除也不写回 ⇒ fps==0 时 image_index 不变。
 *   两条路最后都 b 0x1d31ac（回绕检查），越界判断不在这段里做。
 */

/* @0x1d31f8 ldr r3, [pc, #0xbc] */
/* @0x1d31fc vldr s17, [r0, #108] */
/* @0x1d3200 ldr r0, [pc, r3] */
/* @0x1d3204 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1d3208 vmov d7, r0, r1 */
/* @0x1d320c vcmp.f64 d7, #0 */
/* @0x1d3210 vmrs APSR_nzcv, fpscr */
/* @0x1d3214 vcvtne.f32.f64 s14, d7 */
/* @0x1d3218 vldrne s16, [r4, #144] */
/* @0x1d321c vldrne s15, [r4, #148] */
/* @0x1d3220 vldreq s16, [r4, #144] */
/* @0x1d3224 vdivne.f32 s17, s17, s14 */
/* @0x1d3228 vmlane.f32 s16, s17, s15 */
/* @0x1d322c vstrne s16, [r4, #144] */
/* @0x1d3230 b 0x1d31ac <_Z16Instance_AnimateP9CInstance+0x30> */

/* ── 上界回绕：image_index -= (float)n，然后尾跳 Perform_Event(inst,inst,7,7) ────
 *   1d3238 重载浮点（s16 被 vcvt.s32 覆写过）；1d323c 再取一次 n（与比较那次是两个调用）；
 *   1d3240/1d3244/1d3248/1d3250 置 r2=r3=7、r1=r0=inst；1d3254 f32(n)、1d3258 vsub、1d325c 回写；
 *   1d3260/1d3264 先 vpop {d8} 再 pop {r4,lr}，1d3268 是 b（不是 bl）⇒ 真尾跳，事件返回后不回本函数。
 */

/* @0x1d3234 mov r0, r4 */
/* @0x1d3238 vldr s16, [r4, #144] */
/* @0x1d323c bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0x1d3240 mov r2, #7 */
/* @0x1d3244 mov r1, r4 */
/* @0x1d3248 mov r3, r2 */
/* @0x1d324c vmov s14, r0 */
/* @0x1d3250 mov r0, r4 */
/* @0x1d3254 vcvt.f32.s32 s15, s14 */
/* @0x1d3258 vsub.f32 s16, s16, s15 */
/* @0x1d325c vstr s16, [r4, #144] */
/* @0x1d3260 vpop {d8} */
/* @0x1d3264 pop {r4, lr} */
/* @0x1d3268 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── 精灵系数档（[spr+0x70]==1）：image_index += image_speed * spr[0x6c] ─────────
 *   s15 = [r0,#108]=0x6c（r0 仍是 Sprite_Data 的返回值），s14 = image_speed，vmla 后回写并回检查点。
 */

/* @0x1d326c vldr s15, [r0, #108] */
/* @0x1d3270 vldr s16, [r4, #144] */
/* @0x1d3274 vldr s14, [r4, #148] */
/* @0x1d3278 vmla.f32 s16, s14, s15 */
/* @0x1d327c vstr s16, [r4, #144] */
/* @0x1d3280 b 0x1d31ac <_Z16Instance_AnimateP9CInstance+0x30> */

/* ── 下界回绕：image_index += (float)n，然后尾跳 Perform_Event(inst,inst,7,7) ────
 *   s16 是 1d31c4 载入的 image_index，跨 GetImageNumber 调用仍有效（s16 在 d8，callee-saved）。
 *   1d328c..1d329c 置 (7,7) 与 r0=r1=inst；1d32a0 f32(n)、1d32a4 vadd、1d32a8 回写；尾部同样真尾跳。
 */

/* @0x1d3284 mov r0, r4 */
/* @0x1d3288 bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0x1d328c mov r2, #7 */
/* @0x1d3290 mov r1, r4 */
/* @0x1d3294 mov r3, r2 */
/* @0x1d3298 vmov s14, r0 */
/* @0x1d329c mov r0, r4 */
/* @0x1d32a0 vcvt.f32.s32 s15, s14 */
/* @0x1d32a4 vadd.f32 s16, s16, s15 */
/* @0x1d32a8 vstr s16, [r4, #144] */
/* @0x1d32ac vpop {d8} */
/* @0x1d32b0 pop {r4, lr} */
/* @0x1d32b4 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── literal pool 两字（非指令，objdump 译成 mlaeq/eoreq）───────────────────────
 *   0x1d32b8 = 0x0021a79c：0x1d3190 + 该值 = 0x3ed92c（模式字节 GOT 槽）
 *   0x1d32bc = 0x0021a72c：0x1d3208 + 该值 = 0x3ed934（CTimingSource GOT 槽）
 */

/* @0x1d32b8 mlaeq r1, r12, r7, r10 */
/* @0x1d32bc eoreq r10, r1, r12, lsr #14 */
