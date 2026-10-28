/* cally 逆向卡：DoRegExpExec（原版 libyoyo.so，armv7）
 * @func 0x24f2b0 0x24f4b8  size 520  130 条（0x24f490..0x24f4b4 十个字是 literal pool，非指令）
 * 级别: 正文（pcre 调用、成功/失败两条出口、错误跳表六条消息、NOMATCH 自循环全部逐条锚定）
 * 符号: _Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i
 *   → int DoRegExpExec(YYObjectBase* re, const char* subject, int length,
 *                      int* ovector, int ovecsize, int* outCount, int startoffset)
 * 调用者: JS_String_prototype_replace_RegEx（0x258e3c），调用点 0x258f78（首查）与 0x259120（g 循环续查）；
 *         两次都把 ovecsize 固定给 100、把上一次返回值当下一次 startoffset。
 *
 * ── 入参与帧 ─────────────────────────────────────────────────
 *   push 9 regs(36) + sub sp,#68 ⇒ sp = 入口 sp-104，故 [sp+0x68]=第5参、[sp+0x6c]=第6参、[sp+0x70]=第7参
 *   r5=re   r10=subject   r7=length   r8=ovector   r11=ovecsize
 *   0x24f2dc ldr r12,[sp,#0x68] 取 ovecsize；0x24f2d0 ldr r6,[sp,#0x70] 取 startoffset
 *   0x24f2e8 lsr r9,r6,#31 ⇒ r9 = (startoffset<0)
 *   re 对象里的 pcre 句柄：+0x1c = pcre*（0x24f35c），+0x20 = pcre_extra*（0x24f360）
 *
 * ── 循环顶：先判 start 是否越界 ──────────────────────────────
 *   0x24f340 cmp r6,r7 / 0x24f344 movle r4,r9 / 0x24f348 orrgt r4,r9,#1
 *   ⇒ options = (startoffset<=length) ? (startoffset<0) : ((startoffset<0)|1)
 *   0x24f350 cmp r4,#0 / 0x24f358 bne 0x24f44c
 *   ⇒ startoffset<0 或 startoffset>length 时 options!=0（PCRE_NOTBOL=1）→ 直接走失败收尾，不调 pcre_exec
 *
 * ── pcre_exec ───────────────────────────────────────────────
 *   实参：r0=[re+0x1c]、r1=[re+0x20]、r2=subject、r3=length、[sp]=startoffset、
 *         [sp+4]=options、[sp+8]=ovector、[sp+0xc]=ovecsize（0x24f364 str / 0x24f368 stmib）
 *   0x24f36c 调 pcre_exec(0x279390)；0x24f370 cmp r0,#0 / 0x24f374 blt 0x24f3c4
 *
 * ── 成功路径 rc>=0 ──────────────────────────────────────────
 *   0x24f378 add r8,r8,r0,lsl #3 ⇒ ovector + rc*8；0x24f37c mov r11,r0（rc 转存）
 *   0x24f388 ldr r5,[r8,#-0x4] ⇒ lastEnd = ovector[2*rc-1]（最后一个捕获的结束偏移）
 *   0x24f398 vmov s13,r5 / 0x24f3a0 vcvt.f64.s32 d7,s13 ⇒ (double)lastEnd
 *   0x24f3a8 strd r6,r7,[r1,#-16]!（写 RValue 值 8 字节，r1 落到 sp+48）
 *   0x24f394 str r4,[sp,#0x3c] ⇒ RValue tag = 0（real；此路 r4 必为 0）
 *   0x24f3ac 调 JS_Object_Put(re, &rv, "lastIndex", true)：名串 0x3560a8，第 4 实参 r3=1（0x24f38c）
 *   0x24f3b0 ldr r7,[sp,#0x6c] / 0x24f3b8 str r11,[r7] ⇒ *outCount = rc
 *   0x24f3b4 mov r0,r5 ⇒ 返回值 = lastEnd（不是 rc！）
 *
 * ── 失败路径：跳表（索引 = rc+6，基址 = 0x24f3d4 = 0x24f3cc+8）──
 *   0x24f3c4 add r0,r0,#6 / 0x24f3c8 cmp r0,#5 / 0x24f3cc addls pc,pc,r0,lsl #2
 *   0x24f3d0 b 0x24f484                                （默认：rc<-6）
 *   rc=-6 NOMEMORY       → 0x24f3d4 → 0x24f440 → 名串 [sp+0x1c]
 *   rc=-5 UNKNOWN_NODE   → 0x24f3d8 → 0x24f434 → 名串 [sp+0x20]
 *   rc=-4 BADMAGIC       → 0x24f3dc → 0x24f428 → 名串 [sp+0x24]
 *   rc=-3 BADOPTION      → 0x24f3e0 → 0x24f41c → 名串 [sp+0x28]
 *   rc=-2 NULL           → 0x24f3e4 → 0x24f3f8 → 名串 [sp+0x2c]
 *   rc=-1 NOMATCH        → 0x24f3e8 → 0x24f3ec：startoffset++ 后回 0x24f340 重试（不报错、不返回）
 *   六条消息串（rodata，0x24f2c0..0x24f328 六对 ldr/add 写入 [sp+0x18..0x2c]）：
 *     "unkown error\n" 0x356140 / "PCRE_ERROR_NOMEMORY error\n" 0x356124 /
 *     "PCRE_ERROR_BADMAGIC error\n" 0x3560e8 / "PCRE_ERROR_BADOPTION error\n" 0x3560cc /
 *     "PCRE_ERROR_UNKNOWN_NODE error\n" 0x356104 / "PCRE_ERROR_NULL error\n" 0x3560b4（原文拼写 unkown）
 *   报错方式（0x24f400..0x24f414）：r2=GOT 基址 0x3f1c58（0x24f32c 存的 [sp+0x14]），
 *     r3 = [GOT 基址-0x453c] = GOT 项 0x3ed71c → 0x3eb70c → .bss 0x47a118 的单例对象，
 *     再 ldr r0,[r3] / ldr r3,[r0] / ldr r3,[r3,#0xc] / blx r3 ⇒ g_pConsole->vtable[3](msg, GOT)
 *     该 vtable（vptr=0x3eb6e0，由 .init_array 里 0x0b9440 的构造写入）第 4 项 = 0xc481c = TConsole::Output(char const*,...)
 *   0x24f418 报错后回 0x24f340（startoffset 未推进）⇒ 持续性错误会一直重打同一句
 *
 * ── 失败收尾（0x24f44c..0x24f480）────────────────────────────
 *   RValue = {0.0, tag 0}（0x24f468 strd r4,r5 清零 8 字节、0x24f470 tag=0）
 *   名串仍是 "lastIndex"（0x24f450 取 0x106c34），但 JS_Object_Put 第 4 实参 r3=0（非严格）
 *   0x24f478 mvn r0,#0 ⇒ 返回 -1
 *
 * 结论（本卡新增五条硬事实）:
 *   1. re 对象把 pcre 句柄存在 +0x1c/+0x20，本函数不碰 pattern 串——匹配器是外部 pcre，
 *      这也解释了 DoReplace 只出现 pcre_free_substring 而从不 pcre_exec。
 *   2. 返回值是 ovector[2*rc-1]（末个捕获的结束偏移），rc 通过 *outCount 侧路输出；
 *      调用方正是拿这个返回值当下一次 startoffset（0x2591e4 mov r9,r8）。
 *   3. NOMATCH 由本函数自己线性推进：每次 startoffset++ 重来一遍 pcre_exec，不做 pcre 的
 *      「从失败点续搜」优化；这也解释了它为什么必须自己判 startoffset>length。
 *   4. 成功路径写 lastIndex 用严格模式（r3=1）、失败路径用非严格（r3=0），两边同名 "lastIndex"、
 *      值 0.0 —— 与 JS_String_prototype_replace_RegEx 用 lastIndex 判「还有没有下一处」一致。
 *   5. startoffset<0 或 >length 时不进 pcre，直接置 lastIndex=0 返回 -1；即「越界即无匹配」。
 * open:
 *   1. 报错汇聚点的动态类型：0x47a118 的 vptr 在静态构造里被写成 0x3eb6e0（TConsole 的 vtable），
 *      而 TConsole::Output 是 3 条指令的空实现（0xc481c push{r1,r2,r3}; add sp,#12; bx lr）——
 *      若运行期不被换成 TRelConsole（vtable 0x3eb6f8，Output 在 0xc4890），错误串等于丢弃；
 *      无论哪种，报错后回到循环顶都意味着 rc<-1 的持续性错误会死循环。
 *   2. rc==0（ovector 太小）也落进成功路径，此时 r8+0 后读 [r8-4] 即 ovector[-1]；调用方固定给 100，
 *      实际触发条件未证。
 *   3. pcre_exec 之外的 pcre_fullinfo/pcre_get_substring 都在调用者里，ovector 的容量契约（100）由调用者硬编码。
 */

