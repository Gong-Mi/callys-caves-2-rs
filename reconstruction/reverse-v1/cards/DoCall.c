/* cally 逆向卡：DoCall（原版 libyoyo.so，armv7）
 * @func 0xe8b48 0xe9790  size 3144  786 条（0xe9744..0xe978c 为 literal pool）
 * 级别: 正文（kind 分流、id 区间、五条调用路径、实参释放与结果回填已证；kind5 的 JS 对象内部与 profiling 实参未展开）
 * 符号: _Z6DoCalljPhPKhP6VMExec → uchar* DoCall(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 * 位置: 紧接 DoCallGML(0xe8b00..0xe8b48)，两者共用下游 DoCallScript(0xe8588..0xe8afc，350 条)
 *
 * ── 顶层：只有两种 kind ───────────────────────────────────────
 *   kind = arg[19:16]（@0xe8b48 ubfx r12,r0,#0x10,#0x4）
 *   argc = (uint16)arg（@0xe8bec uxth r6,r0）—— 与 DoCallGML 一致，实参个数取低 16 位
 *   kind == 2 → @0xe8be0 「按 id 调用」；kind == 5 → @0xe8b94 「按 RValue 调用」
 *   其它 → VMError(exec, "DoCall :: Execution Engine type error")（@0xe8b74）并原样返回 sp
 *   帧 76 字节，全部临时 RValue 在帧内（out 槽 sp+56 = 0x38，另一个 sp+40 = 0x28）
 *
 * ── kind 2：id = *(int*)base，按区间四分流（@0xe8be0..@0xe8c18）──────────
 *   id <= 99999      (@0xe8be4 movw r3,#0x869f @0xe8be8 movt r3,#0x1；@0xe8bf0 cmp；@0xe8bf4 ble) → 内建函数
 *   id >  500000     (@0xe8bf8 movw #0xa120 @0xe8bfc movt #0x7；@0xe8c00 cmp；@0xe8c04 bgt)              → 扩展 DLL
 *   id == 499999     (@0xe8c08 movw #0xa11f @0xe8c0c movt #0x7；@0xe8c10 cmp；@0xe8c14 beq)              → 间接脚本
 *   其余             → 脚本：Script_Data(id-100000)（@0xe8c18 sub #99328 / @0xe8c1c sub #672）
 *   注：判据是严格 bgt，所以 id == 500000 不落扩展路，会走脚本路算成 Script_Data(400000)（open 1）
 *
 * ── 路径 A：脚本（@0xe8c20..@0xe8c40）──────────────────────────
 *   scr = Script_Data(id-100000)（@0xe8c20）
 *   DoCallScript(scr, argc, sp, exec, NULL, NULL) —— @0xe8c34/@0xe8c38 先把两个栈槽清 0（第 5/6 实参）
 *   返回值直接当新 sp（@0xe8c40 mov r11,r0 → 尾部 pop）
 *   这条就是 DoCallGML 的全部内容（DoCallGML 只是把 id 固定取自 *(uint32*)base）
 *
 * ── 路径 B：内建函数（@0xe8d0c..@0xe8d80）───────────────────────
 *   entry = builtinTable + id*80：@0xe8d18 add r10,r2,r2,lsl #2（=id*5）→ @0xe8d44 add r10,r0,r10,lsl #4（×16）
 *   fn = [entry+0x40]（@0xe8d70），[global] 暂存 entry（@0xe8d74/@0xe8d78），blx r12（@0xe8d7c）
 *   调用协议：fn(r0=&out(sp+56), r1=exec[0x14], r2=exec[0x18], r3=argc, [sp]=sp)（@0xe8d50..@0xe8d6c）
 *   out 先 16 字节清零（@0xe8d20..@0xe8d2c）
 *   profiling：全局字节 A（@0xe8d40 ldrb）非 0 → CProfiler::Push（@0xe9014/@0xe901c），返回后同样判 A → CProfiler::Pop（@0xe9004/@0xe900c）
 *   [global] = exec（@0xe8c8c / @0xe8d98）
 *
 * ── 路径 C：扩展 DLL（@0xe8c50..@0xe8c7c）──────────────────────
 *   idx = id-500000（@0xe8c54 sub #499712 / @0xe8c58 sub #288，即 0x7A120）
 *   out = sp+56 先 16 字节清零（@0xe8c60/@0xe8c64/@0xe8c68/@0xe8c70/@0xe8c74）
 *   Extension_Call_DLL_Function(idx, argc, sp, &out)（@0xe8c7c）→ 之后 [global] = exec（@0xe8c8c）
 *
 * ── 路径 D：间接脚本（@0xe9024..@0xe9040）──────────────────────
 *   n = YYGetInt32(sp, 0)（@0xe902c）；sp += 16（@0xe9030）；argc -= 1（@0xe9034）；id = n + 100000（@0xe9038/@0xe903c）
 *   → 落回路径 A。即「脚本 id 由栈顶 RValue 给出」的写法（低 16 位不再当 argc 的用法只有这一支）
 *
 * ── 三条路的共同收尾（@0xe8c80..@0xe8d04）─────────────────────
 *   逐槽释放 argc 个实参（@0xe8ca4..@0xe8ce0 与 @0xe8dcc..@0xe8e04 两份同构循环）：
 *     tag-1 清 bits31..24 再清 bits1..0 得 0（即 tag 1..4）→ FREE_RValue__Pre(slot)；随后 [slot+0]=0、[slot+8]=0、tag=5（undefined），槽 +16
 *   sp += argc*16（@0xe8ce0 add r4,r4,r8,lsl #4）
 *   结果 16 字节从 out(sp+56) 拷到 sp-16（@0xe8ce4 ldm r7! / @0xe8cf0..@0xe8d00），返回 sp-16（@0xe8ce8 sub r12,r4,#16）
 *   ⇒ 净效果：弹掉 argc 个实参，压回 1 个返回值
 *   全局字节 B（@0xe8da8 ldrb）非 0 时跳过上述释放直接返回（@0xe8db0 bne）
 *
 * ── kind 5：调用「可调用 RValue」（@0xe8b94..）────────────────────
 *   tag = [sp+0xc] & 0x00FFFFFF（@0xe8b94/@0xe8b9c）
 *   tag == 6 → 对象路（@0xe8ba4）；tag == 0x00FFFFFF（变量引用）→ JSThrowReferenceError("Invalid callv target")（@0xe8ff4/@0xe8ffc）
 *   其它 → 若全局字节非 0 则直接返回 sp（@0xe8bb4..@0xe8bc4），否则 JSThrowTypeError("Invalid callv target #2")（@0xe8bc8/@0xe8bd0），返回 sp+16
 *   对象路（@0xe8e08..）：
 *     obj = [sp]（@0xe8e08）；[obj+0x48] != 3 → 同一错误（@0xe8e0c/@0xe8e14）
 *     scr = [obj+0x64]（@0xe8e18）；scr == 0 → 原生回调 [obj+0x68]（@0xe9074，@0xe9110 blx r10，前后 PushContextStack/PopContextStack）
 *     scr != 0 → code = GetCode(scr)：code->flags & 4 == 0 → YYAllocLocalStackNew 建局部栈（@0xe91a8；[obj+0x78] == 6 时把 [obj+0x6c] 写进新栈 +0xc）
 *     [obj+0x88] == 6 → FindValue("[[BoundArgs]]")（@0xe9200 或 @0xe947c）→ 按 tag 15 路表把绑定实参逐槽搬进实参区（@0xe92e4 表，body @0xe932c..@0xe936c）
 *     this：([sp+0x1c]&0x00FFFFFF) ∈ {3,6} → [sp+0x10]（@0xe8e64..@0xe8e78 / @0xe9044）；
 *           否则 F_JS_ToObject(&out, sp+16)（@0xe8e7c），返回 1 → VMError "could not convert rvalue of kind=%d to object"（@0xe9634）
 *     默认参数补齐：槽索引取自全局（!= -1 则用它，否则 Code_Variable_Find_Slot_From_Name(obj,"length")，@0xe93fc/@0xe9408），
 *           读出该槽 double 上限 p（@0xe8ec4 ldm）；p > argc 且 (int)p > argc → memmove 把 argc 个实参整体下移 (p-argc) 槽（@0xe8f04），
 *           尾部空槽填 tag 5（@0xe8f1c..@0xe8f30），argc 改为 p（@0xe8f38）
 *     code->flags & 1（@0xe8f4c ands）为 1 → CreateArgumentsObject(&args, this, argc, sp, true)（@0xe8f84），作为第 6 实参
 *     DoCallScript(scr, argc, sp, exec, this, argsObj)（@0xe8fa4 / @0xe9050 两个调用点：@0xe8fa4 传 arguments 对象，@0xe9068 传 NULL）
 *     返回后：this != 0 且 (code->flags & 2) == 0 → exec->[0xc] = 0（@0xe8fc4）；exec->[0x14] = 原值（@0xe8fdc）；释放 this（@0xe8fe8）
 *     原生回调缺失时 JSThrowTypeError("Invalid callv target #1")（@0xe9698/@0xe96a0）
 *
 * ── 与 DoCallScript / DoCallGML 的三层关系（本卡重点）──────────────
 *   DoCallGML  0xe8b00  72B : 特化层。id 只从 *(uint32*)base 取，固定 Script_Data(id-100000)，
 *                              argc = (uint16)arg，DoCallScript(scr, argc, sp, exec, NULL, NULL)。= 本卡路径 A。
 *   DoCall     0xe8b48 3144B: 通用层。先按 id 区间判「内建/脚本/间接/扩展」，再按 kind 判「2=按 id / 5=按 RValue」；
 *                              只有脚本路(A/D)与 kind5 路才进 DoCallScript，内建路(B)与扩展路(C)是直接 blx / 直接调用。
 *   DoCallScript 0xe8588    : 执行层（帧压栈）。frame = sp-60；把 exec 的 +0x14/+0x18/+0x2c/+0x30/+0x34/+0x38/+0x3c/+0x44
 *                              搬进 [frame+0x04..+0x38]，旧 sp 存 frame+0，然后 [exec+0x28] = frame、[exec+0x2c] = code、
 *                              [exec+0x44] = code[0x6c]、[exec+0x50] = base[4]、[exec+0x24] = base[0x10] ——
 *                              PerformReturn(0xe42d8) 正是把这套倒着弹回（[exec+0x4c] 帧深度自减）。
 *   一句话：DoCallGML 是 DoCall 脚本路的特化，DoCall 是 id 空间的总闸，DoCallScript 是唯一的压帧入口。
 *           id 空间：<100000 内建、100000..499998 脚本（索引 id-100000）、499999 间接、>500000 扩展（索引 id-500000）。
 *
 * 结论（新增四条硬事实）:
 *   1. DoCall 的 kind 只有 2 和 5；这与 DoCallGML 里「无 kind 分支」互补 —— DoCallGML 是 kind 2 的脚本子集。
 *   2. 脚本 id 基址 100000 在 DoCall 里被写成两条减法（-99328 再 -672）而不是字面量，与 DoCallGML 完全同构，
 *      可判定为同一个 Script_Data 索引约定，不是两套。
 *   3. 内建函数表项 80 字节、函数指针在项内 +0x40；调用协议是 (RValue* ret, exec[0x14], exec[0x18], argc, sp)。
 *   4. 「弹 argc 个实参、压回 1 个返回值」对所有路径统一在 @0xe8ce4 收口，且实参释放会先把 tag 1..3 的槽
 *      FREE_RValue__Pre 再写成 tag 5（undefined）—— 这解释了 tag 5 在 DoConv/boxType 里反复出现的身份。
 * open:
 *   1. id == 500000 的归属（既不 >500000 也不 ==499999，落到脚本路变成 Script_Data(400000)）。
 *   2. 内建表项 80 字节的其余字段（+0 起）、CProfiler::Push/Pop 的两个 int 实参来源。
 *   3. kind5 里 [obj+0x48]==3 的类型枚举、[obj+0x78]/[obj+0x88] 的取值域（只证到 ==6 分支）。
 *   4. 两个全局字节（A=profiling、B=跳过释放）的符号名。
 *
 * ── 结构（本批证到，逐条锚在下方）: 调用 GML 脚本 ──
 *   CScript::GetCode ×3 + DoCallScript ×3（三个调用入口，形参顺序待逐条确认）；FREE_RValue__Pre ×7 释放实参；YYFree ×4 / operator delete ×4；VMError ×3
 *   ⚠ LOCK_RVALUE_MUTEX / UNLOCK_RVALUE_MUTEX 在本库是单条 `bx lr` 空桩（0x190f2c / 0x190f30），
 *     本函数里出现的「加锁」按无锁读，不写「有锁保护」。
 *   open: 三个 DoCallScript 调用点的形参与栈布局、脚本缺失时的错误路径
 */
