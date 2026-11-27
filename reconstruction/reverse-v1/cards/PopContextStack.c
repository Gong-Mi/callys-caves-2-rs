/* cally 逆向卡：PopContextStack（原版 libyoyo.so，armv7）
 * @func 0xd3a34 0xd3a54  size 32  8 条（7 条代码 + 1 个字面量池字）
 * 级别: 正文（唯一动作、下溢保护、与 Push/Top 的门不对称全部落锚；open 2 条见文末）
 * 符号: _Z15PopContextStackv → void PopContextStack()
 *
 * ── 语义 ─────────────────────────────────────────────────────────────
 *   void PopContextStack() { if (g_count > 0) --g_count; }        // 只有这一件事
 *
 * ── 存在哪个全局 ─────────────────────────────────────────────────────
 *   只碰一个全局：count @ .bss 0x47f280，经 GOT 槽 0x3edc08 取址。
 *   取址用的是「pc 相对直取槽内容」的短形式：0xd3a34 取池字 0x0031a1c8，0xd3a38 就是 ldr r3,[pc,r3]，
 *   连 GOT 基址寄存器都不建。同一槽在 PushContextStack 里由 0xd3990 用 GOT 基址形式取，
 *   两条路径必须落在同一地址：0xd3a40 + 0x0031a1c8 = 0x3edc08 = 0x3f1c58 - 0x4050。
 *   （校验法：池字是相对「消费者 PC」的偏移，消费者在 0xd3a38 时 PC = 0xd3a40。）
 *
 * ── 关键负面事实 ─────────────────────────────────────────────────────
 *   1. 不下溢：0xd3a40 cmp r2,#0 之后是 subgt / strgt ⇒ count==0 时一条指令都不写（r3 也不被写回）。
 *   2. 不清槽、不释放、不读 data：函数里没有 data（0x47f284）槽的引用，也没有 FREE_RValue__Pre 一类调用；
 *      弹出的槽内容原样留在数组里，等下一次 Push 覆盖。
 *   3. 不读门字节（0x47f295）：Push 入口要过门，Pop 不过门。推论（不是指令直接给的事实）：
 *      门为 0 期间 Push 全 no-op 而 Pop 照减，成对使用时会让计数偏低；但因为有 0xd3a40 的保护，
 *      结果只可能是「计数偏低」，绝不可能是负数。
 *   4. 无锁、无返回值：0xd3a4c bx lr，r0 在函数体内一次都没被写（声明是 void）。
 *
 * ── 调用面（48 处，34 bl + 14 尾跳 b）──────────────────────────────────
 *   DoPop×5、DoPush、VM::Exec、DoCall、DoCallScript、DoPopLocalVariable、DoCallLibrary、
 *   Code_Constant_Find、YYObjectBase::Add、Variable_Scope_SetVar、Variable_Scope_DeleteVar、
 *   SetArrayEntry、JS_DefineOwnProperty_Internal×5、CreateArgumentsObject×2、
 *   Call_Accessor_Get×3、Call_Accessor_Set×3、Call_ScriptRef、JS_Argument_Put×2、
 *   F_JS_Object_getOwnPropertyNames、F_JS_Object_keys
 *   与 Push 的 42 个点相比少 8 个函数（AddConstant、Variable_Global_SetVar、F_NewGMLArray、
 *   JS_Argument_Get、F_JSNewArray/F_JSNew/F_JSNewObject/F_JSArrayCall 系列、unshift）——
 *   那些点只压不弹，或弹在别的函数里，本卡不建配对表。
 *
 * ── open ────────────────────────────────────────────────────────────
 *   1. 14 处尾跳（b 0xd3a34）说明存在「pop 后直接返回」的收尾模板；哪些调用点与哪个 Push 配对
 *      没有逐对建表（本卡只给调用面与计数，不给配对图）。
 *   2. data 里的元素会不会被别处直接读（绕过 Top）：本函数不读；对 data 槽的反查只按 GOT 字面量做，
 *      没有做「pc 相对形式」的穷举，可能漏掉个别直读点。
 */

/* ---- 取 &count → 有符号判空 → 减一 ---- */
/* @0xd3a34 ldr r3, [pc, #0x14] */
/* @0xd3a38 ldr r3, [pc, r3] */
/* @0xd3a3c ldr r2, [r3] */
/* @0xd3a40 cmp r2, #0 */
/* @0xd3a44 subgt r2, r2, #1 */
/* @0xd3a48 strgt r2, [r3] */
/* @0xd3a4c bx lr */
/* ---- 字面量池 1 字（相对消费者的槽偏移） ---- */
/* @0xd3a50 eorseq r10, r1, r8, asr #3 */