/* ── 锚点（逐条对应 asm/index-DoRegExpExec.tsv，脚本生成，勿手改）── */
/* @0x24f2b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24f2b4 sub sp, sp, #68 */
/* @0x24f2b8 mov r10, r1 */
/* @0x24f2bc mov r7, r2 */
/* @0x24f2c0 ldr r1, [pc, #0x1c8] */
/* @0x24f2c4 mov r8, r3 */
/* @0x24f2c8 ldr r2, [pc, #0x1c4] */
/* @0x24f2cc mov r5, r0 */
/* @0x24f2d0 ldr r6, [sp, #0x70] */
/* @0x24f2d4 add r1, pc, r1 */
/* @0x24f2d8 add r2, pc, r2 */
/* @0x24f2dc ldr r12, [sp, #0x68] */
/* @0x24f2e0 str r1, [sp, #0x18] */
/* @0x24f2e4 str r2, [sp, #0x1c] */
/* @0x24f2e8 lsr r9, r6, #31 */
/* @0x24f2ec ldr r1, [pc, #0x1a4] */
/* @0x24f2f0 mov r11, r12 */
/* @0x24f2f4 ldr r2, [pc, #0x1a0] */
/* @0x24f2f8 add r1, pc, r1 */
/* @0x24f2fc ldr r3, [pc, #0x19c] */
/* @0x24f300 add r2, pc, r2 */
/* @0x24f304 str r1, [sp, #0x24] */
/* @0x24f308 str r2, [sp, #0x28] */
/* @0x24f30c add r3, pc, r3 */
/* @0x24f310 ldr r1, [pc, #0x18c] */
/* @0x24f314 ldr r2, [pc, #0x18c] */
/* @0x24f318 str r3, [sp, #0x20] */
/* @0x24f31c add r1, pc, r1 */
/* @0x24f320 mov r3, #0 */
/* @0x24f324 add r2, pc, r2 */
/* @0x24f328 str r1, [sp, #0x2c] */
/* @0x24f32c str r2, [sp, #0x14] */
/* @0x24f330 str r3, [sp, #0x30] */
/* @0x24f334 str r3, [sp, #0x34] */
/* @0x24f338 str r3, [sp, #0x38] */
/* @0x24f33c str r3, [sp, #0x3c] */
/* @0x24f340 cmp r6, r7 */
/* @0x24f344 movle r4, r9 */
/* @0x24f348 orrgt r4, r9, #1 */
/* @0x24f34c mov r2, r10 */
/* @0x24f350 cmp r4, #0 */
/* @0x24f354 mov r3, r7 */
/* @0x24f358 bne 0x24f44c <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x19c> */
/* @0x24f35c ldr r0, [r5, #0x1c] */
/* @0x24f360 ldr r1, [r5, #0x20] */
/* @0x24f364 str r6, [sp] */
/* @0x24f368 stmib sp, {r4, r8, r11} */
/* @0x24f36c bl 0x279390 <pcre_exec> */
/* @0x24f370 cmp r0, #0 */
/* @0x24f374 blt 0x24f3c4 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x114> */
/* @0x24f378 add r8, r8, r0, lsl #3 */
/* @0x24f37c mov r11, r0 */
/* @0x24f380 mov r0, r5 */
/* @0x24f384 add r1, sp, #64 */
/* @0x24f388 ldr r5, [r8, #-0x4] */
/* @0x24f38c mov r3, #1 */
/* @0x24f390 ldr r2, [pc, #0x114] */
/* @0x24f394 str r4, [sp, #0x3c] */
/* @0x24f398 vmov s13, r5 */
/* @0x24f39c add r2, pc, r2 */
/* @0x24f3a0 vcvt.f64.s32 d7, s13 */
/* @0x24f3a4 vmov r6, r7, d7 */
/* @0x24f3a8 strd r6, r7, [r1, #-16]! */
/* @0x24f3ac bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24f3b0 ldr r7, [sp, #0x6c] */
/* @0x24f3b4 mov r0, r5 */
/* @0x24f3b8 str r11, [r7] */
/* @0x24f3bc add sp, sp, #68 */
/* @0x24f3c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24f3c4 add r0, r0, #6 */
/* @0x24f3c8 cmp r0, #5 */
/* @0x24f3cc addls pc, pc, r0, lsl #2 */
/* @0x24f3d0 b 0x24f484 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x1d4> */
/* @0x24f3d4 b 0x24f440 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x190> */
/* @0x24f3d8 b 0x24f434 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x184> */
/* @0x24f3dc b 0x24f428 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x178> */
/* @0x24f3e0 b 0x24f41c <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x16c> */
/* @0x24f3e4 b 0x24f3f8 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x148> */
/* @0x24f3e8 b 0x24f3ec <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x13c> */
/* @0x24f3ec add r6, r6, #1 */
/* @0x24f3f0 lsr r9, r6, #31 */
/* @0x24f3f4 b 0x24f340 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x90> */
/* @0x24f3f8 ldr r3, [pc, #0xb0] */
/* @0x24f3fc ldr r1, [sp, #0x2c] */
/* @0x24f400 ldr r2, [sp, #0x14] */
/* @0x24f404 ldr r3, [r2, r3] */
/* @0x24f408 ldr r0, [r3] */
/* @0x24f40c ldr r3, [r0] */
/* @0x24f410 ldr r3, [r3, #0xc] */
/* @0x24f414 blx r3 */
/* @0x24f418 b 0x24f340 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x90> */
/* @0x24f41c ldr r3, [pc, #0x8c] */
/* @0x24f420 ldr r1, [sp, #0x28] */
/* @0x24f424 b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f428 ldr r3, [pc, #0x80] */
/* @0x24f42c ldr r1, [sp, #0x24] */
/* @0x24f430 b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f434 ldr r3, [pc, #0x74] */
/* @0x24f438 ldr r1, [sp, #0x20] */
/* @0x24f43c b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f440 ldr r3, [pc, #0x68] */
/* @0x24f444 ldr r1, [sp, #0x1c] */
/* @0x24f448 b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f44c add r1, sp, #64 */
/* @0x24f450 ldr r2, [pc, #0x5c] */
/* @0x24f454 mov r12, #0 */
/* @0x24f458 mov r0, r5 */
/* @0x24f45c mov r4, #0 */
/* @0x24f460 mov r5, #0 */
/* @0x24f464 mov r3, r12 */
/* @0x24f468 strd r4, r5, [r1, #-16]! */
/* @0x24f46c add r2, pc, r2 */
/* @0x24f470 str r12, [sp, #0x3c] */
/* @0x24f474 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24f478 mvn r0, #0 */
/* @0x24f47c add sp, sp, #68 */
/* @0x24f480 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24f484 ldr r3, [pc, #0x24] */
/* @0x24f488 ldr r1, [sp, #0x18] */
/* @0x24f48c b 0x24f400 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i+0x150> */
/* @0x24f490 andseq r6, r0, r4, ror #28 */
/* @0x24f494 andseq r6, r0, r4, asr #28 */
/* @0x24f498 andseq r6, r0, r8, ror #27 */
/* @0x24f49c andseq r6, r0, r4, asr #27 */
/* @0x24f4a0 ldrsheq r6, [r0], -r0 */
/* @0x24f4a4 mulseq r0, r0, sp */
/* @0x24f4a8 andseq r2, r10, r12, lsr #18 */
/* @0x24f4ac andseq r6, r0, r4, lsl #26 */
/* @0x24f4b0 .word 0xffffbac4 */
/* @0x24f4b4 andseq r6, r0, r4, lsr r12 */
