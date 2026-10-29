/* cally 逆向卡：anon_319414（原版 libyoyo.so，armv7）
 * @func 0x319414 0x319458  size 68  17 条（无字面量池、无栈帧；除零快路 0 条栈操作）
 * 级别: 正文（除数为 0 的夹逼、SIGFPE、余数经栈槽回填的三段协议、单次除法的算法全部落锚；open 2 条）
 * 符号: 本仓库 functions.tsv 记作 anon_319414；.dynsym 里同址是 T __aeabi_ldivmod（st_value 0x319414，
 *       llvm-nm -D 可复核）——即 ARM EABI 的 64 位有符号除法运行库入口。命名差异只是清点口径，地址同一。
 *
 * ── 契约（AAPCS / RTABI）──────────────────────────────────────────────
 *   long long __aeabi_ldivmod(long long n, long long d);
 *   入参：n = r0(低):r1(高)、d = r2(低):r3(高)
 *   返回：商 = r0:r1、余数 = r2:r3（两个 64 位值 —— 这是 ARM EABI 与普通 C 返回约定最大的差别，
 *         也是下面那段「sub sp / push {sp,lr} / pop {r2,r3}」序言存在的唯一理由）
 *
 * ── 语义草案 ─────────────────────────────────────────────────────────
 *   if (d == 0) { raise(SIGFPE); return (n < 0 ? LLONG_MIN_high : LLONG_MAX_high), 0; }
 *   q = __divdi3(n, d);  rem = n - q*d;  return q, rem;
 *
 * ── 已证（每条指到指令）───────────────────────────────────────────────
 *   1. 64 位除数为 0 的判定用两条指令吃完：0x319414 cmp r3,#0 + 0x319418 cmpeq r2,#0，
 *      0x31941c bne 0x31943c ⇒ d != 0 走慢路，d == 0 落到夹逼段。
 *   2. 夹逼的符号判定同样两条：0x319420 cmp r1,#0 + 0x319424 cmpeq r0,#0（r1 非 0 就看 r1，否则看 r0），
 *      即判断被除数 n < 0。
 *      0x319428 movlt r1,#-2147483648、0x31942c movlt r0,#0 ⇒ r1 = 0x80000000、r0 = 0；
 *      0x319430 mvngt r1,#-2147483648、0x319434 mvngt r0,#0 ⇒ r1 = 0x7FFFFFFF、r0 = 0xFFFFFFFF。
 *      注意 mvngt 是「取反立即数」：mvn r1,#-2147483648 得 0x7FFFFFFF，mvn r0,#0 得 0xFFFFFFFF。
 *   3. 夹逼段以 0x319438 b 0x319458 尾跳 __aeabi_ldiv0 收尾。该函数（16 B，.dynsym 里 __aeabi_idiv0
 *      与 __aeabi_ldiv0 同址、均为 W）体是：push {r1,lr} → mov r0,#8 → bl raise@plt → pop {r1,pc}
 *      ⇒ raise(SIGFPE)（8 = SIGFPE）。
 *      细节（重要，避免把夹逼读成严格返回值）：它只保存/恢复 r1（商的高字）与 lr，r0 会被 raise 的
 *      返回值覆盖 ⇒ 若信号处理返回，商 = (raise 的返回值, 夹逼高字)，只有高字是夹逼值；
 *      余数 r2:r3 此时仍是 0（就是那个 0 除数）⇒ 余数 = 0。
 *   4. 慢路 0x31943c..0x319454 是一段为「8 字节余数槽 + 8 字节栈对齐」手写的序言：
 *      0x31943c sub sp,sp,#8 预留 8 B（余数槽）；
 *      0x319440 push {sp,lr} 把「该槽的地址」压成 helper 的第 5 实参，同时保存 lr（顺带凑满 16 B 对齐）；
 *      0x319444 bl 0x3195b8 __gnu_ldivmod_helper；
 *      0x319448 ldr lr,[sp,#4] 取回 lr；0x31944c add sp,sp,#8 回到槽底；
 *      0x319450 pop {r2,r3} 把槽里的 64 位余数装进 r2:r3。
 *      ⇒ 这三条不是凑对齐：push 写的是第 5 实参（余数指针），pop {r2,r3} 才是「第二个 64 位返回值」的通道。
 *   5. helper 侧（0x3195b8，60 B）验证了同一条协议：
 *      push {r3,r4,r5,r6,r7,lr}；0x3195d0 ldr r12,[sp,#0x18] 取余数指针（= 调用者入口的 [sp]，即第 5 实参）；
 *      0x3195cc bl 0x31b220 __divdi3 求商；再用 0x3195d4 mul / 0x3195d8 mla / 0x3195dc umull /
 *      0x3195e0 add / 0x3195e4 subs / 0x3195e8 sbc 手算 n - q*d；0x3195ec strd r2,r3,[r12] 写回余数槽；
 *      0x3195f0 pop {r3,r4,r5,r6,r7,pc} 交出商（r0:r1）。
 *      ⇒ 全程只做一次 64 位除法；余数由乘减导出，没有第二次 __moddi3 调用。
 *   6. 调用面 27 个 bl 点，全部是 64 位除法 / 取余：
 *      DoRem×7（0xd46e0 / 0xd4714 / 0xd4750 / 0xd4778 / 0xd4800 / 0xd482c / 0xd4880）、
 *      DoDiv×3（0xde17c / 0xde1e0 / 0xde204）、DoMod×3（0xde9fc / 0xdeb1c / 0xdeb40）、
 *      iScript_Random（0x110d80）、MainLoop_Process×2（0x1d4a6c / 0x1d4a8c）、GV_CurrentTime（0x1fa298）、
 *      DrawTimingEvents×2（0x224d60 / 0x224d84）、anon_225230（0x225410）、COggAudio::SyncDrawDebug（0x226cf4）、
 *      libvorbis 时间换算 ov_bitrate_instant / ov_time_total / ov_bitrate / ov_time_seek /
 *      ov_time_seek_page / ov_time_tell（0x231248 / 0x231484 / 0x2315c4 / 0x232b3c / 0x232c84 / 0x232d60）
 *      ⇒ GML 的 int64 取余/整除（DoRem/DoDiv/DoMod 的 64 位档）与音频时间轴共用这一个入口。
 *
 * ── open ────────────────────────────────────────────────────────────
 *   1. 除零路径的运行期行为未验：raise(SIGFPE) 在 ART/Android 上默认会终止进程；只有上层装了 handler
 *      且返回，才会观察到期「夹逼高字 + raise 返回值」的商。静态侧只能给出这条路径与寄存器状态。
 *   2. 余数槽的 push {sp,lr} 依赖「STM 基址寄存器在列表里时存写回前的值」这条 ARMv7 规则
 *      （即存进去的是 sub sp 之后的槽地址）；本卡未做活体验证。静态自洽性证据是 helper 的
 *      ldr r12,[sp,#0x18] 与返回后的 pop {r2,r3} 必须指向同一 8 字节，否则余数必然错。
 */

