/* cally 逆向卡：GetContextStackTop（原版 libyoyo.so，armv7）
 * @func 0xd3a54 0xd3a8c  size 60  15 条（13 条代码 + 2 个字面量池字）
 * 级别: 正文（取值域、空栈返回 0、count-1 的取巧写法、157 个调用点的消费形态全部落锚；open 2 条）
 * 符号: _Z18GetContextStackTopv → YYObjectBase* GetContextStackTop()
 *
 * ── 语义 ─────────────────────────────────────────────────────────────
 *   YYObjectBase* GetContextStackTop() { return g_count > 0 ? g_data[g_count-1] : 0; }
 *
 * ── 两个全局 ─────────────────────────────────────────────────────────
 *   count @ .bss 0x47f280（GOT 槽 0x3edc08）、data @ .bss 0x47f284（GOT 槽 0x3edc10）。
 *   取址全是「pc 相对直取槽内容」的短形式，不建 GOT 基址寄存器：
 *     0xd3a54 取池字 0x0031a1a8，0xd3a58 消费者 PC = 0xd3a60 ⇒ 0xd3a60 + 0x0031a1a8 = 0x3edc08；
 *     0xd3a68 取池字 0x0031a198，0xd3a70 消费者 PC = 0xd3a78 ⇒ 0xd3a78 + 0x0031a198 = 0x3edc10。
 *   判空用 0xd3a64 ble（有符号）⇒ count <= 0 一律返回 0（0xd3a80 / 0xd3a84 两条指令）。
 *   0xd3a6c 的 sub r2, r2, #-1073741823 就是 count-1：0x40000000-1 = 0x3FFFFFFF ≡ -1（mod 2^32），
 *   省一条立即数构造（同 PushContextStack 的 0xd39d4 用 lsls 取容量的手法一致：都是「借立即数」）。
 *   0xd3a78 ldr r0, [r3, r2, lsl #2] ⇒ 元素 4 字节、按 count-1 索引。
 *   本函数不读门字节 0x47f295：门为 0 时 Push 全 no-op，本函数恒返回 0。
 *
 * ── 调用面（157 个 bl 点，无尾跳）──────────────────────────────────────
 *   虚拟机语义层：ExecuteIt、SET_RValue、SET_RValue_Array、GET_RValue×2、CopyRefArrayAndUnref、
 *     DoPushLocal、DoPushGlobal、DoDup、DoPop×2、DoPush×4、DoCall×2、VM::Exec、DoCallScript、
 *     DoOperation、YYGML_CallExtensionFunction、AddConstant、Code_Constant_Find、SetArrayEntry
 *   变量层：RVariable::RVariable×5、RVariable::Assign×2、CVariableList::Alloc、GetVariable、
 *     YYObjectBase::AssignVars、CInstance::Assign、YYObjectBase::Add
 *   DS 层（一大片）：CDS_List/Map/Grid/Priority/Stack/Queue 的 Add/Set/Assign/Replace/Delete/Get_Max|Min…
 *     F_Ds* 系列、dsMapAddRValue、AddStringToGrid
 *   JS 层：F_JS_* 一族（ToObject/ToPrimitive/ToString/ToNumber/Throw/NewArray/NewObject/Call…）
 *   其它：F_Min/F_Max/F_Choose、YYGML_min/max/choose、F_ExternalCall、F_ScriptExecute×2、
 *     F_ActionIf、F_ActionExecuteScript、ProcessGMLCallbacks、F_InstanceDeactivateRegionSpecial×2
 *
 * ── 消费形态：返回值 = GC 写屏障的 parent 实例（本卡实测 12 个点，全部同构）──
 *   top = GetContextStackTop();
 *   DeterminePotentialRoot(top, <刚写进变量的那个对象>);      // 0x191710，两参 YYObjectBase*
 *   实证点：
 *     DoPushLocal 0xd4b6c → 0xd4b74 bl DeterminePotentialRoot；DoPushGlobal 0xd4d04；
 *     DoDup 0xd57d0；SET_RValue 0xd0c64（此点后接 add sp,#12，是「先判空再记根」的变体）；
 *     SET_RValue_Array 0xcfef4；GET_RValue 0xd1510 / 0xd17f0；CopyRefArrayAndUnref 0xd0894；
 *     DoPop 0xe7408 / 0xe7b1c；VM::Exec 0xe8294（top → 写屏障 → 0xe82a0 PopContextStack，push/top/pop 三件套）；
 *     ExecuteIt 0xcfa18；RVariable::RVariable 0x1f5ca0
 *   量化：157 个调用点里 127 个在 7 条指令内 bl 0x191710（DeterminePotentialRoot）。
 *   ⇒ 上下文栈的语义不是「作用域名字表」，而是「当前实例」：谁被压上来，随后写进变量的引用就记在谁名下。
 *     这也解释了 Push 为什么要包住变量解析（DoPop 0xe6b54 push 后按 [inst+0x24] 走变量数），
 *     以及 VM::Exec 为什么在脚本执行窗口里 push 当前实例。
 *
 * ── open ────────────────────────────────────────────────────────────
 *   1. 另外 30 个调用点没走写屏障（有的把返回值直接当实例指针用，如 VM::PokeDSList/PokeDSStack/
 *      PokeDSQueue/PokeDSMap/PokeDSGrid/PokeDSPriority），它们如何解释「空栈返回 0」未逐一核对
 *      （部分点有 cmp r0,#0 判空，未统计全量）。
 *   2. 门为 0 时本函数恒返回 0，写屏障收到 parent=0 的行为未证（DeterminePotentialRoot 对 0 的容忍度本卡未读）。
 */

/* ---- 取 &count → 有符号判空（ble） ---- */
/* @0xd3a54 ldr r3, [pc, #0x2c] */
/* @0xd3a58 ldr r3, [pc, r3] */
/* @0xd3a5c ldr r2, [r3] */
/* @0xd3a60 cmp r2, #0 */
/* @0xd3a64 ble 0xd3a80 <_Z18GetContextStackTopv+0x2c> */
/* ---- 非空：取 &data，count-1 索引 ---- */
/* @0xd3a68 ldr r3, [pc, #0x1c] */
/* @0xd3a6c sub r2, r2, #-1073741823 */
/* @0xd3a70 ldr r3, [pc, r3] */
/* @0xd3a74 ldr r3, [r3] */
/* @0xd3a78 ldr r0, [r3, r2, lsl #2] */
/* @0xd3a7c bx lr */
/* ---- 空栈出口：返回 0 ---- */
/* @0xd3a80 mov r0, #0 */
/* @0xd3a84 bx lr */
/* ---- 字面量池 2 字（相对消费者的槽偏移） ---- */
/* @0xd3a88 eorseq r10, r1, r8, lsr #3 */
/* @0xd3a8c mlaseq r1, r8, r1, r10 */