/* @0xe8b48 ubfx r12, r0, #0x10, #0x4 */
/* @0xe8b4c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe8b50 cmp r12, #2 */
/* @0xe8b54 ldr r5, [pc, #0xbe8] */
/* @0xe8b58 sub sp, sp, #76 */
/* @0xe8b5c mov r4, r1 */
/* @0xe8b60 mov r9, r3 */
/* @0xe8b64 add r5, pc, r5 */
/* @0xe8b68 beq 0xe8be0 <_Z6DoCalljPhPKhP6VMExec+0x98> */
/* @0xe8b6c cmp r12, #5 */
/* @0xe8b70 beq 0xe8b94 <_Z6DoCalljPhPKhP6VMExec+0x4c> */
/* @0xe8b74 ldr r1, [pc, #0xbcc] */
/* @0xe8b78 mov r0, r3 */
/* @0xe8b7c add r1, pc, r1 */
/* @0xe8b80 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe8b84 mov r11, r4 */
/* @0xe8b88 mov r0, r11 */
/* @0xe8b8c add sp, sp, #76 */
/* @0xe8b90 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8b94 ldr r3, [r1, #0xc] */
/* @0xe8b98 add r11, r1, #16 */
/* @0xe8b9c bic r3, r3, #-16777216 */
/* @0xe8ba0 cmp r3, #6 */
/* @0xe8ba4 beq 0xe8e08 <_Z6DoCalljPhPKhP6VMExec+0x2c0> */
/* @0xe8ba8 mvn r2, #-16777216 */
/* @0xe8bac cmp r3, r2 */
/* @0xe8bb0 beq 0xe8ff4 <_Z6DoCalljPhPKhP6VMExec+0x4ac> */
/* @0xe8bb4 ldr r3, [pc, #0xb90] */
/* @0xe8bb8 ldr r3, [r5, r3] */
/* @0xe8bbc ldrb r3, [r3] */
/* @0xe8bc0 cmp r3, #0 */
/* @0xe8bc4 bne 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe8bc8 ldr r0, [pc, #0xb80] */
/* @0xe8bcc add r0, pc, r0 */
/* @0xe8bd0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe8bd4 mov r0, r11 */
/* @0xe8bd8 add sp, sp, #76 */
/* @0xe8bdc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8be0 ldr r2, [r2] */
/* @0xe8be4 movw r3, #0x869f */
/* @0xe8be8 movt r3, #0x1 */
/* @0xe8bec uxth r6, r0 */
/* @0xe8bf0 cmp r2, r3 */
/* @0xe8bf4 ble 0xe8d0c <_Z6DoCalljPhPKhP6VMExec+0x1c4> */
/* @0xe8bf8 movw r3, #0xa120 */
/* @0xe8bfc movt r3, #0x7 */
/* @0xe8c00 cmp r2, r3 */
/* @0xe8c04 bgt 0xe8c50 <_Z6DoCalljPhPKhP6VMExec+0x108> */
/* @0xe8c08 movw r3, #0xa11f */
/* @0xe8c0c movt r3, #0x7 */
/* @0xe8c10 cmp r2, r3 */
/* @0xe8c14 beq 0xe9024 <_Z6DoCalljPhPKhP6VMExec+0x4dc> */
/* @0xe8c18 sub r0, r2, #99328 */
/* @0xe8c1c sub r0, r0, #672 */
/* @0xe8c20 bl 0x1e069c <_Z11Script_Datai> */
/* @0xe8c24 mov r12, #0 */
/* @0xe8c28 mov r1, r6 */
/* @0xe8c2c mov r2, r4 */
/* @0xe8c30 mov r3, r9 */
/* @0xe8c34 str r12, [sp] */
/* @0xe8c38 str r12, [sp, #0x4] */
/* @0xe8c3c bl 0xe8588 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_> */
/* @0xe8c40 mov r11, r0 */
/* @0xe8c44 mov r0, r11 */
/* @0xe8c48 add sp, sp, #76 */
/* @0xe8c4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8c50 add r7, sp, #72 */
/* @0xe8c54 sub r0, r2, #499712 */
/* @0xe8c58 mov r8, #0 */
/* @0xe8c5c sub r0, r0, #288 */
/* @0xe8c60 str r8, [sp, #0x44] */
/* @0xe8c64 mov r1, r6 */
/* @0xe8c68 str r8, [sp, #0x40] */
/* @0xe8c6c mov r2, r4 */
/* @0xe8c70 str r8, [sp, #0x3c] */
/* @0xe8c74 str r8, [r7, #-0x10]! */
/* @0xe8c78 mov r3, r7 */
/* @0xe8c7c bl 0xf6344 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_> */
/* @0xe8c80 ldr r3, [pc, #0xacc] */
/* @0xe8c84 cmp r6, r8 */
/* @0xe8c88 ldr r3, [r5, r3] */
/* @0xe8c8c str r9, [r3] */
/* @0xe8c90 beq 0xe8ce4 <_Z6DoCalljPhPKhP6VMExec+0x19c> */
/* @0xe8c94 mov r5, r4 */
/* @0xe8c98 mov r9, r8 */
/* @0xe8c9c mov r10, #5 */
/* @0xe8ca0 b 0xe8cb8 <_Z6DoCalljPhPKhP6VMExec+0x170> */
/* @0xe8ca4 cmp r8, r6 */
/* @0xe8ca8 str r9, [r5, #0x8] */
/* @0xe8cac str r10, [r5, #0xc] */
/* @0xe8cb0 str r9, [r5], #16 */
/* @0xe8cb4 beq 0xe8ce0 <_Z6DoCalljPhPKhP6VMExec+0x198> */
/* @0xe8cb8 ldr r3, [r5, #0xc] */
/* @0xe8cbc add r8, r8, #1 */
/* @0xe8cc0 sub r3, r3, #1 */
/* @0xe8cc4 bic r3, r3, #-16777216 */
/* @0xe8cc8 bic r3, r3, #3 */
/* @0xe8ccc cmp r3, #0 */
/* @0xe8cd0 bne 0xe8ca4 <_Z6DoCalljPhPKhP6VMExec+0x15c> */
/* @0xe8cd4 mov r0, r5 */
/* @0xe8cd8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe8cdc b 0xe8ca4 <_Z6DoCalljPhPKhP6VMExec+0x15c> */
/* @0xe8ce0 add r4, r4, r8, lsl #4 */
/* @0xe8ce4 ldm r7!, {r0, r1, r2, r3} */
/* @0xe8ce8 sub r12, r4, #16 */
/* @0xe8cec mov r11, r12 */
/* @0xe8cf0 str r0, [r4, #-0x10] */
/* @0xe8cf4 str r1, [r4, #-0xc] */
/* @0xe8cf8 mov r0, r11 */
/* @0xe8cfc str r2, [r4, #-0x8] */
/* @0xe8d00 str r3, [r4, #-0x4] */
/* @0xe8d04 add sp, sp, #76 */
/* @0xe8d08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8d0c ldr r3, [pc, #0xa44] */
/* @0xe8d10 mov r1, #0 */
/* @0xe8d14 ldr r0, [pc, #0xa40] */
/* @0xe8d18 add r10, r2, r2, lsl #2 */
/* @0xe8d1c ldr r3, [r5, r3] */
/* @0xe8d20 str r1, [sp, #0x38] */
/* @0xe8d24 str r1, [sp, #0x3c] */
/* @0xe8d28 str r1, [sp, #0x40] */
/* @0xe8d2c str r1, [sp, #0x44] */
/* @0xe8d30 ldr r0, [r5, r0] */
/* @0xe8d34 str r0, [sp, #0xc] */
/* @0xe8d38 ldr r12, [sp, #0xc] */
/* @0xe8d3c ldr r0, [r3] */
/* @0xe8d40 ldrb r3, [r12] */
/* @0xe8d44 add r10, r0, r10, lsl #4 */
/* @0xe8d48 cmp r3, r1 */
/* @0xe8d4c bne 0xe9014 <_Z6DoCalljPhPKhP6VMExec+0x4cc> */
/* @0xe8d50 ldr r12, [pc, #0xa08] */
/* @0xe8d54 add r7, sp, #56 */
/* @0xe8d58 ldr r2, [r9, #0x18] */
/* @0xe8d5c mov r3, r6 */
/* @0xe8d60 ldr r1, [r9, #0x14] */
/* @0xe8d64 mov r0, r7 */
/* @0xe8d68 ldr r8, [r5, r12] */
/* @0xe8d6c str r4, [sp] */
/* @0xe8d70 ldr r12, [r10, #0x40] */
/* @0xe8d74 ldr r11, [r8] */
/* @0xe8d78 str r10, [r8] */
/* @0xe8d7c blx r12 */
/* @0xe8d80 ldr r12, [sp, #0xc] */
/* @0xe8d84 ldr r3, [pc, #0x9c8] */
/* @0xe8d88 str r11, [r8] */
/* @0xe8d8c ldrb r2, [r12] */
/* @0xe8d90 ldr r3, [r5, r3] */
/* @0xe8d94 cmp r2, #0 */
/* @0xe8d98 str r9, [r3] */
/* @0xe8d9c bne 0xe9004 <_Z6DoCalljPhPKhP6VMExec+0x4bc> */
/* @0xe8da0 ldr r3, [pc, #0x9bc] */
/* @0xe8da4 ldr r3, [r5, r3] */
/* @0xe8da8 ldrb r8, [r3] */
/* @0xe8dac cmp r8, #0 */
/* @0xe8db0 bne 0xe8b84 <_Z6DoCalljPhPKhP6VMExec+0x3c> */
/* @0xe8db4 cmp r6, #0 */
/* @0xe8db8 movne r5, r4 */
/* @0xe8dbc movne r9, r8 */
/* @0xe8dc0 movne r10, #5 */
/* @0xe8dc4 bne 0xe8de0 <_Z6DoCalljPhPKhP6VMExec+0x298> */
/* @0xe8dc8 b 0xe8ce4 <_Z6DoCalljPhPKhP6VMExec+0x19c> */
/* @0xe8dcc cmp r8, r6 */
/* @0xe8dd0 str r9, [r5, #0x8] */
/* @0xe8dd4 str r10, [r5, #0xc] */
/* @0xe8dd8 str r9, [r5], #16 */
/* @0xe8ddc beq 0xe8ce0 <_Z6DoCalljPhPKhP6VMExec+0x198> */
/* @0xe8de0 ldr r3, [r5, #0xc] */
/* @0xe8de4 add r8, r8, #1 */
/* @0xe8de8 sub r3, r3, #1 */
/* @0xe8dec bic r3, r3, #-16777216 */
/* @0xe8df0 bic r3, r3, #3 */
/* @0xe8df4 cmp r3, #0 */
/* @0xe8df8 bne 0xe8dcc <_Z6DoCalljPhPKhP6VMExec+0x284> */
/* @0xe8dfc mov r0, r5 */
/* @0xe8e00 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe8e04 b 0xe8dcc <_Z6DoCalljPhPKhP6VMExec+0x284> */
/* @0xe8e08 ldr r8, [r1] */
/* @0xe8e0c ldr r3, [r8, #0x48] */
/* @0xe8e10 cmp r3, #3 */
/* @0xe8e14 bne 0xe8bb4 <_Z6DoCalljPhPKhP6VMExec+0x6c> */
/* @0xe8e18 ldr r7, [r8, #0x64] */
/* @0xe8e1c uxth r6, r0 */
/* @0xe8e20 cmp r7, #0 */
/* @0xe8e24 beq 0xe9074 <_Z6DoCalljPhPKhP6VMExec+0x52c> */
/* @0xe8e28 mov r0, r7 */
/* @0xe8e2c mov r10, #0 */
/* @0xe8e30 add r12, r1, #32 */
/* @0xe8e34 str r10, [sp, #0x28] */
/* @0xe8e38 str r12, [sp, #0xc] */
/* @0xe8e3c str r10, [sp, #0x2c] */
/* @0xe8e40 str r10, [sp, #0x30] */
/* @0xe8e44 str r10, [sp, #0x34] */
/* @0xe8e48 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe8e4c ldr r3, [r0, #0x78] */
/* @0xe8e50 tst r3, #4 */
/* @0xe8e54 beq 0xe91a8 <_Z6DoCalljPhPKhP6VMExec+0x660> */
/* @0xe8e58 ldr r3, [r8, #0x88] */
/* @0xe8e5c cmp r3, #6 */
/* @0xe8e60 beq 0xe9200 <_Z6DoCalljPhPKhP6VMExec+0x6b8> */
/* @0xe8e64 ldr r3, [r4, #0x1c] */
/* @0xe8e68 bic r3, r3, #-16777216 */
/* @0xe8e6c cmp r3, #3 */
/* @0xe8e70 beq 0xe9044 <_Z6DoCalljPhPKhP6VMExec+0x4fc> */
/* @0xe8e74 cmp r3, #6 */
/* @0xe8e78 beq 0xe9044 <_Z6DoCalljPhPKhP6VMExec+0x4fc> */
/* @0xe8e7c mov r1, r11 */
/* @0xe8e80 add r0, sp, #40 */
/* @0xe8e84 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0xe8e88 cmp r0, #1 */
/* @0xe8e8c beq 0xe9634 <_Z6DoCalljPhPKhP6VMExec+0xaec> */
/* @0xe8e90 ldr r4, [sp, #0x28] */
/* @0xe8e94 str r4, [sp, #0x14] */
/* @0xe8e98 ldr r3, [pc, #0x8c8] */
/* @0xe8e9c ldr r4, [r5, r3] */
/* @0xe8ea0 ldr r0, [r4] */
/* @0xe8ea4 cmn r0, #1 */
/* @0xe8ea8 movne r1, r0 */
/* @0xe8eac beq 0xe93fc <_Z6DoCalljPhPKhP6VMExec+0x8b4> */
/* @0xe8eb0 ldr r3, [r8, #0x4] */
/* @0xe8eb4 cmp r3, #0 */
/* @0xe8eb8 beq 0xe9464 <_Z6DoCalljPhPKhP6VMExec+0x91c> */
/* @0xe8ebc add r0, r3, r1, lsl #4 */
/* @0xe8ec0 vmov s12, r6 */
/* @0xe8ec4 ldm r0, {r2, r3} */
/* @0xe8ec8 vcvt.f64.s32 d7, s12 */
/* @0xe8ecc vmov d6, r2, r3 */
/* @0xe8ed0 vcmpe.f64 d6, d7 */
/* @0xe8ed4 vmrs APSR_nzcv, fpscr */
/* @0xe8ed8 ble 0xe8f40 <_Z6DoCalljPhPKhP6VMExec+0x3f8> */
/* @0xe8edc vcvt.s32.f64 s13, d6 */
/* @0xe8ee0 vmov r4, s13 */
/* @0xe8ee4 cmp r6, r4 */
/* @0xe8ee8 bge 0xe8f40 <_Z6DoCalljPhPKhP6VMExec+0x3f8> */
/* @0xe8eec ldr r1, [sp, #0xc] */
/* @0xe8ef0 rsb r3, r6, r4 */
/* @0xe8ef4 lsl r6, r6, #4 */
/* @0xe8ef8 sub r12, r1, r3, lsl #4 */
/* @0xe8efc mov r2, r6 */
/* @0xe8f00 mov r0, r12 */
/* @0xe8f04 bl 0xb6694 <memmove@plt> */
/* @0xe8f08 mov r1, #0 */
/* @0xe8f0c mov r2, #5 */
/* @0xe8f10 mov r12, r0 */
/* @0xe8f14 add r3, r0, r6 */
/* @0xe8f18 add r0, r0, r4, lsl #4 */
/* @0xe8f1c str r1, [r3] */
/* @0xe8f20 add r3, r3, #16 */
/* @0xe8f24 str r1, [r3, #-0xc] */
/* @0xe8f28 str r1, [r3, #-0x8] */
/* @0xe8f2c str r2, [r3, #-0x4] */
/* @0xe8f30 cmp r3, r0 */
/* @0xe8f34 bne 0xe8f1c <_Z6DoCalljPhPKhP6VMExec+0x3d4> */
/* @0xe8f38 mov r6, r4 */
/* @0xe8f3c str r12, [sp, #0xc] */
/* @0xe8f40 mov r0, r7 */
/* @0xe8f44 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe8f48 ldr r3, [r0, #0x78] */
/* @0xe8f4c ands r3, r3, #1 */
/* @0xe8f50 beq 0xe9050 <_Z6DoCalljPhPKhP6VMExec+0x508> */
/* @0xe8f54 mov r12, #0 */
/* @0xe8f58 mov r1, r8 */
/* @0xe8f5c add r0, sp, #56 */
/* @0xe8f60 str r12, [sp] */
/* @0xe8f64 mov r2, r6 */
/* @0xe8f68 ldr r3, [sp, #0xc] */
/* @0xe8f6c str r12, [sp, #0x40] */
/* @0xe8f70 mov r4, #0 */
/* @0xe8f74 mvn r12, #-16777216 */
/* @0xe8f78 mov r5, #0 */
/* @0xe8f7c str r12, [sp, #0x44] */
/* @0xe8f80 strd r4, r5, [sp, #56] */
/* @0xe8f84 bl 0x248b58 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b> */
/* @0xe8f88 ldr r12, [sp, #0x38] */
/* @0xe8f8c mov r1, r6 */
/* @0xe8f90 str r10, [sp] */
/* @0xe8f94 mov r0, r7 */
/* @0xe8f98 ldr r2, [sp, #0xc] */
/* @0xe8f9c mov r3, r9 */
/* @0xe8fa0 str r12, [sp, #0x4] */
/* @0xe8fa4 bl 0xe8588 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_> */
/* @0xe8fa8 mov r11, r0 */
/* @0xe8fac cmp r10, #0 */
/* @0xe8fb0 beq 0xe8fc8 <_Z6DoCalljPhPKhP6VMExec+0x480> */
/* @0xe8fb4 mov r0, r7 */
/* @0xe8fb8 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe8fbc ldr r3, [r0, #0x78] */
/* @0xe8fc0 ands r3, r3, #2 */
/* @0xe8fc4 streq r3, [r9, #0xc] */
/* @0xe8fc8 ldr r3, [sp, #0x34] */
/* @0xe8fcc ldr r4, [sp, #0x14] */
/* @0xe8fd0 sub r3, r3, #1 */
/* @0xe8fd4 bic r3, r3, #-16777216 */
/* @0xe8fd8 bic r3, r3, #3 */
/* @0xe8fdc str r4, [r9, #0x14] */
/* @0xe8fe0 cmp r3, #0 */
/* @0xe8fe4 bne 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe8fe8 add r0, sp, #40 */
/* @0xe8fec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe8ff0 b 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe8ff4 ldr r0, [pc, #0x770] */
/* @0xe8ff8 add r0, pc, r0 */
/* @0xe8ffc bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe9000 b 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe9004 ldr r3, [pc, #0x764] */
/* @0xe9008 ldr r0, [r5, r3] */
/* @0xe900c bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xe9010 b 0xe8da0 <_Z6DoCalljPhPKhP6VMExec+0x258> */
/* @0xe9014 ldr r3, [pc, #0x754] */
/* @0xe9018 ldr r0, [r5, r3] */
/* @0xe901c bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0xe9020 b 0xe8d50 <_Z6DoCalljPhPKhP6VMExec+0x208> */
/* @0xe9024 mov r0, r1 */
/* @0xe9028 mov r1, #0 */
/* @0xe902c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xe9030 add r4, r4, #16 */
/* @0xe9034 sub r6, r6, #1 */
/* @0xe9038 add r0, r0, #99328 */
/* @0xe903c add r2, r0, #672 */
/* @0xe9040 b 0xe8c18 <_Z6DoCalljPhPKhP6VMExec+0xd0> */
/* @0xe9044 ldr r4, [r4, #0x10] */
/* @0xe9048 str r4, [sp, #0x14] */
/* @0xe904c b 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe9050 str r3, [sp, #0x4] */
/* @0xe9054 mov r1, r6 */
/* @0xe9058 str r10, [sp] */
/* @0xe905c mov r0, r7 */
/* @0xe9060 ldr r2, [sp, #0xc] */
/* @0xe9064 mov r3, r9 */
/* @0xe9068 bl 0xe8588 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_> */
/* @0xe906c mov r11, r0 */
/* @0xe9070 b 0xe8fac <_Z6DoCalljPhPKhP6VMExec+0x464> */
/* @0xe9074 ldr r10, [r8, #0x68] */
/* @0xe9078 cmp r10, #0 */
/* @0xe907c beq 0xe9698 <_Z6DoCalljPhPKhP6VMExec+0xb50> */
/* @0xe9080 str r12, [sp, #0x34] */
/* @0xe9084 mvn r1, #-16777216 */
/* @0xe9088 str r7, [sp, #0x38] */
/* @0xe908c mov r2, #0 */
/* @0xe9090 str r7, [sp, #0x3c] */
/* @0xe9094 mov r3, #0 */
/* @0xe9098 str r7, [sp, #0x40] */
/* @0xe909c add r12, r4, #32 */
/* @0xe90a0 str r1, [sp, #0x44] */
/* @0xe90a4 ldr r1, [r8, #0x88] */
/* @0xe90a8 str r12, [sp, #0xc] */
/* @0xe90ac cmp r1, #6 */
/* @0xe90b0 str r7, [sp, #0x30] */
/* @0xe90b4 strd r2, r3, [sp, #40] */
/* @0xe90b8 beq 0xe947c <_Z6DoCalljPhPKhP6VMExec+0x934> */
/* @0xe90bc ldr r3, [r4, #0x1c] */
/* @0xe90c0 bic r3, r3, #-16777216 */
/* @0xe90c4 cmp r3, #3 */
/* @0xe90c8 beq 0xe91f0 <_Z6DoCalljPhPKhP6VMExec+0x6a8> */
/* @0xe90cc cmp r3, #6 */
/* @0xe90d0 beq 0xe91f0 <_Z6DoCalljPhPKhP6VMExec+0x6a8> */
/* @0xe90d4 mov r1, r11 */
/* @0xe90d8 add r0, sp, #56 */
/* @0xe90dc bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0xe90e0 cmp r0, #1 */
/* @0xe90e4 beq 0xe96a8 <_Z6DoCalljPhPKhP6VMExec+0xb60> */
/* @0xe90e8 ldr r7, [sp, #0x38] */
/* @0xe90ec mov r0, #0 */
/* @0xe90f0 add r8, sp, #40 */
/* @0xe90f4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe90f8 ldr r4, [sp, #0xc] */
/* @0xe90fc ldr r2, [r9, #0x18] */
/* @0xe9100 mov r3, r6 */
/* @0xe9104 mov r1, r7 */
/* @0xe9108 mov r0, r8 */
/* @0xe910c str r4, [sp] */
/* @0xe9110 blx r10 */
/* @0xe9114 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe9118 ldr r3, [sp, #0x44] */
/* @0xe911c sub r3, r3, #1 */
/* @0xe9120 bic r3, r3, #-16777216 */
/* @0xe9124 bic r3, r3, #3 */
/* @0xe9128 cmp r3, #0 */
/* @0xe912c beq 0xe9418 <_Z6DoCalljPhPKhP6VMExec+0x8d0> */
/* @0xe9130 ldr r2, [pc, #0x62c] */
/* @0xe9134 mov r3, #0 */
/* @0xe9138 mov r10, #5 */
/* @0xe913c str r3, [sp, #0x40] */
/* @0xe9140 str r3, [sp, #0x38] */
/* @0xe9144 str r10, [sp, #0x44] */
/* @0xe9148 ldr r3, [r5, r2] */
/* @0xe914c ldrb r5, [r3] */
/* @0xe9150 cmp r5, #0 */
/* @0xe9154 bne 0xe91f8 <_Z6DoCalljPhPKhP6VMExec+0x6b0> */
/* @0xe9158 cmp r6, #0 */
/* @0xe915c movne r7, r5 */
/* @0xe9160 ldrne r4, [sp, #0xc] */
/* @0xe9164 bne 0xe9180 <_Z6DoCalljPhPKhP6VMExec+0x638> */
/* @0xe9168 b 0xe91dc <_Z6DoCalljPhPKhP6VMExec+0x694> */
/* @0xe916c cmp r5, r6 */
/* @0xe9170 str r7, [r4, #0x8] */
/* @0xe9174 str r10, [r4, #0xc] */
/* @0xe9178 str r7, [r4], #16 */
/* @0xe917c beq 0xe91d0 <_Z6DoCalljPhPKhP6VMExec+0x688> */
/* @0xe9180 ldr r3, [r4, #0xc] */
/* @0xe9184 add r5, r5, #1 */
/* @0xe9188 sub r3, r3, #1 */
/* @0xe918c bic r3, r3, #-16777216 */
/* @0xe9190 bic r3, r3, #3 */
/* @0xe9194 cmp r3, #0 */
/* @0xe9198 bne 0xe916c <_Z6DoCalljPhPKhP6VMExec+0x624> */
/* @0xe919c mov r0, r4 */
/* @0xe91a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe91a4 b 0xe916c <_Z6DoCalljPhPKhP6VMExec+0x624> */
/* @0xe91a8 ldr r3, [pc, #0x5c4] */
/* @0xe91ac ldr r3, [r5, r3] */
/* @0xe91b0 ldr r0, [r3] */
/* @0xe91b4 bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0xe91b8 ldr r3, [r8, #0x78] */
/* @0xe91bc cmp r3, #6 */
/* @0xe91c0 ldreq r3, [r8, #0x6c] */
/* @0xe91c4 mov r10, r0 */
/* @0xe91c8 streq r3, [r0, #0xc] */
/* @0xe91cc b 0xe8e58 <_Z6DoCalljPhPKhP6VMExec+0x310> */
/* @0xe91d0 ldr r12, [sp, #0xc] */
/* @0xe91d4 add r12, r12, r5, lsl #4 */
/* @0xe91d8 str r12, [sp, #0xc] */
/* @0xe91dc ldr r4, [sp, #0xc] */
/* @0xe91e0 mov r9, r8 */
/* @0xe91e4 ldm r9!, {r0, r1, r2, r3} */
/* @0xe91e8 sub r12, r4, #16 */
/* @0xe91ec b 0xe8cec <_Z6DoCalljPhPKhP6VMExec+0x1a4> */
/* @0xe91f0 ldr r7, [r4, #0x10] */
/* @0xe91f4 b 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe91f8 ldr r11, [sp, #0xc] */
/* @0xe91fc b 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe9200 ldr r4, [r8, #0x7c] */
/* @0xe9204 mov r0, r8 */
/* @0xe9208 ldr r1, [pc, #0x568] */
/* @0xe920c add r1, pc, r1 */
/* @0xe9210 str r4, [sp, #0x14] */
/* @0xe9214 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0xe9218 cmp r0, #0 */
/* @0xe921c beq 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe9220 ldr r3, [r0, #0xc] */
/* @0xe9224 cmp r3, #6 */
/* @0xe9228 bne 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe922c ldr r0, [r0] */
/* @0xe9230 ldr r3, [r0, #0x4] */
/* @0xe9234 cmp r3, #0 */
/* @0xe9238 addne r0, r3, #16 */
/* @0xe923c beq 0xe9700 <_Z6DoCalljPhPKhP6VMExec+0xbb8> */
/* @0xe9240 ldr r2, [r0] */
/* @0xe9244 ldr r3, [r2, #0x24] */
/* @0xe9248 ldr r2, [r2, #0x4] */
/* @0xe924c sub r11, r3, #-268435455 */
/* @0xe9250 subs r3, r3, #1 */
/* @0xe9254 add r11, r2, r11, lsl #4 */
/* @0xe9258 bmi 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe925c sub r11, r11, #16 */
/* @0xe9260 ldr r4, [sp, #0xc] */
/* @0xe9264 str r8, [sp, #0x18] */
/* @0xe9268 mov r8, r3 */
/* @0xe926c str r7, [sp, #0x1c] */
/* @0xe9270 mov r7, r11 */
/* @0xe9274 str r10, [sp, #0x10] */
/* @0xe9278 str r9, [sp, #0x20] */
/* @0xe927c str r5, [sp, #0x24] */
/* @0xe9280 ldr r0, [r4, #-0x4] */
/* @0xe9284 sub r9, r4, #16 */
/* @0xe9288 add r10, r7, #16 */
/* @0xe928c bic r1, r0, #-16777216 */
/* @0xe9290 mov r5, r9 */
/* @0xe9294 cmp r1, #1 */
/* @0xe9298 beq 0xe93d0 <_Z6DoCalljPhPKhP6VMExec+0x888> */
/* @0xe929c cmp r1, #2 */
/* @0xe92a0 bne 0xe92c4 <_Z6DoCalljPhPKhP6VMExec+0x77c> */
/* @0xe92a4 sub r1, r0, #1 */
/* @0xe92a8 bic r1, r1, #-16777216 */
/* @0xe92ac bic r1, r1, #3 */
/* @0xe92b0 cmp r1, #0 */
/* @0xe92b4 beq 0xe9470 <_Z6DoCalljPhPKhP6VMExec+0x928> */
/* @0xe92b8 mov r0, #0 */
/* @0xe92bc mov r12, #5 */
/* @0xe92c0 stmdb r4, {r0, r12} */
/* @0xe92c4 mov r1, #0 */
/* @0xe92c8 str r1, [r4, #-0x10] */
/* @0xe92cc ldr r1, [r7, #0x1c] */
/* @0xe92d0 str r1, [r4, #-0x4] */
/* @0xe92d4 ldr r1, [r7, #0x18] */
/* @0xe92d8 str r1, [r4, #-0x8] */
/* @0xe92dc ldr r1, [r7, #0x1c] */
/* @0xe92e0 bic r1, r1, #-16777216 */
/* @0xe92e4 cmp r1, #14 */
/* @0xe92e8 addls pc, pc, r1, lsl #2 */
/* @0xe92ec b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe92f0 b 0xe9364 <_Z6DoCalljPhPKhP6VMExec+0x81c> */
/* @0xe92f4 b 0xe93c0 <_Z6DoCalljPhPKhP6VMExec+0x878> */
/* @0xe92f8 b 0xe9394 <_Z6DoCalljPhPKhP6VMExec+0x84c> */
/* @0xe92fc b 0xe932c <_Z6DoCalljPhPKhP6VMExec+0x7e4> */
/* @0xe9300 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9304 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9308 b 0xe9370 <_Z6DoCalljPhPKhP6VMExec+0x828> */
/* @0xe930c b 0xe932c <_Z6DoCalljPhPKhP6VMExec+0x7e4> */
/* @0xe9310 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9314 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9318 b 0xe9364 <_Z6DoCalljPhPKhP6VMExec+0x81c> */
/* @0xe931c b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9320 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9324 b 0xe9364 <_Z6DoCalljPhPKhP6VMExec+0x81c> */
/* @0xe9328 b 0xe932c <_Z6DoCalljPhPKhP6VMExec+0x7e4> */
/* @0xe932c ldr r1, [r7, #0x10] */
/* @0xe9330 str r1, [r4, #-0x10] */
/* @0xe9334 subs r8, r8, #1 */
/* @0xe9338 add r6, r6, #1 */
/* @0xe933c sub r7, r7, #16 */
/* @0xe9340 mov r4, r9 */
/* @0xe9344 bpl 0xe9280 <_Z6DoCalljPhPKhP6VMExec+0x738> */
/* @0xe9348 str r5, [sp, #0xc] */
/* @0xe934c ldr r10, [sp, #0x10] */
/* @0xe9350 ldr r8, [sp, #0x18] */
/* @0xe9354 ldr r7, [sp, #0x1c] */
/* @0xe9358 ldr r9, [sp, #0x20] */
/* @0xe935c ldr r5, [sp, #0x24] */
/* @0xe9360 b 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe9364 ldm r10, {r0, r1} */
/* @0xe9368 stm r9, {r0, r1} */
/* @0xe936c b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9370 ldr r1, [r7, #0x10] */
/* @0xe9374 str r1, [r4, #-0x10] */
/* @0xe9378 ldr r1, [r7, #0x10] */
/* @0xe937c cmp r1, #0 */
/* @0xe9380 beq 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9384 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe9388 ldr r1, [r7, #0x10] */
/* @0xe938c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe9390 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9394 ldr r1, [r7, #0x10] */
/* @0xe9398 cmp r1, #0 */
/* @0xe939c str r1, [r4, #-0x10] */
/* @0xe93a0 beq 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe93a4 ldr r12, [r1, #0x8] */
/* @0xe93a8 ldr r0, [r1] */
/* @0xe93ac cmp r12, #0 */
/* @0xe93b0 streq r9, [r1, #0x8] */
/* @0xe93b4 add r0, r0, #1 */
/* @0xe93b8 str r0, [r1] */
/* @0xe93bc b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe93c0 ldr r0, [r7, #0x10] */
/* @0xe93c4 bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xe93c8 str r0, [r4, #-0x10] */
/* @0xe93cc b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe93d0 ldr r11, [r4, #-0x10] */
/* @0xe93d4 cmp r11, #0 */
/* @0xe93d8 beq 0xe92c4 <_Z6DoCalljPhPKhP6VMExec+0x77c> */
/* @0xe93dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe93e0 ldr r12, [r11, #0x4] */
/* @0xe93e4 sub r12, r12, #1 */
/* @0xe93e8 str r12, [r11, #0x4] */
/* @0xe93ec cmp r12, #0 */
/* @0xe93f0 beq 0xe9424 <_Z6DoCalljPhPKhP6VMExec+0x8dc> */
/* @0xe93f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe93f8 b 0xe92c4 <_Z6DoCalljPhPKhP6VMExec+0x77c> */
/* @0xe93fc ldr r1, [pc, #0x378] */
/* @0xe9400 mov r0, r8 */
/* @0xe9404 add r1, pc, r1 */
/* @0xe9408 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0xe940c mov r1, r0 */
/* @0xe9410 str r0, [r4] */
/* @0xe9414 b 0xe8eb0 <_Z6DoCalljPhPKhP6VMExec+0x368> */
/* @0xe9418 add r0, sp, #56 */
/* @0xe941c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9420 b 0xe9130 <_Z6DoCalljPhPKhP6VMExec+0x5e8> */
/* @0xe9424 ldr r0, [r11] */
/* @0xe9428 str r12, [sp, #0x8] */
/* @0xe942c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9430 ldr r12, [sp, #0x8] */
/* @0xe9434 str r12, [r11] */
/* @0xe9438 str r12, [r11, #0x8] */
/* @0xe943c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9440 ldr r12, [r11, #0x4] */
/* @0xe9444 sub r12, r12, #1 */
/* @0xe9448 str r12, [r11, #0x4] */
/* @0xe944c cmp r12, #0 */
/* @0xe9450 beq 0xe9658 <_Z6DoCalljPhPKhP6VMExec+0xb10> */
/* @0xe9454 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9458 mov r0, r11 */
/* @0xe945c bl 0x27d1d0 <_ZdlPv> */
/* @0xe9460 b 0xe93f4 <_Z6DoCalljPhPKhP6VMExec+0x8ac> */
/* @0xe9464 mov r0, r8 */
/* @0xe9468 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe946c b 0xe8ec0 <_Z6DoCalljPhPKhP6VMExec+0x378> */
/* @0xe9470 mov r0, r9 */
/* @0xe9474 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9478 b 0xe92b8 <_Z6DoCalljPhPKhP6VMExec+0x770> */
/* @0xe947c ldr r1, [pc, #0x2fc] */
/* @0xe9480 mov r0, r8 */
/* @0xe9484 ldr r7, [r8, #0x7c] */
/* @0xe9488 add r1, pc, r1 */
/* @0xe948c bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0xe9490 cmp r0, #0 */
/* @0xe9494 beq 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe9498 ldr r3, [r0, #0xc] */
/* @0xe949c cmp r3, #6 */
/* @0xe94a0 bne 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe94a4 ldr r0, [r0] */
/* @0xe94a8 ldr r3, [r0, #0x4] */
/* @0xe94ac cmp r3, #0 */
/* @0xe94b0 addne r0, r3, #16 */
/* @0xe94b4 beq 0xe970c <_Z6DoCalljPhPKhP6VMExec+0xbc4> */
/* @0xe94b8 ldr r3, [r0] */
/* @0xe94bc ldr r2, [r3, #0x24] */
/* @0xe94c0 ldr r3, [r3, #0x4] */
/* @0xe94c4 sub r11, r2, #-268435455 */
/* @0xe94c8 subs r8, r2, #1 */
/* @0xe94cc add r11, r3, r11, lsl #4 */
/* @0xe94d0 bmi 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe94d4 ldr r4, [sp, #0xc] */
/* @0xe94d8 sub r11, r11, #16 */
/* @0xe94dc str r7, [sp, #0x10] */
/* @0xe94e0 mov r7, r8 */
/* @0xe94e4 str r5, [sp, #0x14] */
/* @0xe94e8 ldr r0, [r4, #-0x4] */
/* @0xe94ec sub r5, r4, #16 */
/* @0xe94f0 add r8, r11, #16 */
/* @0xe94f4 str r5, [sp, #0xc] */
/* @0xe94f8 bic r2, r0, #-16777216 */
/* @0xe94fc cmp r2, #1 */
/* @0xe9500 beq 0xe9628 <_Z6DoCalljPhPKhP6VMExec+0xae0> */
/* @0xe9504 cmp r2, #2 */
/* @0xe9508 bne 0xe952c <_Z6DoCalljPhPKhP6VMExec+0x9e4> */
/* @0xe950c sub r2, r0, #1 */
/* @0xe9510 bic r2, r2, #-16777216 */
/* @0xe9514 bic r2, r2, #3 */
/* @0xe9518 cmp r2, #0 */
/* @0xe951c beq 0xe964c <_Z6DoCalljPhPKhP6VMExec+0xb04> */
/* @0xe9520 mov r0, #0 */
/* @0xe9524 mov r1, #5 */
/* @0xe9528 stmdb r4, {r0, r1} */
/* @0xe952c mov r2, #0 */
/* @0xe9530 str r2, [r4, #-0x10] */
/* @0xe9534 ldr r2, [r11, #0x1c] */
/* @0xe9538 str r2, [r4, #-0x4] */
/* @0xe953c ldr r2, [r11, #0x18] */
/* @0xe9540 str r2, [r4, #-0x8] */
/* @0xe9544 ldr r2, [r11, #0x1c] */
/* @0xe9548 bic r2, r2, #-16777216 */
/* @0xe954c cmp r2, #14 */
/* @0xe9550 addls pc, pc, r2, lsl #2 */
/* @0xe9554 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9558 b 0xe95bc <_Z6DoCalljPhPKhP6VMExec+0xa74> */
/* @0xe955c b 0xe9618 <_Z6DoCalljPhPKhP6VMExec+0xad0> */
/* @0xe9560 b 0xe95ec <_Z6DoCalljPhPKhP6VMExec+0xaa4> */
/* @0xe9564 b 0xe9594 <_Z6DoCalljPhPKhP6VMExec+0xa4c> */
/* @0xe9568 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe956c b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9570 b 0xe95c8 <_Z6DoCalljPhPKhP6VMExec+0xa80> */
/* @0xe9574 b 0xe9594 <_Z6DoCalljPhPKhP6VMExec+0xa4c> */
/* @0xe9578 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe957c b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9580 b 0xe95bc <_Z6DoCalljPhPKhP6VMExec+0xa74> */
/* @0xe9584 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9588 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe958c b 0xe95bc <_Z6DoCalljPhPKhP6VMExec+0xa74> */
/* @0xe9590 b 0xe9594 <_Z6DoCalljPhPKhP6VMExec+0xa4c> */
/* @0xe9594 ldr r2, [r11, #0x10] */
/* @0xe9598 str r2, [r4, #-0x10] */
/* @0xe959c subs r7, r7, #1 */
/* @0xe95a0 add r6, r6, #1 */
/* @0xe95a4 sub r11, r11, #16 */
/* @0xe95a8 mov r4, r5 */
/* @0xe95ac bpl 0xe94e8 <_Z6DoCalljPhPKhP6VMExec+0x9a0> */
/* @0xe95b0 ldr r7, [sp, #0x10] */
/* @0xe95b4 ldr r5, [sp, #0x14] */
/* @0xe95b8 b 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe95bc ldm r8, {r0, r2} */
/* @0xe95c0 stm r5, {r0, r2} */
/* @0xe95c4 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe95c8 ldr r2, [r11, #0x10] */
/* @0xe95cc str r2, [r4, #-0x10] */
/* @0xe95d0 ldr r2, [r11, #0x10] */
/* @0xe95d4 cmp r2, #0 */
/* @0xe95d8 beq 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe95dc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe95e0 ldr r1, [r11, #0x10] */
/* @0xe95e4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe95e8 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe95ec ldr r2, [r11, #0x10] */
/* @0xe95f0 cmp r2, #0 */
/* @0xe95f4 str r2, [r4, #-0x10] */
/* @0xe95f8 beq 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe95fc ldr r0, [r2, #0x8] */
/* @0xe9600 ldr r1, [r2] */
/* @0xe9604 cmp r0, #0 */
/* @0xe9608 streq r5, [r2, #0x8] */
/* @0xe960c add r1, r1, #1 */
/* @0xe9610 str r1, [r2] */
/* @0xe9614 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9618 ldr r0, [r11, #0x10] */
/* @0xe961c bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xe9620 str r0, [r4, #-0x10] */
/* @0xe9624 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9628 ldr r0, [r4, #-0x10] */
/* @0xe962c bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xe9630 b 0xe952c <_Z6DoCalljPhPKhP6VMExec+0x9e4> */
/* @0xe9634 ldr r1, [pc, #0x148] */
/* @0xe9638 mov r0, r9 */
/* @0xe963c ldr r2, [r4, #0x1c] */
/* @0xe9640 add r1, pc, r1 */
/* @0xe9644 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe9648 b 0xe8e90 <_Z6DoCalljPhPKhP6VMExec+0x348> */
/* @0xe964c mov r0, r5 */
/* @0xe9650 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9654 b 0xe9520 <_Z6DoCalljPhPKhP6VMExec+0x9d8> */
/* @0xe9658 ldr r0, [r11] */
/* @0xe965c str r12, [sp, #0x8] */
/* @0xe9660 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9664 ldr r12, [sp, #0x8] */
/* @0xe9668 str r12, [r11] */
/* @0xe966c str r12, [r11, #0x8] */
/* @0xe9670 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9674 ldr r12, [r11, #0x4] */
/* @0xe9678 sub r12, r12, #1 */
/* @0xe967c str r12, [r11, #0x4] */
/* @0xe9680 cmp r12, #0 */
/* @0xe9684 beq 0xe96c0 <_Z6DoCalljPhPKhP6VMExec+0xb78> */
/* @0xe9688 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe968c mov r0, r11 */
/* @0xe9690 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9694 b 0xe9454 <_Z6DoCalljPhPKhP6VMExec+0x90c> */
/* @0xe9698 ldr r0, [pc, #0xe8] */
/* @0xe969c add r0, pc, r0 */
/* @0xe96a0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe96a4 b 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe96a8 ldr r1, [pc, #0xdc] */
/* @0xe96ac mov r0, r9 */
/* @0xe96b0 ldr r2, [r4, #0x1c] */
/* @0xe96b4 add r1, pc, r1 */
/* @0xe96b8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe96bc b 0xe90e8 <_Z6DoCalljPhPKhP6VMExec+0x5a0> */
/* @0xe96c0 ldr r0, [r11] */
/* @0xe96c4 str r12, [sp, #0x8] */
/* @0xe96c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe96cc ldr r12, [sp, #0x8] */
/* @0xe96d0 str r12, [r11] */
/* @0xe96d4 str r12, [r11, #0x8] */
/* @0xe96d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe96dc ldr r12, [r11, #0x4] */
/* @0xe96e0 sub r12, r12, #1 */
/* @0xe96e4 str r12, [r11, #0x4] */
/* @0xe96e8 cmp r12, #0 */
/* @0xe96ec beq 0xe9718 <_Z6DoCalljPhPKhP6VMExec+0xbd0> */
/* @0xe96f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe96f4 mov r0, r11 */
/* @0xe96f8 bl 0x27d1d0 <_ZdlPv> */
/* @0xe96fc b 0xe9688 <_Z6DoCalljPhPKhP6VMExec+0xb40> */
/* @0xe9700 mov r1, #1 */
/* @0xe9704 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe9708 b 0xe9240 <_Z6DoCalljPhPKhP6VMExec+0x6f8> */
/* @0xe970c mov r1, #1 */
/* @0xe9710 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe9714 b 0xe94b8 <_Z6DoCalljPhPKhP6VMExec+0x970> */
/* @0xe9718 ldr r0, [r11] */
/* @0xe971c str r12, [sp, #0x8] */
/* @0xe9720 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9724 ldr r12, [sp, #0x8] */
/* @0xe9728 mov r0, r11 */
/* @0xe972c str r12, [r11] */
/* @0xe9730 str r12, [r11, #0x8] */
/* @0xe9734 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe9738 mov r0, r11 */
/* @0xe973c bl 0x27d1d0 <_ZdlPv> */
/* @0xe9740 b 0xe96f0 <_Z6DoCalljPhPKhP6VMExec+0xba8> */
/* ---- 以下 0xe9744..0xe978c 是 literal pool：字符串偏移与代码相对偏移，
 *      按 README 规矩保留 objdump 写法（部分被译成 eorseq），它们不是指令 ---- */
/* @0xe9744 eorseq r9, r0, r12, ror #1 */
/* @0xe9748 eoreq r11, r4, r8, asr sp */
/* @0xe974c .word 0xffffc0fc */
/* @0xe9750 .word 0x0024bcf0 */
/* @0xe9754 .word 0xffffbf58 */
/* @0xe9758 .word 0xffffbec8 */
/* @0xe975c .word 0xffffbf18 */
/* @0xe9760 .word 0xffffbee0 */
/* @0xe9764 .word 0xffffc0cc */
/* @0xe9768 .word 0xffffc05c */
/* @0xe976c eoreq r11, r4, r12, lsr #17 */
/* @0xe9770 .word 0xffffbf1c */
/* @0xe9774 .word 0xffffc104 */
/* @0xe9778 eoreq r11, r4, r0, asr #12 */
/* @0xe977c eoreq r7, r4, r8, ror #8 */
/* @0xe9780 eoreq r11, r4, r4, asr #7 */
/* @0xe9784 eoreq r11, r4, r12, lsl r2 */
/* @0xe9788 .word 0x0024b1f0 */
/* @0xe978c eoreq r11, r4, r8, lsr #3 */