/* ---- 除数为 0？ ---- */
/* @0x319414 cmp r3, #0 */
/* @0x319418 cmpeq r2, #0 */
/* @0x31941c bne 0x31943c <__aeabi_ldivmod+0x28> */
/* ---- 零除数：按被除数符号夹逼（movlt / mvngt） ---- */
/* @0x319420 cmp r1, #0 */
/* @0x319424 cmpeq r0, #0 */
/* @0x319428 movlt r1, #-2147483648 */
/* @0x31942c movlt r0, #0 */
/* @0x319430 mvngt r1, #-2147483648 */
/* @0x319434 mvngt r0, #0 */
/* ---- → __aeabi_ldiv0（raise SIGFPE） ---- */
/* @0x319438 b 0x319458 <__aeabi_ldiv0> */
/* ---- 慢路：预留 8B 余数槽 + 调 helper ---- */
/* @0x31943c sub sp, sp, #8 */
/* @0x319440 push {sp, lr} */
/* @0x319444 bl 0x3195b8 <__gnu_ldivmod_helper> */
/* ---- 取回 lr、把余数装进 r2:r3 ---- */
/* @0x319448 ldr lr, [sp, #0x4] */
/* @0x31944c add sp, sp, #8 */
/* @0x319450 pop {r2, r3} */
/* @0x319454 bx lr */
